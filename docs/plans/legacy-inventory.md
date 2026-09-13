# Legacy-path inventory

This inventory prevents M5 from confusing old with unused. Its path catalogue
is supplemented by the normative [M5 plan](m5.md), which records the target
decisions, exact removal scope and acceptance evidence. A path may be removed
only in a dedicated pull request that records its replacement and runs the
stated verification.

| Path | Current role | Removal gate |
| --- | --- | --- |
| `bootstrap/<host>/*.c` | Retired in M7 | Replaced by the manifest-pinned, attested minimal Stage-0 seed chain; the retained `bootstrap/seed-provenance.json` records every host input |
| Root `makefile` | Retired in M7 | The v1.24.4 CMake release and package qualification satisfied the gate recorded in [#141](https://github.com/metaneutrons/freebasic-ng/issues/141); local test makefiles remain CTest fixtures, not a root build entrypoint |
| `contrib/deb/` | Retired in M5 | Replaced by the native, attested Debian and APT release path (M5-R1); its DEP-5 copyright record is preserved verbatim at `docs/history/debian-packaging-copyright` |
| `contrib/rpm/` | Retired in M5 | RPM support was explicitly dropped; no maintained RPM channel is promised (M5-R2) |
| `contrib/release/` | Retired in M5 | Replaced by attested GitHub release assembly (M5-R3) |
| `contrib/manifest/` | Retired in M7 | The v1.24.4 qualified CMake archive and package path replaces legacy bindist manifests under [#141](https://github.com/metaneutrons/freebasic-ng/issues/141) |
| `contrib/nsis-installer/` and `contrib/unix-installer/` | Retired in M7 | The v1.24.4 release qualification covers Windows/Linux archives and Debian package upgrade installation; they are removed under [#141](https://github.com/metaneutrons/freebasic-ng/issues/141) |
| `todo.txt`, `changelog.txt` and historic documentation | Upstream project record | Material is either retained as history or migrated with stable links; never bulk-deleted |

No M0 change deletes a path in this table. Each removal must name the related
M5 issue and leave upstream licence and attribution notices intact. M5 records
which paths remain because their gates are not yet met; the table is an
inventory, not a second live acceptance checklist.
