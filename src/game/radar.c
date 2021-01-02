#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_096750.h"
#include "game/game_0b2150.h"
#include "game/game_0b3350.h"
#include "game/game_152fa0.h"
#include "game/game_1531a0.h"
#include "game/mplayer/scenarios.h"
#include "game/radar.h"
#include "game/pdoptions.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_16110.h"
#include "lib/lib_4a360.h"
#include "types.h"

const char var7f1b8dc0[] = "RadarDrawDot : Prop=%x";

const u32 var7f1b8dd8[] = {0x40490fdb};
const u32 var7f1b8ddc[] = {0x3b83126f};
const u32 var7f1b8de0[] = {0x3c8efa35};
const u32 var7f1b8de4[] = {0x00000000};
const u32 var7f1b8de8[] = {0x00000000};
const u32 var7f1b8dec[] = {0x00000000};

GLOBAL_ASM(
glabel func0f18e5a0
/*  f18e5a0:	3c018008 */ 	lui	$at,%hi(var80087cc0)
/*  f18e5a4:	03e00008 */ 	jr	$ra
/*  f18e5a8:	ac247cc0 */ 	sw	$a0,%lo(var80087cc0)($at)
);

Gfx *func0f18e5ac(Gfx *gdl, struct textureconfig *tconfig, s32 arg2, s32 arg3, s32 arg4)
{
	f32 spb0[2];
	f32 spa8[2];

	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureFilter(gdl++, G_TF_POINT);
	gDPSetTextureConvert(gdl++, G_TC_FILT);
	gDPSetTextureLUT(gdl++, G_TT_NONE);
	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
	gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
	gDPSetPrimColorViaWord(gdl++, 0, 0, 0x00000000);

	gDPFillRectangle(gdl++,
			arg2 * g_ScreenWidthMultiplier,
			arg3,
			(arg2 + tconfig->width) * g_ScreenWidthMultiplier,
			arg3 + tconfig->width);

	spb0[0] = arg2 * g_ScreenWidthMultiplier;
	spb0[1] = arg3;
	spa8[0] = arg4 * g_ScreenWidthMultiplier;
	spa8[1] = arg4;

	func0f0b39c0(&gdl, tconfig, 2, 0, 0, 1, 0);
	func0f0b278c(&gdl, spb0, spa8, tconfig->width, tconfig->height,
			0, 0, 1, 0, 0xff, 0, 40, tconfig->level > 0, 0);

	gDPPipeSync(gdl++);
	gDPSetColorDither(gdl++, G_CD_BAYER);
	gDPSetTexturePersp(gdl++, G_TP_PERSP);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_LOD);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);
	gDPSetTextureConvert(gdl++, G_TC_FILT);
	gDPSetTextureLUT(gdl++, G_TT_NONE);

	return gdl;
}

s32 radarGetTeamIndex(s32 team)
{
	s32 index = 0;

	if (team & 1) {
		index = 0;
	} else if (team & 0x02) {
		index = 1;
	} else if (team & 0x04) {
		index = 2;
	} else if (team & 0x08) {
		index = 3;
	} else if (team & 0x10) {
		index = 4;
	} else if (team & 0x20) {
		index = 5;
	} else if (team & 0x40) {
		index = 6;
	} else if (team & 0x80) {
		index = 7;
	}

	return index;
}

