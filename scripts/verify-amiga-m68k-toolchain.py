#!/usr/bin/env python3
"""Validate the pinned AmigaOS/m68k toolchain inventory without network access."""

import json
import re
import sys
from argparse import ArgumentParser
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
LOCK_FILE = ROOT / "cmake" / "toolchains" / "amiga-m68k.lock.json"
SHA256 = re.compile(r"[0-9a-f]{64}\Z")


def fail(message: str) -> None:
    print(f"AmigaOS/m68k toolchain lock error: {message}", file=sys.stderr)
    raise SystemExit(1)


def require_string(value: object, field: str) -> str:
    if not isinstance(value, str) or not value:
        fail(f"{field} must be a non-empty string")
    return value


def require_boolean(value: object, field: str) -> bool:
    if not isinstance(value, bool):
        fail(f"{field} must be a boolean")
    return value


def package_version(packages: list[object], package: str) -> str:
    prefix = f"{package}=="
    matches = [item[len(prefix):] for item in packages
               if isinstance(item, str) and item.startswith(prefix)]
    if len(matches) != 1 or not matches[0]:
        fail(f"runner.packages must contain one {package} version pin")
    return matches[0]


def main() -> None:
    parser = ArgumentParser()
    parser.add_argument("--github-env", type=Path,
                        help="append pinned CI environment variables to this file")
    arguments = parser.parse_args()

    try:
        data = json.loads(LOCK_FILE.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as error:
        fail(f"cannot read {LOCK_FILE}: {error}")

    if not isinstance(data, dict) or data.get("schema") != 1:
        fail("schema must be 1")

    policy = data.get("policy")
    if not isinstance(policy, dict):
        fail("policy must be an object")
    require_string(policy.get("release_qualified_support"),
                   "policy.release_qualified_support")
    require_string(policy.get("generated_c_only"), "policy.generated_c_only")

    target = data.get("target")
    if not isinstance(target, dict):
        fail("target must be an object")
    if target.get("os") != "amiga" or target.get("architecture") != "m68k":
        fail("target must be AmigaOS/m68k")
    if target.get("support_level") not in {"preview", "supported"}:
        fail("target.support_level must be preview or supported")

    toolchain = data.get("toolchain")
    if not isinstance(toolchain, dict) or toolchain.get("provisioning") != "container":
        fail("toolchain must be provisioned from a container")
    image = require_string(toolchain.get("image"), "toolchain.image")
    _, separator, digest = image.partition("@sha256:")
    if not separator or not SHA256.fullmatch(digest):
        fail("toolchain.image must use a full sha256 digest")
    compiler = toolchain.get("compiler")
    if not isinstance(compiler, dict):
        fail("toolchain.compiler must be an object")
    require_string(compiler.get("command"), "toolchain.compiler.command")
    require_string(compiler.get("version"), "toolchain.compiler.version")
    require_string(toolchain.get("sdk_root"), "toolchain.sdk_root")

    runner = data.get("runner")
    if not isinstance(runner, dict):
        fail("runner must be an object")
    if runner.get("kind") != "emulator" or runner.get("name") != "Vamos":
        fail("runner must name the current Vamos emulator")
    packages = runner.get("packages")
    if not isinstance(packages, list) or not all(isinstance(item, str) and "==" in item for item in packages):
        fail("runner.packages must pin package versions")
    amitools_version = package_version(packages, "amitools[vamos]")
    machine68k_version = package_version(packages, "machine68k")
    runner_status = require_string(runner.get("status"), "runner.status")
    require_string(runner.get("limitation"), "runner.limitation")

    validation = data.get("validation")
    if not isinstance(validation, dict):
        fail("validation must be an object")
    executable = require_boolean(validation.get("freebasic_executable"),
                                 "validation.freebasic_executable")
    runtime_marker = require_boolean(validation.get("runtime_marker"),
                                     "validation.runtime_marker")
    process_exit = require_boolean(validation.get("process_exit"),
                                   "validation.process_exit")

    independent_runner = data.get("independent_runner")
    if process_exit:
        if not isinstance(independent_runner, dict):
            fail("process-exit validation requires independent_runner")
        if independent_runner.get("kind") != "emulator":
            fail("independent_runner.kind must be emulator")
        if independent_runner.get("name") != "FS-UAE":
            fail("independent_runner.name must be FS-UAE")
        require_string(independent_runner.get("version"),
                       "independent_runner.version")
        if independent_runner.get("status") != "passed":
            fail("independent_runner.status must be passed")
        require_string(independent_runner.get("input_policy"),
                       "independent_runner.input_policy")
        if independent_runner.get("test") != "test/amiga/run-fs-uae.sh":
            fail("independent_runner.test must name the FS-UAE harness")
    elif independent_runner is not None:
        fail("independent_runner requires process-exit validation")

    if target["support_level"] == "supported":
        if not (executable and runtime_marker and process_exit):
            fail("supported requires executable, runtime-marker and process-exit validation")
    elif runner_status == "passed" and not process_exit:
        fail("a passing runner must validate process termination")

    if arguments.github_env:
        arguments.github_env.open("a", encoding="utf-8").write(
            f"AMIGA_GCC_IMAGE={image}\n"
            f"AMITOOLS_VERSION={amitools_version}\n"
            f"MACHINE68K_VERSION={machine68k_version}\n")

    print("validated pinned AmigaOS/m68k toolchain input")


if __name__ == "__main__":
    main()
