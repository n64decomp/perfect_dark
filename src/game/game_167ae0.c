#include <ultra64.h>
#include "constants.h"
#include "game/bondmove.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/debug.h"
#include "game/dlights.h"
#include "game/game_005fd0.h"
#include "game/game_006bd0.h"
#include "game/game_00b480.h"
#include "game/game_00b820.h"
#include "game/game_00c240.h"
#include "game/game_00c490.h"
#include "game/game_0108d0.h"
#include "game/game_0109d0.h"
#include "game/game_010b20.h"
#include "game/game_011110.h"
#include "game/game_012450.h"
#include "game/game_0125a0.h"
#include "game/game_013010.h"
#include "game/sparksreset.h"
#include "game/weatherallocate.h"
#include "game/game_013540.h"
#include "game/game_013550.h"
#include "game/game_013cf0.h"
#include "game/game_0147a0.h"
#include "game/game_0147d0.h"
#include "game/game_014f10.h"
#include "game/game_015010.h"
#include "game/game_0150a0.h"
#include "game/game_0151f0.h"
#include "game/game_015260.h"
#include "game/game_015270.h"
#include "game/game_015280.h"
#include "game/game_015330.h"
#include "game/game_0153f0.h"
#include "game/game_015400.h"
#include "game/game_015410.h"
#include "game/game_015420.h"
#include "game/game_015470.h"
#include "game/title.h"
#include "game/game_01b0a0.h"
#include "game/game_01bea0.h"
#include "game/weathertick.h"
#include "game/game_01d860.h"
#include "game/game_01d990.h"
#include "game/game_01d9f0.h"
#include "game/game_01de30.h"
#include "game/chr/chr.h"
#include "game/game_0601b0.h"
#include "game/game_095320.h"
#include "game/game_097ba0.h"
#include "game/game_0abe70.h"
#include "game/game_0b0420.h"
#include "game/game_0b28d0.h"
#include "game/game_0b63b0.h"
#include "game/game_0d4690.h"
#include "game/game_0dcdb0.h"
#include "game/game_0f09f0.h"
#include "game/game_0fd660.h"
#include "game/game_107fb0.h"
#include "game/game_10c9c0.h"
#include "game/game_11f000.h"
#include "game/game_127910.h"
#include "game/game_129210.h"
#include "game/explosion.h"
#include "game/game_12f6c0.h"
#include "game/weather.h"
#include "game/game_135c70.h"
#include "game/game_1371b0.h"
#include "game/game_13c510.h"
#include "game/game_141820.h"
#include "game/game_150820.h"
#include "game/game_1531a0.h"
#include "game/game_157db0.h"
#include "game/game_165670.h"
#include "game/game_167ae0.h"
#include "game/music.h"
#include "game/game_16e810.h"
#include "game/game_176080.h"
#include "game/game_179060.h"
#include "game/game_17f930.h"
#include "game/game_19aa80.h"
#include "game/training.h"
#include "game/lang.h"
#include "game/mplayer.h"
#include "game/pak/pak.h"
#include "game/propobj.h"
#include "game/sparkstick.h"
#include "game/splat.h"
#include "game/utils.h"
#include "game/wallhit.h"
#include "gvars/gvars.h"
#include "lib/lib_06440.h"
#include "lib/lib_09660.h"
#include "lib/main.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_11420.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_13900.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "lib/lib_317f0.h"
#include "lib/lib_4a360.h"
#include "types.h"

u32 var80084010 = 0;
bool var80084014 = false;
f32 var80084018 = 1;
u32 var8008401c = 0x00000001;

s32 g_Difficulty = 0;

s32 g_StageTimeElapsed = 0;
s32 g_MpTimeLimit = 36000;
s32 g_MpScoreLimit = 10;
s32 g_MpTeamScoreLimit = 20;
struct audiohandle *g_MiscAudioHandle = NULL;
s32 g_NumReasonsToEndMpMatch = 0;
f32 g_StageTimeElapsed60f = 0;
bool var80084040 = true;
u32 g_BoostAndSlayerSounds[] = {0x05c8, 0x8068, 0x01c8};
u32 var80084050 = 0;

s16 g_FadeNumFrames = 0;
f32 g_FadeFrac = -1;
u32 g_FadePrevColour = 0;
u32 g_FadeColour = 0;
s16 g_FadeDelay = 0;

u32 getVar80084040(void)
{
	return var80084040;
}

void setVar80084040(u32 value)
{
	var80084040 = value;
}

void func0f167af8(void)
{
	g_Vars.unk000320 = 0;
	g_Vars.unk0004d8 = -1;
}

void boostAndSlayerSfxStopAll(void)
{
	s32 i;

	for (i = 0; i != 3; i++) {
		g_BoostAndSlayerAudioHandles[i] = NULL;
		g_BoostAndSlayerActiveTypes[i] = -1;
	}
}

s32 boostAndSlayerSfxGetIndex(u32 type)
{
	s32 i;

	for (i = 0; i != 3; i++) {
		if (g_BoostAndSlayerActiveTypes[i] == type) {
			return i;
		}
	}

	return -1;
}

void boostAndSlayerSfxSetEnabled(u32 type, bool enable)
{
	if (enable) {
		if (boostAndSlayerSfxGetIndex(type) == -1) {
			s32 index = boostAndSlayerSfxGetIndex(-1);

			if (index != -1 && g_BoostAndSlayerAudioHandles[index] == NULL) {
				audioStart(var80095200, g_BoostAndSlayerSounds[type], &g_BoostAndSlayerAudioHandles[index], -1, -1, -1, -1, -1);
				g_BoostAndSlayerActiveTypes[index] = type;
			}
		}
	} else {
		u32 stack;
		s32 index = boostAndSlayerSfxGetIndex(type);

		if (index != -1) {
			audioStop(g_BoostAndSlayerAudioHandles[index]);
			g_BoostAndSlayerActiveTypes[index] = -1;
		}
	}
}

void boostAndSlayerSfxUpdate(void)
{
	s32 i;

	if (g_Vars.lvupdate240 == 0) {
		for (i = 0; i != 3; i++) {
			boostAndSlayerSfxSetEnabled(i, false);
		}
	} else {
		bool usingboost = g_Vars.speedpillon
			&& getEffectiveSlowMotion() == SLOWMOTION_OFF
			&& g_Vars.in_cutscene == false;
		bool usingrocket;

		boostAndSlayerSfxSetEnabled(0, usingboost);

		usingrocket = false;

		for (i = 0; i < PLAYERCOUNT(); i++) {
			if (g_Vars.players[i]->visionmode == VISIONMODE_SLAYERROCKET) {
				usingrocket = true;
			}
		}

		boostAndSlayerSfxSetEnabled(1, usingrocket);
		boostAndSlayerSfxSetEnabled(2, usingrocket);
	}

	if (g_Vars.lvupdate240 == 0 && g_MiscAudioHandle && func000337f0(g_MiscAudioHandle)) {
		audioStop(g_MiscAudioHandle);
	}
}

void func0f167e7c(s32 stagenum)
{
	fadeCancel();

	var80084014 = false;
	var80084010 = 0;

	func00013900();

	g_Vars.unk0004d8 = 10;
	g_Vars.unk0004d1 = 0;
	g_Vars.unk0004d0 = 0;
	g_Vars.stagenum = stagenum;

	cheatsActivate();

	var80084040 = true;
	g_Vars.lvframenum = 0;
	var80084050 = 0;

	g_Vars.lvframe60 = 0;
	g_Vars.lvupdate240 = 4;

	g_Vars.lvupdate240f = 1;
	g_Vars.lvupdate240frealprev = 1.0f;
	g_Vars.lvupdate240freal = g_Vars.lvupdate240frealprev;

	g_StageTimeElapsed = 0;
	g_StageTimeElapsed60f = 0;

	g_Vars.speedpilltime = 0;
	g_Vars.speedpillchange = 0;
	g_Vars.speedpillwant = 0;
	g_Vars.speedpillon = false;

	g_Vars.restartlevel = false;
	g_Vars.unk000478 = 0;
	g_Vars.unk000488 = 0;
	g_Vars.unk000440 = -1;
	g_Vars.unk000444 = -1;
	g_Vars.dontplaynrg = false;
	g_Vars.in_cutscene = 0;
	g_Vars.unk0004d3 = 0;
	g_Vars.unk0004d6 = 0;
	g_Vars.unk0004d7 = 0;

	g_MiscAudioHandle = NULL;

	func0f16d324();
	func0f011124(true);
	func0f013b80();
	func0f1735c0();
	fontsLoadForCurrentStage();
	hudmsgSystemInit();

	if (stagenum == STAGE_TEST_OLD) {
		func0f00b480();
	}

	if (stagenum == STAGE_TITLE) {
		func0f00b480();
	} else if (stagenum == STAGE_BOOTPAKMENU) {
		// empty
	} else if (stagenum == STAGE_CREDITS) {
		// empty
	} else if (stagenum == STAGE_4MBMENU) {
		// empty
	} else {
		s32 i;
		s32 j;

		stageLoadTiles();
		func0f15b534(g_Vars.stagenum);
		func0f15b908(g_Vars.stagenum);
		func0f0147a0(g_Vars.stagenum);

		if (g_Vars.normmplayerisrunning) {
			musicSetStageAndStartMusic(stagenum);
		} else {
			musicSetStage(stagenum);
		}

		if (g_Vars.normmplayerisrunning) {
			func0f188530();
		}

		if (g_Vars.mplayerisrunning == false) {
			g_Vars.playerstats[0].mpindex = 4;
			g_MpPlayers[4].base.unk45 = 0;
			g_MpPlayers[4].base.unk46 = 1;
		}

		for (i = 0; i != 4; i++) {
			g_Vars.playerstats[i].damagescale = 1;
			g_Vars.playerstats[i].drawplayercount = 0;
			g_Vars.playerstats[i].distance = 0;
			g_Vars.playerstats[i].backshotcount = 0;
			g_Vars.playerstats[i].armourcount = 0;
			g_Vars.playerstats[i].fastest2kills = 0x7fffffff;
			g_Vars.playerstats[i].slowest2kills = 0;
			g_Vars.playerstats[i].maxkills = 0;
			g_Vars.playerstats[i].maxsimulkills = 0;
			g_Vars.playerstats[i].longestlife = 0;
			g_Vars.playerstats[i].shortestlife = 0x7fffffff;
			g_Vars.playerstats[i].tokenheldtime = 0;
			g_Vars.playerstats[i].damreceived = 0;
			g_Vars.playerstats[i].damtransmitted = 0;

			for (j = 0; j != 4; j++) {
				g_Vars.playerstats[i].kills[j] = 0;
			}
		}
	}

	func0f18836c();
	func0002373c();
	func0f0109d0();
	func0f013ba0();
	func0f011110();
	func0f0108d0();
	func0f00eb64(stagenum);
	func0f18620c();
	func0f00c240();
	func0f00c490();
	func0f00b510();
	func0f00b820(stagenum);
	setupParseObjects(stagenum);
	tagsAllocatePtrs();
	func0f013010();
	func0f013130();
	sparksReset();
	weatherAllocate();
	boostAndSlayerSfxStopAll();

	switch (g_Vars.stagenum) {
	case STAGE_ESCAPE:
	case STAGE_EXTRACTION:
	case STAGE_INFILTRATION:
	case STAGE_DEFECTION:
	case STAGE_ATTACKSHIP:
	case STAGE_TEST_OLD:
		func0f1360e8();
		break;
	}

	func0f0099a4();
	func0f0147d0();
	func0f0147f8();
	func0f013540();
	func0f0139f0();
	frUnloadData();

	if (g_Vars.stagenum == STAGE_TITLE) {
		// empty
	} else if (stagenum == STAGE_BOOTPAKMENU) {
		setCurrentPlayerNum(0);
		func0f0f8c98();
	} else if (stagenum == STAGE_4MBMENU) {
		setCurrentPlayerNum(0);
		func0f0f8c98();
	} else if (stagenum == STAGE_CREDITS) {
		func0f13b4c4();
	} else {
		s32 i;

		func0f1777f8();
		func0f010b20();

		for (i = 0; i < PLAYERCOUNT(); i++) {
			setCurrentPlayerNum(i);
			g_Vars.currentplayer->usedowntime = 0;
			g_Vars.currentplayer->invdowntime = g_Vars.currentplayer->usedowntime;

			func0f0f8c98();
			func0f0fe848();
			currentPlayerInitGunsHeld();
			func0f010bb0();
			func0f0b77cc();
			currentPlayerInit();
			func0f0b802c();
			func0f012684();

			if (g_Vars.normmplayerisrunning && (g_MpSetup.options & MPOPTION_TEAMSENABLED)) {
				currentPlayerCalculateAiBuddyNums();
			}
		}

		func0f0b6764();
		func0f0b65f8();
		func0f001bdc();
		setCurrentPlayerNum(0);
	}

	if (g_Vars.lvmpbotlevel) {
		func0f187e70();
	}

	func0f11a2e4();
	func0000eadc();

	if (stagenum == STAGE_BOOTPAKMENU) {
		func0f10c970();
	}

	if (stagenum == STAGE_4MBMENU) {
		func0f10cb2c();
	}

	if (!IS4MB()) {
		func0f14a3c4();
	}

	func0f011124(false);
	var80084018 = 1;
	func00002560();
	soloSetPaused(0);

#if PIRACYCHECKS
	{
		u32 checksum = 0;
		s32 *i = (s32 *)&getEffectiveSlowMotion;
		s32 *end = (s32 *)&func0f16b96c;

		while (i < end) {
			checksum += *i;
			i++;
		}

		if (checksum != CHECKSUM_PLACEHOLDER) {
			u32 address = 0;
			u32 buffer[4];
			buffer[0] = 0xbb8b80bd;
			buffer[1] = 0xffffffff;
			buffer[2] = 0x020f0100;
			buffer[3] = 0xcd31100b;
			osEepromLongWrite(&var80099e78, address, (u8 *)&buffer, 0x10);
			var800a316c[2] = 0;
		}
	}
#endif
}

void fadeConfigure(u32 color, s16 num_frames)
{
	g_FadeNumFrames = num_frames;
	g_FadePrevColour = g_FadeColour;

	if (g_FadeNumFrames == 0) {
		g_FadeColour = color;
		g_FadeFrac = -1;
		return;
	}

	g_FadeFrac = 0;
	g_FadeColour = color;
	g_FadeDelay = 2;
}

Gfx *fadeRender(Gfx *gdl)
{
	u32 colour = g_FadeColour;
	u32 inset = 0;

	if (g_Vars.stagenum == STAGE_TEST_OLD) {
		inset = 61;
	}

	if (g_FadeFrac >= 0) {
		if (g_FadeDelay > 0) {
			g_FadeDelay--;
		} else {
			g_FadeFrac += g_Vars.diffframe60f / g_FadeNumFrames;

			if (g_FadeFrac >= 1) {
				g_FadeFrac = -1;
			}
		}
	}

	if (g_FadeFrac < 0) {
		if ((g_FadeColour & 0xff) == 0) {
			return gdl;
		}
	} else {
		colour = colourBlend(g_FadeColour, g_FadePrevColour, g_FadeFrac * 255);
	}

	if ((colour & 0xff) == 0) {
		return gdl;
	}

	gDPPipeSync(gdl++);
	gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
	gDPSetPrimColor(gdl++, 0, 0, colour);

	gDPFillRectangle(gdl++,
			viGetViewLeft(),
			viGetViewTop() + inset,
			viGetViewLeft() + viGetViewX() + 1,
			viGetViewTop() + viGetViewY() - inset + 2);

	return func0f153838(gdl);
}

bool fadeIsActive(void)
{
	return g_FadeFrac >= 0;
}

void fadeCancel(void)
{
	g_FadeNumFrames = 0;
	g_FadeFrac = -1;
	g_FadePrevColour = 0;
	g_FadeColour = 0;
	g_FadeDelay = 0;
}

bool threatCheckCmpFollow(struct threat *threat, s32 index)
{
	f32 sp76;
	f32 sp72;
	f32 sp68;
	f32 sp64;
	struct prop *prop = threat->prop;
	struct chrdata *chr;

	if (threat->prop && prop->chr) {
		switch (threat->prop->type) {
		case PROPTYPE_PLAYER:
			if (propGetPlayerNum(prop) == g_Vars.currentplayernum) {
				return false;
			}
			// fall through
		case PROPTYPE_CHR:
			chr = threat->prop->chr;

			if (chrIsDead(threat->prop->chr)) {
				if (index >= 0) {
					// Existing threat
					if (g_Vars.currentplayer->unk1b90[index] <= 128) {
						g_Vars.currentplayer->unk1b90[index] = 129;
					}

					if (g_Vars.currentplayer->unk1b90[index] >= 175) {
						threat->prop = NULL;
						return false;
					}
				} else {
					// Attempting to add a new threat, but chr is dead
					threat->prop = NULL;
					return false;
				}
			}

			if ((threat->prop->flags & PROPFLAG_02)
					&& (chr->chrflags & CHRCFLAG_NOAUTOAIM) == 0) {
				struct model *model = chr->model;
				sp72 = -1;
				sp76 = -1;
				sp64 = -2;
				sp68 = -2;

				if (modelSetRedBox(model, &sp64, &sp72, &sp68, &sp76)) {
					break;
				}
				return false;
			}
			return false;
		case PROPTYPE_OBJ:
		case PROPTYPE_WEAPON:
			if (threat->prop->flags & PROPFLAG_02) {
				struct defaultobj *obj = threat->prop->obj;
				struct model *model = obj->model;
				sp72 = -1;
				sp76 = -1;
				sp64 = -2;
				sp68 = -2;

				if (modelSetRedBox(model, &sp64, &sp72, &sp68, &sp76)) {
					break;
				}
				return false;
			}
			return false;
		case PROPTYPE_DOOR:
		case PROPTYPE_EYESPY:
		case PROPTYPE_EXPLOSION:
		case PROPTYPE_EFFECT:
		default:
			return false;
		}

		threat->unk04 = sp72 - 2;
		threat->unk08 = sp64 + 2;
		threat->unk06 = sp76 - 2;
		threat->unk0a = sp68 + 2;
	}

	return true;
}

GLOBAL_ASM(
glabel propFindThreats
.late_rodata
glabel var7f1b7800
.word propFindThreats+0x124 # f168c70
glabel var7f1b7804
.word propFindThreats+0x138 # f168c84
glabel var7f1b7808
.word propFindThreats+0x138 # f168c84
glabel var7f1b780c
.word propFindThreats+0x138 # f168c84
glabel var7f1b7810
.word propFindThreats+0x138 # f168c84
glabel var7f1b7814
.word propFindThreats+0x138 # f168c84
glabel var7f1b7818
.word propFindThreats+0x138 # f168c84
glabel var7f1b781c
.word propFindThreats+0x138 # f168c84
glabel var7f1b7820
.word propFindThreats+0x138 # f168c84
glabel var7f1b7824
.word propFindThreats+0x138 # f168c84
glabel var7f1b7828
.word propFindThreats+0x138 # f168c84
glabel var7f1b782c
.word propFindThreats+0x138 # f168c84
glabel var7f1b7830
.word propFindThreats+0x138 # f168c84
glabel var7f1b7834
.word propFindThreats+0x138 # f168c84
glabel var7f1b7838
.word propFindThreats+0x138 # f168c84
glabel var7f1b783c
.word propFindThreats+0x11c # f168c68
glabel var7f1b7840
.word propFindThreats+0x11c # f168c68
glabel var7f1b7844
.word propFindThreats+0x11c # f168c68
glabel var7f1b7848
.word propFindThreats+0x11c # f168c68
glabel var7f1b784c
.word propFindThreats+0x11c # f168c68
.text
/*  f168b4c:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f168b50:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f168b54:	00808025 */ 	or	$s0,$a0,$zero
/*  f168b58:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f168b5c:	afa5006c */ 	sw	$a1,0x6c($sp)
/*  f168b60:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f168b64:	afa70074 */ 	sw	$a3,0x74($sp)
/*  f168b68:	14a00009 */ 	bnez	$a1,.L0f168b90
/*  f168b6c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f168b70:	c4840014 */ 	lwc1	$f4,0x14($a0)
/*  f168b74:	44803000 */ 	mtc1	$zero,$f6
/*  f168b78:	00000000 */ 	nop
/*  f168b7c:	4606203c */ 	c.lt.s	$f4,$f6
/*  f168b80:	00000000 */ 	nop
/*  f168b84:	45020003 */ 	bc1fl	.L0f168b94
/*  f168b88:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f168b8c:	00001825 */ 	or	$v1,$zero,$zero
.L0f168b90:
/*  f168b90:	8e040004 */ 	lw	$a0,0x4($s0)
.L0f168b94:
/*  f168b94:	508000cc */ 	beqzl	$a0,.L0f168ec8
/*  f168b98:	8e04001c */ 	lw	$a0,0x1c($s0)
/*  f168b9c:	920f0001 */ 	lbu	$t7,0x1($s0)
/*  f168ba0:	31f80002 */ 	andi	$t8,$t7,0x2
/*  f168ba4:	530000c8 */ 	beqzl	$t8,.L0f168ec8
/*  f168ba8:	8e04001c */ 	lw	$a0,0x1c($s0)
/*  f168bac:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f168bb0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f168bb4:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f168bb8:	10410003 */ 	beq	$v0,$at,.L0f168bc8
/*  f168bbc:	00000000 */ 	nop
/*  f168bc0:	552200c1 */ 	bnel	$t1,$v0,.L0f168ec8
/*  f168bc4:	8e04001c */ 	lw	$a0,0x1c($s0)
.L0f168bc8:
/*  f168bc8:	106000be */ 	beqz	$v1,.L0f168ec4
/*  f168bcc:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f168bd0:	8c990018 */ 	lw	$t9,0x18($a0)
/*  f168bd4:	00004025 */ 	or	$t0,$zero,$zero
/*  f168bd8:	00801025 */ 	or	$v0,$a0,$zero
/*  f168bdc:	1080000b */ 	beqz	$a0,.L0f168c0c
/*  f168be0:	afb90044 */ 	sw	$t9,0x44($sp)
/*  f168be4:	904a0003 */ 	lbu	$t2,0x3($v0)
/*  f168be8:	2401000d */ 	addiu	$at,$zero,0xd
/*  f168bec:	15410007 */ 	bne	$t2,$at,.L0f168c0c
/*  f168bf0:	00000000 */ 	nop
/*  f168bf4:	8c4b000c */ 	lw	$t3,0xc($v0)
/*  f168bf8:	3c01a000 */ 	lui	$at,0xa000
/*  f168bfc:	01616024 */ 	and	$t4,$t3,$at
/*  f168c00:	15800002 */ 	bnez	$t4,.L0f168c0c
/*  f168c04:	00000000 */ 	nop
/*  f168c08:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f168c0c:
/*  f168c0c:	10400006 */ 	beqz	$v0,.L0f168c28
/*  f168c10:	00801825 */ 	or	$v1,$a0,$zero
/*  f168c14:	844d0004 */ 	lh	$t5,0x4($v0)
/*  f168c18:	240100c8 */ 	addiu	$at,$zero,0xc8
/*  f168c1c:	15a10002 */ 	bne	$t5,$at,.L0f168c28
/*  f168c20:	00000000 */ 	nop
/*  f168c24:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f168c28:
/*  f168c28:	10800016 */ 	beqz	$a0,.L0f168c84
/*  f168c2c:	84450004 */ 	lh	$a1,0x4($v0)
/*  f168c30:	908e0003 */ 	lbu	$t6,0x3($a0)
/*  f168c34:	24010008 */ 	addiu	$at,$zero,0x8
/*  f168c38:	55c10013 */ 	bnel	$t6,$at,.L0f168c88
/*  f168c3c:	2401014c */ 	addiu	$at,$zero,0x14c
/*  f168c40:	908f005c */ 	lbu	$t7,0x5c($a0)
/*  f168c44:	25f8fff1 */ 	addiu	$t8,$t7,-15
/*  f168c48:	2f010014 */ 	sltiu	$at,$t8,0x14
/*  f168c4c:	1020000d */ 	beqz	$at,.L0f168c84
/*  f168c50:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f168c54:	3c017f1b */ 	lui	$at,%hi(var7f1b7800)
/*  f168c58:	00380821 */ 	addu	$at,$at,$t8
/*  f168c5c:	8c387800 */ 	lw	$t8,%lo(var7f1b7800)($at)
/*  f168c60:	03000008 */ 	jr	$t8
/*  f168c64:	00000000 */ 	nop
/*  f168c68:	10000006 */ 	b	.L0f168c84
/*  f168c6c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f168c70:	9079005f */ 	lbu	$t9,0x5f($v1)
/*  f168c74:	24010001 */ 	addiu	$at,$zero,0x1
/*  f168c78:	57210003 */ 	bnel	$t9,$at,.L0f168c88
/*  f168c7c:	2401014c */ 	addiu	$at,$zero,0x14c
/*  f168c80:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f168c84:
/*  f168c84:	2401014c */ 	addiu	$at,$zero,0x14c
.L0f168c88:
/*  f168c88:	14a10007 */ 	bne	$a1,$at,.L0f168ca8
/*  f168c8c:	02002025 */ 	or	$a0,$s0,$zero
/*  f168c90:	0fc67c88 */ 	jal	frIsTargetOneHitExplodable
/*  f168c94:	afa8005c */ 	sw	$t0,0x5c($sp)
/*  f168c98:	8fa8005c */ 	lw	$t0,0x5c($sp)
/*  f168c9c:	10400002 */ 	beqz	$v0,.L0f168ca8
/*  f168ca0:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f168ca4:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f168ca8:
/*  f168ca8:	1100000b */ 	beqz	$t0,.L0f168cd8
/*  f168cac:	00001825 */ 	or	$v1,$zero,$zero
/*  f168cb0:	3c04800a */ 	lui	$a0,%hi(g_Vars+0x284)
/*  f168cb4:	8c84a244 */ 	lw	$a0,%lo(g_Vars+0x284)($a0)
/*  f168cb8:	24020030 */ 	addiu	$v0,$zero,0x30
.L0f168cbc:
/*  f168cbc:	8c8a1630 */ 	lw	$t2,0x1630($a0)
/*  f168cc0:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f168cc4:	160a0002 */ 	bne	$s0,$t2,.L0f168cd0
/*  f168cc8:	00000000 */ 	nop
/*  f168ccc:	00004025 */ 	or	$t0,$zero,$zero
.L0f168cd0:
/*  f168cd0:	1462fffa */ 	bne	$v1,$v0,.L0f168cbc
/*  f168cd4:	2484000c */ 	addiu	$a0,$a0,12
.L0f168cd8:
/*  f168cd8:	11000014 */ 	beqz	$t0,.L0f168d2c
/*  f168cdc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f168ce0:	44810000 */ 	mtc1	$at,$f0
/*  f168ce4:	3c01c000 */ 	lui	$at,0xc000
/*  f168ce8:	44811000 */ 	mtc1	$at,$f2
/*  f168cec:	27ab0058 */ 	addiu	$t3,$sp,0x58
/*  f168cf0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f168cf4:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f168cf8:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f168cfc:	27a60054 */ 	addiu	$a2,$sp,0x54
/*  f168d00:	27a70050 */ 	addiu	$a3,$sp,0x50
/*  f168d04:	afa8005c */ 	sw	$t0,0x5c($sp)
/*  f168d08:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f168d0c:	e7a00058 */ 	swc1	$f0,0x58($sp)
/*  f168d10:	e7a2004c */ 	swc1	$f2,0x4c($sp)
/*  f168d14:	0fc1a006 */ 	jal	modelSetRedBox
/*  f168d18:	e7a20050 */ 	swc1	$f2,0x50($sp)
/*  f168d1c:	8fa8005c */ 	lw	$t0,0x5c($sp)
/*  f168d20:	14400002 */ 	bnez	$v0,.L0f168d2c
/*  f168d24:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f168d28:	00004025 */ 	or	$t0,$zero,$zero
.L0f168d2c:
/*  f168d2c:	11000065 */ 	beqz	$t0,.L0f168ec4
/*  f168d30:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f168d34:	c6080010 */ 	lwc1	$f8,0x10($s0)
/*  f168d38:	c58a0008 */ 	lwc1	$f10,0x8($t4)
/*  f168d3c:	c6120008 */ 	lwc1	$f18,0x8($s0)
/*  f168d40:	c5840000 */ 	lwc1	$f4,0x0($t4)
/*  f168d44:	460a4001 */ 	sub.s	$f0,$f8,$f10
/*  f168d48:	c5880004 */ 	lwc1	$f8,0x4($t4)
/*  f168d4c:	c606000c */ 	lwc1	$f6,0xc($s0)
/*  f168d50:	46049301 */ 	sub.s	$f12,$f18,$f4
/*  f168d54:	44801000 */ 	mtc1	$zero,$f2
/*  f168d58:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f168d5c:	46083381 */ 	sub.s	$f14,$f6,$f8
/*  f168d60:	460c6282 */ 	mul.s	$f10,$f12,$f12
/*  f168d64:	00001025 */ 	or	$v0,$zero,$zero
/*  f168d68:	8fa30074 */ 	lw	$v1,0x74($sp)
/*  f168d6c:	460e7482 */ 	mul.s	$f18,$f14,$f14
/*  f168d70:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f168d74:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f168d78:	46043400 */ 	add.s	$f16,$f6,$f4
.L0f168d7c:
/*  f168d7c:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f168d80:	55a00003 */ 	bnezl	$t5,.L0f168d90
/*  f168d84:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f168d88:	00402025 */ 	or	$a0,$v0,$zero
/*  f168d8c:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f168d90:
/*  f168d90:	28410004 */ 	slti	$at,$v0,0x4
/*  f168d94:	1420fff9 */ 	bnez	$at,.L0f168d7c
/*  f168d98:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f168d9c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f168da0:	14810011 */ 	bne	$a0,$at,.L0f168de8
/*  f168da4:	00001025 */ 	or	$v0,$zero,$zero
/*  f168da8:	8fa30078 */ 	lw	$v1,0x78($sp)
.L0f168dac:
/*  f168dac:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f168db0:	4600103c */ 	c.lt.s	$f2,$f0
/*  f168db4:	00000000 */ 	nop
/*  f168db8:	45020004 */ 	bc1fl	.L0f168dcc
/*  f168dbc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f168dc0:	46000086 */ 	mov.s	$f2,$f0
/*  f168dc4:	00402025 */ 	or	$a0,$v0,$zero
/*  f168dc8:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f168dcc:
/*  f168dcc:	1449fff7 */ 	bne	$v0,$t1,.L0f168dac
/*  f168dd0:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f168dd4:	4610103e */ 	c.le.s	$f2,$f16
/*  f168dd8:	00000000 */ 	nop
/*  f168ddc:	45000002 */ 	bc1f	.L0f168de8
/*  f168de0:	00000000 */ 	nop
/*  f168de4:	2404ffff */ 	addiu	$a0,$zero,-1
.L0f168de8:
/*  f168de8:	04800036 */ 	bltz	$a0,.L0f168ec4
/*  f168dec:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f168df0:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f168df4:	8c6e0284 */ 	lw	$t6,0x284($v1)
/*  f168df8:	00041080 */ 	sll	$v0,$a0,0x2
/*  f168dfc:	00441023 */ 	subu	$v0,$v0,$a0
/*  f168e00:	00021080 */ 	sll	$v0,$v0,0x2
/*  f168e04:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f168e08:	3c014000 */ 	lui	$at,0x4000
/*  f168e0c:	adf01630 */ 	sw	$s0,0x1630($t7)
/*  f168e10:	44810000 */ 	mtc1	$at,$f0
/*  f168e14:	c7a80054 */ 	lwc1	$f8,0x54($sp)
/*  f168e18:	8c6a0284 */ 	lw	$t2,0x284($v1)
/*  f168e1c:	00042880 */ 	sll	$a1,$a0,0x2
/*  f168e20:	46004281 */ 	sub.s	$f10,$f8,$f0
/*  f168e24:	01425821 */ 	addu	$t3,$t2,$v0
/*  f168e28:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f168e2c:	44199000 */ 	mfc1	$t9,$f18
/*  f168e30:	00000000 */ 	nop
/*  f168e34:	a5791634 */ 	sh	$t9,0x1634($t3)
/*  f168e38:	c7a6004c */ 	lwc1	$f6,0x4c($sp)
/*  f168e3c:	8c6e0284 */ 	lw	$t6,0x284($v1)
/*  f168e40:	46003100 */ 	add.s	$f4,$f6,$f0
/*  f168e44:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f168e48:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f168e4c:	440d4000 */ 	mfc1	$t5,$f8
/*  f168e50:	00000000 */ 	nop
/*  f168e54:	a5ed1638 */ 	sh	$t5,0x1638($t7)
/*  f168e58:	c7aa0058 */ 	lwc1	$f10,0x58($sp)
/*  f168e5c:	8c790284 */ 	lw	$t9,0x284($v1)
/*  f168e60:	46005481 */ 	sub.s	$f18,$f10,$f0
/*  f168e64:	03225821 */ 	addu	$t3,$t9,$v0
/*  f168e68:	0004c840 */ 	sll	$t9,$a0,0x1
/*  f168e6c:	4600918d */ 	trunc.w.s	$f6,$f18
/*  f168e70:	440a3000 */ 	mfc1	$t2,$f6
/*  f168e74:	00000000 */ 	nop
/*  f168e78:	a56a1636 */ 	sh	$t2,0x1636($t3)
/*  f168e7c:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f168e80:	8c6d0284 */ 	lw	$t5,0x284($v1)
/*  f168e84:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f168e88:	46002200 */ 	add.s	$f8,$f4,$f0
/*  f168e8c:	01a27821 */ 	addu	$t7,$t5,$v0
/*  f168e90:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f168e94:	440e5000 */ 	mfc1	$t6,$f10
/*  f168e98:	00000000 */ 	nop
/*  f168e9c:	a5ee163a */ 	sh	$t6,0x163a($t7)
/*  f168ea0:	8c780284 */ 	lw	$t8,0x284($v1)
/*  f168ea4:	03195021 */ 	addu	$t2,$t8,$t9
/*  f168ea8:	a5401b90 */ 	sh	$zero,0x1b90($t2)
/*  f168eac:	8fac0074 */ 	lw	$t4,0x74($sp)
/*  f168eb0:	01856821 */ 	addu	$t5,$t4,$a1
/*  f168eb4:	adab0000 */ 	sw	$t3,0x0($t5)
/*  f168eb8:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f168ebc:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f168ec0:	e5f00000 */ 	swc1	$f16,0x0($t7)
.L0f168ec4:
/*  f168ec4:	8e04001c */ 	lw	$a0,0x1c($s0)
.L0f168ec8:
/*  f168ec8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f168ecc:	8fa60070 */ 	lw	$a2,0x70($sp)
/*  f168ed0:	10800004 */ 	beqz	$a0,.L0f168ee4
/*  f168ed4:	8fb80078 */ 	lw	$t8,0x78($sp)
/*  f168ed8:	8fa70074 */ 	lw	$a3,0x74($sp)
/*  f168edc:	0fc5a2d3 */ 	jal	propFindThreats
/*  f168ee0:	afb80010 */ 	sw	$t8,0x10($sp)
.L0f168ee4:
/*  f168ee4:	8fb9006c */ 	lw	$t9,0x6c($sp)
/*  f168ee8:	5320000a */ 	beqzl	$t9,.L0f168f14
/*  f168eec:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f168ef0:	8e040020 */ 	lw	$a0,0x20($s0)
/*  f168ef4:	03202825 */ 	or	$a1,$t9,$zero
/*  f168ef8:	8fa60070 */ 	lw	$a2,0x70($sp)
/*  f168efc:	10800004 */ 	beqz	$a0,.L0f168f10
/*  f168f00:	8faa0078 */ 	lw	$t2,0x78($sp)
/*  f168f04:	8fa70074 */ 	lw	$a3,0x74($sp)
/*  f168f08:	0fc5a2d3 */ 	jal	propFindThreats
/*  f168f0c:	afaa0010 */ 	sw	$t2,0x10($sp)
.L0f168f10:
/*  f168f10:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f168f14:
/*  f168f14:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f168f18:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*  f168f1c:	03e00008 */ 	jr	$ra
/*  f168f20:	00000000 */ 	nop
);

