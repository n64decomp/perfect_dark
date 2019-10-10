# Perfect Dark Decompilation (WIP)

This repository contains a work-in-progress decompilation of Perfect Dark for the Nintendo 64.

## Roadmap

| Section         | Progress                                  |
| --------------- | ----------------------------------------- |
| 0x40 rspboot    | Won't disassemble as source is likely ASM |
| 0x1000 boot     | 5/34 functions done (14.71%)              |
| 0x3050 library  | 1/684 functions done (0.15%)              |
| 0x39850 setup   | About 50% identified                      |
| 0x4e850 rarezip | 2/8 functions done (25.00%)               |
| 0x5032e game    | 119/4102 functions done (2.90%)           |
| Lang files      | Done                                      |
| Setup files     | Done                                      |
| Prop files      | Not started                               |
| Character files | Not started                               |
| Gun files       | Not started                               |
| BG files        | Not started                               |
| Pad files       | Not started                               |
| Tile files      | Not started                               |

If you want to browse the stage setup files, use this table to find the filename:

| Stage            | File                                 |
| ---------------- | ------------------------------------ |
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

## Extracting the base ROM

Before you do anything you need an existing ROM to extract assets from.

1. Save your existing ROM file into the root of the repository with the name `pd.ntsc-final.z64`. It should not be byteswapped (the first four bytes should be `0x80371240`).
2. Run `make extract`. This will create an `extracted/ntsc-final` directory containing assets from your ROM.

## Compiling

The project can do the following:

* Build individual ucode binaries (boot, library, setup, rarezip and game) which match the ones extracted from the base ROM.
* Build a functioning ROM by splicing your stage setup and lang files into an existing ROM.

The project does NOT build a full ROM using the C code yet.

* Run `make` to build the individual ucode binaries. These files will be written to `build/ntsc-final`.
* Run `make rom` to build a ROM from the stage setup and lang files. The ROM will be written to `build/ntsc-final/pd.z64`.

## How do I know the built files are matching?

Run `make` followed by `make test`. If `make test` produces no output then everything is matching.
