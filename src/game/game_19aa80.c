#include <ultra64.h>
#include "constants.h"
#include "game/chr/chrai.h"
#include "game/chr/chraicommands.h"
#include "game/prop.h"
#include "game/atan2f.h"
#include "game/game_127910.h"
#include "game/mplayer/setup.h"
#include "game/game_190260.h"
#include "game/game_19aa80.h"
#include "game/training/training.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "bss.h"
#include "lib/dma.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

u8 g_MpFeaturesForceUnlocked[40];
u8 g_MpFeaturesUnlocked[80];

u32 g_MpChallengeIndex = 0;
struct mpconfigfull *g_MpCurrentChallengeConfig = NULL;

// 2e4d8
struct challenge g_MpChallenges[NUM_CHALLENGES] = {
	{ L_OPTIONS_406, MPCONFIG_CHALLENGE01 }, // "Challenge 1"
	{ L_OPTIONS_407, MPCONFIG_CHALLENGE02 }, // "Challenge 2"
	{ L_OPTIONS_408, MPCONFIG_CHALLENGE03 }, // "Challenge 3"
	{ L_OPTIONS_409, MPCONFIG_CHALLENGE04 }, // "Challenge 4"
	{ L_OPTIONS_410, MPCONFIG_CHALLENGE05 }, // "Challenge 5"
	{ L_OPTIONS_411, MPCONFIG_CHALLENGE06 }, // "Challenge 6"
	{ L_OPTIONS_412, MPCONFIG_CHALLENGE07 }, // "Challenge 7"
	{ L_OPTIONS_413, MPCONFIG_CHALLENGE08 }, // "Challenge 8"
	{ L_OPTIONS_414, MPCONFIG_CHALLENGE09 }, // "Challenge 9"
	{ L_OPTIONS_415, MPCONFIG_CHALLENGE10 }, // "Challenge 10"
	{ L_OPTIONS_416, MPCONFIG_CHALLENGE11 }, // "Challenge 11"
	{ L_OPTIONS_417, MPCONFIG_CHALLENGE12 }, // "Challenge 12"
	{ L_OPTIONS_418, MPCONFIG_CHALLENGE13 }, // "Challenge 13"
	{ L_OPTIONS_419, MPCONFIG_CHALLENGE14 }, // "Challenge 14"
	{ L_OPTIONS_420, MPCONFIG_CHALLENGE15 }, // "Challenge 15"
	{ L_OPTIONS_421, MPCONFIG_CHALLENGE16 }, // "Challenge 16"
	{ L_OPTIONS_422, MPCONFIG_CHALLENGE17 }, // "Challenge 17"
	{ L_OPTIONS_423, MPCONFIG_CHALLENGE18 }, // "Challenge 18"
	{ L_OPTIONS_424, MPCONFIG_CHALLENGE19 }, // "Challenge 19"
	{ L_OPTIONS_425, MPCONFIG_CHALLENGE20 }, // "Challenge 20"
	{ L_OPTIONS_426, MPCONFIG_CHALLENGE21 }, // "Challenge 21"
	{ L_OPTIONS_427, MPCONFIG_CHALLENGE22 }, // "Challenge 22"
	{ L_OPTIONS_428, MPCONFIG_CHALLENGE23 }, // "Challenge 23"
	{ L_OPTIONS_429, MPCONFIG_CHALLENGE24 }, // "Challenge 24"
	{ L_OPTIONS_430, MPCONFIG_CHALLENGE25 }, // "Challenge 25"
	{ L_OPTIONS_431, MPCONFIG_CHALLENGE26 }, // "Challenge 26"
	{ L_OPTIONS_432, MPCONFIG_CHALLENGE27 }, // "Challenge 27"
	{ L_OPTIONS_433, MPCONFIG_CHALLENGE28 }, // "Challenge 28"
	{ L_OPTIONS_434, MPCONFIG_CHALLENGE29 }, // "Challenge 29"
	{ L_OPTIONS_435, MPCONFIG_CHALLENGE30 }, // "Challenge 30"
};

/**
 * @cmd 0185
 */
bool aiMpInitSimulants(void)
{
	mpInitSimulants();
	g_Vars.aioffset += 2;
	return false;
}

/**
 * @cmd 0176
 */
bool ai0176(void)
{
	u8 *cmd = g_Vars.ailist + g_Vars.aioffset;
	struct aibot *aibot;

	/**
	 * @bug: Missing return means a crash will occur if either of these are
	 * null.
	 */
	if (!g_Vars.chrdata || !g_Vars.chrdata->aibot) {
		g_Vars.aioffset += 3;
		//return false;
	}

	aibot = g_Vars.chrdata->aibot;

	if (aibot->unk059 == 1) {
		g_Vars.aioffset = chraiGoToLabel(g_Vars.ailist, g_Vars.aioffset, cmd[2]);
		aibot->unk059 = 0;
	} else {
		g_Vars.aioffset += 3;
	}

	return false;
}

#if VERSION >= VERSION_NTSC_1_0
void func0f19ab40(void)
{
	if (g_Is4Mb) {
		var80090af4 = 0;
		var80090af8 = 0;
		var80090afc = 0;
	}
}
#else
const char var7f1b3750nb[] = "VM: Page Misses %d (%d Replaces)";
const char var7f1b3774nb[] = "VM: TLB Misses %d";

