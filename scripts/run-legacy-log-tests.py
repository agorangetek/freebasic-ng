#!/usr/bin/env python3
"""Run the historical log-test suite from a CMake-built, staged compiler.

The historical makefiles create logs, objects and executables alongside their
inputs.  This adapter recreates the source layout inside the CMake binary tree
and treats the generated failure records as the suite's result, without
modifying the checkout or invoking the root makefile.
"""

from __future__ import annotations

import argparse
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


def run(command: list[str], *, cwd: Path | None = None, log: Path | None = None) -> None:
    print("+", " ".join(command), flush=True)
    if log is None:
        subprocess.run(command, cwd=cwd, check=True)
        return

    with log.open("w", encoding="utf-8") as output:
        result = subprocess.run(
            command,
            cwd=cwd,
            stdout=output,
            stderr=subprocess.STDOUT,
            text=True,
            check=False,
        )

    if result.returncode:
        print(f"legacy log suite failed; full log: {log}", file=sys.stderr)
        with log.open("r", encoding="utf-8", errors="replace") as output:
            sys.stderr.writelines(output.readlines()[-80:])
        raise subprocess.CalledProcessError(result.returncode, command)


def require_no_recorded_failures(test_dir: Path) -> None:
    """Make's log target records individual failures without failing itself."""
    failed_records = sorted(test_dir.glob("failed-*.log"))
    failures = [
        path
        for path in failed_records
        if "RESULT=FAILED" in path.read_text(encoding="utf-8", errors="replace")
    ]
    if not failures:
        return

    print("legacy log tests recorded failures:", file=sys.stderr)
    for path in failures:
        print(f"\n--- {path.name} ---", file=sys.stderr)
        print(path.read_text(encoding="utf-8", errors="replace"), file=sys.stderr)
    raise RuntimeError("historical log suite recorded failed tests")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cmake", required=True, type=Path)
    parser.add_argument("--make", required=True, type=Path)
    parser.add_argument("--build-dir", required=True, type=Path)
    parser.add_argument("--install-prefix", required=True, type=Path)
    parser.add_argument("--source-tests-dir", required=True, type=Path)
    parser.add_argument("--source-include-dir", required=True, type=Path)
    parser.add_argument("--work-dir", required=True, type=Path)
    parser.add_argument("--log", required=True, type=Path)
    parser.add_argument("--fbc-flag", action="append", default=[])
    args = parser.parse_args()

    build_dir = args.build_dir.resolve()
    install_prefix = args.install_prefix.resolve()
    work_dir = args.work_dir.resolve()
    log_path = args.log.resolve()

    require_child(install_prefix, build_dir, "install prefix")
    require_child(work_dir, build_dir, "test work directory")
    require_child(log_path, build_dir, "test log")

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

    if not args.source_tests_dir.is_dir():
        raise FileNotFoundError(f"legacy tests directory is missing: {args.source_tests_dir}")
    if not args.source_include_dir.is_dir():
        raise FileNotFoundError(
            f"legacy compiler include directory is missing: {args.source_include_dir}"
        )

    # The source suite contains relative includes that escape tests/, so retain
    # the checkout's tests/ + inc/ sibling relationship in the sandbox.
    test_dir = work_dir / "tests"
    shutil.copytree(args.source_tests_dir, test_dir)
    shutil.copytree(args.source_include_dir, work_dir / "inc")

    compiler = install_prefix / "bin" / "fbc"
    if not compiler.is_file():
        compiler = compiler.with_suffix(".exe")
    compiler_include_dir = install_prefix / "include" / "freebasic"
    if not compiler.is_file() or not compiler_include_dir.is_dir():
        raise FileNotFoundError("CMake installation did not contain fbc and its include directory")

    fbc_command = " ".join([str(compiler), "-i", str(compiler_include_dir), *args.fbc_flag])
    run(
        [
            str(args.make),
            "log-tests",
            f"FBC={fbc_command}",
        ],
        cwd=test_dir,
        log=log_path,
    )
    require_no_recorded_failures(test_dir)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
