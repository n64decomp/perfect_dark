# Characters (chrs)

Chrs generally represent a person in the game. All of the following have chr structs allocated for them:

* Human guards and allies
* Maians
* Skedar
* Any players (Joanna/Velvet)
* Multiplayer simulants

Surprisingly, the eyespy also has its own chr struct.

And lastly, chr structs are allocated for every background (10xx) and environmental (14xx) AI list in the stage. These AI list types don't run in the context of a real chr, but still need a chr struct to save information to. These chrs are referred to as background chrs, or BG chrs. They have no models or positional data and will never be seen in the stage.

Because BG chrs are very different to regular chrs, they are stored in different arrays.

## The `g_ChrSlots` Array

The `g_ChrSlots` array holds an allocation of chr structs which is used for all chrs except BG chrs. Its allocated size is determined when the stage is loaded and is never changed until the stage is unloaded. The array can contain free slots, which can be identified by the chrnum being `-1`. The array is not sorted in any way; free slots can occur anywhere.

The allocation is:

* Sum of chrs to be placed in the stage according to its setup file
* Plus 1 for the player
* Plus however many is needed for a co-op player, co-op buddies or counter-op player
* Plus 10 spare

When the stage is started there will be 10 free slots. When chrs are spawned a slot becomes used, and when corpses are reaped (removed) their slot becomes free. Chrs cannot be spawned if there are no free slots.

## The `g_Chrnums` and `g_ChrIndexes` Arrays

These are two arrays which work together to allow the engine to quickly resolve a chr number to its struct.

* The `g_Chrnums` array is a list of chr numbers, kept in ascending order. It is kept in sync with `g_ChrSlots`, so every used slot in `g_ChrSlots` will have its chrnum in `g_Chrnums`.
* The `g_ChrIndexes` array mirrors the `g_Chrnums` array but stores the slot index of the chr struct. Whenever `g_Chrnums` is resorted, `g_ChrIndexes` is also updated with the same movements.

To resolve a chr number to its struct, the `g_Chrnums` array is bisected until the chrnum is found. The index of that chrnum in the `g_Chrnums` array is then used to grab the `g_ChrIndexes` value. That value is the index into `g_ChrSlots`.

## The `g_BgChrs` Array

The `g_BgChrs` array is similar to `g_ChrSlots` in that it stores entire chr structs. Its size is also determined when the stage is loaded.

The allocation is:

* Sum of background (10xx) and environmental (14xx) AI lists from the stage's setup file
* Plus 1 for something reserved

There are no free slots in this allocation, and slots are not changed during gameplay. The use of the reserved slot is not yet known.

## Chr Numbers and Registration

Registration is the term given when a slot and chrnum are assigned. Likewise, deregistration is the term given for when a chr slot and chrnum are marked as free.

Chr numbers are signed shorts which means they have a range of -32,768 to 32,767, however anything negative is considered to be a free slot.

* **0 to 3,999** are for manual allocation (ie. most/all guards)
* **4,000 to 4,899** are for BG chrs
* **4,900** is the ID of the reserved BG chr
* **5,000 to 32,767** are for automatic allocation

Whenever a chr is registered, a chrnum is automatically generated for it in the 5,000+ range. In most cases the game then assigns a manual chrnum to the chr (from zero onwards). This happens for all placed guards in a setup file. For chrs that spawn during gameplay it's up to the AI list scripting to assign a new chrnum if it wants to.

When an automatic chrnum is allocated, a "next" global variable is incremented. So if a chr is given chrnum 5010 then is reassigned to a low number, the next chr will be given 5011 even though 5010 is available. For this reason it's common to have the player have a chrnum of 5060 or so when 5000-5059 are not used.

If you repeatedly kill and spawn enough chrs to reach the 32,767 limit the number will wrap around to 5,000 again. And at this point, the game ensures the automatic chrnum is not in use before assigning it.
