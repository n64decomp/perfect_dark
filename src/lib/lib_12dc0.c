#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
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

GLOBAL_ASM(
glabel func00012efc
/*    12efc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    12f00:	00802825 */ 	or	$a1,$a0,$zero
/*    12f04:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    12f08:	3c04800a */ 	lui	$a0,%hi(var80099880)
/*    12f0c:	0c004c4c */ 	jal	strcpy
/*    12f10:	24849880 */ 	addiu	$a0,$a0,%lo(var80099880)
/*    12f14:	3c04800a */ 	lui	$a0,%hi(var80099880)
/*    12f18:	0c004b98 */ 	jal	argParseString
/*    12f1c:	24849880 */ 	addiu	$a0,$a0,%lo(var80099880)
/*    12f20:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    12f24:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    12f28:	03e00008 */ 	jr	$ra
/*    12f2c:	00000000 */ 	nop
);

const char var70053ff4[] = "-d";
const char var70053ff8[] = "-s";
const char var70053ffc[] = "-j";

GLOBAL_ASM(
glabel func00012f30
/*    12f30:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    12f34:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    12f38:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    12f3c:	3c1101ff */ 	lui	$s1,0x1ff
/*    12f40:	afb20020 */ 	sw	$s2,0x20($sp)
/*    12f44:	afb00018 */ 	sw	$s0,0x18($sp)
/*    12f48:	afa00028 */ 	sw	$zero,0x28($sp)
/*    12f4c:	0c00be82 */ 	jal	func0002fa08
/*    12f50:	3631ff00 */ 	ori	$s1,$s1,0xff00
/*    12f54:	10400004 */ 	beqz	$v0,.L00012f68
/*    12f58:	3c10800a */ 	lui	$s0,%hi(var80099880)
/*    12f5c:	3c01800a */ 	lui	$at,%hi(var80099880)
/*    12f60:	1000000a */ 	b	.L00012f8c
/*    12f64:	ac209880 */ 	sw	$zero,%lo(var80099880)($at)
.L00012f68:
/*    12f68:	3c12800a */ 	lui	$s2,%hi(var800998f8)
/*    12f6c:	265298f8 */ 	addiu	$s2,$s2,%lo(var800998f8)
/*    12f70:	26109880 */ 	addiu	$s0,$s0,%lo(var80099880)
.L00012f74:
/*    12f74:	02202025 */ 	or	$a0,$s1,$zero
/*    12f78:	0c013994 */ 	jal	osPiReadIo
/*    12f7c:	02002825 */ 	or	$a1,$s0,$zero
/*    12f80:	26100004 */ 	addiu	$s0,$s0,0x4
/*    12f84:	1612fffb */ 	bne	$s0,$s2,.L00012f74
/*    12f88:	26310004 */ 	addiu	$s1,$s1,0x4
.L00012f8c:
/*    12f8c:	3c04800a */ 	lui	$a0,%hi(var80099880)
/*    12f90:	0c004b98 */ 	jal	argParseString
/*    12f94:	24849880 */ 	addiu	$a0,$a0,%lo(var80099880)
/*    12f98:	3c057005 */ 	lui	$a1,%hi(var70053ff4)
/*    12f9c:	24a53ff4 */ 	addiu	$a1,$a1,%lo(var70053ff4)
/*    12fa0:	0c004c04 */ 	jal	argFindByPrefix
/*    12fa4:	24040001 */ 	addiu	$a0,$zero,0x1
/*    12fa8:	10400003 */ 	beqz	$v0,.L00012fb8
/*    12fac:	24040001 */ 	addiu	$a0,$zero,0x1
/*    12fb0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*    12fb4:	afae0028 */ 	sw	$t6,0x28($sp)
.L00012fb8:
/*    12fb8:	3c057005 */ 	lui	$a1,%hi(var70053ff8)
/*    12fbc:	0c004c04 */ 	jal	argFindByPrefix
/*    12fc0:	24a53ff8 */ 	addiu	$a1,$a1,%lo(var70053ff8)
/*    12fc4:	10400004 */ 	beqz	$v0,.L00012fd8
/*    12fc8:	24040001 */ 	addiu	$a0,$zero,0x1
/*    12fcc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    12fd0:	3c018006 */ 	lui	$at,%hi(var8005dda0)
/*    12fd4:	ac2fdda0 */ 	sw	$t7,%lo(var8005dda0)($at)
.L00012fd8:
/*    12fd8:	3c057005 */ 	lui	$a1,%hi(var70053ffc)
/*    12fdc:	0c004c04 */ 	jal	argFindByPrefix
/*    12fe0:	24a53ffc */ 	addiu	$a1,$a1,%lo(var70053ffc)
/*    12fe4:	10400003 */ 	beqz	$v0,.L00012ff4
/*    12fe8:	24180001 */ 	addiu	$t8,$zero,0x1
/*    12fec:	3c018008 */ 	lui	$at,%hi(g_LanguageId)
/*    12ff0:	ac384120 */ 	sw	$t8,%lo(g_LanguageId)($at)
.L00012ff4:
/*    12ff4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    12ff8:	8fa20028 */ 	lw	$v0,0x28($sp)
/*    12ffc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    13000:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    13004:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    13008:	03e00008 */ 	jr	$ra
/*    1300c:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

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
