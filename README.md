# Perfect Dark - High Performance (PDHP)

A mod that optimises for runtime performance on console.

No accurate benchmarking has been done.

The mod is based off the framerate graph mod, so you can press L to toggle the frame rate graph.

## GCC build

The code is built with modern gcc and is optimised for code size. It reduces the game segment by around 360KB and the lib segment by around 72KB. This memory can then be used to do things which improve performance, and enables some of the improvements detailed below.

## Expansion pak required and virtual memory disabled

Retail PD uses virtual memory addresses (0x70000000 and 0x7f000000 ranges) which get mapped to physical ones (0x80000000 range) via the CPU's TLB. This incurs a minor overhead on every memory read and write. The game does this because it allowed it to implement memory paging when the expansion pak is not in use.

PDHP removes support for 4MB mode (ie. making the expansion pak required), then disables the virtual memory addressing and puts everything in physical memory. It also removes code and data that is specific to 4MB mode, such as menus, which saves some memory.

With the TLB no longer in use, the game segment doesn't need to be aligned to an 0x20000 boundary in physical memory any more. So PDHP puts it flush against other data, which means there is more continuous usable memory for other performance improvements.

## Crash and rmon threads disabled

The crash thread is used when the game crashes, and rmon is used for debugging with a host computer. They typically don't spend any CPU time at all, but disabling them means their stack allocations can be removed which frees up more memory for other performance improvements. This saves approximately 8KB.

## Unused VI modes removed

Nintendo's library contains several dozen video mode configurations, but only four of them are used by PD. PDHP deletes the configuration for the unused modes which saves approximately 4KB.

## Camdraw removed

Camdraw code contains mostly unused code. They are functions for editing Perfect Head photos. Removing them frees up more memory.

## Room preloading

The retail game loads room graphics data on the fly, based on rooms near the player and the direction they're looking. These rooms are then unloaded when not needed. When loading a room, the game uses a blocking DMA call which results in a lag frame (or a few if loading several rooms). There's extra processing associated with this as well, such as unzipping the graphics data and scanning the display lists.

For all stages except the Area 51 stages, PDHP loads all rooms during stage load and bypasses the "what rooms should I load" code. This gives a much more consistent frame rate. For the Area 51 stages, there is not enough memory to load all rooms at the same time (it would require around 1.5MB) so the original "load on the fly" method is used for those stages.

## Weapon preloading

In the retail game, when you change weapons it has to load the model and textures for the gun, hands and ammo casing. Each load is done using a blocking DMA call. They are split over several frames, so changing weapons results in a few laggy frames.

PDHP preloads all this data for the stage's natural weapons so they don't have to be loaded on the fly. Weapons that are given via cheats are not preloaded and will be loaded on the fly as usual. This means changing weapons is relatively quick and doesn't create any lag.

## Room visibility scripts replaced

Some stages have a bytecode script that overrides room visibility based on which rooms the player is in. The bytecode is interpreted by the C engine on every frame.

PDHP removes the scripting entirely and implements the custom visibility logic directly in C.

## AI: dprint command removed

All AI commands have a fixed-length, with the exception of the dprint command. The dprint command takes a variable-length string and prints it to the developer's console.

PDHP removes all uses of the command, which allows it to optimise the "how long is this command" function. In fact it's no longer a function at all, but a direct lookup into an array.

## AI: Pointers for AI offsets

Characters keep track of where they are in their AI processing by storing a pointer to their current AI "list", as well as an integer byte offset within that list. These have to be added together to read their current command, and then again for the next commnd and so on.

PDHP changes the aioffset value to be a pointer as well so it can be read directly, thus skipping the addition on each command invocation.

## AI: Preprocessing gotos and labels

In the retail game, AI command lists have a "label" command which is just a marker in the command list. Other commands can conditionally or unconditionally jump to a label. To implement this, the C engine has to iterate through the commands to find the label.

PDHP changes this so the goto statements specify a byte offset instead, and the labels are removed. When taking a branch, the C engine can now jump directly to the offset instead of searching for the label. This is achieved by preprocessing and rewriting each AI list during stage load.

