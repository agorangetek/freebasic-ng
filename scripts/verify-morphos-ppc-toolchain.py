#!/usr/bin/env python3
"""Validate the pinned MorphOS PowerPC SDK inventory without network access."""

import json
import re
import subprocess
import sys
from argparse import ArgumentParser
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
LOCK_FILE = ROOT / "cmake" / "toolchains" / "morphos-ppc.lock.json"
SHA256 = re.compile(r"[0-9a-f]{64}\Z")


def fail(message: str) -> None:
    print(f"MorphOS/PPC toolchain lock error: {message}", file=sys.stderr)
    raise SystemExit(1)


def require_string(value: object, field: str) -> str:
    if not isinstance(value, str) or not value:
        fail(f"{field} must be a non-empty string")
    return value


def require_boolean(value: object, field: str) -> bool:
    if not isinstance(value, bool):
        fail(f"{field} must be a boolean")
    return value


def command_output(command: Path, argument: str) -> str:
    try:
        return subprocess.check_output(
            [command, argument], text=True, stderr=subprocess.STDOUT
        )
    except (OSError, subprocess.CalledProcessError) as error:
        fail(f"could not execute {command} {argument}: {error}")


def main() -> None:
    parser = ArgumentParser()
    parser.add_argument("--github-env", type=Path,
                        help="append pinned CI environment variables to this file")
    parser.add_argument("--verify-installed", action="store_true",
                        help="also inspect the SDK at its pinned absolute path")
    arguments = parser.parse_args()

    try:
        data = json.loads(LOCK_FILE.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as error:
        fail(f"cannot read {LOCK_FILE}: {error}")

    if not isinstance(data, dict) or data.get("schema") != 1:
        fail("schema must be 1")

    target = data.get("target")
    if not isinstance(target, dict) or target.get("os") != "morphos" or target.get("architecture") != "powerpc":
        fail("target must be MorphOS/PowerPC")
    if target.get("support_level") not in {"unqualified", "preview", "supported"}:
        fail("target.support_level must be unqualified, preview, or supported")

    toolchain = data.get("toolchain")
    if not isinstance(toolchain, dict) or toolchain.get("provisioning") != "container":
        fail("toolchain must be provisioned from a container")
    image = require_string(toolchain.get("image"), "toolchain.image")
    _, separator, digest = image.partition("@sha256:")
    if not separator or not SHA256.fullmatch(digest):
        fail("toolchain.image must use a full sha256 digest")
    sdk_root = Path(require_string(toolchain.get("sdk_root"), "toolchain.sdk_root"))

    compiler = toolchain.get("compiler")
    linker = toolchain.get("linker")
    c_runtime = toolchain.get("c_runtime")
    if not isinstance(compiler, dict) or not isinstance(linker, dict) or not isinstance(c_runtime, dict):
        fail("toolchain compiler, linker, and c_runtime must be objects")
    compiler_command = require_string(compiler.get("command"), "toolchain.compiler.command")
    compiler_target = require_string(compiler.get("target"), "toolchain.compiler.target")
    compiler_version = require_string(compiler.get("version"), "toolchain.compiler.version")
    linker_command = require_string(linker.get("command"), "toolchain.linker.command")
    linker_version = require_string(linker.get("version"), "toolchain.linker.version")
    require_string(linker.get("output_format"), "toolchain.linker.output_format")
    if c_runtime.get("flag") != "-noixemul" or c_runtime.get("flavour") != "libnix":
        fail("toolchain.c_runtime must select the native libnix ABI with -noixemul")

    validation = data.get("validation")
    if not isinstance(validation, dict):
        fail("validation must be an object")
    runtime_archive = require_boolean(validation.get("runtime_archive"),
                                      "validation.runtime_archive")
    freebasic_executable = require_boolean(validation.get("freebasic_executable"),
                                           "validation.freebasic_executable")
    runtime_marker = require_boolean(validation.get("runtime_marker"),
                                     "validation.runtime_marker")
    process_exit = require_boolean(validation.get("process_exit"),
                                   "validation.process_exit")
    if target["support_level"] == "supported" and not (
        runtime_archive and freebasic_executable and runtime_marker and process_exit
    ):
        fail("supported requires archive, executable, marker, and process-exit validation")

    compiler_path = sdk_root / "bin" / compiler_command
    linker_path = sdk_root / "bin" / linker_command

    if arguments.verify_installed:
        for path in (
            sdk_root / "os-include",
            sdk_root / "lib",
            sdk_root / "ppc-morphos" / "lib" / "libnix",
        ):
            if not path.is_dir():
                fail(f"required SDK directory is missing: {path}")
        for path in (compiler_path, linker_path):
            if not path.is_file():
                fail(f"required SDK tool is missing: {path}")

        if command_output(compiler_path, "-dumpmachine").strip() != compiler_target:
            fail(f"{compiler_command} does not target {compiler_target}")
        if compiler_version not in command_output(compiler_path, "--version"):
            fail(f"{compiler_command} does not report version {compiler_version}")
        if linker_version not in command_output(linker_path, "-V"):
            fail(f"{linker_command} does not report version {linker_version}")

    if arguments.github_env:
        arguments.github_env.open("a", encoding="utf-8").write(
            f"MORPHOS_GCC_IMAGE={image}\n"
        )

    if arguments.verify_installed:
        print("validated installed MorphOS/PowerPC SDK against its pinned lock")
    else:
        print("validated pinned MorphOS/PowerPC toolchain input")


if __name__ == "__main__":
    main()
