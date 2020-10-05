#include <ultra64.h>
#include "constants.h"
#include "game/chr/chrai.h"
#include "game/chr/chraicommands.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02a0e0.h"
#include "game/data/data_02da90.h"
#include "game/game_0601b0.h"
#include "game/game_096750.h"
#include "game/game_127910.h"
#include "game/game_179060.h"
#include "game/game_190260.h"
#include "game/game_19aa80.h"
#include "game/training.h"
#include "game/lang.h"
#include "game/mplayer.h"
#include "game/pad.h"
#include "gvars/gvars.h"
#include "lib/lib_0d0a0.h"
#include "lib/lib_12dc0.h"
#include "types.h"

u32 g_MpChallengeIndex = 0;
struct mpconfigfull *g_MpCurrentChallengeConfig = NULL;

// 2e4d8
struct challenge g_MpChallenges[NUM_CHALLENGES] = {
	{ L_OPTIONS(406), MPCONFIG_CHALLENGE01 }, // "Challenge 1"
	{ L_OPTIONS(407), MPCONFIG_CHALLENGE02 }, // "Challenge 2"
	{ L_OPTIONS(408), MPCONFIG_CHALLENGE03 }, // "Challenge 3"
	{ L_OPTIONS(409), MPCONFIG_CHALLENGE04 }, // "Challenge 4"
	{ L_OPTIONS(410), MPCONFIG_CHALLENGE05 }, // "Challenge 5"
	{ L_OPTIONS(411), MPCONFIG_CHALLENGE06 }, // "Challenge 6"
	{ L_OPTIONS(412), MPCONFIG_CHALLENGE07 }, // "Challenge 7"
	{ L_OPTIONS(413), MPCONFIG_CHALLENGE08 }, // "Challenge 8"
	{ L_OPTIONS(414), MPCONFIG_CHALLENGE09 }, // "Challenge 9"
	{ L_OPTIONS(415), MPCONFIG_CHALLENGE10 }, // "Challenge 10"
	{ L_OPTIONS(416), MPCONFIG_CHALLENGE11 }, // "Challenge 11"
	{ L_OPTIONS(417), MPCONFIG_CHALLENGE12 }, // "Challenge 12"
	{ L_OPTIONS(418), MPCONFIG_CHALLENGE13 }, // "Challenge 13"
	{ L_OPTIONS(419), MPCONFIG_CHALLENGE14 }, // "Challenge 14"
	{ L_OPTIONS(420), MPCONFIG_CHALLENGE15 }, // "Challenge 15"
	{ L_OPTIONS(421), MPCONFIG_CHALLENGE16 }, // "Challenge 16"
	{ L_OPTIONS(422), MPCONFIG_CHALLENGE17 }, // "Challenge 17"
	{ L_OPTIONS(423), MPCONFIG_CHALLENGE18 }, // "Challenge 18"
	{ L_OPTIONS(424), MPCONFIG_CHALLENGE19 }, // "Challenge 19"
	{ L_OPTIONS(425), MPCONFIG_CHALLENGE20 }, // "Challenge 20"
	{ L_OPTIONS(426), MPCONFIG_CHALLENGE21 }, // "Challenge 21"
	{ L_OPTIONS(427), MPCONFIG_CHALLENGE22 }, // "Challenge 22"
	{ L_OPTIONS(428), MPCONFIG_CHALLENGE23 }, // "Challenge 23"
	{ L_OPTIONS(429), MPCONFIG_CHALLENGE24 }, // "Challenge 24"
	{ L_OPTIONS(430), MPCONFIG_CHALLENGE25 }, // "Challenge 25"
	{ L_OPTIONS(431), MPCONFIG_CHALLENGE26 }, // "Challenge 26"
	{ L_OPTIONS(432), MPCONFIG_CHALLENGE27 }, // "Challenge 27"
	{ L_OPTIONS(433), MPCONFIG_CHALLENGE28 }, // "Challenge 28"
	{ L_OPTIONS(434), MPCONFIG_CHALLENGE29 }, // "Challenge 29"
	{ L_OPTIONS(435), MPCONFIG_CHALLENGE30 }, // "Challenge 30"
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

void func0f19ab40(void)
{
	if (g_Is4Mb) {
		var80090af4 = 0;
		var80090af8 = 0;
		var80090afc = 0;
	}
}

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
/*  f19abe4:	0fc458b8 */ 	jal	coverLoad
/*  f19abe8:	27a50158 */ 	addiu	$a1,$sp,0x158
/*  f19abec:	50400027 */ 	beqzl	$v0,.L0f19ac8c
/*  f19abf0:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f19abf4:	0fc4596c */ 	jal	coverHasSomeFlags
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
/*  f19ae18:	0fc458b8 */ 	jal	coverLoad
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
/*  f19ae48:	0fc259d4 */ 	jal	func0f096750
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
/*  f19aeb4:	0fc259d4 */ 	jal	func0f096750
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
/*  f19af10:	00047080 */ 	sll	$t6,$a0,0x2
/*  f19af14:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f19af18:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f19af1c:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f19af20:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f19af24:	3c028009 */ 	lui	$v0,%hi(g_MpChallenges+0x4)
/*  f19af28:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f19af2c:	904284bc */ 	lbu	$v0,%lo(g_MpChallenges+0x4)($v0)
/*  f19af30:	304f0001 */ 	andi	$t7,$v0,0x1
/*  f19af34:	03e00008 */ 	jr	$ra
/*  f19af38:	000f102b */ 	sltu	$v0,$zero,$t7
);

bool func0f19af3c(s32 chrnum, s32 challengeindex)
{
	if ((g_MpSetup.chrslots & (1 << chrnum)) == 0) {
		return 0;
	}

	return ((g_MpChallenges[challengeindex].completions[0] & (2 << chrnum)) != 0);
}

bool mpIsChallengeAvailable(s32 challengeindex)
{
	return (g_MpChallenges[challengeindex].completions[0] & (((g_MpSetup.chrslots & 0xf) << 1) | 1)) != 0;
}