//void propFindThreats(struct prop *prop, bool inchild, struct coord *playerpos, bool *activeslots, f32 *distances)
//{
//	bool condition = true;
//	struct defaultobj *obj;
//	bool pass;
//	f32 sp88;
//	f32 sp84;
//	f32 sp80;
//	f32 sp76;
//	s32 i;
//	struct model *model;
//	struct weaponobj *weapon;
//
//	if (!inchild && prop->z < 0) {
//		condition = false;
//	}
//
//	if (prop->obj
//			&& (prop->flags & PROPFLAG_02)
//			&& (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON)
//			&& condition) {
//		pass = false;
//		obj = prop->obj;
//		model = prop->obj->model;
//
//		if (obj
//				&& obj->type == OBJTYPE_AUTOGUN
//				&& (obj->flags2 & (OBJFLAG2_80000000 | OBJFLAG2_AICANNOTUSE)) == 0) {
//			pass = true;
//		}
//
//		if (obj && obj->modelnum == MODEL_SK_SHUTTLE) {
//			pass = true;
//		}
//
//		weapon = (struct weaponobj *)prop->obj;
//
//		if (weapon && prop->obj->type == OBJTYPE_WEAPON) {
//			switch (weapon->weaponnum) {
//			case WEAPON_GRENADE:
//			case WEAPON_NBOMB:
//			case WEAPON_TIMEDMINE:
//			case WEAPON_PROXIMITYMINE:
//			case WEAPON_REMOTEMINE:
//				pass = true;
//				break;
//			case WEAPON_DRAGON:
//				if (weapon->thrown == 1U) {
//					pass = true;
//				}
//				break;
//			}
//		}
//
//		if (obj->modelnum == MODEL_TARGET && frIsTargetOneHitExplodable(prop)) {
//			pass = true;
//		}
//
//		if (pass) {
//			for (i = 0; i != 4; i++) {
//				if (g_Vars.currentplayer->cmpfollowprops[i].prop == prop) {
//					pass = false;
//				}
//			}
//		}
//
//		if (pass) {
//			sp84 = -1;
//			sp88 = -1;
//			sp76 = -2;
//			sp80 = -2;
//
//			if (!modelSetRedBox(model, &sp76, &sp84, &sp80, &sp88)) {
//				pass = false;
//			}
//		}
//
//		if (pass) {
//			f32 furtherestdist = 0;
//			s32 index = -1;
//
//			// Method 1: This generates correctly ordered FPU instructions, but
//			// the multiply and adding is relocated to after the for loop, and
//			// this method also uses too much stack.
//			//f32 zdiff = prop->pos.z - playerpos->z;
//			//f32 xdiff = prop->pos.x - playerpos->x;
//			//f32 ydiff = prop->pos.y - playerpos->y;
//			//f32 sqdist = zdiff * zdiff + xdiff * xdiff + ydiff * ydiff;
//
//			// Method 2: Stack is correct, location is correct, but FPU
//			// instructions are mismatching.
//			f32 sqdist = (prop->pos.z - playerpos->z) * (prop->pos.z - playerpos->z)
//				+ (prop->pos.x - playerpos->x) * (prop->pos.x - playerpos->x)
//				+ (prop->pos.y - playerpos->y) * (prop->pos.y - playerpos->y);
//
//			for (i = 0; i < 4; i++) {
//				if (!activeslots[i]) {
//					index = i;
//				}
//			}
//
//			if (index == -1) {
//				// No slots available - consider replacing the furtherest
//				for (i = 0; i != 4; i++) {
//					if (distances[i] > furtherestdist) {
//						furtherestdist = distances[i];
//						index = i;
//					}
//				}
//
//				if (sqdist >= furtherestdist) {
//					index = -1;
//				}
//			}
//
//			if (index >= 0) {
//				g_Vars.currentplayer->cmpfollowprops[index].prop = prop;
//				g_Vars.currentplayer->cmpfollowprops[index].unk04 = sp84 - 2;
//				g_Vars.currentplayer->cmpfollowprops[index].unk08 = sp76 + 2;
//				g_Vars.currentplayer->cmpfollowprops[index].unk06 = sp88 - 2;
//				g_Vars.currentplayer->cmpfollowprops[index].unk0a = sp80 + 2;
//				g_Vars.currentplayer->unk1b90[index] = 0;
//				activeslots[index] = true;
//				distances[index] = sqdist;
//			}
//		}
//	}
//
//	if (prop->child) {
//		propFindThreats(prop->child, true, playerpos, activeslots, distances);
//	}
//
//	if (inchild && prop->next) {
//		propFindThreats(prop->next, inchild, playerpos, activeslots, distances);
//	}
//}

GLOBAL_ASM(
glabel func0f168f24
/*  f168f24:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f168f28:	f7b80030 */ 	sdc1	$f24,0x30($sp)
/*  f168f2c:	3c01c000 */ 	lui	$at,0xc000
/*  f168f30:	4481c000 */ 	mtc1	$at,$f24
/*  f168f34:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f168f38:	3c01bf80 */ 	lui	$at,0xbf80
/*  f168f3c:	4481b000 */ 	mtc1	$at,$f22
/*  f168f40:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f168f44:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f168f48:	3c014000 */ 	lui	$at,0x4000
/*  f168f4c:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f168f50:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f168f54:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f168f58:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f168f5c:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f168f60:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f168f64:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f168f68:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f168f6c:	4481a000 */ 	mtc1	$at,$f20
/*  f168f70:	00809025 */ 	or	$s2,$a0,$zero
/*  f168f74:	00c0a825 */ 	or	$s5,$a2,$zero
/*  f168f78:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f168f7c:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f168f80:	afa5008c */ 	sw	$a1,0x8c($sp)
/*  f168f84:	afa70094 */ 	sw	$a3,0x94($sp)
/*  f168f88:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f168f8c:	00008025 */ 	or	$s0,$zero,$zero
/*  f168f90:	0000a025 */ 	or	$s4,$zero,$zero
/*  f168f94:	24160001 */ 	addiu	$s6,$zero,0x1
/*  f168f98:	24170004 */ 	addiu	$s7,$zero,0x4
/*  f168f9c:	8fbe0098 */ 	lw	$s8,0x98($sp)
.L0f168fa0:
/*  f168fa0:	8e6e0284 */ 	lw	$t6,0x284($s3)
/*  f168fa4:	01d07821 */ 	addu	$t7,$t6,$s0
/*  f168fa8:	8de31630 */ 	lw	$v1,0x1630($t7)
/*  f168fac:	56430062 */ 	bnel	$s2,$v1,.L0f169138
/*  f168fb0:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f168fb4:	92580001 */ 	lbu	$t8,0x1($s2)
/*  f168fb8:	33190002 */ 	andi	$t9,$t8,0x2
/*  f168fbc:	5320005e */ 	beqzl	$t9,.L0f169138
/*  f168fc0:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f168fc4:	92420000 */ 	lbu	$v0,0x0($s2)
/*  f168fc8:	00008825 */ 	or	$s1,$zero,$zero
/*  f168fcc:	52c20006 */ 	beql	$s6,$v0,.L0f168fe8
/*  f168fd0:	8c680004 */ 	lw	$t0,0x4($v1)
/*  f168fd4:	12e20003 */ 	beq	$s7,$v0,.L0f168fe4
/*  f168fd8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f168fdc:	54410005 */ 	bnel	$v0,$at,.L0f168ff4
/*  f168fe0:	24010003 */ 	addiu	$at,$zero,0x3
.L0f168fe4:
/*  f168fe4:	8c680004 */ 	lw	$t0,0x4($v1)
.L0f168fe8:
/*  f168fe8:	10000010 */ 	b	.L0f16902c
/*  f168fec:	8d110018 */ 	lw	$s1,0x18($t0)
/*  f168ff0:	24010003 */ 	addiu	$at,$zero,0x3
.L0f168ff4:
/*  f168ff4:	1041000b */ 	beq	$v0,$at,.L0f169024
/*  f168ff8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f168ffc:	1441000b */ 	bne	$v0,$at,.L0f16902c
/*  f169000:	00000000 */ 	nop
/*  f169004:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f169008:	02402025 */ 	or	$a0,$s2,$zero
/*  f16900c:	8e69028c */ 	lw	$t1,0x28c($s3)
/*  f169010:	10490006 */ 	beq	$v0,$t1,.L0f16902c
/*  f169014:	00000000 */ 	nop
/*  f169018:	8e6a0284 */ 	lw	$t2,0x284($s3)
/*  f16901c:	01505821 */ 	addu	$t3,$t2,$s0
/*  f169020:	8d631630 */ 	lw	$v1,0x1630($t3)
.L0f169024:
/*  f169024:	8c6c0004 */ 	lw	$t4,0x4($v1)
/*  f169028:	8d910020 */ 	lw	$s1,0x20($t4)
.L0f16902c:
/*  f16902c:	12200041 */ 	beqz	$s1,.L0f169134
/*  f169030:	02202025 */ 	or	$a0,$s1,$zero
/*  f169034:	27ad0080 */ 	addiu	$t5,$sp,0x80
/*  f169038:	e7b6007c */ 	swc1	$f22,0x7c($sp)
/*  f16903c:	e7b60080 */ 	swc1	$f22,0x80($sp)
/*  f169040:	e7b80074 */ 	swc1	$f24,0x74($sp)
/*  f169044:	e7b80078 */ 	swc1	$f24,0x78($sp)
/*  f169048:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f16904c:	27a50074 */ 	addiu	$a1,$sp,0x74
/*  f169050:	27a6007c */ 	addiu	$a2,$sp,0x7c
/*  f169054:	0fc1a006 */ 	jal	modelSetRedBox
/*  f169058:	27a70078 */ 	addiu	$a3,$sp,0x78
/*  f16905c:	10400035 */ 	beqz	$v0,.L0f169134
/*  f169060:	8fae0094 */ 	lw	$t6,0x94($sp)
/*  f169064:	00141080 */ 	sll	$v0,$s4,0x2
/*  f169068:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f16906c:	adf60000 */ 	sw	$s6,0x0($t7)
/*  f169070:	c7a4007c */ 	lwc1	$f4,0x7c($sp)
/*  f169074:	8e680284 */ 	lw	$t0,0x284($s3)
/*  f169078:	46142181 */ 	sub.s	$f6,$f4,$f20
/*  f16907c:	01104821 */ 	addu	$t1,$t0,$s0
/*  f169080:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f169084:	44194000 */ 	mfc1	$t9,$f8
/*  f169088:	00000000 */ 	nop
/*  f16908c:	a5391634 */ 	sh	$t9,0x1634($t1)
/*  f169090:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f169094:	8e6c0284 */ 	lw	$t4,0x284($s3)
/*  f169098:	46145400 */ 	add.s	$f16,$f10,$f20
/*  f16909c:	01906821 */ 	addu	$t5,$t4,$s0
/*  f1690a0:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f1690a4:	440b9000 */ 	mfc1	$t3,$f18
/*  f1690a8:	00000000 */ 	nop
/*  f1690ac:	a5ab1638 */ 	sh	$t3,0x1638($t5)
/*  f1690b0:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f1690b4:	8e780284 */ 	lw	$t8,0x284($s3)
/*  f1690b8:	03c25821 */ 	addu	$t3,$s8,$v0
/*  f1690bc:	46142181 */ 	sub.s	$f6,$f4,$f20
/*  f1690c0:	03104021 */ 	addu	$t0,$t8,$s0
/*  f1690c4:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f1690c8:	440f4000 */ 	mfc1	$t7,$f8
/*  f1690cc:	00000000 */ 	nop
/*  f1690d0:	a50f1636 */ 	sh	$t7,0x1636($t0)
/*  f1690d4:	c7aa0078 */ 	lwc1	$f10,0x78($sp)
/*  f1690d8:	8e6a0284 */ 	lw	$t2,0x284($s3)
/*  f1690dc:	46145400 */ 	add.s	$f16,$f10,$f20
/*  f1690e0:	01506021 */ 	addu	$t4,$t2,$s0
/*  f1690e4:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f1690e8:	44099000 */ 	mfc1	$t1,$f18
/*  f1690ec:	00000000 */ 	nop
/*  f1690f0:	a589163a */ 	sh	$t1,0x163a($t4)
/*  f1690f4:	c6aa0000 */ 	lwc1	$f10,0x0($s5)
/*  f1690f8:	c6480008 */ 	lwc1	$f8,0x8($s2)
/*  f1690fc:	c6b20004 */ 	lwc1	$f18,0x4($s5)
/*  f169100:	c650000c */ 	lwc1	$f16,0xc($s2)
/*  f169104:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f169108:	c6a60008 */ 	lwc1	$f6,0x8($s5)
/*  f16910c:	c6440010 */ 	lwc1	$f4,0x10($s2)
/*  f169110:	46128301 */ 	sub.s	$f12,$f16,$f18
/*  f169114:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f169118:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f16911c:	00000000 */ 	nop
/*  f169120:	460c6182 */ 	mul.s	$f6,$f12,$f12
/*  f169124:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f169128:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f16912c:	46085400 */ 	add.s	$f16,$f10,$f8
/*  f169130:	e5700000 */ 	swc1	$f16,0x0($t3)
.L0f169134:
/*  f169134:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f169138:
/*  f169138:	1697ff99 */ 	bne	$s4,$s7,.L0f168fa0
/*  f16913c:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f169140:	8e44001c */ 	lw	$a0,0x1c($s2)
/*  f169144:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f169148:	02a03025 */ 	or	$a2,$s5,$zero
/*  f16914c:	10800003 */ 	beqz	$a0,.L0f16915c
/*  f169150:	8fa70094 */ 	lw	$a3,0x94($sp)
/*  f169154:	0fc5a3c9 */ 	jal	func0f168f24
/*  f169158:	afbe0010 */ 	sw	$s8,0x10($sp)
.L0f16915c:
/*  f16915c:	8fad008c */ 	lw	$t5,0x8c($sp)
/*  f169160:	51a00009 */ 	beqzl	$t5,.L0f169188
/*  f169164:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f169168:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f16916c:	01a02825 */ 	or	$a1,$t5,$zero
/*  f169170:	02a03025 */ 	or	$a2,$s5,$zero
/*  f169174:	10800003 */ 	beqz	$a0,.L0f169184
/*  f169178:	8fa70094 */ 	lw	$a3,0x94($sp)
/*  f16917c:	0fc5a3c9 */ 	jal	func0f168f24
/*  f169180:	afbe0010 */ 	sw	$s8,0x10($sp)
.L0f169184:
/*  f169184:	8fbf005c */ 	lw	$ra,0x5c($sp)
.L0f169188:
/*  f169188:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f16918c:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f169190:	d7b80030 */ 	ldc1	$f24,0x30($sp)
/*  f169194:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f169198:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f16919c:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f1691a0:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f1691a4:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f1691a8:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f1691ac:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f1691b0:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f1691b4:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f1691b8:	03e00008 */ 	jr	$ra
/*  f1691bc:	27bd0088 */ 	addiu	$sp,$sp,0x88
);

// Mismatch because goal uses a nop when calculating distances[i].
// I suspect this needs an earlier version of the compiler.
//void func0f168f24(struct prop *prop, bool inchild, struct coord *playerpos, s32 *activeslots, f32 *distances)
//{
//	s32 i;
//	struct model *model;
//	f32 sp128;
//	f32 sp124;
//	f32 sp120;
//	f32 sp116;
//
//	for (i = 0; i != 4; i++) {
//		if (g_Vars.currentplayer->cmpfollowprops[i].prop == prop
//				&& (prop->flags & PROPFLAG_02)) {
//			model = NULL;
//
//			if (prop->type == PROPTYPE_OBJ
//					|| prop->type == PROPTYPE_WEAPON
//					|| prop->type == PROPTYPE_DOOR) {
//				model = g_Vars.currentplayer->cmpfollowprops[i].prop->obj->model;
//			} else {
//				if (prop->type == PROPTYPE_CHR
//						|| (prop->type == PROPTYPE_PLAYER
//							&& propGetPlayerNum(prop) != g_Vars.currentplayernum)) {
//					model = g_Vars.currentplayer->cmpfollowprops[i].prop->chr->model;
//				}
//			}
//
//			if (model) {
//				sp128 = -1;
//				sp124 = -1;
//				sp120 = -2;
//				sp116 = -2;
//
//				if (modelSetRedBox(model, &sp116, &sp124, &sp120, &sp128)) {
//					activeslots[i] = true;
//					g_Vars.currentplayer->cmpfollowprops[i].unk04 = sp124 - 2;
//					g_Vars.currentplayer->cmpfollowprops[i].unk08 = sp116 + 2;
//					g_Vars.currentplayer->cmpfollowprops[i].unk06 = sp128 - 2;
//					g_Vars.currentplayer->cmpfollowprops[i].unk0a = sp120 + 2;
//
//					distances[i] = (prop->pos.x - playerpos->x) * (prop->pos.x - playerpos->x)
//						+ (prop->pos.y - playerpos->y) * (prop->pos.y - playerpos->y)
//						+ (prop->pos.z - playerpos->z) * (prop->pos.z - playerpos->z);
//				}
//			}
//		}
//	}
//
//	if (prop->child) {
//		func0f168f24(prop->child, true, playerpos, activeslots, distances);
//	}
//
//	if (inchild && prop->next) {
//		func0f168f24(prop->next, inchild, playerpos, activeslots, distances);
//	}
//}

void func0f1691c0(void)
{
	s32 i;
	struct prop *prop;
	f32 distances[] = {0, 0, 0, 0};
	s32 activeslots[] = {false, false, false, false};
	struct prop **propptr = g_Vars.unk00034c - 1;
	struct coord campos;

	campos.x = g_Vars.currentplayer->cam_pos.x;
	campos.y = g_Vars.currentplayer->cam_pos.y;
	campos.z = g_Vars.currentplayer->cam_pos.z;

	while (propptr >= g_Vars.tangibleprops) {
		prop = *propptr;

		if (prop) {
			func0f168f24(prop, false, &campos, activeslots, distances);
		}

		propptr--;
	}

	for (i = 0; i != 4; i++) {
		if (!activeslots[i]) {
			g_Vars.currentplayer->cmpfollowprops[i].prop = NULL;
			g_Vars.currentplayer->cmpfollowprops[i].unk04 = -1;
			g_Vars.currentplayer->cmpfollowprops[i].unk08 = -2;
		}
	}

	propptr = g_Vars.unk00034c - 1;

	while (propptr >= g_Vars.tangibleprops) {
		prop = *propptr;

		if (prop) {
			propFindThreats(prop, false, &campos, activeslots, distances);
		}

		propptr--;
	}
}

u32 var80084088 = 0x00000000;
u32 var8008408c = 0x00000000;
u32 var80084090 = 0x00000000;
u32 var80084094 = 0x1e000000;
u32 var80084098 = 0x00000000;
u32 var8008409c = 0x00000064;
u32 var800840a0 = 0x00000000;
u32 g_CutsceneTime240_60 = 0x00000000;
u32 var800840a8 = 0x00000000;
u32 var800840ac = 0x00000000;
u32 var800840b0 = 0x00000000;
u32 var800840b4 = 0x00000000;
u32 var800840b8 = 0x00000000;
u32 var800840bc = 0x00000000;

