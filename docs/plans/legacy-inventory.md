# Legacy-path inventory

This inventory prevents M5 from confusing old with unused. A path may be
removed only in a dedicated pull request that records its replacement and runs
the stated verification.

| Path | Current role | Removal gate |
| --- | --- | --- |
| `bootstrap/` | Generated C sources needed to build `fbc` without a pre-existing compiler | Reproducible replacement bootstrap sources for every supported host, with provenance and bootstrap test |
| Root `makefile` | Builds targets not yet covered by CMake | CMake covers every retained target and the equivalent test suite passes |
| `contrib/travis/` | Historic CI helper scripts | GitHub Actions covers its still-supported host and test cases |
| `contrib/deb/` | Historic binary Debian package generator | `freebasic-ng` `.deb` is built, installed and archive-qualified through the central APT workflow |
| `contrib/rpm/` | Historic RPM specification and helper | Explicit decision to support RPM through a maintained replacement, or to drop RPM support |
| `contrib/release/` and `contrib/manifest/` | Historic release assembly and file manifests | Attested GitHub release artifacts cover the retained deliverables |
| `contrib/nsis-installer/` and `contrib/unix-installer/` | Historic installers | New Windows/Linux installer or package path has successful install and upgrade tests |
| `todo.txt`, `changelog.txt` and historic documentation | Upstream project record | Material is either retained as history or migrated with stable links; never bulk-deleted |

No M0 change deletes a path in this table. Each removal must name the related
M5 issue and leave upstream licence and attribution notices intact.