## AI: Excessive reads and writes to g_Vars properties removed

In the retail game, the AI execution engine looks somewhat like this (simplified):

    while (g_Vars.ailist) {
    	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
    	s32 type = cmd[0] << 8 | cmd[1];

    	yielding = g_CommandHandlers[type]();

		if (yielding) {
		    break;
		}
    }

And a minimal handler looks like this:

    bool aiSomeHandler(void)
    {
        u8 *cmd = g_Vars.ailist + g_Vars.aioffset;

        // do something with cmd here

        g_Vars.aioffset += 2; // or more if command has parameters

        return false;
    }

PDHP does a few improvements in this area:

* The handlers now accept an argument which is a pointer to the command being processed.
* The handlers increment the given command pointer and return it without writing it back to g_Vars.
    * Unless the handler wants to yield, in which case it returns NULL.
* The loop code reuses the command pointer from the previous invocation.
* The loop code removes the unnecessary test on `g_Vars.ailist`.

The new loop runner code looks like this:

    u8 *cmd = g_Vars.aioffset;

    do {
        s32 type = (cmd[0] << 8) | cmd[1];
        cmd = g_CommandPointers[type](cmd);
    } while (cmd);

And a new handler looks like this:

    u8 *aiSomeHandler(u8 *cmd)
    {
        // do something with cmd here

        cmd += 2; // or more if command has parameters

        return cmd;
    }

## AI: Single byte command IDs

The AI loop typically has to load two bytes (two lbu instructions) from the command pointer and bitwise-or them together to get the command type/ID. It can't use a single load-half instruction because the data is not aligned.

PDHP improves this by issuing new IDs to all the commands. All commands have been categorised into into critical and non-critical commands based on the number of usages and whether they occur during main gameplay (as opposed to during cutscenes or level startup). PDHP makes it so critical commands can be identified by the first byte only, while non-critical commands will have 0xff as the first byte and then use the second byte to identify them. What this means is that the vast majority of commands that are run during gameplay are identified and executed using a single lbu instruction, which is almost as good as having single-byte command IDs.

Additionally, commands which are not used or are unreachable have been completely removed.

## AI: Inlined handlers

PDHP moves all AI command handler functions in the same file as the AI loop, adds the `static` keyword on all of the handler functions, and implements them as a switch rather than a lookup array. The compiler (gcc) inlines them into the main AI loop.

## AI: Timer comparisons changed to integers

Each character maintains a timer which can be used for AI purposes. The timer is stored as an integer, where each unit is one 60th of a second. When AI scripting wants to set or check the timer, it specifies an integer value in 60ths of a second as well.

In the retail game, the function for getting the character's timer and the function for comparing it both convert the times into seconds as floats before comparing the two floats.

PDHP removes the float conversion and compares them as integers.

## Pads stored in their full unpacked format

Pad data is zipped on the ROM, but then within the zipped data each pad can have a different size depending on which fields are customised. For example, the "up" coordinates can be omitted in the ROM data if the pad is upright, and a bitflag is set in the pad's flags to specify this. This pad data is unzipped and loaded into memory in the same format as used on the ROM.

When reading a pad's data, the game calls a function called `padUnpack` and passes it a pointer to a temporary pad struct. `padUnpack` reads the compact data, calculates any omitted properties and writes it back to the pad pointer that was passed to it. These are not preserved between frames, so this unpacking has to happen every time any pad is read.

PDHP puts the full pad data on the ROM, removes `padUnpack` and makes the callers point directly to the pad data. They no longer need to unpack or convert anything.

## Player count caching

The retail game uses a `PLAYERCOUNT()` macro which expands to:

    ((g_Vars.players[0] ? 1 : 0) + (g_Vars.players[1] ? 1 : 0) + (g_Vars.players[2] ? 1 : 0) + (g_Vars.players[3] ? 1 : 0))

This creates a great deal of memory reads, branching and register usage, especially when used in loop conditions. By creating a `playercount` property in the `g_Vars` struct, the excessive checking is reduced.

