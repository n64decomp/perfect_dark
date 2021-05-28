#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/game_00b480.h"
#include "game/game_00b820.h"
#include "game/game_00c490.h"
#include "game/objectives.h"
#include "game/game_011110.h"
#include "game/inventory/init.h"
#include "game/game_0125a0.h"
#include "game/game_012d50.h"
#include "game/game_0147d0.h"
#include "game/chr/chr.h"
#include "game/game_02cde0.h"
#include "game/prop.h"
#include "game/game_091e10.h"
#include "game/atan2f.h"
#include "game/inventory/inventory.h"
#include "game/game_127910.h"
#include "game/bg.h"
#include "game/game_1655c0.h"
#include "game/file.h"
#include "game/lv.h"
#include "game/mplayer/scenarios.h"
#include "game/game_19aa80.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/memory.h"
#include "lib/model.h"
#include "lib/rng.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_184d0.h"
#include "lib/lib_233c0.h"
#include "lib/lib_24e40.h"
#include "data.h"
#include "types.h"

s32 var8009cc30;
u32 var8009cc34;
u32 var8009cc38;
u32 var8009cc3c;

struct tvscreen var80061a80 = {
	g_TvCmdlist00, // cmdlist
	0,           // offset
	0xffff,      // pause60
	0,           // tconfig
	0,           // rot
	1,           // xscale
	0,           // xscalefrac
	0,           // xscaleinc
	1,           // xscaleold
	1,           // xscalenew
	1,           // yscale
	0,           // yscalefrac
	0,           // yscaleinc
	1,           // yscaleold
	1,           // yscalenew
	0.5,         // xmid
	0,           // xmidfrac
	0,           // xmidinc
	0.5,         // xmidold
	0.5,         // xmidnew
	0.5,         // ymid
	0,           // ymidfrac
	0,           // ymidinc
	0.5,         // ymidold
	0.5,         // ymidnew
	0xff,        // red
	0xff,        // redold
	0xff,        // rednew
	0xff,        // green
	0xff,        // greenold
	0xff,        // greennew
	0xff,        // blue
	0xff,        // blueold
	0xff,        // bluenew
	0xff,        // alpha
	0xff,        // alphaold
	0xff,        // alphanew
	1,           // colfrac
	0,           // colinc
};

struct tvscreen var80061af4 = {
	var8006aaa0, // cmdlist
	0,           // offset
	0xffff,      // pause60
	0,           // tconfig
	0,           // rot
	1,           // xscale
	0,           // xscalefrac
	0,           // xscaleinc
	1,           // xscaleold
	1,           // xscalenew
	1,           // yscale
	0,           // yscalefrac
	0,           // yscaleinc
	1,           // yscaleold
	1,           // yscalenew
	0.5,         // xmid
	0,           // xmidfrac
	0,           // xmidinc
	0.5,         // xmidold
	0.5,         // xmidnew
	0.5,         // ymid
	0,           // ymidfrac
	0,           // ymidinc
	0.5,         // ymidold
	0.5,         // ymidnew
	0xff,        // red
	0xff,        // redold
	0xff,        // rednew
	0xff,        // green
	0xff,        // greenold
	0xff,        // greennew
	0xff,        // blue
	0xff,        // blueold
	0xff,        // bluenew
	0xff,        // alpha
	0xff,        // alphaold
	0xff,        // alphanew
	1,           // colfrac
	0,           // colinc
};

struct tvscreen var80061b68 = {
	var8006aae4, // cmdlist
	0,           // offset
	0xffff,      // pause60
	0,           // tconfig
	0,           // rot
	1,           // xscale
	0,           // xscalefrac
	0,           // xscaleinc
	1,           // xscaleold
	1,           // xscalenew
	1,           // yscale
	0,           // yscalefrac
	0,           // yscaleinc
	1,           // yscaleold
	1,           // yscalenew
	0.5,         // xmid
	0,           // xmidfrac
	0,           // xmidinc
	0.5,         // xmidold
	0.5,         // xmidnew
	0.5,         // ymid
	0,           // ymidfrac
	0,           // ymidinc
	0.5,         // ymidold
	0.5,         // ymidnew
	0xff,        // red
	0xff,        // redold
	0xff,        // rednew
	0xff,        // green
	0xff,        // greenold
	0xff,        // greennew
	0xff,        // blue
	0xff,        // blueold
	0xff,        // bluenew
	0xff,        // alpha
	0xff,        // alphaold
	0xff,        // alphanew
	1,           // colfrac
	0,           // colinc
};

u32 var80061bdc = 0x00000000;
f32 g_DoorScale = 1;
u32 var80061be4 = 0x00000000;
u32 var80061be8 = 0x00000000;
u32 var80061bec = 0x00000000;

void setupInit(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_Lifts); i++) {
		g_Lifts[i] = NULL;
	}

	var8009ce40 = 50;
	var8009ce44 = 10;
	var8009ce48 = 20;
	var8009ce4c = 15;
	g_NumProjectiles = IS4MB() ? 20 : 100;
	g_NumMonitorThings = IS4MB() ? 40 : 80;

	if (g_Vars.stagenum >= STAGE_TITLE) {
		var8009ce40 = 0;
		var8009ce44 = 0;
		var8009ce48 = 0;
		var8009ce4c = 0;
		g_NumProjectiles = 0;
		g_NumMonitorThings = 0;
	}

	func0f00cc8c();
	setupClearProxyMines();

	g_AlarmTimer = 0;
	g_AlarmAudioHandle = NULL;
	g_AlarmSpeakerWeight = 64;

	var800698e4 = 0;
	var800698e8 = 0;
	var800698ec[0] = 0;
	var800698ec[1] = 0;
	var800698ec[2] = 0;
	var800698f8 = 0;
	var800698fc = 0;
	var80069900 = 0;

	g_CountdownTimerVisible = true;
	g_CountdownTimerRunning = false;
	g_CountdownTimerValue = 0;

	var80069910 = 0;
	g_TintedGlassEnabled = false;

	if (var8009ce40 == 0) {
		var8009ce58 = NULL;
	} else {
		var8009ce58 = malloc(ALIGN16(var8009ce40 * sizeof(struct weaponobj)), MEMPOOL_STAGE);

		for (i = 0; i < var8009ce40; i++) {
			var8009ce58[i].base.prop = NULL;
		}

		var80069914 = 0;
	}

	if (var8009ce44 == 0) {
		var8009ce5c = NULL;
	} else {
		var8009ce5c = malloc(ALIGN16(var8009ce44 * sizeof(struct defaultobj)), MEMPOOL_STAGE);

		for (i = 0; i < var8009ce44; i++) {
			var8009ce5c[i].prop = NULL;
		}

		var80069918 = 0;
	}

	if (var8009ce48 == 0) {
		var8009ce60 = 0;
	} else {
		var8009ce60 = malloc(ALIGN16(var8009ce48 * sizeof(struct var8009ce60)), MEMPOOL_STAGE);

		for (i = 0; i < var8009ce48; i++) {
			var8009ce60[i].base.prop = NULL;
		}
	}

	if (var8009ce4c == 0) {
		var8009ce64 = 0;
	} else {
		var8009ce64 = malloc(ALIGN16(var8009ce4c * sizeof(struct defaultobj)), MEMPOOL_STAGE);

		for (i = 0; i < var8009ce4c; i++) {
			var8009ce64[i].prop = NULL;
		}
	}

	if (g_NumProjectiles == 0) {
		g_Projectiles = 0;
	} else {
		g_Projectiles = malloc(ALIGN16(g_NumProjectiles * sizeof(struct projectile)), MEMPOOL_STAGE);

		for (i = 0; i < g_NumProjectiles; i++) {
			g_Projectiles[i].flags = PROJECTILEFLAG_FREE;
		}
	}

	if (g_NumMonitorThings == 0) {
		g_MonitorThings = 0;
	} else {
		g_MonitorThings = malloc(ALIGN16(g_NumMonitorThings * sizeof(struct monitorthing)), MEMPOOL_STAGE);

		for (i = 0; i < g_NumMonitorThings; i++) {
			g_MonitorThings[i].flags = 0x00000001;
		}
	}

	g_LiftDoors = NULL;
	g_PadlockedDoors = NULL;
	g_SafeItems = NULL;
	g_LinkedScenery = NULL;
	g_BlockedPaths = NULL;

	var80069930 = 0;
	var80069934 = -1;
	g_CameraWaitMultiplier = 1;
	var8006994c = 1;
	var80069950 = 1;
	var80069954 = 1;
	var80069958 = 1;
	g_AmmoMultiplier = 1;

	g_MaxThrownLaptops = g_Vars.normmplayerisrunning ? 12 : PLAYERCOUNT();

	g_ThrownLaptops = malloc(ALIGN16(g_MaxThrownLaptops * sizeof(struct autogunobj)), MEMPOOL_STAGE);
	var8006996c = malloc(ALIGN16(g_MaxThrownLaptops * 0x2c), MEMPOOL_STAGE);

	for (i = 0; i < g_MaxThrownLaptops; i++) {
		g_ThrownLaptops[i].base.prop = NULL;
	}
}

void addLiftDoor(struct linkliftdoorobj *link)
{
	link->next = g_LiftDoors;
	g_LiftDoors = link;
}

void addPadlockedDoor(struct padlockeddoorobj *link)
{
	link->next = g_PadlockedDoors;
	g_PadlockedDoors = link;
}

void addSafeItem(struct safeitemobj *link)
{
	link->next = g_SafeItems;
	g_SafeItems = link;
}

void addConditionalScenery(struct linksceneryobj *link)
{
	link->next = g_LinkedScenery;
	g_LinkedScenery = link;
}

void addBlockedPath(struct blockedpathobj *blockedpath)
{
	blockedpath->next = g_BlockedPaths;
	g_BlockedPaths = blockedpath;
}

void func0f00cc8c(void)
{
	struct tvscreen tmp1;
	struct tvscreen tmp2;
	struct tvscreen tmp3;

	tmp1 = var80061a80;
	var8009ce98 = tmp1;

	tmp2 = var80061af4;
	var8009cf10 = tmp2;

	tmp3 = var80061b68;
	var8009cf88 = tmp3;
}

void setupClearProxyMines(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_Proxies); i++) {
		g_Proxies[i] = NULL;
	}
}

s32 setupCountCommandType(u32 type)
{
	struct defaultobj *obj = (struct defaultobj *)g_StageSetup.props;
	s32 count = 0;

	if (obj) {
		while (obj->type != OBJTYPE_END) {
			if (obj->type == (u8)type) {
				count++;
			}

			obj = (struct defaultobj *)((u32 *)obj + setupGetCommandLength((u32 *)obj));
		}
	}

	return count;
}

