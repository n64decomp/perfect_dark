# Perfect Dark Decompilation (WIP)

This repository contains a work-in-progress decompilation of Perfect Dark for the Nintendo 64.

## Status

See the [Perfect Dark Decompilation Status Page](https://ryandwyer.gitlab.io/pdstatus/).

## Installation Requirements

* make
* mips build tools (Debian/Ubuntu: binutils-mips-linux-gnu, Arch: mips64-elf-binutils from AUR)
* Python 3

## ROM Versions

Perfect Dark has six known versions:

| ROM ID     | Description                                                   |
|------------|---------------------------------------------------------------|
| ntsc-final | NTSC 8.7 final - fully supported                              |
| ntsc-1.0   | NTSC 8.7 final (the initial, buggy release) - fully supported |
| ntsc-beta  | NTSC 6.4 beta - can extract assets only                       |
| pal-final  | PAL 8.7 final - can extract assets only                       |
| pal-beta   | PAL 28.7 beta - can extract assets only                       |
| jap-final  | Japanese 8.7 final - can extract assets only                  |

Currently only the ntsc-final and ntsc-1.0 versions are fully supported. The NTSC beta, PAL and JAP versions can have their assets extracted from the base ROM but no effort has been made to build those versions back into a ROM.

The project uses the `$ROMID` environment variable to know which version to work with. If not set, it defaults to `ntsc-final`. You can change it by running something like `export ROMID=ntsc-1.0`.

## Extracting the base ROM

Before you do anything you need an existing ROM to extract assets from.

1. Save your existing ROM file into the root of the repository with the name `pd.ntsc-final.z64`. It should not be byteswapped (the first four bytes should be `0x80371240`).
2. Run `make extract`. This will create an `extracted/ntsc-final` directory containing assets from your ROM.

## Compiling

* Run `make` to build the assets that will be included in the ROM. These files will be written to `build/ntsc-final` and are matching what's in the `extracted/ntsc-final` folder.
* Run `make rom` to build the ROM. The ROM will be written to `build/ntsc-final/pd.z64`.

## How do I know the built files are matching?

Run `make` followed by `make test`. If `make test` produces no output then all compiled segments are matching.

You can also md5sum your base ROM with the built ROM and check they have the same hash: `md5sum pd.ntsc-final.z64 build/ntsc-final/pd.z64`.
