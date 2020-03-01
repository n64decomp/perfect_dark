#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "game/game_005fd0.h"
#include "game/game_01e250.h"
#include "game/game_0601b0.h"
#include "game/game_066310.h"
#include "game/game_092610.h"
#include "game/game_096750.h"
#include "game/game_096ca0.h"
#include "game/game_097ba0.h"
#include "game/game_0b0420.h"
#include "game/game_0b3350.h"
#include "game/game_0b63b0.h"
#include "game/game_0c3620.h"
#include "game/game_0c37d0.h"
#include "game/game_0c79f0.h"
#include "game/game_0d1fe0.h"
#include "game/game_0fd660.h"
#include "game/game_113220.h"
#include "game/game_11ecf0.h"
#include "game/game_127910.h"
#include "game/game_157db0.h"
#include "game/game_167ae0.h"
#include "game/game_177e00.h"
#include "game/game_187770.h"
#include "game/pdoptions.h"
#include "gvars/gvars.h"
#include "lib/lib_04790.h"
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

const u32 var7f1ad86c[] = {0xbf333333};
const u32 var7f1ad870[] = {0x3f333333};
const u32 var7f1ad874[] = {0x3d4ccccd};
const u32 var7f1ad878[] = {0x3c4ccccd};
const u32 var7f1ad87c[] = {0x3d4ccccd};
const u32 var7f1ad880[] = {0x3c4ccccd};
const u32 var7f1ad884[] = {0x3d4ccccd};
const u32 var7f1ad888[] = {0x3d4ccccd};
const u32 var7f1ad88c[] = {0xbf333333};
const u32 var7f1ad890[] = {0x3f333333};
const u32 var7f1ad894[] = {0x3d4ccccd};
const u32 var7f1ad898[] = {0x3c4ccccd};
const u32 var7f1ad89c[] = {0x3d4ccccd};
const u32 var7f1ad8a0[] = {0x3c4ccccd};
const u32 var7f1ad8a4[] = {0x3d4ccccd};
const u32 var7f1ad8a8[] = {0x3d4ccccd};
const u32 var7f1ad8ac[] = {0x3e4ccccd};
const u32 var7f1ad8b0[] = {0x40c907a9};
const u32 var7f1ad8b4[] = {0x3f5dddde};
const u32 var7f1ad8b8[] = {0x3c23d70a};
const u32 var7f1ad8bc[] = {0x3c23d70a};
const u32 var7f1ad8c0[] = {0x3d4ccccd};
const u32 var7f1ad8c4[] = {0x3f76872b};
const u32 var7f1ad8c8[] = {0x39a7c599};
const u32 var7f1ad8cc[] = {0x3f6a3d71};
const u32 var7f1ad8d0[] = {0x3f7a9fbe};
const u32 var7f1ad8d4[] = {0x39a7c599};
const u32 var7f1ad8d8[] = {0x3f76872b};
const u32 var7f1ad8dc[] = {0x3e99999a};
const u32 var7f1ad8e0[] = {0x3dcccccd};
const u32 var7f1ad8e4[] = {0x3f266666};
const u32 var7f1ad8e8[] = {0x38d1b717};
const u32 var7f1ad8ec[] = {0x3d088889};
const u32 var7f1ad8f0[] = {0x3a83126f};
const u32 var7f1ad8f4[] = {0xba83126f};
const u32 var7f1ad8f8[] = {0x3f666666};
const u32 var7f1ad8fc[] = {0x3a83126f};
const u32 var7f1ad900[] = {0xba83126f};
const u32 var7f1ad904[] = {0x3f666666};
const u32 var7f1ad908[] = {0x3c8ef461};
const u32 var7f1ad90c[] = {0x3c8ef461};
const u32 var7f1ad910[] = {0x3c8ef461};
const u32 var7f1ad914[] = {0x3c8ef461};
const u32 var7f1ad918[] = {0x3c8ef461};
const u32 var7f1ad91c[] = {0x3f19999a};
const u32 var7f1ad920[] = {0x3ecccccd};
const u32 var7f1ad924[] = {0x3f19999a};
const u32 var7f1ad928[] = {0x3ecccccd};
const u32 var7f1ad92c[] = {0x3ecccccd};
const u32 var7f1ad930[] = {0x3ecccccd};
const u32 var7f1ad934[] = {0x3c8ef461};
const u32 var7f1ad938[] = {0x3c8ef461};
const u32 var7f1ad93c[] = {0x00000000};

const char var7f1ad940[] = "bondgrab.c";
const char var7f1ad94c[] = "bondgrab.c";
const char var7f1ad958[] = "bondgrab.c";
const char var7f1ad964[] = "bondgrab.c";

const u32 var7f1ad970[] = {0x40c907a9};
const u32 var7f1ad974[] = {0x40c907a9};
const u32 var7f1ad978[] = {0x40c907a9};
const u32 var7f1ad97c[] = {0x3e4ccccd};
const u32 var7f1ad980[] = {0x40c907a9};
const u32 var7f1ad984[] = {0x40c907a9};
const u32 var7f1ad988[] = {0xc0490fdb};
const u32 var7f1ad98c[] = {0x40490fdb};
const u32 var7f1ad990[] = {0x3dcccccd};
const u32 var7f1ad994[] = {0x3dcccccd};
const u32 var7f1ad998[] = {0x3c8ef461};
const u32 var7f1ad99c[] = {0x3f7cbfb1};
const u32 var7f1ad9a0[] = {0x3c5013c0};
const u32 var7f1ad9a4[] = {0x40490fdb};
const u32 var7f1ad9a8[] = {0x40c907a9};
const u32 var7f1ad9ac[] = {0xc0490fdb};
const u32 var7f1ad9b0[] = {0x40c907a9};
const u32 var7f1ad9b4[] = {0x40c907a9};
const u32 var7f1ad9b8[] = {0x40c907a9};
const u32 var7f1ad9bc[] = {0x40c907a9};
const u32 var7f1ad9c0[] = {0x40c907a9};
const u32 var7f1ad9c4[] = {0x40c907a9};
const u32 var7f1ad9c8[] = {0x3f8147ae};
const u32 var7f1ad9cc[] = {0x3c8ef461};
const u32 var7f1ad9d0[] = {0xc6ea6000};
const u32 var7f1ad9d4[] = {0x3d3a5e30};
const u32 var7f1ad9d8[] = {0x3d3a5e30};
const u32 var7f1ad9dc[] = {0x3f745a1d};
const u32 var7f1ad9e0[] = {0x3d3a5e30};
const u32 var7f1ad9e4[] = {0x3d888889};
const u32 var7f1ad9e8[] = {0x3d888889};
const u32 var7f1ad9ec[] = {0x3d888889};
const u32 var7f1ad9f0[] = {0x3c6a0ea1};
const u32 var7f1ad9f4[] = {0x3d888889};
const u32 var7f1ad9f8[] = {0x3d888889};
const u32 var7f1ad9fc[] = {0x3d888889};
const u32 var7f1ada00[] = {0x3d888889};
const u32 var7f1ada04[] = {0x3c6a0ea1};
const u32 var7f1ada08[] = {0x3d888889};
const u32 var7f1ada0c[] = {0x3f8a3d71};
const u32 var7f1ada10[] = {0x3f7c154d};
const u32 var7f1ada14[] = {0x3c7aacc0};
const u32 var7f1ada18[] = {0x3f4ccccd};
const u32 var7f1ada1c[] = {0x4528c000};
const u32 var7f1ada20[] = {0x3ecccccd};
const u32 var7f1ada24[] = {0x3f333333};
const u32 var7f1ada28[] = {0x3f99999a};
const u32 var7f1ada2c[] = {0x3c8ef461};
const u32 var7f1ada30[] = {0xc6ea6000};
const u32 var7f1ada34[] = {0x00000000};
const u32 var7f1ada38[] = {0x00000000};
const u32 var7f1ada3c[] = {0x00000000};

const char var7f1ada40[] = "bondeyespy.c";
const char var7f1ada50[] = "bondeyespy.c";
const char var7f1ada60[] = "bondeyespy.c";
const char var7f1ada70[] = "g";
const char var7f1ada74[] = "l";
const char var7f1ada78[] = "%s%s";

GLOBAL_ASM(
glabel func0f0c79f0
/*  f0c79f0:	3c0e800a */ 	lui	$t6,0x800a
/*  f0c79f4:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0c79f8:	03e00008 */ 	jr	$ra
/*  f0c79fc:	adc40334 */ 	sw	$a0,0x334($t6)
);