GLOBAL_ASM(
glabel func0f169374
.late_rodata
glabel var7f1b7850
.word 0x3f866666
glabel var7f1b7854
.word 0x3ca3d70b
glabel var7f1b7858
.word 0x3f8ccccd
glabel var7f1b785c
.word 0x3bda740e
glabel var7f1b7860
.word 0x3ca3d70b
glabel var7f1b7864
.word 0x3f8ccccd
glabel var7f1b7868
.word 0x3bda740e
.text
/*  f169374:	27bdfe70 */ 	addiu	$sp,$sp,-400
/*  f169378:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f16937c:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f169380:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f169384:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f169388:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f16938c:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f169390:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f169394:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f169398:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f16939c:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f1693a0:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f1693a4:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f1693a8:	35ce0006 */ 	ori	$t6,$t6,0x6
/*  f1693ac:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1693b0:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f1693b4:	0fc3569f */ 	jal	func0f0d5a7c
/*  f1693b8:	24920008 */ 	addiu	$s2,$a0,0x8
/*  f1693bc:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f1693c0:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f1693c4:	8e6204b4 */ 	lw	$v0,0x4b4($s3)
/*  f1693c8:	2401005a */ 	addiu	$at,$zero,0x5a
/*  f1693cc:	10410006 */ 	beq	$v0,$at,.L0f1693e8
/*  f1693d0:	2401004e */ 	addiu	$at,$zero,0x4e
/*  f1693d4:	54410060 */ 	bnel	$v0,$at,.L0f169558
/*  f1693d8:	8e6204b4 */ 	lw	$v0,0x4b4($s3)
/*  f1693dc:	0fc06aea */ 	jal	titleIsKeepingMode
/*  f1693e0:	00000000 */ 	nop
/*  f1693e4:	1040005b */ 	beqz	$v0,.L0f169554
.L0f1693e8:
/*  f1693e8:	02401025 */ 	or	$v0,$s2,$zero
/*  f1693ec:	3c188006 */ 	lui	$t8,%hi(var800613a0)
/*  f1693f0:	271813a0 */ 	addiu	$t8,$t8,%lo(var800613a0)
/*  f1693f4:	3c0f0600 */ 	lui	$t7,0x600
/*  f1693f8:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f1693fc:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f169400:	0fc47b8a */ 	jal	debug0f11ee28
/*  f169404:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f169408:	10400008 */ 	beqz	$v0,.L0f16942c
/*  f16940c:	02401025 */ 	or	$v0,$s2,$zero
/*  f169410:	3c0a8006 */ 	lui	$t2,%hi(var80061360)
/*  f169414:	254a1360 */ 	addiu	$t2,$t2,%lo(var80061360)
/*  f169418:	3c190600 */ 	lui	$t9,0x600
/*  f16941c:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f169420:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f169424:	10000008 */ 	b	.L0f169448
/*  f169428:	26520008 */ 	addiu	$s2,$s2,0x8
.L0f16942c:
/*  f16942c:	02401025 */ 	or	$v0,$s2,$zero
/*  f169430:	3c0c8006 */ 	lui	$t4,%hi(var80061380)
/*  f169434:	258c1380 */ 	addiu	$t4,$t4,%lo(var80061380)
/*  f169438:	3c0b0600 */ 	lui	$t3,0x600
/*  f16943c:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f169440:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f169444:	26520008 */ 	addiu	$s2,$s2,0x8
.L0f169448:
/*  f169448:	0c002ca0 */ 	jal	func0000b280
/*  f16944c:	02402025 */ 	or	$a0,$s2,$zero
/*  f169450:	0c002c74 */ 	jal	func0000b1d0
/*  f169454:	00402025 */ 	or	$a0,$v0,$zero
/*  f169458:	0040a025 */ 	or	$s4,$v0,$zero
/*  f16945c:	0c002f40 */ 	jal	viGetViewLeft
/*  f169460:	24520008 */ 	addiu	$s2,$v0,0x8
/*  f169464:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f169468:	00116c03 */ 	sra	$t5,$s1,0x10
/*  f16946c:	0c002f44 */ 	jal	viGetViewTop
/*  f169470:	01a08825 */ 	or	$s1,$t5,$zero
/*  f169474:	44822000 */ 	mtc1	$v0,$f4
/*  f169478:	44918000 */ 	mtc1	$s1,$f16
/*  f16947c:	3c014080 */ 	lui	$at,0x4080
/*  f169480:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f169484:	4481a000 */ 	mtc1	$at,$f20
/*  f169488:	3c01ed00 */ 	lui	$at,0xed00
/*  f16948c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f169490:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f169494:	00000000 */ 	nop
/*  f169498:	46149102 */ 	mul.s	$f4,$f18,$f20
/*  f16949c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f1694a0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f1694a4:	440f5000 */ 	mfc1	$t7,$f10
/*  f1694a8:	440b3000 */ 	mfc1	$t3,$f6
/*  f1694ac:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f1694b0:	0301c825 */ 	or	$t9,$t8,$at
/*  f1694b4:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f1694b8:	000c6b00 */ 	sll	$t5,$t4,0xc
/*  f1694bc:	032d7025 */ 	or	$t6,$t9,$t5
/*  f1694c0:	0c002f22 */ 	jal	viGetViewX
/*  f1694c4:	ae8e0000 */ 	sw	$t6,0x0($s4)
/*  f1694c8:	0c002f40 */ 	jal	viGetViewLeft
/*  f1694cc:	a7a2008a */ 	sh	$v0,0x8a($sp)
/*  f1694d0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1694d4:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f1694d8:	0c002f44 */ 	jal	viGetViewTop
/*  f1694dc:	01e08025 */ 	or	$s0,$t7,$zero
/*  f1694e0:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f1694e4:	0011c403 */ 	sra	$t8,$s1,0x10
/*  f1694e8:	0c002f26 */ 	jal	viGetViewY
/*  f1694ec:	03008825 */ 	or	$s1,$t8,$zero
/*  f1694f0:	87ad008a */ 	lh	$t5,0x8a($sp)
/*  f1694f4:	00515021 */ 	addu	$t2,$v0,$s1
/*  f1694f8:	448a4000 */ 	mtc1	$t2,$f8
/*  f1694fc:	020d7021 */ 	addu	$t6,$s0,$t5
/*  f169500:	448e2000 */ 	mtc1	$t6,$f4
/*  f169504:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f169508:	02402025 */ 	or	$a0,$s2,$zero
/*  f16950c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f169510:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f169514:	00000000 */ 	nop
/*  f169518:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f16951c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f169520:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f169524:	440c9000 */ 	mfc1	$t4,$f18
/*  f169528:	44185000 */ 	mfc1	$t8,$f10
/*  f16952c:	31990fff */ 	andi	$t9,$t4,0xfff
/*  f169530:	330a0fff */ 	andi	$t2,$t8,0xfff
/*  f169534:	000a5b00 */ 	sll	$t3,$t2,0xc
/*  f169538:	032b6025 */ 	or	$t4,$t9,$t3
/*  f16953c:	0fc06bbc */ 	jal	titleRender
/*  f169540:	ae8c0004 */ 	sw	$t4,0x4($s4)
/*  f169544:	0fc5a176 */ 	jal	fadeRender
/*  f169548:	00402025 */ 	or	$a0,$v0,$zero
/*  f16954c:	1000065d */ 	b	.L0f16aec4
/*  f169550:	00409025 */ 	or	$s2,$v0,$zero
.L0f169554:
/*  f169554:	8e6204b4 */ 	lw	$v0,0x4b4($s3)
.L0f169558:
/*  f169558:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f16955c:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f169560:	14410040 */ 	bne	$v0,$at,.L0f169664
/*  f169564:	3408fffe */ 	dli	$t0,0xfffe
/*  f169568:	02401025 */ 	or	$v0,$s2,$zero
/*  f16956c:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f169570:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f169574:	35ad0404 */ 	ori	$t5,$t5,0x404
/*  f169578:	02401825 */ 	or	$v1,$s2,$zero
/*  f16957c:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f169580:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f169584:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f169588:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f16958c:	35ce0c04 */ 	ori	$t6,$t6,0xc04
/*  f169590:	02402025 */ 	or	$a0,$s2,$zero
/*  f169594:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f169598:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f16959c:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f1695a0:	35ef1404 */ 	ori	$t7,$t7,0x1404
/*  f1695a4:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f1695a8:	02402825 */ 	or	$a1,$s2,$zero
/*  f1695ac:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f1695b0:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f1695b4:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f1695b8:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f1695bc:	37181c04 */ 	ori	$t8,$t8,0x1c04
/*  f1695c0:	02403025 */ 	or	$a2,$s2,$zero
/*  f1695c4:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1695c8:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f1695cc:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f1695d0:	3c0a8006 */ 	lui	$t2,%hi(var800613a0)
/*  f1695d4:	3c090600 */ 	lui	$t1,0x600
/*  f1695d8:	254a13a0 */ 	addiu	$t2,$t2,%lo(var800613a0)
/*  f1695dc:	02401025 */ 	or	$v0,$s2,$zero
/*  f1695e0:	3c198006 */ 	lui	$t9,%hi(var80061380)
/*  f1695e4:	acca0004 */ 	sw	$t2,0x4($a2)
/*  f1695e8:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f1695ec:	27391380 */ 	addiu	$t9,$t9,%lo(var80061380)
/*  f1695f0:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f1695f4:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f1695f8:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f1695fc:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f169600:	00002025 */ 	or	$a0,$zero,$zero
/*  f169604:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f169608:	86040634 */ 	lh	$a0,0x634($s0)
/*  f16960c:	0c002f2a */ 	jal	viSetViewPosition
/*  f169610:	86050636 */ 	lh	$a1,0x636($s0)
/*  f169614:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f169618:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f16961c:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f169620:	86060630 */ 	lh	$a2,0x630($s0)
/*  f169624:	0c002f76 */ 	jal	viSetFovAspectAndSize
/*  f169628:	86070632 */ 	lh	$a3,0x632($s0)
/*  f16962c:	3c013f80 */ 	lui	$at,0x3f80
/*  f169630:	44816000 */ 	mtc1	$at,$f12
/*  f169634:	0c0059d2 */ 	jal	func00016748
/*  f169638:	00000000 */ 	nop
/*  f16963c:	0c002c74 */ 	jal	func0000b1d0
/*  f169640:	02402025 */ 	or	$a0,$s2,$zero
/*  f169644:	0c002ccc */ 	jal	func0000b330
/*  f169648:	00402025 */ 	or	$a0,$v0,$zero
/*  f16964c:	0fc572dd */ 	jal	func0f15cb74
/*  f169650:	00402025 */ 	or	$a0,$v0,$zero
/*  f169654:	0fc3ef0c */ 	jal	func0f0fbc30
/*  f169658:	00402025 */ 	or	$a0,$v0,$zero
/*  f16965c:	10000619 */ 	b	.L0f16aec4
/*  f169660:	00409025 */ 	or	$s2,$v0,$zero
.L0f169664:
/*  f169664:	2401005d */ 	addiu	$at,$zero,0x5d
/*  f169668:	14410046 */ 	bne	$v0,$at,.L0f169784
/*  f16966c:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f169670:	02401025 */ 	or	$v0,$s2,$zero
/*  f169674:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f169678:	3c0bbc00 */ 	lui	$t3,0xbc00
/*  f16967c:	356b0404 */ 	ori	$t3,$t3,0x404
/*  f169680:	02401825 */ 	or	$v1,$s2,$zero
/*  f169684:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f169688:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f16968c:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f169690:	3c0cbc00 */ 	lui	$t4,0xbc00
/*  f169694:	358c0c04 */ 	ori	$t4,$t4,0xc04
/*  f169698:	02402025 */ 	or	$a0,$s2,$zero
/*  f16969c:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f1696a0:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f1696a4:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f1696a8:	3408fffe */ 	dli	$t0,0xfffe
/*  f1696ac:	35ad1404 */ 	ori	$t5,$t5,0x1404
/*  f1696b0:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f1696b4:	02402825 */ 	or	$a1,$s2,$zero
/*  f1696b8:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f1696bc:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f1696c0:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f1696c4:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f1696c8:	35ce1c04 */ 	ori	$t6,$t6,0x1c04
/*  f1696cc:	02403025 */ 	or	$a2,$s2,$zero
/*  f1696d0:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f1696d4:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f1696d8:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f1696dc:	3c0f8006 */ 	lui	$t7,%hi(var800613a0)
/*  f1696e0:	3c090600 */ 	lui	$t1,0x600
/*  f1696e4:	25ef13a0 */ 	addiu	$t7,$t7,%lo(var800613a0)
/*  f1696e8:	02401025 */ 	or	$v0,$s2,$zero
/*  f1696ec:	3c188006 */ 	lui	$t8,%hi(var80061380)
/*  f1696f0:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f1696f4:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f1696f8:	27181380 */ 	addiu	$t8,$t8,%lo(var80061380)
/*  f1696fc:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f169700:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f169704:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f169708:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f16970c:	00002025 */ 	or	$a0,$zero,$zero
/*  f169710:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f169714:	86040634 */ 	lh	$a0,0x634($s0)
/*  f169718:	0c002f2a */ 	jal	viSetViewPosition
/*  f16971c:	86050636 */ 	lh	$a1,0x636($s0)
/*  f169720:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f169724:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f169728:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f16972c:	86060630 */ 	lh	$a2,0x630($s0)
/*  f169730:	0c002f76 */ 	jal	viSetFovAspectAndSize
/*  f169734:	86070632 */ 	lh	$a3,0x632($s0)
/*  f169738:	3c013f80 */ 	lui	$at,0x3f80
/*  f16973c:	44816000 */ 	mtc1	$at,$f12
/*  f169740:	0c0059d2 */ 	jal	func00016748
/*  f169744:	00000000 */ 	nop
/*  f169748:	0c002c74 */ 	jal	func0000b1d0
/*  f16974c:	02402025 */ 	or	$a0,$s2,$zero
/*  f169750:	0fc572dd */ 	jal	func0f15cb74
/*  f169754:	00402025 */ 	or	$a0,$v0,$zero
/*  f169758:	0fc3ef0c */ 	jal	func0f0fbc30
/*  f16975c:	00402025 */ 	or	$a0,$v0,$zero
/*  f169760:	8e6a0284 */ 	lw	$t2,0x284($s3)
/*  f169764:	00409025 */ 	or	$s2,$v0,$zero
/*  f169768:	8d591a24 */ 	lw	$t9,0x1a24($t2)
/*  f16976c:	532005d6 */ 	beqzl	$t9,.L0f16aec8
/*  f169770:	826e04d3 */ 	lb	$t6,0x4d3($s3)
/*  f169774:	0fc2eb5b */ 	jal	func0f0bad6c
/*  f169778:	00000000 */ 	nop
/*  f16977c:	100005d2 */ 	b	.L0f16aec8
/*  f169780:	826e04d3 */ 	lb	$t6,0x4d3($s3)
.L0f169784:
/*  f169784:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f169788:	14410041 */ 	bne	$v0,$at,.L0f169890
/*  f16978c:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f169790:	02401025 */ 	or	$v0,$s2,$zero
/*  f169794:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f169798:	3c0bbc00 */ 	lui	$t3,0xbc00
/*  f16979c:	356b0404 */ 	ori	$t3,$t3,0x404
/*  f1697a0:	02401825 */ 	or	$v1,$s2,$zero
/*  f1697a4:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f1697a8:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f1697ac:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f1697b0:	3c0cbc00 */ 	lui	$t4,0xbc00
/*  f1697b4:	358c0c04 */ 	ori	$t4,$t4,0xc04
/*  f1697b8:	02402025 */ 	or	$a0,$s2,$zero
/*  f1697bc:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f1697c0:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f1697c4:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f1697c8:	3408fffe */ 	dli	$t0,0xfffe
/*  f1697cc:	35ad1404 */ 	ori	$t5,$t5,0x1404
/*  f1697d0:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f1697d4:	02402825 */ 	or	$a1,$s2,$zero
/*  f1697d8:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f1697dc:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f1697e0:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f1697e4:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f1697e8:	35ce1c04 */ 	ori	$t6,$t6,0x1c04
/*  f1697ec:	02403025 */ 	or	$a2,$s2,$zero
/*  f1697f0:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f1697f4:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f1697f8:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f1697fc:	3c0f8006 */ 	lui	$t7,%hi(var800613a0)
/*  f169800:	3c090600 */ 	lui	$t1,0x600
/*  f169804:	25ef13a0 */ 	addiu	$t7,$t7,%lo(var800613a0)
/*  f169808:	02401025 */ 	or	$v0,$s2,$zero
/*  f16980c:	3c188006 */ 	lui	$t8,%hi(var80061380)
/*  f169810:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f169814:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f169818:	27181380 */ 	addiu	$t8,$t8,%lo(var80061380)
/*  f16981c:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f169820:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f169824:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f169828:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f16982c:	00002025 */ 	or	$a0,$zero,$zero
/*  f169830:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f169834:	86040634 */ 	lh	$a0,0x634($s0)
/*  f169838:	0c002f2a */ 	jal	viSetViewPosition
/*  f16983c:	86050636 */ 	lh	$a1,0x636($s0)
/*  f169840:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f169844:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f169848:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f16984c:	86060630 */ 	lh	$a2,0x630($s0)
/*  f169850:	0c002f76 */ 	jal	viSetFovAspectAndSize
/*  f169854:	86070632 */ 	lh	$a3,0x632($s0)
/*  f169858:	3c013f80 */ 	lui	$at,0x3f80
/*  f16985c:	44816000 */ 	mtc1	$at,$f12
/*  f169860:	0c0059d2 */ 	jal	func00016748
/*  f169864:	00000000 */ 	nop
/*  f169868:	0c002c6a */ 	jal	func0000b1a8
/*  f16986c:	02402025 */ 	or	$a0,$s2,$zero
/*  f169870:	0c002c74 */ 	jal	func0000b1d0
/*  f169874:	00402025 */ 	or	$a0,$v0,$zero
/*  f169878:	0c002ccc */ 	jal	func0000b330
/*  f16987c:	00402025 */ 	or	$a0,$v0,$zero
/*  f169880:	0fc4ec19 */ 	jal	func0f13b064
/*  f169884:	00402025 */ 	or	$a0,$v0,$zero
/*  f169888:	1000058e */ 	b	.L0f16aec4
/*  f16988c:	00409025 */ 	or	$s2,$v0,$zero
.L0f169890:
/*  f169890:	8e700298 */ 	lw	$s0,0x298($s3)
/*  f169894:	06010006 */ 	bgez	$s0,.L0f1698b0
/*  f169898:	00000000 */ 	nop
/*  f16989c:	8e70029c */ 	lw	$s0,0x29c($s3)
/*  f1698a0:	2a190000 */ 	slti	$t9,$s0,0x0
/*  f1698a4:	3b300001 */ 	xori	$s0,$t9,0x1
/*  f1698a8:	12000004 */ 	beqz	$s0,.L0f1698bc
/*  f1698ac:	00000000 */ 	nop
.L0f1698b0:
/*  f1698b0:	0fc2f130 */ 	jal	func0f0bc4c0
/*  f1698b4:	00000000 */ 	nop
/*  f1698b8:	0002802b */ 	sltu	$s0,$zero,$v0
.L0f1698bc:
/*  f1698bc:	12000004 */ 	beqz	$s0,.L0f1698d0
/*  f1698c0:	afb00124 */ 	sw	$s0,0x124($sp)
/*  f1698c4:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f1698c8:	1000001c */ 	b	.L0f16993c
/*  f1698cc:	afab012c */ 	sw	$t3,0x12c($sp)
.L0f1698d0:
/*  f1698d0:	8e6c006c */ 	lw	$t4,0x6c($s3)
/*  f1698d4:	00002025 */ 	or	$a0,$zero,$zero
/*  f1698d8:	00001825 */ 	or	$v1,$zero,$zero
/*  f1698dc:	11800003 */ 	beqz	$t4,.L0f1698ec
/*  f1698e0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1698e4:	10000001 */ 	b	.L0f1698ec
/*  f1698e8:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f1698ec:
/*  f1698ec:	8e6d0068 */ 	lw	$t5,0x68($s3)
/*  f1698f0:	00008025 */ 	or	$s0,$zero,$zero
/*  f1698f4:	11a00003 */ 	beqz	$t5,.L0f169904
/*  f1698f8:	00000000 */ 	nop
/*  f1698fc:	10000001 */ 	b	.L0f169904
/*  f169900:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f169904:
/*  f169904:	8e6e0064 */ 	lw	$t6,0x64($s3)
/*  f169908:	11c00003 */ 	beqz	$t6,.L0f169918
/*  f16990c:	00000000 */ 	nop
/*  f169910:	10000001 */ 	b	.L0f169918
/*  f169914:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f169918:
/*  f169918:	8e6f0070 */ 	lw	$t7,0x70($s3)
/*  f16991c:	11e00003 */ 	beqz	$t7,.L0f16992c
/*  f169920:	00000000 */ 	nop
/*  f169924:	10000001 */ 	b	.L0f16992c
/*  f169928:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f16992c:
/*  f16992c:	0202c021 */ 	addu	$t8,$s0,$v0
/*  f169930:	03035021 */ 	addu	$t2,$t8,$v1
/*  f169934:	0144c821 */ 	addu	$t9,$t2,$a0
/*  f169938:	afb9012c */ 	sw	$t9,0x12c($sp)
.L0f16993c:
/*  f16993c:	02401025 */ 	or	$v0,$s2,$zero
/*  f169940:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f169944:	3c0bbc00 */ 	lui	$t3,0xbc00
/*  f169948:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f16994c:	356b0404 */ 	ori	$t3,$t3,0x404
/*  f169950:	02401825 */ 	or	$v1,$s2,$zero
/*  f169954:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f169958:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f16995c:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f169960:	3c0cbc00 */ 	lui	$t4,0xbc00
/*  f169964:	358c0c04 */ 	ori	$t4,$t4,0xc04
/*  f169968:	02402025 */ 	or	$a0,$s2,$zero
/*  f16996c:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f169970:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f169974:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f169978:	3408fffe */ 	dli	$t0,0xfffe
/*  f16997c:	35ad1404 */ 	ori	$t5,$t5,0x1404
/*  f169980:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f169984:	02402825 */ 	or	$a1,$s2,$zero
/*  f169988:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f16998c:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f169990:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f169994:	35ce1c04 */ 	ori	$t6,$t6,0x1c04
/*  f169998:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f16999c:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f1699a0:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f1699a4:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f1699a8:	00008025 */ 	or	$s0,$zero,$zero
/*  f1699ac:	19e00545 */ 	blez	$t7,.L0f16aec4
/*  f1699b0:	3c188006 */ 	lui	$t8,%hi(var800613a0)
/*  f1699b4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1699b8:	271813a0 */ 	addiu	$t8,$t8,%lo(var800613a0)
/*  f1699bc:	4481a000 */ 	mtc1	$at,$f20
/*  f1699c0:	afb80068 */ 	sw	$t8,0x68($sp)
/*  f1699c4:	241e0001 */ 	addiu	$s8,$zero,0x1
/*  f1699c8:	2417ffff */ 	addiu	$s7,$zero,-1
/*  f1699cc:	2416fffe */ 	addiu	$s6,$zero,-2
/*  f1699d0:	24140004 */ 	addiu	$s4,$zero,0x4
/*  f1699d4:	8faa0124 */ 	lw	$t2,0x124($sp)
.L0f1699d8:
/*  f1699d8:	0000a825 */ 	or	$s5,$zero,$zero
/*  f1699dc:	afb20128 */ 	sw	$s2,0x128($sp)
/*  f1699e0:	11400007 */ 	beqz	$t2,.L0f169a00
/*  f1699e4:	00002025 */ 	or	$a0,$zero,$zero
/*  f1699e8:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f1699ec:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f1699f0:	26190001 */ 	addiu	$t9,$s0,0x1
/*  f1699f4:	ae600290 */ 	sw	$zero,0x290($s3)
/*  f1699f8:	1000000a */ 	b	.L0f169a24
/*  f1699fc:	afb90060 */ 	sw	$t9,0x60($sp)
.L0f169a00:
/*  f169a00:	0fc4a3b2 */ 	jal	getPlayerByOrderNum
/*  f169a04:	02002025 */ 	or	$a0,$s0,$zero
/*  f169a08:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f169a0c:	00402025 */ 	or	$a0,$v0,$zero
/*  f169a10:	8fab012c */ 	lw	$t3,0x12c($sp)
/*  f169a14:	26020001 */ 	addiu	$v0,$s0,0x1
/*  f169a18:	afa20060 */ 	sw	$v0,0x60($sp)
/*  f169a1c:	01628826 */ 	xor	$s1,$t3,$v0
/*  f169a20:	2e310001 */ 	sltiu	$s1,$s1,0x1
.L0f169a24:
/*  f169a24:	8e6c02ac */ 	lw	$t4,0x2ac($s3)
/*  f169a28:	24010006 */ 	addiu	$at,$zero,0x6
/*  f169a2c:	11810029 */ 	beq	$t4,$at,.L0f169ad4
/*  f169a30:	00000000 */ 	nop
/*  f169a34:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f169a38:	8e0d00bc */ 	lw	$t5,0xbc($s0)
/*  f169a3c:	8da20004 */ 	lw	$v0,0x4($t5)
/*  f169a40:	844402d8 */ 	lh	$a0,0x2d8($v0)
/*  f169a44:	18800023 */ 	blez	$a0,.L0f169ad4
/*  f169a48:	00000000 */ 	nop
/*  f169a4c:	920e1922 */ 	lbu	$t6,0x1922($s0)
/*  f169a50:	15c00020 */ 	bnez	$t6,.L0f169ad4
/*  f169a54:	00000000 */ 	nop
/*  f169a58:	8e0f1c08 */ 	lw	$t7,0x1c08($s0)
/*  f169a5c:	24011388 */ 	addiu	$at,$zero,0x1388
/*  f169a60:	15e0001c */ 	bnez	$t7,.L0f169ad4
/*  f169a64:	00000000 */ 	nop
/*  f169a68:	0004a980 */ 	sll	$s5,$a0,0x6
/*  f169a6c:	02a4a821 */ 	addu	$s5,$s5,$a0
/*  f169a70:	0015a840 */ 	sll	$s5,$s5,0x1
/*  f169a74:	02a1001a */ 	div	$zero,$s5,$at
/*  f169a78:	0000c012 */ 	mflo	$t8
/*  f169a7c:	27150064 */ 	addiu	$s5,$t8,0x64
/*  f169a80:	2ea100e7 */ 	sltiu	$at,$s5,0xe7
/*  f169a84:	14200002 */ 	bnez	$at,.L0f169a90
/*  f169a88:	240a1388 */ 	addiu	$t2,$zero,0x1388
/*  f169a8c:	241500e6 */ 	addiu	$s5,$zero,0xe6
.L0f169a90:
/*  f169a90:	28811389 */ 	slti	$at,$a0,0x1389
/*  f169a94:	54200004 */ 	bnezl	$at,.L0f169aa8
/*  f169a98:	904b02ff */ 	lbu	$t3,0x2ff($v0)
/*  f169a9c:	a44a02d8 */ 	sh	$t2,0x2d8($v0)
/*  f169aa0:	844402d8 */ 	lh	$a0,0x2d8($v0)
/*  f169aa4:	904b02ff */ 	lbu	$t3,0x2ff($v0)
.L0f169aa8:
/*  f169aa8:	8e790038 */ 	lw	$t9,0x38($s3)
/*  f169aac:	256c0001 */ 	addiu	$t4,$t3,0x1
/*  f169ab0:	032c0019 */ 	multu	$t9,$t4
/*  f169ab4:	00006812 */ 	mflo	$t5
/*  f169ab8:	008d7023 */ 	subu	$t6,$a0,$t5
/*  f169abc:	a44e02d8 */ 	sh	$t6,0x2d8($v0)
/*  f169ac0:	844f02d8 */ 	lh	$t7,0x2d8($v0)
/*  f169ac4:	1de00003 */ 	bgtz	$t7,.L0f169ad4
/*  f169ac8:	00000000 */ 	nop
/*  f169acc:	a44002d8 */ 	sh	$zero,0x2d8($v0)
/*  f169ad0:	a04002ff */ 	sb	$zero,0x2ff($v0)
.L0f169ad4:
/*  f169ad4:	0fc522d0 */ 	jal	func0f148b40
/*  f169ad8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f169adc:	02401025 */ 	or	$v0,$s2,$zero
/*  f169ae0:	3c180600 */ 	lui	$t8,0x600
/*  f169ae4:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f169ae8:	8faa0068 */ 	lw	$t2,0x68($sp)
/*  f169aec:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f169af0:	0fc47b8a */ 	jal	debug0f11ee28
/*  f169af4:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f169af8:	10400009 */ 	beqz	$v0,.L0f169b20
/*  f169afc:	3c0c0600 */ 	lui	$t4,0x600
/*  f169b00:	02401025 */ 	or	$v0,$s2,$zero
/*  f169b04:	3c198006 */ 	lui	$t9,%hi(var80061360)
/*  f169b08:	27391360 */ 	addiu	$t9,$t9,%lo(var80061360)
/*  f169b0c:	3c0b0600 */ 	lui	$t3,0x600
/*  f169b10:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f169b14:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f169b18:	10000007 */ 	b	.L0f169b38
/*  f169b1c:	26520008 */ 	addiu	$s2,$s2,0x8
.L0f169b20:
/*  f169b20:	02401025 */ 	or	$v0,$s2,$zero
/*  f169b24:	3c0d8006 */ 	lui	$t5,%hi(var80061380)
/*  f169b28:	25ad1380 */ 	addiu	$t5,$t5,%lo(var80061380)
/*  f169b2c:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f169b30:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f169b34:	26520008 */ 	addiu	$s2,$s2,0x8
.L0f169b38:
/*  f169b38:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f169b3c:	86040634 */ 	lh	$a0,0x634($s0)
/*  f169b40:	0c002f2a */ 	jal	viSetViewPosition
/*  f169b44:	86050636 */ 	lh	$a1,0x636($s0)
/*  f169b48:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f169b4c:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f169b50:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f169b54:	86060630 */ 	lh	$a2,0x630($s0)
/*  f169b58:	0c002f76 */ 	jal	viSetFovAspectAndSize
/*  f169b5c:	86070632 */ 	lh	$a3,0x632($s0)
/*  f169b60:	8e6e0288 */ 	lw	$t6,0x288($s3)
/*  f169b64:	0c0059d2 */ 	jal	func00016748
/*  f169b68:	c5cc0074 */ 	lwc1	$f12,0x74($t6)
/*  f169b6c:	0fc595fe */ 	jal	func0f1657f8
/*  f169b70:	00000000 */ 	nop
/*  f169b74:	0fc5d8a6 */ 	jal	func0f176298
/*  f169b78:	00000000 */ 	nop
/*  f169b7c:	0c002ca0 */ 	jal	func0000b280
/*  f169b80:	02402025 */ 	or	$a0,$s2,$zero
/*  f169b84:	0c002c74 */ 	jal	func0000b1d0
/*  f169b88:	00402025 */ 	or	$a0,$v0,$zero
/*  f169b8c:	0fc572dd */ 	jal	func0f15cb74
/*  f169b90:	00402025 */ 	or	$a0,$v0,$zero
/*  f169b94:	0fc4f144 */ 	jal	func0f13c510
/*  f169b98:	00409025 */ 	or	$s2,$v0,$zero
/*  f169b9c:	8e6f04b4 */ 	lw	$t7,0x4b4($s3)
/*  f169ba0:	24010026 */ 	addiu	$at,$zero,0x26
/*  f169ba4:	3c188008 */ 	lui	$t8,%hi(var80087260)
/*  f169ba8:	55e1000a */ 	bnel	$t7,$at,.L0f169bd4
/*  f169bac:	8e6b000c */ 	lw	$t3,0xc($s3)
/*  f169bb0:	8f187260 */ 	lw	$t8,%lo(var80087260)($t8)
/*  f169bb4:	3c0a800a */ 	lui	$t2,%hi(g_MenuData+0x4)
/*  f169bb8:	5f00001a */ 	bgtzl	$t8,.L0f169c24
/*  f169bbc:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f169bc0:	8d4a19c4 */ 	lw	$t2,%lo(g_MenuData+0x4)($t2)
/*  f169bc4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f169bc8:	51410016 */ 	beql	$t2,$at,.L0f169c24
/*  f169bcc:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f169bd0:	8e6b000c */ 	lw	$t3,0xc($s3)
.L0f169bd4:
/*  f169bd4:	29610006 */ 	slti	$at,$t3,0x6
/*  f169bd8:	50200012 */ 	beqzl	$at,.L0f169c24
/*  f169bdc:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f169be0:	8e790318 */ 	lw	$t9,0x318($s3)
/*  f169be4:	5720000f */ 	bnezl	$t9,.L0f169c24
/*  f169be8:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f169bec:	8e6c02ac */ 	lw	$t4,0x2ac($s3)
/*  f169bf0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f169bf4:	3c028008 */ 	lui	$v0,%hi(var80084050)
/*  f169bf8:	5181000a */ 	beql	$t4,$at,.L0f169c24
/*  f169bfc:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f169c00:	8c424050 */ 	lw	$v0,%lo(var80084050)($v0)
/*  f169c04:	28410006 */ 	slti	$at,$v0,0x6
/*  f169c08:	10200002 */ 	beqz	$at,.L0f169c14
/*  f169c0c:	244d0001 */ 	addiu	$t5,$v0,0x1
/*  f169c10:	ae7e0320 */ 	sw	$s8,0x320($s3)
.L0f169c14:
/*  f169c14:	3c018008 */ 	lui	$at,%hi(var80084050)
/*  f169c18:	1000001d */ 	b	.L0f169c90
/*  f169c1c:	ac2d4050 */ 	sw	$t5,%lo(var80084050)($at)
/*  f169c20:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f169c24:
/*  f169c24:	3c0a8007 */ 	lui	$t2,%hi(var80075d60)
/*  f169c28:	8e0e1580 */ 	lw	$t6,0x1580($s0)
/*  f169c2c:	000ec780 */ 	sll	$t8,$t6,0x1e
/*  f169c30:	07030018 */ 	bgezl	$t8,.L0f169c94
/*  f169c34:	8e6a0320 */ 	lw	$t2,0x320($s3)
/*  f169c38:	8d4a5d60 */ 	lw	$t2,%lo(var80075d60)($t2)
/*  f169c3c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f169c40:	55410014 */ 	bnel	$t2,$at,.L0f169c94
/*  f169c44:	8e6a0320 */ 	lw	$t2,0x320($s3)
/*  f169c48:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f169c4c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f169c50:	53c20010 */ 	beql	$s8,$v0,.L0f169c94
/*  f169c54:	8e6a0320 */ 	lw	$t2,0x320($s3)
/*  f169c58:	1041000d */ 	beq	$v0,$at,.L0f169c90
/*  f169c5c:	3c0b800a */ 	lui	$t3,%hi(var8009dfc0)
/*  f169c60:	8d6bdfc0 */ 	lw	$t3,%lo(var8009dfc0)($t3)
/*  f169c64:	5560000b */ 	bnezl	$t3,.L0f169c94
/*  f169c68:	8e6a0320 */ 	lw	$t2,0x320($s3)
/*  f169c6c:	0fc27ab9 */ 	jal	func0f09eae4
/*  f169c70:	00000000 */ 	nop
/*  f169c74:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f169c78:	00026040 */ 	sll	$t4,$v0,0x1
/*  f169c7c:	318d0002 */ 	andi	$t5,$t4,0x2
/*  f169c80:	920e1583 */ 	lbu	$t6,0x1583($s0)
/*  f169c84:	31cffffd */ 	andi	$t7,$t6,0xfffd
/*  f169c88:	01afc025 */ 	or	$t8,$t5,$t7
/*  f169c8c:	a2181583 */ 	sb	$t8,0x1583($s0)
.L0f169c90:
/*  f169c90:	8e6a0320 */ 	lw	$t2,0x320($s3)
.L0f169c94:
/*  f169c94:	02402025 */ 	or	$a0,$s2,$zero
/*  f169c98:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f169c9c:	11400008 */ 	beqz	$t2,.L0f169cc0
/*  f169ca0:	3c0c800a */ 	lui	$t4,%hi(var8009dfc0)
/*  f169ca4:	0fc5090e */ 	jal	func0f142438
/*  f169ca8:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f169cac:	8e6b0320 */ 	lw	$t3,0x320($s3)
/*  f169cb0:	00409025 */ 	or	$s2,$v0,$zero
/*  f169cb4:	2579ffff */ 	addiu	$t9,$t3,-1
/*  f169cb8:	1000046e */ 	b	.L0f16ae74
/*  f169cbc:	ae790320 */ 	sw	$t9,0x320($s3)
.L0f169cc0:
/*  f169cc0:	8d8cdfc0 */ 	lw	$t4,%lo(var8009dfc0)($t4)
/*  f169cc4:	3c188007 */ 	lui	$t8,%hi(var80075d60)
/*  f169cc8:	11800012 */ 	beqz	$t4,.L0f169d14
/*  f169ccc:	00000000 */ 	nop
/*  f169cd0:	0c002ccc */ 	jal	func0000b330
/*  f169cd4:	02402025 */ 	or	$a0,$s2,$zero
/*  f169cd8:	0fc572dd */ 	jal	func0f15cb74
/*  f169cdc:	00402025 */ 	or	$a0,$v0,$zero
/*  f169ce0:	3c013f80 */ 	lui	$at,0x3f80
/*  f169ce4:	44816000 */ 	mtc1	$at,$f12
/*  f169ce8:	0c0059d2 */ 	jal	func00016748
/*  f169cec:	00409025 */ 	or	$s2,$v0,$zero
/*  f169cf0:	8e6e0284 */ 	lw	$t6,0x284($s3)
/*  f169cf4:	8dcd1c50 */ 	lw	$t5,0x1c50($t6)
/*  f169cf8:	000d7fc2 */ 	srl	$t7,$t5,0x1f
/*  f169cfc:	11e0045d */ 	beqz	$t7,.L0f16ae74
/*  f169d00:	00000000 */ 	nop
/*  f169d04:	0fc3ef0c */ 	jal	func0f0fbc30
/*  f169d08:	02402025 */ 	or	$a0,$s2,$zero
/*  f169d0c:	10000459 */ 	b	.L0f16ae74
/*  f169d10:	00409025 */ 	or	$s2,$v0,$zero
.L0f169d14:
/*  f169d14:	8f185d60 */ 	lw	$t8,%lo(var80075d60)($t8)
/*  f169d18:	24010002 */ 	addiu	$at,$zero,0x2
/*  f169d1c:	17010004 */ 	bne	$t8,$at,.L0f169d30
/*  f169d20:	00000000 */ 	nop
/*  f169d24:	0fc2fff3 */ 	jal	func0f0bffcc
/*  f169d28:	02402025 */ 	or	$a0,$s2,$zero
/*  f169d2c:	00409025 */ 	or	$s2,$v0,$zero
.L0f169d30:
/*  f169d30:	0c002ccc */ 	jal	func0000b330
/*  f169d34:	02402025 */ 	or	$a0,$s2,$zero
/*  f169d38:	0fc47e61 */ 	jal	func0f11f984
/*  f169d3c:	00402025 */ 	or	$a0,$v0,$zero
/*  f169d40:	0fc57280 */ 	jal	func0f15ca00
/*  f169d44:	00409025 */ 	or	$s2,$v0,$zero
/*  f169d48:	0fc010c5 */ 	jal	func0f004314
/*  f169d4c:	00000000 */ 	nop
/*  f169d50:	0fc18c0b */ 	jal	func0f06302c
/*  f169d54:	02202025 */ 	or	$a0,$s1,$zero
/*  f169d58:	0fc615c8 */ 	jal	scenarioCallback14
/*  f169d5c:	00002025 */ 	or	$a0,$zero,$zero
/*  f169d60:	0fc1806c */ 	jal	func0f0601b0
/*  f169d64:	00000000 */ 	nop
/*  f169d68:	0fc1933a */ 	jal	func0f064ce8
/*  f169d6c:	00000000 */ 	nop
/*  f169d70:	0fc18acb */ 	jal	func0f062b2c
/*  f169d74:	00000000 */ 	nop
/*  f169d78:	8e6a006c */ 	lw	$t2,0x6c($s3)
/*  f169d7c:	00002025 */ 	or	$a0,$zero,$zero
/*  f169d80:	00001825 */ 	or	$v1,$zero,$zero
/*  f169d84:	11400003 */ 	beqz	$t2,.L0f169d94
/*  f169d88:	00001025 */ 	or	$v0,$zero,$zero
/*  f169d8c:	10000001 */ 	b	.L0f169d94
/*  f169d90:	03c02025 */ 	or	$a0,$s8,$zero
.L0f169d94:
/*  f169d94:	8e6b0068 */ 	lw	$t3,0x68($s3)
/*  f169d98:	00008025 */ 	or	$s0,$zero,$zero
/*  f169d9c:	11600003 */ 	beqz	$t3,.L0f169dac
/*  f169da0:	00000000 */ 	nop
/*  f169da4:	10000001 */ 	b	.L0f169dac
/*  f169da8:	03c01825 */ 	or	$v1,$s8,$zero
.L0f169dac:
/*  f169dac:	8e790064 */ 	lw	$t9,0x64($s3)
/*  f169db0:	13200003 */ 	beqz	$t9,.L0f169dc0
/*  f169db4:	00000000 */ 	nop
/*  f169db8:	10000001 */ 	b	.L0f169dc0
/*  f169dbc:	03c01025 */ 	or	$v0,$s8,$zero
.L0f169dc0:
/*  f169dc0:	8e6c0070 */ 	lw	$t4,0x70($s3)
/*  f169dc4:	11800003 */ 	beqz	$t4,.L0f169dd4
/*  f169dc8:	00000000 */ 	nop
/*  f169dcc:	10000001 */ 	b	.L0f169dd4
/*  f169dd0:	03c08025 */ 	or	$s0,$s8,$zero
.L0f169dd4:
/*  f169dd4:	02027021 */ 	addu	$t6,$s0,$v0
/*  f169dd8:	01c36821 */ 	addu	$t5,$t6,$v1
/*  f169ddc:	01a47821 */ 	addu	$t7,$t5,$a0
/*  f169de0:	53cf0012 */ 	beql	$s8,$t7,.L0f169e2c
/*  f169de4:	00002025 */ 	or	$a0,$zero,$zero
/*  f169de8:	8e780298 */ 	lw	$t8,0x298($s3)
/*  f169dec:	0703000f */ 	bgezl	$t8,.L0f169e2c
/*  f169df0:	00002025 */ 	or	$a0,$zero,$zero
/*  f169df4:	8e6a029c */ 	lw	$t2,0x29c($s3)
/*  f169df8:	0543000c */ 	bgezl	$t2,.L0f169e2c
/*  f169dfc:	00002025 */ 	or	$a0,$zero,$zero
/*  f169e00:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f169e04:	00002025 */ 	or	$a0,$zero,$zero
/*  f169e08:	00402025 */ 	or	$a0,$v0,$zero
/*  f169e0c:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f169e10:	3c054000 */ 	lui	$a1,0x4000
/*  f169e14:	50400050 */ 	beqzl	$v0,.L0f169f58
/*  f169e18:	8e6a0284 */ 	lw	$t2,0x284($s3)
/*  f169e1c:	0fc31ebc */ 	jal	currentPlayerIsInSightAimMode
/*  f169e20:	00000000 */ 	nop
/*  f169e24:	1040004b */ 	beqz	$v0,.L0f169f54
/*  f169e28:	00002025 */ 	or	$a0,$zero,$zero
.L0f169e2c:
/*  f169e2c:	00002825 */ 	or	$a1,$zero,$zero
/*  f169e30:	0fc18755 */ 	jal	func0f061d54
/*  f169e34:	00003025 */ 	or	$a2,$zero,$zero
/*  f169e38:	8e6b0284 */ 	lw	$t3,0x284($s3)
/*  f169e3c:	ad621624 */ 	sw	$v0,0x1624($t3)
/*  f169e40:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f169e44:	8e041624 */ 	lw	$a0,0x1624($s0)
/*  f169e48:	50800046 */ 	beqzl	$a0,.L0f169f64
/*  f169e4c:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f169e50:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f169e54:	24010003 */ 	addiu	$at,$zero,0x3
/*  f169e58:	10410003 */ 	beq	$v0,$at,.L0f169e68
/*  f169e5c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f169e60:	1441001f */ 	bne	$v0,$at,.L0f169ee0
/*  f169e64:	00000000 */ 	nop
.L0f169e68:
/*  f169e68:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f169e6c:	8c590014 */ 	lw	$t9,0x14($v0)
/*  f169e70:	00196080 */ 	sll	$t4,$t9,0x2
/*  f169e74:	0583003b */ 	bgezl	$t4,.L0f169f64
/*  f169e78:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f169e7c:	8e0e00d8 */ 	lw	$t6,0xd8($s0)
/*  f169e80:	3c0d8007 */ 	lui	$t5,%hi(var80070764)
/*  f169e84:	55c00014 */ 	bnezl	$t6,.L0f169ed8
/*  f169e88:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f169e8c:	8dad0764 */ 	lw	$t5,%lo(var80070764)($t5)
/*  f169e90:	55a00011 */ 	bnezl	$t5,.L0f169ed8
/*  f169e94:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f169e98:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f169e9c:	50400007 */ 	beqzl	$v0,.L0f169ebc
/*  f169ea0:	8e0a1c54 */ 	lw	$t2,0x1c54($s0)
/*  f169ea4:	5040000c */ 	beqzl	$v0,.L0f169ed8
/*  f169ea8:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f169eac:	804f0037 */ 	lb	$t7,0x37($v0)
/*  f169eb0:	55e00009 */ 	bnezl	$t7,.L0f169ed8
/*  f169eb4:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f169eb8:	8e0a1c54 */ 	lw	$t2,0x1c54($s0)
.L0f169ebc:
/*  f169ebc:	8e1800c4 */ 	lw	$t8,0xc4($s0)
/*  f169ec0:	01405827 */ 	nor	$t3,$t2,$zero
/*  f169ec4:	030bc824 */ 	and	$t9,$t8,$t3
/*  f169ec8:	332c0008 */ 	andi	$t4,$t9,0x8
/*  f169ecc:	55800025 */ 	bnezl	$t4,.L0f169f64
/*  f169ed0:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f169ed4:	ae001624 */ 	sw	$zero,0x1624($s0)
.L0f169ed8:
/*  f169ed8:	10000021 */ 	b	.L0f169f60
/*  f169edc:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f169ee0:
/*  f169ee0:	53c20006 */ 	beql	$s8,$v0,.L0f169efc
/*  f169ee4:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f169ee8:	12820003 */ 	beq	$s4,$v0,.L0f169ef8
/*  f169eec:	24010002 */ 	addiu	$at,$zero,0x2
/*  f169ef0:	54410016 */ 	bnel	$v0,$at,.L0f169f4c
/*  f169ef4:	ae001624 */ 	sw	$zero,0x1624($s0)
.L0f169ef8:
/*  f169ef8:	8c830004 */ 	lw	$v1,0x4($a0)
.L0f169efc:
/*  f169efc:	8c6e0010 */ 	lw	$t6,0x10($v1)
/*  f169f00:	31cd8000 */ 	andi	$t5,$t6,0x8000
/*  f169f04:	55a00017 */ 	bnezl	$t5,.L0f169f64
/*  f169f08:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f169f0c:	8e6f04b4 */ 	lw	$t7,0x4b4($s3)
/*  f169f10:	24010026 */ 	addiu	$at,$zero,0x26
/*  f169f14:	55e1000a */ 	bnel	$t7,$at,.L0f169f40
/*  f169f18:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f169f1c:	84620004 */ 	lh	$v0,0x4($v1)
/*  f169f20:	2401014c */ 	addiu	$at,$zero,0x14c
/*  f169f24:	1041000e */ 	beq	$v0,$at,.L0f169f60
/*  f169f28:	240101aa */ 	addiu	$at,$zero,0x1aa
/*  f169f2c:	1041000c */ 	beq	$v0,$at,.L0f169f60
/*  f169f30:	240100b0 */ 	addiu	$at,$zero,0xb0
/*  f169f34:	5041000b */ 	beql	$v0,$at,.L0f169f64
/*  f169f38:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f169f3c:	ae001624 */ 	sw	$zero,0x1624($s0)
.L0f169f40:
/*  f169f40:	10000007 */ 	b	.L0f169f60
/*  f169f44:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f169f48:	ae001624 */ 	sw	$zero,0x1624($s0)
.L0f169f4c:
/*  f169f4c:	10000004 */ 	b	.L0f169f60
/*  f169f50:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f169f54:
/*  f169f54:	8e6a0284 */ 	lw	$t2,0x284($s3)
.L0f169f58:
/*  f169f58:	ad401624 */ 	sw	$zero,0x1624($t2)
/*  f169f5c:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f169f60:
/*  f169f60:	26040638 */ 	addiu	$a0,$s0,0x638
.L0f169f64:
/*  f169f64:	0fc2c7aa */ 	jal	func0f0b1ea8
/*  f169f68:	3c050008 */ 	lui	$a1,0x8
/*  f169f6c:	10400005 */ 	beqz	$v0,.L0f169f84
/*  f169f70:	00000000 */ 	nop
/*  f169f74:	0fc5a470 */ 	jal	func0f1691c0
/*  f169f78:	00000000 */ 	nop
/*  f169f7c:	10000033 */ 	b	.L0f16a04c
/*  f169f80:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f169f84:
/*  f169f84:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f169f88:	00002025 */ 	or	$a0,$zero,$zero
/*  f169f8c:	00402025 */ 	or	$a0,$v0,$zero
/*  f169f90:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f169f94:	3c054000 */ 	lui	$a1,0x4000
/*  f169f98:	5040002c */ 	beqzl	$v0,.L0f16a04c
/*  f169f9c:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f169fa0:	0fc6830c */ 	jal	frIsInTraining
/*  f169fa4:	00000000 */ 	nop
/*  f169fa8:	5040000f */ 	beqzl	$v0,.L0f169fe8
/*  f169fac:	8e640284 */ 	lw	$a0,0x284($s3)
/*  f169fb0:	8e780284 */ 	lw	$t8,0x284($s3)
/*  f169fb4:	8f0b1624 */ 	lw	$t3,0x1624($t8)
/*  f169fb8:	5160000b */ 	beqzl	$t3,.L0f169fe8
/*  f169fbc:	8e640284 */ 	lw	$a0,0x284($s3)
/*  f169fc0:	0fc31ebc */ 	jal	currentPlayerIsInSightAimMode
/*  f169fc4:	00000000 */ 	nop
/*  f169fc8:	50400007 */ 	beqzl	$v0,.L0f169fe8
/*  f169fcc:	8e640284 */ 	lw	$a0,0x284($s3)
/*  f169fd0:	8e790284 */ 	lw	$t9,0x284($s3)
/*  f169fd4:	0fc68249 */ 	jal	func0f1a0924
/*  f169fd8:	8f241624 */ 	lw	$a0,0x1624($t9)
/*  f169fdc:	1000000a */ 	b	.L0f16a008
/*  f169fe0:	00008825 */ 	or	$s1,$zero,$zero
/*  f169fe4:	8e640284 */ 	lw	$a0,0x284($s3)
.L0f169fe8:
/*  f169fe8:	02e02825 */ 	or	$a1,$s7,$zero
/*  f169fec:	0fc5a23f */ 	jal	threatCheckCmpFollow
/*  f169ff0:	24841624 */ 	addiu	$a0,$a0,0x1624
/*  f169ff4:	54400004 */ 	bnezl	$v0,.L0f16a008
/*  f169ff8:	00008825 */ 	or	$s1,$zero,$zero
/*  f169ffc:	8e6c0284 */ 	lw	$t4,0x284($s3)
/*  f16a000:	ad801624 */ 	sw	$zero,0x1624($t4)
/*  f16a004:	00008825 */ 	or	$s1,$zero,$zero
.L0f16a008:
/*  f16a008:	00008025 */ 	or	$s0,$zero,$zero
.L0f16a00c:
/*  f16a00c:	8e6e0284 */ 	lw	$t6,0x284($s3)
/*  f16a010:	02202825 */ 	or	$a1,$s1,$zero
/*  f16a014:	01d02021 */ 	addu	$a0,$t6,$s0
/*  f16a018:	0fc5a23f */ 	jal	threatCheckCmpFollow
/*  f16a01c:	24841630 */ 	addiu	$a0,$a0,0x1630
/*  f16a020:	14400007 */ 	bnez	$v0,.L0f16a040
/*  f16a024:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f16a028:	8e6d0284 */ 	lw	$t5,0x284($s3)
/*  f16a02c:	01b07821 */ 	addu	$t7,$t5,$s0
/*  f16a030:	a5f71634 */ 	sh	$s7,0x1634($t7)
/*  f16a034:	8e6a0284 */ 	lw	$t2,0x284($s3)
/*  f16a038:	0150c021 */ 	addu	$t8,$t2,$s0
/*  f16a03c:	a7161638 */ 	sh	$s6,0x1638($t8)
.L0f16a040:
/*  f16a040:	1634fff2 */ 	bne	$s1,$s4,.L0f16a00c
/*  f16a044:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f16a048:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f16a04c:
/*  f16a04c:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f16a050:	50400071 */ 	beqzl	$v0,.L0f16a218
/*  f16a054:	8e1800d0 */ 	lw	$t8,0xd0($s0)
/*  f16a058:	8e191c54 */ 	lw	$t9,0x1c54($s0)
/*  f16a05c:	8e0b00c4 */ 	lw	$t3,0xc4($s0)
/*  f16a060:	03206027 */ 	nor	$t4,$t9,$zero
/*  f16a064:	016c7024 */ 	and	$t6,$t3,$t4
/*  f16a068:	31cd0004 */ 	andi	$t5,$t6,0x4
/*  f16a06c:	51a0006a */ 	beqzl	$t5,.L0f16a218
/*  f16a070:	8e1800d0 */ 	lw	$t8,0xd0($s0)
/*  f16a074:	804f0039 */ 	lb	$t7,0x39($v0)
/*  f16a078:	51e00067 */ 	beqzl	$t7,.L0f16a218
/*  f16a07c:	8e1800d0 */ 	lw	$t8,0xd0($s0)
/*  f16a080:	9043006b */ 	lbu	$v1,0x6b($v0)
/*  f16a084:	3c0143c8 */ 	lui	$at,0x43c8
/*  f16a088:	14600010 */ 	bnez	$v1,.L0f16a0cc
/*  f16a08c:	00000000 */ 	nop
/*  f16a090:	44816000 */ 	mtc1	$at,$f12
/*  f16a094:	0fc25822 */ 	jal	objectiveCheckHolograph
/*  f16a098:	00000000 */ 	nop
/*  f16a09c:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f16a0a0:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f16a0a4:	240504ff */ 	addiu	$a1,$zero,0x4ff
/*  f16a0a8:	00003025 */ 	or	$a2,$zero,$zero
/*  f16a0ac:	02e03825 */ 	or	$a3,$s7,$zero
/*  f16a0b0:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16a0b4:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16a0b8:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16a0bc:	0c004241 */ 	jal	audioStart
/*  f16a0c0:	afb7001c */ 	sw	$s7,0x1c($sp)
/*  f16a0c4:	10000053 */ 	b	.L0f16a214
/*  f16a0c8:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f16a0cc:
/*  f16a0cc:	17c30032 */ 	bne	$s8,$v1,.L0f16a198
/*  f16a0d0:	3c188008 */ 	lui	$t8,%hi(g_Stages+0x33f)
/*  f16a0d4:	8e0a0490 */ 	lw	$t2,0x490($s0)
/*  f16a0d8:	3c048009 */ 	lui	$a0,%hi(var80090008)
/*  f16a0dc:	24058052 */ 	addiu	$a1,$zero,-32686
/*  f16a0e0:	11400024 */ 	beqz	$t2,.L0f16a174
/*  f16a0e4:	00003025 */ 	or	$a2,$zero,$zero
/*  f16a0e8:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f16a0ec:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f16a0f0:	24058057 */ 	addiu	$a1,$zero,-32681
/*  f16a0f4:	00003025 */ 	or	$a2,$zero,$zero
/*  f16a0f8:	02e03825 */ 	or	$a3,$s7,$zero
/*  f16a0fc:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16a100:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16a104:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16a108:	0c004241 */ 	jal	audioStart
/*  f16a10c:	afb7001c */ 	sw	$s7,0x1c($sp)
/*  f16a110:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f16a114:	240f001c */ 	addiu	$t7,$zero,0x1c
/*  f16a118:	00002825 */ 	or	$a1,$zero,$zero
/*  f16a11c:	8e180490 */ 	lw	$t8,0x490($s0)
/*  f16a120:	27a700e0 */ 	addiu	$a3,$sp,0xe0
/*  f16a124:	2719ffff */ 	addiu	$t9,$t8,%lo(g_Stages+0x33f)
/*  f16a128:	ae190490 */ 	sw	$t9,0x490($s0)
/*  f16a12c:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f16a130:	8e0b0480 */ 	lw	$t3,0x480($s0)
/*  f16a134:	c5700004 */ 	lwc1	$f16,0x4($t3)
/*  f16a138:	e7b000e0 */ 	swc1	$f16,0xe0($sp)
/*  f16a13c:	8e0c0480 */ 	lw	$t4,0x480($s0)
/*  f16a140:	c5920008 */ 	lwc1	$f18,0x8($t4)
/*  f16a144:	e7b200e4 */ 	swc1	$f18,0xe4($sp)
/*  f16a148:	8e0e0480 */ 	lw	$t6,0x480($s0)
/*  f16a14c:	c5c4000c */ 	lwc1	$f4,0xc($t6)
/*  f16a150:	e7a400e8 */ 	swc1	$f4,0xe8($sp)
/*  f16a154:	8e0d0480 */ 	lw	$t5,0x480($s0)
/*  f16a158:	8da40000 */ 	lw	$a0,0x0($t5)
/*  f16a15c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f16a160:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f16a164:	0fc244b7 */ 	jal	func0f0912dc
/*  f16a168:	24860008 */ 	addiu	$a2,$a0,%lo(var80090008)
/*  f16a16c:	10000008 */ 	b	.L0f16a190
/*  f16a170:	00000000 */ 	nop
.L0f16a174:
/*  f16a174:	8c845200 */ 	lw	$a0,0x5200($a0)
/*  f16a178:	02e03825 */ 	or	$a3,$s7,$zero
/*  f16a17c:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16a180:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16a184:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16a188:	0c004241 */ 	jal	audioStart
/*  f16a18c:	afb7001c */ 	sw	$s7,0x1c($sp)
.L0f16a190:
/*  f16a190:	10000020 */ 	b	.L0f16a214
/*  f16a194:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f16a198:
/*  f16a198:	27184088 */ 	addiu	$t8,$t8,16520
/*  f16a19c:	8f010000 */ 	lw	$at,0x0($t8)
/*  f16a1a0:	27aa00d4 */ 	addiu	$t2,$sp,0xd4
/*  f16a1a4:	8f0c0004 */ 	lw	$t4,0x4($t8)
/*  f16a1a8:	ad410000 */ 	sw	$at,0x0($t2)
/*  f16a1ac:	8f010008 */ 	lw	$at,0x8($t8)
/*  f16a1b0:	3c0e8008 */ 	lui	$t6,%hi(var80084094)
/*  f16a1b4:	ad4c0004 */ 	sw	$t4,0x4($t2)
/*  f16a1b8:	ad410008 */ 	sw	$at,0x8($t2)
/*  f16a1bc:	8dce4094 */ 	lw	$t6,%lo(var80084094)($t6)
/*  f16a1c0:	24070017 */ 	addiu	$a3,$zero,0x17
/*  f16a1c4:	afae00d0 */ 	sw	$t6,0xd0($sp)
/*  f16a1c8:	8e0d0480 */ 	lw	$t5,0x480($s0)
/*  f16a1cc:	8da40000 */ 	lw	$a0,0x0($t5)
/*  f16a1d0:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f16a1d4:	24850008 */ 	addiu	$a1,$a0,0x8
/*  f16a1d8:	0fc4a640 */ 	jal	explosionCreateSimple
/*  f16a1dc:	24860028 */ 	addiu	$a2,$a0,0x28
/*  f16a1e0:	8e6f0284 */ 	lw	$t7,0x284($s3)
/*  f16a1e4:	27aa00d0 */ 	addiu	$t2,$sp,0xd0
/*  f16a1e8:	27a500d4 */ 	addiu	$a1,$sp,0xd4
/*  f16a1ec:	8deb0480 */ 	lw	$t3,0x480($t7)
/*  f16a1f0:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f16a1f4:	00003825 */ 	or	$a3,$zero,$zero
/*  f16a1f8:	8d790000 */ 	lw	$t9,0x0($t3)
/*  f16a1fc:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f16a200:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f16a204:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f16a208:	0fc0c66a */ 	jal	func0f0319a8
/*  f16a20c:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f16a210:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f16a214:
/*  f16a214:	8e1800d0 */ 	lw	$t8,0xd0($s0)
.L0f16a218:
/*  f16a218:	5300000c */ 	beqzl	$t8,.L0f16a24c
/*  f16a21c:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f16a220:	0fc18b9d */ 	jal	func0f062e74
/*  f16a224:	00002025 */ 	or	$a0,$zero,$zero
/*  f16a228:	10400012 */ 	beqz	$v0,.L0f16a274
/*  f16a22c:	00000000 */ 	nop
/*  f16a230:	0fc28886 */ 	jal	func0f0a2218
/*  f16a234:	00002025 */ 	or	$a0,$zero,$zero
/*  f16a238:	0fc28886 */ 	jal	func0f0a2218
/*  f16a23c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f16a240:	1000000c */ 	b	.L0f16a274
/*  f16a244:	00000000 */ 	nop
/*  f16a248:	8e020480 */ 	lw	$v0,0x480($s0)
.L0f16a24c:
/*  f16a24c:	10400009 */ 	beqz	$v0,.L0f16a274
/*  f16a250:	00000000 */ 	nop
/*  f16a254:	804c0037 */ 	lb	$t4,0x37($v0)
/*  f16a258:	11800006 */ 	beqz	$t4,.L0f16a274
/*  f16a25c:	00000000 */ 	nop
/*  f16a260:	904e006a */ 	lbu	$t6,0x6a($v0)
/*  f16a264:	11c00003 */ 	beqz	$t6,.L0f16a274
/*  f16a268:	00000000 */ 	nop
/*  f16a26c:	0fc18b9d */ 	jal	func0f062e74
/*  f16a270:	03c02025 */ 	or	$a0,$s8,$zero
.L0f16a274:
/*  f16a274:	0fc1907d */ 	jal	func0f0641f4
/*  f16a278:	00000000 */ 	nop
/*  f16a27c:	0fc572b8 */ 	jal	func0f15cae0
/*  f16a280:	02402025 */ 	or	$a0,$s2,$zero
/*  f16a284:	3c108007 */ 	lui	$s0,%hi(var80075d68)
/*  f16a288:	8e105d68 */ 	lw	$s0,%lo(var80075d68)($s0)
/*  f16a28c:	00409025 */ 	or	$s2,$v0,$zero
/*  f16a290:	3a0d000f */ 	xori	$t5,$s0,0xf
/*  f16a294:	2db00001 */ 	sltiu	$s0,$t5,0x1
/*  f16a298:	16000005 */ 	bnez	$s0,.L0f16a2b0
/*  f16a29c:	00000000 */ 	nop
/*  f16a2a0:	3c108006 */ 	lui	$s0,%hi(var8005f020)
/*  f16a2a4:	8e10f020 */ 	lw	$s0,%lo(var8005f020)($s0)
/*  f16a2a8:	0010782b */ 	sltu	$t7,$zero,$s0
/*  f16a2ac:	01e08025 */ 	or	$s0,$t7,$zero
.L0f16a2b0:
/*  f16a2b0:	0fc0a126 */ 	jal	func0f028498
/*  f16a2b4:	02002025 */ 	or	$a0,$s0,$zero
/*  f16a2b8:	0fc1fdb4 */ 	jal	func0f07f6d0
/*  f16a2bc:	02402025 */ 	or	$a0,$s2,$zero
/*  f16a2c0:	0fc549b9 */ 	jal	func0f1526e4
/*  f16a2c4:	00402025 */ 	or	$a0,$v0,$zero
/*  f16a2c8:	0fc4c011 */ 	jal	func0f130044
/*  f16a2cc:	00402025 */ 	or	$a0,$v0,$zero
/*  f16a2d0:	0fc4c418 */ 	jal	weatherRender
/*  f16a2d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f16a2d8:	3c0b8006 */ 	lui	$t3,%hi(var80061640)
/*  f16a2dc:	8d6b1640 */ 	lw	$t3,%lo(var80061640)($t3)
/*  f16a2e0:	00409025 */ 	or	$s2,$v0,$zero
/*  f16a2e4:	11600004 */ 	beqz	$t3,.L0f16a2f8
/*  f16a2e8:	00000000 */ 	nop
/*  f16a2ec:	0fc0285a */ 	jal	func0f00a168
/*  f16a2f0:	00402025 */ 	or	$a0,$v0,$zero
/*  f16a2f4:	00409025 */ 	or	$s2,$v0,$zero
.L0f16a2f8:
/*  f16a2f8:	3c198007 */ 	lui	$t9,%hi(var80075d60)
/*  f16a2fc:	8f395d60 */ 	lw	$t9,%lo(var80075d60)($t9)
/*  f16a300:	24010002 */ 	addiu	$at,$zero,0x2
/*  f16a304:	17210005 */ 	bne	$t9,$at,.L0f16a31c
/*  f16a308:	00000000 */ 	nop
/*  f16a30c:	0fc301f2 */ 	jal	func0f0c07c8
/*  f16a310:	02402025 */ 	or	$a0,$s2,$zero
/*  f16a314:	1000000b */ 	b	.L0f16a344
/*  f16a318:	00409025 */ 	or	$s2,$v0,$zero
.L0f16a31c:
/*  f16a31c:	0fc2bbb6 */ 	jal	func0f0aeed8
/*  f16a320:	02402025 */ 	or	$a0,$s2,$zero
/*  f16a324:	8e6a0284 */ 	lw	$t2,0x284($s3)
/*  f16a328:	00409025 */ 	or	$s2,$v0,$zero
/*  f16a32c:	95580010 */ 	lhu	$t8,0x10($t2)
/*  f16a330:	13d80004 */ 	beq	$s8,$t8,.L0f16a344
/*  f16a334:	00000000 */ 	nop
/*  f16a338:	0fc56c45 */ 	jal	func0f15b114
/*  f16a33c:	00402025 */ 	or	$a0,$v0,$zero
/*  f16a340:	00409025 */ 	or	$s2,$v0,$zero
.L0f16a344:
/*  f16a344:	3c0c8007 */ 	lui	$t4,%hi(var80075d78)
/*  f16a348:	8d8c5d78 */ 	lw	$t4,%lo(var80075d78)($t4)
/*  f16a34c:	1d800288 */ 	bgtz	$t4,.L0f16ad70
/*  f16a350:	00000000 */ 	nop
/*  f16a354:	8e6e02ac */ 	lw	$t6,0x2ac($s3)
/*  f16a358:	24010006 */ 	addiu	$at,$zero,0x6
/*  f16a35c:	afa000cc */ 	sw	$zero,0xcc($sp)
/*  f16a360:	15c10109 */ 	bne	$t6,$at,.L0f16a788
/*  f16a364:	00000000 */ 	nop
/*  f16a368:	8e6d04b4 */ 	lw	$t5,0x4b4($s3)
/*  f16a36c:	2401004e */ 	addiu	$at,$zero,0x4e
/*  f16a370:	3c04800a */ 	lui	$a0,%hi(var8009de18)
/*  f16a374:	15a10095 */ 	bne	$t5,$at,.L0f16a5cc
/*  f16a378:	00008025 */ 	or	$s0,$zero,$zero
/*  f16a37c:	44800000 */ 	mtc1	$zero,$f0
/*  f16a380:	8484de18 */ 	lh	$a0,%lo(var8009de18)($a0)
/*  f16a384:	0c008dda */ 	jal	animGetNumFrames
/*  f16a388:	e7a000c4 */ 	swc1	$f0,0xc4($sp)
/*  f16a38c:	3c03800a */ 	lui	$v1,%hi(var8009de10)
/*  f16a390:	8c63de10 */ 	lw	$v1,%lo(var8009de10)($v1)
/*  f16a394:	c7a000c4 */ 	lwc1	$f0,0xc4($sp)
/*  f16a398:	3c0f800a */ 	lui	$t7,%hi(var8009de18)
/*  f16a39c:	2861005a */ 	slti	$at,$v1,0x5a
/*  f16a3a0:	10200009 */ 	beqz	$at,.L0f16a3c8
/*  f16a3a4:	2444ffff */ 	addiu	$a0,$v0,-1
/*  f16a3a8:	44833000 */ 	mtc1	$v1,$f6
/*  f16a3ac:	3c0142b4 */ 	lui	$at,0x42b4
/*  f16a3b0:	44815000 */ 	mtc1	$at,$f10
/*  f16a3b4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f16a3b8:	3c013f80 */ 	lui	$at,0x3f80
/*  f16a3bc:	44819000 */ 	mtc1	$at,$f18
/*  f16a3c0:	460a4403 */ 	div.s	$f16,$f8,$f10
/*  f16a3c4:	46109001 */ 	sub.s	$f0,$f18,$f16
.L0f16a3c8:
/*  f16a3c8:	85efde18 */ 	lh	$t7,%lo(var8009de18)($t7)
/*  f16a3cc:	2401046c */ 	addiu	$at,$zero,0x46c
/*  f16a3d0:	2498ffe2 */ 	addiu	$t8,$a0,-30
/*  f16a3d4:	11e1000d */ 	beq	$t7,$at,.L0f16a40c
/*  f16a3d8:	3c0de700 */ 	lui	$t5,0xe700
/*  f16a3dc:	2444ffff */ 	addiu	$a0,$v0,-1
/*  f16a3e0:	248bffa6 */ 	addiu	$t3,$a0,-90
/*  f16a3e4:	0163082a */ 	slt	$at,$t3,$v1
/*  f16a3e8:	10200012 */ 	beqz	$at,.L0f16a434
/*  f16a3ec:	0064c823 */ 	subu	$t9,$v1,$a0
/*  f16a3f0:	272a005a */ 	addiu	$t2,$t9,0x5a
/*  f16a3f4:	448a2000 */ 	mtc1	$t2,$f4
/*  f16a3f8:	3c0142b4 */ 	lui	$at,0x42b4
/*  f16a3fc:	44814000 */ 	mtc1	$at,$f8
/*  f16a400:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f16a404:	1000000b */ 	b	.L0f16a434
/*  f16a408:	46083003 */ 	div.s	$f0,$f6,$f8
.L0f16a40c:
/*  f16a40c:	0303082a */ 	slt	$at,$t8,$v1
/*  f16a410:	10200008 */ 	beqz	$at,.L0f16a434
/*  f16a414:	00646023 */ 	subu	$t4,$v1,$a0
/*  f16a418:	258e001e */ 	addiu	$t6,$t4,0x1e
/*  f16a41c:	448e5000 */ 	mtc1	$t6,$f10
/*  f16a420:	3c0141f0 */ 	lui	$at,0x41f0
/*  f16a424:	44818000 */ 	mtc1	$at,$f16
/*  f16a428:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f16a42c:	2410ff00 */ 	addiu	$s0,$zero,-256
/*  f16a430:	46109003 */ 	div.s	$f0,$f18,$f16
.L0f16a434:
/*  f16a434:	44802000 */ 	mtc1	$zero,$f4
/*  f16a438:	3c0fb900 */ 	lui	$t7,0xb900
/*  f16a43c:	3c0b0050 */ 	lui	$t3,0x50
/*  f16a440:	4600203c */ 	c.lt.s	$f4,$f0
/*  f16a444:	02401025 */ 	or	$v0,$s2,$zero
/*  f16a448:	356b4340 */ 	ori	$t3,$t3,0x4340
/*  f16a44c:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f16a450:	4500005e */ 	bc1f	.L0f16a5cc
/*  f16a454:	3c19fcff */ 	lui	$t9,0xfcff
/*  f16a458:	3c01437f */ 	lui	$at,0x437f
/*  f16a45c:	44813000 */ 	mtc1	$at,$f6
/*  f16a460:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f16a464:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f16a468:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f16a46c:	02401825 */ 	or	$v1,$s2,$zero
/*  f16a470:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f16a474:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f16a478:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f16a47c:	02402025 */ 	or	$a0,$s2,$zero
/*  f16a480:	ac6b0004 */ 	sw	$t3,0x4($v1)
/*  f16a484:	444cf800 */ 	cfc1	$t4,$31
/*  f16a488:	44cef800 */ 	ctc1	$t6,$31
/*  f16a48c:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f16a490:	3c0afffd */ 	lui	$t2,0xfffd
/*  f16a494:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f16a498:	354af6fb */ 	ori	$t2,$t2,0xf6fb
/*  f16a49c:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f16a4a0:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f16a4a4:	444ef800 */ 	cfc1	$t6,$31
/*  f16a4a8:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f16a4ac:	ac8a0004 */ 	sw	$t2,0x4($a0)
/*  f16a4b0:	02402825 */ 	or	$a1,$s2,$zero
/*  f16a4b4:	3c18fa00 */ 	lui	$t8,0xfa00
/*  f16a4b8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f16a4bc:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f16a4c0:	11c00013 */ 	beqz	$t6,.L0f16a510
/*  f16a4c4:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f16a4c8:	3c014f00 */ 	lui	$at,0x4f00
/*  f16a4cc:	44815000 */ 	mtc1	$at,$f10
/*  f16a4d0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f16a4d4:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f16a4d8:	44cef800 */ 	ctc1	$t6,$31
/*  f16a4dc:	00000000 */ 	nop
/*  f16a4e0:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f16a4e4:	444ef800 */ 	cfc1	$t6,$31
/*  f16a4e8:	00000000 */ 	nop
/*  f16a4ec:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f16a4f0:	15c00005 */ 	bnez	$t6,.L0f16a508
/*  f16a4f4:	00000000 */ 	nop
/*  f16a4f8:	440e5000 */ 	mfc1	$t6,$f10
/*  f16a4fc:	3c018000 */ 	lui	$at,0x8000
/*  f16a500:	10000007 */ 	b	.L0f16a520
/*  f16a504:	01c17025 */ 	or	$t6,$t6,$at
.L0f16a508:
/*  f16a508:	10000005 */ 	b	.L0f16a520
/*  f16a50c:	240effff */ 	addiu	$t6,$zero,-1
.L0f16a510:
/*  f16a510:	440e5000 */ 	mfc1	$t6,$f10
/*  f16a514:	00000000 */ 	nop
/*  f16a518:	05c0fffb */ 	bltz	$t6,.L0f16a508
/*  f16a51c:	00000000 */ 	nop
.L0f16a520:
/*  f16a520:	020e6825 */ 	or	$t5,$s0,$t6
/*  f16a524:	acad0004 */ 	sw	$t5,0x4($a1)
/*  f16a528:	44ccf800 */ 	ctc1	$t4,$31
/*  f16a52c:	afb200a8 */ 	sw	$s2,0xa8($sp)
/*  f16a530:	0c002f22 */ 	jal	viGetViewX
/*  f16a534:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f16a538:	0c002f40 */ 	jal	viGetViewLeft
/*  f16a53c:	a7a2008a */ 	sh	$v0,0x8a($sp)
/*  f16a540:	00028400 */ 	sll	$s0,$v0,0x10
/*  f16a544:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f16a548:	0c002f44 */ 	jal	viGetViewTop
/*  f16a54c:	01e08025 */ 	or	$s0,$t7,$zero
/*  f16a550:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f16a554:	00115c03 */ 	sra	$t3,$s1,0x10
/*  f16a558:	0c002f26 */ 	jal	viGetViewY
/*  f16a55c:	01608825 */ 	or	$s1,$t3,$zero
/*  f16a560:	87ae008a */ 	lh	$t6,0x8a($sp)
/*  f16a564:	0051c821 */ 	addu	$t9,$v0,$s1
/*  f16a568:	332a03ff */ 	andi	$t2,$t9,0x3ff
/*  f16a56c:	000ac080 */ 	sll	$t8,$t2,0x2
/*  f16a570:	020e6821 */ 	addu	$t5,$s0,$t6
/*  f16a574:	31af03ff */ 	andi	$t7,$t5,0x3ff
/*  f16a578:	3c01f600 */ 	lui	$at,0xf600
/*  f16a57c:	8faa00a8 */ 	lw	$t2,0xa8($sp)
/*  f16a580:	03016025 */ 	or	$t4,$t8,$at
/*  f16a584:	000f5b80 */ 	sll	$t3,$t7,0xe
/*  f16a588:	018bc825 */ 	or	$t9,$t4,$t3
/*  f16a58c:	0c002f40 */ 	jal	viGetViewLeft
/*  f16a590:	ad590000 */ 	sw	$t9,0x0($t2)
/*  f16a594:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f16a598:	0011c403 */ 	sra	$t8,$s1,0x10
/*  f16a59c:	0c002f44 */ 	jal	viGetViewTop
/*  f16a5a0:	03008825 */ 	or	$s1,$t8,$zero
/*  f16a5a4:	304e03ff */ 	andi	$t6,$v0,0x3ff
/*  f16a5a8:	322f03ff */ 	andi	$t7,$s1,0x3ff
/*  f16a5ac:	8fb900a8 */ 	lw	$t9,0xa8($sp)
/*  f16a5b0:	000f6380 */ 	sll	$t4,$t7,0xe
/*  f16a5b4:	000e6880 */ 	sll	$t5,$t6,0x2
/*  f16a5b8:	01ac5825 */ 	or	$t3,$t5,$t4
/*  f16a5bc:	02402025 */ 	or	$a0,$s2,$zero
/*  f16a5c0:	0fc54e0e */ 	jal	func0f153838
/*  f16a5c4:	af2b0004 */ 	sw	$t3,0x4($t9)
/*  f16a5c8:	00409025 */ 	or	$s2,$v0,$zero
.L0f16a5cc:
/*  f16a5cc:	3c10800a */ 	lui	$s0,%hi(var8009de18)
/*  f16a5d0:	8610de18 */ 	lh	$s0,%lo(var8009de18)($s0)
/*  f16a5d4:	24010181 */ 	addiu	$at,$zero,0x181
/*  f16a5d8:	3c048008 */ 	lui	$a0,%hi(var80084098)
/*  f16a5dc:	12010011 */ 	beq	$s0,$at,.L0f16a624
/*  f16a5e0:	24010183 */ 	addiu	$at,$zero,0x183
/*  f16a5e4:	1201000f */ 	beq	$s0,$at,.L0f16a624
/*  f16a5e8:	24010188 */ 	addiu	$at,$zero,0x188
/*  f16a5ec:	1201000d */ 	beq	$s0,$at,.L0f16a624
/*  f16a5f0:	240101e5 */ 	addiu	$at,$zero,0x1e5
/*  f16a5f4:	16010064 */ 	bne	$s0,$at,.L0f16a788
/*  f16a5f8:	3c03800a */ 	lui	$v1,%hi(var8009de10)
/*  f16a5fc:	8c63de10 */ 	lw	$v1,%lo(var8009de10)($v1)
/*  f16a600:	28610348 */ 	slti	$at,$v1,0x348
/*  f16a604:	14200060 */ 	bnez	$at,.L0f16a788
/*  f16a608:	28610583 */ 	slti	$at,$v1,0x583
/*  f16a60c:	1020005e */ 	beqz	$at,.L0f16a788
/*  f16a610:	00000000 */ 	nop
/*  f16a614:	0fc51f89 */ 	jal	hudRenderHorizonScanner
/*  f16a618:	02402025 */ 	or	$a0,$s2,$zero
/*  f16a61c:	1000005a */ 	b	.L0f16a788
/*  f16a620:	00409025 */ 	or	$s2,$v0,$zero
.L0f16a624:
/*  f16a624:	8c844098 */ 	lw	$a0,%lo(var80084098)($a0)
/*  f16a628:	00008025 */ 	or	$s0,$zero,$zero
/*  f16a62c:	afbe00cc */ 	sw	$s8,0xcc($sp)
/*  f16a630:	1480000b */ 	bnez	$a0,.L0f16a660
/*  f16a634:	2405059f */ 	addiu	$a1,$zero,0x59f
/*  f16a638:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f16a63c:	3c068008 */ 	lui	$a2,%hi(var80084098)
/*  f16a640:	24c64098 */ 	addiu	$a2,$a2,%lo(var80084098)
/*  f16a644:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f16a648:	02e03825 */ 	or	$a3,$s7,$zero
/*  f16a64c:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16a650:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16a654:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16a658:	0c004241 */ 	jal	audioStart
/*  f16a65c:	afb7001c */ 	sw	$s7,0x1c($sp)
.L0f16a660:
/*  f16a660:	3c0a8008 */ 	lui	$t2,%hi(var8008409c)
/*  f16a664:	8d4a409c */ 	lw	$t2,%lo(var8008409c)($t2)
/*  f16a668:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f16a66c:	3c018008 */ 	lui	$at,%hi(var8008409c)
/*  f16a670:	01587023 */ 	subu	$t6,$t2,$t8
/*  f16a674:	05c1000b */ 	bgez	$t6,.L0f16a6a4
/*  f16a678:	ac2e409c */ 	sw	$t6,%lo(var8008409c)($at)
/*  f16a67c:	0c004b70 */ 	jal	random
/*  f16a680:	00000000 */ 	nop
/*  f16a684:	240100c8 */ 	addiu	$at,$zero,0xc8
/*  f16a688:	0041001b */ 	divu	$zero,$v0,$at
/*  f16a68c:	00007810 */ 	mfhi	$t7
/*  f16a690:	25ed0028 */ 	addiu	$t5,$t7,0x28
/*  f16a694:	3c018008 */ 	lui	$at,%hi(var8008409c)
/*  f16a698:	ac2d409c */ 	sw	$t5,%lo(var8008409c)($at)
/*  f16a69c:	3c018008 */ 	lui	$at,%hi(var800840a0)
/*  f16a6a0:	a02040a0 */ 	sb	$zero,%lo(var800840a0)($at)
.L0f16a6a4:
/*  f16a6a4:	02402025 */ 	or	$a0,$s2,$zero
/*  f16a6a8:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f16a6ac:	0fc50a63 */ 	jal	func0f14298c
/*  f16a6b0:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f16a6b4:	3c0c8008 */ 	lui	$t4,%hi(var8008409c)
/*  f16a6b8:	8d8c409c */ 	lw	$t4,%lo(var8008409c)($t4)
/*  f16a6bc:	00409025 */ 	or	$s2,$v0,$zero
/*  f16a6c0:	3c0b8008 */ 	lui	$t3,%hi(var800840a0)
/*  f16a6c4:	2981000f */ 	slti	$at,$t4,0xf
/*  f16a6c8:	10200017 */ 	beqz	$at,.L0f16a728
/*  f16a6cc:	00000000 */ 	nop
/*  f16a6d0:	916b40a0 */ 	lbu	$t3,%lo(var800840a0)($t3)
/*  f16a6d4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f16a6d8:	3c018008 */ 	lui	$at,%hi(var800840a0)
/*  f16a6dc:	1560000b */ 	bnez	$t3,.L0f16a70c
/*  f16a6e0:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f16a6e4:	a03940a0 */ 	sb	$t9,%lo(var800840a0)($at)
/*  f16a6e8:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f16a6ec:	2405059e */ 	addiu	$a1,$zero,0x59e
/*  f16a6f0:	00003025 */ 	or	$a2,$zero,$zero
/*  f16a6f4:	02e03825 */ 	or	$a3,$s7,$zero
/*  f16a6f8:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16a6fc:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16a700:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16a704:	0c004241 */ 	jal	audioStart
/*  f16a708:	afb7001c */ 	sw	$s7,0x1c($sp)
.L0f16a70c:
/*  f16a70c:	3c0a8008 */ 	lui	$t2,%hi(var8008409c)
/*  f16a710:	8d4a409c */ 	lw	$t2,%lo(var8008409c)($t2)
/*  f16a714:	240e00e1 */ 	addiu	$t6,$zero,0xe1
/*  f16a718:	000ac080 */ 	sll	$t8,$t2,0x2
/*  f16a71c:	030ac021 */ 	addu	$t8,$t8,$t2
/*  f16a720:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f16a724:	01d88023 */ 	subu	$s0,$t6,$t8
.L0f16a728:
/*  f16a728:	0c004b70 */ 	jal	random
/*  f16a72c:	00000000 */ 	nop
/*  f16a730:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f16a734:	0041001b */ 	divu	$zero,$v0,$at
/*  f16a738:	00007810 */ 	mfhi	$t7
/*  f16a73c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f16a740:	15e1000b */ 	bne	$t7,$at,.L0f16a770
/*  f16a744:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f16a748:	241000ff */ 	addiu	$s0,$zero,0xff
/*  f16a74c:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f16a750:	2405059d */ 	addiu	$a1,$zero,0x59d
/*  f16a754:	00003025 */ 	or	$a2,$zero,$zero
/*  f16a758:	02e03825 */ 	or	$a3,$s7,$zero
/*  f16a75c:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16a760:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16a764:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16a768:	0c004241 */ 	jal	audioStart
/*  f16a76c:	afb7001c */ 	sw	$s7,0x1c($sp)
.L0f16a770:
/*  f16a770:	12000005 */ 	beqz	$s0,.L0f16a788
/*  f16a774:	02402025 */ 	or	$a0,$s2,$zero
/*  f16a778:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f16a77c:	0fc50991 */ 	jal	func0f142644
/*  f16a780:	02003025 */ 	or	$a2,$s0,$zero
/*  f16a784:	00409025 */ 	or	$s2,$v0,$zero
.L0f16a788:
/*  f16a788:	3c048008 */ 	lui	$a0,%hi(var80084098)
/*  f16a78c:	8c844098 */ 	lw	$a0,%lo(var80084098)($a0)
/*  f16a790:	8fad00cc */ 	lw	$t5,0xcc($sp)
/*  f16a794:	50800006 */ 	beqzl	$a0,.L0f16a7b0
/*  f16a798:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f16a79c:	55a00004 */ 	bnezl	$t5,.L0f16a7b0
/*  f16a7a0:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f16a7a4:	0c00cec9 */ 	jal	audioStop
/*  f16a7a8:	00000000 */ 	nop
/*  f16a7ac:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f16a7b0:
/*  f16a7b0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f16a7b4:	960c0010 */ 	lhu	$t4,0x10($s0)
/*  f16a7b8:	5581001c */ 	bnel	$t4,$at,.L0f16a82c
/*  f16a7bc:	96030010 */ 	lhu	$v1,0x10($s0)
/*  f16a7c0:	8e6b02ac */ 	lw	$t3,0x2ac($s3)
/*  f16a7c4:	24010006 */ 	addiu	$at,$zero,0x6
/*  f16a7c8:	02402025 */ 	or	$a0,$s2,$zero
/*  f16a7cc:	11610016 */ 	beq	$t3,$at,.L0f16a828
/*  f16a7d0:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f16a7d4:	0fc509dd */ 	jal	func0f142774
/*  f16a7d8:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f16a7dc:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f16a7e0:	00409025 */ 	or	$s2,$v0,$zero
/*  f16a7e4:	2401005a */ 	addiu	$at,$zero,0x5a
/*  f16a7e8:	8e0300c8 */ 	lw	$v1,0xc8($s0)
/*  f16a7ec:	02402025 */ 	or	$a0,$s2,$zero
/*  f16a7f0:	3c054fff */ 	lui	$a1,0x4fff
/*  f16a7f4:	1860000c */ 	blez	$v1,.L0f16a828
/*  f16a7f8:	00033200 */ 	sll	$a2,$v1,0x8
/*  f16a7fc:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f16a800:	00c1001a */ 	div	$zero,$a2,$at
/*  f16a804:	00003012 */ 	mflo	$a2
/*  f16a808:	2cc10100 */ 	sltiu	$at,$a2,0x100
/*  f16a80c:	14200002 */ 	bnez	$at,.L0f16a818
/*  f16a810:	00000000 */ 	nop
/*  f16a814:	240600ff */ 	addiu	$a2,$zero,0xff
.L0f16a818:
/*  f16a818:	0fc50991 */ 	jal	func0f142644
/*  f16a81c:	34a5ffff */ 	ori	$a1,$a1,0xffff
/*  f16a820:	00409025 */ 	or	$s2,$v0,$zero
/*  f16a824:	8e700284 */ 	lw	$s0,0x284($s3)
.L0f16a828:
/*  f16a828:	96030010 */ 	lhu	$v1,0x10($s0)
.L0f16a82c:
/*  f16a82c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f16a830:	02402025 */ 	or	$a0,$s2,$zero
/*  f16a834:	14610009 */ 	bne	$v1,$at,.L0f16a85c
/*  f16a838:	3c054fff */ 	lui	$a1,0x4fff
/*  f16a83c:	34a5ffff */ 	ori	$a1,$a1,0xffff
/*  f16a840:	0fc50991 */ 	jal	func0f142644
/*  f16a844:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f16a848:	8e6a0284 */ 	lw	$t2,0x284($s3)
/*  f16a84c:	00409025 */ 	or	$s2,$v0,$zero
/*  f16a850:	a5400010 */ 	sh	$zero,0x10($t2)
/*  f16a854:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f16a858:	96030010 */ 	lhu	$v1,0x10($s0)
.L0f16a85c:
/*  f16a85c:	57c30017 */ 	bnel	$s8,$v1,.L0f16a8bc
/*  f16a860:	8e630460 */ 	lw	$v1,0x460($s3)
/*  f16a864:	8e6e02ac */ 	lw	$t6,0x2ac($s3)
/*  f16a868:	24010006 */ 	addiu	$at,$zero,0x6
/*  f16a86c:	51c10013 */ 	beql	$t6,$at,.L0f16a8bc
/*  f16a870:	8e630460 */ 	lw	$v1,0x460($s3)
/*  f16a874:	8e020254 */ 	lw	$v0,0x254($s0)
/*  f16a878:	24060063 */ 	addiu	$a2,$zero,0x63
/*  f16a87c:	240d00f9 */ 	addiu	$t5,$zero,0xf9
/*  f16a880:	284100c8 */ 	slti	$at,$v0,0xc8
/*  f16a884:	10200004 */ 	beqz	$at,.L0f16a898
/*  f16a888:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f16a88c:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f16a890:	00187883 */ 	sra	$t7,$t8,0x2
/*  f16a894:	01af3023 */ 	subu	$a2,$t5,$t7
.L0f16a898:
/*  f16a898:	3c017f1b */ 	lui	$at,%hi(var7f1b7850)
/*  f16a89c:	c4207850 */ 	lwc1	$f0,%lo(var7f1b7850)($at)
/*  f16a8a0:	02402025 */ 	or	$a0,$s2,$zero
/*  f16a8a4:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f16a8a8:	44070000 */ 	mfc1	$a3,$f0
/*  f16a8ac:	0fc50afc */ 	jal	func0f142bf0
/*  f16a8b0:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f16a8b4:	00409025 */ 	or	$s2,$v0,$zero
/*  f16a8b8:	8e630460 */ 	lw	$v1,0x460($s3)
.L0f16a8bc:
/*  f16a8bc:	18600003 */ 	blez	$v1,.L0f16a8cc
/*  f16a8c0:	2861001e */ 	slti	$at,$v1,0x1e
/*  f16a8c4:	5420000c */ 	bnezl	$at,.L0f16a8f8
/*  f16a8c8:	2401001e */ 	addiu	$at,$zero,0x1e
.L0f16a8cc:
/*  f16a8cc:	8e620464 */ 	lw	$v0,0x464($s3)
/*  f16a8d0:	10400004 */ 	beqz	$v0,.L0f16a8e4
/*  f16a8d4:	00000000 */ 	nop
/*  f16a8d8:	8e6c0468 */ 	lw	$t4,0x468($s3)
/*  f16a8dc:	51800006 */ 	beqzl	$t4,.L0f16a8f8
/*  f16a8e0:	2401001e */ 	addiu	$at,$zero,0x1e
.L0f16a8e4:
/*  f16a8e4:	54400085 */ 	bnezl	$v0,.L0f16aafc
/*  f16a8e8:	28610010 */ 	slti	$at,$v1,0x10
/*  f16a8ec:	8e6b0468 */ 	lw	$t3,0x468($s3)
/*  f16a8f0:	11600081 */ 	beqz	$t3,.L0f16aaf8
/*  f16a8f4:	2401001e */ 	addiu	$at,$zero,0x1e
.L0f16a8f8:
/*  f16a8f8:	54610018 */ 	bnel	$v1,$at,.L0f16a95c
/*  f16a8fc:	2861000f */ 	slti	$at,$v1,0xf
/*  f16a900:	8e790464 */ 	lw	$t9,0x464($s3)
/*  f16a904:	57200015 */ 	bnezl	$t9,.L0f16a95c
/*  f16a908:	2861000f */ 	slti	$at,$v1,0xf
/*  f16a90c:	0fc5ae15 */ 	jal	getEffectiveSlowMotion
/*  f16a910:	00000000 */ 	nop
/*  f16a914:	10400003 */ 	beqz	$v0,.L0f16a924
/*  f16a918:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f16a91c:	10000002 */ 	b	.L0f16a928
/*  f16a920:	241005c9 */ 	addiu	$s0,$zero,0x5c9
.L0f16a924:
/*  f16a924:	241002ad */ 	addiu	$s0,$zero,0x2ad
.L0f16a928:
/*  f16a928:	00102c00 */ 	sll	$a1,$s0,0x10
/*  f16a92c:	00055403 */ 	sra	$t2,$a1,0x10
/*  f16a930:	01402825 */ 	or	$a1,$t2,$zero
/*  f16a934:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f16a938:	00003025 */ 	or	$a2,$zero,$zero
/*  f16a93c:	02e03825 */ 	or	$a3,$s7,$zero
/*  f16a940:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16a944:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16a948:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16a94c:	0c004241 */ 	jal	audioStart
/*  f16a950:	afb7001c */ 	sw	$s7,0x1c($sp)
/*  f16a954:	8e630460 */ 	lw	$v1,0x460($s3)
/*  f16a958:	2861000f */ 	slti	$at,$v1,0xf
.L0f16a95c:
/*  f16a95c:	10200026 */ 	beqz	$at,.L0f16a9f8
/*  f16a960:	240d001e */ 	addiu	$t5,$zero,0x1e
/*  f16a964:	2401000f */ 	addiu	$at,$zero,0xf
/*  f16a968:	00033080 */ 	sll	$a2,$v1,0x2
/*  f16a96c:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f16a970:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16a974:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f16a978:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16a97c:	00c33021 */ 	addu	$a2,$a2,$v1
/*  f16a980:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16a984:	00c1001a */ 	div	$zero,$a2,$at
/*  f16a988:	44839000 */ 	mtc1	$v1,$f18
/*  f16a98c:	3c017f1b */ 	lui	$at,%hi(var7f1b7854)
/*  f16a990:	c4247854 */ 	lwc1	$f4,%lo(var7f1b7854)($at)
/*  f16a994:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f16a998:	3c017f1b */ 	lui	$at,%hi(var7f1b7858)
/*  f16a99c:	c4287858 */ 	lwc1	$f8,%lo(var7f1b7858)($at)
/*  f16a9a0:	00003012 */ 	mflo	$a2
/*  f16a9a4:	02402025 */ 	or	$a0,$s2,$zero
/*  f16a9a8:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f16a9ac:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f16a9b0:	46083000 */ 	add.s	$f0,$f6,$f8
/*  f16a9b4:	44070000 */ 	mfc1	$a3,$f0
/*  f16a9b8:	0fc50afc */ 	jal	func0f142bf0
/*  f16a9bc:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f16a9c0:	8e780460 */ 	lw	$t8,0x460($s3)
/*  f16a9c4:	3c017f1b */ 	lui	$at,%hi(var7f1b785c)
/*  f16a9c8:	c430785c */ 	lwc1	$f16,%lo(var7f1b785c)($at)
/*  f16a9cc:	44985000 */ 	mtc1	$t8,$f10
/*  f16a9d0:	00402025 */ 	or	$a0,$v0,$zero
/*  f16a9d4:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f16a9d8:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f16a9dc:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f16a9e0:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f16a9e4:	46109102 */ 	mul.s	$f4,$f18,$f16
/*  f16a9e8:	0fc2ec13 */ 	jal	fadeDraw
/*  f16a9ec:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f16a9f0:	10000029 */ 	b	.L0f16aa98
/*  f16a9f4:	00409025 */ 	or	$s2,$v0,$zero
.L0f16a9f8:
/*  f16a9f8:	2401000f */ 	addiu	$at,$zero,0xf
/*  f16a9fc:	01a31023 */ 	subu	$v0,$t5,$v1
/*  f16aa00:	00023080 */ 	sll	$a2,$v0,0x2
/*  f16aa04:	00c23023 */ 	subu	$a2,$a2,$v0
/*  f16aa08:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16aa0c:	00c23023 */ 	subu	$a2,$a2,$v0
/*  f16aa10:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16aa14:	00c23021 */ 	addu	$a2,$a2,$v0
/*  f16aa18:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16aa1c:	00c1001a */ 	div	$zero,$a2,$at
/*  f16aa20:	44823000 */ 	mtc1	$v0,$f6
/*  f16aa24:	3c017f1b */ 	lui	$at,%hi(var7f1b7860)
/*  f16aa28:	c42a7860 */ 	lwc1	$f10,%lo(var7f1b7860)($at)
/*  f16aa2c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f16aa30:	3c017f1b */ 	lui	$at,%hi(var7f1b7864)
/*  f16aa34:	c4307864 */ 	lwc1	$f16,%lo(var7f1b7864)($at)
/*  f16aa38:	00003012 */ 	mflo	$a2
/*  f16aa3c:	02402025 */ 	or	$a0,$s2,$zero
/*  f16aa40:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f16aa44:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f16aa48:	46109000 */ 	add.s	$f0,$f18,$f16
/*  f16aa4c:	44070000 */ 	mfc1	$a3,$f0
/*  f16aa50:	0fc50afc */ 	jal	func0f142bf0
/*  f16aa54:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f16aa58:	8e6c0460 */ 	lw	$t4,0x460($s3)
/*  f16aa5c:	3c0141f0 */ 	lui	$at,0x41f0
/*  f16aa60:	44812000 */ 	mtc1	$at,$f4
/*  f16aa64:	448c3000 */ 	mtc1	$t4,$f6
/*  f16aa68:	3c017f1b */ 	lui	$at,%hi(var7f1b7868)
/*  f16aa6c:	c4327868 */ 	lwc1	$f18,%lo(var7f1b7868)($at)
/*  f16aa70:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f16aa74:	00402025 */ 	or	$a0,$v0,$zero
/*  f16aa78:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f16aa7c:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f16aa80:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f16aa84:	46082281 */ 	sub.s	$f10,$f4,$f8
/*  f16aa88:	46125402 */ 	mul.s	$f16,$f10,$f18
/*  f16aa8c:	0fc2ec13 */ 	jal	fadeDraw
/*  f16aa90:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f16aa94:	00409025 */ 	or	$s2,$v0,$zero
.L0f16aa98:
/*  f16aa98:	8e6b028c */ 	lw	$t3,0x28c($s3)
/*  f16aa9c:	5560000c */ 	bnezl	$t3,.L0f16aad0
/*  f16aaa0:	8e630460 */ 	lw	$v1,0x460($s3)
/*  f16aaa4:	8e790464 */ 	lw	$t9,0x464($s3)
/*  f16aaa8:	53200006 */ 	beqzl	$t9,.L0f16aac4
/*  f16aaac:	8e780460 */ 	lw	$t8,0x460($s3)
/*  f16aab0:	8e6a0460 */ 	lw	$t2,0x460($s3)
/*  f16aab4:	254e0001 */ 	addiu	$t6,$t2,0x1
/*  f16aab8:	10000004 */ 	b	.L0f16aacc
/*  f16aabc:	ae6e0460 */ 	sw	$t6,0x460($s3)
/*  f16aac0:	8e780460 */ 	lw	$t8,0x460($s3)
.L0f16aac4:
/*  f16aac4:	270dffff */ 	addiu	$t5,$t8,-1
/*  f16aac8:	ae6d0460 */ 	sw	$t5,0x460($s3)
.L0f16aacc:
/*  f16aacc:	8e630460 */ 	lw	$v1,0x460($s3)
.L0f16aad0:
/*  f16aad0:	2861001f */ 	slti	$at,$v1,0x1f
/*  f16aad4:	14200004 */ 	bnez	$at,.L0f16aae8
/*  f16aad8:	00000000 */ 	nop
/*  f16aadc:	2403001e */ 	addiu	$v1,$zero,0x1e
/*  f16aae0:	10000005 */ 	b	.L0f16aaf8
/*  f16aae4:	ae630460 */ 	sw	$v1,0x460($s3)
.L0f16aae8:
/*  f16aae8:	04630004 */ 	bgezl	$v1,.L0f16aafc
/*  f16aaec:	28610010 */ 	slti	$at,$v1,0x10
/*  f16aaf0:	ae600460 */ 	sw	$zero,0x460($s3)
/*  f16aaf4:	00001825 */ 	or	$v1,$zero,$zero
.L0f16aaf8:
/*  f16aaf8:	28610010 */ 	slti	$at,$v1,0x10
.L0f16aafc:
/*  f16aafc:	54200004 */ 	bnezl	$at,.L0f16ab10
/*  f16ab00:	ae600468 */ 	sw	$zero,0x468($s3)
/*  f16ab04:	10000002 */ 	b	.L0f16ab10
/*  f16ab08:	ae7e0468 */ 	sw	$s8,0x468($s3)
/*  f16ab0c:	ae600468 */ 	sw	$zero,0x468($s3)
.L0f16ab10:
/*  f16ab10:	52a00009 */ 	beqzl	$s5,.L0f16ab38
/*  f16ab14:	8e6c02ac */ 	lw	$t4,0x2ac($s3)
/*  f16ab18:	0fc522db */ 	jal	func0f148b6c
/*  f16ab1c:	00000000 */ 	nop
/*  f16ab20:	02402025 */ 	or	$a0,$s2,$zero
/*  f16ab24:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f16ab28:	0fc5090e */ 	jal	func0f142438
/*  f16ab2c:	02a03025 */ 	or	$a2,$s5,$zero
/*  f16ab30:	00409025 */ 	or	$s2,$v0,$zero
/*  f16ab34:	8e6c02ac */ 	lw	$t4,0x2ac($s3)
.L0f16ab38:
/*  f16ab38:	24010006 */ 	addiu	$at,$zero,0x6
/*  f16ab3c:	15810031 */ 	bne	$t4,$at,.L0f16ac04
/*  f16ab40:	00000000 */ 	nop
/*  f16ab44:	0fc2ea0e */ 	jal	getVar8009de1c
/*  f16ab48:	00000000 */ 	nop
/*  f16ab4c:	44803000 */ 	mtc1	$zero,$f6
/*  f16ab50:	3c01437f */ 	lui	$at,0x437f
/*  f16ab54:	4600303c */ 	c.lt.s	$f6,$f0
/*  f16ab58:	00000000 */ 	nop
/*  f16ab5c:	45000029 */ 	bc1f	.L0f16ac04
/*  f16ab60:	00000000 */ 	nop
/*  f16ab64:	44812000 */ 	mtc1	$at,$f4
/*  f16ab68:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f16ab6c:	3c014f00 */ 	lui	$at,0x4f00
/*  f16ab70:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f16ab74:	02402025 */ 	or	$a0,$s2,$zero
/*  f16ab78:	2405ff00 */ 	addiu	$a1,$zero,-256
/*  f16ab7c:	444bf800 */ 	cfc1	$t3,$31
/*  f16ab80:	44c6f800 */ 	ctc1	$a2,$31
/*  f16ab84:	00000000 */ 	nop
/*  f16ab88:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f16ab8c:	4446f800 */ 	cfc1	$a2,$31
/*  f16ab90:	00000000 */ 	nop
/*  f16ab94:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f16ab98:	50c00013 */ 	beqzl	$a2,.L0f16abe8
/*  f16ab9c:	44065000 */ 	mfc1	$a2,$f10
/*  f16aba0:	44815000 */ 	mtc1	$at,$f10
/*  f16aba4:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f16aba8:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f16abac:	44c6f800 */ 	ctc1	$a2,$31
/*  f16abb0:	00000000 */ 	nop
/*  f16abb4:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f16abb8:	4446f800 */ 	cfc1	$a2,$31
/*  f16abbc:	00000000 */ 	nop
/*  f16abc0:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f16abc4:	14c00005 */ 	bnez	$a2,.L0f16abdc
/*  f16abc8:	00000000 */ 	nop
/*  f16abcc:	44065000 */ 	mfc1	$a2,$f10
/*  f16abd0:	3c018000 */ 	lui	$at,0x8000
/*  f16abd4:	10000007 */ 	b	.L0f16abf4
/*  f16abd8:	00c13025 */ 	or	$a2,$a2,$at
.L0f16abdc:
/*  f16abdc:	10000005 */ 	b	.L0f16abf4
/*  f16abe0:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f16abe4:	44065000 */ 	mfc1	$a2,$f10
.L0f16abe8:
/*  f16abe8:	00000000 */ 	nop
/*  f16abec:	04c0fffb */ 	bltz	$a2,.L0f16abdc
/*  f16abf0:	00000000 */ 	nop
.L0f16abf4:
/*  f16abf4:	44cbf800 */ 	ctc1	$t3,$31
/*  f16abf8:	0fc5090e */ 	jal	func0f142438
/*  f16abfc:	00000000 */ 	nop
/*  f16ac00:	00409025 */ 	or	$s2,$v0,$zero
.L0f16ac04:
/*  f16ac04:	0fc47bb6 */ 	jal	debug0f11eed8
/*  f16ac08:	00000000 */ 	nop
/*  f16ac0c:	145e0006 */ 	bne	$v0,$s8,.L0f16ac28
/*  f16ac10:	02402025 */ 	or	$a0,$s2,$zero
/*  f16ac14:	2405ff00 */ 	addiu	$a1,$zero,-256
/*  f16ac18:	0fc5090e */ 	jal	func0f142438
/*  f16ac1c:	24060080 */ 	addiu	$a2,$zero,0x80
/*  f16ac20:	10000014 */ 	b	.L0f16ac74
/*  f16ac24:	00409025 */ 	or	$s2,$v0,$zero
.L0f16ac28:
/*  f16ac28:	0fc47bb6 */ 	jal	debug0f11eed8
/*  f16ac2c:	00000000 */ 	nop
/*  f16ac30:	24010002 */ 	addiu	$at,$zero,0x2
/*  f16ac34:	14410006 */ 	bne	$v0,$at,.L0f16ac50
/*  f16ac38:	02402025 */ 	or	$a0,$s2,$zero
/*  f16ac3c:	2405ff00 */ 	addiu	$a1,$zero,-256
/*  f16ac40:	0fc5090e */ 	jal	func0f142438
/*  f16ac44:	240600c0 */ 	addiu	$a2,$zero,0xc0
/*  f16ac48:	1000000a */ 	b	.L0f16ac74
/*  f16ac4c:	00409025 */ 	or	$s2,$v0,$zero
.L0f16ac50:
/*  f16ac50:	0fc47bb6 */ 	jal	debug0f11eed8
/*  f16ac54:	00000000 */ 	nop
/*  f16ac58:	24010003 */ 	addiu	$at,$zero,0x3
/*  f16ac5c:	14410005 */ 	bne	$v0,$at,.L0f16ac74
/*  f16ac60:	02402025 */ 	or	$a0,$s2,$zero
/*  f16ac64:	2405ff00 */ 	addiu	$a1,$zero,-256
/*  f16ac68:	0fc5090e */ 	jal	func0f142438
/*  f16ac6c:	240600e6 */ 	addiu	$a2,$zero,0xe6
/*  f16ac70:	00409025 */ 	or	$s2,$v0,$zero
.L0f16ac74:
/*  f16ac74:	8e700284 */ 	lw	$s0,0x284($s3)
/*  f16ac78:	24010003 */ 	addiu	$at,$zero,0x3
/*  f16ac7c:	92031bfc */ 	lbu	$v1,0x1bfc($s0)
/*  f16ac80:	1860003b */ 	blez	$v1,.L0f16ad70
/*  f16ac84:	00000000 */ 	nop
/*  f16ac88:	14610002 */ 	bne	$v1,$at,.L0f16ac94
/*  f16ac8c:	00008825 */ 	or	$s1,$zero,$zero
/*  f16ac90:	241100ff */ 	addiu	$s1,$zero,0xff
.L0f16ac94:
/*  f16ac94:	56830009 */ 	bnel	$s4,$v1,.L0f16acbc
/*  f16ac98:	24010002 */ 	addiu	$at,$zero,0x2
/*  f16ac9c:	92021bfd */ 	lbu	$v0,0x1bfd($s0)
/*  f16aca0:	28410010 */ 	slti	$at,$v0,0x10
/*  f16aca4:	50200005 */ 	beqzl	$at,.L0f16acbc
/*  f16aca8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f16acac:	00028823 */ 	negu	$s1,$v0
/*  f16acb0:	0011c900 */ 	sll	$t9,$s1,0x4
/*  f16acb4:	273100f0 */ 	addiu	$s1,$t9,0xf0
/*  f16acb8:	24010002 */ 	addiu	$at,$zero,0x2
.L0f16acbc:
/*  f16acbc:	1461000b */ 	bne	$v1,$at,.L0f16acec
/*  f16acc0:	00000000 */ 	nop
/*  f16acc4:	92021bfd */ 	lbu	$v0,0x1bfd($s0)
/*  f16acc8:	28410021 */ 	slti	$at,$v0,0x21
/*  f16accc:	54200004 */ 	bnezl	$at,.L0f16ace0
/*  f16acd0:	24010030 */ 	addiu	$at,$zero,0x30
/*  f16acd4:	00028900 */ 	sll	$s1,$v0,0x4
/*  f16acd8:	2631fe00 */ 	addiu	$s1,$s1,-512
/*  f16acdc:	24010030 */ 	addiu	$at,$zero,0x30
.L0f16ace0:
/*  f16ace0:	14410002 */ 	bne	$v0,$at,.L0f16acec
/*  f16ace4:	00000000 */ 	nop
/*  f16ace8:	241100ff */ 	addiu	$s1,$zero,0xff
.L0f16acec:
/*  f16acec:	12200020 */ 	beqz	$s1,.L0f16ad70
/*  f16acf0:	00000000 */ 	nop
/*  f16acf4:	0fc54d8a */ 	jal	func0f153628
/*  f16acf8:	02402025 */ 	or	$a0,$s2,$zero
/*  f16acfc:	0c002f40 */ 	jal	viGetViewLeft
/*  f16ad00:	00409025 */ 	or	$s2,$v0,$zero
/*  f16ad04:	0c002f44 */ 	jal	viGetViewTop
/*  f16ad08:	a7a2006e */ 	sh	$v0,0x6e($sp)
/*  f16ad0c:	0c002f40 */ 	jal	viGetViewLeft
/*  f16ad10:	a7a20070 */ 	sh	$v0,0x70($sp)
/*  f16ad14:	0c002f22 */ 	jal	viGetViewX
/*  f16ad18:	a7a20072 */ 	sh	$v0,0x72($sp)
/*  f16ad1c:	0c002f44 */ 	jal	viGetViewTop
/*  f16ad20:	a7a2008a */ 	sh	$v0,0x8a($sp)
/*  f16ad24:	00028400 */ 	sll	$s0,$v0,0x10
/*  f16ad28:	00105403 */ 	sra	$t2,$s0,0x10
/*  f16ad2c:	0c002f26 */ 	jal	viGetViewY
/*  f16ad30:	01408025 */ 	or	$s0,$t2,$zero
/*  f16ad34:	87ae008a */ 	lh	$t6,0x8a($sp)
/*  f16ad38:	87b80072 */ 	lh	$t8,0x72($sp)
/*  f16ad3c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f16ad40:	02217825 */ 	or	$t7,$s1,$at
/*  f16ad44:	00506821 */ 	addu	$t5,$v0,$s0
/*  f16ad48:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f16ad4c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f16ad50:	02402025 */ 	or	$a0,$s2,$zero
/*  f16ad54:	87a5006e */ 	lh	$a1,0x6e($sp)
/*  f16ad58:	87a60070 */ 	lh	$a2,0x70($sp)
/*  f16ad5c:	0fc54e8d */ 	jal	func0f153a34
/*  f16ad60:	01d83821 */ 	addu	$a3,$t6,$t8
/*  f16ad64:	0fc54de0 */ 	jal	func0f153780
/*  f16ad68:	00402025 */ 	or	$a0,$v0,$zero
/*  f16ad6c:	00409025 */ 	or	$s2,$v0,$zero
.L0f16ad70:
/*  f16ad70:	0fc615dd */ 	jal	func0f185774
/*  f16ad74:	02402025 */ 	or	$a0,$s2,$zero
/*  f16ad78:	0fc5a176 */ 	jal	fadeRender
/*  f16ad7c:	00402025 */ 	or	$a0,$v0,$zero
/*  f16ad80:	3c0c8009 */ 	lui	$t4,%hi(g_FrIsValidWeapon)
/*  f16ad84:	918c8804 */ 	lbu	$t4,%lo(g_FrIsValidWeapon)($t4)
/*  f16ad88:	00409025 */ 	or	$s2,$v0,$zero
/*  f16ad8c:	11800004 */ 	beqz	$t4,.L0f16ada0
/*  f16ad90:	00000000 */ 	nop
/*  f16ad94:	0fc68bd8 */ 	jal	frRenderHud
/*  f16ad98:	00402025 */ 	or	$a0,$v0,$zero
/*  f16ad9c:	00409025 */ 	or	$s2,$v0,$zero
.L0f16ada0:
/*  f16ada0:	0fc47ba2 */ 	jal	debug0f11ee88
/*  f16ada4:	00000000 */ 	nop
/*  f16ada8:	14400013 */ 	bnez	$v0,.L0f16adf8
/*  f16adac:	00000000 */ 	nop
/*  f16adb0:	0fc47ba4 */ 	jal	debug0f11ee90
/*  f16adb4:	00000000 */ 	nop
/*  f16adb8:	1440000f */ 	bnez	$v0,.L0f16adf8
/*  f16adbc:	00000000 */ 	nop
/*  f16adc0:	0fc47baa */ 	jal	debug0f11eea8
/*  f16adc4:	00000000 */ 	nop
/*  f16adc8:	1440000b */ 	bnez	$v0,.L0f16adf8
/*  f16adcc:	00000000 */ 	nop
/*  f16add0:	0fc47be0 */ 	jal	debug0f11ef80
/*  f16add4:	00000000 */ 	nop
/*  f16add8:	14400007 */ 	bnez	$v0,.L0f16adf8
/*  f16addc:	00000000 */ 	nop
/*  f16ade0:	0fc47bde */ 	jal	debug0f11ef78
/*  f16ade4:	00000000 */ 	nop
/*  f16ade8:	14400003 */ 	bnez	$v0,.L0f16adf8
/*  f16adec:	00000000 */ 	nop
/*  f16adf0:	0fc47b90 */ 	jal	debug0f11ee40
/*  f16adf4:	00000000 */ 	nop
.L0f16adf8:
/*  f16adf8:	0fc49d36 */ 	jal	func0f1274d8
/*  f16adfc:	02402025 */ 	or	$a0,$s2,$zero
/*  f16ae00:	0fc402b4 */ 	jal	func0f100ad0
/*  f16ae04:	00402025 */ 	or	$a0,$v0,$zero
/*  f16ae08:	3c013f80 */ 	lui	$at,0x3f80
/*  f16ae0c:	44816000 */ 	mtc1	$at,$f12
/*  f16ae10:	0c0059d2 */ 	jal	func00016748
/*  f16ae14:	00409025 */ 	or	$s2,$v0,$zero
/*  f16ae18:	8e6b0284 */ 	lw	$t3,0x284($s3)
/*  f16ae1c:	8d791c50 */ 	lw	$t9,0x1c50($t3)
/*  f16ae20:	001957c2 */ 	srl	$t2,$t9,0x1f
/*  f16ae24:	51400005 */ 	beqzl	$t2,.L0f16ae3c
/*  f16ae28:	8e6e0288 */ 	lw	$t6,0x288($s3)
/*  f16ae2c:	0fc3ef0c */ 	jal	func0f0fbc30
/*  f16ae30:	02402025 */ 	or	$a0,$s2,$zero
/*  f16ae34:	00409025 */ 	or	$s2,$v0,$zero
/*  f16ae38:	8e6e0288 */ 	lw	$t6,0x288($s3)
.L0f16ae3c:
/*  f16ae3c:	0c0059d2 */ 	jal	func00016748
/*  f16ae40:	c5cc0074 */ 	lwc1	$f12,0x74($t6)
/*  f16ae44:	8e780314 */ 	lw	$t8,0x314($s3)
/*  f16ae48:	53000005 */ 	beqzl	$t8,.L0f16ae60
/*  f16ae4c:	8e6d0284 */ 	lw	$t5,0x284($s3)
/*  f16ae50:	0fc625cf */ 	jal	func0f18973c
/*  f16ae54:	02402025 */ 	or	$a0,$s2,$zero
/*  f16ae58:	00409025 */ 	or	$s2,$v0,$zero
/*  f16ae5c:	8e6d0284 */ 	lw	$t5,0x284($s3)
.L0f16ae60:
/*  f16ae60:	91af19b3 */ 	lbu	$t7,0x19b3($t5)
/*  f16ae64:	11e00003 */ 	beqz	$t7,.L0f16ae74
/*  f16ae68:	00000000 */ 	nop
/*  f16ae6c:	0fc2dcb7 */ 	jal	func0f0b72dc
/*  f16ae70:	00000000 */ 	nop
.L0f16ae74:
/*  f16ae74:	0fc4f153 */ 	jal	func0f13c54c
/*  f16ae78:	00000000 */ 	nop
/*  f16ae7c:	8e6c0298 */ 	lw	$t4,0x298($s3)
/*  f16ae80:	05810004 */ 	bgez	$t4,.L0f16ae94
/*  f16ae84:	00000000 */ 	nop
/*  f16ae88:	8e6b029c */ 	lw	$t3,0x29c($s3)
/*  f16ae8c:	0562000a */ 	bltzl	$t3,.L0f16aeb8
/*  f16ae90:	8fb00060 */ 	lw	$s0,0x60($sp)
.L0f16ae94:
/*  f16ae94:	0fc2f130 */ 	jal	func0f0bc4c0
/*  f16ae98:	00000000 */ 	nop
/*  f16ae9c:	50400006 */ 	beqzl	$v0,.L0f16aeb8
/*  f16aea0:	8fb00060 */ 	lw	$s0,0x60($sp)
/*  f16aea4:	8e79028c */ 	lw	$t9,0x28c($s3)
/*  f16aea8:	53200003 */ 	beqzl	$t9,.L0f16aeb8
/*  f16aeac:	8fb00060 */ 	lw	$s0,0x60($sp)
/*  f16aeb0:	8fb20128 */ 	lw	$s2,0x128($sp)
/*  f16aeb4:	8fb00060 */ 	lw	$s0,0x60($sp)
.L0f16aeb8:
/*  f16aeb8:	8faa012c */ 	lw	$t2,0x12c($sp)
/*  f16aebc:	560afac6 */ 	bnel	$s0,$t2,.L0f1699d8
/*  f16aec0:	8faa0124 */ 	lw	$t2,0x124($sp)
.L0f16aec4:
/*  f16aec4:	826e04d3 */ 	lb	$t6,0x4d3($s3)
.L0f16aec8:
/*  f16aec8:	3c014080 */ 	lui	$at,0x4080
/*  f16aecc:	4481a000 */ 	mtc1	$at,$f20
/*  f16aed0:	11c00013 */ 	beqz	$t6,.L0f16af20
/*  f16aed4:	2417ffff */ 	addiu	$s7,$zero,-1
/*  f16aed8:	827804d6 */ 	lb	$t8,0x4d6($s3)
/*  f16aedc:	53000011 */ 	beqzl	$t8,.L0f16af24
/*  f16aee0:	826b04d3 */ 	lb	$t3,0x4d3($s3)
/*  f16aee4:	826d04d7 */ 	lb	$t5,0x4d7($s3)
/*  f16aee8:	a26004d3 */ 	sb	$zero,0x4d3($s3)
/*  f16aeec:	a26004d6 */ 	sb	$zero,0x4d6($s3)
/*  f16aef0:	51a00004 */ 	beqzl	$t5,.L0f16af04
/*  f16aef4:	826f04d4 */ 	lb	$t7,0x4d4($s3)
/*  f16aef8:	a27704d4 */ 	sb	$s7,0x4d4($s3)
/*  f16aefc:	a26004d5 */ 	sb	$zero,0x4d5($s3)
/*  f16af00:	826f04d4 */ 	lb	$t7,0x4d4($s3)
.L0f16af04:
/*  f16af04:	05e30007 */ 	bgezl	$t7,.L0f16af24
/*  f16af08:	826b04d3 */ 	lb	$t3,0x4d3($s3)
/*  f16af0c:	826c04d5 */ 	lb	$t4,0x4d5($s3)
/*  f16af10:	5d800004 */ 	bgtzl	$t4,.L0f16af24
/*  f16af14:	826b04d3 */ 	lb	$t3,0x4d3($s3)
/*  f16af18:	0c003a57 */ 	jal	mainSetStageNum
/*  f16af1c:	2404005a */ 	addiu	$a0,$zero,0x5a
.L0f16af20:
/*  f16af20:	826b04d3 */ 	lb	$t3,0x4d3($s3)
.L0f16af24:
/*  f16af24:	55600042 */ 	bnezl	$t3,.L0f16b030
/*  f16af28:	02408025 */ 	or	$s0,$s2,$zero
/*  f16af2c:	827904d4 */ 	lb	$t9,0x4d4($s3)
/*  f16af30:	0722003f */ 	bltzl	$t9,.L0f16b030
/*  f16af34:	02408025 */ 	or	$s0,$s2,$zero
/*  f16af38:	826a04d5 */ 	lb	$t2,0x4d5($s3)
/*  f16af3c:	5940003c */ 	blezl	$t2,.L0f16b030
/*  f16af40:	02408025 */ 	or	$s0,$s2,$zero
/*  f16af44:	0fc37798 */ 	jal	hudmsgRemoveAll
/*  f16af48:	00000000 */ 	nop
/*  f16af4c:	826e04d4 */ 	lb	$t6,0x4d4($s3)
/*  f16af50:	2414000c */ 	addiu	$s4,$zero,0xc
/*  f16af54:	3c118007 */ 	lui	$s1,%hi(g_Cutscenes)
/*  f16af58:	01d40019 */ 	multu	$t6,$s4
/*  f16af5c:	263136d8 */ 	addiu	$s1,$s1,%lo(g_Cutscenes)
/*  f16af60:	3c10800a */ 	lui	$s0,%hi(g_MissionConfig)
/*  f16af64:	2610dfe8 */ 	addiu	$s0,$s0,%lo(g_MissionConfig)
/*  f16af68:	920c0003 */ 	lbu	$t4,0x3($s0)
/*  f16af6c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f16af70:	3199ff7f */ 	andi	$t9,$t4,0xff7f
/*  f16af74:	332a00bf */ 	andi	$t2,$t9,0xbf
/*  f16af78:	0000c012 */ 	mflo	$t8
/*  f16af7c:	02386821 */ 	addu	$t5,$s1,$t8
/*  f16af80:	8daf0004 */ 	lw	$t7,0x4($t5)
/*  f16af84:	a2190003 */ 	sb	$t9,0x3($s0)
/*  f16af88:	ae600314 */ 	sw	$zero,0x314($s3)
/*  f16af8c:	ae600318 */ 	sw	$zero,0x318($s3)
/*  f16af90:	ae600294 */ 	sw	$zero,0x294($s3)
/*  f16af94:	ae770298 */ 	sw	$s7,0x298($s3)
/*  f16af98:	ae77029c */ 	sw	$s7,0x29c($s3)
/*  f16af9c:	a20a0003 */ 	sb	$t2,0x3($s0)
/*  f16afa0:	0fc068d5 */ 	jal	setNumPlayers
/*  f16afa4:	a26f04d2 */ 	sb	$t7,0x4d2($s3)
/*  f16afa8:	0fc069f9 */ 	jal	titleSetNextMode
/*  f16afac:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f16afb0:	920e0000 */ 	lbu	$t6,0x0($s0)
/*  f16afb4:	00002025 */ 	or	$a0,$zero,$zero
/*  f16afb8:	31d8ff01 */ 	andi	$t8,$t6,0xff01
/*  f16afbc:	0fc5b36a */ 	jal	setDifficulty
/*  f16afc0:	a2180000 */ 	sb	$t8,0x0($s0)
/*  f16afc4:	826d04d4 */ 	lb	$t5,0x4d4($s3)
/*  f16afc8:	01b40019 */ 	multu	$t5,$s4
/*  f16afcc:	00007812 */ 	mflo	$t7
/*  f16afd0:	022f1021 */ 	addu	$v0,$s1,$t7
/*  f16afd4:	844c0002 */ 	lh	$t4,0x2($v0)
/*  f16afd8:	84440000 */ 	lh	$a0,0x0($v0)
/*  f16afdc:	a20c0002 */ 	sb	$t4,0x2($s0)
/*  f16afe0:	0fc06c55 */ 	jal	titleSetNextStage
/*  f16afe4:	a2040001 */ 	sb	$a0,0x1($s0)
/*  f16afe8:	826b04d4 */ 	lb	$t3,0x4d4($s3)
/*  f16afec:	01740019 */ 	multu	$t3,$s4
/*  f16aff0:	0000c812 */ 	mflo	$t9
/*  f16aff4:	02395021 */ 	addu	$t2,$s1,$t9
/*  f16aff8:	0c003a57 */ 	jal	mainSetStageNum
/*  f16affc:	85440000 */ 	lh	$a0,0x0($t2)
/*  f16b000:	826e04d5 */ 	lb	$t6,0x4d5($s3)
/*  f16b004:	25d8ffff */ 	addiu	$t8,$t6,-1
/*  f16b008:	a27804d5 */ 	sb	$t8,0x4d5($s3)
/*  f16b00c:	826d04d5 */ 	lb	$t5,0x4d5($s3)
/*  f16b010:	59a00006 */ 	blezl	$t5,.L0f16b02c
/*  f16b014:	a27704d4 */ 	sb	$s7,0x4d4($s3)
/*  f16b018:	826f04d4 */ 	lb	$t7,0x4d4($s3)
/*  f16b01c:	25ec0001 */ 	addiu	$t4,$t7,0x1
/*  f16b020:	10000002 */ 	b	.L0f16b02c
/*  f16b024:	a26c04d4 */ 	sb	$t4,0x4d4($s3)
/*  f16b028:	a27704d4 */ 	sb	$s7,0x4d4($s3)
.L0f16b02c:
/*  f16b02c:	02408025 */ 	or	$s0,$s2,$zero
.L0f16b030:
/*  f16b030:	3c0bed00 */ 	lui	$t3,0xed00
/*  f16b034:	ae0b0000 */ 	sw	$t3,0x0($s0)
/*  f16b038:	0c002f02 */ 	jal	viGetX
/*  f16b03c:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f16b040:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f16b044:	0011cc03 */ 	sra	$t9,$s1,0x10
/*  f16b048:	0c002f06 */ 	jal	viGetY
/*  f16b04c:	03208825 */ 	or	$s1,$t9,$zero
/*  f16b050:	44829000 */ 	mtc1	$v0,$f18
/*  f16b054:	44914000 */ 	mtc1	$s1,$f8
/*  f16b058:	02401025 */ 	or	$v0,$s2,$zero
/*  f16b05c:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f16b060:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f16b064:	46148182 */ 	mul.s	$f6,$f16,$f20
/*  f16b068:	00000000 */ 	nop
/*  f16b06c:	46145482 */ 	mul.s	$f18,$f10,$f20
/*  f16b070:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f16b074:	4600940d */ 	trunc.w.s	$f16,$f18
/*  f16b078:	440e2000 */ 	mfc1	$t6,$f4
/*  f16b07c:	440f8000 */ 	mfc1	$t7,$f16
/*  f16b080:	31d80fff */ 	andi	$t8,$t6,0xfff
/*  f16b084:	31ec0fff */ 	andi	$t4,$t7,0xfff
/*  f16b088:	000c5b00 */ 	sll	$t3,$t4,0xc
/*  f16b08c:	030bc825 */ 	or	$t9,$t8,$t3
/*  f16b090:	ae190004 */ 	sw	$t9,0x4($s0)
/*  f16b094:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f16b098:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f16b09c:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f16b0a0:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f16b0a4:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f16b0a8:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f16b0ac:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f16b0b0:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f16b0b4:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f16b0b8:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f16b0bc:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f16b0c0:	03e00008 */ 	jr	$ra
/*  f16b0c4:	27bd0190 */ 	addiu	$sp,$sp,0x190
);

