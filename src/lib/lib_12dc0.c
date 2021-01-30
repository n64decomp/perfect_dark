#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02a0e0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_2fa00.h"
#include "types.h"

u64 rand_seed = 0xab8d9f7781280783;

u32 var8005ee08 = 0x00000000;
u32 var8005ee0c = 0x00000000;
s32 argc = 1;

char *argv[17] = {
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
};

GLOBAL_ASM(
glabel random
/*    12dc0:	3c048006 */ 	lui	$a0,%hi(rand_seed)
/*    12dc4:	dc84ee00 */ 	ld	$a0,%lo(rand_seed)($a0)
/*    12dc8:	3c018006 */ 	lui	$at,%hi(rand_seed)
/*    12dcc:	000437fc */ 	dsll32	$a2,$a0,0x1f
/*    12dd0:	00042ff8 */ 	dsll	$a1,$a0,0x1f
/*    12dd4:	000637fa */ 	dsrl	$a2,$a2,0x1f
/*    12dd8:	0005283e */ 	dsrl32	$a1,$a1,0x0
/*    12ddc:	0004233c */ 	dsll32	$a0,$a0,0xc
/*    12de0:	00c53025 */ 	or	$a2,$a2,$a1
/*    12de4:	0004203e */ 	dsrl32	$a0,$a0,0x0
/*    12de8:	00c43026 */ 	xor	$a2,$a2,$a0
/*    12dec:	0006253a */ 	dsrl	$a0,$a2,0x14
/*    12df0:	30840fff */ 	andi	$a0,$a0,0xfff
/*    12df4:	00862026 */ 	xor	$a0,$a0,$a2
/*    12df8:	0004103c */ 	dsll32	$v0,$a0,0x0
/*    12dfc:	fc24ee00 */ 	sd	$a0,%lo(rand_seed)($at)
/*    12e00:	03e00008 */ 	jr	$ra
/*    12e04:	0002103f */ 	dsra32	$v0,$v0,0x0
);

// Commented because ld isn't happy with bitshifting a u64.
//u32 random(void)
//{
//	rand_seed = ((rand_seed << 63) >> 31 | (rand_seed << 31) >> 32) ^ (rand_seed << 44) >> 32;
//	rand_seed = rand_seed >> 20 & 0xfff ^ rand_seed;
//
//	return rand_seed;
//}

GLOBAL_ASM(
glabel rngSetSeed
/*    12e08:	64840001 */ 	daddiu	$a0,$a0,0x1
/*    12e0c:	3c018006 */ 	lui	$at,%hi(rand_seed)
/*    12e10:	fc24ee00 */ 	sd	$a0,%lo(rand_seed)($at)
/*    12e14:	03e00008 */ 	jr	$ra
/*    12e18:	24040000 */ 	addiu	$a0,$zero,0x0
);

GLOBAL_ASM(
glabel func00012e1c
/*    12e1c:	dc870000 */ 	ld	$a3,0x0($a0)
/*    12e20:	000737fc */ 	dsll32	$a2,$a3,0x1f
/*    12e24:	00072ff8 */ 	dsll	$a1,$a3,0x1f
/*    12e28:	000637fa */ 	dsrl	$a2,$a2,0x1f
/*    12e2c:	0005283e */ 	dsrl32	$a1,$a1,0x0
/*    12e30:	00073b3c */ 	dsll32	$a3,$a3,0xc
/*    12e34:	00c53025 */ 	or	$a2,$a2,$a1
/*    12e38:	0007383e */ 	dsrl32	$a3,$a3,0x0
/*    12e3c:	00c73026 */ 	xor	$a2,$a2,$a3
/*    12e40:	00063d3a */ 	dsrl	$a3,$a2,0x14
/*    12e44:	30e70fff */ 	andi	$a3,$a3,0xfff
/*    12e48:	00e63826 */ 	xor	$a3,$a3,$a2
/*    12e4c:	0007103c */ 	dsll32	$v0,$a3,0x0
/*    12e50:	fc870000 */ 	sd	$a3,0x0($a0)
/*    12e54:	03e00008 */ 	jr	$ra
/*    12e58:	0002103f */ 	dsra32	$v0,$v0,0x0
/*    12e5c:	00000000 */ 	nop
);

/**
 * Split the given string into words and populate the argv array.
 */
char *argParseString(char *str)
{
	argv[0] = "";
	argc = 1;

	while (*str != '\0') {
		while (*str == ' ') {
			*str = '\0';
			str++;
		}

		argv[argc] = str;
		argc++;

		while (*str > ' ') {
			*str++;
		}
	}

	return str;
}

void argSetString(char *string)
{
	strcpy(g_ArgBuffer, string);
	argParseString((char *) g_ArgBuffer);
}

bool argsParseDebugArgs(void)
{
	u32 devaddr;
	u32 stack;
	s32 i;
	bool ret = false;

	devaddr = 0x1ffff00;

	if (rmonIsDisabled()) {
		g_ArgBuffer[0] = 0;
	} else {
		for (i = 0; i < 30; i++) {
			osPiReadIo(devaddr, &g_ArgBuffer[i]);
			devaddr += 4;
		}
	}

	argParseString((char *) g_ArgBuffer);

	// I'm guessing the -d stands for debug. If set at boot, the main thread
	// stops itself immediately after creating the rmon thread.
	if (argFindByPrefix(1, "-d")) {
		ret = true;
	}

	if (argFindByPrefix(1, "-s")) {
		g_Silent = true;
	}

	if (argFindByPrefix(1, "-j")) {
		g_LanguageId = LANGUAGE_JAPANESE;
	}

	return ret;
}

/**
 * Find a program argument based on its prefix and occurrence of that prefix,
 * and return a pointer to whatever comes after the prefix.
 *
 * Typically called with arguments such as 1, "-hard". In this example, if the
 * argument "-hard2" exists then it would return a pointer to "2".
 */
char *argFindByPrefix(s32 occurrence, char *str)
{
	s32 len = strlen(str);
	s32 i;

	for (i = 1; i < argc; i++) {
		if (strncmp(str, argv[i], len) == 0) {
			occurrence--;

			if (occurrence == 0) {
				return &argv[i][len];
			}
		}
	}

	return NULL;
}

void argGetLevel(s32 *stagenum)
{
	char *ptr = argFindByPrefix(1, "-level_");

	if (ptr) {
		*stagenum = ptr[0] * 10 + ptr[1] - 528;
	}
}