GLOBAL_ASM(
glabel func0f19ab40
/*  f194b20:	3c0e8009 */ 	lui	$t6,0x8009
/*  f194b24:	91ce30e0 */ 	lbu	$t6,0x30e0($t6)
/*  f194b28:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f194b2c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f194b30:	11c0002b */ 	beqz	$t6,.NB0f194be0
/*  f194b34:	3c0f8006 */ 	lui	$t7,0x8006
/*  f194b38:	91efe710 */ 	lbu	$t7,-0x18f0($t7)
/*  f194b3c:	240400ff */ 	addiu	$a0,$zero,0xff
/*  f194b40:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f194b44:	11e00020 */ 	beqz	$t7,.NB0f194bc8
/*  f194b48:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f194b4c:	0c005106 */ 	jal	func000137bc
/*  f194b50:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f194b54:	00002025 */ 	or	$a0,$zero,$zero
/*  f194b58:	00002825 */ 	or	$a1,$zero,$zero
/*  f194b5c:	00003025 */ 	or	$a2,$zero,$zero
/*  f194b60:	0c005115 */ 	jal	func000137d0
/*  f194b64:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f194b68:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f194b6c:	3c068009 */ 	lui	$a2,0x8009
/*  f194b70:	3c078009 */ 	lui	$a3,0x8009
/*  f194b74:	8ce730ec */ 	lw	$a3,0x30ec($a3)
/*  f194b78:	8cc630e8 */ 	lw	$a2,0x30e8($a2)
/*  f194b7c:	24a53750 */ 	addiu	$a1,$a1,0x3750
/*  f194b80:	0c004fc1 */ 	jal	sprintf
/*  f194b84:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f194b88:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f194b8c:	0c0050df */ 	jal	func000137b0
/*  f194b90:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f194b94:	0c005175 */ 	jal	func000137fc
/*  f194b98:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f194b9c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f194ba0:	3c068009 */ 	lui	$a2,0x8009
/*  f194ba4:	8cc630e4 */ 	lw	$a2,0x30e4($a2)
/*  f194ba8:	24a53774 */ 	addiu	$a1,$a1,0x3774
/*  f194bac:	0c004fc1 */ 	jal	sprintf
/*  f194bb0:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f194bb4:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f194bb8:	0c0050df */ 	jal	func000137b0
/*  f194bbc:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f194bc0:	0c005175 */ 	jal	func000137fc
/*  f194bc4:	27a40018 */ 	addiu	$a0,$sp,0x18
.NB0f194bc8:
/*  f194bc8:	3c018009 */ 	lui	$at,0x8009
/*  f194bcc:	ac2030e4 */ 	sw	$zero,0x30e4($at)
/*  f194bd0:	3c018009 */ 	lui	$at,0x8009
/*  f194bd4:	ac2030e8 */ 	sw	$zero,0x30e8($at)
/*  f194bd8:	3c018009 */ 	lui	$at,0x8009
/*  f194bdc:	ac2030ec */ 	sw	$zero,0x30ec($at)
.NB0f194be0:
/*  f194be0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f194be4:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*  f194be8:	03e00008 */ 	jr	$ra
/*  f194bec:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

GLOBAL_ASM(
glabel func0f19ab70
/*  f19ab70:	27bdfde8 */ 	addiu	$sp,$sp,-536
/*  f19ab74:	afa40218 */ 	sw	$a0,0x218($sp)
/*  f19ab78:	87ae021a */ 	lh	$t6,0x21a($sp)
/*  f19ab7c:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f19ab80:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f19ab84:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f19ab88:	240fffff */ 	addiu	$t7,$zero,-1
/*  f19ab8c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f19ab90:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f19ab94:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f19ab98:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f19ab9c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f19aba0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f19aba4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f19aba8:	afa5021c */ 	sw	$a1,0x21c($sp)
/*  f19abac:	afa60220 */ 	sw	$a2,0x220($sp)
/*  f19abb0:	afa70224 */ 	sw	$a3,0x224($sp)
/*  f19abb4:	0000b025 */ 	or	$s6,$zero,$zero
/*  f19abb8:	0000a825 */ 	or	$s5,$zero,$zero
/*  f19abbc:	afa00050 */ 	sw	$zero,0x50($sp)
/*  f19abc0:	a7af0156 */ 	sh	$t7,0x156($sp)
/*  f19abc4:	0000a025 */ 	or	$s4,$zero,$zero
/*  f19abc8:	a7ae0154 */ 	sh	$t6,0x154($sp)
/*  f19abcc:	afa00054 */ 	sw	$zero,0x54($sp)
.L0f19abd0:
/*  f19abd0:	0fc458b4 */ 	jal	coverGetCount
/*  f19abd4:	00009025 */ 	or	$s2,$zero,$zero
/*  f19abd8:	1840002f */ 	blez	$v0,.L0f19ac98
/*  f19abdc:	0040f025 */ 	or	$s8,$v0,$zero
/*  f19abe0:	02402025 */ 	or	$a0,$s2,$zero
.L0f19abe4:
/*  f19abe4:	0fc458b8 */ 	jal	coverUnpack
/*  f19abe8:	27a50158 */ 	addiu	$a1,$sp,0x158
/*  f19abec:	50400027 */ 	beqzl	$v0,.L0f19ac8c
/*  f19abf0:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f19abf4:	0fc4596c */ 	jal	coverIsSpecial
/*  f19abf8:	27a40158 */ 	addiu	$a0,$sp,0x158
/*  f19abfc:	14400022 */ 	bnez	$v0,.L0f19ac88
/*  f19ac00:	27a40160 */ 	addiu	$a0,$sp,0x160
/*  f19ac04:	0fc19620 */ 	jal	arrayIntersects
/*  f19ac08:	27a50154 */ 	addiu	$a1,$sp,0x154
/*  f19ac0c:	1040001e */ 	beqz	$v0,.L0f19ac88
/*  f19ac10:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f19ac14:	1300000e */ 	beqz	$t8,.L0f19ac50
/*  f19ac18:	97b90164 */ 	lhu	$t9,0x164($sp)
/*  f19ac1c:	33280100 */ 	andi	$t0,$t9,0x100
/*  f19ac20:	1100000b */ 	beqz	$t0,.L0f19ac50
/*  f19ac24:	02402025 */ 	or	$a0,$s2,$zero
/*  f19ac28:	00164880 */ 	sll	$t1,$s6,0x2
/*  f19ac2c:	27aa016c */ 	addiu	$t2,$sp,0x16c
/*  f19ac30:	012a8021 */ 	addu	$s0,$t1,$t2
/*  f19ac34:	0fc4594a */ 	jal	coverUnsetFlag
/*  f19ac38:	24050100 */ 	addiu	$a1,$zero,0x100
/*  f19ac3c:	ae120000 */ 	sw	$s2,0x0($s0)
/*  f19ac40:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f19ac44:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f19ac48:	1000000c */ 	b	.L0f19ac7c
/*  f19ac4c:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f19ac50:
/*  f19ac50:	97ab0164 */ 	lhu	$t3,0x164($sp)
/*  f19ac54:	316c0100 */ 	andi	$t4,$t3,0x100
/*  f19ac58:	15800006 */ 	bnez	$t4,.L0f19ac74
/*  f19ac5c:	00166880 */ 	sll	$t5,$s6,0x2
/*  f19ac60:	03ad7021 */ 	addu	$t6,$sp,$t5
/*  f19ac64:	add2016c */ 	sw	$s2,0x16c($t6)
/*  f19ac68:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f19ac6c:	10000003 */ 	b	.L0f19ac7c
/*  f19ac70:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f19ac74:
/*  f19ac74:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f19ac78:	afaf0054 */ 	sw	$t7,0x54($sp)
.L0f19ac7c:
/*  f19ac7c:	2ac10028 */ 	slti	$at,$s6,0x28
/*  f19ac80:	10200005 */ 	beqz	$at,.L0f19ac98
/*  f19ac84:	00000000 */ 	nop
.L0f19ac88:
/*  f19ac88:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f19ac8c:
/*  f19ac8c:	025e082a */ 	slt	$at,$s2,$s8
/*  f19ac90:	5420ffd4 */ 	bnezl	$at,.L0f19abe4
/*  f19ac94:	02402025 */ 	or	$a0,$s2,$zero
.L0f19ac98:
/*  f19ac98:	3c18800a */ 	lui	$t8,%hi(g_StageSetup)
/*  f19ac9c:	8f18d030 */ 	lw	$t8,%lo(g_StageSetup)($t8)
/*  f19aca0:	53000047 */ 	beqzl	$t8,.L0f19adc0
/*  f19aca4:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f19aca8:	87b7021a */ 	lh	$s7,0x21a($sp)
/*  f19acac:	3c08800a */ 	lui	$t0,%hi(g_Rooms)
/*  f19acb0:	8d084928 */ 	lw	$t0,%lo(g_Rooms)($t0)
/*  f19acb4:	0017c8c0 */ 	sll	$t9,$s7,0x3
/*  f19acb8:	0337c821 */ 	addu	$t9,$t9,$s7
/*  f19acbc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f19acc0:	0337c823 */ 	subu	$t9,$t9,$s7
/*  f19acc4:	0019b880 */ 	sll	$s7,$t9,0x2
/*  f19acc8:	01174821 */ 	addu	$t1,$t0,$s7
/*  f19accc:	913e0009 */ 	lbu	$s8,0x9($t1)
/*  f19acd0:	00009025 */ 	or	$s2,$zero,$zero
/*  f19acd4:	5bc0003a */ 	blezl	$s8,.L0f19adc0
/*  f19acd8:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f19acdc:	00009825 */ 	or	$s3,$zero,$zero
.L0f19ace0:
/*  f19ace0:	3c0b800a */ 	lui	$t3,%hi(g_Rooms)
/*  f19ace4:	8d6b4928 */ 	lw	$t3,%lo(g_Rooms)($t3)
/*  f19ace8:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x60)
/*  f19acec:	8d4aa020 */ 	lw	$t2,%lo(g_Vars+0x60)($t2)
/*  f19acf0:	01776021 */ 	addu	$t4,$t3,$s7
/*  f19acf4:	958d000c */ 	lhu	$t5,0xc($t4)
/*  f19acf8:	3c08800a */ 	lui	$t0,%hi(g_StageSetup)
/*  f19acfc:	8d08d030 */ 	lw	$t0,%lo(g_StageSetup)($t0)
/*  f19ad00:	000d7040 */ 	sll	$t6,$t5,0x1
/*  f19ad04:	014e7821 */ 	addu	$t7,$t2,$t6
/*  f19ad08:	01f3c021 */ 	addu	$t8,$t7,$s3
/*  f19ad0c:	87020000 */ 	lh	$v0,0x0($t8)
/*  f19ad10:	24050080 */ 	addiu	$a1,$zero,0x80
/*  f19ad14:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f19ad18:	0002c900 */ 	sll	$t9,$v0,0x4
/*  f19ad1c:	03288821 */ 	addu	$s1,$t9,$t0
/*  f19ad20:	0fc456ac */ 	jal	padUnpack
/*  f19ad24:	8e240000 */ 	lw	$a0,0x0($s1)
/*  f19ad28:	8fa90050 */ 	lw	$t1,0x50($sp)
/*  f19ad2c:	51200011 */ 	beqzl	$t1,.L0f19ad74
/*  f19ad30:	8faf00a4 */ 	lw	$t7,0xa4($sp)
/*  f19ad34:	8fab00a4 */ 	lw	$t3,0xa4($sp)
/*  f19ad38:	3c050002 */ 	lui	$a1,0x2
/*  f19ad3c:	00156880 */ 	sll	$t5,$s5,0x2
/*  f19ad40:	000b6380 */ 	sll	$t4,$t3,0xe
/*  f19ad44:	0581000a */ 	bgez	$t4,.L0f19ad70
/*  f19ad48:	27aa00b4 */ 	addiu	$t2,$sp,0xb4
/*  f19ad4c:	8e240000 */ 	lw	$a0,0x0($s1)
/*  f19ad50:	0fc458a0 */ 	jal	padUnsetFlag
/*  f19ad54:	01aa8021 */ 	addu	$s0,$t5,$t2
/*  f19ad58:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f19ad5c:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f19ad60:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f19ad64:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f19ad68:	1000000e */ 	b	.L0f19ada4
/*  f19ad6c:	ae0efffc */ 	sw	$t6,-0x4($s0)
.L0f19ad70:
/*  f19ad70:	8faf00a4 */ 	lw	$t7,0xa4($sp)
.L0f19ad74:
/*  f19ad74:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f19ad78:	07020009 */ 	bltzl	$t8,.L0f19ada0
/*  f19ad7c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f19ad80:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f19ad84:	00154080 */ 	sll	$t0,$s5,0x2
/*  f19ad88:	03a84821 */ 	addu	$t1,$sp,$t0
/*  f19ad8c:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f19ad90:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f19ad94:	10000003 */ 	b	.L0f19ada4
/*  f19ad98:	ad3900b4 */ 	sw	$t9,0xb4($t1)
/*  f19ad9c:	240b0001 */ 	addiu	$t3,$zero,0x1
.L0f19ada0:
/*  f19ada0:	afab0054 */ 	sw	$t3,0x54($sp)
.L0f19ada4:
/*  f19ada4:	2aa10028 */ 	slti	$at,$s5,0x28
/*  f19ada8:	50200005 */ 	beqzl	$at,.L0f19adc0
/*  f19adac:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f19adb0:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f19adb4:	165effca */ 	bne	$s2,$s8,.L0f19ace0
/*  f19adb8:	26730002 */ 	addiu	$s3,$s3,0x2
/*  f19adbc:	8fac0054 */ 	lw	$t4,0x54($sp)
.L0f19adc0:
/*  f19adc0:	11800003 */ 	beqz	$t4,.L0f19add0
/*  f19adc4:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f19adc8:	5280ff81 */ 	beqzl	$s4,.L0f19abd0
/*  f19adcc:	afa00054 */ 	sw	$zero,0x54($sp)
.L0f19add0:
/*  f19add0:	16800003 */ 	bnez	$s4,.L0f19ade0
/*  f19add4:	00000000 */ 	nop
/*  f19add8:	10000041 */ 	b	.L0f19aee0
/*  f19addc:	00001025 */ 	or	$v0,$zero,$zero
.L0f19ade0:
/*  f19ade0:	0c004b70 */ 	jal	random
/*  f19ade4:	00000000 */ 	nop
/*  f19ade8:	0054001b */ 	divu	$zero,$v0,$s4
/*  f19adec:	00001810 */ 	mfhi	$v1
/*  f19adf0:	0076082a */ 	slt	$at,$v1,$s6
/*  f19adf4:	16800002 */ 	bnez	$s4,.L0f19ae00
/*  f19adf8:	00000000 */ 	nop
/*  f19adfc:	0007000d */ 	break	0x7
.L0f19ae00:
/*  f19ae00:	00609025 */ 	or	$s2,$v1,$zero
/*  f19ae04:	1020001b */ 	beqz	$at,.L0f19ae74
/*  f19ae08:	00036880 */ 	sll	$t5,$v1,0x2
/*  f19ae0c:	27aa016c */ 	addiu	$t2,$sp,0x16c
/*  f19ae10:	01aa8021 */ 	addu	$s0,$t5,$t2
/*  f19ae14:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f19ae18:	0fc458b8 */ 	jal	coverUnpack
/*  f19ae1c:	27a50158 */ 	addiu	$a1,$sp,0x158
/*  f19ae20:	8fae0158 */ 	lw	$t6,0x158($sp)
/*  f19ae24:	8faf021c */ 	lw	$t7,0x21c($sp)
/*  f19ae28:	c5c40000 */ 	lwc1	$f4,0x0($t6)
/*  f19ae2c:	e5e40000 */ 	swc1	$f4,0x0($t7)
/*  f19ae30:	c5c60004 */ 	lwc1	$f6,0x4($t6)
/*  f19ae34:	e5e60004 */ 	swc1	$f6,0x4($t7)
/*  f19ae38:	c5c80008 */ 	lwc1	$f8,0x8($t6)
/*  f19ae3c:	e5e80008 */ 	swc1	$f8,0x8($t7)
/*  f19ae40:	8fb8015c */ 	lw	$t8,0x15c($sp)
/*  f19ae44:	c70c0008 */ 	lwc1	$f12,0x8($t8)
/*  f19ae48:	0fc259d4 */ 	jal	atan2f
/*  f19ae4c:	c70e0000 */ 	lwc1	$f14,0x0($t8)
/*  f19ae50:	8fb90220 */ 	lw	$t9,0x220($sp)
/*  f19ae54:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f19ae58:	e7200000 */ 	swc1	$f0,0x0($t9)
/*  f19ae5c:	8fa90224 */ 	lw	$t1,0x224($sp)
/*  f19ae60:	ad280000 */ 	sw	$t0,0x0($t1)
/*  f19ae64:	8fac0228 */ 	lw	$t4,0x228($sp)
/*  f19ae68:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f19ae6c:	1000001b */ 	b	.L0f19aedc
/*  f19ae70:	ad8b0000 */ 	sw	$t3,0x0($t4)
.L0f19ae74:
/*  f19ae74:	02569023 */ 	subu	$s2,$s2,$s6
/*  f19ae78:	00126880 */ 	sll	$t5,$s2,0x2
/*  f19ae7c:	27aa00b4 */ 	addiu	$t2,$sp,0xb4
/*  f19ae80:	01aa8021 */ 	addu	$s0,$t5,$t2
/*  f19ae84:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f19ae88:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f19ae8c:	0fc456ac */ 	jal	padUnpack
/*  f19ae90:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f19ae94:	c7aa0058 */ 	lwc1	$f10,0x58($sp)
/*  f19ae98:	8fae021c */ 	lw	$t6,0x21c($sp)
/*  f19ae9c:	e5ca0000 */ 	swc1	$f10,0x0($t6)
/*  f19aea0:	c7b0005c */ 	lwc1	$f16,0x5c($sp)
/*  f19aea4:	e5d00004 */ 	swc1	$f16,0x4($t6)
/*  f19aea8:	c7b20060 */ 	lwc1	$f18,0x60($sp)
/*  f19aeac:	e5d20008 */ 	swc1	$f18,0x8($t6)
/*  f19aeb0:	c7ae0064 */ 	lwc1	$f14,0x64($sp)
/*  f19aeb4:	0fc259d4 */ 	jal	atan2f
/*  f19aeb8:	c7ac006c */ 	lwc1	$f12,0x6c($sp)
/*  f19aebc:	8faf0220 */ 	lw	$t7,0x220($sp)
/*  f19aec0:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f19aec4:	e5e00000 */ 	swc1	$f0,0x0($t7)
/*  f19aec8:	8fb90224 */ 	lw	$t9,0x224($sp)
/*  f19aecc:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f19aed0:	af380000 */ 	sw	$t8,0x0($t9)
/*  f19aed4:	8fa90228 */ 	lw	$t1,0x228($sp)
/*  f19aed8:	ad280000 */ 	sw	$t0,0x0($t1)
.L0f19aedc:
/*  f19aedc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19aee0:
/*  f19aee0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f19aee4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f19aee8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f19aeec:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f19aef0:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f19aef4:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f19aef8:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f19aefc:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f19af00:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f19af04:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f19af08:	03e00008 */ 	jr	$ra
/*  f19af0c:	27bd0218 */ 	addiu	$sp,$sp,0x218
);

