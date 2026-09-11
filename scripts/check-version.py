#!/usr/bin/env python3
"""Reject divergence between the FreeBASIC-NG versioning surfaces."""

from __future__ import annotations

import json
import pathlib
import re
import sys


ROOT = pathlib.Path(__file__).resolve().parents[1]


def fail(message: str) -> None:
    print(f"version check failed: {message}", file=sys.stderr)
    raise SystemExit(1)


version_match = re.search(
    r"^FBVERSION\s*:=\s*(\d+\.\d+\.\d+)\s*$",
    (ROOT / "version.mk").read_text(encoding="utf-8"),
    re.MULTILINE,
)
if version_match is None:
    fail("version.mk has no semantic FBVERSION")

version = version_match.group(1)
manifest = json.loads((ROOT / ".release-please-manifest.json").read_text(encoding="utf-8"))
if manifest.get(".") != version:
    fail(f"release-please manifest is {manifest.get('.')!r}, expected {version!r}")

cmake = (ROOT / "CMakeLists.txt").read_text(encoding="utf-8")
if "project(FreeBASICNG VERSION ${FREEBASIC_NG_VERSION}" not in cmake:
    fail("CMake does not derive its project version from version.mk")

print(f"version metadata consistent: {version}")
