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

## Build

Requirements:

- CMake 3.20 or newer
- a C compiler (GCC or Clang; MinGW-w64 on Windows)
- Python 3 when building bootstrap sources with Clang
- ncurses on Linux and macOS

```bash
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/src/compiler/fbc --version
```

Builds use the versioned generated C bootstrap sources by default. This keeps
source builds independent of an arbitrary `fbc` found on `PATH`. Developers who
specifically want a native bootstrap may opt in with
`-DFB_USE_SYSTEM_FBC=ON`.

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