GLOBAL_ASM(
glabel setupGenericObject
.late_rodata
glabel var7f1a7f80
.word 0x358637bd
.text
/*  f00cee4:	27bdfeb8 */ 	addiu	$sp,$sp,-328
/*  f00cee8:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f00ceec:	00808025 */ 	or	$s0,$a0,$zero
/*  f00cef0:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f00cef4:	afa5014c */ 	sw	$a1,0x14c($sp)
/*  f00cef8:	84840004 */ 	lh	$a0,0x4($a0)
/*  f00cefc:	0fc2486d */ 	jal	propLoad
/*  f00cf00:	afa40140 */ 	sw	$a0,0x140($sp)
/*  f00cf04:	960e0000 */ 	lhu	$t6,0x0($s0)
/*  f00cf08:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f00cf0c:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f00cf10:	448e2000 */ 	mtc1	$t6,$f4
/*  f00cf14:	8fa80140 */ 	lw	$t0,0x140($sp)
/*  f00cf18:	05c10005 */ 	bgez	$t6,.L0f00cf30
/*  f00cf1c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f00cf20:	3c014f80 */ 	lui	$at,0x4f80
/*  f00cf24:	44814000 */ 	mtc1	$at,$f8
/*  f00cf28:	00000000 */ 	nop
/*  f00cf2c:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f00cf30:
/*  f00cf30:	3c013b80 */ 	lui	$at,0x3b80
/*  f00cf34:	44815000 */ 	mtc1	$at,$f10
/*  f00cf38:	8c6f0318 */ 	lw	$t7,0x318($v1)
/*  f00cf3c:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f00cf40:	15e00004 */ 	bnez	$t7,.L0f00cf54
/*  f00cf44:	e7a4009c */ 	swc1	$f4,0x9c($sp)
/*  f00cf48:	8c78031c */ 	lw	$t8,0x31c($v1)
/*  f00cf4c:	53000005 */ 	beqzl	$t8,.L0f00cf64
/*  f00cf50:	8e030008 */ 	lw	$v1,0x8($s0)
.L0f00cf54:
/*  f00cf54:	92190002 */ 	lbu	$t9,0x2($s0)
/*  f00cf58:	37290004 */ 	ori	$t1,$t9,0x4
/*  f00cf5c:	a2090002 */ 	sb	$t1,0x2($s0)
/*  f00cf60:	8e030008 */ 	lw	$v1,0x8($s0)
.L0f00cf64:
/*  f00cf64:	306a8000 */ 	andi	$t2,$v1,0x8000
/*  f00cf68:	1140001b */ 	beqz	$t2,.L0f00cfd8
/*  f00cf6c:	306e4000 */ 	andi	$t6,$v1,0x4000
/*  f00cf70:	920b0003 */ 	lbu	$t3,0x3($s0)
/*  f00cf74:	24010008 */ 	addiu	$at,$zero,0x8
/*  f00cf78:	02002025 */ 	or	$a0,$s0,$zero
/*  f00cf7c:	15610009 */ 	bne	$t3,$at,.L0f00cfa4
/*  f00cf80:	000868c0 */ 	sll	$t5,$t0,0x3
/*  f00cf84:	000860c0 */ 	sll	$t4,$t0,0x3
/*  f00cf88:	3c058008 */ 	lui	$a1,%hi(g_ModelStates)
/*  f00cf8c:	00ac2821 */ 	addu	$a1,$a1,$t4
/*  f00cf90:	8ca5b06c */ 	lw	$a1,%lo(g_ModelStates)($a1)
/*  f00cf94:	0fc22b83 */ 	jal	func0f08ae0c
/*  f00cf98:	02002025 */ 	or	$a0,$s0,$zero
/*  f00cf9c:	10000006 */ 	b	.L0f00cfb8
/*  f00cfa0:	8e040018 */ 	lw	$a0,0x18($s0)
.L0f00cfa4:
/*  f00cfa4:	3c058008 */ 	lui	$a1,%hi(g_ModelStates)
/*  f00cfa8:	00ad2821 */ 	addu	$a1,$a1,$t5
/*  f00cfac:	0fc1a94b */ 	jal	func0f06a52c
/*  f00cfb0:	8ca5b06c */ 	lw	$a1,%lo(g_ModelStates)($a1)
/*  f00cfb4:	8e040018 */ 	lw	$a0,0x18($s0)
.L0f00cfb8:
/*  f00cfb8:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
/*  f00cfbc:	c4880014 */ 	lwc1	$f8,0x14($a0)
/*  f00cfc0:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f00cfc4:	44055000 */ 	mfc1	$a1,$f10
/*  f00cfc8:	0c006bd6 */ 	jal	modelSetScale
/*  f00cfcc:	00000000 */ 	nop
/*  f00cfd0:	100001a3 */ 	b	.L0f00d660
/*  f00cfd4:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f00cfd8:
/*  f00cfd8:	51c0002d */ 	beqzl	$t6,.L0f00d090
/*  f00cfdc:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00cfe0:	0fc0a1dd */ 	jal	chrFindByLiteralId
/*  f00cfe4:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00cfe8:	8fa80140 */ 	lw	$t0,0x140($sp)
/*  f00cfec:	1040019b */ 	beqz	$v0,.L0f00d65c
/*  f00cff0:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f00cff4:	8c4f001c */ 	lw	$t7,0x1c($v0)
/*  f00cff8:	51e00199 */ 	beqzl	$t7,.L0f00d660
/*  f00cffc:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f00d000:	8c580020 */ 	lw	$t8,0x20($v0)
/*  f00d004:	53000196 */ 	beqzl	$t8,.L0f00d660
/*  f00d008:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f00d00c:	92190003 */ 	lbu	$t9,0x3($s0)
/*  f00d010:	24010008 */ 	addiu	$at,$zero,0x8
/*  f00d014:	02002025 */ 	or	$a0,$s0,$zero
/*  f00d018:	17210009 */ 	bne	$t9,$at,.L0f00d040
/*  f00d01c:	000850c0 */ 	sll	$t2,$t0,0x3
/*  f00d020:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f00d024:	3c058008 */ 	lui	$a1,%hi(g_ModelStates)
/*  f00d028:	00a92821 */ 	addu	$a1,$a1,$t1
/*  f00d02c:	8ca5b06c */ 	lw	$a1,%lo(g_ModelStates)($a1)
/*  f00d030:	0fc22b83 */ 	jal	func0f08ae0c
/*  f00d034:	02002025 */ 	or	$a0,$s0,$zero
/*  f00d038:	10000006 */ 	b	.L0f00d054
/*  f00d03c:	00403025 */ 	or	$a2,$v0,$zero
.L0f00d040:
/*  f00d040:	3c058008 */ 	lui	$a1,%hi(g_ModelStates)
/*  f00d044:	00aa2821 */ 	addu	$a1,$a1,$t2
/*  f00d048:	0fc1a94b */ 	jal	func0f06a52c
/*  f00d04c:	8ca5b06c */ 	lw	$a1,%lo(g_ModelStates)($a1)
/*  f00d050:	00403025 */ 	or	$a2,$v0,$zero
.L0f00d054:
/*  f00d054:	8e040018 */ 	lw	$a0,0x18($s0)
/*  f00d058:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f00d05c:	c4840014 */ 	lwc1	$f4,0x14($a0)
/*  f00d060:	afa6006c */ 	sw	$a2,0x6c($sp)
/*  f00d064:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f00d068:	44053000 */ 	mfc1	$a1,$f6
/*  f00d06c:	0c006bd6 */ 	jal	modelSetScale
/*  f00d070:	00000000 */ 	nop
/*  f00d074:	8fab0070 */ 	lw	$t3,0x70($sp)
/*  f00d078:	8fa4006c */ 	lw	$a0,0x6c($sp)
/*  f00d07c:	0fc181a6 */ 	jal	propReparent
/*  f00d080:	8d65001c */ 	lw	$a1,0x1c($t3)
/*  f00d084:	10000176 */ 	b	.L0f00d660
/*  f00d088:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f00d08c:	86040006 */ 	lh	$a0,0x6($s0)
.L0f00d090:
/*  f00d090:	2405006e */ 	addiu	$a1,$zero,0x6e
/*  f00d094:	0481001b */ 	bgez	$a0,.L0f00d104
/*  f00d098:	00000000 */ 	nop
/*  f00d09c:	920c0003 */ 	lbu	$t4,0x3($s0)
/*  f00d0a0:	24010008 */ 	addiu	$at,$zero,0x8
/*  f00d0a4:	02002025 */ 	or	$a0,$s0,$zero
/*  f00d0a8:	15810009 */ 	bne	$t4,$at,.L0f00d0d0
/*  f00d0ac:	000870c0 */ 	sll	$t6,$t0,0x3
/*  f00d0b0:	000868c0 */ 	sll	$t5,$t0,0x3
/*  f00d0b4:	3c058008 */ 	lui	$a1,%hi(g_ModelStates)
/*  f00d0b8:	00ad2821 */ 	addu	$a1,$a1,$t5
/*  f00d0bc:	8ca5b06c */ 	lw	$a1,%lo(g_ModelStates)($a1)
/*  f00d0c0:	0fc22b83 */ 	jal	func0f08ae0c
/*  f00d0c4:	02002025 */ 	or	$a0,$s0,$zero
/*  f00d0c8:	10000006 */ 	b	.L0f00d0e4
/*  f00d0cc:	8e040018 */ 	lw	$a0,0x18($s0)
.L0f00d0d0:
/*  f00d0d0:	3c058008 */ 	lui	$a1,%hi(g_ModelStates)
/*  f00d0d4:	00ae2821 */ 	addu	$a1,$a1,$t6
/*  f00d0d8:	0fc1a94b */ 	jal	func0f06a52c
/*  f00d0dc:	8ca5b06c */ 	lw	$a1,%lo(g_ModelStates)($a1)
/*  f00d0e0:	8e040018 */ 	lw	$a0,0x18($s0)
.L0f00d0e4:
/*  f00d0e4:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f00d0e8:	c48a0014 */ 	lwc1	$f10,0x14($a0)
/*  f00d0ec:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f00d0f0:	44054000 */ 	mfc1	$a1,$f8
/*  f00d0f4:	0c006bd6 */ 	jal	modelSetScale
/*  f00d0f8:	00000000 */ 	nop
/*  f00d0fc:	10000158 */ 	b	.L0f00d660
/*  f00d100:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f00d104:
/*  f00d104:	0fc456ac */ 	jal	padUnpack
/*  f00d108:	27a600ec */ 	addiu	$a2,$sp,0xec
/*  f00d10c:	8faf0134 */ 	lw	$t7,0x134($sp)
/*  f00d110:	27a400ac */ 	addiu	$a0,$sp,0xac
/*  f00d114:	c7a600f8 */ 	lwc1	$f6,0xf8($sp)
/*  f00d118:	59e00151 */ 	blezl	$t7,.L0f00d660
/*  f00d11c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f00d120:	c7a400fc */ 	lwc1	$f4,0xfc($sp)
/*  f00d124:	46003287 */ 	neg.s	$f10,$f6
/*  f00d128:	44800000 */ 	mtc1	$zero,$f0
/*  f00d12c:	c7a60100 */ 	lwc1	$f6,0x100($sp)
/*  f00d130:	46002207 */ 	neg.s	$f8,$f4
/*  f00d134:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f00d138:	46003287 */ 	neg.s	$f10,$f6
/*  f00d13c:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f00d140:	c7a80108 */ 	lwc1	$f8,0x108($sp)
/*  f00d144:	c7a6010c */ 	lwc1	$f6,0x10c($sp)
/*  f00d148:	c7a40104 */ 	lwc1	$f4,0x104($sp)
/*  f00d14c:	44050000 */ 	mfc1	$a1,$f0
/*  f00d150:	44060000 */ 	mfc1	$a2,$f0
/*  f00d154:	44070000 */ 	mfc1	$a3,$f0
/*  f00d158:	e7aa0018 */ 	swc1	$f10,0x18($sp)
/*  f00d15c:	e7a80020 */ 	swc1	$f8,0x20($sp)
/*  f00d160:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*  f00d164:	0c005b56 */ 	jal	func00016d58
/*  f00d168:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f00d16c:	c7aa00ec */ 	lwc1	$f10,0xec($sp)
/*  f00d170:	c7a400f0 */ 	lwc1	$f4,0xf0($sp)
/*  f00d174:	c7a800f4 */ 	lwc1	$f8,0xf4($sp)
/*  f00d178:	8fb80134 */ 	lw	$t8,0x134($sp)
/*  f00d17c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f00d180:	a7b90082 */ 	sh	$t9,0x82($sp)
/*  f00d184:	e7aa0090 */ 	swc1	$f10,0x90($sp)
/*  f00d188:	e7a40094 */ 	swc1	$f4,0x94($sp)
/*  f00d18c:	e7a80098 */ 	swc1	$f8,0x98($sp)
/*  f00d190:	a7b80080 */ 	sh	$t8,0x80($sp)
/*  f00d194:	0fc457c0 */ 	jal	padHasBboxData
/*  f00d198:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00d19c:	14400013 */ 	bnez	$v0,.L0f00d1ec
/*  f00d1a0:	8fa80140 */ 	lw	$t0,0x140($sp)
/*  f00d1a4:	8e090008 */ 	lw	$t1,0x8($s0)
/*  f00d1a8:	c7a600ec */ 	lwc1	$f6,0xec($sp)
/*  f00d1ac:	c7a800ec */ 	lwc1	$f8,0xec($sp)
/*  f00d1b0:	312a0002 */ 	andi	$t2,$t1,0x2
/*  f00d1b4:	51400008 */ 	beqzl	$t2,.L0f00d1d8
/*  f00d1b8:	c7a600f0 */ 	lwc1	$f6,0xf0($sp)
/*  f00d1bc:	c7aa00f0 */ 	lwc1	$f10,0xf0($sp)
/*  f00d1c0:	c7a400f4 */ 	lwc1	$f4,0xf4($sp)
/*  f00d1c4:	e7a600a0 */ 	swc1	$f6,0xa0($sp)
/*  f00d1c8:	e7aa00a4 */ 	swc1	$f10,0xa4($sp)
/*  f00d1cc:	10000021 */ 	b	.L0f00d254
/*  f00d1d0:	e7a400a8 */ 	swc1	$f4,0xa8($sp)
/*  f00d1d4:	c7a600f0 */ 	lwc1	$f6,0xf0($sp)
.L0f00d1d8:
/*  f00d1d8:	c7aa00f4 */ 	lwc1	$f10,0xf4($sp)
/*  f00d1dc:	e7a800a0 */ 	swc1	$f8,0xa0($sp)
/*  f00d1e0:	e7a600a4 */ 	swc1	$f6,0xa4($sp)
/*  f00d1e4:	1000001b */ 	b	.L0f00d254
/*  f00d1e8:	e7aa00a8 */ 	swc1	$f10,0xa8($sp)
.L0f00d1ec:
/*  f00d1ec:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00d1f0:	0fc457cd */ 	jal	padGetCentre
/*  f00d1f4:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f00d1f8:	c7a40124 */ 	lwc1	$f4,0x124($sp)
/*  f00d1fc:	c7a80128 */ 	lwc1	$f8,0x128($sp)
/*  f00d200:	3c013f00 */ 	lui	$at,0x3f00
/*  f00d204:	44815000 */ 	mtc1	$at,$f10
/*  f00d208:	46082181 */ 	sub.s	$f6,$f4,$f8
/*  f00d20c:	c7a80104 */ 	lwc1	$f8,0x104($sp)
/*  f00d210:	c7a400a0 */ 	lwc1	$f4,0xa0($sp)
/*  f00d214:	8fa80140 */ 	lw	$t0,0x140($sp)
/*  f00d218:	460a3002 */ 	mul.s	$f0,$f6,$f10
/*  f00d21c:	00000000 */ 	nop
/*  f00d220:	46080182 */ 	mul.s	$f6,$f0,$f8
/*  f00d224:	c7a800a4 */ 	lwc1	$f8,0xa4($sp)
/*  f00d228:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f00d22c:	c7a40108 */ 	lwc1	$f4,0x108($sp)
/*  f00d230:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f00d234:	e7aa00a0 */ 	swc1	$f10,0xa0($sp)
/*  f00d238:	c7a400a8 */ 	lwc1	$f4,0xa8($sp)
/*  f00d23c:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f00d240:	c7a8010c */ 	lwc1	$f8,0x10c($sp)
/*  f00d244:	46080182 */ 	mul.s	$f6,$f0,$f8
/*  f00d248:	e7aa00a4 */ 	swc1	$f10,0xa4($sp)
/*  f00d24c:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f00d250:	e7aa00a8 */ 	swc1	$f10,0xa8($sp)
.L0f00d254:
/*  f00d254:	920b0003 */ 	lbu	$t3,0x3($s0)
/*  f00d258:	24010008 */ 	addiu	$at,$zero,0x8
/*  f00d25c:	02002025 */ 	or	$a0,$s0,$zero
/*  f00d260:	15610007 */ 	bne	$t3,$at,.L0f00d280
/*  f00d264:	000860c0 */ 	sll	$t4,$t0,0x3
/*  f00d268:	3c058008 */ 	lui	$a1,%hi(g_ModelStates)
/*  f00d26c:	00ac2821 */ 	addu	$a1,$a1,$t4
/*  f00d270:	0fc22b83 */ 	jal	func0f08ae0c
/*  f00d274:	8ca5b06c */ 	lw	$a1,%lo(g_ModelStates)($a1)
/*  f00d278:	10000004 */ 	b	.L0f00d28c
/*  f00d27c:	afa2007c */ 	sw	$v0,0x7c($sp)
.L0f00d280:
/*  f00d280:	0fc1a954 */ 	jal	func0f06a550
/*  f00d284:	02002025 */ 	or	$a0,$s0,$zero
/*  f00d288:	afa2007c */ 	sw	$v0,0x7c($sp)
.L0f00d28c:
/*  f00d28c:	0fc457c0 */ 	jal	padHasBboxData
/*  f00d290:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00d294:	504000c1 */ 	beqzl	$v0,.L0f00d59c
/*  f00d298:	8e040018 */ 	lw	$a0,0x18($s0)
/*  f00d29c:	0fc1a2bd */ 	jal	objFindBboxRodata
/*  f00d2a0:	02002025 */ 	or	$a0,$s0,$zero
/*  f00d2a4:	104000bc */ 	beqz	$v0,.L0f00d598
/*  f00d2a8:	3c013f80 */ 	lui	$at,0x3f80
/*  f00d2ac:	44819000 */ 	mtc1	$at,$f18
/*  f00d2b0:	00000000 */ 	nop
/*  f00d2b4:	e7b20064 */ 	swc1	$f18,0x64($sp)
/*  f00d2b8:	8e030008 */ 	lw	$v1,0x8($s0)
/*  f00d2bc:	46009406 */ 	mov.s	$f16,$f18
/*  f00d2c0:	30640020 */ 	andi	$a0,$v1,0x20
/*  f00d2c4:	1080001c */ 	beqz	$a0,.L0f00d338
/*  f00d2c8:	30660040 */ 	andi	$a2,$v1,0x40
/*  f00d2cc:	c4420004 */ 	lwc1	$f2,0x4($v0)
/*  f00d2d0:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f00d2d4:	306d0002 */ 	andi	$t5,$v1,0x2
/*  f00d2d8:	4600103c */ 	c.lt.s	$f2,$f0
/*  f00d2dc:	00000000 */ 	nop
/*  f00d2e0:	45000015 */ 	bc1f	.L0f00d338
/*  f00d2e4:	00000000 */ 	nop
/*  f00d2e8:	11a0000b */ 	beqz	$t5,.L0f00d318
/*  f00d2ec:	c7a80120 */ 	lwc1	$f8,0x120($sp)
/*  f00d2f0:	c7a80120 */ 	lwc1	$f8,0x120($sp)
/*  f00d2f4:	c7a4011c */ 	lwc1	$f4,0x11c($sp)
/*  f00d2f8:	8e0e0018 */ 	lw	$t6,0x18($s0)
/*  f00d2fc:	46020281 */ 	sub.s	$f10,$f0,$f2
/*  f00d300:	46044181 */ 	sub.s	$f6,$f8,$f4
/*  f00d304:	c5c80014 */ 	lwc1	$f8,0x14($t6)
/*  f00d308:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f00d30c:	46043283 */ 	div.s	$f10,$f6,$f4
/*  f00d310:	10000009 */ 	b	.L0f00d338
/*  f00d314:	e7aa0064 */ 	swc1	$f10,0x64($sp)
.L0f00d318:
/*  f00d318:	c7a6011c */ 	lwc1	$f6,0x11c($sp)
/*  f00d31c:	8e0f0018 */ 	lw	$t7,0x18($s0)
/*  f00d320:	46020281 */ 	sub.s	$f10,$f0,$f2
/*  f00d324:	46064101 */ 	sub.s	$f4,$f8,$f6
/*  f00d328:	c5e80014 */ 	lwc1	$f8,0x14($t7)
/*  f00d32c:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f00d330:	46062283 */ 	div.s	$f10,$f4,$f6
/*  f00d334:	e7aa0064 */ 	swc1	$f10,0x64($sp)
.L0f00d338:
/*  f00d338:	10c00018 */ 	beqz	$a2,.L0f00d39c
/*  f00d33c:	30650080 */ 	andi	$a1,$v1,0x80
/*  f00d340:	c442000c */ 	lwc1	$f2,0xc($v0)
/*  f00d344:	c4400010 */ 	lwc1	$f0,0x10($v0)
/*  f00d348:	4600103c */ 	c.lt.s	$f2,$f0
/*  f00d34c:	00000000 */ 	nop
/*  f00d350:	45000012 */ 	bc1f	.L0f00d39c
/*  f00d354:	00000000 */ 	nop
/*  f00d358:	8e180018 */ 	lw	$t8,0x18($s0)
/*  f00d35c:	30790002 */ 	andi	$t9,$v1,0x2
/*  f00d360:	13200008 */ 	beqz	$t9,.L0f00d384
/*  f00d364:	c70c0014 */ 	lwc1	$f12,0x14($t8)
/*  f00d368:	46020281 */ 	sub.s	$f10,$f0,$f2
/*  f00d36c:	c7a80130 */ 	lwc1	$f8,0x130($sp)
/*  f00d370:	c7a4012c */ 	lwc1	$f4,0x12c($sp)
/*  f00d374:	46044181 */ 	sub.s	$f6,$f8,$f4
/*  f00d378:	460c5202 */ 	mul.s	$f8,$f10,$f12
/*  f00d37c:	10000007 */ 	b	.L0f00d39c
/*  f00d380:	46083483 */ 	div.s	$f18,$f6,$f8
.L0f00d384:
/*  f00d384:	46020201 */ 	sub.s	$f8,$f0,$f2
/*  f00d388:	c7a40128 */ 	lwc1	$f4,0x128($sp)
/*  f00d38c:	c7aa0124 */ 	lwc1	$f10,0x124($sp)
/*  f00d390:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f00d394:	460c4102 */ 	mul.s	$f4,$f8,$f12
/*  f00d398:	46043403 */ 	div.s	$f16,$f6,$f4
.L0f00d39c:
/*  f00d39c:	50a00019 */ 	beqzl	$a1,.L0f00d404
/*  f00d3a0:	c7a40064 */ 	lwc1	$f4,0x64($sp)
/*  f00d3a4:	c4420014 */ 	lwc1	$f2,0x14($v0)
/*  f00d3a8:	c4400018 */ 	lwc1	$f0,0x18($v0)
/*  f00d3ac:	4600103c */ 	c.lt.s	$f2,$f0
/*  f00d3b0:	00000000 */ 	nop
/*  f00d3b4:	45020013 */ 	bc1fl	.L0f00d404
/*  f00d3b8:	c7a40064 */ 	lwc1	$f4,0x64($sp)
/*  f00d3bc:	8e090018 */ 	lw	$t1,0x18($s0)
/*  f00d3c0:	306a0002 */ 	andi	$t2,$v1,0x2
/*  f00d3c4:	11400008 */ 	beqz	$t2,.L0f00d3e8
/*  f00d3c8:	c52c0014 */ 	lwc1	$f12,0x14($t1)
/*  f00d3cc:	46020101 */ 	sub.s	$f4,$f0,$f2
/*  f00d3d0:	c7aa0128 */ 	lwc1	$f10,0x128($sp)
/*  f00d3d4:	c7a80124 */ 	lwc1	$f8,0x124($sp)
/*  f00d3d8:	46085181 */ 	sub.s	$f6,$f10,$f8
/*  f00d3dc:	460c2282 */ 	mul.s	$f10,$f4,$f12
/*  f00d3e0:	10000007 */ 	b	.L0f00d400
/*  f00d3e4:	460a3403 */ 	div.s	$f16,$f6,$f10
.L0f00d3e8:
/*  f00d3e8:	46020281 */ 	sub.s	$f10,$f0,$f2
/*  f00d3ec:	c7a80130 */ 	lwc1	$f8,0x130($sp)
/*  f00d3f0:	c7a4012c */ 	lwc1	$f4,0x12c($sp)
/*  f00d3f4:	46044181 */ 	sub.s	$f6,$f8,$f4
/*  f00d3f8:	460c5202 */ 	mul.s	$f8,$f10,$f12
/*  f00d3fc:	46083483 */ 	div.s	$f18,$f6,$f8
.L0f00d400:
/*  f00d400:	c7a40064 */ 	lwc1	$f4,0x64($sp)
.L0f00d404:
/*  f00d404:	c7ac0064 */ 	lwc1	$f12,0x64($sp)
/*  f00d408:	4604803c */ 	c.lt.s	$f16,$f4
/*  f00d40c:	00000000 */ 	nop
/*  f00d410:	45020002 */ 	bc1fl	.L0f00d41c
/*  f00d414:	4610603c */ 	c.lt.s	$f12,$f16
/*  f00d418:	4610603c */ 	c.lt.s	$f12,$f16
.L0f00d41c:
/*  f00d41c:	46006386 */ 	mov.s	$f14,$f12
/*  f00d420:	45020003 */ 	bc1fl	.L0f00d430
/*  f00d424:	4612703c */ 	c.lt.s	$f14,$f18
/*  f00d428:	46008386 */ 	mov.s	$f14,$f16
/*  f00d42c:	4612703c */ 	c.lt.s	$f14,$f18
.L0f00d430:
/*  f00d430:	306b0002 */ 	andi	$t3,$v1,0x2
/*  f00d434:	306c0002 */ 	andi	$t4,$v1,0x2
/*  f00d438:	45000002 */ 	bc1f	.L0f00d444
/*  f00d43c:	00000000 */ 	nop
/*  f00d440:	46009386 */ 	mov.s	$f14,$f18
.L0f00d444:
/*  f00d444:	1480000f */ 	bnez	$a0,.L0f00d484
/*  f00d448:	306d0002 */ 	andi	$t5,$v1,0x2
/*  f00d44c:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f00d450:	11600007 */ 	beqz	$t3,.L0f00d470
/*  f00d454:	c4420004 */ 	lwc1	$f2,0x4($v0)
/*  f00d458:	46001032 */ 	c.eq.s	$f2,$f0
/*  f00d45c:	00000000 */ 	nop
/*  f00d460:	45000008 */ 	bc1f	.L0f00d484
/*  f00d464:	00000000 */ 	nop
/*  f00d468:	10000006 */ 	b	.L0f00d484
/*  f00d46c:	46007306 */ 	mov.s	$f12,$f14
.L0f00d470:
/*  f00d470:	46001032 */ 	c.eq.s	$f2,$f0
/*  f00d474:	00000000 */ 	nop
/*  f00d478:	45000002 */ 	bc1f	.L0f00d484
/*  f00d47c:	00000000 */ 	nop
/*  f00d480:	46007306 */ 	mov.s	$f12,$f14
.L0f00d484:
/*  f00d484:	14c0000f */ 	bnez	$a2,.L0f00d4c4
/*  f00d488:	460e6303 */ 	div.s	$f12,$f12,$f14
/*  f00d48c:	c4400010 */ 	lwc1	$f0,0x10($v0)
/*  f00d490:	11800007 */ 	beqz	$t4,.L0f00d4b0
/*  f00d494:	c442000c */ 	lwc1	$f2,0xc($v0)
/*  f00d498:	46001032 */ 	c.eq.s	$f2,$f0
/*  f00d49c:	00000000 */ 	nop
/*  f00d4a0:	45000008 */ 	bc1f	.L0f00d4c4
/*  f00d4a4:	00000000 */ 	nop
/*  f00d4a8:	10000006 */ 	b	.L0f00d4c4
/*  f00d4ac:	46007486 */ 	mov.s	$f18,$f14
.L0f00d4b0:
/*  f00d4b0:	46001032 */ 	c.eq.s	$f2,$f0
/*  f00d4b4:	00000000 */ 	nop
/*  f00d4b8:	45000002 */ 	bc1f	.L0f00d4c4
/*  f00d4bc:	00000000 */ 	nop
/*  f00d4c0:	46007406 */ 	mov.s	$f16,$f14
.L0f00d4c4:
/*  f00d4c4:	14a0000f */ 	bnez	$a1,.L0f00d504
/*  f00d4c8:	3c017f1a */ 	lui	$at,%hi(var7f1a7f80)
/*  f00d4cc:	c4400018 */ 	lwc1	$f0,0x18($v0)
/*  f00d4d0:	11a00007 */ 	beqz	$t5,.L0f00d4f0
/*  f00d4d4:	c4420014 */ 	lwc1	$f2,0x14($v0)
/*  f00d4d8:	46001032 */ 	c.eq.s	$f2,$f0
/*  f00d4dc:	00000000 */ 	nop
/*  f00d4e0:	45000008 */ 	bc1f	.L0f00d504
/*  f00d4e4:	00000000 */ 	nop
/*  f00d4e8:	10000006 */ 	b	.L0f00d504
/*  f00d4ec:	46007406 */ 	mov.s	$f16,$f14
.L0f00d4f0:
/*  f00d4f0:	46001032 */ 	c.eq.s	$f2,$f0
/*  f00d4f4:	00000000 */ 	nop
/*  f00d4f8:	45000002 */ 	bc1f	.L0f00d504
/*  f00d4fc:	00000000 */ 	nop
/*  f00d500:	46007486 */ 	mov.s	$f18,$f14
.L0f00d504:
/*  f00d504:	c4207f80 */ 	lwc1	$f0,%lo(var7f1a7f80)($at)
/*  f00d508:	460e8403 */ 	div.s	$f16,$f16,$f14
/*  f00d50c:	3c013f80 */ 	lui	$at,0x3f80
/*  f00d510:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00d514:	4600603e */ 	c.le.s	$f12,$f0
/*  f00d518:	00000000 */ 	nop
/*  f00d51c:	45010009 */ 	bc1t	.L0f00d544
/*  f00d520:	460e9483 */ 	div.s	$f18,$f18,$f14
/*  f00d524:	4600803e */ 	c.le.s	$f16,$f0
/*  f00d528:	00000000 */ 	nop
/*  f00d52c:	45030006 */ 	bc1tl	.L0f00d548
/*  f00d530:	44816000 */ 	mtc1	$at,$f12
/*  f00d534:	4600903e */ 	c.le.s	$f18,$f0
/*  f00d538:	00000000 */ 	nop
/*  f00d53c:	45020006 */ 	bc1fl	.L0f00d558
/*  f00d540:	e7ae0054 */ 	swc1	$f14,0x54($sp)
.L0f00d544:
/*  f00d544:	44816000 */ 	mtc1	$at,$f12
.L0f00d548:
/*  f00d548:	00000000 */ 	nop
/*  f00d54c:	46006486 */ 	mov.s	$f18,$f12
/*  f00d550:	46006406 */ 	mov.s	$f16,$f12
/*  f00d554:	e7ae0054 */ 	swc1	$f14,0x54($sp)
.L0f00d558:
/*  f00d558:	e7b00060 */ 	swc1	$f16,0x60($sp)
/*  f00d55c:	0c005789 */ 	jal	func00015e24
/*  f00d560:	e7b2005c */ 	swc1	$f18,0x5c($sp)
/*  f00d564:	c7ac0060 */ 	lwc1	$f12,0x60($sp)
/*  f00d568:	0c0057a0 */ 	jal	func00015e80
/*  f00d56c:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00d570:	c7ac005c */ 	lwc1	$f12,0x5c($sp)
/*  f00d574:	0c0057b7 */ 	jal	func00015edc
/*  f00d578:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00d57c:	8e040018 */ 	lw	$a0,0x18($s0)
/*  f00d580:	c7ae0054 */ 	lwc1	$f14,0x54($sp)
/*  f00d584:	c48a0014 */ 	lwc1	$f10,0x14($a0)
/*  f00d588:	460e5182 */ 	mul.s	$f6,$f10,$f14
/*  f00d58c:	44053000 */ 	mfc1	$a1,$f6
/*  f00d590:	0c006bd6 */ 	jal	modelSetScale
/*  f00d594:	00000000 */ 	nop
.L0f00d598:
/*  f00d598:	8e040018 */ 	lw	$a0,0x18($s0)
.L0f00d59c:
/*  f00d59c:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f00d5a0:	c4880014 */ 	lwc1	$f8,0x14($a0)
/*  f00d5a4:	46044282 */ 	mul.s	$f10,$f8,$f4
/*  f00d5a8:	44055000 */ 	mfc1	$a1,$f10
/*  f00d5ac:	0c006bd6 */ 	jal	modelSetScale
/*  f00d5b0:	00000000 */ 	nop
/*  f00d5b4:	8e0e0018 */ 	lw	$t6,0x18($s0)
/*  f00d5b8:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00d5bc:	0c0057c1 */ 	jal	func00015f04
/*  f00d5c0:	c5cc0014 */ 	lwc1	$f12,0x14($t6)
/*  f00d5c4:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f00d5c8:	8fb9007c */ 	lw	$t9,0x7c($sp)
/*  f00d5cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f00d5d0:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f00d5d4:	07010004 */ 	bgez	$t8,.L0f00d5e8
/*  f00d5d8:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f00d5dc:	93290001 */ 	lbu	$t1,0x1($t9)
/*  f00d5e0:	352a0010 */ 	ori	$t2,$t1,0x10
/*  f00d5e4:	a32a0001 */ 	sb	$t2,0x1($t9)
.L0f00d5e8:
/*  f00d5e8:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*  f00d5ec:	27a600ac */ 	addiu	$a2,$sp,0xac
/*  f00d5f0:	27a70080 */ 	addiu	$a3,$sp,0x80
/*  f00d5f4:	316c0002 */ 	andi	$t4,$t3,0x2
/*  f00d5f8:	1180000a */ 	beqz	$t4,.L0f00d624
/*  f00d5fc:	27ae00a0 */ 	addiu	$t6,$sp,0xa0
/*  f00d600:	27ad00a0 */ 	addiu	$t5,$sp,0xa0
/*  f00d604:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f00d608:	02002025 */ 	or	$a0,$s0,$zero
/*  f00d60c:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f00d610:	27a600ac */ 	addiu	$a2,$sp,0xac
/*  f00d614:	0fc1aad8 */ 	jal	func0f06ab60
/*  f00d618:	27a70080 */ 	addiu	$a3,$sp,0x80
/*  f00d61c:	10000004 */ 	b	.L0f00d630
/*  f00d620:	8e0f0040 */ 	lw	$t7,0x40($s0)
.L0f00d624:
/*  f00d624:	0fc1a9cc */ 	jal	func0f06a730
/*  f00d628:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f00d62c:	8e0f0040 */ 	lw	$t7,0x40($s0)
.L0f00d630:
/*  f00d630:	31f88000 */ 	andi	$t8,$t7,0x8000
/*  f00d634:	13000005 */ 	beqz	$t8,.L0f00d64c
/*  f00d638:	00000000 */ 	nop
/*  f00d63c:	0fc1814e */ 	jal	propAppendToList1
/*  f00d640:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f00d644:	10000003 */ 	b	.L0f00d654
/*  f00d648:	00000000 */ 	nop
.L0f00d64c:
/*  f00d64c:	0fc1812f */ 	jal	propPrependToList1
/*  f00d650:	8fa4007c */ 	lw	$a0,0x7c($sp)
.L0f00d654:
/*  f00d654:	0fc180bc */ 	jal	propShow
/*  f00d658:	8fa4007c */ 	lw	$a0,0x7c($sp)
.L0f00d65c:
/*  f00d65c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f00d660:
/*  f00d660:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f00d664:	27bd0148 */ 	addiu	$sp,$sp,0x148
/*  f00d668:	03e00008 */ 	jr	$ra
/*  f00d66c:	00000000 */ 	nop
);