GLOBAL_ASM(
glabel func0f16b0c8
.late_rodata
glabel var7f1b786c
.word 0x3eb33333
glabel var7f1b7870
.word 0x3e4ccccd
glabel var7f1b7874
.word 0x3f19999a
glabel var7f1b7878
.word 0x3f8ccccd
glabel var7f1b787c
.word 0x3f333333
glabel var7f1b7880
.word 0x3f266666
glabel var7f1b7884
.word 0x3f19999a
glabel var7f1b7888
.word 0x3e4ccccd
glabel var7f1b788c
.word 0x3f8ccccd
glabel var7f1b7890
.word 0x3e4ccccd
glabel var7f1b7894
.word 0x3f19999a
glabel var7f1b7898
.word 0x3ef33334
glabel var7f1b789c
.word 0x3f19999a
glabel var7f1b78a0
.word 0x3e4ccccd
glabel var7f1b78a4
.word 0x3f4ccccd
glabel var7f1b78a8
.word 0x3f19999a
glabel var7f1b78ac
.word 0x3f8ccccd
glabel var7f1b78b0
.word 0x3f966666
glabel var7f1b78b4
.word 0x3e4ccccd
glabel var7f1b78b8
.word 0x3f8ccccd
.text
/*  f16b0c8:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f16b0cc:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f16b0d0:	8c43029c */ 	lw	$v1,0x29c($v0)
/*  f16b0d4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f16b0d8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16b0dc:	04620081 */ 	bltzl	$v1,.L0f16b2e4
/*  f16b0e0:	8c440298 */ 	lw	$a0,0x298($v0)
/*  f16b0e4:	3c028008 */ 	lui	$v0,%hi(g_Difficulty)
/*  f16b0e8:	8c424020 */ 	lw	$v0,%lo(g_Difficulty)($v0)
/*  f16b0ec:	24010001 */ 	addiu	$at,$zero,0x1
/*  f16b0f0:	1440002a */ 	bnez	$v0,.L0f16b19c
/*  f16b0f4:	00000000 */ 	nop
/*  f16b0f8:	3c014000 */ 	lui	$at,0x4000
/*  f16b0fc:	44811000 */ 	mtc1	$at,$f2
/*  f16b100:	3c013f00 */ 	lui	$at,0x3f00
/*  f16b104:	44816000 */ 	mtc1	$at,$f12
/*  f16b108:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f16b10c:	44818000 */ 	mtc1	$at,$f16
/*  f16b110:	3c018007 */ 	lui	$at,%hi(var80069948)
/*  f16b114:	e4229948 */ 	swc1	$f2,%lo(var80069948)($at)
/*  f16b118:	3c018007 */ 	lui	$at,%hi(var8006994c)
/*  f16b11c:	e422994c */ 	swc1	$f2,%lo(var8006994c)($at)
/*  f16b120:	3c018007 */ 	lui	$at,%hi(var80069950)
/*  f16b124:	e42c9950 */ 	swc1	$f12,%lo(var80069950)($at)
/*  f16b128:	3c018007 */ 	lui	$at,%hi(var80069954)
/*  f16b12c:	e42c9954 */ 	swc1	$f12,%lo(var80069954)($at)
/*  f16b130:	3c018007 */ 	lui	$at,%hi(var80069958)
/*  f16b134:	e4229958 */ 	swc1	$f2,%lo(var80069958)($at)
/*  f16b138:	3c018006 */ 	lui	$at,%hi(var80062ca0)
/*  f16b13c:	e42c2ca0 */ 	swc1	$f12,%lo(var80062ca0)($at)
/*  f16b140:	3c017f1b */ 	lui	$at,%hi(var7f1b786c)
/*  f16b144:	c424786c */ 	lwc1	$f4,%lo(var7f1b786c)($at)
/*  f16b148:	3c018006 */ 	lui	$at,%hi(var80062ca4)
/*  f16b14c:	e4242ca4 */ 	swc1	$f4,%lo(var80062ca4)($at)
/*  f16b150:	3c014080 */ 	lui	$at,0x4080
/*  f16b154:	44813000 */ 	mtc1	$at,$f6
/*  f16b158:	3c018006 */ 	lui	$at,%hi(var80062ca8)
/*  f16b15c:	e4262ca8 */ 	swc1	$f6,%lo(var80062ca8)($at)
/*  f16b160:	3c013e80 */ 	lui	$at,0x3e80
/*  f16b164:	44814000 */ 	mtc1	$at,$f8
/*  f16b168:	3c018008 */ 	lui	$at,%hi(var8007e4a8)
/*  f16b16c:	e428e4a8 */ 	swc1	$f8,%lo(var8007e4a8)($at)
/*  f16b170:	3c018007 */ 	lui	$at,%hi(var80069880)
/*  f16b174:	e4309880 */ 	swc1	$f16,%lo(var80069880)($at)
/*  f16b178:	3c014040 */ 	lui	$at,0x4040
/*  f16b17c:	44815000 */ 	mtc1	$at,$f10
/*  f16b180:	3c018007 */ 	lui	$at,%hi(g_AmmoMultiplier)
/*  f16b184:	e42a995c */ 	swc1	$f10,%lo(g_AmmoMultiplier)($at)
/*  f16b188:	3c017f1b */ 	lui	$at,%hi(var7f1b7870)
/*  f16b18c:	c4327870 */ 	lwc1	$f18,%lo(var7f1b7870)($at)
/*  f16b190:	3c018006 */ 	lui	$at,%hi(var80062cac)
/*  f16b194:	10000196 */ 	b	.L0f16b7f0
/*  f16b198:	e4322cac */ 	swc1	$f18,%lo(var80062cac)($at)
.L0f16b19c:
/*  f16b19c:	14410029 */ 	bne	$v0,$at,.L0f16b244
/*  f16b1a0:	3c014000 */ 	lui	$at,0x4000
/*  f16b1a4:	44811000 */ 	mtc1	$at,$f2
/*  f16b1a8:	3c013f00 */ 	lui	$at,0x3f00
/*  f16b1ac:	44816000 */ 	mtc1	$at,$f12
/*  f16b1b0:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f16b1b4:	44818000 */ 	mtc1	$at,$f16
/*  f16b1b8:	3c018007 */ 	lui	$at,%hi(var80069948)
/*  f16b1bc:	e4229948 */ 	swc1	$f2,%lo(var80069948)($at)
/*  f16b1c0:	3c018007 */ 	lui	$at,%hi(var8006994c)
/*  f16b1c4:	e430994c */ 	swc1	$f16,%lo(var8006994c)($at)
/*  f16b1c8:	3c018007 */ 	lui	$at,%hi(var80069950)
/*  f16b1cc:	e42c9950 */ 	swc1	$f12,%lo(var80069950)($at)
/*  f16b1d0:	3c018007 */ 	lui	$at,%hi(var80069954)
/*  f16b1d4:	e42c9954 */ 	swc1	$f12,%lo(var80069954)($at)
/*  f16b1d8:	3c018007 */ 	lui	$at,%hi(var80069958)
/*  f16b1dc:	e4309958 */ 	swc1	$f16,%lo(var80069958)($at)
/*  f16b1e0:	3c017f1b */ 	lui	$at,%hi(var7f1b7874)
/*  f16b1e4:	c4247874 */ 	lwc1	$f4,%lo(var7f1b7874)($at)
/*  f16b1e8:	3c018006 */ 	lui	$at,%hi(var80062ca0)
/*  f16b1ec:	e4242ca0 */ 	swc1	$f4,%lo(var80062ca0)($at)
/*  f16b1f0:	3c018006 */ 	lui	$at,%hi(var80062ca4)
/*  f16b1f4:	e42c2ca4 */ 	swc1	$f12,%lo(var80062ca4)($at)
/*  f16b1f8:	3c014040 */ 	lui	$at,0x4040
/*  f16b1fc:	44813000 */ 	mtc1	$at,$f6
/*  f16b200:	3c018006 */ 	lui	$at,%hi(var80062ca8)
/*  f16b204:	e4262ca8 */ 	swc1	$f6,%lo(var80062ca8)($at)
/*  f16b208:	3c013e80 */ 	lui	$at,0x3e80
/*  f16b20c:	44814000 */ 	mtc1	$at,$f8
/*  f16b210:	3c018008 */ 	lui	$at,%hi(var8007e4a8)
/*  f16b214:	e428e4a8 */ 	swc1	$f8,%lo(var8007e4a8)($at)
/*  f16b218:	3c017f1b */ 	lui	$at,%hi(var7f1b7878)
/*  f16b21c:	c42a7878 */ 	lwc1	$f10,%lo(var7f1b7878)($at)
/*  f16b220:	3c018007 */ 	lui	$at,%hi(var80069880)
/*  f16b224:	e42a9880 */ 	swc1	$f10,%lo(var80069880)($at)
/*  f16b228:	3c014020 */ 	lui	$at,0x4020
/*  f16b22c:	44819000 */ 	mtc1	$at,$f18
/*  f16b230:	3c018007 */ 	lui	$at,%hi(g_AmmoMultiplier)
/*  f16b234:	e432995c */ 	swc1	$f18,%lo(g_AmmoMultiplier)($at)
/*  f16b238:	3c018006 */ 	lui	$at,%hi(var80062cac)
/*  f16b23c:	1000016c */ 	b	.L0f16b7f0
/*  f16b240:	e42c2cac */ 	swc1	$f12,%lo(var80062cac)($at)
.L0f16b244:
/*  f16b244:	3c013f80 */ 	lui	$at,0x3f80
/*  f16b248:	44810000 */ 	mtc1	$at,$f0
/*  f16b24c:	3c014000 */ 	lui	$at,0x4000
/*  f16b250:	44811000 */ 	mtc1	$at,$f2
/*  f16b254:	3c013f00 */ 	lui	$at,0x3f00
/*  f16b258:	44816000 */ 	mtc1	$at,$f12
/*  f16b25c:	3c013f40 */ 	lui	$at,0x3f40
/*  f16b260:	44817000 */ 	mtc1	$at,$f14
/*  f16b264:	3c018007 */ 	lui	$at,%hi(var80069948)
/*  f16b268:	e4229948 */ 	swc1	$f2,%lo(var80069948)($at)
/*  f16b26c:	3c018007 */ 	lui	$at,%hi(var8006994c)
/*  f16b270:	e420994c */ 	swc1	$f0,%lo(var8006994c)($at)
/*  f16b274:	3c018007 */ 	lui	$at,%hi(var80069950)
/*  f16b278:	e42c9950 */ 	swc1	$f12,%lo(var80069950)($at)
/*  f16b27c:	3c018007 */ 	lui	$at,%hi(var80069954)
/*  f16b280:	e42c9954 */ 	swc1	$f12,%lo(var80069954)($at)
/*  f16b284:	3c018007 */ 	lui	$at,%hi(var80069958)
/*  f16b288:	e4209958 */ 	swc1	$f0,%lo(var80069958)($at)
/*  f16b28c:	3c017f1b */ 	lui	$at,%hi(var7f1b787c)
/*  f16b290:	c424787c */ 	lwc1	$f4,%lo(var7f1b787c)($at)
/*  f16b294:	3c018006 */ 	lui	$at,%hi(var80062ca0)
/*  f16b298:	e4242ca0 */ 	swc1	$f4,%lo(var80062ca0)($at)
/*  f16b29c:	3c017f1b */ 	lui	$at,%hi(var7f1b7880)
/*  f16b2a0:	c4267880 */ 	lwc1	$f6,%lo(var7f1b7880)($at)
/*  f16b2a4:	3c018006 */ 	lui	$at,%hi(var80062ca4)
/*  f16b2a8:	e4262ca4 */ 	swc1	$f6,%lo(var80062ca4)($at)
/*  f16b2ac:	3c018006 */ 	lui	$at,%hi(var80062ca8)
/*  f16b2b0:	e4222ca8 */ 	swc1	$f2,%lo(var80062ca8)($at)
/*  f16b2b4:	3c013e80 */ 	lui	$at,0x3e80
/*  f16b2b8:	44814000 */ 	mtc1	$at,$f8
/*  f16b2bc:	3c018008 */ 	lui	$at,%hi(var8007e4a8)
/*  f16b2c0:	e428e4a8 */ 	swc1	$f8,%lo(var8007e4a8)($at)
/*  f16b2c4:	3c018007 */ 	lui	$at,%hi(var80069880)
/*  f16b2c8:	e42e9880 */ 	swc1	$f14,%lo(var80069880)($at)
/*  f16b2cc:	3c018007 */ 	lui	$at,%hi(g_AmmoMultiplier)
/*  f16b2d0:	e422995c */ 	swc1	$f2,%lo(g_AmmoMultiplier)($at)
/*  f16b2d4:	3c018006 */ 	lui	$at,%hi(var80062cac)
/*  f16b2d8:	10000145 */ 	b	.L0f16b7f0
/*  f16b2dc:	e4202cac */ 	swc1	$f0,%lo(var80062cac)($at)
/*  f16b2e0:	8c440298 */ 	lw	$a0,0x298($v0)
.L0f16b2e4:
/*  f16b2e4:	3c028008 */ 	lui	$v0,%hi(g_Difficulty)
/*  f16b2e8:	0480007c */ 	bltz	$a0,.L0f16b4dc
/*  f16b2ec:	00000000 */ 	nop
/*  f16b2f0:	3c028008 */ 	lui	$v0,%hi(g_Difficulty)
/*  f16b2f4:	8c424020 */ 	lw	$v0,%lo(g_Difficulty)($v0)
/*  f16b2f8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f16b2fc:	14400026 */ 	bnez	$v0,.L0f16b398
/*  f16b300:	00000000 */ 	nop
/*  f16b304:	3c014000 */ 	lui	$at,0x4000
/*  f16b308:	44811000 */ 	mtc1	$at,$f2
/*  f16b30c:	3c013f00 */ 	lui	$at,0x3f00
/*  f16b310:	44816000 */ 	mtc1	$at,$f12
/*  f16b314:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f16b318:	44818000 */ 	mtc1	$at,$f16
/*  f16b31c:	3c018007 */ 	lui	$at,%hi(var80069948)
/*  f16b320:	e4229948 */ 	swc1	$f2,%lo(var80069948)($at)
/*  f16b324:	3c018007 */ 	lui	$at,%hi(var8006994c)
/*  f16b328:	e422994c */ 	swc1	$f2,%lo(var8006994c)($at)
/*  f16b32c:	3c018007 */ 	lui	$at,%hi(var80069950)
/*  f16b330:	e42c9950 */ 	swc1	$f12,%lo(var80069950)($at)
/*  f16b334:	3c018007 */ 	lui	$at,%hi(var80069954)
/*  f16b338:	e42c9954 */ 	swc1	$f12,%lo(var80069954)($at)
/*  f16b33c:	3c018007 */ 	lui	$at,%hi(var80069958)
/*  f16b340:	e4229958 */ 	swc1	$f2,%lo(var80069958)($at)
/*  f16b344:	3c017f1b */ 	lui	$at,%hi(var7f1b7884)
/*  f16b348:	c42a7884 */ 	lwc1	$f10,%lo(var7f1b7884)($at)
/*  f16b34c:	3c018006 */ 	lui	$at,%hi(var80062ca0)
/*  f16b350:	e42a2ca0 */ 	swc1	$f10,%lo(var80062ca0)($at)
/*  f16b354:	3c018006 */ 	lui	$at,%hi(var80062ca4)
/*  f16b358:	e42c2ca4 */ 	swc1	$f12,%lo(var80062ca4)($at)
/*  f16b35c:	3c018006 */ 	lui	$at,%hi(var80062ca8)
/*  f16b360:	e4222ca8 */ 	swc1	$f2,%lo(var80062ca8)($at)
/*  f16b364:	3c013e80 */ 	lui	$at,0x3e80
/*  f16b368:	44819000 */ 	mtc1	$at,$f18
/*  f16b36c:	3c018008 */ 	lui	$at,%hi(var8007e4a8)
/*  f16b370:	e432e4a8 */ 	swc1	$f18,%lo(var8007e4a8)($at)
/*  f16b374:	3c018007 */ 	lui	$at,%hi(var80069880)
/*  f16b378:	e4309880 */ 	swc1	$f16,%lo(var80069880)($at)
/*  f16b37c:	3c018007 */ 	lui	$at,%hi(g_AmmoMultiplier)
/*  f16b380:	e422995c */ 	swc1	$f2,%lo(g_AmmoMultiplier)($at)
/*  f16b384:	3c017f1b */ 	lui	$at,%hi(var7f1b7888)
/*  f16b388:	c4247888 */ 	lwc1	$f4,%lo(var7f1b7888)($at)
/*  f16b38c:	3c018006 */ 	lui	$at,%hi(var80062cac)
/*  f16b390:	10000117 */ 	b	.L0f16b7f0
/*  f16b394:	e4242cac */ 	swc1	$f4,%lo(var80062cac)($at)
.L0f16b398:
/*  f16b398:	1441002a */ 	bne	$v0,$at,.L0f16b444
/*  f16b39c:	3c0f8008 */ 	lui	$t7,%hi(g_LanguageId)
/*  f16b3a0:	3c013f80 */ 	lui	$at,0x3f80
/*  f16b3a4:	44810000 */ 	mtc1	$at,$f0
/*  f16b3a8:	3c013f40 */ 	lui	$at,0x3f40
/*  f16b3ac:	44817000 */ 	mtc1	$at,$f14
/*  f16b3b0:	3c018007 */ 	lui	$at,%hi(var80069948)
/*  f16b3b4:	e4209948 */ 	swc1	$f0,%lo(var80069948)($at)
/*  f16b3b8:	3c018007 */ 	lui	$at,%hi(var8006994c)
/*  f16b3bc:	e420994c */ 	swc1	$f0,%lo(var8006994c)($at)
/*  f16b3c0:	3c018007 */ 	lui	$at,%hi(var80069950)
/*  f16b3c4:	e42e9950 */ 	swc1	$f14,%lo(var80069950)($at)
/*  f16b3c8:	3c018007 */ 	lui	$at,%hi(var80069954)
/*  f16b3cc:	e4209954 */ 	swc1	$f0,%lo(var80069954)($at)
/*  f16b3d0:	3c018007 */ 	lui	$at,%hi(var80069958)
/*  f16b3d4:	e4209958 */ 	swc1	$f0,%lo(var80069958)($at)
/*  f16b3d8:	3c018006 */ 	lui	$at,%hi(var80062ca0)
/*  f16b3dc:	e42e2ca0 */ 	swc1	$f14,%lo(var80062ca0)($at)
/*  f16b3e0:	3c018006 */ 	lui	$at,%hi(var80062ca4)
/*  f16b3e4:	3c0e8008 */ 	lui	$t6,%hi(g_LanguageId)
/*  f16b3e8:	e4202ca4 */ 	swc1	$f0,%lo(var80062ca4)($at)
/*  f16b3ec:	8dce4120 */ 	lw	$t6,%lo(g_LanguageId)($t6)
/*  f16b3f0:	3c018006 */ 	lui	$at,%hi(var80062ca8)
/*  f16b3f4:	e4202ca8 */ 	swc1	$f0,%lo(var80062ca8)($at)
/*  f16b3f8:	3c018008 */ 	lui	$at,%hi(var8007e4a8)
/*  f16b3fc:	11c00006 */ 	beqz	$t6,.L0f16b418
/*  f16b400:	e420e4a8 */ 	swc1	$f0,%lo(var8007e4a8)($at)
/*  f16b404:	3c017f1b */ 	lui	$at,%hi(var7f1b788c)
/*  f16b408:	c426788c */ 	lwc1	$f6,%lo(var7f1b788c)($at)
/*  f16b40c:	3c018007 */ 	lui	$at,%hi(var80069880)
/*  f16b410:	10000003 */ 	b	.L0f16b420
/*  f16b414:	e4269880 */ 	swc1	$f6,%lo(var80069880)($at)
.L0f16b418:
/*  f16b418:	3c018007 */ 	lui	$at,%hi(var80069880)
/*  f16b41c:	e42e9880 */ 	swc1	$f14,%lo(var80069880)($at)
.L0f16b420:
/*  f16b420:	3c013f00 */ 	lui	$at,0x3f00
/*  f16b424:	44816000 */ 	mtc1	$at,$f12
/*  f16b428:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f16b42c:	44818000 */ 	mtc1	$at,$f16
/*  f16b430:	3c018007 */ 	lui	$at,%hi(g_AmmoMultiplier)
/*  f16b434:	e430995c */ 	swc1	$f16,%lo(g_AmmoMultiplier)($at)
/*  f16b438:	3c018006 */ 	lui	$at,%hi(var80062cac)
/*  f16b43c:	100000ec */ 	b	.L0f16b7f0
/*  f16b440:	e42c2cac */ 	swc1	$f12,%lo(var80062cac)($at)
.L0f16b444:
/*  f16b444:	3c013f80 */ 	lui	$at,0x3f80
/*  f16b448:	44810000 */ 	mtc1	$at,$f0
/*  f16b44c:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f16b450:	44818000 */ 	mtc1	$at,$f16
/*  f16b454:	3c018007 */ 	lui	$at,%hi(var80069948)
/*  f16b458:	e4209948 */ 	swc1	$f0,%lo(var80069948)($at)
/*  f16b45c:	3c018007 */ 	lui	$at,%hi(var8006994c)
/*  f16b460:	e420994c */ 	swc1	$f0,%lo(var8006994c)($at)
/*  f16b464:	3c018007 */ 	lui	$at,%hi(var80069950)
/*  f16b468:	e4209950 */ 	swc1	$f0,%lo(var80069950)($at)
/*  f16b46c:	3c018007 */ 	lui	$at,%hi(var80069954)
/*  f16b470:	e4309954 */ 	swc1	$f16,%lo(var80069954)($at)
/*  f16b474:	3c018007 */ 	lui	$at,%hi(var80069958)
/*  f16b478:	e4209958 */ 	swc1	$f0,%lo(var80069958)($at)
/*  f16b47c:	3c018006 */ 	lui	$at,%hi(var80062ca0)
/*  f16b480:	e4302ca0 */ 	swc1	$f16,%lo(var80062ca0)($at)
/*  f16b484:	3c018006 */ 	lui	$at,%hi(var80062ca4)
/*  f16b488:	e4302ca4 */ 	swc1	$f16,%lo(var80062ca4)($at)
/*  f16b48c:	8def4120 */ 	lw	$t7,%lo(g_LanguageId)($t7)
/*  f16b490:	3c018006 */ 	lui	$at,%hi(var80062ca8)
/*  f16b494:	e4202ca8 */ 	swc1	$f0,%lo(var80062ca8)($at)
/*  f16b498:	3c018008 */ 	lui	$at,%hi(var8007e4a8)
/*  f16b49c:	11e00006 */ 	beqz	$t7,.L0f16b4b8
/*  f16b4a0:	e430e4a8 */ 	swc1	$f16,%lo(var8007e4a8)($at)
/*  f16b4a4:	3c013f40 */ 	lui	$at,0x3f40
/*  f16b4a8:	44817000 */ 	mtc1	$at,$f14
/*  f16b4ac:	3c018007 */ 	lui	$at,%hi(var80069880)
/*  f16b4b0:	10000005 */ 	b	.L0f16b4c8
/*  f16b4b4:	e42e9880 */ 	swc1	$f14,%lo(var80069880)($at)
.L0f16b4b8:
/*  f16b4b8:	3c017f1b */ 	lui	$at,%hi(var7f1b7890)
/*  f16b4bc:	c4287890 */ 	lwc1	$f8,%lo(var7f1b7890)($at)
/*  f16b4c0:	3c018007 */ 	lui	$at,%hi(var80069880)
/*  f16b4c4:	e4289880 */ 	swc1	$f8,%lo(var80069880)($at)
.L0f16b4c8:
/*  f16b4c8:	3c018007 */ 	lui	$at,%hi(g_AmmoMultiplier)
/*  f16b4cc:	e420995c */ 	swc1	$f0,%lo(g_AmmoMultiplier)($at)
/*  f16b4d0:	3c018006 */ 	lui	$at,%hi(var80062cac)
/*  f16b4d4:	100000c6 */ 	b	.L0f16b7f0
/*  f16b4d8:	e4202cac */ 	swc1	$f0,%lo(var80062cac)($at)
.L0f16b4dc:
/*  f16b4dc:	8c424020 */ 	lw	$v0,%lo(g_Difficulty)($v0)
/*  f16b4e0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f16b4e4:	1440004d */ 	bnez	$v0,.L0f16b61c
/*  f16b4e8:	00000000 */ 	nop
/*  f16b4ec:	3c013f80 */ 	lui	$at,0x3f80
/*  f16b4f0:	44817000 */ 	mtc1	$at,$f14
/*  f16b4f4:	04830023 */ 	bgezl	$a0,.L0f16b584
/*  f16b4f8:	3c014000 */ 	lui	$at,0x4000
/*  f16b4fc:	04630021 */ 	bgezl	$v1,.L0f16b584
/*  f16b500:	3c014000 */ 	lui	$at,0x4000
/*  f16b504:	0fc30865 */ 	jal	currentPlayerGetHealth
/*  f16b508:	e7ae0020 */ 	swc1	$f14,0x20($sp)
/*  f16b50c:	0fc30869 */ 	jal	func0f0c21a4
/*  f16b510:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f16b514:	c7aa001c */ 	lwc1	$f10,0x1c($sp)
/*  f16b518:	3c013e00 */ 	lui	$at,0x3e00
/*  f16b51c:	44818000 */ 	mtc1	$at,$f16
/*  f16b520:	460a0080 */ 	add.s	$f2,$f0,$f10
/*  f16b524:	c7ae0020 */ 	lwc1	$f14,0x20($sp)
/*  f16b528:	3c017f1b */ 	lui	$at,%hi(var7f1b7894)
/*  f16b52c:	4610103e */ 	c.le.s	$f2,$f16
/*  f16b530:	00000000 */ 	nop
/*  f16b534:	45000005 */ 	bc1f	.L0f16b54c
/*  f16b538:	00000000 */ 	nop
/*  f16b53c:	3c013f00 */ 	lui	$at,0x3f00
/*  f16b540:	44817000 */ 	mtc1	$at,$f14
/*  f16b544:	1000000f */ 	b	.L0f16b584
/*  f16b548:	3c014000 */ 	lui	$at,0x4000
.L0f16b54c:
/*  f16b54c:	c4327894 */ 	lwc1	$f18,%lo(var7f1b7894)($at)
/*  f16b550:	3c013f00 */ 	lui	$at,0x3f00
/*  f16b554:	4612103e */ 	c.le.s	$f2,$f18
/*  f16b558:	00000000 */ 	nop
/*  f16b55c:	45020009 */ 	bc1fl	.L0f16b584
/*  f16b560:	3c014000 */ 	lui	$at,0x4000
/*  f16b564:	46101101 */ 	sub.s	$f4,$f2,$f16
/*  f16b568:	44816000 */ 	mtc1	$at,$f12
/*  f16b56c:	3c017f1b */ 	lui	$at,%hi(var7f1b7898)
/*  f16b570:	c4287898 */ 	lwc1	$f8,%lo(var7f1b7898)($at)
/*  f16b574:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f16b578:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f16b57c:	460c5380 */ 	add.s	$f14,$f10,$f12
/*  f16b580:	3c014000 */ 	lui	$at,0x4000
.L0f16b584:
/*  f16b584:	44811000 */ 	mtc1	$at,$f2
/*  f16b588:	3c013f00 */ 	lui	$at,0x3f00
/*  f16b58c:	44816000 */ 	mtc1	$at,$f12
/*  f16b590:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f16b594:	44818000 */ 	mtc1	$at,$f16
/*  f16b598:	460e6002 */ 	mul.s	$f0,$f12,$f14
/*  f16b59c:	3c018007 */ 	lui	$at,%hi(var80069948)
/*  f16b5a0:	e4229948 */ 	swc1	$f2,%lo(var80069948)($at)
/*  f16b5a4:	3c018007 */ 	lui	$at,%hi(var8006994c)
/*  f16b5a8:	e422994c */ 	swc1	$f2,%lo(var8006994c)($at)
/*  f16b5ac:	3c018007 */ 	lui	$at,%hi(var80069950)
/*  f16b5b0:	e4209950 */ 	swc1	$f0,%lo(var80069950)($at)
/*  f16b5b4:	3c018007 */ 	lui	$at,%hi(var80069954)
/*  f16b5b8:	e4209954 */ 	swc1	$f0,%lo(var80069954)($at)
/*  f16b5bc:	3c018007 */ 	lui	$at,%hi(var80069958)
/*  f16b5c0:	e4229958 */ 	swc1	$f2,%lo(var80069958)($at)
/*  f16b5c4:	3c017f1b */ 	lui	$at,%hi(var7f1b789c)
/*  f16b5c8:	c432789c */ 	lwc1	$f18,%lo(var7f1b789c)($at)
/*  f16b5cc:	3c018006 */ 	lui	$at,%hi(var80062ca0)
/*  f16b5d0:	e4322ca0 */ 	swc1	$f18,%lo(var80062ca0)($at)
/*  f16b5d4:	3c018006 */ 	lui	$at,%hi(var80062ca4)
/*  f16b5d8:	e4202ca4 */ 	swc1	$f0,%lo(var80062ca4)($at)
/*  f16b5dc:	3c018006 */ 	lui	$at,%hi(var80062ca8)
/*  f16b5e0:	e4222ca8 */ 	swc1	$f2,%lo(var80062ca8)($at)
/*  f16b5e4:	3c013e80 */ 	lui	$at,0x3e80
/*  f16b5e8:	44812000 */ 	mtc1	$at,$f4
/*  f16b5ec:	3c018008 */ 	lui	$at,%hi(var8007e4a8)
/*  f16b5f0:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f16b5f4:	e426e4a8 */ 	swc1	$f6,%lo(var8007e4a8)($at)
/*  f16b5f8:	3c018007 */ 	lui	$at,%hi(var80069880)
/*  f16b5fc:	e4309880 */ 	swc1	$f16,%lo(var80069880)($at)
/*  f16b600:	3c018007 */ 	lui	$at,%hi(g_AmmoMultiplier)
/*  f16b604:	e422995c */ 	swc1	$f2,%lo(g_AmmoMultiplier)($at)
/*  f16b608:	3c017f1b */ 	lui	$at,%hi(var7f1b78a0)
/*  f16b60c:	c42878a0 */ 	lwc1	$f8,%lo(var7f1b78a0)($at)
/*  f16b610:	3c018006 */ 	lui	$at,%hi(var80062cac)
/*  f16b614:	10000076 */ 	b	.L0f16b7f0
/*  f16b618:	e4282cac */ 	swc1	$f8,%lo(var80062cac)($at)
.L0f16b61c:
/*  f16b61c:	1441002d */ 	bne	$v0,$at,.L0f16b6d4
/*  f16b620:	3c013f80 */ 	lui	$at,0x3f80
/*  f16b624:	44810000 */ 	mtc1	$at,$f0
/*  f16b628:	3c013f40 */ 	lui	$at,0x3f40
/*  f16b62c:	44817000 */ 	mtc1	$at,$f14
/*  f16b630:	3c018007 */ 	lui	$at,%hi(var80069948)
/*  f16b634:	e4209948 */ 	swc1	$f0,%lo(var80069948)($at)
/*  f16b638:	3c018007 */ 	lui	$at,%hi(var8006994c)
/*  f16b63c:	e420994c */ 	swc1	$f0,%lo(var8006994c)($at)
/*  f16b640:	3c018007 */ 	lui	$at,%hi(var80069950)
/*  f16b644:	e42e9950 */ 	swc1	$f14,%lo(var80069950)($at)
/*  f16b648:	3c018007 */ 	lui	$at,%hi(var80069954)
/*  f16b64c:	e42e9954 */ 	swc1	$f14,%lo(var80069954)($at)
/*  f16b650:	3c018007 */ 	lui	$at,%hi(var80069958)
/*  f16b654:	e4209958 */ 	swc1	$f0,%lo(var80069958)($at)
/*  f16b658:	3c017f1b */ 	lui	$at,%hi(var7f1b78a4)
/*  f16b65c:	c42a78a4 */ 	lwc1	$f10,%lo(var7f1b78a4)($at)
/*  f16b660:	3c018006 */ 	lui	$at,%hi(var80062ca0)
/*  f16b664:	3c188008 */ 	lui	$t8,%hi(g_LanguageId)
/*  f16b668:	e42a2ca0 */ 	swc1	$f10,%lo(var80062ca0)($at)
/*  f16b66c:	3c017f1b */ 	lui	$at,%hi(var7f1b78a8)
/*  f16b670:	c43278a8 */ 	lwc1	$f18,%lo(var7f1b78a8)($at)
/*  f16b674:	3c018006 */ 	lui	$at,%hi(var80062ca4)
/*  f16b678:	8f184120 */ 	lw	$t8,%lo(g_LanguageId)($t8)
/*  f16b67c:	e4322ca4 */ 	swc1	$f18,%lo(var80062ca4)($at)
/*  f16b680:	3c018006 */ 	lui	$at,%hi(var80062ca8)
/*  f16b684:	e4202ca8 */ 	swc1	$f0,%lo(var80062ca8)($at)
/*  f16b688:	3c018008 */ 	lui	$at,%hi(var8007e4a8)
/*  f16b68c:	13000006 */ 	beqz	$t8,.L0f16b6a8
/*  f16b690:	e42ee4a8 */ 	swc1	$f14,%lo(var8007e4a8)($at)
/*  f16b694:	3c017f1b */ 	lui	$at,%hi(var7f1b78ac)
/*  f16b698:	c42478ac */ 	lwc1	$f4,%lo(var7f1b78ac)($at)
/*  f16b69c:	3c018007 */ 	lui	$at,%hi(var80069880)
/*  f16b6a0:	10000003 */ 	b	.L0f16b6b0
/*  f16b6a4:	e4249880 */ 	swc1	$f4,%lo(var80069880)($at)
.L0f16b6a8:
/*  f16b6a8:	3c018007 */ 	lui	$at,%hi(var80069880)
/*  f16b6ac:	e42e9880 */ 	swc1	$f14,%lo(var80069880)($at)
.L0f16b6b0:
/*  f16b6b0:	3c013f00 */ 	lui	$at,0x3f00
/*  f16b6b4:	44816000 */ 	mtc1	$at,$f12
/*  f16b6b8:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f16b6bc:	44818000 */ 	mtc1	$at,$f16
/*  f16b6c0:	3c018007 */ 	lui	$at,%hi(g_AmmoMultiplier)
/*  f16b6c4:	e430995c */ 	swc1	$f16,%lo(g_AmmoMultiplier)($at)
/*  f16b6c8:	3c018006 */ 	lui	$at,%hi(var80062cac)
/*  f16b6cc:	10000048 */ 	b	.L0f16b7f0
/*  f16b6d0:	e42c2cac */ 	swc1	$f12,%lo(var80062cac)($at)
.L0f16b6d4:
/*  f16b6d4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f16b6d8:	14410027 */ 	bne	$v0,$at,.L0f16b778
/*  f16b6dc:	3c013f80 */ 	lui	$at,0x3f80
/*  f16b6e0:	44810000 */ 	mtc1	$at,$f0
/*  f16b6e4:	3c018007 */ 	lui	$at,%hi(var80069948)
/*  f16b6e8:	3c198008 */ 	lui	$t9,%hi(g_LanguageId)
/*  f16b6ec:	e4209948 */ 	swc1	$f0,%lo(var80069948)($at)
/*  f16b6f0:	3c018007 */ 	lui	$at,%hi(var8006994c)
/*  f16b6f4:	e420994c */ 	swc1	$f0,%lo(var8006994c)($at)
/*  f16b6f8:	3c018007 */ 	lui	$at,%hi(var80069950)
/*  f16b6fc:	e4209950 */ 	swc1	$f0,%lo(var80069950)($at)
/*  f16b700:	3c018007 */ 	lui	$at,%hi(var80069954)
/*  f16b704:	e4209954 */ 	swc1	$f0,%lo(var80069954)($at)
/*  f16b708:	3c018007 */ 	lui	$at,%hi(var80069958)
/*  f16b70c:	e4209958 */ 	swc1	$f0,%lo(var80069958)($at)
/*  f16b710:	3c017f1b */ 	lui	$at,%hi(var7f1b78b0)
/*  f16b714:	c42678b0 */ 	lwc1	$f6,%lo(var7f1b78b0)($at)
/*  f16b718:	3c018006 */ 	lui	$at,%hi(var80062ca0)
/*  f16b71c:	8f394120 */ 	lw	$t9,%lo(g_LanguageId)($t9)
/*  f16b720:	e4262ca0 */ 	swc1	$f6,%lo(var80062ca0)($at)
/*  f16b724:	3c018006 */ 	lui	$at,%hi(var80062ca4)
/*  f16b728:	e4202ca4 */ 	swc1	$f0,%lo(var80062ca4)($at)
/*  f16b72c:	3c018006 */ 	lui	$at,%hi(var80062ca8)
/*  f16b730:	e4202ca8 */ 	swc1	$f0,%lo(var80062ca8)($at)
/*  f16b734:	3c018008 */ 	lui	$at,%hi(var8007e4a8)
/*  f16b738:	13200006 */ 	beqz	$t9,.L0f16b754
/*  f16b73c:	e420e4a8 */ 	swc1	$f0,%lo(var8007e4a8)($at)
/*  f16b740:	3c013f40 */ 	lui	$at,0x3f40
/*  f16b744:	44817000 */ 	mtc1	$at,$f14
/*  f16b748:	3c018007 */ 	lui	$at,%hi(var80069880)
/*  f16b74c:	10000005 */ 	b	.L0f16b764
/*  f16b750:	e42e9880 */ 	swc1	$f14,%lo(var80069880)($at)
.L0f16b754:
/*  f16b754:	3c017f1b */ 	lui	$at,%hi(var7f1b78b4)
/*  f16b758:	c42878b4 */ 	lwc1	$f8,%lo(var7f1b78b4)($at)
/*  f16b75c:	3c018007 */ 	lui	$at,%hi(var80069880)
/*  f16b760:	e4289880 */ 	swc1	$f8,%lo(var80069880)($at)
.L0f16b764:
/*  f16b764:	3c018007 */ 	lui	$at,%hi(g_AmmoMultiplier)
/*  f16b768:	e420995c */ 	swc1	$f0,%lo(g_AmmoMultiplier)($at)
/*  f16b76c:	3c018006 */ 	lui	$at,%hi(var80062cac)
/*  f16b770:	1000001f */ 	b	.L0f16b7f0
/*  f16b774:	e4202cac */ 	swc1	$f0,%lo(var80062cac)($at)
.L0f16b778:
/*  f16b778:	24010003 */ 	addiu	$at,$zero,0x3
/*  f16b77c:	1441001c */ 	bne	$v0,$at,.L0f16b7f0
/*  f16b780:	3c013f80 */ 	lui	$at,0x3f80
/*  f16b784:	44810000 */ 	mtc1	$at,$f0
/*  f16b788:	3c018007 */ 	lui	$at,%hi(var80069948)
/*  f16b78c:	e4209948 */ 	swc1	$f0,%lo(var80069948)($at)
/*  f16b790:	3c018007 */ 	lui	$at,%hi(var8006994c)
/*  f16b794:	e420994c */ 	swc1	$f0,%lo(var8006994c)($at)
/*  f16b798:	3c018007 */ 	lui	$at,%hi(var80069950)
/*  f16b79c:	e4209950 */ 	swc1	$f0,%lo(var80069950)($at)
/*  f16b7a0:	3c018007 */ 	lui	$at,%hi(var80069954)
/*  f16b7a4:	e4209954 */ 	swc1	$f0,%lo(var80069954)($at)
/*  f16b7a8:	3c018007 */ 	lui	$at,%hi(var80069958)
/*  f16b7ac:	e4209958 */ 	swc1	$f0,%lo(var80069958)($at)
/*  f16b7b0:	3c017f1b */ 	lui	$at,%hi(var7f1b78b8)
/*  f16b7b4:	c42a78b8 */ 	lwc1	$f10,%lo(var7f1b78b8)($at)
/*  f16b7b8:	3c018006 */ 	lui	$at,%hi(var80062ca0)
/*  f16b7bc:	e42a2ca0 */ 	swc1	$f10,%lo(var80062ca0)($at)
/*  f16b7c0:	3c018006 */ 	lui	$at,%hi(var80062ca4)
/*  f16b7c4:	e4202ca4 */ 	swc1	$f0,%lo(var80062ca4)($at)
/*  f16b7c8:	3c018006 */ 	lui	$at,%hi(var80062ca8)
/*  f16b7cc:	e4202ca8 */ 	swc1	$f0,%lo(var80062ca8)($at)
/*  f16b7d0:	3c018008 */ 	lui	$at,%hi(var8007e4a8)
/*  f16b7d4:	e420e4a8 */ 	swc1	$f0,%lo(var8007e4a8)($at)
/*  f16b7d8:	3c018007 */ 	lui	$at,%hi(var80069880)
/*  f16b7dc:	e4209880 */ 	swc1	$f0,%lo(var80069880)($at)
/*  f16b7e0:	3c018007 */ 	lui	$at,%hi(g_AmmoMultiplier)
/*  f16b7e4:	e420995c */ 	swc1	$f0,%lo(g_AmmoMultiplier)($at)
/*  f16b7e8:	3c018006 */ 	lui	$at,%hi(var80062cac)
/*  f16b7ec:	e4202cac */ 	swc1	$f0,%lo(var80062cac)($at)
.L0f16b7f0:
/*  f16b7f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16b7f4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f16b7f8:	03e00008 */ 	jr	$ra
/*  f16b7fc:	00000000 */ 	nop
);

