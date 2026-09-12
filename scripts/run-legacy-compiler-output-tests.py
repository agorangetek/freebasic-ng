#!/usr/bin/env python3
"""Check historical compiler-output fixtures with a staged CMake compiler.

The warning and syntax suites regenerate versioned result files under r/.  The
adapter runs them only in a copied source-layout sandbox, then compares that
generated tree byte-for-byte with the checked-in reference tree.
"""

from __future__ import annotations

import argparse
import os
import shutil
import subprocess
import sys
from pathlib import Path


def require_child(path: Path, parent: Path, label: str) -> None:
    """Reject a destructive test-output path outside the CMake build tree."""
    try:
        path.resolve().relative_to(parent.resolve())
    except ValueError as error:
        raise ValueError(f"{label} must be below build directory: {path}") from error


def run(command: list[str], *, cwd: Path | None = None, env: dict[str, str] | None = None,
        log: Path | None = None) -> None:
    print("+", " ".join(command), flush=True)
    if log is None:
        subprocess.run(command, cwd=cwd, env=env, check=True)
        return

    with log.open("w", encoding="utf-8") as output:
        result = subprocess.run(
            command,
            cwd=cwd,
            env=env,
            stdout=output,
            stderr=subprocess.STDOUT,
            text=True,
            check=False,
        )

    if result.returncode:
        print(f"legacy compiler-output suite failed; full log: {log}", file=sys.stderr)
        with log.open("r", encoding="utf-8", errors="replace") as output:
            sys.stderr.writelines(output.readlines()[-80:])
        raise subprocess.CalledProcessError(result.returncode, command)


def compare_result_trees(expected: Path, actual: Path) -> None:
    """Fail on missing, extra or byte-different versioned result files."""
    expected_files = {
        path.relative_to(expected): path
        for path in expected.rglob("*")
        if path.is_file()
    }
    actual_files = {
        path.relative_to(actual): path
        for path in actual.rglob("*")
        if path.is_file()
    }

    missing = sorted(expected_files.keys() - actual_files.keys())
    extra = sorted(actual_files.keys() - expected_files.keys())
    changed = sorted(
        relative
        for relative in expected_files.keys() & actual_files.keys()
        if expected_files[relative].read_bytes() != actual_files[relative].read_bytes()
    )
    if not (missing or extra or changed):
        return

    def render(label: str, paths: list[Path]) -> str:
        if not paths:
            return ""
        items = "\n".join(f"  {path}" for path in paths[:40])
        suffix = "\n  ..." if len(paths) > 40 else ""
        return f"{label}:\n{items}{suffix}\n"

    detail = (
        render("missing generated fixtures", missing)
        + render("unexpected generated fixtures", extra)
        + render("changed compiler-output fixtures", changed)
    )
    raise RuntimeError(f"compiler-output fixtures differ from the checkout:\n{detail}")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cmake", required=True, type=Path)
    parser.add_argument("--build-dir", required=True, type=Path)
    parser.add_argument("--install-prefix", required=True, type=Path)
    parser.add_argument("--source-tests-dir", required=True, type=Path)
    parser.add_argument("--source-include-dir", required=True, type=Path)
    parser.add_argument("--suite", required=True, choices=("warnings", "syntax"))
    parser.add_argument("--work-dir", required=True, type=Path)
    parser.add_argument("--log", required=True, type=Path)
    args = parser.parse_args()

    build_dir = args.build_dir.resolve()
    install_prefix = args.install_prefix.resolve()
    work_dir = args.work_dir.resolve()
    log_path = args.log.resolve()

    require_child(install_prefix, build_dir, "install prefix")
    require_child(work_dir, build_dir, "test work directory")
    require_child(log_path, build_dir, "test log")
    if not args.source_tests_dir.is_dir():
        raise FileNotFoundError(f"legacy tests directory is missing: {args.source_tests_dir}")
    if not args.source_include_dir.is_dir():
        raise FileNotFoundError(
            f"legacy compiler include directory is missing: {args.source_include_dir}"
        )

    expected_dir = args.source_tests_dir / args.suite / "r"
    if not expected_dir.is_dir():
        raise FileNotFoundError(f"legacy {args.suite} fixtures are missing: {expected_dir}")

    shutil.rmtree(install_prefix, ignore_errors=True)
    shutil.rmtree(work_dir, ignore_errors=True)
    log_path.parent.mkdir(parents=True, exist_ok=True)

    run([
        str(args.cmake),
        "--install",
        str(build_dir),
        "--prefix",
        str(install_prefix),
    ])

    # Preserve the checkout's source layout instead of regenerating tracked
    # fixtures in place.
    test_dir = work_dir / "tests"
    shutil.copytree(args.source_tests_dir, test_dir)
    shutil.copytree(args.source_include_dir, work_dir / "inc")

    compiler = install_prefix / "bin" / "fbc"
    if not compiler.is_file():
        compiler = compiler.with_suffix(".exe")
    compiler_include_dir = install_prefix / "include" / "freebasic"
    if not compiler.is_file() or not compiler_include_dir.is_dir():
        raise FileNotFoundError("CMake installation did not contain fbc and its include directory")

    suite_dir = test_dir / args.suite
    environment = os.environ | {"FBC": f"{compiler} -i {compiler_include_dir}"}
    run([str(suite_dir / "test.sh")], cwd=suite_dir, env=environment, log=log_path)
    compare_result_trees(expected_dir, suite_dir / "r")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
