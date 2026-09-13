# M1 and M2 release process

## Maintained distribution contract

FreeBASIC-NG publishes the six Tier 1 archives, signed source archive, native
Debian packages for `amd64` and `arm64`, a Homebrew formula, and the
`freebasic-ng` / `freebasic-ng-bin` AUR metadata. The central APT archive
ingests the attested Debian assets after GitHub Release promotion. RPM is not a
maintained distribution channel.

The historical local Debian and release assemblers were retired in M5. The
versioned GitHub Actions release workflow is the sole maintained release path;
its qualification and retention boundaries are recorded in
[the M5 plan](plans/m5.md).

The upstream release procedure, `todo.txt` and `changelog.txt` remain
available as historical records in [the history index](history/README.md).
They do not define this release process or the FreeBASIC-NG roadmap.

Release Please observes conventional commits on main, opens a version PR and,
when that PR is merged, creates a draft GitHub release and an immutable
v&lt;version&gt; tag. It authenticates through the existing
organisation-wide `metaneutrons-release-please` GitHub App; no personal token
is acceptable. Although that App has a shared parent key and broad
installation, this workflow requests and verifies an installation token scoped
to `metaneutrons/freebasic-ng` only.

The tag dispatches the release workflow. For each Tier 1 host it builds from
the checked-in, provenance-verified bootstrap C sources, stages a normal
installation and compiles and runs an independent FreeBASIC program from the
staged installation. It then repeats that smoke test after extracting the
archive.

The workflow publishes a GitHub prerelease only after all six archives are
present. Each archive has:

- an SPDX JSON SBOM;
- a Sigstore keyless signature bundle;
- a GitHub build-provenance attestation;
- a signed SHA256SUMS inventory covering the archives, SBOMs and bundles.

It downloads the assets from the draft release and verifies the checksum
inventory before the draft is made visible. M2 adds native Debian packages for
`amd64` and `arm64`, a signed source archive, and measured Homebrew plus AUR
source/binary metadata to that same candidate. Before visibility, clean
Bookworm, Homebrew on both macOS architectures, and Arch Linux x86_64/aarch64
qualification lanes install the generated packages and compile a program with
`fbc`. Qualification receives no channel credentials.

Merging the Release Please version PR is the explicit stable-release decision.
For a stable `v<version>` tag, the workflow first proves every channel's
credentials and destination scope without writing, then publishes the verified
candidate, publishes Homebrew and AUR metadata, promotes the GitHub release,
and finally dispatches the APT archive. A deliberately planned prerelease tag
such as `v<version>-m2.1` performs the complete build and package qualification
but remains a GitHub prerelease and cannot write to package channels.

## Required GitHub configuration

Use the existing `metaneutrons-release-please` App (client ID
`Iv23liGQAEDw6hfrazTD`). Store that ID as the `release` environment variable
`RELEASE_PLEASE_CLIENT_ID` and its existing private key as the `release`
environment secret `RELEASE_PLEASE_APP_PRIVATE_KEY`. The workflow must retain
its explicit `owner: metaneutrons`, `repositories: freebasic-ng` token request
and reject any token inventory other than this repository.

The release workflow itself uses GitHub Actions OIDC for Cosign; it does not
need a stored signing key. The repository must permit Actions to create
attestations and to write releases.