GLOBAL_ASM(
glabel radarDrawDot
/*  f18e9ec:	27bdff20 */ 	addiu	$sp,$sp,-224
/*  f18e9f0:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f18e9f4:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f18e9f8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f18e9fc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f18ea00:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f18ea04:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f18ea08:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f18ea0c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f18ea10:	afa700ec */ 	sw	$a3,0xec($sp)
/*  f18ea14:	00808025 */ 	or	$s0,$a0,$zero
/*  f18ea18:	00c09025 */ 	or	$s2,$a2,$zero
/*  f18ea1c:	00a0b025 */ 	or	$s6,$a1,$zero
/*  f18ea20:	c4ce0008 */ 	lwc1	$f14,0x8($a2)
/*  f18ea24:	0fc259d4 */ 	jal	func0f096750
/*  f18ea28:	c4cc0000 */ 	lwc1	$f12,0x0($a2)
/*  f18ea2c:	3c014334 */ 	lui	$at,0x4334
/*  f18ea30:	44818000 */ 	mtc1	$at,$f16
/*  f18ea34:	3c017f1c */ 	lui	$at,%hi(var7f1b8dd8)
/*  f18ea38:	c4268dd8 */ 	lwc1	$f6,%lo(var7f1b8dd8)($at)
/*  f18ea3c:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f18ea40:	3c15800a */ 	lui	$s5,%hi(g_Vars)
/*  f18ea44:	26b59fc0 */ 	addiu	$s5,$s5,%lo(g_Vars)
/*  f18ea48:	8eae0284 */ 	lw	$t6,0x284($s5)
/*  f18ea4c:	c5ca0144 */ 	lwc1	$f10,0x144($t6)
/*  f18ea50:	46062203 */ 	div.s	$f8,$f4,$f6
/*  f18ea54:	460a4480 */ 	add.s	$f18,$f8,$f10
/*  f18ea58:	46109100 */ 	add.s	$f4,$f18,$f16
/*  f18ea5c:	e7a400cc */ 	swc1	$f4,0xcc($sp)
/*  f18ea60:	c64e0008 */ 	lwc1	$f14,0x8($s2)
/*  f18ea64:	c6420000 */ 	lwc1	$f2,0x0($s2)
/*  f18ea68:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f18ea6c:	00000000 */ 	nop
/*  f18ea70:	46021202 */ 	mul.s	$f8,$f2,$f2
/*  f18ea74:	0c012974 */ 	jal	sqrtf
/*  f18ea78:	46083300 */ 	add.s	$f12,$f6,$f8
/*  f18ea7c:	3c014180 */ 	lui	$at,0x4180
/*  f18ea80:	44816000 */ 	mtc1	$at,$f12
/*  f18ea84:	3c017f1c */ 	lui	$at,%hi(var7f1b8ddc)
/*  f18ea88:	c42a8ddc */ 	lwc1	$f10,%lo(var7f1b8ddc)($at)
/*  f18ea8c:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f18ea90:	3c017f1c */ 	lui	$at,%hi(var7f1b8de0)
/*  f18ea94:	460a0382 */ 	mul.s	$f14,$f0,$f10
/*  f18ea98:	c7b200cc */ 	lwc1	$f18,0xcc($sp)
/*  f18ea9c:	460c703c */ 	c.lt.s	$f14,$f12
/*  f18eaa0:	00000000 */ 	nop
/*  f18eaa4:	45020004 */ 	bc1fl	.L0f18eab8
/*  f18eaa8:	46006386 */ 	mov.s	$f14,$f12
/*  f18eaac:	10000002 */ 	b	.L0f18eab8
/*  f18eab0:	00009825 */ 	or	$s3,$zero,$zero
/*  f18eab4:	46006386 */ 	mov.s	$f14,$f12
.L0f18eab8:
/*  f18eab8:	c4248de0 */ 	lwc1	$f4,%lo(var7f1b8de0)($at)
/*  f18eabc:	e7ae00d0 */ 	swc1	$f14,0xd0($sp)
/*  f18eac0:	46049302 */ 	mul.s	$f12,$f18,$f4
/*  f18eac4:	0c0068f7 */ 	jal	sinf
/*  f18eac8:	e7ac0048 */ 	swc1	$f12,0x48($sp)
/*  f18eacc:	c7ae00d0 */ 	lwc1	$f14,0xd0($sp)
/*  f18ead0:	3c19800b */ 	lui	$t9,%hi(g_RadarX)
/*  f18ead4:	8f39cc70 */ 	lw	$t9,%lo(g_RadarX)($t9)
/*  f18ead8:	460e0182 */ 	mul.s	$f6,$f0,$f14
/*  f18eadc:	c7ac0048 */ 	lwc1	$f12,0x48($sp)
/*  f18eae0:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f18eae4:	44184000 */ 	mfc1	$t8,$f8
/*  f18eae8:	0c0068f4 */ 	jal	cosf
/*  f18eaec:	03198821 */ 	addu	$s1,$t8,$t9
/*  f18eaf0:	c7ae00d0 */ 	lwc1	$f14,0xd0($sp)
/*  f18eaf4:	8fac00f4 */ 	lw	$t4,0xf4($sp)
/*  f18eaf8:	3c0b800b */ 	lui	$t3,%hi(g_RadarY)
/*  f18eafc:	460e0282 */ 	mul.s	$f10,$f0,$f14
/*  f18eb00:	8d6bcc74 */ 	lw	$t3,%lo(g_RadarY)($t3)
/*  f18eb04:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f18eb08:	440a9000 */ 	mfc1	$t2,$f18
/*  f18eb0c:	118001a8 */ 	beqz	$t4,.L0f18f1b0
/*  f18eb10:	014ba021 */ 	addu	$s4,$t2,$t3
/*  f18eb14:	8ead0284 */ 	lw	$t5,0x284($s5)
/*  f18eb18:	02002025 */ 	or	$a0,$s0,$zero
/*  f18eb1c:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f18eb20:	8dae00bc */ 	lw	$t6,0xbc($t5)
/*  f18eb24:	8fb800ec */ 	lw	$t8,0xec($sp)
/*  f18eb28:	3c028008 */ 	lui	$v0,%hi(var80087cc0)
/*  f18eb2c:	16ce0086 */ 	bne	$s6,$t6,.L0f18ed48
/*  f18eb30:	00000000 */ 	nop
/*  f18eb34:	026f9007 */ 	srav	$s2,$t7,$s3
/*  f18eb38:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f18eb3c:	02582821 */ 	addu	$a1,$s2,$t8
/*  f18eb40:	3c108008 */ 	lui	$s0,%hi(g_ScreenWidthMultiplier)
/*  f18eb44:	2610fac0 */ 	addiu	$s0,$s0,%lo(g_ScreenWidthMultiplier)
/*  f18eb48:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18eb4c:	26350001 */ 	addiu	$s5,$s1,0x1
/*  f18eb50:	268d0003 */ 	addiu	$t5,$s4,0x3
/*  f18eb54:	02b90019 */ 	multu	$s5,$t9
/*  f18eb58:	3c13f600 */ 	lui	$s3,0xf600
/*  f18eb5c:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f18eb60:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f18eb64:	2636fffe */ 	addiu	$s6,$s1,-2
/*  f18eb68:	26880002 */ 	addiu	$t0,$s4,0x2
/*  f18eb6c:	311903ff */ 	andi	$t9,$t0,0x3ff
/*  f18eb70:	00194080 */ 	sll	$t0,$t9,0x2
/*  f18eb74:	2687ffff */ 	addiu	$a3,$s4,-1
/*  f18eb78:	24440018 */ 	addiu	$a0,$v0,0x18
/*  f18eb7c:	00004812 */ 	mflo	$t1
/*  f18eb80:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f18eb84:	000a5b80 */ 	sll	$t3,$t2,0xe
/*  f18eb88:	01736025 */ 	or	$t4,$t3,$s3
/*  f18eb8c:	018fc025 */ 	or	$t8,$t4,$t7
/*  f18eb90:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f18eb94:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f18eb98:	262f0002 */ 	addiu	$t7,$s1,0x2
/*  f18eb9c:	02ca0019 */ 	multu	$s6,$t2
/*  f18eba0:	00005812 */ 	mflo	$t3
/*  f18eba4:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f18eba8:	000d7380 */ 	sll	$t6,$t5,0xe
/*  f18ebac:	01c86025 */ 	or	$t4,$t6,$t0
/*  f18ebb0:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f18ebb4:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18ebb8:	30ee03ff */ 	andi	$t6,$a3,0x3ff
/*  f18ebbc:	000e3880 */ 	sll	$a3,$t6,0x2
/*  f18ebc0:	01f80019 */ 	multu	$t7,$t8
/*  f18ebc4:	262ffffd */ 	addiu	$t7,$s1,-3
/*  f18ebc8:	0000c812 */ 	mflo	$t9
/*  f18ebcc:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f18ebd0:	00095380 */ 	sll	$t2,$t1,0xe
/*  f18ebd4:	01535825 */ 	or	$t3,$t2,$s3
/*  f18ebd8:	01686825 */ 	or	$t5,$t3,$t0
/*  f18ebdc:	ac4d0008 */ 	sw	$t5,0x8($v0)
/*  f18ebe0:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18ebe4:	01f80019 */ 	multu	$t7,$t8
/*  f18ebe8:	0000c812 */ 	mflo	$t9
/*  f18ebec:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f18ebf0:	00095380 */ 	sll	$t2,$t1,0xe
/*  f18ebf4:	01475825 */ 	or	$t3,$t2,$a3
/*  f18ebf8:	ac4b000c */ 	sw	$t3,0xc($v0)
/*  f18ebfc:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18ec00:	02ad0019 */ 	multu	$s5,$t5
/*  f18ec04:	00007012 */ 	mflo	$t6
/*  f18ec08:	31cc03ff */ 	andi	$t4,$t6,0x3ff
/*  f18ec0c:	000c7b80 */ 	sll	$t7,$t4,0xe
/*  f18ec10:	01f3c025 */ 	or	$t8,$t7,$s3
/*  f18ec14:	0307c825 */ 	or	$t9,$t8,$a3
/*  f18ec18:	ac590010 */ 	sw	$t9,0x10($v0)
/*  f18ec1c:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18ec20:	268efffe */ 	addiu	$t6,$s4,-2
/*  f18ec24:	31cc03ff */ 	andi	$t4,$t6,0x3ff
/*  f18ec28:	02c90019 */ 	multu	$s6,$t1
/*  f18ec2c:	000c7880 */ 	sll	$t7,$t4,0x2
/*  f18ec30:	00005012 */ 	mflo	$t2
/*  f18ec34:	314b03ff */ 	andi	$t3,$t2,0x3ff
/*  f18ec38:	000b6b80 */ 	sll	$t5,$t3,0xe
/*  f18ec3c:	01afc025 */ 	or	$t8,$t5,$t7
/*  f18ec40:	ac580014 */ 	sw	$t8,0x14($v0)
/*  f18ec44:	afa8003c */ 	sw	$t0,0x3c($sp)
/*  f18ec48:	0fc54e0e */ 	jal	func0f153838
/*  f18ec4c:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f18ec50:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f18ec54:	00402025 */ 	or	$a0,$v0,$zero
/*  f18ec58:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f18ec5c:	02592821 */ 	addu	$a1,$s2,$t9
/*  f18ec60:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18ec64:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*  f18ec68:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f18ec6c:	02290019 */ 	multu	$s1,$t1
/*  f18ec70:	2625ffff */ 	addiu	$a1,$s1,-1
/*  f18ec74:	26860001 */ 	addiu	$a2,$s4,0x1
/*  f18ec78:	30cf03ff */ 	andi	$t7,$a2,0x3ff
/*  f18ec7c:	000f3080 */ 	sll	$a2,$t7,0x2
/*  f18ec80:	328303ff */ 	andi	$v1,$s4,0x3ff
/*  f18ec84:	24440018 */ 	addiu	$a0,$v0,0x18
/*  f18ec88:	00005012 */ 	mflo	$t2
/*  f18ec8c:	314b03ff */ 	andi	$t3,$t2,0x3ff
/*  f18ec90:	000b7380 */ 	sll	$t6,$t3,0xe
/*  f18ec94:	01d36025 */ 	or	$t4,$t6,$s3
/*  f18ec98:	01886825 */ 	or	$t5,$t4,$t0
/*  f18ec9c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f18eca0:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18eca4:	00b90019 */ 	multu	$a1,$t9
/*  f18eca8:	00004812 */ 	mflo	$t1
/*  f18ecac:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f18ecb0:	000a5b80 */ 	sll	$t3,$t2,0xe
/*  f18ecb4:	01667025 */ 	or	$t6,$t3,$a2
/*  f18ecb8:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f18ecbc:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18ecc0:	00035080 */ 	sll	$t2,$v1,0x2
/*  f18ecc4:	01401825 */ 	or	$v1,$t2,$zero
/*  f18ecc8:	02ac0019 */ 	multu	$s5,$t4
/*  f18eccc:	00006812 */ 	mflo	$t5
/*  f18ecd0:	31af03ff */ 	andi	$t7,$t5,0x3ff
/*  f18ecd4:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f18ecd8:	0313c825 */ 	or	$t9,$t8,$s3
/*  f18ecdc:	03264825 */ 	or	$t1,$t9,$a2
/*  f18ece0:	ac490008 */ 	sw	$t1,0x8($v0)
/*  f18ece4:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18ece8:	02cb0019 */ 	multu	$s6,$t3
/*  f18ecec:	00007012 */ 	mflo	$t6
/*  f18ecf0:	31cc03ff */ 	andi	$t4,$t6,0x3ff
/*  f18ecf4:	000c6b80 */ 	sll	$t5,$t4,0xe
/*  f18ecf8:	01aa7825 */ 	or	$t7,$t5,$t2
/*  f18ecfc:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f18ed00:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18ed04:	02380019 */ 	multu	$s1,$t8
/*  f18ed08:	0000c812 */ 	mflo	$t9
/*  f18ed0c:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f18ed10:	00095380 */ 	sll	$t2,$t1,0xe
/*  f18ed14:	01535825 */ 	or	$t3,$t2,$s3
/*  f18ed18:	01637025 */ 	or	$t6,$t3,$v1
/*  f18ed1c:	ac4e0010 */ 	sw	$t6,0x10($v0)
/*  f18ed20:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18ed24:	00ac0019 */ 	multu	$a1,$t4
/*  f18ed28:	00006812 */ 	mflo	$t5
/*  f18ed2c:	31af03ff */ 	andi	$t7,$t5,0x3ff
/*  f18ed30:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f18ed34:	0307c825 */ 	or	$t9,$t8,$a3
/*  f18ed38:	0fc54e0e */ 	jal	func0f153838
/*  f18ed3c:	ac590014 */ 	sw	$t9,0x14($v0)
/*  f18ed40:	100002c1 */ 	b	.L0f18f848
/*  f18ed44:	00408025 */ 	or	$s0,$v0,$zero
.L0f18ed48:
/*  f18ed48:	8c427cc0 */ 	lw	$v0,%lo(var80087cc0)($v0)
/*  f18ed4c:	3c01437a */ 	lui	$at,0x437a
/*  f18ed50:	1040006b */ 	beqz	$v0,.L0f18ef00
/*  f18ed54:	00000000 */ 	nop
/*  f18ed58:	44812000 */ 	mtc1	$at,$f4
/*  f18ed5c:	c6460004 */ 	lwc1	$f6,0x4($s2)
/*  f18ed60:	02002025 */ 	or	$a0,$s0,$zero
/*  f18ed64:	240900ff */ 	addiu	$t1,$zero,0xff
/*  f18ed68:	4606203c */ 	c.lt.s	$f4,$f6
/*  f18ed6c:	8faa00ec */ 	lw	$t2,0xec($sp)
/*  f18ed70:	45000063 */ 	bc1f	.L0f18ef00
/*  f18ed74:	00000000 */ 	nop
/*  f18ed78:	02699007 */ 	srav	$s2,$t1,$s3
/*  f18ed7c:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f18ed80:	024a2821 */ 	addu	$a1,$s2,$t2
/*  f18ed84:	3c108008 */ 	lui	$s0,%hi(g_ScreenWidthMultiplier)
/*  f18ed88:	2610fac0 */ 	addiu	$s0,$s0,%lo(g_ScreenWidthMultiplier)
/*  f18ed8c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18ed90:	262b0002 */ 	addiu	$t3,$s1,0x2
/*  f18ed94:	26990002 */ 	addiu	$t9,$s4,0x2
/*  f18ed98:	016e0019 */ 	multu	$t3,$t6
/*  f18ed9c:	3c13f600 */ 	lui	$s3,0xf600
/*  f18eda0:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f18eda4:	00095080 */ 	sll	$t2,$t1,0x2
/*  f18eda8:	2687ffff */ 	addiu	$a3,$s4,-1
/*  f18edac:	30ee03ff */ 	andi	$t6,$a3,0x3ff
/*  f18edb0:	000e3880 */ 	sll	$a3,$t6,0x2
/*  f18edb4:	26350001 */ 	addiu	$s5,$s1,0x1
/*  f18edb8:	2636fffe */ 	addiu	$s6,$s1,-2
/*  f18edbc:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18edc0:	00006012 */ 	mflo	$t4
/*  f18edc4:	318d03ff */ 	andi	$t5,$t4,0x3ff
/*  f18edc8:	000d7b80 */ 	sll	$t7,$t5,0xe
/*  f18edcc:	01f3c025 */ 	or	$t8,$t7,$s3
/*  f18edd0:	030a5825 */ 	or	$t3,$t8,$t2
/*  f18edd4:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f18edd8:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f18eddc:	262dfffd */ 	addiu	$t5,$s1,-3
/*  f18ede0:	01af0019 */ 	multu	$t5,$t7
/*  f18ede4:	0000c812 */ 	mflo	$t9
/*  f18ede8:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f18edec:	0009c380 */ 	sll	$t8,$t1,0xe
/*  f18edf0:	03075025 */ 	or	$t2,$t8,$a3
/*  f18edf4:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f18edf8:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18edfc:	02ab0019 */ 	multu	$s5,$t3
/*  f18ee00:	00007012 */ 	mflo	$t6
/*  f18ee04:	31cc03ff */ 	andi	$t4,$t6,0x3ff
/*  f18ee08:	000c6b80 */ 	sll	$t5,$t4,0xe
/*  f18ee0c:	01b37825 */ 	or	$t7,$t5,$s3
/*  f18ee10:	01e7c825 */ 	or	$t9,$t7,$a3
/*  f18ee14:	ac590008 */ 	sw	$t9,0x8($v0)
/*  f18ee18:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18ee1c:	268efffe */ 	addiu	$t6,$s4,-2
/*  f18ee20:	31cc03ff */ 	andi	$t4,$t6,0x3ff
/*  f18ee24:	02c90019 */ 	multu	$s6,$t1
/*  f18ee28:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f18ee2c:	0000c012 */ 	mflo	$t8
/*  f18ee30:	330a03ff */ 	andi	$t2,$t8,0x3ff
/*  f18ee34:	000a5b80 */ 	sll	$t3,$t2,0xe
/*  f18ee38:	016d7825 */ 	or	$t7,$t3,$t5
/*  f18ee3c:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f18ee40:	0fc54e0e */ 	jal	func0f153838
/*  f18ee44:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f18ee48:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f18ee4c:	00402025 */ 	or	$a0,$v0,$zero
/*  f18ee50:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f18ee54:	02592821 */ 	addu	$a1,$s2,$t9
/*  f18ee58:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18ee5c:	268b0001 */ 	addiu	$t3,$s4,0x1
/*  f18ee60:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f18ee64:	02a90019 */ 	multu	$s5,$t1
/*  f18ee68:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f18ee6c:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f18ee70:	328303ff */ 	andi	$v1,$s4,0x3ff
/*  f18ee74:	00034880 */ 	sll	$t1,$v1,0x2
/*  f18ee78:	01201825 */ 	or	$v1,$t1,$zero
/*  f18ee7c:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18ee80:	0000c012 */ 	mflo	$t8
/*  f18ee84:	330a03ff */ 	andi	$t2,$t8,0x3ff
/*  f18ee88:	000a7380 */ 	sll	$t6,$t2,0xe
/*  f18ee8c:	01d36025 */ 	or	$t4,$t6,$s3
/*  f18ee90:	018fc825 */ 	or	$t9,$t4,$t7
/*  f18ee94:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f18ee98:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18ee9c:	02d80019 */ 	multu	$s6,$t8
/*  f18eea0:	00005012 */ 	mflo	$t2
/*  f18eea4:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f18eea8:	000e5b80 */ 	sll	$t3,$t6,0xe
/*  f18eeac:	01696825 */ 	or	$t5,$t3,$t1
/*  f18eeb0:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f18eeb4:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18eeb8:	262effff */ 	addiu	$t6,$s1,-1
/*  f18eebc:	022c0019 */ 	multu	$s1,$t4
/*  f18eec0:	00007812 */ 	mflo	$t7
/*  f18eec4:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f18eec8:	00194b80 */ 	sll	$t1,$t9,0xe
/*  f18eecc:	0133c025 */ 	or	$t8,$t1,$s3
/*  f18eed0:	03035025 */ 	or	$t2,$t8,$v1
/*  f18eed4:	ac4a0008 */ 	sw	$t2,0x8($v0)
/*  f18eed8:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18eedc:	01cb0019 */ 	multu	$t6,$t3
/*  f18eee0:	00006812 */ 	mflo	$t5
/*  f18eee4:	31ac03ff */ 	andi	$t4,$t5,0x3ff
/*  f18eee8:	000c7b80 */ 	sll	$t7,$t4,0xe
/*  f18eeec:	01e7c825 */ 	or	$t9,$t7,$a3
/*  f18eef0:	0fc54e0e */ 	jal	func0f153838
/*  f18eef4:	ac59000c */ 	sw	$t9,0xc($v0)
/*  f18eef8:	10000253 */ 	b	.L0f18f848
/*  f18eefc:	00408025 */ 	or	$s0,$v0,$zero
.L0f18ef00:
/*  f18ef00:	1040006a */ 	beqz	$v0,.L0f18f0ac
/*  f18ef04:	3c01c37a */ 	lui	$at,0xc37a
/*  f18ef08:	c6480004 */ 	lwc1	$f8,0x4($s2)
/*  f18ef0c:	44815000 */ 	mtc1	$at,$f10
/*  f18ef10:	02002025 */ 	or	$a0,$s0,$zero
/*  f18ef14:	240900ff */ 	addiu	$t1,$zero,0xff
/*  f18ef18:	460a403c */ 	c.lt.s	$f8,$f10
/*  f18ef1c:	8fb800ec */ 	lw	$t8,0xec($sp)
/*  f18ef20:	45000062 */ 	bc1f	.L0f18f0ac
/*  f18ef24:	02699007 */ 	srav	$s2,$t1,$s3
/*  f18ef28:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f18ef2c:	02582821 */ 	addu	$a1,$s2,$t8
/*  f18ef30:	3c108008 */ 	lui	$s0,%hi(g_ScreenWidthMultiplier)
/*  f18ef34:	2610fac0 */ 	addiu	$s0,$s0,%lo(g_ScreenWidthMultiplier)
/*  f18ef38:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18ef3c:	262b0002 */ 	addiu	$t3,$s1,0x2
/*  f18ef40:	26860001 */ 	addiu	$a2,$s4,0x1
/*  f18ef44:	016d0019 */ 	multu	$t3,$t5
/*  f18ef48:	3c13f600 */ 	lui	$s3,0xf600
/*  f18ef4c:	30ca03ff */ 	andi	$t2,$a2,0x3ff
/*  f18ef50:	000a3080 */ 	sll	$a2,$t2,0x2
/*  f18ef54:	262afffd */ 	addiu	$t2,$s1,-3
/*  f18ef58:	26350001 */ 	addiu	$s5,$s1,0x1
/*  f18ef5c:	2636fffe */ 	addiu	$s6,$s1,-2
/*  f18ef60:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18ef64:	00006012 */ 	mflo	$t4
/*  f18ef68:	318f03ff */ 	andi	$t7,$t4,0x3ff
/*  f18ef6c:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f18ef70:	03334825 */ 	or	$t1,$t9,$s3
/*  f18ef74:	0126c025 */ 	or	$t8,$t1,$a2
/*  f18ef78:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f18ef7c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18ef80:	268ffffe */ 	addiu	$t7,$s4,-2
/*  f18ef84:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f18ef88:	014e0019 */ 	multu	$t2,$t6
/*  f18ef8c:	00194880 */ 	sll	$t1,$t9,0x2
/*  f18ef90:	26990002 */ 	addiu	$t9,$s4,0x2
/*  f18ef94:	00005812 */ 	mflo	$t3
/*  f18ef98:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f18ef9c:	000d6380 */ 	sll	$t4,$t5,0xe
/*  f18efa0:	0189c025 */ 	or	$t8,$t4,$t1
/*  f18efa4:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f18efa8:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f18efac:	332c03ff */ 	andi	$t4,$t9,0x3ff
/*  f18efb0:	000c4880 */ 	sll	$t1,$t4,0x2
/*  f18efb4:	02aa0019 */ 	multu	$s5,$t2
/*  f18efb8:	00007012 */ 	mflo	$t6
/*  f18efbc:	31cb03ff */ 	andi	$t3,$t6,0x3ff
/*  f18efc0:	000b6b80 */ 	sll	$t5,$t3,0xe
/*  f18efc4:	01b37825 */ 	or	$t7,$t5,$s3
/*  f18efc8:	01e9c025 */ 	or	$t8,$t7,$t1
/*  f18efcc:	ac580008 */ 	sw	$t8,0x8($v0)
/*  f18efd0:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f18efd4:	02ca0019 */ 	multu	$s6,$t2
/*  f18efd8:	00007012 */ 	mflo	$t6
/*  f18efdc:	31cb03ff */ 	andi	$t3,$t6,0x3ff
/*  f18efe0:	000b6b80 */ 	sll	$t5,$t3,0xe
/*  f18efe4:	01a6c825 */ 	or	$t9,$t5,$a2
/*  f18efe8:	ac59000c */ 	sw	$t9,0xc($v0)
/*  f18efec:	0fc54e0e */ 	jal	func0f153838
/*  f18eff0:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f18eff4:	8fac00f0 */ 	lw	$t4,0xf0($sp)
/*  f18eff8:	00402025 */ 	or	$a0,$v0,$zero
/*  f18effc:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f18f000:	024c2821 */ 	addu	$a1,$s2,$t4
/*  f18f004:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18f008:	328303ff */ 	andi	$v1,$s4,0x3ff
/*  f18f00c:	00037880 */ 	sll	$t7,$v1,0x2
/*  f18f010:	02a90019 */ 	multu	$s5,$t1
/*  f18f014:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*  f18f018:	01e01825 */ 	or	$v1,$t7,$zero
/*  f18f01c:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18f020:	0000c012 */ 	mflo	$t8
/*  f18f024:	330a03ff */ 	andi	$t2,$t8,0x3ff
/*  f18f028:	000a7380 */ 	sll	$t6,$t2,0xe
/*  f18f02c:	01d35825 */ 	or	$t3,$t6,$s3
/*  f18f030:	016f6825 */ 	or	$t5,$t3,$t7
/*  f18f034:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f18f038:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18f03c:	2698ffff */ 	addiu	$t8,$s4,-1
/*  f18f040:	330a03ff */ 	andi	$t2,$t8,0x3ff
/*  f18f044:	02d90019 */ 	multu	$s6,$t9
/*  f18f048:	000a7080 */ 	sll	$t6,$t2,0x2
/*  f18f04c:	00006012 */ 	mflo	$t4
/*  f18f050:	318f03ff */ 	andi	$t7,$t4,0x3ff
/*  f18f054:	000f4b80 */ 	sll	$t1,$t7,0xe
/*  f18f058:	012e5825 */ 	or	$t3,$t1,$t6
/*  f18f05c:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f18f060:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18f064:	2629ffff */ 	addiu	$t1,$s1,-1
/*  f18f068:	022d0019 */ 	multu	$s1,$t5
/*  f18f06c:	0000c812 */ 	mflo	$t9
/*  f18f070:	332c03ff */ 	andi	$t4,$t9,0x3ff
/*  f18f074:	000c7b80 */ 	sll	$t7,$t4,0xe
/*  f18f078:	01f3c025 */ 	or	$t8,$t7,$s3
/*  f18f07c:	03065025 */ 	or	$t2,$t8,$a2
/*  f18f080:	ac4a0008 */ 	sw	$t2,0x8($v0)
/*  f18f084:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18f088:	012e0019 */ 	multu	$t1,$t6
/*  f18f08c:	00005812 */ 	mflo	$t3
/*  f18f090:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f18f094:	000dcb80 */ 	sll	$t9,$t5,0xe
/*  f18f098:	03236025 */ 	or	$t4,$t9,$v1
/*  f18f09c:	0fc54e0e */ 	jal	func0f153838
/*  f18f0a0:	ac4c000c */ 	sw	$t4,0xc($v0)
/*  f18f0a4:	100001e8 */ 	b	.L0f18f848
/*  f18f0a8:	00408025 */ 	or	$s0,$v0,$zero
.L0f18f0ac:
/*  f18f0ac:	8fb800ec */ 	lw	$t8,0xec($sp)
/*  f18f0b0:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f18f0b4:	026f9007 */ 	srav	$s2,$t7,$s3
/*  f18f0b8:	02002025 */ 	or	$a0,$s0,$zero
/*  f18f0bc:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f18f0c0:	02582821 */ 	addu	$a1,$s2,$t8
/*  f18f0c4:	3c108008 */ 	lui	$s0,%hi(g_ScreenWidthMultiplier)
/*  f18f0c8:	2610fac0 */ 	addiu	$s0,$s0,%lo(g_ScreenWidthMultiplier)
/*  f18f0cc:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18f0d0:	262a0002 */ 	addiu	$t2,$s1,0x2
/*  f18f0d4:	268c0002 */ 	addiu	$t4,$s4,0x2
/*  f18f0d8:	01490019 */ 	multu	$t2,$t1
/*  f18f0dc:	3c13f600 */ 	lui	$s3,0xf600
/*  f18f0e0:	318f03ff */ 	andi	$t7,$t4,0x3ff
/*  f18f0e4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f18f0e8:	2629fffe */ 	addiu	$t1,$s1,-2
/*  f18f0ec:	268ffffe */ 	addiu	$t7,$s4,-2
/*  f18f0f0:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f18f0f4:	00007012 */ 	mflo	$t6
/*  f18f0f8:	31cb03ff */ 	andi	$t3,$t6,0x3ff
/*  f18f0fc:	000b6b80 */ 	sll	$t5,$t3,0xe
/*  f18f100:	01b3c825 */ 	or	$t9,$t5,$s3
/*  f18f104:	03385025 */ 	or	$t2,$t9,$t8
/*  f18f108:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f18f10c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18f110:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f18f114:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f18f118:	012e0019 */ 	multu	$t1,$t6
/*  f18f11c:	00005812 */ 	mflo	$t3
/*  f18f120:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f18f124:	000d6380 */ 	sll	$t4,$t5,0xe
/*  f18f128:	01985025 */ 	or	$t2,$t4,$t8
/*  f18f12c:	0fc54e0e */ 	jal	func0f153838
/*  f18f130:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f18f134:	8fa900f0 */ 	lw	$t1,0xf0($sp)
/*  f18f138:	00402025 */ 	or	$a0,$v0,$zero
/*  f18f13c:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f18f140:	02492821 */ 	addu	$a1,$s2,$t1
/*  f18f144:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18f148:	262e0001 */ 	addiu	$t6,$s1,0x1
/*  f18f14c:	26980001 */ 	addiu	$t8,$s4,0x1
/*  f18f150:	01cb0019 */ 	multu	$t6,$t3
/*  f18f154:	330a03ff */ 	andi	$t2,$t8,0x3ff
/*  f18f158:	000a4880 */ 	sll	$t1,$t2,0x2
/*  f18f15c:	262bffff */ 	addiu	$t3,$s1,-1
/*  f18f160:	268affff */ 	addiu	$t2,$s4,-1
/*  f18f164:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f18f168:	00006812 */ 	mflo	$t5
/*  f18f16c:	31af03ff */ 	andi	$t7,$t5,0x3ff
/*  f18f170:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f18f174:	03336025 */ 	or	$t4,$t9,$s3
/*  f18f178:	01897025 */ 	or	$t6,$t4,$t1
/*  f18f17c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f18f180:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18f184:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f18f188:	000c4880 */ 	sll	$t1,$t4,0x2
/*  f18f18c:	016d0019 */ 	multu	$t3,$t5
/*  f18f190:	00007812 */ 	mflo	$t7
/*  f18f194:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f18f198:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f18f19c:	03097025 */ 	or	$t6,$t8,$t1
/*  f18f1a0:	0fc54e0e */ 	jal	func0f153838
/*  f18f1a4:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f18f1a8:	100001a7 */ 	b	.L0f18f848
/*  f18f1ac:	00408025 */ 	or	$s0,$v0,$zero
.L0f18f1b0:
/*  f18f1b0:	8eab0284 */ 	lw	$t3,0x284($s5)
/*  f18f1b4:	02002025 */ 	or	$a0,$s0,$zero
/*  f18f1b8:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f18f1bc:	8d6d00bc */ 	lw	$t5,0xbc($t3)
/*  f18f1c0:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f18f1c4:	3c028008 */ 	lui	$v0,%hi(var80087cc0)
/*  f18f1c8:	16cd0086 */ 	bne	$s6,$t5,.L0f18f3e4
/*  f18f1cc:	00000000 */ 	nop
/*  f18f1d0:	026f9007 */ 	srav	$s2,$t7,$s3
/*  f18f1d4:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f18f1d8:	02592821 */ 	addu	$a1,$s2,$t9
/*  f18f1dc:	3c108008 */ 	lui	$s0,%hi(g_ScreenWidthMultiplier)
/*  f18f1e0:	2610fac0 */ 	addiu	$s0,$s0,%lo(g_ScreenWidthMultiplier)
/*  f18f1e4:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f18f1e8:	26350001 */ 	addiu	$s5,$s1,0x1
/*  f18f1ec:	268b0003 */ 	addiu	$t3,$s4,0x3
/*  f18f1f0:	02aa0019 */ 	multu	$s5,$t2
/*  f18f1f4:	3c13f600 */ 	lui	$s3,0xf600
/*  f18f1f8:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f18f1fc:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f18f200:	2636fffe */ 	addiu	$s6,$s1,-2
/*  f18f204:	26880002 */ 	addiu	$t0,$s4,0x2
/*  f18f208:	310a03ff */ 	andi	$t2,$t0,0x3ff
/*  f18f20c:	000a4080 */ 	sll	$t0,$t2,0x2
/*  f18f210:	2687ffff */ 	addiu	$a3,$s4,-1
/*  f18f214:	24440018 */ 	addiu	$a0,$v0,0x18
/*  f18f218:	00006012 */ 	mflo	$t4
/*  f18f21c:	319803ff */ 	andi	$t8,$t4,0x3ff
/*  f18f220:	00184b80 */ 	sll	$t1,$t8,0xe
/*  f18f224:	01337025 */ 	or	$t6,$t1,$s3
/*  f18f228:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f18f22c:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f18f230:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18f234:	262f0002 */ 	addiu	$t7,$s1,0x2
/*  f18f238:	02d80019 */ 	multu	$s6,$t8
/*  f18f23c:	00004812 */ 	mflo	$t1
/*  f18f240:	312b03ff */ 	andi	$t3,$t1,0x3ff
/*  f18f244:	000b6b80 */ 	sll	$t5,$t3,0xe
/*  f18f248:	01a87025 */ 	or	$t6,$t5,$t0
/*  f18f24c:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f18f250:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18f254:	30ed03ff */ 	andi	$t5,$a3,0x3ff
/*  f18f258:	000d3880 */ 	sll	$a3,$t5,0x2
/*  f18f25c:	01f90019 */ 	multu	$t7,$t9
/*  f18f260:	262ffffd */ 	addiu	$t7,$s1,-3
/*  f18f264:	00005012 */ 	mflo	$t2
/*  f18f268:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f18f26c:	000cc380 */ 	sll	$t8,$t4,0xe
/*  f18f270:	03134825 */ 	or	$t1,$t8,$s3
/*  f18f274:	01285825 */ 	or	$t3,$t1,$t0
/*  f18f278:	ac4b0008 */ 	sw	$t3,0x8($v0)
/*  f18f27c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18f280:	01f90019 */ 	multu	$t7,$t9
/*  f18f284:	00005012 */ 	mflo	$t2
/*  f18f288:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f18f28c:	000cc380 */ 	sll	$t8,$t4,0xe
/*  f18f290:	03074825 */ 	or	$t1,$t8,$a3
/*  f18f294:	ac49000c */ 	sw	$t1,0xc($v0)
/*  f18f298:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18f29c:	02ab0019 */ 	multu	$s5,$t3
/*  f18f2a0:	00006812 */ 	mflo	$t5
/*  f18f2a4:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f18f2a8:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f18f2ac:	01f3c825 */ 	or	$t9,$t7,$s3
/*  f18f2b0:	03275025 */ 	or	$t2,$t9,$a3
/*  f18f2b4:	ac4a0010 */ 	sw	$t2,0x10($v0)
/*  f18f2b8:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18f2bc:	268dfffe */ 	addiu	$t5,$s4,-2
/*  f18f2c0:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f18f2c4:	02cc0019 */ 	multu	$s6,$t4
/*  f18f2c8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f18f2cc:	0000c012 */ 	mflo	$t8
/*  f18f2d0:	330903ff */ 	andi	$t1,$t8,0x3ff
/*  f18f2d4:	00095b80 */ 	sll	$t3,$t1,0xe
/*  f18f2d8:	016fc825 */ 	or	$t9,$t3,$t7
/*  f18f2dc:	ac590014 */ 	sw	$t9,0x14($v0)
/*  f18f2e0:	afa8003c */ 	sw	$t0,0x3c($sp)
/*  f18f2e4:	0fc54e0e */ 	jal	func0f153838
/*  f18f2e8:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f18f2ec:	8faa00ec */ 	lw	$t2,0xec($sp)
/*  f18f2f0:	00402025 */ 	or	$a0,$v0,$zero
/*  f18f2f4:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f18f2f8:	024a2821 */ 	addu	$a1,$s2,$t2
/*  f18f2fc:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18f300:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*  f18f304:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f18f308:	022c0019 */ 	multu	$s1,$t4
/*  f18f30c:	2625ffff */ 	addiu	$a1,$s1,-1
/*  f18f310:	26860001 */ 	addiu	$a2,$s4,0x1
/*  f18f314:	30cf03ff */ 	andi	$t7,$a2,0x3ff
/*  f18f318:	000f3080 */ 	sll	$a2,$t7,0x2
/*  f18f31c:	328303ff */ 	andi	$v1,$s4,0x3ff
/*  f18f320:	24440018 */ 	addiu	$a0,$v0,0x18
/*  f18f324:	0000c012 */ 	mflo	$t8
/*  f18f328:	330903ff */ 	andi	$t1,$t8,0x3ff
/*  f18f32c:	00096b80 */ 	sll	$t5,$t1,0xe
/*  f18f330:	01b37025 */ 	or	$t6,$t5,$s3
/*  f18f334:	01c85825 */ 	or	$t3,$t6,$t0
/*  f18f338:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f18f33c:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f18f340:	00aa0019 */ 	multu	$a1,$t2
/*  f18f344:	00006012 */ 	mflo	$t4
/*  f18f348:	319803ff */ 	andi	$t8,$t4,0x3ff
/*  f18f34c:	00184b80 */ 	sll	$t1,$t8,0xe
/*  f18f350:	01266825 */ 	or	$t5,$t1,$a2
/*  f18f354:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f18f358:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18f35c:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f18f360:	03001825 */ 	or	$v1,$t8,$zero
/*  f18f364:	02ae0019 */ 	multu	$s5,$t6
/*  f18f368:	00005812 */ 	mflo	$t3
/*  f18f36c:	316f03ff */ 	andi	$t7,$t3,0x3ff
/*  f18f370:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f18f374:	03335025 */ 	or	$t2,$t9,$s3
/*  f18f378:	01466025 */ 	or	$t4,$t2,$a2
/*  f18f37c:	ac4c0008 */ 	sw	$t4,0x8($v0)
/*  f18f380:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18f384:	02c90019 */ 	multu	$s6,$t1
/*  f18f388:	00006812 */ 	mflo	$t5
/*  f18f38c:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f18f390:	000e5b80 */ 	sll	$t3,$t6,0xe
/*  f18f394:	01787825 */ 	or	$t7,$t3,$t8
/*  f18f398:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f18f39c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18f3a0:	02390019 */ 	multu	$s1,$t9
/*  f18f3a4:	00005012 */ 	mflo	$t2
/*  f18f3a8:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f18f3ac:	000cc380 */ 	sll	$t8,$t4,0xe
/*  f18f3b0:	03134825 */ 	or	$t1,$t8,$s3
/*  f18f3b4:	01236825 */ 	or	$t5,$t1,$v1
/*  f18f3b8:	ac4d0010 */ 	sw	$t5,0x10($v0)
/*  f18f3bc:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18f3c0:	00ae0019 */ 	multu	$a1,$t6
/*  f18f3c4:	00005812 */ 	mflo	$t3
/*  f18f3c8:	316f03ff */ 	andi	$t7,$t3,0x3ff
/*  f18f3cc:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f18f3d0:	03275025 */ 	or	$t2,$t9,$a3
/*  f18f3d4:	0fc54e0e */ 	jal	func0f153838
/*  f18f3d8:	ac4a0014 */ 	sw	$t2,0x14($v0)
/*  f18f3dc:	1000011a */ 	b	.L0f18f848
/*  f18f3e0:	00408025 */ 	or	$s0,$v0,$zero
.L0f18f3e4:
/*  f18f3e4:	8c427cc0 */ 	lw	$v0,%lo(var80087cc0)($v0)
/*  f18f3e8:	3c01437a */ 	lui	$at,0x437a
/*  f18f3ec:	1040006b */ 	beqz	$v0,.L0f18f59c
/*  f18f3f0:	00000000 */ 	nop
/*  f18f3f4:	44819000 */ 	mtc1	$at,$f18
/*  f18f3f8:	c6440004 */ 	lwc1	$f4,0x4($s2)
/*  f18f3fc:	02002025 */ 	or	$a0,$s0,$zero
/*  f18f400:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f18f404:	4604903c */ 	c.lt.s	$f18,$f4
/*  f18f408:	8fb800f0 */ 	lw	$t8,0xf0($sp)
/*  f18f40c:	45000063 */ 	bc1f	.L0f18f59c
/*  f18f410:	00000000 */ 	nop
/*  f18f414:	026c9007 */ 	srav	$s2,$t4,$s3
/*  f18f418:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f18f41c:	02582821 */ 	addu	$a1,$s2,$t8
/*  f18f420:	3c108008 */ 	lui	$s0,%hi(g_ScreenWidthMultiplier)
/*  f18f424:	2610fac0 */ 	addiu	$s0,$s0,%lo(g_ScreenWidthMultiplier)
/*  f18f428:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18f42c:	26290002 */ 	addiu	$t1,$s1,0x2
/*  f18f430:	268a0002 */ 	addiu	$t2,$s4,0x2
/*  f18f434:	012d0019 */ 	multu	$t1,$t5
/*  f18f438:	3c13f600 */ 	lui	$s3,0xf600
/*  f18f43c:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f18f440:	000cc080 */ 	sll	$t8,$t4,0x2
/*  f18f444:	2687ffff */ 	addiu	$a3,$s4,-1
/*  f18f448:	30ed03ff */ 	andi	$t5,$a3,0x3ff
/*  f18f44c:	000d3880 */ 	sll	$a3,$t5,0x2
/*  f18f450:	26350001 */ 	addiu	$s5,$s1,0x1
/*  f18f454:	2636fffe */ 	addiu	$s6,$s1,-2
/*  f18f458:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18f45c:	00007012 */ 	mflo	$t6
/*  f18f460:	31cb03ff */ 	andi	$t3,$t6,0x3ff
/*  f18f464:	000b7b80 */ 	sll	$t7,$t3,0xe
/*  f18f468:	01f3c825 */ 	or	$t9,$t7,$s3
/*  f18f46c:	03384825 */ 	or	$t1,$t9,$t8
/*  f18f470:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f18f474:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f18f478:	262bfffd */ 	addiu	$t3,$s1,-3
/*  f18f47c:	016f0019 */ 	multu	$t3,$t7
/*  f18f480:	00005012 */ 	mflo	$t2
/*  f18f484:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f18f488:	000ccb80 */ 	sll	$t9,$t4,0xe
/*  f18f48c:	0327c025 */ 	or	$t8,$t9,$a3
/*  f18f490:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f18f494:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18f498:	02a90019 */ 	multu	$s5,$t1
/*  f18f49c:	00006812 */ 	mflo	$t5
/*  f18f4a0:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f18f4a4:	000e5b80 */ 	sll	$t3,$t6,0xe
/*  f18f4a8:	01737825 */ 	or	$t7,$t3,$s3
/*  f18f4ac:	01e75025 */ 	or	$t2,$t7,$a3
/*  f18f4b0:	ac4a0008 */ 	sw	$t2,0x8($v0)
/*  f18f4b4:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18f4b8:	268dfffe */ 	addiu	$t5,$s4,-2
/*  f18f4bc:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f18f4c0:	02cc0019 */ 	multu	$s6,$t4
/*  f18f4c4:	000e5880 */ 	sll	$t3,$t6,0x2
/*  f18f4c8:	0000c812 */ 	mflo	$t9
/*  f18f4cc:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f18f4d0:	00184b80 */ 	sll	$t1,$t8,0xe
/*  f18f4d4:	012b7825 */ 	or	$t7,$t1,$t3
/*  f18f4d8:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f18f4dc:	0fc54e0e */ 	jal	func0f153838
/*  f18f4e0:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f18f4e4:	8faa00ec */ 	lw	$t2,0xec($sp)
/*  f18f4e8:	00402025 */ 	or	$a0,$v0,$zero
/*  f18f4ec:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f18f4f0:	024a2821 */ 	addu	$a1,$s2,$t2
/*  f18f4f4:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18f4f8:	26890001 */ 	addiu	$t1,$s4,0x1
/*  f18f4fc:	312b03ff */ 	andi	$t3,$t1,0x3ff
/*  f18f500:	02ac0019 */ 	multu	$s5,$t4
/*  f18f504:	000b7880 */ 	sll	$t7,$t3,0x2
/*  f18f508:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f18f50c:	328303ff */ 	andi	$v1,$s4,0x3ff
/*  f18f510:	00036080 */ 	sll	$t4,$v1,0x2
/*  f18f514:	01801825 */ 	or	$v1,$t4,$zero
/*  f18f518:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18f51c:	0000c812 */ 	mflo	$t9
/*  f18f520:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f18f524:	00186b80 */ 	sll	$t5,$t8,0xe
/*  f18f528:	01b37025 */ 	or	$t6,$t5,$s3
/*  f18f52c:	01cf5025 */ 	or	$t2,$t6,$t7
/*  f18f530:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f18f534:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f18f538:	02d90019 */ 	multu	$s6,$t9
/*  f18f53c:	0000c012 */ 	mflo	$t8
/*  f18f540:	330d03ff */ 	andi	$t5,$t8,0x3ff
/*  f18f544:	000d4b80 */ 	sll	$t1,$t5,0xe
/*  f18f548:	012c5825 */ 	or	$t3,$t1,$t4
/*  f18f54c:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f18f550:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f18f554:	262dffff */ 	addiu	$t5,$s1,-1
/*  f18f558:	022e0019 */ 	multu	$s1,$t6
/*  f18f55c:	00007812 */ 	mflo	$t7
/*  f18f560:	31ea03ff */ 	andi	$t2,$t7,0x3ff
/*  f18f564:	000a6380 */ 	sll	$t4,$t2,0xe
/*  f18f568:	0193c825 */ 	or	$t9,$t4,$s3
/*  f18f56c:	0323c025 */ 	or	$t8,$t9,$v1
/*  f18f570:	ac580008 */ 	sw	$t8,0x8($v0)
/*  f18f574:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18f578:	01a90019 */ 	multu	$t5,$t1
/*  f18f57c:	00005812 */ 	mflo	$t3
/*  f18f580:	316e03ff */ 	andi	$t6,$t3,0x3ff
/*  f18f584:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f18f588:	01e75025 */ 	or	$t2,$t7,$a3
/*  f18f58c:	0fc54e0e */ 	jal	func0f153838
/*  f18f590:	ac4a000c */ 	sw	$t2,0xc($v0)
/*  f18f594:	100000ac */ 	b	.L0f18f848
/*  f18f598:	00408025 */ 	or	$s0,$v0,$zero
.L0f18f59c:
/*  f18f59c:	1040006a */ 	beqz	$v0,.L0f18f748
/*  f18f5a0:	3c01c37a */ 	lui	$at,0xc37a
/*  f18f5a4:	c6460004 */ 	lwc1	$f6,0x4($s2)
/*  f18f5a8:	44814000 */ 	mtc1	$at,$f8
/*  f18f5ac:	02002025 */ 	or	$a0,$s0,$zero
/*  f18f5b0:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f18f5b4:	4608303c */ 	c.lt.s	$f6,$f8
/*  f18f5b8:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f18f5bc:	45000062 */ 	bc1f	.L0f18f748
/*  f18f5c0:	026c9007 */ 	srav	$s2,$t4,$s3
/*  f18f5c4:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f18f5c8:	02592821 */ 	addu	$a1,$s2,$t9
/*  f18f5cc:	3c108008 */ 	lui	$s0,%hi(g_ScreenWidthMultiplier)
/*  f18f5d0:	2610fac0 */ 	addiu	$s0,$s0,%lo(g_ScreenWidthMultiplier)
/*  f18f5d4:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18f5d8:	26290002 */ 	addiu	$t1,$s1,0x2
/*  f18f5dc:	26860001 */ 	addiu	$a2,$s4,0x1
/*  f18f5e0:	012b0019 */ 	multu	$t1,$t3
/*  f18f5e4:	3c13f600 */ 	lui	$s3,0xf600
/*  f18f5e8:	30d803ff */ 	andi	$t8,$a2,0x3ff
/*  f18f5ec:	00183080 */ 	sll	$a2,$t8,0x2
/*  f18f5f0:	2638fffd */ 	addiu	$t8,$s1,-3
/*  f18f5f4:	26350001 */ 	addiu	$s5,$s1,0x1
/*  f18f5f8:	2636fffe */ 	addiu	$s6,$s1,-2
/*  f18f5fc:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18f600:	00007012 */ 	mflo	$t6
/*  f18f604:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f18f608:	000f5380 */ 	sll	$t2,$t7,0xe
/*  f18f60c:	01536025 */ 	or	$t4,$t2,$s3
/*  f18f610:	0186c825 */ 	or	$t9,$t4,$a2
/*  f18f614:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f18f618:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18f61c:	268ffffe */ 	addiu	$t7,$s4,-2
/*  f18f620:	31ea03ff */ 	andi	$t2,$t7,0x3ff
/*  f18f624:	030d0019 */ 	multu	$t8,$t5
/*  f18f628:	000a6080 */ 	sll	$t4,$t2,0x2
/*  f18f62c:	268a0002 */ 	addiu	$t2,$s4,0x2
/*  f18f630:	00004812 */ 	mflo	$t1
/*  f18f634:	312b03ff */ 	andi	$t3,$t1,0x3ff
/*  f18f638:	000b7380 */ 	sll	$t6,$t3,0xe
/*  f18f63c:	01ccc825 */ 	or	$t9,$t6,$t4
/*  f18f640:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f18f644:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18f648:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f18f64c:	000e6080 */ 	sll	$t4,$t6,0x2
/*  f18f650:	02b80019 */ 	multu	$s5,$t8
/*  f18f654:	00006812 */ 	mflo	$t5
/*  f18f658:	31a903ff */ 	andi	$t1,$t5,0x3ff
/*  f18f65c:	00095b80 */ 	sll	$t3,$t1,0xe
/*  f18f660:	01737825 */ 	or	$t7,$t3,$s3
/*  f18f664:	01ecc825 */ 	or	$t9,$t7,$t4
/*  f18f668:	ac590008 */ 	sw	$t9,0x8($v0)
/*  f18f66c:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f18f670:	02d80019 */ 	multu	$s6,$t8
/*  f18f674:	00006812 */ 	mflo	$t5
/*  f18f678:	31a903ff */ 	andi	$t1,$t5,0x3ff
/*  f18f67c:	00095b80 */ 	sll	$t3,$t1,0xe
/*  f18f680:	01665025 */ 	or	$t2,$t3,$a2
/*  f18f684:	ac4a000c */ 	sw	$t2,0xc($v0)
/*  f18f688:	0fc54e0e */ 	jal	func0f153838
/*  f18f68c:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f18f690:	8fae00ec */ 	lw	$t6,0xec($sp)
/*  f18f694:	00402025 */ 	or	$a0,$v0,$zero
/*  f18f698:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f18f69c:	024e2821 */ 	addu	$a1,$s2,$t6
/*  f18f6a0:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18f6a4:	328303ff */ 	andi	$v1,$s4,0x3ff
/*  f18f6a8:	00037880 */ 	sll	$t7,$v1,0x2
/*  f18f6ac:	02ac0019 */ 	multu	$s5,$t4
/*  f18f6b0:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*  f18f6b4:	01e01825 */ 	or	$v1,$t7,$zero
/*  f18f6b8:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f18f6bc:	0000c812 */ 	mflo	$t9
/*  f18f6c0:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f18f6c4:	00186b80 */ 	sll	$t5,$t8,0xe
/*  f18f6c8:	01b34825 */ 	or	$t1,$t5,$s3
/*  f18f6cc:	012f5825 */ 	or	$t3,$t1,$t7
/*  f18f6d0:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f18f6d4:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f18f6d8:	2699ffff */ 	addiu	$t9,$s4,-1
/*  f18f6dc:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f18f6e0:	02ca0019 */ 	multu	$s6,$t2
/*  f18f6e4:	00186880 */ 	sll	$t5,$t8,0x2
/*  f18f6e8:	00007012 */ 	mflo	$t6
/*  f18f6ec:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f18f6f0:	000f6380 */ 	sll	$t4,$t7,0xe
/*  f18f6f4:	018d4825 */ 	or	$t1,$t4,$t5
/*  f18f6f8:	ac490004 */ 	sw	$t1,0x4($v0)
/*  f18f6fc:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18f700:	262cffff */ 	addiu	$t4,$s1,-1
/*  f18f704:	022b0019 */ 	multu	$s1,$t3
/*  f18f708:	00005012 */ 	mflo	$t2
/*  f18f70c:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f18f710:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f18f714:	01f3c825 */ 	or	$t9,$t7,$s3
/*  f18f718:	0326c025 */ 	or	$t8,$t9,$a2
/*  f18f71c:	ac580008 */ 	sw	$t8,0x8($v0)
/*  f18f720:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18f724:	018d0019 */ 	multu	$t4,$t5
/*  f18f728:	00004812 */ 	mflo	$t1
/*  f18f72c:	312b03ff */ 	andi	$t3,$t1,0x3ff
/*  f18f730:	000b5380 */ 	sll	$t2,$t3,0xe
/*  f18f734:	01437025 */ 	or	$t6,$t2,$v1
/*  f18f738:	0fc54e0e */ 	jal	func0f153838
/*  f18f73c:	ac4e000c */ 	sw	$t6,0xc($v0)
/*  f18f740:	10000041 */ 	b	.L0f18f848
/*  f18f744:	00408025 */ 	or	$s0,$v0,$zero
.L0f18f748:
/*  f18f748:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f18f74c:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f18f750:	026f9007 */ 	srav	$s2,$t7,$s3
/*  f18f754:	02002025 */ 	or	$a0,$s0,$zero
/*  f18f758:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f18f75c:	02592821 */ 	addu	$a1,$s2,$t9
/*  f18f760:	3c108008 */ 	lui	$s0,%hi(g_ScreenWidthMultiplier)
/*  f18f764:	2610fac0 */ 	addiu	$s0,$s0,%lo(g_ScreenWidthMultiplier)
/*  f18f768:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f18f76c:	26380002 */ 	addiu	$t8,$s1,0x2
/*  f18f770:	268e0002 */ 	addiu	$t6,$s4,0x2
/*  f18f774:	030c0019 */ 	multu	$t8,$t4
/*  f18f778:	3c13f600 */ 	lui	$s3,0xf600
/*  f18f77c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f18f780:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f18f784:	262cfffe */ 	addiu	$t4,$s1,-2
/*  f18f788:	268ffffe */ 	addiu	$t7,$s4,-2
/*  f18f78c:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f18f790:	00006812 */ 	mflo	$t5
/*  f18f794:	31a903ff */ 	andi	$t1,$t5,0x3ff
/*  f18f798:	00095b80 */ 	sll	$t3,$t1,0xe
/*  f18f79c:	01735025 */ 	or	$t2,$t3,$s3
/*  f18f7a0:	0159c025 */ 	or	$t8,$t2,$t9
/*  f18f7a4:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f18f7a8:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f18f7ac:	31ea03ff */ 	andi	$t2,$t7,0x3ff
/*  f18f7b0:	000ac880 */ 	sll	$t9,$t2,0x2
/*  f18f7b4:	018d0019 */ 	multu	$t4,$t5
/*  f18f7b8:	00004812 */ 	mflo	$t1
/*  f18f7bc:	312b03ff */ 	andi	$t3,$t1,0x3ff
/*  f18f7c0:	000b7380 */ 	sll	$t6,$t3,0xe
/*  f18f7c4:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f18f7c8:	0fc54e0e */ 	jal	func0f153838
/*  f18f7cc:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f18f7d0:	8fac00ec */ 	lw	$t4,0xec($sp)
/*  f18f7d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f18f7d8:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f18f7dc:	024c2821 */ 	addu	$a1,$s2,$t4
/*  f18f7e0:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f18f7e4:	262d0001 */ 	addiu	$t5,$s1,0x1
/*  f18f7e8:	26990001 */ 	addiu	$t9,$s4,0x1
/*  f18f7ec:	01a90019 */ 	multu	$t5,$t1
/*  f18f7f0:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f18f7f4:	00186080 */ 	sll	$t4,$t8,0x2
/*  f18f7f8:	2629ffff */ 	addiu	$t1,$s1,-1
/*  f18f7fc:	2698ffff */ 	addiu	$t8,$s4,-1
/*  f18f800:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f18f804:	00005812 */ 	mflo	$t3
/*  f18f808:	316f03ff */ 	andi	$t7,$t3,0x3ff
/*  f18f80c:	000f5380 */ 	sll	$t2,$t7,0xe
/*  f18f810:	01537025 */ 	or	$t6,$t2,$s3
/*  f18f814:	01cc6825 */ 	or	$t5,$t6,$t4
/*  f18f818:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f18f81c:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f18f820:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f18f824:	000e6080 */ 	sll	$t4,$t6,0x2
/*  f18f828:	012b0019 */ 	multu	$t1,$t3
/*  f18f82c:	00007812 */ 	mflo	$t7
/*  f18f830:	31ea03ff */ 	andi	$t2,$t7,0x3ff
/*  f18f834:	000acb80 */ 	sll	$t9,$t2,0xe
/*  f18f838:	032c6825 */ 	or	$t5,$t9,$t4
/*  f18f83c:	0fc54e0e */ 	jal	func0f153838
/*  f18f840:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f18f844:	00408025 */ 	or	$s0,$v0,$zero
.L0f18f848:
/*  f18f848:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f18f84c:	02001025 */ 	or	$v0,$s0,$zero
/*  f18f850:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f18f854:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f18f858:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f18f85c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f18f860:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f18f864:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f18f868:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f18f86c:	03e00008 */ 	jr	$ra
/*  f18f870:	27bd00e0 */ 	addiu	$sp,$sp,0xe0
);

