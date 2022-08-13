#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/game_00b820.h"
#include "game/setup.h"
#include "game/objectives.h"
#include "game/playerreset.h"
#include "game/botmgr.h"
#include "game/chr.h"
#include "game/body.h"
#include "game/prop.h"
#include "game/setuputils.h"
#include "game/atan2f.h"
#include "game/inv.h"
#include "game/playermgr.h"
#include "game/bg.h"
#include "game/stagetable.h"
#include "game/file.h"
#include "game/lv.h"
#include "game/mplayer/scenarios.h"
#include "game/challenge.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/memp.h"
#include "lib/model.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/ailist.h"
#include "lib/anim.h"
#include "lib/collision.h"
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

void propsReset(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_Lifts); i++) {
		g_Lifts[i] = NULL;
	}

	g_MaxWeaponSlots = 50;
	g_MaxHatSlots = 10;
	g_MaxAmmoCrates = 20;
	g_MaxDebrisSlots = 15;
	g_MaxProjectiles = IS4MB() ? 20 : 100;
	g_MaxEmbedments = IS4MB() ? 40 : 80;

	if (g_Vars.stagenum >= STAGE_TITLE) {
		g_MaxWeaponSlots = 0;
		g_MaxHatSlots = 0;
		g_MaxAmmoCrates = 0;
		g_MaxDebrisSlots = 0;
		g_MaxProjectiles = 0;
		g_MaxEmbedments = 0;
	}

	setupReset0f00cc8c();
	setupResetProxyMines();

	g_AlarmTimer = 0;
	g_AlarmAudioHandle = NULL;
	g_AlarmSpeakerWeight = 64;

	g_GasReleaseTimer240 = 0;
	g_GasReleasing = false;
	g_GasPos.x = 0;
	g_GasPos.y = 0;
	g_GasPos.z = 0;
	g_GasLastCough60 = 0;
	g_GasSoundTimer240 = 0;
	g_GasAudioHandle = NULL;

	g_CountdownTimerOff = COUNTDOWNTIMERREASON_AI;
	g_CountdownTimerRunning = false;
	g_CountdownTimerValue60 = 0;

	g_PlayersDetonatingMines = 0;
	g_TintedGlassEnabled = false;

	if (g_MaxWeaponSlots == 0) {
		g_WeaponSlots = NULL;
	} else {
		g_WeaponSlots = mempAlloc(ALIGN16(g_MaxWeaponSlots * sizeof(struct weaponobj)), MEMPOOL_STAGE);

		for (i = 0; i < g_MaxWeaponSlots; i++) {
			g_WeaponSlots[i].base.prop = NULL;
		}

		g_NextWeaponSlot = 0;
	}

	if (g_MaxHatSlots == 0) {
		g_HatSlots = NULL;
	} else {
		g_HatSlots = mempAlloc(ALIGN16(g_MaxHatSlots * sizeof(struct hatobj)), MEMPOOL_STAGE);

		for (i = 0; i < g_MaxHatSlots; i++) {
			g_HatSlots[i].base.prop = NULL;
		}

		g_NextHatSlot = 0;
	}

	if (g_MaxAmmoCrates == 0) {
		g_AmmoCrates = NULL;
	} else {
		g_AmmoCrates = mempAlloc(ALIGN16(g_MaxAmmoCrates * sizeof(struct ammocrateobj)), MEMPOOL_STAGE);

		for (i = 0; i < g_MaxAmmoCrates; i++) {
			g_AmmoCrates[i].base.prop = NULL;
		}
	}

	if (g_MaxDebrisSlots == 0) {
		g_DebrisSlots = NULL;
	} else {
		g_DebrisSlots = mempAlloc(ALIGN16(g_MaxDebrisSlots * sizeof(struct defaultobj)), MEMPOOL_STAGE);

		for (i = 0; i < g_MaxDebrisSlots; i++) {
			g_DebrisSlots[i].prop = NULL;
		}
	}

	if (g_MaxProjectiles == 0) {
		g_Projectiles = NULL;
	} else {
		g_Projectiles = mempAlloc(ALIGN16(g_MaxProjectiles * sizeof(struct projectile)), MEMPOOL_STAGE);

		for (i = 0; i < g_MaxProjectiles; i++) {
			g_Projectiles[i].flags = PROJECTILEFLAG_FREE;
		}
	}

	if (g_MaxEmbedments == 0) {
		g_Embedments = NULL;
	} else {
		g_Embedments = mempAlloc(ALIGN16(g_MaxEmbedments * sizeof(struct embedment)), MEMPOOL_STAGE);

		for (i = 0; i < g_MaxEmbedments; i++) {
			g_Embedments[i].flags = EMBEDMENTFLAG_FREE;
		}
	}

	g_LiftDoors = NULL;
	g_PadlockedDoors = NULL;
	g_SafeItems = NULL;
	g_LinkedScenery = NULL;
	g_BlockedPaths = NULL;

	g_EmbedProp = NULL;
	g_EmbedHitPart = -1;
	g_CctvWaitScale = 1;
	g_CctvDamageRxScale = 1;
	g_AutogunAccuracyScale = 1;
	g_AutogunDamageTxScale = 1;
	g_AutogunDamageRxScale = 1;
	g_AmmoQuantityScale = 1;

	g_MaxThrownLaptops = g_Vars.normmplayerisrunning ? 12 : PLAYERCOUNT();

	g_ThrownLaptops = mempAlloc(ALIGN16(g_MaxThrownLaptops * sizeof(struct autogunobj)), MEMPOOL_STAGE);
	g_ThrownLaptopBeams = mempAlloc(ALIGN16(g_MaxThrownLaptops * sizeof(struct beam)), MEMPOOL_STAGE);

	for (i = 0; i < g_MaxThrownLaptops; i++) {
		g_ThrownLaptops[i].base.prop = NULL;
	}
}

void setupCreateLiftDoor(struct linkliftdoorobj *link)
{
	link->next = g_LiftDoors;
	g_LiftDoors = link;
}

void setupCreatePadlockedDoor(struct padlockeddoorobj *link)
{
	link->next = g_PadlockedDoors;
	g_PadlockedDoors = link;
}

void setupCreateSafeItem(struct safeitemobj *link)
{
	link->next = g_SafeItems;
	g_SafeItems = link;
}

void setupCreateConditionalScenery(struct linksceneryobj *link)
{
	link->next = g_LinkedScenery;
	g_LinkedScenery = link;
}

