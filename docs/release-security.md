# Release credential boundaries

Publication credentials are configured only as GitHub Environment secrets. They
are never repository secrets, committed files or build artifacts. M0 creates the
environments; a channel is enabled only after its scoped credential preflight
passes.

| Environment | Purpose | Variables | Environment secret |
| --- | --- | --- | --- |
| `release` | Release Please | `RELEASE_PLEASE_CLIENT_ID` | `RELEASE_PLEASE_APP_PRIVATE_KEY` |
| `release-apt` | Dispatch attested `.deb` artifacts to the central archive | `ARCHIVE_DISPATCH_CLIENT_ID` | `ARCHIVE_DISPATCH_PRIVATE_KEY` |
| `release-homebrew` | Open and merge a formula update in the dedicated tap | `HOMEBREW_TAP_REPO`, `HOMEBREW_APP_CLIENT_ID` | `HOMEBREW_APP_PRIVATE_KEY` |
| `release-aur` | Publish the two AUR PKGBUILDs | `AUR_PACKAGE_NAME`, `AUR_SSH_KNOWN_HOSTS` | `AUR_SSH_PRIVATE_KEY` |

Each App installation is restricted to its one destination repository. The APT
dispatch identity may trigger an archive workflow but has neither archive signing
material nor object-storage access. The Homebrew identity may update only the
tap. AUR SSH authentication uses pinned host keys and strict host checking.

Every environment currently permits deployments only from `main`. A release
workflow must perform a read-only preflight before it can write to its channel.

M0 provides a manual Release Please workflow so that its App installation can
be qualified before it receives normal `main`-branch automation. M1 enables the
push trigger only after that qualification succeeds.
