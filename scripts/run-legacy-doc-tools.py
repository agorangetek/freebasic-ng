#!/usr/bin/env python3
"""Build historic documentation tools from a staged CMake compiler.

The legacy tool makefiles create libraries and executables next to their
sources.  This adapter copies doc/ into the CMake binary tree and invokes only
those three local makefiles, leaving the checkout untouched.
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


def run(command: list[str], *, log: Path) -> None:
    print("+", " ".join(command), flush=True)
    with log.open("a", encoding="utf-8") as output:
        result = subprocess.run(
            command,
            stdout=output,
            stderr=subprocess.STDOUT,
            text=True,
            check=False,
        )
    if result.returncode:
        print(f"legacy documentation tools failed; full log: {log}", file=sys.stderr)
        with log.open("r", encoding="utf-8", errors="replace") as output:
            sys.stderr.writelines(output.readlines()[-80:])
        raise subprocess.CalledProcessError(result.returncode, command)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cmake", required=True, type=Path)
    parser.add_argument("--make", required=True, type=Path)
    parser.add_argument("--build-dir", required=True, type=Path)
    parser.add_argument("--install-prefix", required=True, type=Path)
    parser.add_argument("--source-doc-dir", required=True, type=Path)
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
    if not args.source_doc_dir.is_dir():
        raise FileNotFoundError(f"legacy documentation directory is missing: {args.source_doc_dir}")

    shutil.rmtree(install_prefix, ignore_errors=True)
    shutil.rmtree(work_dir, ignore_errors=True)
    log_path.parent.mkdir(parents=True, exist_ok=True)
    log_path.write_text("", encoding="utf-8")

    run([
        str(args.cmake),
        "--install",
        str(build_dir),
        "--prefix",
        str(install_prefix),
    ], log=log_path)

    compiler = install_prefix / "bin" / "fbc"
    if not compiler.is_file():
        compiler = compiler.with_suffix(".exe")
    compiler_include_dir = install_prefix / "include" / "freebasic"
    if not compiler.is_file() or not compiler_include_dir.is_dir():
        raise FileNotFoundError("CMake installation did not contain fbc and its include directory")

    doc_dir = work_dir / "doc"
    shutil.copytree(args.source_doc_dir, doc_dir)
    fbc = " ".join([str(compiler), "-i", str(compiler_include_dir), *args.fbc_flag])
    make_args = [f"FBC={fbc}", "HAVE_ASPELL=1"]
    for component in ("libfbdoc", "fbdoc", "fbchkdoc"):
        run([str(args.make), "-C", str(doc_dir / component), *make_args], log=log_path)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
