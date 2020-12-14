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
s32 var80084050 = 0;

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

	if (g_Vars.lvupdate240 == 0 && g_MiscAudioHandle && audioIsPlaying(g_MiscAudioHandle)) {
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
	g_Vars.paksconnected = 0;
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
	g_Vars.antiheadnum = -1;
	g_Vars.antibodynum = -1;
	g_Vars.dontplaynrg = false;
	g_Vars.in_cutscene = 0;
	g_Vars.unk0004d3 = 0;
	g_Vars.unk0004d6 = 0;
	g_Vars.unk0004d7 = 0;

	g_MiscAudioHandle = NULL;

	func0f16d324();
	func0f011124(true);
	func0f013b80();
	texturesLoadConfigs();
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
	setupResetObjectives();
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
		pakPushPakMenuDialog();
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
			var800a2380[4].unk2be = 0;
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
	gDPSetPrimColorViaWord(gdl++, 0, 0, colour);

	gDPFillRectangle(gdl++,
			viGetViewLeft(),
			viGetViewTop() + inset,
			viGetViewLeft() + viGetViewWidth() + 1,
			viGetViewTop() + viGetViewHeight() - inset + 2);

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

/**
 * Renders a complete frame for all players, and also does some other game logic
 * that really doesn't belong here.
 *
 * This function is pretty big, so here's an overview of its structure:
 *
 * if (stage == STAGE_TITLE) {
 *     // title screen rendering
 * } else if (stage == STAGE_BOOTPAKMENU) {
 *     // boot pak menu rendering
 * } else if (stage == STAGE_4MBMENU) {
 *     // 4MB menu rendering
 * } else if (stage == STAGE_CREDITS) {
 *     // credits rendering
 * } else {
 *     for (i = 0; i < numplayers; i++) {
 *         // rendering and logic per player
 *     }
 * }
 * // logic for auto-playing cutscene advancement
 *
 * The player loop takes up the majority of the function. In addition to
 * rendering the scene and HUD, it also handles the following logic:
 * - decreasing dizziness
 * - detecting if the prop being looked at is still valid
 * - pressing Z when using eyespy
 * - opening doors and reloading
 * - random static in the Infiltration intro cutscene
 * - combat boost activation and reverting
 */
Gfx *renderFrame(Gfx *gdl)
{
	gSPSegment(gdl++, 0x00, 0x00000000);

	func0f0d5a7c();

	if (g_Vars.stagenum == STAGE_TITLE
			|| (g_Vars.stagenum == STAGE_TEST_OLD && titleIsKeepingMode())) {
		gSPDisplayList(gdl++, &var800613a0);

		if (debug0f11ee28()) {
			gSPDisplayList(gdl++, &var80061360);
		} else {
			gSPDisplayList(gdl++, &var80061380);
		}

		gdl = func0000b280(gdl);
		gdl = func0000b1d0(gdl);

		gDPSetScissorFrac(gdl++, 0,
				viGetViewLeft() * 4.0f, viGetViewTop() * 4.0f,
				(viGetViewLeft() + viGetViewWidth()) * 4.0f,
				(viGetViewTop() + viGetViewHeight()) * 4.0f);

		gdl = titleRender(gdl);
		gdl = fadeRender(gdl);
	} else if (g_Vars.stagenum == STAGE_BOOTPAKMENU) {
		gSPClipRatio(gdl++, FRUSTRATIO_2);
		gSPDisplayList(gdl++, &var800613a0);
		gSPDisplayList(gdl++, &var80061380);

		setCurrentPlayerNum(0);
		viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
		viSetFovAspectAndSize(g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
				g_Vars.currentplayer->viewx, g_Vars.currentplayer->viewy);
		func00016748(1);

		gdl = func0000b1d0(gdl);
		gdl = func0000b330(gdl);
		gdl = func0f15cb74(gdl);
		gdl = func0f0fbc30(gdl);
	} else if (g_Vars.stagenum == STAGE_4MBMENU) {
		gSPClipRatio(gdl++, FRUSTRATIO_2);
		gSPDisplayList(gdl++, &var800613a0);
		gSPDisplayList(gdl++, &var80061380);

		setCurrentPlayerNum(0);
		viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
		viSetFovAspectAndSize(g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
				g_Vars.currentplayer->viewx, g_Vars.currentplayer->viewy);
		func00016748(1);

		gdl = func0000b1d0(gdl);
		gdl = func0f15cb74(gdl);
		gdl = func0f0fbc30(gdl);

		if (g_Vars.currentplayer->pausemode != PAUSEMODE_UNPAUSED) {
			currentPlayerTickPauseMenu();
		}
	} else if (g_Vars.stagenum == STAGE_CREDITS) {
		gSPClipRatio(gdl++, FRUSTRATIO_2);
		gSPDisplayList(gdl++, &var800613a0);
		gSPDisplayList(gdl++, &var80061380);

		setCurrentPlayerNum(0);
		viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
		viSetFovAspectAndSize(g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
				g_Vars.currentplayer->viewx, g_Vars.currentplayer->viewy);
		func00016748(1);

		gdl = func0000b1a8(gdl);
		gdl = func0000b1d0(gdl);
		gdl = func0000b330(gdl);
		gdl = func0f13b064(gdl);
	} else {
		// Normal stages
		s32 i;
		s32 playercount;
		Gfx *savedgdl;
		bool forcesingleplayer = (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
			&& func0f0bc4c0();
		struct player *player;
		struct chrdata *chr;

		playercount = forcesingleplayer ? 1 : PLAYERCOUNT();

		gSPClipRatio(gdl++, FRUSTRATIO_2);

		for (i = 0; i < playercount; i++) {
			bool islastplayer;
			u32 bluramount = 0;

			savedgdl = gdl;

			if (forcesingleplayer) {
				setCurrentPlayerNum(0);
				g_Vars.currentplayerindex = 0;
				islastplayer = true;
			} else {
				s32 nextplayernum = i + 1;
				setCurrentPlayerNum(getPlayerByOrderNum(i));
				islastplayer = playercount == nextplayernum;
			}

			// Calculate bluramount - this will be used later
			if (g_Vars.tickmode != TICKMODE_CUTSCENE) {
				player = g_Vars.currentplayer;
				chr = player->prop->chr;

				if (chr->blurdrugamount > 0
						&& !g_Vars.currentplayer->invincible
						&& !g_Vars.currentplayer->training) {
					bluramount = (chr->blurdrugamount * 130) / 5000 + 100;

					if (bluramount > 230) {
						bluramount = 230;
					}

					if (chr->blurdrugamount > 5000) {
						chr->blurdrugamount = 5000;
					}

					chr->blurdrugamount -= g_Vars.lvupdate240_60 * (chr->blurnumtimesdied + 1);

					if (chr->blurdrugamount < 1) {
						chr->blurdrugamount = 0;
						chr->blurnumtimesdied = 0;
					}
				}
			}

			func0f148b40(bluramount);

			gSPDisplayList(gdl++, &var800613a0);

			if (debug0f11ee28()) {
				gSPDisplayList(gdl++, &var80061360);
			} else {
				gSPDisplayList(gdl++, &var80061380);
			}

			viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
			viSetFovAspectAndSize(g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
					g_Vars.currentplayer->viewx, g_Vars.currentplayer->viewy);
			func00016748(g_Vars.currentplayerstats->scale_bg2gfx);
			func0f1657f8();
			func0f176298();
			gdl = func0000b280(gdl);
			gdl = func0000b1d0(gdl);
			gdl = func0f15cb74(gdl);
			func0f13c510();

			if ((g_Vars.stagenum != STAGE_CITRAINING || (var80087260 <= 0 && g_MenuData.root != MENUROOT_MPSETUP))
					&& g_Vars.lvframenum <= 5
					&& !g_Vars.normmplayerisrunning
					&& g_Vars.tickmode != TICKMODE_CUTSCENE) {
				if (var80084050 < 6) {
					g_Vars.unk000320 = 1;
				}

				var80084050++;
			} else if (g_Vars.currentplayer->unk1583_06
					&& var80075d60 == 2
					&& g_Vars.currentplayer->cameramode != CAMERAMODE_THIRDPERSON
					&& g_Vars.currentplayer->cameramode != CAMERAMODE_EYESPY
					&& var8009dfc0 == 0) {
				g_Vars.currentplayer->unk1583_06 = func0f09eae4();
			}

			if (g_Vars.unk000320) {
				gdl = hudRenderMotionBlur(gdl, 0xffffffff, 255);
				g_Vars.unk000320--;
			} else if (var8009dfc0) {
				gdl = func0000b330(gdl);
				gdl = func0f15cb74(gdl);
				func00016748(1);

				if (g_Vars.currentplayer->unk1c50_01) {
					gdl = func0f0fbc30(gdl);
				}
			} else {
				if (var80075d60 == 2) {
					gdl = func0f0bffcc(gdl);
				}

				gdl = func0000b330(gdl);
				gdl = func0f11f984(gdl);
				func0f15ca00();
				func0f004314();
				func0f06302c(islastplayer);
				scenarioCallback14(NULL);
				func0f0601b0();
				func0f064ce8();
				func0f062b2c();

				// Calculate lookingatprop
				if (PLAYERCOUNT() == 1
						|| g_Vars.coopplayernum >= 0
						|| g_Vars.antiplayernum >= 0
						|| (weaponHasFlag(getCurrentPlayerWeaponId(0), WEAPONFLAG_AIMTRACK) && currentPlayerIsInSightAimMode())) {
					g_Vars.currentplayer->lookingatprop.prop = func0f061d54(0, 0, 0);

					if (g_Vars.currentplayer->lookingatprop.prop) {
						if (g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_CHR
								|| g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_PLAYER) {
							chr = g_Vars.currentplayer->lookingatprop.prop->chr;

							if (chr->hidden & CHRHFLAG_CLOAKED) {
								if (g_Vars.currentplayer->isdead
										|| var80070764
										|| !EYESPYINACTIVE()
										|| (g_Vars.currentplayer->itemswitch & ~g_Vars.currentplayer->unk1c54 & 8) == 0) {
									g_Vars.currentplayer->lookingatprop.prop = NULL;
								}
							}
						} else if (g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_OBJ
								|| g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_WEAPON
								|| g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_DOOR) {
							struct defaultobj *obj = g_Vars.currentplayer->lookingatprop.prop->obj;

							if ((obj->flags3 & OBJFLAG3_00008000) == 0) {
								if (g_Vars.stagenum != STAGE_CITRAINING
										|| (obj->modelnum != MODEL_TARGET
											&& obj->modelnum != MODEL_CIHUB
											&& obj->modelnum != MODEL_COMHUB)) {
									g_Vars.currentplayer->lookingatprop.prop = NULL;
								}
							}
						} else {
							g_Vars.currentplayer->lookingatprop.prop = NULL;
						}
					}
				} else {
					g_Vars.currentplayer->lookingatprop.prop = NULL;
				}

				if (func0f0b1ea8(g_Vars.currentplayer->hands, 0x80000)) {
					func0f1691c0();
				} else if (weaponHasFlag(getCurrentPlayerWeaponId(0), WEAPONFLAG_AIMTRACK)) {
					s32 j;

					if (frIsInTraining()
							&& g_Vars.currentplayer->lookingatprop.prop
							&& currentPlayerIsInSightAimMode()) {
						func0f1a0924(g_Vars.currentplayer->lookingatprop.prop);
					} else if (threatCheckCmpFollow(&g_Vars.currentplayer->lookingatprop, -1) == 0) {
						g_Vars.currentplayer->lookingatprop.prop = NULL;
					}

					for (j = 0; j < 4; j++) {
						if (!threatCheckCmpFollow(&g_Vars.currentplayer->cmpfollowprops[j], j)) {
							g_Vars.currentplayer->cmpfollowprops[j].unk04 = -1;
							g_Vars.currentplayer->cmpfollowprops[j].unk08 = -2;
						}
					}
				}

				// Handle eyespy Z presses
				if (g_Vars.currentplayer->eyespy
						&& (g_Vars.currentplayer->itemswitch & ~g_Vars.currentplayer->unk1c54 & 4)
						&& g_Vars.currentplayer->eyespy->camerabuttonheld) {
					if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
						objectiveCheckHolograph(400);
						audioStart(var80095200, 0x4ff, 0, -1, -1, -1, -1, -1);
					} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
						if (g_Vars.currentplayer->eyespydarts) {
							// Fire dart
							struct coord direction;
							audioStart(var80095200, 0x8057, 0, -1, -1, -1, -1, -1);
							g_Vars.currentplayer->eyespydarts--;

							direction.x = g_Vars.currentplayer->eyespy->look.x;
							direction.y = g_Vars.currentplayer->eyespy->look.y;
							direction.z = g_Vars.currentplayer->eyespy->look.z;

							func0f0912dc(g_Vars.currentplayer->eyespy->prop, 0,
									&g_Vars.currentplayer->eyespy->prop->pos, &direction, WEAPON_TRANQUILIZER, 0);
						} else {
							// No dart ammo
							audioStart(var80095200, 0x8052, 0, -1, -1, -1, -1, -1);
						}
					} else { // EYESPYMODE_BOMBSPY
						struct coord spd4 = {0, 0, 0};
						s8 spd0[] = {30, 0, 0, 0};
						explosionCreateSimple(g_Vars.currentplayer->eyespy->prop,
								&g_Vars.currentplayer->eyespy->prop->pos,
								g_Vars.currentplayer->eyespy->prop->rooms,
								EXPLOSIONTYPE_23, 0);
						func0f0319a8(g_Vars.currentplayer->eyespy->prop->chr, &spd4, 0, 0, spd0, 0, 0);
					}
				}

				// Handle opening doors and reloading
				if (g_Vars.currentplayer->bondactivateorreload) {
					if (currentPlayerInteract(false)) {
						currentPlayerReloadHandIfPossible(HAND_RIGHT);
						currentPlayerReloadHandIfPossible(HAND_LEFT);
					}
				} else if (g_Vars.currentplayer->eyespy
						&& g_Vars.currentplayer->eyespy->active
						&& g_Vars.currentplayer->eyespy->opendoor) {
					currentPlayerInteract(true);
				}

				func0f0641f4();
				gdl = func0f15cae0(gdl);
				func0f028498(var80075d68 == 15 || var8005f020);
				gdl = func0f07f6d0(gdl);
				gdl = func0f1526e4(gdl);
				gdl = func0f130044(gdl);
				gdl = weatherRender(gdl);

				if (var80061640) {
					gdl = func0f00a168(gdl);
				}

				if (var80075d60 == 2) {
					gdl = func0f0c07c8(gdl);
				} else {
					gdl = func0f0aeed8(gdl);

					if (g_Vars.currentplayer->visionmode != VISIONMODE_XRAY) {
						gdl = func0f15b114(gdl);
					}
				}

				if (var80075d78 <= 0) {
					static struct audiohandle *g_CutsceneStaticAudioHandle = NULL;
					static s32 g_CutsceneStaticTimer = 100;
					static u8 g_CutsceneStaticActive = false;
					bool cutscenehasstatic = false;
					u32 alpha;

					if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
						// This chunk of code is unreachable
						// (STAGE_TEST_OLD is not used)
						if (g_Vars.stagenum == STAGE_TEST_OLD) {
							f32 frac = 0;
							u32 colour;
							s32 endframe = animGetNumFrames(g_CameraAnimNum) - 1;

							colour = 0;

							if (g_CameraAnimCurFrame < STAGE_TITLE) {
								frac = 1.0f - (f32)g_CameraAnimCurFrame / 90.0f;
							}

							if (g_CameraAnimNum != 0x46c) {
								if (g_CameraAnimCurFrame > endframe - 90) {
									frac = (g_CameraAnimCurFrame - endframe + 90) / 90.0f;
								}
							} else {
								if (g_CameraAnimCurFrame > endframe - 30) {
									colour = 0xffffff00;
									frac = (g_CameraAnimCurFrame - endframe + 30) / 30.0f;
								}
							}

							if (frac > 0) {
								alpha = 255 * frac;

								gDPPipeSync(gdl++);
								gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
								gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
								gDPSetPrimColorViaWord(gdl++, 0, 0, colour | alpha);

								gDPFillRectangle(gdl++,
									viGetViewLeft(),
									viGetViewTop(),
									viGetViewLeft() + viGetViewWidth(),
									viGetViewTop() + viGetViewHeight());

								gdl = func0f153838(gdl);
							}
						}

						// Handle visual effects in cutscenes
						switch (g_CameraAnimNum) {
						case 0x1e5:
							// Horizon scanner in Air Base intro
							if (g_CameraAnimCurFrame > 839 && g_CameraAnimCurFrame < 1411) {
								gdl = hudRenderHorizonScanner(gdl);
							}
							break;
						case 0x181:
						case 0x183:
						case 0x188:
							{
								// Show static randomly in Infiltration intro
								s32 cutscenestatic = 0;
								cutscenehasstatic = true;

								if (g_CutsceneStaticAudioHandle == NULL) {
									audioStart(var80095200, 0x59f, &g_CutsceneStaticAudioHandle, -1, -1, -1, -1, -1);
								}

								g_CutsceneStaticTimer -= g_Vars.diffframe60;

								if (g_CutsceneStaticTimer < 0) {
									g_CutsceneStaticTimer = random() % 200 + 40;
									g_CutsceneStaticActive = false;
								}

								gdl = func0f14298c(gdl, 0xffffffff, 0xffffffff);

								if (g_CutsceneStaticTimer < 15) {
									if (g_CutsceneStaticActive == false) {
										g_CutsceneStaticActive = true;
										audioStart(var80095200, 0x59e, NULL, -1, -1, -1, -1, -1);
									}

									cutscenestatic = 225 - g_CutsceneStaticTimer * 10;
								}

								// Consider a single frame of static, separate
								// to the main static above
								if (random() % 60 == 1) {
									cutscenestatic = 255;
									audioStart(var80095200, 0x59d, NULL, -1, -1, -1, -1, -1);
								}

								if (cutscenestatic) {
									gdl = hudRenderStatic(gdl, 0xffffffff, cutscenestatic);
								}
							}
							break;
						}
					}

					if (g_CutsceneStaticAudioHandle && !cutscenehasstatic) {
						audioStop(g_CutsceneStaticAudioHandle);
					}

					// Slayer rocket shows static when flying out of bounds
					if (g_Vars.currentplayer->visionmode == VISIONMODE_SLAYERROCKET
							&& g_Vars.tickmode != TICKMODE_CUTSCENE) {
						gdl = hudRenderSlayerRocketLens(gdl, 0xffffffff, 0xffffffff);

						if (g_Vars.currentplayer->badrockettime > 0) {
							u32 slayerstatic = g_Vars.currentplayer->badrockettime * 255 / 90;

							if (slayerstatic > 255) {
								slayerstatic = 255;
							}

							gdl = hudRenderStatic(gdl, 0x4fffffff, slayerstatic);
						}
					}

					if (g_Vars.currentplayer->visionmode == VISIONMODE_3) {
						gdl = hudRenderStatic(gdl, 0x4fffffff, 255);
						g_Vars.currentplayer->visionmode = VISIONMODE_NORMAL;
					}

					if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY
							&& g_Vars.tickmode != TICKMODE_CUTSCENE) {
						s32 xraything = 99;

						if (g_Vars.currentplayer->erasertime < 200) {
							xraything = 249 - (g_Vars.currentplayer->erasertime * 3 >> 2);
						}

						gdl = func0f142bf0(gdl, 0xffffffff, xraything, 1.05f, 1.05f);
					}

					// Handle combat boosts
					if ((g_Vars.speedpillchange > 0 && g_Vars.speedpillchange < 30)
							|| (g_Vars.speedpillwant && !g_Vars.speedpillon)
							|| (!g_Vars.speedpillwant && g_Vars.speedpillon)) {
						if (g_Vars.speedpillchange == 30 && !g_Vars.speedpillwant) {
							audioStart(var80095200, getEffectiveSlowMotion() ? 0x5c9 : 0x2ad, 0, -1, -1, -1, -1, -1);
						}

						if (g_Vars.speedpillchange < 15) {
							gdl = func0f142bf0(gdl, 0xffffffff,
									g_Vars.speedpillchange * 180 / 15,
									(f32)g_Vars.speedpillchange * 0.02000000141561f + 1.1f,
									(f32)g_Vars.speedpillchange * 0.02000000141561f + 1.1f);
							gdl = fadeDraw(gdl, 0xff, 0xff, 0xff,
									g_Vars.speedpillchange * 0.0066666668280959f);
						} else {
							gdl = func0f142bf0(gdl, 0xffffffff,
									(30 - g_Vars.speedpillchange) * 180 / 15,
									(f32)(30 - g_Vars.speedpillchange) * 0.02000000141561f + 1.1f,
									(f32)(30 - g_Vars.speedpillchange) * 0.02000000141561f + 1.1f);
							gdl = fadeDraw(gdl, 0xff, 0xff, 0xff,
									(30.0f - g_Vars.speedpillchange) * 0.0066666668280959f);
						}

						if (g_Vars.currentplayernum == 0) {
							if (g_Vars.speedpillwant) {
								g_Vars.speedpillchange++;
							} else {
								g_Vars.speedpillchange--;
							}
						}

						if (g_Vars.speedpillchange > 30) {
							g_Vars.speedpillchange = 30;
						} else if (g_Vars.speedpillchange < 0) {
							g_Vars.speedpillchange = 0;
						}
					}

					if (g_Vars.speedpillchange > 15) {
						g_Vars.speedpillon = true;
					} else {
						g_Vars.speedpillon = false;
					}

					if (bluramount) {
						// empty
					}

					if (bluramount) {
						func0f148b6c();
						gdl = hudRenderMotionBlur(gdl, 0xffffffff, bluramount);
					}

					// Handle blur effect in cutscenes (Extraction intro?)
					if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
						f32 cutsceneblurfrac = cutsceneGetBlurFrac();

						if (cutsceneblurfrac > 0) {
							u32 bluramount = cutsceneblurfrac * 255;
							gdl = hudRenderMotionBlur(gdl, 0xffffff00, bluramount);
						}
					}

					if (debugGetMotionBlur() == 1) {
						gdl = hudRenderMotionBlur(gdl, 0xffffff00, 128);
					} else if (debugGetMotionBlur() == 2) {
						gdl = hudRenderMotionBlur(gdl, 0xffffff00, 192);
					} else if (debugGetMotionBlur() == 3) {
						gdl = hudRenderMotionBlur(gdl, 0xffffff00, 230);
					}

					if (bluramount) {
						// empty
					}

					// Render white when teleporting
					if (g_Vars.currentplayer->teleportstate > TELEPORTSTATE_INACTIVE) {
						alpha = 0;

						if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_WHITE) {
							alpha = 255;
						}

						if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_EXITING
								&& g_Vars.currentplayer->teleporttime < 16) {
							alpha = -g_Vars.currentplayer->teleporttime * 16 + 240;
						}

						if (g_Vars.currentplayer->teleportstate == TELEPORTSTATE_ENTERING) {
							if (g_Vars.currentplayer->teleporttime > 32) {
								alpha = g_Vars.currentplayer->teleporttime * 16 - 512;
							}

							if (g_Vars.currentplayer->teleporttime == 48) {
								alpha = 255;
							}
						}

						if (alpha) {
							gdl = func0f153628(gdl);
							gdl = func0f153a34(gdl,
									viGetViewLeft(), viGetViewTop(),
									viGetViewLeft() + viGetViewWidth(),
									viGetViewTop() + viGetViewHeight(), 0xffffff00 | alpha);
							gdl = func0f153780(gdl);
						}
					}
				}

				gdl = func0f185774(gdl);
				gdl = fadeRender(gdl);

				if (g_FrIsValidWeapon) {
					gdl = frRenderHud(gdl);
				}

				if (debug0f11ee88() == 0
						&& debug0f11ee90() == 0
						&& debug0f11eea8() == 0
						&& debug0f11ef80() == 0
						&& debug0f11ef78() == 0) {
					debug0f11ee40();
				}

				gdl = func0f1274d8(gdl);
				gdl = func0f100ad0(gdl);
				func00016748(1);

				if (g_Vars.currentplayer->unk1c50_01) {
					gdl = func0f0fbc30(gdl);
				}

				func00016748(g_Vars.currentplayerstats->scale_bg2gfx);

				if (g_Vars.mplayerisrunning) {
					gdl = func0f18973c(gdl);
				}

				if (g_Vars.currentplayer->dostartnewlife) {
					func0f0b72dc();
				}
			}

			func0f13c54c();

			if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
					&& func0f0bc4c0()
					&& g_Vars.currentplayernum != 0) {
				gdl = savedgdl;
			}
		} // end of player loop
	} // end of stage if-statements

	if (g_Vars.unk0004d3) {
		if (g_Vars.unk0004d6) {
			g_Vars.unk0004d3 = 0;
			g_Vars.unk0004d6 = 0;

			if (g_Vars.unk0004d7) {
				g_Vars.unk0004d4 = -1;
				g_Vars.unk0004d5 = 0;
			}

			if (g_Vars.unk0004d4 < 0 && g_Vars.unk0004d5 <= 0) {
				mainSetStageNum(STAGE_TITLE);
			}
		}
	}

	// Advance the cutscenes when autoplaying
	if (g_Vars.unk0004d3 == 0 && g_Vars.unk0004d4 >= 0 && g_Vars.unk0004d5 > 0) {
		hudmsgRemoveAll();
		g_Vars.unk0004d2 = g_Cutscenes[g_Vars.unk0004d4].scene;
		g_MissionConfig.iscoop = false;
		g_Vars.mplayerisrunning = false;
		g_Vars.normmplayerisrunning = false;
		g_Vars.bondplayernum = 0;
		g_Vars.coopplayernum = -1;
		g_Vars.antiplayernum = -1;
		g_MissionConfig.isanti = false;
		setNumPlayers(1);
		titleSetNextMode(TITLEMODE_SKIP);
		g_MissionConfig.difficulty = DIFF_A;
		setDifficulty(DIFF_A);
		g_MissionConfig.stageindex = g_Cutscenes[g_Vars.unk0004d4].mission;
		g_MissionConfig.stagenum = g_Cutscenes[g_Vars.unk0004d4].stage;
		titleSetNextStage(g_Cutscenes[g_Vars.unk0004d4].stage);
		mainSetStageNum(g_Cutscenes[g_Vars.unk0004d4].stage);

		g_Vars.unk0004d5--;

		if (g_Vars.unk0004d5 > 0) {
			g_Vars.unk0004d4++;
		} else {
			g_Vars.unk0004d4 = -1;
		}
	}

	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, viGetX(), viGetY());

	return gdl;
}