bool func0f19af10(s32 challengeindex)
{
	return (g_MpChallenges[challengeindex].availability & 1) != 0;
}

bool mpIsChallengeAvailableToPlayer(s32 chrnum, s32 challengeindex)
{
	if ((g_MpSetup.chrslots & (1 << chrnum)) == 0) {
		return 0;
	}

	return ((g_MpChallenges[challengeindex].availability & (2 << chrnum)) != 0);
}

bool mpIsChallengeAvailableToAnyPlayer(s32 challengeindex)
{
	return (g_MpChallenges[challengeindex].availability & (((g_MpSetup.chrslots & 0xf) << 1) | 1)) != 0;
}

#if VERSION >= VERSION_NTSC_1_0
void mpDetermineUnlockedFeatures(void)
{
	s32 challengeindex;
	s32 numgifted; // number of unlocked but not completed challenges
	u8 flag;
	s32 prev;
	s32 i;
	s32 j;
	s32 k;

	// Clear all challenge availability
	for (challengeindex = 0; challengeindex < 30; challengeindex++) {
		g_MpChallenges[challengeindex].availability = 0;
	}

	numgifted = 0;

	// Mark challenges completed by any player
	for (challengeindex = 0; challengeindex < 30; challengeindex++) {
		flag = 0;

		if (mpIsChallengeCompletedByAnyPlayerWithNumPlayers(challengeindex, 1)
				|| mpIsChallengeCompletedByAnyPlayerWithNumPlayers(challengeindex, 2)
				|| mpIsChallengeCompletedByAnyPlayerWithNumPlayers(challengeindex, 3)
				|| mpIsChallengeCompletedByAnyPlayerWithNumPlayers(challengeindex, 4)) {
			// Completed challenge
			flag = 1;
		} else if (challengeindex < 4) {
			// Not yet completed, but challenges 1-4 are always available
			flag = 1;
			numgifted++;
		} else if (challengeindex > 0) {
			// Challenges are available if their previous one is complete
			prev = challengeindex - 1;

			if (mpIsChallengeCompletedByAnyPlayerWithNumPlayers(prev, 1)
					|| mpIsChallengeCompletedByAnyPlayerWithNumPlayers(prev, 2)
					|| mpIsChallengeCompletedByAnyPlayerWithNumPlayers(prev, 3)
					|| mpIsChallengeCompletedByAnyPlayerWithNumPlayers(prev, 4)) {
				flag = 1;
				numgifted++;
			}
		}

		g_MpChallenges[challengeindex].availability |= flag;
	}

	// Gift up to 4 challenges
	for (challengeindex = 0; numgifted < 4 && challengeindex < 30; challengeindex++) {
		if ((g_MpChallenges[challengeindex].availability & 1) == 0) {
			g_MpChallenges[challengeindex].availability |= 1;
			numgifted++;
		}
	}

	// Now same as above, but per player
	for (j = 0; j < 4; j++) {
		numgifted = 0;

		for (challengeindex = 0; challengeindex < 30; challengeindex++) {
			flag = 0;

			if (mpIsChallengeCompletedByPlayerWithNumPlayers(j, challengeindex, 1)
					|| mpIsChallengeCompletedByPlayerWithNumPlayers(j, challengeindex, 2)
					|| mpIsChallengeCompletedByPlayerWithNumPlayers(j, challengeindex, 3)
					|| mpIsChallengeCompletedByPlayerWithNumPlayers(j, challengeindex, 4)) {
				// Completed challenge
				flag = 2 << j;
			} else if (challengeindex < 4) {
				// Not yet completed, but challenges 1-4 are always available
				flag = 2 << j;
				numgifted++;
			} else if (challengeindex > 0) {
				// Challenges are available if their previous one is complete
				prev = challengeindex - 1;

				if (mpIsChallengeCompletedByPlayerWithNumPlayers(j, prev, 1)
						|| mpIsChallengeCompletedByPlayerWithNumPlayers(j, prev, 2)
						|| mpIsChallengeCompletedByPlayerWithNumPlayers(j, prev, 3)
						|| mpIsChallengeCompletedByPlayerWithNumPlayers(j, prev, 4)) {
					flag = 2 << j;
					numgifted++;
				}
			}

			g_MpChallenges[challengeindex].availability |= flag;
		}

		// Gift up to 4 challenges
		for (challengeindex = 0; numgifted < 4 && challengeindex < 30; challengeindex++) {
			if ((g_MpChallenges[challengeindex].availability & (2 << j)) == 0) {
				g_MpChallenges[challengeindex].availability |= 2 << j;
				numgifted++;
			}
		}
	}

	for (j = 0; j < ARRAYCOUNT(g_MpFeaturesUnlocked); j++) {
		flag = 0;

		for (challengeindex = 0; challengeindex < 30; challengeindex++) {
			if (mpIsChallengeAvailableToAnyPlayer(challengeindex)) {
				for (i = 0; i < 16; i++) {
					if (g_MpChallenges[challengeindex].unlockfeatures[i] == j) {
						flag |= 1;
					}
				}
			}
		}

		for (i = 0; i < ARRAYCOUNT(g_MpFeaturesForceUnlocked); i++) {
			if (g_MpFeaturesForceUnlocked[i] == j) {
				flag |= 1;
			}
		}

		for (challengeindex = 0; challengeindex < 30; challengeindex++) {
			for (prev = 0; prev < 4; prev++) {
				if (mpIsChallengeAvailableToPlayer(prev, challengeindex)) {
					for (i = 0; i < 16; i++) {
						if (g_MpChallenges[challengeindex].unlockfeatures[i] == j) {
							flag |= 2 << prev;
						}
					}
				}
			}
		}

		g_MpFeaturesUnlocked[j] = flag;
	}

	for (j = 0; j < func0f188bcc(); j++) {
		struct mpweapon *weapon = &g_MpWeapons[j];

		if (weapon->unlockfeature > 0 && func0f19cbcc(weapon->weaponnum)) {
			g_MpFeaturesUnlocked[weapon->unlockfeature] |= 1;
		}
	}

	func0f1895e8();

	// If the ability to have 8 simulants hasn't been unlocked, limit them to 4
	if (!mpIsFeatureUnlocked(MPFEATURE_8BOTS)) {
		for (k = 4; k < 8; k++) {
			if (g_MpSetup.chrslots & (1 << (4 + k))) {
				mpRemoveSimulant(k);
			}
		}

		if (g_Vars.mpquickteamnumsims > 4) {
			g_Vars.mpquickteamnumsims = 4;
		}
	}
}
#else
GLOBAL_ASM(
glabel mpDetermineUnlockedFeatures
/*  f19505c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f195060:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f195064:	3c118009 */ 	lui	$s1,0x8009
/*  f195068:	3c028009 */ 	lui	$v0,0x8009
/*  f19506c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f195070:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f195074:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f195078:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f19507c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f195080:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f195084:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f195088:	2442af34 */ 	addiu	$v0,$v0,-20684
/*  f19508c:	2631ac28 */ 	addiu	$s1,$s1,-21464
.NB0f195090:
/*  f195090:	2631001a */ 	addiu	$s1,$s1,0x1a
/*  f195094:	0222082b */ 	sltu	$at,$s1,$v0
/*  f195098:	1420fffd */ 	bnez	$at,.NB0f195090
/*  f19509c:	a220ffea */ 	sb	$zero,-0x16($s1)
/*  f1950a0:	3c118009 */ 	lui	$s1,0x8009
/*  f1950a4:	0000a025 */ 	or	$s4,$zero,$zero
/*  f1950a8:	2631ac28 */ 	addiu	$s1,$s1,-21464
/*  f1950ac:	0000a825 */ 	or	$s5,$zero,$zero
.NB0f1950b0:
/*  f1950b0:	00009025 */ 	or	$s2,$zero,$zero
/*  f1950b4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1950b8:	0fc65912 */ 	jal	mpIsChallengeCompletedByAnyPlayerWithNumPlayers
/*  f1950bc:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1950c0:	1440000d */ 	bnez	$v0,.NB0f1950f8
/*  f1950c4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1950c8:	0fc65912 */ 	jal	mpIsChallengeCompletedByAnyPlayerWithNumPlayers
/*  f1950cc:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f1950d0:	14400009 */ 	bnez	$v0,.NB0f1950f8
/*  f1950d4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1950d8:	0fc65912 */ 	jal	mpIsChallengeCompletedByAnyPlayerWithNumPlayers
/*  f1950dc:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f1950e0:	14400005 */ 	bnez	$v0,.NB0f1950f8
/*  f1950e4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1950e8:	0fc65912 */ 	jal	mpIsChallengeCompletedByAnyPlayerWithNumPlayers
/*  f1950ec:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f1950f0:	10400003 */ 	beqz	$v0,.NB0f195100
/*  f1950f4:	2aa10004 */ 	slti	$at,$s5,0x4
.NB0f1950f8:
/*  f1950f8:	10000021 */ 	beqz	$zero,.NB0f195180
/*  f1950fc:	24120001 */ 	addiu	$s2,$zero,0x1
.NB0f195100:
/*  f195100:	10200004 */ 	beqz	$at,.NB0f195114
/*  f195104:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195108:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f19510c:	1000001c */ 	beqz	$zero,.NB0f195180
/*  f195110:	26940001 */ 	addiu	$s4,$s4,0x1
.NB0f195114:
/*  f195114:	1aa00015 */ 	blez	$s5,.NB0f19516c
/*  f195118:	26b0ffff */ 	addiu	$s0,$s5,-1
/*  f19511c:	02002025 */ 	or	$a0,$s0,$zero
/*  f195120:	0fc65912 */ 	jal	mpIsChallengeCompletedByAnyPlayerWithNumPlayers
/*  f195124:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f195128:	1440000d */ 	bnez	$v0,.NB0f195160
/*  f19512c:	02002025 */ 	or	$a0,$s0,$zero
/*  f195130:	0fc65912 */ 	jal	mpIsChallengeCompletedByAnyPlayerWithNumPlayers
/*  f195134:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f195138:	14400009 */ 	bnez	$v0,.NB0f195160
/*  f19513c:	02002025 */ 	or	$a0,$s0,$zero
/*  f195140:	0fc65912 */ 	jal	mpIsChallengeCompletedByAnyPlayerWithNumPlayers
/*  f195144:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f195148:	14400005 */ 	bnez	$v0,.NB0f195160
/*  f19514c:	02002025 */ 	or	$a0,$s0,$zero
/*  f195150:	0fc65912 */ 	jal	mpIsChallengeCompletedByAnyPlayerWithNumPlayers
/*  f195154:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f195158:	10400004 */ 	beqz	$v0,.NB0f19516c
/*  f19515c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f195160:
/*  f195160:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f195164:	10000006 */ 	beqz	$zero,.NB0f195180
/*  f195168:	26940001 */ 	addiu	$s4,$s4,0x1
.NB0f19516c:
/*  f19516c:	0fc466d5 */ 	jal	debug0f119b54nb
/*  f195170:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195174:	50400003 */ 	beqzl	$v0,.NB0f195184
/*  f195178:	922e0004 */ 	lbu	$t6,0x4($s1)
/*  f19517c:	24120001 */ 	addiu	$s2,$zero,0x1
.NB0f195180:
/*  f195180:	922e0004 */ 	lbu	$t6,0x4($s1)
.NB0f195184:
/*  f195184:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f195188:	2aa1001e */ 	slti	$at,$s5,0x1e
/*  f19518c:	01d27825 */ 	or	$t7,$t6,$s2
/*  f195190:	2631001a */ 	addiu	$s1,$s1,0x1a
/*  f195194:	1420ffc6 */ 	bnez	$at,.NB0f1950b0
/*  f195198:	a22fffea */ 	sb	$t7,-0x16($s1)
/*  f19519c:	2a810004 */ 	slti	$at,$s4,0x4
/*  f1951a0:	10200014 */ 	beqz	$at,.NB0f1951f4
/*  f1951a4:	00009825 */ 	or	$s3,$zero,$zero
/*  f1951a8:	0000c080 */ 	sll	$t8,$zero,0x2
/*  f1951ac:	0300c023 */ 	subu	$t8,$t8,$zero
/*  f1951b0:	3c198009 */ 	lui	$t9,0x8009
/*  f1951b4:	2739ac28 */ 	addiu	$t9,$t9,-21464
/*  f1951b8:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f1951bc:	3c038009 */ 	lui	$v1,0x8009
/*  f1951c0:	2463af34 */ 	addiu	$v1,$v1,-20684
/*  f1951c4:	03198821 */ 	addu	$s1,$t8,$t9
/*  f1951c8:	92220004 */ 	lbu	$v0,0x4($s1)
.NB0f1951cc:
/*  f1951cc:	30480001 */ 	andi	$t0,$v0,0x1
/*  f1951d0:	15000003 */ 	bnez	$t0,.NB0f1951e0
/*  f1951d4:	34490001 */ 	ori	$t1,$v0,0x1
/*  f1951d8:	a2290004 */ 	sb	$t1,0x4($s1)
/*  f1951dc:	26940001 */ 	addiu	$s4,$s4,0x1
.NB0f1951e0:
/*  f1951e0:	2a810004 */ 	slti	$at,$s4,0x4
/*  f1951e4:	10200003 */ 	beqz	$at,.NB0f1951f4
/*  f1951e8:	2631001a */ 	addiu	$s1,$s1,0x1a
/*  f1951ec:	5623fff7 */ 	bnel	$s1,$v1,.NB0f1951cc
/*  f1951f0:	92220004 */ 	lbu	$v0,0x4($s1)
.NB0f1951f4:
/*  f1951f4:	3c168009 */ 	lui	$s6,0x8009
/*  f1951f8:	26d6af34 */ 	addiu	$s6,$s6,-20684
.NB0f1951fc:
/*  f1951fc:	3c118009 */ 	lui	$s1,0x8009
/*  f195200:	0000a025 */ 	or	$s4,$zero,$zero
/*  f195204:	2631ac28 */ 	addiu	$s1,$s1,-21464
/*  f195208:	0000a825 */ 	or	$s5,$zero,$zero
.NB0f19520c:
/*  f19520c:	00009025 */ 	or	$s2,$zero,$zero
/*  f195210:	02602025 */ 	or	$a0,$s3,$zero
/*  f195214:	02a02825 */ 	or	$a1,$s5,$zero
/*  f195218:	0fc6593a */ 	jal	mpIsChallengeCompletedByPlayerWithNumPlayers
/*  f19521c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f195220:	14400010 */ 	bnez	$v0,.NB0f195264
/*  f195224:	02602025 */ 	or	$a0,$s3,$zero
/*  f195228:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19522c:	0fc6593a */ 	jal	mpIsChallengeCompletedByPlayerWithNumPlayers
/*  f195230:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f195234:	1440000b */ 	bnez	$v0,.NB0f195264
/*  f195238:	02602025 */ 	or	$a0,$s3,$zero
/*  f19523c:	02a02825 */ 	or	$a1,$s5,$zero
/*  f195240:	0fc6593a */ 	jal	mpIsChallengeCompletedByPlayerWithNumPlayers
/*  f195244:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f195248:	14400006 */ 	bnez	$v0,.NB0f195264
/*  f19524c:	02602025 */ 	or	$a0,$s3,$zero
/*  f195250:	02a02825 */ 	or	$a1,$s5,$zero
/*  f195254:	0fc6593a */ 	jal	mpIsChallengeCompletedByPlayerWithNumPlayers
/*  f195258:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f19525c:	10400006 */ 	beqz	$v0,.NB0f195278
/*  f195260:	2aa10004 */ 	slti	$at,$s5,0x4
.NB0f195264:
/*  f195264:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f195268:	026a9004 */ 	sllv	$s2,$t2,$s3
/*  f19526c:	324b00ff */ 	andi	$t3,$s2,0xff
/*  f195270:	10000023 */ 	beqz	$zero,.NB0f195300
/*  f195274:	01609025 */ 	or	$s2,$t3,$zero
.NB0f195278:
/*  f195278:	10200006 */ 	beqz	$at,.NB0f195294
/*  f19527c:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f195280:	026c9004 */ 	sllv	$s2,$t4,$s3
/*  f195284:	324d00ff */ 	andi	$t5,$s2,0xff
/*  f195288:	01a09025 */ 	or	$s2,$t5,$zero
/*  f19528c:	1000001c */ 	beqz	$zero,.NB0f195300
/*  f195290:	26940001 */ 	addiu	$s4,$s4,0x1
.NB0f195294:
/*  f195294:	1aa0001a */ 	blez	$s5,.NB0f195300
/*  f195298:	02602025 */ 	or	$a0,$s3,$zero
/*  f19529c:	26b0ffff */ 	addiu	$s0,$s5,-1
/*  f1952a0:	02002825 */ 	or	$a1,$s0,$zero
/*  f1952a4:	0fc6593a */ 	jal	mpIsChallengeCompletedByPlayerWithNumPlayers
/*  f1952a8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1952ac:	1440000f */ 	bnez	$v0,.NB0f1952ec
/*  f1952b0:	02602025 */ 	or	$a0,$s3,$zero
/*  f1952b4:	02002825 */ 	or	$a1,$s0,$zero
/*  f1952b8:	0fc6593a */ 	jal	mpIsChallengeCompletedByPlayerWithNumPlayers
/*  f1952bc:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f1952c0:	1440000a */ 	bnez	$v0,.NB0f1952ec
/*  f1952c4:	02602025 */ 	or	$a0,$s3,$zero
/*  f1952c8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1952cc:	0fc6593a */ 	jal	mpIsChallengeCompletedByPlayerWithNumPlayers
/*  f1952d0:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f1952d4:	14400005 */ 	bnez	$v0,.NB0f1952ec
/*  f1952d8:	02602025 */ 	or	$a0,$s3,$zero
/*  f1952dc:	02002825 */ 	or	$a1,$s0,$zero
/*  f1952e0:	0fc6593a */ 	jal	mpIsChallengeCompletedByPlayerWithNumPlayers
/*  f1952e4:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f1952e8:	10400005 */ 	beqz	$v0,.NB0f195300
.NB0f1952ec:
/*  f1952ec:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f1952f0:	026e9004 */ 	sllv	$s2,$t6,$s3
/*  f1952f4:	324f00ff */ 	andi	$t7,$s2,0xff
/*  f1952f8:	01e09025 */ 	or	$s2,$t7,$zero
/*  f1952fc:	26940001 */ 	addiu	$s4,$s4,0x1
.NB0f195300:
/*  f195300:	92380004 */ 	lbu	$t8,0x4($s1)
/*  f195304:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f195308:	2aa1001e */ 	slti	$at,$s5,0x1e
/*  f19530c:	0312c825 */ 	or	$t9,$t8,$s2
/*  f195310:	2631001a */ 	addiu	$s1,$s1,0x1a
/*  f195314:	1420ffbd */ 	bnez	$at,.NB0f19520c
/*  f195318:	a239ffea */ 	sb	$t9,-0x16($s1)
/*  f19531c:	2a810004 */ 	slti	$at,$s4,0x4
/*  f195320:	10200013 */ 	beqz	$at,.NB0f195370
/*  f195324:	00004080 */ 	sll	$t0,$zero,0x2
/*  f195328:	01004023 */ 	subu	$t0,$t0,$zero
/*  f19532c:	3c098009 */ 	lui	$t1,0x8009
/*  f195330:	2529ac28 */ 	addiu	$t1,$t1,-21464
/*  f195334:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f195338:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f19533c:	026a1804 */ 	sllv	$v1,$t2,$s3
/*  f195340:	01098821 */ 	addu	$s1,$t0,$t1
/*  f195344:	92220004 */ 	lbu	$v0,0x4($s1)
.NB0f195348:
/*  f195348:	00435824 */ 	and	$t3,$v0,$v1
/*  f19534c:	15600003 */ 	bnez	$t3,.NB0f19535c
/*  f195350:	00436025 */ 	or	$t4,$v0,$v1
/*  f195354:	a22c0004 */ 	sb	$t4,0x4($s1)
/*  f195358:	26940001 */ 	addiu	$s4,$s4,0x1
.NB0f19535c:
/*  f19535c:	2a810004 */ 	slti	$at,$s4,0x4
/*  f195360:	10200003 */ 	beqz	$at,.NB0f195370
/*  f195364:	2631001a */ 	addiu	$s1,$s1,0x1a
/*  f195368:	5636fff7 */ 	bnel	$s1,$s6,.NB0f195348
/*  f19536c:	92220004 */ 	lbu	$v0,0x4($s1)
.NB0f195370:
/*  f195370:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f195374:	2a610004 */ 	slti	$at,$s3,0x4
/*  f195378:	1420ffa0 */ 	bnez	$at,.NB0f1951fc
/*  f19537c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195380:	3c14800b */ 	lui	$s4,0x800b
/*  f195384:	3c16800b */ 	lui	$s6,0x800b
/*  f195388:	26d61578 */ 	addiu	$s6,$s6,0x1578
/*  f19538c:	26941578 */ 	addiu	$s4,$s4,0x1578
/*  f195390:	00009825 */ 	or	$s3,$zero,$zero
/*  f195394:	24110010 */ 	addiu	$s1,$zero,0x10
.NB0f195398:
/*  f195398:	00009025 */ 	or	$s2,$zero,$zero
/*  f19539c:	0000a825 */ 	or	$s5,$zero,$zero
.NB0f1953a0:
/*  f1953a0:	0fc65406 */ 	jal	mpIsChallengeAvailableToAnyPlayer
/*  f1953a4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1953a8:	10400011 */ 	beqz	$v0,.NB0f1953f0
/*  f1953ac:	00156880 */ 	sll	$t5,$s5,0x2
/*  f1953b0:	01b56823 */ 	subu	$t5,$t5,$s5
/*  f1953b4:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f1953b8:	01b56821 */ 	addu	$t5,$t5,$s5
/*  f1953bc:	3c0e8009 */ 	lui	$t6,0x8009
/*  f1953c0:	25ceac28 */ 	addiu	$t6,$t6,-21464
/*  f1953c4:	000d6840 */ 	sll	$t5,$t5,0x1
/*  f1953c8:	01ae1821 */ 	addu	$v1,$t5,$t6
/*  f1953cc:	00001025 */ 	or	$v0,$zero,$zero
.NB0f1953d0:
/*  f1953d0:	906f0009 */ 	lbu	$t7,0x9($v1)
/*  f1953d4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1953d8:	36580001 */ 	ori	$t8,$s2,0x1
/*  f1953dc:	166f0002 */ 	bne	$s3,$t7,.NB0f1953e8
/*  f1953e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1953e4:	331200ff */ 	andi	$s2,$t8,0xff
.NB0f1953e8:
/*  f1953e8:	1451fff9 */ 	bne	$v0,$s1,.NB0f1953d0
/*  f1953ec:	24630001 */ 	addiu	$v1,$v1,0x1
.NB0f1953f0:
/*  f1953f0:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f1953f4:	2aa1001e */ 	slti	$at,$s5,0x1e
/*  f1953f8:	1420ffe9 */ 	bnez	$at,.NB0f1953a0
/*  f1953fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195400:	3c03800b */ 	lui	$v1,0x800b
/*  f195404:	24631550 */ 	addiu	$v1,$v1,0x1550
/*  f195408:	90680000 */ 	lbu	$t0,0x0($v1)
.NB0f19540c:
/*  f19540c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f195410:	36490001 */ 	ori	$t1,$s2,0x1
/*  f195414:	16680002 */ 	bne	$s3,$t0,.NB0f195420
/*  f195418:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19541c:	313200ff */ 	andi	$s2,$t1,0xff
.NB0f195420:
/*  f195420:	5476fffa */ 	bnel	$v1,$s6,.NB0f19540c
/*  f195424:	90680000 */ 	lbu	$t0,0x0($v1)
/*  f195428:	0000a825 */ 	or	$s5,$zero,$zero
/*  f19542c:	00008025 */ 	or	$s0,$zero,$zero
.NB0f195430:
/*  f195430:	02002025 */ 	or	$a0,$s0,$zero
.NB0f195434:
/*  f195434:	0fc653ef */ 	jal	mpIsChallengeAvailableToPlayer
/*  f195438:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19543c:	10400013 */ 	beqz	$v0,.NB0f19548c
/*  f195440:	00155880 */ 	sll	$t3,$s5,0x2
/*  f195444:	01755823 */ 	subu	$t3,$t3,$s5
/*  f195448:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f19544c:	01755821 */ 	addu	$t3,$t3,$s5
/*  f195450:	3c0c8009 */ 	lui	$t4,0x8009
/*  f195454:	258cac28 */ 	addiu	$t4,$t4,-21464
/*  f195458:	000b5840 */ 	sll	$t3,$t3,0x1
/*  f19545c:	016c1821 */ 	addu	$v1,$t3,$t4
/*  f195460:	00001025 */ 	or	$v0,$zero,$zero
.NB0f195464:
/*  f195464:	906d0009 */ 	lbu	$t5,0x9($v1)
/*  f195468:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f19546c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f195470:	166d0004 */ 	bne	$s3,$t5,.NB0f195484
/*  f195474:	020e7804 */ 	sllv	$t7,$t6,$s0
/*  f195478:	024f9025 */ 	or	$s2,$s2,$t7
/*  f19547c:	325800ff */ 	andi	$t8,$s2,0xff
/*  f195480:	03009025 */ 	or	$s2,$t8,$zero
.NB0f195484:
/*  f195484:	1451fff7 */ 	bne	$v0,$s1,.NB0f195464
/*  f195488:	24630001 */ 	addiu	$v1,$v1,0x1
.NB0f19548c:
/*  f19548c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f195490:	2a010004 */ 	slti	$at,$s0,0x4
/*  f195494:	5420ffe7 */ 	bnezl	$at,.NB0f195434
/*  f195498:	02002025 */ 	or	$a0,$s0,$zero
/*  f19549c:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f1954a0:	2aa1001e */ 	slti	$at,$s5,0x1e
/*  f1954a4:	5420ffe2 */ 	bnezl	$at,.NB0f195430
/*  f1954a8:	00008025 */ 	or	$s0,$zero,$zero
/*  f1954ac:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f1954b0:	2a610050 */ 	slti	$at,$s3,0x50
/*  f1954b4:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f1954b8:	1420ffb7 */ 	bnez	$at,.NB0f195398
/*  f1954bc:	a292ffff */ 	sb	$s2,-0x1($s4)
/*  f1954c0:	0fc60bef */ 	jal	func0f188bcc
/*  f1954c4:	00009825 */ 	or	$s3,$zero,$zero
/*  f1954c8:	1840001c */ 	blez	$v0,.NB0f19553c
/*  f1954cc:	0013c880 */ 	sll	$t9,$s3,0x2
/*  f1954d0:	0333c821 */ 	addu	$t9,$t9,$s3
/*  f1954d4:	3c088009 */ 	lui	$t0,0x8009
/*  f1954d8:	250899e8 */ 	addiu	$t0,$t0,-26136
/*  f1954dc:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f1954e0:	3c11800b */ 	lui	$s1,0x800b
/*  f1954e4:	26311578 */ 	addiu	$s1,$s1,0x1578
/*  f1954e8:	03288021 */ 	addu	$s0,$t9,$t0
/*  f1954ec:	96090004 */ 	lhu	$t1,0x4($s0)
.NB0f1954f0:
/*  f1954f0:	312a007f */ 	andi	$t2,$t1,0x7f
/*  f1954f4:	5940000c */ 	blezl	$t2,.NB0f195528
/*  f1954f8:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f1954fc:	0fc65b06 */ 	jal	func0f19cbcc
/*  f195500:	92040000 */ 	lbu	$a0,0x0($s0)
/*  f195504:	50400008 */ 	beqzl	$v0,.NB0f195528
/*  f195508:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f19550c:	960b0004 */ 	lhu	$t3,0x4($s0)
/*  f195510:	316c007f */ 	andi	$t4,$t3,0x7f
/*  f195514:	022c1021 */ 	addu	$v0,$s1,$t4
/*  f195518:	904d0000 */ 	lbu	$t5,0x0($v0)
/*  f19551c:	35ae0001 */ 	ori	$t6,$t5,0x1
/*  f195520:	a04e0000 */ 	sb	$t6,0x0($v0)
/*  f195524:	26730001 */ 	addiu	$s3,$s3,0x1
.NB0f195528:
/*  f195528:	0fc60bef */ 	jal	func0f188bcc
/*  f19552c:	2610000a */ 	addiu	$s0,$s0,0xa
/*  f195530:	0262082a */ 	slt	$at,$s3,$v0
/*  f195534:	5420ffee */ 	bnezl	$at,.NB0f1954f0
/*  f195538:	96090004 */ 	lhu	$t1,0x4($s0)
.NB0f19553c:
/*  f19553c:	0fc60e76 */ 	jal	func0f1895e8
/*  f195540:	00000000 */ 	sll	$zero,$zero,0x0
/*  f195544:	0fc65a5e */ 	jal	mpIsFeatureUnlocked
/*  f195548:	24040040 */ 	addiu	$a0,$zero,0x40
/*  f19554c:	14400018 */ 	bnez	$v0,.NB0f1955b0
/*  f195550:	24100004 */ 	addiu	$s0,$zero,0x4
/*  f195554:	3c11800b */ 	lui	$s1,0x800b
/*  f195558:	26311438 */ 	addiu	$s1,$s1,0x1438
/*  f19555c:	24120008 */ 	addiu	$s2,$zero,0x8
/*  f195560:	962f0016 */ 	lhu	$t7,0x16($s1)
.NB0f195564:
/*  f195564:	26180004 */ 	addiu	$t8,$s0,0x4
/*  f195568:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f19556c:	03194004 */ 	sllv	$t0,$t9,$t8
/*  f195570:	01e84824 */ 	and	$t1,$t7,$t0
/*  f195574:	51200004 */ 	beqzl	$t1,.NB0f195588
/*  f195578:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19557c:	0fc61b80 */ 	jal	mpRemoveSimulant
/*  f195580:	02002025 */ 	or	$a0,$s0,$zero
/*  f195584:	26100001 */ 	addiu	$s0,$s0,0x1
.NB0f195588:
/*  f195588:	5612fff6 */ 	bnel	$s0,$s2,.NB0f195564
/*  f19558c:	962f0016 */ 	lhu	$t7,0x16($s1)
/*  f195590:	3c02800a */ 	lui	$v0,0x800a
/*  f195594:	2442e6c0 */ 	addiu	$v0,$v0,-6464
/*  f195598:	8c4a04a4 */ 	lw	$t2,0x4a4($v0)
/*  f19559c:	240b0004 */ 	addiu	$t3,$zero,0x4
/*  f1955a0:	29410005 */ 	slti	$at,$t2,0x5
/*  f1955a4:	54200003 */ 	bnezl	$at,.NB0f1955b4
/*  f1955a8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1955ac:	ac4b04a4 */ 	sw	$t3,0x4a4($v0)
.NB0f1955b0:
/*  f1955b0:	8fbf0034 */ 	lw	$ra,0x34($sp)
.NB0f1955b4:
/*  f1955b4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1955b8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1955bc:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1955c0:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f1955c4:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f1955c8:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f1955cc:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f1955d0:	03e00008 */ 	jr	$ra
/*  f1955d4:	27bd0038 */ 	addiu	$sp,$sp,0x38
);
#endif

