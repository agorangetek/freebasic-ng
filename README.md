# FreeBASIC-NG

FreeBASIC-NG is an independently maintained fork of
[FreeBASIC](https://github.com/freebasic/fbc): a free, open-source,
multi-platform BASIC compiler with MS-QuickBASIC-compatible syntax.  The
compiler executable remains `fbc` for source compatibility.

The project is based on the upstream 1.20.0 development line.  Its exact
upstream base and the fork's compatibility policy are documented in
[UPSTREAM_BASE.md](UPSTREAM_BASE.md).

## Project identity

| Surface | Name |
| --- | --- |
| Project | FreeBASIC-NG |
| Compiler executable | `fbc` |
| GitHub repository | `metaneutrons/freebasic-ng` |
| Debian and Homebrew package | `freebasic-ng` |
| AUR source and binary packages | `freebasic-ng`, `freebasic-ng-bin` |

Release tags use `v<version>` and release assets use the
`freebasic-ng-<version>-<platform>` prefix.

## Local changes in this copy

This is a fork of FreeBASIC-NG with a **native Cocoa 2D graphics driver** for
macOS on top of it, so a plain `ScreenRes` opens a real window without XQuartz
and without OpenGL (deprecated on macOS):

| File | Change |
| --- | --- |
| `src/gfxlib2/darwin/gfx_driver_cocoa.m` | the driver: presents the software framebuffer in an `NSWindow` through CoreGraphics |
| `src/rtlib/darwin/fb_private_scancodes_cocoa.h` | keyboard scancodes for the driver |
| `src/gfxlib2/unix/gfx_unix.c` | registers the Cocoa driver after X11, so an XQuartz build keeps X11 and falls back to Cocoa |
| `src/compiler/fbc.bas` | links `-framework Cocoa -framework QuartzCore -framework CoreGraphics` for Darwin programs that use gfx |
| `src/gfxlib2/CMakeLists.txt` | compiles the Objective-C driver and enables the `OBJC` language on Darwin only |

The window, view and event handling is modelled on the Cocoa/OpenGL driver from
[freebasic/fbc#448](https://github.com/freebasic/fbc/pull/448) by Markos-Th09 –
including the scancode table; the software-framebuffer present path and the
driver hooks are new. The upstream work this follows is
[freebasic/fbc#479](https://github.com/freebasic/fbc/pull/479) and
[#480](https://github.com/freebasic/fbc/pull/480).

Verified on macOS arm64: a `ScreenRes 320,240,32` program draws a red box and a
green circle, and `BSave` returns those exact pixels (`line …, b` draws an
outline, so the interiors are black as expected).

## Build

Requirements:

- CMake 3.20 or newer
- a C compiler (GCC or Clang; MinGW-w64 on Windows)
- Python 3 and CA certificates when CMake materializes a bootstrap seed
- ncurses on Linux and macOS

```bash
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/src/compiler/fbc --version
```

Builds use a target-specific, provenance-verified compiler seed by default.
This keeps source builds independent of an arbitrary `fbc` found on `PATH`.
The verified binary is cached below the build directory after its first use.
Developers who specifically want a local compiler may opt in with
`-DFB_USE_SYSTEM_FBC=ON`. See [the bootstrap chain](docs/bootstrap.md)
for the pinned release provenance and offline reproduction procedure.

To stage an installation:

```bash
cmake --install build --prefix "$PWD/stage"
```

## Platform status

CI and stable releases cover Linux x86_64/aarch64, macOS x86_64/aarch64 and
Windows x86_64/aarch64 as Tier 1 native hosts.

AmigaOS, AROS and MorphOS are separate target-SDK work. They are not advertised
as native host releases until cross-compilation and runtime validation exist.

## Compatibility

FreeBASIC-NG aims for source compatibility with its upstream base. It does not
claim ABI compatibility with FreeBASIC distributions. Package managers must
treat it as an alternative compiler distribution, not as a drop-in provider for
an arbitrary `freebasic` dependency.

## Contributing and security

Read [CONTRIBUTING.md](CONTRIBUTING.md) before opening a pull request and
[SECURITY.md](SECURITY.md) for vulnerability reporting. The release and
repository roadmap is versioned in [docs/plans/m0.md](docs/plans/m0.md); the
current tidy-up decisions are in [docs/plans/m5.md](docs/plans/m5.md).

## License and attribution

FreeBASIC-NG preserves the original copyright notices and component licences.
The compiler is GPL-2.0-or-later; `libfb` and `libfbgfx` are
LGPL-2.1-or-later with the existing static-linking exception. See
[LICENSE.md](LICENSE.md) and the notices alongside the respective sources.
