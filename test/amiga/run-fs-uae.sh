#!/usr/bin/env bash
# Run the AmigaOS/m68k FreeBASIC smoke test in FS-UAE using legal local inputs.
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/../.." && pwd)"
INPUT="${1:-$SCRIPT_DIR/smoke.bas}"
FBC="${FBC:-$PROJECT_DIR/build/src/compiler/fbc}"
FS_UAE_BIN="${FS_UAE_BIN:-fs-uae}"
XDFTOOL="${XDFTOOL:-xdftool}"
RUN_SECONDS="${FS_UAE_RUN_SECONDS:-60}"
FS_UAE_VERSION="${FS_UAE_VERSION:-3.2.35}"

if [[ ! -x "$FBC" ]]; then
  echo "FBC must name an executable compiler (got: $FBC)" >&2
  exit 2
fi
if [[ ! -f "$INPUT" ]]; then
  echo "Input program does not exist: $INPUT" >&2
  exit 2
fi
if [[ -z "${FS_UAE_KICKSTART:-}" || ! -f "$FS_UAE_KICKSTART" ]]; then
  echo "FS_UAE_KICKSTART must name a local, lawful Kickstart ROM" >&2
  exit 2
fi
if [[ -z "${FS_UAE_SYSTEM_HDF:-}" || ! -f "$FS_UAE_SYSTEM_HDF" ]]; then
  echo "FS_UAE_SYSTEM_HDF must name a local, lawful bootable AmigaOS HDF" >&2
  exit 2
fi
if ! [[ "$RUN_SECONDS" =~ ^[1-9][0-9]*$ ]]; then
  echo "FS_UAE_RUN_SECONDS must be a positive integer (got: $RUN_SECONDS)" >&2
  exit 2
fi
for tool in "$FS_UAE_BIN" "$XDFTOOL" python3 shasum; do
  if ! command -v "$tool" >/dev/null 2>&1; then
    echo "Required tool is unavailable: $tool" >&2
    exit 2
  fi
done
actual_fs_uae_version="$("$FS_UAE_BIN" --version)"
if [[ "$actual_fs_uae_version" != "$FS_UAE_VERSION" ]]; then
  echo "FS-UAE version must be $FS_UAE_VERSION (got: $actual_fs_uae_version)" >&2
  exit 2
fi

WORK_DIR="${FS_UAE_WORK_DIR:-$(mktemp -d "${TMPDIR:-/tmp}/freebasic-ng-fsuae.XXXXXX")}"
remove_work_dir=0
if [[ -z "${FS_UAE_WORK_DIR:-}" ]]; then
  remove_work_dir=1
fi
emulator_pid=""

cleanup() {
  if [[ -n "$emulator_pid" ]] && kill -0 "$emulator_pid" 2>/dev/null; then
    kill -TERM "$emulator_pid" 2>/dev/null || true
    wait "$emulator_pid" 2>/dev/null || true
  fi
  if (( remove_work_dir )); then
    command rm -rf "$WORK_DIR"
  fi
}
trap cleanup EXIT

mkdir -p "$WORK_DIR/build"
printf '%s\n' "$actual_fs_uae_version" >"$WORK_DIR/fs-uae.version"
source_hash_before="$(shasum -a 256 "$FS_UAE_SYSTEM_HDF" | awk '{print $1}')"
clone_hdf="$WORK_DIR/system-copy.hdf"
command cp "$FS_UAE_SYSTEM_HDF" "$clone_hdf"

FBC="$FBC" \
FB_AMIGA_RUNTIME="${FB_AMIGA_RUNTIME:-}" \
AMIGA_GCC_SYSROOT="${AMIGA_GCC_SYSROOT:-}" \
AMIGA_CC="${AMIGA_CC:-m68k-amigaos-gcc}" \
AMIGA_TEST_RUNNER=/usr/bin/true \
FB_AMIGA_BUILD_DIR="$WORK_DIR/build" \
"$SCRIPT_DIR/build_and_test.sh" "$INPUT"

"$XDFTOOL" -r "$clone_hdf" read S/Startup-Sequence "$WORK_DIR/Startup-Sequence.original"
python3 "$PROJECT_DIR/scripts/prepare-fs-uae-inputs.py" \
  --startup-input "$WORK_DIR/Startup-Sequence.original" \
  --startup-output "$WORK_DIR/Startup-Sequence" \
  --config-output "$WORK_DIR/runner.fs-uae" \
  --kickstart "$FS_UAE_KICKSTART" \
  --system-hdf "$clone_hdf"

"$XDFTOOL" "$clone_hdf" \
  delete S/Startup-Sequence + write "$WORK_DIR/Startup-Sequence" S
"$XDFTOOL" "$clone_hdf" write "$SCRIPT_DIR/fs-uae-run-smoke" S
"$XDFTOOL" "$clone_hdf" write "$WORK_DIR/build/smoke" C

"$FS_UAE_BIN" "$WORK_DIR/runner.fs-uae" >"$WORK_DIR/fs-uae.log" 2>&1 &
emulator_pid=$!
sleep "$RUN_SECONDS"
if kill -0 "$emulator_pid" 2>/dev/null; then
  kill -TERM "$emulator_pid"
fi
wait "$emulator_pid" || true
emulator_pid=""

for result in m3-fsuae-boot-marker m3-fsuae-result m3-fsuae-output; do
  if ! "$XDFTOOL" -r "$clone_hdf" read "S/$result" "$WORK_DIR/$result"; then
    echo "FS-UAE did not write S/$result; inspect $WORK_DIR/fs-uae.log" >&2
    exit 1
  fi
done

grep -Fx 'M3-FS-UAE-STARTUP-REACHED' "$WORK_DIR/m3-fsuae-boot-marker"
grep -Fx 'M3-FS-UAE-PASS' "$WORK_DIR/m3-fsuae-result"
grep -Fx 'FreeBASIC-NG AmigaOS M3 smoke' "$WORK_DIR/m3-fsuae-output"

source_hash_after="$(shasum -a 256 "$FS_UAE_SYSTEM_HDF" | awk '{print $1}')"
if [[ "$source_hash_before" != "$source_hash_after" ]]; then
  echo "FS_UAE_SYSTEM_HDF changed during the test; refusing to report success" >&2
  exit 1
fi

echo "FS-UAE independently validated the AmigaOS/m68k smoke marker and process exit."
if (( ! remove_work_dir )); then
  echo "Evidence retained in: $WORK_DIR"
fi
