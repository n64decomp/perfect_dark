# Perfect Dark Setup Decompilation

This repository contains a decompilation of the level setup files used in Perfect Dark for the Nintendo 64.

## Come again?

It's known that Perfect Dark (and GoldenEye) use a custom made binary scripting language to set up the levels. See the GE/PD Function Explorer and the GoldenEye Setup Editor. However, the specifics of how it works has been difficult to explore. Until now.

I've realised that Rare likely did their level setup and scripting with assembly macros. The giveaway was the U prefix on the setup filename, which is also a common prefix for compiled machine code (ucode). So I made a tool that would read the binaries and generate some assembly files which can be compiled back into those exact same binaries. Once I got it matching, I started annotating each setup file, discovering new commands and renaming symbols.

## I still have no idea what you're talking about

Go have a look at the level scripts in the asm/setup directory. Here's a mapping table for your convenience:

| Stage            | File                                 |
| ---------------- | ------------------------------------ |
| Defection        | [setupame.s](asm/setup/setupame.s)   |
| Investigation    | [setupear.s](asm/setup/setupear.s)   |
| Extraction       | [setupark.s](asm/setup/setupark.s)   |
| Villa            | [setupeld.s](asm/setup/setupeld.s)   |
| Chicago          | [setuppete.s](asm/setup/setuppete.s) |
| G5 Building      | [setupdepo.s](asm/setup/setupdepo.s) |
| Infiltration     | [setuplue.s](asm/setup/setuplue.s)   |
| Rescue           | [setuplip.s](asm/setup/setuplip.s)   |
| Escape           | [setuptra.s](asm/setup/setuptra.s)   |
| Air Base         | [setupcave.s](asm/setup/setupcave.s) |
| Air Force One    | [setuprit.s](asm/setup/setuprit.s)   |
| Crash Site       | [setupazt.s](asm/setup/setupazt.s)   |
| Pelagic II       | [setupdam.s](asm/setup/setupdam.s)   |
| Deep Sea         | [setuppam.s](asm/setup/setuppam.s)   |
| Defense          | [setupimp.s](asm/setup/setupimp.s)   |
| Attack Ship      | [setuplee.s](asm/setup/setuplee.s)   |
| Skedar Ruins     | [setupsho.s](asm/setup/setupsho.s)   |
| MBR              | [setupwax.s](asm/setup/setupwax.s)   |
| Maian SOS        | [setupsev.s](asm/setup/setupsev.s)   |
| WAR!             | [setupstat.s](asm/setup/setupstat.s) |
| The Duel         | [setupate.s](asm/setup/setupate.s)   |
| CI Training      | [setupdish.s](asm/setup/setupdish.s) |
| Global Functions | [globals.s](asm/globals.s)           |

There is also a stagetable.txt in the repository root which includes multiplayer stages.

## What can I do with this?

You can read and modify the level scripting easily, then recompile it into a playable ROM file. Assuming you have a ROM already of course (it's not included in the repo). The only supported version is the NTSC 8.7 final version. Other versions will be supported eventually.

You can use this to make mods without having to deal with the GE Setup Editor's interface. Or you can use it for practicing speedruns (eg. start a level at a particular location with particular objectives completed). Or you could make ROMs to help figure out how certain commands work.

## Okay, how? Show me how to make an edit

Install the following:

* make
* aarch64 build tools (aarch64-linux-gnu-as, aarch64-linux-gnu-ld, aarch64-linux-gnu-objcopy)
* Python 3

Then:

1. Save your existing ROM file into the root of the repository with the name `pd.ntsc-final.z64`. It should not be byteswapped (the first four bytes should be `0x80371240`).
2. Edit a setup file. Open up `asm/setup/setupame.s` (Defection), find the function `func0422_intro` and add `explosions_around_chr CHR_JOANNA` as the first statement.
3. Run `make rom`. This will create a ROM file at `build/ntsc-final/pd.z64`.
4. Play the ROM.
5. Start Defection, watch the intro and admire Joanna jumping from the dropship into a sea of explosions to her fiery death.

## Wait, aarch64? Isn't that ARM?

Yeah. I originally used mips64, but the binaries it created were padded and therefore incorrect. I couldn't figure out how to change that with modern versions of the mips build tools and I didn't want to waste too much time on that aspect of it. Because there's no actual opcodes being generated, the architecture isn't really important. I just needed something that worked and was big endian (so x64_64 was out of the question too).

## Where's the list of commands? Is there a reference?

See `asm/include/commands.inc` and `asm/include/constants.inc` for a start.

## Whats with all this beginloop and endloop stuff?

All scripting is a series of labels and gotos. To give some structure to the code, I made a macro called `beginloop` that replaces a `label` + `yield`, and a macro called `endloop` that replaces a `goto_first` when used in this context. Most loops use the label and yield consecutively which allows this to work.

I don't think Rare had constructs like this though. There's a few rare places where yields are done at the end of the loop, and some where there's a dprint (comment) between the label and yield. In these cases my macros can't and aren't used.

I also added a `reloop` macro, which is selectively used to replace a `goto_first` within a loop. It's basically a `continue` statement for those familiar with programming.

## Can I edit global functions?

Well, yes but no. They won't be injected into the ROM because I'm lazy and haven't written code to do that. The stage files will though.

The global functions are at asm/globals.s.

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
