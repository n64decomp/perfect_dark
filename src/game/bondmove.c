#include <ultra64.h>
#include "constants.h"
#include "game/bondbike.h"
#include "game/bondgrab.h"
#include "game/bondmove.h"
#include "game/bondwalk.h"
#include "game/cheats.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_005fd0.h"
#include "game/game_01e250.h"
#include "game/game_0601b0.h"
#include "game/game_096750.h"
#include "game/game_096ca0.h"
#include "game/game_097ba0.h"
#include "game/game_0b0420.h"
#include "game/game_0b3350.h"
#include "game/game_0b63b0.h"
#include "game/game_0c3620.h"
#include "game/game_0fd660.h"
#include "game/game_113220.h"
#include "game/game_127910.h"
#include "game/game_157db0.h"
#include "game/game_167ae0.h"
#include "game/game_177e00.h"
#include "game/mplayer.h"
#include "game/pdoptions.h"
#include "game/propobj.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_13900.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "lib/lib_4a360.h"
#include "types.h"

const char var7f1ad860[] = "bondmove.c";

GLOBAL_ASM(
glabel func0f0c79f0
/*  f0c79f0:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0c79f4:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0c79f8:	03e00008 */ 	jr	$ra
/*  f0c79fc:	adc40334 */ 	sw	$a0,0x334($t6)
);

GLOBAL_ASM(
glabel func0f0c7a00
/*  f0c7a00:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0c7a04:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0c7a08:	03e00008 */ 	jr	$ra
/*  f0c7a0c:	adc40114 */ 	sw	$a0,0x114($t6)
/*  f0c7a10:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0c7a14:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0c7a18:	03e00008 */ 	jr	$ra
/*  f0c7a1c:	8dc20114 */ 	lw	$v0,0x114($t6)
);

void currentPlayerSetAutoAimY(bool enabled)
{
	g_Vars.currentplayer->autoyaimenabled = enabled;
}

bool currentPlayerIsAutoAimYEnabled(void)
{
	if (!g_Vars.normmplayerisrunning) {
		return g_Vars.currentplayer->autoyaimenabled;
	}

	if (g_MpSetup.options & MPOPTION_NOAUTOAIM) {
		return false;
	}

	return optionsGetAutoAim(g_Vars.currentplayerstats->mpindex);
}

GLOBAL_ASM(
glabel func0f0c7a8c
/*  f0c7a8c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0c7a90:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0c7a94:	0fc2c43b */ 	jal	func0f0b10ec
/*  f0c7a98:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c7a9c:	1040000e */ 	beqz	$v0,.L0f0c7ad8
/*  f0c7aa0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7aa4:	8c4e0010 */ 	lw	$t6,0x10($v0)
/*  f0c7aa8:	31cf0040 */ 	andi	$t7,$t6,0x40
/*  f0c7aac:	51e00004 */ 	beqzl	$t7,.L0f0c7ac0
/*  f0c7ab0:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f0c7ab4:	1000000a */ 	beqz	$zero,.L0f0c7ae0
/*  f0c7ab8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c7abc:	8c580000 */ 	lw	$t8,0x0($v0)
.L0f0c7ac0:
/*  f0c7ac0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c7ac4:	331900ff */ 	andi	$t9,$t8,0xff
/*  f0c7ac8:	17210003 */ 	bne	$t9,$at,.L0f0c7ad8
/*  f0c7acc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7ad0:	10000003 */ 	beqz	$zero,.L0f0c7ae0
/*  f0c7ad4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0c7ad8:
/*  f0c7ad8:	0fc31e8c */ 	jal	currentPlayerIsAutoAimYEnabled
/*  f0c7adc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0c7ae0:
/*  f0c7ae0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c7ae4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0c7ae8:	03e00008 */ 	jr	$ra
/*  f0c7aec:	00000000 */ 	sll	$zero,$zero,0x0
);

bool currentPlayerIsInSightAimMode(void)
{
	return g_Vars.currentplayer->insightaimmode;
}

void currentPlayerUpdateAutoAimYProp(struct prop *prop, f32 autoaimy)
{
	if (g_Vars.currentplayer->autoyaimtime60 >= 0) {
		g_Vars.currentplayer->autoyaimtime60 -= g_Vars.lvupdate240_60;
	}

	if (prop != g_Vars.currentplayer->autoyaimprop) {
		if (g_Vars.currentplayer->autoyaimtime60 < 0) {
			g_Vars.currentplayer->autoyaimtime60 = 30;
			g_Vars.currentplayer->autoyaimprop = prop;
		} else {
			return;
		}
	}

	g_Vars.currentplayer->autoaimy = autoaimy;
}

void currentPlayerSetAutoAimX(bool enabled)
{
	g_Vars.currentplayer->autoxaimenabled = enabled;
}

bool currentPlayerIsAutoAimXEnabled(void)
{
	if (!g_Vars.normmplayerisrunning) {
		return g_Vars.currentplayer->autoxaimenabled;
	}

	if (g_MpSetup.options & MPOPTION_NOAUTOAIM) {
		return false;
	}

	return optionsGetAutoAim(g_Vars.currentplayerstats->mpindex);
}

GLOBAL_ASM(
glabel func0f0c7bd0
/*  f0c7bd0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0c7bd4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0c7bd8:	0fc2c43b */ 	jal	func0f0b10ec
/*  f0c7bdc:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c7be0:	1040000e */ 	beqz	$v0,.L0f0c7c1c
/*  f0c7be4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7be8:	8c4e0010 */ 	lw	$t6,0x10($v0)
/*  f0c7bec:	31cf0040 */ 	andi	$t7,$t6,0x40
/*  f0c7bf0:	51e00004 */ 	beqzl	$t7,.L0f0c7c04
/*  f0c7bf4:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f0c7bf8:	1000000a */ 	beqz	$zero,.L0f0c7c24
/*  f0c7bfc:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c7c00:	8c580000 */ 	lw	$t8,0x0($v0)
.L0f0c7c04:
/*  f0c7c04:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c7c08:	331900ff */ 	andi	$t9,$t8,0xff
/*  f0c7c0c:	17210003 */ 	bne	$t9,$at,.L0f0c7c1c
/*  f0c7c10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7c14:	10000003 */ 	beqz	$zero,.L0f0c7c24
/*  f0c7c18:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0c7c1c:
/*  f0c7c1c:	0fc31edd */ 	jal	currentPlayerIsAutoAimXEnabled
/*  f0c7c20:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0c7c24:
/*  f0c7c24:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c7c28:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0c7c2c:	03e00008 */ 	jr	$ra
/*  f0c7c30:	00000000 */ 	sll	$zero,$zero,0x0
);

void currentPlayerUpdateAutoAimXProp(struct prop *prop, f32 autoaimx)
{
	if (g_Vars.currentplayer->autoxaimtime60 >= 0) {
		g_Vars.currentplayer->autoxaimtime60 -= g_Vars.lvupdate240_60;
	}

	if (prop != g_Vars.currentplayer->autoxaimprop) {
		if (g_Vars.currentplayer->autoxaimtime60 < 0) {
			g_Vars.currentplayer->autoxaimtime60 = 30;
			g_Vars.currentplayer->autoxaimprop = prop;
		} else {
			return;
		}
	}

	g_Vars.currentplayer->autoaimx = autoaimx;
}

struct prop *currentPlayerGetHoverbike(void)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		return g_Vars.currentplayer->hoverbike;
	}

	return NULL;
}

struct prop *currentPlayerGetGrabbedProp(void)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
		return g_Vars.currentplayer->grabbedprop;
	}

	return NULL;
}

void currentPlayerGrabProp(struct prop *prop)
{
	struct defaultobj *obj = prop->obj;

	if ((obj->hidden & OBJHFLAG_04000000) == 0 && (obj->hidden & OBJHFLAG_GRABBED) == 0) {
		g_Vars.currentplayer->grabbedprop = prop;
		currentPlayerGrabInit();
	}
}

void currentPlayerSetMoveMode(u32 movemode)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
		currentPlayerUpdateGrabbedPropForRelease();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		func0f0d2184();
	}

	if (movemode == MOVEMODE_BIKE) {
		currentPlayerBikeInit();
	} else if (movemode == MOVEMODE_GRAB) {
		currentPlayerGrabInit();
	} else if (movemode == MOVEMODE_CUTSCENE) {
		currentPlayerSetMoveModeCutscene();
	} else if (movemode == MOVEMODE_WALK) {
		currentPlayerWalkInit();
	}
}

void setMoveModeForAllPlayers(u32 movemode)
{
	u32 prevplayernum = g_Vars.currentplayernum;
	s32 i;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		setCurrentPlayerNum(i);
		currentPlayerSetMoveMode(movemode);
	}

	setCurrentPlayerNum(prevplayernum);
}

void func0f0c7f2c(void)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		func0f0d2558();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
		func0f0ce450();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
		func0f0c65a8();
	}
}

void func0f0c7f98(void)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		func0f0d26ac();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
		func0f0ce608();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
		func0f0c65c8();
	}
}

void func0f0c8004(void)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		// empty
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
		currentPlayerUpdateSpeedThetaGrab();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
		currentPlayerApplyCrouchSpeedTheta();
	}
}

f32 func0f0c805c(f32 value)
{
	if (value > 0) {
		return (func0000be74() * value * -0.7f) / 60.0f;
	}

	if (value < 0) {
		return (func0000be74() * -value * 0.7f) / 60.0f;
	}

	return 0;
}

void currentPlayerUpdateSpeedVerta(f32 value)
{
	f32 mult = func0000be74() / 60.0f;
	f32 limit = func0f0c805c(value);

	if (value > 0) {
		if (g_Vars.currentplayer->speedverta > 0) {
			g_Vars.currentplayer->speedverta -= 0.05f * g_Vars.lvupdate240freal * mult;
		} else {
			g_Vars.currentplayer->speedverta -= 0.0125f * g_Vars.lvupdate240freal * mult;
		}

		if (g_Vars.currentplayer->speedverta < limit) {
			g_Vars.currentplayer->speedverta = limit;
		}
	} else if (value < 0) {
		if (g_Vars.currentplayer->speedverta < 0) {
			g_Vars.currentplayer->speedverta += 0.05f * g_Vars.lvupdate240freal * mult;
		} else {
			g_Vars.currentplayer->speedverta += 0.0125f * g_Vars.lvupdate240freal * mult;
		}

		if (g_Vars.currentplayer->speedverta > limit) {
			g_Vars.currentplayer->speedverta = limit;
		}
	} else {
		if (g_Vars.currentplayer->speedverta > limit) {
			g_Vars.currentplayer->speedverta -= 0.05f * g_Vars.lvupdate240freal * mult;

			if (g_Vars.currentplayer->speedverta < limit) {
				g_Vars.currentplayer->speedverta = limit;
			}
		} else {
			g_Vars.currentplayer->speedverta += 0.05f * g_Vars.lvupdate240freal * mult;

			if (g_Vars.currentplayer->speedverta > limit) {
				g_Vars.currentplayer->speedverta = limit;
			}
		}
	}
}

f32 func0f0c82f8(f32 value)
{
	if (value > 0) {
		return (func0000be74() * value * -0.7f) / 60.0f;
	}

	if (value < 0) {
		return (func0000be74() * -value * 0.7f) / 60.0f;
	}

	return 0;
}

void currentPlayerUpdateSpeedThetaControl(f32 value)
{
	f32 mult = func0000be74() / 60.0f;
	f32 limit = func0f0c82f8(value);

	if (value > 0) {
		if (g_Vars.currentplayer->speedthetacontrol > 0) {
			g_Vars.currentplayer->speedthetacontrol -= 0.05f * g_Vars.lvupdate240freal * mult;
		} else {
			g_Vars.currentplayer->speedthetacontrol -= 0.0125f * g_Vars.lvupdate240freal * mult;
		}

		if (g_Vars.currentplayer->speedthetacontrol < limit) {
			g_Vars.currentplayer->speedthetacontrol = limit;
		}
	} else if (value < 0) {
		if (g_Vars.currentplayer->speedthetacontrol < 0.0f) {
			g_Vars.currentplayer->speedthetacontrol += 0.05f * g_Vars.lvupdate240freal * mult;
		} else {
			g_Vars.currentplayer->speedthetacontrol += 0.0125f * g_Vars.lvupdate240freal * mult;
		}

		if (g_Vars.currentplayer->speedthetacontrol > limit) {
			g_Vars.currentplayer->speedthetacontrol = limit;
		}
	} else {
		if (g_Vars.currentplayer->speedthetacontrol > limit) {
			g_Vars.currentplayer->speedthetacontrol -= 0.05f * g_Vars.lvupdate240freal * mult;

			if (g_Vars.currentplayer->speedthetacontrol < limit) {
				g_Vars.currentplayer->speedthetacontrol = limit;
			}
		} else {
			g_Vars.currentplayer->speedthetacontrol += 0.05f * g_Vars.lvupdate240freal * mult;

			if (g_Vars.currentplayer->speedthetacontrol > limit) {
				g_Vars.currentplayer->speedthetacontrol = limit;
			}
		}
	}
}

GLOBAL_ASM(
glabel func0f0c8598
.late_rodata
glabel var7f1ad8ac
.word 0x3e4ccccd
glabel var7f1ad8b0
.word 0x40c907a9
glabel var7f1ad8b4
.word 0x3f5dddde
.text
/*  f0c8598:	27bdfe98 */ 	addiu	$sp,$sp,-360
/*  f0c859c:	3c01c080 */ 	lui	$at,0xc080
/*  f0c85a0:	44811000 */ 	mtc1	$at,$f2
/*  f0c85a4:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0c85a8:	3c0143c8 */ 	lui	$at,0x43c8
/*  f0c85ac:	44812000 */ 	mtc1	$at,$f4
/*  f0c85b0:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f0c85b4:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f0c85b8:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f0c85bc:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f0c85c0:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f0c85c4:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f0c85c8:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f0c85cc:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f0c85d0:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f0c85d4:	f7b80030 */ 	sdc1	$f24,0x30($sp)
/*  f0c85d8:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f0c85dc:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f0c85e0:	e7a20164 */ 	swc1	$f2,0x164($sp)
/*  f0c85e4:	e7a40160 */ 	swc1	$f4,0x160($sp)
/*  f0c85e8:	8e0e02b0 */ 	lw	$t6,0x2b0($s0)
/*  f0c85ec:	0000b025 */ 	or	$s6,$zero,$zero
/*  f0c85f0:	00008825 */ 	or	$s1,$zero,$zero
/*  f0c85f4:	11c00003 */ 	beqz	$t6,.L0f0c8604
/*  f0c85f8:	c6180078 */ 	lwc1	$f24,0x78($s0)
/*  f0c85fc:	1000011d */ 	beqz	$zero,.L0f0c8a74
/*  f0c8600:	46001006 */ 	mov.s	$f0,$f2
.L0f0c8604:
/*  f0c8604:	8e0400bc */ 	lw	$a0,0xbc($s0)
/*  f0c8608:	27a50144 */ 	addiu	$a1,$sp,0x144
/*  f0c860c:	27a6014c */ 	addiu	$a2,$sp,0x14c
/*  f0c8610:	0fc3082e */ 	jal	propPlayerGetBbox
/*  f0c8614:	27a70148 */ 	addiu	$a3,$sp,0x148
/*  f0c8618:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f0c861c:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f0c8620:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0c8624:	44812000 */ 	mtc1	$at,$f4
/*  f0c8628:	c606036c */ 	lwc1	$f6,0x36c($s0)
/*  f0c862c:	27a500f0 */ 	addiu	$a1,$sp,0xf0
/*  f0c8630:	27a700e0 */ 	addiu	$a3,$sp,0xe0
/*  f0c8634:	e7a60100 */ 	swc1	$f6,0x100($sp)
/*  f0c8638:	c6080370 */ 	lwc1	$f8,0x370($s0)
/*  f0c863c:	e7a80104 */ 	swc1	$f8,0x104($sp)
/*  f0c8640:	c60a0374 */ 	lwc1	$f10,0x374($s0)
/*  f0c8644:	e7aa0108 */ 	swc1	$f10,0x108($sp)
/*  f0c8648:	8e0f00bc */ 	lw	$t7,0xbc($s0)
/*  f0c864c:	c5f00008 */ 	lwc1	$f16,0x8($t7)
/*  f0c8650:	e7b000f0 */ 	swc1	$f16,0xf0($sp)
/*  f0c8654:	8e1800bc */ 	lw	$t8,0xbc($s0)
/*  f0c8658:	c712000c */ 	lwc1	$f18,0xc($t8)
/*  f0c865c:	46049181 */ 	sub.s	$f6,$f18,$f4
/*  f0c8660:	e7a600f4 */ 	swc1	$f6,0xf4($sp)
/*  f0c8664:	8e1900bc */ 	lw	$t9,0xbc($s0)
/*  f0c8668:	c7280010 */ 	lwc1	$f8,0x10($t9)
/*  f0c866c:	e7a800f8 */ 	swc1	$f8,0xf8($sp)
/*  f0c8670:	8e0200bc */ 	lw	$v0,0xbc($s0)
/*  f0c8674:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0c8678:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0c867c:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0c8680:	0c006052 */ 	jal	func00018148
/*  f0c8684:	24460028 */ 	addiu	$a2,$v0,0x28
/*  f0c8688:	3c0143c8 */ 	lui	$at,0x43c8
/*  f0c868c:	44810000 */ 	mtc1	$at,$f0
/*  f0c8690:	c7aa0100 */ 	lwc1	$f10,0x100($sp)
/*  f0c8694:	c7b200f0 */ 	lwc1	$f18,0xf0($sp)
/*  f0c8698:	c7a60104 */ 	lwc1	$f6,0x104($sp)
/*  f0c869c:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0c86a0:	c7aa00f4 */ 	lwc1	$f10,0xf4($sp)
/*  f0c86a4:	27b00150 */ 	addiu	$s0,$sp,0x150
/*  f0c86a8:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0c86ac:	c7a600f8 */ 	lwc1	$f6,0xf8($sp)
/*  f0c86b0:	240b000f */ 	addiu	$t3,$zero,0xf
/*  f0c86b4:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0c86b8:	02003025 */ 	or	$a2,$s0,$zero
/*  f0c86bc:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f0c86c0:	c7b20108 */ 	lwc1	$f18,0x108($sp)
/*  f0c86c4:	27a400f0 */ 	addiu	$a0,$sp,0xf0
/*  f0c86c8:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f0c86cc:	e7a40150 */ 	swc1	$f4,0x150($sp)
/*  f0c86d0:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0c86d4:	27a500e0 */ 	addiu	$a1,$sp,0xe0
/*  f0c86d8:	e7b00154 */ 	swc1	$f16,0x154($sp)
/*  f0c86dc:	24071020 */ 	addiu	$a3,$zero,0x1020
/*  f0c86e0:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0c86e4:	0c00b764 */ 	jal	func0002dd90
/*  f0c86e8:	e7a80158 */ 	swc1	$f8,0x158($sp)
/*  f0c86ec:	14400018 */ 	bnez	$v0,.L0f0c8750
/*  f0c86f0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c86f4:	3c067f1b */ 	lui	$a2,%hi(var7f1ad860)
/*  f0c86f8:	24c6d860 */ 	addiu	$a2,$a2,%lo(var7f1ad860)
/*  f0c86fc:	0c0093af */ 	jal	func00024ebc
/*  f0c8700:	240501c7 */ 	addiu	$a1,$zero,0x1c7
/*  f0c8704:	0c0093c4 */ 	jal	func00024f10
/*  f0c8708:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c870c:	c7aa0150 */ 	lwc1	$f10,0x150($sp)
/*  f0c8710:	c7b000f0 */ 	lwc1	$f16,0xf0($sp)
/*  f0c8714:	c7b20154 */ 	lwc1	$f18,0x154($sp)
/*  f0c8718:	c7a400f4 */ 	lwc1	$f4,0xf4($sp)
/*  f0c871c:	46105001 */ 	sub.s	$f0,$f10,$f16
/*  f0c8720:	c7a60158 */ 	lwc1	$f6,0x158($sp)
/*  f0c8724:	c7a800f8 */ 	lwc1	$f8,0xf8($sp)
/*  f0c8728:	46049081 */ 	sub.s	$f2,$f18,$f4
/*  f0c872c:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f0c8730:	3051ffff */ 	andi	$s1,$v0,0xffff
/*  f0c8734:	46083381 */ 	sub.s	$f14,$f6,$f8
/*  f0c8738:	46021402 */ 	mul.s	$f16,$f2,$f2
/*  f0c873c:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f0c8740:	460e7102 */ 	mul.s	$f4,$f14,$f14
/*  f0c8744:	0c012974 */ 	jal	sqrtf
/*  f0c8748:	46049300 */ 	add.s	$f12,$f18,$f4
/*  f0c874c:	e7a00160 */ 	swc1	$f0,0x160($sp)
.L0f0c8750:
/*  f0c8750:	3c014270 */ 	lui	$at,0x4270
/*  f0c8754:	c7a20160 */ 	lwc1	$f2,0x160($sp)
/*  f0c8758:	44813000 */ 	mtc1	$at,$f6
/*  f0c875c:	322c0001 */ 	andi	$t4,$s1,0x1
/*  f0c8760:	00008825 */ 	or	$s1,$zero,$zero
/*  f0c8764:	4602303c */ 	c.lt.s	$f6,$f2
/*  f0c8768:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0c876c:	00004025 */ 	or	$t0,$zero,$zero
/*  f0c8770:	27b00118 */ 	addiu	$s0,$sp,0x118
/*  f0c8774:	45010003 */ 	bc1t	.L0f0c8784
/*  f0c8778:	27b50080 */ 	addiu	$s5,$sp,0x80
/*  f0c877c:	518000b3 */ 	beqzl	$t4,.L0f0c8a4c
/*  f0c8780:	c7a20164 */ 	lwc1	$f2,0x164($sp)
.L0f0c8784:
/*  f0c8784:	4481b000 */ 	mtc1	$at,$f22
/*  f0c8788:	e7a20160 */ 	swc1	$f2,0x160($sp)
/*  f0c878c:	27b400a0 */ 	addiu	$s4,$sp,0xa0
/*  f0c8790:	27b300bc */ 	addiu	$s3,$sp,0xbc
.L0f0c8794:
/*  f0c8794:	25120001 */ 	addiu	$s2,$t0,0x1
/*  f0c8798:	44924000 */ 	mtc1	$s2,$f8
/*  f0c879c:	c7a20160 */ 	lwc1	$f2,0x160($sp)
/*  f0c87a0:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f0c87a4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0c87a8:	3c017f1b */ 	lui	$at,%hi(var7f1ad8ac)
/*  f0c87ac:	c432d8ac */ 	lwc1	$f18,%lo(var7f1ad8ac)($at)
/*  f0c87b0:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*  f0c87b4:	c7a800f0 */ 	lwc1	$f8,0xf0($sp)
/*  f0c87b8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0c87bc:	46025402 */ 	mul.s	$f16,$f10,$f2
/*  f0c87c0:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0c87c4:	27a400f0 */ 	addiu	$a0,$sp,0xf0
/*  f0c87c8:	02602825 */ 	or	$a1,$s3,$zero
/*  f0c87cc:	27a600e0 */ 	addiu	$a2,$sp,0xe0
/*  f0c87d0:	02803825 */ 	or	$a3,$s4,$zero
/*  f0c87d4:	46128502 */ 	mul.s	$f20,$f16,$f18
/*  f0c87d8:	c7b00104 */ 	lwc1	$f16,0x104($sp)
/*  f0c87dc:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f0c87e0:	c7a400f4 */ 	lwc1	$f4,0xf4($sp)
/*  f0c87e4:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f0c87e8:	c7b000f8 */ 	lwc1	$f16,0xf8($sp)
/*  f0c87ec:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0c87f0:	c7a80108 */ 	lwc1	$f8,0x108($sp)
/*  f0c87f4:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f0c87f8:	e7aa00bc */ 	swc1	$f10,0xbc($sp)
/*  f0c87fc:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f0c8800:	e7a600c0 */ 	swc1	$f6,0xc0($sp)
/*  f0c8804:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f0c8808:	0c006052 */ 	jal	func00018148
/*  f0c880c:	e7b200c4 */ 	swc1	$f18,0xc4($sp)
/*  f0c8810:	3c0143c8 */ 	lui	$at,0x43c8
/*  f0c8814:	44814000 */ 	mtc1	$at,$f8
/*  f0c8818:	c7a600c0 */ 	lwc1	$f6,0xc0($sp)
/*  f0c881c:	c7a400bc */ 	lwc1	$f4,0xbc($sp)
/*  f0c8820:	c7b000c4 */ 	lwc1	$f16,0xc4($sp)
/*  f0c8824:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0c8828:	240d0007 */ 	addiu	$t5,$zero,0x7
/*  f0c882c:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0c8830:	02602025 */ 	or	$a0,$s3,$zero
/*  f0c8834:	e7aa00b4 */ 	swc1	$f10,0xb4($sp)
/*  f0c8838:	27a500b0 */ 	addiu	$a1,$sp,0xb0
/*  f0c883c:	02803025 */ 	or	$a2,$s4,$zero
/*  f0c8840:	27a70090 */ 	addiu	$a3,$sp,0x90
/*  f0c8844:	afb50010 */ 	sw	$s5,0x10($sp)
/*  f0c8848:	e7a400b0 */ 	swc1	$f4,0xb0($sp)
/*  f0c884c:	0c006052 */ 	jal	func00018148
/*  f0c8850:	e7b000b8 */ 	swc1	$f16,0xb8($sp)
/*  f0c8854:	02602025 */ 	or	$a0,$s3,$zero
/*  f0c8858:	02a02825 */ 	or	$a1,$s5,$zero
/*  f0c885c:	27a60078 */ 	addiu	$a2,$sp,0x78
/*  f0c8860:	00003825 */ 	or	$a3,$zero,$zero
/*  f0c8864:	0c00a910 */ 	jal	func0002a440
/*  f0c8868:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0c886c:	18400034 */ 	blez	$v0,.L0f0c8940
/*  f0c8870:	c7b20078 */ 	lwc1	$f18,0x78($sp)
/*  f0c8874:	46189001 */ 	sub.s	$f0,$f18,$f24
/*  f0c8878:	3c014348 */ 	lui	$at,0x4348
/*  f0c887c:	44812000 */ 	mtc1	$at,$f4
/*  f0c8880:	3c01c348 */ 	lui	$at,0xc348
/*  f0c8884:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0c8888:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c888c:	4502002d */ 	bc1fl	.L0f0c8944
/*  f0c8890:	2a410005 */ 	slti	$at,$s2,0x5
/*  f0c8894:	44813000 */ 	mtc1	$at,$f6
/*  f0c8898:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0c889c:	4600303c */ 	c.lt.s	$f6,$f0
/*  f0c88a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c88a4:	45020027 */ 	bc1fl	.L0f0c8944
/*  f0c88a8:	2a410005 */ 	slti	$at,$s2,0x5
/*  f0c88ac:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0c88b0:	4600a386 */ 	mov.s	$f14,$f20
/*  f0c88b4:	c5c80078 */ 	lwc1	$f8,0x78($t6)
/*  f0c88b8:	0fc259d4 */ 	jal	func0f096750
/*  f0c88bc:	46089301 */ 	sub.s	$f12,$f18,$f8
/*  f0c88c0:	46160282 */ 	mul.s	$f10,$f0,$f22
/*  f0c88c4:	3c017f1b */ 	lui	$at,%hi(var7f1ad8b0)
/*  f0c88c8:	c430d8b0 */ 	lwc1	$f16,%lo(var7f1ad8b0)($at)
/*  f0c88cc:	3c01c080 */ 	lui	$at,0xc080
/*  f0c88d0:	44813000 */ 	mtc1	$at,$f6
/*  f0c88d4:	3c014334 */ 	lui	$at,0x4334
/*  f0c88d8:	44819000 */ 	mtc1	$at,$f18
/*  f0c88dc:	46105103 */ 	div.s	$f4,$f10,$f16
/*  f0c88e0:	3c01c248 */ 	lui	$at,0xc248
/*  f0c88e4:	44814000 */ 	mtc1	$at,$f8
/*  f0c88e8:	3c014220 */ 	lui	$at,0x4220
/*  f0c88ec:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f0c88f0:	460c903e */ 	c.le.s	$f18,$f12
/*  f0c88f4:	46006086 */ 	mov.s	$f2,$f12
/*  f0c88f8:	45020003 */ 	bc1fl	.L0f0c8908
/*  f0c88fc:	4602403e */ 	c.le.s	$f8,$f2
/*  f0c8900:	46166081 */ 	sub.s	$f2,$f12,$f22
/*  f0c8904:	4602403e */ 	c.le.s	$f8,$f2
.L0f0c8908:
/*  f0c8908:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c890c:	4502000d */ 	bc1fl	.L0f0c8944
/*  f0c8910:	2a410005 */ 	slti	$at,$s2,0x5
/*  f0c8914:	44815000 */ 	mtc1	$at,$f10
/*  f0c8918:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0c891c:	03b1c021 */ 	addu	$t8,$sp,$s1
/*  f0c8920:	460a103e */ 	c.le.s	$f2,$f10
/*  f0c8924:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8928:	45020006 */ 	bc1fl	.L0f0c8944
/*  f0c892c:	2a410005 */ 	slti	$at,$s2,0x5
/*  f0c8930:	ae0f0000 */ 	sw	$t7,0x0($s0)
/*  f0c8934:	e702012c */ 	swc1	$f2,0x12c($t8)
/*  f0c8938:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f0c893c:	c7b80078 */ 	lwc1	$f24,0x78($sp)
.L0f0c8940:
/*  f0c8940:	2a410005 */ 	slti	$at,$s2,0x5
.L0f0c8944:
/*  f0c8944:	02404025 */ 	or	$t0,$s2,$zero
/*  f0c8948:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f0c894c:	1420ff91 */ 	bnez	$at,.L0f0c8794
/*  f0c8950:	26100004 */ 	addiu	$s0,$s0,4
/*  f0c8954:	26c9ffff */ 	addiu	$t1,$s6,-1
/*  f0c8958:	1920002f */ 	blez	$t1,.L0f0c8a18
/*  f0c895c:	00004025 */ 	or	$t0,$zero,$zero
/*  f0c8960:	c7a20070 */ 	lwc1	$f2,0x70($sp)
/*  f0c8964:	27aa0118 */ 	addiu	$t2,$sp,0x118
/*  f0c8968:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f0c896c:	2404ffff */ 	addiu	$a0,$zero,-1
.L0f0c8970:
/*  f0c8970:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c8974:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c8978:	27a60118 */ 	addiu	$a2,$sp,0x118
.L0f0c897c:
/*  f0c897c:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f0c8980:	24c60004 */ 	addiu	$a2,$a2,0x04
/*  f0c8984:	27ab012c */ 	addiu	$t3,$sp,0x12c
/*  f0c8988:	53200019 */ 	beqzl	$t9,.L0f0c89f0
/*  f0c898c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0c8990:	04810004 */ 	bgez	$a0,.L0f0c89a4
/*  f0c8994:	00ab1021 */ 	addu	$v0,$a1,$t3
/*  f0c8998:	00602025 */ 	or	$a0,$v1,$zero
/*  f0c899c:	10000013 */ 	beqz	$zero,.L0f0c89ec
/*  f0c89a0:	c4420000 */ 	lwc1	$f2,0x0($v0)
.L0f0c89a4:
/*  f0c89a4:	310c0001 */ 	andi	$t4,$t0,0x1
/*  f0c89a8:	5180000a */ 	beqzl	$t4,.L0f0c89d4
/*  f0c89ac:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f0c89b0:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f0c89b4:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c89b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c89bc:	4502000c */ 	bc1fl	.L0f0c89f0
/*  f0c89c0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0c89c4:	00602025 */ 	or	$a0,$v1,$zero
/*  f0c89c8:	10000008 */ 	beqz	$zero,.L0f0c89ec
/*  f0c89cc:	46000086 */ 	mov.s	$f2,$f0
/*  f0c89d0:	c4400000 */ 	lwc1	$f0,0x0($v0)
.L0f0c89d4:
/*  f0c89d4:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0c89d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c89dc:	45020004 */ 	bc1fl	.L0f0c89f0
/*  f0c89e0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0c89e4:	00602025 */ 	or	$a0,$v1,$zero
/*  f0c89e8:	46000086 */ 	mov.s	$f2,$f0
.L0f0c89ec:
/*  f0c89ec:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f0c89f0:
/*  f0c89f0:	1467ffe2 */ 	bne	$v1,$a3,.L0f0c897c
/*  f0c89f4:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f0c89f8:	04800004 */ 	bltz	$a0,.L0f0c8a0c
/*  f0c89fc:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f0c8a00:	00046880 */ 	sll	$t5,$a0,0x2
/*  f0c8a04:	014d7021 */ 	addu	$t6,$t2,$t5
/*  f0c8a08:	adc00000 */ 	sw	$zero,0x0($t6)
.L0f0c8a0c:
/*  f0c8a0c:	5509ffd8 */ 	bnel	$t0,$t1,.L0f0c8970
/*  f0c8a10:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f0c8a14:	e7a20070 */ 	swc1	$f2,0x70($sp)
.L0f0c8a18:
/*  f0c8a18:	00008825 */ 	or	$s1,$zero,$zero
/*  f0c8a1c:	27b00118 */ 	addiu	$s0,$sp,0x118
/*  f0c8a20:	27a2012c */ 	addiu	$v0,$sp,0x12c
.L0f0c8a24:
/*  f0c8a24:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f0c8a28:	26100004 */ 	addiu	$s0,$s0,4
/*  f0c8a2c:	11e00004 */ 	beqz	$t7,.L0f0c8a40
/*  f0c8a30:	03b1c021 */ 	addu	$t8,$sp,$s1
/*  f0c8a34:	c702012c */ 	lwc1	$f2,0x12c($t8)
/*  f0c8a38:	10000003 */ 	beqz	$zero,.L0f0c8a48
/*  f0c8a3c:	e7a20164 */ 	swc1	$f2,0x164($sp)
.L0f0c8a40:
/*  f0c8a40:	1602fff8 */ 	bne	$s0,$v0,.L0f0c8a24
/*  f0c8a44:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f0c8a48:
/*  f0c8a48:	c7a20164 */ 	lwc1	$f2,0x164($sp)
.L0f0c8a4c:
/*  f0c8a4c:	44808000 */ 	mtc1	$zero,$f16
/*  f0c8a50:	3c017f1b */ 	lui	$at,%hi(var7f1ad8b4)
/*  f0c8a54:	4602803c */ 	c.lt.s	$f16,$f2
/*  f0c8a58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8a5c:	45020005 */ 	bc1fl	.L0f0c8a74
/*  f0c8a60:	46001006 */ 	mov.s	$f0,$f2
/*  f0c8a64:	c424d8b4 */ 	lwc1	$f4,%lo(var7f1ad8b4)($at)
/*  f0c8a68:	46041082 */ 	mul.s	$f2,$f2,$f4
/*  f0c8a6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8a70:	46001006 */ 	mov.s	$f0,$f2
.L0f0c8a74:
/*  f0c8a74:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f0c8a78:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f0c8a7c:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f0c8a80:	d7b80030 */ 	ldc1	$f24,0x30($sp)
/*  f0c8a84:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0c8a88:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f0c8a8c:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f0c8a90:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f0c8a94:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f0c8a98:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f0c8a9c:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f0c8aa0:	03e00008 */ 	jr	$ra
/*  f0c8aa4:	27bd0168 */ 	addiu	$sp,$sp,0x168
);

