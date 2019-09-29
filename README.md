# Perfect Dark Decompilation (WIP)

This repository contains a work-in-progress decompilation of Perfect Dark for the Nintendo 64.

## Roadmap

| Section         | Progress                                  |
| --------------- | ----------------------------------------- |
| 0x40 rspboot    | Won't disassemble as source is likely ASM |
| 0x1000 boot     | Not started                               |
| 0x3050 library  | Not started                               |
| 0x39850 setup   | About 50% identified                      |
| 0x4e850 rarezip | 2/8 functions done                        |
| 0x5032e game    | Not started                               |
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
| Defection        | [setupame.c](src/setup/setupame.c)   |
| Investigation    | [setupear.c](src/setup/setupear.c)   |
| Extraction       | [setupark.c](src/setup/setupark.c)   |
| Villa            | [setupeld.c](src/setup/setupeld.c)   |
| Chicago          | [setuppete.c](src/setup/setuppete.c) |
| G5 Building      | [setupdepo.c](src/setup/setupdepo.c) |
| Infiltration     | [setuplue.c](src/setup/setuplue.c)   |
| Rescue           | [setuplip.c](src/setup/setuplip.c)   |
| Escape           | [setuptra.c](src/setup/setuptra.c)   |
| Air Base         | [setupcave.c](src/setup/setupcave.c) |
| Air Force One    | [setuprit.c](src/setup/setuprit.c)   |
| Crash Site       | [setupazt.c](src/setup/setupazt.c)   |
| Pelagic II       | [setupdam.c](src/setup/setupdam.c)   |
| Deep Sea         | [setuppam.c](src/setup/setuppam.c)   |
| Defense          | [setupimp.c](src/setup/setupimp.c)   |
| Attack Ship      | [setuplee.c](src/setup/setuplee.c)   |
| Skedar Ruins     | [setupsho.c](src/setup/setupsho.c)   |
| MBR              | [setupwax.c](src/setup/setupwax.c)   |
| Maian SOS        | [setupsev.c](src/setup/setupsev.c)   |
| WAR!             | [setupstat.c](src/setup/setupstat.c) |
| The Duel         | [setupate.c](src/setup/setupate.c)   |
| CI Training      | [setupdish.c](src/setup/setupdish.c) |
| Common Functions | [setup.c](src/setup.c)               |

There is also a stagetable.txt in the repository root which includes multiplayer stages.

## Compiling

Install the following:

* make
* mips build tools (Debian/Ubuntu: binutils-mips-linux-gnu, Arch: mips64-elf-binutils from AUR)
* Python 3

Then:

1. Save your existing ROM file into the root of the repository with the name `pd.ntsc-final.z64`. It should not be byteswapped (the first four bytes should be `0x80371240`).
2. Run `make extract`. This will create an `extracted/ntsc-final` containing assets from your ROM.
3. Make edits to the C files in the `src` directory if desired.
3. Run `make rom`. This will create a ROM file at `build/ntsc-final/pd.z64`.

## How do I know the built files are matching?

Run `make` followed by `make test`. If `make test` produces no output then everything is matching.
