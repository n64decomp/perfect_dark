# Piracy Checks

Perfect Dark contains several checks to determine if the game is running in unusual conditions, such as with a modified boot loader or with modified functions. The functions which check for these are in various places throughout the code and some even occur during gameplay. Many of these functions are themselves checked by other functions. In other words, the game detects if you've defeated the first measure then applies a second measure.

If piracy is detected, the game will either corrupt certain functions in memory which causes instability and crashes, or it will alter things within the game to annoy you.

The decomp project wraps all decompiled piracy checks in `#if PIRACYCHECKS` statements. The project is built by default with piracy checks enabled. These are generally fine to keep enabled even when making changes to the source because the project recalculates and updates the expected checksums during the build process.

## List of Piracy Checks

### boot

**When Called:** On power-on before the legal screen appears.

**What It Checks:** Checks an address in the bootloader (ROM address 0x2e8) for a known value.

**Payload:** Goes into an infinite loop so the system never boots.

### __scHandleTasks

**When Called:** On every frame.

**What It Checks:** Checksums `boot` to make sure it hasn't been modified.

**Payload:** Writes 40 bytes of 0xff to 0x80095210. This appears to be related to sound effects but has no obvious effect.

### cheat_menu_handle_dialog

**When Called:** When the Cheats menu dialog is opened.

**What It Checks:** Checksums `__scHandleTasks` to make sure it hasn't been modified.

**Payload:** Corrupts `__scHandleTasks` by nopping the call to `__scAppendList` and some of the function arguments to `osRecvMesg`. Most likely results in a crash.

---

### door_finish_close

**When Called:** When a door finishes closing.

**What It Checks:** Checks that the value of `osCicId` is 6105.

**Payload:** Rewrites the start of `func0f08f968` so it immediately returns false. This makes it impossible to open doors.

### bot_pickup_prop

**When Called:** When a simulant in multiplayer picks up an item.

**What It Checks:** Checksums `door_finish_close` to make sure it hasn't been modified.

**Payload:** Rewrites the start of `chr_check_can_see_target` so it immediately returns true. This makes all guards able to see Jo through walls.

### chr_uncloak

**When Called:** When a guard uncloaks.

**What It Checks:** Checksums `bot_pickup_prop` to make sure it hasn't been modified.

**Payload:** Disables the ability for the player and other characters to go up or down slopes. This is done by nopping the `jr ra` instruction in `cd_find_ground_info_at_cyl`, which causes it to flow into the following function, which unconditionally returns false and only exists for this purpose.

---

### chrs_check_for_noise

**When Called:** When a guard hears you.

**What It Checks:** Checksums `__scHandleRetrace` to make sure it hasn't been modified. That function doesn't appear to have any piracy checks, however.

**Payload:** Sets the Skedar King's body file number to zero, which causes the game to crash when loading Skedar Ruins or WAR.

---

### lv_get_slow_motion_type

**When Called:** On each tick when unpaused.

**What It Checks:** Checks an address in the bootloader (ROM address 0xa5c) for a known value.

**Payload:** Corrupts the rspboot microcode, causing a crash.

### lv_reset

**When Called:** When loading any stage (including title screen).

**What It Checks:** Checksums `lv_get_slow_motion_type` to make sure it hasn't been modified.

**Payload:** Writes a filesystem terminator file to the start of EEPROM. This disables the cartridge's save data, removing the ability to read existing files and create new ones.

### body_allocate_eyespy

**When Called:** When loading any stage that uses the eyespy.

**What It Checks:** Checksums `lv_reset` to make sure it hasn't been modified.

**Payload:** Nops `_mema_free` entirely, so any time that function is called it'll flow into the following function, which just returns. The effect this has is that the system is unable to free individual mema allocations which makes it unable to load rooms as you move throughout the level.

---

### bg_reset

**When Called:** When loading a normal stage (eg. CI Training).

**What It Checks:** Checks an address in the bootloader (ROM address 0x454) for a known value.

**Payload:** Copies 64 bytes from a random location in ROM to a random location in RAM.

### chr_consider_grenade_throw

**When Called:** When a chr decides to throw a grenade.

**What It Checks:** Checksums `bg_reset` to make sure it hasn't been modified.

**Payload:** Surrounds the player in infinite explosions.

---

### tags_reset

**When Called:** When loading a normal stage (eg. CI Training).

**What It Checks:** Calls `mtx_get_obfuscated_rom_base` to get the value of `osRomBase` then compares it with a known value.

**Payload:** Copies 4KB from a random location in ROM to a random location in RAM.

### bgun_tick_gun_load

**When Called:** When equipping any weapon.

**What It Checks:** Checksums `tags_reset` to make sure it hasn't been modified.

**Payload:** Corrupts `tags_reset` by writing 4 bytes of 0xff.

---

### menu_tick_timers

**When Called:** On every frame except credits.

**What It Checks:** Checksums `mtx_get_obfuscated_rom_base` to make sure it hasn't been modified.

**Payload:** Corrupts `bg_reset` by writing 16 bytes of 0x12 to a random address within that function.

### bg_tick_counter

**When Called:** On every frame.

**What It Checks:** Checksums `menu_tick_timers` to make sure it hasn't been modified.

**Payload:** Corrupts `bg_build_tables` by adding a fixed amount to 16 bytes within that function.

---

### glass_destroy

**When Called:** When the player breaks glass.

**What It Checks:** Checks an address in the bootloader (ROM address 0xdc0) for a known value.

**Payload:** Sets the audio frequency to a high value which makes everyone sound like chipmunks.

### explosion_alert_chrs

**When Called:** When there's an explosion.

**What It Checks:** Checksums `glass_destroy` to make sure it hasn't been modified.

**Payload:** Makes all explosions huge.