GLOBAL_ASM(
glabel func0f0c8aa8
/*  f0c8aa8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0c8aac:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0c8ab0:	44800000 */ 	mtc1	$zero,$f0
/*  f0c8ab4:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f0c8ab8:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f0c8abc:	ac800008 */ 	sw	$zero,0x8($a0)
/*  f0c8ac0:	ac80000c */ 	sw	$zero,0xc($a0)
/*  f0c8ac4:	ac800010 */ 	sw	$zero,0x10($a0)
/*  f0c8ac8:	ac800014 */ 	sw	$zero,0x14($a0)
/*  f0c8acc:	ac800018 */ 	sw	$zero,0x18($a0)
/*  f0c8ad0:	ac80001c */ 	sw	$zero,0x1c($a0)
/*  f0c8ad4:	ac800020 */ 	sw	$zero,0x20($a0)
/*  f0c8ad8:	ac800024 */ 	sw	$zero,0x24($a0)
/*  f0c8adc:	ac800028 */ 	sw	$zero,0x28($a0)
/*  f0c8ae0:	ac80002c */ 	sw	$zero,0x2c($a0)
/*  f0c8ae4:	ac800048 */ 	sw	$zero,0x48($a0)
/*  f0c8ae8:	ac80004c */ 	sw	$zero,0x4c($a0)
/*  f0c8aec:	ac800050 */ 	sw	$zero,0x50($a0)
/*  f0c8af0:	ac800054 */ 	sw	$zero,0x54($a0)
/*  f0c8af4:	ac800058 */ 	sw	$zero,0x58($a0)
/*  f0c8af8:	ac800064 */ 	sw	$zero,0x64($a0)
/*  f0c8afc:	ac800068 */ 	sw	$zero,0x68($a0)
/*  f0c8b00:	ac80006c */ 	sw	$zero,0x6c($a0)
/*  f0c8b04:	ac800070 */ 	sw	$zero,0x70($a0)
/*  f0c8b08:	ac800074 */ 	sw	$zero,0x74($a0)
/*  f0c8b0c:	ac800078 */ 	sw	$zero,0x78($a0)
/*  f0c8b10:	ac80007c */ 	sw	$zero,0x7c($a0)
/*  f0c8b14:	ac800080 */ 	sw	$zero,0x80($a0)
/*  f0c8b18:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x288)
/*  f0c8b1c:	e4800030 */ 	swc1	$f0,0x30($a0)
/*  f0c8b20:	e4800034 */ 	swc1	$f0,0x34($a0)
/*  f0c8b24:	e4800038 */ 	swc1	$f0,0x38($a0)
/*  f0c8b28:	e480003c */ 	swc1	$f0,0x3c($a0)
/*  f0c8b2c:	e4800040 */ 	swc1	$f0,0x40($a0)
/*  f0c8b30:	e4800044 */ 	swc1	$f0,0x44($a0)
/*  f0c8b34:	e480005c */ 	swc1	$f0,0x5c($a0)
/*  f0c8b38:	e4800060 */ 	swc1	$f0,0x60($a0)
/*  f0c8b3c:	8dcea248 */ 	lw	$t6,%lo(g_Vars+0x288)($t6)
/*  f0c8b40:	00802825 */ 	or	$a1,$a0,$zero
/*  f0c8b44:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0c8b48:	0fc549e0 */ 	jal	optionsGetForwardPitch
/*  f0c8b4c:	afa50018 */ 	sw	$a1,0x18($sp)
/*  f0c8b50:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f0c8b54:	2c4f0001 */ 	sltiu	$t7,$v0,0x1
/*  f0c8b58:	acaf0084 */ 	sw	$t7,0x84($a1)
/*  f0c8b5c:	aca00088 */ 	sw	$zero,0x88($a1)
/*  f0c8b60:	aca0008c */ 	sw	$zero,0x8c($a1)
/*  f0c8b64:	aca00090 */ 	sw	$zero,0x90($a1)
/*  f0c8b68:	aca00094 */ 	sw	$zero,0x94($a1)
/*  f0c8b6c:	aca00098 */ 	sw	$zero,0x98($a1)
/*  f0c8b70:	aca0009c */ 	sw	$zero,0x9c($a1)
/*  f0c8b74:	aca000a0 */ 	sw	$zero,0xa0($a1)
/*  f0c8b78:	aca000a4 */ 	sw	$zero,0xa4($a1)
/*  f0c8b7c:	aca000a8 */ 	sw	$zero,0xa8($a1)
/*  f0c8b80:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c8b84:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0c8b88:	03e00008 */ 	jr	$ra
/*  f0c8b8c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0c8b90
.late_rodata
glabel var7f1ad8b8
.word 0x3c23d70a
glabel var7f1ad8bc
.word 0x3c23d70a
glabel var7f1ad8c0
.word 0x3d4ccccd
glabel var7f1ad8c4
.word 0x3f76872b
glabel var7f1ad8c8
.word 0x39a7c599
glabel var7f1ad8cc
.word 0x3f6a3d71
glabel var7f1ad8d0
.word 0x3f7a9fbe
glabel var7f1ad8d4
.word 0x39a7c599
glabel var7f1ad8d8
.word 0x3f76872b
glabel var7f1ad8dc
.word 0x3e99999a
glabel var7f1ad8e0
.word 0x3dcccccd
glabel var7f1ad8e4
.word 0x3f266666
.text
/*  f0c8b90:	27bdfda0 */ 	addiu	$sp,$sp,-608
/*  f0c8b94:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0c8b98:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f0c8b9c:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f0c8ba0:	8e4e0288 */ 	lw	$t6,0x288($s2)
/*  f0c8ba4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0c8ba8:	00808025 */ 	or	$s0,$a0,$zero
/*  f0c8bac:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0c8bb0:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f0c8bb4:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f0c8bb8:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0c8bbc:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0c8bc0:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0c8bc4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0c8bc8:	afa7026c */ 	sw	$a3,0x26c($sp)
/*  f0c8bcc:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0c8bd0:	00c0b025 */ 	or	$s6,$a2,$zero
/*  f0c8bd4:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f0c8bd8:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0c8bdc:	afa201b0 */ 	sw	$v0,0x1b0($sp)
/*  f0c8be0:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0c8be4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c8be8:	afa201ac */ 	sw	$v0,0x1ac($sp)
/*  f0c8bec:	00402025 */ 	or	$a0,$v0,$zero
/*  f0c8bf0:	0fc2c601 */ 	jal	func0f0b1804
/*  f0c8bf4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c8bf8:	8e4f0288 */ 	lw	$t7,0x288($s2)
/*  f0c8bfc:	afa201a8 */ 	sw	$v0,0x1a8($sp)
/*  f0c8c00:	0fc549d2 */ 	jal	optionsGetUnk45
/*  f0c8c04:	8de40070 */ 	lw	$a0,0x70($t7)
/*  f0c8c08:	0002ae00 */ 	sll	$s5,$v0,0x18
/*  f0c8c0c:	0015c603 */ 	sra	$t8,$s5,0x18
/*  f0c8c10:	12000009 */ 	beqz	$s0,.L0f0c8c38
/*  f0c8c14:	0300a825 */ 	or	$s5,$t8,$zero
/*  f0c8c18:	00182600 */ 	sll	$a0,$t8,0x18
/*  f0c8c1c:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f0c8c20:	0c005384 */ 	jal	func00014e10
/*  f0c8c24:	03202025 */ 	or	$a0,$t9,$zero
/*  f0c8c28:	0002a600 */ 	sll	$s4,$v0,0x18
/*  f0c8c2c:	00144603 */ 	sra	$t0,$s4,0x18
/*  f0c8c30:	10000002 */ 	beqz	$zero,.L0f0c8c3c
/*  f0c8c34:	0100a025 */ 	or	$s4,$t0,$zero
.L0f0c8c38:
/*  f0c8c38:	0000a025 */ 	or	$s4,$zero,$zero
.L0f0c8c3c:
/*  f0c8c3c:	12200008 */ 	beqz	$s1,.L0f0c8c60
/*  f0c8c40:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0c8c44:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f0c8c48:	0c0053ae */ 	jal	func00014eb8
/*  f0c8c4c:	01202025 */ 	or	$a0,$t1,$zero
/*  f0c8c50:	00029e00 */ 	sll	$s3,$v0,0x18
/*  f0c8c54:	00135603 */ 	sra	$t2,$s3,0x18
/*  f0c8c58:	10000002 */ 	beqz	$zero,.L0f0c8c64
/*  f0c8c5c:	01409825 */ 	or	$s3,$t2,$zero
.L0f0c8c60:
/*  f0c8c60:	00009825 */ 	or	$s3,$zero,$zero
.L0f0c8c64:
/*  f0c8c64:	0016b82b */ 	sltu	$s7,$zero,$s6
/*  f0c8c68:	12e00007 */ 	beqz	$s7,.L0f0c8c88
/*  f0c8c6c:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0c8c70:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f0c8c74:	01602025 */ 	or	$a0,$t3,$zero
/*  f0c8c78:	0c0053d8 */ 	jal	func00014f60
/*  f0c8c7c:	3405ffff */ 	dli	$a1,0xffff
/*  f0c8c80:	10000002 */ 	beqz	$zero,.L0f0c8c8c
/*  f0c8c84:	a7a201a2 */ 	sh	$v0,0x1a2($sp)
.L0f0c8c88:
/*  f0c8c88:	a7a001a2 */ 	sh	$zero,0x1a2($sp)
.L0f0c8c8c:
/*  f0c8c8c:	12e00007 */ 	beqz	$s7,.L0f0c8cac
/*  f0c8c90:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0c8c94:	00046603 */ 	sra	$t4,$a0,0x18
/*  f0c8c98:	01802025 */ 	or	$a0,$t4,$zero
/*  f0c8c9c:	0c005408 */ 	jal	func00015020
/*  f0c8ca0:	3405ffff */ 	dli	$a1,0xffff
/*  f0c8ca4:	10000002 */ 	beqz	$zero,.L0f0c8cb0
/*  f0c8ca8:	a7a201a0 */ 	sh	$v0,0x1a0($sp)
.L0f0c8cac:
/*  f0c8cac:	a7a001a0 */ 	sh	$zero,0x1a0($sp)
.L0f0c8cb0:
/*  f0c8cb0:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c8cb4:	340dffff */ 	dli	$t5,0xffff
/*  f0c8cb8:	a7ad019e */ 	sh	$t5,0x19e($sp)
/*  f0c8cbc:	8dc21c40 */ 	lw	$v0,0x1c40($t6)
/*  f0c8cc0:	304fffff */ 	andi	$t7,$v0,0xffff
/*  f0c8cc4:	11e00017 */ 	beqz	$t7,.L0f0c8d24
/*  f0c8cc8:	31f0ffff */ 	andi	$s0,$t7,0xffff
/*  f0c8ccc:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0c8cd0:	0200c027 */ 	nor	$t8,$s0,$zero
/*  f0c8cd4:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f0c8cd8:	a7b8019e */ 	sh	$t8,0x19e($sp)
/*  f0c8cdc:	03202025 */ 	or	$a0,$t9,$zero
/*  f0c8ce0:	0c0053d8 */ 	jal	func00014f60
/*  f0c8ce4:	3405ffff */ 	dli	$a1,0xffff
/*  f0c8ce8:	00508824 */ 	and	$s1,$v0,$s0
/*  f0c8cec:	97a901a2 */ 	lhu	$t1,0x1a2($sp)
/*  f0c8cf0:	97ab01a0 */ 	lhu	$t3,0x1a0($sp)
/*  f0c8cf4:	3228ffff */ 	andi	$t0,$s1,0xffff
/*  f0c8cf8:	01001827 */ 	nor	$v1,$t0,$zero
/*  f0c8cfc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8d00:	01235024 */ 	and	$t2,$t1,$v1
/*  f0c8d04:	01636024 */ 	and	$t4,$t3,$v1
/*  f0c8d08:	a7aa01a2 */ 	sh	$t2,0x1a2($sp)
/*  f0c8d0c:	a7ac01a0 */ 	sh	$t4,0x1a0($sp)
/*  f0c8d10:	8cad1c40 */ 	lw	$t5,0x1c40($a1)
/*  f0c8d14:	3c01ffff */ 	lui	$at,0xffff
/*  f0c8d18:	01a17024 */ 	and	$t6,$t5,$at
/*  f0c8d1c:	01c87825 */ 	or	$t7,$t6,$t0
/*  f0c8d20:	acaf1c40 */ 	sw	$t7,0x1c40($a1)
.L0f0c8d24:
/*  f0c8d24:	0c005207 */ 	jal	func0001481c
/*  f0c8d28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8d2c:	0040b025 */ 	or	$s6,$v0,$zero
/*  f0c8d30:	0fc322aa */ 	jal	func0f0c8aa8
/*  f0c8d34:	27a401b4 */ 	addiu	$a0,$sp,0x1b4
/*  f0c8d38:	2a81fffb */ 	slti	$at,$s4,-5
/*  f0c8d3c:	10200003 */ 	beqz	$at,.L0f0c8d4c
/*  f0c8d40:	26980005 */ 	addiu	$t8,$s4,0x5
/*  f0c8d44:	10000007 */ 	beqz	$zero,.L0f0c8d64
/*  f0c8d48:	afb80240 */ 	sw	$t8,0x240($sp)
.L0f0c8d4c:
/*  f0c8d4c:	2a810006 */ 	slti	$at,$s4,0x6
/*  f0c8d50:	14200003 */ 	bnez	$at,.L0f0c8d60
/*  f0c8d54:	2699fffb */ 	addiu	$t9,$s4,-5
/*  f0c8d58:	10000002 */ 	beqz	$zero,.L0f0c8d64
/*  f0c8d5c:	afb90240 */ 	sw	$t9,0x240($sp)
.L0f0c8d60:
/*  f0c8d60:	afa00240 */ 	sw	$zero,0x240($sp)
.L0f0c8d64:
/*  f0c8d64:	2a61fffb */ 	slti	$at,$s3,-5
/*  f0c8d68:	10200003 */ 	beqz	$at,.L0f0c8d78
/*  f0c8d6c:	26680005 */ 	addiu	$t0,$s3,0x5
/*  f0c8d70:	10000007 */ 	beqz	$zero,.L0f0c8d90
/*  f0c8d74:	afa80244 */ 	sw	$t0,0x244($sp)
.L0f0c8d78:
/*  f0c8d78:	2a610006 */ 	slti	$at,$s3,0x6
/*  f0c8d7c:	14200003 */ 	bnez	$at,.L0f0c8d8c
/*  f0c8d80:	2669fffb */ 	addiu	$t1,$s3,-5
/*  f0c8d84:	10000002 */ 	beqz	$zero,.L0f0c8d90
/*  f0c8d88:	afa90244 */ 	sw	$t1,0x244($sp)
.L0f0c8d8c:
/*  f0c8d8c:	afa00244 */ 	sw	$zero,0x244($sp)
.L0f0c8d90:
/*  f0c8d90:	8faa0240 */ 	lw	$t2,0x240($sp)
/*  f0c8d94:	8fab0244 */ 	lw	$t3,0x244($sp)
/*  f0c8d98:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8d9c:	afb40248 */ 	sw	$s4,0x248($sp)
/*  f0c8da0:	afb3024c */ 	sw	$s3,0x24c($sp)
/*  f0c8da4:	afaa0250 */ 	sw	$t2,0x250($sp)
/*  f0c8da8:	afaa0258 */ 	sw	$t2,0x258($sp)
/*  f0c8dac:	afab0254 */ 	sw	$t3,0x254($sp)
/*  f0c8db0:	afab025c */ 	sw	$t3,0x25c($sp)
/*  f0c8db4:	8cac00d8 */ 	lw	$t4,0xd8($a1)
/*  f0c8db8:	55800017 */ 	bnezl	$t4,.L0f0c8e18
/*  f0c8dbc:	8e480314 */ 	lw	$t0,0x314($s2)
/*  f0c8dc0:	8cad1a24 */ 	lw	$t5,0x1a24($a1)
/*  f0c8dc4:	97ae01a0 */ 	lhu	$t6,0x1a0($sp)
/*  f0c8dc8:	15a0004a */ 	bnez	$t5,.L0f0c8ef4
/*  f0c8dcc:	31cf1000 */ 	andi	$t7,$t6,0x1000
/*  f0c8dd0:	51e00049 */ 	beqzl	$t7,.L0f0c8ef8
/*  f0c8dd4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8dd8:	8e580314 */ 	lw	$t8,0x314($s2)
/*  f0c8ddc:	17000009 */ 	bnez	$t8,.L0f0c8e04
/*  f0c8de0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8de4:	8e59000c */ 	lw	$t9,0xc($s2)
/*  f0c8de8:	2b210010 */ 	slti	$at,$t9,0x10
/*  f0c8dec:	54200042 */ 	bnezl	$at,.L0f0c8ef8
/*  f0c8df0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8df4:	0fc2ebc3 */ 	jal	currentPlayerPause
/*  f0c8df8:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0c8dfc:	1000003e */ 	beqz	$zero,.L0f0c8ef8
/*  f0c8e00:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c8e04:
/*  f0c8e04:	0fc5e36f */ 	jal	func0f178dbc
/*  f0c8e08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8e0c:	1000003a */ 	beqz	$zero,.L0f0c8ef8
/*  f0c8e10:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8e14:	8e480314 */ 	lw	$t0,0x314($s2)
.L0f0c8e18:
/*  f0c8e18:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c8e1c:	51000036 */ 	beqzl	$t0,.L0f0c8ef8
/*  f0c8e20:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8e24:	8e49006c */ 	lw	$t1,0x6c($s2)
/*  f0c8e28:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c8e2c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0c8e30:	11200003 */ 	beqz	$t1,.L0f0c8e40
/*  f0c8e34:	00001825 */ 	or	$v1,$zero,$zero
/*  f0c8e38:	10000001 */ 	beqz	$zero,.L0f0c8e40
/*  f0c8e3c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0c8e40:
/*  f0c8e40:	8e4a0068 */ 	lw	$t2,0x68($s2)
/*  f0c8e44:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c8e48:	11400003 */ 	beqz	$t2,.L0f0c8e58
/*  f0c8e4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8e50:	10000001 */ 	beqz	$zero,.L0f0c8e58
/*  f0c8e54:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0c8e58:
/*  f0c8e58:	8e4b0064 */ 	lw	$t3,0x64($s2)
/*  f0c8e5c:	11600003 */ 	beqz	$t3,.L0f0c8e6c
/*  f0c8e60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8e64:	10000001 */ 	beqz	$zero,.L0f0c8e6c
/*  f0c8e68:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0c8e6c:
/*  f0c8e6c:	8e4c0070 */ 	lw	$t4,0x70($s2)
/*  f0c8e70:	11800003 */ 	beqz	$t4,.L0f0c8e80
/*  f0c8e74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8e78:	10000001 */ 	beqz	$zero,.L0f0c8e80
/*  f0c8e7c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0c8e80:
/*  f0c8e80:	00836821 */ 	addu	$t5,$a0,$v1
/*  f0c8e84:	01a27021 */ 	addu	$t6,$t5,$v0
/*  f0c8e88:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f0c8e8c:	15e10010 */ 	bne	$t7,$at,.L0f0c8ed0
/*  f0c8e90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8e94:	0fc62590 */ 	jal	mpIsPaused
/*  f0c8e98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8e9c:	10400015 */ 	beqz	$v0,.L0f0c8ef4
/*  f0c8ea0:	97b801a0 */ 	lhu	$t8,0x1a0($sp)
/*  f0c8ea4:	33191000 */ 	andi	$t9,$t8,0x1000
/*  f0c8ea8:	13200012 */ 	beqz	$t9,.L0f0c8ef4
/*  f0c8eac:	3c08800b */ 	lui	$t0,%hi(g_MpSetup+0x1e)
/*  f0c8eb0:	9108cba6 */ 	lbu	$t0,%lo(g_MpSetup+0x1e)($t0)
/*  f0c8eb4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0c8eb8:	5101000f */ 	beql	$t0,$at,.L0f0c8ef8
/*  f0c8ebc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8ec0:	0fc625cb */ 	jal	mpSetPaused
/*  f0c8ec4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c8ec8:	1000000b */ 	beqz	$zero,.L0f0c8ef8
/*  f0c8ecc:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c8ed0:
/*  f0c8ed0:	0fc62590 */ 	jal	mpIsPaused
/*  f0c8ed4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8ed8:	10400006 */ 	beqz	$v0,.L0f0c8ef4
/*  f0c8edc:	97a901a0 */ 	lhu	$t1,0x1a0($sp)
/*  f0c8ee0:	312a1000 */ 	andi	$t2,$t1,0x1000
/*  f0c8ee4:	51400004 */ 	beqzl	$t2,.L0f0c8ef8
/*  f0c8ee8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c8eec:	0fc5e36f */ 	jal	func0f178dbc
/*  f0c8ef0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0c8ef4:
/*  f0c8ef4:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c8ef8:
/*  f0c8ef8:	8cab1a24 */ 	lw	$t3,0x1a24($a1)
/*  f0c8efc:	55600675 */ 	bnezl	$t3,.L0f0ca8d4
/*  f0c8f00:	aca000d0 */ 	sw	$zero,0xd0($a1)
/*  f0c8f04:	8cac00d8 */ 	lw	$t4,0xd8($a1)
/*  f0c8f08:	8fa201b0 */ 	lw	$v0,0x1b0($sp)
/*  f0c8f0c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0c8f10:	55800670 */ 	bnezl	$t4,.L0f0ca8d4
/*  f0c8f14:	aca000d0 */ 	sw	$zero,0xd0($a1)
/*  f0c8f18:	10410007 */ 	beq	$v0,$at,.L0f0c8f38
/*  f0c8f1c:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0c8f20:	10410005 */ 	beq	$v0,$at,.L0f0c8f38
/*  f0c8f24:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0c8f28:	10410003 */ 	beq	$v0,$at,.L0f0c8f38
/*  f0c8f2c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0c8f30:	5441033f */ 	bnel	$v0,$at,.L0f0c9c30
/*  f0c8f34:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0c8f38:
/*  f0c8f38:	8e4d0288 */ 	lw	$t5,0x288($s2)
/*  f0c8f3c:	0fc549d9 */ 	jal	optionsGetUnk46
/*  f0c8f40:	8da40070 */ 	lw	$a0,0x70($t5)
/*  f0c8f44:	0002a600 */ 	sll	$s4,$v0,0x18
/*  f0c8f48:	00022600 */ 	sll	$a0,$v0,0x18
/*  f0c8f4c:	00147603 */ 	sra	$t6,$s4,0x18
/*  f0c8f50:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0c8f54:	01c0a025 */ 	or	$s4,$t6,$zero
/*  f0c8f58:	0c005384 */ 	jal	func00014e10
/*  f0c8f5c:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0c8f60:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c8f64:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f0c8f68:	a3a200e9 */ 	sb	$v0,0xe9($sp)
/*  f0c8f6c:	0c0053ae */ 	jal	func00014eb8
/*  f0c8f70:	03002025 */ 	or	$a0,$t8,$zero
/*  f0c8f74:	00028600 */ 	sll	$s0,$v0,0x18
/*  f0c8f78:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c8f7c:	0010ce03 */ 	sra	$t9,$s0,0x18
/*  f0c8f80:	00044603 */ 	sra	$t0,$a0,0x18
/*  f0c8f84:	03208025 */ 	or	$s0,$t9,$zero
/*  f0c8f88:	01002025 */ 	or	$a0,$t0,$zero
/*  f0c8f8c:	0c0053d8 */ 	jal	func00014f60
/*  f0c8f90:	3405ffff */ 	dli	$a1,0xffff
/*  f0c8f94:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c8f98:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f0c8f9c:	a7a200e6 */ 	sh	$v0,0xe6($sp)
/*  f0c8fa0:	01202025 */ 	or	$a0,$t1,$zero
/*  f0c8fa4:	0c005408 */ 	jal	func00015020
/*  f0c8fa8:	3405ffff */ 	dli	$a1,0xffff
/*  f0c8fac:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0c8fb0:	340affff */ 	dli	$t2,0xffff
/*  f0c8fb4:	a7a200e4 */ 	sh	$v0,0xe4($sp)
/*  f0c8fb8:	a7aa00da */ 	sh	$t2,0xda($sp)
/*  f0c8fbc:	8d631c40 */ 	lw	$v1,0x1c40($t3)
/*  f0c8fc0:	83b300e9 */ 	lb	$s3,0xe9($sp)
/*  f0c8fc4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c8fc8:	00036402 */ 	srl	$t4,$v1,0x10
/*  f0c8fcc:	5180001b */ 	beqzl	$t4,.L0f0c903c
/*  f0c8fd0:	8faf026c */ 	lw	$t7,0x26c($sp)
/*  f0c8fd4:	afb000dc */ 	sw	$s0,0xdc($sp)
/*  f0c8fd8:	00038c02 */ 	srl	$s1,$v1,0x10
/*  f0c8fdc:	3230ffff */ 	andi	$s0,$s1,0xffff
/*  f0c8fe0:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c8fe4:	02007027 */ 	nor	$t6,$s0,$zero
/*  f0c8fe8:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f0c8fec:	a7ae00da */ 	sh	$t6,0xda($sp)
/*  f0c8ff0:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0c8ff4:	0c0053d8 */ 	jal	func00014f60
/*  f0c8ff8:	3405ffff */ 	dli	$a1,0xffff
/*  f0c8ffc:	97b900e6 */ 	lhu	$t9,0xe6($sp)
/*  f0c9000:	97a900e4 */ 	lhu	$t1,0xe4($sp)
/*  f0c9004:	0050c024 */ 	and	$t8,$v0,$s0
/*  f0c9008:	03001827 */ 	nor	$v1,$t8,$zero
/*  f0c900c:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9010:	03234024 */ 	and	$t0,$t9,$v1
/*  f0c9014:	01235024 */ 	and	$t2,$t1,$v1
/*  f0c9018:	a7a800e6 */ 	sh	$t0,0xe6($sp)
/*  f0c901c:	a7aa00e4 */ 	sh	$t2,0xe4($sp)
/*  f0c9020:	8cab1c40 */ 	lw	$t3,0x1c40($a1)
/*  f0c9024:	00186c00 */ 	sll	$t5,$t8,0x10
/*  f0c9028:	316cffff */ 	andi	$t4,$t3,0xffff
/*  f0c902c:	018d7025 */ 	or	$t6,$t4,$t5
/*  f0c9030:	acae1c40 */ 	sw	$t6,0x1c40($a1)
/*  f0c9034:	8fa400dc */ 	lw	$a0,0xdc($sp)
/*  f0c9038:	8faf026c */ 	lw	$t7,0x26c($sp)
.L0f0c903c:
/*  f0c903c:	51e00007 */ 	beqzl	$t7,.L0f0c905c
/*  f0c9040:	2a61fffb */ 	slti	$at,$s3,-5
/*  f0c9044:	a3a000e9 */ 	sb	$zero,0xe9($sp)
/*  f0c9048:	a7a000e6 */ 	sh	$zero,0xe6($sp)
/*  f0c904c:	00009825 */ 	or	$s3,$zero,$zero
/*  f0c9050:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c9054:	a7a000e4 */ 	sh	$zero,0xe4($sp)
/*  f0c9058:	2a61fffb */ 	slti	$at,$s3,-5
.L0f0c905c:
/*  f0c905c:	10200003 */ 	beqz	$at,.L0f0c906c
/*  f0c9060:	8fa201b0 */ 	lw	$v0,0x1b0($sp)
/*  f0c9064:	10000007 */ 	beqz	$zero,.L0f0c9084
/*  f0c9068:	26730005 */ 	addiu	$s3,$s3,0x5
.L0f0c906c:
/*  f0c906c:	2a610006 */ 	slti	$at,$s3,0x6
/*  f0c9070:	54200004 */ 	bnezl	$at,.L0f0c9084
/*  f0c9074:	00009825 */ 	or	$s3,$zero,$zero
/*  f0c9078:	10000002 */ 	beqz	$zero,.L0f0c9084
/*  f0c907c:	2673fffb */ 	addiu	$s3,$s3,-5
/*  f0c9080:	00009825 */ 	or	$s3,$zero,$zero
.L0f0c9084:
/*  f0c9084:	2881fffb */ 	slti	$at,$a0,-5
/*  f0c9088:	50200004 */ 	beqzl	$at,.L0f0c909c
/*  f0c908c:	28810006 */ 	slti	$at,$a0,0x6
/*  f0c9090:	10000007 */ 	beqz	$zero,.L0f0c90b0
/*  f0c9094:	24840005 */ 	addiu	$a0,$a0,0x5
/*  f0c9098:	28810006 */ 	slti	$at,$a0,0x6
.L0f0c909c:
/*  f0c909c:	54200004 */ 	bnezl	$at,.L0f0c90b0
/*  f0c90a0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c90a4:	10000002 */ 	beqz	$zero,.L0f0c90b0
/*  f0c90a8:	2484fffb */ 	addiu	$a0,$a0,-5
/*  f0c90ac:	00002025 */ 	or	$a0,$zero,$zero
.L0f0c90b0:
/*  f0c90b0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0c90b4:	10410003 */ 	beq	$v0,$at,.L0f0c90c4
/*  f0c90b8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0c90bc:	54410005 */ 	bnel	$v0,$at,.L0f0c90d4
/*  f0c90c0:	afb30258 */ 	sw	$s3,0x258($sp)
.L0f0c90c4:
/*  f0c90c4:	afb30258 */ 	sw	$s3,0x258($sp)
/*  f0c90c8:	10000003 */ 	beqz	$zero,.L0f0c90d8
/*  f0c90cc:	afa40254 */ 	sw	$a0,0x254($sp)
/*  f0c90d0:	afb30258 */ 	sw	$s3,0x258($sp)
.L0f0c90d4:
/*  f0c90d4:	afa4025c */ 	sw	$a0,0x25c($sp)
.L0f0c90d8:
/*  f0c90d8:	8e5802ac */ 	lw	$t8,0x2ac($s2)
/*  f0c90dc:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0c90e0:	afa400dc */ 	sw	$a0,0xdc($sp)
/*  f0c90e4:	5701000b */ 	bnel	$t8,$at,.L0f0c9114
/*  f0c90e8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0c90ec:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c90f0:	afa001d4 */ 	sw	$zero,0x1d4($sp)
/*  f0c90f4:	afa001d8 */ 	sw	$zero,0x1d8($sp)
/*  f0c90f8:	afa00258 */ 	sw	$zero,0x258($sp)
/*  f0c90fc:	8cb91bdc */ 	lw	$t9,0x1bdc($a1)
/*  f0c9100:	afb9025c */ 	sw	$t9,0x25c($sp)
/*  f0c9104:	8ca81bd8 */ 	lw	$t0,0x1bd8($a1)
/*  f0c9108:	afa00254 */ 	sw	$zero,0x254($sp)
/*  f0c910c:	afa80250 */ 	sw	$t0,0x250($sp)
/*  f0c9110:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0c9114:
/*  f0c9114:	10410005 */ 	beq	$v0,$at,.L0f0c912c
/*  f0c9118:	8fa400dc */ 	lw	$a0,0xdc($sp)
/*  f0c911c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0c9120:	1441000b */ 	bne	$v0,$at,.L0f0c9150
/*  f0c9124:	00158e00 */ 	sll	$s1,$s5,0x18
/*  f0c9128:	afa400dc */ 	sw	$a0,0xdc($sp)
.L0f0c912c:
/*  f0c912c:	97aa00da */ 	lhu	$t2,0xda($sp)
/*  f0c9130:	97ab019e */ 	lhu	$t3,0x19e($sp)
/*  f0c9134:	00148e00 */ 	sll	$s1,$s4,0x18
/*  f0c9138:	00114e03 */ 	sra	$t1,$s1,0x18
/*  f0c913c:	01208825 */ 	or	$s1,$t1,$zero
/*  f0c9140:	a3b500ef */ 	sb	$s5,0xef($sp)
/*  f0c9144:	a7aa00ec */ 	sh	$t2,0xec($sp)
/*  f0c9148:	10000009 */ 	beqz	$zero,.L0f0c9170
/*  f0c914c:	a7ab00ea */ 	sh	$t3,0xea($sp)
.L0f0c9150:
/*  f0c9150:	97ad019e */ 	lhu	$t5,0x19e($sp)
/*  f0c9154:	97ae00da */ 	lhu	$t6,0xda($sp)
/*  f0c9158:	00116603 */ 	sra	$t4,$s1,0x18
/*  f0c915c:	afa400dc */ 	sw	$a0,0xdc($sp)
/*  f0c9160:	01808825 */ 	or	$s1,$t4,$zero
/*  f0c9164:	a3b400ef */ 	sb	$s4,0xef($sp)
/*  f0c9168:	a7ad00ec */ 	sh	$t5,0xec($sp)
/*  f0c916c:	a7ae00ea */ 	sh	$t6,0xea($sp)
.L0f0c9170:
/*  f0c9170:	8e4f0288 */ 	lw	$t7,0x288($s2)
/*  f0c9174:	0fc549fb */ 	jal	optionsGetAimControl
/*  f0c9178:	8de40070 */ 	lw	$a0,0x70($t7)
/*  f0c917c:	1440001f */ 	bnez	$v0,.L0f0c91fc
/*  f0c9180:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c9184:	1ac00018 */ 	blez	$s6,.L0f0c91e8
/*  f0c9188:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c918c:	27a3014c */ 	addiu	$v1,$sp,0x14c
/*  f0c9190:	27a700fc */ 	addiu	$a3,$sp,0xfc
.L0f0c9194:
/*  f0c9194:	12e0000d */ 	beqz	$s7,.L0f0c91cc
/*  f0c9198:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0c919c:	97b900ec */ 	lhu	$t9,0xec($sp)
/*  f0c91a0:	00112e00 */ 	sll	$a1,$s1,0x18
/*  f0c91a4:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f0c91a8:	03002825 */ 	or	$a1,$t8,$zero
/*  f0c91ac:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c91b0:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0c91b4:	afa70048 */ 	sw	$a3,0x48($sp)
/*  f0c91b8:	0c00529e */ 	jal	func00014a78
/*  f0c91bc:	33262000 */ 	andi	$a2,$t9,0x2000
/*  f0c91c0:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0c91c4:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0c91c8:	0002202b */ 	sltu	$a0,$zero,$v0
.L0f0c91cc:
/*  f0c91cc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c91d0:	2c890001 */ 	sltiu	$t1,$a0,0x1
/*  f0c91d4:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0c91d8:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f0c91dc:	ac64fffc */ 	sw	$a0,-0x4($v1)
/*  f0c91e0:	1616ffec */ 	bne	$s0,$s6,.L0f0c9194
/*  f0c91e4:	ace9fffc */ 	sw	$t1,-0x4($a3)
.L0f0c91e8:
/*  f0c91e8:	00165080 */ 	sll	$t2,$s6,0x2
/*  f0c91ec:	03aa5821 */ 	addu	$t3,$sp,$t2
/*  f0c91f0:	8d6b0148 */ 	lw	$t3,0x148($t3)
/*  f0c91f4:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0c91f8:	ad8b0120 */ 	sw	$t3,0x120($t4)
.L0f0c91fc:
/*  f0c91fc:	0fc5b364 */ 	jal	getVar80084014
/*  f0c9200:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c9204:	54400243 */ 	bnezl	$v0,.L0f0c9b14
/*  f0c9208:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c920c:	8e4d0288 */ 	lw	$t5,0x288($s2)
/*  f0c9210:	0fc549fb */ 	jal	optionsGetAimControl
/*  f0c9214:	8da40070 */ 	lw	$a0,0x70($t5)
/*  f0c9218:	1040001f */ 	beqz	$v0,.L0f0c9298
/*  f0c921c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c9220:	1ac0001d */ 	blez	$s6,.L0f0c9298
/*  f0c9224:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c9228:	27a3014c */ 	addiu	$v1,$sp,0x14c
/*  f0c922c:	27a700fc */ 	addiu	$a3,$sp,0xfc
.L0f0c9230:
/*  f0c9230:	12e00010 */ 	beqz	$s7,.L0f0c9274
/*  f0c9234:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9238:	97af00ec */ 	lhu	$t7,0xec($sp)
/*  f0c923c:	00112e00 */ 	sll	$a1,$s1,0x18
/*  f0c9240:	00057603 */ 	sra	$t6,$a1,0x18
/*  f0c9244:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0c9248:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0c924c:	afa70048 */ 	sw	$a3,0x48($sp)
/*  f0c9250:	0c0052d4 */ 	jal	func00014b50
/*  f0c9254:	31e62000 */ 	andi	$a2,$t7,0x2000
/*  f0c9258:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0c925c:	10400005 */ 	beqz	$v0,.L0f0c9274
/*  f0c9260:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0c9264:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9268:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c926c:	2c990001 */ 	sltiu	$t9,$a0,0x1
/*  f0c9270:	acb90120 */ 	sw	$t9,0x120($a1)
.L0f0c9274:
/*  f0c9274:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c9278:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c927c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0c9280:	8d090120 */ 	lw	$t1,0x120($t0)
/*  f0c9284:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f0c9288:	2d2a0001 */ 	sltiu	$t2,$t1,0x1
/*  f0c928c:	aceafffc */ 	sw	$t2,-0x4($a3)
/*  f0c9290:	1616ffe7 */ 	bne	$s0,$s6,.L0f0c9230
/*  f0c9294:	ac69fffc */ 	sw	$t1,-0x4($v1)
.L0f0c9298:
/*  f0c9298:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0c929c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c92a0:	24010032 */ 	addiu	$at,$zero,0x32
/*  f0c92a4:	54410005 */ 	bnel	$v0,$at,.L0f0c92bc
/*  f0c92a8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c92ac:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0c92b0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0c92b4:	ad8b0120 */ 	sw	$t3,0x120($t4)
/*  f0c92b8:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c92bc:
/*  f0c92bc:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0c92c0:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c92c4:	2c8d0001 */ 	sltiu	$t5,$a0,0x1
/*  f0c92c8:	afad01b4 */ 	sw	$t5,0x1b4($sp)
/*  f0c92cc:	8cae0120 */ 	lw	$t6,0x120($a1)
/*  f0c92d0:	afae01b8 */ 	sw	$t6,0x1b8($sp)
/*  f0c92d4:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c92d8:	afa001d4 */ 	sw	$zero,0x1d4($sp)
/*  f0c92dc:	afa001d8 */ 	sw	$zero,0x1d8($sp)
/*  f0c92e0:	2c8f0001 */ 	sltiu	$t7,$a0,0x1
/*  f0c92e4:	afaf022c */ 	sw	$t7,0x22c($sp)
/*  f0c92e8:	afa001dc */ 	sw	$zero,0x1dc($sp)
/*  f0c92ec:	afa001e0 */ 	sw	$zero,0x1e0($sp)
/*  f0c92f0:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c92f4:	afb901c8 */ 	sw	$t9,0x1c8($sp)
/*  f0c92f8:	2c980001 */ 	sltiu	$t8,$a0,0x1
/*  f0c92fc:	afb801c4 */ 	sw	$t8,0x1c4($sp)
/*  f0c9300:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9304:	2c880001 */ 	sltiu	$t0,$a0,0x1
/*  f0c9308:	afa801cc */ 	sw	$t0,0x1cc($sp)
/*  f0c930c:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9310:	2c890001 */ 	sltiu	$t1,$a0,0x1
/*  f0c9314:	afa901d0 */ 	sw	$t1,0x1d0($sp)
/*  f0c9318:	8caa0120 */ 	lw	$t2,0x120($a1)
/*  f0c931c:	51400015 */ 	beqzl	$t2,.L0f0c9374
/*  f0c9320:	44809000 */ 	mtc1	$zero,$f18
/*  f0c9324:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0c9328:	2881003d */ 	slti	$at,$a0,0x3d
/*  f0c932c:	14200010 */ 	bnez	$at,.L0f0c9370
/*  f0c9330:	248bffc4 */ 	addiu	$t3,$a0,-60
/*  f0c9334:	448b2000 */ 	mtc1	$t3,$f4
/*  f0c9338:	3c014120 */ 	lui	$at,0x4120
/*  f0c933c:	44811000 */ 	mtc1	$at,$f2
/*  f0c9340:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c9344:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9348:	44815000 */ 	mtc1	$at,$f10
/*  f0c934c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9350:	46023203 */ 	div.s	$f8,$f6,$f2
/*  f0c9354:	4608503c */ 	c.lt.s	$f10,$f8
/*  f0c9358:	e7a801ec */ 	swc1	$f8,0x1ec($sp)
/*  f0c935c:	45020009 */ 	bc1fl	.L0f0c9384
/*  f0c9360:	8cac0120 */ 	lw	$t4,0x120($a1)
/*  f0c9364:	44818000 */ 	mtc1	$at,$f16
/*  f0c9368:	10000005 */ 	beqz	$zero,.L0f0c9380
/*  f0c936c:	e7b001ec */ 	swc1	$f16,0x1ec($sp)
.L0f0c9370:
/*  f0c9370:	44809000 */ 	mtc1	$zero,$f18
.L0f0c9374:
/*  f0c9374:	3c014120 */ 	lui	$at,0x4120
/*  f0c9378:	44811000 */ 	mtc1	$at,$f2
/*  f0c937c:	e7b201ec */ 	swc1	$f18,0x1ec($sp)
.L0f0c9380:
/*  f0c9380:	8cac0120 */ 	lw	$t4,0x120($a1)
.L0f0c9384:
/*  f0c9384:	51800014 */ 	beqzl	$t4,.L0f0c93d8
/*  f0c9388:	44809000 */ 	mtc1	$zero,$f18
/*  f0c938c:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0c9390:	240dffc4 */ 	addiu	$t5,$zero,-60
/*  f0c9394:	2881ffc4 */ 	slti	$at,$a0,-60
/*  f0c9398:	1020000e */ 	beqz	$at,.L0f0c93d4
/*  f0c939c:	01a47023 */ 	subu	$t6,$t5,$a0
/*  f0c93a0:	448e2000 */ 	mtc1	$t6,$f4
/*  f0c93a4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c93a8:	44814000 */ 	mtc1	$at,$f8
/*  f0c93ac:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c93b0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c93b4:	46023283 */ 	div.s	$f10,$f6,$f2
/*  f0c93b8:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0c93bc:	e7aa01f0 */ 	swc1	$f10,0x1f0($sp)
/*  f0c93c0:	45020008 */ 	bc1fl	.L0f0c93e4
/*  f0c93c4:	8caf0120 */ 	lw	$t7,0x120($a1)
/*  f0c93c8:	44818000 */ 	mtc1	$at,$f16
/*  f0c93cc:	10000004 */ 	beqz	$zero,.L0f0c93e0
/*  f0c93d0:	e7b001f0 */ 	swc1	$f16,0x1f0($sp)
.L0f0c93d4:
/*  f0c93d4:	44809000 */ 	mtc1	$zero,$f18
.L0f0c93d8:
/*  f0c93d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c93dc:	e7b201f0 */ 	swc1	$f18,0x1f0($sp)
.L0f0c93e0:
/*  f0c93e0:	8caf0120 */ 	lw	$t7,0x120($a1)
.L0f0c93e4:
/*  f0c93e4:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0c93e8:	11e00011 */ 	beqz	$t7,.L0f0c9430
/*  f0c93ec:	2861ffc4 */ 	slti	$at,$v1,-60
/*  f0c93f0:	1020000f */ 	beqz	$at,.L0f0c9430
/*  f0c93f4:	2418ffc4 */ 	addiu	$t8,$zero,-60
/*  f0c93f8:	0303c823 */ 	subu	$t9,$t8,$v1
/*  f0c93fc:	44992000 */ 	mtc1	$t9,$f4
/*  f0c9400:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9404:	44814000 */ 	mtc1	$at,$f8
/*  f0c9408:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c940c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9410:	46023303 */ 	div.s	$f12,$f6,$f2
/*  f0c9414:	460c403c */ 	c.lt.s	$f8,$f12
/*  f0c9418:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
/*  f0c941c:	45020008 */ 	bc1fl	.L0f0c9440
/*  f0c9420:	8ca80120 */ 	lw	$t0,0x120($a1)
/*  f0c9424:	44816000 */ 	mtc1	$at,$f12
/*  f0c9428:	10000004 */ 	beqz	$zero,.L0f0c943c
/*  f0c942c:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
.L0f0c9430:
/*  f0c9430:	44806000 */ 	mtc1	$zero,$f12
/*  f0c9434:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c9438:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
.L0f0c943c:
/*  f0c943c:	8ca80120 */ 	lw	$t0,0x120($a1)
.L0f0c9440:
/*  f0c9440:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0c9444:	11000010 */ 	beqz	$t0,.L0f0c9488
/*  f0c9448:	2861003d */ 	slti	$at,$v1,0x3d
/*  f0c944c:	1420000e */ 	bnez	$at,.L0f0c9488
/*  f0c9450:	2469ffc4 */ 	addiu	$t1,$v1,-60
/*  f0c9454:	44895000 */ 	mtc1	$t1,$f10
/*  f0c9458:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c945c:	44819000 */ 	mtc1	$at,$f18
/*  f0c9460:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0c9464:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9468:	46028003 */ 	div.s	$f0,$f16,$f2
/*  f0c946c:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0c9470:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
/*  f0c9474:	45000007 */ 	bc1f	.L0f0c9494
/*  f0c9478:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c947c:	44810000 */ 	mtc1	$at,$f0
/*  f0c9480:	10000004 */ 	beqz	$zero,.L0f0c9494
/*  f0c9484:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
.L0f0c9488:
/*  f0c9488:	44800000 */ 	mtc1	$zero,$f0
/*  f0c948c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c9490:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
.L0f0c9494:
/*  f0c9494:	12e0005c */ 	beqz	$s7,.L0f0c9608
/*  f0c9498:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c949c:	84a2024c */ 	lh	$v0,0x24c($a1)
/*  f0c94a0:	2841fffe */ 	slti	$at,$v0,-2
/*  f0c94a4:	10200009 */ 	beqz	$at,.L0f0c94cc
/*  f0c94a8:	00565021 */ 	addu	$t2,$v0,$s6
/*  f0c94ac:	a4aa024c */ 	sh	$t2,0x24c($a1)
/*  f0c94b0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c94b4:	84ab024c */ 	lh	$t3,0x24c($a1)
/*  f0c94b8:	2961fffe */ 	slti	$at,$t3,-2
/*  f0c94bc:	14200052 */ 	bnez	$at,.L0f0c9608
/*  f0c94c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c94c4:	10000050 */ 	beqz	$zero,.L0f0c9608
/*  f0c94c8:	a4a0024c */ 	sh	$zero,0x24c($a1)
.L0f0c94cc:
/*  f0c94cc:	1ac0004e */ 	blez	$s6,.L0f0c9608
/*  f0c94d0:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c94d4:	97ac019e */ 	lhu	$t4,0x19e($sp)
/*  f0c94d8:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f0c94dc:	31918000 */ 	andi	$s1,$t4,0x8000
/*  f0c94e0:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0c94e4:
/*  f0c94e4:	00057603 */ 	sra	$t6,$a1,0x18
/*  f0c94e8:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0c94ec:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c94f0:	0c00529e */ 	jal	func00014a78
/*  f0c94f4:	3226ffff */ 	andi	$a2,$s1,0xffff
/*  f0c94f8:	14400009 */ 	bnez	$v0,.L0f0c9520
/*  f0c94fc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9500:	97b800da */ 	lhu	$t8,0xda($sp)
/*  f0c9504:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c9508:	00057e03 */ 	sra	$t7,$a1,0x18
/*  f0c950c:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0c9510:	0c00529e */ 	jal	func00014a78
/*  f0c9514:	33068000 */ 	andi	$a2,$t8,0x8000
/*  f0c9518:	50400028 */ 	beqzl	$v0,.L0f0c95bc
/*  f0c951c:	8e490284 */ 	lw	$t1,0x284($s2)
.L0f0c9520:
/*  f0c9520:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c9524:	97aa00ea */ 	lhu	$t2,0xea($sp)
/*  f0c9528:	8509024c */ 	lh	$t1,0x24c($t0)
/*  f0c952c:	31462000 */ 	andi	$a2,$t2,0x2000
/*  f0c9530:	2921ffff */ 	slti	$at,$t1,-1
/*  f0c9534:	14200031 */ 	bnez	$at,.L0f0c95fc
/*  f0c9538:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c953c:	83a500ef */ 	lb	$a1,0xef($sp)
/*  f0c9540:	0c0052d4 */ 	jal	func00014b50
/*  f0c9544:	afa6004c */ 	sw	$a2,0x4c($sp)
/*  f0c9548:	10400006 */ 	beqz	$v0,.L0f0c9564
/*  f0c954c:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0c9550:	8fac01fc */ 	lw	$t4,0x1fc($sp)
/*  f0c9554:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c9558:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f0c955c:	afad01fc */ 	sw	$t5,0x1fc($sp)
/*  f0c9560:	a5d3024c */ 	sh	$s3,0x24c($t6)
.L0f0c9564:
/*  f0c9564:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0c9568:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c956c:	85f8024c */ 	lh	$t8,0x24c($t7)
/*  f0c9570:	07020023 */ 	bltzl	$t8,.L0f0c9600
/*  f0c9574:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c9578:	0c00529e */ 	jal	func00014a78
/*  f0c957c:	83a500ef */ 	lb	$a1,0xef($sp)
/*  f0c9580:	5440001f */ 	bnezl	$v0,.L0f0c9600
/*  f0c9584:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c9588:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c958c:	84a2024c */ 	lh	$v0,0x24c($a1)
/*  f0c9590:	28410010 */ 	slti	$at,$v0,0x10
/*  f0c9594:	14200006 */ 	bnez	$at,.L0f0c95b0
/*  f0c9598:	24480001 */ 	addiu	$t0,$v0,0x1
/*  f0c959c:	0fc3fbda */ 	jal	activemenuOpen
/*  f0c95a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c95a4:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0c95a8:	10000014 */ 	beqz	$zero,.L0f0c95fc
/*  f0c95ac:	a733024c */ 	sh	$s3,0x24c($t9)
.L0f0c95b0:
/*  f0c95b0:	10000012 */ 	beqz	$zero,.L0f0c95fc
/*  f0c95b4:	a4a8024c */ 	sh	$t0,0x24c($a1)
/*  f0c95b8:	8e490284 */ 	lw	$t1,0x284($s2)
.L0f0c95bc:
/*  f0c95bc:	852a024c */ 	lh	$t2,0x24c($t1)
/*  f0c95c0:	5940000d */ 	blezl	$t2,.L0f0c95f8
/*  f0c95c4:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0c95c8:	12e00007 */ 	beqz	$s7,.L0f0c95e8
/*  f0c95cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c95d0:	97ab00ea */ 	lhu	$t3,0xea($sp)
/*  f0c95d4:	83a500ef */ 	lb	$a1,0xef($sp)
/*  f0c95d8:	0c00529e */ 	jal	func00014a78
/*  f0c95dc:	31662000 */ 	andi	$a2,$t3,0x2000
/*  f0c95e0:	54400005 */ 	bnezl	$v0,.L0f0c95f8
/*  f0c95e4:	8e4d0284 */ 	lw	$t5,0x284($s2)
.L0f0c95e8:
/*  f0c95e8:	8fa20200 */ 	lw	$v0,0x200($sp)
/*  f0c95ec:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c95f0:	afa20200 */ 	sw	$v0,0x200($sp)
/*  f0c95f4:	8e4d0284 */ 	lw	$t5,0x284($s2)
.L0f0c95f8:
/*  f0c95f8:	a5a0024c */ 	sh	$zero,0x24c($t5)
.L0f0c95fc:
/*  f0c95fc:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0c9600:
/*  f0c9600:	5616ffb8 */ 	bnel	$s0,$s6,.L0f0c94e4
/*  f0c9604:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0c9608:
/*  f0c9608:	12e0005e */ 	beqz	$s7,.L0f0c9784
/*  f0c960c:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f0c9610:	1ac0005c */ 	blez	$s6,.L0f0c9784
/*  f0c9614:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c9618:	97ae019e */ 	lhu	$t6,0x19e($sp)
/*  f0c961c:	31cf4000 */ 	andi	$t7,$t6,0x4000
/*  f0c9620:	afaf0044 */ 	sw	$t7,0x44($sp)
/*  f0c9624:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0c9628:
/*  f0c9628:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f0c962c:	8fa60044 */ 	lw	$a2,0x44($sp)
/*  f0c9630:	03002825 */ 	or	$a1,$t8,$zero
/*  f0c9634:	0c00529e */ 	jal	func00014a78
/*  f0c9638:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c963c:	14400009 */ 	bnez	$v0,.L0f0c9664
/*  f0c9640:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9644:	97a800da */ 	lhu	$t0,0xda($sp)
/*  f0c9648:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c964c:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f0c9650:	03202825 */ 	or	$a1,$t9,$zero
/*  f0c9654:	0c00529e */ 	jal	func00014a78
/*  f0c9658:	31064000 */ 	andi	$a2,$t0,0x4000
/*  f0c965c:	5040003e */ 	beqzl	$v0,.L0f0c9758
/*  f0c9660:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9664:
/*  f0c9664:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0c9668:	97ab00ea */ 	lhu	$t3,0xea($sp)
/*  f0c966c:	83a500ef */ 	lb	$a1,0xef($sp)
/*  f0c9670:	8544024e */ 	lh	$a0,0x24e($t2)
/*  f0c9674:	31662000 */ 	andi	$a2,$t3,0x2000
/*  f0c9678:	2881ffff */ 	slti	$at,$a0,-1
/*  f0c967c:	5420002f */ 	bnezl	$at,.L0f0c973c
/*  f0c9680:	2881fffe */ 	slti	$at,$a0,-2
/*  f0c9684:	0c0052d4 */ 	jal	func00014b50
/*  f0c9688:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c968c:	5040000e */ 	beqzl	$v0,.L0f0c96c8
/*  f0c9690:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9694:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0c9698:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0c969c:	85a4024e */ 	lh	$a0,0x24e($t5)
/*  f0c96a0:	04820009 */ 	bltzl	$a0,.L0f0c96c8
/*  f0c96a4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c96a8:	0fc2a257 */ 	jal	func0f0a895c
/*  f0c96ac:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c96b0:	50400005 */ 	beqzl	$v0,.L0f0c96c8
/*  f0c96b4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c96b8:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0c96bc:	240efffd */ 	addiu	$t6,$zero,-3
/*  f0c96c0:	a5ee024e */ 	sh	$t6,0x24e($t7)
/*  f0c96c4:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c96c8:
/*  f0c96c8:	84a4024e */ 	lh	$a0,0x24e($a1)
/*  f0c96cc:	0480002a */ 	bltz	$a0,.L0f0c9778
/*  f0c96d0:	2881001a */ 	slti	$at,$a0,0x1a
/*  f0c96d4:	14200016 */ 	bnez	$at,.L0f0c9730
/*  f0c96d8:	248b0001 */ 	addiu	$t3,$a0,0x1
/*  f0c96dc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c96e0:	0fc2a257 */ 	jal	func0f0a895c
/*  f0c96e4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c96e8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c96ec:	54410005 */ 	bnel	$v0,$at,.L0f0c9704
/*  f0c96f0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0c96f4:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0c96f8:	1000001f */ 	beqz	$zero,.L0f0c9778
/*  f0c96fc:	a713024e */ 	sh	$s3,0x24e($t8)
/*  f0c9700:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0c9704:
/*  f0c9704:	54410006 */ 	bnel	$v0,$at,.L0f0c9720
/*  f0c9708:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c970c:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c9710:	2419fffe */ 	addiu	$t9,$zero,-2
/*  f0c9714:	10000018 */ 	beqz	$zero,.L0f0c9778
/*  f0c9718:	a519024e */ 	sh	$t9,0x24e($t0)
/*  f0c971c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9720:
/*  f0c9720:	84a9024e */ 	lh	$t1,0x24e($a1)
/*  f0c9724:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f0c9728:	10000013 */ 	beqz	$zero,.L0f0c9778
/*  f0c972c:	a4aa024e */ 	sh	$t2,0x24e($a1)
.L0f0c9730:
/*  f0c9730:	10000011 */ 	beqz	$zero,.L0f0c9778
/*  f0c9734:	a4ab024e */ 	sh	$t3,0x24e($a1)
/*  f0c9738:	2881fffe */ 	slti	$at,$a0,-2
.L0f0c973c:
/*  f0c973c:	1420000e */ 	bnez	$at,.L0f0c9778
/*  f0c9740:	00002825 */ 	or	$a1,$zero,$zero
/*  f0c9744:	0fc2a257 */ 	jal	func0f0a895c
/*  f0c9748:	00003025 */ 	or	$a2,$zero,$zero
/*  f0c974c:	1000000b */ 	beqz	$zero,.L0f0c977c
/*  f0c9750:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c9754:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9758:
/*  f0c9758:	8fad01c0 */ 	lw	$t5,0x1c0($sp)
/*  f0c975c:	84ac024e */ 	lh	$t4,0x24e($a1)
/*  f0c9760:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f0c9764:	19800002 */ 	blez	$t4,.L0f0c9770
/*  f0c9768:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c976c:	afae01c0 */ 	sw	$t6,0x1c0($sp)
.L0f0c9770:
/*  f0c9770:	0fc2a314 */ 	jal	func0f0a8c50
/*  f0c9774:	a4a0024e */ 	sh	$zero,0x24e($a1)
.L0f0c9778:
/*  f0c9778:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0c977c:
/*  f0c977c:	5616ffaa */ 	bnel	$s0,$s6,.L0f0c9628
/*  f0c9780:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0c9784:
/*  f0c9784:	8faf01a8 */ 	lw	$t7,0x1a8($sp)
/*  f0c9788:	11e0002b */ 	beqz	$t7,.L0f0c9838
/*  f0c978c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c9790:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0c9794:	8fa800dc */ 	lw	$t0,0xdc($sp)
/*  f0c9798:	8f190120 */ 	lw	$t9,0x120($t8)
/*  f0c979c:	13200026 */ 	beqz	$t9,.L0f0c9838
/*  f0c97a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c97a4:	05010011 */ 	bgez	$t0,.L0f0c97ec
/*  f0c97a8:	00084823 */ 	negu	$t1,$t0
/*  f0c97ac:	44892000 */ 	mtc1	$t1,$f4
/*  f0c97b0:	3c01428c */ 	lui	$at,0x428c
/*  f0c97b4:	44814000 */ 	mtc1	$at,$f8
/*  f0c97b8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0c97bc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c97c0:	44815000 */ 	mtc1	$at,$f10
/*  f0c97c4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c97c8:	46083303 */ 	div.s	$f12,$f6,$f8
/*  f0c97cc:	460c503c */ 	c.lt.s	$f10,$f12
/*  f0c97d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c97d4:	45020004 */ 	bc1fl	.L0f0c97e8
/*  f0c97d8:	460c6300 */ 	add.s	$f12,$f12,$f12
/*  f0c97dc:	44816000 */ 	mtc1	$at,$f12
/*  f0c97e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c97e4:	460c6300 */ 	add.s	$f12,$f12,$f12
.L0f0c97e8:
/*  f0c97e8:	e7ac0210 */ 	swc1	$f12,0x210($sp)
.L0f0c97ec:
/*  f0c97ec:	8faa00dc */ 	lw	$t2,0xdc($sp)
/*  f0c97f0:	19400011 */ 	blez	$t2,.L0f0c9838
/*  f0c97f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c97f8:	448a8000 */ 	mtc1	$t2,$f16
/*  f0c97fc:	3c01428c */ 	lui	$at,0x428c
/*  f0c9800:	44812000 */ 	mtc1	$at,$f4
/*  f0c9804:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0c9808:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c980c:	44813000 */ 	mtc1	$at,$f6
/*  f0c9810:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9814:	46049303 */ 	div.s	$f12,$f18,$f4
/*  f0c9818:	460c303c */ 	c.lt.s	$f6,$f12
/*  f0c981c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c9820:	45020004 */ 	bc1fl	.L0f0c9834
/*  f0c9824:	460c6300 */ 	add.s	$f12,$f12,$f12
/*  f0c9828:	44816000 */ 	mtc1	$at,$f12
/*  f0c982c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c9830:	460c6300 */ 	add.s	$f12,$f12,$f12
.L0f0c9834:
/*  f0c9834:	e7ac0214 */ 	swc1	$f12,0x214($sp)
.L0f0c9838:
/*  f0c9838:	12e0005a */ 	beqz	$s7,.L0f0c99a4
/*  f0c983c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c9840:	1ac00058 */ 	blez	$s6,.L0f0c99a4
/*  f0c9844:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c9848:	8fab01a8 */ 	lw	$t3,0x1a8($sp)
.L0f0c984c:
/*  f0c984c:	00106080 */ 	sll	$t4,$s0,0x2
/*  f0c9850:	03ac6821 */ 	addu	$t5,$sp,$t4
/*  f0c9854:	55600034 */ 	bnezl	$t3,.L0f0c9928
/*  f0c9858:	8e4a0288 */ 	lw	$t2,0x288($s2)
/*  f0c985c:	8dad014c */ 	lw	$t5,0x14c($t5)
/*  f0c9860:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c9864:	00057603 */ 	sra	$t6,$a1,0x18
/*  f0c9868:	11a0002e */ 	beqz	$t5,.L0f0c9924
/*  f0c986c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9870:	0c005241 */ 	jal	func00014904
/*  f0c9874:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0c9878:	2841001f */ 	slti	$at,$v0,0x1f
/*  f0c987c:	14200011 */ 	bnez	$at,.L0f0c98c4
/*  f0c9880:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9884:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c9888:	00057e03 */ 	sra	$t7,$a1,0x18
/*  f0c988c:	0c005270 */ 	jal	func000149c0
/*  f0c9890:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0c9894:	2841001f */ 	slti	$at,$v0,0x1f
/*  f0c9898:	1020000a */ 	beqz	$at,.L0f0c98c4
/*  f0c989c:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0c98a0:	10400003 */ 	beqz	$v0,.L0f0c98b0
/*  f0c98a4:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0c98a8:	10000004 */ 	beqz	$zero,.L0f0c98bc
/*  f0c98ac:	afa20218 */ 	sw	$v0,0x218($sp)
.L0f0c98b0:
/*  f0c98b0:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0c98b4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c98b8:	afa2021c */ 	sw	$v0,0x21c($sp)
.L0f0c98bc:
/*  f0c98bc:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0c98c0:	af130260 */ 	sw	$s3,0x260($t8)
.L0f0c98c4:
/*  f0c98c4:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c98c8:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f0c98cc:	03202825 */ 	or	$a1,$t9,$zero
/*  f0c98d0:	0c005241 */ 	jal	func00014904
/*  f0c98d4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c98d8:	2841ffe2 */ 	slti	$at,$v0,-30
/*  f0c98dc:	10200011 */ 	beqz	$at,.L0f0c9924
/*  f0c98e0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c98e4:	00142e00 */ 	sll	$a1,$s4,0x18
/*  f0c98e8:	00054603 */ 	sra	$t0,$a1,0x18
/*  f0c98ec:	0c005270 */ 	jal	func000149c0
/*  f0c98f0:	01002825 */ 	or	$a1,$t0,$zero
/*  f0c98f4:	2841ffe2 */ 	slti	$at,$v0,-30
/*  f0c98f8:	1420000a */ 	bnez	$at,.L0f0c9924
/*  f0c98fc:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0c9900:	10400003 */ 	beqz	$v0,.L0f0c9910
/*  f0c9904:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0c9908:	10000004 */ 	beqz	$zero,.L0f0c991c
/*  f0c990c:	afa2021c */ 	sw	$v0,0x21c($sp)
.L0f0c9910:
/*  f0c9910:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0c9914:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c9918:	afa20218 */ 	sw	$v0,0x218($sp)
.L0f0c991c:
/*  f0c991c:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0c9920:	ad330260 */ 	sw	$s3,0x260($t1)
.L0f0c9924:
/*  f0c9924:	8e4a0288 */ 	lw	$t2,0x288($s2)
.L0f0c9928:
/*  f0c9928:	0fc549fb */ 	jal	optionsGetAimControl
/*  f0c992c:	8d440070 */ 	lw	$a0,0x70($t2)
/*  f0c9930:	14400019 */ 	bnez	$v0,.L0f0c9998
/*  f0c9934:	00105880 */ 	sll	$t3,$s0,0x2
/*  f0c9938:	03ab6021 */ 	addu	$t4,$sp,$t3
/*  f0c993c:	8d8c014c */ 	lw	$t4,0x14c($t4)
/*  f0c9940:	51800008 */ 	beqzl	$t4,.L0f0c9964
/*  f0c9944:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9948:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c994c:	8ca20260 */ 	lw	$v0,0x260($a1)
/*  f0c9950:	04400011 */ 	bltz	$v0,.L0f0c9998
/*  f0c9954:	244d0001 */ 	addiu	$t5,$v0,0x1
/*  f0c9958:	1000000f */ 	beqz	$zero,.L0f0c9998
/*  f0c995c:	acad0260 */ 	sw	$t5,0x260($a1)
/*  f0c9960:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9964:
/*  f0c9964:	8ca20260 */ 	lw	$v0,0x260($a1)
/*  f0c9968:	1840000a */ 	blez	$v0,.L0f0c9994
/*  f0c996c:	2841000f */ 	slti	$at,$v0,0xf
/*  f0c9970:	10200008 */ 	beqz	$at,.L0f0c9994
/*  f0c9974:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0c9978:	10400003 */ 	beqz	$v0,.L0f0c9988
/*  f0c997c:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0c9980:	10000004 */ 	beqz	$zero,.L0f0c9994
/*  f0c9984:	afa20218 */ 	sw	$v0,0x218($sp)
.L0f0c9988:
/*  f0c9988:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0c998c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0c9990:	afa2021c */ 	sw	$v0,0x21c($sp)
.L0f0c9994:
/*  f0c9994:	aca00260 */ 	sw	$zero,0x260($a1)
.L0f0c9998:
/*  f0c9998:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c999c:	5616ffab */ 	bnel	$s0,$s6,.L0f0c984c
/*  f0c99a0:	8fab01a8 */ 	lw	$t3,0x1a8($sp)
.L0f0c99a4:
/*  f0c99a4:	0fc331a0 */ 	jal	currentPlayerGetCrouchPos
/*  f0c99a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c99ac:	1440001d */ 	bnez	$v0,.L0f0c9a24
/*  f0c99b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c99b4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c99b8:	3c01c2b4 */ 	lui	$at,0xc2b4
/*  f0c99bc:	44814000 */ 	mtc1	$at,$f8
/*  f0c99c0:	c4aa00b4 */ 	lwc1	$f10,0xb4($a1)
/*  f0c99c4:	460a4032 */ 	c.eq.s	$f8,$f10
/*  f0c99c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c99cc:	45000015 */ 	bc1f	.L0f0c9a24
/*  f0c99d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c99d4:	8e4e0314 */ 	lw	$t6,0x314($s2)
/*  f0c99d8:	11c00012 */ 	beqz	$t6,.L0f0c9a24
/*  f0c99dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c99e0:	8e4f0298 */ 	lw	$t7,0x298($s2)
/*  f0c99e4:	05e1000f */ 	bgez	$t7,.L0f0c9a24
/*  f0c99e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c99ec:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c99f0:	8fa201a8 */ 	lw	$v0,0x1a8($sp)
/*  f0c99f4:	0004c02b */ 	sltu	$t8,$zero,$a0
/*  f0c99f8:	13000009 */ 	beqz	$t8,.L0f0c9a20
/*  f0c99fc:	03002025 */ 	or	$a0,$t8,$zero
/*  f0c9a00:	2c440001 */ 	sltiu	$a0,$v0,0x1
/*  f0c9a04:	50800007 */ 	beqzl	$a0,.L0f0c9a24
/*  f0c9a08:	afa40234 */ 	sw	$a0,0x234($sp)
/*  f0c9a0c:	00142600 */ 	sll	$a0,$s4,0x18
/*  f0c9a10:	00044603 */ 	sra	$t0,$a0,0x18
/*  f0c9a14:	0c0053ae */ 	jal	func00014eb8
/*  f0c9a18:	01002025 */ 	or	$a0,$t0,$zero
/*  f0c9a1c:	2844ffe2 */ 	slti	$a0,$v0,-30
.L0f0c9a20:
/*  f0c9a20:	afa40234 */ 	sw	$a0,0x234($sp)
.L0f0c9a24:
/*  f0c9a24:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0c9a28:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c9a2c:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0c9a30:	54410011 */ 	bnel	$v0,$at,.L0f0c9a78
/*  f0c9a34:	97a201a2 */ 	lhu	$v0,0x1a2($sp)
/*  f0c9a38:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9a3c:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0c9a40:	50400004 */ 	beqzl	$v0,.L0f0c9a54
/*  f0c9a44:	0002202b */ 	sltu	$a0,$zero,$v0
/*  f0c9a48:	afa001c8 */ 	sw	$zero,0x1c8($sp)
/*  f0c9a4c:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0c9a50:	0002202b */ 	sltu	$a0,$zero,$v0
.L0f0c9a54:
/*  f0c9a54:	10800006 */ 	beqz	$a0,.L0f0c9a70
/*  f0c9a58:	83a900e9 */ 	lb	$t1,0xe9($sp)
/*  f0c9a5c:	2924ffe2 */ 	slti	$a0,$t1,-30
/*  f0c9a60:	54800004 */ 	bnezl	$a0,.L0f0c9a74
/*  f0c9a64:	afa40230 */ 	sw	$a0,0x230($sp)
/*  f0c9a68:	2924001f */ 	slti	$a0,$t1,0x1f
/*  f0c9a6c:	38840001 */ 	xori	$a0,$a0,0x1
.L0f0c9a70:
/*  f0c9a70:	afa40230 */ 	sw	$a0,0x230($sp)
.L0f0c9a74:
/*  f0c9a74:	97a201a2 */ 	lhu	$v0,0x1a2($sp)
.L0f0c9a78:
/*  f0c9a78:	afa00220 */ 	sw	$zero,0x220($sp)
/*  f0c9a7c:	afa00224 */ 	sw	$zero,0x224($sp)
/*  f0c9a80:	304a8000 */ 	andi	$t2,$v0,0x8000
/*  f0c9a84:	11400003 */ 	beqz	$t2,.L0f0c9a94
/*  f0c9a88:	97ab01a0 */ 	lhu	$t3,0x1a0($sp)
/*  f0c9a8c:	316c4000 */ 	andi	$t4,$t3,0x4000
/*  f0c9a90:	15800012 */ 	bnez	$t4,.L0f0c9adc
.L0f0c9a94:
/*  f0c9a94:	304d4000 */ 	andi	$t5,$v0,0x4000
/*  f0c9a98:	11a00004 */ 	beqz	$t5,.L0f0c9aac
/*  f0c9a9c:	97ae01a0 */ 	lhu	$t6,0x1a0($sp)
/*  f0c9aa0:	31cf8000 */ 	andi	$t7,$t6,0x8000
/*  f0c9aa4:	55e0000e */ 	bnezl	$t7,.L0f0c9ae0
/*  f0c9aa8:	8fac01ac */ 	lw	$t4,0x1ac($sp)
.L0f0c9aac:
/*  f0c9aac:	97a200e6 */ 	lhu	$v0,0xe6($sp)
/*  f0c9ab0:	97b900e4 */ 	lhu	$t9,0xe4($sp)
/*  f0c9ab4:	30588000 */ 	andi	$t8,$v0,0x8000
/*  f0c9ab8:	13000002 */ 	beqz	$t8,.L0f0c9ac4
/*  f0c9abc:	33284000 */ 	andi	$t0,$t9,0x4000
/*  f0c9ac0:	15000006 */ 	bnez	$t0,.L0f0c9adc
.L0f0c9ac4:
/*  f0c9ac4:	30494000 */ 	andi	$t1,$v0,0x4000
/*  f0c9ac8:	11200011 */ 	beqz	$t1,.L0f0c9b10
/*  f0c9acc:	97aa00e4 */ 	lhu	$t2,0xe4($sp)
/*  f0c9ad0:	314b8000 */ 	andi	$t3,$t2,0x8000
/*  f0c9ad4:	5160000f */ 	beqzl	$t3,.L0f0c9b14
/*  f0c9ad8:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9adc:
/*  f0c9adc:	8fac01ac */ 	lw	$t4,0x1ac($sp)
.L0f0c9ae0:
/*  f0c9ae0:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0c9ae4:	2402fffe */ 	addiu	$v0,$zero,-2
/*  f0c9ae8:	15810009 */ 	bne	$t4,$at,.L0f0c9b10
/*  f0c9aec:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0c9af0:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c9af4:	afad0228 */ 	sw	$t5,0x228($sp)
/*  f0c9af8:	afa001fc */ 	sw	$zero,0x1fc($sp)
/*  f0c9afc:	afa00200 */ 	sw	$zero,0x200($sp)
/*  f0c9b00:	afa001c0 */ 	sw	$zero,0x1c0($sp)
/*  f0c9b04:	a5c2024c */ 	sh	$v0,0x24c($t6)
/*  f0c9b08:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0c9b0c:	a5e2024e */ 	sh	$v0,0x24e($t7)
.L0f0c9b10:
/*  f0c9b10:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9b14:
/*  f0c9b14:	97a900ea */ 	lhu	$t1,0xea($sp)
/*  f0c9b18:	8cb80120 */ 	lw	$t8,0x120($a1)
/*  f0c9b1c:	afb80208 */ 	sw	$t8,0x208($sp)
/*  f0c9b20:	8cb90120 */ 	lw	$t9,0x120($a1)
/*  f0c9b24:	afb9020c */ 	sw	$t9,0x20c($sp)
/*  f0c9b28:	8ca80274 */ 	lw	$t0,0x274($a1)
/*  f0c9b2c:	31252000 */ 	andi	$a1,$t1,0x2000
/*  f0c9b30:	11000007 */ 	beqz	$t0,.L0f0c9b50
/*  f0c9b34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c9b38:	0c0053d8 */ 	jal	func00014f60
/*  f0c9b3c:	83a400ef */ 	lb	$a0,0xef($sp)
/*  f0c9b40:	14400003 */ 	bnez	$v0,.L0f0c9b50
/*  f0c9b44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c9b48:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0c9b4c:	ad600274 */ 	sw	$zero,0x274($t3)
.L0f0c9b50:
/*  f0c9b50:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0c9b54:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c9b58:	00402025 */ 	or	$a0,$v0,$zero
/*  f0c9b5c:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0c9b60:	3c058000 */ 	lui	$a1,0x8000
/*  f0c9b64:	50400012 */ 	beqzl	$v0,.L0f0c9bb0
/*  f0c9b68:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c9b6c:	12e0000d */ 	beqz	$s7,.L0f0c9ba4
/*  f0c9b70:	97ac00ea */ 	lhu	$t4,0xea($sp)
/*  f0c9b74:	83a400ef */ 	lb	$a0,0xef($sp)
/*  f0c9b78:	0c005408 */ 	jal	func00015020
/*  f0c9b7c:	31852000 */ 	andi	$a1,$t4,0x2000
/*  f0c9b80:	10400008 */ 	beqz	$v0,.L0f0c9ba4
/*  f0c9b84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c9b88:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c9b8c:	8fb801c0 */ 	lw	$t8,0x1c0($sp)
/*  f0c9b90:	8dcf1a24 */ 	lw	$t7,0x1a24($t6)
/*  f0c9b94:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0c9b98:	15e00002 */ 	bnez	$t7,.L0f0c9ba4
/*  f0c9b9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c9ba0:	afb901c0 */ 	sw	$t9,0x1c0($sp)
.L0f0c9ba4:
/*  f0c9ba4:	1000001e */ 	beqz	$zero,.L0f0c9c20
/*  f0c9ba8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9bac:	8e480284 */ 	lw	$t0,0x284($s2)
.L0f0c9bb0:
/*  f0c9bb0:	8d040274 */ 	lw	$a0,0x274($t0)
/*  f0c9bb4:	2c890001 */ 	sltiu	$t1,$a0,0x1
/*  f0c9bb8:	11200017 */ 	beqz	$t1,.L0f0c9c18
/*  f0c9bbc:	01202025 */ 	or	$a0,$t1,$zero
/*  f0c9bc0:	12e00015 */ 	beqz	$s7,.L0f0c9c18
/*  f0c9bc4:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0c9bc8:	97aa00ea */ 	lhu	$t2,0xea($sp)
/*  f0c9bcc:	83a400ef */ 	lb	$a0,0xef($sp)
/*  f0c9bd0:	0c0053d8 */ 	jal	func00014f60
/*  f0c9bd4:	31452000 */ 	andi	$a1,$t2,0x2000
/*  f0c9bd8:	0002202b */ 	sltu	$a0,$zero,$v0
/*  f0c9bdc:	5080000f */ 	beqzl	$a0,.L0f0c9c1c
/*  f0c9be0:	afa401bc */ 	sw	$a0,0x1bc($sp)
/*  f0c9be4:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0c9be8:	97a201a2 */ 	lhu	$v0,0x1a2($sp)
/*  f0c9bec:	8d841a24 */ 	lw	$a0,0x1a24($t4)
/*  f0c9bf0:	304e8000 */ 	andi	$t6,$v0,0x8000
/*  f0c9bf4:	2c8d0001 */ 	sltiu	$t5,$a0,0x1
/*  f0c9bf8:	11a00007 */ 	beqz	$t5,.L0f0c9c18
/*  f0c9bfc:	01a02025 */ 	or	$a0,$t5,$zero
/*  f0c9c00:	2dc40001 */ 	sltiu	$a0,$t6,0x1
/*  f0c9c04:	50800005 */ 	beqzl	$a0,.L0f0c9c1c
/*  f0c9c08:	afa401bc */ 	sw	$a0,0x1bc($sp)
/*  f0c9c0c:	97a400e6 */ 	lhu	$a0,0xe6($sp)
/*  f0c9c10:	30988000 */ 	andi	$t8,$a0,0x8000
/*  f0c9c14:	2f040001 */ 	sltiu	$a0,$t8,0x1
.L0f0c9c18:
/*  f0c9c18:	afa401bc */ 	sw	$a0,0x1bc($sp)
.L0f0c9c1c:
/*  f0c9c1c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9c20:
/*  f0c9c20:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0c9c24:	1000032a */ 	beqz	$zero,.L0f0ca8d0
/*  f0c9c28:	afa8023c */ 	sw	$t0,0x23c($sp)
/*  f0c9c2c:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0c9c30:
/*  f0c9c30:	10410004 */ 	beq	$v0,$at,.L0f0c9c44
/*  f0c9c34:	34148000 */ 	dli	$s4,0x8000
/*  f0c9c38:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c9c3c:	14410005 */ 	bne	$v0,$at,.L0f0c9c54
/*  f0c9c40:	24110030 */ 	addiu	$s1,$zero,0x30
.L0f0c9c44:
/*  f0c9c44:	24090030 */ 	addiu	$t1,$zero,0x30
/*  f0c9c48:	24112000 */ 	addiu	$s1,$zero,0x2000
/*  f0c9c4c:	10000004 */ 	beqz	$zero,.L0f0c9c60
/*  f0c9c50:	a7a900ca */ 	sh	$t1,0xca($sp)
.L0f0c9c54:
/*  f0c9c54:	340a8000 */ 	dli	$t2,0x8000
/*  f0c9c58:	24142000 */ 	addiu	$s4,$zero,0x2000
/*  f0c9c5c:	a7aa00ca */ 	sh	$t2,0xca($sp)
.L0f0c9c60:
/*  f0c9c60:	8e4b0288 */ 	lw	$t3,0x288($s2)
/*  f0c9c64:	0fc549fb */ 	jal	optionsGetAimControl
/*  f0c9c68:	8d640070 */ 	lw	$a0,0x70($t3)
/*  f0c9c6c:	14400021 */ 	bnez	$v0,.L0f0c9cf4
/*  f0c9c70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c9c74:	1ac0001a */ 	blez	$s6,.L0f0c9ce0
/*  f0c9c78:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c9c7c:	27a3014c */ 	addiu	$v1,$sp,0x14c
/*  f0c9c80:	27a700fc */ 	addiu	$a3,$sp,0xfc
.L0f0c9c84:
/*  f0c9c84:	12e0000f */ 	beqz	$s7,.L0f0c9cc4
/*  f0c9c88:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0c9c8c:	97ad019e */ 	lhu	$t5,0x19e($sp)
/*  f0c9c90:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c9c94:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0c9c98:	022d3024 */ 	and	$a2,$s1,$t5
/*  f0c9c9c:	30ceffff */ 	andi	$t6,$a2,0xffff
/*  f0c9ca0:	01c03025 */ 	or	$a2,$t6,$zero
/*  f0c9ca4:	01802825 */ 	or	$a1,$t4,$zero
/*  f0c9ca8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9cac:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0c9cb0:	0c00529e */ 	jal	func00014a78
/*  f0c9cb4:	afa70048 */ 	sw	$a3,0x48($sp)
/*  f0c9cb8:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0c9cbc:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0c9cc0:	0002202b */ 	sltu	$a0,$zero,$v0
.L0f0c9cc4:
/*  f0c9cc4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c9cc8:	2c8f0001 */ 	sltiu	$t7,$a0,0x1
/*  f0c9ccc:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0c9cd0:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f0c9cd4:	ac64fffc */ 	sw	$a0,-0x4($v1)
/*  f0c9cd8:	1616ffea */ 	bne	$s0,$s6,.L0f0c9c84
/*  f0c9cdc:	aceffffc */ 	sw	$t7,-0x4($a3)
.L0f0c9ce0:
/*  f0c9ce0:	0016c080 */ 	sll	$t8,$s6,0x2
/*  f0c9ce4:	03b8c821 */ 	addu	$t9,$sp,$t8
/*  f0c9ce8:	8f390148 */ 	lw	$t9,0x148($t9)
/*  f0c9cec:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c9cf0:	ad190120 */ 	sw	$t9,0x120($t0)
.L0f0c9cf4:
/*  f0c9cf4:	0fc5b364 */ 	jal	getVar80084014
/*  f0c9cf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c9cfc:	544002ba */ 	bnezl	$v0,.L0f0ca7e8
/*  f0c9d00:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9d04:	8e490288 */ 	lw	$t1,0x288($s2)
/*  f0c9d08:	0fc549fb */ 	jal	optionsGetAimControl
/*  f0c9d0c:	8d240070 */ 	lw	$a0,0x70($t1)
/*  f0c9d10:	10400021 */ 	beqz	$v0,.L0f0c9d98
/*  f0c9d14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c9d18:	1ac0001f */ 	blez	$s6,.L0f0c9d98
/*  f0c9d1c:	00008025 */ 	or	$s0,$zero,$zero
/*  f0c9d20:	27a3014c */ 	addiu	$v1,$sp,0x14c
/*  f0c9d24:	27a700fc */ 	addiu	$a3,$sp,0xfc
.L0f0c9d28:
/*  f0c9d28:	12e00012 */ 	beqz	$s7,.L0f0c9d74
/*  f0c9d2c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9d30:	97ab019e */ 	lhu	$t3,0x19e($sp)
/*  f0c9d34:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c9d38:	00055603 */ 	sra	$t2,$a1,0x18
/*  f0c9d3c:	022b3024 */ 	and	$a2,$s1,$t3
/*  f0c9d40:	30ccffff */ 	andi	$t4,$a2,0xffff
/*  f0c9d44:	01803025 */ 	or	$a2,$t4,$zero
/*  f0c9d48:	01402825 */ 	or	$a1,$t2,$zero
/*  f0c9d4c:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f0c9d50:	0c0052d4 */ 	jal	func00014b50
/*  f0c9d54:	afa70048 */ 	sw	$a3,0x48($sp)
/*  f0c9d58:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0c9d5c:	10400005 */ 	beqz	$v0,.L0f0c9d74
/*  f0c9d60:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0c9d64:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9d68:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9d6c:	2c8d0001 */ 	sltiu	$t5,$a0,0x1
/*  f0c9d70:	acad0120 */ 	sw	$t5,0x120($a1)
.L0f0c9d74:
/*  f0c9d74:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0c9d78:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0c9d7c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0c9d80:	8dcf0120 */ 	lw	$t7,0x120($t6)
/*  f0c9d84:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f0c9d88:	2df80001 */ 	sltiu	$t8,$t7,0x1
/*  f0c9d8c:	acf8fffc */ 	sw	$t8,-0x4($a3)
/*  f0c9d90:	1616ffe5 */ 	bne	$s0,$s6,.L0f0c9d28
/*  f0c9d94:	ac6ffffc */ 	sw	$t7,-0x4($v1)
.L0f0c9d98:
/*  f0c9d98:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0c9d9c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0c9da0:	24010032 */ 	addiu	$at,$zero,0x32
/*  f0c9da4:	54410005 */ 	bnel	$v0,$at,.L0f0c9dbc
/*  f0c9da8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0c9dac:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0c9db0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0c9db4:	ad190120 */ 	sw	$t9,0x120($t0)
/*  f0c9db8:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9dbc:
/*  f0c9dbc:	8fac01b0 */ 	lw	$t4,0x1b0($sp)
/*  f0c9dc0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0c9dc4:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9dc8:	2c890001 */ 	sltiu	$t1,$a0,0x1
/*  f0c9dcc:	afa901b4 */ 	sw	$t1,0x1b4($sp)
/*  f0c9dd0:	8caa0120 */ 	lw	$t2,0x120($a1)
/*  f0c9dd4:	afaa01b8 */ 	sw	$t2,0x1b8($sp)
/*  f0c9dd8:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9ddc:	2c8b0001 */ 	sltiu	$t3,$a0,0x1
/*  f0c9de0:	11810004 */ 	beq	$t4,$at,.L0f0c9df4
/*  f0c9de4:	afab022c */ 	sw	$t3,0x22c($sp)
/*  f0c9de8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c9dec:	15810054 */ 	bne	$t4,$at,.L0f0c9f40
/*  f0c9df0:	97af01a2 */ 	lhu	$t7,0x1a2($sp)
.L0f0c9df4:
/*  f0c9df4:	8cad0120 */ 	lw	$t5,0x120($a1)
/*  f0c9df8:	97a201a2 */ 	lhu	$v0,0x1a2($sp)
/*  f0c9dfc:	15a0001a */ 	bnez	$t5,.L0f0c9e68
/*  f0c9e00:	30490202 */ 	andi	$t1,$v0,0x202
/*  f0c9e04:	12e00015 */ 	beqz	$s7,.L0f0c9e5c
/*  f0c9e08:	27b000fc */ 	addiu	$s0,$sp,0xfc
/*  f0c9e0c:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0c9e10:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c9e14:	00057603 */ 	sra	$t6,$a1,0x18
/*  f0c9e18:	02203025 */ 	or	$a2,$s1,$zero
/*  f0c9e1c:	30cf0202 */ 	andi	$t7,$a2,0x202
/*  f0c9e20:	01e03025 */ 	or	$a2,$t7,$zero
/*  f0c9e24:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0c9e28:	0c005326 */ 	jal	func00014c98
/*  f0c9e2c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9e30:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c9e34:	02203025 */ 	or	$a2,$s1,$zero
/*  f0c9e38:	30d90101 */ 	andi	$t9,$a2,0x101
/*  f0c9e3c:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f0c9e40:	afa201dc */ 	sw	$v0,0x1dc($sp)
/*  f0c9e44:	03002825 */ 	or	$a1,$t8,$zero
/*  f0c9e48:	03203025 */ 	or	$a2,$t9,$zero
/*  f0c9e4c:	0c005326 */ 	jal	func00014c98
/*  f0c9e50:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9e54:	afa201e0 */ 	sw	$v0,0x1e0($sp)
/*  f0c9e58:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9e5c:
/*  f0c9e5c:	97a801a2 */ 	lhu	$t0,0x1a2($sp)
/*  f0c9e60:	1000000d */ 	beqz	$zero,.L0f0c9e98
/*  f0c9e64:	afa80048 */ 	sw	$t0,0x48($sp)
.L0f0c9e68:
/*  f0c9e68:	11200005 */ 	beqz	$t1,.L0f0c9e80
/*  f0c9e6c:	304a0101 */ 	andi	$t2,$v0,0x101
/*  f0c9e70:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9e74:	44818000 */ 	mtc1	$at,$f16
/*  f0c9e78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c9e7c:	e7b001e4 */ 	swc1	$f16,0x1e4($sp)
.L0f0c9e80:
/*  f0c9e80:	11400005 */ 	beqz	$t2,.L0f0c9e98
/*  f0c9e84:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f0c9e88:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9e8c:	44819000 */ 	mtc1	$at,$f18
/*  f0c9e90:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f0c9e94:	e7b201e8 */ 	swc1	$f18,0x1e8($sp)
.L0f0c9e98:
/*  f0c9e98:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9e9c:	44802000 */ 	mtc1	$zero,$f4
/*  f0c9ea0:	44803000 */ 	mtc1	$zero,$f6
/*  f0c9ea4:	2c8b0001 */ 	sltiu	$t3,$a0,0x1
/*  f0c9ea8:	11600004 */ 	beqz	$t3,.L0f0c9ebc
/*  f0c9eac:	01602025 */ 	or	$a0,$t3,$zero
/*  f0c9eb0:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0c9eb4:	308c0808 */ 	andi	$t4,$a0,0x808
/*  f0c9eb8:	000c202b */ 	sltu	$a0,$zero,$t4
.L0f0c9ebc:
/*  f0c9ebc:	afa401d4 */ 	sw	$a0,0x1d4($sp)
/*  f0c9ec0:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9ec4:	2c8e0001 */ 	sltiu	$t6,$a0,0x1
/*  f0c9ec8:	11c00004 */ 	beqz	$t6,.L0f0c9edc
/*  f0c9ecc:	01c02025 */ 	or	$a0,$t6,$zero
/*  f0c9ed0:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0c9ed4:	308f0404 */ 	andi	$t7,$a0,0x404
/*  f0c9ed8:	000f202b */ 	sltu	$a0,$zero,$t7
.L0f0c9edc:
/*  f0c9edc:	afa401d8 */ 	sw	$a0,0x1d8($sp)
/*  f0c9ee0:	afa001c4 */ 	sw	$zero,0x1c4($sp)
/*  f0c9ee4:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9ee8:	e7a401ec */ 	swc1	$f4,0x1ec($sp)
/*  f0c9eec:	e7a601f0 */ 	swc1	$f6,0x1f0($sp)
/*  f0c9ef0:	2c990001 */ 	sltiu	$t9,$a0,0x1
/*  f0c9ef4:	afb901d0 */ 	sw	$t9,0x1d0($sp)
/*  f0c9ef8:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9efc:	8e4902ac */ 	lw	$t1,0x2ac($s2)
/*  f0c9f00:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0c9f04:	2c880001 */ 	sltiu	$t0,$a0,0x1
/*  f0c9f08:	1521005b */ 	bne	$t1,$at,.L0f0ca078
/*  f0c9f0c:	afa801cc */ 	sw	$t0,0x1cc($sp)
/*  f0c9f10:	8caa1bdc */ 	lw	$t2,0x1bdc($a1)
/*  f0c9f14:	000a582a */ 	slt	$t3,$zero,$t2
/*  f0c9f18:	afab01d4 */ 	sw	$t3,0x1d4($sp)
/*  f0c9f1c:	8cac1bdc */ 	lw	$t4,0x1bdc($a1)
/*  f0c9f20:	afa00258 */ 	sw	$zero,0x258($sp)
/*  f0c9f24:	afa0025c */ 	sw	$zero,0x25c($sp)
/*  f0c9f28:	298d0000 */ 	slti	$t5,$t4,0x0
/*  f0c9f2c:	afad01d8 */ 	sw	$t5,0x1d8($sp)
/*  f0c9f30:	8cae1bd8 */ 	lw	$t6,0x1bd8($a1)
/*  f0c9f34:	afa00254 */ 	sw	$zero,0x254($sp)
/*  f0c9f38:	1000004f */ 	beqz	$zero,.L0f0ca078
/*  f0c9f3c:	afae0250 */ 	sw	$t6,0x250($sp)
.L0f0c9f40:
/*  f0c9f40:	31f80202 */ 	andi	$t8,$t7,0x202
/*  f0c9f44:	13000005 */ 	beqz	$t8,.L0f0c9f5c
/*  f0c9f48:	afaf0048 */ 	sw	$t7,0x48($sp)
/*  f0c9f4c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9f50:	44814000 */ 	mtc1	$at,$f8
/*  f0c9f54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c9f58:	e7a801e4 */ 	swc1	$f8,0x1e4($sp)
.L0f0c9f5c:
/*  f0c9f5c:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f0c9f60:	3c013f80 */ 	lui	$at,0x3f80
/*  f0c9f64:	33280101 */ 	andi	$t0,$t9,0x101
/*  f0c9f68:	51000005 */ 	beqzl	$t0,.L0f0c9f80
/*  f0c9f6c:	8ca90120 */ 	lw	$t1,0x120($a1)
/*  f0c9f70:	44815000 */ 	mtc1	$at,$f10
/*  f0c9f74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c9f78:	e7aa01e8 */ 	swc1	$f10,0x1e8($sp)
/*  f0c9f7c:	8ca90120 */ 	lw	$t1,0x120($a1)
.L0f0c9f80:
/*  f0c9f80:	55200018 */ 	bnezl	$t1,.L0f0c9fe4
/*  f0c9f84:	afa001d4 */ 	sw	$zero,0x1d4($sp)
/*  f0c9f88:	12e00015 */ 	beqz	$s7,.L0f0c9fe0
/*  f0c9f8c:	27b000fc */ 	addiu	$s0,$sp,0xfc
/*  f0c9f90:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0c9f94:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c9f98:	00055603 */ 	sra	$t2,$a1,0x18
/*  f0c9f9c:	02203025 */ 	or	$a2,$s1,$zero
/*  f0c9fa0:	30cb0202 */ 	andi	$t3,$a2,0x202
/*  f0c9fa4:	01603025 */ 	or	$a2,$t3,$zero
/*  f0c9fa8:	01402825 */ 	or	$a1,$t2,$zero
/*  f0c9fac:	0c005326 */ 	jal	func00014c98
/*  f0c9fb0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9fb4:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0c9fb8:	02203025 */ 	or	$a2,$s1,$zero
/*  f0c9fbc:	30cd0101 */ 	andi	$t5,$a2,0x101
/*  f0c9fc0:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0c9fc4:	afa201dc */ 	sw	$v0,0x1dc($sp)
/*  f0c9fc8:	01802825 */ 	or	$a1,$t4,$zero
/*  f0c9fcc:	01a03025 */ 	or	$a2,$t5,$zero
/*  f0c9fd0:	0c005326 */ 	jal	func00014c98
/*  f0c9fd4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0c9fd8:	afa201e0 */ 	sw	$v0,0x1e0($sp)
/*  f0c9fdc:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0c9fe0:
/*  f0c9fe0:	afa001d4 */ 	sw	$zero,0x1d4($sp)
.L0f0c9fe4:
/*  f0c9fe4:	afa001d8 */ 	sw	$zero,0x1d8($sp)
/*  f0c9fe8:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0c9fec:	afa001d0 */ 	sw	$zero,0x1d0($sp)
/*  f0c9ff0:	8faf0048 */ 	lw	$t7,0x48($sp)
/*  f0c9ff4:	2c8e0001 */ 	sltiu	$t6,$a0,0x1
/*  f0c9ff8:	afae01c4 */ 	sw	$t6,0x1c4($sp)
/*  f0c9ffc:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0ca000:	31f80808 */ 	andi	$t8,$t7,0x808
/*  f0ca004:	14400007 */ 	bnez	$v0,.L0f0ca024
/*  f0ca008:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca00c:	13000005 */ 	beqz	$t8,.L0f0ca024
/*  f0ca010:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca014:	44818000 */ 	mtc1	$at,$f16
/*  f0ca018:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca01c:	e7b001ec */ 	swc1	$f16,0x1ec($sp)
/*  f0ca020:	8ca20120 */ 	lw	$v0,0x120($a1)
.L0f0ca024:
/*  f0ca024:	14400008 */ 	bnez	$v0,.L0f0ca048
/*  f0ca028:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f0ca02c:	33280404 */ 	andi	$t0,$t9,0x404
/*  f0ca030:	11000005 */ 	beqz	$t0,.L0f0ca048
/*  f0ca034:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca038:	44819000 */ 	mtc1	$at,$f18
/*  f0ca03c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca040:	e7b201f0 */ 	swc1	$f18,0x1f0($sp)
/*  f0ca044:	8ca20120 */ 	lw	$v0,0x120($a1)
.L0f0ca048:
/*  f0ca048:	8e4902ac */ 	lw	$t1,0x2ac($s2)
/*  f0ca04c:	2c440001 */ 	sltiu	$a0,$v0,0x1
/*  f0ca050:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0ca054:	afa401cc */ 	sw	$a0,0x1cc($sp)
/*  f0ca058:	15210007 */ 	bne	$t1,$at,.L0f0ca078
/*  f0ca05c:	afa001c8 */ 	sw	$zero,0x1c8($sp)
/*  f0ca060:	afa00258 */ 	sw	$zero,0x258($sp)
/*  f0ca064:	8caa1bdc */ 	lw	$t2,0x1bdc($a1)
/*  f0ca068:	afaa025c */ 	sw	$t2,0x25c($sp)
/*  f0ca06c:	8cab1bd8 */ 	lw	$t3,0x1bd8($a1)
/*  f0ca070:	afa00254 */ 	sw	$zero,0x254($sp)
/*  f0ca074:	afab0250 */ 	sw	$t3,0x250($sp)
.L0f0ca078:
/*  f0ca078:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0ca07c:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0ca080:	10400012 */ 	beqz	$v0,.L0f0ca0cc
/*  f0ca084:	2881003d */ 	slti	$at,$a0,0x3d
/*  f0ca088:	14200010 */ 	bnez	$at,.L0f0ca0cc
/*  f0ca08c:	248cffc4 */ 	addiu	$t4,$a0,-60
/*  f0ca090:	448c2000 */ 	mtc1	$t4,$f4
/*  f0ca094:	3c014120 */ 	lui	$at,0x4120
/*  f0ca098:	44811000 */ 	mtc1	$at,$f2
/*  f0ca09c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ca0a0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca0a4:	44815000 */ 	mtc1	$at,$f10
/*  f0ca0a8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca0ac:	46023203 */ 	div.s	$f8,$f6,$f2
/*  f0ca0b0:	4608503c */ 	c.lt.s	$f10,$f8
/*  f0ca0b4:	e7a801ec */ 	swc1	$f8,0x1ec($sp)
/*  f0ca0b8:	4502001a */ 	bc1fl	.L0f0ca124
/*  f0ca0bc:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0ca0c0:	44818000 */ 	mtc1	$at,$f16
/*  f0ca0c4:	10000016 */ 	beqz	$zero,.L0f0ca120
/*  f0ca0c8:	e7b001ec */ 	swc1	$f16,0x1ec($sp)
.L0f0ca0cc:
/*  f0ca0cc:	10400014 */ 	beqz	$v0,.L0f0ca120
/*  f0ca0d0:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0ca0d4:	2881ffc4 */ 	slti	$at,$a0,-60
/*  f0ca0d8:	10200011 */ 	beqz	$at,.L0f0ca120
/*  f0ca0dc:	240dffc4 */ 	addiu	$t5,$zero,-60
/*  f0ca0e0:	01a47023 */ 	subu	$t6,$t5,$a0
/*  f0ca0e4:	448e9000 */ 	mtc1	$t6,$f18
/*  f0ca0e8:	3c014120 */ 	lui	$at,0x4120
/*  f0ca0ec:	44811000 */ 	mtc1	$at,$f2
/*  f0ca0f0:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0ca0f4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca0f8:	44815000 */ 	mtc1	$at,$f10
/*  f0ca0fc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca100:	46022183 */ 	div.s	$f6,$f4,$f2
/*  f0ca104:	4606503c */ 	c.lt.s	$f10,$f6
/*  f0ca108:	e7a601f0 */ 	swc1	$f6,0x1f0($sp)
/*  f0ca10c:	45020005 */ 	bc1fl	.L0f0ca124
/*  f0ca110:	8ca20120 */ 	lw	$v0,0x120($a1)
/*  f0ca114:	44814000 */ 	mtc1	$at,$f8
/*  f0ca118:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca11c:	e7a801f0 */ 	swc1	$f8,0x1f0($sp)
.L0f0ca120:
/*  f0ca120:	8ca20120 */ 	lw	$v0,0x120($a1)
.L0f0ca124:
/*  f0ca124:	3c014120 */ 	lui	$at,0x4120
/*  f0ca128:	44811000 */ 	mtc1	$at,$f2
/*  f0ca12c:	10400012 */ 	beqz	$v0,.L0f0ca178
/*  f0ca130:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0ca134:	2861ffc4 */ 	slti	$at,$v1,-60
/*  f0ca138:	1020000f */ 	beqz	$at,.L0f0ca178
/*  f0ca13c:	240fffc4 */ 	addiu	$t7,$zero,-60
/*  f0ca140:	01e3c023 */ 	subu	$t8,$t7,$v1
/*  f0ca144:	44988000 */ 	mtc1	$t8,$f16
/*  f0ca148:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca14c:	44812000 */ 	mtc1	$at,$f4
/*  f0ca150:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0ca154:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca158:	46029303 */ 	div.s	$f12,$f18,$f2
/*  f0ca15c:	460c203c */ 	c.lt.s	$f4,$f12
/*  f0ca160:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
/*  f0ca164:	45000016 */ 	bc1f	.L0f0ca1c0
/*  f0ca168:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca16c:	44816000 */ 	mtc1	$at,$f12
/*  f0ca170:	10000013 */ 	beqz	$zero,.L0f0ca1c0
/*  f0ca174:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
.L0f0ca178:
/*  f0ca178:	10400011 */ 	beqz	$v0,.L0f0ca1c0
/*  f0ca17c:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0ca180:	2861003d */ 	slti	$at,$v1,0x3d
/*  f0ca184:	1420000e */ 	bnez	$at,.L0f0ca1c0
/*  f0ca188:	2479ffc4 */ 	addiu	$t9,$v1,-60
/*  f0ca18c:	44995000 */ 	mtc1	$t9,$f10
/*  f0ca190:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca194:	44814000 */ 	mtc1	$at,$f8
/*  f0ca198:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f0ca19c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca1a0:	46023003 */ 	div.s	$f0,$f6,$f2
/*  f0ca1a4:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0ca1a8:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
/*  f0ca1ac:	45000004 */ 	bc1f	.L0f0ca1c0
/*  f0ca1b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca1b4:	44810000 */ 	mtc1	$at,$f0
/*  f0ca1b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca1bc:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
.L0f0ca1c0:
/*  f0ca1c0:	52e00060 */ 	beqzl	$s7,.L0f0ca344
/*  f0ca1c4:	97aa00ca */ 	lhu	$t2,0xca($sp)
/*  f0ca1c8:	84a2024c */ 	lh	$v0,0x24c($a1)
/*  f0ca1cc:	2841fffe */ 	slti	$at,$v0,-2
/*  f0ca1d0:	10200009 */ 	beqz	$at,.L0f0ca1f8
/*  f0ca1d4:	00564021 */ 	addu	$t0,$v0,$s6
/*  f0ca1d8:	a4a8024c */ 	sh	$t0,0x24c($a1)
/*  f0ca1dc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca1e0:	84a9024c */ 	lh	$t1,0x24c($a1)
/*  f0ca1e4:	2921fffe */ 	slti	$at,$t1,-2
/*  f0ca1e8:	54200056 */ 	bnezl	$at,.L0f0ca344
/*  f0ca1ec:	97aa00ca */ 	lhu	$t2,0xca($sp)
/*  f0ca1f0:	10000053 */ 	beqz	$zero,.L0f0ca340
/*  f0ca1f4:	a4a0024c */ 	sh	$zero,0x24c($a1)
.L0f0ca1f8:
/*  f0ca1f8:	1ac00051 */ 	blez	$s6,.L0f0ca340
/*  f0ca1fc:	00008025 */ 	or	$s0,$zero,$zero
/*  f0ca200:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0ca204:	97aa00ca */ 	lhu	$t2,0xca($sp)
/*  f0ca208:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f0ca20c:	01513024 */ 	and	$a2,$t2,$s1
/*  f0ca210:	30cbffff */ 	andi	$t3,$a2,0xffff
/*  f0ca214:	afab003c */ 	sw	$t3,0x3c($sp)
/*  f0ca218:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0ca21c:
/*  f0ca21c:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0ca220:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*  f0ca224:	01802825 */ 	or	$a1,$t4,$zero
/*  f0ca228:	0c00529e */ 	jal	func00014a78
/*  f0ca22c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca230:	5040002d */ 	beqzl	$v0,.L0f0ca2e8
/*  f0ca234:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0ca238:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0ca23c:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0ca240:	00057e03 */ 	sra	$t7,$a1,0x18
/*  f0ca244:	85ae024c */ 	lh	$t6,0x24c($t5)
/*  f0ca248:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0ca24c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca250:	29c1ffff */ 	slti	$at,$t6,-1
/*  f0ca254:	14200037 */ 	bnez	$at,.L0f0ca334
/*  f0ca258:	02913024 */ 	and	$a2,$s4,$s1
/*  f0ca25c:	30d8ffff */ 	andi	$t8,$a2,0xffff
/*  f0ca260:	03003025 */ 	or	$a2,$t8,$zero
/*  f0ca264:	0c0052d4 */ 	jal	func00014b50
/*  f0ca268:	afb8004c */ 	sw	$t8,0x4c($sp)
/*  f0ca26c:	10400006 */ 	beqz	$v0,.L0f0ca288
/*  f0ca270:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0ca274:	8fb901fc */ 	lw	$t9,0x1fc($sp)
/*  f0ca278:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0ca27c:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f0ca280:	afa801fc */ 	sw	$t0,0x1fc($sp)
/*  f0ca284:	a533024c */ 	sh	$s3,0x24c($t1)
.L0f0ca288:
/*  f0ca288:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0ca28c:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0ca290:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0ca294:	854b024c */ 	lh	$t3,0x24c($t2)
/*  f0ca298:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca29c:	05620026 */ 	bltzl	$t3,.L0f0ca338
/*  f0ca2a0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0ca2a4:	0c00529e */ 	jal	func00014a78
/*  f0ca2a8:	01802825 */ 	or	$a1,$t4,$zero
/*  f0ca2ac:	54400022 */ 	bnezl	$v0,.L0f0ca338
/*  f0ca2b0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0ca2b4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca2b8:	84a2024c */ 	lh	$v0,0x24c($a1)
/*  f0ca2bc:	28410010 */ 	slti	$at,$v0,0x10
/*  f0ca2c0:	14200006 */ 	bnez	$at,.L0f0ca2dc
/*  f0ca2c4:	244e0001 */ 	addiu	$t6,$v0,0x1
/*  f0ca2c8:	0fc3fbda */ 	jal	activemenuOpen
/*  f0ca2cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca2d0:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0ca2d4:	10000017 */ 	beqz	$zero,.L0f0ca334
/*  f0ca2d8:	a5b3024c */ 	sh	$s3,0x24c($t5)
.L0f0ca2dc:
/*  f0ca2dc:	10000015 */ 	beqz	$zero,.L0f0ca334
/*  f0ca2e0:	a4ae024c */ 	sh	$t6,0x24c($a1)
/*  f0ca2e4:	8e4f0284 */ 	lw	$t7,0x284($s2)
.L0f0ca2e8:
/*  f0ca2e8:	85f8024c */ 	lh	$t8,0x24c($t7)
/*  f0ca2ec:	5b000010 */ 	blezl	$t8,.L0f0ca330
/*  f0ca2f0:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0ca2f4:	12e0000a */ 	beqz	$s7,.L0f0ca320
/*  f0ca2f8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca2fc:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0ca300:	02913024 */ 	and	$a2,$s4,$s1
/*  f0ca304:	30c8ffff */ 	andi	$t0,$a2,0xffff
/*  f0ca308:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f0ca30c:	03202825 */ 	or	$a1,$t9,$zero
/*  f0ca310:	0c00529e */ 	jal	func00014a78
/*  f0ca314:	01003025 */ 	or	$a2,$t0,$zero
/*  f0ca318:	54400005 */ 	bnezl	$v0,.L0f0ca330
/*  f0ca31c:	8e490284 */ 	lw	$t1,0x284($s2)
.L0f0ca320:
/*  f0ca320:	8fa20200 */ 	lw	$v0,0x200($sp)
/*  f0ca324:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0ca328:	afa20200 */ 	sw	$v0,0x200($sp)
/*  f0ca32c:	8e490284 */ 	lw	$t1,0x284($s2)
.L0f0ca330:
/*  f0ca330:	a520024c */ 	sh	$zero,0x24c($t1)
.L0f0ca334:
/*  f0ca334:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0ca338:
/*  f0ca338:	5616ffb8 */ 	bnel	$s0,$s6,.L0f0ca21c
/*  f0ca33c:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0ca340:
/*  f0ca340:	97aa00ca */ 	lhu	$t2,0xca($sp)
.L0f0ca344:
/*  f0ca344:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f0ca348:	12e00058 */ 	beqz	$s7,.L0f0ca4ac
/*  f0ca34c:	afaa0038 */ 	sw	$t2,0x38($sp)
/*  f0ca350:	1ac00056 */ 	blez	$s6,.L0f0ca4ac
/*  f0ca354:	00008025 */ 	or	$s0,$zero,$zero
/*  f0ca358:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0ca35c:	322c4000 */ 	andi	$t4,$s1,0x4000
/*  f0ca360:	afac0044 */ 	sw	$t4,0x44($sp)
/*  f0ca364:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0ca368:
/*  f0ca368:	00056e03 */ 	sra	$t5,$a1,0x18
/*  f0ca36c:	01a02825 */ 	or	$a1,$t5,$zero
/*  f0ca370:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca374:	0c00529e */ 	jal	func00014a78
/*  f0ca378:	97a60046 */ 	lhu	$a2,0x46($sp)
/*  f0ca37c:	50400040 */ 	beqzl	$v0,.L0f0ca480
/*  f0ca380:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca384:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0ca388:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0ca38c:	00057e03 */ 	sra	$t7,$a1,0x18
/*  f0ca390:	85c4024e */ 	lh	$a0,0x24e($t6)
/*  f0ca394:	02913024 */ 	and	$a2,$s4,$s1
/*  f0ca398:	30d8ffff */ 	andi	$t8,$a2,0xffff
/*  f0ca39c:	2881ffff */ 	slti	$at,$a0,-1
/*  f0ca3a0:	1420002f */ 	bnez	$at,.L0f0ca460
/*  f0ca3a4:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0ca3a8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca3ac:	0c0052d4 */ 	jal	func00014b50
/*  f0ca3b0:	03003025 */ 	or	$a2,$t8,$zero
/*  f0ca3b4:	5040000e */ 	beqzl	$v0,.L0f0ca3f0
/*  f0ca3b8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca3bc:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0ca3c0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0ca3c4:	8724024e */ 	lh	$a0,0x24e($t9)
/*  f0ca3c8:	04820009 */ 	bltzl	$a0,.L0f0ca3f0
/*  f0ca3cc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca3d0:	0fc2a257 */ 	jal	func0f0a895c
/*  f0ca3d4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0ca3d8:	50400005 */ 	beqzl	$v0,.L0f0ca3f0
/*  f0ca3dc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca3e0:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0ca3e4:	2408fffd */ 	addiu	$t0,$zero,-3
/*  f0ca3e8:	a528024e */ 	sh	$t0,0x24e($t1)
/*  f0ca3ec:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca3f0:
/*  f0ca3f0:	84a4024e */ 	lh	$a0,0x24e($a1)
/*  f0ca3f4:	0480002a */ 	bltz	$a0,.L0f0ca4a0
/*  f0ca3f8:	2881001a */ 	slti	$at,$a0,0x1a
/*  f0ca3fc:	14200016 */ 	bnez	$at,.L0f0ca458
/*  f0ca400:	248f0001 */ 	addiu	$t7,$a0,0x1
/*  f0ca404:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ca408:	0fc2a257 */ 	jal	func0f0a895c
/*  f0ca40c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0ca410:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ca414:	54410005 */ 	bnel	$v0,$at,.L0f0ca42c
/*  f0ca418:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0ca41c:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0ca420:	1000001f */ 	beqz	$zero,.L0f0ca4a0
/*  f0ca424:	a553024e */ 	sh	$s3,0x24e($t2)
/*  f0ca428:	24010002 */ 	addiu	$at,$zero,0x2
.L0f0ca42c:
/*  f0ca42c:	54410006 */ 	bnel	$v0,$at,.L0f0ca448
/*  f0ca430:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca434:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0ca438:	240bfffe */ 	addiu	$t3,$zero,-2
/*  f0ca43c:	10000018 */ 	beqz	$zero,.L0f0ca4a0
/*  f0ca440:	a58b024e */ 	sh	$t3,0x24e($t4)
/*  f0ca444:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca448:
/*  f0ca448:	84ad024e */ 	lh	$t5,0x24e($a1)
/*  f0ca44c:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f0ca450:	10000013 */ 	beqz	$zero,.L0f0ca4a0
/*  f0ca454:	a4ae024e */ 	sh	$t6,0x24e($a1)
.L0f0ca458:
/*  f0ca458:	10000011 */ 	beqz	$zero,.L0f0ca4a0
/*  f0ca45c:	a4af024e */ 	sh	$t7,0x24e($a1)
.L0f0ca460:
/*  f0ca460:	2881fffe */ 	slti	$at,$a0,-2
/*  f0ca464:	1420000e */ 	bnez	$at,.L0f0ca4a0
/*  f0ca468:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ca46c:	0fc2a257 */ 	jal	func0f0a895c
/*  f0ca470:	00003025 */ 	or	$a2,$zero,$zero
/*  f0ca474:	1000000b */ 	beqz	$zero,.L0f0ca4a4
/*  f0ca478:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0ca47c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca480:
/*  f0ca480:	8fb901c0 */ 	lw	$t9,0x1c0($sp)
/*  f0ca484:	84b8024e */ 	lh	$t8,0x24e($a1)
/*  f0ca488:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f0ca48c:	1b000002 */ 	blez	$t8,.L0f0ca498
/*  f0ca490:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca494:	afa801c0 */ 	sw	$t0,0x1c0($sp)
.L0f0ca498:
/*  f0ca498:	0fc2a314 */ 	jal	func0f0a8c50
/*  f0ca49c:	a4a0024e */ 	sh	$zero,0x24e($a1)
.L0f0ca4a0:
/*  f0ca4a0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0ca4a4:
/*  f0ca4a4:	5616ffb0 */ 	bnel	$s0,$s6,.L0f0ca368
/*  f0ca4a8:	00152e00 */ 	sll	$a1,$s5,0x18
.L0f0ca4ac:
/*  f0ca4ac:	8fa901a8 */ 	lw	$t1,0x1a8($sp)
/*  f0ca4b0:	1120001c */ 	beqz	$t1,.L0f0ca524
/*  f0ca4b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca4b8:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0ca4bc:	8fa20048 */ 	lw	$v0,0x48($sp)
/*  f0ca4c0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ca4c4:	8d4b0120 */ 	lw	$t3,0x120($t2)
/*  f0ca4c8:	30510808 */ 	andi	$s1,$v0,0x808
/*  f0ca4cc:	0011602b */ 	sltu	$t4,$zero,$s1
/*  f0ca4d0:	11600014 */ 	beqz	$t3,.L0f0ca524
/*  f0ca4d4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ca4d8:	44810000 */ 	mtc1	$at,$f0
/*  f0ca4dc:	30500404 */ 	andi	$s0,$v0,0x404
/*  f0ca4e0:	0010682b */ 	sltu	$t5,$zero,$s0
/*  f0ca4e4:	01a08025 */ 	or	$s0,$t5,$zero
/*  f0ca4e8:	01808825 */ 	or	$s1,$t4,$zero
/*  f0ca4ec:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0ca4f0:	e7a000bc */ 	swc1	$f0,0xbc($sp)
/*  f0ca4f4:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0ca4f8:	14410004 */ 	bne	$v0,$at,.L0f0ca50c
/*  f0ca4fc:	c7a000bc */ 	lwc1	$f0,0xbc($sp)
/*  f0ca500:	3c013f00 */ 	lui	$at,0x3f00
/*  f0ca504:	44810000 */ 	mtc1	$at,$f0
/*  f0ca508:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ca50c:
/*  f0ca50c:	12000002 */ 	beqz	$s0,.L0f0ca518
/*  f0ca510:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca514:	e7a00210 */ 	swc1	$f0,0x210($sp)
.L0f0ca518:
/*  f0ca518:	12200002 */ 	beqz	$s1,.L0f0ca524
/*  f0ca51c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca520:	e7a00214 */ 	swc1	$f0,0x214($sp)
.L0f0ca524:
/*  f0ca524:	12e00052 */ 	beqz	$s7,.L0f0ca670
/*  f0ca528:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca52c:	1ac00050 */ 	blez	$s6,.L0f0ca670
/*  f0ca530:	00008025 */ 	or	$s0,$zero,$zero
/*  f0ca534:	8fae01a8 */ 	lw	$t6,0x1a8($sp)
.L0f0ca538:
/*  f0ca538:	00107880 */ 	sll	$t7,$s0,0x2
/*  f0ca53c:	03afc021 */ 	addu	$t8,$sp,$t7
/*  f0ca540:	55c0002c */ 	bnezl	$t6,.L0f0ca5f4
/*  f0ca544:	8e4e0288 */ 	lw	$t6,0x288($s2)
/*  f0ca548:	8f18014c */ 	lw	$t8,0x14c($t8)
/*  f0ca54c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca550:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0ca554:	13000026 */ 	beqz	$t8,.L0f0ca5f0
/*  f0ca558:	97b1019e */ 	lhu	$s1,0x19e($sp)
/*  f0ca55c:	02203025 */ 	or	$a2,$s1,$zero
/*  f0ca560:	30c80808 */ 	andi	$t0,$a2,0x808
/*  f0ca564:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f0ca568:	322a0404 */ 	andi	$t2,$s1,0x404
/*  f0ca56c:	afaa0050 */ 	sw	$t2,0x50($sp)
/*  f0ca570:	03202825 */ 	or	$a1,$t9,$zero
/*  f0ca574:	0c0052d4 */ 	jal	func00014b50
/*  f0ca578:	01003025 */ 	or	$a2,$t0,$zero
/*  f0ca57c:	1040000b */ 	beqz	$v0,.L0f0ca5ac
/*  f0ca580:	02002025 */ 	or	$a0,$s0,$zero
/*  f0ca584:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0ca588:	10400003 */ 	beqz	$v0,.L0f0ca598
/*  f0ca58c:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0ca590:	10000004 */ 	beqz	$zero,.L0f0ca5a4
/*  f0ca594:	afa20218 */ 	sw	$v0,0x218($sp)
.L0f0ca598:
/*  f0ca598:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0ca59c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0ca5a0:	afa2021c */ 	sw	$v0,0x21c($sp)
.L0f0ca5a4:
/*  f0ca5a4:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0ca5a8:	ad730260 */ 	sw	$s3,0x260($t3)
.L0f0ca5ac:
/*  f0ca5ac:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f0ca5b0:	00056603 */ 	sra	$t4,$a1,0x18
/*  f0ca5b4:	01802825 */ 	or	$a1,$t4,$zero
/*  f0ca5b8:	0c0052d4 */ 	jal	func00014b50
/*  f0ca5bc:	97a60052 */ 	lhu	$a2,0x52($sp)
/*  f0ca5c0:	5040000c */ 	beqzl	$v0,.L0f0ca5f4
/*  f0ca5c4:	8e4e0288 */ 	lw	$t6,0x288($s2)
/*  f0ca5c8:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0ca5cc:	10400003 */ 	beqz	$v0,.L0f0ca5dc
/*  f0ca5d0:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0ca5d4:	10000004 */ 	beqz	$zero,.L0f0ca5e8
/*  f0ca5d8:	afa2021c */ 	sw	$v0,0x21c($sp)
.L0f0ca5dc:
/*  f0ca5dc:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0ca5e0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0ca5e4:	afa20218 */ 	sw	$v0,0x218($sp)
.L0f0ca5e8:
/*  f0ca5e8:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0ca5ec:	adb30260 */ 	sw	$s3,0x260($t5)
.L0f0ca5f0:
/*  f0ca5f0:	8e4e0288 */ 	lw	$t6,0x288($s2)
.L0f0ca5f4:
/*  f0ca5f4:	0fc549fb */ 	jal	optionsGetAimControl
/*  f0ca5f8:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0ca5fc:	14400019 */ 	bnez	$v0,.L0f0ca664
/*  f0ca600:	00107880 */ 	sll	$t7,$s0,0x2
/*  f0ca604:	03afc021 */ 	addu	$t8,$sp,$t7
/*  f0ca608:	8f18014c */ 	lw	$t8,0x14c($t8)
/*  f0ca60c:	53000008 */ 	beqzl	$t8,.L0f0ca630
/*  f0ca610:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca614:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca618:	8ca20260 */ 	lw	$v0,0x260($a1)
/*  f0ca61c:	04400011 */ 	bltz	$v0,.L0f0ca664
/*  f0ca620:	24590001 */ 	addiu	$t9,$v0,0x1
/*  f0ca624:	1000000f */ 	beqz	$zero,.L0f0ca664
/*  f0ca628:	acb90260 */ 	sw	$t9,0x260($a1)
/*  f0ca62c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca630:
/*  f0ca630:	8ca20260 */ 	lw	$v0,0x260($a1)
/*  f0ca634:	1840000a */ 	blez	$v0,.L0f0ca660
/*  f0ca638:	2841000f */ 	slti	$at,$v0,0xf
/*  f0ca63c:	10200008 */ 	beqz	$at,.L0f0ca660
/*  f0ca640:	8fa20218 */ 	lw	$v0,0x218($sp)
/*  f0ca644:	10400003 */ 	beqz	$v0,.L0f0ca654
/*  f0ca648:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0ca64c:	10000004 */ 	beqz	$zero,.L0f0ca660
/*  f0ca650:	afa20218 */ 	sw	$v0,0x218($sp)
.L0f0ca654:
/*  f0ca654:	8fa2021c */ 	lw	$v0,0x21c($sp)
/*  f0ca658:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0ca65c:	afa2021c */ 	sw	$v0,0x21c($sp)
.L0f0ca660:
/*  f0ca660:	aca00260 */ 	sw	$zero,0x260($a1)
.L0f0ca664:
/*  f0ca664:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0ca668:	5616ffb3 */ 	bnel	$s0,$s6,.L0f0ca538
/*  f0ca66c:	8fae01a8 */ 	lw	$t6,0x1a8($sp)
.L0f0ca670:
/*  f0ca670:	0fc331a0 */ 	jal	currentPlayerGetCrouchPos
/*  f0ca674:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca678:	1440001e */ 	bnez	$v0,.L0f0ca6f4
/*  f0ca67c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca680:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca684:	3c01c2b4 */ 	lui	$at,0xc2b4
/*  f0ca688:	44818000 */ 	mtc1	$at,$f16
/*  f0ca68c:	c4b200b4 */ 	lwc1	$f18,0xb4($a1)
/*  f0ca690:	46128032 */ 	c.eq.s	$f16,$f18
/*  f0ca694:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca698:	45000016 */ 	bc1f	.L0f0ca6f4
/*  f0ca69c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca6a0:	8e480314 */ 	lw	$t0,0x314($s2)
/*  f0ca6a4:	11000013 */ 	beqz	$t0,.L0f0ca6f4
/*  f0ca6a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca6ac:	8e490298 */ 	lw	$t1,0x298($s2)
/*  f0ca6b0:	05210010 */ 	bgez	$t1,.L0f0ca6f4
/*  f0ca6b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca6b8:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0ca6bc:	8fa201a8 */ 	lw	$v0,0x1a8($sp)
/*  f0ca6c0:	0004502b */ 	sltu	$t2,$zero,$a0
/*  f0ca6c4:	1140000a */ 	beqz	$t2,.L0f0ca6f0
/*  f0ca6c8:	01402025 */ 	or	$a0,$t2,$zero
/*  f0ca6cc:	2c440001 */ 	sltiu	$a0,$v0,0x1
/*  f0ca6d0:	10800007 */ 	beqz	$a0,.L0f0ca6f0
/*  f0ca6d4:	97ad019e */ 	lhu	$t5,0x19e($sp)
/*  f0ca6d8:	00152600 */ 	sll	$a0,$s5,0x18
/*  f0ca6dc:	00046603 */ 	sra	$t4,$a0,0x18
/*  f0ca6e0:	01802025 */ 	or	$a0,$t4,$zero
/*  f0ca6e4:	0c0053d8 */ 	jal	func00014f60
/*  f0ca6e8:	31a50404 */ 	andi	$a1,$t5,0x404
/*  f0ca6ec:	0002202b */ 	sltu	$a0,$zero,$v0
.L0f0ca6f0:
/*  f0ca6f0:	afa40234 */ 	sw	$a0,0x234($sp)
.L0f0ca6f4:
/*  f0ca6f4:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0ca6f8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ca6fc:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0ca700:	5441000c */ 	bnel	$v0,$at,.L0f0ca734
/*  f0ca704:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca708:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca70c:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0ca710:	0004782b */ 	sltu	$t7,$zero,$a0
/*  f0ca714:	11e00004 */ 	beqz	$t7,.L0f0ca728
/*  f0ca718:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0ca71c:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0ca720:	30980303 */ 	andi	$t8,$a0,0x303
/*  f0ca724:	0018202b */ 	sltu	$a0,$zero,$t8
.L0f0ca728:
/*  f0ca728:	10000012 */ 	beqz	$zero,.L0f0ca774
/*  f0ca72c:	afa40230 */ 	sw	$a0,0x230($sp)
/*  f0ca730:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca734:
/*  f0ca734:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0ca738:	0004402b */ 	sltu	$t0,$zero,$a0
/*  f0ca73c:	11000004 */ 	beqz	$t0,.L0f0ca750
/*  f0ca740:	01002025 */ 	or	$a0,$t0,$zero
/*  f0ca744:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0ca748:	30890202 */ 	andi	$t1,$a0,0x202
/*  f0ca74c:	0009202b */ 	sltu	$a0,$zero,$t1
.L0f0ca750:
/*  f0ca750:	afa40220 */ 	sw	$a0,0x220($sp)
/*  f0ca754:	8ca40120 */ 	lw	$a0,0x120($a1)
/*  f0ca758:	0004582b */ 	sltu	$t3,$zero,$a0
/*  f0ca75c:	11600004 */ 	beqz	$t3,.L0f0ca770
/*  f0ca760:	01602025 */ 	or	$a0,$t3,$zero
/*  f0ca764:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f0ca768:	308c0101 */ 	andi	$t4,$a0,0x101
/*  f0ca76c:	000c202b */ 	sltu	$a0,$zero,$t4
.L0f0ca770:
/*  f0ca770:	afa40224 */ 	sw	$a0,0x224($sp)
.L0f0ca774:
/*  f0ca774:	8fae0048 */ 	lw	$t6,0x48($sp)
/*  f0ca778:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f0ca77c:	97b901a0 */ 	lhu	$t9,0x1a0($sp)
/*  f0ca780:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f0ca784:	01cfc024 */ 	and	$t8,$t6,$t7
/*  f0ca788:	13000002 */ 	beqz	$t8,.L0f0ca794
/*  f0ca78c:	33284000 */ 	andi	$t0,$t9,0x4000
/*  f0ca790:	15000007 */ 	bnez	$t0,.L0f0ca7b0
.L0f0ca794:
/*  f0ca794:	312a4000 */ 	andi	$t2,$t1,0x4000
/*  f0ca798:	11400012 */ 	beqz	$t2,.L0f0ca7e4
/*  f0ca79c:	97ab01a0 */ 	lhu	$t3,0x1a0($sp)
/*  f0ca7a0:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f0ca7a4:	016c6824 */ 	and	$t5,$t3,$t4
/*  f0ca7a8:	51a0000f */ 	beqzl	$t5,.L0f0ca7e8
/*  f0ca7ac:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca7b0:
/*  f0ca7b0:	8fae01ac */ 	lw	$t6,0x1ac($sp)
/*  f0ca7b4:	24010022 */ 	addiu	$at,$zero,0x22
/*  f0ca7b8:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0ca7bc:	15c10009 */ 	bne	$t6,$at,.L0f0ca7e4
/*  f0ca7c0:	2418fffe */ 	addiu	$t8,$zero,-2
/*  f0ca7c4:	afaf0228 */ 	sw	$t7,0x228($sp)
/*  f0ca7c8:	afa001fc */ 	sw	$zero,0x1fc($sp)
/*  f0ca7cc:	afa00200 */ 	sw	$zero,0x200($sp)
/*  f0ca7d0:	afa001c0 */ 	sw	$zero,0x1c0($sp)
/*  f0ca7d4:	a4b8024c */ 	sh	$t8,0x24c($a1)
/*  f0ca7d8:	8e480284 */ 	lw	$t0,0x284($s2)
/*  f0ca7dc:	2419fffe */ 	addiu	$t9,$zero,-2
/*  f0ca7e0:	a519024e */ 	sh	$t9,0x24e($t0)
.L0f0ca7e4:
/*  f0ca7e4:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca7e8:
/*  f0ca7e8:	97ac01a2 */ 	lhu	$t4,0x1a2($sp)
/*  f0ca7ec:	8ca90120 */ 	lw	$t1,0x120($a1)
/*  f0ca7f0:	01946824 */ 	and	$t5,$t4,$s4
/*  f0ca7f4:	afa90208 */ 	sw	$t1,0x208($sp)
/*  f0ca7f8:	8caa0120 */ 	lw	$t2,0x120($a1)
/*  f0ca7fc:	afaa020c */ 	sw	$t2,0x20c($sp)
/*  f0ca800:	8cab0274 */ 	lw	$t3,0x274($a1)
/*  f0ca804:	11600004 */ 	beqz	$t3,.L0f0ca818
/*  f0ca808:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca80c:	15a00002 */ 	bnez	$t5,.L0f0ca818
/*  f0ca810:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca814:	aca00274 */ 	sw	$zero,0x274($a1)
.L0f0ca818:
/*  f0ca818:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0ca81c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ca820:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ca824:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0ca828:	3c058000 */ 	lui	$a1,0x8000
/*  f0ca82c:	1040000d */ 	beqz	$v0,.L0f0ca864
/*  f0ca830:	97ae01a0 */ 	lhu	$t6,0x1a0($sp)
/*  f0ca834:	01d47824 */ 	and	$t7,$t6,$s4
/*  f0ca838:	11e00008 */ 	beqz	$t7,.L0f0ca85c
/*  f0ca83c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca840:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0ca844:	8fa801c0 */ 	lw	$t0,0x1c0($sp)
/*  f0ca848:	8f191a24 */ 	lw	$t9,0x1a24($t8)
/*  f0ca84c:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f0ca850:	17200002 */ 	bnez	$t9,.L0f0ca85c
/*  f0ca854:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca858:	afa901c0 */ 	sw	$t1,0x1c0($sp)
.L0f0ca85c:
/*  f0ca85c:	10000014 */ 	beqz	$zero,.L0f0ca8b0
/*  f0ca860:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0ca864:
/*  f0ca864:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca868:	97a301a2 */ 	lhu	$v1,0x1a2($sp)
/*  f0ca86c:	8ca40274 */ 	lw	$a0,0x274($a1)
/*  f0ca870:	00741024 */ 	and	$v0,$v1,$s4
/*  f0ca874:	2c8a0001 */ 	sltiu	$t2,$a0,0x1
/*  f0ca878:	1140000c */ 	beqz	$t2,.L0f0ca8ac
/*  f0ca87c:	01402025 */ 	or	$a0,$t2,$zero
/*  f0ca880:	0002202b */ 	sltu	$a0,$zero,$v0
/*  f0ca884:	5080000a */ 	beqzl	$a0,.L0f0ca8b0
/*  f0ca888:	afa401bc */ 	sw	$a0,0x1bc($sp)
/*  f0ca88c:	8ca41a24 */ 	lw	$a0,0x1a24($a1)
/*  f0ca890:	97ad00ca */ 	lhu	$t5,0xca($sp)
/*  f0ca894:	2c8c0001 */ 	sltiu	$t4,$a0,0x1
/*  f0ca898:	11800004 */ 	beqz	$t4,.L0f0ca8ac
/*  f0ca89c:	01802025 */ 	or	$a0,$t4,$zero
/*  f0ca8a0:	006d2024 */ 	and	$a0,$v1,$t5
/*  f0ca8a4:	2c8e0001 */ 	sltiu	$t6,$a0,0x1
/*  f0ca8a8:	01c02025 */ 	or	$a0,$t6,$zero
.L0f0ca8ac:
/*  f0ca8ac:	afa401bc */ 	sw	$a0,0x1bc($sp)
.L0f0ca8b0:
/*  f0ca8b0:	8faf01b0 */ 	lw	$t7,0x1b0($sp)
/*  f0ca8b4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ca8b8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0ca8bc:	11e10003 */ 	beq	$t7,$at,.L0f0ca8cc
/*  f0ca8c0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0ca8c4:	55e10003 */ 	bnel	$t7,$at,.L0f0ca8d4
/*  f0ca8c8:	aca000d0 */ 	sw	$zero,0xd0($a1)
.L0f0ca8cc:
/*  f0ca8cc:	afb8023c */ 	sw	$t8,0x23c($sp)
.L0f0ca8d0:
/*  f0ca8d0:	aca000d0 */ 	sw	$zero,0xd0($a1)
.L0f0ca8d4:
/*  f0ca8d4:	8fb901c0 */ 	lw	$t9,0x1c0($sp)
/*  f0ca8d8:	5320000c */ 	beqzl	$t9,.L0f0ca90c
/*  f0ca8dc:	8fad0238 */ 	lw	$t5,0x238($sp)
/*  f0ca8e0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0ca8e4:	8ca801a0 */ 	lw	$t0,0x1a0($a1)
/*  f0ca8e8:	aca8019c */ 	sw	$t0,0x19c($a1)
/*  f0ca8ec:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0ca8f0:	8e490008 */ 	lw	$t1,0x8($s2)
/*  f0ca8f4:	ad4901a0 */ 	sw	$t1,0x1a0($t2)
/*  f0ca8f8:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0ca8fc:	8fab01c0 */ 	lw	$t3,0x1c0($sp)
/*  f0ca900:	0fc31fcb */ 	jal	func0f0c7f2c
/*  f0ca904:	ad8b00d0 */ 	sw	$t3,0xd0($t4)
/*  f0ca908:	8fad0238 */ 	lw	$t5,0x238($sp)
.L0f0ca90c:
/*  f0ca90c:	15a0000b */ 	bnez	$t5,.L0f0ca93c
/*  f0ca910:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca914:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0ca918:	8fae0254 */ 	lw	$t6,0x254($sp)
/*  f0ca91c:	c7a001ec */ 	lwc1	$f0,0x1ec($sp)
/*  f0ca920:	c7a401f0 */ 	lwc1	$f4,0x1f0($sp)
/*  f0ca924:	00042023 */ 	negu	$a0,$a0
/*  f0ca928:	000e7823 */ 	negu	$t7,$t6
/*  f0ca92c:	afaf0254 */ 	sw	$t7,0x254($sp)
/*  f0ca930:	afa4024c */ 	sw	$a0,0x24c($sp)
/*  f0ca934:	e7a001f0 */ 	swc1	$f0,0x1f0($sp)
/*  f0ca938:	e7a401ec */ 	swc1	$f4,0x1ec($sp)
.L0f0ca93c:
/*  f0ca93c:	0fc2a34d */ 	jal	func0f0a8d34
/*  f0ca940:	8fa401bc */ 	lw	$a0,0x1bc($sp)
/*  f0ca944:	8e580324 */ 	lw	$t8,0x324($s2)
/*  f0ca948:	5300002b */ 	beqzl	$t8,.L0f0ca9f8
/*  f0ca94c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0ca950:	0fc2883f */ 	jal	func0f0a20fc
/*  f0ca954:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ca958:	54400006 */ 	bnezl	$v0,.L0f0ca974
/*  f0ca95c:	44805000 */ 	mtc1	$zero,$f10
/*  f0ca960:	0fc2883f */ 	jal	func0f0a20fc
/*  f0ca964:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ca968:	50400023 */ 	beqzl	$v0,.L0f0ca9f8
/*  f0ca96c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0ca970:	44805000 */ 	mtc1	$zero,$f10
.L0f0ca974:
/*  f0ca974:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ca978:	0fc2883f */ 	jal	func0f0a20fc
/*  f0ca97c:	e7aa00b4 */ 	swc1	$f10,0xb4($sp)
/*  f0ca980:	1040000c */ 	beqz	$v0,.L0f0ca9b4
/*  f0ca984:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca988:	0fc273d6 */ 	jal	func0f09cf58
/*  f0ca98c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ca990:	44803000 */ 	mtc1	$zero,$f6
/*  f0ca994:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca998:	4600303c */ 	c.lt.s	$f6,$f0
/*  f0ca99c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca9a0:	45000004 */ 	bc1f	.L0f0ca9b4
/*  f0ca9a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca9a8:	0fc273d6 */ 	jal	func0f09cf58
/*  f0ca9ac:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ca9b0:	e7a000b4 */ 	swc1	$f0,0xb4($sp)
.L0f0ca9b4:
/*  f0ca9b4:	0fc2883f */ 	jal	func0f0a20fc
/*  f0ca9b8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ca9bc:	1040000b */ 	beqz	$v0,.L0f0ca9ec
/*  f0ca9c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca9c4:	0fc273d6 */ 	jal	func0f09cf58
/*  f0ca9c8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ca9cc:	c7a800b4 */ 	lwc1	$f8,0xb4($sp)
/*  f0ca9d0:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0ca9d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca9d8:	45000004 */ 	bc1f	.L0f0ca9ec
/*  f0ca9dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ca9e0:	0fc273d6 */ 	jal	func0f09cf58
/*  f0ca9e4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ca9e8:	e7a000b4 */ 	swc1	$f0,0xb4($sp)
.L0f0ca9ec:
/*  f0ca9ec:	0fc0a164 */ 	jal	func0f028590
/*  f0ca9f0:	c7ac00b4 */ 	lwc1	$f12,0xb4($sp)
/*  f0ca9f4:	24040002 */ 	addiu	$a0,$zero,0x2
.L0f0ca9f8:
/*  f0ca9f8:	0fc2af1d */ 	jal	func0f0abc74
/*  f0ca9fc:	8fa50208 */ 	lw	$a1,0x208($sp)
/*  f0caa00:	c7ac0210 */ 	lwc1	$f12,0x210($sp)
/*  f0caa04:	44808000 */ 	mtc1	$zero,$f16
/*  f0caa08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caa0c:	460c803c */ 	c.lt.s	$f16,$f12
/*  f0caa10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caa14:	45020004 */ 	bc1fl	.L0f0caa28
/*  f0caa18:	c7ac0214 */ 	lwc1	$f12,0x214($sp)
/*  f0caa1c:	0fc2c562 */ 	jal	func0f0b1588
/*  f0caa20:	e7ac0210 */ 	swc1	$f12,0x210($sp)
/*  f0caa24:	c7ac0214 */ 	lwc1	$f12,0x214($sp)
.L0f0caa28:
/*  f0caa28:	44809000 */ 	mtc1	$zero,$f18
/*  f0caa2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caa30:	460c903c */ 	c.lt.s	$f18,$f12
/*  f0caa34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caa38:	45020004 */ 	bc1fl	.L0f0caa4c
/*  f0caa3c:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0caa40:	0fc2c5a9 */ 	jal	currentPlayerUpdateGunZoomFovs
/*  f0caa44:	e7ac0214 */ 	swc1	$f12,0x214($sp)
/*  f0caa48:	8e590284 */ 	lw	$t9,0x284($s2)
.L0f0caa4c:
/*  f0caa4c:	8f281a24 */ 	lw	$t0,0x1a24($t9)
/*  f0caa50:	150000b5 */ 	bnez	$t0,.L0f0cad28
/*  f0caa54:	3c098006 */ 	lui	$t1,%hi(var8005d9d0)
/*  f0caa58:	8d29d9d0 */ 	lw	$t1,%lo(var8005d9d0)($t1)
/*  f0caa5c:	3c014270 */ 	lui	$at,0x4270
/*  f0caa60:	152000b1 */ 	bnez	$t1,.L0f0cad28
/*  f0caa64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caa68:	44812000 */ 	mtc1	$at,$f4
/*  f0caa6c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0caa70:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0caa74:	e7a400b0 */ 	swc1	$f4,0xb0($sp)
/*  f0caa78:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0caa7c:	5441008b */ 	bnel	$v0,$at,.L0f0cacac
/*  f0caa80:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0caa84:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0caa88:	8fab0230 */ 	lw	$t3,0x230($sp)
/*  f0caa8c:	8caa0120 */ 	lw	$t2,0x120($a1)
/*  f0caa90:	51400086 */ 	beqzl	$t2,.L0f0cacac
/*  f0caa94:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0caa98:	55600006 */ 	bnezl	$t3,.L0f0caab4
/*  f0caa9c:	c4a00258 */ 	lwc1	$f0,0x258($a1)
/*  f0caaa0:	90ac063b */ 	lbu	$t4,0x63b($a1)
/*  f0caaa4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0caaa8:	55810080 */ 	bnel	$t4,$at,.L0f0cacac
/*  f0caaac:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0caab0:	c4a00258 */ 	lwc1	$f0,0x258($a1)
.L0f0caab4:
/*  f0caab4:	44805000 */ 	mtc1	$zero,$f10
/*  f0caab8:	3c0143fa */ 	lui	$at,0x43fa
/*  f0caabc:	4600503c */ 	c.lt.s	$f10,$f0
/*  f0caac0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caac4:	45020079 */ 	bc1fl	.L0f0cacac
/*  f0caac8:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0caacc:	44813000 */ 	mtc1	$at,$f6
/*  f0caad0:	0fc2d26e */ 	jal	func0f0b49b8
/*  f0caad4:	46003303 */ 	div.s	$f12,$f6,$f0
/*  f0caad8:	3c014270 */ 	lui	$at,0x4270
/*  f0caadc:	44816000 */ 	mtc1	$at,$f12
/*  f0caae0:	46000086 */ 	mov.s	$f2,$f0
/*  f0caae4:	3c014000 */ 	lui	$at,0x4000
/*  f0caae8:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0caaec:	44810000 */ 	mtc1	$at,$f0
/*  f0caaf0:	45020003 */ 	bc1fl	.L0f0cab00
/*  f0caaf4:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0caaf8:	46006086 */ 	mov.s	$f2,$f12
/*  f0caafc:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0cab00:
/*  f0cab00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cab04:	45020003 */ 	bc1fl	.L0f0cab14
/*  f0cab08:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0cab0c:	46000086 */ 	mov.s	$f2,$f0
/*  f0cab10:	8e4d0284 */ 	lw	$t5,0x284($s2)
.L0f0cab14:
/*  f0cab14:	e5a216f8 */ 	swc1	$f2,0x16f8($t5)
/*  f0cab18:	0fc2d5be */ 	jal	currentPlayerGetUnk1740
/*  f0cab1c:	e7a200ac */ 	swc1	$f2,0xac($sp)
/*  f0cab20:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0cab24:	27b000a0 */ 	addiu	$s0,$sp,0xa0
/*  f0cab28:	02003025 */ 	or	$a2,$s0,$zero
/*  f0cab2c:	8dc5025c */ 	lw	$a1,0x25c($t6)
/*  f0cab30:	00402025 */ 	or	$a0,$v0,$zero
/*  f0cab34:	0c0056da */ 	jal	func00015b68
/*  f0cab38:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0cab3c:	c7a200ac */ 	lwc1	$f2,0xac($sp)
/*  f0cab40:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0cab44:	02002025 */ 	or	$a0,$s0,$zero
/*  f0cab48:	44061000 */ 	mfc1	$a2,$f2
/*  f0cab4c:	27a50098 */ 	addiu	$a1,$sp,0x98
/*  f0cab50:	0fc2d3ae */ 	jal	func0f0b4eb8
/*  f0cab54:	8de7171c */ 	lw	$a3,0x171c($t7)
/*  f0cab58:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f0cab5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cab60:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f0cab64:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f0cab68:	3c013f00 */ 	lui	$at,0x3f00
/*  f0cab6c:	44818000 */ 	mtc1	$at,$f16
/*  f0cab70:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*  f0cab74:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0cab78:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f0cab7c:	44813000 */ 	mtc1	$at,$f6
/*  f0cab80:	c7a80098 */ 	lwc1	$f8,0x98($sp)
/*  f0cab84:	3c013e80 */ 	lui	$at,0x3e80
/*  f0cab88:	46049280 */ 	add.s	$f10,$f18,$f4
/*  f0cab8c:	46065401 */ 	sub.s	$f16,$f10,$f6
/*  f0cab90:	4610403c */ 	c.lt.s	$f8,$f16
/*  f0cab94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cab98:	45000004 */ 	bc1f	.L0f0cabac
/*  f0cab9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caba0:	44816000 */ 	mtc1	$at,$f12
/*  f0caba4:	10000016 */ 	beqz	$zero,.L0f0cac00
/*  f0caba8:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
.L0f0cabac:
/*  f0cabac:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f0cabb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cabb4:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f0cabb8:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f0cabbc:	3c013f00 */ 	lui	$at,0x3f00
/*  f0cabc0:	44819000 */ 	mtc1	$at,$f18
/*  f0cabc4:	c7aa0054 */ 	lwc1	$f10,0x54($sp)
/*  f0cabc8:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0cabcc:	46120102 */ 	mul.s	$f4,$f0,$f18
/*  f0cabd0:	44814000 */ 	mtc1	$at,$f8
/*  f0cabd4:	c7b20098 */ 	lwc1	$f18,0x98($sp)
/*  f0cabd8:	3c013e80 */ 	lui	$at,0x3e80
/*  f0cabdc:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0cabe0:	46083400 */ 	add.s	$f16,$f6,$f8
/*  f0cabe4:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0cabe8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cabec:	45000004 */ 	bc1f	.L0f0cac00
/*  f0cabf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cabf4:	44810000 */ 	mtc1	$at,$f0
/*  f0cabf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cabfc:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
.L0f0cac00:
/*  f0cac00:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f0cac04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cac08:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f0cac0c:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f0cac10:	3c013f00 */ 	lui	$at,0x3f00
/*  f0cac14:	44815000 */ 	mtc1	$at,$f10
/*  f0cac18:	c7a80054 */ 	lwc1	$f8,0x54($sp)
/*  f0cac1c:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0cac20:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f0cac24:	44819000 */ 	mtc1	$at,$f18
/*  f0cac28:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f0cac2c:	3c013e80 */ 	lui	$at,0x3e80
/*  f0cac30:	46083400 */ 	add.s	$f16,$f6,$f8
/*  f0cac34:	46128281 */ 	sub.s	$f10,$f16,$f18
/*  f0cac38:	460a203c */ 	c.lt.s	$f4,$f10
/*  f0cac3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cac40:	45000004 */ 	bc1f	.L0f0cac54
/*  f0cac44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cac48:	44813000 */ 	mtc1	$at,$f6
/*  f0cac4c:	10000016 */ 	beqz	$zero,.L0f0caca8
/*  f0cac50:	e7a601f0 */ 	swc1	$f6,0x1f0($sp)
.L0f0cac54:
/*  f0cac54:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f0cac58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cac5c:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f0cac60:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f0cac64:	3c013f00 */ 	lui	$at,0x3f00
/*  f0cac68:	44814000 */ 	mtc1	$at,$f8
/*  f0cac6c:	c7b20054 */ 	lwc1	$f18,0x54($sp)
/*  f0cac70:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0cac74:	46080402 */ 	mul.s	$f16,$f0,$f8
/*  f0cac78:	44815000 */ 	mtc1	$at,$f10
/*  f0cac7c:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f0cac80:	3c013e80 */ 	lui	$at,0x3e80
/*  f0cac84:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f0cac88:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0cac8c:	4608303c */ 	c.lt.s	$f6,$f8
/*  f0cac90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cac94:	45020005 */ 	bc1fl	.L0f0cacac
/*  f0cac98:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0cac9c:	44818000 */ 	mtc1	$at,$f16
/*  f0caca0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caca4:	e7b001ec */ 	swc1	$f16,0x1ec($sp)
.L0f0caca8:
/*  f0caca8:	8fb8020c */ 	lw	$t8,0x20c($sp)
.L0f0cacac:
/*  f0cacac:	13000004 */ 	beqz	$t8,.L0f0cacc0
/*  f0cacb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cacb4:	0fc2c536 */ 	jal	func0f0b14d8
/*  f0cacb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cacbc:	e7a000b0 */ 	swc1	$f0,0xb0($sp)
.L0f0cacc0:
/*  f0cacc0:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0cacc4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cacc8:	24010011 */ 	addiu	$at,$zero,0x11
/*  f0caccc:	5441000a */ 	bnel	$v0,$at,.L0f0cacf8
/*  f0cacd0:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0cacd4:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0cacd8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cacdc:	9328063b */ 	lbu	$t0,0x63b($t9)
/*  f0cace0:	55010005 */ 	bnel	$t0,$at,.L0f0cacf8
/*  f0cace4:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0cace8:	0fc2c536 */ 	jal	func0f0b14d8
/*  f0cacec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cacf0:	e7a000b0 */ 	swc1	$f0,0xb0($sp)
/*  f0cacf4:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
.L0f0cacf8:
/*  f0cacf8:	44809000 */ 	mtc1	$zero,$f18
/*  f0cacfc:	3c014270 */ 	lui	$at,0x4270
/*  f0cad00:	4612603e */ 	c.le.s	$f12,$f18
/*  f0cad04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cad08:	45000003 */ 	bc1f	.L0f0cad18
/*  f0cad0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cad10:	44816000 */ 	mtc1	$at,$f12
/*  f0cad14:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cad18:
/*  f0cad18:	0fc2ea2c */ 	jal	func0f0ba8b0
/*  f0cad1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cad20:	0fc2eab0 */ 	jal	currentPlayerUpdateZoom
/*  f0cad24:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cad28:
/*  f0cad28:	0fc31fe6 */ 	jal	func0f0c7f98
/*  f0cad2c:	27a401b4 */ 	addiu	$a0,$sp,0x1b4
/*  f0cad30:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cad34:	8ca90178 */ 	lw	$t1,0x178($a1)
/*  f0cad38:	292100b4 */ 	slti	$at,$t1,0xb4
/*  f0cad3c:	1420001b */ 	bnez	$at,.L0f0cadac
/*  f0cad40:	3c013fa0 */ 	lui	$at,0x3fa0
/*  f0cad44:	44811000 */ 	mtc1	$at,$f2
/*  f0cad48:	c4a00174 */ 	lwc1	$f0,0x174($a1)
/*  f0cad4c:	3c017f1b */ 	lui	$at,%hi(var7f1ad8b8)
/*  f0cad50:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0cad54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cad58:	45020009 */ 	bc1fl	.L0f0cad80
/*  f0cad5c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0cad60:	c424d8b8 */ 	lwc1	$f4,%lo(var7f1ad8b8)($at)
/*  f0cad64:	c64a004c */ 	lwc1	$f10,0x4c($s2)
/*  f0cad68:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f0cad6c:	46060200 */ 	add.s	$f8,$f0,$f6
/*  f0cad70:	e4a80174 */ 	swc1	$f8,0x174($a1)
/*  f0cad74:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cad78:	c4a00174 */ 	lwc1	$f0,0x174($a1)
/*  f0cad7c:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0cad80:
/*  f0cad80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cad84:	45020024 */ 	bc1fl	.L0f0cae18
/*  f0cad88:	8cab1a24 */ 	lw	$t3,0x1a24($a1)
/*  f0cad8c:	0fc20b5d */ 	jal	func0f082d74
/*  f0cad90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cad94:	3c013fa0 */ 	lui	$at,0x3fa0
/*  f0cad98:	44811000 */ 	mtc1	$at,$f2
/*  f0cad9c:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0cada0:	e5420174 */ 	swc1	$f2,0x174($t2)
/*  f0cada4:	1000001b */ 	beqz	$zero,.L0f0cae14
/*  f0cada8:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cadac:
/*  f0cadac:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cadb0:	44818000 */ 	mtc1	$at,$f16
/*  f0cadb4:	c4a00174 */ 	lwc1	$f0,0x174($a1)
/*  f0cadb8:	3c017f1b */ 	lui	$at,%hi(var7f1ad8bc)
/*  f0cadbc:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0cadc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cadc4:	45020009 */ 	bc1fl	.L0f0cadec
/*  f0cadc8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cadcc:	c432d8bc */ 	lwc1	$f18,%lo(var7f1ad8bc)($at)
/*  f0cadd0:	c644004c */ 	lwc1	$f4,0x4c($s2)
/*  f0cadd4:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0cadd8:	460a0181 */ 	sub.s	$f6,$f0,$f10
/*  f0caddc:	e4a60174 */ 	swc1	$f6,0x174($a1)
/*  f0cade0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cade4:	c4a00174 */ 	lwc1	$f0,0x174($a1)
/*  f0cade8:	3c013f80 */ 	lui	$at,0x3f80
.L0f0cadec:
/*  f0cadec:	44814000 */ 	mtc1	$at,$f8
/*  f0cadf0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cadf4:	4608003c */ 	c.lt.s	$f0,$f8
/*  f0cadf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cadfc:	45020006 */ 	bc1fl	.L0f0cae18
/*  f0cae00:	8cab1a24 */ 	lw	$t3,0x1a24($a1)
/*  f0cae04:	44818000 */ 	mtc1	$at,$f16
/*  f0cae08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cae0c:	e4b00174 */ 	swc1	$f16,0x174($a1)
/*  f0cae10:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cae14:
/*  f0cae14:	8cab1a24 */ 	lw	$t3,0x1a24($a1)
.L0f0cae18:
/*  f0cae18:	55600144 */ 	bnezl	$t3,.L0f0cb32c
/*  f0cae1c:	8faa01cc */ 	lw	$t2,0x1cc($sp)
/*  f0cae20:	8ca201b0 */ 	lw	$v0,0x1b0($a1)
/*  f0cae24:	3c01c080 */ 	lui	$at,0xc080
/*  f0cae28:	44817000 */ 	mtc1	$at,$f14
/*  f0cae2c:	2c440001 */ 	sltiu	$a0,$v0,0x1
/*  f0cae30:	54800004 */ 	bnezl	$a0,.L0f0cae44
/*  f0cae34:	8cac0110 */ 	lw	$t4,0x110($a1)
/*  f0cae38:	38440004 */ 	xori	$a0,$v0,0x4
/*  f0cae3c:	2c840001 */ 	sltiu	$a0,$a0,0x1
/*  f0cae40:	8cac0110 */ 	lw	$t4,0x110($a1)
.L0f0cae44:
/*  f0cae44:	51800011 */ 	beqzl	$t4,.L0f0cae8c
/*  f0cae48:	8cb9010c */ 	lw	$t9,0x10c($a1)
/*  f0cae4c:	8e42000c */ 	lw	$v0,0xc($s2)
/*  f0cae50:	94ad1be4 */ 	lhu	$t5,0x1be4($a1)
/*  f0cae54:	504d000c */ 	beql	$v0,$t5,.L0f0cae88
/*  f0cae58:	c4ae1be0 */ 	lwc1	$f14,0x1be0($a1)
/*  f0cae5c:	8e4e028c */ 	lw	$t6,0x28c($s2)
/*  f0cae60:	304f0003 */ 	andi	$t7,$v0,0x3
/*  f0cae64:	55cf0008 */ 	bnel	$t6,$t7,.L0f0cae88
/*  f0cae68:	c4ae1be0 */ 	lwc1	$f14,0x1be0($a1)
/*  f0cae6c:	0fc32166 */ 	jal	func0f0c8598
/*  f0cae70:	afa40064 */ 	sw	$a0,0x64($sp)
/*  f0cae74:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f0cae78:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f0cae7c:	e7001be0 */ 	swc1	$f0,0x1be0($t8)
/*  f0cae80:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cae84:	c4ae1be0 */ 	lwc1	$f14,0x1be0($a1)
.L0f0cae88:
/*  f0cae88:	8cb9010c */ 	lw	$t9,0x10c($a1)
.L0f0cae8c:
/*  f0cae8c:	8fa8025c */ 	lw	$t0,0x25c($sp)
/*  f0cae90:	13200007 */ 	beqz	$t9,.L0f0caeb0
/*  f0cae94:	29010028 */ 	slti	$at,$t0,0x28
/*  f0cae98:	10200005 */ 	beqz	$at,.L0f0caeb0
/*  f0cae9c:	2901ffd9 */ 	slti	$at,$t0,-39
/*  f0caea0:	14200003 */ 	bnez	$at,.L0f0caeb0
/*  f0caea4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caea8:	aca0010c */ 	sw	$zero,0x10c($a1)
/*  f0caeac:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0caeb0:
/*  f0caeb0:	10800064 */ 	beqz	$a0,.L0f0cb044
/*  f0caeb4:	c7a401ec */ 	lwc1	$f4,0x1ec($sp)
/*  f0caeb8:	44809000 */ 	mtc1	$zero,$f18
/*  f0caebc:	c7a601f0 */ 	lwc1	$f6,0x1f0($sp)
/*  f0caec0:	4604903c */ 	c.lt.s	$f18,$f4
/*  f0caec4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caec8:	45030008 */ 	bc1tl	.L0f0caeec
/*  f0caecc:	aca00100 */ 	sw	$zero,0x100($a1)
/*  f0caed0:	44805000 */ 	mtc1	$zero,$f10
/*  f0caed4:	8fac023c */ 	lw	$t4,0x23c($sp)
/*  f0caed8:	4606503c */ 	c.lt.s	$f10,$f6
/*  f0caedc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caee0:	45000009 */ 	bc1f	.L0f0caf08
/*  f0caee4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caee8:	aca00100 */ 	sw	$zero,0x100($a1)
.L0f0caeec:
/*  f0caeec:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f0caef0:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0caef4:	ad490108 */ 	sw	$t1,0x108($t2)
/*  f0caef8:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0caefc:	ad60011c */ 	sw	$zero,0x11c($t3)
/*  f0caf00:	10000050 */ 	beqz	$zero,.L0f0cb044
/*  f0caf04:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0caf08:
/*  f0caf08:	51800005 */ 	beqzl	$t4,.L0f0caf20
/*  f0caf0c:	8cad0114 */ 	lw	$t5,0x114($a1)
/*  f0caf10:	aca0011c */ 	sw	$zero,0x11c($a1)
/*  f0caf14:	10000049 */ 	beqz	$zero,.L0f0cb03c
/*  f0caf18:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0caf1c:	8cad0114 */ 	lw	$t5,0x114($a1)
.L0f0caf20:
/*  f0caf20:	8fae01c4 */ 	lw	$t6,0x1c4($sp)
/*  f0caf24:	51a00026 */ 	beqzl	$t5,.L0f0cafc0
/*  f0caf28:	8caa0118 */ 	lw	$t2,0x118($a1)
/*  f0caf2c:	11c00009 */ 	beqz	$t6,.L0f0caf54
/*  f0caf30:	8faf025c */ 	lw	$t7,0x25c($sp)
/*  f0caf34:	29e1003d */ 	slti	$at,$t7,0x3d
/*  f0caf38:	10200004 */ 	beqz	$at,.L0f0caf4c
/*  f0caf3c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0caf40:	29e1ffc4 */ 	slti	$at,$t7,-60
/*  f0caf44:	50200004 */ 	beqzl	$at,.L0f0caf58
/*  f0caf48:	8cb9011c */ 	lw	$t9,0x11c($a1)
.L0f0caf4c:
/*  f0caf4c:	acb8011c */ 	sw	$t8,0x11c($a1)
/*  f0caf50:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0caf54:
/*  f0caf54:	8cb9011c */ 	lw	$t9,0x11c($a1)
.L0f0caf58:
/*  f0caf58:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0caf5c:	53200038 */ 	beqzl	$t9,.L0f0cb040
/*  f0caf60:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0caf64:	44814000 */ 	mtc1	$at,$f8
/*  f0caf68:	c4a00154 */ 	lwc1	$f0,0x154($a1)
/*  f0caf6c:	3c01c120 */ 	lui	$at,0xc120
/*  f0caf70:	46087400 */ 	add.s	$f16,$f14,$f8
/*  f0caf74:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0caf78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caf7c:	45030009 */ 	bc1tl	.L0f0cafa4
/*  f0caf80:	8ca8010c */ 	lw	$t0,0x10c($a1)
/*  f0caf84:	44819000 */ 	mtc1	$at,$f18
/*  f0caf88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caf8c:	46127100 */ 	add.s	$f4,$f14,$f18
/*  f0caf90:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0caf94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0caf98:	45020029 */ 	bc1fl	.L0f0cb040
/*  f0caf9c:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0cafa0:	8ca8010c */ 	lw	$t0,0x10c($a1)
.L0f0cafa4:
/*  f0cafa4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0cafa8:	55000025 */ 	bnezl	$t0,.L0f0cb040
/*  f0cafac:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0cafb0:	aca90100 */ 	sw	$t1,0x100($a1)
/*  f0cafb4:	10000021 */ 	beqz	$zero,.L0f0cb03c
/*  f0cafb8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cafbc:	8caa0118 */ 	lw	$t2,0x118($a1)
.L0f0cafc0:
/*  f0cafc0:	8fab01c4 */ 	lw	$t3,0x1c4($sp)
/*  f0cafc4:	5140001e */ 	beqzl	$t2,.L0f0cb040
/*  f0cafc8:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0cafcc:	1160001b */ 	beqz	$t3,.L0f0cb03c
/*  f0cafd0:	8fac025c */ 	lw	$t4,0x25c($sp)
/*  f0cafd4:	2981003d */ 	slti	$at,$t4,0x3d
/*  f0cafd8:	10200002 */ 	beqz	$at,.L0f0cafe4
/*  f0cafdc:	2981ffc4 */ 	slti	$at,$t4,-60
/*  f0cafe0:	10200016 */ 	beqz	$at,.L0f0cb03c
.L0f0cafe4:
/*  f0cafe4:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0cafe8:	44815000 */ 	mtc1	$at,$f10
/*  f0cafec:	c4a00154 */ 	lwc1	$f0,0x154($a1)
/*  f0caff0:	3c01c120 */ 	lui	$at,0xc120
/*  f0caff4:	460a7180 */ 	add.s	$f6,$f14,$f10
/*  f0caff8:	4600303c */ 	c.lt.s	$f6,$f0
/*  f0caffc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb000:	45030009 */ 	bc1tl	.L0f0cb028
/*  f0cb004:	8cad010c */ 	lw	$t5,0x10c($a1)
/*  f0cb008:	44814000 */ 	mtc1	$at,$f8
/*  f0cb00c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb010:	46087400 */ 	add.s	$f16,$f14,$f8
/*  f0cb014:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0cb018:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb01c:	45020008 */ 	bc1fl	.L0f0cb040
/*  f0cb020:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0cb024:	8cad010c */ 	lw	$t5,0x10c($a1)
.L0f0cb028:
/*  f0cb028:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0cb02c:	55a00004 */ 	bnezl	$t5,.L0f0cb040
/*  f0cb030:	aca00108 */ 	sw	$zero,0x108($a1)
/*  f0cb034:	acae0100 */ 	sw	$t6,0x100($a1)
/*  f0cb038:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb03c:
/*  f0cb03c:	aca00108 */ 	sw	$zero,0x108($a1)
.L0f0cb040:
/*  f0cb040:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb044:
/*  f0cb044:	8caf01b0 */ 	lw	$t7,0x1b0($a1)
/*  f0cb048:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0cb04c:	55e10004 */ 	bnel	$t7,$at,.L0f0cb060
/*  f0cb050:	8cb80100 */ 	lw	$t8,0x100($a1)
/*  f0cb054:	aca00100 */ 	sw	$zero,0x100($a1)
/*  f0cb058:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb05c:	8cb80100 */ 	lw	$t8,0x100($a1)
.L0f0cb060:
/*  f0cb060:	8fa901d0 */ 	lw	$t1,0x1d0($sp)
/*  f0cb064:	1300004a */ 	beqz	$t8,.L0f0cb190
/*  f0cb068:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb06c:	508000af */ 	beqzl	$a0,.L0f0cb32c
/*  f0cb070:	8faa01cc */ 	lw	$t2,0x1cc($sp)
/*  f0cb074:	c4a2015c */ 	lwc1	$f2,0x15c($a1)
/*  f0cb078:	3c013f00 */ 	lui	$at,0x3f00
/*  f0cb07c:	44812000 */ 	mtc1	$at,$f4
/*  f0cb080:	46021482 */ 	mul.s	$f18,$f2,$f2
/*  f0cb084:	3c017f1b */ 	lui	$at,%hi(var7f1ad8c0)
/*  f0cb088:	c426d8c0 */ 	lwc1	$f6,%lo(var7f1ad8c0)($at)
/*  f0cb08c:	c4a00154 */ 	lwc1	$f0,0x154($a1)
/*  f0cb090:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cb094:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0cb098:	46065303 */ 	div.s	$f12,$f10,$f6
/*  f0cb09c:	460c7200 */ 	add.s	$f8,$f14,$f12
/*  f0cb0a0:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0cb0a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb0a8:	45020007 */ 	bc1fl	.L0f0cb0c8
/*  f0cb0ac:	460c7401 */ 	sub.s	$f16,$f14,$f12
/*  f0cb0b0:	44816000 */ 	mtc1	$at,$f12
/*  f0cb0b4:	0fc3203e */ 	jal	currentPlayerUpdateSpeedVerta
/*  f0cb0b8:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f0cb0bc:	10000010 */ 	beqz	$zero,.L0f0cb100
/*  f0cb0c0:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f0cb0c4:	460c7401 */ 	sub.s	$f16,$f14,$f12
.L0f0cb0c8:
/*  f0cb0c8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0cb0cc:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0cb0d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb0d4:	45020007 */ 	bc1fl	.L0f0cb0f4
/*  f0cb0d8:	44806000 */ 	mtc1	$zero,$f12
/*  f0cb0dc:	44816000 */ 	mtc1	$at,$f12
/*  f0cb0e0:	0fc3203e */ 	jal	currentPlayerUpdateSpeedVerta
/*  f0cb0e4:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f0cb0e8:	10000005 */ 	beqz	$zero,.L0f0cb100
/*  f0cb0ec:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f0cb0f0:	44806000 */ 	mtc1	$zero,$f12
.L0f0cb0f4:
/*  f0cb0f4:	0fc3203e */ 	jal	currentPlayerUpdateSpeedVerta
/*  f0cb0f8:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f0cb0fc:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
.L0f0cb100:
/*  f0cb100:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb104:	c644004c */ 	lwc1	$f4,0x4c($s2)
/*  f0cb108:	c4b2015c */ 	lwc1	$f18,0x15c($a1)
/*  f0cb10c:	c4a00154 */ 	lwc1	$f0,0x154($a1)
/*  f0cb110:	46049082 */ 	mul.s	$f2,$f18,$f4
/*  f0cb114:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0cb118:	46021280 */ 	add.s	$f10,$f2,$f2
/*  f0cb11c:	45000007 */ 	bc1f	.L0f0cb13c
/*  f0cb120:	460a0300 */ 	add.s	$f12,$f0,$f10
/*  f0cb124:	460c703c */ 	c.lt.s	$f14,$f12
/*  f0cb128:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb12c:	45020004 */ 	bc1fl	.L0f0cb140
/*  f0cb130:	460e003c */ 	c.lt.s	$f0,$f14
/*  f0cb134:	1000007c */ 	beqz	$zero,.L0f0cb328
/*  f0cb138:	e4ac0154 */ 	swc1	$f12,0x154($a1)
.L0f0cb13c:
/*  f0cb13c:	460e003c */ 	c.lt.s	$f0,$f14
.L0f0cb140:
/*  f0cb140:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb144:	45020008 */ 	bc1fl	.L0f0cb168
/*  f0cb148:	e4ae0154 */ 	swc1	$f14,0x154($a1)
/*  f0cb14c:	460e603c */ 	c.lt.s	$f12,$f14
/*  f0cb150:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb154:	45020004 */ 	bc1fl	.L0f0cb168
/*  f0cb158:	e4ae0154 */ 	swc1	$f14,0x154($a1)
/*  f0cb15c:	10000072 */ 	beqz	$zero,.L0f0cb328
/*  f0cb160:	e4ac0154 */ 	swc1	$f12,0x154($a1)
/*  f0cb164:	e4ae0154 */ 	swc1	$f14,0x154($a1)
.L0f0cb168:
/*  f0cb168:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f0cb16c:	44803000 */ 	mtc1	$zero,$f6
/*  f0cb170:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb174:	e726015c */ 	swc1	$f6,0x15c($t9)
/*  f0cb178:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb17c:	8ca80108 */ 	lw	$t0,0x108($a1)
/*  f0cb180:	5500006a */ 	bnezl	$t0,.L0f0cb32c
/*  f0cb184:	8faa01cc */ 	lw	$t2,0x1cc($sp)
/*  f0cb188:	10000067 */ 	beqz	$zero,.L0f0cb328
/*  f0cb18c:	aca00100 */ 	sw	$zero,0x100($a1)
.L0f0cb190:
/*  f0cb190:	1120002f */ 	beqz	$t1,.L0f0cb250
/*  f0cb194:	c7a601ec */ 	lwc1	$f6,0x1ec($sp)
/*  f0cb198:	0c002f9d */ 	jal	func0000be74
/*  f0cb19c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb1a0:	8faa0254 */ 	lw	$t2,0x254($sp)
/*  f0cb1a4:	3c014270 */ 	lui	$at,0x4270
/*  f0cb1a8:	44814000 */ 	mtc1	$at,$f8
/*  f0cb1ac:	448a8000 */ 	mtc1	$t2,$f16
/*  f0cb1b0:	3c01428c */ 	lui	$at,0x428c
/*  f0cb1b4:	44812000 */ 	mtc1	$at,$f4
/*  f0cb1b8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0cb1bc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cb1c0:	44815000 */ 	mtc1	$at,$f10
/*  f0cb1c4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0cb1c8:	46080383 */ 	div.s	$f14,$f0,$f8
/*  f0cb1cc:	44804000 */ 	mtc1	$zero,$f8
/*  f0cb1d0:	46049303 */ 	div.s	$f12,$f18,$f4
/*  f0cb1d4:	460c503c */ 	c.lt.s	$f10,$f12
/*  f0cb1d8:	46006086 */ 	mov.s	$f2,$f12
/*  f0cb1dc:	45020006 */ 	bc1fl	.L0f0cb1f8
/*  f0cb1e0:	44813000 */ 	mtc1	$at,$f6
/*  f0cb1e4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cb1e8:	44811000 */ 	mtc1	$at,$f2
/*  f0cb1ec:	1000000a */ 	beqz	$zero,.L0f0cb218
/*  f0cb1f0:	4602403e */ 	c.le.s	$f8,$f2
/*  f0cb1f4:	44813000 */ 	mtc1	$at,$f6
.L0f0cb1f8:
/*  f0cb1f8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0cb1fc:	4606603c */ 	c.lt.s	$f12,$f6
/*  f0cb200:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb204:	45020004 */ 	bc1fl	.L0f0cb218
/*  f0cb208:	4602403e */ 	c.le.s	$f8,$f2
/*  f0cb20c:	44811000 */ 	mtc1	$at,$f2
/*  f0cb210:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb214:	4602403e */ 	c.le.s	$f8,$f2
.L0f0cb218:
/*  f0cb218:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb21c:	45020005 */ 	bc1fl	.L0f0cb234
/*  f0cb220:	46001407 */ 	neg.s	$f16,$f2
/*  f0cb224:	46021082 */ 	mul.s	$f2,$f2,$f2
/*  f0cb228:	10000005 */ 	beqz	$zero,.L0f0cb240
/*  f0cb22c:	46001487 */ 	neg.s	$f18,$f2
/*  f0cb230:	46001407 */ 	neg.s	$f16,$f2
.L0f0cb234:
/*  f0cb234:	46101082 */ 	mul.s	$f2,$f2,$f16
/*  f0cb238:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb23c:	46001487 */ 	neg.s	$f18,$f2
.L0f0cb240:
/*  f0cb240:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f0cb244:	460e9102 */ 	mul.s	$f4,$f18,$f14
/*  f0cb248:	1000002c */ 	beqz	$zero,.L0f0cb2fc
/*  f0cb24c:	e564015c */ 	swc1	$f4,0x15c($t3)
.L0f0cb250:
/*  f0cb250:	44805000 */ 	mtc1	$zero,$f10
/*  f0cb254:	c7b001f0 */ 	lwc1	$f16,0x1f0($sp)
/*  f0cb258:	4606503c */ 	c.lt.s	$f10,$f6
/*  f0cb25c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb260:	45020010 */ 	bc1fl	.L0f0cb2a4
/*  f0cb264:	44804000 */ 	mtc1	$zero,$f8
/*  f0cb268:	0fc3203e */ 	jal	currentPlayerUpdateSpeedVerta
/*  f0cb26c:	46003306 */ 	mov.s	$f12,$f6
/*  f0cb270:	8fac01c4 */ 	lw	$t4,0x1c4($sp)
/*  f0cb274:	8fad025c */ 	lw	$t5,0x25c($sp)
/*  f0cb278:	11800020 */ 	beqz	$t4,.L0f0cb2fc
/*  f0cb27c:	29a1003d */ 	slti	$at,$t5,0x3d
/*  f0cb280:	10200003 */ 	beqz	$at,.L0f0cb290
/*  f0cb284:	29a1ffc4 */ 	slti	$at,$t5,-60
/*  f0cb288:	5020001d */ 	beqzl	$at,.L0f0cb300
/*  f0cb28c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb290:
/*  f0cb290:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0cb294:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0cb298:	10000018 */ 	beqz	$zero,.L0f0cb2fc
/*  f0cb29c:	adee010c */ 	sw	$t6,0x10c($t7)
/*  f0cb2a0:	44804000 */ 	mtc1	$zero,$f8
.L0f0cb2a4:
/*  f0cb2a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb2a8:	4610403c */ 	c.lt.s	$f8,$f16
/*  f0cb2ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb2b0:	45020010 */ 	bc1fl	.L0f0cb2f4
/*  f0cb2b4:	44806000 */ 	mtc1	$zero,$f12
/*  f0cb2b8:	0fc3203e */ 	jal	currentPlayerUpdateSpeedVerta
/*  f0cb2bc:	46008307 */ 	neg.s	$f12,$f16
/*  f0cb2c0:	8fb801c4 */ 	lw	$t8,0x1c4($sp)
/*  f0cb2c4:	8fb9025c */ 	lw	$t9,0x25c($sp)
/*  f0cb2c8:	1300000c */ 	beqz	$t8,.L0f0cb2fc
/*  f0cb2cc:	2b21003d */ 	slti	$at,$t9,0x3d
/*  f0cb2d0:	10200003 */ 	beqz	$at,.L0f0cb2e0
/*  f0cb2d4:	2b21ffc4 */ 	slti	$at,$t9,-60
/*  f0cb2d8:	50200009 */ 	beqzl	$at,.L0f0cb300
/*  f0cb2dc:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb2e0:
/*  f0cb2e0:	8e490284 */ 	lw	$t1,0x284($s2)
/*  f0cb2e4:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0cb2e8:	10000004 */ 	beqz	$zero,.L0f0cb2fc
/*  f0cb2ec:	ad28010c */ 	sw	$t0,0x10c($t1)
/*  f0cb2f0:	44806000 */ 	mtc1	$zero,$f12
.L0f0cb2f4:
/*  f0cb2f4:	0fc3203e */ 	jal	currentPlayerUpdateSpeedVerta
/*  f0cb2f8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cb2fc:
/*  f0cb2fc:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb300:
/*  f0cb300:	c644004c */ 	lwc1	$f4,0x4c($s2)
/*  f0cb304:	3c014060 */ 	lui	$at,0x4060
/*  f0cb308:	c4b2015c */ 	lwc1	$f18,0x15c($a1)
/*  f0cb30c:	44813000 */ 	mtc1	$at,$f6
/*  f0cb310:	c4b00154 */ 	lwc1	$f16,0x154($a1)
/*  f0cb314:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0cb318:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb31c:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0cb320:	46088480 */ 	add.s	$f18,$f16,$f8
/*  f0cb324:	e4b20154 */ 	swc1	$f18,0x154($a1)
.L0f0cb328:
/*  f0cb328:	8faa01cc */ 	lw	$t2,0x1cc($sp)
.L0f0cb32c:
/*  f0cb32c:	c7ac01f4 */ 	lwc1	$f12,0x1f4($sp)
/*  f0cb330:	5140002d */ 	beqzl	$t2,.L0f0cb3e8
/*  f0cb334:	44804000 */ 	mtc1	$zero,$f8
/*  f0cb338:	0c002f9d */ 	jal	func0000be74
/*  f0cb33c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb340:	8fab0250 */ 	lw	$t3,0x250($sp)
/*  f0cb344:	3c01428c */ 	lui	$at,0x428c
/*  f0cb348:	44813000 */ 	mtc1	$at,$f6
/*  f0cb34c:	448b2000 */ 	mtc1	$t3,$f4
/*  f0cb350:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cb354:	44818000 */ 	mtc1	$at,$f16
/*  f0cb358:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0cb35c:	44809000 */ 	mtc1	$zero,$f18
/*  f0cb360:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0cb364:	46065303 */ 	div.s	$f12,$f10,$f6
/*  f0cb368:	460c803c */ 	c.lt.s	$f16,$f12
/*  f0cb36c:	46006086 */ 	mov.s	$f2,$f12
/*  f0cb370:	45020006 */ 	bc1fl	.L0f0cb38c
/*  f0cb374:	44814000 */ 	mtc1	$at,$f8
/*  f0cb378:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cb37c:	44811000 */ 	mtc1	$at,$f2
/*  f0cb380:	1000000a */ 	beqz	$zero,.L0f0cb3ac
/*  f0cb384:	4602903e */ 	c.le.s	$f18,$f2
/*  f0cb388:	44814000 */ 	mtc1	$at,$f8
.L0f0cb38c:
/*  f0cb38c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0cb390:	4608603c */ 	c.lt.s	$f12,$f8
/*  f0cb394:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb398:	45020004 */ 	bc1fl	.L0f0cb3ac
/*  f0cb39c:	4602903e */ 	c.le.s	$f18,$f2
/*  f0cb3a0:	44811000 */ 	mtc1	$at,$f2
/*  f0cb3a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb3a8:	4602903e */ 	c.le.s	$f18,$f2
.L0f0cb3ac:
/*  f0cb3ac:	3c014270 */ 	lui	$at,0x4270
/*  f0cb3b0:	44815000 */ 	mtc1	$at,$f10
/*  f0cb3b4:	45000004 */ 	bc1f	.L0f0cb3c8
/*  f0cb3b8:	460a0183 */ 	div.s	$f6,$f0,$f10
/*  f0cb3bc:	46021082 */ 	mul.s	$f2,$f2,$f2
/*  f0cb3c0:	10000004 */ 	beqz	$zero,.L0f0cb3d4
/*  f0cb3c4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cb3c8:
/*  f0cb3c8:	46001107 */ 	neg.s	$f4,$f2
/*  f0cb3cc:	46041082 */ 	mul.s	$f2,$f2,$f4
/*  f0cb3d0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cb3d4:
/*  f0cb3d4:	46061402 */ 	mul.s	$f16,$f2,$f6
/*  f0cb3d8:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f0cb3dc:	10000019 */ 	beqz	$zero,.L0f0cb444
/*  f0cb3e0:	e5901b9c */ 	swc1	$f16,0x1b9c($t4)
/*  f0cb3e4:	44804000 */ 	mtc1	$zero,$f8
.L0f0cb3e8:
/*  f0cb3e8:	c7a001f8 */ 	lwc1	$f0,0x1f8($sp)
/*  f0cb3ec:	460c403c */ 	c.lt.s	$f8,$f12
/*  f0cb3f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb3f4:	45020006 */ 	bc1fl	.L0f0cb410
/*  f0cb3f8:	44809000 */ 	mtc1	$zero,$f18
/*  f0cb3fc:	0fc320e5 */ 	jal	currentPlayerUpdateSpeedThetaControl
/*  f0cb400:	e7ac01f4 */ 	swc1	$f12,0x1f4($sp)
/*  f0cb404:	10000010 */ 	beqz	$zero,.L0f0cb448
/*  f0cb408:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb40c:	44809000 */ 	mtc1	$zero,$f18
.L0f0cb410:
/*  f0cb410:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb414:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0cb418:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb41c:	45020007 */ 	bc1fl	.L0f0cb43c
/*  f0cb420:	44806000 */ 	mtc1	$zero,$f12
/*  f0cb424:	46000307 */ 	neg.s	$f12,$f0
/*  f0cb428:	0fc320e5 */ 	jal	currentPlayerUpdateSpeedThetaControl
/*  f0cb42c:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
/*  f0cb430:	10000005 */ 	beqz	$zero,.L0f0cb448
/*  f0cb434:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb438:	44806000 */ 	mtc1	$zero,$f12
.L0f0cb43c:
/*  f0cb43c:	0fc320e5 */ 	jal	currentPlayerUpdateSpeedThetaControl
/*  f0cb440:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cb444:
/*  f0cb444:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb448:
/*  f0cb448:	c4a41b9c */ 	lwc1	$f4,0x1b9c($a1)
/*  f0cb44c:	0fc32001 */ 	jal	func0f0c8004
/*  f0cb450:	e4a40148 */ 	swc1	$f4,0x148($a1)
/*  f0cb454:	8fad0228 */ 	lw	$t5,0x228($sp)
/*  f0cb458:	51a00008 */ 	beqzl	$t5,.L0f0cb47c
/*  f0cb45c:	8e5802ac */ 	lw	$t8,0x2ac($s2)
/*  f0cb460:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0cb464:	adc00658 */ 	sw	$zero,0x658($t6)
/*  f0cb468:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0cb46c:	ade0065c */ 	sw	$zero,0x65c($t7)
/*  f0cb470:	0fc22a7d */ 	jal	func0f08a9f4
/*  f0cb474:	8e44028c */ 	lw	$a0,0x28c($s2)
/*  f0cb478:	8e5802ac */ 	lw	$t8,0x2ac($s2)
.L0f0cb47c:
/*  f0cb47c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0cb480:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0cb484:	57010003 */ 	bnel	$t8,$at,.L0f0cb494
/*  f0cb488:	8e59000c */ 	lw	$t9,0xc($s2)
/*  f0cb48c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0cb490:	8e59000c */ 	lw	$t9,0xc($s2)
.L0f0cb494:
/*  f0cb494:	2b21000a */ 	slti	$at,$t9,0xa
/*  f0cb498:	10200002 */ 	beqz	$at,.L0f0cb4a4
/*  f0cb49c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb4a0:	00001025 */ 	or	$v0,$zero,$zero
.L0f0cb4a4:
/*  f0cb4a4:	5040001a */ 	beqzl	$v0,.L0f0cb510
/*  f0cb4a8:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb4ac:	8fa201fc */ 	lw	$v0,0x1fc($sp)
/*  f0cb4b0:	0002202a */ 	slt	$a0,$zero,$v0
/*  f0cb4b4:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0cb4b8:	10800008 */ 	beqz	$a0,.L0f0cb4dc
/*  f0cb4bc:	afa201fc */ 	sw	$v0,0x1fc($sp)
.L0f0cb4c0:
/*  f0cb4c0:	0fc2870b */ 	jal	func0f0a1c2c
/*  f0cb4c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb4c8:	8fa201fc */ 	lw	$v0,0x1fc($sp)
/*  f0cb4cc:	0002202a */ 	slt	$a0,$zero,$v0
/*  f0cb4d0:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0cb4d4:	1480fffa */ 	bnez	$a0,.L0f0cb4c0
/*  f0cb4d8:	afa201fc */ 	sw	$v0,0x1fc($sp)
.L0f0cb4dc:
/*  f0cb4dc:	8fa20200 */ 	lw	$v0,0x200($sp)
/*  f0cb4e0:	0002202a */ 	slt	$a0,$zero,$v0
/*  f0cb4e4:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0cb4e8:	10800008 */ 	beqz	$a0,.L0f0cb50c
/*  f0cb4ec:	afa20200 */ 	sw	$v0,0x200($sp)
.L0f0cb4f0:
/*  f0cb4f0:	0fc286d4 */ 	jal	func0f0a1b50
/*  f0cb4f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb4f8:	8fa20200 */ 	lw	$v0,0x200($sp)
/*  f0cb4fc:	0002202a */ 	slt	$a0,$zero,$v0
/*  f0cb500:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f0cb504:	1480fffa */ 	bnez	$a0,.L0f0cb4f0
/*  f0cb508:	afa20200 */ 	sw	$v0,0x200($sp)
.L0f0cb50c:
/*  f0cb50c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb510:
/*  f0cb510:	8fa901b4 */ 	lw	$t1,0x1b4($sp)
/*  f0cb514:	8ca81c64 */ 	lw	$t0,0x1c64($a1)
/*  f0cb518:	11000003 */ 	beqz	$t0,.L0f0cb528
/*  f0cb51c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb520:	10000093 */ 	beqz	$zero,.L0f0cb770
/*  f0cb524:	aca01c64 */ 	sw	$zero,0x1c64($a1)
.L0f0cb528:
/*  f0cb528:	1120007d */ 	beqz	$t1,.L0f0cb720
/*  f0cb52c:	8fb901b8 */ 	lw	$t9,0x1b8($sp)
/*  f0cb530:	0fc2a4f4 */ 	jal	currentPlayerSetAimType
/*  f0cb534:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cb538:	8faa022c */ 	lw	$t2,0x22c($sp)
/*  f0cb53c:	11400015 */ 	beqz	$t2,.L0f0cb594
/*  f0cb540:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb544:	0fc31ef4 */ 	jal	func0f0c7bd0
/*  f0cb548:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb54c:	54400006 */ 	bnezl	$v0,.L0f0cb568
/*  f0cb550:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb554:	0fc31ea3 */ 	jal	func0f0c7a8c
/*  f0cb558:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb55c:	1040000d */ 	beqz	$v0,.L0f0cb594
/*  f0cb560:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb564:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb568:
/*  f0cb568:	8cab013c */ 	lw	$t3,0x13c($a1)
/*  f0cb56c:	11600009 */ 	beqz	$t3,.L0f0cb594
/*  f0cb570:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb574:	8cac012c */ 	lw	$t4,0x12c($a1)
/*  f0cb578:	8fa401ac */ 	lw	$a0,0x1ac($sp)
/*  f0cb57c:	11800005 */ 	beqz	$t4,.L0f0cb594
/*  f0cb580:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb584:	0fc2c601 */ 	jal	func0f0b1804
/*  f0cb588:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f0cb58c:	5440000b */ 	bnezl	$v0,.L0f0cb5bc
/*  f0cb590:	00008025 */ 	or	$s0,$zero,$zero
.L0f0cb594:
/*  f0cb594:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0cb598:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cb59c:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0cb5a0:	54410037 */ 	bnel	$v0,$at,.L0f0cb680
/*  f0cb5a4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb5a8:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f0cb5ac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cb5b0:	91ae063b */ 	lbu	$t6,0x63b($t5)
/*  f0cb5b4:	15c10031 */ 	bne	$t6,$at,.L0f0cb67c
/*  f0cb5b8:	00008025 */ 	or	$s0,$zero,$zero
.L0f0cb5bc:
/*  f0cb5bc:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f0cb5c0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cb5c4:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0cb5c8:	54410008 */ 	bnel	$v0,$at,.L0f0cb5ec
/*  f0cb5cc:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb5d0:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0cb5d4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cb5d8:	91f8063b */ 	lbu	$t8,0x63b($t7)
/*  f0cb5dc:	57010003 */ 	bnel	$t8,$at,.L0f0cb5ec
/*  f0cb5e0:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb5e4:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0cb5e8:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb5ec:
/*  f0cb5ec:	3c017f1b */ 	lui	$at,%hi(var7f1ad8c4)
/*  f0cb5f0:	c422d8c4 */ 	lwc1	$f2,%lo(var7f1ad8c4)($at)
/*  f0cb5f4:	c4a01b68 */ 	lwc1	$f0,0x1b68($a1)
/*  f0cb5f8:	3c017f1b */ 	lui	$at,%hi(var7f1ad8c8)
/*  f0cb5fc:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0cb600:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb604:	45020009 */ 	bc1fl	.L0f0cb62c
/*  f0cb608:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0cb60c:	c42ad8c8 */ 	lwc1	$f10,%lo(var7f1ad8c8)($at)
/*  f0cb610:	c646004c */ 	lwc1	$f6,0x4c($s2)
/*  f0cb614:	46065402 */ 	mul.s	$f16,$f10,$f6
/*  f0cb618:	46100201 */ 	sub.s	$f8,$f0,$f16
/*  f0cb61c:	e4a81b68 */ 	swc1	$f8,0x1b68($a1)
/*  f0cb620:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb624:	c4a01b68 */ 	lwc1	$f0,0x1b68($a1)
/*  f0cb628:	4602003c */ 	c.lt.s	$f0,$f2
.L0f0cb62c:
/*  f0cb62c:	3c017f1b */ 	lui	$at,%hi(var7f1ad8cc)
/*  f0cb630:	45020005 */ 	bc1fl	.L0f0cb648
/*  f0cb634:	c4ac0138 */ 	lwc1	$f12,0x138($a1)
/*  f0cb638:	e4a21b68 */ 	swc1	$f2,0x1b68($a1)
/*  f0cb63c:	3c05800a */ 	lui	$a1,%hi(g_Vars+0x284)
/*  f0cb640:	8ca5a244 */ 	lw	$a1,%lo(g_Vars+0x284)($a1)
/*  f0cb644:	c4ac0138 */ 	lwc1	$f12,0x138($a1)
.L0f0cb648:
/*  f0cb648:	12000008 */ 	beqz	$s0,.L0f0cb66c
/*  f0cb64c:	c4ae0128 */ 	lwc1	$f14,0x128($a1)
/*  f0cb650:	c420d8cc */ 	lwc1	$f0,%lo(var7f1ad8cc)($at)
/*  f0cb654:	44060000 */ 	mfc1	$a2,$f0
/*  f0cb658:	44070000 */ 	mfc1	$a3,$f0
/*  f0cb65c:	0fc280e5 */ 	jal	func0f0a0394
/*  f0cb660:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb664:	10000043 */ 	beqz	$zero,.L0f0cb774
/*  f0cb668:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0cb66c:
/*  f0cb66c:	0fc282cc */ 	jal	func0f0a0b30
/*  f0cb670:	8ca61b68 */ 	lw	$a2,0x1b68($a1)
/*  f0cb674:	1000003f */ 	beqz	$zero,.L0f0cb774
/*  f0cb678:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0cb67c:
/*  f0cb67c:	8e450284 */ 	lw	$a1,0x284($s2)
.L0f0cb680:
/*  f0cb680:	3c017f1b */ 	lui	$at,%hi(var7f1ad8d0)
/*  f0cb684:	c422d8d0 */ 	lwc1	$f2,%lo(var7f1ad8d0)($at)
/*  f0cb688:	c4a01b68 */ 	lwc1	$f0,0x1b68($a1)
/*  f0cb68c:	3c017f1b */ 	lui	$at,%hi(var7f1ad8d4)
/*  f0cb690:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0cb694:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb698:	45020009 */ 	bc1fl	.L0f0cb6c0
/*  f0cb69c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0cb6a0:	c432d8d4 */ 	lwc1	$f18,%lo(var7f1ad8d4)($at)
/*  f0cb6a4:	c644004c */ 	lwc1	$f4,0x4c($s2)
/*  f0cb6a8:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0cb6ac:	460a0180 */ 	add.s	$f6,$f0,$f10
/*  f0cb6b0:	e4a61b68 */ 	swc1	$f6,0x1b68($a1)
/*  f0cb6b4:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb6b8:	c4a01b68 */ 	lwc1	$f0,0x1b68($a1)
/*  f0cb6bc:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0cb6c0:
/*  f0cb6c0:	3c017f1b */ 	lui	$at,%hi(var7f1ad8d8)
/*  f0cb6c4:	45000004 */ 	bc1f	.L0f0cb6d8
/*  f0cb6c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb6cc:	e4a21b68 */ 	swc1	$f2,0x1b68($a1)
/*  f0cb6d0:	3c05800a */ 	lui	$a1,%hi(g_Vars+0x284)
/*  f0cb6d4:	8ca5a244 */ 	lw	$a1,%lo(g_Vars+0x284)($a1)
.L0f0cb6d8:
/*  f0cb6d8:	c422d8d8 */ 	lwc1	$f2,%lo(var7f1ad8d8)($at)
/*  f0cb6dc:	3c017f1b */ 	lui	$at,%hi(var7f1ad8dc)
/*  f0cb6e0:	c428d8dc */ 	lwc1	$f8,%lo(var7f1ad8dc)($at)
/*  f0cb6e4:	c4b00148 */ 	lwc1	$f16,0x148($a1)
/*  f0cb6e8:	c4aa015c */ 	lwc1	$f10,0x15c($a1)
/*  f0cb6ec:	3c017f1b */ 	lui	$at,%hi(var7f1ad8e0)
/*  f0cb6f0:	46088482 */ 	mul.s	$f18,$f16,$f8
/*  f0cb6f4:	c430d8e0 */ 	lwc1	$f16,%lo(var7f1ad8e0)($at)
/*  f0cb6f8:	46005187 */ 	neg.s	$f6,$f10
/*  f0cb6fc:	c4a401b4 */ 	lwc1	$f4,0x1b4($a1)
/*  f0cb700:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f0cb704:	44061000 */ 	mfc1	$a2,$f2
/*  f0cb708:	46049300 */ 	add.s	$f12,$f18,$f4
/*  f0cb70c:	c4b201b8 */ 	lwc1	$f18,0x1b8($a1)
/*  f0cb710:	0fc282cc */ 	jal	func0f0a0b30
/*  f0cb714:	46124380 */ 	add.s	$f14,$f8,$f18
/*  f0cb718:	10000016 */ 	beqz	$zero,.L0f0cb774
/*  f0cb71c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0cb720:
/*  f0cb720:	53200014 */ 	beqzl	$t9,.L0f0cb774
/*  f0cb724:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0cb728:	0fc2a4f4 */ 	jal	currentPlayerSetAimType
/*  f0cb72c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cb730:	8fa30248 */ 	lw	$v1,0x248($sp)
/*  f0cb734:	8fa4024c */ 	lw	$a0,0x24c($sp)
/*  f0cb738:	3c017f1b */ 	lui	$at,%hi(var7f1ad8e4)
/*  f0cb73c:	44832000 */ 	mtc1	$v1,$f4
/*  f0cb740:	44848000 */ 	mtc1	$a0,$f16
/*  f0cb744:	c420d8e4 */ 	lwc1	$f0,%lo(var7f1ad8e4)($at)
/*  f0cb748:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0cb74c:	3c0142a0 */ 	lui	$at,0x42a0
/*  f0cb750:	44811000 */ 	mtc1	$at,$f2
/*  f0cb754:	46808220 */ 	cvt.s.w	$f8,$f16
/*  f0cb758:	46005182 */ 	mul.s	$f6,$f10,$f0
/*  f0cb75c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb760:	46004482 */ 	mul.s	$f18,$f8,$f0
/*  f0cb764:	46023303 */ 	div.s	$f12,$f6,$f2
/*  f0cb768:	0fc282e6 */ 	jal	func0f0a0b98
/*  f0cb76c:	46029383 */ 	div.s	$f14,$f18,$f2
.L0f0cb770:
/*  f0cb770:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0cb774:
/*  f0cb774:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0cb778:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0cb77c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0cb780:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0cb784:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0cb788:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0cb78c:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f0cb790:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f0cb794:	03e00008 */ 	jr	$ra
/*  f0cb798:	27bd0260 */ 	addiu	$sp,$sp,0x260
);