s32 sub54321(s32 value)
{
	return value - 54321;
}

void updateCutsceneTime(void)
{
	if (g_Vars.in_cutscene) {
		g_CutsceneTime240_60 += g_Vars.lvupdate240_60;
		return;
	}

	g_CutsceneTime240_60 = 0;
}

GLOBAL_ASM(
glabel getEffectiveSlowMotion
/*  f16b854:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f16b858:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16b85c:	3c04b000 */ 	lui	$a0,0xb000
/*  f16b860:	0fc5ae00 */ 	jal	sub54321
/*  f16b864:	3484de8d */ 	ori	$a0,$a0,0xde8d
/*  f16b868:	3c041741 */ 	lui	$a0,0x1741
/*  f16b86c:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f16b870:	0fc5ae00 */ 	jal	sub54321
/*  f16b874:	3484d42a */ 	ori	$a0,$a0,0xd42a
/*  f16b878:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f16b87c:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f16b880:	0c013994 */ 	jal	osPiReadIo
/*  f16b884:	27a50028 */ 	addiu	$a1,$sp,0x28
/*  f16b888:	8fae0028 */ 	lw	$t6,0x28($sp)
/*  f16b88c:	8faf0024 */ 	lw	$t7,0x24($sp)
/*  f16b890:	3c058006 */ 	lui	$a1,%hi(var80059fe0)
/*  f16b894:	24a29fe0 */ 	addiu	$v0,$a1,%lo(var80059fe0)
/*  f16b898:	11cf000d */ 	beq	$t6,$t7,.L0f16b8d0
/*  f16b89c:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x318)
/*  f16b8a0:	3c188006 */ 	lui	$t8,%hi(var80059fe0+0x1)
/*  f16b8a4:	24431000 */ 	addiu	$v1,$v0,0x1000
/*  f16b8a8:	27189fe1 */ 	addiu	$t8,$t8,%lo(var80059fe0+0x1)
/*  f16b8ac:	0078082b */ 	sltu	$at,$v1,$t8
/*  f16b8b0:	14200007 */ 	bnez	$at,.L0f16b8d0
/*  f16b8b4:	00000000 */ 	nop
.L0f16b8b8:
/*  f16b8b8:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f16b8bc:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f16b8c0:	0043082b */ 	sltu	$at,$v0,$v1
/*  f16b8c4:	27280008 */ 	addiu	$t0,$t9,0x8
/*  f16b8c8:	1420fffb */ 	bnez	$at,.L0f16b8b8
/*  f16b8cc:	ac48fffc */ 	sw	$t0,-0x4($v0)
.L0f16b8d0:
/*  f16b8d0:	8d29a2d8 */ 	lw	$t1,%lo(g_Vars+0x318)($t1)
/*  f16b8d4:	3c02800b */ 	lui	$v0,%hi(g_MpSetup+0xc)
/*  f16b8d8:	1120000b */ 	beqz	$t1,.L0f16b908
/*  f16b8dc:	00000000 */ 	nop
/*  f16b8e0:	8c42cb94 */ 	lw	$v0,%lo(g_MpSetup+0xc)($v0)
/*  f16b8e4:	304a0040 */ 	andi	$t2,$v0,0x40
/*  f16b8e8:	11400003 */ 	beqz	$t2,.L0f16b8f8
/*  f16b8ec:	304b0080 */ 	andi	$t3,$v0,0x80
/*  f16b8f0:	1000001a */ 	b	.L0f16b95c
/*  f16b8f4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f16b8f8:
/*  f16b8f8:	51600018 */ 	beqzl	$t3,.L0f16b95c
/*  f16b8fc:	00001025 */ 	or	$v0,$zero,$zero
/*  f16b900:	10000016 */ 	b	.L0f16b95c
/*  f16b904:	24020002 */ 	addiu	$v0,$zero,0x2
.L0f16b908:
/*  f16b908:	0fc41b99 */ 	jal	cheatIsActive
/*  f16b90c:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f16b910:	10400003 */ 	beqz	$v0,.L0f16b920
/*  f16b914:	00000000 */ 	nop
/*  f16b918:	10000010 */ 	b	.L0f16b95c
/*  f16b91c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f16b920:
/*  f16b920:	0fc47b9c */ 	jal	debugGetSlowMotion
/*  f16b924:	00000000 */ 	nop
/*  f16b928:	24010001 */ 	addiu	$at,$zero,0x1
/*  f16b92c:	14410003 */ 	bne	$v0,$at,.L0f16b93c
/*  f16b930:	00000000 */ 	nop
/*  f16b934:	10000009 */ 	b	.L0f16b95c
/*  f16b938:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f16b93c:
/*  f16b93c:	0fc47b9c */ 	jal	debugGetSlowMotion
/*  f16b940:	00000000 */ 	nop
/*  f16b944:	24010002 */ 	addiu	$at,$zero,0x2
/*  f16b948:	54410004 */ 	bnel	$v0,$at,.L0f16b95c
/*  f16b94c:	00001025 */ 	or	$v0,$zero,$zero
/*  f16b950:	10000002 */ 	b	.L0f16b95c
/*  f16b954:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f16b958:	00001025 */ 	or	$v0,$zero,$zero
.L0f16b95c:
/*  f16b95c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16b960:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f16b964:	03e00008 */ 	jr	$ra
/*  f16b968:	00000000 */ 	nop
);