GLOBAL_ASM(
glabel func0f0c7a00
/*  f0c7a00:	3c0e800a */ 	lui	$t6,0x800a
/*  f0c7a04:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0c7a08:	03e00008 */ 	jr	$ra
/*  f0c7a0c:	adc40114 */ 	sw	$a0,0x114($t6)
/*  f0c7a10:	3c0e800a */ 	lui	$t6,0x800a
/*  f0c7a14:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
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

	return optionsGetAutoAim(g_Vars.unk000288->mpchrnum);
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

	return optionsGetAutoAim(g_Vars.unk000288->mpchrnum);
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
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_HOVERBIKE) {
		return g_Vars.currentplayer->hoverbike;
	}

	return NULL;
}

struct prop *currentPlayerGetGrabbedProp(void)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRABBEDPROP) {
		return g_Vars.currentplayer->grabbedprop;
	}

	return NULL;
}

void currentPlayerGrabProp(struct prop *prop)
{
	struct defaultobj *obj = prop->obj;

	if ((obj->hidden & OBJHFLAG_04000000) == 0 && (obj->hidden & OBJHFLAG_08000000) == 0) {
		g_Vars.currentplayer->grabbedprop = prop;
		currentPlayerSetMoveModeGrabbedProp();
	}
}

void currentPlayerSetMoveMode(u32 movemode)
{
	if (g_Vars.currentplayer->bondmovemode == MOVEMODE_GRABBEDPROP) {
		func0f0ccac4();
	} else if (g_Vars.currentplayer->bondmovemode == MOVEMODE_HOVERBIKE) {
		func0f0d2184();
	}

	if (movemode == MOVEMODE_HOVERBIKE) {
		currentPlayerSetMoveModeHoverbike();
	} else if (movemode == MOVEMODE_GRABBEDPROP) {
		currentPlayerSetMoveModeGrabbedProp();
	} else if (movemode == MOVEMODE_CUTSCENE) {
		currentPlayerSetMoveModeCutscene();
	} else if (movemode == MOVEMODE_NORMAL) {
		currentPlayerSetMoveModeNormal();
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

GLOBAL_ASM(
glabel func0f0c7f2c
/*  f0c7f2c:	3c0e800a */ 	lui	$t6,0x800a
/*  f0c7f30:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0c7f34:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0c7f38:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0c7f3c:	8dc201b0 */ 	lw	$v0,0x1b0($t6)
/*  f0c7f40:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c7f44:	54410006 */ 	bnel	$v0,$at,.L0f0c7f60
/*  f0c7f48:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0c7f4c:	0fc34956 */ 	jal	func0f0d2558
/*  f0c7f50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7f54:	1000000d */ 	beqz	$zero,.L0f0c7f8c
/*  f0c7f58:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c7f5c:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0c7f60:
/*  f0c7f60:	14410005 */ 	bne	$v0,$at,.L0f0c7f78
/*  f0c7f64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7f68:	0fc33914 */ 	jal	func0f0ce450
/*  f0c7f6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7f70:	10000006 */ 	beqz	$zero,.L0f0c7f8c
/*  f0c7f74:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0c7f78:
/*  f0c7f78:	54400004 */ 	bnezl	$v0,.L0f0c7f8c
/*  f0c7f7c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c7f80:	0fc3196a */ 	jal	func0f0c65a8
/*  f0c7f84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7f88:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0c7f8c:
/*  f0c7f8c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0c7f90:	03e00008 */ 	jr	$ra
/*  f0c7f94:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0c7f98
/*  f0c7f98:	3c0e800a */ 	lui	$t6,0x800a
/*  f0c7f9c:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0c7fa0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0c7fa4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0c7fa8:	8dc201b0 */ 	lw	$v0,0x1b0($t6)
/*  f0c7fac:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c7fb0:	54410006 */ 	bnel	$v0,$at,.L0f0c7fcc
/*  f0c7fb4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0c7fb8:	0fc349ab */ 	jal	func0f0d26ac
/*  f0c7fbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7fc0:	1000000d */ 	beqz	$zero,.L0f0c7ff8
/*  f0c7fc4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c7fc8:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0c7fcc:
/*  f0c7fcc:	14410005 */ 	bne	$v0,$at,.L0f0c7fe4
/*  f0c7fd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7fd4:	0fc33982 */ 	jal	func0f0ce608
/*  f0c7fd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7fdc:	10000006 */ 	beqz	$zero,.L0f0c7ff8
/*  f0c7fe0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0c7fe4:
/*  f0c7fe4:	54400004 */ 	bnezl	$v0,.L0f0c7ff8
/*  f0c7fe8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c7fec:	0fc31972 */ 	jal	func0f0c65c8
/*  f0c7ff0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c7ff4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0c7ff8:
/*  f0c7ff8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0c7ffc:	03e00008 */ 	jr	$ra
/*  f0c8000:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0c8004
/*  f0c8004:	3c0e800a */ 	lui	$t6,0x800a
/*  f0c8008:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0c800c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0c8010:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0c8014:	8dc201b0 */ 	lw	$v0,0x1b0($t6)
/*  f0c8018:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0c801c:	1041000b */ 	beq	$v0,$at,.L0f0c804c
/*  f0c8020:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0c8024:	14410005 */ 	bne	$v0,$at,.L0f0c803c
/*  f0c8028:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c802c:	0fc33a2b */ 	jal	func0f0ce8ac
/*  f0c8030:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8034:	10000006 */ 	beqz	$zero,.L0f0c8050
/*  f0c8038:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0c803c:
/*  f0c803c:	54400004 */ 	bnezl	$v0,.L0f0c8050
/*  f0c8040:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c8044:	0fc31a52 */ 	jal	func0f0c6948
/*  f0c8048:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0c804c:
/*  f0c804c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0c8050:
/*  f0c8050:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0c8054:	03e00008 */ 	jr	$ra
/*  f0c8058:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0c805c
/*  f0c805c:	44801000 */ 	mtc1	$zero,$f2
/*  f0c8060:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0c8064:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0c8068:	460c103c */ 	c.lt.s	$f2,$f12
/*  f0c806c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8070:	4502000d */ 	bc1fl	.L0f0c80a8
/*  f0c8074:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0c8078:	0c002f9d */ 	jal	func0000be74
/*  f0c807c:	e7ac0018 */ 	swc1	$f12,0x18($sp)
/*  f0c8080:	c7ac0018 */ 	lwc1	$f12,0x18($sp)
/*  f0c8084:	3c017f1b */ 	lui	$at,%hi(var7f1ad86c)
/*  f0c8088:	c426d86c */ 	lwc1	$f6,%lo(var7f1ad86c)($at)
/*  f0c808c:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f0c8090:	3c014270 */ 	lui	$at,0x4270
/*  f0c8094:	44815000 */ 	mtc1	$at,$f10
/*  f0c8098:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0c809c:	10000012 */ 	beqz	$zero,.L0f0c80e8
/*  f0c80a0:	460a4003 */ 	div.s	$f0,$f8,$f10
/*  f0c80a4:	4602603c */ 	c.lt.s	$f12,$f2
.L0f0c80a8:
/*  f0c80a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c80ac:	4502000e */ 	bc1fl	.L0f0c80e8
/*  f0c80b0:	46001006 */ 	mov.s	$f0,$f2
/*  f0c80b4:	0c002f9d */ 	jal	func0000be74
/*  f0c80b8:	e7ac0018 */ 	swc1	$f12,0x18($sp)
/*  f0c80bc:	c7ac0018 */ 	lwc1	$f12,0x18($sp)
/*  f0c80c0:	3c017f1b */ 	lui	$at,%hi(var7f1ad870)
/*  f0c80c4:	c424d870 */ 	lwc1	$f4,%lo(var7f1ad870)($at)
/*  f0c80c8:	46006407 */ 	neg.s	$f16,$f12
/*  f0c80cc:	3c014270 */ 	lui	$at,0x4270
/*  f0c80d0:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f0c80d4:	44814000 */ 	mtc1	$at,$f8
/*  f0c80d8:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0c80dc:	10000002 */ 	beqz	$zero,.L0f0c80e8
/*  f0c80e0:	46083003 */ 	div.s	$f0,$f6,$f8
/*  f0c80e4:	46001006 */ 	mov.s	$f0,$f2
.L0f0c80e8:
/*  f0c80e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c80ec:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0c80f0:	03e00008 */ 	jr	$ra
/*  f0c80f4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0c80f8
/*  f0c80f8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0c80fc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0c8100:	0c002f9d */ 	jal	func0000be74
/*  f0c8104:	e7ac0020 */ 	swc1	$f12,0x20($sp)
/*  f0c8108:	3c014270 */ 	lui	$at,0x4270
/*  f0c810c:	44812000 */ 	mtc1	$at,$f4
/*  f0c8110:	c7ac0020 */ 	lwc1	$f12,0x20($sp)
/*  f0c8114:	46040383 */ 	div.s	$f14,$f0,$f4
/*  f0c8118:	0fc32017 */ 	jal	func0f0c805c
/*  f0c811c:	e7ae001c */ 	swc1	$f14,0x1c($sp)
/*  f0c8120:	c7a20020 */ 	lwc1	$f2,0x20($sp)
/*  f0c8124:	44806000 */ 	mtc1	$zero,$f12
/*  f0c8128:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0c812c:	c7ae001c */ 	lwc1	$f14,0x1c($sp)
/*  f0c8130:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0c8134:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0c8138:	45020021 */ 	bc1fl	.L0f0c81c0
/*  f0c813c:	460c103c */ 	c.lt.s	$f2,$f12
/*  f0c8140:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c8144:	3c017f1b */ 	lui	$at,%hi(var7f1ad874)
/*  f0c8148:	c442015c */ 	lwc1	$f2,0x15c($v0)
/*  f0c814c:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0c8150:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8154:	4500000a */ 	bc1f	.L0f0c8180
/*  f0c8158:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c815c:	3c017f1b */ 	lui	$at,%hi(var7f1ad878)
/*  f0c8160:	c426d874 */ 	lwc1	$f6,%lo(var7f1ad874)($at)
/*  f0c8164:	c468004c */ 	lwc1	$f8,0x4c($v1)
/*  f0c8168:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0c816c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8170:	460e5402 */ 	mul.s	$f16,$f10,$f14
/*  f0c8174:	46101481 */ 	sub.s	$f18,$f2,$f16
/*  f0c8178:	10000008 */ 	beqz	$zero,.L0f0c819c
/*  f0c817c:	e452015c */ 	swc1	$f18,0x15c($v0)
.L0f0c8180:
/*  f0c8180:	c424d878 */ 	lwc1	$f4,%lo(var7f1ad878)($at)
/*  f0c8184:	c466004c */ 	lwc1	$f6,0x4c($v1)
/*  f0c8188:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0c818c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8190:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*  f0c8194:	460a1401 */ 	sub.s	$f16,$f2,$f10
/*  f0c8198:	e450015c */ 	swc1	$f16,0x15c($v0)
.L0f0c819c:
/*  f0c819c:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c81a0:	c452015c */ 	lwc1	$f18,0x15c($v0)
/*  f0c81a4:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0c81a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c81ac:	4502004f */ 	bc1fl	.L0f0c82ec
/*  f0c81b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c81b4:	1000004c */ 	beqz	$zero,.L0f0c82e8
/*  f0c81b8:	e440015c */ 	swc1	$f0,0x15c($v0)
/*  f0c81bc:	460c103c */ 	c.lt.s	$f2,$f12
.L0f0c81c0:
/*  f0c81c0:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0c81c4:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0c81c8:	45020023 */ 	bc1fl	.L0f0c8258
/*  f0c81cc:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c81d0:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0c81d4:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0c81d8:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c81dc:	3c017f1b */ 	lui	$at,%hi(var7f1ad87c)
/*  f0c81e0:	c442015c */ 	lwc1	$f2,0x15c($v0)
/*  f0c81e4:	460c103c */ 	c.lt.s	$f2,$f12
/*  f0c81e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c81ec:	4500000a */ 	bc1f	.L0f0c8218
/*  f0c81f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c81f4:	3c017f1b */ 	lui	$at,%hi(var7f1ad880)
/*  f0c81f8:	c424d87c */ 	lwc1	$f4,%lo(var7f1ad87c)($at)
/*  f0c81fc:	c466004c */ 	lwc1	$f6,0x4c($v1)
/*  f0c8200:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0c8204:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8208:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*  f0c820c:	460a1400 */ 	add.s	$f16,$f2,$f10
/*  f0c8210:	10000008 */ 	beqz	$zero,.L0f0c8234
/*  f0c8214:	e450015c */ 	swc1	$f16,0x15c($v0)
.L0f0c8218:
/*  f0c8218:	c432d880 */ 	lwc1	$f18,%lo(var7f1ad880)($at)
/*  f0c821c:	c464004c */ 	lwc1	$f4,0x4c($v1)
/*  f0c8220:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0c8224:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8228:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*  f0c822c:	46081280 */ 	add.s	$f10,$f2,$f8
/*  f0c8230:	e44a015c */ 	swc1	$f10,0x15c($v0)
.L0f0c8234:
/*  f0c8234:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c8238:	c450015c */ 	lwc1	$f16,0x15c($v0)
/*  f0c823c:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0c8240:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8244:	45020029 */ 	bc1fl	.L0f0c82ec
/*  f0c8248:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c824c:	10000026 */ 	beqz	$zero,.L0f0c82e8
/*  f0c8250:	e440015c */ 	swc1	$f0,0x15c($v0)
/*  f0c8254:	8c620284 */ 	lw	$v0,0x284($v1)
.L0f0c8258:
/*  f0c8258:	3c017f1b */ 	lui	$at,%hi(var7f1ad884)
/*  f0c825c:	c442015c */ 	lwc1	$f2,0x15c($v0)
/*  f0c8260:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c8264:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8268:	45000011 */ 	bc1f	.L0f0c82b0
/*  f0c826c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8270:	3c017f1b */ 	lui	$at,%hi(var7f1ad888)
/*  f0c8274:	c432d884 */ 	lwc1	$f18,%lo(var7f1ad884)($at)
/*  f0c8278:	c464004c */ 	lwc1	$f4,0x4c($v1)
/*  f0c827c:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0c8280:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8284:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*  f0c8288:	46081281 */ 	sub.s	$f10,$f2,$f8
/*  f0c828c:	e44a015c */ 	swc1	$f10,0x15c($v0)
/*  f0c8290:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c8294:	c450015c */ 	lwc1	$f16,0x15c($v0)
/*  f0c8298:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0c829c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c82a0:	45000011 */ 	bc1f	.L0f0c82e8
/*  f0c82a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c82a8:	1000000f */ 	beqz	$zero,.L0f0c82e8
/*  f0c82ac:	e440015c */ 	swc1	$f0,0x15c($v0)
.L0f0c82b0:
/*  f0c82b0:	c432d888 */ 	lwc1	$f18,%lo(var7f1ad888)($at)
/*  f0c82b4:	c464004c */ 	lwc1	$f4,0x4c($v1)
/*  f0c82b8:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0c82bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c82c0:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*  f0c82c4:	46081280 */ 	add.s	$f10,$f2,$f8
/*  f0c82c8:	e44a015c */ 	swc1	$f10,0x15c($v0)
/*  f0c82cc:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c82d0:	c450015c */ 	lwc1	$f16,0x15c($v0)
/*  f0c82d4:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0c82d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c82dc:	45000002 */ 	bc1f	.L0f0c82e8
/*  f0c82e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c82e4:	e440015c */ 	swc1	$f0,0x15c($v0)
.L0f0c82e8:
/*  f0c82e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0c82ec:
/*  f0c82ec:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0c82f0:	03e00008 */ 	jr	$ra
/*  f0c82f4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0c82f8
/*  f0c82f8:	44801000 */ 	mtc1	$zero,$f2
/*  f0c82fc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0c8300:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0c8304:	460c103c */ 	c.lt.s	$f2,$f12
/*  f0c8308:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c830c:	4502000d */ 	bc1fl	.L0f0c8344
/*  f0c8310:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0c8314:	0c002f9d */ 	jal	func0000be74
/*  f0c8318:	e7ac0018 */ 	swc1	$f12,0x18($sp)
/*  f0c831c:	c7ac0018 */ 	lwc1	$f12,0x18($sp)
/*  f0c8320:	3c017f1b */ 	lui	$at,%hi(var7f1ad88c)
/*  f0c8324:	c426d88c */ 	lwc1	$f6,%lo(var7f1ad88c)($at)
/*  f0c8328:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f0c832c:	3c014270 */ 	lui	$at,0x4270
/*  f0c8330:	44815000 */ 	mtc1	$at,$f10
/*  f0c8334:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0c8338:	10000012 */ 	beqz	$zero,.L0f0c8384
/*  f0c833c:	460a4003 */ 	div.s	$f0,$f8,$f10
/*  f0c8340:	4602603c */ 	c.lt.s	$f12,$f2
.L0f0c8344:
/*  f0c8344:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8348:	4502000e */ 	bc1fl	.L0f0c8384
/*  f0c834c:	46001006 */ 	mov.s	$f0,$f2
/*  f0c8350:	0c002f9d */ 	jal	func0000be74
/*  f0c8354:	e7ac0018 */ 	swc1	$f12,0x18($sp)
/*  f0c8358:	c7ac0018 */ 	lwc1	$f12,0x18($sp)
/*  f0c835c:	3c017f1b */ 	lui	$at,%hi(var7f1ad890)
/*  f0c8360:	c424d890 */ 	lwc1	$f4,%lo(var7f1ad890)($at)
/*  f0c8364:	46006407 */ 	neg.s	$f16,$f12
/*  f0c8368:	3c014270 */ 	lui	$at,0x4270
/*  f0c836c:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f0c8370:	44814000 */ 	mtc1	$at,$f8
/*  f0c8374:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0c8378:	10000002 */ 	beqz	$zero,.L0f0c8384
/*  f0c837c:	46083003 */ 	div.s	$f0,$f6,$f8
/*  f0c8380:	46001006 */ 	mov.s	$f0,$f2
.L0f0c8384:
/*  f0c8384:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c8388:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0c838c:	03e00008 */ 	jr	$ra
/*  f0c8390:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0c8394
/*  f0c8394:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0c8398:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0c839c:	0c002f9d */ 	jal	func0000be74
/*  f0c83a0:	e7ac0020 */ 	swc1	$f12,0x20($sp)
/*  f0c83a4:	3c014270 */ 	lui	$at,0x4270
/*  f0c83a8:	44812000 */ 	mtc1	$at,$f4
/*  f0c83ac:	c7ac0020 */ 	lwc1	$f12,0x20($sp)
/*  f0c83b0:	46040383 */ 	div.s	$f14,$f0,$f4
/*  f0c83b4:	0fc320be */ 	jal	func0f0c82f8
/*  f0c83b8:	e7ae001c */ 	swc1	$f14,0x1c($sp)
/*  f0c83bc:	c7a20020 */ 	lwc1	$f2,0x20($sp)
/*  f0c83c0:	44806000 */ 	mtc1	$zero,$f12
/*  f0c83c4:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0c83c8:	c7ae001c */ 	lwc1	$f14,0x1c($sp)
/*  f0c83cc:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0c83d0:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0c83d4:	45020021 */ 	bc1fl	.L0f0c845c
/*  f0c83d8:	460c103c */ 	c.lt.s	$f2,$f12
/*  f0c83dc:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c83e0:	3c017f1b */ 	lui	$at,%hi(var7f1ad894)
/*  f0c83e4:	c4421b9c */ 	lwc1	$f2,0x1b9c($v0)
/*  f0c83e8:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0c83ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c83f0:	4500000a */ 	bc1f	.L0f0c841c
/*  f0c83f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c83f8:	3c017f1b */ 	lui	$at,%hi(var7f1ad898)
/*  f0c83fc:	c426d894 */ 	lwc1	$f6,%lo(var7f1ad894)($at)
/*  f0c8400:	c468004c */ 	lwc1	$f8,0x4c($v1)
/*  f0c8404:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0c8408:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c840c:	460e5402 */ 	mul.s	$f16,$f10,$f14
/*  f0c8410:	46101481 */ 	sub.s	$f18,$f2,$f16
/*  f0c8414:	10000008 */ 	beqz	$zero,.L0f0c8438
/*  f0c8418:	e4521b9c */ 	swc1	$f18,0x1b9c($v0)
.L0f0c841c:
/*  f0c841c:	c424d898 */ 	lwc1	$f4,%lo(var7f1ad898)($at)
/*  f0c8420:	c466004c */ 	lwc1	$f6,0x4c($v1)
/*  f0c8424:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0c8428:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c842c:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*  f0c8430:	460a1401 */ 	sub.s	$f16,$f2,$f10
/*  f0c8434:	e4501b9c */ 	swc1	$f16,0x1b9c($v0)
.L0f0c8438:
/*  f0c8438:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c843c:	c4521b9c */ 	lwc1	$f18,0x1b9c($v0)
/*  f0c8440:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0c8444:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8448:	45020050 */ 	bc1fl	.L0f0c858c
/*  f0c844c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c8450:	1000004d */ 	beqz	$zero,.L0f0c8588
/*  f0c8454:	e4401b9c */ 	swc1	$f0,0x1b9c($v0)
/*  f0c8458:	460c103c */ 	c.lt.s	$f2,$f12
.L0f0c845c:
/*  f0c845c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0c8460:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0c8464:	45020024 */ 	bc1fl	.L0f0c84f8
/*  f0c8468:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c846c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0c8470:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0c8474:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c8478:	44802000 */ 	mtc1	$zero,$f4
/*  f0c847c:	3c017f1b */ 	lui	$at,%hi(var7f1ad89c)
/*  f0c8480:	c4421b9c */ 	lwc1	$f2,0x1b9c($v0)
/*  f0c8484:	4604103c */ 	c.lt.s	$f2,$f4
/*  f0c8488:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c848c:	4500000a */ 	bc1f	.L0f0c84b8
/*  f0c8490:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8494:	3c017f1b */ 	lui	$at,%hi(var7f1ad8a0)
/*  f0c8498:	c426d89c */ 	lwc1	$f6,%lo(var7f1ad89c)($at)
/*  f0c849c:	c468004c */ 	lwc1	$f8,0x4c($v1)
/*  f0c84a0:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0c84a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c84a8:	460e5402 */ 	mul.s	$f16,$f10,$f14
/*  f0c84ac:	46101480 */ 	add.s	$f18,$f2,$f16
/*  f0c84b0:	10000008 */ 	beqz	$zero,.L0f0c84d4
/*  f0c84b4:	e4521b9c */ 	swc1	$f18,0x1b9c($v0)
.L0f0c84b8:
/*  f0c84b8:	c424d8a0 */ 	lwc1	$f4,%lo(var7f1ad8a0)($at)
/*  f0c84bc:	c466004c */ 	lwc1	$f6,0x4c($v1)
/*  f0c84c0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0c84c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c84c8:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*  f0c84cc:	460a1400 */ 	add.s	$f16,$f2,$f10
/*  f0c84d0:	e4501b9c */ 	swc1	$f16,0x1b9c($v0)
.L0f0c84d4:
/*  f0c84d4:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c84d8:	c4521b9c */ 	lwc1	$f18,0x1b9c($v0)
/*  f0c84dc:	4612003c */ 	c.lt.s	$f0,$f18
/*  f0c84e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c84e4:	45020029 */ 	bc1fl	.L0f0c858c
/*  f0c84e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0c84ec:	10000026 */ 	beqz	$zero,.L0f0c8588
/*  f0c84f0:	e4401b9c */ 	swc1	$f0,0x1b9c($v0)
/*  f0c84f4:	8c620284 */ 	lw	$v0,0x284($v1)
.L0f0c84f8:
/*  f0c84f8:	3c017f1b */ 	lui	$at,%hi(var7f1ad8a4)
/*  f0c84fc:	c4421b9c */ 	lwc1	$f2,0x1b9c($v0)
/*  f0c8500:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0c8504:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8508:	45000011 */ 	bc1f	.L0f0c8550
/*  f0c850c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8510:	3c017f1b */ 	lui	$at,%hi(var7f1ad8a8)
/*  f0c8514:	c424d8a4 */ 	lwc1	$f4,%lo(var7f1ad8a4)($at)
/*  f0c8518:	c466004c */ 	lwc1	$f6,0x4c($v1)
/*  f0c851c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0c8520:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8524:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*  f0c8528:	460a1401 */ 	sub.s	$f16,$f2,$f10
/*  f0c852c:	e4501b9c */ 	swc1	$f16,0x1b9c($v0)
/*  f0c8530:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c8534:	c4521b9c */ 	lwc1	$f18,0x1b9c($v0)
/*  f0c8538:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0c853c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8540:	45000011 */ 	bc1f	.L0f0c8588
/*  f0c8544:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8548:	1000000f */ 	beqz	$zero,.L0f0c8588
/*  f0c854c:	e4401b9c */ 	swc1	$f0,0x1b9c($v0)
.L0f0c8550:
/*  f0c8550:	c424d8a8 */ 	lwc1	$f4,%lo(var7f1ad8a8)($at)
/*  f0c8554:	c466004c */ 	lwc1	$f6,0x4c($v1)
/*  f0c8558:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0c855c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8560:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*  f0c8564:	460a1400 */ 	add.s	$f16,$f2,$f10
/*  f0c8568:	e4501b9c */ 	swc1	$f16,0x1b9c($v0)
/*  f0c856c:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0c8570:	c4521b9c */ 	lwc1	$f18,0x1b9c($v0)
/*  f0c8574:	4612003c */ 	c.lt.s	$f0,$f18
/*  f0c8578:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c857c:	45000002 */ 	bc1f	.L0f0c8588
/*  f0c8580:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c8584:	e4401b9c */ 	swc1	$f0,0x1b9c($v0)
.L0f0c8588:
/*  f0c8588:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0c858c:
/*  f0c858c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0c8590:	03e00008 */ 	jr	$ra
/*  f0c8594:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0c8598
/*  f0c8598:	27bdfe98 */ 	addiu	$sp,$sp,-360
/*  f0c859c:	3c01c080 */ 	lui	$at,0xc080
/*  f0c85a0:	44811000 */ 	mtc1	$at,$f2
/*  f0c85a4:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0c85a8:	3c0143c8 */ 	lui	$at,0x43c8
/*  f0c85ac:	44812000 */ 	mtc1	$at,$f4
/*  f0c85b0:	3c10800a */ 	lui	$s0,%hi(var800a0004)
/*  f0c85b4:	8e10a244 */ 	lw	$s0,-0x5dbc($s0)
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
/*  f0c8618:	3c10800a */ 	lui	$s0,%hi(var800a0004)
/*  f0c861c:	8e10a244 */ 	lw	$s0,-0x5dbc($s0)
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
/*  f0c86f4:	3c067f1b */ 	lui	$a2,0x7f1b
/*  f0c86f8:	24c6d860 */ 	addiu	$a2,$a2,-10144
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
/*  f0c8898:	3c0e800a */ 	lui	$t6,0x800a
/*  f0c889c:	4600303c */ 	c.lt.s	$f6,$f0
/*  f0c88a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0c88a4:	45020027 */ 	bc1fl	.L0f0c8944
/*  f0c88a8:	2a410005 */ 	slti	$at,$s2,0x5
/*  f0c88ac:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
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
/*  f0c8950:	26100004 */ 	addiu	$s0,$s0,%lo(var800a0004)
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
/*  f0c8a28:	26100004 */ 	addiu	$s0,$s0,%lo(var800a0004)
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
/*  f0c8b18:	3c0e800a */ 	lui	$t6,0x800a
/*  f0c8b1c:	e4800030 */ 	swc1	$f0,0x30($a0)
/*  f0c8b20:	e4800034 */ 	swc1	$f0,0x34($a0)
/*  f0c8b24:	e4800038 */ 	swc1	$f0,0x38($a0)
/*  f0c8b28:	e480003c */ 	swc1	$f0,0x3c($a0)
/*  f0c8b2c:	e4800040 */ 	swc1	$f0,0x40($a0)
/*  f0c8b30:	e4800044 */ 	swc1	$f0,0x44($a0)
/*  f0c8b34:	e480005c */ 	swc1	$f0,0x5c($a0)
/*  f0c8b38:	e4800060 */ 	swc1	$f0,0x60($a0)
/*  f0c8b3c:	8dcea248 */ 	lw	$t6,-0x5db8($t6)
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
/*  f0c8df4:	0fc2ebc3 */ 	jal	func0f0baf0c
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
/*  f0c8eac:	3c08800b */ 	lui	$t0,0x800b
/*  f0c8eb0:	9108cba6 */ 	lbu	$t0,-0x345a($t0)
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
/*  f0c99a4:	0fc331a0 */ 	jal	func0f0cc680
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
/*  f0ca670:	0fc331a0 */ 	jal	func0f0cc680
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
/*  f0caa40:	0fc2c5a9 */ 	jal	func0f0b16a4
/*  f0caa44:	e7ac0214 */ 	swc1	$f12,0x214($sp)
/*  f0caa48:	8e590284 */ 	lw	$t9,0x284($s2)
.L0f0caa4c:
/*  f0caa4c:	8f281a24 */ 	lw	$t0,0x1a24($t9)
/*  f0caa50:	150000b5 */ 	bnez	$t0,.L0f0cad28
/*  f0caa54:	3c098006 */ 	lui	$t1,0x8006
/*  f0caa58:	8d29d9d0 */ 	lw	$t1,-0x2630($t1)
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
/*  f0cab18:	0fc2d5be */ 	jal	func0f0b56f8
/*  f0cab1c:	e7a200ac */ 	swc1	$f2,0xac($sp)
/*  f0cab20:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f0cab24:	27b000a0 */ 	addiu	$s0,$sp,0xa0
/*  f0cab28:	02003025 */ 	or	$a2,$s0,$zero
/*  f0cab2c:	8dc5025c */ 	lw	$a1,0x25c($t6)
/*  f0cab30:	00402025 */ 	or	$a0,$v0,$zero
/*  f0cab34:	0c0056da */ 	jal	0x15b68
/*  f0cab38:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0cab3c:	c7a200ac */ 	lwc1	$f2,0xac($sp)
/*  f0cab40:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f0cab44:	02002025 */ 	or	$a0,$s0,$zero
/*  f0cab48:	44061000 */ 	mfc1	$a2,$f2
/*  f0cab4c:	27a50098 */ 	addiu	$a1,$sp,0x98
/*  f0cab50:	0fc2d3ae */ 	jal	func0f0b4eb8
/*  f0cab54:	8de7171c */ 	lw	$a3,0x171c($t7)
/*  f0cab58:	0fc2d5fe */ 	jal	func0f0b57f8
/*  f0cab5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cab60:	0fc2d5f6 */ 	jal	func0f0b57d8
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
/*  f0cabac:	0fc2d5fe */ 	jal	func0f0b57f8
/*  f0cabb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cabb4:	0fc2d5f6 */ 	jal	func0f0b57d8
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
/*  f0cac00:	0fc2d602 */ 	jal	func0f0b5808
/*  f0cac04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cac08:	0fc2d5fa */ 	jal	func0f0b57e8
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
/*  f0cac54:	0fc2d602 */ 	jal	func0f0b5808
/*  f0cac58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cac5c:	0fc2d5fa */ 	jal	func0f0b57e8
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
/*  f0cad20:	0fc2eab0 */ 	jal	func0f0baac0
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
/*  f0cb0b4:	0fc3203e */ 	jal	func0f0c80f8
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
/*  f0cb0e0:	0fc3203e */ 	jal	func0f0c80f8
/*  f0cb0e4:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f0cb0e8:	10000005 */ 	beqz	$zero,.L0f0cb100
/*  f0cb0ec:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f0cb0f0:	44806000 */ 	mtc1	$zero,$f12
.L0f0cb0f4:
/*  f0cb0f4:	0fc3203e */ 	jal	func0f0c80f8
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
/*  f0cb268:	0fc3203e */ 	jal	func0f0c80f8
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
/*  f0cb2b8:	0fc3203e */ 	jal	func0f0c80f8
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
/*  f0cb2f4:	0fc3203e */ 	jal	func0f0c80f8
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
/*  f0cb3fc:	0fc320e5 */ 	jal	func0f0c8394
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
/*  f0cb428:	0fc320e5 */ 	jal	func0f0c8394
/*  f0cb42c:	e7a001f8 */ 	swc1	$f0,0x1f8($sp)
/*  f0cb430:	10000005 */ 	beqz	$zero,.L0f0cb448
/*  f0cb434:	8e450284 */ 	lw	$a1,0x284($s2)
/*  f0cb438:	44806000 */ 	mtc1	$zero,$f12
.L0f0cb43c:
/*  f0cb43c:	0fc320e5 */ 	jal	func0f0c8394
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
/*  f0cb530:	0fc2a4f4 */ 	jal	func0f0a93d0
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
/*  f0cb63c:	3c05800a */ 	lui	$a1,0x800a
/*  f0cb640:	8ca5a244 */ 	lw	$a1,-0x5dbc($a1)
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
/*  f0cb6d0:	3c05800a */ 	lui	$a1,0x800a
/*  f0cb6d4:	8ca5a244 */ 	lw	$a1,-0x5dbc($a1)
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
/*  f0cb728:	0fc2a4f4 */ 	jal	func0f0a93d0
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

GLOBAL_ASM(
glabel func0f0cb79c
/*  f0cb79c:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0cb7a0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0cb7a4:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0cb7a8:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f0cb7ac:	afa60058 */ 	sw	$a2,0x58($sp)
/*  f0cb7b0:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0cb7b4:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f0cb7b8:	8c8400bc */ 	lw	$a0,0xbc($a0)
/*  f0cb7bc:	00027880 */ 	sll	$t7,$v0,0x2
/*  f0cb7c0:	3c18800a */ 	lui	$t8,0x800a
/*  f0cb7c4:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0cb7c8:	8f18a024 */ 	lw	$t8,-0x5fdc($t8)
/*  f0cb7cc:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f0cb7d0:	c70c19c4 */ 	lwc1	$f12,0x19c4($t8)
/*  f0cb7d4:	8f2400bc */ 	lw	$a0,0xbc($t9)
/*  f0cb7d8:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f0cb7dc:	e7ac0034 */ 	swc1	$f12,0x34($sp)
/*  f0cb7e0:	3c014248 */ 	lui	$at,0x4248
/*  f0cb7e4:	44810000 */ 	mtc1	$at,$f0
/*  f0cb7e8:	c6040000 */ 	lwc1	$f4,0x0($s0)
/*  f0cb7ec:	00024080 */ 	sll	$t0,$v0,0x2
/*  f0cb7f0:	3c09800a */ 	lui	$t1,0x800a
/*  f0cb7f4:	01284821 */ 	addu	$t1,$t1,$t0
/*  f0cb7f8:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0cb7fc:	8d29a024 */ 	lw	$t1,-0x5fdc($t1)
/*  f0cb800:	8fa30050 */ 	lw	$v1,0x50($sp)
/*  f0cb804:	c7ac0034 */ 	lwc1	$f12,0x34($sp)
/*  f0cb808:	c52219c0 */ 	lwc1	$f2,0x19c0($t1)
/*  f0cb80c:	e7a60044 */ 	swc1	$f6,0x44($sp)
/*  f0cb810:	c6080004 */ 	lwc1	$f8,0x4($s0)
/*  f0cb814:	c46a008c */ 	lwc1	$f10,0x8c($v1)
/*  f0cb818:	3c014120 */ 	lui	$at,0x4120
/*  f0cb81c:	44817000 */ 	mtc1	$at,$f14
/*  f0cb820:	460a4401 */ 	sub.s	$f16,$f8,$f10
/*  f0cb824:	27a40044 */ 	addiu	$a0,$sp,0x44
/*  f0cb828:	27a50038 */ 	addiu	$a1,$sp,0x38
/*  f0cb82c:	8fa60058 */ 	lw	$a2,0x58($sp)
/*  f0cb830:	460c8481 */ 	sub.s	$f18,$f16,$f12
/*  f0cb834:	24070007 */ 	addiu	$a3,$zero,0x7
/*  f0cb838:	460e9101 */ 	sub.s	$f4,$f18,$f14
/*  f0cb83c:	e7a40048 */ 	swc1	$f4,0x48($sp)
/*  f0cb840:	c6060008 */ 	lwc1	$f6,0x8($s0)
/*  f0cb844:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0cb848:	e7a8004c */ 	swc1	$f8,0x4c($sp)
/*  f0cb84c:	c60a0000 */ 	lwc1	$f10,0x0($s0)
/*  f0cb850:	46005400 */ 	add.s	$f16,$f10,$f0
/*  f0cb854:	e7b00038 */ 	swc1	$f16,0x38($sp)
/*  f0cb858:	c6120004 */ 	lwc1	$f18,0x4($s0)
/*  f0cb85c:	c464008c */ 	lwc1	$f4,0x8c($v1)
/*  f0cb860:	46049181 */ 	sub.s	$f6,$f18,$f4
/*  f0cb864:	460c3201 */ 	sub.s	$f8,$f6,$f12
/*  f0cb868:	46024280 */ 	add.s	$f10,$f8,$f2
/*  f0cb86c:	460e5400 */ 	add.s	$f16,$f10,$f14
/*  f0cb870:	e7b0003c */ 	swc1	$f16,0x3c($sp)
/*  f0cb874:	c6120008 */ 	lwc1	$f18,0x8($s0)
/*  f0cb878:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0cb87c:	46009100 */ 	add.s	$f4,$f18,$f0
/*  f0cb880:	0fc59434 */ 	jal	func0f1650d0
/*  f0cb884:	e7a40040 */ 	swc1	$f4,0x40($sp)
/*  f0cb888:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0cb88c:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0cb890:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f0cb894:	03e00008 */ 	jr	$ra
/*  f0cb898:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0cb89c
/*  f0cb89c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0cb8a0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0cb8a4:	00a03025 */ 	or	$a2,$a1,$zero
/*  f0cb8a8:	8c8500bc */ 	lw	$a1,0xbc($a0)
/*  f0cb8ac:	0fc32de7 */ 	jal	func0f0cb79c
/*  f0cb8b0:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f0cb8b4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cb8b8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0cb8bc:	03e00008 */ 	jr	$ra
/*  f0cb8c0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0cb8c4
/*  f0cb8c4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0cb8c8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0cb8cc:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0cb8d0:	0fc19711 */ 	jal	func0f065c44
/*  f0cb8d4:	8c8400bc */ 	lw	$a0,0xbc($a0)
/*  f0cb8d8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f0cb8dc:	8c8500bc */ 	lw	$a1,0xbc($a0)
/*  f0cb8e0:	0fc32e27 */ 	jal	func0f0cb89c
/*  f0cb8e4:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f0cb8e8:	8faf0018 */ 	lw	$t7,0x18($sp)
/*  f0cb8ec:	0fc1972c */ 	jal	func0f065cb0
/*  f0cb8f0:	8de400bc */ 	lw	$a0,0xbc($t7)
/*  f0cb8f4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cb8f8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0cb8fc:	03e00008 */ 	jr	$ra
/*  f0cb900:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0cb904
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

GLOBAL_ASM(
glabel func0f0cba88
/*  f0cba88:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0cba8c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0cba90:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0cba94:	44800000 */ 	mtc1	$zero,$f0
/*  f0cba98:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*  f0cba9c:	44876000 */ 	mtc1	$a3,$f12
/*  f0cbaa0:	00803825 */ 	or	$a3,$a0,$zero
/*  f0cbaa4:	46040032 */ 	c.eq.s	$f0,$f4
/*  f0cbaa8:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0cbaac:	45020007 */ 	bc1fl	.L0f0cbacc
/*  f0cbab0:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f0cbab4:	c4c60008 */ 	lwc1	$f6,0x8($a2)
/*  f0cbab8:	46060032 */ 	c.eq.s	$f0,$f6
/*  f0cbabc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbac0:	4503001c */ 	bc1tl	.L0f0cbb34
/*  f0cbac4:	e4e00000 */ 	swc1	$f0,0x0($a3)
/*  f0cbac8:	afa5001c */ 	sw	$a1,0x1c($sp)
.L0f0cbacc:
/*  f0cbacc:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f0cbad0:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f0cbad4:	0fc32e41 */ 	jal	func0f0cb904
/*  f0cbad8:	e7ac0024 */ 	swc1	$f12,0x24($sp)
/*  f0cbadc:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f0cbae0:	c7a00028 */ 	lwc1	$f0,0x28($sp)
/*  f0cbae4:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*  f0cbae8:	c4c80008 */ 	lwc1	$f8,0x8($a2)
/*  f0cbaec:	c4d00000 */ 	lwc1	$f16,0x0($a2)
/*  f0cbaf0:	8fa70018 */ 	lw	$a3,0x18($sp)
/*  f0cbaf4:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0cbaf8:	46008487 */ 	neg.s	$f18,$f16
/*  f0cbafc:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f0cbb00:	460c9102 */ 	mul.s	$f4,$f18,$f12
/*  f0cbb04:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0cbb08:	e4e60000 */ 	swc1	$f6,0x0($a3)
/*  f0cbb0c:	c4c80000 */ 	lwc1	$f8,0x0($a2)
/*  f0cbb10:	c4ca0008 */ 	lwc1	$f10,0x8($a2)
/*  f0cbb14:	46004407 */ 	neg.s	$f16,$f8
/*  f0cbb18:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0cbb1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbb20:	460c5102 */ 	mul.s	$f4,$f10,$f12
/*  f0cbb24:	46049181 */ 	sub.s	$f6,$f18,$f4
/*  f0cbb28:	10000003 */ 	beqz	$zero,.L0f0cbb38
/*  f0cbb2c:	e4a60000 */ 	swc1	$f6,0x0($a1)
/*  f0cbb30:	e4e00000 */ 	swc1	$f0,0x0($a3)
.L0f0cbb34:
/*  f0cbb34:	e4a00000 */ 	swc1	$f0,0x0($a1)
.L0f0cbb38:
/*  f0cbb38:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cbb3c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0cbb40:	03e00008 */ 	jr	$ra
/*  f0cbb44:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0cbb48
/*  f0cbb48:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0cbb4c:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0cbb50:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0cbb54:	44801000 */ 	mtc1	$zero,$f2
/*  f0cbb58:	3c017f1b */ 	lui	$at,%hi(var7f1ad8f0)
/*  f0cbb5c:	c44001a4 */ 	lwc1	$f0,0x1a4($v0)
/*  f0cbb60:	46001032 */ 	c.eq.s	$f2,$f0
/*  f0cbb64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbb68:	4503001c */ 	bc1tl	.L0f0cbbdc
/*  f0cbb6c:	c44001ac */ 	lwc1	$f0,0x1ac($v0)
/*  f0cbb70:	c424d8f0 */ 	lwc1	$f4,%lo(var7f1ad8f0)($at)
/*  f0cbb74:	3c017f1b */ 	lui	$at,%hi(var7f1ad8f4)
/*  f0cbb78:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0cbb7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbb80:	45000009 */ 	bc1f	.L0f0cbba8
/*  f0cbb84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbb88:	c426d8f4 */ 	lwc1	$f6,%lo(var7f1ad8f4)($at)
/*  f0cbb8c:	4600303c */ 	c.lt.s	$f6,$f0
/*  f0cbb90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbb94:	45000004 */ 	bc1f	.L0f0cbba8
/*  f0cbb98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbb9c:	e44201a4 */ 	swc1	$f2,0x1a4($v0)
/*  f0cbba0:	1000000d */ 	beqz	$zero,.L0f0cbbd8
/*  f0cbba4:	8c620284 */ 	lw	$v0,0x284($v1)
.L0f0cbba8:
/*  f0cbba8:	3c017f1b */ 	lui	$at,%hi(var7f1ad8f8)
/*  f0cbbac:	c428d8f8 */ 	lwc1	$f8,%lo(var7f1ad8f8)($at)
/*  f0cbbb0:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f0cbbb4:	e44a01a4 */ 	swc1	$f10,0x1a4($v0)
/*  f0cbbb8:	8c6e0284 */ 	lw	$t6,0x284($v1)
/*  f0cbbbc:	c472004c */ 	lwc1	$f18,0x4c($v1)
/*  f0cbbc0:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f0cbbc4:	c5d001a4 */ 	lwc1	$f16,0x1a4($t6)
/*  f0cbbc8:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0cbbcc:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f0cbbd0:	e4880000 */ 	swc1	$f8,0x0($a0)
/*  f0cbbd4:	8c620284 */ 	lw	$v0,0x284($v1)
.L0f0cbbd8:
/*  f0cbbd8:	c44001ac */ 	lwc1	$f0,0x1ac($v0)
.L0f0cbbdc:
/*  f0cbbdc:	3c017f1b */ 	lui	$at,%hi(var7f1ad8fc)
/*  f0cbbe0:	46001032 */ 	c.eq.s	$f2,$f0
/*  f0cbbe4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbbe8:	45010019 */ 	bc1t	.L0f0cbc50
/*  f0cbbec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbbf0:	c42ad8fc */ 	lwc1	$f10,%lo(var7f1ad8fc)($at)
/*  f0cbbf4:	3c017f1b */ 	lui	$at,%hi(var7f1ad900)
/*  f0cbbf8:	460a003c */ 	c.lt.s	$f0,$f10
/*  f0cbbfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbc00:	45000008 */ 	bc1f	.L0f0cbc24
/*  f0cbc04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbc08:	c430d900 */ 	lwc1	$f16,%lo(var7f1ad900)($at)
/*  f0cbc0c:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0cbc10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbc14:	45000003 */ 	bc1f	.L0f0cbc24
/*  f0cbc18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbc1c:	03e00008 */ 	jr	$ra
/*  f0cbc20:	e44201ac */ 	swc1	$f2,0x1ac($v0)
.L0f0cbc24:
/*  f0cbc24:	3c017f1b */ 	lui	$at,%hi(var7f1ad904)
/*  f0cbc28:	c432d904 */ 	lwc1	$f18,%lo(var7f1ad904)($at)
/*  f0cbc2c:	46120182 */ 	mul.s	$f6,$f0,$f18
/*  f0cbc30:	e44601ac */ 	swc1	$f6,0x1ac($v0)
/*  f0cbc34:	8c6f0284 */ 	lw	$t7,0x284($v1)
/*  f0cbc38:	c468004c */ 	lwc1	$f8,0x4c($v1)
/*  f0cbc3c:	c4900008 */ 	lwc1	$f16,0x8($a0)
/*  f0cbc40:	c5e401ac */ 	lwc1	$f4,0x1ac($t7)
/*  f0cbc44:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f0cbc48:	460a8480 */ 	add.s	$f18,$f16,$f10
/*  f0cbc4c:	e4920008 */ 	swc1	$f18,0x8($a0)
.L0f0cbc50:
/*  f0cbc50:	03e00008 */ 	jr	$ra
/*  f0cbc54:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0cbc58
/*  f0cbc58:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0cbc5c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0cbc60:	0fc322e4 */ 	jal	func0f0c8b90
/*  f0cbc64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbc68:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0cbc6c:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0cbc70:	8ce30284 */ 	lw	$v1,0x284($a3)
/*  f0cbc74:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0cbc78:	8c6201b0 */ 	lw	$v0,0x1b0($v1)
/*  f0cbc7c:	54410009 */ 	bnel	$v0,$at,.L0f0cbca4
/*  f0cbc80:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0cbc84:	0fc34f54 */ 	jal	func0f0d3d50
/*  f0cbc88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbc8c:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0cbc90:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0cbc94:	8ce30284 */ 	lw	$v1,0x284($a3)
/*  f0cbc98:	1000001d */ 	beqz	$zero,.L0f0cbd10
/*  f0cbc9c:	8c6201b0 */ 	lw	$v0,0x1b0($v1)
/*  f0cbca0:	24010004 */ 	addiu	$at,$zero,0x4
.L0f0cbca4:
/*  f0cbca4:	54410009 */ 	bnel	$v0,$at,.L0f0cbccc
/*  f0cbca8:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0cbcac:	0fc33bb1 */ 	jal	func0f0ceec4
/*  f0cbcb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbcb4:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0cbcb8:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0cbcbc:	8ce30284 */ 	lw	$v1,0x284($a3)
/*  f0cbcc0:	10000013 */ 	beqz	$zero,.L0f0cbd10
/*  f0cbcc4:	8c6201b0 */ 	lw	$v0,0x1b0($v1)
/*  f0cbcc8:	24010005 */ 	addiu	$at,$zero,0x5
.L0f0cbccc:
/*  f0cbccc:	14410008 */ 	bne	$v0,$at,.L0f0cbcf0
/*  f0cbcd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbcd4:	0fc30df0 */ 	jal	func0f0c37c0
/*  f0cbcd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbcdc:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0cbce0:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0cbce4:	8ce30284 */ 	lw	$v1,0x284($a3)
/*  f0cbce8:	10000009 */ 	beqz	$zero,.L0f0cbd10
/*  f0cbcec:	8c6201b0 */ 	lw	$v0,0x1b0($v1)
.L0f0cbcf0:
/*  f0cbcf0:	14400007 */ 	bnez	$v0,.L0f0cbd10
/*  f0cbcf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbcf8:	0fc31e17 */ 	jal	func0f0c785c
/*  f0cbcfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbd00:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0cbd04:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0cbd08:	8ce30284 */ 	lw	$v1,0x284($a3)
/*  f0cbd0c:	8c6201b0 */ 	lw	$v0,0x1b0($v1)
.L0f0cbd10:
/*  f0cbd10:	10400003 */ 	beqz	$v0,.L0f0cbd20
/*  f0cbd14:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0cbd18:	5441008a */ 	bnel	$v0,$at,.L0f0cbf44
/*  f0cbd1c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0cbd20:
/*  f0cbd20:	44808000 */ 	mtc1	$zero,$f16
/*  f0cbd24:	c4640170 */ 	lwc1	$f4,0x170($v1)
/*  f0cbd28:	46048032 */ 	c.eq.s	$f16,$f4
/*  f0cbd2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbd30:	45020007 */ 	bc1fl	.L0f0cbd50
/*  f0cbd34:	8cee0318 */ 	lw	$t6,0x318($a3)
/*  f0cbd38:	c4660168 */ 	lwc1	$f6,0x168($v1)
/*  f0cbd3c:	46068032 */ 	c.eq.s	$f16,$f6
/*  f0cbd40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbd44:	4503007f */ 	bc1tl	.L0f0cbf44
/*  f0cbd48:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0cbd4c:	8cee0318 */ 	lw	$t6,0x318($a3)
.L0f0cbd50:
/*  f0cbd50:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cbd54:	51c0001e */ 	beqzl	$t6,.L0f0cbdd0
/*  f0cbd58:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0cbd5c:	8cef006c */ 	lw	$t7,0x6c($a3)
/*  f0cbd60:	00003025 */ 	or	$a2,$zero,$zero
/*  f0cbd64:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cbd68:	11e00003 */ 	beqz	$t7,.L0f0cbd78
/*  f0cbd6c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cbd70:	10000001 */ 	beqz	$zero,.L0f0cbd78
/*  f0cbd74:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0cbd78:
/*  f0cbd78:	8cf80068 */ 	lw	$t8,0x68($a3)
/*  f0cbd7c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0cbd80:	13000003 */ 	beqz	$t8,.L0f0cbd90
/*  f0cbd84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbd88:	10000001 */ 	beqz	$zero,.L0f0cbd90
/*  f0cbd8c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0cbd90:
/*  f0cbd90:	8cf90064 */ 	lw	$t9,0x64($a3)
/*  f0cbd94:	13200003 */ 	beqz	$t9,.L0f0cbda4
/*  f0cbd98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbd9c:	10000001 */ 	beqz	$zero,.L0f0cbda4
/*  f0cbda0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0cbda4:
/*  f0cbda4:	8ce80070 */ 	lw	$t0,0x70($a3)
/*  f0cbda8:	11000003 */ 	beqz	$t0,.L0f0cbdb8
/*  f0cbdac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbdb0:	10000001 */ 	beqz	$zero,.L0f0cbdb8
/*  f0cbdb4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0cbdb8:
/*  f0cbdb8:	00454821 */ 	addu	$t1,$v0,$a1
/*  f0cbdbc:	01245021 */ 	addu	$t2,$t1,$a0
/*  f0cbdc0:	01465821 */ 	addu	$t3,$t2,$a2
/*  f0cbdc4:	5561005f */ 	bnel	$t3,$at,.L0f0cbf44
/*  f0cbdc8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0cbdcc:	8c6c0000 */ 	lw	$t4,0x0($v1)
.L0f0cbdd0:
/*  f0cbdd0:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0cbdd4:	3c01c0c0 */ 	lui	$at,0xc0c0
/*  f0cbdd8:	15800059 */ 	bnez	$t4,.L0f0cbf40
/*  f0cbddc:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f0cbde0:	c4680080 */ 	lwc1	$f8,0x80($v1)
/*  f0cbde4:	44815000 */ 	mtc1	$at,$f10
/*  f0cbde8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbdec:	4608503e */ 	c.le.s	$f10,$f8
/*  f0cbdf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbdf4:	45020053 */ 	bc1fl	.L0f0cbf44
/*  f0cbdf8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0cbdfc:	c4720310 */ 	lwc1	$f18,0x310($v1)
/*  f0cbe00:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f0cbe04:	c4660314 */ 	lwc1	$f6,0x314($v1)
/*  f0cbe08:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f0cbe0c:	46049001 */ 	sub.s	$f0,$f18,$f4
/*  f0cbe10:	c4520010 */ 	lwc1	$f18,0x10($v0)
/*  f0cbe14:	c46a0318 */ 	lwc1	$f10,0x318($v1)
/*  f0cbe18:	46083081 */ 	sub.s	$f2,$f6,$f8
/*  f0cbe1c:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f0cbe20:	afa60034 */ 	sw	$a2,0x34($sp)
/*  f0cbe24:	46125381 */ 	sub.s	$f14,$f10,$f18
/*  f0cbe28:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f0cbe2c:	a3a00033 */ 	sb	$zero,0x33($sp)
/*  f0cbe30:	460e7282 */ 	mul.s	$f10,$f14,$f14
/*  f0cbe34:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0cbe38:	0c012974 */ 	jal	sqrtf
/*  f0cbe3c:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f0cbe40:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0cbe44:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0cbe48:	8ce30284 */ 	lw	$v1,0x284($a3)
/*  f0cbe4c:	93a40033 */ 	lbu	$a0,0x33($sp)
/*  f0cbe50:	8fa60034 */ 	lw	$a2,0x34($sp)
/*  f0cbe54:	c4721c18 */ 	lwc1	$f18,0x1c18($v1)
/*  f0cbe58:	3c014316 */ 	lui	$at,0x4316
/*  f0cbe5c:	44814000 */ 	mtc1	$at,$f8
/*  f0cbe60:	46009100 */ 	add.s	$f4,$f18,$f0
/*  f0cbe64:	44808000 */ 	mtc1	$zero,$f16
/*  f0cbe68:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0cbe6c:	46000086 */ 	mov.s	$f2,$f0
/*  f0cbe70:	e4641c18 */ 	swc1	$f4,0x1c18($v1)
/*  f0cbe74:	8ce30284 */ 	lw	$v1,0x284($a3)
/*  f0cbe78:	c4661c18 */ 	lwc1	$f6,0x1c18($v1)
/*  f0cbe7c:	4606403e */ 	c.le.s	$f8,$f6
/*  f0cbe80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbe84:	45000003 */ 	bc1f	.L0f0cbe94
/*  f0cbe88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbe8c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0cbe90:	e4701c18 */ 	swc1	$f16,0x1c18($v1)
.L0f0cbe94:
/*  f0cbe94:	5080002b */ 	beqzl	$a0,.L0f0cbf44
/*  f0cbe98:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0cbe9c:	8ced0284 */ 	lw	$t5,0x284($a3)
/*  f0cbea0:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0cbea4:	8dae1c14 */ 	lw	$t6,0x1c14($t5)
/*  f0cbea8:	51c00004 */ 	beqzl	$t6,.L0f0cbebc
/*  f0cbeac:	a0cf0190 */ 	sb	$t7,0x190($a2)
/*  f0cbeb0:	10000002 */ 	beqz	$zero,.L0f0cbebc
/*  f0cbeb4:	a0c20190 */ 	sb	$v0,0x190($a2)
/*  f0cbeb8:	a0cf0190 */ 	sb	$t7,0x190($a2)
.L0f0cbebc:
/*  f0cbebc:	8ce30284 */ 	lw	$v1,0x284($a3)
/*  f0cbec0:	3c014120 */ 	lui	$at,0x4120
/*  f0cbec4:	44815000 */ 	mtc1	$at,$f10
/*  f0cbec8:	8c781c14 */ 	lw	$t8,0x1c14($v1)
/*  f0cbecc:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0cbed0:	4602503c */ 	c.lt.s	$f10,$f2
/*  f0cbed4:	0058c823 */ 	subu	$t9,$v0,$t8
/*  f0cbed8:	ac791c14 */ 	sw	$t9,0x1c14($v1)
/*  f0cbedc:	8ce80284 */ 	lw	$t0,0x284($a3)
/*  f0cbee0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cbee4:	9109161e */ 	lbu	$t1,0x161e($t0)
/*  f0cbee8:	45000002 */ 	bc1f	.L0f0cbef4
/*  f0cbeec:	a0c90191 */ 	sb	$t1,0x191($a2)
/*  f0cbef0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0cbef4:
/*  f0cbef4:	0fc0181d */ 	jal	func0f006074
/*  f0cbef8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbefc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0cbf00:	1041000f */ 	beq	$v0,$at,.L0f0cbf40
/*  f0cbf04:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cbf08:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cbf0c:	44819000 */ 	mtc1	$at,$f18
/*  f0cbf10:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0cbf14:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0cbf18:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0cbf1c:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0cbf20:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0cbf24:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0cbf28:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cbf2c:	24067fff */ 	addiu	$a2,$zero,0x7fff
/*  f0cbf30:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f0cbf34:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0cbf38:	0c0041c6 */ 	jal	func00010718
/*  f0cbf3c:	e7b20014 */ 	swc1	$f18,0x14($sp)
.L0f0cbf40:
/*  f0cbf40:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0cbf44:
/*  f0cbf44:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0cbf48:	03e00008 */ 	jr	$ra
/*  f0cbf4c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0cbf50
/*  f0cbf50:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0cbf54:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0cbf58:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0cbf5c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0cbf60:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0cbf64:	3c01c334 */ 	lui	$at,0xc334
/*  f0cbf68:	44811000 */ 	mtc1	$at,$f2
/*  f0cbf6c:	c4400154 */ 	lwc1	$f0,0x154($v0)
/*  f0cbf70:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0cbf74:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0cbf78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbf7c:	4502000c */ 	bc1fl	.L0f0cbfb0
/*  f0cbf80:	3c014334 */ 	lui	$at,0x4334
/*  f0cbf84:	44817000 */ 	mtc1	$at,$f14
/*  f0cbf88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbf8c:	460e0100 */ 	add.s	$f4,$f0,$f14
.L0f0cbf90:
/*  f0cbf90:	e4440154 */ 	swc1	$f4,0x154($v0)
/*  f0cbf94:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0cbf98:	c4400154 */ 	lwc1	$f0,0x154($v0)
/*  f0cbf9c:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0cbfa0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbfa4:	4503fffa */ 	bc1tl	.L0f0cbf90
/*  f0cbfa8:	460e0100 */ 	add.s	$f4,$f0,$f14
/*  f0cbfac:	3c014334 */ 	lui	$at,0x4334
.L0f0cbfb0:
/*  f0cbfb0:	44811000 */ 	mtc1	$at,$f2
/*  f0cbfb4:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0cbfb8:	44817000 */ 	mtc1	$at,$f14
/*  f0cbfbc:	4600103e */ 	c.le.s	$f2,$f0
/*  f0cbfc0:	3c0142b4 */ 	lui	$at,0x42b4
/*  f0cbfc4:	4502000a */ 	bc1fl	.L0f0cbff0
/*  f0cbfc8:	44811000 */ 	mtc1	$at,$f2
/*  f0cbfcc:	460e0181 */ 	sub.s	$f6,$f0,$f14
.L0f0cbfd0:
/*  f0cbfd0:	e4460154 */ 	swc1	$f6,0x154($v0)
/*  f0cbfd4:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0cbfd8:	c4400154 */ 	lwc1	$f0,0x154($v0)
/*  f0cbfdc:	4600103e */ 	c.le.s	$f2,$f0
/*  f0cbfe0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbfe4:	4503fffa */ 	bc1tl	.L0f0cbfd0
/*  f0cbfe8:	460e0181 */ 	sub.s	$f6,$f0,$f14
/*  f0cbfec:	44811000 */ 	mtc1	$at,$f2
.L0f0cbff0:
/*  f0cbff0:	3c01c2b4 */ 	lui	$at,0xc2b4
/*  f0cbff4:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0cbff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cbffc:	45020005 */ 	bc1fl	.L0f0cc014
/*  f0cc000:	44811000 */ 	mtc1	$at,$f2
/*  f0cc004:	e4420154 */ 	swc1	$f2,0x154($v0)
/*  f0cc008:	10000009 */ 	beqz	$zero,.L0f0cc030
/*  f0cc00c:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0cc010:	44811000 */ 	mtc1	$at,$f2
.L0f0cc014:
/*  f0cc014:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc018:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0cc01c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc020:	45000003 */ 	bc1f	.L0f0cc030
/*  f0cc024:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc028:	e4420154 */ 	swc1	$f2,0x154($v0)
/*  f0cc02c:	8c620284 */ 	lw	$v0,0x284($v1)
.L0f0cc030:
/*  f0cc030:	3c017f1b */ 	lui	$at,%hi(var7f1ad908)
/*  f0cc034:	c42ad908 */ 	lwc1	$f10,%lo(var7f1ad908)($at)
/*  f0cc038:	c4480144 */ 	lwc1	$f8,0x144($v0)
/*  f0cc03c:	460a4302 */ 	mul.s	$f12,$f8,$f10
/*  f0cc040:	0c0068f4 */ 	jal	func0001a3d0
/*  f0cc044:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc048:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0cc04c:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0cc050:	8c6e0284 */ 	lw	$t6,0x284($v1)
/*  f0cc054:	3c017f1b */ 	lui	$at,%hi(var7f1ad90c)
/*  f0cc058:	e5c0014c */ 	swc1	$f0,0x14c($t6)
/*  f0cc05c:	8c6f0284 */ 	lw	$t7,0x284($v1)
/*  f0cc060:	c432d90c */ 	lwc1	$f18,%lo(var7f1ad90c)($at)
/*  f0cc064:	c5f00144 */ 	lwc1	$f16,0x144($t7)
/*  f0cc068:	46128302 */ 	mul.s	$f12,$f16,$f18
/*  f0cc06c:	0c0068f7 */ 	jal	func0001a3dc
/*  f0cc070:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc074:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0cc078:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0cc07c:	8c780284 */ 	lw	$t8,0x284($v1)
/*  f0cc080:	44803000 */ 	mtc1	$zero,$f6
/*  f0cc084:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0cc088:	e7000150 */ 	swc1	$f0,0x150($t8)
/*  f0cc08c:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0cc090:	44817000 */ 	mtc1	$at,$f14
/*  f0cc094:	3c017f1b */ 	lui	$at,%hi(var7f1ad910)
/*  f0cc098:	c4440154 */ 	lwc1	$f4,0x154($v0)
/*  f0cc09c:	e4440158 */ 	swc1	$f4,0x158($v0)
/*  f0cc0a0:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0cc0a4:	c4420158 */ 	lwc1	$f2,0x158($v0)
/*  f0cc0a8:	4606103c */ 	c.lt.s	$f2,$f6
/*  f0cc0ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc0b0:	45000005 */ 	bc1f	.L0f0cc0c8
/*  f0cc0b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc0b8:	460e1200 */ 	add.s	$f8,$f2,$f14
/*  f0cc0bc:	e4480158 */ 	swc1	$f8,0x158($v0)
/*  f0cc0c0:	8c790284 */ 	lw	$t9,0x284($v1)
/*  f0cc0c4:	c7220158 */ 	lwc1	$f2,0x158($t9)
.L0f0cc0c8:
/*  f0cc0c8:	c42ad910 */ 	lwc1	$f10,%lo(var7f1ad910)($at)
/*  f0cc0cc:	460a1302 */ 	mul.s	$f12,$f2,$f10
/*  f0cc0d0:	0c0068f4 */ 	jal	func0001a3d0
/*  f0cc0d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc0d8:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0cc0dc:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0cc0e0:	8c680284 */ 	lw	$t0,0x284($v1)
/*  f0cc0e4:	3c017f1b */ 	lui	$at,%hi(var7f1ad914)
/*  f0cc0e8:	e5000160 */ 	swc1	$f0,0x160($t0)
/*  f0cc0ec:	8c690284 */ 	lw	$t1,0x284($v1)
/*  f0cc0f0:	c432d914 */ 	lwc1	$f18,%lo(var7f1ad914)($at)
/*  f0cc0f4:	c5300158 */ 	lwc1	$f16,0x158($t1)
/*  f0cc0f8:	46128302 */ 	mul.s	$f12,$f16,$f18
/*  f0cc0fc:	0c0068f7 */ 	jal	func0001a3dc
/*  f0cc100:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc104:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0cc108:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0cc10c:	8c6a0284 */ 	lw	$t2,0x284($v1)
/*  f0cc110:	44804000 */ 	mtc1	$zero,$f8
/*  f0cc114:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0cc118:	e5400164 */ 	swc1	$f0,0x164($t2)
/*  f0cc11c:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0cc120:	44817000 */ 	mtc1	$at,$f14
/*  f0cc124:	c4440150 */ 	lwc1	$f4,0x150($v0)
/*  f0cc128:	46002187 */ 	neg.s	$f6,$f4
/*  f0cc12c:	e446036c */ 	swc1	$f6,0x36c($v0)
/*  f0cc130:	8c6b0284 */ 	lw	$t3,0x284($v1)
/*  f0cc134:	e5680370 */ 	swc1	$f8,0x370($t3)
/*  f0cc138:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0cc13c:	c44a014c */ 	lwc1	$f10,0x14c($v0)
/*  f0cc140:	e44a0374 */ 	swc1	$f10,0x374($v0)
/*  f0cc144:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0cc148:	8c4500bc */ 	lw	$a1,0xbc($v0)
/*  f0cc14c:	50a00010 */ 	beqzl	$a1,.L0f0cc190
/*  f0cc150:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cc154:	8ca40004 */ 	lw	$a0,0x4($a1)
/*  f0cc158:	5080000d */ 	beqzl	$a0,.L0f0cc190
/*  f0cc15c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cc160:	8c8c0020 */ 	lw	$t4,0x20($a0)
/*  f0cc164:	5180000a */ 	beqzl	$t4,.L0f0cc190
/*  f0cc168:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cc16c:	c4500144 */ 	lwc1	$f16,0x144($v0)
/*  f0cc170:	3c017f1b */ 	lui	$at,%hi(var7f1ad918)
/*  f0cc174:	c424d918 */ 	lwc1	$f4,%lo(var7f1ad918)($at)
/*  f0cc178:	46107481 */ 	sub.s	$f18,$f14,$f16
/*  f0cc17c:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0cc180:	44053000 */ 	mfc1	$a1,$f6
/*  f0cc184:	0fc0f94e */ 	jal	func0f03e538
/*  f0cc188:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc18c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0cc190:
/*  f0cc190:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0cc194:	03e00008 */ 	jr	$ra
/*  f0cc198:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0cc19c
/*  f0cc19c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0cc1a0:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0cc1a4:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f0cc1a8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0cc1ac:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f0cc1b0:	8cae0284 */ 	lw	$t6,0x284($a1)
/*  f0cc1b4:	e5c4037c */ 	swc1	$f4,0x37c($t6)
/*  f0cc1b8:	8caf0284 */ 	lw	$t7,0x284($a1)
/*  f0cc1bc:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f0cc1c0:	e5e60380 */ 	swc1	$f6,0x380($t7)
/*  f0cc1c4:	8cb80284 */ 	lw	$t8,0x284($a1)
/*  f0cc1c8:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f0cc1cc:	e7080384 */ 	swc1	$f8,0x384($t8)
/*  f0cc1d0:	8ca20284 */ 	lw	$v0,0x284($a1)
/*  f0cc1d4:	8c5900d8 */ 	lw	$t9,0xd8($v0)
/*  f0cc1d8:	53200015 */ 	beqzl	$t9,.L0f0cc230
/*  f0cc1dc:	44801000 */ 	mtc1	$zero,$f2
/*  f0cc1e0:	44801000 */ 	mtc1	$zero,$f2
/*  f0cc1e4:	c4401928 */ 	lwc1	$f0,0x1928($v0)
/*  f0cc1e8:	3c013e80 */ 	lui	$at,0x3e80
/*  f0cc1ec:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0cc1f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc1f4:	4502000e */ 	bc1fl	.L0f0cc230
/*  f0cc1f8:	44801000 */ 	mtc1	$zero,$f2
/*  f0cc1fc:	44815000 */ 	mtc1	$at,$f10
/*  f0cc200:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc204:	460a0401 */ 	sub.s	$f16,$f0,$f10
/*  f0cc208:	e4501928 */ 	swc1	$f16,0x1928($v0)
/*  f0cc20c:	8ca20284 */ 	lw	$v0,0x284($a1)
/*  f0cc210:	c4521928 */ 	lwc1	$f18,0x1928($v0)
/*  f0cc214:	4602903c */ 	c.lt.s	$f18,$f2
/*  f0cc218:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc21c:	45020004 */ 	bc1fl	.L0f0cc230
/*  f0cc220:	44801000 */ 	mtc1	$zero,$f2
/*  f0cc224:	e4421928 */ 	swc1	$f2,0x1928($v0)
/*  f0cc228:	8ca20284 */ 	lw	$v0,0x284($a1)
/*  f0cc22c:	44801000 */ 	mtc1	$zero,$f2
.L0f0cc230:
/*  f0cc230:	c4440154 */ 	lwc1	$f4,0x154($v0)
/*  f0cc234:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cc238:	4602203c */ 	c.lt.s	$f4,$f2
/*  f0cc23c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc240:	4500000a */ 	bc1f	.L0f0cc26c
/*  f0cc244:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc248:	44813000 */ 	mtc1	$at,$f6
/*  f0cc24c:	c4480160 */ 	lwc1	$f8,0x160($v0)
/*  f0cc250:	c4521928 */ 	lwc1	$f18,0x1928($v0)
/*  f0cc254:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0cc258:	c4460380 */ 	lwc1	$f6,0x380($v0)
/*  f0cc25c:	46005407 */ 	neg.s	$f16,$f10
/*  f0cc260:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0cc264:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f0cc268:	e4480380 */ 	swc1	$f8,0x380($v0)
.L0f0cc26c:
/*  f0cc26c:	0fc41b99 */ 	jal	cheatIsActive
/*  f0cc270:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f0cc274:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0cc278:	10400040 */ 	beqz	$v0,.L0f0cc37c
/*  f0cc27c:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f0cc280:	8ca20284 */ 	lw	$v0,0x284($a1)
/*  f0cc284:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0cc288:	8c4301b0 */ 	lw	$v1,0x1b0($v0)
/*  f0cc28c:	14610008 */ 	bne	$v1,$at,.L0f0cc2b0
/*  f0cc290:	3c017f1b */ 	lui	$at,%hi(var7f1ad91c)
/*  f0cc294:	c430d91c */ 	lwc1	$f16,%lo(var7f1ad91c)($at)
/*  f0cc298:	c44a1a80 */ 	lwc1	$f10,0x1a80($v0)
/*  f0cc29c:	3c017f1b */ 	lui	$at,%hi(var7f1ad920)
/*  f0cc2a0:	c426d920 */ 	lwc1	$f6,%lo(var7f1ad920)($at)
/*  f0cc2a4:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0cc2a8:	1000002a */ 	beqz	$zero,.L0f0cc354
/*  f0cc2ac:	46069080 */ 	add.s	$f2,$f18,$f6
.L0f0cc2b0:
/*  f0cc2b0:	14600019 */ 	bnez	$v1,.L0f0cc318
/*  f0cc2b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc2b8:	8c481af8 */ 	lw	$t0,0x1af8($v0)
/*  f0cc2bc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cc2c0:	11000015 */ 	beqz	$t0,.L0f0cc318
/*  f0cc2c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc2c8:	8c4919ac */ 	lw	$t1,0x19ac($v0)
/*  f0cc2cc:	8c4a19b8 */ 	lw	$t2,0x19b8($v0)
/*  f0cc2d0:	c4401b48 */ 	lwc1	$f0,0x1b48($v0)
/*  f0cc2d4:	44812000 */ 	mtc1	$at,$f4
/*  f0cc2d8:	012a5823 */ 	subu	$t3,$t1,$t2
/*  f0cc2dc:	448b3000 */ 	mtc1	$t3,$f6
/*  f0cc2e0:	46002201 */ 	sub.s	$f8,$f4,$f0
/*  f0cc2e4:	3c017f1b */ 	lui	$at,%hi(var7f1ad924)
/*  f0cc2e8:	c42ad924 */ 	lwc1	$f10,%lo(var7f1ad924)($at)
/*  f0cc2ec:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f0cc2f0:	3c017f1b */ 	lui	$at,%hi(var7f1ad928)
/*  f0cc2f4:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0cc2f8:	c432d928 */ 	lwc1	$f18,%lo(var7f1ad928)($at)
/*  f0cc2fc:	c44a0380 */ 	lwc1	$f10,0x380($v0)
/*  f0cc300:	46002202 */ 	mul.s	$f8,$f4,$f0
/*  f0cc304:	46128080 */ 	add.s	$f2,$f16,$f18
/*  f0cc308:	46085400 */ 	add.s	$f16,$f10,$f8
/*  f0cc30c:	e4500380 */ 	swc1	$f16,0x380($v0)
/*  f0cc310:	10000010 */ 	beqz	$zero,.L0f0cc354
/*  f0cc314:	8ca20284 */ 	lw	$v0,0x284($a1)
.L0f0cc318:
/*  f0cc318:	1460000d */ 	bnez	$v1,.L0f0cc350
/*  f0cc31c:	3c017f1b */ 	lui	$at,%hi(var7f1ad92c)
/*  f0cc320:	8c4c19ac */ 	lw	$t4,0x19ac($v0)
/*  f0cc324:	8c4d19b8 */ 	lw	$t5,0x19b8($v0)
/*  f0cc328:	c4440380 */ 	lwc1	$f4,0x380($v0)
/*  f0cc32c:	3c017f1b */ 	lui	$at,%hi(var7f1ad930)
/*  f0cc330:	018d7023 */ 	subu	$t6,$t4,$t5
/*  f0cc334:	448e9000 */ 	mtc1	$t6,$f18
/*  f0cc338:	c422d92c */ 	lwc1	$f2,%lo(var7f1ad92c)($at)
/*  f0cc33c:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f0cc340:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f0cc344:	e44a0380 */ 	swc1	$f10,0x380($v0)
/*  f0cc348:	10000002 */ 	beqz	$zero,.L0f0cc354
/*  f0cc34c:	8ca20284 */ 	lw	$v0,0x284($a1)
.L0f0cc350:
/*  f0cc350:	c422d930 */ 	lwc1	$f2,%lo(var7f1ad930)($at)
.L0f0cc354:
/*  f0cc354:	c4480380 */ 	lwc1	$f8,0x380($v0)
/*  f0cc358:	c4500074 */ 	lwc1	$f16,0x74($v0)
/*  f0cc35c:	46104481 */ 	sub.s	$f18,$f8,$f16
/*  f0cc360:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f0cc364:	e4440380 */ 	swc1	$f4,0x380($v0)
/*  f0cc368:	8ca20284 */ 	lw	$v0,0x284($a1)
/*  f0cc36c:	c4460380 */ 	lwc1	$f6,0x380($v0)
/*  f0cc370:	c44a0074 */ 	lwc1	$f10,0x74($v0)
/*  f0cc374:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f0cc378:	e4480380 */ 	swc1	$f8,0x380($v0)
.L0f0cc37c:
/*  f0cc37c:	8ca20284 */ 	lw	$v0,0x284($a1)
/*  f0cc380:	3c014120 */ 	lui	$at,0x4120
/*  f0cc384:	44819000 */ 	mtc1	$at,$f18
/*  f0cc388:	c4500078 */ 	lwc1	$f16,0x78($v0)
/*  f0cc38c:	c4440380 */ 	lwc1	$f4,0x380($v0)
/*  f0cc390:	46128000 */ 	add.s	$f0,$f16,$f18
/*  f0cc394:	4600203c */ 	c.lt.s	$f4,$f0
/*  f0cc398:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc39c:	45020003 */ 	bc1fl	.L0f0cc3ac
/*  f0cc3a0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cc3a4:	e4400380 */ 	swc1	$f0,0x380($v0)
/*  f0cc3a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0cc3ac:
/*  f0cc3ac:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0cc3b0:	03e00008 */ 	jr	$ra
/*  f0cc3b4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0cc3b8
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
/*  f0cc45c:	3c198007 */ 	lui	$t9,0x8007
/*  f0cc460:	8f39077c */ 	lw	$t9,0x77c($t9)
/*  f0cc464:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f0cc468:	3c048007 */ 	lui	$a0,0x8007
/*  f0cc46c:	30450001 */ 	andi	$a1,$v0,0x1
/*  f0cc470:	0319001b */ 	divu	$zero,$t8,$t9
/*  f0cc474:	00004010 */ 	mfhi	$t0
/*  f0cc478:	00084840 */ 	sll	$t1,$t0,0x1
/*  f0cc47c:	00892021 */ 	addu	$a0,$a0,$t1
/*  f0cc480:	17200002 */ 	bnez	$t9,.L0f0cc48c
/*  f0cc484:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc488:	0007000d */ 	break	0x7
.L0f0cc48c:
/*  f0cc48c:	84840768 */ 	lh	$a0,0x768($a0)
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

GLOBAL_ASM(
glabel func0f0cc680
/*  f0cc680:	3c02800a */ 	lui	$v0,0x800a
/*  f0cc684:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0cc688:	8c4300ac */ 	lw	$v1,0xac($v0)
/*  f0cc68c:	8c4400b0 */ 	lw	$a0,0xb0($v0)
/*  f0cc690:	0064082a */ 	slt	$at,$v1,$a0
/*  f0cc694:	10200003 */ 	beqz	$at,.L0f0cc6a4
/*  f0cc698:	00802825 */ 	or	$a1,$a0,$zero
/*  f0cc69c:	03e00008 */ 	jr	$ra
/*  f0cc6a0:	00601025 */ 	or	$v0,$v1,$zero
.L0f0cc6a4:
/*  f0cc6a4:	03e00008 */ 	jr	$ra
/*  f0cc6a8:	00a01025 */ 	or	$v0,$a1,$zero
);

GLOBAL_ASM(
glabel func0f0cc6ac
/*  f0cc6ac:	00047080 */ 	sll	$t6,$a0,0x2
/*  f0cc6b0:	3c02800a */ 	lui	$v0,0x800a
/*  f0cc6b4:	004e1021 */ 	addu	$v0,$v0,$t6
/*  f0cc6b8:	8c42a024 */ 	lw	$v0,-0x5fdc($v0)
/*  f0cc6bc:	8c4300ac */ 	lw	$v1,0xac($v0)
/*  f0cc6c0:	8c4500b0 */ 	lw	$a1,0xb0($v0)
/*  f0cc6c4:	0065082a */ 	slt	$at,$v1,$a1
/*  f0cc6c8:	10200003 */ 	beqz	$at,.L0f0cc6d8
/*  f0cc6cc:	00a02025 */ 	or	$a0,$a1,$zero
/*  f0cc6d0:	03e00008 */ 	jr	$ra
/*  f0cc6d4:	00601025 */ 	or	$v0,$v1,$zero
.L0f0cc6d8:
/*  f0cc6d8:	03e00008 */ 	jr	$ra
/*  f0cc6dc:	00801025 */ 	or	$v0,$a0,$zero
);

GLOBAL_ASM(
glabel currentPlayerSetMoveModeGrabbedProp
/*  f0cc6e0:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0cc6e4:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0cc6e8:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0cc6ec:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0cc6f0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0cc6f4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0cc6f8:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0cc6fc:	8c4e01b0 */ 	lw	$t6,0x1b0($v0)
/*  f0cc700:	3c017f1b */ 	lui	$at,%hi(var7f1ad970)
/*  f0cc704:	c42ed970 */ 	lwc1	$f14,%lo(var7f1ad970)($at)
/*  f0cc708:	240f0004 */ 	addiu	$t7,$zero,0x4
/*  f0cc70c:	afae0094 */ 	sw	$t6,0x94($sp)
/*  f0cc710:	ac4f01b0 */ 	sw	$t7,0x1b0($v0)
/*  f0cc714:	44800000 */ 	mtc1	$zero,$f0
/*  f0cc718:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cc71c:	8c461b5c */ 	lw	$a2,0x1b5c($v0)
/*  f0cc720:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0cc724:	e7001b60 */ 	swc1	$f0,0x1b60($t8)
/*  f0cc728:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0cc72c:	c4c40008 */ 	lwc1	$f4,0x8($a2)
/*  f0cc730:	27b10054 */ 	addiu	$s1,$sp,0x54
/*  f0cc734:	02202825 */ 	or	$a1,$s1,$zero
/*  f0cc738:	e7241a00 */ 	swc1	$f4,0x1a00($t9)
/*  f0cc73c:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0cc740:	c4c6000c */ 	lwc1	$f6,0xc($a2)
/*  f0cc744:	e5061a04 */ 	swc1	$f6,0x1a04($t0)
/*  f0cc748:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0cc74c:	c4c80010 */ 	lwc1	$f8,0x10($a2)
/*  f0cc750:	e5281a08 */ 	swc1	$f8,0x1a08($t1)
/*  f0cc754:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0cc758:	e5401a0c */ 	swc1	$f0,0x1a0c($t2)
/*  f0cc75c:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0cc760:	e5601c58 */ 	swc1	$f0,0x1c58($t3)
/*  f0cc764:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0cc768:	c4ca0008 */ 	lwc1	$f10,0x8($a2)
/*  f0cc76c:	8c4c00bc */ 	lw	$t4,0xbc($v0)
/*  f0cc770:	c5900008 */ 	lwc1	$f16,0x8($t4)
/*  f0cc774:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f0cc778:	e4521a10 */ 	swc1	$f18,0x1a10($v0)
/*  f0cc77c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0cc780:	c4c4000c */ 	lwc1	$f4,0xc($a2)
/*  f0cc784:	8c4d00bc */ 	lw	$t5,0xbc($v0)
/*  f0cc788:	c5a6000c */ 	lwc1	$f6,0xc($t5)
/*  f0cc78c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0cc790:	e4481a14 */ 	swc1	$f8,0x1a14($v0)
/*  f0cc794:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0cc798:	c4ca0010 */ 	lwc1	$f10,0x10($a2)
/*  f0cc79c:	44814000 */ 	mtc1	$at,$f8
/*  f0cc7a0:	8c4e00bc */ 	lw	$t6,0xbc($v0)
/*  f0cc7a4:	c5d00010 */ 	lwc1	$f16,0x10($t6)
/*  f0cc7a8:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f0cc7ac:	e4521a18 */ 	swc1	$f18,0x1a18($v0)
/*  f0cc7b0:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0cc7b4:	ade01a1c */ 	sw	$zero,0x1a1c($t7)
/*  f0cc7b8:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cc7bc:	e7001a20 */ 	swc1	$f0,0x1a20($t8)
/*  f0cc7c0:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0cc7c4:	e7201a2c */ 	swc1	$f0,0x1a2c($t9)
/*  f0cc7c8:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0cc7cc:	e5001a30 */ 	swc1	$f0,0x1a30($t0)
/*  f0cc7d0:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0cc7d4:	e5201a34 */ 	swc1	$f0,0x1a34($t1)
/*  f0cc7d8:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0cc7dc:	e5401a38 */ 	swc1	$f0,0x1a38($t2)
/*  f0cc7e0:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0cc7e4:	e5601a3c */ 	swc1	$f0,0x1a3c($t3)
/*  f0cc7e8:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0cc7ec:	e5801a40 */ 	swc1	$f0,0x1a40($t4)
/*  f0cc7f0:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0cc7f4:	e5a01a44 */ 	swc1	$f0,0x1a44($t5)
/*  f0cc7f8:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0cc7fc:	e5c01968 */ 	swc1	$f0,0x1968($t6)
/*  f0cc800:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0cc804:	e5e001b4 */ 	swc1	$f0,0x1b4($t7)
/*  f0cc808:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cc80c:	e70001b8 */ 	swc1	$f0,0x1b8($t8)
/*  f0cc810:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0cc814:	c7240144 */ 	lwc1	$f4,0x144($t9)
/*  f0cc818:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f0cc81c:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f0cc820:	0c0058dd */ 	jal	func00016374
/*  f0cc824:	46083303 */ 	div.s	$f12,$f6,$f8
/*  f0cc828:	8e050284 */ 	lw	$a1,0x284($s0)
/*  f0cc82c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0cc830:	0c0056c4 */ 	jal	func00015b10
/*  f0cc834:	24a51a10 */ 	addiu	$a1,$a1,0x1a10
/*  f0cc838:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0cc83c:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f0cc840:	3c017f1b */ 	lui	$at,%hi(var7f1ad978)
/*  f0cc844:	c44a0144 */ 	lwc1	$f10,0x144($v0)
/*  f0cc848:	c42ed978 */ 	lwc1	$f14,%lo(var7f1ad978)($at)
/*  f0cc84c:	44800000 */ 	mtc1	$zero,$f0
/*  f0cc850:	e44a19fc */ 	swc1	$f10,0x19fc($v0)
/*  f0cc854:	90c30000 */ 	lbu	$v1,0x0($a2)
/*  f0cc858:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cc85c:	10610005 */ 	beq	$v1,$at,.L0f0cc874
/*  f0cc860:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0cc864:	10610003 */ 	beq	$v1,$at,.L0f0cc874
/*  f0cc868:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0cc86c:	5461006a */ 	bnel	$v1,$at,.L0f0cca18
/*  f0cc870:	8fa20094 */ 	lw	$v0,0x94($sp)
.L0f0cc874:
/*  f0cc874:	8cd10004 */ 	lw	$s1,0x4($a2)
/*  f0cc878:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cc87c:	8e280040 */ 	lw	$t0,0x40($s1)
/*  f0cc880:	31090080 */ 	andi	$t1,$t0,0x80
/*  f0cc884:	5120001a */ 	beqzl	$t1,.L0f0cc8f0
/*  f0cc888:	92220003 */ 	lbu	$v0,0x3($s1)
/*  f0cc88c:	8e230048 */ 	lw	$v1,0x48($s1)
/*  f0cc890:	3c017f1b */ 	lui	$at,%hi(var7f1ad97c)
/*  f0cc894:	c422d97c */ 	lwc1	$f2,%lo(var7f1ad97c)($at)
/*  f0cc898:	c4720004 */ 	lwc1	$f18,0x4($v1)
/*  f0cc89c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0cc8a0:	02202025 */ 	or	$a0,$s1,$zero
/*  f0cc8a4:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f0cc8a8:	c450017c */ 	lwc1	$f16,0x17c($v0)
/*  f0cc8ac:	46048180 */ 	add.s	$f6,$f16,$f4
/*  f0cc8b0:	e446017c */ 	swc1	$f6,0x17c($v0)
/*  f0cc8b4:	c46a000c */ 	lwc1	$f10,0xc($v1)
/*  f0cc8b8:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0cc8bc:	46025482 */ 	mul.s	$f18,$f10,$f2
/*  f0cc8c0:	c4480184 */ 	lwc1	$f8,0x184($v0)
/*  f0cc8c4:	46124400 */ 	add.s	$f16,$f8,$f18
/*  f0cc8c8:	e4500184 */ 	swc1	$f16,0x184($v0)
/*  f0cc8cc:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f0cc8d0:	0fc1ab10 */ 	jal	func0f06ac40
/*  f0cc8d4:	afa00048 */ 	sw	$zero,0x48($sp)
/*  f0cc8d8:	3c017f1b */ 	lui	$at,%hi(var7f1ad980)
/*  f0cc8dc:	44800000 */ 	mtc1	$zero,$f0
/*  f0cc8e0:	c42ed980 */ 	lwc1	$f14,%lo(var7f1ad980)($at)
/*  f0cc8e4:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f0cc8e8:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f0cc8ec:	92220003 */ 	lbu	$v0,0x3($s1)
.L0f0cc8f0:
/*  f0cc8f0:	24010035 */ 	addiu	$at,$zero,0x35
/*  f0cc8f4:	54410005 */ 	bnel	$v0,$at,.L0f0cc90c
/*  f0cc8f8:	24010033 */ 	addiu	$at,$zero,0x33
/*  f0cc8fc:	8cc20004 */ 	lw	$v0,0x4($a2)
/*  f0cc900:	10000006 */ 	beqz	$zero,.L0f0cc91c
/*  f0cc904:	2445005c */ 	addiu	$a1,$v0,0x5c
/*  f0cc908:	24010033 */ 	addiu	$at,$zero,0x33
.L0f0cc90c:
/*  f0cc90c:	14410003 */ 	bne	$v0,$at,.L0f0cc91c
/*  f0cc910:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc914:	8cc20004 */ 	lw	$v0,0x4($a2)
/*  f0cc918:	2445005c */ 	addiu	$a1,$v0,0x5c
.L0f0cc91c:
/*  f0cc91c:	50a0001b */ 	beqzl	$a1,.L0f0cc98c
/*  f0cc920:	8e2a0040 */ 	lw	$t2,0x40($s1)
/*  f0cc924:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0cc928:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0cc92c:	44815000 */ 	mtc1	$at,$f10
/*  f0cc930:	c4440144 */ 	lwc1	$f4,0x144($v0)
/*  f0cc934:	c4b00010 */ 	lwc1	$f16,0x10($a1)
/*  f0cc938:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f0cc93c:	460a3203 */ 	div.s	$f8,$f6,$f10
/*  f0cc940:	46087481 */ 	sub.s	$f18,$f14,$f8
/*  f0cc944:	46128101 */ 	sub.s	$f4,$f16,$f18
/*  f0cc948:	e4441a0c */ 	swc1	$f4,0x1a0c($v0)
/*  f0cc94c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0cc950:	c4421a0c */ 	lwc1	$f2,0x1a0c($v0)
/*  f0cc954:	4602703e */ 	c.le.s	$f14,$f2
/*  f0cc958:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc95c:	45020005 */ 	bc1fl	.L0f0cc974
/*  f0cc960:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0cc964:	460e1181 */ 	sub.s	$f6,$f2,$f14
/*  f0cc968:	10000007 */ 	beqz	$zero,.L0f0cc988
/*  f0cc96c:	e4461a0c */ 	swc1	$f6,0x1a0c($v0)
/*  f0cc970:	4600103c */ 	c.lt.s	$f2,$f0
.L0f0cc974:
/*  f0cc974:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cc978:	45020004 */ 	bc1fl	.L0f0cc98c
/*  f0cc97c:	8e2a0040 */ 	lw	$t2,0x40($s1)
/*  f0cc980:	460e1280 */ 	add.s	$f10,$f2,$f14
/*  f0cc984:	e44a1a0c */ 	swc1	$f10,0x1a0c($v0)
.L0f0cc988:
/*  f0cc988:	8e2a0040 */ 	lw	$t2,0x40($s1)
.L0f0cc98c:
/*  f0cc98c:	8e2c0010 */ 	lw	$t4,0x10($s1)
/*  f0cc990:	3c010800 */ 	lui	$at,0x800
/*  f0cc994:	01415825 */ 	or	$t3,$t2,$at
/*  f0cc998:	000c6980 */ 	sll	$t5,$t4,0x6
/*  f0cc99c:	05a1000d */ 	bgez	$t5,.L0f0cc9d4
/*  f0cc9a0:	ae2b0040 */ 	sw	$t3,0x40($s1)
/*  f0cc9a4:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0cc9a8:	8e240044 */ 	lw	$a0,0x44($s1)
/*  f0cc9ac:	3c074234 */ 	lui	$a3,0x4234
/*  f0cc9b0:	8dc200bc */ 	lw	$v0,0xbc($t6)
/*  f0cc9b4:	8c450008 */ 	lw	$a1,0x8($v0)
/*  f0cc9b8:	8c460010 */ 	lw	$a2,0x10($v0)
/*  f0cc9bc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0cc9c0:	0c009db2 */ 	jal	func000276c8
/*  f0cc9c4:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0cc9c8:	44800000 */ 	mtc1	$zero,$f0
/*  f0cc9cc:	1000000c */ 	beqz	$zero,.L0f0cca00
/*  f0cc9d0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cc9d4:
/*  f0cc9d4:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0cc9d8:	8e240044 */ 	lw	$a0,0x44($s1)
/*  f0cc9dc:	3c074234 */ 	lui	$a3,0x4234
/*  f0cc9e0:	8de200bc */ 	lw	$v0,0xbc($t7)
/*  f0cc9e4:	8c450008 */ 	lw	$a1,0x8($v0)
/*  f0cc9e8:	8c460010 */ 	lw	$a2,0x10($v0)
/*  f0cc9ec:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0cc9f0:	0c009d38 */ 	jal	func000274e0
/*  f0cc9f4:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0cc9f8:	44800000 */ 	mtc1	$zero,$f0
/*  f0cc9fc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cca00:
/*  f0cca00:	10400004 */ 	beqz	$v0,.L0f0cca14
/*  f0cca04:	3c014170 */ 	lui	$at,0x4170
/*  f0cca08:	44814000 */ 	mtc1	$at,$f8
/*  f0cca0c:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cca10:	e7081c58 */ 	swc1	$f8,0x1c58($t8)
.L0f0cca14:
/*  f0cca14:	8fa20094 */ 	lw	$v0,0x94($sp)
.L0f0cca18:
/*  f0cca18:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0cca1c:	50410022 */ 	beql	$v0,$at,.L0f0ccaa8
/*  f0cca20:	8e0a0008 */ 	lw	$t2,0x8($s0)
/*  f0cca24:	1040001f */ 	beqz	$v0,.L0f0ccaa4
/*  f0cca28:	2403000c */ 	addiu	$v1,$zero,0xc
/*  f0cca2c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0cca30:
/*  f0cca30:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0cca34:	03224021 */ 	addu	$t0,$t9,$v0
/*  f0cca38:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f0cca3c:	1443fffc */ 	bne	$v0,$v1,.L0f0cca30
/*  f0cca40:	e500017c */ 	swc1	$f0,0x17c($t0)
/*  f0cca44:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0cca48:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cca4c:	44818000 */ 	mtc1	$at,$f16
/*  f0cca50:	e5200168 */ 	swc1	$f0,0x168($t1)
/*  f0cca54:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0cca58:	e540016c */ 	swc1	$f0,0x16c($t2)
/*  f0cca5c:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0cca60:	e56019a4 */ 	swc1	$f0,0x19a4($t3)
/*  f0cca64:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0cca68:	e5900174 */ 	swc1	$f16,0x174($t4)
/*  f0cca6c:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0cca70:	ada00178 */ 	sw	$zero,0x178($t5)
/*  f0cca74:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0cca78:	e5c00170 */ 	swc1	$f0,0x170($t6)
/*  f0cca7c:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0cca80:	e5e00148 */ 	swc1	$f0,0x148($t7)
/*  f0cca84:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cca88:	e7001b9c */ 	swc1	$f0,0x1b9c($t8)
/*  f0cca8c:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0cca90:	e72001a4 */ 	swc1	$f0,0x1a4($t9)
/*  f0cca94:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0cca98:	e50001a8 */ 	swc1	$f0,0x1a8($t0)
/*  f0cca9c:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0ccaa0:	e52001ac */ 	swc1	$f0,0x1ac($t1)
.L0f0ccaa4:
/*  f0ccaa4:	8e0a0008 */ 	lw	$t2,0x8($s0)
.L0f0ccaa8:
/*  f0ccaa8:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0ccaac:	ad6a1b64 */ 	sw	$t2,0x1b64($t3)
/*  f0ccab0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0ccab4:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f0ccab8:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f0ccabc:	03e00008 */ 	jr	$ra
/*  f0ccac0:	27bd0098 */ 	addiu	$sp,$sp,0x98
);

GLOBAL_ASM(
glabel func0f0ccac4
/*  f0ccac4:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0ccac8:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0ccacc:	8d0e0284 */ 	lw	$t6,0x284($t0)
/*  f0ccad0:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0ccad4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0ccad8:	8dc31b5c */ 	lw	$v1,0x1b5c($t6)
/*  f0ccadc:	50600041 */ 	beqzl	$v1,.L0f0ccbe4
/*  f0ccae0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0ccae4:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f0ccae8:	3c01f7ff */ 	lui	$at,0xf7ff
/*  f0ccaec:	3421ffff */ 	ori	$at,$at,0xffff
/*  f0ccaf0:	8c4f0040 */ 	lw	$t7,0x40($v0)
/*  f0ccaf4:	01e1c024 */ 	and	$t8,$t7,$at
/*  f0ccaf8:	ac580040 */ 	sw	$t8,0x40($v0)
/*  f0ccafc:	8d190034 */ 	lw	$t9,0x34($t0)
/*  f0ccb00:	5b200036 */ 	blezl	$t9,.L0f0ccbdc
/*  f0ccb04:	8d0c0284 */ 	lw	$t4,0x284($t0)
/*  f0ccb08:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0ccb0c:	c502004c */ 	lwc1	$f2,0x4c($t0)
/*  f0ccb10:	44808000 */ 	mtc1	$zero,$f16
/*  f0ccb14:	8c491b5c */ 	lw	$t1,0x1b5c($v0)
/*  f0ccb18:	c4461a00 */ 	lwc1	$f6,0x1a00($v0)
/*  f0ccb1c:	3c017f1b */ 	lui	$at,%hi(var7f1ad984)
/*  f0ccb20:	c5240008 */ 	lwc1	$f4,0x8($t1)
/*  f0ccb24:	e7b00038 */ 	swc1	$f16,0x38($sp)
/*  f0ccb28:	c42cd984 */ 	lwc1	$f12,%lo(var7f1ad984)($at)
/*  f0ccb2c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0ccb30:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0ccb34:	46024283 */ 	div.s	$f10,$f8,$f2
/*  f0ccb38:	e7aa0034 */ 	swc1	$f10,0x34($sp)
/*  f0ccb3c:	8c4a1b5c */ 	lw	$t2,0x1b5c($v0)
/*  f0ccb40:	c4441a08 */ 	lwc1	$f4,0x1a08($v0)
/*  f0ccb44:	c5520010 */ 	lwc1	$f18,0x10($t2)
/*  f0ccb48:	46049181 */ 	sub.s	$f6,$f18,$f4
/*  f0ccb4c:	46023203 */ 	div.s	$f8,$f6,$f2
/*  f0ccb50:	e7a8003c */ 	swc1	$f8,0x3c($sp)
/*  f0ccb54:	c45019fc */ 	lwc1	$f16,0x19fc($v0)
/*  f0ccb58:	c44a0144 */ 	lwc1	$f10,0x144($v0)
/*  f0ccb5c:	44814000 */ 	mtc1	$at,$f8
/*  f0ccb60:	3c017f1b */ 	lui	$at,%hi(var7f1ad988)
/*  f0ccb64:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f0ccb68:	c42ad988 */ 	lwc1	$f10,%lo(var7f1ad988)($at)
/*  f0ccb6c:	3c017f1b */ 	lui	$at,%hi(var7f1ad98c)
/*  f0ccb70:	46009107 */ 	neg.s	$f4,$f18
/*  f0ccb74:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f0ccb78:	46083003 */ 	div.s	$f0,$f6,$f8
/*  f0ccb7c:	460a003c */ 	c.lt.s	$f0,$f10
/*  f0ccb80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ccb84:	45000003 */ 	bc1f	.L0f0ccb94
/*  f0ccb88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ccb8c:	10000007 */ 	beqz	$zero,.L0f0ccbac
/*  f0ccb90:	460c0000 */ 	add.s	$f0,$f0,$f12
.L0f0ccb94:
/*  f0ccb94:	c430d98c */ 	lwc1	$f16,%lo(var7f1ad98c)($at)
/*  f0ccb98:	4600803e */ 	c.le.s	$f16,$f0
/*  f0ccb9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ccba0:	45020003 */ 	bc1fl	.L0f0ccbb0
/*  f0ccba4:	46020003 */ 	div.s	$f0,$f0,$f2
/*  f0ccba8:	460c0001 */ 	sub.s	$f0,$f0,$f12
.L0f0ccbac:
/*  f0ccbac:	46020003 */ 	div.s	$f0,$f0,$f2
.L0f0ccbb0:
/*  f0ccbb0:	8c4b1b5c */ 	lw	$t3,0x1b5c($v0)
/*  f0ccbb4:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f0ccbb8:	00003825 */ 	or	$a3,$zero,$zero
/*  f0ccbbc:	8d640004 */ 	lw	$a0,0x4($t3)
/*  f0ccbc0:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0ccbc4:	44060000 */ 	mfc1	$a2,$f0
/*  f0ccbc8:	0fc20a87 */ 	jal	func0f082a1c
/*  f0ccbcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ccbd0:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0ccbd4:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0ccbd8:	8d0c0284 */ 	lw	$t4,0x284($t0)
.L0f0ccbdc:
/*  f0ccbdc:	ad801b5c */ 	sw	$zero,0x1b5c($t4)
/*  f0ccbe0:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0ccbe4:
/*  f0ccbe4:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f0ccbe8:	03e00008 */ 	jr	$ra
/*  f0ccbec:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ccbf0
/*  f0ccbf0:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0ccbf4:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0ccbf8:	8c6e0034 */ 	lw	$t6,0x34($v1)
/*  f0ccbfc:	27bdff20 */ 	addiu	$sp,$sp,-224
/*  f0ccc00:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0ccc04:	afa400e0 */ 	sw	$a0,0xe0($sp)
/*  f0ccc08:	afa500e4 */ 	sw	$a1,0xe4($sp)
/*  f0ccc0c:	19c0010f */ 	blez	$t6,.L0f0cd04c
/*  f0ccc10:	afa600e8 */ 	sw	$a2,0xe8($sp)
/*  f0ccc14:	3c0f800a */ 	lui	$t7,0x800a
/*  f0ccc18:	8defde70 */ 	lw	$t7,-0x2190($t7)
/*  f0ccc1c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0ccc20:	27ae0074 */ 	addiu	$t6,$sp,0x74
/*  f0ccc24:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f0ccc28:	3c0f8007 */ 	lui	$t7,%hi(var80070e84)
/*  f0ccc2c:	25ef0e84 */ 	addiu	$t7,$t7,%lo(var80070e84)
/*  f0ccc30:	1701004f */ 	bne	$t8,$at,.L0f0ccd70
/*  f0ccc34:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f0ccc38:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ccc3c:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f0ccc40:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f0ccc44:	8c4800bc */ 	lw	$t0,0xbc($v0)
/*  f0ccc48:	24e7d940 */ 	addiu	$a3,$a3,-9920
/*  f0ccc4c:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0ccc50:	c5060008 */ 	lwc1	$f6,0x8($t0)
/*  f0ccc54:	240600c9 */ 	addiu	$a2,$zero,0xc9
/*  f0ccc58:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0ccc5c:	e7a80098 */ 	swc1	$f8,0x98($sp)
/*  f0ccc60:	8c4900bc */ 	lw	$t1,0xbc($v0)
/*  f0ccc64:	c52a000c */ 	lwc1	$f10,0xc($t1)
/*  f0ccc68:	e7aa009c */ 	swc1	$f10,0x9c($sp)
/*  f0ccc6c:	8c4a00bc */ 	lw	$t2,0xbc($v0)
/*  f0ccc70:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f0ccc74:	27a400b0 */ 	addiu	$a0,$sp,0xb0
/*  f0ccc78:	c5460010 */ 	lwc1	$f6,0x10($t2)
/*  f0ccc7c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0ccc80:	0c009393 */ 	jal	func00024e4c
/*  f0ccc84:	e7a800a0 */ 	swc1	$f8,0xa0($sp)
/*  f0ccc88:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*  f0ccc8c:	c7a400b8 */ 	lwc1	$f4,0xb8($sp)
/*  f0ccc90:	44809000 */ 	mtc1	$zero,$f18
/*  f0ccc94:	c7a600b0 */ 	lwc1	$f6,0xb0($sp)
/*  f0ccc98:	46045001 */ 	sub.s	$f0,$f10,$f4
/*  f0ccc9c:	c7a800a4 */ 	lwc1	$f8,0xa4($sp)
/*  f0ccca0:	27a400c8 */ 	addiu	$a0,$sp,0xc8
/*  f0ccca4:	27a500cc */ 	addiu	$a1,$sp,0xcc
/*  f0ccca8:	46009032 */ 	c.eq.s	$f18,$f0
/*  f0cccac:	e7a000c8 */ 	swc1	$f0,0xc8($sp)
/*  f0cccb0:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0cccb4:	e7b200cc */ 	swc1	$f18,0xcc($sp)
/*  f0cccb8:	45000005 */ 	bc1f	.L0f0cccd0
/*  f0cccbc:	e7aa00d0 */ 	swc1	$f10,0xd0($sp)
/*  f0cccc0:	460a9032 */ 	c.eq.s	$f18,$f10
/*  f0cccc4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cccc8:	45030006 */ 	bc1tl	.L0f0ccce4
/*  f0ccccc:	44812000 */ 	mtc1	$at,$f4
.L0f0cccd0:
/*  f0cccd0:	0c0011e4 */ 	jal	scaleTo1
/*  f0cccd4:	27a600d0 */ 	addiu	$a2,$sp,0xd0
/*  f0cccd8:	10000005 */ 	beqz	$zero,.L0f0cccf0
/*  f0cccdc:	27ab00d4 */ 	addiu	$t3,$sp,0xd4
/*  f0ccce0:	44812000 */ 	mtc1	$at,$f4
.L0f0ccce4:
/*  f0ccce4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ccce8:	e7a400d0 */ 	swc1	$f4,0xd0($sp)
/*  f0cccec:	27ab00d4 */ 	addiu	$t3,$sp,0xd4
.L0f0cccf0:
/*  f0cccf0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0cccf4:	27a400b0 */ 	addiu	$a0,$sp,0xb0
/*  f0cccf8:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f0cccfc:	27a60098 */ 	addiu	$a2,$sp,0x98
/*  f0ccd00:	0fc0b8f7 */ 	jal	func0f02e3dc
/*  f0ccd04:	27a700c8 */ 	addiu	$a3,$sp,0xc8
/*  f0ccd08:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0ccd0c:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0ccd10:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ccd14:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f0ccd18:	c460004c */ 	lwc1	$f0,0x4c($v1)
/*  f0ccd1c:	8c4c00bc */ 	lw	$t4,0xbc($v0)
/*  f0ccd20:	44809000 */ 	mtc1	$zero,$f18
/*  f0ccd24:	8fa400e8 */ 	lw	$a0,0xe8($sp)
/*  f0ccd28:	c5880008 */ 	lwc1	$f8,0x8($t4)
/*  f0ccd2c:	e7b200c0 */ 	swc1	$f18,0xc0($sp)
/*  f0ccd30:	27a500d4 */ 	addiu	$a1,$sp,0xd4
/*  f0ccd34:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0ccd38:	c7a600a0 */ 	lwc1	$f6,0xa0($sp)
/*  f0ccd3c:	27a600c8 */ 	addiu	$a2,$sp,0xc8
/*  f0ccd40:	27a700bc */ 	addiu	$a3,$sp,0xbc
/*  f0ccd44:	46005103 */ 	div.s	$f4,$f10,$f0
/*  f0ccd48:	e7a400bc */ 	swc1	$f4,0xbc($sp)
/*  f0ccd4c:	8c4d00bc */ 	lw	$t5,0xbc($v0)
/*  f0ccd50:	c5a80010 */ 	lwc1	$f8,0x10($t5)
/*  f0ccd54:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0ccd58:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0ccd5c:	46005103 */ 	div.s	$f4,$f10,$f0
/*  f0ccd60:	0fc20ba1 */ 	jal	func0f082e84
/*  f0ccd64:	e7a400c4 */ 	swc1	$f4,0xc4($sp)
/*  f0ccd68:	100000b9 */ 	beqz	$zero,.L0f0cd050
/*  f0ccd6c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0ccd70:
/*  f0ccd70:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0ccd74:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f0ccd78:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f0ccd7c:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0ccd80:	8de10008 */ 	lw	$at,0x8($t7)
/*  f0ccd84:	24e7d94c */ 	addiu	$a3,$a3,-9908
/*  f0ccd88:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f0ccd8c:	240600e4 */ 	addiu	$a2,$zero,0xe4
/*  f0ccd90:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f0ccd94:	0c009393 */ 	jal	func00024e4c
/*  f0ccd98:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0ccd9c:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f0ccda0:	0c0094d9 */ 	jal	func00025364
/*  f0ccda4:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f0ccda8:	1040000e */ 	beqz	$v0,.L0f0ccde4
/*  f0ccdac:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f0ccdb0:	c7a60044 */ 	lwc1	$f6,0x44($sp)
/*  f0ccdb4:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*  f0ccdb8:	c7a40048 */ 	lwc1	$f4,0x48($sp)
/*  f0ccdbc:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0ccdc0:	c7a60054 */ 	lwc1	$f6,0x54($sp)
/*  f0ccdc4:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0ccdc8:	e7aa0044 */ 	swc1	$f10,0x44($sp)
/*  f0ccdcc:	c7aa004c */ 	lwc1	$f10,0x4c($sp)
/*  f0ccdd0:	c7a40058 */ 	lwc1	$f4,0x58($sp)
/*  f0ccdd4:	e7a80048 */ 	swc1	$f8,0x48($sp)
/*  f0ccdd8:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f0ccddc:	10000019 */ 	beqz	$zero,.L0f0cce44
/*  f0ccde0:	e7a6004c */ 	swc1	$f6,0x4c($sp)
.L0f0ccde4:
/*  f0ccde4:	3c02800a */ 	lui	$v0,0x800a
/*  f0ccde8:	8c42de70 */ 	lw	$v0,-0x2190($v0)
/*  f0ccdec:	8fb900e8 */ 	lw	$t9,0xe8($sp)
/*  f0ccdf0:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0ccdf4:	e7a80050 */ 	swc1	$f8,0x50($sp)
/*  f0ccdf8:	c44a000c */ 	lwc1	$f10,0xc($v0)
/*  f0ccdfc:	e7aa0054 */ 	swc1	$f10,0x54($sp)
/*  f0cce00:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0cce04:	e7a40058 */ 	swc1	$f4,0x58($sp)
/*  f0cce08:	8f2a0014 */ 	lw	$t2,0x14($t9)
/*  f0cce0c:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f0cce10:	c5460008 */ 	lwc1	$f6,0x8($t2)
/*  f0cce14:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0cce18:	e7aa0044 */ 	swc1	$f10,0x44($sp)
/*  f0cce1c:	8f2b0014 */ 	lw	$t3,0x14($t9)
/*  f0cce20:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f0cce24:	c564000c */ 	lwc1	$f4,0xc($t3)
/*  f0cce28:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0cce2c:	e7a80048 */ 	swc1	$f8,0x48($sp)
/*  f0cce30:	8f2c0014 */ 	lw	$t4,0x14($t9)
/*  f0cce34:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f0cce38:	c58a0010 */ 	lwc1	$f10,0x10($t4)
/*  f0cce3c:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f0cce40:	e7a6004c */ 	swc1	$f6,0x4c($sp)
.L0f0cce44:
/*  f0cce44:	27ad008c */ 	addiu	$t5,$sp,0x8c
/*  f0cce48:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0cce4c:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f0cce50:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f0cce54:	0fc0b8f7 */ 	jal	func0f02e3dc
/*  f0cce58:	27a70044 */ 	addiu	$a3,$sp,0x44
/*  f0cce5c:	8fa200e0 */ 	lw	$v0,0xe0($sp)
/*  f0cce60:	44809000 */ 	mtc1	$zero,$f18
/*  f0cce64:	27a40080 */ 	addiu	$a0,$sp,0x80
/*  f0cce68:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f0cce6c:	e7b20084 */ 	swc1	$f18,0x84($sp)
/*  f0cce70:	27a50084 */ 	addiu	$a1,$sp,0x84
/*  f0cce74:	e7a80080 */ 	swc1	$f8,0x80($sp)
/*  f0cce78:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f0cce7c:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f0cce80:	46049032 */ 	c.eq.s	$f18,$f4
/*  f0cce84:	e7aa0088 */ 	swc1	$f10,0x88($sp)
/*  f0cce88:	c7a60088 */ 	lwc1	$f6,0x88($sp)
/*  f0cce8c:	45000005 */ 	bc1f	.L0f0ccea4
/*  f0cce90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cce94:	46069032 */ 	c.eq.s	$f18,$f6
/*  f0cce98:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cce9c:	45030007 */ 	bc1tl	.L0f0ccebc
/*  f0ccea0:	44814000 */ 	mtc1	$at,$f8
.L0f0ccea4:
/*  f0ccea4:	0c0011e4 */ 	jal	scaleTo1
/*  f0ccea8:	27a60088 */ 	addiu	$a2,$sp,0x88
/*  f0cceac:	44809000 */ 	mtc1	$zero,$f18
/*  f0cceb0:	10000004 */ 	beqz	$zero,.L0f0ccec4
/*  f0cceb4:	8fa200e0 */ 	lw	$v0,0xe0($sp)
/*  f0cceb8:	44814000 */ 	mtc1	$at,$f8
.L0f0ccebc:
/*  f0ccebc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ccec0:	e7a80088 */ 	swc1	$f8,0x88($sp)
.L0f0ccec4:
/*  f0ccec4:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f0ccec8:	3c01800a */ 	lui	$at,0x800a
/*  f0ccecc:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0cced0:	46009032 */ 	c.eq.s	$f18,$f0
/*  f0cced4:	27a60080 */ 	addiu	$a2,$sp,0x80
/*  f0cced8:	27a70074 */ 	addiu	$a3,$sp,0x74
/*  f0ccedc:	45030007 */ 	bc1tl	.L0f0ccefc
/*  f0ccee0:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f0ccee4:	c424a00c */ 	lwc1	$f4,-0x5ff4($at)
/*  f0ccee8:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f0cceec:	46040183 */ 	div.s	$f6,$f0,$f4
/*  f0ccef0:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0ccef4:	e7a80074 */ 	swc1	$f8,0x74($sp)
/*  f0ccef8:	c4400008 */ 	lwc1	$f0,0x8($v0)
.L0f0ccefc:
/*  f0ccefc:	3c01800a */ 	lui	$at,0x800a
/*  f0ccf00:	46009032 */ 	c.eq.s	$f18,$f0
/*  f0ccf04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ccf08:	45030007 */ 	bc1tl	.L0f0ccf28
/*  f0ccf0c:	8fa400e8 */ 	lw	$a0,0xe8($sp)
/*  f0ccf10:	c42aa00c */ 	lwc1	$f10,-0x5ff4($at)
/*  f0ccf14:	c7a4007c */ 	lwc1	$f4,0x7c($sp)
/*  f0ccf18:	460a0183 */ 	div.s	$f6,$f0,$f10
/*  f0ccf1c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0ccf20:	e7a8007c */ 	swc1	$f8,0x7c($sp)
/*  f0ccf24:	8fa400e8 */ 	lw	$a0,0xe8($sp)
.L0f0ccf28:
/*  f0ccf28:	0fc20ba1 */ 	jal	func0f082e84
/*  f0ccf2c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0ccf30:	44809000 */ 	mtc1	$zero,$f18
/*  f0ccf34:	c7aa00e4 */ 	lwc1	$f10,0xe4($sp)
/*  f0ccf38:	3c08800a */ 	lui	$t0,0x800a
/*  f0ccf3c:	46125032 */ 	c.eq.s	$f10,$f18
/*  f0ccf40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ccf44:	45030042 */ 	bc1tl	.L0f0cd050
/*  f0ccf48:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0ccf4c:	8d08a244 */ 	lw	$t0,-0x5dbc($t0)
/*  f0ccf50:	c7a4008c */ 	lwc1	$f4,0x8c($sp)
/*  f0ccf54:	c7a80094 */ 	lwc1	$f8,0x94($sp)
/*  f0ccf58:	8d0200bc */ 	lw	$v0,0xbc($t0)
/*  f0ccf5c:	3c0e8007 */ 	lui	$t6,%hi(var80070e90)
/*  f0ccf60:	25ce0e90 */ 	addiu	$t6,$t6,%lo(var80070e90)
/*  f0ccf64:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f0ccf68:	c44a0010 */ 	lwc1	$f10,0x10($v0)
/*  f0ccf6c:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0ccf70:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f0ccf74:	27b8002c */ 	addiu	$t8,$sp,0x2c
/*  f0ccf78:	af010000 */ 	sw	$at,0x0($t8)
/*  f0ccf7c:	460a4381 */ 	sub.s	$f14,$f8,$f10
/*  f0ccf80:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f0ccf84:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f0ccf88:	8dc90004 */ 	lw	$t1,0x4($t6)
/*  f0ccf8c:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f0ccf90:	af010008 */ 	sw	$at,0x8($t8)
/*  f0ccf94:	af090004 */ 	sw	$t1,0x4($t8)
/*  f0ccf98:	e7ae003c */ 	swc1	$f14,0x3c($sp)
/*  f0ccf9c:	e7a20040 */ 	swc1	$f2,0x40($sp)
/*  f0ccfa0:	0c012974 */ 	jal	sqrtf
/*  f0ccfa4:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f0ccfa8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ccfac:	44814000 */ 	mtc1	$at,$f8
/*  f0ccfb0:	3c01800a */ 	lui	$at,0x800a
/*  f0ccfb4:	c424a00c */ 	lwc1	$f4,-0x5ff4($at)
/*  f0ccfb8:	46004303 */ 	div.s	$f12,$f8,$f0
/*  f0ccfbc:	c7aa00e4 */ 	lwc1	$f10,0xe4($sp)
/*  f0ccfc0:	c7a20040 */ 	lwc1	$f2,0x40($sp)
/*  f0ccfc4:	c7ae003c */ 	lwc1	$f14,0x3c($sp)
/*  f0ccfc8:	3c014220 */ 	lui	$at,0x4220
/*  f0ccfcc:	44809000 */ 	mtc1	$zero,$f18
/*  f0ccfd0:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0ccfd4:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0ccfd8:	8fa400e8 */ 	lw	$a0,0xe8($sp)
/*  f0ccfdc:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*  f0ccfe0:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0ccfe4:	46045183 */ 	div.s	$f6,$f10,$f4
/*  f0ccfe8:	44812000 */ 	mtc1	$at,$f4
/*  f0ccfec:	460c1082 */ 	mul.s	$f2,$f2,$f12
/*  f0ccff0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ccff4:	460c7382 */ 	mul.s	$f14,$f14,$f12
/*  f0ccff8:	46007207 */ 	neg.s	$f8,$f14
/*  f0ccffc:	e7a600e4 */ 	swc1	$f6,0xe4($sp)
/*  f0cd000:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f0cd004:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd008:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f0cd00c:	c7aa002c */ 	lwc1	$f10,0x2c($sp)
/*  f0cd010:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0cd014:	46061282 */ 	mul.s	$f10,$f2,$f6
/*  f0cd018:	44814000 */ 	mtc1	$at,$f8
/*  f0cd01c:	3c017f1b */ 	lui	$at,%hi(var7f1ad990)
/*  f0cd020:	e7a4002c */ 	swc1	$f4,0x2c($sp)
/*  f0cd024:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0cd028:	c7aa0034 */ 	lwc1	$f10,0x34($sp)
/*  f0cd02c:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f0cd030:	c42ad990 */ 	lwc1	$f10,%lo(var7f1ad990)($at)
/*  f0cd034:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f0cd038:	e7a80034 */ 	swc1	$f8,0x34($sp)
/*  f0cd03c:	46049400 */ 	add.s	$f16,$f18,$f4
/*  f0cd040:	44068000 */ 	mfc1	$a2,$f16
/*  f0cd044:	0fc20a87 */ 	jal	func0f082a1c
/*  f0cd048:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cd04c:
/*  f0cd04c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0cd050:
/*  f0cd050:	27bd00e0 */ 	addiu	$sp,$sp,0xe0
/*  f0cd054:	03e00008 */ 	jr	$ra
/*  f0cd058:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0cd05c
/*  f0cd05c:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0cd060:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0cd064:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0cd068:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0cd06c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f0cd070:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0cd074:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f0cd078:	8c4e00bc */ 	lw	$t6,0xbc($v0)
/*  f0cd07c:	27a6003c */ 	addiu	$a2,$sp,0x3c
/*  f0cd080:	27a70038 */ 	addiu	$a3,$sp,0x38
/*  f0cd084:	c5c40008 */ 	lwc1	$f4,0x8($t6)
/*  f0cd088:	e7a40050 */ 	swc1	$f4,0x50($sp)
/*  f0cd08c:	8c4f00bc */ 	lw	$t7,0xbc($v0)
/*  f0cd090:	c5e6000c */ 	lwc1	$f6,0xc($t7)
/*  f0cd094:	460c3200 */ 	add.s	$f8,$f6,$f12
/*  f0cd098:	e7a80054 */ 	swc1	$f8,0x54($sp)
/*  f0cd09c:	8c5800bc */ 	lw	$t8,0xbc($v0)
/*  f0cd0a0:	c70a0010 */ 	lwc1	$f10,0x10($t8)
/*  f0cd0a4:	e7aa0058 */ 	swc1	$f10,0x58($sp)
/*  f0cd0a8:	0fc3082e */ 	jal	propPlayerGetBbox
/*  f0cd0ac:	8c4400bc */ 	lw	$a0,0xbc($v0)
/*  f0cd0b0:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0cd0b4:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f0cd0b8:	27a70040 */ 	addiu	$a3,$sp,0x40
/*  f0cd0bc:	8f2200bc */ 	lw	$v0,0xbc($t9)
/*  f0cd0c0:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0cd0c4:	0fc1979d */ 	jal	func0f065e74
/*  f0cd0c8:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f0cd0cc:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f0cd0d0:	27a50050 */ 	addiu	$a1,$sp,0x50
/*  f0cd0d4:	0fc32de7 */ 	jal	func0f0cb79c
/*  f0cd0d8:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f0cd0dc:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0cd0e0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cd0e4:	0fc1905e */ 	jal	func0f064178
/*  f0cd0e8:	8d0400bc */ 	lw	$a0,0xbc($t0)
/*  f0cd0ec:	3c017f1b */ 	lui	$at,%hi(var7f1ad994)
/*  f0cd0f0:	c432d994 */ 	lwc1	$f18,%lo(var7f1ad994)($at)
/*  f0cd0f4:	c7b00038 */ 	lwc1	$f16,0x38($sp)
/*  f0cd0f8:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0cd0fc:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0cd100:	46128101 */ 	sub.s	$f4,$f16,$f18
/*  f0cd104:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0cd108:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*  f0cd10c:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f0cd110:	e7a40038 */ 	swc1	$f4,0x38($sp)
/*  f0cd114:	8d4b00bc */ 	lw	$t3,0xbc($t2)
/*  f0cd118:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f0cd11c:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f0cd120:	c560000c */ 	lwc1	$f0,0xc($t3)
/*  f0cd124:	2407003f */ 	addiu	$a3,$zero,0x3f
/*  f0cd128:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0cd12c:	46002281 */ 	sub.s	$f10,$f4,$f0
/*  f0cd130:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f0cd134:	0c00a9a1 */ 	jal	func0002a684
/*  f0cd138:	e7aa0018 */ 	swc1	$f10,0x18($sp)
/*  f0cd13c:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0cd140:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f0cd144:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0cd148:	0fc1905e */ 	jal	func0f064178
/*  f0cd14c:	8d8400bc */ 	lw	$a0,0xbc($t4)
/*  f0cd150:	8fad005c */ 	lw	$t5,0x5c($sp)
/*  f0cd154:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cd158:	55a1000e */ 	bnel	$t5,$at,.L0f0cd194
/*  f0cd15c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0cd160:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0cd164:	c7b00054 */ 	lwc1	$f16,0x54($sp)
/*  f0cd168:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f0cd16c:	e5f0000c */ 	swc1	$f16,0xc($t7)
/*  f0cd170:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cd174:	0fc19711 */ 	jal	func0f065c44
/*  f0cd178:	8f0400bc */ 	lw	$a0,0xbc($t8)
/*  f0cd17c:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0cd180:	27a40040 */ 	addiu	$a0,$sp,0x40
/*  f0cd184:	8f2500bc */ 	lw	$a1,0xbc($t9)
/*  f0cd188:	0fc195e9 */ 	jal	func0f0657a4
/*  f0cd18c:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f0cd190:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0cd194:
/*  f0cd194:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*  f0cd198:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0cd19c:	03e00008 */ 	jr	$ra
/*  f0cd1a0:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f0cd1a4
/*  f0cd1a4:	27bdff10 */ 	addiu	$sp,$sp,-240
/*  f0cd1a8:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0cd1ac:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f0cd1b0:	3c018007 */ 	lui	$at,0x8007
/*  f0cd1b4:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f0cd1b8:	ac200e80 */ 	sw	$zero,0xe80($at)
/*  f0cd1bc:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0cd1c0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0cd1c4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0cd1c8:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f0cd1cc:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f0cd1d0:	afa400f0 */ 	sw	$a0,0xf0($sp)
/*  f0cd1d4:	afa500f4 */ 	sw	$a1,0xf4($sp)
/*  f0cd1d8:	afa600f8 */ 	sw	$a2,0xf8($sp)
/*  f0cd1dc:	afae00ec */ 	sw	$t6,0xec($sp)
/*  f0cd1e0:	afa000c8 */ 	sw	$zero,0xc8($sp)
/*  f0cd1e4:	27a600c4 */ 	addiu	$a2,$sp,0xc4
/*  f0cd1e8:	27a500bc */ 	addiu	$a1,$sp,0xbc
/*  f0cd1ec:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f0cd1f0:	0fc3082e */ 	jal	propPlayerGetBbox
/*  f0cd1f4:	8de400bc */ 	lw	$a0,0xbc($t7)
/*  f0cd1f8:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cd1fc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cd200:	0fc1905e */ 	jal	func0f064178
/*  f0cd204:	8f0400bc */ 	lw	$a0,0xbc($t8)
/*  f0cd208:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0cd20c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cd210:	0fc1905e */ 	jal	func0f064178
/*  f0cd214:	8f241b5c */ 	lw	$a0,0x1b5c($t9)
/*  f0cd218:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0cd21c:	8fa300f0 */ 	lw	$v1,0xf0($sp)
/*  f0cd220:	4480a000 */ 	mtc1	$zero,$f20
/*  f0cd224:	8d0900bc */ 	lw	$t1,0xbc($t0)
/*  f0cd228:	c5240008 */ 	lwc1	$f4,0x8($t1)
/*  f0cd22c:	e7a400dc */ 	swc1	$f4,0xdc($sp)
/*  f0cd230:	8d0a00bc */ 	lw	$t2,0xbc($t0)
/*  f0cd234:	c546000c */ 	lwc1	$f6,0xc($t2)
/*  f0cd238:	e7a600e0 */ 	swc1	$f6,0xe0($sp)
/*  f0cd23c:	8d0b00bc */ 	lw	$t3,0xbc($t0)
/*  f0cd240:	c7a600dc */ 	lwc1	$f6,0xdc($sp)
/*  f0cd244:	c5680010 */ 	lwc1	$f8,0x10($t3)
/*  f0cd248:	e7a800e4 */ 	swc1	$f8,0xe4($sp)
/*  f0cd24c:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f0cd250:	4600a032 */ 	c.eq.s	$f20,$f0
/*  f0cd254:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd258:	4502000c */ 	bc1fl	.L0f0cd28c
/*  f0cd25c:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f0cd260:	c46a0004 */ 	lwc1	$f10,0x4($v1)
/*  f0cd264:	460aa032 */ 	c.eq.s	$f20,$f10
/*  f0cd268:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd26c:	45020007 */ 	bc1fl	.L0f0cd28c
/*  f0cd270:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f0cd274:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f0cd278:	4604a032 */ 	c.eq.s	$f20,$f4
/*  f0cd27c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd280:	45030047 */ 	bc1tl	.L0f0cd3a0
/*  f0cd284:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0cd288:	46003200 */ 	add.s	$f8,$f6,$f0
.L0f0cd28c:
/*  f0cd28c:	c7aa00e0 */ 	lwc1	$f10,0xe0($sp)
/*  f0cd290:	27a600dc */ 	addiu	$a2,$sp,0xdc
/*  f0cd294:	27a700cc */ 	addiu	$a3,$sp,0xcc
/*  f0cd298:	e7a800dc */ 	swc1	$f8,0xdc($sp)
/*  f0cd29c:	c4640004 */ 	lwc1	$f4,0x4($v1)
/*  f0cd2a0:	c7a800e4 */ 	lwc1	$f8,0xe4($sp)
/*  f0cd2a4:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0cd2a8:	e7a600e0 */ 	swc1	$f6,0xe0($sp)
/*  f0cd2ac:	c46a0008 */ 	lwc1	$f10,0x8($v1)
/*  f0cd2b0:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0cd2b4:	e7a400e4 */ 	swc1	$f4,0xe4($sp)
/*  f0cd2b8:	8d0200bc */ 	lw	$v0,0xbc($t0)
/*  f0cd2bc:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0cd2c0:	0fc1979d */ 	jal	func0f065e74
/*  f0cd2c4:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f0cd2c8:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f0cd2cc:	27a500dc */ 	addiu	$a1,$sp,0xdc
/*  f0cd2d0:	0fc32de7 */ 	jal	func0f0cb79c
/*  f0cd2d4:	27a600cc */ 	addiu	$a2,$sp,0xcc
/*  f0cd2d8:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0cd2dc:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0cd2e0:	afac00c8 */ 	sw	$t4,0xc8($sp)
/*  f0cd2e4:	8da200bc */ 	lw	$v0,0xbc($t5)
/*  f0cd2e8:	240e003f */ 	addiu	$t6,$zero,0x3f
/*  f0cd2ec:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0cd2f0:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0cd2f4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0cd2f8:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f0cd2fc:	c7a600c4 */ 	lwc1	$f6,0xc4($sp)
/*  f0cd300:	c7aa00c0 */ 	lwc1	$f10,0xc0($sp)
/*  f0cd304:	27a600dc */ 	addiu	$a2,$sp,0xdc
/*  f0cd308:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0cd30c:	27a700cc */ 	addiu	$a3,$sp,0xcc
/*  f0cd310:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0cd314:	46005101 */ 	sub.s	$f4,$f10,$f0
/*  f0cd318:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*  f0cd31c:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f0cd320:	0c00b62e */ 	jal	func0002d8b8
/*  f0cd324:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f0cd328:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cd32c:	14410014 */ 	bne	$v0,$at,.L0f0cd380
/*  f0cd330:	afa200ec */ 	sw	$v0,0xec($sp)
/*  f0cd334:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cd338:	2419003f */ 	addiu	$t9,$zero,0x3f
/*  f0cd33c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0cd340:	8f0200bc */ 	lw	$v0,0xbc($t8)
/*  f0cd344:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0cd348:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0cd34c:	c440000c */ 	lwc1	$f0,0xc($v0)
/*  f0cd350:	c7a600c4 */ 	lwc1	$f6,0xc4($sp)
/*  f0cd354:	c7aa00c0 */ 	lwc1	$f10,0xc0($sp)
/*  f0cd358:	27a500dc */ 	addiu	$a1,$sp,0xdc
/*  f0cd35c:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0cd360:	8fa600bc */ 	lw	$a2,0xbc($sp)
/*  f0cd364:	27a700cc */ 	addiu	$a3,$sp,0xcc
/*  f0cd368:	46005101 */ 	sub.s	$f4,$f10,$f0
/*  f0cd36c:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*  f0cd370:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0cd374:	0c00a9bf */ 	jal	func0002a6fc
/*  f0cd378:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f0cd37c:	afa200ec */ 	sw	$v0,0xec($sp)
.L0f0cd380:
/*  f0cd380:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cd384:	50410006 */ 	beql	$v0,$at,.L0f0cd3a0
/*  f0cd388:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0cd38c:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0cd390:	3c01800a */ 	lui	$at,0x800a
/*  f0cd394:	8d4b00bc */ 	lw	$t3,0xbc($t2)
/*  f0cd398:	ac2bde70 */ 	sw	$t3,-0x2190($at)
/*  f0cd39c:	8e0c0284 */ 	lw	$t4,0x284($s0)
.L0f0cd3a0:
/*  f0cd3a0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0cd3a4:	0fc1905e */ 	jal	func0f064178
/*  f0cd3a8:	8d841b5c */ 	lw	$a0,0x1b5c($t4)
/*  f0cd3ac:	8fad00ec */ 	lw	$t5,0xec($sp)
/*  f0cd3b0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cd3b4:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
/*  f0cd3b8:	55a1010c */ 	bnel	$t5,$at,.L0f0cd7ec
/*  f0cd3bc:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0cd3c0:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0cd3c4:	46003387 */ 	neg.s	$f14,$f6
/*  f0cd3c8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0cd3cc:	e7ae004c */ 	swc1	$f14,0x4c($sp)
/*  f0cd3d0:	8d0f1a1c */ 	lw	$t7,0x1a1c($t0)
/*  f0cd3d4:	8d0e1b5c */ 	lw	$t6,0x1b5c($t0)
/*  f0cd3d8:	3c014120 */ 	lui	$at,0x4120
/*  f0cd3dc:	11e0005d */ 	beqz	$t7,.L0f0cd554
/*  f0cd3e0:	8dc50004 */ 	lw	$a1,0x4($t6)
/*  f0cd3e4:	44811000 */ 	mtc1	$at,$f2
/*  f0cd3e8:	c50a0148 */ 	lwc1	$f10,0x148($t0)
/*  f0cd3ec:	3c017f1b */ 	lui	$at,%hi(var7f1ad998)
/*  f0cd3f0:	c426d998 */ 	lwc1	$f6,%lo(var7f1ad998)($at)
/*  f0cd3f4:	46005107 */ 	neg.s	$f4,$f10
/*  f0cd3f8:	3c014060 */ 	lui	$at,0x4060
/*  f0cd3fc:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0cd400:	44815000 */ 	mtc1	$at,$f10
/*  f0cd404:	3c0140c0 */ 	lui	$at,0x40c0
/*  f0cd408:	44812000 */ 	mtc1	$at,$f4
/*  f0cd40c:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0cd410:	44813000 */ 	mtc1	$at,$f6
/*  f0cd414:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0cd418:	460a4002 */ 	mul.s	$f0,$f8,$f10
/*  f0cd41c:	44815000 */ 	mtc1	$at,$f10
/*  f0cd420:	8e030034 */ 	lw	$v1,0x34($s0)
/*  f0cd424:	3c017f1b */ 	lui	$at,%hi(var7f1ad99c)
/*  f0cd428:	00001025 */ 	or	$v0,$zero,$zero
/*  f0cd42c:	46040402 */ 	mul.s	$f16,$f0,$f4
/*  f0cd430:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd434:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0cd438:	c5060168 */ 	lwc1	$f6,0x168($t0)
/*  f0cd43c:	e7b4008c */ 	swc1	$f20,0x8c($sp)
/*  f0cd440:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0cd444:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd448:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f0cd44c:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0cd450:	e7aa0088 */ 	swc1	$f10,0x88($sp)
/*  f0cd454:	c5060170 */ 	lwc1	$f6,0x170($t0)
/*  f0cd458:	46003107 */ 	neg.s	$f4,$f6
/*  f0cd45c:	c5061c58 */ 	lwc1	$f6,0x1c58($t0)
/*  f0cd460:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f0cd464:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0cd468:	e7a40090 */ 	swc1	$f4,0x90($sp)
/*  f0cd46c:	c5081a3c */ 	lwc1	$f8,0x1a3c($t0)
/*  f0cd470:	c5161a38 */ 	lwc1	$f22,0x1a38($t0)
/*  f0cd474:	e7a800ac */ 	swc1	$f8,0xac($sp)
/*  f0cd478:	c5061a40 */ 	lwc1	$f6,0x1a40($t0)
/*  f0cd47c:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f0cd480:	e7a600b0 */ 	swc1	$f6,0xb0($sp)
/*  f0cd484:	c5081a44 */ 	lwc1	$f8,0x1a44($t0)
/*  f0cd488:	18600024 */ 	blez	$v1,.L0f0cd51c
/*  f0cd48c:	e7a800b4 */ 	swc1	$f8,0xb4($sp)
/*  f0cd490:	46002306 */ 	mov.s	$f12,$f4
/*  f0cd494:	46005086 */ 	mov.s	$f2,$f10
/*  f0cd498:	c420d99c */ 	lwc1	$f0,%lo(var7f1ad99c)($at)
/*  f0cd49c:	c7aa00b0 */ 	lwc1	$f10,0xb0($sp)
/*  f0cd4a0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0cd4a4:	0043082a */ 	slt	$at,$v0,$v1
/*  f0cd4a8:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0cd4ac:	10200011 */ 	beqz	$at,.L0f0cd4f4
/*  f0cd4b0:	c7aa00b4 */ 	lwc1	$f10,0xb4($sp)
.L0f0cd4b4:
/*  f0cd4b4:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f0cd4b8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0cd4bc:	0043082a */ 	slt	$at,$v0,$v1
/*  f0cd4c0:	46160102 */ 	mul.s	$f4,$f0,$f22
/*  f0cd4c4:	4608a280 */ 	add.s	$f10,$f20,$f8
/*  f0cd4c8:	46120202 */ 	mul.s	$f8,$f0,$f18
/*  f0cd4cc:	46066180 */ 	add.s	$f6,$f12,$f6
/*  f0cd4d0:	e7aa00b0 */ 	swc1	$f10,0xb0($sp)
/*  f0cd4d4:	c7aa00b0 */ 	lwc1	$f10,0xb0($sp)
/*  f0cd4d8:	46102580 */ 	add.s	$f22,$f4,$f16
/*  f0cd4dc:	e7a600b4 */ 	swc1	$f6,0xb4($sp)
/*  f0cd4e0:	46081480 */ 	add.s	$f18,$f2,$f8
/*  f0cd4e4:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0cd4e8:	c7aa00b4 */ 	lwc1	$f10,0xb4($sp)
/*  f0cd4ec:	1420fff1 */ 	bnez	$at,.L0f0cd4b4
/*  f0cd4f0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cd4f4:
/*  f0cd4f4:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f0cd4f8:	4608a280 */ 	add.s	$f10,$f20,$f8
/*  f0cd4fc:	46160102 */ 	mul.s	$f4,$f0,$f22
/*  f0cd500:	e7aa00b0 */ 	swc1	$f10,0xb0($sp)
/*  f0cd504:	46120202 */ 	mul.s	$f8,$f0,$f18
/*  f0cd508:	46066180 */ 	add.s	$f6,$f12,$f6
/*  f0cd50c:	46102580 */ 	add.s	$f22,$f4,$f16
/*  f0cd510:	e7a600b4 */ 	swc1	$f6,0xb4($sp)
/*  f0cd514:	46081480 */ 	add.s	$f18,$f2,$f8
/*  f0cd518:	e7b200ac */ 	swc1	$f18,0xac($sp)
.L0f0cd51c:
/*  f0cd51c:	3c017f1b */ 	lui	$at,%hi(var7f1ad9a0)
/*  f0cd520:	c420d9a0 */ 	lwc1	$f0,%lo(var7f1ad9a0)($at)
/*  f0cd524:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f0cd528:	c7a400b0 */ 	lwc1	$f4,0xb0($sp)
/*  f0cd52c:	4600b182 */ 	mul.s	$f6,$f22,$f0
/*  f0cd530:	e7a600a8 */ 	swc1	$f6,0xa8($sp)
/*  f0cd534:	46009202 */ 	mul.s	$f8,$f18,$f0
/*  f0cd538:	c7a600b4 */ 	lwc1	$f6,0xb4($sp)
/*  f0cd53c:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0cd540:	e7a8009c */ 	swc1	$f8,0x9c($sp)
/*  f0cd544:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0cd548:	e7aa00a0 */ 	swc1	$f10,0xa0($sp)
/*  f0cd54c:	1000000a */ 	beqz	$zero,.L0f0cd578
/*  f0cd550:	e7a800a4 */ 	swc1	$f8,0xa4($sp)
.L0f0cd554:
/*  f0cd554:	c5041a20 */ 	lwc1	$f4,0x1a20($t0)
/*  f0cd558:	c7b600b8 */ 	lwc1	$f22,0xb8($sp)
/*  f0cd55c:	e7a400a8 */ 	swc1	$f4,0xa8($sp)
/*  f0cd560:	c50a1a2c */ 	lwc1	$f10,0x1a2c($t0)
/*  f0cd564:	e7aa009c */ 	swc1	$f10,0x9c($sp)
/*  f0cd568:	c5061a30 */ 	lwc1	$f6,0x1a30($t0)
/*  f0cd56c:	e7a600a0 */ 	swc1	$f6,0xa0($sp)
/*  f0cd570:	c5081a34 */ 	lwc1	$f8,0x1a34($t0)
/*  f0cd574:	e7a800a4 */ 	swc1	$f8,0xa4($sp)
.L0f0cd578:
/*  f0cd578:	8fb800f0 */ 	lw	$t8,0xf0($sp)
/*  f0cd57c:	24010035 */ 	addiu	$at,$zero,0x35
/*  f0cd580:	c7040000 */ 	lwc1	$f4,0x0($t8)
/*  f0cd584:	e7a4007c */ 	swc1	$f4,0x7c($sp)
/*  f0cd588:	c70a0004 */ 	lwc1	$f10,0x4($t8)
/*  f0cd58c:	e7aa0080 */ 	swc1	$f10,0x80($sp)
/*  f0cd590:	c7060008 */ 	lwc1	$f6,0x8($t8)
/*  f0cd594:	e7a60084 */ 	swc1	$f6,0x84($sp)
/*  f0cd598:	90a20003 */ 	lbu	$v0,0x3($a1)
/*  f0cd59c:	54410006 */ 	bnel	$v0,$at,.L0f0cd5b8
/*  f0cd5a0:	24010033 */ 	addiu	$at,$zero,0x33
/*  f0cd5a4:	8d191b5c */ 	lw	$t9,0x1b5c($t0)
/*  f0cd5a8:	8f220004 */ 	lw	$v0,0x4($t9)
/*  f0cd5ac:	10000007 */ 	beqz	$zero,.L0f0cd5cc
/*  f0cd5b0:	2444005c */ 	addiu	$a0,$v0,0x5c
/*  f0cd5b4:	24010033 */ 	addiu	$at,$zero,0x33
.L0f0cd5b8:
/*  f0cd5b8:	14410004 */ 	bne	$v0,$at,.L0f0cd5cc
/*  f0cd5bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd5c0:	8d091b5c */ 	lw	$t1,0x1b5c($t0)
/*  f0cd5c4:	8d220004 */ 	lw	$v0,0x4($t1)
/*  f0cd5c8:	2444005c */ 	addiu	$a0,$v0,0x5c
.L0f0cd5cc:
/*  f0cd5cc:	10800026 */ 	beqz	$a0,.L0f0cd668
/*  f0cd5d0:	3c017f1b */ 	lui	$at,%hi(var7f1ad9a4)
/*  f0cd5d4:	c420d9a4 */ 	lwc1	$f0,%lo(var7f1ad9a4)($at)
/*  f0cd5d8:	3c017f1b */ 	lui	$at,%hi(var7f1ad9a8)
/*  f0cd5dc:	c422d9a8 */ 	lwc1	$f2,%lo(var7f1ad9a8)($at)
/*  f0cd5e0:	c5080144 */ 	lwc1	$f8,0x144($t0)
/*  f0cd5e4:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0cd5e8:	44818000 */ 	mtc1	$at,$f16
/*  f0cd5ec:	46024102 */ 	mul.s	$f4,$f8,$f2
/*  f0cd5f0:	c7a8004c */ 	lwc1	$f8,0x4c($sp)
/*  f0cd5f4:	3c017f1b */ 	lui	$at,%hi(var7f1ad9ac)
/*  f0cd5f8:	46102283 */ 	div.s	$f10,$f4,$f16
/*  f0cd5fc:	460a1181 */ 	sub.s	$f6,$f2,$f10
/*  f0cd600:	c50a1a0c */ 	lwc1	$f10,0x1a0c($t0)
/*  f0cd604:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f0cd608:	c4880010 */ 	lwc1	$f8,0x10($a0)
/*  f0cd60c:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0cd610:	c7aa00a8 */ 	lwc1	$f10,0xa8($sp)
/*  f0cd614:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f0cd618:	460a2380 */ 	add.s	$f14,$f4,$f10
/*  f0cd61c:	460e003e */ 	c.le.s	$f0,$f14
/*  f0cd620:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd624:	45000006 */ 	bc1f	.L0f0cd640
/*  f0cd628:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd62c:	46027381 */ 	sub.s	$f14,$f14,$f2
.L0f0cd630:
/*  f0cd630:	460e003e */ 	c.le.s	$f0,$f14
/*  f0cd634:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd638:	4503fffd */ 	bc1tl	.L0f0cd630
/*  f0cd63c:	46027381 */ 	sub.s	$f14,$f14,$f2
.L0f0cd640:
/*  f0cd640:	c420d9ac */ 	lwc1	$f0,%lo(var7f1ad9ac)($at)
/*  f0cd644:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0cd648:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd64c:	45020007 */ 	bc1fl	.L0f0cd66c
/*  f0cd650:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
/*  f0cd654:	46027380 */ 	add.s	$f14,$f14,$f2
.L0f0cd658:
/*  f0cd658:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0cd65c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd660:	4503fffd */ 	bc1tl	.L0f0cd658
/*  f0cd664:	46027380 */ 	add.s	$f14,$f14,$f2
.L0f0cd668:
/*  f0cd668:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
.L0f0cd66c:
/*  f0cd66c:	3c017f1b */ 	lui	$at,%hi(var7f1ad9b0)
/*  f0cd670:	c422d9b0 */ 	lwc1	$f2,%lo(var7f1ad9b0)($at)
/*  f0cd674:	46143032 */ 	c.eq.s	$f6,$f20
/*  f0cd678:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0cd67c:	44818000 */ 	mtc1	$at,$f16
/*  f0cd680:	45020005 */ 	bc1fl	.L0f0cd698
/*  f0cd684:	c5080144 */ 	lwc1	$f8,0x144($t0)
/*  f0cd688:	8d0a1a1c */ 	lw	$t2,0x1a1c($t0)
/*  f0cd68c:	51400034 */ 	beqzl	$t2,.L0f0cd760
/*  f0cd690:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0cd694:	c5080144 */ 	lwc1	$f8,0x144($t0)
.L0f0cd698:
/*  f0cd698:	46024102 */ 	mul.s	$f4,$f8,$f2
/*  f0cd69c:	c7a800f4 */ 	lwc1	$f8,0xf4($sp)
/*  f0cd6a0:	46102283 */ 	div.s	$f10,$f4,$f16
/*  f0cd6a4:	460a1181 */ 	sub.s	$f6,$f2,$f10
/*  f0cd6a8:	46083301 */ 	sub.s	$f12,$f6,$f8
/*  f0cd6ac:	460c103e */ 	c.le.s	$f2,$f12
/*  f0cd6b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd6b4:	45020004 */ 	bc1fl	.L0f0cd6c8
/*  f0cd6b8:	4614603c */ 	c.lt.s	$f12,$f20
/*  f0cd6bc:	10000006 */ 	beqz	$zero,.L0f0cd6d8
/*  f0cd6c0:	46026301 */ 	sub.s	$f12,$f12,$f2
/*  f0cd6c4:	4614603c */ 	c.lt.s	$f12,$f20
.L0f0cd6c8:
/*  f0cd6c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd6cc:	45020003 */ 	bc1fl	.L0f0cd6dc
/*  f0cd6d0:	e7ac0074 */ 	swc1	$f12,0x74($sp)
/*  f0cd6d4:	46026300 */ 	add.s	$f12,$f12,$f2
.L0f0cd6d8:
/*  f0cd6d8:	e7ac0074 */ 	swc1	$f12,0x74($sp)
.L0f0cd6dc:
/*  f0cd6dc:	0c0068f4 */ 	jal	func0001a3d0
/*  f0cd6e0:	e7ae0078 */ 	swc1	$f14,0x78($sp)
/*  f0cd6e4:	c7ac0074 */ 	lwc1	$f12,0x74($sp)
/*  f0cd6e8:	0c0068f7 */ 	jal	func0001a3dc
/*  f0cd6ec:	e7a00070 */ 	swc1	$f0,0x70($sp)
/*  f0cd6f0:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0cd6f4:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f0cd6f8:	c7a600a4 */ 	lwc1	$f6,0xa4($sp)
/*  f0cd6fc:	c50a1a10 */ 	lwc1	$f10,0x1a10($t0)
/*  f0cd700:	c5081a18 */ 	lwc1	$f8,0x1a18($t0)
/*  f0cd704:	8d0b1b5c */ 	lw	$t3,0x1b5c($t0)
/*  f0cd708:	460a2300 */ 	add.s	$f12,$f4,$f10
/*  f0cd70c:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*  f0cd710:	c7a400dc */ 	lwc1	$f4,0xdc($sp)
/*  f0cd714:	46083480 */ 	add.s	$f18,$f6,$f8
/*  f0cd718:	460a6182 */ 	mul.s	$f6,$f12,$f10
/*  f0cd71c:	c7ae0078 */ 	lwc1	$f14,0x78($sp)
/*  f0cd720:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0cd724:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0cd728:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0cd72c:	c5680008 */ 	lwc1	$f8,0x8($t3)
/*  f0cd730:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f0cd734:	460a9202 */ 	mul.s	$f8,$f18,$f10
/*  f0cd738:	c7a600e4 */ 	lwc1	$f6,0xe4($sp)
/*  f0cd73c:	46006282 */ 	mul.s	$f10,$f12,$f0
/*  f0cd740:	e7a4007c */ 	swc1	$f4,0x7c($sp)
/*  f0cd744:	8d0c1b5c */ 	lw	$t4,0x1b5c($t0)
/*  f0cd748:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f0cd74c:	c5880010 */ 	lwc1	$f8,0x10($t4)
/*  f0cd750:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f0cd754:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f0cd758:	e7a40084 */ 	swc1	$f4,0x84($sp)
/*  f0cd75c:	240d0001 */ 	addiu	$t5,$zero,0x1
.L0f0cd760:
/*  f0cd760:	3c018007 */ 	lui	$at,0x8007
/*  f0cd764:	ac2d0e80 */ 	sw	$t5,0xe80($at)
/*  f0cd768:	8d0e1b5c */ 	lw	$t6,0x1b5c($t0)
/*  f0cd76c:	c7a6007c */ 	lwc1	$f6,0x7c($sp)
/*  f0cd770:	3c02800a */ 	lui	$v0,%hi(var8009de78)
/*  f0cd774:	c5ca0008 */ 	lwc1	$f10,0x8($t6)
/*  f0cd778:	2442de78 */ 	addiu	$v0,$v0,%lo(var8009de78)
/*  f0cd77c:	44067000 */ 	mfc1	$a2,$f14
/*  f0cd780:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0cd784:	c7aa0080 */ 	lwc1	$f10,0x80($sp)
/*  f0cd788:	27a5007c */ 	addiu	$a1,$sp,0x7c
/*  f0cd78c:	8fa700f8 */ 	lw	$a3,0xf8($sp)
/*  f0cd790:	e4480000 */ 	swc1	$f8,0x0($v0)
/*  f0cd794:	8d0f1b5c */ 	lw	$t7,0x1b5c($t0)
/*  f0cd798:	c5e4000c */ 	lwc1	$f4,0xc($t7)
/*  f0cd79c:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0cd7a0:	c7a40084 */ 	lwc1	$f4,0x84($sp)
/*  f0cd7a4:	e4460004 */ 	swc1	$f6,0x4($v0)
/*  f0cd7a8:	8d181b5c */ 	lw	$t8,0x1b5c($t0)
/*  f0cd7ac:	c7080010 */ 	lwc1	$f8,0x10($t8)
/*  f0cd7b0:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f0cd7b4:	e44a0008 */ 	swc1	$f10,0x8($v0)
/*  f0cd7b8:	8d191b5c */ 	lw	$t9,0x1b5c($t0)
/*  f0cd7bc:	0fc1c851 */ 	jal	func0f072144
/*  f0cd7c0:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f0cd7c4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cd7c8:	afa200ec */ 	sw	$v0,0xec($sp)
/*  f0cd7cc:	10410006 */ 	beq	$v0,$at,.L0f0cd7e8
/*  f0cd7d0:	e7b600b8 */ 	swc1	$f22,0xb8($sp)
/*  f0cd7d4:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0cd7d8:	3c01800a */ 	lui	$at,0x800a
/*  f0cd7dc:	8d2a1b5c */ 	lw	$t2,0x1b5c($t1)
/*  f0cd7e0:	e7b600b8 */ 	swc1	$f22,0xb8($sp)
/*  f0cd7e4:	ac2ade70 */ 	sw	$t2,-0x2190($at)
.L0f0cd7e8:
/*  f0cd7e8:	8e0b0284 */ 	lw	$t3,0x284($s0)
.L0f0cd7ec:
/*  f0cd7ec:	c7b600b8 */ 	lwc1	$f22,0xb8($sp)
/*  f0cd7f0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0cd7f4:	0fc1905e */ 	jal	func0f064178
/*  f0cd7f8:	8d6400bc */ 	lw	$a0,0xbc($t3)
/*  f0cd7fc:	3c017f1b */ 	lui	$at,%hi(var7f1ad9c4)
/*  f0cd800:	c422d9c4 */ 	lwc1	$f2,%lo(var7f1ad9c4)($at)
/*  f0cd804:	8fac00ec */ 	lw	$t4,0xec($sp)
/*  f0cd808:	3c0143b4 */ 	lui	$at,0x43b4
/*  f0cd80c:	44818000 */ 	mtc1	$at,$f16
/*  f0cd810:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cd814:	55810050 */ 	bnel	$t4,$at,.L0f0cd958
/*  f0cd818:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0cd81c:	8fad00f8 */ 	lw	$t5,0xf8($sp)
/*  f0cd820:	3c01800a */ 	lui	$at,0x800a
/*  f0cd824:	ac20de70 */ 	sw	$zero,-0x2190($at)
/*  f0cd828:	11a0004a */ 	beqz	$t5,.L0f0cd954
/*  f0cd82c:	c7a800f4 */ 	lwc1	$f8,0xf4($sp)
/*  f0cd830:	46104102 */ 	mul.s	$f4,$f8,$f16
/*  f0cd834:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0cd838:	c5060144 */ 	lwc1	$f6,0x144($t0)
/*  f0cd83c:	46022283 */ 	div.s	$f10,$f4,$f2
/*  f0cd840:	460a3000 */ 	add.s	$f0,$f6,$f10
/*  f0cd844:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0cd848:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd84c:	45020007 */ 	bc1fl	.L0f0cd86c
/*  f0cd850:	4600803e */ 	c.le.s	$f16,$f0
/*  f0cd854:	46100000 */ 	add.s	$f0,$f0,$f16
.L0f0cd858:
/*  f0cd858:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0cd85c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd860:	4503fffd */ 	bc1tl	.L0f0cd858
/*  f0cd864:	46100000 */ 	add.s	$f0,$f0,$f16
/*  f0cd868:	4600803e */ 	c.le.s	$f16,$f0
.L0f0cd86c:
/*  f0cd86c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd870:	45020007 */ 	bc1fl	.L0f0cd890
/*  f0cd874:	e5000144 */ 	swc1	$f0,0x144($t0)
/*  f0cd878:	46100001 */ 	sub.s	$f0,$f0,$f16
.L0f0cd87c:
/*  f0cd87c:	4600803e */ 	c.le.s	$f16,$f0
/*  f0cd880:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd884:	4503fffd */ 	bc1tl	.L0f0cd87c
/*  f0cd888:	46100001 */ 	sub.s	$f0,$f0,$f16
/*  f0cd88c:	e5000144 */ 	swc1	$f0,0x144($t0)
.L0f0cd890:
/*  f0cd890:	8e0e0284 */ 	lw	$t6,0x284($s0)
/*  f0cd894:	c7a800dc */ 	lwc1	$f8,0xdc($sp)
/*  f0cd898:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f0cd89c:	e5e80008 */ 	swc1	$f8,0x8($t7)
/*  f0cd8a0:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cd8a4:	c7a400e0 */ 	lwc1	$f4,0xe0($sp)
/*  f0cd8a8:	8f1900bc */ 	lw	$t9,0xbc($t8)
/*  f0cd8ac:	e724000c */ 	swc1	$f4,0xc($t9)
/*  f0cd8b0:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0cd8b4:	c7a600e4 */ 	lwc1	$f6,0xe4($sp)
/*  f0cd8b8:	8d2a00bc */ 	lw	$t2,0xbc($t1)
/*  f0cd8bc:	e5460010 */ 	swc1	$f6,0x10($t2)
/*  f0cd8c0:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*  f0cd8c4:	5160000a */ 	beqzl	$t3,.L0f0cd8f0
/*  f0cd8c8:	8e080284 */ 	lw	$t0,0x284($s0)
/*  f0cd8cc:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0cd8d0:	0fc19711 */ 	jal	func0f065c44
/*  f0cd8d4:	8d8400bc */ 	lw	$a0,0xbc($t4)
/*  f0cd8d8:	8e0d0284 */ 	lw	$t5,0x284($s0)
/*  f0cd8dc:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f0cd8e0:	8da500bc */ 	lw	$a1,0xbc($t5)
/*  f0cd8e4:	0fc195e9 */ 	jal	func0f0657a4
/*  f0cd8e8:	24a50028 */ 	addiu	$a1,$a1,0x28
/*  f0cd8ec:	8e080284 */ 	lw	$t0,0x284($s0)
.L0f0cd8f0:
/*  f0cd8f0:	c7aa00a8 */ 	lwc1	$f10,0xa8($sp)
/*  f0cd8f4:	8d0e1a1c */ 	lw	$t6,0x1a1c($t0)
/*  f0cd8f8:	51c00017 */ 	beqzl	$t6,.L0f0cd958
/*  f0cd8fc:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0cd900:	e50a1a20 */ 	swc1	$f10,0x1a20($t0)
/*  f0cd904:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f0cd908:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f0cd90c:	e5e81a2c */ 	swc1	$f8,0x1a2c($t7)
/*  f0cd910:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f0cd914:	c7a400a0 */ 	lwc1	$f4,0xa0($sp)
/*  f0cd918:	e7041a30 */ 	swc1	$f4,0x1a30($t8)
/*  f0cd91c:	8e190284 */ 	lw	$t9,0x284($s0)
/*  f0cd920:	c7a600a4 */ 	lwc1	$f6,0xa4($sp)
/*  f0cd924:	e7261a34 */ 	swc1	$f6,0x1a34($t9)
/*  f0cd928:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f0cd92c:	e5361a38 */ 	swc1	$f22,0x1a38($t1)
/*  f0cd930:	8e0a0284 */ 	lw	$t2,0x284($s0)
/*  f0cd934:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*  f0cd938:	e54a1a3c */ 	swc1	$f10,0x1a3c($t2)
/*  f0cd93c:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f0cd940:	c7a800b0 */ 	lwc1	$f8,0xb0($sp)
/*  f0cd944:	e5681a40 */ 	swc1	$f8,0x1a40($t3)
/*  f0cd948:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f0cd94c:	c7a400b4 */ 	lwc1	$f4,0xb4($sp)
/*  f0cd950:	e5841a44 */ 	swc1	$f4,0x1a44($t4)
.L0f0cd954:
/*  f0cd954:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f0cd958:
/*  f0cd958:	8fa200ec */ 	lw	$v0,0xec($sp)
/*  f0cd95c:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f0cd960:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f0cd964:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0cd968:	03e00008 */ 	jr	$ra
/*  f0cd96c:	27bd00f0 */ 	addiu	$sp,$sp,0xf0
);

GLOBAL_ASM(
glabel func0f0cd970
/*  f0cd970:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0cd974:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0cd978:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0cd97c:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f0cd980:	0fc33469 */ 	jal	func0f0cd1a4
/*  f0cd984:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0cd988:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cd98c:	10410058 */ 	beq	$v0,$at,.L0f0cdaf0
/*  f0cd990:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f0cd994:	0c0093ac */ 	jal	func00024eb0
/*  f0cd998:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cd99c:	10400054 */ 	beqz	$v0,.L0f0cdaf0
/*  f0cd9a0:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0cd9a4:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0cd9a8:	8c8e0034 */ 	lw	$t6,0x34($a0)
/*  f0cd9ac:	59c00051 */ 	blezl	$t6,.L0f0cdaf4
/*  f0cd9b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cd9b4:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f0cd9b8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0cd9bc:	1061004c */ 	beq	$v1,$at,.L0f0cdaf0
/*  f0cd9c0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0cd9c4:	1061004a */ 	beq	$v1,$at,.L0f0cdaf0
/*  f0cd9c8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cd9cc:	54610049 */ 	bnel	$v1,$at,.L0f0cdaf4
/*  f0cd9d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cd9d4:	8c460004 */ 	lw	$a2,0x4($v0)
/*  f0cd9d8:	8cc30040 */ 	lw	$v1,0x40($a2)
/*  f0cd9dc:	00037940 */ 	sll	$t7,$v1,0x5
/*  f0cd9e0:	05e00043 */ 	bltz	$t7,.L0f0cdaf0
/*  f0cd9e4:	0003c100 */ 	sll	$t8,$v1,0x4
/*  f0cd9e8:	07020042 */ 	bltzl	$t8,.L0f0cdaf4
/*  f0cd9ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cd9f0:	8cd90010 */ 	lw	$t9,0x10($a2)
/*  f0cd9f4:	33280001 */ 	andi	$t0,$t9,0x1
/*  f0cd9f8:	5100003e */ 	beqzl	$t0,.L0f0cdaf4
/*  f0cd9fc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cda00:	8c890284 */ 	lw	$t1,0x284($a0)
/*  f0cda04:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0cda08:	ad200178 */ 	sw	$zero,0x178($t1)
/*  f0cda0c:	8cca0040 */ 	lw	$t2,0x40($a2)
/*  f0cda10:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f0cda14:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0cda18:	314b0080 */ 	andi	$t3,$t2,0x80
/*  f0cda1c:	11600007 */ 	beqz	$t3,.L0f0cda3c
/*  f0cda20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cda24:	8ccc0048 */ 	lw	$t4,0x48($a2)
/*  f0cda28:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f0cda2c:	31ae1000 */ 	andi	$t6,$t5,0x1000
/*  f0cda30:	11c00002 */ 	beqz	$t6,.L0f0cda3c
/*  f0cda34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cda38:	00001025 */ 	or	$v0,$zero,$zero
.L0f0cda3c:
/*  f0cda3c:	5040002d */ 	beqzl	$v0,.L0f0cdaf4
/*  f0cda40:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cda44:	0fc332fc */ 	jal	func0f0ccbf0
/*  f0cda48:	afa6002c */ 	sw	$a2,0x2c($sp)
/*  f0cda4c:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f0cda50:	8ccf0040 */ 	lw	$t7,0x40($a2)
/*  f0cda54:	31f80080 */ 	andi	$t8,$t7,0x80
/*  f0cda58:	53000026 */ 	beqzl	$t8,.L0f0cdaf4
/*  f0cda5c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cda60:	8cd90048 */ 	lw	$t9,0x48($a2)
/*  f0cda64:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0cda68:	27a50020 */ 	addiu	$a1,$sp,0x20
/*  f0cda6c:	8f280000 */ 	lw	$t0,0x0($t9)
/*  f0cda70:	31090800 */ 	andi	$t1,$t0,0x800
/*  f0cda74:	5120001f */ 	beqzl	$t1,.L0f0cdaf4
/*  f0cda78:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cda7c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0cda80:	0fc1cf1b */ 	jal	func0f073c6c
/*  f0cda84:	afa6002c */ 	sw	$a2,0x2c($sp)
/*  f0cda88:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f0cda8c:	8cca0040 */ 	lw	$t2,0x40($a2)
/*  f0cda90:	314b0080 */ 	andi	$t3,$t2,0x80
/*  f0cda94:	11600010 */ 	beqz	$t3,.L0f0cdad8
/*  f0cda98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cda9c:	8cc30048 */ 	lw	$v1,0x48($a2)
/*  f0cdaa0:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0cdaa4:	358d1000 */ 	ori	$t5,$t4,0x1000
/*  f0cdaa8:	10400006 */ 	beqz	$v0,.L0f0cdac4
/*  f0cdaac:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0cdab0:	8cc30048 */ 	lw	$v1,0x48($a2)
/*  f0cdab4:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0cdab8:	35cf2000 */ 	ori	$t7,$t6,0x2000
/*  f0cdabc:	10000006 */ 	beqz	$zero,.L0f0cdad8
/*  f0cdac0:	ac6f0000 */ 	sw	$t7,0x0($v1)
.L0f0cdac4:
/*  f0cdac4:	8cc30048 */ 	lw	$v1,0x48($a2)
/*  f0cdac8:	2401dfff */ 	addiu	$at,$zero,-8193
/*  f0cdacc:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0cdad0:	0301c824 */ 	and	$t9,$t8,$at
/*  f0cdad4:	ac790000 */ 	sw	$t9,0x0($v1)
.L0f0cdad8:
/*  f0cdad8:	10400005 */ 	beqz	$v0,.L0f0cdaf0
/*  f0cdadc:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0cdae0:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f0cdae4:	0fc33469 */ 	jal	func0f0cd1a4
/*  f0cdae8:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0cdaec:	afa20034 */ 	sw	$v0,0x34($sp)
.L0f0cdaf0:
/*  f0cdaf0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0cdaf4:
/*  f0cdaf4:	8fa20034 */ 	lw	$v0,0x34($sp)
/*  f0cdaf8:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0cdafc:	03e00008 */ 	jr	$ra
/*  f0cdb00:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0cdb04
/*  f0cdb04:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0cdb08:	3c0e8007 */ 	lui	$t6,%hi(var80070e9c)
/*  f0cdb0c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0cdb10:	25ce0e9c */ 	addiu	$t6,$t6,%lo(var80070e9c)
/*  f0cdb14:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f0cdb18:	27a4001c */ 	addiu	$a0,$sp,0x1c
/*  f0cdb1c:	3c09800a */ 	lui	$t1,0x800a
/*  f0cdb20:	ac810000 */ 	sw	$at,0x0($a0)
/*  f0cdb24:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f0cdb28:	00a03025 */ 	or	$a2,$a1,$zero
/*  f0cdb2c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0cdb30:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f0cdb34:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f0cdb38:	44056000 */ 	mfc1	$a1,$f12
/*  f0cdb3c:	ac810008 */ 	sw	$at,0x8($a0)
/*  f0cdb40:	8d29a244 */ 	lw	$t1,-0x5dbc($t1)
/*  f0cdb44:	0fc3365c */ 	jal	func0f0cd970
/*  f0cdb48:	ad281a1c */ 	sw	$t0,0x1a1c($t1)
/*  f0cdb4c:	3c0a800a */ 	lui	$t2,0x800a
/*  f0cdb50:	8d4aa244 */ 	lw	$t2,-0x5dbc($t2)
/*  f0cdb54:	ad401a1c */ 	sw	$zero,0x1a1c($t2)
/*  f0cdb58:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cdb5c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f0cdb60:	03e00008 */ 	jr	$ra
/*  f0cdb64:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0cdb68
/*  f0cdb68:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f0cdb6c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0cdb70:	44817000 */ 	mtc1	$at,$f14
/*  f0cdb74:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0cdb78:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f0cdb7c:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f0cdb80:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f0cdb84:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f0cdb88:	e7ac00b0 */ 	swc1	$f12,0xb0($sp)
/*  f0cdb8c:	24e7d958 */ 	addiu	$a3,$a3,-9896
/*  f0cdb90:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f0cdb94:	27a50098 */ 	addiu	$a1,$sp,0x98
/*  f0cdb98:	240602a6 */ 	addiu	$a2,$zero,0x2a6
/*  f0cdb9c:	0c009393 */ 	jal	func00024e4c
/*  f0cdba0:	e7ae0060 */ 	swc1	$f14,0x60($sp)
/*  f0cdba4:	c7ac00a4 */ 	lwc1	$f12,0xa4($sp)
/*  f0cdba8:	c7a40098 */ 	lwc1	$f4,0x98($sp)
/*  f0cdbac:	4480c000 */ 	mtc1	$zero,$f24
/*  f0cdbb0:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f0cdbb4:	460c2401 */ 	sub.s	$f16,$f4,$f12
/*  f0cdbb8:	c7a600a0 */ 	lwc1	$f6,0xa0($sp)
/*  f0cdbbc:	c7ae0060 */ 	lwc1	$f14,0x60($sp)
/*  f0cdbc0:	46188032 */ 	c.eq.s	$f16,$f24
/*  f0cdbc4:	46123001 */ 	sub.s	$f0,$f6,$f18
/*  f0cdbc8:	45000008 */ 	bc1f	.L0f0cdbec
/*  f0cdbcc:	46000086 */ 	mov.s	$f2,$f0
/*  f0cdbd0:	46180032 */ 	c.eq.s	$f0,$f24
/*  f0cdbd4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cdbd8:	45000004 */ 	bc1f	.L0f0cdbec
/*  f0cdbdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdbe0:	44811000 */ 	mtc1	$at,$f2
/*  f0cdbe4:	10000012 */ 	beqz	$zero,.L0f0cdc30
/*  f0cdbe8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cdbec:
/*  f0cdbec:	46108202 */ 	mul.s	$f8,$f16,$f16
/*  f0cdbf0:	e7a20078 */ 	swc1	$f2,0x78($sp)
/*  f0cdbf4:	e7ae0060 */ 	swc1	$f14,0x60($sp)
/*  f0cdbf8:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f0cdbfc:	e7b0007c */ 	swc1	$f16,0x7c($sp)
/*  f0cdc00:	0c012974 */ 	jal	sqrtf
/*  f0cdc04:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f0cdc08:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cdc0c:	44812000 */ 	mtc1	$at,$f4
/*  f0cdc10:	c7b0007c */ 	lwc1	$f16,0x7c($sp)
/*  f0cdc14:	c7a20078 */ 	lwc1	$f2,0x78($sp)
/*  f0cdc18:	46002303 */ 	div.s	$f12,$f4,$f0
/*  f0cdc1c:	c7ae0060 */ 	lwc1	$f14,0x60($sp)
/*  f0cdc20:	460c8402 */ 	mul.s	$f16,$f16,$f12
/*  f0cdc24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdc28:	460c1082 */ 	mul.s	$f2,$f2,$f12
/*  f0cdc2c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cdc30:
/*  f0cdc30:	3c0e800a */ 	lui	$t6,0x800a
/*  f0cdc34:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0cdc38:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f0cdc3c:	46008007 */ 	neg.s	$f0,$f16
/*  f0cdc40:	8dc200bc */ 	lw	$v0,0xbc($t6)
/*  f0cdc44:	46001506 */ 	mov.s	$f20,$f2
/*  f0cdc48:	46000586 */ 	mov.s	$f22,$f0
/*  f0cdc4c:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f0cdc50:	3c0f8006 */ 	lui	$t7,0x8006
/*  f0cdc54:	27a4008c */ 	addiu	$a0,$sp,0x8c
/*  f0cdc58:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0cdc5c:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f0cdc60:	27a50080 */ 	addiu	$a1,$sp,0x80
/*  f0cdc64:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0cdc68:	c7aa00a4 */ 	lwc1	$f10,0xa4($sp)
/*  f0cdc6c:	460a3181 */ 	sub.s	$f6,$f6,$f10
/*  f0cdc70:	46061182 */ 	mul.s	$f6,$f2,$f6
/*  f0cdc74:	46062100 */ 	add.s	$f4,$f4,$f6
/*  f0cdc78:	4618203c */ 	c.lt.s	$f4,$f24
/*  f0cdc7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdc80:	45000003 */ 	bc1f	.L0f0cdc90
/*  f0cdc84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdc88:	46001507 */ 	neg.s	$f20,$f2
/*  f0cdc8c:	46000587 */ 	neg.s	$f22,$f0
.L0f0cdc90:
/*  f0cdc90:	8deff034 */ 	lw	$t7,-0xfcc($t7)
/*  f0cdc94:	c7ac00a4 */ 	lwc1	$f12,0xa4($sp)
/*  f0cdc98:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f0cdc9c:	11e00020 */ 	beqz	$t7,.L0f0cdd20
/*  f0cdca0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdca4:	3c04800a */ 	lui	$a0,0x800a
/*  f0cdca8:	9084a919 */ 	lbu	$a0,-0x56e7($a0)
/*  f0cdcac:	3c18800a */ 	lui	$t8,0x800a
/*  f0cdcb0:	2702a918 */ 	addiu	$v0,$t8,-22248
/*  f0cdcb4:	18800061 */ 	blez	$a0,.L0f0cde3c
/*  f0cdcb8:	0004c8c0 */ 	sll	$t9,$a0,0x3
/*  f0cdcbc:	03221821 */ 	addu	$v1,$t9,$v0
/*  f0cdcc0:	c4460010 */ 	lwc1	$f6,0x10($v0)
.L0f0cdcc4:
/*  f0cdcc4:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f0cdcc8:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f0cdccc:	46123101 */ 	sub.s	$f4,$f6,$f18
/*  f0cdcd0:	0043082b */ 	sltu	$at,$v0,$v1
/*  f0cdcd4:	460c4181 */ 	sub.s	$f6,$f8,$f12
/*  f0cdcd8:	46162282 */ 	mul.s	$f10,$f4,$f22
/*  f0cdcdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdce0:	46143102 */ 	mul.s	$f4,$f6,$f20
/*  f0cdce4:	46045000 */ 	add.s	$f0,$f10,$f4
/*  f0cdce8:	4618003c */ 	c.lt.s	$f0,$f24
/*  f0cdcec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdcf0:	45000007 */ 	bc1f	.L0f0cdd10
/*  f0cdcf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdcf8:	46000007 */ 	neg.s	$f0,$f0
/*  f0cdcfc:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0cdd00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdd04:	45000002 */ 	bc1f	.L0f0cdd10
/*  f0cdd08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdd0c:	46000386 */ 	mov.s	$f14,$f0
.L0f0cdd10:
/*  f0cdd10:	5420ffec */ 	bnezl	$at,.L0f0cdcc4
/*  f0cdd14:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f0cdd18:	10000049 */ 	beqz	$zero,.L0f0cde40
/*  f0cdd1c:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
.L0f0cdd20:
/*  f0cdd20:	0c0094d9 */ 	jal	func00025364
/*  f0cdd24:	e7ae0060 */ 	swc1	$f14,0x60($sp)
/*  f0cdd28:	1040001c */ 	beqz	$v0,.L0f0cdd9c
/*  f0cdd2c:	c7ae0060 */ 	lwc1	$f14,0x60($sp)
/*  f0cdd30:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f0cdd34:	c7a80094 */ 	lwc1	$f8,0x94($sp)
/*  f0cdd38:	c7ac00a4 */ 	lwc1	$f12,0xa4($sp)
/*  f0cdd3c:	c7a4008c */ 	lwc1	$f4,0x8c($sp)
/*  f0cdd40:	46124181 */ 	sub.s	$f6,$f8,$f18
/*  f0cdd44:	460c2201 */ 	sub.s	$f8,$f4,$f12
/*  f0cdd48:	46163282 */ 	mul.s	$f10,$f6,$f22
/*  f0cdd4c:	c7a40088 */ 	lwc1	$f4,0x88($sp)
/*  f0cdd50:	46144182 */ 	mul.s	$f6,$f8,$f20
/*  f0cdd54:	46122201 */ 	sub.s	$f8,$f4,$f18
/*  f0cdd58:	46065000 */ 	add.s	$f0,$f10,$f6
/*  f0cdd5c:	c7a60080 */ 	lwc1	$f6,0x80($sp)
/*  f0cdd60:	46164282 */ 	mul.s	$f10,$f8,$f22
/*  f0cdd64:	460c3101 */ 	sub.s	$f4,$f6,$f12
/*  f0cdd68:	46142202 */ 	mul.s	$f8,$f4,$f20
/*  f0cdd6c:	46085400 */ 	add.s	$f16,$f10,$f8
/*  f0cdd70:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0cdd74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdd78:	45020003 */ 	bc1fl	.L0f0cdd88
/*  f0cdd7c:	4618003c */ 	c.lt.s	$f0,$f24
/*  f0cdd80:	46008006 */ 	mov.s	$f0,$f16
/*  f0cdd84:	4618003c */ 	c.lt.s	$f0,$f24
.L0f0cdd88:
/*  f0cdd88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdd8c:	4502002c */ 	bc1fl	.L0f0cde40
/*  f0cdd90:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0cdd94:	10000029 */ 	beqz	$zero,.L0f0cde3c
/*  f0cdd98:	46000387 */ 	neg.s	$f14,$f0
.L0f0cdd9c:
/*  f0cdd9c:	3c088007 */ 	lui	$t0,0x8007
/*  f0cdda0:	8d080e80 */ 	lw	$t0,0xe80($t0)
/*  f0cdda4:	3c09800a */ 	lui	$t1,0x800a
/*  f0cdda8:	51000025 */ 	beqzl	$t0,.L0f0cde40
/*  f0cddac:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0cddb0:	8d29a244 */ 	lw	$t1,-0x5dbc($t1)
/*  f0cddb4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cddb8:	8d241b5c */ 	lw	$a0,0x1b5c($t1)
/*  f0cddbc:	908a0000 */ 	lbu	$t2,0x0($a0)
/*  f0cddc0:	5541001f */ 	bnel	$t2,$at,.L0f0cde40
/*  f0cddc4:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0cddc8:	8c8b0004 */ 	lw	$t3,0x4($a0)
/*  f0cddcc:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f0cddd0:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f0cddd4:	8d6c0010 */ 	lw	$t4,0x10($t3)
/*  f0cddd8:	27a70044 */ 	addiu	$a3,$sp,0x44
/*  f0cdddc:	000c6980 */ 	sll	$t5,$t4,0x6
/*  f0cdde0:	05a30017 */ 	bgezl	$t5,.L0f0cde40
/*  f0cdde4:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0cdde8:	0fc21d5b */ 	jal	propObjGetBbox
/*  f0cddec:	e7ae0060 */ 	swc1	$f14,0x60($sp)
/*  f0cddf0:	3c02800a */ 	lui	$v0,%hi(var8009de78)
/*  f0cddf4:	2442de78 */ 	addiu	$v0,$v0,%lo(var8009de78)
/*  f0cddf8:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f0cddfc:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f0cde00:	c7ac00a4 */ 	lwc1	$f12,0xa4($sp)
/*  f0cde04:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f0cde08:	46123101 */ 	sub.s	$f4,$f6,$f18
/*  f0cde0c:	c7ae0060 */ 	lwc1	$f14,0x60($sp)
/*  f0cde10:	460c4181 */ 	sub.s	$f6,$f8,$f12
/*  f0cde14:	46162282 */ 	mul.s	$f10,$f4,$f22
/*  f0cde18:	c7a8004c */ 	lwc1	$f8,0x4c($sp)
/*  f0cde1c:	46143102 */ 	mul.s	$f4,$f6,$f20
/*  f0cde20:	46045000 */ 	add.s	$f0,$f10,$f4
/*  f0cde24:	46080001 */ 	sub.s	$f0,$f0,$f8
/*  f0cde28:	4618003c */ 	c.lt.s	$f0,$f24
/*  f0cde2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cde30:	45020003 */ 	bc1fl	.L0f0cde40
/*  f0cde34:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0cde38:	46000387 */ 	neg.s	$f14,$f0
.L0f0cde3c:
/*  f0cde3c:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
.L0f0cde40:
/*  f0cde40:	0c0068f7 */ 	jal	func0001a3dc
/*  f0cde44:	e7ae0060 */ 	swc1	$f14,0x60($sp)
/*  f0cde48:	3c0143c8 */ 	lui	$at,0x43c8
/*  f0cde4c:	44813000 */ 	mtc1	$at,$f6
/*  f0cde50:	c7ae0060 */ 	lwc1	$f14,0x60($sp)
/*  f0cde54:	00001025 */ 	or	$v0,$zero,$zero
/*  f0cde58:	46060302 */ 	mul.s	$f12,$f0,$f6
/*  f0cde5c:	4618603c */ 	c.lt.s	$f12,$f24
/*  f0cde60:	46006086 */ 	mov.s	$f2,$f12
/*  f0cde64:	45020003 */ 	bc1fl	.L0f0cde74
/*  f0cde68:	460e103c */ 	c.lt.s	$f2,$f14
/*  f0cde6c:	46006087 */ 	neg.s	$f2,$f12
/*  f0cde70:	460e103c */ 	c.lt.s	$f2,$f14
.L0f0cde74:
/*  f0cde74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cde78:	45020003 */ 	bc1fl	.L0f0cde88
/*  f0cde7c:	460ec03e */ 	c.le.s	$f24,$f14
/*  f0cde80:	46001386 */ 	mov.s	$f14,$f2
/*  f0cde84:	460ec03e */ 	c.le.s	$f24,$f14
.L0f0cde88:
/*  f0cde88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cde8c:	45000012 */ 	bc1f	.L0f0cded8
/*  f0cde90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cde94:	46147282 */ 	mul.s	$f10,$f14,$f20
/*  f0cde98:	3c017f1b */ 	lui	$at,%hi(var7f1ad9c8)
/*  f0cde9c:	c420d9c8 */ 	lwc1	$f0,%lo(var7f1ad9c8)($at)
/*  f0cdea0:	e7b80058 */ 	swc1	$f24,0x58($sp)
/*  f0cdea4:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f0cdea8:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0cdeac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdeb0:	46167202 */ 	mul.s	$f8,$f14,$f22
/*  f0cdeb4:	e7a40054 */ 	swc1	$f4,0x54($sp)
/*  f0cdeb8:	46004182 */ 	mul.s	$f6,$f8,$f0
/*  f0cdebc:	0fc3382f */ 	jal	func0f0ce0bc
/*  f0cdec0:	e7a6005c */ 	swc1	$f6,0x5c($sp)
/*  f0cdec4:	c7ac00b0 */ 	lwc1	$f12,0xb0($sp)
/*  f0cdec8:	0fc336c1 */ 	jal	func0f0cdb04
/*  f0cdecc:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0cded0:	10000002 */ 	beqz	$zero,.L0f0cdedc
/*  f0cded4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0cded8:
/*  f0cded8:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0cdedc:
/*  f0cdedc:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f0cdee0:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f0cdee4:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f0cdee8:	03e00008 */ 	jr	$ra
/*  f0cdeec:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
);

GLOBAL_ASM(
glabel func0f0cdef0
/*  f0cdef0:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0cdef4:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0cdef8:	8c4e0034 */ 	lw	$t6,0x34($v0)
/*  f0cdefc:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0cdf00:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0cdf04:	59c00014 */ 	blezl	$t6,.L0f0cdf58
/*  f0cdf08:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cdf0c:	8c4f0284 */ 	lw	$t7,0x284($v0)
/*  f0cdf10:	c446004c */ 	lwc1	$f6,0x4c($v0)
/*  f0cdf14:	3c017f1b */ 	lui	$at,%hi(var7f1ad9cc)
/*  f0cdf18:	c5e40148 */ 	lwc1	$f4,0x148($t7)
/*  f0cdf1c:	c42ad9cc */ 	lwc1	$f10,%lo(var7f1ad9cc)($at)
/*  f0cdf20:	3c014060 */ 	lui	$at,0x4060
/*  f0cdf24:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0cdf28:	44819000 */ 	mtc1	$at,$f18
/*  f0cdf2c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0cdf30:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0cdf34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdf38:	46128302 */ 	mul.s	$f12,$f16,$f18
/*  f0cdf3c:	0fc336c1 */ 	jal	func0f0cdb04
/*  f0cdf40:	e7ac001c */ 	swc1	$f12,0x1c($sp)
/*  f0cdf44:	14400003 */ 	bnez	$v0,.L0f0cdf54
/*  f0cdf48:	c7ac001c */ 	lwc1	$f12,0x1c($sp)
/*  f0cdf4c:	0fc336da */ 	jal	func0f0cdb68
/*  f0cdf50:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cdf54:
/*  f0cdf54:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0cdf58:
/*  f0cdf58:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0cdf5c:	03e00008 */ 	jr	$ra
/*  f0cdf60:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0cdf64
/*  f0cdf64:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0cdf68:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0cdf6c:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f0cdf70:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f0cdf74:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0cdf78:	0fc3365c */ 	jal	func0f0cd970
/*  f0cdf7c:	24050000 */ 	addiu	$a1,$zero,0x0
/*  f0cdf80:	14400009 */ 	bnez	$v0,.L0f0cdfa8
/*  f0cdf84:	00401825 */ 	or	$v1,$v0,$zero
/*  f0cdf88:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f0cdf8c:	24e7d964 */ 	addiu	$a3,$a3,-9884
/*  f0cdf90:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f0cdf94:	8fa50028 */ 	lw	$a1,0x28($sp)
/*  f0cdf98:	2406032f */ 	addiu	$a2,$zero,0x32f
/*  f0cdf9c:	0c009393 */ 	jal	func00024e4c
/*  f0cdfa0:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f0cdfa4:	8fa3001c */ 	lw	$v1,0x1c($sp)
.L0f0cdfa8:
/*  f0cdfa8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0cdfac:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0cdfb0:	00601025 */ 	or	$v0,$v1,$zero
/*  f0cdfb4:	03e00008 */ 	jr	$ra
/*  f0cdfb8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0cdfbc
/*  f0cdfbc:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0cdfc0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0cdfc4:	c4c20000 */ 	lwc1	$f2,0x0($a2)
/*  f0cdfc8:	c4a00000 */ 	lwc1	$f0,0x0($a1)
/*  f0cdfcc:	00803825 */ 	or	$a3,$a0,$zero
/*  f0cdfd0:	46020032 */ 	c.eq.s	$f0,$f2
/*  f0cdfd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdfd8:	45020009 */ 	bc1fl	.L0f0ce000
/*  f0cdfdc:	46001201 */ 	sub.s	$f8,$f2,$f0
/*  f0cdfe0:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*  f0cdfe4:	c4c60008 */ 	lwc1	$f6,0x8($a2)
/*  f0cdfe8:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0cdfec:	46062032 */ 	c.eq.s	$f4,$f6
/*  f0cdff0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdff4:	4501002d */ 	bc1t	.L0f0ce0ac
/*  f0cdff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cdffc:	46001201 */ 	sub.s	$f8,$f2,$f0
.L0f0ce000:
/*  f0ce000:	e7a80030 */ 	swc1	$f8,0x30($sp)
/*  f0ce004:	c4b00008 */ 	lwc1	$f16,0x8($a1)
/*  f0ce008:	c4ca0008 */ 	lwc1	$f10,0x8($a2)
/*  f0ce00c:	c7a80030 */ 	lwc1	$f8,0x30($sp)
/*  f0ce010:	afa70040 */ 	sw	$a3,0x40($sp)
/*  f0ce014:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f0ce018:	e7b20038 */ 	swc1	$f18,0x38($sp)
/*  f0ce01c:	c7a40038 */ 	lwc1	$f4,0x38($sp)
/*  f0ce020:	46042182 */ 	mul.s	$f6,$f4,$f4
/*  f0ce024:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce028:	46084282 */ 	mul.s	$f10,$f8,$f8
/*  f0ce02c:	0c012974 */ 	jal	sqrtf
/*  f0ce030:	460a3300 */ 	add.s	$f12,$f6,$f10
/*  f0ce034:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ce038:	44818000 */ 	mtc1	$at,$f16
/*  f0ce03c:	c7b20030 */ 	lwc1	$f18,0x30($sp)
/*  f0ce040:	c7a80038 */ 	lwc1	$f8,0x38($sp)
/*  f0ce044:	46008083 */ 	div.s	$f2,$f16,$f0
/*  f0ce048:	8fa70040 */ 	lw	$a3,0x40($sp)
/*  f0ce04c:	44807000 */ 	mtc1	$zero,$f14
/*  f0ce050:	27a40024 */ 	addiu	$a0,$sp,0x24
/*  f0ce054:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0ce058:	44057000 */ 	mfc1	$a1,$f14
/*  f0ce05c:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f0ce060:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce064:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f0ce068:	e7a40030 */ 	swc1	$f4,0x30($sp)
/*  f0ce06c:	e7a60038 */ 	swc1	$f6,0x38($sp)
/*  f0ce070:	c4ea0008 */ 	lwc1	$f10,0x8($a3)
/*  f0ce074:	c4f20000 */ 	lwc1	$f18,0x0($a3)
/*  f0ce078:	e7ae0028 */ 	swc1	$f14,0x28($sp)
/*  f0ce07c:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0ce080:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce084:	46049202 */ 	mul.s	$f8,$f18,$f4
/*  f0ce088:	46088300 */ 	add.s	$f12,$f16,$f8
/*  f0ce08c:	460c2282 */ 	mul.s	$f10,$f4,$f12
/*  f0ce090:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce094:	460c3482 */ 	mul.s	$f18,$f6,$f12
/*  f0ce098:	e7aa0024 */ 	swc1	$f10,0x24($sp)
/*  f0ce09c:	0fc3365c */ 	jal	func0f0cd970
/*  f0ce0a0:	e7b2002c */ 	swc1	$f18,0x2c($sp)
/*  f0ce0a4:	10000002 */ 	beqz	$zero,.L0f0ce0b0
/*  f0ce0a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ce0ac:
/*  f0ce0ac:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ce0b0:
/*  f0ce0b0:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f0ce0b4:	03e00008 */ 	jr	$ra
/*  f0ce0b8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ce0bc
/*  f0ce0bc:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0ce0c0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0ce0c4:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0ce0c8:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*  f0ce0cc:	0fc337d9 */ 	jal	func0f0cdf64
/*  f0ce0d0:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f0ce0d4:	14400006 */ 	bnez	$v0,.L0f0ce0f0
/*  f0ce0d8:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0ce0dc:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*  f0ce0e0:	0fc337ef */ 	jal	func0f0cdfbc
/*  f0ce0e4:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f0ce0e8:	5c400002 */ 	bgtzl	$v0,.L0f0ce0f4
/*  f0ce0ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ce0f0:
/*  f0ce0f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0ce0f4:
/*  f0ce0f4:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0ce0f8:	03e00008 */ 	jr	$ra
/*  f0ce0fc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ce100
/*  f0ce100:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0ce104:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0ce108:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ce10c:	8c4e00bc */ 	lw	$t6,0xbc($v0)
/*  f0ce110:	c5c40008 */ 	lwc1	$f4,0x8($t6)
/*  f0ce114:	e4440310 */ 	swc1	$f4,0x310($v0)
/*  f0ce118:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ce11c:	8c4f00bc */ 	lw	$t7,0xbc($v0)
/*  f0ce120:	c5e6000c */ 	lwc1	$f6,0xc($t7)
/*  f0ce124:	e4460314 */ 	swc1	$f6,0x314($v0)
/*  f0ce128:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ce12c:	8c5800bc */ 	lw	$t8,0xbc($v0)
/*  f0ce130:	c7080010 */ 	lwc1	$f8,0x10($t8)
/*  f0ce134:	e4480318 */ 	swc1	$f8,0x318($v0)
/*  f0ce138:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ce13c:	c44a0144 */ 	lwc1	$f10,0x144($v0)
/*  f0ce140:	e44a19fc */ 	swc1	$f10,0x19fc($v0)
/*  f0ce144:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ce148:	8c591b5c */ 	lw	$t9,0x1b5c($v0)
/*  f0ce14c:	c7300008 */ 	lwc1	$f16,0x8($t9)
/*  f0ce150:	e4501a00 */ 	swc1	$f16,0x1a00($v0)
/*  f0ce154:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ce158:	8c481b5c */ 	lw	$t0,0x1b5c($v0)
/*  f0ce15c:	c512000c */ 	lwc1	$f18,0xc($t0)
/*  f0ce160:	e4521a04 */ 	swc1	$f18,0x1a04($v0)
/*  f0ce164:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ce168:	8c491b5c */ 	lw	$t1,0x1b5c($v0)
/*  f0ce16c:	c5240010 */ 	lwc1	$f4,0x10($t1)
/*  f0ce170:	03e00008 */ 	jr	$ra
/*  f0ce174:	e4441a08 */ 	swc1	$f4,0x1a08($v0)
);

GLOBAL_ASM(
glabel func0f0ce178
/*  f0ce178:	3c0e800a */ 	lui	$t6,0x800a
/*  f0ce17c:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0ce180:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0ce184:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0ce188:	8dcf1b5c */ 	lw	$t7,0x1b5c($t6)
/*  f0ce18c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ce190:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0ce194:	0fc1a71c */ 	jal	func0f069c70
/*  f0ce198:	8de40004 */ 	lw	$a0,0x4($t7)
/*  f0ce19c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ce1a0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0ce1a4:	03e00008 */ 	jr	$ra
/*  f0ce1a8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ce1ac
/*  f0ce1ac:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0ce1b0:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0ce1b4:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0ce1b8:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f0ce1bc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0ce1c0:	afa00054 */ 	sw	$zero,0x54($sp)
/*  f0ce1c4:	8c6200bc */ 	lw	$v0,0xbc($v1)
/*  f0ce1c8:	8c650378 */ 	lw	$a1,0x378($v1)
/*  f0ce1cc:	27b90058 */ 	addiu	$t9,$sp,0x58
/*  f0ce1d0:	27a90054 */ 	addiu	$t1,$sp,0x54
/*  f0ce1d4:	246e161e */ 	addiu	$t6,$v1,0x161e
/*  f0ce1d8:	246f161c */ 	addiu	$t7,$v1,0x161c
/*  f0ce1dc:	247819b0 */ 	addiu	$t8,$v1,0x19b0
/*  f0ce1e0:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0ce1e4:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0ce1e8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0ce1ec:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f0ce1f0:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0ce1f4:	2467161a */ 	addiu	$a3,$v1,0x161a
/*  f0ce1f8:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0ce1fc:	0c00a86c */ 	jal	func0002a1b0
/*  f0ce200:	24460028 */ 	addiu	$a2,$v0,0x28
/*  f0ce204:	3c017f1b */ 	lui	$at,%hi(var7f1ad9d0)
/*  f0ce208:	c422d9d0 */ 	lwc1	$f2,%lo(var7f1ad9d0)($at)
/*  f0ce20c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0ce210:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0ce214:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0ce218:	46000386 */ 	mov.s	$f14,$f0
/*  f0ce21c:	8fab0058 */ 	lw	$t3,0x58($sp)
/*  f0ce220:	45020003 */ 	bc1fl	.L0f0ce230
/*  f0ce224:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0ce228:	46001386 */ 	mov.s	$f14,$f2
/*  f0ce22c:	8d030284 */ 	lw	$v1,0x284($t0)
.L0f0ce230:
/*  f0ce230:	8c6a02b0 */ 	lw	$t2,0x2b0($v1)
/*  f0ce234:	51400027 */ 	beqzl	$t2,.L0f0ce2d4
/*  f0ce238:	afa00054 */ 	sw	$zero,0x54($sp)
/*  f0ce23c:	11600024 */ 	beqz	$t3,.L0f0ce2d0
/*  f0ce240:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f0ce244:	8c6d0298 */ 	lw	$t5,0x298($v1)
/*  f0ce248:	558d0023 */ 	bnel	$t4,$t5,.L0f0ce2d8
/*  f0ce24c:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f0ce250:	c4640294 */ 	lwc1	$f4,0x294($v1)
/*  f0ce254:	c4660074 */ 	lwc1	$f6,0x74($v1)
/*  f0ce258:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ce25c:	44814000 */ 	mtc1	$at,$f8
/*  f0ce260:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f0ce264:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0ce268:	4608003c */ 	c.lt.s	$f0,$f8
/*  f0ce26c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce270:	45020019 */ 	bc1fl	.L0f0ce2d8
/*  f0ce274:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f0ce278:	44815000 */ 	mtc1	$at,$f10
/*  f0ce27c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce280:	4600503c */ 	c.lt.s	$f10,$f0
/*  f0ce284:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce288:	45020013 */ 	bc1fl	.L0f0ce2d8
/*  f0ce28c:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f0ce290:	c46c0078 */ 	lwc1	$f12,0x78($v1)
/*  f0ce294:	3c017f1b */ 	lui	$at,%hi(var7f1ad9d4)
/*  f0ce298:	460c7001 */ 	sub.s	$f0,$f14,$f12
/*  f0ce29c:	46006100 */ 	add.s	$f4,$f12,$f0
/*  f0ce2a0:	e4640078 */ 	swc1	$f4,0x78($v1)
/*  f0ce2a4:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0ce2a8:	c4660074 */ 	lwc1	$f6,0x74($v1)
/*  f0ce2ac:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f0ce2b0:	e4680074 */ 	swc1	$f8,0x74($v1)
/*  f0ce2b4:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0ce2b8:	c424d9d4 */ 	lwc1	$f4,%lo(var7f1ad9d4)($at)
/*  f0ce2bc:	c46a0074 */ 	lwc1	$f10,0x74($v1)
/*  f0ce2c0:	46045183 */ 	div.s	$f6,$f10,$f4
/*  f0ce2c4:	e4660070 */ 	swc1	$f6,0x70($v1)
/*  f0ce2c8:	10000002 */ 	beqz	$zero,.L0f0ce2d4
/*  f0ce2cc:	8d030284 */ 	lw	$v1,0x284($t0)
.L0f0ce2d0:
/*  f0ce2d0:	afa00054 */ 	sw	$zero,0x54($sp)
.L0f0ce2d4:
/*  f0ce2d4:	8fae0058 */ 	lw	$t6,0x58($sp)
.L0f0ce2d8:
/*  f0ce2d8:	ac6e02b0 */ 	sw	$t6,0x2b0($v1)
/*  f0ce2dc:	8faf0058 */ 	lw	$t7,0x58($sp)
/*  f0ce2e0:	51e00004 */ 	beqzl	$t7,.L0f0ce2f4
/*  f0ce2e4:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f0ce2e8:	8d180284 */ 	lw	$t8,0x284($t0)
/*  f0ce2ec:	e70e0294 */ 	swc1	$f14,0x294($t8)
/*  f0ce2f0:	8fb90054 */ 	lw	$t9,0x54($sp)
.L0f0ce2f4:
/*  f0ce2f4:	8d090284 */ 	lw	$t1,0x284($t0)
/*  f0ce2f8:	3c017f1b */ 	lui	$at,%hi(var7f1ad9d8)
/*  f0ce2fc:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ce300:	ad390298 */ 	sw	$t9,0x298($t1)
/*  f0ce304:	8d0a0284 */ 	lw	$t2,0x284($t0)
/*  f0ce308:	e54e0078 */ 	swc1	$f14,0x78($t2)
/*  f0ce30c:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0ce310:	c46803c4 */ 	lwc1	$f8,0x3c4($v1)
/*  f0ce314:	c46a0414 */ 	lwc1	$f10,0x414($v1)
/*  f0ce318:	c46619c4 */ 	lwc1	$f6,0x19c4($v1)
/*  f0ce31c:	460a4103 */ 	div.s	$f4,$f8,$f10
/*  f0ce320:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0ce324:	e46819bc */ 	swc1	$f8,0x19bc($v1)
/*  f0ce328:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0ce32c:	8d040034 */ 	lw	$a0,0x34($t0)
/*  f0ce330:	c424d9d8 */ 	lwc1	$f4,%lo(var7f1ad9d8)($at)
/*  f0ce334:	c46a0074 */ 	lwc1	$f10,0x74($v1)
/*  f0ce338:	3c017f1b */ 	lui	$at,%hi(var7f1ad9dc)
/*  f0ce33c:	18800008 */ 	blez	$a0,.L0f0ce360
/*  f0ce340:	46045083 */ 	div.s	$f2,$f10,$f4
/*  f0ce344:	c46c0078 */ 	lwc1	$f12,0x78($v1)
/*  f0ce348:	c420d9dc */ 	lwc1	$f0,%lo(var7f1ad9dc)($at)
.L0f0ce34c:
/*  f0ce34c:	46020182 */ 	mul.s	$f6,$f0,$f2
/*  f0ce350:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0ce354:	0044082a */ 	slt	$at,$v0,$a0
/*  f0ce358:	1420fffc */ 	bnez	$at,.L0f0ce34c
/*  f0ce35c:	460c3080 */ 	add.s	$f2,$f6,$f12
.L0f0ce360:
/*  f0ce360:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0ce364:	44817000 */ 	mtc1	$at,$f14
/*  f0ce368:	c46019bc */ 	lwc1	$f0,0x19bc($v1)
/*  f0ce36c:	c46c0078 */ 	lwc1	$f12,0x78($v1)
/*  f0ce370:	3c017f1b */ 	lui	$at,%hi(var7f1ad9e0)
/*  f0ce374:	460e003c */ 	c.lt.s	$f0,$f14
/*  f0ce378:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce37c:	45000002 */ 	bc1f	.L0f0ce388
/*  f0ce380:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce384:	46007006 */ 	mov.s	$f0,$f14
.L0f0ce388:
/*  f0ce388:	c428d9e0 */ 	lwc1	$f8,%lo(var7f1ad9e0)($at)
/*  f0ce38c:	8c6b00bc */ 	lw	$t3,0xbc($v1)
/*  f0ce390:	3c014120 */ 	lui	$at,0x4120
/*  f0ce394:	46081482 */ 	mul.s	$f18,$f2,$f8
/*  f0ce398:	44812000 */ 	mtc1	$at,$f4
/*  f0ce39c:	c570000c */ 	lwc1	$f16,0xc($t3)
/*  f0ce3a0:	46046180 */ 	add.s	$f6,$f12,$f4
/*  f0ce3a4:	46009280 */ 	add.s	$f10,$f18,$f0
/*  f0ce3a8:	e7a60030 */ 	swc1	$f6,0x30($sp)
/*  f0ce3ac:	46105381 */ 	sub.s	$f14,$f10,$f16
/*  f0ce3b0:	c7aa0030 */ 	lwc1	$f10,0x30($sp)
/*  f0ce3b4:	460e8200 */ 	add.s	$f8,$f16,$f14
/*  f0ce3b8:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0ce3bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce3c0:	45020003 */ 	bc1fl	.L0f0ce3d0
/*  f0ce3c4:	46007306 */ 	mov.s	$f12,$f14
/*  f0ce3c8:	46105381 */ 	sub.s	$f14,$f10,$f16
/*  f0ce3cc:	46007306 */ 	mov.s	$f12,$f14
.L0f0ce3d0:
/*  f0ce3d0:	e7a20048 */ 	swc1	$f2,0x48($sp)
/*  f0ce3d4:	0fc33417 */ 	jal	func0f0cd05c
/*  f0ce3d8:	e7b20038 */ 	swc1	$f18,0x38($sp)
/*  f0ce3dc:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0ce3e0:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0ce3e4:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f0ce3e8:	10400005 */ 	beqz	$v0,.L0f0ce400
/*  f0ce3ec:	c7b20038 */ 	lwc1	$f18,0x38($sp)
/*  f0ce3f0:	8d0c0284 */ 	lw	$t4,0x284($t0)
/*  f0ce3f4:	e5820070 */ 	swc1	$f2,0x70($t4)
/*  f0ce3f8:	8d0d0284 */ 	lw	$t5,0x284($t0)
/*  f0ce3fc:	e5b20074 */ 	swc1	$f18,0x74($t5)
.L0f0ce400:
/*  f0ce400:	8d030284 */ 	lw	$v1,0x284($t0)
/*  f0ce404:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0ce408:	946e161c */ 	lhu	$t6,0x161c($v1)
/*  f0ce40c:	31cf4000 */ 	andi	$t7,$t6,0x4000
/*  f0ce410:	51e0000c */ 	beqzl	$t7,.L0f0ce444
/*  f0ce414:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0ce418:	c4640074 */ 	lwc1	$f4,0x74($v1)
/*  f0ce41c:	44813000 */ 	mtc1	$at,$f6
/*  f0ce420:	c46a0078 */ 	lwc1	$f10,0x78($v1)
/*  f0ce424:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0ce428:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0ce42c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce430:	45020004 */ 	bc1fl	.L0f0ce444
/*  f0ce434:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0ce438:	0fc304ea */ 	jal	func0f0c13a8
/*  f0ce43c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0ce440:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0ce444:
/*  f0ce444:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*  f0ce448:	03e00008 */ 	jr	$ra
/*  f0ce44c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ce450
/*  f0ce450:	3c0e800a */ 	lui	$t6,0x800a
/*  f0ce454:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f0ce458:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0ce45c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0ce460:	0fc21b58 */ 	jal	func0f086d60
/*  f0ce464:	8dc41b5c */ 	lw	$a0,0x1b5c($t6)
/*  f0ce468:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0ce46c:	10400004 */ 	beqz	$v0,.L0f0ce480
/*  f0ce470:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0ce474:	8c6f0284 */ 	lw	$t7,0x284($v1)
/*  f0ce478:	10000005 */ 	beqz	$zero,.L0f0ce490
/*  f0ce47c:	ade000d0 */ 	sw	$zero,0xd0($t7)
.L0f0ce480:
/*  f0ce480:	8c780284 */ 	lw	$t8,0x284($v1)
/*  f0ce484:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ce488:	0fc31f4c */ 	jal	currentPlayerSetMoveMode
/*  f0ce48c:	af0000d0 */ 	sw	$zero,0xd0($t8)
.L0f0ce490:
/*  f0ce490:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ce494:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0ce498:	03e00008 */ 	jr	$ra
/*  f0ce49c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ce4a0
/*  f0ce4a0:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0ce4a4:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0ce4a8:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ce4ac:	c440016c */ 	lwc1	$f0,0x16c($v0)
/*  f0ce4b0:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0ce4b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce4b8:	45020013 */ 	bc1fl	.L0f0ce508
/*  f0ce4bc:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0ce4c0:	44862000 */ 	mtc1	$a2,$f4
/*  f0ce4c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce4c8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ce4cc:	46067202 */ 	mul.s	$f8,$f14,$f6
/*  f0ce4d0:	46080281 */ 	sub.s	$f10,$f0,$f8
/*  f0ce4d4:	e44a016c */ 	swc1	$f10,0x16c($v0)
/*  f0ce4d8:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ce4dc:	c440016c */ 	lwc1	$f0,0x16c($v0)
/*  f0ce4e0:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0ce4e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce4e8:	4500001a */ 	bc1f	.L0f0ce554
/*  f0ce4ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce4f0:	e44c016c */ 	swc1	$f12,0x16c($v0)
/*  f0ce4f4:	3c02800a */ 	lui	$v0,0x800a
/*  f0ce4f8:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0ce4fc:	10000015 */ 	beqz	$zero,.L0f0ce554
/*  f0ce500:	c440016c */ 	lwc1	$f0,0x16c($v0)
/*  f0ce504:	460c003c */ 	c.lt.s	$f0,$f12
.L0f0ce508:
/*  f0ce508:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce50c:	45000011 */ 	bc1f	.L0f0ce554
/*  f0ce510:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce514:	44868000 */ 	mtc1	$a2,$f16
/*  f0ce518:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce51c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0ce520:	46127102 */ 	mul.s	$f4,$f14,$f18
/*  f0ce524:	46040180 */ 	add.s	$f6,$f0,$f4
/*  f0ce528:	e446016c */ 	swc1	$f6,0x16c($v0)
/*  f0ce52c:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ce530:	c440016c */ 	lwc1	$f0,0x16c($v0)
/*  f0ce534:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0ce538:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce53c:	45000005 */ 	bc1f	.L0f0ce554
/*  f0ce540:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce544:	e44c016c */ 	swc1	$f12,0x16c($v0)
/*  f0ce548:	3c02800a */ 	lui	$v0,0x800a
/*  f0ce54c:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0ce550:	c440016c */ 	lwc1	$f0,0x16c($v0)
.L0f0ce554:
/*  f0ce554:	03e00008 */ 	jr	$ra
/*  f0ce558:	e4400168 */ 	swc1	$f0,0x168($v0)
);

GLOBAL_ASM(
glabel func0f0ce55c
/*  f0ce55c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0ce560:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0ce564:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ce568:	c44019a4 */ 	lwc1	$f0,0x19a4($v0)
/*  f0ce56c:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0ce570:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce574:	45020011 */ 	bc1fl	.L0f0ce5bc
/*  f0ce578:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0ce57c:	c464004c */ 	lwc1	$f4,0x4c($v1)
/*  f0ce580:	46047182 */ 	mul.s	$f6,$f14,$f4
/*  f0ce584:	46060200 */ 	add.s	$f8,$f0,$f6
/*  f0ce588:	e44819a4 */ 	swc1	$f8,0x19a4($v0)
/*  f0ce58c:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ce590:	c44019a4 */ 	lwc1	$f0,0x19a4($v0)
/*  f0ce594:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0ce598:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce59c:	45000018 */ 	bc1f	.L0f0ce600
/*  f0ce5a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce5a4:	e44c19a4 */ 	swc1	$f12,0x19a4($v0)
/*  f0ce5a8:	3c02800a */ 	lui	$v0,0x800a
/*  f0ce5ac:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0ce5b0:	10000013 */ 	beqz	$zero,.L0f0ce600
/*  f0ce5b4:	c44019a4 */ 	lwc1	$f0,0x19a4($v0)
/*  f0ce5b8:	4600603c */ 	c.lt.s	$f12,$f0
.L0f0ce5bc:
/*  f0ce5bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce5c0:	4500000f */ 	bc1f	.L0f0ce600
/*  f0ce5c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce5c8:	c46a004c */ 	lwc1	$f10,0x4c($v1)
/*  f0ce5cc:	460a7402 */ 	mul.s	$f16,$f14,$f10
/*  f0ce5d0:	46100481 */ 	sub.s	$f18,$f0,$f16
/*  f0ce5d4:	e45219a4 */ 	swc1	$f18,0x19a4($v0)
/*  f0ce5d8:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f0ce5dc:	c44019a4 */ 	lwc1	$f0,0x19a4($v0)
/*  f0ce5e0:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0ce5e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce5e8:	45000005 */ 	bc1f	.L0f0ce600
/*  f0ce5ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce5f0:	e44c19a4 */ 	swc1	$f12,0x19a4($v0)
/*  f0ce5f4:	3c02800a */ 	lui	$v0,0x800a
/*  f0ce5f8:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0ce5fc:	c44019a4 */ 	lwc1	$f0,0x19a4($v0)
.L0f0ce600:
/*  f0ce600:	03e00008 */ 	jr	$ra
/*  f0ce604:	e4400170 */ 	swc1	$f0,0x170($v0)
);

GLOBAL_ASM(
glabel func0f0ce608
/*  f0ce608:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0ce60c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0ce610:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0ce614:	8c860028 */ 	lw	$a2,0x28($a0)
/*  f0ce618:	00808025 */ 	or	$s0,$a0,$zero
/*  f0ce61c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0ce620:	50c00008 */ 	beqzl	$a2,.L0f0ce644
/*  f0ce624:	8e06002c */ 	lw	$a2,0x2c($s0)
/*  f0ce628:	44816000 */ 	mtc1	$at,$f12
/*  f0ce62c:	3c017f1b */ 	lui	$at,%hi(var7f1ad9e4)
/*  f0ce630:	0fc33928 */ 	jal	func0f0ce4a0
/*  f0ce634:	c42ed9e4 */ 	lwc1	$f14,%lo(var7f1ad9e4)($at)
/*  f0ce638:	10000015 */ 	beqz	$zero,.L0f0ce690
/*  f0ce63c:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f0ce640:	8e06002c */ 	lw	$a2,0x2c($s0)
.L0f0ce644:
/*  f0ce644:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ce648:	50c00008 */ 	beqzl	$a2,.L0f0ce66c
/*  f0ce64c:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f0ce650:	44816000 */ 	mtc1	$at,$f12
/*  f0ce654:	3c017f1b */ 	lui	$at,%hi(var7f1ad9e8)
/*  f0ce658:	0fc33928 */ 	jal	func0f0ce4a0
/*  f0ce65c:	c42ed9e8 */ 	lwc1	$f14,%lo(var7f1ad9e8)($at)
/*  f0ce660:	1000000b */ 	beqz	$zero,.L0f0ce690
/*  f0ce664:	8e020014 */ 	lw	$v0,0x14($s0)
/*  f0ce668:	8e020014 */ 	lw	$v0,0x14($s0)
.L0f0ce66c:
/*  f0ce66c:	3c017f1b */ 	lui	$at,%hi(var7f1ad9ec)
/*  f0ce670:	3c06800a */ 	lui	$a2,0x800a
/*  f0ce674:	14400006 */ 	bnez	$v0,.L0f0ce690
/*  f0ce678:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce67c:	44806000 */ 	mtc1	$zero,$f12
/*  f0ce680:	c42ed9ec */ 	lwc1	$f14,%lo(var7f1ad9ec)($at)
/*  f0ce684:	0fc33928 */ 	jal	func0f0ce4a0
/*  f0ce688:	8cc69ff8 */ 	lw	$a2,-0x6008($a2)
/*  f0ce68c:	8e020014 */ 	lw	$v0,0x14($s0)
.L0f0ce690:
/*  f0ce690:	5040000e */ 	beqzl	$v0,.L0f0ce6cc
/*  f0ce694:	8e0f0020 */ 	lw	$t7,0x20($s0)
/*  f0ce698:	8e0e00a4 */ 	lw	$t6,0xa4($s0)
/*  f0ce69c:	3c017f1b */ 	lui	$at,%hi(var7f1ad9f0)
/*  f0ce6a0:	c428d9f0 */ 	lwc1	$f8,%lo(var7f1ad9f0)($at)
/*  f0ce6a4:	448e2000 */ 	mtc1	$t6,$f4
/*  f0ce6a8:	3c017f1b */ 	lui	$at,%hi(var7f1ad9f4)
/*  f0ce6ac:	3c06800a */ 	lui	$a2,0x800a
/*  f0ce6b0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0ce6b4:	8cc69ff8 */ 	lw	$a2,-0x6008($a2)
/*  f0ce6b8:	c42ed9f4 */ 	lwc1	$f14,%lo(var7f1ad9f4)($at)
/*  f0ce6bc:	46083302 */ 	mul.s	$f12,$f6,$f8
/*  f0ce6c0:	0fc33928 */ 	jal	func0f0ce4a0
/*  f0ce6c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce6c8:	8e0f0020 */ 	lw	$t7,0x20($s0)
.L0f0ce6cc:
/*  f0ce6cc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ce6d0:	51e0000f */ 	beqzl	$t7,.L0f0ce710
/*  f0ce6d4:	8e090024 */ 	lw	$t1,0x24($s0)
/*  f0ce6d8:	44816000 */ 	mtc1	$at,$f12
/*  f0ce6dc:	3c017f1b */ 	lui	$at,%hi(var7f1ad9f8)
/*  f0ce6e0:	0fc33957 */ 	jal	func0f0ce55c
/*  f0ce6e4:	c42ed9f8 */ 	lwc1	$f14,%lo(var7f1ad9f8)($at)
/*  f0ce6e8:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0ce6ec:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0ce6f0:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0ce6f4:	8c990038 */ 	lw	$t9,0x38($a0)
/*  f0ce6f8:	8c580178 */ 	lw	$t8,0x178($v0)
/*  f0ce6fc:	03194021 */ 	addu	$t0,$t8,$t9
/*  f0ce700:	ac480178 */ 	sw	$t0,0x178($v0)
/*  f0ce704:	10000012 */ 	beqz	$zero,.L0f0ce750
/*  f0ce708:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0ce70c:	8e090024 */ 	lw	$t1,0x24($s0)
.L0f0ce710:
/*  f0ce710:	11200007 */ 	beqz	$t1,.L0f0ce730
/*  f0ce714:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0ce718:	44816000 */ 	mtc1	$at,$f12
/*  f0ce71c:	3c017f1b */ 	lui	$at,%hi(var7f1ad9fc)
/*  f0ce720:	0fc33957 */ 	jal	func0f0ce55c
/*  f0ce724:	c42ed9fc */ 	lwc1	$f14,%lo(var7f1ad9fc)($at)
/*  f0ce728:	10000009 */ 	beqz	$zero,.L0f0ce750
/*  f0ce72c:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0ce730:
/*  f0ce730:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0ce734:	3c017f1b */ 	lui	$at,%hi(var7f1ada00)
/*  f0ce738:	14600005 */ 	bnez	$v1,.L0f0ce750
/*  f0ce73c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce740:	44806000 */ 	mtc1	$zero,$f12
/*  f0ce744:	0fc33957 */ 	jal	func0f0ce55c
/*  f0ce748:	c42eda00 */ 	lwc1	$f14,%lo(var7f1ada00)($at)
/*  f0ce74c:	8e030010 */ 	lw	$v1,0x10($s0)
.L0f0ce750:
/*  f0ce750:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0ce754:	1060001e */ 	beqz	$v1,.L0f0ce7d0
/*  f0ce758:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0ce75c:	8e0a00a8 */ 	lw	$t2,0xa8($s0)
/*  f0ce760:	3c017f1b */ 	lui	$at,%hi(var7f1ada04)
/*  f0ce764:	c432da04 */ 	lwc1	$f18,%lo(var7f1ada04)($at)
/*  f0ce768:	448a5000 */ 	mtc1	$t2,$f10
/*  f0ce76c:	3c017f1b */ 	lui	$at,%hi(var7f1ada08)
/*  f0ce770:	c42eda08 */ 	lwc1	$f14,%lo(var7f1ada08)($at)
/*  f0ce774:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0ce778:	46128302 */ 	mul.s	$f12,$f16,$f18
/*  f0ce77c:	0fc33957 */ 	jal	func0f0ce55c
/*  f0ce780:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce784:	8e0b00a8 */ 	lw	$t3,0xa8($s0)
/*  f0ce788:	3c02800a */ 	lui	$v0,0x800a
/*  f0ce78c:	3c0f800a */ 	lui	$t7,0x800a
/*  f0ce790:	2961003d */ 	slti	$at,$t3,0x3d
/*  f0ce794:	1420000a */ 	bnez	$at,.L0f0ce7c0
/*  f0ce798:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce79c:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f0ce7a0:	3c0d800a */ 	lui	$t5,0x800a
/*  f0ce7a4:	8dad9ff8 */ 	lw	$t5,-0x6008($t5)
/*  f0ce7a8:	8c4c0178 */ 	lw	$t4,0x178($v0)
/*  f0ce7ac:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0ce7b0:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0ce7b4:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f0ce7b8:	10000005 */ 	beqz	$zero,.L0f0ce7d0
/*  f0ce7bc:	ac4e0178 */ 	sw	$t6,0x178($v0)
.L0f0ce7c0:
/*  f0ce7c0:	8defa244 */ 	lw	$t7,-0x5dbc($t7)
/*  f0ce7c4:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0ce7c8:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0ce7cc:	ade00178 */ 	sw	$zero,0x178($t7)
.L0f0ce7d0:
/*  f0ce7d0:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0ce7d4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ce7d8:	44816000 */ 	mtc1	$at,$f12
/*  f0ce7dc:	c4400170 */ 	lwc1	$f0,0x170($v0)
/*  f0ce7e0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0ce7e4:	44811000 */ 	mtc1	$at,$f2
/*  f0ce7e8:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0ce7ec:	3c017f1b */ 	lui	$at,%hi(var7f1ada0c)
/*  f0ce7f0:	45020005 */ 	bc1fl	.L0f0ce808
/*  f0ce7f4:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0ce7f8:	e44c0170 */ 	swc1	$f12,0x170($v0)
/*  f0ce7fc:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0ce800:	c4400170 */ 	lwc1	$f0,0x170($v0)
/*  f0ce804:	4602003c */ 	c.lt.s	$f0,$f2
.L0f0ce808:
/*  f0ce808:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce80c:	45020004 */ 	bc1fl	.L0f0ce820
/*  f0ce810:	c4400168 */ 	lwc1	$f0,0x168($v0)
/*  f0ce814:	e4420170 */ 	swc1	$f2,0x170($v0)
/*  f0ce818:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0ce81c:	c4400168 */ 	lwc1	$f0,0x168($v0)
.L0f0ce820:
/*  f0ce820:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0ce824:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce828:	45020005 */ 	bc1fl	.L0f0ce840
/*  f0ce82c:	4602003c */ 	c.lt.s	$f0,$f2
/*  f0ce830:	e44c0168 */ 	swc1	$f12,0x168($v0)
/*  f0ce834:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0ce838:	c4400168 */ 	lwc1	$f0,0x168($v0)
/*  f0ce83c:	4602003c */ 	c.lt.s	$f0,$f2
.L0f0ce840:
/*  f0ce840:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce844:	45020004 */ 	bc1fl	.L0f0ce858
/*  f0ce848:	c4440170 */ 	lwc1	$f4,0x170($v0)
/*  f0ce84c:	e4420168 */ 	swc1	$f2,0x168($v0)
/*  f0ce850:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0ce854:	c4440170 */ 	lwc1	$f4,0x170($v0)
.L0f0ce858:
/*  f0ce858:	c426da0c */ 	lwc1	$f6,%lo(var7f1ada0c)($at)
/*  f0ce85c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0ce860:	e4480170 */ 	swc1	$f8,0x170($v0)
/*  f0ce864:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0ce868:	c44a0170 */ 	lwc1	$f10,0x170($v0)
/*  f0ce86c:	c4500174 */ 	lwc1	$f16,0x174($v0)
/*  f0ce870:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0ce874:	e4520170 */ 	swc1	$f18,0x170($v0)
/*  f0ce878:	8e180010 */ 	lw	$t8,0x10($s0)
/*  f0ce87c:	57000007 */ 	bnezl	$t8,.L0f0ce89c
/*  f0ce880:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0ce884:	8e190020 */ 	lw	$t9,0x20($s0)
/*  f0ce888:	57200004 */ 	bnezl	$t9,.L0f0ce89c
/*  f0ce88c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0ce890:	8c880284 */ 	lw	$t0,0x284($a0)
/*  f0ce894:	ad000178 */ 	sw	$zero,0x178($t0)
/*  f0ce898:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0ce89c:
/*  f0ce89c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0ce8a0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0ce8a4:	03e00008 */ 	jr	$ra
/*  f0ce8a8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ce8ac
/*  f0ce8ac:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0ce8b0:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0ce8b4:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0ce8b8:	3c013f40 */ 	lui	$at,0x3f40
/*  f0ce8bc:	44813000 */ 	mtc1	$at,$f6
/*  f0ce8c0:	c4440148 */ 	lwc1	$f4,0x148($v0)
/*  f0ce8c4:	8c8e0034 */ 	lw	$t6,0x34($a0)
/*  f0ce8c8:	3c017f1b */ 	lui	$at,%hi(var7f1ada10)
/*  f0ce8cc:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f0ce8d0:	19c0000e */ 	blez	$t6,.L0f0ce90c
/*  f0ce8d4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ce8d8:	c422da10 */ 	lwc1	$f2,%lo(var7f1ada10)($at)
/*  f0ce8dc:	8c820284 */ 	lw	$v0,0x284($a0)
.L0f0ce8e0:
/*  f0ce8e0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0ce8e4:	c4481b60 */ 	lwc1	$f8,0x1b60($v0)
/*  f0ce8e8:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0ce8ec:	46005400 */ 	add.s	$f16,$f10,$f0
/*  f0ce8f0:	e4501b60 */ 	swc1	$f16,0x1b60($v0)
/*  f0ce8f4:	8c8f0034 */ 	lw	$t7,0x34($a0)
/*  f0ce8f8:	006f082a */ 	slt	$at,$v1,$t7
/*  f0ce8fc:	5420fff8 */ 	bnezl	$at,.L0f0ce8e0
/*  f0ce900:	8c820284 */ 	lw	$v0,0x284($a0)
/*  f0ce904:	3c02800a */ 	lui	$v0,0x800a
/*  f0ce908:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
.L0f0ce90c:
/*  f0ce90c:	3c017f1b */ 	lui	$at,%hi(var7f1ada14)
/*  f0ce910:	c424da14 */ 	lwc1	$f4,%lo(var7f1ada14)($at)
/*  f0ce914:	c4521b60 */ 	lwc1	$f18,0x1b60($v0)
/*  f0ce918:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0ce91c:	03e00008 */ 	jr	$ra
/*  f0ce920:	e4460148 */ 	swc1	$f6,0x148($v0)
);

GLOBAL_ASM(
glabel func0f0ce924
/*  f0ce924:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f0ce928:	3c0f8007 */ 	lui	$t7,%hi(var80070ea8)
/*  f0ce92c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0ce930:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0ce934:	25ef0ea8 */ 	addiu	$t7,$t7,%lo(var80070ea8)
/*  f0ce938:	8de10000 */ 	lw	$at,0x0($t7)
/*  f0ce93c:	27ae0074 */ 	addiu	$t6,$sp,0x74
/*  f0ce940:	8de90004 */ 	lw	$t1,0x4($t7)
/*  f0ce944:	adc10000 */ 	sw	$at,0x0($t6)
/*  f0ce948:	8de10008 */ 	lw	$at,0x8($t7)
/*  f0ce94c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0ce950:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0ce954:	adc90004 */ 	sw	$t1,0x4($t6)
/*  f0ce958:	adc10008 */ 	sw	$at,0x8($t6)
/*  f0ce95c:	8d0a0034 */ 	lw	$t2,0x34($t0)
/*  f0ce960:	59400154 */ 	blezl	$t2,.L0f0ceeb4
/*  f0ce964:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0ce968:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0ce96c:	27a40070 */ 	addiu	$a0,$sp,0x70
/*  f0ce970:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f0ce974:	c444014c */ 	lwc1	$f4,0x14c($v0)
/*  f0ce978:	8c470150 */ 	lw	$a3,0x150($v0)
/*  f0ce97c:	2446017c */ 	addiu	$a2,$v0,0x17c
/*  f0ce980:	0fc32ea2 */ 	jal	func0f0cba88
/*  f0ce984:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f0ce988:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0ce98c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0ce990:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0ce994:	c7a80070 */ 	lwc1	$f8,0x70($sp)
/*  f0ce998:	3c017f1b */ 	lui	$at,%hi(var7f1ada18)
/*  f0ce99c:	c4460170 */ 	lwc1	$f6,0x170($v0)
/*  f0ce9a0:	c42cda18 */ 	lwc1	$f12,%lo(var7f1ada18)($at)
/*  f0ce9a4:	3c018007 */ 	lui	$at,0x8007
/*  f0ce9a8:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0ce9ac:	4480a000 */ 	mtc1	$zero,$f20
/*  f0ce9b0:	e44a0170 */ 	swc1	$f10,0x170($v0)
/*  f0ce9b4:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0ce9b8:	c7a6006c */ 	lwc1	$f6,0x6c($sp)
/*  f0ce9bc:	c4440168 */ 	lwc1	$f4,0x168($v0)
/*  f0ce9c0:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0ce9c4:	e4480168 */ 	swc1	$f8,0x168($v0)
/*  f0ce9c8:	c42a5c24 */ 	lwc1	$f10,0x5c24($at)
/*  f0ce9cc:	3c013f00 */ 	lui	$at,0x3f00
/*  f0ce9d0:	44812000 */ 	mtc1	$at,$f4
/*  f0ce9d4:	c50e004c */ 	lwc1	$f14,0x4c($t0)
/*  f0ce9d8:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0ce9dc:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f0ce9e0:	3c013f40 */ 	lui	$at,0x3f40
/*  f0ce9e4:	c4400168 */ 	lwc1	$f0,0x168($v0)
/*  f0ce9e8:	460e3082 */ 	mul.s	$f2,$f6,$f14
/*  f0ce9ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ce9f0:	46020202 */ 	mul.s	$f8,$f0,$f2
/*  f0ce9f4:	e7a80088 */ 	swc1	$f8,0x88($sp)
/*  f0ce9f8:	460c0402 */ 	mul.s	$f16,$f0,$f12
/*  f0ce9fc:	c44a0148 */ 	lwc1	$f10,0x148($v0)
/*  f0cea00:	c4520170 */ 	lwc1	$f18,0x170($v0)
/*  f0cea04:	44810000 */ 	mtc1	$at,$f0
/*  f0cea08:	460c5102 */ 	mul.s	$f4,$f10,$f12
/*  f0cea0c:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0cea10:	e7a40060 */ 	swc1	$f4,0x60($sp)
/*  f0cea14:	45000002 */ 	bc1f	.L0f0cea20
/*  f0cea18:	c7a60060 */ 	lwc1	$f6,0x60($sp)
/*  f0cea1c:	46008407 */ 	neg.s	$f16,$f16
.L0f0cea20:
/*  f0cea20:	4614903c */ 	c.lt.s	$f18,$f20
/*  f0cea24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cea28:	45020003 */ 	bc1fl	.L0f0cea38
/*  f0cea2c:	4614303c */ 	c.lt.s	$f6,$f20
/*  f0cea30:	46009487 */ 	neg.s	$f18,$f18
/*  f0cea34:	4614303c */ 	c.lt.s	$f6,$f20
.L0f0cea38:
/*  f0cea38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cea3c:	45020004 */ 	bc1fl	.L0f0cea50
/*  f0cea40:	4610903c */ 	c.lt.s	$f18,$f16
/*  f0cea44:	46003207 */ 	neg.s	$f8,$f6
/*  f0cea48:	e7a80060 */ 	swc1	$f8,0x60($sp)
/*  f0cea4c:	4610903c */ 	c.lt.s	$f18,$f16
.L0f0cea50:
/*  f0cea50:	46009306 */ 	mov.s	$f12,$f18
/*  f0cea54:	c7aa0060 */ 	lwc1	$f10,0x60($sp)
/*  f0cea58:	45020003 */ 	bc1fl	.L0f0cea68
/*  f0cea5c:	460a603c */ 	c.lt.s	$f12,$f10
/*  f0cea60:	46008306 */ 	mov.s	$f12,$f16
/*  f0cea64:	460a603c */ 	c.lt.s	$f12,$f10
.L0f0cea68:
/*  f0cea68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cea6c:	45020003 */ 	bc1fl	.L0f0cea7c
/*  f0cea70:	460c003e */ 	c.le.s	$f0,$f12
/*  f0cea74:	46005306 */ 	mov.s	$f12,$f10
/*  f0cea78:	460c003e */ 	c.le.s	$f0,$f12
.L0f0cea7c:
/*  f0cea7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cea80:	4502000b */ 	bc1fl	.L0f0ceab0
/*  f0cea84:	460c0201 */ 	sub.s	$f8,$f0,$f12
/*  f0cea88:	46006101 */ 	sub.s	$f4,$f12,$f0
/*  f0cea8c:	3c014461 */ 	lui	$at,0x4461
/*  f0cea90:	44814000 */ 	mtc1	$at,$f8
/*  f0cea94:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f0cea98:	c4440198 */ 	lwc1	$f4,0x198($v0)
/*  f0cea9c:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f0ceaa0:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f0ceaa4:	10000009 */ 	beqz	$zero,.L0f0ceacc
/*  f0ceaa8:	e4460198 */ 	swc1	$f6,0x198($v0)
/*  f0ceaac:	460c0201 */ 	sub.s	$f8,$f0,$f12
.L0f0ceab0:
/*  f0ceab0:	3c017f1b */ 	lui	$at,%hi(var7f1ada1c)
/*  f0ceab4:	c42ada1c */ 	lwc1	$f10,%lo(var7f1ada1c)($at)
/*  f0ceab8:	460e4102 */ 	mul.s	$f4,$f8,$f14
/*  f0ceabc:	c4480198 */ 	lwc1	$f8,0x198($v0)
/*  f0ceac0:	460a2183 */ 	div.s	$f6,$f4,$f10
/*  f0ceac4:	46064101 */ 	sub.s	$f4,$f8,$f6
/*  f0ceac8:	e4440198 */ 	swc1	$f4,0x198($v0)
.L0f0ceacc:
/*  f0ceacc:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0cead0:	c4400198 */ 	lwc1	$f0,0x198($v0)
/*  f0cead4:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0cead8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceadc:	45020005 */ 	bc1fl	.L0f0ceaf4
/*  f0ceae0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ceae4:	e4540198 */ 	swc1	$f20,0x198($v0)
/*  f0ceae8:	1000000c */ 	beqz	$zero,.L0f0ceb1c
/*  f0ceaec:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0ceaf0:	3c013f80 */ 	lui	$at,0x3f80
.L0f0ceaf4:
/*  f0ceaf4:	44815000 */ 	mtc1	$at,$f10
/*  f0ceaf8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ceafc:	4600503c */ 	c.lt.s	$f10,$f0
/*  f0ceb00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceb04:	45020006 */ 	bc1fl	.L0f0ceb20
/*  f0ceb08:	c44e0170 */ 	lwc1	$f14,0x170($v0)
/*  f0ceb0c:	44814000 */ 	mtc1	$at,$f8
/*  f0ceb10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceb14:	e4480198 */ 	swc1	$f8,0x198($v0)
/*  f0ceb18:	8d020284 */ 	lw	$v0,0x284($t0)
.L0f0ceb1c:
/*  f0ceb1c:	c44e0170 */ 	lwc1	$f14,0x170($v0)
.L0f0ceb20:
/*  f0ceb20:	e7ac005c */ 	swc1	$f12,0x5c($sp)
/*  f0ceb24:	0fc33195 */ 	jal	func0f0cc654
/*  f0ceb28:	8fa60088 */ 	lw	$a2,0x88($sp)
/*  f0ceb2c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0ceb30:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0ceb34:	c7ac005c */ 	lwc1	$f12,0x5c($sp)
/*  f0ceb38:	8d0b0284 */ 	lw	$t3,0x284($t0)
/*  f0ceb3c:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f0ceb40:	e56c00cc */ 	swc1	$f12,0xcc($t3)
/*  f0ceb44:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0ceb48:	c44003c0 */ 	lwc1	$f0,0x3c0($v0)
/*  f0ceb4c:	c44203c8 */ 	lwc1	$f2,0x3c8($v0)
/*  f0ceb50:	e7a00084 */ 	swc1	$f0,0x84($sp)
/*  f0ceb54:	0fc41b99 */ 	jal	cheatIsActive
/*  f0ceb58:	e7a20080 */ 	swc1	$f2,0x80($sp)
/*  f0ceb5c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0ceb60:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0ceb64:	c7a00084 */ 	lwc1	$f0,0x84($sp)
/*  f0ceb68:	10400007 */ 	beqz	$v0,.L0f0ceb88
/*  f0ceb6c:	c7a20080 */ 	lwc1	$f2,0x80($sp)
/*  f0ceb70:	3c017f1b */ 	lui	$at,%hi(var7f1ada20)
/*  f0ceb74:	c42cda20 */ 	lwc1	$f12,%lo(var7f1ada20)($at)
/*  f0ceb78:	460c0002 */ 	mul.s	$f0,$f0,$f12
/*  f0ceb7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceb80:	460c1082 */ 	mul.s	$f2,$f2,$f12
/*  f0ceb84:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ceb88:
/*  f0ceb88:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0ceb8c:	c50e004c */ 	lwc1	$f14,0x4c($t0)
/*  f0ceb90:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f0ceb94:	c446036c */ 	lwc1	$f6,0x36c($v0)
/*  f0ceb98:	c44a0374 */ 	lwc1	$f10,0x374($v0)
/*  f0ceb9c:	46061102 */ 	mul.s	$f4,$f2,$f6
/*  f0ceba0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceba4:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0ceba8:	46082181 */ 	sub.s	$f6,$f4,$f8
/*  f0cebac:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f0cebb0:	460e3282 */ 	mul.s	$f10,$f6,$f14
/*  f0cebb4:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0cebb8:	e7a80074 */ 	swc1	$f8,0x74($sp)
/*  f0cebbc:	c4460374 */ 	lwc1	$f6,0x374($v0)
/*  f0cebc0:	c44a036c */ 	lwc1	$f10,0x36c($v0)
/*  f0cebc4:	46061102 */ 	mul.s	$f4,$f2,$f6
/*  f0cebc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cebcc:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0cebd0:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f0cebd4:	c7a4007c */ 	lwc1	$f4,0x7c($sp)
/*  f0cebd8:	460e3282 */ 	mul.s	$f10,$f6,$f14
/*  f0cebdc:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0cebe0:	0fc32ed2 */ 	jal	func0f0cbb48
/*  f0cebe4:	e7a8007c */ 	swc1	$f8,0x7c($sp)
/*  f0cebe8:	0fc47b82 */ 	jal	func0f11ee08
/*  f0cebec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cebf0:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0cebf4:	1040001f */ 	beqz	$v0,.L0f0cec74
/*  f0cebf8:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0cebfc:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0cec00:	c50e004c */ 	lwc1	$f14,0x4c($t0)
/*  f0cec04:	3c014120 */ 	lui	$at,0x4120
/*  f0cec08:	c446036c */ 	lwc1	$f6,0x36c($v0)
/*  f0cec0c:	c4440170 */ 	lwc1	$f4,0x170($v0)
/*  f0cec10:	c4480374 */ 	lwc1	$f8,0x374($v0)
/*  f0cec14:	44810000 */ 	mtc1	$at,$f0
/*  f0cec18:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f0cec1c:	c4460168 */ 	lwc1	$f6,0x168($v0)
/*  f0cec20:	46064102 */ 	mul.s	$f4,$f8,$f6
/*  f0cec24:	46045201 */ 	sub.s	$f8,$f10,$f4
/*  f0cec28:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f0cec2c:	460e4182 */ 	mul.s	$f6,$f8,$f14
/*  f0cec30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cec34:	46003282 */ 	mul.s	$f10,$f6,$f0
/*  f0cec38:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0cec3c:	e7a80074 */ 	swc1	$f8,0x74($sp)
/*  f0cec40:	c4440170 */ 	lwc1	$f4,0x170($v0)
/*  f0cec44:	c4460374 */ 	lwc1	$f6,0x374($v0)
/*  f0cec48:	c448036c */ 	lwc1	$f8,0x36c($v0)
/*  f0cec4c:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f0cec50:	c4460168 */ 	lwc1	$f6,0x168($v0)
/*  f0cec54:	46064102 */ 	mul.s	$f4,$f8,$f6
/*  f0cec58:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f0cec5c:	c7a4007c */ 	lwc1	$f4,0x7c($sp)
/*  f0cec60:	460e4182 */ 	mul.s	$f6,$f8,$f14
/*  f0cec64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cec68:	46003282 */ 	mul.s	$f10,$f6,$f0
/*  f0cec6c:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0cec70:	e7a8007c */ 	swc1	$f8,0x7c($sp)
.L0f0cec74:
/*  f0cec74:	0fc3382f */ 	jal	func0f0ce0bc
/*  f0cec78:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f0cec7c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0cec80:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0cec84:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0cec88:	8c4300bc */ 	lw	$v1,0xbc($v0)
/*  f0cec8c:	c4480318 */ 	lwc1	$f8,0x318($v0)
/*  f0cec90:	c4440310 */ 	lwc1	$f4,0x310($v0)
/*  f0cec94:	c46a0010 */ 	lwc1	$f10,0x10($v1)
/*  f0cec98:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f0cec9c:	c440036c */ 	lwc1	$f0,0x36c($v0)
/*  f0ceca0:	46085381 */ 	sub.s	$f14,$f10,$f8
/*  f0ceca4:	c4420374 */ 	lwc1	$f2,0x374($v0)
/*  f0ceca8:	46043301 */ 	sub.s	$f12,$f6,$f4
/*  f0cecac:	460e0182 */ 	mul.s	$f6,$f0,$f14
/*  f0cecb0:	46006107 */ 	neg.s	$f4,$f12
/*  f0cecb4:	46022282 */ 	mul.s	$f10,$f4,$f2
/*  f0cecb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cecbc:	460e1202 */ 	mul.s	$f8,$f2,$f14
/*  f0cecc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cecc4:	46006102 */ 	mul.s	$f4,$f12,$f0
/*  f0cecc8:	460a3400 */ 	add.s	$f16,$f6,$f10
/*  f0ceccc:	c7aa007c */ 	lwc1	$f10,0x7c($sp)
/*  f0cecd0:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0cecd4:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f0cecd8:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f0cecdc:	e7a6004c */ 	swc1	$f6,0x4c($sp)
/*  f0cece0:	46002187 */ 	neg.s	$f6,$f4
/*  f0cece4:	46023182 */ 	mul.s	$f6,$f6,$f2
/*  f0cece8:	46064480 */ 	add.s	$f18,$f8,$f6
/*  f0cecec:	460a1202 */ 	mul.s	$f8,$f2,$f10
/*  f0cecf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cecf4:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0cecf8:	46149032 */ 	c.eq.s	$f18,$f20
/*  f0cecfc:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f0ced00:	45010019 */ 	bc1t	.L0f0ced68
/*  f0ced04:	e7aa0044 */ 	swc1	$f10,0x44($sp)
/*  f0ced08:	c440016c */ 	lwc1	$f0,0x16c($v0)
/*  f0ced0c:	46120102 */ 	mul.s	$f4,$f0,$f18
/*  f0ced10:	4604a03c */ 	c.lt.s	$f20,$f4
/*  f0ced14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ced18:	45020014 */ 	bc1fl	.L0f0ced6c
/*  f0ced1c:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*  f0ced20:	46128403 */ 	div.s	$f16,$f16,$f18
/*  f0ced24:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ced28:	4614803e */ 	c.le.s	$f16,$f20
/*  f0ced2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ced30:	45020005 */ 	bc1fl	.L0f0ced48
/*  f0ced34:	44814000 */ 	mtc1	$at,$f8
/*  f0ced38:	e454016c */ 	swc1	$f20,0x16c($v0)
/*  f0ced3c:	1000000a */ 	beqz	$zero,.L0f0ced68
/*  f0ced40:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0ced44:	44814000 */ 	mtc1	$at,$f8
.L0f0ced48:
/*  f0ced48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ced4c:	4608803c */ 	c.lt.s	$f16,$f8
/*  f0ced50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ced54:	45020005 */ 	bc1fl	.L0f0ced6c
/*  f0ced58:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*  f0ced5c:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f0ced60:	e446016c */ 	swc1	$f6,0x16c($v0)
/*  f0ced64:	8d020284 */ 	lw	$v0,0x284($t0)
.L0f0ced68:
/*  f0ced68:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
.L0f0ced6c:
/*  f0ced6c:	46145032 */ 	c.eq.s	$f10,$f20
/*  f0ced70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ced74:	4503001c */ 	bc1tl	.L0f0cede8
/*  f0ced78:	c4460148 */ 	lwc1	$f6,0x148($v0)
/*  f0ced7c:	c44019a4 */ 	lwc1	$f0,0x19a4($v0)
/*  f0ced80:	c7a8004c */ 	lwc1	$f8,0x4c($sp)
/*  f0ced84:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f0ced88:	4604a03c */ 	c.lt.s	$f20,$f4
/*  f0ced8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ced90:	45020015 */ 	bc1fl	.L0f0cede8
/*  f0ced94:	c4460148 */ 	lwc1	$f6,0x148($v0)
/*  f0ced98:	460a4183 */ 	div.s	$f6,$f8,$f10
/*  f0ced9c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0ceda0:	4614303e */ 	c.le.s	$f6,$f20
/*  f0ceda4:	e7a6004c */ 	swc1	$f6,0x4c($sp)
/*  f0ceda8:	c7a4004c */ 	lwc1	$f4,0x4c($sp)
/*  f0cedac:	45020005 */ 	bc1fl	.L0f0cedc4
/*  f0cedb0:	44814000 */ 	mtc1	$at,$f8
/*  f0cedb4:	e45419a4 */ 	swc1	$f20,0x19a4($v0)
/*  f0cedb8:	1000000a */ 	beqz	$zero,.L0f0cede4
/*  f0cedbc:	8d020284 */ 	lw	$v0,0x284($t0)
/*  f0cedc0:	44814000 */ 	mtc1	$at,$f8
.L0f0cedc4:
/*  f0cedc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cedc8:	4608203c */ 	c.lt.s	$f4,$f8
/*  f0cedcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cedd0:	45020005 */ 	bc1fl	.L0f0cede8
/*  f0cedd4:	c4460148 */ 	lwc1	$f6,0x148($v0)
/*  f0cedd8:	46040282 */ 	mul.s	$f10,$f0,$f4
/*  f0ceddc:	e44a19a4 */ 	swc1	$f10,0x19a4($v0)
/*  f0cede0:	8d020284 */ 	lw	$v0,0x284($t0)
.L0f0cede4:
/*  f0cede4:	c4460148 */ 	lwc1	$f6,0x148($v0)
.L0f0cede8:
/*  f0cede8:	3c017f1b */ 	lui	$at,%hi(var7f1ada24)
/*  f0cedec:	c424da24 */ 	lwc1	$f4,%lo(var7f1ada24)($at)
/*  f0cedf0:	e7a60040 */ 	swc1	$f6,0x40($sp)
/*  f0cedf4:	c448015c */ 	lwc1	$f8,0x15c($v0)
/*  f0cedf8:	c44a00cc */ 	lwc1	$f10,0xcc($v0)
/*  f0cedfc:	46044083 */ 	div.s	$f2,$f8,$f4
/*  f0cee00:	e7aa0038 */ 	swc1	$f10,0x38($sp)
/*  f0cee04:	0fc4505b */ 	jal	func0f11416c
/*  f0cee08:	e7a2003c */ 	swc1	$f2,0x3c($sp)
/*  f0cee0c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0cee10:	44817000 */ 	mtc1	$at,$f14
/*  f0cee14:	c7a2003c */ 	lwc1	$f2,0x3c($sp)
/*  f0cee18:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0cee1c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0cee20:	4602703c */ 	c.lt.s	$f14,$f2
/*  f0cee24:	46000306 */ 	mov.s	$f12,$f0
/*  f0cee28:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0cee2c:	8fa70040 */ 	lw	$a3,0x40($sp)
/*  f0cee30:	45020004 */ 	bc1fl	.L0f0cee44
/*  f0cee34:	44817000 */ 	mtc1	$at,$f14
/*  f0cee38:	10000008 */ 	beqz	$zero,.L0f0cee5c
/*  f0cee3c:	46007086 */ 	mov.s	$f2,$f14
/*  f0cee40:	44817000 */ 	mtc1	$at,$f14
.L0f0cee44:
/*  f0cee44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cee48:	460e103c */ 	c.lt.s	$f2,$f14
/*  f0cee4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cee50:	45020003 */ 	bc1fl	.L0f0cee60
/*  f0cee54:	8d0c0284 */ 	lw	$t4,0x284($t0)
/*  f0cee58:	46007086 */ 	mov.s	$f2,$f14
.L0f0cee5c:
/*  f0cee5c:	8d0c0284 */ 	lw	$t4,0x284($t0)
.L0f0cee60:
/*  f0cee60:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0cee64:	44061000 */ 	mfc1	$a2,$f2
/*  f0cee68:	8d8d03ac */ 	lw	$t5,0x3ac($t4)
/*  f0cee6c:	c7ae0038 */ 	lwc1	$f14,0x38($sp)
/*  f0cee70:	15a10004 */ 	bne	$t5,$at,.L0f0cee84
/*  f0cee74:	3c017f1b */ 	lui	$at,%hi(var7f1ada28)
/*  f0cee78:	c426da28 */ 	lwc1	$f6,%lo(var7f1ada28)($at)
/*  f0cee7c:	46060302 */ 	mul.s	$f12,$f0,$f6
/*  f0cee80:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cee84:
/*  f0cee84:	0fc27637 */ 	jal	func0f09d8dc
/*  f0cee88:	e7b40010 */ 	swc1	$f20,0x10($sp)
/*  f0cee8c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f0cee90:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f0cee94:	8d190284 */ 	lw	$t9,0x284($t0)
/*  f0cee98:	3c017f1b */ 	lui	$at,%hi(var7f1ada2c)
/*  f0cee9c:	c424da2c */ 	lwc1	$f4,%lo(var7f1ada2c)($at)
/*  f0ceea0:	c7280158 */ 	lwc1	$f8,0x158($t9)
/*  f0ceea4:	46044302 */ 	mul.s	$f12,$f8,$f4
/*  f0ceea8:	0fc288a4 */ 	jal	func0f0a2290
/*  f0ceeac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceeb0:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0ceeb4:
/*  f0ceeb4:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0ceeb8:	27bd0090 */ 	addiu	$sp,$sp,0x90
/*  f0ceebc:	03e00008 */ 	jr	$ra
/*  f0ceec0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ceec4
/*  f0ceec4:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0ceec8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0ceecc:	0fc33840 */ 	jal	func0f0ce100
/*  f0ceed0:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0ceed4:	0fc337bc */ 	jal	func0f0cdef0
/*  f0ceed8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceedc:	0fc32fd4 */ 	jal	func0f0cbf50
/*  f0ceee0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceee4:	0fc33a49 */ 	jal	func0f0ce924
/*  f0ceee8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceeec:	0fc3385e */ 	jal	func0f0ce178
/*  f0ceef0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceef4:	0fc3386b */ 	jal	func0f0ce1ac
/*  f0ceef8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceefc:	3c10800a */ 	lui	$s0,0x800a
/*  f0cef00:	8e10a244 */ 	lw	$s0,-0x5dbc($s0)
/*  f0cef04:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0cef08:	8e0600bc */ 	lw	$a2,0xbc($s0)
/*  f0cef0c:	84ce0028 */ 	lh	$t6,0x28($a2)
/*  f0cef10:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0cef14:	50ae0018 */ 	beql	$a1,$t6,.L0f0cef78
/*  f0cef18:	8e091b5c */ 	lw	$t1,0x1b5c($s0)
/*  f0cef1c:	860419b0 */ 	lh	$a0,0x19b0($s0)
/*  f0cef20:	84c30028 */ 	lh	$v1,0x28($a2)
.L0f0cef24:
/*  f0cef24:	54830010 */ 	bnel	$a0,$v1,.L0f0cef68
/*  f0cef28:	8443002a */ 	lh	$v1,0x2a($v0)
/*  f0cef2c:	0fc19711 */ 	jal	func0f065c44
/*  f0cef30:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0cef34:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0cef38:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0cef3c:	8c500284 */ 	lw	$s0,0x284($v0)
/*  f0cef40:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0cef44:	860f19b0 */ 	lh	$t7,0x19b0($s0)
/*  f0cef48:	8e1800bc */ 	lw	$t8,0xbc($s0)
/*  f0cef4c:	a70f0028 */ 	sh	$t7,0x28($t8)
/*  f0cef50:	8c590284 */ 	lw	$t9,0x284($v0)
/*  f0cef54:	8f2800bc */ 	lw	$t0,0xbc($t9)
/*  f0cef58:	a505002a */ 	sh	$a1,0x2a($t0)
/*  f0cef5c:	10000005 */ 	beqz	$zero,.L0f0cef74
/*  f0cef60:	8c500284 */ 	lw	$s0,0x284($v0)
/*  f0cef64:	8443002a */ 	lh	$v1,0x2a($v0)
.L0f0cef68:
/*  f0cef68:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0cef6c:	14a3ffed */ 	bne	$a1,$v1,.L0f0cef24
/*  f0cef70:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cef74:
/*  f0cef74:	8e091b5c */ 	lw	$t1,0x1b5c($s0)
.L0f0cef78:
/*  f0cef78:	24010035 */ 	addiu	$at,$zero,0x35
/*  f0cef7c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cef80:	8d220004 */ 	lw	$v0,0x4($t1)
/*  f0cef84:	90430003 */ 	lbu	$v1,0x3($v0)
/*  f0cef88:	00402025 */ 	or	$a0,$v0,$zero
/*  f0cef8c:	54610004 */ 	bnel	$v1,$at,.L0f0cefa0
/*  f0cef90:	24010033 */ 	addiu	$at,$zero,0x33
/*  f0cef94:	10000005 */ 	beqz	$zero,.L0f0cefac
/*  f0cef98:	2445005c */ 	addiu	$a1,$v0,0x5c
/*  f0cef9c:	24010033 */ 	addiu	$at,$zero,0x33
.L0f0cefa0:
/*  f0cefa0:	14610002 */ 	bne	$v1,$at,.L0f0cefac
/*  f0cefa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cefa8:	2445005c */ 	addiu	$a1,$v0,0x5c
.L0f0cefac:
/*  f0cefac:	10a00005 */ 	beqz	$a1,.L0f0cefc4
/*  f0cefb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cefb4:	0fc1c52e */ 	jal	func0f0714b8
/*  f0cefb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cefbc:	3c10800a */ 	lui	$s0,0x800a
/*  f0cefc0:	8e10a244 */ 	lw	$s0,-0x5dbc($s0)
.L0f0cefc4:
/*  f0cefc4:	0fc32e31 */ 	jal	func0f0cb8c4
/*  f0cefc8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0cefcc:	3c0a800a */ 	lui	$t2,0x800a
/*  f0cefd0:	8d4aa244 */ 	lw	$t2,-0x5dbc($t2)
/*  f0cefd4:	8d4b00bc */ 	lw	$t3,0xbc($t2)
/*  f0cefd8:	0fc257d8 */ 	jal	objectiveCheckRoomEntered
/*  f0cefdc:	85640028 */ 	lh	$a0,0x28($t3)
/*  f0cefe0:	3c0c800a */ 	lui	$t4,0x800a
/*  f0cefe4:	8d8ca244 */ 	lw	$t4,-0x5dbc($t4)
/*  f0cefe8:	8d8400bc */ 	lw	$a0,0xbc($t4)
/*  f0cefec:	0fc33067 */ 	jal	func0f0cc19c
/*  f0ceff0:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0ceff4:	0fc307fd */ 	jal	func0f0c1ff4
/*  f0ceff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ceffc:	0fc23064 */ 	jal	func0f08c190
/*  f0cf000:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf004:	3c0d800a */ 	lui	$t5,0x800a
/*  f0cf008:	8dada244 */ 	lw	$t5,-0x5dbc($t5)
/*  f0cf00c:	8da21b5c */ 	lw	$v0,0x1b5c($t5)
/*  f0cf010:	50400048 */ 	beqzl	$v0,.L0f0cf134
/*  f0cf014:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0cf018:	0fc1c4d8 */ 	jal	func0f071360
/*  f0cf01c:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f0cf020:	3c10800a */ 	lui	$s0,0x800a
/*  f0cf024:	8e10a244 */ 	lw	$s0,-0x5dbc($s0)
/*  f0cf028:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cf02c:	8e021b5c */ 	lw	$v0,0x1b5c($s0)
/*  f0cf030:	c6080074 */ 	lwc1	$f8,0x74($s0)
/*  f0cf034:	c444000c */ 	lwc1	$f4,0xc($v0)
/*  f0cf038:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f0cf03c:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0cf040:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0cf044:	e7aa0030 */ 	swc1	$f10,0x30($sp)
/*  f0cf048:	0fc1905e */ 	jal	func0f064178
/*  f0cf04c:	8e0400bc */ 	lw	$a0,0xbc($s0)
/*  f0cf050:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f0cf054:	0fc1905e */ 	jal	func0f064178
/*  f0cf058:	00002825 */ 	or	$a1,$zero,$zero
/*  f0cf05c:	3c10800a */ 	lui	$s0,0x800a
/*  f0cf060:	8e10a244 */ 	lw	$s0,-0x5dbc($s0)
/*  f0cf064:	3c017f1b */ 	lui	$at,%hi(var7f1ada30)
/*  f0cf068:	c430da30 */ 	lwc1	$f16,%lo(var7f1ada30)($at)
/*  f0cf06c:	c6000078 */ 	lwc1	$f0,0x78($s0)
/*  f0cf070:	3c01c2c8 */ 	lui	$at,0xc2c8
/*  f0cf074:	c7a20030 */ 	lwc1	$f2,0x30($sp)
/*  f0cf078:	4610003e */ 	c.le.s	$f0,$f16
/*  f0cf07c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf080:	45010021 */ 	bc1t	.L0f0cf108
/*  f0cf084:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf088:	44819000 */ 	mtc1	$at,$f18
/*  f0cf08c:	3c0142c8 */ 	lui	$at,0x42c8
/*  f0cf090:	4612103c */ 	c.lt.s	$f2,$f18
/*  f0cf094:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf098:	4501001b */ 	bc1t	.L0f0cf108
/*  f0cf09c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf0a0:	44812000 */ 	mtc1	$at,$f4
/*  f0cf0a4:	3c014248 */ 	lui	$at,0x4248
/*  f0cf0a8:	4602203c */ 	c.lt.s	$f4,$f2
/*  f0cf0ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf0b0:	45010015 */ 	bc1t	.L0f0cf108
/*  f0cf0b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf0b8:	c6060074 */ 	lwc1	$f6,0x74($s0)
/*  f0cf0bc:	44814000 */ 	mtc1	$at,$f8
/*  f0cf0c0:	240e003f */ 	addiu	$t6,$zero,0x3f
/*  f0cf0c4:	240f000c */ 	addiu	$t7,$zero,0xc
/*  f0cf0c8:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0cf0cc:	460a003c */ 	c.lt.s	$f0,$f10
/*  f0cf0d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf0d4:	4501000c */ 	bc1t	.L0f0cf108
/*  f0cf0d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf0dc:	8e0300bc */ 	lw	$v1,0xbc($s0)
/*  f0cf0e0:	8e021b5c */ 	lw	$v0,0x1b5c($s0)
/*  f0cf0e4:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0cf0e8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0cf0ec:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f0cf0f0:	24650028 */ 	addiu	$a1,$v1,0x28
/*  f0cf0f4:	24460008 */ 	addiu	$a2,$v0,0x8
/*  f0cf0f8:	0c00b70f */ 	jal	hasLineOfSight
/*  f0cf0fc:	24470028 */ 	addiu	$a3,$v0,0x28
/*  f0cf100:	14400003 */ 	bnez	$v0,.L0f0cf110
/*  f0cf104:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0cf108:
/*  f0cf108:	0fc31f4c */ 	jal	currentPlayerSetMoveMode
/*  f0cf10c:	00002025 */ 	or	$a0,$zero,$zero
.L0f0cf110:
/*  f0cf110:	3c18800a */ 	lui	$t8,0x800a
/*  f0cf114:	8f18a244 */ 	lw	$t8,-0x5dbc($t8)
/*  f0cf118:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0cf11c:	0fc1905e */ 	jal	func0f064178
/*  f0cf120:	8f0400bc */ 	lw	$a0,0xbc($t8)
/*  f0cf124:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f0cf128:	0fc1905e */ 	jal	func0f064178
/*  f0cf12c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0cf130:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0cf134:
/*  f0cf134:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0cf138:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f0cf13c:	03e00008 */ 	jr	$ra
/*  f0cf140:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf144:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf148:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0cf14c:	00000000 */ 	sll	$zero,$zero,0x0
);