GLOBAL_ASM(
glabel func0f19afdc
/*  f19afdc:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f19afe0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f19afe4:	3c118009 */ 	lui	$s1,%hi(g_MpChallenges)
/*  f19afe8:	3c028009 */ 	lui	$v0,%hi(var800887c4)
/*  f19afec:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f19aff0:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f19aff4:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f19aff8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f19affc:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f19b000:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f19b004:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f19b008:	244287c4 */ 	addiu	$v0,$v0,%lo(var800887c4)
/*  f19b00c:	263184b8 */ 	addiu	$s1,$s1,%lo(g_MpChallenges)
.L0f19b010:
/*  f19b010:	2631001a */ 	addiu	$s1,$s1,0x1a
/*  f19b014:	0222082b */ 	sltu	$at,$s1,$v0
/*  f19b018:	1420fffd */ 	bnez	$at,.L0f19b010
/*  f19b01c:	a220ffea */ 	sb	$zero,-0x16($s1)
/*  f19b020:	3c118009 */ 	lui	$s1,%hi(g_MpChallenges)
/*  f19b024:	0000a025 */ 	or	$s4,$zero,$zero
/*  f19b028:	263184b8 */ 	addiu	$s1,$s1,%lo(g_MpChallenges)
/*  f19b02c:	0000a825 */ 	or	$s5,$zero,$zero
.L0f19b030:
/*  f19b030:	00009025 */ 	or	$s2,$zero,$zero
/*  f19b034:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19b038:	0fc670f7 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayers
/*  f19b03c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f19b040:	1440000d */ 	bnez	$v0,.L0f19b078
/*  f19b044:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19b048:	0fc670f7 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayers
/*  f19b04c:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f19b050:	14400009 */ 	bnez	$v0,.L0f19b078
/*  f19b054:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19b058:	0fc670f7 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayers
/*  f19b05c:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f19b060:	14400005 */ 	bnez	$v0,.L0f19b078
/*  f19b064:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19b068:	0fc670f7 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayers
/*  f19b06c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f19b070:	10400003 */ 	beqz	$v0,.L0f19b080
/*  f19b074:	2aa10004 */ 	slti	$at,$s5,0x4
.L0f19b078:
/*  f19b078:	1000001b */ 	b	.L0f19b0e8
/*  f19b07c:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f19b080:
/*  f19b080:	10200004 */ 	beqz	$at,.L0f19b094
/*  f19b084:	00000000 */ 	nop
/*  f19b088:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f19b08c:	10000016 */ 	b	.L0f19b0e8
/*  f19b090:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f19b094:
/*  f19b094:	1aa00014 */ 	blez	$s5,.L0f19b0e8
/*  f19b098:	26b0ffff */ 	addiu	$s0,$s5,-1
/*  f19b09c:	02002025 */ 	or	$a0,$s0,$zero
/*  f19b0a0:	0fc670f7 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayers
/*  f19b0a4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f19b0a8:	1440000d */ 	bnez	$v0,.L0f19b0e0
/*  f19b0ac:	02002025 */ 	or	$a0,$s0,$zero
/*  f19b0b0:	0fc670f7 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayers
/*  f19b0b4:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f19b0b8:	14400009 */ 	bnez	$v0,.L0f19b0e0
/*  f19b0bc:	02002025 */ 	or	$a0,$s0,$zero
/*  f19b0c0:	0fc670f7 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayers
/*  f19b0c4:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f19b0c8:	14400005 */ 	bnez	$v0,.L0f19b0e0
/*  f19b0cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f19b0d0:	0fc670f7 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayers
/*  f19b0d4:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f19b0d8:	50400004 */ 	beqzl	$v0,.L0f19b0ec
/*  f19b0dc:	922e0004 */ 	lbu	$t6,0x4($s1)
.L0f19b0e0:
/*  f19b0e0:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f19b0e4:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f19b0e8:
/*  f19b0e8:	922e0004 */ 	lbu	$t6,0x4($s1)
.L0f19b0ec:
/*  f19b0ec:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f19b0f0:	2aa1001e */ 	slti	$at,$s5,0x1e
/*  f19b0f4:	01d27825 */ 	or	$t7,$t6,$s2
/*  f19b0f8:	2631001a */ 	addiu	$s1,$s1,0x1a
/*  f19b0fc:	1420ffcc */ 	bnez	$at,.L0f19b030
/*  f19b100:	a22fffea */ 	sb	$t7,-0x16($s1)
/*  f19b104:	2a810004 */ 	slti	$at,$s4,0x4
/*  f19b108:	10200014 */ 	beqz	$at,.L0f19b15c
/*  f19b10c:	00009825 */ 	or	$s3,$zero,$zero
/*  f19b110:	0000c080 */ 	sll	$t8,$zero,0x2
/*  f19b114:	0300c023 */ 	subu	$t8,$t8,$zero
/*  f19b118:	3c198009 */ 	lui	$t9,%hi(g_MpChallenges)
/*  f19b11c:	273984b8 */ 	addiu	$t9,$t9,%lo(g_MpChallenges)
/*  f19b120:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f19b124:	3c038009 */ 	lui	$v1,%hi(var800887c4)
/*  f19b128:	246387c4 */ 	addiu	$v1,$v1,%lo(var800887c4)
/*  f19b12c:	03198821 */ 	addu	$s1,$t8,$t9
/*  f19b130:	92220004 */ 	lbu	$v0,0x4($s1)
.L0f19b134:
/*  f19b134:	30480001 */ 	andi	$t0,$v0,0x1
/*  f19b138:	15000003 */ 	bnez	$t0,.L0f19b148
/*  f19b13c:	34490001 */ 	ori	$t1,$v0,0x1
/*  f19b140:	a2290004 */ 	sb	$t1,0x4($s1)
/*  f19b144:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f19b148:
/*  f19b148:	2a810004 */ 	slti	$at,$s4,0x4
/*  f19b14c:	10200003 */ 	beqz	$at,.L0f19b15c
/*  f19b150:	2631001a */ 	addiu	$s1,$s1,0x1a
/*  f19b154:	5623fff7 */ 	bnel	$s1,$v1,.L0f19b134
/*  f19b158:	92220004 */ 	lbu	$v0,0x4($s1)
.L0f19b15c:
/*  f19b15c:	3c168009 */ 	lui	$s6,%hi(var800887c4)
/*  f19b160:	26d687c4 */ 	addiu	$s6,$s6,%lo(var800887c4)
.L0f19b164:
/*  f19b164:	3c118009 */ 	lui	$s1,%hi(g_MpChallenges)
/*  f19b168:	0000a025 */ 	or	$s4,$zero,$zero
/*  f19b16c:	263184b8 */ 	addiu	$s1,$s1,%lo(g_MpChallenges)
/*  f19b170:	0000a825 */ 	or	$s5,$zero,$zero
.L0f19b174:
/*  f19b174:	00009025 */ 	or	$s2,$zero,$zero
/*  f19b178:	02602025 */ 	or	$a0,$s3,$zero
/*  f19b17c:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19b180:	0fc6711f */ 	jal	mpIsChallengeCompletedByChrWithNumPlayers
/*  f19b184:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f19b188:	14400010 */ 	bnez	$v0,.L0f19b1cc
/*  f19b18c:	02602025 */ 	or	$a0,$s3,$zero
/*  f19b190:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19b194:	0fc6711f */ 	jal	mpIsChallengeCompletedByChrWithNumPlayers
/*  f19b198:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f19b19c:	1440000b */ 	bnez	$v0,.L0f19b1cc
/*  f19b1a0:	02602025 */ 	or	$a0,$s3,$zero
/*  f19b1a4:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19b1a8:	0fc6711f */ 	jal	mpIsChallengeCompletedByChrWithNumPlayers
/*  f19b1ac:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f19b1b0:	14400006 */ 	bnez	$v0,.L0f19b1cc
/*  f19b1b4:	02602025 */ 	or	$a0,$s3,$zero
/*  f19b1b8:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19b1bc:	0fc6711f */ 	jal	mpIsChallengeCompletedByChrWithNumPlayers
/*  f19b1c0:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f19b1c4:	10400006 */ 	beqz	$v0,.L0f19b1e0
/*  f19b1c8:	2aa10004 */ 	slti	$at,$s5,0x4
.L0f19b1cc:
/*  f19b1cc:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f19b1d0:	026a9004 */ 	sllv	$s2,$t2,$s3
/*  f19b1d4:	324b00ff */ 	andi	$t3,$s2,0xff
/*  f19b1d8:	10000023 */ 	b	.L0f19b268
/*  f19b1dc:	01609025 */ 	or	$s2,$t3,$zero
.L0f19b1e0:
/*  f19b1e0:	10200006 */ 	beqz	$at,.L0f19b1fc
/*  f19b1e4:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f19b1e8:	026c9004 */ 	sllv	$s2,$t4,$s3
/*  f19b1ec:	324d00ff */ 	andi	$t5,$s2,0xff
/*  f19b1f0:	01a09025 */ 	or	$s2,$t5,$zero
/*  f19b1f4:	1000001c */ 	b	.L0f19b268
/*  f19b1f8:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f19b1fc:
/*  f19b1fc:	1aa0001a */ 	blez	$s5,.L0f19b268
/*  f19b200:	02602025 */ 	or	$a0,$s3,$zero
/*  f19b204:	26b0ffff */ 	addiu	$s0,$s5,-1
/*  f19b208:	02002825 */ 	or	$a1,$s0,$zero
/*  f19b20c:	0fc6711f */ 	jal	mpIsChallengeCompletedByChrWithNumPlayers
/*  f19b210:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f19b214:	1440000f */ 	bnez	$v0,.L0f19b254
/*  f19b218:	02602025 */ 	or	$a0,$s3,$zero
/*  f19b21c:	02002825 */ 	or	$a1,$s0,$zero
/*  f19b220:	0fc6711f */ 	jal	mpIsChallengeCompletedByChrWithNumPlayers
/*  f19b224:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f19b228:	1440000a */ 	bnez	$v0,.L0f19b254
/*  f19b22c:	02602025 */ 	or	$a0,$s3,$zero
/*  f19b230:	02002825 */ 	or	$a1,$s0,$zero
/*  f19b234:	0fc6711f */ 	jal	mpIsChallengeCompletedByChrWithNumPlayers
/*  f19b238:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f19b23c:	14400005 */ 	bnez	$v0,.L0f19b254
/*  f19b240:	02602025 */ 	or	$a0,$s3,$zero
/*  f19b244:	02002825 */ 	or	$a1,$s0,$zero
/*  f19b248:	0fc6711f */ 	jal	mpIsChallengeCompletedByChrWithNumPlayers
/*  f19b24c:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f19b250:	10400005 */ 	beqz	$v0,.L0f19b268
.L0f19b254:
/*  f19b254:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f19b258:	026e9004 */ 	sllv	$s2,$t6,$s3
/*  f19b25c:	324f00ff */ 	andi	$t7,$s2,0xff
/*  f19b260:	01e09025 */ 	or	$s2,$t7,$zero
/*  f19b264:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f19b268:
/*  f19b268:	92380004 */ 	lbu	$t8,0x4($s1)
/*  f19b26c:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f19b270:	2aa1001e */ 	slti	$at,$s5,0x1e
/*  f19b274:	0312c825 */ 	or	$t9,$t8,$s2
/*  f19b278:	2631001a */ 	addiu	$s1,$s1,0x1a
/*  f19b27c:	1420ffbd */ 	bnez	$at,.L0f19b174
/*  f19b280:	a239ffea */ 	sb	$t9,-0x16($s1)
/*  f19b284:	2a810004 */ 	slti	$at,$s4,0x4
/*  f19b288:	10200013 */ 	beqz	$at,.L0f19b2d8
/*  f19b28c:	00004080 */ 	sll	$t0,$zero,0x2
/*  f19b290:	01004023 */ 	subu	$t0,$t0,$zero
/*  f19b294:	3c098009 */ 	lui	$t1,%hi(g_MpChallenges)
/*  f19b298:	252984b8 */ 	addiu	$t1,$t1,%lo(g_MpChallenges)
/*  f19b29c:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f19b2a0:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f19b2a4:	026a1804 */ 	sllv	$v1,$t2,$s3
/*  f19b2a8:	01098821 */ 	addu	$s1,$t0,$t1
/*  f19b2ac:	92220004 */ 	lbu	$v0,0x4($s1)
.L0f19b2b0:
/*  f19b2b0:	00435824 */ 	and	$t3,$v0,$v1
/*  f19b2b4:	15600003 */ 	bnez	$t3,.L0f19b2c4
/*  f19b2b8:	00436025 */ 	or	$t4,$v0,$v1
/*  f19b2bc:	a22c0004 */ 	sb	$t4,0x4($s1)
/*  f19b2c0:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f19b2c4:
/*  f19b2c4:	2a810004 */ 	slti	$at,$s4,0x4
/*  f19b2c8:	10200003 */ 	beqz	$at,.L0f19b2d8
/*  f19b2cc:	2631001a */ 	addiu	$s1,$s1,0x1a
/*  f19b2d0:	5636fff7 */ 	bnel	$s1,$s6,.L0f19b2b0
/*  f19b2d4:	92220004 */ 	lbu	$v0,0x4($s1)
.L0f19b2d8:
/*  f19b2d8:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f19b2dc:	2a610004 */ 	slti	$at,$s3,0x4
/*  f19b2e0:	1420ffa0 */ 	bnez	$at,.L0f19b164
/*  f19b2e4:	00000000 */ 	nop
/*  f19b2e8:	3c14800b */ 	lui	$s4,%hi(g_MpChallengesCompleted)
/*  f19b2ec:	3c16800b */ 	lui	$s6,%hi(g_MpChallengesCompleted)
/*  f19b2f0:	26d6ccc8 */ 	addiu	$s6,$s6,%lo(g_MpChallengesCompleted)
/*  f19b2f4:	2694ccc8 */ 	addiu	$s4,$s4,%lo(g_MpChallengesCompleted)
/*  f19b2f8:	00009825 */ 	or	$s3,$zero,$zero
/*  f19b2fc:	24110010 */ 	addiu	$s1,$zero,0x10
.L0f19b300:
/*  f19b300:	00009025 */ 	or	$s2,$zero,$zero
/*  f19b304:	0000a825 */ 	or	$s5,$zero,$zero
.L0f19b308:
/*  f19b308:	0fc66be6 */ 	jal	mpIsChallengeAvailable
/*  f19b30c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f19b310:	10400011 */ 	beqz	$v0,.L0f19b358
/*  f19b314:	00156880 */ 	sll	$t5,$s5,0x2
/*  f19b318:	01b56823 */ 	subu	$t5,$t5,$s5
/*  f19b31c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f19b320:	01b56821 */ 	addu	$t5,$t5,$s5
/*  f19b324:	3c0e8009 */ 	lui	$t6,%hi(g_MpChallenges)
/*  f19b328:	25ce84b8 */ 	addiu	$t6,$t6,%lo(g_MpChallenges)
/*  f19b32c:	000d6840 */ 	sll	$t5,$t5,0x1
/*  f19b330:	01ae1821 */ 	addu	$v1,$t5,$t6
/*  f19b334:	00001025 */ 	or	$v0,$zero,$zero
.L0f19b338:
/*  f19b338:	906f0009 */ 	lbu	$t7,0x9($v1)
/*  f19b33c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f19b340:	36580001 */ 	ori	$t8,$s2,0x1
/*  f19b344:	166f0002 */ 	bne	$s3,$t7,.L0f19b350
/*  f19b348:	00000000 */ 	nop
/*  f19b34c:	331200ff */ 	andi	$s2,$t8,0xff
.L0f19b350:
/*  f19b350:	1451fff9 */ 	bne	$v0,$s1,.L0f19b338
/*  f19b354:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f19b358:
/*  f19b358:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f19b35c:	2aa1001e */ 	slti	$at,$s5,0x1e
/*  f19b360:	1420ffe9 */ 	bnez	$at,.L0f19b308
/*  f19b364:	00000000 */ 	nop
/*  f19b368:	3c03800b */ 	lui	$v1,%hi(var800acca0)
/*  f19b36c:	2463cca0 */ 	addiu	$v1,$v1,%lo(var800acca0)
/*  f19b370:	90680000 */ 	lbu	$t0,0x0($v1)
.L0f19b374:
/*  f19b374:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f19b378:	36490001 */ 	ori	$t1,$s2,0x1
/*  f19b37c:	16680002 */ 	bne	$s3,$t0,.L0f19b388
/*  f19b380:	00000000 */ 	nop
/*  f19b384:	313200ff */ 	andi	$s2,$t1,0xff
.L0f19b388:
/*  f19b388:	5476fffa */ 	bnel	$v1,$s6,.L0f19b374
/*  f19b38c:	90680000 */ 	lbu	$t0,0x0($v1)
/*  f19b390:	0000a825 */ 	or	$s5,$zero,$zero
/*  f19b394:	00008025 */ 	or	$s0,$zero,$zero
.L0f19b398:
/*  f19b398:	02002025 */ 	or	$a0,$s0,$zero
.L0f19b39c:
/*  f19b39c:	0fc66bcf */ 	jal	func0f19af3c
/*  f19b3a0:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19b3a4:	10400013 */ 	beqz	$v0,.L0f19b3f4
/*  f19b3a8:	00155880 */ 	sll	$t3,$s5,0x2
/*  f19b3ac:	01755823 */ 	subu	$t3,$t3,$s5
/*  f19b3b0:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f19b3b4:	01755821 */ 	addu	$t3,$t3,$s5
/*  f19b3b8:	3c0c8009 */ 	lui	$t4,%hi(g_MpChallenges)
/*  f19b3bc:	258c84b8 */ 	addiu	$t4,$t4,%lo(g_MpChallenges)
/*  f19b3c0:	000b5840 */ 	sll	$t3,$t3,0x1
/*  f19b3c4:	016c1821 */ 	addu	$v1,$t3,$t4
/*  f19b3c8:	00001025 */ 	or	$v0,$zero,$zero
.L0f19b3cc:
/*  f19b3cc:	906d0009 */ 	lbu	$t5,0x9($v1)
/*  f19b3d0:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f19b3d4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f19b3d8:	166d0004 */ 	bne	$s3,$t5,.L0f19b3ec
/*  f19b3dc:	020e7804 */ 	sllv	$t7,$t6,$s0
/*  f19b3e0:	024f9025 */ 	or	$s2,$s2,$t7
/*  f19b3e4:	325800ff */ 	andi	$t8,$s2,0xff
/*  f19b3e8:	03009025 */ 	or	$s2,$t8,$zero
.L0f19b3ec:
/*  f19b3ec:	1451fff7 */ 	bne	$v0,$s1,.L0f19b3cc
/*  f19b3f0:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f19b3f4:
/*  f19b3f4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19b3f8:	2a010004 */ 	slti	$at,$s0,0x4
/*  f19b3fc:	5420ffe7 */ 	bnezl	$at,.L0f19b39c
/*  f19b400:	02002025 */ 	or	$a0,$s0,$zero
/*  f19b404:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f19b408:	2aa1001e */ 	slti	$at,$s5,0x1e
/*  f19b40c:	5420ffe2 */ 	bnezl	$at,.L0f19b398
/*  f19b410:	00008025 */ 	or	$s0,$zero,$zero
/*  f19b414:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f19b418:	2a610050 */ 	slti	$at,$s3,0x50
/*  f19b41c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f19b420:	1420ffb7 */ 	bnez	$at,.L0f19b300
/*  f19b424:	a292ffff */ 	sb	$s2,-0x1($s4)
/*  f19b428:	0fc622f3 */ 	jal	func0f188bcc
/*  f19b42c:	00009825 */ 	or	$s3,$zero,$zero
/*  f19b430:	1840001c */ 	blez	$v0,.L0f19b4a4
/*  f19b434:	0013c880 */ 	sll	$t9,$s3,0x2
/*  f19b438:	0333c821 */ 	addu	$t9,$t9,$s3
/*  f19b43c:	3c088008 */ 	lui	$t0,%hi(g_MpWeapons)
/*  f19b440:	25087268 */ 	addiu	$t0,$t0,%lo(g_MpWeapons)
/*  f19b444:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f19b448:	3c11800b */ 	lui	$s1,%hi(g_MpChallengesCompleted)
/*  f19b44c:	2631ccc8 */ 	addiu	$s1,$s1,%lo(g_MpChallengesCompleted)
/*  f19b450:	03288021 */ 	addu	$s0,$t9,$t0
/*  f19b454:	96090004 */ 	lhu	$t1,0x4($s0)
.L0f19b458:
/*  f19b458:	312a007f */ 	andi	$t2,$t1,0x7f
/*  f19b45c:	5940000c */ 	blezl	$t2,.L0f19b490
/*  f19b460:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f19b464:	0fc672f3 */ 	jal	func0f19cbcc
/*  f19b468:	92040000 */ 	lbu	$a0,0x0($s0)
/*  f19b46c:	50400008 */ 	beqzl	$v0,.L0f19b490
/*  f19b470:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f19b474:	960b0004 */ 	lhu	$t3,0x4($s0)
/*  f19b478:	316c007f */ 	andi	$t4,$t3,0x7f
/*  f19b47c:	022c1021 */ 	addu	$v0,$s1,$t4
/*  f19b480:	904d0000 */ 	lbu	$t5,0x0($v0)
/*  f19b484:	35ae0001 */ 	ori	$t6,$t5,0x1
/*  f19b488:	a04e0000 */ 	sb	$t6,0x0($v0)
/*  f19b48c:	26730001 */ 	addiu	$s3,$s3,0x1
.L0f19b490:
/*  f19b490:	0fc622f3 */ 	jal	func0f188bcc
/*  f19b494:	2610000a */ 	addiu	$s0,$s0,0xa
/*  f19b498:	0262082a */ 	slt	$at,$s3,$v0
/*  f19b49c:	5420ffee */ 	bnezl	$at,.L0f19b458
/*  f19b4a0:	96090004 */ 	lhu	$t1,0x4($s0)
.L0f19b4a4:
/*  f19b4a4:	0fc6257a */ 	jal	func0f1895e8
/*  f19b4a8:	00000000 */ 	nop
/*  f19b4ac:	0fc67244 */ 	jal	mpIsChallengeComplete
/*  f19b4b0:	24040040 */ 	addiu	$a0,$zero,0x40
/*  f19b4b4:	14400018 */ 	bnez	$v0,.L0f19b518
/*  f19b4b8:	24100004 */ 	addiu	$s0,$zero,0x4
/*  f19b4bc:	3c11800b */ 	lui	$s1,%hi(g_MpSetup)
/*  f19b4c0:	2631cb88 */ 	addiu	$s1,$s1,%lo(g_MpSetup)
/*  f19b4c4:	24120008 */ 	addiu	$s2,$zero,0x8
/*  f19b4c8:	962f0016 */ 	lhu	$t7,0x16($s1)
.L0f19b4cc:
/*  f19b4cc:	26180004 */ 	addiu	$t8,$s0,0x4
/*  f19b4d0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f19b4d4:	03194004 */ 	sllv	$t0,$t9,$t8
/*  f19b4d8:	01e84824 */ 	and	$t1,$t7,$t0
/*  f19b4dc:	51200004 */ 	beqzl	$t1,.L0f19b4f0
/*  f19b4e0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19b4e4:	0fc632ff */ 	jal	mpRemoveSimulant
/*  f19b4e8:	02002025 */ 	or	$a0,$s0,$zero
/*  f19b4ec:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f19b4f0:
/*  f19b4f0:	5612fff6 */ 	bnel	$s0,$s2,.L0f19b4cc
/*  f19b4f4:	962f0016 */ 	lhu	$t7,0x16($s1)
/*  f19b4f8:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f19b4fc:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f19b500:	8c4a04a4 */ 	lw	$t2,0x4a4($v0)
/*  f19b504:	240b0004 */ 	addiu	$t3,$zero,0x4
/*  f19b508:	29410005 */ 	slti	$at,$t2,0x5
/*  f19b50c:	54200003 */ 	bnezl	$at,.L0f19b51c
/*  f19b510:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f19b514:	ac4b04a4 */ 	sw	$t3,0x4a4($v0)
.L0f19b518:
/*  f19b518:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f19b51c:
/*  f19b51c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f19b520:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f19b524:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f19b528:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f19b52c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f19b530:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f19b534:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f19b538:	03e00008 */ 	jr	$ra
/*  f19b53c:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

void mpPerformSanityChecks(void)
{
	if (g_MpSetupSaveFile.locktype == MPLOCKTYPE_CHALLENGE) {
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
			g_MpSimulants[i].skill = g_MpSimulantSkillsPerNumPlayers[i * 4 + numplayers - 1];

			if (g_MpSimulants[i].skill != SIMSKILL_DISABLED) {
				g_MpSetup.chrslots |= 1 << (i + 4);
			}
		}

		if (g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL) {
			g_Vars.mphilltime = 10;
		}
	} else if (!mpIsChallengeComplete(CHALLENGE_UNK64)) {
		// Limit to 4 players and 4 simulants
		g_MpSetup.chrslots &= 0x00ff;
	}
}

s32 mpGetNumAvailableChallenges(void)
{
	s32 challengeindex;
	s32 count = 0;

	for (challengeindex = 0; challengeindex != NUM_CHALLENGES; challengeindex++) {
		if (mpIsChallengeAvailable(challengeindex)) {
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
		if (mpIsChallengeAvailable(i)) {
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
		if (mpIsChallengeAvailable(challengeindex)) {
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
		if (mpIsChallengeAvailable(i)) {
			if (availableindex == slot) {
				return mpIsChallengeCompletedByAnyChrWithNumPlayers(i, numplayers);
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
		if (mpIsChallengeAvailable(i)) {
			if (availableindex == slot) {
				return mpIsChallengeCompletedByChrWithNumPlayers(mpchrnum, i, numplayers);
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
/*  f19b924:	0fc5b9b5 */ 	jal	langGetLanguageId
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
/*  f19b99c:	0c003522 */ 	jal	func0000d488
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
/*  f19b9d0:	0c003522 */ 	jal	func0000d488
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
//	u32 language_id = langGetLanguageId();
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
//	mpconfig = func0000d488(buffer, &_mpconfigsSegmentRomStart[confignum], sizeof(struct mpconfig));
//
//	// Load mpstrings
//	bank = banks[language_id][0];
//	loadedstrings = func0000d488(buffer2, &bank[confignum], sizeof(struct mpstrings));
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
		if (mpIsChallengeAvailable(challengeindex)) {
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
 * This is adding unlockvalue to the array, provided it's unique.
 */
s32 func0f19bb50(s32 unlockvalue, u8 *array, s32 index, s32 len)
{
	s32 i;

	for (i = 0; i < index; i++) {
		if (array[i] == unlockvalue) {
			break;
		}
	}

	if (i >= index && index < len) {
		array[index] = unlockvalue;
		index++;
	}

	return index;
}

GLOBAL_ASM(
glabel func0f19bb98
/*  f19bb98:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f19bb9c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f19bba0:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f19bba4:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f19bba8:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f19bbac:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f19bbb0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f19bbb4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f19bbb8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f19bbbc:	3c138008 */ 	lui	$s3,%hi(g_MpWeapons)
/*  f19bbc0:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f19bbc4:	00c0b025 */ 	or	$s6,$a2,$zero
/*  f19bbc8:	0080b825 */ 	or	$s7,$a0,$zero
/*  f19bbcc:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f19bbd0:	00009025 */ 	or	$s2,$zero,$zero
/*  f19bbd4:	26737268 */ 	addiu	$s3,$s3,%lo(g_MpWeapons)
/*  f19bbd8:	00808025 */ 	or	$s0,$a0,$zero
/*  f19bbdc:	00008825 */ 	or	$s1,$zero,$zero
/*  f19bbe0:	2414000a */ 	addiu	$s4,$zero,0xa
.L0f19bbe4:
/*  f19bbe4:	920e0018 */ 	lbu	$t6,0x18($s0)
/*  f19bbe8:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19bbec:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bbf0:	01d40019 */ 	multu	$t6,$s4
/*  f19bbf4:	00007812 */ 	mflo	$t7
/*  f19bbf8:	026fc021 */ 	addu	$t8,$s3,$t7
/*  f19bbfc:	97040004 */ 	lhu	$a0,0x4($t8)
/*  f19bc00:	3099007f */ 	andi	$t9,$a0,0x7f
/*  f19bc04:	13200004 */ 	beqz	$t9,.L0f19bc18
/*  f19bc08:	03202025 */ 	or	$a0,$t9,$zero
/*  f19bc0c:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19bc10:	02c03825 */ 	or	$a3,$s6,$zero
/*  f19bc14:	00409025 */ 	or	$s2,$v0,$zero
.L0f19bc18:
/*  f19bc18:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f19bc1c:	2a210006 */ 	slti	$at,$s1,0x6
/*  f19bc20:	1420fff0 */ 	bnez	$at,.L0f19bbe4
/*  f19bc24:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19bc28:	0fc5e43f */ 	jal	func0f1790fc
/*  f19bc2c:	00008825 */ 	or	$s1,$zero,$zero
/*  f19bc30:	18400018 */ 	blez	$v0,.L0f19bc94
/*  f19bc34:	00114080 */ 	sll	$t0,$s1,0x2
/*  f19bc38:	01114023 */ 	subu	$t0,$t0,$s1
/*  f19bc3c:	3c098008 */ 	lui	$t1,%hi(g_MpArenas)
/*  f19bc40:	25294b98 */ 	addiu	$t1,$t1,%lo(g_MpArenas)
/*  f19bc44:	00084040 */ 	sll	$t0,$t0,0x1
/*  f19bc48:	01098021 */ 	addu	$s0,$t0,$t1
/*  f19bc4c:	92ea0011 */ 	lbu	$t2,0x11($s7)
.L0f19bc50:
/*  f19bc50:	860b0000 */ 	lh	$t3,0x0($s0)
/*  f19bc54:	554b000a */ 	bnel	$t2,$t3,.L0f19bc80
/*  f19bc58:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f19bc5c:	92040002 */ 	lbu	$a0,0x2($s0)
/*  f19bc60:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19bc64:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bc68:	50800005 */ 	beqzl	$a0,.L0f19bc80
/*  f19bc6c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f19bc70:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19bc74:	02c03825 */ 	or	$a3,$s6,$zero
/*  f19bc78:	00409025 */ 	or	$s2,$v0,$zero
/*  f19bc7c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f19bc80:
/*  f19bc80:	0fc5e43f */ 	jal	func0f1790fc
/*  f19bc84:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f19bc88:	0222082a */ 	slt	$at,$s1,$v0
/*  f19bc8c:	5420fff0 */ 	bnezl	$at,.L0f19bc50
/*  f19bc90:	92ea0011 */ 	lbu	$t2,0x11($s7)
.L0f19bc94:
/*  f19bc94:	92e20010 */ 	lbu	$v0,0x10($s7)
/*  f19bc98:	3c048008 */ 	lui	$a0,%hi(g_MpScenarioOverviews+0x4)
/*  f19bc9c:	28410006 */ 	slti	$at,$v0,0x6
/*  f19bca0:	1020000c */ 	beqz	$at,.L0f19bcd4
/*  f19bca4:	00026080 */ 	sll	$t4,$v0,0x2
/*  f19bca8:	01826023 */ 	subu	$t4,$t4,$v0
/*  f19bcac:	000c6040 */ 	sll	$t4,$t4,0x1
/*  f19bcb0:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f19bcb4:	9084714c */ 	lbu	$a0,%lo(g_MpScenarioOverviews+0x4)($a0)
/*  f19bcb8:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19bcbc:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bcc0:	50800005 */ 	beqzl	$a0,.L0f19bcd8
/*  f19bcc4:	8ee3000c */ 	lw	$v1,0xc($s7)
/*  f19bcc8:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19bccc:	02c03825 */ 	or	$a3,$s6,$zero
/*  f19bcd0:	00409025 */ 	or	$s2,$v0,$zero
.L0f19bcd4:
/*  f19bcd4:	8ee3000c */ 	lw	$v1,0xc($s7)
.L0f19bcd8:
/*  f19bcd8:	2404001e */ 	addiu	$a0,$zero,0x1e
/*  f19bcdc:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19bce0:	306d0001 */ 	andi	$t5,$v1,0x1
/*  f19bce4:	11a00005 */ 	beqz	$t5,.L0f19bcfc
/*  f19bce8:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bcec:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19bcf0:	02c03825 */ 	or	$a3,$s6,$zero
/*  f19bcf4:	00409025 */ 	or	$s2,$v0,$zero
/*  f19bcf8:	8ee3000c */ 	lw	$v1,0xc($s7)
.L0f19bcfc:
/*  f19bcfc:	306e00c0 */ 	andi	$t6,$v1,0xc0
/*  f19bd00:	11c00006 */ 	beqz	$t6,.L0f19bd1c
/*  f19bd04:	2404001d */ 	addiu	$a0,$zero,0x1d
/*  f19bd08:	02a02825 */ 	or	$a1,$s5,$zero
/*  f19bd0c:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bd10:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19bd14:	02c03825 */ 	or	$a3,$s6,$zero
/*  f19bd18:	00409025 */ 	or	$s2,$v0,$zero
.L0f19bd1c:
/*  f19bd1c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f19bd20:	02401025 */ 	or	$v0,$s2,$zero
/*  f19bd24:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f19bd28:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f19bd2c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f19bd30:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f19bd34:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f19bd38:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f19bd3c:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f19bd40:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f19bd44:	03e00008 */ 	jr	$ra
/*  f19bd48:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f19bd4c
/*  f19bd4c:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f19bd50:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f19bd54:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f19bd58:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f19bd5c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f19bd60:	00808025 */ 	or	$s0,$a0,$zero
/*  f19bd64:	00c09825 */ 	or	$s3,$a2,$zero
/*  f19bd68:	00a0a025 */ 	or	$s4,$a1,$zero
/*  f19bd6c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f19bd70:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f19bd74:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f19bd78:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f19bd7c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f19bd80:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f19bd84:	0fc66ee6 */ 	jal	func0f19bb98
/*  f19bd88:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f19bd8c:	3c158008 */ 	lui	$s5,%hi(g_MpSimulantTypes)
/*  f19bd90:	00409025 */ 	or	$s2,$v0,$zero
/*  f19bd94:	26b5772c */ 	addiu	$s5,$s5,%lo(g_MpSimulantTypes)
/*  f19bd98:	0000f025 */ 	or	$s8,$zero,$zero
/*  f19bd9c:	0200b825 */ 	or	$s7,$s0,$zero
/*  f19bda0:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f19bda4:	24160004 */ 	addiu	$s6,$zero,0x4
.L0f19bda8:
/*  f19bda8:	92e40028 */ 	lbu	$a0,0x28($s7)
/*  f19bdac:	0fc6335a */ 	jal	mpGetSimTypeIndex
/*  f19bdb0:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f19bdb4:	0440000a */ 	bltz	$v0,.L0f19bde0
/*  f19bdb8:	000270c0 */ 	sll	$t6,$v0,0x3
/*  f19bdbc:	02ae7821 */ 	addu	$t7,$s5,$t6
/*  f19bdc0:	91e40006 */ 	lbu	$a0,0x6($t7)
/*  f19bdc4:	02802825 */ 	or	$a1,$s4,$zero
/*  f19bdc8:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bdcc:	50800005 */ 	beqzl	$a0,.L0f19bde4
/*  f19bdd0:	00008025 */ 	or	$s0,$zero,$zero
/*  f19bdd4:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19bdd8:	02603825 */ 	or	$a3,$s3,$zero
/*  f19bddc:	00409025 */ 	or	$s2,$v0,$zero
.L0f19bde0:
/*  f19bde0:	00008025 */ 	or	$s0,$zero,$zero
.L0f19bde4:
/*  f19bde4:	8fb10040 */ 	lw	$s1,0x40($sp)
.L0f19bde8:
/*  f19bde8:	00002025 */ 	or	$a0,$zero,$zero
/*  f19bdec:	0fc6335a */ 	jal	mpGetSimTypeIndex
/*  f19bdf0:	9225002c */ 	lbu	$a1,0x2c($s1)
/*  f19bdf4:	0440000a */ 	bltz	$v0,.L0f19be20
/*  f19bdf8:	0002c0c0 */ 	sll	$t8,$v0,0x3
/*  f19bdfc:	02b8c821 */ 	addu	$t9,$s5,$t8
/*  f19be00:	93240006 */ 	lbu	$a0,0x6($t9)
/*  f19be04:	02802825 */ 	or	$a1,$s4,$zero
/*  f19be08:	02403025 */ 	or	$a2,$s2,$zero
/*  f19be0c:	50800005 */ 	beqzl	$a0,.L0f19be24
/*  f19be10:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f19be14:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19be18:	02603825 */ 	or	$a3,$s3,$zero
/*  f19be1c:	00409025 */ 	or	$s2,$v0,$zero
.L0f19be20:
/*  f19be20:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f19be24:
/*  f19be24:	1616fff0 */ 	bne	$s0,$s6,.L0f19bde8
/*  f19be28:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f19be2c:	92e2002a */ 	lbu	$v0,0x2a($s7)
/*  f19be30:	3c048008 */ 	lui	$a0,%hi(g_MpBodies+0x6)
/*  f19be34:	2841003d */ 	slti	$at,$v0,0x3d
/*  f19be38:	1020000a */ 	beqz	$at,.L0f19be64
/*  f19be3c:	000240c0 */ 	sll	$t0,$v0,0x3
/*  f19be40:	00882021 */ 	addu	$a0,$a0,$t0
/*  f19be44:	908477c2 */ 	lbu	$a0,%lo(g_MpBodies+0x6)($a0)
/*  f19be48:	02802825 */ 	or	$a1,$s4,$zero
/*  f19be4c:	02403025 */ 	or	$a2,$s2,$zero
/*  f19be50:	50800005 */ 	beqzl	$a0,.L0f19be68
/*  f19be54:	92e20029 */ 	lbu	$v0,0x29($s7)
/*  f19be58:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19be5c:	02603825 */ 	or	$a3,$s3,$zero
/*  f19be60:	00409025 */ 	or	$s2,$v0,$zero
.L0f19be64:
/*  f19be64:	92e20029 */ 	lbu	$v0,0x29($s7)
.L0f19be68:
/*  f19be68:	3c048008 */ 	lui	$a0,%hi(g_MpHeads+0x2)
/*  f19be6c:	2841004b */ 	slti	$at,$v0,0x4b
/*  f19be70:	1020000a */ 	beqz	$at,.L0f19be9c
/*  f19be74:	00024880 */ 	sll	$t1,$v0,0x2
/*  f19be78:	00892021 */ 	addu	$a0,$a0,$t1
/*  f19be7c:	9084752e */ 	lbu	$a0,%lo(g_MpHeads+0x2)($a0)
/*  f19be80:	02802825 */ 	or	$a1,$s4,$zero
/*  f19be84:	02403025 */ 	or	$a2,$s2,$zero
/*  f19be88:	50800005 */ 	beqzl	$a0,.L0f19bea0
/*  f19be8c:	8faa0040 */ 	lw	$t2,0x40($sp)
/*  f19be90:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19be94:	02603825 */ 	or	$a3,$s3,$zero
/*  f19be98:	00409025 */ 	or	$s2,$v0,$zero
.L0f19be9c:
/*  f19be9c:	8faa0040 */ 	lw	$t2,0x40($sp)
.L0f19bea0:
/*  f19bea0:	27de0008 */ 	addiu	$s8,$s8,0x8
/*  f19bea4:	2bc10040 */ 	slti	$at,$s8,0x40
/*  f19bea8:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f19beac:	afab0040 */ 	sw	$t3,0x40($sp)
/*  f19beb0:	1420ffbd */ 	bnez	$at,.L0f19bda8
/*  f19beb4:	26f70008 */ 	addiu	$s7,$s7,0x8
/*  f19beb8:	8fa2006c */ 	lw	$v0,0x6c($sp)
/*  f19bebc:	2404001c */ 	addiu	$a0,$zero,0x1c
/*  f19bec0:	02802825 */ 	or	$a1,$s4,$zero
/*  f19bec4:	28410019 */ 	slti	$at,$v0,0x19
/*  f19bec8:	14200006 */ 	bnez	$at,.L0f19bee4
/*  f19becc:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bed0:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19bed4:	02603825 */ 	or	$a3,$s3,$zero
/*  f19bed8:	00409025 */ 	or	$s2,$v0,$zero
/*  f19bedc:	10000014 */ 	b	.L0f19bf30
/*  f19bee0:	8fa2006c */ 	lw	$v0,0x6c($sp)
.L0f19bee4:
/*  f19bee4:	28410014 */ 	slti	$at,$v0,0x14
/*  f19bee8:	14200008 */ 	bnez	$at,.L0f19bf0c
/*  f19beec:	24040023 */ 	addiu	$a0,$zero,0x23
/*  f19bef0:	02802825 */ 	or	$a1,$s4,$zero
/*  f19bef4:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bef8:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19befc:	02603825 */ 	or	$a3,$s3,$zero
/*  f19bf00:	00409025 */ 	or	$s2,$v0,$zero
/*  f19bf04:	1000000a */ 	b	.L0f19bf30
/*  f19bf08:	8fa2006c */ 	lw	$v0,0x6c($sp)
.L0f19bf0c:
/*  f19bf0c:	2841000f */ 	slti	$at,$v0,0xf
/*  f19bf10:	14200007 */ 	bnez	$at,.L0f19bf30
/*  f19bf14:	2404004d */ 	addiu	$a0,$zero,0x4d
/*  f19bf18:	02802825 */ 	or	$a1,$s4,$zero
/*  f19bf1c:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bf20:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19bf24:	02603825 */ 	or	$a3,$s3,$zero
/*  f19bf28:	00409025 */ 	or	$s2,$v0,$zero
/*  f19bf2c:	8fa2006c */ 	lw	$v0,0x6c($sp)
.L0f19bf30:
/*  f19bf30:	2841000a */ 	slti	$at,$v0,0xa
/*  f19bf34:	14200006 */ 	bnez	$at,.L0f19bf50
/*  f19bf38:	24040040 */ 	addiu	$a0,$zero,0x40
/*  f19bf3c:	02802825 */ 	or	$a1,$s4,$zero
/*  f19bf40:	02403025 */ 	or	$a2,$s2,$zero
/*  f19bf44:	0fc66ed4 */ 	jal	func0f19bb50
/*  f19bf48:	02603825 */ 	or	$a3,$s3,$zero
/*  f19bf4c:	00409025 */ 	or	$s2,$v0,$zero
.L0f19bf50:
/*  f19bf50:	0253082a */ 	slt	$at,$s2,$s3
/*  f19bf54:	10200006 */ 	beqz	$at,.L0f19bf70
/*  f19bf58:	02401825 */ 	or	$v1,$s2,$zero
/*  f19bf5c:	02921021 */ 	addu	$v0,$s4,$s2
.L0f19bf60:
/*  f19bf60:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f19bf64:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f19bf68:	1473fffd */ 	bne	$v1,$s3,.L0f19bf60
/*  f19bf6c:	a040ffff */ 	sb	$zero,-0x1($v0)
.L0f19bf70:
/*  f19bf70:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f19bf74:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f19bf78:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f19bf7c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f19bf80:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f19bf84:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f19bf88:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f19bf8c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f19bf90:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f19bf94:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f19bf98:	03e00008 */ 	jr	$ra
/*  f19bf9c:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

void func0f19bfa0(void)
{
	s32 numsims = 0;
	s32 index = func0f19bb98(&g_MpSetup, var800acca0, 40);
	s32 i;

	for (i = 0; i < 8; i++) {
		s32 simtypeindex = mpGetSimTypeIndex(g_MpSimulants[i].base.simtype, SIMSKILL_NORMAL);

		if (simtypeindex >= 0) {
			s32 unlockvalue = g_MpSimulantTypes[simtypeindex].unlockvalue;

			if (unlockvalue) {
				index = func0f19bb50(unlockvalue, var800acca0, index, 40);
			}
		}

		simtypeindex = mpGetSimTypeIndex(SIMTYPE_GENERAL, g_MpSimulants[i].skill);

		if (simtypeindex >= 0) {
			s32 unlockvalue = g_MpSimulantTypes[simtypeindex].unlockvalue;

			if (unlockvalue) {
				index = func0f19bb50(unlockvalue, var800acca0, index, 40);
			}
		}

		if (simtypeindex >= 0) {
			numsims++;
		}

		if (g_MpSimulants[i].base.bodynum < ARRAYCOUNT(g_MpBodies)) {
			s32 unlockvalue = g_MpBodies[g_MpSimulants[i].base.bodynum].unlockvalue;

			if (unlockvalue) {
				index = func0f19bb50(unlockvalue, var800acca0, index, 40);
			}
		}

		if (g_MpSimulants[i].base.headnum < ARRAYCOUNT(g_MpHeads)) {
			s32 unlockvalue = g_MpHeads[g_MpSimulants[i].base.headnum].unlockvalue;

			if (unlockvalue) {
				index = func0f19bb50(unlockvalue, var800acca0, index, 40);
			}
		}
	}

	if (numsims > 4) {
		index = func0f19bb50(64, var800acca0, index, 40);
	}

	for (i = index; i < 40; i++) {
		var800acca0[i] = 0;
	}

	func0f19afdc();
}

void func0f19c190(void)
{
	s32 i;
	for (i = 0; i < 40; i++) {
		var800acca0[i] = 0;
	}

	func0f19afdc();
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

s32 mpGetNumChallengesAvailable(s32 mpchrnum)
{
	s32 challengeindex;
	s32 numavail = 0;

	for (challengeindex = 29; challengeindex >= 0; challengeindex--) {
		if (mpIsChallengeCompletedByChrWithNumPlayers(mpchrnum, challengeindex, 1) ||
				mpIsChallengeCompletedByChrWithNumPlayers(mpchrnum, challengeindex, 2) ||
				mpIsChallengeCompletedByChrWithNumPlayers(mpchrnum, challengeindex, 3) ||
				mpIsChallengeCompletedByChrWithNumPlayers(mpchrnum, challengeindex, 4)) {
			numavail = challengeindex + 1;
			break;
		}
	}

	if (numavail < 4) {
		numavail = 4;
	}

	return numavail;
}

char *mpChallengeGetNameWithArg(s32 arg0, s32 challengeindex)
{
	return langGet(g_MpChallenges[challengeindex].name);
}

bool func0f19c3bc(s32 mpchrnum, s32 index, s32 numplayers)
{
	return mpIsChallengeCompletedByChrWithNumPlayers(mpchrnum, index, numplayers);
}

bool mpIsChallengeCompletedByAnyChrWithNumPlayers(s32 index, s32 numplayers)
{
	return (g_MpChallenges[index].completions[numplayers] & 1) != 0;
}

void mpSetChallengeCompletedByAnyChrWithNumPlayers(s32 index, s32 numplayers, bool completed)
{
	if (completed) {
		g_MpChallenges[index].completions[numplayers] |= 1;
		return;
	}

	g_MpChallenges[index].completions[numplayers] &= ~1;
}

bool mpIsChallengeCompletedByChrWithNumPlayers(s32 mpchrnum, s32 index, s32 numplayers)
{
	return (g_MpChallenges[index].completions[numplayers] & (2 << mpchrnum)) != 0;
}

void mpSetChallengeCompletedByChrWithNumPlayers(u32 mpchrnum, s32 index, s32 numplayers, bool completed)
{
	if (completed) {
		g_MpChallenges[index].completions[numplayers] |= 2 << mpchrnum;
		return;
	}

	g_MpChallenges[index].completions[numplayers] &= ~(2 << mpchrnum);
}

GLOBAL_ASM(
glabel mpIsChallengeCompleteForEndscreen
/*  f19c53c:	27bdfec0 */ 	addiu	$sp,$sp,-320
/*  f19c540:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f19c544:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f19c548:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f19c54c:	8e0f006c */ 	lw	$t7,0x6c($s0)
/*  f19c550:	8e0e028c */ 	lw	$t6,0x28c($s0)
/*  f19c554:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f19c558:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f19c55c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f19c560:	afa00138 */ 	sw	$zero,0x138($sp)
/*  f19c564:	00009025 */ 	or	$s2,$zero,$zero
/*  f19c568:	00008825 */ 	or	$s1,$zero,$zero
/*  f19c56c:	11e00003 */ 	beqz	$t7,.L0f19c57c
/*  f19c570:	afae013c */ 	sw	$t6,0x13c($sp)
/*  f19c574:	10000002 */ 	b	.L0f19c580
/*  f19c578:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f19c57c:
/*  f19c57c:	00002825 */ 	or	$a1,$zero,$zero
.L0f19c580:
/*  f19c580:	8e180068 */ 	lw	$t8,0x68($s0)
/*  f19c584:	00002025 */ 	or	$a0,$zero,$zero
/*  f19c588:	00001825 */ 	or	$v1,$zero,$zero
/*  f19c58c:	13000003 */ 	beqz	$t8,.L0f19c59c
/*  f19c590:	00000000 */ 	nop
/*  f19c594:	10000001 */ 	b	.L0f19c59c
/*  f19c598:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f19c59c:
/*  f19c59c:	8e190064 */ 	lw	$t9,0x64($s0)
/*  f19c5a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f19c5a4:	13200003 */ 	beqz	$t9,.L0f19c5b4
/*  f19c5a8:	00000000 */ 	nop
/*  f19c5ac:	10000001 */ 	b	.L0f19c5b4
/*  f19c5b0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f19c5b4:
/*  f19c5b4:	8e080070 */ 	lw	$t0,0x70($s0)
/*  f19c5b8:	11000003 */ 	beqz	$t0,.L0f19c5c8
/*  f19c5bc:	00000000 */ 	nop
/*  f19c5c0:	10000001 */ 	b	.L0f19c5c8
/*  f19c5c4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19c5c8:
/*  f19c5c8:	00434821 */ 	addu	$t1,$v0,$v1
/*  f19c5cc:	01245021 */ 	addu	$t2,$t1,$a0
/*  f19c5d0:	01455821 */ 	addu	$t3,$t2,$a1
/*  f19c5d4:	19600027 */ 	blez	$t3,.L0f19c674
/*  f19c5d8:	00000000 */ 	nop
.L0f19c5dc:
/*  f19c5dc:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f19c5e0:	02202025 */ 	or	$a0,$s1,$zero
/*  f19c5e4:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f19c5e8:	00002825 */ 	or	$a1,$zero,$zero
/*  f19c5ec:	00002025 */ 	or	$a0,$zero,$zero
/*  f19c5f0:	8d8d048c */ 	lw	$t5,0x48c($t4)
/*  f19c5f4:	00001825 */ 	or	$v1,$zero,$zero
/*  f19c5f8:	00001025 */ 	or	$v0,$zero,$zero
/*  f19c5fc:	51a00003 */ 	beqzl	$t5,.L0f19c60c
/*  f19c600:	8e0e006c */ 	lw	$t6,0x6c($s0)
/*  f19c604:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f19c608:	8e0e006c */ 	lw	$t6,0x6c($s0)
.L0f19c60c:
/*  f19c60c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f19c610:	11c00003 */ 	beqz	$t6,.L0f19c620
/*  f19c614:	00000000 */ 	nop
/*  f19c618:	10000001 */ 	b	.L0f19c620
/*  f19c61c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f19c620:
/*  f19c620:	8e0f0068 */ 	lw	$t7,0x68($s0)
/*  f19c624:	11e00003 */ 	beqz	$t7,.L0f19c634
/*  f19c628:	00000000 */ 	nop
/*  f19c62c:	10000001 */ 	b	.L0f19c634
/*  f19c630:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f19c634:
/*  f19c634:	8e180064 */ 	lw	$t8,0x64($s0)
/*  f19c638:	13000003 */ 	beqz	$t8,.L0f19c648
/*  f19c63c:	00000000 */ 	nop
/*  f19c640:	10000001 */ 	b	.L0f19c648
/*  f19c644:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f19c648:
/*  f19c648:	8e190070 */ 	lw	$t9,0x70($s0)
/*  f19c64c:	13200003 */ 	beqz	$t9,.L0f19c65c
/*  f19c650:	00000000 */ 	nop
/*  f19c654:	10000001 */ 	b	.L0f19c65c
/*  f19c658:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19c65c:
/*  f19c65c:	00434021 */ 	addu	$t0,$v0,$v1
/*  f19c660:	01044821 */ 	addu	$t1,$t0,$a0
/*  f19c664:	01255021 */ 	addu	$t2,$t1,$a1
/*  f19c668:	022a082a */ 	slt	$at,$s1,$t2
/*  f19c66c:	1420ffdb */ 	bnez	$at,.L0f19c5dc
/*  f19c670:	00000000 */ 	nop
.L0f19c674:
/*  f19c674:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f19c678:	8fa4013c */ 	lw	$a0,0x13c($sp)
/*  f19c67c:	56400009 */ 	bnezl	$s2,.L0f19c6a4
/*  f19c680:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f19c684:	0fc622a1 */ 	jal	mpGetTeamRankings
/*  f19c688:	27a4003c */ 	addiu	$a0,$sp,0x3c
/*  f19c68c:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f19c690:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f19c694:	55600003 */ 	bnezl	$t3,.L0f19c6a4
/*  f19c698:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f19c69c:	afac0138 */ 	sw	$t4,0x138($sp)
/*  f19c6a0:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f19c6a4:
/*  f19c6a4:	8fa20138 */ 	lw	$v0,0x138($sp)
/*  f19c6a8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f19c6ac:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f19c6b0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f19c6b4:	03e00008 */ 	jr	$ra
/*  f19c6b8:	27bd0140 */ 	addiu	$sp,$sp,0x140
);

/**
 * This uses about 256 extra bytes of stack and passes it to mpGetTeamRankings.
 * Should decompile mpGetTeamRankings first.
 */
//bool mpIsChallengeCompleteForEndscreen(void)
//{
//	bool result = false;
//	bool aborting = false;
//	s32 i;
//	u32 prevplayernum = g_Vars.currentplayernum;
//
//	for (i = 0; i < PLAYERCOUNT(); i++) {
//		setCurrentPlayerNum(i);
//
//		if (g_Vars.currentplayer->aborted) {
//			aborting = true;
//		}
//	}
//
//	setCurrentPlayerNum(prevplayernum);
//
//	if (!aborting && mpGetTeamRankings() == 0) {
//		result = true;
//	}
//
//	return result;
//}

void mpConsiderMarkingCurrentChallengeComplete(void)
{
	bool result = mpIsChallengeCompleteForEndscreen();

	if (g_CheatsActiveBank0 == 0 && g_CheatsActiveBank1 == 0 && result) {
		u32 prevplayernum;
		s32 i;

		mpSetChallengeCompletedByAnyChrWithNumPlayers(g_MpChallengeIndex, PLAYERCOUNT(), 1);
		prevplayernum = g_Vars.currentplayernum;

		for (i = 0; i < PLAYERCOUNT(); i++) {
			setCurrentPlayerNum(i);
			mpSetChallengeCompletedByChrWithNumPlayers(g_Vars.currentplayerstats->mpindex, g_MpChallengeIndex, PLAYERCOUNT(), true);
		}

		setCurrentPlayerNum(prevplayernum);
		func0f19afdc();
	}
}

bool mpIsChallengeComplete(s32 challenge)
{
	if (challenge == 0) {
		return true;
	}

	return (g_MpChallengesCompleted[challenge] & 1) != 0;
}

bool mpIsChallengeCompleteWithNumPlayers(u32 numplayers, s32 challenge)
{
	if (challenge == 0) {
		return true;
	}

	return (g_MpChallengesCompleted[challenge] & (2 << numplayers)) != 0;
}

bool func0f19c96c(s32 challenge)
{
	if (challenge) {
		return false;
	}

	return true;
}