/**
 * Assigns a weapon to its home.
 *
 * Its home is a chr's hand or a pad, as defined in the stage's setup file.
 *
 * The Marquis of Queensbury Rules (everyone unarmed) and Enemy Rockets cheats
 * are implemented here.
 */
void weaponAssignToHome(struct weaponobj *weapon, s32 cmdindex)
{
	if (weapon->base.flags & OBJFLAG_ASSIGNEDTOCHR) {
		u32 stack[2];
		struct chrdata *chr = chrFindByLiteralId(weapon->base.pad);

		if (chr && chr->prop && chr->model) {
			if (cheatIsActive(CHEAT_MARQUIS)) {
				// NTSC 1.0 and newer simplifies the Marqis logic
#if VERSION >= VERSION_NTSC_1_0
				weapon->base.flags &= ~OBJFLAG_DEACTIVATED;
				weapon->base.flags |= OBJFLAG_20000000;
				weaponLoadProjectileModels(weapon->weaponnum);
				func0f08b25c(weapon, chr);
#else
				if (g_Vars.stagenum == STAGE_INVESTIGATION
						&& lvGetDifficulty() == DIFF_PA
						&& weapon->weaponnum == WEAPON_K7AVENGER) {
					weaponLoadProjectileModels(weapon->weaponnum);
					func0f08b25c(weapon, chr);
				} else if (g_Vars.stagenum == STAGE_ATTACKSHIP) {
					weapon->base.flags &= ~OBJFLAG_DEACTIVATED;
					weapon->base.flags |= OBJFLAG_20000000;
					weaponLoadProjectileModels(weapon->weaponnum);
					func0f08b25c(weapon, chr);
				} else {
					weapon->weaponnum = WEAPON_NONE;
				}
#endif
			} else {
				if (cheatIsActive(CHEAT_ENEMYROCKETS)) {
					switch (weapon->weaponnum) {
					case WEAPON_FALCON2:
					case WEAPON_FALCON2_SILENCER:
					case WEAPON_FALCON2_SCOPE:
					case WEAPON_MAGSEC4:
					case WEAPON_MAULER:
					case WEAPON_PHOENIX:
					case WEAPON_DY357MAGNUM:
					case WEAPON_DY357LX:
					case WEAPON_CMP150:
					case WEAPON_CYCLONE:
					case WEAPON_CALLISTO:
					case WEAPON_RCP120:
					case WEAPON_LAPTOPGUN:
					case WEAPON_DRAGON:
					case WEAPON_AR34:
					case WEAPON_SUPERDRAGON:
					case WEAPON_SHOTGUN:
					case WEAPON_REAPER:
					case WEAPON_SNIPERRIFLE:
					case WEAPON_FARSIGHT:
					case WEAPON_DEVASTATOR:
					case WEAPON_ROCKETLAUNCHER:
					case WEAPON_SLAYER:
					case WEAPON_COMBATKNIFE:
					case WEAPON_CROSSBOW:
					case WEAPON_TRANQUILIZER:
					case WEAPON_GRENADE:
					case WEAPON_NBOMB:
					case WEAPON_TIMEDMINE:
					case WEAPON_PROXIMITYMINE:
					case WEAPON_REMOTEMINE:
						weapon->weaponnum = WEAPON_ROCKETLAUNCHER;
						weapon->base.modelnum = MODEL_CHRDYROCKET;
						weapon->base.extrascale = 256;
						break;
					case WEAPON_K7AVENGER:
						// Don't replace the K7 guard's weapon in Investigation
						// because it would make an objective impossible.
						// @bug: It's still replaced on PD mode difficulty.
						if (g_Vars.stagenum != STAGE_INVESTIGATION || lvGetDifficulty() != DIFF_PA) {
							weapon->weaponnum = WEAPON_ROCKETLAUNCHER;
							weapon->base.modelnum = MODEL_CHRDYROCKET;
							weapon->base.extrascale = 256;
						}
						break;
					}
				}

				weaponLoadProjectileModels(weapon->weaponnum);
				func0f08b25c(weapon, chr);
			}
		}
	} else {
		bool giveweapon = true;

		if (g_Vars.normmplayerisrunning || g_Vars.lvmpbotlevel) {
			struct mpweapon *mpweapon;
			s32 mpweaponnum;

			var8009cc30 = -1;

			// Seems like a weaponnum >= 240 means an mpweaponnum...
			switch (weapon->weaponnum) {
			case 0xf0:
			case 0xf1:
			case 0xf2:
			case 0xf3:
			case 0xf4:
			case 0xf5:
			case 0xf6:
			case 0xf7:
			case 0xf8:
			case 0xf9:
			case 0xfa:
			case 0xfb:
			case 0xfc:
			case 0xfd:
			case 0xfe:
			case 0xff:
				mpweaponnum = weapon->weaponnum - 0xf0;
				mpweapon = func0f188e24(mpweaponnum);
				var8009cc30 = mpweaponnum;
				weapon->weaponnum = mpweapon->weaponnum;
				weapon->base.modelnum = mpweapon->model;
				weapon->base.extrascale = mpweapon->extrascale;
				giveweapon = mpweapon->giveweapon;

				if (mpweapon->weaponnum == WEAPON_MPSHIELD) {
					struct shieldobj *shield = (struct shieldobj *)weapon;
					shield->base.modelnum = MODEL_CHRSHIELD;
					shield->base.type = OBJTYPE_SHIELD;
					shield->base.flags |= OBJFLAG_01000000 | OBJFLAG_INVINCIBLE;
					shield->base.flags2 |= OBJFLAG2_00200000 | OBJFLAG2_IMMUNETOGUNFIRE;
					shield->initialamount = 1;
					shield->amount = 1;
					setupGenericObject(&shield->base, cmdindex);
					giveweapon = false;
				}
				break;
			}
		}

		if (weapon->weaponnum != WEAPON_NONE && giveweapon) {
			weaponLoadProjectileModels(weapon->weaponnum);
			setupGenericObject(&weapon->base, cmdindex);
		}
	}
}

void setupHat(struct hatobj *hat, s32 cmdindex)
{
	if (hat->base.flags & OBJFLAG_ASSIGNEDTOCHR) {
		struct chrdata *chr = chrFindByLiteralId(hat->base.pad);

		if (chr && chr->prop && chr->model) {
			hatAssignToChr(hat, chr);
		}
	} else {
		setupGenericObject(&hat->base, cmdindex);
	}
}

void setupKey(struct keyobj *key, s32 cmdindex)
{
	setupGenericObject(&key->base, cmdindex);
}

void setupMine(struct mineobj *mine, s32 cmdindex)
{
	mine->base.type = OBJTYPE_WEAPON;

	setupGenericObject(&mine->base, cmdindex);

	if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
		mine->base.hidden = mine->base.hidden & 0x0fffffff | OBJHFLAG_20000000;
	}

	mine->base.prop->unk3f_02 = 1;
}

void setupCctv(struct cctvobj *cctv, s32 cmdindex)
{
	struct defaultobj *obj = &cctv->base;

	setupGenericObject(obj, cmdindex);

	if (cctv->lookatpadnum >= 0) {
		struct coord lenspos;
		union modelrodata *lens = modelGetPartRodata(obj->model->filedata, MODELPART_CCTV_LENS);
		struct pad pad;
		f32 xdiff;
		f32 ydiff;
		f32 zdiff;

		padUnpack(cctv->lookatpadnum, PADFIELD_POS, &pad);

		lenspos.x = lens->position.pos.x;
		lenspos.y = lens->position.pos.y;
		lenspos.z = lens->position.pos.z;

		func00016208(obj->realrot, &lenspos);

		lenspos.x += obj->prop->pos.x;
		lenspos.y += obj->prop->pos.y;
		lenspos.z += obj->prop->pos.z;

		xdiff = lenspos.x - pad.pos.x;
		ydiff = lenspos.y - pad.pos.y;
		zdiff = lenspos.z - pad.pos.z;

		if (ydiff) {
			// empty
		}

		func00016d58(&cctv->camrotm, 0.0f, 0.0f, 0.0f, xdiff, ydiff, zdiff, 0.0f, 1.0f, 0.0f);
		func00015f04(obj->model->scale, &cctv->camrotm);

		cctv->toleft = 0;
		cctv->yleft = *(s32 *)&cctv->yleft * M_BADTAU / 65536.0f;
		cctv->yright = *(s32 *)&cctv->yright * M_BADTAU / 65536.0f;
		cctv->yspeed = 0.0f;
		cctv->ymaxspeed = *(s32 *)&cctv->ymaxspeed * M_BADTAU / 65536.0f;
		cctv->maxdist = *(s32 *)&cctv->maxdist;
		cctv->yrot = cctv->yleft;

		cctv->yzero = atan2f(xdiff, zdiff);
		cctv->xzero = M_BADTAU - atan2f(ydiff, sqrtf(xdiff * xdiff + zdiff * zdiff));

		if (xdiff || zdiff) {
			// empty
		}

		cctv->seebondtime60 = 0;
	}
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel setupAutogun
.late_rodata
glabel var7f1a9250pf
.word 0x40c907a9
glabel var7f1a9254pf
.word 0x40f13c65
glabel var7f1a9258pf
.word 0xbfc907a9
.text
/*  f00dbe0:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f00dbe4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f00dbe8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f00dbec:	0fc033b1 */ 	jal	setupGenericObject
/*  f00dbf0:	00808025 */ 	move	$s0,$a0
/*  f00dbf4:	8e0e0080 */ 	lw	$t6,0x80($s0)
/*  f00dbf8:	3c014780 */ 	lui	$at,0x4780
/*  f00dbfc:	44811000 */ 	mtc1	$at,$f2
/*  f00dc00:	448e2000 */ 	mtc1	$t6,$f4
/*  f00dc04:	8e0f0084 */ 	lw	$t7,0x84($s0)
/*  f00dc08:	3c017f1b */ 	lui	$at,0x7f1b
/*  f00dc0c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f00dc10:	c42c9250 */ 	lwc1	$f12,-0x6db0($at)
/*  f00dc14:	3c017f1b */ 	lui	$at,0x7f1b
/*  f00dc18:	c4289254 */ 	lwc1	$f8,-0x6dac($at)
/*  f00dc1c:	448f9000 */ 	mtc1	$t7,$f18
/*  f00dc20:	3c0142c8 */ 	lui	$at,0x42c8
/*  f00dc24:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f00dc28:	44813000 */ 	mtc1	$at,$f6
/*  f00dc2c:	8e180064 */ 	lw	$t8,0x64($s0)
/*  f00dc30:	8e190068 */ 	lw	$t9,0x68($s0)
/*  f00dc34:	44800000 */ 	mtc1	$zero,$f0
/*  f00dc38:	2403ffff */ 	li	$v1,-1
/*  f00dc3c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f00dc40:	a200005f */ 	sb	$zero,0x5f($s0)
/*  f00dc44:	ae030090 */ 	sw	$v1,0x90($s0)
/*  f00dc48:	ae030094 */ 	sw	$v1,0x94($s0)
/*  f00dc4c:	ae030098 */ 	sw	$v1,0x98($s0)
/*  f00dc50:	46025403 */ 	div.s	$f16,$f10,$f2
/*  f00dc54:	24040030 */ 	li	$a0,0x30
/*  f00dc58:	24050004 */ 	li	$a1,0x4
/*  f00dc5c:	e600006c */ 	swc1	$f0,0x6c($s0)
/*  f00dc60:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f00dc64:	e6000070 */ 	swc1	$f0,0x70($s0)
/*  f00dc68:	e6000060 */ 	swc1	$f0,0x60($s0)
/*  f00dc6c:	e6000078 */ 	swc1	$f0,0x78($s0)
/*  f00dc70:	e600007c */ 	swc1	$f0,0x7c($s0)
/*  f00dc74:	e6000074 */ 	swc1	$f0,0x74($s0)
/*  f00dc78:	e6000088 */ 	swc1	$f0,0x88($s0)
/*  f00dc7c:	e600008c */ 	swc1	$f0,0x8c($s0)
/*  f00dc80:	46024283 */ 	div.s	$f10,$f8,$f2
/*  f00dc84:	e6100080 */ 	swc1	$f16,0x80($s0)
/*  f00dc88:	44988000 */ 	mtc1	$t8,$f16
/*  f00dc8c:	44994000 */ 	mtc1	$t9,$f8
/*  f00dc90:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f00dc94:	460c9102 */ 	mul.s	$f4,$f18,$f12
/*  f00dc98:	e60a0084 */ 	swc1	$f10,0x84($s0)
/*  f00dc9c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f00dca0:	46022183 */ 	div.s	$f6,$f4,$f2
/*  f00dca4:	460c5402 */ 	mul.s	$f16,$f10,$f12
/*  f00dca8:	46028483 */ 	div.s	$f18,$f16,$f2
/*  f00dcac:	e6060064 */ 	swc1	$f6,0x64($s0)
/*  f00dcb0:	0c004856 */ 	jal	malloc
/*  f00dcb4:	e6120068 */ 	swc1	$f18,0x68($s0)
/*  f00dcb8:	2403ffff */ 	li	$v1,-1
/*  f00dcbc:	ae02009c */ 	sw	$v0,0x9c($s0)
/*  f00dcc0:	a0430000 */ 	sb	$v1,0x0($v0)
/*  f00dcc4:	8604005c */ 	lh	$a0,0x5c($s0)
/*  f00dcc8:	44800000 */ 	mtc1	$zero,$f0
/*  f00dccc:	240800ff */ 	li	$t0,0xff
/*  f00dcd0:	a200005e */ 	sb	$zero,0x5e($s0)
/*  f00dcd4:	a20800a9 */ 	sb	$t0,0xa9($s0)
/*  f00dcd8:	0480001f */ 	bltz	$a0,.PF0f00dd58
/*  f00dcdc:	e60000a0 */ 	swc1	$f0,0xa0($s0)
/*  f00dce0:	24050002 */ 	li	$a1,0x2
/*  f00dce4:	0fc45964 */ 	jal	padUnpack
/*  f00dce8:	27a60028 */ 	addiu	$a2,$sp,0x28
/*  f00dcec:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f00dcf0:	c7a8002c */ 	lwc1	$f8,0x2c($sp)
/*  f00dcf4:	c7a40028 */ 	lwc1	$f4,0x28($sp)
/*  f00dcf8:	c44a000c */ 	lwc1	$f10,0xc($v0)
/*  f00dcfc:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f00dd00:	c7b20030 */ 	lwc1	$f18,0x30($sp)
/*  f00dd04:	460a4401 */ 	sub.s	$f16,$f8,$f10
/*  f00dd08:	46062301 */ 	sub.s	$f12,$f4,$f6
/*  f00dd0c:	e7b00084 */ 	swc1	$f16,0x84($sp)
/*  f00dd10:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f00dd14:	e7ac0088 */ 	swc1	$f12,0x88($sp)
/*  f00dd18:	46049381 */ 	sub.s	$f14,$f18,$f4
/*  f00dd1c:	0fc2599c */ 	jal	atan2f
/*  f00dd20:	e7ae0080 */ 	swc1	$f14,0x80($sp)
/*  f00dd24:	c7a20088 */ 	lwc1	$f2,0x88($sp)
/*  f00dd28:	c7ae0080 */ 	lwc1	$f14,0x80($sp)
/*  f00dd2c:	e6000060 */ 	swc1	$f0,0x60($s0)
/*  f00dd30:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f00dd34:	00000000 */ 	nop
/*  f00dd38:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*  f00dd3c:	0c0127b4 */ 	jal	sqrtf
/*  f00dd40:	46083300 */ 	add.s	$f12,$f6,$f8
/*  f00dd44:	c7ac0084 */ 	lwc1	$f12,0x84($sp)
/*  f00dd48:	0fc2599c */ 	jal	atan2f
/*  f00dd4c:	46000386 */ 	mov.s	$f14,$f0
/*  f00dd50:	10000007 */ 	b	.PF0f00dd70
/*  f00dd54:	e6000074 */ 	swc1	$f0,0x74($s0)
.PF0f00dd58:
/*  f00dd58:	86090004 */ 	lh	$t1,0x4($s0)
/*  f00dd5c:	24010144 */ 	li	$at,0x144
/*  f00dd60:	15210003 */ 	bne	$t1,$at,.PF0f00dd70
/*  f00dd64:	3c017f1b */ 	lui	$at,0x7f1b
/*  f00dd68:	c42a9258 */ 	lwc1	$f10,-0x6da8($at)
/*  f00dd6c:	e60a0074 */ 	swc1	$f10,0x74($s0)
.PF0f00dd70:
/*  f00dd70:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f00dd74:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f00dd78:	27bd0090 */ 	addiu	$sp,$sp,0x90
/*  f00dd7c:	03e00008 */ 	jr	$ra
/*  f00dd80:	00000000 */ 	nop
);
#else
void setupAutogun(struct autogunobj *autogun, s32 cmdindex)
{
	setupGenericObject(&autogun->base, cmdindex);

	autogun->firecount = 0;
	autogun->lastseebond60 = -1;
	autogun->lastaimbond60 = -1;
	autogun->allowsoundframe = -1;
	autogun->yrot = 0;
	autogun->yspeed = 0;
	autogun->yzero = 0;
	autogun->xrot = 0;
	autogun->xspeed = 0;
	autogun->xzero = 0;
	autogun->barrelspeed = 0;
	autogun->barrelrot = 0;
	autogun->maxspeed = *(s32 *)&autogun->maxspeed * M_BADTAU / 65536.0f;
	autogun->aimdist = *(s32 *)&autogun->aimdist * 100.0f / 65536.0f;
	autogun->ymaxleft = *(s32 *)&autogun->ymaxleft * M_BADTAU / 65536.0f;
	autogun->ymaxright = *(s32 *)&autogun->ymaxright * M_BADTAU / 65536.0f;
	autogun->beam = malloc(ALIGN16(sizeof(struct beam)), MEMPOOL_STAGE);
	autogun->beam->age = -1;
	autogun->firing = false;
	autogun->ammoquantity = 255;
	autogun->shotbondsum = 0;

	if (autogun->targetpad >= 0) {
		u32 stack1;
		f32 xdiff;
		f32 ydiff;
		f32 zdiff;
		u32 stack2;
		struct pad pad;

		padUnpack(autogun->targetpad, PADFIELD_POS, &pad);

		xdiff = pad.pos.x - autogun->base.prop->pos.x;
		ydiff = pad.pos.y - autogun->base.prop->pos.y;
		zdiff = pad.pos.z - autogun->base.prop->pos.z;

		autogun->yzero = atan2f(xdiff, zdiff);
		autogun->xzero = atan2f(ydiff, sqrtf(xdiff * xdiff + zdiff * zdiff));
	} else if (autogun->base.modelnum == MODEL_CETROOFGUN) {
		// Deep Sea roofgun
		autogun->xzero = -1.5705462694168f;
	}
}
#endif

void setupHangingMonitors(struct hangingmonitorsobj *monitors, s32 cmdindex)
{
	setupGenericObject(&monitors->base, cmdindex);
}

void setupSingleMonitor(struct singlemonitorobj *monitor, s32 cmdindex)
{
	u32 stack[2];

	monitor->screen = var8009ce98;
	tvscreenSetImageByNum(&monitor->screen, monitor->imagenum);

	// The setup files never place any monitors on a -1 pad, so this code is
	// unreachable. It appears to allow attaching monitors to other objects.
	if (monitor->base.pad < 0 && (monitor->base.flags & OBJFLAG_00008000) == 0) {
		s32 modelnum = monitor->base.modelnum;
		struct defaultobj *owner = (struct defaultobj *)setupGetPtrToCommandByIndex(cmdindex + monitor->owneroffset);
		struct prop *prop;
		f32 scale;
		struct coord spa4;
		Mtxf sp64;
		Mtxf sp24;

		propLoad(modelnum);

		scale = monitor->base.extrascale * (1.0f / 256.0f);

		if (g_Vars.normmplayerisrunning || g_Vars.lvmpbotlevel) {
			monitor->base.hidden2 |= OBJH2FLAG_04;
		}

		prop = func0f06a550(&monitor->base);
		monitor->base.monitorthing = monitorthingGetNew();

		if (prop && monitor->base.monitorthing) {
			monitor->base.hidden |= OBJHFLAG_00000040;
			modelSetScale(monitor->base.model, monitor->base.model->scale * scale);
			monitor->base.model->attachedto = owner->model;

			if (monitor->ownerpart == MODELPART_0000) {
				monitor->base.model->unk1c = modelGetPart(owner->model->filedata, MODELPART_0000);
			} else if (monitor->ownerpart == MODELPART_0001) {
				monitor->base.model->unk1c = modelGetPart(owner->model->filedata, MODELPART_0001);
			} else if (monitor->ownerpart == MODELPART_0002) {
				monitor->base.model->unk1c = modelGetPart(owner->model->filedata, MODELPART_0002);
			} else {
				monitor->base.model->unk1c = modelGetPart(owner->model->filedata, MODELPART_0003);
			}

			propReparent(prop, owner->prop);
			func000162e8(0.3664608001709f, &sp64);
			func00015f04(monitor->base.model->scale / owner->model->scale, &sp64);
			modelGetRootPosition(monitor->base.model, &spa4);

			spa4.x = -spa4.x;
			spa4.y = -spa4.y;
			spa4.z = -spa4.z;

			func000166dc(&spa4, &sp24);
			func00015be4(&sp64, &sp24, &monitor->base.monitorthing->matrix);
		}
	} else {
		setupGenericObject(&monitor->base, cmdindex);
	}

	if (monitor->base.prop && (monitor->base.flags & OBJFLAG_40000000)) {
		monitor->base.prop->flags |= PROPFLAG_01;
	}
}