void mpPerformSanityChecks(void)
{
	if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
		s32 numplayers = 0;
		s32 i;

		// Reset player handicaps
		for (i = 0; i < 4; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				g_MpPlayers[i].handicap = 0x80;
				numplayers++;
			}
		}

		// Turn off all simulants and turn them on if enabled
		// for this number of players
		g_MpSetup.chrslots &= 0x000f;

		for (i = 0; i != MAX_SIMULANTS; i++) {
			g_MpSimulants[i].difficulty = g_MpSimulantDifficultiesPerNumPlayers[i * 4 + numplayers - 1];

			if (g_MpSimulants[i].difficulty != SIMDIFF_DISABLED) {
				g_MpSetup.chrslots |= 1 << (i + 4);
			}
		}

		if (g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL) {
			g_Vars.mphilltime = 10;
		}
	} else if (!mpIsFeatureUnlocked(MPFEATURE_8BOTS)) {
		// Limit to 4 players and 4 simulants
		g_MpSetup.chrslots &= 0x00ff;
	}
}

s32 mpGetNumAvailableChallenges(void)
{
	s32 challengeindex;
	s32 count = 0;

	for (challengeindex = 0; challengeindex != NUM_CHALLENGES; challengeindex++) {
		if (mpIsChallengeAvailableToAnyPlayer(challengeindex)) {
			count++;
		}
	}

	return count;
}

