#!/usr/bin/env python3
"""Run the historical unit suite from a CMake-built, staged compiler.

The historical tests makefiles create objects and logs next to their inputs.
This adapter recreates the source layout required by the test suite in the
CMake binary tree, so CTest can own the execution without modifying the
checkout or invoking the root makefile.
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


def run(
    command: list[str],
    *,
    cwd: Path | None = None,
    log: Path | None = None,
    expect_failure: bool = False,
    failure_marker: str | None = None,
) -> None:
    print("+", " ".join(command), flush=True)
    if log is None:
        result = subprocess.run(command, cwd=cwd, check=False)
    else:
        with log.open("w", encoding="utf-8") as output:
            result = subprocess.run(
                command,
                cwd=cwd,
                stdout=output,
                stderr=subprocess.STDOUT,
                text=True,
                check=False,
            )

    if expect_failure:
        if result.returncode == 0:
            raise RuntimeError("legacy unit suite unexpectedly accepted the injected failure")
        if log is not None and failure_marker is not None:
            output = log.read_text(encoding="utf-8", errors="replace")
            if failure_marker not in output:
                raise RuntimeError(
                    "legacy unit suite failed without executing the injected fixture"
                )
        print("legacy unit suite rejected the injected failure as expected", flush=True)
        return

    if result.returncode:
        if log is not None:
            print(f"legacy unit suite failed; full log: {log}", file=sys.stderr)
            with log.open("r", encoding="utf-8", errors="replace") as output:
                tail = output.readlines()[-80:]
            sys.stderr.writelines(tail)
        raise subprocess.CalledProcessError(result.returncode, command)


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
    parser.add_argument("--inject-failing-fixture", action="store_true")
    parser.add_argument("--expect-failure", action="store_true")
    args = parser.parse_args()

    if args.expect_failure != args.inject_failing_fixture:
        parser.error("--expect-failure requires --inject-failing-fixture and vice versa")

    build_dir = args.build_dir.resolve()
    install_prefix = args.install_prefix.resolve()
    work_dir = args.work_dir.resolve()
    log_path = args.log.resolve()

    require_child(install_prefix, build_dir, "install prefix")
    require_child(work_dir, build_dir, "test work directory")
    require_child(log_path, build_dir, "test log")

    # A prior CTest invocation may have left a failed test tree or staging
    # area.  Both are verified CMake-build children before being recreated.
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

    # Some historic tests include headers via paths such as
    # "..\\..\\inc\\fbthread.bi".  Keep tests/ and inc/ as siblings, just as
    # they are in the source checkout, rather than rewriting that input.
    test_dir = work_dir / "tests"
    legacy_include_dir = work_dir / "inc"
    shutil.copytree(args.source_tests_dir, test_dir)
    shutil.copytree(args.source_include_dir, legacy_include_dir)

    if args.inject_failing_fixture:
        # This source exists only in CMake's copied work tree.  It proves that
        # the adapter fails for a genuine fbcunit assertion, not merely for a
        # missing file or a compiler invocation error.
        fixture = test_dir / "boolean" / "cmake_failure_detection.bas"
        fixture.write_text(
            "#include once \"fbcunit.bi\"\n\n"
            "SUITE( fbc_tests.cmake_failure_detection_ )\n"
            "    TEST( intentionally_fails )\n"
            "        CU_FAIL( cmake_failure_detection )\n"
            "    END_TEST\n"
            "END_SUITE\n",
            encoding="utf-8",
        )

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
            "unit-tests",
            f"FBC={fbc_command}",
            "UNITTEST_RUN_ARGS=--brief-summary",
        ],
        cwd=test_dir,
        log=log_path,
        expect_failure=args.expect_failure,
        failure_marker="cmake_failure_detection" if args.expect_failure else None,
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
