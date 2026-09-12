#!/usr/bin/env bash
# Generate and link a FreeBASIC MorphOS/PowerPC smoke executable.
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/../.." && pwd)"
INPUT="${1:-$SCRIPT_DIR/smoke.bas}"
FBC="${FBC:-$PROJECT_DIR/build/src/compiler/fbc}"
MORPHOS_CC="${MORPHOS_CC:-ppc-morphos-gcc}"
MORPHOS_OBJDUMP="${MORPHOS_OBJDUMP:-ppc-morphos-objdump}"
MORPHOS_READELF="${MORPHOS_READELF:-ppc-morphos-readelf}"

if [[ ! -x "$FBC" ]]; then
  echo "FBC must name an executable compiler (got: $FBC)" >&2
  exit 2
fi
if [[ ! -f "$INPUT" ]]; then
  echo "Input program does not exist: $INPUT" >&2
  exit 2
fi
if [[ -z "${FB_MORPHOS_RUNTIME:-}" || ! -f "$FB_MORPHOS_RUNTIME" ]]; then
  echo "FB_MORPHOS_RUNTIME must name the CMake-built libfb.a" >&2
  exit 2
fi

WORK_DIR="${FB_MORPHOS_BUILD_DIR:-$(mktemp -d)}"
cleanup=0
if [[ -z "${FB_MORPHOS_BUILD_DIR:-}" ]]; then
  cleanup=1
fi
if (( cleanup )); then
  trap 'command rm -rf "$WORK_DIR"' EXIT
fi
mkdir -p "$WORK_DIR"

BASENAME="$(basename "$INPUT" .bas)"
command cp "$INPUT" "$WORK_DIR/$BASENAME.bas"

echo "=== FreeBASIC-NG -> MorphOS/PowerPC ==="
(
  cd "$WORK_DIR"
  "$FBC" -gen gcc -r -m "$BASENAME" -target morphos -arch powerpc "$BASENAME.bas"
)

"$MORPHOS_CC" -noixemul -mcpu=powerpc \
  -I"$PROJECT_DIR/src/rtlib" \
  "$WORK_DIR/$BASENAME.c" "$FB_MORPHOS_RUNTIME" \
  -lgcc -lc -lm -o "$WORK_DIR/$BASENAME"

echo "Built: $WORK_DIR/$BASENAME"
"$MORPHOS_OBJDUMP" -f "$WORK_DIR/$BASENAME" | tee "$WORK_DIR/$BASENAME.format"
grep -Fq "file format elf32-morphos" "$WORK_DIR/$BASENAME.format"
"$MORPHOS_READELF" -Ws "$WORK_DIR/$BASENAME" > "$WORK_DIR/$BASENAME.symbols"
grep -Eq '[[:space:]]__start$' "$WORK_DIR/$BASENAME.symbols"
grep -Eq '[[:space:]]main$' "$WORK_DIR/$BASENAME.symbols"
grep -Eq '[[:space:]]fb_Init$' "$WORK_DIR/$BASENAME.symbols"