char *mpChallengeGetName(s32 challengeindex)
{
	return langGet(g_MpChallenges[challengeindex].name);
}

char *mpGetChallengeNameBySlot(s32 slot)
{
	s32 index = 0;
	s32 i;

	for (i = 0; i < 30; i++) {
		if (mpIsChallengeAvailableToAnyPlayer(i)) {
			if (index == slot) {
				return mpChallengeGetName(i);
			}

			index++;
		}
	}

	return "";
}

void mpSetCurrentChallenge(s32 slotnum)
{
	s32 challengeindex;
	g_MpChallengeIndex = 0;

	for (challengeindex = 0; challengeindex != NUM_CHALLENGES; challengeindex++) {
		if (mpIsChallengeAvailableToAnyPlayer(challengeindex)) {
			if (slotnum == 0) {
				g_MpChallengeIndex = challengeindex;
				break;
			}

			slotnum--;
		}
	}

	func0f19c1cc();
}

s32 mpGetCurrentChallengeIndex(void)
{
	return g_MpChallengeIndex;
}

bool mpIsChallengeCompletedByAnyChrWithNumPlayersBySlot(s32 slot, s32 numplayers)
{
	s32 availableindex = 0;
	s32 i;

	for (i = 0; i < 30; i++) {
		if (mpIsChallengeAvailableToAnyPlayer(i)) {
			if (availableindex == slot) {
				return mpIsChallengeCompletedByAnyPlayerWithNumPlayers(i, numplayers);
			}

			availableindex++;
		}
	}

	return false;
}

