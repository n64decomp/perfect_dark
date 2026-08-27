# Building a matching ROM in Docker

The upstream README's Debian/Ubuntu instructions do not pin a binutils version.
On a current Ubuntu they produce a ROM that builds cleanly, boots, and **does not
match** — so this fork carries a pinned container instead.

Verified 2026-08-27 on an Apple Silicon Mac (arm64 host, amd64 container):
`make test` silent, and the built ROM byte-identical to a retail
`Perfect Dark (USA) (Rev 1)` dump.

## Build

Put your base ROM in the repository root as `pd.ntsc-final.z64` (not
byteswapped — the first four bytes must be `80 37 12 40`), then:

```
git submodule update --init --recursive
ROMID=ntsc-final python3 tools/extract
docker compose build
docker compose run --rm pd make -j"$(nproc)"
docker compose run --rm pd make test
```

`make test` printing nothing means the build matches. The ROM is written to
`build/ntsc-final/pd.z64`.

`tools/extract` is pure Python — only `os` and `zlib` — so it runs fine on the
host and needs no container. It takes about a second and writes ~6,200 files
into `src/assets/ntsc-final`, all of them gitignored.

For `ntsc-final` the base ROM's md5 is `e03b088b6ac9e0080440efed07c1e40f`. The
other five supported versions are listed in the README.

## Why the base image is pinned to Ubuntu 20.04

**Because of binutils, and nothing else.**

| | GNU ld 2.34 (20.04) | GNU ld 2.38 (22.04) |
|---|---|---|
| `make test` | silent — matching | 811 of 1553 checksums fail |
| ROM vs retail | byte-identical | 42% of bytes differ |
| `game` / `data` / `lib` vs retail | 0 / 0 / 0 bytes | 10 / 3843 / 8 bytes |

The 2.38 failure is worth describing, because it presents as catastrophic and
is not:

1. `ld` 2.38 lays the lib segment out **3600 (`0xE10`) bytes** differently under
   `BEGIN_SEG(lib) SUBALIGN(0x10)` in [`ld/pd.ld`](../ld/pd.ld).
2. That changes link-time constants baked into `lib` and `game` as `addiu`
   immediates — 18 bytes in total, each off by exactly `0xE10`:

   ```
   lib.bin 0xC710:  retail 2465f550   built 2465e740
   lib.bin 0xC714:  retail 256bfe00   built 256beff0
   ```

3. `lib` is compressed into the ROM from offset `0x3050`, so those bytes change
   the deflate stream from `0x8F7C` onward **and its length**.
4. Every asset after it shifts, with the drift accumulating by position.
5. The file-offset table in `data.bin` is generated from the real offsets, so
   its 1,951 differing words each pick up their own accumulated delta. That is
   the 3,843-byte `data.bin` "difference" — an effect, not a cause.

Everything else is correct throughout. Each of a random sample of twelve
"failing" compressed assets was found **byte-identical inside the retail ROM**,
merely at a different offset. The compression is right, the assets are right,
and the decompiled code is right.

Things this is *not*, each checked directly:

* **Not a regression.** Checking out `a3d56e74e` — the 2022 commit that last
  wrote `checksums.ntsc-final.md5` — and building it under 2.38 fails
  identically, at the same 811.
* **Not the vendored gzip.** `tools/rarezip` shells out to `tools/gzip`, a
  vendored gzip 1.2.4 (1993) that links only libc and is deterministic across
  runs. Its output for a given input appears verbatim in the retail ROM.
* **Not a stale checksums file.** It has been correct since 2022. Modern Ubuntu
  simply stopped being able to satisfy it.

## Two traps when changing the container

Both cost a failed build:

* **`xxd` is not installed by default on 20.04** and is not named in the
  README, but `tools/rarezip` pipes through it. Its absence kills the build
  partway through the assets.
* **`make clean` removes neither `build/recomp/` nor `tools/mkrom/mkrom`.**
  Switching base images without deleting those by hand gives
  `version 'GLIBC_2.34' not found` from binaries the *other* image built. Use
  `rm -rf build tools/mkrom/mkrom` when changing toolchains.
