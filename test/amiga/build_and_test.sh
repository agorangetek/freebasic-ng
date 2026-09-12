#!/usr/bin/env bash
# Build and execute a FreeBASIC AmigaOS/m68k smoke program.
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/../.." && pwd)"
INPUT="${1:-$SCRIPT_DIR/smoke.bas}"
FBC="${FBC:-$PROJECT_DIR/build/src/compiler/fbc}"
AMIGA_CC="${AMIGA_CC:-m68k-amigaos-gcc}"

if [[ ! -x "$FBC" ]]; then
  echo "FBC must name an executable compiler (got: $FBC)" >&2
  exit 2
fi
if [[ ! -f "$INPUT" ]]; then
  echo "Input program does not exist: $INPUT" >&2
  exit 2
fi
if [[ -z "${FB_AMIGA_RUNTIME:-}" || ! -f "$FB_AMIGA_RUNTIME" ]]; then
  echo "FB_AMIGA_RUNTIME must name the CMake-built libfb.a" >&2
  exit 2
fi

if [[ -z "${AMIGA_GCC_SYSROOT:-}" ]]; then
  AMIGA_GCC_SYSROOT="$(brew --prefix amiga-gcc)/m68k-amigaos"
fi
if [[ ! -d "$AMIGA_GCC_SYSROOT/lib" ]]; then
  echo "Amiga GCC sysroot has no lib directory: $AMIGA_GCC_SYSROOT" >&2
  exit 2
fi

WORK_DIR="${FB_AMIGA_BUILD_DIR:-$(mktemp -d)}"
mkdir -p "$WORK_DIR"
BASENAME="$(basename "$INPUT" .bas)"
command cp "$INPUT" "$WORK_DIR/$BASENAME.bas"

echo "=== FreeBASIC-NG -> AmigaOS/m68k ==="
(
  cd "$WORK_DIR"
  "$FBC" -gen gcc -r -m "$BASENAME" -target amiga -arch m68k "$BASENAME.bas"
)

"$AMIGA_CC" -m68020 -msoft-float \
  -B"$AMIGA_GCC_SYSROOT/lib" -L"$AMIGA_GCC_SYSROOT/lib" \
  -I"$PROJECT_DIR/src/rtlib" \
  "$WORK_DIR/$BASENAME.c" "$FB_AMIGA_RUNTIME" \
  -lamiga -lgcc -o "$WORK_DIR/$BASENAME"

echo "Built: $WORK_DIR/$BASENAME"
m68k-amigaos-objdump -f "$WORK_DIR/$BASENAME"

if [[ -n "${AMIGA_TEST_RUNNER:-}" ]]; then
  "$AMIGA_TEST_RUNNER" "$WORK_DIR/$BASENAME"
elif command -v vamos >/dev/null; then
  vamos -C 68020 "$WORK_DIR/$BASENAME"
else
  echo "No runtime runner configured; set AMIGA_TEST_RUNNER or install vamos." >&2
  exit 2
fi
