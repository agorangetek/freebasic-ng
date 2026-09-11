# Developer-preview platform contract

M1 releases native `fbc` host archives for the following Tier 1 platforms:

| Release ID | Native host | Bootstrap directory | CI runner |
| --- | --- | --- | --- |
| `linux-x86_64` | Linux x86_64 | `bootstrap/linux-x86_64` | `ubuntu-24.04` |
| `linux-aarch64` | Linux ARM64 | `bootstrap/linux-aarch64` | `ubuntu-24.04-arm` |
| `darwin-x86_64` | macOS Intel | `bootstrap/darwin-x86_64` | `macos-15-intel` |
| `darwin-aarch64` | macOS Apple silicon | `bootstrap/darwin-aarch64` | `macos-15` |
| `win64` | Windows x86_64 | `bootstrap/win64` | `windows-2025` with MSYS2 `MINGW64` |
| `win32-aarch64` | Windows ARM64 | `bootstrap/win32-aarch64` | `windows-11-arm` with MSYS2 `CLANGARM64` |

Each directory is an input to a reproducible C bootstrap, not an interchangeable
source cache. CMake verifies its file count and digest against
[`bootstrap/provenance.json`](../bootstrap/provenance.json) and fails if the
exact host bootstrap is absent or changed. `FB_USE_SYSTEM_FBC=ON` is the only
intentional opt-in to a locally installed compiler.

Every Tier 1 CI job builds the complete CMake tree, installs it into an empty
prefix, confirms the host identity, compiles a small FreeBASIC program with the
installed compiler, and executes that program on the same host. This is the
assurance level for a Developer Preview host archive. The archive uses the
normal `bin`, `include/freebasic` and `lib/freebasic/<host>` layout and requires
the platform C toolchain at use time; it does not bundle a C toolchain.

The AmigaOS, AROS and MorphOS targets remain separate target-generation work:
CI verifies `-gen gcc -r` output only. It does not claim native executable or
runtime validation on those operating systems. Package publication to APT,
Homebrew and the AUR is M2 work.