void setupMultiMonitor(struct multimonitorobj *monitor, s32 cmdindex)
{
	monitor->screens[0] = var8009ce98;
	tvscreenSetImageByNum(&monitor->screens[0], monitor->imagenums[0]);

	monitor->screens[1] = var8009ce98;
	tvscreenSetImageByNum(&monitor->screens[1], monitor->imagenums[1]);

	monitor->screens[2] = var8009ce98;
	tvscreenSetImageByNum(&monitor->screens[2], monitor->imagenums[2]);

	monitor->screens[3] = var8009ce98;
	tvscreenSetImageByNum(&monitor->screens[3], monitor->imagenums[3]);

	setupGenericObject(&monitor->base, cmdindex);
}

s32 func0f00e1f8(s32 padnum)
{
	f32 mult;
	struct coord centre;
	struct coord coord;
	u32 stack;
	struct pad pad;

	padGetCentre(padnum, &centre);
	padUnpack(padnum, PADFIELD_BBOX | PADFIELD_UP, &pad);

	mult = (pad.bbox.ymax - pad.bbox.ymin) * 0.5f + 10;

	coord.x = pad.up.x * mult + centre.x;
	coord.y = pad.up.y * mult + centre.y;
	coord.z = pad.up.z * mult + centre.z;

	centre.x = centre.x - pad.up.x * mult;
	centre.y = centre.y - pad.up.y * mult;
	centre.z = centre.z - pad.up.z * mult;

	return func0f164e8c(&centre, &coord);
}

