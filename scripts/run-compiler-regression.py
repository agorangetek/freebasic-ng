#!/usr/bin/env python3
"""Compile and execute a self-contained FreeBASIC compiler regression."""

from __future__ import annotations

import argparse
import shutil
import subprocess
from pathlib import Path


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--cmake", type=Path, required=True)
    parser.add_argument("--build-dir", type=Path, required=True)
    parser.add_argument("--install-prefix", type=Path, required=True)
    parser.add_argument("--source", type=Path, required=True)
    parser.add_argument("--work-dir", type=Path, required=True)
    args = parser.parse_args()

    cmake = args.cmake.resolve()
    build_dir = args.build_dir.resolve()
    install_prefix = args.install_prefix.resolve()
    source = args.source.resolve()
    work_dir = args.work_dir.resolve()
    fbc = install_prefix / "bin" / "fbc"
    executable = work_dir / source.stem

    if not cmake.is_file():
        parser.error(f"CMake executable does not exist: {cmake}")
    if not build_dir.is_dir():
        parser.error(f"CMake build directory does not exist: {build_dir}")
    if not source.is_file():
        parser.error(f"regression source does not exist: {source}")

    shutil.rmtree(install_prefix, ignore_errors=True)
    shutil.rmtree(work_dir, ignore_errors=True)
    subprocess.run(
        [str(cmake), "--install", str(build_dir), "--prefix", str(install_prefix)],
        check=True,
    )
    if not fbc.is_file():
        raise RuntimeError(f"installed compiler does not exist: {fbc}")
    work_dir.mkdir(parents=True)
    subprocess.run([str(fbc), str(source), "-x", str(executable)], check=True)
    subprocess.run([str(executable)], check=True)


if __name__ == "__main__":
    main()
