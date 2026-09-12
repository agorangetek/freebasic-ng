#!/usr/bin/env python3
"""Prepare disposable FS-UAE inputs for the AmigaOS/m68k runtime test."""

from argparse import ArgumentParser
from pathlib import Path


BOOT_MARKER = "M3-FS-UAE-STARTUP-REACHED"
RUN_SCRIPT = "fs-uae-run-smoke"


def prepare_startup(source: Path, destination: Path) -> None:
    text = source.read_text(encoding="latin-1")
    if BOOT_MARKER in text or RUN_SCRIPT in text:
        raise SystemExit("startup input already contains FreeBASIC-NG FS-UAE hooks")

    lines = text.splitlines(keepends=True)
    insertion = 0
    while insertion < len(lines):
        stripped = lines[insertion].strip()
        if stripped and not stripped.startswith(";"):
            break
        insertion += 1

    hooks = [
        f'C:Echo "{BOOT_MARKER}" >S:m3-fsuae-boot-marker\n',
        f"C:Execute S:{RUN_SCRIPT}\n",
        "\n",
    ]
    destination.write_text("".join(lines[:insertion] + hooks + lines[insertion:]),
                           encoding="latin-1")


def prepare_config(destination: Path, kickstart: Path, system_hdf: Path) -> None:
    for label, path in (("kickstart", kickstart), ("system HDF", system_hdf)):
        if "\n" in str(path) or "\r" in str(path):
            raise SystemExit(f"{label} path must not contain a line break")

    destination.write_text(
        "[fs-uae]\n"
        "amiga_model = A1200/020\n"
        "chip_memory = 2048\n"
        "cpu = 68EC030\n"
        "fast_memory = 8192\n"
        "zorro_iii_memory = 32768\n"
        "graphics_card = uaegfx-z3\n"
        "graphics_memory = 32768\n"
        "jit_compiler = 1\n"
        "warp_mode = 1\n"
        "sound_output = none\n"
        "floppy_drive_count = 0\n"
        f"kickstart_file = {kickstart}\n"
        f"hard_drive_0 = {system_hdf}\n"
        "hard_drive_0_label = DH0\n"
        "hard_drive_0_read_only = 0\n",
        encoding="utf-8",
    )


def main() -> None:
    parser = ArgumentParser()
    parser.add_argument("--startup-input", type=Path, required=True)
    parser.add_argument("--startup-output", type=Path, required=True)
    parser.add_argument("--config-output", type=Path, required=True)
    parser.add_argument("--kickstart", type=Path, required=True)
    parser.add_argument("--system-hdf", type=Path, required=True)
    arguments = parser.parse_args()

    for label, path in (("startup input", arguments.startup_input),
                        ("kickstart", arguments.kickstart),
                        ("system HDF", arguments.system_hdf)):
        if not path.is_file():
            raise SystemExit(f"{label} does not exist: {path}")

    prepare_startup(arguments.startup_input, arguments.startup_output)
    prepare_config(arguments.config_output, arguments.kickstart.resolve(),
                   arguments.system_hdf.resolve())


if __name__ == "__main__":
    main()
