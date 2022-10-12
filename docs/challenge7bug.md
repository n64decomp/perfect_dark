# The Challenge 7 Bug

Perfect Dark's initial release didn't exactly go smoothly. It had a game breaking memory corruption bug that required a new version to be produced the following day. Attempting to complete Challenge 7 with 3 players would prove impossible because the game would crash during gameplay.

Thanks to the decompilation project we can easily see all the differences between the two versions, determine what exactly was happening and how it was fixed.

## The Root Cause

The root cause is in a function that the decomp project has named bgReset which can be found in [src/game/bg.c](src/game/bg.c). This function is somewhat complex so we'll just cover the important parts here.

bgReset is called while the screen is black after accepting the challenge. It's responsible for loading the background (BG) file for a stage. BG files contain the stage polygon data, room information, a texture list and lighting information among other things. The exact format of the file is not important here, but you just need to know that it contains several sections and some of those sections are compressed, similar to a zip file.

The problem starts when loading the section 2 data, approximately half way into the function. Section 2 is a section of the BG file that is very simple; it's just a compressed list of texture IDs. Let's start by looking at the fix the developers made:

    #if VERSION >= VERSION_NTSC_FINAL
        // Fixed version
        section2 = mempAlloc(inflatedsize + 0x8000, MEMPOOL_STAGE);
        scratch = (u32)section2 + 0x8000;
    #else
        // Buggy version
        section2 = mempAlloc(inflatedsize + 0x800, MEMPOOL_STAGE);
        scratch = (u32)section2 + 0x800;
    #endif

This code is allocating space in memory for section 2. It's intentionally overallocating it and setting up a scratch pointer into a later part of that space. We can see that the buggy code was adding an extra 0x800 to the allocation, and their fix was to bump this up to 0x8000. This doesn't give any answers though, so let's see how this allocation is used.

    // Load compressed data from ROM to scratch
	bgLoadFile((u8 *)scratch, section2start + 4, ((section2compsize - 1) | 0xf) + 1);

bgLoadFile's arguments are u8 *destination, u32 bgfileoffset, u32 length. It loads part of a BG file from the ROM and writes it to the destination, in this case the scratch pointer. The + 4 in the second argument is just skipping past a section header so it copies the body of the section only. And the last argument is the compressed size, rounded up to the next 16-byte boundary. This rounding is required because the N64 requires loads from the ROM to be in increments of 16 bytes. To put it simply, this function is copying the compressed data from the ROM to the scratch pointer.

Hold up. Let's do some math. How much space is available in the scratch? For the buggy version the pointer is 0x800 into the allocation, and the allocation is inflatedsize + 0x800, so we know we have inflatedsize available to place the compressed buffer. For the fixed version the pointer is 0x8000 into the allocation, and the allocation is inflatedsize + 0x8000, so we end up with... also just inflatedsize. The exact same amount of space is available in both versions. All it's done is move the scratch further away from the start of the allocation and increased the allocation accordingly.

	// Inflate section 2 to the start of the buffer
	bgInflate((u8 *)scratch, section2, section2compsize);

bgInflate's arguments are u8 *source, u8 *destination, u32 compressedlength. It decompresses the source to the destination, which in this case is decompressing it to the start of the allocation. So maybe the buggy code had the two streams too close to each other, and the inflated stream was overwriting the compressed stream while it was still being decompressed? Sounds plausible. For this to happen, the inflated size would have to be at least 0x800 bytes. Maybe the Warehouse stage (used by Challenge 7) is the only file with a section 2 this big? Let's take a look.

0x3c. The inflated size of the texture list is just 0x3c bytes. That's less than 1/30th of the allocation. There's no way this is writing over the compressed stream.

At this point I actually concluded that this was not the source of the Challenge 7 bug, documented it as such, and moved on to continue my search. But of course this was absolutely the source of the bug, and I completely missed what was happening.

## Memory Management

Before we go any further, we need to understand a bit about how memory is managed in Perfect Dark and on the Nintendo 64 in general.

The Nintendo 64 has 4MB of onboard memory. This is addressable in the range 0x80000000 to 0x80400000. With the expansion pak inserted in the console you get an additional 4MB in the range 0x80400000 to 0x80800000. While the expansion pak is optional in Perfect Dark, you must have the expansion pak to be able to play with 3 or more players. And because this bug only occurs with 3 players, we know the expansion pak must be used to trigger it.

A very basic view of the memory layout is as follows:

* Onboard: 0x80000000 to 0x800ad1c0 = immovable code and data
* Onboard: 0x800ad1c0 to 0x80220000 = onboard memory bank (heap)
* Onboard: 0x80220000 to 0x80400000 = more immovable code and data
* Expansion: 0x80400000 to 0x80800000 = expansion pak memory bank (a second heap)

When the game needs to allocate memory it asks the memory system to allocate a certain size. The memory system tries to allocate it out of the onboard bank. These allocations are made left to right. If there's not enough space available in the onboard bank then it tries the expansion pak bank in the same way.

The memory system also supports allocating from right to left. This method is used only by texture data allocations.

