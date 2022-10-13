# Perfect Dark Decompilation

This repository contains a complete decompilation of Perfect Dark for the Nintendo 64.

The project aims to be a matching decompilation. When a matching decompilation is compiled with the same compiler that the original developers used, the output will be exactly the same as the retail game, byte for byte.

To build the project, you must already have a Perfect Dark ROM. The project can build the exact same ROM from decomp's source code combined with assets that it extracts from your base ROM.

## Status

See the [Perfect Dark Decompilation Status Page](https://ryandwyer.gitlab.io/pdstatus/).

The ntsc-1.0 and ntsc-final versions are fully decompiled, but a small handful of functions are not yet byte-matching even though they are functionally the same. The status page doesn't show these as 100% because it counts matching functions only.

## Installation Requirements

For Arch Linux:

* Install these packages: `binutils fakeroot gcc make python vim`
* Install from AUR: `armips` and a mips binutils package of your choice (eg. `mips-elf-binutils`)

For Debian and Ubuntu:

* Install these packages: `binutils-mips-linux-gnu build-essential libc6-dev-i386 libcapstone3 libcapstone-dev make`
* Compile and install `armips`

## ROM Versions

Perfect Dark has six known versions:

| ROM ID     | Description                                 | MD5 Checksum                     |
|------------|---------------------------------------------|----------------------------------|
| ntsc-beta  | NTSC 6.4 beta                               | aa93f4df16fceada399a749f5ad2f273 |
| ntsc-1.0   | NTSC 8.7 final (the initial, buggy release) | 7f4171b0c8d17815be37913f535e4e93 |
| ntsc-final | NTSC 8.7 final                              | e03b088b6ac9e0080440efed07c1e40f |
| pal-beta   | PAL 28.7 beta                               | ad2de210a3455ba5ec541f0c78d91444 |
| pal-final  | PAL 8.7 final                               | d9b5cd305d228424891ce38e71bc9213 |
| jpn-final  | JPN 8.9 final                               | 538d2b75945eae069b29c46193e74790 |

The project uses the `$ROMID` environment variable to know which version to work with. If not set, it defaults to `ntsc-final`. You can change it by running something like `export ROMID=ntsc-1.0`.

## Extracting the base ROM

1. Save your existing ROM file into the root of the repository with the name `pd.ntsc-final.z64`. It should not be byteswapped (the first four bytes should be `0x80371240`).
2. Run `make extract`.

This will extract assets to `src/assets`. If any asset already exists then it will not be overwritten. This means you can modify assets as desired, and your changes will not be overwritten if you run the extract command again.

The extract command will also create an `extracted/ntsc-final` directory. This directory contains some compiled code segments from the ROM and is only used for comparison purposes.

## Compiling

* Run `git submodule update --init --recursive`. You only have to do this once.
* Run `make -j` to build the ROM. The ROM will be written to `build/ntsc-final/pd.z64`.

## How do I know the built files are matching?

Run `make` followed by `make test`. If `make test` produces no output then the compiled project is matching.

You can also md5sum your base ROM with the built ROM and check they have the same hash: `md5sum pd.ntsc-final.z64 build/ntsc-final/pd.z64`.
