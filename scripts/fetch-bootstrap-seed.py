#!/usr/bin/env python3
"""Fetch and verify the minimal host compiler seed declared by provenance."""

from __future__ import annotations

import argparse
import hashlib
import io
import json
import os
from pathlib import Path
import re
import tarfile
import tempfile
from urllib.request import Request, urlopen
import zipfile


HEX256 = re.compile(r"^[0-9a-f]{64}$")
ROOT = Path(__file__).resolve().parents[1]


class SeedError(RuntimeError):
    pass


def fail(message: str) -> None:
    raise SeedError(message)


def sha256_file(filename: Path) -> str:
    digest = hashlib.sha256()
    with filename.open("rb") as source:
        for chunk in iter(lambda: source.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def safe_filename(value: object, label: str) -> str:
    if not isinstance(value, str) or not value or Path(value).name != value:
        fail(f"{label} must be a non-empty filename")
    return value


def required_hash(value: object, label: str) -> str:
    if not isinstance(value, str) or HEX256.fullmatch(value) is None:
        fail(f"{label} must be a lowercase SHA-256 digest")
    return value


def safe_member(value: object) -> str:
    if not isinstance(value, str) or not value:
        fail("member must be a non-empty archive member name")
    member = value[2:] if value.startswith("./") else value
    if member.startswith("/") or any(part in ("", ".", "..") for part in member.split("/")):
        fail("member is not a safe relative archive member name")
    return member


def load_entry(manifest: Path, target: str) -> dict[str, str]:
    try:
        data = json.loads(manifest.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as error:
        fail(f"cannot read provenance manifest: {error}")
    if data.get("schema") != 1:
        fail("unsupported seed provenance schema")
    seeds = data.get("seeds")
    if not isinstance(seeds, dict):
        fail("provenance manifest has no seeds object")
    entry = seeds.get(target)
    if not isinstance(entry, dict):
        fail(f"no seed declared for target {target!r}")
    if entry.get("host") != target:
        fail(f"seed host identity does not match target {target!r}")
    url = entry.get("url")
    archive_format = entry.get("format")
    if not isinstance(url, str) or not url.startswith("https://"):
        fail("seed URL must use HTTPS")
    if archive_format not in {"deb", "tar.xz", "zip"}:
        fail("seed format must be deb, tar.xz or zip")
    return {
        "asset": safe_filename(entry.get("asset"), "asset"),
        "asset_sha256": required_hash(entry.get("asset_sha256"), "asset_sha256"),
        "format": archive_format,
        "member": safe_member(entry.get("member")),
        "seed": safe_filename(entry.get("seed"), "seed"),
        "seed_sha256": required_hash(entry.get("seed_sha256"), "seed_sha256"),
        "url": url,
    }


def ensure_directory(directory: Path) -> None:
    if directory.is_symlink():
        fail(f"cache directory must not be a symlink: {directory}")
    directory.mkdir(parents=True, exist_ok=True)
    if not directory.is_dir() or directory.is_symlink():
        fail(f"cache directory is not a safe directory: {directory}")


def write_atomic(destination: Path, contents: bytes, executable: bool) -> None:
    ensure_directory(destination.parent)
    with tempfile.NamedTemporaryFile(dir=destination.parent, delete=False) as output:
        output.write(contents)
        output.flush()
        os.fsync(output.fileno())
        temporary = Path(output.name)
    temporary.chmod(0o755 if executable else 0o644)
    temporary.replace(destination)


def download_asset(url: str, destination: Path, expected_digest: str) -> None:
    request = Request(url, headers={"User-Agent": "freebasic-ng-bootstrap-seed/1"})
    try:
        with urlopen(request) as response:
            with tempfile.NamedTemporaryFile(dir=destination.parent, delete=False) as output:
                for chunk in iter(lambda: response.read(1024 * 1024), b""):
                    output.write(chunk)
                output.flush()
                os.fsync(output.fileno())
                temporary = Path(output.name)
    except OSError as error:
        fail(f"could not download seed asset: {error}")
    actual_digest = sha256_file(temporary)
    if actual_digest != expected_digest:
        temporary.unlink(missing_ok=True)
        fail(f"downloaded asset SHA-256 is {actual_digest}, expected {expected_digest}")
    temporary.chmod(0o644)
    temporary.replace(destination)


def read_tar_member(archive: tarfile.TarFile, wanted: str) -> bytes:
    for candidate in (wanted, f"./{wanted}"):
        try:
            member = archive.getmember(candidate)
        except KeyError:
            continue
        if not member.isfile():
            fail(f"archive member is not a regular file: {wanted}")
        extracted = archive.extractfile(member)
        if extracted is None:
            fail(f"could not read archive member: {wanted}")
        return extracted.read()
    fail(f"archive does not contain expected member: {wanted}")


def read_deb_member(asset: Path, wanted: str) -> bytes:
    with asset.open("rb") as source:
        if source.read(8) != b"!<arch>\n":
            fail(f"{asset} is not a Debian ar archive")
        data_tar = None
        while header := source.read(60):
            if len(header) != 60 or header[58:60] != b"\x60\n":
                fail(f"{asset} has a malformed ar header")
            name = header[:16].decode("ascii", "strict").strip().rstrip("/")
            try:
                length = int(header[48:58].decode("ascii", "strict").strip())
            except ValueError as error:
                fail(f"{asset} has an invalid ar member length: {error}")
            contents = source.read(length)
            if len(contents) != length:
                fail(f"{asset} ended inside ar member {name!r}")
            if length % 2:
                source.read(1)
            if name.startswith("data.tar"):
                data_tar = contents
                break
    if data_tar is None:
        fail(f"{asset} does not contain data.tar")
    with tarfile.open(fileobj=io.BytesIO(data_tar), mode="r:*") as archive:
        return read_tar_member(archive, wanted)


def extract_seed(asset: Path, entry: dict[str, str]) -> bytes:
    if entry["format"] == "deb":
        return read_deb_member(asset, entry["member"])
    if entry["format"] == "tar.xz":
        with tarfile.open(asset, mode="r:xz") as archive:
            return read_tar_member(archive, entry["member"])
    with zipfile.ZipFile(asset) as archive:
        try:
            info = archive.getinfo(entry["member"])
        except KeyError:
            fail(f"archive does not contain expected member: {entry['member']}")
        if info.is_dir():
            fail(f"archive member is not a regular file: {entry['member']}")
        return archive.read(info)


def materialize_seed(manifest: Path, target: str, cache_directory: Path) -> Path:
    entry = load_entry(manifest, target)
    target_directory = cache_directory / target
    ensure_directory(target_directory)
    seed = target_directory / entry["seed"]
    if seed.exists():
        if not seed.is_file() or seed.is_symlink():
            fail(f"cached seed is not a regular file: {seed}")
        if sha256_file(seed) == entry["seed_sha256"]:
            seed.chmod(0o755)
            return seed
        seed.unlink()

    asset = target_directory / entry["asset"]
    if asset.exists():
        if not asset.is_file() or asset.is_symlink():
            fail(f"cached asset is not a regular file: {asset}")
        if sha256_file(asset) != entry["asset_sha256"]:
            asset.unlink()
    if not asset.exists():
        download_asset(entry["url"], asset, entry["asset_sha256"])
    contents = extract_seed(asset, entry)
    actual_digest = hashlib.sha256(contents).hexdigest()
    if actual_digest != entry["seed_sha256"]:
        fail(f"extracted seed SHA-256 is {actual_digest}, expected {entry['seed_sha256']}")
    write_atomic(seed, contents, executable=True)
    return seed


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--manifest", type=Path,
                        default=ROOT / "bootstrap" / "seed-provenance.json")
    parser.add_argument("--target", required=True, help="CMake FB_TARGET_ID")
    parser.add_argument("--cache-dir", type=Path, required=True)
    args = parser.parse_args()
    try:
        print(materialize_seed(args.manifest, args.target, args.cache_dir))
    except SeedError as error:
        raise SystemExit(f"bootstrap seed failed: {error}") from error
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