Gfx *radarRender(Gfx *gdl)
{
	s32 stack;
	s32 stack2;
	s32 playercount;
	s32 playernum;
	struct textureconfig *tconfig;
	struct coord pos;
	u32 colour;
	s32 i;

	tconfig = var800ab5ac;
	playernum = g_Vars.currentplayernum;
	playercount = PLAYERCOUNT();

	if (g_Vars.mplayerisrunning) {
		if (g_Vars.normmplayerisrunning && (g_MpSetup.options & MPOPTION_NORADAR)) {
			return gdl;
		}

		if ((g_MpPlayers[g_Vars.currentplayerstats->mpindex].base.displayoptions & 0x00000004) == 0) {
			return gdl;
		}
	} else if ((g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_RTRACKER) == 0) {
		if (!g_MissionConfig.iscoop || !g_Vars.coopradaron) {
			return gdl;
		}
	}

	if (g_Vars.currentplayer->mpmenuon || g_Vars.currentplayer->isdead) {
		return gdl;
	}

	if (g_ViMode == VIMODE_HIRES) {
		g_ScreenWidthMultiplier = 2;
	} else {
		g_ScreenWidthMultiplier = 1;
	}

	g_RadarX = (viGetViewLeft() + viGetViewWidth()) / g_ScreenWidthMultiplier - 41;

	if (playercount == 2) {
		if (IS4MB() || optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) {
			if (playernum == 0) {
				g_RadarX += 16;
			}

			if (IS4MB()) {
				g_RadarX -= 4;
			}
		} else {
			g_RadarX -= 7;
		}
	} else if (playercount >= 3) {
		if ((playernum & 1) == 0) {
			g_RadarX += 7;
		} else {
			g_RadarX -= 7;
		}
	}

	g_RadarY = viGetViewTop() + 26;

	if (playercount == 2) {
		if (IS4MB()) {
			g_RadarY -= 6;
		} else if (optionsGetScreenSplit() != SCREENSPLIT_VERTICAL && playernum == 1) {
			g_RadarY -= 8;
		}
	} else if (playercount >= 3) {
		if (playernum >= 2) {
			g_RadarY -= 8;
		} else {
			g_RadarY -= 2;
		}
	} else {
		if (optionsGetEffectiveScreenSize() != SCREENSIZE_FULL) {
			g_RadarY -= 6;
		}
	}

	gdl = func0f18e5ac(gdl, tconfig, g_RadarX, g_RadarY, 0x10);
	gdl = func0f153134(gdl);

	// Draw dots for human players
	for (i = 0; i < playercount; i++) {
		if (i != playernum) {
			if (g_Vars.players[i]->isdead == false
					&& (g_Vars.players[i]->prop->chr->hidden & CHRHFLAG_CLOAKED) == 0
					&& scenarioRadar2(&gdl, g_Vars.players[i]->prop) == false) {
				pos.x = g_Vars.players[i]->prop->pos.x - g_Vars.currentplayer->prop->pos.x;
				pos.y = g_Vars.players[i]->prop->pos.y - g_Vars.currentplayer->prop->pos.y;
				pos.z = g_Vars.players[i]->prop->pos.z - g_Vars.currentplayer->prop->pos.z;

				if (g_Vars.normmplayerisrunning && (g_MpSetup.options & MPOPTION_TEAMSENABLED)) {
					s32 index = g_MpPlayers[g_Vars.playerstats[i].mpindex].base.team;
					colour = g_TeamColours[index];
				} else {
					colour = 0x00ff0000;
				}

				gdl = radarDrawDot(gdl, g_Vars.players[i]->prop, &pos, colour, 0, 0);
			}
		}
	}

	// Draw dots for coop AI buddies
	if (!g_Vars.normmplayerisrunning && g_MissionConfig.iscoop) {
		for (i = 0; i < g_Vars.numaibuddies && i < 4; i++) {
			struct prop *prop = g_Vars.aibuddies[i];

			if (prop
					&& prop->type == PROPTYPE_CHR
					&& prop->chr
					&& prop->chr->actiontype != ACT_DIE
					&& prop->chr->actiontype != ACT_DEAD) {
				pos.x = prop->pos.x - g_Vars.currentplayer->prop->pos.x;
				pos.y = prop->pos.y - g_Vars.currentplayer->prop->pos.y;
				pos.z = prop->pos.z - g_Vars.currentplayer->prop->pos.z;

				gdl = radarDrawDot(gdl, prop, &pos, 0x00ff0000, 0, 0);
			}
		}
	}

	// Draw dots for MP simulants
	if (g_Vars.normmplayerisrunning != 0) {
		for (i = 0; i < g_NumMpSimulantChrs; i++) {
			if (!chrIsDead(g_MpSimulantChrs[i])
					&& (g_MpSimulantChrs[i]->hidden & CHRHFLAG_CLOAKED) == 0
					&& scenarioRadar2(&gdl, g_MpSimulantChrs[i]->prop) == false) {
				pos.x = g_MpSimulantChrs[i]->prop->pos.x - g_Vars.currentplayer->prop->pos.x;
				pos.y = g_MpSimulantChrs[i]->prop->pos.y - g_Vars.currentplayer->prop->pos.y;
				pos.z = g_MpSimulantChrs[i]->prop->pos.z - g_Vars.currentplayer->prop->pos.z;

				if (g_Vars.normmplayerisrunning && (g_MpSetup.options & MPOPTION_TEAMSENABLED)) {
					colour = g_TeamColours[radarGetTeamIndex(g_MpSimulantChrs[i]->team)];
				} else {
					colour = 0x00ff0000;
				}

				gdl = radarDrawDot(gdl, g_MpSimulantChrs[i]->prop, &pos, colour, 0, 0);
			}
		}
	}

	gdl = scenarioRadar(gdl);

	// Draw dots for r-tracked props
	if (g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_RTRACKER) {
		gdl = radarRenderRTrackedProps(gdl);
	}

	// Draw dot for the current player
	if (scenarioRadar2(&gdl, g_Vars.currentplayer->prop) == 0) {
		pos.x = 0;
		pos.y = 0;
		pos.z = 0;

		if (g_Vars.normmplayerisrunning && (g_MpSetup.options & MPOPTION_TEAMSENABLED)) {
			s32 index = g_MpPlayers[g_Vars.playerstats[playernum].mpindex].base.team;
			colour = g_TeamColours[index];
		} else {
			colour = 0x00ff0000;
		}

		gdl = radarDrawDot(gdl, g_Vars.currentplayer->prop, &pos, colour, 0, 0);
	}

	g_ScreenWidthMultiplier = 1;

	return gdl;
}