s32 func0f00e2b0(s32 padnum)
{
	f32 mult;
	struct coord centre;
	struct coord coord;
	u32 stack;
	struct pad pad;

	padGetCentre(padnum, &centre);
	padUnpack(padnum, PADFIELD_BBOX | PADFIELD_NORMAL, &pad);

	mult = (pad.bbox.xmax - pad.bbox.xmin) * 0.5f + 10;

	coord.x = pad.normal.x * mult + centre.x;
	coord.y = pad.normal.y * mult + centre.y;
	coord.z = pad.normal.z * mult + centre.z;

	centre.x = centre.x - pad.normal.x * mult;
	centre.y = centre.y - pad.normal.y * mult;
	centre.z = centre.z - pad.normal.z * mult;

	return func0f164e8c(&centre, &coord);
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel setupDoor
.late_rodata
glabel var7f1a9260pf
.word 0x3fc907a9
glabel var7f1a9264pf
.word 0x3fc907a9
glabel var7f1a9268pf
.word 0x358637bd
glabel var7f1a926cpf
.word 0x3f99999a
.text
/*  f00e350:	27bdfe38 */ 	addiu	$sp,$sp,-456
/*  f00e354:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f00e358:	00808025 */ 	move	$s0,$a0
/*  f00e35c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f00e360:	afa501cc */ 	sw	$a1,0x1cc($sp)
/*  f00e364:	84840004 */ 	lh	$a0,0x4($a0)
/*  f00e368:	240effff */ 	li	$t6,-1
/*  f00e36c:	afae01bc */ 	sw	$t6,0x1bc($sp)
/*  f00e370:	0fc2482d */ 	jal	propLoad
/*  f00e374:	afa401c0 */ 	sw	$a0,0x1c0($sp)
/*  f00e378:	960f0070 */ 	lhu	$t7,0x70($s0)
/*  f00e37c:	31f80040 */ 	andi	$t8,$t7,0x40
/*  f00e380:	53000004 */ 	beqzl	$t8,.PF0f00e394
/*  f00e384:	8e190008 */ 	lw	$t9,0x8($s0)
/*  f00e388:	0fc45ad2 */ 	jal	func0f116068
/*  f00e38c:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00e390:	8e190008 */ 	lw	$t9,0x8($s0)
.PF0f00e394:
/*  f00e394:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f00e398:	05030005 */ 	bgezl	$t0,.PF0f00e3b0
/*  f00e39c:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00e3a0:	0fc038a6 */ 	jal	func0f00e2b0
/*  f00e3a4:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00e3a8:	afa201bc */ 	sw	$v0,0x1bc($sp)
/*  f00e3ac:	86040006 */ 	lh	$a0,0x6($s0)
.PF0f00e3b0:
/*  f00e3b0:	2405007e */ 	li	$a1,0x7e
/*  f00e3b4:	0fc45964 */ 	jal	padUnpack
/*  f00e3b8:	27a60168 */ 	addiu	$a2,$sp,0x168
/*  f00e3bc:	3c018006 */ 	lui	$at,0x8006
/*  f00e3c0:	c42c18b0 */ 	lwc1	$f12,0x18b0($at)
/*  f00e3c4:	3c013f80 */ 	lui	$at,0x3f80
/*  f00e3c8:	44812000 */ 	mtc1	$at,$f4
/*  f00e3cc:	c7a60198 */ 	lwc1	$f6,0x198($sp)
/*  f00e3d0:	27a50168 */ 	addiu	$a1,$sp,0x168
/*  f00e3d4:	460c2032 */ 	c.eq.s	$f4,$f12
/*  f00e3d8:	00000000 */ 	nop
/*  f00e3dc:	4503005b */ 	bc1tl	.PF0f00e54c
/*  f00e3e0:	8fab01b0 */ 	lw	$t3,0x1b0($sp)
/*  f00e3e4:	460c3202 */ 	mul.s	$f8,$f6,$f12
/*  f00e3e8:	c7aa019c */ 	lwc1	$f10,0x19c($sp)
/*  f00e3ec:	8fa301bc */ 	lw	$v1,0x1bc($sp)
/*  f00e3f0:	3c0a800a */ 	lui	$t2,0x800a
/*  f00e3f4:	460c5402 */ 	mul.s	$f16,$f10,$f12
/*  f00e3f8:	00034880 */ 	sll	$t1,$v1,0x2
/*  f00e3fc:	01234821 */ 	addu	$t1,$t1,$v1
/*  f00e400:	e7a80198 */ 	swc1	$f8,0x198($sp)
/*  f00e404:	0460004e */ 	bltz	$v1,.PF0f00e540
/*  f00e408:	e7b0019c */ 	swc1	$f16,0x19c($sp)
/*  f00e40c:	8d4a526c */ 	lw	$t2,0x526c($t2)
/*  f00e410:	00094880 */ 	sll	$t1,$t1,0x2
/*  f00e414:	c7a40170 */ 	lwc1	$f4,0x170($sp)
/*  f00e418:	012a1021 */ 	addu	$v0,$t1,$t2
/*  f00e41c:	c4520008 */ 	lwc1	$f18,0x8($v0)
/*  f00e420:	c7aa016c */ 	lwc1	$f10,0x16c($sp)
/*  f00e424:	c4420000 */ 	lwc1	$f2,0x0($v0)
/*  f00e428:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f00e42c:	c4520004 */ 	lwc1	$f18,0x4($v0)
/*  f00e430:	3c013f80 */ 	lui	$at,0x3f80
/*  f00e434:	c44e000c */ 	lwc1	$f14,0xc($v0)
/*  f00e438:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f00e43c:	c7aa0168 */ 	lwc1	$f10,0x168($sp)
/*  f00e440:	46025482 */ 	mul.s	$f18,$f10,$f2
/*  f00e444:	46049280 */ 	add.s	$f10,$f18,$f4
/*  f00e448:	44812000 */ 	mtc1	$at,$f4
/*  f00e44c:	460a3000 */ 	add.s	$f0,$f6,$f10
/*  f00e450:	46046181 */ 	sub.s	$f6,$f12,$f4
/*  f00e454:	460e0481 */ 	sub.s	$f18,$f0,$f14
/*  f00e458:	46069002 */ 	mul.s	$f0,$f18,$f6
/*  f00e45c:	00000000 */ 	nop
/*  f00e460:	46001282 */ 	mul.s	$f10,$f2,$f0
/*  f00e464:	e7aa0150 */ 	swc1	$f10,0x150($sp)
/*  f00e468:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f00e46c:	46002482 */ 	mul.s	$f18,$f4,$f0
/*  f00e470:	c7a40150 */ 	lwc1	$f4,0x150($sp)
/*  f00e474:	e7b20154 */ 	swc1	$f18,0x154($sp)
/*  f00e478:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f00e47c:	c7b2018c */ 	lwc1	$f18,0x18c($sp)
/*  f00e480:	46003282 */ 	mul.s	$f10,$f6,$f0
/*  f00e484:	e7aa0158 */ 	swc1	$f10,0x158($sp)
/*  f00e488:	46122182 */ 	mul.s	$f6,$f4,$f18
/*  f00e48c:	c7a40190 */ 	lwc1	$f4,0x190($sp)
/*  f00e490:	c7aa0154 */ 	lwc1	$f10,0x154($sp)
/*  f00e494:	46045482 */ 	mul.s	$f18,$f10,$f4
/*  f00e498:	c7a40194 */ 	lwc1	$f4,0x194($sp)
/*  f00e49c:	46123280 */ 	add.s	$f10,$f6,$f18
/*  f00e4a0:	c7a60158 */ 	lwc1	$f6,0x158($sp)
/*  f00e4a4:	46062482 */ 	mul.s	$f18,$f4,$f6
/*  f00e4a8:	460a9000 */ 	add.s	$f0,$f18,$f10
/*  f00e4ac:	c7aa0150 */ 	lwc1	$f10,0x150($sp)
/*  f00e4b0:	46004100 */ 	add.s	$f4,$f8,$f0
/*  f00e4b4:	c7a80180 */ 	lwc1	$f8,0x180($sp)
/*  f00e4b8:	46008480 */ 	add.s	$f18,$f16,$f0
/*  f00e4bc:	e7a40198 */ 	swc1	$f4,0x198($sp)
/*  f00e4c0:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f00e4c4:	c7b00154 */ 	lwc1	$f16,0x154($sp)
/*  f00e4c8:	e7b2019c */ 	swc1	$f18,0x19c($sp)
/*  f00e4cc:	c7b20184 */ 	lwc1	$f18,0x184($sp)
/*  f00e4d0:	46128282 */ 	mul.s	$f10,$f16,$f18
/*  f00e4d4:	c7b00188 */ 	lwc1	$f16,0x188($sp)
/*  f00e4d8:	46068482 */ 	mul.s	$f18,$f16,$f6
/*  f00e4dc:	c7b001a4 */ 	lwc1	$f16,0x1a4($sp)
/*  f00e4e0:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f00e4e4:	c7a401a0 */ 	lwc1	$f4,0x1a0($sp)
/*  f00e4e8:	46089000 */ 	add.s	$f0,$f18,$f8
/*  f00e4ec:	c7a80150 */ 	lwc1	$f8,0x150($sp)
/*  f00e4f0:	46008480 */ 	add.s	$f18,$f16,$f0
/*  f00e4f4:	c7b00154 */ 	lwc1	$f16,0x154($sp)
/*  f00e4f8:	46002280 */ 	add.s	$f10,$f4,$f0
/*  f00e4fc:	c7a40174 */ 	lwc1	$f4,0x174($sp)
/*  f00e500:	e7b201a4 */ 	swc1	$f18,0x1a4($sp)
/*  f00e504:	c7b20178 */ 	lwc1	$f18,0x178($sp)
/*  f00e508:	e7aa01a0 */ 	swc1	$f10,0x1a0($sp)
/*  f00e50c:	46044282 */ 	mul.s	$f10,$f8,$f4
/*  f00e510:	00000000 */ 	nop
/*  f00e514:	46128202 */ 	mul.s	$f8,$f16,$f18
/*  f00e518:	c7b0017c */ 	lwc1	$f16,0x17c($sp)
/*  f00e51c:	46068482 */ 	mul.s	$f18,$f16,$f6
/*  f00e520:	c7b001ac */ 	lwc1	$f16,0x1ac($sp)
/*  f00e524:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f00e528:	c7aa01a8 */ 	lwc1	$f10,0x1a8($sp)
/*  f00e52c:	46049000 */ 	add.s	$f0,$f18,$f4
/*  f00e530:	46008180 */ 	add.s	$f6,$f16,$f0
/*  f00e534:	46005200 */ 	add.s	$f8,$f10,$f0
/*  f00e538:	e7a601ac */ 	swc1	$f6,0x1ac($sp)
/*  f00e53c:	e7a801a8 */ 	swc1	$f8,0x1a8($sp)
.PF0f00e540:
/*  f00e540:	0fc45b1c */ 	jal	padCopyBboxFromPad
/*  f00e544:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00e548:	8fab01b0 */ 	lw	$t3,0x1b0($sp)
.PF0f00e54c:
/*  f00e54c:	8fac01c0 */ 	lw	$t4,0x1c0($sp)
/*  f00e550:	3c048008 */ 	lui	$a0,0x8008
/*  f00e554:	196000e6 */ 	blez	$t3,.PF0f00e8f0
/*  f00e558:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f00e55c:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f00e560:	0fc1a2ff */ 	jal	modelFileDataFindBboxRodata
/*  f00e564:	8c84b53c */ 	lw	$a0,-0x4ac4($a0)
/*  f00e568:	c7b20174 */ 	lwc1	$f18,0x174($sp)
/*  f00e56c:	44800000 */ 	mtc1	$zero,$f0
/*  f00e570:	c7aa0178 */ 	lwc1	$f10,0x178($sp)
/*  f00e574:	46009107 */ 	neg.s	$f4,$f18
/*  f00e578:	c7b0017c */ 	lwc1	$f16,0x17c($sp)
/*  f00e57c:	46005207 */ 	neg.s	$f8,$f10
/*  f00e580:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f00e584:	c7a40184 */ 	lwc1	$f4,0x184($sp)
/*  f00e588:	c7aa0188 */ 	lwc1	$f10,0x188($sp)
/*  f00e58c:	c7b20180 */ 	lwc1	$f18,0x180($sp)
/*  f00e590:	46008187 */ 	neg.s	$f6,$f16
/*  f00e594:	44050000 */ 	mfc1	$a1,$f0
/*  f00e598:	44060000 */ 	mfc1	$a2,$f0
/*  f00e59c:	44070000 */ 	mfc1	$a3,$f0
/*  f00e5a0:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f00e5a4:	e7a60018 */ 	swc1	$f6,0x18($sp)
/*  f00e5a8:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f00e5ac:	27a40110 */ 	addiu	$a0,$sp,0x110
/*  f00e5b0:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f00e5b4:	e7aa0024 */ 	swc1	$f10,0x24($sp)
/*  f00e5b8:	0c005aba */ 	jal	func00016d58
/*  f00e5bc:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f00e5c0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f00e5c4:	c42c9260 */ 	lwc1	$f12,-0x6da0($at)
/*  f00e5c8:	0c00581e */ 	jal	func000162e8
/*  f00e5cc:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00e5d0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f00e5d4:	c42c9264 */ 	lwc1	$f12,-0x6d9c($at)
/*  f00e5d8:	0c005864 */ 	jal	func00016400
/*  f00e5dc:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f00e5e0:	27a40060 */ 	addiu	$a0,$sp,0x60
/*  f00e5e4:	0c0055e3 */ 	jal	func000159fc
/*  f00e5e8:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00e5ec:	27a40110 */ 	addiu	$a0,$sp,0x110
/*  f00e5f0:	0c0055e3 */ 	jal	func000159fc
/*  f00e5f4:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00e5f8:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00e5fc:	0fc45a85 */ 	jal	padGetCentre
/*  f00e600:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f00e604:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f00e608:	c7a801a4 */ 	lwc1	$f8,0x1a4($sp)
/*  f00e60c:	c7b001a0 */ 	lwc1	$f16,0x1a0($sp)
/*  f00e610:	c4520008 */ 	lwc1	$f18,0x8($v0)
/*  f00e614:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f00e618:	46104181 */ 	sub.s	$f6,$f8,$f16
/*  f00e61c:	c7b001a8 */ 	lwc1	$f16,0x1a8($sp)
/*  f00e620:	c7a801ac */ 	lwc1	$f8,0x1ac($sp)
/*  f00e624:	46049281 */ 	sub.s	$f10,$f18,$f4
/*  f00e628:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f00e62c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f00e630:	46104481 */ 	sub.s	$f18,$f8,$f16
/*  f00e634:	c4209268 */ 	lwc1	$f0,-0x6d98($at)
/*  f00e638:	c7b00198 */ 	lwc1	$f16,0x198($sp)
/*  f00e63c:	460a3303 */ 	div.s	$f12,$f6,$f10
/*  f00e640:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f00e644:	c7a8019c */ 	lwc1	$f8,0x19c($sp)
/*  f00e648:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00e64c:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f00e650:	c4460018 */ 	lwc1	$f6,0x18($v0)
/*  f00e654:	46104101 */ 	sub.s	$f4,$f8,$f16
/*  f00e658:	460a9083 */ 	div.s	$f2,$f18,$f10
/*  f00e65c:	c4520014 */ 	lwc1	$f18,0x14($v0)
/*  f00e660:	4600603e */ 	c.le.s	$f12,$f0
/*  f00e664:	46123281 */ 	sub.s	$f10,$f6,$f18
/*  f00e668:	45010008 */ 	bc1t	.PF0f00e68c
/*  f00e66c:	460a2383 */ 	div.s	$f14,$f4,$f10
/*  f00e670:	4600103e */ 	c.le.s	$f2,$f0
/*  f00e674:	00000000 */ 	nop
/*  f00e678:	45030005 */ 	bc1tl	.PF0f00e690
/*  f00e67c:	3c013f80 */ 	lui	$at,0x3f80
/*  f00e680:	4600703e */ 	c.le.s	$f14,$f0
/*  f00e684:	00000000 */ 	nop
/*  f00e688:	45000005 */ 	bc1f	.PF0f00e6a0
.PF0f00e68c:
/*  f00e68c:	3c013f80 */ 	lui	$at,0x3f80
.PF0f00e690:
/*  f00e690:	44816000 */ 	mtc1	$at,$f12
/*  f00e694:	00000000 */ 	nop
/*  f00e698:	46006386 */ 	mov.s	$f14,$f12
/*  f00e69c:	46006086 */ 	mov.s	$f2,$f12
.PF0f00e6a0:
/*  f00e6a0:	e7a2004c */ 	swc1	$f2,0x4c($sp)
/*  f00e6a4:	e7ac0050 */ 	swc1	$f12,0x50($sp)
/*  f00e6a8:	0c0056ed */ 	jal	func00015e24
/*  f00e6ac:	e7ae0048 */ 	swc1	$f14,0x48($sp)
/*  f00e6b0:	c7ac004c */ 	lwc1	$f12,0x4c($sp)
/*  f00e6b4:	0c005704 */ 	jal	func00015e80
/*  f00e6b8:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00e6bc:	c7ac0048 */ 	lwc1	$f12,0x48($sp)
/*  f00e6c0:	0c00571b */ 	jal	func00015edc
/*  f00e6c4:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00e6c8:	c7a80168 */ 	lwc1	$f8,0x168($sp)
/*  f00e6cc:	c7b0016c */ 	lwc1	$f16,0x16c($sp)
/*  f00e6d0:	c7a60170 */ 	lwc1	$f6,0x170($sp)
/*  f00e6d4:	8fae01b0 */ 	lw	$t6,0x1b0($sp)
/*  f00e6d8:	240fffff */ 	li	$t7,-1
/*  f00e6dc:	a7af00ee */ 	sh	$t7,0xee($sp)
/*  f00e6e0:	e7a800fc */ 	swc1	$f8,0xfc($sp)
/*  f00e6e4:	e7b00100 */ 	swc1	$f16,0x100($sp)
/*  f00e6e8:	e7a60104 */ 	swc1	$f6,0x104($sp)
/*  f00e6ec:	a7ae00ec */ 	sh	$t6,0xec($sp)
/*  f00e6f0:	96020072 */ 	lhu	$v0,0x72($s0)
/*  f00e6f4:	24010004 */ 	li	$at,0x4
/*  f00e6f8:	c7b201ac */ 	lwc1	$f18,0x1ac($sp)
/*  f00e6fc:	10410004 */ 	beq	$v0,$at,.PF0f00e710
/*  f00e700:	c7a401a8 */ 	lwc1	$f4,0x1a8($sp)
/*  f00e704:	24010008 */ 	li	$at,0x8
/*  f00e708:	1441000e */ 	bne	$v0,$at,.PF0f00e744
/*  f00e70c:	c7aa01a0 */ 	lwc1	$f10,0x1a0($sp)
.PF0f00e710:
/*  f00e710:	46049001 */ 	sub.s	$f0,$f18,$f4
/*  f00e714:	c7aa0174 */ 	lwc1	$f10,0x174($sp)
/*  f00e718:	c7b00178 */ 	lwc1	$f16,0x178($sp)
/*  f00e71c:	c7b2017c */ 	lwc1	$f18,0x17c($sp)
/*  f00e720:	46005202 */ 	mul.s	$f8,$f10,$f0
/*  f00e724:	00000000 */ 	nop
/*  f00e728:	46008182 */ 	mul.s	$f6,$f16,$f0
/*  f00e72c:	00000000 */ 	nop
/*  f00e730:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f00e734:	e7a80054 */ 	swc1	$f8,0x54($sp)
/*  f00e738:	e7a60058 */ 	swc1	$f6,0x58($sp)
/*  f00e73c:	1000000e */ 	b	.PF0f00e778
/*  f00e740:	e7a4005c */ 	swc1	$f4,0x5c($sp)
.PF0f00e744:
/*  f00e744:	c7a801a4 */ 	lwc1	$f8,0x1a4($sp)
/*  f00e748:	c7b00180 */ 	lwc1	$f16,0x180($sp)
/*  f00e74c:	c7b20184 */ 	lwc1	$f18,0x184($sp)
/*  f00e750:	46085001 */ 	sub.s	$f0,$f10,$f8
/*  f00e754:	c7aa0188 */ 	lwc1	$f10,0x188($sp)
/*  f00e758:	46008182 */ 	mul.s	$f6,$f16,$f0
/*  f00e75c:	00000000 */ 	nop
/*  f00e760:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f00e764:	00000000 */ 	nop
/*  f00e768:	46005202 */ 	mul.s	$f8,$f10,$f0
/*  f00e76c:	e7a60054 */ 	swc1	$f6,0x54($sp)
/*  f00e770:	e7a40058 */ 	swc1	$f4,0x58($sp)
/*  f00e774:	e7a8005c */ 	swc1	$f8,0x5c($sp)
.PF0f00e778:
/*  f00e778:	8e18005c */ 	lw	$t8,0x5c($s0)
/*  f00e77c:	3c014780 */ 	lui	$at,0x4780
/*  f00e780:	44810000 */ 	mtc1	$at,$f0
/*  f00e784:	44988000 */ 	mtc1	$t8,$f16
/*  f00e788:	8e080064 */ 	lw	$t0,0x64($s0)
/*  f00e78c:	8e190060 */ 	lw	$t9,0x60($s0)
/*  f00e790:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f00e794:	44888000 */ 	mtc1	$t0,$f16
/*  f00e798:	44992000 */ 	mtc1	$t9,$f4
/*  f00e79c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f00e7a0:	c422926c */ 	lwc1	$f2,-0x6d94($at)
/*  f00e7a4:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f00e7a8:	3c014c7a */ 	lui	$at,0x4c7a
/*  f00e7ac:	44816000 */ 	mtc1	$at,$f12
/*  f00e7b0:	8e090068 */ 	lw	$t1,0x68($s0)
/*  f00e7b4:	8e0a006c */ 	lw	$t2,0x6c($s0)
/*  f00e7b8:	46003483 */ 	div.s	$f18,$f6,$f0
/*  f00e7bc:	8e0b00bc */ 	lw	$t3,0xbc($s0)
/*  f00e7c0:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f00e7c4:	46005203 */ 	div.s	$f8,$f10,$f0
/*  f00e7c8:	e612005c */ 	swc1	$f18,0x5c($s0)
/*  f00e7cc:	44895000 */ 	mtc1	$t1,$f10
/*  f00e7d0:	46023482 */ 	mul.s	$f18,$f6,$f2
/*  f00e7d4:	460c9103 */ 	div.s	$f4,$f18,$f12
/*  f00e7d8:	e6080060 */ 	swc1	$f8,0x60($s0)
/*  f00e7dc:	448a9000 */ 	mtc1	$t2,$f18
/*  f00e7e0:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f00e7e4:	46024402 */ 	mul.s	$f16,$f8,$f2
/*  f00e7e8:	e6040064 */ 	swc1	$f4,0x64($s0)
/*  f00e7ec:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f00e7f0:	460c8183 */ 	div.s	$f6,$f16,$f12
/*  f00e7f4:	46022282 */ 	mul.s	$f10,$f4,$f2
/*  f00e7f8:	46005203 */ 	div.s	$f8,$f10,$f0
/*  f00e7fc:	e6060068 */ 	swc1	$f6,0x68($s0)
/*  f00e800:	11600006 */ 	beqz	$t3,.PF0f00e81c
/*  f00e804:	e608006c */ 	swc1	$f8,0x6c($s0)
/*  f00e808:	8e0c00bc */ 	lw	$t4,0xbc($s0)
/*  f00e80c:	8fad01cc */ 	lw	$t5,0x1cc($sp)
/*  f00e810:	0fc247c1 */ 	jal	setupGetPtrToCommandByIndex
/*  f00e814:	018d2021 */ 	addu	$a0,$t4,$t5
/*  f00e818:	ae0200bc */ 	sw	$v0,0xbc($s0)
.PF0f00e81c:
/*  f00e81c:	27ae0054 */ 	addiu	$t6,$sp,0x54
/*  f00e820:	27af00a0 */ 	addiu	$t7,$sp,0xa0
/*  f00e824:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f00e828:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f00e82c:	02002025 */ 	move	$a0,$s0
/*  f00e830:	27a500fc */ 	addiu	$a1,$sp,0xfc
/*  f00e834:	27a600ac */ 	addiu	$a2,$sp,0xac
/*  f00e838:	0fc2351b */ 	jal	func0f08d540
/*  f00e83c:	27a700ec */ 	addiu	$a3,$sp,0xec
/*  f00e840:	afa2010c */ 	sw	$v0,0x10c($sp)
/*  f00e844:	8e180008 */ 	lw	$t8,0x8($s0)
/*  f00e848:	8fa801bc */ 	lw	$t0,0x1bc($sp)
/*  f00e84c:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f00e850:	0723000e */ 	bgezl	$t9,.PF0f00e88c
/*  f00e854:	8e040018 */ 	lw	$a0,0x18($s0)
/*  f00e858:	a60800c4 */ 	sh	$t0,0xc4($s0)
/*  f00e85c:	860900c4 */ 	lh	$t1,0xc4($s0)
/*  f00e860:	0522000a */ 	bltzl	$t1,.PF0f00e88c
/*  f00e864:	8e040018 */ 	lw	$a0,0x18($s0)
/*  f00e868:	44808000 */ 	mtc1	$zero,$f16
/*  f00e86c:	c606007c */ 	lwc1	$f6,0x7c($s0)
/*  f00e870:	46068032 */ 	c.eq.s	$f16,$f6
/*  f00e874:	00000000 */ 	nop
/*  f00e878:	45020004 */ 	bc1fl	.PF0f00e88c
/*  f00e87c:	8e040018 */ 	lw	$a0,0x18($s0)
/*  f00e880:	0fc23510 */ 	jal	doorDeactivatePortal
/*  f00e884:	02002025 */ 	move	$a0,$s0
/*  f00e888:	8e040018 */ 	lw	$a0,0x18($s0)
.PF0f00e88c:
/*  f00e88c:	c7a00050 */ 	lwc1	$f0,0x50($sp)
/*  f00e890:	c7ac004c */ 	lwc1	$f12,0x4c($sp)
/*  f00e894:	10800010 */ 	beqz	$a0,.PF0f00e8d8
/*  f00e898:	c7b20048 */ 	lwc1	$f18,0x48($sp)
/*  f00e89c:	460c003c */ 	c.lt.s	$f0,$f12
/*  f00e8a0:	00000000 */ 	nop
/*  f00e8a4:	45020003 */ 	bc1fl	.PF0f00e8b4
/*  f00e8a8:	4612003c */ 	c.lt.s	$f0,$f18
/*  f00e8ac:	46006006 */ 	mov.s	$f0,$f12
/*  f00e8b0:	4612003c */ 	c.lt.s	$f0,$f18
.PF0f00e8b4:
/*  f00e8b4:	00000000 */ 	nop
/*  f00e8b8:	45020003 */ 	bc1fl	.PF0f00e8c8
/*  f00e8bc:	c4840014 */ 	lwc1	$f4,0x14($a0)
/*  f00e8c0:	46009006 */ 	mov.s	$f0,$f18
/*  f00e8c4:	c4840014 */ 	lwc1	$f4,0x14($a0)
.PF0f00e8c8:
/*  f00e8c8:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f00e8cc:	44055000 */ 	mfc1	$a1,$f10
/*  f00e8d0:	0c006b3a */ 	jal	modelSetScale
/*  f00e8d4:	00000000 */ 	nop
.PF0f00e8d8:
/*  f00e8d8:	0fc181c7 */ 	jal	propPrependToList1
/*  f00e8dc:	8fa4010c */ 	lw	$a0,0x10c($sp)
/*  f00e8e0:	0fc18154 */ 	jal	propShow
/*  f00e8e4:	8fa4010c */ 	lw	$a0,0x10c($sp)
/*  f00e8e8:	10000003 */ 	b	.PF0f00e8f8
/*  f00e8ec:	8fbf0034 */ 	lw	$ra,0x34($sp)
.PF0f00e8f0:
/*  f00e8f0:	ae000014 */ 	sw	$zero,0x14($s0)
/*  f00e8f4:	8fbf0034 */ 	lw	$ra,0x34($sp)
.PF0f00e8f8:
/*  f00e8f8:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f00e8fc:	27bd01c8 */ 	addiu	$sp,$sp,0x1c8
/*  f00e900:	03e00008 */ 	jr	$ra
/*  f00e904:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel setupDoor
.late_rodata
glabel var7f1a805c
.word 0x3fc907a9
glabel var7f1a8060
.word 0x3fc907a9
glabel var7f1a8064
.word 0x358637bd
.text
/*  f00e368:	27bdfe38 */ 	addiu	$sp,$sp,-456
/*  f00e36c:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f00e370:	00808025 */ 	or	$s0,$a0,$zero
/*  f00e374:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f00e378:	afa501cc */ 	sw	$a1,0x1cc($sp)
/*  f00e37c:	84840004 */ 	lh	$a0,0x4($a0)
/*  f00e380:	240effff */ 	addiu	$t6,$zero,-1
/*  f00e384:	afae01bc */ 	sw	$t6,0x1bc($sp)
/*  f00e388:	0fc2486d */ 	jal	propLoad
/*  f00e38c:	afa401c0 */ 	sw	$a0,0x1c0($sp)
/*  f00e390:	960f0070 */ 	lhu	$t7,0x70($s0)
/*  f00e394:	31f80040 */ 	andi	$t8,$t7,0x40
/*  f00e398:	53000004 */ 	beqzl	$t8,.L0f00e3ac
/*  f00e39c:	8e190008 */ 	lw	$t9,0x8($s0)
/*  f00e3a0:	0fc4581a */ 	jal	func0f116068
/*  f00e3a4:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00e3a8:	8e190008 */ 	lw	$t9,0x8($s0)
.L0f00e3ac:
/*  f00e3ac:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f00e3b0:	05030005 */ 	bgezl	$t0,.L0f00e3c8
/*  f00e3b4:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00e3b8:	0fc038ac */ 	jal	func0f00e2b0
/*  f00e3bc:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00e3c0:	afa201bc */ 	sw	$v0,0x1bc($sp)
/*  f00e3c4:	86040006 */ 	lh	$a0,0x6($s0)
.L0f00e3c8:
/*  f00e3c8:	2405007e */ 	addiu	$a1,$zero,0x7e
/*  f00e3cc:	0fc456ac */ 	jal	padUnpack
/*  f00e3d0:	27a60168 */ 	addiu	$a2,$sp,0x168
/*  f00e3d4:	3c018006 */ 	lui	$at,%hi(g_DoorScale)
/*  f00e3d8:	c42c1be0 */ 	lwc1	$f12,%lo(g_DoorScale)($at)
/*  f00e3dc:	3c013f80 */ 	lui	$at,0x3f80
/*  f00e3e0:	44812000 */ 	mtc1	$at,$f4
/*  f00e3e4:	c7a60198 */ 	lwc1	$f6,0x198($sp)
/*  f00e3e8:	27a50168 */ 	addiu	$a1,$sp,0x168
/*  f00e3ec:	460c2032 */ 	c.eq.s	$f4,$f12
/*  f00e3f0:	00000000 */ 	nop
/*  f00e3f4:	4503005b */ 	bc1tl	.L0f00e564
/*  f00e3f8:	8fab01b0 */ 	lw	$t3,0x1b0($sp)
/*  f00e3fc:	460c3202 */ 	mul.s	$f8,$f6,$f12
/*  f00e400:	c7aa019c */ 	lwc1	$f10,0x19c($sp)
/*  f00e404:	8fa301bc */ 	lw	$v1,0x1bc($sp)
/*  f00e408:	3c0a800a */ 	lui	$t2,%hi(var800a4ccc)
/*  f00e40c:	460c5402 */ 	mul.s	$f16,$f10,$f12
/*  f00e410:	00034880 */ 	sll	$t1,$v1,0x2
/*  f00e414:	01234821 */ 	addu	$t1,$t1,$v1
/*  f00e418:	e7a80198 */ 	swc1	$f8,0x198($sp)
/*  f00e41c:	0460004e */ 	bltz	$v1,.L0f00e558
/*  f00e420:	e7b0019c */ 	swc1	$f16,0x19c($sp)
/*  f00e424:	8d4a4ccc */ 	lw	$t2,%lo(var800a4ccc)($t2)
/*  f00e428:	00094880 */ 	sll	$t1,$t1,0x2
/*  f00e42c:	c7a40170 */ 	lwc1	$f4,0x170($sp)
/*  f00e430:	012a1021 */ 	addu	$v0,$t1,$t2
/*  f00e434:	c4520008 */ 	lwc1	$f18,0x8($v0)
/*  f00e438:	c7aa016c */ 	lwc1	$f10,0x16c($sp)
/*  f00e43c:	c4420000 */ 	lwc1	$f2,0x0($v0)
/*  f00e440:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f00e444:	c4520004 */ 	lwc1	$f18,0x4($v0)
/*  f00e448:	3c013f80 */ 	lui	$at,0x3f80
/*  f00e44c:	c44e000c */ 	lwc1	$f14,0xc($v0)
/*  f00e450:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f00e454:	c7aa0168 */ 	lwc1	$f10,0x168($sp)
/*  f00e458:	46025482 */ 	mul.s	$f18,$f10,$f2
/*  f00e45c:	46049280 */ 	add.s	$f10,$f18,$f4
/*  f00e460:	44812000 */ 	mtc1	$at,$f4
/*  f00e464:	460a3000 */ 	add.s	$f0,$f6,$f10
/*  f00e468:	46046181 */ 	sub.s	$f6,$f12,$f4
/*  f00e46c:	460e0481 */ 	sub.s	$f18,$f0,$f14
/*  f00e470:	46069002 */ 	mul.s	$f0,$f18,$f6
/*  f00e474:	00000000 */ 	nop
/*  f00e478:	46001282 */ 	mul.s	$f10,$f2,$f0
/*  f00e47c:	e7aa0150 */ 	swc1	$f10,0x150($sp)
/*  f00e480:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f00e484:	46002482 */ 	mul.s	$f18,$f4,$f0
/*  f00e488:	c7a40150 */ 	lwc1	$f4,0x150($sp)
/*  f00e48c:	e7b20154 */ 	swc1	$f18,0x154($sp)
/*  f00e490:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f00e494:	c7b2018c */ 	lwc1	$f18,0x18c($sp)
/*  f00e498:	46003282 */ 	mul.s	$f10,$f6,$f0
/*  f00e49c:	e7aa0158 */ 	swc1	$f10,0x158($sp)
/*  f00e4a0:	46122182 */ 	mul.s	$f6,$f4,$f18
/*  f00e4a4:	c7a40190 */ 	lwc1	$f4,0x190($sp)
/*  f00e4a8:	c7aa0154 */ 	lwc1	$f10,0x154($sp)
/*  f00e4ac:	46045482 */ 	mul.s	$f18,$f10,$f4
/*  f00e4b0:	c7a40194 */ 	lwc1	$f4,0x194($sp)
/*  f00e4b4:	46123280 */ 	add.s	$f10,$f6,$f18
/*  f00e4b8:	c7a60158 */ 	lwc1	$f6,0x158($sp)
/*  f00e4bc:	46062482 */ 	mul.s	$f18,$f4,$f6
/*  f00e4c0:	460a9000 */ 	add.s	$f0,$f18,$f10
/*  f00e4c4:	c7aa0150 */ 	lwc1	$f10,0x150($sp)
/*  f00e4c8:	46004100 */ 	add.s	$f4,$f8,$f0
/*  f00e4cc:	c7a80180 */ 	lwc1	$f8,0x180($sp)
/*  f00e4d0:	46008480 */ 	add.s	$f18,$f16,$f0
/*  f00e4d4:	e7a40198 */ 	swc1	$f4,0x198($sp)
/*  f00e4d8:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f00e4dc:	c7b00154 */ 	lwc1	$f16,0x154($sp)
/*  f00e4e0:	e7b2019c */ 	swc1	$f18,0x19c($sp)
/*  f00e4e4:	c7b20184 */ 	lwc1	$f18,0x184($sp)
/*  f00e4e8:	46128282 */ 	mul.s	$f10,$f16,$f18
/*  f00e4ec:	c7b00188 */ 	lwc1	$f16,0x188($sp)
/*  f00e4f0:	46068482 */ 	mul.s	$f18,$f16,$f6
/*  f00e4f4:	c7b001a4 */ 	lwc1	$f16,0x1a4($sp)
/*  f00e4f8:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f00e4fc:	c7a401a0 */ 	lwc1	$f4,0x1a0($sp)
/*  f00e500:	46089000 */ 	add.s	$f0,$f18,$f8
/*  f00e504:	c7a80150 */ 	lwc1	$f8,0x150($sp)
/*  f00e508:	46008480 */ 	add.s	$f18,$f16,$f0
/*  f00e50c:	c7b00154 */ 	lwc1	$f16,0x154($sp)
/*  f00e510:	46002280 */ 	add.s	$f10,$f4,$f0
/*  f00e514:	c7a40174 */ 	lwc1	$f4,0x174($sp)
/*  f00e518:	e7b201a4 */ 	swc1	$f18,0x1a4($sp)
/*  f00e51c:	c7b20178 */ 	lwc1	$f18,0x178($sp)
/*  f00e520:	e7aa01a0 */ 	swc1	$f10,0x1a0($sp)
/*  f00e524:	46044282 */ 	mul.s	$f10,$f8,$f4
/*  f00e528:	00000000 */ 	nop
/*  f00e52c:	46128202 */ 	mul.s	$f8,$f16,$f18
/*  f00e530:	c7b0017c */ 	lwc1	$f16,0x17c($sp)
/*  f00e534:	46068482 */ 	mul.s	$f18,$f16,$f6
/*  f00e538:	c7b001ac */ 	lwc1	$f16,0x1ac($sp)
/*  f00e53c:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f00e540:	c7aa01a8 */ 	lwc1	$f10,0x1a8($sp)
/*  f00e544:	46049000 */ 	add.s	$f0,$f18,$f4
/*  f00e548:	46008180 */ 	add.s	$f6,$f16,$f0
/*  f00e54c:	46005200 */ 	add.s	$f8,$f10,$f0
/*  f00e550:	e7a601ac */ 	swc1	$f6,0x1ac($sp)
/*  f00e554:	e7a801a8 */ 	swc1	$f8,0x1a8($sp)
.L0f00e558:
/*  f00e558:	0fc45864 */ 	jal	padCopyBboxFromPad
/*  f00e55c:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00e560:	8fab01b0 */ 	lw	$t3,0x1b0($sp)
.L0f00e564:
/*  f00e564:	8fac01c0 */ 	lw	$t4,0x1c0($sp)
/*  f00e568:	3c048008 */ 	lui	$a0,%hi(g_ModelStates)
/*  f00e56c:	196000e1 */ 	blez	$t3,.L0f00e8f4
/*  f00e570:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f00e574:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f00e578:	0fc1a25b */ 	jal	modelFileDataFindBboxRodata
/*  f00e57c:	8c84b06c */ 	lw	$a0,%lo(g_ModelStates)($a0)
/*  f00e580:	c7b20174 */ 	lwc1	$f18,0x174($sp)
/*  f00e584:	44800000 */ 	mtc1	$zero,$f0
/*  f00e588:	c7aa0178 */ 	lwc1	$f10,0x178($sp)
/*  f00e58c:	46009107 */ 	neg.s	$f4,$f18
/*  f00e590:	c7b0017c */ 	lwc1	$f16,0x17c($sp)
/*  f00e594:	46005207 */ 	neg.s	$f8,$f10
/*  f00e598:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f00e59c:	c7a40184 */ 	lwc1	$f4,0x184($sp)
/*  f00e5a0:	c7aa0188 */ 	lwc1	$f10,0x188($sp)
/*  f00e5a4:	c7b20180 */ 	lwc1	$f18,0x180($sp)
/*  f00e5a8:	46008187 */ 	neg.s	$f6,$f16
/*  f00e5ac:	44050000 */ 	mfc1	$a1,$f0
/*  f00e5b0:	44060000 */ 	mfc1	$a2,$f0
/*  f00e5b4:	44070000 */ 	mfc1	$a3,$f0
/*  f00e5b8:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f00e5bc:	e7a60018 */ 	swc1	$f6,0x18($sp)
/*  f00e5c0:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f00e5c4:	27a40110 */ 	addiu	$a0,$sp,0x110
/*  f00e5c8:	e7a40020 */ 	swc1	$f4,0x20($sp)
/*  f00e5cc:	e7aa0024 */ 	swc1	$f10,0x24($sp)
/*  f00e5d0:	0c005b56 */ 	jal	func00016d58
/*  f00e5d4:	e7b2001c */ 	swc1	$f18,0x1c($sp)
/*  f00e5d8:	3c017f1b */ 	lui	$at,%hi(var7f1a805c)
/*  f00e5dc:	c42c805c */ 	lwc1	$f12,%lo(var7f1a805c)($at)
/*  f00e5e0:	0c0058ba */ 	jal	func000162e8
/*  f00e5e4:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00e5e8:	3c017f1b */ 	lui	$at,%hi(var7f1a8060)
/*  f00e5ec:	c42c8060 */ 	lwc1	$f12,%lo(var7f1a8060)($at)
/*  f00e5f0:	0c005900 */ 	jal	func00016400
/*  f00e5f4:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f00e5f8:	27a40060 */ 	addiu	$a0,$sp,0x60
/*  f00e5fc:	0c00567f */ 	jal	func000159fc
/*  f00e600:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00e604:	27a40110 */ 	addiu	$a0,$sp,0x110
/*  f00e608:	0c00567f */ 	jal	func000159fc
/*  f00e60c:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00e610:	86040006 */ 	lh	$a0,0x6($s0)
/*  f00e614:	0fc457cd */ 	jal	padGetCentre
/*  f00e618:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f00e61c:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f00e620:	c7a801a4 */ 	lwc1	$f8,0x1a4($sp)
/*  f00e624:	c7b001a0 */ 	lwc1	$f16,0x1a0($sp)
/*  f00e628:	c4520008 */ 	lwc1	$f18,0x8($v0)
/*  f00e62c:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f00e630:	46104181 */ 	sub.s	$f6,$f8,$f16
/*  f00e634:	c7b001a8 */ 	lwc1	$f16,0x1a8($sp)
/*  f00e638:	c7a801ac */ 	lwc1	$f8,0x1ac($sp)
/*  f00e63c:	46049281 */ 	sub.s	$f10,$f18,$f4
/*  f00e640:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f00e644:	3c017f1b */ 	lui	$at,%hi(var7f1a8064)
/*  f00e648:	46104481 */ 	sub.s	$f18,$f8,$f16
/*  f00e64c:	c4208064 */ 	lwc1	$f0,%lo(var7f1a8064)($at)
/*  f00e650:	c7b00198 */ 	lwc1	$f16,0x198($sp)
/*  f00e654:	460a3303 */ 	div.s	$f12,$f6,$f10
/*  f00e658:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f00e65c:	c7a8019c */ 	lwc1	$f8,0x19c($sp)
/*  f00e660:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00e664:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f00e668:	c4460018 */ 	lwc1	$f6,0x18($v0)
/*  f00e66c:	46104101 */ 	sub.s	$f4,$f8,$f16
/*  f00e670:	460a9083 */ 	div.s	$f2,$f18,$f10
/*  f00e674:	c4520014 */ 	lwc1	$f18,0x14($v0)
/*  f00e678:	4600603e */ 	c.le.s	$f12,$f0
/*  f00e67c:	46123281 */ 	sub.s	$f10,$f6,$f18
/*  f00e680:	45010008 */ 	bc1t	.L0f00e6a4
/*  f00e684:	460a2383 */ 	div.s	$f14,$f4,$f10
/*  f00e688:	4600103e */ 	c.le.s	$f2,$f0
/*  f00e68c:	00000000 */ 	nop
/*  f00e690:	45030005 */ 	bc1tl	.L0f00e6a8
/*  f00e694:	3c013f80 */ 	lui	$at,0x3f80
/*  f00e698:	4600703e */ 	c.le.s	$f14,$f0
/*  f00e69c:	00000000 */ 	nop
/*  f00e6a0:	45000005 */ 	bc1f	.L0f00e6b8
.L0f00e6a4:
/*  f00e6a4:	3c013f80 */ 	lui	$at,0x3f80
.L0f00e6a8:
/*  f00e6a8:	44816000 */ 	mtc1	$at,$f12
/*  f00e6ac:	00000000 */ 	nop
/*  f00e6b0:	46006386 */ 	mov.s	$f14,$f12
/*  f00e6b4:	46006086 */ 	mov.s	$f2,$f12
.L0f00e6b8:
/*  f00e6b8:	e7a2004c */ 	swc1	$f2,0x4c($sp)
/*  f00e6bc:	e7ac0050 */ 	swc1	$f12,0x50($sp)
/*  f00e6c0:	0c005789 */ 	jal	func00015e24
/*  f00e6c4:	e7ae0048 */ 	swc1	$f14,0x48($sp)
/*  f00e6c8:	c7ac004c */ 	lwc1	$f12,0x4c($sp)
/*  f00e6cc:	0c0057a0 */ 	jal	func00015e80
/*  f00e6d0:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00e6d4:	c7ac0048 */ 	lwc1	$f12,0x48($sp)
/*  f00e6d8:	0c0057b7 */ 	jal	func00015edc
/*  f00e6dc:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00e6e0:	c7a80168 */ 	lwc1	$f8,0x168($sp)
/*  f00e6e4:	c7b0016c */ 	lwc1	$f16,0x16c($sp)
/*  f00e6e8:	c7a60170 */ 	lwc1	$f6,0x170($sp)
/*  f00e6ec:	8fae01b0 */ 	lw	$t6,0x1b0($sp)
/*  f00e6f0:	240fffff */ 	addiu	$t7,$zero,-1
/*  f00e6f4:	a7af00ee */ 	sh	$t7,0xee($sp)
/*  f00e6f8:	e7a800fc */ 	swc1	$f8,0xfc($sp)
/*  f00e6fc:	e7b00100 */ 	swc1	$f16,0x100($sp)
/*  f00e700:	e7a60104 */ 	swc1	$f6,0x104($sp)
/*  f00e704:	a7ae00ec */ 	sh	$t6,0xec($sp)
/*  f00e708:	96020072 */ 	lhu	$v0,0x72($s0)
/*  f00e70c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f00e710:	c7b201ac */ 	lwc1	$f18,0x1ac($sp)
/*  f00e714:	10410004 */ 	beq	$v0,$at,.L0f00e728
/*  f00e718:	c7a401a8 */ 	lwc1	$f4,0x1a8($sp)
/*  f00e71c:	24010008 */ 	addiu	$at,$zero,0x8
/*  f00e720:	1441000e */ 	bne	$v0,$at,.L0f00e75c
/*  f00e724:	c7aa01a0 */ 	lwc1	$f10,0x1a0($sp)
.L0f00e728:
/*  f00e728:	46049001 */ 	sub.s	$f0,$f18,$f4
/*  f00e72c:	c7aa0174 */ 	lwc1	$f10,0x174($sp)
/*  f00e730:	c7b00178 */ 	lwc1	$f16,0x178($sp)
/*  f00e734:	c7b2017c */ 	lwc1	$f18,0x17c($sp)
/*  f00e738:	46005202 */ 	mul.s	$f8,$f10,$f0
/*  f00e73c:	00000000 */ 	nop
/*  f00e740:	46008182 */ 	mul.s	$f6,$f16,$f0
/*  f00e744:	00000000 */ 	nop
/*  f00e748:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f00e74c:	e7a80054 */ 	swc1	$f8,0x54($sp)
/*  f00e750:	e7a60058 */ 	swc1	$f6,0x58($sp)
/*  f00e754:	1000000e */ 	b	.L0f00e790
/*  f00e758:	e7a4005c */ 	swc1	$f4,0x5c($sp)
.L0f00e75c:
/*  f00e75c:	c7a801a4 */ 	lwc1	$f8,0x1a4($sp)
/*  f00e760:	c7b00180 */ 	lwc1	$f16,0x180($sp)
/*  f00e764:	c7b20184 */ 	lwc1	$f18,0x184($sp)
/*  f00e768:	46085001 */ 	sub.s	$f0,$f10,$f8
/*  f00e76c:	c7aa0188 */ 	lwc1	$f10,0x188($sp)
/*  f00e770:	46008182 */ 	mul.s	$f6,$f16,$f0
/*  f00e774:	00000000 */ 	nop
/*  f00e778:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f00e77c:	00000000 */ 	nop
/*  f00e780:	46005202 */ 	mul.s	$f8,$f10,$f0
/*  f00e784:	e7a60054 */ 	swc1	$f6,0x54($sp)
/*  f00e788:	e7a40058 */ 	swc1	$f4,0x58($sp)
/*  f00e78c:	e7a8005c */ 	swc1	$f8,0x5c($sp)
.L0f00e790:
/*  f00e790:	8e18005c */ 	lw	$t8,0x5c($s0)
/*  f00e794:	3c014780 */ 	lui	$at,0x4780
/*  f00e798:	44810000 */ 	mtc1	$at,$f0
/*  f00e79c:	44988000 */ 	mtc1	$t8,$f16
/*  f00e7a0:	8e190060 */ 	lw	$t9,0x60($s0)
/*  f00e7a4:	8e080064 */ 	lw	$t0,0x64($s0)
/*  f00e7a8:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f00e7ac:	44992000 */ 	mtc1	$t9,$f4
/*  f00e7b0:	44888000 */ 	mtc1	$t0,$f16
/*  f00e7b4:	3c014c7a */ 	lui	$at,0x4c7a
/*  f00e7b8:	44811000 */ 	mtc1	$at,$f2
/*  f00e7bc:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f00e7c0:	8e090068 */ 	lw	$t1,0x68($s0)
/*  f00e7c4:	8e0a006c */ 	lw	$t2,0x6c($s0)
/*  f00e7c8:	8e0b00bc */ 	lw	$t3,0xbc($s0)
/*  f00e7cc:	44892000 */ 	mtc1	$t1,$f4
/*  f00e7d0:	46003483 */ 	div.s	$f18,$f6,$f0
/*  f00e7d4:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f00e7d8:	448a8000 */ 	mtc1	$t2,$f16
/*  f00e7dc:	46005203 */ 	div.s	$f8,$f10,$f0
/*  f00e7e0:	e612005c */ 	swc1	$f18,0x5c($s0)
/*  f00e7e4:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f00e7e8:	46023483 */ 	div.s	$f18,$f6,$f2
/*  f00e7ec:	e6080060 */ 	swc1	$f8,0x60($s0)
/*  f00e7f0:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f00e7f4:	46025203 */ 	div.s	$f8,$f10,$f2
/*  f00e7f8:	e6120064 */ 	swc1	$f18,0x64($s0)
/*  f00e7fc:	46003483 */ 	div.s	$f18,$f6,$f0
/*  f00e800:	e6080068 */ 	swc1	$f8,0x68($s0)
/*  f00e804:	11600006 */ 	beqz	$t3,.L0f00e820
/*  f00e808:	e612006c */ 	swc1	$f18,0x6c($s0)
/*  f00e80c:	8e0c00bc */ 	lw	$t4,0xbc($s0)
/*  f00e810:	8fad01cc */ 	lw	$t5,0x1cc($sp)
/*  f00e814:	0fc24801 */ 	jal	setupGetPtrToCommandByIndex
/*  f00e818:	018d2021 */ 	addu	$a0,$t4,$t5
/*  f00e81c:	ae0200bc */ 	sw	$v0,0xbc($s0)
.L0f00e820:
/*  f00e820:	27ae0054 */ 	addiu	$t6,$sp,0x54
/*  f00e824:	27af00a0 */ 	addiu	$t7,$sp,0xa0
/*  f00e828:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f00e82c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f00e830:	02002025 */ 	or	$a0,$s0,$zero
/*  f00e834:	27a500fc */ 	addiu	$a1,$sp,0xfc
/*  f00e838:	27a600ac */ 	addiu	$a2,$sp,0xac
/*  f00e83c:	0fc23550 */ 	jal	func0f08d540
/*  f00e840:	27a700ec */ 	addiu	$a3,$sp,0xec
/*  f00e844:	afa2010c */ 	sw	$v0,0x10c($sp)
/*  f00e848:	8e180008 */ 	lw	$t8,0x8($s0)
/*  f00e84c:	8fa801bc */ 	lw	$t0,0x1bc($sp)
/*  f00e850:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f00e854:	0723000e */ 	bgezl	$t9,.L0f00e890
/*  f00e858:	8e040018 */ 	lw	$a0,0x18($s0)
/*  f00e85c:	a60800c4 */ 	sh	$t0,0xc4($s0)
/*  f00e860:	860900c4 */ 	lh	$t1,0xc4($s0)
/*  f00e864:	0522000a */ 	bltzl	$t1,.L0f00e890
/*  f00e868:	8e040018 */ 	lw	$a0,0x18($s0)
/*  f00e86c:	44802000 */ 	mtc1	$zero,$f4
/*  f00e870:	c60a007c */ 	lwc1	$f10,0x7c($s0)
/*  f00e874:	460a2032 */ 	c.eq.s	$f4,$f10
/*  f00e878:	00000000 */ 	nop
/*  f00e87c:	45020004 */ 	bc1fl	.L0f00e890
/*  f00e880:	8e040018 */ 	lw	$a0,0x18($s0)
/*  f00e884:	0fc23545 */ 	jal	doorDeactivatePortal
/*  f00e888:	02002025 */ 	or	$a0,$s0,$zero
/*  f00e88c:	8e040018 */ 	lw	$a0,0x18($s0)
.L0f00e890:
/*  f00e890:	c7a00050 */ 	lwc1	$f0,0x50($sp)
/*  f00e894:	c7ac004c */ 	lwc1	$f12,0x4c($sp)
/*  f00e898:	10800010 */ 	beqz	$a0,.L0f00e8dc
/*  f00e89c:	c7a80048 */ 	lwc1	$f8,0x48($sp)
/*  f00e8a0:	460c003c */ 	c.lt.s	$f0,$f12
/*  f00e8a4:	00000000 */ 	nop
/*  f00e8a8:	45020003 */ 	bc1fl	.L0f00e8b8
/*  f00e8ac:	4608003c */ 	c.lt.s	$f0,$f8
/*  f00e8b0:	46006006 */ 	mov.s	$f0,$f12
/*  f00e8b4:	4608003c */ 	c.lt.s	$f0,$f8
.L0f00e8b8:
/*  f00e8b8:	00000000 */ 	nop
/*  f00e8bc:	45020003 */ 	bc1fl	.L0f00e8cc
/*  f00e8c0:	c4900014 */ 	lwc1	$f16,0x14($a0)
/*  f00e8c4:	46004006 */ 	mov.s	$f0,$f8
/*  f00e8c8:	c4900014 */ 	lwc1	$f16,0x14($a0)
.L0f00e8cc:
/*  f00e8cc:	46008182 */ 	mul.s	$f6,$f16,$f0
/*  f00e8d0:	44053000 */ 	mfc1	$a1,$f6
/*  f00e8d4:	0c006bd6 */ 	jal	modelSetScale
/*  f00e8d8:	00000000 */ 	nop
.L0f00e8dc:
/*  f00e8dc:	0fc1812f */ 	jal	propPrependToList1
/*  f00e8e0:	8fa4010c */ 	lw	$a0,0x10c($sp)
/*  f00e8e4:	0fc180bc */ 	jal	propShow
/*  f00e8e8:	8fa4010c */ 	lw	$a0,0x10c($sp)
/*  f00e8ec:	10000003 */ 	b	.L0f00e8fc
/*  f00e8f0:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f00e8f4:
/*  f00e8f4:	ae000014 */ 	sw	$zero,0x14($s0)
/*  f00e8f8:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f00e8fc:
/*  f00e8fc:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f00e900:	27bd01c8 */ 	addiu	$sp,$sp,0x1c8
/*  f00e904:	03e00008 */ 	jr	$ra
/*  f00e908:	00000000 */ 	nop
);
#endif

