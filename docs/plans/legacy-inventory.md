# Legacy-path inventory

This inventory prevents M5 from confusing old with unused. Its path catalogue
is supplemented by the normative [M5 plan](m5.md), which records the target
decisions, exact removal scope and acceptance evidence. A path may be removed
only in a dedicated pull request that records its replacement and runs the
stated verification.

| Path | Current role | Removal gate |
| --- | --- | --- |
| `bootstrap/` | Generated C sources needed to build `fbc` without a pre-existing compiler | Reproducible replacement bootstrap sources for every supported host, with provenance and bootstrap test |
| Root `makefile` | Builds targets not yet covered by CMake | CMake covers every retained target and the equivalent test suite passes |
| `contrib/deb/` | Retired in M5 | Replaced by the native, attested Debian and APT release path (M5-R1); its DEP-5 copyright record is preserved verbatim at `docs/history/debian-packaging-copyright` |
| `contrib/rpm/` | Retired in M5 | RPM support was explicitly dropped; no maintained RPM channel is promised (M5-R2) |
| `contrib/release/` | Retired in M5 | Replaced by attested GitHub release assembly (M5-R3) |
| `contrib/manifest/` | Legacy bindist manifests retained by the root `makefile` | The root make release/packaging path has a qualified CMake replacement |
| `contrib/nsis-installer/` and `contrib/unix-installer/` | Historic installers | New Windows/Linux installer or package path has successful install and upgrade tests |
| `todo.txt`, `changelog.txt` and historic documentation | Upstream project record | Material is either retained as history or migrated with stable links; never bulk-deleted |

No M0 change deletes a path in this table. Each removal must name the related
M5 issue and leave upstream licence and attribution notices intact. M5 records
which paths remain because their gates are not yet met; the table is an
inventory, not a second live acceptance checklist.