Gfx *radarRenderRTrackedProps(Gfx *gdl)
{
	struct prop *prop = g_Vars.unk00033c;
	struct coord *playerpos = &g_Vars.currentplayer->prop->pos;
	struct defaultobj *obj;
	struct chrdata *chr;
	u32 stack1;
	struct coord dist1;
	u32 stack2;
	struct coord dist2;

	while (prop) {
		switch (prop->type) {
		case PROPTYPE_OBJ:
		case PROPTYPE_DOOR:
		case PROPTYPE_WEAPON:
			obj = prop->obj;

			if ((obj->flags3 & OBJFLAG3_RTRACKED_YELLOW) ||
					(cheatIsActive(CHEAT_RTRACKER) && (obj->flags3 & OBJFLAG3_RTRACKED_BLUE))) {
				dist1.x = prop->pos.x - playerpos->x;
				dist1.y = prop->pos.y - playerpos->y;
				dist1.z = prop->pos.z - playerpos->z;

				gdl = radarDrawDot(gdl, prop, &dist1,
						(obj->flags3 & OBJFLAG3_RTRACKED_YELLOW) ? 0xffff0000 : 0x0000ff00,
						0, 0);
			}
			break;
		case PROPTYPE_CHR:
			chr = prop->chr;

			if (chr && chr->unk32c_20
					&& chr->actiontype != ACT_DIE
					&& chr->actiontype != ACT_DEAD
					&& (chr->hidden & CHRHFLAG_CLOAKED) == 0) {
				dist2.x = prop->pos.x - playerpos->x;
				dist2.y = prop->pos.y - playerpos->y;
				dist2.z = prop->pos.z - playerpos->z;
				gdl = radarDrawDot(gdl, prop, &dist2, 0xff000000, 0, 0);
			}
			break;
		}

		prop = prop->next;
	}

	return gdl;
}
