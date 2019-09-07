# Perfect Dark Decompilation (WIP)

This repository contains a work-in-progress decompilation of Perfect Dark for the Nintendo 64. So far only the stage setup files are decompiled.

## I have no idea what you're talking about

Go have a look at the level scripts in the src/setup directory. Here's a mapping table for your convenience:

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
| Global Functions | [globals.c](src/globals.c)           |

There is also a stagetable.txt in the repository root which includes multiplayer stages.

## What can I do with this?

You can read and modify the level scripting easily, then recompile it into a playable ROM file. Assuming you have a ROM already of course (it's not included in the repo). The only supported version is the NTSC 8.7 final version. Other versions will be supported eventually.

You can use this to make mods without having to deal with the GE Setup Editor's interface. Or you can use it for practicing speedruns (eg. start a level at a particular location with particular objectives completed). Or you could make ROMs to help figure out how certain commands work.

## Okay, how? Show me how to make an edit

Install the following:

* make
* mips build tools (Debian/Ubuntu: binutils-mips-linux-gnu, Arch: mips64-elf-binutils from AUR)
* Python 3

Then:

1. Save your existing ROM file into the root of the repository with the name `pd.ntsc-final.z64`. It should not be byteswapped (the first four bytes should be `0x80371240`).
2. Edit a setup file. Open up `src/setup/setupame.c` (Defection), find the symbol `func0422_intro` and add `explosions_around_chr(CHR_JOANNA)` as the first statement.
3. Run `make rom`. This will create a ROM file at `build/ntsc-final/pd.z64`.
4. Play the ROM.
5. Start Defection, watch the intro and admire Joanna jumping from the dropship into a sea of explosions to her fiery death.

## Where's the list of commands? Is there a reference?

See `src/include/commands.h` and `src/include/constants.h` for a start.

## Whats with all this beginloop and endloop stuff?

All scripting is a series of labels and gotos. To give some structure to the code, I made a macro called `beginloop` that replaces a `label` + `yield`, and a macro called `endloop` that replaces a `goto_first` when used in this context. Most loops use the label and yield consecutively which allows this to work.

I don't think Rare had constructs like this though. There's a few rare places where yields are done at the end of the loop, and some where there's a dprint (comment) between the label and yield. In these cases my macros can't and aren't used.

I also added a `reloop` macro, which is selectively used to replace a `goto_first` within a loop. It's basically a `continue` statement for those familiar with programming.

## Can I edit global functions?

Well, yes but no. They won't be injected into the ROM because I'm lazy and haven't written code to do that. The stage files will though.

The global functions are at src/globals.c.

## How much stuff can I add before I run out of space?

Lots. If all the usual file space is exhaused, there's about 300KB of unused ROM space from other locations which will also be used. Considering each command averages only a couple of bytes, you're looking at about 10,000 to 100,000 commands you can add before you run out.

## How do I know the built files are matching?

1. With your ROM in place from earlier, run `make extract`. This will create an `extracted/ntsc-final` directory and populate it with the binaries from your ROM.
2. Without making any modifications to the setup files, run `make` to build them as usual. These will be compiled at `build/ntsc-final/files`.
3. Run `make test`. This will compare the setup binaries in `extracted` with the ones in `build`. If you get no output then they're matching. Try making a change to a file and repeat the `make` and `make test` steps again to see it identify the mismatching files.

## I want to see support for PAL, JAP and other versions

It's next on my to do list.

## Can you do the same for GoldenEye?

I might do, but my focus is on PD for now.