void func0f0cb79c(struct player *player, struct coord *mid, s16 *rooms)
{
	struct coord lower;
	struct coord upper;
	f32 eyeheight = g_Vars.players[propGetPlayerNum(player->prop)]->vv_eyeheight;
	f32 headheight = g_Vars.players[propGetPlayerNum(player->prop)]->vv_headheight;

	lower.x = mid->x - 50;
	lower.y = mid->y - player->crouchheight - eyeheight - 10;
	lower.z = mid->z - 50;

	upper.x = mid->x + 50;
	upper.y = mid->y - player->crouchheight - eyeheight + headheight + 10;
	upper.z = mid->z + 50;

	func0f1650d0(&lower, &upper, rooms, 7, 0);
}

void func0f0cb89c(struct player *player, s16 *rooms)
{
	func0f0cb79c(player, &player->prop->pos, rooms);
}

void func0f0cb8c4(struct player *player)
{
	func0f065c44(player->prop);
	func0f0cb89c(player, player->prop->rooms);
	func0f065cb0(player->prop);
}

GLOBAL_ASM(
glabel func0f0cb904
.late_rodata
glabel var7f1ad8e8
.word 0x38d1b717
glabel var7f1ad8ec
.word 0x3d088889
.text
/*  f0cb904:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0cb908:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0cb90c:	44801000 */ 	mtc1	$zero,$f2
/*  f0cb910:	c48e0000 */ 	lwc1	$f14,0x0($a0)
/*  f0cb914:	460e1032 */ 	c.eq.s	$f2,$f14
/*  f0cb918:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb91c:	45020007 */ 	bc1fl	.L0f0cb93c
/*  f0cb920:	c4800008 */ 	lwc1	$f0,0x8($a0)
/*  f0cb924:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f0cb928:	46041032 */ 	c.eq.s	$f2,$f4
/*  f0cb92c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb930:	45030052 */ 	bc1tl	.L0f0cba7c
/*  f0cb934:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cb938:	c4800008 */ 	lwc1	$f0,0x8($a0)
.L0f0cb93c:
/*  f0cb93c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0cb940:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f0cb944:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb948:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*  f0cb94c:	0c012974 */ 	jal	sqrtf
/*  f0cb950:	46083300 */ 	add.s	$f12,$f6,$f8
/*  f0cb954:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f0cb958:	44818000 */ 	mtc1	$at,$f16
/*  f0cb95c:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f0cb960:	44801000 */ 	mtc1	$zero,$f2
/*  f0cb964:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0cb968:	46000306 */ 	mov.s	$f12,$f0
/*  f0cb96c:	3c017f1b */ 	lui	$at,%hi(var7f1ad8e8)
/*  f0cb970:	00001825 */ 	or	$v1,$zero,$zero
/*  f0cb974:	4500000a */ 	bc1f	.L0f0cb9a0
/*  f0cb978:	00801025 */ 	or	$v0,$a0,$zero
/*  f0cb97c:	46008383 */ 	div.s	$f14,$f16,$f0
/*  f0cb980:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f0cb984:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f0cb988:	46008306 */ 	mov.s	$f12,$f16
/*  f0cb98c:	460e5482 */ 	mul.s	$f18,$f10,$f14
/*  f0cb990:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb994:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f0cb998:	e4920000 */ 	swc1	$f18,0x0($a0)
/*  f0cb99c:	e4860008 */ 	swc1	$f6,0x8($a0)
.L0f0cb9a0:
/*  f0cb9a0:	c430d8e8 */ 	lwc1	$f16,%lo(var7f1ad8e8)($at)
/*  f0cb9a4:	3c017f1b */ 	lui	$at,%hi(var7f1ad8ec)
/*  f0cb9a8:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0cb9ac:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0cb9b0:	c42ed8ec */ 	lwc1	$f14,%lo(var7f1ad8ec)($at)
/*  f0cb9b4:	2405000c */ 	addiu	$a1,$zero,0xc
.L0f0cb9b8:
/*  f0cb9b8:	460c803c */ 	c.lt.s	$f16,$f12
/*  f0cb9bc:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0cb9c0:	4502002b */ 	bc1fl	.L0f0cba70
/*  f0cb9c4:	e4420000 */ 	swc1	$f2,0x0($v0)
/*  f0cb9c8:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f0cb9cc:	46001032 */ 	c.eq.s	$f2,$f0
/*  f0cb9d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb9d4:	45010026 */ 	bc1t	.L0f0cba70
/*  f0cb9d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb9dc:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0cb9e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb9e4:	45020010 */ 	bc1fl	.L0f0cba28
/*  f0cb9e8:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0cb9ec:	c488004c */ 	lwc1	$f8,0x4c($a0)
/*  f0cb9f0:	46087282 */ 	mul.s	$f10,$f14,$f8
/*  f0cb9f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cb9f8:	46005482 */ 	mul.s	$f18,$f10,$f0
/*  f0cb9fc:	460c9103 */ 	div.s	$f4,$f18,$f12
/*  f0cba00:	46040181 */ 	sub.s	$f6,$f0,$f4
/*  f0cba04:	e4460000 */ 	swc1	$f6,0x0($v0)
/*  f0cba08:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f0cba0c:	4602403c */ 	c.lt.s	$f8,$f2
/*  f0cba10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cba14:	45000016 */ 	bc1f	.L0f0cba70
/*  f0cba18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cba1c:	10000014 */ 	beqz	$zero,.L0f0cba70
/*  f0cba20:	e4420000 */ 	swc1	$f2,0x0($v0)
/*  f0cba24:	4602003c */ 	c.lt.s	$f0,$f2
.L0f0cba28:
/*  f0cba28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cba2c:	45000010 */ 	bc1f	.L0f0cba70
/*  f0cba30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cba34:	c48a004c */ 	lwc1	$f10,0x4c($a0)
/*  f0cba38:	460a7482 */ 	mul.s	$f18,$f14,$f10
/*  f0cba3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cba40:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0cba44:	460c2183 */ 	div.s	$f6,$f4,$f12
/*  f0cba48:	46060201 */ 	sub.s	$f8,$f0,$f6
/*  f0cba4c:	e4480000 */ 	swc1	$f8,0x0($v0)
/*  f0cba50:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f0cba54:	460a103c */ 	c.lt.s	$f2,$f10
/*  f0cba58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cba5c:	45000004 */ 	bc1f	.L0f0cba70
/*  f0cba60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cba64:	10000002 */ 	beqz	$zero,.L0f0cba70
/*  f0cba68:	e4420000 */ 	swc1	$f2,0x0($v0)
/*  f0cba6c:	e4420000 */ 	swc1	$f2,0x0($v0)
.L0f0cba70:
/*  f0cba70:	1465ffd1 */ 	bne	$v1,$a1,.L0f0cb9b8
/*  f0cba74:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f0cba78:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0cba7c:
/*  f0cba7c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0cba80:	03e00008 */ 	jr	$ra
/*  f0cba84:	00000000 */ 	sll	$zero,$zero,0x0
);