You can think of each memory bank as a block containing two pointers: a left and a right pointer. As allocations are made from the left side the left pointer moves towards the right, and as allocations are made from the right side the right pointer is moved towards the left. The gap between the two pointers is the amount of free space, and when they meet the bank is considered to be full.

## The Root Cause... Again

We'll step through the code again, starting from a couple of statements earlier than we did above, and this time calculating the actual values that are used and dumping memory values.

    inflatedsize = (*(u16 *)&header[0] & 0x7fff) - 1;
    section2compsize = *(u16 *)&header[2];
    inflatedsize = (inflatedsize | 0xf) + 1;

This is reading the inflated and compressed sizes from a header within the file. inflatedsize is rounded up to the next 16-byte alignment.

The inflatedsize value in the header is 0x3c, which after alignment becomes 0x40.

And the section2compsize value in the header is 0x44, which is bigger than the inflated size. That's not surprising - the data is a list of unique texture IDs. There's no repetition and not much data, so this wouldn't compress very well.

    section2 = mempAlloc(inflatedsize + 0x800, MEMPOOL_STAGE);
    scratch = (u32)section2 + 0x800;

Because inflatedsize is 0x40, the allocation is 0x840. And scratch points at 0x800 into the allocation, which is 0x40 from the end.

Prior to this allocation being made, the memory system's onboard bank has the following values:

* Left pointer = 0x80211c70
* Right pointer = 0x802124b0
* (free space = 0x840)

The allocation is made from the onboard bank, which has just the amount of free space that's needed and is now completely full.

	bgLoadFile((u8 *)scratch, section2start + 4, ((section2compsize - 1) | 0xf) + 1);

section2compsize is 0x44. But the value being passed to bgLoadFile is after alignment which is 0x50. So it's copying 0x50 bytes into a buffer of size 0x40. This normally wouldn't be an issue because the space to the right is usually unallocated, but because the allocation is flush against the end of the onboard memory bank the space to the right is in use and 0x10 bytes of it is being inadvertently overwritten.

As stated earlier, the allocations on the right side of the bank are for texture data. The format of this data is not well understood yet, but it contains pointers. The 0x10 overflow is overwriting one of these pointers. Then during gameplay the game is trying to read this value as if it were a pointer, leading to a crash.

## The Fix

With this knowledge we can understand why the fix they made works. Increasing the extra allocation to 0x8000 was not done because it needed more space. It was done so that the memory system would make the allocation from the expansion pak bank, therefore allowing the overflow to happen into unallocated space where it wouldn't cause any issues. This is not fixing the root issue, but is instead moving the goal posts so the bug doesn't score a goal.

A better fix would be to change the allocation size so it's just the aligned inflated size + aligned compressed size, then set the scratch to the allocation + aligned inflated size. I'm sure the developer knew what the root issue was but chose to use their safer fix instead. Imagine you're a developer on the game and you've just sent the master copy of the game the previous day for production, and now you're fixing a critical bug so you can send a new master today. There is no time for testing. Making a mistake with the calculation could cost the company a huge amount of money due to recalls and another round of production. It's understandable why they implemented the fix they did. They must have been sure that 0x8000 was enough to fix it.

## Conclusion

The one line tl;dr: When loading the background data for a stage, if the background file contained a specific section that decompressed to a smaller size than the compressed data itself, an overflow would occur due to a miscalculated buffer size. For the overflow to cause any problems the allocation had to be made from the first memory bank and be the exact same size as the remaining space in that bank. If this criteria was met, the overflow would overwrite a pointer in texture data which would cause a crash. The fix that was made increases the allocation to point where it can never be made out of the first bank, therefore avoiding the issue.

But what about the requirement of having 3 players? Why does it not happen with 4? Because each additional player causes an additional player structure to be allocated, and these are made prior to bgReset being called which means they affect the amount of free space in the first bank when bgReset is run. With 1 or 2 players there's going to be more memory available so the issue does not occur. And when playing with 4 players the expansion pak bank starts to be used sooner so the issue does not occur there either. Using 3 players on this particular stage made it total to the exact value that was needed for the onboard bank to be full at this point. In contrast, changing other settings like the number of bots or the weapon loadout would have no effect on this because those are allocated after bgReset is called.

Just to be clear, this situation was incredibly unlucky. Adding or deleting a couple of lines of code anywhere else in the game would have made this a non-issue because it would change the heap size (the heap is sized based on what's left over after code and data). And even if the memory system is in the danger territory, there's a 1 in 455 chance that any number of player structure allocations would line it up in a way that can trigger the bug (each player structure is 7280 bytes and there's a 16 byte window where the bug can occur).

Given that the root cause was not fixed, you may wonder if it's possible that the bug is still possible with other stages or versions of the game. This has been thoroughly examined and I can confidently say the bug can not occur in any other stage or version. Bumping the allocation to 0x8000 was an effective fix for the subsequent versions, and the memory system cannot achieve the exact total for any stage in NTSC beta or any other stage in NTSC 1.0.