bool mpIsChallengeCompletedByChrWithNumPlayersBySlot(s32 mpchrnum, s32 slot, s32 numplayers)
{
	s32 availableindex = 0;
	s32 i;

	for (i = 0; i < 30; i++) {
		if (mpIsChallengeAvailableToAnyPlayer(i)) {
			if (availableindex == slot) {
				return mpIsChallengeCompletedByPlayerWithNumPlayers(mpchrnum, i, numplayers);
			}

			availableindex++;
		}
	}

	return false;
}

extern u32 _mpstringsESegmentRomStart;
extern u32 _mpstringsJSegmentRomStart;
extern u32 _mpstringsPSegmentRomStart;
extern u32 _mpstringsGSegmentRomStart;
extern u32 _mpstringsFSegmentRomStart;
extern u32 _mpstringsSSegmentRomStart;
extern u32 _mpstringsISegmentRomStart;
extern u32 _mpstringsESegmentRomEnd;
extern u32 _mpstringsJSegmentRomEnd;
extern u32 _mpstringsPSegmentRomEnd;
extern u32 _mpstringsGSegmentRomEnd;
extern u32 _mpstringsFSegmentRomEnd;
extern u32 _mpstringsSSegmentRomEnd;
extern u32 _mpstringsISegmentRomEnd;

u32 *var800887c4 = &_mpstringsESegmentRomStart;
u32 *var800887c8 = &_mpstringsESegmentRomEnd;
u32 *var800887cc = &_mpstringsJSegmentRomStart;
u32 *var800887d0 = &_mpstringsJSegmentRomEnd;
u32 *var800887d4 = &_mpstringsPSegmentRomStart;
u32 *var800887d8 = &_mpstringsPSegmentRomEnd;
u32 *var800887dc = &_mpstringsGSegmentRomStart;
u32 *var800887e0 = &_mpstringsGSegmentRomEnd;
u32 *var800887e4 = &_mpstringsFSegmentRomStart;
u32 *var800887e8 = &_mpstringsFSegmentRomEnd;
u32 *var800887ec = &_mpstringsSSegmentRomStart;
u32 *var800887f0 = &_mpstringsSSegmentRomEnd;
u32 *var800887f4 = &_mpstringsISegmentRomStart;
u32 *var800887f8 = &_mpstringsISegmentRomEnd;