u32 g_CutsceneTime240_60 = 0;
u32 var800840a8 = 0x00000000;
u32 var800840ac = 0x00000000;
u32 var800840b0 = 0x00000000;
u32 var800840b4 = 0x00000000;
u32 var800840b8 = 0x00000000;
u32 var800840bc = 0x00000000;

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
/*  f16b50c:	0fc30869 */ 	jal	currentPlayerGetShieldFrac
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
		g_Vars.players[j]->hands[HAND_LEFT].unk0cec = 0;
		g_Vars.players[j]->hands[HAND_RIGHT].unk0cec = 0;
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

	speedpillTick();
	func0f0df364();

	if ((contGetButtonsPressedThisFrame(0, 0xffff) != 0
				|| contGetStickX(0) > 10
				|| contGetStickX(0) < -10
				|| contGetStickY(0) > 10
				|| contGetStickY(0) < -10
				|| contGetButtonsPressedThisFrame(1, 0xffff) != 0
				|| contGetStickX(1) > 10
				|| contGetStickX(1) < -10
				|| contGetStickY(1) > 10
				|| contGetStickY(1) < -10
				|| contGetButtonsPressedThisFrame(2, 0xffff) != 0
				|| contGetStickX(2) > 10
				|| contGetStickX(2) < -10
				|| contGetStickY(2) > 10
				|| contGetStickY(2) < -10
				|| contGetButtonsPressedThisFrame(3, 0xffff) != 0
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
		pakExecuteDebugOperations();
	} else if (g_Vars.stagenum == STAGE_4MBMENU) {
		menuTickAll();
		func00011d84();
		func0f01d860();
		pakExecuteDebugOperations();
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
		pakExecuteDebugOperations();
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

	if (g_MiscAudioHandle && audioIsPlaying(g_MiscAudioHandle)) {
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