// Can't match the antipiracy part
//u32 getEffectiveSlowMotion(void)
//{
//#if PIRACYCHECKS
//	u32 addr = sub54321(0xb000de8d);
//	u32 actual;
//	u32 expected = sub54321(0x1741d42a);
//	osPiReadIo(addr, &actual);
//
//	if (actual != expected) {
//		extern u32 _rspMicrocodeStart;
//		extern u32 _rspMicrocodeStartPlusOne;
//		u32 *ptr = &_rspMicrocodeStart;
//		u32 *end = &ptr[1024];
//
//		if (!(end < &_rspMicrocodeStartPlusOne)) {
//			do {
//				*ptr += 8;
//				ptr++;
//			} while (ptr < end);
//		}
//	}
//#endif
//
//	if (g_Vars.normmplayerisrunning) {
//		if (g_MpSetup.options & MPOPTION_SLOWMOTION_ON) {
//			return SLOWMOTION_ON;
//		}
//		if (g_MpSetup.options & MPOPTION_SLOWMOTION_SMART) {
//			return SLOWMOTION_SMART;
//		}
//	} else {
//		if (cheatIsActive(CHEAT_SLOMO)) {
//			return SLOWMOTION_ON;
//		}
//		if (debugGetSlowMotion() == SLOWMOTION_ON) {
//			return SLOWMOTION_ON;
//		}
//		if (debugGetSlowMotion() == SLOWMOTION_SMART) {
//			return SLOWMOTION_SMART;
//		}
//	}
//
//	return SLOWMOTION_OFF;
//}