GLOBAL_ASM(
glabel mpLoadConfig
/*  f19b914:	27bdfe38 */ 	addiu	$sp,$sp,-456
/*  f19b918:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19b91c:	afa401c8 */ 	sw	$a0,0x1c8($sp)
/*  f19b920:	afa501cc */ 	sw	$a1,0x1cc($sp)
/*  f19b924:	0fc5b9b5 */ 	jal	langGetFileNumOffset
/*  f19b928:	afa601d0 */ 	sw	$a2,0x1d0($sp)
/*  f19b92c:	3c0f8009 */ 	lui	$t7,%hi(var800887c4)
/*  f19b930:	25ef87c4 */ 	addiu	$t7,$t7,%lo(var800887c4)
/*  f19b934:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f19b938:	25e80030 */ 	addiu	$t0,$t7,0x30
/*  f19b93c:	27ae0018 */ 	addiu	$t6,$sp,0x18
.L0f19b940:
/*  f19b940:	8de10000 */ 	lw	$at,0x0($t7)
/*  f19b944:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f19b948:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f19b94c:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f19b950:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f19b954:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f19b958:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f19b95c:	15e8fff8 */ 	bne	$t7,$t0,.L0f19b940
/*  f19b960:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f19b964:	8de10000 */ 	lw	$at,0x0($t7)
/*  f19b968:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f19b96c:	3c0b007d */ 	lui	$t3,%hi(_mpconfigsSegmentRomStart)
/*  f19b970:	adc10000 */ 	sw	$at,0x0($t6)
/*  f19b974:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f19b978:	8fa901c8 */ 	lw	$t1,0x1c8($sp)
/*  f19b97c:	256b0a40 */ 	addiu	$t3,$t3,%lo(_mpconfigsSegmentRomStart)
/*  f19b980:	8fa401cc */ 	lw	$a0,0x1cc($sp)
/*  f19b984:	00095080 */ 	sll	$t2,$t1,0x2
/*  f19b988:	01495023 */ 	subu	$t2,$t2,$t1
/*  f19b98c:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f19b990:	01495021 */ 	addu	$t2,$t2,$t1
/*  f19b994:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f19b998:	014b2821 */ 	addu	$a1,$t2,$t3
/*  f19b99c:	0c003522 */ 	jal	dmaExecWithAutoAlign
/*  f19b9a0:	24060068 */ 	addiu	$a2,$zero,0x68
/*  f19b9a4:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f19b9a8:	8fb901c8 */ 	lw	$t9,0x1c8($sp)
/*  f19b9ac:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f19b9b0:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f19b9b4:	03ad1821 */ 	addu	$v1,$sp,$t5
/*  f19b9b8:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f19b9bc:	8c630018 */ 	lw	$v1,0x18($v1)
/*  f19b9c0:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f19b9c4:	0018c180 */ 	sll	$t8,$t8,0x6
/*  f19b9c8:	afa201c4 */ 	sw	$v0,0x1c4($sp)
/*  f19b9cc:	24060140 */ 	addiu	$a2,$zero,0x140
/*  f19b9d0:	0c003522 */ 	jal	dmaExecWithAutoAlign
/*  f19b9d4:	00782821 */ 	addu	$a1,$v1,$t8
/*  f19b9d8:	8fa701c4 */ 	lw	$a3,0x1c4($sp)
/*  f19b9dc:	00404825 */ 	or	$t1,$v0,$zero
/*  f19b9e0:	244e0138 */ 	addiu	$t6,$v0,0x138
/*  f19b9e4:	00e05025 */ 	or	$t2,$a3,$zero
.L0f19b9e8:
/*  f19b9e8:	89210000 */ 	lwl	$at,0x0($t1)
/*  f19b9ec:	99210003 */ 	lwr	$at,0x3($t1)
/*  f19b9f0:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f19b9f4:	254a000c */ 	addiu	$t2,$t2,0xc
/*  f19b9f8:	a941005c */ 	swl	$at,0x5c($t2)
/*  f19b9fc:	b941005f */ 	swr	$at,0x5f($t2)
/*  f19ba00:	8921fff8 */ 	lwl	$at,-0x8($t1)
/*  f19ba04:	9921fffb */ 	lwr	$at,-0x5($t1)
/*  f19ba08:	a9410060 */ 	swl	$at,0x60($t2)
/*  f19ba0c:	b9410063 */ 	swr	$at,0x63($t2)
/*  f19ba10:	8921fffc */ 	lwl	$at,-0x4($t1)
/*  f19ba14:	9921ffff */ 	lwr	$at,-0x1($t1)
/*  f19ba18:	a9410064 */ 	swl	$at,0x64($t2)
/*  f19ba1c:	152efff2 */ 	bne	$t1,$t6,.L0f19b9e8
/*  f19ba20:	b9410067 */ 	swr	$at,0x67($t2)
/*  f19ba24:	89210000 */ 	lwl	$at,0x0($t1)
/*  f19ba28:	99210003 */ 	lwr	$at,0x3($t1)
/*  f19ba2c:	00e01025 */ 	or	$v0,$a3,$zero
/*  f19ba30:	a9410068 */ 	swl	$at,0x68($t2)
/*  f19ba34:	b941006b */ 	swr	$at,0x6b($t2)
/*  f19ba38:	892e0004 */ 	lwl	$t6,0x4($t1)
/*  f19ba3c:	992e0007 */ 	lwr	$t6,0x7($t1)
/*  f19ba40:	a94e006c */ 	swl	$t6,0x6c($t2)
/*  f19ba44:	b94e006f */ 	swr	$t6,0x6f($t2)
/*  f19ba48:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19ba4c:	27bd01c8 */ 	addiu	$sp,$sp,0x1c8
/*  f19ba50:	03e00008 */ 	jr	$ra
/*  f19ba54:	00000000 */ 	nop
);

// Mismatch because the arguments to an addu instruction are swapped.
// It's the addu for calculating &bank[confignum].
//struct mpconfigfull *mpLoadConfig(s32 confignum, u8 *buffer, s32 len)
//{
//	struct mpconfigfull *mpconfig;
//	u8 buffer2[sizeof(struct mpstrings) + 40];
//	struct mpstrings *loadedstrings;
//	struct mpstrings *bank;
//	u32 language_id = langGetFileNumOffset();
//	extern struct mpconfig _mpconfigsSegmentRomStart[];
//	extern struct mpstrings _mpstringsESegmentRomStart;
//	extern struct mpstrings _mpstringsJSegmentRomStart;
//	extern struct mpstrings _mpstringsPSegmentRomStart;
//	extern struct mpstrings _mpstringsGSegmentRomStart;
//	extern struct mpstrings _mpstringsFSegmentRomStart;
//	extern struct mpstrings _mpstringsSSegmentRomStart;
//	extern struct mpstrings _mpstringsISegmentRomStart;
//	extern struct mpstrings _mpstringsESegmentRomEnd;
//	extern struct mpstrings _mpstringsJSegmentRomEnd;
//	extern struct mpstrings _mpstringsPSegmentRomEnd;
//	extern struct mpstrings _mpstringsGSegmentRomEnd;
//	extern struct mpstrings _mpstringsFSegmentRomEnd;
//	extern struct mpstrings _mpstringsSSegmentRomEnd;
//	extern struct mpstrings _mpstringsISegmentRomEnd;
//
//	struct mpstrings *banks[][2] = {
//		{ &_mpstringsESegmentRomStart, &_mpstringsESegmentRomEnd },
//		{ &_mpstringsJSegmentRomStart, &_mpstringsJSegmentRomEnd },
//		{ &_mpstringsPSegmentRomStart, &_mpstringsPSegmentRomEnd },
//		{ &_mpstringsGSegmentRomStart, &_mpstringsGSegmentRomEnd },
//		{ &_mpstringsFSegmentRomStart, &_mpstringsFSegmentRomEnd },
//		{ &_mpstringsSSegmentRomStart, &_mpstringsSSegmentRomEnd },
//		{ &_mpstringsISegmentRomStart, &_mpstringsISegmentRomEnd },
//	};
//
//	// Load mpconfigs
//	mpconfig = dmaExecWithAutoAlign(buffer, &_mpconfigsSegmentRomStart[confignum], sizeof(struct mpconfig));
//
//	// Load mpstrings
//	bank = banks[language_id][0];
//	loadedstrings = dmaExecWithAutoAlign(buffer2, &bank[confignum], sizeof(struct mpstrings));
//
//	mpconfig->strings = *loadedstrings;
//
//	return mpconfig;
//}

struct mpconfigfull *mpLoadChallenge(s32 challengeindex, u8 *buffer, s32 len)
{
	return mpLoadConfig(g_MpChallenges[challengeindex].confignum, buffer, len);
}

struct mpconfigfull *mpGetNthAvailableChallengeSomething(s32 n, u8 *buffer, s32 len)
{
	s32 numavailable = 0;
	s32 challengeindex;

	for (challengeindex = 0; challengeindex != NUM_CHALLENGES; challengeindex++) {
		if (mpIsChallengeAvailableToAnyPlayer(challengeindex)) {
			if (numavailable == n) {
				return mpLoadChallenge(challengeindex, buffer, len);
			}

			numavailable++;
		}
	}

	return 0;
}

struct mpconfigfull *mpLoadCurrentChallenge(u8 *buffer, s32 len)
{
	return mpLoadChallenge(g_MpChallengeIndex, buffer, len);
}

/**
 * This is adding featurenum to the array, provided it's unique.
 */
s32 mpForceUnlockFeature(s32 featurenum, u8 *array, s32 tail, s32 len)
{
	s32 i;

	for (i = 0; i < tail; i++) {
		if (array[i] == featurenum) {
			break;
		}
	}

	if (i >= tail && tail < len) {
		array[tail] = featurenum;
		tail++;
	}

	return tail;
}

s32 mpForceUnlockSetupFeatures(struct mpsetup *setup, u8 *array, s32 len)
{
	s32 index = 0;
	s32 i;

	// Force unlock the weapons (if never held before)
	for (i = 0; i < 6; i++) {
		s32 featurenum = g_MpWeapons[setup->weapons[i]].unlockfeature;

		if (featurenum) {
			index = mpForceUnlockFeature(featurenum, array, index, len);
		}
	}

	// Force unlock the stage
	for (i = 0; i < mpGetNumStages(); i++) {
		if (g_MpArenas[i].stagenum == setup->stagenum) {
			s32 featurenum = g_MpArenas[i].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, array, index, len);
			}
		}
	}

	// Force unlock the scenario
	if (setup->scenario <= MPSCENARIO_CAPTURETHECASE) {
		s32 featurenum = g_MpScenarioOverviews[setup->scenario].unlockfeature;

		if (featurenum) {
			index = mpForceUnlockFeature(featurenum, array, index, len);
		}
	}

	// Force unlock the scenario options
	if (setup->options & MPOPTION_ONEHITKILLS) {
		index = mpForceUnlockFeature(MPFEATURE_ONEHITKILLS, array, index, len);
	}

	if (setup->options & (MPOPTION_SLOWMOTION_ON | MPOPTION_SLOWMOTION_SMART)) {
		index = mpForceUnlockFeature(MPFEATURE_SLOWMOTION, array, index, len);
	}

	return index;
}