void setupCreateBlockedPath(struct blockedpathobj *blockedpath)
{
	blockedpath->next = g_BlockedPaths;
	g_BlockedPaths = blockedpath;
}

void setupReset0f00cc8c(void)
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

void setupResetProxyMines(void)
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

			obj = (struct defaultobj *)((u32 *)obj + setupGetCmdLength((u32 *)obj));
		}
	}

	return count;
}

GLOBAL_ASM(
glabel setupCreateObject
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
/*  f00cefc:	0fc2486d */ 	jal	setupLoadModeldef
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
/*  f00cfac:	0fc1a94b */ 	jal	objInitWithModelDef
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
/*  f00d048:	0fc1a94b */ 	jal	objInitWithModelDef
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
/*  f00d0d8:	0fc1a94b */ 	jal	objInitWithModelDef
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
/*  f00d164:	0c005b56 */ 	jal	mtx00016d58
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
/*  f00d280:	0fc1a954 */ 	jal	objInitWithAutoModel
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
/*  f00d55c:	0c005789 */ 	jal	mtx00015e24
/*  f00d560:	e7b2005c */ 	swc1	$f18,0x5c($sp)
/*  f00d564:	c7ac0060 */ 	lwc1	$f12,0x60($sp)
/*  f00d568:	0c0057a0 */ 	jal	mtx00015e80
/*  f00d56c:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f00d570:	c7ac005c */ 	lwc1	$f12,0x5c($sp)
/*  f00d574:	0c0057b7 */ 	jal	mtx00015edc
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
/*  f00d5bc:	0c0057c1 */ 	jal	mtx00015f04
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
/*  f00d63c:	0fc1814e */ 	jal	propActivateThisFrame
/*  f00d640:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f00d644:	10000003 */ 	b	.L0f00d654
/*  f00d648:	00000000 */ 	nop
.L0f00d64c:
/*  f00d64c:	0fc1812f */ 	jal	propActivate
/*  f00d650:	8fa4007c */ 	lw	$a0,0x7c($sp)
.L0f00d654:
/*  f00d654:	0fc180bc */ 	jal	propEnable
/*  f00d658:	8fa4007c */ 	lw	$a0,0x7c($sp)
.L0f00d65c:
/*  f00d65c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f00d660:
/*  f00d660:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f00d664:	27bd0148 */ 	addiu	$sp,$sp,0x148
/*  f00d668:	03e00008 */ 	jr	$ra
/*  f00d66c:	00000000 */ 	nop
);

