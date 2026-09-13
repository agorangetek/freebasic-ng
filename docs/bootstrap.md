# Reproducible bootstrap chain

FreeBASIC-NG source checkouts do not retain generated compiler C trees. A
fresh checkout instead materializes one small, target-specific Stage-0 compiler
binary and uses it to generate the native compiler sources.

The tracked seed provenance manifest pins, for every Tier 1 host:

- the immutable release tag and producing workflow identity;
- the HTTPS release asset and its SHA-256;
- the one archive member containing fbc or fbc.exe, with its own SHA-256.

The fetcher rejects a wrong host, non-HTTPS origin, unsafe archive member,
unexpected transport digest or unexpected extracted-binary digest. It caches
the verified binary below the CMake build directory, so later builds can work
without a network connection. A local compiler is used only when
FB_USE_SYSTEM_FBC=ON was selected explicitly.

## Independent reproduction

The current manifest is rooted in the attested v1.22.3 assets. An independent
maintainer can materialize and inspect a seed before configuring CMake:

~~~bash
python3 scripts/fetch-bootstrap-seed.py \
  --target linux-aarch64 \
  --cache-dir build/bootstrap-seeds
shasum -a 256 build/bootstrap-seeds/linux-aarch64/fbc
cmake -S . -B build -G Ninja
cmake --build build
~~~

The printed checksum must equal the target seed_sha256 in the manifest. Use
GitHub attestation verification for the declared release asset before a seed
rotation:

~~~bash
gh attestation verify freebasic-ng_1.22.3-1_arm64.deb \
  --repo metaneutrons/freebasic-ng
~~~

Linux seeds intentionally come from the Bookworm-built Debian packages, not
from the Ubuntu host archives. The latter require a newer glibc than Bookworm.
The binary seed is only the compiler executable; the current checkout supplies
the compiler sources and include tree, and CMake rebuilds the resulting fbc.

## Seed rotation

A seed rotation is a dedicated change. It must use a fully qualified, attested
release asset for each Tier 1 host, record the release identity and both
digests in the manifest, and pass every native host build from an empty seed
cache. The release workflow's provenance attestations establish the release
side of that chain; the CMake build and host smoke tests establish that the
selected seed regenerates the current compiler.