void mpForceUnlockConfigFeatures(struct mpconfig *config, u8 *array, s32 len, s32 challengeindex)
{
	s32 index = mpForceUnlockSetupFeatures(&config->setup, array, len);
	s32 featurenum;
	s32 numplayers;
	s32 i;

	for (i = 0; i < 8; i++) {
		s32 simtype = mpGetSimTypeIndex(config->simulants[i].type, SIMDIFF_NORMAL);

		if (simtype >= 0) {
			featurenum = g_MpSimulantTypes[simtype].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, array, index, len);
			}
		}

		for (numplayers = 0; numplayers < 4; numplayers++) {
			simtype = mpGetSimTypeIndex(0, config->simulants[i].difficulties[numplayers]);

			if (simtype >= 0) {
				featurenum = g_MpSimulantTypes[simtype].requirefeature;

				if (featurenum) {
					index = mpForceUnlockFeature(featurenum, array, index, len);
				}
			}
		}

		if (config->simulants[i].mpbodynum <= MPBODY_DJBOND) {
			featurenum = g_MpBodies[config->simulants[i].mpbodynum].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, array, index, len);
			}
		}

		if (config->simulants[i].mpheadnum <= MPHEAD_WINNER) {
			featurenum = g_MpHeads[config->simulants[i].mpheadnum].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, array, index, len);
			}
		}
	}

#if VERSION >= VERSION_NTSC_1_0
	if (challengeindex >= 25) {
		index = mpForceUnlockFeature(MPFEATURE_SIMDIFF_DARK, array, index, len);
	} else if (challengeindex >= 20) {
		index = mpForceUnlockFeature(MPFEATURE_STAGE_CARPARK, array, index, len);
	} else if (challengeindex >= 15) {
		index = mpForceUnlockFeature(MPFEATURE_4D, array, index, len);
	}

	if (challengeindex >= 10) {
		index = mpForceUnlockFeature(MPFEATURE_8BOTS, array, index, len);
	}
#else
	if (challengeindex >= 10) {
		index = mpForceUnlockFeature(MPFEATURE_8BOTS, array, index, len);
	}

	if (challengeindex >= 15) {
		index = mpForceUnlockFeature(MPFEATURE_4D, array, index, len);
	}

	if (challengeindex >= 20) {
		index = mpForceUnlockFeature(MPFEATURE_STAGE_CARPARK, array, index, len);
	}
#endif

	// Clear the remainder of the array
	for (i = index; i < len; i++) {
		array[i] = 0;
	}
}

void mpForceUnlockSimulantFeatures(void)
{
	s32 numsims = 0;
	s32 index = mpForceUnlockSetupFeatures(&g_MpSetup, g_MpFeaturesForceUnlocked, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
	s32 i;

	for (i = 0; i < 8; i++) {
		// Force unlock the simulant type
		s32 simtypeindex = mpGetSimTypeIndex(g_MpSimulants[i].base.simtype, SIMDIFF_NORMAL);

		if (simtypeindex >= 0) {
			s32 featurenum = g_MpSimulantTypes[simtypeindex].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, g_MpFeaturesForceUnlocked, index, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
			}
		}

		// Force unlock the simulant difficulty
		simtypeindex = mpGetSimTypeIndex(SIMTYPE_GENERAL, g_MpSimulants[i].difficulty);

		if (simtypeindex >= 0) {
			s32 featurenum = g_MpSimulantTypes[simtypeindex].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, g_MpFeaturesForceUnlocked, index, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
			}
		}

		if (simtypeindex >= 0) {
			numsims++;
		}

		// Force unlock the simulant's body
		if (g_MpSimulants[i].base.mpbodynum < ARRAYCOUNT(g_MpBodies)) {
			s32 featurenum = g_MpBodies[g_MpSimulants[i].base.mpbodynum].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, g_MpFeaturesForceUnlocked, index, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
			}
		}

		// Force unlock the simulant's head
		if (g_MpSimulants[i].base.mpheadnum < ARRAYCOUNT(g_MpHeads)) {
			s32 featurenum = g_MpHeads[g_MpSimulants[i].base.mpheadnum].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, g_MpFeaturesForceUnlocked, index, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
			}
		}
	}

	// Force unlock 8 simulants
	if (numsims > 4) {
		index = mpForceUnlockFeature(MPFEATURE_8BOTS, g_MpFeaturesForceUnlocked, index, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
	}

	// Clear the remainder of the array
	for (i = index; i < ARRAYCOUNT(g_MpFeaturesForceUnlocked); i++) {
		g_MpFeaturesForceUnlocked[i] = 0;
	}

	mpDetermineUnlockedFeatures();
}

void func0f19c190(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_MpFeaturesForceUnlocked); i++) {
		g_MpFeaturesForceUnlocked[i] = 0;
	}

	mpDetermineUnlockedFeatures();
}

void func0f19c1cc(void)
{
	s32 i;
	u8 buffer[458];

	func0f18dcec(mpLoadCurrentChallenge(buffer, 458));
	mpSetLock(MPLOCKTYPE_CHALLENGE, 5);

	for (i = 0; i < 4; i++) {
		g_MpPlayers[i].base.team = 0;
	}
}

s32 mpRemoveLock(void)
{
	return mpSetLock(MPLOCKTYPE_NONE, 0);
}

void mpLoadAndStoreCurrentChallenge(u8 *buffer, s32 len)
{
	g_MpCurrentChallengeConfig = mpLoadCurrentChallenge(buffer, len);
}

void mpClearCurrentChallenge(void)
{
	g_MpCurrentChallengeConfig = NULL;
}

bool mpIsChallengeLoaded(void)
{
	return g_MpCurrentChallengeConfig != NULL;
}

char *mpGetCurrentChallengeDescription(void)
{
	if (g_MpCurrentChallengeConfig) {
		return g_MpCurrentChallengeConfig->strings.description;
	}

	return "";
}

char *mpconfigGetDescription(struct mpconfigfull *mpconfig)
{
	if (mpconfig) {
		return mpconfig->strings.description;
	}

	return "";
}

/**
 * Return the index of the first incomplete challenge, but if it's in the first
 * 4 then return index 4 because the first 4 are always shown.
 */
s32 mpGetAutoFocusedChallengeIndex(s32 mpchrnum)
{
	s32 challengeindex;
	s32 index = 0;

	for (challengeindex = 29; challengeindex >= 0; challengeindex--) {
		if (mpIsChallengeCompletedByPlayerWithNumPlayers(mpchrnum, challengeindex, 1) ||
				mpIsChallengeCompletedByPlayerWithNumPlayers(mpchrnum, challengeindex, 2) ||
				mpIsChallengeCompletedByPlayerWithNumPlayers(mpchrnum, challengeindex, 3) ||
				mpIsChallengeCompletedByPlayerWithNumPlayers(mpchrnum, challengeindex, 4)) {
			index = challengeindex + 1;
			break;
		}
	}

	if (index < 4) {
		index = 4;
	}

	return index;
}

char *mpChallengeGetNameWithArg(s32 arg0, s32 challengeindex)
{
	return langGet(g_MpChallenges[challengeindex].name);
}

bool mpIsChallengeCompletedByPlayerWithNumPlayers2(s32 mpchrnum, s32 index, s32 numplayers)
{
	return mpIsChallengeCompletedByPlayerWithNumPlayers(mpchrnum, index, numplayers);
}

bool mpIsChallengeCompletedByAnyPlayerWithNumPlayers(s32 index, s32 numplayers)
{
	return (g_MpChallenges[index].completions[numplayers - 1] & 1) != 0;
}

void mpSetChallengeCompletedByAnyPlayerWithNumPlayers(s32 index, s32 numplayers, bool completed)
{
	if (completed) {
		g_MpChallenges[index].completions[numplayers - 1] |= 1;
		return;
	}

	g_MpChallenges[index].completions[numplayers - 1] &= ~1;
}

bool mpIsChallengeCompletedByPlayerWithNumPlayers(s32 mpchrnum, s32 index, s32 numplayers)
{
	return (g_MpChallenges[index].completions[numplayers - 1] & (2 << mpchrnum)) != 0;
}

void mpSetChallengeCompletedByPlayerWithNumPlayers(u32 mpchrnum, s32 index, s32 numplayers, bool completed)
{
	if (completed) {
		g_MpChallenges[index].completions[numplayers - 1] |= 2 << mpchrnum;
		return;
	}

	g_MpChallenges[index].completions[numplayers - 1] &= ~(2 << mpchrnum);
}

bool mpIsChallengeCompleteForEndscreen(void)
{
	s32 prevplayernum = g_Vars.currentplayernum;
	s32 result = false;
	s32 aborted = false;
	s32 i;
	u32 stack;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		setCurrentPlayerNum(i);

		if (g_Vars.currentplayer->aborted) {
			aborted = true;
		}
	}

	setCurrentPlayerNum(prevplayernum);

	if (!aborted) {
		struct mpteaminfo info[12];
		mpGetTeamRankings(info);

		if (info[0].teamnum == 0) {
			result = true;
		}
	}

	return result;
}

void mpConsiderMarkingCurrentChallengeComplete(void)
{
	bool result = mpIsChallengeCompleteForEndscreen();

#if VERSION >= VERSION_NTSC_1_0
	if (g_CheatsActiveBank0 == 0 && g_CheatsActiveBank1 == 0 && result)
#else
	if (result && g_CheatsActiveBank0 == 0 && g_CheatsActiveBank1 == 0)
#endif
	{
		u32 prevplayernum;
		s32 i;

		mpSetChallengeCompletedByAnyPlayerWithNumPlayers(g_MpChallengeIndex, PLAYERCOUNT(), 1);
		prevplayernum = g_Vars.currentplayernum;

		for (i = 0; i < PLAYERCOUNT(); i++) {
			setCurrentPlayerNum(i);
			mpSetChallengeCompletedByPlayerWithNumPlayers(g_Vars.currentplayerstats->mpindex, g_MpChallengeIndex, PLAYERCOUNT(), true);
		}

		setCurrentPlayerNum(prevplayernum);
		mpDetermineUnlockedFeatures();
	}
}

bool mpIsFeatureUnlocked(s32 featurenum)
{
	if (featurenum == 0) {
		return true;
	}

	return (g_MpFeaturesUnlocked[featurenum] & 1) != 0;
}

bool mpIsFeatureUnlockedByPlayer(u32 numplayers, s32 featurenum)
{
	if (featurenum == 0) {
		return true;
	}

	return (g_MpFeaturesUnlocked[featurenum] & (2 << numplayers)) != 0;
}

bool func0f19c96c(s32 featurenum)
{
	if (featurenum) {
		return false;
	}

	return true;
}
