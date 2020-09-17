#include <ultra64.h>
#include "constants.h"
#include "game/camdraw.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_005fd0.h"
#include "game/game_006bd0.h"
#include "game/game_02cde0.h"
#include "game/game_095320.h"
#include "game/game_096ca0.h"
#include "game/game_097ba0.h"
#include "game/game_0b3350.h"
#include "game/game_0b63b0.h"
#include "game/game_0d4690.h"
#include "game/game_0e0770.h"
#include "game/game_0e5ce0.h"
#include "game/game_0f09f0.h"
#include "game/game_0fd660.h"
#include "game/game_107fb0.h"
#include "game/game_1371b0.h"
#include "game/game_1531a0.h"
#include "game/game_166e40.h"
#include "game/game_167ae0.h"
#include "game/music.h"
#include "game/game_16e810.h"
#include "game/game_179060.h"
#include "game/game_19aa80.h"
#include "game/game_1a3340.h"
#include "game/game_1a78b0.h"
#include "game/gamefile.h"
#include "game/lang.h"
#include "game/mplayer.h"
#include "game/pak/pak.h"
#include "game/pdoptions.h"
#include "game/propobj.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_0d520.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_121e0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_13130.h"
#include "lib/lib_13900.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_1a500.h"
#include "lib/lib_317f0.h"
#include "lib/lib_481e0.h"
#include "lib/lib_48830.h"
#include "lib/lib_4b480.h"
#include "types.h"

const struct menucolourpalette g_MenuColourPalettes[] = {
	{ 0x20202000, 0x20202000, 0x20202000, 0x4f4f4f00, 0x00000000, 0x00000000, 0x4f4f4f00, 0x4f4f4f00, 0x4f4f4f00, 0x4f4f4f00, 0x00000000, 0x00000000, 0x4f4f4f00, 0x00000000, 0x00000000 },
	{ 0x0060bf7f, 0x0000507f, 0x00f0ff7f, 0xffffffff, 0x00002f7f, 0x00006f7f, 0x00ffffff, 0x007f7fff, 0xffffffff, 0x8fffffff, 0x000044ff, 0x000030ff, 0x7f7fffff, 0xffffffff, 0x6644ff7f },
	{ 0xbf00007f, 0x5000007f, 0xff00007f, 0xffff00ff, 0x2f00007f, 0x6f00007f, 0xff7050ff, 0x7f0000ff, 0xffff00ff, 0xff9070ff, 0x440000ff, 0x003000ff, 0xffff00ff, 0xffffffff, 0xff44447f },
	{ 0x00bf007f, 0x0050007f, 0x00ff007f, 0xffff00ff, 0x002f007f, 0x00ff0028, 0x55ff55ff, 0x006f00af, 0xffffffff, 0x00000000, 0x004400ff, 0x003000ff, 0xffff00ff, 0xffffffff, 0x44ff447f },
	{ 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
	{ 0xaaaaaaff, 0xaaaaaa7f, 0xaaaaaaff, 0xffffffff, 0xffffff2f, 0xffffffff, 0xffffffff, 0xffffffff, 0xff8888ff, 0xffffffff, 0x00000000, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
};

const struct menucolourpalette g_MenuColourPalettes2[] = {
	{ 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x4f4f4f00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000 },
	{ 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x006f6faf, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000 },
	{ 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x006f6faf, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000 },
	{ 0xffffff00, 0xffffff00, 0xffffff00, 0xff7f0000, 0xffffff00, 0xffffff00, 0x00ffff00, 0x006f6faf, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000 },
	{ 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
	{ 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
};

const struct menucolourpalette g_MenuColourPalettes3[] = {
	{ 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x4f4f4f00, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x00000000 },
	{ 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x006f6faf, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x00000000 },
	{ 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x006f6faf, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x00000000 },
	{ 0x44444400, 0x44444400, 0x44444400, 0x00ff0000, 0x44444400, 0x44444400, 0xffff0000, 0x006f6faf, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x00000000 },
	{ 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
	{ 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
};

const u32 var7f1b23e8[] = {0x544d0000};
char *g_StringPointer = g_CheatMarqueeString;
char *g_StringPointer2 = &g_CheatMarqueeString[125];
s32 g_MpPlayerNum = 0;

GLOBAL_ASM(
glabel func0f0f09f0
.late_rodata
glabel var7f1b27c0
.word func0f0f09f0+0x40 # f0f0a30
glabel var7f1b27c4
.word func0f0f09f0+0x48 # f0f0a38
glabel var7f1b27c8
.word func0f0f09f0+0x50 # f0f0a40
glabel var7f1b27cc
.word func0f0f09f0+0x58 # f0f0a48
glabel var7f1b27d0
.word func0f0f09f0+0x60 # f0f0a50
glabel var7f1b27d4
.word func0f0f09f0+0x78 # f0f0a68
glabel var7f1b27d8
.word func0f0f09f0+0xc8 # f0f0ab8
glabel var7f1b27dc
.word func0f0f09f0+0xc8 # f0f0ab8
glabel var7f1b27e0
.word func0f0f09f0+0x80 # f0f0a70
glabel var7f1b27e4
.word func0f0f09f0+0x88 # f0f0a78
glabel var7f1b27e8
.word func0f0f09f0+0x90 # f0f0a80
glabel var7f1b27ec
.word func0f0f09f0+0xc8 # f0f0ab8
glabel var7f1b27f0
.word func0f0f09f0+0x98 # f0f0a88
glabel var7f1b27f4
.word func0f0f09f0+0xb4 # f0f0aa4
glabel var7f1b27f8
.word 0x3ecccccd
glabel var7f1b27fc
.word 0x3ed68d76
.text
/*  f0f09f0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f09f4:	44812000 */ 	mtc1	$at,$f4
/*  f0f09f8:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0f09fc:	2c81000e */ 	sltiu	$at,$a0,0xe
/*  f0f0a00:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0f0a04:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f0f0a08:	00004025 */ 	or	$t0,$zero,$zero
/*  f0f0a0c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f0a10:	10200029 */ 	beqz	$at,.L0f0f0ab8
/*  f0f0a14:	e7a40030 */ 	swc1	$f4,0x30($sp)
/*  f0f0a18:	00047080 */ 	sll	$t6,$a0,0x2
/*  f0f0a1c:	3c017f1b */ 	lui	$at,%hi(var7f1b27c0)
/*  f0f0a20:	002e0821 */ 	addu	$at,$at,$t6
/*  f0f0a24:	8c2e27c0 */ 	lw	$t6,%lo(var7f1b27c0)($at)
/*  f0f0a28:	01c00008 */ 	jr	$t6
/*  f0f0a2c:	00000000 */ 	nop
/*  f0f0a30:	10000021 */ 	b	.L0f0f0ab8
/*  f0f0a34:	240305bb */ 	addiu	$v1,$zero,0x5bb
/*  f0f0a38:	1000001f */ 	b	.L0f0f0ab8
/*  f0f0a3c:	240305bc */ 	addiu	$v1,$zero,0x5bc
/*  f0f0a40:	1000001d */ 	b	.L0f0f0ab8
/*  f0f0a44:	24030441 */ 	addiu	$v1,$zero,0x441
/*  f0f0a48:	1000001b */ 	b	.L0f0f0ab8
/*  f0f0a4c:	240305dd */ 	addiu	$v1,$zero,0x5dd
/*  f0f0a50:	3c017f1b */ 	lui	$at,%hi(var7f1b27f8)
/*  f0f0a54:	c42627f8 */ 	lwc1	$f6,%lo(var7f1b27f8)($at)
/*  f0f0a58:	34038040 */ 	dli	$v1,0x8040
/*  f0f0a5c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f0a60:	10000015 */ 	b	.L0f0f0ab8
/*  f0f0a64:	e7a60030 */ 	swc1	$f6,0x30($sp)
/*  f0f0a68:	10000013 */ 	b	.L0f0f0ab8
/*  f0f0a6c:	34038098 */ 	dli	$v1,0x8098
/*  f0f0a70:	10000011 */ 	b	.L0f0f0ab8
/*  f0f0a74:	240305dd */ 	addiu	$v1,$zero,0x5dd
/*  f0f0a78:	1000000f */ 	b	.L0f0f0ab8
/*  f0f0a7c:	2403043e */ 	addiu	$v1,$zero,0x43e
/*  f0f0a80:	1000000d */ 	b	.L0f0f0ab8
/*  f0f0a84:	2403043e */ 	addiu	$v1,$zero,0x43e
/*  f0f0a88:	3c014060 */ 	lui	$at,0x4060
/*  f0f0a8c:	44814000 */ 	mtc1	$at,$f8
/*  f0f0a90:	240300ea */ 	addiu	$v1,$zero,0xea
/*  f0f0a94:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f0a98:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0f0a9c:	10000006 */ 	b	.L0f0f0ab8
/*  f0f0aa0:	e7a80030 */ 	swc1	$f8,0x30($sp)
/*  f0f0aa4:	3c017f1b */ 	lui	$at,%hi(var7f1b27fc)
/*  f0f0aa8:	c42a27fc */ 	lwc1	$f10,%lo(var7f1b27fc)($at)
/*  f0f0aac:	2403002b */ 	addiu	$v1,$zero,0x2b
/*  f0f0ab0:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f0ab4:	e7aa0030 */ 	swc1	$f10,0x30($sp)
.L0f0f0ab8:
/*  f0f0ab8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f0abc:	10610030 */ 	beq	$v1,$at,.L0f0f0b80
/*  f0f0ac0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f0ac4:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f0f0ac8:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f0f0acc:	0c012230 */ 	jal	osGetThreadPri
/*  f0f0ad0:	afa80038 */ 	sw	$t0,0x38($sp)
/*  f0f0ad4:	3c048009 */ 	lui	$a0,%hi(var800915e0)
/*  f0f0ad8:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f0f0adc:	0c012230 */ 	jal	osGetThreadPri
/*  f0f0ae0:	248415e0 */ 	addiu	$a0,$a0,%lo(var800915e0)
/*  f0f0ae4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f0ae8:	0c01210c */ 	jal	osSetThreadPri
/*  f0f0aec:	24450001 */ 	addiu	$a1,$v0,0x1
/*  f0f0af0:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f0f0af4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0f0af8:	44818000 */ 	mtc1	$at,$f16
/*  f0f0afc:	00032c00 */ 	sll	$a1,$v1,0x10
/*  f0f0b00:	00057c03 */ 	sra	$t7,$a1,0x10
/*  f0f0b04:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f0f0b08:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0f0b0c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0f0b10:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f0f0b14:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f0f0b18:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0f0b1c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f0b20:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f0f0b24:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0f0b28:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f0b2c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0f0b30:	0c004241 */ 	jal	audioStart
/*  f0f0b34:	e7b00014 */ 	swc1	$f16,0x14($sp)
/*  f0f0b38:	8fa80038 */ 	lw	$t0,0x38($sp)
/*  f0f0b3c:	10400007 */ 	beqz	$v0,.L0f0f0b5c
/*  f0f0b40:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f0b44:	11000005 */ 	beqz	$t0,.L0f0f0b5c
/*  f0f0b48:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f0f0b4c:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f0f0b50:	0c00cf94 */ 	jal	func00033e50
/*  f0f0b54:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f0f0b58:	8fa4002c */ 	lw	$a0,0x2c($sp)
.L0f0f0b5c:
/*  f0f0b5c:	10800005 */ 	beqz	$a0,.L0f0f0b74
/*  f0f0b60:	8faa0034 */ 	lw	$t2,0x34($sp)
/*  f0f0b64:	11400003 */ 	beqz	$t2,.L0f0f0b74
/*  f0f0b68:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0f0b6c:	0c00cf94 */ 	jal	func00033e50
/*  f0f0b70:	24064000 */ 	addiu	$a2,$zero,0x4000
.L0f0f0b74:
/*  f0f0b74:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f0b78:	0c01210c */ 	jal	osSetThreadPri
/*  f0f0b7c:	8fa50028 */ 	lw	$a1,0x28($sp)
.L0f0f0b80:
/*  f0f0b80:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0f0b84:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f0f0b88:	03e00008 */ 	jr	$ra
/*  f0f0b8c:	00000000 */ 	nop
);

bool menuIsSoloMissionOrMp(void)
{
	switch (g_MenuData.root) {
	case MENUROOT_MAINMENU:
	case MENUROOT_TRAINING:
		if (g_Vars.stagenum == STAGE_CITRAINING) {
			return false;
		}

		return true;
	case MENUROOT_MPPAUSE:
		return true;
	}

	return false;
}

bool currentPlayerIsMenuOpenInSoloOrMp(void)
{
	s32 mpindex = g_Vars.currentplayerstats->mpindex;

	if (menuIsSoloMissionOrMp()) {
		if (mpindex >= 4) {
			mpindex -= 4;
		}

		if (g_Menus[mpindex].curframe) {
			return true;
		}
	}

	return false;
}

bool func0f0f0c68(void)
{
	if (g_MenuData.unk014 || g_MenuData.unk015 != 255) {
		return false;
	}

	return true;
}

void func0f0f0ca0(s32 value, bool allplayers)
{
	if (allplayers) {
		g_MenuData.unk01b = value;
		return;
	}

	g_Menus[g_MpPlayerNum].unkdf8 = value;
}

u32 var8007144c = 0x51e451e5;
u32 var80071450 = 0x51e651e7;
u32 var80071454 = 0x51e851e9;
u32 var80071458 = 0x51ea51eb;
u32 var8007145c = 0x51ec51ed;
u32 var80071460 = 0x51ee0000;
u32 var80071464 = 0x00000000;

GLOBAL_ASM(
glabel func0f0f0ce8
/*  f0f0ce8:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f0f0cec:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f0f0cf0:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0f0cf4:	3c038008 */ 	lui	$v1,%hi(var8007fb10)
/*  f0f0cf8:	3c088008 */ 	lui	$t0,%hi(var8007fb0c)
/*  f0f0cfc:	00808825 */ 	or	$s1,$a0,$zero
/*  f0f0d00:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0f0d04:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0f0d08:	afa50094 */ 	sw	$a1,0x94($sp)
/*  f0f0d0c:	afa60098 */ 	sw	$a2,0x98($sp)
/*  f0f0d10:	afa7009c */ 	sw	$a3,0x9c($sp)
/*  f0f0d14:	8c63fb10 */ 	lw	$v1,%lo(var8007fb10)($v1)
/*  f0f0d18:	11c00005 */ 	beqz	$t6,.L0f0f0d30
/*  f0f0d1c:	8d08fb0c */ 	lw	$t0,%lo(var8007fb0c)($t0)
/*  f0f0d20:	3c038008 */ 	lui	$v1,%hi(var8007fb18)
/*  f0f0d24:	3c088008 */ 	lui	$t0,%hi(var8007fb14)
/*  f0f0d28:	8c63fb18 */ 	lw	$v1,%lo(var8007fb18)($v1)
/*  f0f0d2c:	8d08fb14 */ 	lw	$t0,%lo(var8007fb14)($t0)
.L0f0f0d30:
/*  f0f0d30:	8faf0098 */ 	lw	$t7,0x98($sp)
/*  f0f0d34:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*  f0f0d38:	8fa900a8 */ 	lw	$t1,0xa8($sp)
/*  f0f0d3c:	3c0b8007 */ 	lui	$t3,%hi(var8007144c)
/*  f0f0d40:	01f83021 */ 	addu	$a2,$t7,$t8
/*  f0f0d44:	256b144c */ 	addiu	$t3,$t3,%lo(var8007144c)
/*  f0f0d48:	00095040 */ 	sll	$t2,$t1,0x1
/*  f0f0d4c:	04c10003 */ 	bgez	$a2,.L0f0f0d5c
/*  f0f0d50:	0006c843 */ 	sra	$t9,$a2,0x1
/*  f0f0d54:	24c10001 */ 	addiu	$at,$a2,0x1
/*  f0f0d58:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f0d5c:
/*  f0f0d5c:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f0f0d60:	94440000 */ 	lhu	$a0,0x0($v0)
/*  f0f0d64:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0f0d68:	afb90084 */ 	sw	$t9,0x84($sp)
/*  f0f0d6c:	afa30064 */ 	sw	$v1,0x64($sp)
/*  f0f0d70:	0fc5b9f1 */ 	jal	langGet
/*  f0f0d74:	afa80060 */ 	sw	$t0,0x60($sp)
/*  f0f0d78:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f0f0d7c:	27a4007c */ 	addiu	$a0,$sp,0x7c
/*  f0f0d80:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0f0d84:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f0d88:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f0f0d8c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f0d90:	0fc55cbe */ 	jal	textMeasure
/*  f0f0d94:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0f0d98:	0fc5b9f1 */ 	jal	langGet
/*  f0f0d9c:	240451ef */ 	addiu	$a0,$zero,0x51ef
/*  f0f0da0:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0f0da4:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f0f0da8:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0f0dac:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f0db0:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f0f0db4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f0db8:	0fc55cbe */ 	jal	textMeasure
/*  f0f0dbc:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0f0dc0:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f0f0dc4:	240151eb */ 	addiu	$at,$zero,0x51eb
/*  f0f0dc8:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f0dcc:	95cf0000 */ 	lhu	$t7,0x0($t6)
/*  f0f0dd0:	55e10005 */ 	bnel	$t7,$at,.L0f0f0de8
/*  f0f0dd4:	8fa2007c */ 	lw	$v0,0x7c($sp)
/*  f0f0dd8:	8fb80078 */ 	lw	$t8,0x78($sp)
/*  f0f0ddc:	27190007 */ 	addiu	$t9,$t8,0x7
/*  f0f0de0:	afb90078 */ 	sw	$t9,0x78($sp)
/*  f0f0de4:	8fa2007c */ 	lw	$v0,0x7c($sp)
.L0f0f0de8:
/*  f0f0de8:	8fa30074 */ 	lw	$v1,0x74($sp)
/*  f0f0dec:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0f0df0:	2405007f */ 	addiu	$a1,$zero,0x7f
/*  f0f0df4:	00434821 */ 	addu	$t1,$v0,$v1
/*  f0f0df8:	05210003 */ 	bgez	$t1,.L0f0f0e08
/*  f0f0dfc:	00095043 */ 	sra	$t2,$t1,0x1
/*  f0f0e00:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0f0e04:	00015043 */ 	sra	$t2,$at,0x1
.L0f0f0e08:
/*  f0f0e08:	00ca3023 */ 	subu	$a2,$a2,$t2
/*  f0f0e0c:	00c26021 */ 	addu	$t4,$a2,$v0
/*  f0f0e10:	01836821 */ 	addu	$t5,$t4,$v1
/*  f0f0e14:	24cbfffc */ 	addiu	$t3,$a2,-4
/*  f0f0e18:	25ae0007 */ 	addiu	$t6,$t5,0x7
/*  f0f0e1c:	afa60080 */ 	sw	$a2,0x80($sp)
/*  f0f0e20:	afab006c */ 	sw	$t3,0x6c($sp)
/*  f0f0e24:	afae0068 */ 	sw	$t6,0x68($sp)
/*  f0f0e28:	0fc54df7 */ 	jal	func0f1537dc
/*  f0f0e2c:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f0e30:	3c038008 */ 	lui	$v1,%hi(g_ScreenWidthMultiplier)
/*  f0f0e34:	2463fac0 */ 	addiu	$v1,$v1,%lo(g_ScreenWidthMultiplier)
/*  f0f0e38:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0f0e3c:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f0f0e40:	8fac00a0 */ 	lw	$t4,0xa0($sp)
/*  f0f0e44:	3c10f600 */ 	lui	$s0,0xf600
/*  f0f0e48:	01f80019 */ 	multu	$t7,$t8
/*  f0f0e4c:	318d03ff */ 	andi	$t5,$t4,0x3ff
/*  f0f0e50:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f0f0e54:	8fb1006c */ 	lw	$s1,0x6c($sp)
/*  f0f0e58:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0f0e5c:	0000c812 */ 	mflo	$t9
/*  f0f0e60:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f0f0e64:	00095380 */ 	sll	$t2,$t1,0xe
/*  f0f0e68:	01505825 */ 	or	$t3,$t2,$s0
/*  f0f0e6c:	016e7825 */ 	or	$t7,$t3,$t6
/*  f0f0e70:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0f0e74:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f0e78:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f0f0e7c:	8fad0098 */ 	lw	$t5,0x98($sp)
/*  f0f0e80:	03190019 */ 	multu	$t8,$t9
/*  f0f0e84:	31ab03ff */ 	andi	$t3,$t5,0x3ff
/*  f0f0e88:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f0f0e8c:	00004812 */ 	mflo	$t1
/*  f0f0e90:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f0f0e94:	000a6380 */ 	sll	$t4,$t2,0xe
/*  f0f0e98:	018e7825 */ 	or	$t7,$t4,$t6
/*  f0f0e9c:	0fc54e0e */ 	jal	func0f153838
/*  f0f0ea0:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0f0ea4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f0ea8:	0fc54df7 */ 	jal	func0f1537dc
/*  f0f0eac:	24057f7f */ 	addiu	$a1,$zero,0x7f7f
/*  f0f0eb0:	3c038008 */ 	lui	$v1,%hi(g_ScreenWidthMultiplier)
/*  f0f0eb4:	2463fac0 */ 	addiu	$v1,$v1,%lo(g_ScreenWidthMultiplier)
/*  f0f0eb8:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f0ebc:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f0f0ec0:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0f0ec4:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0f0ec8:	03190019 */ 	multu	$t8,$t9
/*  f0f0ecc:	318e03ff */ 	andi	$t6,$t4,0x3ff
/*  f0f0ed0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0f0ed4:	322e03ff */ 	andi	$t6,$s1,0x3ff
/*  f0f0ed8:	00004812 */ 	mflo	$t1
/*  f0f0edc:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f0f0ee0:	000a6b80 */ 	sll	$t5,$t2,0xe
/*  f0f0ee4:	01b05825 */ 	or	$t3,$t5,$s0
/*  f0f0ee8:	016fc025 */ 	or	$t8,$t3,$t7
/*  f0f0eec:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0f0ef0:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f0f0ef4:	8fb90094 */ 	lw	$t9,0x94($sp)
/*  f0f0ef8:	000e5880 */ 	sll	$t3,$t6,0x2
/*  f0f0efc:	03290019 */ 	multu	$t9,$t1
/*  f0f0f00:	00005012 */ 	mflo	$t2
/*  f0f0f04:	314d03ff */ 	andi	$t5,$t2,0x3ff
/*  f0f0f08:	000d6380 */ 	sll	$t4,$t5,0xe
/*  f0f0f0c:	018b7825 */ 	or	$t7,$t4,$t3
/*  f0f0f10:	0fc54e0e */ 	jal	func0f153838
/*  f0f0f14:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0f0f18:	3c057f7f */ 	lui	$a1,0x7f7f
/*  f0f0f1c:	34a5ff7f */ 	ori	$a1,$a1,0xff7f
/*  f0f0f20:	0fc54df7 */ 	jal	func0f1537dc
/*  f0f0f24:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f0f28:	3c038008 */ 	lui	$v1,%hi(g_ScreenWidthMultiplier)
/*  f0f0f2c:	2463fac0 */ 	addiu	$v1,$v1,%lo(g_ScreenWidthMultiplier)
/*  f0f0f30:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f0f34:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f0f0f38:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0f0f3c:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f0f0f40:	03190019 */ 	multu	$t8,$t9
/*  f0f0f44:	258b0004 */ 	addiu	$t3,$t4,0x4
/*  f0f0f48:	316f03ff */ 	andi	$t7,$t3,0x3ff
/*  f0f0f4c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0f0f50:	00004812 */ 	mflo	$t1
/*  f0f0f54:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f0f0f58:	000a6b80 */ 	sll	$t5,$t2,0xe
/*  f0f0f5c:	01b07025 */ 	or	$t6,$t5,$s0
/*  f0f0f60:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0f0f64:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0f0f68:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f0f0f6c:	8fa90094 */ 	lw	$t1,0x94($sp)
/*  f0f0f70:	8faf0068 */ 	lw	$t7,0x68($sp)
/*  f0f0f74:	012a0019 */ 	multu	$t1,$t2
/*  f0f0f78:	25ee0002 */ 	addiu	$t6,$t7,0x2
/*  f0f0f7c:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f0f0f80:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0f0f84:	00006812 */ 	mflo	$t5
/*  f0f0f88:	31ac03ff */ 	andi	$t4,$t5,0x3ff
/*  f0f0f8c:	000c5b80 */ 	sll	$t3,$t4,0xe
/*  f0f0f90:	01794825 */ 	or	$t1,$t3,$t9
/*  f0f0f94:	ac490004 */ 	sw	$t1,0x4($v0)
/*  f0f0f98:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f0f0f9c:	8faa009c */ 	lw	$t2,0x9c($sp)
/*  f0f0fa0:	262bfffe */ 	addiu	$t3,$s1,-2
/*  f0f0fa4:	317903ff */ 	andi	$t9,$t3,0x3ff
/*  f0f0fa8:	014d0019 */ 	multu	$t2,$t5
/*  f0f0fac:	00194880 */ 	sll	$t1,$t9,0x2
/*  f0f0fb0:	2639fffc */ 	addiu	$t9,$s1,-4
/*  f0f0fb4:	00006012 */ 	mflo	$t4
/*  f0f0fb8:	318f03ff */ 	andi	$t7,$t4,0x3ff
/*  f0f0fbc:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0f0fc0:	01d0c025 */ 	or	$t8,$t6,$s0
/*  f0f0fc4:	03095025 */ 	or	$t2,$t8,$t1
/*  f0f0fc8:	ac4a0008 */ 	sw	$t2,0x8($v0)
/*  f0f0fcc:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0f0fd0:	8fad0094 */ 	lw	$t5,0x94($sp)
/*  f0f0fd4:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f0f0fd8:	00184880 */ 	sll	$t1,$t8,0x2
/*  f0f0fdc:	01ac0019 */ 	multu	$t5,$t4
/*  f0f0fe0:	00007812 */ 	mflo	$t7
/*  f0f0fe4:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0f0fe8:	000e5b80 */ 	sll	$t3,$t6,0xe
/*  f0f0fec:	01695025 */ 	or	$t2,$t3,$t1
/*  f0f0ff0:	0fc54e0e */ 	jal	func0f153838
/*  f0f0ff4:	ac4a000c */ 	sw	$t2,0xc($v0)
/*  f0f0ff8:	0fc54d8a */ 	jal	func0f153628
/*  f0f0ffc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f1000:	8fad0094 */ 	lw	$t5,0x94($sp)
/*  f0f1004:	8fac00ac */ 	lw	$t4,0xac($sp)
/*  f0f1008:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f0f100c:	8fb800b0 */ 	lw	$t8,0xb0($sp)
/*  f0f1010:	01ac7821 */ 	addu	$t7,$t5,$t4
/*  f0f1014:	01eec821 */ 	addu	$t9,$t7,$t6
/*  f0f1018:	03381823 */ 	subu	$v1,$t9,$t8
/*  f0f101c:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0f1020:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0f1024:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f0f1028:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f102c:	04610003 */ 	bgez	$v1,.L0f0f103c
/*  f0f1030:	00035843 */ 	sra	$t3,$v1,0x1
/*  f0f1034:	24610001 */ 	addiu	$at,$v1,0x1
/*  f0f1038:	00015843 */ 	sra	$t3,$at,0x1
.L0f0f103c:
/*  f0f103c:	01601825 */ 	or	$v1,$t3,$zero
/*  f0f1040:	05210003 */ 	bgez	$t1,.L0f0f1050
/*  f0f1044:	00095043 */ 	sra	$t2,$t1,0x1
/*  f0f1048:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0f104c:	00015043 */ 	sra	$t2,$at,0x1
.L0f0f1050:
/*  f0f1050:	006a6823 */ 	subu	$t5,$v1,$t2
/*  f0f1054:	25ac0002 */ 	addiu	$t4,$t5,0x2
/*  f0f1058:	afac0088 */ 	sw	$t4,0x88($sp)
/*  f0f105c:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f0f1060:	95e40000 */ 	lhu	$a0,0x0($t7)
/*  f0f1064:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f1068:	0fc5b9f1 */ 	jal	langGet
/*  f0f106c:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0f1070:	0c002f02 */ 	jal	viGetX
/*  f0f1074:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f1078:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f107c:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0f1080:	0c002f02 */ 	jal	viGetX
/*  f0f1084:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0f1088:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0f108c:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0f1090:	240b00ff */ 	addiu	$t3,$zero,0xff
/*  f0f1094:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f1098:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f109c:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f10a0:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f10a4:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0f10a8:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f10ac:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f10b0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f10b4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f10b8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f10bc:	0fc5580f */ 	jal	textRenderWhite
/*  f0f10c0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f10c4:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0f10c8:	8fa90044 */ 	lw	$t1,0x44($sp)
/*  f0f10cc:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0f10d0:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f10d4:	05410003 */ 	bgez	$t2,.L0f0f10e4
/*  f0f10d8:	000a6843 */ 	sra	$t5,$t2,0x1
/*  f0f10dc:	25410001 */ 	addiu	$at,$t2,0x1
/*  f0f10e0:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f10e4:
/*  f0f10e4:	012d6023 */ 	subu	$t4,$t1,$t5
/*  f0f10e8:	258f0002 */ 	addiu	$t7,$t4,0x2
/*  f0f10ec:	24c60003 */ 	addiu	$a2,$a2,0x3
/*  f0f10f0:	afaf0088 */ 	sw	$t7,0x88($sp)
/*  f0f10f4:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f10f8:	0fc5b9f1 */ 	jal	langGet
/*  f0f10fc:	240451ef */ 	addiu	$a0,$zero,0x51ef
/*  f0f1100:	0c002f02 */ 	jal	viGetX
/*  f0f1104:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f1108:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f110c:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0f1110:	0c002f02 */ 	jal	viGetX
/*  f0f1114:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0f1118:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0f111c:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0f1120:	240b00ff */ 	addiu	$t3,$zero,0xff
/*  f0f1124:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f1128:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f112c:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f1130:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f1134:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0f1138:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f113c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f1140:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f1144:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f1148:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f114c:	0fc5580f */ 	jal	textRenderWhite
/*  f0f1150:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f1154:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0f1158:	8faa0044 */ 	lw	$t2,0x44($sp)
/*  f0f115c:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f0f1160:	8fa60080 */ 	lw	$a2,0x80($sp)
/*  f0f1164:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f1168:	05210003 */ 	bgez	$t1,.L0f0f1178
/*  f0f116c:	00096843 */ 	sra	$t5,$t1,0x1
/*  f0f1170:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0f1174:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f1178:
/*  f0f1178:	014d6023 */ 	subu	$t4,$t2,$t5
/*  f0f117c:	afac0088 */ 	sw	$t4,0x88($sp)
/*  f0f1180:	95e40000 */ 	lhu	$a0,0x0($t7)
/*  f0f1184:	0fc5b9f1 */ 	jal	langGet
/*  f0f1188:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f118c:	0c002f02 */ 	jal	viGetX
/*  f0f1190:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f1194:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f1198:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0f119c:	0c002f02 */ 	jal	viGetX
/*  f0f11a0:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0f11a4:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0f11a8:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0f11ac:	3c0bbfbf */ 	lui	$t3,0xbfbf
/*  f0f11b0:	356bffff */ 	ori	$t3,$t3,0xffff
/*  f0f11b4:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f11b8:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f11bc:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f11c0:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f11c4:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0f11c8:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f11cc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f11d0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f11d4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f11d8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f11dc:	0fc5580f */ 	jal	textRenderWhite
/*  f0f11e0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f11e4:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0f11e8:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0f11ec:	8fa90044 */ 	lw	$t1,0x44($sp)
/*  f0f11f0:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f11f4:	05410003 */ 	bgez	$t2,.L0f0f1204
/*  f0f11f8:	000a6843 */ 	sra	$t5,$t2,0x1
/*  f0f11fc:	25410001 */ 	addiu	$at,$t2,0x1
/*  f0f1200:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f1204:
/*  f0f1204:	24c60003 */ 	addiu	$a2,$a2,0x3
/*  f0f1208:	012d6023 */ 	subu	$t4,$t1,$t5
/*  f0f120c:	afac0088 */ 	sw	$t4,0x88($sp)
/*  f0f1210:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f1214:	0fc5b9f1 */ 	jal	langGet
/*  f0f1218:	240451ef */ 	addiu	$a0,$zero,0x51ef
/*  f0f121c:	0c002f02 */ 	jal	viGetX
/*  f0f1220:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f1224:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f1228:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f0f122c:	0c002f02 */ 	jal	viGetX
/*  f0f1230:	01e08025 */ 	or	$s0,$t7,$zero
/*  f0f1234:	8fae0064 */ 	lw	$t6,0x64($sp)
/*  f0f1238:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0f123c:	3c18bfbf */ 	lui	$t8,0xbfbf
/*  f0f1240:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f0f1244:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0f1248:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f124c:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f1250:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f1254:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0f1258:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f125c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f1260:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f1264:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f1268:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f126c:	0fc5580f */ 	jal	textRenderWhite
/*  f0f1270:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0f1274:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f0f1278:	8fa60080 */ 	lw	$a2,0x80($sp)
/*  f0f127c:	240151eb */ 	addiu	$at,$zero,0x51eb
/*  f0f1280:	956a0000 */ 	lhu	$t2,0x0($t3)
/*  f0f1284:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f1288:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0f128c:	15410023 */ 	bne	$t2,$at,.L0f0f131c
/*  f0f1290:	24c6ffff */ 	addiu	$a2,$a2,-1
/*  f0f1294:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f0f1298:	05210003 */ 	bgez	$t1,.L0f0f12a8
/*  f0f129c:	00096843 */ 	sra	$t5,$t1,0x1
/*  f0f12a0:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0f12a4:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f12a8:
/*  f0f12a8:	01ac7821 */ 	addu	$t7,$t5,$t4
/*  f0f12ac:	25eefff9 */ 	addiu	$t6,$t7,-7
/*  f0f12b0:	afae0088 */ 	sw	$t6,0x88($sp)
/*  f0f12b4:	0c002f02 */ 	jal	viGetX
/*  f0f12b8:	afa60084 */ 	sw	$a2,0x84($sp)
/*  f0f12bc:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f12c0:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f0f12c4:	0c002f02 */ 	jal	viGetX
/*  f0f12c8:	03208025 */ 	or	$s0,$t9,$zero
/*  f0f12cc:	3c188008 */ 	lui	$t8,%hi(var8007fb08)
/*  f0f12d0:	3c0b8008 */ 	lui	$t3,%hi(var8007fb04)
/*  f0f12d4:	8d6bfb04 */ 	lw	$t3,%lo(var8007fb04)($t3)
/*  f0f12d8:	8f18fb08 */ 	lw	$t8,%lo(var8007fb08)($t8)
/*  f0f12dc:	3c0abfbf */ 	lui	$t2,0xbfbf
/*  f0f12e0:	354affff */ 	ori	$t2,$t2,0xffff
/*  f0f12e4:	3c077f1b */ 	lui	$a3,%hi(var7f1b23e8)
/*  f0f12e8:	24e723e8 */ 	addiu	$a3,$a3,%lo(var7f1b23e8)
/*  f0f12ec:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0f12f0:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f12f4:	27a50088 */ 	addiu	$a1,$sp,0x88
/*  f0f12f8:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0f12fc:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f1300:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f1304:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f1308:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f130c:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0f1310:	0fc5580f */ 	jal	textRenderWhite
/*  f0f1314:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f1318:	00408825 */ 	or	$s1,$v0,$zero
.L0f0f131c:
/*  f0f131c:	0fc54de0 */ 	jal	func0f153780
/*  f0f1320:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f1324:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f1328:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0f132c:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0f1330:	03e00008 */ 	jr	$ra
/*  f0f1334:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

struct menudfc *func0f0f1338(u32 arg0)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (g_Menus[g_MpPlayerNum].unkdfc[i].unk00 == arg0) {
			return &g_Menus[g_MpPlayerNum].unkdfc[i];
		}
	}

	return NULL;
}

void func0f0f139c(s32 arg0, f32 arg1)
{
	struct menudfc *thing = func0f0f1338(arg0);

	if (thing) {
		thing->unk04 = arg1;
		return;
	}

	thing = func0f0f1338(0);

	if (thing) {
		thing->unk00 = arg0;
		thing->unk04 = arg1;
	}
}

void func0f0f13ec(s32 arg0)
{
	struct menudfc *thing = func0f0f1338(arg0);

	if (thing) {
		thing->unk00 = 0;
	}
}

void func0f0f1418(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (g_Menus[g_MpPlayerNum].unkdfc[i].unk00) {
			g_Menus[g_MpPlayerNum].unkdfc[i].unk04 += g_Vars.diffframe60f / 60.0f;
		}
	}
}

void func0f0f1494(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		g_Menus[g_MpPlayerNum].unkdfc[i].unk00 = 0;
	}
}

char *menuResolveText(u32 thing, struct menuitem *item)
{
	char *(*handler)(struct menuitem *item) = (void *)thing;

	// Null/zero
	if (thing == 0) {
		return NULL;
	}

	// Text ID
	if (thing < 0x5a00) {
		return langGet((u32)thing);
	}

	if (thing > (u32)func0f1a78b0) {
		return NULL;
	}

	// Function pointer
	if (handler) {
		return handler(item);
	}

	return "";
}

const u32 var7f1b23f0[] = {0x00000000};
const u32 var7f1b23f4[] = {0x00000000};
const u32 var7f1b23f8[] = {0x00000000};
const u32 var7f1b23fc[] = {0x00000000};

const char var7f1b2400[] = "(BNC:Menu) findItem Warning: Item not found\n";
const char var7f1b2430[] = "(BNC:Menu) menuFirstFocus - Menu %s does not have any focusable item!\n";
const char var7f1b2478[] = "(BNC:Menu) menuLastFocus - Menu %s does not have any focusable item!\n";
const char var7f1b24c0[] = "Init menu %x\n";
const char var7f1b24d0[] = "[]-[] Added Main menu to ctl slot %d\n";
const char var7f1b24f8[] = "[]-[] Added Slide menu to ctl slot %d\n";
const char var7f1b2520[] = "[]-[] StackStart Stats: slides %d, ctlPtr %d slidePtr %d\n";
const char var7f1b255c[] = "$-$-$avePtr: %d\n";
const char var7f1b2570[] = "[]-[] Menu End: now %d slides\n";
const char var7f1b2590[] = "Freeing challenge mem\n";
const char var7f1b25a8[] = "IG:) style %d gbHead:%d\n";
const char var7f1b25c4[] = "GRABBED GUN MEM!\n";
const char var7f1b25d8[] = "Freeing challenge mem\n";
const char var7f1b25f0[] = "mzn";
const char var7f1b25f4[] = "mzf";

const u32 var7f1b25f8[] = {0xbf000000};
const u32 var7f1b25fc[] = {0x50000000};
const u32 var7f1b2600[] = {0xff000000};
const u32 var7f1b2604[] = {0xbfbf0000};
const u32 var7f1b2608[] = {0x50500000};
const u32 var7f1b260c[] = {0xffff0000};
const u32 var7f1b2610[] = {0x0000bf00};
const u32 var7f1b2614[] = {0x00005000};
const u32 var7f1b2618[] = {0x0000ff00};
const u32 var7f1b261c[] = {0xbf00bf00};
const u32 var7f1b2620[] = {0x50005000};
const u32 var7f1b2624[] = {0xff00ff00};
const u32 var7f1b2628[] = {0x00bfbf00};
const u32 var7f1b262c[] = {0x00505000};
const u32 var7f1b2630[] = {0x00ffff00};
const u32 var7f1b2634[] = {0xff885500};
const u32 var7f1b2638[] = {0x7f482000};
const u32 var7f1b263c[] = {0xff885500};
const u32 var7f1b2640[] = {0xff888800};
const u32 var7f1b2644[] = {0x7f484800};
const u32 var7f1b2648[] = {0xff888800};
const u32 var7f1b264c[] = {0x88445500};
const u32 var7f1b2650[] = {0x48242000};
const u32 var7f1b2654[] = {0x88445500};

char *menuResolveParam2Text(struct menuitem *item)
{
	return menuResolveText(item->param2, item);
}

char *menuResolveParam1Text(struct menuitem *item)
{
	return menuResolveText(item->param1, item);
}

void func0f0f15a4(u8 *arg0, u32 *arg1)
{
	switch (*arg0) {
	case 8:
	case 9:
	case 14:
	case 20:
	case 24:
		*arg1 = 1;
		break;
	case 5:
	case 23:
	case 25:
		*arg1 = 2;
		break;
	case 2:
		*arg1 = 3;
		break;
	case 12:
		*arg1 = 4;
		break;
	case 15:
		*arg1 = 5;
		break;
	case 13:
	case 16:
	case 22:
		*arg1 = 3;
		break;
	}
}

GLOBAL_ASM(
glabel func0f0f1618
.late_rodata
glabel var7f1b2860
.word func0f0f1618+0x3dc # f0f19f4
glabel var7f1b2864
.word func0f0f1618+0x118 # f0f1730
glabel var7f1b2868
.word func0f0f1618+0x72c # f0f1d44
glabel var7f1b286c
.word func0f0f1618+0x3dc # f0f19f4
glabel var7f1b2870
.word func0f0f1618+0x59c # f0f1bb4
glabel var7f1b2874
.word func0f0f1618+0x5d8 # f0f1bf0
glabel var7f1b2878
.word func0f0f1618+0x6a4 # f0f1cbc
glabel var7f1b287c
.word func0f0f1618+0x27c # f0f1894
glabel var7f1b2880
.word func0f0f1618+0x2d4 # f0f18ec
glabel var7f1b2884
.word func0f0f1618+0x72c # f0f1d44
glabel var7f1b2888
.word func0f0f1618+0x388 # f0f19a0
glabel var7f1b288c
.word func0f0f1618+0x16c # f0f1784
glabel var7f1b2890
.word func0f0f1618+0x104 # f0f171c
glabel var7f1b2894
.word func0f0f1618+0x6c8 # f0f1ce0
glabel var7f1b2898
.word func0f0f1618+0x6b4 # f0f1ccc
glabel var7f1b289c
.word func0f0f1618+0x6dc # f0f1cf4
glabel var7f1b28a0
.word func0f0f1618+0x718 # f0f1d30
glabel var7f1b28a4
.word func0f0f1618+0x374 # f0f198c
glabel var7f1b28a8
.word func0f0f1618+0x268 # f0f1880
glabel var7f1b28ac
.word func0f0f1618+0xdc # f0f16f4
glabel var7f1b28b0
.word func0f0f1618+0xf0 # f0f1708
glabel var7f1b28b4
.word func0f0f1618+0x704 # f0f1d1c
glabel var7f1b28b8
.word func0f0f1618+0x3ac # f0f19c4
glabel var7f1b28bc
.word func0f0f1618+0xb0 # f0f16c8
glabel var7f1b28c0
.word func0f0f1618+0x9c # f0f16b4
.text
/*  f0f1618:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f0f161c:	3c0e8008 */ 	lui	$t6,%hi(var8007fb10)
/*  f0f1620:	3c0f8008 */ 	lui	$t7,%hi(var8007fb0c)
/*  f0f1624:	8dcefb10 */ 	lw	$t6,%lo(var8007fb10)($t6)
/*  f0f1628:	8deffb0c */ 	lw	$t7,%lo(var8007fb0c)($t7)
/*  f0f162c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0f1630:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f0f1634:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f0f1638:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0f163c:	afae0068 */ 	sw	$t6,0x68($sp)
/*  f0f1640:	afaf0064 */ 	sw	$t7,0x64($sp)
/*  f0f1644:	8c820010 */ 	lw	$v0,0x10($a0)
/*  f0f1648:	00808025 */ 	or	$s0,$a0,$zero
/*  f0f164c:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0f1650:	1040000e */ 	beqz	$v0,.L0f0f168c
/*  f0f1654:	00c09025 */ 	or	$s2,$a2,$zero
/*  f0f1658:	8c980004 */ 	lw	$t8,0x4($a0)
/*  f0f165c:	24040018 */ 	addiu	$a0,$zero,0x18
/*  f0f1660:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f1664:	33190004 */ 	andi	$t9,$t8,0x4
/*  f0f1668:	17200008 */ 	bnez	$t9,.L0f0f168c
/*  f0f166c:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f0f1670:	0040f809 */ 	jalr	$v0
/*  f0f1674:	afa70084 */ 	sw	$a3,0x84($sp)
/*  f0f1678:	10400004 */ 	beqz	$v0,.L0f0f168c
/*  f0f167c:	8fa70084 */ 	lw	$a3,0x84($sp)
/*  f0f1680:	a6200000 */ 	sh	$zero,0x0($s1)
/*  f0f1684:	100001b3 */ 	b	.L0f0f1d54
/*  f0f1688:	a6400000 */ 	sh	$zero,0x0($s2)
.L0f0f168c:
/*  f0f168c:	92080000 */ 	lbu	$t0,0x0($s0)
/*  f0f1690:	2509ffff */ 	addiu	$t1,$t0,-1
/*  f0f1694:	2d210019 */ 	sltiu	$at,$t1,0x19
/*  f0f1698:	102001aa */ 	beqz	$at,.L0f0f1d44
/*  f0f169c:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0f16a0:	3c017f1b */ 	lui	$at,%hi(var7f1b2860)
/*  f0f16a4:	00290821 */ 	addu	$at,$at,$t1
/*  f0f16a8:	8c292860 */ 	lw	$t1,%lo(var7f1b2860)($at)
/*  f0f16ac:	01200008 */ 	jr	$t1
/*  f0f16b0:	00000000 */ 	nop
/*  f0f16b4:	240a0096 */ 	addiu	$t2,$zero,0x96
/*  f0f16b8:	a64a0000 */ 	sh	$t2,0x0($s2)
/*  f0f16bc:	240b00e6 */ 	addiu	$t3,$zero,0xe6
/*  f0f16c0:	100001a4 */ 	b	.L0f0f1d54
/*  f0f16c4:	a62b0000 */ 	sh	$t3,0x0($s1)
/*  f0f16c8:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*  f0f16cc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f16d0:	240e007e */ 	addiu	$t6,$zero,0x7e
/*  f0f16d4:	15810004 */ 	bne	$t4,$at,.L0f0f16e8
/*  f0f16d8:	240f00d2 */ 	addiu	$t7,$zero,0xd2
/*  f0f16dc:	240d00aa */ 	addiu	$t5,$zero,0xaa
/*  f0f16e0:	10000002 */ 	b	.L0f0f16ec
/*  f0f16e4:	a64d0000 */ 	sh	$t5,0x0($s2)
.L0f0f16e8:
/*  f0f16e8:	a64e0000 */ 	sh	$t6,0x0($s2)
.L0f0f16ec:
/*  f0f16ec:	10000199 */ 	b	.L0f0f1d54
/*  f0f16f0:	a62f0000 */ 	sh	$t7,0x0($s1)
/*  f0f16f4:	2418005a */ 	addiu	$t8,$zero,0x5a
/*  f0f16f8:	a6380000 */ 	sh	$t8,0x0($s1)
/*  f0f16fc:	24190036 */ 	addiu	$t9,$zero,0x36
/*  f0f1700:	10000194 */ 	b	.L0f0f1d54
/*  f0f1704:	a6590000 */ 	sh	$t9,0x0($s2)
/*  f0f1708:	24080018 */ 	addiu	$t0,$zero,0x18
/*  f0f170c:	a6280000 */ 	sh	$t0,0x0($s1)
/*  f0f1710:	24090006 */ 	addiu	$t1,$zero,0x6
/*  f0f1714:	1000018f */ 	b	.L0f0f1d54
/*  f0f1718:	a6490000 */ 	sh	$t1,0x0($s2)
/*  f0f171c:	240a0082 */ 	addiu	$t2,$zero,0x82
/*  f0f1720:	a62a0000 */ 	sh	$t2,0x0($s1)
/*  f0f1724:	240b0049 */ 	addiu	$t3,$zero,0x49
/*  f0f1728:	1000018a */ 	b	.L0f0f1d54
/*  f0f172c:	a64b0000 */ 	sh	$t3,0x0($s2)
/*  f0f1730:	8e020008 */ 	lw	$v0,0x8($s0)
/*  f0f1734:	240c0050 */ 	addiu	$t4,$zero,0x50
/*  f0f1738:	24180079 */ 	addiu	$t8,$zero,0x79
/*  f0f173c:	58400004 */ 	blezl	$v0,.L0f0f1750
/*  f0f1740:	a62c0000 */ 	sh	$t4,0x0($s1)
/*  f0f1744:	10000008 */ 	b	.L0f0f1768
/*  f0f1748:	a6220000 */ 	sh	$v0,0x0($s1)
/*  f0f174c:	a62c0000 */ 	sh	$t4,0x0($s1)
.L0f0f1750:
/*  f0f1750:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f0f1754:	240f00b4 */ 	addiu	$t7,$zero,0xb4
/*  f0f1758:	31ae0040 */ 	andi	$t6,$t5,0x40
/*  f0f175c:	51c00003 */ 	beqzl	$t6,.L0f0f176c
/*  f0f1760:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f0f1764:	a62f0000 */ 	sh	$t7,0x0($s1)
.L0f0f1768:
/*  f0f1768:	8e02000c */ 	lw	$v0,0xc($s0)
.L0f0f176c:
/*  f0f176c:	18400003 */ 	blez	$v0,.L0f0f177c
/*  f0f1770:	00000000 */ 	nop
/*  f0f1774:	10000177 */ 	b	.L0f0f1d54
/*  f0f1778:	a6420000 */ 	sh	$v0,0x0($s2)
.L0f0f177c:
/*  f0f177c:	10000175 */ 	b	.L0f0f1d54
/*  f0f1780:	a6580000 */ 	sh	$t8,0x0($s2)
/*  f0f1784:	0fc3c557 */ 	jal	menuResolveParam2Text
/*  f0f1788:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f178c:	1040000b */ 	beqz	$v0,.L0f0f17bc
/*  f0f1790:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f1794:	3c057f1b */ 	lui	$a1,%hi(var7f1b23f0)
/*  f0f1798:	24a523f0 */ 	addiu	$a1,$a1,%lo(var7f1b23f0)
/*  f0f179c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f17a0:	0c004c9d */ 	jal	func00013274
/*  f0f17a4:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f0f17a8:	14400004 */ 	bnez	$v0,.L0f0f17bc
/*  f0f17ac:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0f17b0:	a6200000 */ 	sh	$zero,0x0($s1)
/*  f0f17b4:	10000167 */ 	b	.L0f0f1d54
/*  f0f17b8:	a6400000 */ 	sh	$zero,0x0($s2)
.L0f0f17bc:
/*  f0f17bc:	afa00070 */ 	sw	$zero,0x70($sp)
/*  f0f17c0:	10c0000a */ 	beqz	$a2,.L0f0f17ec
/*  f0f17c4:	afa0006c */ 	sw	$zero,0x6c($sp)
/*  f0f17c8:	3c198008 */ 	lui	$t9,%hi(var8007fb0c)
/*  f0f17cc:	8f39fb0c */ 	lw	$t9,%lo(var8007fb0c)($t9)
/*  f0f17d0:	3c078008 */ 	lui	$a3,%hi(var8007fb10)
/*  f0f17d4:	8ce7fb10 */ 	lw	$a3,%lo(var8007fb10)($a3)
/*  f0f17d8:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0f17dc:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0f17e0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f17e4:	0fc55cbe */ 	jal	textMeasure
/*  f0f17e8:	afb90010 */ 	sw	$t9,0x10($sp)
.L0f0f17ec:
/*  f0f17ec:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f0f17f0:	240a000c */ 	addiu	$t2,$zero,0xc
/*  f0f17f4:	25090014 */ 	addiu	$t1,$t0,0x14
/*  f0f17f8:	a6290000 */ 	sh	$t1,0x0($s1)
/*  f0f17fc:	a64a0000 */ 	sh	$t2,0x0($s2)
/*  f0f1800:	8e0b0010 */ 	lw	$t3,0x10($s0)
/*  f0f1804:	27b20040 */ 	addiu	$s2,$sp,0x40
/*  f0f1808:	51600153 */ 	beqzl	$t3,.L0f0f1d58
/*  f0f180c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0f1810:	afa00040 */ 	sw	$zero,0x40($sp)
/*  f0f1814:	8e190010 */ 	lw	$t9,0x10($s0)
/*  f0f1818:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f0f181c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f1820:	0320f809 */ 	jalr	$t9
/*  f0f1824:	02403025 */ 	or	$a2,$s2,$zero
/*  f0f1828:	afa00044 */ 	sw	$zero,0x44($sp)
/*  f0f182c:	8e190010 */ 	lw	$t9,0x10($s0)
/*  f0f1830:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0f1834:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f1838:	0320f809 */ 	jalr	$t9
/*  f0f183c:	02403025 */ 	or	$a2,$s2,$zero
/*  f0f1840:	3c0c8008 */ 	lui	$t4,%hi(var8007fb0c)
/*  f0f1844:	8d8cfb0c */ 	lw	$t4,%lo(var8007fb0c)($t4)
/*  f0f1848:	3c078008 */ 	lui	$a3,%hi(var8007fb10)
/*  f0f184c:	8ce7fb10 */ 	lw	$a3,%lo(var8007fb10)($a3)
/*  f0f1850:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0f1854:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0f1858:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f185c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f1860:	0fc55cbe */ 	jal	textMeasure
/*  f0f1864:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0f1868:	862d0000 */ 	lh	$t5,0x0($s1)
/*  f0f186c:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f0f1870:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0f1874:	25f8000a */ 	addiu	$t8,$t7,0xa
/*  f0f1878:	10000136 */ 	b	.L0f0f1d54
/*  f0f187c:	a6380000 */ 	sh	$t8,0x0($s1)
/*  f0f1880:	24080046 */ 	addiu	$t0,$zero,0x46
/*  f0f1884:	a6280000 */ 	sh	$t0,0x0($s1)
/*  f0f1888:	24090032 */ 	addiu	$t1,$zero,0x32
/*  f0f188c:	10000131 */ 	b	.L0f0f1d54
/*  f0f1890:	a6490000 */ 	sh	$t1,0x0($s2)
/*  f0f1894:	10e00009 */ 	beqz	$a3,.L0f0f18bc
/*  f0f1898:	24190096 */ 	addiu	$t9,$zero,0x96
/*  f0f189c:	90ea006e */ 	lbu	$t2,0x6e($a3)
/*  f0f18a0:	24020078 */ 	addiu	$v0,$zero,0x78
/*  f0f18a4:	240b0016 */ 	addiu	$t3,$zero,0x16
/*  f0f18a8:	51400005 */ 	beqzl	$t2,.L0f0f18c0
/*  f0f18ac:	a6390000 */ 	sh	$t9,0x0($s1)
/*  f0f18b0:	a6220000 */ 	sh	$v0,0x0($s1)
/*  f0f18b4:	10000127 */ 	b	.L0f0f1d54
/*  f0f18b8:	a64b0000 */ 	sh	$t3,0x0($s2)
.L0f0f18bc:
/*  f0f18bc:	a6390000 */ 	sh	$t9,0x0($s1)
.L0f0f18c0:
/*  f0f18c0:	240c000c */ 	addiu	$t4,$zero,0xc
/*  f0f18c4:	a64c0000 */ 	sh	$t4,0x0($s2)
/*  f0f18c8:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f0f18cc:	24020078 */ 	addiu	$v0,$zero,0x78
/*  f0f18d0:	240f0016 */ 	addiu	$t7,$zero,0x16
/*  f0f18d4:	000d72c0 */ 	sll	$t6,$t5,0xb
/*  f0f18d8:	05c3011f */ 	bgezl	$t6,.L0f0f1d58
/*  f0f18dc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0f18e0:	a64f0000 */ 	sh	$t7,0x0($s2)
/*  f0f18e4:	1000011b */ 	b	.L0f0f1d54
/*  f0f18e8:	a6220000 */ 	sh	$v0,0x0($s1)
/*  f0f18ec:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f0f18f0:	3c098008 */ 	lui	$t1,%hi(var8007fb08)
/*  f0f18f4:	3c0a8008 */ 	lui	$t2,%hi(var8007fb04)
/*  f0f18f8:	33080200 */ 	andi	$t0,$t8,0x200
/*  f0f18fc:	11000005 */ 	beqz	$t0,.L0f0f1914
/*  f0f1900:	00000000 */ 	nop
/*  f0f1904:	8d29fb08 */ 	lw	$t1,%lo(var8007fb08)($t1)
/*  f0f1908:	8d4afb04 */ 	lw	$t2,%lo(var8007fb04)($t2)
/*  f0f190c:	afa90068 */ 	sw	$t1,0x68($sp)
/*  f0f1910:	afaa0064 */ 	sw	$t2,0x64($sp)
.L0f0f1914:
/*  f0f1914:	0fc3c557 */ 	jal	menuResolveParam2Text
/*  f0f1918:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f191c:	14400004 */ 	bnez	$v0,.L0f0f1930
/*  f0f1920:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f1924:	24020078 */ 	addiu	$v0,$zero,0x78
/*  f0f1928:	10000015 */ 	b	.L0f0f1980
/*  f0f192c:	a6220000 */ 	sh	$v0,0x0($s1)
.L0f0f1930:
/*  f0f1930:	3c057f1b */ 	lui	$a1,%hi(var7f1b23f4)
/*  f0f1934:	24a523f4 */ 	addiu	$a1,$a1,%lo(var7f1b23f4)
/*  f0f1938:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0f193c:	0c004c9d */ 	jal	func00013274
/*  f0f1940:	afa60074 */ 	sw	$a2,0x74($sp)
/*  f0f1944:	14400004 */ 	bnez	$v0,.L0f0f1958
/*  f0f1948:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0f194c:	a6200000 */ 	sh	$zero,0x0($s1)
/*  f0f1950:	1000000b */ 	b	.L0f0f1980
/*  f0f1954:	a6400000 */ 	sh	$zero,0x0($s2)
.L0f0f1958:
/*  f0f1958:	8fab0064 */ 	lw	$t3,0x64($sp)
/*  f0f195c:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0f1960:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0f1964:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0f1968:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f196c:	0fc55cbe */ 	jal	textMeasure
/*  f0f1970:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f1974:	87b90072 */ 	lh	$t9,0x72($sp)
/*  f0f1978:	272c0022 */ 	addiu	$t4,$t9,0x22
/*  f0f197c:	a62c0000 */ 	sh	$t4,0x0($s1)
.L0f0f1980:
/*  f0f1980:	240d000c */ 	addiu	$t5,$zero,0xc
/*  f0f1984:	100000f3 */ 	b	.L0f0f1d54
/*  f0f1988:	a64d0000 */ 	sh	$t5,0x0($s2)
/*  f0f198c:	8e0e0008 */ 	lw	$t6,0x8($s0)
/*  f0f1990:	a62e0000 */ 	sh	$t6,0x0($s1)
/*  f0f1994:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f0f1998:	100000ee */ 	b	.L0f0f1d54
/*  f0f199c:	a64f0000 */ 	sh	$t7,0x0($s2)
/*  f0f19a0:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f19a4:	a6380000 */ 	sh	$t8,0x0($s1)
/*  f0f19a8:	8e020008 */ 	lw	$v0,0x8($s0)
/*  f0f19ac:	24080005 */ 	addiu	$t0,$zero,0x5
/*  f0f19b0:	10400002 */ 	beqz	$v0,.L0f0f19bc
/*  f0f19b4:	00000000 */ 	nop
/*  f0f19b8:	a6220000 */ 	sh	$v0,0x0($s1)
.L0f0f19bc:
/*  f0f19bc:	100000e5 */ 	b	.L0f0f1d54
/*  f0f19c0:	a6480000 */ 	sh	$t0,0x0($s2)
/*  f0f19c4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0f19c8:	a6290000 */ 	sh	$t1,0x0($s1)
/*  f0f19cc:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f0f19d0:	2419000b */ 	addiu	$t9,$zero,0xb
/*  f0f19d4:	240c000d */ 	addiu	$t4,$zero,0xd
/*  f0f19d8:	314b0200 */ 	andi	$t3,$t2,0x200
/*  f0f19dc:	11600003 */ 	beqz	$t3,.L0f0f19ec
/*  f0f19e0:	00000000 */ 	nop
/*  f0f19e4:	100000db */ 	b	.L0f0f1d54
/*  f0f19e8:	a6590000 */ 	sh	$t9,0x0($s2)
.L0f0f19ec:
/*  f0f19ec:	100000d9 */ 	b	.L0f0f1d54
/*  f0f19f0:	a64c0000 */ 	sh	$t4,0x0($s2)
/*  f0f19f4:	0fc3c557 */ 	jal	menuResolveParam2Text
/*  f0f19f8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f19fc:	14400004 */ 	bnez	$v0,.L0f0f1a10
/*  f0f1a00:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f1a04:	a6200000 */ 	sh	$zero,0x0($s1)
/*  f0f1a08:	100000d2 */ 	b	.L0f0f1d54
/*  f0f1a0c:	a6400000 */ 	sh	$zero,0x0($s2)
.L0f0f1a10:
/*  f0f1a10:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f0f1a14:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0f1a18:	3c057f1b */ 	lui	$a1,%hi(var7f1b23f8)
/*  f0f1a1c:	304d0200 */ 	andi	$t5,$v0,0x200
/*  f0f1a20:	11a00007 */ 	beqz	$t5,.L0f0f1a40
/*  f0f1a24:	0002c240 */ 	sll	$t8,$v0,0x9
/*  f0f1a28:	3c0e8008 */ 	lui	$t6,%hi(var8007fb08)
/*  f0f1a2c:	3c0f8008 */ 	lui	$t7,%hi(var8007fb04)
/*  f0f1a30:	8dcefb08 */ 	lw	$t6,%lo(var8007fb08)($t6)
/*  f0f1a34:	8deffb04 */ 	lw	$t7,%lo(var8007fb04)($t7)
/*  f0f1a38:	afae0068 */ 	sw	$t6,0x68($sp)
/*  f0f1a3c:	afaf0064 */ 	sw	$t7,0x64($sp)
.L0f0f1a40:
/*  f0f1a40:	07010007 */ 	bgez	$t8,.L0f0f1a60
/*  f0f1a44:	24a523f8 */ 	addiu	$a1,$a1,%lo(var7f1b23f8)
/*  f0f1a48:	3c088008 */ 	lui	$t0,%hi(var8007fb18)
/*  f0f1a4c:	3c098008 */ 	lui	$t1,%hi(var8007fb14)
/*  f0f1a50:	8d08fb18 */ 	lw	$t0,%lo(var8007fb18)($t0)
/*  f0f1a54:	8d29fb14 */ 	lw	$t1,%lo(var8007fb14)($t1)
/*  f0f1a58:	afa80068 */ 	sw	$t0,0x68($sp)
/*  f0f1a5c:	afa90064 */ 	sw	$t1,0x64($sp)
.L0f0f1a60:
/*  f0f1a60:	0c004c9d */ 	jal	func00013274
/*  f0f1a64:	afa60074 */ 	sw	$a2,0x74($sp)
/*  f0f1a68:	14400005 */ 	bnez	$v0,.L0f0f1a80
/*  f0f1a6c:	8fa60074 */ 	lw	$a2,0x74($sp)
/*  f0f1a70:	a6400000 */ 	sh	$zero,0x0($s2)
/*  f0f1a74:	864a0000 */ 	lh	$t2,0x0($s2)
/*  f0f1a78:	1000003d */ 	b	.L0f0f1b70
/*  f0f1a7c:	a62a0000 */ 	sh	$t2,0x0($s1)
.L0f0f1a80:
/*  f0f1a80:	8fab0064 */ 	lw	$t3,0x64($sp)
/*  f0f1a84:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0f1a88:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0f1a8c:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0f1a90:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f1a94:	0fc55cbe */ 	jal	textMeasure
/*  f0f1a98:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f1a9c:	87b90072 */ 	lh	$t9,0x72($sp)
/*  f0f1aa0:	3c010040 */ 	lui	$at,0x40
/*  f0f1aa4:	34218000 */ 	ori	$at,$at,0x8000
/*  f0f1aa8:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f0f1aac:	a62c0000 */ 	sh	$t4,0x0($s1)
/*  f0f1ab0:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f0f1ab4:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f1ab8:	31ae1010 */ 	andi	$t6,$t5,0x1010
/*  f0f1abc:	55c00005 */ 	bnezl	$t6,.L0f0f1ad4
/*  f0f1ac0:	8fa8006c */ 	lw	$t0,0x6c($sp)
/*  f0f1ac4:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0f1ac8:	25f80014 */ 	addiu	$t8,$t7,0x14
/*  f0f1acc:	a6380000 */ 	sh	$t8,0x0($s1)
/*  f0f1ad0:	8fa8006c */ 	lw	$t0,0x6c($sp)
.L0f0f1ad4:
/*  f0f1ad4:	25090003 */ 	addiu	$t1,$t0,0x3
/*  f0f1ad8:	a6490000 */ 	sh	$t1,0x0($s2)
/*  f0f1adc:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f0f1ae0:	304a0200 */ 	andi	$t2,$v0,0x200
/*  f0f1ae4:	51400006 */ 	beqzl	$t2,.L0f0f1b00
/*  f0f1ae8:	00416024 */ 	and	$t4,$v0,$at
/*  f0f1aec:	864b0000 */ 	lh	$t3,0x0($s2)
/*  f0f1af0:	2579fffe */ 	addiu	$t9,$t3,-2
/*  f0f1af4:	a6590000 */ 	sh	$t9,0x0($s2)
/*  f0f1af8:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f0f1afc:	00416024 */ 	and	$t4,$v0,$at
.L0f0f1b00:
/*  f0f1b00:	5580001c */ 	bnezl	$t4,.L0f0f1b74
/*  f0f1b04:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f0f1b08:	0fc3c539 */ 	jal	menuResolveText
/*  f0f1b0c:	8e04000c */ 	lw	$a0,0xc($s0)
/*  f0f1b10:	10400017 */ 	beqz	$v0,.L0f0f1b70
/*  f0f1b14:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f1b18:	3c0d7f1b */ 	lui	$t5,%hi(var7f1b23fc)
/*  f0f1b1c:	25ad23fc */ 	addiu	$t5,$t5,%lo(var7f1b23fc)
/*  f0f1b20:	104d0013 */ 	beq	$v0,$t5,.L0f0f1b70
/*  f0f1b24:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0f1b28:	8fae0064 */ 	lw	$t6,0x64($sp)
/*  f0f1b2c:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0f1b30:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0f1b34:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f1b38:	0fc55cbe */ 	jal	textMeasure
/*  f0f1b3c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f1b40:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0f1b44:	8fb80070 */ 	lw	$t8,0x70($sp)
/*  f0f1b48:	01f84021 */ 	addu	$t0,$t7,$t8
/*  f0f1b4c:	25090005 */ 	addiu	$t1,$t0,0x5
/*  f0f1b50:	a6290000 */ 	sh	$t1,0x0($s1)
/*  f0f1b54:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f0f1b58:	314b1000 */ 	andi	$t3,$t2,0x1000
/*  f0f1b5c:	51600005 */ 	beqzl	$t3,.L0f0f1b74
/*  f0f1b60:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f0f1b64:	86390000 */ 	lh	$t9,0x0($s1)
/*  f0f1b68:	272cfffa */ 	addiu	$t4,$t9,-6
/*  f0f1b6c:	a62c0000 */ 	sh	$t4,0x0($s1)
.L0f0f1b70:
/*  f0f1b70:	8e020004 */ 	lw	$v0,0x4($s0)
.L0f0f1b74:
/*  f0f1b74:	240e001c */ 	addiu	$t6,$zero,0x1c
/*  f0f1b78:	00026a40 */ 	sll	$t5,$v0,0x9
/*  f0f1b7c:	05a30007 */ 	bgezl	$t5,.L0f0f1b9c
/*  f0f1b80:	00024180 */ 	sll	$t0,$v0,0x6
/*  f0f1b84:	a64e0000 */ 	sh	$t6,0x0($s2)
/*  f0f1b88:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f0f1b8c:	25f80024 */ 	addiu	$t8,$t7,0x24
/*  f0f1b90:	a6380000 */ 	sh	$t8,0x0($s1)
/*  f0f1b94:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f0f1b98:	00024180 */ 	sll	$t0,$v0,0x6
.L0f0f1b9c:
/*  f0f1b9c:	0503006e */ 	bgezl	$t0,.L0f0f1d58
/*  f0f1ba0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0f1ba4:	86490000 */ 	lh	$t1,0x0($s2)
/*  f0f1ba8:	252affff */ 	addiu	$t2,$t1,-1
/*  f0f1bac:	10000069 */ 	b	.L0f0f1d54
/*  f0f1bb0:	a64a0000 */ 	sh	$t2,0x0($s2)
/*  f0f1bb4:	8e020008 */ 	lw	$v0,0x8($s0)
/*  f0f1bb8:	240b00f0 */ 	addiu	$t3,$zero,0xf0
/*  f0f1bbc:	24190096 */ 	addiu	$t9,$zero,0x96
/*  f0f1bc0:	58400004 */ 	blezl	$v0,.L0f0f1bd4
/*  f0f1bc4:	a62b0000 */ 	sh	$t3,0x0($s1)
/*  f0f1bc8:	10000002 */ 	b	.L0f0f1bd4
/*  f0f1bcc:	a6220000 */ 	sh	$v0,0x0($s1)
/*  f0f1bd0:	a62b0000 */ 	sh	$t3,0x0($s1)
.L0f0f1bd4:
/*  f0f1bd4:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f0f1bd8:	18400003 */ 	blez	$v0,.L0f0f1be8
/*  f0f1bdc:	00000000 */ 	nop
/*  f0f1be0:	1000005c */ 	b	.L0f0f1d54
/*  f0f1be4:	a6420000 */ 	sh	$v0,0x0($s2)
.L0f0f1be8:
/*  f0f1be8:	1000005a */ 	b	.L0f0f1d54
/*  f0f1bec:	a6590000 */ 	sh	$t9,0x0($s2)
/*  f0f1bf0:	240c00f0 */ 	addiu	$t4,$zero,0xf0
/*  f0f1bf4:	3c03800a */ 	lui	$v1,%hi(g_Briefing)
/*  f0f1bf8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f1bfc:	a62c0000 */ 	sh	$t4,0x0($s1)
/*  f0f1c00:	2463dfc8 */ 	addiu	$v1,$v1,%lo(g_Briefing)
/*  f0f1c04:	946d0002 */ 	lhu	$t5,0x2($v1)
.L0f0f1c08:
/*  f0f1c08:	11a0000d */ 	beqz	$t5,.L0f0f1c40
/*  f0f1c0c:	00000000 */ 	nop
/*  f0f1c10:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f0f1c14:	0fc5b367 */ 	jal	getDifficulty
/*  f0f1c18:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0f1c1c:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f0f1c20:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0f1c24:	004e7804 */ 	sllv	$t7,$t6,$v0
/*  f0f1c28:	9478000e */ 	lhu	$t8,0xe($v1)
/*  f0f1c2c:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0f1c30:	01f84024 */ 	and	$t0,$t7,$t8
/*  f0f1c34:	11000002 */ 	beqz	$t0,.L0f0f1c40
/*  f0f1c38:	00000000 */ 	nop
/*  f0f1c3c:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f0f1c40:
/*  f0f1c40:	3c09800a */ 	lui	$t1,%hi(g_Briefing+0xc)
/*  f0f1c44:	2529dfd4 */ 	addiu	$t1,$t1,%lo(g_Briefing+0xc)
/*  f0f1c48:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0f1c4c:	5469ffee */ 	bnel	$v1,$t1,.L0f0f1c08
/*  f0f1c50:	946d0002 */ 	lhu	$t5,0x2($v1)
/*  f0f1c54:	92020001 */ 	lbu	$v0,0x1($s0)
/*  f0f1c58:	000450c0 */ 	sll	$t2,$a0,0x3
/*  f0f1c5c:	01445021 */ 	addu	$t2,$t2,$a0
/*  f0f1c60:	14400005 */ 	bnez	$v0,.L0f0f1c78
/*  f0f1c64:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f1c68:	000a5040 */ 	sll	$t2,$t2,0x1
/*  f0f1c6c:	254b0009 */ 	addiu	$t3,$t2,0x9
/*  f0f1c70:	10000038 */ 	b	.L0f0f1d54
/*  f0f1c74:	a64b0000 */ 	sh	$t3,0x0($s2)
.L0f0f1c78:
/*  f0f1c78:	14410006 */ 	bne	$v0,$at,.L0f0f1c94
/*  f0f1c7c:	0004c8c0 */ 	sll	$t9,$a0,0x3
/*  f0f1c80:	0324c823 */ 	subu	$t9,$t9,$a0
/*  f0f1c84:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f0f1c88:	272c0009 */ 	addiu	$t4,$t9,0x9
/*  f0f1c8c:	10000031 */ 	b	.L0f0f1d54
/*  f0f1c90:	a64c0000 */ 	sh	$t4,0x0($s2)
.L0f0f1c94:
/*  f0f1c94:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f1c98:	1441002e */ 	bne	$v0,$at,.L0f0f1d54
/*  f0f1c9c:	00046900 */ 	sll	$t5,$a0,0x4
/*  f0f1ca0:	01a46823 */ 	subu	$t5,$t5,$a0
/*  f0f1ca4:	000d6840 */ 	sll	$t5,$t5,0x1
/*  f0f1ca8:	25ae0009 */ 	addiu	$t6,$t5,0x9
/*  f0f1cac:	24020078 */ 	addiu	$v0,$zero,0x78
/*  f0f1cb0:	a64e0000 */ 	sh	$t6,0x0($s2)
/*  f0f1cb4:	10000027 */ 	b	.L0f0f1d54
/*  f0f1cb8:	a6220000 */ 	sh	$v0,0x0($s1)
/*  f0f1cbc:	24020078 */ 	addiu	$v0,$zero,0x78
/*  f0f1cc0:	a6220000 */ 	sh	$v0,0x0($s1)
/*  f0f1cc4:	10000023 */ 	b	.L0f0f1d54
/*  f0f1cc8:	a6420000 */ 	sh	$v0,0x0($s2)
/*  f0f1ccc:	240f007d */ 	addiu	$t7,$zero,0x7d
/*  f0f1cd0:	a62f0000 */ 	sh	$t7,0x0($s1)
/*  f0f1cd4:	24180044 */ 	addiu	$t8,$zero,0x44
/*  f0f1cd8:	1000001e */ 	b	.L0f0f1d54
/*  f0f1cdc:	a6580000 */ 	sh	$t8,0x0($s2)
/*  f0f1ce0:	2408007d */ 	addiu	$t0,$zero,0x7d
/*  f0f1ce4:	a6280000 */ 	sh	$t0,0x0($s1)
/*  f0f1ce8:	2409003a */ 	addiu	$t1,$zero,0x3a
/*  f0f1cec:	10000019 */ 	b	.L0f0f1d54
/*  f0f1cf0:	a6490000 */ 	sh	$t1,0x0($s2)
/*  f0f1cf4:	8e020008 */ 	lw	$v0,0x8($s0)
/*  f0f1cf8:	240b0042 */ 	addiu	$t3,$zero,0x42
/*  f0f1cfc:	10400003 */ 	beqz	$v0,.L0f0f1d0c
/*  f0f1d00:	244a0002 */ 	addiu	$t2,$v0,0x2
/*  f0f1d04:	10000002 */ 	b	.L0f0f1d10
/*  f0f1d08:	a62a0000 */ 	sh	$t2,0x0($s1)
.L0f0f1d0c:
/*  f0f1d0c:	a62b0000 */ 	sh	$t3,0x0($s1)
.L0f0f1d10:
/*  f0f1d10:	86390000 */ 	lh	$t9,0x0($s1)
/*  f0f1d14:	1000000f */ 	b	.L0f0f1d54
/*  f0f1d18:	a6590000 */ 	sh	$t9,0x0($s2)
/*  f0f1d1c:	240c0042 */ 	addiu	$t4,$zero,0x42
/*  f0f1d20:	a62c0000 */ 	sh	$t4,0x0($s1)
/*  f0f1d24:	862d0000 */ 	lh	$t5,0x0($s1)
/*  f0f1d28:	1000000a */ 	b	.L0f0f1d54
/*  f0f1d2c:	a64d0000 */ 	sh	$t5,0x0($s2)
/*  f0f1d30:	240e0082 */ 	addiu	$t6,$zero,0x82
/*  f0f1d34:	a62e0000 */ 	sh	$t6,0x0($s1)
/*  f0f1d38:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f0f1d3c:	10000005 */ 	b	.L0f0f1d54
/*  f0f1d40:	a64f0000 */ 	sh	$t7,0x0($s2)
.L0f0f1d44:
/*  f0f1d44:	24180050 */ 	addiu	$t8,$zero,0x50
/*  f0f1d48:	a6380000 */ 	sh	$t8,0x0($s1)
/*  f0f1d4c:	2408000c */ 	addiu	$t0,$zero,0xc
/*  f0f1d50:	a6480000 */ 	sh	$t0,0x0($s2)
.L0f0f1d54:
/*  f0f1d54:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0f1d58:
/*  f0f1d58:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0f1d5c:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f0f1d60:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f0f1d64:	03e00008 */ 	jr	$ra
/*  f0f1d68:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

GLOBAL_ASM(
glabel func0f0f1d6c
/*  f0f1d6c:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f0f1d70:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0f1d74:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0f1d78:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0f1d7c:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0f1d80:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0f1d84:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0f1d88:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0f1d8c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0f1d90:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0f1d94:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f1d98:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f0f1d9c:	8cc206d8 */ 	lw	$v0,0x6d8($a2)
/*  f0f1da0:	8c910008 */ 	lw	$s1,0x8($a0)
/*  f0f1da4:	84d7081e */ 	lh	$s7,0x81e($a2)
/*  f0f1da8:	8cd6065c */ 	lw	$s6,0x65c($a2)
/*  f0f1dac:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0f1db0:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f0f1db4:	00a0f025 */ 	or	$s8,$a1,$zero
/*  f0f1db8:	00009825 */ 	or	$s3,$zero,$zero
/*  f0f1dbc:	a0a00005 */ 	sb	$zero,0x5($a1)
/*  f0f1dc0:	a0b80004 */ 	sb	$t8,0x4($a1)
/*  f0f1dc4:	1220003a */ 	beqz	$s1,.L0f0f1eb0
/*  f0f1dc8:	a4b70006 */ 	sh	$s7,0x6($a1)
/*  f0f1dcc:	92390000 */ 	lbu	$t9,0x0($s1)
/*  f0f1dd0:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f0f1dd4:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f0f1dd8:	13210035 */ 	beq	$t9,$at,.L0f0f1eb0
/*  f0f1ddc:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f0f1de0:	00024880 */ 	sll	$t1,$v0,0x2
/*  f0f1de4:	01224821 */ 	addu	$t1,$t1,$v0
/*  f0f1de8:	00094840 */ 	sll	$t1,$t1,0x1
/*  f0f1dec:	00165080 */ 	sll	$t2,$s6,0x2
/*  f0f1df0:	010a9021 */ 	addu	$s2,$t0,$t2
/*  f0f1df4:	01098021 */ 	addu	$s0,$t0,$t1
/*  f0f1df8:	2415ffff */ 	addiu	$s5,$zero,-1
.L0f0f1dfc:
/*  f0f1dfc:	8e2b0004 */ 	lw	$t3,0x4($s1)
/*  f0f1e00:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f1e04:	27a50058 */ 	addiu	$a1,$sp,0x58
/*  f0f1e08:	316c0001 */ 	andi	$t4,$t3,0x1
/*  f0f1e0c:	11800002 */ 	beqz	$t4,.L0f0f1e18
/*  f0f1e10:	00000000 */ 	nop
/*  f0f1e14:	24140001 */ 	addiu	$s4,$zero,0x1
.L0f0f1e18:
/*  f0f1e18:	5280000d */ 	beqzl	$s4,.L0f0f1e50
/*  f0f1e1c:	afb50058 */ 	sw	$s5,0x58($sp)
/*  f0f1e20:	93cd0005 */ 	lbu	$t5,0x5($s8)
/*  f0f1e24:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f1e28:	2610000a */ 	addiu	$s0,$s0,0xa
/*  f0f1e2c:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f0f1e30:	a3ce0005 */ 	sb	$t6,0x5($s8)
/*  f0f1e34:	a6000660 */ 	sh	$zero,0x660($s0)
/*  f0f1e38:	a6000662 */ 	sh	$zero,0x662($s0)
/*  f0f1e3c:	a2000664 */ 	sb	$zero,0x664($s0)
/*  f0f1e40:	a2000668 */ 	sb	$zero,0x668($s0)
/*  f0f1e44:	a6160666 */ 	sh	$s6,0x666($s0)
/*  f0f1e48:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0f1e4c:	afb50058 */ 	sw	$s5,0x58($sp)
.L0f0f1e50:
/*  f0f1e50:	0fc3c569 */ 	jal	func0f0f15a4
/*  f0f1e54:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f0f1e58:	8faf0058 */ 	lw	$t7,0x58($sp)
/*  f0f1e5c:	8fa20064 */ 	lw	$v0,0x64($sp)
/*  f0f1e60:	51f50008 */ 	beql	$t7,$s5,.L0f0f1e84
/*  f0f1e64:	a25504ff */ 	sb	$s5,0x4ff($s2)
/*  f0f1e68:	a25704ff */ 	sb	$s7,0x4ff($s2)
/*  f0f1e6c:	87b8005a */ 	lh	$t8,0x5a($sp)
/*  f0f1e70:	02f8b821 */ 	addu	$s7,$s7,$t8
/*  f0f1e74:	0017cc00 */ 	sll	$t9,$s7,0x10
/*  f0f1e78:	10000002 */ 	b	.L0f0f1e84
/*  f0f1e7c:	0019bc03 */ 	sra	$s7,$t9,0x10
/*  f0f1e80:	a25504ff */ 	sb	$s5,0x4ff($s2)
.L0f0f1e84:
/*  f0f1e84:	a25304fe */ 	sb	$s3,0x4fe($s2)
/*  f0f1e88:	92080668 */ 	lbu	$t0,0x668($s0)
/*  f0f1e8c:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f0f1e90:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f0f1e94:	250a0001 */ 	addiu	$t2,$t0,0x1
/*  f0f1e98:	a20a0668 */ 	sb	$t2,0x668($s0)
/*  f0f1e9c:	922b0014 */ 	lbu	$t3,0x14($s1)
/*  f0f1ea0:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f0f1ea4:	26310014 */ 	addiu	$s1,$s1,0x14
/*  f0f1ea8:	1561ffd4 */ 	bne	$t3,$at,.L0f0f1dfc
/*  f0f1eac:	26730001 */ 	addiu	$s3,$s3,0x1
.L0f0f1eb0:
/*  f0f1eb0:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f0f1eb4:	244c0001 */ 	addiu	$t4,$v0,0x1
/*  f0f1eb8:	adac06d8 */ 	sw	$t4,0x6d8($t5)
/*  f0f1ebc:	adb6065c */ 	sw	$s6,0x65c($t5)
/*  f0f1ec0:	adb7081c */ 	sw	$s7,0x81c($t5)
/*  f0f1ec4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f1ec8:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0f1ecc:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0f1ed0:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0f1ed4:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0f1ed8:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0f1edc:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0f1ee0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0f1ee4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0f1ee8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0f1eec:	03e00008 */ 	jr	$ra
/*  f0f1ef0:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel func0f0f1ef4
/*  f0f1ef4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0f1ef8:	afb70024 */ 	sw	$s7,0x24($sp)
/*  f0f1efc:	afb60020 */ 	sw	$s6,0x20($sp)
/*  f0f1f00:	afb5001c */ 	sw	$s5,0x1c($sp)
/*  f0f1f04:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f0f1f08:	afb30014 */ 	sw	$s3,0x14($sp)
/*  f0f1f0c:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f0f1f10:	afb1000c */ 	sw	$s1,0xc($sp)
/*  f0f1f14:	afb00008 */ 	sw	$s0,0x8($sp)
/*  f0f1f18:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f0f1f1c:	8c8d0020 */ 	lw	$t5,0x20($a0)
/*  f0f1f20:	00803025 */ 	or	$a2,$a0,$zero
/*  f0f1f24:	8dcf0010 */ 	lw	$t7,0x10($t6)
/*  f0f1f28:	3c19800a */ 	lui	$t9,%hi(g_MenuData+0x4)
/*  f0f1f2c:	25adfff4 */ 	addiu	$t5,$t5,-12
/*  f0f1f30:	31f80040 */ 	andi	$t8,$t7,0x40
/*  f0f1f34:	57000076 */ 	bnezl	$t8,.L0f0f2110
/*  f0f1f38:	8fb00008 */ 	lw	$s0,0x8($sp)
/*  f0f1f3c:	8f3919c4 */ 	lw	$t9,%lo(g_MenuData+0x4)($t9)
/*  f0f1f40:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0f1f44:	53210072 */ 	beql	$t9,$at,.L0f0f2110
/*  f0f1f48:	8fb00008 */ 	lw	$s0,0x8($sp)
/*  f0f1f4c:	8c8e0028 */ 	lw	$t6,0x28($a0)
/*  f0f1f50:	01ae082a */ 	slt	$at,$t5,$t6
/*  f0f1f54:	5020006e */ 	beqzl	$at,.L0f0f2110
/*  f0f1f58:	8fb00008 */ 	lw	$s0,0x8($sp)
/*  f0f1f5c:	90910005 */ 	lbu	$s1,0x5($a0)
/*  f0f1f60:	00006025 */ 	or	$t4,$zero,$zero
/*  f0f1f64:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f0f1f68:	1a200068 */ 	blez	$s1,.L0f0f210c
/*  f0f1f6c:	3c19800a */ 	lui	$t9,%hi(g_Menus)
/*  f0f1f70:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f0f1f74:	2739e000 */ 	addiu	$t9,$t9,%lo(g_Menus)
/*  f0f1f78:	2410000a */ 	addiu	$s0,$zero,0xa
/*  f0f1f7c:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f1f80:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f1f84:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f1f88:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f1f8c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f1f90:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f1f94:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f1f98:	03192821 */ 	addu	$a1,$t8,$t9
/*  f0f1f9c:	3c0b0020 */ 	lui	$t3,0x20
/*  f0f1fa0:	240a0012 */ 	addiu	$t2,$zero,0x12
/*  f0f1fa4:	24090005 */ 	addiu	$t1,$zero,0x5
/*  f0f1fa8:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f0f1fac:	24070014 */ 	addiu	$a3,$zero,0x14
/*  f0f1fb0:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f0f1fb4:	90ce0004 */ 	lbu	$t6,0x4($a2)
.L0f0f1fb8:
/*  f0f1fb8:	01cc9021 */ 	addu	$s2,$t6,$t4
/*  f0f1fbc:	02500019 */ 	multu	$s2,$s0
/*  f0f1fc0:	258c0001 */ 	addiu	$t4,$t4,0x1
/*  f0f1fc4:	00007812 */ 	mflo	$t7
/*  f0f1fc8:	00af1821 */ 	addu	$v1,$a1,$t7
/*  f0f1fcc:	84780662 */ 	lh	$t8,0x662($v1)
/*  f0f1fd0:	030d1023 */ 	subu	$v0,$t8,$t5
/*  f0f1fd4:	5840004b */ 	blezl	$v0,.L0f0f2104
/*  f0f1fd8:	0191082a */ 	slt	$at,$t4,$s1
/*  f0f1fdc:	90730668 */ 	lbu	$s3,0x668($v1)
/*  f0f1fe0:	00009025 */ 	or	$s2,$zero,$zero
/*  f0f1fe4:	5a600047 */ 	blezl	$s3,.L0f0f2104
/*  f0f1fe8:	0191082a */ 	slt	$at,$t4,$s1
.L0f0f1fec:
/*  f0f1fec:	58400040 */ 	blezl	$v0,.L0f0f20f0
/*  f0f1ff0:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0f1ff4:	94790666 */ 	lhu	$t9,0x666($v1)
/*  f0f1ff8:	00008825 */ 	or	$s1,$zero,$zero
/*  f0f1ffc:	0332a021 */ 	addu	$s4,$t9,$s2
/*  f0f2000:	00147080 */ 	sll	$t6,$s4,0x2
/*  f0f2004:	00aeb021 */ 	addu	$s6,$a1,$t6
/*  f0f2008:	92cf04fe */ 	lbu	$t7,0x4fe($s6)
/*  f0f200c:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f0f2010:	01e70019 */ 	multu	$t7,$a3
/*  f0f2014:	8f2e0008 */ 	lw	$t6,0x8($t9)
/*  f0f2018:	0000c012 */ 	mflo	$t8
/*  f0f201c:	030ea821 */ 	addu	$s5,$t8,$t6
/*  f0f2020:	92b70000 */ 	lbu	$s7,0x0($s5)
/*  f0f2024:	52e80008 */ 	beql	$s7,$t0,.L0f0f2048
/*  f0f2028:	8eaf0004 */ 	lw	$t7,0x4($s5)
/*  f0f202c:	52e90022 */ 	beql	$s7,$t1,.L0f0f20b8
/*  f0f2030:	86d404fc */ 	lh	$s4,0x4fc($s6)
/*  f0f2034:	52ea0020 */ 	beql	$s7,$t2,.L0f0f20b8
/*  f0f2038:	86d404fc */ 	lh	$s4,0x4fc($s6)
/*  f0f203c:	10000024 */ 	b	.L0f0f20d0
/*  f0f2040:	00000000 */ 	nop
/*  f0f2044:	8eaf0004 */ 	lw	$t7,0x4($s5)
.L0f0f2048:
/*  f0f2048:	244e000a */ 	addiu	$t6,$v0,0xa
/*  f0f204c:	01ebc824 */ 	and	$t9,$t7,$t3
/*  f0f2050:	13200009 */ 	beqz	$t9,.L0f0f2078
/*  f0f2054:	00000000 */ 	nop
/*  f0f2058:	86d404fc */ 	lh	$s4,0x4fc($s6)
/*  f0f205c:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f2060:	0282c023 */ 	subu	$t8,$s4,$v0
/*  f0f2064:	2b01001e */ 	slti	$at,$t8,0x1e
/*  f0f2068:	10200019 */ 	beqz	$at,.L0f0f20d0
/*  f0f206c:	00000000 */ 	nop
/*  f0f2070:	10000017 */ 	b	.L0f0f20d0
/*  f0f2074:	2691ffe2 */ 	addiu	$s1,$s4,-30
.L0f0f2078:
/*  f0f2078:	01c4001a */ 	div	$zero,$t6,$a0
/*  f0f207c:	00007812 */ 	mflo	$t7
/*  f0f2080:	14800002 */ 	bnez	$a0,.L0f0f208c
/*  f0f2084:	00000000 */ 	nop
/*  f0f2088:	0007000d */ 	break	0x7
.L0f0f208c:
/*  f0f208c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f2090:	14810004 */ 	bne	$a0,$at,.L0f0f20a4
/*  f0f2094:	3c018000 */ 	lui	$at,0x8000
/*  f0f2098:	15c10002 */ 	bne	$t6,$at,.L0f0f20a4
/*  f0f209c:	00000000 */ 	nop
/*  f0f20a0:	0006000d */ 	break	0x6
.L0f0f20a4:
/*  f0f20a4:	01e40019 */ 	multu	$t7,$a0
/*  f0f20a8:	00008812 */ 	mflo	$s1
/*  f0f20ac:	10000008 */ 	b	.L0f0f20d0
/*  f0f20b0:	00000000 */ 	nop
/*  f0f20b4:	86d404fc */ 	lh	$s4,0x4fc($s6)
.L0f0f20b8:
/*  f0f20b8:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f20bc:	0282c823 */ 	subu	$t9,$s4,$v0
/*  f0f20c0:	2b210032 */ 	slti	$at,$t9,0x32
/*  f0f20c4:	10200002 */ 	beqz	$at,.L0f0f20d0
/*  f0f20c8:	00000000 */ 	nop
/*  f0f20cc:	2691ffce */ 	addiu	$s1,$s4,-50
.L0f0f20d0:
/*  f0f20d0:	5a200007 */ 	blezl	$s1,.L0f0f20f0
/*  f0f20d4:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0f20d8:	86d804fc */ 	lh	$t8,0x4fc($s6)
/*  f0f20dc:	00511023 */ 	subu	$v0,$v0,$s1
/*  f0f20e0:	03117023 */ 	subu	$t6,$t8,$s1
/*  f0f20e4:	a6ce04fc */ 	sh	$t6,0x4fc($s6)
/*  f0f20e8:	90730668 */ 	lbu	$s3,0x668($v1)
/*  f0f20ec:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f0f20f0:
/*  f0f20f0:	0253082a */ 	slt	$at,$s2,$s3
/*  f0f20f4:	1420ffbd */ 	bnez	$at,.L0f0f1fec
/*  f0f20f8:	00000000 */ 	nop
/*  f0f20fc:	90d10005 */ 	lbu	$s1,0x5($a2)
/*  f0f2100:	0191082a */ 	slt	$at,$t4,$s1
.L0f0f2104:
/*  f0f2104:	5420ffac */ 	bnezl	$at,.L0f0f1fb8
/*  f0f2108:	90ce0004 */ 	lbu	$t6,0x4($a2)
.L0f0f210c:
/*  f0f210c:	8fb00008 */ 	lw	$s0,0x8($sp)
.L0f0f2110:
/*  f0f2110:	8fb1000c */ 	lw	$s1,0xc($sp)
/*  f0f2114:	8fb20010 */ 	lw	$s2,0x10($sp)
/*  f0f2118:	8fb30014 */ 	lw	$s3,0x14($sp)
/*  f0f211c:	8fb40018 */ 	lw	$s4,0x18($sp)
/*  f0f2120:	8fb5001c */ 	lw	$s5,0x1c($sp)
/*  f0f2124:	8fb60020 */ 	lw	$s6,0x20($sp)
/*  f0f2128:	8fb70024 */ 	lw	$s7,0x24($sp)
/*  f0f212c:	03e00008 */ 	jr	$ra
/*  f0f2130:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f0f2134
/*  f0f2134:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0f2138:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0f213c:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f0f2140:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f0f2144:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f0f2148:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f0f214c:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f0f2150:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f0f2154:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f0f2158:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f0f215c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0f2160:	afa5009c */ 	sw	$a1,0x9c($sp)
/*  f0f2164:	8c920008 */ 	lw	$s2,0x8($a0)
/*  f0f2168:	90a20004 */ 	lbu	$v0,0x4($a1)
/*  f0f216c:	00c0f025 */ 	or	$s8,$a2,$zero
/*  f0f2170:	12400030 */ 	beqz	$s2,.L0f0f2234
/*  f0f2174:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0f2178:	924f0000 */ 	lbu	$t7,0x0($s2)
/*  f0f217c:	2417001a */ 	addiu	$s7,$zero,0x1a
/*  f0f2180:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f0f2184:	12ef002b */ 	beq	$s7,$t7,.L0f0f2234
/*  f0f2188:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f0f218c:	0302c021 */ 	addu	$t8,$t8,$v0
/*  f0f2190:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f0f2194:	00d88021 */ 	addu	$s0,$a2,$t8
/*  f0f2198:	27b60068 */ 	addiu	$s6,$sp,0x68
/*  f0f219c:	27b5006a */ 	addiu	$s5,$sp,0x6a
/*  f0f21a0:	8fb30090 */ 	lw	$s3,0x90($sp)
/*  f0f21a4:	8e590004 */ 	lw	$t9,0x4($s2)
.L0f0f21a8:
/*  f0f21a8:	02402025 */ 	or	$a0,$s2,$zero
/*  f0f21ac:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0f21b0:	33280001 */ 	andi	$t0,$t9,0x1
/*  f0f21b4:	11000002 */ 	beqz	$t0,.L0f0f21c0
/*  f0f21b8:	02c03025 */ 	or	$a2,$s6,$zero
/*  f0f21bc:	24140001 */ 	addiu	$s4,$zero,0x1
.L0f0f21c0:
/*  f0f21c0:	52800007 */ 	beqzl	$s4,.L0f0f21e0
/*  f0f21c4:	00134880 */ 	sll	$t1,$s3,0x2
/*  f0f21c8:	2610000a */ 	addiu	$s0,$s0,0xa
/*  f0f21cc:	a6000660 */ 	sh	$zero,0x660($s0)
/*  f0f21d0:	a6000662 */ 	sh	$zero,0x662($s0)
/*  f0f21d4:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0f21d8:	96130666 */ 	lhu	$s3,0x666($s0)
/*  f0f21dc:	00134880 */ 	sll	$t1,$s3,0x2
.L0f0f21e0:
/*  f0f21e0:	03c98821 */ 	addu	$s1,$s8,$t1
/*  f0f21e4:	0fc3c586 */ 	jal	func0f0f1618
/*  f0f21e8:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0f21ec:	860a0660 */ 	lh	$t2,0x660($s0)
/*  f0f21f0:	87ab006a */ 	lh	$t3,0x6a($sp)
/*  f0f21f4:	014b082a */ 	slt	$at,$t2,$t3
/*  f0f21f8:	50200003 */ 	beqzl	$at,.L0f0f2208
/*  f0f21fc:	87ac0068 */ 	lh	$t4,0x68($sp)
/*  f0f2200:	a60b0660 */ 	sh	$t3,0x660($s0)
/*  f0f2204:	87ac0068 */ 	lh	$t4,0x68($sp)
.L0f0f2208:
/*  f0f2208:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0f220c:	26520014 */ 	addiu	$s2,$s2,0x14
/*  f0f2210:	a62c04fc */ 	sh	$t4,0x4fc($s1)
/*  f0f2214:	860d0662 */ 	lh	$t5,0x662($s0)
/*  f0f2218:	87ae0068 */ 	lh	$t6,0x68($sp)
/*  f0f221c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0f2220:	a60f0662 */ 	sh	$t7,0x662($s0)
/*  f0f2224:	92580000 */ 	lbu	$t8,0x0($s2)
/*  f0f2228:	56f8ffdf */ 	bnel	$s7,$t8,.L0f0f21a8
/*  f0f222c:	8e590004 */ 	lw	$t9,0x4($s2)
/*  f0f2230:	afb30090 */ 	sw	$s3,0x90($sp)
.L0f0f2234:
/*  f0f2234:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f0f2238:	00008025 */ 	or	$s0,$zero,$zero
/*  f0f223c:	00008825 */ 	or	$s1,$zero,$zero
/*  f0f2240:	93220005 */ 	lbu	$v0,0x5($t9)
/*  f0f2244:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f2248:	8fab009c */ 	lw	$t3,0x9c($sp)
/*  f0f224c:	18400013 */ 	blez	$v0,.L0f0f229c
/*  f0f2250:	00023080 */ 	sll	$a2,$v0,0x2
/*  f0f2254:	93280004 */ 	lbu	$t0,0x4($t9)
/*  f0f2258:	00c23021 */ 	addu	$a2,$a2,$v0
/*  f0f225c:	00063040 */ 	sll	$a2,$a2,0x1
/*  f0f2260:	00084880 */ 	sll	$t1,$t0,0x2
/*  f0f2264:	01284821 */ 	addu	$t1,$t1,$t0
/*  f0f2268:	00094840 */ 	sll	$t1,$t1,0x1
/*  f0f226c:	03c92821 */ 	addu	$a1,$s8,$t1
/*  f0f2270:	00a31021 */ 	addu	$v0,$a1,$v1
.L0f0f2274:
/*  f0f2274:	84440662 */ 	lh	$a0,0x662($v0)
/*  f0f2278:	844a0660 */ 	lh	$t2,0x660($v0)
/*  f0f227c:	2463000a */ 	addiu	$v1,$v1,0xa
/*  f0f2280:	0204082a */ 	slt	$at,$s0,$a0
/*  f0f2284:	10200002 */ 	beqz	$at,.L0f0f2290
/*  f0f2288:	022a8821 */ 	addu	$s1,$s1,$t2
/*  f0f228c:	00808025 */ 	or	$s0,$a0,$zero
.L0f0f2290:
/*  f0f2290:	0066082a */ 	slt	$at,$v1,$a2
/*  f0f2294:	5420fff7 */ 	bnezl	$at,.L0f0f2274
/*  f0f2298:	00a31021 */ 	addu	$v0,$a1,$v1
.L0f0f229c:
/*  f0f229c:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f0f22a0:	0fc3c560 */ 	jal	menuResolveParam1Text
/*  f0f22a4:	8d640000 */ 	lw	$a0,0x0($t3)
/*  f0f22a8:	3c0c8008 */ 	lui	$t4,%hi(var8007fb0c)
/*  f0f22ac:	8d8cfb0c */ 	lw	$t4,%lo(var8007fb0c)($t4)
/*  f0f22b0:	3c078008 */ 	lui	$a3,%hi(var8007fb10)
/*  f0f22b4:	8ce7fb10 */ 	lw	$a3,%lo(var8007fb10)($a3)
/*  f0f22b8:	27a4007c */ 	addiu	$a0,$sp,0x7c
/*  f0f22bc:	27a50080 */ 	addiu	$a1,$sp,0x80
/*  f0f22c0:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f22c4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f22c8:	0fc55cbe */ 	jal	textMeasure
/*  f0f22cc:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0f22d0:	3c02800a */ 	lui	$v0,%hi(g_MenuData+0x4)
/*  f0f22d4:	8c4219c4 */ 	lw	$v0,%lo(g_MenuData+0x4)($v0)
/*  f0f22d8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f22dc:	24030008 */ 	addiu	$v1,$zero,0x8
/*  f0f22e0:	10410008 */ 	beq	$v0,$at,.L0f0f2304
/*  f0f22e4:	8fad0080 */ 	lw	$t5,0x80($sp)
/*  f0f22e8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f22ec:	10410005 */ 	beq	$v0,$at,.L0f0f2304
/*  f0f22f0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f22f4:	10410003 */ 	beq	$v0,$at,.L0f0f2304
/*  f0f22f8:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0f22fc:	54410003 */ 	bnel	$v0,$at,.L0f0f230c
/*  f0f2300:	01a31021 */ 	addu	$v0,$t5,$v1
.L0f0f2304:
/*  f0f2304:	24030011 */ 	addiu	$v1,$zero,0x11
/*  f0f2308:	01a31021 */ 	addu	$v0,$t5,$v1
.L0f0f230c:
/*  f0f230c:	0222082a */ 	slt	$at,$s1,$v0
/*  f0f2310:	10200002 */ 	beqz	$at,.L0f0f231c
/*  f0f2314:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f0f2318:	00408825 */ 	or	$s1,$v0,$zero
.L0f0f231c:
/*  f0f231c:	add10024 */ 	sw	$s1,0x24($t6)
/*  f0f2320:	add00028 */ 	sw	$s0,0x28($t6)
/*  f0f2324:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0f2328:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f0f232c:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f0f2330:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f0f2334:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f0f2338:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f0f233c:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f0f2340:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f0f2344:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f0f2348:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0f234c:	03e00008 */ 	jr	$ra
/*  f0f2350:	27bd0098 */ 	addiu	$sp,$sp,0x98
);

GLOBAL_ASM(
glabel func0f0f2354
/*  f0f2354:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*  f0f2358:	afb1000c */ 	sw	$s1,0xc($sp)
/*  f0f235c:	afb00008 */ 	sw	$s0,0x8($sp)
/*  f0f2360:	90820004 */ 	lbu	$v0,0x4($a0)
/*  f0f2364:	3c0c8007 */ 	lui	$t4,%hi(g_MpPlayerNum)
/*  f0f2368:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0f236c:	ace20000 */ 	sw	$v0,0x0($a3)
/*  f0f2370:	908f0005 */ 	lbu	$t7,0x5($a0)
/*  f0f2374:	90830004 */ 	lbu	$v1,0x4($a0)
/*  f0f2378:	258c1448 */ 	addiu	$t4,$t4,%lo(g_MpPlayerNum)
/*  f0f237c:	24110014 */ 	addiu	$s1,$zero,0x14
/*  f0f2380:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f0f2384:	0058082a */ 	slt	$at,$v0,$t8
/*  f0f2388:	10200051 */ 	beqz	$at,.L0f0f24d0
/*  f0f238c:	240d000a */ 	addiu	$t5,$zero,0xa
/*  f0f2390:	3c0b800a */ 	lui	$t3,%hi(g_Menus)
/*  f0f2394:	256be000 */ 	addiu	$t3,$t3,%lo(g_Menus)
.L0f0f2398:
/*  f0f2398:	004d0019 */ 	multu	$v0,$t5
/*  f0f239c:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f0f23a0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f23a4:	001970c0 */ 	sll	$t6,$t9,0x3
/*  f0f23a8:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0f23ac:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f23b0:	01d97021 */ 	addu	$t6,$t6,$t9
/*  f0f23b4:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0f23b8:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0f23bc:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0f23c0:	0000c012 */ 	mflo	$t8
/*  f0f23c4:	016e7821 */ 	addu	$t7,$t3,$t6
/*  f0f23c8:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f0f23cc:	97290666 */ 	lhu	$t1,0x666($t9)
/*  f0f23d0:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f0f23d4:	8ce20000 */ 	lw	$v0,0x0($a3)
/*  f0f23d8:	8d8f0000 */ 	lw	$t7,0x0($t4)
/*  f0f23dc:	004d0019 */ 	multu	$v0,$t5
/*  f0f23e0:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f23e4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f23e8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f23ec:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f23f0:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f23f4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f23f8:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f23fc:	01782821 */ 	addu	$a1,$t3,$t8
/*  f0f2400:	0000c812 */ 	mflo	$t9
/*  f0f2404:	00b94021 */ 	addu	$t0,$a1,$t9
/*  f0f2408:	910e0668 */ 	lbu	$t6,0x668($t0)
/*  f0f240c:	950f0666 */ 	lhu	$t7,0x666($t0)
/*  f0f2410:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0f2414:	0138082a */ 	slt	$at,$t1,$t8
/*  f0f2418:	10200024 */ 	beqz	$at,.L0f0f24ac
/*  f0f241c:	0009c880 */ 	sll	$t9,$t1,0x2
.L0f0f2420:
/*  f0f2420:	00b95021 */ 	addu	$t2,$a1,$t9
/*  f0f2424:	914e04fe */ 	lbu	$t6,0x4fe($t2)
/*  f0f2428:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f0f242c:	01d10019 */ 	multu	$t6,$s1
/*  f0f2430:	8f190008 */ 	lw	$t9,0x8($t8)
/*  f0f2434:	25380001 */ 	addiu	$t8,$t1,0x1
/*  f0f2438:	00007812 */ 	mflo	$t7
/*  f0f243c:	01f91021 */ 	addu	$v0,$t7,$t9
/*  f0f2440:	54500004 */ 	bnel	$v0,$s0,.L0f0f2454
/*  f0f2444:	854e04fc */ 	lh	$t6,0x4fc($t2)
/*  f0f2448:	10000036 */ 	b	.L0f0f2524
/*  f0f244c:	00601025 */ 	or	$v0,$v1,$zero
/*  f0f2450:	854e04fc */ 	lh	$t6,0x4fc($t2)
.L0f0f2454:
/*  f0f2454:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f0f2458:	8ce20000 */ 	lw	$v0,0x0($a3)
/*  f0f245c:	8d8f0000 */ 	lw	$t7,0x0($t4)
/*  f0f2460:	01c31821 */ 	addu	$v1,$t6,$v1
/*  f0f2464:	004d0019 */ 	multu	$v0,$t5
/*  f0f2468:	000fc8c0 */ 	sll	$t9,$t7,0x3
/*  f0f246c:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f0f2470:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f2474:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f0f2478:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0f247c:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f0f2480:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0f2484:	01792821 */ 	addu	$a1,$t3,$t9
/*  f0f2488:	03004825 */ 	or	$t1,$t8,$zero
/*  f0f248c:	00007012 */ 	mflo	$t6
/*  f0f2490:	00ae4021 */ 	addu	$t0,$a1,$t6
/*  f0f2494:	91180668 */ 	lbu	$t8,0x668($t0)
/*  f0f2498:	950f0666 */ 	lhu	$t7,0x666($t0)
/*  f0f249c:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f0f24a0:	0139082a */ 	slt	$at,$t1,$t9
/*  f0f24a4:	5420ffde */ 	bnezl	$at,.L0f0f2420
/*  f0f24a8:	0009c880 */ 	sll	$t9,$t1,0x2
.L0f0f24ac:
/*  f0f24ac:	244e0001 */ 	addiu	$t6,$v0,0x1
/*  f0f24b0:	acee0000 */ 	sw	$t6,0x0($a3)
/*  f0f24b4:	90980005 */ 	lbu	$t8,0x5($a0)
/*  f0f24b8:	90830004 */ 	lbu	$v1,0x4($a0)
/*  f0f24bc:	01c01025 */ 	or	$v0,$t6,$zero
/*  f0f24c0:	00787821 */ 	addu	$t7,$v1,$t8
/*  f0f24c4:	01cf082a */ 	slt	$at,$t6,$t7
/*  f0f24c8:	1420ffb3 */ 	bnez	$at,.L0f0f2398
/*  f0f24cc:	00000000 */ 	nop
.L0f0f24d0:
/*  f0f24d0:	3c0c8007 */ 	lui	$t4,%hi(g_MpPlayerNum)
/*  f0f24d4:	258c1448 */ 	addiu	$t4,$t4,%lo(g_MpPlayerNum)
/*  f0f24d8:	240d000a */ 	addiu	$t5,$zero,0xa
/*  f0f24dc:	ace30000 */ 	sw	$v1,0x0($a3)
/*  f0f24e0:	006d0019 */ 	multu	$v1,$t5
/*  f0f24e4:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f0f24e8:	3c0b800a */ 	lui	$t3,%hi(g_Menus)
/*  f0f24ec:	256be000 */ 	addiu	$t3,$t3,%lo(g_Menus)
/*  f0f24f0:	001970c0 */ 	sll	$t6,$t9,0x3
/*  f0f24f4:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0f24f8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f24fc:	01d97021 */ 	addu	$t6,$t6,$t9
/*  f0f2500:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0f2504:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0f2508:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0f250c:	016ec021 */ 	addu	$t8,$t3,$t6
/*  f0f2510:	0000c812 */ 	mflo	$t9
/*  f0f2514:	03197021 */ 	addu	$t6,$t8,$t9
/*  f0f2518:	95cf0666 */ 	lhu	$t7,0x666($t6)
/*  f0f251c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f2520:	accf0000 */ 	sw	$t7,0x0($a2)
.L0f0f2524:
/*  f0f2524:	8fb00008 */ 	lw	$s0,0x8($sp)
/*  f0f2528:	8fb1000c */ 	lw	$s1,0xc($sp)
/*  f0f252c:	03e00008 */ 	jr	$ra
/*  f0f2530:	27bd0010 */ 	addiu	$sp,$sp,0x10
);

GLOBAL_ASM(
glabel func0f0f2534
/*  f0f2534:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f0f2538:	24030005 */ 	addiu	$v1,$zero,0x5
/*  f0f253c:	546e0010 */ 	bnel	$v1,$t6,.L0f0f2580
/*  f0f2540:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f2544:	90820001 */ 	lbu	$v0,0x1($a0)
/*  f0f2548:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f254c:	10410009 */ 	beq	$v0,$at,.L0f0f2574
/*  f0f2550:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f2554:	10410007 */ 	beq	$v0,$at,.L0f0f2574
/*  f0f2558:	00000000 */ 	nop
/*  f0f255c:	10620005 */ 	beq	$v1,$v0,.L0f0f2574
/*  f0f2560:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0f2564:	10410003 */ 	beq	$v0,$at,.L0f0f2574
/*  f0f2568:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0f256c:	54410004 */ 	bnel	$v0,$at,.L0f0f2580
/*  f0f2570:	00001025 */ 	or	$v0,$zero,$zero
.L0f0f2574:
/*  f0f2574:	03e00008 */ 	jr	$ra
/*  f0f2578:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0f257c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0f2580:
/*  f0f2580:	03e00008 */ 	jr	$ra
/*  f0f2584:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0f2588
/*  f0f2588:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0f258c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0f2590:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f2594:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0f2598:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*  f0f259c:	00808025 */ 	or	$s0,$a0,$zero
/*  f0f25a0:	3c048007 */ 	lui	$a0,%hi(g_MpPlayerNum)
/*  f0f25a4:	31cf0400 */ 	andi	$t7,$t6,0x400
/*  f0f25a8:	11e00003 */ 	beqz	$t7,.L0f0f25b8
/*  f0f25ac:	00000000 */ 	nop
/*  f0f25b0:	1000002b */ 	b	.L0f0f2660
/*  f0f25b4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0f25b8:
/*  f0f25b8:	0fc62ff6 */ 	jal	mpIsPlayerLockedOut
/*  f0f25bc:	8c841448 */ 	lw	$a0,%lo(g_MpPlayerNum)($a0)
/*  f0f25c0:	10400007 */ 	beqz	$v0,.L0f0f25e0
/*  f0f25c4:	00000000 */ 	nop
/*  f0f25c8:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f0f25cc:	0018cb40 */ 	sll	$t9,$t8,0xd
/*  f0f25d0:	07210003 */ 	bgez	$t9,.L0f0f25e0
/*  f0f25d4:	00000000 */ 	nop
/*  f0f25d8:	10000021 */ 	b	.L0f0f2660
/*  f0f25dc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0f25e0:
/*  f0f25e0:	0fc3c94d */ 	jal	func0f0f2534
/*  f0f25e4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f25e8:	50400004 */ 	beqzl	$v0,.L0f0f25fc
/*  f0f25ec:	8e020010 */ 	lw	$v0,0x10($s0)
/*  f0f25f0:	1000001b */ 	b	.L0f0f2660
/*  f0f25f4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0f25f8:	8e020010 */ 	lw	$v0,0x10($s0)
.L0f0f25fc:
/*  f0f25fc:	5040000e */ 	beqzl	$v0,.L0f0f2638
/*  f0f2600:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f2604:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f0f2608:	2404000c */ 	addiu	$a0,$zero,0xc
/*  f0f260c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f2610:	31090004 */ 	andi	$t1,$t0,0x4
/*  f0f2614:	55200008 */ 	bnezl	$t1,.L0f0f2638
/*  f0f2618:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f261c:	0040f809 */ 	jalr	$v0
/*  f0f2620:	27a60030 */ 	addiu	$a2,$sp,0x30
/*  f0f2624:	50400004 */ 	beqzl	$v0,.L0f0f2638
/*  f0f2628:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f262c:	1000000c */ 	b	.L0f0f2660
/*  f0f2630:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0f2634:	02002025 */ 	or	$a0,$s0,$zero
.L0f0f2638:
/*  f0f2638:	27a5002e */ 	addiu	$a1,$sp,0x2e
/*  f0f263c:	27a6002c */ 	addiu	$a2,$sp,0x2c
/*  f0f2640:	0fc3c586 */ 	jal	func0f0f1618
/*  f0f2644:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f0f2648:	87aa002c */ 	lh	$t2,0x2c($sp)
/*  f0f264c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f2650:	15400003 */ 	bnez	$t2,.L0f0f2660
/*  f0f2654:	00000000 */ 	nop
/*  f0f2658:	10000001 */ 	b	.L0f0f2660
/*  f0f265c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0f2660:
/*  f0f2660:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0f2664:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0f2668:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f0f266c:	03e00008 */ 	jr	$ra
/*  f0f2670:	00000000 */ 	nop
);

bool func0f0f2674(u8 *arg0, u32 arg1, u32 arg2)
{
	u32 thing1;
	u32 thing2;

	switch (*arg0) {
	case 1:
	case 6:
	case 7:
	case 11:
	case 18:
	case 19:
	case 21:
	case 23:
	case 25:
		return false;
	case 16:
	case 20:
	case 22:
	case 24:
		func0f0f2354(arg1, arg0, &thing1, &thing2);
	}

	if (func0f0f2588(arg0, arg1)) {
		return false;
	}

	return true;
}

GLOBAL_ASM(
glabel func0f0f26fc
/*  f0f26fc:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f0f2700:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f0f2704:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0f2708:	3c18800a */ 	lui	$t8,%hi(g_Menus)
/*  f0f270c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f2710:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f2714:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f2718:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f271c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f2720:	00054080 */ 	sll	$t0,$a1,0x2
/*  f0f2724:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f2728:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f272c:	01054021 */ 	addu	$t0,$t0,$a1
/*  f0f2730:	2718e000 */ 	addiu	$t8,$t8,%lo(g_Menus)
/*  f0f2734:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f0f2738:	00084040 */ 	sll	$t0,$t0,0x1
/*  f0f273c:	00681021 */ 	addu	$v0,$v1,$t0
/*  f0f2740:	90590668 */ 	lbu	$t9,0x668($v0)
/*  f0f2744:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0f2748:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0f274c:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0f2750:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0f2754:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0f2758:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0f275c:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0f2760:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0f2764:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0f2768:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f276c:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f0f2770:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f0f2774:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f0f2778:	0000f025 */ 	or	$s8,$zero,$zero
/*  f0f277c:	0000a825 */ 	or	$s5,$zero,$zero
/*  f0f2780:	94520666 */ 	lhu	$s2,0x666($v0)
/*  f0f2784:	00009825 */ 	or	$s3,$zero,$zero
/*  f0f2788:	1b200033 */ 	blez	$t9,.L0f0f2858
/*  f0f278c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0f2790:	00128880 */ 	sll	$s1,$s2,0x2
/*  f0f2794:	00711021 */ 	addu	$v0,$v1,$s1
/*  f0f2798:	24170014 */ 	addiu	$s7,$zero,0x14
/*  f0f279c:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f0f27a0:	904904fe */ 	lbu	$t1,0x4fe($v0)
.L0f0f27a4:
/*  f0f27a4:	8fab0068 */ 	lw	$t3,0x68($sp)
/*  f0f27a8:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0f27ac:	01370019 */ 	multu	$t1,$s7
/*  f0f27b0:	8d6c0008 */ 	lw	$t4,0x8($t3)
/*  f0f27b4:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f0f27b8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0f27bc:	00005012 */ 	mflo	$t2
/*  f0f27c0:	014c8021 */ 	addu	$s0,$t2,$t4
/*  f0f27c4:	0fc3c99d */ 	jal	func0f0f2674
/*  f0f27c8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f27cc:	10400009 */ 	beqz	$v0,.L0f0f27f4
/*  f0f27d0:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f0f27d4:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0f27d8:	0200f025 */ 	or	$s8,$s0,$zero
/*  f0f27dc:	8fae006c */ 	lw	$t6,0x6c($sp)
/*  f0f27e0:	028d082a */ 	slt	$at,$s4,$t5
/*  f0f27e4:	54200003 */ 	bnezl	$at,.L0f0f27f4
/*  f0f27e8:	add20000 */ 	sw	$s2,0x0($t6)
/*  f0f27ec:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f0f27f0:	add20000 */ 	sw	$s2,0x0($t6)
.L0f0f27f4:
/*  f0f27f4:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f0f27f8:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f0f27fc:	3c19800a */ 	lui	$t9,%hi(g_Menus)
/*  f0f2800:	2739e000 */ 	addiu	$t9,$t9,%lo(g_Menus)
/*  f0f2804:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f2808:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f280c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f2810:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f2814:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f2818:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f281c:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f2820:	03191821 */ 	addu	$v1,$t8,$t9
/*  f0f2824:	00711021 */ 	addu	$v0,$v1,$s1
/*  f0f2828:	844904fc */ 	lh	$t1,0x4fc($v0)
/*  f0f282c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f0f2830:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f0f2834:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0f2838:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0f283c:	16a00006 */ 	bnez	$s5,.L0f0f2858
/*  f0f2840:	0134a021 */ 	addu	$s4,$t1,$s4
/*  f0f2844:	00685821 */ 	addu	$t3,$v1,$t0
/*  f0f2848:	916a0668 */ 	lbu	$t2,0x668($t3)
/*  f0f284c:	026a082a */ 	slt	$at,$s3,$t2
/*  f0f2850:	5420ffd4 */ 	bnezl	$at,.L0f0f27a4
/*  f0f2854:	904904fe */ 	lbu	$t1,0x4fe($v0)
.L0f0f2858:
/*  f0f2858:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f285c:	03c01025 */ 	or	$v0,$s8,$zero
/*  f0f2860:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0f2864:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0f2868:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0f286c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0f2870:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0f2874:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0f2878:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0f287c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0f2880:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0f2884:	03e00008 */ 	jr	$ra
/*  f0f2888:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f0f288c
/*  f0f288c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0f2890:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0f2894:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f0f2898:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f0f289c:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0f28a0:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f28a4:	908e0005 */ 	lbu	$t6,0x5($a0)
/*  f0f28a8:	00809025 */ 	or	$s2,$a0,$zero
/*  f0f28ac:	90900004 */ 	lbu	$s0,0x4($a0)
/*  f0f28b0:	19c00012 */ 	blez	$t6,.L0f0f28fc
/*  f0f28b4:	00008825 */ 	or	$s1,$zero,$zero
/*  f0f28b8:	27b30034 */ 	addiu	$s3,$sp,0x34
/*  f0f28bc:	8e460000 */ 	lw	$a2,0x0($s2)
.L0f0f28c0:
/*  f0f28c0:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f0f28c4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f28c8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f28cc:	0fc3c9bf */ 	jal	func0f0f26fc
/*  f0f28d0:	02603825 */ 	or	$a3,$s3,$zero
/*  f0f28d4:	50400004 */ 	beqzl	$v0,.L0f0f28e8
/*  f0f28d8:	924f0005 */ 	lbu	$t7,0x5($s2)
/*  f0f28dc:	1000000c */ 	b	.L0f0f2910
/*  f0f28e0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0f28e4:	924f0005 */ 	lbu	$t7,0x5($s2)
.L0f0f28e8:
/*  f0f28e8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0f28ec:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0f28f0:	022f082a */ 	slt	$at,$s1,$t7
/*  f0f28f4:	5420fff2 */ 	bnezl	$at,.L0f0f28c0
/*  f0f28f8:	8e460000 */ 	lw	$a2,0x0($s2)
.L0f0f28fc:
/*  f0f28fc:	0fc3c560 */ 	jal	menuResolveParam1Text
/*  f0f2900:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f2904:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f0f2908:	8f020008 */ 	lw	$v0,0x8($t8)
/*  f0f290c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0f2910:
/*  f0f2910:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f0f2914:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f0f2918:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f0f291c:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f0f2920:	03e00008 */ 	jr	$ra
/*  f0f2924:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel func0f0f2928
/*  f0f2928:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0f292c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0f2930:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f0f2934:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f0f2938:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0f293c:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0f2940:	908e0004 */ 	lbu	$t6,0x4($a0)
/*  f0f2944:	90820005 */ 	lbu	$v0,0x5($a0)
/*  f0f2948:	00809025 */ 	or	$s2,$a0,$zero
/*  f0f294c:	00008825 */ 	or	$s1,$zero,$zero
/*  f0f2950:	01c28021 */ 	addu	$s0,$t6,$v0
/*  f0f2954:	18400012 */ 	blez	$v0,.L0f0f29a0
/*  f0f2958:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f0f295c:	27b3003c */ 	addiu	$s3,$sp,0x3c
/*  f0f2960:	8e460000 */ 	lw	$a2,0x0($s2)
.L0f0f2964:
/*  f0f2964:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f0f2968:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f296c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f2970:	0fc3c9bf */ 	jal	func0f0f26fc
/*  f0f2974:	02603825 */ 	or	$a3,$s3,$zero
/*  f0f2978:	50400004 */ 	beqzl	$v0,.L0f0f298c
/*  f0f297c:	924f0005 */ 	lbu	$t7,0x5($s2)
/*  f0f2980:	1000000c */ 	b	.L0f0f29b4
/*  f0f2984:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0f2988:	924f0005 */ 	lbu	$t7,0x5($s2)
.L0f0f298c:
/*  f0f298c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0f2990:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f0f2994:	022f082a */ 	slt	$at,$s1,$t7
/*  f0f2998:	5420fff2 */ 	bnezl	$at,.L0f0f2964
/*  f0f299c:	8e460000 */ 	lw	$a2,0x0($s2)
.L0f0f29a0:
/*  f0f29a0:	0fc3c560 */ 	jal	menuResolveParam1Text
/*  f0f29a4:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f29a8:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f0f29ac:	8f020008 */ 	lw	$v0,0x8($t8)
/*  f0f29b0:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0f29b4:
/*  f0f29b4:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f0f29b8:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f0f29bc:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f0f29c0:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f0f29c4:	03e00008 */ 	jr	$ra
/*  f0f29c8:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func0f0f29cc
/*  f0f29cc:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0f29d0:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0f29d4:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0f29d8:	00a09025 */ 	or	$s2,$a1,$zero
/*  f0f29dc:	00809825 */ 	or	$s3,$a0,$zero
/*  f0f29e0:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0f29e4:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0f29e8:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0f29ec:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0f29f0:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0f29f4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0f29f8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0f29fc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f2a00:	00008025 */ 	or	$s0,$zero,$zero
/*  f0f2a04:	8e650008 */ 	lw	$a1,0x8($s3)
/*  f0f2a08:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*  f0f2a0c:	0fc3c8d5 */ 	jal	func0f0f2354
/*  f0f2a10:	27a70058 */ 	addiu	$a3,$sp,0x58
/*  f0f2a14:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f0f2a18:	3c168007 */ 	lui	$s6,%hi(g_MpPlayerNum)
/*  f0f2a1c:	3c15800a */ 	lui	$s5,%hi(g_Menus)
/*  f0f2a20:	26b5e000 */ 	addiu	$s5,$s5,%lo(g_Menus)
/*  f0f2a24:	26d61448 */ 	addiu	$s6,$s6,%lo(g_MpPlayerNum)
/*  f0f2a28:	241e0014 */ 	addiu	$s8,$zero,0x14
/*  f0f2a2c:	2417000a */ 	addiu	$s7,$zero,0xa
/*  f0f2a30:	00a0a025 */ 	or	$s4,$a1,$zero
/*  f0f2a34:	8fb80058 */ 	lw	$t8,0x58($sp)
.L0f0f2a38:
/*  f0f2a38:	8ece0000 */ 	lw	$t6,0x0($s6)
/*  f0f2a3c:	00b22821 */ 	addu	$a1,$a1,$s2
/*  f0f2a40:	03170019 */ 	multu	$t8,$s7
/*  f0f2a44:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f2a48:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f2a4c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f2a50:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f2a54:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f2a58:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f2a5c:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f2a60:	02af3821 */ 	addu	$a3,$s5,$t7
/*  f0f2a64:	0000c812 */ 	mflo	$t9
/*  f0f2a68:	00f91021 */ 	addu	$v0,$a3,$t9
/*  f0f2a6c:	94430666 */ 	lhu	$v1,0x666($v0)
/*  f0f2a70:	90480668 */ 	lbu	$t0,0x668($v0)
/*  f0f2a74:	01032021 */ 	addu	$a0,$t0,$v1
/*  f0f2a78:	00a4082a */ 	slt	$at,$a1,$a0
/*  f0f2a7c:	54200003 */ 	bnezl	$at,.L0f0f2a8c
/*  f0f2a80:	00a3082a */ 	slt	$at,$a1,$v1
/*  f0f2a84:	00602825 */ 	or	$a1,$v1,$zero
/*  f0f2a88:	00a3082a */ 	slt	$at,$a1,$v1
.L0f0f2a8c:
/*  f0f2a8c:	10200003 */ 	beqz	$at,.L0f0f2a9c
/*  f0f2a90:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f0f2a94:	2485ffff */ 	addiu	$a1,$a0,-1
/*  f0f2a98:	afa5005c */ 	sw	$a1,0x5c($sp)
.L0f0f2a9c:
/*  f0f2a9c:	8fa9005c */ 	lw	$t1,0x5c($sp)
/*  f0f2aa0:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f0f2aa4:	02602825 */ 	or	$a1,$s3,$zero
/*  f0f2aa8:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0f2aac:	00ea5821 */ 	addu	$t3,$a3,$t2
/*  f0f2ab0:	916c04fe */ 	lbu	$t4,0x4fe($t3)
/*  f0f2ab4:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*  f0f2ab8:	02403025 */ 	or	$a2,$s2,$zero
/*  f0f2abc:	019e0019 */ 	multu	$t4,$s8
/*  f0f2ac0:	00006812 */ 	mflo	$t5
/*  f0f2ac4:	01af8821 */ 	addu	$s1,$t5,$t7
/*  f0f2ac8:	0fc3c99d */ 	jal	func0f0f2674
/*  f0f2acc:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f2ad0:	10400002 */ 	beqz	$v0,.L0f0f2adc
/*  f0f2ad4:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f0f2ad8:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0f2adc:
/*  f0f2adc:	14b40002 */ 	bne	$a1,$s4,.L0f0f2ae8
/*  f0f2ae0:	00000000 */ 	nop
/*  f0f2ae4:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0f2ae8:
/*  f0f2ae8:	5200ffd3 */ 	beqzl	$s0,.L0f0f2a38
/*  f0f2aec:	8fb80058 */ 	lw	$t8,0x58($sp)
/*  f0f2af0:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f0f2af4:	afb1004c */ 	sw	$s1,0x4c($sp)
/*  f0f2af8:	ae710008 */ 	sw	$s1,0x8($s3)
/*  f0f2afc:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f2b00:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0f2b04:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0f2b08:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0f2b0c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0f2b10:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0f2b14:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0f2b18:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0f2b1c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0f2b20:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0f2b24:	03e00008 */ 	jr	$ra
/*  f0f2b28:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f0f2b2c
/*  f0f2b2c:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0f2b30:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f0f2b34:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f0f2b38:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0f2b3c:	00808025 */ 	or	$s0,$a0,$zero
/*  f0f2b40:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f0f2b44:	27b6005c */ 	addiu	$s6,$sp,0x5c
/*  f0f2b48:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0f2b4c:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f0f2b50:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f0f2b54:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f0f2b58:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f0f2b5c:	00008825 */ 	or	$s1,$zero,$zero
/*  f0f2b60:	00009025 */ 	or	$s2,$zero,$zero
/*  f0f2b64:	8e050008 */ 	lw	$a1,0x8($s0)
/*  f0f2b68:	02c03025 */ 	or	$a2,$s6,$zero
/*  f0f2b6c:	0fc3c8d5 */ 	jal	func0f0f2354
/*  f0f2b70:	27a70058 */ 	addiu	$a3,$sp,0x58
/*  f0f2b74:	00409825 */ 	or	$s3,$v0,$zero
/*  f0f2b78:	8fb40058 */ 	lw	$s4,0x58($sp)
/*  f0f2b7c:	8fae0058 */ 	lw	$t6,0x58($sp)
.L0f0f2b80:
/*  f0f2b80:	02602025 */ 	or	$a0,$s3,$zero
/*  f0f2b84:	02c03825 */ 	or	$a3,$s6,$zero
/*  f0f2b88:	01d57821 */ 	addu	$t7,$t6,$s5
/*  f0f2b8c:	afaf0058 */ 	sw	$t7,0x58($sp)
/*  f0f2b90:	92180005 */ 	lbu	$t8,0x5($s0)
/*  f0f2b94:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f0f2b98:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f0f2b9c:	01f9082a */ 	slt	$at,$t7,$t9
/*  f0f2ba0:	54200005 */ 	bnezl	$at,.L0f0f2bb8
/*  f0f2ba4:	8fa80058 */ 	lw	$t0,0x58($sp)
/*  f0f2ba8:	afa20058 */ 	sw	$v0,0x58($sp)
/*  f0f2bac:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0f2bb0:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f0f2bb4:	8fa80058 */ 	lw	$t0,0x58($sp)
.L0f0f2bb8:
/*  f0f2bb8:	0102082a */ 	slt	$at,$t0,$v0
/*  f0f2bbc:	50200007 */ 	beqzl	$at,.L0f0f2bdc
/*  f0f2bc0:	8e060000 */ 	lw	$a2,0x0($s0)
/*  f0f2bc4:	92090005 */ 	lbu	$t1,0x5($s0)
/*  f0f2bc8:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f0f2bcc:	00495021 */ 	addu	$t2,$v0,$t1
/*  f0f2bd0:	254bffff */ 	addiu	$t3,$t2,-1
/*  f0f2bd4:	afab0058 */ 	sw	$t3,0x58($sp)
/*  f0f2bd8:	8e060000 */ 	lw	$a2,0x0($s0)
.L0f0f2bdc:
/*  f0f2bdc:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0f2be0:	0fc3c9bf */ 	jal	func0f0f26fc
/*  f0f2be4:	8fa50058 */ 	lw	$a1,0x58($sp)
/*  f0f2be8:	10400002 */ 	beqz	$v0,.L0f0f2bf4
/*  f0f2bec:	00401825 */ 	or	$v1,$v0,$zero
/*  f0f2bf0:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f0f2bf4:
/*  f0f2bf4:	8fac0058 */ 	lw	$t4,0x58($sp)
/*  f0f2bf8:	15940002 */ 	bne	$t4,$s4,.L0f0f2c04
/*  f0f2bfc:	00000000 */ 	nop
/*  f0f2c00:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f0f2c04:
/*  f0f2c04:	5220ffde */ 	beqzl	$s1,.L0f0f2b80
/*  f0f2c08:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f0f2c0c:	10600002 */ 	beqz	$v1,.L0f0f2c18
/*  f0f2c10:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0f2c14:	ae030008 */ 	sw	$v1,0x8($s0)
.L0f0f2c18:
/*  f0f2c18:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f2c1c:	02401025 */ 	or	$v0,$s2,$zero
/*  f0f2c20:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f0f2c24:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0f2c28:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f0f2c2c:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f0f2c30:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f0f2c34:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f0f2c38:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f0f2c3c:	03e00008 */ 	jr	$ra
/*  f0f2c40:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f0f2c44
/*  f0f2c44:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0f2c48:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f2c4c:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0f2c50:	00a03825 */ 	or	$a3,$a1,$zero
/*  f0f2c54:	14a00005 */ 	bnez	$a1,.L0f0f2c6c
/*  f0f2c58:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f2c5c:	14c00003 */ 	bnez	$a2,.L0f0f2c6c
/*  f0f2c60:	00000000 */ 	nop
/*  f0f2c64:	1000001f */ 	b	.L0f0f2ce4
/*  f0f2c68:	00001025 */ 	or	$v0,$zero,$zero
.L0f0f2c6c:
/*  f0f2c6c:	10c00007 */ 	beqz	$a2,.L0f0f2c8c
/*  f0f2c70:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0f2c74:	00c02825 */ 	or	$a1,$a2,$zero
/*  f0f2c78:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f0f2c7c:	0fc3ca73 */ 	jal	func0f0f29cc
/*  f0f2c80:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f0f2c84:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f0f2c88:	8fa7003c */ 	lw	$a3,0x3c($sp)
.L0f0f2c8c:
/*  f0f2c8c:	10e00004 */ 	beqz	$a3,.L0f0f2ca0
/*  f0f2c90:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0f2c94:	0fc3cacb */ 	jal	func0f0f2b2c
/*  f0f2c98:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0f2c9c:	00401825 */ 	or	$v1,$v0,$zero
.L0f0f2ca0:
/*  f0f2ca0:	8fae0038 */ 	lw	$t6,0x38($sp)
/*  f0f2ca4:	8dc50008 */ 	lw	$a1,0x8($t6)
/*  f0f2ca8:	50a0000e */ 	beqzl	$a1,.L0f0f2ce4
/*  f0f2cac:	00601025 */ 	or	$v0,$v1,$zero
/*  f0f2cb0:	8ca20010 */ 	lw	$v0,0x10($a1)
/*  f0f2cb4:	5040000b */ 	beqzl	$v0,.L0f0f2ce4
/*  f0f2cb8:	00601025 */ 	or	$v0,$v1,$zero
/*  f0f2cbc:	8caf0004 */ 	lw	$t7,0x4($a1)
/*  f0f2cc0:	2404000d */ 	addiu	$a0,$zero,0xd
/*  f0f2cc4:	27a60024 */ 	addiu	$a2,$sp,0x24
/*  f0f2cc8:	31f80004 */ 	andi	$t8,$t7,0x4
/*  f0f2ccc:	57000005 */ 	bnezl	$t8,.L0f0f2ce4
/*  f0f2cd0:	00601025 */ 	or	$v0,$v1,$zero
/*  f0f2cd4:	0040f809 */ 	jalr	$v0
/*  f0f2cd8:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f0f2cdc:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f0f2ce0:	00601025 */ 	or	$v0,$v1,$zero
.L0f0f2ce4:
/*  f0f2ce4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f2ce8:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0f2cec:	03e00008 */ 	jr	$ra
/*  f0f2cf0:	00000000 */ 	nop
);

void menuOpenDialog(struct menudialog *dialog, struct menuframe *frame, struct menu *menu)
{
	union handlerdata data3;
	struct menuitem *item;
	union handlerdata data1;
	union handlerdata data2;

	frame->dialog = dialog;

	switch (g_MenuData.root) {
	case MENUROOT_MPSETUP:
	case MENUROOT_4MBMAINMENU:
		frame->unk6e = 1;
		break;
	case MENUROOT_MAINMENU:
	case MENUROOT_TRAINING:
	default:
		frame->unk6e = 0;
		break;
	}

	func0f0f1d6c(dialog, frame, menu);
	func0f0fa574(frame);

	frame->dialogtype = dialog->type;
	frame->unk40 = -1;
	frame->unk48 = 0;
	frame->unk4c = random() * (1.0f / U32_MAX) * M_TAU;

	g_Menus[g_MpPlayerNum].curframe->unk60 = 0;
	g_Menus[g_MpPlayerNum].curframe->unk50 = 0;

	frame->unk54 = 0;
	frame->unk58 = 0;
	frame->unk5c = 0;

	frame->focuseditem = func0f0f288c(frame);

	// Check if any items should be focused automatically
	item = frame->dialog->items;

	while (item->type != MENUITEMTYPE_END) {
		if (item->handler
				&& (item->param1 & 0x04) == 0
				&& item->handler(MENUOP_CHECKPREFOCUSED, item, &data1)) {
			frame->focuseditem = item;
		}

		item++;
	}

	// Run focus handler
	if (frame->focuseditem
			&& frame->focuseditem->handler
			&& (frame->focuseditem->param1 & 0x04) == 0) {
		frame->focuseditem->handler(MENUOP_FOCUS, frame->focuseditem, &data2);
	}

	frame->unk0c = 0;
	frame->unk64 = 0;
	frame->unk68 = 0;

	if (dialog->handler) {
		dialog->handler(MENUOP_OPEN, dialog, &data3);
	}

	func0f0f2134(dialog, frame, menu);
	func0f0f7e98(frame);

	frame->unk14 = frame->unk2c;
	frame->unk18 = frame->unk30;
	frame->unk1c = frame->unk34;
	frame->unk20 = frame->unk38;
}

GLOBAL_ASM(
glabel menuPushDialog
/*  f0f2f4c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0f2f50:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0f2f54:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0f2f58:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0f2f5c:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0f2f60:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0f2f64:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0f2f68:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0f2f6c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0f2f70:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0f2f74:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f2f78:	1080009d */ 	beqz	$a0,.L0f0f31f0
/*  f0f2f7c:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f0f2f80:	3c158007 */ 	lui	$s5,%hi(g_MpPlayerNum)
/*  f0f2f84:	26b51448 */ 	addiu	$s5,$s5,%lo(g_MpPlayerNum)
/*  f0f2f88:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f0f2f8c:	24160e70 */ 	addiu	$s6,$zero,0xe70
/*  f0f2f90:	3c14800a */ 	lui	$s4,%hi(g_Menus)
/*  f0f2f94:	01f60019 */ 	multu	$t7,$s6
/*  f0f2f98:	2694e000 */ 	addiu	$s4,$s4,%lo(g_Menus)
/*  f0f2f9c:	0000c012 */ 	mflo	$t8
/*  f0f2fa0:	02982021 */ 	addu	$a0,$s4,$t8
/*  f0f2fa4:	0fc3cde9 */ 	jal	func0f0f37a4
/*  f0f2fa8:	24840840 */ 	addiu	$a0,$a0,0x840
/*  f0f2fac:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f0f2fb0:	03360019 */ 	multu	$t9,$s6
/*  f0f2fb4:	00004012 */ 	mflo	$t0
/*  f0f2fb8:	02881821 */ 	addu	$v1,$s4,$t0
/*  f0f2fbc:	846704f4 */ 	lh	$a3,0x4f4($v1)
/*  f0f2fc0:	28e10006 */ 	slti	$at,$a3,0x6
/*  f0f2fc4:	5020008b */ 	beqzl	$at,.L0f0f31f4
/*  f0f2fc8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f2fcc:	84690460 */ 	lh	$t1,0x460($v1)
/*  f0f2fd0:	00075080 */ 	sll	$t2,$a3,0x2
/*  f0f2fd4:	01475023 */ 	subu	$t2,$t2,$a3
/*  f0f2fd8:	2921000a */ 	slti	$at,$t1,0xa
/*  f0f2fdc:	10200084 */ 	beqz	$at,.L0f0f31f0
/*  f0f2fe0:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0f2fe4:	24eb0001 */ 	addiu	$t3,$a3,0x1
/*  f0f2fe8:	006a8821 */ 	addu	$s1,$v1,$t2
/*  f0f2fec:	a46b04f4 */ 	sh	$t3,0x4f4($v1)
/*  f0f2ff0:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f2ff4:	a22c0478 */ 	sb	$t4,0x478($s1)
/*  f0f2ff8:	a2200479 */ 	sb	$zero,0x479($s1)
/*  f0f2ffc:	8ead0000 */ 	lw	$t5,0x0($s5)
/*  f0f3000:	241e0070 */ 	addiu	$s8,$zero,0x70
/*  f0f3004:	26310464 */ 	addiu	$s1,$s1,0x464
/*  f0f3008:	01b60019 */ 	multu	$t5,$s6
/*  f0f300c:	00007012 */ 	mflo	$t6
/*  f0f3010:	028e1821 */ 	addu	$v1,$s4,$t6
/*  f0f3014:	84620460 */ 	lh	$v0,0x460($v1)
/*  f0f3018:	005e0019 */ 	multu	$v0,$s8
/*  f0f301c:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f0f3020:	a4780460 */ 	sh	$t8,0x460($v1)
/*  f0f3024:	00007812 */ 	mflo	$t7
/*  f0f3028:	006f8021 */ 	addu	$s0,$v1,$t7
/*  f0f302c:	ae300000 */ 	sw	$s0,0x0($s1)
/*  f0f3030:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f0f3034:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f3038:	03360019 */ 	multu	$t9,$s6
/*  f0f303c:	00004012 */ 	mflo	$t0
/*  f0f3040:	02884821 */ 	addu	$t1,$s4,$t0
/*  f0f3044:	ad3004f8 */ 	sw	$s0,0x4f8($t1)
/*  f0f3048:	a200006d */ 	sb	$zero,0x6d($s0)
/*  f0f304c:	8eaa0000 */ 	lw	$t2,0x0($s5)
/*  f0f3050:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f3054:	01560019 */ 	multu	$t2,$s6
/*  f0f3058:	00005812 */ 	mflo	$t3
/*  f0f305c:	028b3021 */ 	addu	$a2,$s4,$t3
/*  f0f3060:	0fc3cb3d */ 	jal	menuOpenDialog
/*  f0f3064:	00000000 */ 	nop
/*  f0f3068:	0c002f02 */ 	jal	viGetX
/*  f0f306c:	00000000 */ 	nop
/*  f0f3070:	8e0c001c */ 	lw	$t4,0x1c($s0)
/*  f0f3074:	004c6823 */ 	subu	$t5,$v0,$t4
/*  f0f3078:	05a10003 */ 	bgez	$t5,.L0f0f3088
/*  f0f307c:	000d7043 */ 	sra	$t6,$t5,0x1
/*  f0f3080:	25a10001 */ 	addiu	$at,$t5,0x1
/*  f0f3084:	00017043 */ 	sra	$t6,$at,0x1
.L0f0f3088:
/*  f0f3088:	0c002f06 */ 	jal	viGetY
/*  f0f308c:	ae0e002c */ 	sw	$t6,0x2c($s0)
/*  f0f3090:	8e0f0020 */ 	lw	$t7,0x20($s0)
/*  f0f3094:	004fc023 */ 	subu	$t8,$v0,$t7
/*  f0f3098:	07010003 */ 	bgez	$t8,.L0f0f30a8
/*  f0f309c:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0f30a0:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0f30a4:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f30a8:
/*  f0f30a8:	ae190030 */ 	sw	$t9,0x30($s0)
/*  f0f30ac:	8ea80000 */ 	lw	$t0,0x0($s5)
/*  f0f30b0:	8fad0040 */ 	lw	$t5,0x40($sp)
/*  f0f30b4:	01160019 */ 	multu	$t0,$s6
/*  f0f30b8:	00004812 */ 	mflo	$t1
/*  f0f30bc:	02891821 */ 	addu	$v1,$s4,$t1
/*  f0f30c0:	906b0e40 */ 	lbu	$t3,0xe40($v1)
/*  f0f30c4:	356c0080 */ 	ori	$t4,$t3,0x80
/*  f0f30c8:	a06c0e40 */ 	sb	$t4,0xe40($v1)
/*  f0f30cc:	8db20014 */ 	lw	$s2,0x14($t5)
/*  f0f30d0:	12400037 */ 	beqz	$s2,.L0f0f31b0
/*  f0f30d4:	00000000 */ 	nop
/*  f0f30d8:	822e0014 */ 	lb	$t6,0x14($s1)
/*  f0f30dc:	2417ffff */ 	addiu	$s7,$zero,-1
/*  f0f30e0:	2413fec0 */ 	addiu	$s3,$zero,-320
/*  f0f30e4:	29c10005 */ 	slti	$at,$t6,0x5
/*  f0f30e8:	10200031 */ 	beqz	$at,.L0f0f31b0
/*  f0f30ec:	00000000 */ 	nop
/*  f0f30f0:	8eaf0000 */ 	lw	$t7,0x0($s5)
.L0f0f30f4:
/*  f0f30f4:	01f60019 */ 	multu	$t7,$s6
/*  f0f30f8:	0000c012 */ 	mflo	$t8
/*  f0f30fc:	02981821 */ 	addu	$v1,$s4,$t8
/*  f0f3100:	84620460 */ 	lh	$v0,0x460($v1)
/*  f0f3104:	2841000a */ 	slti	$at,$v0,0xa
/*  f0f3108:	10200023 */ 	beqz	$at,.L0f0f3198
/*  f0f310c:	00000000 */ 	nop
/*  f0f3110:	005e0019 */ 	multu	$v0,$s8
/*  f0f3114:	24480001 */ 	addiu	$t0,$v0,0x1
/*  f0f3118:	a4680460 */ 	sh	$t0,0x460($v1)
/*  f0f311c:	82290014 */ 	lb	$t1,0x14($s1)
/*  f0f3120:	02402025 */ 	or	$a0,$s2,$zero
/*  f0f3124:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0f3128:	022a5821 */ 	addu	$t3,$s1,$t2
/*  f0f312c:	0000c812 */ 	mflo	$t9
/*  f0f3130:	00798021 */ 	addu	$s0,$v1,$t9
/*  f0f3134:	ad700000 */ 	sw	$s0,0x0($t3)
/*  f0f3138:	822c0014 */ 	lb	$t4,0x14($s1)
/*  f0f313c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f3140:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f0f3144:	a22d0014 */ 	sb	$t5,0x14($s1)
/*  f0f3148:	a217006d */ 	sb	$s7,0x6d($s0)
/*  f0f314c:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f0f3150:	01d60019 */ 	multu	$t6,$s6
/*  f0f3154:	00007812 */ 	mflo	$t7
/*  f0f3158:	028f3021 */ 	addu	$a2,$s4,$t7
/*  f0f315c:	0fc3cb3d */ 	jal	menuOpenDialog
/*  f0f3160:	00000000 */ 	nop
/*  f0f3164:	ae130014 */ 	sw	$s3,0x14($s0)
/*  f0f3168:	0c002f06 */ 	jal	viGetY
/*  f0f316c:	ae13002c */ 	sw	$s3,0x2c($s0)
/*  f0f3170:	8e180020 */ 	lw	$t8,0x20($s0)
/*  f0f3174:	a200003c */ 	sb	$zero,0x3c($s0)
/*  f0f3178:	00581823 */ 	subu	$v1,$v0,$t8
/*  f0f317c:	04610003 */ 	bgez	$v1,.L0f0f318c
/*  f0f3180:	0003c843 */ 	sra	$t9,$v1,0x1
/*  f0f3184:	24610001 */ 	addiu	$at,$v1,0x1
/*  f0f3188:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f318c:
/*  f0f318c:	ae190018 */ 	sw	$t9,0x18($s0)
/*  f0f3190:	ae190030 */ 	sw	$t9,0x30($s0)
/*  f0f3194:	8e520014 */ 	lw	$s2,0x14($s2)
.L0f0f3198:
/*  f0f3198:	12400005 */ 	beqz	$s2,.L0f0f31b0
/*  f0f319c:	00000000 */ 	nop
/*  f0f31a0:	82280014 */ 	lb	$t0,0x14($s1)
/*  f0f31a4:	29010005 */ 	slti	$at,$t0,0x5
/*  f0f31a8:	5420ffd2 */ 	bnezl	$at,.L0f0f30f4
/*  f0f31ac:	8eaf0000 */ 	lw	$t7,0x0($s5)
.L0f0f31b0:
/*  f0f31b0:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0f31b4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0f31b8:	8fa90040 */ 	lw	$t1,0x40($sp)
/*  f0f31bc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f31c0:	91220000 */ 	lbu	$v0,0x0($t1)
/*  f0f31c4:	54410006 */ 	bnel	$v0,$at,.L0f0f31e0
/*  f0f31c8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f31cc:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0f31d0:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0f31d4:	8faa0040 */ 	lw	$t2,0x40($sp)
/*  f0f31d8:	91420000 */ 	lbu	$v0,0x0($t2)
/*  f0f31dc:	24010003 */ 	addiu	$at,$zero,0x3
.L0f0f31e0:
/*  f0f31e0:	54410004 */ 	bnel	$v0,$at,.L0f0f31f4
/*  f0f31e4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0f31e8:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0f31ec:	2404000e */ 	addiu	$a0,$zero,0xe
.L0f0f31f0:
/*  f0f31f0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f0f31f4:
/*  f0f31f4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0f31f8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0f31fc:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0f3200:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0f3204:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0f3208:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0f320c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0f3210:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0f3214:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0f3218:	03e00008 */ 	jr	$ra
/*  f0f321c:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

// regalloc: s1 (layer) and s2 (sibling) are swapped
//void menuPushDialog(struct menudialog *dialog)
//{
//	if (dialog) {
//		func0f0f37a4(&g_Menus[g_MpPlayerNum].unk840);
//
//		if (g_Menus[g_MpPlayerNum].depth < 6 && g_Menus[g_MpPlayerNum].numframes < 10) {
//			struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[g_Menus[g_MpPlayerNum].depth];
//			struct menudialog *sibling;
//			struct menuframe *frame;
//
//			g_Menus[g_MpPlayerNum].depth++;
//
//			layer->numsiblings = 1;
//			layer->cursibling = 0;
//
//			frame = &g_Menus[g_MpPlayerNum].frames[g_Menus[g_MpPlayerNum].numframes];
//			g_Menus[g_MpPlayerNum].numframes++;
//			layer->siblings[0] = frame;
//			g_Menus[g_MpPlayerNum].curframe = frame;
//			frame->unk6d = 0;
//
//			menuOpenDialog(dialog, frame, &g_Menus[g_MpPlayerNum]);
//
//			frame->unk2c = (viGetX() - frame->unk1c) / 2;
//			frame->unk30 = (viGetY() - frame->unk20) / 2;
//
//			g_Menus[g_MpPlayerNum].unke40 |= 0x80;
//			sibling = dialog->nextsibling;
//
//			while (sibling && layer->numsiblings < 5) {
//				// If this limit were to be reached, the game would soft lock
//				// because sibling is incremented inside the if-statement block.
//				if (g_Menus[g_MpPlayerNum].numframes < 10) {
//					frame = &g_Menus[g_MpPlayerNum].frames[g_Menus[g_MpPlayerNum].numframes];
//					g_Menus[g_MpPlayerNum].numframes++;
//
//					layer->siblings[layer->numsiblings] = frame;
//					layer->numsiblings++;
//
//					frame->unk6d = -1;
//
//					menuOpenDialog(sibling, frame, &g_Menus[g_MpPlayerNum]);
//
//					frame->unk14 = -320;
//					frame->unk2c = -320;
//					frame->unk18 = (viGetY() - frame->unk20) / 2;
//					frame->unk30 = frame->unk18;
//					frame->unk3c = 0;
//
//					sibling = sibling->nextsibling;
//				}
//			}
//
//			func0f0f09f0(1);
//
//			if (dialog->type == MENUDIALOGTYPE_DANGER) {
//				func0f0f09f0(4);
//			}
//
//			if (dialog->type == MENUDIALOGTYPE_SUCCESS) {
//				func0f0f09f0(14);
//			}
//		}
//	}
//}

GLOBAL_ASM(
glabel func0f0f3220
/*  f0f3220:	3c03800a */ 	lui	$v1,%hi(g_MenuData+0x669)
/*  f0f3224:	00641821 */ 	addu	$v1,$v1,$a0
/*  f0f3228:	90632029 */ 	lbu	$v1,%lo(g_MenuData+0x669)($v1)
/*  f0f322c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0f3230:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f3234:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f3238:	1461003d */ 	bne	$v1,$at,.L0f0f3330
/*  f0f323c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f3240:	3c078007 */ 	lui	$a3,%hi(g_MpPlayerNum)
/*  f0f3244:	24e71448 */ 	addiu	$a3,$a3,%lo(g_MpPlayerNum)
/*  f0f3248:	3c03800a */ 	lui	$v1,%hi(g_Menus+0x2b50)
/*  f0f324c:	8ce90000 */ 	lw	$t1,0x0($a3)
/*  f0f3250:	24630b50 */ 	addiu	$v1,$v1,%lo(g_Menus+0x2b50)
/*  f0f3254:	24020003 */ 	addiu	$v0,$zero,0x3
.L0f0f3258:
/*  f0f3258:	8c6e04f8 */ 	lw	$t6,0x4f8($v1)
/*  f0f325c:	51c00003 */ 	beqzl	$t6,.L0f0f326c
/*  f0f3260:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0f3264:	ace20000 */ 	sw	$v0,0x0($a3)
/*  f0f3268:	2442ffff */ 	addiu	$v0,$v0,-1
.L0f0f326c:
/*  f0f326c:	0441fffa */ 	bgez	$v0,.L0f0f3258
/*  f0f3270:	2463f190 */ 	addiu	$v1,$v1,-3696
/*  f0f3274:	8ce20000 */ 	lw	$v0,0x0($a3)
/*  f0f3278:	3c18800a */ 	lui	$t8,%hi(g_Menus)
/*  f0f327c:	2718e000 */ 	addiu	$t8,$t8,%lo(g_Menus)
/*  f0f3280:	000278c0 */ 	sll	$t7,$v0,0x3
/*  f0f3284:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f0f3288:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f328c:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f0f3290:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f3294:	01e27823 */ 	subu	$t7,$t7,$v0
/*  f0f3298:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f329c:	01f81821 */ 	addu	$v1,$t7,$t8
/*  f0f32a0:	847904f4 */ 	lh	$t9,0x4f4($v1)
/*  f0f32a4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f32a8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f32ac:	2b210002 */ 	slti	$at,$t9,0x2
/*  f0f32b0:	54200003 */ 	bnezl	$at,.L0f0f32c0
/*  f0f32b4:	8c6404f8 */ 	lw	$a0,0x4f8($v1)
/*  f0f32b8:	00004025 */ 	or	$t0,$zero,$zero
/*  f0f32bc:	8c6404f8 */ 	lw	$a0,0x4f8($v1)
.L0f0f32c0:
/*  f0f32c0:	1080000f */ 	beqz	$a0,.L0f0f3300
/*  f0f32c4:	00000000 */ 	nop
/*  f0f32c8:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0f32cc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f32d0:	3c0b8008 */ 	lui	$t3,%hi(g_MpEndscreenChallengeCheatedMenuDialog)
/*  f0f32d4:	904a0000 */ 	lbu	$t2,0x0($v0)
/*  f0f32d8:	256b4a40 */ 	addiu	$t3,$t3,%lo(g_MpEndscreenChallengeCheatedMenuDialog)
/*  f0f32dc:	15410008 */ 	bne	$t2,$at,.L0f0f3300
/*  f0f32e0:	00000000 */ 	nop
/*  f0f32e4:	11620005 */ 	beq	$t3,$v0,.L0f0f32fc
/*  f0f32e8:	00004025 */ 	or	$t0,$zero,$zero
/*  f0f32ec:	3c0c8008 */ 	lui	$t4,%hi(g_MpEndscreenChallengeFailedMenuDialog)
/*  f0f32f0:	258c4a58 */ 	addiu	$t4,$t4,%lo(g_MpEndscreenChallengeFailedMenuDialog)
/*  f0f32f4:	15820002 */ 	bne	$t4,$v0,.L0f0f3300
/*  f0f32f8:	00000000 */ 	nop
.L0f0f32fc:
/*  f0f32fc:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f0f3300:
/*  f0f3300:	11000009 */ 	beqz	$t0,.L0f0f3328
/*  f0f3304:	3c04800a */ 	lui	$a0,%hi(var800a22c0)
/*  f0f3308:	248422c0 */ 	addiu	$a0,$a0,%lo(var800a22c0)
/*  f0f330c:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f0f3310:	0fc42539 */ 	jal	func0f1094e4
/*  f0f3314:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f0f3318:	3c078007 */ 	lui	$a3,%hi(g_MpPlayerNum)
/*  f0f331c:	24e71448 */ 	addiu	$a3,$a3,%lo(g_MpPlayerNum)
/*  f0f3320:	8fa80024 */ 	lw	$t0,0x24($sp)
/*  f0f3324:	8fa9001c */ 	lw	$t1,0x1c($sp)
.L0f0f3328:
/*  f0f3328:	10000019 */ 	b	.L0f0f3390
/*  f0f332c:	ace90000 */ 	sw	$t1,0x0($a3)
.L0f0f3330:
/*  f0f3330:	28610004 */ 	slti	$at,$v1,0x4
/*  f0f3334:	10200016 */ 	beqz	$at,.L0f0f3390
/*  f0f3338:	3c078007 */ 	lui	$a3,%hi(g_MpPlayerNum)
/*  f0f333c:	00037080 */ 	sll	$t6,$v1,0x2
/*  f0f3340:	24e71448 */ 	addiu	$a3,$a3,%lo(g_MpPlayerNum)
/*  f0f3344:	01c37021 */ 	addu	$t6,$t6,$v1
/*  f0f3348:	8ced0000 */ 	lw	$t5,0x0($a3)
/*  f0f334c:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f0f3350:	3c18800b */ 	lui	$t8,%hi(g_MpPlayers)
/*  f0f3354:	2718c7b8 */ 	addiu	$t8,$t8,%lo(g_MpPlayers)
/*  f0f3358:	25cf004c */ 	addiu	$t7,$t6,0x4c
/*  f0f335c:	ace30000 */ 	sw	$v1,0x0($a3)
/*  f0f3360:	01f82021 */ 	addu	$a0,$t7,$t8
/*  f0f3364:	00601025 */ 	or	$v0,$v1,$zero
/*  f0f3368:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f0f336c:	00603025 */ 	or	$a2,$v1,$zero
/*  f0f3370:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f0f3374:	0fc42539 */ 	jal	func0f1094e4
/*  f0f3378:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0f337c:	8fb90018 */ 	lw	$t9,0x18($sp)
/*  f0f3380:	3c078007 */ 	lui	$a3,%hi(g_MpPlayerNum)
/*  f0f3384:	24e71448 */ 	addiu	$a3,$a3,%lo(g_MpPlayerNum)
/*  f0f3388:	8fa80024 */ 	lw	$t0,0x24($sp)
/*  f0f338c:	acf90000 */ 	sw	$t9,0x0($a3)
.L0f0f3390:
/*  f0f3390:	11000005 */ 	beqz	$t0,.L0f0f33a8
/*  f0f3394:	3c0a800a */ 	lui	$t2,%hi(g_MenuData+0x66e)
/*  f0f3398:	814a202e */ 	lb	$t2,%lo(g_MenuData+0x66e)($t2)
/*  f0f339c:	3c01800a */ 	lui	$at,%hi(g_MenuData+0x66e)
/*  f0f33a0:	254bffff */ 	addiu	$t3,$t2,-1
/*  f0f33a4:	a02b202e */ 	sb	$t3,%lo(g_MenuData+0x66e)($at)
.L0f0f33a8:
/*  f0f33a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f33ac:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0f33b0:	01001025 */ 	or	$v0,$t0,$zero
/*  f0f33b4:	03e00008 */ 	jr	$ra
/*  f0f33b8:	00000000 */ 	nop
);

void menuCloseDialog(void)
{
	if (g_Menus[g_MpPlayerNum].depth > 0) {
		union handlerdata data;
		struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[g_Menus[g_MpPlayerNum].depth - 1];
		u32 value_prevent = 1; // constant value, but required for match
		s32 i;

		for (i = 0; i < layer->numsiblings; i++) {
			data.dialog1.preventclose = false;

			if (layer->siblings[i]->dialog->handler) {
				layer->siblings[i]->dialog->handler(MENUOP_CLOSE, layer->siblings[i]->dialog, &data);
			}

			if (value_prevent == data.dialog1.preventclose) {
				return;
			}
		}

		for (i = 0; i < layer->numsiblings; i++) {
			g_Menus[g_MpPlayerNum].numframes--;
		}

		g_Menus[g_MpPlayerNum].unk65c = g_Menus[g_MpPlayerNum].unk666[layer->siblings[0]->unk04][0];
		g_Menus[g_MpPlayerNum].unk6d8 = layer->siblings[0]->unk04;
		g_Menus[g_MpPlayerNum].unk81c = layer->siblings[0]->unk06;
		g_Menus[g_MpPlayerNum].depth--;

		func0f0f09f0(0xb);
	}

	if (g_MenuData.unk66e > 0 && g_Menus[g_MpPlayerNum].depth == 0) {
		s32 value = g_MenuData.unk66e;

		while (value >= 0) {
			func0f0f3220(value);
			value--;
		}
	}

	if (g_Menus[g_MpPlayerNum].depth == 0) {
		g_Menus[g_MpPlayerNum].curframe = NULL;
	} else {
		struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[g_Menus[g_MpPlayerNum].depth - 1];
		g_Menus[g_MpPlayerNum].curframe = layer->siblings[layer->cursibling];
	}
}

void menuUpdateCurFrame(void)
{
	s32 depth = g_Menus[g_MpPlayerNum].depth;

	if (depth == 0) {
		// No more parent menus - return control to the player
		g_Vars.currentplayer->joybutinhibit = 0xffffffff;
		func0f0f8040();
		g_Menus[g_MpPlayerNum].curframe = NULL;
	} else {
		// Set up parent menu
		struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[depth - 1];
		g_Menus[g_MpPlayerNum].curframe = layer->siblings[layer->cursibling];
	}
}

void menuPopDialog(void)
{
	menuCloseDialog();
	menuUpdateCurFrame();
}

void func0f0f3704(struct menudialog *dialog)
{
	menuCloseDialog();
	menuPushDialog(dialog);
}

GLOBAL_ASM(
glabel func0f0f372c
/*  f0f372c:	44856000 */ 	mtc1	$a1,$f12
/*  f0f3730:	afa7000c */ 	sw	$a3,0xc($sp)
/*  f0f3734:	93a50023 */ 	lbu	$a1,0x23($sp)
/*  f0f3738:	908f05b1 */ 	lbu	$t7,0x5b1($a0)
/*  f0f373c:	44867000 */ 	mtc1	$a2,$f14
/*  f0f3740:	30b90002 */ 	andi	$t9,$a1,0x2
/*  f0f3744:	35f80008 */ 	ori	$t8,$t7,0x8
/*  f0f3748:	a09805b1 */ 	sb	$t8,0x5b1($a0)
/*  f0f374c:	13200005 */ 	beqz	$t9,.L0f0f3764
/*  f0f3750:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0f3754:	e48c0538 */ 	swc1	$f12,0x538($a0)
/*  f0f3758:	e48e053c */ 	swc1	$f14,0x53c($a0)
/*  f0f375c:	c7a4000c */ 	lwc1	$f4,0xc($sp)
/*  f0f3760:	e4840540 */ 	swc1	$f4,0x540($a0)
.L0f0f3764:
/*  f0f3764:	30480004 */ 	andi	$t0,$v0,0x4
/*  f0f3768:	11000007 */ 	beqz	$t0,.L0f0f3788
/*  f0f376c:	30490001 */ 	andi	$t1,$v0,0x1
/*  f0f3770:	c7a60010 */ 	lwc1	$f6,0x10($sp)
/*  f0f3774:	e4860548 */ 	swc1	$f6,0x548($a0)
/*  f0f3778:	c7a80014 */ 	lwc1	$f8,0x14($sp)
/*  f0f377c:	e488054c */ 	swc1	$f8,0x54c($a0)
/*  f0f3780:	c7aa0018 */ 	lwc1	$f10,0x18($sp)
/*  f0f3784:	e48a0550 */ 	swc1	$f10,0x550($a0)
.L0f0f3788:
/*  f0f3788:	11200002 */ 	beqz	$t1,.L0f0f3794
/*  f0f378c:	c7b0001c */ 	lwc1	$f16,0x1c($sp)
/*  f0f3790:	e4900544 */ 	swc1	$f16,0x544($a0)
.L0f0f3794:
/*  f0f3794:	44809000 */ 	mtc1	$zero,$f18
/*  f0f3798:	a0850568 */ 	sb	$a1,0x568($a0)
/*  f0f379c:	03e00008 */ 	jr	$ra
/*  f0f37a0:	e4920564 */ 	swc1	$f18,0x564($a0)
);

GLOBAL_ASM(
glabel func0f0f37a4
/*  f0f37a4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f37a8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f37ac:	8c8e0010 */ 	lw	$t6,0x10($a0)
/*  f0f37b0:	3c014fac */ 	lui	$at,0x4fac
/*  f0f37b4:	34215ace */ 	ori	$at,$at,0x5ace
/*  f0f37b8:	55c10005 */ 	bnel	$t6,$at,.L0f0f37d0
/*  f0f37bc:	44800000 */ 	mtc1	$zero,$f0
/*  f0f37c0:	0fc6709a */ 	jal	mpClearCurrentChallenge
/*  f0f37c4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0f37c8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f0f37cc:	44800000 */ 	mtc1	$zero,$f0
.L0f0f37d0:
/*  f0f37d0:	908f05b1 */ 	lbu	$t7,0x5b1($a0)
/*  f0f37d4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f37d8:	44811000 */ 	mtc1	$at,$f2
/*  f0f37dc:	31f9ff7f */ 	andi	$t9,$t7,0xff7f
/*  f0f37e0:	332900bf */ 	andi	$t1,$t9,0xbf
/*  f0f37e4:	a09905b1 */ 	sb	$t9,0x5b1($a0)
/*  f0f37e8:	312b00df */ 	andi	$t3,$t1,0xdf
/*  f0f37ec:	a08905b1 */ 	sb	$t1,0x5b1($a0)
/*  f0f37f0:	316d00ef */ 	andi	$t5,$t3,0xef
/*  f0f37f4:	a08b05b1 */ 	sb	$t3,0x5b1($a0)
/*  f0f37f8:	31af00f7 */ 	andi	$t7,$t5,0xf7
/*  f0f37fc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0f3800:	44812000 */ 	mtc1	$at,$f4
/*  f0f3804:	a08d05b1 */ 	sb	$t5,0x5b1($a0)
/*  f0f3808:	31f900fb */ 	andi	$t9,$t7,0xfb
/*  f0f380c:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0f3810:	a08f05b1 */ 	sb	$t7,0x5b1($a0)
/*  f0f3814:	a09905b1 */ 	sb	$t9,0x5b1($a0)
/*  f0f3818:	332800fd */ 	andi	$t0,$t9,0xfd
/*  f0f381c:	a0800000 */ 	sb	$zero,0x0($a0)
/*  f0f3820:	ac80000c */ 	sw	$zero,0xc($a0)
/*  f0f3824:	ac800010 */ 	sw	$zero,0x10($a0)
/*  f0f3828:	ac800054 */ 	sw	$zero,0x54($a0)
/*  f0f382c:	ac800058 */ 	sw	$zero,0x58($a0)
/*  f0f3830:	a480005c */ 	sh	$zero,0x5c($a0)
/*  f0f3834:	a480005e */ 	sh	$zero,0x5e($a0)
/*  f0f3838:	a08005b0 */ 	sb	$zero,0x5b0($a0)
/*  f0f383c:	a08805b1 */ 	sb	$t0,0x5b1($a0)
/*  f0f3840:	ac8005b4 */ 	sw	$zero,0x5b4($a0)
/*  f0f3844:	a4820560 */ 	sh	$v0,0x560($a0)
/*  f0f3848:	a4820002 */ 	sh	$v0,0x2($a0)
/*  f0f384c:	a482056a */ 	sh	$v0,0x56a($a0)
/*  f0f3850:	e4800550 */ 	swc1	$f0,0x550($a0)
/*  f0f3854:	e480054c */ 	swc1	$f0,0x54c($a0)
/*  f0f3858:	e4800548 */ 	swc1	$f0,0x548($a0)
/*  f0f385c:	e4800540 */ 	swc1	$f0,0x540($a0)
/*  f0f3860:	e480053c */ 	swc1	$f0,0x53c($a0)
/*  f0f3864:	e4800538 */ 	swc1	$f0,0x538($a0)
/*  f0f3868:	e4800534 */ 	swc1	$f0,0x534($a0)
/*  f0f386c:	e4800530 */ 	swc1	$f0,0x530($a0)
/*  f0f3870:	e480052c */ 	swc1	$f0,0x52c($a0)
/*  f0f3874:	e4800528 */ 	swc1	$f0,0x528($a0)
/*  f0f3878:	e4800524 */ 	swc1	$f0,0x524($a0)
/*  f0f387c:	e4800520 */ 	swc1	$f0,0x520($a0)
/*  f0f3880:	e4800518 */ 	swc1	$f0,0x518($a0)
/*  f0f3884:	e4800514 */ 	swc1	$f0,0x514($a0)
/*  f0f3888:	e4800510 */ 	swc1	$f0,0x510($a0)
/*  f0f388c:	e4800558 */ 	swc1	$f0,0x558($a0)
/*  f0f3890:	e482055c */ 	swc1	$f2,0x55c($a0)
/*  f0f3894:	e482051c */ 	swc1	$f2,0x51c($a0)
/*  f0f3898:	e4820544 */ 	swc1	$f2,0x544($a0)
/*  f0f389c:	e4840554 */ 	swc1	$f4,0x554($a0)
/*  f0f38a0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f38a4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f38a8:	03e00008 */ 	jr	$ra
/*  f0f38ac:	00000000 */ 	nop
);

u32 var80071468 = 0x96969600;
u32 var8007146c = 0x96969600;

u32 var80071470 = 0xffffff00;
u32 var80071474 = 0xffffff00;
u32 var80071478 = 0xb24d2e00;
u32 var8007147c = 0x00000000;

u32 var80071480 = 0x00000000;
u32 var80071484 = 0x00000001;
u32 var80071488 = 0x00000003;
u32 var8007148c = 0x00000000;
u32 var80071490 = 0x00000000;
u32 var80071494 = 0x00000000;
u32 var80071498 = 0x00000000;
u32 var8007149c = 0x00000000;
u32 var800714a0 = 0x00000000;
u32 var800714a4 = 0x00000000;
u32 var800714a8 = 0x00000000;
u32 var800714ac = 0x00000000;
u32 var800714b0 = 0x00000000;
u32 var800714b4 = 0x00000000;
u32 var800714b8 = 0x00000000;
u32 var800714bc = 0x00000000;

u32 var800714c0 = 0x0000000a;

u32 var800714c4 = 0x0000012c;

GLOBAL_ASM(
glabel func0f0f38b0
.late_rodata
glabel var7f1b292c
.word 0x40f33333
glabel var7f1b2930
.word 0x3b03126f
glabel var7f1b2934
.word 0x3f7f7cee
glabel var7f1b2938
.word 0x3f7f7cee
glabel var7f1b293c
.word 0x3b03126f
glabel var7f1b2940
.word 0x3b03126f
glabel var7f1b2944
.word 0x3b03126f
glabel var7f1b2948
.word 0x40490fdb
.text
/*  f0f38b0:	27bdfbc0 */ 	addiu	$sp,$sp,-1088
/*  f0f38b4:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x4b4)
/*  f0f38b8:	8c42a474 */ 	lw	$v0,%lo(g_Vars+0x4b4)($v0)
/*  f0f38bc:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f0f38c0:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0f38c4:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0f38c8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0f38cc:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f0f38d0:	afa40440 */ 	sw	$a0,0x440($sp)
/*  f0f38d4:	1041001d */ 	beq	$v0,$at,.L0f0f394c
/*  f0f38d8:	afa60448 */ 	sw	$a2,0x448($sp)
/*  f0f38dc:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f0f38e0:	1041001a */ 	beq	$v0,$at,.L0f0f394c
/*  f0f38e4:	3c0e800a */ 	lui	$t6,%hi(g_MenuData+0x5d5)
/*  f0f38e8:	81cf1f95 */ 	lb	$t7,%lo(g_MenuData+0x5d5)($t6)
/*  f0f38ec:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f38f0:	05e30008 */ 	bgezl	$t7,.L0f0f3914
/*  f0f38f4:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f0f38f8:	10c10005 */ 	beq	$a2,$at,.L0f0f3910
/*  f0f38fc:	28c10003 */ 	slti	$at,$a2,0x3
/*  f0f3900:	50200004 */ 	beqzl	$at,.L0f0f3914
/*  f0f3904:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f0f3908:	100005b9 */ 	b	.L0f0f4ff0
/*  f0f390c:	00801025 */ 	or	$v0,$a0,$zero
.L0f0f3910:
/*  f0f3910:	8e190004 */ 	lw	$t9,0x4($s0)
.L0f0f3914:
/*  f0f3914:	5720000e */ 	bnezl	$t9,.L0f0f3950
/*  f0f3918:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f0f391c:	0fc27801 */ 	jal	func0f09e004
/*  f0f3920:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0f3924:	10400007 */ 	beqz	$v0,.L0f0f3944
/*  f0f3928:	00000000 */ 	nop
/*  f0f392c:	0fc2777b */ 	jal	func0f09ddec
/*  f0f3930:	00000000 */ 	nop
/*  f0f3934:	0fc2777f */ 	jal	func0f09ddfc
/*  f0f3938:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f0f393c:	10000003 */ 	b	.L0f0f394c
/*  f0f3940:	ae020008 */ 	sw	$v0,0x8($s0)
.L0f0f3944:
/*  f0f3944:	100005aa */ 	b	.L0f0f4ff0
/*  f0f3948:	8fa20440 */ 	lw	$v0,0x440($sp)
.L0f0f394c:
/*  f0f394c:	8e0a0004 */ 	lw	$t2,0x4($s0)
.L0f0f3950:
/*  f0f3950:	55400004 */ 	bnezl	$t2,.L0f0f3964
/*  f0f3954:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f0f3958:	100005a5 */ 	b	.L0f0f4ff0
/*  f0f395c:	8fa20440 */ 	lw	$v0,0x440($sp)
/*  f0f3960:	8e02000c */ 	lw	$v0,0xc($s0)
.L0f0f3964:
/*  f0f3964:	504000dc */ 	beqzl	$v0,.L0f0f3cd8
/*  f0f3968:	8e0a0054 */ 	lw	$t2,0x54($s0)
/*  f0f396c:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0f3970:	3c014fac */ 	lui	$at,0x4fac
/*  f0f3974:	34215ace */ 	ori	$at,$at,0x5ace
/*  f0f3978:	14620004 */ 	bne	$v1,$v0,.L0f0f398c
/*  f0f397c:	00000000 */ 	nop
/*  f0f3980:	ae00000c */ 	sw	$zero,0xc($s0)
/*  f0f3984:	100000d3 */ 	b	.L0f0f3cd4
/*  f0f3988:	a2000000 */ 	sb	$zero,0x0($s0)
.L0f0f398c:
/*  f0f398c:	54610004 */ 	bnel	$v1,$at,.L0f0f39a0
/*  f0f3990:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f0f3994:	0fc6709a */ 	jal	mpClearCurrentChallenge
/*  f0f3998:	00000000 */ 	nop
/*  f0f399c:	92020000 */ 	lbu	$v0,0x0($s0)
.L0f0f39a0:
/*  f0f39a0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0f39a4:	14400004 */ 	bnez	$v0,.L0f0f39b8
/*  f0f39a8:	244cffff */ 	addiu	$t4,$v0,-1
/*  f0f39ac:	a20b0000 */ 	sb	$t3,0x0($s0)
/*  f0f39b0:	1000058f */ 	b	.L0f0f4ff0
/*  f0f39b4:	8fa20440 */ 	lw	$v0,0x440($sp)
.L0f0f39b8:
/*  f0f39b8:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f0f39bc:	15a000c3 */ 	bnez	$t5,.L0f0f3ccc
/*  f0f39c0:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f0f39c4:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f0f39c8:	3401ffff */ 	dli	$at,0xffff
/*  f0f39cc:	304effff */ 	andi	$t6,$v0,0xffff
/*  f0f39d0:	11c10002 */ 	beq	$t6,$at,.L0f0f39dc
/*  f0f39d4:	00027800 */ 	sll	$t7,$v0,0x0
/*  f0f39d8:	05e10092 */ 	bgez	$t7,.L0f0f3c24
.L0f0f39dc:
/*  f0f39dc:	0002c000 */ 	sll	$t8,$v0,0x0
/*  f0f39e0:	07010008 */ 	bgez	$t8,.L0f0f3a04
/*  f0f39e4:	3c01000f */ 	lui	$at,0xf
/*  f0f39e8:	3421fc00 */ 	ori	$at,$at,0xfc00
/*  f0f39ec:	00415024 */ 	and	$t2,$v0,$at
/*  f0f39f0:	305903ff */ 	andi	$t9,$v0,0x3ff
/*  f0f39f4:	000a5a82 */ 	srl	$t3,$t2,0xa
/*  f0f39f8:	afb90400 */ 	sw	$t9,0x400($sp)
/*  f0f39fc:	1000001a */ 	b	.L0f0f3a68
/*  f0f3a00:	afab0404 */ 	sw	$t3,0x404($sp)
.L0f0f3a04:
/*  f0f3a04:	00028c02 */ 	srl	$s1,$v0,0x10
/*  f0f3a08:	322c00ff */ 	andi	$t4,$s1,0xff
/*  f0f3a0c:	00026e02 */ 	srl	$t5,$v0,0x18
/*  f0f3a10:	01808825 */ 	or	$s1,$t4,$zero
/*  f0f3a14:	0fc62ee4 */ 	jal	mpGetBodyId
/*  f0f3a18:	31a400ff */ 	andi	$a0,$t5,0xff
/*  f0f3a1c:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f0f3a20:	afa20404 */ 	sw	$v0,0x404($sp)
/*  f0f3a24:	0222082a */ 	slt	$at,$s1,$v0
/*  f0f3a28:	10200005 */ 	beqz	$at,.L0f0f3a40
/*  f0f3a2c:	00000000 */ 	nop
/*  f0f3a30:	0fc62ecb */ 	jal	mpGetHeadId
/*  f0f3a34:	322400ff */ 	andi	$a0,$s1,0xff
/*  f0f3a38:	1000000b */ 	b	.L0f0f3a68
/*  f0f3a3c:	afa20400 */ 	sw	$v0,0x400($sp)
.L0f0f3a40:
/*  f0f3a40:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f0f3a44:	00000000 */ 	nop
/*  f0f3a48:	0fc52a7e */ 	jal	func0f14a9f8
/*  f0f3a4c:	02222023 */ 	subu	$a0,$s1,$v0
/*  f0f3a50:	0fc62ed9 */ 	jal	mpGetBeauHeadId
/*  f0f3a54:	304400ff */ 	andi	$a0,$v0,0xff
/*  f0f3a58:	0fc62ec7 */ 	jal	func0f18bb1c
/*  f0f3a5c:	afa20400 */ 	sw	$v0,0x400($sp)
/*  f0f3a60:	02227823 */ 	subu	$t7,$s1,$v0
/*  f0f3a64:	a20f05b0 */ 	sb	$t7,0x5b0($s0)
.L0f0f3a68:
/*  f0f3a68:	8fb80404 */ 	lw	$t8,0x404($sp)
/*  f0f3a6c:	3c0a8008 */ 	lui	$t2,%hi(g_Bodies)
/*  f0f3a70:	254acf04 */ 	addiu	$t2,$t2,%lo(g_Bodies)
/*  f0f3a74:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0f3a78:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0f3a7c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f3a80:	032a8821 */ 	addu	$s1,$t9,$t2
/*  f0f3a84:	96220002 */ 	lhu	$v0,0x2($s1)
/*  f0f3a88:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f3a8c:	a7a2040a */ 	sh	$v0,0x40a($sp)
/*  f0f3a90:	0fc59c15 */ 	jal	func0f167054
/*  f0f3a94:	afa2003c */ 	sw	$v0,0x3c($sp)
/*  f0f3a98:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f0f3a9c:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f0f3aa0:	346b003f */ 	ori	$t3,$v1,0x3f
/*  f0f3aa4:	000d7840 */ 	sll	$t7,$t5,0x1
/*  f0f3aa8:	05e10005 */ 	bgez	$t7,.L0f0f3ac0
/*  f0f3aac:	3963003f */ 	xori	$v1,$t3,0x3f
/*  f0f3ab0:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0f3ab4:	afb80400 */ 	sw	$t8,0x400($sp)
/*  f0f3ab8:	10000011 */ 	b	.L0f0f3b00
/*  f0f3abc:	3411ffff */ 	dli	$s1,0xffff
.L0f0f3ac0:
/*  f0f3ac0:	8fb90400 */ 	lw	$t9,0x400($sp)
/*  f0f3ac4:	3c118008 */ 	lui	$s1,%hi(g_Bodies+0x2)
/*  f0f3ac8:	afa30420 */ 	sw	$v1,0x420($sp)
/*  f0f3acc:	00195080 */ 	sll	$t2,$t9,0x2
/*  f0f3ad0:	01595021 */ 	addu	$t2,$t2,$t9
/*  f0f3ad4:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0f3ad8:	022a8821 */ 	addu	$s1,$s1,$t2
/*  f0f3adc:	9631cf06 */ 	lhu	$s1,%lo(g_Bodies+0x2)($s1)
/*  f0f3ae0:	0fc59c15 */ 	jal	func0f167054
/*  f0f3ae4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f3ae8:	8fab0420 */ 	lw	$t3,0x420($sp)
/*  f0f3aec:	244c003f */ 	addiu	$t4,$v0,0x3f
/*  f0f3af0:	358d003f */ 	ori	$t5,$t4,0x3f
/*  f0f3af4:	39ae003f */ 	xori	$t6,$t5,0x3f
/*  f0f3af8:	016e1821 */ 	addu	$v1,$t3,$t6
/*  f0f3afc:	afa30420 */ 	sw	$v1,0x420($sp)
.L0f0f3b00:
/*  f0f3b00:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f0f3b04:	8e190008 */ 	lw	$t9,0x8($s0)
/*  f0f3b08:	24634000 */ 	addiu	$v1,$v1,0x4000
/*  f0f3b0c:	afa30420 */ 	sw	$v1,0x420($sp)
/*  f0f3b10:	27a40410 */ 	addiu	$a0,$sp,0x410
/*  f0f3b14:	03032821 */ 	addu	$a1,$t8,$v1
/*  f0f3b18:	0fc5cb9c */ 	jal	func0f172e70
/*  f0f3b1c:	03233023 */ 	subu	$a2,$t9,$v1
/*  f0f3b20:	8faa0400 */ 	lw	$t2,0x400($sp)
/*  f0f3b24:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f0f3b28:	27a70410 */ 	addiu	$a3,$sp,0x410
/*  f0f3b2c:	a60a0002 */ 	sh	$t2,0x2($s0)
/*  f0f3b30:	8fac0404 */ 	lw	$t4,0x404($sp)
/*  f0f3b34:	a60c056a */ 	sh	$t4,0x56a($s0)
/*  f0f3b38:	8fa60420 */ 	lw	$a2,0x420($sp)
/*  f0f3b3c:	0fc69de5 */ 	jal	func0f1a7794
/*  f0f3b40:	97a4040a */ 	lhu	$a0,0x40a($sp)
/*  f0f3b44:	ae020054 */ 	sw	$v0,0x54($s0)
/*  f0f3b48:	0fc59ca0 */ 	jal	fileGetSize
/*  f0f3b4c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f3b50:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f0f3b54:	346d003f */ 	ori	$t5,$v1,0x3f
/*  f0f3b58:	39ab003f */ 	xori	$t3,$t5,0x3f
/*  f0f3b5c:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f3b60:	0c008b49 */ 	jal	func00022d24
/*  f0f3b64:	afab040c */ 	sw	$t3,0x40c($sp)
/*  f0f3b68:	8fae0400 */ 	lw	$t6,0x400($sp)
/*  f0f3b6c:	8fa3040c */ 	lw	$v1,0x40c($sp)
/*  f0f3b70:	3224ffff */ 	andi	$a0,$s1,0xffff
/*  f0f3b74:	05c10003 */ 	bgez	$t6,.L0f0f3b84
/*  f0f3b78:	8fb80420 */ 	lw	$t8,0x420($sp)
/*  f0f3b7c:	10000010 */ 	b	.L0f0f3bc0
/*  f0f3b80:	ae000058 */ 	sw	$zero,0x58($s0)
.L0f0f3b84:
/*  f0f3b84:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f0f3b88:	afb10040 */ 	sw	$s1,0x40($sp)
/*  f0f3b8c:	03033023 */ 	subu	$a2,$t8,$v1
/*  f0f3b90:	27a70410 */ 	addiu	$a3,$sp,0x410
/*  f0f3b94:	0fc69de5 */ 	jal	func0f1a7794
/*  f0f3b98:	01e32821 */ 	addu	$a1,$t7,$v1
/*  f0f3b9c:	ae020058 */ 	sw	$v0,0x58($s0)
/*  f0f3ba0:	0fc59ca0 */ 	jal	fileGetSize
/*  f0f3ba4:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f3ba8:	8e040058 */ 	lw	$a0,0x58($s0)
/*  f0f3bac:	8fa50400 */ 	lw	$a1,0x400($sp)
/*  f0f3bb0:	0fc0b76f */ 	jal	func0f02ddbc
/*  f0f3bb4:	8fa60404 */ 	lw	$a2,0x404($sp)
/*  f0f3bb8:	0c008b49 */ 	jal	func00022d24
/*  f0f3bbc:	8e040058 */ 	lw	$a0,0x58($s0)
.L0f0f3bc0:
/*  f0f3bc0:	26040060 */ 	addiu	$a0,$s0,0x60
/*  f0f3bc4:	8e050054 */ 	lw	$a1,0x54($s0)
/*  f0f3bc8:	afa4003c */ 	sw	$a0,0x3c($sp)
/*  f0f3bcc:	26060110 */ 	addiu	$a2,$s0,0x110
/*  f0f3bd0:	0c008be9 */ 	jal	func00022fa4
/*  f0f3bd4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0f3bd8:	26110084 */ 	addiu	$s1,$s0,0x84
/*  f0f3bdc:	0c008c28 */ 	jal	animInitialise
/*  f0f3be0:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f3be4:	24190100 */ 	addiu	$t9,$zero,0x100
/*  f0f3be8:	a6190062 */ 	sh	$t9,0x62($s0)
/*  f0f3bec:	ae110080 */ 	sw	$s1,0x80($s0)
/*  f0f3bf0:	8e060054 */ 	lw	$a2,0x54($s0)
/*  f0f3bf4:	8e070058 */ 	lw	$a3,0x58($s0)
/*  f0f3bf8:	8faa003c */ 	lw	$t2,0x3c($sp)
/*  f0f3bfc:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f3c00:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0f3c04:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f3c08:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0f3c0c:	8fa50400 */ 	lw	$a1,0x400($sp)
/*  f0f3c10:	8fa40404 */ 	lw	$a0,0x404($sp)
/*  f0f3c14:	0fc0b3a3 */ 	jal	func0f02ce8c
/*  f0f3c18:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0f3c1c:	10000027 */ 	b	.L0f0f3cbc
/*  f0f3c20:	8e19000c */ 	lw	$t9,0xc($s0)
.L0f0f3c24:
/*  f0f3c24:	0fc59c15 */ 	jal	func0f167054
/*  f0f3c28:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f3c2c:	2443003f */ 	addiu	$v1,$v0,0x3f
/*  f0f3c30:	346d003f */ 	ori	$t5,$v1,0x3f
/*  f0f3c34:	39ab003f */ 	xori	$t3,$t5,0x3f
/*  f0f3c38:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f0f3c3c:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*  f0f3c40:	25634000 */ 	addiu	$v1,$t3,0x4000
/*  f0f3c44:	afa30420 */ 	sw	$v1,0x420($sp)
/*  f0f3c48:	27a40410 */ 	addiu	$a0,$sp,0x410
/*  f0f3c4c:	01c32821 */ 	addu	$a1,$t6,$v1
/*  f0f3c50:	0fc5cb9c */ 	jal	func0f172e70
/*  f0f3c54:	01e33023 */ 	subu	$a2,$t7,$v1
/*  f0f3c58:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0f3c5c:	a6020002 */ 	sh	$v0,0x2($s0)
/*  f0f3c60:	a602056a */ 	sh	$v0,0x56a($s0)
/*  f0f3c64:	8fa60420 */ 	lw	$a2,0x420($sp)
/*  f0f3c68:	9604000e */ 	lhu	$a0,0xe($s0)
/*  f0f3c6c:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f0f3c70:	0fc69de5 */ 	jal	func0f1a7794
/*  f0f3c74:	27a70410 */ 	addiu	$a3,$sp,0x410
/*  f0f3c78:	ae020054 */ 	sw	$v0,0x54($s0)
/*  f0f3c7c:	0fc59ca0 */ 	jal	fileGetSize
/*  f0f3c80:	8e04000c */ 	lw	$a0,0xc($s0)
/*  f0f3c84:	0c008b49 */ 	jal	func00022d24
/*  f0f3c88:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f3c8c:	26040060 */ 	addiu	$a0,$s0,0x60
/*  f0f3c90:	8e050054 */ 	lw	$a1,0x54($s0)
/*  f0f3c94:	26060110 */ 	addiu	$a2,$s0,0x110
/*  f0f3c98:	0c008be9 */ 	jal	func00022fa4
/*  f0f3c9c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0f3ca0:	26110084 */ 	addiu	$s1,$s0,0x84
/*  f0f3ca4:	0c008c28 */ 	jal	animInitialise
/*  f0f3ca8:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f3cac:	24180100 */ 	addiu	$t8,$zero,0x100
/*  f0f3cb0:	a6180062 */ 	sh	$t8,0x62($s0)
/*  f0f3cb4:	ae110080 */ 	sw	$s1,0x80($s0)
/*  f0f3cb8:	8e19000c */ 	lw	$t9,0xc($s0)
.L0f0f3cbc:
/*  f0f3cbc:	a600005e */ 	sh	$zero,0x5e($s0)
/*  f0f3cc0:	ae00000c */ 	sw	$zero,0xc($s0)
/*  f0f3cc4:	10000003 */ 	b	.L0f0f3cd4
/*  f0f3cc8:	ae190010 */ 	sw	$t9,0x10($s0)
.L0f0f3ccc:
/*  f0f3ccc:	100004c8 */ 	b	.L0f0f4ff0
/*  f0f3cd0:	8fa20440 */ 	lw	$v0,0x440($sp)
.L0f0f3cd4:
/*  f0f3cd4:	8e0a0054 */ 	lw	$t2,0x54($s0)
.L0f0f3cd8:
/*  f0f3cd8:	3c0d8007 */ 	lui	$t5,%hi(var80071480)
/*  f0f3cdc:	25ad1480 */ 	addiu	$t5,$t5,%lo(var80071480)
/*  f0f3ce0:	114004c2 */ 	beqz	$t2,.L0f0f4fec
/*  f0f3ce4:	27ac03b8 */ 	addiu	$t4,$sp,0x3b8
/*  f0f3ce8:	25ae003c */ 	addiu	$t6,$t5,0x3c
.L0f0f3cec:
/*  f0f3cec:	8da10000 */ 	lw	$at,0x0($t5)
/*  f0f3cf0:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f0f3cf4:	258c000c */ 	addiu	$t4,$t4,0xc
/*  f0f3cf8:	ad81fff4 */ 	sw	$at,-0xc($t4)
/*  f0f3cfc:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*  f0f3d00:	ad81fff8 */ 	sw	$at,-0x8($t4)
/*  f0f3d04:	8da1fffc */ 	lw	$at,-0x4($t5)
/*  f0f3d08:	15aefff8 */ 	bne	$t5,$t6,.L0f0f3cec
/*  f0f3d0c:	ad81fffc */ 	sw	$at,-0x4($t4)
/*  f0f3d10:	8da10000 */ 	lw	$at,0x0($t5)
/*  f0f3d14:	260f0060 */ 	addiu	$t7,$s0,0x60
/*  f0f3d18:	ad810000 */ 	sw	$at,0x0($t4)
/*  f0f3d1c:	8fb80448 */ 	lw	$t8,0x448($sp)
/*  f0f3d20:	afaf003c */ 	sw	$t7,0x3c($sp)
/*  f0f3d24:	2b010003 */ 	slti	$at,$t8,0x3
/*  f0f3d28:	1020001b */ 	beqz	$at,.L0f0f3d98
/*  f0f3d2c:	3c19800a */ 	lui	$t9,%hi(g_MenuData+0x5d4)
/*  f0f3d30:	8f391f94 */ 	lw	$t9,%lo(g_MenuData+0x5d4)($t9)
/*  f0f3d34:	00195a80 */ 	sll	$t3,$t9,0xa
/*  f0f3d38:	05630018 */ 	bgezl	$t3,.L0f0f3d9c
/*  f0f3d3c:	8faa0440 */ 	lw	$t2,0x440($sp)
/*  f0f3d40:	0c002ca0 */ 	jal	func0000b280
/*  f0f3d44:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f3d48:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f3d4c:	0c002c74 */ 	jal	func0000b1d0
/*  f0f3d50:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f3d54:	3c0e800a */ 	lui	$t6,%hi(g_MenuData+0x5d5)
/*  f0f3d58:	91ce1f95 */ 	lbu	$t6,%lo(g_MenuData+0x5d5)($t6)
/*  f0f3d5c:	8fac0448 */ 	lw	$t4,0x448($sp)
/*  f0f3d60:	3c01800a */ 	lui	$at,%hi(g_MenuData+0x5d5)
/*  f0f3d64:	31cdffdf */ 	andi	$t5,$t6,0xffdf
/*  f0f3d68:	a02d1f95 */ 	sb	$t5,%lo(g_MenuData+0x5d5)($at)
/*  f0f3d6c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f3d70:	11810003 */ 	beq	$t4,$at,.L0f0f3d80
/*  f0f3d74:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f3d78:	0fc3d43f */ 	jal	func0f0f50fc
/*  f0f3d7c:	00402025 */ 	or	$a0,$v0,$zero
.L0f0f3d80:
/*  f0f3d80:	244f0008 */ 	addiu	$t7,$v0,0x8
/*  f0f3d84:	afaf0440 */ 	sw	$t7,0x440($sp)
/*  f0f3d88:	3c18b700 */ 	lui	$t8,0xb700
/*  f0f3d8c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f3d90:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0f3d94:	ac580000 */ 	sw	$t8,0x0($v0)
.L0f0f3d98:
/*  f0f3d98:	8faa0440 */ 	lw	$t2,0x440($sp)
.L0f0f3d9c:
/*  f0f3d9c:	3c0d8006 */ 	lui	$t5,%hi(var80061380)
/*  f0f3da0:	25ad1380 */ 	addiu	$t5,$t5,%lo(var80061380)
/*  f0f3da4:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0f3da8:	afab0440 */ 	sw	$t3,0x440($sp)
/*  f0f3dac:	3c0e0600 */ 	lui	$t6,0x600
/*  f0f3db0:	ad4e0000 */ 	sw	$t6,0x0($t2)
/*  f0f3db4:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0f3db8:	8fac0440 */ 	lw	$t4,0x440($sp)
/*  f0f3dbc:	3c180600 */ 	lui	$t8,0x600
/*  f0f3dc0:	3c198006 */ 	lui	$t9,%hi(var800613a0)
/*  f0f3dc4:	258f0008 */ 	addiu	$t7,$t4,0x8
/*  f0f3dc8:	afaf0440 */ 	sw	$t7,0x440($sp)
/*  f0f3dcc:	273913a0 */ 	addiu	$t9,$t9,%lo(var800613a0)
/*  f0f3dd0:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f0f3dd4:	afb90038 */ 	sw	$t9,0x38($sp)
/*  f0f3dd8:	ad990004 */ 	sw	$t9,0x4($t4)
/*  f0f3ddc:	afa00308 */ 	sw	$zero,0x308($sp)
/*  f0f3de0:	c6060554 */ 	lwc1	$f6,0x554($s0)
/*  f0f3de4:	44802000 */ 	mtc1	$zero,$f4
/*  f0f3de8:	00000000 */ 	nop
/*  f0f3dec:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0f3df0:	00000000 */ 	nop
/*  f0f3df4:	4500005c */ 	bc1f	.L0f0f3f68
/*  f0f3df8:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0f3dfc:	afaa02f4 */ 	sw	$t2,0x2f4($sp)
/*  f0f3e00:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f3e04:	3c0b8008 */ 	lui	$t3,%hi(stagethinglist_22e60)
/*  f0f3e08:	256bce40 */ 	addiu	$t3,$t3,%lo(stagethinglist_22e60)
/*  f0f3e0c:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*  f0f3e10:	556e002f */ 	bnel	$t3,$t6,.L0f0f3ed0
/*  f0f3e14:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f0f3e18:	0c006a47 */ 	jal	modelGetPart
/*  f0f3e1c:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f0f3e20:	5040002b */ 	beqzl	$v0,.L0f0f3ed0
/*  f0f3e24:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f0f3e28:	8e0d0574 */ 	lw	$t5,0x574($s0)
/*  f0f3e2c:	3c0143f0 */ 	lui	$at,0x43f0
/*  f0f3e30:	44812000 */ 	mtc1	$at,$f4
/*  f0f3e34:	448d4000 */ 	mtc1	$t5,$f8
/*  f0f3e38:	8c510004 */ 	lw	$s1,0x4($v0)
/*  f0f3e3c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0f3e40:	0fc01af4 */ 	jal	func0f006bd0
/*  f0f3e44:	46045303 */ 	div.s	$f12,$f10,$f4
/*  f0f3e48:	44806000 */ 	mtc1	$zero,$f12
/*  f0f3e4c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f3e50:	44817000 */ 	mtc1	$at,$f14
/*  f0f3e54:	3c017f1b */ 	lui	$at,%hi(var7f1b292c)
/*  f0f3e58:	e7ac02fc */ 	swc1	$f12,0x2fc($sp)
/*  f0f3e5c:	c6260004 */ 	lwc1	$f6,0x4($s1)
/*  f0f3e60:	c428292c */ 	lwc1	$f8,%lo(var7f1b292c)($at)
/*  f0f3e64:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f0f3e68:	3c014387 */ 	lui	$at,0x4387
/*  f0f3e6c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f3e70:	afac0308 */ 	sw	$t4,0x308($sp)
/*  f0f3e74:	e7ac0304 */ 	swc1	$f12,0x304($sp)
/*  f0f3e78:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f0f3e7c:	46047181 */ 	sub.s	$f6,$f14,$f4
/*  f0f3e80:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0f3e84:	46007281 */ 	sub.s	$f10,$f14,$f0
/*  f0f3e88:	44813000 */ 	mtc1	$at,$f6
/*  f0f3e8c:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0f3e90:	46086101 */ 	sub.s	$f4,$f12,$f8
/*  f0f3e94:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0f3e98:	e7a40300 */ 	swc1	$f4,0x300($sp)
/*  f0f3e9c:	44812000 */ 	mtc1	$at,$f4
/*  f0f3ea0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f3ea4:	44813000 */ 	mtc1	$at,$f6
/*  f0f3ea8:	46044080 */ 	add.s	$f2,$f8,$f4
/*  f0f3eac:	e6020554 */ 	swc1	$f2,0x554($s0)
/*  f0f3eb0:	c62a0004 */ 	lwc1	$f10,0x4($s1)
/*  f0f3eb4:	afa002f4 */ 	sw	$zero,0x2f4($sp)
/*  f0f3eb8:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f3ebc:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0f3ec0:	46081103 */ 	div.s	$f4,$f2,$f8
/*  f0f3ec4:	0fc1a2aa */ 	jal	func0f068aa8
/*  f0f3ec8:	e7a402f8 */ 	swc1	$f4,0x2f8($sp)
/*  f0f3ecc:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
.L0f0f3ed0:
/*  f0f3ed0:	11e00025 */ 	beqz	$t7,.L0f0f3f68
/*  f0f3ed4:	00000000 */ 	nop
/*  f0f3ed8:	0fc1a2aa */ 	jal	func0f068aa8
/*  f0f3edc:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f3ee0:	10400021 */ 	beqz	$v0,.L0f0f3f68
/*  f0f3ee4:	00000000 */ 	nop
/*  f0f3ee8:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f0f3eec:	c44a0004 */ 	lwc1	$f10,0x4($v0)
/*  f0f3ef0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f3ef4:	44817000 */ 	mtc1	$at,$f14
/*  f0f3ef8:	460a0181 */ 	sub.s	$f6,$f0,$f10
/*  f0f3efc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f3f00:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*  f0f3f04:	46080101 */ 	sub.s	$f4,$f0,$f8
/*  f0f3f08:	46002287 */ 	neg.s	$f10,$f4
/*  f0f3f0c:	e7aa02fc */ 	swc1	$f10,0x2fc($sp)
/*  f0f3f10:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f0f3f14:	c4420010 */ 	lwc1	$f2,0x10($v0)
/*  f0f3f18:	46061201 */ 	sub.s	$f8,$f2,$f6
/*  f0f3f1c:	460e4102 */ 	mul.s	$f4,$f8,$f14
/*  f0f3f20:	46041281 */ 	sub.s	$f10,$f2,$f4
/*  f0f3f24:	46005187 */ 	neg.s	$f6,$f10
/*  f0f3f28:	e7a60300 */ 	swc1	$f6,0x300($sp)
/*  f0f3f2c:	c4480014 */ 	lwc1	$f8,0x14($v0)
/*  f0f3f30:	c44c0018 */ 	lwc1	$f12,0x18($v0)
/*  f0f3f34:	afb80308 */ 	sw	$t8,0x308($sp)
/*  f0f3f38:	46086101 */ 	sub.s	$f4,$f12,$f8
/*  f0f3f3c:	460e2282 */ 	mul.s	$f10,$f4,$f14
/*  f0f3f40:	460a6181 */ 	sub.s	$f6,$f12,$f10
/*  f0f3f44:	46003207 */ 	neg.s	$f8,$f6
/*  f0f3f48:	e7a80304 */ 	swc1	$f8,0x304($sp)
/*  f0f3f4c:	c44a000c */ 	lwc1	$f10,0xc($v0)
/*  f0f3f50:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0f3f54:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f0f3f58:	c6040554 */ 	lwc1	$f4,0x554($s0)
/*  f0f3f5c:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*  f0f3f60:	46082283 */ 	div.s	$f10,$f4,$f8
/*  f0f3f64:	e7aa02f8 */ 	swc1	$f10,0x2f8($sp)
.L0f0f3f68:
/*  f0f3f68:	0c00566c */ 	jal	func000159b0
/*  f0f3f6c:	27a40350 */ 	addiu	$a0,$sp,0x350
/*  f0f3f70:	8fb90448 */ 	lw	$t9,0x448($sp)
/*  f0f3f74:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f3f78:	17210083 */ 	bne	$t9,$at,.L0f0f4188
/*  f0f3f7c:	3c0a8009 */ 	lui	$t2,%hi(g_Is4Mb)
/*  f0f3f80:	914a0af0 */ 	lbu	$t2,%lo(g_Is4Mb)($t2)
/*  f0f3f84:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f3f88:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f3f8c:	11410130 */ 	beq	$t2,$at,.L0f0f4450
/*  f0f3f90:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f3f94:	c6000538 */ 	lwc1	$f0,0x538($s0)
/*  f0f3f98:	c6060510 */ 	lwc1	$f6,0x510($s0)
/*  f0f3f9c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0f3fa0:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0f3fa4:	46060032 */ 	c.eq.s	$f0,$f6
/*  f0f3fa8:	00000000 */ 	nop
/*  f0f3fac:	45030014 */ 	bc1tl	.L0f0f4000
/*  f0f3fb0:	c60c053c */ 	lwc1	$f12,0x53c($s0)
/*  f0f3fb4:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f0f3fb8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f3fbc:	3c017f1b */ 	lui	$at,%hi(var7f1b2930)
/*  f0f3fc0:	5960000f */ 	blezl	$t3,.L0f0f4000
/*  f0f3fc4:	c60c053c */ 	lwc1	$f12,0x53c($s0)
/*  f0f3fc8:	c4242930 */ 	lwc1	$f4,%lo(var7f1b2930)($at)
/*  f0f3fcc:	3c017f1b */ 	lui	$at,%hi(var7f1b2934)
/*  f0f3fd0:	46040082 */ 	mul.s	$f2,$f0,$f4
/*  f0f3fd4:	c4202934 */ 	lwc1	$f0,%lo(var7f1b2934)($at)
/*  f0f3fd8:	c6080510 */ 	lwc1	$f8,0x510($s0)
.L0f0f3fdc:
/*  f0f3fdc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f3fe0:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0f3fe4:	460a1180 */ 	add.s	$f6,$f2,$f10
/*  f0f3fe8:	e6060510 */ 	swc1	$f6,0x510($s0)
/*  f0f3fec:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0f3ff0:	004e082a */ 	slt	$at,$v0,$t6
/*  f0f3ff4:	5420fff9 */ 	bnezl	$at,.L0f0f3fdc
/*  f0f3ff8:	c6080510 */ 	lwc1	$f8,0x510($s0)
/*  f0f3ffc:	c60c053c */ 	lwc1	$f12,0x53c($s0)
.L0f0f4000:
/*  f0f4000:	c6040514 */ 	lwc1	$f4,0x514($s0)
/*  f0f4004:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0f4008:	3c017f1b */ 	lui	$at,%hi(var7f1b2938)
/*  f0f400c:	46046032 */ 	c.eq.s	$f12,$f4
/*  f0f4010:	c4202938 */ 	lwc1	$f0,%lo(var7f1b2938)($at)
/*  f0f4014:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0f4018:	3c0b8007 */ 	lui	$t3,%hi(g_HiResActive)
/*  f0f401c:	45030013 */ 	bc1tl	.L0f0f406c
/*  f0f4020:	c60c0540 */ 	lwc1	$f12,0x540($s0)
/*  f0f4024:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f0f4028:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f402c:	3c017f1b */ 	lui	$at,%hi(var7f1b293c)
/*  f0f4030:	59a0000e */ 	blezl	$t5,.L0f0f406c
/*  f0f4034:	c60c0540 */ 	lwc1	$f12,0x540($s0)
/*  f0f4038:	c428293c */ 	lwc1	$f8,%lo(var7f1b293c)($at)
/*  f0f403c:	46086082 */ 	mul.s	$f2,$f12,$f8
/*  f0f4040:	00000000 */ 	nop
/*  f0f4044:	c60a0514 */ 	lwc1	$f10,0x514($s0)
.L0f0f4048:
/*  f0f4048:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f404c:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f0f4050:	46061100 */ 	add.s	$f4,$f2,$f6
/*  f0f4054:	e6040514 */ 	swc1	$f4,0x514($s0)
/*  f0f4058:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0f405c:	004c082a */ 	slt	$at,$v0,$t4
/*  f0f4060:	5420fff9 */ 	bnezl	$at,.L0f0f4048
/*  f0f4064:	c60a0514 */ 	lwc1	$f10,0x514($s0)
/*  f0f4068:	c60c0540 */ 	lwc1	$f12,0x540($s0)
.L0f0f406c:
/*  f0f406c:	c6080518 */ 	lwc1	$f8,0x518($s0)
/*  f0f4070:	46086032 */ 	c.eq.s	$f12,$f8
/*  f0f4074:	00000000 */ 	nop
/*  f0f4078:	45030013 */ 	bc1tl	.L0f0f40c8
/*  f0f407c:	c60c0544 */ 	lwc1	$f12,0x544($s0)
/*  f0f4080:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0f4084:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f4088:	3c017f1b */ 	lui	$at,%hi(var7f1b2940)
/*  f0f408c:	59e0000e */ 	blezl	$t7,.L0f0f40c8
/*  f0f4090:	c60c0544 */ 	lwc1	$f12,0x544($s0)
/*  f0f4094:	c42a2940 */ 	lwc1	$f10,%lo(var7f1b2940)($at)
/*  f0f4098:	460a6082 */ 	mul.s	$f2,$f12,$f10
/*  f0f409c:	00000000 */ 	nop
/*  f0f40a0:	c6060518 */ 	lwc1	$f6,0x518($s0)
.L0f0f40a4:
/*  f0f40a4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f40a8:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0f40ac:	46041200 */ 	add.s	$f8,$f2,$f4
/*  f0f40b0:	e6080518 */ 	swc1	$f8,0x518($s0)
/*  f0f40b4:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0f40b8:	0058082a */ 	slt	$at,$v0,$t8
/*  f0f40bc:	5420fff9 */ 	bnezl	$at,.L0f0f40a4
/*  f0f40c0:	c6060518 */ 	lwc1	$f6,0x518($s0)
/*  f0f40c4:	c60c0544 */ 	lwc1	$f12,0x544($s0)
.L0f0f40c8:
/*  f0f40c8:	c60e051c */ 	lwc1	$f14,0x51c($s0)
/*  f0f40cc:	460e6032 */ 	c.eq.s	$f12,$f14
/*  f0f40d0:	00000000 */ 	nop
/*  f0f40d4:	45030014 */ 	bc1tl	.L0f0f4128
/*  f0f40d8:	c60a0510 */ 	lwc1	$f10,0x510($s0)
/*  f0f40dc:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f40e0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f40e4:	3c017f1b */ 	lui	$at,%hi(var7f1b2944)
/*  f0f40e8:	5b20000f */ 	blezl	$t9,.L0f0f4128
/*  f0f40ec:	c60a0510 */ 	lwc1	$f10,0x510($s0)
/*  f0f40f0:	c42a2944 */ 	lwc1	$f10,%lo(var7f1b2944)($at)
/*  f0f40f4:	460a6082 */ 	mul.s	$f2,$f12,$f10
/*  f0f40f8:	00000000 */ 	nop
/*  f0f40fc:	c606051c */ 	lwc1	$f6,0x51c($s0)
.L0f0f4100:
/*  f0f4100:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f4104:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0f4108:	46041200 */ 	add.s	$f8,$f2,$f4
/*  f0f410c:	e608051c */ 	swc1	$f8,0x51c($s0)
/*  f0f4110:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f0f4114:	004a082a */ 	slt	$at,$v0,$t2
/*  f0f4118:	5420fff9 */ 	bnezl	$at,.L0f0f4100
/*  f0f411c:	c606051c */ 	lwc1	$f6,0x51c($s0)
/*  f0f4120:	c60e051c */ 	lwc1	$f14,0x51c($s0)
/*  f0f4124:	c60a0510 */ 	lwc1	$f10,0x510($s0)
.L0f0f4128:
/*  f0f4128:	8d6b06c8 */ 	lw	$t3,%lo(g_HiResActive)($t3)
/*  f0f412c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f4130:	e7aa0430 */ 	swc1	$f10,0x430($sp)
/*  f0f4134:	c6120518 */ 	lwc1	$f18,0x518($s0)
/*  f0f4138:	15610004 */ 	bne	$t3,$at,.L0f0f414c
/*  f0f413c:	c6100514 */ 	lwc1	$f16,0x514($s0)
/*  f0f4140:	c7a60430 */ 	lwc1	$f6,0x430($sp)
/*  f0f4144:	46063100 */ 	add.s	$f4,$f6,$f6
/*  f0f4148:	e7a40430 */ 	swc1	$f4,0x430($sp)
.L0f0f414c:
/*  f0f414c:	e7b0042c */ 	swc1	$f16,0x42c($sp)
/*  f0f4150:	e7b20428 */ 	swc1	$f18,0x428($sp)
/*  f0f4154:	e7ae0424 */ 	swc1	$f14,0x424($sp)
/*  f0f4158:	c6020548 */ 	lwc1	$f2,0x548($s0)
/*  f0f415c:	c60c054c */ 	lwc1	$f12,0x54c($s0)
/*  f0f4160:	c6000550 */ 	lwc1	$f0,0x550($s0)
/*  f0f4164:	e6020520 */ 	swc1	$f2,0x520($s0)
/*  f0f4168:	e60c0524 */ 	swc1	$f12,0x524($s0)
/*  f0f416c:	e6000528 */ 	swc1	$f0,0x528($s0)
/*  f0f4170:	e7a20398 */ 	swc1	$f2,0x398($sp)
/*  f0f4174:	e7ac039c */ 	swc1	$f12,0x39c($sp)
/*  f0f4178:	0c005923 */ 	jal	func0001648c
/*  f0f417c:	e7a003a0 */ 	swc1	$f0,0x3a0($sp)
/*  f0f4180:	100000b4 */ 	b	.L0f0f4454
/*  f0f4184:	3c01c2c8 */ 	lui	$at,0xc2c8
.L0f0f4188:
/*  f0f4188:	8e0205b0 */ 	lw	$v0,0x5b0($s0)
/*  f0f418c:	3c01800a */ 	lui	$at,%hi(g_Vars+0x4)
/*  f0f4190:	00027300 */ 	sll	$t6,$v0,0xc
/*  f0f4194:	000e17c2 */ 	srl	$v0,$t6,0x1f
/*  f0f4198:	10400093 */ 	beqz	$v0,.L0f0f43e8
/*  f0f419c:	00000000 */ 	nop
/*  f0f41a0:	c4289fc4 */ 	lwc1	$f8,%lo(g_Vars+0x4)($at)
/*  f0f41a4:	3c014220 */ 	lui	$at,0x4220
/*  f0f41a8:	44815000 */ 	mtc1	$at,$f10
/*  f0f41ac:	c6040564 */ 	lwc1	$f4,0x564($s0)
/*  f0f41b0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f41b4:	460a4183 */ 	div.s	$f6,$f8,$f10
/*  f0f41b8:	44815000 */ 	mtc1	$at,$f10
/*  f0f41bc:	3c017f1b */ 	lui	$at,%hi(var7f1b2948)
/*  f0f41c0:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0f41c4:	e6080564 */ 	swc1	$f8,0x564($s0)
/*  f0f41c8:	c6000564 */ 	lwc1	$f0,0x564($s0)
/*  f0f41cc:	4600503c */ 	c.lt.s	$f10,$f0
/*  f0f41d0:	00000000 */ 	nop
/*  f0f41d4:	45000010 */ 	bc1f	.L0f0f4218
/*  f0f41d8:	00000000 */ 	nop
/*  f0f41dc:	920c05b1 */ 	lbu	$t4,0x5b1($s0)
/*  f0f41e0:	c6040538 */ 	lwc1	$f4,0x538($s0)
/*  f0f41e4:	c606053c */ 	lwc1	$f6,0x53c($s0)
/*  f0f41e8:	318ffff7 */ 	andi	$t7,$t4,0xfff7
/*  f0f41ec:	a20f05b1 */ 	sb	$t7,0x5b1($s0)
/*  f0f41f0:	8e0205b0 */ 	lw	$v0,0x5b0($s0)
/*  f0f41f4:	c6080540 */ 	lwc1	$f8,0x540($s0)
/*  f0f41f8:	c60a0544 */ 	lwc1	$f10,0x544($s0)
/*  f0f41fc:	0002c300 */ 	sll	$t8,$v0,0xc
/*  f0f4200:	001817c2 */ 	srl	$v0,$t8,0x1f
/*  f0f4204:	e6040510 */ 	swc1	$f4,0x510($s0)
/*  f0f4208:	e6060514 */ 	swc1	$f6,0x514($s0)
/*  f0f420c:	e6080518 */ 	swc1	$f8,0x518($s0)
/*  f0f4210:	10000075 */ 	b	.L0f0f43e8
/*  f0f4214:	e60a051c */ 	swc1	$f10,0x51c($s0)
.L0f0f4218:
/*  f0f4218:	c4242948 */ 	lwc1	$f4,%lo(var7f1b2948)($at)
/*  f0f421c:	46040302 */ 	mul.s	$f12,$f0,$f4
/*  f0f4220:	0c0068f4 */ 	jal	cosf
/*  f0f4224:	00000000 */ 	nop
/*  f0f4228:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f422c:	44814000 */ 	mtc1	$at,$f8
/*  f0f4230:	46000187 */ 	neg.s	$f6,$f0
/*  f0f4234:	44812000 */ 	mtc1	$at,$f4
/*  f0f4238:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0f423c:	92020568 */ 	lbu	$v0,0x568($s0)
/*  f0f4240:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f4244:	44813000 */ 	mtc1	$at,$f6
/*  f0f4248:	304a0002 */ 	andi	$t2,$v0,0x2
/*  f0f424c:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f4250:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f4254:	46045080 */ 	add.s	$f2,$f10,$f4
/*  f0f4258:	46001386 */ 	mov.s	$f14,$f2
/*  f0f425c:	11400017 */ 	beqz	$t2,.L0f0f42bc
/*  f0f4260:	46023301 */ 	sub.s	$f12,$f6,$f2
/*  f0f4264:	c6080510 */ 	lwc1	$f8,0x510($s0)
/*  f0f4268:	c6040538 */ 	lwc1	$f4,0x538($s0)
/*  f0f426c:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f0f4270:	00000000 */ 	nop
/*  f0f4274:	46041182 */ 	mul.s	$f6,$f2,$f4
/*  f0f4278:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0f427c:	e7a80430 */ 	swc1	$f8,0x430($sp)
/*  f0f4280:	c6040514 */ 	lwc1	$f4,0x514($s0)
/*  f0f4284:	c606053c */ 	lwc1	$f6,0x53c($s0)
/*  f0f4288:	460c2282 */ 	mul.s	$f10,$f4,$f12
/*  f0f428c:	00000000 */ 	nop
/*  f0f4290:	46061202 */ 	mul.s	$f8,$f2,$f6
/*  f0f4294:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0f4298:	e7a4042c */ 	swc1	$f4,0x42c($sp)
/*  f0f429c:	c6060518 */ 	lwc1	$f6,0x518($s0)
/*  f0f42a0:	c6080540 */ 	lwc1	$f8,0x540($s0)
/*  f0f42a4:	460c3282 */ 	mul.s	$f10,$f6,$f12
/*  f0f42a8:	00000000 */ 	nop
/*  f0f42ac:	46081102 */ 	mul.s	$f4,$f2,$f8
/*  f0f42b0:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0f42b4:	1000000b */ 	b	.L0f0f42e4
/*  f0f42b8:	e7a60428 */ 	swc1	$f6,0x428($sp)
.L0f0f42bc:
/*  f0f42bc:	c6000538 */ 	lwc1	$f0,0x538($s0)
/*  f0f42c0:	e6000510 */ 	swc1	$f0,0x510($s0)
/*  f0f42c4:	e7a00430 */ 	swc1	$f0,0x430($sp)
/*  f0f42c8:	c600053c */ 	lwc1	$f0,0x53c($s0)
/*  f0f42cc:	e6000514 */ 	swc1	$f0,0x514($s0)
/*  f0f42d0:	e7a0042c */ 	swc1	$f0,0x42c($sp)
/*  f0f42d4:	c6000540 */ 	lwc1	$f0,0x540($s0)
/*  f0f42d8:	e6000518 */ 	swc1	$f0,0x518($s0)
/*  f0f42dc:	e7a00428 */ 	swc1	$f0,0x428($sp)
/*  f0f42e0:	92020568 */ 	lbu	$v0,0x568($s0)
.L0f0f42e4:
/*  f0f42e4:	304b0001 */ 	andi	$t3,$v0,0x1
/*  f0f42e8:	5160000a */ 	beqzl	$t3,.L0f0f4314
/*  f0f42ec:	c6000544 */ 	lwc1	$f0,0x544($s0)
/*  f0f42f0:	c608051c */ 	lwc1	$f8,0x51c($s0)
/*  f0f42f4:	c6040544 */ 	lwc1	$f4,0x544($s0)
/*  f0f42f8:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f0f42fc:	00000000 */ 	nop
/*  f0f4300:	46047182 */ 	mul.s	$f6,$f14,$f4
/*  f0f4304:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0f4308:	10000005 */ 	b	.L0f0f4320
/*  f0f430c:	e7a80424 */ 	swc1	$f8,0x424($sp)
/*  f0f4310:	c6000544 */ 	lwc1	$f0,0x544($s0)
.L0f0f4314:
/*  f0f4314:	e600051c */ 	swc1	$f0,0x51c($s0)
/*  f0f4318:	e7a00424 */ 	swc1	$f0,0x424($sp)
/*  f0f431c:	92020568 */ 	lbu	$v0,0x568($s0)
.L0f0f4320:
/*  f0f4320:	304e0004 */ 	andi	$t6,$v0,0x4
/*  f0f4324:	51c00024 */ 	beqzl	$t6,.L0f0f43b8
/*  f0f4328:	c6020548 */ 	lwc1	$f2,0x548($s0)
/*  f0f432c:	c6040520 */ 	lwc1	$f4,0x520($s0)
/*  f0f4330:	27b10290 */ 	addiu	$s1,$sp,0x290
/*  f0f4334:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f4338:	e7a40290 */ 	swc1	$f4,0x290($sp)
/*  f0f433c:	c60a0524 */ 	lwc1	$f10,0x524($s0)
/*  f0f4340:	27a502bc */ 	addiu	$a1,$sp,0x2bc
/*  f0f4344:	e7aa0294 */ 	swc1	$f10,0x294($sp)
/*  f0f4348:	c6060528 */ 	lwc1	$f6,0x528($s0)
/*  f0f434c:	e7ae02d0 */ 	swc1	$f14,0x2d0($sp)
/*  f0f4350:	0fc25b28 */ 	jal	func0f096ca0
/*  f0f4354:	e7a60298 */ 	swc1	$f6,0x298($sp)
/*  f0f4358:	c6080548 */ 	lwc1	$f8,0x548($s0)
/*  f0f435c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f4360:	27a502ac */ 	addiu	$a1,$sp,0x2ac
/*  f0f4364:	e7a80290 */ 	swc1	$f8,0x290($sp)
/*  f0f4368:	c604054c */ 	lwc1	$f4,0x54c($s0)
/*  f0f436c:	e7a40294 */ 	swc1	$f4,0x294($sp)
/*  f0f4370:	c60a0550 */ 	lwc1	$f10,0x550($s0)
/*  f0f4374:	0fc25b28 */ 	jal	func0f096ca0
/*  f0f4378:	e7aa0298 */ 	swc1	$f10,0x298($sp)
/*  f0f437c:	c7ae02d0 */ 	lwc1	$f14,0x2d0($sp)
/*  f0f4380:	27b1029c */ 	addiu	$s1,$sp,0x29c
/*  f0f4384:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f4388:	44067000 */ 	mfc1	$a2,$f14
/*  f0f438c:	27a402bc */ 	addiu	$a0,$sp,0x2bc
/*  f0f4390:	0fc25cae */ 	jal	func0f0972b8
/*  f0f4394:	27a502ac */ 	addiu	$a1,$sp,0x2ac
/*  f0f4398:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f439c:	0fc25bb5 */ 	jal	func0f096ed4
/*  f0f43a0:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f43a4:	8e0205b0 */ 	lw	$v0,0x5b0($s0)
/*  f0f43a8:	00026b00 */ 	sll	$t5,$v0,0xc
/*  f0f43ac:	1000000e */ 	b	.L0f0f43e8
/*  f0f43b0:	000d17c2 */ 	srl	$v0,$t5,0x1f
/*  f0f43b4:	c6020548 */ 	lwc1	$f2,0x548($s0)
.L0f0f43b8:
/*  f0f43b8:	c60c054c */ 	lwc1	$f12,0x54c($s0)
/*  f0f43bc:	c6000550 */ 	lwc1	$f0,0x550($s0)
/*  f0f43c0:	e6020520 */ 	swc1	$f2,0x520($s0)
/*  f0f43c4:	e60c0524 */ 	swc1	$f12,0x524($s0)
/*  f0f43c8:	e6000528 */ 	swc1	$f0,0x528($s0)
/*  f0f43cc:	e7a20398 */ 	swc1	$f2,0x398($sp)
/*  f0f43d0:	e7ac039c */ 	swc1	$f12,0x39c($sp)
/*  f0f43d4:	0c005923 */ 	jal	func0001648c
/*  f0f43d8:	e7a003a0 */ 	swc1	$f0,0x3a0($sp)
/*  f0f43dc:	8e0205b0 */ 	lw	$v0,0x5b0($s0)
/*  f0f43e0:	00027b00 */ 	sll	$t7,$v0,0xc
/*  f0f43e4:	000f17c2 */ 	srl	$v0,$t7,0x1f
.L0f0f43e8:
/*  f0f43e8:	5440001a */ 	bnezl	$v0,.L0f0f4454
/*  f0f43ec:	3c01c2c8 */ 	lui	$at,0xc2c8
/*  f0f43f0:	c6000538 */ 	lwc1	$f0,0x538($s0)
/*  f0f43f4:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f43f8:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f43fc:	e6000510 */ 	swc1	$f0,0x510($s0)
/*  f0f4400:	e7a00430 */ 	swc1	$f0,0x430($sp)
/*  f0f4404:	c600053c */ 	lwc1	$f0,0x53c($s0)
/*  f0f4408:	e6000514 */ 	swc1	$f0,0x514($s0)
/*  f0f440c:	e7a0042c */ 	swc1	$f0,0x42c($sp)
/*  f0f4410:	c6000540 */ 	lwc1	$f0,0x540($s0)
/*  f0f4414:	e6000518 */ 	swc1	$f0,0x518($s0)
/*  f0f4418:	e7a00428 */ 	swc1	$f0,0x428($sp)
/*  f0f441c:	c6000544 */ 	lwc1	$f0,0x544($s0)
/*  f0f4420:	e600051c */ 	swc1	$f0,0x51c($s0)
/*  f0f4424:	e7a00424 */ 	swc1	$f0,0x424($sp)
/*  f0f4428:	c6020548 */ 	lwc1	$f2,0x548($s0)
/*  f0f442c:	c60c054c */ 	lwc1	$f12,0x54c($s0)
/*  f0f4430:	c6000550 */ 	lwc1	$f0,0x550($s0)
/*  f0f4434:	e6020520 */ 	swc1	$f2,0x520($s0)
/*  f0f4438:	e60c0524 */ 	swc1	$f12,0x524($s0)
/*  f0f443c:	e6000528 */ 	swc1	$f0,0x528($s0)
/*  f0f4440:	e7a20398 */ 	swc1	$f2,0x398($sp)
/*  f0f4444:	e7ac039c */ 	swc1	$f12,0x39c($sp)
/*  f0f4448:	0c005923 */ 	jal	func0001648c
/*  f0f444c:	e7a003a0 */ 	swc1	$f0,0x3a0($sp)
.L0f0f4450:
/*  f0f4450:	3c01c2c8 */ 	lui	$at,0xc2c8
.L0f0f4454:
/*  f0f4454:	44813000 */ 	mtc1	$at,$f6
/*  f0f4458:	c7a80428 */ 	lwc1	$f8,0x428($sp)
/*  f0f445c:	8fb90448 */ 	lw	$t9,0x448($sp)
/*  f0f4460:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f4464:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f0f4468:	17210011 */ 	bne	$t9,$at,.L0f0f44b0
/*  f0f446c:	e7a4030c */ 	swc1	$f4,0x30c($sp)
/*  f0f4470:	3c0a8009 */ 	lui	$t2,%hi(g_Is4Mb)
/*  f0f4474:	914a0af0 */ 	lbu	$t2,%lo(g_Is4Mb)($t2)
/*  f0f4478:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f447c:	3c0b8008 */ 	lui	$t3,%hi(g_ScreenWidthMultiplier)
/*  f0f4480:	51410035 */ 	beql	$t2,$at,.L0f0f4558
/*  f0f4484:	27a40390 */ 	addiu	$a0,$sp,0x390
/*  f0f4488:	8d6bfac0 */ 	lw	$t3,%lo(g_ScreenWidthMultiplier)($t3)
/*  f0f448c:	c60a0510 */ 	lwc1	$f10,0x510($s0)
/*  f0f4490:	448b3000 */ 	mtc1	$t3,$f6
/*  f0f4494:	00000000 */ 	nop
/*  f0f4498:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0f449c:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0f44a0:	e7a40390 */ 	swc1	$f4,0x390($sp)
/*  f0f44a4:	c6060514 */ 	lwc1	$f6,0x514($s0)
/*  f0f44a8:	1000002a */ 	b	.L0f0f4554
/*  f0f44ac:	e7a60394 */ 	swc1	$f6,0x394($sp)
.L0f0f44b0:
/*  f0f44b0:	0c002f40 */ 	jal	viGetViewLeft
/*  f0f44b4:	00000000 */ 	nop
/*  f0f44b8:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0f44bc:	00117403 */ 	sra	$t6,$s1,0x10
/*  f0f44c0:	0c002f22 */ 	jal	viGetViewX
/*  f0f44c4:	01c08825 */ 	or	$s1,$t6,$zero
/*  f0f44c8:	44825000 */ 	mtc1	$v0,$f10
/*  f0f44cc:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f44d0:	44812000 */ 	mtc1	$at,$f4
/*  f0f44d4:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f0f44d8:	3c0d8008 */ 	lui	$t5,%hi(g_ScreenWidthMultiplier)
/*  f0f44dc:	8dadfac0 */ 	lw	$t5,%lo(g_ScreenWidthMultiplier)($t5)
/*  f0f44e0:	c7aa0430 */ 	lwc1	$f10,0x430($sp)
/*  f0f44e4:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f0f44e8:	448d4000 */ 	mtc1	$t5,$f8
/*  f0f44ec:	00000000 */ 	nop
/*  f0f44f0:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0f44f4:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f0f44f8:	44915000 */ 	mtc1	$s1,$f10
/*  f0f44fc:	00000000 */ 	nop
/*  f0f4500:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0f4504:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f0f4508:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f0f450c:	0c002f44 */ 	jal	viGetViewTop
/*  f0f4510:	e7a80390 */ 	swc1	$f8,0x390($sp)
/*  f0f4514:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0f4518:	00116403 */ 	sra	$t4,$s1,0x10
/*  f0f451c:	0c002f26 */ 	jal	viGetViewY
/*  f0f4520:	01808825 */ 	or	$s1,$t4,$zero
/*  f0f4524:	44822000 */ 	mtc1	$v0,$f4
/*  f0f4528:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f452c:	44815000 */ 	mtc1	$at,$f10
/*  f0f4530:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0f4534:	c7a4042c */ 	lwc1	$f4,0x42c($sp)
/*  f0f4538:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0f453c:	44913000 */ 	mtc1	$s1,$f6
/*  f0f4540:	00000000 */ 	nop
/*  f0f4544:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0f4548:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0f454c:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0f4550:	e7a40394 */ 	swc1	$f4,0x394($sp)
.L0f0f4554:
/*  f0f4554:	27a40390 */ 	addiu	$a0,$sp,0x390
.L0f0f4558:
/*  f0f4558:	27a50398 */ 	addiu	$a1,$sp,0x398
/*  f0f455c:	0fc2d30f */ 	jal	func0f0b4c3c
/*  f0f4560:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0f4564:	0c00566c */ 	jal	func000159b0
/*  f0f4568:	27a40310 */ 	addiu	$a0,$sp,0x310
/*  f0f456c:	8e0205b4 */ 	lw	$v0,0x5b4($s0)
/*  f0f4570:	5040001d */ 	beqzl	$v0,.L0f0f45e8
/*  f0f4574:	8fb90448 */ 	lw	$t9,0x448($sp)
/*  f0f4578:	90450000 */ 	lbu	$a1,0x0($v0)
/*  f0f457c:	241100ff */ 	addiu	$s1,$zero,0xff
/*  f0f4580:	00401825 */ 	or	$v1,$v0,$zero
/*  f0f4584:	52250018 */ 	beql	$s1,$a1,.L0f0f45e8
/*  f0f4588:	8fb90448 */ 	lw	$t9,0x448($sp)
/*  f0f458c:	8e040054 */ 	lw	$a0,0x54($s0)
.L0f0f4590:
/*  f0f4590:	0c006a47 */ 	jal	modelGetPart
/*  f0f4594:	afa3028c */ 	sw	$v1,0x28c($sp)
/*  f0f4598:	8fa3028c */ 	lw	$v1,0x28c($sp)
/*  f0f459c:	1040000d */ 	beqz	$v0,.L0f0f45d4
/*  f0f45a0:	00402825 */ 	or	$a1,$v0,$zero
/*  f0f45a4:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f45a8:	0c006a87 */ 	jal	modelGetNodeData
/*  f0f45ac:	afa3028c */ 	sw	$v1,0x28c($sp)
/*  f0f45b0:	10400008 */ 	beqz	$v0,.L0f0f45d4
/*  f0f45b4:	8fa3028c */ 	lw	$v1,0x28c($sp)
/*  f0f45b8:	906f0001 */ 	lbu	$t7,0x1($v1)
/*  f0f45bc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f45c0:	51e00004 */ 	beqzl	$t7,.L0f0f45d4
/*  f0f45c4:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f0f45c8:	10000002 */ 	b	.L0f0f45d4
/*  f0f45cc:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0f45d0:	ac400000 */ 	sw	$zero,0x0($v0)
.L0f0f45d4:
/*  f0f45d4:	90650002 */ 	lbu	$a1,0x2($v1)
/*  f0f45d8:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0f45dc:	5625ffec */ 	bnel	$s1,$a1,.L0f0f4590
/*  f0f45e0:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f45e4:	8fb90448 */ 	lw	$t9,0x448($sp)
.L0f0f45e8:
/*  f0f45e8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f45ec:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f45f0:	57210009 */ 	bnel	$t9,$at,.L0f0f4618
/*  f0f45f4:	c7a203a0 */ 	lwc1	$f2,0x3a0($sp)
/*  f0f45f8:	c60a0510 */ 	lwc1	$f10,0x510($s0)
/*  f0f45fc:	e7aa0398 */ 	swc1	$f10,0x398($sp)
/*  f0f4600:	c6080514 */ 	lwc1	$f8,0x514($s0)
/*  f0f4604:	e7a8039c */ 	swc1	$f8,0x39c($sp)
/*  f0f4608:	c6060518 */ 	lwc1	$f6,0x518($s0)
/*  f0f460c:	1000000e */ 	b	.L0f0f4648
/*  f0f4610:	e7a603a0 */ 	swc1	$f6,0x3a0($sp)
/*  f0f4614:	c7a203a0 */ 	lwc1	$f2,0x3a0($sp)
.L0f0f4618:
/*  f0f4618:	c7a4030c */ 	lwc1	$f4,0x30c($sp)
/*  f0f461c:	c7aa0398 */ 	lwc1	$f10,0x398($sp)
/*  f0f4620:	c7a6039c */ 	lwc1	$f6,0x39c($sp)
/*  f0f4624:	46022003 */ 	div.s	$f0,$f4,$f2
/*  f0f4628:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0f462c:	00000000 */ 	nop
/*  f0f4630:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0f4634:	00000000 */ 	nop
/*  f0f4638:	46020082 */ 	mul.s	$f2,$f0,$f2
/*  f0f463c:	e7a80398 */ 	swc1	$f8,0x398($sp)
/*  f0f4640:	e7a4039c */ 	swc1	$f4,0x39c($sp)
/*  f0f4644:	e7a203a0 */ 	swc1	$f2,0x3a0($sp)
.L0f0f4648:
/*  f0f4648:	0c0059b7 */ 	jal	func000166dc
/*  f0f464c:	27a50310 */ 	addiu	$a1,$sp,0x310
/*  f0f4650:	8faa0308 */ 	lw	$t2,0x308($sp)
/*  f0f4654:	5140000a */ 	beqzl	$t2,.L0f0f4680
/*  f0f4658:	c7ac0424 */ 	lwc1	$f12,0x424($sp)
/*  f0f465c:	c7aa0424 */ 	lwc1	$f10,0x424($sp)
/*  f0f4660:	c7a802f8 */ 	lwc1	$f8,0x2f8($sp)
/*  f0f4664:	27a50310 */ 	addiu	$a1,$sp,0x310
/*  f0f4668:	46085302 */ 	mul.s	$f12,$f10,$f8
/*  f0f466c:	0c0057c1 */ 	jal	func00015f04
/*  f0f4670:	00000000 */ 	nop
/*  f0f4674:	10000005 */ 	b	.L0f0f468c
/*  f0f4678:	8fab0308 */ 	lw	$t3,0x308($sp)
/*  f0f467c:	c7ac0424 */ 	lwc1	$f12,0x424($sp)
.L0f0f4680:
/*  f0f4680:	0c0057c1 */ 	jal	func00015f04
/*  f0f4684:	27a50310 */ 	addiu	$a1,$sp,0x310
/*  f0f4688:	8fab0308 */ 	lw	$t3,0x308($sp)
.L0f0f468c:
/*  f0f468c:	11600005 */ 	beqz	$t3,.L0f0f46a4
/*  f0f4690:	27a402fc */ 	addiu	$a0,$sp,0x2fc
/*  f0f4694:	0c0059b7 */ 	jal	func000166dc
/*  f0f4698:	27a50204 */ 	addiu	$a1,$sp,0x204
/*  f0f469c:	1000000b */ 	b	.L0f0f46cc
/*  f0f46a0:	27b10244 */ 	addiu	$s1,$sp,0x244
.L0f0f46a4:
/*  f0f46a4:	c606052c */ 	lwc1	$f6,0x52c($s0)
/*  f0f46a8:	27a40398 */ 	addiu	$a0,$sp,0x398
/*  f0f46ac:	27a50204 */ 	addiu	$a1,$sp,0x204
/*  f0f46b0:	e7a60398 */ 	swc1	$f6,0x398($sp)
/*  f0f46b4:	c6040530 */ 	lwc1	$f4,0x530($s0)
/*  f0f46b8:	e7a4039c */ 	swc1	$f4,0x39c($sp)
/*  f0f46bc:	c60a0534 */ 	lwc1	$f10,0x534($s0)
/*  f0f46c0:	0c0059b7 */ 	jal	func000166dc
/*  f0f46c4:	e7aa03a0 */ 	swc1	$f10,0x3a0($sp)
/*  f0f46c8:	27b10244 */ 	addiu	$s1,$sp,0x244
.L0f0f46cc:
/*  f0f46cc:	02203025 */ 	or	$a2,$s1,$zero
/*  f0f46d0:	27a40310 */ 	addiu	$a0,$sp,0x310
/*  f0f46d4:	0c005680 */ 	jal	func00015a00
/*  f0f46d8:	27a50350 */ 	addiu	$a1,$sp,0x350
/*  f0f46dc:	8fae0448 */ 	lw	$t6,0x448($sp)
/*  f0f46e0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f46e4:	55c1000f */ 	bnel	$t6,$at,.L0f0f4724
/*  f0f46e8:	26060014 */ 	addiu	$a2,$s0,0x14
/*  f0f46ec:	0fc4eb81 */ 	jal	func0f13ae04
/*  f0f46f0:	27a401c4 */ 	addiu	$a0,$sp,0x1c4
/*  f0f46f4:	27a401c4 */ 	addiu	$a0,$sp,0x1c4
/*  f0f46f8:	02202825 */ 	or	$a1,$s1,$zero
/*  f0f46fc:	0c005680 */ 	jal	func00015a00
/*  f0f4700:	27a60184 */ 	addiu	$a2,$sp,0x184
/*  f0f4704:	26060014 */ 	addiu	$a2,$s0,0x14
/*  f0f4708:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0f470c:	27a40184 */ 	addiu	$a0,$sp,0x184
/*  f0f4710:	0c005680 */ 	jal	func00015a00
/*  f0f4714:	27a50204 */ 	addiu	$a1,$sp,0x204
/*  f0f4718:	10000006 */ 	b	.L0f0f4734
/*  f0f471c:	00000000 */ 	nop
/*  f0f4720:	26060014 */ 	addiu	$a2,$s0,0x14
.L0f0f4724:
/*  f0f4724:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0f4728:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f472c:	0c005680 */ 	jal	func00015a00
/*  f0f4730:	27a50204 */ 	addiu	$a1,$sp,0x204
.L0f0f4734:
/*  f0f4734:	0fc388d2 */ 	jal	func0f0e2348
/*  f0f4738:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f473c:	8fad0448 */ 	lw	$t5,0x448($sp)
/*  f0f4740:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f4744:	29a10003 */ 	slti	$at,$t5,0x3
/*  f0f4748:	5020006f */ 	beqzl	$at,.L0f0f4908
/*  f0f474c:	8e0a0054 */ 	lw	$t2,0x54($s0)
/*  f0f4750:	11a0000e */ 	beqz	$t5,.L0f0f478c
/*  f0f4754:	3c11800a */ 	lui	$s1,%hi(g_Menus+0x2004)
/*  f0f4758:	0fc35272 */ 	jal	func0f0d49c8
/*  f0f475c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f4760:	244c0008 */ 	addiu	$t4,$v0,0x8
/*  f0f4764:	3c0f0103 */ 	lui	$t7,0x103
/*  f0f4768:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f0f476c:	afac0440 */ 	sw	$t4,0x440($sp)
/*  f0f4770:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0f4774:	0fc2d3fa */ 	jal	currentPlayerGetUnk1750
/*  f0f4778:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f477c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0f4780:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f4784:	1000005f */ 	b	.L0f0f4904
/*  f0f4788:	ae220004 */ 	sw	$v0,%lo(g_Menus+0x2004)($s1)
.L0f0f478c:
/*  f0f478c:	26312038 */ 	addiu	$s1,$s1,8248
/*  f0f4790:	3c18800a */ 	lui	$t8,%hi(var800a203c)
/*  f0f4794:	3c0b800a */ 	lui	$t3,%hi(var800a2044)
/*  f0f4798:	3c0e800a */ 	lui	$t6,%hi(var800a2040)
/*  f0f479c:	8dce2040 */ 	lw	$t6,%lo(var800a2040)($t6)
/*  f0f47a0:	8d6b2044 */ 	lw	$t3,%lo(var800a2044)($t3)
/*  f0f47a4:	8f18203c */ 	lw	$t8,%lo(var800a203c)($t8)
/*  f0f47a8:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f0f47ac:	016e6823 */ 	subu	$t5,$t3,$t6
/*  f0f47b0:	448d2000 */ 	mtc1	$t5,$f4
/*  f0f47b4:	03195023 */ 	subu	$t2,$t8,$t9
/*  f0f47b8:	448a4000 */ 	mtc1	$t2,$f8
/*  f0f47bc:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0f47c0:	3c047f1b */ 	lui	$a0,%hi(var7f1b25f0)
/*  f0f47c4:	3c058007 */ 	lui	$a1,%hi(var800714c0)
/*  f0f47c8:	24a514c0 */ 	addiu	$a1,$a1,%lo(var800714c0)
/*  f0f47cc:	248425f0 */ 	addiu	$a0,$a0,%lo(var7f1b25f0)
/*  f0f47d0:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0f47d4:	460a3203 */ 	div.s	$f8,$f6,$f10
/*  f0f47d8:	0c0036cc */ 	jal	func0000db30
/*  f0f47dc:	e7a8017c */ 	swc1	$f8,0x17c($sp)
/*  f0f47e0:	3c047f1b */ 	lui	$a0,%hi(var7f1b25f4)
/*  f0f47e4:	3c058007 */ 	lui	$a1,%hi(var800714c4)
/*  f0f47e8:	24a514c4 */ 	addiu	$a1,$a1,%lo(var800714c4)
/*  f0f47ec:	0c0036cc */ 	jal	func0000db30
/*  f0f47f0:	248425f4 */ 	addiu	$a0,$a0,%lo(var7f1b25f4)
/*  f0f47f4:	0fc35272 */ 	jal	func0f0d49c8
/*  f0f47f8:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f47fc:	3c0f8008 */ 	lui	$t7,%hi(g_ScreenWidthMultiplier)
/*  f0f4800:	8deffac0 */ 	lw	$t7,%lo(g_ScreenWidthMultiplier)($t7)
/*  f0f4804:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f0f4808:	3c05800a */ 	lui	$a1,%hi(var800a2040+0x2)
/*  f0f480c:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f4810:	018f0019 */ 	multu	$t4,$t7
/*  f0f4814:	84a52042 */ 	lh	$a1,%lo(var800a2040+0x2)($a1)
/*  f0f4818:	00002012 */ 	mflo	$a0
/*  f0f481c:	0004c400 */ 	sll	$t8,$a0,0x10
/*  f0f4820:	0c002f2a */ 	jal	viSetViewPosition
/*  f0f4824:	00182403 */ 	sra	$a0,$t8,0x10
/*  f0f4828:	3c0b800a */ 	lui	$t3,%hi(var800a203c)
/*  f0f482c:	8d6b203c */ 	lw	$t3,%lo(var800a203c)($t3)
/*  f0f4830:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0f4834:	3c0c8008 */ 	lui	$t4,%hi(g_ScreenWidthMultiplier)
/*  f0f4838:	8d8cfac0 */ 	lw	$t4,%lo(g_ScreenWidthMultiplier)($t4)
/*  f0f483c:	016e6823 */ 	subu	$t5,$t3,$t6
/*  f0f4840:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x284)
/*  f0f4844:	01ac0019 */ 	multu	$t5,$t4
/*  f0f4848:	8d4aa244 */ 	lw	$t2,%lo(g_Vars+0x284)($t2)
/*  f0f484c:	3c19800a */ 	lui	$t9,%hi(var800a2044)
/*  f0f4850:	8f392044 */ 	lw	$t9,%lo(var800a2044)($t9)
/*  f0f4854:	c54c1854 */ 	lwc1	$f12,0x1854($t2)
/*  f0f4858:	3c0a800a */ 	lui	$t2,%hi(var800a2040)
/*  f0f485c:	8d4a2040 */ 	lw	$t2,%lo(var800a2040)($t2)
/*  f0f4860:	c7ae017c */ 	lwc1	$f14,0x17c($sp)
/*  f0f4864:	032a3823 */ 	subu	$a3,$t9,$t2
/*  f0f4868:	00003012 */ 	mflo	$a2
/*  f0f486c:	00067c00 */ 	sll	$t7,$a2,0x10
/*  f0f4870:	00075c00 */ 	sll	$t3,$a3,0x10
/*  f0f4874:	000b3c03 */ 	sra	$a3,$t3,0x10
/*  f0f4878:	0c002f76 */ 	jal	viSetFovAspectAndSize
/*  f0f487c:	000f3403 */ 	sra	$a2,$t7,0x10
/*  f0f4880:	3c0d8007 */ 	lui	$t5,%hi(g_MpPlayerNum)
/*  f0f4884:	8dad1448 */ 	lw	$t5,%lo(g_MpPlayerNum)($t5)
/*  f0f4888:	3c0f800a */ 	lui	$t7,%hi(var800a2048)
/*  f0f488c:	25ef2048 */ 	addiu	$t7,$t7,%lo(var800a2048)
/*  f0f4890:	000d6140 */ 	sll	$t4,$t5,0x5
/*  f0f4894:	018f2821 */ 	addu	$a1,$t4,$t7
/*  f0f4898:	0c002bc0 */ 	jal	func0000af00
/*  f0f489c:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f48a0:	3c188007 */ 	lui	$t8,%hi(var800714c0)
/*  f0f48a4:	8f1814c0 */ 	lw	$t8,%lo(var800714c0)($t8)
/*  f0f48a8:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f48ac:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f48b0:	44982000 */ 	mtc1	$t8,$f4
/*  f0f48b4:	3c198007 */ 	lui	$t9,%hi(var800714c4)
/*  f0f48b8:	07010005 */ 	bgez	$t8,.L0f0f48d0
/*  f0f48bc:	46802120 */ 	cvt.s.w	$f4,$f4
/*  f0f48c0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0f48c4:	44813000 */ 	mtc1	$at,$f6
/*  f0f48c8:	00000000 */ 	nop
/*  f0f48cc:	46062100 */ 	add.s	$f4,$f4,$f6
.L0f0f48d0:
/*  f0f48d0:	8f3914c4 */ 	lw	$t9,%lo(var800714c4)($t9)
/*  f0f48d4:	44052000 */ 	mfc1	$a1,$f4
/*  f0f48d8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0f48dc:	44995000 */ 	mtc1	$t9,$f10
/*  f0f48e0:	07210004 */ 	bgez	$t9,.L0f0f48f4
/*  f0f48e4:	468052a0 */ 	cvt.s.w	$f10,$f10
/*  f0f48e8:	44814000 */ 	mtc1	$at,$f8
/*  f0f48ec:	00000000 */ 	nop
/*  f0f48f0:	46085280 */ 	add.s	$f10,$f10,$f8
.L0f0f48f4:
/*  f0f48f4:	44065000 */ 	mfc1	$a2,$f10
/*  f0f48f8:	0c002b29 */ 	jal	func0000aca4
/*  f0f48fc:	00000000 */ 	nop
/*  f0f4900:	afa20440 */ 	sw	$v0,0x440($sp)
.L0f0f4904:
/*  f0f4904:	8e0a0054 */ 	lw	$t2,0x54($s0)
.L0f0f4908:
/*  f0f4908:	8544000e */ 	lh	$a0,0xe($t2)
/*  f0f490c:	00045980 */ 	sll	$t3,$a0,0x6
/*  f0f4910:	0fc59e7d */ 	jal	func0f1679f4
/*  f0f4914:	01602025 */ 	or	$a0,$t3,$zero
/*  f0f4918:	afa203b4 */ 	sw	$v0,0x3b4($sp)
/*  f0f491c:	8e0e0054 */ 	lw	$t6,0x54($s0)
/*  f0f4920:	00008825 */ 	or	$s1,$zero,$zero
/*  f0f4924:	85cd000e */ 	lh	$t5,0xe($t6)
/*  f0f4928:	59a0000d */ 	blezl	$t5,.L0f0f4960
/*  f0f492c:	8605005c */ 	lh	$a1,0x5c($s0)
/*  f0f4930:	8faf03b4 */ 	lw	$t7,0x3b4($sp)
.L0f0f4934:
/*  f0f4934:	00116180 */ 	sll	$t4,$s1,0x6
/*  f0f4938:	0c00566c */ 	jal	func000159b0
/*  f0f493c:	018f2021 */ 	addu	$a0,$t4,$t7
/*  f0f4940:	8e180054 */ 	lw	$t8,0x54($s0)
/*  f0f4944:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0f4948:	8719000e */ 	lh	$t9,0xe($t8)
/*  f0f494c:	0239082a */ 	slt	$at,$s1,$t9
/*  f0f4950:	5420fff8 */ 	bnezl	$at,.L0f0f4934
/*  f0f4954:	8faf03b4 */ 	lw	$t7,0x3b4($sp)
/*  f0f4958:	00008825 */ 	or	$s1,$zero,$zero
/*  f0f495c:	8605005c */ 	lh	$a1,0x5c($s0)
.L0f0f4960:
/*  f0f4960:	8faa03b4 */ 	lw	$t2,0x3b4($sp)
/*  f0f4964:	10a00025 */ 	beqz	$a1,.L0f0f49fc
/*  f0f4968:	ae0a006c */ 	sw	$t2,0x6c($s0)
/*  f0f496c:	860b005e */ 	lh	$t3,0x5e($s0)
/*  f0f4970:	50ab0023 */ 	beql	$a1,$t3,.L0f0f4a00
/*  f0f4974:	8618005e */ 	lh	$t8,0x5e($s0)
/*  f0f4978:	8e0e05b0 */ 	lw	$t6,0x5b0($s0)
/*  f0f497c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4980:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f4984:	000e62c0 */ 	sll	$t4,$t6,0xb
/*  f0f4988:	05810014 */ 	bgez	$t4,.L0f0f49dc
/*  f0f498c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f4990:	3c01bf00 */ 	lui	$at,0xbf00
/*  f0f4994:	44812000 */ 	mtc1	$at,$f4
/*  f0f4998:	44803000 */ 	mtc1	$zero,$f6
/*  f0f499c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f49a0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f49a4:	24070000 */ 	addiu	$a3,$zero,0x0
/*  f0f49a8:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0f49ac:	0c007733 */ 	jal	modelSetAnimation
/*  f0f49b0:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f0f49b4:	0c007486 */ 	jal	modelGetNumAnimFrames
/*  f0f49b8:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f49bc:	44825000 */ 	mtc1	$v0,$f10
/*  f0f49c0:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f49c4:	468052a0 */ 	cvt.s.w	$f10,$f10
/*  f0f49c8:	44055000 */ 	mfc1	$a1,$f10
/*  f0f49cc:	0c007806 */ 	jal	func0001e018
/*  f0f49d0:	00000000 */ 	nop
/*  f0f49d4:	10000008 */ 	b	.L0f0f49f8
/*  f0f49d8:	860f005c */ 	lh	$t7,0x5c($s0)
.L0f0f49dc:
/*  f0f49dc:	44814000 */ 	mtc1	$at,$f8
/*  f0f49e0:	44802000 */ 	mtc1	$zero,$f4
/*  f0f49e4:	24070000 */ 	addiu	$a3,$zero,0x0
/*  f0f49e8:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0f49ec:	0c007733 */ 	jal	modelSetAnimation
/*  f0f49f0:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f0f49f4:	860f005c */ 	lh	$t7,0x5c($s0)
.L0f0f49f8:
/*  f0f49f8:	a60f005e */ 	sh	$t7,0x5e($s0)
.L0f0f49fc:
/*  f0f49fc:	8618005e */ 	lh	$t8,0x5e($s0)
.L0f0f4a00:
/*  f0f4a00:	a600005c */ 	sh	$zero,0x5c($s0)
/*  f0f4a04:	13000023 */ 	beqz	$t8,.L0f0f4a94
/*  f0f4a08:	3c05800a */ 	lui	$a1,%hi(g_Vars+0x40)
/*  f0f4a0c:	8ca5a000 */ 	lw	$a1,%lo(g_Vars+0x40)($a1)
/*  f0f4a10:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4a14:	0c007b86 */ 	jal	func0001ee18
/*  f0f4a18:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0f4a1c:	8e1905b0 */ 	lw	$t9,0x5b0($s0)
/*  f0f4a20:	00195ac0 */ 	sll	$t3,$t9,0xb
/*  f0f4a24:	0561000c */ 	bgez	$t3,.L0f0f4a58
/*  f0f4a28:	00000000 */ 	nop
/*  f0f4a2c:	0c007486 */ 	jal	modelGetNumAnimFrames
/*  f0f4a30:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4a34:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0f4a38:	0c00745f */ 	jal	modelGetCurAnimFrame
/*  f0f4a3c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4a40:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f0f4a44:	448e3000 */ 	mtc1	$t6,$f6
/*  f0f4a48:	00000000 */ 	nop
/*  f0f4a4c:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0f4a50:	10000004 */ 	b	.L0f0f4a64
/*  f0f4a54:	46005081 */ 	sub.s	$f2,$f10,$f0
.L0f0f4a58:
/*  f0f4a58:	0c00745f */ 	jal	modelGetCurAnimFrame
/*  f0f4a5c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4a60:	46000086 */ 	mov.s	$f2,$f0
.L0f0f4a64:
/*  f0f4a64:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0f4a68:	0c007486 */ 	jal	modelGetNumAnimFrames
/*  f0f4a6c:	e7a20178 */ 	swc1	$f2,0x178($sp)
/*  f0f4a70:	244dffff */ 	addiu	$t5,$v0,-1
/*  f0f4a74:	448d4000 */ 	mtc1	$t5,$f8
/*  f0f4a78:	c7a20178 */ 	lwc1	$f2,0x178($sp)
/*  f0f4a7c:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0f4a80:	4602203e */ 	c.le.s	$f4,$f2
/*  f0f4a84:	00000000 */ 	nop
/*  f0f4a88:	45020003 */ 	bc1fl	.L0f0f4a98
/*  f0f4a8c:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0f4a90:	a600005e */ 	sh	$zero,0x5e($s0)
.L0f0f4a94:
/*  f0f4a94:	8fa40040 */ 	lw	$a0,0x40($sp)
.L0f0f4a98:
/*  f0f4a98:	0c005746 */ 	jal	func00015d18
/*  f0f4a9c:	8fa503b4 */ 	lw	$a1,0x3b4($sp)
/*  f0f4aa0:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f0f4aa4:	27a403b8 */ 	addiu	$a0,$sp,0x3b8
/*  f0f4aa8:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f0f4aac:	afac03b8 */ 	sw	$t4,0x3b8($sp)
/*  f0f4ab0:	8e0f006c */ 	lw	$t7,0x6c($s0)
/*  f0f4ab4:	0c0073af */ 	jal	func0001cebc
/*  f0f4ab8:	afaf03c8 */ 	sw	$t7,0x3c8($sp)
/*  f0f4abc:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f4ac0:	3c188008 */ 	lui	$t8,%hi(stagethinglist_22c54)
/*  f0f4ac4:	2718cc34 */ 	addiu	$t8,$t8,%lo(stagethinglist_22c54)
/*  f0f4ac8:	8c990004 */ 	lw	$t9,0x4($a0)
/*  f0f4acc:	57190092 */ 	bnel	$t8,$t9,.L0f0f4d18
/*  f0f4ad0:	8fb80440 */ 	lw	$t8,0x440($sp)
/*  f0f4ad4:	0c006a47 */ 	jal	modelGetPart
/*  f0f4ad8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f4adc:	5040002e */ 	beqzl	$v0,.L0f0f4b98
/*  f0f4ae0:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f4ae4:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f0f4ae8:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0f4aec:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0f4af0:	84aa0010 */ 	lh	$t2,0x10($a1)
/*  f0f4af4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f4af8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f4afc:	19400025 */ 	blez	$t2,.L0f0f4b94
/*  f0f4b00:	24080064 */ 	addiu	$t0,$zero,0x64
/*  f0f4b04:	8d2d0000 */ 	lw	$t5,0x0($t1)
.L0f0f4b08:
/*  f0f4b08:	8cab000c */ 	lw	$t3,0xc($a1)
/*  f0f4b0c:	01a80019 */ 	multu	$t5,$t0
/*  f0f4b10:	01661021 */ 	addu	$v0,$t3,$a2
/*  f0f4b14:	844e0008 */ 	lh	$t6,0x8($v0)
/*  f0f4b18:	00006012 */ 	mflo	$t4
/*  f0f4b1c:	01cc7823 */ 	subu	$t7,$t6,$t4
/*  f0f4b20:	a44f0008 */ 	sh	$t7,0x8($v0)
/*  f0f4b24:	8cb8000c */ 	lw	$t8,0xc($a1)
/*  f0f4b28:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f0f4b2c:	872a0008 */ 	lh	$t2,0x8($t9)
/*  f0f4b30:	2941a000 */ 	slti	$at,$t2,-24576
/*  f0f4b34:	50200012 */ 	beqzl	$at,.L0f0f4b80
/*  f0f4b38:	84b80010 */ 	lh	$t8,0x10($a1)
/*  f0f4b3c:	84ab0010 */ 	lh	$t3,0x10($a1)
/*  f0f4b40:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f4b44:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f4b48:	5960000d */ 	blezl	$t3,.L0f0f4b80
/*  f0f4b4c:	84b80010 */ 	lh	$t8,0x10($a1)
/*  f0f4b50:	8cad000c */ 	lw	$t5,0xc($a1)
.L0f0f4b54:
/*  f0f4b54:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0f4b58:	01a41021 */ 	addu	$v0,$t5,$a0
/*  f0f4b5c:	844e0008 */ 	lh	$t6,0x8($v0)
/*  f0f4b60:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f0f4b64:	25cc2000 */ 	addiu	$t4,$t6,0x2000
/*  f0f4b68:	a44c0008 */ 	sh	$t4,0x8($v0)
/*  f0f4b6c:	84af0010 */ 	lh	$t7,0x10($a1)
/*  f0f4b70:	006f082a */ 	slt	$at,$v1,$t7
/*  f0f4b74:	5420fff7 */ 	bnezl	$at,.L0f0f4b54
/*  f0f4b78:	8cad000c */ 	lw	$t5,0xc($a1)
/*  f0f4b7c:	84b80010 */ 	lh	$t8,0x10($a1)
.L0f0f4b80:
/*  f0f4b80:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f0f4b84:	24c6000c */ 	addiu	$a2,$a2,0xc
/*  f0f4b88:	00f8082a */ 	slt	$at,$a3,$t8
/*  f0f4b8c:	5420ffde */ 	bnezl	$at,.L0f0f4b08
/*  f0f4b90:	8d2d0000 */ 	lw	$t5,0x0($t1)
.L0f0f4b94:
/*  f0f4b94:	8e040054 */ 	lw	$a0,0x54($s0)
.L0f0f4b98:
/*  f0f4b98:	0c006a47 */ 	jal	modelGetPart
/*  f0f4b9c:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f0f4ba0:	10400019 */ 	beqz	$v0,.L0f0f4c08
/*  f0f4ba4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f4ba8:	0c006949 */ 	jal	func0001a524
/*  f0f4bac:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f4bb0:	afa20160 */ 	sw	$v0,0x160($sp)
/*  f0f4bb4:	0c00566c */ 	jal	func000159b0
/*  f0f4bb8:	27a40120 */ 	addiu	$a0,$sp,0x120
/*  f0f4bbc:	3c014080 */ 	lui	$at,0x4080
/*  f0f4bc0:	44816000 */ 	mtc1	$at,$f12
/*  f0f4bc4:	0fc01ad5 */ 	jal	func0f006b54
/*  f0f4bc8:	00000000 */ 	nop
/*  f0f4bcc:	46000306 */ 	mov.s	$f12,$f0
/*  f0f4bd0:	0c0058ba */ 	jal	func000162e8
/*  f0f4bd4:	27a50120 */ 	addiu	$a1,$sp,0x120
/*  f0f4bd8:	8faa0160 */ 	lw	$t2,0x160($sp)
/*  f0f4bdc:	8fb903b4 */ 	lw	$t9,0x3b4($sp)
/*  f0f4be0:	27a50120 */ 	addiu	$a1,$sp,0x120
/*  f0f4be4:	000a5980 */ 	sll	$t3,$t2,0x6
/*  f0f4be8:	032b3821 */ 	addu	$a3,$t9,$t3
/*  f0f4bec:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0f4bf0:	afa70040 */ 	sw	$a3,0x40($sp)
/*  f0f4bf4:	0c005680 */ 	jal	func00015a00
/*  f0f4bf8:	27a600e0 */ 	addiu	$a2,$sp,0xe0
/*  f0f4bfc:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f0f4c00:	0c005746 */ 	jal	func00015d18
/*  f0f4c04:	27a400e0 */ 	addiu	$a0,$sp,0xe0
.L0f0f4c08:
/*  f0f4c08:	8e040054 */ 	lw	$a0,0x54($s0)
/*  f0f4c0c:	0c006a47 */ 	jal	modelGetPart
/*  f0f4c10:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0f4c14:	1040003f */ 	beqz	$v0,.L0f0f4d14
/*  f0f4c18:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f4c1c:	3c02800a */ 	lui	$v0,%hi(g_MenuData+0x4)
/*  f0f4c20:	8c4219c4 */ 	lw	$v0,%lo(g_MenuData+0x4)($v0)
/*  f0f4c24:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f4c28:	10410007 */ 	beq	$v0,$at,.L0f0f4c48
/*  f0f4c2c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0f4c30:	10410005 */ 	beq	$v0,$at,.L0f0f4c48
/*  f0f4c34:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f4c38:	10410003 */ 	beq	$v0,$at,.L0f0f4c48
/*  f0f4c3c:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0f4c40:	54410035 */ 	bnel	$v0,$at,.L0f0f4d18
/*  f0f4c44:	8fb80440 */ 	lw	$t8,0x440($sp)
.L0f0f4c48:
/*  f0f4c48:	0c006949 */ 	jal	func0001a524
/*  f0f4c4c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f4c50:	8fad03b4 */ 	lw	$t5,0x3b4($sp)
/*  f0f4c54:	00027180 */ 	sll	$t6,$v0,0x6
/*  f0f4c58:	27a400d0 */ 	addiu	$a0,$sp,0xd0
/*  f0f4c5c:	01ae1821 */ 	addu	$v1,$t5,$t6
/*  f0f4c60:	c4660030 */ 	lwc1	$f6,0x30($v1)
/*  f0f4c64:	27a500c8 */ 	addiu	$a1,$sp,0xc8
/*  f0f4c68:	e7a600d0 */ 	swc1	$f6,0xd0($sp)
/*  f0f4c6c:	c46a0034 */ 	lwc1	$f10,0x34($v1)
/*  f0f4c70:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0f4c74:	c4680038 */ 	lwc1	$f8,0x38($v1)
/*  f0f4c78:	0fc2d341 */ 	jal	func0f0b4d04
/*  f0f4c7c:	e7a800d8 */ 	swc1	$f8,0xd8($sp)
/*  f0f4c80:	0c002f02 */ 	jal	viGetX
/*  f0f4c84:	00000000 */ 	nop
/*  f0f4c88:	c7a400c8 */ 	lwc1	$f4,0xc8($sp)
/*  f0f4c8c:	3c198008 */ 	lui	$t9,%hi(g_ScreenWidthMultiplier)
/*  f0f4c90:	8f39fac0 */ 	lw	$t9,%lo(g_ScreenWidthMultiplier)($t9)
/*  f0f4c94:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0f4c98:	440f3000 */ 	mfc1	$t7,$f6
/*  f0f4c9c:	04410003 */ 	bgez	$v0,.L0f0f4cac
/*  f0f4ca0:	0002c043 */ 	sra	$t8,$v0,0x1
/*  f0f4ca4:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0f4ca8:	0001c043 */ 	sra	$t8,$at,0x1
.L0f0f4cac:
/*  f0f4cac:	01f85023 */ 	subu	$t2,$t7,$t8
/*  f0f4cb0:	0159001a */ 	div	$zero,$t2,$t9
/*  f0f4cb4:	17200002 */ 	bnez	$t9,.L0f0f4cc0
/*  f0f4cb8:	00000000 */ 	nop
/*  f0f4cbc:	0007000d */ 	break	0x7
.L0f0f4cc0:
/*  f0f4cc0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f4cc4:	17210004 */ 	bne	$t9,$at,.L0f0f4cd8
/*  f0f4cc8:	3c018000 */ 	lui	$at,0x8000
/*  f0f4ccc:	15410002 */ 	bne	$t2,$at,.L0f0f4cd8
/*  f0f4cd0:	00000000 */ 	nop
/*  f0f4cd4:	0006000d */ 	break	0x6
.L0f0f4cd8:
/*  f0f4cd8:	3c01800a */ 	lui	$at,%hi(var8009de98)
/*  f0f4cdc:	00005812 */ 	mflo	$t3
/*  f0f4ce0:	ac2bde98 */ 	sw	$t3,%lo(var8009de98)($at)
/*  f0f4ce4:	0c002f06 */ 	jal	viGetY
/*  f0f4ce8:	00000000 */ 	nop
/*  f0f4cec:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0f4cf0:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f0f4cf4:	440e4000 */ 	mfc1	$t6,$f8
/*  f0f4cf8:	04410003 */ 	bgez	$v0,.L0f0f4d08
/*  f0f4cfc:	00026043 */ 	sra	$t4,$v0,0x1
/*  f0f4d00:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0f4d04:	00016043 */ 	sra	$t4,$at,0x1
.L0f0f4d08:
/*  f0f4d08:	3c01800a */ 	lui	$at,%hi(var8009de9c)
/*  f0f4d0c:	01cc7823 */ 	subu	$t7,$t6,$t4
/*  f0f4d10:	ac2fde9c */ 	sw	$t7,%lo(var8009de9c)($at)
.L0f0f4d14:
/*  f0f4d14:	8fb80440 */ 	lw	$t8,0x440($sp)
.L0f0f4d18:
/*  f0f4d18:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f0f4d1c:	3c0b8000 */ 	lui	$t3,0x8000
/*  f0f4d20:	270a0008 */ 	addiu	$t2,$t8,0x8
/*  f0f4d24:	afaa0440 */ 	sw	$t2,0x440($sp)
/*  f0f4d28:	356b0040 */ 	ori	$t3,$t3,0x40
/*  f0f4d2c:	37390002 */ 	ori	$t9,$t9,0x2
/*  f0f4d30:	af190000 */ 	sw	$t9,0x0($t8)
/*  f0f4d34:	af0b0004 */ 	sw	$t3,0x4($t8)
/*  f0f4d38:	8fad0440 */ 	lw	$t5,0x440($sp)
/*  f0f4d3c:	3c0c0386 */ 	lui	$t4,0x386
/*  f0f4d40:	3c0f8007 */ 	lui	$t7,%hi(var80071470)
/*  f0f4d44:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0f4d48:	afae0440 */ 	sw	$t6,0x440($sp)
/*  f0f4d4c:	25ef1470 */ 	addiu	$t7,$t7,%lo(var80071470)
/*  f0f4d50:	358c0010 */ 	ori	$t4,$t4,0x10
/*  f0f4d54:	adac0000 */ 	sw	$t4,0x0($t5)
/*  f0f4d58:	adaf0004 */ 	sw	$t7,0x4($t5)
/*  f0f4d5c:	8fb80440 */ 	lw	$t8,0x440($sp)
/*  f0f4d60:	3c0b8007 */ 	lui	$t3,%hi(var80071468)
/*  f0f4d64:	3c190388 */ 	lui	$t9,0x388
/*  f0f4d68:	270a0008 */ 	addiu	$t2,$t8,0x8
/*  f0f4d6c:	afaa0440 */ 	sw	$t2,0x440($sp)
/*  f0f4d70:	37390010 */ 	ori	$t9,$t9,0x10
/*  f0f4d74:	256b1468 */ 	addiu	$t3,$t3,%lo(var80071468)
/*  f0f4d78:	af0b0004 */ 	sw	$t3,0x4($t8)
/*  f0f4d7c:	af190000 */ 	sw	$t9,0x0($t8)
/*  f0f4d80:	8fad0440 */ 	lw	$t5,0x440($sp)
/*  f0f4d84:	3c0c0384 */ 	lui	$t4,0x384
/*  f0f4d88:	358c0010 */ 	ori	$t4,$t4,0x10
/*  f0f4d8c:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0f4d90:	afae0440 */ 	sw	$t6,0x440($sp)
/*  f0f4d94:	adac0000 */ 	sw	$t4,0x0($t5)
/*  f0f4d98:	0fc2d5ea */ 	jal	currentPlayerGetUnk175c
/*  f0f4d9c:	afad00b8 */ 	sw	$t5,0xb8($sp)
/*  f0f4da0:	8fa500b8 */ 	lw	$a1,0xb8($sp)
/*  f0f4da4:	3c0a0382 */ 	lui	$t2,0x382
/*  f0f4da8:	354a0010 */ 	ori	$t2,$t2,0x10
/*  f0f4dac:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0f4db0:	8faf0440 */ 	lw	$t7,0x440($sp)
/*  f0f4db4:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0f4db8:	afb80440 */ 	sw	$t8,0x440($sp)
/*  f0f4dbc:	adea0000 */ 	sw	$t2,0x0($t7)
/*  f0f4dc0:	0fc2d5ea */ 	jal	currentPlayerGetUnk175c
/*  f0f4dc4:	afaf00b4 */ 	sw	$t7,0xb4($sp)
/*  f0f4dc8:	8fa600b4 */ 	lw	$a2,0xb4($sp)
/*  f0f4dcc:	24590010 */ 	addiu	$t9,$v0,0x10
/*  f0f4dd0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0f4dd4:	acd90004 */ 	sw	$t9,0x4($a2)
/*  f0f4dd8:	8fac0440 */ 	lw	$t4,0x440($sp)
/*  f0f4ddc:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0f4de0:	240effff */ 	addiu	$t6,$zero,-1
/*  f0f4de4:	258f0008 */ 	addiu	$t7,$t4,0x8
/*  f0f4de8:	afab03e8 */ 	sw	$t3,0x3e8($sp)
/*  f0f4dec:	afad03ec */ 	sw	$t5,0x3ec($sp)
/*  f0f4df0:	afae03f0 */ 	sw	$t6,0x3f0($sp)
/*  f0f4df4:	afaf0440 */ 	sw	$t7,0x440($sp)
/*  f0f4df8:	3c18b700 */ 	lui	$t8,0xb700
/*  f0f4dfc:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0f4e00:	ad8a0004 */ 	sw	$t2,0x4($t4)
/*  f0f4e04:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f0f4e08:	8fb90440 */ 	lw	$t9,0x440($sp)
/*  f0f4e0c:	afab03bc */ 	sw	$t3,0x3bc($sp)
/*  f0f4e10:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f0f4e14:	27a403b8 */ 	addiu	$a0,$sp,0x3b8
/*  f0f4e18:	0c0087bd */ 	jal	func00021ef4
/*  f0f4e1c:	afb903c4 */ 	sw	$t9,0x3c4($sp)
/*  f0f4e20:	8fad03c4 */ 	lw	$t5,0x3c4($sp)
/*  f0f4e24:	0c0059d8 */ 	jal	func00016760
/*  f0f4e28:	afad0440 */ 	sw	$t5,0x440($sp)
/*  f0f4e2c:	8e0e0054 */ 	lw	$t6,0x54($s0)
/*  f0f4e30:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f4e34:	85cc000e */ 	lh	$t4,0xe($t6)
/*  f0f4e38:	19800013 */ 	blez	$t4,.L0f0f4e88
/*  f0f4e3c:	00000000 */ 	nop
/*  f0f4e40:	8e0f006c */ 	lw	$t7,0x6c($s0)
.L0f0f4e44:
/*  f0f4e44:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0f4e48:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0f4e4c:	0c005746 */ 	jal	func00015d18
/*  f0f4e50:	01e22021 */ 	addu	$a0,$t7,$v0
/*  f0f4e54:	8e18006c */ 	lw	$t8,0x6c($s0)
/*  f0f4e58:	00115180 */ 	sll	$t2,$s1,0x6
/*  f0f4e5c:	27a40070 */ 	addiu	$a0,$sp,0x70
/*  f0f4e60:	0c005815 */ 	jal	func00016054
/*  f0f4e64:	030a2821 */ 	addu	$a1,$t8,$t2
/*  f0f4e68:	8e190054 */ 	lw	$t9,0x54($s0)
/*  f0f4e6c:	8fa20040 */ 	lw	$v0,0x40($sp)
/*  f0f4e70:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0f4e74:	872b000e */ 	lh	$t3,0xe($t9)
/*  f0f4e78:	24420040 */ 	addiu	$v0,$v0,64
/*  f0f4e7c:	022b082a */ 	slt	$at,$s1,$t3
/*  f0f4e80:	5420fff0 */ 	bnezl	$at,.L0f0f4e44
/*  f0f4e84:	8e0f006c */ 	lw	$t7,0x6c($s0)
.L0f0f4e88:
/*  f0f4e88:	0c0059e1 */ 	jal	func00016784
/*  f0f4e8c:	00000000 */ 	nop
/*  f0f4e90:	8fad0448 */ 	lw	$t5,0x448($sp)
/*  f0f4e94:	29a10003 */ 	slti	$at,$t5,0x3
/*  f0f4e98:	50200005 */ 	beqzl	$at,.L0f0f4eb0
/*  f0f4e9c:	8fae0440 */ 	lw	$t6,0x440($sp)
/*  f0f4ea0:	0fc351e7 */ 	jal	func0f0d479c
/*  f0f4ea4:	8fa40440 */ 	lw	$a0,0x440($sp)
/*  f0f4ea8:	afa20440 */ 	sw	$v0,0x440($sp)
/*  f0f4eac:	8fae0440 */ 	lw	$t6,0x440($sp)
.L0f0f4eb0:
/*  f0f4eb0:	3c0fe700 */ 	lui	$t7,0xe700
/*  f0f4eb4:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0f4eb8:	25cc0008 */ 	addiu	$t4,$t6,0x8
/*  f0f4ebc:	afac0440 */ 	sw	$t4,0x440($sp)
/*  f0f4ec0:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0f4ec4:	adcf0000 */ 	sw	$t7,0x0($t6)
/*  f0f4ec8:	8fb80440 */ 	lw	$t8,0x440($sp)
/*  f0f4ecc:	37391402 */ 	ori	$t9,$t9,0x1402
/*  f0f4ed0:	3c0eb900 */ 	lui	$t6,0xb900
/*  f0f4ed4:	270a0008 */ 	addiu	$t2,$t8,0x8
/*  f0f4ed8:	afaa0440 */ 	sw	$t2,0x440($sp)
/*  f0f4edc:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0f4ee0:	af190000 */ 	sw	$t9,0x0($t8)
/*  f0f4ee4:	8fab0440 */ 	lw	$t3,0x440($sp)
/*  f0f4ee8:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f0f4eec:	3c18fc12 */ 	lui	$t8,0xfc12
/*  f0f4ef0:	256d0008 */ 	addiu	$t5,$t3,0x8
/*  f0f4ef4:	afad0440 */ 	sw	$t5,0x440($sp)
/*  f0f4ef8:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f0f4efc:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f0f4f00:	8fac0440 */ 	lw	$t4,0x440($sp)
/*  f0f4f04:	37187e24 */ 	ori	$t8,$t8,0x7e24
/*  f0f4f08:	240af9fc */ 	addiu	$t2,$zero,-1540
/*  f0f4f0c:	258f0008 */ 	addiu	$t7,$t4,0x8
/*  f0f4f10:	afaf0440 */ 	sw	$t7,0x440($sp)
/*  f0f4f14:	ad8a0004 */ 	sw	$t2,0x4($t4)
/*  f0f4f18:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f0f4f1c:	8fb90440 */ 	lw	$t9,0x440($sp)
/*  f0f4f20:	240e3000 */ 	addiu	$t6,$zero,0x3000
/*  f0f4f24:	3c0db600 */ 	lui	$t5,0xb600
/*  f0f4f28:	272b0008 */ 	addiu	$t3,$t9,0x8
/*  f0f4f2c:	afab0440 */ 	sw	$t3,0x440($sp)
/*  f0f4f30:	af2e0004 */ 	sw	$t6,0x4($t9)
/*  f0f4f34:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0f4f38:	8fac0440 */ 	lw	$t4,0x440($sp)
/*  f0f4f3c:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0f4f40:	37180c02 */ 	ori	$t8,$t8,0xc02
/*  f0f4f44:	258f0008 */ 	addiu	$t7,$t4,0x8
/*  f0f4f48:	afaf0440 */ 	sw	$t7,0x440($sp)
/*  f0f4f4c:	240a2000 */ 	addiu	$t2,$zero,0x2000
/*  f0f4f50:	ad8a0004 */ 	sw	$t2,0x4($t4)
/*  f0f4f54:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f0f4f58:	27b00440 */ 	addiu	$s0,$sp,0x440
/*  f0f4f5c:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f0f4f60:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0f4f64:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0f4f68:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f4f6c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f4f70:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f4f74:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f4f78:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0f4f7c:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0f4f80:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f4f84:	8fad0440 */ 	lw	$t5,0x440($sp)
/*  f0f4f88:	3c0cb900 */ 	lui	$t4,0xb900
/*  f0f4f8c:	3c0f0050 */ 	lui	$t7,0x50
/*  f0f4f90:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0f4f94:	afae0440 */ 	sw	$t6,0x440($sp)
/*  f0f4f98:	35ef4240 */ 	ori	$t7,$t7,0x4240
/*  f0f4f9c:	358c031d */ 	ori	$t4,$t4,0x31d
/*  f0f4fa0:	adac0000 */ 	sw	$t4,0x0($t5)
/*  f0f4fa4:	adaf0004 */ 	sw	$t7,0x4($t5)
/*  f0f4fa8:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f0f4fac:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0f4fb0:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0f4fb4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f4fb8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f4fbc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f4fc0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f4fc4:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0f4fc8:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0f4fcc:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f4fd0:	8fb90440 */ 	lw	$t9,0x440($sp)
/*  f0f4fd4:	3c0d0600 */ 	lui	$t5,0x600
/*  f0f4fd8:	272b0008 */ 	addiu	$t3,$t9,0x8
/*  f0f4fdc:	afab0440 */ 	sw	$t3,0x440($sp)
/*  f0f4fe0:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0f4fe4:	8fae0038 */ 	lw	$t6,0x38($sp)
/*  f0f4fe8:	af2e0004 */ 	sw	$t6,0x4($t9)
.L0f0f4fec:
/*  f0f4fec:	8fa20440 */ 	lw	$v0,0x440($sp)
.L0f0f4ff0:
/*  f0f4ff0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0f4ff4:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f0f4ff8:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f0f4ffc:	03e00008 */ 	jr	$ra
/*  f0f5000:	27bd0440 */ 	addiu	$sp,$sp,0x440
);

GLOBAL_ASM(
glabel func0f0f5004
/*  f0f5004:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0f5008:	3c0e7f1b */ 	lui	$t6,%hi(var7f1b25f8)
/*  f0f500c:	27a20000 */ 	addiu	$v0,$sp,0x0
/*  f0f5010:	3c03800b */ 	lui	$v1,%hi(g_MpPlayers)
/*  f0f5014:	3c078007 */ 	lui	$a3,%hi(g_MpPlayerNum)
/*  f0f5018:	25ce25f8 */ 	addiu	$t6,$t6,%lo(var7f1b25f8)
/*  f0f501c:	24e71448 */ 	addiu	$a3,$a3,%lo(g_MpPlayerNum)
/*  f0f5020:	2463c7b8 */ 	addiu	$v1,$v1,%lo(g_MpPlayers)
/*  f0f5024:	240800a0 */ 	addiu	$t0,$zero,0xa0
/*  f0f5028:	2409000c */ 	addiu	$t1,$zero,0xc
/*  f0f502c:	25d90060 */ 	addiu	$t9,$t6,0x60
/*  f0f5030:	00405025 */ 	or	$t2,$v0,$zero
.L0f0f5034:
/*  f0f5034:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0f5038:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f0f503c:	254a000c */ 	addiu	$t2,$t2,0xc
/*  f0f5040:	ad41fff4 */ 	sw	$at,-0xc($t2)
/*  f0f5044:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f0f5048:	ad41fff8 */ 	sw	$at,-0x8($t2)
/*  f0f504c:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f0f5050:	15d9fff8 */ 	bne	$t6,$t9,.L0f0f5034
/*  f0f5054:	ad41fffc */ 	sw	$at,-0x4($t2)
/*  f0f5058:	8ced0000 */ 	lw	$t5,0x0($a3)
/*  f0f505c:	8c8b0000 */ 	lw	$t3,0x0($a0)
/*  f0f5060:	01a80019 */ 	multu	$t5,$t0
/*  f0f5064:	316c00ff */ 	andi	$t4,$t3,0xff
/*  f0f5068:	0000c012 */ 	mflo	$t8
/*  f0f506c:	00787821 */ 	addu	$t7,$v1,$t8
/*  f0f5070:	91f90011 */ 	lbu	$t9,0x11($t7)
/*  f0f5074:	03290019 */ 	multu	$t9,$t1
/*  f0f5078:	00007012 */ 	mflo	$t6
/*  f0f507c:	004e5021 */ 	addu	$t2,$v0,$t6
/*  f0f5080:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*  f0f5084:	018b6825 */ 	or	$t5,$t4,$t3
/*  f0f5088:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f0f508c:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f0f5090:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f0f5094:	03280019 */ 	multu	$t9,$t0
/*  f0f5098:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f0f509c:	00007012 */ 	mflo	$t6
/*  f0f50a0:	006e5021 */ 	addu	$t2,$v1,$t6
/*  f0f50a4:	914c0011 */ 	lbu	$t4,0x11($t2)
/*  f0f50a8:	01890019 */ 	multu	$t4,$t1
/*  f0f50ac:	00005812 */ 	mflo	$t3
/*  f0f50b0:	004b6821 */ 	addu	$t5,$v0,$t3
/*  f0f50b4:	8db80004 */ 	lw	$t8,0x4($t5)
/*  f0f50b8:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f0f50bc:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f0f50c0:	8cec0000 */ 	lw	$t4,0x0($a3)
/*  f0f50c4:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f0f50c8:	01880019 */ 	multu	$t4,$t0
/*  f0f50cc:	31ca00ff */ 	andi	$t2,$t6,0xff
/*  f0f50d0:	00005812 */ 	mflo	$t3
/*  f0f50d4:	006b6821 */ 	addu	$t5,$v1,$t3
/*  f0f50d8:	91af0011 */ 	lbu	$t7,0x11($t5)
/*  f0f50dc:	01e90019 */ 	multu	$t7,$t1
/*  f0f50e0:	0000c012 */ 	mflo	$t8
/*  f0f50e4:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f0f50e8:	8f2e0008 */ 	lw	$t6,0x8($t9)
/*  f0f50ec:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f0f50f0:	014e6025 */ 	or	$t4,$t2,$t6
/*  f0f50f4:	03e00008 */ 	jr	$ra
/*  f0f50f8:	accc0000 */ 	sw	$t4,0x0($a2)
);

GLOBAL_ASM(
glabel func0f0f50fc
/*  f0f50fc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f5100:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f5104:	00801025 */ 	or	$v0,$a0,$zero
/*  f0f5108:	3c0ee700 */ 	lui	$t6,0xe700
/*  f0f510c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0f5110:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f0f5114:	3c038008 */ 	lui	$v1,%hi(g_ScreenWidthMultiplier)
/*  f0f5118:	3c0f800a */ 	lui	$t7,%hi(var800a2038)
/*  f0f511c:	8def2038 */ 	lw	$t7,%lo(var800a2038)($t7)
/*  f0f5120:	8c63fac0 */ 	lw	$v1,%lo(g_ScreenWidthMultiplier)($v1)
/*  f0f5124:	3c058007 */ 	lui	$a1,%hi(var80071190)
/*  f0f5128:	24a51190 */ 	addiu	$a1,$a1,%lo(var80071190)
/*  f0f512c:	01e30019 */ 	multu	$t7,$v1
/*  f0f5130:	3c19800a */ 	lui	$t9,%hi(var800a203c)
/*  f0f5134:	3c068007 */ 	lui	$a2,%hi(var80071194)
/*  f0f5138:	24c61194 */ 	addiu	$a2,$a2,%lo(var80071194)
/*  f0f513c:	3c0a800a */ 	lui	$t2,%hi(var800a2040)
/*  f0f5140:	3c088007 */ 	lui	$t0,%hi(var80071198)
/*  f0f5144:	25081198 */ 	addiu	$t0,$t0,%lo(var80071198)
/*  f0f5148:	3c0b800a */ 	lui	$t3,%hi(var800a2044)
/*  f0f514c:	3c078007 */ 	lui	$a3,%hi(var8007119c)
/*  f0f5150:	24e7119c */ 	addiu	$a3,$a3,%lo(var8007119c)
/*  f0f5154:	0000c012 */ 	mflo	$t8
/*  f0f5158:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f0f515c:	8f39203c */ 	lw	$t9,%lo(var800a203c)($t9)
/*  f0f5160:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0f5164:	03230019 */ 	multu	$t9,$v1
/*  f0f5168:	00004812 */ 	mflo	$t1
/*  f0f516c:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f0f5170:	8d4a2040 */ 	lw	$t2,%lo(var800a2040)($t2)
/*  f0f5174:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f0f5178:	8d6b2044 */ 	lw	$t3,%lo(var800a2044)($t3)
/*  f0f517c:	07010002 */ 	bgez	$t8,.L0f0f5188
/*  f0f5180:	aceb0000 */ 	sw	$t3,0x0($a3)
/*  f0f5184:	aca00000 */ 	sw	$zero,0x0($a1)
.L0f0f5188:
/*  f0f5188:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f0f518c:	05a30003 */ 	bgezl	$t5,.L0f0f519c
/*  f0f5190:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0f5194:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f0f5198:	8d0e0000 */ 	lw	$t6,0x0($t0)
.L0f0f519c:
/*  f0f519c:	05c30003 */ 	bgezl	$t6,.L0f0f51ac
/*  f0f51a0:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f0f51a4:	ad000000 */ 	sw	$zero,0x0($t0)
/*  f0f51a8:	8cef0000 */ 	lw	$t7,0x0($a3)
.L0f0f51ac:
/*  f0f51ac:	05e10002 */ 	bgez	$t7,.L0f0f51b8
/*  f0f51b0:	00000000 */ 	nop
/*  f0f51b4:	ace00000 */ 	sw	$zero,0x0($a3)
.L0f0f51b8:
/*  f0f51b8:	0c002ef1 */ 	jal	viGetBufX
/*  f0f51bc:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0f51c0:	3c188007 */ 	lui	$t8,%hi(var80071190)
/*  f0f51c4:	8f181190 */ 	lw	$t8,%lo(var80071190)($t8)
/*  f0f51c8:	0058082a */ 	slt	$at,$v0,$t8
/*  f0f51cc:	10200005 */ 	beqz	$at,.L0f0f51e4
/*  f0f51d0:	00000000 */ 	nop
/*  f0f51d4:	0c002ef1 */ 	jal	viGetBufX
/*  f0f51d8:	00000000 */ 	nop
/*  f0f51dc:	3c018007 */ 	lui	$at,%hi(var80071190)
/*  f0f51e0:	ac221190 */ 	sw	$v0,%lo(var80071190)($at)
.L0f0f51e4:
/*  f0f51e4:	0c002ef1 */ 	jal	viGetBufX
/*  f0f51e8:	00000000 */ 	nop
/*  f0f51ec:	3c198007 */ 	lui	$t9,%hi(var80071194)
/*  f0f51f0:	8f391194 */ 	lw	$t9,%lo(var80071194)($t9)
/*  f0f51f4:	0059082a */ 	slt	$at,$v0,$t9
/*  f0f51f8:	10200005 */ 	beqz	$at,.L0f0f5210
/*  f0f51fc:	00000000 */ 	nop
/*  f0f5200:	0c002ef1 */ 	jal	viGetBufX
/*  f0f5204:	00000000 */ 	nop
/*  f0f5208:	3c018007 */ 	lui	$at,%hi(var80071194)
/*  f0f520c:	ac221194 */ 	sw	$v0,%lo(var80071194)($at)
.L0f0f5210:
/*  f0f5210:	0c002ef5 */ 	jal	viGetBufY
/*  f0f5214:	00000000 */ 	nop
/*  f0f5218:	3c098007 */ 	lui	$t1,%hi(var80071198)
/*  f0f521c:	8d291198 */ 	lw	$t1,%lo(var80071198)($t1)
/*  f0f5220:	0049082a */ 	slt	$at,$v0,$t1
/*  f0f5224:	10200005 */ 	beqz	$at,.L0f0f523c
/*  f0f5228:	00000000 */ 	nop
/*  f0f522c:	0c002ef5 */ 	jal	viGetBufY
/*  f0f5230:	00000000 */ 	nop
/*  f0f5234:	3c018007 */ 	lui	$at,%hi(var80071198)
/*  f0f5238:	ac221198 */ 	sw	$v0,%lo(var80071198)($at)
.L0f0f523c:
/*  f0f523c:	0c002ef5 */ 	jal	viGetBufY
/*  f0f5240:	00000000 */ 	nop
/*  f0f5244:	3c078007 */ 	lui	$a3,%hi(var8007119c)
/*  f0f5248:	24e7119c */ 	addiu	$a3,$a3,%lo(var8007119c)
/*  f0f524c:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f0f5250:	0043082a */ 	slt	$at,$v0,$v1
/*  f0f5254:	10200009 */ 	beqz	$at,.L0f0f527c
/*  f0f5258:	00000000 */ 	nop
/*  f0f525c:	0c002ef5 */ 	jal	viGetBufY
/*  f0f5260:	00000000 */ 	nop
/*  f0f5264:	3c018007 */ 	lui	$at,%hi(var8007119c)
/*  f0f5268:	ac22119c */ 	sw	$v0,%lo(var8007119c)($at)
/*  f0f526c:	3c038007 */ 	lui	$v1,%hi(var8007119c)
/*  f0f5270:	3c078007 */ 	lui	$a3,%hi(var8007119c)
/*  f0f5274:	24e7119c */ 	addiu	$a3,$a3,%lo(var8007119c)
/*  f0f5278:	8c63119c */ 	lw	$v1,%lo(var8007119c)($v1)
.L0f0f527c:
/*  f0f527c:	3c088007 */ 	lui	$t0,%hi(var80071194)
/*  f0f5280:	3c048007 */ 	lui	$a0,%hi(var80071190)
/*  f0f5284:	8c841190 */ 	lw	$a0,%lo(var80071190)($a0)
/*  f0f5288:	25081194 */ 	addiu	$t0,$t0,%lo(var80071194)
/*  f0f528c:	8d0a0000 */ 	lw	$t2,0x0($t0)
/*  f0f5290:	44842000 */ 	mtc1	$a0,$f4
/*  f0f5294:	3c058007 */ 	lui	$a1,%hi(var80071198)
/*  f0f5298:	0144082a */ 	slt	$at,$t2,$a0
/*  f0f529c:	10200002 */ 	beqz	$at,.L0f0f52a8
/*  f0f52a0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0f52a4:	ad040000 */ 	sw	$a0,0x0($t0)
.L0f0f52a8:
/*  f0f52a8:	8ca51198 */ 	lw	$a1,%lo(var80071198)($a1)
/*  f0f52ac:	0065082a */ 	slt	$at,$v1,$a1
/*  f0f52b0:	50200003 */ 	beqzl	$at,.L0f0f52c0
/*  f0f52b4:	44858000 */ 	mtc1	$a1,$f16
/*  f0f52b8:	ace50000 */ 	sw	$a1,0x0($a3)
/*  f0f52bc:	44858000 */ 	mtc1	$a1,$f16
.L0f0f52c0:
/*  f0f52c0:	3c014080 */ 	lui	$at,0x4080
/*  f0f52c4:	44810000 */ 	mtc1	$at,$f0
/*  f0f52c8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0f52cc:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f0f52d0:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0f52d4:	3c01ed00 */ 	lui	$at,0xed00
/*  f0f52d8:	24620008 */ 	addiu	$v0,$v1,0x8
/*  f0f52dc:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0f52e0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0f52e4:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0f52e8:	440c5000 */ 	mfc1	$t4,$f10
/*  f0f52ec:	44193000 */ 	mfc1	$t9,$f6
/*  f0f52f0:	318d0fff */ 	andi	$t5,$t4,0xfff
/*  f0f52f4:	000d7300 */ 	sll	$t6,$t5,0xc
/*  f0f52f8:	01c17825 */ 	or	$t7,$t6,$at
/*  f0f52fc:	33290fff */ 	andi	$t1,$t9,0xfff
/*  f0f5300:	01e95025 */ 	or	$t2,$t7,$t1
/*  f0f5304:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f0f5308:	8d0b0000 */ 	lw	$t3,0x0($t0)
/*  f0f530c:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f0f5310:	448b4000 */ 	mtc1	$t3,$f8
/*  f0f5314:	44992000 */ 	mtc1	$t9,$f4
/*  f0f5318:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0f531c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0f5320:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0f5324:	00000000 */ 	nop
/*  f0f5328:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0f532c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0f5330:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0f5334:	440d9000 */ 	mfc1	$t5,$f18
/*  f0f5338:	44095000 */ 	mfc1	$t1,$f10
/*  f0f533c:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f0f5340:	000ec300 */ 	sll	$t8,$t6,0xc
/*  f0f5344:	312a0fff */ 	andi	$t2,$t1,0xfff
/*  f0f5348:	030a5825 */ 	or	$t3,$t8,$t2
/*  f0f534c:	ac6b0004 */ 	sw	$t3,0x4($v1)
/*  f0f5350:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f5354:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f5358:	03e00008 */ 	jr	$ra
/*  f0f535c:	00000000 */ 	nop
);

const char var7f1b2658[] = "1\n";
const char var7f1b265c[] = "2\n";
const char var7f1b2660[] = "3\n";
const char var7f1b2664[] = "4\n";

u32 var800714c8 = (u32)&var7f1b2658;
u32 var800714cc = (u32)&var7f1b265c;
u32 var800714d0 = (u32)&var7f1b2660;
u32 var800714d4 = (u32)&var7f1b2664;

const char var7f1b2668[] = "[]-[] Terminate Complete\n";
const char var7f1b2684[] = "Enabling control %d\n";
const char var7f1b269c[] = "NOT IN MODE MULTIINGAME!\n";
const char var7f1b26b8[] = "Numactive now:%d\n";
const char var7f1b26cc[] = "[]-[] SwitchMenuMode called, context %d\n";
const char var7f1b26f8[] = "cthresh";
const char var7f1b2700[] = "[]-[] slide from %d";
const char var7f1b2714[] = " to %d\n";
const char var7f1b271c[] = "UNPAUSE: enabling control 0\n";
const char var7f1b273c[] = "file: type %d guid %x-%x data %x err %d\n";
const char var7f1b2768[] = "StartSelects\n";
const char var7f1b2778[] = "bblur";

GLOBAL_ASM(
glabel func0f0f5360
/*  f0f5360:	27bdfe18 */ 	addiu	$sp,$sp,-488
/*  f0f5364:	afbe0060 */ 	sw	$s8,0x60($sp)
/*  f0f5368:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f0f536c:	afb7005c */ 	sw	$s7,0x5c($sp)
/*  f0f5370:	afb60058 */ 	sw	$s6,0x58($sp)
/*  f0f5374:	afb50054 */ 	sw	$s5,0x54($sp)
/*  f0f5378:	afb40050 */ 	sw	$s4,0x50($sp)
/*  f0f537c:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f0f5380:	afb20048 */ 	sw	$s2,0x48($sp)
/*  f0f5384:	afb10044 */ 	sw	$s1,0x44($sp)
/*  f0f5388:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f0f538c:	f7b40038 */ 	sdc1	$f20,0x38($sp)
/*  f0f5390:	afa401e8 */ 	sw	$a0,0x1e8($sp)
/*  f0f5394:	afa601f0 */ 	sw	$a2,0x1f0($sp)
/*  f0f5398:	afa701f4 */ 	sw	$a3,0x1f4($sp)
/*  f0f539c:	3c1e800a */ 	lui	$s8,%hi(g_Vars)
/*  f0f53a0:	27de9fc0 */ 	addiu	$s8,$s8,%lo(g_Vars)
/*  f0f53a4:	8fd80298 */ 	lw	$t8,0x298($s8)
/*  f0f53a8:	8cb50014 */ 	lw	$s5,0x14($a1)
/*  f0f53ac:	8cb30018 */ 	lw	$s3,0x18($a1)
/*  f0f53b0:	8cae001c */ 	lw	$t6,0x1c($a1)
/*  f0f53b4:	8caf0020 */ 	lw	$t7,0x20($a1)
/*  f0f53b8:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0f53bc:	02aeb021 */ 	addu	$s6,$s5,$t6
/*  f0f53c0:	07010005 */ 	bgez	$t8,.L0f0f53d8
/*  f0f53c4:	026fa021 */ 	addu	$s4,$s3,$t7
/*  f0f53c8:	8fd9029c */ 	lw	$t9,0x29c($s8)
/*  f0f53cc:	afa501ec */ 	sw	$a1,0x1ec($sp)
/*  f0f53d0:	0722000c */ 	bltzl	$t9,.L0f0f5404
/*  f0f53d4:	8fb001ec */ 	lw	$s0,0x1ec($sp)
.L0f0f53d8:
/*  f0f53d8:	0fc3f303 */ 	jal	menuGetRoot
/*  f0f53dc:	afb001ec */ 	sw	$s0,0x1ec($sp)
/*  f0f53e0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f53e4:	14410006 */ 	bne	$v0,$at,.L0f0f5400
/*  f0f53e8:	3c0b800a */ 	lui	$t3,%hi(var8009dfc0)
/*  f0f53ec:	8d6bdfc0 */ 	lw	$t3,%lo(var8009dfc0)($t3)
/*  f0f53f0:	55600004 */ 	bnezl	$t3,.L0f0f5404
/*  f0f53f4:	8fb001ec */ 	lw	$s0,0x1ec($sp)
/*  f0f53f8:	1000081e */ 	b	.L0f0f7474
/*  f0f53fc:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f5400:
/*  f0f5400:	8fb001ec */ 	lw	$s0,0x1ec($sp)
.L0f0f5404:
/*  f0f5404:	4480a000 */ 	mtc1	$zero,$f20
/*  f0f5408:	3c197f1b */ 	lui	$t9,%hi(g_MenuColourPalettes)
/*  f0f540c:	c6040040 */ 	lwc1	$f4,0x40($s0)
/*  f0f5410:	27391fb0 */ 	addiu	$t9,$t9,%lo(g_MenuColourPalettes)
/*  f0f5414:	4614203c */ 	c.lt.s	$f4,$f20
/*  f0f5418:	00000000 */ 	nop
/*  f0f541c:	4502000c */ 	bc1fl	.L0f0f5450
/*  f0f5420:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f0f5424:	920c003c */ 	lbu	$t4,0x3c($s0)
/*  f0f5428:	3c0e7f1b */ 	lui	$t6,%hi(g_MenuColourPalettes+0x28)
/*  f0f542c:	afb001ec */ 	sw	$s0,0x1ec($sp)
/*  f0f5430:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0f5434:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0f5438:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f543c:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f0f5440:	8dce1fd8 */ 	lw	$t6,%lo(g_MenuColourPalettes+0x28)($t6)
/*  f0f5444:	10000011 */ 	b	.L0f0f548c
/*  f0f5448:	afae01bc */ 	sw	$t6,0x1bc($sp)
/*  f0f544c:	920f003d */ 	lbu	$t7,0x3d($s0)
.L0f0f5450:
/*  f0f5450:	920c003c */ 	lbu	$t4,0x3c($s0)
/*  f0f5454:	8e060044 */ 	lw	$a2,0x44($s0)
/*  f0f5458:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f0f545c:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0f5460:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f5464:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0f5468:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f546c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f5470:	03195821 */ 	addu	$t3,$t8,$t9
/*  f0f5474:	01b97021 */ 	addu	$t6,$t5,$t9
/*  f0f5478:	8dc50028 */ 	lw	$a1,0x28($t6)
/*  f0f547c:	8d640028 */ 	lw	$a0,0x28($t3)
/*  f0f5480:	0fc01a40 */ 	jal	colourBlend
/*  f0f5484:	afb001ec */ 	sw	$s0,0x1ec($sp)
/*  f0f5488:	afa201bc */ 	sw	$v0,0x1bc($sp)
.L0f0f548c:
/*  f0f548c:	0fc5580c */ 	jal	func0f156030
/*  f0f5490:	8fa401bc */ 	lw	$a0,0x1bc($sp)
/*  f0f5494:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f0f5498:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f0f549c:	3c0b800a */ 	lui	$t3,%hi(g_Menus)
/*  f0f54a0:	3c018008 */ 	lui	$at,%hi(var8007fb9c)
/*  f0f54a4:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f54a8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f54ac:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f54b0:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f54b4:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f54b8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f54bc:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f54c0:	256be000 */ 	addiu	$t3,$t3,%lo(g_Menus)
/*  f0f54c4:	ac20fb9c */ 	sw	$zero,%lo(var8007fb9c)($at)
/*  f0f54c8:	030b1821 */ 	addu	$v1,$t8,$t3
/*  f0f54cc:	8fa701ec */ 	lw	$a3,0x1ec($sp)
/*  f0f54d0:	8c6c04f8 */ 	lw	$t4,0x4f8($v1)
/*  f0f54d4:	54ec002d */ 	bnel	$a3,$t4,.L0f0f558c
/*  f0f54d8:	8cf8001c */ 	lw	$t8,0x1c($a3)
/*  f0f54dc:	8ced0000 */ 	lw	$t5,0x0($a3)
/*  f0f54e0:	8faf01f4 */ 	lw	$t7,0x1f4($sp)
/*  f0f54e4:	8db90010 */ 	lw	$t9,0x10($t5)
/*  f0f54e8:	332e0002 */ 	andi	$t6,$t9,0x2
/*  f0f54ec:	51c00027 */ 	beqzl	$t6,.L0f0f558c
/*  f0f54f0:	8cf8001c */ 	lw	$t8,0x1c($a3)
/*  f0f54f4:	55e00025 */ 	bnezl	$t7,.L0f0f558c
/*  f0f54f8:	8cf8001c */ 	lw	$t8,0x1c($a3)
/*  f0f54fc:	8c780df0 */ 	lw	$t8,0xdf0($v1)
/*  f0f5500:	8fad01e8 */ 	lw	$t5,0x1e8($sp)
/*  f0f5504:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f5508:	00185b80 */ 	sll	$t3,$t8,0xe
/*  f0f550c:	000b67c2 */ 	srl	$t4,$t3,0x1f
/*  f0f5510:	1581001d */ 	bne	$t4,$at,.L0f0f5588
/*  f0f5514:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f0f5518:	afb901e8 */ 	sw	$t9,0x1e8($sp)
/*  f0f551c:	3c0eb700 */ 	lui	$t6,0xb700
/*  f0f5520:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f5524:	adaf0004 */ 	sw	$t7,0x4($t5)
/*  f0f5528:	adae0000 */ 	sw	$t6,0x0($t5)
/*  f0f552c:	3c188007 */ 	lui	$t8,%hi(g_MpPlayerNum)
/*  f0f5530:	8f181448 */ 	lw	$t8,%lo(g_MpPlayerNum)($t8)
/*  f0f5534:	3c0d800a */ 	lui	$t5,%hi(g_Menus)
/*  f0f5538:	25ade000 */ 	addiu	$t5,$t5,%lo(g_Menus)
/*  f0f553c:	001858c0 */ 	sll	$t3,$t8,0x3
/*  f0f5540:	01785823 */ 	subu	$t3,$t3,$t8
/*  f0f5544:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0f5548:	01785821 */ 	addu	$t3,$t3,$t8
/*  f0f554c:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f0f5550:	01785823 */ 	subu	$t3,$t3,$t8
/*  f0f5554:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f0f5558:	256c0840 */ 	addiu	$t4,$t3,0x840
/*  f0f555c:	018d2821 */ 	addu	$a1,$t4,$t5
/*  f0f5560:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5564:	0fc3ce2c */ 	jal	func0f0f38b0
/*  f0f5568:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0f556c:	24590008 */ 	addiu	$t9,$v0,0x8
/*  f0f5570:	afb901e8 */ 	sw	$t9,0x1e8($sp)
/*  f0f5574:	3c0eb600 */ 	lui	$t6,0xb600
/*  f0f5578:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f557c:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0f5580:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0f5584:	8fa701ec */ 	lw	$a3,0x1ec($sp)
.L0f0f5588:
/*  f0f5588:	8cf8001c */ 	lw	$t8,0x1c($a3)
.L0f0f558c:
/*  f0f558c:	3c0c8008 */ 	lui	$t4,%hi(g_MpReadyMenuDialog)
/*  f0f5590:	258c57b8 */ 	addiu	$t4,$t4,%lo(g_MpReadyMenuDialog)
/*  f0f5594:	a7b801ca */ 	sh	$t8,0x1ca($sp)
/*  f0f5598:	90eb0060 */ 	lbu	$t3,0x60($a3)
/*  f0f559c:	84f00022 */ 	lh	$s0,0x22($a3)
/*  f0f55a0:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f0f55a4:	55600029 */ 	bnezl	$t3,.L0f0f564c
/*  f0f55a8:	8ced0014 */ 	lw	$t5,0x14($a3)
/*  f0f55ac:	15840003 */ 	bne	$t4,$a0,.L0f0f55bc
/*  f0f55b0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f55b4:	100007af */ 	b	.L0f0f7474
/*  f0f55b8:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f55bc:
/*  f0f55bc:	44813000 */ 	mtc1	$at,$f6
/*  f0f55c0:	8fcd0298 */ 	lw	$t5,0x298($s8)
/*  f0f55c4:	3c01800a */ 	lui	$at,%hi(g_MenuData+0x10)
/*  f0f55c8:	c42819d0 */ 	lwc1	$f8,%lo(g_MenuData+0x10)($at)
/*  f0f55cc:	05a10004 */ 	bgez	$t5,.L0f0f55e0
/*  f0f55d0:	46083001 */ 	sub.s	$f0,$f6,$f8
/*  f0f55d4:	8fd9029c */ 	lw	$t9,0x29c($s8)
/*  f0f55d8:	0720000b */ 	bltz	$t9,.L0f0f5608
/*  f0f55dc:	00000000 */ 	nop
.L0f0f55e0:
/*  f0f55e0:	0fc3f303 */ 	jal	menuGetRoot
/*  f0f55e4:	e7a00170 */ 	swc1	$f0,0x170($sp)
/*  f0f55e8:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f55ec:	14410006 */ 	bne	$v0,$at,.L0f0f5608
/*  f0f55f0:	c7a00170 */ 	lwc1	$f0,0x170($sp)
/*  f0f55f4:	8fae01ec */ 	lw	$t6,0x1ec($sp)
/*  f0f55f8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f55fc:	44815000 */ 	mtc1	$at,$f10
/*  f0f5600:	c5d00050 */ 	lwc1	$f16,0x50($t6)
/*  f0f5604:	46105001 */ 	sub.s	$f0,$f10,$f16
.L0f0f5608:
/*  f0f5608:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f0f560c:	44903000 */ 	mtc1	$s0,$f6
/*  f0f5610:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f5614:	44819000 */ 	mtc1	$at,$f18
/*  f0f5618:	8fa701ec */ 	lw	$a3,0x1ec($sp)
/*  f0f561c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0f5620:	8cec0018 */ 	lw	$t4,0x18($a3)
/*  f0f5624:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f0f5628:	46049001 */ 	sub.s	$f0,$f18,$f4
/*  f0f562c:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0f5630:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0f5634:	44108000 */ 	mfc1	$s0,$f16
/*  f0f5638:	00000000 */ 	nop
/*  f0f563c:	0010c400 */ 	sll	$t8,$s0,0x10
/*  f0f5640:	00188403 */ 	sra	$s0,$t8,0x10
/*  f0f5644:	0190a021 */ 	addu	$s4,$t4,$s0
/*  f0f5648:	8ced0014 */ 	lw	$t5,0x14($a3)
.L0f0f564c:
/*  f0f564c:	afad01e0 */ 	sw	$t5,0x1e0($sp)
/*  f0f5650:	8ce20018 */ 	lw	$v0,0x18($a3)
/*  f0f5654:	02021821 */ 	addu	$v1,$s0,$v0
/*  f0f5658:	afa301d4 */ 	sw	$v1,0x1d4($sp)
/*  f0f565c:	afa30084 */ 	sw	$v1,0x84($sp)
/*  f0f5660:	0fc3c560 */ 	jal	menuResolveParam1Text
/*  f0f5664:	afa201dc */ 	sw	$v0,0x1dc($sp)
/*  f0f5668:	8fa701ec */ 	lw	$a3,0x1ec($sp)
/*  f0f566c:	0040b825 */ 	or	$s7,$v0,$zero
/*  f0f5670:	c4f20040 */ 	lwc1	$f18,0x40($a3)
/*  f0f5674:	4614903c */ 	c.lt.s	$f18,$f20
/*  f0f5678:	00000000 */ 	nop
/*  f0f567c:	4502000c */ 	bc1fl	.L0f0f56b0
/*  f0f5680:	90eb003d */ 	lbu	$t3,0x3d($a3)
/*  f0f5684:	90f9003c */ 	lbu	$t9,0x3c($a3)
/*  f0f5688:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0f568c:	3c097f1b */ 	lui	$t1,%hi(g_MenuColourPalettes)
/*  f0f5690:	03280019 */ 	multu	$t9,$t0
/*  f0f5694:	25291fb0 */ 	addiu	$t1,$t1,%lo(g_MenuColourPalettes)
/*  f0f5698:	00007012 */ 	mflo	$t6
/*  f0f569c:	012e7821 */ 	addu	$t7,$t1,$t6
/*  f0f56a0:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f0f56a4:	10000016 */ 	b	.L0f0f5700
/*  f0f56a8:	afb801bc */ 	sw	$t8,0x1bc($sp)
/*  f0f56ac:	90eb003d */ 	lbu	$t3,0x3d($a3)
.L0f0f56b0:
/*  f0f56b0:	90ee003c */ 	lbu	$t6,0x3c($a3)
/*  f0f56b4:	3c0d7f1b */ 	lui	$t5,%hi(g_MenuColourPalettes)
/*  f0f56b8:	000b6100 */ 	sll	$t4,$t3,0x4
/*  f0f56bc:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f0f56c0:	25ad1fb0 */ 	addiu	$t5,$t5,%lo(g_MenuColourPalettes)
/*  f0f56c4:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0f56c8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f56cc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f56d0:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0f56d4:	018dc821 */ 	addu	$t9,$t4,$t5
/*  f0f56d8:	01edc021 */ 	addu	$t8,$t7,$t5
/*  f0f56dc:	8f050000 */ 	lw	$a1,0x0($t8)
/*  f0f56e0:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f0f56e4:	0fc01a40 */ 	jal	colourBlend
/*  f0f56e8:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0f56ec:	3c097f1b */ 	lui	$t1,%hi(g_MenuColourPalettes)
/*  f0f56f0:	25291fb0 */ 	addiu	$t1,$t1,%lo(g_MenuColourPalettes)
/*  f0f56f4:	afa201bc */ 	sw	$v0,0x1bc($sp)
/*  f0f56f8:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0f56fc:	8fa701ec */ 	lw	$a3,0x1ec($sp)
.L0f0f5700:
/*  f0f5700:	c4e40040 */ 	lwc1	$f4,0x40($a3)
/*  f0f5704:	4614203c */ 	c.lt.s	$f4,$f20
/*  f0f5708:	00000000 */ 	nop
/*  f0f570c:	45020009 */ 	bc1fl	.L0f0f5734
/*  f0f5710:	90ef003d */ 	lbu	$t7,0x3d($a3)
/*  f0f5714:	90eb003c */ 	lbu	$t3,0x3c($a3)
/*  f0f5718:	01680019 */ 	multu	$t3,$t0
/*  f0f571c:	00006012 */ 	mflo	$t4
/*  f0f5720:	012cc821 */ 	addu	$t9,$t1,$t4
/*  f0f5724:	8f2e0004 */ 	lw	$t6,0x4($t9)
/*  f0f5728:	10000012 */ 	b	.L0f0f5774
/*  f0f572c:	afae01b8 */ 	sw	$t6,0x1b8($sp)
/*  f0f5730:	90ef003d */ 	lbu	$t7,0x3d($a3)
.L0f0f5734:
/*  f0f5734:	90eb003c */ 	lbu	$t3,0x3c($a3)
/*  f0f5738:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0f573c:	01e80019 */ 	multu	$t7,$t0
/*  f0f5740:	00006812 */ 	mflo	$t5
/*  f0f5744:	012dc021 */ 	addu	$t8,$t1,$t5
/*  f0f5748:	8f040004 */ 	lw	$a0,0x4($t8)
/*  f0f574c:	01680019 */ 	multu	$t3,$t0
/*  f0f5750:	00006012 */ 	mflo	$t4
/*  f0f5754:	012cc821 */ 	addu	$t9,$t1,$t4
/*  f0f5758:	0fc01a40 */ 	jal	colourBlend
/*  f0f575c:	8f250004 */ 	lw	$a1,0x4($t9)
/*  f0f5760:	3c097f1b */ 	lui	$t1,%hi(g_MenuColourPalettes)
/*  f0f5764:	25291fb0 */ 	addiu	$t1,$t1,%lo(g_MenuColourPalettes)
/*  f0f5768:	afa201b8 */ 	sw	$v0,0x1b8($sp)
/*  f0f576c:	2408003c */ 	addiu	$t0,$zero,0x3c
/*  f0f5770:	8fa701ec */ 	lw	$a3,0x1ec($sp)
.L0f0f5774:
/*  f0f5774:	c4e60040 */ 	lwc1	$f6,0x40($a3)
/*  f0f5778:	4614303c */ 	c.lt.s	$f6,$f20
/*  f0f577c:	00000000 */ 	nop
/*  f0f5780:	45020009 */ 	bc1fl	.L0f0f57a8
/*  f0f5784:	90eb003d */ 	lbu	$t3,0x3d($a3)
/*  f0f5788:	90ee003c */ 	lbu	$t6,0x3c($a3)
/*  f0f578c:	01c80019 */ 	multu	$t6,$t0
/*  f0f5790:	00007812 */ 	mflo	$t7
/*  f0f5794:	012f6821 */ 	addu	$t5,$t1,$t7
/*  f0f5798:	8db80008 */ 	lw	$t8,0x8($t5)
/*  f0f579c:	1000000f */ 	b	.L0f0f57dc
/*  f0f57a0:	afb801b4 */ 	sw	$t8,0x1b4($sp)
/*  f0f57a4:	90eb003d */ 	lbu	$t3,0x3d($a3)
.L0f0f57a8:
/*  f0f57a8:	90ee003c */ 	lbu	$t6,0x3c($a3)
/*  f0f57ac:	8ce60044 */ 	lw	$a2,0x44($a3)
/*  f0f57b0:	01680019 */ 	multu	$t3,$t0
/*  f0f57b4:	00006012 */ 	mflo	$t4
/*  f0f57b8:	012cc821 */ 	addu	$t9,$t1,$t4
/*  f0f57bc:	8f240008 */ 	lw	$a0,0x8($t9)
/*  f0f57c0:	01c80019 */ 	multu	$t6,$t0
/*  f0f57c4:	00007812 */ 	mflo	$t7
/*  f0f57c8:	012f6821 */ 	addu	$t5,$t1,$t7
/*  f0f57cc:	0fc01a40 */ 	jal	colourBlend
/*  f0f57d0:	8da50008 */ 	lw	$a1,0x8($t5)
/*  f0f57d4:	afa201b4 */ 	sw	$v0,0x1b4($sp)
/*  f0f57d8:	8fa701ec */ 	lw	$a3,0x1ec($sp)
.L0f0f57dc:
/*  f0f57dc:	8fb801e8 */ 	lw	$t8,0x1e8($sp)
/*  f0f57e0:	3c0cb600 */ 	lui	$t4,0xb600
/*  f0f57e4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f57e8:	270b0008 */ 	addiu	$t3,$t8,0x8
/*  f0f57ec:	afab01e8 */ 	sw	$t3,0x1e8($sp)
/*  f0f57f0:	af190004 */ 	sw	$t9,0x4($t8)
/*  f0f57f4:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f0f57f8:	8fae01bc */ 	lw	$t6,0x1bc($sp)
/*  f0f57fc:	8fb201b4 */ 	lw	$s2,0x1b4($sp)
/*  f0f5800:	8fb801b4 */ 	lw	$t8,0x1b4($sp)
/*  f0f5804:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f0f5808:	2de10040 */ 	sltiu	$at,$t7,0x40
/*  f0f580c:	14200005 */ 	bnez	$at,.L0f0f5824
/*  f0f5810:	01c08825 */ 	or	$s1,$t6,$zero
/*  f0f5814:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f5818:	01c18824 */ 	and	$s1,$t6,$at
/*  f0f581c:	362d003f */ 	ori	$t5,$s1,0x3f
/*  f0f5820:	01a08825 */ 	or	$s1,$t5,$zero
.L0f0f5824:
/*  f0f5824:	330b00ff */ 	andi	$t3,$t8,0xff
/*  f0f5828:	2d610040 */ 	sltiu	$at,$t3,0x40
/*  f0f582c:	14200005 */ 	bnez	$at,.L0f0f5844
/*  f0f5830:	2419fc18 */ 	addiu	$t9,$zero,-1000
/*  f0f5834:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f5838:	03019024 */ 	and	$s2,$t8,$at
/*  f0f583c:	364c003f */ 	ori	$t4,$s2,0x3f
/*  f0f5840:	01809025 */ 	or	$s2,$t4,$zero
.L0f0f5844:
/*  f0f5844:	3c01800a */ 	lui	$at,%hi(var8009de90)
/*  f0f5848:	ac39de90 */ 	sw	$t9,%lo(var8009de90)($at)
/*  f0f584c:	3c01800a */ 	lui	$at,%hi(var8009de94)
/*  f0f5850:	240f03e8 */ 	addiu	$t7,$zero,0x3e8
/*  f0f5854:	ac2fde94 */ 	sw	$t7,%lo(var8009de94)($at)
/*  f0f5858:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0f585c:	3c03800a */ 	lui	$v1,%hi(g_MenuData+0x4)
/*  f0f5860:	8dc40010 */ 	lw	$a0,0x10($t6)
/*  f0f5864:	308d0100 */ 	andi	$t5,$a0,0x100
/*  f0f5868:	11a00002 */ 	beqz	$t5,.L0f0f5874
/*  f0f586c:	01a02025 */ 	or	$a0,$t5,$zero
/*  f0f5870:	2673000b */ 	addiu	$s3,$s3,0xb
.L0f0f5874:
/*  f0f5874:	8c6319c4 */ 	lw	$v1,%lo(g_MenuData+0x4)($v1)
/*  f0f5878:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f587c:	10610060 */ 	beq	$v1,$at,.L0f0f5a00
/*  f0f5880:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f5884:	14610004 */ 	bne	$v1,$at,.L0f0f5898
/*  f0f5888:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0f588c:	8fcb0318 */ 	lw	$t3,0x318($s8)
/*  f0f5890:	1160005b */ 	beqz	$t3,.L0f0f5a00
/*  f0f5894:	00000000 */ 	nop
.L0f0f5898:
/*  f0f5898:	3c10800a */ 	lui	$s0,%hi(var800a4634)
/*  f0f589c:	26104634 */ 	addiu	$s0,$s0,%lo(var800a4634)
/*  f0f58a0:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f0f58a4:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f58a8:	02c03825 */ 	or	$a3,$s6,$zero
/*  f0f58ac:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f58b0:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f0f58b4:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0f58b8:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f58bc:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f58c0:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f58c4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f58c8:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0f58cc:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f58d0:	02c03825 */ 	or	$a3,$s6,$zero
/*  f0f58d4:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f0f58d8:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f58dc:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f58e0:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f58e4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f58e8:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f58ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f58f0:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0f58f4:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f58f8:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0f58fc:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f0f5900:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f0f5904:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0f5908:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f590c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f5910:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f5914:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f5918:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0f591c:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f5920:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0f5924:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f5928:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f592c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f5930:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f5934:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f5938:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f593c:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f5940:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0f5944:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f5948:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0f594c:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f5950:	02c03825 */ 	or	$a3,$s6,$zero
/*  f0f5954:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f5958:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f595c:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f5960:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f5964:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f5968:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f596c:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0f5970:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f5974:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0f5978:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f597c:	02c03825 */ 	or	$a3,$s6,$zero
/*  f0f5980:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f0f5984:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f0f5988:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f598c:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0f5990:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f5994:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f5998:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0f599c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f59a0:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0f59a4:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f59a8:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0f59ac:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f0f59b0:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f59b4:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f59b8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f59bc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f59c0:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f59c4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0f59c8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f59cc:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0f59d0:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f59d4:	02a03825 */ 	or	$a3,$s5,$zero
/*  f0f59d8:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f59dc:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f0f59e0:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0f59e4:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f0f59e8:	8fae01ec */ 	lw	$t6,0x1ec($sp)
/*  f0f59ec:	ae020000 */ 	sw	$v0,0x0($s0)
/*  f0f59f0:	8dcd0000 */ 	lw	$t5,0x0($t6)
/*  f0f59f4:	8da40010 */ 	lw	$a0,0x10($t5)
/*  f0f59f8:	308b0100 */ 	andi	$t3,$a0,0x100
/*  f0f59fc:	01602025 */ 	or	$a0,$t3,$zero
.L0f0f5a00:
/*  f0f5a00:	148000e3 */ 	bnez	$a0,.L0f0f5d90
/*  f0f5a04:	3c03800a */ 	lui	$v1,%hi(g_MenuData+0x4)
/*  f0f5a08:	8c6319c4 */ 	lw	$v1,%lo(g_MenuData+0x4)($v1)
/*  f0f5a0c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f5a10:	10610002 */ 	beq	$v1,$at,.L0f0f5a1c
/*  f0f5a14:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0f5a18:	1461000c */ 	bne	$v1,$at,.L0f0f5a4c
.L0f0f5a1c:
/*  f0f5a1c:	3c18800b */ 	lui	$t8,%hi(g_MpSetup+0xc)
/*  f0f5a20:	8f18cb94 */ 	lw	$t8,%lo(g_MpSetup+0xc)($t8)
/*  f0f5a24:	330c0002 */ 	andi	$t4,$t8,0x2
/*  f0f5a28:	51800009 */ 	beqzl	$t4,.L0f0f5a50
/*  f0f5a2c:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
/*  f0f5a30:	8fd90490 */ 	lw	$t9,0x490($s8)
/*  f0f5a34:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f5a38:	27a401bc */ 	addiu	$a0,$sp,0x1bc
/*  f0f5a3c:	13210003 */ 	beq	$t9,$at,.L0f0f5a4c
/*  f0f5a40:	27a501b8 */ 	addiu	$a1,$sp,0x1b8
/*  f0f5a44:	0fc3d401 */ 	jal	func0f0f5004
/*  f0f5a48:	27a601b4 */ 	addiu	$a2,$sp,0x1b4
.L0f0f5a4c:
/*  f0f5a4c:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
.L0f0f5a50:
/*  f0f5a50:	87af01ca */ 	lh	$t7,0x1ca($sp)
/*  f0f5a54:	8fa601dc */ 	lw	$a2,0x1dc($sp)
/*  f0f5a58:	8fad01bc */ 	lw	$t5,0x1bc($sp)
/*  f0f5a5c:	8fab01b8 */ 	lw	$t3,0x1b8($sp)
/*  f0f5a60:	8fae01b4 */ 	lw	$t6,0x1b4($sp)
/*  f0f5a64:	01e31021 */ 	addu	$v0,$t7,$v1
/*  f0f5a68:	24510002 */ 	addiu	$s1,$v0,0x2
/*  f0f5a6c:	2470fffe */ 	addiu	$s0,$v1,-2
/*  f0f5a70:	24d5000b */ 	addiu	$s5,$a2,0xb
/*  f0f5a74:	afb50010 */ 	sw	$s5,0x10($sp)
/*  f0f5a78:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f5a7c:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f5a80:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f0f5a84:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5a88:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0f5a8c:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f5a90:	0fc3873a */ 	jal	func0f0e1ce8
/*  f0f5a94:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0f5a98:	8fac01bc */ 	lw	$t4,0x1bc($sp)
/*  f0f5a9c:	8fa601dc */ 	lw	$a2,0x1dc($sp)
/*  f0f5aa0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0f5aa4:	319900ff */ 	andi	$t9,$t4,0xff
/*  f0f5aa8:	00197842 */ 	srl	$t7,$t9,0x1
/*  f0f5aac:	240b0028 */ 	addiu	$t3,$zero,0x28
/*  f0f5ab0:	24d80001 */ 	addiu	$t8,$a2,0x1
/*  f0f5ab4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f5ab8:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0f5abc:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0f5ac0:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0f5ac4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f5ac8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f5acc:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f5ad0:	0fc38aa9 */ 	jal	func0f0e2aa4
/*  f0f5ad4:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0f5ad8:	8fae01bc */ 	lw	$t6,0x1bc($sp)
/*  f0f5adc:	8fa601dc */ 	lw	$a2,0x1dc($sp)
/*  f0f5ae0:	24190028 */ 	addiu	$t9,$zero,0x28
/*  f0f5ae4:	31d800ff */ 	andi	$t8,$t6,0xff
/*  f0f5ae8:	00186042 */ 	srl	$t4,$t8,0x1
/*  f0f5aec:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f5af0:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0f5af4:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0f5af8:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0f5afc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f5b00:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f5b04:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f5b08:	afb50010 */ 	sw	$s5,0x10($sp)
/*  f0f5b0c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0f5b10:	0fc38aa9 */ 	jal	func0f0e2aa4
/*  f0f5b14:	24c6000a */ 	addiu	$a2,$a2,0xa
/*  f0f5b18:	8fb201e0 */ 	lw	$s2,0x1e0($sp)
/*  f0f5b1c:	8fb001dc */ 	lw	$s0,0x1dc($sp)
/*  f0f5b20:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f5b24:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f0f5b28:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f0f5b2c:	afb001cc */ 	sw	$s0,0x1cc($sp)
/*  f0f5b30:	0fc54d8a */ 	jal	func0f153628
/*  f0f5b34:	afb201d0 */ 	sw	$s2,0x1d0($sp)
/*  f0f5b38:	8fad01f4 */ 	lw	$t5,0x1f4($sp)
/*  f0f5b3c:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f5b40:	afa001b0 */ 	sw	$zero,0x1b0($sp)
/*  f0f5b44:	11a00003 */ 	beqz	$t5,.L0f0f5b54
/*  f0f5b48:	3c0e8007 */ 	lui	$t6,%hi(var800714c8)
/*  f0f5b4c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0f5b50:	afab01b0 */ 	sw	$t3,0x1b0($sp)
.L0f0f5b54:
/*  f0f5b54:	25ce14c8 */ 	addiu	$t6,$t6,%lo(var800714c8)
/*  f0f5b58:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0f5b5c:	8fa301ec */ 	lw	$v1,0x1ec($sp)
/*  f0f5b60:	27b40154 */ 	addiu	$s4,$sp,0x154
/*  f0f5b64:	ae810000 */ 	sw	$at,0x0($s4)
/*  f0f5b68:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f0f5b6c:	ae990004 */ 	sw	$t9,0x4($s4)
/*  f0f5b70:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f0f5b74:	ae810008 */ 	sw	$at,0x8($s4)
/*  f0f5b78:	8dd9000c */ 	lw	$t9,0xc($t6)
/*  f0f5b7c:	3c0e7f1b */ 	lui	$t6,%hi(g_MenuColourPalettes)
/*  f0f5b80:	25ce1fb0 */ 	addiu	$t6,$t6,%lo(g_MenuColourPalettes)
/*  f0f5b84:	ae99000c */ 	sw	$t9,0xc($s4)
/*  f0f5b88:	c4680040 */ 	lwc1	$f8,0x40($v1)
/*  f0f5b8c:	4614403c */ 	c.lt.s	$f8,$f20
/*  f0f5b90:	00000000 */ 	nop
/*  f0f5b94:	4502000b */ 	bc1fl	.L0f0f5bc4
/*  f0f5b98:	906c003d */ 	lbu	$t4,0x3d($v1)
/*  f0f5b9c:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0f5ba0:	3c0b7f1b */ 	lui	$t3,%hi(g_MenuColourPalettes+0xc)
/*  f0f5ba4:	000f6900 */ 	sll	$t5,$t7,0x4
/*  f0f5ba8:	01af6823 */ 	subu	$t5,$t5,$t7
/*  f0f5bac:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f5bb0:	016d5821 */ 	addu	$t3,$t3,$t5
/*  f0f5bb4:	8d6b1fbc */ 	lw	$t3,%lo(g_MenuColourPalettes+0xc)($t3)
/*  f0f5bb8:	10000011 */ 	b	.L0f0f5c00
/*  f0f5bbc:	afab01bc */ 	sw	$t3,0x1bc($sp)
/*  f0f5bc0:	906c003d */ 	lbu	$t4,0x3d($v1)
.L0f0f5bc4:
/*  f0f5bc4:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0f5bc8:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0f5bcc:	000cc100 */ 	sll	$t8,$t4,0x4
/*  f0f5bd0:	000f6900 */ 	sll	$t5,$t7,0x4
/*  f0f5bd4:	030cc023 */ 	subu	$t8,$t8,$t4
/*  f0f5bd8:	01af6823 */ 	subu	$t5,$t5,$t7
/*  f0f5bdc:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f5be0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f5be4:	030ec821 */ 	addu	$t9,$t8,$t6
/*  f0f5be8:	01ae5821 */ 	addu	$t3,$t5,$t6
/*  f0f5bec:	8d65000c */ 	lw	$a1,0xc($t3)
/*  f0f5bf0:	0fc01a40 */ 	jal	colourBlend
/*  f0f5bf4:	8f24000c */ 	lw	$a0,0xc($t9)
/*  f0f5bf8:	afa201bc */ 	sw	$v0,0x1bc($sp)
/*  f0f5bfc:	8fa301ec */ 	lw	$v1,0x1ec($sp)
.L0f0f5c00:
/*  f0f5c00:	9062003c */ 	lbu	$v0,0x3c($v1)
/*  f0f5c04:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes3+0xc)
/*  f0f5c08:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes2+0xc)
/*  f0f5c0c:	00026100 */ 	sll	$t4,$v0,0x4
/*  f0f5c10:	01826023 */ 	subu	$t4,$t4,$v0
/*  f0f5c14:	000c1080 */ 	sll	$v0,$t4,0x2
/*  f0f5c18:	00822021 */ 	addu	$a0,$a0,$v0
/*  f0f5c1c:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f0f5c20:	8ca52124 */ 	lw	$a1,%lo(g_MenuColourPalettes2+0xc)($a1)
/*  f0f5c24:	0fc54f8e */ 	jal	func0f153e38
/*  f0f5c28:	8c84228c */ 	lw	$a0,%lo(g_MenuColourPalettes3+0xc)($a0)
/*  f0f5c2c:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
/*  f0f5c30:	8fa501dc */ 	lw	$a1,0x1dc($sp)
/*  f0f5c34:	24630003 */ 	addiu	$v1,$v1,0x3
/*  f0f5c38:	24a50003 */ 	addiu	$a1,$a1,0x3
/*  f0f5c3c:	afa501cc */ 	sw	$a1,0x1cc($sp)
/*  f0f5c40:	0c002f06 */ 	jal	viGetY
/*  f0f5c44:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f5c48:	8faf01bc */ 	lw	$t7,0x1bc($sp)
/*  f0f5c4c:	3c118008 */ 	lui	$s1,%hi(var8007fb10)
/*  f0f5c50:	3c138008 */ 	lui	$s3,%hi(var8007fb0c)
/*  f0f5c54:	2673fb0c */ 	addiu	$s3,$s3,%lo(var8007fb0c)
/*  f0f5c58:	2631fb10 */ 	addiu	$s1,$s1,%lo(var8007fb10)
/*  f0f5c5c:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0f5c60:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f0f5c64:	87ae01ca */ 	lh	$t6,0x1ca($sp)
/*  f0f5c68:	31ed00ff */ 	andi	$t5,$t7,0xff
/*  f0f5c6c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0f5c70:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5c74:	27a501d0 */ 	addiu	$a1,$sp,0x1d0
/*  f0f5c78:	27a601cc */ 	addiu	$a2,$sp,0x1cc
/*  f0f5c7c:	02e03825 */ 	or	$a3,$s7,$zero
/*  f0f5c80:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f5c84:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f5c88:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f5c8c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f5c90:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0f5c94:	0fc5580f */ 	jal	textRenderWhite
/*  f0f5c98:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0f5c9c:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f5ca0:	afb201d0 */ 	sw	$s2,0x1d0($sp)
/*  f0f5ca4:	0c002f06 */ 	jal	viGetY
/*  f0f5ca8:	afb001cc */ 	sw	$s0,0x1cc($sp)
/*  f0f5cac:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f0f5cb0:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f0f5cb4:	8fb801bc */ 	lw	$t8,0x1bc($sp)
/*  f0f5cb8:	87b901ca */ 	lh	$t9,0x1ca($sp)
/*  f0f5cbc:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5cc0:	27a501d0 */ 	addiu	$a1,$sp,0x1d0
/*  f0f5cc4:	27a601cc */ 	addiu	$a2,$sp,0x1cc
/*  f0f5cc8:	02e03825 */ 	or	$a3,$s7,$zero
/*  f0f5ccc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f5cd0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f5cd4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f5cd8:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f5cdc:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0f5ce0:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0f5ce4:	0fc5580f */ 	jal	textRenderWhite
/*  f0f5ce8:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0f5cec:	3c03800a */ 	lui	$v1,%hi(g_MenuData+0x4)
/*  f0f5cf0:	8c6319c4 */ 	lw	$v1,%lo(g_MenuData+0x4)($v1)
/*  f0f5cf4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f5cf8:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f5cfc:	10610007 */ 	beq	$v1,$at,.L0f0f5d1c
/*  f0f5d00:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f5d04:	10610005 */ 	beq	$v1,$at,.L0f0f5d1c
/*  f0f5d08:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f5d0c:	10610003 */ 	beq	$v1,$at,.L0f0f5d1c
/*  f0f5d10:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0f5d14:	1461001b */ 	bne	$v1,$at,.L0f0f5d84
/*  f0f5d18:	00000000 */ 	nop
.L0f0f5d1c:
/*  f0f5d1c:	8fa30088 */ 	lw	$v1,0x88($sp)
/*  f0f5d20:	afb001cc */ 	sw	$s0,0x1cc($sp)
/*  f0f5d24:	2463fff7 */ 	addiu	$v1,$v1,-9
/*  f0f5d28:	0c002f06 */ 	jal	viGetY
/*  f0f5d2c:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f5d30:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f0f5d34:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f0f5d38:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f0f5d3c:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f0f5d40:	000f6880 */ 	sll	$t5,$t7,0x2
/*  f0f5d44:	028d7021 */ 	addu	$t6,$s4,$t5
/*  f0f5d48:	8dc70000 */ 	lw	$a3,0x0($t6)
/*  f0f5d4c:	8fb801bc */ 	lw	$t8,0x1bc($sp)
/*  f0f5d50:	87b901ca */ 	lh	$t9,0x1ca($sp)
/*  f0f5d54:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f5d58:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f5d5c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f5d60:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5d64:	27a501d0 */ 	addiu	$a1,$sp,0x1d0
/*  f0f5d68:	27a601cc */ 	addiu	$a2,$sp,0x1cc
/*  f0f5d6c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f5d70:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0f5d74:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0f5d78:	0fc5580f */ 	jal	textRenderWhite
/*  f0f5d7c:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0f5d80:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f5d84:
/*  f0f5d84:	0fc54de0 */ 	jal	func0f153780
/*  f0f5d88:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5d8c:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f5d90:
/*  f0f5d90:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f5d94:	8fb501dc */ 	lw	$s5,0x1dc($sp)
/*  f0f5d98:	3c0f800a */ 	lui	$t7,%hi(g_MenuData+0x4)
/*  f0f5d9c:	c4400048 */ 	lwc1	$f0,0x48($v0)
/*  f0f5da0:	26b5000b */ 	addiu	$s5,$s5,0xb
/*  f0f5da4:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0f5da8:	00000000 */ 	nop
/*  f0f5dac:	4503001b */ 	bc1tl	.L0f0f5e1c
/*  f0f5db0:	904b0060 */ 	lbu	$t3,0x60($v0)
/*  f0f5db4:	8def19c4 */ 	lw	$t7,%lo(g_MenuData+0x4)($t7)
/*  f0f5db8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f5dbc:	51e1001e */ 	beql	$t7,$at,.L0f0f5e38
/*  f0f5dc0:	8fac0084 */ 	lw	$t4,0x84($sp)
/*  f0f5dc4:	904d0060 */ 	lbu	$t5,0x60($v0)
/*  f0f5dc8:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f5dcc:	29a10003 */ 	slti	$at,$t5,0x3
/*  f0f5dd0:	54200009 */ 	bnezl	$at,.L0f0f5df8
/*  f0f5dd4:	44060000 */ 	mfc1	$a2,$f0
/*  f0f5dd8:	44060000 */ 	mfc1	$a2,$f0
/*  f0f5ddc:	8c440014 */ 	lw	$a0,0x14($v0)
/*  f0f5de0:	8c450018 */ 	lw	$a1,0x18($v0)
/*  f0f5de4:	0fc54f08 */ 	jal	func0f153c20
/*  f0f5de8:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0f5dec:	10000006 */ 	b	.L0f0f5e08
/*  f0f5df0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0f5df4:	44060000 */ 	mfc1	$a2,$f0
.L0f0f5df8:
/*  f0f5df8:	8c440014 */ 	lw	$a0,0x14($v0)
/*  f0f5dfc:	0fc54f08 */ 	jal	func0f153c20
/*  f0f5e00:	8c450018 */ 	lw	$a1,0x18($v0)
/*  f0f5e04:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f0f5e08:
/*  f0f5e08:	3c018008 */ 	lui	$at,%hi(var8007fb9c)
/*  f0f5e0c:	ac2efb9c */ 	sw	$t6,%lo(var8007fb9c)($at)
/*  f0f5e10:	10000008 */ 	b	.L0f0f5e34
/*  f0f5e14:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f5e18:	904b0060 */ 	lbu	$t3,0x60($v0)
.L0f0f5e1c:
/*  f0f5e1c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f5e20:	55610005 */ 	bnel	$t3,$at,.L0f0f5e38
/*  f0f5e24:	8fac0084 */ 	lw	$t4,0x84($sp)
/*  f0f5e28:	0fc54f62 */ 	jal	func0f153d88
/*  f0f5e2c:	c44c0050 */ 	lwc1	$f12,0x50($v0)
/*  f0f5e30:	8fa201ec */ 	lw	$v0,0x1ec($sp)
.L0f0f5e34:
/*  f0f5e34:	8fac0084 */ 	lw	$t4,0x84($sp)
.L0f0f5e38:
/*  f0f5e38:	3c0b7f1b */ 	lui	$t3,%hi(g_MenuColourPalettes)
/*  f0f5e3c:	256b1fb0 */ 	addiu	$t3,$t3,%lo(g_MenuColourPalettes)
/*  f0f5e40:	0195082a */ 	slt	$at,$t4,$s5
/*  f0f5e44:	50200003 */ 	beqzl	$at,.L0f0f5e54
/*  f0f5e48:	c44a0040 */ 	lwc1	$f10,0x40($v0)
/*  f0f5e4c:	afb501d4 */ 	sw	$s5,0x1d4($sp)
/*  f0f5e50:	c44a0040 */ 	lwc1	$f10,0x40($v0)
.L0f0f5e54:
/*  f0f5e54:	4614503c */ 	c.lt.s	$f10,$f20
/*  f0f5e58:	00000000 */ 	nop
/*  f0f5e5c:	4502000b */ 	bc1fl	.L0f0f5e8c
/*  f0f5e60:	904d003d */ 	lbu	$t5,0x3d($v0)
/*  f0f5e64:	9058003c */ 	lbu	$t8,0x3c($v0)
/*  f0f5e68:	3c0f7f1b */ 	lui	$t7,%hi(g_MenuColourPalettes+0x10)
/*  f0f5e6c:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0f5e70:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f5e74:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f5e78:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f0f5e7c:	8def1fc0 */ 	lw	$t7,%lo(g_MenuColourPalettes+0x10)($t7)
/*  f0f5e80:	10000011 */ 	b	.L0f0f5ec8
/*  f0f5e84:	afaf01bc */ 	sw	$t7,0x1bc($sp)
/*  f0f5e88:	904d003d */ 	lbu	$t5,0x3d($v0)
.L0f0f5e8c:
/*  f0f5e8c:	9058003c */ 	lbu	$t8,0x3c($v0)
/*  f0f5e90:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f5e94:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f0f5e98:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0f5e9c:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0f5ea0:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f5ea4:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f5ea8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f5eac:	01cb6021 */ 	addu	$t4,$t6,$t3
/*  f0f5eb0:	032b7821 */ 	addu	$t7,$t9,$t3
/*  f0f5eb4:	8de50010 */ 	lw	$a1,0x10($t7)
/*  f0f5eb8:	0fc01a40 */ 	jal	colourBlend
/*  f0f5ebc:	8d840010 */ 	lw	$a0,0x10($t4)
/*  f0f5ec0:	afa201bc */ 	sw	$v0,0x1bc($sp)
/*  f0f5ec4:	8fa201ec */ 	lw	$v0,0x1ec($sp)
.L0f0f5ec8:
/*  f0f5ec8:	8c4d000c */ 	lw	$t5,0xc($v0)
/*  f0f5ecc:	8fa401bc */ 	lw	$a0,0x1bc($sp)
/*  f0f5ed0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f5ed4:	51a0000b */ 	beqzl	$t5,.L0f0f5f04
/*  f0f5ed8:	c4500040 */ 	lwc1	$f16,0x40($v0)
/*  f0f5edc:	0fc01a40 */ 	jal	colourBlend
/*  f0f5ee0:	2406002c */ 	addiu	$a2,$zero,0x2c
/*  f0f5ee4:	8fac01bc */ 	lw	$t4,0x1bc($sp)
/*  f0f5ee8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f5eec:	00417024 */ 	and	$t6,$v0,$at
/*  f0f5ef0:	319800ff */ 	andi	$t8,$t4,0xff
/*  f0f5ef4:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0f5ef8:	afb901bc */ 	sw	$t9,0x1bc($sp)
/*  f0f5efc:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f5f00:	c4500040 */ 	lwc1	$f16,0x40($v0)
.L0f0f5f04:
/*  f0f5f04:	3c187f1b */ 	lui	$t8,%hi(g_MenuColourPalettes)
/*  f0f5f08:	27181fb0 */ 	addiu	$t8,$t8,%lo(g_MenuColourPalettes)
/*  f0f5f0c:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0f5f10:	00000000 */ 	nop
/*  f0f5f14:	4502000b */ 	bc1fl	.L0f0f5f44
/*  f0f5f18:	904c003d */ 	lbu	$t4,0x3d($v0)
/*  f0f5f1c:	904b003c */ 	lbu	$t3,0x3c($v0)
/*  f0f5f20:	3c0d7f1b */ 	lui	$t5,%hi(g_MenuColourPalettes+0x14)
/*  f0f5f24:	000b7900 */ 	sll	$t7,$t3,0x4
/*  f0f5f28:	01eb7823 */ 	subu	$t7,$t7,$t3
/*  f0f5f2c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f5f30:	01af6821 */ 	addu	$t5,$t5,$t7
/*  f0f5f34:	8dad1fc4 */ 	lw	$t5,%lo(g_MenuColourPalettes+0x14)($t5)
/*  f0f5f38:	10000011 */ 	b	.L0f0f5f80
/*  f0f5f3c:	afad01b8 */ 	sw	$t5,0x1b8($sp)
/*  f0f5f40:	904c003d */ 	lbu	$t4,0x3d($v0)
.L0f0f5f44:
/*  f0f5f44:	904b003c */ 	lbu	$t3,0x3c($v0)
/*  f0f5f48:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f5f4c:	000c7100 */ 	sll	$t6,$t4,0x4
/*  f0f5f50:	000b7900 */ 	sll	$t7,$t3,0x4
/*  f0f5f54:	01cc7023 */ 	subu	$t6,$t6,$t4
/*  f0f5f58:	01eb7823 */ 	subu	$t7,$t7,$t3
/*  f0f5f5c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f5f60:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f5f64:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f0f5f68:	01f86821 */ 	addu	$t5,$t7,$t8
/*  f0f5f6c:	8da50014 */ 	lw	$a1,0x14($t5)
/*  f0f5f70:	0fc01a40 */ 	jal	colourBlend
/*  f0f5f74:	8f240014 */ 	lw	$a0,0x14($t9)
/*  f0f5f78:	afa201b8 */ 	sw	$v0,0x1b8($sp)
/*  f0f5f7c:	8fa201ec */ 	lw	$v0,0x1ec($sp)
.L0f0f5f80:
/*  f0f5f80:	8fac01f4 */ 	lw	$t4,0x1f4($sp)
/*  f0f5f84:	8fa901e0 */ 	lw	$t1,0x1e0($sp)
/*  f0f5f88:	5580008a */ 	bnezl	$t4,.L0f0f61b4
/*  f0f5f8c:	904d0060 */ 	lbu	$t5,0x60($v0)
/*  f0f5f90:	90430060 */ 	lbu	$v1,0x60($v0)
/*  f0f5f94:	87ae01ca */ 	lh	$t6,0x1ca($sp)
/*  f0f5f98:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f5f9c:	14610014 */ 	bne	$v1,$at,.L0f0f5ff0
/*  f0f5fa0:	01c94021 */ 	addu	$t0,$t6,$t1
/*  f0f5fa4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f5fa8:	44819000 */ 	mtc1	$at,$f18
/*  f0f5fac:	8fb901d4 */ 	lw	$t9,0x1d4($sp)
/*  f0f5fb0:	8fab01bc */ 	lw	$t3,0x1bc($sp)
/*  f0f5fb4:	8faf01b8 */ 	lw	$t7,0x1b8($sp)
/*  f0f5fb8:	25300001 */ 	addiu	$s0,$t1,0x1
/*  f0f5fbc:	2511ffff */ 	addiu	$s1,$t0,-1
/*  f0f5fc0:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f5fc4:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f5fc8:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5fcc:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f5fd0:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0f5fd4:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f5fd8:	e7b20020 */ 	swc1	$f18,0x20($sp)
/*  f0f5fdc:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f5fe0:	0fc3836b */ 	jal	func0f0e0dac
/*  f0f5fe4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0f5fe8:	10000027 */ 	b	.L0f0f6088
/*  f0f5fec:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f5ff0:
/*  f0f5ff0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f5ff4:	14610013 */ 	bne	$v1,$at,.L0f0f6044
/*  f0f5ff8:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f5ffc:	8fb801d4 */ 	lw	$t8,0x1d4($sp)
/*  f0f6000:	8fad01bc */ 	lw	$t5,0x1bc($sp)
/*  f0f6004:	8fac01b8 */ 	lw	$t4,0x1b8($sp)
/*  f0f6008:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0f600c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f6010:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0f6014:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0f6018:	c4440050 */ 	lwc1	$f4,0x50($v0)
/*  f0f601c:	25300001 */ 	addiu	$s0,$t1,0x1
/*  f0f6020:	2511ffff */ 	addiu	$s1,$t0,-1
/*  f0f6024:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f6028:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f602c:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6030:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f6034:	0fc3836b */ 	jal	func0f0e0dac
/*  f0f6038:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f0f603c:	10000012 */ 	b	.L0f0f6088
/*  f0f6040:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f6044:
/*  f0f6044:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0f6048:	44813000 */ 	mtc1	$at,$f6
/*  f0f604c:	8fae01d4 */ 	lw	$t6,0x1d4($sp)
/*  f0f6050:	8fb901bc */ 	lw	$t9,0x1bc($sp)
/*  f0f6054:	8fab01b8 */ 	lw	$t3,0x1b8($sp)
/*  f0f6058:	25300001 */ 	addiu	$s0,$t1,0x1
/*  f0f605c:	2511ffff */ 	addiu	$s1,$t0,-1
/*  f0f6060:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f6064:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f6068:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f606c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0f6070:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f6074:	e7a60020 */ 	swc1	$f6,0x20($sp)
/*  f0f6078:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0f607c:	0fc3836b */ 	jal	func0f0e0dac
/*  f0f6080:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0f6084:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f6088:
/*  f0f6088:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f608c:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f0f6090:	8df80010 */ 	lw	$t8,0x10($t7)
/*  f0f6094:	330d0100 */ 	andi	$t5,$t8,0x100
/*  f0f6098:	51a00046 */ 	beqzl	$t5,.L0f0f61b4
/*  f0f609c:	904d0060 */ 	lbu	$t5,0x60($v0)
/*  f0f60a0:	c4400040 */ 	lwc1	$f0,0x40($v0)
/*  f0f60a4:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0f60a8:	00000000 */ 	nop
/*  f0f60ac:	4502000b */ 	bc1fl	.L0f0f60dc
/*  f0f60b0:	904b003d */ 	lbu	$t3,0x3d($v0)
/*  f0f60b4:	904c003c */ 	lbu	$t4,0x3c($v0)
/*  f0f60b8:	3c197f1b */ 	lui	$t9,%hi(g_MenuColourPalettes)
/*  f0f60bc:	27391fb0 */ 	addiu	$t9,$t9,%lo(g_MenuColourPalettes)
/*  f0f60c0:	000c7100 */ 	sll	$t6,$t4,0x4
/*  f0f60c4:	01cc7023 */ 	subu	$t6,$t6,$t4
/*  f0f60c8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f60cc:	01d91821 */ 	addu	$v1,$t6,$t9
/*  f0f60d0:	1000001b */ 	b	.L0f0f6140
/*  f0f60d4:	8c720000 */ 	lw	$s2,0x0($v1)
/*  f0f60d8:	904b003d */ 	lbu	$t3,0x3d($v0)
.L0f0f60dc:
/*  f0f60dc:	904c003c */ 	lbu	$t4,0x3c($v0)
/*  f0f60e0:	3c187f1b */ 	lui	$t8,%hi(g_MenuColourPalettes)
/*  f0f60e4:	000b7900 */ 	sll	$t7,$t3,0x4
/*  f0f60e8:	000c7100 */ 	sll	$t6,$t4,0x4
/*  f0f60ec:	27181fb0 */ 	addiu	$t8,$t8,%lo(g_MenuColourPalettes)
/*  f0f60f0:	01eb7823 */ 	subu	$t7,$t7,$t3
/*  f0f60f4:	01cc7023 */ 	subu	$t6,$t6,$t4
/*  f0f60f8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f60fc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f6100:	01f86821 */ 	addu	$t5,$t7,$t8
/*  f0f6104:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f0f6108:	8f250000 */ 	lw	$a1,0x0($t9)
/*  f0f610c:	8da40000 */ 	lw	$a0,0x0($t5)
/*  f0f6110:	0fc01a40 */ 	jal	colourBlend
/*  f0f6114:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f6118:	00409025 */ 	or	$s2,$v0,$zero
/*  f0f611c:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f6120:	3c0c7f1b */ 	lui	$t4,%hi(g_MenuColourPalettes)
/*  f0f6124:	258c1fb0 */ 	addiu	$t4,$t4,%lo(g_MenuColourPalettes)
/*  f0f6128:	904f003c */ 	lbu	$t7,0x3c($v0)
/*  f0f612c:	c4400040 */ 	lwc1	$f0,0x40($v0)
/*  f0f6130:	000f6900 */ 	sll	$t5,$t7,0x4
/*  f0f6134:	01af6823 */ 	subu	$t5,$t5,$t7
/*  f0f6138:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f613c:	01ac1821 */ 	addu	$v1,$t5,$t4
.L0f0f6140:
/*  f0f6140:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0f6144:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes+0x8)
/*  f0f6148:	45020004 */ 	bc1fl	.L0f0f615c
/*  f0f614c:	904e003d */ 	lbu	$t6,0x3d($v0)
/*  f0f6150:	1000000b */ 	b	.L0f0f6180
/*  f0f6154:	8c680008 */ 	lw	$t0,0x8($v1)
/*  f0f6158:	904e003d */ 	lbu	$t6,0x3d($v0)
.L0f0f615c:
/*  f0f615c:	8c650008 */ 	lw	$a1,0x8($v1)
/*  f0f6160:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f6164:	000ec100 */ 	sll	$t8,$t6,0x4
/*  f0f6168:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f0f616c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f6170:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0f6174:	0fc01a40 */ 	jal	colourBlend
/*  f0f6178:	8c841fb8 */ 	lw	$a0,%lo(g_MenuColourPalettes+0x8)($a0)
/*  f0f617c:	00404025 */ 	or	$t0,$v0,$zero
.L0f0f6180:
/*  f0f6180:	8fb901dc */ 	lw	$t9,0x1dc($sp)
/*  f0f6184:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6188:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f618c:	272f000c */ 	addiu	$t7,$t9,0xc
/*  f0f6190:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0f6194:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f6198:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f619c:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f0f61a0:	0fc38bba */ 	jal	func0f0e2ee8
/*  f0f61a4:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0f61a8:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f61ac:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f61b0:	904d0060 */ 	lbu	$t5,0x60($v0)
.L0f0f61b4:
/*  f0f61b4:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
/*  f0f61b8:	87ac01ca */ 	lh	$t4,0x1ca($sp)
/*  f0f61bc:	15a00003 */ 	bnez	$t5,.L0f0f61cc
/*  f0f61c0:	24720002 */ 	addiu	$s2,$v1,0x2
/*  f0f61c4:	100004ab */ 	b	.L0f0f7474
/*  f0f61c8:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f61cc:
/*  f0f61cc:	01835821 */ 	addu	$t3,$t4,$v1
/*  f0f61d0:	0c002f40 */ 	jal	viGetViewLeft
/*  f0f61d4:	afab0088 */ 	sw	$t3,0x88($sp)
/*  f0f61d8:	3c0e8008 */ 	lui	$t6,%hi(g_ScreenWidthMultiplier)
/*  f0f61dc:	8dcefac0 */ 	lw	$t6,%lo(g_ScreenWidthMultiplier)($t6)
/*  f0f61e0:	004e001a */ 	div	$zero,$v0,$t6
/*  f0f61e4:	00009812 */ 	mflo	$s3
/*  f0f61e8:	15c00002 */ 	bnez	$t6,.L0f0f61f4
/*  f0f61ec:	00000000 */ 	nop
/*  f0f61f0:	0007000d */ 	break	0x7
.L0f0f61f4:
/*  f0f61f4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f61f8:	15c10004 */ 	bne	$t6,$at,.L0f0f620c
/*  f0f61fc:	3c018000 */ 	lui	$at,0x8000
/*  f0f6200:	14410002 */ 	bne	$v0,$at,.L0f0f620c
/*  f0f6204:	00000000 */ 	nop
/*  f0f6208:	0006000d */ 	break	0x6
.L0f0f620c:
/*  f0f620c:	0c002f44 */ 	jal	viGetViewTop
/*  f0f6210:	00000000 */ 	nop
/*  f0f6214:	0c002f40 */ 	jal	viGetViewLeft
/*  f0f6218:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0f621c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f6220:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f0f6224:	0c002f22 */ 	jal	viGetViewX
/*  f0f6228:	03008025 */ 	or	$s0,$t8,$zero
/*  f0f622c:	3c0f8008 */ 	lui	$t7,%hi(g_ScreenWidthMultiplier)
/*  f0f6230:	8deffac0 */ 	lw	$t7,%lo(g_ScreenWidthMultiplier)($t7)
/*  f0f6234:	0050c821 */ 	addu	$t9,$v0,$s0
/*  f0f6238:	032f001a */ 	div	$zero,$t9,$t7
/*  f0f623c:	00008812 */ 	mflo	$s1
/*  f0f6240:	15e00002 */ 	bnez	$t7,.L0f0f624c
/*  f0f6244:	00000000 */ 	nop
/*  f0f6248:	0007000d */ 	break	0x7
.L0f0f624c:
/*  f0f624c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f6250:	15e10004 */ 	bne	$t7,$at,.L0f0f6264
/*  f0f6254:	3c018000 */ 	lui	$at,0x8000
/*  f0f6258:	17210002 */ 	bne	$t9,$at,.L0f0f6264
/*  f0f625c:	00000000 */ 	nop
/*  f0f6260:	0006000d */ 	break	0x6
.L0f0f6264:
/*  f0f6264:	0c002f44 */ 	jal	viGetViewTop
/*  f0f6268:	00000000 */ 	nop
/*  f0f626c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f6270:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f0f6274:	0c002f26 */ 	jal	viGetViewY
/*  f0f6278:	01a08025 */ 	or	$s0,$t5,$zero
/*  f0f627c:	8fac0088 */ 	lw	$t4,0x88($sp)
/*  f0f6280:	3c08800a */ 	lui	$t0,%hi(var800a2038)
/*  f0f6284:	25082038 */ 	addiu	$t0,$t0,%lo(var800a2038)
/*  f0f6288:	3c0a800a */ 	lui	$t2,%hi(var800a203c)
/*  f0f628c:	ad120000 */ 	sw	$s2,0x0($t0)
/*  f0f6290:	3c01800a */ 	lui	$at,%hi(var800a203c)
/*  f0f6294:	258bfffe */ 	addiu	$t3,$t4,-2
/*  f0f6298:	254a203c */ 	addiu	$t2,$t2,%lo(var800a203c)
/*  f0f629c:	ac2b203c */ 	sw	$t3,%lo(var800a203c)($at)
/*  f0f62a0:	8fae01d4 */ 	lw	$t6,0x1d4($sp)
/*  f0f62a4:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f0f62a8:	3c03800a */ 	lui	$v1,%hi(var800a2044)
/*  f0f62ac:	3c09800a */ 	lui	$t1,%hi(var800a2040)
/*  f0f62b0:	25292040 */ 	addiu	$t1,$t1,%lo(var800a2040)
/*  f0f62b4:	24632044 */ 	addiu	$v1,$v1,%lo(var800a2044)
/*  f0f62b8:	25d8ffff */ 	addiu	$t8,$t6,-1
/*  f0f62bc:	0093082a */ 	slt	$at,$a0,$s3
/*  f0f62c0:	ad350000 */ 	sw	$s5,0x0($t1)
/*  f0f62c4:	10200003 */ 	beqz	$at,.L0f0f62d4
/*  f0f62c8:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f0f62cc:	10000469 */ 	b	.L0f0f7474
/*  f0f62d0:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f62d4:
/*  f0f62d4:	8c650000 */ 	lw	$a1,0x0($v1)
/*  f0f62d8:	00b4082a */ 	slt	$at,$a1,$s4
/*  f0f62dc:	50200004 */ 	beqzl	$at,.L0f0f62f0
/*  f0f62e0:	8d060000 */ 	lw	$a2,0x0($t0)
/*  f0f62e4:	10000463 */ 	b	.L0f0f7474
/*  f0f62e8:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
/*  f0f62ec:	8d060000 */ 	lw	$a2,0x0($t0)
.L0f0f62f0:
/*  f0f62f0:	0226082a */ 	slt	$at,$s1,$a2
/*  f0f62f4:	50200004 */ 	beqzl	$at,.L0f0f6308
/*  f0f62f8:	8d270000 */ 	lw	$a3,0x0($t1)
/*  f0f62fc:	1000045d */ 	b	.L0f0f7474
/*  f0f6300:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
/*  f0f6304:	8d270000 */ 	lw	$a3,0x0($t1)
.L0f0f6308:
/*  f0f6308:	00501821 */ 	addu	$v1,$v0,$s0
/*  f0f630c:	0067082a */ 	slt	$at,$v1,$a3
/*  f0f6310:	50200004 */ 	beqzl	$at,.L0f0f6324
/*  f0f6314:	0224082a */ 	slt	$at,$s1,$a0
/*  f0f6318:	10000456 */ 	b	.L0f0f7474
/*  f0f631c:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
/*  f0f6320:	0224082a */ 	slt	$at,$s1,$a0
.L0f0f6324:
/*  f0f6324:	50200004 */ 	beqzl	$at,.L0f0f6338
/*  f0f6328:	0065082a */ 	slt	$at,$v1,$a1
/*  f0f632c:	ad510000 */ 	sw	$s1,0x0($t2)
/*  f0f6330:	02202025 */ 	or	$a0,$s1,$zero
/*  f0f6334:	0065082a */ 	slt	$at,$v1,$a1
.L0f0f6338:
/*  f0f6338:	10200004 */ 	beqz	$at,.L0f0f634c
/*  f0f633c:	3c01800a */ 	lui	$at,%hi(var800a2044)
/*  f0f6340:	ac232044 */ 	sw	$v1,%lo(var800a2044)($at)
/*  f0f6344:	3c05800a */ 	lui	$a1,%hi(var800a2044)
/*  f0f6348:	8ca52044 */ 	lw	$a1,%lo(var800a2044)($a1)
.L0f0f634c:
/*  f0f634c:	00d3082a */ 	slt	$at,$a2,$s3
/*  f0f6350:	50200003 */ 	beqzl	$at,.L0f0f6360
/*  f0f6354:	0094082a */ 	slt	$at,$a0,$s4
/*  f0f6358:	ad130000 */ 	sw	$s3,0x0($t0)
/*  f0f635c:	0094082a */ 	slt	$at,$a0,$s4
.L0f0f6360:
/*  f0f6360:	10200002 */ 	beqz	$at,.L0f0f636c
/*  f0f6364:	00000000 */ 	nop
/*  f0f6368:	ad540000 */ 	sw	$s4,0x0($t2)
.L0f0f636c:
/*  f0f636c:	3c01800a */ 	lui	$at,%hi(var8009de90)
/*  f0f6370:	ac27de90 */ 	sw	$a3,%lo(var8009de90)($at)
/*  f0f6374:	3c01800a */ 	lui	$at,%hi(var8009de94)
/*  f0f6378:	ac25de94 */ 	sw	$a1,%lo(var8009de94)($at)
/*  f0f637c:	0fc3d43f */ 	jal	func0f0f50fc
/*  f0f6380:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6384:	3c198007 */ 	lui	$t9,%hi(g_MpPlayerNum)
/*  f0f6388:	8f391448 */ 	lw	$t9,%lo(g_MpPlayerNum)($t9)
/*  f0f638c:	3c0d800a */ 	lui	$t5,%hi(g_Menus)
/*  f0f6390:	25ade000 */ 	addiu	$t5,$t5,%lo(g_Menus)
/*  f0f6394:	001978c0 */ 	sll	$t7,$t9,0x3
/*  f0f6398:	01f97823 */ 	subu	$t7,$t7,$t9
/*  f0f639c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f63a0:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f0f63a4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f63a8:	01f97823 */ 	subu	$t7,$t7,$t9
/*  f0f63ac:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f63b0:	01ed1821 */ 	addu	$v1,$t7,$t5
/*  f0f63b4:	8fa701ec */ 	lw	$a3,0x1ec($sp)
/*  f0f63b8:	8c6c04f8 */ 	lw	$t4,0x4f8($v1)
/*  f0f63bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f63c0:	54ec0033 */ 	bnel	$a3,$t4,.L0f0f6490
/*  f0f63c4:	90f8003c */ 	lbu	$t8,0x3c($a3)
/*  f0f63c8:	8ceb0000 */ 	lw	$t3,0x0($a3)
/*  f0f63cc:	8fb901f4 */ 	lw	$t9,0x1f4($sp)
/*  f0f63d0:	8d6e0010 */ 	lw	$t6,0x10($t3)
/*  f0f63d4:	31d80002 */ 	andi	$t8,$t6,0x2
/*  f0f63d8:	5300002d */ 	beqzl	$t8,.L0f0f6490
/*  f0f63dc:	90f8003c */ 	lbu	$t8,0x3c($a3)
/*  f0f63e0:	5720002b */ 	bnezl	$t9,.L0f0f6490
/*  f0f63e4:	90f8003c */ 	lbu	$t8,0x3c($a3)
/*  f0f63e8:	8c6f0df0 */ 	lw	$t7,0xdf0($v1)
/*  f0f63ec:	3c0bb700 */ 	lui	$t3,0xb700
/*  f0f63f0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0f63f4:	000f6380 */ 	sll	$t4,$t7,0xe
/*  f0f63f8:	05800024 */ 	bltz	$t4,.L0f0f648c
/*  f0f63fc:	3c188007 */ 	lui	$t8,%hi(g_MpPlayerNum)
/*  f0f6400:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f0f6404:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0f6408:	8f181448 */ 	lw	$t8,%lo(g_MpPlayerNum)($t8)
/*  f0f640c:	3c0d800a */ 	lui	$t5,%hi(g_Menus)
/*  f0f6410:	25ade000 */ 	addiu	$t5,$t5,%lo(g_Menus)
/*  f0f6414:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0f6418:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f641c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f6420:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0f6424:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0f6428:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f642c:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0f6430:	272f0840 */ 	addiu	$t7,$t9,0x840
/*  f0f6434:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0f6438:	01ed2821 */ 	addu	$a1,$t7,$t5
/*  f0f643c:	0fc3ce2c */ 	jal	func0f0f38b0
/*  f0f6440:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f6444:	244c0008 */ 	addiu	$t4,$v0,0x8
/*  f0f6448:	afac01e8 */ 	sw	$t4,0x1e8($sp)
/*  f0f644c:	3c0bb600 */ 	lui	$t3,0xb600
/*  f0f6450:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0f6454:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0f6458:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f0f645c:	8fd00284 */ 	lw	$s0,0x284($s8)
/*  f0f6460:	86040634 */ 	lh	$a0,0x634($s0)
/*  f0f6464:	0c002f2a */ 	jal	viSetViewPosition
/*  f0f6468:	86050636 */ 	lh	$a1,0x636($s0)
/*  f0f646c:	8fd00284 */ 	lw	$s0,0x284($s8)
/*  f0f6470:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f0f6474:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f0f6478:	86060630 */ 	lh	$a2,0x630($s0)
/*  f0f647c:	0c002f76 */ 	jal	viSetFovAspectAndSize
/*  f0f6480:	86070632 */ 	lh	$a3,0x632($s0)
/*  f0f6484:	8fa701ec */ 	lw	$a3,0x1ec($sp)
/*  f0f6488:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
.L0f0f648c:
/*  f0f648c:	90f8003c */ 	lbu	$t8,0x3c($a3)
.L0f0f6490:
/*  f0f6490:	57000008 */ 	bnezl	$t8,.L0f0f64b4
/*  f0f6494:	8fb901e0 */ 	lw	$t9,0x1e0($sp)
/*  f0f6498:	c4e80040 */ 	lwc1	$f8,0x40($a3)
/*  f0f649c:	00809825 */ 	or	$s3,$a0,$zero
/*  f0f64a0:	4608a03e */ 	c.le.s	$f20,$f8
/*  f0f64a4:	00000000 */ 	nop
/*  f0f64a8:	45020292 */ 	bc1fl	.L0f0f6ef4
/*  f0f64ac:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0f64b0:	8fb901e0 */ 	lw	$t9,0x1e0($sp)
.L0f0f64b4:
/*  f0f64b4:	afa00130 */ 	sw	$zero,0x130($sp)
/*  f0f64b8:	afa001e4 */ 	sw	$zero,0x1e4($sp)
/*  f0f64bc:	afa401e8 */ 	sw	$a0,0x1e8($sp)
/*  f0f64c0:	afb90194 */ 	sw	$t9,0x194($sp)
/*  f0f64c4:	90ef0005 */ 	lbu	$t7,0x5($a3)
/*  f0f64c8:	59e001e7 */ 	blezl	$t7,.L0f0f6c68
/*  f0f64cc:	8fad01f4 */ 	lw	$t5,0x1f4($sp)
/*  f0f64d0:	afa401e8 */ 	sw	$a0,0x1e8($sp)
.L0f0f64d4:
/*  f0f64d4:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f64d8:	8fad01dc */ 	lw	$t5,0x1dc($sp)
/*  f0f64dc:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes+0x18)
/*  f0f64e0:	8c4c0064 */ 	lw	$t4,0x64($v0)
/*  f0f64e4:	afa00128 */ 	sw	$zero,0x128($sp)
/*  f0f64e8:	01ac5821 */ 	addu	$t3,$t5,$t4
/*  f0f64ec:	256e000c */ 	addiu	$t6,$t3,0xc
/*  f0f64f0:	afae012c */ 	sw	$t6,0x12c($sp)
/*  f0f64f4:	9058003c */ 	lbu	$t8,0x3c($v0)
/*  f0f64f8:	afa001c0 */ 	sw	$zero,0x1c0($sp)
/*  f0f64fc:	c44a0040 */ 	lwc1	$f10,0x40($v0)
/*  f0f6500:	0018c900 */ 	sll	$t9,$t8,0x4
/*  f0f6504:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f6508:	4614503c */ 	c.lt.s	$f10,$f20
/*  f0f650c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f6510:	00b92821 */ 	addu	$a1,$a1,$t9
/*  f0f6514:	8ca51fc8 */ 	lw	$a1,%lo(g_MenuColourPalettes+0x18)($a1)
/*  f0f6518:	45020005 */ 	bc1fl	.L0f0f6530
/*  f0f651c:	904f003d */ 	lbu	$t7,0x3d($v0)
/*  f0f6520:	afa50120 */ 	sw	$a1,0x120($sp)
/*  f0f6524:	1000000d */ 	b	.L0f0f655c
/*  f0f6528:	90430004 */ 	lbu	$v1,0x4($v0)
/*  f0f652c:	904f003d */ 	lbu	$t7,0x3d($v0)
.L0f0f6530:
/*  f0f6530:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes+0x18)
/*  f0f6534:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f0f6538:	000f6900 */ 	sll	$t5,$t7,0x4
/*  f0f653c:	01af6823 */ 	subu	$t5,$t5,$t7
/*  f0f6540:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f6544:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f0f6548:	0fc01a40 */ 	jal	colourBlend
/*  f0f654c:	8c841fc8 */ 	lw	$a0,%lo(g_MenuColourPalettes+0x18)($a0)
/*  f0f6550:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f0f6554:	8fa201ec */ 	lw	$v0,0x1ec($sp)
/*  f0f6558:	90430004 */ 	lbu	$v1,0x4($v0)
.L0f0f655c:
/*  f0f655c:	8fab0120 */ 	lw	$t3,0x120($sp)
/*  f0f6560:	8fb901e4 */ 	lw	$t9,0x1e4($sp)
/*  f0f6564:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f6568:	01617024 */ 	and	$t6,$t3,$at
/*  f0f656c:	35d8003f */ 	ori	$t8,$t6,0x3f
/*  f0f6570:	afb80120 */ 	sw	$t8,0x120($sp)
/*  f0f6574:	13200010 */ 	beqz	$t9,.L0f0f65b8
/*  f0f6578:	00798021 */ 	addu	$s0,$v1,$t9
/*  f0f657c:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f0f6580:	8fa70194 */ 	lw	$a3,0x194($sp)
/*  f0f6584:	8fa601dc */ 	lw	$a2,0x1dc($sp)
/*  f0f6588:	8ded0010 */ 	lw	$t5,0x10($t7)
/*  f0f658c:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6590:	24e5ffff */ 	addiu	$a1,$a3,-1
/*  f0f6594:	31ac0400 */ 	andi	$t4,$t5,0x400
/*  f0f6598:	15800007 */ 	bnez	$t4,.L0f0f65b8
/*  f0f659c:	24c6000c */ 	addiu	$a2,$a2,0xc
/*  f0f65a0:	8fab01d4 */ 	lw	$t3,0x1d4($sp)
/*  f0f65a4:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f65a8:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0f65ac:	0fc38bd7 */ 	jal	renderFilledRect
/*  f0f65b0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f65b4:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f65b8:
/*  f0f65b8:	8fae01f0 */ 	lw	$t6,0x1f0($sp)
/*  f0f65bc:	0010c880 */ 	sll	$t9,$s0,0x2
/*  f0f65c0:	0330c821 */ 	addu	$t9,$t9,$s0
/*  f0f65c4:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f0f65c8:	01d92821 */ 	addu	$a1,$t6,$t9
/*  f0f65cc:	84a40660 */ 	lh	$a0,0x660($a1)
/*  f0f65d0:	8faf0130 */ 	lw	$t7,0x130($sp)
/*  f0f65d4:	8fb801ec */ 	lw	$t8,0x1ec($sp)
/*  f0f65d8:	8fab01e4 */ 	lw	$t3,0x1e4($sp)
/*  f0f65dc:	01e46021 */ 	addu	$t4,$t7,$a0
/*  f0f65e0:	afac0130 */ 	sw	$t4,0x130($sp)
/*  f0f65e4:	afa40124 */ 	sw	$a0,0x124($sp)
/*  f0f65e8:	93030005 */ 	lbu	$v1,0x5($t8)
/*  f0f65ec:	256e0001 */ 	addiu	$t6,$t3,0x1
/*  f0f65f0:	8fb90088 */ 	lw	$t9,0x88($sp)
/*  f0f65f4:	15c30009 */ 	bne	$t6,$v1,.L0f0f661c
/*  f0f65f8:	00806825 */ 	or	$t5,$a0,$zero
/*  f0f65fc:	8faf01e0 */ 	lw	$t7,0x1e0($sp)
/*  f0f6600:	032f1023 */ 	subu	$v0,$t9,$t7
/*  f0f6604:	2442fffe */ 	addiu	$v0,$v0,-2
/*  f0f6608:	0182082a */ 	slt	$at,$t4,$v0
/*  f0f660c:	10200003 */ 	beqz	$at,.L0f0f661c
/*  f0f6610:	01a2c021 */ 	addu	$t8,$t5,$v0
/*  f0f6614:	030c5823 */ 	subu	$t3,$t8,$t4
/*  f0f6618:	afab0124 */ 	sw	$t3,0x124($sp)
.L0f0f661c:
/*  f0f661c:	90ae0668 */ 	lbu	$t6,0x668($a1)
/*  f0f6620:	8fb901dc */ 	lw	$t9,0x1dc($sp)
/*  f0f6624:	19c00187 */ 	blez	$t6,.L0f0f6c44
/*  f0f6628:	272f000c */ 	addiu	$t7,$t9,0xc
/*  f0f662c:	afaf0084 */ 	sw	$t7,0x84($sp)
/*  f0f6630:	afa50080 */ 	sw	$a1,0x80($sp)
/*  f0f6634:	8fb80080 */ 	lw	$t8,0x80($sp)
.L0f0f6638:
/*  f0f6638:	afa00114 */ 	sw	$zero,0x114($sp)
/*  f0f663c:	8fab01c0 */ 	lw	$t3,0x1c0($sp)
/*  f0f6640:	970c0666 */ 	lhu	$t4,0x666($t8)
/*  f0f6644:	8fae01f0 */ 	lw	$t6,0x1f0($sp)
/*  f0f6648:	8fad01ec */ 	lw	$t5,0x1ec($sp)
/*  f0f664c:	018b1821 */ 	addu	$v1,$t4,$t3
/*  f0f6650:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f0f6654:	01d91021 */ 	addu	$v0,$t6,$t9
/*  f0f6658:	904f04fe */ 	lbu	$t7,0x4fe($v0)
/*  f0f665c:	8dac0000 */ 	lw	$t4,0x0($t5)
/*  f0f6660:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f6664:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0f6668:	8d8b0008 */ 	lw	$t3,0x8($t4)
/*  f0f666c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f6670:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f6674:	030b3021 */ 	addu	$a2,$t8,$t3
/*  f0f6678:	afa60118 */ 	sw	$a2,0x118($sp)
/*  f0f667c:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f0f6680:	8dae0008 */ 	lw	$t6,0x8($t5)
/*  f0f6684:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f6688:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f668c:	54ce0008 */ 	bnel	$a2,$t6,.L0f0f66b0
/*  f0f6690:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*  f0f6694:	afb90114 */ 	sw	$t9,0x114($sp)
/*  f0f6698:	8daf000c */ 	lw	$t7,0xc($t5)
/*  f0f669c:	240c0003 */ 	addiu	$t4,$zero,0x3
/*  f0f66a0:	51e00003 */ 	beqzl	$t7,.L0f0f66b0
/*  f0f66a4:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*  f0f66a8:	afac0114 */ 	sw	$t4,0x114($sp)
/*  f0f66ac:	8fb8007c */ 	lw	$t8,0x7c($sp)
.L0f0f66b0:
/*  f0f66b0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f66b4:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f0f66b8:	830204ff */ 	lb	$v0,0x4ff($t8)
/*  f0f66bc:	8fab01f0 */ 	lw	$t3,0x1f0($sp)
/*  f0f66c0:	8fb90194 */ 	lw	$t9,0x194($sp)
/*  f0f66c4:	10410003 */ 	beq	$v0,$at,.L0f0f66d4
/*  f0f66c8:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0f66cc:	016e2821 */ 	addu	$a1,$t3,$t6
/*  f0f66d0:	24a506dc */ 	addiu	$a1,$a1,0x6dc
.L0f0f66d4:
/*  f0f66d4:	8fad0124 */ 	lw	$t5,0x124($sp)
/*  f0f66d8:	8faf007c */ 	lw	$t7,0x7c($sp)
/*  f0f66dc:	a7b90198 */ 	sh	$t9,0x198($sp)
/*  f0f66e0:	a7a3019a */ 	sh	$v1,0x19a($sp)
/*  f0f66e4:	a7ad019c */ 	sh	$t5,0x19c($sp)
/*  f0f66e8:	85ec04fc */ 	lh	$t4,0x4fc($t7)
/*  f0f66ec:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f0f66f0:	00031400 */ 	sll	$v0,$v1,0x10
/*  f0f66f4:	0002c403 */ 	sra	$t8,$v0,0x10
/*  f0f66f8:	030c5821 */ 	addu	$t3,$t8,$t4
/*  f0f66fc:	016e082a */ 	slt	$at,$t3,$t6
/*  f0f6700:	03001025 */ 	or	$v0,$t8,$zero
/*  f0f6704:	10200002 */ 	beqz	$at,.L0f0f6710
/*  f0f6708:	a7ac019e */ 	sh	$t4,0x19e($sp)
/*  f0f670c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0f6710:
/*  f0f6710:	8fb901d4 */ 	lw	$t9,0x1d4($sp)
/*  f0f6714:	87ad019e */ 	lh	$t5,0x19e($sp)
/*  f0f6718:	8faf0118 */ 	lw	$t7,0x118($sp)
/*  f0f671c:	0322082a */ 	slt	$at,$t9,$v0
/*  f0f6720:	10200002 */ 	beqz	$at,.L0f0f672c
/*  f0f6724:	00000000 */ 	nop
/*  f0f6728:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0f672c:
/*  f0f672c:	15a00002 */ 	bnez	$t5,.L0f0f6738
/*  f0f6730:	00000000 */ 	nop
/*  f0f6734:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0f6738:
/*  f0f6738:	54800133 */ 	bnezl	$a0,.L0f0f6c08
/*  f0f673c:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f0f6740:	8fab0128 */ 	lw	$t3,0x128($sp)
/*  f0f6744:	8fb80114 */ 	lw	$t8,0x114($sp)
/*  f0f6748:	8fac01ec */ 	lw	$t4,0x1ec($sp)
/*  f0f674c:	afaf01a0 */ 	sw	$t7,0x1a0($sp)
/*  f0f6750:	afa501ac */ 	sw	$a1,0x1ac($sp)
/*  f0f6754:	afb801a4 */ 	sw	$t8,0x1a4($sp)
/*  f0f6758:	1160000e */ 	beqz	$t3,.L0f0f6794
/*  f0f675c:	afac01a8 */ 	sw	$t4,0x1a8($sp)
/*  f0f6760:	8fa30120 */ 	lw	$v1,0x120($sp)
/*  f0f6764:	87b00196 */ 	lh	$s0,0x196($sp)
/*  f0f6768:	87ae0126 */ 	lh	$t6,0x126($sp)
/*  f0f676c:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6770:	2446ffff */ 	addiu	$a2,$v0,-1
/*  f0f6774:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0f6778:	afa00128 */ 	sw	$zero,0x128($sp)
/*  f0f677c:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0f6780:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0f6784:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f6788:	0fc38bd7 */ 	jal	renderFilledRect
/*  f0f678c:	020e3821 */ 	addu	$a3,$s0,$t6
/*  f0f6790:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f6794:
/*  f0f6794:	8fb90118 */ 	lw	$t9,0x118($sp)
/*  f0f6798:	8fb801f4 */ 	lw	$t8,0x1f4($sp)
/*  f0f679c:	8f2d0004 */ 	lw	$t5,0x4($t9)
/*  f0f67a0:	31af4000 */ 	andi	$t7,$t5,0x4000
/*  f0f67a4:	51e00046 */ 	beqzl	$t7,.L0f0f68c0
/*  f0f67a8:	8fb90114 */ 	lw	$t9,0x114($sp)
/*  f0f67ac:	17000043 */ 	bnez	$t8,.L0f0f68bc
/*  f0f67b0:	8fad01ec */ 	lw	$t5,0x1ec($sp)
/*  f0f67b4:	c5b00040 */ 	lwc1	$f16,0x40($t5)
/*  f0f67b8:	87b00198 */ 	lh	$s0,0x198($sp)
/*  f0f67bc:	87ae019c */ 	lh	$t6,0x19c($sp)
/*  f0f67c0:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0f67c4:	87b1019a */ 	lh	$s1,0x19a($sp)
/*  f0f67c8:	87b9019e */ 	lh	$t9,0x19e($sp)
/*  f0f67cc:	01d09021 */ 	addu	$s2,$t6,$s0
/*  f0f67d0:	8fae01ec */ 	lw	$t6,0x1ec($sp)
/*  f0f67d4:	45000009 */ 	bc1f	.L0f0f67fc
/*  f0f67d8:	03319821 */ 	addu	$s3,$t9,$s1
/*  f0f67dc:	91af003c */ 	lbu	$t7,0x3c($t5)
/*  f0f67e0:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes+0x28)
/*  f0f67e4:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f0f67e8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f67ec:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f67f0:	00982021 */ 	addu	$a0,$a0,$t8
/*  f0f67f4:	10000011 */ 	b	.L0f0f683c
/*  f0f67f8:	8c841fd8 */ 	lw	$a0,%lo(g_MenuColourPalettes+0x28)($a0)
.L0f0f67fc:
/*  f0f67fc:	91cc003d */ 	lbu	$t4,0x3d($t6)
/*  f0f6800:	2402003c */ 	addiu	$v0,$zero,0x3c
/*  f0f6804:	91cd003c */ 	lbu	$t5,0x3c($t6)
/*  f0f6808:	01820019 */ 	multu	$t4,$v0
/*  f0f680c:	3c037f1b */ 	lui	$v1,%hi(g_MenuColourPalettes)
/*  f0f6810:	24631fb0 */ 	addiu	$v1,$v1,%lo(g_MenuColourPalettes)
/*  f0f6814:	8dc60044 */ 	lw	$a2,0x44($t6)
/*  f0f6818:	0000c812 */ 	mflo	$t9
/*  f0f681c:	00795821 */ 	addu	$t3,$v1,$t9
/*  f0f6820:	8d640028 */ 	lw	$a0,0x28($t3)
/*  f0f6824:	01a20019 */ 	multu	$t5,$v0
/*  f0f6828:	00007812 */ 	mflo	$t7
/*  f0f682c:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f0f6830:	0fc01a40 */ 	jal	colourBlend
/*  f0f6834:	8f050028 */ 	lw	$a1,0x28($t8)
/*  f0f6838:	00402025 */ 	or	$a0,$v0,$zero
.L0f0f683c:
/*  f0f683c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f6840:	00812824 */ 	and	$a1,$a0,$at
/*  f0f6844:	0fc01a40 */ 	jal	colourBlend
/*  f0f6848:	2406007f */ 	addiu	$a2,$zero,0x7f
/*  f0f684c:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6850:	0fc54df7 */ 	jal	func0f1537dc
/*  f0f6854:	00402825 */ 	or	$a1,$v0,$zero
/*  f0f6858:	3c038008 */ 	lui	$v1,%hi(g_ScreenWidthMultiplier)
/*  f0f685c:	2463fac0 */ 	addiu	$v1,$v1,%lo(g_ScreenWidthMultiplier)
/*  f0f6860:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0f6864:	3c01f600 */ 	lui	$at,0xf600
/*  f0f6868:	327803ff */ 	andi	$t8,$s3,0x3ff
/*  f0f686c:	024c0019 */ 	multu	$s2,$t4
/*  f0f6870:	00187080 */ 	sll	$t6,$t8,0x2
/*  f0f6874:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0f6878:	0000c812 */ 	mflo	$t9
/*  f0f687c:	332b03ff */ 	andi	$t3,$t9,0x3ff
/*  f0f6880:	000b6b80 */ 	sll	$t5,$t3,0xe
/*  f0f6884:	01a17825 */ 	or	$t7,$t5,$at
/*  f0f6888:	01ee6025 */ 	or	$t4,$t7,$t6
/*  f0f688c:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0f6890:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0f6894:	322f03ff */ 	andi	$t7,$s1,0x3ff
/*  f0f6898:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f0f689c:	02190019 */ 	multu	$s0,$t9
/*  f0f68a0:	00005812 */ 	mflo	$t3
/*  f0f68a4:	316d03ff */ 	andi	$t5,$t3,0x3ff
/*  f0f68a8:	000dc380 */ 	sll	$t8,$t5,0xe
/*  f0f68ac:	030e6025 */ 	or	$t4,$t8,$t6
/*  f0f68b0:	0fc54e0e */ 	jal	func0f153838
/*  f0f68b4:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f0f68b8:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f68bc:
/*  f0f68bc:	8fb90114 */ 	lw	$t9,0x114($sp)
.L0f0f68c0:
/*  f0f68c0:	8fab0118 */ 	lw	$t3,0x118($sp)
/*  f0f68c4:	532000c0 */ 	beqzl	$t9,.L0f0f6bc8
/*  f0f68c8:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f68cc:	91620000 */ 	lbu	$v0,0x0($t3)
/*  f0f68d0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f68d4:	8fad01ec */ 	lw	$t5,0x1ec($sp)
/*  f0f68d8:	1041000b */ 	beq	$v0,$at,.L0f0f6908
/*  f0f68dc:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f68e0:	10410009 */ 	beq	$v0,$at,.L0f0f6908
/*  f0f68e4:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0f68e8:	10410007 */ 	beq	$v0,$at,.L0f0f6908
/*  f0f68ec:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0f68f0:	10410005 */ 	beq	$v0,$at,.L0f0f6908
/*  f0f68f4:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0f68f8:	10410003 */ 	beq	$v0,$at,.L0f0f6908
/*  f0f68fc:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0f6900:	54410015 */ 	bnel	$v0,$at,.L0f0f6958
/*  f0f6904:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0f6908:
/*  f0f6908:	c5a00040 */ 	lwc1	$f0,0x40($t5)
/*  f0f690c:	4600a03e */ 	c.le.s	$f20,$f0
/*  f0f6910:	00000000 */ 	nop
/*  f0f6914:	45020005 */ 	bc1fl	.L0f0f692c
/*  f0f6918:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0f691c:	91af003d */ 	lbu	$t7,0x3d($t5)
/*  f0f6920:	51e0000d */ 	beqzl	$t7,.L0f0f6958
/*  f0f6924:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f6928:	4614003c */ 	c.lt.s	$f0,$f20
.L0f0f692c:
/*  f0f692c:	8fb801ec */ 	lw	$t8,0x1ec($sp)
/*  f0f6930:	45000004 */ 	bc1f	.L0f0f6944
/*  f0f6934:	00000000 */ 	nop
/*  f0f6938:	930e003c */ 	lbu	$t6,0x3c($t8)
/*  f0f693c:	51c00006 */ 	beqzl	$t6,.L0f0f6958
/*  f0f6940:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0f6944:
/*  f0f6944:	0fc55809 */ 	jal	func0f156024
/*  f0f6948:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0f694c:	8fac0118 */ 	lw	$t4,0x118($sp)
/*  f0f6950:	91820000 */ 	lbu	$v0,0x0($t4)
/*  f0f6954:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0f6958:
/*  f0f6958:	10410008 */ 	beq	$v0,$at,.L0f0f697c
/*  f0f695c:	87a3019c */ 	lh	$v1,0x19c($sp)
/*  f0f6960:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0f6964:	10410005 */ 	beq	$v0,$at,.L0f0f697c
/*  f0f6968:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0f696c:	10410003 */ 	beq	$v0,$at,.L0f0f697c
/*  f0f6970:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0f6974:	54410094 */ 	bnel	$v0,$at,.L0f0f6bc8
/*  f0f6978:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
.L0f0f697c:
/*  f0f697c:	87ab019e */ 	lh	$t3,0x19e($sp)
/*  f0f6980:	8fb70120 */ 	lw	$s7,0x120($sp)
/*  f0f6984:	87a20198 */ 	lh	$v0,0x198($sp)
/*  f0f6988:	87b9019a */ 	lh	$t9,0x19a($sp)
/*  f0f698c:	05610003 */ 	bgez	$t3,.L0f0f699c
/*  f0f6990:	000b6843 */ 	sra	$t5,$t3,0x1
/*  f0f6994:	25610001 */ 	addiu	$at,$t3,0x1
/*  f0f6998:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f699c:
/*  f0f699c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f69a0:	0061001a */ 	div	$zero,$v1,$at
/*  f0f69a4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0f69a8:	02e1c024 */ 	and	$t8,$s7,$at
/*  f0f69ac:	00007812 */ 	mflo	$t7
/*  f0f69b0:	370e002f */ 	ori	$t6,$t8,0x2f
/*  f0f69b4:	032d8021 */ 	addu	$s0,$t9,$t5
/*  f0f69b8:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f0f69bc:	afae0078 */ 	sw	$t6,0x78($sp)
/*  f0f69c0:	0300b825 */ 	or	$s7,$t8,$zero
/*  f0f69c4:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f69c8:	0040a025 */ 	or	$s4,$v0,$zero
/*  f0f69cc:	24510008 */ 	addiu	$s1,$v0,0x8
/*  f0f69d0:	0fc38926 */ 	jal	func0f0e2498
/*  f0f69d4:	004ff021 */ 	addu	$s8,$v0,$t7
/*  f0f69d8:	8fa30120 */ 	lw	$v1,0x120($sp)
/*  f0f69dc:	2615ffff */ 	addiu	$s5,$s0,-1
/*  f0f69e0:	2632fffd */ 	addiu	$s2,$s1,-3
/*  f0f69e4:	02403825 */ 	or	$a3,$s2,$zero
/*  f0f69e8:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f69ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f69f0:	02802825 */ 	or	$a1,$s4,$zero
/*  f0f69f4:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0f69f8:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f69fc:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0f6a00:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6a04:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0f6a08:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f0f6a0c:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0f6a10:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f6a14:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6a18:	02402825 */ 	or	$a1,$s2,$zero
/*  f0f6a1c:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f6a20:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f6a24:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0f6a28:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6a2c:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6a30:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0f6a34:	8fa30120 */ 	lw	$v1,0x120($sp)
/*  f0f6a38:	26130001 */ 	addiu	$s3,$s0,0x1
/*  f0f6a3c:	26160002 */ 	addiu	$s6,$s0,0x2
/*  f0f6a40:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f0f6a44:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f6a48:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6a4c:	02802825 */ 	or	$a1,$s4,$zero
/*  f0f6a50:	02403825 */ 	or	$a3,$s2,$zero
/*  f0f6a54:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6a58:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0f6a5c:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6a60:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0f6a64:	8fb90120 */ 	lw	$t9,0x120($sp)
/*  f0f6a68:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0f6a6c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0f6a70:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6a74:	02402825 */ 	or	$a1,$s2,$zero
/*  f0f6a78:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f6a7c:	02203825 */ 	or	$a3,$s1,$zero
/*  f0f6a80:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f0f6a84:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6a88:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6a8c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0f6a90:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f0f6a94:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6a98:	2625fffe */ 	addiu	$a1,$s1,-2
/*  f0f6a9c:	02003025 */ 	or	$a2,$s0,$zero
/*  f0f6aa0:	03c03825 */ 	or	$a3,$s8,$zero
/*  f0f6aa4:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f6aa8:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f0f6aac:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6ab0:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6ab4:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0f6ab8:	8fb80118 */ 	lw	$t8,0x118($sp)
/*  f0f6abc:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f6ac0:	87a20198 */ 	lh	$v0,0x198($sp)
/*  f0f6ac4:	8f0e0004 */ 	lw	$t6,0x4($t8)
/*  f0f6ac8:	87a3019c */ 	lh	$v1,0x19c($sp)
/*  f0f6acc:	8fa80120 */ 	lw	$t0,0x120($sp)
/*  f0f6ad0:	31cc0020 */ 	andi	$t4,$t6,0x20
/*  f0f6ad4:	1180003b */ 	beqz	$t4,.L0f0f6bc4
/*  f0f6ad8:	00433821 */ 	addu	$a3,$v0,$v1
/*  f0f6adc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f6ae0:	0061001a */ 	div	$zero,$v1,$at
/*  f0f6ae4:	00005812 */ 	mflo	$t3
/*  f0f6ae8:	00e0a025 */ 	or	$s4,$a3,$zero
/*  f0f6aec:	24f1fff8 */ 	addiu	$s1,$a3,-8
/*  f0f6af0:	00ebf023 */ 	subu	$s8,$a3,$t3
/*  f0f6af4:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6af8:	24e5fffb */ 	addiu	$a1,$a3,-5
/*  f0f6afc:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f6b00:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0f6b04:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f0f6b08:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0f6b0c:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6b10:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6b14:	8fad0120 */ 	lw	$t5,0x120($sp)
/*  f0f6b18:	26320003 */ 	addiu	$s2,$s1,0x3
/*  f0f6b1c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0f6b20:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0f6b24:	02403825 */ 	or	$a3,$s2,$zero
/*  f0f6b28:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6b2c:	02202825 */ 	or	$a1,$s1,$zero
/*  f0f6b30:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0f6b34:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0f6b38:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6b3c:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6b40:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0f6b44:	8faf0120 */ 	lw	$t7,0x120($sp)
/*  f0f6b48:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6b4c:	02402825 */ 	or	$a1,$s2,$zero
/*  f0f6b50:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f6b54:	02803825 */ 	or	$a3,$s4,$zero
/*  f0f6b58:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f0f6b5c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6b60:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0f6b64:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6b68:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0f6b6c:	8fae0120 */ 	lw	$t6,0x120($sp)
/*  f0f6b70:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0f6b74:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f6b78:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6b7c:	02202825 */ 	or	$a1,$s1,$zero
/*  f0f6b80:	02603025 */ 	or	$a2,$s3,$zero
/*  f0f6b84:	02403825 */ 	or	$a3,$s2,$zero
/*  f0f6b88:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f0f6b8c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6b90:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6b94:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0f6b98:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f0f6b9c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f6ba0:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0f6ba4:	02003025 */ 	or	$a2,$s0,$zero
/*  f0f6ba8:	26270002 */ 	addiu	$a3,$s1,0x2
/*  f0f6bac:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0f6bb0:	afb70014 */ 	sw	$s7,0x14($sp)
/*  f0f6bb4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f6bb8:	0fc38963 */ 	jal	func0f0e258c
/*  f0f6bbc:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0f6bc0:	afa201e8 */ 	sw	$v0,0x1e8($sp)
.L0f0f6bc4:
/*  f0f6bc4:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
.L0f0f6bc8:
/*  f0f6bc8:	0fc3c167 */ 	jal	menuRenderItem
/*  f0f6bcc:	27a50198 */ 	addiu	$a1,$sp,0x198
/*  f0f6bd0:	8fab0118 */ 	lw	$t3,0x118($sp)
/*  f0f6bd4:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f6bd8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f6bdc:	91790000 */ 	lbu	$t9,0x0($t3)
/*  f0f6be0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0f6be4:	57210003 */ 	bnel	$t9,$at,.L0f0f6bf4
/*  f0f6be8:	8faf0114 */ 	lw	$t7,0x114($sp)
/*  f0f6bec:	afad0128 */ 	sw	$t5,0x128($sp)
/*  f0f6bf0:	8faf0114 */ 	lw	$t7,0x114($sp)
.L0f0f6bf4:
/*  f0f6bf4:	51e00004 */ 	beqzl	$t7,.L0f0f6c08
/*  f0f6bf8:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f0f6bfc:	0fc55809 */ 	jal	func0f156024
/*  f0f6c00:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f6c04:	8fae007c */ 	lw	$t6,0x7c($sp)
.L0f0f6c08:
/*  f0f6c08:	8fb901c0 */ 	lw	$t9,0x1c0($sp)
/*  f0f6c0c:	8fb8012c */ 	lw	$t8,0x12c($sp)
/*  f0f6c10:	85cc04fc */ 	lh	$t4,0x4fc($t6)
/*  f0f6c14:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f0f6c18:	272d0001 */ 	addiu	$t5,$t9,0x1
/*  f0f6c1c:	030c5821 */ 	addu	$t3,$t8,$t4
/*  f0f6c20:	afad01c0 */ 	sw	$t5,0x1c0($sp)
/*  f0f6c24:	afab012c */ 	sw	$t3,0x12c($sp)
/*  f0f6c28:	904f0668 */ 	lbu	$t7,0x668($v0)
/*  f0f6c2c:	01af082a */ 	slt	$at,$t5,$t7
/*  f0f6c30:	5420fe81 */ 	bnezl	$at,.L0f0f6638
/*  f0f6c34:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f0f6c38:	8fae01ec */ 	lw	$t6,0x1ec($sp)
/*  f0f6c3c:	84440660 */ 	lh	$a0,0x660($v0)
/*  f0f6c40:	91c30005 */ 	lbu	$v1,0x5($t6)
.L0f0f6c44:
/*  f0f6c44:	8fab01e4 */ 	lw	$t3,0x1e4($sp)
/*  f0f6c48:	8fb80194 */ 	lw	$t8,0x194($sp)
/*  f0f6c4c:	25790001 */ 	addiu	$t9,$t3,0x1
/*  f0f6c50:	0323082a */ 	slt	$at,$t9,$v1
/*  f0f6c54:	03046021 */ 	addu	$t4,$t8,$a0
/*  f0f6c58:	afb901e4 */ 	sw	$t9,0x1e4($sp)
/*  f0f6c5c:	1420fe1d */ 	bnez	$at,.L0f0f64d4
/*  f0f6c60:	afac0194 */ 	sw	$t4,0x194($sp)
/*  f0f6c64:	8fad01f4 */ 	lw	$t5,0x1f4($sp)
.L0f0f6c68:
/*  f0f6c68:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6c6c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0f6c70:	15a00061 */ 	bnez	$t5,.L0f0f6df8
/*  f0f6c74:	8faf01e0 */ 	lw	$t7,0x1e0($sp)
/*  f0f6c78:	afaf0194 */ 	sw	$t7,0x194($sp)
/*  f0f6c7c:	0fc54df7 */ 	jal	func0f1537dc
/*  f0f6c80:	afa001e4 */ 	sw	$zero,0x1e4($sp)
/*  f0f6c84:	8fae01ec */ 	lw	$t6,0x1ec($sp)
/*  f0f6c88:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f6c8c:	91c30005 */ 	lbu	$v1,0x5($t6)
/*  f0f6c90:	18600055 */ 	blez	$v1,.L0f0f6de8
/*  f0f6c94:	00000000 */ 	nop
.L0f0f6c98:
/*  f0f6c98:	8fac01ec */ 	lw	$t4,0x1ec($sp)
/*  f0f6c9c:	8fad01e4 */ 	lw	$t5,0x1e4($sp)
/*  f0f6ca0:	8fb801dc */ 	lw	$t8,0x1dc($sp)
/*  f0f6ca4:	91990004 */ 	lbu	$t9,0x4($t4)
/*  f0f6ca8:	8d8b0064 */ 	lw	$t3,0x64($t4)
/*  f0f6cac:	8faf01f0 */ 	lw	$t7,0x1f0($sp)
/*  f0f6cb0:	032d8021 */ 	addu	$s0,$t9,$t5
/*  f0f6cb4:	00107080 */ 	sll	$t6,$s0,0x2
/*  f0f6cb8:	01d07021 */ 	addu	$t6,$t6,$s0
/*  f0f6cbc:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f0f6cc0:	030b8821 */ 	addu	$s1,$t8,$t3
/*  f0f6cc4:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f0f6cc8:	afb80080 */ 	sw	$t8,0x80($sp)
/*  f0f6ccc:	afa001c0 */ 	sw	$zero,0x1c0($sp)
/*  f0f6cd0:	930b0668 */ 	lbu	$t3,0x668($t8)
/*  f0f6cd4:	2631000c */ 	addiu	$s1,$s1,0xc
/*  f0f6cd8:	87b00196 */ 	lh	$s0,0x196($sp)
/*  f0f6cdc:	59600039 */ 	blezl	$t3,.L0f0f6dc4
/*  f0f6ce0:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f0f6ce4:	8fac0080 */ 	lw	$t4,0x80($sp)
.L0f0f6ce8:
/*  f0f6ce8:	8fad01c0 */ 	lw	$t5,0x1c0($sp)
/*  f0f6cec:	8faf01f0 */ 	lw	$t7,0x1f0($sp)
/*  f0f6cf0:	95990666 */ 	lhu	$t9,0x666($t4)
/*  f0f6cf4:	8fac01ec */ 	lw	$t4,0x1ec($sp)
/*  f0f6cf8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f6cfc:	032d1821 */ 	addu	$v1,$t9,$t5
/*  f0f6d00:	00037080 */ 	sll	$t6,$v1,0x2
/*  f0f6d04:	01ee2021 */ 	addu	$a0,$t7,$t6
/*  f0f6d08:	909804fe */ 	lbu	$t8,0x4fe($a0)
/*  f0f6d0c:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f0f6d10:	808204ff */ 	lb	$v0,0x4ff($a0)
/*  f0f6d14:	00185880 */ 	sll	$t3,$t8,0x2
/*  f0f6d18:	8f2d0008 */ 	lw	$t5,0x8($t9)
/*  f0f6d1c:	01785821 */ 	addu	$t3,$t3,$t8
/*  f0f6d20:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0f6d24:	00004025 */ 	or	$t0,$zero,$zero
/*  f0f6d28:	afa4007c */ 	sw	$a0,0x7c($sp)
/*  f0f6d2c:	10410005 */ 	beq	$v0,$at,.L0f0f6d44
/*  f0f6d30:	016d4821 */ 	addu	$t1,$t3,$t5
/*  f0f6d34:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0f6d38:	01ee4021 */ 	addu	$t0,$t7,$t6
/*  f0f6d3c:	250806dc */ 	addiu	$t0,$t0,0x6dc
/*  f0f6d40:	afa4007c */ 	sw	$a0,0x7c($sp)
.L0f0f6d44:
/*  f0f6d44:	8fb90080 */ 	lw	$t9,0x80($sp)
/*  f0f6d48:	8fab007c */ 	lw	$t3,0x7c($sp)
/*  f0f6d4c:	8faf01ec */ 	lw	$t7,0x1ec($sp)
/*  f0f6d50:	87270660 */ 	lh	$a3,0x660($t9)
/*  f0f6d54:	856d04fc */ 	lh	$t5,0x4fc($t3)
/*  f0f6d58:	00102c00 */ 	sll	$a1,$s0,0x10
/*  f0f6d5c:	00113400 */ 	sll	$a2,$s1,0x10
/*  f0f6d60:	00066403 */ 	sra	$t4,$a2,0x10
/*  f0f6d64:	0005c403 */ 	sra	$t8,$a1,0x10
/*  f0f6d68:	03002825 */ 	or	$a1,$t8,$zero
/*  f0f6d6c:	01803025 */ 	or	$a2,$t4,$zero
/*  f0f6d70:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0f6d74:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0f6d78:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6d7c:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0f6d80:	0fc3c246 */ 	jal	func0f0f0918
/*  f0f6d84:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0f6d88:	8fac01c0 */ 	lw	$t4,0x1c0($sp)
/*  f0f6d8c:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f0f6d90:	8fab0080 */ 	lw	$t3,0x80($sp)
/*  f0f6d94:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f6d98:	85d804fc */ 	lh	$t8,0x4fc($t6)
/*  f0f6d9c:	25990001 */ 	addiu	$t9,$t4,0x1
/*  f0f6da0:	afb901c0 */ 	sw	$t9,0x1c0($sp)
/*  f0f6da4:	916d0668 */ 	lbu	$t5,0x668($t3)
/*  f0f6da8:	02388821 */ 	addu	$s1,$s1,$t8
/*  f0f6dac:	032d082a */ 	slt	$at,$t9,$t5
/*  f0f6db0:	5420ffcd */ 	bnezl	$at,.L0f0f6ce8
/*  f0f6db4:	8fac0080 */ 	lw	$t4,0x80($sp)
/*  f0f6db8:	8faf01ec */ 	lw	$t7,0x1ec($sp)
/*  f0f6dbc:	91e30005 */ 	lbu	$v1,0x5($t7)
/*  f0f6dc0:	8fb80080 */ 	lw	$t8,0x80($sp)
.L0f0f6dc4:
/*  f0f6dc4:	8fb901e4 */ 	lw	$t9,0x1e4($sp)
/*  f0f6dc8:	8fae0194 */ 	lw	$t6,0x194($sp)
/*  f0f6dcc:	870c0660 */ 	lh	$t4,0x660($t8)
/*  f0f6dd0:	272d0001 */ 	addiu	$t5,$t9,0x1
/*  f0f6dd4:	01a3082a */ 	slt	$at,$t5,$v1
/*  f0f6dd8:	01cc5821 */ 	addu	$t3,$t6,$t4
/*  f0f6ddc:	afad01e4 */ 	sw	$t5,0x1e4($sp)
/*  f0f6de0:	1420ffad */ 	bnez	$at,.L0f0f6c98
/*  f0f6de4:	afab0194 */ 	sw	$t3,0x194($sp)
.L0f0f6de8:
/*  f0f6de8:	0fc54e0e */ 	jal	func0f153838
/*  f0f6dec:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f6df0:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f6df4:	00402025 */ 	or	$a0,$v0,$zero
.L0f0f6df8:
/*  f0f6df8:	00809825 */ 	or	$s3,$a0,$zero
/*  f0f6dfc:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0f6e00:	0c002f40 */ 	jal	viGetViewLeft
/*  f0f6e04:	afa401e8 */ 	sw	$a0,0x1e8($sp)
/*  f0f6e08:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f6e0c:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f0f6e10:	0c002f44 */ 	jal	viGetViewTop
/*  f0f6e14:	01e08025 */ 	or	$s0,$t7,$zero
/*  f0f6e18:	44829000 */ 	mtc1	$v0,$f18
/*  f0f6e1c:	44905000 */ 	mtc1	$s0,$f10
/*  f0f6e20:	3c014080 */ 	lui	$at,0x4080
/*  f0f6e24:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0f6e28:	44810000 */ 	mtc1	$at,$f0
/*  f0f6e2c:	3c01ed00 */ 	lui	$at,0xed00
/*  f0f6e30:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0f6e34:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0f6e38:	00000000 */ 	nop
/*  f0f6e3c:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0f6e40:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0f6e44:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0f6e48:	440e4000 */ 	mfc1	$t6,$f8
/*  f0f6e4c:	440d2000 */ 	mfc1	$t5,$f4
/*  f0f6e50:	31cc0fff */ 	andi	$t4,$t6,0xfff
/*  f0f6e54:	01815825 */ 	or	$t3,$t4,$at
/*  f0f6e58:	31af0fff */ 	andi	$t7,$t5,0xfff
/*  f0f6e5c:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f0f6e60:	01787025 */ 	or	$t6,$t3,$t8
/*  f0f6e64:	0c002f22 */ 	jal	viGetViewX
/*  f0f6e68:	ae6e0000 */ 	sw	$t6,0x0($s3)
/*  f0f6e6c:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0f6e70:	00116403 */ 	sra	$t4,$s1,0x10
/*  f0f6e74:	0c002f40 */ 	jal	viGetViewLeft
/*  f0f6e78:	01808825 */ 	or	$s1,$t4,$zero
/*  f0f6e7c:	00029400 */ 	sll	$s2,$v0,0x10
/*  f0f6e80:	0012cc03 */ 	sra	$t9,$s2,0x10
/*  f0f6e84:	0c002f44 */ 	jal	viGetViewTop
/*  f0f6e88:	03209025 */ 	or	$s2,$t9,$zero
/*  f0f6e8c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f6e90:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f0f6e94:	0c002f26 */ 	jal	viGetViewY
/*  f0f6e98:	01a08025 */ 	or	$s0,$t5,$zero
/*  f0f6e9c:	00507821 */ 	addu	$t7,$v0,$s0
/*  f0f6ea0:	448f3000 */ 	mtc1	$t7,$f6
/*  f0f6ea4:	02516021 */ 	addu	$t4,$s2,$s1
/*  f0f6ea8:	448c9000 */ 	mtc1	$t4,$f18
/*  f0f6eac:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0f6eb0:	3c014080 */ 	lui	$at,0x4080
/*  f0f6eb4:	44810000 */ 	mtc1	$at,$f0
/*  f0f6eb8:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0f6ebc:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0f6ec0:	00000000 */ 	nop
/*  f0f6ec4:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0f6ec8:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0f6ecc:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0f6ed0:	44188000 */ 	mfc1	$t8,$f16
/*  f0f6ed4:	440d4000 */ 	mfc1	$t5,$f8
/*  f0f6ed8:	330e0fff */ 	andi	$t6,$t8,0xfff
/*  f0f6edc:	31af0fff */ 	andi	$t7,$t5,0xfff
/*  f0f6ee0:	000f5b00 */ 	sll	$t3,$t7,0xc
/*  f0f6ee4:	01cbc025 */ 	or	$t8,$t6,$t3
/*  f0f6ee8:	1000003e */ 	b	.L0f0f6fe4
/*  f0f6eec:	ae780004 */ 	sw	$t8,0x4($s3)
/*  f0f6ef0:	24840008 */ 	addiu	$a0,$a0,0x8
.L0f0f6ef4:
/*  f0f6ef4:	0c002f40 */ 	jal	viGetViewLeft
/*  f0f6ef8:	afa401e8 */ 	sw	$a0,0x1e8($sp)
/*  f0f6efc:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f6f00:	00106403 */ 	sra	$t4,$s0,0x10
/*  f0f6f04:	0c002f44 */ 	jal	viGetViewTop
/*  f0f6f08:	01808025 */ 	or	$s0,$t4,$zero
/*  f0f6f0c:	44825000 */ 	mtc1	$v0,$f10
/*  f0f6f10:	44903000 */ 	mtc1	$s0,$f6
/*  f0f6f14:	3c014080 */ 	lui	$at,0x4080
/*  f0f6f18:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0f6f1c:	44810000 */ 	mtc1	$at,$f0
/*  f0f6f20:	3c01ed00 */ 	lui	$at,0xed00
/*  f0f6f24:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0f6f28:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0f6f2c:	00000000 */ 	nop
/*  f0f6f30:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0f6f34:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0f6f38:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0f6f3c:	440d2000 */ 	mfc1	$t5,$f4
/*  f0f6f40:	44188000 */ 	mfc1	$t8,$f16
/*  f0f6f44:	31af0fff */ 	andi	$t7,$t5,0xfff
/*  f0f6f48:	01e17025 */ 	or	$t6,$t7,$at
/*  f0f6f4c:	330c0fff */ 	andi	$t4,$t8,0xfff
/*  f0f6f50:	000ccb00 */ 	sll	$t9,$t4,0xc
/*  f0f6f54:	01d96825 */ 	or	$t5,$t6,$t9
/*  f0f6f58:	0c002f22 */ 	jal	viGetViewX
/*  f0f6f5c:	ae6d0000 */ 	sw	$t5,0x0($s3)
/*  f0f6f60:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0f6f64:	00117c03 */ 	sra	$t7,$s1,0x10
/*  f0f6f68:	0c002f40 */ 	jal	viGetViewLeft
/*  f0f6f6c:	01e08825 */ 	or	$s1,$t7,$zero
/*  f0f6f70:	00029400 */ 	sll	$s2,$v0,0x10
/*  f0f6f74:	00125c03 */ 	sra	$t3,$s2,0x10
/*  f0f6f78:	0c002f44 */ 	jal	viGetViewTop
/*  f0f6f7c:	01609025 */ 	or	$s2,$t3,$zero
/*  f0f6f80:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f6f84:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f0f6f88:	0c002f26 */ 	jal	viGetViewY
/*  f0f6f8c:	03008025 */ 	or	$s0,$t8,$zero
/*  f0f6f90:	00506021 */ 	addu	$t4,$v0,$s0
/*  f0f6f94:	448c9000 */ 	mtc1	$t4,$f18
/*  f0f6f98:	02517821 */ 	addu	$t7,$s2,$s1
/*  f0f6f9c:	448f8000 */ 	mtc1	$t7,$f16
/*  f0f6fa0:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0f6fa4:	3c014080 */ 	lui	$at,0x4080
/*  f0f6fa8:	44813000 */ 	mtc1	$at,$f6
/*  f0f6fac:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0f6fb0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0f6fb4:	44812000 */ 	mtc1	$at,$f4
/*  f0f6fb8:	00000000 */ 	nop
/*  f0f6fbc:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0f6fc0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0f6fc4:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0f6fc8:	44195000 */ 	mfc1	$t9,$f10
/*  f0f6fcc:	44184000 */ 	mfc1	$t8,$f8
/*  f0f6fd0:	332d0fff */ 	andi	$t5,$t9,0xfff
/*  f0f6fd4:	330c0fff */ 	andi	$t4,$t8,0xfff
/*  f0f6fd8:	000c7300 */ 	sll	$t6,$t4,0xc
/*  f0f6fdc:	01aec825 */ 	or	$t9,$t5,$t6
/*  f0f6fe0:	ae790004 */ 	sw	$t9,0x4($s3)
.L0f0f6fe4:
/*  f0f6fe4:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f0f6fe8:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f0f6fec:	3c18800a */ 	lui	$t8,%hi(g_Menus)
/*  f0f6ff0:	2718e000 */ 	addiu	$t8,$t8,%lo(g_Menus)
/*  f0f6ff4:	000f58c0 */ 	sll	$t3,$t7,0x3
/*  f0f6ff8:	016f5823 */ 	subu	$t3,$t3,$t7
/*  f0f6ffc:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0f7000:	016f5821 */ 	addu	$t3,$t3,$t7
/*  f0f7004:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f0f7008:	016f5823 */ 	subu	$t3,$t3,$t7
/*  f0f700c:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f0f7010:	01781821 */ 	addu	$v1,$t3,$t8
/*  f0f7014:	846c04f4 */ 	lh	$t4,0x4f4($v1)
/*  f0f7018:	8fae01ec */ 	lw	$t6,0x1ec($sp)
/*  f0f701c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0f7020:	91d9003c */ 	lbu	$t9,0x3c($t6)
/*  f0f7024:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0f7028:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0f702c:	006d8821 */ 	addu	$s1,$v1,$t5
/*  f0f7030:	17200006 */ 	bnez	$t9,.L0f0f704c
/*  f0f7034:	2631044c */ 	addiu	$s1,$s1,0x44c
/*  f0f7038:	c5ca0040 */ 	lwc1	$f10,0x40($t6)
/*  f0f703c:	460aa03e */ 	c.le.s	$f20,$f10
/*  f0f7040:	00000000 */ 	nop
/*  f0f7044:	4502010b */ 	bc1fl	.L0f0f7474
/*  f0f7048:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f704c:
/*  f0f704c:	822b0015 */ 	lb	$t3,0x15($s1)
/*  f0f7050:	8faf01ec */ 	lw	$t7,0x1ec($sp)
/*  f0f7054:	000bc080 */ 	sll	$t8,$t3,0x2
/*  f0f7058:	02386021 */ 	addu	$t4,$s1,$t8
/*  f0f705c:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f0f7060:	55ed0104 */ 	bnel	$t7,$t5,.L0f0f7474
/*  f0f7064:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
/*  f0f7068:	82390014 */ 	lb	$t9,0x14($s1)
/*  f0f706c:	2b210002 */ 	slti	$at,$t9,0x2
/*  f0f7070:	142000ff */ 	bnez	$at,.L0f0f7470
/*  f0f7074:	3c014120 */ 	lui	$at,0x4120
/*  f0f7078:	44816000 */ 	mtc1	$at,$f12
/*  f0f707c:	0fc01ac2 */ 	jal	func0f006b08
/*  f0f7080:	00000000 */ 	nop
/*  f0f7084:	3c01437f */ 	lui	$at,0x437f
/*  f0f7088:	44818000 */ 	mtc1	$at,$f16
/*  f0f708c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0f7090:	3c014f00 */ 	lui	$at,0x4f00
/*  f0f7094:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f0f7098:	8fab01ec */ 	lw	$t3,0x1ec($sp)
/*  f0f709c:	8faf01ec */ 	lw	$t7,0x1ec($sp)
/*  f0f70a0:	444ef800 */ 	cfc1	$t6,$31
/*  f0f70a4:	44d0f800 */ 	ctc1	$s0,$31
/*  f0f70a8:	00000000 */ 	nop
/*  f0f70ac:	46009124 */ 	cvt.w.s	$f4,$f18
/*  f0f70b0:	4450f800 */ 	cfc1	$s0,$31
/*  f0f70b4:	00000000 */ 	nop
/*  f0f70b8:	32100078 */ 	andi	$s0,$s0,0x78
/*  f0f70bc:	52000013 */ 	beqzl	$s0,.L0f0f710c
/*  f0f70c0:	44102000 */ 	mfc1	$s0,$f4
/*  f0f70c4:	44812000 */ 	mtc1	$at,$f4
/*  f0f70c8:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0f70cc:	46049101 */ 	sub.s	$f4,$f18,$f4
/*  f0f70d0:	44d0f800 */ 	ctc1	$s0,$31
/*  f0f70d4:	00000000 */ 	nop
/*  f0f70d8:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0f70dc:	4450f800 */ 	cfc1	$s0,$31
/*  f0f70e0:	00000000 */ 	nop
/*  f0f70e4:	32100078 */ 	andi	$s0,$s0,0x78
/*  f0f70e8:	16000005 */ 	bnez	$s0,.L0f0f7100
/*  f0f70ec:	00000000 */ 	nop
/*  f0f70f0:	44102000 */ 	mfc1	$s0,$f4
/*  f0f70f4:	3c018000 */ 	lui	$at,0x8000
/*  f0f70f8:	10000007 */ 	b	.L0f0f7118
/*  f0f70fc:	02018025 */ 	or	$s0,$s0,$at
.L0f0f7100:
/*  f0f7100:	10000005 */ 	b	.L0f0f7118
/*  f0f7104:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f0f7108:	44102000 */ 	mfc1	$s0,$f4
.L0f0f710c:
/*  f0f710c:	00000000 */ 	nop
/*  f0f7110:	0600fffb */ 	bltz	$s0,.L0f0f7100
/*  f0f7114:	00000000 */ 	nop
.L0f0f7118:
/*  f0f7118:	44cef800 */ 	ctc1	$t6,$31
/*  f0f711c:	c5660040 */ 	lwc1	$f6,0x40($t3)
/*  f0f7120:	4614303c */ 	c.lt.s	$f6,$f20
/*  f0f7124:	00000000 */ 	nop
/*  f0f7128:	4502000a */ 	bc1fl	.L0f0f7154
/*  f0f712c:	91ed003d */ 	lbu	$t5,0x3d($t7)
/*  f0f7130:	9178003c */ 	lbu	$t8,0x3c($t3)
/*  f0f7134:	3c057f1b */ 	lui	$a1,%hi(g_MenuColourPalettes)
/*  f0f7138:	00186100 */ 	sll	$t4,$t8,0x4
/*  f0f713c:	01986023 */ 	subu	$t4,$t4,$t8
/*  f0f7140:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0f7144:	00ac2821 */ 	addu	$a1,$a1,$t4
/*  f0f7148:	10000011 */ 	b	.L0f0f7190
/*  f0f714c:	8ca51fb0 */ 	lw	$a1,%lo(g_MenuColourPalettes)($a1)
/*  f0f7150:	91ed003d */ 	lbu	$t5,0x3d($t7)
.L0f0f7154:
/*  f0f7154:	2402003c */ 	addiu	$v0,$zero,0x3c
/*  f0f7158:	91eb003c */ 	lbu	$t3,0x3c($t7)
/*  f0f715c:	01a20019 */ 	multu	$t5,$v0
/*  f0f7160:	3c037f1b */ 	lui	$v1,%hi(g_MenuColourPalettes)
/*  f0f7164:	24631fb0 */ 	addiu	$v1,$v1,%lo(g_MenuColourPalettes)
/*  f0f7168:	8de60044 */ 	lw	$a2,0x44($t7)
/*  f0f716c:	0000c812 */ 	mflo	$t9
/*  f0f7170:	00797021 */ 	addu	$t6,$v1,$t9
/*  f0f7174:	8dc40000 */ 	lw	$a0,0x0($t6)
/*  f0f7178:	01620019 */ 	multu	$t3,$v0
/*  f0f717c:	0000c012 */ 	mflo	$t8
/*  f0f7180:	00786021 */ 	addu	$t4,$v1,$t8
/*  f0f7184:	0fc01a40 */ 	jal	colourBlend
/*  f0f7188:	8d850000 */ 	lw	$a1,0x0($t4)
/*  f0f718c:	00402825 */ 	or	$a1,$v0,$zero
.L0f0f7190:
/*  f0f7190:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f0f7194:	0fc01a40 */ 	jal	colourBlend
/*  f0f7198:	02003025 */ 	or	$a2,$s0,$zero
/*  f0f719c:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0f71a0:	4481a000 */ 	mtc1	$at,$f20
/*  f0f71a4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0f71a8:	0fc01ac2 */ 	jal	func0f006b08
/*  f0f71ac:	4600a306 */ 	mov.s	$f12,$f20
/*  f0f71b0:	8fad01dc */ 	lw	$t5,0x1dc($sp)
/*  f0f71b4:	8fb901d4 */ 	lw	$t9,0x1d4($sp)
/*  f0f71b8:	8fa501e0 */ 	lw	$a1,0x1e0($sp)
/*  f0f71bc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0f71c0:	01b9a821 */ 	addu	$s5,$t5,$t9
/*  f0f71c4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0f71c8:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f71cc:	24070009 */ 	addiu	$a3,$zero,0x9
/*  f0f71d0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0f71d4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f71d8:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f0f71dc:	24a5fffb */ 	addiu	$a1,$a1,-5
/*  f0f71e0:	06a10003 */ 	bgez	$s5,.L0f0f71f0
/*  f0f71e4:	0015a043 */ 	sra	$s4,$s5,0x1
/*  f0f71e8:	26a10001 */ 	addiu	$at,$s5,0x1
/*  f0f71ec:	0001a043 */ 	sra	$s4,$at,0x1
.L0f0f71f0:
/*  f0f71f0:	0fc38cc9 */ 	jal	func0f0e3324
/*  f0f71f4:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f71f8:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f71fc:	0fc01ac2 */ 	jal	func0f006b08
/*  f0f7200:	4600a306 */ 	mov.s	$f12,$f20
/*  f0f7204:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f0f7208:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f0f720c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f7210:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f7214:	02803025 */ 	or	$a2,$s4,$zero
/*  f0f7218:	24070009 */ 	addiu	$a3,$zero,0x9
/*  f0f721c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0f7220:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f7224:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f0f7228:	0fc38cc9 */ 	jal	func0f0e3324
/*  f0f722c:	24a50005 */ 	addiu	$a1,$a1,0x5
/*  f0f7230:	3c03800a */ 	lui	$v1,%hi(g_MenuData+0x4)
/*  f0f7234:	8c6319c4 */ 	lw	$v1,%lo(g_MenuData+0x4)($v1)
/*  f0f7238:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f723c:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f7240:	10610007 */ 	beq	$v1,$at,.L0f0f7260
/*  f0f7244:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0f7248:	10610005 */ 	beq	$v1,$at,.L0f0f7260
/*  f0f724c:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0f7250:	10610003 */ 	beq	$v1,$at,.L0f0f7260
/*  f0f7254:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0f7258:	54610086 */ 	bnel	$v1,$at,.L0f0f7474
/*  f0f725c:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f7260:
/*  f0f7260:	0fc54f93 */ 	jal	func0f153e4c
/*  f0f7264:	00000000 */ 	nop
/*  f0f7268:	0fc54c6e */ 	jal	func0f1531b8
/*  f0f726c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0f7270:	0fc54d8a */ 	jal	func0f153628
/*  f0f7274:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f7278:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f727c:	82230015 */ 	lb	$v1,0x15($s1)
/*  f0f7280:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f0f7284:	04630004 */ 	bgezl	$v1,.L0f0f7298
/*  f0f7288:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f0f728c:	82230014 */ 	lb	$v1,0x14($s1)
/*  f0f7290:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f0f7294:	0003c080 */ 	sll	$t8,$v1,0x2
.L0f0f7298:
/*  f0f7298:	02386021 */ 	addu	$t4,$s1,$t8
/*  f0f729c:	8d8f0000 */ 	lw	$t7,0x0($t4)
/*  f0f72a0:	0fc3c560 */ 	jal	menuResolveParam1Text
/*  f0f72a4:	8de40000 */ 	lw	$a0,0x0($t7)
/*  f0f72a8:	3c138008 */ 	lui	$s3,%hi(var8007fb04)
/*  f0f72ac:	2673fb04 */ 	addiu	$s3,$s3,%lo(var8007fb04)
/*  f0f72b0:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f0f72b4:	3c128008 */ 	lui	$s2,%hi(var8007fb08)
/*  f0f72b8:	2652fb08 */ 	addiu	$s2,$s2,%lo(var8007fb08)
/*  f0f72bc:	27b600b0 */ 	addiu	$s6,$sp,0xb0
/*  f0f72c0:	27b700ac */ 	addiu	$s7,$sp,0xac
/*  f0f72c4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0f72c8:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0f72cc:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0f72d0:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f0f72d4:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f72d8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f72dc:	0fc55cbe */ 	jal	textMeasure
/*  f0f72e0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0f72e4:	8fa200ac */ 	lw	$v0,0xac($sp)
/*  f0f72e8:	8fa301e0 */ 	lw	$v1,0x1e0($sp)
/*  f0f72ec:	8fb901dc */ 	lw	$t9,0x1dc($sp)
/*  f0f72f0:	02822823 */ 	subu	$a1,$s4,$v0
/*  f0f72f4:	24a5fffd */ 	addiu	$a1,$a1,-3
/*  f0f72f8:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f0f72fc:	00b9082a */ 	slt	$at,$a1,$t9
/*  f0f7300:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f7304:	10200009 */ 	beqz	$at,.L0f0f732c
/*  f0f7308:	afa501cc */ 	sw	$a1,0x1cc($sp)
/*  f0f730c:	02a22823 */ 	subu	$a1,$s5,$v0
/*  f0f7310:	04a10003 */ 	bgez	$a1,.L0f0f7320
/*  f0f7314:	00057043 */ 	sra	$t6,$a1,0x1
/*  f0f7318:	24a10001 */ 	addiu	$at,$a1,0x1
/*  f0f731c:	00017043 */ 	sra	$t6,$at,0x1
.L0f0f7320:
/*  f0f7320:	2463fffd */ 	addiu	$v1,$v1,-3
/*  f0f7324:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f7328:	afae01cc */ 	sw	$t6,0x1cc($sp)
.L0f0f732c:
/*  f0f732c:	0c002f06 */ 	jal	viGetY
/*  f0f7330:	00000000 */ 	nop
/*  f0f7334:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f0f7338:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f0f733c:	87af01ca */ 	lh	$t7,0x1ca($sp)
/*  f0f7340:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0f7344:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0f7348:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f734c:	27a501cc */ 	addiu	$a1,$sp,0x1cc
/*  f0f7350:	27a601d0 */ 	addiu	$a2,$sp,0x1d0
/*  f0f7354:	02003825 */ 	or	$a3,$s0,$zero
/*  f0f7358:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f735c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f7360:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f7364:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0f7368:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f736c:	0fc5580f */ 	jal	textRenderWhite
/*  f0f7370:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0f7374:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f7378:	82230015 */ 	lb	$v1,0x15($s1)
/*  f0f737c:	822d0014 */ 	lb	$t5,0x14($s1)
/*  f0f7380:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0f7384:	006d082a */ 	slt	$at,$v1,$t5
/*  f0f7388:	54200003 */ 	bnezl	$at,.L0f0f7398
/*  f0f738c:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f0f7390:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f7394:	0003c880 */ 	sll	$t9,$v1,0x2
.L0f0f7398:
/*  f0f7398:	02397021 */ 	addu	$t6,$s1,$t9
/*  f0f739c:	8dcb0000 */ 	lw	$t3,0x0($t6)
/*  f0f73a0:	0fc3c560 */ 	jal	menuResolveParam1Text
/*  f0f73a4:	8d640000 */ 	lw	$a0,0x0($t3)
/*  f0f73a8:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f0f73ac:	00408025 */ 	or	$s0,$v0,$zero
/*  f0f73b0:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0f73b4:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0f73b8:	00403025 */ 	or	$a2,$v0,$zero
/*  f0f73bc:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f0f73c0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f73c4:	0fc55cbe */ 	jal	textMeasure
/*  f0f73c8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0f73cc:	8fa200ac */ 	lw	$v0,0xac($sp)
/*  f0f73d0:	8fa30088 */ 	lw	$v1,0x88($sp)
/*  f0f73d4:	8fac01d4 */ 	lw	$t4,0x1d4($sp)
/*  f0f73d8:	26850003 */ 	addiu	$a1,$s4,0x3
/*  f0f73dc:	00a27821 */ 	addu	$t7,$a1,$v0
/*  f0f73e0:	24630007 */ 	addiu	$v1,$v1,0x7
/*  f0f73e4:	018f082a */ 	slt	$at,$t4,$t7
/*  f0f73e8:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f73ec:	10200009 */ 	beqz	$at,.L0f0f7414
/*  f0f73f0:	afa501cc */ 	sw	$a1,0x1cc($sp)
/*  f0f73f4:	02a22823 */ 	subu	$a1,$s5,$v0
/*  f0f73f8:	04a10003 */ 	bgez	$a1,.L0f0f7408
/*  f0f73fc:	00056843 */ 	sra	$t5,$a1,0x1
/*  f0f7400:	24a10001 */ 	addiu	$at,$a1,0x1
/*  f0f7404:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f7408:
/*  f0f7408:	24630003 */ 	addiu	$v1,$v1,0x3
/*  f0f740c:	afa301d0 */ 	sw	$v1,0x1d0($sp)
/*  f0f7410:	afad01cc */ 	sw	$t5,0x1cc($sp)
.L0f0f7414:
/*  f0f7414:	0c002f06 */ 	jal	viGetY
/*  f0f7418:	00000000 */ 	nop
/*  f0f741c:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f0f7420:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f0f7424:	87b801ca */ 	lh	$t8,0x1ca($sp)
/*  f0f7428:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0f742c:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f7430:	8fa401e8 */ 	lw	$a0,0x1e8($sp)
/*  f0f7434:	27a501cc */ 	addiu	$a1,$sp,0x1cc
/*  f0f7438:	27a601d0 */ 	addiu	$a2,$sp,0x1d0
/*  f0f743c:	02003825 */ 	or	$a3,$s0,$zero
/*  f0f7440:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0f7444:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f7448:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0f744c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f7450:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0f7454:	0fc5580f */ 	jal	textRenderWhite
/*  f0f7458:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0f745c:	0fc54de0 */ 	jal	func0f153780
/*  f0f7460:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f7464:	afa201e8 */ 	sw	$v0,0x1e8($sp)
/*  f0f7468:	0fc54c6e */ 	jal	func0f1531b8
/*  f0f746c:	00002025 */ 	or	$a0,$zero,$zero
.L0f0f7470:
/*  f0f7470:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
.L0f0f7474:
/*  f0f7474:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f0f7478:	d7b40038 */ 	ldc1	$f20,0x38($sp)
/*  f0f747c:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f0f7480:	8fb10044 */ 	lw	$s1,0x44($sp)
/*  f0f7484:	8fb20048 */ 	lw	$s2,0x48($sp)
/*  f0f7488:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*  f0f748c:	8fb40050 */ 	lw	$s4,0x50($sp)
/*  f0f7490:	8fb50054 */ 	lw	$s5,0x54($sp)
/*  f0f7494:	8fb60058 */ 	lw	$s6,0x58($sp)
/*  f0f7498:	8fb7005c */ 	lw	$s7,0x5c($sp)
/*  f0f749c:	8fbe0060 */ 	lw	$s8,0x60($sp)
/*  f0f74a0:	03e00008 */ 	jr	$ra
/*  f0f74a4:	27bd01e8 */ 	addiu	$sp,$sp,0x1e8
);

GLOBAL_ASM(
glabel func0f0f74a8
.late_rodata
glabel var7f1b294c
.word func0f0f74a8+0x3c # f0f74e4
glabel var7f1b2950
.word func0f0f74a8+0x58 # f0f7500
glabel var7f1b2954
.word func0f0f74a8+0x58 # f0f7500
glabel var7f1b2958
.word func0f0f74a8+0x3c # f0f74e4
glabel var7f1b295c
.word func0f0f74a8+0x3c # f0f74e4
glabel var7f1b2960
.word func0f0f74a8+0x58 # f0f7500
glabel var7f1b2964
.word func0f0f74a8+0x58 # f0f7500
glabel var7f1b2968
.word func0f0f74a8+0x3c # f0f74e4
glabel var7f1b296c
.word func0f0f74a8+0x3c # f0f74e4
.text
/*  f0f74a8:	3c0e800a */ 	lui	$t6,%hi(g_MenuData+0x4)
/*  f0f74ac:	8dce19c4 */ 	lw	$t6,%lo(g_MenuData+0x4)($t6)
/*  f0f74b0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f74b4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f74b8:	25cffffd */ 	addiu	$t7,$t6,-3
/*  f0f74bc:	2de10009 */ 	sltiu	$at,$t7,0x9
/*  f0f74c0:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0f74c4:	1020000e */ 	beqz	$at,.L0f0f7500
/*  f0f74c8:	00803025 */ 	or	$a2,$a0,$zero
/*  f0f74cc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f74d0:	3c017f1b */ 	lui	$at,%hi(var7f1b294c)
/*  f0f74d4:	002f0821 */ 	addu	$at,$at,$t7
/*  f0f74d8:	8c2f294c */ 	lw	$t7,%lo(var7f1b294c)($at)
/*  f0f74dc:	01e00008 */ 	jr	$t7
/*  f0f74e0:	00000000 */ 	nop
/*  f0f74e4:	3c188007 */ 	lui	$t8,%hi(g_MpPlayerNum)
/*  f0f74e8:	8f181448 */ 	lw	$t8,%lo(g_MpPlayerNum)($t8)
/*  f0f74ec:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0f74f0:	a0d80000 */ 	sb	$t8,0x0($a2)
/*  f0f74f4:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*  f0f74f8:	10000022 */ 	b	.L0f0f7584
/*  f0f74fc:	a1190000 */ 	sb	$t9,0x0($t0)
.L0f0f7500:
/*  f0f7500:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x288)
/*  f0f7504:	8d29a248 */ 	lw	$t1,%lo(g_Vars+0x288)($t1)
/*  f0f7508:	8d240070 */ 	lw	$a0,0x70($t1)
/*  f0f750c:	0fc549d2 */ 	jal	optionsGetContpadNum1
/*  f0f7510:	afa60018 */ 	sw	$a2,0x18($sp)
/*  f0f7514:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f0f7518:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0f751c:	240affff */ 	addiu	$t2,$zero,-1
/*  f0f7520:	a0c20000 */ 	sb	$v0,0x0($a2)
/*  f0f7524:	8fab001c */ 	lw	$t3,0x1c($sp)
/*  f0f7528:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0f752c:	a16a0000 */ 	sb	$t2,0x0($t3)
/*  f0f7530:	8c6c0318 */ 	lw	$t4,0x318($v1)
/*  f0f7534:	55800014 */ 	bnezl	$t4,.L0f0f7588
/*  f0f7538:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f753c:	8c6d0288 */ 	lw	$t5,0x288($v1)
/*  f0f7540:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f0f7544:	8da40070 */ 	lw	$a0,0x70($t5)
/*  f0f7548:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0f754c:	10410008 */ 	beq	$v0,$at,.L0f0f7570
/*  f0f7550:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x288)
/*  f0f7554:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0f7558:	10410005 */ 	beq	$v0,$at,.L0f0f7570
/*  f0f755c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f7560:	10410003 */ 	beq	$v0,$at,.L0f0f7570
/*  f0f7564:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f7568:	54410007 */ 	bnel	$v0,$at,.L0f0f7588
/*  f0f756c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f7570:
/*  f0f7570:	8dcea248 */ 	lw	$t6,%lo(g_Vars+0x288)($t6)
/*  f0f7574:	0fc549d9 */ 	jal	optionsGetContpadNum2
/*  f0f7578:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0f757c:	8faf001c */ 	lw	$t7,0x1c($sp)
/*  f0f7580:	a1e20000 */ 	sb	$v0,0x0($t7)
.L0f0f7584:
/*  f0f7584:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f7588:
/*  f0f7588:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f758c:	03e00008 */ 	jr	$ra
/*  f0f7590:	00000000 */ 	nop
);

u32 var800714d8 = 0x00000001;

GLOBAL_ASM(
glabel func0f0f7594
/*  f0f7594:	3c0e800a */ 	lui	$t6,%hi(g_MenuData+0x4)
/*  f0f7598:	8dce19c4 */ 	lw	$t6,%lo(g_MenuData+0x4)($t6)
/*  f0f759c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f75a0:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f0f75a4:	55c1005d */ 	bnel	$t6,$at,.L0f0f771c
/*  f0f75a8:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f0f75ac:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f0f75b0:	3c02800a */ 	lui	$v0,%hi(g_Menus+0x83b)
/*  f0f75b4:	3c038007 */ 	lui	$v1,%hi(var800714d8)
/*  f0f75b8:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f75bc:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f75c0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f75c4:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f75c8:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f75cc:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f75d0:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f75d4:	00581021 */ 	addu	$v0,$v0,$t8
/*  f0f75d8:	9042e83b */ 	lbu	$v0,%lo(g_Menus+0x83b)($v0)
/*  f0f75dc:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f0f75e0:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f0f75e4:	8c6314d8 */ 	lw	$v1,%lo(var800714d8)($v1)
/*  f0f75e8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f75ec:	10610009 */ 	beq	$v1,$at,.L0f0f7614
/*  f0f75f0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f75f4:	10610009 */ 	beq	$v1,$at,.L0f0f761c
/*  f0f75f8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f75fc:	10610017 */ 	beq	$v1,$at,.L0f0f765c
/*  f0f7600:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f7604:	1061002a */ 	beq	$v1,$at,.L0f0f76b0
/*  f0f7608:	00000000 */ 	nop
/*  f0f760c:	03e00008 */ 	jr	$ra
/*  f0f7610:	00000000 */ 	nop
.L0f0f7614:
/*  f0f7614:	03e00008 */ 	jr	$ra
/*  f0f7618:	acc40000 */ 	sw	$a0,0x0($a2)
.L0f0f761c:
/*  f0f761c:	14400008 */ 	bnez	$v0,.L0f0f7640
/*  f0f7620:	00000000 */ 	nop
/*  f0f7624:	04810004 */ 	bgez	$a0,.L0f0f7638
/*  f0f7628:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0f762c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0f7630:	03e00008 */ 	jr	$ra
/*  f0f7634:	acd90000 */ 	sw	$t9,0x0($a2)
.L0f0f7638:
/*  f0f7638:	03e00008 */ 	jr	$ra
/*  f0f763c:	aca80000 */ 	sw	$t0,0x0($a1)
.L0f0f7640:
/*  f0f7640:	18800004 */ 	blez	$a0,.L0f0f7654
/*  f0f7644:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0f7648:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0f764c:	03e00008 */ 	jr	$ra
/*  f0f7650:	acc30000 */ 	sw	$v1,0x0($a2)
.L0f0f7654:
/*  f0f7654:	03e00008 */ 	jr	$ra
/*  f0f7658:	aca30000 */ 	sw	$v1,0x0($a1)
.L0f0f765c:
/*  f0f765c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f7660:	14410003 */ 	bne	$v0,$at,.L0f0f7670
/*  f0f7664:	00000000 */ 	nop
/*  f0f7668:	03e00008 */ 	jr	$ra
/*  f0f766c:	acc40000 */ 	sw	$a0,0x0($a2)
.L0f0f7670:
/*  f0f7670:	14400008 */ 	bnez	$v0,.L0f0f7694
/*  f0f7674:	00000000 */ 	nop
/*  f0f7678:	04810004 */ 	bgez	$a0,.L0f0f768c
/*  f0f767c:	240affff */ 	addiu	$t2,$zero,-1
/*  f0f7680:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f0f7684:	03e00008 */ 	jr	$ra
/*  f0f7688:	acc90000 */ 	sw	$t1,0x0($a2)
.L0f0f768c:
/*  f0f768c:	03e00008 */ 	jr	$ra
/*  f0f7690:	acaa0000 */ 	sw	$t2,0x0($a1)
.L0f0f7694:
/*  f0f7694:	18800004 */ 	blez	$a0,.L0f0f76a8
/*  f0f7698:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0f769c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0f76a0:	03e00008 */ 	jr	$ra
/*  f0f76a4:	acc30000 */ 	sw	$v1,0x0($a2)
.L0f0f76a8:
/*  f0f76a8:	03e00008 */ 	jr	$ra
/*  f0f76ac:	acab0000 */ 	sw	$t3,0x0($a1)
.L0f0f76b0:
/*  f0f76b0:	10400003 */ 	beqz	$v0,.L0f0f76c0
/*  f0f76b4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f76b8:	1441000c */ 	bne	$v0,$at,.L0f0f76ec
/*  f0f76bc:	00000000 */ 	nop
.L0f0f76c0:
/*  f0f76c0:	04810003 */ 	bgez	$a0,.L0f0f76d0
/*  f0f76c4:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0f76c8:	03e00008 */ 	jr	$ra
/*  f0f76cc:	accc0000 */ 	sw	$t4,0x0($a2)
.L0f0f76d0:
/*  f0f76d0:	14400004 */ 	bnez	$v0,.L0f0f76e4
/*  f0f76d4:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0f76d8:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0f76dc:	03e00008 */ 	jr	$ra
/*  f0f76e0:	acad0000 */ 	sw	$t5,0x0($a1)
.L0f0f76e4:
/*  f0f76e4:	03e00008 */ 	jr	$ra
/*  f0f76e8:	aca30000 */ 	sw	$v1,0x0($a1)
.L0f0f76ec:
/*  f0f76ec:	18800004 */ 	blez	$a0,.L0f0f7700
/*  f0f76f0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0f76f4:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0f76f8:	03e00008 */ 	jr	$ra
/*  f0f76fc:	acc30000 */ 	sw	$v1,0x0($a2)
.L0f0f7700:
/*  f0f7700:	14430003 */ 	bne	$v0,$v1,.L0f0f7710
/*  f0f7704:	240effff */ 	addiu	$t6,$zero,-1
/*  f0f7708:	03e00008 */ 	jr	$ra
/*  f0f770c:	acae0000 */ 	sw	$t6,0x0($a1)
.L0f0f7710:
/*  f0f7710:	03e00008 */ 	jr	$ra
/*  f0f7714:	aca30000 */ 	sw	$v1,0x0($a1)
/*  f0f7718:	aca00000 */ 	sw	$zero,0x0($a1)
.L0f0f771c:
/*  f0f771c:	acc40000 */ 	sw	$a0,0x0($a2)
/*  f0f7720:	03e00008 */ 	jr	$ra
/*  f0f7724:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0f7728
.late_rodata
glabel var7f1b2970
.word func0f0f7728+0x180 # f0f78a8
glabel var7f1b2974
.word func0f0f7728+0x3d8 # f0f7b00
glabel var7f1b2978
.word func0f0f7728+0x3d8 # f0f7b00
glabel var7f1b297c
.word func0f0f7728+0x748 # f0f7e70
glabel var7f1b2980
.word func0f0f7728+0x748 # f0f7e70
glabel var7f1b2984
.word func0f0f7728+0x3d8 # f0f7b00
glabel var7f1b2988
.word func0f0f7728+0x748 # f0f7e70
glabel var7f1b298c
.word func0f0f7728+0x3d8 # f0f7b00
glabel var7f1b2990
.word func0f0f7728+0x180 # f0f78a8
.text
/*  f0f7728:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0f772c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f7730:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0f7734:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f0f7738:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0f773c:	0c002f40 */ 	jal	viGetViewLeft
/*  f0f7740:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f0f7744:	3c0e8008 */ 	lui	$t6,%hi(g_ScreenWidthMultiplier)
/*  f0f7748:	8dcefac0 */ 	lw	$t6,%lo(g_ScreenWidthMultiplier)($t6)
/*  f0f774c:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f0f7750:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f0f7754:	004e001a */ 	div	$zero,$v0,$t6
/*  f0f7758:	00003012 */ 	mflo	$a2
/*  f0f775c:	24c60014 */ 	addiu	$a2,$a2,0x14
/*  f0f7760:	15c00002 */ 	bnez	$t6,.L0f0f776c
/*  f0f7764:	00000000 */ 	nop
/*  f0f7768:	0007000d */ 	break	0x7
.L0f0f776c:
/*  f0f776c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f7770:	15c10004 */ 	bne	$t6,$at,.L0f0f7784
/*  f0f7774:	3c018000 */ 	lui	$at,0x8000
/*  f0f7778:	14410002 */ 	bne	$v0,$at,.L0f0f7784
/*  f0f777c:	00000000 */ 	nop
/*  f0f7780:	0006000d */ 	break	0x6
.L0f0f7784:
/*  f0f7784:	afa60034 */ 	sw	$a2,0x34($sp)
/*  f0f7788:	0c002f44 */ 	jal	viGetViewTop
/*  f0f778c:	00000000 */ 	nop
/*  f0f7790:	24430004 */ 	addiu	$v1,$v0,0x4
/*  f0f7794:	0c002f40 */ 	jal	viGetViewLeft
/*  f0f7798:	afa30030 */ 	sw	$v1,0x30($sp)
/*  f0f779c:	0c002f22 */ 	jal	viGetViewX
/*  f0f77a0:	a7a2001a */ 	sh	$v0,0x1a($sp)
/*  f0f77a4:	87af001a */ 	lh	$t7,0x1a($sp)
/*  f0f77a8:	3c198008 */ 	lui	$t9,%hi(g_ScreenWidthMultiplier)
/*  f0f77ac:	8f39fac0 */ 	lw	$t9,%lo(g_ScreenWidthMultiplier)($t9)
/*  f0f77b0:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f0f77b4:	8fa30030 */ 	lw	$v1,0x30($sp)
/*  f0f77b8:	0319001a */ 	div	$zero,$t8,$t9
/*  f0f77bc:	00003812 */ 	mflo	$a3
/*  f0f77c0:	24e7ffec */ 	addiu	$a3,$a3,-20
/*  f0f77c4:	8fa60034 */ 	lw	$a2,0x34($sp)
/*  f0f77c8:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f0f77cc:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f0f77d0:	17200002 */ 	bnez	$t9,.L0f0f77dc
/*  f0f77d4:	00000000 */ 	nop
/*  f0f77d8:	0007000d */ 	break	0x7
.L0f0f77dc:
/*  f0f77dc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f77e0:	17210004 */ 	bne	$t9,$at,.L0f0f77f4
/*  f0f77e4:	3c018000 */ 	lui	$at,0x8000
/*  f0f77e8:	17010002 */ 	bne	$t8,$at,.L0f0f77f4
/*  f0f77ec:	00000000 */ 	nop
/*  f0f77f0:	0006000d */ 	break	0x6
.L0f0f77f4:
/*  f0f77f4:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f0f77f8:	0c002f44 */ 	jal	viGetViewTop
/*  f0f77fc:	00000000 */ 	nop
/*  f0f7800:	0c002f26 */ 	jal	viGetViewY
/*  f0f7804:	a7a2001a */ 	sh	$v0,0x1a($sp)
/*  f0f7808:	87ae001a */ 	lh	$t6,0x1a($sp)
/*  f0f780c:	004e2021 */ 	addu	$a0,$v0,$t6
/*  f0f7810:	2484fffc */ 	addiu	$a0,$a0,-4
/*  f0f7814:	0fc3c2fb */ 	jal	currentPlayerIsMenuOpenInSoloOrMp
/*  f0f7818:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f0f781c:	8fa30030 */ 	lw	$v1,0x30($sp)
/*  f0f7820:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f0f7824:	8fa60034 */ 	lw	$a2,0x34($sp)
/*  f0f7828:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f0f782c:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f0f7830:	10400011 */ 	beqz	$v0,.L0f0f7878
/*  f0f7834:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f0f7838:	24630016 */ 	addiu	$v1,$v1,0x16
/*  f0f783c:	afa30030 */ 	sw	$v1,0x30($sp)
/*  f0f7840:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f0f7844:	afa60034 */ 	sw	$a2,0x34($sp)
/*  f0f7848:	0fc54b60 */ 	jal	optionsGetEffectiveScreenSize
/*  f0f784c:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f0f7850:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f7854:	8fa30030 */ 	lw	$v1,0x30($sp)
/*  f0f7858:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f0f785c:	8fa60034 */ 	lw	$a2,0x34($sp)
/*  f0f7860:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f0f7864:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f0f7868:	14410003 */ 	bne	$v0,$at,.L0f0f7878
/*  f0f786c:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f0f7870:	2463fff8 */ 	addiu	$v1,$v1,-8
/*  f0f7874:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f0f7878:
/*  f0f7878:	3c02800a */ 	lui	$v0,%hi(g_MenuData)
/*  f0f787c:	244219c0 */ 	addiu	$v0,$v0,%lo(g_MenuData)
/*  f0f7880:	8c4f0004 */ 	lw	$t7,0x4($v0)
/*  f0f7884:	25f8fffd */ 	addiu	$t8,$t7,-3
/*  f0f7888:	2f010009 */ 	sltiu	$at,$t8,0x9
/*  f0f788c:	10200178 */ 	beqz	$at,.L0f0f7e70
/*  f0f7890:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f7894:	3c017f1b */ 	lui	$at,%hi(var7f1b2970)
/*  f0f7898:	00380821 */ 	addu	$at,$at,$t8
/*  f0f789c:	8c382970 */ 	lw	$t8,%lo(var7f1b2970)($at)
/*  f0f78a0:	03000008 */ 	jr	$t8
/*  f0f78a4:	00000000 */ 	nop
/*  f0f78a8:	3c1f8007 */ 	lui	$ra,%hi(g_MpPlayerNum)
/*  f0f78ac:	27ff1448 */ 	addiu	$ra,$ra,%lo(g_MpPlayerNum)
/*  f0f78b0:	8ff90000 */ 	lw	$t9,0x0($ra)
/*  f0f78b4:	90580017 */ 	lbu	$t8,0x17($v0)
/*  f0f78b8:	3c0d800a */ 	lui	$t5,%hi(g_Menus)
/*  f0f78bc:	001970c0 */ 	sll	$t6,$t9,0x3
/*  f0f78c0:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0f78c4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f78c8:	01d97021 */ 	addu	$t6,$t6,$t9
/*  f0f78cc:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0f78d0:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0f78d4:	25ade000 */ 	addiu	$t5,$t5,%lo(g_Menus)
/*  f0f78d8:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0f78dc:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0f78e0:	1f000004 */ 	bgtz	$t8,.L0f0f78f4
/*  f0f78e4:	91e5083b */ 	lbu	$a1,0x83b($t7)
/*  f0f78e8:	90590018 */ 	lbu	$t9,0x18($v0)
/*  f0f78ec:	5b200003 */ 	blezl	$t9,.L0f0f78fc
/*  f0f78f0:	904e0019 */ 	lbu	$t6,0x19($v0)
.L0f0f78f4:
/*  f0f78f4:	2463000a */ 	addiu	$v1,$v1,0xa
/*  f0f78f8:	904e0019 */ 	lbu	$t6,0x19($v0)
.L0f0f78fc:
/*  f0f78fc:	5dc00005 */ 	bgtzl	$t6,.L0f0f7914
/*  f0f7900:	2484fff6 */ 	addiu	$a0,$a0,-10
/*  f0f7904:	904f001a */ 	lbu	$t7,0x1a($v0)
/*  f0f7908:	19e00002 */ 	blez	$t7,.L0f0f7914
/*  f0f790c:	00000000 */ 	nop
/*  f0f7910:	2484fff6 */ 	addiu	$a0,$a0,-10
.L0f0f7914:
/*  f0f7914:	3c028007 */ 	lui	$v0,%hi(var800714d8)
/*  f0f7918:	8c4214d8 */ 	lw	$v0,%lo(var800714d8)($v0)
/*  f0f791c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f7920:	1041000a */ 	beq	$v0,$at,.L0f0f794c
/*  f0f7924:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f7928:	1041000f */ 	beq	$v0,$at,.L0f0f7968
/*  f0f792c:	8fae003c */ 	lw	$t6,0x3c($sp)
/*  f0f7930:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f7934:	10410020 */ 	beq	$v0,$at,.L0f0f79b8
/*  f0f7938:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f793c:	10410047 */ 	beq	$v0,$at,.L0f0f7a5c
/*  f0f7940:	00000000 */ 	nop
/*  f0f7944:	10000151 */ 	b	.L0f0f7e8c
/*  f0f7948:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f794c:
/*  f0f794c:	ad660000 */ 	sw	$a2,0x0($t3)
/*  f0f7950:	ad870000 */ 	sw	$a3,0x0($t4)
/*  f0f7954:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f0f7958:	af030000 */ 	sw	$v1,0x0($t8)
/*  f0f795c:	8fb90044 */ 	lw	$t9,0x44($sp)
/*  f0f7960:	10000149 */ 	b	.L0f0f7e88
/*  f0f7964:	af240000 */ 	sw	$a0,0x0($t9)
.L0f0f7968:
/*  f0f7968:	adc30000 */ 	sw	$v1,0x0($t6)
/*  f0f796c:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f7970:	00c77021 */ 	addu	$t6,$a2,$a3
/*  f0f7974:	14a00009 */ 	bnez	$a1,.L0f0f799c
/*  f0f7978:	ade40000 */ 	sw	$a0,0x0($t7)
/*  f0f797c:	00c7c021 */ 	addu	$t8,$a2,$a3
/*  f0f7980:	ad660000 */ 	sw	$a2,0x0($t3)
/*  f0f7984:	07010003 */ 	bgez	$t8,.L0f0f7994
/*  f0f7988:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0f798c:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0f7990:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f7994:
/*  f0f7994:	1000013c */ 	b	.L0f0f7e88
/*  f0f7998:	ad990000 */ 	sw	$t9,0x0($t4)
.L0f0f799c:
/*  f0f799c:	05c10003 */ 	bgez	$t6,.L0f0f79ac
/*  f0f79a0:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f0f79a4:	25c10001 */ 	addiu	$at,$t6,0x1
/*  f0f79a8:	00017843 */ 	sra	$t7,$at,0x1
.L0f0f79ac:
/*  f0f79ac:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f0f79b0:	10000135 */ 	b	.L0f0f7e88
/*  f0f79b4:	ad870000 */ 	sw	$a3,0x0($t4)
.L0f0f79b8:
/*  f0f79b8:	10a00003 */ 	beqz	$a1,.L0f0f79c8
/*  f0f79bc:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f79c0:	14a8001b */ 	bne	$a1,$t0,.L0f0f7a30
/*  f0f79c4:	0064c021 */ 	addu	$t8,$v1,$a0
.L0f0f79c8:
/*  f0f79c8:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f0f79cc:	0064c821 */ 	addu	$t9,$v1,$a0
/*  f0f79d0:	af030000 */ 	sw	$v1,0x0($t8)
/*  f0f79d4:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f79d8:	07210003 */ 	bgez	$t9,.L0f0f79e8
/*  f0f79dc:	00197043 */ 	sra	$t6,$t9,0x1
/*  f0f79e0:	27210001 */ 	addiu	$at,$t9,0x1
/*  f0f79e4:	00017043 */ 	sra	$t6,$at,0x1
.L0f0f79e8:
/*  f0f79e8:	14a00009 */ 	bnez	$a1,.L0f0f7a10
/*  f0f79ec:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f0f79f0:	00c7c021 */ 	addu	$t8,$a2,$a3
/*  f0f79f4:	ad660000 */ 	sw	$a2,0x0($t3)
/*  f0f79f8:	07010003 */ 	bgez	$t8,.L0f0f7a08
/*  f0f79fc:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0f7a00:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0f7a04:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f7a08:
/*  f0f7a08:	1000011f */ 	b	.L0f0f7e88
/*  f0f7a0c:	ad990000 */ 	sw	$t9,0x0($t4)
.L0f0f7a10:
/*  f0f7a10:	00c77021 */ 	addu	$t6,$a2,$a3
/*  f0f7a14:	05c10003 */ 	bgez	$t6,.L0f0f7a24
/*  f0f7a18:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f0f7a1c:	25c10001 */ 	addiu	$at,$t6,0x1
/*  f0f7a20:	00017843 */ 	sra	$t7,$at,0x1
.L0f0f7a24:
/*  f0f7a24:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f0f7a28:	10000117 */ 	b	.L0f0f7e88
/*  f0f7a2c:	ad870000 */ 	sw	$a3,0x0($t4)
.L0f0f7a30:
/*  f0f7a30:	8fae003c */ 	lw	$t6,0x3c($sp)
/*  f0f7a34:	07010003 */ 	bgez	$t8,.L0f0f7a44
/*  f0f7a38:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0f7a3c:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0f7a40:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f7a44:
/*  f0f7a44:	add90000 */ 	sw	$t9,0x0($t6)
/*  f0f7a48:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f7a4c:	ade40000 */ 	sw	$a0,0x0($t7)
/*  f0f7a50:	ad660000 */ 	sw	$a2,0x0($t3)
/*  f0f7a54:	1000010c */ 	b	.L0f0f7e88
/*  f0f7a58:	ad870000 */ 	sw	$a3,0x0($t4)
.L0f0f7a5c:
/*  f0f7a5c:	10a00003 */ 	beqz	$a1,.L0f0f7a6c
/*  f0f7a60:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f7a64:	14a10009 */ 	bne	$a1,$at,.L0f0f7a8c
/*  f0f7a68:	00c77021 */ 	addu	$t6,$a2,$a3
.L0f0f7a6c:
/*  f0f7a6c:	00c7c021 */ 	addu	$t8,$a2,$a3
/*  f0f7a70:	ad660000 */ 	sw	$a2,0x0($t3)
/*  f0f7a74:	07010003 */ 	bgez	$t8,.L0f0f7a84
/*  f0f7a78:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0f7a7c:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0f7a80:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f7a84:
/*  f0f7a84:	10000007 */ 	b	.L0f0f7aa4
/*  f0f7a88:	ad990000 */ 	sw	$t9,0x0($t4)
.L0f0f7a8c:
/*  f0f7a8c:	05c10003 */ 	bgez	$t6,.L0f0f7a9c
/*  f0f7a90:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f0f7a94:	25c10001 */ 	addiu	$at,$t6,0x1
/*  f0f7a98:	00017843 */ 	sra	$t7,$at,0x1
.L0f0f7a9c:
/*  f0f7a9c:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f0f7aa0:	ad870000 */ 	sw	$a3,0x0($t4)
.L0f0f7aa4:
/*  f0f7aa4:	10a00003 */ 	beqz	$a1,.L0f0f7ab4
/*  f0f7aa8:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f7aac:	14a8000b */ 	bne	$a1,$t0,.L0f0f7adc
/*  f0f7ab0:	0064c021 */ 	addu	$t8,$v1,$a0
.L0f0f7ab4:
/*  f0f7ab4:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f0f7ab8:	0064c821 */ 	addu	$t9,$v1,$a0
/*  f0f7abc:	af030000 */ 	sw	$v1,0x0($t8)
/*  f0f7ac0:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f7ac4:	07210003 */ 	bgez	$t9,.L0f0f7ad4
/*  f0f7ac8:	00197043 */ 	sra	$t6,$t9,0x1
/*  f0f7acc:	27210001 */ 	addiu	$at,$t9,0x1
/*  f0f7ad0:	00017043 */ 	sra	$t6,$at,0x1
.L0f0f7ad4:
/*  f0f7ad4:	100000ec */ 	b	.L0f0f7e88
/*  f0f7ad8:	adee0000 */ 	sw	$t6,0x0($t7)
.L0f0f7adc:
/*  f0f7adc:	8fae003c */ 	lw	$t6,0x3c($sp)
/*  f0f7ae0:	07010003 */ 	bgez	$t8,.L0f0f7af0
/*  f0f7ae4:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0f7ae8:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0f7aec:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f7af0:
/*  f0f7af0:	add90000 */ 	sw	$t9,0x0($t6)
/*  f0f7af4:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f7af8:	100000e3 */ 	b	.L0f0f7e88
/*  f0f7afc:	ade40000 */ 	sw	$a0,0x0($t7)
/*  f0f7b00:	3c1f8007 */ 	lui	$ra,%hi(g_MpPlayerNum)
/*  f0f7b04:	27ff1448 */ 	addiu	$ra,$ra,%lo(g_MpPlayerNum)
/*  f0f7b08:	8ff80000 */ 	lw	$t8,0x0($ra)
/*  f0f7b0c:	3c0d800a */ 	lui	$t5,%hi(g_Menus)
/*  f0f7b10:	25ade000 */ 	addiu	$t5,$t5,%lo(g_Menus)
/*  f0f7b14:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0f7b18:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f7b1c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f7b20:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0f7b24:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0f7b28:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f7b2c:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0f7b30:	01b97021 */ 	addu	$t6,$t5,$t9
/*  f0f7b34:	91cf083b */ 	lbu	$t7,0x83b($t6)
/*  f0f7b38:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0f7b3c:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0f7b40:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0f7b44:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f0f7b48:	8f2e0064 */ 	lw	$t6,0x64($t9)
/*  f0f7b4c:	3c188008 */ 	lui	$t8,%hi(g_ScreenWidthMultiplier)
/*  f0f7b50:	8f18fac0 */ 	lw	$t8,%lo(g_ScreenWidthMultiplier)($t8)
/*  f0f7b54:	85cf0634 */ 	lh	$t7,0x634($t6)
/*  f0f7b58:	00005025 */ 	or	$t2,$zero,$zero
/*  f0f7b5c:	01f8001a */ 	div	$zero,$t7,$t8
/*  f0f7b60:	0000c812 */ 	mflo	$t9
/*  f0f7b64:	ad790000 */ 	sw	$t9,0x0($t3)
/*  f0f7b68:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f0f7b6c:	17000002 */ 	bnez	$t8,.L0f0f7b78
/*  f0f7b70:	00000000 */ 	nop
/*  f0f7b74:	0007000d */ 	break	0x7
.L0f0f7b78:
/*  f0f7b78:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f7b7c:	17010004 */ 	bne	$t8,$at,.L0f0f7b90
/*  f0f7b80:	3c018000 */ 	lui	$at,0x8000
/*  f0f7b84:	15e10002 */ 	bne	$t7,$at,.L0f0f7b90
/*  f0f7b88:	00000000 */ 	nop
/*  f0f7b8c:	0006000d */ 	break	0x6
.L0f0f7b90:
/*  f0f7b90:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f7b94:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f7b98:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f7b9c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f7ba0:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f7ba4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f7ba8:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f7bac:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f0f7bb0:	9319083b */ 	lbu	$t9,0x83b($t8)
/*  f0f7bb4:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0f7bb8:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f0f7bbc:	8df80064 */ 	lw	$t8,0x64($t7)
/*  f0f7bc0:	8fae003c */ 	lw	$t6,0x3c($sp)
/*  f0f7bc4:	87190636 */ 	lh	$t9,0x636($t8)
/*  f0f7bc8:	add90000 */ 	sw	$t9,0x0($t6)
/*  f0f7bcc:	8fef0000 */ 	lw	$t7,0x0($ra)
/*  f0f7bd0:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f7bd4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f7bd8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f7bdc:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f7be0:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f7be4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f7be8:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f7bec:	01b8c821 */ 	addu	$t9,$t5,$t8
/*  f0f7bf0:	932e083b */ 	lbu	$t6,0x83b($t9)
/*  f0f7bf4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0f7bf8:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f0f7bfc:	8f020064 */ 	lw	$v0,0x64($t8)
/*  f0f7c00:	3c188008 */ 	lui	$t8,%hi(g_ScreenWidthMultiplier)
/*  f0f7c04:	8f18fac0 */ 	lw	$t8,%lo(g_ScreenWidthMultiplier)($t8)
/*  f0f7c08:	84590630 */ 	lh	$t9,0x630($v0)
/*  f0f7c0c:	844e0634 */ 	lh	$t6,0x634($v0)
/*  f0f7c10:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f0f7c14:	01f8001a */ 	div	$zero,$t7,$t8
/*  f0f7c18:	0000c812 */ 	mflo	$t9
/*  f0f7c1c:	ad990000 */ 	sw	$t9,0x0($t4)
/*  f0f7c20:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f0f7c24:	17000002 */ 	bnez	$t8,.L0f0f7c30
/*  f0f7c28:	00000000 */ 	nop
/*  f0f7c2c:	0007000d */ 	break	0x7
.L0f0f7c30:
/*  f0f7c30:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f7c34:	17010004 */ 	bne	$t8,$at,.L0f0f7c48
/*  f0f7c38:	3c018000 */ 	lui	$at,0x8000
/*  f0f7c3c:	15e10002 */ 	bne	$t7,$at,.L0f0f7c48
/*  f0f7c40:	00000000 */ 	nop
/*  f0f7c44:	0006000d */ 	break	0x6
.L0f0f7c48:
/*  f0f7c48:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f7c4c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f7c50:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f7c54:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f7c58:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f7c5c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f7c60:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f7c64:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f0f7c68:	9319083b */ 	lbu	$t9,0x83b($t8)
/*  f0f7c6c:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0f7c70:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f0f7c74:	8de20064 */ 	lw	$v0,0x64($t7)
/*  f0f7c78:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f7c7c:	84580632 */ 	lh	$t8,0x632($v0)
/*  f0f7c80:	84590636 */ 	lh	$t9,0x636($v0)
/*  f0f7c84:	03197021 */ 	addu	$t6,$t8,$t9
/*  f0f7c88:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f0f7c8c:	8c65006c */ 	lw	$a1,0x6c($v1)
/*  f0f7c90:	10a00003 */ 	beqz	$a1,.L0f0f7ca0
/*  f0f7c94:	00000000 */ 	nop
/*  f0f7c98:	10000001 */ 	b	.L0f0f7ca0
/*  f0f7c9c:	240a0001 */ 	addiu	$t2,$zero,0x1
.L0f0f7ca0:
/*  f0f7ca0:	8c660068 */ 	lw	$a2,0x68($v1)
/*  f0f7ca4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f7ca8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f7cac:	10c00003 */ 	beqz	$a2,.L0f0f7cbc
/*  f0f7cb0:	00000000 */ 	nop
/*  f0f7cb4:	10000001 */ 	b	.L0f0f7cbc
/*  f0f7cb8:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0f7cbc:
/*  f0f7cbc:	8c680064 */ 	lw	$t0,0x64($v1)
/*  f0f7cc0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f7cc4:	11000003 */ 	beqz	$t0,.L0f0f7cd4
/*  f0f7cc8:	00000000 */ 	nop
/*  f0f7ccc:	10000001 */ 	b	.L0f0f7cd4
/*  f0f7cd0:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0f7cd4:
/*  f0f7cd4:	8c690070 */ 	lw	$t1,0x70($v1)
/*  f0f7cd8:	11200003 */ 	beqz	$t1,.L0f0f7ce8
/*  f0f7cdc:	00000000 */ 	nop
/*  f0f7ce0:	10000001 */ 	b	.L0f0f7ce8
/*  f0f7ce4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0f7ce8:
/*  f0f7ce8:	0044c021 */ 	addu	$t8,$v0,$a0
/*  f0f7cec:	0307c821 */ 	addu	$t9,$t8,$a3
/*  f0f7cf0:	032a7021 */ 	addu	$t6,$t9,$t2
/*  f0f7cf4:	29c10003 */ 	slti	$at,$t6,0x3
/*  f0f7cf8:	14200026 */ 	bnez	$at,.L0f0f7d94
/*  f0f7cfc:	00005025 */ 	or	$t2,$zero,$zero
/*  f0f7d00:	8fef0000 */ 	lw	$t7,0x0($ra)
/*  f0f7d04:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f7d08:	3c05800a */ 	lui	$a1,%hi(g_Vars+0x6c)
/*  f0f7d0c:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f7d10:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f7d14:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f7d18:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f7d1c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f7d20:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f7d24:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f7d28:	01b8c821 */ 	addu	$t9,$t5,$t8
/*  f0f7d2c:	9322083b */ 	lbu	$v0,0x83b($t9)
/*  f0f7d30:	3c06800a */ 	lui	$a2,%hi(g_Vars+0x68)
/*  f0f7d34:	50400004 */ 	beqzl	$v0,.L0f0f7d48
/*  f0f7d38:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f0f7d3c:	1441000b */ 	bne	$v0,$at,.L0f0f7d6c
/*  f0f7d40:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x64)
/*  f0f7d44:	8d6e0000 */ 	lw	$t6,0x0($t3)
.L0f0f7d48:
/*  f0f7d48:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x64)
/*  f0f7d4c:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x70)
/*  f0f7d50:	25cf0016 */ 	addiu	$t7,$t6,0x16
/*  f0f7d54:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f0f7d58:	8d29a030 */ 	lw	$t1,%lo(g_Vars+0x70)($t1)
/*  f0f7d5c:	8d08a024 */ 	lw	$t0,%lo(g_Vars+0x64)($t0)
/*  f0f7d60:	8cc6a028 */ 	lw	$a2,%lo(g_Vars+0x68)($a2)
/*  f0f7d64:	1000000b */ 	b	.L0f0f7d94
/*  f0f7d68:	8ca5a02c */ 	lw	$a1,%lo(g_Vars+0x6c)($a1)
.L0f0f7d6c:
/*  f0f7d6c:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f0f7d70:	3c05800a */ 	lui	$a1,%hi(g_Vars+0x6c)
/*  f0f7d74:	3c06800a */ 	lui	$a2,%hi(g_Vars+0x68)
/*  f0f7d78:	2719ffea */ 	addiu	$t9,$t8,-22
/*  f0f7d7c:	ad990000 */ 	sw	$t9,0x0($t4)
/*  f0f7d80:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x70)
/*  f0f7d84:	8d29a030 */ 	lw	$t1,%lo(g_Vars+0x70)($t1)
/*  f0f7d88:	8d08a024 */ 	lw	$t0,%lo(g_Vars+0x64)($t0)
/*  f0f7d8c:	8cc6a028 */ 	lw	$a2,%lo(g_Vars+0x68)($a2)
/*  f0f7d90:	8ca5a02c */ 	lw	$a1,%lo(g_Vars+0x6c)($a1)
.L0f0f7d94:
/*  f0f7d94:	10a00003 */ 	beqz	$a1,.L0f0f7da4
/*  f0f7d98:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f7d9c:	10000001 */ 	b	.L0f0f7da4
/*  f0f7da0:	240a0001 */ 	addiu	$t2,$zero,0x1
.L0f0f7da4:
/*  f0f7da4:	10c00003 */ 	beqz	$a2,.L0f0f7db4
/*  f0f7da8:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f7dac:	10000001 */ 	b	.L0f0f7db4
/*  f0f7db0:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0f7db4:
/*  f0f7db4:	11000003 */ 	beqz	$t0,.L0f0f7dc4
/*  f0f7db8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f7dbc:	10000001 */ 	b	.L0f0f7dc4
/*  f0f7dc0:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0f7dc4:
/*  f0f7dc4:	11200003 */ 	beqz	$t1,.L0f0f7dd4
/*  f0f7dc8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f7dcc:	10000001 */ 	b	.L0f0f7dd4
/*  f0f7dd0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0f7dd4:
/*  f0f7dd4:	00447021 */ 	addu	$t6,$v0,$a0
/*  f0f7dd8:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f0f7ddc:	01eac021 */ 	addu	$t8,$t7,$t2
/*  f0f7de0:	5701002a */ 	bnel	$t8,$at,.L0f0f7e8c
/*  f0f7de4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f7de8:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0f7dec:	00000000 */ 	nop
/*  f0f7df0:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f7df4:	3c0d800a */ 	lui	$t5,%hi(g_Menus)
/*  f0f7df8:	3c1f8007 */ 	lui	$ra,%hi(g_MpPlayerNum)
/*  f0f7dfc:	27ff1448 */ 	addiu	$ra,$ra,%lo(g_MpPlayerNum)
/*  f0f7e00:	25ade000 */ 	addiu	$t5,$t5,%lo(g_Menus)
/*  f0f7e04:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f0f7e08:	11020005 */ 	beq	$t0,$v0,.L0f0f7e20
/*  f0f7e0c:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f0f7e10:	3c198009 */ 	lui	$t9,%hi(g_Is4Mb)
/*  f0f7e14:	93390af0 */ 	lbu	$t9,%lo(g_Is4Mb)($t9)
/*  f0f7e18:	5519001c */ 	bnel	$t0,$t9,.L0f0f7e8c
/*  f0f7e1c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f7e20:
/*  f0f7e20:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f0f7e24:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f7e28:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f7e2c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f7e30:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f7e34:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f7e38:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f7e3c:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f7e40:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f0f7e44:	9319083b */ 	lbu	$t9,0x83b($t8)
/*  f0f7e48:	57200006 */ 	bnezl	$t9,.L0f0f7e64
/*  f0f7e4c:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f0f7e50:	8d6e0000 */ 	lw	$t6,0x0($t3)
/*  f0f7e54:	25cf0016 */ 	addiu	$t7,$t6,0x16
/*  f0f7e58:	1000000b */ 	b	.L0f0f7e88
/*  f0f7e5c:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f0f7e60:	8d980000 */ 	lw	$t8,0x0($t4)
.L0f0f7e64:
/*  f0f7e64:	2719ffea */ 	addiu	$t9,$t8,-22
/*  f0f7e68:	10000007 */ 	b	.L0f0f7e88
/*  f0f7e6c:	ad990000 */ 	sw	$t9,0x0($t4)
.L0f0f7e70:
/*  f0f7e70:	ad660000 */ 	sw	$a2,0x0($t3)
/*  f0f7e74:	8fae003c */ 	lw	$t6,0x3c($sp)
/*  f0f7e78:	adc30000 */ 	sw	$v1,0x0($t6)
/*  f0f7e7c:	ad870000 */ 	sw	$a3,0x0($t4)
/*  f0f7e80:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f7e84:	ade40000 */ 	sw	$a0,0x0($t7)
.L0f0f7e88:
/*  f0f7e88:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f7e8c:
/*  f0f7e8c:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0f7e90:	03e00008 */ 	jr	$ra
/*  f0f7e94:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0f7e98
/*  f0f7e98:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0f7e9c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f7ea0:	00808025 */ 	or	$s0,$a0,$zero
/*  f0f7ea4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0f7ea8:	27a4004c */ 	addiu	$a0,$sp,0x4c
/*  f0f7eac:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f0f7eb0:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f0f7eb4:	0fc3ddca */ 	jal	func0f0f7728
/*  f0f7eb8:	27a70040 */ 	addiu	$a3,$sp,0x40
/*  f0f7ebc:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f0f7ec0:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*  f0f7ec4:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f0f7ec8:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f7ecc:	8e060024 */ 	lw	$a2,0x24($s0)
/*  f0f7ed0:	03191023 */ 	subu	$v0,$t8,$t9
/*  f0f7ed4:	2444fffa */ 	addiu	$a0,$v0,-6
/*  f0f7ed8:	01cf2823 */ 	subu	$a1,$t6,$t7
/*  f0f7edc:	24a5fffa */ 	addiu	$a1,$a1,-6
/*  f0f7ee0:	00c4082a */ 	slt	$at,$a2,$a0
/*  f0f7ee4:	10200002 */ 	beqz	$at,.L0f0f7ef0
/*  f0f7ee8:	00a01825 */ 	or	$v1,$a1,$zero
/*  f0f7eec:	00c02025 */ 	or	$a0,$a2,$zero
.L0f0f7ef0:
/*  f0f7ef0:	8e020028 */ 	lw	$v0,0x28($s0)
/*  f0f7ef4:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0f7ef8:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*  f0f7efc:	0045082a */ 	slt	$at,$v0,$a1
/*  f0f7f00:	10200002 */ 	beqz	$at,.L0f0f7f0c
/*  f0f7f04:	01095021 */ 	addu	$t2,$t0,$t1
/*  f0f7f08:	00401825 */ 	or	$v1,$v0,$zero
.L0f0f7f0c:
/*  f0f7f0c:	01445823 */ 	subu	$t3,$t2,$a0
/*  f0f7f10:	05610003 */ 	bgez	$t3,.L0f0f7f20
/*  f0f7f14:	000b6043 */ 	sra	$t4,$t3,0x1
/*  f0f7f18:	25610001 */ 	addiu	$at,$t3,0x1
/*  f0f7f1c:	00016043 */ 	sra	$t4,$at,0x1
.L0f0f7f20:
/*  f0f7f20:	ae0c002c */ 	sw	$t4,0x2c($s0)
/*  f0f7f24:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f0f7f28:	8fad0044 */ 	lw	$t5,0x44($sp)
/*  f0f7f2c:	8207006d */ 	lb	$a3,0x6d($s0)
/*  f0f7f30:	ae040034 */ 	sw	$a0,0x34($s0)
/*  f0f7f34:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0f7f38:	01e3c023 */ 	subu	$t8,$t7,$v1
/*  f0f7f3c:	07010003 */ 	bgez	$t8,.L0f0f7f4c
/*  f0f7f40:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0f7f44:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0f7f48:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f7f4c:
/*  f0f7f4c:	ae190030 */ 	sw	$t9,0x30($s0)
/*  f0f7f50:	10e00036 */ 	beqz	$a3,.L0f0f802c
/*  f0f7f54:	ae030038 */ 	sw	$v1,0x38($s0)
/*  f0f7f58:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0f7f5c:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f0f7f60:	0fc3dd65 */ 	jal	func0f0f7594
/*  f0f7f64:	27a60030 */ 	addiu	$a2,$sp,0x30
/*  f0f7f68:	8fa80030 */ 	lw	$t0,0x30($sp)
/*  f0f7f6c:	05030006 */ 	bgezl	$t0,.L0f0f7f88
/*  f0f7f70:	8fac0030 */ 	lw	$t4,0x30($sp)
/*  f0f7f74:	8e090034 */ 	lw	$t1,0x34($s0)
/*  f0f7f78:	240afffc */ 	addiu	$t2,$zero,-4
/*  f0f7f7c:	01495823 */ 	subu	$t3,$t2,$t1
/*  f0f7f80:	ae0b002c */ 	sw	$t3,0x2c($s0)
/*  f0f7f84:	8fac0030 */ 	lw	$t4,0x30($sp)
.L0f0f7f88:
/*  f0f7f88:	59800017 */ 	blezl	$t4,.L0f0f7fe8
/*  f0f7f8c:	8fa80034 */ 	lw	$t0,0x34($sp)
/*  f0f7f90:	0c002f40 */ 	jal	viGetViewLeft
/*  f0f7f94:	00000000 */ 	nop
/*  f0f7f98:	0c002f22 */ 	jal	viGetViewX
/*  f0f7f9c:	a7a2002e */ 	sh	$v0,0x2e($sp)
/*  f0f7fa0:	87ad002e */ 	lh	$t5,0x2e($sp)
/*  f0f7fa4:	3c0f8008 */ 	lui	$t7,%hi(g_ScreenWidthMultiplier)
/*  f0f7fa8:	8deffac0 */ 	lw	$t7,%lo(g_ScreenWidthMultiplier)($t7)
/*  f0f7fac:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f0f7fb0:	01cf001a */ 	div	$zero,$t6,$t7
/*  f0f7fb4:	0000c012 */ 	mflo	$t8
/*  f0f7fb8:	27190004 */ 	addiu	$t9,$t8,0x4
/*  f0f7fbc:	ae19002c */ 	sw	$t9,0x2c($s0)
/*  f0f7fc0:	15e00002 */ 	bnez	$t7,.L0f0f7fcc
/*  f0f7fc4:	00000000 */ 	nop
/*  f0f7fc8:	0007000d */ 	break	0x7
.L0f0f7fcc:
/*  f0f7fcc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f7fd0:	15e10004 */ 	bne	$t7,$at,.L0f0f7fe4
/*  f0f7fd4:	3c018000 */ 	lui	$at,0x8000
/*  f0f7fd8:	15c10002 */ 	bne	$t6,$at,.L0f0f7fe4
/*  f0f7fdc:	00000000 */ 	nop
/*  f0f7fe0:	0006000d */ 	break	0x6
.L0f0f7fe4:
/*  f0f7fe4:	8fa80034 */ 	lw	$t0,0x34($sp)
.L0f0f7fe8:
/*  f0f7fe8:	05030006 */ 	bgezl	$t0,.L0f0f8004
/*  f0f7fec:	8fac0034 */ 	lw	$t4,0x34($sp)
/*  f0f7ff0:	8e0a0038 */ 	lw	$t2,0x38($s0)
/*  f0f7ff4:	2409fffc */ 	addiu	$t1,$zero,-4
/*  f0f7ff8:	012a5823 */ 	subu	$t3,$t1,$t2
/*  f0f7ffc:	ae0b0030 */ 	sw	$t3,0x30($s0)
/*  f0f8000:	8fac0034 */ 	lw	$t4,0x34($sp)
.L0f0f8004:
/*  f0f8004:	5980000a */ 	blezl	$t4,.L0f0f8030
/*  f0f8008:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0f800c:	0c002f44 */ 	jal	viGetViewTop
/*  f0f8010:	00000000 */ 	nop
/*  f0f8014:	0c002f26 */ 	jal	viGetViewY
/*  f0f8018:	a7a2002e */ 	sh	$v0,0x2e($sp)
/*  f0f801c:	87ad002e */ 	lh	$t5,0x2e($sp)
/*  f0f8020:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f0f8024:	25cf0004 */ 	addiu	$t7,$t6,0x4
/*  f0f8028:	ae0f0030 */ 	sw	$t7,0x30($s0)
.L0f0f802c:
/*  f0f802c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0f8030:
/*  f0f8030:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0f8034:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f0f8038:	03e00008 */ 	jr	$ra
/*  f0f803c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0f8040
/*  f0f8040:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f0f8044:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f0f8048:	3c18800a */ 	lui	$t8,%hi(g_Menus)
/*  f0f804c:	2718e000 */ 	addiu	$t8,$t8,%lo(g_Menus)
/*  f0f8050:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f8054:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f8058:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f805c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f8060:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f8064:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f8068:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f806c:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f0f8070:	3c04800a */ 	lui	$a0,%hi(g_MenuData)
/*  f0f8074:	248419c0 */ 	addiu	$a0,$a0,%lo(g_MenuData)
/*  f0f8078:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f0f807c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f8080:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0f8084:	2419000a */ 	addiu	$t9,$zero,0xa
/*  f0f8088:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f808c:	a44004f4 */ 	sh	$zero,0x4f4($v0)
/*  f0f8090:	a4400460 */ 	sh	$zero,0x460($v0)
/*  f0f8094:	ac40065c */ 	sw	$zero,0x65c($v0)
/*  f0f8098:	ac4006d8 */ 	sw	$zero,0x6d8($v0)
/*  f0f809c:	ac40081c */ 	sw	$zero,0x81c($v0)
/*  f0f80a0:	ac4004f8 */ 	sw	$zero,0x4f8($v0)
/*  f0f80a4:	14a30007 */ 	bne	$a1,$v1,.L0f0f80c4
/*  f0f80a8:	a059083c */ 	sb	$t9,0x83c($v0)
/*  f0f80ac:	9049083b */ 	lbu	$t1,0x83b($v0)
/*  f0f80b0:	3c018007 */ 	lui	$at,%hi(g_PlayersWithControl)
/*  f0f80b4:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f80b8:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0f80bc:	002a0821 */ 	addu	$at,$at,$t2
/*  f0f80c0:	ac280750 */ 	sw	$t0,%lo(g_PlayersWithControl)($at)
.L0f0f80c4:
/*  f0f80c4:	8c8b0000 */ 	lw	$t3,0x0($a0)
/*  f0f80c8:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0f80cc:	256cffff */ 	addiu	$t4,$t3,-1
/*  f0f80d0:	14a3000a */ 	bne	$a1,$v1,.L0f0f80fc
/*  f0f80d4:	ac8c0000 */ 	sw	$t4,0x0($a0)
/*  f0f80d8:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0f80dc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f80e0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0f80e4:	904d0250 */ 	lbu	$t5,0x250($v0)
/*  f0f80e8:	55a10005 */ 	bnel	$t5,$at,.L0f0f8100
/*  f0f80ec:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0f80f0:	a04e0250 */ 	sb	$t6,0x250($v0)
/*  f0f80f4:	3c03800a */ 	lui	$v1,%hi(g_MenuData+0x4)
/*  f0f80f8:	8c6319c4 */ 	lw	$v1,%lo(g_MenuData+0x4)($v1)
.L0f0f80fc:
/*  f0f80fc:	24010007 */ 	addiu	$at,$zero,0x7
.L0f0f8100:
/*  f0f8100:	54610004 */ 	bnel	$v1,$at,.L0f0f8114
/*  f0f8104:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f8108:	0c003a57 */ 	jal	func0000e95c
/*  f0f810c:	2404005a */ 	addiu	$a0,$zero,0x5a
/*  f0f8110:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f8114:
/*  f0f8114:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f8118:	03e00008 */ 	jr	$ra
/*  f0f811c:	00000000 */ 	nop
);

void func0f0f8120(void)
{
	struct menuframe *prev = g_Menus[g_MpPlayerNum].curframe;
	s32 i;

	if (g_MenuData.unk66e > 0) {
		for (i = g_MenuData.unk66e; i >= 0; i--) {
			func0f0f3220(i);
		}
	}

	if (g_Menus[g_MpPlayerNum].curframe == prev) {
		while (g_Menus[g_MpPlayerNum].depth > 0) {
			menuPopDialog();
		}
	}
}

void func0f0f820c(struct menudialog *dialog, s32 arg1)
{
	s32 i;
	s32 prevplayernum = g_MpPlayerNum;

	for (i = 0; i < 4; i++) {
		if (g_Menus[i].curframe) {
			g_MpPlayerNum = i;
			func0f0f8120();
		}
	}

	g_MpPlayerNum = prevplayernum;

	g_MenuData.unk008 = arg1;
	g_MenuData.unk00c = dialog;
}

bool func0f0f82a8(s32 arg0)
{
	bool pass = g_MenuData.unk014 == 0;

	if (g_MenuData.unk015 == 1 || g_MenuData.unk015 == 4) {
		pass = false;
	}

	if (g_MenuData.unk014 != arg0) {
		g_MenuData.unk015 = arg0;
	}

	if (pass && g_MenuData.unk014 == 0) {
		g_MenuData.unk016 = 1;
	}
}

void func0f0f8300(void)
{
	s32 i;

	if (g_MenuData.count == 0) {
		for (i = 0; i < 4; i++) {
			g_MenuData.unk017[i] = 0;
		}
	}
}

GLOBAL_ASM(
glabel menuPushRootDialog
.late_rodata
glabel var7f1b2994
.word menuPushRootDialog+0x134 # f0f8464
glabel var7f1b2998
.word menuPushRootDialog+0x134 # f0f8464
glabel var7f1b299c
.word menuPushRootDialog+0x13c # f0f846c
glabel var7f1b29a0
.word menuPushRootDialog+0x13c # f0f846c
glabel var7f1b29a4
.word menuPushRootDialog+0x13c # f0f846c
glabel var7f1b29a8
.word menuPushRootDialog+0x134 # f0f8464
glabel var7f1b29ac
.word menuPushRootDialog+0x134 # f0f8464
glabel var7f1b29b0
.word menuPushRootDialog+0x134 # f0f8464
glabel var7f1b29b4
.word menuPushRootDialog+0x134 # f0f8464
glabel var7f1b29b8
.word menuPushRootDialog+0x134 # f0f8464
glabel var7f1b29bc
.word menuPushRootDialog+0x13c # f0f846c
glabel var7f1b29c0
.word menuPushRootDialog+0x13c # f0f846c
glabel var7f1b29c4
.word menuPushRootDialog+0x134 # f0f8464
glabel var7f1b29c8
.word menuPushRootDialog+0x23c # f0f856c
glabel var7f1b29cc
.word menuPushRootDialog+0x260 # f0f8590
glabel var7f1b29d0
.word menuPushRootDialog+0x204 # f0f8534
glabel var7f1b29d4
.word menuPushRootDialog+0x288 # f0f85b8
glabel var7f1b29d8
.word menuPushRootDialog+0x260 # f0f8590
glabel var7f1b29dc
.word menuPushRootDialog+0x260 # f0f8590
glabel var7f1b29e0
.word menuPushRootDialog+0x270 # f0f85a0
glabel var7f1b29e4
.word menuPushRootDialog+0x288 # f0f85b8
glabel var7f1b29e8
.word menuPushRootDialog+0x260 # f0f8590
glabel var7f1b29ec
.word menuPushRootDialog+0x214 # f0f8544
glabel var7f1b29f0
.word menuPushRootDialog+0x230 # f0f8560
glabel var7f1b29f4
.word menuPushRootDialog+0x288 # f0f85b8
glabel var7f1b29f8
.word menuPushRootDialog+0x260 # f0f8590
.text
/*  f0f8330:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f0f8334:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f0f8338:	3c03800a */ 	lui	$v1,%hi(g_MenuData)
/*  f0f833c:	246319c0 */ 	addiu	$v1,$v1,%lo(g_MenuData)
/*  f0f8340:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f8344:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f8348:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f834c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f8350:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f8354:	3c18800a */ 	lui	$t8,%hi(g_Menus)
/*  f0f8358:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f835c:	907905d5 */ 	lbu	$t9,0x5d5($v1)
/*  f0f8360:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f8364:	2718e000 */ 	addiu	$t8,$t8,%lo(g_Menus)
/*  f0f8368:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f0f836c:	904b083b */ 	lbu	$t3,0x83b($v0)
/*  f0f8370:	3329ff7f */ 	andi	$t1,$t9,0xff7f
/*  f0f8374:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0f8378:	a06905d5 */ 	sb	$t1,0x5d5($v1)
/*  f0f837c:	312a00ef */ 	andi	$t2,$t1,0xef
/*  f0f8380:	3c018007 */ 	lui	$at,%hi(g_PlayersWithControl)
/*  f0f8384:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f0f8388:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f838c:	a4400460 */ 	sh	$zero,0x460($v0)
/*  f0f8390:	a44004f4 */ 	sh	$zero,0x4f4($v0)
/*  f0f8394:	a06a05d5 */ 	sb	$t2,0x5d5($v1)
/*  f0f8398:	002c0821 */ 	addu	$at,$at,$t4
/*  f0f839c:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0f83a0:	ac200750 */ 	sw	$zero,%lo(g_PlayersWithControl)($at)
/*  f0f83a4:	0fc3c525 */ 	jal	func0f0f1494
/*  f0f83a8:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f0f83ac:	3c03800a */ 	lui	$v1,%hi(g_MenuData)
/*  f0f83b0:	246319c0 */ 	addiu	$v1,$v1,%lo(g_MenuData)
/*  f0f83b4:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f0f83b8:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f0f83bc:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0f83c0:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f0f83c4:	14a10011 */ 	bne	$a1,$at,.L0f0f840c
/*  f0f83c8:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f0f83cc:	3c0f8007 */ 	lui	$t7,%hi(g_MpPlayerNum)
/*  f0f83d0:	8def1448 */ 	lw	$t7,%lo(g_MpPlayerNum)($t7)
/*  f0f83d4:	3c19800a */ 	lui	$t9,%hi(g_Menus)
/*  f0f83d8:	2739e000 */ 	addiu	$t9,$t9,%lo(g_Menus)
/*  f0f83dc:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f83e0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f83e4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f83e8:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f83ec:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f83f0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f83f4:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f83f8:	03191021 */ 	addu	$v0,$t8,$t9
/*  f0f83fc:	90490e40 */ 	lbu	$t1,0xe40($v0)
/*  f0f8400:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0f8404:	352a0080 */ 	ori	$t2,$t1,0x80
/*  f0f8408:	a04a0e40 */ 	sb	$t2,0xe40($v0)
.L0f0f840c:
/*  f0f840c:	3c0b8007 */ 	lui	$t3,%hi(g_MpPlayerNum)
/*  f0f8410:	8d6b1448 */ 	lw	$t3,%lo(g_MpPlayerNum)($t3)
/*  f0f8414:	3c0d800a */ 	lui	$t5,%hi(g_Menus)
/*  f0f8418:	24aeffff */ 	addiu	$t6,$a1,-1
/*  f0f841c:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f0f8420:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0f8424:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0f8428:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f0f842c:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f0f8430:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0f8434:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f0f8438:	2dc1000d */ 	sltiu	$at,$t6,0xd
/*  f0f843c:	25ade000 */ 	addiu	$t5,$t5,%lo(g_Menus)
/*  f0f8440:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f0f8444:	10200009 */ 	beqz	$at,.L0f0f846c
/*  f0f8448:	00a03025 */ 	or	$a2,$a1,$zero
/*  f0f844c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f8450:	3c017f1b */ 	lui	$at,%hi(var7f1b2994)
/*  f0f8454:	002e0821 */ 	addu	$at,$at,$t6
/*  f0f8458:	8c2e2994 */ 	lw	$t6,%lo(var7f1b2994)($at)
/*  f0f845c:	01c00008 */ 	jr	$t6
/*  f0f8460:	00000000 */ 	nop
/*  f0f8464:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0f8468:	ac6f0000 */ 	sw	$t7,0x0($v1)
.L0f0f846c:
/*  f0f846c:	906805d5 */ 	lbu	$t0,0x5d5($v1)
/*  f0f8470:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f8474:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0f8478:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f847c:	3109ffbf */ 	andi	$t1,$t0,0xffbf
/*  f0f8480:	a0580820 */ 	sb	$t8,0x820($v0)
/*  f0f8484:	ac650004 */ 	sw	$a1,0x4($v1)
/*  f0f8488:	ac790008 */ 	sw	$t9,0x8($v1)
/*  f0f848c:	10c10007 */ 	beq	$a2,$at,.L0f0f84ac
/*  f0f8490:	a06905d5 */ 	sb	$t1,0x5d5($v1)
/*  f0f8494:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0f8498:	10c10004 */ 	beq	$a2,$at,.L0f0f84ac
/*  f0f849c:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0f84a0:	10c10002 */ 	beq	$a2,$at,.L0f0f84ac
/*  f0f84a4:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0f84a8:	14c10013 */ 	bne	$a2,$at,.L0f0f84f8
.L0f0f84ac:
/*  f0f84ac:	3c0a8009 */ 	lui	$t2,%hi(g_Is4Mb)
/*  f0f84b0:	914a0af0 */ 	lbu	$t2,%lo(g_Is4Mb)($t2)
/*  f0f84b4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f84b8:	51410010 */ 	beql	$t2,$at,.L0f0f84fc
/*  f0f84bc:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0f84c0:	906b05d4 */ 	lbu	$t3,0x5d4($v1)
/*  f0f84c4:	51600006 */ 	beqzl	$t3,.L0f0f84e0
/*  f0f84c8:	8c6f05d4 */ 	lw	$t7,0x5d4($v1)
/*  f0f84cc:	8c6c05cc */ 	lw	$t4,0x5cc($v1)
/*  f0f84d0:	000c72c0 */ 	sll	$t6,$t4,0xb
/*  f0f84d4:	05c30009 */ 	bgezl	$t6,.L0f0f84fc
/*  f0f84d8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0f84dc:	8c6f05d4 */ 	lw	$t7,0x5d4($v1)
.L0f0f84e0:
/*  f0f84e0:	000fcac0 */ 	sll	$t9,$t7,0xb
/*  f0f84e4:	07220005 */ 	bltzl	$t9,.L0f0f84fc
/*  f0f84e8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f0f84ec:	906905d5 */ 	lbu	$t1,0x5d5($v1)
/*  f0f84f0:	352a0008 */ 	ori	$t2,$t1,0x8
/*  f0f84f4:	a06a05d5 */ 	sb	$t2,0x5d5($v1)
.L0f0f84f8:
/*  f0f84f8:	8fa40020 */ 	lw	$a0,0x20($sp)
.L0f0f84fc:
/*  f0f84fc:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f0f8500:	afa60018 */ 	sw	$a2,0x18($sp)
/*  f0f8504:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f0f8508:	3c03800a */ 	lui	$v1,%hi(g_MenuData)
/*  f0f850c:	246319c0 */ 	addiu	$v1,$v1,%lo(g_MenuData)
/*  f0f8510:	24cbffff */ 	addiu	$t3,$a2,-1
/*  f0f8514:	2d61000d */ 	sltiu	$at,$t3,0xd
/*  f0f8518:	10200027 */ 	beqz	$at,.L0f0f85b8
/*  f0f851c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0f8520:	3c017f1b */ 	lui	$at,%hi(var7f1b29c8)
/*  f0f8524:	002b0821 */ 	addu	$at,$at,$t3
/*  f0f8528:	8c2b29c8 */ 	lw	$t3,%lo(var7f1b29c8)($at)
/*  f0f852c:	01600008 */ 	jr	$t3
/*  f0f8530:	00000000 */ 	nop
/*  f0f8534:	0fc3e0aa */ 	jal	func0f0f82a8
/*  f0f8538:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0f853c:	1000001e */ 	b	.L0f0f85b8
/*  f0f8540:	00000000 */ 	nop
/*  f0f8544:	0fc5b6c5 */ 	jal	musicStartForMenu
/*  f0f8548:	00000000 */ 	nop
/*  f0f854c:	3c03800a */ 	lui	$v1,%hi(g_MenuData)
/*  f0f8550:	246319c0 */ 	addiu	$v1,$v1,%lo(g_MenuData)
/*  f0f8554:	240c0009 */ 	addiu	$t4,$zero,0x9
/*  f0f8558:	10000017 */ 	b	.L0f0f85b8
/*  f0f855c:	a06c0014 */ 	sb	$t4,0x14($v1)
/*  f0f8560:	240d0009 */ 	addiu	$t5,$zero,0x9
/*  f0f8564:	10000014 */ 	b	.L0f0f85b8
/*  f0f8568:	a06d0014 */ 	sb	$t5,0x14($v1)
/*  f0f856c:	8fae0020 */ 	lw	$t6,0x20($sp)
/*  f0f8570:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f8574:	24180003 */ 	addiu	$t8,$zero,0x3
/*  f0f8578:	91cf0000 */ 	lbu	$t7,0x0($t6)
/*  f0f857c:	15e10004 */ 	bne	$t7,$at,.L0f0f8590
/*  f0f8580:	00000000 */ 	nop
/*  f0f8584:	a06005d4 */ 	sb	$zero,0x5d4($v1)
/*  f0f8588:	1000000b */ 	b	.L0f0f85b8
/*  f0f858c:	a0780015 */ 	sb	$t8,0x15($v1)
.L0f0f8590:
/*  f0f8590:	0fc3e0aa */ 	jal	func0f0f82a8
/*  f0f8594:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0f8598:	10000007 */ 	b	.L0f0f85b8
/*  f0f859c:	00000000 */ 	nop
/*  f0f85a0:	0fc5b6c5 */ 	jal	musicStartForMenu
/*  f0f85a4:	00000000 */ 	nop
/*  f0f85a8:	3c03800a */ 	lui	$v1,%hi(g_MenuData)
/*  f0f85ac:	246319c0 */ 	addiu	$v1,$v1,%lo(g_MenuData)
/*  f0f85b0:	24190005 */ 	addiu	$t9,$zero,0x5
/*  f0f85b4:	a0790014 */ 	sb	$t9,0x14($v1)
.L0f0f85b8:
/*  f0f85b8:	0fc3c2e4 */ 	jal	menuIsSoloMissionOrMp
/*  f0f85bc:	00000000 */ 	nop
/*  f0f85c0:	50400004 */ 	beqzl	$v0,.L0f0f85d4
/*  f0f85c4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f85c8:	0fc2eda7 */ 	jal	func0f0bb69c
/*  f0f85cc:	00000000 */ 	nop
/*  f0f85d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0f85d4:
/*  f0f85d4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0f85d8:	03e00008 */ 	jr	$ra
/*  f0f85dc:	00000000 */ 	nop
);

void func0f0f85e0(struct menudialog *dialog, s32 root)
{
	if (dialog == &g_MainMenuMenuDialog) {
		musicStartForMenu();
	}

	menuPushRootDialog(dialog, root);
	soloSetPaused(true);
	g_Vars.currentplayer->pausemode = PAUSEMODE_3;
}

u32 var800714dc = 0x00000078;

GLOBAL_ASM(
glabel func0f0f8634
/*  f0f8634:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f8638:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0f863c:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0f8640:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f8644:	3c058007 */ 	lui	$a1,%hi(var800714dc)
/*  f0f8648:	3c047f1b */ 	lui	$a0,%hi(var7f1b26f8)
/*  f0f864c:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f0f8650:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f0f8654:	248426f8 */ 	addiu	$a0,$a0,%lo(var7f1b26f8)
/*  f0f8658:	0c0036cc */ 	jal	func0000db30
/*  f0f865c:	24a514dc */ 	addiu	$a1,$a1,%lo(var800714dc)
/*  f0f8660:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f0f8664:	3c068007 */ 	lui	$a2,%hi(var800714dc)
/*  f0f8668:	8cc614dc */ 	lw	$a2,%lo(var800714dc)($a2)
/*  f0f866c:	8c440054 */ 	lw	$a0,0x54($v0)
/*  f0f8670:	0fc54f54 */ 	jal	func0f153d50
/*  f0f8674:	8c450058 */ 	lw	$a1,0x58($v0)
/*  f0f8678:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f0f867c:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f0f8680:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f0f8684:	0fc3d4d8 */ 	jal	func0f0f5360
/*  f0f8688:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f0f868c:	0fc54f93 */ 	jal	func0f153e4c
/*  f0f8690:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0f8694:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f8698:	8fa20018 */ 	lw	$v0,0x18($sp)
/*  f0f869c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f86a0:	03e00008 */ 	jr	$ra
/*  f0f86a4:	00000000 */ 	nop
);

u32 var800714e0 = 0x00000000;
u32 var800714e4 = 0x00000000;
u32 var800714e8 = 0x00000000;

GLOBAL_ASM(
glabel func0f0f86a8
/*  f0f86a8:	3c038007 */ 	lui	$v1,%hi(g_MpPlayerNum)
/*  f0f86ac:	8c631448 */ 	lw	$v1,%lo(g_MpPlayerNum)($v1)
/*  f0f86b0:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0f86b4:	3c0f800a */ 	lui	$t7,%hi(g_Menus)
/*  f0f86b8:	000370c0 */ 	sll	$t6,$v1,0x3
/*  f0f86bc:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f0f86c0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f86c4:	01c37021 */ 	addu	$t6,$t6,$v1
/*  f0f86c8:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0f86cc:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f0f86d0:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f0f86d4:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0f86d8:	25efe000 */ 	addiu	$t7,$t7,%lo(g_Menus)
/*  f0f86dc:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f0f86e0:	01cf8821 */ 	addu	$s1,$t6,$t7
/*  f0f86e4:	8e3004f8 */ 	lw	$s0,0x4f8($s1)
/*  f0f86e8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0f86ec:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f0f86f0:	1200012a */ 	beqz	$s0,.L0f0f8b9c
/*  f0f86f4:	3c02800a */ 	lui	$v0,%hi(g_MenuData+0x4)
/*  f0f86f8:	8c4219c4 */ 	lw	$v0,%lo(g_MenuData+0x4)($v0)
/*  f0f86fc:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f8700:	10410005 */ 	beq	$v0,$at,.L0f0f8718
/*  f0f8704:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0f8708:	10410003 */ 	beq	$v0,$at,.L0f0f8718
/*  f0f870c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f8710:	14410056 */ 	bne	$v0,$at,.L0f0f886c
/*  f0f8714:	3c0d8007 */ 	lui	$t5,%hi(var800714e0)
.L0f0f8718:
/*  f0f8718:	0c002f02 */ 	jal	viGetX
/*  f0f871c:	00000000 */ 	nop
/*  f0f8720:	3c0e8008 */ 	lui	$t6,%hi(g_ScreenWidthMultiplier)
/*  f0f8724:	8dcefac0 */ 	lw	$t6,%lo(g_ScreenWidthMultiplier)($t6)
/*  f0f8728:	3c188007 */ 	lui	$t8,%hi(g_MpPlayerNum)
/*  f0f872c:	8f181448 */ 	lw	$t8,%lo(g_MpPlayerNum)($t8)
/*  f0f8730:	000e7840 */ 	sll	$t7,$t6,0x1
/*  f0f8734:	004f001a */ 	div	$zero,$v0,$t7
/*  f0f8738:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0f873c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f8740:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f8744:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0f8748:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0f874c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f8750:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0f8754:	3c10800a */ 	lui	$s0,%hi(g_Menus+0x4f8)
/*  f0f8758:	02198021 */ 	addu	$s0,$s0,$t9
/*  f0f875c:	8e10e4f8 */ 	lw	$s0,%lo(g_Menus+0x4f8)($s0)
/*  f0f8760:	0000c012 */ 	mflo	$t8
/*  f0f8764:	8e0b001c */ 	lw	$t3,0x1c($s0)
/*  f0f8768:	8e0a0014 */ 	lw	$t2,0x14($s0)
/*  f0f876c:	05610003 */ 	bgez	$t3,.L0f0f877c
/*  f0f8770:	000b6043 */ 	sra	$t4,$t3,0x1
/*  f0f8774:	25610001 */ 	addiu	$at,$t3,0x1
/*  f0f8778:	00016043 */ 	sra	$t4,$at,0x1
.L0f0f877c:
/*  f0f877c:	014c6821 */ 	addu	$t5,$t2,$t4
/*  f0f8780:	15e00002 */ 	bnez	$t7,.L0f0f878c
/*  f0f8784:	00000000 */ 	nop
/*  f0f8788:	0007000d */ 	break	0x7
.L0f0f878c:
/*  f0f878c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f8790:	15e10004 */ 	bne	$t7,$at,.L0f0f87a4
/*  f0f8794:	3c018000 */ 	lui	$at,0x8000
/*  f0f8798:	14410002 */ 	bne	$v0,$at,.L0f0f87a4
/*  f0f879c:	00000000 */ 	nop
/*  f0f87a0:	0006000d */ 	break	0x6
.L0f0f87a4:
/*  f0f87a4:	3c01800a */ 	lui	$at,%hi(var8009de98)
/*  f0f87a8:	01b8c823 */ 	subu	$t9,$t5,$t8
/*  f0f87ac:	0c002f06 */ 	jal	viGetY
/*  f0f87b0:	ac39de98 */ 	sw	$t9,%lo(var8009de98)($at)
/*  f0f87b4:	3c0b8007 */ 	lui	$t3,%hi(g_MpPlayerNum)
/*  f0f87b8:	8d6b1448 */ 	lw	$t3,%lo(g_MpPlayerNum)($t3)
/*  f0f87bc:	3c0c800a */ 	lui	$t4,%hi(g_Menus)
/*  f0f87c0:	258ce000 */ 	addiu	$t4,$t4,%lo(g_Menus)
/*  f0f87c4:	000b50c0 */ 	sll	$t2,$t3,0x3
/*  f0f87c8:	014b5023 */ 	subu	$t2,$t2,$t3
/*  f0f87cc:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0f87d0:	014b5021 */ 	addu	$t2,$t2,$t3
/*  f0f87d4:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0f87d8:	014b5023 */ 	subu	$t2,$t2,$t3
/*  f0f87dc:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0f87e0:	014c8821 */ 	addu	$s1,$t2,$t4
/*  f0f87e4:	8e3004f8 */ 	lw	$s0,0x4f8($s1)
/*  f0f87e8:	02203025 */ 	or	$a2,$s1,$zero
/*  f0f87ec:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0f87f0:	8e0f0020 */ 	lw	$t7,0x20($s0)
/*  f0f87f4:	8e0e0018 */ 	lw	$t6,0x18($s0)
/*  f0f87f8:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f87fc:	05e10003 */ 	bgez	$t7,.L0f0f880c
/*  f0f8800:	000f6843 */ 	sra	$t5,$t7,0x1
/*  f0f8804:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f0f8808:	00016843 */ 	sra	$t5,$at,0x1
.L0f0f880c:
/*  f0f880c:	01cdc021 */ 	addu	$t8,$t6,$t5
/*  f0f8810:	04410003 */ 	bgez	$v0,.L0f0f8820
/*  f0f8814:	0002c843 */ 	sra	$t9,$v0,0x1
/*  f0f8818:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0f881c:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0f8820:
/*  f0f8820:	3c01800a */ 	lui	$at,%hi(var8009de9c)
/*  f0f8824:	03195823 */ 	subu	$t3,$t8,$t9
/*  f0f8828:	ac2bde9c */ 	sw	$t3,%lo(var8009de9c)($at)
/*  f0f882c:	0fc3e18d */ 	jal	func0f0f8634
/*  f0f8830:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f8834:	3c0a8007 */ 	lui	$t2,%hi(g_MpPlayerNum)
/*  f0f8838:	8d4a1448 */ 	lw	$t2,%lo(g_MpPlayerNum)($t2)
/*  f0f883c:	3c0f800a */ 	lui	$t7,%hi(g_Menus)
/*  f0f8840:	25efe000 */ 	addiu	$t7,$t7,%lo(g_Menus)
/*  f0f8844:	000a60c0 */ 	sll	$t4,$t2,0x3
/*  f0f8848:	018a6023 */ 	subu	$t4,$t4,$t2
/*  f0f884c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0f8850:	018a6021 */ 	addu	$t4,$t4,$t2
/*  f0f8854:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f0f8858:	018a6023 */ 	subu	$t4,$t4,$t2
/*  f0f885c:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f0f8860:	018f8821 */ 	addu	$s1,$t4,$t7
/*  f0f8864:	1000005b */ 	b	.L0f0f89d4
/*  f0f8868:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0f886c:
/*  f0f886c:	25ad14e0 */ 	addiu	$t5,$t5,%lo(var800714e0)
/*  f0f8870:	8da10000 */ 	lw	$at,0x0($t5)
/*  f0f8874:	8dab0004 */ 	lw	$t3,0x4($t5)
/*  f0f8878:	27ae0088 */ 	addiu	$t6,$sp,0x88
/*  f0f887c:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0f8880:	adcb0004 */ 	sw	$t3,0x4($t6)
/*  f0f8884:	862204f4 */ 	lh	$v0,0x4f4($s1)
/*  f0f8888:	000350c0 */ 	sll	$t2,$v1,0x3
/*  f0f888c:	01435023 */ 	subu	$t2,$t2,$v1
/*  f0f8890:	18400028 */ 	blez	$v0,.L0f0f8934
/*  f0f8894:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f8898:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0f889c:	01435021 */ 	addu	$t2,$t2,$v1
/*  f0f88a0:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0f88a4:	01435023 */ 	subu	$t2,$t2,$v1
/*  f0f88a8:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0f88ac:	3c0f800a */ 	lui	$t7,%hi(g_Menus)
/*  f0f88b0:	00024880 */ 	sll	$t1,$v0,0x2
/*  f0f88b4:	01224823 */ 	subu	$t1,$t1,$v0
/*  f0f88b8:	25efe000 */ 	addiu	$t7,$t7,%lo(g_Menus)
/*  f0f88bc:	254c0464 */ 	addiu	$t4,$t2,0x464
/*  f0f88c0:	44800000 */ 	mtc1	$zero,$f0
/*  f0f88c4:	018f4021 */ 	addu	$t0,$t4,$t7
/*  f0f88c8:	000948c0 */ 	sll	$t1,$t1,0x3
.L0f0f88cc:
/*  f0f88cc:	81050014 */ 	lb	$a1,0x14($t0)
/*  f0f88d0:	24e70018 */ 	addiu	$a3,$a3,0x18
/*  f0f88d4:	01003025 */ 	or	$a2,$t0,$zero
/*  f0f88d8:	18a00013 */ 	blez	$a1,.L0f0f8928
/*  f0f88dc:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f88e0:	00c02025 */ 	or	$a0,$a2,$zero
.L0f0f88e4:
/*  f0f88e4:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0f88e8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0f88ec:	5050000c */ 	beql	$v0,$s0,.L0f0f8920
/*  f0f88f0:	0065082a */ 	slt	$at,$v1,$a1
/*  f0f88f4:	9059003c */ 	lbu	$t9,0x3c($v0)
/*  f0f88f8:	57200007 */ 	bnezl	$t9,.L0f0f8918
/*  f0f88fc:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f0f8900:	c4440040 */ 	lwc1	$f4,0x40($v0)
/*  f0f8904:	4604003e */ 	c.le.s	$f0,$f4
/*  f0f8908:	00000000 */ 	nop
/*  f0f890c:	45020004 */ 	bc1fl	.L0f0f8920
/*  f0f8910:	0065082a */ 	slt	$at,$v1,$a1
/*  f0f8914:	afa20088 */ 	sw	$v0,0x88($sp)
.L0f0f8918:
/*  f0f8918:	80c50014 */ 	lb	$a1,0x14($a2)
/*  f0f891c:	0065082a */ 	slt	$at,$v1,$a1
.L0f0f8920:
/*  f0f8920:	1420fff0 */ 	bnez	$at,.L0f0f88e4
/*  f0f8924:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f0f8928:
/*  f0f8928:	00e9082a */ 	slt	$at,$a3,$t1
/*  f0f892c:	1420ffe7 */ 	bnez	$at,.L0f0f88cc
/*  f0f8930:	25080018 */ 	addiu	$t0,$t0,0x18
.L0f0f8934:
/*  f0f8934:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f0f8938:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0f893c:	02203025 */ 	or	$a2,$s1,$zero
/*  f0f8940:	10a00011 */ 	beqz	$a1,.L0f0f8988
/*  f0f8944:	00000000 */ 	nop
/*  f0f8948:	0fc3e18d */ 	jal	func0f0f8634
/*  f0f894c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f8950:	3c188007 */ 	lui	$t8,%hi(g_MpPlayerNum)
/*  f0f8954:	8f181448 */ 	lw	$t8,%lo(g_MpPlayerNum)($t8)
/*  f0f8958:	3c0d800a */ 	lui	$t5,%hi(g_Menus)
/*  f0f895c:	25ade000 */ 	addiu	$t5,$t5,%lo(g_Menus)
/*  f0f8960:	001870c0 */ 	sll	$t6,$t8,0x3
/*  f0f8964:	01d87023 */ 	subu	$t6,$t6,$t8
/*  f0f8968:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f896c:	01d87021 */ 	addu	$t6,$t6,$t8
/*  f0f8970:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0f8974:	01d87023 */ 	subu	$t6,$t6,$t8
/*  f0f8978:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0f897c:	01cd8821 */ 	addu	$s1,$t6,$t5
/*  f0f8980:	8e3004f8 */ 	lw	$s0,0x4f8($s1)
/*  f0f8984:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0f8988:
/*  f0f8988:	12000012 */ 	beqz	$s0,.L0f0f89d4
/*  f0f898c:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0f8990:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f8994:	02203025 */ 	or	$a2,$s1,$zero
/*  f0f8998:	0fc3e18d */ 	jal	func0f0f8634
/*  f0f899c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0f89a0:	3c0b8007 */ 	lui	$t3,%hi(g_MpPlayerNum)
/*  f0f89a4:	8d6b1448 */ 	lw	$t3,%lo(g_MpPlayerNum)($t3)
/*  f0f89a8:	3c0c800a */ 	lui	$t4,%hi(g_Menus)
/*  f0f89ac:	258ce000 */ 	addiu	$t4,$t4,%lo(g_Menus)
/*  f0f89b0:	000b50c0 */ 	sll	$t2,$t3,0x3
/*  f0f89b4:	014b5023 */ 	subu	$t2,$t2,$t3
/*  f0f89b8:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0f89bc:	014b5021 */ 	addu	$t2,$t2,$t3
/*  f0f89c0:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0f89c4:	014b5023 */ 	subu	$t2,$t2,$t3
/*  f0f89c8:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0f89cc:	014c8821 */ 	addu	$s1,$t2,$t4
/*  f0f89d0:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0f89d4:
/*  f0f89d4:	822f0df8 */ 	lb	$t7,0xdf8($s1)
/*  f0f89d8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f89dc:	51e10070 */ 	beql	$t7,$at,.L0f0f8ba0
/*  f0f89e0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0f89e4:	8e3904f8 */ 	lw	$t9,0x4f8($s1)
/*  f0f89e8:	3c0b800a */ 	lui	$t3,%hi(g_MenuData)
/*  f0f89ec:	8f380000 */ 	lw	$t8,0x0($t9)
/*  f0f89f0:	8f0e0010 */ 	lw	$t6,0x10($t8)
/*  f0f89f4:	31cd0080 */ 	andi	$t5,$t6,0x80
/*  f0f89f8:	55a00069 */ 	bnezl	$t5,.L0f0f8ba0
/*  f0f89fc:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0f8a00:	8d6b19c0 */ 	lw	$t3,%lo(g_MenuData)($t3)
/*  f0f8a04:	27a40080 */ 	addiu	$a0,$sp,0x80
/*  f0f8a08:	27a5007c */ 	addiu	$a1,$sp,0x7c
/*  f0f8a0c:	29610002 */ 	slti	$at,$t3,0x2
/*  f0f8a10:	1420001c */ 	bnez	$at,.L0f0f8a84
/*  f0f8a14:	27a60078 */ 	addiu	$a2,$sp,0x78
/*  f0f8a18:	0fc3ddca */ 	jal	func0f0f7728
/*  f0f8a1c:	27a70074 */ 	addiu	$a3,$sp,0x74
/*  f0f8a20:	3c0c8007 */ 	lui	$t4,%hi(g_MpPlayerNum)
/*  f0f8a24:	8d8c1448 */ 	lw	$t4,%lo(g_MpPlayerNum)($t4)
/*  f0f8a28:	3c19800a */ 	lui	$t9,%hi(g_Menus+0xdf8)
/*  f0f8a2c:	8faa0074 */ 	lw	$t2,0x74($sp)
/*  f0f8a30:	000c78c0 */ 	sll	$t7,$t4,0x3
/*  f0f8a34:	01ec7823 */ 	subu	$t7,$t7,$t4
/*  f0f8a38:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f8a3c:	01ec7821 */ 	addu	$t7,$t7,$t4
/*  f0f8a40:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f8a44:	01ec7823 */ 	subu	$t7,$t7,$t4
/*  f0f8a48:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f8a4c:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f0f8a50:	8339edf8 */ 	lb	$t9,%lo(g_Menus+0xdf8)($t9)
/*  f0f8a54:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0f8a58:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f0f8a5c:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f0f8a60:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f0f8a64:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0f8a68:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f8a6c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0f8a70:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0f8a74:	0fc3c33a */ 	jal	func0f0f0ce8
/*  f0f8a78:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0f8a7c:	10000047 */ 	b	.L0f0f8b9c
/*  f0f8a80:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0f8a84:
/*  f0f8a84:	0c002f40 */ 	jal	viGetViewLeft
/*  f0f8a88:	00000000 */ 	nop
/*  f0f8a8c:	3c188008 */ 	lui	$t8,%hi(g_ScreenWidthMultiplier)
/*  f0f8a90:	8f18fac0 */ 	lw	$t8,%lo(g_ScreenWidthMultiplier)($t8)
/*  f0f8a94:	0058001a */ 	div	$zero,$v0,$t8
/*  f0f8a98:	00007012 */ 	mflo	$t6
/*  f0f8a9c:	afae0070 */ 	sw	$t6,0x70($sp)
/*  f0f8aa0:	17000002 */ 	bnez	$t8,.L0f0f8aac
/*  f0f8aa4:	00000000 */ 	nop
/*  f0f8aa8:	0007000d */ 	break	0x7
.L0f0f8aac:
/*  f0f8aac:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f8ab0:	17010004 */ 	bne	$t8,$at,.L0f0f8ac4
/*  f0f8ab4:	3c018000 */ 	lui	$at,0x8000
/*  f0f8ab8:	14410002 */ 	bne	$v0,$at,.L0f0f8ac4
/*  f0f8abc:	00000000 */ 	nop
/*  f0f8ac0:	0006000d */ 	break	0x6
.L0f0f8ac4:
/*  f0f8ac4:	0c002f44 */ 	jal	viGetViewTop
/*  f0f8ac8:	00000000 */ 	nop
/*  f0f8acc:	0c002f40 */ 	jal	viGetViewLeft
/*  f0f8ad0:	00408825 */ 	or	$s1,$v0,$zero
/*  f0f8ad4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f8ad8:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f0f8adc:	0c002f22 */ 	jal	viGetViewX
/*  f0f8ae0:	01a08025 */ 	or	$s0,$t5,$zero
/*  f0f8ae4:	3c0a8008 */ 	lui	$t2,%hi(g_ScreenWidthMultiplier)
/*  f0f8ae8:	8d4afac0 */ 	lw	$t2,%lo(g_ScreenWidthMultiplier)($t2)
/*  f0f8aec:	00505821 */ 	addu	$t3,$v0,$s0
/*  f0f8af0:	016a001a */ 	div	$zero,$t3,$t2
/*  f0f8af4:	00006012 */ 	mflo	$t4
/*  f0f8af8:	afac0068 */ 	sw	$t4,0x68($sp)
/*  f0f8afc:	15400002 */ 	bnez	$t2,.L0f0f8b08
/*  f0f8b00:	00000000 */ 	nop
/*  f0f8b04:	0007000d */ 	break	0x7
.L0f0f8b08:
/*  f0f8b08:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f8b0c:	15410004 */ 	bne	$t2,$at,.L0f0f8b20
/*  f0f8b10:	3c018000 */ 	lui	$at,0x8000
/*  f0f8b14:	15610002 */ 	bne	$t3,$at,.L0f0f8b20
/*  f0f8b18:	00000000 */ 	nop
/*  f0f8b1c:	0006000d */ 	break	0x6
.L0f0f8b20:
/*  f0f8b20:	0c002f44 */ 	jal	viGetViewTop
/*  f0f8b24:	00000000 */ 	nop
/*  f0f8b28:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0f8b2c:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f0f8b30:	0c002f26 */ 	jal	viGetViewY
/*  f0f8b34:	01e08025 */ 	or	$s0,$t7,$zero
/*  f0f8b38:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f0f8b3c:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f0f8b40:	3c0b800a */ 	lui	$t3,%hi(g_Menus+0xdf8)
/*  f0f8b44:	0050c821 */ 	addu	$t9,$v0,$s0
/*  f0f8b48:	000e68c0 */ 	sll	$t5,$t6,0x3
/*  f0f8b4c:	01ae6823 */ 	subu	$t5,$t5,$t6
/*  f0f8b50:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0f8b54:	01ae6821 */ 	addu	$t5,$t5,$t6
/*  f0f8b58:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0f8b5c:	01ae6823 */ 	subu	$t5,$t5,$t6
/*  f0f8b60:	000d6900 */ 	sll	$t5,$t5,0x4
/*  f0f8b64:	016d5821 */ 	addu	$t3,$t3,$t5
/*  f0f8b68:	816bedf8 */ 	lb	$t3,%lo(g_Menus+0xdf8)($t3)
/*  f0f8b6c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0f8b70:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0f8b74:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0f8b78:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0f8b7c:	8fa50070 */ 	lw	$a1,0x70($sp)
/*  f0f8b80:	02203025 */ 	or	$a2,$s1,$zero
/*  f0f8b84:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f0f8b88:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0f8b8c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0f8b90:	0fc3c33a */ 	jal	func0f0f0ce8
/*  f0f8b94:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0f8b98:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0f8b9c:
/*  f0f8b9c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0f8ba0:
/*  f0f8ba0:	8fa20098 */ 	lw	$v0,0x98($sp)
/*  f0f8ba4:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f0f8ba8:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f0f8bac:	03e00008 */ 	jr	$ra
/*  f0f8bb0:	27bd0098 */ 	addiu	$sp,$sp,0x98
);

GLOBAL_ASM(
glabel func0f0f8bb4
/*  f0f8bb4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0f8bb8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f8bbc:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0f8bc0:	00803825 */ 	or	$a3,$a0,$zero
/*  f0f8bc4:	10c00008 */ 	beqz	$a2,.L0f0f8be8
/*  f0f8bc8:	ac850008 */ 	sw	$a1,0x8($a0)
/*  f0f8bcc:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f0f8bd0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0f8bd4:	0c0048f2 */ 	jal	malloc
/*  f0f8bd8:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f0f8bdc:	8fa70018 */ 	lw	$a3,0x18($sp)
/*  f0f8be0:	10000002 */ 	b	.L0f0f8bec
/*  f0f8be4:	ace20004 */ 	sw	$v0,0x4($a3)
.L0f0f8be8:
/*  f0f8be8:	ace00004 */ 	sw	$zero,0x4($a3)
.L0f0f8bec:
/*  f0f8bec:	44800000 */ 	mtc1	$zero,$f0
/*  f0f8bf0:	90f805b1 */ 	lbu	$t8,0x5b1($a3)
/*  f0f8bf4:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0f8bf8:	e4e0054c */ 	swc1	$f0,0x54c($a3)
/*  f0f8bfc:	3308ff7f */ 	andi	$t0,$t8,0xff7f
/*  f0f8c00:	310a00bf */ 	andi	$t2,$t0,0xbf
/*  f0f8c04:	c4e4054c */ 	lwc1	$f4,0x54c($a3)
/*  f0f8c08:	a0e805b1 */ 	sb	$t0,0x5b1($a3)
/*  f0f8c0c:	314c00ef */ 	andi	$t4,$t2,0xef
/*  f0f8c10:	a0ea05b1 */ 	sb	$t2,0x5b1($a3)
/*  f0f8c14:	340fffff */ 	dli	$t7,0xffff
/*  f0f8c18:	a0ec05b1 */ 	sb	$t4,0x5b1($a3)
/*  f0f8c1c:	318d00fb */ 	andi	$t5,$t4,0xfb
/*  f0f8c20:	a0e00000 */ 	sb	$zero,0x0($a3)
/*  f0f8c24:	acef000c */ 	sw	$t7,0xc($a3)
/*  f0f8c28:	ace00054 */ 	sw	$zero,0x54($a3)
/*  f0f8c2c:	ace00010 */ 	sw	$zero,0x10($a3)
/*  f0f8c30:	ace0056c */ 	sw	$zero,0x56c($a3)
/*  f0f8c34:	ace00570 */ 	sw	$zero,0x570($a3)
/*  f0f8c38:	ace005b4 */ 	sw	$zero,0x5b4($a3)
/*  f0f8c3c:	a0ed05b1 */ 	sb	$t5,0x5b1($a3)
/*  f0f8c40:	a4e20002 */ 	sh	$v0,0x2($a3)
/*  f0f8c44:	a4e2056a */ 	sh	$v0,0x56a($a3)
/*  f0f8c48:	e4e00538 */ 	swc1	$f0,0x538($a3)
/*  f0f8c4c:	e4e00510 */ 	swc1	$f0,0x510($a3)
/*  f0f8c50:	e4e0053c */ 	swc1	$f0,0x53c($a3)
/*  f0f8c54:	e4e00514 */ 	swc1	$f0,0x514($a3)
/*  f0f8c58:	e4e00540 */ 	swc1	$f0,0x540($a3)
/*  f0f8c5c:	e4e00518 */ 	swc1	$f0,0x518($a3)
/*  f0f8c60:	e4e00544 */ 	swc1	$f0,0x544($a3)
/*  f0f8c64:	e4e0051c */ 	swc1	$f0,0x51c($a3)
/*  f0f8c68:	e4e00548 */ 	swc1	$f0,0x548($a3)
/*  f0f8c6c:	e4e00520 */ 	swc1	$f0,0x520($a3)
/*  f0f8c70:	e4e00550 */ 	swc1	$f0,0x550($a3)
/*  f0f8c74:	e4e00528 */ 	swc1	$f0,0x528($a3)
/*  f0f8c78:	e4e00534 */ 	swc1	$f0,0x534($a3)
/*  f0f8c7c:	e4e00530 */ 	swc1	$f0,0x530($a3)
/*  f0f8c80:	e4e0052c */ 	swc1	$f0,0x52c($a3)
/*  f0f8c84:	e4e40524 */ 	swc1	$f4,0x524($a3)
/*  f0f8c88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f8c8c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0f8c90:	03e00008 */ 	jr	$ra
/*  f0f8c94:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0f8c98
.late_rodata
glabel var7f1b29fc
.word 0xc0490fdb
glabel var7f1b2a00
.word 0xc34d8000
glabel var7f1b2a04
.word 0x4374b333
glabel var7f1b2a08
.word 0x4288999a
glabel var7f1b2a0c
.word 0x3dfa0a52
.text
/*  f0f8c98:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0f8c9c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0f8ca0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0f8ca4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0f8ca8:	0fc442fc */ 	jal	func0f110bf0
/*  f0f8cac:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0f8cb0:	3c0e8009 */ 	lui	$t6,%hi(g_Is4Mb)
/*  f0f8cb4:	91ce0af0 */ 	lbu	$t6,%lo(g_Is4Mb)($t6)
/*  f0f8cb8:	3c01800a */ 	lui	$at,%hi(var8009dfc0)
/*  f0f8cbc:	ac20dfc0 */ 	sw	$zero,%lo(var8009dfc0)($at)
/*  f0f8cc0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f8cc4:	11c10005 */ 	beq	$t6,$at,.L0f0f8cdc
/*  f0f8cc8:	24044b00 */ 	addiu	$a0,$zero,0x4b00
/*  f0f8ccc:	0c0048f2 */ 	jal	malloc
/*  f0f8cd0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0f8cd4:	3c01800a */ 	lui	$at,%hi(var8009dfbc)
/*  f0f8cd8:	ac22dfbc */ 	sw	$v0,%lo(var8009dfbc)($at)
.L0f0f8cdc:
/*  f0f8cdc:	3c11800a */ 	lui	$s1,%hi(g_MenuData)
/*  f0f8ce0:	263119c0 */ 	addiu	$s1,$s1,%lo(g_MenuData)
/*  f0f8ce4:	922f05d5 */ 	lbu	$t7,0x5d5($s1)
/*  f0f8ce8:	3c12800b */ 	lui	$s2,%hi(var800ab5a8)
/*  f0f8cec:	2652b5a8 */ 	addiu	$s2,$s2,%lo(var800ab5a8)
/*  f0f8cf0:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8cf4:	31f8ff7f */ 	andi	$t8,$t7,0xff7f
/*  f0f8cf8:	a23805d5 */ 	sb	$t8,0x5d5($s1)
/*  f0f8cfc:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d00:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f0f8d04:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8d08:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d0c:	24840048 */ 	addiu	$a0,$a0,0x48
/*  f0f8d10:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8d14:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d18:	24840264 */ 	addiu	$a0,$a0,0x264
/*  f0f8d1c:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8d20:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d24:	24840270 */ 	addiu	$a0,$a0,0x270
/*  f0f8d28:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8d2c:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d30:	2484027c */ 	addiu	$a0,$a0,0x27c
/*  f0f8d34:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8d38:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d3c:	24840288 */ 	addiu	$a0,$a0,0x288
/*  f0f8d40:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8d44:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d48:	24840294 */ 	addiu	$a0,$a0,0x294
/*  f0f8d4c:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x4b4)
/*  f0f8d50:	8f39a474 */ 	lw	$t9,%lo(g_Vars+0x4b4)($t9)
/*  f0f8d54:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0f8d58:	24100090 */ 	addiu	$s0,$zero,0x90
/*  f0f8d5c:	17210011 */ 	bne	$t9,$at,.L0f0f8da4
/*  f0f8d60:	00000000 */ 	nop
/*  f0f8d64:	8e480000 */ 	lw	$t0,0x0($s2)
.L0f0f8d68:
/*  f0f8d68:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d6c:	02082021 */ 	addu	$a0,$s0,$t0
/*  f0f8d70:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f0f8d74:	24010198 */ 	addiu	$at,$zero,0x198
/*  f0f8d78:	5601fffb */ 	bnel	$s0,$at,.L0f0f8d68
/*  f0f8d7c:	8e480000 */ 	lw	$t0,0x0($s2)
/*  f0f8d80:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8d84:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d88:	24840198 */ 	addiu	$a0,$a0,0x198
/*  f0f8d8c:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8d90:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8d94:	248401b0 */ 	addiu	$a0,$a0,0x1b0
/*  f0f8d98:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8d9c:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8da0:	248401a4 */ 	addiu	$a0,$a0,0x1a4
.L0f0f8da4:
/*  f0f8da4:	3c05800a */ 	lui	$a1,%hi(g_Vars+0x314)
/*  f0f8da8:	8ca5a2d4 */ 	lw	$a1,%lo(g_Vars+0x314)($a1)
/*  f0f8dac:	10a00006 */ 	beqz	$a1,.L0f0f8dc8
/*  f0f8db0:	00000000 */ 	nop
/*  f0f8db4:	8e440000 */ 	lw	$a0,0x0($s2)
/*  f0f8db8:	0fc2ce62 */ 	jal	func0f0b3988
/*  f0f8dbc:	248401a4 */ 	addiu	$a0,$a0,0x1a4
/*  f0f8dc0:	3c05800a */ 	lui	$a1,%hi(g_Vars+0x314)
/*  f0f8dc4:	8ca5a2d4 */ 	lw	$a1,%lo(g_Vars+0x314)($a1)
.L0f0f8dc8:
/*  f0f8dc8:	3c04800a */ 	lui	$a0,%hi(g_Vars+0x4b4)
/*  f0f8dcc:	3c02800a */ 	lui	$v0,%hi(g_Menus)
/*  f0f8dd0:	3c03800a */ 	lui	$v1,%hi(g_MenuData)
/*  f0f8dd4:	246319c0 */ 	addiu	$v1,$v1,%lo(g_MenuData)
/*  f0f8dd8:	2442e000 */ 	addiu	$v0,$v0,%lo(g_Menus)
/*  f0f8ddc:	8c84a474 */ 	lw	$a0,%lo(g_Vars+0x4b4)($a0)
.L0f0f8de0:
/*  f0f8de0:	24420e70 */ 	addiu	$v0,$v0,0xe70
/*  f0f8de4:	0043082b */ 	sltu	$at,$v0,$v1
/*  f0f8de8:	1420fffd */ 	bnez	$at,.L0f0f8de0
/*  f0f8dec:	ac40f9d4 */ 	sw	$zero,-0x62c($v0)
/*  f0f8df0:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0f8df4:	1481000b */ 	bne	$a0,$at,.L0f0f8e24
/*  f0f8df8:	ae200020 */ 	sw	$zero,0x20($s1)
/*  f0f8dfc:	3c02800a */ 	lui	$v0,%hi(g_MissionConfig)
/*  f0f8e00:	2442dfe8 */ 	addiu	$v0,$v0,%lo(g_MissionConfig)
/*  f0f8e04:	90490003 */ 	lbu	$t1,0x3($v0)
/*  f0f8e08:	904d0000 */ 	lbu	$t5,0x0($v0)
/*  f0f8e0c:	312bff7f */ 	andi	$t3,$t1,0xff7f
/*  f0f8e10:	a04b0003 */ 	sb	$t3,0x3($v0)
/*  f0f8e14:	316c00bf */ 	andi	$t4,$t3,0xbf
/*  f0f8e18:	31aefffe */ 	andi	$t6,$t5,0xfffe
/*  f0f8e1c:	a04c0003 */ 	sb	$t4,0x3($v0)
/*  f0f8e20:	a04e0000 */ 	sb	$t6,0x0($v0)
.L0f0f8e24:
/*  f0f8e24:	14a0004e */ 	bnez	$a1,.L0f0f8f60
/*  f0f8e28:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0f8e2c:	14810002 */ 	bne	$a0,$at,.L0f0f8e38
/*  f0f8e30:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f8e34:	24020004 */ 	addiu	$v0,$zero,0x4
.L0f0f8e38:
/*  f0f8e38:	2401005d */ 	addiu	$at,$zero,0x5d
/*  f0f8e3c:	14810002 */ 	bne	$a0,$at,.L0f0f8e48
/*  f0f8e40:	3c10800a */ 	lui	$s0,%hi(g_Menus+0x840)
/*  f0f8e44:	24020004 */ 	addiu	$v0,$zero,0x4
.L0f0f8e48:
/*  f0f8e48:	18400015 */ 	blez	$v0,.L0f0f8ea0
/*  f0f8e4c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0f8e50:	2610e840 */ 	addiu	$s0,$s0,%lo(g_Menus+0x840)
.L0f0f8e54:
/*  f0f8e54:	3c0f8009 */ 	lui	$t7,%hi(g_Is4Mb)
/*  f0f8e58:	91ef0af0 */ 	lbu	$t7,%lo(g_Is4Mb)($t7)
/*  f0f8e5c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f8e60:	02002025 */ 	or	$a0,$s0,$zero
/*  f0f8e64:	15e10003 */ 	bne	$t7,$at,.L0f0f8e74
/*  f0f8e68:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0f8e6c:	10000003 */ 	b	.L0f0f8e7c
/*  f0f8e70:	3405b400 */ 	dli	$a1,0xb400
.L0f0f8e74:
/*  f0f8e74:	3c050002 */ 	lui	$a1,0x2
/*  f0f8e78:	34a55800 */ 	ori	$a1,$a1,0x5800
.L0f0f8e7c:
/*  f0f8e7c:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f0f8e80:	0fc3e2ed */ 	jal	func0f0f8bb4
/*  f0f8e84:	afa3002c */ 	sw	$v1,0x2c($sp)
/*  f0f8e88:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f0f8e8c:	8fa20028 */ 	lw	$v0,0x28($sp)
/*  f0f8e90:	26100e70 */ 	addiu	$s0,$s0,0xe70
/*  f0f8e94:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0f8e98:	1462ffee */ 	bne	$v1,$v0,.L0f0f8e54
/*  f0f8e9c:	00000000 */ 	nop
.L0f0f8ea0:
/*  f0f8ea0:	3c188009 */ 	lui	$t8,%hi(g_Is4Mb)
/*  f0f8ea4:	93180af0 */ 	lbu	$t8,%lo(g_Is4Mb)($t8)
/*  f0f8ea8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f8eac:	3c04800a */ 	lui	$a0,%hi(g_MenuData+0x1c)
/*  f0f8eb0:	13010004 */ 	beq	$t8,$at,.L0f0f8ec4
/*  f0f8eb4:	248419dc */ 	addiu	$a0,$a0,%lo(g_MenuData+0x1c)
/*  f0f8eb8:	3405c800 */ 	dli	$a1,0xc800
/*  f0f8ebc:	0fc3e2ed */ 	jal	func0f0f8bb4
/*  f0f8ec0:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0f8ec4:
/*  f0f8ec4:	24190259 */ 	addiu	$t9,$zero,0x259
/*  f0f8ec8:	44800000 */ 	mtc1	$zero,$f0
/*  f0f8ecc:	ae390028 */ 	sw	$t9,0x28($s1)
/*  f0f8ed0:	3c017f1b */ 	lui	$at,%hi(var7f1b29fc)
/*  f0f8ed4:	c42429fc */ 	lwc1	$f4,%lo(var7f1b29fc)($at)
/*  f0f8ed8:	e6200564 */ 	swc1	$f0,0x564($s1)
/*  f0f8edc:	e620056c */ 	swc1	$f0,0x56c($s1)
/*  f0f8ee0:	e6240568 */ 	swc1	$f4,0x568($s1)
/*  f0f8ee4:	c6260568 */ 	lwc1	$f6,0x568($s1)
/*  f0f8ee8:	c6280564 */ 	lwc1	$f8,0x564($s1)
/*  f0f8eec:	c62a056c */ 	lwc1	$f10,0x56c($s1)
/*  f0f8ef0:	3c017f1b */ 	lui	$at,%hi(var7f1b2a00)
/*  f0f8ef4:	e6260540 */ 	swc1	$f6,0x540($s1)
/*  f0f8ef8:	e628053c */ 	swc1	$f8,0x53c($s1)
/*  f0f8efc:	e62a0544 */ 	swc1	$f10,0x544($s1)
/*  f0f8f00:	c4302a00 */ 	lwc1	$f16,%lo(var7f1b2a00)($at)
/*  f0f8f04:	3c017f1b */ 	lui	$at,%hi(var7f1b2a04)
/*  f0f8f08:	922805cd */ 	lbu	$t0,0x5cd($s1)
/*  f0f8f0c:	e6300554 */ 	swc1	$f16,0x554($s1)
/*  f0f8f10:	c6320554 */ 	lwc1	$f18,0x554($s1)
/*  f0f8f14:	3109ff7f */ 	andi	$t1,$t0,0xff7f
/*  f0f8f18:	e632052c */ 	swc1	$f18,0x52c($s1)
/*  f0f8f1c:	c4242a04 */ 	lwc1	$f4,%lo(var7f1b2a04)($at)
/*  f0f8f20:	3c017f1b */ 	lui	$at,%hi(var7f1b2a08)
/*  f0f8f24:	e6240558 */ 	swc1	$f4,0x558($s1)
/*  f0f8f28:	c6260558 */ 	lwc1	$f6,0x558($s1)
/*  f0f8f2c:	e6260530 */ 	swc1	$f6,0x530($s1)
/*  f0f8f30:	c4282a08 */ 	lwc1	$f8,%lo(var7f1b2a08)($at)
/*  f0f8f34:	3c017f1b */ 	lui	$at,%hi(var7f1b2a0c)
/*  f0f8f38:	e628055c */ 	swc1	$f8,0x55c($s1)
/*  f0f8f3c:	c62a055c */ 	lwc1	$f10,0x55c($s1)
/*  f0f8f40:	e62a0534 */ 	swc1	$f10,0x534($s1)
/*  f0f8f44:	c4302a0c */ 	lwc1	$f16,%lo(var7f1b2a0c)($at)
/*  f0f8f48:	a22905cd */ 	sb	$t1,0x5cd($s1)
/*  f0f8f4c:	ae200590 */ 	sw	$zero,0x590($s1)
/*  f0f8f50:	e6300560 */ 	swc1	$f16,0x560($s1)
/*  f0f8f54:	c6320560 */ 	lwc1	$f18,0x560($s1)
/*  f0f8f58:	ae20059c */ 	sw	$zero,0x59c($s1)
/*  f0f8f5c:	e6320538 */ 	swc1	$f18,0x538($s1)
.L0f0f8f60:
/*  f0f8f60:	922a05d5 */ 	lbu	$t2,0x5d5($s1)
/*  f0f8f64:	3c02800a */ 	lui	$v0,%hi(g_Menus)
/*  f0f8f68:	3c03800a */ 	lui	$v1,%hi(g_MenuData)
/*  f0f8f6c:	314bfff7 */ 	andi	$t3,$t2,0xfff7
/*  f0f8f70:	44800000 */ 	mtc1	$zero,$f0
/*  f0f8f74:	a22005d4 */ 	sb	$zero,0x5d4($s1)
/*  f0f8f78:	a22b05d5 */ 	sb	$t3,0x5d5($s1)
/*  f0f8f7c:	246319c0 */ 	addiu	$v1,$v1,%lo(g_MenuData)
/*  f0f8f80:	2442e000 */ 	addiu	$v0,$v0,%lo(g_Menus)
/*  f0f8f84:	2404ffff */ 	addiu	$a0,$zero,-1
.L0f0f8f88:
/*  f0f8f88:	24420e70 */ 	addiu	$v0,$v0,0xe70
/*  f0f8f8c:	0043082b */ 	sltu	$at,$v0,$v1
/*  f0f8f90:	ac40f688 */ 	sw	$zero,-0x978($v0)
/*  f0f8f94:	a440f684 */ 	sh	$zero,-0x97c($v0)
/*  f0f8f98:	a440f5f0 */ 	sh	$zero,-0xa10($v0)
/*  f0f8f9c:	a040f9b0 */ 	sb	$zero,-0x650($v0)
/*  f0f8fa0:	ac40f7ec */ 	sw	$zero,-0x814($v0)
/*  f0f8fa4:	ac40f9ac */ 	sw	$zero,-0x654($v0)
/*  f0f8fa8:	ac40f868 */ 	sw	$zero,-0x798($v0)
/*  f0f8fac:	a044ff88 */ 	sb	$a0,-0x78($v0)
/*  f0f8fb0:	a040ffd1 */ 	sb	$zero,-0x2f($v0)
/*  f0f8fb4:	ac40fff4 */ 	sw	$zero,-0xc($v0)
/*  f0f8fb8:	1420fff3 */ 	bnez	$at,.L0f0f8f88
/*  f0f8fbc:	ac40fff8 */ 	sw	$zero,-0x8($v0)
/*  f0f8fc0:	922c05d5 */ 	lbu	$t4,0x5d5($s1)
/*  f0f8fc4:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f0f8fc8:	3c02800a */ 	lui	$v0,%hi(g_MenuData)
/*  f0f8fcc:	3c03800a */ 	lui	$v1,%hi(g_MenuData+0x5)
/*  f0f8fd0:	318dfffb */ 	andi	$t5,$t4,0xfffb
/*  f0f8fd4:	a2240668 */ 	sb	$a0,0x668($s1)
/*  f0f8fd8:	ae20000c */ 	sw	$zero,0xc($s1)
/*  f0f8fdc:	ae240008 */ 	sw	$a0,0x8($s1)
/*  f0f8fe0:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f0f8fe4:	ae200004 */ 	sw	$zero,0x4($s1)
/*  f0f8fe8:	e6200010 */ 	swc1	$f0,0x10($s1)
/*  f0f8fec:	a2200014 */ 	sb	$zero,0x14($s1)
/*  f0f8ff0:	a22d05d5 */ 	sb	$t5,0x5d5($s1)
/*  f0f8ff4:	a2250015 */ 	sb	$a1,0x15($s1)
/*  f0f8ff8:	a224001b */ 	sb	$a0,0x1b($s1)
/*  f0f8ffc:	246319c5 */ 	addiu	$v1,$v1,%lo(g_MenuData+0x5)
/*  f0f9000:	244219c0 */ 	addiu	$v0,$v0,%lo(g_MenuData)
.L0f0f9004:
/*  f0f9004:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f9008:	1443fffe */ 	bne	$v0,$v1,.L0f0f9004
/*  f0f900c:	a0450668 */ 	sb	$a1,0x668($v0)
/*  f0f9010:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0f9014:	a220066e */ 	sb	$zero,0x66e($s1)
/*  f0f9018:	a220066f */ 	sb	$zero,0x66f($s1)
/*  f0f901c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0f9020:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0f9024:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0f9028:	03e00008 */ 	jr	$ra
/*  f0f902c:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f0f9030
/*  f0f9030:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f0f9034:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0f9038:	3c148007 */ 	lui	$s4,%hi(g_MpPlayerNum)
/*  f0f903c:	26941448 */ 	addiu	$s4,$s4,%lo(g_MpPlayerNum)
/*  f0f9040:	8e8e0000 */ 	lw	$t6,0x0($s4)
/*  f0f9044:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0f9048:	24150e70 */ 	addiu	$s5,$zero,0xe70
/*  f0f904c:	01d50019 */ 	multu	$t6,$s5
/*  f0f9050:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0f9054:	3c13800a */ 	lui	$s3,%hi(g_Menus)
/*  f0f9058:	2673e000 */ 	addiu	$s3,$s3,%lo(g_Menus)
/*  f0f905c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0f9060:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0f9064:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0f9068:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0f906c:	00802825 */ 	or	$a1,$a0,$zero
/*  f0f9070:	00007812 */ 	mflo	$t7
/*  f0f9074:	026f1821 */ 	addu	$v1,$s3,$t7
/*  f0f9078:	847804f4 */ 	lh	$t8,0x4f4($v1)
/*  f0f907c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0f9080:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f9084:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0f9088:	00791021 */ 	addu	$v0,$v1,$t9
/*  f0f908c:	80480460 */ 	lb	$t0,0x460($v0)
/*  f0f9090:	2442044c */ 	addiu	$v0,$v0,0x44c
/*  f0f9094:	29010002 */ 	slti	$at,$t0,0x2
/*  f0f9098:	542000a8 */ 	bnezl	$at,.L0f0f933c
/*  f0f909c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0f90a0:	8c6a04f8 */ 	lw	$t2,0x4f8($v1)
/*  f0f90a4:	00044823 */ 	negu	$t1,$a0
/*  f0f90a8:	00806825 */ 	or	$t5,$a0,$zero
/*  f0f90ac:	a149006d */ 	sb	$t1,0x6d($t2)
/*  f0f90b0:	804b0015 */ 	lb	$t3,0x15($v0)
/*  f0f90b4:	016d7021 */ 	addu	$t6,$t3,$t5
/*  f0f90b8:	a04e0015 */ 	sb	$t6,0x15($v0)
/*  f0f90bc:	80440015 */ 	lb	$a0,0x15($v0)
/*  f0f90c0:	04830006 */ 	bgezl	$a0,.L0f0f90dc
/*  f0f90c4:	80590014 */ 	lb	$t9,0x14($v0)
/*  f0f90c8:	804f0014 */ 	lb	$t7,0x14($v0)
/*  f0f90cc:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f0f90d0:	a0580015 */ 	sb	$t8,0x15($v0)
/*  f0f90d4:	80440015 */ 	lb	$a0,0x15($v0)
/*  f0f90d8:	80590014 */ 	lb	$t9,0x14($v0)
.L0f0f90dc:
/*  f0f90dc:	0099082a */ 	slt	$at,$a0,$t9
/*  f0f90e0:	54200004 */ 	bnezl	$at,.L0f0f90f4
/*  f0f90e4:	8e880000 */ 	lw	$t0,0x0($s4)
/*  f0f90e8:	a0400015 */ 	sb	$zero,0x15($v0)
/*  f0f90ec:	80440015 */ 	lb	$a0,0x15($v0)
/*  f0f90f0:	8e880000 */ 	lw	$t0,0x0($s4)
.L0f0f90f4:
/*  f0f90f4:	00045080 */ 	sll	$t2,$a0,0x2
/*  f0f90f8:	004a6021 */ 	addu	$t4,$v0,$t2
/*  f0f90fc:	01150019 */ 	multu	$t0,$s5
/*  f0f9100:	8d8b0000 */ 	lw	$t3,0x0($t4)
/*  f0f9104:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f9108:	01602025 */ 	or	$a0,$t3,$zero
/*  f0f910c:	00004812 */ 	mflo	$t1
/*  f0f9110:	02691821 */ 	addu	$v1,$s3,$t1
/*  f0f9114:	14a1000a */ 	bne	$a1,$at,.L0f0f9140
/*  f0f9118:	ac6b04f8 */ 	sw	$t3,0x4f8($v1)
/*  f0f911c:	0fc3ca23 */ 	jal	func0f0f288c
/*  f0f9120:	afa50068 */ 	sw	$a1,0x68($sp)
/*  f0f9124:	8e8d0000 */ 	lw	$t5,0x0($s4)
/*  f0f9128:	01b50019 */ 	multu	$t5,$s5
/*  f0f912c:	00007012 */ 	mflo	$t6
/*  f0f9130:	026e7821 */ 	addu	$t7,$s3,$t6
/*  f0f9134:	8df804f8 */ 	lw	$t8,0x4f8($t7)
/*  f0f9138:	1000000a */ 	b	.L0f0f9164
/*  f0f913c:	af020008 */ 	sw	$v0,0x8($t8)
.L0f0f9140:
/*  f0f9140:	8c6404f8 */ 	lw	$a0,0x4f8($v1)
/*  f0f9144:	0fc3ca4a */ 	jal	func0f0f2928
/*  f0f9148:	afa50068 */ 	sw	$a1,0x68($sp)
/*  f0f914c:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f0f9150:	03350019 */ 	multu	$t9,$s5
/*  f0f9154:	00004012 */ 	mflo	$t0
/*  f0f9158:	02684821 */ 	addu	$t1,$s3,$t0
/*  f0f915c:	8d2a04f8 */ 	lw	$t2,0x4f8($t1)
/*  f0f9160:	ad420008 */ 	sw	$v0,0x8($t2)
.L0f0f9164:
/*  f0f9164:	8e8c0000 */ 	lw	$t4,0x0($s4)
/*  f0f9168:	2411001a */ 	addiu	$s1,$zero,0x1a
/*  f0f916c:	27b20050 */ 	addiu	$s2,$sp,0x50
/*  f0f9170:	01950019 */ 	multu	$t4,$s5
/*  f0f9174:	00005812 */ 	mflo	$t3
/*  f0f9178:	026b6821 */ 	addu	$t5,$s3,$t3
/*  f0f917c:	8da304f8 */ 	lw	$v1,0x4f8($t5)
/*  f0f9180:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0f9184:	8dd00008 */ 	lw	$s0,0x8($t6)
/*  f0f9188:	920f0000 */ 	lbu	$t7,0x0($s0)
/*  f0f918c:	522f0023 */ 	beql	$s1,$t7,.L0f0f921c
/*  f0f9190:	8c650008 */ 	lw	$a1,0x8($v1)
/*  f0f9194:	8e020010 */ 	lw	$v0,0x10($s0)
.L0f0f9198:
/*  f0f9198:	50400012 */ 	beqzl	$v0,.L0f0f91e4
/*  f0f919c:	920b0014 */ 	lbu	$t3,0x14($s0)
/*  f0f91a0:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f0f91a4:	2404000f */ 	addiu	$a0,$zero,0xf
/*  f0f91a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f0f91ac:	33190004 */ 	andi	$t9,$t8,0x4
/*  f0f91b0:	5720000c */ 	bnezl	$t9,.L0f0f91e4
/*  f0f91b4:	920b0014 */ 	lbu	$t3,0x14($s0)
/*  f0f91b8:	0040f809 */ 	jalr	$v0
/*  f0f91bc:	02403025 */ 	or	$a2,$s2,$zero
/*  f0f91c0:	50400008 */ 	beqzl	$v0,.L0f0f91e4
/*  f0f91c4:	920b0014 */ 	lbu	$t3,0x14($s0)
/*  f0f91c8:	8e880000 */ 	lw	$t0,0x0($s4)
/*  f0f91cc:	01150019 */ 	multu	$t0,$s5
/*  f0f91d0:	00004812 */ 	mflo	$t1
/*  f0f91d4:	02695021 */ 	addu	$t2,$s3,$t1
/*  f0f91d8:	8d4c04f8 */ 	lw	$t4,0x4f8($t2)
/*  f0f91dc:	ad900008 */ 	sw	$s0,0x8($t4)
/*  f0f91e0:	920b0014 */ 	lbu	$t3,0x14($s0)
.L0f0f91e4:
/*  f0f91e4:	26100014 */ 	addiu	$s0,$s0,0x14
/*  f0f91e8:	562bffeb */ 	bnel	$s1,$t3,.L0f0f9198
/*  f0f91ec:	8e020010 */ 	lw	$v0,0x10($s0)
/*  f0f91f0:	8e8d0000 */ 	lw	$t5,0x0($s4)
/*  f0f91f4:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f0f91f8:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0f91fc:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f9200:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f0f9204:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0f9208:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f0f920c:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0f9210:	026e7821 */ 	addu	$t7,$s3,$t6
/*  f0f9214:	8de304f8 */ 	lw	$v1,0x4f8($t7)
/*  f0f9218:	8c650008 */ 	lw	$a1,0x8($v1)
.L0f0f921c:
/*  f0f921c:	50a00016 */ 	beqzl	$a1,.L0f0f9278
/*  f0f9220:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0f9224:	8ca20010 */ 	lw	$v0,0x10($a1)
/*  f0f9228:	50400013 */ 	beqzl	$v0,.L0f0f9278
/*  f0f922c:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0f9230:	8cb80004 */ 	lw	$t8,0x4($a1)
/*  f0f9234:	2404000d */ 	addiu	$a0,$zero,0xd
/*  f0f9238:	33190004 */ 	andi	$t9,$t8,0x4
/*  f0f923c:	5720000e */ 	bnezl	$t9,.L0f0f9278
/*  f0f9240:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0f9244:	0040f809 */ 	jalr	$v0
/*  f0f9248:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f0f924c:	8e880000 */ 	lw	$t0,0x0($s4)
/*  f0f9250:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f0f9254:	01284823 */ 	subu	$t1,$t1,$t0
/*  f0f9258:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0f925c:	01284821 */ 	addu	$t1,$t1,$t0
/*  f0f9260:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f0f9264:	01284823 */ 	subu	$t1,$t1,$t0
/*  f0f9268:	00094900 */ 	sll	$t1,$t1,0x4
/*  f0f926c:	02695021 */ 	addu	$t2,$s3,$t1
/*  f0f9270:	8d4304f8 */ 	lw	$v1,0x4f8($t2)
/*  f0f9274:	8fac0068 */ 	lw	$t4,0x68($sp)
.L0f0f9278:
/*  f0f9278:	a06c006d */ 	sb	$t4,0x6d($v1)
/*  f0f927c:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f0f9280:	01750019 */ 	multu	$t3,$s5
/*  f0f9284:	00006812 */ 	mflo	$t5
/*  f0f9288:	026d7021 */ 	addu	$t6,$s3,$t5
/*  f0f928c:	0fc3dfa6 */ 	jal	func0f0f7e98
/*  f0f9290:	8dc404f8 */ 	lw	$a0,0x4f8($t6)
/*  f0f9294:	8e8f0000 */ 	lw	$t7,0x0($s4)
/*  f0f9298:	44802000 */ 	mtc1	$zero,$f4
/*  f0f929c:	01f50019 */ 	multu	$t7,$s5
/*  f0f92a0:	0000c012 */ 	mflo	$t8
/*  f0f92a4:	0278c821 */ 	addu	$t9,$s3,$t8
/*  f0f92a8:	8f2304f8 */ 	lw	$v1,0x4f8($t9)
/*  f0f92ac:	8c68002c */ 	lw	$t0,0x2c($v1)
/*  f0f92b0:	ac680014 */ 	sw	$t0,0x14($v1)
/*  f0f92b4:	8e890000 */ 	lw	$t1,0x0($s4)
/*  f0f92b8:	01350019 */ 	multu	$t1,$s5
/*  f0f92bc:	00005012 */ 	mflo	$t2
/*  f0f92c0:	026a6021 */ 	addu	$t4,$s3,$t2
/*  f0f92c4:	8d8304f8 */ 	lw	$v1,0x4f8($t4)
/*  f0f92c8:	8c6b0030 */ 	lw	$t3,0x30($v1)
/*  f0f92cc:	ac6b0018 */ 	sw	$t3,0x18($v1)
/*  f0f92d0:	8e8d0000 */ 	lw	$t5,0x0($s4)
/*  f0f92d4:	01b50019 */ 	multu	$t5,$s5
/*  f0f92d8:	00007012 */ 	mflo	$t6
/*  f0f92dc:	026e7821 */ 	addu	$t7,$s3,$t6
/*  f0f92e0:	8df804f8 */ 	lw	$t8,0x4f8($t7)
/*  f0f92e4:	a300006d */ 	sb	$zero,0x6d($t8)
/*  f0f92e8:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f0f92ec:	03350019 */ 	multu	$t9,$s5
/*  f0f92f0:	00004012 */ 	mflo	$t0
/*  f0f92f4:	02684821 */ 	addu	$t1,$s3,$t0
/*  f0f92f8:	8d2a04f8 */ 	lw	$t2,0x4f8($t1)
/*  f0f92fc:	a1400060 */ 	sb	$zero,0x60($t2)
/*  f0f9300:	8e8c0000 */ 	lw	$t4,0x0($s4)
/*  f0f9304:	01950019 */ 	multu	$t4,$s5
/*  f0f9308:	00005812 */ 	mflo	$t3
/*  f0f930c:	026b6821 */ 	addu	$t5,$s3,$t3
/*  f0f9310:	8dae04f8 */ 	lw	$t6,0x4f8($t5)
/*  f0f9314:	e5c40050 */ 	swc1	$f4,0x50($t6)
/*  f0f9318:	8e8f0000 */ 	lw	$t7,0x0($s4)
/*  f0f931c:	01f50019 */ 	multu	$t7,$s5
/*  f0f9320:	0000c012 */ 	mflo	$t8
/*  f0f9324:	02782021 */ 	addu	$a0,$s3,$t8
/*  f0f9328:	0fc3cde9 */ 	jal	func0f0f37a4
/*  f0f932c:	24840840 */ 	addiu	$a0,$a0,0x840
/*  f0f9330:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0f9334:	00002025 */ 	or	$a0,$zero,$zero
/*  f0f9338:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0f933c:
/*  f0f933c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0f9340:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0f9344:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0f9348:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0f934c:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0f9350:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0f9354:	03e00008 */ 	jr	$ra
/*  f0f9358:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel func0f0f935c
.late_rodata
glabel var7f1b2a10
.word 0x3c23d70a
glabel var7f1b2a14
.word 0x3d2c0831
glabel var7f1b2a18
.word 0x3d4ccccd
glabel var7f1b2a1c
.word 0x3e4ccccd
glabel var7f1b2a20
.word 0x3f4ccccd
glabel var7f1b2a24
.word 0x3f4ccccd
glabel var7f1b2a28
.word 0x3f4ccccd
glabel var7f1b2a2c
.word 0x3dcccccd
glabel var7f1b2a30
.word 0x3d23d70a
glabel var7f1b2a34
.word 0x3f4ccccd
glabel var7f1b2a38
.word 0x3f4ccccd
glabel var7f1b2a3c
.word 0x3f4ccccd
glabel var7f1b2a40
.word 0x3f333333
glabel var7f1b2a44
.word 0x3e99999a
glabel var7f1b2a48
.word 0x3f333333
glabel var7f1b2a4c
.word 0x3f333333
glabel var7f1b2a50
.word 0x3f333333
glabel var7f1b2a54
.word 0x3e99999a
glabel var7f1b2a58
.word 0x3e99999a
glabel var7f1b2a5c
.word 0x3e99999a
glabel var7f1b2a60
.word 0x3e4ccccd
glabel var7f1b2a64
.word 0x3f4ccccd
.text
/*  f0f935c:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f0f9360:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f0f9364:	27bdfee0 */ 	addiu	$sp,$sp,-288
/*  f0f9368:	3c18800a */ 	lui	$t8,%hi(g_Menus)
/*  f0f936c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f9370:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f9374:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f9378:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f937c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f9380:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f9384:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f9388:	2718e000 */ 	addiu	$t8,$t8,%lo(g_Menus)
/*  f0f938c:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f0f9390:	8c590e40 */ 	lw	$t9,0xe40($v0)
/*  f0f9394:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0f9398:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f0f939c:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f0f93a0:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f0f93a4:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f0f93a8:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f0f93ac:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f0f93b0:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f0f93b4:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f0f93b8:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0f93bc:	afa60128 */ 	sw	$a2,0x128($sp)
/*  f0f93c0:	afa0011c */ 	sw	$zero,0x11c($sp)
/*  f0f93c4:	8c930000 */ 	lw	$s3,0x0($a0)
/*  f0f93c8:	001947c2 */ 	srl	$t0,$t9,0x1f
/*  f0f93cc:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0f93d0:	0080f025 */ 	or	$s8,$a0,$zero
/*  f0f93d4:	15000005 */ 	bnez	$t0,.L0f0f93ec
/*  f0f93d8:	afa20114 */ 	sw	$v0,0x114($sp)
/*  f0f93dc:	3c098006 */ 	lui	$t1,%hi(var8005dd58)
/*  f0f93e0:	8d29dd58 */ 	lw	$t1,%lo(var8005dd58)($t1)
/*  f0f93e4:	5120001e */ 	beqzl	$t1,.L0f0f9460
/*  f0f93e8:	90580e40 */ 	lbu	$t8,0xe40($v0)
.L0f0f93ec:
/*  f0f93ec:	00002e00 */ 	sll	$a1,$zero,0x18
/*  f0f93f0:	00055603 */ 	sra	$t2,$a1,0x18
/*  f0f93f4:	314600ff */ 	andi	$a2,$t2,0xff
/*  f0f93f8:	a2260001 */ 	sb	$a2,0x1($s1)
/*  f0f93fc:	a2260000 */ 	sb	$a2,0x0($s1)
/*  f0f9400:	a22a0003 */ 	sb	$t2,0x3($s1)
/*  f0f9404:	a22a0002 */ 	sb	$t2,0x2($s1)
/*  f0f9408:	a2200014 */ 	sb	$zero,0x14($s1)
/*  f0f940c:	a2200007 */ 	sb	$zero,0x7($s1)
/*  f0f9410:	a2200006 */ 	sb	$zero,0x6($s1)
/*  f0f9414:	a2200005 */ 	sb	$zero,0x5($s1)
/*  f0f9418:	a2200004 */ 	sb	$zero,0x4($s1)
/*  f0f941c:	3c0b8007 */ 	lui	$t3,%hi(g_MpPlayerNum)
/*  f0f9420:	8d6b1448 */ 	lw	$t3,%lo(g_MpPlayerNum)($t3)
/*  f0f9424:	3c0d800a */ 	lui	$t5,%hi(g_Menus)
/*  f0f9428:	25ade000 */ 	addiu	$t5,$t5,%lo(g_Menus)
/*  f0f942c:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f0f9430:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0f9434:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0f9438:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f0f943c:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f0f9440:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0f9444:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f0f9448:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f0f944c:	904e0e40 */ 	lbu	$t6,0xe40($v0)
/*  f0f9450:	01402825 */ 	or	$a1,$t2,$zero
/*  f0f9454:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f0f9458:	a04f0e40 */ 	sb	$t7,0xe40($v0)
/*  f0f945c:	90580e40 */ 	lbu	$t8,0xe40($v0)
.L0f0f9460:
/*  f0f9460:	a3a000da */ 	sb	$zero,0xda($sp)
/*  f0f9464:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0f9468:	3319ff7f */ 	andi	$t9,$t8,0xff7f
/*  f0f946c:	a0590e40 */ 	sb	$t9,0xe40($v0)
/*  f0f9470:	92280003 */ 	lbu	$t0,0x3($s1)
/*  f0f9474:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0f9478:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f0f947c:	a3a800db */ 	sb	$t0,0xdb($sp)
/*  f0f9480:	82290000 */ 	lb	$t1,0x0($s1)
/*  f0f9484:	44807000 */ 	mtc1	$zero,$f14
/*  f0f9488:	a3a900d8 */ 	sb	$t1,0xd8($sp)
/*  f0f948c:	822a0001 */ 	lb	$t2,0x1($s1)
/*  f0f9490:	a3aa00d9 */ 	sb	$t2,0xd9($sp)
/*  f0f9494:	822b0004 */ 	lb	$t3,0x4($s1)
/*  f0f9498:	a3ab00dc */ 	sb	$t3,0xdc($sp)
/*  f0f949c:	822c0005 */ 	lb	$t4,0x5($s1)
/*  f0f94a0:	a3ac00dd */ 	sb	$t4,0xdd($sp)
/*  f0f94a4:	822d0008 */ 	lb	$t5,0x8($s1)
/*  f0f94a8:	a3ad00e0 */ 	sb	$t5,0xe0($sp)
/*  f0f94ac:	822e0009 */ 	lb	$t6,0x9($s1)
/*  f0f94b0:	a3a000e2 */ 	sb	$zero,0xe2($sp)
/*  f0f94b4:	a3ae00e1 */ 	sb	$t6,0xe1($sp)
/*  f0f94b8:	8e2f000c */ 	lw	$t7,0xc($s1)
/*  f0f94bc:	afaf00e4 */ 	sw	$t7,0xe4($sp)
/*  f0f94c0:	8e380010 */ 	lw	$t8,0x10($s1)
/*  f0f94c4:	afb800e8 */ 	sw	$t8,0xe8($sp)
/*  f0f94c8:	8fd90054 */ 	lw	$t9,0x54($s8)
/*  f0f94cc:	8fc9005c */ 	lw	$t1,0x5c($s8)
/*  f0f94d0:	c7c00040 */ 	lwc1	$f0,0x40($s8)
/*  f0f94d4:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f0f94d8:	afc80054 */ 	sw	$t0,0x54($s8)
/*  f0f94dc:	8cea0000 */ 	lw	$t2,0x0($a3)
/*  f0f94e0:	01006025 */ 	or	$t4,$t0,$zero
/*  f0f94e4:	3c198007 */ 	lui	$t9,%hi(var800714dc)
/*  f0f94e8:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f0f94ec:	0164001a */ 	div	$zero,$t3,$a0
/*  f0f94f0:	00006812 */ 	mflo	$t5
/*  f0f94f4:	00007810 */ 	mfhi	$t7
/*  f0f94f8:	afcb005c */ 	sw	$t3,0x5c($s8)
/*  f0f94fc:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f0f9500:	afce0054 */ 	sw	$t6,0x54($s8)
/*  f0f9504:	afcf005c */ 	sw	$t7,0x5c($s8)
/*  f0f9508:	8f3914dc */ 	lw	$t9,%lo(var800714dc)($t9)
/*  f0f950c:	01601825 */ 	or	$v1,$t3,$zero
/*  f0f9510:	460e003c */ 	c.lt.s	$f0,$f14
/*  f0f9514:	01d9001b */ 	divu	$zero,$t6,$t9
/*  f0f9518:	14800002 */ 	bnez	$a0,.L0f0f9524
/*  f0f951c:	00000000 */ 	nop
/*  f0f9520:	0007000d */ 	break	0x7
.L0f0f9524:
/*  f0f9524:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f9528:	14810004 */ 	bne	$a0,$at,.L0f0f953c
/*  f0f952c:	3c018000 */ 	lui	$at,0x8000
/*  f0f9530:	14610002 */ 	bne	$v1,$at,.L0f0f953c
/*  f0f9534:	00000000 */ 	nop
/*  f0f9538:	0006000d */ 	break	0x6
.L0f0f953c:
/*  f0f953c:	00004010 */ 	mfhi	$t0
/*  f0f9540:	afc80054 */ 	sw	$t0,0x54($s8)
/*  f0f9544:	01c0c025 */ 	or	$t8,$t6,$zero
/*  f0f9548:	17200002 */ 	bnez	$t9,.L0f0f9554
/*  f0f954c:	00000000 */ 	nop
/*  f0f9550:	0007000d */ 	break	0x7
.L0f0f9554:
/*  f0f9554:	4500004b */ 	bc1f	.L0f0f9684
/*  f0f9558:	3c048007 */ 	lui	$a0,%hi(g_MpPlayerNum)
/*  f0f955c:	8c841448 */ 	lw	$a0,%lo(g_MpPlayerNum)($a0)
/*  f0f9560:	3c0a800a */ 	lui	$t2,%hi(g_Menus+0x4f8)
/*  f0f9564:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f9568:	000448c0 */ 	sll	$t1,$a0,0x3
/*  f0f956c:	01244823 */ 	subu	$t1,$t1,$a0
/*  f0f9570:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0f9574:	01244821 */ 	addu	$t1,$t1,$a0
/*  f0f9578:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f0f957c:	01244823 */ 	subu	$t1,$t1,$a0
/*  f0f9580:	00094900 */ 	sll	$t1,$t1,0x4
/*  f0f9584:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0f9588:	8d4ae4f8 */ 	lw	$t2,%lo(g_Menus+0x4f8)($t2)
/*  f0f958c:	57ca0034 */ 	bnel	$s8,$t2,.L0f0f9660
/*  f0f9590:	93c9003c */ 	lbu	$t1,0x3c($s8)
/*  f0f9594:	92700000 */ 	lbu	$s0,0x0($s3)
/*  f0f9598:	0fc62ff6 */ 	jal	mpIsPlayerLockedOut
/*  f0f959c:	afb10124 */ 	sw	$s1,0x124($sp)
/*  f0f95a0:	44807000 */ 	mtc1	$zero,$f14
/*  f0f95a4:	10400007 */ 	beqz	$v0,.L0f0f95c4
/*  f0f95a8:	3c0e800a */ 	lui	$t6,%hi(g_MenuData+0x4)
/*  f0f95ac:	8fcb0000 */ 	lw	$t3,0x0($s8)
/*  f0f95b0:	8d6c0010 */ 	lw	$t4,0x10($t3)
/*  f0f95b4:	318d0010 */ 	andi	$t5,$t4,0x10
/*  f0f95b8:	11a00002 */ 	beqz	$t5,.L0f0f95c4
/*  f0f95bc:	00000000 */ 	nop
/*  f0f95c0:	24100002 */ 	addiu	$s0,$zero,0x2
.L0f0f95c4:
/*  f0f95c4:	8dce19c4 */ 	lw	$t6,%lo(g_MenuData+0x4)($t6)
/*  f0f95c8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f95cc:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0f95d0:	15c10017 */ 	bne	$t6,$at,.L0f0f9630
/*  f0f95d4:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0f95d8:	3c02800a */ 	lui	$v0,%hi(g_MenuData+0x14)
/*  f0f95dc:	904219d4 */ 	lbu	$v0,%lo(g_MenuData+0x14)($v0)
/*  f0f95e0:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0f95e4:	3c0f8008 */ 	lui	$t7,%hi(g_StageIndex)
/*  f0f95e8:	10410004 */ 	beq	$v0,$at,.L0f0f95fc
/*  f0f95ec:	24120003 */ 	addiu	$s2,$zero,0x3
/*  f0f95f0:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0f95f4:	14410002 */ 	bne	$v0,$at,.L0f0f9600
/*  f0f95f8:	00000000 */ 	nop
.L0f0f95fc:
/*  f0f95fc:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0f9600:
/*  f0f9600:	8deffc00 */ 	lw	$t7,%lo(g_StageIndex)($t7)
/*  f0f9604:	24010019 */ 	addiu	$at,$zero,0x19
/*  f0f9608:	55e1000a */ 	bnel	$t7,$at,.L0f0f9634
/*  f0f960c:	93c8003c */ 	lbu	$t0,0x3c($s8)
/*  f0f9610:	12420007 */ 	beq	$s2,$v0,.L0f0f9630
/*  f0f9614:	3c18800a */ 	lui	$t8,%hi(g_MenuData+0x15)
/*  f0f9618:	931819d5 */ 	lbu	$t8,%lo(g_MenuData+0x15)($t8)
/*  f0f961c:	24190005 */ 	addiu	$t9,$zero,0x5
/*  f0f9620:	52580004 */ 	beql	$s2,$t8,.L0f0f9634
/*  f0f9624:	93c8003c */ 	lbu	$t0,0x3c($s8)
/*  f0f9628:	24100005 */ 	addiu	$s0,$zero,0x5
/*  f0f962c:	a3d9003c */ 	sb	$t9,0x3c($s8)
.L0f0f9630:
/*  f0f9630:	93c8003c */ 	lbu	$t0,0x3c($s8)
.L0f0f9634:
/*  f0f9634:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f9638:	44816000 */ 	mtc1	$at,$f12
/*  f0f963c:	12080005 */ 	beq	$s0,$t0,.L0f0f9654
/*  f0f9640:	24120003 */ 	addiu	$s2,$zero,0x3
/*  f0f9644:	44802000 */ 	mtc1	$zero,$f4
/*  f0f9648:	a3d0003d */ 	sb	$s0,0x3d($s8)
/*  f0f964c:	afc00044 */ 	sw	$zero,0x44($s8)
/*  f0f9650:	e7c40040 */ 	swc1	$f4,0x40($s8)
.L0f0f9654:
/*  f0f9654:	10000072 */ 	b	.L0f0f9820
/*  f0f9658:	8fb10124 */ 	lw	$s1,0x124($sp)
/*  f0f965c:	93c9003c */ 	lbu	$t1,0x3c($s8)
.L0f0f9660:
/*  f0f9660:	44816000 */ 	mtc1	$at,$f12
/*  f0f9664:	11200005 */ 	beqz	$t1,.L0f0f967c
/*  f0f9668:	00000000 */ 	nop
/*  f0f966c:	44803000 */ 	mtc1	$zero,$f6
/*  f0f9670:	a3c0003d */ 	sb	$zero,0x3d($s8)
/*  f0f9674:	afc00044 */ 	sw	$zero,0x44($s8)
/*  f0f9678:	e7c60040 */ 	swc1	$f6,0x40($s8)
.L0f0f967c:
/*  f0f967c:	10000068 */ 	b	.L0f0f9820
/*  f0f9680:	24120003 */ 	addiu	$s2,$zero,0x3
.L0f0f9684:
/*  f0f9684:	3c02800a */ 	lui	$v0,%hi(g_MenuData+0x4)
/*  f0f9688:	8c4219c4 */ 	lw	$v0,%lo(g_MenuData+0x4)($v0)
/*  f0f968c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f9690:	3c0a8008 */ 	lui	$t2,%hi(g_StageIndex)
/*  f0f9694:	54410017 */ 	bnel	$v0,$at,.L0f0f96f4
/*  f0f9698:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f969c:	8d4afc00 */ 	lw	$t2,%lo(g_StageIndex)($t2)
/*  f0f96a0:	24010019 */ 	addiu	$at,$zero,0x19
/*  f0f96a4:	3c0b800a */ 	lui	$t3,%hi(g_MenuData+0x14)
/*  f0f96a8:	55410012 */ 	bnel	$t2,$at,.L0f0f96f4
/*  f0f96ac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f96b0:	916b19d4 */ 	lbu	$t3,%lo(g_MenuData+0x14)($t3)
/*  f0f96b4:	24120003 */ 	addiu	$s2,$zero,0x3
/*  f0f96b8:	3c0c800a */ 	lui	$t4,%hi(g_MenuData+0x15)
/*  f0f96bc:	524b000d */ 	beql	$s2,$t3,.L0f0f96f4
/*  f0f96c0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f96c4:	918c19d5 */ 	lbu	$t4,%lo(g_MenuData+0x15)($t4)
/*  f0f96c8:	524c000a */ 	beql	$s2,$t4,.L0f0f96f4
/*  f0f96cc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f96d0:	93cd003d */ 	lbu	$t5,0x3d($s8)
/*  f0f96d4:	240e0005 */ 	addiu	$t6,$zero,0x5
/*  f0f96d8:	51a00006 */ 	beqzl	$t5,.L0f0f96f4
/*  f0f96dc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f96e0:	a3ce003d */ 	sb	$t6,0x3d($s8)
/*  f0f96e4:	3c02800a */ 	lui	$v0,%hi(g_MenuData+0x4)
/*  f0f96e8:	8c4219c4 */ 	lw	$v0,%lo(g_MenuData+0x4)($v0)
/*  f0f96ec:	c7c00040 */ 	lwc1	$f0,0x40($s8)
/*  f0f96f0:	24010001 */ 	addiu	$at,$zero,0x1
.L0f0f96f4:
/*  f0f96f4:	14410011 */ 	bne	$v0,$at,.L0f0f973c
/*  f0f96f8:	24120003 */ 	addiu	$s2,$zero,0x3
/*  f0f96fc:	93cf003c */ 	lbu	$t7,0x3c($s8)
/*  f0f9700:	3c02800a */ 	lui	$v0,%hi(g_MenuData+0x14)
/*  f0f9704:	164f000d */ 	bne	$s2,$t7,.L0f0f973c
/*  f0f9708:	00000000 */ 	nop
/*  f0f970c:	904219d4 */ 	lbu	$v0,%lo(g_MenuData+0x14)($v0)
/*  f0f9710:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0f9714:	10410002 */ 	beq	$v0,$at,.L0f0f9720
/*  f0f9718:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0f971c:	14410007 */ 	bne	$v0,$at,.L0f0f973c
.L0f0f9720:
/*  f0f9720:	3c017f1b */ 	lui	$at,%hi(var7f1b2a10)
/*  f0f9724:	c42a2a10 */ 	lwc1	$f10,%lo(var7f1b2a10)($at)
/*  f0f9728:	c4e80004 */ 	lwc1	$f8,0x4($a3)
/*  f0f972c:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f0f9730:	46120100 */ 	add.s	$f4,$f0,$f18
/*  f0f9734:	10000007 */ 	b	.L0f0f9754
/*  f0f9738:	e7c40040 */ 	swc1	$f4,0x40($s8)
.L0f0f973c:
/*  f0f973c:	3c017f1b */ 	lui	$at,%hi(var7f1b2a14)
/*  f0f9740:	c4282a14 */ 	lwc1	$f8,%lo(var7f1b2a14)($at)
/*  f0f9744:	c4e60004 */ 	lwc1	$f6,0x4($a3)
/*  f0f9748:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0f974c:	460a0480 */ 	add.s	$f18,$f0,$f10
/*  f0f9750:	e7d20040 */ 	swc1	$f18,0x40($s8)
.L0f0f9754:
/*  f0f9754:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f9758:	44816000 */ 	mtc1	$at,$f12
/*  f0f975c:	c7c00040 */ 	lwc1	$f0,0x40($s8)
/*  f0f9760:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0f9764:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0f9768:	00000000 */ 	nop
/*  f0f976c:	45020007 */ 	bc1fl	.L0f0f978c
/*  f0f9770:	3c01437f */ 	lui	$at,0x437f
/*  f0f9774:	44812000 */ 	mtc1	$at,$f4
/*  f0f9778:	93d8003d */ 	lbu	$t8,0x3d($s8)
/*  f0f977c:	e7c40040 */ 	swc1	$f4,0x40($s8)
/*  f0f9780:	c7c00040 */ 	lwc1	$f0,0x40($s8)
/*  f0f9784:	a3d8003c */ 	sb	$t8,0x3c($s8)
/*  f0f9788:	3c01437f */ 	lui	$at,0x437f
.L0f0f978c:
/*  f0f978c:	44813000 */ 	mtc1	$at,$f6
/*  f0f9790:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f9794:	3c014f00 */ 	lui	$at,0x4f00
/*  f0f9798:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0f979c:	4459f800 */ 	cfc1	$t9,$31
/*  f0f97a0:	44c8f800 */ 	ctc1	$t0,$31
/*  f0f97a4:	00000000 */ 	nop
/*  f0f97a8:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f0f97ac:	4448f800 */ 	cfc1	$t0,$31
/*  f0f97b0:	00000000 */ 	nop
/*  f0f97b4:	31080078 */ 	andi	$t0,$t0,0x78
/*  f0f97b8:	51000013 */ 	beqzl	$t0,.L0f0f9808
/*  f0f97bc:	44085000 */ 	mfc1	$t0,$f10
/*  f0f97c0:	44815000 */ 	mtc1	$at,$f10
/*  f0f97c4:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0f97c8:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f0f97cc:	44c8f800 */ 	ctc1	$t0,$31
/*  f0f97d0:	00000000 */ 	nop
/*  f0f97d4:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0f97d8:	4448f800 */ 	cfc1	$t0,$31
/*  f0f97dc:	00000000 */ 	nop
/*  f0f97e0:	31080078 */ 	andi	$t0,$t0,0x78
/*  f0f97e4:	15000005 */ 	bnez	$t0,.L0f0f97fc
/*  f0f97e8:	00000000 */ 	nop
/*  f0f97ec:	44085000 */ 	mfc1	$t0,$f10
/*  f0f97f0:	3c018000 */ 	lui	$at,0x8000
/*  f0f97f4:	10000007 */ 	b	.L0f0f9814
/*  f0f97f8:	01014025 */ 	or	$t0,$t0,$at
.L0f0f97fc:
/*  f0f97fc:	10000005 */ 	b	.L0f0f9814
/*  f0f9800:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0f9804:	44085000 */ 	mfc1	$t0,$f10
.L0f0f9808:
/*  f0f9808:	00000000 */ 	nop
/*  f0f980c:	0500fffb */ 	bltz	$t0,.L0f0f97fc
/*  f0f9810:	00000000 */ 	nop
.L0f0f9814:
/*  f0f9814:	44d9f800 */ 	ctc1	$t9,$31
/*  f0f9818:	afc80044 */ 	sw	$t0,0x44($s8)
/*  f0f981c:	00000000 */ 	nop
.L0f0f9820:
/*  f0f9820:	93c20060 */ 	lbu	$v0,0x60($s8)
/*  f0f9824:	1642001b */ 	bne	$s2,$v0,.L0f0f9894
/*  f0f9828:	3c09800a */ 	lui	$t1,%hi(g_MenuData+0x15)
/*  f0f982c:	912919d5 */ 	lbu	$t1,%lo(g_MenuData+0x15)($t1)
/*  f0f9830:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f9834:	51210018 */ 	beql	$t1,$at,.L0f0f9898
/*  f0f9838:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0f983c:	c7d20048 */ 	lwc1	$f18,0x48($s8)
/*  f0f9840:	3c0142f0 */ 	lui	$at,0x42f0
/*  f0f9844:	460e903c */ 	c.lt.s	$f18,$f14
/*  f0f9848:	00000000 */ 	nop
/*  f0f984c:	45020010 */ 	bc1fl	.L0f0f9890
/*  f0f9850:	e7ce0050 */ 	swc1	$f14,0x50($s8)
/*  f0f9854:	c4e40004 */ 	lwc1	$f4,0x4($a3)
/*  f0f9858:	44813000 */ 	mtc1	$at,$f6
/*  f0f985c:	c7ca0050 */ 	lwc1	$f10,0x50($s8)
/*  f0f9860:	46062203 */ 	div.s	$f8,$f4,$f6
/*  f0f9864:	46085480 */ 	add.s	$f18,$f10,$f8
/*  f0f9868:	e7d20050 */ 	swc1	$f18,0x50($s8)
/*  f0f986c:	c7c40050 */ 	lwc1	$f4,0x50($s8)
/*  f0f9870:	4604603c */ 	c.lt.s	$f12,$f4
/*  f0f9874:	00000000 */ 	nop
/*  f0f9878:	45000002 */ 	bc1f	.L0f0f9884
/*  f0f987c:	00000000 */ 	nop
/*  f0f9880:	e7ce0048 */ 	swc1	$f14,0x48($s8)
.L0f0f9884:
/*  f0f9884:	10000003 */ 	b	.L0f0f9894
/*  f0f9888:	93c20060 */ 	lbu	$v0,0x60($s8)
/*  f0f988c:	e7ce0050 */ 	swc1	$f14,0x50($s8)
.L0f0f9890:
/*  f0f9890:	93c20060 */ 	lbu	$v0,0x60($s8)
.L0f0f9894:
/*  f0f9894:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0f9898:
/*  f0f9898:	14410014 */ 	bne	$v0,$at,.L0f0f98ec
/*  f0f989c:	3c017f1b */ 	lui	$at,%hi(var7f1b2a18)
/*  f0f98a0:	c4262a18 */ 	lwc1	$f6,%lo(var7f1b2a18)($at)
/*  f0f98a4:	c4ea0004 */ 	lwc1	$f10,0x4($a3)
/*  f0f98a8:	c7d20050 */ 	lwc1	$f18,0x50($s8)
/*  f0f98ac:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0f98b0:	46089101 */ 	sub.s	$f4,$f18,$f8
/*  f0f98b4:	e7c40050 */ 	swc1	$f4,0x50($s8)
/*  f0f98b8:	c7c60050 */ 	lwc1	$f6,0x50($s8)
/*  f0f98bc:	460e303c */ 	c.lt.s	$f6,$f14
/*  f0f98c0:	00000000 */ 	nop
/*  f0f98c4:	4502000a */ 	bc1fl	.L0f0f98f0
/*  f0f98c8:	93cb0060 */ 	lbu	$t3,0x60($s8)
/*  f0f98cc:	c7ca0048 */ 	lwc1	$f10,0x48($s8)
/*  f0f98d0:	e7ce0050 */ 	swc1	$f14,0x50($s8)
/*  f0f98d4:	240a0003 */ 	addiu	$t2,$zero,0x3
/*  f0f98d8:	460e503c */ 	c.lt.s	$f10,$f14
/*  f0f98dc:	00000000 */ 	nop
/*  f0f98e0:	45020003 */ 	bc1fl	.L0f0f98f0
/*  f0f98e4:	93cb0060 */ 	lbu	$t3,0x60($s8)
/*  f0f98e8:	a3ca0060 */ 	sb	$t2,0x60($s8)
.L0f0f98ec:
/*  f0f98ec:	93cb0060 */ 	lbu	$t3,0x60($s8)
.L0f0f98f0:
/*  f0f98f0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0f98f4:	5561003d */ 	bnel	$t3,$at,.L0f0f99ec
/*  f0f98f8:	93c90060 */ 	lbu	$t1,0x60($s8)
/*  f0f98fc:	8fcd0020 */ 	lw	$t5,0x20($s8)
/*  f0f9900:	c7c00050 */ 	lwc1	$f0,0x50($s8)
/*  f0f9904:	448d4000 */ 	mtc1	$t5,$f8
/*  f0f9908:	4600048d */ 	trunc.w.s	$f18,$f0
/*  f0f990c:	468040a0 */ 	cvt.s.w	$f2,$f8
/*  f0f9910:	44039000 */ 	mfc1	$v1,$f18
/*  f0f9914:	00000000 */ 	nop
/*  f0f9918:	00602025 */ 	or	$a0,$v1,$zero
/*  f0f991c:	46001032 */ 	c.eq.s	$f2,$f0
/*  f0f9920:	00000000 */ 	nop
/*  f0f9924:	45010018 */ 	bc1t	.L0f0f9988
/*  f0f9928:	00000000 */ 	nop
/*  f0f992c:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0f9930:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f9934:	3c017f1b */ 	lui	$at,%hi(var7f1b2a1c)
/*  f0f9938:	19c00013 */ 	blez	$t6,.L0f0f9988
/*  f0f993c:	00000000 */ 	nop
/*  f0f9940:	c4242a1c */ 	lwc1	$f4,%lo(var7f1b2a1c)($at)
/*  f0f9944:	3c017f1b */ 	lui	$at,%hi(var7f1b2a20)
/*  f0f9948:	c4302a20 */ 	lwc1	$f16,%lo(var7f1b2a20)($at)
/*  f0f994c:	46041002 */ 	mul.s	$f0,$f2,$f4
/*  f0f9950:	00000000 */ 	nop
/*  f0f9954:	c7c60050 */ 	lwc1	$f6,0x50($s8)
.L0f0f9958:
/*  f0f9958:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f995c:	46068282 */ 	mul.s	$f10,$f16,$f6
/*  f0f9960:	460a0480 */ 	add.s	$f18,$f0,$f10
/*  f0f9964:	e7d20050 */ 	swc1	$f18,0x50($s8)
/*  f0f9968:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f0f996c:	004f082a */ 	slt	$at,$v0,$t7
/*  f0f9970:	5420fff9 */ 	bnezl	$at,.L0f0f9958
/*  f0f9974:	c7c60050 */ 	lwc1	$f6,0x50($s8)
/*  f0f9978:	c7c00050 */ 	lwc1	$f0,0x50($s8)
/*  f0f997c:	4600020d */ 	trunc.w.s	$f8,$f0
/*  f0f9980:	44034000 */ 	mfc1	$v1,$f8
/*  f0f9984:	00000000 */ 	nop
.L0f0f9988:
/*  f0f9988:	5483000b */ 	bnel	$a0,$v1,.L0f0f99b8
/*  f0f998c:	460c1201 */ 	sub.s	$f8,$f2,$f12
/*  f0f9990:	44842000 */ 	mtc1	$a0,$f4
/*  f0f9994:	8fd90020 */ 	lw	$t9,0x20($s8)
/*  f0f9998:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0f999c:	44999000 */ 	mtc1	$t9,$f18
/*  f0f99a0:	00000000 */ 	nop
/*  f0f99a4:	468090a0 */ 	cvt.s.w	$f2,$f18
/*  f0f99a8:	460c3280 */ 	add.s	$f10,$f6,$f12
/*  f0f99ac:	e7ca0050 */ 	swc1	$f10,0x50($s8)
/*  f0f99b0:	c7c00050 */ 	lwc1	$f0,0x50($s8)
/*  f0f99b4:	460c1201 */ 	sub.s	$f8,$f2,$f12
.L0f0f99b8:
/*  f0f99b8:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0f99bc:	00000000 */ 	nop
/*  f0f99c0:	4502000a */ 	bc1fl	.L0f0f99ec
/*  f0f99c4:	93c90060 */ 	lbu	$t1,0x60($s8)
/*  f0f99c8:	460c1100 */ 	add.s	$f4,$f2,$f12
/*  f0f99cc:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f0f99d0:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0f99d4:	00000000 */ 	nop
/*  f0f99d8:	45020004 */ 	bc1fl	.L0f0f99ec
/*  f0f99dc:	93c90060 */ 	lbu	$t1,0x60($s8)
/*  f0f99e0:	a3c80060 */ 	sb	$t0,0x60($s8)
/*  f0f99e4:	e7cc0050 */ 	swc1	$f12,0x50($s8)
/*  f0f99e8:	93c90060 */ 	lbu	$t1,0x60($s8)
.L0f0f99ec:
/*  f0f99ec:	55200053 */ 	bnezl	$t1,.L0f0f9b3c
/*  f0f99f0:	c7c00048 */ 	lwc1	$f0,0x48($s8)
/*  f0f99f4:	8fcb0000 */ 	lw	$t3,0x0($s8)
/*  f0f99f8:	3c0a8008 */ 	lui	$t2,%hi(g_MpReadyMenuDialog)
/*  f0f99fc:	254a57b8 */ 	addiu	$t2,$t2,%lo(g_MpReadyMenuDialog)
/*  f0f9a00:	154b0013 */ 	bne	$t2,$t3,.L0f0f9a50
/*  f0f9a04:	3c017f1b */ 	lui	$at,%hi(var7f1b2a2c)
/*  f0f9a08:	c7c00050 */ 	lwc1	$f0,0x50($s8)
/*  f0f9a0c:	c4262a2c */ 	lwc1	$f6,%lo(var7f1b2a2c)($at)
/*  f0f9a10:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0f9a14:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f9a18:	4606003c */ 	c.lt.s	$f0,$f6
/*  f0f9a1c:	00000000 */ 	nop
/*  f0f9a20:	45020007 */ 	bc1fl	.L0f0f9a40
/*  f0f9a24:	44814000 */ 	mtc1	$at,$f8
/*  f0f9a28:	3c017f1b */ 	lui	$at,%hi(var7f1b2a30)
/*  f0f9a2c:	c42a2a30 */ 	lwc1	$f10,%lo(var7f1b2a30)($at)
/*  f0f9a30:	460a0480 */ 	add.s	$f18,$f0,$f10
/*  f0f9a34:	10000040 */ 	b	.L0f0f9b38
/*  f0f9a38:	e7d20050 */ 	swc1	$f18,0x50($s8)
/*  f0f9a3c:	44814000 */ 	mtc1	$at,$f8
.L0f0f9a40:
/*  f0f9a40:	a3cc0060 */ 	sb	$t4,0x60($s8)
/*  f0f9a44:	e7ce0048 */ 	swc1	$f14,0x48($s8)
/*  f0f9a48:	1000003b */ 	b	.L0f0f9b38
/*  f0f9a4c:	e7c80050 */ 	swc1	$f8,0x50($s8)
.L0f0f9a50:
/*  f0f9a50:	8ced0298 */ 	lw	$t5,0x298($a3)
/*  f0f9a54:	05a10005 */ 	bgez	$t5,.L0f0f9a6c
/*  f0f9a58:	00000000 */ 	nop
/*  f0f9a5c:	8cee029c */ 	lw	$t6,0x29c($a3)
/*  f0f9a60:	afb10124 */ 	sw	$s1,0x124($sp)
/*  f0f9a64:	05c00024 */ 	bltz	$t6,.L0f0f9af8
/*  f0f9a68:	00000000 */ 	nop
.L0f0f9a6c:
/*  f0f9a6c:	0fc3f303 */ 	jal	menuGetRoot
/*  f0f9a70:	afb10124 */ 	sw	$s1,0x124($sp)
/*  f0f9a74:	3c013f80 */ 	lui	$at,0x3f80
/*  f0f9a78:	44816000 */ 	mtc1	$at,$f12
/*  f0f9a7c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f9a80:	44807000 */ 	mtc1	$zero,$f14
/*  f0f9a84:	1441001c */ 	bne	$v0,$at,.L0f0f9af8
/*  f0f9a88:	3c0f800a */ 	lui	$t7,%hi(var8009dfc0)
/*  f0f9a8c:	8defdfc0 */ 	lw	$t7,%lo(var8009dfc0)($t7)
/*  f0f9a90:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0f9a94:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x40)
/*  f0f9a98:	11e00015 */ 	beqz	$t7,.L0f0f9af0
/*  f0f9a9c:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0f9aa0:	8f18a000 */ 	lw	$t8,%lo(g_Vars+0x40)($t8)
/*  f0f9aa4:	3c014270 */ 	lui	$at,0x4270
/*  f0f9aa8:	44815000 */ 	mtc1	$at,$f10
/*  f0f9aac:	44982000 */ 	mtc1	$t8,$f4
/*  f0f9ab0:	c7c80050 */ 	lwc1	$f8,0x50($s8)
/*  f0f9ab4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0f9ab8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0f9abc:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f9ac0:	460a3483 */ 	div.s	$f18,$f6,$f10
/*  f0f9ac4:	46124100 */ 	add.s	$f4,$f8,$f18
/*  f0f9ac8:	e7c40050 */ 	swc1	$f4,0x50($s8)
/*  f0f9acc:	c7c60050 */ 	lwc1	$f6,0x50($s8)
/*  f0f9ad0:	4606603c */ 	c.lt.s	$f12,$f6
/*  f0f9ad4:	00000000 */ 	nop
/*  f0f9ad8:	45000005 */ 	bc1f	.L0f0f9af0
/*  f0f9adc:	00000000 */ 	nop
/*  f0f9ae0:	44815000 */ 	mtc1	$at,$f10
/*  f0f9ae4:	a3d90060 */ 	sb	$t9,0x60($s8)
/*  f0f9ae8:	e7ce0048 */ 	swc1	$f14,0x48($s8)
/*  f0f9aec:	e7ca0050 */ 	swc1	$f10,0x50($s8)
.L0f0f9af0:
/*  f0f9af0:	10000011 */ 	b	.L0f0f9b38
/*  f0f9af4:	8fb10124 */ 	lw	$s1,0x124($sp)
.L0f0f9af8:
/*  f0f9af8:	3c08800a */ 	lui	$t0,%hi(g_MenuData+0x15)
/*  f0f9afc:	910819d5 */ 	lbu	$t0,%lo(g_MenuData+0x15)($t0)
/*  f0f9b00:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0f9b04:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0f9b08:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0f9b0c:	11010004 */ 	beq	$t0,$at,.L0f0f9b20
/*  f0f9b10:	8fb10124 */ 	lw	$s1,0x124($sp)
/*  f0f9b14:	3c09800a */ 	lui	$t1,%hi(g_MenuData+0x14)
/*  f0f9b18:	912919d4 */ 	lbu	$t1,%lo(g_MenuData+0x14)($t1)
/*  f0f9b1c:	11200006 */ 	beqz	$t1,.L0f0f9b38
.L0f0f9b20:
/*  f0f9b20:	3c013f00 */ 	lui	$at,0x3f00
/*  f0f9b24:	44814000 */ 	mtc1	$at,$f8
/*  f0f9b28:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0f9b2c:	a3ca0060 */ 	sb	$t2,0x60($s8)
/*  f0f9b30:	e7ce0048 */ 	swc1	$f14,0x48($s8)
/*  f0f9b34:	e7c80050 */ 	swc1	$f8,0x50($s8)
.L0f0f9b38:
/*  f0f9b38:	c7c00048 */ 	lwc1	$f0,0x48($s8)
.L0f0f9b3c:
/*  f0f9b3c:	460e003c */ 	c.lt.s	$f0,$f14
/*  f0f9b40:	00000000 */ 	nop
/*  f0f9b44:	4503001e */ 	bc1tl	.L0f0f9bc0
/*  f0f9b48:	8fc40000 */ 	lw	$a0,0x0($s8)
/*  f0f9b4c:	93cb0060 */ 	lbu	$t3,0x60($s8)
/*  f0f9b50:	8ce30000 */ 	lw	$v1,0x0($a3)
/*  f0f9b54:	3c014416 */ 	lui	$at,0x4416
/*  f0f9b58:	164b0008 */ 	bne	$s2,$t3,.L0f0f9b7c
/*  f0f9b5c:	00036880 */ 	sll	$t5,$v1,0x2
/*  f0f9b60:	00036040 */ 	sll	$t4,$v1,0x1
/*  f0f9b64:	448c9000 */ 	mtc1	$t4,$f18
/*  f0f9b68:	00000000 */ 	nop
/*  f0f9b6c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0f9b70:	46040180 */ 	add.s	$f6,$f0,$f4
/*  f0f9b74:	10000007 */ 	b	.L0f0f9b94
/*  f0f9b78:	e7c60048 */ 	swc1	$f6,0x48($s8)
.L0f0f9b7c:
/*  f0f9b7c:	01a36821 */ 	addu	$t5,$t5,$v1
/*  f0f9b80:	448d5000 */ 	mtc1	$t5,$f10
/*  f0f9b84:	00000000 */ 	nop
/*  f0f9b88:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f0f9b8c:	46080480 */ 	add.s	$f18,$f0,$f8
/*  f0f9b90:	e7d20048 */ 	swc1	$f18,0x48($s8)
.L0f0f9b94:
/*  f0f9b94:	44812000 */ 	mtc1	$at,$f4
/*  f0f9b98:	c7c60048 */ 	lwc1	$f6,0x48($s8)
/*  f0f9b9c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0f9ba0:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0f9ba4:	00000000 */ 	nop
/*  f0f9ba8:	45020005 */ 	bc1fl	.L0f0f9bc0
/*  f0f9bac:	8fc40000 */ 	lw	$a0,0x0($s8)
/*  f0f9bb0:	44815000 */ 	mtc1	$at,$f10
/*  f0f9bb4:	00000000 */ 	nop
/*  f0f9bb8:	e7ca0048 */ 	swc1	$f10,0x48($s8)
/*  f0f9bbc:	8fc40000 */ 	lw	$a0,0x0($s8)
.L0f0f9bc0:
/*  f0f9bc0:	afb10124 */ 	sw	$s1,0x124($sp)
/*  f0f9bc4:	8c8e0010 */ 	lw	$t6,0x10($a0)
/*  f0f9bc8:	31cf0200 */ 	andi	$t7,$t6,0x200
/*  f0f9bcc:	15e00004 */ 	bnez	$t7,.L0f0f9be0
/*  f0f9bd0:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0f9bd4:	8fa60114 */ 	lw	$a2,0x114($sp)
/*  f0f9bd8:	0fc3c84d */ 	jal	func0f0f2134
/*  f0f9bdc:	afb10124 */ 	sw	$s1,0x124($sp)
.L0f0f9be0:
/*  f0f9be0:	0fc3dfa6 */ 	jal	func0f0f7e98
/*  f0f9be4:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0f9be8:	0fc3c7bd */ 	jal	func0f0f1ef4
/*  f0f9bec:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0f9bf0:	3c02800a */ 	lui	$v0,%hi(g_MenuData+0x4)
/*  f0f9bf4:	8c4219c4 */ 	lw	$v0,%lo(g_MenuData+0x4)($v0)
/*  f0f9bf8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0f9bfc:	10410005 */ 	beq	$v0,$at,.L0f0f9c14
/*  f0f9c00:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0f9c04:	10410003 */ 	beq	$v0,$at,.L0f0f9c14
/*  f0f9c08:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0f9c0c:	54410009 */ 	bnel	$v0,$at,.L0f0f9c34
/*  f0f9c10:	8fc5002c */ 	lw	$a1,0x2c($s8)
.L0f0f9c14:
/*  f0f9c14:	8fd8002c */ 	lw	$t8,0x2c($s8)
/*  f0f9c18:	8fd90030 */ 	lw	$t9,0x30($s8)
/*  f0f9c1c:	3c017f1b */ 	lui	$at,%hi(var7f1b2a40)
/*  f0f9c20:	afd80014 */ 	sw	$t8,0x14($s8)
/*  f0f9c24:	afd90018 */ 	sw	$t9,0x18($s8)
/*  f0f9c28:	1000004b */ 	b	.L0f0f9d58
/*  f0f9c2c:	c42c2a40 */ 	lwc1	$f12,%lo(var7f1b2a40)($at)
/*  f0f9c30:	8fc5002c */ 	lw	$a1,0x2c($s8)
.L0f0f9c34:
/*  f0f9c34:	8fc40014 */ 	lw	$a0,0x14($s8)
/*  f0f9c38:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0f9c3c:	10a40021 */ 	beq	$a1,$a0,.L0f0f9cc4
/*  f0f9c40:	00803025 */ 	or	$a2,$a0,$zero
/*  f0f9c44:	8c639fc0 */ 	lw	$v1,%lo(g_Vars)($v1)
/*  f0f9c48:	44844000 */ 	mtc1	$a0,$f8
/*  f0f9c4c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f9c50:	1860000e */ 	blez	$v1,.L0f0f9c8c
/*  f0f9c54:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f0f9c58:	44859000 */ 	mtc1	$a1,$f18
/*  f0f9c5c:	3c017f1b */ 	lui	$at,%hi(var7f1b2a44)
/*  f0f9c60:	c4262a44 */ 	lwc1	$f6,%lo(var7f1b2a44)($at)
/*  f0f9c64:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0f9c68:	3c017f1b */ 	lui	$at,%hi(var7f1b2a48)
/*  f0f9c6c:	c42c2a48 */ 	lwc1	$f12,%lo(var7f1b2a48)($at)
/*  f0f9c70:	46062082 */ 	mul.s	$f2,$f4,$f6
/*  f0f9c74:	00000000 */ 	nop
.L0f0f9c78:
/*  f0f9c78:	46006282 */ 	mul.s	$f10,$f12,$f0
/*  f0f9c7c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f9c80:	0043082a */ 	slt	$at,$v0,$v1
/*  f0f9c84:	1420fffc */ 	bnez	$at,.L0f0f9c78
/*  f0f9c88:	460a1000 */ 	add.s	$f0,$f2,$f10
.L0f0f9c8c:
/*  f0f9c8c:	4600020d */ 	trunc.w.s	$f8,$f0
/*  f0f9c90:	44024000 */ 	mfc1	$v0,$f8
/*  f0f9c94:	00000000 */ 	nop
/*  f0f9c98:	10a2000a */ 	beq	$a1,$v0,.L0f0f9cc4
/*  f0f9c9c:	afc20014 */ 	sw	$v0,0x14($s8)
/*  f0f9ca0:	14c20008 */ 	bne	$a2,$v0,.L0f0f9cc4
/*  f0f9ca4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f9ca8:	0045082a */ 	slt	$at,$v0,$a1
/*  f0f9cac:	10200004 */ 	beqz	$at,.L0f0f9cc0
/*  f0f9cb0:	248affff */ 	addiu	$t2,$a0,-1
/*  f0f9cb4:	24490001 */ 	addiu	$t1,$v0,0x1
/*  f0f9cb8:	10000002 */ 	b	.L0f0f9cc4
/*  f0f9cbc:	afc90014 */ 	sw	$t1,0x14($s8)
.L0f0f9cc0:
/*  f0f9cc0:	afca0014 */ 	sw	$t2,0x14($s8)
.L0f0f9cc4:
/*  f0f9cc4:	8fc50030 */ 	lw	$a1,0x30($s8)
/*  f0f9cc8:	8fc40018 */ 	lw	$a0,0x18($s8)
/*  f0f9ccc:	3c017f1b */ 	lui	$at,%hi(var7f1b2a50)
/*  f0f9cd0:	c42c2a50 */ 	lwc1	$f12,%lo(var7f1b2a50)($at)
/*  f0f9cd4:	10a40020 */ 	beq	$a1,$a0,.L0f0f9d58
/*  f0f9cd8:	00803025 */ 	or	$a2,$a0,$zero
/*  f0f9cdc:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0f9ce0:	8c639fc0 */ 	lw	$v1,%lo(g_Vars)($v1)
/*  f0f9ce4:	44849000 */ 	mtc1	$a0,$f18
/*  f0f9ce8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f9cec:	1860000c */ 	blez	$v1,.L0f0f9d20
/*  f0f9cf0:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f0f9cf4:	44852000 */ 	mtc1	$a1,$f4
/*  f0f9cf8:	3c017f1b */ 	lui	$at,%hi(var7f1b2a54)
/*  f0f9cfc:	c42a2a54 */ 	lwc1	$f10,%lo(var7f1b2a54)($at)
/*  f0f9d00:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0f9d04:	460a3082 */ 	mul.s	$f2,$f6,$f10
/*  f0f9d08:	00000000 */ 	nop
.L0f0f9d0c:
/*  f0f9d0c:	46006202 */ 	mul.s	$f8,$f12,$f0
/*  f0f9d10:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f9d14:	0043082a */ 	slt	$at,$v0,$v1
/*  f0f9d18:	1420fffc */ 	bnez	$at,.L0f0f9d0c
/*  f0f9d1c:	46081000 */ 	add.s	$f0,$f2,$f8
.L0f0f9d20:
/*  f0f9d20:	4600048d */ 	trunc.w.s	$f18,$f0
/*  f0f9d24:	44029000 */ 	mfc1	$v0,$f18
/*  f0f9d28:	00000000 */ 	nop
/*  f0f9d2c:	10a2000a */ 	beq	$a1,$v0,.L0f0f9d58
/*  f0f9d30:	afc20018 */ 	sw	$v0,0x18($s8)
/*  f0f9d34:	14c20008 */ 	bne	$a2,$v0,.L0f0f9d58
/*  f0f9d38:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f9d3c:	0045082a */ 	slt	$at,$v0,$a1
/*  f0f9d40:	10200004 */ 	beqz	$at,.L0f0f9d54
/*  f0f9d44:	248dffff */ 	addiu	$t5,$a0,-1
/*  f0f9d48:	244c0001 */ 	addiu	$t4,$v0,0x1
/*  f0f9d4c:	10000002 */ 	b	.L0f0f9d58
/*  f0f9d50:	afcc0018 */ 	sw	$t4,0x18($s8)
.L0f0f9d54:
/*  f0f9d54:	afcd0018 */ 	sw	$t5,0x18($s8)
.L0f0f9d58:
/*  f0f9d58:	8fc50034 */ 	lw	$a1,0x34($s8)
/*  f0f9d5c:	8fc4001c */ 	lw	$a0,0x1c($s8)
/*  f0f9d60:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0f9d64:	10a4001f */ 	beq	$a1,$a0,.L0f0f9de4
/*  f0f9d68:	00803025 */ 	or	$a2,$a0,$zero
/*  f0f9d6c:	8c639fc0 */ 	lw	$v1,%lo(g_Vars)($v1)
/*  f0f9d70:	44842000 */ 	mtc1	$a0,$f4
/*  f0f9d74:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f9d78:	1860000c */ 	blez	$v1,.L0f0f9dac
/*  f0f9d7c:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0f9d80:	44853000 */ 	mtc1	$a1,$f6
/*  f0f9d84:	3c017f1b */ 	lui	$at,%hi(var7f1b2a58)
/*  f0f9d88:	c4282a58 */ 	lwc1	$f8,%lo(var7f1b2a58)($at)
/*  f0f9d8c:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0f9d90:	46085082 */ 	mul.s	$f2,$f10,$f8
/*  f0f9d94:	00000000 */ 	nop
.L0f0f9d98:
/*  f0f9d98:	46006482 */ 	mul.s	$f18,$f12,$f0
/*  f0f9d9c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f9da0:	0043082a */ 	slt	$at,$v0,$v1
/*  f0f9da4:	1420fffc */ 	bnez	$at,.L0f0f9d98
/*  f0f9da8:	46121000 */ 	add.s	$f0,$f2,$f18
.L0f0f9dac:
/*  f0f9dac:	4600010d */ 	trunc.w.s	$f4,$f0
/*  f0f9db0:	44022000 */ 	mfc1	$v0,$f4
/*  f0f9db4:	00000000 */ 	nop
/*  f0f9db8:	10a2000a */ 	beq	$a1,$v0,.L0f0f9de4
/*  f0f9dbc:	afc2001c */ 	sw	$v0,0x1c($s8)
/*  f0f9dc0:	14c20008 */ 	bne	$a2,$v0,.L0f0f9de4
/*  f0f9dc4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f9dc8:	0045082a */ 	slt	$at,$v0,$a1
/*  f0f9dcc:	10200004 */ 	beqz	$at,.L0f0f9de0
/*  f0f9dd0:	2498ffff */ 	addiu	$t8,$a0,-1
/*  f0f9dd4:	244f0001 */ 	addiu	$t7,$v0,0x1
/*  f0f9dd8:	10000002 */ 	b	.L0f0f9de4
/*  f0f9ddc:	afcf001c */ 	sw	$t7,0x1c($s8)
.L0f0f9de0:
/*  f0f9de0:	afd8001c */ 	sw	$t8,0x1c($s8)
.L0f0f9de4:
/*  f0f9de4:	8fc50038 */ 	lw	$a1,0x38($s8)
/*  f0f9de8:	8fc40020 */ 	lw	$a0,0x20($s8)
/*  f0f9dec:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0f9df0:	10a4001f */ 	beq	$a1,$a0,.L0f0f9e70
/*  f0f9df4:	00803025 */ 	or	$a2,$a0,$zero
/*  f0f9df8:	8c639fc0 */ 	lw	$v1,%lo(g_Vars)($v1)
/*  f0f9dfc:	44843000 */ 	mtc1	$a0,$f6
/*  f0f9e00:	00001025 */ 	or	$v0,$zero,$zero
/*  f0f9e04:	1860000c */ 	blez	$v1,.L0f0f9e38
/*  f0f9e08:	46803020 */ 	cvt.s.w	$f0,$f6
/*  f0f9e0c:	44855000 */ 	mtc1	$a1,$f10
/*  f0f9e10:	3c017f1b */ 	lui	$at,%hi(var7f1b2a5c)
/*  f0f9e14:	c4322a5c */ 	lwc1	$f18,%lo(var7f1b2a5c)($at)
/*  f0f9e18:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f0f9e1c:	46124082 */ 	mul.s	$f2,$f8,$f18
/*  f0f9e20:	00000000 */ 	nop
.L0f0f9e24:
/*  f0f9e24:	46006102 */ 	mul.s	$f4,$f12,$f0
/*  f0f9e28:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0f9e2c:	0043082a */ 	slt	$at,$v0,$v1
/*  f0f9e30:	1420fffc */ 	bnez	$at,.L0f0f9e24
/*  f0f9e34:	46041000 */ 	add.s	$f0,$f2,$f4
.L0f0f9e38:
/*  f0f9e38:	4600018d */ 	trunc.w.s	$f6,$f0
/*  f0f9e3c:	44023000 */ 	mfc1	$v0,$f6
/*  f0f9e40:	00000000 */ 	nop
/*  f0f9e44:	10a2000a */ 	beq	$a1,$v0,.L0f0f9e70
/*  f0f9e48:	afc20020 */ 	sw	$v0,0x20($s8)
/*  f0f9e4c:	14c20008 */ 	bne	$a2,$v0,.L0f0f9e70
/*  f0f9e50:	00402025 */ 	or	$a0,$v0,$zero
/*  f0f9e54:	0045082a */ 	slt	$at,$v0,$a1
/*  f0f9e58:	10200004 */ 	beqz	$at,.L0f0f9e6c
/*  f0f9e5c:	2489ffff */ 	addiu	$t1,$a0,-1
/*  f0f9e60:	24480001 */ 	addiu	$t0,$v0,0x1
/*  f0f9e64:	10000002 */ 	b	.L0f0f9e70
/*  f0f9e68:	afc80020 */ 	sw	$t0,0x20($s8)
.L0f0f9e6c:
/*  f0f9e6c:	afc90020 */ 	sw	$t1,0x20($s8)
.L0f0f9e70:
/*  f0f9e70:	8faa0124 */ 	lw	$t2,0x124($sp)
/*  f0f9e74:	24040066 */ 	addiu	$a0,$zero,0x66
/*  f0f9e78:	02602825 */ 	or	$a1,$s3,$zero
/*  f0f9e7c:	afaa00f0 */ 	sw	$t2,0xf0($sp)
/*  f0f9e80:	8e62000c */ 	lw	$v0,0xc($s3)
/*  f0f9e84:	50400004 */ 	beqzl	$v0,.L0f0f9e98
/*  f0f9e88:	8fcb000c */ 	lw	$t3,0xc($s8)
/*  f0f9e8c:	0040f809 */ 	jalr	$v0
/*  f0f9e90:	27a600f0 */ 	addiu	$a2,$sp,0xf0
/*  f0f9e94:	8fcb000c */ 	lw	$t3,0xc($s8)
.L0f0f9e98:
/*  f0f9e98:	3c0d800a */ 	lui	$t5,%hi(g_Vars)
/*  f0f9e9c:	27b600d8 */ 	addiu	$s6,$sp,0xd8
/*  f0f9ea0:	51600007 */ 	beqzl	$t3,.L0f0f9ec0
/*  f0f9ea4:	afc00010 */ 	sw	$zero,0x10($s8)
/*  f0f9ea8:	8fcc0010 */ 	lw	$t4,0x10($s8)
/*  f0f9eac:	8dad9fc0 */ 	lw	$t5,%lo(g_Vars)($t5)
/*  f0f9eb0:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f0f9eb4:	10000002 */ 	b	.L0f0f9ec0
/*  f0f9eb8:	afce0010 */ 	sw	$t6,0x10($s8)
/*  f0f9ebc:	afc00010 */ 	sw	$zero,0x10($s8)
.L0f0f9ec0:
/*  f0f9ec0:	93c30005 */ 	lbu	$v1,0x5($s8)
/*  f0f9ec4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0f9ec8:	8fa50114 */ 	lw	$a1,0x114($sp)
/*  f0f9ecc:	5860007c */ 	blezl	$v1,.L0f0fa0c0
/*  f0f9ed0:	8fd00008 */ 	lw	$s0,0x8($s8)
/*  f0f9ed4:	93cf0004 */ 	lbu	$t7,0x4($s8)
.L0f0f9ed8:
/*  f0f9ed8:	0000a825 */ 	or	$s5,$zero,$zero
/*  f0f9edc:	01e61021 */ 	addu	$v0,$t7,$a2
/*  f0f9ee0:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f0f9ee4:	0302c021 */ 	addu	$t8,$t8,$v0
/*  f0f9ee8:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f0f9eec:	00b8b821 */ 	addu	$s7,$a1,$t8
/*  f0f9ef0:	92f90668 */ 	lbu	$t9,0x668($s7)
/*  f0f9ef4:	5b20006e */ 	blezl	$t9,.L0f0fa0b0
/*  f0f9ef8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0f9efc:	afa60104 */ 	sw	$a2,0x104($sp)
/*  f0f9f00:	96e80666 */ 	lhu	$t0,0x666($s7)
.L0f0f9f04:
/*  f0f9f04:	8fa50114 */ 	lw	$a1,0x114($sp)
/*  f0f9f08:	8fcc0000 */ 	lw	$t4,0x0($s8)
/*  f0f9f0c:	01151021 */ 	addu	$v0,$t0,$s5
/*  f0f9f10:	00024880 */ 	sll	$t1,$v0,0x2
/*  f0f9f14:	00a9a021 */ 	addu	$s4,$a1,$t1
/*  f0f9f18:	928a04fe */ 	lbu	$t2,0x4fe($s4)
/*  f0f9f1c:	8d8d0008 */ 	lw	$t5,0x8($t4)
/*  f0f9f20:	3c048007 */ 	lui	$a0,%hi(g_MpPlayerNum)
/*  f0f9f24:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f0f9f28:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f0f9f2c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0f9f30:	00009825 */ 	or	$s3,$zero,$zero
/*  f0f9f34:	8fb10124 */ 	lw	$s1,0x124($sp)
/*  f0f9f38:	8c841448 */ 	lw	$a0,%lo(g_MpPlayerNum)($a0)
/*  f0f9f3c:	0fc62ff6 */ 	jal	mpIsPlayerLockedOut
/*  f0f9f40:	016d9021 */ 	addu	$s2,$t3,$t5
/*  f0f9f44:	50400008 */ 	beqzl	$v0,.L0f0f9f68
/*  f0f9f48:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f0f9f4c:	8e4e0004 */ 	lw	$t6,0x4($s2)
/*  f0f9f50:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0f9f54:	05e30004 */ 	bgezl	$t7,.L0f0f9f68
/*  f0f9f58:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f0f9f5c:	10000013 */ 	b	.L0f0f9fac
/*  f0f9f60:	02c08825 */ 	or	$s1,$s6,$zero
/*  f0f9f64:	8e580004 */ 	lw	$t8,0x4($s2)
.L0f0f9f68:
/*  f0f9f68:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f0f9f6c:	07210009 */ 	bgez	$t9,.L0f0f9f94
/*  f0f9f70:	00000000 */ 	nop
/*  f0f9f74:	0fc62587 */ 	jal	mpGetWeaponSet
/*  f0f9f78:	00000000 */ 	nop
/*  f0f9f7c:	0fc62422 */ 	jal	func0f189088
/*  f0f9f80:	00408025 */ 	or	$s0,$v0,$zero
/*  f0f9f84:	10500003 */ 	beq	$v0,$s0,.L0f0f9f94
/*  f0f9f88:	00000000 */ 	nop
/*  f0f9f8c:	10000007 */ 	b	.L0f0f9fac
/*  f0f9f90:	02c08825 */ 	or	$s1,$s6,$zero
.L0f0f9f94:
/*  f0f9f94:	3c08800a */ 	lui	$t0,%hi(g_MenuData+0x4)
/*  f0f9f98:	8d0819c4 */ 	lw	$t0,%lo(g_MenuData+0x4)($t0)
/*  f0f9f9c:	2401000c */ 	addiu	$at,$zero,0xc
/*  f0f9fa0:	55010003 */ 	bnel	$t0,$at,.L0f0f9fb0
/*  f0f9fa4:	828204ff */ 	lb	$v0,0x4ff($s4)
/*  f0f9fa8:	02c08825 */ 	or	$s1,$s6,$zero
.L0f0f9fac:
/*  f0f9fac:	828204ff */ 	lb	$v0,0x4ff($s4)
.L0f0f9fb0:
/*  f0f9fb0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0f9fb4:	8fa90114 */ 	lw	$t1,0x114($sp)
/*  f0f9fb8:	10410004 */ 	beq	$v0,$at,.L0f0f9fcc
/*  f0f9fbc:	3c0c8007 */ 	lui	$t4,%hi(g_MpPlayerNum)
/*  f0f9fc0:	00025080 */ 	sll	$t2,$v0,0x2
/*  f0f9fc4:	012a9821 */ 	addu	$s3,$t1,$t2
/*  f0f9fc8:	267306dc */ 	addiu	$s3,$s3,0x6dc
.L0f0f9fcc:
/*  f0f9fcc:	8d8c1448 */ 	lw	$t4,%lo(g_MpPlayerNum)($t4)
/*  f0f9fd0:	3c0d800a */ 	lui	$t5,%hi(g_Menus+0xe40)
/*  f0f9fd4:	3c0f8006 */ 	lui	$t7,%hi(var8005dd58)
/*  f0f9fd8:	000c58c0 */ 	sll	$t3,$t4,0x3
/*  f0f9fdc:	016c5823 */ 	subu	$t3,$t3,$t4
/*  f0f9fe0:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f0f9fe4:	016c5821 */ 	addu	$t3,$t3,$t4
/*  f0f9fe8:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f0f9fec:	016c5823 */ 	subu	$t3,$t3,$t4
/*  f0f9ff0:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f0f9ff4:	01ab6821 */ 	addu	$t5,$t5,$t3
/*  f0f9ff8:	8dadee40 */ 	lw	$t5,%lo(g_Menus+0xe40)($t5)
/*  f0f9ffc:	000d77c2 */ 	srl	$t6,$t5,0x1f
/*  f0fa000:	55c00023 */ 	bnezl	$t6,.L0f0fa090
/*  f0fa004:	92e90668 */ 	lbu	$t1,0x668($s7)
/*  f0fa008:	8defdd58 */ 	lw	$t7,%lo(var8005dd58)($t7)
/*  f0fa00c:	8fb40128 */ 	lw	$s4,0x128($sp)
/*  f0fa010:	15e0001e */ 	bnez	$t7,.L0f0fa08c
/*  f0fa014:	32980001 */ 	andi	$t8,$s4,0x1
/*  f0fa018:	13000017 */ 	beqz	$t8,.L0f0fa078
/*  f0fa01c:	02402025 */ 	or	$a0,$s2,$zero
/*  f0fa020:	8fd90008 */ 	lw	$t9,0x8($s8)
/*  f0fa024:	56590015 */ 	bnel	$s2,$t9,.L0f0fa07c
/*  f0fa028:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0fa02c:	8fc8000c */ 	lw	$t0,0xc($s8)
/*  f0fa030:	36900002 */ 	ori	$s0,$s4,0x2
/*  f0fa034:	02402025 */ 	or	$a0,$s2,$zero
/*  f0fa038:	11000009 */ 	beqz	$t0,.L0f0fa060
/*  f0fa03c:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0fa040:	02402025 */ 	or	$a0,$s2,$zero
/*  f0fa044:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0fa048:	02203025 */ 	or	$a2,$s1,$zero
/*  f0fa04c:	36070004 */ 	ori	$a3,$s0,0x4
/*  f0fa050:	0fc3c1c1 */ 	jal	func0f0f0704
/*  f0fa054:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0fa058:	1000000c */ 	b	.L0f0fa08c
/*  f0fa05c:	afa2011c */ 	sw	$v0,0x11c($sp)
.L0f0fa060:
/*  f0fa060:	02203025 */ 	or	$a2,$s1,$zero
/*  f0fa064:	02003825 */ 	or	$a3,$s0,$zero
/*  f0fa068:	0fc3c1c1 */ 	jal	func0f0f0704
/*  f0fa06c:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f0fa070:	10000006 */ 	b	.L0f0fa08c
/*  f0fa074:	afa2011c */ 	sw	$v0,0x11c($sp)
.L0f0fa078:
/*  f0fa078:	03c02825 */ 	or	$a1,$s8,$zero
.L0f0fa07c:
/*  f0fa07c:	02203025 */ 	or	$a2,$s1,$zero
/*  f0fa080:	02803825 */ 	or	$a3,$s4,$zero
/*  f0fa084:	0fc3c1c1 */ 	jal	func0f0f0704
/*  f0fa088:	afb30010 */ 	sw	$s3,0x10($sp)
.L0f0fa08c:
/*  f0fa08c:	92e90668 */ 	lbu	$t1,0x668($s7)
.L0f0fa090:
/*  f0fa090:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f0fa094:	02a9082a */ 	slt	$at,$s5,$t1
/*  f0fa098:	5420ff9a */ 	bnezl	$at,.L0f0f9f04
/*  f0fa09c:	96e80666 */ 	lhu	$t0,0x666($s7)
/*  f0fa0a0:	93c30005 */ 	lbu	$v1,0x5($s8)
/*  f0fa0a4:	8fa60104 */ 	lw	$a2,0x104($sp)
/*  f0fa0a8:	8fa50114 */ 	lw	$a1,0x114($sp)
/*  f0fa0ac:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f0fa0b0:
/*  f0fa0b0:	00c3082a */ 	slt	$at,$a2,$v1
/*  f0fa0b4:	5420ff88 */ 	bnezl	$at,.L0f0f9ed8
/*  f0fa0b8:	93cf0004 */ 	lbu	$t7,0x4($s8)
/*  f0fa0bc:	8fd00008 */ 	lw	$s0,0x8($s8)
.L0f0fa0c0:
/*  f0fa0c0:	1200000d */ 	beqz	$s0,.L0f0fa0f8
/*  f0fa0c4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fa0c8:	0fc3c962 */ 	jal	func0f0f2588
/*  f0fa0cc:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0fa0d0:	10400009 */ 	beqz	$v0,.L0f0fa0f8
/*  f0fa0d4:	8faa0128 */ 	lw	$t2,0x128($sp)
/*  f0fa0d8:	314c0001 */ 	andi	$t4,$t2,0x1
/*  f0fa0dc:	11800006 */ 	beqz	$t4,.L0f0fa0f8
/*  f0fa0e0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0fa0e4:	8fae0124 */ 	lw	$t6,0x124($sp)
/*  f0fa0e8:	afab011c */ 	sw	$t3,0x11c($sp)
/*  f0fa0ec:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0fa0f0:	a1cd0001 */ 	sb	$t5,0x1($t6)
/*  f0fa0f4:	afc0000c */ 	sw	$zero,0xc($s8)
.L0f0fa0f8:
/*  f0fa0f8:	8faf011c */ 	lw	$t7,0x11c($sp)
/*  f0fa0fc:	8fb80128 */ 	lw	$t8,0x128($sp)
/*  f0fa100:	11e0006f */ 	beqz	$t7,.L0f0fa2c0
/*  f0fa104:	33190001 */ 	andi	$t9,$t8,0x1
/*  f0fa108:	5320006e */ 	beqzl	$t9,.L0f0fa2c4
/*  f0fa10c:	8fd00008 */ 	lw	$s0,0x8($s8)
/*  f0fa110:	8fc8000c */ 	lw	$t0,0xc($s8)
/*  f0fa114:	3c098007 */ 	lui	$t1,%hi(g_MpPlayerNum)
/*  f0fa118:	5500006a */ 	bnezl	$t0,.L0f0fa2c4
/*  f0fa11c:	8fd00008 */ 	lw	$s0,0x8($s8)
/*  f0fa120:	8d291448 */ 	lw	$t1,%lo(g_MpPlayerNum)($t1)
/*  f0fa124:	3c0c800a */ 	lui	$t4,%hi(g_Menus)
/*  f0fa128:	258ce000 */ 	addiu	$t4,$t4,%lo(g_Menus)
/*  f0fa12c:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f0fa130:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0fa134:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0fa138:	01495021 */ 	addu	$t2,$t2,$t1
/*  f0fa13c:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0fa140:	01495023 */ 	subu	$t2,$t2,$t1
/*  f0fa144:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0fa148:	014c1021 */ 	addu	$v0,$t2,$t4
/*  f0fa14c:	844b04f4 */ 	lh	$t3,0x4f4($v0)
/*  f0fa150:	8fd00008 */ 	lw	$s0,0x8($s8)
/*  f0fa154:	8faf0124 */ 	lw	$t7,0x124($sp)
/*  f0fa158:	000b6880 */ 	sll	$t5,$t3,0x2
/*  f0fa15c:	01ab6823 */ 	subu	$t5,$t5,$t3
/*  f0fa160:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0fa164:	004d1821 */ 	addu	$v1,$v0,$t5
/*  f0fa168:	806e0460 */ 	lb	$t6,0x460($v1)
/*  f0fa16c:	2463044c */ 	addiu	$v1,$v1,1100
/*  f0fa170:	8fb90124 */ 	lw	$t9,0x124($sp)
/*  f0fa174:	29c10002 */ 	slti	$at,$t6,0x2
/*  f0fa178:	1020000c */ 	beqz	$at,.L0f0fa1ac
/*  f0fa17c:	02008825 */ 	or	$s1,$s0,$zero
/*  f0fa180:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0fa184:	81e50000 */ 	lb	$a1,0x0($t7)
/*  f0fa188:	0fc3cb11 */ 	jal	func0f0f2c44
/*  f0fa18c:	81e60001 */ 	lb	$a2,0x1($t7)
/*  f0fa190:	8fd80008 */ 	lw	$t8,0x8($s8)
/*  f0fa194:	52380016 */ 	beql	$s1,$t8,.L0f0fa1f0
/*  f0fa198:	8fa90124 */ 	lw	$t1,0x124($sp)
/*  f0fa19c:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0fa1a0:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0fa1a4:	10000012 */ 	b	.L0f0fa1f0
/*  f0fa1a8:	8fa90124 */ 	lw	$t1,0x124($sp)
.L0f0fa1ac:
/*  f0fa1ac:	02008825 */ 	or	$s1,$s0,$zero
/*  f0fa1b0:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0fa1b4:	83250000 */ 	lb	$a1,0x0($t9)
/*  f0fa1b8:	0fc3cb11 */ 	jal	func0f0f2c44
/*  f0fa1bc:	83260001 */ 	lb	$a2,0x1($t9)
/*  f0fa1c0:	10400005 */ 	beqz	$v0,.L0f0fa1d8
/*  f0fa1c4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fa1c8:	0fc3e40c */ 	jal	func0f0f9030
/*  f0fa1cc:	00000000 */ 	nop
/*  f0fa1d0:	10000007 */ 	b	.L0f0fa1f0
/*  f0fa1d4:	8fa90124 */ 	lw	$t1,0x124($sp)
.L0f0fa1d8:
/*  f0fa1d8:	8fc80008 */ 	lw	$t0,0x8($s8)
/*  f0fa1dc:	52280004 */ 	beql	$s1,$t0,.L0f0fa1f0
/*  f0fa1e0:	8fa90124 */ 	lw	$t1,0x124($sp)
/*  f0fa1e4:	0fc3c27c */ 	jal	func0f0f09f0
/*  f0fa1e8:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0fa1ec:	8fa90124 */ 	lw	$t1,0x124($sp)
.L0f0fa1f0:
/*  f0fa1f0:	91220003 */ 	lbu	$v0,0x3($t1)
/*  f0fa1f4:	50400020 */ 	beqzl	$v0,.L0f0fa278
/*  f0fa1f8:	8fcf0000 */ 	lw	$t7,0x0($s8)
/*  f0fa1fc:	8fca0000 */ 	lw	$t2,0x0($s8)
/*  f0fa200:	3c0b800a */ 	lui	$t3,%hi(g_Vars+0x498)
/*  f0fa204:	8d420010 */ 	lw	$v0,0x10($t2)
/*  f0fa208:	304c0800 */ 	andi	$t4,$v0,0x800
/*  f0fa20c:	11800013 */ 	beqz	$t4,.L0f0fa25c
/*  f0fa210:	304e0020 */ 	andi	$t6,$v0,0x20
/*  f0fa214:	8d6ba458 */ 	lw	$t3,%lo(g_Vars+0x498)($t3)
/*  f0fa218:	3c0d8009 */ 	lui	$t5,%hi(g_Is4Mb)
/*  f0fa21c:	1160000f */ 	beqz	$t3,.L0f0fa25c
/*  f0fa220:	00000000 */ 	nop
/*  f0fa224:	91ad0af0 */ 	lbu	$t5,%lo(g_Is4Mb)($t5)
/*  f0fa228:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fa22c:	3c048008 */ 	lui	$a0,%hi(menudialog_2aba0)
/*  f0fa230:	15a10006 */ 	bne	$t5,$at,.L0f0fa24c
/*  f0fa234:	00000000 */ 	nop
/*  f0fa238:	3c048007 */ 	lui	$a0,%hi(menudialog_mpdropout)
/*  f0fa23c:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f0fa240:	248452fc */ 	addiu	$a0,$a0,%lo(menudialog_mpdropout)
/*  f0fa244:	1000001f */ 	b	.L0f0fa2c4
/*  f0fa248:	8fd00008 */ 	lw	$s0,0x8($s8)
.L0f0fa24c:
/*  f0fa24c:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f0fa250:	24844b80 */ 	addiu	$a0,$a0,%lo(menudialog_2aba0)
/*  f0fa254:	1000001b */ 	b	.L0f0fa2c4
/*  f0fa258:	8fd00008 */ 	lw	$s0,0x8($s8)
.L0f0fa25c:
/*  f0fa25c:	55c00019 */ 	bnezl	$t6,.L0f0fa2c4
/*  f0fa260:	8fd00008 */ 	lw	$s0,0x8($s8)
/*  f0fa264:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f0fa268:	00000000 */ 	nop
/*  f0fa26c:	10000015 */ 	b	.L0f0fa2c4
/*  f0fa270:	8fd00008 */ 	lw	$s0,0x8($s8)
/*  f0fa274:	8fcf0000 */ 	lw	$t7,0x0($s8)
.L0f0fa278:
/*  f0fa278:	8df80010 */ 	lw	$t8,0x10($t7)
/*  f0fa27c:	33190001 */ 	andi	$t9,$t8,0x1
/*  f0fa280:	53200010 */ 	beqzl	$t9,.L0f0fa2c4
/*  f0fa284:	8fd00008 */ 	lw	$s0,0x8($s8)
/*  f0fa288:	93c80060 */ 	lbu	$t0,0x60($s8)
/*  f0fa28c:	8fa90124 */ 	lw	$t1,0x124($sp)
/*  f0fa290:	5900000c */ 	blezl	$t0,.L0f0fa2c4
/*  f0fa294:	8fd00008 */ 	lw	$s0,0x8($s8)
/*  f0fa298:	912a0002 */ 	lbu	$t2,0x2($t1)
/*  f0fa29c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fa2a0:	304b0001 */ 	andi	$t3,$v0,0x1
/*  f0fa2a4:	314c0001 */ 	andi	$t4,$t2,0x1
/*  f0fa2a8:	11810003 */ 	beq	$t4,$at,.L0f0fa2b8
/*  f0fa2ac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fa2b0:	55610004 */ 	bnel	$t3,$at,.L0f0fa2c4
/*  f0fa2b4:	8fd00008 */ 	lw	$s0,0x8($s8)
.L0f0fa2b8:
/*  f0fa2b8:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f0fa2bc:	00000000 */ 	nop
.L0f0fa2c0:
/*  f0fa2c0:	8fd00008 */ 	lw	$s0,0x8($s8)
.L0f0fa2c4:
/*  f0fa2c4:	8fcd0000 */ 	lw	$t5,0x0($s8)
/*  f0fa2c8:	1200002b */ 	beqz	$s0,.L0f0fa378
/*  f0fa2cc:	8da20010 */ 	lw	$v0,0x10($t5)
/*  f0fa2d0:	304e0008 */ 	andi	$t6,$v0,0x8
/*  f0fa2d4:	15c00028 */ 	bnez	$t6,.L0f0fa378
/*  f0fa2d8:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0fa2dc:	02002825 */ 	or	$a1,$s0,$zero
/*  f0fa2e0:	27a6007c */ 	addiu	$a2,$sp,0x7c
/*  f0fa2e4:	0fc3c8d5 */ 	jal	func0f0f2354
/*  f0fa2e8:	27a70078 */ 	addiu	$a3,$sp,0x78
/*  f0fa2ec:	8fcf0008 */ 	lw	$t7,0x8($s8)
/*  f0fa2f0:	8fa9007c */ 	lw	$t1,0x7c($sp)
/*  f0fa2f4:	8df80004 */ 	lw	$t8,0x4($t7)
/*  f0fa2f8:	0018cbc0 */ 	sll	$t9,$t8,0xf
/*  f0fa2fc:	0720001c */ 	bltz	$t9,.L0f0fa370
/*  f0fa300:	00000000 */ 	nop
/*  f0fa304:	8fa80114 */ 	lw	$t0,0x114($sp)
/*  f0fa308:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0fa30c:	8fc40020 */ 	lw	$a0,0x20($s8)
/*  f0fa310:	010a6021 */ 	addu	$t4,$t0,$t2
/*  f0fa314:	858b04fc */ 	lh	$t3,0x4fc($t4)
/*  f0fa318:	248efff4 */ 	addiu	$t6,$a0,-12
/*  f0fa31c:	05610003 */ 	bgez	$t3,.L0f0fa32c
/*  f0fa320:	000b6843 */ 	sra	$t5,$t3,0x1
/*  f0fa324:	25610001 */ 	addiu	$at,$t3,0x1
/*  f0fa328:	00016843 */ 	sra	$t5,$at,0x1
.L0f0fa32c:
/*  f0fa32c:	01a22821 */ 	addu	$a1,$t5,$v0
/*  f0fa330:	05c10003 */ 	bgez	$t6,.L0f0fa340
/*  f0fa334:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f0fa338:	25c10001 */ 	addiu	$at,$t6,0x1
/*  f0fa33c:	00017843 */ 	sra	$t7,$at,0x1
.L0f0fa340:
/*  f0fa340:	01e51823 */ 	subu	$v1,$t7,$a1
/*  f0fa344:	58600003 */ 	blezl	$v1,.L0f0fa354
/*  f0fa348:	8fd80028 */ 	lw	$t8,0x28($s8)
/*  f0fa34c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fa350:	8fd80028 */ 	lw	$t8,0x28($s8)
.L0f0fa354:
/*  f0fa354:	00981023 */ 	subu	$v0,$a0,$t8
/*  f0fa358:	0062082a */ 	slt	$at,$v1,$v0
/*  f0fa35c:	10200002 */ 	beqz	$at,.L0f0fa368
/*  f0fa360:	00000000 */ 	nop
/*  f0fa364:	00401825 */ 	or	$v1,$v0,$zero
.L0f0fa368:
/*  f0fa368:	10000025 */ 	b	.L0f0fa400
/*  f0fa36c:	afc30068 */ 	sw	$v1,0x68($s8)
.L0f0fa370:
/*  f0fa370:	10000023 */ 	b	.L0f0fa400
/*  f0fa374:	afc00068 */ 	sw	$zero,0x68($s8)
.L0f0fa378:
/*  f0fa378:	30590040 */ 	andi	$t9,$v0,0x40
/*  f0fa37c:	13200020 */ 	beqz	$t9,.L0f0fa400
/*  f0fa380:	8fa90124 */ 	lw	$t1,0x124($sp)
/*  f0fa384:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0fa388:	8c639fc0 */ 	lw	$v1,%lo(g_Vars)($v1)
/*  f0fa38c:	81280005 */ 	lb	$t0,0x5($t1)
/*  f0fa390:	24010014 */ 	addiu	$at,$zero,0x14
/*  f0fa394:	812b0009 */ 	lb	$t3,0x9($t1)
/*  f0fa398:	01030019 */ 	multu	$t0,$v1
/*  f0fa39c:	8fce0068 */ 	lw	$t6,0x68($s8)
/*  f0fa3a0:	00005012 */ 	mflo	$t2
/*  f0fa3a4:	00000000 */ 	nop
/*  f0fa3a8:	00000000 */ 	nop
/*  f0fa3ac:	0141001a */ 	div	$zero,$t2,$at
/*  f0fa3b0:	00006012 */ 	mflo	$t4
/*  f0fa3b4:	00000000 */ 	nop
/*  f0fa3b8:	00000000 */ 	nop
/*  f0fa3bc:	01630019 */ 	multu	$t3,$v1
/*  f0fa3c0:	00006812 */ 	mflo	$t5
/*  f0fa3c4:	018d1023 */ 	subu	$v0,$t4,$t5
/*  f0fa3c8:	01c22821 */ 	addu	$a1,$t6,$v0
/*  f0fa3cc:	18a00003 */ 	blez	$a1,.L0f0fa3dc
/*  f0fa3d0:	afc50068 */ 	sw	$a1,0x68($s8)
/*  f0fa3d4:	afc00068 */ 	sw	$zero,0x68($s8)
/*  f0fa3d8:	00002825 */ 	or	$a1,$zero,$zero
.L0f0fa3dc:
/*  f0fa3dc:	8fd80020 */ 	lw	$t8,0x20($s8)
/*  f0fa3e0:	8fd90028 */ 	lw	$t9,0x28($s8)
/*  f0fa3e4:	03191023 */ 	subu	$v0,$t8,$t9
/*  f0fa3e8:	00a2082a */ 	slt	$at,$a1,$v0
/*  f0fa3ec:	50200004 */ 	beqzl	$at,.L0f0fa400
/*  f0fa3f0:	afc50064 */ 	sw	$a1,0x64($s8)
/*  f0fa3f4:	afc20068 */ 	sw	$v0,0x68($s8)
/*  f0fa3f8:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fa3fc:	afc50064 */ 	sw	$a1,0x64($s8)
.L0f0fa400:
/*  f0fa400:	8fc50068 */ 	lw	$a1,0x68($s8)
/*  f0fa404:	8fc40064 */ 	lw	$a0,0x64($s8)
/*  f0fa408:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0fa40c:	3c0b8007 */ 	lui	$t3,%hi(g_MpPlayerNum)
/*  f0fa410:	10a40021 */ 	beq	$a1,$a0,.L0f0fa498
/*  f0fa414:	00803025 */ 	or	$a2,$a0,$zero
/*  f0fa418:	8c639fc0 */ 	lw	$v1,%lo(g_Vars)($v1)
/*  f0fa41c:	44845000 */ 	mtc1	$a0,$f10
/*  f0fa420:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fa424:	1860000e */ 	blez	$v1,.L0f0fa460
/*  f0fa428:	46805020 */ 	cvt.s.w	$f0,$f10
/*  f0fa42c:	44854000 */ 	mtc1	$a1,$f8
/*  f0fa430:	3c017f1b */ 	lui	$at,%hi(var7f1b2a60)
/*  f0fa434:	c4242a60 */ 	lwc1	$f4,%lo(var7f1b2a60)($at)
/*  f0fa438:	468044a0 */ 	cvt.s.w	$f18,$f8
/*  f0fa43c:	3c017f1b */ 	lui	$at,%hi(var7f1b2a64)
/*  f0fa440:	c42c2a64 */ 	lwc1	$f12,%lo(var7f1b2a64)($at)
/*  f0fa444:	46049082 */ 	mul.s	$f2,$f18,$f4
/*  f0fa448:	00000000 */ 	nop
.L0f0fa44c:
/*  f0fa44c:	46006182 */ 	mul.s	$f6,$f12,$f0
/*  f0fa450:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0fa454:	0043082a */ 	slt	$at,$v0,$v1
/*  f0fa458:	1420fffc */ 	bnez	$at,.L0f0fa44c
/*  f0fa45c:	46061000 */ 	add.s	$f0,$f2,$f6
.L0f0fa460:
/*  f0fa460:	4600028d */ 	trunc.w.s	$f10,$f0
/*  f0fa464:	44025000 */ 	mfc1	$v0,$f10
/*  f0fa468:	00000000 */ 	nop
/*  f0fa46c:	10a2000a */ 	beq	$a1,$v0,.L0f0fa498
/*  f0fa470:	afc20064 */ 	sw	$v0,0x64($s8)
/*  f0fa474:	14c20008 */ 	bne	$a2,$v0,.L0f0fa498
/*  f0fa478:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fa47c:	0045082a */ 	slt	$at,$v0,$a1
/*  f0fa480:	10200004 */ 	beqz	$at,.L0f0fa494
/*  f0fa484:	2489ffff */ 	addiu	$t1,$a0,-1
/*  f0fa488:	244a0001 */ 	addiu	$t2,$v0,0x1
/*  f0fa48c:	10000002 */ 	b	.L0f0fa498
/*  f0fa490:	afca0064 */ 	sw	$t2,0x64($s8)
.L0f0fa494:
/*  f0fa494:	afc90064 */ 	sw	$t1,0x64($s8)
.L0f0fa498:
/*  f0fa498:	8d6b1448 */ 	lw	$t3,%lo(g_MpPlayerNum)($t3)
/*  f0fa49c:	3c0d800a */ 	lui	$t5,%hi(g_Menus+0xe40)
/*  f0fa4a0:	3c0f8006 */ 	lui	$t7,%hi(var8005dd58)
/*  f0fa4a4:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f0fa4a8:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0fa4ac:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0fa4b0:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f0fa4b4:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f0fa4b8:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0fa4bc:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f0fa4c0:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0fa4c4:	8dadee40 */ 	lw	$t5,%lo(g_Menus+0xe40)($t5)
/*  f0fa4c8:	8fb80124 */ 	lw	$t8,0x124($sp)
/*  f0fa4cc:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f0fa4d0:	000d77c2 */ 	srl	$t6,$t5,0x1f
/*  f0fa4d4:	55c00005 */ 	bnezl	$t6,.L0f0fa4ec
/*  f0fa4d8:	a3000014 */ 	sb	$zero,0x14($t8)
/*  f0fa4dc:	8defdd58 */ 	lw	$t7,%lo(var8005dd58)($t7)
/*  f0fa4e0:	51e00019 */ 	beqzl	$t7,.L0f0fa548
/*  f0fa4e4:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0fa4e8:	a3000014 */ 	sb	$zero,0x14($t8)
.L0f0fa4ec:
/*  f0fa4ec:	a3000007 */ 	sb	$zero,0x7($t8)
/*  f0fa4f0:	a3000006 */ 	sb	$zero,0x6($t8)
/*  f0fa4f4:	a3000005 */ 	sb	$zero,0x5($t8)
/*  f0fa4f8:	a3000004 */ 	sb	$zero,0x4($t8)
/*  f0fa4fc:	a3000003 */ 	sb	$zero,0x3($t8)
/*  f0fa500:	a3000002 */ 	sb	$zero,0x2($t8)
/*  f0fa504:	a3000001 */ 	sb	$zero,0x1($t8)
/*  f0fa508:	a3000000 */ 	sb	$zero,0x0($t8)
/*  f0fa50c:	8d081448 */ 	lw	$t0,%lo(g_MpPlayerNum)($t0)
/*  f0fa510:	3c09800a */ 	lui	$t1,%hi(g_Menus)
/*  f0fa514:	2529e000 */ 	addiu	$t1,$t1,%lo(g_Menus)
/*  f0fa518:	000850c0 */ 	sll	$t2,$t0,0x3
/*  f0fa51c:	01485023 */ 	subu	$t2,$t2,$t0
/*  f0fa520:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0fa524:	01485021 */ 	addu	$t2,$t2,$t0
/*  f0fa528:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0fa52c:	01485023 */ 	subu	$t2,$t2,$t0
/*  f0fa530:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f0fa534:	01491021 */ 	addu	$v0,$t2,$t1
/*  f0fa538:	904b0e40 */ 	lbu	$t3,0xe40($v0)
/*  f0fa53c:	316cff7f */ 	andi	$t4,$t3,0xff7f
/*  f0fa540:	a04c0e40 */ 	sb	$t4,0xe40($v0)
/*  f0fa544:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f0fa548:
/*  f0fa548:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0fa54c:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f0fa550:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f0fa554:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f0fa558:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f0fa55c:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f0fa560:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f0fa564:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f0fa568:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f0fa56c:	03e00008 */ 	jr	$ra
/*  f0fa570:	27bd0120 */ 	addiu	$sp,$sp,0x120
);

GLOBAL_ASM(
glabel func0f0fa574
/*  f0fa574:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0fa578:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f0fa57c:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f0fa580:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0fa584:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f0fa588:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0fa58c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0fa590:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0fa594:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f0fa598:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0fa59c:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0fa5a0:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0fa5a4:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0fa5a8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0fa5ac:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0fa5b0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0fa5b4:	90830005 */ 	lbu	$v1,0x5($a0)
/*  f0fa5b8:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0fa5bc:	3c18800a */ 	lui	$t8,%hi(g_Menus)
/*  f0fa5c0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0fa5c4:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0fa5c8:	2718e000 */ 	addiu	$t8,$t8,%lo(g_Menus)
/*  f0fa5cc:	0080a825 */ 	or	$s5,$a0,$zero
/*  f0fa5d0:	01f89021 */ 	addu	$s2,$t7,$t8
/*  f0fa5d4:	1860002a */ 	blez	$v1,.L0f0fa680
/*  f0fa5d8:	0000b025 */ 	or	$s6,$zero,$zero
/*  f0fa5dc:	2417000a */ 	addiu	$s7,$zero,0xa
/*  f0fa5e0:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f0fa5e4:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f0fa5e8:	92b90004 */ 	lbu	$t9,0x4($s5)
.L0f0fa5ec:
/*  f0fa5ec:	00008025 */ 	or	$s0,$zero,$zero
/*  f0fa5f0:	03361021 */ 	addu	$v0,$t9,$s6
/*  f0fa5f4:	00570019 */ 	multu	$v0,$s7
/*  f0fa5f8:	00004012 */ 	mflo	$t0
/*  f0fa5fc:	02488821 */ 	addu	$s1,$s2,$t0
/*  f0fa600:	92290668 */ 	lbu	$t1,0x668($s1)
/*  f0fa604:	5920001b */ 	blezl	$t1,.L0f0fa674
/*  f0fa608:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f0fa60c:	962a0666 */ 	lhu	$t2,0x666($s1)
.L0f0fa610:
/*  f0fa610:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f0fa614:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fa618:	01501821 */ 	addu	$v1,$t2,$s0
/*  f0fa61c:	00035880 */ 	sll	$t3,$v1,0x2
/*  f0fa620:	024b1021 */ 	addu	$v0,$s2,$t3
/*  f0fa624:	904c04fe */ 	lbu	$t4,0x4fe($v0)
/*  f0fa628:	804404ff */ 	lb	$a0,0x4ff($v0)
/*  f0fa62c:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*  f0fa630:	01930019 */ 	multu	$t4,$s3
/*  f0fa634:	0004c080 */ 	sll	$t8,$a0,0x2
/*  f0fa638:	00006812 */ 	mflo	$t5
/*  f0fa63c:	01af3021 */ 	addu	$a2,$t5,$t7
/*  f0fa640:	12840003 */ 	beq	$s4,$a0,.L0f0fa650
/*  f0fa644:	00000000 */ 	nop
/*  f0fa648:	02582821 */ 	addu	$a1,$s2,$t8
/*  f0fa64c:	24a506dc */ 	addiu	$a1,$a1,0x6dc
.L0f0fa650:
/*  f0fa650:	0fc3c218 */ 	jal	func0f0f0860
/*  f0fa654:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0fa658:	92390668 */ 	lbu	$t9,0x668($s1)
/*  f0fa65c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0fa660:	0219082a */ 	slt	$at,$s0,$t9
/*  f0fa664:	5420ffea */ 	bnezl	$at,.L0f0fa610
/*  f0fa668:	962a0666 */ 	lhu	$t2,0x666($s1)
/*  f0fa66c:	92a30005 */ 	lbu	$v1,0x5($s5)
/*  f0fa670:	26d60001 */ 	addiu	$s6,$s6,0x1
.L0f0fa674:
/*  f0fa674:	02c3082a */ 	slt	$at,$s6,$v1
/*  f0fa678:	5420ffdc */ 	bnezl	$at,.L0f0fa5ec
/*  f0fa67c:	92b90004 */ 	lbu	$t9,0x4($s5)
.L0f0fa680:
/*  f0fa680:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0fa684:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0fa688:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0fa68c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0fa690:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0fa694:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0fa698:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0fa69c:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f0fa6a0:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f0fa6a4:	03e00008 */ 	jr	$ra
/*  f0fa6a8:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

void func0f0fa6ac(void)
{
	switch (g_MenuData.root) {
	case MENUROOT_MAINMENU:
	case MENUROOT_MPSETUP:
	case MENUROOT_FILESELECT:
	case MENUROOT_4MBMAINMENU:
	case MENUROOT_TRAINING:
		func0f0baf38();
		g_PlayersWithControl[0] = true;
	}
}

GLOBAL_ASM(
glabel func0f0fa704
.late_rodata
glabel var7f1b2a98
.word func0f0fa704+0xd10 # f0fb414
glabel var7f1b2a9c
.word func0f0fa704+0xd10 # f0fb414
glabel var7f1b2aa0
.word func0f0fa704+0xc38 # f0fb33c
glabel var7f1b2aa4
.word func0f0fa704+0xcc0 # f0fb3c4
glabel var7f1b2aa8
.word func0f0fa704+0xd10 # f0fb414
glabel var7f1b2aac
.word func0f0fa704+0xd54 # f0fb458
glabel var7f1b2ab0
.word func0f0fa704+0xd54 # f0fb458
glabel var7f1b2ab4
.word func0f0fa704+0xd54 # f0fb458
glabel var7f1b2ab8
.word func0f0fa704+0xd54 # f0fb458
glabel var7f1b2abc
.word func0f0fa704+0xd54 # f0fb458
glabel var7f1b2ac0
.word func0f0fa704+0xc38 # f0fb33c
glabel var7f1b2ac4
.word func0f0fa704+0xd54 # f0fb458
glabel var7f1b2ac8
.word func0f0fa704+0xd10 # f0fb414
.text
/*  f0fa704:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f0fa708:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0fa70c:	3c178007 */ 	lui	$s7,%hi(g_MpPlayerNum)
/*  f0fa710:	26f71448 */ 	addiu	$s7,$s7,%lo(g_MpPlayerNum)
/*  f0fa714:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f0fa718:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0fa71c:	241e0e70 */ 	addiu	$s8,$zero,0xe70
/*  f0fa720:	01de0019 */ 	multu	$t6,$s8
/*  f0fa724:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0fa728:	3c16800a */ 	lui	$s6,%hi(g_Menus)
/*  f0fa72c:	26d6e000 */ 	addiu	$s6,$s6,%lo(g_Menus)
/*  f0fa730:	3c19800a */ 	lui	$t9,%hi(g_MenuData+0x4)
/*  f0fa734:	8f3919c4 */ 	lw	$t9,%lo(g_MenuData+0x4)($t9)
/*  f0fa738:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0fa73c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0fa740:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0fa744:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0fa748:	00007812 */ 	mflo	$t7
/*  f0fa74c:	02cf3821 */ 	addu	$a3,$s6,$t7
/*  f0fa750:	8cf804f8 */ 	lw	$t8,0x4f8($a3)
/*  f0fa754:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0fa758:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0fa75c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0fa760:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0fa764:	00006025 */ 	or	$t4,$zero,$zero
/*  f0fa768:	00004825 */ 	or	$t1,$zero,$zero
/*  f0fa76c:	00004025 */ 	or	$t0,$zero,$zero
/*  f0fa770:	0000a825 */ 	or	$s5,$zero,$zero
/*  f0fa774:	afa0011c */ 	sw	$zero,0x11c($sp)
/*  f0fa778:	afa700fc */ 	sw	$a3,0xfc($sp)
/*  f0fa77c:	17210005 */ 	bne	$t9,$at,.L0f0fa794
/*  f0fa780:	afb80100 */ 	sw	$t8,0x100($sp)
/*  f0fa784:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x28c)
/*  f0fa788:	8dcea24c */ 	lw	$t6,%lo(g_Vars+0x28c)($t6)
/*  f0fa78c:	3c01800a */ 	lui	$at,%hi(g_ActiveMenuIndex)
/*  f0fa790:	ac2e21b8 */ 	sw	$t6,%lo(g_ActiveMenuIndex)($at)
.L0f0fa794:
/*  f0fa794:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0fa798:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0fa79c:	0fc3c506 */ 	jal	func0f0f1418
/*  f0fa7a0:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0fa7a4:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f0fa7a8:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0fa7ac:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0fa7b0:	01fe0019 */ 	multu	$t7,$s8
/*  f0fa7b4:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0fa7b8:	a3a00106 */ 	sb	$zero,0x106($sp)
/*  f0fa7bc:	a3a00107 */ 	sb	$zero,0x107($sp)
/*  f0fa7c0:	a3a0010a */ 	sb	$zero,0x10a($sp)
/*  f0fa7c4:	a3a0010b */ 	sb	$zero,0x10b($sp)
/*  f0fa7c8:	00005025 */ 	or	$t2,$zero,$zero
/*  f0fa7cc:	00005825 */ 	or	$t3,$zero,$zero
/*  f0fa7d0:	3c0f800a */ 	lui	$t7,%hi(g_MenuData+0x4)
/*  f0fa7d4:	0000c012 */ 	mflo	$t8
/*  f0fa7d8:	02d8c821 */ 	addu	$t9,$s6,$t8
/*  f0fa7dc:	8f2e04f8 */ 	lw	$t6,0x4f8($t9)
/*  f0fa7e0:	51c0031e */ 	beqzl	$t6,.L0f0fb45c
/*  f0fa7e4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fa7e8:	8def19c4 */ 	lw	$t7,%lo(g_MenuData+0x4)($t7)
/*  f0fa7ec:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0fa7f0:	afa000f8 */ 	sw	$zero,0xf8($sp)
/*  f0fa7f4:	15e1000b */ 	bne	$t7,$at,.L0f0fa824
/*  f0fa7f8:	afa000ec */ 	sw	$zero,0xec($sp)
/*  f0fa7fc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0fa800:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f0fa804:	240e0003 */ 	addiu	$t6,$zero,0x3
/*  f0fa808:	240f0004 */ 	addiu	$t7,$zero,0x4
/*  f0fa80c:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f0fa810:	afb800dc */ 	sw	$t8,0xdc($sp)
/*  f0fa814:	afb900e0 */ 	sw	$t9,0xe0($sp)
/*  f0fa818:	afae00e4 */ 	sw	$t6,0xe4($sp)
/*  f0fa81c:	1000001b */ 	b	.L0f0fa88c
/*  f0fa820:	afaf00ec */ 	sw	$t7,0xec($sp)
.L0f0fa824:
/*  f0fa824:	27a400d7 */ 	addiu	$a0,$sp,0xd7
/*  f0fa828:	27a500d6 */ 	addiu	$a1,$sp,0xd6
/*  f0fa82c:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0fa830:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0fa834:	afaa00f4 */ 	sw	$t2,0xf4($sp)
/*  f0fa838:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f0fa83c:	0fc3dd2a */ 	jal	func0f0f74a8
/*  f0fa840:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0fa844:	83a200d7 */ 	lb	$v0,0xd7($sp)
/*  f0fa848:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0fa84c:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0fa850:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*  f0fa854:	8fab00f0 */ 	lw	$t3,0xf0($sp)
/*  f0fa858:	04400004 */ 	bltz	$v0,.L0f0fa86c
/*  f0fa85c:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0fa860:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0fa864:	afa200d8 */ 	sw	$v0,0xd8($sp)
/*  f0fa868:	afa300ec */ 	sw	$v1,0xec($sp)
.L0f0fa86c:
/*  f0fa86c:	83a200d6 */ 	lb	$v0,0xd6($sp)
/*  f0fa870:	8fa300ec */ 	lw	$v1,0xec($sp)
/*  f0fa874:	04400005 */ 	bltz	$v0,.L0f0fa88c
/*  f0fa878:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f0fa87c:	03b8c821 */ 	addu	$t9,$sp,$t8
/*  f0fa880:	af2200d8 */ 	sw	$v0,0xd8($t9)
/*  f0fa884:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0fa888:	afa300ec */ 	sw	$v1,0xec($sp)
.L0f0fa88c:
/*  f0fa88c:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f0fa890:	01de0019 */ 	multu	$t6,$s8
/*  f0fa894:	00007812 */ 	mflo	$t7
/*  f0fa898:	02cf3821 */ 	addu	$a3,$s6,$t7
/*  f0fa89c:	90e20e41 */ 	lbu	$v0,0xe41($a3)
/*  f0fa8a0:	1840001a */ 	blez	$v0,.L0f0fa90c
/*  f0fa8a4:	2458ffff */ 	addiu	$t8,$v0,-1
/*  f0fa8a8:	331900ff */ 	andi	$t9,$t8,0xff
/*  f0fa8ac:	17200014 */ 	bnez	$t9,.L0f0fa900
/*  f0fa8b0:	a0f80e41 */ 	sb	$t8,0xe41($a3)
/*  f0fa8b4:	8cee0e48 */ 	lw	$t6,0xe48($a3)
/*  f0fa8b8:	8cef0e4c */ 	lw	$t7,0xe4c($a3)
/*  f0fa8bc:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0fa8c0:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0fa8c4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fa8c8:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0fa8cc:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0fa8d0:	afaa00f4 */ 	sw	$t2,0xf4($sp)
/*  f0fa8d4:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f0fa8d8:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0fa8dc:	afae00cc */ 	sw	$t6,0xcc($sp)
/*  f0fa8e0:	0fc42539 */ 	jal	func0f1094e4
/*  f0fa8e4:	a7af00d0 */ 	sh	$t7,0xd0($sp)
/*  f0fa8e8:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0fa8ec:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0fa8f0:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*  f0fa8f4:	8fab00f0 */ 	lw	$t3,0xf0($sp)
/*  f0fa8f8:	10000004 */ 	b	.L0f0fa90c
/*  f0fa8fc:	8fac012c */ 	lw	$t4,0x12c($sp)
.L0f0fa900:
/*  f0fa900:	90f90e40 */ 	lbu	$t9,0xe40($a3)
/*  f0fa904:	372e0080 */ 	ori	$t6,$t9,0x80
/*  f0fa908:	a0ee0e40 */ 	sb	$t6,0xe40($a3)
.L0f0fa90c:
/*  f0fa90c:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f0fa910:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0fa914:	19e00083 */ 	blez	$t7,.L0f0fab24
/*  f0fa918:	27b300d8 */ 	addiu	$s3,$sp,0xd8
.L0f0fa91c:
/*  f0fa91c:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0fa920:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f0fa924:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f0fa928:	afaa00f4 */ 	sw	$t2,0xf4($sp)
/*  f0fa92c:	afa90128 */ 	sw	$t1,0x128($sp)
/*  f0fa930:	0c005384 */ 	jal	func00014e10
/*  f0fa934:	afa80124 */ 	sw	$t0,0x124($sp)
/*  f0fa938:	00028600 */ 	sll	$s0,$v0,0x18
/*  f0fa93c:	0010c603 */ 	sra	$t8,$s0,0x18
/*  f0fa940:	03008025 */ 	or	$s0,$t8,$zero
/*  f0fa944:	0c0053ae */ 	jal	func00014eb8
/*  f0fa948:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0fa94c:	00028e00 */ 	sll	$s1,$v0,0x18
/*  f0fa950:	0011ce03 */ 	sra	$t9,$s1,0x18
/*  f0fa954:	03208825 */ 	or	$s1,$t9,$zero
/*  f0fa958:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0fa95c:	0c0053d8 */ 	jal	func00014f60
/*  f0fa960:	3405ffff */ 	dli	$a1,0xffff
/*  f0fa964:	3052ffff */ 	andi	$s2,$v0,0xffff
/*  f0fa968:	82640003 */ 	lb	$a0,0x3($s3)
/*  f0fa96c:	0c005408 */ 	jal	func00015020
/*  f0fa970:	3405ffff */ 	dli	$a1,0xffff
/*  f0fa974:	304e8000 */ 	andi	$t6,$v0,0x8000
/*  f0fa978:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f0fa97c:	8fa90128 */ 	lw	$t1,0x128($sp)
/*  f0fa980:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*  f0fa984:	8fab00f0 */ 	lw	$t3,0xf0($sp)
/*  f0fa988:	8fac012c */ 	lw	$t4,0x12c($sp)
/*  f0fa98c:	11c00003 */ 	beqz	$t6,.L0f0fa99c
/*  f0fa990:	00403025 */ 	or	$a2,$v0,$zero
/*  f0fa994:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fa998:	a3af0106 */ 	sb	$t7,0x106($sp)
.L0f0fa99c:
/*  f0fa99c:	30d84000 */ 	andi	$t8,$a2,0x4000
/*  f0fa9a0:	13000003 */ 	beqz	$t8,.L0f0fa9b0
/*  f0fa9a4:	30ce2000 */ 	andi	$t6,$a2,0x2000
/*  f0fa9a8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0fa9ac:	a3b90107 */ 	sb	$t9,0x107($sp)
.L0f0fa9b0:
/*  f0fa9b0:	11c00003 */ 	beqz	$t6,.L0f0fa9c0
/*  f0fa9b4:	30d81000 */ 	andi	$t8,$a2,0x1000
/*  f0fa9b8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fa9bc:	a3af0106 */ 	sb	$t7,0x106($sp)
.L0f0fa9c0:
/*  f0fa9c0:	13000003 */ 	beqz	$t8,.L0f0fa9d0
/*  f0fa9c4:	324e0010 */ 	andi	$t6,$s2,0x10
/*  f0fa9c8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0fa9cc:	afb900f8 */ 	sw	$t9,0xf8($sp)
.L0f0fa9d0:
/*  f0fa9d0:	11c00003 */ 	beqz	$t6,.L0f0fa9e0
/*  f0fa9d4:	02402825 */ 	or	$a1,$s2,$zero
/*  f0fa9d8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fa9dc:	a3af010a */ 	sb	$t7,0x10a($sp)
.L0f0fa9e0:
/*  f0fa9e0:	30b80020 */ 	andi	$t8,$a1,0x20
/*  f0fa9e4:	13000003 */ 	beqz	$t8,.L0f0fa9f4
/*  f0fa9e8:	30ae0008 */ 	andi	$t6,$a1,0x8
/*  f0fa9ec:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0fa9f0:	a3b9010a */ 	sb	$t9,0x10a($sp)
.L0f0fa9f4:
/*  f0fa9f4:	05410003 */ 	bgez	$t2,.L0f0faa04
/*  f0fa9f8:	30cf0008 */ 	andi	$t7,$a2,0x8
/*  f0fa9fc:	10000002 */ 	b	.L0f0faa08
/*  f0faa00:	000a2023 */ 	negu	$a0,$t2
.L0f0faa04:
/*  f0faa04:	01402025 */ 	or	$a0,$t2,$zero
.L0f0faa08:
/*  f0faa08:	06010003 */ 	bgez	$s0,.L0f0faa18
/*  f0faa0c:	30b80004 */ 	andi	$t8,$a1,0x4
/*  f0faa10:	10000002 */ 	b	.L0f0faa1c
/*  f0faa14:	00101823 */ 	negu	$v1,$s0
.L0f0faa18:
/*  f0faa18:	02001825 */ 	or	$v1,$s0,$zero
.L0f0faa1c:
/*  f0faa1c:	0083082a */ 	slt	$at,$a0,$v1
/*  f0faa20:	10200002 */ 	beqz	$at,.L0f0faa2c
/*  f0faa24:	30d90004 */ 	andi	$t9,$a2,0x4
/*  f0faa28:	02005025 */ 	or	$t2,$s0,$zero
.L0f0faa2c:
/*  f0faa2c:	05610003 */ 	bgez	$t3,.L0f0faa3c
/*  f0faa30:	01602025 */ 	or	$a0,$t3,$zero
/*  f0faa34:	10000001 */ 	b	.L0f0faa3c
/*  f0faa38:	000b2023 */ 	negu	$a0,$t3
.L0f0faa3c:
/*  f0faa3c:	06210003 */ 	bgez	$s1,.L0f0faa4c
/*  f0faa40:	02201825 */ 	or	$v1,$s1,$zero
/*  f0faa44:	10000001 */ 	b	.L0f0faa4c
/*  f0faa48:	00111823 */ 	negu	$v1,$s1
.L0f0faa4c:
/*  f0faa4c:	0083082a */ 	slt	$at,$a0,$v1
/*  f0faa50:	10200002 */ 	beqz	$at,.L0f0faa5c
/*  f0faa54:	00000000 */ 	nop
/*  f0faa58:	02205825 */ 	or	$t3,$s1,$zero
.L0f0faa5c:
/*  f0faa5c:	11c00002 */ 	beqz	$t6,.L0f0faa68
/*  f0faa60:	00000000 */ 	nop
/*  f0faa64:	240cffff */ 	addiu	$t4,$zero,-1
.L0f0faa68:
/*  f0faa68:	11e00002 */ 	beqz	$t7,.L0f0faa74
/*  f0faa6c:	30ae0002 */ 	andi	$t6,$a1,0x2
/*  f0faa70:	2408ffff */ 	addiu	$t0,$zero,-1
.L0f0faa74:
/*  f0faa74:	13000002 */ 	beqz	$t8,.L0f0faa80
/*  f0faa78:	30cf0002 */ 	andi	$t7,$a2,0x2
/*  f0faa7c:	240c0001 */ 	addiu	$t4,$zero,0x1
.L0f0faa80:
/*  f0faa80:	13200002 */ 	beqz	$t9,.L0f0faa8c
/*  f0faa84:	30b80001 */ 	andi	$t8,$a1,0x1
/*  f0faa88:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f0faa8c:
/*  f0faa8c:	11c00002 */ 	beqz	$t6,.L0f0faa98
/*  f0faa90:	30d90001 */ 	andi	$t9,$a2,0x1
/*  f0faa94:	2409ffff */ 	addiu	$t1,$zero,-1
.L0f0faa98:
/*  f0faa98:	11e00002 */ 	beqz	$t7,.L0f0faaa4
/*  f0faa9c:	30ae0800 */ 	andi	$t6,$a1,0x800
/*  f0faaa0:	2415ffff */ 	addiu	$s5,$zero,-1
.L0f0faaa4:
/*  f0faaa4:	13000002 */ 	beqz	$t8,.L0f0faab0
/*  f0faaa8:	30cf0800 */ 	andi	$t7,$a2,0x800
/*  f0faaac:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f0faab0:
/*  f0faab0:	13200002 */ 	beqz	$t9,.L0f0faabc
/*  f0faab4:	30b80400 */ 	andi	$t8,$a1,0x400
/*  f0faab8:	24150001 */ 	addiu	$s5,$zero,0x1
.L0f0faabc:
/*  f0faabc:	11c00002 */ 	beqz	$t6,.L0f0faac8
/*  f0faac0:	30d90400 */ 	andi	$t9,$a2,0x400
/*  f0faac4:	240cffff */ 	addiu	$t4,$zero,-1
.L0f0faac8:
/*  f0faac8:	11e00002 */ 	beqz	$t7,.L0f0faad4
/*  f0faacc:	30ae0200 */ 	andi	$t6,$a1,0x200
/*  f0faad0:	2408ffff */ 	addiu	$t0,$zero,-1
.L0f0faad4:
/*  f0faad4:	13000002 */ 	beqz	$t8,.L0f0faae0
/*  f0faad8:	30cf0200 */ 	andi	$t7,$a2,0x200
/*  f0faadc:	240c0001 */ 	addiu	$t4,$zero,0x1
.L0f0faae0:
/*  f0faae0:	13200002 */ 	beqz	$t9,.L0f0faaec
/*  f0faae4:	30b80100 */ 	andi	$t8,$a1,0x100
/*  f0faae8:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f0faaec:
/*  f0faaec:	11c00002 */ 	beqz	$t6,.L0f0faaf8
/*  f0faaf0:	30d90100 */ 	andi	$t9,$a2,0x100
/*  f0faaf4:	2409ffff */ 	addiu	$t1,$zero,-1
.L0f0faaf8:
/*  f0faaf8:	11e00002 */ 	beqz	$t7,.L0f0fab04
/*  f0faafc:	8fae00ec */ 	lw	$t6,0xec($sp)
/*  f0fab00:	2415ffff */ 	addiu	$s5,$zero,-1
.L0f0fab04:
/*  f0fab04:	13000002 */ 	beqz	$t8,.L0f0fab10
/*  f0fab08:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0fab0c:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f0fab10:
/*  f0fab10:	13200002 */ 	beqz	$t9,.L0f0fab1c
/*  f0fab14:	00000000 */ 	nop
/*  f0fab18:	24150001 */ 	addiu	$s5,$zero,0x1
.L0f0fab1c:
/*  f0fab1c:	168eff7f */ 	bne	$s4,$t6,.L0f0fa91c
/*  f0fab20:	26730004 */ 	addiu	$s3,$s3,0x4
.L0f0fab24:
/*  f0fab24:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f0fab28:	93ae0106 */ 	lbu	$t6,0x106($sp)
/*  f0fab2c:	2410000a */ 	addiu	$s0,$zero,0xa
/*  f0fab30:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0fab34:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0fab38:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0fab3c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0fab40:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0fab44:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0fab48:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0fab4c:	02d8c821 */ 	addu	$t9,$s6,$t8
/*  f0fab50:	11c00002 */ 	beqz	$t6,.L0f0fab5c
/*  f0fab54:	8f2404f8 */ 	lw	$a0,0x4f8($t9)
/*  f0fab58:	a3a00107 */ 	sb	$zero,0x107($sp)
.L0f0fab5c:
/*  f0fab5c:	11000002 */ 	beqz	$t0,.L0f0fab68
/*  f0fab60:	2406001e */ 	addiu	$a2,$zero,0x1e
/*  f0fab64:	01006025 */ 	or	$t4,$t0,$zero
.L0f0fab68:
/*  f0fab68:	12a00002 */ 	beqz	$s5,.L0f0fab74
/*  f0fab6c:	2413003c */ 	addiu	$s3,$zero,0x3c
/*  f0fab70:	02a04825 */ 	or	$t1,$s5,$zero
.L0f0fab74:
/*  f0fab74:	24110021 */ 	addiu	$s1,$zero,0x21
/*  f0fab78:	2414002c */ 	addiu	$s4,$zero,0x2c
/*  f0fab7c:	10800019 */ 	beqz	$a0,.L0f0fabe4
/*  f0fab80:	00009025 */ 	or	$s2,$zero,$zero
/*  f0fab84:	8c820008 */ 	lw	$v0,0x8($a0)
/*  f0fab88:	10400016 */ 	beqz	$v0,.L0f0fabe4
/*  f0fab8c:	00000000 */ 	nop
/*  f0fab90:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f0fab94:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0fab98:	10610003 */ 	beq	$v1,$at,.L0f0faba8
/*  f0fab9c:	24010010 */ 	addiu	$at,$zero,0x10
/*  f0faba0:	54610009 */ 	bnel	$v1,$at,.L0f0fabc8
/*  f0faba4:	2401000d */ 	addiu	$at,$zero,0xd
.L0f0faba8:
/*  f0faba8:	8c8f000c */ 	lw	$t7,0xc($a0)
/*  f0fabac:	51e00006 */ 	beqzl	$t7,.L0f0fabc8
/*  f0fabb0:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0fabb4:	24100005 */ 	addiu	$s0,$zero,0x5
/*  f0fabb8:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f0fabbc:	2413001e */ 	addiu	$s3,$zero,0x1e
/*  f0fabc0:	2411000a */ 	addiu	$s1,$zero,0xa
/*  f0fabc4:	2401000d */ 	addiu	$at,$zero,0xd
.L0f0fabc8:
/*  f0fabc8:	14610006 */ 	bne	$v1,$at,.L0f0fabe4
/*  f0fabcc:	00000000 */ 	nop
/*  f0fabd0:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0fabd4:	24100005 */ 	addiu	$s0,$zero,0x5
/*  f0fabd8:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f0fabdc:	2411000a */ 	addiu	$s1,$zero,0xa
/*  f0fabe0:	2414000a */ 	addiu	$s4,$zero,0xa
.L0f0fabe4:
/*  f0fabe4:	15200004 */ 	bnez	$t1,.L0f0fabf8
/*  f0fabe8:	0000f825 */ 	or	$ra,$zero,$zero
/*  f0fabec:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fabf0:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0fabf4:	a478082c */ 	sh	$t8,0x82c($v1)
.L0f0fabf8:
/*  f0fabf8:	12a00006 */ 	beqz	$s5,.L0f0fac14
/*  f0fabfc:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fac00:	a460082c */ 	sh	$zero,0x82c($v1)
/*  f0fac04:	ac600824 */ 	sw	$zero,0x824($v1)
/*  f0fac08:	a475082a */ 	sh	$s5,0x82a($v1)
/*  f0fac0c:	10000004 */ 	b	.L0f0fac20
/*  f0fac10:	241f0001 */ 	addiu	$ra,$zero,0x1
.L0f0fac14:
/*  f0fac14:	51200003 */ 	beqzl	$t1,.L0f0fac24
/*  f0fac18:	8c620824 */ 	lw	$v0,0x824($v1)
/*  f0fac1c:	8469082a */ 	lh	$t1,0x82a($v1)
.L0f0fac20:
/*  f0fac20:	8c620824 */ 	lw	$v0,0x824($v1)
.L0f0fac24:
/*  f0fac24:	3c0e800a */ 	lui	$t6,%hi(g_Vars)
/*  f0fac28:	2841003d */ 	slti	$at,$v0,0x3d
/*  f0fac2c:	14200004 */ 	bnez	$at,.L0f0fac40
/*  f0fac30:	00000000 */ 	nop
/*  f0fac34:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0fac38:	a479082c */ 	sh	$t9,0x82c($v1)
/*  f0fac3c:	8c620824 */ 	lw	$v0,0x824($v1)
.L0f0fac40:
/*  f0fac40:	0050001a */ 	div	$zero,$v0,$s0
/*  f0fac44:	8dce9fc0 */ 	lw	$t6,%lo(g_Vars)($t6)
/*  f0fac48:	00003812 */ 	mflo	$a3
/*  f0fac4c:	8478082c */ 	lh	$t8,0x82c($v1)
/*  f0fac50:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f0fac54:	01f0001a */ 	div	$zero,$t7,$s0
/*  f0fac58:	16000002 */ 	bnez	$s0,.L0f0fac64
/*  f0fac5c:	00000000 */ 	nop
/*  f0fac60:	0007000d */ 	break	0x7
.L0f0fac64:
/*  f0fac64:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fac68:	16010004 */ 	bne	$s0,$at,.L0f0fac7c
/*  f0fac6c:	3c018000 */ 	lui	$at,0x8000
/*  f0fac70:	14410002 */ 	bne	$v0,$at,.L0f0fac7c
/*  f0fac74:	00000000 */ 	nop
/*  f0fac78:	0006000d */ 	break	0x6
.L0f0fac7c:
/*  f0fac7c:	00006812 */ 	mflo	$t5
/*  f0fac80:	16000002 */ 	bnez	$s0,.L0f0fac8c
/*  f0fac84:	00000000 */ 	nop
/*  f0fac88:	0007000d */ 	break	0x7
.L0f0fac8c:
/*  f0fac8c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fac90:	16010004 */ 	bne	$s0,$at,.L0f0faca4
/*  f0fac94:	3c018000 */ 	lui	$at,0x8000
/*  f0fac98:	15e10002 */ 	bne	$t7,$at,.L0f0faca4
/*  f0fac9c:	00000000 */ 	nop
/*  f0faca0:	0006000d */ 	break	0x6
.L0f0faca4:
/*  f0faca4:	1700000b */ 	bnez	$t8,.L0f0facd4
/*  f0faca8:	00000000 */ 	nop
/*  f0facac:	04e10003 */ 	bgez	$a3,.L0f0facbc
/*  f0facb0:	0007c843 */ 	sra	$t9,$a3,0x1
/*  f0facb4:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f0facb8:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0facbc:
/*  f0facbc:	03203825 */ 	or	$a3,$t9,$zero
/*  f0facc0:	05a10003 */ 	bgez	$t5,.L0f0facd0
/*  f0facc4:	000d7043 */ 	sra	$t6,$t5,0x1
/*  f0facc8:	25a10001 */ 	addiu	$at,$t5,0x1
/*  f0faccc:	00017043 */ 	sra	$t6,$at,0x1
.L0f0facd0:
/*  f0facd0:	01c06825 */ 	or	$t5,$t6,$zero
.L0f0facd4:
/*  f0facd4:	05410003 */ 	bgez	$t2,.L0f0face4
/*  f0facd8:	a3a9010c */ 	sb	$t1,0x10c($sp)
/*  f0facdc:	10000002 */ 	b	.L0f0face8
/*  f0face0:	000a1023 */ 	negu	$v0,$t2
.L0f0face4:
/*  f0face4:	01401025 */ 	or	$v0,$t2,$zero
.L0f0face8:
/*  f0face8:	05610003 */ 	bgez	$t3,.L0f0facf8
/*  f0facec:	0046082a */ 	slt	$at,$v0,$a2
/*  f0facf0:	10000002 */ 	b	.L0f0facfc
/*  f0facf4:	000b1823 */ 	negu	$v1,$t3
.L0f0facf8:
/*  f0facf8:	01601825 */ 	or	$v1,$t3,$zero
.L0f0facfc:
/*  f0facfc:	14200065 */ 	bnez	$at,.L0f0fae94
/*  f0fad00:	0062082a */ 	slt	$at,$v1,$v0
/*  f0fad04:	14200003 */ 	bnez	$at,.L0f0fad14
/*  f0fad08:	00000000 */ 	nop
/*  f0fad0c:	52400062 */ 	beqzl	$s2,.L0f0fae98
/*  f0fad10:	8fb800fc */ 	lw	$t8,0xfc($sp)
.L0f0fad14:
/*  f0fad14:	05410006 */ 	bgez	$t2,.L0f0fad30
/*  f0fad18:	28410047 */ 	slti	$at,$v0,0x47
/*  f0fad1c:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fad20:	846f0828 */ 	lh	$t7,0x828($v1)
/*  f0fad24:	59e00003 */ 	blezl	$t7,.L0f0fad34
/*  f0fad28:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fad2c:	a4600828 */ 	sh	$zero,0x828($v1)
.L0f0fad30:
/*  f0fad30:	8fa300fc */ 	lw	$v1,0xfc($sp)
.L0f0fad34:
/*  f0fad34:	19400005 */ 	blez	$t2,.L0f0fad4c
/*  f0fad38:	84640828 */ 	lh	$a0,0x828($v1)
/*  f0fad3c:	04810003 */ 	bgez	$a0,.L0f0fad4c
/*  f0fad40:	00000000 */ 	nop
/*  f0fad44:	a4600828 */ 	sh	$zero,0x828($v1)
/*  f0fad48:	84640828 */ 	lh	$a0,0x828($v1)
.L0f0fad4c:
/*  f0fad4c:	14800003 */ 	bnez	$a0,.L0f0fad5c
/*  f0fad50:	00000000 */ 	nop
/*  f0fad54:	ac600824 */ 	sw	$zero,0x824($v1)
/*  f0fad58:	84640828 */ 	lh	$a0,0x828($v1)
.L0f0fad5c:
/*  f0fad5c:	54200003 */ 	bnezl	$at,.L0f0fad6c
/*  f0fad60:	00461023 */ 	subu	$v0,$v0,$a2
/*  f0fad64:	24020046 */ 	addiu	$v0,$zero,0x46
/*  f0fad68:	00461023 */ 	subu	$v0,$v0,$a2
.L0f0fad6c:
/*  f0fad6c:	02220019 */ 	multu	$s1,$v0
/*  f0fad70:	24190046 */ 	addiu	$t9,$zero,0x46
/*  f0fad74:	03267023 */ 	subu	$t6,$t9,$a2
/*  f0fad78:	0000c012 */ 	mflo	$t8
/*  f0fad7c:	00000000 */ 	nop
/*  f0fad80:	00000000 */ 	nop
/*  f0fad84:	030e001a */ 	div	$zero,$t8,$t6
/*  f0fad88:	15c00002 */ 	bnez	$t6,.L0f0fad94
/*  f0fad8c:	00000000 */ 	nop
/*  f0fad90:	0007000d */ 	break	0x7
.L0f0fad94:
/*  f0fad94:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fad98:	15c10004 */ 	bne	$t6,$at,.L0f0fadac
/*  f0fad9c:	3c018000 */ 	lui	$at,0x8000
/*  f0fada0:	17010002 */ 	bne	$t8,$at,.L0f0fadac
/*  f0fada4:	00000000 */ 	nop
/*  f0fada8:	0006000d */ 	break	0x6
.L0f0fadac:
/*  f0fadac:	00007812 */ 	mflo	$t7
/*  f0fadb0:	026f2823 */ 	subu	$a1,$s3,$t7
/*  f0fadb4:	28810003 */ 	slti	$at,$a0,0x3
/*  f0fadb8:	10200004 */ 	beqz	$at,.L0f0fadcc
/*  f0fadbc:	00a01825 */ 	or	$v1,$a1,$zero
/*  f0fadc0:	2881fffe */ 	slti	$at,$a0,-2
/*  f0fadc4:	10200005 */ 	beqz	$at,.L0f0faddc
/*  f0fadc8:	00000000 */ 	nop
.L0f0fadcc:
/*  f0fadcc:	04a10003 */ 	bgez	$a1,.L0f0faddc
/*  f0fadd0:	00051843 */ 	sra	$v1,$a1,0x1
/*  f0fadd4:	24a10001 */ 	addiu	$at,$a1,0x1
/*  f0fadd8:	00011843 */ 	sra	$v1,$at,0x1
.L0f0faddc:
/*  f0faddc:	1860002f */ 	blez	$v1,.L0f0fae9c
/*  f0fade0:	00000000 */ 	nop
/*  f0fade4:	8fb900fc */ 	lw	$t9,0xfc($sp)
/*  f0fade8:	3c18800a */ 	lui	$t8,%hi(g_Vars)
/*  f0fadec:	8f189fc0 */ 	lw	$t8,%lo(g_Vars)($t8)
/*  f0fadf0:	8f220824 */ 	lw	$v0,0x824($t9)
/*  f0fadf4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0fadf8:	0043001a */ 	div	$zero,$v0,$v1
/*  f0fadfc:	00587021 */ 	addu	$t6,$v0,$t8
/*  f0fae00:	00003812 */ 	mflo	$a3
/*  f0fae04:	14600002 */ 	bnez	$v1,.L0f0fae10
/*  f0fae08:	00000000 */ 	nop
/*  f0fae0c:	0007000d */ 	break	0x7
.L0f0fae10:
/*  f0fae10:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fae14:	14610004 */ 	bne	$v1,$at,.L0f0fae28
/*  f0fae18:	3c018000 */ 	lui	$at,0x8000
/*  f0fae1c:	14410002 */ 	bne	$v0,$at,.L0f0fae28
/*  f0fae20:	00000000 */ 	nop
/*  f0fae24:	0006000d */ 	break	0x6
.L0f0fae28:
/*  f0fae28:	01c3001a */ 	div	$zero,$t6,$v1
/*  f0fae2c:	00006812 */ 	mflo	$t5
/*  f0fae30:	14600002 */ 	bnez	$v1,.L0f0fae3c
/*  f0fae34:	00000000 */ 	nop
/*  f0fae38:	0007000d */ 	break	0x7
.L0f0fae3c:
/*  f0fae3c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fae40:	14610004 */ 	bne	$v1,$at,.L0f0fae54
/*  f0fae44:	3c018000 */ 	lui	$at,0x8000
/*  f0fae48:	15c10002 */ 	bne	$t6,$at,.L0f0fae54
/*  f0fae4c:	00000000 */ 	nop
/*  f0fae50:	0006000d */ 	break	0x6
.L0f0fae54:
/*  f0fae54:	05410003 */ 	bgez	$t2,.L0f0fae64
/*  f0fae58:	00000000 */ 	nop
/*  f0fae5c:	10000001 */ 	b	.L0f0fae64
/*  f0fae60:	2409ffff */ 	addiu	$t1,$zero,-1
.L0f0fae64:
/*  f0fae64:	10ed0002 */ 	beq	$a3,$t5,.L0f0fae70
/*  f0fae68:	00000000 */ 	nop
/*  f0fae6c:	241f0001 */ 	addiu	$ra,$zero,0x1
.L0f0fae70:
/*  f0fae70:	14800002 */ 	bnez	$a0,.L0f0fae7c
/*  f0fae74:	00000000 */ 	nop
/*  f0fae78:	241f0001 */ 	addiu	$ra,$zero,0x1
.L0f0fae7c:
/*  f0fae7c:	13e00007 */ 	beqz	$ra,.L0f0fae9c
/*  f0fae80:	00000000 */ 	nop
/*  f0fae84:	8fb900fc */ 	lw	$t9,0xfc($sp)
/*  f0fae88:	00897821 */ 	addu	$t7,$a0,$t1
/*  f0fae8c:	10000003 */ 	b	.L0f0fae9c
/*  f0fae90:	a72f0828 */ 	sh	$t7,0x828($t9)
.L0f0fae94:
/*  f0fae94:	8fb800fc */ 	lw	$t8,0xfc($sp)
.L0f0fae98:
/*  f0fae98:	a7000828 */ 	sh	$zero,0x828($t8)
.L0f0fae9c:
/*  f0fae9c:	10ed0002 */ 	beq	$a3,$t5,.L0f0faea8
/*  f0faea0:	3c19800a */ 	lui	$t9,%hi(g_Vars)
/*  f0faea4:	241f0001 */ 	addiu	$ra,$zero,0x1
.L0f0faea8:
/*  f0faea8:	17e00002 */ 	bnez	$ra,.L0f0faeb4
/*  f0faeac:	00000000 */ 	nop
/*  f0faeb0:	00004825 */ 	or	$t1,$zero,$zero
.L0f0faeb4:
/*  f0faeb4:	11000007 */ 	beqz	$t0,.L0f0faed4
/*  f0faeb8:	00006825 */ 	or	$t5,$zero,$zero
/*  f0faebc:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0faec0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0faec4:	a4600838 */ 	sh	$zero,0x838($v1)
/*  f0faec8:	ac600830 */ 	sw	$zero,0x830($v1)
/*  f0faecc:	10000005 */ 	b	.L0f0faee4
/*  f0faed0:	a4680836 */ 	sh	$t0,0x836($v1)
.L0f0faed4:
/*  f0faed4:	51800004 */ 	beqzl	$t4,.L0f0faee8
/*  f0faed8:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0faedc:	8fae00fc */ 	lw	$t6,0xfc($sp)
/*  f0faee0:	85cc0836 */ 	lh	$t4,0x836($t6)
.L0f0faee4:
/*  f0faee4:	8fa300fc */ 	lw	$v1,0xfc($sp)
.L0f0faee8:
/*  f0faee8:	8c620830 */ 	lw	$v0,0x830($v1)
/*  f0faeec:	2841003d */ 	slti	$at,$v0,0x3d
/*  f0faef0:	14200004 */ 	bnez	$at,.L0f0faf04
/*  f0faef4:	00000000 */ 	nop
/*  f0faef8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0faefc:	a46f0838 */ 	sh	$t7,0x838($v1)
/*  f0faf00:	8c620830 */ 	lw	$v0,0x830($v1)
.L0f0faf04:
/*  f0faf04:	0050001a */ 	div	$zero,$v0,$s0
/*  f0faf08:	8f399fc0 */ 	lw	$t9,%lo(g_Vars)($t9)
/*  f0faf0c:	00003812 */ 	mflo	$a3
/*  f0faf10:	846e0838 */ 	lh	$t6,0x838($v1)
/*  f0faf14:	0059c021 */ 	addu	$t8,$v0,$t9
/*  f0faf18:	0310001a */ 	div	$zero,$t8,$s0
/*  f0faf1c:	16000002 */ 	bnez	$s0,.L0f0faf28
/*  f0faf20:	00000000 */ 	nop
/*  f0faf24:	0007000d */ 	break	0x7
.L0f0faf28:
/*  f0faf28:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0faf2c:	16010004 */ 	bne	$s0,$at,.L0f0faf40
/*  f0faf30:	3c018000 */ 	lui	$at,0x8000
/*  f0faf34:	14410002 */ 	bne	$v0,$at,.L0f0faf40
/*  f0faf38:	00000000 */ 	nop
/*  f0faf3c:	0006000d */ 	break	0x6
.L0f0faf40:
/*  f0faf40:	00004012 */ 	mflo	$t0
/*  f0faf44:	01601025 */ 	or	$v0,$t3,$zero
/*  f0faf48:	16000002 */ 	bnez	$s0,.L0f0faf54
/*  f0faf4c:	00000000 */ 	nop
/*  f0faf50:	0007000d */ 	break	0x7
.L0f0faf54:
/*  f0faf54:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0faf58:	16010004 */ 	bne	$s0,$at,.L0f0faf6c
/*  f0faf5c:	3c018000 */ 	lui	$at,0x8000
/*  f0faf60:	17010002 */ 	bne	$t8,$at,.L0f0faf6c
/*  f0faf64:	00000000 */ 	nop
/*  f0faf68:	0006000d */ 	break	0x6
.L0f0faf6c:
/*  f0faf6c:	15c0000b */ 	bnez	$t6,.L0f0faf9c
/*  f0faf70:	00000000 */ 	nop
/*  f0faf74:	04e10003 */ 	bgez	$a3,.L0f0faf84
/*  f0faf78:	00077843 */ 	sra	$t7,$a3,0x1
/*  f0faf7c:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f0faf80:	00017843 */ 	sra	$t7,$at,0x1
.L0f0faf84:
/*  f0faf84:	01e03825 */ 	or	$a3,$t7,$zero
/*  f0faf88:	05010003 */ 	bgez	$t0,.L0f0faf98
/*  f0faf8c:	0008c843 */ 	sra	$t9,$t0,0x1
/*  f0faf90:	25010001 */ 	addiu	$at,$t0,0x1
/*  f0faf94:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0faf98:
/*  f0faf98:	03204025 */ 	or	$t0,$t9,$zero
.L0f0faf9c:
/*  f0faf9c:	05610003 */ 	bgez	$t3,.L0f0fafac
/*  f0fafa0:	a3ac010d */ 	sb	$t4,0x10d($sp)
/*  f0fafa4:	10000001 */ 	b	.L0f0fafac
/*  f0fafa8:	000b1023 */ 	negu	$v0,$t3
.L0f0fafac:
/*  f0fafac:	05410003 */ 	bgez	$t2,.L0f0fafbc
/*  f0fafb0:	28410014 */ 	slti	$at,$v0,0x14
/*  f0fafb4:	10000002 */ 	b	.L0f0fafc0
/*  f0fafb8:	000a1823 */ 	negu	$v1,$t2
.L0f0fafbc:
/*  f0fafbc:	01401825 */ 	or	$v1,$t2,$zero
.L0f0fafc0:
/*  f0fafc0:	1420005d */ 	bnez	$at,.L0f0fb138
/*  f0fafc4:	0062082a */ 	slt	$at,$v1,$v0
/*  f0fafc8:	14200003 */ 	bnez	$at,.L0f0fafd8
/*  f0fafcc:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0fafd0:	5240005a */ 	beqzl	$s2,.L0f0fb13c
/*  f0fafd4:	8fa300fc */ 	lw	$v1,0xfc($sp)
.L0f0fafd8:
/*  f0fafd8:	05610006 */ 	bgez	$t3,.L0f0faff4
/*  f0fafdc:	28410047 */ 	slti	$at,$v0,0x47
/*  f0fafe0:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fafe4:	84780834 */ 	lh	$t8,0x834($v1)
/*  f0fafe8:	07030003 */ 	bgezl	$t8,.L0f0faff8
/*  f0fafec:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0faff0:	a4600834 */ 	sh	$zero,0x834($v1)
.L0f0faff4:
/*  f0faff4:	8fa300fc */ 	lw	$v1,0xfc($sp)
.L0f0faff8:
/*  f0faff8:	19600005 */ 	blez	$t3,.L0f0fb010
/*  f0faffc:	84640834 */ 	lh	$a0,0x834($v1)
/*  f0fb000:	18800003 */ 	blez	$a0,.L0f0fb010
/*  f0fb004:	00000000 */ 	nop
/*  f0fb008:	a4600834 */ 	sh	$zero,0x834($v1)
/*  f0fb00c:	84640834 */ 	lh	$a0,0x834($v1)
.L0f0fb010:
/*  f0fb010:	14800003 */ 	bnez	$a0,.L0f0fb020
/*  f0fb014:	00000000 */ 	nop
/*  f0fb018:	ac600830 */ 	sw	$zero,0x830($v1)
/*  f0fb01c:	84640834 */ 	lh	$a0,0x834($v1)
.L0f0fb020:
/*  f0fb020:	14200002 */ 	bnez	$at,.L0f0fb02c
/*  f0fb024:	8cc69fc0 */ 	lw	$a2,%lo(g_Vars)($a2)
/*  f0fb028:	24020046 */ 	addiu	$v0,$zero,0x46
.L0f0fb02c:
/*  f0fb02c:	2442ffec */ 	addiu	$v0,$v0,-20
/*  f0fb030:	02820019 */ 	multu	$s4,$v0
/*  f0fb034:	24010032 */ 	addiu	$at,$zero,0x32
/*  f0fb038:	8fb900fc */ 	lw	$t9,0xfc($sp)
/*  f0fb03c:	00007012 */ 	mflo	$t6
/*  f0fb040:	00000000 */ 	nop
/*  f0fb044:	00000000 */ 	nop
/*  f0fb048:	01c1001a */ 	div	$zero,$t6,$at
/*  f0fb04c:	00007812 */ 	mflo	$t7
/*  f0fb050:	026f2823 */ 	subu	$a1,$s3,$t7
/*  f0fb054:	28810003 */ 	slti	$at,$a0,0x3
/*  f0fb058:	10200004 */ 	beqz	$at,.L0f0fb06c
/*  f0fb05c:	00a01825 */ 	or	$v1,$a1,$zero
/*  f0fb060:	2881fffe */ 	slti	$at,$a0,-2
/*  f0fb064:	10200006 */ 	beqz	$at,.L0f0fb080
/*  f0fb068:	00000000 */ 	nop
.L0f0fb06c:
/*  f0fb06c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0fb070:	00a1001a */ 	div	$zero,$a1,$at
/*  f0fb074:	00001812 */ 	mflo	$v1
/*  f0fb078:	00000000 */ 	nop
/*  f0fb07c:	00000000 */ 	nop
.L0f0fb080:
/*  f0fb080:	5860002b */ 	blezl	$v1,.L0f0fb130
/*  f0fb084:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fb088:	8f220830 */ 	lw	$v0,0x830($t9)
/*  f0fb08c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0fb090:	0043001a */ 	div	$zero,$v0,$v1
/*  f0fb094:	0046c021 */ 	addu	$t8,$v0,$a2
/*  f0fb098:	00003812 */ 	mflo	$a3
/*  f0fb09c:	14600002 */ 	bnez	$v1,.L0f0fb0a8
/*  f0fb0a0:	00000000 */ 	nop
/*  f0fb0a4:	0007000d */ 	break	0x7
.L0f0fb0a8:
/*  f0fb0a8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fb0ac:	14610004 */ 	bne	$v1,$at,.L0f0fb0c0
/*  f0fb0b0:	3c018000 */ 	lui	$at,0x8000
/*  f0fb0b4:	14410002 */ 	bne	$v0,$at,.L0f0fb0c0
/*  f0fb0b8:	00000000 */ 	nop
/*  f0fb0bc:	0006000d */ 	break	0x6
.L0f0fb0c0:
/*  f0fb0c0:	0303001a */ 	div	$zero,$t8,$v1
/*  f0fb0c4:	00004012 */ 	mflo	$t0
/*  f0fb0c8:	14600002 */ 	bnez	$v1,.L0f0fb0d4
/*  f0fb0cc:	00000000 */ 	nop
/*  f0fb0d0:	0007000d */ 	break	0x7
.L0f0fb0d4:
/*  f0fb0d4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fb0d8:	14610004 */ 	bne	$v1,$at,.L0f0fb0ec
/*  f0fb0dc:	3c018000 */ 	lui	$at,0x8000
/*  f0fb0e0:	17010002 */ 	bne	$t8,$at,.L0f0fb0ec
/*  f0fb0e4:	00000000 */ 	nop
/*  f0fb0e8:	0006000d */ 	break	0x6
.L0f0fb0ec:
/*  f0fb0ec:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fb0f0:	19600003 */ 	blez	$t3,.L0f0fb100
/*  f0fb0f4:	00000000 */ 	nop
/*  f0fb0f8:	10000001 */ 	b	.L0f0fb100
/*  f0fb0fc:	240cffff */ 	addiu	$t4,$zero,-1
.L0f0fb100:
/*  f0fb100:	10e80002 */ 	beq	$a3,$t0,.L0f0fb10c
/*  f0fb104:	008c7021 */ 	addu	$t6,$a0,$t4
/*  f0fb108:	240d0001 */ 	addiu	$t5,$zero,0x1
.L0f0fb10c:
/*  f0fb10c:	14800002 */ 	bnez	$a0,.L0f0fb118
/*  f0fb110:	00000000 */ 	nop
/*  f0fb114:	240d0001 */ 	addiu	$t5,$zero,0x1
.L0f0fb118:
/*  f0fb118:	51a00005 */ 	beqzl	$t5,.L0f0fb130
/*  f0fb11c:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0fb120:	a46e0834 */ 	sh	$t6,0x834($v1)
/*  f0fb124:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0fb128:	8cc69fc0 */ 	lw	$a2,%lo(g_Vars)($a2)
/*  f0fb12c:	8fa300fc */ 	lw	$v1,0xfc($sp)
.L0f0fb130:
/*  f0fb130:	10000006 */ 	b	.L0f0fb14c
/*  f0fb134:	8c620830 */ 	lw	$v0,0x830($v1)
.L0f0fb138:
/*  f0fb138:	8fa300fc */ 	lw	$v1,0xfc($sp)
.L0f0fb13c:
/*  f0fb13c:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0fb140:	a4600834 */ 	sh	$zero,0x834($v1)
/*  f0fb144:	8cc69fc0 */ 	lw	$a2,%lo(g_Vars)($a2)
/*  f0fb148:	8c620830 */ 	lw	$v0,0x830($v1)
.L0f0fb14c:
/*  f0fb14c:	10e80002 */ 	beq	$a3,$t0,.L0f0fb158
/*  f0fb150:	27b50104 */ 	addiu	$s5,$sp,0x104
/*  f0fb154:	240d0001 */ 	addiu	$t5,$zero,0x1
.L0f0fb158:
/*  f0fb158:	55a00003 */ 	bnezl	$t5,.L0f0fb168
/*  f0fb15c:	8c6f0824 */ 	lw	$t7,0x824($v1)
/*  f0fb160:	00006025 */ 	or	$t4,$zero,$zero
/*  f0fb164:	8c6f0824 */ 	lw	$t7,0x824($v1)
.L0f0fb168:
/*  f0fb168:	8fa500f8 */ 	lw	$a1,0xf8($sp)
/*  f0fb16c:	3c18800a */ 	lui	$t8,%hi(g_Vars)
/*  f0fb170:	01e6c821 */ 	addu	$t9,$t7,$a2
/*  f0fb174:	ac790824 */ 	sw	$t9,0x824($v1)
/*  f0fb178:	8f189fc0 */ 	lw	$t8,%lo(g_Vars)($t8)
/*  f0fb17c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fb180:	00587021 */ 	addu	$t6,$v0,$t8
/*  f0fb184:	ac6e0830 */ 	sw	$t6,0x830($v1)
/*  f0fb188:	a3a90104 */ 	sb	$t1,0x104($sp)
/*  f0fb18c:	a3ac0105 */ 	sb	$t4,0x105($sp)
/*  f0fb190:	a3aa0108 */ 	sb	$t2,0x108($sp)
/*  f0fb194:	a3ab0109 */ 	sb	$t3,0x109($sp)
/*  f0fb198:	10a00003 */ 	beqz	$a1,.L0f0fb1a8
/*  f0fb19c:	a3a00118 */ 	sb	$zero,0x118($sp)
/*  f0fb1a0:	10000002 */ 	b	.L0f0fb1ac
/*  f0fb1a4:	a3af010e */ 	sb	$t7,0x10e($sp)
.L0f0fb1a8:
/*  f0fb1a8:	a3a0010e */ 	sb	$zero,0x10e($sp)
.L0f0fb1ac:
/*  f0fb1ac:	8ee30000 */ 	lw	$v1,0x0($s7)
/*  f0fb1b0:	007e0019 */ 	multu	$v1,$s8
/*  f0fb1b4:	0000c812 */ 	mflo	$t9
/*  f0fb1b8:	02d93821 */ 	addu	$a3,$s6,$t9
/*  f0fb1bc:	8ce404f8 */ 	lw	$a0,0x4f8($a3)
/*  f0fb1c0:	50800016 */ 	beqzl	$a0,.L0f0fb21c
/*  f0fb1c4:	84e204f4 */ 	lh	$v0,0x4f4($a3)
/*  f0fb1c8:	50a00014 */ 	beqzl	$a1,.L0f0fb21c
/*  f0fb1cc:	84e204f4 */ 	lh	$v0,0x4f4($a3)
/*  f0fb1d0:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f0fb1d4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0fb1d8:	8f0e0010 */ 	lw	$t6,0x10($t8)
/*  f0fb1dc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0fb1e0:	31cf0004 */ 	andi	$t7,$t6,0x4
/*  f0fb1e4:	51e00004 */ 	beqzl	$t7,.L0f0fb1f8
/*  f0fb1e8:	8c820008 */ 	lw	$v0,0x8($a0)
/*  f0fb1ec:	a3b90106 */ 	sb	$t9,0x106($sp)
/*  f0fb1f0:	afb8011c */ 	sw	$t8,0x11c($sp)
/*  f0fb1f4:	8c820008 */ 	lw	$v0,0x8($a0)
.L0f0fb1f8:
/*  f0fb1f8:	50400008 */ 	beqzl	$v0,.L0f0fb21c
/*  f0fb1fc:	84e204f4 */ 	lh	$v0,0x4f4($a3)
/*  f0fb200:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f0fb204:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0fb208:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fb20c:	55c10003 */ 	bnel	$t6,$at,.L0f0fb21c
/*  f0fb210:	84e204f4 */ 	lh	$v0,0x4f4($a3)
/*  f0fb214:	a3af0106 */ 	sb	$t7,0x106($sp)
/*  f0fb218:	84e204f4 */ 	lh	$v0,0x4f4($a3)
.L0f0fb21c:
/*  f0fb21c:	00009825 */ 	or	$s3,$zero,$zero
/*  f0fb220:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0fb224:	1840003a */ 	blez	$v0,.L0f0fb310
/*  f0fb228:	00000000 */ 	nop
/*  f0fb22c:	afa00044 */ 	sw	$zero,0x44($sp)
.L0f0fb230:
/*  f0fb230:	0003c8c0 */ 	sll	$t9,$v1,0x3
/*  f0fb234:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0fb238:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0fb23c:	0323c821 */ 	addu	$t9,$t9,$v1
/*  f0fb240:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fb244:	8fae0044 */ 	lw	$t6,0x44($sp)
/*  f0fb248:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0fb24c:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0fb250:	02d9c021 */ 	addu	$t8,$s6,$t9
/*  f0fb254:	030e9021 */ 	addu	$s2,$t8,$t6
/*  f0fb258:	824f0478 */ 	lb	$t7,0x478($s2)
/*  f0fb25c:	26520464 */ 	addiu	$s2,$s2,0x464
/*  f0fb260:	02408825 */ 	or	$s1,$s2,$zero
/*  f0fb264:	19e00024 */ 	blez	$t7,.L0f0fb2f8
/*  f0fb268:	00008025 */ 	or	$s0,$zero,$zero
/*  f0fb26c:	8ef80000 */ 	lw	$t8,0x0($s7)
.L0f0fb270:
/*  f0fb270:	26990001 */ 	addiu	$t9,$s4,0x1
/*  f0fb274:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fb278:	031e0019 */ 	multu	$t8,$s8
/*  f0fb27c:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0fb280:	00007012 */ 	mflo	$t6
/*  f0fb284:	02ce7821 */ 	addu	$t7,$s6,$t6
/*  f0fb288:	85f804f4 */ 	lh	$t8,0x4f4($t7)
/*  f0fb28c:	17380008 */ 	bne	$t9,$t8,.L0f0fb2b0
/*  f0fb290:	00000000 */ 	nop
/*  f0fb294:	824e0015 */ 	lb	$t6,0x15($s2)
/*  f0fb298:	160e0005 */ 	bne	$s0,$t6,.L0f0fb2b0
/*  f0fb29c:	00000000 */ 	nop
/*  f0fb2a0:	16600003 */ 	bnez	$s3,.L0f0fb2b0
/*  f0fb2a4:	00000000 */ 	nop
/*  f0fb2a8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0fb2ac:	24130001 */ 	addiu	$s3,$zero,0x1
.L0f0fb2b0:
/*  f0fb2b0:	0fc3e4d7 */ 	jal	func0f0f935c
/*  f0fb2b4:	8e240000 */ 	lw	$a0,0x0($s1)
/*  f0fb2b8:	824f0014 */ 	lb	$t7,0x14($s2)
/*  f0fb2bc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0fb2c0:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f0fb2c4:	020f082a */ 	slt	$at,$s0,$t7
/*  f0fb2c8:	5420ffe9 */ 	bnezl	$at,.L0f0fb270
/*  f0fb2cc:	8ef80000 */ 	lw	$t8,0x0($s7)
/*  f0fb2d0:	8ee30000 */ 	lw	$v1,0x0($s7)
/*  f0fb2d4:	0003c8c0 */ 	sll	$t9,$v1,0x3
/*  f0fb2d8:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0fb2dc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0fb2e0:	0323c821 */ 	addu	$t9,$t9,$v1
/*  f0fb2e4:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fb2e8:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f0fb2ec:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0fb2f0:	02d93821 */ 	addu	$a3,$s6,$t9
/*  f0fb2f4:	84e204f4 */ 	lh	$v0,0x4f4($a3)
.L0f0fb2f8:
/*  f0fb2f8:	8fb80044 */ 	lw	$t8,0x44($sp)
/*  f0fb2fc:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0fb300:	0282082a */ 	slt	$at,$s4,$v0
/*  f0fb304:	270e0018 */ 	addiu	$t6,$t8,0x18
/*  f0fb308:	1420ffc9 */ 	bnez	$at,.L0f0fb230
/*  f0fb30c:	afae0044 */ 	sw	$t6,0x44($sp)
.L0f0fb310:
/*  f0fb310:	3c0f800a */ 	lui	$t7,%hi(g_MenuData+0x4)
/*  f0fb314:	8def19c4 */ 	lw	$t7,%lo(g_MenuData+0x4)($t7)
/*  f0fb318:	25f9ffff */ 	addiu	$t9,$t7,-1
/*  f0fb31c:	2f21000d */ 	sltiu	$at,$t9,0xd
/*  f0fb320:	1020004d */ 	beqz	$at,.L0f0fb458
/*  f0fb324:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0fb328:	3c017f1b */ 	lui	$at,%hi(var7f1b2a98)
/*  f0fb32c:	00390821 */ 	addu	$at,$at,$t9
/*  f0fb330:	8c392a98 */ 	lw	$t9,%lo(var7f1b2a98)($at)
/*  f0fb334:	03200008 */ 	jr	$t9
/*  f0fb338:	00000000 */ 	nop
/*  f0fb33c:	83b8010e */ 	lb	$t8,0x10e($sp)
/*  f0fb340:	8fae011c */ 	lw	$t6,0x11c($sp)
/*  f0fb344:	53000045 */ 	beqzl	$t8,.L0f0fb45c
/*  f0fb348:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb34c:	55c00043 */ 	bnezl	$t6,.L0f0fb45c
/*  f0fb350:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb354:	8ce404f8 */ 	lw	$a0,0x4f8($a3)
/*  f0fb358:	8faf0100 */ 	lw	$t7,0x100($sp)
/*  f0fb35c:	5080003f */ 	beqzl	$a0,.L0f0fb45c
/*  f0fb360:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb364:	8df9000c */ 	lw	$t9,0xc($t7)
/*  f0fb368:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x490)
/*  f0fb36c:	5720003b */ 	bnezl	$t9,.L0f0fb45c
/*  f0fb370:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb374:	8f18a450 */ 	lw	$t8,%lo(g_Vars+0x490)($t8)
/*  f0fb378:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f0fb37c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0fb380:	13010008 */ 	beq	$t8,$at,.L0f0fb3a4
/*  f0fb384:	3c048008 */ 	lui	$a0,%hi(g_MpReadyMenuDialog)
/*  f0fb388:	248457b8 */ 	addiu	$a0,$a0,%lo(g_MpReadyMenuDialog)
/*  f0fb38c:	10820005 */ 	beq	$a0,$v0,.L0f0fb3a4
/*  f0fb390:	00000000 */ 	nop
/*  f0fb394:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f0fb398:	00000000 */ 	nop
/*  f0fb39c:	1000002f */ 	b	.L0f0fb45c
/*  f0fb3a0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f0fb3a4:
/*  f0fb3a4:	3c0e8008 */ 	lui	$t6,%hi(g_MpQuickTeamGameSetupMenuDialog)
/*  f0fb3a8:	25ce6680 */ 	addiu	$t6,$t6,%lo(g_MpQuickTeamGameSetupMenuDialog)
/*  f0fb3ac:	55c2002b */ 	bnel	$t6,$v0,.L0f0fb45c
/*  f0fb3b0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb3b4:	0fc5fd0a */ 	jal	func0f17f428
/*  f0fb3b8:	00000000 */ 	nop
/*  f0fb3bc:	10000027 */ 	b	.L0f0fb45c
/*  f0fb3c0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb3c4:	3c0f8007 */ 	lui	$t7,%hi(var80070764)
/*  f0fb3c8:	8def0764 */ 	lw	$t7,%lo(var80070764)($t7)
/*  f0fb3cc:	51e00010 */ 	beqzl	$t7,.L0f0fb410
/*  f0fb3d0:	240f000a */ 	addiu	$t7,$zero,0xa
/*  f0fb3d4:	0fc3e048 */ 	jal	func0f0f8120
/*  f0fb3d8:	00000000 */ 	nop
/*  f0fb3dc:	3c198007 */ 	lui	$t9,%hi(g_MpPlayerNum)
/*  f0fb3e0:	8f391448 */ 	lw	$t9,%lo(g_MpPlayerNum)($t9)
/*  f0fb3e4:	3c0e800a */ 	lui	$t6,%hi(g_Menus)
/*  f0fb3e8:	25cee000 */ 	addiu	$t6,$t6,%lo(g_Menus)
/*  f0fb3ec:	0019c0c0 */ 	sll	$t8,$t9,0x3
/*  f0fb3f0:	0319c023 */ 	subu	$t8,$t8,$t9
/*  f0fb3f4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0fb3f8:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f0fb3fc:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0fb400:	0319c023 */ 	subu	$t8,$t8,$t9
/*  f0fb404:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0fb408:	030e3821 */ 	addu	$a3,$t8,$t6
/*  f0fb40c:	240f000a */ 	addiu	$t7,$zero,0xa
.L0f0fb410:
/*  f0fb410:	a0ef083c */ 	sb	$t7,0x83c($a3)
/*  f0fb414:	83b9010e */ 	lb	$t9,0x10e($sp)
/*  f0fb418:	8fb8011c */ 	lw	$t8,0x11c($sp)
/*  f0fb41c:	5320000f */ 	beqzl	$t9,.L0f0fb45c
/*  f0fb420:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb424:	5700000d */ 	bnezl	$t8,.L0f0fb45c
/*  f0fb428:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb42c:	8cee04f8 */ 	lw	$t6,0x4f8($a3)
/*  f0fb430:	8faf0100 */ 	lw	$t7,0x100($sp)
/*  f0fb434:	51c00009 */ 	beqzl	$t6,.L0f0fb45c
/*  f0fb438:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb43c:	8df90000 */ 	lw	$t9,0x0($t7)
/*  f0fb440:	8f380010 */ 	lw	$t8,0x10($t9)
/*  f0fb444:	330e0020 */ 	andi	$t6,$t8,0x20
/*  f0fb448:	55c00004 */ 	bnezl	$t6,.L0f0fb45c
/*  f0fb44c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fb450:	0fc3e048 */ 	jal	func0f0f8120
/*  f0fb454:	00000000 */ 	nop
.L0f0fb458:
/*  f0fb458:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f0fb45c:
/*  f0fb45c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0fb460:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0fb464:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0fb468:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0fb46c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0fb470:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0fb474:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0fb478:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0fb47c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0fb480:	03e00008 */ 	jr	$ra
/*  f0fb484:	27bd0130 */ 	addiu	$sp,$sp,0x130
);

u32 var800714ec = 0x00000001;

GLOBAL_ASM(
glabel func0f0fb488
.late_rodata
glabel var7f1b2acc
.word func0f0fb488+0x40 # f0fb4c8
glabel var7f1b2ad0
.word func0f0fb488+0x12c # f0fb5b4
glabel var7f1b2ad4
.word func0f0fb488+0x3c4 # f0fb84c
glabel var7f1b2ad8
.word func0f0fb488+0x4f0 # f0fb978
glabel var7f1b2adc
.word func0f0fb488+0x66c # f0fbaf4
glabel var7f1b2ae0
.word func0f0fb488+0x700 # f0fbb88
glabel var7f1b2ae4
.word func0f0fb488+0x22c # f0fb6b4
glabel var7f1b2ae8
.word func0f0fb488+0x12c # f0fb5b4
glabel var7f1b2aec
.word func0f0fb488+0x6b8 # f0fbb40
glabel var7f1b2af0
.word 0x3f847ae1
glabel var7f1b2af4
.word 0x47ae147b
.text
/*  f0fb488:	30ae00ff */ 	andi	$t6,$a1,0xff
/*  f0fb48c:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f0fb490:	25cfffff */ 	addiu	$t7,$t6,-1
/*  f0fb494:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0fb498:	44866000 */ 	mtc1	$a2,$f12
/*  f0fb49c:	2de10009 */ 	sltiu	$at,$t7,0x9
/*  f0fb4a0:	00808025 */ 	or	$s0,$a0,$zero
/*  f0fb4a4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0fb4a8:	102001b7 */ 	beqz	$at,.L0f0fbb88
/*  f0fb4ac:	afa50084 */ 	sw	$a1,0x84($sp)
/*  f0fb4b0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0fb4b4:	3c017f1b */ 	lui	$at,%hi(var7f1b2acc)
/*  f0fb4b8:	002f0821 */ 	addu	$at,$at,$t7
/*  f0fb4bc:	8c2f2acc */ 	lw	$t7,%lo(var7f1b2acc)($at)
/*  f0fb4c0:	01e00008 */ 	jr	$t7
/*  f0fb4c4:	00000000 */ 	nop
/*  f0fb4c8:	3c01437f */ 	lui	$at,0x437f
/*  f0fb4cc:	44812000 */ 	mtc1	$at,$f4
/*  f0fb4d0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0fb4d4:	3c014f00 */ 	lui	$at,0x4f00
/*  f0fb4d8:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f0fb4dc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fb4e0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fb4e4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0fb4e8:	4458f800 */ 	cfc1	$t8,$31
/*  f0fb4ec:	44c3f800 */ 	ctc1	$v1,$31
/*  f0fb4f0:	00000000 */ 	nop
/*  f0fb4f4:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0fb4f8:	4443f800 */ 	cfc1	$v1,$31
/*  f0fb4fc:	00000000 */ 	nop
/*  f0fb500:	30630078 */ 	andi	$v1,$v1,0x78
/*  f0fb504:	50600013 */ 	beqzl	$v1,.L0f0fb554
/*  f0fb508:	44034000 */ 	mfc1	$v1,$f8
/*  f0fb50c:	44814000 */ 	mtc1	$at,$f8
/*  f0fb510:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0fb514:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0fb518:	44c3f800 */ 	ctc1	$v1,$31
/*  f0fb51c:	00000000 */ 	nop
/*  f0fb520:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0fb524:	4443f800 */ 	cfc1	$v1,$31
/*  f0fb528:	00000000 */ 	nop
/*  f0fb52c:	30630078 */ 	andi	$v1,$v1,0x78
/*  f0fb530:	14600005 */ 	bnez	$v1,.L0f0fb548
/*  f0fb534:	00000000 */ 	nop
/*  f0fb538:	44034000 */ 	mfc1	$v1,$f8
/*  f0fb53c:	3c018000 */ 	lui	$at,0x8000
/*  f0fb540:	10000007 */ 	b	.L0f0fb560
/*  f0fb544:	00611825 */ 	or	$v1,$v1,$at
.L0f0fb548:
/*  f0fb548:	10000005 */ 	b	.L0f0fb560
/*  f0fb54c:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f0fb550:	44034000 */ 	mfc1	$v1,$f8
.L0f0fb554:
/*  f0fb554:	00000000 */ 	nop
/*  f0fb558:	0460fffb */ 	bltz	$v1,.L0f0fb548
/*  f0fb55c:	00000000 */ 	nop
.L0f0fb560:
/*  f0fb560:	44d8f800 */ 	ctc1	$t8,$31
/*  f0fb564:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0fb568:	00612825 */ 	or	$a1,$v1,$at
/*  f0fb56c:	0fc38266 */ 	jal	func0f0e0998
/*  f0fb570:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f0fb574:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f0fb578:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0fb57c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fb580:	00038042 */ 	srl	$s0,$v1,0x1
/*  f0fb584:	02012825 */ 	or	$a1,$s0,$at
/*  f0fb588:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0fb58c:	2406ffe2 */ 	addiu	$a2,$zero,-30
/*  f0fb590:	0fc38266 */ 	jal	func0f0e0998
/*  f0fb594:	2407ffe2 */ 	addiu	$a3,$zero,-30
/*  f0fb598:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fb59c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0fb5a0:	2406001e */ 	addiu	$a2,$zero,0x1e
/*  f0fb5a4:	0fc38266 */ 	jal	func0f0e0998
/*  f0fb5a8:	2407001e */ 	addiu	$a3,$zero,0x1e
/*  f0fb5ac:	10000176 */ 	b	.L0f0fbb88
/*  f0fb5b0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0fb5b4:	3c01437f */ 	lui	$at,0x437f
/*  f0fb5b8:	44815000 */ 	mtc1	$at,$f10
/*  f0fb5bc:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0fb5c0:	3c098006 */ 	lui	$t1,%hi(var800613a0)
/*  f0fb5c4:	460c5402 */ 	mul.s	$f16,$f10,$f12
/*  f0fb5c8:	252913a0 */ 	addiu	$t1,$t1,%lo(var800613a0)
/*  f0fb5cc:	3c080600 */ 	lui	$t0,0x600
/*  f0fb5d0:	ae080000 */ 	sw	$t0,0x0($s0)
/*  f0fb5d4:	ae090004 */ 	sw	$t1,0x4($s0)
/*  f0fb5d8:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f0fb5dc:	3c014f00 */ 	lui	$at,0x4f00
/*  f0fb5e0:	444af800 */ 	cfc1	$t2,$31
/*  f0fb5e4:	44c5f800 */ 	ctc1	$a1,$31
/*  f0fb5e8:	00000000 */ 	nop
/*  f0fb5ec:	460084a4 */ 	cvt.w.s	$f18,$f16
/*  f0fb5f0:	4445f800 */ 	cfc1	$a1,$31
/*  f0fb5f4:	00000000 */ 	nop
/*  f0fb5f8:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f0fb5fc:	50a00013 */ 	beqzl	$a1,.L0f0fb64c
/*  f0fb600:	44059000 */ 	mfc1	$a1,$f18
/*  f0fb604:	44819000 */ 	mtc1	$at,$f18
/*  f0fb608:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0fb60c:	46128481 */ 	sub.s	$f18,$f16,$f18
/*  f0fb610:	44c5f800 */ 	ctc1	$a1,$31
/*  f0fb614:	00000000 */ 	nop
/*  f0fb618:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f0fb61c:	4445f800 */ 	cfc1	$a1,$31
/*  f0fb620:	00000000 */ 	nop
/*  f0fb624:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f0fb628:	14a00005 */ 	bnez	$a1,.L0f0fb640
/*  f0fb62c:	00000000 */ 	nop
/*  f0fb630:	44059000 */ 	mfc1	$a1,$f18
/*  f0fb634:	3c018000 */ 	lui	$at,0x8000
/*  f0fb638:	10000007 */ 	b	.L0f0fb658
/*  f0fb63c:	00a12825 */ 	or	$a1,$a1,$at
.L0f0fb640:
/*  f0fb640:	10000005 */ 	b	.L0f0fb658
/*  f0fb644:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0fb648:	44059000 */ 	mfc1	$a1,$f18
.L0f0fb64c:
/*  f0fb64c:	00000000 */ 	nop
/*  f0fb650:	04a0fffb */ 	bltz	$a1,.L0f0fb640
/*  f0fb654:	00000000 */ 	nop
.L0f0fb658:
/*  f0fb658:	44caf800 */ 	ctc1	$t2,$31
/*  f0fb65c:	0fc54df7 */ 	jal	func0f1537dc
/*  f0fb660:	00000000 */ 	nop
/*  f0fb664:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f0fb668:	0c002f02 */ 	jal	viGetX
/*  f0fb66c:	24500008 */ 	addiu	$s0,$v0,0x8
/*  f0fb670:	0c002f06 */ 	jal	viGetY
/*  f0fb674:	a7a2003a */ 	sh	$v0,0x3a($sp)
/*  f0fb678:	87ae003a */ 	lh	$t6,0x3a($sp)
/*  f0fb67c:	304b03ff */ 	andi	$t3,$v0,0x3ff
/*  f0fb680:	8fa30070 */ 	lw	$v1,0x70($sp)
/*  f0fb684:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f0fb688:	3c01f600 */ 	lui	$at,0xf600
/*  f0fb68c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0fb690:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0fb694:	01816825 */ 	or	$t5,$t4,$at
/*  f0fb698:	01b8c825 */ 	or	$t9,$t5,$t8
/*  f0fb69c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fb6a0:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f0fb6a4:	0fc54e0e */ 	jal	func0f153838
/*  f0fb6a8:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f0fb6ac:	10000136 */ 	b	.L0f0fbb88
/*  f0fb6b0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0fb6b4:	02001025 */ 	or	$v0,$s0,$zero
/*  f0fb6b8:	3c038006 */ 	lui	$v1,%hi(var800613a0)
/*  f0fb6bc:	246313a0 */ 	addiu	$v1,$v1,%lo(var800613a0)
/*  f0fb6c0:	3c080600 */ 	lui	$t0,0x600
/*  f0fb6c4:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f0fb6c8:	ac430004 */ 	sw	$v1,0x4($v0)
/*  f0fb6cc:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f0fb6d0:	e7ac0088 */ 	swc1	$f12,0x88($sp)
/*  f0fb6d4:	afa30034 */ 	sw	$v1,0x34($sp)
/*  f0fb6d8:	0fc54df7 */ 	jal	func0f1537dc
/*  f0fb6dc:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f0fb6e0:	afa20068 */ 	sw	$v0,0x68($sp)
/*  f0fb6e4:	0c002f02 */ 	jal	viGetX
/*  f0fb6e8:	24500008 */ 	addiu	$s0,$v0,0x8
/*  f0fb6ec:	0c002f06 */ 	jal	viGetY
/*  f0fb6f0:	a7a2003a */ 	sh	$v0,0x3a($sp)
/*  f0fb6f4:	87ac003a */ 	lh	$t4,0x3a($sp)
/*  f0fb6f8:	304903ff */ 	andi	$t1,$v0,0x3ff
/*  f0fb6fc:	8fa30068 */ 	lw	$v1,0x68($sp)
/*  f0fb700:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0fb704:	3c01f600 */ 	lui	$at,0xf600
/*  f0fb708:	318e03ff */ 	andi	$t6,$t4,0x3ff
/*  f0fb70c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0fb710:	01415825 */ 	or	$t3,$t2,$at
/*  f0fb714:	016f6825 */ 	or	$t5,$t3,$t7
/*  f0fb718:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fb71c:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0fb720:	0fc54e0e */ 	jal	func0f153838
/*  f0fb724:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f0fb728:	0fc39400 */ 	jal	func0f0e5000
/*  f0fb72c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fb730:	3c013f80 */ 	lui	$at,0x3f80
/*  f0fb734:	44810000 */ 	mtc1	$at,$f0
/*  f0fb738:	c7a40088 */ 	lwc1	$f4,0x88($sp)
/*  f0fb73c:	3c01437f */ 	lui	$at,0x437f
/*  f0fb740:	44814000 */ 	mtc1	$at,$f8
/*  f0fb744:	46040181 */ 	sub.s	$f6,$f0,$f4
/*  f0fb748:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0fb74c:	00408025 */ 	or	$s0,$v0,$zero
/*  f0fb750:	3c014f00 */ 	lui	$at,0x4f00
/*  f0fb754:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0fb758:	02001025 */ 	or	$v0,$s0,$zero
/*  f0fb75c:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f0fb760:	3c190600 */ 	lui	$t9,0x600
/*  f0fb764:	4458f800 */ 	cfc1	$t8,$31
/*  f0fb768:	44c6f800 */ 	ctc1	$a2,$31
/*  f0fb76c:	00000000 */ 	nop
/*  f0fb770:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f0fb774:	4446f800 */ 	cfc1	$a2,$31
/*  f0fb778:	00000000 */ 	nop
/*  f0fb77c:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f0fb780:	50c00013 */ 	beqzl	$a2,.L0f0fb7d0
/*  f0fb784:	44068000 */ 	mfc1	$a2,$f16
/*  f0fb788:	44818000 */ 	mtc1	$at,$f16
/*  f0fb78c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0fb790:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f0fb794:	44c6f800 */ 	ctc1	$a2,$31
/*  f0fb798:	00000000 */ 	nop
/*  f0fb79c:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f0fb7a0:	4446f800 */ 	cfc1	$a2,$31
/*  f0fb7a4:	00000000 */ 	nop
/*  f0fb7a8:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f0fb7ac:	14c00005 */ 	bnez	$a2,.L0f0fb7c4
/*  f0fb7b0:	00000000 */ 	nop
/*  f0fb7b4:	44068000 */ 	mfc1	$a2,$f16
/*  f0fb7b8:	3c018000 */ 	lui	$at,0x8000
/*  f0fb7bc:	10000007 */ 	b	.L0f0fb7dc
/*  f0fb7c0:	00c13025 */ 	or	$a2,$a2,$at
.L0f0fb7c4:
/*  f0fb7c4:	10000005 */ 	b	.L0f0fb7dc
/*  f0fb7c8:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0fb7cc:	44068000 */ 	mfc1	$a2,$f16
.L0f0fb7d0:
/*  f0fb7d0:	00000000 */ 	nop
/*  f0fb7d4:	04c0fffb */ 	bltz	$a2,.L0f0fb7c4
/*  f0fb7d8:	00000000 */ 	nop
.L0f0fb7dc:
/*  f0fb7dc:	44d8f800 */ 	ctc1	$t8,$31
/*  f0fb7e0:	50c000ea */ 	beqzl	$a2,.L0f0fbb8c
/*  f0fb7e4:	02001025 */ 	or	$v0,$s0,$zero
/*  f0fb7e8:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0fb7ec:	8fa80034 */ 	lw	$t0,0x34($sp)
/*  f0fb7f0:	00c02825 */ 	or	$a1,$a2,$zero
/*  f0fb7f4:	0fc54df7 */ 	jal	func0f1537dc
/*  f0fb7f8:	ac480004 */ 	sw	$t0,0x4($v0)
/*  f0fb7fc:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f0fb800:	0c002f02 */ 	jal	viGetX
/*  f0fb804:	24500008 */ 	addiu	$s0,$v0,0x8
/*  f0fb808:	0c002f06 */ 	jal	viGetY
/*  f0fb80c:	a7a2003a */ 	sh	$v0,0x3a($sp)
/*  f0fb810:	87ae003a */ 	lh	$t6,0x3a($sp)
/*  f0fb814:	304903ff */ 	andi	$t1,$v0,0x3ff
/*  f0fb818:	8fa3005c */ 	lw	$v1,0x5c($sp)
/*  f0fb81c:	00095080 */ 	sll	$t2,$t1,0x2
/*  f0fb820:	3c01f600 */ 	lui	$at,0xf600
/*  f0fb824:	31cb03ff */ 	andi	$t3,$t6,0x3ff
/*  f0fb828:	000b7b80 */ 	sll	$t7,$t3,0xe
/*  f0fb82c:	01416025 */ 	or	$t4,$t2,$at
/*  f0fb830:	018f6825 */ 	or	$t5,$t4,$t7
/*  f0fb834:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fb838:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0fb83c:	0fc54e0e */ 	jal	func0f153838
/*  f0fb840:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f0fb844:	100000d0 */ 	b	.L0f0fbb88
/*  f0fb848:	00408025 */ 	or	$s0,$v0,$zero
/*  f0fb84c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0fb850:	44810000 */ 	mtc1	$at,$f0
/*  f0fb854:	3c01437f */ 	lui	$at,0x437f
/*  f0fb858:	44812000 */ 	mtc1	$at,$f4
/*  f0fb85c:	460c0481 */ 	sub.s	$f18,$f0,$f12
/*  f0fb860:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0fb864:	3c198006 */ 	lui	$t9,%hi(var800613a0)
/*  f0fb868:	273913a0 */ 	addiu	$t9,$t9,%lo(var800613a0)
/*  f0fb86c:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0fb870:	3c180600 */ 	lui	$t8,0x600
/*  f0fb874:	ae180000 */ 	sw	$t8,0x0($s0)
/*  f0fb878:	ae190004 */ 	sw	$t9,0x4($s0)
/*  f0fb87c:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f0fb880:	3c014f00 */ 	lui	$at,0x4f00
/*  f0fb884:	4448f800 */ 	cfc1	$t0,$31
/*  f0fb888:	44c6f800 */ 	ctc1	$a2,$31
/*  f0fb88c:	00000000 */ 	nop
/*  f0fb890:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0fb894:	4446f800 */ 	cfc1	$a2,$31
/*  f0fb898:	00000000 */ 	nop
/*  f0fb89c:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f0fb8a0:	50c00013 */ 	beqzl	$a2,.L0f0fb8f0
/*  f0fb8a4:	44064000 */ 	mfc1	$a2,$f8
/*  f0fb8a8:	44814000 */ 	mtc1	$at,$f8
/*  f0fb8ac:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0fb8b0:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0fb8b4:	44c6f800 */ 	ctc1	$a2,$31
/*  f0fb8b8:	00000000 */ 	nop
/*  f0fb8bc:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0fb8c0:	4446f800 */ 	cfc1	$a2,$31
/*  f0fb8c4:	00000000 */ 	nop
/*  f0fb8c8:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f0fb8cc:	14c00005 */ 	bnez	$a2,.L0f0fb8e4
/*  f0fb8d0:	00000000 */ 	nop
/*  f0fb8d4:	44064000 */ 	mfc1	$a2,$f8
/*  f0fb8d8:	3c018000 */ 	lui	$at,0x8000
/*  f0fb8dc:	10000007 */ 	b	.L0f0fb8fc
/*  f0fb8e0:	00c13025 */ 	or	$a2,$a2,$at
.L0f0fb8e4:
/*  f0fb8e4:	10000005 */ 	b	.L0f0fb8fc
/*  f0fb8e8:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0fb8ec:	44064000 */ 	mfc1	$a2,$f8
.L0f0fb8f0:
/*  f0fb8f0:	00000000 */ 	nop
/*  f0fb8f4:	04c0fffb */ 	bltz	$a2,.L0f0fb8e4
/*  f0fb8f8:	00000000 */ 	nop
.L0f0fb8fc:
/*  f0fb8fc:	00064e00 */ 	sll	$t1,$a2,0x18
/*  f0fb900:	00065400 */ 	sll	$t2,$a2,0x10
/*  f0fb904:	012a7025 */ 	or	$t6,$t1,$t2
/*  f0fb908:	00065a00 */ 	sll	$t3,$a2,0x8
/*  f0fb90c:	01cb2825 */ 	or	$a1,$t6,$t3
/*  f0fb910:	34ac00ff */ 	ori	$t4,$a1,0xff
/*  f0fb914:	44c8f800 */ 	ctc1	$t0,$31
/*  f0fb918:	0fc54df7 */ 	jal	func0f1537dc
/*  f0fb91c:	01802825 */ 	or	$a1,$t4,$zero
/*  f0fb920:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0fb924:	0c002f02 */ 	jal	viGetX
/*  f0fb928:	24500008 */ 	addiu	$s0,$v0,0x8
/*  f0fb92c:	0c002f06 */ 	jal	viGetY
/*  f0fb930:	a7a2003a */ 	sh	$v0,0x3a($sp)
/*  f0fb934:	87b9003a */ 	lh	$t9,0x3a($sp)
/*  f0fb938:	304f03ff */ 	andi	$t7,$v0,0x3ff
/*  f0fb93c:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0fb940:	000f6880 */ 	sll	$t5,$t7,0x2
/*  f0fb944:	3c01f600 */ 	lui	$at,0xf600
/*  f0fb948:	332803ff */ 	andi	$t0,$t9,0x3ff
/*  f0fb94c:	00084b80 */ 	sll	$t1,$t0,0xe
/*  f0fb950:	01a1c025 */ 	or	$t8,$t5,$at
/*  f0fb954:	03095025 */ 	or	$t2,$t8,$t1
/*  f0fb958:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fb95c:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f0fb960:	0fc54e0e */ 	jal	func0f153838
/*  f0fb964:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f0fb968:	0fc38e74 */ 	jal	func0f0e39d0
/*  f0fb96c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fb970:	10000085 */ 	b	.L0f0fbb88
/*  f0fb974:	00408025 */ 	or	$s0,$v0,$zero
/*  f0fb978:	3c047f1b */ 	lui	$a0,%hi(var7f1b2778)
/*  f0fb97c:	3c058007 */ 	lui	$a1,%hi(var800714ec)
/*  f0fb980:	24a514ec */ 	addiu	$a1,$a1,%lo(var800714ec)
/*  f0fb984:	24842778 */ 	addiu	$a0,$a0,%lo(var7f1b2778)
/*  f0fb988:	0c0036cc */ 	jal	func0000db30
/*  f0fb98c:	e7ac0088 */ 	swc1	$f12,0x88($sp)
/*  f0fb990:	3c0e800a */ 	lui	$t6,%hi(g_MenuData+0x16)
/*  f0fb994:	91ce19d6 */ 	lbu	$t6,%lo(g_MenuData+0x16)($t6)
/*  f0fb998:	3c0b8007 */ 	lui	$t3,%hi(var800714ec)
/*  f0fb99c:	11c00003 */ 	beqz	$t6,.L0f0fb9ac
/*  f0fb9a0:	00000000 */ 	nop
/*  f0fb9a4:	10000079 */ 	b	.L0f0fbb8c
/*  f0fb9a8:	02001025 */ 	or	$v0,$s0,$zero
.L0f0fb9ac:
/*  f0fb9ac:	8d6b14ec */ 	lw	$t3,%lo(var800714ec)($t3)
/*  f0fb9b0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fb9b4:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0fb9b8:	11600073 */ 	beqz	$t3,.L0f0fbb88
/*  f0fb9bc:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fb9c0:	0fc38266 */ 	jal	func0f0e0998
/*  f0fb9c4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0fb9c8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0fb9cc:	44810000 */ 	mtc1	$at,$f0
/*  f0fb9d0:	c7aa0088 */ 	lwc1	$f10,0x88($sp)
/*  f0fb9d4:	3c0f8006 */ 	lui	$t7,%hi(var800613a0)
/*  f0fb9d8:	00408025 */ 	or	$s0,$v0,$zero
/*  f0fb9dc:	4600503c */ 	c.lt.s	$f10,$f0
/*  f0fb9e0:	25ef13a0 */ 	addiu	$t7,$t7,%lo(var800613a0)
/*  f0fb9e4:	3c0c0600 */ 	lui	$t4,0x600
/*  f0fb9e8:	45020068 */ 	bc1fl	.L0f0fbb8c
/*  f0fb9ec:	02001025 */ 	or	$v0,$s0,$zero
/*  f0fb9f0:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0fb9f4:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0fb9f8:	c7b00088 */ 	lwc1	$f16,0x88($sp)
/*  f0fb9fc:	3c01437f */ 	lui	$at,0x437f
/*  f0fba00:	44812000 */ 	mtc1	$at,$f4
/*  f0fba04:	46100481 */ 	sub.s	$f18,$f0,$f16
/*  f0fba08:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0fba0c:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f0fba10:	3c014f00 */ 	lui	$at,0x4f00
/*  f0fba14:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0fba18:	444df800 */ 	cfc1	$t5,$31
/*  f0fba1c:	44c5f800 */ 	ctc1	$a1,$31
/*  f0fba20:	00000000 */ 	nop
/*  f0fba24:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0fba28:	4445f800 */ 	cfc1	$a1,$31
/*  f0fba2c:	00000000 */ 	nop
/*  f0fba30:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f0fba34:	50a00013 */ 	beqzl	$a1,.L0f0fba84
/*  f0fba38:	44054000 */ 	mfc1	$a1,$f8
/*  f0fba3c:	44814000 */ 	mtc1	$at,$f8
/*  f0fba40:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0fba44:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0fba48:	44c5f800 */ 	ctc1	$a1,$31
/*  f0fba4c:	00000000 */ 	nop
/*  f0fba50:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0fba54:	4445f800 */ 	cfc1	$a1,$31
/*  f0fba58:	00000000 */ 	nop
/*  f0fba5c:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f0fba60:	14a00005 */ 	bnez	$a1,.L0f0fba78
/*  f0fba64:	00000000 */ 	nop
/*  f0fba68:	44054000 */ 	mfc1	$a1,$f8
/*  f0fba6c:	3c018000 */ 	lui	$at,0x8000
/*  f0fba70:	10000007 */ 	b	.L0f0fba90
/*  f0fba74:	00a12825 */ 	or	$a1,$a1,$at
.L0f0fba78:
/*  f0fba78:	10000005 */ 	b	.L0f0fba90
/*  f0fba7c:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0fba80:	44054000 */ 	mfc1	$a1,$f8
.L0f0fba84:
/*  f0fba84:	00000000 */ 	nop
/*  f0fba88:	04a0fffb */ 	bltz	$a1,.L0f0fba78
/*  f0fba8c:	00000000 */ 	nop
.L0f0fba90:
/*  f0fba90:	3c01ff00 */ 	lui	$at,0xff00
/*  f0fba94:	00a1c825 */ 	or	$t9,$a1,$at
/*  f0fba98:	44cdf800 */ 	ctc1	$t5,$31
/*  f0fba9c:	0fc54df7 */ 	jal	func0f1537dc
/*  f0fbaa0:	03202825 */ 	or	$a1,$t9,$zero
/*  f0fbaa4:	afa2003c */ 	sw	$v0,0x3c($sp)
/*  f0fbaa8:	0c002f02 */ 	jal	viGetX
/*  f0fbaac:	24500008 */ 	addiu	$s0,$v0,0x8
/*  f0fbab0:	0c002f06 */ 	jal	viGetY
/*  f0fbab4:	a7a2003a */ 	sh	$v0,0x3a($sp)
/*  f0fbab8:	87aa003a */ 	lh	$t2,0x3a($sp)
/*  f0fbabc:	304803ff */ 	andi	$t0,$v0,0x3ff
/*  f0fbac0:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f0fbac4:	0008c080 */ 	sll	$t8,$t0,0x2
/*  f0fbac8:	3c01f600 */ 	lui	$at,0xf600
/*  f0fbacc:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f0fbad0:	000e5b80 */ 	sll	$t3,$t6,0xe
/*  f0fbad4:	03014825 */ 	or	$t1,$t8,$at
/*  f0fbad8:	012b6025 */ 	or	$t4,$t1,$t3
/*  f0fbadc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fbae0:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f0fbae4:	0fc54e0e */ 	jal	func0f153838
/*  f0fbae8:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f0fbaec:	10000026 */ 	b	.L0f0fbb88
/*  f0fbaf0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0fbaf4:	0c002f02 */ 	jal	viGetX
/*  f0fbaf8:	00000000 */ 	nop
/*  f0fbafc:	0c002f06 */ 	jal	viGetY
/*  f0fbb00:	a7a20038 */ 	sh	$v0,0x38($sp)
/*  f0fbb04:	3c198f00 */ 	lui	$t9,0x8f00
/*  f0fbb08:	373900ff */ 	ori	$t9,$t9,0xff
/*  f0fbb0c:	240f7f7f */ 	addiu	$t7,$zero,0x7f7f
/*  f0fbb10:	240d00ff */ 	addiu	$t5,$zero,0xff
/*  f0fbb14:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0fbb18:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0fbb1c:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0fbb20:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fbb24:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fbb28:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fbb2c:	87a70038 */ 	lh	$a3,0x38($sp)
/*  f0fbb30:	0fc3873a */ 	jal	func0f0e1ce8
/*  f0fbb34:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0fbb38:	10000013 */ 	b	.L0f0fbb88
/*  f0fbb3c:	00408025 */ 	or	$s0,$v0,$zero
/*  f0fbb40:	0c002f02 */ 	jal	viGetX
/*  f0fbb44:	00000000 */ 	nop
/*  f0fbb48:	0c002f06 */ 	jal	viGetY
/*  f0fbb4c:	a7a20038 */ 	sh	$v0,0x38($sp)
/*  f0fbb50:	3c033f3f */ 	lui	$v1,0x3f3f
/*  f0fbb54:	3c087f00 */ 	lui	$t0,0x7f00
/*  f0fbb58:	350800ff */ 	ori	$t0,$t0,0xff
/*  f0fbb5c:	346300ff */ 	ori	$v1,$v1,0xff
/*  f0fbb60:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0fbb64:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0fbb68:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0fbb6c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fbb70:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fbb74:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fbb78:	87a70038 */ 	lh	$a3,0x38($sp)
/*  f0fbb7c:	0fc3873a */ 	jal	func0f0e1ce8
/*  f0fbb80:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0fbb84:	00408025 */ 	or	$s0,$v0,$zero
.L0f0fbb88:
/*  f0fbb88:	02001025 */ 	or	$v0,$s0,$zero
.L0f0fbb8c:
/*  f0fbb8c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0fbb90:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0fbb94:	27bd0080 */ 	addiu	$sp,$sp,0x80
/*  f0fbb98:	03e00008 */ 	jr	$ra
/*  f0fbb9c:	00000000 */ 	nop
);

u32 var800714f0 = 1;

Gfx *func0f0fbba0(Gfx *gdl, u8 param_2, s32 arg2)
{
	if (param_2 == 4 || param_2 == 9) {
		func0000db30("cone", &var800714f0);

		if (var800714f0 && (g_MenuData.unk015 == 4 || g_MenuData.unk015 == 0 || g_MenuData.unk015 == 255)) {
			gdl = func0f0e4190(gdl);
		}
	}

	return gdl;
}

const char var7f1b2788[] = "usePiece";
const char var7f1b2794[] = "%s%s";
const char var7f1b279c[] = "%s%s";
const char var7f1b27a4[] = "Tune Selector - mode %d\n";

u32 var800714f4 = 0x00000001;

GLOBAL_ASM(
glabel func0f0fbc30
.late_rodata
glabel var7f1b2af8
.word 0xc34d8000
glabel var7f1b2afc
.word 0x4374b333
.text
/*  f0fbc30:	27bdfee8 */ 	addiu	$sp,$sp,-280
/*  f0fbc34:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0fbc38:	3c118007 */ 	lui	$s1,%hi(g_MpPlayerNum)
/*  f0fbc3c:	26311448 */ 	addiu	$s1,$s1,%lo(g_MpPlayerNum)
/*  f0fbc40:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f0fbc44:	3c0e8007 */ 	lui	$t6,%hi(g_HiResActive)
/*  f0fbc48:	8dce06c8 */ 	lw	$t6,%lo(g_HiResActive)($t6)
/*  f0fbc4c:	afb50048 */ 	sw	$s5,0x48($sp)
/*  f0fbc50:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0fbc54:	0080a825 */ 	or	$s5,$a0,$zero
/*  f0fbc58:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f0fbc5c:	afb70050 */ 	sw	$s7,0x50($sp)
/*  f0fbc60:	afb6004c */ 	sw	$s6,0x4c($sp)
/*  f0fbc64:	afb40044 */ 	sw	$s4,0x44($sp)
/*  f0fbc68:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f0fbc6c:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f0fbc70:	144e0005 */ 	bne	$v0,$t6,.L0f0fbc88
/*  f0fbc74:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0fbc78:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0fbc7c:	3c018008 */ 	lui	$at,%hi(g_ScreenWidthMultiplier)
/*  f0fbc80:	10000003 */ 	b	.L0f0fbc90
/*  f0fbc84:	ac2ffac0 */ 	sw	$t7,%lo(g_ScreenWidthMultiplier)($at)
.L0f0fbc88:
/*  f0fbc88:	3c018008 */ 	lui	$at,%hi(g_ScreenWidthMultiplier)
/*  f0fbc8c:	ac22fac0 */ 	sw	$v0,%lo(g_ScreenWidthMultiplier)($at)
.L0f0fbc90:
/*  f0fbc90:	0fc351e7 */ 	jal	func0f0d479c
/*  f0fbc94:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fbc98:	3c138006 */ 	lui	$s3,%hi(var800613a0)
/*  f0fbc9c:	3c17800a */ 	lui	$s7,%hi(g_MenuData)
/*  f0fbca0:	267313a0 */ 	addiu	$s3,$s3,%lo(var800613a0)
/*  f0fbca4:	3c180600 */ 	lui	$t8,0x600
/*  f0fbca8:	26f719c0 */ 	addiu	$s7,$s7,%lo(g_MenuData)
/*  f0fbcac:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0fbcb0:	ac530004 */ 	sw	$s3,0x4($v0)
/*  f0fbcb4:	92e30015 */ 	lbu	$v1,0x15($s7)
/*  f0fbcb8:	24550008 */ 	addiu	$s5,$v0,0x8
/*  f0fbcbc:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0fbcc0:	10610017 */ 	beq	$v1,$at,.L0f0fbd20
/*  f0fbcc4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fbcc8:	1460000c */ 	bnez	$v1,.L0f0fbcfc
/*  f0fbccc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fbcd0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0fbcd4:	44812000 */ 	mtc1	$at,$f4
/*  f0fbcd8:	c6e60010 */ 	lwc1	$f6,0x10($s7)
/*  f0fbcdc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fbce0:	92e50014 */ 	lbu	$a1,0x14($s7)
/*  f0fbce4:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0fbce8:	44064000 */ 	mfc1	$a2,$f8
/*  f0fbcec:	0fc3ed22 */ 	jal	func0f0fb488
/*  f0fbcf0:	00000000 */ 	nop
/*  f0fbcf4:	1000000e */ 	b	.L0f0fbd30
/*  f0fbcf8:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fbcfc:
/*  f0fbcfc:	92e50014 */ 	lbu	$a1,0x14($s7)
/*  f0fbd00:	0fc3ed22 */ 	jal	func0f0fb488
/*  f0fbd04:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0fbd08:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fbd0c:	92e50015 */ 	lbu	$a1,0x15($s7)
/*  f0fbd10:	0fc3ed22 */ 	jal	func0f0fb488
/*  f0fbd14:	8ee60010 */ 	lw	$a2,0x10($s7)
/*  f0fbd18:	10000005 */ 	b	.L0f0fbd30
/*  f0fbd1c:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fbd20:
/*  f0fbd20:	92e50014 */ 	lbu	$a1,0x14($s7)
/*  f0fbd24:	0fc3ed22 */ 	jal	func0f0fb488
/*  f0fbd28:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0fbd2c:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fbd30:
/*  f0fbd30:	8ef905d4 */ 	lw	$t9,0x5d4($s7)
/*  f0fbd34:	240c040d */ 	addiu	$t4,$zero,0x40d
/*  f0fbd38:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fbd3c:	00195b00 */ 	sll	$t3,$t9,0xc
/*  f0fbd40:	0561000b */ 	bgez	$t3,.L0f0fbd70
/*  f0fbd44:	3c0a8009 */ 	lui	$t2,%hi(g_Is4Mb)
/*  f0fbd48:	92ed05cd */ 	lbu	$t5,0x5cd($s7)
/*  f0fbd4c:	92f805d5 */ 	lbu	$t8,0x5d5($s7)
/*  f0fbd50:	a6e0007a */ 	sh	$zero,0x7a($s7)
/*  f0fbd54:	31aeffef */ 	andi	$t6,$t5,0xffef
/*  f0fbd58:	3319fff7 */ 	andi	$t9,$t8,0xfff7
/*  f0fbd5c:	a6ec0078 */ 	sh	$t4,0x78($s7)
/*  f0fbd60:	aee0059c */ 	sw	$zero,0x59c($s7)
/*  f0fbd64:	a2ee05cd */ 	sb	$t6,0x5cd($s7)
/*  f0fbd68:	a2ef05d4 */ 	sb	$t7,0x5d4($s7)
/*  f0fbd6c:	a2f905d5 */ 	sb	$t9,0x5d5($s7)
.L0f0fbd70:
/*  f0fbd70:	914a0af0 */ 	lbu	$t2,%lo(g_Is4Mb)($t2)
/*  f0fbd74:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fbd78:	114100ab */ 	beq	$t2,$at,.L0f0fc028
/*  f0fbd7c:	00000000 */ 	nop
/*  f0fbd80:	92eb05d4 */ 	lbu	$t3,0x5d4($s7)
/*  f0fbd84:	02a01025 */ 	or	$v0,$s5,$zero
/*  f0fbd88:	3c0cb700 */ 	lui	$t4,0xb700
/*  f0fbd8c:	116000a6 */ 	beqz	$t3,.L0f0fc028
/*  f0fbd90:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0fbd94:	00008025 */ 	or	$s0,$zero,$zero
/*  f0fbd98:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f0fbd9c:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0fbda0:	0c004b70 */ 	jal	random
/*  f0fbda4:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f0fbda8:	44825000 */ 	mtc1	$v0,$f10
/*  f0fbdac:	3c014f80 */ 	lui	$at,0x4f80
/*  f0fbdb0:	04410004 */ 	bgez	$v0,.L0f0fbdc4
/*  f0fbdb4:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0fbdb8:	44819000 */ 	mtc1	$at,$f18
/*  f0fbdbc:	00000000 */ 	nop
/*  f0fbdc0:	46128400 */ 	add.s	$f16,$f16,$f18
.L0f0fbdc4:
/*  f0fbdc4:	3c012f80 */ 	lui	$at,0x2f80
/*  f0fbdc8:	44812000 */ 	mtc1	$at,$f4
/*  f0fbdcc:	3c017f1b */ 	lui	$at,%hi(var7f1b2af0)
/*  f0fbdd0:	d42a2af0 */ 	ldc1	$f10,%lo(var7f1b2af0)($at)
/*  f0fbdd4:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f0fbdd8:	46003221 */ 	cvt.d.s	$f8,$f6
/*  f0fbddc:	462a403c */ 	c.lt.d	$f8,$f10
/*  f0fbde0:	00000000 */ 	nop
/*  f0fbde4:	4502002d */ 	bc1fl	.L0f0fbe9c
/*  f0fbde8:	8ee30004 */ 	lw	$v1,0x4($s7)
/*  f0fbdec:	0c004b70 */ 	jal	random
/*  f0fbdf0:	00000000 */ 	nop
/*  f0fbdf4:	44829000 */ 	mtc1	$v0,$f18
/*  f0fbdf8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0fbdfc:	04410004 */ 	bgez	$v0,.L0f0fbe10
/*  f0fbe00:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f0fbe04:	44812000 */ 	mtc1	$at,$f4
/*  f0fbe08:	00000000 */ 	nop
/*  f0fbe0c:	46048400 */ 	add.s	$f16,$f16,$f4
.L0f0fbe10:
/*  f0fbe10:	3c012f80 */ 	lui	$at,0x2f80
/*  f0fbe14:	44813000 */ 	mtc1	$at,$f6
/*  f0fbe18:	3c0142a0 */ 	lui	$at,0x42a0
/*  f0fbe1c:	44815000 */ 	mtc1	$at,$f10
/*  f0fbe20:	46068202 */ 	mul.s	$f8,$f16,$f6
/*  f0fbe24:	3c017f1b */ 	lui	$at,%hi(var7f1b2af8)
/*  f0fbe28:	c4242af8 */ 	lwc1	$f4,%lo(var7f1b2af8)($at)
/*  f0fbe2c:	3c014220 */ 	lui	$at,0x4220
/*  f0fbe30:	44813000 */ 	mtc1	$at,$f6
/*  f0fbe34:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f0fbe38:	46049400 */ 	add.s	$f16,$f18,$f4
/*  f0fbe3c:	46068201 */ 	sub.s	$f8,$f16,$f6
/*  f0fbe40:	0c004b70 */ 	jal	random
/*  f0fbe44:	e6e80554 */ 	swc1	$f8,0x554($s7)
/*  f0fbe48:	44825000 */ 	mtc1	$v0,$f10
/*  f0fbe4c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0fbe50:	04410004 */ 	bgez	$v0,.L0f0fbe64
/*  f0fbe54:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f0fbe58:	44812000 */ 	mtc1	$at,$f4
/*  f0fbe5c:	00000000 */ 	nop
/*  f0fbe60:	46049480 */ 	add.s	$f18,$f18,$f4
.L0f0fbe64:
/*  f0fbe64:	3c012f80 */ 	lui	$at,0x2f80
/*  f0fbe68:	44818000 */ 	mtc1	$at,$f16
/*  f0fbe6c:	3c0142a0 */ 	lui	$at,0x42a0
/*  f0fbe70:	44814000 */ 	mtc1	$at,$f8
/*  f0fbe74:	46109182 */ 	mul.s	$f6,$f18,$f16
/*  f0fbe78:	3c017f1b */ 	lui	$at,%hi(var7f1b2afc)
/*  f0fbe7c:	c4242afc */ 	lwc1	$f4,%lo(var7f1b2afc)($at)
/*  f0fbe80:	3c014220 */ 	lui	$at,0x4220
/*  f0fbe84:	44818000 */ 	mtc1	$at,$f16
/*  f0fbe88:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0fbe8c:	46045480 */ 	add.s	$f18,$f10,$f4
/*  f0fbe90:	46109181 */ 	sub.s	$f6,$f18,$f16
/*  f0fbe94:	e6e60558 */ 	swc1	$f6,0x558($s7)
/*  f0fbe98:	8ee30004 */ 	lw	$v1,0x4($s7)
.L0f0fbe9c:
/*  f0fbe9c:	3c12800a */ 	lui	$s2,%hi(var8009de9c)
/*  f0fbea0:	3c14800a */ 	lui	$s4,%hi(var8009de98)
/*  f0fbea4:	2694de98 */ 	addiu	$s4,$s4,%lo(var8009de98)
/*  f0fbea8:	2652de9c */ 	addiu	$s2,$s2,%lo(var8009de9c)
/*  f0fbeac:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f0fbeb0:	ae400000 */ 	sw	$zero,0x0($s2)
/*  f0fbeb4:	14c30005 */ 	bne	$a2,$v1,.L0f0fbecc
/*  f0fbeb8:	ae800000 */ 	sw	$zero,0x0($s4)
/*  f0fbebc:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f0fbec0:	5de00003 */ 	bgtzl	$t7,.L0f0fbed0
/*  f0fbec4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0fbec8:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0fbecc:
/*  f0fbecc:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0fbed0:
/*  f0fbed0:	10610008 */ 	beq	$v1,$at,.L0f0fbef4
/*  f0fbed4:	3c16800a */ 	lui	$s6,%hi(g_Vars)
/*  f0fbed8:	10c30006 */ 	beq	$a2,$v1,.L0f0fbef4
/*  f0fbedc:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0fbee0:	10610004 */ 	beq	$v1,$at,.L0f0fbef4
/*  f0fbee4:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0fbee8:	50610003 */ 	beql	$v1,$at,.L0f0fbef8
/*  f0fbeec:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0fbef0:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0fbef4:
/*  f0fbef4:	8e380000 */ 	lw	$t8,0x0($s1)
.L0f0fbef8:
/*  f0fbef8:	3c0a800a */ 	lui	$t2,%hi(g_Menus+0x4f8)
/*  f0fbefc:	3c047f1b */ 	lui	$a0,%hi(var7f1b2788)
/*  f0fbf00:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0fbf04:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0fbf08:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0fbf0c:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0fbf10:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fbf14:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0fbf18:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0fbf1c:	01595021 */ 	addu	$t2,$t2,$t9
/*  f0fbf20:	8d4ae4f8 */ 	lw	$t2,%lo(g_Menus+0x4f8)($t2)
/*  f0fbf24:	26d69fc0 */ 	addiu	$s6,$s6,%lo(g_Vars)
/*  f0fbf28:	24842788 */ 	addiu	$a0,$a0,%lo(var7f1b2788)
/*  f0fbf2c:	15400004 */ 	bnez	$t2,.L0f0fbf40
/*  f0fbf30:	3c058007 */ 	lui	$a1,%hi(var800714f4)
/*  f0fbf34:	50c30003 */ 	beql	$a2,$v1,.L0f0fbf44
/*  f0fbf38:	8ec30284 */ 	lw	$v1,0x284($s6)
/*  f0fbf3c:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0fbf40:
/*  f0fbf40:	8ec30284 */ 	lw	$v1,0x284($s6)
.L0f0fbf44:
/*  f0fbf44:	8c620480 */ 	lw	$v0,0x480($v1)
/*  f0fbf48:	1040000c */ 	beqz	$v0,.L0f0fbf7c
/*  f0fbf4c:	00000000 */ 	nop
/*  f0fbf50:	8c6c1c54 */ 	lw	$t4,0x1c54($v1)
/*  f0fbf54:	8c6b00c4 */ 	lw	$t3,0xc4($v1)
/*  f0fbf58:	01806827 */ 	nor	$t5,$t4,$zero
/*  f0fbf5c:	016d7024 */ 	and	$t6,$t3,$t5
/*  f0fbf60:	31cf0004 */ 	andi	$t7,$t6,0x4
/*  f0fbf64:	11e00005 */ 	beqz	$t7,.L0f0fbf7c
/*  f0fbf68:	00000000 */ 	nop
/*  f0fbf6c:	80580037 */ 	lb	$t8,0x37($v0)
/*  f0fbf70:	13000002 */ 	beqz	$t8,.L0f0fbf7c
/*  f0fbf74:	00000000 */ 	nop
/*  f0fbf78:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0fbf7c:
/*  f0fbf7c:	12000012 */ 	beqz	$s0,.L0f0fbfc8
/*  f0fbf80:	00000000 */ 	nop
/*  f0fbf84:	8ef9059c */ 	lw	$t9,0x59c($s7)
/*  f0fbf88:	240d040d */ 	addiu	$t5,$zero,0x40d
/*  f0fbf8c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0fbf90:	57200009 */ 	bnezl	$t9,.L0f0fbfb8
/*  f0fbf94:	86ef007a */ 	lh	$t7,0x7a($s7)
/*  f0fbf98:	92ec05cd */ 	lbu	$t4,0x5cd($s7)
/*  f0fbf9c:	a6e0007a */ 	sh	$zero,0x7a($s7)
/*  f0fbfa0:	a6ed0078 */ 	sh	$t5,0x78($s7)
/*  f0fbfa4:	358b0010 */ 	ori	$t3,$t4,0x10
/*  f0fbfa8:	a2eb05cd */ 	sb	$t3,0x5cd($s7)
/*  f0fbfac:	10000006 */ 	b	.L0f0fbfc8
/*  f0fbfb0:	aeee059c */ 	sw	$t6,0x59c($s7)
/*  f0fbfb4:	86ef007a */ 	lh	$t7,0x7a($s7)
.L0f0fbfb8:
/*  f0fbfb8:	15e00003 */ 	bnez	$t7,.L0f0fbfc8
/*  f0fbfbc:	00000000 */ 	nop
/*  f0fbfc0:	aee0059c */ 	sw	$zero,0x59c($s7)
/*  f0fbfc4:	a2e005d4 */ 	sb	$zero,0x5d4($s7)
.L0f0fbfc8:
/*  f0fbfc8:	0c0036cc */ 	jal	func0000db30
/*  f0fbfcc:	24a514f4 */ 	addiu	$a1,$a1,%lo(var800714f4)
/*  f0fbfd0:	3c188007 */ 	lui	$t8,%hi(var800714f4)
/*  f0fbfd4:	8f1814f4 */ 	lw	$t8,%lo(var800714f4)($t8)
/*  f0fbfd8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fbfdc:	3c05800a */ 	lui	$a1,%hi(g_MenuData+0x1c)
/*  f0fbfe0:	1300000f */ 	beqz	$t8,.L0f0fc020
/*  f0fbfe4:	00000000 */ 	nop
/*  f0fbfe8:	92f905d5 */ 	lbu	$t9,0x5d5($s7)
/*  f0fbfec:	24a519dc */ 	addiu	$a1,$a1,%lo(g_MenuData+0x1c)
/*  f0fbff0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0fbff4:	332affdf */ 	andi	$t2,$t9,0xffdf
/*  f0fbff8:	0fc3ce2c */ 	jal	func0f0f38b0
/*  f0fbffc:	a2ea05d5 */ 	sb	$t2,0x5d5($s7)
/*  f0fc000:	3c0cb600 */ 	lui	$t4,0xb600
/*  f0fc004:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0fc008:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f0fc00c:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0fc010:	92ee05d5 */ 	lbu	$t6,0x5d5($s7)
/*  f0fc014:	24550008 */ 	addiu	$s5,$v0,0x8
/*  f0fc018:	35cf0020 */ 	ori	$t7,$t6,0x20
/*  f0fc01c:	a2ef05d5 */ 	sb	$t7,0x5d5($s7)
.L0f0fc020:
/*  f0fc020:	1000000a */ 	b	.L0f0fc04c
/*  f0fc024:	8ee205d4 */ 	lw	$v0,0x5d4($s7)
.L0f0fc028:
/*  f0fc028:	3c12800a */ 	lui	$s2,%hi(var8009de9c)
/*  f0fc02c:	3c14800a */ 	lui	$s4,%hi(var8009de98)
/*  f0fc030:	2694de98 */ 	addiu	$s4,$s4,%lo(var8009de98)
/*  f0fc034:	2652de9c */ 	addiu	$s2,$s2,%lo(var8009de9c)
/*  f0fc038:	3c16800a */ 	lui	$s6,%hi(g_Vars)
/*  f0fc03c:	26d69fc0 */ 	addiu	$s6,$s6,%lo(g_Vars)
/*  f0fc040:	ae400000 */ 	sw	$zero,0x0($s2)
/*  f0fc044:	ae800000 */ 	sw	$zero,0x0($s4)
/*  f0fc048:	8ee205d4 */ 	lw	$v0,0x5d4($s7)
.L0f0fc04c:
/*  f0fc04c:	000252c0 */ 	sll	$t2,$v0,0xb
/*  f0fc050:	05410005 */ 	bgez	$t2,.L0f0fc068
/*  f0fc054:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc058:	8eec0670 */ 	lw	$t4,0x670($s7)
/*  f0fc05c:	8eeb0674 */ 	lw	$t3,0x674($s7)
/*  f0fc060:	ae8c0000 */ 	sw	$t4,0x0($s4)
/*  f0fc064:	ae4b0000 */ 	sw	$t3,0x0($s2)
.L0f0fc068:
/*  f0fc068:	92e30015 */ 	lbu	$v1,0x15($s7)
/*  f0fc06c:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0fc070:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0fc074:	10610017 */ 	beq	$v1,$at,.L0f0fc0d4
/*  f0fc078:	00000000 */ 	nop
/*  f0fc07c:	1460000c */ 	bnez	$v1,.L0f0fc0b0
/*  f0fc080:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc084:	3c013f80 */ 	lui	$at,0x3f80
/*  f0fc088:	44814000 */ 	mtc1	$at,$f8
/*  f0fc08c:	c6ea0010 */ 	lwc1	$f10,0x10($s7)
/*  f0fc090:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc094:	92e50014 */ 	lbu	$a1,0x14($s7)
/*  f0fc098:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f0fc09c:	44062000 */ 	mfc1	$a2,$f4
/*  f0fc0a0:	0fc3eee8 */ 	jal	func0f0fbba0
/*  f0fc0a4:	00000000 */ 	nop
/*  f0fc0a8:	1000000d */ 	b	.L0f0fc0e0
/*  f0fc0ac:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fc0b0:
/*  f0fc0b0:	92e50014 */ 	lbu	$a1,0x14($s7)
/*  f0fc0b4:	0fc3eee8 */ 	jal	func0f0fbba0
/*  f0fc0b8:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0fc0bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fc0c0:	92e50015 */ 	lbu	$a1,0x15($s7)
/*  f0fc0c4:	0fc3eee8 */ 	jal	func0f0fbba0
/*  f0fc0c8:	8ee60010 */ 	lw	$a2,0x10($s7)
/*  f0fc0cc:	10000004 */ 	b	.L0f0fc0e0
/*  f0fc0d0:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fc0d4:
/*  f0fc0d4:	0fc3eee8 */ 	jal	func0f0fbba0
/*  f0fc0d8:	92e50014 */ 	lbu	$a1,0x14($s7)
/*  f0fc0dc:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fc0e0:
/*  f0fc0e0:	92ed0014 */ 	lbu	$t5,0x14($s7)
/*  f0fc0e4:	55a00006 */ 	bnezl	$t5,.L0f0fc100
/*  f0fc0e8:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f0fc0ec:	92ee0015 */ 	lbu	$t6,0x15($s7)
/*  f0fc0f0:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0fc0f4:	51c10010 */ 	beql	$t6,$at,.L0f0fc138
/*  f0fc0f8:	8ef90000 */ 	lw	$t9,0x0($s7)
/*  f0fc0fc:	8ecf0284 */ 	lw	$t7,0x284($s6)
.L0f0fc100:
/*  f0fc100:	8de20480 */ 	lw	$v0,0x480($t7)
/*  f0fc104:	10400004 */ 	beqz	$v0,.L0f0fc118
/*  f0fc108:	00000000 */ 	nop
/*  f0fc10c:	80580037 */ 	lb	$t8,0x37($v0)
/*  f0fc110:	57000009 */ 	bnezl	$t8,.L0f0fc138
/*  f0fc114:	8ef90000 */ 	lw	$t9,0x0($s7)
.L0f0fc118:
/*  f0fc118:	0fc35272 */ 	jal	func0f0d49c8
/*  f0fc11c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc120:	0fc2efde */ 	jal	hudRenderHealthBar
/*  f0fc124:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fc128:	0fc351e7 */ 	jal	func0f0d479c
/*  f0fc12c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fc130:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0fc134:	8ef90000 */ 	lw	$t9,0x0($s7)
.L0f0fc138:
/*  f0fc138:	5b20017b */ 	blezl	$t9,.L0f0fc728
/*  f0fc13c:	82f8001b */ 	lb	$t8,0x1b($s7)
/*  f0fc140:	0fc54eac */ 	jal	func0f153ab0
/*  f0fc144:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc148:	8ee30004 */ 	lw	$v1,0x4($s7)
/*  f0fc14c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0fc150:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0fc154:	10610003 */ 	beq	$v1,$at,.L0f0fc164
/*  f0fc158:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0fc15c:	14610008 */ 	bne	$v1,$at,.L0f0fc180
/*  f0fc160:	00008025 */ 	or	$s0,$zero,$zero
.L0f0fc164:
/*  f0fc164:	8eca0288 */ 	lw	$t2,0x288($s6)
/*  f0fc168:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc16c:	8d4c0070 */ 	lw	$t4,0x70($t2)
/*  f0fc170:	0fc3e1aa */ 	jal	func0f0f86a8
/*  f0fc174:	ae2c0000 */ 	sw	$t4,0x0($s1)
/*  f0fc178:	10000008 */ 	b	.L0f0fc19c
/*  f0fc17c:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fc180:
/*  f0fc180:	ae300000 */ 	sw	$s0,0x0($s1)
/*  f0fc184:	0fc3e1aa */ 	jal	func0f0f86a8
/*  f0fc188:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc18c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0fc190:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0fc194:	1601fffa */ 	bne	$s0,$at,.L0f0fc180
/*  f0fc198:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fc19c:
/*  f0fc19c:	3c0b0103 */ 	lui	$t3,0x103
/*  f0fc1a0:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f0fc1a4:	356b0040 */ 	ori	$t3,$t3,0x40
/*  f0fc1a8:	02a08025 */ 	or	$s0,$s5,$zero
/*  f0fc1ac:	ae0b0000 */ 	sw	$t3,0x0($s0)
/*  f0fc1b0:	0fc2d3fa */ 	jal	currentPlayerGetUnk1750
/*  f0fc1b4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f0fc1b8:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0fc1bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fc1c0:	02a01825 */ 	or	$v1,$s5,$zero
/*  f0fc1c4:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f0fc1c8:	3c0d0600 */ 	lui	$t5,0x600
/*  f0fc1cc:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0fc1d0:	ac730004 */ 	sw	$s3,0x4($v1)
/*  f0fc1d4:	0fc54ed0 */ 	jal	func0f153b40
/*  f0fc1d8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f0fc1dc:	8ee30004 */ 	lw	$v1,0x4($s7)
/*  f0fc1e0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0fc1e4:	10610003 */ 	beq	$v1,$at,.L0f0fc1f4
/*  f0fc1e8:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0fc1ec:	54610148 */ 	bnel	$v1,$at,.L0f0fc710
/*  f0fc1f0:	02a01025 */ 	or	$v0,$s5,$zero
.L0f0fc1f4:
/*  f0fc1f4:	0c002f40 */ 	jal	viGetViewLeft
/*  f0fc1f8:	00000000 */ 	nop
/*  f0fc1fc:	3c0e8008 */ 	lui	$t6,%hi(g_ScreenWidthMultiplier)
/*  f0fc200:	8dcefac0 */ 	lw	$t6,%lo(g_ScreenWidthMultiplier)($t6)
/*  f0fc204:	004e001a */ 	div	$zero,$v0,$t6
/*  f0fc208:	00007812 */ 	mflo	$t7
/*  f0fc20c:	25f80014 */ 	addiu	$t8,$t7,0x14
/*  f0fc210:	15c00002 */ 	bnez	$t6,.L0f0fc21c
/*  f0fc214:	00000000 */ 	nop
/*  f0fc218:	0007000d */ 	break	0x7
.L0f0fc21c:
/*  f0fc21c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fc220:	15c10004 */ 	bne	$t6,$at,.L0f0fc234
/*  f0fc224:	3c018000 */ 	lui	$at,0x8000
/*  f0fc228:	14410002 */ 	bne	$v0,$at,.L0f0fc234
/*  f0fc22c:	00000000 */ 	nop
/*  f0fc230:	0006000d */ 	break	0x6
.L0f0fc234:
/*  f0fc234:	afb800f0 */ 	sw	$t8,0xf0($sp)
/*  f0fc238:	0c002f44 */ 	jal	viGetViewTop
/*  f0fc23c:	00000000 */ 	nop
/*  f0fc240:	24590004 */ 	addiu	$t9,$v0,0x4
/*  f0fc244:	0c002f40 */ 	jal	viGetViewLeft
/*  f0fc248:	afb900ec */ 	sw	$t9,0xec($sp)
/*  f0fc24c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0fc250:	00105403 */ 	sra	$t2,$s0,0x10
/*  f0fc254:	0c002f22 */ 	jal	viGetViewX
/*  f0fc258:	01408025 */ 	or	$s0,$t2,$zero
/*  f0fc25c:	3c0b8008 */ 	lui	$t3,%hi(g_ScreenWidthMultiplier)
/*  f0fc260:	8d6bfac0 */ 	lw	$t3,%lo(g_ScreenWidthMultiplier)($t3)
/*  f0fc264:	00506021 */ 	addu	$t4,$v0,$s0
/*  f0fc268:	018b001a */ 	div	$zero,$t4,$t3
/*  f0fc26c:	00006812 */ 	mflo	$t5
/*  f0fc270:	25aeffec */ 	addiu	$t6,$t5,-20
/*  f0fc274:	15600002 */ 	bnez	$t3,.L0f0fc280
/*  f0fc278:	00000000 */ 	nop
/*  f0fc27c:	0007000d */ 	break	0x7
.L0f0fc280:
/*  f0fc280:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fc284:	15610004 */ 	bne	$t3,$at,.L0f0fc298
/*  f0fc288:	3c018000 */ 	lui	$at,0x8000
/*  f0fc28c:	15810002 */ 	bne	$t4,$at,.L0f0fc298
/*  f0fc290:	00000000 */ 	nop
/*  f0fc294:	0006000d */ 	break	0x6
.L0f0fc298:
/*  f0fc298:	afae00e8 */ 	sw	$t6,0xe8($sp)
/*  f0fc29c:	0c002f44 */ 	jal	viGetViewTop
/*  f0fc2a0:	00000000 */ 	nop
/*  f0fc2a4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0fc2a8:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f0fc2ac:	0c002f26 */ 	jal	viGetViewY
/*  f0fc2b0:	01e08025 */ 	or	$s0,$t7,$zero
/*  f0fc2b4:	0050c021 */ 	addu	$t8,$v0,$s0
/*  f0fc2b8:	2719fffc */ 	addiu	$t9,$t8,-4
/*  f0fc2bc:	afb900e4 */ 	sw	$t9,0xe4($sp)
/*  f0fc2c0:	0fc54d8a */ 	jal	func0f153628
/*  f0fc2c4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc2c8:	3c13800a */ 	lui	$s3,%hi(g_Vars+0x4)
/*  f0fc2cc:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0fc2d0:	26739fc4 */ 	addiu	$s3,$s3,%lo(g_Vars+0x4)
/*  f0fc2d4:	00009025 */ 	or	$s2,$zero,$zero
/*  f0fc2d8:	27b400b8 */ 	addiu	$s4,$sp,0xb8
/*  f0fc2dc:	8ec20490 */ 	lw	$v0,0x490($s6)
.L0f0fc2e0:
/*  f0fc2e0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0fc2e4:	02d25021 */ 	addu	$t2,$s6,$s2
/*  f0fc2e8:	54410013 */ 	bnel	$v0,$at,.L0f0fc338
/*  f0fc2ec:	8eeb0004 */ 	lw	$t3,0x4($s7)
/*  f0fc2f0:	814c0494 */ 	lb	$t4,0x494($t2)
/*  f0fc2f4:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0fc2f8:	5180000f */ 	beqzl	$t4,.L0f0fc338
/*  f0fc2fc:	8eeb0004 */ 	lw	$t3,0x4($s7)
/*  f0fc300:	0fc5b9f1 */ 	jal	langGet
/*  f0fc304:	240451e2 */ 	addiu	$a0,$zero,0x51e2
/*  f0fc308:	00408825 */ 	or	$s1,$v0,$zero
/*  f0fc30c:	0fc5b9f1 */ 	jal	langGet
/*  f0fc310:	240459cd */ 	addiu	$a0,$zero,0x59cd
/*  f0fc314:	3c057f1b */ 	lui	$a1,%hi(var7f1b2794)
/*  f0fc318:	24a52794 */ 	addiu	$a1,$a1,%lo(var7f1b2794)
/*  f0fc31c:	02802025 */ 	or	$a0,$s4,$zero
/*  f0fc320:	02203025 */ 	or	$a2,$s1,$zero
/*  f0fc324:	0c004dad */ 	jal	sprintf
/*  f0fc328:	00403825 */ 	or	$a3,$v0,$zero
/*  f0fc32c:	10000023 */ 	b	.L0f0fc3bc
/*  f0fc330:	00000000 */ 	nop
/*  f0fc334:	8eeb0004 */ 	lw	$t3,0x4($s7)
.L0f0fc338:
/*  f0fc338:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0fc33c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0fc340:	15610013 */ 	bne	$t3,$at,.L0f0fc390
/*  f0fc344:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0fc348:	1441000d */ 	bne	$v0,$at,.L0f0fc380
/*  f0fc34c:	3c108007 */ 	lui	$s0,%hi(var800714d8)
/*  f0fc350:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0fc354:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0fc358:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0fc35c:	804d0494 */ 	lb	$t5,0x494($v0)
.L0f0fc360:
/*  f0fc360:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0fc364:	11a00002 */ 	beqz	$t5,.L0f0fc370
/*  f0fc368:	00000000 */ 	nop
/*  f0fc36c:	00008025 */ 	or	$s0,$zero,$zero
.L0f0fc370:
/*  f0fc370:	5453fffb */ 	bnel	$v0,$s3,.L0f0fc360
/*  f0fc374:	804d0494 */ 	lb	$t5,0x494($v0)
/*  f0fc378:	10000005 */ 	b	.L0f0fc390
/*  f0fc37c:	00000000 */ 	nop
.L0f0fc380:
/*  f0fc380:	8e1014d8 */ 	lw	$s0,%lo(var800714d8)($s0)
/*  f0fc384:	2e0e0002 */ 	sltiu	$t6,$s0,0x2
/*  f0fc388:	10000001 */ 	b	.L0f0fc390
/*  f0fc38c:	01c08025 */ 	or	$s0,$t6,$zero
.L0f0fc390:
/*  f0fc390:	0fc5b9f1 */ 	jal	langGet
/*  f0fc394:	240451e2 */ 	addiu	$a0,$zero,0x51e2
/*  f0fc398:	00408825 */ 	or	$s1,$v0,$zero
/*  f0fc39c:	0fc5b9f1 */ 	jal	langGet
/*  f0fc3a0:	240451e3 */ 	addiu	$a0,$zero,0x51e3
/*  f0fc3a4:	3c057f1b */ 	lui	$a1,%hi(var7f1b279c)
/*  f0fc3a8:	24a5279c */ 	addiu	$a1,$a1,%lo(var7f1b279c)
/*  f0fc3ac:	02802025 */ 	or	$a0,$s4,$zero
/*  f0fc3b0:	02203025 */ 	or	$a2,$s1,$zero
/*  f0fc3b4:	0c004dad */ 	jal	sprintf
/*  f0fc3b8:	00403825 */ 	or	$a3,$v0,$zero
.L0f0fc3bc:
/*  f0fc3bc:	120000cc */ 	beqz	$s0,.L0f0fc6f0
/*  f0fc3c0:	27a400e0 */ 	addiu	$a0,$sp,0xe0
/*  f0fc3c4:	3c0f8008 */ 	lui	$t7,%hi(var8007fb0c)
/*  f0fc3c8:	8deffb0c */ 	lw	$t7,%lo(var8007fb0c)($t7)
/*  f0fc3cc:	3c078008 */ 	lui	$a3,%hi(var8007fb10)
/*  f0fc3d0:	8ce7fb10 */ 	lw	$a3,%lo(var8007fb10)($a3)
/*  f0fc3d4:	27a500dc */ 	addiu	$a1,$sp,0xdc
/*  f0fc3d8:	02803025 */ 	or	$a2,$s4,$zero
/*  f0fc3dc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0fc3e0:	02f28821 */ 	addu	$s1,$s7,$s2
/*  f0fc3e4:	0fc55cbe */ 	jal	textMeasure
/*  f0fc3e8:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0fc3ec:	0c005013 */ 	jal	getConnectedControllers
/*  f0fc3f0:	00000000 */ 	nop
/*  f0fc3f4:	3c19800b */ 	lui	$t9,%hi(g_MpSetup+0x16)
/*  f0fc3f8:	9739cb9e */ 	lhu	$t9,%lo(g_MpSetup+0x16)($t9)
/*  f0fc3fc:	0040c027 */ 	nor	$t8,$v0,$zero
/*  f0fc400:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0fc404:	024c5804 */ 	sllv	$t3,$t4,$s2
/*  f0fc408:	03195025 */ 	or	$t2,$t8,$t9
/*  f0fc40c:	014b6824 */ 	and	$t5,$t2,$t3
/*  f0fc410:	55a00014 */ 	bnezl	$t5,.L0f0fc464
/*  f0fc414:	8ec30000 */ 	lw	$v1,0x0($s6)
/*  f0fc418:	8ec30000 */ 	lw	$v1,0x0($s6)
/*  f0fc41c:	92220017 */ 	lbu	$v0,0x17($s1)
/*  f0fc420:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f0fc424:	00037080 */ 	sll	$t6,$v1,0x2
/*  f0fc428:	284100ff */ 	slti	$at,$v0,0xff
/*  f0fc42c:	10200019 */ 	beqz	$at,.L0f0fc494
/*  f0fc430:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f0fc434:	01e2c023 */ 	subu	$t8,$t7,$v0
/*  f0fc438:	01d8082a */ 	slt	$at,$t6,$t8
/*  f0fc43c:	10200005 */ 	beqz	$at,.L0f0fc454
/*  f0fc440:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f0fc444:	004ec821 */ 	addu	$t9,$v0,$t6
/*  f0fc448:	a2390017 */ 	sb	$t9,0x17($s1)
/*  f0fc44c:	10000011 */ 	b	.L0f0fc494
/*  f0fc450:	332200ff */ 	andi	$v0,$t9,0xff
.L0f0fc454:
/*  f0fc454:	a22c0017 */ 	sb	$t4,0x17($s1)
/*  f0fc458:	1000000e */ 	b	.L0f0fc494
/*  f0fc45c:	318200ff */ 	andi	$v0,$t4,0xff
/*  f0fc460:	8ec30000 */ 	lw	$v1,0x0($s6)
.L0f0fc464:
/*  f0fc464:	92220017 */ 	lbu	$v0,0x17($s1)
/*  f0fc468:	000350c0 */ 	sll	$t2,$v1,0x3
/*  f0fc46c:	18400009 */ 	blez	$v0,.L0f0fc494
/*  f0fc470:	01435021 */ 	addu	$t2,$t2,$v1
/*  f0fc474:	0142082a */ 	slt	$at,$t2,$v0
/*  f0fc478:	10200004 */ 	beqz	$at,.L0f0fc48c
/*  f0fc47c:	004a5823 */ 	subu	$t3,$v0,$t2
/*  f0fc480:	a22b0017 */ 	sb	$t3,0x17($s1)
/*  f0fc484:	10000003 */ 	b	.L0f0fc494
/*  f0fc488:	316200ff */ 	andi	$v0,$t3,0xff
.L0f0fc48c:
/*  f0fc48c:	a2200017 */ 	sb	$zero,0x17($s1)
/*  f0fc490:	300200ff */ 	andi	$v0,$zero,0xff
.L0f0fc494:
/*  f0fc494:	18400096 */ 	blez	$v0,.L0f0fc6f0
/*  f0fc498:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0fc49c:	44816000 */ 	mtc1	$at,$f12
/*  f0fc4a0:	0fc01ac2 */ 	jal	func0f006b08
/*  f0fc4a4:	00000000 */ 	nop
/*  f0fc4a8:	3c01437f */ 	lui	$at,0x437f
/*  f0fc4ac:	44819000 */ 	mtc1	$at,$f18
/*  f0fc4b0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0fc4b4:	3c014f00 */ 	lui	$at,0x4f00
/*  f0fc4b8:	46120402 */ 	mul.s	$f16,$f0,$f18
/*  f0fc4bc:	240451e2 */ 	addiu	$a0,$zero,0x51e2
/*  f0fc4c0:	444df800 */ 	cfc1	$t5,$31
/*  f0fc4c4:	44cef800 */ 	ctc1	$t6,$31
/*  f0fc4c8:	00000000 */ 	nop
/*  f0fc4cc:	460081a4 */ 	cvt.w.s	$f6,$f16
/*  f0fc4d0:	444ef800 */ 	cfc1	$t6,$31
/*  f0fc4d4:	00000000 */ 	nop
/*  f0fc4d8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0fc4dc:	51c00013 */ 	beqzl	$t6,.L0f0fc52c
/*  f0fc4e0:	440e3000 */ 	mfc1	$t6,$f6
/*  f0fc4e4:	44813000 */ 	mtc1	$at,$f6
/*  f0fc4e8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0fc4ec:	46068181 */ 	sub.s	$f6,$f16,$f6
/*  f0fc4f0:	44cef800 */ 	ctc1	$t6,$31
/*  f0fc4f4:	00000000 */ 	nop
/*  f0fc4f8:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0fc4fc:	444ef800 */ 	cfc1	$t6,$31
/*  f0fc500:	00000000 */ 	nop
/*  f0fc504:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0fc508:	15c00005 */ 	bnez	$t6,.L0f0fc520
/*  f0fc50c:	00000000 */ 	nop
/*  f0fc510:	440e3000 */ 	mfc1	$t6,$f6
/*  f0fc514:	3c018000 */ 	lui	$at,0x8000
/*  f0fc518:	10000007 */ 	b	.L0f0fc538
/*  f0fc51c:	01c17025 */ 	or	$t6,$t6,$at
.L0f0fc520:
/*  f0fc520:	10000005 */ 	b	.L0f0fc538
/*  f0fc524:	240effff */ 	addiu	$t6,$zero,-1
/*  f0fc528:	440e3000 */ 	mfc1	$t6,$f6
.L0f0fc52c:
/*  f0fc52c:	00000000 */ 	nop
/*  f0fc530:	05c0fffb */ 	bltz	$t6,.L0f0fc520
/*  f0fc534:	00000000 */ 	nop
.L0f0fc538:
/*  f0fc538:	44cdf800 */ 	ctc1	$t5,$31
/*  f0fc53c:	0fc5b9f1 */ 	jal	langGet
/*  f0fc540:	afae00a0 */ 	sw	$t6,0xa0($sp)
/*  f0fc544:	02802025 */ 	or	$a0,$s4,$zero
/*  f0fc548:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fc54c:	0c004dad */ 	jal	sprintf
/*  f0fc550:	26460001 */ 	addiu	$a2,$s2,0x1
/*  f0fc554:	2a410002 */ 	slti	$at,$s2,0x2
/*  f0fc558:	10200005 */ 	beqz	$at,.L0f0fc570
/*  f0fc55c:	8fb900e4 */ 	lw	$t9,0xe4($sp)
/*  f0fc560:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f0fc564:	25f80002 */ 	addiu	$t8,$t7,0x2
/*  f0fc568:	10000003 */ 	b	.L0f0fc578
/*  f0fc56c:	afb800a8 */ 	sw	$t8,0xa8($sp)
.L0f0fc570:
/*  f0fc570:	272cfff7 */ 	addiu	$t4,$t9,-9
/*  f0fc574:	afac00a8 */ 	sw	$t4,0xa8($sp)
.L0f0fc578:
/*  f0fc578:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fc57c:	12410004 */ 	beq	$s2,$at,.L0f0fc590
/*  f0fc580:	8faa00e8 */ 	lw	$t2,0xe8($sp)
/*  f0fc584:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0fc588:	16410006 */ 	bne	$s2,$at,.L0f0fc5a4
/*  f0fc58c:	8faf00f0 */ 	lw	$t7,0xf0($sp)
.L0f0fc590:
/*  f0fc590:	8fab00dc */ 	lw	$t3,0xdc($sp)
/*  f0fc594:	014b6823 */ 	subu	$t5,$t2,$t3
/*  f0fc598:	25aefffe */ 	addiu	$t6,$t5,-2
/*  f0fc59c:	10000003 */ 	b	.L0f0fc5ac
/*  f0fc5a0:	afae00ac */ 	sw	$t6,0xac($sp)
.L0f0fc5a4:
/*  f0fc5a4:	25f80002 */ 	addiu	$t8,$t7,0x2
/*  f0fc5a8:	afb800ac */ 	sw	$t8,0xac($sp)
.L0f0fc5ac:
/*  f0fc5ac:	0c002f02 */ 	jal	viGetX
/*  f0fc5b0:	00000000 */ 	nop
/*  f0fc5b4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0fc5b8:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f0fc5bc:	0c002f06 */ 	jal	viGetY
/*  f0fc5c0:	03208025 */ 	or	$s0,$t9,$zero
/*  f0fc5c4:	922b0017 */ 	lbu	$t3,0x17($s1)
/*  f0fc5c8:	3c0c8008 */ 	lui	$t4,%hi(var8007fb10)
/*  f0fc5cc:	3c0a8008 */ 	lui	$t2,%hi(var8007fb0c)
/*  f0fc5d0:	3c015070 */ 	lui	$at,0x5070
/*  f0fc5d4:	8d4afb0c */ 	lw	$t2,%lo(var8007fb0c)($t2)
/*  f0fc5d8:	8d8cfb10 */ 	lw	$t4,%lo(var8007fb10)($t4)
/*  f0fc5dc:	3421ff00 */ 	ori	$at,$at,0xff00
/*  f0fc5e0:	01616825 */ 	or	$t5,$t3,$at
/*  f0fc5e4:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0fc5e8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc5ec:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f0fc5f0:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f0fc5f4:	02803825 */ 	or	$a3,$s4,$zero
/*  f0fc5f8:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0fc5fc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0fc600:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0fc604:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0fc608:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0fc60c:	0fc5580f */ 	jal	textRenderWhite
/*  f0fc610:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0fc614:	8ece0490 */ 	lw	$t6,0x490($s6)
/*  f0fc618:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0fc61c:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0fc620:	15c1000f */ 	bne	$t6,$at,.L0f0fc660
/*  f0fc624:	02d27821 */ 	addu	$t7,$s6,$s2
/*  f0fc628:	81f80494 */ 	lb	$t8,0x494($t7)
/*  f0fc62c:	1300000c */ 	beqz	$t8,.L0f0fc660
/*  f0fc630:	00000000 */ 	nop
/*  f0fc634:	0fc5b9f1 */ 	jal	langGet
/*  f0fc638:	240459cd */ 	addiu	$a0,$zero,0x59cd
/*  f0fc63c:	02802025 */ 	or	$a0,$s4,$zero
/*  f0fc640:	0c004c4c */ 	jal	strcpy
/*  f0fc644:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fc648:	92230017 */ 	lbu	$v1,0x17($s1)
/*  f0fc64c:	3c01d000 */ 	lui	$at,0xd000
/*  f0fc650:	342120ff */ 	ori	$at,$at,0x20ff
/*  f0fc654:	0061c825 */ 	or	$t9,$v1,$at
/*  f0fc658:	1000000d */ 	b	.L0f0fc690
/*  f0fc65c:	03201825 */ 	or	$v1,$t9,$zero
.L0f0fc660:
/*  f0fc660:	0fc5b9f1 */ 	jal	langGet
/*  f0fc664:	240451e3 */ 	addiu	$a0,$zero,0x51e3
/*  f0fc668:	02802025 */ 	or	$a0,$s4,$zero
/*  f0fc66c:	0c004c4c */ 	jal	strcpy
/*  f0fc670:	00402825 */ 	or	$a1,$v0,$zero
/*  f0fc674:	3c0400ff */ 	lui	$a0,0xff
/*  f0fc678:	3484ff00 */ 	ori	$a0,$a0,0xff00
/*  f0fc67c:	2405ff00 */ 	addiu	$a1,$zero,-256
/*  f0fc680:	0fc01a40 */ 	jal	colourBlend
/*  f0fc684:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*  f0fc688:	922c0017 */ 	lbu	$t4,0x17($s1)
/*  f0fc68c:	01821825 */ 	or	$v1,$t4,$v0
.L0f0fc690:
/*  f0fc690:	0c002f02 */ 	jal	viGetX
/*  f0fc694:	afa300a4 */ 	sw	$v1,0xa4($sp)
/*  f0fc698:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0fc69c:	00105403 */ 	sra	$t2,$s0,0x10
/*  f0fc6a0:	0c002f06 */ 	jal	viGetY
/*  f0fc6a4:	01408025 */ 	or	$s0,$t2,$zero
/*  f0fc6a8:	3c0b8008 */ 	lui	$t3,%hi(var8007fb10)
/*  f0fc6ac:	3c0d8008 */ 	lui	$t5,%hi(var8007fb0c)
/*  f0fc6b0:	8dadfb0c */ 	lw	$t5,%lo(var8007fb0c)($t5)
/*  f0fc6b4:	8d6bfb10 */ 	lw	$t3,%lo(var8007fb10)($t3)
/*  f0fc6b8:	8fa300a4 */ 	lw	$v1,0xa4($sp)
/*  f0fc6bc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc6c0:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f0fc6c4:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f0fc6c8:	02803825 */ 	or	$a3,$s4,$zero
/*  f0fc6cc:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0fc6d0:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0fc6d4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0fc6d8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0fc6dc:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0fc6e0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0fc6e4:	0fc5580f */ 	jal	textRenderWhite
/*  f0fc6e8:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0fc6ec:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fc6f0:
/*  f0fc6f0:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0fc6f4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0fc6f8:	5641fef9 */ 	bnel	$s2,$at,.L0f0fc2e0
/*  f0fc6fc:	8ec20490 */ 	lw	$v0,0x490($s6)
/*  f0fc700:	0fc54de0 */ 	jal	func0f153780
/*  f0fc704:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc708:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0fc70c:	02a01025 */ 	or	$v0,$s5,$zero
.L0f0fc710:
/*  f0fc710:	3c0eb700 */ 	lui	$t6,0xb700
/*  f0fc714:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fc718:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0fc71c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0fc720:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f0fc724:	82f8001b */ 	lb	$t8,0x1b($s7)
.L0f0fc728:
/*  f0fc728:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fc72c:	130100a1 */ 	beq	$t8,$at,.L0f0fc9b4
/*  f0fc730:	00000000 */ 	nop
/*  f0fc734:	0c002f40 */ 	jal	viGetViewLeft
/*  f0fc738:	00000000 */ 	nop
/*  f0fc73c:	3c198008 */ 	lui	$t9,%hi(g_ScreenWidthMultiplier)
/*  f0fc740:	8f39fac0 */ 	lw	$t9,%lo(g_ScreenWidthMultiplier)($t9)
/*  f0fc744:	0059001a */ 	div	$zero,$v0,$t9
/*  f0fc748:	00006012 */ 	mflo	$t4
/*  f0fc74c:	afac0098 */ 	sw	$t4,0x98($sp)
/*  f0fc750:	17200002 */ 	bnez	$t9,.L0f0fc75c
/*  f0fc754:	00000000 */ 	nop
/*  f0fc758:	0007000d */ 	break	0x7
.L0f0fc75c:
/*  f0fc75c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fc760:	17210004 */ 	bne	$t9,$at,.L0f0fc774
/*  f0fc764:	3c018000 */ 	lui	$at,0x8000
/*  f0fc768:	14410002 */ 	bne	$v0,$at,.L0f0fc774
/*  f0fc76c:	00000000 */ 	nop
/*  f0fc770:	0006000d */ 	break	0x6
.L0f0fc774:
/*  f0fc774:	0c002f44 */ 	jal	viGetViewTop
/*  f0fc778:	00000000 */ 	nop
/*  f0fc77c:	0c002f40 */ 	jal	viGetViewLeft
/*  f0fc780:	afa20094 */ 	sw	$v0,0x94($sp)
/*  f0fc784:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0fc788:	00105403 */ 	sra	$t2,$s0,0x10
/*  f0fc78c:	0c002f22 */ 	jal	viGetViewX
/*  f0fc790:	01408025 */ 	or	$s0,$t2,$zero
/*  f0fc794:	3c0d8008 */ 	lui	$t5,%hi(g_ScreenWidthMultiplier)
/*  f0fc798:	8dadfac0 */ 	lw	$t5,%lo(g_ScreenWidthMultiplier)($t5)
/*  f0fc79c:	00505821 */ 	addu	$t3,$v0,$s0
/*  f0fc7a0:	016d001a */ 	div	$zero,$t3,$t5
/*  f0fc7a4:	0000a012 */ 	mflo	$s4
/*  f0fc7a8:	15a00002 */ 	bnez	$t5,.L0f0fc7b4
/*  f0fc7ac:	00000000 */ 	nop
/*  f0fc7b0:	0007000d */ 	break	0x7
.L0f0fc7b4:
/*  f0fc7b4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fc7b8:	15a10004 */ 	bne	$t5,$at,.L0f0fc7cc
/*  f0fc7bc:	3c018000 */ 	lui	$at,0x8000
/*  f0fc7c0:	15610002 */ 	bne	$t3,$at,.L0f0fc7cc
/*  f0fc7c4:	00000000 */ 	nop
/*  f0fc7c8:	0006000d */ 	break	0x6
.L0f0fc7cc:
/*  f0fc7cc:	0c002f44 */ 	jal	viGetViewTop
/*  f0fc7d0:	00000000 */ 	nop
/*  f0fc7d4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0fc7d8:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0fc7dc:	0c002f26 */ 	jal	viGetViewY
/*  f0fc7e0:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0fc7e4:	8ec7006c */ 	lw	$a3,0x6c($s6)
/*  f0fc7e8:	00504821 */ 	addu	$t1,$v0,$s0
/*  f0fc7ec:	00009025 */ 	or	$s2,$zero,$zero
/*  f0fc7f0:	10e00003 */ 	beqz	$a3,.L0f0fc800
/*  f0fc7f4:	00009825 */ 	or	$s3,$zero,$zero
/*  f0fc7f8:	10000002 */ 	b	.L0f0fc804
/*  f0fc7fc:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f0fc800:
/*  f0fc800:	00004025 */ 	or	$t0,$zero,$zero
.L0f0fc804:
/*  f0fc804:	8ec40068 */ 	lw	$a0,0x68($s6)
/*  f0fc808:	50800004 */ 	beqzl	$a0,.L0f0fc81c
/*  f0fc80c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fc810:	10000002 */ 	b	.L0f0fc81c
/*  f0fc814:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0fc818:	00001825 */ 	or	$v1,$zero,$zero
.L0f0fc81c:
/*  f0fc81c:	8ec50064 */ 	lw	$a1,0x64($s6)
/*  f0fc820:	50a00004 */ 	beqzl	$a1,.L0f0fc834
/*  f0fc824:	00008825 */ 	or	$s1,$zero,$zero
/*  f0fc828:	10000002 */ 	b	.L0f0fc834
/*  f0fc82c:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f0fc830:	00008825 */ 	or	$s1,$zero,$zero
.L0f0fc834:
/*  f0fc834:	8ec60070 */ 	lw	$a2,0x70($s6)
/*  f0fc838:	50c00004 */ 	beqzl	$a2,.L0f0fc84c
/*  f0fc83c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fc840:	10000002 */ 	b	.L0f0fc84c
/*  f0fc844:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0fc848:	00001025 */ 	or	$v0,$zero,$zero
.L0f0fc84c:
/*  f0fc84c:	00517821 */ 	addu	$t7,$v0,$s1
/*  f0fc850:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f0fc854:	0308c821 */ 	addu	$t9,$t8,$t0
/*  f0fc858:	2b210003 */ 	slti	$at,$t9,0x3
/*  f0fc85c:	1420000a */ 	bnez	$at,.L0f0fc888
/*  f0fc860:	00000000 */ 	nop
/*  f0fc864:	8ec2028c */ 	lw	$v0,0x28c($s6)
/*  f0fc868:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fc86c:	10410003 */ 	beq	$v0,$at,.L0f0fc87c
/*  f0fc870:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0fc874:	54410004 */ 	bnel	$v0,$at,.L0f0fc888
/*  f0fc878:	2412000f */ 	addiu	$s2,$zero,0xf
.L0f0fc87c:
/*  f0fc87c:	10000002 */ 	b	.L0f0fc888
/*  f0fc880:	2413000f */ 	addiu	$s3,$zero,0xf
/*  f0fc884:	2412000f */ 	addiu	$s2,$zero,0xf
.L0f0fc888:
/*  f0fc888:	10e00003 */ 	beqz	$a3,.L0f0fc898
/*  f0fc88c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0fc890:	10000002 */ 	b	.L0f0fc89c
/*  f0fc894:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f0fc898:
/*  f0fc898:	00004025 */ 	or	$t0,$zero,$zero
.L0f0fc89c:
/*  f0fc89c:	10800003 */ 	beqz	$a0,.L0f0fc8ac
/*  f0fc8a0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fc8a4:	10000001 */ 	b	.L0f0fc8ac
/*  f0fc8a8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0fc8ac:
/*  f0fc8ac:	10a00003 */ 	beqz	$a1,.L0f0fc8bc
/*  f0fc8b0:	00008825 */ 	or	$s1,$zero,$zero
/*  f0fc8b4:	10000001 */ 	b	.L0f0fc8bc
/*  f0fc8b8:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f0fc8bc:
/*  f0fc8bc:	10c00003 */ 	beqz	$a2,.L0f0fc8cc
/*  f0fc8c0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fc8c4:	10000001 */ 	b	.L0f0fc8cc
/*  f0fc8c8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0fc8cc:
/*  f0fc8cc:	00516021 */ 	addu	$t4,$v0,$s1
/*  f0fc8d0:	01835021 */ 	addu	$t2,$t4,$v1
/*  f0fc8d4:	01485821 */ 	addu	$t3,$t2,$t0
/*  f0fc8d8:	55610013 */ 	bnel	$t3,$at,.L0f0fc928
/*  f0fc8dc:	8ecf006c */ 	lw	$t7,0x6c($s6)
/*  f0fc8e0:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0fc8e4:	afa9008c */ 	sw	$t1,0x8c($sp)
/*  f0fc8e8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fc8ec:	10410006 */ 	beq	$v0,$at,.L0f0fc908
/*  f0fc8f0:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f0fc8f4:	3c0d8009 */ 	lui	$t5,%hi(g_Is4Mb)
/*  f0fc8f8:	91ad0af0 */ 	lbu	$t5,%lo(g_Is4Mb)($t5)
/*  f0fc8fc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fc900:	55a10009 */ 	bnel	$t5,$at,.L0f0fc928
/*  f0fc904:	8ecf006c */ 	lw	$t7,0x6c($s6)
.L0f0fc908:
/*  f0fc908:	8ece028c */ 	lw	$t6,0x28c($s6)
/*  f0fc90c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fc910:	55c10004 */ 	bnel	$t6,$at,.L0f0fc924
/*  f0fc914:	2412000f */ 	addiu	$s2,$zero,0xf
/*  f0fc918:	10000002 */ 	b	.L0f0fc924
/*  f0fc91c:	2413000f */ 	addiu	$s3,$zero,0xf
/*  f0fc920:	2412000f */ 	addiu	$s2,$zero,0xf
.L0f0fc924:
/*  f0fc924:	8ecf006c */ 	lw	$t7,0x6c($s6)
.L0f0fc928:
/*  f0fc928:	8ec40068 */ 	lw	$a0,0x68($s6)
/*  f0fc92c:	8ec50064 */ 	lw	$a1,0x64($s6)
/*  f0fc930:	11e00003 */ 	beqz	$t7,.L0f0fc940
/*  f0fc934:	8ec60070 */ 	lw	$a2,0x70($s6)
/*  f0fc938:	10000002 */ 	b	.L0f0fc944
/*  f0fc93c:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f0fc940:
/*  f0fc940:	00004025 */ 	or	$t0,$zero,$zero
.L0f0fc944:
/*  f0fc944:	10800003 */ 	beqz	$a0,.L0f0fc954
/*  f0fc948:	02803825 */ 	or	$a3,$s4,$zero
/*  f0fc94c:	10000002 */ 	b	.L0f0fc958
/*  f0fc950:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0fc954:
/*  f0fc954:	00001825 */ 	or	$v1,$zero,$zero
.L0f0fc958:
/*  f0fc958:	10a00003 */ 	beqz	$a1,.L0f0fc968
/*  f0fc95c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc960:	10000002 */ 	b	.L0f0fc96c
/*  f0fc964:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f0fc968:
/*  f0fc968:	00008825 */ 	or	$s1,$zero,$zero
.L0f0fc96c:
/*  f0fc96c:	10c00003 */ 	beqz	$a2,.L0f0fc97c
/*  f0fc970:	8fa50098 */ 	lw	$a1,0x98($sp)
/*  f0fc974:	10000002 */ 	b	.L0f0fc980
/*  f0fc978:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0fc97c:
/*  f0fc97c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0fc980:
/*  f0fc980:	0051c021 */ 	addu	$t8,$v0,$s1
/*  f0fc984:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f0fc988:	82eb001b */ 	lb	$t3,0x1b($s7)
/*  f0fc98c:	03286021 */ 	addu	$t4,$t9,$t0
/*  f0fc990:	298a0002 */ 	slti	$t2,$t4,0x2
/*  f0fc994:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0fc998:	8fa60094 */ 	lw	$a2,0x94($sp)
/*  f0fc99c:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0fc9a0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0fc9a4:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0fc9a8:	0fc3c33a */ 	jal	func0f0f0ce8
/*  f0fc9ac:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0fc9b0:	0040a825 */ 	or	$s5,$v0,$zero
.L0f0fc9b4:
/*  f0fc9b4:	0fc35272 */ 	jal	func0f0d49c8
/*  f0fc9b8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fc9bc:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f0fc9c0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0fc9c4:	3c018008 */ 	lui	$at,%hi(g_ScreenWidthMultiplier)
/*  f0fc9c8:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0fc9cc:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0fc9d0:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f0fc9d4:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f0fc9d8:	8fb40044 */ 	lw	$s4,0x44($sp)
/*  f0fc9dc:	8fb50048 */ 	lw	$s5,0x48($sp)
/*  f0fc9e0:	8fb6004c */ 	lw	$s6,0x4c($sp)
/*  f0fc9e4:	8fb70050 */ 	lw	$s7,0x50($sp)
/*  f0fc9e8:	ac2dfac0 */ 	sw	$t5,%lo(g_ScreenWidthMultiplier)($at)
/*  f0fc9ec:	03e00008 */ 	jr	$ra
/*  f0fc9f0:	27bd0118 */ 	addiu	$sp,$sp,0x118
);

u32 menuChooseMusic(void)
{
	s32 missionsuccess = MUSIC_MISSION_SUCCESS;

	if (g_StageIndex == STAGEINDEX_DEFENSE) {
		missionsuccess = MUSIC_MISSION_UNKNOWN;
	}

	if (g_MenuData.root == MENUROOT_ENDSCREEN) {
		if (g_Vars.bond->isdead || g_Vars.bond->aborted || !objectiveIsAllComplete()) {
			return MUSIC_MISSION_FAILED;
		}

		return missionsuccess;
	}

	if (g_MenuData.root == MENUROOT_MPENDSCREEN) {
		if (g_Vars.coopplayernum >= 0) {
			if ((g_Vars.bond->isdead && g_Vars.coop->isdead)
					|| g_Vars.bond->aborted
					|| g_Vars.coop->aborted
					|| !objectiveIsAllComplete()) {
				return MUSIC_MISSION_FAILED;
			}

			return missionsuccess;
		}

		if (g_Vars.antiplayernum >= 0) {
			if (g_Vars.bond->isdead || g_Vars.bond->aborted || !objectiveIsAllComplete()) {
				return MUSIC_MISSION_FAILED;
			}

			return missionsuccess;
		}
	}

	if (g_MenuData.root == MENUROOT_FILESELECT) {
		return MUSIC_MAINMENU;
	}

	if (g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU) {
		return MUSIC_COMBATSIM_MENU;
	}

	if (g_MenuData.root == MENUROOT_MPPAUSE) {
		return MUSIC_COMBATSIM_COMPLETE;
	}

	if (g_MenuData.root == MENUROOT_BOOTPAKMGR) {
		return MUSIC_MISSION_UNKNOWN;
	}

	if (g_Vars.mplayerisrunning) {
		return MUSIC_COMBATSIM_COMPLETE;
	}

	if (g_Vars.stagenum == STAGE_CITRAINING || g_Vars.stagenum == STAGE_4MBMENU) {
		return MUSIC_MAINMENU;
	}

	return MUSIC_PAUSEMENU;
}

bool func0f0fcbcc(void)
{
	if (var80062940 == 0 && g_Vars.stagenum == STAGE_CITRAINING) {
		return true;
	}

	return false;
}

bool func0f0fcc04(void)
{
	return false;
}

u32 menuGetRoot(void)
{
	if (g_MenuData.count == 0) {
		return 0;
	}

	return g_MenuData.root;
}

GLOBAL_ASM(
glabel menuhandler000fcc34
/*  f0fcc34:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0fcc38:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0fcc3c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0fcc40:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0fcc44:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0fcc48:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0fcc4c:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0fcc50:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0fcc54:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0fcc58:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0fcc5c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0fcc60:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0fcc64:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0fcc68:	1481002a */ 	bne	$a0,$at,.L0f0fcd14
/*  f0fcc6c:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f0fcc70:	3c1e8007 */ 	lui	$s8,%hi(menudialog_damagedcontrollerpak)
/*  f0fcc74:	3c178007 */ 	lui	$s7,%hi(g_PakAttemptRepairMenuDialog)
/*  f0fcc78:	3c168007 */ 	lui	$s6,%hi(g_PakRepairFailedMenuDialog)
/*  f0fcc7c:	3c158007 */ 	lui	$s5,%hi(menudialog_pakremoved)
/*  f0fcc80:	3c148007 */ 	lui	$s4,%hi(g_PakRepairSuccessMenuDialog)
/*  f0fcc84:	3c128007 */ 	lui	$s2,%hi(g_MpPlayerNum)
/*  f0fcc88:	3c11800a */ 	lui	$s1,%hi(g_Menus)
/*  f0fcc8c:	2631e000 */ 	addiu	$s1,$s1,%lo(g_Menus)
/*  f0fcc90:	26521448 */ 	addiu	$s2,$s2,%lo(g_MpPlayerNum)
/*  f0fcc94:	269415b0 */ 	addiu	$s4,$s4,%lo(g_PakRepairSuccessMenuDialog)
/*  f0fcc98:	26b51548 */ 	addiu	$s5,$s5,%lo(menudialog_pakremoved)
/*  f0fcc9c:	26d61618 */ 	addiu	$s6,$s6,%lo(g_PakRepairFailedMenuDialog)
/*  f0fcca0:	26f716a8 */ 	addiu	$s7,$s7,%lo(g_PakAttemptRepairMenuDialog)
/*  f0fcca4:	27de176c */ 	addiu	$s8,$s8,%lo(menudialog_damagedcontrollerpak)
/*  f0fcca8:	24130e70 */ 	addiu	$s3,$zero,0xe70
/*  f0fccac:	8e4e0000 */ 	lw	$t6,0x0($s2)
.L0f0fccb0:
/*  f0fccb0:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0fccb4:	01d30019 */ 	multu	$t6,$s3
/*  f0fccb8:	00007812 */ 	mflo	$t7
/*  f0fccbc:	022fc021 */ 	addu	$t8,$s1,$t7
/*  f0fccc0:	8f0304f8 */ 	lw	$v1,0x4f8($t8)
/*  f0fccc4:	10600011 */ 	beqz	$v1,.L0f0fcd0c
/*  f0fccc8:	00000000 */ 	nop
/*  f0fcccc:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f0fccd0:	1282000c */ 	beq	$s4,$v0,.L0f0fcd04
/*  f0fccd4:	00000000 */ 	nop
/*  f0fccd8:	12a2000a */ 	beq	$s5,$v0,.L0f0fcd04
/*  f0fccdc:	00000000 */ 	nop
/*  f0fcce0:	12c20008 */ 	beq	$s6,$v0,.L0f0fcd04
/*  f0fcce4:	00000000 */ 	nop
/*  f0fcce8:	12e20006 */ 	beq	$s7,$v0,.L0f0fcd04
/*  f0fccec:	00000000 */ 	nop
/*  f0fccf0:	13c20004 */ 	beq	$s8,$v0,.L0f0fcd04
/*  f0fccf4:	3c198007 */ 	lui	$t9,%hi(menudialog_fullcontrollerpak)
/*  f0fccf8:	27391810 */ 	addiu	$t9,$t9,%lo(menudialog_fullcontrollerpak)
/*  f0fccfc:	17220003 */ 	bne	$t9,$v0,.L0f0fcd0c
/*  f0fcd00:	00000000 */ 	nop
.L0f0fcd04:
/*  f0fcd04:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f0fcd08:	00008025 */ 	or	$s0,$zero,$zero
.L0f0fcd0c:
/*  f0fcd0c:	5200ffe8 */ 	beqzl	$s0,.L0f0fccb0
/*  f0fcd10:	8e4e0000 */ 	lw	$t6,0x0($s2)
.L0f0fcd14:
/*  f0fcd14:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0fcd18:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0fcd1c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0fcd20:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0fcd24:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0fcd28:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0fcd2c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0fcd30:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0fcd34:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0fcd38:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0fcd3c:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f0fcd40:	03e00008 */ 	jr	$ra
/*  f0fcd44:	00001025 */ 	or	$v0,$zero,$zero
);

s32 menudialog000fcd48(u32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if (g_Menus[g_MpPlayerNum].curframe
				&& g_Menus[g_MpPlayerNum].curframe->dialog == dialog
				&& func000155b4(g_Menus[g_MpPlayerNum].savedevice) == 0) {
			func0f0f3704(&menudialog_pakremoved);
		}
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f0fcdd0
/*  f0fcdd0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0fcdd4:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0fcdd8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0fcddc:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0fcde0:	14810004 */ 	bne	$a0,$at,.L0f0fcdf4
/*  f0fcde4:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f0fcde8:	3c048007 */ 	lui	$a0,%hi(menudialog_damagedcontrollerpak)
/*  f0fcdec:	0fc3cdc1 */ 	jal	func0f0f3704
/*  f0fcdf0:	2484176c */ 	addiu	$a0,$a0,%lo(menudialog_damagedcontrollerpak)
.L0f0fcdf4:
/*  f0fcdf4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fcdf8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0fcdfc:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fce00:	03e00008 */ 	jr	$ra
/*  f0fce04:	00000000 */ 	nop
);

s32 menuhandlerRepairPak(u32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (pakRepair(g_Menus[g_MpPlayerNum].savedevice)) {
			func0f0f3704(&g_PakRepairSuccessMenuDialog);
		} else {
			func0f0f3704(&g_PakRepairFailedMenuDialog);
		}
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f0fce8c
/*  f0fce8c:	0005c0c0 */ 	sll	$t8,$a1,0x3
/*  f0fce90:	0305c023 */ 	subu	$t8,$t8,$a1
/*  f0fce94:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0fce98:	0305c021 */ 	addu	$t8,$t8,$a1
/*  f0fce9c:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0fcea0:	0305c023 */ 	subu	$t8,$t8,$a1
/*  f0fcea4:	3c19800a */ 	lui	$t9,%hi(g_Menus)
/*  f0fcea8:	2739e000 */ 	addiu	$t9,$t9,%lo(g_Menus)
/*  f0fceac:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0fceb0:	3c088007 */ 	lui	$t0,%hi(g_MpPlayerNum)
/*  f0fceb4:	03191021 */ 	addu	$v0,$t8,$t9
/*  f0fceb8:	8c4904f8 */ 	lw	$t1,0x4f8($v0)
/*  f0fcebc:	25081448 */ 	addiu	$t0,$t0,%lo(g_MpPlayerNum)
/*  f0fcec0:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0fcec4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0fcec8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0fcecc:	00803825 */ 	or	$a3,$a0,$zero
/*  f0fced0:	ad050000 */ 	sw	$a1,0x0($t0)
/*  f0fced4:	a0460e6c */ 	sb	$a2,0xe6c($v0)
/*  f0fced8:	1520002f */ 	bnez	$t1,.L0f0fcf98
/*  f0fcedc:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0fcee0:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0fcee4:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0fcee8:	8cca006c */ 	lw	$t2,0x6c($a2)
/*  f0fceec:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fcef0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fcef4:	11400003 */ 	beqz	$t2,.L0f0fcf04
/*  f0fcef8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fcefc:	10000001 */ 	b	.L0f0fcf04
/*  f0fcf00:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0fcf04:
/*  f0fcf04:	8ccb0068 */ 	lw	$t3,0x68($a2)
/*  f0fcf08:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fcf0c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fcf10:	11600003 */ 	beqz	$t3,.L0f0fcf20
/*  f0fcf14:	00000000 */ 	nop
/*  f0fcf18:	10000001 */ 	b	.L0f0fcf20
/*  f0fcf1c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0fcf20:
/*  f0fcf20:	8ccc0064 */ 	lw	$t4,0x64($a2)
/*  f0fcf24:	11800003 */ 	beqz	$t4,.L0f0fcf34
/*  f0fcf28:	00000000 */ 	nop
/*  f0fcf2c:	10000001 */ 	b	.L0f0fcf34
/*  f0fcf30:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0fcf34:
/*  f0fcf34:	8ccd0070 */ 	lw	$t5,0x70($a2)
/*  f0fcf38:	11a00003 */ 	beqz	$t5,.L0f0fcf48
/*  f0fcf3c:	00000000 */ 	nop
/*  f0fcf40:	10000001 */ 	b	.L0f0fcf48
/*  f0fcf44:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0fcf48:
/*  f0fcf48:	00447021 */ 	addu	$t6,$v0,$a0
/*  f0fcf4c:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f0fcf50:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f0fcf54:	1701000b */ 	bne	$t8,$at,.L0f0fcf84
/*  f0fcf58:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0fcf5c:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f0fcf60:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f0fcf64:	0fc5b350 */ 	jal	soloSetPaused
/*  f0fcf68:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0fcf6c:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0fcf70:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0fcf74:	8cc90284 */ 	lw	$t1,0x284($a2)
/*  f0fcf78:	24190003 */ 	addiu	$t9,$zero,0x3
/*  f0fcf7c:	10000008 */ 	b	.L0f0fcfa0
/*  f0fcf80:	ad391a24 */ 	sw	$t9,0x1a24($t1)
.L0f0fcf84:
/*  f0fcf84:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0fcf88:	0fc3e0cc */ 	jal	menuPushRootDialog
/*  f0fcf8c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0fcf90:	10000004 */ 	b	.L0f0fcfa4
/*  f0fcf94:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0fcf98:
/*  f0fcf98:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f0fcf9c:	00e02025 */ 	or	$a0,$a3,$zero
.L0f0fcfa0:
/*  f0fcfa0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0fcfa4:
/*  f0fcfa4:	8faa001c */ 	lw	$t2,0x1c($sp)
/*  f0fcfa8:	3c018007 */ 	lui	$at,%hi(g_MpPlayerNum)
/*  f0fcfac:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0fcfb0:	03e00008 */ 	jr	$ra
/*  f0fcfb4:	ac2a1448 */ 	sw	$t2,%lo(g_MpPlayerNum)($at)
);

struct menuitem menuitems_pakremoved[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS(174), 0x00000000, NULL }, // "The Controller Pak has been removed."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPWEAPONS(73), 0x00000000, menuhandler000fcc34 }, // "OK"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog menudialog_pakremoved = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS(173), // "Error"
	menuitems_pakremoved,
	NULL,
	0x00000000,
	NULL,
};

struct menuitem menuitems_pakrepaired[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, 0x000054b5, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, 0x00005449, 0x00000000, menuhandler000fcc34 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_PakRepairSuccessMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPWEAPONS(180), // "Repair Successful"
	menuitems_pakrepaired,
	menudialog000fcd48,
	0x00000000,
	NULL,
};

struct menuitem menuitems_pakrepairfailed[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS(183), 0x00000000, NULL }, // "The Controller Pak cannot be repaired. You will not be able to load from or save to this Controller Pak."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPWEAPONS(73), 0x00000000, NULL }, // "OK"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_PakRepairFailedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS(182), // "Repair Failed"
	menuitems_pakrepairfailed,
	menudialog000fcd48,
	0x00000000,
	NULL,
};

struct menuitem menuitems_pakattemptrepair[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS(176), 0x00000000, NULL }, // "Are you sure you want to attempt repair of this Controller Pak?"
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS(177), 0x00000000, NULL }, // "Data may be lost!"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPWEAPONS(178), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPWEAPONS(179), 0x00000000, menuhandlerRepairPak }, // "Repair"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_PakAttemptRepairMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS(175), // "Attempt Repair"
	menuitems_pakattemptrepair,
	menudialog000fcd48,
	0x00000000,
	NULL,
};

char *menuTextSaveDeviceName(struct menuitem *item)
{
	u16 devices[] = {
		L_OPTIONS(112), // "Controller Pak 1"
		L_OPTIONS(113), // "Controller Pak 2"
		L_OPTIONS(114), // "Controller Pak 3"
		L_OPTIONS(115), // "Controller Pak 4"
		L_OPTIONS(111), // "Game Pak"
	};

	if ((u8)g_Menus[g_MpPlayerNum].savedevice < 5) {
		return langGet(devices[(u8)g_Menus[g_MpPlayerNum].savedevice]);
	}

	return NULL;
}

s32 menuhandlerRetrySavePak(u32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		g_Vars.unk0004e4 &= 0xfff0;
		g_Vars.unk0004e4 |= 8;
		g_Vars.unk0004e4 |= 1 << ((u8)g_Menus[g_MpPlayerNum].savedevice + 8);
	}

	return 0;
}

s32 menuhandlerWarnRepairPak(u32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPushDialog(&g_PakAttemptRepairMenuDialog);
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f0fd118
/*  f0fd118:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0fd11c:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0fd120:	8cee0318 */ 	lw	$t6,0x318($a3)
/*  f0fd124:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fd128:	3c0f800b */ 	lui	$t7,%hi(g_MpSetup+0x16)
/*  f0fd12c:	51c0000a */ 	beqzl	$t6,.L0f0fd158
/*  f0fd130:	8ce90298 */ 	lw	$t1,0x298($a3)
/*  f0fd134:	95efcb9e */ 	lhu	$t7,%lo(g_MpSetup+0x16)($t7)
/*  f0fd138:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0fd13c:	0098c804 */ 	sllv	$t9,$t8,$a0
/*  f0fd140:	01f94024 */ 	and	$t0,$t7,$t9
/*  f0fd144:	11000029 */ 	beqz	$t0,.L0f0fd1ec
/*  f0fd148:	00000000 */ 	nop
/*  f0fd14c:	03e00008 */ 	jr	$ra
/*  f0fd150:	00801025 */ 	or	$v0,$a0,$zero
/*  f0fd154:	8ce90298 */ 	lw	$t1,0x298($a3)
.L0f0fd158:
/*  f0fd158:	05230005 */ 	bgezl	$t1,.L0f0fd170
/*  f0fd15c:	8ceb006c */ 	lw	$t3,0x6c($a3)
/*  f0fd160:	8cea029c */ 	lw	$t2,0x29c($a3)
/*  f0fd164:	05400021 */ 	bltz	$t2,.L0f0fd1ec
/*  f0fd168:	00000000 */ 	nop
/*  f0fd16c:	8ceb006c */ 	lw	$t3,0x6c($a3)
.L0f0fd170:
/*  f0fd170:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fd174:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fd178:	11600003 */ 	beqz	$t3,.L0f0fd188
/*  f0fd17c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fd180:	10000001 */ 	b	.L0f0fd188
/*  f0fd184:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0fd188:
/*  f0fd188:	8cec0068 */ 	lw	$t4,0x68($a3)
/*  f0fd18c:	11800003 */ 	beqz	$t4,.L0f0fd19c
/*  f0fd190:	00000000 */ 	nop
/*  f0fd194:	10000001 */ 	b	.L0f0fd19c
/*  f0fd198:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0fd19c:
/*  f0fd19c:	8ced0064 */ 	lw	$t5,0x64($a3)
/*  f0fd1a0:	11a00003 */ 	beqz	$t5,.L0f0fd1b0
/*  f0fd1a4:	00000000 */ 	nop
/*  f0fd1a8:	10000001 */ 	b	.L0f0fd1b0
/*  f0fd1ac:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0fd1b0:
/*  f0fd1b0:	8cee0070 */ 	lw	$t6,0x70($a3)
/*  f0fd1b4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0fd1b8:	11c00003 */ 	beqz	$t6,.L0f0fd1c8
/*  f0fd1bc:	00000000 */ 	nop
/*  f0fd1c0:	10000001 */ 	b	.L0f0fd1c8
/*  f0fd1c4:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0fd1c8:
/*  f0fd1c8:	00e6c021 */ 	addu	$t8,$a3,$a2
/*  f0fd1cc:	03057821 */ 	addu	$t7,$t8,$a1
/*  f0fd1d0:	01e2c821 */ 	addu	$t9,$t7,$v0
/*  f0fd1d4:	2b210002 */ 	slti	$at,$t9,0x2
/*  f0fd1d8:	14200004 */ 	bnez	$at,.L0f0fd1ec
/*  f0fd1dc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fd1e0:	14810002 */ 	bne	$a0,$at,.L0f0fd1ec
/*  f0fd1e4:	00000000 */ 	nop
/*  f0fd1e8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0fd1ec:
/*  f0fd1ec:	03e00008 */ 	jr	$ra
/*  f0fd1f0:	00601025 */ 	or	$v0,$v1,$zero
);

bool func0f0fd1f4(u32 arg0, u32 arg1)
{
	s32 playernum = func0f0fd118(arg0);
	bool result = true;

	if (g_Vars.lvframenum < 20) {
		result = false;
	}

	if (var80062940 == 0) {
		result = false;
	}

	if (g_Vars.stagenum == STAGE_BOOTPAKMENU) {
		result = true;
	}

	if (g_Menus[playernum].curframe) {
		if (g_Menus[playernum].curframe->dialog == &menudialog_damagedcontrollerpak
				|| g_Menus[playernum].curframe->dialog == &menudialog_cannotreadgameboy
				|| g_Menus[playernum].curframe->dialog == &menudialog_datalost
				|| g_Menus[playernum].curframe->dialog == &menudialog_fullcontrollerpak
				|| g_Menus[playernum].curframe->dialog == &g_PakAttemptRepairMenuDialog
				|| g_Menus[playernum].curframe->dialog == &menudialog_pakremoved
				|| g_Menus[playernum].curframe->dialog == &g_PakRepairSuccessMenuDialog
				|| g_Menus[playernum].curframe->dialog == &g_PakRepairFailedMenuDialog) {
			result = false;
		}
	} else if (g_MenuData.unk015 != 255 || g_MenuData.unk014 || g_MenuData.unk5d4) {
		result = false;
	}

	return result;
}

GLOBAL_ASM(
glabel func0f0fd320
.late_rodata
glabel var7f1b2b00
.word func0f0fd320+0x6c # f0fd38c
glabel var7f1b2b04
.word func0f0fd320+0x50 # f0fd370
glabel var7f1b2b08
.word func0f0fd320+0x50 # f0fd370
glabel var7f1b2b0c
.word func0f0fd320+0x12c # f0fd44c
glabel var7f1b2b10
.word func0f0fd320+0x148 # f0fd468
.text
/*  f0fd320:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0fd324:	3c0e8007 */ 	lui	$t6,%hi(g_MpPlayerNum)
/*  f0fd328:	8dce1448 */ 	lw	$t6,%lo(g_MpPlayerNum)($t6)
/*  f0fd32c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0fd330:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0fd334:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f0fd338:	0fc3f446 */ 	jal	func0f0fd118
/*  f0fd33c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0fd340:	8faf0024 */ 	lw	$t7,0x24($sp)
/*  f0fd344:	3c018007 */ 	lui	$at,%hi(g_MpPlayerNum)
/*  f0fd348:	ac221448 */ 	sw	$v0,%lo(g_MpPlayerNum)($at)
/*  f0fd34c:	2de10005 */ 	sltiu	$at,$t7,0x5
/*  f0fd350:	1020004a */ 	beqz	$at,.L0f0fd47c
/*  f0fd354:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0fd358:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0fd35c:	3c017f1b */ 	lui	$at,%hi(var7f1b2b00)
/*  f0fd360:	002f0821 */ 	addu	$at,$at,$t7
/*  f0fd364:	8c2f2b00 */ 	lw	$t7,%lo(var7f1b2b00)($at)
/*  f0fd368:	01e00008 */ 	jr	$t7
/*  f0fd36c:	00000000 */ 	nop
/*  f0fd370:	3c048007 */ 	lui	$a0,%hi(menudialog_damagedcontrollerpak)
/*  f0fd374:	2484176c */ 	addiu	$a0,$a0,%lo(menudialog_damagedcontrollerpak)
/*  f0fd378:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f0fd37c:	0fc3f3a3 */ 	jal	func0f0fce8c
/*  f0fd380:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f0fd384:	1000003e */ 	b	.L0f0fd480
/*  f0fd388:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fd38c:	3c048007 */ 	lui	$a0,%hi(g_MpPlayerNum)
/*  f0fd390:	8c841448 */ 	lw	$a0,%lo(g_MpPlayerNum)($a0)
/*  f0fd394:	3c19800a */ 	lui	$t9,%hi(g_Menus)
/*  f0fd398:	2739e000 */ 	addiu	$t9,$t9,%lo(g_Menus)
/*  f0fd39c:	0004c0c0 */ 	sll	$t8,$a0,0x3
/*  f0fd3a0:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f0fd3a4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0fd3a8:	0304c021 */ 	addu	$t8,$t8,$a0
/*  f0fd3ac:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0fd3b0:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f0fd3b4:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0fd3b8:	03194021 */ 	addu	$t0,$t8,$t9
/*  f0fd3bc:	850604f4 */ 	lh	$a2,0x4f4($t0)
/*  f0fd3c0:	00003825 */ 	or	$a3,$zero,$zero
/*  f0fd3c4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fd3c8:	18c00018 */ 	blez	$a2,.L0f0fd42c
/*  f0fd3cc:	000448c0 */ 	sll	$t1,$a0,0x3
/*  f0fd3d0:	01244823 */ 	subu	$t1,$t1,$a0
/*  f0fd3d4:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0fd3d8:	01244821 */ 	addu	$t1,$t1,$a0
/*  f0fd3dc:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f0fd3e0:	00062880 */ 	sll	$a1,$a2,0x2
/*  f0fd3e4:	00a62823 */ 	subu	$a1,$a1,$a2
/*  f0fd3e8:	01244823 */ 	subu	$t1,$t1,$a0
/*  f0fd3ec:	00094900 */ 	sll	$t1,$t1,0x4
/*  f0fd3f0:	3c068007 */ 	lui	$a2,%hi(menudialog_controllerpakmenu)
/*  f0fd3f4:	24c64c38 */ 	addiu	$a2,$a2,%lo(menudialog_controllerpakmenu)
/*  f0fd3f8:	01391821 */ 	addu	$v1,$t1,$t9
/*  f0fd3fc:	000528c0 */ 	sll	$a1,$a1,0x3
.L0f0fd400:
/*  f0fd400:	8c640464 */ 	lw	$a0,0x464($v1)
/*  f0fd404:	24420018 */ 	addiu	$v0,$v0,0x18
/*  f0fd408:	0045082a */ 	slt	$at,$v0,$a1
/*  f0fd40c:	10800005 */ 	beqz	$a0,.L0f0fd424
/*  f0fd410:	00000000 */ 	nop
/*  f0fd414:	8c8a0000 */ 	lw	$t2,0x0($a0)
/*  f0fd418:	14ca0002 */ 	bne	$a2,$t2,.L0f0fd424
/*  f0fd41c:	00000000 */ 	nop
/*  f0fd420:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0fd424:
/*  f0fd424:	1420fff6 */ 	bnez	$at,.L0f0fd400
/*  f0fd428:	24630018 */ 	addiu	$v1,$v1,0x18
.L0f0fd42c:
/*  f0fd42c:	14e00013 */ 	bnez	$a3,.L0f0fd47c
/*  f0fd430:	3c048007 */ 	lui	$a0,%hi(menudialog_fullcontrollerpak)
/*  f0fd434:	24841810 */ 	addiu	$a0,$a0,%lo(menudialog_fullcontrollerpak)
/*  f0fd438:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f0fd43c:	0fc3f3a3 */ 	jal	func0f0fce8c
/*  f0fd440:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f0fd444:	1000000e */ 	b	.L0f0fd480
/*  f0fd448:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fd44c:	3c048007 */ 	lui	$a0,%hi(menudialog_cannotreadgameboy)
/*  f0fd450:	24841878 */ 	addiu	$a0,$a0,%lo(menudialog_cannotreadgameboy)
/*  f0fd454:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f0fd458:	0fc3f3a3 */ 	jal	func0f0fce8c
/*  f0fd45c:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f0fd460:	10000007 */ 	b	.L0f0fd480
/*  f0fd464:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0fd468:	3c048007 */ 	lui	$a0,%hi(menudialog_datalost)
/*  f0fd46c:	2484191c */ 	addiu	$a0,$a0,%lo(menudialog_datalost)
/*  f0fd470:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f0fd474:	0fc3f3a3 */ 	jal	func0f0fce8c
/*  f0fd478:	8fa60020 */ 	lw	$a2,0x20($sp)
.L0f0fd47c:
/*  f0fd47c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0fd480:
/*  f0fd480:	8fab001c */ 	lw	$t3,0x1c($sp)
/*  f0fd484:	3c018007 */ 	lui	$at,%hi(g_MpPlayerNum)
/*  f0fd488:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0fd48c:	03e00008 */ 	jr	$ra
/*  f0fd490:	ac2b1448 */ 	sw	$t3,%lo(g_MpPlayerNum)($at)
);

GLOBAL_ASM(
glabel func0f0fd494
/*  f0fd494:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0fd498:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0fd49c:	3c10800a */ 	lui	$s0,%hi(g_MenuData)
/*  f0fd4a0:	261019c0 */ 	addiu	$s0,$s0,%lo(g_MenuData)
/*  f0fd4a4:	920f05d5 */ 	lbu	$t7,0x5d5($s0)
/*  f0fd4a8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0fd4ac:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0fd4b0:	35f80010 */ 	ori	$t8,$t7,0x10
/*  f0fd4b4:	0fc2d5be */ 	jal	currentPlayerGetMatrix
/*  f0fd4b8:	a21805d5 */ 	sb	$t8,0x5d5($s0)
/*  f0fd4bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0fd4c0:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f0fd4c4:	0c0056da */ 	jal	func00015b68
/*  f0fd4c8:	27a60024 */ 	addiu	$a2,$sp,0x24
/*  f0fd4cc:	27a40024 */ 	addiu	$a0,$sp,0x24
/*  f0fd4d0:	0fc2d341 */ 	jal	func0f0b4d04
/*  f0fd4d4:	27a50030 */ 	addiu	$a1,$sp,0x30
/*  f0fd4d8:	0c002f02 */ 	jal	viGetX
/*  f0fd4dc:	00000000 */ 	nop
/*  f0fd4e0:	c7a40030 */ 	lwc1	$f4,0x30($sp)
/*  f0fd4e4:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0fd4e8:	44083000 */ 	mfc1	$t0,$f6
/*  f0fd4ec:	04410003 */ 	bgez	$v0,.L0f0fd4fc
/*  f0fd4f0:	00024843 */ 	sra	$t1,$v0,0x1
/*  f0fd4f4:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0fd4f8:	00014843 */ 	sra	$t1,$at,0x1
.L0f0fd4fc:
/*  f0fd4fc:	01095023 */ 	subu	$t2,$t0,$t1
/*  f0fd500:	0c002f06 */ 	jal	viGetY
/*  f0fd504:	ae0a0670 */ 	sw	$t2,0x670($s0)
/*  f0fd508:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*  f0fd50c:	920f05d5 */ 	lbu	$t7,0x5d5($s0)
/*  f0fd510:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0fd514:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0fd518:	31f8fff7 */ 	andi	$t8,$t7,0xfff7
/*  f0fd51c:	a21805d5 */ 	sb	$t8,0x5d5($s0)
/*  f0fd520:	440c5000 */ 	mfc1	$t4,$f10
/*  f0fd524:	04410003 */ 	bgez	$v0,.L0f0fd534
/*  f0fd528:	00026843 */ 	sra	$t5,$v0,0x1
/*  f0fd52c:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0fd530:	00016843 */ 	sra	$t5,$at,0x1
.L0f0fd534:
/*  f0fd534:	018d7023 */ 	subu	$t6,$t4,$t5
/*  f0fd538:	ae0e0674 */ 	sw	$t6,0x674($s0)
/*  f0fd53c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0fd540:	03e00008 */ 	jr	$ra
/*  f0fd544:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

void func0f0fd548(s32 arg0)
{
	g_MenuData.unk669[g_MenuData.unk66e++] = arg0;
	g_MenuData.unk66f = 0;
}

GLOBAL_ASM(
glabel func0f0fd570
/*  f0fd570:	3c028007 */ 	lui	$v0,%hi(g_MpPlayerNum)
/*  f0fd574:	8c421448 */ 	lw	$v0,%lo(g_MpPlayerNum)($v0)
/*  f0fd578:	3c0f800a */ 	lui	$t7,%hi(g_Menus)
/*  f0fd57c:	25efe000 */ 	addiu	$t7,$t7,%lo(g_Menus)
/*  f0fd580:	000270c0 */ 	sll	$t6,$v0,0x3
/*  f0fd584:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f0fd588:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0fd58c:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f0fd590:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0fd594:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f0fd598:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0fd59c:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f0fd5a0:	8c7804f8 */ 	lw	$t8,0x4f8($v1)
/*  f0fd5a4:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f0fd5a8:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f0fd5ac:	13000024 */ 	beqz	$t8,.L0f0fd640
/*  f0fd5b0:	00808025 */ 	or	$s0,$a0,$zero
/*  f0fd5b4:	846504f4 */ 	lh	$a1,0x4f4($v1)
/*  f0fd5b8:	0002c8c0 */ 	sll	$t9,$v0,0x3
/*  f0fd5bc:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f0fd5c0:	18a0001f */ 	blez	$a1,.L0f0fd640
/*  f0fd5c4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fd5c8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0fd5cc:	0322c821 */ 	addu	$t9,$t9,$v0
/*  f0fd5d0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fd5d4:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f0fd5d8:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0fd5dc:	032f1821 */ 	addu	$v1,$t9,$t7
/*  f0fd5e0:	00603025 */ 	or	$a2,$v1,$zero
.L0f0fd5e4:
/*  f0fd5e4:	80c70478 */ 	lb	$a3,0x478($a2)
/*  f0fd5e8:	00045080 */ 	sll	$t2,$a0,0x2
/*  f0fd5ec:	01445023 */ 	subu	$t2,$t2,$a0
/*  f0fd5f0:	18e0000f */ 	blez	$a3,.L0f0fd630
/*  f0fd5f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0fd5f8:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0fd5fc:	006a4021 */ 	addu	$t0,$v1,$t2
.L0f0fd600:
/*  f0fd600:	8d090464 */ 	lw	$t1,0x464($t0)
/*  f0fd604:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0fd608:	0047082a */ 	slt	$at,$v0,$a3
/*  f0fd60c:	11200006 */ 	beqz	$t1,.L0f0fd628
/*  f0fd610:	00000000 */ 	nop
/*  f0fd614:	8d2b0000 */ 	lw	$t3,0x0($t1)
/*  f0fd618:	160b0003 */ 	bne	$s0,$t3,.L0f0fd628
/*  f0fd61c:	00000000 */ 	nop
/*  f0fd620:	10000008 */ 	b	.L0f0fd644
/*  f0fd624:	01201025 */ 	or	$v0,$t1,$zero
.L0f0fd628:
/*  f0fd628:	1420fff5 */ 	bnez	$at,.L0f0fd600
/*  f0fd62c:	25080004 */ 	addiu	$t0,$t0,0x4
.L0f0fd630:
/*  f0fd630:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f0fd634:	0085082a */ 	slt	$at,$a0,$a1
/*  f0fd638:	1420ffea */ 	bnez	$at,.L0f0fd5e4
/*  f0fd63c:	24c60018 */ 	addiu	$a2,$a2,0x18
.L0f0fd640:
/*  f0fd640:	00001025 */ 	or	$v0,$zero,$zero
.L0f0fd644:
/*  f0fd644:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f0fd648:	03e00008 */ 	jr	$ra
/*  f0fd64c:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

bool currentPlayerGetUnk1c04(void)
{
	return g_Vars.currentplayer->unk1c04;
}

struct menuitem menuitems_damagedcontrollerpak[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000030, (u32)&menuTextSaveDeviceName, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x02000030, L_MPWEAPONS(65), 0x00000000, NULL }, // "is damaged or"
	{ MENUITEMTYPE_LABEL,       0, 0x02000030, L_MPWEAPONS(66), 0x00000000, NULL }, // "inserted incorrectly"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPWEAPONS(67), 0x00000000, menuhandlerWarnRepairPak }, // "Attempt Repair"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPWEAPONS(68), 0x00000000, menuhandlerRetrySavePak }, // "Retry"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPWEAPONS(69), 0x00000000, NULL }, // "Continue without using the Controller Pak"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog menudialog_damagedcontrollerpak = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS(64), // "Damaged Controller Pak"
	menuitems_damagedcontrollerpak,
	menudialog000fcd48,
	0x00000020,
	NULL,
};

struct menuitem menuitems_fullcontrollerpak[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&menuTextSaveDeviceName, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x02000210, L_MPWEAPONS(71), 0x00000000, NULL }, // "is too full to save note - 1 note and 28 pages required to save"
	{ MENUITEMTYPE_LABEL,       0, 0x02000220, L_OPTIONS(3), 0x00000000, NULL }, // ""
	{ MENUITEMTYPE_LABEL,       0, 0x02000210, L_MPWEAPONS(72), 0x00000000, NULL }, // "Enter the Controller Pak Menu to free some space (hold START while powering up.)"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPWEAPONS(73), 0x00000000, NULL }, // "OK"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog menudialog_fullcontrollerpak = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS(70), // "Full Controller Pak"
	menuitems_fullcontrollerpak,
	menudialog000fcd48,
	0x00000020,
	NULL,
};

struct menuitem menuitems_cannotreadgameboy[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS(254), 0x00000000, NULL }, // "Cannot read Game Boy Game Pak. Check connections and make sure correct Game Boy Game Pak is being used."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPWEAPONS(255), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog menudialog_cannotreadgameboy = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS(253), // "Error"
	menuitems_cannotreadgameboy,
	NULL,
	0x00000020,
	NULL,
};

struct menuitem menuitems_datalost[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000030, (u32)&menuTextSaveDeviceName, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x02000030, L_MPWEAPONS(257), 0x00000000, NULL }, // "The saved data has"
	{ MENUITEMTYPE_LABEL,       0, 0x02000030, L_MPWEAPONS(258), 0x00000000, NULL }, // "been erased due to"
	{ MENUITEMTYPE_LABEL,       0, 0x02000030, L_MPWEAPONS(259), 0x00000000, NULL }, // "corruption or damage."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPWEAPONS(260), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog menudialog_datalost = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS(256), // "Error"
	menuitems_datalost,
	NULL,
	0x00000020,
	NULL,
};
