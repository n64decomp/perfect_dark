#include <ultra64.h>
#include "constants.h"
#include "game/activemenu/activemenu.h"
#include "game/activemenu/tick.h"
#include "game/bondmove.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/chr/chraction.h"
#include "game/debug.h"
#include "game/dlights.h"
#include "game/game_005fd0.h"
#include "game/nbomb.h"
#include "game/game_00b480.h"
#include "game/game_00b820.h"
#include "game/game_00c240.h"
#include "game/game_00c490.h"
#include "game/game_0108d0.h"
#include "game/objectives.h"
#include "game/casing.h"
#include "game/game_011110.h"
#include "game/inventory/init.h"
#include "game/game_0125a0.h"
#include "game/explosions/init.h"
#include "game/smoke/init.h"
#include "game/sparks/init.h"
#include "game/weather/init.h"
#include "game/stubs/game_013540.h"
#include "game/game_013550.h"
#include "game/game_013cf0.h"
#include "game/game_0147a0.h"
#include "game/game_0147d0.h"
#include "game/game_014f10.h"
#include "game/game_015010.h"
#include "game/game_0150a0.h"
#include "game/stubs/game_015260.h"
#include "game/stubs/game_015270.h"
#include "game/explosions/reset.h"
#include "game/smoke/reset.h"
#include "game/stubs/game_0153f0.h"
#include "game/stubs/game_015400.h"
#include "game/stubs/game_015410.h"
#include "game/shards.h"
#include "game/game_015470.h"
#include "game/title.h"
#include "game/game_01b0a0.h"
#include "game/game_01bea0.h"
#include "game/weather/tick.h"
#include "game/game_01d860.h"
#include "game/game_01d990.h"
#include "game/chr/chr.h"
#include "game/prop.h"
#include "game/game_095320.h"
#include "game/game_097ba0.h"
#include "game/game_0abe70.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b28d0.h"
#include "game/game_0b63b0.h"
#include "game/game_0b69d0.h"
#include "game/game_0d4690.h"
#include "game/hudmsg.h"
#include "game/game_0f09f0.h"
#include "game/game_107fb0.h"
#include "game/game_10c9c0.h"
#include "game/game_11f000.h"
#include "game/game_127910.h"
#include "game/game_129210.h"
#include "game/explosions/explosions.h"
#include "game/sparks/sparks.h"
#include "game/weather/weather.h"
#include "game/sky.h"
#include "game/credits.h"
#include "game/game_13c510.h"
#include "game/bondview.h"
#include "game/game_1531a0.h"
#include "game/room.h"
#include "game/game_165670.h"
#include "game/core.h"
#include "game/music.h"
#include "game/texture.h"
#include "game/game_176080.h"
#include "game/mplayer/setup.h"
#include "game/mplayer/scenarios.h"
#include "game/game_19aa80.h"
#include "game/training/training.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pak/pak.h"
#include "game/propobj.h"
#include "game/sparks/tick.h"
#include "game/splat.h"
#include "game/utils.h"
#include "game/wallhit.h"
#include "gvars/gvars.h"
#include "lib/args.h"
#include "lib/controller.h"
#include "lib/lib_06440.h"
#include "lib/lib_09660.h"
#include "lib/main.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_11420.h"
#include "lib/rng.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

const char var7f1b7730[] = "fr: %d\n";
const char var7f1b7738[] = "cutsceneframe: %d\n";
const char var7f1b774c[] = "pos:%s%s %.2f %.2f %.2f\n";
const char var7f1b7768[] = "";
const char var7f1b776c[] = "";

struct audiohandle *g_MiscSfxAudioHandles[3];
u32 var800aa5bc;
s32 g_MiscSfxActiveTypes[3];

u32 var80084010 = 0;
bool var80084014 = false;
f32 var80084018 = 1;
u32 var8008401c = 0x00000001;

s32 g_Difficulty = DIFF_A;

s32 g_StageTimeElapsed60 = 0;
s32 g_MpTimeLimit60 = SECSTOTIME60(60 * 10); // 10 minutes
s32 g_MpScoreLimit = 10;
s32 g_MpTeamScoreLimit = 20;
struct audiohandle *g_MiscAudioHandle = NULL;
s32 g_NumReasonsToEndMpMatch = 0;
f32 g_StageTimeElapsed1f = 0;
bool var80084040 = true;

u32 g_MiscSfxSounds[] = {
	SFX_HEARTBEAT,
	SFX_SLAYER_WHIR,
	SFX_SLAYER_BEEP,
};

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
	g_Vars.lockscreen = 0;
	g_Vars.unk0004d8 = -1;
}

void coreStopAllMiscSfx(void)
{
	s32 i;

	for (i = 0; i != ARRAYCOUNT(g_MiscSfxAudioHandles); i++) {
		g_MiscSfxAudioHandles[i] = NULL;
		g_MiscSfxActiveTypes[i] = -1;
	}
}

s32 coreGetMiscSfxIndex(u32 type)
{
	s32 i;

	for (i = 0; i != ARRAYCOUNT(g_MiscSfxActiveTypes); i++) {
		if (g_MiscSfxActiveTypes[i] == type) {
			return i;
		}
	}

	return -1;
}

void coreSetMiscSfxState(u32 type, bool play)
{
	if (play) {
		if (coreGetMiscSfxIndex(type) == -1) {
			s32 index = coreGetMiscSfxIndex(-1);

			if (index != -1 && g_MiscSfxAudioHandles[index] == NULL) {
				audioStart(var80095200, g_MiscSfxSounds[type], &g_MiscSfxAudioHandles[index], -1, -1, -1, -1, -1);
				g_MiscSfxActiveTypes[index] = type;
			}
		}
	} else {
		u32 stack;
		s32 index = coreGetMiscSfxIndex(type);

		if (index != -1) {
			audioStop(g_MiscSfxAudioHandles[index]);
			g_MiscSfxActiveTypes[index] = -1;
		}
	}
}

void coreUpdateMiscSfx(void)
{
	s32 i;

	if (g_Vars.lvupdate240 == 0) {
		for (i = 0; i != ARRAYCOUNT(g_MiscSfxActiveTypes); i++) {
			coreSetMiscSfxState(i, false);
		}
	} else {
		bool usingboost = g_Vars.speedpillon
			&& coreGetSlowMotionType() == SLOWMOTION_OFF
			&& g_Vars.in_cutscene == false;
		bool usingrocket;

		coreSetMiscSfxState(MISCSFX_BOOSTHEARTBEAT, usingboost);

		usingrocket = false;

		for (i = 0; i < PLAYERCOUNT(); i++) {
			if (g_Vars.players[i]->visionmode == VISIONMODE_SLAYERROCKET) {
				usingrocket = true;
			}
		}

		coreSetMiscSfxState(MISCSFX_SLAYERROCKETHUM, usingrocket);
		coreSetMiscSfxState(MISCSFX_SLAYERROCKETBEEP, usingrocket);
	}

	if (g_Vars.lvupdate240 == 0 && g_MiscAudioHandle && audioIsPlaying(g_MiscAudioHandle)) {
		audioStop(g_MiscAudioHandle);
	}
}

void coreLoadStage(s32 stagenum)
{
	coreCancelFade();

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
	g_Vars.lvupdate240frealprev = FRAMESTOTIME60(1.0f);
	g_Vars.lvupdate240freal = g_Vars.lvupdate240frealprev;

	g_StageTimeElapsed60 = 0;
	g_StageTimeElapsed1f = 0;

	g_Vars.speedpilltime = 0;
	g_Vars.speedpillchange = 0;
	g_Vars.speedpillwant = 0;
	g_Vars.speedpillon = false;

	g_Vars.restartlevel = false;
	g_Vars.unk000478 = 0;
	g_Vars.totalkills = 0;
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
	hudmsgsInit();

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
		bgInit(g_Vars.stagenum);
		bgBuildTables(g_Vars.stagenum);
		func0f0147a0(g_Vars.stagenum);

		if (g_Vars.normmplayerisrunning) {
			musicSetStageAndStartMusic(stagenum);
		} else {
			musicSetStage(stagenum);
		}

		if (g_Vars.normmplayerisrunning) {
			mpApplyLimits();
		}

		if (g_Vars.mplayerisrunning == false) {
			g_Vars.playerstats[0].mpindex = 4;
			g_MpPlayers[4].base.contpad1 = 0;
			g_MpPlayers[4].base.contpad2 = 1;
		}

		for (i = 0; i != ARRAYCOUNT(g_Vars.playerstats); i++) {
			g_Vars.playerstats[i].damagescale = 1;
			g_Vars.playerstats[i].drawplayercount = 0;
			g_Vars.playerstats[i].distance = 0;
			g_Vars.playerstats[i].backshotcount = 0;
			g_Vars.playerstats[i].armourcount = 0;
			g_Vars.playerstats[i].fastest2kills = S32_MAX;
			g_Vars.playerstats[i].slowest2kills = 0;
			g_Vars.playerstats[i].maxkills = 0;
			g_Vars.playerstats[i].maxsimulkills = 0;
			g_Vars.playerstats[i].longestlife = 0;
			g_Vars.playerstats[i].shortestlife = S32_MAX;
			g_Vars.playerstats[i].tokenheldtime = 0;
			g_Vars.playerstats[i].damreceived = 0;
			g_Vars.playerstats[i].damtransmitted = 0;

			for (j = 0; j != ARRAYCOUNT(g_Vars.playerstats[i].kills); j++) {
				g_Vars.playerstats[i].kills[j] = 0;
			}
		}
	}

	mpSetDefaultNamesIfEmpty();
	func0002373c();
	objectivesReset();
	func0f013ba0();
	func0f011110();
	func0f0108d0();
	setupLoadFiles(stagenum);
	mpPrepareScenario();
	gvarsInitProps();
	setupInit();
	func0f00b510();
	stageChooseActiveHeads(stagenum);
	setupParseObjects(stagenum);
	tagsAllocatePtrs();
	explosionsInit();
	smokeInit();
	sparksInit();
	weatherInit();
	coreStopAllMiscSfx();

	switch (g_Vars.stagenum) {
	case STAGE_ESCAPE:
	case STAGE_EXTRACTION:
	case STAGE_INFILTRATION:
	case STAGE_DEFECTION:
	case STAGE_ATTACKSHIP:
	case STAGE_TEST_OLD:
		skyInit();
		break;
	}

	func0f0099a4();
	func0f0147d0();
	lasersightsReset();
	stub0f013540();
	shardsInit();
	frUnloadData();

	if (g_Vars.stagenum == STAGE_TITLE) {
		// empty
	} else if (stagenum == STAGE_BOOTPAKMENU) {
		setCurrentPlayerNum(0);
		menuInit();
	} else if (stagenum == STAGE_4MBMENU) {
		setCurrentPlayerNum(0);
		menuInit();
	} else if (stagenum == STAGE_CREDITS) {
		creditsInit();
	} else {
		s32 i;

		func0f1777f8();
		casingsReset();

		for (i = 0; i < PLAYERCOUNT(); i++) {
			setCurrentPlayerNum(i);
			g_Vars.currentplayer->usedowntime = 0;
			g_Vars.currentplayer->invdowntime = g_Vars.currentplayer->usedowntime;

			menuInit();
			amInit();
			invInitGunsHeld();
			func0f010bb0();
			currentPlayerResetToDefault();
			currentPlayerInit();
			currentPlayerSpawn();
			currentPlayerInitAnimation();

			if (g_Vars.normmplayerisrunning && (g_MpSetup.options & MPOPTION_TEAMSENABLED)) {
				currentPlayerCalculateAiBuddyNums();
			}
		}

		acousticReset();
		func0f0b65f8();
		func0f001bdc();
		setCurrentPlayerNum(0);
	}

	if (g_Vars.lvmpbotlevel) {
		mpCalculateTeamIsOnlyAi();
	}

	func0f11a2e4();
	func0000eadc();

	if (stagenum == STAGE_BOOTPAKMENU) {
		pakPushPakMenuDialog();
	}

	if (stagenum == STAGE_4MBMENU) {
		func0f10cb2c();
	}

	if (IS8MB()) {
		func0f14a3c4();
	}

	func0f011124(false);
	var80084018 = 1;
	bbufResetIndexes();
	coreSetPaused(0);

