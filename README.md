# Perfect Dark Decompilation (WIP)

This repository contains a work-in-progress decompilation of Perfect Dark for the Nintendo 64.

## Roadmap

Actual decompilation:

| Segment         | Progress                                   |
|-----------------|--------------------------------------------|
| 0x1000 boot     | 206/2,068 words decompiled (9.96%)         |
| 0x3050 library  | 8,115/89,060 words decompiled (9.11%)      |
| 0x39850 setup   | 36,494/50,064 words decompiled (72.89%)    |
| 0x4e850 inflate | 150/1,276 words decompiled (11.76%)        |
| 0x4fc40 game    | 46,256/452,216 words decompiled (10.23%)   |
|-----------------+--------------------------------------------|
| Total           | 91,221/594,684 words decompiled (15.34%)   |

Assets:

| Asset Type      | Progress                                  |
|-----------------|-------------------------------------------|
| Lang files      | Done                                      |
| Setup files     | Done                                      |
| Prop files      | To do                                     |
| Character files | To do                                     |
| Gun files       | To do                                     |
| BG files        | To do                                     |
| Pad files       | To do                                     |
| Tile files      | Done                                      |
| MIDI files      | Extracted as binaries                     |
| Animation files | To do                                     |
| Textures        | To do                                     |

If you want to browse the stage setup files, use this table to find the filename:

| Stage            | File                                       |
|------------------|--------------------------------------------|
| Defection        | [setupame.c](src/files/setup/setupame.c)   |
| Investigation    | [setupear.c](src/files/setup/setupear.c)   |
| Extraction       | [setupark.c](src/files/setup/setupark.c)   |
| Villa            | [setupeld.c](src/files/setup/setupeld.c)   |
| Chicago          | [setuppete.c](src/files/setup/setuppete.c) |
| G5 Building      | [setupdepo.c](src/files/setup/setupdepo.c) |
| Infiltration     | [setuplue.c](src/files/setup/setuplue.c)   |
| Rescue           | [setuplip.c](src/files/setup/setuplip.c)   |
| Escape           | [setuptra.c](src/files/setup/setuptra.c)   |
| Air Base         | [setupcave.c](src/files/setup/setupcave.c) |
| Air Force One    | [setuprit.c](src/files/setup/setuprit.c)   |
| Crash Site       | [setupazt.c](src/files/setup/setupazt.c)   |
| Pelagic II       | [setupdam.c](src/files/setup/setupdam.c)   |
| Deep Sea         | [setuppam.c](src/files/setup/setuppam.c)   |
| Defense          | [setupimp.c](src/files/setup/setupimp.c)   |
| Attack Ship      | [setuplee.c](src/files/setup/setuplee.c)   |
| Skedar Ruins     | [setupsho.c](src/files/setup/setupsho.c)   |
| MBR              | [setupwax.c](src/files/setup/setupwax.c)   |
| Maian SOS        | [setupsev.c](src/files/setup/setupsev.c)   |
| WAR!             | [setupstat.c](src/files/setup/setupstat.c) |
| The Duel         | [setupate.c](src/files/setup/setupate.c)   |
| CI Training      | [setupdish.c](src/files/setup/setupdish.c) |

There is also a stagetable.txt in the repository root which includes multiplayer stages.

## Installation Requirements

* make
* mips build tools (Debian/Ubuntu: binutils-mips-linux-gnu, Arch: mips64-elf-binutils from AUR)
* Python 3
* pigz - a zlib compression tool

## Extracting the base ROM

Before you do anything you need an existing ROM to extract assets from.

1. Save your existing ROM file into the root of the repository with the name `pd.ntsc-final.z64`. It should not be byteswapped (the first four bytes should be `0x80371240`).
2. Run `make extract`. This will create an `extracted/ntsc-final` directory containing assets from your ROM.

## Compiling

The project can do the following:

* Build individual ucode binaries (boot, library, setup, inflate and game) which match the ones extracted from the base ROM.
* Build a functioning ROM by splicing the C source and assets into an existing ROM. The built ROM is not byte perfect yet, but is is functionally equivalent.

* Run `make` to build the assets that will be included in the ROM. These files will be written to `build/ntsc-final` and are matching what's in the `extracted/ntsc-final` folder.
* Run `make rom` to build the ROM. The ROM will be written to `build/ntsc-final/pd.z64`.

## How do I know the built files are matching?

Run `make` followed by `make test`. If `make test` produces no output then everything is matching.