void func0f16b96c(void)
{
	s32 j;
	s32 i;

	func0f16cce4();

	if (g_Vars.unk0004e4) {
		func0f11c54c();
	}

	if (g_Vars.unk0004d8 > 0) {
		g_Vars.unk0004d8--;
	} else if (g_Vars.unk0004d8 == 0) {
		func00013938();

		if (g_Vars.stagenum == STAGE_TITLE
				|| g_Vars.stagenum == STAGE_BOOTPAKMENU
				|| g_Vars.stagenum == STAGE_CREDITS
				|| g_Vars.stagenum == STAGE_4MBMENU) {
			g_Vars.unk0004d1 = 0;
		} else {
			g_Vars.unk0004d1 = 31;
			func0f11df38();
		}

		g_Vars.unk0004d8 = -1;
	}

	if (IS4MB()) {
		func0f19ab40();
	}

	for (j = 0; j < PLAYERCOUNT(); j++) {
		g_Vars.players[j]->hands[1].unk0cec = 0;
		g_Vars.players[j]->hands[0].unk0cec = 0;
	}

	if (soloIsPaused()) {
		g_Vars.lvupdate240 = 0;
	} else if (mpIsPaused()) {
		g_Vars.lvupdate240 = 0;

		for (j = 0; j < PLAYERCOUNT(); j++) {
			g_Vars.players[j]->joybutinhibit = 0xefffefff;
		}
	} else {
		s32 slowmo = getEffectiveSlowMotion();
		g_Vars.lvupdate240 = g_Vars.diffframe240;

		if (slowmo == SLOWMOTION_ON) {
			if (g_Vars.speedpillon == false || g_Vars.in_cutscene) {
				if (g_Vars.lvupdate240 > 4) {
					g_Vars.lvupdate240 = 4;
				}
			}
		} else if (slowmo == SLOWMOTION_SMART) {
			// Smart slow motion - activates if an enemy chr is nearby
			if (g_Vars.speedpillon == false || g_Vars.in_cutscene) {
				if (g_Vars.mplayerisrunning) {
					bool foundnearbychr = false;
					s32 playernum;

					// Check if another player is in a nearby room
					for (playernum = 0; playernum < PLAYERCOUNT() && !foundnearbychr; playernum++) {
						if (g_Vars.players[playernum]->isdead == false) {
							s16 *rooms = g_Vars.players[playernum]->prop->rooms;
							s32 r;

							for (r = 0; rooms[r] != -1 && !foundnearbychr; r++) {
								s32 otherplayernum;
								for (otherplayernum = 0; otherplayernum < PLAYERCOUNT(); otherplayernum++) {
									if (playernum != otherplayernum
											&& g_Vars.players[otherplayernum]->isdead == false
											&& roomIsVisibleByPlayer(rooms[r], otherplayernum)) {
										foundnearbychr = true;
									}
								}
							}
						}
					}

					if (foundnearbychr) {
						if (g_Vars.lvupdate240 > 4) {
							g_Vars.lvupdate240 = 4;
						}
					} else {
						if (g_Vars.lvupdate240 > 8) {
							g_Vars.lvupdate240 = 8;
						}
					}
				} else {
					if (g_Vars.lvupdate240 > 4) {
						g_Vars.lvupdate240 = 4;
					}
				}
			}
		} else {
			// Slow motion settings are off
			if (g_Vars.speedpillon && g_Vars.in_cutscene == false) {
				if (g_Vars.lvupdate240 > 4) {
					g_Vars.lvupdate240 = 4;
				}
			}
		}
	}

	g_Vars.lvupdate240_60 = g_Vars.lvupdate240 + g_Vars.lvupdate240_60error;
	g_Vars.lvupdate240_60error = g_Vars.lvupdate240_60 & 3;
	g_Vars.lvupdate240_60 >>= 2;

	if (g_Vars.lvupdate240 > 0) {
		g_Vars.lvframenum++;
	}

	g_Vars.lvupdate240f = g_Vars.lvupdate240 * 0.25f;
	g_Vars.lvframe60 += g_Vars.lvupdate240_60;
	g_Vars.lvframe240 += g_Vars.lvupdate240;
	g_Vars.lvupdate240frealprev = g_Vars.lvupdate240freal;
	g_Vars.lvupdate240freal = g_Vars.lvupdate240f;

	func0f0abc28();
	func0f0df364();

	if ((func00015020(0, 0xffff) != 0
				|| contGetStickX(0) > 10
				|| contGetStickX(0) < -10
				|| contGetStickY(0) > 10
				|| contGetStickY(0) < -10
				|| func00015020(1, 0xffff) != 0
				|| contGetStickX(1) > 10
				|| contGetStickX(1) < -10
				|| contGetStickY(1) > 10
				|| contGetStickY(1) < -10
				|| func00015020(2, 0xffff) != 0
				|| contGetStickX(2) > 10
				|| contGetStickX(2) < -10
				|| contGetStickY(2) > 10
				|| contGetStickY(2) < -10
				|| func00015020(3, 0xffff) != 0
				|| contGetStickX(3) > 10
				|| contGetStickX(3) < -10
				|| contGetStickY(3) > 10
				|| contGetStickY(3) < -10) && var800624a4) {
		if (g_Vars.stagenum != STAGE_TITLE) {
			titleSetNextMode(TITLEMODE_SKIP);
			mainSetStageNum(STAGE_TITLE);
		}

		var800624a4 = 0;
	}

	if (g_Vars.stagenum < STAGE_TITLE && !var800624a4 && !g_Vars.in_cutscene) {
		if (contGetButtons(0, 0xffff) == 0
				&& contGetStickX(0) < 10
				&& contGetStickX(0) > -10
				&& contGetStickY(0) < 10
				&& contGetStickY(0) > -10
				&& contGetButtons(1, 0xffff) == 0
				&& contGetStickX(1) < 10
				&& contGetStickX(1) > -10
				&& contGetStickY(1) < 10
				&& contGetStickY(1) > -10
				&& contGetButtons(2, 0xffff) == 0
				&& contGetStickX(2) < 10
				&& contGetStickX(2) > -10
				&& contGetStickY(2) < 10
				&& contGetStickY(2) > -10
				&& contGetButtons(3, 0xffff) == 0
				&& contGetStickX(3) < 10
				&& contGetStickX(3) > -10
				&& contGetStickY(3) < 10
				&& contGetStickY(3) > -10) {
			var800624b0 += g_Vars.diffframe60;
		} else {
			var800624b0 = 0;
		}
	} else {
		var800624b0 = 0;
	}

	g_NumReasonsToEndMpMatch = 0;

	// Handle MP match ending
	if (g_Vars.normmplayerisrunning && g_Vars.stagenum < STAGE_TITLE) {
		if (g_MpTimeLimit > 0) {
			s32 elapsed = g_StageTimeElapsed;
			s32 nexttime = g_Vars.lvupdate240_60 + g_StageTimeElapsed;
			s32 warntime = g_MpTimeLimit - 3600;

			// Show HUD message at one minute remaining
			if (elapsed < warntime && nexttime >= warntime) {
				s32 i;

				for (i = 0; i < PLAYERCOUNT(); i++) {
					setCurrentPlayerNum(i);
					hudmsgCreateViaPreset(langGet(L_MISC(68)), 0); // "One minute left."
				}
			}

			if (elapsed < g_MpTimeLimit && nexttime >= g_MpTimeLimit) {
				// Match is ending due to time limit reached
				mainEndStage();
			}

			// Sound alarm at 10 seconds remaining
			if (nexttime >= g_MpTimeLimit - 600
					&& g_MiscAudioHandle == NULL
					&& !soloIsPaused()
					&& nexttime < g_MpTimeLimit) {
				func00010718(&g_MiscAudioHandle, 0, 0x7fff, 0x40, 163, 1, 1, -1, 1);
			}
		}

		if (g_Vars.lvupdate240 != 0) {
			s32 numdying = 0;

			for (i = 0; i < PLAYERCOUNT(); i++) {
				if (g_Vars.players[i]->isdead) {
					if (g_Vars.players[i]->redbloodfinished == false
							|| g_Vars.players[i]->deathanimfinished == false
							|| g_Vars.players[i]->colourfadetimemax60 >= 0) {
						numdying++;
					}
				}
			}

			for (i = 0; i < g_MpNumPlayers; i++) {
				if (g_MpPlayerChrs[i]->actiontype == ACT_DIE) {
					numdying++;
				}
			}

			if (g_MpScoreLimit > 0) {
				struct mpteaminfo info[12];
				s32 count = mpGetPlayerRankings(info);

				for (i = 0; i < count; i++) {
					if (info[i].score >= g_MpScoreLimit) {
						g_NumReasonsToEndMpMatch++;
					}
				}
			}

			if (g_MpTeamScoreLimit > 0) {
				struct mpteaminfo info[12];
				s32 count = mpGetTeamRankings(info);

				for (i = 0; i < count; i++) {
					if (info[i].score >= g_MpTeamScoreLimit) {
						g_NumReasonsToEndMpMatch++;
					}
				}
			}

			if (g_NumReasonsToEndMpMatch > 0 && numdying == 0) {
				mainEndStage();
			}
		}
	}

	g_StageTimeElapsed += g_Vars.lvupdate240_60;
	g_StageTimeElapsed60f = g_StageTimeElapsed / 60.0f;

	viSetUseZBuf(true);

	if (g_Vars.stagenum == STAGE_TEST_OLD) {
		func0f01ae30();
		func00011d84();
	}

	if (g_Vars.stagenum == STAGE_TITLE) {
		titleTick();
		func0f01d860();
		func00011d84();
	} else if (g_Vars.stagenum == STAGE_BOOTPAKMENU) {
		setCurrentPlayerNum(0);
		menuTickAll();
		func00011d84();
		func0f01d860();
		func0f11c7a0();
	} else if (g_Vars.stagenum == STAGE_4MBMENU) {
		menuTickAll();
		func00011d84();
		func0f01d860();
		func0f11c7a0();
	} else if (g_Vars.stagenum == STAGE_CREDITS) {
		func00011d84();
		func0f01d860();
	} else {
		updateCutsceneTime();
		func0f12939c();
		func0f16b0c8();
		func0f01d8c0();
		func0f01d990();
		func0f01dd6c();
		func0f01de30();
		sparksTick();
		func0f13eb44();
		func0f149864();

		if (g_WeatherEnabled) {
			weatherTick();
		}

		if (var80061640) {
			func0f009eac();
		}

		boostAndSlayerSfxUpdate();
		func0000fe88();
		func0f11c7a0();
		func0f0033b0();
		func0f0b2904();
		func0f0aefb8();
		activemenuTick();
		menuTickAll();
		scenarioCallback10();

		if (var8005d9d0 == 0) {
			func0f01e250();
		}

		func00011d84();
		func0f01d860();
		func0f063dcc();

		if (mainGetStageNum() == STAGE_CITRAINING) {
			struct trainingdata *trainingdata = dtGetData();

			if ((g_Vars.currentplayer->prop->rooms[0] < CIROOM_HOLOSTART || g_Vars.currentplayer->prop->rooms[0] > CIROOM_HOLOEND)
					&& g_Vars.currentplayer->prop->rooms[0] != CIROOM_FIRINGRANGE
					&& (trainingdata == NULL || trainingdata->intraining == false)) {
				chrUnsetStageFlag(NULL, STAGEFLAG_CI_IN_TRAINING);
			}

			frTick();

			if (g_Vars.lvupdate240 != 0) {
				dtTick();
				htTick();
			}
		}
	}
}

