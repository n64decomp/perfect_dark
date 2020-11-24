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

void mpForceUnlockSimulantFeatures2(struct mpsetupwrapper *wrapper, u8 *array, s32 len, s32 arg3)
{
	s32 index = mpForceUnlockSetupFeatures(&wrapper->setup, array, len);
	s32 featurenum;
	s32 i;
	s32 j;

	for (i = 0; i < 8; i++) {
		s32 simtype = mpGetSimTypeIndex(wrapper->things[i].simskill, SIMSKILL_NORMAL);

		if (simtype >= 0) {
			featurenum = g_MpSimulantTypes[simtype].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, array, index, len);
			}
		}

		for (j = 0; j < 4; j++) {
			simtype = mpGetSimTypeIndex(0, wrapper->things[i].simtypes[j]);

			if (simtype >= 0) {
				featurenum = g_MpSimulantTypes[simtype].requirefeature;

				if (featurenum) {
					index = mpForceUnlockFeature(featurenum, array, index, len);
				}
			}
		}

		if (wrapper->things[i].mpbodynum <= MPBODY_DJBOND) {
			featurenum = g_MpBodies[wrapper->things[i].mpbodynum].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, array, index, len);
			}
		}

		if (wrapper->things[i].mpheadnum <= MPHEAD_WINNER) {
			featurenum = g_MpHeads[wrapper->things[i].mpheadnum].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, array, index, len);
			}
		}
	}

	if (arg3 >= 25) {
		index = mpForceUnlockFeature(MPFEATURE_SIMSKILL_DARK, array, index, len);
	} else if (arg3 >= 20) {
		index = mpForceUnlockFeature(MPFEATURE_STAGE_CARPARK, array, index, len);
	} else if (arg3 > 14) {
		index = mpForceUnlockFeature(MPFEATURE_4D, array, index, len);
	}

	if (arg3 > 9) {
		index = mpForceUnlockFeature(MPFEATURE_8BOTS, array, index, len);
	}

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
		s32 simtypeindex = mpGetSimTypeIndex(g_MpSimulants[i].base.simtype, SIMSKILL_NORMAL);

		if (simtypeindex >= 0) {
			s32 featurenum = g_MpSimulantTypes[simtypeindex].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, g_MpFeaturesForceUnlocked, index, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
			}
		}

		// Force unlock the simulant skill
		simtypeindex = mpGetSimTypeIndex(SIMTYPE_GENERAL, g_MpSimulants[i].skill);

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
		if (g_MpSimulants[i].base.bodynum < ARRAYCOUNT(g_MpBodies)) {
			s32 featurenum = g_MpBodies[g_MpSimulants[i].base.bodynum].requirefeature;

			if (featurenum) {
				index = mpForceUnlockFeature(featurenum, g_MpFeaturesForceUnlocked, index, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
			}
		}

		// Force unlock the simulant's head
		if (g_MpSimulants[i].base.headnum < ARRAYCOUNT(g_MpHeads)) {
			s32 featurenum = g_MpHeads[g_MpSimulants[i].base.headnum].requirefeature;

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

	if (g_CheatsActiveBank0 == 0 && g_CheatsActiveBank1 == 0 && result) {
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
