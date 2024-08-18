#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "mkrom.h"

#define CHECKSUM_PLACEHOLDER 0x99aabbcc

extern struct state state;

typedef uint32_t (*Algo)(uint32_t sum, uint32_t word);

static uint32_t algo01(uint32_t sum, uint32_t word) { return sum ^ word; }
static uint32_t algo02(uint32_t sum, uint32_t word) { return sum ^ ~word; }
static uint32_t algo03(uint32_t sum, uint32_t word) { return (sum + word) * 2; }
static uint32_t algo04(uint32_t sum, uint32_t word) { return sum + ~word; }
static uint32_t algo05(uint32_t sum, uint32_t word) { return sum * 2 + word; }
static uint32_t algo06(uint32_t sum, uint32_t word) { return sum + word; }
static uint32_t algo07(uint32_t sum, uint32_t word) { return (sum << 1) ^ word; }
static uint32_t algo08(uint32_t sum, uint32_t word) { return (sum + word) + (word >> 1); }
static uint32_t algo09(uint32_t sum, uint32_t word) { return sum - ~word; }
static uint32_t algo10(uint32_t sum, uint32_t word) { return (sum ^ word) << 1; }
static uint32_t algo11(uint32_t sum, uint32_t word) { return (sum ^ ~word) << 1; }

static uint32_t algo12(uint32_t sum, uint32_t word) {
	sum ^= ~word;
	sum ^= word << 5;
	sum ^= word >> 15;
	return sum;
}

/**
 * Calculate the checksum of sumfunc.
 *
 * We just iterate each word in the function and run the algo function on each.
 */
static uint32_t calc_sum(char *sumfunc, Algo algo)
{
	uint32_t start;
	uint32_t end;
	uint32_t sum = 0;
	uint32_t offset;

	if (!map_get_function_rompos(sumfunc, &start, &end)) {
		fprintf(stderr, "Unable to find function \"%s\" in map file.\n", sumfunc);
		fprintf(stderr, "If a piracy function has been renamed then you may need to rebuild mkrom:\n");
		fprintf(stderr, "\n");
		fprintf(stderr, "    make -C tools/mkrom\n");
		fprintf(stderr, "\n");
		exit(1);
	}

	for (offset = start; offset < end; offset += 4) {
		sum = algo(sum, ntohl(*(uint32_t *) &state.rom[offset]));
	}

	return sum;
}

static bool is_branch_likely(uint32_t word)
{
	uint32_t op = word & 0xfc000000;

	if (op == 0x50000000) { // beql
		return true;
	}

	if (op == 0x54000000) { // bnel
		return true;
	}

	if (op == 0x58000000) { // blezl
		return true;
	}

	if (op == 0x5c000000) { // bgtzl
		return true;
	}

	if (op == 0x01000000 && (word & 0x001f0000) == 0x00020000) { // bltzl
		return true;
	}

	if (op == 0x01000000 && (word & 0x001f0000) == 0x00030000) { // bgezl
		return true;
	}

	return false;
}

/**
 * Search the patchfunc for the placeholder checksum and replace it with the one
 * we calculated.
 *
 * Checksums are always written into $at with lui and ori instructions.
 *
 * 3c0199aa   lui   $at,0x99aa
 * 3421bbcc   ori   $at,$at,0xbbcc
 */