void currentPlayerRecordDistanceMoved(void)
{
	f32 xdiff;
	f32 zdiff;

	if (var80075d64 == 2) {
		if (var80075d68 == 2) {
			func0f0bd904(true);
		} else {
			func0f0bd904(false);
		}
	}

	xdiff = g_Vars.currentplayer->prop->pos.x - g_Vars.currentplayer->bondprevpos.x;
	zdiff = g_Vars.currentplayer->prop->pos.z - g_Vars.currentplayer->bondprevpos.z;

	g_Vars.currentplayerstats->distance += sqrtf(xdiff * xdiff + zdiff * zdiff);
}

void stageLoad(void)
{
	func0f11dcb0(1);

	if (g_MiscAudioHandle && func000337f0(g_MiscAudioHandle)) {
		audioStop(g_MiscAudioHandle);
	}

	if (g_Vars.stagenum < NUM_STAGES) {
		s32 bank = langGetLangBankIndexFromStagenum(g_Vars.stagenum);
		langClearBank(bank);
		func0f015270();
	}

	func0f014f10();
	func0f015280();
	func0f015330();
	func0f015400();
	func0f015410();
	func0f015420();
	func0f0153f0();
	func0f014fe0();
	func0f015010();
	weatherFree();
	func0f0151f0();
	func0f015260();
	func0f015470();
	func0f0150a0();
	func0f16d9fc();
	hudmsgsReset();

	if (g_Vars.stagenum < NUM_STAGES) {
		func0f15c850();
	}

	func00033dd8();

	if (var80062940 == 2) {
		menuPlaySound(5);
		var80062940 = 0;
	}

	func0f01bea0();
}

void func0f16cce4(void)
{
	u32 paused = mpIsPaused();

	if (paused != var80084010) {
		if (paused) {
			func0f11deb8();
		} else {
			func0f11df38();
		}
	}

	var80084010 = paused;
}

void soloSetPaused(bool paused)
{
	if (paused) {
		func0f11deb8();
		func0000fe20();
	} else {
		func0000fe50();
		func0f11df38();
	}

	var80084014 = paused;
}

bool soloIsPaused(void)
{
	return var80084014;
}

s32 getDifficulty(void)
{
	return g_Difficulty;
}

void setDifficulty(s32 difficulty)
{
	if (difficulty < DIFF_A || difficulty > DIFF_PD) {
		difficulty = DIFF_A;
	}

	g_Difficulty = difficulty;
}

void mpSetTimeLimit(u32 limit)
{
	g_MpTimeLimit = limit;
}

void mpSetScoreLimit(u32 limit)
{
	g_MpScoreLimit = limit;
}

void mpSetTeamScoreLimit(u32 limit)
{
	g_MpTeamScoreLimit = limit;
}

f32 getUptime(void)
{
	return g_StageTimeElapsed60f;
}

u32 mpGetTimeElapsed(void)
{
	return g_StageTimeElapsed;
}

u32 func0f16ce04(u32 arg0)
{
	return arg0;
}