void func0f0cba88(f32 *a, f32 *b, struct coord *c, f32 mult1, f32 mult2)
{
	if (c->x != 0 || c->z != 0) {
		func0f0cb904(c);
		*a = c->z * mult2 + -c->x * mult1;
		*b = -c->x * mult2 - c->z * mult1;
	} else {
		*a = 0;
		*b = 0;
	}
}

void currentPlayerUpdateMoveInitSpeed(struct coord *newpos)
{
	if (g_Vars.currentplayer->moveinitspeed.x != 0) {
		if (g_Vars.currentplayer->moveinitspeed.x < 0.001f && g_Vars.currentplayer->moveinitspeed.x > -0.001f) {
			g_Vars.currentplayer->moveinitspeed.x = 0;
		} else {
			g_Vars.currentplayer->moveinitspeed.x *= 0.9f;
			newpos->x += g_Vars.currentplayer->moveinitspeed.x * g_Vars.lvupdate240freal;
		}
	}

	if (g_Vars.currentplayer->moveinitspeed.z != 0) {
		if (g_Vars.currentplayer->moveinitspeed.z < 0.001f && g_Vars.currentplayer->moveinitspeed.z > -0.001f) {
			g_Vars.currentplayer->moveinitspeed.z = 0;
		} else {
			g_Vars.currentplayer->moveinitspeed.z *= 0.9f;
			newpos->z += g_Vars.currentplayer->moveinitspeed.z * g_Vars.lvupdate240freal;
		}
	}
}

