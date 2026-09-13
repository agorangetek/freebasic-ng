#!/usr/bin/env python3
"""Prove a versioned release archive can replace an earlier installation.

Release archives intentionally contain a versioned top-level directory.  The
supported archive upgrade is therefore a directory replacement: extract the
new archive, replace the active installation directory, then use the compiler
from that stable location.  This helper makes that contract explicit and
proves files no longer present in the candidate cannot survive the operation.
"""

from __future__ import annotations

import argparse
import os
from pathlib import Path, PurePosixPath
import shutil
import stat
import tarfile
import zipfile


def fail(message: str) -> None:
    raise RuntimeError(message)


def validate_member_name(name: str, archive: Path) -> PurePosixPath:
    path = PurePosixPath(name)
    if not name or path.is_absolute() or ".." in path.parts:
        fail(f"unsafe member {name!r} in {archive}")
    return path


def extract_archive(archive: Path, destination: Path) -> Path:
    """Safely extract one release archive and return its sole top-level dir."""
    top_levels: set[str] = set()

    if archive.name.endswith(".tar.xz"):
        with tarfile.open(archive, mode="r:xz") as input_archive:
            members = input_archive.getmembers()
            for member in members:
                path = validate_member_name(member.name, archive)
                if member.issym() or member.islnk() or member.isdev():
                    fail(f"unsupported link or device member {member.name!r} in {archive}")
                top_levels.add(path.parts[0])
            input_archive.extractall(destination, members=members)
    elif archive.suffix == ".zip":
        with zipfile.ZipFile(archive) as input_archive:
            members = input_archive.infolist()
            for member in members:
                path = validate_member_name(member.filename, archive)
                mode = member.external_attr >> 16
                if stat.S_ISLNK(mode):
                    fail(f"unsupported link member {member.filename!r} in {archive}")
                top_levels.add(path.parts[0])
            input_archive.extractall(destination, members=members)
    else:
        fail(f"unsupported release archive format: {archive}")

    if len(top_levels) != 1:
        fail(f"expected one top-level directory in {archive}, found {sorted(top_levels)!r}")
    root = destination / next(iter(top_levels))
    if not root.is_dir():
        fail(f"archive root is not a directory: {root}")
    return root


def files_below(root: Path) -> set[Path]:
    return {
        path.relative_to(root)
        for path in root.rglob("*")
        if path.is_file()
    }


def compiler_exists(prefix: Path) -> bool:
    bindir = prefix / "bin"
    return (bindir / "fbc").is_file() or (bindir / "fbc.exe").is_file()


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--previous", type=Path, required=True,
                        help="archive from the preceding stable release")
    parser.add_argument("--candidate", type=Path, required=True,
                        help="archive built for the release candidate")
    parser.add_argument("--work-dir", type=Path, required=True,
                        help="new, disposable qualification directory")
    args = parser.parse_args()

    previous = args.previous.resolve(strict=True)
    candidate = args.candidate.resolve(strict=True)
    work_dir = args.work_dir.resolve()
    if work_dir.exists():
        fail(f"qualification work directory already exists: {work_dir}")
    work_dir.mkdir(parents=True)

    previous_root = extract_archive(previous, work_dir / "previous")
    candidate_root = extract_archive(candidate, work_dir / "candidate")
    if previous_root.name == candidate_root.name:
        fail("previous and candidate archives have the same top-level directory")
    if not compiler_exists(previous_root):
        fail(f"previous archive contains no compiler below {previous_root / 'bin'}")
    if not compiler_exists(candidate_root):
        fail(f"candidate archive contains no compiler below {candidate_root / 'bin'}")

    previous_files = files_below(previous_root)
    candidate_files = files_below(candidate_root)
    active = work_dir / "active"
    os.replace(previous_root, active)
    if previous_root.exists() or not compiler_exists(active):
        fail("could not install the previous archive into the active prefix")

    # Directory replacement is intentional: an archive does not have a
    # package database capable of removing files dropped by a later release.
    shutil.rmtree(active)
    os.replace(candidate_root, active)
    if candidate_root.exists() or not compiler_exists(active):
        fail("could not replace the active prefix with the candidate archive")

    stale_files = previous_files - candidate_files
    remaining = sorted(path.as_posix() for path in stale_files if (active / path).exists())
    if remaining:
        fail(f"archive replacement left stale files: {remaining!r}")

    print(active)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