static void write_sum(char *patchfunc, uint32_t sum)
{
	uint32_t start;
	uint32_t end;

	if (!map_get_function_rompos(patchfunc, &start, &end)) {
		fprintf(stderr, "Unable to find function \"%s\" in map file.\n", patchfunc);
		fprintf(stderr, "If a piracy function has been renamed then you may need to rebuild mkrom:\n");
		fprintf(stderr, "\n");
		fprintf(stderr, "    make -C tools/mkrom\n");
		fprintf(stderr, "\n");
		exit(1);
	}

	bool in_branchlikely = false;

	uint32_t upperpos = 0;
	uint32_t lowerpos = 0;
	uint32_t offset;

	for (offset = start; offset < end && (!upperpos || !lowerpos); offset += 4) {
		uint32_t word = ntohl(*(uint32_t *) &state.rom[offset]);

		if (in_branchlikely) {
			in_branchlikely = false;
		} else {
			if (is_branch_likely(word)) {
				in_branchlikely = true;
			} else if (word == (0x3c010000 | (CHECKSUM_PLACEHOLDER >> 16))) {
				upperpos = offset;
			} else if (upperpos && word == (0x34210000 | (CHECKSUM_PLACEHOLDER & 0xffff))) {
				lowerpos = offset;
			}
		}
	}

	if (!upperpos || !lowerpos) {
		fprintf(stderr, "Unable to find placeholder checksum in %s.\n", patchfunc);
		fprintf(stderr, "This can happen if you've turned PIRACYCHECKS off, built the files, then turned it on without rebuilding.\n");
		fprintf(stderr, "To fix, try running the following:\n");
		fprintf(stderr, "\n");
		fprintf(stderr, "    touch $(grep -lr PIRACYCHECKS src)\n");
		fprintf(stderr, "    make\n");
		fprintf(stderr, "\n");
		exit(1);
	}

	state.rom[upperpos + 2] = (sum >> 24) & 0xff;
	state.rom[upperpos + 3] = (sum >> 16) & 0xff;
	state.rom[lowerpos + 2] = (sum >> 8) & 0xff;
	state.rom[lowerpos + 3] = sum & 0xff;
}

static void patch(Algo algo, char *patchfunc, char *sumfunc)
{
	uint32_t sum = calc_sum(sumfunc, algo);

	write_sum(patchfunc, sum);
}

/**
 * Patch all the piracy functions in the game.
 */
void piracy_patch_checksums(void)
{
	// algorithm, patch function, sum function
	patch(algo01, "__scHandleTasks", "boot");
	patch(algo02, "cheat_menu_handle_dialog", "__scHandleTasks");
	patch(algo03, "bot_pickup_prop", "door_finish_close");
	patch(algo04, "chr_uncloak", "bot_pickup_prop");
	patch(algo05, "chrs_check_for_noise", "__scHandleRetrace");
	patch(algo06, "lv_reset", "lv_get_slow_motion_type");
	patch(algo07, "body_instantiate_eyespy", "lv_reset");
	patch(algo08, "chr_consider_grenade_throw", "bg_reset");
	patch(algo09, "bgun_tick_gun_load", "tags_reset");
	patch(algo10, "explosion_alert_chrs", "glass_destroy");
	patch(algo11, "menu_tick_timers", "mtx_get_obfuscated_rom_base");
	patch(algo12, "bg_tick_counter", "menu_tick_timers");
}

/**
 * NTSC Beta's original main_loop function reads from a hardware device and
 * refuses to run if it doesn't exist. Because of this, the reads must be
 * patched to allow a ROM to work without this hardware.
 *
 * Decomp's target ROM is the patched one, so we apply the patch here.
 */
void piracy_patch_mainloop(void)
{
	uint32_t start;
	uint32_t end;
	uint32_t offset;
	bool done_first = false;

	if (!map_get_function_rompos("main_loop", &start, &end)) {
		return;
	}

	for (offset = start; offset < end; offset += 4) {
		uint32_t word = 0;
		word |= state.rom[offset] << 24;
		word |= state.rom[offset + 1] << 16;
		word |= state.rom[offset + 2] << 8;
		word |= state.rom[offset + 3];

		if (!done_first) {
			if (word == 0x84820000) { // lh $v0, 0($a0)
				// Replace with: li $v0, 0x4f4a
				state.rom[offset + 0] = 0x24;
				state.rom[offset + 1] = 0x02;
				state.rom[offset + 2] = 0x4f;
				state.rom[offset + 3] = 0x4a;
				done_first = true;
			}
		} else {
			if (word == 0x84820002) { // lh $v0, 2($a0)
				// Replace with: li $v0, 0x4653
				state.rom[offset + 0] = 0x24;
				state.rom[offset + 1] = 0x02;
				state.rom[offset + 2] = 0x46;
				state.rom[offset + 3] = 0x53;
				break;
			}
		}
	}
}