void currentPlayerUpdateFootsteps(bool arg0, bool arg1, bool arg2, bool arg3)
{
	struct chrdata *chr;
	u8 foot;
	s32 thing;
	f32 xdiff;
	f32 ydiff;
	f32 zdiff;
	f32 distance;

	func0f0c8b90(arg0, arg1, arg2, arg3);

	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
		func0f0d3d50();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB) {
		func0f0ceec4();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_CUTSCENE) {
		func0f0c37c0();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
		func0f0c785c();
	}

	if ((g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK || g_Vars.currentplayer->bondmovemode == MOVEMODE_GRAB)
			&& (g_Vars.currentplayer->speedforwards || g_Vars.currentplayer->speedsideways)
			&& (!g_Vars.normmplayerisrunning || PLAYERCOUNT() == 1)) {
		chr = g_Vars.currentplayer->prop->chr;

		if (g_Vars.currentplayer->cameramode == CAMERAMODE_0
				&& g_Vars.currentplayer->bdeltapos.y >= -6.0f) {
			xdiff = g_Vars.currentplayer->bondprevpos.x - g_Vars.currentplayer->prop->pos.x;
			ydiff = g_Vars.currentplayer->bondprevpos.y - g_Vars.currentplayer->prop->pos.y;
			zdiff = g_Vars.currentplayer->bondprevpos.z - g_Vars.currentplayer->prop->pos.z;

			foot = 0;
			distance = sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);

			g_Vars.currentplayer->footstepdist += distance;

			if (g_Vars.currentplayer->footstepdist >= 150.0f) {
				foot = 1;
				g_Vars.currentplayer->footstepdist = 0;
			}

			if (foot) {
				if (g_Vars.currentplayer->foot) {
					chr->footstep = 1;
				} else {
					chr->footstep = 2;
				}

				g_Vars.currentplayer->foot = 1 - g_Vars.currentplayer->foot;

				chr->floortype = g_Vars.currentplayer->floortype;

				thing = func0f006074(chr, distance > 10);

				if (thing != -1) {
					func00010718(0, 0, 0x7fff, 0x40, thing, 1, 1, -1, 1);
				}
			}
		}
	}
}