// Mismatch:
// 1. Floating point math near 41c is vastly different
// 2. Goal skips sp slots 164, 160 and 15c - related to the above
// 3. Goal seems to have rooms array as rooms[8] instead of rooms[2] but this
// causes too much stack usage, because of 4
// 4. Mine allocates too many unused stack slots at the bottom
//void setupDoor(struct doorobj *door, s32 cmdindex)
//{
//	f32 mult;
//	s32 modelnum = door->base.modelnum; // 1c0
//	s32 portalnum = -1; // 1bc
//	struct pad pad; // 168
//
//	propLoad(modelnum);
//
//	if (door->doorflags & DOORFLAG_0040) {
//		func0f116068(door->base.pad);
//	}
//
//	if (door->base.flags & OBJFLAG_DOOR_HASPORTAL) {
//		portalnum = func0f00e2b0(door->base.pad);
//	}
//
//	padUnpack(door->base.pad, PADFIELD_POS | PADFIELD_LOOK | PADFIELD_UP | PADFIELD_NORMAL | PADFIELD_BBOX | PADFIELD_ROOM, &pad);
//
//	// 3f4
//	if (g_DoorScale != 1) {
//		pad.bbox.xmin *= g_DoorScale;
//		pad.bbox.xmax *= g_DoorScale;
//
//		// 41c
//		if (portalnum >= 0) {
//			// Is this is adjusting the pad's bbox to match the portal's
//			// dimensions?
//			f32 f0 = pad.pos.x * var800a4ccc[portalnum].coord.x
//				+ pad.pos.y * var800a4ccc[portalnum].coord.y
//				+ pad.pos.z * var800a4ccc[portalnum].coord.z;
//			struct coord sp150;
//			f0 = (f0 - var800a4ccc[portalnum].unk0c) * (g_DoorScale - 1);
//
//			sp150.x = var800a4ccc[portalnum].coord.x * f0;
//			sp150.y = var800a4ccc[portalnum].coord.y * f0;
//			sp150.z = var800a4ccc[portalnum].coord.z * f0;
//
//			pad.bbox.xmin += pad.normal.x * sp150.x + pad.normal.y * sp150.y + pad.normal.z * sp150.z;
//			pad.bbox.xmax += pad.normal.x * sp150.x + pad.normal.y * sp150.y + pad.normal.z * sp150.z;
//			pad.bbox.ymin += pad.up.x * sp150.x + pad.up.y * sp150.y + pad.up.z * sp150.z;
//			pad.bbox.ymax += pad.up.x * sp150.x + pad.up.y * sp150.y + pad.up.z * sp150.z;
//			pad.bbox.zmin += pad.look.x * sp150.x + pad.look.y * sp150.y + pad.look.z * sp150.z;
//			pad.bbox.zmax += pad.look.x * sp150.x + pad.look.y * sp150.y + pad.look.z * sp150.z;
//		}
//
//		// Write the modified bbox into the pad file data
//		padCopyBboxFromPad(door->base.pad, &pad);
//	}
//
//	if (pad.room >= 1) {
//		f32 sp110[16]; // 110 - 150
//		struct prop *prop; // 10c
//		struct coord pos; // fc - 108
//		s16 rooms[2]; // ec - ?
//		f32 spac[16]; // ac - ec
//		struct coord spa0; // a0 - ac
//		f32 sp60[16]; // 60 - a0
//		struct coord sp54; // 54 - 60
//		f32 sp50;
//		f32 sp4c;
//		f32 sp48;
//		f32 *floats; // 44
//
//		floats = modelFileDataFindBboxRodata(g_ModelStates[modelnum].filedata);
//
//		func00016d58(sp110, 0, 0, 0,
//				-pad.look.x, -pad.look.y, -pad.look.z,
//				pad.up.x, pad.up.y, pad.up.z);
//		func000162e8(1.5705462694168f, spac);
//		func00016400(1.5705462694168f, sp60);
//		func000159fc(sp60, spac);
//		func000159fc(sp110, spac);
//
//		padGetCentre(door->base.pad, &spa0);
//
//		sp50 = (pad.bbox.ymax - pad.bbox.ymin) / (floats[2] - floats[1]);
//		sp4c = (pad.bbox.zmax - pad.bbox.zmin) / (floats[4] - floats[3]);
//		sp48 = (pad.bbox.xmax - pad.bbox.xmin) / (floats[6] - floats[5]);
//
//		if (sp50 <= 0.00001f || sp4c <= 0.00001f || sp48 <= 0.00001f) {
//			sp50 = 1;
//			sp4c = 1;
//			sp48 = 1;
//		}
//
//		func00015e24(sp50, spac);
//		func00015e80(sp4c, spac);
//		func00015edc(sp48, spac);
//
//		pos.x = pad.pos.x;
//		pos.y = pad.pos.y;
//		pos.z = pad.pos.z;
//
//		rooms[0] = pad.room;
//		rooms[1] = -1;
//
//		// 714
//		if (door->doortype == DOORTYPE_VERTICAL || door->doortype == DOORTYPE_8) {
//			sp54.x = (pad.bbox.zmax - pad.bbox.zmin) * pad.look.x;
//			sp54.y = (pad.bbox.zmax - pad.bbox.zmin) * pad.look.y;
//			sp54.z = (pad.bbox.zmax - pad.bbox.zmin) * pad.look.z;
//		} else {
//			sp54.x = (pad.bbox.ymin - pad.bbox.ymax) * pad.up.x;
//			sp54.y = (pad.bbox.ymin - pad.bbox.ymax) * pad.up.y;
//			sp54.z = (pad.bbox.ymin - pad.bbox.ymax) * pad.up.z;
//		}
//
//		// 790
//		door->maxfrac = *(s32 *)&door->maxfrac / 65536.0f;
//		door->perimfrac = *(s32 *)&door->perimfrac / 65536.0f;
//		door->accel = *(s32 *)&door->accel / 65536000.0f;
//		door->decel = *(s32 *)&door->decel / 65536000.0f;
//		door->maxspeed = *(s32 *)&door->maxspeed / 65536.0f;
//
//		if (door->sibling) {
//			door->sibling = (struct doorobj *)setupGetPtrToCommandByIndex((s32)door->sibling + cmdindex);
//		}
//
//		prop = func0f08d540(door, &pos, spac, rooms, &sp54, &spa0);
//
//		if (door->base.flags & OBJFLAG_DOOR_HASPORTAL) {
//			door->portalnum = portalnum;
//
//			if (door->portalnum >= 0 && door->frac == 0) {
//				doorDeactivatePortal(door);
//			}
//		}
//
//		// 898
//		if (door->base.model) {
//			mult = sp50;
//
//			if (sp4c > mult) {
//				mult = sp4c;
//			}
//
//			if (sp48 > mult) {
//				mult = sp48;
//			}
//
//			modelSetScale(door->base.model, door->base.model->scale * mult);
//		}
//
//		propPrependToList1(prop);
//		propShow(prop);
//	} else {
//		door->base.prop = NULL;
//	}
//}