#if PIRACYCHECKS
	{
		u32 checksum = 0;
		s32 *i = (s32 *)&coreGetSlowMotionType;
		s32 *end = (s32 *)&coreTick;

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

void coreConfigureFade(u32 color, s16 num_frames)
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

Gfx *coreRenderFade(Gfx *gdl)
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

bool coreIsFadeActive(void)
{
	return g_FadeFrac >= 0;
}

void coreCancelFade(void)
{
	g_FadeNumFrames = 0;
	g_FadeFrac = -1;
	g_FadePrevColour = 0;
	g_FadeColour = 0;
	g_FadeDelay = 0;
}

bool coreCheckCmpFollowThreat(struct threat *threat, s32 index)
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
					if (g_Vars.currentplayer->targetset[index] < 129) {
						g_Vars.currentplayer->targetset[index] = 129;
					}

					if (g_Vars.currentplayer->targetset[index] >= 175) {
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
		case PROPTYPE_SMOKE:
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

void coreFindThreatsForProp(struct prop *prop, bool inchild, struct coord *playerpos, bool *activeslots, f32 *distances)
{
	bool condition = true;
	struct defaultobj *obj;
	bool pass;
	f32 sp88;
	f32 sp84;
	f32 sp80;
	f32 sp76;
	s32 i;
	struct model *model;
	struct weaponobj *weapon;

	if (!inchild && prop->z < 0) {
		condition = false;
	}

	if (prop->obj
			&& (prop->flags & PROPFLAG_02)
			&& (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON)
			&& condition) {
		pass = false;
		obj = prop->obj;
		model = prop->obj->model;

		if (obj
				&& obj->type == OBJTYPE_AUTOGUN
				&& (obj->flags2 & (OBJFLAG2_80000000 | OBJFLAG2_AICANNOTUSE)) == 0) {
			pass = true;
		}

		if (obj && obj->modelnum == MODEL_SK_SHUTTLE) {
			pass = true;
		}

		weapon = (struct weaponobj *)prop->obj;

		if (weapon && prop->obj->type == OBJTYPE_WEAPON) {
			switch (weapon->weaponnum) {
			case WEAPON_GRENADE:
			case WEAPON_NBOMB:
			case WEAPON_TIMEDMINE:
			case WEAPON_PROXIMITYMINE:
			case WEAPON_REMOTEMINE:
				pass = true;
				break;
			case WEAPON_DRAGON:
				if (weapon->gunfunc == (u32)FUNC_SECONDARY) {
					pass = true;
				}
				break;
			}
		}

		if (obj->modelnum == MODEL_TARGET && frIsTargetOneHitExplodable(prop)) {
			pass = true;
		}

		if (pass) {
			for (i = 0; i != 4; i++) {
				if (g_Vars.currentplayer->cmpfollowprops[i].prop == prop) {
					pass = false;
				}
			}
		}

		if (pass) {
			sp84 = -1;
			sp88 = -1;
			sp76 = -2;
			sp80 = -2;

			if (!modelSetRedBox(model, &sp76, &sp84, &sp80, &sp88)) {
				pass = false;
			}
		}

		if (pass) {
			f32 furtherestdist = 0;
			s32 index = -1;

			f32 sqdist =
				(prop->pos.f[0] - playerpos->f[0]) * (prop->pos.f[0] - playerpos->f[0]) +
				(prop->pos.f[1] - playerpos->f[1]) * (prop->pos.f[1] - playerpos->f[1]) +
				(prop->pos.f[2] - playerpos->f[2]) * (prop->pos.f[2] - playerpos->f[2]);

			for (i = 0; i < 4; i++) {
				if (!activeslots[i]) {
					index = i;
				}
			}

			if (index == -1) {
				// No slots available - consider replacing the furtherest
				for (i = 0; i != 4; i++) {
					if (distances[i] > furtherestdist) {
						furtherestdist = distances[i];
						index = i;
					}
				}

				if (sqdist >= furtherestdist) {
					index = -1;
				}
			}

			if (index >= 0) {
				g_Vars.currentplayer->cmpfollowprops[index].prop = prop;
				g_Vars.currentplayer->cmpfollowprops[index].unk04 = sp84 - 2;
				g_Vars.currentplayer->cmpfollowprops[index].unk08 = sp76 + 2;
				g_Vars.currentplayer->cmpfollowprops[index].unk06 = sp88 - 2;
				g_Vars.currentplayer->cmpfollowprops[index].unk0a = sp80 + 2;
				g_Vars.currentplayer->targetset[index] = 0;
				activeslots[index] = true;
				distances[index] = sqdist;
			}
		}
	}

	if (prop->child) {
		coreFindThreatsForProp(prop->child, true, playerpos, activeslots, distances);
	}

	if (inchild && prop->next) {
		coreFindThreatsForProp(prop->next, inchild, playerpos, activeslots, distances);
	}
}

void func0f168f24(struct prop *prop, bool inchild, struct coord *playerpos, s32 *activeslots, f32 *distances)
{
	s32 i;
	f32 sp128;
	f32 sp124;
	f32 sp120;
	f32 sp116;
	struct model *model;

	for (i = 0; i != 4; i++) {
		if (g_Vars.currentplayer->cmpfollowprops[i].prop == prop
				&& (prop->flags & PROPFLAG_02)) {
			model = NULL;

			if (prop->type == PROPTYPE_OBJ
					|| prop->type == PROPTYPE_WEAPON
					|| prop->type == PROPTYPE_DOOR) {
				model = g_Vars.currentplayer->cmpfollowprops[i].prop->obj->model;
			} else {
				if (prop->type == PROPTYPE_CHR
						|| (prop->type == PROPTYPE_PLAYER
							&& propGetPlayerNum(prop) != g_Vars.currentplayernum)) {
					model = g_Vars.currentplayer->cmpfollowprops[i].prop->chr->model;
				}
			}

			if (model) {
				sp124 = -1;
				sp128 = -1;
				sp116 = -2;
				sp120 = -2;

				if (modelSetRedBox(model, &sp116, &sp124, &sp120, &sp128)) {
					activeslots[i] = true;
					g_Vars.currentplayer->cmpfollowprops[i].unk04 = sp124 - 2;
					g_Vars.currentplayer->cmpfollowprops[i].unk08 = sp116 + 2;
					g_Vars.currentplayer->cmpfollowprops[i].unk06 = sp128 - 2;
					g_Vars.currentplayer->cmpfollowprops[i].unk0a = sp120 + 2;

					distances[i] =
						(prop->pos.f[0] - playerpos->f[0]) * (prop->pos.f[0] - playerpos->f[0]) +
						(prop->pos.f[1] - playerpos->f[1]) * (prop->pos.f[1] - playerpos->f[1]) +
						(prop->pos.f[2] - playerpos->f[2]) * (prop->pos.f[2] - playerpos->f[2]);
				}
			}
		}
	}

	if (prop->child) {
		func0f168f24(prop->child, true, playerpos, activeslots, distances);
	}

	if (inchild && prop->next) {
		func0f168f24(prop->next, inchild, playerpos, activeslots, distances);
	}
}

void coreFindThreats(void)
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

	for (i = 0; i != ARRAYCOUNT(activeslots); i++) {
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
			coreFindThreatsForProp(prop, false, &campos, activeslots, distances);
		}

		propptr--;
	}
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel coreRender
/*  f16a2f8:	27bdfe90 */ 	addiu	$sp,$sp,-368
/*  f16a2fc:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f16a300:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f16a304:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f16a308:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f16a30c:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f16a310:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f16a314:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f16a318:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f16a31c:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f16a320:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f16a324:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f16a328:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f16a32c:	35ce0006 */ 	ori	$t6,$t6,0x6
/*  f16a330:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f16a334:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f16a338:	0fc35807 */ 	jal	0xf0d601c
/*  f16a33c:	24930008 */ 	addiu	$s3,$a0,0x8
/*  f16a340:	3c12800a */ 	lui	$s2,0x800a
/*  f16a344:	2652a510 */ 	addiu	$s2,$s2,-23280
/*  f16a348:	8e4204b4 */ 	lw	$v0,0x4b4($s2)
/*  f16a34c:	2401005a */ 	li	$at,0x5a
/*  f16a350:	10410006 */ 	beq	$v0,$at,.PF0f16a36c
/*  f16a354:	2401004e */ 	li	$at,0x4e
/*  f16a358:	5441005f */ 	bnel	$v0,$at,.PF0f16a4d8
/*  f16a35c:	8e4204b4 */ 	lw	$v0,0x4b4($s2)
/*  f16a360:	0fc06b27 */ 	jal	0xf01ac9c
/*  f16a364:	00000000 */ 	nop
/*  f16a368:	1040005a */ 	beqz	$v0,.PF0f16a4d4
.PF0f16a36c:
/*  f16a36c:	02601025 */ 	move	$v0,$s3
/*  f16a370:	3c188006 */ 	lui	$t8,0x8006
/*  f16a374:	27181070 */ 	addiu	$t8,$t8,0x1070
/*  f16a378:	3c0f0600 */ 	lui	$t7,0x600
/*  f16a37c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f16a380:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f16a384:	0fc47e4a */ 	jal	0xf11f928
/*  f16a388:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a38c:	10400008 */ 	beqz	$v0,.PF0f16a3b0
/*  f16a390:	02601025 */ 	move	$v0,$s3
/*  f16a394:	3c0a8006 */ 	lui	$t2,0x8006
/*  f16a398:	254a1030 */ 	addiu	$t2,$t2,0x1030
/*  f16a39c:	3c190600 */ 	lui	$t9,0x600
/*  f16a3a0:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f16a3a4:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f16a3a8:	10000008 */ 	b	.PF0f16a3cc
/*  f16a3ac:	26730008 */ 	addiu	$s3,$s3,0x8
.PF0f16a3b0:
/*  f16a3b0:	02601025 */ 	move	$v0,$s3
/*  f16a3b4:	3c0c8006 */ 	lui	$t4,0x8006
/*  f16a3b8:	258c1050 */ 	addiu	$t4,$t4,0x1050
/*  f16a3bc:	3c0b0600 */ 	lui	$t3,0x600
/*  f16a3c0:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f16a3c4:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f16a3c8:	26730008 */ 	addiu	$s3,$s3,0x8
.PF0f16a3cc:
/*  f16a3cc:	0c002bf1 */ 	jal	0xafc4
/*  f16a3d0:	02602025 */ 	move	$a0,$s3
/*  f16a3d4:	0c002bc5 */ 	jal	0xaf14
/*  f16a3d8:	00402025 */ 	move	$a0,$v0
/*  f16a3dc:	00408825 */ 	move	$s1,$v0
/*  f16a3e0:	0c002e91 */ 	jal	0xba44
/*  f16a3e4:	24530008 */ 	addiu	$s3,$v0,0x8
/*  f16a3e8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f16a3ec:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f16a3f0:	0c002e95 */ 	jal	0xba54
/*  f16a3f4:	01a08025 */ 	move	$s0,$t5
/*  f16a3f8:	44822000 */ 	mtc1	$v0,$f4
/*  f16a3fc:	44908000 */ 	mtc1	$s0,$f16
/*  f16a400:	3c014080 */ 	lui	$at,0x4080
/*  f16a404:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f16a408:	4481a000 */ 	mtc1	$at,$f20
/*  f16a40c:	3c01ed00 */ 	lui	$at,0xed00
/*  f16a410:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f16a414:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f16a418:	00000000 */ 	nop
/*  f16a41c:	46149102 */ 	mul.s	$f4,$f18,$f20
/*  f16a420:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f16a424:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f16a428:	440f5000 */ 	mfc1	$t7,$f10
/*  f16a42c:	440b3000 */ 	mfc1	$t3,$f6
/*  f16a430:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f16a434:	0301c825 */ 	or	$t9,$t8,$at
/*  f16a438:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f16a43c:	000c6b00 */ 	sll	$t5,$t4,0xc
/*  f16a440:	032d7025 */ 	or	$t6,$t9,$t5
/*  f16a444:	0c002e73 */ 	jal	0xb9cc
/*  f16a448:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f16a44c:	0c002e91 */ 	jal	0xba44
/*  f16a450:	a7a2008e */ 	sh	$v0,0x8e($sp)
/*  f16a454:	0c002e95 */ 	jal	0xba54
/*  f16a458:	a7a20090 */ 	sh	$v0,0x90($sp)
/*  f16a45c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f16a460:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f16a464:	0c002e77 */ 	jal	0xb9dc
/*  f16a468:	01e08025 */ 	move	$s0,$t7
/*  f16a46c:	87b80090 */ 	lh	$t8,0x90($sp)
/*  f16a470:	87aa008e */ 	lh	$t2,0x8e($sp)
/*  f16a474:	00507821 */ 	addu	$t7,$v0,$s0
/*  f16a478:	448f2000 */ 	mtc1	$t7,$f4
/*  f16a47c:	030a5821 */ 	addu	$t3,$t8,$t2
/*  f16a480:	448b4000 */ 	mtc1	$t3,$f8
/*  f16a484:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f16a488:	02602025 */ 	move	$a0,$s3
/*  f16a48c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f16a490:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f16a494:	00000000 */ 	nop
/*  f16a498:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f16a49c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f16a4a0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f16a4a4:	44199000 */ 	mfc1	$t9,$f18
/*  f16a4a8:	440a5000 */ 	mfc1	$t2,$f10
/*  f16a4ac:	332d0fff */ 	andi	$t5,$t9,0xfff
/*  f16a4b0:	000d7300 */ 	sll	$t6,$t5,0xc
/*  f16a4b4:	314b0fff */ 	andi	$t3,$t2,0xfff
/*  f16a4b8:	016e6025 */ 	or	$t4,$t3,$t6
/*  f16a4bc:	0fc06bf9 */ 	jal	0xf01afe4
/*  f16a4c0:	ae2c0004 */ 	sw	$t4,0x4($s1)
/*  f16a4c4:	0fc5a557 */ 	jal	0xf16955c
/*  f16a4c8:	00402025 */ 	move	$a0,$v0
/*  f16a4cc:	100005e8 */ 	b	.PF0f16bc70
/*  f16a4d0:	00409825 */ 	move	$s3,$v0
.PF0f16a4d4:
/*  f16a4d4:	8e4204b4 */ 	lw	$v0,0x4b4($s2)
.PF0f16a4d8:
/*  f16a4d8:	2401005b */ 	li	$at,0x5b
/*  f16a4dc:	24070002 */ 	li	$a3,0x2
/*  f16a4e0:	14410040 */ 	bne	$v0,$at,.PF0f16a5e4
/*  f16a4e4:	3408fffe */ 	li	$t0,0xfffe
/*  f16a4e8:	02601025 */ 	move	$v0,$s3
/*  f16a4ec:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a4f0:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f16a4f4:	37390404 */ 	ori	$t9,$t9,0x404
/*  f16a4f8:	02601825 */ 	move	$v1,$s3
/*  f16a4fc:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a500:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f16a504:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f16a508:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f16a50c:	35ad0c04 */ 	ori	$t5,$t5,0xc04
/*  f16a510:	02602025 */ 	move	$a0,$s3
/*  f16a514:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f16a518:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f16a51c:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f16a520:	35ef1404 */ 	ori	$t7,$t7,0x1404
/*  f16a524:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a528:	02602825 */ 	move	$a1,$s3
/*  f16a52c:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f16a530:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f16a534:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a538:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f16a53c:	37181c04 */ 	ori	$t8,$t8,0x1c04
/*  f16a540:	02603025 */ 	move	$a2,$s3
/*  f16a544:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f16a548:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f16a54c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a550:	3c0a8006 */ 	lui	$t2,0x8006
/*  f16a554:	3c090600 */ 	lui	$t1,0x600
/*  f16a558:	254a1070 */ 	addiu	$t2,$t2,0x1070
/*  f16a55c:	02601025 */ 	move	$v0,$s3
/*  f16a560:	3c0b8006 */ 	lui	$t3,0x8006
/*  f16a564:	acca0004 */ 	sw	$t2,0x4($a2)
/*  f16a568:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f16a56c:	256b1050 */ 	addiu	$t3,$t3,0x1050
/*  f16a570:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f16a574:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f16a578:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a57c:	0fc4a4ff */ 	jal	0xf1293fc
/*  f16a580:	00002025 */ 	move	$a0,$zero
/*  f16a584:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a588:	86040634 */ 	lh	$a0,0x634($s0)
/*  f16a58c:	0c002e7b */ 	jal	0xb9ec
/*  f16a590:	86050636 */ 	lh	$a1,0x636($s0)
/*  f16a594:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a598:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f16a59c:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f16a5a0:	86060630 */ 	lh	$a2,0x630($s0)
/*  f16a5a4:	0c002ec7 */ 	jal	0xbb1c
/*  f16a5a8:	86070632 */ 	lh	$a3,0x632($s0)
/*  f16a5ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f16a5b0:	44816000 */ 	mtc1	$at,$f12
/*  f16a5b4:	0c005936 */ 	jal	0x164d8
/*  f16a5b8:	00000000 */ 	nop
/*  f16a5bc:	0c002bc5 */ 	jal	0xaf14
/*  f16a5c0:	02602025 */ 	move	$a0,$s3
/*  f16a5c4:	0c002c1d */ 	jal	0xb074
/*  f16a5c8:	00402025 */ 	move	$a0,$v0
/*  f16a5cc:	0fc576bd */ 	jal	0xf15daf4
/*  f16a5d0:	00402025 */ 	move	$a0,$v0
/*  f16a5d4:	0fc3f0f0 */ 	jal	0xf0fc3c0
/*  f16a5d8:	00402025 */ 	move	$a0,$v0
/*  f16a5dc:	100005a4 */ 	b	.PF0f16bc70
/*  f16a5e0:	00409825 */ 	move	$s3,$v0
.PF0f16a5e4:
/*  f16a5e4:	2401005d */ 	li	$at,0x5d
/*  f16a5e8:	14410063 */ 	bne	$v0,$at,.PF0f16a778
/*  f16a5ec:	24070002 */ 	li	$a3,0x2
/*  f16a5f0:	02601025 */ 	move	$v0,$s3
/*  f16a5f4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a5f8:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f16a5fc:	35ce0404 */ 	ori	$t6,$t6,0x404
/*  f16a600:	02601825 */ 	move	$v1,$s3
/*  f16a604:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a608:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f16a60c:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f16a610:	3c0cbc00 */ 	lui	$t4,0xbc00
/*  f16a614:	358c0c04 */ 	ori	$t4,$t4,0xc04
/*  f16a618:	02602025 */ 	move	$a0,$s3
/*  f16a61c:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f16a620:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f16a624:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f16a628:	3408fffe */ 	li	$t0,0xfffe
/*  f16a62c:	37391404 */ 	ori	$t9,$t9,0x1404
/*  f16a630:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a634:	02602825 */ 	move	$a1,$s3
/*  f16a638:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f16a63c:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f16a640:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a644:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f16a648:	35ad1c04 */ 	ori	$t5,$t5,0x1c04
/*  f16a64c:	02603025 */ 	move	$a2,$s3
/*  f16a650:	acad0000 */ 	sw	$t5,0x0($a1)
/*  f16a654:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f16a658:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a65c:	3c0f8006 */ 	lui	$t7,0x8006
/*  f16a660:	3c090600 */ 	lui	$t1,0x600
/*  f16a664:	25ef1070 */ 	addiu	$t7,$t7,0x1070
/*  f16a668:	02601025 */ 	move	$v0,$s3
/*  f16a66c:	3c188006 */ 	lui	$t8,0x8006
/*  f16a670:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f16a674:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f16a678:	27181050 */ 	addiu	$t8,$t8,0x1050
/*  f16a67c:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f16a680:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f16a684:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a688:	0fc4a4ff */ 	jal	0xf1293fc
/*  f16a68c:	00002025 */ 	move	$a0,$zero
/*  f16a690:	0c0029fd */ 	jal	0xa7f4
/*  f16a694:	24040001 */ 	li	$a0,0x1
/*  f16a698:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a69c:	86040634 */ 	lh	$a0,0x634($s0)
/*  f16a6a0:	0c002e7b */ 	jal	0xb9ec
/*  f16a6a4:	86050636 */ 	lh	$a1,0x636($s0)
/*  f16a6a8:	0fc2f272 */ 	jal	0xf0bc9c8
/*  f16a6ac:	00000000 */ 	nop
/*  f16a6b0:	0fc2f27d */ 	jal	0xf0bc9f4
/*  f16a6b4:	a7a20090 */ 	sh	$v0,0x90($sp)
/*  f16a6b8:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f16a6bc:	00055403 */ 	sra	$t2,$a1,0x10
/*  f16a6c0:	01402825 */ 	move	$a1,$t2
/*  f16a6c4:	0c002e4a */ 	jal	0xb928
/*  f16a6c8:	87a40090 */ 	lh	$a0,0x90($sp)
/*  f16a6cc:	0fc2f272 */ 	jal	0xf0bc9c8
/*  f16a6d0:	00000000 */ 	nop
/*  f16a6d4:	0fc2f27d */ 	jal	0xf0bc9f4
/*  f16a6d8:	a7a20090 */ 	sh	$v0,0x90($sp)
/*  f16a6dc:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f16a6e0:	00055c03 */ 	sra	$t3,$a1,0x10
/*  f16a6e4:	01602825 */ 	move	$a1,$t3
/*  f16a6e8:	0c002e39 */ 	jal	0xb8e4
/*  f16a6ec:	87a40090 */ 	lh	$a0,0x90($sp)
/*  f16a6f0:	0fc2f272 */ 	jal	0xf0bc9c8
/*  f16a6f4:	00000000 */ 	nop
/*  f16a6f8:	0fc2f27d */ 	jal	0xf0bc9f4
/*  f16a6fc:	a7a20090 */ 	sh	$v0,0x90($sp)
/*  f16a700:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f16a704:	00057403 */ 	sra	$t6,$a1,0x10
/*  f16a708:	01c02825 */ 	move	$a1,$t6
/*  f16a70c:	0c002e5b */ 	jal	0xb96c
/*  f16a710:	87a40090 */ 	lh	$a0,0x90($sp)
/*  f16a714:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a718:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f16a71c:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f16a720:	86060630 */ 	lh	$a2,0x630($s0)
/*  f16a724:	0c002ec7 */ 	jal	0xbb1c
/*  f16a728:	86070632 */ 	lh	$a3,0x632($s0)
/*  f16a72c:	3c013f80 */ 	lui	$at,0x3f80
/*  f16a730:	44816000 */ 	mtc1	$at,$f12
/*  f16a734:	0c005936 */ 	jal	0x164d8
/*  f16a738:	00000000 */ 	nop
/*  f16a73c:	0c002bc5 */ 	jal	0xaf14
/*  f16a740:	02602025 */ 	move	$a0,$s3
/*  f16a744:	0fc576bd */ 	jal	0xf15daf4
/*  f16a748:	00402025 */ 	move	$a0,$v0
/*  f16a74c:	0fc3f0f0 */ 	jal	0xf0fc3c0
/*  f16a750:	00402025 */ 	move	$a0,$v0
/*  f16a754:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f16a758:	00409825 */ 	move	$s3,$v0
/*  f16a75c:	8d991a24 */ 	lw	$t9,0x1a24($t4)
/*  f16a760:	53200544 */ 	beqzl	$t9,.PF0f16bc74
/*  f16a764:	824b04d3 */ 	lb	$t3,0x4d3($s2)
/*  f16a768:	0fc2ecb3 */ 	jal	0xf0bb2cc
/*  f16a76c:	00000000 */ 	nop
/*  f16a770:	10000540 */ 	b	.PF0f16bc74
/*  f16a774:	824b04d3 */ 	lb	$t3,0x4d3($s2)
.PF0f16a778:
/*  f16a778:	2401005c */ 	li	$at,0x5c
/*  f16a77c:	14410041 */ 	bne	$v0,$at,.PF0f16a884
/*  f16a780:	24070002 */ 	li	$a3,0x2
/*  f16a784:	02601025 */ 	move	$v0,$s3
/*  f16a788:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a78c:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f16a790:	35ad0404 */ 	ori	$t5,$t5,0x404
/*  f16a794:	02601825 */ 	move	$v1,$s3
/*  f16a798:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a79c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f16a7a0:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f16a7a4:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f16a7a8:	35ef0c04 */ 	ori	$t7,$t7,0xc04
/*  f16a7ac:	02602025 */ 	move	$a0,$s3
/*  f16a7b0:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f16a7b4:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f16a7b8:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f16a7bc:	3408fffe */ 	li	$t0,0xfffe
/*  f16a7c0:	37181404 */ 	ori	$t8,$t8,0x1404
/*  f16a7c4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a7c8:	02602825 */ 	move	$a1,$s3
/*  f16a7cc:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f16a7d0:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f16a7d4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a7d8:	3c0abc00 */ 	lui	$t2,0xbc00
/*  f16a7dc:	354a1c04 */ 	ori	$t2,$t2,0x1c04
/*  f16a7e0:	02603025 */ 	move	$a2,$s3
/*  f16a7e4:	acaa0000 */ 	sw	$t2,0x0($a1)
/*  f16a7e8:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f16a7ec:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a7f0:	3c0b8006 */ 	lui	$t3,0x8006
/*  f16a7f4:	3c090600 */ 	lui	$t1,0x600
/*  f16a7f8:	256b1070 */ 	addiu	$t3,$t3,0x1070
/*  f16a7fc:	02601025 */ 	move	$v0,$s3
/*  f16a800:	3c0e8006 */ 	lui	$t6,0x8006
/*  f16a804:	accb0004 */ 	sw	$t3,0x4($a2)
/*  f16a808:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f16a80c:	25ce1050 */ 	addiu	$t6,$t6,0x1050
/*  f16a810:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f16a814:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f16a818:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a81c:	0fc4a4ff */ 	jal	0xf1293fc
/*  f16a820:	00002025 */ 	move	$a0,$zero
/*  f16a824:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a828:	86040634 */ 	lh	$a0,0x634($s0)
/*  f16a82c:	0c002e7b */ 	jal	0xb9ec
/*  f16a830:	86050636 */ 	lh	$a1,0x636($s0)
/*  f16a834:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a838:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f16a83c:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f16a840:	86060630 */ 	lh	$a2,0x630($s0)
/*  f16a844:	0c002ec7 */ 	jal	0xbb1c
/*  f16a848:	86070632 */ 	lh	$a3,0x632($s0)
/*  f16a84c:	3c013f80 */ 	lui	$at,0x3f80
/*  f16a850:	44816000 */ 	mtc1	$at,$f12
/*  f16a854:	0c005936 */ 	jal	0x164d8
/*  f16a858:	00000000 */ 	nop
/*  f16a85c:	0c002bbb */ 	jal	0xaeec
/*  f16a860:	02602025 */ 	move	$a0,$s3
/*  f16a864:	0c002bc5 */ 	jal	0xaf14
/*  f16a868:	00402025 */ 	move	$a0,$v0
/*  f16a86c:	0c002c1d */ 	jal	0xb074
/*  f16a870:	00402025 */ 	move	$a0,$v0
/*  f16a874:	0fc4eef2 */ 	jal	0xf13bbc8
/*  f16a878:	00402025 */ 	move	$a0,$v0
/*  f16a87c:	100004fc */ 	b	.PF0f16bc70
/*  f16a880:	00409825 */ 	move	$s3,$v0
.PF0f16a884:
/*  f16a884:	8e500298 */ 	lw	$s0,0x298($s2)
/*  f16a888:	06010006 */ 	bgez	$s0,.PF0f16a8a4
/*  f16a88c:	00000000 */ 	nop
/*  f16a890:	8e50029c */ 	lw	$s0,0x29c($s2)
/*  f16a894:	2a190000 */ 	slti	$t9,$s0,0x0
/*  f16a898:	3b300001 */ 	xori	$s0,$t9,0x1
/*  f16a89c:	12000004 */ 	beqz	$s0,.PF0f16a8b0
/*  f16a8a0:	00000000 */ 	nop
.PF0f16a8a4:
/*  f16a8a4:	0fc2f28f */ 	jal	0xf0bca3c
/*  f16a8a8:	00000000 */ 	nop
/*  f16a8ac:	0002802b */ 	sltu	$s0,$zero,$v0
.PF0f16a8b0:
/*  f16a8b0:	12000004 */ 	beqz	$s0,.PF0f16a8c4
/*  f16a8b4:	afb00104 */ 	sw	$s0,0x104($sp)
/*  f16a8b8:	240d0001 */ 	li	$t5,0x1
/*  f16a8bc:	1000001c */ 	b	.PF0f16a930
/*  f16a8c0:	afad010c */ 	sw	$t5,0x10c($sp)
.PF0f16a8c4:
/*  f16a8c4:	8e4f006c */ 	lw	$t7,0x6c($s2)
/*  f16a8c8:	00002025 */ 	move	$a0,$zero
/*  f16a8cc:	00001825 */ 	move	$v1,$zero
/*  f16a8d0:	11e00003 */ 	beqz	$t7,.PF0f16a8e0
/*  f16a8d4:	00001025 */ 	move	$v0,$zero
/*  f16a8d8:	10000001 */ 	b	.PF0f16a8e0
/*  f16a8dc:	24040001 */ 	li	$a0,0x1
.PF0f16a8e0:
/*  f16a8e0:	8e580068 */ 	lw	$t8,0x68($s2)
/*  f16a8e4:	00008025 */ 	move	$s0,$zero
/*  f16a8e8:	13000003 */ 	beqz	$t8,.PF0f16a8f8
/*  f16a8ec:	00000000 */ 	nop
/*  f16a8f0:	10000001 */ 	b	.PF0f16a8f8
/*  f16a8f4:	24030001 */ 	li	$v1,0x1
.PF0f16a8f8:
/*  f16a8f8:	8e4a0064 */ 	lw	$t2,0x64($s2)
/*  f16a8fc:	11400003 */ 	beqz	$t2,.PF0f16a90c
/*  f16a900:	00000000 */ 	nop
/*  f16a904:	10000001 */ 	b	.PF0f16a90c
/*  f16a908:	24020001 */ 	li	$v0,0x1
.PF0f16a90c:
/*  f16a90c:	8e4b0070 */ 	lw	$t3,0x70($s2)
/*  f16a910:	11600003 */ 	beqz	$t3,.PF0f16a920
/*  f16a914:	00000000 */ 	nop
/*  f16a918:	10000001 */ 	b	.PF0f16a920
/*  f16a91c:	24100001 */ 	li	$s0,0x1
.PF0f16a920:
/*  f16a920:	02027021 */ 	addu	$t6,$s0,$v0
/*  f16a924:	01c36021 */ 	addu	$t4,$t6,$v1
/*  f16a928:	0184c821 */ 	addu	$t9,$t4,$a0
/*  f16a92c:	afb9010c */ 	sw	$t9,0x10c($sp)
.PF0f16a930:
/*  f16a930:	02601025 */ 	move	$v0,$s3
/*  f16a934:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a938:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f16a93c:	24070002 */ 	li	$a3,0x2
/*  f16a940:	35ad0404 */ 	ori	$t5,$t5,0x404
/*  f16a944:	02601825 */ 	move	$v1,$s3
/*  f16a948:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a94c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f16a950:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f16a954:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f16a958:	35ef0c04 */ 	ori	$t7,$t7,0xc04
/*  f16a95c:	02602025 */ 	move	$a0,$s3
/*  f16a960:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f16a964:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f16a968:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f16a96c:	3408fffe */ 	li	$t0,0xfffe
/*  f16a970:	37181404 */ 	ori	$t8,$t8,0x1404
/*  f16a974:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a978:	02602825 */ 	move	$a1,$s3
/*  f16a97c:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f16a980:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f16a984:	3c0abc00 */ 	lui	$t2,0xbc00
/*  f16a988:	354a1c04 */ 	ori	$t2,$t2,0x1c04
/*  f16a98c:	acaa0000 */ 	sw	$t2,0x0($a1)
/*  f16a990:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f16a994:	8fab010c */ 	lw	$t3,0x10c($sp)
/*  f16a998:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16a99c:	00008025 */ 	move	$s0,$zero
/*  f16a9a0:	196004b3 */ 	blez	$t3,.PF0f16bc70
/*  f16a9a4:	3c0e8006 */ 	lui	$t6,0x8006
/*  f16a9a8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f16a9ac:	25ce1070 */ 	addiu	$t6,$t6,0x1070
/*  f16a9b0:	4481a000 */ 	mtc1	$at,$f20
/*  f16a9b4:	afae006c */ 	sw	$t6,0x6c($sp)
/*  f16a9b8:	241e0001 */ 	li	$s8,0x1
/*  f16a9bc:	2417ffff */ 	li	$s7,-1
/*  f16a9c0:	2416fffe */ 	li	$s6,-2
/*  f16a9c4:	24150004 */ 	li	$s5,0x4
/*  f16a9c8:	8fac0104 */ 	lw	$t4,0x104($sp)
.PF0f16a9cc:
/*  f16a9cc:	0000a025 */ 	move	$s4,$zero
/*  f16a9d0:	afb30108 */ 	sw	$s3,0x108($sp)
/*  f16a9d4:	11800007 */ 	beqz	$t4,.PF0f16a9f4
/*  f16a9d8:	00002025 */ 	move	$a0,$zero
/*  f16a9dc:	0fc4a4ff */ 	jal	0xf1293fc
/*  f16a9e0:	24110001 */ 	li	$s1,0x1
/*  f16a9e4:	26190001 */ 	addiu	$t9,$s0,0x1
/*  f16a9e8:	ae400290 */ 	sw	$zero,0x290($s2)
/*  f16a9ec:	1000000a */ 	b	.PF0f16aa18
/*  f16a9f0:	afb90064 */ 	sw	$t9,0x64($sp)
.PF0f16a9f4:
/*  f16a9f4:	0fc4a666 */ 	jal	0xf129998
/*  f16a9f8:	02002025 */ 	move	$a0,$s0
/*  f16a9fc:	0fc4a4ff */ 	jal	0xf1293fc
/*  f16aa00:	00402025 */ 	move	$a0,$v0
/*  f16aa04:	8fad010c */ 	lw	$t5,0x10c($sp)
/*  f16aa08:	26020001 */ 	addiu	$v0,$s0,0x1
/*  f16aa0c:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f16aa10:	01a28826 */ 	xor	$s1,$t5,$v0
/*  f16aa14:	2e310001 */ 	sltiu	$s1,$s1,0x1
.PF0f16aa18:
/*  f16aa18:	8e4f02ac */ 	lw	$t7,0x2ac($s2)
/*  f16aa1c:	24010006 */ 	li	$at,0x6
/*  f16aa20:	11e10029 */ 	beq	$t7,$at,.PF0f16aac8
/*  f16aa24:	00000000 */ 	nop
/*  f16aa28:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16aa2c:	8e1800bc */ 	lw	$t8,0xbc($s0)
/*  f16aa30:	8f020004 */ 	lw	$v0,0x4($t8)
/*  f16aa34:	844402d8 */ 	lh	$a0,0x2d8($v0)
/*  f16aa38:	18800023 */ 	blez	$a0,.PF0f16aac8
/*  f16aa3c:	00000000 */ 	nop
/*  f16aa40:	920a1922 */ 	lbu	$t2,0x1922($s0)
/*  f16aa44:	15400020 */ 	bnez	$t2,.PF0f16aac8
/*  f16aa48:	00000000 */ 	nop
/*  f16aa4c:	8e0b1c08 */ 	lw	$t3,0x1c08($s0)
/*  f16aa50:	24011046 */ 	li	$at,0x1046
/*  f16aa54:	1560001c */ 	bnez	$t3,.PF0f16aac8
/*  f16aa58:	00000000 */ 	nop
/*  f16aa5c:	0004a180 */ 	sll	$s4,$a0,0x6
/*  f16aa60:	0284a021 */ 	addu	$s4,$s4,$a0
/*  f16aa64:	0014a040 */ 	sll	$s4,$s4,0x1
/*  f16aa68:	0281001a */ 	div	$zero,$s4,$at
/*  f16aa6c:	00007012 */ 	mflo	$t6
/*  f16aa70:	25d40064 */ 	addiu	$s4,$t6,0x64
/*  f16aa74:	2e8100e7 */ 	sltiu	$at,$s4,0xe7
/*  f16aa78:	14200002 */ 	bnez	$at,.PF0f16aa84
/*  f16aa7c:	240c1046 */ 	li	$t4,0x1046
/*  f16aa80:	241400e6 */ 	li	$s4,0xe6
.PF0f16aa84:
/*  f16aa84:	28811047 */ 	slti	$at,$a0,0x1047
/*  f16aa88:	54200004 */ 	bnezl	$at,.PF0f16aa9c
/*  f16aa8c:	904d02ff */ 	lbu	$t5,0x2ff($v0)
/*  f16aa90:	a44c02d8 */ 	sh	$t4,0x2d8($v0)
/*  f16aa94:	844402d8 */ 	lh	$a0,0x2d8($v0)
/*  f16aa98:	904d02ff */ 	lbu	$t5,0x2ff($v0)
.PF0f16aa9c:
/*  f16aa9c:	8e590038 */ 	lw	$t9,0x38($s2)
/*  f16aaa0:	25af0001 */ 	addiu	$t7,$t5,0x1
/*  f16aaa4:	032f0019 */ 	multu	$t9,$t7
/*  f16aaa8:	0000c012 */ 	mflo	$t8
/*  f16aaac:	00985023 */ 	subu	$t2,$a0,$t8
/*  f16aab0:	a44a02d8 */ 	sh	$t2,0x2d8($v0)
/*  f16aab4:	844b02d8 */ 	lh	$t3,0x2d8($v0)
/*  f16aab8:	1d600003 */ 	bgtz	$t3,.PF0f16aac8
/*  f16aabc:	00000000 */ 	nop
/*  f16aac0:	a44002d8 */ 	sh	$zero,0x2d8($v0)
/*  f16aac4:	a04002ff */ 	sb	$zero,0x2ff($v0)
.PF0f16aac8:
/*  f16aac8:	0fc525fd */ 	jal	0xf1497f4
/*  f16aacc:	02802025 */ 	move	$a0,$s4
/*  f16aad0:	02601025 */ 	move	$v0,$s3
/*  f16aad4:	3c0e0600 */ 	lui	$t6,0x600
/*  f16aad8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f16aadc:	8fac006c */ 	lw	$t4,0x6c($sp)
/*  f16aae0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16aae4:	0fc47e4a */ 	jal	0xf11f928
/*  f16aae8:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f16aaec:	10400009 */ 	beqz	$v0,.PF0f16ab14
/*  f16aaf0:	3c0f0600 */ 	lui	$t7,0x600
/*  f16aaf4:	02601025 */ 	move	$v0,$s3
/*  f16aaf8:	3c198006 */ 	lui	$t9,0x8006
/*  f16aafc:	27391030 */ 	addiu	$t9,$t9,0x1030
/*  f16ab00:	3c0d0600 */ 	lui	$t5,0x600
/*  f16ab04:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f16ab08:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f16ab0c:	10000007 */ 	b	.PF0f16ab2c
/*  f16ab10:	26730008 */ 	addiu	$s3,$s3,0x8
.PF0f16ab14:
/*  f16ab14:	02601025 */ 	move	$v0,$s3
/*  f16ab18:	3c188006 */ 	lui	$t8,0x8006
/*  f16ab1c:	27181050 */ 	addiu	$t8,$t8,0x1050
/*  f16ab20:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f16ab24:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f16ab28:	26730008 */ 	addiu	$s3,$s3,0x8
.PF0f16ab2c:
/*  f16ab2c:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16ab30:	86040634 */ 	lh	$a0,0x634($s0)
/*  f16ab34:	0c002e7b */ 	jal	0xb9ec
/*  f16ab38:	86050636 */ 	lh	$a1,0x636($s0)
/*  f16ab3c:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16ab40:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f16ab44:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f16ab48:	86060630 */ 	lh	$a2,0x630($s0)
/*  f16ab4c:	0c002ec7 */ 	jal	0xbb1c
/*  f16ab50:	86070632 */ 	lh	$a3,0x632($s0)
/*  f16ab54:	8e4a0288 */ 	lw	$t2,0x288($s2)
/*  f16ab58:	0c005936 */ 	jal	0x164d8
/*  f16ab5c:	c54c0074 */ 	lwc1	$f12,0x74($t2)
/*  f16ab60:	0fc599de */ 	jal	0xf166778
/*  f16ab64:	00000000 */ 	nop
/*  f16ab68:	0fc5dcb2 */ 	jal	0xf1772c8
/*  f16ab6c:	00000000 */ 	nop
/*  f16ab70:	0c002bf1 */ 	jal	0xafc4
/*  f16ab74:	02602025 */ 	move	$a0,$s3
/*  f16ab78:	0c002bc5 */ 	jal	0xaf14
/*  f16ab7c:	00402025 */ 	move	$a0,$v0
/*  f16ab80:	0fc576bd */ 	jal	0xf15daf4
/*  f16ab84:	00402025 */ 	move	$a0,$v0
/*  f16ab88:	0fc4f420 */ 	jal	0xf13d080
/*  f16ab8c:	00409825 */ 	move	$s3,$v0
/*  f16ab90:	8e4b04b4 */ 	lw	$t3,0x4b4($s2)
/*  f16ab94:	24010026 */ 	li	$at,0x26
/*  f16ab98:	3c0e8008 */ 	lui	$t6,0x8008
/*  f16ab9c:	5561000a */ 	bnel	$t3,$at,.PF0f16abc8
/*  f16aba0:	8e4d000c */ 	lw	$t5,0xc($s2)
/*  f16aba4:	8dce77b0 */ 	lw	$t6,0x77b0($t6)
/*  f16aba8:	3c0c800a */ 	lui	$t4,0x800a
/*  f16abac:	5dc0001a */ 	bgtzl	$t6,.PF0f16ac18
/*  f16abb0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16abb4:	8d8c1f64 */ 	lw	$t4,0x1f64($t4)
/*  f16abb8:	24010003 */ 	li	$at,0x3
/*  f16abbc:	51810016 */ 	beql	$t4,$at,.PF0f16ac18
/*  f16abc0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16abc4:	8e4d000c */ 	lw	$t5,0xc($s2)
.PF0f16abc8:
/*  f16abc8:	29a10006 */ 	slti	$at,$t5,0x6
/*  f16abcc:	50200012 */ 	beqzl	$at,.PF0f16ac18
/*  f16abd0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16abd4:	8e590318 */ 	lw	$t9,0x318($s2)
/*  f16abd8:	5720000f */ 	bnezl	$t9,.PF0f16ac18
/*  f16abdc:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16abe0:	8e4f02ac */ 	lw	$t7,0x2ac($s2)
/*  f16abe4:	24010006 */ 	li	$at,0x6
/*  f16abe8:	3c028008 */ 	lui	$v0,0x8008
/*  f16abec:	51e1000a */ 	beql	$t7,$at,.PF0f16ac18
/*  f16abf0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16abf4:	8c424590 */ 	lw	$v0,0x4590($v0)
/*  f16abf8:	28410006 */ 	slti	$at,$v0,0x6
/*  f16abfc:	10200002 */ 	beqz	$at,.PF0f16ac08
/*  f16ac00:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f16ac04:	ae5e0320 */ 	sw	$s8,0x320($s2)
.PF0f16ac08:
/*  f16ac08:	3c018008 */ 	lui	$at,0x8008
/*  f16ac0c:	1000001d */ 	b	.PF0f16ac84
/*  f16ac10:	ac384590 */ 	sw	$t8,0x4590($at)
/*  f16ac14:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16ac18:
/*  f16ac18:	3c0c8007 */ 	lui	$t4,0x8007
/*  f16ac1c:	8e0a1580 */ 	lw	$t2,0x1580($s0)
/*  f16ac20:	000a7780 */ 	sll	$t6,$t2,0x1e
/*  f16ac24:	05c30018 */ 	bgezl	$t6,.PF0f16ac88
/*  f16ac28:	8e4c0320 */ 	lw	$t4,0x320($s2)
/*  f16ac2c:	8d8c6230 */ 	lw	$t4,0x6230($t4)
/*  f16ac30:	24010002 */ 	li	$at,0x2
/*  f16ac34:	55810014 */ 	bnel	$t4,$at,.PF0f16ac88
/*  f16ac38:	8e4c0320 */ 	lw	$t4,0x320($s2)
/*  f16ac3c:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f16ac40:	24010002 */ 	li	$at,0x2
/*  f16ac44:	53c20010 */ 	beql	$s8,$v0,.PF0f16ac88
/*  f16ac48:	8e4c0320 */ 	lw	$t4,0x320($s2)
/*  f16ac4c:	1041000d */ 	beq	$v0,$at,.PF0f16ac84
/*  f16ac50:	3c0d800a */ 	lui	$t5,0x800a
/*  f16ac54:	8dade560 */ 	lw	$t5,-0x1aa0($t5)
/*  f16ac58:	55a0000b */ 	bnezl	$t5,.PF0f16ac88
/*  f16ac5c:	8e4c0320 */ 	lw	$t4,0x320($s2)
/*  f16ac60:	0fc27b66 */ 	jal	0xf09ed98
/*  f16ac64:	00000000 */ 	nop
/*  f16ac68:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16ac6c:	00027840 */ 	sll	$t7,$v0,0x1
/*  f16ac70:	31f80002 */ 	andi	$t8,$t7,0x2
/*  f16ac74:	920a1583 */ 	lbu	$t2,0x1583($s0)
/*  f16ac78:	314bfffd */ 	andi	$t3,$t2,0xfffd
/*  f16ac7c:	030b7025 */ 	or	$t6,$t8,$t3
/*  f16ac80:	a20e1583 */ 	sb	$t6,0x1583($s0)
.PF0f16ac84:
/*  f16ac84:	8e4c0320 */ 	lw	$t4,0x320($s2)
.PF0f16ac88:
/*  f16ac88:	02602025 */ 	move	$a0,$s3
/*  f16ac8c:	2405ffff */ 	li	$a1,-1
/*  f16ac90:	11800008 */ 	beqz	$t4,.PF0f16acb4
/*  f16ac94:	3c0f800a */ 	lui	$t7,0x800a
/*  f16ac98:	0fc50bea */ 	jal	0xf142fa8
/*  f16ac9c:	240600ff */ 	li	$a2,0xff
/*  f16aca0:	8e4d0320 */ 	lw	$t5,0x320($s2)
/*  f16aca4:	00409825 */ 	move	$s3,$v0
/*  f16aca8:	25b9ffff */ 	addiu	$t9,$t5,-1
/*  f16acac:	100003dc */ 	b	.PF0f16bc20
/*  f16acb0:	ae590320 */ 	sw	$t9,0x320($s2)
.PF0f16acb4:
/*  f16acb4:	8defe560 */ 	lw	$t7,-0x1aa0($t7)
/*  f16acb8:	3c0e8007 */ 	lui	$t6,0x8007
/*  f16acbc:	11e00012 */ 	beqz	$t7,.PF0f16ad08
/*  f16acc0:	00000000 */ 	nop
/*  f16acc4:	0c002c1d */ 	jal	0xb074
/*  f16acc8:	02602025 */ 	move	$a0,$s3
/*  f16accc:	0fc576bd */ 	jal	0xf15daf4
/*  f16acd0:	00402025 */ 	move	$a0,$v0
/*  f16acd4:	3c013f80 */ 	lui	$at,0x3f80
/*  f16acd8:	44816000 */ 	mtc1	$at,$f12
/*  f16acdc:	0c005936 */ 	jal	0x164d8
/*  f16ace0:	00409825 */ 	move	$s3,$v0
/*  f16ace4:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f16ace8:	8d581c50 */ 	lw	$t8,0x1c50($t2)
/*  f16acec:	00185fc2 */ 	srl	$t3,$t8,0x1f
/*  f16acf0:	116003cb */ 	beqz	$t3,.PF0f16bc20
/*  f16acf4:	00000000 */ 	nop
/*  f16acf8:	0fc3f0f0 */ 	jal	0xf0fc3c0
/*  f16acfc:	02602025 */ 	move	$a0,$s3
/*  f16ad00:	100003c7 */ 	b	.PF0f16bc20
/*  f16ad04:	00409825 */ 	move	$s3,$v0
.PF0f16ad08:
/*  f16ad08:	8dce6230 */ 	lw	$t6,0x6230($t6)
/*  f16ad0c:	24010002 */ 	li	$at,0x2
/*  f16ad10:	15c10004 */ 	bne	$t6,$at,.PF0f16ad24
/*  f16ad14:	00000000 */ 	nop
/*  f16ad18:	0fc3014e */ 	jal	0xf0c0538
/*  f16ad1c:	02602025 */ 	move	$a0,$s3
/*  f16ad20:	00409825 */ 	move	$s3,$v0
.PF0f16ad24:
/*  f16ad24:	0c002c1d */ 	jal	0xb074
/*  f16ad28:	02602025 */ 	move	$a0,$s3
/*  f16ad2c:	0fc48121 */ 	jal	0xf120484
/*  f16ad30:	00402025 */ 	move	$a0,$v0
/*  f16ad34:	0fc57660 */ 	jal	0xf15d980
/*  f16ad38:	00409825 */ 	move	$s3,$v0
/*  f16ad3c:	0fc010c5 */ 	jal	0xf004314
/*  f16ad40:	00000000 */ 	nop
/*  f16ad44:	0fc18ca3 */ 	jal	0xf06328c
/*  f16ad48:	02202025 */ 	move	$a0,$s1
/*  f16ad4c:	0fc619c9 */ 	jal	0xf186724
/*  f16ad50:	00002025 */ 	move	$a0,$zero
/*  f16ad54:	0fc18104 */ 	jal	0xf060410
/*  f16ad58:	00000000 */ 	nop
/*  f16ad5c:	0fc193de */ 	jal	0xf064f78
/*  f16ad60:	00000000 */ 	nop
/*  f16ad64:	0fc18b63 */ 	jal	0xf062d8c
/*  f16ad68:	00000000 */ 	nop
/*  f16ad6c:	8e4c006c */ 	lw	$t4,0x6c($s2)
/*  f16ad70:	00002025 */ 	move	$a0,$zero
/*  f16ad74:	00001825 */ 	move	$v1,$zero
/*  f16ad78:	11800003 */ 	beqz	$t4,.PF0f16ad88
/*  f16ad7c:	00001025 */ 	move	$v0,$zero
/*  f16ad80:	10000001 */ 	b	.PF0f16ad88
/*  f16ad84:	03c02025 */ 	move	$a0,$s8
.PF0f16ad88:
/*  f16ad88:	8e4d0068 */ 	lw	$t5,0x68($s2)
/*  f16ad8c:	00008025 */ 	move	$s0,$zero
/*  f16ad90:	11a00003 */ 	beqz	$t5,.PF0f16ada0
/*  f16ad94:	00000000 */ 	nop
/*  f16ad98:	10000001 */ 	b	.PF0f16ada0
/*  f16ad9c:	03c01825 */ 	move	$v1,$s8
.PF0f16ada0:
/*  f16ada0:	8e590064 */ 	lw	$t9,0x64($s2)
/*  f16ada4:	13200003 */ 	beqz	$t9,.PF0f16adb4
/*  f16ada8:	00000000 */ 	nop
/*  f16adac:	10000001 */ 	b	.PF0f16adb4
/*  f16adb0:	03c01025 */ 	move	$v0,$s8
.PF0f16adb4:
/*  f16adb4:	8e4f0070 */ 	lw	$t7,0x70($s2)
/*  f16adb8:	11e00003 */ 	beqz	$t7,.PF0f16adc8
/*  f16adbc:	00000000 */ 	nop
/*  f16adc0:	10000001 */ 	b	.PF0f16adc8
/*  f16adc4:	03c08025 */ 	move	$s0,$s8
.PF0f16adc8:
/*  f16adc8:	02025021 */ 	addu	$t2,$s0,$v0
/*  f16adcc:	0143c021 */ 	addu	$t8,$t2,$v1
/*  f16add0:	03045821 */ 	addu	$t3,$t8,$a0
/*  f16add4:	53cb0012 */ 	beql	$s8,$t3,.PF0f16ae20
/*  f16add8:	00002025 */ 	move	$a0,$zero
/*  f16addc:	8e4e0298 */ 	lw	$t6,0x298($s2)
/*  f16ade0:	05c3000f */ 	bgezl	$t6,.PF0f16ae20
/*  f16ade4:	00002025 */ 	move	$a0,$zero
/*  f16ade8:	8e4c029c */ 	lw	$t4,0x29c($s2)
/*  f16adec:	0583000c */ 	bgezl	$t4,.PF0f16ae20
/*  f16adf0:	00002025 */ 	move	$a0,$zero
/*  f16adf4:	0fc28737 */ 	jal	0xf0a1cdc
/*  f16adf8:	00002025 */ 	move	$a0,$zero
/*  f16adfc:	00402025 */ 	move	$a0,$v0
/*  f16ae00:	0fc2c720 */ 	jal	0xf0b1c80
/*  f16ae04:	3c054000 */ 	lui	$a1,0x4000
/*  f16ae08:	50400050 */ 	beqzl	$v0,.PF0f16af4c
/*  f16ae0c:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f16ae10:	0fc32020 */ 	jal	0xf0c8080
/*  f16ae14:	00000000 */ 	nop
/*  f16ae18:	1040004b */ 	beqz	$v0,.PF0f16af48
/*  f16ae1c:	00002025 */ 	move	$a0,$zero
.PF0f16ae20:
/*  f16ae20:	00002825 */ 	move	$a1,$zero
/*  f16ae24:	0fc187ed */ 	jal	0xf061fb4
/*  f16ae28:	00003025 */ 	move	$a2,$zero
/*  f16ae2c:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f16ae30:	ada21624 */ 	sw	$v0,0x1624($t5)
/*  f16ae34:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16ae38:	8e041624 */ 	lw	$a0,0x1624($s0)
/*  f16ae3c:	50800046 */ 	beqzl	$a0,.PF0f16af58
/*  f16ae40:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f16ae44:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f16ae48:	24010003 */ 	li	$at,0x3
/*  f16ae4c:	10410003 */ 	beq	$v0,$at,.PF0f16ae5c
/*  f16ae50:	24010006 */ 	li	$at,0x6
/*  f16ae54:	1441001f */ 	bne	$v0,$at,.PF0f16aed4
/*  f16ae58:	00000000 */ 	nop
.PF0f16ae5c:
/*  f16ae5c:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f16ae60:	8c590014 */ 	lw	$t9,0x14($v0)
/*  f16ae64:	00197880 */ 	sll	$t7,$t9,0x2
/*  f16ae68:	05e3003b */ 	bgezl	$t7,.PF0f16af58
/*  f16ae6c:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f16ae70:	8e0a00d8 */ 	lw	$t2,0xd8($s0)
/*  f16ae74:	3c188007 */ 	lui	$t8,0x8007
/*  f16ae78:	55400014 */ 	bnezl	$t2,.PF0f16aecc
/*  f16ae7c:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f16ae80:	8f180a44 */ 	lw	$t8,0xa44($t8)
/*  f16ae84:	57000011 */ 	bnezl	$t8,.PF0f16aecc
/*  f16ae88:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f16ae8c:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f16ae90:	50400007 */ 	beqzl	$v0,.PF0f16aeb0
/*  f16ae94:	8e0c1c54 */ 	lw	$t4,0x1c54($s0)
/*  f16ae98:	5040000c */ 	beqzl	$v0,.PF0f16aecc
/*  f16ae9c:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f16aea0:	804b0037 */ 	lb	$t3,0x37($v0)
/*  f16aea4:	55600009 */ 	bnezl	$t3,.PF0f16aecc
/*  f16aea8:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f16aeac:	8e0c1c54 */ 	lw	$t4,0x1c54($s0)
.PF0f16aeb0:
/*  f16aeb0:	8e0e00c4 */ 	lw	$t6,0xc4($s0)
/*  f16aeb4:	01806827 */ 	nor	$t5,$t4,$zero
/*  f16aeb8:	01cdc824 */ 	and	$t9,$t6,$t5
/*  f16aebc:	332f0008 */ 	andi	$t7,$t9,0x8
/*  f16aec0:	55e00025 */ 	bnezl	$t7,.PF0f16af58
/*  f16aec4:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f16aec8:	ae001624 */ 	sw	$zero,0x1624($s0)
.PF0f16aecc:
/*  f16aecc:	10000021 */ 	b	.PF0f16af54
/*  f16aed0:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16aed4:
/*  f16aed4:	53c20006 */ 	beql	$s8,$v0,.PF0f16aef0
/*  f16aed8:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f16aedc:	12a20003 */ 	beq	$s5,$v0,.PF0f16aeec
/*  f16aee0:	24010002 */ 	li	$at,0x2
/*  f16aee4:	54410016 */ 	bnel	$v0,$at,.PF0f16af40
/*  f16aee8:	ae001624 */ 	sw	$zero,0x1624($s0)
.PF0f16aeec:
/*  f16aeec:	8c830004 */ 	lw	$v1,0x4($a0)
.PF0f16aef0:
/*  f16aef0:	8c6a0010 */ 	lw	$t2,0x10($v1)
/*  f16aef4:	31588000 */ 	andi	$t8,$t2,0x8000
/*  f16aef8:	57000017 */ 	bnezl	$t8,.PF0f16af58
/*  f16aefc:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f16af00:	8e4b04b4 */ 	lw	$t3,0x4b4($s2)
/*  f16af04:	24010026 */ 	li	$at,0x26
/*  f16af08:	5561000a */ 	bnel	$t3,$at,.PF0f16af34
/*  f16af0c:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f16af10:	84620004 */ 	lh	$v0,0x4($v1)
/*  f16af14:	2401014c */ 	li	$at,0x14c
/*  f16af18:	1041000e */ 	beq	$v0,$at,.PF0f16af54
/*  f16af1c:	240101aa */ 	li	$at,0x1aa
/*  f16af20:	1041000c */ 	beq	$v0,$at,.PF0f16af54
/*  f16af24:	240100b0 */ 	li	$at,0xb0
/*  f16af28:	5041000b */ 	beql	$v0,$at,.PF0f16af58
/*  f16af2c:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f16af30:	ae001624 */ 	sw	$zero,0x1624($s0)
.PF0f16af34:
/*  f16af34:	10000007 */ 	b	.PF0f16af54
/*  f16af38:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16af3c:	ae001624 */ 	sw	$zero,0x1624($s0)
.PF0f16af40:
/*  f16af40:	10000004 */ 	b	.PF0f16af54
/*  f16af44:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16af48:
/*  f16af48:	8e4c0284 */ 	lw	$t4,0x284($s2)
.PF0f16af4c:
/*  f16af4c:	ad801624 */ 	sw	$zero,0x1624($t4)
/*  f16af50:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16af54:
/*  f16af54:	26040638 */ 	addiu	$a0,$s0,0x638
.PF0f16af58:
/*  f16af58:	0fc2c8e8 */ 	jal	0xf0b23a0
/*  f16af5c:	3c050008 */ 	lui	$a1,0x8
/*  f16af60:	10400005 */ 	beqz	$v0,.PF0f16af78
/*  f16af64:	00000000 */ 	nop
/*  f16af68:	0fc5a851 */ 	jal	0xf16a144
/*  f16af6c:	00000000 */ 	nop
/*  f16af70:	10000033 */ 	b	.PF0f16b040
/*  f16af74:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16af78:
/*  f16af78:	0fc28737 */ 	jal	0xf0a1cdc
/*  f16af7c:	00002025 */ 	move	$a0,$zero
/*  f16af80:	00402025 */ 	move	$a0,$v0
/*  f16af84:	0fc2c720 */ 	jal	0xf0b1c80
/*  f16af88:	3c054000 */ 	lui	$a1,0x4000
/*  f16af8c:	5040002c */ 	beqzl	$v0,.PF0f16b040
/*  f16af90:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16af94:	0fc68746 */ 	jal	0xf1a1d18
/*  f16af98:	00000000 */ 	nop
/*  f16af9c:	5040000f */ 	beqzl	$v0,.PF0f16afdc
/*  f16afa0:	8e440284 */ 	lw	$a0,0x284($s2)
/*  f16afa4:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f16afa8:	8dcd1624 */ 	lw	$t5,0x1624($t6)
/*  f16afac:	51a0000b */ 	beqzl	$t5,.PF0f16afdc
/*  f16afb0:	8e440284 */ 	lw	$a0,0x284($s2)
/*  f16afb4:	0fc32020 */ 	jal	0xf0c8080
/*  f16afb8:	00000000 */ 	nop
/*  f16afbc:	50400007 */ 	beqzl	$v0,.PF0f16afdc
/*  f16afc0:	8e440284 */ 	lw	$a0,0x284($s2)
/*  f16afc4:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f16afc8:	0fc68683 */ 	jal	0xf1a1a0c
/*  f16afcc:	8f241624 */ 	lw	$a0,0x1624($t9)
/*  f16afd0:	1000000a */ 	b	.PF0f16affc
/*  f16afd4:	00008825 */ 	move	$s1,$zero
/*  f16afd8:	8e440284 */ 	lw	$a0,0x284($s2)
.PF0f16afdc:
/*  f16afdc:	02e02825 */ 	move	$a1,$s7
/*  f16afe0:	0fc5a620 */ 	jal	0xf169880
/*  f16afe4:	24841624 */ 	addiu	$a0,$a0,0x1624
/*  f16afe8:	54400004 */ 	bnezl	$v0,.PF0f16affc
/*  f16afec:	00008825 */ 	move	$s1,$zero
/*  f16aff0:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f16aff4:	ade01624 */ 	sw	$zero,0x1624($t7)
/*  f16aff8:	00008825 */ 	move	$s1,$zero
.PF0f16affc:
/*  f16affc:	00008025 */ 	move	$s0,$zero
.PF0f16b000:
/*  f16b000:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f16b004:	02202825 */ 	move	$a1,$s1
/*  f16b008:	01502021 */ 	addu	$a0,$t2,$s0
/*  f16b00c:	0fc5a620 */ 	jal	0xf169880
/*  f16b010:	24841630 */ 	addiu	$a0,$a0,0x1630
/*  f16b014:	14400007 */ 	bnez	$v0,.PF0f16b034
/*  f16b018:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f16b01c:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f16b020:	03105821 */ 	addu	$t3,$t8,$s0
/*  f16b024:	a5771634 */ 	sh	$s7,0x1634($t3)
/*  f16b028:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f16b02c:	01907021 */ 	addu	$t6,$t4,$s0
/*  f16b030:	a5d61638 */ 	sh	$s6,0x1638($t6)
.PF0f16b034:
/*  f16b034:	1635fff2 */ 	bne	$s1,$s5,.PF0f16b000
/*  f16b038:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f16b03c:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16b040:
/*  f16b040:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f16b044:	50400071 */ 	beqzl	$v0,.PF0f16b20c
/*  f16b048:	8e0e00d0 */ 	lw	$t6,0xd0($s0)
/*  f16b04c:	8e191c54 */ 	lw	$t9,0x1c54($s0)
/*  f16b050:	8e0d00c4 */ 	lw	$t5,0xc4($s0)
/*  f16b054:	03207827 */ 	nor	$t7,$t9,$zero
/*  f16b058:	01af5024 */ 	and	$t2,$t5,$t7
/*  f16b05c:	31580004 */ 	andi	$t8,$t2,0x4
/*  f16b060:	5300006a */ 	beqzl	$t8,.PF0f16b20c
/*  f16b064:	8e0e00d0 */ 	lw	$t6,0xd0($s0)
/*  f16b068:	804b0039 */ 	lb	$t3,0x39($v0)
/*  f16b06c:	51600067 */ 	beqzl	$t3,.PF0f16b20c
/*  f16b070:	8e0e00d0 */ 	lw	$t6,0xd0($s0)
/*  f16b074:	9043006b */ 	lbu	$v1,0x6b($v0)
/*  f16b078:	3c0143c8 */ 	lui	$at,0x43c8
/*  f16b07c:	14600010 */ 	bnez	$v1,.PF0f16b0c0
/*  f16b080:	00000000 */ 	nop
/*  f16b084:	44816000 */ 	mtc1	$at,$f12
/*  f16b088:	0fc257ea */ 	jal	0xf095fa8
/*  f16b08c:	00000000 */ 	nop
/*  f16b090:	3c048009 */ 	lui	$a0,0x8009
/*  f16b094:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f16b098:	240504ff */ 	li	$a1,0x4ff
/*  f16b09c:	00003025 */ 	move	$a2,$zero
/*  f16b0a0:	02e03825 */ 	move	$a3,$s7
/*  f16b0a4:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16b0a8:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16b0ac:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16b0b0:	0c0041a0 */ 	jal	0x10680
/*  f16b0b4:	afb7001c */ 	sw	$s7,0x1c($sp)
/*  f16b0b8:	10000053 */ 	b	.PF0f16b208
/*  f16b0bc:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16b0c0:
/*  f16b0c0:	17c30032 */ 	bne	$s8,$v1,.PF0f16b18c
/*  f16b0c4:	3c0e8008 */ 	lui	$t6,0x8008
/*  f16b0c8:	8e0c0490 */ 	lw	$t4,0x490($s0)
/*  f16b0cc:	3c048009 */ 	lui	$a0,0x8009
/*  f16b0d0:	24058052 */ 	li	$a1,-32686
/*  f16b0d4:	11800024 */ 	beqz	$t4,.PF0f16b168
/*  f16b0d8:	00003025 */ 	move	$a2,$zero
/*  f16b0dc:	3c048009 */ 	lui	$a0,0x8009
/*  f16b0e0:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f16b0e4:	24058057 */ 	li	$a1,-32681
/*  f16b0e8:	00003025 */ 	move	$a2,$zero
/*  f16b0ec:	02e03825 */ 	move	$a3,$s7
/*  f16b0f0:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16b0f4:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16b0f8:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16b0fc:	0c0041a0 */ 	jal	0x10680
/*  f16b100:	afb7001c */ 	sw	$s7,0x1c($sp)
/*  f16b104:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16b108:	240b001c */ 	li	$t3,0x1c
/*  f16b10c:	00002825 */ 	move	$a1,$zero
/*  f16b110:	8e0e0490 */ 	lw	$t6,0x490($s0)
/*  f16b114:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f16b118:	25d9ffff */ 	addiu	$t9,$t6,-1
/*  f16b11c:	ae190490 */ 	sw	$t9,0x490($s0)
/*  f16b120:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16b124:	8e0d0480 */ 	lw	$t5,0x480($s0)
/*  f16b128:	c5b00004 */ 	lwc1	$f16,0x4($t5)
/*  f16b12c:	e7b000c0 */ 	swc1	$f16,0xc0($sp)
/*  f16b130:	8e0f0480 */ 	lw	$t7,0x480($s0)
/*  f16b134:	c5f20008 */ 	lwc1	$f18,0x8($t7)
/*  f16b138:	e7b200c4 */ 	swc1	$f18,0xc4($sp)
/*  f16b13c:	8e0a0480 */ 	lw	$t2,0x480($s0)
/*  f16b140:	c544000c */ 	lwc1	$f4,0xc($t2)
/*  f16b144:	e7a400c8 */ 	swc1	$f4,0xc8($sp)
/*  f16b148:	8e180480 */ 	lw	$t8,0x480($s0)
/*  f16b14c:	8f040000 */ 	lw	$a0,0x0($t8)
/*  f16b150:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f16b154:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f16b158:	0fc24477 */ 	jal	0xf0911dc
/*  f16b15c:	24860008 */ 	addiu	$a2,$a0,0x8
/*  f16b160:	10000008 */ 	b	.PF0f16b184
/*  f16b164:	00000000 */ 	nop
.PF0f16b168:
/*  f16b168:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f16b16c:	02e03825 */ 	move	$a3,$s7
/*  f16b170:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16b174:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16b178:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16b17c:	0c0041a0 */ 	jal	0x10680
/*  f16b180:	afb7001c */ 	sw	$s7,0x1c($sp)
.PF0f16b184:
/*  f16b184:	10000020 */ 	b	.PF0f16b208
/*  f16b188:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16b18c:
/*  f16b18c:	25ce45c8 */ 	addiu	$t6,$t6,0x45c8
/*  f16b190:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f16b194:	27ac00b4 */ 	addiu	$t4,$sp,0xb4
/*  f16b198:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f16b19c:	ad810000 */ 	sw	$at,0x0($t4)
/*  f16b1a0:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f16b1a4:	3c0a8008 */ 	lui	$t2,0x8008
/*  f16b1a8:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f16b1ac:	ad810008 */ 	sw	$at,0x8($t4)
/*  f16b1b0:	8d4a45d4 */ 	lw	$t2,0x45d4($t2)
/*  f16b1b4:	24070017 */ 	li	$a3,0x17
/*  f16b1b8:	afaa00b0 */ 	sw	$t2,0xb0($sp)
/*  f16b1bc:	8e180480 */ 	lw	$t8,0x480($s0)
/*  f16b1c0:	8f040000 */ 	lw	$a0,0x0($t8)
/*  f16b1c4:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f16b1c8:	24850008 */ 	addiu	$a1,$a0,0x8
/*  f16b1cc:	0fc4a8f4 */ 	jal	0xf12a3d0
/*  f16b1d0:	24860028 */ 	addiu	$a2,$a0,0x28
/*  f16b1d4:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f16b1d8:	27ac00b0 */ 	addiu	$t4,$sp,0xb0
/*  f16b1dc:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f16b1e0:	8d6d0480 */ 	lw	$t5,0x480($t3)
/*  f16b1e4:	24060000 */ 	li	$a2,0x0
/*  f16b1e8:	00003825 */ 	move	$a3,$zero
/*  f16b1ec:	8db90000 */ 	lw	$t9,0x0($t5)
/*  f16b1f0:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f16b1f4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f16b1f8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f16b1fc:	0fc0c6bb */ 	jal	0xf031aec
/*  f16b200:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f16b204:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16b208:
/*  f16b208:	8e0e00d0 */ 	lw	$t6,0xd0($s0)
.PF0f16b20c:
/*  f16b20c:	51c0000c */ 	beqzl	$t6,.PF0f16b240
/*  f16b210:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f16b214:	0fc18c35 */ 	jal	0xf0630d4
/*  f16b218:	00002025 */ 	move	$a0,$zero
/*  f16b21c:	10400012 */ 	beqz	$v0,.PF0f16b268
/*  f16b220:	00000000 */ 	nop
/*  f16b224:	0fc28953 */ 	jal	0xf0a254c
/*  f16b228:	00002025 */ 	move	$a0,$zero
/*  f16b22c:	0fc28953 */ 	jal	0xf0a254c
/*  f16b230:	03c02025 */ 	move	$a0,$s8
/*  f16b234:	1000000c */ 	b	.PF0f16b268
/*  f16b238:	00000000 */ 	nop
/*  f16b23c:	8e020480 */ 	lw	$v0,0x480($s0)
.PF0f16b240:
/*  f16b240:	10400009 */ 	beqz	$v0,.PF0f16b268
/*  f16b244:	00000000 */ 	nop
/*  f16b248:	804f0037 */ 	lb	$t7,0x37($v0)
/*  f16b24c:	11e00006 */ 	beqz	$t7,.PF0f16b268
/*  f16b250:	00000000 */ 	nop
/*  f16b254:	904a006a */ 	lbu	$t2,0x6a($v0)
/*  f16b258:	11400003 */ 	beqz	$t2,.PF0f16b268
/*  f16b25c:	00000000 */ 	nop
/*  f16b260:	0fc18c35 */ 	jal	0xf0630d4
/*  f16b264:	03c02025 */ 	move	$a0,$s8
.PF0f16b268:
/*  f16b268:	0fc19121 */ 	jal	0xf064484
/*  f16b26c:	00000000 */ 	nop
/*  f16b270:	0fc57698 */ 	jal	0xf15da60
/*  f16b274:	02602025 */ 	move	$a0,$s3
/*  f16b278:	3c108007 */ 	lui	$s0,0x8007
/*  f16b27c:	8e106238 */ 	lw	$s0,0x6238($s0)
/*  f16b280:	00409825 */ 	move	$s3,$v0
/*  f16b284:	3a18000f */ 	xori	$t8,$s0,0xf
/*  f16b288:	2f100001 */ 	sltiu	$s0,$t8,0x1
/*  f16b28c:	16000005 */ 	bnez	$s0,.PF0f16b2a4
/*  f16b290:	00000000 */ 	nop
/*  f16b294:	3c108006 */ 	lui	$s0,0x8006
/*  f16b298:	8e10ecd0 */ 	lw	$s0,-0x1330($s0)
/*  f16b29c:	0010582b */ 	sltu	$t3,$zero,$s0
/*  f16b2a0:	01608025 */ 	move	$s0,$t3
.PF0f16b2a4:
/*  f16b2a4:	0fc0a16f */ 	jal	0xf0285bc
/*  f16b2a8:	02002025 */ 	move	$a0,$s0
/*  f16b2ac:	0fc1fe48 */ 	jal	0xf07f920
/*  f16b2b0:	02602025 */ 	move	$a0,$s3
/*  f16b2b4:	0fc54ce5 */ 	jal	0xf153394
/*  f16b2b8:	00402025 */ 	move	$a0,$v0
/*  f16b2bc:	0fc4c2ee */ 	jal	0xf130bb8
/*  f16b2c0:	00402025 */ 	move	$a0,$v0
/*  f16b2c4:	0fc4c6f4 */ 	jal	0xf131bd0
/*  f16b2c8:	00402025 */ 	move	$a0,$v0
/*  f16b2cc:	3c0d8006 */ 	lui	$t5,0x8006
/*  f16b2d0:	8dad1310 */ 	lw	$t5,0x1310($t5)
/*  f16b2d4:	00409825 */ 	move	$s3,$v0
/*  f16b2d8:	11a00004 */ 	beqz	$t5,.PF0f16b2ec
/*  f16b2dc:	00000000 */ 	nop
/*  f16b2e0:	0fc0285e */ 	jal	0xf00a178
/*  f16b2e4:	00402025 */ 	move	$a0,$v0
/*  f16b2e8:	00409825 */ 	move	$s3,$v0
.PF0f16b2ec:
/*  f16b2ec:	3c198007 */ 	lui	$t9,0x8007
/*  f16b2f0:	8f396230 */ 	lw	$t9,0x6230($t9)
/*  f16b2f4:	24010002 */ 	li	$at,0x2
/*  f16b2f8:	17210005 */ 	bne	$t9,$at,.PF0f16b310
/*  f16b2fc:	00000000 */ 	nop
/*  f16b300:	0fc3034d */ 	jal	0xf0c0d34
/*  f16b304:	02602025 */ 	move	$a0,$s3
/*  f16b308:	1000000b */ 	b	.PF0f16b338
/*  f16b30c:	00409825 */ 	move	$s3,$v0
.PF0f16b310:
/*  f16b310:	0fc2bce6 */ 	jal	0xf0af398
/*  f16b314:	02602025 */ 	move	$a0,$s3
/*  f16b318:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f16b31c:	00409825 */ 	move	$s3,$v0
/*  f16b320:	958e0010 */ 	lhu	$t6,0x10($t4)
/*  f16b324:	13ce0004 */ 	beq	$s8,$t6,.PF0f16b338
/*  f16b328:	00000000 */ 	nop
/*  f16b32c:	0fc57025 */ 	jal	0xf15c094
/*  f16b330:	00402025 */ 	move	$a0,$v0
/*  f16b334:	00409825 */ 	move	$s3,$v0
.PF0f16b338:
/*  f16b338:	3c0f8007 */ 	lui	$t7,0x8007
/*  f16b33c:	8def6248 */ 	lw	$t7,0x6248($t7)
/*  f16b340:	1de001f6 */ 	bgtz	$t7,.PF0f16bb1c
/*  f16b344:	00000000 */ 	nop
/*  f16b348:	8e4a02ac */ 	lw	$t2,0x2ac($s2)
/*  f16b34c:	24010006 */ 	li	$at,0x6
/*  f16b350:	00008825 */ 	move	$s1,$zero
/*  f16b354:	1541006f */ 	bne	$t2,$at,.PF0f16b514
/*  f16b358:	3c10800a */ 	lui	$s0,0x800a
/*  f16b35c:	8610e38c */ 	lh	$s0,-0x1c74($s0)
/*  f16b360:	24010181 */ 	li	$at,0x181
/*  f16b364:	3c048008 */ 	lui	$a0,0x8008
/*  f16b368:	12010011 */ 	beq	$s0,$at,.PF0f16b3b0
/*  f16b36c:	24010183 */ 	li	$at,0x183
/*  f16b370:	1201000f */ 	beq	$s0,$at,.PF0f16b3b0
/*  f16b374:	24010188 */ 	li	$at,0x188
/*  f16b378:	1201000d */ 	beq	$s0,$at,.PF0f16b3b0
/*  f16b37c:	240101e5 */ 	li	$at,0x1e5
/*  f16b380:	16010064 */ 	bne	$s0,$at,.PF0f16b514
/*  f16b384:	3c02800a */ 	lui	$v0,0x800a
/*  f16b388:	8c42e380 */ 	lw	$v0,-0x1c80($v0)
/*  f16b38c:	28410348 */ 	slti	$at,$v0,0x348
/*  f16b390:	14200060 */ 	bnez	$at,.PF0f16b514
/*  f16b394:	28410583 */ 	slti	$at,$v0,0x583
/*  f16b398:	1020005e */ 	beqz	$at,.PF0f16b514
/*  f16b39c:	00000000 */ 	nop
/*  f16b3a0:	0fc522da */ 	jal	0xf148b68
/*  f16b3a4:	02602025 */ 	move	$a0,$s3
/*  f16b3a8:	1000005a */ 	b	.PF0f16b514
/*  f16b3ac:	00409825 */ 	move	$s3,$v0
.PF0f16b3b0:
/*  f16b3b0:	8c8445d8 */ 	lw	$a0,0x45d8($a0)
/*  f16b3b4:	00008025 */ 	move	$s0,$zero
/*  f16b3b8:	03c08825 */ 	move	$s1,$s8
/*  f16b3bc:	1480000b */ 	bnez	$a0,.PF0f16b3ec
/*  f16b3c0:	2405059f */ 	li	$a1,0x59f
/*  f16b3c4:	3c048009 */ 	lui	$a0,0x8009
/*  f16b3c8:	3c068008 */ 	lui	$a2,0x8008
/*  f16b3cc:	24c645d8 */ 	addiu	$a2,$a2,0x45d8
/*  f16b3d0:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f16b3d4:	02e03825 */ 	move	$a3,$s7
/*  f16b3d8:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16b3dc:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16b3e0:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16b3e4:	0c0041a0 */ 	jal	0x10680
/*  f16b3e8:	afb7001c */ 	sw	$s7,0x1c($sp)
.PF0f16b3ec:
/*  f16b3ec:	3c188008 */ 	lui	$t8,0x8008
/*  f16b3f0:	8f1845dc */ 	lw	$t8,0x45dc($t8)
/*  f16b3f4:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f16b3f8:	3c018008 */ 	lui	$at,0x8008
/*  f16b3fc:	030b6823 */ 	subu	$t5,$t8,$t3
/*  f16b400:	05a1000b */ 	bgez	$t5,.PF0f16b430
/*  f16b404:	ac2d45dc */ 	sw	$t5,0x45dc($at)
/*  f16b408:	0c004ad4 */ 	jal	0x12b50
/*  f16b40c:	00000000 */ 	nop
/*  f16b410:	240100a6 */ 	li	$at,0xa6
/*  f16b414:	0041001b */ 	divu	$zero,$v0,$at
/*  f16b418:	0000c810 */ 	mfhi	$t9
/*  f16b41c:	272c0021 */ 	addiu	$t4,$t9,0x21
/*  f16b420:	3c018008 */ 	lui	$at,0x8008
/*  f16b424:	ac2c45dc */ 	sw	$t4,0x45dc($at)
/*  f16b428:	3c018008 */ 	lui	$at,0x8008
/*  f16b42c:	a02045e0 */ 	sb	$zero,0x45e0($at)
.PF0f16b430:
/*  f16b430:	02602025 */ 	move	$a0,$s3
/*  f16b434:	2405ffff */ 	li	$a1,-1
/*  f16b438:	0fc50d3f */ 	jal	0xf1434fc
/*  f16b43c:	2406ffff */ 	li	$a2,-1
/*  f16b440:	3c0e8008 */ 	lui	$t6,0x8008
/*  f16b444:	8dce45dc */ 	lw	$t6,0x45dc($t6)
/*  f16b448:	00409825 */ 	move	$s3,$v0
/*  f16b44c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f16b450:	29c1000c */ 	slti	$at,$t6,0xc
/*  f16b454:	10200017 */ 	beqz	$at,.PF0f16b4b4
/*  f16b458:	00000000 */ 	nop
/*  f16b45c:	91ef45e0 */ 	lbu	$t7,0x45e0($t7)
/*  f16b460:	240a0001 */ 	li	$t2,0x1
/*  f16b464:	3c018008 */ 	lui	$at,0x8008
/*  f16b468:	15e0000b */ 	bnez	$t7,.PF0f16b498
/*  f16b46c:	3c048009 */ 	lui	$a0,0x8009
/*  f16b470:	a02a45e0 */ 	sb	$t2,0x45e0($at)
/*  f16b474:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f16b478:	2405059e */ 	li	$a1,0x59e
/*  f16b47c:	00003025 */ 	move	$a2,$zero
/*  f16b480:	02e03825 */ 	move	$a3,$s7
/*  f16b484:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16b488:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16b48c:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16b490:	0c0041a0 */ 	jal	0x10680
/*  f16b494:	afb7001c */ 	sw	$s7,0x1c($sp)
.PF0f16b498:
/*  f16b498:	3c188008 */ 	lui	$t8,0x8008
/*  f16b49c:	8f1845dc */ 	lw	$t8,0x45dc($t8)
/*  f16b4a0:	240d00e1 */ 	li	$t5,0xe1
/*  f16b4a4:	00185880 */ 	sll	$t3,$t8,0x2
/*  f16b4a8:	01785823 */ 	subu	$t3,$t3,$t8
/*  f16b4ac:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f16b4b0:	01ab8023 */ 	subu	$s0,$t5,$t3
.PF0f16b4b4:
/*  f16b4b4:	0c004ad4 */ 	jal	0x12b50
/*  f16b4b8:	00000000 */ 	nop
/*  f16b4bc:	2401003c */ 	li	$at,0x3c
/*  f16b4c0:	0041001b */ 	divu	$zero,$v0,$at
/*  f16b4c4:	0000c810 */ 	mfhi	$t9
/*  f16b4c8:	24010001 */ 	li	$at,0x1
/*  f16b4cc:	1721000b */ 	bne	$t9,$at,.PF0f16b4fc
/*  f16b4d0:	3c048009 */ 	lui	$a0,0x8009
/*  f16b4d4:	241000ff */ 	li	$s0,0xff
/*  f16b4d8:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f16b4dc:	2405059d */ 	li	$a1,0x59d
/*  f16b4e0:	00003025 */ 	move	$a2,$zero
/*  f16b4e4:	02e03825 */ 	move	$a3,$s7
/*  f16b4e8:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16b4ec:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16b4f0:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16b4f4:	0c0041a0 */ 	jal	0x10680
/*  f16b4f8:	afb7001c */ 	sw	$s7,0x1c($sp)
.PF0f16b4fc:
/*  f16b4fc:	12000005 */ 	beqz	$s0,.PF0f16b514
/*  f16b500:	02602025 */ 	move	$a0,$s3
/*  f16b504:	2405ffff */ 	li	$a1,-1
/*  f16b508:	0fc50c6d */ 	jal	0xf1431b4
/*  f16b50c:	02003025 */ 	move	$a2,$s0
/*  f16b510:	00409825 */ 	move	$s3,$v0
.PF0f16b514:
/*  f16b514:	3c048008 */ 	lui	$a0,0x8008
/*  f16b518:	8c8445d8 */ 	lw	$a0,0x45d8($a0)
/*  f16b51c:	50800006 */ 	beqzl	$a0,.PF0f16b538
/*  f16b520:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16b524:	56200004 */ 	bnezl	$s1,.PF0f16b538
/*  f16b528:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16b52c:	0c00cd09 */ 	jal	0x33424
/*  f16b530:	00000000 */ 	nop
/*  f16b534:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16b538:
/*  f16b538:	24010002 */ 	li	$at,0x2
/*  f16b53c:	960c0010 */ 	lhu	$t4,0x10($s0)
/*  f16b540:	5581001c */ 	bnel	$t4,$at,.PF0f16b5b4
/*  f16b544:	96030010 */ 	lhu	$v1,0x10($s0)
/*  f16b548:	8e4e02ac */ 	lw	$t6,0x2ac($s2)
/*  f16b54c:	24010006 */ 	li	$at,0x6
/*  f16b550:	02602025 */ 	move	$a0,$s3
/*  f16b554:	11c10016 */ 	beq	$t6,$at,.PF0f16b5b0
/*  f16b558:	2405ffff */ 	li	$a1,-1
/*  f16b55c:	0fc50cb9 */ 	jal	0xf1432e4
/*  f16b560:	2406ffff */ 	li	$a2,-1
/*  f16b564:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16b568:	00409825 */ 	move	$s3,$v0
/*  f16b56c:	2401004b */ 	li	$at,0x4b
/*  f16b570:	8e0300c8 */ 	lw	$v1,0xc8($s0)
/*  f16b574:	02602025 */ 	move	$a0,$s3
/*  f16b578:	3c054fff */ 	lui	$a1,0x4fff
/*  f16b57c:	1860000c */ 	blez	$v1,.PF0f16b5b0
/*  f16b580:	00033200 */ 	sll	$a2,$v1,0x8
/*  f16b584:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f16b588:	00c1001a */ 	div	$zero,$a2,$at
/*  f16b58c:	00003012 */ 	mflo	$a2
/*  f16b590:	2cc10100 */ 	sltiu	$at,$a2,0x100
/*  f16b594:	14200002 */ 	bnez	$at,.PF0f16b5a0
/*  f16b598:	00000000 */ 	nop
/*  f16b59c:	240600ff */ 	li	$a2,0xff
.PF0f16b5a0:
/*  f16b5a0:	0fc50c6d */ 	jal	0xf1431b4
/*  f16b5a4:	34a5ffff */ 	ori	$a1,$a1,0xffff
/*  f16b5a8:	00409825 */ 	move	$s3,$v0
/*  f16b5ac:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16b5b0:
/*  f16b5b0:	96030010 */ 	lhu	$v1,0x10($s0)
.PF0f16b5b4:
/*  f16b5b4:	24010003 */ 	li	$at,0x3
/*  f16b5b8:	02602025 */ 	move	$a0,$s3
/*  f16b5bc:	14610009 */ 	bne	$v1,$at,.PF0f16b5e4
/*  f16b5c0:	3c054fff */ 	lui	$a1,0x4fff
/*  f16b5c4:	34a5ffff */ 	ori	$a1,$a1,0xffff
/*  f16b5c8:	0fc50c6d */ 	jal	0xf1431b4
/*  f16b5cc:	240600ff */ 	li	$a2,0xff
/*  f16b5d0:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f16b5d4:	00409825 */ 	move	$s3,$v0
/*  f16b5d8:	a5400010 */ 	sh	$zero,0x10($t2)
/*  f16b5dc:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16b5e0:	96030010 */ 	lhu	$v1,0x10($s0)
.PF0f16b5e4:
/*  f16b5e4:	57c3001f */ 	bnel	$s8,$v1,.PF0f16b664
/*  f16b5e8:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f16b5ec:	8e5802ac */ 	lw	$t8,0x2ac($s2)
/*  f16b5f0:	24010006 */ 	li	$at,0x6
/*  f16b5f4:	5301001b */ 	beql	$t8,$at,.PF0f16b664
/*  f16b5f8:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f16b5fc:	8e020254 */ 	lw	$v0,0x254($s0)
/*  f16b600:	24060063 */ 	li	$a2,0x63
/*  f16b604:	240c00f9 */ 	li	$t4,0xf9
/*  f16b608:	284100a6 */ 	slti	$at,$v0,0xa6
/*  f16b60c:	1020000c */ 	beqz	$at,.PF0f16b640
/*  f16b610:	00026880 */ 	sll	$t5,$v0,0x2
/*  f16b614:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f16b618:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f16b61c:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f16b620:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f16b624:	01a26821 */ 	addu	$t5,$t5,$v0
/*  f16b628:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f16b62c:	24010032 */ 	li	$at,0x32
/*  f16b630:	01a1001a */ 	div	$zero,$t5,$at
/*  f16b634:	00005812 */ 	mflo	$t3
/*  f16b638:	000bc883 */ 	sra	$t9,$t3,0x2
/*  f16b63c:	01993023 */ 	subu	$a2,$t4,$t9
.PF0f16b640:
/*  f16b640:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b644:	c4208e64 */ 	lwc1	$f0,-0x719c($at)
/*  f16b648:	02602025 */ 	move	$a0,$s3
/*  f16b64c:	2405ffff */ 	li	$a1,-1
/*  f16b650:	44070000 */ 	mfc1	$a3,$f0
/*  f16b654:	0fc50dd8 */ 	jal	0xf143760
/*  f16b658:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f16b65c:	00409825 */ 	move	$s3,$v0
/*  f16b660:	8e430460 */ 	lw	$v1,0x460($s2)
.PF0f16b664:
/*  f16b664:	18600003 */ 	blez	$v1,.PF0f16b674
/*  f16b668:	2861001a */ 	slti	$at,$v1,0x1a
/*  f16b66c:	5420000c */ 	bnezl	$at,.PF0f16b6a0
/*  f16b670:	2401001a */ 	li	$at,0x1a
.PF0f16b674:
/*  f16b674:	8e420464 */ 	lw	$v0,0x464($s2)
/*  f16b678:	10400004 */ 	beqz	$v0,.PF0f16b68c
/*  f16b67c:	00000000 */ 	nop
/*  f16b680:	8e4e0468 */ 	lw	$t6,0x468($s2)
/*  f16b684:	51c00006 */ 	beqzl	$t6,.PF0f16b6a0
/*  f16b688:	2401001a */ 	li	$at,0x1a
.PF0f16b68c:
/*  f16b68c:	54400085 */ 	bnezl	$v0,.PF0f16b8a4
/*  f16b690:	2861000e */ 	slti	$at,$v1,0xe
/*  f16b694:	8e4f0468 */ 	lw	$t7,0x468($s2)
/*  f16b698:	11e00081 */ 	beqz	$t7,.PF0f16b8a0
/*  f16b69c:	2401001a */ 	li	$at,0x1a
.PF0f16b6a0:
/*  f16b6a0:	54610018 */ 	bnel	$v1,$at,.PF0f16b704
/*  f16b6a4:	2861000d */ 	slti	$at,$v1,0xd
/*  f16b6a8:	8e4a0464 */ 	lw	$t2,0x464($s2)
/*  f16b6ac:	55400015 */ 	bnezl	$t2,.PF0f16b704
/*  f16b6b0:	2861000d */ 	slti	$at,$v1,0xd
/*  f16b6b4:	0fc5b180 */ 	jal	0xf16c600
/*  f16b6b8:	00000000 */ 	nop
/*  f16b6bc:	10400003 */ 	beqz	$v0,.PF0f16b6cc
/*  f16b6c0:	3c048009 */ 	lui	$a0,0x8009
/*  f16b6c4:	10000002 */ 	b	.PF0f16b6d0
/*  f16b6c8:	241005c9 */ 	li	$s0,0x5c9
.PF0f16b6cc:
/*  f16b6cc:	241002ad */ 	li	$s0,0x2ad
.PF0f16b6d0:
/*  f16b6d0:	00102c00 */ 	sll	$a1,$s0,0x10
/*  f16b6d4:	0005c403 */ 	sra	$t8,$a1,0x10
/*  f16b6d8:	03002825 */ 	move	$a1,$t8
/*  f16b6dc:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f16b6e0:	00003025 */ 	move	$a2,$zero
/*  f16b6e4:	02e03825 */ 	move	$a3,$s7
/*  f16b6e8:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16b6ec:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16b6f0:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16b6f4:	0c0041a0 */ 	jal	0x10680
/*  f16b6f8:	afb7001c */ 	sw	$s7,0x1c($sp)
/*  f16b6fc:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f16b700:	2861000d */ 	slti	$at,$v1,0xd
.PF0f16b704:
/*  f16b704:	10200026 */ 	beqz	$at,.PF0f16b7a0
/*  f16b708:	240c001a */ 	li	$t4,0x1a
/*  f16b70c:	2401000d */ 	li	$at,0xd
/*  f16b710:	00033080 */ 	sll	$a2,$v1,0x2
/*  f16b714:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f16b718:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16b71c:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f16b720:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16b724:	00c33021 */ 	addu	$a2,$a2,$v1
/*  f16b728:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16b72c:	00c1001a */ 	div	$zero,$a2,$at
/*  f16b730:	44833000 */ 	mtc1	$v1,$f6
/*  f16b734:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b738:	c42a8e68 */ 	lwc1	$f10,-0x7198($at)
/*  f16b73c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f16b740:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b744:	c4328e6c */ 	lwc1	$f18,-0x7194($at)
/*  f16b748:	00003012 */ 	mflo	$a2
/*  f16b74c:	02602025 */ 	move	$a0,$s3
/*  f16b750:	2405ffff */ 	li	$a1,-1
/*  f16b754:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f16b758:	46128000 */ 	add.s	$f0,$f16,$f18
/*  f16b75c:	44070000 */ 	mfc1	$a3,$f0
/*  f16b760:	0fc50dd8 */ 	jal	0xf143760
/*  f16b764:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f16b768:	8e4b0460 */ 	lw	$t3,0x460($s2)
/*  f16b76c:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b770:	c4288e70 */ 	lwc1	$f8,-0x7190($at)
/*  f16b774:	448b2000 */ 	mtc1	$t3,$f4
/*  f16b778:	00402025 */ 	move	$a0,$v0
/*  f16b77c:	240500ff */ 	li	$a1,0xff
/*  f16b780:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f16b784:	240600ff */ 	li	$a2,0xff
/*  f16b788:	240700ff */ 	li	$a3,0xff
/*  f16b78c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f16b790:	0fc2ed6b */ 	jal	0xf0bb5ac
/*  f16b794:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f16b798:	10000029 */ 	b	.PF0f16b840
/*  f16b79c:	00409825 */ 	move	$s3,$v0
.PF0f16b7a0:
/*  f16b7a0:	2401000d */ 	li	$at,0xd
/*  f16b7a4:	01831023 */ 	subu	$v0,$t4,$v1
/*  f16b7a8:	00023080 */ 	sll	$a2,$v0,0x2
/*  f16b7ac:	00c23023 */ 	subu	$a2,$a2,$v0
/*  f16b7b0:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16b7b4:	00c23023 */ 	subu	$a2,$a2,$v0
/*  f16b7b8:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16b7bc:	00c23021 */ 	addu	$a2,$a2,$v0
/*  f16b7c0:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16b7c4:	00c1001a */ 	div	$zero,$a2,$at
/*  f16b7c8:	44828000 */ 	mtc1	$v0,$f16
/*  f16b7cc:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b7d0:	c4248e74 */ 	lwc1	$f4,-0x718c($at)
/*  f16b7d4:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f16b7d8:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b7dc:	c4288e78 */ 	lwc1	$f8,-0x7188($at)
/*  f16b7e0:	00003012 */ 	mflo	$a2
/*  f16b7e4:	02602025 */ 	move	$a0,$s3
/*  f16b7e8:	2405ffff */ 	li	$a1,-1
/*  f16b7ec:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f16b7f0:	46083000 */ 	add.s	$f0,$f6,$f8
/*  f16b7f4:	44070000 */ 	mfc1	$a3,$f0
/*  f16b7f8:	0fc50dd8 */ 	jal	0xf143760
/*  f16b7fc:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f16b800:	8e4e0460 */ 	lw	$t6,0x460($s2)
/*  f16b804:	3c0141d0 */ 	lui	$at,0x41d0
/*  f16b808:	44815000 */ 	mtc1	$at,$f10
/*  f16b80c:	448e8000 */ 	mtc1	$t6,$f16
/*  f16b810:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b814:	c4268e7c */ 	lwc1	$f6,-0x7184($at)
/*  f16b818:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f16b81c:	00402025 */ 	move	$a0,$v0
/*  f16b820:	240500ff */ 	li	$a1,0xff
/*  f16b824:	240600ff */ 	li	$a2,0xff
/*  f16b828:	240700ff */ 	li	$a3,0xff
/*  f16b82c:	46125101 */ 	sub.s	$f4,$f10,$f18
/*  f16b830:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f16b834:	0fc2ed6b */ 	jal	0xf0bb5ac
/*  f16b838:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f16b83c:	00409825 */ 	move	$s3,$v0
.PF0f16b840:
/*  f16b840:	8e4f028c */ 	lw	$t7,0x28c($s2)
/*  f16b844:	55e0000c */ 	bnezl	$t7,.PF0f16b878
/*  f16b848:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f16b84c:	8e4a0464 */ 	lw	$t2,0x464($s2)
/*  f16b850:	51400006 */ 	beqzl	$t2,.PF0f16b86c
/*  f16b854:	8e4b0460 */ 	lw	$t3,0x460($s2)
/*  f16b858:	8e580460 */ 	lw	$t8,0x460($s2)
/*  f16b85c:	270d0001 */ 	addiu	$t5,$t8,0x1
/*  f16b860:	10000004 */ 	b	.PF0f16b874
/*  f16b864:	ae4d0460 */ 	sw	$t5,0x460($s2)
/*  f16b868:	8e4b0460 */ 	lw	$t3,0x460($s2)
.PF0f16b86c:
/*  f16b86c:	256cffff */ 	addiu	$t4,$t3,-1
/*  f16b870:	ae4c0460 */ 	sw	$t4,0x460($s2)
.PF0f16b874:
/*  f16b874:	8e430460 */ 	lw	$v1,0x460($s2)
.PF0f16b878:
/*  f16b878:	2861001b */ 	slti	$at,$v1,0x1b
/*  f16b87c:	14200004 */ 	bnez	$at,.PF0f16b890
/*  f16b880:	00000000 */ 	nop
/*  f16b884:	2403001a */ 	li	$v1,0x1a
/*  f16b888:	10000005 */ 	b	.PF0f16b8a0
/*  f16b88c:	ae430460 */ 	sw	$v1,0x460($s2)
.PF0f16b890:
/*  f16b890:	04630004 */ 	bgezl	$v1,.PF0f16b8a4
/*  f16b894:	2861000e */ 	slti	$at,$v1,0xe
/*  f16b898:	ae400460 */ 	sw	$zero,0x460($s2)
/*  f16b89c:	00001825 */ 	move	$v1,$zero
.PF0f16b8a0:
/*  f16b8a0:	2861000e */ 	slti	$at,$v1,0xe
.PF0f16b8a4:
/*  f16b8a4:	54200004 */ 	bnezl	$at,.PF0f16b8b8
/*  f16b8a8:	ae400468 */ 	sw	$zero,0x468($s2)
/*  f16b8ac:	10000002 */ 	b	.PF0f16b8b8
/*  f16b8b0:	ae5e0468 */ 	sw	$s8,0x468($s2)
/*  f16b8b4:	ae400468 */ 	sw	$zero,0x468($s2)
.PF0f16b8b8:
/*  f16b8b8:	52800009 */ 	beqzl	$s4,.PF0f16b8e0
/*  f16b8bc:	8e4e02ac */ 	lw	$t6,0x2ac($s2)
/*  f16b8c0:	0fc52608 */ 	jal	0xf149820
/*  f16b8c4:	00000000 */ 	nop
/*  f16b8c8:	02602025 */ 	move	$a0,$s3
/*  f16b8cc:	2405ffff */ 	li	$a1,-1
/*  f16b8d0:	0fc50bea */ 	jal	0xf142fa8
/*  f16b8d4:	02803025 */ 	move	$a2,$s4
/*  f16b8d8:	00409825 */ 	move	$s3,$v0
/*  f16b8dc:	8e4e02ac */ 	lw	$t6,0x2ac($s2)
.PF0f16b8e0:
/*  f16b8e0:	24010006 */ 	li	$at,0x6
/*  f16b8e4:	15c10031 */ 	bne	$t6,$at,.PF0f16b9ac
/*  f16b8e8:	00000000 */ 	nop
/*  f16b8ec:	0fc2eb66 */ 	jal	0xf0bad98
/*  f16b8f0:	00000000 */ 	nop
/*  f16b8f4:	44808000 */ 	mtc1	$zero,$f16
/*  f16b8f8:	3c01437f */ 	lui	$at,0x437f
/*  f16b8fc:	4600803c */ 	c.lt.s	$f16,$f0
/*  f16b900:	00000000 */ 	nop
/*  f16b904:	45000029 */ 	bc1f	.PF0f16b9ac
/*  f16b908:	00000000 */ 	nop
/*  f16b90c:	44815000 */ 	mtc1	$at,$f10
/*  f16b910:	24060001 */ 	li	$a2,0x1
/*  f16b914:	3c014f00 */ 	lui	$at,0x4f00
/*  f16b918:	460a0482 */ 	mul.s	$f18,$f0,$f10
/*  f16b91c:	02602025 */ 	move	$a0,$s3
/*  f16b920:	2405ff00 */ 	li	$a1,-256
/*  f16b924:	444ff800 */ 	cfc1	$t7,$31
/*  f16b928:	44c6f800 */ 	ctc1	$a2,$31
/*  f16b92c:	00000000 */ 	nop
/*  f16b930:	46009124 */ 	cvt.w.s	$f4,$f18
/*  f16b934:	4446f800 */ 	cfc1	$a2,$31
/*  f16b938:	00000000 */ 	nop
/*  f16b93c:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f16b940:	50c00013 */ 	beqzl	$a2,.PF0f16b990
/*  f16b944:	44062000 */ 	mfc1	$a2,$f4
/*  f16b948:	44812000 */ 	mtc1	$at,$f4
/*  f16b94c:	24060001 */ 	li	$a2,0x1
/*  f16b950:	46049101 */ 	sub.s	$f4,$f18,$f4
/*  f16b954:	44c6f800 */ 	ctc1	$a2,$31
/*  f16b958:	00000000 */ 	nop
/*  f16b95c:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f16b960:	4446f800 */ 	cfc1	$a2,$31
/*  f16b964:	00000000 */ 	nop
/*  f16b968:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f16b96c:	14c00005 */ 	bnez	$a2,.PF0f16b984
/*  f16b970:	00000000 */ 	nop
/*  f16b974:	44062000 */ 	mfc1	$a2,$f4
/*  f16b978:	3c018000 */ 	lui	$at,0x8000
/*  f16b97c:	10000007 */ 	b	.PF0f16b99c
/*  f16b980:	00c13025 */ 	or	$a2,$a2,$at
.PF0f16b984:
/*  f16b984:	10000005 */ 	b	.PF0f16b99c
/*  f16b988:	2406ffff */ 	li	$a2,-1
/*  f16b98c:	44062000 */ 	mfc1	$a2,$f4
.PF0f16b990:
/*  f16b990:	00000000 */ 	nop
/*  f16b994:	04c0fffb */ 	bltz	$a2,.PF0f16b984
/*  f16b998:	00000000 */ 	nop
.PF0f16b99c:
/*  f16b99c:	44cff800 */ 	ctc1	$t7,$31
/*  f16b9a0:	0fc50bea */ 	jal	0xf142fa8
/*  f16b9a4:	00000000 */ 	nop
/*  f16b9a8:	00409825 */ 	move	$s3,$v0
.PF0f16b9ac:
/*  f16b9ac:	0fc47e76 */ 	jal	0xf11f9d8
/*  f16b9b0:	00000000 */ 	nop
/*  f16b9b4:	145e0006 */ 	bne	$v0,$s8,.PF0f16b9d0
/*  f16b9b8:	02602025 */ 	move	$a0,$s3
/*  f16b9bc:	2405ff00 */ 	li	$a1,-256
/*  f16b9c0:	0fc50bea */ 	jal	0xf142fa8
/*  f16b9c4:	24060080 */ 	li	$a2,0x80
/*  f16b9c8:	10000014 */ 	b	.PF0f16ba1c
/*  f16b9cc:	00409825 */ 	move	$s3,$v0
.PF0f16b9d0:
/*  f16b9d0:	0fc47e76 */ 	jal	0xf11f9d8
/*  f16b9d4:	00000000 */ 	nop
/*  f16b9d8:	24010002 */ 	li	$at,0x2
/*  f16b9dc:	14410006 */ 	bne	$v0,$at,.PF0f16b9f8
/*  f16b9e0:	02602025 */ 	move	$a0,$s3
/*  f16b9e4:	2405ff00 */ 	li	$a1,-256
/*  f16b9e8:	0fc50bea */ 	jal	0xf142fa8
/*  f16b9ec:	240600c0 */ 	li	$a2,0xc0
/*  f16b9f0:	1000000a */ 	b	.PF0f16ba1c
/*  f16b9f4:	00409825 */ 	move	$s3,$v0
.PF0f16b9f8:
/*  f16b9f8:	0fc47e76 */ 	jal	0xf11f9d8
/*  f16b9fc:	00000000 */ 	nop
/*  f16ba00:	24010003 */ 	li	$at,0x3
/*  f16ba04:	14410005 */ 	bne	$v0,$at,.PF0f16ba1c
/*  f16ba08:	02602025 */ 	move	$a0,$s3
/*  f16ba0c:	2405ff00 */ 	li	$a1,-256
/*  f16ba10:	0fc50bea */ 	jal	0xf142fa8
/*  f16ba14:	240600e6 */ 	li	$a2,0xe6
/*  f16ba18:	00409825 */ 	move	$s3,$v0
.PF0f16ba1c:
/*  f16ba1c:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16ba20:	24010003 */ 	li	$at,0x3
/*  f16ba24:	92031bfc */ 	lbu	$v1,0x1bfc($s0)
/*  f16ba28:	1860003c */ 	blez	$v1,.PF0f16bb1c
/*  f16ba2c:	00000000 */ 	nop
/*  f16ba30:	14610002 */ 	bne	$v1,$at,.PF0f16ba3c
/*  f16ba34:	00008825 */ 	move	$s1,$zero
/*  f16ba38:	241100ff */ 	li	$s1,0xff
.PF0f16ba3c:
/*  f16ba3c:	56a30009 */ 	bnel	$s5,$v1,.PF0f16ba64
/*  f16ba40:	24010002 */ 	li	$at,0x2
/*  f16ba44:	92021bfd */ 	lbu	$v0,0x1bfd($s0)
/*  f16ba48:	28410010 */ 	slti	$at,$v0,0x10
/*  f16ba4c:	50200005 */ 	beqzl	$at,.PF0f16ba64
/*  f16ba50:	24010002 */ 	li	$at,0x2
/*  f16ba54:	00028823 */ 	negu	$s1,$v0
/*  f16ba58:	00115100 */ 	sll	$t2,$s1,0x4
/*  f16ba5c:	255100f0 */ 	addiu	$s1,$t2,0xf0
/*  f16ba60:	24010002 */ 	li	$at,0x2
.PF0f16ba64:
/*  f16ba64:	1461000b */ 	bne	$v1,$at,.PF0f16ba94
/*  f16ba68:	00000000 */ 	nop
/*  f16ba6c:	92021bfd */ 	lbu	$v0,0x1bfd($s0)
/*  f16ba70:	28410021 */ 	slti	$at,$v0,0x21
/*  f16ba74:	54200004 */ 	bnezl	$at,.PF0f16ba88
/*  f16ba78:	24010030 */ 	li	$at,0x30
/*  f16ba7c:	00028900 */ 	sll	$s1,$v0,0x4
/*  f16ba80:	2631fe00 */ 	addiu	$s1,$s1,-512
/*  f16ba84:	24010030 */ 	li	$at,0x30
.PF0f16ba88:
/*  f16ba88:	14410002 */ 	bne	$v0,$at,.PF0f16ba94
/*  f16ba8c:	00000000 */ 	nop
/*  f16ba90:	241100ff */ 	li	$s1,0xff
.PF0f16ba94:
/*  f16ba94:	12200021 */ 	beqz	$s1,.PF0f16bb1c
/*  f16ba98:	00000000 */ 	nop
/*  f16ba9c:	0fc550cf */ 	jal	0xf15433c
/*  f16baa0:	02602025 */ 	move	$a0,$s3
/*  f16baa4:	0c002e91 */ 	jal	0xba44
/*  f16baa8:	00409825 */ 	move	$s3,$v0
/*  f16baac:	0c002e95 */ 	jal	0xba54
/*  f16bab0:	a7a20072 */ 	sh	$v0,0x72($sp)
/*  f16bab4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f16bab8:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f16babc:	0c002e91 */ 	jal	0xba44
/*  f16bac0:	03008025 */ 	move	$s0,$t8
/*  f16bac4:	0c002e73 */ 	jal	0xb9cc
/*  f16bac8:	a7a20076 */ 	sh	$v0,0x76($sp)
/*  f16bacc:	0c002e95 */ 	jal	0xba54
/*  f16bad0:	a7a2008e */ 	sh	$v0,0x8e($sp)
/*  f16bad4:	0c002e77 */ 	jal	0xb9dc
/*  f16bad8:	a7a20090 */ 	sh	$v0,0x90($sp)
/*  f16badc:	87ac0090 */ 	lh	$t4,0x90($sp)
/*  f16bae0:	87ad008e */ 	lh	$t5,0x8e($sp)
/*  f16bae4:	87ab0076 */ 	lh	$t3,0x76($sp)
/*  f16bae8:	2401ff00 */ 	li	$at,-256
/*  f16baec:	02217025 */ 	or	$t6,$s1,$at
/*  f16baf0:	004cc821 */ 	addu	$t9,$v0,$t4
/*  f16baf4:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f16baf8:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f16bafc:	02602025 */ 	move	$a0,$s3
/*  f16bb00:	87a50072 */ 	lh	$a1,0x72($sp)
/*  f16bb04:	02003025 */ 	move	$a2,$s0
/*  f16bb08:	0fc551d2 */ 	jal	0xf154748
/*  f16bb0c:	01ab3821 */ 	addu	$a3,$t5,$t3
/*  f16bb10:	0fc55125 */ 	jal	0xf154494
/*  f16bb14:	00402025 */ 	move	$a0,$v0
/*  f16bb18:	00409825 */ 	move	$s3,$v0
.PF0f16bb1c:
/*  f16bb1c:	0fc619de */ 	jal	0xf186778
/*  f16bb20:	02602025 */ 	move	$a0,$s3
/*  f16bb24:	0fc5a557 */ 	jal	0xf16955c
/*  f16bb28:	00402025 */ 	move	$a0,$v0
/*  f16bb2c:	3c0f8009 */ 	lui	$t7,0x8009
/*  f16bb30:	91ef8d54 */ 	lbu	$t7,-0x72ac($t7)
/*  f16bb34:	00409825 */ 	move	$s3,$v0
/*  f16bb38:	11e00004 */ 	beqz	$t7,.PF0f16bb4c
/*  f16bb3c:	00000000 */ 	nop
/*  f16bb40:	0fc69012 */ 	jal	0xf1a4048
/*  f16bb44:	00402025 */ 	move	$a0,$v0
/*  f16bb48:	00409825 */ 	move	$s3,$v0
.PF0f16bb4c:
/*  f16bb4c:	0fc47e62 */ 	jal	0xf11f988
/*  f16bb50:	00000000 */ 	nop
/*  f16bb54:	14400013 */ 	bnez	$v0,.PF0f16bba4
/*  f16bb58:	00000000 */ 	nop
/*  f16bb5c:	0fc47e64 */ 	jal	0xf11f990
/*  f16bb60:	00000000 */ 	nop
/*  f16bb64:	1440000f */ 	bnez	$v0,.PF0f16bba4
/*  f16bb68:	00000000 */ 	nop
/*  f16bb6c:	0fc47e6a */ 	jal	0xf11f9a8
/*  f16bb70:	00000000 */ 	nop
/*  f16bb74:	1440000b */ 	bnez	$v0,.PF0f16bba4
/*  f16bb78:	00000000 */ 	nop
/*  f16bb7c:	0fc47ea0 */ 	jal	0xf11fa80
/*  f16bb80:	00000000 */ 	nop
/*  f16bb84:	14400007 */ 	bnez	$v0,.PF0f16bba4
/*  f16bb88:	00000000 */ 	nop
/*  f16bb8c:	0fc47e9e */ 	jal	0xf11fa78
/*  f16bb90:	00000000 */ 	nop
/*  f16bb94:	14400003 */ 	bnez	$v0,.PF0f16bba4
/*  f16bb98:	00000000 */ 	nop
/*  f16bb9c:	0fc47e50 */ 	jal	0xf11f940
/*  f16bba0:	00000000 */ 	nop
.PF0f16bba4:
/*  f16bba4:	0fc49fea */ 	jal	0xf127fa8
/*  f16bba8:	02602025 */ 	move	$a0,$s3
/*  f16bbac:	0fc40494 */ 	jal	0xf101250
/*  f16bbb0:	00402025 */ 	move	$a0,$v0
/*  f16bbb4:	3c013f80 */ 	lui	$at,0x3f80
/*  f16bbb8:	44816000 */ 	mtc1	$at,$f12
/*  f16bbbc:	0c005936 */ 	jal	0x164d8
/*  f16bbc0:	00409825 */ 	move	$s3,$v0
/*  f16bbc4:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f16bbc8:	8d581c50 */ 	lw	$t8,0x1c50($t2)
/*  f16bbcc:	00186fc2 */ 	srl	$t5,$t8,0x1f
/*  f16bbd0:	51a00005 */ 	beqzl	$t5,.PF0f16bbe8
/*  f16bbd4:	8e4b0288 */ 	lw	$t3,0x288($s2)
/*  f16bbd8:	0fc3f0f0 */ 	jal	0xf0fc3c0
/*  f16bbdc:	02602025 */ 	move	$a0,$s3
/*  f16bbe0:	00409825 */ 	move	$s3,$v0
/*  f16bbe4:	8e4b0288 */ 	lw	$t3,0x288($s2)
.PF0f16bbe8:
/*  f16bbe8:	0c005936 */ 	jal	0x164d8
/*  f16bbec:	c56c0074 */ 	lwc1	$f12,0x74($t3)
/*  f16bbf0:	8e4c0314 */ 	lw	$t4,0x314($s2)
/*  f16bbf4:	51800005 */ 	beqzl	$t4,.PF0f16bc0c
/*  f16bbf8:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f16bbfc:	0fc629f8 */ 	jal	0xf18a7e0
/*  f16bc00:	02602025 */ 	move	$a0,$s3
/*  f16bc04:	00409825 */ 	move	$s3,$v0
/*  f16bc08:	8e590284 */ 	lw	$t9,0x284($s2)
.PF0f16bc0c:
/*  f16bc0c:	932e19b3 */ 	lbu	$t6,0x19b3($t9)
/*  f16bc10:	11c00003 */ 	beqz	$t6,.PF0f16bc20
/*  f16bc14:	00000000 */ 	nop
/*  f16bc18:	0fc2ddff */ 	jal	0xf0b77fc
/*  f16bc1c:	00000000 */ 	nop
.PF0f16bc20:
/*  f16bc20:	0fc4f42f */ 	jal	0xf13d0bc
/*  f16bc24:	00000000 */ 	nop
/*  f16bc28:	8e4f0298 */ 	lw	$t7,0x298($s2)
/*  f16bc2c:	05e10004 */ 	bgez	$t7,.PF0f16bc40
/*  f16bc30:	00000000 */ 	nop
/*  f16bc34:	8e4a029c */ 	lw	$t2,0x29c($s2)
/*  f16bc38:	0542000a */ 	bltzl	$t2,.PF0f16bc64
/*  f16bc3c:	8fb00064 */ 	lw	$s0,0x64($sp)
.PF0f16bc40:
/*  f16bc40:	0fc2f28f */ 	jal	0xf0bca3c
/*  f16bc44:	00000000 */ 	nop
/*  f16bc48:	50400006 */ 	beqzl	$v0,.PF0f16bc64
/*  f16bc4c:	8fb00064 */ 	lw	$s0,0x64($sp)
/*  f16bc50:	8e58028c */ 	lw	$t8,0x28c($s2)
/*  f16bc54:	53000003 */ 	beqzl	$t8,.PF0f16bc64
/*  f16bc58:	8fb00064 */ 	lw	$s0,0x64($sp)
/*  f16bc5c:	8fb30108 */ 	lw	$s3,0x108($sp)
/*  f16bc60:	8fb00064 */ 	lw	$s0,0x64($sp)
.PF0f16bc64:
/*  f16bc64:	8fad010c */ 	lw	$t5,0x10c($sp)
/*  f16bc68:	560dfb58 */ 	bnel	$s0,$t5,.PF0f16a9cc
/*  f16bc6c:	8fac0104 */ 	lw	$t4,0x104($sp)
.PF0f16bc70:
/*  f16bc70:	824b04d3 */ 	lb	$t3,0x4d3($s2)
.PF0f16bc74:
/*  f16bc74:	3c014080 */ 	lui	$at,0x4080
/*  f16bc78:	4481a000 */ 	mtc1	$at,$f20
/*  f16bc7c:	11600013 */ 	beqz	$t3,.PF0f16bccc
/*  f16bc80:	2417ffff */ 	li	$s7,-1
/*  f16bc84:	824c04d6 */ 	lb	$t4,0x4d6($s2)
/*  f16bc88:	51800011 */ 	beqzl	$t4,.PF0f16bcd0
/*  f16bc8c:	824a04d3 */ 	lb	$t2,0x4d3($s2)
/*  f16bc90:	825904d7 */ 	lb	$t9,0x4d7($s2)
/*  f16bc94:	a24004d3 */ 	sb	$zero,0x4d3($s2)
/*  f16bc98:	a24004d6 */ 	sb	$zero,0x4d6($s2)
/*  f16bc9c:	53200004 */ 	beqzl	$t9,.PF0f16bcb0
/*  f16bca0:	824e04d4 */ 	lb	$t6,0x4d4($s2)
/*  f16bca4:	a25704d4 */ 	sb	$s7,0x4d4($s2)
/*  f16bca8:	a24004d5 */ 	sb	$zero,0x4d5($s2)
/*  f16bcac:	824e04d4 */ 	lb	$t6,0x4d4($s2)
.PF0f16bcb0:
/*  f16bcb0:	05c30007 */ 	bgezl	$t6,.PF0f16bcd0
/*  f16bcb4:	824a04d3 */ 	lb	$t2,0x4d3($s2)
/*  f16bcb8:	824f04d5 */ 	lb	$t7,0x4d5($s2)
/*  f16bcbc:	5de00004 */ 	bgtzl	$t7,.PF0f16bcd0
/*  f16bcc0:	824a04d3 */ 	lb	$t2,0x4d3($s2)
/*  f16bcc4:	0c0039af */ 	jal	0xe6bc
/*  f16bcc8:	2404005a */ 	li	$a0,0x5a
.PF0f16bccc:
/*  f16bccc:	824a04d3 */ 	lb	$t2,0x4d3($s2)
.PF0f16bcd0:
/*  f16bcd0:	55400044 */ 	bnezl	$t2,.PF0f16bde4
/*  f16bcd4:	02608825 */ 	move	$s1,$s3
/*  f16bcd8:	825804d4 */ 	lb	$t8,0x4d4($s2)
/*  f16bcdc:	07020041 */ 	bltzl	$t8,.PF0f16bde4
/*  f16bce0:	02608825 */ 	move	$s1,$s3
/*  f16bce4:	824d04d5 */ 	lb	$t5,0x4d5($s2)
/*  f16bce8:	59a0003e */ 	blezl	$t5,.PF0f16bde4
/*  f16bcec:	02608825 */ 	move	$s1,$s3
/*  f16bcf0:	0fc37925 */ 	jal	0xf0de494
/*  f16bcf4:	00000000 */ 	nop
/*  f16bcf8:	824b04d4 */ 	lb	$t3,0x4d4($s2)
/*  f16bcfc:	3c118007 */ 	lui	$s1,0x8007
/*  f16bd00:	26313abc */ 	addiu	$s1,$s1,0x3abc
/*  f16bd04:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f16bd08:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f16bd0c:	3c10800a */ 	lui	$s0,0x800a
/*  f16bd10:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f16bd14:	2610e588 */ 	addiu	$s0,$s0,-6776
/*  f16bd18:	022cc821 */ 	addu	$t9,$s1,$t4
/*  f16bd1c:	8f2e0004 */ 	lw	$t6,0x4($t9)
/*  f16bd20:	920f0003 */ 	lbu	$t7,0x3($s0)
/*  f16bd24:	ae400314 */ 	sw	$zero,0x314($s2)
/*  f16bd28:	ae400318 */ 	sw	$zero,0x318($s2)
/*  f16bd2c:	31f8ff7f */ 	andi	$t8,$t7,0xff7f
/*  f16bd30:	a2180003 */ 	sb	$t8,0x3($s0)
/*  f16bd34:	330d00bf */ 	andi	$t5,$t8,0xbf
/*  f16bd38:	ae400294 */ 	sw	$zero,0x294($s2)
/*  f16bd3c:	ae570298 */ 	sw	$s7,0x298($s2)
/*  f16bd40:	ae57029c */ 	sw	$s7,0x29c($s2)
/*  f16bd44:	a20d0003 */ 	sb	$t5,0x3($s0)
/*  f16bd48:	24040001 */ 	li	$a0,0x1
/*  f16bd4c:	0fc0690e */ 	jal	0xf01a438
/*  f16bd50:	a24e04d2 */ 	sb	$t6,0x4d2($s2)
/*  f16bd54:	0fc06a32 */ 	jal	0xf01a8c8
/*  f16bd58:	24040005 */ 	li	$a0,0x5
/*  f16bd5c:	920b0000 */ 	lbu	$t3,0x0($s0)
/*  f16bd60:	00002025 */ 	move	$a0,$zero
/*  f16bd64:	316cff01 */ 	andi	$t4,$t3,0xff01
/*  f16bd68:	0fc5b6fd */ 	jal	0xf16dbf4
/*  f16bd6c:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f16bd70:	825904d4 */ 	lb	$t9,0x4d4($s2)
/*  f16bd74:	00197080 */ 	sll	$t6,$t9,0x2
/*  f16bd78:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f16bd7c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f16bd80:	022e1021 */ 	addu	$v0,$s1,$t6
/*  f16bd84:	844f0002 */ 	lh	$t7,0x2($v0)
/*  f16bd88:	84440000 */ 	lh	$a0,0x0($v0)
/*  f16bd8c:	a20f0002 */ 	sb	$t7,0x2($s0)
/*  f16bd90:	0fc06c91 */ 	jal	0xf01b244
/*  f16bd94:	a2040001 */ 	sb	$a0,0x1($s0)
/*  f16bd98:	824a04d4 */ 	lb	$t2,0x4d4($s2)
/*  f16bd9c:	000ac080 */ 	sll	$t8,$t2,0x2
/*  f16bda0:	030ac023 */ 	subu	$t8,$t8,$t2
/*  f16bda4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f16bda8:	02386821 */ 	addu	$t5,$s1,$t8
/*  f16bdac:	0c0039af */ 	jal	0xe6bc
/*  f16bdb0:	85a40000 */ 	lh	$a0,0x0($t5)
/*  f16bdb4:	824b04d5 */ 	lb	$t3,0x4d5($s2)
/*  f16bdb8:	256cffff */ 	addiu	$t4,$t3,-1
/*  f16bdbc:	a24c04d5 */ 	sb	$t4,0x4d5($s2)
/*  f16bdc0:	825904d5 */ 	lb	$t9,0x4d5($s2)
/*  f16bdc4:	5b200006 */ 	blezl	$t9,.PF0f16bde0
/*  f16bdc8:	a25704d4 */ 	sb	$s7,0x4d4($s2)
/*  f16bdcc:	824e04d4 */ 	lb	$t6,0x4d4($s2)
/*  f16bdd0:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f16bdd4:	10000002 */ 	b	.PF0f16bde0
/*  f16bdd8:	a24f04d4 */ 	sb	$t7,0x4d4($s2)
/*  f16bddc:	a25704d4 */ 	sb	$s7,0x4d4($s2)
.PF0f16bde0:
/*  f16bde0:	02608825 */ 	move	$s1,$s3
.PF0f16bde4:
/*  f16bde4:	3c0aed00 */ 	lui	$t2,0xed00
/*  f16bde8:	ae2a0000 */ 	sw	$t2,0x0($s1)
/*  f16bdec:	0c002e53 */ 	jal	0xb94c
/*  f16bdf0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16bdf4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f16bdf8:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f16bdfc:	0c002e57 */ 	jal	0xb95c
/*  f16be00:	03008025 */ 	move	$s0,$t8
/*  f16be04:	44823000 */ 	mtc1	$v0,$f6
/*  f16be08:	44909000 */ 	mtc1	$s0,$f18
/*  f16be0c:	02601025 */ 	move	$v0,$s3
/*  f16be10:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f16be14:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f16be18:	46144402 */ 	mul.s	$f16,$f8,$f20
/*  f16be1c:	00000000 */ 	nop
/*  f16be20:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f16be24:	4600828d */ 	trunc.w.s	$f10,$f16
/*  f16be28:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f16be2c:	440b5000 */ 	mfc1	$t3,$f10
/*  f16be30:	440e4000 */ 	mfc1	$t6,$f8
/*  f16be34:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f16be38:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f16be3c:	000f5300 */ 	sll	$t2,$t7,0xc
/*  f16be40:	018ac025 */ 	or	$t8,$t4,$t2
/*  f16be44:	ae380004 */ 	sw	$t8,0x4($s1)
/*  f16be48:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f16be4c:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f16be50:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f16be54:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f16be58:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f16be5c:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f16be60:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f16be64:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f16be68:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f16be6c:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f16be70:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f16be74:	03e00008 */ 	jr	$ra
/*  f16be78:	27bd0170 */ 	addiu	$sp,$sp,0x170
);
#else
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
Gfx *coreRender(Gfx *gdl)
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
		gdl = coreRenderFade(gdl);
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
		gdl = currentPlayerScissorToViewport(gdl);
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
		gdl = currentPlayerScissorToViewport(gdl);
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
		gdl = creditsRender(gdl);
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

			bviewSetBlur(bluramount);

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
			gdl = currentPlayerScissorToViewport(gdl);
			func0f13c510();

			if ((g_Vars.stagenum != STAGE_CITRAINING || (var80087260 <= 0 && g_MenuData.root != MENUROOT_MPSETUP))
					&& g_Vars.lvframenum <= 5
					&& !g_Vars.normmplayerisrunning
					&& g_Vars.tickmode != TICKMODE_CUTSCENE) {
				if (var80084050 < 6) {
					g_Vars.lockscreen = 1;
				}

				var80084050++;
			} else if (g_Vars.currentplayer->gunctrl.unk1583_06
					&& var80075d60 == 2
					&& g_Vars.currentplayer->cameramode != CAMERAMODE_THIRDPERSON
					&& g_Vars.currentplayer->cameramode != CAMERAMODE_EYESPY
					&& var8009dfc0 == 0) {
				g_Vars.currentplayer->gunctrl.unk1583_06 = func0f09eae4();
			}

			if (g_Vars.lockscreen) {
				gdl = bviewRenderMotionBlur(gdl, 0xffffffff, 255);
				g_Vars.lockscreen--;
			} else if (var8009dfc0) {
				gdl = func0000b330(gdl);
				gdl = currentPlayerScissorToViewport(gdl);
				func00016748(1);

				if (g_Vars.currentplayer->unk1c50_01) {
					gdl = func0f0fbc30(gdl);
				}
			} else {
				if (var80075d60 == 2) {
					gdl = currentPlayerUpdateShootRot(gdl);
				}

				gdl = func0000b330(gdl);
				gdl = func0f11f984(gdl);
				roomsTick();
				func0f004314();
				func0f06302c(islastplayer);
				scenarioCallback14(NULL);
				func0f0601b0();
				func0f064ce8();
				handsTickAttack();

				// Calculate lookingatprop
				if (PLAYERCOUNT() == 1
						|| g_Vars.coopplayernum >= 0
						|| g_Vars.antiplayernum >= 0
						|| (weaponHasFlag(handGetWeaponNum(HAND_RIGHT), WEAPONFLAG_AIMTRACK) && bmoveIsInSightAimMode())) {
					g_Vars.currentplayer->lookingatprop.prop = func0f061d54(HAND_RIGHT, 0, 0);

					if (g_Vars.currentplayer->lookingatprop.prop) {
						if (g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_CHR
								|| g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_PLAYER) {
							chr = g_Vars.currentplayer->lookingatprop.prop->chr;

							if (chr->hidden & CHRHFLAG_CLOAKED) {
								if (g_Vars.currentplayer->isdead
										|| g_InCutscene
										|| !EYESPYINACTIVE()
										|| (g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_IRSCANNER) == false) {
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

				if (handHasFunctionFlags(&g_Vars.currentplayer->hands[0].base, FUNCFLAG_00080000)) {
					coreFindThreats();
				} else if (weaponHasFlag(handGetWeaponNum(HAND_RIGHT), WEAPONFLAG_AIMTRACK)) {
					s32 j;

					if (frIsInTraining()
							&& g_Vars.currentplayer->lookingatprop.prop
							&& bmoveIsInSightAimMode()) {
						func0f1a0924(g_Vars.currentplayer->lookingatprop.prop);
					} else if (coreCheckCmpFollowThreat(&g_Vars.currentplayer->lookingatprop, -1) == 0) {
						g_Vars.currentplayer->lookingatprop.prop = NULL;
					}

					for (j = 0; j < ARRAYCOUNT(g_Vars.currentplayer->cmpfollowprops); j++) {
						if (!coreCheckCmpFollowThreat(&g_Vars.currentplayer->cmpfollowprops[j], j)) {
							g_Vars.currentplayer->cmpfollowprops[j].unk04 = -1;
							g_Vars.currentplayer->cmpfollowprops[j].unk08 = -2;
						}
					}
				}

				// Handle eyespy Z presses
				if (g_Vars.currentplayer->eyespy
						&& (g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_EYESPY)
						&& g_Vars.currentplayer->eyespy->camerabuttonheld) {
					if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
						objectiveCheckHolograph(400);
						audioStart(var80095200, SFX_CAMSPY_SHUTTER, 0, -1, -1, -1, -1, -1);
					} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
						if (g_Vars.currentplayer->eyespydarts) {
							// Fire dart
							struct coord direction;
							audioStart(var80095200, SFX_DRUGSPY_FIREDART, 0, -1, -1, -1, -1, -1);
							g_Vars.currentplayer->eyespydarts--;

							direction.x = g_Vars.currentplayer->eyespy->look.x;
							direction.y = g_Vars.currentplayer->eyespy->look.y;
							direction.z = g_Vars.currentplayer->eyespy->look.z;

							projectileCreate(g_Vars.currentplayer->eyespy->prop, 0,
									&g_Vars.currentplayer->eyespy->prop->pos, &direction, WEAPON_TRANQUILIZER, NULL);
						} else {
							// No dart ammo
							audioStart(var80095200, SFX_DRUGSPY_FIREEMPTY, 0, -1, -1, -1, -1, -1);
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
				gdl = bgRender(gdl);
				func0f028498(var80075d68 == 15 || var8005f020);
				gdl = propsRenderBeams(gdl);
				gdl = shardsRender(gdl);
				gdl = sparksRender(gdl);
				gdl = weatherRender(gdl);

				if (g_NbombsActive) {
					gdl = nbombsRender(gdl);
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
								gdl = bviewRenderHorizonScanner(gdl);
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
									audioStart(var80095200, SFX_INFIL_STATIC_LONG, &g_CutsceneStaticAudioHandle, -1, -1, -1, -1, -1);
								}

								g_CutsceneStaticTimer -= g_Vars.diffframe60;

								if (g_CutsceneStaticTimer < 0) {
									g_CutsceneStaticTimer = random() % 200 + 40;
									g_CutsceneStaticActive = false;
								}

								gdl = bviewRenderFilmLens(gdl, 0xffffffff, 0xffffffff);

								if (g_CutsceneStaticTimer < 15) {
									if (g_CutsceneStaticActive == false) {
										g_CutsceneStaticActive = true;
										audioStart(var80095200, SFX_INFIL_STATIC_MEDIUM, NULL, -1, -1, -1, -1, -1);
									}

									cutscenestatic = 225 - g_CutsceneStaticTimer * 10;
								}

								// Consider a single frame of static, separate
								// to the main static above
								if (random() % 60 == 1) {
									cutscenestatic = 255;
									audioStart(var80095200, SFX_INFIL_STATIC_SHORT, NULL, -1, -1, -1, -1, -1);
								}

								if (cutscenestatic) {
									gdl = bviewRenderStatic(gdl, 0xffffffff, cutscenestatic);
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
						gdl = bviewRenderSlayerRocketLens(gdl, 0xffffffff, 0xffffffff);

						if (g_Vars.currentplayer->badrockettime > 0) {
							u32 slayerstatic = g_Vars.currentplayer->badrockettime * 255 / 90;

							if (slayerstatic > 255) {
								slayerstatic = 255;
							}

							gdl = bviewRenderStatic(gdl, 0x4fffffff, slayerstatic);
						}
					}

					if (g_Vars.currentplayer->visionmode == VISIONMODE_3) {
						gdl = bviewRenderStatic(gdl, 0x4fffffff, 255);
						g_Vars.currentplayer->visionmode = VISIONMODE_NORMAL;
					}

					if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY
							&& g_Vars.tickmode != TICKMODE_CUTSCENE) {
						s32 xraything = 99;

						if (g_Vars.currentplayer->erasertime < 200) {
							xraything = 249 - (g_Vars.currentplayer->erasertime * 3 >> 2);
						}

						gdl = bviewRenderZoomBlur(gdl, 0xffffffff, xraything, 1.05f, 1.05f);
					}

					// Handle combat boosts
					if ((g_Vars.speedpillchange > 0 && g_Vars.speedpillchange < 30)
							|| (g_Vars.speedpillwant && !g_Vars.speedpillon)
							|| (!g_Vars.speedpillwant && g_Vars.speedpillon)) {
						if (g_Vars.speedpillchange == 30 && !g_Vars.speedpillwant) {
							audioStart(var80095200, coreGetSlowMotionType() ? SFX_JO_BOOST_ACTIVATE : SFX_JO_BOOST_REVERT, 0, -1, -1, -1, -1, -1);
						}

						if (g_Vars.speedpillchange < 15) {
							gdl = bviewRenderZoomBlur(gdl, 0xffffffff,
									g_Vars.speedpillchange * 180 / 15,
									(f32)g_Vars.speedpillchange * 0.02000000141561f + 1.1f,
									(f32)g_Vars.speedpillchange * 0.02000000141561f + 1.1f);
							gdl = fadeDraw(gdl, 0xff, 0xff, 0xff,
									g_Vars.speedpillchange * 0.0066666668280959f);
						} else {
							gdl = bviewRenderZoomBlur(gdl, 0xffffffff,
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
						bviewClearBlur();
						gdl = bviewRenderMotionBlur(gdl, 0xffffffff, bluramount);
					}

					// Handle blur effect in cutscenes (Extraction intro?)
					if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
						f32 cutsceneblurfrac = cutsceneGetBlurFrac();

						if (cutsceneblurfrac > 0) {
							u32 bluramount = cutsceneblurfrac * 255;
							gdl = bviewRenderMotionBlur(gdl, 0xffffff00, bluramount);
						}
					}

					if (debugGetMotionBlur() == 1) {
						gdl = bviewRenderMotionBlur(gdl, 0xffffff00, 128);
					} else if (debugGetMotionBlur() == 2) {
						gdl = bviewRenderMotionBlur(gdl, 0xffffff00, 192);
					} else if (debugGetMotionBlur() == 3) {
						gdl = bviewRenderMotionBlur(gdl, 0xffffff00, 230);
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
				gdl = coreRenderFade(gdl);

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
				gdl = amRender(gdl);
				func00016748(1);

				if (g_Vars.currentplayer->unk1c50_01) {
					gdl = func0f0fbc30(gdl);
				}

				func00016748(g_Vars.currentplayerstats->scale_bg2gfx);

				if (g_Vars.mplayerisrunning) {
					gdl = mpRenderModalText(gdl);
				}

				if (g_Vars.currentplayer->dostartnewlife) {
					currentPlayerStartNewLife();
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
		coreSetDifficulty(DIFF_A);
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

	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, viGetWidth(), viGetHeight());

	return gdl;
}
#endif

u32 g_CutsceneTime240_60 = 0;
u32 var800840a8 = 0x00000000;
u32 var800840ac = 0x00000000;
u32 var800840b0 = 0x00000000;
u32 var800840b4 = 0x00000000;
u32 var800840b8 = 0x00000000;
u32 var800840bc = 0x00000000;

void coreUpdateSoloHandicaps(void)
{
	if (g_Vars.antiplayernum >= 0) {
		if (g_Difficulty == DIFF_A) {
			g_CameraWaitMultiplier = 2;
			var8006994c = 2;
			var80069950 = 0.5f;
			var80069954 = 0.5f;
			var80069958 = 2;
			var80062ca0 = 0.5f;
			var80062ca4 = 0.35f;
			var80062ca8 = 4;
			var8007e4a8 = 0.25f;
			var80069880 = 1.5f;
			g_AmmoMultiplier = 3;
			var80062cac = 0.2f;
		} else if (g_Difficulty == DIFF_SA) {
			g_CameraWaitMultiplier = 2;
			var8006994c = 1.5f;
			var80069950 = 0.5f;
			var80069954 = 0.5f;
			var80069958 = 1.5f;
			var80062ca0 = 0.6f;
			var80062ca4 = 0.5f;
			var80062ca8 = 3;
			var8007e4a8 = 0.25f;
			var80069880 = 1.1f;
			g_AmmoMultiplier = 2.5f;
			var80062cac = 0.5f;
		} else {
			g_CameraWaitMultiplier = 2;
			var8006994c = 1;
			var80069950 = 0.5f;
			var80069954 = 0.5f;
			var80069958 = 1;
			var80062ca0 = 0.7f;
			var80062ca4 = 0.65f;
			var80062ca8 = 2;
			var8007e4a8 = 0.25f;
			var80069880 = 0.75f;
			g_AmmoMultiplier = 2;
			var80062cac = 1;
		}
	} else if (g_Vars.coopplayernum >= 0) {
		if (g_Difficulty == DIFF_A) {
			g_CameraWaitMultiplier = 2;
			var8006994c = 2;
			var80069950 = 0.5f;
			var80069954 = 0.5f;
			var80069958 = 2;
			var80062ca0 = 0.6f;
			var80062ca4 = 0.5f;
			var80062ca8 = 2;
			var8007e4a8 = 0.25f;
			var80069880 = 1.5f;
			g_AmmoMultiplier = 2;
			var80062cac = 0.2f;
		} else if (g_Difficulty == DIFF_SA) {
			g_CameraWaitMultiplier = 1;
			var8006994c = 1;
			var80069950 = 0.75f;
			var80069954 = 1;
			var80069958 = 1;
			var80062ca0 = 0.75f;
			var80062ca4 = 1;
			var80062ca8 = 1;
			var8007e4a8 = 1;
			var80069880 = g_LanguageId ? 1.1f : 0.75f;
			g_AmmoMultiplier = 1.5f;
			var80062cac = 0.5f;
		} else {
			g_CameraWaitMultiplier = 1;
			var8006994c = 1;
			var80069950 = 1;
			var80069954 = 1.5f;
			var80069958 = 1;
			var80062ca0 = 1.5f;
			var80062ca4 = 1.5f;
			var80062ca8 = 1;
			var8007e4a8 = 1.5f;
			var80069880 = g_LanguageId ? 0.75f : 0.2f;
			g_AmmoMultiplier = 1;
			var80062cac = 1;
		}
	} else {
		if (g_Difficulty == DIFF_A) {
			f32 totalhealth;
			f32 frac = 1;

			if (g_Vars.coopplayernum < 0 && g_Vars.antiplayernum < 0) {
				totalhealth = currentPlayerGetHealthFrac() + currentPlayerGetShieldFrac();

				if (totalhealth <= 0.125f) {
					frac = 0.5f;
				} else {
					frac = 1;

					if (totalhealth <= 0.6f) {
						frac = (totalhealth - 0.125f) * 0.5f / 0.47500002384186f + 0.5f;
					}
				}
			}

			g_CameraWaitMultiplier = 2;
			var8006994c = 2;
			var80069950 = 0.5f * frac;
			var80069954 = 0.5f * frac;
			var80069958 = 2;
			var80062ca0 = 0.6f;
			var80062ca4 = 0.5f * frac;
			var80062ca8 = 2;
			var8007e4a8 = 0.25f * frac;
			var80069880 = 1.5f;
			g_AmmoMultiplier = 2;
			var80062cac = 0.2f;
		} else if (g_Difficulty == DIFF_SA) {
			g_CameraWaitMultiplier = 1;
			var8006994c = 1;
			var80069950 = 0.75f;
			var80069954 = 0.75f;
			var80069958 = 1;
			var80062ca0 = 0.8f;
			var80062ca4 = 0.6f;
			var80062ca8 = 1;
			var8007e4a8 = 0.75f;
			var80069880 = g_LanguageId ? 1.1f : 0.75f;
			g_AmmoMultiplier = 1.5f;
			var80062cac = 0.5f;
		} else if (g_Difficulty == DIFF_PA) {
			g_CameraWaitMultiplier = 1;
			var8006994c = 1;
			var80069950 = 1;
			var80069954 = 1;
			var80069958 = 1;
			var80062ca0 = 1.175f;
			var80062ca4 = 1;
			var80062ca8 = 1;
			var8007e4a8 = 1;
			var80069880 = g_LanguageId ? 0.75f : 0.2f;
			g_AmmoMultiplier = 1;
			var80062cac = 1;
		} else if (g_Difficulty == DIFF_PD) {
			g_CameraWaitMultiplier = 1;
			var8006994c = 1;
			var80069950 = 1;
			var80069954 = 1;
			var80069958 = 1;
			var80062ca0 = 1.1f;
			var80062ca4 = 1;
			var80062ca8 = 1;
			var8007e4a8 = 1;
			var80069880 = 1;
			g_AmmoMultiplier = 1;
			var80062cac = 1;
		}
	}
}

s32 sub54321(s32 value)
{
#if PAL
	return value - 6661;
#else
	return value - 54321;
#endif
}

void coreUpdateCutsceneTime(void)
{
	if (g_Vars.in_cutscene) {
		g_CutsceneTime240_60 += g_Vars.lvupdate240_60;
		return;
	}

	g_CutsceneTime240_60 = 0;
}

GLOBAL_ASM(
glabel coreGetSlowMotionType
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
/*  f16b890:	3c058006 */ 	lui	$a1,%hi(rspbootTextStart)
/*  f16b894:	24a29fe0 */ 	addiu	$v0,$a1,%lo(rspbootTextStart)
/*  f16b898:	11cf000d */ 	beq	$t6,$t7,.L0f16b8d0
/*  f16b89c:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x318)
/*  f16b8a0:	3c188006 */ 	lui	$t8,%hi(rspbootTextStart+0x1)
/*  f16b8a4:	24431000 */ 	addiu	$v1,$v0,0x1000
/*  f16b8a8:	27189fe1 */ 	addiu	$t8,$t8,%lo(rspbootTextStart+0x1)
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
//u32 coreGetSlowMotionType(void)
//{
//#if PIRACYCHECKS
//	u32 addr = sub54321(0xb0000a5c + 54321);
//	u32 actual;
//	u32 expected = sub54321(0x1740fff9);
//	osPiReadIo(addr, &actual);
//
//	if (actual != expected) {
//		extern u32 rspbootTextStart;
//		extern u32 rspbootStartPlusOne;
//		u32 *ptr = &rspbootStart;
//		u32 *end = &ptr[1024];
//
//		if (!(end < &rspbootStartPlusOne)) {
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

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel coreTick
/*  f16c718:	27bdfd70 */ 	addiu	$sp,$sp,-656
/*  f16c71c:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f16c720:	afb50040 */ 	sw	$s5,0x40($sp)
/*  f16c724:	afb4003c */ 	sw	$s4,0x3c($sp)
/*  f16c728:	afb30038 */ 	sw	$s3,0x38($sp)
/*  f16c72c:	afb20034 */ 	sw	$s2,0x34($sp)
/*  f16c730:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f16c734:	0fc5b6cc */ 	jal	0xf16db30
/*  f16c738:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f16c73c:	3c14800a */ 	lui	$s4,0x800a
/*  f16c740:	2694a510 */ 	addiu	$s4,$s4,-23280
/*  f16c744:	968e04e4 */ 	lhu	$t6,0x4e4($s4)
/*  f16c748:	51c00004 */ 	beqzl	$t6,.PF0f16c75c
/*  f16c74c:	8e8204d8 */ 	lw	$v0,0x4d8($s4)
/*  f16c750:	0fc47412 */ 	jal	0xf11d048
/*  f16c754:	00000000 */ 	nop
/*  f16c758:	8e8204d8 */ 	lw	$v0,0x4d8($s4)
.PF0f16c75c:
/*  f16c75c:	18400003 */ 	blez	$v0,.PF0f16c76c
/*  f16c760:	244fffff */ 	addiu	$t7,$v0,-1
/*  f16c764:	10000015 */ 	b	.PF0f16c7bc
/*  f16c768:	ae8f04d8 */ 	sw	$t7,0x4d8($s4)
.PF0f16c76c:
/*  f16c76c:	14400013 */ 	bnez	$v0,.PF0f16c7bc
/*  f16c770:	00000000 */ 	nop
/*  f16c774:	0c004db2 */ 	jal	0x136c8
/*  f16c778:	00000000 */ 	nop
/*  f16c77c:	8e8204b4 */ 	lw	$v0,0x4b4($s4)
/*  f16c780:	2401005a */ 	li	$at,0x5a
/*  f16c784:	10410007 */ 	beq	$v0,$at,.PF0f16c7a4
/*  f16c788:	2401005b */ 	li	$at,0x5b
/*  f16c78c:	10410005 */ 	beq	$v0,$at,.PF0f16c7a4
/*  f16c790:	2401005c */ 	li	$at,0x5c
/*  f16c794:	10410003 */ 	beq	$v0,$at,.PF0f16c7a4
/*  f16c798:	2401005d */ 	li	$at,0x5d
/*  f16c79c:	14410003 */ 	bne	$v0,$at,.PF0f16c7ac
/*  f16c7a0:	2418001f */ 	li	$t8,0x1f
.PF0f16c7a4:
/*  f16c7a4:	10000003 */ 	b	.PF0f16c7b4
/*  f16c7a8:	a28004d1 */ 	sb	$zero,0x4d1($s4)
.PF0f16c7ac:
/*  f16c7ac:	0fc47a8d */ 	jal	0xf11ea34
/*  f16c7b0:	a29804d1 */ 	sb	$t8,0x4d1($s4)
.PF0f16c7b4:
/*  f16c7b4:	2415ffff */ 	li	$s5,-1
/*  f16c7b8:	ae9504d8 */ 	sw	$s5,0x4d8($s4)
.PF0f16c7bc:
/*  f16c7bc:	3c198009 */ 	lui	$t9,0x8009
/*  f16c7c0:	93391040 */ 	lbu	$t9,0x1040($t9)
/*  f16c7c4:	24100001 */ 	li	$s0,0x1
/*  f16c7c8:	2415ffff */ 	li	$s5,-1
/*  f16c7cc:	56190004 */ 	bnel	$s0,$t9,.PF0f16c7e0
/*  f16c7d0:	8e8c006c */ 	lw	$t4,0x6c($s4)
/*  f16c7d4:	0fc66f10 */ 	jal	0xf19bc40
/*  f16c7d8:	00000000 */ 	nop
/*  f16c7dc:	8e8c006c */ 	lw	$t4,0x6c($s4)
.PF0f16c7e0:
/*  f16c7e0:	00003825 */ 	move	$a3,$zero
/*  f16c7e4:	51800004 */ 	beqzl	$t4,.PF0f16c7f8
/*  f16c7e8:	00002825 */ 	move	$a1,$zero
/*  f16c7ec:	10000002 */ 	b	.PF0f16c7f8
/*  f16c7f0:	02002825 */ 	move	$a1,$s0
/*  f16c7f4:	00002825 */ 	move	$a1,$zero
.PF0f16c7f8:
/*  f16c7f8:	8e8d0068 */ 	lw	$t5,0x68($s4)
/*  f16c7fc:	51a00004 */ 	beqzl	$t5,.PF0f16c810
/*  f16c800:	00002025 */ 	move	$a0,$zero
/*  f16c804:	10000002 */ 	b	.PF0f16c810
/*  f16c808:	02002025 */ 	move	$a0,$s0
/*  f16c80c:	00002025 */ 	move	$a0,$zero
.PF0f16c810:
/*  f16c810:	8e8e0064 */ 	lw	$t6,0x64($s4)
/*  f16c814:	51c00004 */ 	beqzl	$t6,.PF0f16c828
/*  f16c818:	00001825 */ 	move	$v1,$zero
/*  f16c81c:	10000002 */ 	b	.PF0f16c828
/*  f16c820:	02001825 */ 	move	$v1,$s0
/*  f16c824:	00001825 */ 	move	$v1,$zero
.PF0f16c828:
/*  f16c828:	8e8f0070 */ 	lw	$t7,0x70($s4)
/*  f16c82c:	51e00004 */ 	beqzl	$t7,.PF0f16c840
/*  f16c830:	00001025 */ 	move	$v0,$zero
/*  f16c834:	10000002 */ 	b	.PF0f16c840
/*  f16c838:	02001025 */ 	move	$v0,$s0
/*  f16c83c:	00001025 */ 	move	$v0,$zero
.PF0f16c840:
/*  f16c840:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f16c844:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f16c848:	03256021 */ 	addu	$t4,$t9,$a1
/*  f16c84c:	19800026 */ 	blez	$t4,.PF0f16c8e8
/*  f16c850:	00076880 */ 	sll	$t5,$a3,0x2
/*  f16c854:	028d3021 */ 	addu	$a2,$s4,$t5
/*  f16c858:	8cce0064 */ 	lw	$t6,0x64($a2)
.PF0f16c85c:
/*  f16c85c:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f16c860:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f16c864:	adc01490 */ 	sw	$zero,0x1490($t6)
/*  f16c868:	8ccf0060 */ 	lw	$t7,0x60($a2)
/*  f16c86c:	00002825 */ 	move	$a1,$zero
/*  f16c870:	00002025 */ 	move	$a0,$zero
/*  f16c874:	ade00cec */ 	sw	$zero,0xcec($t7)
/*  f16c878:	8e98006c */ 	lw	$t8,0x6c($s4)
/*  f16c87c:	00001825 */ 	move	$v1,$zero
/*  f16c880:	00001025 */ 	move	$v0,$zero
/*  f16c884:	13000003 */ 	beqz	$t8,.PF0f16c894
/*  f16c888:	00000000 */ 	nop
/*  f16c88c:	10000001 */ 	b	.PF0f16c894
/*  f16c890:	02002825 */ 	move	$a1,$s0
.PF0f16c894:
/*  f16c894:	8e990068 */ 	lw	$t9,0x68($s4)
/*  f16c898:	13200003 */ 	beqz	$t9,.PF0f16c8a8
/*  f16c89c:	00000000 */ 	nop
/*  f16c8a0:	10000001 */ 	b	.PF0f16c8a8
/*  f16c8a4:	02002025 */ 	move	$a0,$s0
.PF0f16c8a8:
/*  f16c8a8:	8e8c0064 */ 	lw	$t4,0x64($s4)
/*  f16c8ac:	11800003 */ 	beqz	$t4,.PF0f16c8bc
/*  f16c8b0:	00000000 */ 	nop
/*  f16c8b4:	10000001 */ 	b	.PF0f16c8bc
/*  f16c8b8:	02001825 */ 	move	$v1,$s0
.PF0f16c8bc:
/*  f16c8bc:	8e8d0070 */ 	lw	$t5,0x70($s4)
/*  f16c8c0:	11a00003 */ 	beqz	$t5,.PF0f16c8d0
/*  f16c8c4:	00000000 */ 	nop
/*  f16c8c8:	10000001 */ 	b	.PF0f16c8d0
/*  f16c8cc:	02001025 */ 	move	$v0,$s0
.PF0f16c8d0:
/*  f16c8d0:	00437021 */ 	addu	$t6,$v0,$v1
/*  f16c8d4:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f16c8d8:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f16c8dc:	00f8082a */ 	slt	$at,$a3,$t8
/*  f16c8e0:	5420ffde */ 	bnezl	$at,.PF0f16c85c
/*  f16c8e4:	8cce0064 */ 	lw	$t6,0x64($a2)
.PF0f16c8e8:
/*  f16c8e8:	0fc5b6f7 */ 	jal	0xf16dbdc
/*  f16c8ec:	00000000 */ 	nop
/*  f16c8f0:	10400003 */ 	beqz	$v0,.PF0f16c900
/*  f16c8f4:	00000000 */ 	nop
/*  f16c8f8:	1000011a */ 	b	.PF0f16cd64
/*  f16c8fc:	ae800034 */ 	sw	$zero,0x34($s4)
.PF0f16c900:
/*  f16c900:	0fc629b9 */ 	jal	0xf18a6e4
/*  f16c904:	00000000 */ 	nop
/*  f16c908:	10400044 */ 	beqz	$v0,.PF0f16ca1c
/*  f16c90c:	00000000 */ 	nop
/*  f16c910:	8e99006c */ 	lw	$t9,0x6c($s4)
/*  f16c914:	ae800034 */ 	sw	$zero,0x34($s4)
/*  f16c918:	00003825 */ 	move	$a3,$zero
/*  f16c91c:	13200003 */ 	beqz	$t9,.PF0f16c92c
/*  f16c920:	00002825 */ 	move	$a1,$zero
/*  f16c924:	10000001 */ 	b	.PF0f16c92c
/*  f16c928:	24050001 */ 	li	$a1,0x1
.PF0f16c92c:
/*  f16c92c:	8e8c0068 */ 	lw	$t4,0x68($s4)
/*  f16c930:	00002025 */ 	move	$a0,$zero
/*  f16c934:	00001825 */ 	move	$v1,$zero
/*  f16c938:	11800003 */ 	beqz	$t4,.PF0f16c948
/*  f16c93c:	00001025 */ 	move	$v0,$zero
/*  f16c940:	10000001 */ 	b	.PF0f16c948
/*  f16c944:	24040001 */ 	li	$a0,0x1
.PF0f16c948:
/*  f16c948:	8e8d0064 */ 	lw	$t5,0x64($s4)
/*  f16c94c:	00076080 */ 	sll	$t4,$a3,0x2
/*  f16c950:	028c3021 */ 	addu	$a2,$s4,$t4
/*  f16c954:	11a00003 */ 	beqz	$t5,.PF0f16c964
/*  f16c958:	3c08efff */ 	lui	$t0,0xefff
/*  f16c95c:	10000001 */ 	b	.PF0f16c964
/*  f16c960:	24030001 */ 	li	$v1,0x1
.PF0f16c964:
/*  f16c964:	8e8e0070 */ 	lw	$t6,0x70($s4)
/*  f16c968:	3508efff */ 	ori	$t0,$t0,0xefff
/*  f16c96c:	11c00003 */ 	beqz	$t6,.PF0f16c97c
/*  f16c970:	00000000 */ 	nop
/*  f16c974:	10000001 */ 	b	.PF0f16c97c
/*  f16c978:	24020001 */ 	li	$v0,0x1
.PF0f16c97c:
/*  f16c97c:	00437821 */ 	addu	$t7,$v0,$v1
/*  f16c980:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f16c984:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f16c988:	5b2000f7 */ 	blezl	$t9,.PF0f16cd68
/*  f16c98c:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f16c990:	8ccd0064 */ 	lw	$t5,0x64($a2)
.PF0f16c994:
/*  f16c994:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f16c998:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f16c99c:	ada81c40 */ 	sw	$t0,0x1c40($t5)
/*  f16c9a0:	8e8e006c */ 	lw	$t6,0x6c($s4)
/*  f16c9a4:	00002825 */ 	move	$a1,$zero
/*  f16c9a8:	00002025 */ 	move	$a0,$zero
/*  f16c9ac:	11c00003 */ 	beqz	$t6,.PF0f16c9bc
/*  f16c9b0:	00001825 */ 	move	$v1,$zero
/*  f16c9b4:	10000001 */ 	b	.PF0f16c9bc
/*  f16c9b8:	24050001 */ 	li	$a1,0x1
.PF0f16c9bc:
/*  f16c9bc:	8e8f0068 */ 	lw	$t7,0x68($s4)
/*  f16c9c0:	00001025 */ 	move	$v0,$zero
/*  f16c9c4:	11e00003 */ 	beqz	$t7,.PF0f16c9d4
/*  f16c9c8:	00000000 */ 	nop
/*  f16c9cc:	10000001 */ 	b	.PF0f16c9d4
/*  f16c9d0:	24040001 */ 	li	$a0,0x1
.PF0f16c9d4:
/*  f16c9d4:	8e980064 */ 	lw	$t8,0x64($s4)
/*  f16c9d8:	13000003 */ 	beqz	$t8,.PF0f16c9e8
/*  f16c9dc:	00000000 */ 	nop
/*  f16c9e0:	10000001 */ 	b	.PF0f16c9e8
/*  f16c9e4:	24030001 */ 	li	$v1,0x1
.PF0f16c9e8:
/*  f16c9e8:	8e990070 */ 	lw	$t9,0x70($s4)
/*  f16c9ec:	13200003 */ 	beqz	$t9,.PF0f16c9fc
/*  f16c9f0:	00000000 */ 	nop
/*  f16c9f4:	10000001 */ 	b	.PF0f16c9fc
/*  f16c9f8:	24020001 */ 	li	$v0,0x1
.PF0f16c9fc:
/*  f16c9fc:	00436021 */ 	addu	$t4,$v0,$v1
/*  f16ca00:	01846821 */ 	addu	$t5,$t4,$a0
/*  f16ca04:	01a57021 */ 	addu	$t6,$t5,$a1
/*  f16ca08:	00ee082a */ 	slt	$at,$a3,$t6
/*  f16ca0c:	5420ffe1 */ 	bnezl	$at,.PF0f16c994
/*  f16ca10:	8ccd0064 */ 	lw	$t5,0x64($a2)
/*  f16ca14:	100000d4 */ 	b	.PF0f16cd68
/*  f16ca18:	8e830034 */ 	lw	$v1,0x34($s4)
.PF0f16ca1c:
/*  f16ca1c:	0fc5b180 */ 	jal	0xf16c600
/*  f16ca20:	00000000 */ 	nop
/*  f16ca24:	8e8f0040 */ 	lw	$t7,0x40($s4)
/*  f16ca28:	24010002 */ 	li	$at,0x2
/*  f16ca2c:	1450000f */ 	bne	$v0,$s0,.PF0f16ca6c
/*  f16ca30:	ae8f0034 */ 	sw	$t7,0x34($s4)
/*  f16ca34:	8e980468 */ 	lw	$t8,0x468($s4)
/*  f16ca38:	53000005 */ 	beqzl	$t8,.PF0f16ca50
/*  f16ca3c:	8e8c0034 */ 	lw	$t4,0x34($s4)
/*  f16ca40:	8e9904cc */ 	lw	$t9,0x4cc($s4)
/*  f16ca44:	13200007 */ 	beqz	$t9,.PF0f16ca64
/*  f16ca48:	00000000 */ 	nop
/*  f16ca4c:	8e8c0034 */ 	lw	$t4,0x34($s4)
.PF0f16ca50:
/*  f16ca50:	24150004 */ 	li	$s5,0x4
/*  f16ca54:	29810005 */ 	slti	$at,$t4,0x5
/*  f16ca58:	14200002 */ 	bnez	$at,.PF0f16ca64
/*  f16ca5c:	00000000 */ 	nop
/*  f16ca60:	ae950034 */ 	sw	$s5,0x34($s4)
.PF0f16ca64:
/*  f16ca64:	100000c0 */ 	b	.PF0f16cd68
/*  f16ca68:	8e830034 */ 	lw	$v1,0x34($s4)
.PF0f16ca6c:
/*  f16ca6c:	544100b2 */ 	bnel	$v0,$at,.PF0f16cd38
/*  f16ca70:	8e8f0468 */ 	lw	$t7,0x468($s4)
/*  f16ca74:	8e8d0468 */ 	lw	$t5,0x468($s4)
/*  f16ca78:	51a00005 */ 	beqzl	$t5,.PF0f16ca90
/*  f16ca7c:	8e8f0314 */ 	lw	$t7,0x314($s4)
/*  f16ca80:	8e8e04cc */ 	lw	$t6,0x4cc($s4)
/*  f16ca84:	11c000a9 */ 	beqz	$t6,.PF0f16cd2c
/*  f16ca88:	00000000 */ 	nop
/*  f16ca8c:	8e8f0314 */ 	lw	$t7,0x314($s4)
.PF0f16ca90:
/*  f16ca90:	51e000a1 */ 	beqzl	$t7,.PF0f16cd18
/*  f16ca94:	8e8e0034 */ 	lw	$t6,0x34($s4)
/*  f16ca98:	8e89006c */ 	lw	$t1,0x6c($s4)
/*  f16ca9c:	00009025 */ 	move	$s2,$zero
/*  f16caa0:	00009825 */ 	move	$s3,$zero
/*  f16caa4:	11200003 */ 	beqz	$t1,.PF0f16cab4
/*  f16caa8:	00002825 */ 	move	$a1,$zero
/*  f16caac:	10000001 */ 	b	.PF0f16cab4
/*  f16cab0:	24050001 */ 	li	$a1,0x1
.PF0f16cab4:
/*  f16cab4:	8e870068 */ 	lw	$a3,0x68($s4)
/*  f16cab8:	00002025 */ 	move	$a0,$zero
/*  f16cabc:	00001825 */ 	move	$v1,$zero
/*  f16cac0:	10e00003 */ 	beqz	$a3,.PF0f16cad0
/*  f16cac4:	00001025 */ 	move	$v0,$zero
/*  f16cac8:	10000001 */ 	b	.PF0f16cad0
/*  f16cacc:	24040001 */ 	li	$a0,0x1
.PF0f16cad0:
/*  f16cad0:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f16cad4:	00136880 */ 	sll	$t5,$s3,0x2
/*  f16cad8:	028d7021 */ 	addu	$t6,$s4,$t5
/*  f16cadc:	11000003 */ 	beqz	$t0,.PF0f16caec
/*  f16cae0:	00000000 */ 	nop
/*  f16cae4:	10000001 */ 	b	.PF0f16caec
/*  f16cae8:	24030001 */ 	li	$v1,0x1
.PF0f16caec:
/*  f16caec:	8e860070 */ 	lw	$a2,0x70($s4)
/*  f16caf0:	10c00003 */ 	beqz	$a2,.PF0f16cb00
/*  f16caf4:	00000000 */ 	nop
/*  f16caf8:	10000001 */ 	b	.PF0f16cb00
/*  f16cafc:	24020001 */ 	li	$v0,0x1
.PF0f16cb00:
/*  f16cb00:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f16cb04:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f16cb08:	03256021 */ 	addu	$t4,$t9,$a1
/*  f16cb0c:	1980006f */ 	blez	$t4,.PF0f16cccc
/*  f16cb10:	00000000 */ 	nop
/*  f16cb14:	afae004c */ 	sw	$t6,0x4c($sp)
/*  f16cb18:	8faf004c */ 	lw	$t7,0x4c($sp)
.PF0f16cb1c:
/*  f16cb1c:	8de20064 */ 	lw	$v0,0x64($t7)
/*  f16cb20:	8c5800d8 */ 	lw	$t8,0xd8($v0)
/*  f16cb24:	5700004e */ 	bnezl	$t8,.PF0f16cc60
/*  f16cb28:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f16cb2c:	8c4300bc */ 	lw	$v1,0xbc($v0)
/*  f16cb30:	84790028 */ 	lh	$t9,0x28($v1)
/*  f16cb34:	24630028 */ 	addiu	$v1,$v1,0x28
/*  f16cb38:	52b90049 */ 	beql	$s5,$t9,.PF0f16cc60
/*  f16cb3c:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f16cb40:	16400046 */ 	bnez	$s2,.PF0f16cc5c
/*  f16cb44:	00006040 */ 	sll	$t4,$zero,0x1
/*  f16cb48:	006c8821 */ 	addu	$s1,$v1,$t4
.PF0f16cb4c:
/*  f16cb4c:	11200003 */ 	beqz	$t1,.PF0f16cb5c
/*  f16cb50:	00008025 */ 	move	$s0,$zero
/*  f16cb54:	10000002 */ 	b	.PF0f16cb60
/*  f16cb58:	24050001 */ 	li	$a1,0x1
.PF0f16cb5c:
/*  f16cb5c:	00002825 */ 	move	$a1,$zero
.PF0f16cb60:
/*  f16cb60:	10e00003 */ 	beqz	$a3,.PF0f16cb70
/*  f16cb64:	00002025 */ 	move	$a0,$zero
/*  f16cb68:	10000001 */ 	b	.PF0f16cb70
/*  f16cb6c:	24040001 */ 	li	$a0,0x1
.PF0f16cb70:
/*  f16cb70:	11000003 */ 	beqz	$t0,.PF0f16cb80
/*  f16cb74:	00001825 */ 	move	$v1,$zero
/*  f16cb78:	10000001 */ 	b	.PF0f16cb80
/*  f16cb7c:	24030001 */ 	li	$v1,0x1
.PF0f16cb80:
/*  f16cb80:	10c00003 */ 	beqz	$a2,.PF0f16cb90
/*  f16cb84:	00001025 */ 	move	$v0,$zero
/*  f16cb88:	10000001 */ 	b	.PF0f16cb90
/*  f16cb8c:	24020001 */ 	li	$v0,0x1
.PF0f16cb90:
/*  f16cb90:	00436821 */ 	addu	$t5,$v0,$v1
/*  f16cb94:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f16cb98:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f16cb9c:	59e0002a */ 	blezl	$t7,.PF0f16cc48
/*  f16cba0:	86390002 */ 	lh	$t9,0x2($s1)
.PF0f16cba4:
/*  f16cba4:	1270000c */ 	beq	$s3,$s0,.PF0f16cbd8
/*  f16cba8:	0010c080 */ 	sll	$t8,$s0,0x2
/*  f16cbac:	0298c821 */ 	addu	$t9,$s4,$t8
/*  f16cbb0:	8f2c0064 */ 	lw	$t4,0x64($t9)
/*  f16cbb4:	02002825 */ 	move	$a1,$s0
/*  f16cbb8:	8d8d00d8 */ 	lw	$t5,0xd8($t4)
/*  f16cbbc:	55a00007 */ 	bnezl	$t5,.PF0f16cbdc
/*  f16cbc0:	8e89006c */ 	lw	$t1,0x6c($s4)
/*  f16cbc4:	0fc579c8 */ 	jal	0xf15e720
/*  f16cbc8:	86240000 */ 	lh	$a0,0x0($s1)
/*  f16cbcc:	50400003 */ 	beqzl	$v0,.PF0f16cbdc
/*  f16cbd0:	8e89006c */ 	lw	$t1,0x6c($s4)
/*  f16cbd4:	24120001 */ 	li	$s2,0x1
.PF0f16cbd8:
/*  f16cbd8:	8e89006c */ 	lw	$t1,0x6c($s4)
.PF0f16cbdc:
/*  f16cbdc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f16cbe0:	8e870068 */ 	lw	$a3,0x68($s4)
/*  f16cbe4:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f16cbe8:	11200003 */ 	beqz	$t1,.PF0f16cbf8
/*  f16cbec:	8e860070 */ 	lw	$a2,0x70($s4)
/*  f16cbf0:	10000002 */ 	b	.PF0f16cbfc
/*  f16cbf4:	24050001 */ 	li	$a1,0x1
.PF0f16cbf8:
/*  f16cbf8:	00002825 */ 	move	$a1,$zero
.PF0f16cbfc:
/*  f16cbfc:	10e00003 */ 	beqz	$a3,.PF0f16cc0c
/*  f16cc00:	00002025 */ 	move	$a0,$zero
/*  f16cc04:	10000001 */ 	b	.PF0f16cc0c
/*  f16cc08:	24040001 */ 	li	$a0,0x1
.PF0f16cc0c:
/*  f16cc0c:	11000003 */ 	beqz	$t0,.PF0f16cc1c
/*  f16cc10:	00001825 */ 	move	$v1,$zero
/*  f16cc14:	10000001 */ 	b	.PF0f16cc1c
/*  f16cc18:	24030001 */ 	li	$v1,0x1
.PF0f16cc1c:
/*  f16cc1c:	10c00003 */ 	beqz	$a2,.PF0f16cc2c
/*  f16cc20:	00001025 */ 	move	$v0,$zero
/*  f16cc24:	10000001 */ 	b	.PF0f16cc2c
/*  f16cc28:	24020001 */ 	li	$v0,0x1
.PF0f16cc2c:
/*  f16cc2c:	00437021 */ 	addu	$t6,$v0,$v1
/*  f16cc30:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f16cc34:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f16cc38:	0218082a */ 	slt	$at,$s0,$t8
/*  f16cc3c:	1420ffd9 */ 	bnez	$at,.PF0f16cba4
/*  f16cc40:	00000000 */ 	nop
/*  f16cc44:	86390002 */ 	lh	$t9,0x2($s1)
.PF0f16cc48:
/*  f16cc48:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f16cc4c:	52b90004 */ 	beql	$s5,$t9,.PF0f16cc60
/*  f16cc50:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f16cc54:	1240ffbd */ 	beqz	$s2,.PF0f16cb4c
/*  f16cc58:	00000000 */ 	nop
.PF0f16cc5c:
/*  f16cc5c:	8fac004c */ 	lw	$t4,0x4c($sp)
.PF0f16cc60:
/*  f16cc60:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f16cc64:	00002825 */ 	move	$a1,$zero
/*  f16cc68:	258d0004 */ 	addiu	$t5,$t4,0x4
/*  f16cc6c:	11200003 */ 	beqz	$t1,.PF0f16cc7c
/*  f16cc70:	afad004c */ 	sw	$t5,0x4c($sp)
/*  f16cc74:	10000001 */ 	b	.PF0f16cc7c
/*  f16cc78:	24050001 */ 	li	$a1,0x1
.PF0f16cc7c:
/*  f16cc7c:	10e00003 */ 	beqz	$a3,.PF0f16cc8c
/*  f16cc80:	00002025 */ 	move	$a0,$zero
/*  f16cc84:	10000001 */ 	b	.PF0f16cc8c
/*  f16cc88:	24040001 */ 	li	$a0,0x1
.PF0f16cc8c:
/*  f16cc8c:	11000003 */ 	beqz	$t0,.PF0f16cc9c
/*  f16cc90:	00001825 */ 	move	$v1,$zero
/*  f16cc94:	10000001 */ 	b	.PF0f16cc9c
/*  f16cc98:	24030001 */ 	li	$v1,0x1
.PF0f16cc9c:
/*  f16cc9c:	10c00003 */ 	beqz	$a2,.PF0f16ccac
/*  f16cca0:	00001025 */ 	move	$v0,$zero
/*  f16cca4:	10000001 */ 	b	.PF0f16ccac
/*  f16cca8:	24020001 */ 	li	$v0,0x1
.PF0f16ccac:
/*  f16ccac:	00437021 */ 	addu	$t6,$v0,$v1
/*  f16ccb0:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f16ccb4:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f16ccb8:	0278082a */ 	slt	$at,$s3,$t8
/*  f16ccbc:	10200003 */ 	beqz	$at,.PF0f16cccc
/*  f16ccc0:	00000000 */ 	nop
/*  f16ccc4:	5240ff95 */ 	beqzl	$s2,.PF0f16cb1c
/*  f16ccc8:	8faf004c */ 	lw	$t7,0x4c($sp)
.PF0f16cccc:
/*  f16cccc:	5240000a */ 	beqzl	$s2,.PF0f16ccf8
/*  f16ccd0:	8e8c0034 */ 	lw	$t4,0x34($s4)
/*  f16ccd4:	8e990034 */ 	lw	$t9,0x34($s4)
/*  f16ccd8:	24150004 */ 	li	$s5,0x4
/*  f16ccdc:	2b210005 */ 	slti	$at,$t9,0x5
/*  f16cce0:	14200002 */ 	bnez	$at,.PF0f16ccec
/*  f16cce4:	00000000 */ 	nop
/*  f16cce8:	ae950034 */ 	sw	$s5,0x34($s4)
.PF0f16ccec:
/*  f16ccec:	1000001e */ 	b	.PF0f16cd68
/*  f16ccf0:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f16ccf4:	8e8c0034 */ 	lw	$t4,0x34($s4)
.PF0f16ccf8:
/*  f16ccf8:	240d0008 */ 	li	$t5,0x8
/*  f16ccfc:	29810009 */ 	slti	$at,$t4,0x9
/*  f16cd00:	14200002 */ 	bnez	$at,.PF0f16cd0c
/*  f16cd04:	00000000 */ 	nop
/*  f16cd08:	ae8d0034 */ 	sw	$t5,0x34($s4)
.PF0f16cd0c:
/*  f16cd0c:	10000016 */ 	b	.PF0f16cd68
/*  f16cd10:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f16cd14:	8e8e0034 */ 	lw	$t6,0x34($s4)
.PF0f16cd18:
/*  f16cd18:	24150004 */ 	li	$s5,0x4
/*  f16cd1c:	29c10005 */ 	slti	$at,$t6,0x5
/*  f16cd20:	14200002 */ 	bnez	$at,.PF0f16cd2c
/*  f16cd24:	00000000 */ 	nop
/*  f16cd28:	ae950034 */ 	sw	$s5,0x34($s4)
.PF0f16cd2c:
/*  f16cd2c:	1000000e */ 	b	.PF0f16cd68
/*  f16cd30:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f16cd34:	8e8f0468 */ 	lw	$t7,0x468($s4)
.PF0f16cd38:
/*  f16cd38:	51e0000b */ 	beqzl	$t7,.PF0f16cd68
/*  f16cd3c:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f16cd40:	8e9804cc */ 	lw	$t8,0x4cc($s4)
/*  f16cd44:	57000008 */ 	bnezl	$t8,.PF0f16cd68
/*  f16cd48:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f16cd4c:	8e990034 */ 	lw	$t9,0x34($s4)
/*  f16cd50:	24150004 */ 	li	$s5,0x4
/*  f16cd54:	2b210005 */ 	slti	$at,$t9,0x5
/*  f16cd58:	54200003 */ 	bnezl	$at,.PF0f16cd68
/*  f16cd5c:	8e830034 */ 	lw	$v1,0x34($s4)
/*  f16cd60:	ae950034 */ 	sw	$s5,0x34($s4)
.PF0f16cd64:
/*  f16cd64:	8e830034 */ 	lw	$v1,0x34($s4)
.PF0f16cd68:
/*  f16cd68:	8e8c003c */ 	lw	$t4,0x3c($s4)
/*  f16cd6c:	24150004 */ 	li	$s5,0x4
/*  f16cd70:	44832000 */ 	mtc1	$v1,$f4
/*  f16cd74:	006c6821 */ 	addu	$t5,$v1,$t4
/*  f16cd78:	ae8d0038 */ 	sw	$t5,0x38($s4)
/*  f16cd7c:	31ae0003 */ 	andi	$t6,$t5,0x3
/*  f16cd80:	000d7883 */ 	sra	$t7,$t5,0x2
/*  f16cd84:	ae8e003c */ 	sw	$t6,0x3c($s4)
/*  f16cd88:	18600004 */ 	blez	$v1,.PF0f16cd9c
/*  f16cd8c:	ae8f0038 */ 	sw	$t7,0x38($s4)
/*  f16cd90:	8e98000c */ 	lw	$t8,0xc($s4)
/*  f16cd94:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f16cd98:	ae99000c */ 	sw	$t9,0xc($s4)
.PF0f16cd9c:
/*  f16cd9c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f16cda0:	3c013e80 */ 	lui	$at,0x3e80
/*  f16cda4:	44814000 */ 	mtc1	$at,$f8
/*  f16cda8:	8e8c0008 */ 	lw	$t4,0x8($s4)
/*  f16cdac:	8e8d0038 */ 	lw	$t5,0x38($s4)
/*  f16cdb0:	8e8f0030 */ 	lw	$t7,0x30($s4)
/*  f16cdb4:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f16cdb8:	c690004c */ 	lwc1	$f16,0x4c($s4)
/*  f16cdbc:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f16cdc0:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f16cdc4:	ae8e0008 */ 	sw	$t6,0x8($s4)
/*  f16cdc8:	ae980030 */ 	sw	$t8,0x30($s4)
/*  f16cdcc:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16cdd0:	e68a0044 */ 	swc1	$f10,0x44($s4)
/*  f16cdd4:	e6900050 */ 	swc1	$f16,0x50($s4)
/*  f16cdd8:	c4248ed0 */ 	lwc1	$f4,-0x7130($at)
/*  f16cddc:	c6920044 */ 	lwc1	$f18,0x44($s4)
/*  f16cde0:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f16cde4:	0fc2b039 */ 	jal	0xf0ac0e4
/*  f16cde8:	e686004c */ 	swc1	$f6,0x4c($s4)
/*  f16cdec:	0fc37e77 */ 	jal	0xf0df9dc
/*  f16cdf0:	00000000 */ 	nop
/*  f16cdf4:	00002025 */ 	move	$a0,$zero
/*  f16cdf8:	0c00536a */ 	jal	0x14da8
/*  f16cdfc:	3405ffff */ 	li	$a1,0xffff
/*  f16ce00:	1440005c */ 	bnez	$v0,.PF0f16cf74
/*  f16ce04:	00000000 */ 	nop
/*  f16ce08:	0c0052e6 */ 	jal	0x14b98
/*  f16ce0c:	00002025 */ 	move	$a0,$zero
/*  f16ce10:	2841000b */ 	slti	$at,$v0,0xb
/*  f16ce14:	10200057 */ 	beqz	$at,.PF0f16cf74
/*  f16ce18:	00000000 */ 	nop
/*  f16ce1c:	0c0052e6 */ 	jal	0x14b98
/*  f16ce20:	00002025 */ 	move	$a0,$zero
/*  f16ce24:	2841fff6 */ 	slti	$at,$v0,-10
/*  f16ce28:	14200052 */ 	bnez	$at,.PF0f16cf74
/*  f16ce2c:	00000000 */ 	nop
/*  f16ce30:	0c005310 */ 	jal	0x14c40
/*  f16ce34:	00002025 */ 	move	$a0,$zero
/*  f16ce38:	2841000b */ 	slti	$at,$v0,0xb
/*  f16ce3c:	1020004d */ 	beqz	$at,.PF0f16cf74
/*  f16ce40:	00000000 */ 	nop
/*  f16ce44:	0c005310 */ 	jal	0x14c40
/*  f16ce48:	00002025 */ 	move	$a0,$zero
/*  f16ce4c:	2841fff6 */ 	slti	$at,$v0,-10
/*  f16ce50:	14200048 */ 	bnez	$at,.PF0f16cf74
/*  f16ce54:	24040001 */ 	li	$a0,0x1
/*  f16ce58:	0c00536a */ 	jal	0x14da8
/*  f16ce5c:	3405ffff */ 	li	$a1,0xffff
/*  f16ce60:	14400044 */ 	bnez	$v0,.PF0f16cf74
/*  f16ce64:	00000000 */ 	nop
/*  f16ce68:	0c0052e6 */ 	jal	0x14b98
/*  f16ce6c:	24040001 */ 	li	$a0,0x1
/*  f16ce70:	2841000b */ 	slti	$at,$v0,0xb
/*  f16ce74:	1020003f */ 	beqz	$at,.PF0f16cf74
/*  f16ce78:	00000000 */ 	nop
/*  f16ce7c:	0c0052e6 */ 	jal	0x14b98
/*  f16ce80:	24040001 */ 	li	$a0,0x1
/*  f16ce84:	2841fff6 */ 	slti	$at,$v0,-10
/*  f16ce88:	1420003a */ 	bnez	$at,.PF0f16cf74
/*  f16ce8c:	00000000 */ 	nop
/*  f16ce90:	0c005310 */ 	jal	0x14c40
/*  f16ce94:	24040001 */ 	li	$a0,0x1
/*  f16ce98:	2841000b */ 	slti	$at,$v0,0xb
/*  f16ce9c:	10200035 */ 	beqz	$at,.PF0f16cf74
/*  f16cea0:	00000000 */ 	nop
/*  f16cea4:	0c005310 */ 	jal	0x14c40
/*  f16cea8:	24040001 */ 	li	$a0,0x1
/*  f16ceac:	2841fff6 */ 	slti	$at,$v0,-10
/*  f16ceb0:	14200030 */ 	bnez	$at,.PF0f16cf74
/*  f16ceb4:	24040002 */ 	li	$a0,0x2
/*  f16ceb8:	0c00536a */ 	jal	0x14da8
/*  f16cebc:	3405ffff */ 	li	$a1,0xffff
/*  f16cec0:	1440002c */ 	bnez	$v0,.PF0f16cf74
/*  f16cec4:	00000000 */ 	nop
/*  f16cec8:	0c0052e6 */ 	jal	0x14b98
/*  f16cecc:	24040002 */ 	li	$a0,0x2
/*  f16ced0:	2841000b */ 	slti	$at,$v0,0xb
/*  f16ced4:	10200027 */ 	beqz	$at,.PF0f16cf74
/*  f16ced8:	00000000 */ 	nop
/*  f16cedc:	0c0052e6 */ 	jal	0x14b98
/*  f16cee0:	24040002 */ 	li	$a0,0x2
/*  f16cee4:	2841fff6 */ 	slti	$at,$v0,-10
/*  f16cee8:	14200022 */ 	bnez	$at,.PF0f16cf74
/*  f16ceec:	00000000 */ 	nop
/*  f16cef0:	0c005310 */ 	jal	0x14c40
/*  f16cef4:	24040002 */ 	li	$a0,0x2
/*  f16cef8:	2841000b */ 	slti	$at,$v0,0xb
/*  f16cefc:	1020001d */ 	beqz	$at,.PF0f16cf74
/*  f16cf00:	00000000 */ 	nop
/*  f16cf04:	0c005310 */ 	jal	0x14c40
/*  f16cf08:	24040002 */ 	li	$a0,0x2
/*  f16cf0c:	2841fff6 */ 	slti	$at,$v0,-10
/*  f16cf10:	14200018 */ 	bnez	$at,.PF0f16cf74
/*  f16cf14:	24040003 */ 	li	$a0,0x3
/*  f16cf18:	0c00536a */ 	jal	0x14da8
/*  f16cf1c:	3405ffff */ 	li	$a1,0xffff
/*  f16cf20:	14400014 */ 	bnez	$v0,.PF0f16cf74
/*  f16cf24:	00000000 */ 	nop
/*  f16cf28:	0c0052e6 */ 	jal	0x14b98
/*  f16cf2c:	24040003 */ 	li	$a0,0x3
/*  f16cf30:	2841000b */ 	slti	$at,$v0,0xb
/*  f16cf34:	1020000f */ 	beqz	$at,.PF0f16cf74
/*  f16cf38:	00000000 */ 	nop
/*  f16cf3c:	0c0052e6 */ 	jal	0x14b98
/*  f16cf40:	24040003 */ 	li	$a0,0x3
/*  f16cf44:	2841fff6 */ 	slti	$at,$v0,-10
/*  f16cf48:	1420000a */ 	bnez	$at,.PF0f16cf74
/*  f16cf4c:	00000000 */ 	nop
/*  f16cf50:	0c005310 */ 	jal	0x14c40
/*  f16cf54:	24040003 */ 	li	$a0,0x3
/*  f16cf58:	2841000b */ 	slti	$at,$v0,0xb
/*  f16cf5c:	10200005 */ 	beqz	$at,.PF0f16cf74
/*  f16cf60:	00000000 */ 	nop
/*  f16cf64:	0c005310 */ 	jal	0x14c40
/*  f16cf68:	24040003 */ 	li	$a0,0x3
/*  f16cf6c:	2841fff6 */ 	slti	$at,$v0,-10
/*  f16cf70:	1020000e */ 	beqz	$at,.PF0f16cfac
.PF0f16cf74:
/*  f16cf74:	3c108006 */ 	lui	$s0,0x8006
/*  f16cf78:	26102174 */ 	addiu	$s0,$s0,0x2174
/*  f16cf7c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f16cf80:	5320000b */ 	beqzl	$t9,.PF0f16cfb0
/*  f16cf84:	8e8d04b4 */ 	lw	$t5,0x4b4($s4)
/*  f16cf88:	8e8c04b4 */ 	lw	$t4,0x4b4($s4)
/*  f16cf8c:	2401005a */ 	li	$at,0x5a
/*  f16cf90:	51810006 */ 	beql	$t4,$at,.PF0f16cfac
/*  f16cf94:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f16cf98:	0fc06a32 */ 	jal	0xf01a8c8
/*  f16cf9c:	24040005 */ 	li	$a0,0x5
/*  f16cfa0:	0c0039af */ 	jal	0xe6bc
/*  f16cfa4:	2404005a */ 	li	$a0,0x5a
/*  f16cfa8:	ae000000 */ 	sw	$zero,0x0($s0)
.PF0f16cfac:
/*  f16cfac:	8e8d04b4 */ 	lw	$t5,0x4b4($s4)
.PF0f16cfb0:
/*  f16cfb0:	3c108006 */ 	lui	$s0,0x8006
/*  f16cfb4:	26102174 */ 	addiu	$s0,$s0,0x2174
/*  f16cfb8:	29a1005a */ 	slti	$at,$t5,0x5a
/*  f16cfbc:	10200072 */ 	beqz	$at,.PF0f16d188
/*  f16cfc0:	3c028006 */ 	lui	$v0,0x8006
/*  f16cfc4:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f16cfc8:	15c0006f */ 	bnez	$t6,.PF0f16d188
/*  f16cfcc:	00000000 */ 	nop
/*  f16cfd0:	8e8f04cc */ 	lw	$t7,0x4cc($s4)
/*  f16cfd4:	00002025 */ 	move	$a0,$zero
/*  f16cfd8:	15e0006b */ 	bnez	$t7,.PF0f16d188
/*  f16cfdc:	00000000 */ 	nop
/*  f16cfe0:	0c00533a */ 	jal	0x14ce8
/*  f16cfe4:	3405ffff */ 	li	$a1,0xffff
/*  f16cfe8:	14400063 */ 	bnez	$v0,.PF0f16d178
/*  f16cfec:	00000000 */ 	nop
/*  f16cff0:	0c0052e6 */ 	jal	0x14b98
/*  f16cff4:	00002025 */ 	move	$a0,$zero
/*  f16cff8:	2841000a */ 	slti	$at,$v0,0xa
/*  f16cffc:	1020005e */ 	beqz	$at,.PF0f16d178
/*  f16d000:	00000000 */ 	nop
/*  f16d004:	0c0052e6 */ 	jal	0x14b98
/*  f16d008:	00002025 */ 	move	$a0,$zero
/*  f16d00c:	2841fff7 */ 	slti	$at,$v0,-9
/*  f16d010:	14200059 */ 	bnez	$at,.PF0f16d178
/*  f16d014:	00000000 */ 	nop
/*  f16d018:	0c005310 */ 	jal	0x14c40
/*  f16d01c:	00002025 */ 	move	$a0,$zero
/*  f16d020:	2841000a */ 	slti	$at,$v0,0xa
/*  f16d024:	10200054 */ 	beqz	$at,.PF0f16d178
/*  f16d028:	00000000 */ 	nop
/*  f16d02c:	0c005310 */ 	jal	0x14c40
/*  f16d030:	00002025 */ 	move	$a0,$zero
/*  f16d034:	2841fff7 */ 	slti	$at,$v0,-9
/*  f16d038:	1420004f */ 	bnez	$at,.PF0f16d178
/*  f16d03c:	24040001 */ 	li	$a0,0x1
/*  f16d040:	0c00533a */ 	jal	0x14ce8
/*  f16d044:	3405ffff */ 	li	$a1,0xffff
/*  f16d048:	1440004b */ 	bnez	$v0,.PF0f16d178
/*  f16d04c:	00000000 */ 	nop
/*  f16d050:	0c0052e6 */ 	jal	0x14b98
/*  f16d054:	24040001 */ 	li	$a0,0x1
/*  f16d058:	2841000a */ 	slti	$at,$v0,0xa
/*  f16d05c:	10200046 */ 	beqz	$at,.PF0f16d178
/*  f16d060:	00000000 */ 	nop
/*  f16d064:	0c0052e6 */ 	jal	0x14b98
/*  f16d068:	24040001 */ 	li	$a0,0x1
/*  f16d06c:	2841fff7 */ 	slti	$at,$v0,-9
/*  f16d070:	14200041 */ 	bnez	$at,.PF0f16d178
/*  f16d074:	00000000 */ 	nop
/*  f16d078:	0c005310 */ 	jal	0x14c40
/*  f16d07c:	24040001 */ 	li	$a0,0x1
/*  f16d080:	2841000a */ 	slti	$at,$v0,0xa
/*  f16d084:	1020003c */ 	beqz	$at,.PF0f16d178
/*  f16d088:	00000000 */ 	nop
/*  f16d08c:	0c005310 */ 	jal	0x14c40
/*  f16d090:	24040001 */ 	li	$a0,0x1
/*  f16d094:	2841fff7 */ 	slti	$at,$v0,-9
/*  f16d098:	14200037 */ 	bnez	$at,.PF0f16d178
/*  f16d09c:	24040002 */ 	li	$a0,0x2
/*  f16d0a0:	0c00533a */ 	jal	0x14ce8
/*  f16d0a4:	3405ffff */ 	li	$a1,0xffff
/*  f16d0a8:	14400033 */ 	bnez	$v0,.PF0f16d178
/*  f16d0ac:	00000000 */ 	nop
/*  f16d0b0:	0c0052e6 */ 	jal	0x14b98
/*  f16d0b4:	24040002 */ 	li	$a0,0x2
/*  f16d0b8:	2841000a */ 	slti	$at,$v0,0xa
/*  f16d0bc:	1020002e */ 	beqz	$at,.PF0f16d178
/*  f16d0c0:	00000000 */ 	nop
/*  f16d0c4:	0c0052e6 */ 	jal	0x14b98
/*  f16d0c8:	24040002 */ 	li	$a0,0x2
/*  f16d0cc:	2841fff7 */ 	slti	$at,$v0,-9
/*  f16d0d0:	14200029 */ 	bnez	$at,.PF0f16d178
/*  f16d0d4:	00000000 */ 	nop
/*  f16d0d8:	0c005310 */ 	jal	0x14c40
/*  f16d0dc:	24040002 */ 	li	$a0,0x2
/*  f16d0e0:	2841000a */ 	slti	$at,$v0,0xa
/*  f16d0e4:	10200024 */ 	beqz	$at,.PF0f16d178
/*  f16d0e8:	00000000 */ 	nop
/*  f16d0ec:	0c005310 */ 	jal	0x14c40
/*  f16d0f0:	24040002 */ 	li	$a0,0x2
/*  f16d0f4:	2841fff7 */ 	slti	$at,$v0,-9
/*  f16d0f8:	1420001f */ 	bnez	$at,.PF0f16d178
/*  f16d0fc:	24040003 */ 	li	$a0,0x3
/*  f16d100:	0c00533a */ 	jal	0x14ce8
/*  f16d104:	3405ffff */ 	li	$a1,0xffff
/*  f16d108:	1440001b */ 	bnez	$v0,.PF0f16d178
/*  f16d10c:	00000000 */ 	nop
/*  f16d110:	0c0052e6 */ 	jal	0x14b98
/*  f16d114:	24040003 */ 	li	$a0,0x3
/*  f16d118:	2841000a */ 	slti	$at,$v0,0xa
/*  f16d11c:	10200016 */ 	beqz	$at,.PF0f16d178
/*  f16d120:	00000000 */ 	nop
/*  f16d124:	0c0052e6 */ 	jal	0x14b98
/*  f16d128:	24040003 */ 	li	$a0,0x3
/*  f16d12c:	2841fff7 */ 	slti	$at,$v0,-9
/*  f16d130:	14200011 */ 	bnez	$at,.PF0f16d178
/*  f16d134:	00000000 */ 	nop
/*  f16d138:	0c005310 */ 	jal	0x14c40
/*  f16d13c:	24040003 */ 	li	$a0,0x3
/*  f16d140:	2841000a */ 	slti	$at,$v0,0xa
/*  f16d144:	1020000c */ 	beqz	$at,.PF0f16d178
/*  f16d148:	00000000 */ 	nop
/*  f16d14c:	0c005310 */ 	jal	0x14c40
/*  f16d150:	24040003 */ 	li	$a0,0x3
/*  f16d154:	2841fff7 */ 	slti	$at,$v0,-9
/*  f16d158:	14200007 */ 	bnez	$at,.PF0f16d178
/*  f16d15c:	3c028006 */ 	lui	$v0,0x8006
/*  f16d160:	24422180 */ 	addiu	$v0,$v0,0x2180
/*  f16d164:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f16d168:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f16d16c:	03196021 */ 	addu	$t4,$t8,$t9
/*  f16d170:	10000007 */ 	b	.PF0f16d190
/*  f16d174:	ac4c0000 */ 	sw	$t4,0x0($v0)
.PF0f16d178:
/*  f16d178:	3c028006 */ 	lui	$v0,0x8006
/*  f16d17c:	24422180 */ 	addiu	$v0,$v0,0x2180
/*  f16d180:	10000003 */ 	b	.PF0f16d190
/*  f16d184:	ac400000 */ 	sw	$zero,0x0($v0)
.PF0f16d188:
/*  f16d188:	24422180 */ 	addiu	$v0,$v0,0x2180
/*  f16d18c:	ac400000 */ 	sw	$zero,0x0($v0)
.PF0f16d190:
/*  f16d190:	8e8d0318 */ 	lw	$t5,0x318($s4)
/*  f16d194:	3c118008 */ 	lui	$s1,0x8008
/*  f16d198:	26314578 */ 	addiu	$s1,$s1,0x4578
/*  f16d19c:	11a00139 */ 	beqz	$t5,.PF0f16d684
/*  f16d1a0:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f16d1a4:	8e8e04b4 */ 	lw	$t6,0x4b4($s4)
/*  f16d1a8:	3c038008 */ 	lui	$v1,0x8008
/*  f16d1ac:	29c1005a */ 	slti	$at,$t6,0x5a
/*  f16d1b0:	10200134 */ 	beqz	$at,.PF0f16d684
/*  f16d1b4:	00000000 */ 	nop
/*  f16d1b8:	8c634568 */ 	lw	$v1,0x4568($v1)
/*  f16d1bc:	3c028008 */ 	lui	$v0,0x8008
/*  f16d1c0:	2401003c */ 	li	$at,0x3c
/*  f16d1c4:	18600098 */ 	blez	$v1,.PF0f16d428
/*  f16d1c8:	00033080 */ 	sll	$a2,$v1,0x2
/*  f16d1cc:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f16d1d0:	000630c0 */ 	sll	$a2,$a2,0x3
/*  f16d1d4:	00c33021 */ 	addu	$a2,$a2,$v1
/*  f16d1d8:	00063040 */ 	sll	$a2,$a2,0x1
/*  f16d1dc:	00c1001a */ 	div	$zero,$a2,$at
/*  f16d1e0:	8c534564 */ 	lw	$s3,0x4564($v0)
/*  f16d1e4:	00003012 */ 	mflo	$a2
/*  f16d1e8:	8e8f0038 */ 	lw	$t7,0x38($s4)
/*  f16d1ec:	24c4f448 */ 	addiu	$a0,$a2,-3000
/*  f16d1f0:	0264082a */ 	slt	$at,$s3,$a0
/*  f16d1f4:	10200052 */ 	beqz	$at,.PF0f16d340
/*  f16d1f8:	01f39021 */ 	addu	$s2,$t7,$s3
/*  f16d1fc:	0244082a */ 	slt	$at,$s2,$a0
/*  f16d200:	54200050 */ 	bnezl	$at,.PF0f16d344
/*  f16d204:	0266082a */ 	slt	$at,$s3,$a2
/*  f16d208:	8e99006c */ 	lw	$t9,0x6c($s4)
/*  f16d20c:	00008025 */ 	move	$s0,$zero
/*  f16d210:	00002825 */ 	move	$a1,$zero
/*  f16d214:	13200003 */ 	beqz	$t9,.PF0f16d224
/*  f16d218:	00002025 */ 	move	$a0,$zero
/*  f16d21c:	10000001 */ 	b	.PF0f16d224
/*  f16d220:	24050001 */ 	li	$a1,0x1
.PF0f16d224:
/*  f16d224:	8e8c0068 */ 	lw	$t4,0x68($s4)
/*  f16d228:	00001825 */ 	move	$v1,$zero
/*  f16d22c:	00001025 */ 	move	$v0,$zero
/*  f16d230:	11800003 */ 	beqz	$t4,.PF0f16d240
/*  f16d234:	00000000 */ 	nop
/*  f16d238:	10000001 */ 	b	.PF0f16d240
/*  f16d23c:	24040001 */ 	li	$a0,0x1
.PF0f16d240:
/*  f16d240:	8e8d0064 */ 	lw	$t5,0x64($s4)
/*  f16d244:	11a00003 */ 	beqz	$t5,.PF0f16d254
/*  f16d248:	00000000 */ 	nop
/*  f16d24c:	10000001 */ 	b	.PF0f16d254
/*  f16d250:	24030001 */ 	li	$v1,0x1
.PF0f16d254:
/*  f16d254:	8e8e0070 */ 	lw	$t6,0x70($s4)
/*  f16d258:	11c00003 */ 	beqz	$t6,.PF0f16d268
/*  f16d25c:	00000000 */ 	nop
/*  f16d260:	10000001 */ 	b	.PF0f16d268
/*  f16d264:	24020001 */ 	li	$v0,0x1
.PF0f16d268:
/*  f16d268:	00437821 */ 	addu	$t7,$v0,$v1
/*  f16d26c:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f16d270:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f16d274:	5b200033 */ 	blezl	$t9,.PF0f16d344
/*  f16d278:	0266082a */ 	slt	$at,$s3,$a2
.PF0f16d27c:
/*  f16d27c:	0fc4a4ff */ 	jal	0xf1293fc
/*  f16d280:	02002025 */ 	move	$a0,$s0
/*  f16d284:	0fc5bdaa */ 	jal	0xf16f6a8
/*  f16d288:	24045807 */ 	li	$a0,0x5807
/*  f16d28c:	00402025 */ 	move	$a0,$v0
/*  f16d290:	0fc37954 */ 	jal	0xf0de550
/*  f16d294:	00002825 */ 	move	$a1,$zero
/*  f16d298:	8e8c006c */ 	lw	$t4,0x6c($s4)
/*  f16d29c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f16d2a0:	00002825 */ 	move	$a1,$zero
/*  f16d2a4:	11800003 */ 	beqz	$t4,.PF0f16d2b4
/*  f16d2a8:	00002025 */ 	move	$a0,$zero
/*  f16d2ac:	10000001 */ 	b	.PF0f16d2b4
/*  f16d2b0:	24050001 */ 	li	$a1,0x1
.PF0f16d2b4:
/*  f16d2b4:	8e8d0068 */ 	lw	$t5,0x68($s4)
/*  f16d2b8:	00001825 */ 	move	$v1,$zero
/*  f16d2bc:	00001025 */ 	move	$v0,$zero
/*  f16d2c0:	11a00003 */ 	beqz	$t5,.PF0f16d2d0
/*  f16d2c4:	00000000 */ 	nop
/*  f16d2c8:	10000001 */ 	b	.PF0f16d2d0
/*  f16d2cc:	24040001 */ 	li	$a0,0x1
.PF0f16d2d0:
/*  f16d2d0:	8e8e0064 */ 	lw	$t6,0x64($s4)
/*  f16d2d4:	11c00003 */ 	beqz	$t6,.PF0f16d2e4
/*  f16d2d8:	00000000 */ 	nop
/*  f16d2dc:	10000001 */ 	b	.PF0f16d2e4
/*  f16d2e0:	24030001 */ 	li	$v1,0x1
.PF0f16d2e4:
/*  f16d2e4:	8e8f0070 */ 	lw	$t7,0x70($s4)
/*  f16d2e8:	11e00003 */ 	beqz	$t7,.PF0f16d2f8
/*  f16d2ec:	00000000 */ 	nop
/*  f16d2f0:	10000001 */ 	b	.PF0f16d2f8
/*  f16d2f4:	24020001 */ 	li	$v0,0x1
.PF0f16d2f8:
/*  f16d2f8:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f16d2fc:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f16d300:	03256021 */ 	addu	$t4,$t9,$a1
/*  f16d304:	020c082a */ 	slt	$at,$s0,$t4
/*  f16d308:	1420ffdc */ 	bnez	$at,.PF0f16d27c
/*  f16d30c:	00000000 */ 	nop
/*  f16d310:	3c068008 */ 	lui	$a2,0x8008
/*  f16d314:	8cc64568 */ 	lw	$a2,0x4568($a2)
/*  f16d318:	2401003c */ 	li	$at,0x3c
/*  f16d31c:	00066880 */ 	sll	$t5,$a2,0x2
/*  f16d320:	01a66823 */ 	subu	$t5,$t5,$a2
/*  f16d324:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f16d328:	01a66821 */ 	addu	$t5,$t5,$a2
/*  f16d32c:	000d6840 */ 	sll	$t5,$t5,0x1
/*  f16d330:	01a1001a */ 	div	$zero,$t5,$at
/*  f16d334:	00003012 */ 	mflo	$a2
/*  f16d338:	00000000 */ 	nop
/*  f16d33c:	00000000 */ 	nop
.PF0f16d340:
/*  f16d340:	0266082a */ 	slt	$at,$s3,$a2
.PF0f16d344:
/*  f16d344:	10200011 */ 	beqz	$at,.PF0f16d38c
/*  f16d348:	0246082a */ 	slt	$at,$s2,$a2
/*  f16d34c:	54200010 */ 	bnezl	$at,.PF0f16d390
/*  f16d350:	24d9fe0c */ 	addiu	$t9,$a2,-500
/*  f16d354:	0c0038f9 */ 	jal	0xe3e4
/*  f16d358:	00000000 */ 	nop
/*  f16d35c:	3c068008 */ 	lui	$a2,0x8008
/*  f16d360:	8cc64568 */ 	lw	$a2,0x4568($a2)
/*  f16d364:	2401003c */ 	li	$at,0x3c
/*  f16d368:	00067880 */ 	sll	$t7,$a2,0x2
/*  f16d36c:	01e67823 */ 	subu	$t7,$t7,$a2
/*  f16d370:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f16d374:	01e67821 */ 	addu	$t7,$t7,$a2
/*  f16d378:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f16d37c:	01e1001a */ 	div	$zero,$t7,$at
/*  f16d380:	00003012 */ 	mflo	$a2
/*  f16d384:	00000000 */ 	nop
/*  f16d388:	00000000 */ 	nop
.PF0f16d38c:
/*  f16d38c:	24d9fe0c */ 	addiu	$t9,$a2,-500
.PF0f16d390:
/*  f16d390:	0259082a */ 	slt	$at,$s2,$t9
/*  f16d394:	14200024 */ 	bnez	$at,.PF0f16d428
/*  f16d398:	3c108008 */ 	lui	$s0,0x8008
/*  f16d39c:	26104574 */ 	addiu	$s0,$s0,0x4574
/*  f16d3a0:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f16d3a4:	55800021 */ 	bnezl	$t4,.PF0f16d42c
/*  f16d3a8:	8e8e0034 */ 	lw	$t6,0x34($s4)
/*  f16d3ac:	0fc5b6f7 */ 	jal	0xf16dbdc
/*  f16d3b0:	00000000 */ 	nop
/*  f16d3b4:	1440001c */ 	bnez	$v0,.PF0f16d428
/*  f16d3b8:	3c0d8008 */ 	lui	$t5,0x8008
/*  f16d3bc:	8dad4568 */ 	lw	$t5,0x4568($t5)
/*  f16d3c0:	2401003c */ 	li	$at,0x3c
/*  f16d3c4:	02002025 */ 	move	$a0,$s0
/*  f16d3c8:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f16d3cc:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f16d3d0:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f16d3d4:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f16d3d8:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f16d3dc:	01c1001a */ 	div	$zero,$t6,$at
/*  f16d3e0:	00007812 */ 	mflo	$t7
/*  f16d3e4:	024f082a */ 	slt	$at,$s2,$t7
/*  f16d3e8:	1020000f */ 	beqz	$at,.PF0f16d428
/*  f16d3ec:	00002825 */ 	move	$a1,$zero
/*  f16d3f0:	3c013f80 */ 	lui	$at,0x3f80
/*  f16d3f4:	44814000 */ 	mtc1	$at,$f8
/*  f16d3f8:	241800a3 */ 	li	$t8,0xa3
/*  f16d3fc:	24190001 */ 	li	$t9,0x1
/*  f16d400:	240cffff */ 	li	$t4,-1
/*  f16d404:	240d0001 */ 	li	$t5,0x1
/*  f16d408:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f16d40c:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f16d410:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f16d414:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f16d418:	24067fff */ 	li	$a2,0x7fff
/*  f16d41c:	24070040 */ 	li	$a3,0x40
/*  f16d420:	0c004125 */ 	jal	0x10494
/*  f16d424:	e7a80014 */ 	swc1	$f8,0x14($sp)
.PF0f16d428:
/*  f16d428:	8e8e0034 */ 	lw	$t6,0x34($s4)
.PF0f16d42c:
/*  f16d42c:	00008025 */ 	move	$s0,$zero
/*  f16d430:	00005825 */ 	move	$t3,$zero
/*  f16d434:	11c00093 */ 	beqz	$t6,.PF0f16d684
/*  f16d438:	00000000 */ 	nop
/*  f16d43c:	8e89006c */ 	lw	$t1,0x6c($s4)
/*  f16d440:	8e870068 */ 	lw	$a3,0x68($s4)
/*  f16d444:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f16d448:	11200003 */ 	beqz	$t1,.PF0f16d458
/*  f16d44c:	8e860070 */ 	lw	$a2,0x70($s4)
/*  f16d450:	10000002 */ 	b	.PF0f16d45c
/*  f16d454:	24050001 */ 	li	$a1,0x1
.PF0f16d458:
/*  f16d458:	00002825 */ 	move	$a1,$zero
.PF0f16d45c:
/*  f16d45c:	10e00003 */ 	beqz	$a3,.PF0f16d46c
/*  f16d460:	00002025 */ 	move	$a0,$zero
/*  f16d464:	10000001 */ 	b	.PF0f16d46c
/*  f16d468:	24040001 */ 	li	$a0,0x1
.PF0f16d46c:
/*  f16d46c:	11000003 */ 	beqz	$t0,.PF0f16d47c
/*  f16d470:	00001825 */ 	move	$v1,$zero
/*  f16d474:	10000001 */ 	b	.PF0f16d47c
/*  f16d478:	24030001 */ 	li	$v1,0x1
.PF0f16d47c:
/*  f16d47c:	10c00003 */ 	beqz	$a2,.PF0f16d48c
/*  f16d480:	00001025 */ 	move	$v0,$zero
/*  f16d484:	10000001 */ 	b	.PF0f16d48c
/*  f16d488:	24020001 */ 	li	$v0,0x1
.PF0f16d48c:
/*  f16d48c:	00437821 */ 	addu	$t7,$v0,$v1
/*  f16d490:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f16d494:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f16d498:	1b20002d */ 	blez	$t9,.PF0f16d550
/*  f16d49c:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f16d4a0:	44800000 */ 	mtc1	$zero,$f0
/*  f16d4a4:	028c5021 */ 	addu	$t2,$s4,$t4
/*  f16d4a8:	8d420064 */ 	lw	$v0,0x64($t2)
.PF0f16d4ac:
/*  f16d4ac:	256b0001 */ 	addiu	$t3,$t3,0x1
/*  f16d4b0:	00002825 */ 	move	$a1,$zero
/*  f16d4b4:	8c4d00d8 */ 	lw	$t5,0xd8($v0)
/*  f16d4b8:	00002025 */ 	move	$a0,$zero
/*  f16d4bc:	00001825 */ 	move	$v1,$zero
/*  f16d4c0:	11a0000d */ 	beqz	$t5,.PF0f16d4f8
/*  f16d4c4:	00000000 */ 	nop
/*  f16d4c8:	8c4e032c */ 	lw	$t6,0x32c($v0)
/*  f16d4cc:	51c0000a */ 	beqzl	$t6,.PF0f16d4f8
/*  f16d4d0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f16d4d4:	8c4f0330 */ 	lw	$t7,0x330($v0)
/*  f16d4d8:	51e00007 */ 	beqzl	$t7,.PF0f16d4f8
/*  f16d4dc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f16d4e0:	c44a02ec */ 	lwc1	$f10,0x2ec($v0)
/*  f16d4e4:	460a003e */ 	c.le.s	$f0,$f10
/*  f16d4e8:	00000000 */ 	nop
/*  f16d4ec:	45000002 */ 	bc1f	.PF0f16d4f8
/*  f16d4f0:	00000000 */ 	nop
/*  f16d4f4:	26100001 */ 	addiu	$s0,$s0,0x1
.PF0f16d4f8:
/*  f16d4f8:	11200003 */ 	beqz	$t1,.PF0f16d508
/*  f16d4fc:	254a0004 */ 	addiu	$t2,$t2,0x4
/*  f16d500:	10000001 */ 	b	.PF0f16d508
/*  f16d504:	24050001 */ 	li	$a1,0x1
.PF0f16d508:
/*  f16d508:	10e00003 */ 	beqz	$a3,.PF0f16d518
/*  f16d50c:	00001025 */ 	move	$v0,$zero
/*  f16d510:	10000001 */ 	b	.PF0f16d518
/*  f16d514:	24040001 */ 	li	$a0,0x1
.PF0f16d518:
/*  f16d518:	11000003 */ 	beqz	$t0,.PF0f16d528
/*  f16d51c:	00000000 */ 	nop
/*  f16d520:	10000001 */ 	b	.PF0f16d528
/*  f16d524:	24030001 */ 	li	$v1,0x1
.PF0f16d528:
/*  f16d528:	10c00003 */ 	beqz	$a2,.PF0f16d538
/*  f16d52c:	00000000 */ 	nop
/*  f16d530:	10000001 */ 	b	.PF0f16d538
/*  f16d534:	24020001 */ 	li	$v0,0x1
.PF0f16d538:
/*  f16d538:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f16d53c:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f16d540:	03256021 */ 	addu	$t4,$t9,$a1
/*  f16d544:	016c082a */ 	slt	$at,$t3,$t4
/*  f16d548:	5420ffd8 */ 	bnezl	$at,.PF0f16d4ac
/*  f16d54c:	8d420064 */ 	lw	$v0,0x64($t2)
.PF0f16d550:
/*  f16d550:	3c04800b */ 	lui	$a0,0x800b
/*  f16d554:	8c84cad0 */ 	lw	$a0,-0x3530($a0)
/*  f16d558:	3c0d800b */ 	lui	$t5,0x800b
/*  f16d55c:	25a2ca70 */ 	addiu	$v0,$t5,-13712
/*  f16d560:	1880000c */ 	blez	$a0,.PF0f16d594
/*  f16d564:	3c198008 */ 	lui	$t9,0x8008
/*  f16d568:	00047080 */ 	sll	$t6,$a0,0x2
/*  f16d56c:	01c21821 */ 	addu	$v1,$t6,$v0
/*  f16d570:	8c4f0000 */ 	lw	$t7,0x0($v0)
.PF0f16d574:
/*  f16d574:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f16d578:	0043082b */ 	sltu	$at,$v0,$v1
/*  f16d57c:	81f80007 */ 	lb	$t8,0x7($t7)
/*  f16d580:	16b80002 */ 	bne	$s5,$t8,.PF0f16d58c
/*  f16d584:	00000000 */ 	nop
/*  f16d588:	26100001 */ 	addiu	$s0,$s0,0x1
.PF0f16d58c:
/*  f16d58c:	5420fff9 */ 	bnezl	$at,.PF0f16d574
/*  f16d590:	8c4f0000 */ 	lw	$t7,0x0($v0)
.PF0f16d594:
/*  f16d594:	8f39456c */ 	lw	$t9,0x456c($t9)
/*  f16d598:	27a4016c */ 	addiu	$a0,$sp,0x16c
/*  f16d59c:	1b200017 */ 	blez	$t9,.PF0f16d5fc
/*  f16d5a0:	00000000 */ 	nop
/*  f16d5a4:	0fc625a2 */ 	jal	0xf189688
/*  f16d5a8:	00005825 */ 	move	$t3,$zero
/*  f16d5ac:	18400013 */ 	blez	$v0,.PF0f16d5fc
/*  f16d5b0:	00401825 */ 	move	$v1,$v0
/*  f16d5b4:	00037080 */ 	sll	$t6,$v1,0x2
/*  f16d5b8:	01c37021 */ 	addu	$t6,$t6,$v1
/*  f16d5bc:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f16d5c0:	3c048008 */ 	lui	$a0,0x8008
/*  f16d5c4:	27a2016c */ 	addiu	$v0,$sp,0x16c
/*  f16d5c8:	01c22821 */ 	addu	$a1,$t6,$v0
/*  f16d5cc:	8c84456c */ 	lw	$a0,0x456c($a0)
/*  f16d5d0:	8c4d0010 */ 	lw	$t5,0x10($v0)
.PF0f16d5d4:
/*  f16d5d4:	24420014 */ 	addiu	$v0,$v0,0x14
/*  f16d5d8:	01a4082a */ 	slt	$at,$t5,$a0
/*  f16d5dc:	54200005 */ 	bnezl	$at,.PF0f16d5f4
/*  f16d5e0:	0045082b */ 	sltu	$at,$v0,$a1
/*  f16d5e4:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f16d5e8:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f16d5ec:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f16d5f0:	0045082b */ 	sltu	$at,$v0,$a1
.PF0f16d5f4:
/*  f16d5f4:	5420fff7 */ 	bnezl	$at,.PF0f16d5d4
/*  f16d5f8:	8c4d0010 */ 	lw	$t5,0x10($v0)
.PF0f16d5fc:
/*  f16d5fc:	3c198008 */ 	lui	$t9,0x8008
/*  f16d600:	8f394570 */ 	lw	$t9,0x4570($t9)
/*  f16d604:	27a40078 */ 	addiu	$a0,$sp,0x78
/*  f16d608:	5b200018 */ 	blezl	$t9,.PF0f16d66c
/*  f16d60c:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f16d610:	0fc626ca */ 	jal	0xf189b28
/*  f16d614:	00005825 */ 	move	$t3,$zero
/*  f16d618:	18400013 */ 	blez	$v0,.PF0f16d668
/*  f16d61c:	00401825 */ 	move	$v1,$v0
/*  f16d620:	00036080 */ 	sll	$t4,$v1,0x2
/*  f16d624:	01836021 */ 	addu	$t4,$t4,$v1
/*  f16d628:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f16d62c:	3c048008 */ 	lui	$a0,0x8008
/*  f16d630:	27a20078 */ 	addiu	$v0,$sp,0x78
/*  f16d634:	01822821 */ 	addu	$a1,$t4,$v0
/*  f16d638:	8c844570 */ 	lw	$a0,0x4570($a0)
/*  f16d63c:	8c4d0010 */ 	lw	$t5,0x10($v0)
.PF0f16d640:
/*  f16d640:	24420014 */ 	addiu	$v0,$v0,0x14
/*  f16d644:	01a4082a */ 	slt	$at,$t5,$a0
/*  f16d648:	54200005 */ 	bnezl	$at,.PF0f16d660
/*  f16d64c:	0045082b */ 	sltu	$at,$v0,$a1
/*  f16d650:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f16d654:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f16d658:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f16d65c:	0045082b */ 	sltu	$at,$v0,$a1
.PF0f16d660:
/*  f16d660:	5420fff7 */ 	bnezl	$at,.PF0f16d640
/*  f16d664:	8c4d0010 */ 	lw	$t5,0x10($v0)
.PF0f16d668:
/*  f16d668:	8e390000 */ 	lw	$t9,0x0($s1)
.PF0f16d66c:
/*  f16d66c:	1b200005 */ 	blez	$t9,.PF0f16d684
/*  f16d670:	00000000 */ 	nop
/*  f16d674:	16000003 */ 	bnez	$s0,.PF0f16d684
/*  f16d678:	00000000 */ 	nop
/*  f16d67c:	0c0038f9 */ 	jal	0xe3e4
/*  f16d680:	00000000 */ 	nop
.PF0f16d684:
/*  f16d684:	3c0c8008 */ 	lui	$t4,0x8008
/*  f16d688:	8d8c4564 */ 	lw	$t4,0x4564($t4)
/*  f16d68c:	8e8e0038 */ 	lw	$t6,0x38($s4)
/*  f16d690:	3c018008 */ 	lui	$at,0x8008
/*  f16d694:	24040001 */ 	li	$a0,0x1
/*  f16d698:	018e6821 */ 	addu	$t5,$t4,$t6
/*  f16d69c:	448d8000 */ 	mtc1	$t5,$f16
/*  f16d6a0:	ac2d4564 */ 	sw	$t5,0x4564($at)
/*  f16d6a4:	3c014248 */ 	lui	$at,0x4248
/*  f16d6a8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f16d6ac:	44812000 */ 	mtc1	$at,$f4
/*  f16d6b0:	3c018008 */ 	lui	$at,0x8008
/*  f16d6b4:	46049183 */ 	div.s	$f6,$f18,$f4
/*  f16d6b8:	0c002e99 */ 	jal	0xba64
/*  f16d6bc:	e426457c */ 	swc1	$f6,0x457c($at)
/*  f16d6c0:	8e8204b4 */ 	lw	$v0,0x4b4($s4)
/*  f16d6c4:	2401004e */ 	li	$at,0x4e
/*  f16d6c8:	54410007 */ 	bnel	$v0,$at,.PF0f16d6e8
/*  f16d6cc:	2401005a */ 	li	$at,0x5a
/*  f16d6d0:	0fc06bc9 */ 	jal	0xf01af24
/*  f16d6d4:	00000000 */ 	nop
/*  f16d6d8:	0c0046c5 */ 	jal	0x11b14
/*  f16d6dc:	00000000 */ 	nop
/*  f16d6e0:	8e8204b4 */ 	lw	$v0,0x4b4($s4)
/*  f16d6e4:	2401005a */ 	li	$at,0x5a
.PF0f16d6e8:
/*  f16d6e8:	5441000a */ 	bnel	$v0,$at,.PF0f16d714
/*  f16d6ec:	2401005b */ 	li	$at,0x5b
/*  f16d6f0:	0fc06a3d */ 	jal	0xf01a8f4
/*  f16d6f4:	00000000 */ 	nop
/*  f16d6f8:	0fc0764c */ 	jal	0xf01d930
/*  f16d6fc:	00000000 */ 	nop
/*  f16d700:	0c0046c5 */ 	jal	0x11b14
/*  f16d704:	00000000 */ 	nop
/*  f16d708:	10000089 */ 	b	.PF0f16d930
/*  f16d70c:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f16d710:	2401005b */ 	li	$at,0x5b
.PF0f16d714:
/*  f16d714:	54410010 */ 	bnel	$v0,$at,.PF0f16d758
/*  f16d718:	2401005d */ 	li	$at,0x5d
/*  f16d71c:	0fc4a4ff */ 	jal	0xf1293fc
/*  f16d720:	00002025 */ 	move	$a0,$zero
/*  f16d724:	0fc2f738 */ 	jal	0xf0bdce0
/*  f16d728:	00000000 */ 	nop
/*  f16d72c:	0fc07006 */ 	jal	0xf01c018
/*  f16d730:	00000000 */ 	nop
/*  f16d734:	0c0046c5 */ 	jal	0x11b14
/*  f16d738:	00000000 */ 	nop
/*  f16d73c:	0fc0764c */ 	jal	0xf01d930
/*  f16d740:	00000000 */ 	nop
/*  f16d744:	0fc474a7 */ 	jal	0xf11d29c
/*  f16d748:	00000000 */ 	nop
/*  f16d74c:	10000078 */ 	b	.PF0f16d930
/*  f16d750:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f16d754:	2401005d */ 	li	$at,0x5d
.PF0f16d758:
/*  f16d758:	5441000c */ 	bnel	$v0,$at,.PF0f16d78c
/*  f16d75c:	2401005c */ 	li	$at,0x5c
/*  f16d760:	0fc07006 */ 	jal	0xf01c018
/*  f16d764:	00000000 */ 	nop
/*  f16d768:	0c0046c5 */ 	jal	0x11b14
/*  f16d76c:	00000000 */ 	nop
/*  f16d770:	0fc0764c */ 	jal	0xf01d930
/*  f16d774:	00000000 */ 	nop
/*  f16d778:	0fc474a7 */ 	jal	0xf11d29c
/*  f16d77c:	00000000 */ 	nop
/*  f16d780:	1000006b */ 	b	.PF0f16d930
/*  f16d784:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f16d788:	2401005c */ 	li	$at,0x5c
.PF0f16d78c:
/*  f16d78c:	14410007 */ 	bne	$v0,$at,.PF0f16d7ac
/*  f16d790:	00000000 */ 	nop
/*  f16d794:	0c0046c5 */ 	jal	0x11b14
/*  f16d798:	00000000 */ 	nop
/*  f16d79c:	0fc0764c */ 	jal	0xf01d930
/*  f16d7a0:	00000000 */ 	nop
/*  f16d7a4:	10000062 */ 	b	.PF0f16d930
/*  f16d7a8:	8fbf0044 */ 	lw	$ra,0x44($sp)
.PF0f16d7ac:
/*  f16d7ac:	0fc5b16f */ 	jal	0xf16c5bc
/*  f16d7b0:	00000000 */ 	nop
/*  f16d7b4:	0fc4a79b */ 	jal	0xf129e6c
/*  f16d7b8:	00000000 */ 	nop
/*  f16d7bc:	0fc5af9f */ 	jal	0xf16be7c
/*  f16d7c0:	00000000 */ 	nop
/*  f16d7c4:	0fc07678 */ 	jal	0xf01d9e0
/*  f16d7c8:	00000000 */ 	nop
/*  f16d7cc:	0fc076ac */ 	jal	0xf01dab0
/*  f16d7d0:	00000000 */ 	nop
/*  f16d7d4:	0fc077a3 */ 	jal	0xf01de8c
/*  f16d7d8:	00000000 */ 	nop
/*  f16d7dc:	0fc077d4 */ 	jal	0xf01df50
/*  f16d7e0:	00000000 */ 	nop
/*  f16d7e4:	0fc0785c */ 	jal	0xf01e170
/*  f16d7e8:	00000000 */ 	nop
/*  f16d7ec:	0fc4fdad */ 	jal	0xf13f6b4
/*  f16d7f0:	00000000 */ 	nop
/*  f16d7f4:	0fc52945 */ 	jal	0xf14a514
/*  f16d7f8:	00000000 */ 	nop
/*  f16d7fc:	3c0f8006 */ 	lui	$t7,0x8006
/*  f16d800:	8def20c0 */ 	lw	$t7,0x20c0($t7)
/*  f16d804:	11e00003 */ 	beqz	$t7,.PF0f16d814
/*  f16d808:	00000000 */ 	nop
/*  f16d80c:	0fc07610 */ 	jal	0xf01d840
/*  f16d810:	00000000 */ 	nop
.PF0f16d814:
/*  f16d814:	3c188006 */ 	lui	$t8,0x8006
/*  f16d818:	8f181310 */ 	lw	$t8,0x1310($t8)
/*  f16d81c:	13000003 */ 	beqz	$t8,.PF0f16d82c
/*  f16d820:	00000000 */ 	nop
/*  f16d824:	0fc027af */ 	jal	0xf009ebc
/*  f16d828:	00000000 */ 	nop
.PF0f16d82c:
/*  f16d82c:	0fc5a302 */ 	jal	0xf168c08
/*  f16d830:	00000000 */ 	nop
/*  f16d834:	0c003f01 */ 	jal	0xfc04
/*  f16d838:	00000000 */ 	nop
/*  f16d83c:	0fc474a7 */ 	jal	0xf11d29c
/*  f16d840:	00000000 */ 	nop
/*  f16d844:	0fc00cec */ 	jal	0xf0033b0
/*  f16d848:	00000000 */ 	nop
/*  f16d84c:	0fc2cb89 */ 	jal	0xf0b2e24
/*  f16d850:	00000000 */ 	nop
/*  f16d854:	0fc2bd1e */ 	jal	0xf0af478
/*  f16d858:	00000000 */ 	nop
/*  f16d85c:	0fc06c94 */ 	jal	0xf01b250
/*  f16d860:	00000000 */ 	nop
/*  f16d864:	0fc07006 */ 	jal	0xf01c018
/*  f16d868:	00000000 */ 	nop
/*  f16d86c:	0fc619ac */ 	jal	0xf1866b0
/*  f16d870:	00000000 */ 	nop
/*  f16d874:	3c198006 */ 	lui	$t9,0x8006
/*  f16d878:	8f39d670 */ 	lw	$t9,-0x2990($t9)
/*  f16d87c:	17200003 */ 	bnez	$t9,.PF0f16d88c
/*  f16d880:	00000000 */ 	nop
/*  f16d884:	0fc078dc */ 	jal	0xf01e370
/*  f16d888:	00000000 */ 	nop
.PF0f16d88c:
/*  f16d88c:	0c0046c5 */ 	jal	0x11b14
/*  f16d890:	00000000 */ 	nop
/*  f16d894:	0fc0764c */ 	jal	0xf01d930
/*  f16d898:	00000000 */ 	nop
/*  f16d89c:	0fc19017 */ 	jal	0xf06405c
/*  f16d8a0:	00000000 */ 	nop
/*  f16d8a4:	0c0039b9 */ 	jal	0xe6e4
/*  f16d8a8:	00000000 */ 	nop
/*  f16d8ac:	24010026 */ 	li	$at,0x26
/*  f16d8b0:	5441001f */ 	bnel	$v0,$at,.PF0f16d930
/*  f16d8b4:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f16d8b8:	0fc68a40 */ 	jal	0xf1a2900
/*  f16d8bc:	00000000 */ 	nop
/*  f16d8c0:	8e8c0284 */ 	lw	$t4,0x284($s4)
/*  f16d8c4:	8d8e00bc */ 	lw	$t6,0xbc($t4)
/*  f16d8c8:	85c30028 */ 	lh	$v1,0x28($t6)
/*  f16d8cc:	28610016 */ 	slti	$at,$v1,0x16
/*  f16d8d0:	14200002 */ 	bnez	$at,.PF0f16d8dc
/*  f16d8d4:	2861001a */ 	slti	$at,$v1,0x1a
/*  f16d8d8:	1420000b */ 	bnez	$at,.PF0f16d908
.PF0f16d8dc:
/*  f16d8dc:	2401000a */ 	li	$at,0xa
/*  f16d8e0:	10610009 */ 	beq	$v1,$at,.PF0f16d908
/*  f16d8e4:	00000000 */ 	nop
/*  f16d8e8:	10400005 */ 	beqz	$v0,.PF0f16d900
/*  f16d8ec:	00002025 */ 	move	$a0,$zero
/*  f16d8f0:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f16d8f4:	000d7fc2 */ 	srl	$t7,$t5,0x1f
/*  f16d8f8:	15e00003 */ 	bnez	$t7,.PF0f16d908
/*  f16d8fc:	00000000 */ 	nop
.PF0f16d900:
/*  f16d900:	0fc12838 */ 	jal	0xf04a0e0
/*  f16d904:	24050001 */ 	li	$a1,0x1
.PF0f16d908:
/*  f16d908:	0fc682aa */ 	jal	0xf1a0aa8
/*  f16d90c:	00000000 */ 	nop
/*  f16d910:	8e980034 */ 	lw	$t8,0x34($s4)
/*  f16d914:	53000006 */ 	beqzl	$t8,.PF0f16d930
/*  f16d918:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f16d91c:	0fc68aa0 */ 	jal	0xf1a2a80
/*  f16d920:	00000000 */ 	nop
/*  f16d924:	0fc68c56 */ 	jal	0xf1a3158
/*  f16d928:	00000000 */ 	nop
/*  f16d92c:	8fbf0044 */ 	lw	$ra,0x44($sp)
.PF0f16d930:
/*  f16d930:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f16d934:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f16d938:	8fb20034 */ 	lw	$s2,0x34($sp)
/*  f16d93c:	8fb30038 */ 	lw	$s3,0x38($sp)
/*  f16d940:	8fb4003c */ 	lw	$s4,0x3c($sp)
/*  f16d944:	8fb50040 */ 	lw	$s5,0x40($sp)
/*  f16d948:	03e00008 */ 	jr	$ra
/*  f16d94c:	27bd0290 */ 	addiu	$sp,$sp,0x290
);
#else
void coreTick(void)
{
	s32 j;
	s32 i;

	coreCheckPauseStateChanged();

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

	if (coreIsPaused()) {
		g_Vars.lvupdate240 = 0;
	} else if (mpIsPaused()) {
		g_Vars.lvupdate240 = 0;

		for (j = 0; j < PLAYERCOUNT(); j++) {
			g_Vars.players[j]->joybutinhibit = 0xefffefff;
		}
	} else {
		s32 slowmo = coreGetSlowMotionType();
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
	g_Vars.lvupdate240freal = FRAMESTOTIME60(g_Vars.lvupdate240f);

	speedpillTick();
	hudmsgsTick();

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
		if (g_MpTimeLimit60 > 0) {
			s32 elapsed = g_StageTimeElapsed60;
			s32 nexttime = g_Vars.lvupdate240_60 + g_StageTimeElapsed60;
			s32 warntime = g_MpTimeLimit60 - 3600;

			// Show HUD message at one minute remaining
			if (elapsed < warntime && nexttime >= warntime) {
				s32 i;

				for (i = 0; i < PLAYERCOUNT(); i++) {
					setCurrentPlayerNum(i);
					hudmsgCreateViaPreset(langGet(L_MISC(68)), 0); // "One minute left."
				}
			}

			if (elapsed < g_MpTimeLimit60 && nexttime >= g_MpTimeLimit60) {
				// Match is ending due to time limit reached
				mainEndStage();
			}

			// Sound alarm at 10 seconds remaining
			if (nexttime >= g_MpTimeLimit60 - 600
					&& g_MiscAudioHandle == NULL
					&& !coreIsPaused()
					&& nexttime < g_MpTimeLimit60) {
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

	g_StageTimeElapsed60 += g_Vars.lvupdate240_60;
	g_StageTimeElapsed1f = g_StageTimeElapsed60 / 60.0f;

	viSetUseZBuf(true);

	if (g_Vars.stagenum == STAGE_TEST_OLD) {
		titleTickOld();
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
		coreUpdateCutsceneTime();
		func0f12939c();
		coreUpdateSoloHandicaps();
		func0f01d8c0();
		func0f01d990();
		casingsTick();
		shardsTick();
		sparksTick();
		func0f13eb44();
		func0f149864();

		if (g_WeatherActive) {
			weatherTick();
		}

		if (g_NbombsActive) {
			nbombsTick();
		}

		coreUpdateMiscSfx();
		func0000fe88();
		pakExecuteDebugOperations();
		lightingTick();
		func0f0b2904();
		func0f0aefb8();
		amTick();
		menuTickAll();
		scenarioTick();

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
#endif

void coreRecordDistanceMoved(void)
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

void coreUnloadStage(void)
{
	func0f11dcb0(1);

	if (g_MiscAudioHandle && audioIsPlaying(g_MiscAudioHandle)) {
		audioStop(g_MiscAudioHandle);
	}

	if (g_Vars.stagenum < NUM_STAGES) {
		s32 bank = langGetLangBankIndexFromStagenum(g_Vars.stagenum);
		langClearBank(bank);
		stub0f015270();
	}

	chrsReset();
	explosionsReset();
	smokeReset();
	stub0f015400();
	stub0f015410();
	shardsReset();
	stub0f0153f0();
	alarmReset();
	func0f015010(); // props/setup related
	weatherReset();
	objectivesAutocomplete();
	stub0f015260();
	func0f015470();
	func0f0150a0();
	musicReset();
	hudmsgsReset();

	if (g_Vars.stagenum < NUM_STAGES) {
		func0f15c850();
	}

	func00033dd8();

	if (g_FileState == FILESTATE_CHANGINGAGENT) {
		menuPlaySound(MENUSOUND_EXPLOSION);
		g_FileState = FILESTATE_UNSELECTED;
	}

	func0f01bea0();
}

void coreCheckPauseStateChanged(void)
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

void coreSetPaused(bool paused)
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

bool coreIsPaused(void)
{
	return var80084014;
}

s32 coreGetDifficulty(void)
{
	return g_Difficulty;
}

void coreSetDifficulty(s32 difficulty)
{
	if (difficulty < DIFF_A || difficulty > DIFF_PD) {
		difficulty = DIFF_A;
	}

	g_Difficulty = difficulty;
}

void coreSetMpTimeLimit60(u32 limit)
{
	g_MpTimeLimit60 = limit;
}

void coreSetMpScoreLimit(u32 limit)
{
	g_MpScoreLimit = limit;
}

void coreSetMpTeamScoreLimit(u32 limit)
{
	g_MpTeamScoreLimit = limit;
}

f32 coreGetStageTimeInSeconds(void)
{
	return g_StageTimeElapsed1f;
}

s32 coreGetStageTime60(void)
{
	return g_StageTimeElapsed60;
}

u32 func0f16ce04(u32 arg0)
{
	return arg0;
}
