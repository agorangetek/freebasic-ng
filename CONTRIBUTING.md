# Contributing to FreeBASIC-NG

## Scope

Use GitHub Issues for defects, proposals and release work. Check existing issues
before opening a new one. Changes to compiler behaviour require a focused test
or a documented reason why automated coverage is not feasible.

## Pull requests

- Base changes on `main`.
- Keep a pull request narrowly scoped and describe user-visible impact.
- Use Conventional Commit-style titles, for example `fix: correct arm64 link flags`.
- Do not include generated binaries, build directories or unrelated formatting.
- Preserve upstream copyright and licence notices.
- Run the relevant CMake build and `fbc --version` smoke test before requesting review.

## Compatibility and platforms

Do not present an experimental code-generation target as a supported native
host. Changes affecting a platform need an explicit host/target statement and
the corresponding CI coverage or a tracking issue for it.

## Release changes

Release metadata, package recipes and provenance files are security-sensitive.
They require review before merge and must not add unscoped publication tokens.
