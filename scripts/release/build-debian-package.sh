#!/usr/bin/env bash
# Build a native Debian package from a CMake source tree.
#
# This runs inside a clean, native Debian container in CI.  The container owns
# the compiler and dpkg metadata tools; the source tree remains read-only.

set -euo pipefail

readonly PROGRAM='build-debian-package'

fail() {
  printf '%s: %s\n' "$PROGRAM" "$*" >&2
  exit 1
}

SOURCE_DIR=''
WORK_DIR=''
OUTPUT_DIR=''
VERSION=''
while (($#)); do
  case "$1" in
    --source-dir) SOURCE_DIR="${2-}"; shift 2 ;;
    --work-dir) WORK_DIR="${2-}"; shift 2 ;;
    --output-dir) OUTPUT_DIR="${2-}"; shift 2 ;;
    --version) VERSION="${2-}"; shift 2 ;;
    *) fail "unknown argument: $1" ;;
  esac
done

[[ -d "$SOURCE_DIR" && ! -L "$SOURCE_DIR" ]] || fail '--source-dir is not a safe directory'
[[ "$VERSION" =~ ^[0-9]+\.[0-9]+\.[0-9]+$ ]] ||
  fail '--version must be a three-component release version'
[[ -n "$WORK_DIR" && -n "$OUTPUT_DIR" ]] || fail '--work-dir and --output-dir are required'
[[ ! -e "$WORK_DIR" && ! -L "$WORK_DIR" ]] || fail '--work-dir must not exist yet'

for command in cmake ninja dpkg-deb dpkg-shlibdeps; do
  command -v "$command" >/dev/null || fail "required command is missing: $command"
done

architecture=$(dpkg --print-architecture)
case "$architecture" in amd64|arm64) ;; *) fail "unsupported Debian architecture: $architecture" ;; esac

mkdir -p "$WORK_DIR" "$OUTPUT_DIR"
build_dir="$WORK_DIR/build"
package_root="$WORK_DIR/package"
cmake -S "$SOURCE_DIR" -B "$build_dir" -G Ninja \
  -DCMAKE_BUILD_TYPE=Release -DFB_BUILD_GFXLIB=OFF
cmake --build "$build_dir"
DESTDIR="$package_root" cmake --install "$build_dir" --prefix /usr

[[ -x "$package_root/usr/bin/fbc" ]] || fail 'CMake installation contains no fbc'
# dpkg-shlibdeps derives substitution variables in the context of a Debian
# source package and deliberately refuses to run without debian/control.  The
# package is otherwise assembled directly from CMake, so provide only that
# minimal, private metadata input before deriving the binary's shared-library
# dependencies.
install -d "$WORK_DIR/debian"
cat > "$WORK_DIR/debian/control" <<'CONTROL'
Source: freebasic-ng
Section: devel
Priority: optional
Maintainer: metaneutrons <noreply@metaneutrons.cc>
Standards-Version: 4.6.2

Package: freebasic-ng
Architecture: any
Description: FreeBASIC-NG compiler
CONTROL
runtime_dependencies=$(
  cd "$WORK_DIR"
  dpkg-shlibdeps -O -e"package/usr/bin/fbc" | sed -n 's/^shlibs:Depends=//p'
)
[[ -n "$runtime_dependencies" ]] || fail 'dpkg-shlibdeps returned no runtime dependencies'

install -Dm644 "$SOURCE_DIR/LICENSE.md" \
  "$package_root/usr/share/doc/freebasic-ng/copyright"
install -Dm644 "$SOURCE_DIR/README.md" \
  "$package_root/usr/share/doc/freebasic-ng/README.md"
install -d "$package_root/DEBIAN"
cat > "$package_root/DEBIAN/control" <<CONTROL
Package: freebasic-ng
Version: ${VERSION}-1
Section: devel
Priority: optional
Architecture: ${architecture}
Maintainer: metaneutrons <https://github.com/metaneutrons>
Depends: gcc, binutils, libncurses-dev, ${runtime_dependencies}
Description: FreeBASIC-NG compiler
 FreeBASIC-NG is an independent, maintained FreeBASIC compiler fork.
CONTROL

package="$OUTPUT_DIR/freebasic-ng_${VERSION}-1_${architecture}.deb"
dpkg-deb --root-owner-group --build "$package_root" "$package" >/dev/null
dpkg-deb --info "$package" >/dev/null
printf '%s: wrote %s\n' "$PROGRAM" "$package"