void func0f0cbf50(void)
{
	while (g_Vars.currentplayer->vv_verta < -180) {
		g_Vars.currentplayer->vv_verta += 360;
	}

	while (g_Vars.currentplayer->vv_verta >= 180) {
		g_Vars.currentplayer->vv_verta -= 360;
	}

	if (g_Vars.currentplayer->vv_verta > 90) {
		g_Vars.currentplayer->vv_verta = 90;
	} else if (g_Vars.currentplayer->vv_verta < -90) {
		g_Vars.currentplayer->vv_verta = -90;
	}

	g_Vars.currentplayer->vv_costheta = cosf(g_Vars.currentplayer->vv_theta * 0.017450513318181f);
	g_Vars.currentplayer->vv_sintheta = sinf(g_Vars.currentplayer->vv_theta * 0.017450513318181f);

	g_Vars.currentplayer->vv_verta360 = g_Vars.currentplayer->vv_verta;

	if (g_Vars.currentplayer->vv_verta360 < 0) {
		g_Vars.currentplayer->vv_verta360 += 360;
	}

	g_Vars.currentplayer->vv_cosverta = cosf(g_Vars.currentplayer->vv_verta360 * 0.017450513318181f);
	g_Vars.currentplayer->vv_sinverta = sinf(g_Vars.currentplayer->vv_verta360 * 0.017450513318181f);

	g_Vars.currentplayer->bond2.unk00.x = -g_Vars.currentplayer->vv_sintheta;
	g_Vars.currentplayer->bond2.unk00.y = 0;
	g_Vars.currentplayer->bond2.unk00.z = g_Vars.currentplayer->vv_costheta;

	if (g_Vars.currentplayer->prop) {
		struct chrdata *chr = g_Vars.currentplayer->prop->chr;

		if (chr && chr->animdata) {
			func0f03e538(chr, (360 - g_Vars.currentplayer->vv_theta) * 0.017450513318181f);
		}
	}
}