void setupHov(struct defaultobj *obj, struct hov *hov)
{
	hov->unk04 = 0;
	hov->unk08 = 0;
	hov->unk0c = 0;
	hov->unk10 = atan2f(obj->realrot[6], obj->realrot[8]);
	hov->unk14 = 0;
	hov->unk18 = 0;
	hov->unk1c = 0;
	hov->unk20 = 0;
	hov->unk24 = 0;
	hov->unk28 = 0;
	hov->unk2c = 0;
	hov->unk30 = 0;
	hov->ground = 0;
	hov->groundnext60 = -1;
	hov->groundprev60 = -1;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f00e980
/*  f00e980:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f00e984:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f00e988:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f00e98c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f00e990:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f00e994:	2881005a */ 	slti	$at,$a0,0x5a
/*  f00e998:	00e08825 */ 	or	$s1,$a3,$zero
/*  f00e99c:	00a09025 */ 	or	$s2,$a1,$zero
/*  f00e9a0:	00809825 */ 	or	$s3,$a0,$zero
/*  f00e9a4:	00c0a825 */ 	or	$s5,$a2,$zero
/*  f00e9a8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f00e9ac:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f00e9b0:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f00e9b4:	10200061 */ 	beqz	$at,.L0f00eb3c
/*  f00e9b8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f00e9bc:	0fc59585 */ 	jal	stageGetIndex
/*  f00e9c0:	00000000 */ 	nop
/*  f00e9c4:	04410002 */ 	bgez	$v0,.L0f00e9d0
/*  f00e9c8:	00401825 */ 	or	$v1,$v0,$zero
/*  f00e9cc:	00001825 */ 	or	$v1,$zero,$zero
.L0f00e9d0:
/*  f00e9d0:	000370c0 */ 	sll	$t6,$v1,0x3
/*  f00e9d4:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f00e9d8:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f00e9dc:	3c028008 */ 	lui	$v0,%hi(g_Stages+0xe)
/*  f00e9e0:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f00e9e4:	9444fcce */ 	lhu	$a0,%lo(g_Stages+0xe)($v0)
/*  f00e9e8:	240f0003 */ 	addiu	$t7,$zero,0x3
/*  f00e9ec:	3c018006 */ 	lui	$at,%hi(g_LoadType)
/*  f00e9f0:	a02fd9a0 */ 	sb	$t7,%lo(g_LoadType)($at)
/*  f00e9f4:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f00e9f8:	02403025 */ 	or	$a2,$s2,$zero
/*  f00e9fc:	02a03825 */ 	or	$a3,$s5,$zero
/*  f00ea00:	0fc59c80 */ 	jal	func0f167200
/*  f00ea04:	00808025 */ 	or	$s0,$a0,$zero
/*  f00ea08:	0fc59ca0 */ 	jal	fileGetSize
/*  f00ea0c:	02002025 */ 	or	$a0,$s0,$zero
/*  f00ea10:	02428021 */ 	addu	$s0,$s2,$v0
/*  f00ea14:	02a2a023 */ 	subu	$s4,$s5,$v0
/*  f00ea18:	0fc5b878 */ 	jal	langGetLangBankIndexFromStagenum
/*  f00ea1c:	02602025 */ 	or	$a0,$s3,$zero
/*  f00ea20:	a622001a */ 	sh	$v0,0x1a($s1)
/*  f00ea24:	3044ffff */ 	andi	$a0,$v0,0xffff
/*  f00ea28:	02002825 */ 	or	$a1,$s0,$zero
/*  f00ea2c:	0fc5b9d9 */ 	jal	langSetBank
/*  f00ea30:	02803025 */ 	or	$a2,$s4,$zero
/*  f00ea34:	8e580010 */ 	lw	$t8,0x10($s2)
/*  f00ea38:	02589821 */ 	addu	$s3,$s2,$t8
/*  f00ea3c:	52600040 */ 	beqzl	$s3,.L0f00eb40
/*  f00ea40:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f00ea44:	0fc5b367 */ 	jal	lvGetDifficulty
/*  f00ea48:	24160001 */ 	addiu	$s6,$zero,0x1
/*  f00ea4c:	14400002 */ 	bnez	$v0,.L0f00ea58
/*  f00ea50:	00000000 */ 	nop
/*  f00ea54:	24160003 */ 	addiu	$s6,$zero,0x3
.L0f00ea58:
/*  f00ea58:	0fc5b367 */ 	jal	lvGetDifficulty
/*  f00ea5c:	00000000 */ 	nop
/*  f00ea60:	24010001 */ 	addiu	$at,$zero,0x1
/*  f00ea64:	14410002 */ 	bne	$v0,$at,.L0f00ea70
/*  f00ea68:	02201825 */ 	or	$v1,$s1,$zero
/*  f00ea6c:	24160002 */ 	addiu	$s6,$zero,0x2
.L0f00ea70:
/*  f00ea70:	00001025 */ 	or	$v0,$zero,$zero
.L0f00ea74:
/*  f00ea74:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f00ea78:	28410006 */ 	slti	$at,$v0,0x6
/*  f00ea7c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f00ea80:	1420fffc */ 	bnez	$at,.L0f00ea74
/*  f00ea84:	a4600000 */ 	sh	$zero,0x0($v1)
/*  f00ea88:	2419582a */ 	addiu	$t9,$zero,0x5801
/*  f00ea8c:	a6390000 */ 	sh	$t9,0x0($s1)
/*  f00ea90:	92680003 */ 	lbu	$t0,0x3($s3)
/*  f00ea94:	24120034 */ 	addiu	$s2,$zero,0x34
/*  f00ea98:	02608025 */ 	or	$s0,$s3,$zero
/*  f00ea9c:	12480027 */ 	beq	$s2,$t0,.L0f00eb3c
/*  f00eaa0:	310300ff */ 	andi	$v1,$t0,0xff
/*  f00eaa4:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f00eaa8:	24140023 */ 	addiu	$s4,$zero,0x23
/*  f00eaac:	24130017 */ 	addiu	$s3,$zero,0x17
.L0f00eab0:
/*  f00eab0:	5073000f */ 	beql	$v1,$s3,.L0f00eaf0
/*  f00eab4:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f00eab8:	14740019 */ 	bne	$v1,$s4,.L0f00eb20
/*  f00eabc:	00000000 */ 	nop
/*  f00eac0:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f00eac4:	16a20004 */ 	bne	$s5,$v0,.L0f00ead8
/*  f00eac8:	00000000 */ 	nop
/*  f00eacc:	8e090008 */ 	lw	$t1,0x8($s0)
/*  f00ead0:	a6290000 */ 	sh	$t1,0x0($s1)
/*  f00ead4:	8e020004 */ 	lw	$v0,0x4($s0)
.L0f00ead8:
/*  f00ead8:	16c20011 */ 	bne	$s6,$v0,.L0f00eb20
/*  f00eadc:	00000000 */ 	nop
/*  f00eae0:	8e0a0008 */ 	lw	$t2,0x8($s0)
/*  f00eae4:	1000000e */ 	b	.L0f00eb20
/*  f00eae8:	a62a0000 */ 	sh	$t2,0x0($s1)
/*  f00eaec:	8e020004 */ 	lw	$v0,0x4($s0)
.L0f00eaf0:
/*  f00eaf0:	2c410007 */ 	sltiu	$at,$v0,0x7
/*  f00eaf4:	1020000a */ 	beqz	$at,.L0f00eb20
/*  f00eaf8:	00000000 */ 	nop
/*  f00eafc:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*  f00eb00:	00026040 */ 	sll	$t4,$v0,0x1
/*  f00eb04:	022c6821 */ 	addu	$t5,$s1,$t4
/*  f00eb08:	a5ab0002 */ 	sh	$t3,0x2($t5)
/*  f00eb0c:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f00eb10:	820e000f */ 	lb	$t6,0xf($s0)
/*  f00eb14:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f00eb18:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f00eb1c:	a72e000e */ 	sh	$t6,0xe($t9)
.L0f00eb20:
/*  f00eb20:	0fc24784 */ 	jal	setupGetCommandLength
/*  f00eb24:	02002025 */ 	or	$a0,$s0,$zero
/*  f00eb28:	00024080 */ 	sll	$t0,$v0,0x2
/*  f00eb2c:	01108021 */ 	addu	$s0,$t0,$s0
/*  f00eb30:	92030003 */ 	lbu	$v1,0x3($s0)
/*  f00eb34:	1643ffde */ 	bne	$s2,$v1,.L0f00eab0
/*  f00eb38:	00000000 */ 	nop
.L0f00eb3c:
/*  f00eb3c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f00eb40:
/*  f00eb40:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f00eb44:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f00eb48:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f00eb4c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f00eb50:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f00eb54:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f00eb58:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f00eb5c:	03e00008 */ 	jr	$ra
/*  f00eb60:	27bd0038 */ 	addiu	$sp,$sp,0x38
);
#else
GLOBAL_ASM(
glabel func0f00e980
/*  f00e980:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f00e984:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f00e988:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f00e98c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f00e990:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f00e994:	2881005a */ 	slti	$at,$a0,0x5a
/*  f00e998:	00e08825 */ 	or	$s1,$a3,$zero
/*  f00e99c:	00a09025 */ 	or	$s2,$a1,$zero
/*  f00e9a0:	00809825 */ 	or	$s3,$a0,$zero
/*  f00e9a4:	00c0a825 */ 	or	$s5,$a2,$zero
/*  f00e9a8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f00e9ac:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f00e9b0:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f00e9b4:	10200061 */ 	beqz	$at,.L0f00eb3c
/*  f00e9b8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f00e9bc:	0fc59585 */ 	jal	stageGetIndex
/*  f00e9c0:	00000000 */ 	nop
/*  f00e9c4:	04410002 */ 	bgez	$v0,.L0f00e9d0
/*  f00e9c8:	00401825 */ 	or	$v1,$v0,$zero
/*  f00e9cc:	00001825 */ 	or	$v1,$zero,$zero
.L0f00e9d0:
/*  f00e9d0:	000370c0 */ 	sll	$t6,$v1,0x3
/*  f00e9d4:	01c37023 */ 	subu	$t6,$t6,$v1
/*  f00e9d8:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f00e9dc:	3c028008 */ 	lui	$v0,%hi(g_Stages+0xe)
/*  f00e9e0:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f00e9e4:	9444fcce */ 	lhu	$a0,%lo(g_Stages+0xe)($v0)
/*  f00e9e8:	240f0003 */ 	addiu	$t7,$zero,0x3
/*  f00e9ec:	3c018006 */ 	lui	$at,%hi(g_LoadType)
/*  f00e9f0:	a02fd9a0 */ 	sb	$t7,%lo(g_LoadType)($at)
/*  f00e9f4:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f00e9f8:	02403025 */ 	or	$a2,$s2,$zero
/*  f00e9fc:	02a03825 */ 	or	$a3,$s5,$zero
/*  f00ea00:	0fc59c80 */ 	jal	func0f167200
/*  f00ea04:	00808025 */ 	or	$s0,$a0,$zero
/*  f00ea08:	0fc59ca0 */ 	jal	fileGetSize
/*  f00ea0c:	02002025 */ 	or	$a0,$s0,$zero
/*  f00ea10:	02428021 */ 	addu	$s0,$s2,$v0
/*  f00ea14:	02a2a023 */ 	subu	$s4,$s5,$v0
/*  f00ea18:	0fc5b878 */ 	jal	langGetLangBankIndexFromStagenum
/*  f00ea1c:	02602025 */ 	or	$a0,$s3,$zero
/*  f00ea20:	a622001a */ 	sh	$v0,0x1a($s1)
/*  f00ea24:	3044ffff */ 	andi	$a0,$v0,0xffff
/*  f00ea28:	02002825 */ 	or	$a1,$s0,$zero
/*  f00ea2c:	0fc5b9d9 */ 	jal	langSetBank
/*  f00ea30:	02803025 */ 	or	$a2,$s4,$zero
/*  f00ea34:	8e580010 */ 	lw	$t8,0x10($s2)
/*  f00ea38:	02589821 */ 	addu	$s3,$s2,$t8
/*  f00ea3c:	52600040 */ 	beqzl	$s3,.L0f00eb40
/*  f00ea40:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f00ea44:	0fc5b367 */ 	jal	lvGetDifficulty
/*  f00ea48:	24160001 */ 	addiu	$s6,$zero,0x1
/*  f00ea4c:	14400002 */ 	bnez	$v0,.L0f00ea58
/*  f00ea50:	00000000 */ 	nop
/*  f00ea54:	24160003 */ 	addiu	$s6,$zero,0x3
.L0f00ea58:
/*  f00ea58:	0fc5b367 */ 	jal	lvGetDifficulty
/*  f00ea5c:	00000000 */ 	nop
/*  f00ea60:	24010001 */ 	addiu	$at,$zero,0x1
/*  f00ea64:	14410002 */ 	bne	$v0,$at,.L0f00ea70
/*  f00ea68:	02201825 */ 	or	$v1,$s1,$zero
/*  f00ea6c:	24160002 */ 	addiu	$s6,$zero,0x2
.L0f00ea70:
/*  f00ea70:	00001025 */ 	or	$v0,$zero,$zero
.L0f00ea74:
/*  f00ea74:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f00ea78:	28410006 */ 	slti	$at,$v0,0x6
/*  f00ea7c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f00ea80:	1420fffc */ 	bnez	$at,.L0f00ea74
/*  f00ea84:	a4600000 */ 	sh	$zero,0x0($v1)
/*  f00ea88:	2419582a */ 	addiu	$t9,$zero,0x582a
/*  f00ea8c:	a6390000 */ 	sh	$t9,0x0($s1)
/*  f00ea90:	92680003 */ 	lbu	$t0,0x3($s3)
/*  f00ea94:	24120034 */ 	addiu	$s2,$zero,0x34
/*  f00ea98:	02608025 */ 	or	$s0,$s3,$zero
/*  f00ea9c:	12480027 */ 	beq	$s2,$t0,.L0f00eb3c
/*  f00eaa0:	310300ff */ 	andi	$v1,$t0,0xff
/*  f00eaa4:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f00eaa8:	24140023 */ 	addiu	$s4,$zero,0x23
/*  f00eaac:	24130017 */ 	addiu	$s3,$zero,0x17
.L0f00eab0:
/*  f00eab0:	5073000f */ 	beql	$v1,$s3,.L0f00eaf0
/*  f00eab4:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f00eab8:	14740019 */ 	bne	$v1,$s4,.L0f00eb20
/*  f00eabc:	00000000 */ 	nop
/*  f00eac0:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f00eac4:	16a20004 */ 	bne	$s5,$v0,.L0f00ead8
/*  f00eac8:	00000000 */ 	nop
/*  f00eacc:	8e090008 */ 	lw	$t1,0x8($s0)
/*  f00ead0:	a6290000 */ 	sh	$t1,0x0($s1)
/*  f00ead4:	8e020004 */ 	lw	$v0,0x4($s0)
.L0f00ead8:
/*  f00ead8:	16c20011 */ 	bne	$s6,$v0,.L0f00eb20
/*  f00eadc:	00000000 */ 	nop
/*  f00eae0:	8e0a0008 */ 	lw	$t2,0x8($s0)
/*  f00eae4:	1000000e */ 	b	.L0f00eb20
/*  f00eae8:	a62a0000 */ 	sh	$t2,0x0($s1)
/*  f00eaec:	8e020004 */ 	lw	$v0,0x4($s0)
.L0f00eaf0:
/*  f00eaf0:	2c410007 */ 	sltiu	$at,$v0,0x7
/*  f00eaf4:	1020000a */ 	beqz	$at,.L0f00eb20
/*  f00eaf8:	00000000 */ 	nop
/*  f00eafc:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*  f00eb00:	00026040 */ 	sll	$t4,$v0,0x1
/*  f00eb04:	022c6821 */ 	addu	$t5,$s1,$t4
/*  f00eb08:	a5ab0002 */ 	sh	$t3,0x2($t5)
/*  f00eb0c:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f00eb10:	820e000f */ 	lb	$t6,0xf($s0)
/*  f00eb14:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f00eb18:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f00eb1c:	a72e000e */ 	sh	$t6,0xe($t9)
.L0f00eb20:
/*  f00eb20:	0fc24784 */ 	jal	setupGetCommandLength
/*  f00eb24:	02002025 */ 	or	$a0,$s0,$zero
/*  f00eb28:	00024080 */ 	sll	$t0,$v0,0x2
/*  f00eb2c:	01108021 */ 	addu	$s0,$t0,$s0
/*  f00eb30:	92030003 */ 	lbu	$v1,0x3($s0)
/*  f00eb34:	1643ffde */ 	bne	$s2,$v1,.L0f00eab0
/*  f00eb38:	00000000 */ 	nop
.L0f00eb3c:
/*  f00eb3c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f00eb40:
/*  f00eb40:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f00eb44:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f00eb48:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f00eb4c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f00eb50:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f00eb54:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f00eb58:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f00eb5c:	03e00008 */ 	jr	$ra
/*  f00eb60:	27bd0038 */ 	addiu	$sp,$sp,0x38
);
#endif

void setupLoadFiles(s32 stagenum)
{
	s32 i;
	s32 j;
	struct ailist tmp;
	s32 numchrs = 0;
	s32 total = 0;
	s32 extra;
	struct stagesetup *setup;
	u16 filenum;
	bool modified;

	var80069960 = 0;
	var80069964 = 0xffffffff;

	g_DoorScale = 1;

	for (i = 0; i < ARRAYCOUNT(g_ModelStates); i++) {
		g_ModelStates[i].filedata = NULL;
	}

	if (stagenum < STAGE_TITLE) {
		if (g_Vars.normmplayerisrunning) {
			filenum = g_Stages[g_StageIndex].mpsetupfileid;
		} else {
			filenum = g_Stages[g_StageIndex].setupfileid;
		}

		g_LoadType = LOADTYPE_SETUP;

		g_GeCreditsData = (u8 *)func0f1670fc(filenum, 0x22);
		setup = (struct stagesetup *)g_GeCreditsData;
		langSetBankSimple(langGetLangBankIndexFromStagenum(stagenum));

		g_StageSetup.intro = (s32 *)((u32)setup + (u32)setup->intro);
		g_StageSetup.props = (u32 *)((u32)setup + (u32)setup->props);
		g_StageSetup.paths = (struct path *)((u32)setup + (u32)setup->paths);
		g_StageSetup.ailists = (struct ailist *)((u32)setup + (u32)setup->ailists);

		g_LoadType = LOADTYPE_PADS;

		g_StageSetup.padfiledata = func0f1670fc(g_Stages[g_StageIndex].padsfileid, 0x22);

		g_StageSetup.waypoints = NULL;
		g_StageSetup.waygroups = NULL;
		g_StageSetup.cover = NULL;

		// Convert ailist pointers from file-local to proper pointers
		if (g_StageSetup.ailists) {
			for (i = 0; g_StageSetup.ailists[i].list != NULL; i++) {
				g_StageSetup.ailists[i].list = (u8 *)((u32)setup + (u32)g_StageSetup.ailists[i].list);
			}
		}

		// Sort the global AI lists by ID asc
		do {
			modified = false;

			for (i = 0; g_GlobalAilists[i + 1].list != NULL; i++) {
				if (g_GlobalAilists[i + 1].id < g_GlobalAilists[i].id) {
					// Swap them
					tmp = g_GlobalAilists[i];
					g_GlobalAilists[i] = g_GlobalAilists[i + 1];
					g_GlobalAilists[i + 1] = tmp;

					modified = true;
				}
			}
		} while (modified);

		// Sort the stage AI lists by ID asc
		do {
			modified = false;

			for (i = 0; g_StageSetup.ailists[i + 1].list != NULL; i++) {
				if (g_StageSetup.ailists[i + 1].id < g_StageSetup.ailists[i].id) {
					// Swap them
					tmp = g_StageSetup.ailists[i];
					g_StageSetup.ailists[i] = g_StageSetup.ailists[i + 1];
					g_StageSetup.ailists[i + 1] = tmp;

					modified = true;
				}
			}
		} while (modified);

		// Count the AI lists
		for (g_NumGlobalAilists = 0; g_GlobalAilists[g_NumGlobalAilists].list != NULL; g_NumGlobalAilists++);
		for (g_NumLvAilists = 0; g_StageSetup.ailists[g_NumLvAilists].list != NULL; g_NumLvAilists++);

		// Convert path pad pointers from file-local to proper pointers
		// and calculate the path lengths
		if (g_StageSetup.paths) {
			for (i = 0; g_StageSetup.paths[i].pads != NULL; i++) {
				g_StageSetup.paths[i].pads = (s32 *)((u32)g_StageSetup.paths[i].pads + (u32)setup);

				for (j = 0; g_StageSetup.paths[i].pads[j] >= 0; j++);

				g_StageSetup.paths[i].len = j;
			}
		}

		numchrs += setupCountCommandType(OBJTYPE_CHR);

		if (!g_Vars.normmplayerisrunning && g_MissionConfig.iscoop && g_Vars.numaibuddies > 0) {
			numchrs += g_Vars.numaibuddies;
			total += g_Vars.numaibuddies;
		}

		total += setupCountCommandType(OBJTYPE_WEAPON);
		total += setupCountCommandType(OBJTYPE_KEY);
		total += setupCountCommandType(OBJTYPE_HAT);
		total += setupCountCommandType(OBJTYPE_DOOR);
		total += setupCountCommandType(OBJTYPE_CCTV);
		total += setupCountCommandType(OBJTYPE_AUTOGUN);
		total += setupCountCommandType(OBJTYPE_HANGINGMONITORS);
		total += setupCountCommandType(OBJTYPE_SINGLEMONITOR);
		total += setupCountCommandType(OBJTYPE_MULTIMONITOR);
		total += setupCountCommandType(OBJTYPE_SHIELD);
		total += setupCountCommandType(OBJTYPE_BASIC);
		total += setupCountCommandType(OBJTYPE_DEBRIS);
		total += setupCountCommandType(OBJTYPE_GLASS);
		total += setupCountCommandType(OBJTYPE_TINTEDGLASS);
		total += setupCountCommandType(OBJTYPE_SAFE);
		total += setupCountCommandType(OBJTYPE_29);
		total += setupCountCommandType(OBJTYPE_24);
		total += setupCountCommandType(OBJTYPE_ALARM);
		total += setupCountCommandType(OBJTYPE_AMMOCRATE);
		total += setupCountCommandType(OBJTYPE_MULTIAMMOCRATE);
		total += setupCountCommandType(OBJTYPE_TRUCK);
		total += setupCountCommandType(OBJTYPE_TANK);
		total += setupCountCommandType(OBJTYPE_LIFT);
		total += setupCountCommandType(OBJTYPE_HOVERBIKE);
		total += setupCountCommandType(OBJTYPE_HOVERPROP);
		total += setupCountCommandType(OBJTYPE_FAN);
		total += setupCountCommandType(OBJTYPE_HOVERCAR);
		total += setupCountCommandType(OBJTYPE_CHOPPER);
		total += setupCountCommandType(OBJTYPE_HELI);
		total += setupCountCommandType(OBJTYPE_ESCASTEP);

		if (g_Vars.normmplayerisrunning) {
			total += scenarioCallback08();
		}

		func0f011130(total, numchrs);
	} else {
		// cover isn't set to NULL here... I guess it's not important
		g_StageSetup.waypoints = NULL;
		g_StageSetup.waygroups = NULL;
		g_StageSetup.intro = 0;
		g_StageSetup.props = 0;
		g_StageSetup.paths = NULL;
		g_StageSetup.ailists = NULL;
		g_StageSetup.padfiledata = NULL;

		func0f011130(0, 0);
	}

	if (IS4MB()) {
		extra = 40;
	} else {
		extra = 60;
	}

	if (IS4MB());

	g_Vars.maxprops = total + numchrs + extra + 40;
}

