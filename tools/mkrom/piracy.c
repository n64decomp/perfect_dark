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
void piracy_patch(void)
{
	// algorithm, patch function, sum function
	patch(algo01, "__scHandleTasks", "bootPhase1");
	patch(algo02, "cheatMenuHandleDialog", "__scHandleTasks");
	patch(algo03, "botPickupProp", "doorFinishClose");
	patch(algo04, "chrUncloak", "botPickupProp");
	patch(algo05, "chrsCheckForNoise", "__scHandleRetrace");
	patch(algo06, "lvReset", "lvGetSlowMotionType");
	patch(algo07, "bodyAllocateEyespy", "lvReset");
	patch(algo08, "chrConsiderGrenadeThrow", "bgReset");
	patch(algo09, "bgunTickGunLoad", "tagsReset");
	patch(algo10, "explosionAlertChrs", "glassDestroy");
	patch(algo11, "menuTickTimers", "mtxGetObfuscatedRomBase");
	patch(algo12, "func0f15c920", "menuTickTimers");
}