void func0f0cc19c(struct coord *arg)
{
	f32 min;
	f32 mult;

	g_Vars.currentplayer->bond2.unk10.x = arg->x;
	g_Vars.currentplayer->bond2.unk10.y = arg->y;
	g_Vars.currentplayer->bond2.unk10.z = arg->z;

	if (g_Vars.currentplayer->isdead && g_Vars.currentplayer->bondleandown > 0) {
		g_Vars.currentplayer->bondleandown -= 0.25f;

		if (g_Vars.currentplayer->bondleandown < 0) {
			g_Vars.currentplayer->bondleandown = 0;
		}
	}

	if (g_Vars.currentplayer->vv_verta < 0) {
		g_Vars.currentplayer->bond2.unk10.y += -(1.0f - g_Vars.currentplayer->vv_cosverta) * g_Vars.currentplayer->bondleandown;
	}

	if (cheatIsActive(CHEAT_SMALLJO)) {
		if (g_Vars.currentplayer->bondmovemode == MOVEMODE_BIKE) {
			mult = g_Vars.currentplayer->unk1a80 * 0.6f + 0.4f;
		} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK && g_Vars.currentplayer->walkinitmove) {
			mult = (1.0f - g_Vars.currentplayer->walkinitt) * 0.6f + 0.4f;
			g_Vars.currentplayer->bond2.unk10.y += (g_Vars.currentplayer->crouchoffsetreal - g_Vars.currentplayer->crouchoffsetrealsmall) * g_Vars.currentplayer->walkinitt;
		} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_WALK) {
			mult = 0.4f;
			g_Vars.currentplayer->bond2.unk10.y += (g_Vars.currentplayer->crouchoffsetreal - g_Vars.currentplayer->crouchoffsetrealsmall);
		} else {
			mult = 0.4f;
		}

		g_Vars.currentplayer->bond2.unk10.y = (g_Vars.currentplayer->bond2.unk10.y - g_Vars.currentplayer->vv_manground) * mult;
		g_Vars.currentplayer->bond2.unk10.y += g_Vars.currentplayer->vv_manground;
	}

	min = g_Vars.currentplayer->vv_ground + 10;

	if (g_Vars.currentplayer->bond2.unk10.y < min) {
		g_Vars.currentplayer->bond2.unk10.y = min;
	}
}