//void setupCreateObject(struct defaultobj *obj, s32 cmdindex)
//{
//	f32 f0;
//	s32 modelnum; // 140
//	struct pad pad; // ec
//	Mtxf spac; // ac
//	struct coord centre; // a0
//	f32 scale; // 9c
//	struct coord pos; // 90
//	s16 rooms[8];
//	struct prop *prop2; // 7c
//	u32 stack[2];
//	struct chrdata *chr; // 70
//	struct prop *prop; // 6c
//
//	modelnum = obj->modelnum;
//	setupLoadModeldef(modelnum);
//	scale = obj->extrascale * (1.0f / 256.0f);
//
//	if (g_Vars.normmplayerisrunning || g_Vars.lvmpbotlevel) {
//		obj->hidden2 |= OBJH2FLAG_CANREGEN;
//	}
//
//	if (obj->flags & OBJFLAG_INSIDEANOTHEROBJ) {
//		if (obj->type == OBJTYPE_WEAPON) {
//			func0f08ae0c((struct weaponobj *)obj, g_ModelStates[modelnum].filedata);
//		} else {
//			objInitWithModelDef(obj, g_ModelStates[modelnum].filedata);
//		}
//
//		modelSetScale(obj->model, obj->model->scale * scale);
//		return;
//	}
//
//	if (obj->flags & OBJFLAG_ASSIGNEDTOCHR) {
//		chr = chrFindByLiteralId(obj->pad);
//
//		if (chr && chr->prop && chr->model) {
//			if (obj->type == OBJTYPE_WEAPON) {
//				prop = func0f08ae0c((struct weaponobj *)obj, g_ModelStates[modelnum].filedata);
//			} else {
//				prop = objInitWithModelDef(obj, g_ModelStates[modelnum].filedata);
//			}
//
//			modelSetScale(obj->model, obj->model->scale * scale);
//			propReparent(prop, chr->prop);
//		}
//	} else {
//		if (obj->pad < 0) {
//			if (obj->type == OBJTYPE_WEAPON) {
//				func0f08ae0c((struct weaponobj *)obj, g_ModelStates[modelnum].filedata);
//			} else {
//				objInitWithModelDef(obj, g_ModelStates[modelnum].filedata);
//			}
//
//			modelSetScale(obj->model, obj->model->scale * scale);
//			return;
//		}
//
//		padUnpack(obj->pad, PADFIELD_POS | PADFIELD_LOOK | PADFIELD_UP | PADFIELD_BBOX | PADFIELD_ROOM, &pad);
//
//		if (pad.room > 0) {
//			mtx00016d58(&spac, 0, 0, 0, -pad.look.x, -pad.look.y, -pad.look.z, pad.up.x, pad.up.y, pad.up.z);
//
//			pos.x = pad.pos.x;
//			pos.y = pad.pos.y;
//			pos.z = pad.pos.z;
//
//			rooms[0] = pad.room;
//			rooms[1] = -1;
//
//			if (!padHasBboxData(obj->pad)) {
//				if (obj->flags & OBJFLAG_00000002) {
//					centre.x = pad.pos.x;
//					centre.y = pad.pos.y;
//					centre.z = pad.pos.z;
//				} else {
//					centre.x = pad.pos.x;
//					centre.y = pad.pos.y;
//					centre.z = pad.pos.z;
//				}
//			} else {
//				padGetCentre(obj->pad, &centre);
//				centre.x += (pad.bbox.ymin - pad.bbox.ymax) * 0.5f * pad.up.x;
//				centre.y += (pad.bbox.ymin - pad.bbox.ymax) * 0.5f * pad.up.y;
//				centre.z += (pad.bbox.ymin - pad.bbox.ymax) * 0.5f * pad.up.z;
//			}
//
//			if (obj->type == OBJTYPE_WEAPON) {
//				prop2 = func0f08ae0c((struct weaponobj *)obj, g_ModelStates[modelnum].filedata);
//			} else {
//				prop2 = objInitWithAutoModel(obj);
//			}
//
//			if (padHasBboxData(obj->pad)) {
//				struct modelrodata_bbox *bbox = objFindBboxRodata(obj);
//
//				if (bbox != NULL) {
//					f32 sp64 = 1.0f;
//					f32 sp60 = 1.0f;
//					f32 sp5c = 1.0f;
//					f32 f12;
//					f32 sp54;
//
//					if (obj->flags & OBJFLAG_00000020) {
//						if (bbox->xmin < bbox->xmax) {
//							if (obj->flags & OBJFLAG_00000002) {
//								sp64 = (pad.bbox.xmax - pad.bbox.xmin) / ((bbox->xmax - bbox->xmin) * obj->model->scale);
//							} else {
//								sp64 = (pad.bbox.xmax - pad.bbox.xmin) / ((bbox->xmax - bbox->xmin) * obj->model->scale);
//							}
//						}
//					}
//
//					if (obj->flags & OBJFLAG_00000040) {
//						if (bbox->ymin < bbox->ymax) {
//							if (obj->flags & OBJFLAG_00000002) {
//								sp5c = (pad.bbox.zmax - pad.bbox.zmin) / ((bbox->ymax - bbox->ymin) * obj->model->scale);
//							} else {
//								sp60 = (pad.bbox.ymax - pad.bbox.ymin) / ((bbox->ymax - bbox->ymin) * obj->model->scale);
//							}
//						}
//					}
//
//					if (obj->flags & OBJFLAG_00000080) {
//						if (bbox->zmin < bbox->zmax) {
//							if (obj->flags & OBJFLAG_00000002) {
//								sp60 = (pad.bbox.ymax - pad.bbox.ymin) / ((bbox->zmax - bbox->zmin) * obj->model->scale);
//							} else {
//								sp5c = (pad.bbox.zmax - pad.bbox.zmin) / ((bbox->zmax - bbox->zmin) * obj->model->scale);
//							}
//						}
//					}
//
//					// 400
//					// Goal compares sp60 with sp64 here, then optimises out
//					// whatever's inside the branch, then unconditionally sets
//					// sp54 to sp64 around 418. The below isn't quite the same;
//					// we set sp54 to sp60 to prevent the first if statement
//					// from being completely optimised out which gives closer
//					// codegen.
//					//
//					// Register mappings:
//					// f12 = sp64
//					// f16 = sp60
//					// f18 = sp5c
//					// f14 = sp54
//
//					sp54 = sp60;
//
//					if (sp64 > sp54) { // f12 < f16
//						sp54 = sp64; // optimised out
//					}
//
//					// 418
//					if (sp60 > sp54) { // f12 < f16
//						sp54 = sp60; // f14 = f16
//					}
//
//					// 42c
//					if (sp5c > sp54) { // f14 < f18
//						sp54 = sp5c; // f14 = f18
//					}
//
//					// 444
//					if ((obj->flags & OBJFLAG_00000020) == 0) {
//						if (obj->flags & OBJFLAG_00000002) {
//							if (bbox->xmax == bbox->xmin) {
//								sp64 = sp54;
//							}
//						} else if (bbox->xmax == bbox->xmin) {
//							sp64 = sp54;
//						}
//					}
//
//					if ((obj->flags & OBJFLAG_00000040) == 0) {
//						if (obj->flags & OBJFLAG_00000002) {
//							if (bbox->ymax == bbox->ymin) {
//								sp5c = sp54;
//							}
//						} else if (bbox->ymax == bbox->ymin) {
//							sp60 = sp54;
//						}
//					}
//
//					if ((obj->flags & OBJFLAG_00000080) == 0) {
//						if (obj->flags & OBJFLAG_00000002) {
//							if (bbox->zmax == bbox->zmin) {
//								sp60 = sp54;
//							}
//						} else if (bbox->zmax == bbox->zmin) {
//							sp5c = sp54;
//						}
//					}
//
//					sp64 /= sp54;
//					sp60 /= sp54;
//					sp5c /= sp54;
//
//					if (sp64 <= 0.000001f || sp60 <= 0.000001f || sp5c <= 0.000001f) {
//						sp64 = 1;
//						sp60 = 1;
//						sp5c = 1;
//					}
//
//					mtx00015e24(sp64, &spac);
//					mtx00015e80(sp60, &spac);
//					mtx00015edc(sp5c, &spac);
//
//					modelSetScale(obj->model, obj->model->scale * sp54);
//				}
//			}
//
//			modelSetScale(obj->model, obj->model->scale * scale);
//			mtx00015f04(obj->model->scale, &spac);
//
//			if (obj->flags2 & OBJFLAG2_00020000) {
//				prop2->flags |= PROPFLAG_DONTPAUSE;
//			}
//
//			if (obj->flags & OBJFLAG_00000002) {
//				func0f06ab60(obj, &pos, &spac, rooms, &centre);
//			} else {
//				func0f06a730(obj, &pos, &spac, rooms, &centre);
//			}
//
//			if (obj->hidden & OBJHFLAG_00008000) {
//				propActivateThisFrame(prop2);
//			} else {
//				propActivate(prop2);
//			}
//
//			propEnable(prop2);
//		}
//	}
//}

/**
 * Assigns a weapon to its home.
 *
 * Its home is a chr's hand or a pad, as defined in the stage's setup file.
 *
 * The Marquis of Queensbury Rules (everyone unarmed) and Enemy Rockets cheats
 * are implemented here.
 */
void setupPlaceWeapon(struct weaponobj *weapon, s32 cmdindex)
{
	if (weapon->base.flags & OBJFLAG_ASSIGNEDTOCHR) {
		u32 stack[2];
		struct chrdata *chr = chrFindByLiteralId(weapon->base.pad);

		if (chr && chr->prop && chr->model) {
			if (cheatIsActive(CHEAT_MARQUIS)) {
				// NTSC 1.0 and newer simplifies the Marquis logic
#if VERSION >= VERSION_NTSC_1_0
				weapon->base.flags &= ~OBJFLAG_DEACTIVATED;
				weapon->base.flags |= OBJFLAG_WEAPON_AICANNOTUSE;
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
					weapon->base.flags |= OBJFLAG_WEAPON_AICANNOTUSE;
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
					setupCreateObject(&shield->base, cmdindex);
					giveweapon = false;
				}
				break;
			}
		}

		if (weapon->weaponnum != WEAPON_NONE && giveweapon) {
			weaponLoadProjectileModels(weapon->weaponnum);
			setupCreateObject(&weapon->base, cmdindex);
		}
	}
}

