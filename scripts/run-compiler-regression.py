#!/usr/bin/env python3
"""Compile and execute a self-contained FreeBASIC compiler regression."""

from __future__ import annotations

import argparse
import shutil
import subprocess
from pathlib import Path


def locate(tool: Path) -> Path:
    """Accept a path or a bare name looked up on PATH.

    The Windows test registration passes plain names, because MSYS Python
    reads a C:/... argument as a relative POSIX path.
    """

    if tool.is_file():
        return tool.resolve()
    located = shutil.which(str(tool))
    if located is None:
        return tool
    return Path(located)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--cmake", type=Path, required=True)
    parser.add_argument("--build-dir", type=Path, required=True)
    parser.add_argument("--install-prefix", type=Path, required=True)
    parser.add_argument("--source", type=Path, required=True)
    parser.add_argument(
        "--library-source",
        type=Path,
        help="source compiled with -dylib into the work directory first",
    )
    parser.add_argument("--work-dir", type=Path, required=True)
    parser.add_argument(
        "--fbc-flag",
        action="append",
        default=[],
        help="extra option passed to fbc; repeat for several options",
    )
    args = parser.parse_args()

    cmake = locate(args.cmake)
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
    library_source = args.library_source
    if library_source is not None:
        library_source = library_source.resolve()
        if not library_source.is_file():
            parser.error(f"library source does not exist: {library_source}")

    shutil.rmtree(install_prefix, ignore_errors=True)
    shutil.rmtree(work_dir, ignore_errors=True)
    subprocess.run(
        [str(cmake), "--install", str(build_dir), "--prefix", str(install_prefix)],
        check=True,
    )
    if not fbc.is_file() and fbc.with_suffix(".exe").is_file():
        fbc = fbc.with_suffix(".exe")
    if not fbc.is_file():
        raise RuntimeError(f"installed compiler does not exist: {fbc}")
    work_dir.mkdir(parents=True)
    if library_source is not None:
        # The library is built without -x so that fbc picks the platform's own
        # name for it, which is what the runtime looks for when loading it.
        staged_source = work_dir / library_source.name
        shutil.copyfile(library_source, staged_source)
        subprocess.run(
            [str(fbc), "-dylib", staged_source.name], check=True, cwd=work_dir
        )
    subprocess.run(
        [str(fbc), *args.fbc_flag, str(source), "-x", str(executable)],
        check=True,
    )
    if not executable.is_file() and executable.with_suffix(".exe").is_file():
        executable = executable.with_suffix(".exe")
    subprocess.run([str(executable)], check=True, cwd=work_dir)


if __name__ == "__main__":
    main()
