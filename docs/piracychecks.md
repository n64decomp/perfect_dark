# Piracy Checks

Perfect Dark contains several checks to determine if the game is running in unusual conditions, such as with modified boot loader or with modified functions. The functions which check for these are in various places throughout the code and some even occur during gameplay. Many of these functions are themselves checked by other functions. In other words, the game detects if you've defeated the first measure then applies a second measure.

If piracy is detected, the game will either corrupt certain functions in memory which causes instability and crashes, or it will alter things within the game to annoy you.

The decomp project wraps all decompiled piracy checks in `#if PIRACYCHECKS` statements. The project is built by default with piracy checks enabled. These are generally fine to keep enabled even when making changes to the source because the project recalculates and updates the expected checksums during the build process.

## List of Piracy Checks

### init

**When Called:** On power-on before the legal screen appears.

**What It Checks:** Checks an address in the bootloader (ROM address 0x2e8) for a known value.

**Payload:** Goes into an infinite loop so the system never boots.

### __scHandleRetrace

**When Called:** On every frame.

**What It Checks:** Checksums `init` to make sure it hasn't been modified.

**Piracy Condition:** Writes 40 bytes of 0xff to 0x80095210. This appears to be related to sound effects but has no obvious effect.

### cheatMenuHandleDialog

**When Called:** When the Cheats menu dialog is opened.

**What It Checks:** Checksums `__scHandleRetrace` to make sure it hasn't been modified.

**Payload:** Corrupts `__scHandleRetrace` by nopping the call to `__scAppendList` and some of the function arguments to `osRecvMesg`. Most likely results in a crash.

---

### func0f08e2ac

**When Called:** Unsure. Related to doors.

**What It Checks:** Checks that the value of `osCicId` is 6105.

**Payload:** Rewrites the start of `func0f08f968` so it immediately returns false. This makes it impossible to open doors.

### propobjHandlePickupByAibot

**When Called:** When a simulant in multiplayer picks up an item.

**What It Checks:** Checksums `func0f08e2ac` to make sure it hasn't been modified.

**Payload:** Rewrites the start of `func0f03978c` so it immediately returns true. This makes all guards able to see Jo through walls.

### chrUncloak

**When Called:** When a guard uncloaks.

**What It Checks:** Checksums `propobjHandlePickupByAibot` to make sure it hasn't been modified.

**Payload:** Disables the ability for the player and other characters to go up or down slopes. This is done by nopping the `jr ra` instruction in `cdFindGroundY`, which causes it to flow into the following function, which unconditionally returns false and only exists for this purpose.

---

### func0f028590

**When Called:** When a guard hears you.

**What It Checks:** Checksums `func00002078` to make sure it hasn't been modified. That function doesn't appear to have any piracy checks, however.

**Payload:** Sets the Skedar King's body file number to zero, which causes the game to crash when loading Skedar Ruins or WAR.

---

### lvGetSlowMotionType

**When Called:** On each tick when unpaused.

**What It Checks:** Checks an address in the bootloader (ROM address 0xa5c) for a known value.

**Payload:** Corrupts the rspboot microcode, causing a crash.

### lvInit

**When Called:** When loading any stage (including title screen).

**What It Checks:** Checksums `lvGetSlowMotionType` to make sure it hasn't been modified.

**Payload:** Writes 16 bytes of data to the start of EEPROM. Unsure what this does, but it's probably corrupting it.

### propAllocateEyespy

**When Called:** When loading any stage that uses the eyespy.

**What It Checks:** Checksums `lvInit` to make sure it hasn't been modified.

**Payload:** Nops `func00012914` entirely. Unsure what effect this has. This means any time that function is called it'll flow into the following function, which just returns.

---

### bgInit

**When Called:** When loading a normal stage (eg. CI Training).

**What It Checks:** Checks an address in the bootloader (ROM address 0x454) for a known value.

**Payload:** Copies 64 bytes from a random location in ROM to a random location in RAM.

### chrConsiderGrenadeThrow

**When Called:** When a chr decides to throw a grenade.

**What It Checks:** Checksums `bgInit` to make sure it hasn't been modified.

**Payload:** Surrounds the player in infinite explosions.

---

### tagsAllocatePtrs

**When Called:** When loading a normal stage (eg. CI Training).

**What It Checks:** Calls `func00015fd0` to get the value of `osRomBase` then compares it with a known value.

**Payload:** Copies 4KB from a random location in ROM to a random location in RAM.

### func0f09e144

**When Called:** Unknown.

**What It Checks:** Checksums `tagsAllocatePtrs` to make sure it hasn't been modified.

**Payload:** Corrupts `tagsAllocatePtrs` by writing 28 bytes of 0xff.

---

### func0f0069dc

**When Called:** Unknown.

**What It Checks:** Checksums `func00015fd0` to make sure it hasn't been modified.

**Payload:** Corrupts `bgInit` by writing 16 bytes of 0x12 to a random address within that function.

### func0f15c920

**When Called:** Unknown.

**What It Checks:** Checksums `func0f0069dc` to make sure it hasn't been modified.

**Payload:** Corrupts `bgBuildTables` by adding a fixed amount to 16 bytes within that function.

---

### func0f084cf0

**When Called:** When the player breaks glass.

**What It Checks:** Checks an address in the bootloader (ROM address 0xdc0) for a known value.

**Payload:** Sets the audio frequency to a high value which makes everyone sound like chipmunks.

### explosionAlertChrs

**When Called:** When there's an explosion.

**What It Checks:** Checksums `func0f084cf0` to make sure it hasn't been modified.

**Payload:** Makes all explosions huge.
