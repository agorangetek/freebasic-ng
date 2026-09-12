# Changelog

## [1.22.2](https://github.com/metaneutrons/freebasic-ng/compare/v1.22.1...v1.22.2) (2026-09-12)


### Bug Fixes

* **release:** preserve Homebrew version during qualification ([#96](https://github.com/metaneutrons/freebasic-ng/issues/96)) ([26ab191](https://github.com/metaneutrons/freebasic-ng/commit/26ab19198eb2e74a5940430607b3a42329515270))

## [1.22.1](https://github.com/metaneutrons/freebasic-ng/compare/v1.22.0...v1.22.1) (2026-09-11)


### Bug Fixes

* **packaging:** satisfy Homebrew formula audit ([#94](https://github.com/metaneutrons/freebasic-ng/issues/94)) ([4874ea9](https://github.com/metaneutrons/freebasic-ng/commit/4874ea940dc9aae272694a7e00e531fa5bdc5cb0))

## [1.22.0](https://github.com/metaneutrons/freebasic-ng/compare/v1.21.4...v1.22.0) (2026-09-11)


### Features

* 68000 support - FreeBASIC runs on A500/A600/A1000! ([bd1ee0a](https://github.com/metaneutrons/freebasic-ng/commit/bd1ee0a9da045b1854b408c08e631117183fddce))
* add Amiga/AROS/MorphOS/AmigaOS4 target definitions ([a48a0cb](https://github.com/metaneutrons/freebasic-ng/commit/a48a0cb60789a09f35debd638fcc40a8e8431c58))
* add default libraries for Amiga targets ([e917dc4](https://github.com/metaneutrons/freebasic-ng/commit/e917dc48a632f8fbb0fb66117f52c8d633782017))
* add shell completion scripts ([5714d10](https://github.com/metaneutrons/freebasic-ng/commit/5714d10adb21ba0d5d65d7d497ac32f509bb95ff))
* add shell completion scripts ([7f08314](https://github.com/metaneutrons/freebasic-ng/commit/7f083147fa57db4feafc6c2ea9fdd9662997ea05))
* all AmigaOS libraries - 923 functions in 48 .bi files ([5ebd461](https://github.com/metaneutrons/freebasic-ng/commit/5ebd4612d39fb06ded9f9f5499bc6ebf46fc676e))
* AmigaOS graphics - Screen/Pset/Line via intuition+graphics.library ([6590b0a](https://github.com/metaneutrons/freebasic-ng/commit/6590b0a3cb5b6a40a46347b38ac2366398c51827))
* AmigaOS m68k rtlib port - Hello World works ([5be6cf2](https://github.com/metaneutrons/freebasic-ng/commit/5be6cf23bd2e595c3c2ecd74dd2f5d7dfd4902b1))
* complete Amiga build pipeline with vamos testing ([17b54d3](https://github.com/metaneutrons/freebasic-ng/commit/17b54d3f71d19d2bc1254d00b4815692a0d13d29))
* complete Amiga target support in compiler ([3b75ada](https://github.com/metaneutrons/freebasic-ng/commit/3b75ada542f8ffa6b7133ba9ed152c6ce5550770))
* File I/O and Input for AmigaOS ([f8026c5](https://github.com/metaneutrons/freebasic-ng/commit/f8026c522a7e62639a0f539b9bf73c4691253e33))
* Float support and improved Input for AmigaOS ([493063e](https://github.com/metaneutrons/freebasic-ng/commit/493063e6aa8f33358383492e0efc3293a7be1587))
* FreeBASIC headers for AmigaOS APIs (.bi files) ([bf4c6aa](https://github.com/metaneutrons/freebasic-ng/commit/bf4c6aab6280050d1d0f4be752b4f962d2209be6))
* FreeBASIC Print works on AmigaOS m68k! ([45d0917](https://github.com/metaneutrons/freebasic-ng/commit/45d09179d8eea605ad55bf24889ad04332aa0e6c))
* full FreeBASIC runtime for AmigaOS - loops, strings, math work! ([50aa5a0](https://github.com/metaneutrons/freebasic-ng/commit/50aa5a0d1216105a1696f681430f28b46a96d106))
* full libfb.a works on AmigaOS + Sleep/Timer ([9bb6929](https://github.com/metaneutrons/freebasic-ng/commit/9bb6929c60eaebca8e7beb79f4f144fff0efc255))
* **packaging:** generate distribution channel metadata ([#88](https://github.com/metaneutrons/freebasic-ng/issues/88)) ([528545d](https://github.com/metaneutrons/freebasic-ng/commit/528545d7876e12136028f50cc914359a297603cd))
* soft-float support for 68020 without FPU ([1b130fc](https://github.com/metaneutrons/freebasic-ng/commit/1b130fcda229ca21db45a0a4637c2880ddc59d7c))
* verify Tier 1 CMake host builds ([#74](https://github.com/metaneutrons/freebasic-ng/issues/74)) ([d9d75e3](https://github.com/metaneutrons/freebasic-ng/commit/d9d75e393f95c4c046cf6c5ce18ba3df45abe2e5)), closes [#60](https://github.com/metaneutrons/freebasic-ng/issues/60) [#61](https://github.com/metaneutrons/freebasic-ng/issues/61)


### Bug Fixes

* address all upstream PR [#472](https://github.com/metaneutrons/freebasic-ng/issues/472) review findings ([0b28031](https://github.com/metaneutrons/freebasic-ng/commit/0b2803195eda9fabdd50ca9206711d87023c6836))
* address upstream review findings for Amiga port ([0e1fd2f](https://github.com/metaneutrons/freebasic-ng/commit/0e1fd2f7c92699d2c85a1c769d9a4dd42ea4bafb))
* complete macOS arm64 support with old makefile ([a8af82c](https://github.com/metaneutrons/freebasic-ng/commit/a8af82c92f5d673c18a8e70b437e5835dcc2b1a6))
* libfb.a works cleanly without overrides! ([6eb67dc](https://github.com/metaneutrons/freebasic-ng/commit/6eb67dcefb4176eef6ad729ccd709a8437cee316))
* macOS arm64 support in makefile and linker driver ([19170da](https://github.com/metaneutrons/freebasic-ng/commit/19170daceff8a44d87913d3b24d218e0782c792b))
* **packaging:** disable LTO for AUR runtime ([#93](https://github.com/metaneutrons/freebasic-ng/issues/93)) ([adfa300](https://github.com/metaneutrons/freebasic-ng/commit/adfa3007ba73abbd378bb7c7f75f520a65b21195))
* **packaging:** install Debian linker development dependency ([#90](https://github.com/metaneutrons/freebasic-ng/issues/90)) ([2990bd1](https://github.com/metaneutrons/freebasic-ng/commit/2990bd1f39795f4eae1aa97ef09f8d368b273a9b))
* **packaging:** preserve AUR runtime static libraries ([#91](https://github.com/metaneutrons/freebasic-ng/issues/91)) ([6d1c1ac](https://github.com/metaneutrons/freebasic-ng/commit/6d1c1ac6cbe52c735ee59af1c8604916dd2c9036))
* **packaging:** retain AUR runtime static libraries ([#92](https://github.com/metaneutrons/freebasic-ng/issues/92)) ([f167965](https://github.com/metaneutrons/freebasic-ng/commit/f1679657cfd78a70bd90f98f1efb39a33380e42b))
* **release:** align compiler version with release metadata ([#86](https://github.com/metaneutrons/freebasic-ng/issues/86)) ([da8d4c2](https://github.com/metaneutrons/freebasic-ng/commit/da8d4c21f6fa78a4b15172af1b9c7df0143c74b7))
* **release:** annotate version metadata for release please ([#77](https://github.com/metaneutrons/freebasic-ng/issues/77)) ([b9b7420](https://github.com/metaneutrons/freebasic-ng/commit/b9b7420e00cce7f980f2b75dc2bd9039bf090581))
* **release:** create valid Windows ZIP archives ([#78](https://github.com/metaneutrons/freebasic-ng/issues/78)) ([3e72c5e](https://github.com/metaneutrons/freebasic-ng/commit/3e72c5e6f9a15ac97c8d4bcecae8a55ebac00794))
* **release:** exclude checksum inventory from itself ([#84](https://github.com/metaneutrons/freebasic-ng/issues/84)) ([2eb2d8f](https://github.com/metaneutrons/freebasic-ng/commit/2eb2d8f70d49cdb7462ebfa943a703004c58dd1b))
* **release:** extract Windows ZIP archives with zipfile ([#80](https://github.com/metaneutrons/freebasic-ng/issues/80)) ([acf4ede](https://github.com/metaneutrons/freebasic-ng/commit/acf4eded46d959424485e99419cedeb1564b3dd0))
* **release:** sign Windows ARM archive in candidate job ([#82](https://github.com/metaneutrons/freebasic-ng/issues/82)) ([113ad12](https://github.com/metaneutrons/freebasic-ng/commit/113ad1210267f21381c9ac8c863cca18e7441040))
* **release:** update compiler version in release PRs ([#76](https://github.com/metaneutrons/freebasic-ng/issues/76)) ([636661b](https://github.com/metaneutrons/freebasic-ng/commit/636661bf93ea26a94bba73fcf51700139110378e))
* skip signals and thread init on AmigaOS ([c0812ab](https://github.com/metaneutrons/freebasic-ng/commit/c0812abcea98949f2e2913057fc32e62bfba32c5))

## [1.21.4](https://github.com/metaneutrons/freebasic-ng/compare/freebasic-ng-v1.21.3...freebasic-ng-v1.21.4) (2026-09-11)


### Bug Fixes

* **release:** exclude checksum inventory from itself ([#84](https://github.com/metaneutrons/freebasic-ng/issues/84)) ([2eb2d8f](https://github.com/metaneutrons/freebasic-ng/commit/2eb2d8f70d49cdb7462ebfa943a703004c58dd1b))

## [1.21.3](https://github.com/metaneutrons/freebasic-ng/compare/freebasic-ng-v1.21.2...freebasic-ng-v1.21.3) (2026-09-11)


### Bug Fixes

* **release:** sign Windows ARM archive in candidate job ([#82](https://github.com/metaneutrons/freebasic-ng/issues/82)) ([113ad12](https://github.com/metaneutrons/freebasic-ng/commit/113ad1210267f21381c9ac8c863cca18e7441040))

## [1.21.2](https://github.com/metaneutrons/freebasic-ng/compare/freebasic-ng-v1.21.1...freebasic-ng-v1.21.2) (2026-09-11)


### Bug Fixes

* **release:** extract Windows ZIP archives with zipfile ([#80](https://github.com/metaneutrons/freebasic-ng/issues/80)) ([acf4ede](https://github.com/metaneutrons/freebasic-ng/commit/acf4eded46d959424485e99419cedeb1564b3dd0))

## [1.21.1](https://github.com/metaneutrons/freebasic-ng/compare/freebasic-ng-v1.21.0...freebasic-ng-v1.21.1) (2026-09-11)


### Bug Fixes

* **release:** create valid Windows ZIP archives ([#78](https://github.com/metaneutrons/freebasic-ng/issues/78)) ([3e72c5e](https://github.com/metaneutrons/freebasic-ng/commit/3e72c5e6f9a15ac97c8d4bcecae8a55ebac00794))

## [1.21.0](https://github.com/metaneutrons/freebasic-ng/compare/freebasic-ng-v1.20.0...freebasic-ng-v1.21.0) (2026-09-11)


### Features

* 68000 support - FreeBASIC runs on A500/A600/A1000! ([bd1ee0a](https://github.com/metaneutrons/freebasic-ng/commit/bd1ee0a9da045b1854b408c08e631117183fddce))
* add Amiga/AROS/MorphOS/AmigaOS4 target definitions ([a48a0cb](https://github.com/metaneutrons/freebasic-ng/commit/a48a0cb60789a09f35debd638fcc40a8e8431c58))
* add default libraries for Amiga targets ([e917dc4](https://github.com/metaneutrons/freebasic-ng/commit/e917dc48a632f8fbb0fb66117f52c8d633782017))
* add shell completion scripts ([5714d10](https://github.com/metaneutrons/freebasic-ng/commit/5714d10adb21ba0d5d65d7d497ac32f509bb95ff))
* add shell completion scripts ([7f08314](https://github.com/metaneutrons/freebasic-ng/commit/7f083147fa57db4feafc6c2ea9fdd9662997ea05))
* all AmigaOS libraries - 923 functions in 48 .bi files ([5ebd461](https://github.com/metaneutrons/freebasic-ng/commit/5ebd4612d39fb06ded9f9f5499bc6ebf46fc676e))
* AmigaOS graphics - Screen/Pset/Line via intuition+graphics.library ([6590b0a](https://github.com/metaneutrons/freebasic-ng/commit/6590b0a3cb5b6a40a46347b38ac2366398c51827))
* AmigaOS m68k rtlib port - Hello World works ([5be6cf2](https://github.com/metaneutrons/freebasic-ng/commit/5be6cf23bd2e595c3c2ecd74dd2f5d7dfd4902b1))
* complete Amiga build pipeline with vamos testing ([17b54d3](https://github.com/metaneutrons/freebasic-ng/commit/17b54d3f71d19d2bc1254d00b4815692a0d13d29))
* complete Amiga target support in compiler ([3b75ada](https://github.com/metaneutrons/freebasic-ng/commit/3b75ada542f8ffa6b7133ba9ed152c6ce5550770))
* File I/O and Input for AmigaOS ([f8026c5](https://github.com/metaneutrons/freebasic-ng/commit/f8026c522a7e62639a0f539b9bf73c4691253e33))
* Float support and improved Input for AmigaOS ([493063e](https://github.com/metaneutrons/freebasic-ng/commit/493063e6aa8f33358383492e0efc3293a7be1587))
* FreeBASIC headers for AmigaOS APIs (.bi files) ([bf4c6aa](https://github.com/metaneutrons/freebasic-ng/commit/bf4c6aab6280050d1d0f4be752b4f962d2209be6))
* FreeBASIC Print works on AmigaOS m68k! ([45d0917](https://github.com/metaneutrons/freebasic-ng/commit/45d09179d8eea605ad55bf24889ad04332aa0e6c))
* full FreeBASIC runtime for AmigaOS - loops, strings, math work! ([50aa5a0](https://github.com/metaneutrons/freebasic-ng/commit/50aa5a0d1216105a1696f681430f28b46a96d106))
* full libfb.a works on AmigaOS + Sleep/Timer ([9bb6929](https://github.com/metaneutrons/freebasic-ng/commit/9bb6929c60eaebca8e7beb79f4f144fff0efc255))
* soft-float support for 68020 without FPU ([1b130fc](https://github.com/metaneutrons/freebasic-ng/commit/1b130fcda229ca21db45a0a4637c2880ddc59d7c))
* verify Tier 1 CMake host builds ([#74](https://github.com/metaneutrons/freebasic-ng/issues/74)) ([d9d75e3](https://github.com/metaneutrons/freebasic-ng/commit/d9d75e393f95c4c046cf6c5ce18ba3df45abe2e5)), closes [#60](https://github.com/metaneutrons/freebasic-ng/issues/60) [#61](https://github.com/metaneutrons/freebasic-ng/issues/61)


### Bug Fixes

* address all upstream PR [#472](https://github.com/metaneutrons/freebasic-ng/issues/472) review findings ([0b28031](https://github.com/metaneutrons/freebasic-ng/commit/0b2803195eda9fabdd50ca9206711d87023c6836))
* address upstream review findings for Amiga port ([0e1fd2f](https://github.com/metaneutrons/freebasic-ng/commit/0e1fd2f7c92699d2c85a1c769d9a4dd42ea4bafb))
* complete macOS arm64 support with old makefile ([a8af82c](https://github.com/metaneutrons/freebasic-ng/commit/a8af82c92f5d673c18a8e70b437e5835dcc2b1a6))
* libfb.a works cleanly without overrides! ([6eb67dc](https://github.com/metaneutrons/freebasic-ng/commit/6eb67dcefb4176eef6ad729ccd709a8437cee316))
* macOS arm64 support in makefile and linker driver ([19170da](https://github.com/metaneutrons/freebasic-ng/commit/19170daceff8a44d87913d3b24d218e0782c792b))
* **release:** annotate version metadata for release please ([#77](https://github.com/metaneutrons/freebasic-ng/issues/77)) ([b9b7420](https://github.com/metaneutrons/freebasic-ng/commit/b9b7420e00cce7f980f2b75dc2bd9039bf090581))
* **release:** update compiler version in release PRs ([#76](https://github.com/metaneutrons/freebasic-ng/issues/76)) ([636661b](https://github.com/metaneutrons/freebasic-ng/commit/636661bf93ea26a94bba73fcf51700139110378e))
* skip signals and thread init on AmigaOS ([c0812ab](https://github.com/metaneutrons/freebasic-ng/commit/c0812abcea98949f2e2913057fc32e62bfba32c5))

## [1.10.2](https://github.com/metaneutrons/fbc/compare/1.10.1...v1.10.2) (2026-05-09)

### Features

* CMake build system with cross-platform bootstrap
* macOS Apple Silicon (arm64) support
* Automatic clang computed-goto compatibility
* GitHub Actions CI for Linux, macOS, Windows
* Pre-generated bootstrap C sources for linux-x86_64, linux-aarch64, win64