void setupParseObjects(s32 stagenum)
{
	s32 withchrs = !argFindByPrefix(1, "-nochr") && !argFindByPrefix(1, "-noprop");
	s32 withobjs = !argFindByPrefix(1, "-noobj") && !argFindByPrefix(1, "-noprop");
	s32 withhovercars;
	s32 escstepx;
	s32 escstepy;
	struct defaultobj *obj;
	s32 i;
	s32 j;

	withhovercars = !(stagenum == STAGE_EXTRACTION || stagenum == STAGE_DEFECTION)
		|| !(g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0);

	escstepx = 0;
	escstepy = 0;
	g_Vars.textoverrides = NULL;

	for (j = 0; j != 6; j++) {
		g_Briefing.objectivenames[j] = 0;
		g_Briefing.objectivedifficulties[j] = 0;
	}

	g_Briefing.briefingtextnum = L_MISC_042; // "No briefing for this mission"

	if (stagenum < STAGE_TITLE) {
		if (g_StageSetup.padfiledata) {
			func0f012aa0();
		}

		waypointsLoad();

		if (withchrs) {
			s32 numchrs = 0;

			numchrs += setupCountCommandType(OBJTYPE_CHR);

			if (g_Vars.normmplayerisrunning == false
					&& g_MissionConfig.iscoop
					&& g_Vars.numaibuddies > 0) {
				numchrs += g_Vars.numaibuddies;
			}

			func0f00b62c(numchrs);
		} else {
			func0f00b62c(0);
		}

		for (j = 0; j < PLAYERCOUNT(); j++) {
			setCurrentPlayerNum(j);
			invInit(setupCountCommandType(OBJTYPE_LINKGUNS));
		}

		if (g_StageSetup.props) {
			u32 diffflag = 0;
			s32 index;

			diffflag |= 1 << (lvGetDifficulty() + 4);

			if (g_Vars.mplayerisrunning) {
				if (PLAYERCOUNT() == 2) {
					diffflag |= OBJFLAG2_EXCLUDE_2P;
				} else if (PLAYERCOUNT() == 3) {
					diffflag |= OBJFLAG2_EXCLUDE_3P;
				} else if (PLAYERCOUNT() == 4) {
					diffflag |= OBJFLAG2_EXCLUDE_4P;
				}
			}

			mpRemoveAllSimulants();
			index = 0;

			obj = (struct defaultobj *)g_StageSetup.props;

			while (obj->type != OBJTYPE_END) {
				switch (obj->type) {
				case OBJTYPE_GRENADEPROB:
					{
						struct grenadeprobobj *grenadeprob = (struct grenadeprobobj *)obj;
						u8 probability = grenadeprob->probability;
						struct chrdata *chr = chrFindByLiteralId(grenadeprob->chrnum);

						if (chr && chr->prop && chr->model) {
							chr->grenadeprob = probability;
						}
					}
					break;
				case OBJTYPE_CHR:
					if (withchrs) {
						chrUnpack(stagenum, (struct packedchr *) obj, index);
					}
					break;
				case OBJTYPE_DOOR:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupDoor((struct doorobj *)obj, index);
					}
					break;
				case OBJTYPE_DOORSCALE:
					{
						struct doorscaleobj *scale = (struct doorscaleobj *)obj;
						g_DoorScale = scale->scale / 65536.0f;
					}
					break;
				case OBJTYPE_WEAPON:
					if (withchrs && (obj->flags2 & diffflag) == 0) {
						weaponAssignToHome((struct weaponobj *)obj, index);
					}
					break;
				case OBJTYPE_KEY:
					if (withchrs && (obj->flags2 & diffflag) == 0) {
						setupKey((struct keyobj *)obj, index);
					}
					break;
				case OBJTYPE_HAT:
					if (withchrs && (obj->flags2 & diffflag) == 0) {
						setupHat((struct hatobj *)obj, index);
					}
					break;
				case OBJTYPE_CCTV:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupCctv((struct cctvobj *)obj, index);
					}
					break;
				case OBJTYPE_AUTOGUN:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupAutogun((struct autogunobj *)obj, index);
					}
					break;
				case OBJTYPE_HANGINGMONITORS:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupHangingMonitors((struct hangingmonitorsobj *)obj, index);
					}
					break;
				case OBJTYPE_SINGLEMONITOR:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupSingleMonitor((struct singlemonitorobj *)obj, index);
					}
					break;
				case OBJTYPE_MULTIMONITOR:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupMultiMonitor((struct multimonitorobj *)obj, index);
					}
					break;
				case OBJTYPE_SHIELD:
					if (withobjs) {
						if ((obj->flags2 & diffflag) == 0 || g_Jpn) {
							struct shieldobj *shield = (struct shieldobj *)obj;
							shield->initialamount = *(s32 *)&shield->initialamount / 65536.0f;
							shield->amount = shield->initialamount;
							setupGenericObject(obj, index);
						}
					}
					break;
				case OBJTYPE_TINTEDGLASS:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						if (obj->flags & OBJFLAG_DEACTIVATED) {
							struct tintedglassobj *glass = (struct tintedglassobj *)obj;
							glass->portalnum = func0f00e1f8(obj->pad);
							glass->unk64 = *(s32 *)&glass->unk64 / 65536.0f;
						}

						setupGenericObject(obj, index);
					}
					break;
				case OBJTYPE_LIFT:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct liftobj *lift = (struct liftobj *)obj;
						struct modelstate *modelstate;
						s32 modelnum = obj->modelnum;
						struct prop *prop;
						s32 i;

						lift->accel = PALUPF(*(s32 *)&lift->accel) / 65536.0f;
						lift->maxspeed = PALUPF(*(s32 *)&lift->maxspeed) / 65536.0f;
						lift->dist = 0;
						lift->speed = 0;
						lift->levelcur = 0;
						lift->levelaim = 0;

						for (i = 0; i < 4; i++) {
							if (lift->doors[i]) {
								lift->doors[i] = (struct doorobj *)setupGetPtrToCommandByIndex(index + *(s32*)&lift->doors[i]);
							}
						}

						obj->numtiles = 1;
						propLoad(modelnum);
						modelstate = &g_ModelStates[modelnum];

						if (modelstate->filedata) {
							if (modelGetPartRodata(modelstate->filedata, 1)) {
								obj->numtiles++;
							}
							if (modelGetPartRodata(modelstate->filedata, 2)) {
								obj->numtiles++;
							}
							if (modelGetPartRodata(modelstate->filedata, 3)) {
								obj->numtiles++;
							}
							if (modelGetPartRodata(modelstate->filedata, 4)) {
								obj->numtiles++;
							}
							if (modelGetPartRodata(modelstate->filedata, 6)) {
								obj->numtiles++;
							}
						}

						obj->flags &= ~OBJFLAG_00000100;

						setupGenericObject(obj, index);

						prop = obj->prop;

						if (prop) {
							lift->prevpos.x = prop->pos.x;
							lift->prevpos.y = prop->pos.y;
							lift->prevpos.z = prop->pos.z;

							func0f070f08(lift, true);
						}
					}
					break;
				case OBJTYPE_HOVERPROP:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct hoverpropobj *hoverprop = (struct hoverpropobj *)obj;

						setupGenericObject(obj, index);
						setupHov(obj, &hoverprop->hov);
					}
					break;
				case OBJTYPE_HOVERBIKE:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct hoverbikeobj *bike = (struct hoverbikeobj *)obj;

						setupGenericObject(obj, index);
						setupHov(obj, &bike->hov);

						bike->speed[0] = 0;
						bike->speed[1] = 0;
						bike->w = 0;
						bike->rels[0] = 0;
						bike->rels[1] = 0;
						bike->exreal = 0;
						bike->ezreal = 0;
						bike->ezreal2 = 0;
						bike->leanspeed = 0;
						bike->leandiff = 0;
						bike->maxspeedtime240 = 0;
						bike->speedabs[0] = 0;
						bike->speedabs[1] = 0;
						bike->speedrel[0] = 0;
						bike->speedrel[1] = 0;
					}
					break;
				case OBJTYPE_FAN:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct fanobj *fan = (struct fanobj *)obj;

						fan->yrot = 0;
						fan->ymaxspeed = PALUPF(*(s32 *)&fan->ymaxspeed) / 65536.0f;
						fan->yaccel = PALUPF(*(s32 *)&fan->yaccel) / 65536.0f;

						setupGenericObject(obj, index);
					}
					break;
				case OBJTYPE_GLASS:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						if (obj->flags & OBJFLAG_DEACTIVATED) {
							struct glassobj *glass = (struct glassobj *)obj;
							glass->portalnum = func0f00e1f8(obj->pad);
						}

						setupGenericObject(obj, index);
					}
					break;
				case OBJTYPE_ESCASTEP:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct escalatorobj *step = (struct escalatorobj *)obj;
						struct prop *prop;

						// TODO: There is a stack problem here that should be
						// resolved. sp1a8 is really an Mtxf which doesn't fit
						// in its current location in the stack.
						f32 sp1a8[12];
						f32 sp184[9];

						setupGenericObject(obj, index);

						prop = obj->prop;

						if (prop) {
							step->prevpos.x = prop->pos.x;
							step->prevpos.y = prop->pos.y;
							step->prevpos.z = prop->pos.z;
						}

						if (obj->flags & OBJFLAG_DEACTIVATED) {
							step->frame = escstepy;
							escstepy += 40;
							func00016374(4.7116389274597f, (Mtxf *)sp1a8);
							func00015da0((Mtxf *)sp1a8, sp184);
							func00016110(sp184, obj->realrot);
						} else {
							step->frame = escstepx;
							escstepx += 40;
							func00016374(M_BADPI, (Mtxf *)sp1a8);
							func00015da0((Mtxf *)sp1a8, sp184);
							func00016110(sp184, obj->realrot);
						}
					}
					break;
				case OBJTYPE_BASIC:
				case OBJTYPE_ALARM:
				case OBJTYPE_AMMOCRATE:
				case OBJTYPE_DEBRIS:
				case OBJTYPE_24:
				case OBJTYPE_29:
				case OBJTYPE_SAFE:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupGenericObject(obj, index);
					}
					break;
				case OBJTYPE_MULTIAMMOCRATE:
					{
						struct multiammocrateobj *crate = (struct multiammocrateobj *)obj;
						s32 ammoqty = 1;
						s32 i;

						if (g_Vars.normmplayerisrunning && var8009cc30 >= 0) {
							struct mpweapon *mpweapon = func0f188e24(var8009cc30);
							ammoqty = mpweapon->weapon1ammoqty;

							if (mpweapon->weapon1ammotypeminusone > 0 && mpweapon->weapon1ammotypeminusone < 20) {
								crate->slots[mpweapon->weapon1ammotypeminusone - 1].quantity = ammoqty;
							}

							if (mpweapon->weapon2ammotypeminusone > 0 && mpweapon->weapon2ammotypeminusone < 20) {
								crate->slots[mpweapon->weapon2ammotypeminusone - 1].quantity = mpweapon->weapon2ammoqty;
							}
						}

						if (ammoqty > 0 && withobjs && (obj->flags2 & diffflag) == 0) {
							for (i = 0; i < 19; i++) {
								if (crate->slots[i].quantity > 0 && crate->slots[i].modelnum != 0xffff) {
									propLoad(crate->slots[i].modelnum);
								}
							}

							setupGenericObject(obj, index);
						}
					}
					break;
				case OBJTYPE_TRUCK:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct truckobj *truck = (struct truckobj *)obj;

						setupGenericObject(obj, index);

						if (obj->model) {
							struct modelnode *node = modelGetPart(obj->model->filedata, 5);

							if (node) {
								union modelrwdata *rwdata = modelGetNodeRwData(obj->model, node);
								rwdata->type05.unk00 = ((obj->flags & OBJFLAG_DEACTIVATED) == 0);
							}
						}

						truck->speed = 0;
						truck->wheelxrot = 0;
						truck->wheelyrot = 0;
						truck->speedaim = 0;
						truck->speedtime60 = -1;
						truck->turnrot60 = 0;
						truck->roty = 0;
						truck->ailist = ailistFindById((u32)truck->ailist);
						truck->aioffset = 0;
						truck->aireturnlist = -1;
						truck->path = NULL;
						truck->nextstep = 0;
					}
					break;
				case OBJTYPE_HOVERCAR:
					if (withhovercars && withobjs && (obj->flags2 & diffflag) == 0) {
						struct hovercarobj *car = (struct hovercarobj *)obj;
						struct prop *prop;

						setupGenericObject(obj, index);

						prop = obj->prop;

						car->speed = 0;
						car->speedaim = 0;
						car->turnrot60 = 0;
						car->roty = 0;
						car->rotx = 0;
						car->speedtime60 = -1;
						car->ailist = ailistFindById((s32)car->ailist);
						car->aioffset = 0;
						car->aireturnlist = -1;
						car->path = NULL;
						car->nextstep = 0;

						if (obj->flags & OBJFLAG_CHOPPER_INACTIVE) {
							prop->pos.y = func0002a36c(&prop->pos, prop->rooms, NULL, 0) + 30;
						}

						prop->unk3f_02 = true;
					}
					break;
				case OBJTYPE_CHOPPER:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct chopperobj *chopper = (struct chopperobj *)obj;

						setupGenericObject(obj, index);

						obj->flags |= OBJFLAG_20000000;
						obj->prop->unk3f_02 = true;

						chopper->turnrot60 = 0;
						chopper->roty = 0;
						chopper->rotx = 0;
						chopper->gunroty = 0;
						chopper->gunrotx = 0;
						chopper->barrelrot = 0;
						chopper->barrelrotspeed = 0;
						chopper->ailist = ailistFindById((u32)chopper->ailist);
						chopper->aioffset = 0;
						chopper->aireturnlist = -1;
						chopper->path = NULL;
						chopper->nextstep = 0;
						chopper->target = -1;
						chopper->targetvisible = false;
						chopper->attackmode = 0;
						chopper->vz = 0;
						chopper->vy = 0;
						chopper->vx = 0;
						chopper->otz = 0;
						chopper->oty = 0;
						chopper->otx = 0;
						chopper->power = 0;
						chopper->bob = 0;
						chopper->bobstrength = 0.05f;
						chopper->timer60 = 0;
						chopper->patroltimer60 = 0;
						chopper->cw = 0;
						chopper->weaponsarmed = true;
						chopper->fireslotthing = malloc(sizeof(struct fireslotthing), MEMPOOL_STAGE);
						chopper->fireslotthing->beam = malloc(ALIGN16(sizeof(struct beam)), MEMPOOL_STAGE);
						chopper->fireslotthing->beam->age = -1;
						chopper->fireslotthing->unk08 = -1;
						chopper->fireslotthing->unk00 = 0;
						chopper->fireslotthing->unk01 = 0;
						chopper->fireslotthing->unk0c = 0.85f;
						chopper->fireslotthing->unk10 = 0.2f;
						chopper->fireslotthing->unk14 = 0;
						chopper->dead = false;
					}
					break;
				case OBJTYPE_HELI:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct heliobj *heli = (struct heliobj *)obj;

						setupGenericObject(obj, index);

						heli->speed = 0;
						heli->speedaim = 0;
						heli->rotoryrot = 0;
						heli->rotoryspeed = 0;
						heli->rotoryspeedaim = 0;
						heli->yrot = 0;
						heli->speedtime60 = -1;
						heli->rotoryspeedtime = -1;
						heli->ailist = ailistFindById((u32)heli->ailist);
						heli->aioffset = 0;
						heli->aireturnlist = -1;
						heli->path = NULL;
						heli->nextstep = 0;
					}
					break;
				case OBJTYPE_TAG:
					{
						struct tag *tag = (struct tag *)obj;
						struct defaultobj *taggedobj = setupCommandGetObject(index + tag->cmdoffset);
						tag->obj = taggedobj;

						if (taggedobj) {
							taggedobj->hidden |= OBJHFLAG_TAGGED;
						}

						tagInsert(tag);
					}
					break;
				case OBJTYPE_RENAMEOBJ:
					{
						struct textoverride *override = (struct textoverride *)obj;
						struct defaultobj *targetobj = setupCommandGetObject(override->objoffset + index);
						override->obj = targetobj;

						if (targetobj) {
							targetobj->hidden |= OBJHFLAG_HASTEXTOVERRIDE;
						}

						invInsertTextOverride(override);
					}
					break;
				case OBJTYPE_BRIEFING:
					{
						struct briefingobj *briefing = (struct briefingobj *)obj;
						s32 wanttype = BRIEFINGTYPE_TEXT_PA;

						briefingInsert(briefing);

						if (lvGetDifficulty() == DIFF_A) {
							wanttype = BRIEFINGTYPE_TEXT_A;
						}

						if (lvGetDifficulty() == DIFF_SA) {
							wanttype = BRIEFINGTYPE_TEXT_SA;
						}

						if (briefing->type == wanttype) {
							g_Briefing.briefingtextnum = briefing->text;
						}
					}
					break;
				case OBJTYPE_CAMERAPOS:
					{
						struct cameraposobj *camera = (struct cameraposobj *)obj;
						camera->x = *(s32 *)&camera->x / 100.0f;
						camera->y = *(s32 *)&camera->y / 100.0f;
						camera->z = *(s32 *)&camera->z / 100.0f;
						camera->theta = *(s32 *)&camera->theta / 65536.0f;
						camera->verta = *(s32 *)&camera->verta / 65536.0f;
					}
					break;
				case OBJTYPE_BEGINOBJECTIVE:
					{
						struct objective *objective = (struct objective *)obj;

						objectiveInsert(objective);

						if ((u32)objective->index < 7) {
							g_Briefing.objectivenames[objective->index] = objective->text;
							g_Briefing.objectivedifficulties[objective->index] = objective->difficulties;
						}
					}
					break;
				case OBJECTIVETYPE_ENTERROOM:
					objectiveAddRoomEnteredCriteria((struct criteria_roomentered *)obj);
					break;
				case OBJECTIVETYPE_ATTACHOBJ:
					objectiveAddMultiroomEnteredCriteria((struct criteria_multiroomentered *)obj);
					break;
				case OBJECTIVETYPE_HOLOGRAPH:
					objectiveAddHolographCriteria((struct criteria_holograph *)obj);
					break;
				case OBJTYPE_PADEFFECT:
					{
						struct padeffectobj *padeffect = (struct padeffectobj *)obj;
						if (var80069964 == -1) {
							var80069960 = padeffect;
						}
						var80069964++;
					}
					break;
				case OBJTYPE_MINE:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupMine((struct mineobj *)obj, index);
					}
					break;
				}

				obj = (struct defaultobj *)((u32 *)obj + setupGetCommandLength((u32 *)obj));
				index++;
			}

			index = 0;

			if (g_Vars.normmplayerisrunning && mpHasSimulants()) {
				u32 stack[4];
				s32 i;
				s32 slotsdone[8];
				s32 chrnum = 0;
				s32 maxsimulants;
				s32 slotnum;

				if (mpIsFeatureUnlocked(MPFEATURE_8BOTS)) {
					maxsimulants = 8;
				} else {
					maxsimulants = 4;
				}

				for (i = 0; i < 8; i++) {
					slotsdone[i] = false;
				}

				for (i = 0; i < maxsimulants; i++) {
					slotnum = random() % maxsimulants;

					while (slotsdone[slotnum]) {
						slotnum = (slotnum + 1) % maxsimulants;
					}

					if ((g_MpSetup.chrslots & (1 << (slotnum + 4)))
							&& mpIsSimSlotEnabled(slotnum)) {
						aibotAllocate(chrnum, slotnum);
						chrnum++;
					}

					slotsdone[slotnum] = true;
				}
			}

			if (g_Vars.normmplayerisrunning) {
				scenarioReset();
			}

			obj = (struct defaultobj *)g_StageSetup.props;

			while (obj->type != OBJTYPE_END) {
				switch (obj->type) {
				case OBJTYPE_BASIC:
				case OBJTYPE_KEY:
				case OBJTYPE_AMMOCRATE:
				case OBJTYPE_WEAPON:
				case OBJTYPE_SINGLEMONITOR:
				case OBJTYPE_DEBRIS:
				case OBJTYPE_MULTIAMMOCRATE:
				case OBJTYPE_SHIELD:
				case OBJTYPE_24:
				case OBJTYPE_29:
				case OBJTYPE_GLASS:
				case OBJTYPE_SAFE:
				case OBJTYPE_TINTEDGLASS:
					if (obj->prop && (obj->flags & OBJFLAG_00008000)) {
						s32 offset = obj->pad;
						struct defaultobj *owner = setupCommandGetObject(index + offset);

						if (owner && owner->prop) {
							obj->hidden |= OBJHFLAG_HASOWNER;
							modelSetScale(obj->model, obj->model->scale);
							propReparent(obj->prop, owner->prop);
						}
					}
					break;
				case OBJTYPE_LINKGUNS:
					{
						struct linkgunsobj *link = (struct linkgunsobj *)obj;
						struct weaponobj *gun1 = (struct weaponobj *)setupGetPtrToCommandByIndex(link->offset1 + index);
						struct weaponobj *gun2 = (struct weaponobj *)setupGetPtrToCommandByIndex(link->offset2 + index);

						if (gun1 && gun2
								&& gun1->base.type == OBJTYPE_WEAPON
								&& gun2->base.type == OBJTYPE_WEAPON) {
							propweaponSetDual(gun1, gun2);
						}
					}
					break;
				case OBJTYPE_LINKLIFTDOOR:
					{
						struct linkliftdoorobj *link = (struct linkliftdoorobj *)obj;
						s32 dooroffset = (s32)link->door;
						s32 liftoffset = (s32)link->lift;
						struct defaultobj *door = setupCommandGetObject(index + dooroffset);
						struct defaultobj *lift = setupCommandGetObject(index + liftoffset);

						if (door && door->prop && lift && lift->prop) {
							link->door = door->prop;
							link->lift = lift->prop;

							addLiftDoor(link);

							door->hidden |= OBJHFLAG_LIFTDOOR;
						}
					}
					break;
				case OBJTYPE_SAFEITEM:
					{
						struct safeitemobj *link = (struct safeitemobj *)obj;
						s32 itemoffset = (s32)link->item;
						s32 safeoffset = (s32)link->safe;
						s32 dooroffset = (s32)link->door;
						struct defaultobj *item = setupCommandGetObject(index + itemoffset);
						struct defaultobj *safe = setupCommandGetObject(index + safeoffset);
						struct defaultobj *door = setupCommandGetObject(index + dooroffset);

						if (item && item->prop
								&& safe && safe->prop && safe->type == OBJTYPE_SAFE
								&& door && door->prop && door->type == OBJTYPE_DOOR) {
							link->item = item;
							link->safe = (struct safeobj *)safe;
							link->door = (struct doorobj *)door;

							addSafeItem(link);

							item->flags2 |= OBJFLAG2_LINKEDTOSAFE;
							door->flags2 |= OBJFLAG2_LINKEDTOSAFE;
						}
					}
					break;
				case OBJTYPE_PADLOCKEDDOOR:
					{
						struct padlockeddoorobj *link = (struct padlockeddoorobj *)obj;
						s32 dooroffset = (s32)link->door;
						s32 lockoffset = (s32)link->lock;
						struct defaultobj *door = setupCommandGetObject(index + dooroffset);
						struct defaultobj *lock = setupCommandGetObject(index + lockoffset);

						if (door && door->prop && lock && lock->prop
								&& door->type == OBJTYPE_DOOR) {
							link->door = (struct doorobj *)door;
							link->lock = lock;

							addPadlockedDoor(link);

							door->hidden |= OBJHFLAG_PADLOCKEDDOOR;
						}
					}
					break;
				case OBJTYPE_CONDITIONALSCENERY:
					{
						struct linksceneryobj *link = (struct linksceneryobj *)obj;
						s32 triggeroffset = (s32)link->trigger;
						s32 unexpoffset = (s32)link->unexp;
						s32 expoffset = (s32)link->exp;
						struct defaultobj *trigger = setupCommandGetObject(index + triggeroffset);
						struct defaultobj *unexp = NULL;
						struct defaultobj *exp = NULL;
						s32 alwayszero = 0;

						if (unexpoffset) {
							unexp = setupCommandGetObject(index + unexpoffset);
						}

						if (expoffset) {
							exp = setupCommandGetObject(index + expoffset);
						}

						if (trigger && trigger->prop
								&& (unexpoffset == 0 || (unexp && unexp->prop))
								&& (expoffset == 0 || (exp && exp->prop))) {
							link->trigger = trigger;
							link->unexp = unexp;
							link->exp = exp;

							addConditionalScenery(link);

							trigger->hidden |= OBJHFLAG_01000000;

							if (unexpoffset) {
								unexp->hidden |= OBJHFLAG_01000000;
							}

							// This gets optimised out but makes v0 unavailable
							// for storing OBJHFLAG_01000000, which is required
							// for a match. Any function call would work; I just
							// copied the one above.
							if (alwayszero) {
								addConditionalScenery(link);
							}

							if (expoffset) {
								exp->hidden |= OBJHFLAG_01000000;
								exp->flags2 |= OBJFLAG2_INVISIBLE;
							}

							if (trigger->hidden & OBJHFLAG_02000000) {
								objSetBlockedPathUnblocked(trigger, false);
							}
						}
					}
					break;
				case OBJTYPE_BLOCKEDPATH:
					{
						struct blockedpathobj *blockedpath = (struct blockedpathobj *)obj;
						s32 objoffset = (s32)blockedpath->blocker;
						struct defaultobj *blocker = setupCommandGetObject(index + objoffset);

						if (blocker && blocker->prop) {
							blockedpath->blocker = blocker;

							addBlockedPath(blockedpath);

							blocker->hidden |= OBJHFLAG_02000000;

							if (blocker->hidden & OBJHFLAG_01000000) {
								objSetBlockedPathUnblocked(blocker, false);
							}
						}
					}
					break;
				}

				obj = (struct defaultobj *)((u32 *)obj + setupGetCommandLength((u32 *)obj));
				index++;
			}
		}
	} else {
		func0f00b62c(0);
	}

	stageAllocateBgChrs();
}
//#endif