void setupCreateHat(struct hatobj *hat, s32 cmdindex)
{
	if (hat->base.flags & OBJFLAG_ASSIGNEDTOCHR) {
		struct chrdata *chr = chrFindByLiteralId(hat->base.pad);

		if (chr && chr->prop && chr->model) {
			hatAssignToChr(hat, chr);
		}
	} else {
		setupCreateObject(&hat->base, cmdindex);
	}
}

void setupCreateKey(struct keyobj *key, s32 cmdindex)
{
	setupCreateObject(&key->base, cmdindex);
}

void setupCreateMine(struct mineobj *mine, s32 cmdindex)
{
	mine->base.type = OBJTYPE_WEAPON;

	setupCreateObject(&mine->base, cmdindex);

	if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
		mine->base.hidden = mine->base.hidden & 0x0fffffff | OBJHFLAG_20000000;
	}

	mine->base.prop->forcetick = true;
}

void setupCreateCctv(struct cctvobj *cctv, s32 cmdindex)
{
	struct defaultobj *obj = &cctv->base;

	setupCreateObject(obj, cmdindex);

	if (cctv->lookatpadnum >= 0) {
		struct coord lenspos;
		union modelrodata *lens = modelGetPartRodata(obj->model->filedata, MODELPART_CCTV_CASING);
		struct pad pad;
		f32 xdiff;
		f32 ydiff;
		f32 zdiff;

		padUnpack(cctv->lookatpadnum, PADFIELD_POS, &pad);

		lenspos.x = lens->position.pos.x;
		lenspos.y = lens->position.pos.y;
		lenspos.z = lens->position.pos.z;

		mtx00016208(obj->realrot, &lenspos);

		lenspos.x += obj->prop->pos.x;
		lenspos.y += obj->prop->pos.y;
		lenspos.z += obj->prop->pos.z;

		xdiff = lenspos.x - pad.pos.x;
		ydiff = lenspos.y - pad.pos.y;
		zdiff = lenspos.z - pad.pos.z;

		if (ydiff) {
			// empty
		}

		mtx00016d58(&cctv->camrotm, 0.0f, 0.0f, 0.0f, xdiff, ydiff, zdiff, 0.0f, 1.0f, 0.0f);
		mtx00015f04(obj->model->scale, &cctv->camrotm);

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

void setupCreateAutogun(struct autogunobj *autogun, s32 cmdindex)
{
	setupCreateObject(&autogun->base, cmdindex);

	autogun->maxspeed = *(s32 *)&autogun->maxspeed * PALUPF(M_BADTAU) / 65536.0f;
	autogun->aimdist = *(s32 *)&autogun->aimdist * 100.0f / 65536.0f;
	autogun->ymaxleft = *(s32 *)&autogun->ymaxleft * M_BADTAU / 65536.0f;
	autogun->ymaxright = *(s32 *)&autogun->ymaxright * M_BADTAU / 65536.0f;

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
	autogun->beam = mempAlloc(ALIGN16(sizeof(struct beam)), MEMPOOL_STAGE);
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

void setupCreateHangingMonitors(struct hangingmonitorsobj *monitors, s32 cmdindex)
{
	setupCreateObject(&monitors->base, cmdindex);
}

void setupCreateSingleMonitor(struct singlemonitorobj *monitor, s32 cmdindex)
{
	u32 stack[2];

	monitor->screen = var8009ce98;
	tvscreenSetImageByNum(&monitor->screen, monitor->imagenum);

	// In GE, monitors with a negative pad are hanging TVs which attach to a
	// hangingmonitors object, which is actually just the mount. In PD, hanging
	// monitors do not exist in the setup files so this code is unused.
	if (monitor->base.pad < 0 && (monitor->base.flags & OBJFLAG_INSIDEANOTHEROBJ) == 0) {
		s32 modelnum = monitor->base.modelnum;
		struct defaultobj *owner = (struct defaultobj *)setupGetCmdByIndex(cmdindex + monitor->owneroffset);
		struct prop *prop;
		f32 scale;
		struct coord spa4;
		Mtxf sp64;
		Mtxf sp24;

		setupLoadModeldef(modelnum);

		scale = monitor->base.extrascale * (1.0f / 256.0f);

		if (g_Vars.normmplayerisrunning || g_Vars.lvmpbotlevel) {
			monitor->base.hidden2 |= OBJH2FLAG_CANREGEN;
		}

		prop = objInitWithAutoModel(&monitor->base);
		monitor->base.embedment = embedmentAllocate();

		if (prop && monitor->base.embedment) {
			monitor->base.hidden |= OBJHFLAG_EMBEDDED;
			modelSetScale(monitor->base.model, monitor->base.model->scale * scale);
			monitor->base.model->attachedtomodel = owner->model;

			if (monitor->ownerpart == MODELPART_0000) {
				monitor->base.model->attachedtonode = modelGetPart(owner->model->filedata, MODELPART_0000);
			} else if (monitor->ownerpart == MODELPART_0001) {
				monitor->base.model->attachedtonode = modelGetPart(owner->model->filedata, MODELPART_0001);
			} else if (monitor->ownerpart == MODELPART_0002) {
				monitor->base.model->attachedtonode = modelGetPart(owner->model->filedata, MODELPART_0002);
			} else {
				monitor->base.model->attachedtonode = modelGetPart(owner->model->filedata, MODELPART_0003);
			}

			propReparent(prop, owner->prop);
			mtx4LoadXRotation(0.3664608001709f, &sp64);
			mtx00015f04(monitor->base.model->scale / owner->model->scale, &sp64);
			modelGetRootPosition(monitor->base.model, &spa4);

			spa4.x = -spa4.x;
			spa4.y = -spa4.y;
			spa4.z = -spa4.z;

			mtx4LoadTranslation(&spa4, &sp24);
			mtx00015be4(&sp64, &sp24, &monitor->base.embedment->matrix);
		}
	} else {
		setupCreateObject(&monitor->base, cmdindex);
	}

	if (monitor->base.prop && (monitor->base.flags & OBJFLAG_MONITOR_RENDERPOSTBG)) {
		monitor->base.prop->flags |= PROPFLAG_RENDERPOSTBG;
	}
}

void setupCreateMultiMonitor(struct multimonitorobj *monitor, s32 cmdindex)
{
	monitor->screens[0] = var8009ce98;
	tvscreenSetImageByNum(&monitor->screens[0], monitor->imagenums[0]);

	monitor->screens[1] = var8009ce98;
	tvscreenSetImageByNum(&monitor->screens[1], monitor->imagenums[1]);

	monitor->screens[2] = var8009ce98;
	tvscreenSetImageByNum(&monitor->screens[2], monitor->imagenums[2]);

	monitor->screens[3] = var8009ce98;
	tvscreenSetImageByNum(&monitor->screens[3], monitor->imagenums[3]);

	setupCreateObject(&monitor->base, cmdindex);
}

s32 setupGetPortalByPad(s32 padnum)
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

	return bg0f164e8c(&centre, &coord);
}

s32 setupGetPortalByDoorPad(s32 padnum)
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

	return bg0f164e8c(&centre, &coord);
}

void setupCreateDoor(struct doorobj *door, s32 cmdindex)
{
	f32 scale;
	s32 modelnum = door->base.modelnum;
	s32 portalnum = -1;
	struct pad pad;

	setupLoadModeldef(modelnum);

	if (door->doorflags & DOORFLAG_ROTATEDPAD) {
		padRotateForDoor(door->base.pad);
	}

	if (door->base.flags & OBJFLAG_DOOR_HASPORTAL) {
		portalnum = setupGetPortalByDoorPad(door->base.pad);
	}

	padUnpack(door->base.pad, PADFIELD_POS | PADFIELD_LOOK | PADFIELD_UP | PADFIELD_NORMAL | PADFIELD_BBOX | PADFIELD_ROOM, &pad);

	if (g_DoorScale != 1) {
		pad.bbox.xmin *= g_DoorScale;
		pad.bbox.xmax *= g_DoorScale;

		// If the door has a portal, adjust the pad's bbox to match the portal's dimensions
		if (portalnum >= 0) {
			struct var800a4ccc *ptr = &var800a4ccc[portalnum];
			f32 f0 = pad.pos.f[0] * ptr->coord.f[0] + pad.pos.f[1] * ptr->coord.f[1] + pad.pos.f[2] * ptr->coord.f[2];
			f32 min = ptr->min;
			struct coord sp150;
			f0 = (f0 - min) * (g_DoorScale - 1);

			sp150.x = ptr->coord.x * f0;
			sp150.y = ptr->coord.y * f0;
			sp150.z = ptr->coord.z * f0;

			f0 = sp150.f[0] * pad.normal.f[0] + sp150.f[1] * pad.normal.f[1] + sp150.f[2] * pad.normal.f[2];
			pad.bbox.xmin += f0;
			pad.bbox.xmax += f0;

			f0 = sp150.f[0] * pad.up.f[0] + sp150.f[1] * pad.up.f[1] + sp150.f[2] * pad.up.f[2];
			pad.bbox.ymin += f0;
			pad.bbox.ymax += f0;

			f0 = sp150.f[0] * pad.look.f[0] + sp150.f[1] * pad.look.f[1] + sp150.f[2] * pad.look.f[2];
			pad.bbox.zmin += f0;
			pad.bbox.zmax += f0;
		}

		// Write the modified bbox into the pad file data
		padCopyBboxFromPad(door->base.pad, &pad);
	}

	if (pad.room > 0) {
		Mtxf sp110;
		struct prop *prop;
		s32 siblingcmdindex;
		struct coord pos;
		s16 rooms[8];
		Mtxf finalmtx;
		struct coord centre;
		Mtxf zrotmtx;
		struct coord sp54;
		f32 xscale;
		f32 yscale;
		f32 zscale;
		struct modelrodata_bbox *bbox;

		bbox = modelFileDataFindBboxRodata(g_ModelStates[modelnum].filedata);

		mtx00016d58(&sp110, 0, 0, 0,
				-pad.look.x, -pad.look.y, -pad.look.z,
				pad.up.x, pad.up.y, pad.up.z);
		mtx4LoadXRotation(1.5705462694168f, &finalmtx);
		mtx4LoadZRotation(1.5705462694168f, &zrotmtx);
		mtx4MultMtx4InPlace(&zrotmtx, &finalmtx);
		mtx4MultMtx4InPlace(&sp110, &finalmtx);

		padGetCentre(door->base.pad, &centre);

		xscale = (pad.bbox.ymax - pad.bbox.ymin) / (bbox->xmax - bbox->xmin);
		yscale = (pad.bbox.zmax - pad.bbox.zmin) / (bbox->ymax - bbox->ymin);
		zscale = (pad.bbox.xmax - pad.bbox.xmin) / (bbox->zmax - bbox->zmin);

		if (xscale <= 0.000001f || yscale <= 0.000001f || zscale <= 0.000001f) {
			xscale = yscale = zscale = 1;
		}

		mtx00015e24(xscale, &finalmtx);
		mtx00015e80(yscale, &finalmtx);
		mtx00015edc(zscale, &finalmtx);

		pos.x = pad.pos.x;
		pos.y = pad.pos.y;
		pos.z = pad.pos.z;

		rooms[0] = pad.room;
		rooms[1] = -1;

		if (door->doortype == DOORTYPE_VERTICAL || door->doortype == DOORTYPE_FALLAWAY) {
			sp54.x = pad.look.f[0] * (pad.bbox.zmax - pad.bbox.zmin);
			sp54.y = pad.look.f[1] * (pad.bbox.zmax - pad.bbox.zmin);
			sp54.z = pad.look.f[2] * (pad.bbox.zmax - pad.bbox.zmin);
		} else {
			sp54.x = pad.up.f[0] * (pad.bbox.ymin - pad.bbox.ymax);
			sp54.y = pad.up.f[1] * (pad.bbox.ymin - pad.bbox.ymax);
			sp54.z = pad.up.f[2] * (pad.bbox.ymin - pad.bbox.ymax);
		}

		// These values are stored in the setup files as integers, but at
		// runtime they are floats. Hence reading a "float" as an integer,
		// converting it to a float and writing it back to the same property.
		door->maxfrac = *(s32 *) &door->maxfrac / 65536.0f;
		door->perimfrac = *(s32 *) &door->perimfrac / 65536.0f;
		door->accel = PALUPF(*(s32 *) &door->accel) / 65536000.0f;
		door->decel = PALUPF(*(s32 *) &door->decel) / 65536000.0f;
		door->maxspeed = PALUPF(*(s32 *) &door->maxspeed) / 65536.0f;

		// The sibling door is stored as a relative command number,
		// but at runtime it's a pointer.
		if (door->sibling) {
			siblingcmdindex = *(s32 *) &door->sibling + cmdindex;
			door->sibling = (struct doorobj *) setupGetCmdByIndex(siblingcmdindex);
		}

		prop = doorInit(door, &pos, &finalmtx, rooms, &sp54, &centre);

		if (door->base.flags & OBJFLAG_DOOR_HASPORTAL) {
			door->portalnum = portalnum;

			if (door->portalnum >= 0 && door->frac == 0) {
				doorDeactivatePortal(door);
			}
		}

		if (door->base.model) {
			scale = xscale;

			if (yscale > scale) {
				scale = yscale;
			}

			if (zscale > scale) {
				scale = zscale;
			}

			modelSetScale(door->base.model, door->base.model->scale * scale);
		}

		propActivate(prop);
		propEnable(prop);
	} else {
		door->base.prop = NULL;
	}
}

void setupCreateHov(struct defaultobj *obj, struct hov *hov)
{
	hov->unk04 = 0;
	hov->unk08 = 0;
	hov->unk0c = 0;
	hov->unk10 = atan2f(obj->realrot[2][0], obj->realrot[2][2]);
	hov->unk14 = 0;
	hov->unk18 = 0;
	hov->unk1c = 0;
	hov->unk20 = 0;
	hov->unk24 = 0;
	hov->unk28 = 0;
	hov->unk2c = 0;
	hov->unk30 = 0;
	hov->ground = 0;
	hov->nexttick60 = -1;
	hov->prevtick60 = -1;
}

void setupLoadBriefing(s32 stagenum, u8 *buffer, s32 bufferlen, struct briefing *briefing)
{
	if (stagenum < STAGE_TITLE) {
		s32 stageindex = stageGetIndex(stagenum);
		struct defaultobj *start;
		u16 setupfilenum;
		s32 setupfilesize;
		struct objective *objective;
		struct briefingobj *briefingobj;
		s32 i;
		u8 *langbuffer;
		s32 langbufferlen;
		struct stagesetup *setup;

		if (stageindex < 0) {
			stageindex = 0;
		}

		setupfilenum = g_Stages[stageindex].setupfileid;
		g_LoadType = LOADTYPE_LANG;

		fileLoadToAddr(setupfilenum, FILELOADMETHOD_DEFAULT, buffer, bufferlen);

		setup = (struct stagesetup *)buffer;
		setupfilesize = fileGetLoadedSize(setupfilenum);
		langbuffer = &buffer[setupfilesize];
		langbufferlen = bufferlen - setupfilesize;

		briefing->langbank = langGetLangBankIndexFromStagenum(stagenum);

		langLoadToAddr(briefing->langbank, langbuffer, langbufferlen);

		start = (struct defaultobj *)((u32)setup + (u32)setup->props);

		if (start != NULL) {
			struct defaultobj *obj;
			s32 wanttype = BRIEFINGTYPE_TEXT_PA;

			if (lvGetDifficulty() == DIFF_A) {
				wanttype = BRIEFINGTYPE_TEXT_A;
			}

			if (lvGetDifficulty() == DIFF_SA) {
				wanttype = BRIEFINGTYPE_TEXT_SA;
			}

			for (i = 0; (u32)(i < 6); i++) {
				briefing->objectivenames[i] = 0;
			}

			briefing->briefingtextnum = L_MISC_042; // "No briefing for this mission"

			obj = start;

			while (obj->type != OBJTYPE_END) {
				if (1);
				switch (obj->type) {
				case OBJTYPE_BRIEFING:
					briefingobj = (struct briefingobj *) obj;

					if (briefingobj->type == BRIEFINGTYPE_TEXT_PA) {
						briefing->briefingtextnum = briefingobj->text;
					}

					if (briefingobj->type == wanttype) {
						briefing->briefingtextnum = briefingobj->text;
					}
					break;
				case OBJTYPE_BEGINOBJECTIVE:
					objective = (struct objective *) obj;

					if (objective->index < 7U) {
						briefing->objectivenames[objective->index] = objective->text;
						briefing->objectivedifficulties[objective->index] = objective->difficulties;
					}
					break;
				}

				obj = (struct defaultobj *)((u32 *)obj + setupGetCmdLength((u32 *)obj));
			}
		}
	}
}

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

	g_PadEffects = NULL;
	g_LastPadEffectIndex = -1;

	g_DoorScale = 1;

	for (i = 0; i < NUM_MODELS; i++) {
		g_ModelStates[i].filedata = NULL;
	}

	if (stagenum < STAGE_TITLE) {
		if (g_Vars.normmplayerisrunning) {
			filenum = g_Stages[g_StageIndex].mpsetupfileid;
		} else {
			filenum = g_Stages[g_StageIndex].setupfileid;
		}

		g_LoadType = LOADTYPE_SETUP;

		g_GeCreditsData = (u8 *)fileLoadToNew(filenum, FILELOADMETHOD_DEFAULT);
		setup = (struct stagesetup *)g_GeCreditsData;
		langLoad(langGetLangBankIndexFromStagenum(stagenum));

		g_StageSetup.intro = (s32 *)((u32)setup + (u32)setup->intro);
		g_StageSetup.props = (u32 *)((u32)setup + (u32)setup->props);
		g_StageSetup.paths = (struct path *)((u32)setup + (u32)setup->paths);
		g_StageSetup.ailists = (struct ailist *)((u32)setup + (u32)setup->ailists);

		g_LoadType = LOADTYPE_PADS;

		g_StageSetup.padfiledata = fileLoadToNew(g_Stages[g_StageIndex].padsfileid, FILELOADMETHOD_DEFAULT);

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
		total += setupCountCommandType(OBJTYPE_GASBOTTLE);
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
			total += scenarioNumProps();
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

void setupCreateProps(s32 stagenum)
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
			setupPreparePads();
		}

		setupLoadWaypoints();

		if (withchrs) {
			s32 numchrs = 0;

			numchrs += setupCountCommandType(OBJTYPE_CHR);

			if (g_Vars.normmplayerisrunning == false
					&& g_MissionConfig.iscoop
					&& g_Vars.numaibuddies > 0) {
				numchrs += g_Vars.numaibuddies;
			}

			chrmgrConfigure(numchrs);
		} else {
			chrmgrConfigure(0);
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

			botmgrRemoveAll();
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
						bodyAllocateChr(stagenum, (struct packedchr *) obj, index);
					}
					break;
				case OBJTYPE_DOOR:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupCreateDoor((struct doorobj *)obj, index);
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
						setupPlaceWeapon((struct weaponobj *)obj, index);
					}
					break;
				case OBJTYPE_KEY:
					if (withchrs && (obj->flags2 & diffflag) == 0) {
						setupCreateKey((struct keyobj *)obj, index);
					}
					break;
				case OBJTYPE_HAT:
					if (withchrs && (obj->flags2 & diffflag) == 0) {
						setupCreateHat((struct hatobj *)obj, index);
					}
					break;
				case OBJTYPE_CCTV:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupCreateCctv((struct cctvobj *)obj, index);
					}
					break;
				case OBJTYPE_AUTOGUN:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupCreateAutogun((struct autogunobj *)obj, index);
					}
					break;
				case OBJTYPE_HANGINGMONITORS:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupCreateHangingMonitors((struct hangingmonitorsobj *)obj, index);
					}
					break;
				case OBJTYPE_SINGLEMONITOR:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupCreateSingleMonitor((struct singlemonitorobj *)obj, index);
					}
					break;
				case OBJTYPE_MULTIMONITOR:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupCreateMultiMonitor((struct multimonitorobj *)obj, index);
					}
					break;
				case OBJTYPE_SHIELD:
					if (withobjs) {
#if VERSION >= VERSION_JPN_FINAL
						if ((obj->flags2 & diffflag) == 0)
#else
						if ((obj->flags2 & diffflag) == 0 || g_Jpn)
#endif
						{
							struct shieldobj *shield = (struct shieldobj *)obj;
							shield->initialamount = *(s32 *)&shield->initialamount / 65536.0f;
							shield->amount = shield->initialamount;
							setupCreateObject(obj, index);
						}
					}
					break;
				case OBJTYPE_TINTEDGLASS:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						if (obj->flags & OBJFLAG_GLASS_HASPORTAL) {
							struct tintedglassobj *glass = (struct tintedglassobj *)obj;
							glass->portalnum = setupGetPortalByPad(obj->pad);
							glass->unk64 = *(s32 *)&glass->unk64 / 65536.0f;
						}

						setupCreateObject(obj, index);
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
								lift->doors[i] = (struct doorobj *)setupGetCmdByIndex(index + *(s32*)&lift->doors[i]);
							}
						}

						obj->geocount = 1;
						setupLoadModeldef(modelnum);
						modelstate = &g_ModelStates[modelnum];

						if (modelstate->filedata) {
							if (modelGetPartRodata(modelstate->filedata, 1)) {
								obj->geocount++;
							}
							if (modelGetPartRodata(modelstate->filedata, 2)) {
								obj->geocount++;
							}
							if (modelGetPartRodata(modelstate->filedata, 3)) {
								obj->geocount++;
							}
							if (modelGetPartRodata(modelstate->filedata, 4)) {
								obj->geocount++;
							}
							if (modelGetPartRodata(modelstate->filedata, 6)) {
								obj->geocount++;
							}
						}

						obj->flags &= ~OBJFLAG_00000100;

						setupCreateObject(obj, index);

						prop = obj->prop;

						if (prop) {
							lift->prevpos.x = prop->pos.x;
							lift->prevpos.y = prop->pos.y;
							lift->prevpos.z = prop->pos.z;

							liftUpdateTiles(lift, true);
						}
					}
					break;
				case OBJTYPE_HOVERPROP:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct hoverpropobj *hoverprop = (struct hoverpropobj *)obj;

						setupCreateObject(obj, index);
						setupCreateHov(obj, &hoverprop->hov);
					}
					break;
				case OBJTYPE_HOVERBIKE:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct hoverbikeobj *bike = (struct hoverbikeobj *)obj;

						setupCreateObject(obj, index);
						setupCreateHov(obj, &bike->hov);

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

						setupCreateObject(obj, index);
					}
					break;
				case OBJTYPE_GLASS:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						if (obj->flags & OBJFLAG_GLASS_HASPORTAL) {
							struct glassobj *glass = (struct glassobj *)obj;
							glass->portalnum = setupGetPortalByPad(obj->pad);
						}

						setupCreateObject(obj, index);
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
						f32 sp184[3][3];

						setupCreateObject(obj, index);

						prop = obj->prop;

						if (prop) {
							step->prevpos.x = prop->pos.x;
							step->prevpos.y = prop->pos.y;
							step->prevpos.z = prop->pos.z;
						}

						if (obj->flags & OBJFLAG_ESCSTEP_ZALIGNED) {
							step->frame = escstepy;
							escstepy += 40;
							mtx4LoadYRotation(4.7116389274597f, (Mtxf *)sp1a8);
							mtx4ToMtx3((Mtxf *)sp1a8, sp184);
							mtx00016110(sp184, obj->realrot);
						} else {
							step->frame = escstepx;
							escstepx += 40;
							mtx4LoadYRotation(M_BADPI, (Mtxf *)sp1a8);
							mtx4ToMtx3((Mtxf *)sp1a8, sp184);
							mtx00016110(sp184, obj->realrot);
						}
					}
					break;
				case OBJTYPE_BASIC:
				case OBJTYPE_ALARM:
				case OBJTYPE_AMMOCRATE:
				case OBJTYPE_DEBRIS:
				case OBJTYPE_GASBOTTLE:
				case OBJTYPE_29:
				case OBJTYPE_SAFE:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupCreateObject(obj, index);
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
									setupLoadModeldef(crate->slots[i].modelnum);
								}
							}

							setupCreateObject(obj, index);
						}
					}
					break;
				case OBJTYPE_TRUCK:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct truckobj *truck = (struct truckobj *)obj;

						setupCreateObject(obj, index);

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

						setupCreateObject(obj, index);

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
							prop->pos.y = cd0002a36c(&prop->pos, prop->rooms, NULL, 0) + 30;
						}

						prop->forcetick = true;
					}
					break;
				case OBJTYPE_CHOPPER:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						struct chopperobj *chopper = (struct chopperobj *)obj;

						setupCreateObject(obj, index);

						obj->flags |= OBJFLAG_20000000;
						obj->prop->forcetick = true;

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
						chopper->attackmode = CHOPPERMODE_PATROL;
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
						chopper->fireslotthing = mempAlloc(sizeof(struct fireslotthing), MEMPOOL_STAGE);
						chopper->fireslotthing->beam = mempAlloc(ALIGN16(sizeof(struct beam)), MEMPOOL_STAGE);
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

						setupCreateObject(obj, index);

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
						struct defaultobj *taggedobj = setupGetObjByCmdIndex(index + tag->cmdoffset);
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
						struct defaultobj *targetobj = setupGetObjByCmdIndex(override->objoffset + index);
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
				case OBJECTIVETYPE_THROWINROOM:
					objectiveAddThrowInRoomCriteria((struct criteria_throwinroom *)obj);
					break;
				case OBJECTIVETYPE_HOLOGRAPH:
					objectiveAddHolographCriteria((struct criteria_holograph *)obj);
					break;
				case OBJTYPE_PADEFFECT:
					{
						struct padeffectobj *padeffect = (struct padeffectobj *)obj;
						if (g_LastPadEffectIndex == -1) {
							g_PadEffects = padeffect;
						}
						g_LastPadEffectIndex++;
					}
					break;
				case OBJTYPE_MINE:
					if (withobjs && (obj->flags2 & diffflag) == 0) {
						setupCreateMine((struct mineobj *)obj, index);
					}
					break;
				}

				obj = (struct defaultobj *)((u32 *)obj + setupGetCmdLength((u32 *)obj));
				index++;
			}

			index = 0;

			if (g_Vars.normmplayerisrunning && mpHasSimulants()) {
				u32 stack[4];
				s32 i;
				s32 slotsdone[MAX_BOTS];
				s32 chrnum = 0;
				s32 maxsimulants;
				s32 slotnum;

				if (challengeIsFeatureUnlocked(MPFEATURE_8BOTS)) {
					maxsimulants = MAX_BOTS;
				} else {
					maxsimulants = 4;
				}

				for (i = 0; i < MAX_BOTS; i++) {
					slotsdone[i] = false;
				}

				for (i = 0; i < maxsimulants; i++) {
					slotnum = random() % maxsimulants;

					while (slotsdone[slotnum]) {
						slotnum = (slotnum + 1) % maxsimulants;
					}

					if ((g_MpSetup.chrslots & (1 << (slotnum + 4)))
							&& mpIsSimSlotEnabled(slotnum)) {
						botmgrAllocateBot(chrnum, slotnum);
						chrnum++;
					}

					slotsdone[slotnum] = true;
				}
			}

			if (g_Vars.normmplayerisrunning) {
				scenarioInitProps();
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
				case OBJTYPE_GASBOTTLE:
				case OBJTYPE_29:
				case OBJTYPE_GLASS:
				case OBJTYPE_SAFE:
				case OBJTYPE_TINTEDGLASS:
					if (obj->prop && (obj->flags & OBJFLAG_INSIDEANOTHEROBJ)) {
						s32 offset = obj->pad;
						struct defaultobj *owner = setupGetObjByCmdIndex(index + offset);

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
						struct weaponobj *gun1 = (struct weaponobj *)setupGetCmdByIndex(link->offset1 + index);
						struct weaponobj *gun2 = (struct weaponobj *)setupGetCmdByIndex(link->offset2 + index);

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
						struct defaultobj *door = setupGetObjByCmdIndex(index + dooroffset);
						struct defaultobj *lift = setupGetObjByCmdIndex(index + liftoffset);

						if (door && door->prop && lift && lift->prop) {
							link->door = door->prop;
							link->lift = lift->prop;

							setupCreateLiftDoor(link);

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
						struct defaultobj *item = setupGetObjByCmdIndex(index + itemoffset);
						struct defaultobj *safe = setupGetObjByCmdIndex(index + safeoffset);
						struct defaultobj *door = setupGetObjByCmdIndex(index + dooroffset);

						if (item && item->prop
								&& safe && safe->prop && safe->type == OBJTYPE_SAFE
								&& door && door->prop && door->type == OBJTYPE_DOOR) {
							link->item = item;
							link->safe = (struct safeobj *)safe;
							link->door = (struct doorobj *)door;

							setupCreateSafeItem(link);

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
						struct defaultobj *door = setupGetObjByCmdIndex(index + dooroffset);
						struct defaultobj *lock = setupGetObjByCmdIndex(index + lockoffset);

						if (door && door->prop && lock && lock->prop
								&& door->type == OBJTYPE_DOOR) {
							link->door = (struct doorobj *)door;
							link->lock = lock;

							setupCreatePadlockedDoor(link);

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
						struct defaultobj *trigger = setupGetObjByCmdIndex(index + triggeroffset);
						struct defaultobj *unexp = NULL;
						struct defaultobj *exp = NULL;
						s32 alwayszero = 0;

						if (unexpoffset) {
							unexp = setupGetObjByCmdIndex(index + unexpoffset);
						}

						if (expoffset) {
							exp = setupGetObjByCmdIndex(index + expoffset);
						}

						if (trigger && trigger->prop
								&& (unexpoffset == 0 || (unexp && unexp->prop))
								&& (expoffset == 0 || (exp && exp->prop))) {
							link->trigger = trigger;
							link->unexp = unexp;
							link->exp = exp;

							setupCreateConditionalScenery(link);

							trigger->hidden |= OBJHFLAG_CONDITIONALSCENERY;

							if (unexpoffset) {
								unexp->hidden |= OBJHFLAG_CONDITIONALSCENERY;
							}

							// This gets optimised out but makes v0 unavailable
							// for storing OBJHFLAG_CONDITIONALSCENERY, which is required
							// for a match. Any function call would work; I just
							// copied the one above.
							if (alwayszero) {
								setupCreateConditionalScenery(link);
							}

							if (expoffset) {
								exp->hidden |= OBJHFLAG_CONDITIONALSCENERY;
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
						struct defaultobj *blocker = setupGetObjByCmdIndex(index + objoffset);

						if (blocker && blocker->prop) {
							blockedpath->blocker = blocker;

							setupCreateBlockedPath(blockedpath);

							blocker->hidden |= OBJHFLAG_02000000;

							if (blocker->hidden & OBJHFLAG_CONDITIONALSCENERY) {
								objSetBlockedPathUnblocked(blocker, false);
							}
						}
					}
					break;
				}

				obj = (struct defaultobj *)((u32 *)obj + setupGetCmdLength((u32 *)obj));
				index++;
			}
		}
	} else {
		chrmgrConfigure(0);
	}

	stageAllocateBgChrs();
}