GLOBAL_ASM(
glabel func0f0cc3b8
.late_rodata
glabel var7f1ad934
.word 0x3c8ef461
glabel var7f1ad938
.word 0x3c8ef461
.text
/*  f0cc3b8:	27bdff08 */ 	addiu	$sp,$sp,-248
/*  f0cc3bc:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f0cc3c0:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0cc3c4:	44802000 */ 	mtc1	$zero,$f4
/*  f0cc3c8:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0cc3cc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0cc3d0:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0cc3d4:	afa60100 */ 	sw	$a2,0x100($sp)
/*  f0cc3d8:	afa70104 */ 	sw	$a3,0x104($sp)
/*  f0cc3dc:	e7a400f4 */ 	swc1	$f4,0xf4($sp)
/*  f0cc3e0:	8c4e00d8 */ 	lw	$t6,0xd8($v0)
/*  f0cc3e4:	55c00017 */ 	bnezl	$t6,.L0f0cc444
/*  f0cc3e8:	8c4f0328 */ 	lw	$t7,0x328($v0)
/*  f0cc3ec:	e7ac00f8 */ 	swc1	$f12,0xf8($sp)
/*  f0cc3f0:	0fc44fc4 */ 	jal	func0f113f10
/*  f0cc3f4:	e7ae00fc */ 	swc1	$f14,0xfc($sp)
/*  f0cc3f8:	c7ac00f8 */ 	lwc1	$f12,0xf8($sp)
/*  f0cc3fc:	44803000 */ 	mtc1	$zero,$f6
/*  f0cc400:	c7ae00fc */ 	lwc1	$f14,0xfc($sp)
/*  f0cc404:	46066032 */ 	c.eq.s	$f12,$f6
/*  f0cc408:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc40c:	45030005 */ 	bc1tl	.L0f0cc424
/*  f0cc410:	44805000 */ 	mtc1	$zero,$f10
/*  f0cc414:	460c7203 */ 	div.s	$f8,$f14,$f12
/*  f0cc418:	10000029 */ 	beqz	$zero,.L0f0cc4c0
/*  f0cc41c:	e7a800f4 */ 	swc1	$f8,0xf4($sp)
/*  f0cc420:	44805000 */ 	mtc1	$zero,$f10
.L0f0cc424:
/*  f0cc424:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc428:	460a7032 */ 	c.eq.s	$f14,$f10
/*  f0cc42c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc430:	45020024 */ 	bc1fl	.L0f0cc4c4
/*  f0cc434:	c7ac00f4 */ 	lwc1	$f12,0xf4($sp)
/*  f0cc438:	10000022 */ 	beqz	$zero,.L0f0cc4c4
/*  f0cc43c:	c7ac00f4 */ 	lwc1	$f12,0xf4($sp)
/*  f0cc440:	8c4f0328 */ 	lw	$t7,0x328($v0)
.L0f0cc444:
/*  f0cc444:	51e00018 */ 	beqzl	$t7,.L0f0cc4a8
/*  f0cc448:	3c013f00 */ 	lui	$at,0x3f00
/*  f0cc44c:	0c004b70 */ 	jal	random
/*  f0cc450:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc454:	0c004b70 */ 	jal	random
/*  f0cc458:	afa2003c */ 	sw	$v0,0x3c($sp)
/*  f0cc45c:	3c198007 */ 	lui	$t9,%hi(var8007077c)
/*  f0cc460:	8f39077c */ 	lw	$t9,%lo(var8007077c)($t9)
/*  f0cc464:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f0cc468:	3c048007 */ 	lui	$a0,%hi(var80070768)
/*  f0cc46c:	30450001 */ 	andi	$a1,$v0,0x1
/*  f0cc470:	0319001b */ 	divu	$zero,$t8,$t9
/*  f0cc474:	00004010 */ 	mfhi	$t0
/*  f0cc478:	00084840 */ 	sll	$t1,$t0,0x1
/*  f0cc47c:	00892021 */ 	addu	$a0,$a0,$t1
/*  f0cc480:	17200002 */ 	bnez	$t9,.L0f0cc48c
/*  f0cc484:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc488:	0007000d */ 	break	0x7
.L0f0cc48c:
/*  f0cc48c:	84840768 */ 	lh	$a0,%lo(var80070768)($a0)
/*  f0cc490:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f0cc494:	0fc4502f */ 	jal	func0f1140bc
/*  f0cc498:	3c073f80 */ 	lui	$a3,0x3f80
/*  f0cc49c:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0cc4a0:	ad400328 */ 	sw	$zero,0x328($t2)
/*  f0cc4a4:	3c013f00 */ 	lui	$at,0x3f00
.L0f0cc4a8:
/*  f0cc4a8:	44816000 */ 	mtc1	$at,$f12
/*  f0cc4ac:	0fc4504b */ 	jal	func0f11412c
/*  f0cc4b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc4b4:	44808000 */ 	mtc1	$zero,$f16
/*  f0cc4b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc4bc:	e7b00100 */ 	swc1	$f16,0x100($sp)
.L0f0cc4c0:
/*  f0cc4c0:	c7ac00f4 */ 	lwc1	$f12,0xf4($sp)
.L0f0cc4c4:
/*  f0cc4c4:	0fc44e29 */ 	jal	func0f1138a4
/*  f0cc4c8:	c7ae0100 */ 	lwc1	$f14,0x100($sp)
/*  f0cc4cc:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0cc4d0:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0cc4d4:	44819000 */ 	mtc1	$at,$f18
/*  f0cc4d8:	c5640158 */ 	lwc1	$f4,0x158($t3)
/*  f0cc4dc:	3c017f1b */ 	lui	$at,%hi(var7f1ad934)
/*  f0cc4e0:	c428d934 */ 	lwc1	$f8,%lo(var7f1ad934)($at)
/*  f0cc4e4:	46049181 */ 	sub.s	$f6,$f18,$f4
/*  f0cc4e8:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0cc4ec:	46083302 */ 	mul.s	$f12,$f6,$f8
/*  f0cc4f0:	0c0058ba */ 	jal	func000162e8
/*  f0cc4f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc4f8:	8e0c0288 */ 	lw	$t4,0x288($s0)
/*  f0cc4fc:	0fc54a49 */ 	jal	optionsGetHeadRoll
/*  f0cc500:	8d840070 */ 	lw	$a0,0x70($t4)
/*  f0cc504:	5040001b */ 	beqzl	$v0,.L0f0cc574
/*  f0cc508:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0cc50c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0cc510:	44800000 */ 	mtc1	$zero,$f0
/*  f0cc514:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f0cc518:	c44a03cc */ 	lwc1	$f10,0x3cc($v0)
/*  f0cc51c:	44050000 */ 	mfc1	$a1,$f0
/*  f0cc520:	44060000 */ 	mfc1	$a2,$f0
/*  f0cc524:	46005407 */ 	neg.s	$f16,$f10
/*  f0cc528:	44070000 */ 	mfc1	$a3,$f0
/*  f0cc52c:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f0cc530:	c45203d0 */ 	lwc1	$f18,0x3d0($v0)
/*  f0cc534:	46009107 */ 	neg.s	$f4,$f18
/*  f0cc538:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f0cc53c:	c44603d4 */ 	lwc1	$f6,0x3d4($v0)
/*  f0cc540:	46003207 */ 	neg.s	$f8,$f6
/*  f0cc544:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*  f0cc548:	c44a03d8 */ 	lwc1	$f10,0x3d8($v0)
/*  f0cc54c:	e7aa001c */ 	swc1	$f10,0x1c($sp)
/*  f0cc550:	c45003dc */ 	lwc1	$f16,0x3dc($v0)
/*  f0cc554:	e7b00020 */ 	swc1	$f16,0x20($sp)
/*  f0cc558:	c45203e0 */ 	lwc1	$f18,0x3e0($v0)
/*  f0cc55c:	0c005b56 */ 	jal	func00016d58
/*  f0cc560:	e7b20024 */ 	swc1	$f18,0x24($sp)
/*  f0cc564:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f0cc568:	0c00567f */ 	jal	func000159fc
/*  f0cc56c:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0cc570:	8e0d0284 */ 	lw	$t5,0x284($s0)
.L0f0cc574:
/*  f0cc574:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0cc578:	44812000 */ 	mtc1	$at,$f4
/*  f0cc57c:	c5a60144 */ 	lwc1	$f6,0x144($t5)
/*  f0cc580:	3c017f1b */ 	lui	$at,%hi(var7f1ad938)
/*  f0cc584:	c42ad938 */ 	lwc1	$f10,%lo(var7f1ad938)($at)
/*  f0cc588:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0cc58c:	27a50074 */ 	addiu	$a1,$sp,0x74
/*  f0cc590:	460a4302 */ 	mul.s	$f12,$f8,$f10
/*  f0cc594:	0c0058dd */ 	jal	func00016374
/*  f0cc598:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc59c:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f0cc5a0:	0c00567f */ 	jal	func000159fc
/*  f0cc5a4:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0cc5a8:	8fae0104 */ 	lw	$t6,0x104($sp)
/*  f0cc5ac:	27a400b4 */ 	addiu	$a0,$sp,0xb4
/*  f0cc5b0:	51c00012 */ 	beqzl	$t6,.L0f0cc5fc
/*  f0cc5b4:	c7b000d4 */ 	lwc1	$f16,0xd4($sp)
/*  f0cc5b8:	0fc25c11 */ 	jal	func0f097044
/*  f0cc5bc:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f0cc5c0:	8fa40104 */ 	lw	$a0,0x104($sp)
/*  f0cc5c4:	0fc25c11 */ 	jal	func0f097044
/*  f0cc5c8:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f0cc5cc:	27a40064 */ 	addiu	$a0,$sp,0x64
/*  f0cc5d0:	0fc25db0 */ 	jal	func0f0976c0
/*  f0cc5d4:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f0cc5d8:	27a40064 */ 	addiu	$a0,$sp,0x64
/*  f0cc5dc:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f0cc5e0:	8fa60108 */ 	lw	$a2,0x108($sp)
/*  f0cc5e4:	0fc25cae */ 	jal	func0f0972b8
/*  f0cc5e8:	27a70044 */ 	addiu	$a3,$sp,0x44
/*  f0cc5ec:	27a40044 */ 	addiu	$a0,$sp,0x44
/*  f0cc5f0:	0fc25bb5 */ 	jal	func0f096ed4
/*  f0cc5f4:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f0cc5f8:	c7b000d4 */ 	lwc1	$f16,0xd4($sp)
.L0f0cc5fc:
/*  f0cc5fc:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0cc600:	e5f00388 */ 	swc1	$f16,0x388($t7)
/*  f0cc604:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cc608:	c7b200d8 */ 	lwc1	$f18,0xd8($sp)
/*  f0cc60c:	e712038c */ 	swc1	$f18,0x38c($t8)
/*  f0cc610:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0cc614:	c7a400dc */ 	lwc1	$f4,0xdc($sp)
/*  f0cc618:	e7240390 */ 	swc1	$f4,0x390($t9)
/*  f0cc61c:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0cc620:	c7a600c4 */ 	lwc1	$f6,0xc4($sp)
/*  f0cc624:	e5060394 */ 	swc1	$f6,0x394($t0)
/*  f0cc628:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0cc62c:	c7a800c8 */ 	lwc1	$f8,0xc8($sp)
/*  f0cc630:	e5280398 */ 	swc1	$f8,0x398($t1)
/*  f0cc634:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0cc638:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0cc63c:	e54a039c */ 	swc1	$f10,0x39c($t2)
/*  f0cc640:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0cc644:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f0cc648:	27bd00f8 */ 	addiu	$sp,$sp,0xf8
/*  f0cc64c:	03e00008 */ 	jr	$ra
/*  f0cc650:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0cc654
/*  f0cc654:	44802000 */ 	mtc1	$zero,$f4
/*  f0cc658:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0cc65c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0cc660:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f0cc664:	00003825 */ 	or	$a3,$zero,$zero
/*  f0cc668:	0fc330ee */ 	jal	func0f0cc3b8
/*  f0cc66c:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0cc670:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0cc674:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0cc678:	03e00008 */ 	jr	$ra
/*  f0cc67c:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 currentPlayerGetCrouchPos(void)
{
	return (g_Vars.currentplayer->crouchpos < g_Vars.currentplayer->autocrouchpos)
		? g_Vars.currentplayer->crouchpos
		: g_Vars.currentplayer->autocrouchpos;
}

s32 playerGetCrouchPos(s32 playernum)
{
	return (g_Vars.players[playernum]->crouchpos < g_Vars.players[playernum]->autocrouchpos)
		? g_Vars.players[playernum]->crouchpos
		: g_Vars.players[playernum]->autocrouchpos;
}
