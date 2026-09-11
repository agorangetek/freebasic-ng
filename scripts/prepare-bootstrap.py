#!/usr/bin/env python3
"""Prepare a version-correct derived C bootstrap for one CMake build.

The checked-in bootstrap C is an independently verified input produced from the
upstream baseline.  Its generated compiler-version literals consequently name
that baseline.  CMake must, however, build a compiler whose public version is
the version declared by ``version.mk``.  This script copies a verified bootstrap
into the build directory and changes only those generated literals, checking
the exact generated-C shape before every replacement.

The source bootstrap is never modified.  Its digest remains the provenance
anchor checked before this script runs; the small, deterministic derivation is
therefore reproducible and fails closed if a future bootstrap generator changes
the relevant C layout.
"""

from __future__ import annotations

import argparse
import json
import re
import shutil
from pathlib import Path


SEMVER = re.compile(r"^(?P<major>\d+)\.(?P<minor>\d+)\.(?P<patch>\d+)$")


def fail(message: str) -> None:
    raise SystemExit(f"bootstrap preparation failed: {message}")


def replace_exactly_once(text: str, pattern: re.Pattern[str], replacement: str,
                         *, label: str, path: Path) -> str:
    text, count = pattern.subn(replacement, text)
    if count != 1:
        fail(f"{path}: expected one {label} literal, found {count}")
    return text


def prepare_file(path: Path, *, source_version: str, version: str,
                 parts: dict[str, str]) -> str:
    text = path.read_text(encoding="utf-8")

    if path.name == "fbc.c":
        prefix = "FreeBASIC Compiler - Version "
        pattern = re.compile(
            rf'(\(void\*\)"{re.escape(prefix)}{re.escape(source_version)}'
            rf'(?P<suffix> \([^"\\]*\), built for )", )(?P<length>\d+)ll'
        )

        def replace_banner(match: re.Match[str]) -> str:
            literal = f"{prefix}{version}{match.group('suffix')}"
            return f'(void*)"{literal}", {len(literal)}ll'

        text, count = pattern.subn(replace_banner, text)
        if count != 1:
            fail(f"{path}: expected one compiler-version banner, found {count}")

    if path.name == "ir-gas64.c":
        prefix = "FreeBASIC "
        pattern = re.compile(
            rf'(\(void\*\)"{re.escape(prefix)}{re.escape(source_version)}", )\d+ll'
        )
        literal = f"{prefix}{version}"
        text = replace_exactly_once(
            text, pattern, f'(void*)"{literal}", {len(literal)}ll',
            label="debug-signature", path=path,
        )

    if path.name == "symb-define.c":
        replacements = {
            "__FB_VERSION__": version,
            "__FB_VER_MAJOR__": parts["major"],
            "__FB_VER_MINOR__": parts["minor"],
            "__FB_VER_PATCH__": parts["patch"],
            "__FB_SIGNATURE__": f"FreeBASIC {version}",
        }
        previous = {
            "__FB_VERSION__": source_version,
            "__FB_VER_MAJOR__": source_version.split(".")[0],
            "__FB_VER_MINOR__": source_version.split(".")[1],
            "__FB_VER_PATCH__": source_version.split(".")[2],
            "__FB_SIGNATURE__": f"FreeBASIC {source_version}",
        }
        for name, value in replacements.items():
            pattern = re.compile(
                rf'(\(char\*\)"{re.escape(name)}", \(char\*\)")'
                rf'{re.escape(previous[name])}(", )'
            )
            text = replace_exactly_once(
                text, pattern, rf'\g<1>{value}\g<2>',
                label=name, path=path,
            )

    if source_version in text:
        fail(f"{path}: source bootstrap version {source_version} remains after preparation")
    return text


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source-dir", type=Path, required=True)
    parser.add_argument("--output-dir", type=Path, required=True)
    parser.add_argument("--version", required=True)
    parser.add_argument("--manifest", type=Path, required=True)
    args = parser.parse_args()

    match = SEMVER.fullmatch(args.version)
    if match is None:
        fail(f"version is not a three-component semantic version: {args.version!r}")
    parts = match.groupdict()

    if not args.source_dir.is_dir() or args.source_dir.is_symlink():
        fail(f"source directory is not a safe directory: {args.source_dir}")
    if args.output_dir.is_symlink():
        fail(f"output directory must not be a symlink: {args.output_dir}")

    manifest = json.loads(args.manifest.read_text(encoding="utf-8"))
    source_version = manifest.get("generator", {}).get("version")
    if not isinstance(source_version, str) or SEMVER.fullmatch(source_version) is None:
        fail("bootstrap provenance manifest has no semantic generator.version")

    sources = sorted(args.source_dir.glob("*.c"), key=lambda item: item.name)
    if not sources:
        fail(f"source directory contains no C sources: {args.source_dir}")

    args.output_dir.mkdir(parents=True, exist_ok=True)
    for source in sources:
        target = args.output_dir / source.name
        rendered = prepare_file(
            source, source_version=source_version, version=args.version, parts=parts
        )
        target.write_text(rendered, encoding="utf-8", newline="")
        shutil.copymode(source, target)

    print(
        f"prepared {len(sources)} bootstrap C sources from {source_version} "
        f"for FreeBASIC-NG {args.version}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
