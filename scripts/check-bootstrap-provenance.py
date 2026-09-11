#!/usr/bin/env python3
"""Verify the exact generated-C bootstrap selected by a CMake host build."""

from __future__ import annotations

import argparse
import hashlib
import json
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
MANIFEST = ROOT / "bootstrap" / "provenance.json"


def bootstrap_hash(directory: Path) -> tuple[int, str]:
    sources = sorted(directory.glob("*.c"), key=lambda path: path.name)
    digest = hashlib.sha256()
    for source in sources:
        digest.update(source.name.encode("utf-8"))
        digest.update(b"\0")
        digest.update(source.read_bytes())
        digest.update(b"\0")
    return len(sources), digest.hexdigest()


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--target", help="CMake FB_TARGET_ID to verify")
    parser.add_argument("--print", action="store_true", dest="print_hashes",
                        help="print hashes for all declared bootstrap directories")
    args = parser.parse_args()

    data = json.loads(MANIFEST.read_text(encoding="utf-8"))
    if data.get("schema") != 1:
        raise ValueError(f"unsupported provenance schema in {MANIFEST}")
    sources = data.get("bootstrap_sources", {})

    if args.print_hashes:
        for target in sorted(sources):
            count, digest = bootstrap_hash(ROOT / "bootstrap" / target)
            print(f"{target} {count} {digest}")
        return 0

    if not args.target:
        parser.error("--target is required unless --print is used")
    entry = sources.get(args.target)
    if entry is None:
        print(f"no recorded bootstrap provenance for target '{args.target}'", file=sys.stderr)
        return 1

    directory = ROOT / "bootstrap" / args.target
    count, digest = bootstrap_hash(directory)
    problems = []
    if count != entry["files"]:
        problems.append(f"expected {entry['files']} C files, found {count}")
    if digest != entry["sha256"]:
        problems.append("generated-C SHA-256 does not match bootstrap/provenance.json")
    if problems:
        print(f"bootstrap provenance failed for {args.target}: {'; '.join(problems)}", file=sys.stderr)
        return 1
    print(f"verified bootstrap {args.target}: {count} C sources")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
