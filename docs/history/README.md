# Historical records

This directory holds retained upstream records that explain past FreeBASIC
release and packaging decisions. They are not current FreeBASIC-NG operating
instructions.

- [`debian-packaging-copyright`](debian-packaging-copyright) is the DEP-5
  copyright and licence record that accompanied the retired `contrib/deb/`
  generator before M5. It is preserved verbatim for attribution and
  provenance; it is not a maintained Debian package definition.
- [`todo.txt`](../../todo.txt) and [`changelog.txt`](../../changelog.txt) stay
  at their upstream paths so existing source references remain stable. They
  record upstream work and releases, not the FreeBASIC-NG roadmap or release
  notes.
- [`DevMakingReleases.wakka`](../../doc/manual/cache/DevMakingReleases.wakka)
  is the cached upstream release procedure. Its in-page FreeBASIC-NG banner
  identifies the retired root GNU-make, bindist, manifest and installer paths;
  it remains in the manual cache because its Wakka cross-links are part of
  that record.

Use [the maintained release process](../releasing.md) for current releases.
The current licence boundaries are declared in [`LICENSE.md`](../../LICENSE.md).
