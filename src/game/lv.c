#include <ultra64.h>
#include "constants.h"
#include "game/activemenu/activemenu.h"
#include "game/activemenu/tick.h"
#include "game/atan2f.h"
#include "game/bondmove.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/chr/chraction.h"
#include "game/debug.h"
#include "game/dlights.h"
#include "game/game_006900.h"
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
#include "game/bondgun.h"
#include "game/game_0abe70.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b28d0.h"
#include "game/game_0b63b0.h"
#include "game/player.h"
#include "game/savebuffer.h"
#include "game/hudmsg.h"
#include "game/menu.h"
#include "game/filemgr.h"
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
#include "game/bg.h"
#include "game/game_165670.h"
#include "game/lv.h"
#include "game/music.h"
#include "game/texdecompress.h"
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
#include "bss.h"
#include "lib/args.h"
#include "lib/joy.h"
#include "lib/lib_06440.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "lib/snd.h"
#include "lib/music.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

struct sndstate *g_MiscSfxAudioHandles[3];
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
struct sndstate *g_MiscAudioHandle = NULL;
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

void lv0f167af8(void)
{
	g_Vars.lockscreen = 0;
	g_Vars.joydisableframestogo = -1;
}

void lvStopAllMiscSfx(void)
{
	s32 i;

	for (i = 0; i != ARRAYCOUNT(g_MiscSfxAudioHandles); i++) {
		g_MiscSfxAudioHandles[i] = NULL;
		g_MiscSfxActiveTypes[i] = -1;
	}
}

s32 lvGetMiscSfxIndex(u32 type)
{
	s32 i;

	for (i = 0; i != ARRAYCOUNT(g_MiscSfxActiveTypes); i++) {
		if (g_MiscSfxActiveTypes[i] == type) {
			return i;
		}
	}

	return -1;
}

void lvSetMiscSfxState(u32 type, bool play)
{
	if (play) {
		if (lvGetMiscSfxIndex(type) == -1) {
			s32 index = lvGetMiscSfxIndex(-1);

#if VERSION >= VERSION_NTSC_1_0
			if (index != -1 && g_MiscSfxAudioHandles[index] == NULL)
#else
			if (index != -1)
#endif
			{
				sndStart(var80095200, g_MiscSfxSounds[type], &g_MiscSfxAudioHandles[index], -1, -1, -1, -1, -1);
				g_MiscSfxActiveTypes[index] = type;
			}
		}
	} else {
		u32 stack;
		s32 index = lvGetMiscSfxIndex(type);

		if (index != -1) {
			audioStop(g_MiscSfxAudioHandles[index]);
#if VERSION < VERSION_NTSC_1_0
			g_MiscSfxAudioHandles[index] = 0;
#endif
			g_MiscSfxActiveTypes[index] = -1;
		}
	}
}

void lvUpdateMiscSfx(void)
{
	s32 i;

	if (g_Vars.lvupdate240 == 0) {
		for (i = 0; i != ARRAYCOUNT(g_MiscSfxActiveTypes); i++) {
			lvSetMiscSfxState(i, false);
		}
	} else {
		bool usingboost = g_Vars.speedpillon
			&& lvGetSlowMotionType() == SLOWMOTION_OFF
			&& g_Vars.in_cutscene == false;
		bool usingrocket;

		lvSetMiscSfxState(MISCSFX_BOOSTHEARTBEAT, usingboost);

		usingrocket = false;

		for (i = 0; i < PLAYERCOUNT(); i++) {
			if (g_Vars.players[i]->visionmode == VISIONMODE_SLAYERROCKET) {
				usingrocket = true;
			}
		}

		lvSetMiscSfxState(MISCSFX_SLAYERROCKETHUM, usingrocket);
		lvSetMiscSfxState(MISCSFX_SLAYERROCKETBEEP, usingrocket);
	}

	if (g_Vars.lvupdate240 == 0 && g_MiscAudioHandle && sndGetState(g_MiscAudioHandle) != AL_STOPPED) {
		audioStop(g_MiscAudioHandle);
	}
}

void lvInit(s32 stagenum)
{
	lvCancelFade();

	var80084014 = false;
	var80084010 = 0;

#if VERSION >= VERSION_NTSC_1_0
	joy00013900();

	g_Vars.joydisableframestogo = 10;
#else
	if (joyIsCyclicPollingEnabled()) {
		joyDisableCyclicPolling(760, "lv.c");

		g_Vars.joydisableframestogo = 10;
	}
#endif

	g_Vars.paksconnected2 = 0;
	g_Vars.paksconnected = 0;
	g_Vars.stagenum = stagenum;

	cheatsActivate();

	var80084040 = true;
	g_Vars.lvframenum = 0;
	var80084050 = 0;

	g_Vars.lvframe60 = 0;
	g_Vars.lvupdate240 = 4;

#if VERSION >= VERSION_NTSC_1_0
	g_Vars.lvupdate240f = 1.0f;
	g_Vars.lvupdate240frealprev = PALUPF(1);
#else
	g_Vars.lvupdate240frealprev = PALUPF(1);
	g_Vars.lvupdate240f = 1.0f;
#endif

	g_Vars.lvupdate240freal = g_Vars.lvupdate240frealprev;

	g_StageTimeElapsed60 = 0;
	g_StageTimeElapsed1f = 0;

	g_Vars.speedpilltime = 0;
	g_Vars.speedpillchange = 0;
	g_Vars.speedpillwant = 0;
	g_Vars.speedpillon = false;

	g_Vars.restartlevel = false;
	g_Vars.aibuddiesspawned = false;
	g_Vars.totalkills = 0;
	g_Vars.antiheadnum = -1;
	g_Vars.antibodynum = -1;
	g_Vars.dontplaynrg = false;
	g_Vars.in_cutscene = false;
	g_Vars.autocutplaying = false;
	g_Vars.autocutfinished = false;
	g_Vars.autocutgroupskip = false;

	g_MiscAudioHandle = NULL;

	musicInit();
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
			g_PlayerConfigsArray[4].contpad1 = 0;
			g_PlayerConfigsArray[4].contpad2 = 1;
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
	anim0002373c();
	objectivesReset();
	func0f013ba0();
	func0f011110();
	func0f0108d0();
	setupLoadFiles(stagenum);
	scenarioReset();
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
	lvStopAllMiscSfx();

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
			playerLoadDefaults();
			currentPlayerInit();
			playerSpawn();
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

	pak0f11a2e4();
	sndResetCurMp3();

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
	lvSetPaused(0);

#if PIRACYCHECKS
	{
		u32 checksum = 0;
		s32 *i = (s32 *)&lvGetSlowMotionType;
		s32 *end = (s32 *)&lvTick;

		while (i < end) {
			checksum += *i;
			i++;
		}

		if (checksum != CHECKSUM_PLACEHOLDER) {
			// This is writing a file to the start of the EEPROM data.
			// The file is PAKFILETYPE_TERMINATOR, which is used internally to
			// mark the end of the usable space. This effectively deletes all
			// save data on the game pak and makes it permanently unusable.
			u32 address = 0;
			u32 buffer[4];
			buffer[0] = 0xbb8b80bd;
			buffer[1] = 0xffffffff;
			buffer[2] = 0x020f0100;
			buffer[3] = 0xcd31100b;
			osEepromLongWrite(&g_PiMesgQueue, address, (u8 *)&buffer, 0x10);
			g_Paks[SAVEDEVICE_GAMEPAK].headercachecount = 0;
		}
	}
#endif
}

void lvConfigureFade(u32 color, s16 num_frames)
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

Gfx *lvRenderFade(Gfx *gdl)
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
#if VERSION >= VERSION_PAL_FINAL
			g_FadeFrac += g_Vars.diffframe60freal / g_FadeNumFrames;
#else
			g_FadeFrac += g_Vars.diffframe60f / g_FadeNumFrames;
#endif

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

bool lvIsFadeActive(void)
{
	return g_FadeFrac >= 0;
}

void lvCancelFade(void)
{
	g_FadeNumFrames = 0;
	g_FadeFrac = -1;
	g_FadePrevColour = 0;
	g_FadeColour = 0;
	g_FadeDelay = 0;
}

bool lvCheckCmpFollowThreat(struct threat *threat, s32 index)
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
					if (g_Vars.currentplayer->targetset[index] < PALDOWN(129)) {
						g_Vars.currentplayer->targetset[index] = PALDOWN(129);
					}

					if (g_Vars.currentplayer->targetset[index] >= (PAL ? 146 : 175)) {
						threat->prop = NULL;
						return false;
					}
				} else {
					// Attempting to add a new threat, but chr is dead
					threat->prop = NULL;
					return false;
				}
			}

			if ((threat->prop->flags & PROPFLAG_ONTHISSCREENTHISTICK)
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
			if (threat->prop->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
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

		threat->x1 = sp72 - 2;
		threat->x2 = sp64 + 2;
		threat->y1 = sp76 - 2;
		threat->y2 = sp68 + 2;
	}

	return true;
}

#if VERSION < VERSION_NTSC_1_0
Gfx *lvRenderManPosIfEnabled(Gfx *gdl)
{
	char bufroom[16];
	char bufx[16];
	char bufy[16];
	char bufz[16];
	char bufdir[16];
	s32 x;
	s32 y;
	s32 y2;

	if (debugIsManPosEnabled()) {
		f32 xfrac = g_Vars.currentplayer->bond2.unk00.x;
		f32 zfrac = g_Vars.currentplayer->bond2.unk00.z;

		char directions[][3] = {
			{'n', '\0', '\0'},
			{'n', 'e',  '\0'},
			{'e', '\0', '\0'},
			{'s', 'e',  '\0'},
			{'s', '\0', '\0'},
			{'s', 'w',  '\0'},
			{'w', '\0', '\0'},
			{'n', 'w',  '\0'},
			{'n', '\0', '\0'},
		};

		s32 degrees = atan2f(-xfrac, zfrac) * 180.0f / M_PI;

		sprintf(bufroom, "R=%d(%d)", g_Vars.currentplayer->prop->rooms[0], g_Vars.currentplayer->cam_room);
		sprintf(bufx, "%s%sx %4.0f", "", "", g_Vars.currentplayer->prop->pos.x);
		sprintf(bufy, "%s%sy %4.0f", "", "", g_Vars.currentplayer->prop->pos.y);
		sprintf(bufz, "%s%sz %4.0f", "", "", g_Vars.currentplayer->prop->pos.z);
		sprintf(bufdir, "%s %3d", &directions[(degrees + 22) / 45], degrees);

		x = viGetViewLeft() + 17;
		y = viGetViewTop() + 17;
		y2 = y + 10;
		gdl = func0f153628(gdl);
		gdl = func0f153a34(gdl, 0, y - 1, viGetWidth(), y2 + 1, 0x00000064);

		gdl = textRenderProjected(gdl, &x, &y, bufroom, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0xffffffff, viGetWidth(), viGetHeight(), 0, 0);

		x = viGetViewLeft() + 87;
		gdl = textRenderProjected(gdl, &x, &y, bufx, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0xffffffff, viGetWidth(), viGetHeight(), 0, 0);

		x = viGetViewLeft() + 141;
		gdl = textRenderProjected(gdl, &x, &y, bufy, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0xffffffff, viGetWidth(), viGetHeight(), 0, 0);

		x = viGetViewLeft() + 195;
		gdl = textRenderProjected(gdl, &x, &y, bufz, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0xffffffff, viGetWidth(), viGetHeight(), 0, 0);

		x = viGetViewLeft() + 249;
		gdl = textRenderProjected(gdl, &x, &y, bufdir, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0xffffffff, viGetWidth(), viGetHeight(), 0, 0);

		gdl = func0f153780(gdl);
	}

	return gdl;
}
#endif

void lvFindThreatsForProp(struct prop *prop, bool inchild, struct coord *playerpos, bool *activeslots, f32 *distances)
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
			&& (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK)
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
				g_Vars.currentplayer->cmpfollowprops[index].x1 = sp84 - 2;
				g_Vars.currentplayer->cmpfollowprops[index].x2 = sp76 + 2;
				g_Vars.currentplayer->cmpfollowprops[index].y1 = sp88 - 2;
				g_Vars.currentplayer->cmpfollowprops[index].y2 = sp80 + 2;
				g_Vars.currentplayer->targetset[index] = 0;
				activeslots[index] = true;
				distances[index] = sqdist;
			}
		}
	}

	if (prop->child) {
		lvFindThreatsForProp(prop->child, true, playerpos, activeslots, distances);
	}

	if (inchild && prop->next) {
		lvFindThreatsForProp(prop->next, inchild, playerpos, activeslots, distances);
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
				&& (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK)) {
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
					g_Vars.currentplayer->cmpfollowprops[i].x1 = sp124 - 2;
					g_Vars.currentplayer->cmpfollowprops[i].x2 = sp116 + 2;
					g_Vars.currentplayer->cmpfollowprops[i].y1 = sp128 - 2;
					g_Vars.currentplayer->cmpfollowprops[i].y2 = sp120 + 2;

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

void lvFindThreats(void)
{
	s32 i;
	struct prop *prop;
	f32 distances[] = {0, 0, 0, 0};
	s32 activeslots[] = {false, false, false, false};
	struct prop **propptr = g_Vars.endonscreenprops - 1;
	struct coord campos;

	campos.x = g_Vars.currentplayer->cam_pos.x;
	campos.y = g_Vars.currentplayer->cam_pos.y;
	campos.z = g_Vars.currentplayer->cam_pos.z;

	while (propptr >= g_Vars.onscreenprops) {
		prop = *propptr;

		if (prop) {
			func0f168f24(prop, false, &campos, activeslots, distances);
		}

		propptr--;
	}

	for (i = 0; i != ARRAYCOUNT(activeslots); i++) {
		if (!activeslots[i]) {
			g_Vars.currentplayer->cmpfollowprops[i].prop = NULL;
			g_Vars.currentplayer->cmpfollowprops[i].x1 = -1;
			g_Vars.currentplayer->cmpfollowprops[i].x2 = -2;
		}
	}

	propptr = g_Vars.endonscreenprops - 1;

	while (propptr >= g_Vars.onscreenprops) {
		prop = *propptr;

		if (prop) {
			lvFindThreatsForProp(prop, false, &campos, activeslots, distances);
		}

		propptr--;
	}
}

#if VERSION >= VERSION_PAL_FINAL
struct coord coreRender_spd4 = {0, 0, 0};
s8 coreRender_spd0[] = {30, 0, 0, 0};

GLOBAL_ASM(
glabel lvRender
.late_rodata
glabel var7f1b8e64pf
.word 0x3f866666
glabel var7f1b8e68pf
.word 0x3cbd0bd1
glabel var7f1b8e6cpf
.word 0x3f8ccccd
glabel var7f1b8e70pf
.word 0x3bfc0fc1
glabel var7f1b8e74pf
.word 0x3cbd0bd1
glabel var7f1b8e78pf
.word 0x3f8ccccd
glabel var7f1b8e7cpf
.word 0x3bfc0fc1
.text
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
/*  f16a338:	0fc35807 */ 	jal	func0f0d5a7c
/*  f16a33c:	24930008 */ 	addiu	$s3,$a0,0x8
/*  f16a340:	3c12800a */ 	lui	$s2,0x800a
/*  f16a344:	2652a510 */ 	addiu	$s2,$s2,-23280
/*  f16a348:	8e4204b4 */ 	lw	$v0,0x4b4($s2)
/*  f16a34c:	2401005a */ 	li	$at,0x5a
/*  f16a350:	10410006 */ 	beq	$v0,$at,.PF0f16a36c
/*  f16a354:	2401004e */ 	li	$at,0x4e
/*  f16a358:	5441005f */ 	bnel	$v0,$at,.PF0f16a4d8
/*  f16a35c:	8e4204b4 */ 	lw	$v0,0x4b4($s2)
/*  f16a360:	0fc06b27 */ 	jal	titleIsKeepingMode
/*  f16a364:	00000000 */ 	nop
/*  f16a368:	1040005a */ 	beqz	$v0,.PF0f16a4d4
.PF0f16a36c:
/*  f16a36c:	02601025 */ 	move	$v0,$s3
/*  f16a370:	3c188006 */ 	lui	$t8,0x8006
/*  f16a374:	27181070 */ 	addiu	$t8,$t8,0x1070
/*  f16a378:	3c0f0600 */ 	lui	$t7,0x600
/*  f16a37c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f16a380:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f16a384:	0fc47e4a */ 	jal	debugIsZBufferDisabled
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
/*  f16a3cc:	0c002bf1 */ 	jal	vi0000b280
/*  f16a3d0:	02602025 */ 	move	$a0,$s3
/*  f16a3d4:	0c002bc5 */ 	jal	vi0000b1d0
/*  f16a3d8:	00402025 */ 	move	$a0,$v0
/*  f16a3dc:	00408825 */ 	move	$s1,$v0
/*  f16a3e0:	0c002e91 */ 	jal	viGetViewLeft
/*  f16a3e4:	24530008 */ 	addiu	$s3,$v0,0x8
/*  f16a3e8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f16a3ec:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f16a3f0:	0c002e95 */ 	jal	viGetViewTop
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
/*  f16a444:	0c002e73 */ 	jal	viGetViewWidth
/*  f16a448:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f16a44c:	0c002e91 */ 	jal	viGetViewLeft
/*  f16a450:	a7a2008e */ 	sh	$v0,0x8e($sp)
/*  f16a454:	0c002e95 */ 	jal	viGetViewTop
/*  f16a458:	a7a20090 */ 	sh	$v0,0x90($sp)
/*  f16a45c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f16a460:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f16a464:	0c002e77 */ 	jal	viGetViewHeight
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
/*  f16a4bc:	0fc06bf9 */ 	jal	titleRender
/*  f16a4c0:	ae2c0004 */ 	sw	$t4,0x4($s1)
/*  f16a4c4:	0fc5a557 */ 	jal	lvRenderFade
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
/*  f16a57c:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f16a580:	00002025 */ 	move	$a0,$zero
/*  f16a584:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a588:	86040634 */ 	lh	$a0,0x634($s0)
/*  f16a58c:	0c002e7b */ 	jal	viSetViewPosition
/*  f16a590:	86050636 */ 	lh	$a1,0x636($s0)
/*  f16a594:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a598:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f16a59c:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f16a5a0:	86060630 */ 	lh	$a2,0x630($s0)
/*  f16a5a4:	0c002ec7 */ 	jal	viSetFovAspectAndSize
/*  f16a5a8:	86070632 */ 	lh	$a3,0x632($s0)
/*  f16a5ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f16a5b0:	44816000 */ 	mtc1	$at,$f12
/*  f16a5b4:	0c005936 */ 	jal	mtx00016748
/*  f16a5b8:	00000000 */ 	nop
/*  f16a5bc:	0c002bc5 */ 	jal	vi0000b1d0
/*  f16a5c0:	02602025 */ 	move	$a0,$s3
/*  f16a5c4:	0c002c1d */ 	jal	viRenderViewportEdges
/*  f16a5c8:	00402025 */ 	move	$a0,$v0
/*  f16a5cc:	0fc576bd */ 	jal	currentPlayerScissorToViewport
/*  f16a5d0:	00402025 */ 	move	$a0,$v0
/*  f16a5d4:	0fc3f0f0 */ 	jal	menuRender
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
/*  f16a688:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f16a68c:	00002025 */ 	move	$a0,$zero
/*  f16a690:	0c0029fd */ 	jal	viSetMode
/*  f16a694:	24040001 */ 	li	$a0,0x1
/*  f16a698:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a69c:	86040634 */ 	lh	$a0,0x634($s0)
/*  f16a6a0:	0c002e7b */ 	jal	viSetViewPosition
/*  f16a6a4:	86050636 */ 	lh	$a1,0x636($s0)
/*  f16a6a8:	0fc2f272 */ 	jal	playerGetFbWidth
/*  f16a6ac:	00000000 */ 	nop
/*  f16a6b0:	0fc2f27d */ 	jal	playerGetFbHeight
/*  f16a6b4:	a7a20090 */ 	sh	$v0,0x90($sp)
/*  f16a6b8:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f16a6bc:	00055403 */ 	sra	$t2,$a1,0x10
/*  f16a6c0:	01402825 */ 	move	$a1,$t2
/*  f16a6c4:	0c002e4a */ 	jal	viSetSize
/*  f16a6c8:	87a40090 */ 	lh	$a0,0x90($sp)
/*  f16a6cc:	0fc2f272 */ 	jal	playerGetFbWidth
/*  f16a6d0:	00000000 */ 	nop
/*  f16a6d4:	0fc2f27d */ 	jal	playerGetFbHeight
/*  f16a6d8:	a7a20090 */ 	sh	$v0,0x90($sp)
/*  f16a6dc:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f16a6e0:	00055c03 */ 	sra	$t3,$a1,0x10
/*  f16a6e4:	01602825 */ 	move	$a1,$t3
/*  f16a6e8:	0c002e39 */ 	jal	viSetBufSize
/*  f16a6ec:	87a40090 */ 	lh	$a0,0x90($sp)
/*  f16a6f0:	0fc2f272 */ 	jal	playerGetFbWidth
/*  f16a6f4:	00000000 */ 	nop
/*  f16a6f8:	0fc2f27d */ 	jal	playerGetFbHeight
/*  f16a6fc:	a7a20090 */ 	sh	$v0,0x90($sp)
/*  f16a700:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f16a704:	00057403 */ 	sra	$t6,$a1,0x10
/*  f16a708:	01c02825 */ 	move	$a1,$t6
/*  f16a70c:	0c002e5b */ 	jal	viSetViewSize
/*  f16a710:	87a40090 */ 	lh	$a0,0x90($sp)
/*  f16a714:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a718:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f16a71c:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f16a720:	86060630 */ 	lh	$a2,0x630($s0)
/*  f16a724:	0c002ec7 */ 	jal	viSetFovAspectAndSize
/*  f16a728:	86070632 */ 	lh	$a3,0x632($s0)
/*  f16a72c:	3c013f80 */ 	lui	$at,0x3f80
/*  f16a730:	44816000 */ 	mtc1	$at,$f12
/*  f16a734:	0c005936 */ 	jal	mtx00016748
/*  f16a738:	00000000 */ 	nop
/*  f16a73c:	0c002bc5 */ 	jal	vi0000b1d0
/*  f16a740:	02602025 */ 	move	$a0,$s3
/*  f16a744:	0fc576bd */ 	jal	currentPlayerScissorToViewport
/*  f16a748:	00402025 */ 	move	$a0,$v0
/*  f16a74c:	0fc3f0f0 */ 	jal	menuRender
/*  f16a750:	00402025 */ 	move	$a0,$v0
/*  f16a754:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f16a758:	00409825 */ 	move	$s3,$v0
/*  f16a75c:	8d991a24 */ 	lw	$t9,0x1a24($t4)
/*  f16a760:	53200544 */ 	beqzl	$t9,.PF0f16bc74
/*  f16a764:	824b04d3 */ 	lb	$t3,0x4d3($s2)
/*  f16a768:	0fc2ecb3 */ 	jal	playerTickPauseMenu
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
/*  f16a81c:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f16a820:	00002025 */ 	move	$a0,$zero
/*  f16a824:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a828:	86040634 */ 	lh	$a0,0x634($s0)
/*  f16a82c:	0c002e7b */ 	jal	viSetViewPosition
/*  f16a830:	86050636 */ 	lh	$a1,0x636($s0)
/*  f16a834:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a838:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f16a83c:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f16a840:	86060630 */ 	lh	$a2,0x630($s0)
/*  f16a844:	0c002ec7 */ 	jal	viSetFovAspectAndSize
/*  f16a848:	86070632 */ 	lh	$a3,0x632($s0)
/*  f16a84c:	3c013f80 */ 	lui	$at,0x3f80
/*  f16a850:	44816000 */ 	mtc1	$at,$f12
/*  f16a854:	0c005936 */ 	jal	mtx00016748
/*  f16a858:	00000000 */ 	nop
/*  f16a85c:	0c002bbb */ 	jal	vi0000b1a8
/*  f16a860:	02602025 */ 	move	$a0,$s3
/*  f16a864:	0c002bc5 */ 	jal	vi0000b1d0
/*  f16a868:	00402025 */ 	move	$a0,$v0
/*  f16a86c:	0c002c1d */ 	jal	viRenderViewportEdges
/*  f16a870:	00402025 */ 	move	$a0,$v0
/*  f16a874:	0fc4eef2 */ 	jal	creditsRender
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
/*  f16a8a4:	0fc2f28f */ 	jal	playerHasSharedViewport
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
/*  f16a9dc:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f16a9e0:	24110001 */ 	li	$s1,0x1
/*  f16a9e4:	26190001 */ 	addiu	$t9,$s0,0x1
/*  f16a9e8:	ae400290 */ 	sw	$zero,0x290($s2)
/*  f16a9ec:	1000000a */ 	b	.PF0f16aa18
/*  f16a9f0:	afb90064 */ 	sw	$t9,0x64($sp)
.PF0f16a9f4:
/*  f16a9f4:	0fc4a666 */ 	jal	getPlayerByOrderNum
/*  f16a9f8:	02002025 */ 	move	$a0,$s0
/*  f16a9fc:	0fc4a4ff */ 	jal	setCurrentPlayerNum
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
/*  f16aac8:	0fc525fd */ 	jal	bviewSetBlur
/*  f16aacc:	02802025 */ 	move	$a0,$s4
/*  f16aad0:	02601025 */ 	move	$v0,$s3
/*  f16aad4:	3c0e0600 */ 	lui	$t6,0x600
/*  f16aad8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f16aadc:	8fac006c */ 	lw	$t4,0x6c($sp)
/*  f16aae0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16aae4:	0fc47e4a */ 	jal	debugIsZBufferDisabled
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
/*  f16ab34:	0c002e7b */ 	jal	viSetViewPosition
/*  f16ab38:	86050636 */ 	lh	$a1,0x636($s0)
/*  f16ab3c:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16ab40:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f16ab44:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f16ab48:	86060630 */ 	lh	$a2,0x630($s0)
/*  f16ab4c:	0c002ec7 */ 	jal	viSetFovAspectAndSize
/*  f16ab50:	86070632 */ 	lh	$a3,0x632($s0)
/*  f16ab54:	8e4a0288 */ 	lw	$t2,0x288($s2)
/*  f16ab58:	0c005936 */ 	jal	mtx00016748
/*  f16ab5c:	c54c0074 */ 	lwc1	$f12,0x74($t2)
/*  f16ab60:	0fc599de */ 	jal	func0f1657f8
/*  f16ab64:	00000000 */ 	nop
/*  f16ab68:	0fc5dcb2 */ 	jal	func0f176298
/*  f16ab6c:	00000000 */ 	nop
/*  f16ab70:	0c002bf1 */ 	jal	vi0000b280
/*  f16ab74:	02602025 */ 	move	$a0,$s3
/*  f16ab78:	0c002bc5 */ 	jal	vi0000b1d0
/*  f16ab7c:	00402025 */ 	move	$a0,$v0
/*  f16ab80:	0fc576bd */ 	jal	currentPlayerScissorToViewport
/*  f16ab84:	00402025 */ 	move	$a0,$v0
/*  f16ab88:	0fc4f420 */ 	jal	func0f13c510
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
/*  f16ac60:	0fc27b66 */ 	jal	bgun0f09eae4
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
/*  f16ac98:	0fc50bea */ 	jal	bviewRenderMotionBlur
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
/*  f16acc4:	0c002c1d */ 	jal	viRenderViewportEdges
/*  f16acc8:	02602025 */ 	move	$a0,$s3
/*  f16accc:	0fc576bd */ 	jal	currentPlayerScissorToViewport
/*  f16acd0:	00402025 */ 	move	$a0,$v0
/*  f16acd4:	3c013f80 */ 	lui	$at,0x3f80
/*  f16acd8:	44816000 */ 	mtc1	$at,$f12
/*  f16acdc:	0c005936 */ 	jal	mtx00016748
/*  f16ace0:	00409825 */ 	move	$s3,$v0
/*  f16ace4:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f16ace8:	8d581c50 */ 	lw	$t8,0x1c50($t2)
/*  f16acec:	00185fc2 */ 	srl	$t3,$t8,0x1f
/*  f16acf0:	116003cb */ 	beqz	$t3,.PF0f16bc20
/*  f16acf4:	00000000 */ 	nop
/*  f16acf8:	0fc3f0f0 */ 	jal	menuRender
/*  f16acfc:	02602025 */ 	move	$a0,$s3
/*  f16ad00:	100003c7 */ 	b	.PF0f16bc20
/*  f16ad04:	00409825 */ 	move	$s3,$v0
.PF0f16ad08:
/*  f16ad08:	8dce6230 */ 	lw	$t6,0x6230($t6)
/*  f16ad0c:	24010002 */ 	li	$at,0x2
/*  f16ad10:	15c10004 */ 	bne	$t6,$at,.PF0f16ad24
/*  f16ad14:	00000000 */ 	nop
/*  f16ad18:	0fc3014e */ 	jal	playerUpdateShootRot
/*  f16ad1c:	02602025 */ 	move	$a0,$s3
/*  f16ad20:	00409825 */ 	move	$s3,$v0
.PF0f16ad24:
/*  f16ad24:	0c002c1d */ 	jal	viRenderViewportEdges
/*  f16ad28:	02602025 */ 	move	$a0,$s3
/*  f16ad2c:	0fc48121 */ 	jal	func0f11f984
/*  f16ad30:	00402025 */ 	move	$a0,$v0
/*  f16ad34:	0fc57660 */ 	jal	bgTick
/*  f16ad38:	00409825 */ 	move	$s3,$v0
/*  f16ad3c:	0fc010c5 */ 	jal	func0f004314
/*  f16ad40:	00000000 */ 	nop
/*  f16ad44:	0fc18ca3 */ 	jal	propsTick
/*  f16ad48:	02202025 */ 	move	$a0,$s1
/*  f16ad4c:	0fc619c9 */ 	jal	scenarioTickChr
/*  f16ad50:	00002025 */ 	move	$a0,$zero
/*  f16ad54:	0fc18104 */ 	jal	propsSort
/*  f16ad58:	00000000 */ 	nop
/*  f16ad5c:	0fc193de */ 	jal	autoaimTick
/*  f16ad60:	00000000 */ 	nop
/*  f16ad64:	0fc18b63 */ 	jal	handsTickAttack
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
/*  f16adf4:	0fc28737 */ 	jal	bgunGetWeaponNum
/*  f16adf8:	00002025 */ 	move	$a0,$zero
/*  f16adfc:	00402025 */ 	move	$a0,$v0
/*  f16ae00:	0fc2c720 */ 	jal	weaponHasFlag
/*  f16ae04:	3c054000 */ 	lui	$a1,0x4000
/*  f16ae08:	50400050 */ 	beqzl	$v0,.PF0f16af4c
/*  f16ae0c:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f16ae10:	0fc32020 */ 	jal	bmoveIsInSightAimMode
/*  f16ae14:	00000000 */ 	nop
/*  f16ae18:	1040004b */ 	beqz	$v0,.PF0f16af48
/*  f16ae1c:	00002025 */ 	move	$a0,$zero
.PF0f16ae20:
/*  f16ae20:	00002825 */ 	move	$a1,$zero
/*  f16ae24:	0fc187ed */ 	jal	func0f061d54
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
/*  f16af58:	0fc2c8e8 */ 	jal	gsetHasFunctionFlags
/*  f16af5c:	3c050008 */ 	lui	$a1,0x8
/*  f16af60:	10400005 */ 	beqz	$v0,.PF0f16af78
/*  f16af64:	00000000 */ 	nop
/*  f16af68:	0fc5a851 */ 	jal	lvFindThreats
/*  f16af6c:	00000000 */ 	nop
/*  f16af70:	10000033 */ 	b	.PF0f16b040
/*  f16af74:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16af78:
/*  f16af78:	0fc28737 */ 	jal	bgunGetWeaponNum
/*  f16af7c:	00002025 */ 	move	$a0,$zero
/*  f16af80:	00402025 */ 	move	$a0,$v0
/*  f16af84:	0fc2c720 */ 	jal	weaponHasFlag
/*  f16af88:	3c054000 */ 	lui	$a1,0x4000
/*  f16af8c:	5040002c */ 	beqzl	$v0,.PF0f16b040
/*  f16af90:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16af94:	0fc68746 */ 	jal	frIsInTraining
/*  f16af98:	00000000 */ 	nop
/*  f16af9c:	5040000f */ 	beqzl	$v0,.PF0f16afdc
/*  f16afa0:	8e440284 */ 	lw	$a0,0x284($s2)
/*  f16afa4:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f16afa8:	8dcd1624 */ 	lw	$t5,0x1624($t6)
/*  f16afac:	51a0000b */ 	beqzl	$t5,.PF0f16afdc
/*  f16afb0:	8e440284 */ 	lw	$a0,0x284($s2)
/*  f16afb4:	0fc32020 */ 	jal	bmoveIsInSightAimMode
/*  f16afb8:	00000000 */ 	nop
/*  f16afbc:	50400007 */ 	beqzl	$v0,.PF0f16afdc
/*  f16afc0:	8e440284 */ 	lw	$a0,0x284($s2)
/*  f16afc4:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f16afc8:	0fc68683 */ 	jal	func0f1a0924
/*  f16afcc:	8f241624 */ 	lw	$a0,0x1624($t9)
/*  f16afd0:	1000000a */ 	b	.PF0f16affc
/*  f16afd4:	00008825 */ 	move	$s1,$zero
/*  f16afd8:	8e440284 */ 	lw	$a0,0x284($s2)
.PF0f16afdc:
/*  f16afdc:	02e02825 */ 	move	$a1,$s7
/*  f16afe0:	0fc5a620 */ 	jal	lvCheckCmpFollowThreat
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
/*  f16b00c:	0fc5a620 */ 	jal	lvCheckCmpFollowThreat
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
/*  f16b088:	0fc257ea */ 	jal	objectiveCheckHolograph
/*  f16b08c:	00000000 */ 	nop
/*  f16b090:	3c048009 */ 	lui	$a0,0x8009
/*  f16b094:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f16b098:	240504ff */ 	li	$a1,0x4ff
/*  f16b09c:	00003025 */ 	move	$a2,$zero
/*  f16b0a0:	02e03825 */ 	move	$a3,$s7
/*  f16b0a4:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16b0a8:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16b0ac:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16b0b0:	0c0041a0 */ 	jal	sndStart
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
/*  f16b0fc:	0c0041a0 */ 	jal	sndStart
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
/*  f16b158:	0fc24477 */ 	jal	projectileCreate
/*  f16b15c:	24860008 */ 	addiu	$a2,$a0,0x8
/*  f16b160:	10000008 */ 	b	.PF0f16b184
/*  f16b164:	00000000 */ 	nop
.PF0f16b168:
/*  f16b168:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f16b16c:	02e03825 */ 	move	$a3,$s7
/*  f16b170:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16b174:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16b178:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16b17c:	0c0041a0 */ 	jal	sndStart
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
/*  f16b1cc:	0fc4a8f4 */ 	jal	explosionCreateSimple
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
/*  f16b1fc:	0fc0c6bb */ 	jal	chrBeginDeath
/*  f16b200:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f16b204:	8e500284 */ 	lw	$s0,0x284($s2)
.PF0f16b208:
/*  f16b208:	8e0e00d0 */ 	lw	$t6,0xd0($s0)
.PF0f16b20c:
/*  f16b20c:	51c0000c */ 	beqzl	$t6,.PF0f16b240
/*  f16b210:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f16b214:	0fc18c35 */ 	jal	currentPlayerInteract
/*  f16b218:	00002025 */ 	move	$a0,$zero
/*  f16b21c:	10400012 */ 	beqz	$v0,.PF0f16b268
/*  f16b220:	00000000 */ 	nop
/*  f16b224:	0fc28953 */ 	jal	bgunReloadIfPossible
/*  f16b228:	00002025 */ 	move	$a0,$zero
/*  f16b22c:	0fc28953 */ 	jal	bgunReloadIfPossible
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
/*  f16b260:	0fc18c35 */ 	jal	currentPlayerInteract
/*  f16b264:	03c02025 */ 	move	$a0,$s8
.PF0f16b268:
/*  f16b268:	0fc19121 */ 	jal	func0f0641f4
/*  f16b26c:	00000000 */ 	nop
/*  f16b270:	0fc57698 */ 	jal	bgRender
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
/*  f16b2a4:	0fc0a16f */ 	jal	chr0f028498
/*  f16b2a8:	02002025 */ 	move	$a0,$s0
/*  f16b2ac:	0fc1fe48 */ 	jal	propsRenderBeams
/*  f16b2b0:	02602025 */ 	move	$a0,$s3
/*  f16b2b4:	0fc54ce5 */ 	jal	shardsRender
/*  f16b2b8:	00402025 */ 	move	$a0,$v0
/*  f16b2bc:	0fc4c2ee */ 	jal	sparksRender
/*  f16b2c0:	00402025 */ 	move	$a0,$v0
/*  f16b2c4:	0fc4c6f4 */ 	jal	weatherRender
/*  f16b2c8:	00402025 */ 	move	$a0,$v0
/*  f16b2cc:	3c0d8006 */ 	lui	$t5,0x8006
/*  f16b2d0:	8dad1310 */ 	lw	$t5,0x1310($t5)
/*  f16b2d4:	00409825 */ 	move	$s3,$v0
/*  f16b2d8:	11a00004 */ 	beqz	$t5,.PF0f16b2ec
/*  f16b2dc:	00000000 */ 	nop
/*  f16b2e0:	0fc0285e */ 	jal	nbombsRender
/*  f16b2e4:	00402025 */ 	move	$a0,$v0
/*  f16b2e8:	00409825 */ 	move	$s3,$v0
.PF0f16b2ec:
/*  f16b2ec:	3c198007 */ 	lui	$t9,0x8007
/*  f16b2f0:	8f396230 */ 	lw	$t9,0x6230($t9)
/*  f16b2f4:	24010002 */ 	li	$at,0x2
/*  f16b2f8:	17210005 */ 	bne	$t9,$at,.PF0f16b310
/*  f16b2fc:	00000000 */ 	nop
/*  f16b300:	0fc3034d */ 	jal	playerRenderHud
/*  f16b304:	02602025 */ 	move	$a0,$s3
/*  f16b308:	1000000b */ 	b	.PF0f16b338
/*  f16b30c:	00409825 */ 	move	$s3,$v0
.PF0f16b310:
/*  f16b310:	0fc2bce6 */ 	jal	func0f0aeed8
/*  f16b314:	02602025 */ 	move	$a0,$s3
/*  f16b318:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f16b31c:	00409825 */ 	move	$s3,$v0
/*  f16b320:	958e0010 */ 	lhu	$t6,0x10($t4)
/*  f16b324:	13ce0004 */ 	beq	$s8,$t6,.PF0f16b338
/*  f16b328:	00000000 */ 	nop
/*  f16b32c:	0fc57025 */ 	jal	func0f15b114
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
/*  f16b3a0:	0fc522da */ 	jal	bviewRenderHorizonScanner
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
/*  f16b3e4:	0c0041a0 */ 	jal	sndStart
/*  f16b3e8:	afb7001c */ 	sw	$s7,0x1c($sp)
.PF0f16b3ec:
/*  f16b3ec:	3c188008 */ 	lui	$t8,0x8008
/*  f16b3f0:	8f1845dc */ 	lw	$t8,0x45dc($t8)
/*  f16b3f4:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f16b3f8:	3c018008 */ 	lui	$at,0x8008
/*  f16b3fc:	030b6823 */ 	subu	$t5,$t8,$t3
/*  f16b400:	05a1000b */ 	bgez	$t5,.PF0f16b430
/*  f16b404:	ac2d45dc */ 	sw	$t5,0x45dc($at)
/*  f16b408:	0c004ad4 */ 	jal	random
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
/*  f16b438:	0fc50d3f */ 	jal	bviewRenderFilmLens
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
/*  f16b490:	0c0041a0 */ 	jal	sndStart
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
/*  f16b4b4:	0c004ad4 */ 	jal	random
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
/*  f16b4f4:	0c0041a0 */ 	jal	sndStart
/*  f16b4f8:	afb7001c */ 	sw	$s7,0x1c($sp)
.PF0f16b4fc:
/*  f16b4fc:	12000005 */ 	beqz	$s0,.PF0f16b514
/*  f16b500:	02602025 */ 	move	$a0,$s3
/*  f16b504:	2405ffff */ 	li	$a1,-1
/*  f16b508:	0fc50c6d */ 	jal	bviewRenderStatic
/*  f16b50c:	02003025 */ 	move	$a2,$s0
/*  f16b510:	00409825 */ 	move	$s3,$v0
.PF0f16b514:
/*  f16b514:	3c048008 */ 	lui	$a0,0x8008
/*  f16b518:	8c8445d8 */ 	lw	$a0,0x45d8($a0)
/*  f16b51c:	50800006 */ 	beqzl	$a0,.PF0f16b538
/*  f16b520:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16b524:	56200004 */ 	bnezl	$s1,.PF0f16b538
/*  f16b528:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16b52c:	0c00cd09 */ 	jal	audioStop
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
/*  f16b55c:	0fc50cb9 */ 	jal	bviewRenderSlayerRocketLens
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
/*  f16b5a0:	0fc50c6d */ 	jal	bviewRenderStatic
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
/*  f16b5c8:	0fc50c6d */ 	jal	bviewRenderStatic
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
/*  f16b654:	0fc50dd8 */ 	jal	bviewRenderZoomBlur
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
/*  f16b6b4:	0fc5b180 */ 	jal	lvGetSlowMotionType
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
/*  f16b6f4:	0c0041a0 */ 	jal	sndStart
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
/*  f16b760:	0fc50dd8 */ 	jal	bviewRenderZoomBlur
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
/*  f16b790:	0fc2ed6b */ 	jal	playerDrawFade
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
/*  f16b7f8:	0fc50dd8 */ 	jal	bviewRenderZoomBlur
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
/*  f16b834:	0fc2ed6b */ 	jal	playerDrawFade
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
/*  f16b8c0:	0fc52608 */ 	jal	bviewClearBlur
/*  f16b8c4:	00000000 */ 	nop
/*  f16b8c8:	02602025 */ 	move	$a0,$s3
/*  f16b8cc:	2405ffff */ 	li	$a1,-1
/*  f16b8d0:	0fc50bea */ 	jal	bviewRenderMotionBlur
/*  f16b8d4:	02803025 */ 	move	$a2,$s4
/*  f16b8d8:	00409825 */ 	move	$s3,$v0
/*  f16b8dc:	8e4e02ac */ 	lw	$t6,0x2ac($s2)
.PF0f16b8e0:
/*  f16b8e0:	24010006 */ 	li	$at,0x6
/*  f16b8e4:	15c10031 */ 	bne	$t6,$at,.PF0f16b9ac
/*  f16b8e8:	00000000 */ 	nop
/*  f16b8ec:	0fc2eb66 */ 	jal	playerGetCutsceneBlurFrac
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
/*  f16b9a0:	0fc50bea */ 	jal	bviewRenderMotionBlur
/*  f16b9a4:	00000000 */ 	nop
/*  f16b9a8:	00409825 */ 	move	$s3,$v0
.PF0f16b9ac:
/*  f16b9ac:	0fc47e76 */ 	jal	debugGetMotionBlur
/*  f16b9b0:	00000000 */ 	nop
/*  f16b9b4:	145e0006 */ 	bne	$v0,$s8,.PF0f16b9d0
/*  f16b9b8:	02602025 */ 	move	$a0,$s3
/*  f16b9bc:	2405ff00 */ 	li	$a1,-256
/*  f16b9c0:	0fc50bea */ 	jal	bviewRenderMotionBlur
/*  f16b9c4:	24060080 */ 	li	$a2,0x80
/*  f16b9c8:	10000014 */ 	b	.PF0f16ba1c
/*  f16b9cc:	00409825 */ 	move	$s3,$v0
.PF0f16b9d0:
/*  f16b9d0:	0fc47e76 */ 	jal	debugGetMotionBlur
/*  f16b9d4:	00000000 */ 	nop
/*  f16b9d8:	24010002 */ 	li	$at,0x2
/*  f16b9dc:	14410006 */ 	bne	$v0,$at,.PF0f16b9f8
/*  f16b9e0:	02602025 */ 	move	$a0,$s3
/*  f16b9e4:	2405ff00 */ 	li	$a1,-256
/*  f16b9e8:	0fc50bea */ 	jal	bviewRenderMotionBlur
/*  f16b9ec:	240600c0 */ 	li	$a2,0xc0
/*  f16b9f0:	1000000a */ 	b	.PF0f16ba1c
/*  f16b9f4:	00409825 */ 	move	$s3,$v0
.PF0f16b9f8:
/*  f16b9f8:	0fc47e76 */ 	jal	debugGetMotionBlur
/*  f16b9fc:	00000000 */ 	nop
/*  f16ba00:	24010003 */ 	li	$at,0x3
/*  f16ba04:	14410005 */ 	bne	$v0,$at,.PF0f16ba1c
/*  f16ba08:	02602025 */ 	move	$a0,$s3
/*  f16ba0c:	2405ff00 */ 	li	$a1,-256
/*  f16ba10:	0fc50bea */ 	jal	bviewRenderMotionBlur
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
/*  f16ba9c:	0fc550cf */ 	jal	func0f153628
/*  f16baa0:	02602025 */ 	move	$a0,$s3
/*  f16baa4:	0c002e91 */ 	jal	viGetViewLeft
/*  f16baa8:	00409825 */ 	move	$s3,$v0
/*  f16baac:	0c002e95 */ 	jal	viGetViewTop
/*  f16bab0:	a7a20072 */ 	sh	$v0,0x72($sp)
/*  f16bab4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f16bab8:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f16babc:	0c002e91 */ 	jal	viGetViewLeft
/*  f16bac0:	03008025 */ 	move	$s0,$t8
/*  f16bac4:	0c002e73 */ 	jal	viGetViewWidth
/*  f16bac8:	a7a20076 */ 	sh	$v0,0x76($sp)
/*  f16bacc:	0c002e95 */ 	jal	viGetViewTop
/*  f16bad0:	a7a2008e */ 	sh	$v0,0x8e($sp)
/*  f16bad4:	0c002e77 */ 	jal	viGetViewHeight
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
/*  f16bb08:	0fc551d2 */ 	jal	func0f153a34
/*  f16bb0c:	01ab3821 */ 	addu	$a3,$t5,$t3
/*  f16bb10:	0fc55125 */ 	jal	func0f153780
/*  f16bb14:	00402025 */ 	move	$a0,$v0
/*  f16bb18:	00409825 */ 	move	$s3,$v0
.PF0f16bb1c:
/*  f16bb1c:	0fc619de */ 	jal	scenarioRenderHud
/*  f16bb20:	02602025 */ 	move	$a0,$s3
/*  f16bb24:	0fc5a557 */ 	jal	lvRenderFade
/*  f16bb28:	00402025 */ 	move	$a0,$v0
/*  f16bb2c:	3c0f8009 */ 	lui	$t7,0x8009
/*  f16bb30:	91ef8d54 */ 	lbu	$t7,-0x72ac($t7)
/*  f16bb34:	00409825 */ 	move	$s3,$v0
/*  f16bb38:	11e00004 */ 	beqz	$t7,.PF0f16bb4c
/*  f16bb3c:	00000000 */ 	nop
/*  f16bb40:	0fc69012 */ 	jal	frRenderHud
/*  f16bb44:	00402025 */ 	move	$a0,$v0
/*  f16bb48:	00409825 */ 	move	$s3,$v0
.PF0f16bb4c:
/*  f16bb4c:	0fc47e62 */ 	jal	debugGetTilesDebugMode
/*  f16bb50:	00000000 */ 	nop
/*  f16bb54:	14400013 */ 	bnez	$v0,.PF0f16bba4
/*  f16bb58:	00000000 */ 	nop
/*  f16bb5c:	0fc47e64 */ 	jal	debugGetPadsDebugMode
/*  f16bb60:	00000000 */ 	nop
/*  f16bb64:	1440000f */ 	bnez	$v0,.PF0f16bba4
/*  f16bb68:	00000000 */ 	nop
/*  f16bb6c:	0fc47e6a */ 	jal	debug0f11eea8
/*  f16bb70:	00000000 */ 	nop
/*  f16bb74:	1440000b */ 	bnez	$v0,.PF0f16bba4
/*  f16bb78:	00000000 */ 	nop
/*  f16bb7c:	0fc47ea0 */ 	jal	debug0f11ef80
/*  f16bb80:	00000000 */ 	nop
/*  f16bb84:	14400007 */ 	bnez	$v0,.PF0f16bba4
/*  f16bb88:	00000000 */ 	nop
/*  f16bb8c:	0fc47e9e */ 	jal	debugIsChrStatsEnabled
/*  f16bb90:	00000000 */ 	nop
/*  f16bb94:	14400003 */ 	bnez	$v0,.PF0f16bba4
/*  f16bb98:	00000000 */ 	nop
/*  f16bb9c:	0fc47e50 */ 	jal	debug0f11ee40
/*  f16bba0:	00000000 */ 	nop
.PF0f16bba4:
/*  f16bba4:	0fc49fea */ 	jal	func0f1274d8
/*  f16bba8:	02602025 */ 	move	$a0,$s3
/*  f16bbac:	0fc40494 */ 	jal	amRender
/*  f16bbb0:	00402025 */ 	move	$a0,$v0
/*  f16bbb4:	3c013f80 */ 	lui	$at,0x3f80
/*  f16bbb8:	44816000 */ 	mtc1	$at,$f12
/*  f16bbbc:	0c005936 */ 	jal	mtx00016748
/*  f16bbc0:	00409825 */ 	move	$s3,$v0
/*  f16bbc4:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f16bbc8:	8d581c50 */ 	lw	$t8,0x1c50($t2)
/*  f16bbcc:	00186fc2 */ 	srl	$t5,$t8,0x1f
/*  f16bbd0:	51a00005 */ 	beqzl	$t5,.PF0f16bbe8
/*  f16bbd4:	8e4b0288 */ 	lw	$t3,0x288($s2)
/*  f16bbd8:	0fc3f0f0 */ 	jal	menuRender
/*  f16bbdc:	02602025 */ 	move	$a0,$s3
/*  f16bbe0:	00409825 */ 	move	$s3,$v0
/*  f16bbe4:	8e4b0288 */ 	lw	$t3,0x288($s2)
.PF0f16bbe8:
/*  f16bbe8:	0c005936 */ 	jal	mtx00016748
/*  f16bbec:	c56c0074 */ 	lwc1	$f12,0x74($t3)
/*  f16bbf0:	8e4c0314 */ 	lw	$t4,0x314($s2)
/*  f16bbf4:	51800005 */ 	beqzl	$t4,.PF0f16bc0c
/*  f16bbf8:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f16bbfc:	0fc629f8 */ 	jal	mpRenderModalText
/*  f16bc00:	02602025 */ 	move	$a0,$s3
/*  f16bc04:	00409825 */ 	move	$s3,$v0
/*  f16bc08:	8e590284 */ 	lw	$t9,0x284($s2)
.PF0f16bc0c:
/*  f16bc0c:	932e19b3 */ 	lbu	$t6,0x19b3($t9)
/*  f16bc10:	11c00003 */ 	beqz	$t6,.PF0f16bc20
/*  f16bc14:	00000000 */ 	nop
/*  f16bc18:	0fc2ddff */ 	jal	playerStartNewLife
/*  f16bc1c:	00000000 */ 	nop
.PF0f16bc20:
/*  f16bc20:	0fc4f42f */ 	jal	func0f13c54c
/*  f16bc24:	00000000 */ 	nop
/*  f16bc28:	8e4f0298 */ 	lw	$t7,0x298($s2)
/*  f16bc2c:	05e10004 */ 	bgez	$t7,.PF0f16bc40
/*  f16bc30:	00000000 */ 	nop
/*  f16bc34:	8e4a029c */ 	lw	$t2,0x29c($s2)
/*  f16bc38:	0542000a */ 	bltzl	$t2,.PF0f16bc64
/*  f16bc3c:	8fb00064 */ 	lw	$s0,0x64($sp)
.PF0f16bc40:
/*  f16bc40:	0fc2f28f */ 	jal	playerHasSharedViewport
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
/*  f16bcc4:	0c0039af */ 	jal	mainChangeToStage
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
/*  f16bcf0:	0fc37925 */ 	jal	hudmsgRemoveAll
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
/*  f16bd4c:	0fc0690e */ 	jal	setNumPlayers
/*  f16bd50:	a24e04d2 */ 	sb	$t6,0x4d2($s2)
/*  f16bd54:	0fc06a32 */ 	jal	titleSetNextMode
/*  f16bd58:	24040005 */ 	li	$a0,0x5
/*  f16bd5c:	920b0000 */ 	lbu	$t3,0x0($s0)
/*  f16bd60:	00002025 */ 	move	$a0,$zero
/*  f16bd64:	316cff01 */ 	andi	$t4,$t3,0xff01
/*  f16bd68:	0fc5b6fd */ 	jal	lvSetDifficulty
/*  f16bd6c:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f16bd70:	825904d4 */ 	lb	$t9,0x4d4($s2)
/*  f16bd74:	00197080 */ 	sll	$t6,$t9,0x2
/*  f16bd78:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f16bd7c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f16bd80:	022e1021 */ 	addu	$v0,$s1,$t6
/*  f16bd84:	844f0002 */ 	lh	$t7,0x2($v0)
/*  f16bd88:	84440000 */ 	lh	$a0,0x0($v0)
/*  f16bd8c:	a20f0002 */ 	sb	$t7,0x2($s0)
/*  f16bd90:	0fc06c91 */ 	jal	titleSetNextStage
/*  f16bd94:	a2040001 */ 	sb	$a0,0x1($s0)
/*  f16bd98:	824a04d4 */ 	lb	$t2,0x4d4($s2)
/*  f16bd9c:	000ac080 */ 	sll	$t8,$t2,0x2
/*  f16bda0:	030ac023 */ 	subu	$t8,$t8,$t2
/*  f16bda4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f16bda8:	02386821 */ 	addu	$t5,$s1,$t8
/*  f16bdac:	0c0039af */ 	jal	mainChangeToStage
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
/*  f16bdec:	0c002e53 */ 	jal	viGetWidth
/*  f16bdf0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16bdf4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f16bdf8:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f16bdfc:	0c002e57 */ 	jal	viGetHeight
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
#elif VERSION >= VERSION_NTSC_1_0
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
Gfx *lvRender(Gfx *gdl)
{
	gSPSegment(gdl++, 0x00, 0x00000000);

	func0f0d5a7c();

	if (g_Vars.stagenum == STAGE_TITLE
			|| (g_Vars.stagenum == STAGE_TEST_OLD && titleIsKeepingMode())) {
		gSPDisplayList(gdl++, &var800613a0);

		if (debugIsZBufferDisabled()) {
			gSPDisplayList(gdl++, &var80061360);
		} else {
			gSPDisplayList(gdl++, &var80061380);
		}

		gdl = vi0000b280(gdl);
		gdl = vi0000b1d0(gdl);

		gDPSetScissorFrac(gdl++, 0,
				viGetViewLeft() * 4.0f, viGetViewTop() * 4.0f,
				(viGetViewLeft() + viGetViewWidth()) * 4.0f,
				(viGetViewTop() + viGetViewHeight()) * 4.0f);

		gdl = titleRender(gdl);
		gdl = lvRenderFade(gdl);
	} else if (g_Vars.stagenum == STAGE_BOOTPAKMENU) {
		gSPClipRatio(gdl++, FRUSTRATIO_2);
		gSPDisplayList(gdl++, &var800613a0);
		gSPDisplayList(gdl++, &var80061380);

		setCurrentPlayerNum(0);
		viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
		viSetFovAspectAndSize(g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
				g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);
		mtx00016748(1);

		gdl = vi0000b1d0(gdl);
		gdl = viRenderViewportEdges(gdl);
		gdl = currentPlayerScissorToViewport(gdl);
		gdl = menuRender(gdl);
	} else if (g_Vars.stagenum == STAGE_4MBMENU) {
		gSPClipRatio(gdl++, FRUSTRATIO_2);
		gSPDisplayList(gdl++, &var800613a0);
		gSPDisplayList(gdl++, &var80061380);

		setCurrentPlayerNum(0);
		viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
		viSetFovAspectAndSize(g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
				g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);
		mtx00016748(1);

		gdl = vi0000b1d0(gdl);
		gdl = currentPlayerScissorToViewport(gdl);
		gdl = menuRender(gdl);

		if (g_Vars.currentplayer->pausemode != PAUSEMODE_UNPAUSED) {
			playerTickPauseMenu();
		}
	} else if (g_Vars.stagenum == STAGE_CREDITS) {
		gSPClipRatio(gdl++, FRUSTRATIO_2);
		gSPDisplayList(gdl++, &var800613a0);
		gSPDisplayList(gdl++, &var80061380);

		setCurrentPlayerNum(0);
		viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
		viSetFovAspectAndSize(g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
				g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);
		mtx00016748(1);

		gdl = vi0000b1a8(gdl);
		gdl = vi0000b1d0(gdl);
		gdl = viRenderViewportEdges(gdl);
		gdl = creditsRender(gdl);
	} else {
		// Normal stages
		s32 i;
		s32 playercount;
		Gfx *savedgdl;
		bool forcesingleplayer = (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
			&& playerHasSharedViewport();
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

			if (debugIsZBufferDisabled()) {
				gSPDisplayList(gdl++, &var80061360);
			} else {
				gSPDisplayList(gdl++, &var80061380);
			}

			viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
			viSetFovAspectAndSize(g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
					g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);
			mtx00016748(g_Vars.currentplayerstats->scale_bg2gfx);
			func0f1657f8();
			func0f176298();
			gdl = vi0000b280(gdl);
			gdl = vi0000b1d0(gdl);
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
				g_Vars.currentplayer->gunctrl.unk1583_06 = bgun0f09eae4();
			}

			if (g_Vars.lockscreen) {
				gdl = bviewRenderMotionBlur(gdl, 0xffffffff, 255);
				g_Vars.lockscreen--;
			} else if (var8009dfc0) {
				gdl = viRenderViewportEdges(gdl);
				gdl = currentPlayerScissorToViewport(gdl);
				mtx00016748(1);

				if (g_Vars.currentplayer->menuisactive) {
					gdl = menuRender(gdl);
				}
			} else {
				if (var80075d60 == 2) {
					gdl = playerUpdateShootRot(gdl);
				}

				gdl = viRenderViewportEdges(gdl);
				gdl = func0f11f984(gdl);
				bgTick();
				func0f004314();
				propsTick(islastplayer);
				scenarioTickChr(NULL);
				propsSort();
				autoaimTick();
				handsTickAttack();

				// Calculate lookingatprop
				if (PLAYERCOUNT() == 1
						|| g_Vars.coopplayernum >= 0
						|| g_Vars.antiplayernum >= 0
						|| (weaponHasFlag(bgunGetWeaponNum(HAND_RIGHT), WEAPONFLAG_AIMTRACK) && bmoveIsInSightAimMode())) {
					g_Vars.currentplayer->lookingatprop.prop = func0f061d54(HAND_RIGHT, 0, 0);

					if (g_Vars.currentplayer->lookingatprop.prop) {
						if (g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_CHR
								|| g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_PLAYER) {
							chr = g_Vars.currentplayer->lookingatprop.prop->chr;

							if ((chr->hidden & CHRHFLAG_CLOAKED) && !USINGDEVICE(DEVICE_IRSCANNER)) {
								g_Vars.currentplayer->lookingatprop.prop = NULL;
							}
						} else if (g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_OBJ
								|| g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_WEAPON
								|| g_Vars.currentplayer->lookingatprop.prop->type == PROPTYPE_DOOR) {
							struct defaultobj *obj = g_Vars.currentplayer->lookingatprop.prop->obj;

							if ((obj->flags3 & OBJFLAG3_REACTTOSIGHT) == 0) {
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

				if (gsetHasFunctionFlags(&g_Vars.currentplayer->hands[0].gset, FUNCFLAG_THREATDETECTOR)) {
					lvFindThreats();
				} else if (weaponHasFlag(bgunGetWeaponNum(HAND_RIGHT), WEAPONFLAG_AIMTRACK)) {
					s32 j;

					if (frIsInTraining()
							&& g_Vars.currentplayer->lookingatprop.prop
							&& bmoveIsInSightAimMode()) {
						func0f1a0924(g_Vars.currentplayer->lookingatprop.prop);
					} else if (lvCheckCmpFollowThreat(&g_Vars.currentplayer->lookingatprop, -1) == 0) {
						g_Vars.currentplayer->lookingatprop.prop = NULL;
					}

					for (j = 0; j < ARRAYCOUNT(g_Vars.currentplayer->cmpfollowprops); j++) {
						if (!lvCheckCmpFollowThreat(&g_Vars.currentplayer->cmpfollowprops[j], j)) {
							g_Vars.currentplayer->cmpfollowprops[j].x1 = -1;
							g_Vars.currentplayer->cmpfollowprops[j].x2 = -2;
						}
					}
				}

				// Handle eyespy Z presses
				if (g_Vars.currentplayer->eyespy
						&& (g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_EYESPY)
						&& g_Vars.currentplayer->eyespy->camerabuttonheld) {
					if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
						objectiveCheckHolograph(400);
						sndStart(var80095200, SFX_CAMSPY_SHUTTER, 0, -1, -1, -1, -1, -1);
					} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
						if (g_Vars.currentplayer->eyespydarts) {
							// Fire dart
							struct coord direction;
							sndStart(var80095200, SFX_DRUGSPY_FIREDART, 0, -1, -1, -1, -1, -1);
							g_Vars.currentplayer->eyespydarts--;

							direction.x = g_Vars.currentplayer->eyespy->look.x;
							direction.y = g_Vars.currentplayer->eyespy->look.y;
							direction.z = g_Vars.currentplayer->eyespy->look.z;

							projectileCreate(g_Vars.currentplayer->eyespy->prop, 0,
									&g_Vars.currentplayer->eyespy->prop->pos, &direction, WEAPON_TRANQUILIZER, NULL);
						} else {
							// No dart ammo
							sndStart(var80095200, SFX_FIREEMPTY, 0, -1, -1, -1, -1, -1);
						}
					} else { // EYESPYMODE_BOMBSPY
						struct coord vel = {0, 0, 0};
						struct gset gset = {WEAPON_GRENADE, 0, 0, FUNC_PRIMARY};
						explosionCreateSimple(g_Vars.currentplayer->eyespy->prop,
								&g_Vars.currentplayer->eyespy->prop->pos,
								g_Vars.currentplayer->eyespy->prop->rooms,
								EXPLOSIONTYPE_23, 0);
						chrBeginDeath(g_Vars.currentplayer->eyespy->prop->chr, &vel, 0, 0, &gset, false, 0);
					}
				}

				// Handle opening doors and reloading
				if (g_Vars.currentplayer->bondactivateorreload) {
					if (currentPlayerInteract(false)) {
						bgunReloadIfPossible(HAND_RIGHT);
						bgunReloadIfPossible(HAND_LEFT);
					}
				} else if (g_Vars.currentplayer->eyespy
						&& g_Vars.currentplayer->eyespy->active
						&& g_Vars.currentplayer->eyespy->opendoor) {
					currentPlayerInteract(true);
				}

				func0f0641f4();
				gdl = bgRender(gdl);
				chr0f028498(var80075d68 == 15 || g_AnimHostEnabled);
				gdl = propsRenderBeams(gdl);
				gdl = shardsRender(gdl);
				gdl = sparksRender(gdl);
				gdl = weatherRender(gdl);

				if (g_NbombsActive) {
					gdl = nbombsRender(gdl);
				}

				if (var80075d60 == 2) {
					gdl = playerRenderHud(gdl);
				} else {
					gdl = func0f0aeed8(gdl);

					if (g_Vars.currentplayer->visionmode != VISIONMODE_XRAY) {
						gdl = func0f15b114(gdl);
					}
				}

				if (var80075d78 <= 0) {
					static struct sndstate *g_CutsceneStaticAudioHandle = NULL;
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
							s32 endframe = animGetNumFrames(g_CutsceneAnimNum) - 1;

							colour = 0;

							if (g_CutsceneCurAnimFrame60 < 90) {
								frac = 1.0f - (f32)g_CutsceneCurAnimFrame60 / 90.0f;
							}

							if (g_CutsceneAnimNum != ANIM_046C) {
								if (g_CutsceneCurAnimFrame60 > endframe - 90) {
									frac = (g_CutsceneCurAnimFrame60 - endframe + 90) / 90.0f;
								}
							} else {
								if (g_CutsceneCurAnimFrame60 > endframe - 30) {
									colour = 0xffffff00;
									frac = (g_CutsceneCurAnimFrame60 - endframe + 30) / 30.0f;
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
						switch (g_CutsceneAnimNum) {
						case 0x1e5:
							// Horizon scanner in Air Base intro
							if (g_CutsceneCurAnimFrame60 > 839 && g_CutsceneCurAnimFrame60 < 1411) {
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
									sndStart(var80095200, SFX_INFIL_STATIC_LONG, &g_CutsceneStaticAudioHandle, -1, -1, -1, -1, -1);
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
										sndStart(var80095200, SFX_INFIL_STATIC_MEDIUM, NULL, -1, -1, -1, -1, -1);
									}

									cutscenestatic = 225 - g_CutsceneStaticTimer * 10;
								}

								// Consider a single frame of static, separate
								// to the main static above
								if (random() % 60 == 1) {
									cutscenestatic = 255;
									sndStart(var80095200, SFX_INFIL_STATIC_SHORT, NULL, -1, -1, -1, -1, -1);
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

					if (g_Vars.currentplayer->visionmode == VISIONMODE_SLAYERROCKETSTATIC) {
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
							sndStart(var80095200, lvGetSlowMotionType() ? SFX_JO_BOOST_ACTIVATE : SFX_ARGH_JO_02AD, 0, -1, -1, -1, -1, -1);
						}

						if (g_Vars.speedpillchange < 15) {
							gdl = bviewRenderZoomBlur(gdl, 0xffffffff,
									g_Vars.speedpillchange * 180 / 15,
									(f32)g_Vars.speedpillchange * 0.02000000141561f + 1.1f,
									(f32)g_Vars.speedpillchange * 0.02000000141561f + 1.1f);
							gdl = playerDrawFade(gdl, 0xff, 0xff, 0xff,
									g_Vars.speedpillchange * 0.0066666668280959f);
						} else {
							gdl = bviewRenderZoomBlur(gdl, 0xffffffff,
									(30 - g_Vars.speedpillchange) * 180 / 15,
									(f32)(30 - g_Vars.speedpillchange) * 0.02000000141561f + 1.1f,
									(f32)(30 - g_Vars.speedpillchange) * 0.02000000141561f + 1.1f);
							gdl = playerDrawFade(gdl, 0xff, 0xff, 0xff,
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
						f32 cutsceneblurfrac = playerGetCutsceneBlurFrac();

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

				gdl = scenarioRenderHud(gdl);
				gdl = lvRenderFade(gdl);

				if (g_FrIsValidWeapon) {
					gdl = frRenderHud(gdl);
				}

				if (debugGetTilesDebugMode() == 0
						&& debugGetPadsDebugMode() == 0
						&& debug0f11eea8() == 0
						&& debug0f11ef80() == 0
						&& !debugIsChrStatsEnabled()) {
					debug0f11ee40();
				}

				gdl = func0f1274d8(gdl);
				gdl = amRender(gdl);
				mtx00016748(1);

				if (g_Vars.currentplayer->menuisactive) {
					gdl = menuRender(gdl);
				}

				mtx00016748(g_Vars.currentplayerstats->scale_bg2gfx);

				if (g_Vars.mplayerisrunning) {
					gdl = mpRenderModalText(gdl);
				}

				if (g_Vars.currentplayer->dostartnewlife) {
					playerStartNewLife();
				}
			}

			func0f13c54c();

			if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
					&& playerHasSharedViewport()
					&& g_Vars.currentplayernum != 0) {
				gdl = savedgdl;
			}
		} // end of player loop
	} // end of stage if-statements

	if (g_Vars.autocutplaying) {
		if (g_Vars.autocutfinished) {
			g_Vars.autocutplaying = false;
			g_Vars.autocutfinished = false;

			if (g_Vars.autocutgroupskip) {
				g_Vars.autocutgroupcur = -1;
				g_Vars.autocutgroupleft = 0;
			}

			if (g_Vars.autocutgroupcur < 0 && g_Vars.autocutgroupleft <= 0) {
				mainChangeToStage(STAGE_TITLE);
			}
		}
	}

	// Advance the cutscenes when autoplaying
	if (!g_Vars.autocutplaying && g_Vars.autocutgroupcur >= 0 && g_Vars.autocutgroupleft > 0) {
		hudmsgRemoveAll();
		g_Vars.autocutnum = g_Cutscenes[g_Vars.autocutgroupcur].scene;
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
		lvSetDifficulty(DIFF_A);
		g_MissionConfig.stageindex = g_Cutscenes[g_Vars.autocutgroupcur].mission;
		g_MissionConfig.stagenum = g_Cutscenes[g_Vars.autocutgroupcur].stage;
		titleSetNextStage(g_Cutscenes[g_Vars.autocutgroupcur].stage);
		mainChangeToStage(g_Cutscenes[g_Vars.autocutgroupcur].stage);

		g_Vars.autocutgroupleft--;

		if (g_Vars.autocutgroupleft > 0) {
			g_Vars.autocutgroupcur++;
		} else {
			g_Vars.autocutgroupcur = -1;
		}
	}

	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, viGetWidth(), viGetHeight());

	return gdl;
}
#else
const char var7f1b1e78nb[] = "lv.c Master DL overrun!";

GLOBAL_ASM(
glabel lvRender
.late_rodata
glabel var7f1b1fbcnb
.word 0x3f866666
glabel var7f1b1fc0nb
.word 0x3ca3d70b
glabel var7f1b1fc4nb
.word 0x3f8ccccd
glabel var7f1b1fc8nb
.word 0x3bda740e
glabel var7f1b1fccnb
.word 0x3ca3d70b
glabel var7f1b1fd0nb
.word 0x3f8ccccd
glabel var7f1b1fd4nb
.word 0x3bda740e
.text
/*  f164048:	27bdfe10 */ 	addiu	$sp,$sp,-496
/*  f16404c:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f164050:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f164054:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f164058:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f16405c:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f164060:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f164064:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f164068:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f16406c:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f164070:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f164074:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f164078:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f16407c:	3c12800a */ 	lui	$s2,0x800a
/*  f164080:	35ce0006 */ 	ori	$t6,$t6,0x6
/*  f164084:	2652e6c0 */ 	addiu	$s2,$s2,-6464
/*  f164088:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f16408c:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f164090:	8e4204b4 */ 	lw	$v0,0x4b4($s2)
/*  f164094:	2401005a */ 	addiu	$at,$zero,0x5a
/*  f164098:	24930008 */ 	addiu	$s3,$a0,0x8
/*  f16409c:	10410006 */ 	beq	$v0,$at,.NB0f1640b8
/*  f1640a0:	2401004e */ 	addiu	$at,$zero,0x4e
/*  f1640a4:	54410060 */ 	bnel	$v0,$at,.NB0f164228
/*  f1640a8:	8e4204b4 */ 	lw	$v0,0x4b4($s2)
/*  f1640ac:	0fc06a36 */ 	jal	titleIsKeepingMode
/*  f1640b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1640b4:	1040005b */ 	beqz	$v0,.NB0f164224
.NB0f1640b8:
/*  f1640b8:	02601025 */ 	or	$v0,$s3,$zero
/*  f1640bc:	3c188006 */ 	lui	$t8,0x8006
/*  f1640c0:	271838b0 */ 	addiu	$t8,$t8,0x38b0
/*  f1640c4:	3c0f0600 */ 	lui	$t7,0x600
/*  f1640c8:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f1640cc:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f1640d0:	0fc4666a */ 	jal	debugIsZBufferDisabled
/*  f1640d4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1640d8:	10400008 */ 	beqz	$v0,.NB0f1640fc
/*  f1640dc:	02601025 */ 	or	$v0,$s3,$zero
/*  f1640e0:	3c0a8006 */ 	lui	$t2,0x8006
/*  f1640e4:	254a3870 */ 	addiu	$t2,$t2,0x3870
/*  f1640e8:	3c190600 */ 	lui	$t9,0x600
/*  f1640ec:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f1640f0:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f1640f4:	10000008 */ 	beqz	$zero,.NB0f164118
/*  f1640f8:	26730008 */ 	addiu	$s3,$s3,0x8
.NB0f1640fc:
/*  f1640fc:	02601025 */ 	or	$v0,$s3,$zero
/*  f164100:	3c0c8006 */ 	lui	$t4,0x8006
/*  f164104:	258c3890 */ 	addiu	$t4,$t4,0x3890
/*  f164108:	3c0b0600 */ 	lui	$t3,0x600
/*  f16410c:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f164110:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f164114:	26730008 */ 	addiu	$s3,$s3,0x8
.NB0f164118:
/*  f164118:	0c002d00 */ 	jal	vi0000b280
/*  f16411c:	02602025 */ 	or	$a0,$s3,$zero
/*  f164120:	0c002cd4 */ 	jal	vi0000b1d0
/*  f164124:	00402025 */ 	or	$a0,$v0,$zero
/*  f164128:	0040a025 */ 	or	$s4,$v0,$zero
/*  f16412c:	0c002fb5 */ 	jal	viGetViewLeft
/*  f164130:	24530008 */ 	addiu	$s3,$v0,0x8
/*  f164134:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f164138:	00116c03 */ 	sra	$t5,$s1,0x10
/*  f16413c:	0c002fb9 */ 	jal	viGetViewTop
/*  f164140:	01a08825 */ 	or	$s1,$t5,$zero
/*  f164144:	44822000 */ 	mtc1	$v0,$f4
/*  f164148:	44918000 */ 	mtc1	$s1,$f16
/*  f16414c:	3c014080 */ 	lui	$at,0x4080
/*  f164150:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f164154:	4481a000 */ 	mtc1	$at,$f20
/*  f164158:	3c01ed00 */ 	lui	$at,0xed00
/*  f16415c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f164160:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f164164:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164168:	46149102 */ 	mul.s	$f4,$f18,$f20
/*  f16416c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f164170:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f164174:	440f5000 */ 	mfc1	$t7,$f10
/*  f164178:	440b3000 */ 	mfc1	$t3,$f6
/*  f16417c:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f164180:	0301c825 */ 	or	$t9,$t8,$at
/*  f164184:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f164188:	000c6b00 */ 	sll	$t5,$t4,0xc
/*  f16418c:	032d7025 */ 	or	$t6,$t9,$t5
/*  f164190:	0c002f97 */ 	jal	viGetViewWidth
/*  f164194:	ae8e0000 */ 	sw	$t6,0x0($s4)
/*  f164198:	0c002fb5 */ 	jal	viGetViewLeft
/*  f16419c:	a7a2008e */ 	sh	$v0,0x8e($sp)
/*  f1641a0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1641a4:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f1641a8:	0c002fb9 */ 	jal	viGetViewTop
/*  f1641ac:	01e08025 */ 	or	$s0,$t7,$zero
/*  f1641b0:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f1641b4:	0011c403 */ 	sra	$t8,$s1,0x10
/*  f1641b8:	0c002f9b */ 	jal	viGetViewHeight
/*  f1641bc:	03008825 */ 	or	$s1,$t8,$zero
/*  f1641c0:	87ad008e */ 	lh	$t5,0x8e($sp)
/*  f1641c4:	00515021 */ 	addu	$t2,$v0,$s1
/*  f1641c8:	448a4000 */ 	mtc1	$t2,$f8
/*  f1641cc:	020d7021 */ 	addu	$t6,$s0,$t5
/*  f1641d0:	448e2000 */ 	mtc1	$t6,$f4
/*  f1641d4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f1641d8:	02602025 */ 	or	$a0,$s3,$zero
/*  f1641dc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1641e0:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f1641e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1641e8:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f1641ec:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f1641f0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f1641f4:	440c9000 */ 	mfc1	$t4,$f18
/*  f1641f8:	44185000 */ 	mfc1	$t8,$f10
/*  f1641fc:	31990fff */ 	andi	$t9,$t4,0xfff
/*  f164200:	330a0fff */ 	andi	$t2,$t8,0xfff
/*  f164204:	000a5b00 */ 	sll	$t3,$t2,0xc
/*  f164208:	032b6025 */ 	or	$t4,$t9,$t3
/*  f16420c:	0fc06b08 */ 	jal	titleRender
/*  f164210:	ae8c0004 */ 	sw	$t4,0x4($s4)
/*  f164214:	0fc58ba8 */ 	jal	lvRenderFade
/*  f164218:	00402025 */ 	or	$a0,$v0,$zero
/*  f16421c:	1000069c */ 	beqz	$zero,.NB0f165c90
/*  f164220:	00409825 */ 	or	$s3,$v0,$zero
.NB0f164224:
/*  f164224:	8e4204b4 */ 	lw	$v0,0x4b4($s2)
.NB0f164228:
/*  f164228:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f16422c:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f164230:	14410040 */ 	bne	$v0,$at,.NB0f164334
/*  f164234:	3408fffe */ 	dli	$t0,0xfffe
/*  f164238:	02601025 */ 	or	$v0,$s3,$zero
/*  f16423c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164240:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f164244:	35ad0404 */ 	ori	$t5,$t5,0x404
/*  f164248:	02601825 */ 	or	$v1,$s3,$zero
/*  f16424c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164250:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f164254:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f164258:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f16425c:	35ce0c04 */ 	ori	$t6,$t6,0xc04
/*  f164260:	02602025 */ 	or	$a0,$s3,$zero
/*  f164264:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f164268:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f16426c:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f164270:	35ef1404 */ 	ori	$t7,$t7,0x1404
/*  f164274:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164278:	02602825 */ 	or	$a1,$s3,$zero
/*  f16427c:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f164280:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f164284:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164288:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f16428c:	37181c04 */ 	ori	$t8,$t8,0x1c04
/*  f164290:	02603025 */ 	or	$a2,$s3,$zero
/*  f164294:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f164298:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f16429c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1642a0:	3c0a8006 */ 	lui	$t2,0x8006
/*  f1642a4:	3c090600 */ 	lui	$t1,0x600
/*  f1642a8:	254a38b0 */ 	addiu	$t2,$t2,0x38b0
/*  f1642ac:	02601025 */ 	or	$v0,$s3,$zero
/*  f1642b0:	3c198006 */ 	lui	$t9,0x8006
/*  f1642b4:	acca0004 */ 	sw	$t2,0x4($a2)
/*  f1642b8:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f1642bc:	27393890 */ 	addiu	$t9,$t9,0x3890
/*  f1642c0:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f1642c4:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f1642c8:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1642cc:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f1642d0:	00002025 */ 	or	$a0,$zero,$zero
/*  f1642d4:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1642d8:	86040634 */ 	lh	$a0,0x634($s0)
/*  f1642dc:	0c002f9f */ 	jal	viSetViewPosition
/*  f1642e0:	86050636 */ 	lh	$a1,0x636($s0)
/*  f1642e4:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1642e8:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f1642ec:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f1642f0:	86060630 */ 	lh	$a2,0x630($s0)
/*  f1642f4:	0c002feb */ 	jal	viSetFovAspectAndSize
/*  f1642f8:	86070632 */ 	lh	$a3,0x632($s0)
/*  f1642fc:	3c013f80 */ 	lui	$at,0x3f80
/*  f164300:	44816000 */ 	mtc1	$at,$f12
/*  f164304:	0c005db6 */ 	jal	mtx00016748
/*  f164308:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16430c:	0c002cd4 */ 	jal	vi0000b1d0
/*  f164310:	02602025 */ 	or	$a0,$s3,$zero
/*  f164314:	0c002d2c */ 	jal	viRenderViewportEdges
/*  f164318:	00402025 */ 	or	$a0,$v0,$zero
/*  f16431c:	0fc55c96 */ 	jal	currentPlayerScissorToViewport
/*  f164320:	00402025 */ 	or	$a0,$v0,$zero
/*  f164324:	0fc3e0e0 */ 	jal	menuRender
/*  f164328:	00402025 */ 	or	$a0,$v0,$zero
/*  f16432c:	10000658 */ 	beqz	$zero,.NB0f165c90
/*  f164330:	00409825 */ 	or	$s3,$v0,$zero
.NB0f164334:
/*  f164334:	2401005d */ 	addiu	$at,$zero,0x5d
/*  f164338:	14410046 */ 	bne	$v0,$at,.NB0f164454
/*  f16433c:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f164340:	02601025 */ 	or	$v0,$s3,$zero
/*  f164344:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164348:	3c0bbc00 */ 	lui	$t3,0xbc00
/*  f16434c:	356b0404 */ 	ori	$t3,$t3,0x404
/*  f164350:	02601825 */ 	or	$v1,$s3,$zero
/*  f164354:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164358:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f16435c:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f164360:	3c0cbc00 */ 	lui	$t4,0xbc00
/*  f164364:	358c0c04 */ 	ori	$t4,$t4,0xc04
/*  f164368:	02602025 */ 	or	$a0,$s3,$zero
/*  f16436c:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f164370:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f164374:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f164378:	3408fffe */ 	dli	$t0,0xfffe
/*  f16437c:	35ad1404 */ 	ori	$t5,$t5,0x1404
/*  f164380:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164384:	02602825 */ 	or	$a1,$s3,$zero
/*  f164388:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f16438c:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f164390:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164394:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f164398:	35ce1c04 */ 	ori	$t6,$t6,0x1c04
/*  f16439c:	02603025 */ 	or	$a2,$s3,$zero
/*  f1643a0:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f1643a4:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f1643a8:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1643ac:	3c0f8006 */ 	lui	$t7,0x8006
/*  f1643b0:	3c090600 */ 	lui	$t1,0x600
/*  f1643b4:	25ef38b0 */ 	addiu	$t7,$t7,0x38b0
/*  f1643b8:	02601025 */ 	or	$v0,$s3,$zero
/*  f1643bc:	3c188006 */ 	lui	$t8,0x8006
/*  f1643c0:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f1643c4:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f1643c8:	27183890 */ 	addiu	$t8,$t8,0x3890
/*  f1643cc:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f1643d0:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f1643d4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1643d8:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f1643dc:	00002025 */ 	or	$a0,$zero,$zero
/*  f1643e0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1643e4:	86040634 */ 	lh	$a0,0x634($s0)
/*  f1643e8:	0c002f9f */ 	jal	viSetViewPosition
/*  f1643ec:	86050636 */ 	lh	$a1,0x636($s0)
/*  f1643f0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1643f4:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f1643f8:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f1643fc:	86060630 */ 	lh	$a2,0x630($s0)
/*  f164400:	0c002feb */ 	jal	viSetFovAspectAndSize
/*  f164404:	86070632 */ 	lh	$a3,0x632($s0)
/*  f164408:	3c013f80 */ 	lui	$at,0x3f80
/*  f16440c:	44816000 */ 	mtc1	$at,$f12
/*  f164410:	0c005db6 */ 	jal	mtx00016748
/*  f164414:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164418:	0c002cd4 */ 	jal	vi0000b1d0
/*  f16441c:	02602025 */ 	or	$a0,$s3,$zero
/*  f164420:	0fc55c96 */ 	jal	currentPlayerScissorToViewport
/*  f164424:	00402025 */ 	or	$a0,$v0,$zero
/*  f164428:	0fc3e0e0 */ 	jal	menuRender
/*  f16442c:	00402025 */ 	or	$a0,$v0,$zero
/*  f164430:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f164434:	00409825 */ 	or	$s3,$v0,$zero
/*  f164438:	8d591a24 */ 	lw	$t9,0x1a24($t2)
/*  f16443c:	53200615 */ 	beqzl	$t9,.NB0f165c94
/*  f164440:	825904d3 */ 	lb	$t9,0x4d3($s2)
/*  f164444:	0fc2e290 */ 	jal	playerTickPauseMenu
/*  f164448:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16444c:	10000611 */ 	beqz	$zero,.NB0f165c94
/*  f164450:	825904d3 */ 	lb	$t9,0x4d3($s2)
.NB0f164454:
/*  f164454:	2401005c */ 	addiu	$at,$zero,0x5c
/*  f164458:	14410041 */ 	bne	$v0,$at,.NB0f164560
/*  f16445c:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f164460:	02601025 */ 	or	$v0,$s3,$zero
/*  f164464:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164468:	3c0bbc00 */ 	lui	$t3,0xbc00
/*  f16446c:	356b0404 */ 	ori	$t3,$t3,0x404
/*  f164470:	02601825 */ 	or	$v1,$s3,$zero
/*  f164474:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164478:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f16447c:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f164480:	3c0cbc00 */ 	lui	$t4,0xbc00
/*  f164484:	358c0c04 */ 	ori	$t4,$t4,0xc04
/*  f164488:	02602025 */ 	or	$a0,$s3,$zero
/*  f16448c:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f164490:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f164494:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f164498:	3408fffe */ 	dli	$t0,0xfffe
/*  f16449c:	35ad1404 */ 	ori	$t5,$t5,0x1404
/*  f1644a0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1644a4:	02602825 */ 	or	$a1,$s3,$zero
/*  f1644a8:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f1644ac:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f1644b0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1644b4:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f1644b8:	35ce1c04 */ 	ori	$t6,$t6,0x1c04
/*  f1644bc:	02603025 */ 	or	$a2,$s3,$zero
/*  f1644c0:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f1644c4:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f1644c8:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1644cc:	3c0f8006 */ 	lui	$t7,0x8006
/*  f1644d0:	3c090600 */ 	lui	$t1,0x600
/*  f1644d4:	25ef38b0 */ 	addiu	$t7,$t7,0x38b0
/*  f1644d8:	02601025 */ 	or	$v0,$s3,$zero
/*  f1644dc:	3c188006 */ 	lui	$t8,0x8006
/*  f1644e0:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f1644e4:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f1644e8:	27183890 */ 	addiu	$t8,$t8,0x3890
/*  f1644ec:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f1644f0:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f1644f4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1644f8:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f1644fc:	00002025 */ 	or	$a0,$zero,$zero
/*  f164500:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164504:	86040634 */ 	lh	$a0,0x634($s0)
/*  f164508:	0c002f9f */ 	jal	viSetViewPosition
/*  f16450c:	86050636 */ 	lh	$a1,0x636($s0)
/*  f164510:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164514:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f164518:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f16451c:	86060630 */ 	lh	$a2,0x630($s0)
/*  f164520:	0c002feb */ 	jal	viSetFovAspectAndSize
/*  f164524:	86070632 */ 	lh	$a3,0x632($s0)
/*  f164528:	3c013f80 */ 	lui	$at,0x3f80
/*  f16452c:	44816000 */ 	mtc1	$at,$f12
/*  f164530:	0c005db6 */ 	jal	mtx00016748
/*  f164534:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164538:	0c002cca */ 	jal	vi0000b1a8
/*  f16453c:	02602025 */ 	or	$a0,$s3,$zero
/*  f164540:	0c002cd4 */ 	jal	vi0000b1d0
/*  f164544:	00402025 */ 	or	$a0,$v0,$zero
/*  f164548:	0c002d2c */ 	jal	viRenderViewportEdges
/*  f16454c:	00402025 */ 	or	$a0,$v0,$zero
/*  f164550:	0fc4d6d9 */ 	jal	creditsRender
/*  f164554:	00402025 */ 	or	$a0,$v0,$zero
/*  f164558:	100005cd */ 	beqz	$zero,.NB0f165c90
/*  f16455c:	00409825 */ 	or	$s3,$v0,$zero
.NB0f164560:
/*  f164560:	8e500298 */ 	lw	$s0,0x298($s2)
/*  f164564:	06010006 */ 	bgez	$s0,.NB0f164580
/*  f164568:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16456c:	8e50029c */ 	lw	$s0,0x29c($s2)
/*  f164570:	2a190000 */ 	slti	$t9,$s0,0x0
/*  f164574:	3b300001 */ 	xori	$s0,$t9,0x1
/*  f164578:	1200000e */ 	beqz	$s0,.NB0f1645b4
/*  f16457c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f164580:
/*  f164580:	3c108007 */ 	lui	$s0,0x8007
/*  f164584:	8e102e24 */ 	lw	$s0,0x2e24($s0)
/*  f164588:	0010582b */ 	sltu	$t3,$zero,$s0
/*  f16458c:	11600005 */ 	beqz	$t3,.NB0f1645a4
/*  f164590:	3c108006 */ 	lui	$s0,0x8006
/*  f164594:	8e10f2f0 */ 	lw	$s0,-0xd10($s0)
/*  f164598:	2e0c0001 */ 	sltiu	$t4,$s0,0x1
/*  f16459c:	15800005 */ 	bnez	$t4,.NB0f1645b4
/*  f1645a0:	01808025 */ 	or	$s0,$t4,$zero
.NB0f1645a4:
/*  f1645a4:	0fc3e4d2 */ 	jal	menuGetRoot
/*  f1645a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1645ac:	38500009 */ 	xori	$s0,$v0,0x9
/*  f1645b0:	2e100001 */ 	sltiu	$s0,$s0,0x1
.NB0f1645b4:
/*  f1645b4:	12000004 */ 	beqz	$s0,.NB0f1645c8
/*  f1645b8:	afb00184 */ 	sw	$s0,0x184($sp)
/*  f1645bc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f1645c0:	1000001c */ 	beqz	$zero,.NB0f164634
/*  f1645c4:	afad018c */ 	sw	$t5,0x18c($sp)
.NB0f1645c8:
/*  f1645c8:	8e4e006c */ 	lw	$t6,0x6c($s2)
/*  f1645cc:	00002025 */ 	or	$a0,$zero,$zero
/*  f1645d0:	00001825 */ 	or	$v1,$zero,$zero
/*  f1645d4:	11c00003 */ 	beqz	$t6,.NB0f1645e4
/*  f1645d8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1645dc:	10000001 */ 	beqz	$zero,.NB0f1645e4
/*  f1645e0:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f1645e4:
/*  f1645e4:	8e4f0068 */ 	lw	$t7,0x68($s2)
/*  f1645e8:	00008025 */ 	or	$s0,$zero,$zero
/*  f1645ec:	11e00003 */ 	beqz	$t7,.NB0f1645fc
/*  f1645f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1645f4:	10000001 */ 	beqz	$zero,.NB0f1645fc
/*  f1645f8:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f1645fc:
/*  f1645fc:	8e580064 */ 	lw	$t8,0x64($s2)
/*  f164600:	13000003 */ 	beqz	$t8,.NB0f164610
/*  f164604:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164608:	10000001 */ 	beqz	$zero,.NB0f164610
/*  f16460c:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f164610:
/*  f164610:	8e4a0070 */ 	lw	$t2,0x70($s2)
/*  f164614:	11400003 */ 	beqz	$t2,.NB0f164624
/*  f164618:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16461c:	10000001 */ 	beqz	$zero,.NB0f164624
/*  f164620:	24100001 */ 	addiu	$s0,$zero,0x1
.NB0f164624:
/*  f164624:	0202c821 */ 	addu	$t9,$s0,$v0
/*  f164628:	03235821 */ 	addu	$t3,$t9,$v1
/*  f16462c:	01646021 */ 	addu	$t4,$t3,$a0
/*  f164630:	afac018c */ 	sw	$t4,0x18c($sp)
.NB0f164634:
/*  f164634:	02601025 */ 	or	$v0,$s3,$zero
/*  f164638:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16463c:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f164640:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f164644:	35ad0404 */ 	ori	$t5,$t5,0x404
/*  f164648:	02601825 */ 	or	$v1,$s3,$zero
/*  f16464c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f164650:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f164654:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f164658:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f16465c:	35ce0c04 */ 	ori	$t6,$t6,0xc04
/*  f164660:	02602025 */ 	or	$a0,$s3,$zero
/*  f164664:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f164668:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f16466c:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f164670:	3408fffe */ 	dli	$t0,0xfffe
/*  f164674:	35ef1404 */ 	ori	$t7,$t7,0x1404
/*  f164678:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16467c:	02602825 */ 	or	$a1,$s3,$zero
/*  f164680:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f164684:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f164688:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f16468c:	37181c04 */ 	ori	$t8,$t8,0x1c04
/*  f164690:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f164694:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f164698:	8faa018c */ 	lw	$t2,0x18c($sp)
/*  f16469c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1646a0:	00008025 */ 	or	$s0,$zero,$zero
/*  f1646a4:	1940057a */ 	blez	$t2,.NB0f165c90
/*  f1646a8:	3c198006 */ 	lui	$t9,0x8006
/*  f1646ac:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1646b0:	273938b0 */ 	addiu	$t9,$t9,0x38b0
/*  f1646b4:	4481a000 */ 	mtc1	$at,$f20
/*  f1646b8:	afb9006c */ 	sw	$t9,0x6c($sp)
/*  f1646bc:	27be00c8 */ 	addiu	$s8,$sp,0xc8
/*  f1646c0:	24170004 */ 	addiu	$s7,$zero,0x4
/*  f1646c4:	27b500b0 */ 	addiu	$s5,$sp,0xb0
/*  f1646c8:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f1646cc:	8fab0184 */ 	lw	$t3,0x184($sp)
.NB0f1646d0:
/*  f1646d0:	0000b025 */ 	or	$s6,$zero,$zero
/*  f1646d4:	afb30188 */ 	sw	$s3,0x188($sp)
/*  f1646d8:	11600007 */ 	beqz	$t3,.NB0f1646f8
/*  f1646dc:	00002025 */ 	or	$a0,$zero,$zero
/*  f1646e0:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f1646e4:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f1646e8:	260c0001 */ 	addiu	$t4,$s0,0x1
/*  f1646ec:	ae400290 */ 	sw	$zero,0x290($s2)
/*  f1646f0:	1000000a */ 	beqz	$zero,.NB0f16471c
/*  f1646f4:	afac0064 */ 	sw	$t4,0x64($sp)
.NB0f1646f8:
/*  f1646f8:	0fc48ec2 */ 	jal	getPlayerByOrderNum
/*  f1646fc:	02002025 */ 	or	$a0,$s0,$zero
/*  f164700:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f164704:	00402025 */ 	or	$a0,$v0,$zero
/*  f164708:	8fad018c */ 	lw	$t5,0x18c($sp)
/*  f16470c:	26020001 */ 	addiu	$v0,$s0,0x1
/*  f164710:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f164714:	01a28826 */ 	xor	$s1,$t5,$v0
/*  f164718:	2e310001 */ 	sltiu	$s1,$s1,0x1
.NB0f16471c:
/*  f16471c:	8e4e02ac */ 	lw	$t6,0x2ac($s2)
/*  f164720:	24010006 */ 	addiu	$at,$zero,0x6
/*  f164724:	11c10029 */ 	beq	$t6,$at,.NB0f1647cc
/*  f164728:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16472c:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164730:	8e0f00bc */ 	lw	$t7,0xbc($s0)
/*  f164734:	8de20004 */ 	lw	$v0,0x4($t7)
/*  f164738:	844402d8 */ 	lh	$a0,0x2d8($v0)
/*  f16473c:	18800023 */ 	blez	$a0,.NB0f1647cc
/*  f164740:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164744:	92181922 */ 	lbu	$t8,0x1922($s0)
/*  f164748:	17000020 */ 	bnez	$t8,.NB0f1647cc
/*  f16474c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164750:	8e0a1c08 */ 	lw	$t2,0x1c08($s0)
/*  f164754:	24011388 */ 	addiu	$at,$zero,0x1388
/*  f164758:	1540001c */ 	bnez	$t2,.NB0f1647cc
/*  f16475c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164760:	0004b180 */ 	sll	$s6,$a0,0x6
/*  f164764:	02c4b021 */ 	addu	$s6,$s6,$a0
/*  f164768:	0016b040 */ 	sll	$s6,$s6,0x1
/*  f16476c:	02c1001a */ 	div	$zero,$s6,$at
/*  f164770:	0000c812 */ 	mflo	$t9
/*  f164774:	27360064 */ 	addiu	$s6,$t9,0x64
/*  f164778:	2ec100e7 */ 	sltiu	$at,$s6,0xe7
/*  f16477c:	14200002 */ 	bnez	$at,.NB0f164788
/*  f164780:	240b1388 */ 	addiu	$t3,$zero,0x1388
/*  f164784:	241600e6 */ 	addiu	$s6,$zero,0xe6
.NB0f164788:
/*  f164788:	28811389 */ 	slti	$at,$a0,0x1389
/*  f16478c:	54200004 */ 	bnezl	$at,.NB0f1647a0
/*  f164790:	904d02ff */ 	lbu	$t5,0x2ff($v0)
/*  f164794:	a44b02d8 */ 	sh	$t3,0x2d8($v0)
/*  f164798:	844402d8 */ 	lh	$a0,0x2d8($v0)
/*  f16479c:	904d02ff */ 	lbu	$t5,0x2ff($v0)
.NB0f1647a0:
/*  f1647a0:	8e4c0038 */ 	lw	$t4,0x38($s2)
/*  f1647a4:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f1647a8:	018e0019 */ 	multu	$t4,$t6
/*  f1647ac:	00007812 */ 	mflo	$t7
/*  f1647b0:	008fc023 */ 	subu	$t8,$a0,$t7
/*  f1647b4:	a45802d8 */ 	sh	$t8,0x2d8($v0)
/*  f1647b8:	844a02d8 */ 	lh	$t2,0x2d8($v0)
/*  f1647bc:	1d400003 */ 	bgtz	$t2,.NB0f1647cc
/*  f1647c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1647c4:	a44002d8 */ 	sh	$zero,0x2d8($v0)
/*  f1647c8:	a04002ff */ 	sb	$zero,0x2ff($v0)
.NB0f1647cc:
/*  f1647cc:	0fc50cc5 */ 	jal	bviewSetBlur
/*  f1647d0:	02c02025 */ 	or	$a0,$s6,$zero
/*  f1647d4:	02601025 */ 	or	$v0,$s3,$zero
/*  f1647d8:	3c190600 */ 	lui	$t9,0x600
/*  f1647dc:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f1647e0:	8fab006c */ 	lw	$t3,0x6c($sp)
/*  f1647e4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1647e8:	0fc4666a */ 	jal	debugIsZBufferDisabled
/*  f1647ec:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f1647f0:	10400009 */ 	beqz	$v0,.NB0f164818
/*  f1647f4:	3c0e0600 */ 	lui	$t6,0x600
/*  f1647f8:	02601025 */ 	or	$v0,$s3,$zero
/*  f1647fc:	3c0c8006 */ 	lui	$t4,0x8006
/*  f164800:	258c3870 */ 	addiu	$t4,$t4,0x3870
/*  f164804:	3c0d0600 */ 	lui	$t5,0x600
/*  f164808:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f16480c:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f164810:	10000007 */ 	beqz	$zero,.NB0f164830
/*  f164814:	26730008 */ 	addiu	$s3,$s3,0x8
.NB0f164818:
/*  f164818:	02601025 */ 	or	$v0,$s3,$zero
/*  f16481c:	3c0f8006 */ 	lui	$t7,0x8006
/*  f164820:	25ef3890 */ 	addiu	$t7,$t7,0x3890
/*  f164824:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f164828:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f16482c:	26730008 */ 	addiu	$s3,$s3,0x8
.NB0f164830:
/*  f164830:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164834:	86040634 */ 	lh	$a0,0x634($s0)
/*  f164838:	0c002f9f */ 	jal	viSetViewPosition
/*  f16483c:	86050636 */ 	lh	$a1,0x636($s0)
/*  f164840:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164844:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f164848:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f16484c:	86060630 */ 	lh	$a2,0x630($s0)
/*  f164850:	0c002feb */ 	jal	viSetFovAspectAndSize
/*  f164854:	86070632 */ 	lh	$a3,0x632($s0)
/*  f164858:	8e580288 */ 	lw	$t8,0x288($s2)
/*  f16485c:	0c005db6 */ 	jal	mtx00016748
/*  f164860:	c70c0074 */ 	lwc1	$f12,0x74($t8)
/*  f164864:	0fc57ffe */ 	jal	func0f1657f8
/*  f164868:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16486c:	0fc5c3ce */ 	jal	func0f176298
/*  f164870:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164874:	0c002d00 */ 	jal	vi0000b280
/*  f164878:	02602025 */ 	or	$a0,$s3,$zero
/*  f16487c:	0c002cd4 */ 	jal	vi0000b1d0
/*  f164880:	00402025 */ 	or	$a0,$v0,$zero
/*  f164884:	0fc55c96 */ 	jal	currentPlayerScissorToViewport
/*  f164888:	00402025 */ 	or	$a0,$v0,$zero
/*  f16488c:	0fc4dc04 */ 	jal	func0f13c510
/*  f164890:	00409825 */ 	or	$s3,$v0,$zero
/*  f164894:	8e4a04b4 */ 	lw	$t2,0x4b4($s2)
/*  f164898:	24010026 */ 	addiu	$at,$zero,0x26
/*  f16489c:	3c198009 */ 	lui	$t9,0x8009
/*  f1648a0:	5541000a */ 	bnel	$t2,$at,.NB0f1648cc
/*  f1648a4:	8e4d000c */ 	lw	$t5,0xc($s2)
/*  f1648a8:	8f3999e0 */ 	lw	$t9,-0x6620($t9)
/*  f1648ac:	3c0b800a */ 	lui	$t3,0x800a
/*  f1648b0:	5f20001b */ 	bgtzl	$t9,.NB0f164920
/*  f1648b4:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1648b8:	8d6b5eb4 */ 	lw	$t3,0x5eb4($t3)
/*  f1648bc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1648c0:	51610017 */ 	beql	$t3,$at,.NB0f164920
/*  f1648c4:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1648c8:	8e4d000c */ 	lw	$t5,0xc($s2)
.NB0f1648cc:
/*  f1648cc:	29a10006 */ 	slti	$at,$t5,0x6
/*  f1648d0:	50200013 */ 	beqzl	$at,.NB0f164920
/*  f1648d4:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1648d8:	8e4c0318 */ 	lw	$t4,0x318($s2)
/*  f1648dc:	55800010 */ 	bnezl	$t4,.NB0f164920
/*  f1648e0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1648e4:	8e4e02ac */ 	lw	$t6,0x2ac($s2)
/*  f1648e8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1648ec:	3c028008 */ 	lui	$v0,0x8008
/*  f1648f0:	51c1000b */ 	beql	$t6,$at,.NB0f164920
/*  f1648f4:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1648f8:	8c4268b0 */ 	lw	$v0,0x68b0($v0)
/*  f1648fc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f164900:	28410006 */ 	slti	$at,$v0,0x6
/*  f164904:	10200002 */ 	beqz	$at,.NB0f164910
/*  f164908:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f16490c:	ae4f0320 */ 	sw	$t7,0x320($s2)
.NB0f164910:
/*  f164910:	3c018008 */ 	lui	$at,0x8008
/*  f164914:	1000001d */ 	beqz	$zero,.NB0f16498c
/*  f164918:	ac3868b0 */ 	sw	$t8,0x68b0($at)
/*  f16491c:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f164920:
/*  f164920:	3c0d8008 */ 	lui	$t5,0x8008
/*  f164924:	8e0a1580 */ 	lw	$t2,0x1580($s0)
/*  f164928:	000a5f80 */ 	sll	$t3,$t2,0x1e
/*  f16492c:	05630018 */ 	bgezl	$t3,.NB0f164990
/*  f164930:	8e4d0320 */ 	lw	$t5,0x320($s2)
/*  f164934:	8dad86e8 */ 	lw	$t5,-0x7918($t5)
/*  f164938:	24010002 */ 	addiu	$at,$zero,0x2
/*  f16493c:	55a10014 */ 	bnel	$t5,$at,.NB0f164990
/*  f164940:	8e4d0320 */ 	lw	$t5,0x320($s2)
/*  f164944:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f164948:	24010001 */ 	addiu	$at,$zero,0x1
/*  f16494c:	1041000f */ 	beq	$v0,$at,.NB0f16498c
/*  f164950:	24010002 */ 	addiu	$at,$zero,0x2
/*  f164954:	1041000d */ 	beq	$v0,$at,.NB0f16498c
/*  f164958:	3c0c800a */ 	lui	$t4,0x800a
/*  f16495c:	8d8c2780 */ 	lw	$t4,0x2780($t4)
/*  f164960:	5580000b */ 	bnezl	$t4,.NB0f164990
/*  f164964:	8e4d0320 */ 	lw	$t5,0x320($s2)
/*  f164968:	0fc2725e */ 	jal	bgun0f09eae4
/*  f16496c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164970:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164974:	00027840 */ 	sll	$t7,$v0,0x1
/*  f164978:	31f80002 */ 	andi	$t8,$t7,0x2
/*  f16497c:	920a1583 */ 	lbu	$t2,0x1583($s0)
/*  f164980:	3159fffd */ 	andi	$t9,$t2,0xfffd
/*  f164984:	03195825 */ 	or	$t3,$t8,$t9
/*  f164988:	a20b1583 */ 	sb	$t3,0x1583($s0)
.NB0f16498c:
/*  f16498c:	8e4d0320 */ 	lw	$t5,0x320($s2)
.NB0f164990:
/*  f164990:	02602025 */ 	or	$a0,$s3,$zero
/*  f164994:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f164998:	11a00008 */ 	beqz	$t5,.NB0f1649bc
/*  f16499c:	3c0f800a */ 	lui	$t7,0x800a
/*  f1649a0:	0fc4f3ca */ 	jal	bviewRenderMotionBlur
/*  f1649a4:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f1649a8:	8e4c0320 */ 	lw	$t4,0x320($s2)
/*  f1649ac:	00409825 */ 	or	$s3,$v0,$zero
/*  f1649b0:	258effff */ 	addiu	$t6,$t4,-1
/*  f1649b4:	10000499 */ 	beqz	$zero,.NB0f165c1c
/*  f1649b8:	ae4e0320 */ 	sw	$t6,0x320($s2)
.NB0f1649bc:
/*  f1649bc:	8def2780 */ 	lw	$t7,0x2780($t7)
/*  f1649c0:	3c0b8008 */ 	lui	$t3,0x8008
/*  f1649c4:	11e00012 */ 	beqz	$t7,.NB0f164a10
/*  f1649c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1649cc:	0c002d2c */ 	jal	viRenderViewportEdges
/*  f1649d0:	02602025 */ 	or	$a0,$s3,$zero
/*  f1649d4:	0fc55c96 */ 	jal	currentPlayerScissorToViewport
/*  f1649d8:	00402025 */ 	or	$a0,$v0,$zero
/*  f1649dc:	3c013f80 */ 	lui	$at,0x3f80
/*  f1649e0:	44816000 */ 	mtc1	$at,$f12
/*  f1649e4:	0c005db6 */ 	jal	mtx00016748
/*  f1649e8:	00409825 */ 	or	$s3,$v0,$zero
/*  f1649ec:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f1649f0:	8d581c50 */ 	lw	$t8,0x1c50($t2)
/*  f1649f4:	0018cfc2 */ 	srl	$t9,$t8,0x1f
/*  f1649f8:	13200488 */ 	beqz	$t9,.NB0f165c1c
/*  f1649fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164a00:	0fc3e0e0 */ 	jal	menuRender
/*  f164a04:	02602025 */ 	or	$a0,$s3,$zero
/*  f164a08:	10000484 */ 	beqz	$zero,.NB0f165c1c
/*  f164a0c:	00409825 */ 	or	$s3,$v0,$zero
.NB0f164a10:
/*  f164a10:	8d6b86e8 */ 	lw	$t3,-0x7918($t3)
/*  f164a14:	24010002 */ 	addiu	$at,$zero,0x2
/*  f164a18:	15610004 */ 	bne	$t3,$at,.NB0f164a2c
/*  f164a1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164a20:	0fc2f6ee */ 	jal	playerUpdateShootRot
/*  f164a24:	02602025 */ 	or	$a0,$s3,$zero
/*  f164a28:	00409825 */ 	or	$s3,$v0,$zero
.NB0f164a2c:
/*  f164a2c:	0c002d2c */ 	jal	viRenderViewportEdges
/*  f164a30:	02602025 */ 	or	$a0,$s3,$zero
/*  f164a34:	0fc46971 */ 	jal	func0f11f984
/*  f164a38:	00402025 */ 	or	$a0,$v0,$zero
/*  f164a3c:	0fc55c2f */ 	jal	bgTick
/*  f164a40:	00409825 */ 	or	$s3,$v0,$zero
/*  f164a44:	0fc01017 */ 	jal	func0f004314
/*  f164a48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164a4c:	0fc188ac */ 	jal	propsTick
/*  f164a50:	02202025 */ 	or	$a0,$s1,$zero
/*  f164a54:	0fc5ff30 */ 	jal	scenarioTickChr
/*  f164a58:	00002025 */ 	or	$a0,$zero,$zero
/*  f164a5c:	0fc17d1c */ 	jal	propsSort
/*  f164a60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164a64:	0fc18fd4 */ 	jal	autoaimTick
/*  f164a68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164a6c:	0fc1876c */ 	jal	handsTickAttack
/*  f164a70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164a74:	8e4d006c */ 	lw	$t5,0x6c($s2)
/*  f164a78:	24010001 */ 	addiu	$at,$zero,0x1
/*  f164a7c:	00002025 */ 	or	$a0,$zero,$zero
/*  f164a80:	11a00003 */ 	beqz	$t5,.NB0f164a90
/*  f164a84:	00001825 */ 	or	$v1,$zero,$zero
/*  f164a88:	10000001 */ 	beqz	$zero,.NB0f164a90
/*  f164a8c:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f164a90:
/*  f164a90:	8e4c0068 */ 	lw	$t4,0x68($s2)
/*  f164a94:	00001025 */ 	or	$v0,$zero,$zero
/*  f164a98:	00008025 */ 	or	$s0,$zero,$zero
/*  f164a9c:	11800003 */ 	beqz	$t4,.NB0f164aac
/*  f164aa0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164aa4:	10000001 */ 	beqz	$zero,.NB0f164aac
/*  f164aa8:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f164aac:
/*  f164aac:	8e4e0064 */ 	lw	$t6,0x64($s2)
/*  f164ab0:	11c00003 */ 	beqz	$t6,.NB0f164ac0
/*  f164ab4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164ab8:	10000001 */ 	beqz	$zero,.NB0f164ac0
/*  f164abc:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f164ac0:
/*  f164ac0:	8e4f0070 */ 	lw	$t7,0x70($s2)
/*  f164ac4:	11e00003 */ 	beqz	$t7,.NB0f164ad4
/*  f164ac8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164acc:	10000001 */ 	beqz	$zero,.NB0f164ad4
/*  f164ad0:	24100001 */ 	addiu	$s0,$zero,0x1
.NB0f164ad4:
/*  f164ad4:	02025021 */ 	addu	$t2,$s0,$v0
/*  f164ad8:	0143c021 */ 	addu	$t8,$t2,$v1
/*  f164adc:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f164ae0:	53210012 */ 	beql	$t9,$at,.NB0f164b2c
/*  f164ae4:	00002025 */ 	or	$a0,$zero,$zero
/*  f164ae8:	8e4b0298 */ 	lw	$t3,0x298($s2)
/*  f164aec:	0563000f */ 	bgezl	$t3,.NB0f164b2c
/*  f164af0:	00002025 */ 	or	$a0,$zero,$zero
/*  f164af4:	8e4d029c */ 	lw	$t5,0x29c($s2)
/*  f164af8:	05a3000c */ 	bgezl	$t5,.NB0f164b2c
/*  f164afc:	00002025 */ 	or	$a0,$zero,$zero
/*  f164b00:	0fc27dd7 */ 	jal	bgunGetWeaponNum
/*  f164b04:	00002025 */ 	or	$a0,$zero,$zero
/*  f164b08:	00402025 */ 	or	$a0,$v0,$zero
/*  f164b0c:	0fc2bd48 */ 	jal	weaponHasFlag
/*  f164b10:	3c054000 */ 	lui	$a1,0x4000
/*  f164b14:	50400051 */ 	beqzl	$v0,.NB0f164c5c
/*  f164b18:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f164b1c:	0fc314d4 */ 	jal	bmoveIsInSightAimMode
/*  f164b20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164b24:	1040004c */ 	beqz	$v0,.NB0f164c58
/*  f164b28:	00002025 */ 	or	$a0,$zero,$zero
.NB0f164b2c:
/*  f164b2c:	00002825 */ 	or	$a1,$zero,$zero
/*  f164b30:	0fc183f6 */ 	jal	func0f061d54
/*  f164b34:	00003025 */ 	or	$a2,$zero,$zero
/*  f164b38:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f164b3c:	ad821624 */ 	sw	$v0,0x1624($t4)
/*  f164b40:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164b44:	8e041624 */ 	lw	$a0,0x1624($s0)
/*  f164b48:	50800047 */ 	beqzl	$a0,.NB0f164c68
/*  f164b4c:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f164b50:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f164b54:	24010003 */ 	addiu	$at,$zero,0x3
/*  f164b58:	10410003 */ 	beq	$v0,$at,.NB0f164b68
/*  f164b5c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f164b60:	54410020 */ 	bnel	$v0,$at,.NB0f164be4
/*  f164b64:	24010001 */ 	addiu	$at,$zero,0x1
.NB0f164b68:
/*  f164b68:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f164b6c:	8c4e0014 */ 	lw	$t6,0x14($v0)
/*  f164b70:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f164b74:	05e3003c */ 	bgezl	$t7,.NB0f164c68
/*  f164b78:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f164b7c:	8e0a00d8 */ 	lw	$t2,0xd8($s0)
/*  f164b80:	3c188007 */ 	lui	$t8,0x8007
/*  f164b84:	55400014 */ 	bnezl	$t2,.NB0f164bd8
/*  f164b88:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f164b8c:	8f182e24 */ 	lw	$t8,0x2e24($t8)
/*  f164b90:	57000011 */ 	bnezl	$t8,.NB0f164bd8
/*  f164b94:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f164b98:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f164b9c:	50400007 */ 	beqzl	$v0,.NB0f164bbc
/*  f164ba0:	8e0d1c54 */ 	lw	$t5,0x1c54($s0)
/*  f164ba4:	5040000c */ 	beqzl	$v0,.NB0f164bd8
/*  f164ba8:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f164bac:	80590037 */ 	lb	$t9,0x37($v0)
/*  f164bb0:	57200009 */ 	bnezl	$t9,.NB0f164bd8
/*  f164bb4:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f164bb8:	8e0d1c54 */ 	lw	$t5,0x1c54($s0)
.NB0f164bbc:
/*  f164bbc:	8e0b00c4 */ 	lw	$t3,0xc4($s0)
/*  f164bc0:	01a06027 */ 	nor	$t4,$t5,$zero
/*  f164bc4:	016c7024 */ 	and	$t6,$t3,$t4
/*  f164bc8:	31cf0008 */ 	andi	$t7,$t6,0x8
/*  f164bcc:	55e00026 */ 	bnezl	$t7,.NB0f164c68
/*  f164bd0:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f164bd4:	ae001624 */ 	sw	$zero,0x1624($s0)
.NB0f164bd8:
/*  f164bd8:	10000022 */ 	beqz	$zero,.NB0f164c64
/*  f164bdc:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164be0:	24010001 */ 	addiu	$at,$zero,0x1
.NB0f164be4:
/*  f164be4:	50410006 */ 	beql	$v0,$at,.NB0f164c00
/*  f164be8:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f164bec:	12e20003 */ 	beq	$s7,$v0,.NB0f164bfc
/*  f164bf0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f164bf4:	54410016 */ 	bnel	$v0,$at,.NB0f164c50
/*  f164bf8:	ae001624 */ 	sw	$zero,0x1624($s0)
.NB0f164bfc:
/*  f164bfc:	8c830004 */ 	lw	$v1,0x4($a0)
.NB0f164c00:
/*  f164c00:	8c6a0010 */ 	lw	$t2,0x10($v1)
/*  f164c04:	31588000 */ 	andi	$t8,$t2,0x8000
/*  f164c08:	57000017 */ 	bnezl	$t8,.NB0f164c68
/*  f164c0c:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f164c10:	8e5904b4 */ 	lw	$t9,0x4b4($s2)
/*  f164c14:	24010026 */ 	addiu	$at,$zero,0x26
/*  f164c18:	5721000a */ 	bnel	$t9,$at,.NB0f164c44
/*  f164c1c:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f164c20:	84620004 */ 	lh	$v0,0x4($v1)
/*  f164c24:	2401014c */ 	addiu	$at,$zero,0x14c
/*  f164c28:	1041000e */ 	beq	$v0,$at,.NB0f164c64
/*  f164c2c:	240101aa */ 	addiu	$at,$zero,0x1aa
/*  f164c30:	1041000c */ 	beq	$v0,$at,.NB0f164c64
/*  f164c34:	240100b0 */ 	addiu	$at,$zero,0xb0
/*  f164c38:	5041000b */ 	beql	$v0,$at,.NB0f164c68
/*  f164c3c:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f164c40:	ae001624 */ 	sw	$zero,0x1624($s0)
.NB0f164c44:
/*  f164c44:	10000007 */ 	beqz	$zero,.NB0f164c64
/*  f164c48:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164c4c:	ae001624 */ 	sw	$zero,0x1624($s0)
.NB0f164c50:
/*  f164c50:	10000004 */ 	beqz	$zero,.NB0f164c64
/*  f164c54:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f164c58:
/*  f164c58:	8e4d0284 */ 	lw	$t5,0x284($s2)
.NB0f164c5c:
/*  f164c5c:	ada01624 */ 	sw	$zero,0x1624($t5)
/*  f164c60:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f164c64:
/*  f164c64:	26040638 */ 	addiu	$a0,$s0,0x638
.NB0f164c68:
/*  f164c68:	0fc2bf02 */ 	jal	gsetHasFunctionFlags
/*  f164c6c:	3c050008 */ 	lui	$a1,0x8
/*  f164c70:	10400005 */ 	beqz	$v0,.NB0f164c88
/*  f164c74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164c78:	0fc58fa5 */ 	jal	lvFindThreats
/*  f164c7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164c80:	10000034 */ 	beqz	$zero,.NB0f164d54
/*  f164c84:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f164c88:
/*  f164c88:	0fc27dd7 */ 	jal	bgunGetWeaponNum
/*  f164c8c:	00002025 */ 	or	$a0,$zero,$zero
/*  f164c90:	00402025 */ 	or	$a0,$v0,$zero
/*  f164c94:	0fc2bd48 */ 	jal	weaponHasFlag
/*  f164c98:	3c054000 */ 	lui	$a1,0x4000
/*  f164c9c:	5040002d */ 	beqzl	$v0,.NB0f164d54
/*  f164ca0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164ca4:	0fc66b10 */ 	jal	frIsInTraining
/*  f164ca8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164cac:	5040000f */ 	beqzl	$v0,.NB0f164cec
/*  f164cb0:	8e440284 */ 	lw	$a0,0x284($s2)
/*  f164cb4:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f164cb8:	8d6c1624 */ 	lw	$t4,0x1624($t3)
/*  f164cbc:	5180000b */ 	beqzl	$t4,.NB0f164cec
/*  f164cc0:	8e440284 */ 	lw	$a0,0x284($s2)
/*  f164cc4:	0fc314d4 */ 	jal	bmoveIsInSightAimMode
/*  f164cc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164ccc:	50400007 */ 	beqzl	$v0,.NB0f164cec
/*  f164cd0:	8e440284 */ 	lw	$a0,0x284($s2)
/*  f164cd4:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f164cd8:	0fc66a4d */ 	jal	func0f1a0924
/*  f164cdc:	8dc41624 */ 	lw	$a0,0x1624($t6)
/*  f164ce0:	1000000a */ 	beqz	$zero,.NB0f164d0c
/*  f164ce4:	00008825 */ 	or	$s1,$zero,$zero
/*  f164ce8:	8e440284 */ 	lw	$a0,0x284($s2)
.NB0f164cec:
/*  f164cec:	02802825 */ 	or	$a1,$s4,$zero
/*  f164cf0:	0fc58c71 */ 	jal	lvCheckCmpFollowThreat
/*  f164cf4:	24841624 */ 	addiu	$a0,$a0,0x1624
/*  f164cf8:	54400004 */ 	bnezl	$v0,.NB0f164d0c
/*  f164cfc:	00008825 */ 	or	$s1,$zero,$zero
/*  f164d00:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f164d04:	ade01624 */ 	sw	$zero,0x1624($t7)
/*  f164d08:	00008825 */ 	or	$s1,$zero,$zero
.NB0f164d0c:
/*  f164d0c:	00008025 */ 	or	$s0,$zero,$zero
.NB0f164d10:
/*  f164d10:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f164d14:	02202825 */ 	or	$a1,$s1,$zero
/*  f164d18:	01502021 */ 	addu	$a0,$t2,$s0
/*  f164d1c:	0fc58c71 */ 	jal	lvCheckCmpFollowThreat
/*  f164d20:	24841630 */ 	addiu	$a0,$a0,0x1630
/*  f164d24:	14400008 */ 	bnez	$v0,.NB0f164d48
/*  f164d28:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f164d2c:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f164d30:	240dfffe */ 	addiu	$t5,$zero,-2
/*  f164d34:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f164d38:	a7341634 */ 	sh	$s4,0x1634($t9)
/*  f164d3c:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f164d40:	01706021 */ 	addu	$t4,$t3,$s0
/*  f164d44:	a58d1638 */ 	sh	$t5,0x1638($t4)
.NB0f164d48:
/*  f164d48:	1637fff1 */ 	bne	$s1,$s7,.NB0f164d10
/*  f164d4c:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f164d50:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f164d54:
/*  f164d54:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f164d58:	50400072 */ 	beqzl	$v0,.NB0f164f24
/*  f164d5c:	8e0c00d0 */ 	lw	$t4,0xd0($s0)
/*  f164d60:	8e0f1c54 */ 	lw	$t7,0x1c54($s0)
/*  f164d64:	8e0e00c4 */ 	lw	$t6,0xc4($s0)
/*  f164d68:	01e05027 */ 	nor	$t2,$t7,$zero
/*  f164d6c:	01cac024 */ 	and	$t8,$t6,$t2
/*  f164d70:	33190004 */ 	andi	$t9,$t8,0x4
/*  f164d74:	5320006b */ 	beqzl	$t9,.NB0f164f24
/*  f164d78:	8e0c00d0 */ 	lw	$t4,0xd0($s0)
/*  f164d7c:	804b0039 */ 	lb	$t3,0x39($v0)
/*  f164d80:	51600068 */ 	beqzl	$t3,.NB0f164f24
/*  f164d84:	8e0c00d0 */ 	lw	$t4,0xd0($s0)
/*  f164d88:	9043006b */ 	lbu	$v1,0x6b($v0)
/*  f164d8c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f164d90:	14600011 */ 	bnez	$v1,.NB0f164dd8
/*  f164d94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164d98:	3c0143c8 */ 	lui	$at,0x43c8
/*  f164d9c:	44816000 */ 	mtc1	$at,$f12
/*  f164da0:	0fc25005 */ 	jal	objectiveCheckHolograph
/*  f164da4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164da8:	3c04800a */ 	lui	$a0,0x800a
/*  f164dac:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f164db0:	240504ff */ 	addiu	$a1,$zero,0x4ff
/*  f164db4:	00003025 */ 	or	$a2,$zero,$zero
/*  f164db8:	02803825 */ 	or	$a3,$s4,$zero
/*  f164dbc:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f164dc0:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f164dc4:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f164dc8:	0c004338 */ 	jal	sndStart
/*  f164dcc:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f164dd0:	10000053 */ 	beqz	$zero,.NB0f164f20
/*  f164dd4:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f164dd8:
/*  f164dd8:	14610032 */ 	bne	$v1,$at,.NB0f164ea4
/*  f164ddc:	3c0c8008 */ 	lui	$t4,0x8008
/*  f164de0:	8e0d0490 */ 	lw	$t5,0x490($s0)
/*  f164de4:	3c04800a */ 	lui	$a0,0x800a
/*  f164de8:	24058052 */ 	addiu	$a1,$zero,-32686
/*  f164dec:	11a00024 */ 	beqz	$t5,.NB0f164e80
/*  f164df0:	00003025 */ 	or	$a2,$zero,$zero
/*  f164df4:	3c04800a */ 	lui	$a0,0x800a
/*  f164df8:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f164dfc:	24058057 */ 	addiu	$a1,$zero,-32681
/*  f164e00:	00003025 */ 	or	$a2,$zero,$zero
/*  f164e04:	02803825 */ 	or	$a3,$s4,$zero
/*  f164e08:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f164e0c:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f164e10:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f164e14:	0c004338 */ 	jal	sndStart
/*  f164e18:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f164e1c:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164e20:	240b001c */ 	addiu	$t3,$zero,0x1c
/*  f164e24:	00002825 */ 	or	$a1,$zero,$zero
/*  f164e28:	8e0c0490 */ 	lw	$t4,0x490($s0)
/*  f164e2c:	27a70140 */ 	addiu	$a3,$sp,0x140
/*  f164e30:	258fffff */ 	addiu	$t7,$t4,-1
/*  f164e34:	ae0f0490 */ 	sw	$t7,0x490($s0)
/*  f164e38:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f164e3c:	8e0e0480 */ 	lw	$t6,0x480($s0)
/*  f164e40:	c5d00004 */ 	lwc1	$f16,0x4($t6)
/*  f164e44:	e7b00140 */ 	swc1	$f16,0x140($sp)
/*  f164e48:	8e0a0480 */ 	lw	$t2,0x480($s0)
/*  f164e4c:	c5520008 */ 	lwc1	$f18,0x8($t2)
/*  f164e50:	e7b20144 */ 	swc1	$f18,0x144($sp)
/*  f164e54:	8e180480 */ 	lw	$t8,0x480($s0)
/*  f164e58:	c704000c */ 	lwc1	$f4,0xc($t8)
/*  f164e5c:	e7a40148 */ 	swc1	$f4,0x148($sp)
/*  f164e60:	8e190480 */ 	lw	$t9,0x480($s0)
/*  f164e64:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f164e68:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f164e6c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f164e70:	0fc23e35 */ 	jal	projectileCreate
/*  f164e74:	24860008 */ 	addiu	$a2,$a0,0x8
/*  f164e78:	10000008 */ 	beqz	$zero,.NB0f164e9c
/*  f164e7c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f164e80:
/*  f164e80:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f164e84:	02803825 */ 	or	$a3,$s4,$zero
/*  f164e88:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f164e8c:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f164e90:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f164e94:	0c004338 */ 	jal	sndStart
/*  f164e98:	afb4001c */ 	sw	$s4,0x1c($sp)
.NB0f164e9c:
/*  f164e9c:	10000020 */ 	beqz	$zero,.NB0f164f20
/*  f164ea0:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f164ea4:
/*  f164ea4:	258c6904 */ 	addiu	$t4,$t4,0x6904
/*  f164ea8:	8d810000 */ 	lw	$at,0x0($t4)
/*  f164eac:	27ad0134 */ 	addiu	$t5,$sp,0x134
/*  f164eb0:	8d8a0004 */ 	lw	$t2,0x4($t4)
/*  f164eb4:	ada10000 */ 	sw	$at,0x0($t5)
/*  f164eb8:	8d810008 */ 	lw	$at,0x8($t4)
/*  f164ebc:	3c188008 */ 	lui	$t8,0x8008
/*  f164ec0:	adaa0004 */ 	sw	$t2,0x4($t5)
/*  f164ec4:	ada10008 */ 	sw	$at,0x8($t5)
/*  f164ec8:	8f186910 */ 	lw	$t8,0x6910($t8)
/*  f164ecc:	24070017 */ 	addiu	$a3,$zero,0x17
/*  f164ed0:	afb80130 */ 	sw	$t8,0x130($sp)
/*  f164ed4:	8e190480 */ 	lw	$t9,0x480($s0)
/*  f164ed8:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f164edc:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f164ee0:	24850008 */ 	addiu	$a1,$a0,0x8
/*  f164ee4:	0fc49158 */ 	jal	explosionCreateSimple
/*  f164ee8:	24860028 */ 	addiu	$a2,$a0,0x28
/*  f164eec:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f164ef0:	27ad0130 */ 	addiu	$t5,$sp,0x130
/*  f164ef4:	27a50134 */ 	addiu	$a1,$sp,0x134
/*  f164ef8:	8d6e0480 */ 	lw	$t6,0x480($t3)
/*  f164efc:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f164f00:	00003825 */ 	or	$a3,$zero,$zero
/*  f164f04:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f164f08:	8de40004 */ 	lw	$a0,0x4($t7)
/*  f164f0c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f164f10:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f164f14:	0fc0c4ba */ 	jal	chrBeginDeath
/*  f164f18:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f164f1c:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f164f20:
/*  f164f20:	8e0c00d0 */ 	lw	$t4,0xd0($s0)
.NB0f164f24:
/*  f164f24:	5180000c */ 	beqzl	$t4,.NB0f164f58
/*  f164f28:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f164f2c:	0fc1883e */ 	jal	currentPlayerInteract
/*  f164f30:	00002025 */ 	or	$a0,$zero,$zero
/*  f164f34:	10400012 */ 	beqz	$v0,.NB0f164f80
/*  f164f38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164f3c:	0fc27fe5 */ 	jal	bgunReloadIfPossible
/*  f164f40:	00002025 */ 	or	$a0,$zero,$zero
/*  f164f44:	0fc27fe5 */ 	jal	bgunReloadIfPossible
/*  f164f48:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f164f4c:	1000000c */ 	beqz	$zero,.NB0f164f80
/*  f164f50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164f54:	8e020480 */ 	lw	$v0,0x480($s0)
.NB0f164f58:
/*  f164f58:	10400009 */ 	beqz	$v0,.NB0f164f80
/*  f164f5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164f60:	804a0037 */ 	lb	$t2,0x37($v0)
/*  f164f64:	11400006 */ 	beqz	$t2,.NB0f164f80
/*  f164f68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164f6c:	9058006a */ 	lbu	$t8,0x6a($v0)
/*  f164f70:	13000003 */ 	beqz	$t8,.NB0f164f80
/*  f164f74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164f78:	0fc1883e */ 	jal	currentPlayerInteract
/*  f164f7c:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f164f80:
/*  f164f80:	0fc18d1a */ 	jal	func0f0641f4
/*  f164f84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164f88:	0fc55c71 */ 	jal	bgRender
/*  f164f8c:	02602025 */ 	or	$a0,$s3,$zero
/*  f164f90:	3c108008 */ 	lui	$s0,0x8008
/*  f164f94:	8e1086f0 */ 	lw	$s0,-0x7910($s0)
/*  f164f98:	00409825 */ 	or	$s3,$v0,$zero
/*  f164f9c:	3a19000f */ 	xori	$t9,$s0,0xf
/*  f164fa0:	2f300001 */ 	sltiu	$s0,$t9,0x1
/*  f164fa4:	16000005 */ 	bnez	$s0,.NB0f164fbc
/*  f164fa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164fac:	3c108006 */ 	lui	$s0,0x8006
/*  f164fb0:	8e101530 */ 	lw	$s0,0x1530($s0)
/*  f164fb4:	0010582b */ 	sltu	$t3,$zero,$s0
/*  f164fb8:	01608025 */ 	or	$s0,$t3,$zero
.NB0f164fbc:
/*  f164fbc:	0fc09fa8 */ 	jal	chr0f028498
/*  f164fc0:	02002025 */ 	or	$a0,$s0,$zero
/*  f164fc4:	0fc1f852 */ 	jal	propsRenderBeams
/*  f164fc8:	02602025 */ 	or	$a0,$s3,$zero
/*  f164fcc:	0fc53373 */ 	jal	shardsRender
/*  f164fd0:	00402025 */ 	or	$a0,$v0,$zero
/*  f164fd4:	0fc4aaf5 */ 	jal	sparksRender
/*  f164fd8:	00402025 */ 	or	$a0,$v0,$zero
/*  f164fdc:	0fc4aefc */ 	jal	weatherRender
/*  f164fe0:	00402025 */ 	or	$a0,$v0,$zero
/*  f164fe4:	3c0e8006 */ 	lui	$t6,0x8006
/*  f164fe8:	8dce3b50 */ 	lw	$t6,0x3b50($t6)
/*  f164fec:	00409825 */ 	or	$s3,$v0,$zero
/*  f164ff0:	11c00004 */ 	beqz	$t6,.NB0f165004
/*  f164ff4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164ff8:	0fc0278e */ 	jal	nbombsRender
/*  f164ffc:	00402025 */ 	or	$a0,$v0,$zero
/*  f165000:	00409825 */ 	or	$s3,$v0,$zero
.NB0f165004:
/*  f165004:	3c0f8008 */ 	lui	$t7,0x8008
/*  f165008:	8def86e8 */ 	lw	$t7,-0x7918($t7)
/*  f16500c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f165010:	15e10007 */ 	bne	$t7,$at,.NB0f165030
/*  f165014:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165018:	0fc2f8ed */ 	jal	playerRenderHud
/*  f16501c:	02602025 */ 	or	$a0,$s3,$zero
/*  f165020:	0fc58d05 */ 	jal	lvRenderManPosIfEnabled
/*  f165024:	00402025 */ 	or	$a0,$v0,$zero
/*  f165028:	1000000c */ 	beqz	$zero,.NB0f16505c
/*  f16502c:	00409825 */ 	or	$s3,$v0,$zero
.NB0f165030:
/*  f165030:	0fc2b30e */ 	jal	func0f0aeed8
/*  f165034:	02602025 */ 	or	$a0,$s3,$zero
/*  f165038:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f16503c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f165040:	00409825 */ 	or	$s3,$v0,$zero
/*  f165044:	95ac0010 */ 	lhu	$t4,0x10($t5)
/*  f165048:	11810004 */ 	beq	$t4,$at,.NB0f16505c
/*  f16504c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165050:	0fc555df */ 	jal	func0f15b114
/*  f165054:	00402025 */ 	or	$a0,$v0,$zero
/*  f165058:	00409825 */ 	or	$s3,$v0,$zero
.NB0f16505c:
/*  f16505c:	3c0a8008 */ 	lui	$t2,0x8008
/*  f165060:	8d4a8814 */ 	lw	$t2,-0x77ec($t2)
/*  f165064:	1d40027f */ 	bgtz	$t2,.NB0f165a64
/*  f165068:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16506c:	8e5802ac */ 	lw	$t8,0x2ac($s2)
/*  f165070:	24010006 */ 	addiu	$at,$zero,0x6
/*  f165074:	afa0012c */ 	sw	$zero,0x12c($sp)
/*  f165078:	1701010a */ 	bne	$t8,$at,.NB0f1654a4
/*  f16507c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165080:	8e5904b4 */ 	lw	$t9,0x4b4($s2)
/*  f165084:	2401004e */ 	addiu	$at,$zero,0x4e
/*  f165088:	3c04800a */ 	lui	$a0,0x800a
/*  f16508c:	17210095 */ 	bne	$t9,$at,.NB0f1652e4
/*  f165090:	00008025 */ 	or	$s0,$zero,$zero
/*  f165094:	44800000 */ 	mtc1	$zero,$f0
/*  f165098:	848425f8 */ 	lh	$a0,0x25f8($a0)
/*  f16509c:	0c0092d2 */ 	jal	animGetNumFrames
/*  f1650a0:	e7a00124 */ 	swc1	$f0,0x124($sp)
/*  f1650a4:	3c03800a */ 	lui	$v1,0x800a
/*  f1650a8:	8c6325f0 */ 	lw	$v1,0x25f0($v1)
/*  f1650ac:	c7a00124 */ 	lwc1	$f0,0x124($sp)
/*  f1650b0:	3c0b800a */ 	lui	$t3,0x800a
/*  f1650b4:	2861005a */ 	slti	$at,$v1,0x5a
/*  f1650b8:	10200009 */ 	beqz	$at,.NB0f1650e0
/*  f1650bc:	2444ffff */ 	addiu	$a0,$v0,-1
/*  f1650c0:	44833000 */ 	mtc1	$v1,$f6
/*  f1650c4:	3c0142b4 */ 	lui	$at,0x42b4
/*  f1650c8:	44815000 */ 	mtc1	$at,$f10
/*  f1650cc:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1650d0:	3c013f80 */ 	lui	$at,0x3f80
/*  f1650d4:	44819000 */ 	mtc1	$at,$f18
/*  f1650d8:	460a4403 */ 	div.s	$f16,$f8,$f10
/*  f1650dc:	46109001 */ 	sub.s	$f0,$f18,$f16
.NB0f1650e0:
/*  f1650e0:	856b25f8 */ 	lh	$t3,0x25f8($t3)
/*  f1650e4:	2401046c */ 	addiu	$at,$zero,0x46c
/*  f1650e8:	248cffe2 */ 	addiu	$t4,$a0,-30
/*  f1650ec:	1161000d */ 	beq	$t3,$at,.NB0f165124
/*  f1650f0:	3c19e700 */ 	lui	$t9,0xe700
/*  f1650f4:	2444ffff */ 	addiu	$a0,$v0,-1
/*  f1650f8:	248effa6 */ 	addiu	$t6,$a0,-90
/*  f1650fc:	01c3082a */ 	slt	$at,$t6,$v1
/*  f165100:	10200012 */ 	beqz	$at,.NB0f16514c
/*  f165104:	00647823 */ 	subu	$t7,$v1,$a0
/*  f165108:	25ed005a */ 	addiu	$t5,$t7,0x5a
/*  f16510c:	448d2000 */ 	mtc1	$t5,$f4
/*  f165110:	3c0142b4 */ 	lui	$at,0x42b4
/*  f165114:	44814000 */ 	mtc1	$at,$f8
/*  f165118:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f16511c:	1000000b */ 	beqz	$zero,.NB0f16514c
/*  f165120:	46083003 */ 	div.s	$f0,$f6,$f8
.NB0f165124:
/*  f165124:	0183082a */ 	slt	$at,$t4,$v1
/*  f165128:	10200008 */ 	beqz	$at,.NB0f16514c
/*  f16512c:	00645023 */ 	subu	$t2,$v1,$a0
/*  f165130:	2558001e */ 	addiu	$t8,$t2,0x1e
/*  f165134:	44985000 */ 	mtc1	$t8,$f10
/*  f165138:	3c0141f0 */ 	lui	$at,0x41f0
/*  f16513c:	44818000 */ 	mtc1	$at,$f16
/*  f165140:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f165144:	2410ff00 */ 	addiu	$s0,$zero,-256
/*  f165148:	46109003 */ 	div.s	$f0,$f18,$f16
.NB0f16514c:
/*  f16514c:	44802000 */ 	mtc1	$zero,$f4
/*  f165150:	3c0bb900 */ 	lui	$t3,0xb900
/*  f165154:	3c0e0050 */ 	lui	$t6,0x50
/*  f165158:	4600203c */ 	c.lt.s	$f4,$f0
/*  f16515c:	02601025 */ 	or	$v0,$s3,$zero
/*  f165160:	35ce4340 */ 	ori	$t6,$t6,0x4340
/*  f165164:	356b031d */ 	ori	$t3,$t3,0x31d
/*  f165168:	4500005e */ 	bc1f	.NB0f1652e4
/*  f16516c:	3c0ffcff */ 	lui	$t7,0xfcff
/*  f165170:	3c01437f */ 	lui	$at,0x437f
/*  f165174:	44813000 */ 	mtc1	$at,$f6
/*  f165178:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f16517c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f165180:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f165184:	02601825 */ 	or	$v1,$s3,$zero
/*  f165188:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f16518c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f165190:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f165194:	02602025 */ 	or	$a0,$s3,$zero
/*  f165198:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f16519c:	444af800 */ 	cfc1	$t2,$31
/*  f1651a0:	44d8f800 */ 	ctc1	$t8,$31
/*  f1651a4:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f1651a8:	3c0dfffd */ 	lui	$t5,0xfffd
/*  f1651ac:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f1651b0:	35adf6fb */ 	ori	$t5,$t5,0xf6fb
/*  f1651b4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1651b8:	35efffff */ 	ori	$t7,$t7,0xffff
/*  f1651bc:	4458f800 */ 	cfc1	$t8,$31
/*  f1651c0:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f1651c4:	ac8d0004 */ 	sw	$t5,0x4($a0)
/*  f1651c8:	02602825 */ 	or	$a1,$s3,$zero
/*  f1651cc:	3c0cfa00 */ 	lui	$t4,0xfa00
/*  f1651d0:	33180078 */ 	andi	$t8,$t8,0x78
/*  f1651d4:	acac0000 */ 	sw	$t4,0x0($a1)
/*  f1651d8:	13000013 */ 	beqz	$t8,.NB0f165228
/*  f1651dc:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1651e0:	3c014f00 */ 	lui	$at,0x4f00
/*  f1651e4:	44815000 */ 	mtc1	$at,$f10
/*  f1651e8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1651ec:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f1651f0:	44d8f800 */ 	ctc1	$t8,$31
/*  f1651f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1651f8:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f1651fc:	4458f800 */ 	cfc1	$t8,$31
/*  f165200:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165204:	33180078 */ 	andi	$t8,$t8,0x78
/*  f165208:	17000005 */ 	bnez	$t8,.NB0f165220
/*  f16520c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165210:	44185000 */ 	mfc1	$t8,$f10
/*  f165214:	3c018000 */ 	lui	$at,0x8000
/*  f165218:	10000007 */ 	beqz	$zero,.NB0f165238
/*  f16521c:	0301c025 */ 	or	$t8,$t8,$at
.NB0f165220:
/*  f165220:	10000005 */ 	beqz	$zero,.NB0f165238
/*  f165224:	2418ffff */ 	addiu	$t8,$zero,-1
.NB0f165228:
/*  f165228:	44185000 */ 	mfc1	$t8,$f10
/*  f16522c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165230:	0700fffb */ 	bltz	$t8,.NB0f165220
/*  f165234:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f165238:
/*  f165238:	0218c825 */ 	or	$t9,$s0,$t8
/*  f16523c:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f165240:	44caf800 */ 	ctc1	$t2,$31
/*  f165244:	afb30108 */ 	sw	$s3,0x108($sp)
/*  f165248:	0c002f97 */ 	jal	viGetViewWidth
/*  f16524c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f165250:	0c002fb5 */ 	jal	viGetViewLeft
/*  f165254:	a7a2008e */ 	sh	$v0,0x8e($sp)
/*  f165258:	00028400 */ 	sll	$s0,$v0,0x10
/*  f16525c:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f165260:	0c002fb9 */ 	jal	viGetViewTop
/*  f165264:	01608025 */ 	or	$s0,$t3,$zero
/*  f165268:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f16526c:	00117403 */ 	sra	$t6,$s1,0x10
/*  f165270:	0c002f9b */ 	jal	viGetViewHeight
/*  f165274:	01c08825 */ 	or	$s1,$t6,$zero
/*  f165278:	87b8008e */ 	lh	$t8,0x8e($sp)
/*  f16527c:	00517821 */ 	addu	$t7,$v0,$s1
/*  f165280:	31ed03ff */ 	andi	$t5,$t7,0x3ff
/*  f165284:	000d6080 */ 	sll	$t4,$t5,0x2
/*  f165288:	0218c821 */ 	addu	$t9,$s0,$t8
/*  f16528c:	332b03ff */ 	andi	$t3,$t9,0x3ff
/*  f165290:	3c01f600 */ 	lui	$at,0xf600
/*  f165294:	8fad0108 */ 	lw	$t5,0x108($sp)
/*  f165298:	01815025 */ 	or	$t2,$t4,$at
/*  f16529c:	000b7380 */ 	sll	$t6,$t3,0xe
/*  f1652a0:	014e7825 */ 	or	$t7,$t2,$t6
/*  f1652a4:	0c002fb5 */ 	jal	viGetViewLeft
/*  f1652a8:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f1652ac:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f1652b0:	00116403 */ 	sra	$t4,$s1,0x10
/*  f1652b4:	0c002fb9 */ 	jal	viGetViewTop
/*  f1652b8:	01808825 */ 	or	$s1,$t4,$zero
/*  f1652bc:	305803ff */ 	andi	$t8,$v0,0x3ff
/*  f1652c0:	322b03ff */ 	andi	$t3,$s1,0x3ff
/*  f1652c4:	8faf0108 */ 	lw	$t7,0x108($sp)
/*  f1652c8:	000b5380 */ 	sll	$t2,$t3,0xe
/*  f1652cc:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1652d0:	032a7025 */ 	or	$t6,$t9,$t2
/*  f1652d4:	02602025 */ 	or	$a0,$s3,$zero
/*  f1652d8:	0fc537ce */ 	jal	func0f153838
/*  f1652dc:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f1652e0:	00409825 */ 	or	$s3,$v0,$zero
.NB0f1652e4:
/*  f1652e4:	3c10800a */ 	lui	$s0,0x800a
/*  f1652e8:	861025f8 */ 	lh	$s0,0x25f8($s0)
/*  f1652ec:	24010181 */ 	addiu	$at,$zero,0x181
/*  f1652f0:	3c048008 */ 	lui	$a0,0x8008
/*  f1652f4:	12010011 */ 	beq	$s0,$at,.NB0f16533c
/*  f1652f8:	24010183 */ 	addiu	$at,$zero,0x183
/*  f1652fc:	1201000f */ 	beq	$s0,$at,.NB0f16533c
/*  f165300:	24010188 */ 	addiu	$at,$zero,0x188
/*  f165304:	1201000d */ 	beq	$s0,$at,.NB0f16533c
/*  f165308:	240101e5 */ 	addiu	$at,$zero,0x1e5
/*  f16530c:	16010065 */ 	bne	$s0,$at,.NB0f1654a4
/*  f165310:	3c03800a */ 	lui	$v1,0x800a
/*  f165314:	8c6325f0 */ 	lw	$v1,0x25f0($v1)
/*  f165318:	28610348 */ 	slti	$at,$v1,0x348
/*  f16531c:	14200061 */ 	bnez	$at,.NB0f1654a4
/*  f165320:	28610583 */ 	slti	$at,$v1,0x583
/*  f165324:	1020005f */ 	beqz	$at,.NB0f1654a4
/*  f165328:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16532c:	0fc50990 */ 	jal	bviewRenderHorizonScanner
/*  f165330:	02602025 */ 	or	$a0,$s3,$zero
/*  f165334:	1000005b */ 	beqz	$zero,.NB0f1654a4
/*  f165338:	00409825 */ 	or	$s3,$v0,$zero
.NB0f16533c:
/*  f16533c:	8c846914 */ 	lw	$a0,0x6914($a0)
/*  f165340:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f165344:	00008025 */ 	or	$s0,$zero,$zero
/*  f165348:	1480000c */ 	bnez	$a0,.NB0f16537c
/*  f16534c:	afad012c */ 	sw	$t5,0x12c($sp)
/*  f165350:	3c04800a */ 	lui	$a0,0x800a
/*  f165354:	3c068008 */ 	lui	$a2,0x8008
/*  f165358:	24c66914 */ 	addiu	$a2,$a2,0x6914
/*  f16535c:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f165360:	2405059f */ 	addiu	$a1,$zero,0x59f
/*  f165364:	02803825 */ 	or	$a3,$s4,$zero
/*  f165368:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f16536c:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f165370:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f165374:	0c004338 */ 	jal	sndStart
/*  f165378:	afb4001c */ 	sw	$s4,0x1c($sp)
.NB0f16537c:
/*  f16537c:	3c0c8008 */ 	lui	$t4,0x8008
/*  f165380:	8d8c6918 */ 	lw	$t4,0x6918($t4)
/*  f165384:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f165388:	3c018008 */ 	lui	$at,0x8008
/*  f16538c:	01985823 */ 	subu	$t3,$t4,$t8
/*  f165390:	0561000b */ 	bgez	$t3,.NB0f1653c0
/*  f165394:	ac2b6918 */ 	sw	$t3,0x6918($at)
/*  f165398:	0c004d84 */ 	jal	random
/*  f16539c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1653a0:	240100c8 */ 	addiu	$at,$zero,0xc8
/*  f1653a4:	0041001b */ 	divu	$zero,$v0,$at
/*  f1653a8:	0000c810 */ 	mfhi	$t9
/*  f1653ac:	272a0028 */ 	addiu	$t2,$t9,0x28
/*  f1653b0:	3c018008 */ 	lui	$at,0x8008
/*  f1653b4:	ac2a6918 */ 	sw	$t2,0x6918($at)
/*  f1653b8:	3c018008 */ 	lui	$at,0x8008
/*  f1653bc:	a020691c */ 	sb	$zero,0x691c($at)
.NB0f1653c0:
/*  f1653c0:	02602025 */ 	or	$a0,$s3,$zero
/*  f1653c4:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f1653c8:	0fc4f51f */ 	jal	bviewRenderFilmLens
/*  f1653cc:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f1653d0:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1653d4:	8dce6918 */ 	lw	$t6,0x6918($t6)
/*  f1653d8:	00409825 */ 	or	$s3,$v0,$zero
/*  f1653dc:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1653e0:	29c1000f */ 	slti	$at,$t6,0xf
/*  f1653e4:	10200017 */ 	beqz	$at,.NB0f165444
/*  f1653e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1653ec:	91ef691c */ 	lbu	$t7,0x691c($t7)
/*  f1653f0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f1653f4:	3c018008 */ 	lui	$at,0x8008
/*  f1653f8:	15e0000b */ 	bnez	$t7,.NB0f165428
/*  f1653fc:	3c04800a */ 	lui	$a0,0x800a
/*  f165400:	a02d691c */ 	sb	$t5,0x691c($at)
/*  f165404:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f165408:	2405059e */ 	addiu	$a1,$zero,0x59e
/*  f16540c:	00003025 */ 	or	$a2,$zero,$zero
/*  f165410:	02803825 */ 	or	$a3,$s4,$zero
/*  f165414:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f165418:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16541c:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f165420:	0c004338 */ 	jal	sndStart
/*  f165424:	afb4001c */ 	sw	$s4,0x1c($sp)
.NB0f165428:
/*  f165428:	3c0c8008 */ 	lui	$t4,0x8008
/*  f16542c:	8d8c6918 */ 	lw	$t4,0x6918($t4)
/*  f165430:	240b00e1 */ 	addiu	$t3,$zero,0xe1
/*  f165434:	000cc080 */ 	sll	$t8,$t4,0x2
/*  f165438:	030cc021 */ 	addu	$t8,$t8,$t4
/*  f16543c:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f165440:	01788023 */ 	subu	$s0,$t3,$t8
.NB0f165444:
/*  f165444:	0c004d84 */ 	jal	random
/*  f165448:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16544c:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f165450:	0041001b */ 	divu	$zero,$v0,$at
/*  f165454:	0000c810 */ 	mfhi	$t9
/*  f165458:	24010001 */ 	addiu	$at,$zero,0x1
/*  f16545c:	1721000b */ 	bne	$t9,$at,.NB0f16548c
/*  f165460:	3c04800a */ 	lui	$a0,0x800a
/*  f165464:	241000ff */ 	addiu	$s0,$zero,0xff
/*  f165468:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f16546c:	2405059d */ 	addiu	$a1,$zero,0x59d
/*  f165470:	00003025 */ 	or	$a2,$zero,$zero
/*  f165474:	02803825 */ 	or	$a3,$s4,$zero
/*  f165478:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f16547c:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f165480:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f165484:	0c004338 */ 	jal	sndStart
/*  f165488:	afb4001c */ 	sw	$s4,0x1c($sp)
.NB0f16548c:
/*  f16548c:	12000005 */ 	beqz	$s0,.NB0f1654a4
/*  f165490:	02602025 */ 	or	$a0,$s3,$zero
/*  f165494:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f165498:	0fc4f44d */ 	jal	bviewRenderStatic
/*  f16549c:	02003025 */ 	or	$a2,$s0,$zero
/*  f1654a0:	00409825 */ 	or	$s3,$v0,$zero
.NB0f1654a4:
/*  f1654a4:	3c048008 */ 	lui	$a0,0x8008
/*  f1654a8:	8c846914 */ 	lw	$a0,0x6914($a0)
/*  f1654ac:	8faa012c */ 	lw	$t2,0x12c($sp)
/*  f1654b0:	50800006 */ 	beqzl	$a0,.NB0f1654cc
/*  f1654b4:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1654b8:	55400004 */ 	bnezl	$t2,.NB0f1654cc
/*  f1654bc:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1654c0:	0c00d428 */ 	jal	audioStop
/*  f1654c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1654c8:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f1654cc:
/*  f1654cc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1654d0:	960e0010 */ 	lhu	$t6,0x10($s0)
/*  f1654d4:	55c1001c */ 	bnel	$t6,$at,.NB0f165548
/*  f1654d8:	960c0010 */ 	lhu	$t4,0x10($s0)
/*  f1654dc:	8e4f02ac */ 	lw	$t7,0x2ac($s2)
/*  f1654e0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1654e4:	02602025 */ 	or	$a0,$s3,$zero
/*  f1654e8:	11e10016 */ 	beq	$t7,$at,.NB0f165544
/*  f1654ec:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f1654f0:	0fc4f499 */ 	jal	bviewRenderSlayerRocketLens
/*  f1654f4:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f1654f8:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f1654fc:	00409825 */ 	or	$s3,$v0,$zero
/*  f165500:	2401005a */ 	addiu	$at,$zero,0x5a
/*  f165504:	8e0300c8 */ 	lw	$v1,0xc8($s0)
/*  f165508:	02602025 */ 	or	$a0,$s3,$zero
/*  f16550c:	3c054fff */ 	lui	$a1,0x4fff
/*  f165510:	1860000c */ 	blez	$v1,.NB0f165544
/*  f165514:	00033200 */ 	sll	$a2,$v1,0x8
/*  f165518:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f16551c:	00c1001a */ 	div	$zero,$a2,$at
/*  f165520:	00003012 */ 	mflo	$a2
/*  f165524:	2cc10100 */ 	sltiu	$at,$a2,0x100
/*  f165528:	14200002 */ 	bnez	$at,.NB0f165534
/*  f16552c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165530:	240600ff */ 	addiu	$a2,$zero,0xff
.NB0f165534:
/*  f165534:	0fc4f44d */ 	jal	bviewRenderStatic
/*  f165538:	34a5ffff */ 	ori	$a1,$a1,0xffff
/*  f16553c:	00409825 */ 	or	$s3,$v0,$zero
/*  f165540:	8e500284 */ 	lw	$s0,0x284($s2)
.NB0f165544:
/*  f165544:	960c0010 */ 	lhu	$t4,0x10($s0)
.NB0f165548:
/*  f165548:	24010001 */ 	addiu	$at,$zero,0x1
/*  f16554c:	55810017 */ 	bnel	$t4,$at,.NB0f1655ac
/*  f165550:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f165554:	8e4b02ac */ 	lw	$t3,0x2ac($s2)
/*  f165558:	24010006 */ 	addiu	$at,$zero,0x6
/*  f16555c:	51610013 */ 	beql	$t3,$at,.NB0f1655ac
/*  f165560:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f165564:	8e020254 */ 	lw	$v0,0x254($s0)
/*  f165568:	24060063 */ 	addiu	$a2,$zero,0x63
/*  f16556c:	240a00f9 */ 	addiu	$t2,$zero,0xf9
/*  f165570:	284100c8 */ 	slti	$at,$v0,0xc8
/*  f165574:	10200004 */ 	beqz	$at,.NB0f165588
/*  f165578:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f16557c:	0302c023 */ 	subu	$t8,$t8,$v0
/*  f165580:	0018c883 */ 	sra	$t9,$t8,0x2
/*  f165584:	01593023 */ 	subu	$a2,$t2,$t9
.NB0f165588:
/*  f165588:	3c017f1b */ 	lui	$at,0x7f1b
/*  f16558c:	c4201fbc */ 	lwc1	$f0,0x1fbc($at)
/*  f165590:	02602025 */ 	or	$a0,$s3,$zero
/*  f165594:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f165598:	44070000 */ 	mfc1	$a3,$f0
/*  f16559c:	0fc4f5b8 */ 	jal	bviewRenderZoomBlur
/*  f1655a0:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f1655a4:	00409825 */ 	or	$s3,$v0,$zero
/*  f1655a8:	8e430460 */ 	lw	$v1,0x460($s2)
.NB0f1655ac:
/*  f1655ac:	18600003 */ 	blez	$v1,.NB0f1655bc
/*  f1655b0:	2861001e */ 	slti	$at,$v1,0x1e
/*  f1655b4:	5420000c */ 	bnezl	$at,.NB0f1655e8
/*  f1655b8:	2401001e */ 	addiu	$at,$zero,0x1e
.NB0f1655bc:
/*  f1655bc:	8e420464 */ 	lw	$v0,0x464($s2)
/*  f1655c0:	10400004 */ 	beqz	$v0,.NB0f1655d4
/*  f1655c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1655c8:	8e4e0468 */ 	lw	$t6,0x468($s2)
/*  f1655cc:	51c00006 */ 	beqzl	$t6,.NB0f1655e8
/*  f1655d0:	2401001e */ 	addiu	$at,$zero,0x1e
.NB0f1655d4:
/*  f1655d4:	54400085 */ 	bnezl	$v0,.NB0f1657ec
/*  f1655d8:	28610010 */ 	slti	$at,$v1,0x10
/*  f1655dc:	8e4f0468 */ 	lw	$t7,0x468($s2)
/*  f1655e0:	11e00081 */ 	beqz	$t7,.NB0f1657e8
/*  f1655e4:	2401001e */ 	addiu	$at,$zero,0x1e
.NB0f1655e8:
/*  f1655e8:	54610018 */ 	bnel	$v1,$at,.NB0f16564c
/*  f1655ec:	2861000f */ 	slti	$at,$v1,0xf
/*  f1655f0:	8e4d0464 */ 	lw	$t5,0x464($s2)
/*  f1655f4:	55a00015 */ 	bnezl	$t5,.NB0f16564c
/*  f1655f8:	2861000f */ 	slti	$at,$v1,0xf
/*  f1655fc:	0fc599a0 */ 	jal	lvGetSlowMotionType
/*  f165600:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165604:	10400003 */ 	beqz	$v0,.NB0f165614
/*  f165608:	3c04800a */ 	lui	$a0,0x800a
/*  f16560c:	10000002 */ 	beqz	$zero,.NB0f165618
/*  f165610:	241005c9 */ 	addiu	$s0,$zero,0x5c9
.NB0f165614:
/*  f165614:	241002ad */ 	addiu	$s0,$zero,0x2ad
.NB0f165618:
/*  f165618:	00102c00 */ 	sll	$a1,$s0,0x10
/*  f16561c:	00056403 */ 	sra	$t4,$a1,0x10
/*  f165620:	01802825 */ 	or	$a1,$t4,$zero
/*  f165624:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f165628:	00003025 */ 	or	$a2,$zero,$zero
/*  f16562c:	02803825 */ 	or	$a3,$s4,$zero
/*  f165630:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f165634:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f165638:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f16563c:	0c004338 */ 	jal	sndStart
/*  f165640:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f165644:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f165648:	2861000f */ 	slti	$at,$v1,0xf
.NB0f16564c:
/*  f16564c:	10200026 */ 	beqz	$at,.NB0f1656e8
/*  f165650:	240a001e */ 	addiu	$t2,$zero,0x1e
/*  f165654:	2401000f */ 	addiu	$at,$zero,0xf
/*  f165658:	00033080 */ 	sll	$a2,$v1,0x2
/*  f16565c:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f165660:	00063080 */ 	sll	$a2,$a2,0x2
/*  f165664:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f165668:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16566c:	00c33021 */ 	addu	$a2,$a2,$v1
/*  f165670:	00063080 */ 	sll	$a2,$a2,0x2
/*  f165674:	00c1001a */ 	div	$zero,$a2,$at
/*  f165678:	44839000 */ 	mtc1	$v1,$f18
/*  f16567c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f165680:	c4241fc0 */ 	lwc1	$f4,0x1fc0($at)
/*  f165684:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f165688:	3c017f1b */ 	lui	$at,0x7f1b
/*  f16568c:	c4281fc4 */ 	lwc1	$f8,0x1fc4($at)
/*  f165690:	00003012 */ 	mflo	$a2
/*  f165694:	02602025 */ 	or	$a0,$s3,$zero
/*  f165698:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f16569c:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f1656a0:	46083000 */ 	add.s	$f0,$f6,$f8
/*  f1656a4:	44070000 */ 	mfc1	$a3,$f0
/*  f1656a8:	0fc4f5b8 */ 	jal	bviewRenderZoomBlur
/*  f1656ac:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f1656b0:	8e580460 */ 	lw	$t8,0x460($s2)
/*  f1656b4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1656b8:	c4301fc8 */ 	lwc1	$f16,0x1fc8($at)
/*  f1656bc:	44985000 */ 	mtc1	$t8,$f10
/*  f1656c0:	00402025 */ 	or	$a0,$v0,$zero
/*  f1656c4:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f1656c8:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f1656cc:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f1656d0:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f1656d4:	46109102 */ 	mul.s	$f4,$f18,$f16
/*  f1656d8:	0fc2e348 */ 	jal	playerDrawFade
/*  f1656dc:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f1656e0:	10000029 */ 	beqz	$zero,.NB0f165788
/*  f1656e4:	00409825 */ 	or	$s3,$v0,$zero
.NB0f1656e8:
/*  f1656e8:	2401000f */ 	addiu	$at,$zero,0xf
/*  f1656ec:	01431023 */ 	subu	$v0,$t2,$v1
/*  f1656f0:	00023080 */ 	sll	$a2,$v0,0x2
/*  f1656f4:	00c23023 */ 	subu	$a2,$a2,$v0
/*  f1656f8:	00063080 */ 	sll	$a2,$a2,0x2
/*  f1656fc:	00c23023 */ 	subu	$a2,$a2,$v0
/*  f165700:	00063080 */ 	sll	$a2,$a2,0x2
/*  f165704:	00c23021 */ 	addu	$a2,$a2,$v0
/*  f165708:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16570c:	00c1001a */ 	div	$zero,$a2,$at
/*  f165710:	44823000 */ 	mtc1	$v0,$f6
/*  f165714:	3c017f1b */ 	lui	$at,0x7f1b
/*  f165718:	c42a1fcc */ 	lwc1	$f10,0x1fcc($at)
/*  f16571c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f165720:	3c017f1b */ 	lui	$at,0x7f1b
/*  f165724:	c4301fd0 */ 	lwc1	$f16,0x1fd0($at)
/*  f165728:	00003012 */ 	mflo	$a2
/*  f16572c:	02602025 */ 	or	$a0,$s3,$zero
/*  f165730:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f165734:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f165738:	46109000 */ 	add.s	$f0,$f18,$f16
/*  f16573c:	44070000 */ 	mfc1	$a3,$f0
/*  f165740:	0fc4f5b8 */ 	jal	bviewRenderZoomBlur
/*  f165744:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f165748:	8e4e0460 */ 	lw	$t6,0x460($s2)
/*  f16574c:	3c0141f0 */ 	lui	$at,0x41f0
/*  f165750:	44812000 */ 	mtc1	$at,$f4
/*  f165754:	448e3000 */ 	mtc1	$t6,$f6
/*  f165758:	3c017f1b */ 	lui	$at,0x7f1b
/*  f16575c:	c4321fd4 */ 	lwc1	$f18,0x1fd4($at)
/*  f165760:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f165764:	00402025 */ 	or	$a0,$v0,$zero
/*  f165768:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f16576c:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f165770:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f165774:	46082281 */ 	sub.s	$f10,$f4,$f8
/*  f165778:	46125402 */ 	mul.s	$f16,$f10,$f18
/*  f16577c:	0fc2e348 */ 	jal	playerDrawFade
/*  f165780:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f165784:	00409825 */ 	or	$s3,$v0,$zero
.NB0f165788:
/*  f165788:	8e4f028c */ 	lw	$t7,0x28c($s2)
/*  f16578c:	55e0000c */ 	bnezl	$t7,.NB0f1657c0
/*  f165790:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f165794:	8e4d0464 */ 	lw	$t5,0x464($s2)
/*  f165798:	51a00006 */ 	beqzl	$t5,.NB0f1657b4
/*  f16579c:	8e580460 */ 	lw	$t8,0x460($s2)
/*  f1657a0:	8e4c0460 */ 	lw	$t4,0x460($s2)
/*  f1657a4:	258b0001 */ 	addiu	$t3,$t4,0x1
/*  f1657a8:	10000004 */ 	beqz	$zero,.NB0f1657bc
/*  f1657ac:	ae4b0460 */ 	sw	$t3,0x460($s2)
/*  f1657b0:	8e580460 */ 	lw	$t8,0x460($s2)
.NB0f1657b4:
/*  f1657b4:	270affff */ 	addiu	$t2,$t8,-1
/*  f1657b8:	ae4a0460 */ 	sw	$t2,0x460($s2)
.NB0f1657bc:
/*  f1657bc:	8e430460 */ 	lw	$v1,0x460($s2)
.NB0f1657c0:
/*  f1657c0:	2861001f */ 	slti	$at,$v1,0x1f
/*  f1657c4:	14200004 */ 	bnez	$at,.NB0f1657d8
/*  f1657c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1657cc:	2403001e */ 	addiu	$v1,$zero,0x1e
/*  f1657d0:	10000005 */ 	beqz	$zero,.NB0f1657e8
/*  f1657d4:	ae430460 */ 	sw	$v1,0x460($s2)
.NB0f1657d8:
/*  f1657d8:	04630004 */ 	bgezl	$v1,.NB0f1657ec
/*  f1657dc:	28610010 */ 	slti	$at,$v1,0x10
/*  f1657e0:	ae400460 */ 	sw	$zero,0x460($s2)
/*  f1657e4:	00001825 */ 	or	$v1,$zero,$zero
.NB0f1657e8:
/*  f1657e8:	28610010 */ 	slti	$at,$v1,0x10
.NB0f1657ec:
/*  f1657ec:	14200003 */ 	bnez	$at,.NB0f1657fc
/*  f1657f0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1657f4:	10000002 */ 	beqz	$zero,.NB0f165800
/*  f1657f8:	ae4e0468 */ 	sw	$t6,0x468($s2)
.NB0f1657fc:
/*  f1657fc:	ae400468 */ 	sw	$zero,0x468($s2)
.NB0f165800:
/*  f165800:	52c00009 */ 	beqzl	$s6,.NB0f165828
/*  f165804:	8e4f02ac */ 	lw	$t7,0x2ac($s2)
/*  f165808:	0fc50cd0 */ 	jal	bviewClearBlur
/*  f16580c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165810:	02602025 */ 	or	$a0,$s3,$zero
/*  f165814:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f165818:	0fc4f3ca */ 	jal	bviewRenderMotionBlur
/*  f16581c:	02c03025 */ 	or	$a2,$s6,$zero
/*  f165820:	00409825 */ 	or	$s3,$v0,$zero
/*  f165824:	8e4f02ac */ 	lw	$t7,0x2ac($s2)
.NB0f165828:
/*  f165828:	24010006 */ 	addiu	$at,$zero,0x6
/*  f16582c:	15e10031 */ 	bne	$t7,$at,.NB0f1658f4
/*  f165830:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165834:	0fc2e143 */ 	jal	playerGetCutsceneBlurFrac
/*  f165838:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16583c:	44803000 */ 	mtc1	$zero,$f6
/*  f165840:	3c01437f */ 	lui	$at,0x437f
/*  f165844:	4600303c */ 	c.lt.s	$f6,$f0
/*  f165848:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16584c:	45000029 */ 	bc1f	.NB0f1658f4
/*  f165850:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165854:	44812000 */ 	mtc1	$at,$f4
/*  f165858:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f16585c:	3c014f00 */ 	lui	$at,0x4f00
/*  f165860:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f165864:	02602025 */ 	or	$a0,$s3,$zero
/*  f165868:	2405ff00 */ 	addiu	$a1,$zero,-256
/*  f16586c:	444df800 */ 	cfc1	$t5,$31
/*  f165870:	44c6f800 */ 	ctc1	$a2,$31
/*  f165874:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165878:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f16587c:	4446f800 */ 	cfc1	$a2,$31
/*  f165880:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165884:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f165888:	50c00013 */ 	beqzl	$a2,.NB0f1658d8
/*  f16588c:	44065000 */ 	mfc1	$a2,$f10
/*  f165890:	44815000 */ 	mtc1	$at,$f10
/*  f165894:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f165898:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f16589c:	44c6f800 */ 	ctc1	$a2,$31
/*  f1658a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1658a4:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f1658a8:	4446f800 */ 	cfc1	$a2,$31
/*  f1658ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1658b0:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f1658b4:	14c00005 */ 	bnez	$a2,.NB0f1658cc
/*  f1658b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1658bc:	44065000 */ 	mfc1	$a2,$f10
/*  f1658c0:	3c018000 */ 	lui	$at,0x8000
/*  f1658c4:	10000007 */ 	beqz	$zero,.NB0f1658e4
/*  f1658c8:	00c13025 */ 	or	$a2,$a2,$at
.NB0f1658cc:
/*  f1658cc:	10000005 */ 	beqz	$zero,.NB0f1658e4
/*  f1658d0:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f1658d4:	44065000 */ 	mfc1	$a2,$f10
.NB0f1658d8:
/*  f1658d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1658dc:	04c0fffb */ 	bltz	$a2,.NB0f1658cc
/*  f1658e0:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f1658e4:
/*  f1658e4:	44cdf800 */ 	ctc1	$t5,$31
/*  f1658e8:	0fc4f3ca */ 	jal	bviewRenderMotionBlur
/*  f1658ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1658f0:	00409825 */ 	or	$s3,$v0,$zero
.NB0f1658f4:
/*  f1658f4:	0fc466b7 */ 	jal	debugGetMotionBlur
/*  f1658f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1658fc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f165900:	14410006 */ 	bne	$v0,$at,.NB0f16591c
/*  f165904:	02602025 */ 	or	$a0,$s3,$zero
/*  f165908:	2405ff00 */ 	addiu	$a1,$zero,-256
/*  f16590c:	0fc4f3ca */ 	jal	bviewRenderMotionBlur
/*  f165910:	24060080 */ 	addiu	$a2,$zero,0x80
/*  f165914:	10000014 */ 	beqz	$zero,.NB0f165968
/*  f165918:	00409825 */ 	or	$s3,$v0,$zero
.NB0f16591c:
/*  f16591c:	0fc466b7 */ 	jal	debugGetMotionBlur
/*  f165920:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165924:	24010002 */ 	addiu	$at,$zero,0x2
/*  f165928:	14410006 */ 	bne	$v0,$at,.NB0f165944
/*  f16592c:	02602025 */ 	or	$a0,$s3,$zero
/*  f165930:	2405ff00 */ 	addiu	$a1,$zero,-256
/*  f165934:	0fc4f3ca */ 	jal	bviewRenderMotionBlur
/*  f165938:	240600c0 */ 	addiu	$a2,$zero,0xc0
/*  f16593c:	1000000a */ 	beqz	$zero,.NB0f165968
/*  f165940:	00409825 */ 	or	$s3,$v0,$zero
.NB0f165944:
/*  f165944:	0fc466b7 */ 	jal	debugGetMotionBlur
/*  f165948:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16594c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f165950:	14410005 */ 	bne	$v0,$at,.NB0f165968
/*  f165954:	02602025 */ 	or	$a0,$s3,$zero
/*  f165958:	2405ff00 */ 	addiu	$a1,$zero,-256
/*  f16595c:	0fc4f3ca */ 	jal	bviewRenderMotionBlur
/*  f165960:	240600e6 */ 	addiu	$a2,$zero,0xe6
/*  f165964:	00409825 */ 	or	$s3,$v0,$zero
.NB0f165968:
/*  f165968:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16596c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f165970:	92031bfc */ 	lbu	$v1,0x1bfc($s0)
/*  f165974:	1860003b */ 	blez	$v1,.NB0f165a64
/*  f165978:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16597c:	14610002 */ 	bne	$v1,$at,.NB0f165988
/*  f165980:	00008825 */ 	or	$s1,$zero,$zero
/*  f165984:	241100ff */ 	addiu	$s1,$zero,0xff
.NB0f165988:
/*  f165988:	56e30009 */ 	bnel	$s7,$v1,.NB0f1659b0
/*  f16598c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f165990:	92021bfd */ 	lbu	$v0,0x1bfd($s0)
/*  f165994:	28410010 */ 	slti	$at,$v0,0x10
/*  f165998:	50200005 */ 	beqzl	$at,.NB0f1659b0
/*  f16599c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1659a0:	00028823 */ 	negu	$s1,$v0
/*  f1659a4:	00116100 */ 	sll	$t4,$s1,0x4
/*  f1659a8:	259100f0 */ 	addiu	$s1,$t4,0xf0
/*  f1659ac:	24010002 */ 	addiu	$at,$zero,0x2
.NB0f1659b0:
/*  f1659b0:	1461000b */ 	bne	$v1,$at,.NB0f1659e0
/*  f1659b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1659b8:	92021bfd */ 	lbu	$v0,0x1bfd($s0)
/*  f1659bc:	28410021 */ 	slti	$at,$v0,0x21
/*  f1659c0:	54200004 */ 	bnezl	$at,.NB0f1659d4
/*  f1659c4:	24010030 */ 	addiu	$at,$zero,0x30
/*  f1659c8:	00028900 */ 	sll	$s1,$v0,0x4
/*  f1659cc:	2631fe00 */ 	addiu	$s1,$s1,-512
/*  f1659d0:	24010030 */ 	addiu	$at,$zero,0x30
.NB0f1659d4:
/*  f1659d4:	14410002 */ 	bne	$v0,$at,.NB0f1659e0
/*  f1659d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1659dc:	241100ff */ 	addiu	$s1,$zero,0xff
.NB0f1659e0:
/*  f1659e0:	12200020 */ 	beqz	$s1,.NB0f165a64
/*  f1659e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1659e8:	0fc5374a */ 	jal	func0f153628
/*  f1659ec:	02602025 */ 	or	$a0,$s3,$zero
/*  f1659f0:	0c002fb5 */ 	jal	viGetViewLeft
/*  f1659f4:	00409825 */ 	or	$s3,$v0,$zero
/*  f1659f8:	0c002fb9 */ 	jal	viGetViewTop
/*  f1659fc:	a7a20072 */ 	sh	$v0,0x72($sp)
/*  f165a00:	0c002fb5 */ 	jal	viGetViewLeft
/*  f165a04:	a7a20074 */ 	sh	$v0,0x74($sp)
/*  f165a08:	0c002f97 */ 	jal	viGetViewWidth
/*  f165a0c:	a7a20076 */ 	sh	$v0,0x76($sp)
/*  f165a10:	0c002fb9 */ 	jal	viGetViewTop
/*  f165a14:	a7a2008e */ 	sh	$v0,0x8e($sp)
/*  f165a18:	00028400 */ 	sll	$s0,$v0,0x10
/*  f165a1c:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f165a20:	0c002f9b */ 	jal	viGetViewHeight
/*  f165a24:	01608025 */ 	or	$s0,$t3,$zero
/*  f165a28:	87b8008e */ 	lh	$t8,0x8e($sp)
/*  f165a2c:	87aa0076 */ 	lh	$t2,0x76($sp)
/*  f165a30:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f165a34:	02217025 */ 	or	$t6,$s1,$at
/*  f165a38:	0050c821 */ 	addu	$t9,$v0,$s0
/*  f165a3c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f165a40:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f165a44:	02602025 */ 	or	$a0,$s3,$zero
/*  f165a48:	87a50072 */ 	lh	$a1,0x72($sp)
/*  f165a4c:	87a60074 */ 	lh	$a2,0x74($sp)
/*  f165a50:	0fc53824 */ 	jal	func0f153a34
/*  f165a54:	030a3821 */ 	addu	$a3,$t8,$t2
/*  f165a58:	0fc537a0 */ 	jal	func0f153780
/*  f165a5c:	00402025 */ 	or	$a0,$v0,$zero
/*  f165a60:	00409825 */ 	or	$s3,$v0,$zero
.NB0f165a64:
/*  f165a64:	0fc58ba8 */ 	jal	lvRenderFade
/*  f165a68:	02602025 */ 	or	$a0,$s3,$zero
/*  f165a6c:	0fc5ff45 */ 	jal	scenarioRenderHud
/*  f165a70:	00402025 */ 	or	$a0,$v0,$zero
/*  f165a74:	3c0f8009 */ 	lui	$t7,0x8009
/*  f165a78:	91efaf74 */ 	lbu	$t7,-0x508c($t7)
/*  f165a7c:	00409825 */ 	or	$s3,$v0,$zero
/*  f165a80:	11e00004 */ 	beqz	$t7,.NB0f165a94
/*  f165a84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165a88:	0fc673dc */ 	jal	frRenderHud
/*  f165a8c:	00402025 */ 	or	$a0,$v0,$zero
/*  f165a90:	00409825 */ 	or	$s3,$v0,$zero
.NB0f165a94:
/*  f165a94:	0fc46697 */ 	jal	debugGetTilesDebugMode
/*  f165a98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165a9c:	54400016 */ 	bnezl	$v0,.NB0f165af8
/*  f165aa0:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f165aa4:	0fc4669a */ 	jal	debugGetPadsDebugMode
/*  f165aa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165aac:	54400012 */ 	bnezl	$v0,.NB0f165af8
/*  f165ab0:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f165ab4:	0fc466a6 */ 	jal	debug0f11eea8
/*  f165ab8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165abc:	5440000e */ 	bnezl	$v0,.NB0f165af8
/*  f165ac0:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f165ac4:	0fc466f0 */ 	jal	debug0f11ef80
/*  f165ac8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165acc:	5440000a */ 	bnezl	$v0,.NB0f165af8
/*  f165ad0:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f165ad4:	0fc466ed */ 	jal	debugIsChrStatsEnabled
/*  f165ad8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165adc:	54400006 */ 	bnezl	$v0,.NB0f165af8
/*  f165ae0:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f165ae4:	0fc46673 */ 	jal	debug0f11ee40
/*  f165ae8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165aec:	1040002c */ 	beqz	$v0,.NB0f165ba0
/*  f165af0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165af4:	8e4d0284 */ 	lw	$t5,0x284($s2)
.NB0f165af8:
/*  f165af8:	00001825 */ 	or	$v1,$zero,$zero
/*  f165afc:	27a200c8 */ 	addiu	$v0,$sp,0xc8
/*  f165b00:	8dac0014 */ 	lw	$t4,0x14($t5)
/*  f165b04:	a7b4009e */ 	sh	$s4,0x9e($sp)
/*  f165b08:	27b0009c */ 	addiu	$s0,$sp,0x9c
/*  f165b0c:	a7ac009c */ 	sh	$t4,0x9c($sp)
/*  f165b10:	87ab009c */ 	lh	$t3,0x9c($sp)
/*  f165b14:	528b0009 */ 	beql	$s4,$t3,.NB0f165b3c
/*  f165b18:	00035040 */ 	sll	$t2,$v1,0x1
/*  f165b1c:	86040000 */ 	lh	$a0,0x0($s0)
.NB0f165b20:
/*  f165b20:	a4440000 */ 	sh	$a0,0x0($v0)
/*  f165b24:	86040002 */ 	lh	$a0,0x2($s0)
/*  f165b28:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f165b2c:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f165b30:	1684fffb */ 	bne	$s4,$a0,.NB0f165b20
/*  f165b34:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f165b38:	00035040 */ 	sll	$t2,$v1,0x1
.NB0f165b3c:
/*  f165b3c:	03cac821 */ 	addu	$t9,$s8,$t2
/*  f165b40:	a7340000 */ 	sh	$s4,0x0($t9)
/*  f165b44:	87ae009c */ 	lh	$t6,0x9c($sp)
/*  f165b48:	27b0009c */ 	addiu	$s0,$sp,0x9c
/*  f165b4c:	128e000d */ 	beq	$s4,$t6,.NB0f165b84
/*  f165b50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165b54:	86040000 */ 	lh	$a0,0x0($s0)
/*  f165b58:	02a02825 */ 	or	$a1,$s5,$zero
.NB0f165b5c:
/*  f165b5c:	0fc57b6a */ 	jal	roomGetNeighbours
/*  f165b60:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f165b64:	02a02025 */ 	or	$a0,$s5,$zero
/*  f165b68:	03c02825 */ 	or	$a1,$s8,$zero
/*  f165b6c:	0fc19290 */ 	jal	roomsAppend
/*  f165b70:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f165b74:	86040002 */ 	lh	$a0,0x2($s0)
/*  f165b78:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f165b7c:	5684fff7 */ 	bnel	$s4,$a0,.NB0f165b5c
/*  f165b80:	02a02825 */ 	or	$a1,$s5,$zero
.NB0f165b84:
/*  f165b84:	0fc466ed */ 	jal	debugIsChrStatsEnabled
/*  f165b88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165b8c:	10400004 */ 	beqz	$v0,.NB0f165ba0
/*  f165b90:	02602025 */ 	or	$a0,$s3,$zero
/*  f165b94:	0fc1307a */ 	jal	chrsRenderChrStats
/*  f165b98:	03c02825 */ 	or	$a1,$s8,$zero
/*  f165b9c:	00409825 */ 	or	$s3,$v0,$zero
.NB0f165ba0:
/*  f165ba0:	0fc48846 */ 	jal	func0f1274d8
/*  f165ba4:	02602025 */ 	or	$a0,$s3,$zero
/*  f165ba8:	0fc3f30d */ 	jal	amRender
/*  f165bac:	00402025 */ 	or	$a0,$v0,$zero
/*  f165bb0:	3c013f80 */ 	lui	$at,0x3f80
/*  f165bb4:	44816000 */ 	mtc1	$at,$f12
/*  f165bb8:	0c005db6 */ 	jal	mtx00016748
/*  f165bbc:	00409825 */ 	or	$s3,$v0,$zero
/*  f165bc0:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f165bc4:	8dac1c50 */ 	lw	$t4,0x1c50($t5)
/*  f165bc8:	000c5fc2 */ 	srl	$t3,$t4,0x1f
/*  f165bcc:	51600005 */ 	beqzl	$t3,.NB0f165be4
/*  f165bd0:	8e580288 */ 	lw	$t8,0x288($s2)
/*  f165bd4:	0fc3e0e0 */ 	jal	menuRender
/*  f165bd8:	02602025 */ 	or	$a0,$s3,$zero
/*  f165bdc:	00409825 */ 	or	$s3,$v0,$zero
/*  f165be0:	8e580288 */ 	lw	$t8,0x288($s2)
.NB0f165be4:
/*  f165be4:	0c005db6 */ 	jal	mtx00016748
/*  f165be8:	c70c0074 */ 	lwc1	$f12,0x74($t8)
/*  f165bec:	8e4a0314 */ 	lw	$t2,0x314($s2)
/*  f165bf0:	51400005 */ 	beqzl	$t2,.NB0f165c08
/*  f165bf4:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f165bf8:	0fc60ecb */ 	jal	mpRenderModalText
/*  f165bfc:	02602025 */ 	or	$a0,$s3,$zero
/*  f165c00:	00409825 */ 	or	$s3,$v0,$zero
/*  f165c04:	8e590284 */ 	lw	$t9,0x284($s2)
.NB0f165c08:
/*  f165c08:	932e19b3 */ 	lbu	$t6,0x19b3($t9)
/*  f165c0c:	11c00003 */ 	beqz	$t6,.NB0f165c1c
/*  f165c10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165c14:	0fc2d40c */ 	jal	playerStartNewLife
/*  f165c18:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f165c1c:
/*  f165c1c:	0fc4dc13 */ 	jal	func0f13c54c
/*  f165c20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165c24:	8e4f0298 */ 	lw	$t7,0x298($s2)
/*  f165c28:	3c0c8007 */ 	lui	$t4,0x8007
/*  f165c2c:	05e10004 */ 	bgez	$t7,.NB0f165c40
/*  f165c30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165c34:	8e4d029c */ 	lw	$t5,0x29c($s2)
/*  f165c38:	05a20012 */ 	bltzl	$t5,.NB0f165c84
/*  f165c3c:	8fb00064 */ 	lw	$s0,0x64($sp)
.NB0f165c40:
/*  f165c40:	8d8c2e24 */ 	lw	$t4,0x2e24($t4)
/*  f165c44:	3c0b8006 */ 	lui	$t3,0x8006
/*  f165c48:	11800004 */ 	beqz	$t4,.NB0f165c5c
/*  f165c4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165c50:	8d6bf2f0 */ 	lw	$t3,-0xd10($t3)
/*  f165c54:	51600007 */ 	beqzl	$t3,.NB0f165c74
/*  f165c58:	8e58028c */ 	lw	$t8,0x28c($s2)
.NB0f165c5c:
/*  f165c5c:	0fc3e4d2 */ 	jal	menuGetRoot
/*  f165c60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165c64:	24010009 */ 	addiu	$at,$zero,0x9
/*  f165c68:	54410006 */ 	bnel	$v0,$at,.NB0f165c84
/*  f165c6c:	8fb00064 */ 	lw	$s0,0x64($sp)
/*  f165c70:	8e58028c */ 	lw	$t8,0x28c($s2)
.NB0f165c74:
/*  f165c74:	53000003 */ 	beqzl	$t8,.NB0f165c84
/*  f165c78:	8fb00064 */ 	lw	$s0,0x64($sp)
/*  f165c7c:	8fb30188 */ 	lw	$s3,0x188($sp)
/*  f165c80:	8fb00064 */ 	lw	$s0,0x64($sp)
.NB0f165c84:
/*  f165c84:	8faa018c */ 	lw	$t2,0x18c($sp)
/*  f165c88:	560afa91 */ 	bnel	$s0,$t2,.NB0f1646d0
/*  f165c8c:	8fab0184 */ 	lw	$t3,0x184($sp)
.NB0f165c90:
/*  f165c90:	825904d3 */ 	lb	$t9,0x4d3($s2)
.NB0f165c94:
/*  f165c94:	3c014080 */ 	lui	$at,0x4080
/*  f165c98:	4481a000 */ 	mtc1	$at,$f20
/*  f165c9c:	13200013 */ 	beqz	$t9,.NB0f165cec
/*  f165ca0:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f165ca4:	824e04d6 */ 	lb	$t6,0x4d6($s2)
/*  f165ca8:	51c00011 */ 	beqzl	$t6,.NB0f165cf0
/*  f165cac:	824b04d3 */ 	lb	$t3,0x4d3($s2)
/*  f165cb0:	824f04d7 */ 	lb	$t7,0x4d7($s2)
/*  f165cb4:	a24004d3 */ 	sb	$zero,0x4d3($s2)
/*  f165cb8:	a24004d6 */ 	sb	$zero,0x4d6($s2)
/*  f165cbc:	51e00004 */ 	beqzl	$t7,.NB0f165cd0
/*  f165cc0:	824d04d4 */ 	lb	$t5,0x4d4($s2)
/*  f165cc4:	a25404d4 */ 	sb	$s4,0x4d4($s2)
/*  f165cc8:	a24004d5 */ 	sb	$zero,0x4d5($s2)
/*  f165ccc:	824d04d4 */ 	lb	$t5,0x4d4($s2)
.NB0f165cd0:
/*  f165cd0:	05a30007 */ 	bgezl	$t5,.NB0f165cf0
/*  f165cd4:	824b04d3 */ 	lb	$t3,0x4d3($s2)
/*  f165cd8:	824c04d5 */ 	lb	$t4,0x4d5($s2)
/*  f165cdc:	5d800004 */ 	bgtzl	$t4,.NB0f165cf0
/*  f165ce0:	824b04d3 */ 	lb	$t3,0x4d3($s2)
/*  f165ce4:	0c003c56 */ 	jal	mainChangeToStage
/*  f165ce8:	2404005a */ 	addiu	$a0,$zero,0x5a
.NB0f165cec:
/*  f165cec:	824b04d3 */ 	lb	$t3,0x4d3($s2)
.NB0f165cf0:
/*  f165cf0:	5560004a */ 	bnezl	$t3,.NB0f165e1c
/*  f165cf4:	02608025 */ 	or	$s0,$s3,$zero
/*  f165cf8:	825804d4 */ 	lb	$t8,0x4d4($s2)
/*  f165cfc:	07020047 */ 	bltzl	$t8,.NB0f165e1c
/*  f165d00:	02608025 */ 	or	$s0,$s3,$zero
/*  f165d04:	824a04d5 */ 	lb	$t2,0x4d5($s2)
/*  f165d08:	59400044 */ 	blezl	$t2,.NB0f165e1c
/*  f165d0c:	02608025 */ 	or	$s0,$s3,$zero
/*  f165d10:	0fc36d1e */ 	jal	hudmsgRemoveAll
/*  f165d14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165d18:	825904d4 */ 	lb	$t9,0x4d4($s2)
/*  f165d1c:	2415000c */ 	addiu	$s5,$zero,0xc
/*  f165d20:	3c118007 */ 	lui	$s1,0x8007
/*  f165d24:	03350019 */ 	multu	$t9,$s5
/*  f165d28:	26315c38 */ 	addiu	$s1,$s1,0x5c38
/*  f165d2c:	00007012 */ 	mflo	$t6
/*  f165d30:	022e7821 */ 	addu	$t7,$s1,$t6
/*  f165d34:	8ded0004 */ 	lw	$t5,0x4($t7)
/*  f165d38:	0c003c59 */ 	jal	mainGetStageNum
/*  f165d3c:	a24d04d2 */ 	sb	$t5,0x4d2($s2)
/*  f165d40:	824c04d4 */ 	lb	$t4,0x4d4($s2)
/*  f165d44:	3c10800a */ 	lui	$s0,0x800a
/*  f165d48:	261027a8 */ 	addiu	$s0,$s0,0x27a8
/*  f165d4c:	01950019 */ 	multu	$t4,$s5
/*  f165d50:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f165d54:	00005812 */ 	mflo	$t3
/*  f165d58:	022bc021 */ 	addu	$t8,$s1,$t3
/*  f165d5c:	870a0000 */ 	lh	$t2,0x0($t8)
/*  f165d60:	504a0023 */ 	beql	$v0,$t2,.NB0f165df0
/*  f165d64:	824c04d5 */ 	lb	$t4,0x4d5($s2)
/*  f165d68:	92190003 */ 	lbu	$t9,0x3($s0)
/*  f165d6c:	ae400314 */ 	sw	$zero,0x314($s2)
/*  f165d70:	ae400318 */ 	sw	$zero,0x318($s2)
/*  f165d74:	332fff7f */ 	andi	$t7,$t9,0xff7f
/*  f165d78:	a20f0003 */ 	sb	$t7,0x3($s0)
/*  f165d7c:	31ed00bf */ 	andi	$t5,$t7,0xbf
/*  f165d80:	ae400294 */ 	sw	$zero,0x294($s2)
/*  f165d84:	ae540298 */ 	sw	$s4,0x298($s2)
/*  f165d88:	ae54029c */ 	sw	$s4,0x29c($s2)
/*  f165d8c:	0fc06821 */ 	jal	setNumPlayers
/*  f165d90:	a20d0003 */ 	sb	$t5,0x3($s0)
/*  f165d94:	0fc06945 */ 	jal	titleSetNextMode
/*  f165d98:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f165d9c:	920c0000 */ 	lbu	$t4,0x0($s0)
/*  f165da0:	00002025 */ 	or	$a0,$zero,$zero
/*  f165da4:	318bff01 */ 	andi	$t3,$t4,0xff01
/*  f165da8:	0fc59ed6 */ 	jal	lvSetDifficulty
/*  f165dac:	a20b0000 */ 	sb	$t3,0x0($s0)
/*  f165db0:	825804d4 */ 	lb	$t8,0x4d4($s2)
/*  f165db4:	03150019 */ 	multu	$t8,$s5
/*  f165db8:	00005012 */ 	mflo	$t2
/*  f165dbc:	022a1021 */ 	addu	$v0,$s1,$t2
/*  f165dc0:	84590002 */ 	lh	$t9,0x2($v0)
/*  f165dc4:	84440000 */ 	lh	$a0,0x0($v0)
/*  f165dc8:	a2190002 */ 	sb	$t9,0x2($s0)
/*  f165dcc:	0fc06ba1 */ 	jal	titleSetNextStage
/*  f165dd0:	a2040001 */ 	sb	$a0,0x1($s0)
/*  f165dd4:	824e04d4 */ 	lb	$t6,0x4d4($s2)
/*  f165dd8:	01d50019 */ 	multu	$t6,$s5
/*  f165ddc:	00007812 */ 	mflo	$t7
/*  f165de0:	022f6821 */ 	addu	$t5,$s1,$t7
/*  f165de4:	0c003c56 */ 	jal	mainChangeToStage
/*  f165de8:	85a40000 */ 	lh	$a0,0x0($t5)
/*  f165dec:	824c04d5 */ 	lb	$t4,0x4d5($s2)
.NB0f165df0:
/*  f165df0:	258bffff */ 	addiu	$t3,$t4,-1
/*  f165df4:	a24b04d5 */ 	sb	$t3,0x4d5($s2)
/*  f165df8:	825804d5 */ 	lb	$t8,0x4d5($s2)
/*  f165dfc:	5b000006 */ 	blezl	$t8,.NB0f165e18
/*  f165e00:	a25404d4 */ 	sb	$s4,0x4d4($s2)
/*  f165e04:	824a04d4 */ 	lb	$t2,0x4d4($s2)
/*  f165e08:	25590001 */ 	addiu	$t9,$t2,0x1
/*  f165e0c:	10000002 */ 	beqz	$zero,.NB0f165e18
/*  f165e10:	a25904d4 */ 	sb	$t9,0x4d4($s2)
/*  f165e14:	a25404d4 */ 	sb	$s4,0x4d4($s2)
.NB0f165e18:
/*  f165e18:	02608025 */ 	or	$s0,$s3,$zero
.NB0f165e1c:
/*  f165e1c:	3c0eed00 */ 	lui	$t6,0xed00
/*  f165e20:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*  f165e24:	0c002f77 */ 	jal	viGetWidth
/*  f165e28:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f165e2c:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f165e30:	00117c03 */ 	sra	$t7,$s1,0x10
/*  f165e34:	0c002f7b */ 	jal	viGetHeight
/*  f165e38:	01e08825 */ 	or	$s1,$t7,$zero
/*  f165e3c:	44829000 */ 	mtc1	$v0,$f18
/*  f165e40:	44914000 */ 	mtc1	$s1,$f8
/*  f165e44:	3c03800b */ 	lui	$v1,0x800b
/*  f165e48:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f165e4c:	3c04800b */ 	lui	$a0,0x800b
/*  f165e50:	2484ee30 */ 	addiu	$a0,$a0,-4560
/*  f165e54:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f165e58:	46148182 */ 	mul.s	$f6,$f16,$f20
/*  f165e5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165e60:	46145482 */ 	mul.s	$f18,$f10,$f20
/*  f165e64:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f165e68:	4600940d */ 	trunc.w.s	$f16,$f18
/*  f165e6c:	440c2000 */ 	mfc1	$t4,$f4
/*  f165e70:	440a8000 */ 	mfc1	$t2,$f16
/*  f165e74:	318b0fff */ 	andi	$t3,$t4,0xfff
/*  f165e78:	31590fff */ 	andi	$t9,$t2,0xfff
/*  f165e7c:	00197300 */ 	sll	$t6,$t9,0xc
/*  f165e80:	016e7825 */ 	or	$t7,$t3,$t6
/*  f165e84:	ae0f0004 */ 	sw	$t7,0x4($s0)
/*  f165e88:	9063ee50 */ 	lbu	$v1,-0x11b0($v1)
/*  f165e8c:	00036880 */ 	sll	$t5,$v1,0x2
/*  f165e90:	008d6021 */ 	addu	$t4,$a0,$t5
/*  f165e94:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f165e98:	00035080 */ 	sll	$t2,$v1,0x2
/*  f165e9c:	008ac821 */ 	addu	$t9,$a0,$t2
/*  f165ea0:	0278082b */ 	sltu	$at,$s3,$t8
/*  f165ea4:	14200005 */ 	bnez	$at,.NB0f165ebc
/*  f165ea8:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f165eac:	8f2b0004 */ 	lw	$t3,0x4($t9)
/*  f165eb0:	0173082b */ 	sltu	$at,$t3,$s3
/*  f165eb4:	50200006 */ 	beqzl	$at,.NB0f165ed0
/*  f165eb8:	8fbf0054 */ 	lw	$ra,0x54($sp)
.NB0f165ebc:
/*  f165ebc:	0c003074 */ 	jal	crashSetMessage
/*  f165ec0:	24841e78 */ 	addiu	$a0,$a0,0x1e78
/*  f165ec4:	240e0045 */ 	addiu	$t6,$zero,0x45
/*  f165ec8:	a00e0000 */ 	sb	$t6,0x0($zero)
/*  f165ecc:	8fbf0054 */ 	lw	$ra,0x54($sp)
.NB0f165ed0:
/*  f165ed0:	02601025 */ 	or	$v0,$s3,$zero
/*  f165ed4:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f165ed8:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f165edc:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f165ee0:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f165ee4:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f165ee8:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f165eec:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f165ef0:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f165ef4:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f165ef8:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f165efc:	03e00008 */ 	jr	$ra
/*  f165f00:	27bd01f0 */ 	addiu	$sp,$sp,0x1f0
);
#endif

const char var7f1b7730[] = "fr: %d\n";

#if VERSION >= VERSION_PAL_FINAL
u32 var800840a4 = 0;
u32 var800840a8 = 100;
u32 var800840ac = 0;
u32 g_CutsceneTime240_60 = 0;
#elif VERSION >= VERSION_NTSC_1_0
u32 g_CutsceneTime240_60 = 0;
u32 var800840a8 = 0;
u32 var800840ac = 0;
u32 var800840b0 = 0;
#else
u32 var80086910nb = 0;
u32 var80086914nb = 0;
u32 var80086918nb = 0;
u32 var8008691cnb = 0x1e000000;
u32 var80086920nb = 0;
u32 var80086924nb = 100;
u32 var80086928nb = 0;
u32 g_CutsceneTime240_60 = 0;
u32 var80086930nb = 0;
u32 var800840a8 = 0;
u32 var800840ac = 0;
u32 var800840b0 = 0;
#endif

u32 var800840b4 = 0;
u32 var800840b8 = 0;
u32 var800840bc = 0;

void lvUpdateSoloHandicaps(void)
{
	if (g_Vars.antiplayernum >= 0) {
		if (g_Difficulty == DIFF_A) {
			g_CameraWaitMultiplier = 2;
			var8006994c = 2;
			var80069950 = 0.5f;
			var80069954 = 0.5f;
			var80069958 = 2;
			g_EnemyAccuracyScale = 0.5f;
			g_DamageReceivedScale = 0.35f;
			g_DamageDealtScale = 4;
			g_ExplosionDamageReceivedScale = 0.25f;
			var80069880 = 1.5f;
			g_AmmoMultiplier = 3;
			var80062cac = 0.2f;
		} else if (g_Difficulty == DIFF_SA) {
			g_CameraWaitMultiplier = 2;
			var8006994c = 1.5f;
			var80069950 = 0.5f;
			var80069954 = 0.5f;
			var80069958 = 1.5f;
			g_EnemyAccuracyScale = 0.6f;
			g_DamageReceivedScale = 0.5f;
			g_DamageDealtScale = 3;
			g_ExplosionDamageReceivedScale = 0.25f;
			var80069880 = 1.1f;
			g_AmmoMultiplier = 2.5f;
			var80062cac = 0.5f;
		} else {
			g_CameraWaitMultiplier = 2;
			var8006994c = 1;
			var80069950 = 0.5f;
			var80069954 = 0.5f;
			var80069958 = 1;
			g_EnemyAccuracyScale = 0.7f;
			g_DamageReceivedScale = 0.65f;
			g_DamageDealtScale = 2;
			g_ExplosionDamageReceivedScale = 0.25f;
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
			g_EnemyAccuracyScale = 0.6f;
			g_DamageReceivedScale = 0.5f;
			g_DamageDealtScale = 2;
			g_ExplosionDamageReceivedScale = 0.25f;
			var80069880 = 1.5f;
			g_AmmoMultiplier = 2;
			var80062cac = 0.2f;
		} else if (g_Difficulty == DIFF_SA) {
			g_CameraWaitMultiplier = 1;
			var8006994c = 1;
			var80069950 = 0.75f;
			var80069954 = 1;
			var80069958 = 1;
			g_EnemyAccuracyScale = 0.75f;
			g_DamageReceivedScale = 1;
			g_DamageDealtScale = 1;
			g_ExplosionDamageReceivedScale = 1;
			var80069880 = g_Jpn ? 1.1f : 0.75f;
			g_AmmoMultiplier = 1.5f;
			var80062cac = 0.5f;
		} else {
			g_CameraWaitMultiplier = 1;
			var8006994c = 1;
			var80069950 = 1;
			var80069954 = 1.5f;
			var80069958 = 1;
			g_EnemyAccuracyScale = 1.5f;
			g_DamageReceivedScale = 1.5f;
			g_DamageDealtScale = 1;
			g_ExplosionDamageReceivedScale = 1.5f;
			var80069880 = g_Jpn ? 0.75f : 0.2f;
			g_AmmoMultiplier = 1;
			var80062cac = 1;
		}
	} else {
		if (g_Difficulty == DIFF_A) {
			f32 totalhealth;
			f32 frac = 1;

			if (g_Vars.coopplayernum < 0 && g_Vars.antiplayernum < 0) {
				totalhealth = playerGetHealthFrac() + playerGetShieldFrac();

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
			g_EnemyAccuracyScale = 0.6f;
			g_DamageReceivedScale = 0.5f * frac;
			g_DamageDealtScale = 2;
			g_ExplosionDamageReceivedScale = 0.25f * frac;
			var80069880 = 1.5f;
			g_AmmoMultiplier = 2;
			var80062cac = 0.2f;
		} else if (g_Difficulty == DIFF_SA) {
			g_CameraWaitMultiplier = 1;
			var8006994c = 1;
			var80069950 = 0.75f;
			var80069954 = 0.75f;
			var80069958 = 1;
			g_EnemyAccuracyScale = 0.8f;
			g_DamageReceivedScale = 0.6f;
			g_DamageDealtScale = 1;
			g_ExplosionDamageReceivedScale = 0.75f;
			var80069880 = g_Jpn ? 1.1f : 0.75f;
			g_AmmoMultiplier = 1.5f;
			var80062cac = 0.5f;
		} else if (g_Difficulty == DIFF_PA) {
			g_CameraWaitMultiplier = 1;
			var8006994c = 1;
			var80069950 = 1;
			var80069954 = 1;
			var80069958 = 1;
			g_EnemyAccuracyScale = 1.175f;
			g_DamageReceivedScale = 1;
			g_DamageDealtScale = 1;
			g_ExplosionDamageReceivedScale = 1;
			var80069880 = g_Jpn ? 0.75f : 0.2f;
			g_AmmoMultiplier = 1;
			var80062cac = 1;
		} else if (g_Difficulty == DIFF_PD) {
			g_CameraWaitMultiplier = 1;
			var8006994c = 1;
			var80069950 = 1;
			var80069954 = 1;
			var80069958 = 1;
			g_EnemyAccuracyScale = 1.1f;
			g_DamageReceivedScale = 1;
			g_DamageDealtScale = 1;
			g_ExplosionDamageReceivedScale = 1;
			var80069880 = 1;
			g_AmmoMultiplier = 1;
			var80062cac = 1;
		}
	}
}

#if PIRACYCHECKS

#if VERSION >= VERSION_PAL_FINAL
#define SUBAMOUNT 6661
#else
#define SUBAMOUNT 54321
#endif

s32 sub54321(s32 value)
{
	return value - SUBAMOUNT;
}
#endif

void lvUpdateCutsceneTime(void)
{
	if (g_Vars.in_cutscene) {
		g_CutsceneTime240_60 += g_Vars.lvupdate240_60;
		return;
	}

	g_CutsceneTime240_60 = 0;
}

s32 lvGetSlowMotionType(void)
{
#if PIRACYCHECKS
#if VERSION >= VERSION_PAL_FINAL
	u32 addr = sub54321(0xb0000340 + SUBAMOUNT);
	u32 actual;
	u32 expected = sub54321(0x0330c820 + SUBAMOUNT);
#else
	u32 addr = sub54321(0xb0000a5c + SUBAMOUNT);
	u32 actual;
	u32 expected = sub54321(0x1740fff9 + SUBAMOUNT);
#endif

	osPiReadIo(addr, &actual);

	if (actual != expected) {
		u32 *ptr = (u32 *)&rspbootTextStart;
		u32 *end = (u32 *)(u32)ptr + 1024;

		while (ptr < end) {
			*ptr += 8;
			ptr++;
		}
	}
#endif

	if (g_Vars.normmplayerisrunning) {
		if (g_MpSetup.options & MPOPTION_SLOWMOTION_ON) {
			return SLOWMOTION_ON;
		}
		if (g_MpSetup.options & MPOPTION_SLOWMOTION_SMART) {
			return SLOWMOTION_SMART;
		}
	} else {
		if (cheatIsActive(CHEAT_SLOMO)) {
			return SLOWMOTION_ON;
		}
		if (debugGetSlowMotion() == SLOWMOTION_ON) {
			return SLOWMOTION_ON;
		}
		if (debugGetSlowMotion() == SLOWMOTION_SMART) {
			return SLOWMOTION_SMART;
		}
	}

	return SLOWMOTION_OFF;
}

void lvTick(void)
{
	s32 j;
	s32 i;

	lvCheckPauseStateChanged();

#if VERSION >= VERSION_NTSC_1_0
	if (g_Vars.unk0004e4) {
		pak0f11c54c();
	}
#endif

	if (g_Vars.joydisableframestogo > 0) {
		g_Vars.joydisableframestogo--;
	} else if (g_Vars.joydisableframestogo == 0) {
#if VERSION >= VERSION_NTSC_1_0
		joy00013938();
#else
		if (!joyIsCyclicPollingEnabled()) {
			joyEnableCyclicPolling(3278, "lv.c");
		}
#endif

		if (g_Vars.stagenum == STAGE_TITLE
				|| g_Vars.stagenum == STAGE_BOOTPAKMENU
				|| g_Vars.stagenum == STAGE_CREDITS
				|| g_Vars.stagenum == STAGE_4MBMENU) {
			g_Vars.paksconnected2 = 0;
		} else {
			g_Vars.paksconnected2 = 31;
			pakEnableRumbleForAllPlayers();
		}

		g_Vars.joydisableframestogo = -1;
	}

	if (IS4MB()) {
		vmPrintStatsIfEnabled();
	}

	for (j = 0; j < PLAYERCOUNT(); j++) {
		g_Vars.players[j]->hands[HAND_LEFT].unk0cec = 0;
		g_Vars.players[j]->hands[HAND_RIGHT].unk0cec = 0;
	}

	if (lvIsPaused()) {
		g_Vars.lvupdate240 = 0;
	} else if (mpIsPaused()) {
		g_Vars.lvupdate240 = 0;

		for (j = 0; j < PLAYERCOUNT(); j++) {
			g_Vars.players[j]->joybutinhibit = 0xefffefff;
		}
	} else {
		s32 slowmo = lvGetSlowMotionType();
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
	g_Vars.lvupdate240freal = PALUPF(g_Vars.lvupdate240f);

	bgunTickBoost();
	hudmsgsTick();

	if ((joyGetButtonsPressedThisFrame(0, 0xffff) != 0
				|| joyGetStickX(0) > 10
				|| joyGetStickX(0) < -10
				|| joyGetStickY(0) > 10
				|| joyGetStickY(0) < -10
				|| joyGetButtonsPressedThisFrame(1, 0xffff) != 0
				|| joyGetStickX(1) > 10
				|| joyGetStickX(1) < -10
				|| joyGetStickY(1) > 10
				|| joyGetStickY(1) < -10
				|| joyGetButtonsPressedThisFrame(2, 0xffff) != 0
				|| joyGetStickX(2) > 10
				|| joyGetStickX(2) < -10
				|| joyGetStickY(2) > 10
				|| joyGetStickY(2) < -10
				|| joyGetButtonsPressedThisFrame(3, 0xffff) != 0
				|| joyGetStickX(3) > 10
				|| joyGetStickX(3) < -10
				|| joyGetStickY(3) > 10
				|| joyGetStickY(3) < -10) && g_IsTitleDemo) {
		if (g_Vars.stagenum != STAGE_TITLE) {
			titleSetNextMode(TITLEMODE_SKIP);
			mainChangeToStage(STAGE_TITLE);
		}

		g_IsTitleDemo = false;
	}

	if (g_Vars.stagenum < STAGE_TITLE && !g_IsTitleDemo && !g_Vars.in_cutscene) {
		if (joyGetButtons(0, 0xffff) == 0
				&& joyGetStickX(0) < 10
				&& joyGetStickX(0) > -10
				&& joyGetStickY(0) < 10
				&& joyGetStickY(0) > -10
				&& joyGetButtons(1, 0xffff) == 0
				&& joyGetStickX(1) < 10
				&& joyGetStickX(1) > -10
				&& joyGetStickY(1) < 10
				&& joyGetStickY(1) > -10
				&& joyGetButtons(2, 0xffff) == 0
				&& joyGetStickX(2) < 10
				&& joyGetStickX(2) > -10
				&& joyGetStickY(2) < 10
				&& joyGetStickY(2) > -10
				&& joyGetButtons(3, 0xffff) == 0
				&& joyGetStickX(3) < 10
				&& joyGetStickX(3) > -10
				&& joyGetStickY(3) < 10
				&& joyGetStickY(3) > -10) {
			g_TitleIdleTime60 += g_Vars.diffframe60;
		} else {
			g_TitleIdleTime60 = 0;
		}
	} else {
		g_TitleIdleTime60 = 0;
	}

	g_NumReasonsToEndMpMatch = 0;

	// Handle MP match ending
	if (g_Vars.normmplayerisrunning && g_Vars.stagenum < STAGE_TITLE) {
		if (g_MpTimeLimit60 > 0) {
			s32 elapsed = g_StageTimeElapsed60;
			s32 nexttime = g_Vars.lvupdate240_60 + g_StageTimeElapsed60;
			s32 warntime = PALDOWN(g_MpTimeLimit60) - PALDOWN(3600);

			// Show HUD message at one minute remaining
			if (elapsed < warntime && nexttime >= warntime) {
				s32 i;

				for (i = 0; i < PLAYERCOUNT(); i++) {
					setCurrentPlayerNum(i);
					hudmsgCreate(langGet(L_MISC_068), HUDMSGTYPE_DEFAULT); // "One minute left."
				}
			}

			if (elapsed < PALDOWN(g_MpTimeLimit60) && nexttime >= PALDOWN(g_MpTimeLimit60)) {
				// Match is ending due to time limit reached
				mainEndStage();
			}

			// Sound alarm at 10 seconds remaining
			if (nexttime >= PALDOWN(g_MpTimeLimit60) - PALDOWN(600)
					&& g_MiscAudioHandle == NULL
					&& !lvIsPaused()
					&& nexttime < PALDOWN(g_MpTimeLimit60)) {
				snd00010718(&g_MiscAudioHandle, 0, 0x7fff, 0x40, 163, 1, 1, -1, 1);
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

			for (i = 0; i < g_MpNumChrs; i++) {
				if (g_MpAllChrPtrs[i]->actiontype == ACT_DIE) {
					numdying++;
				}
			}

			if (g_MpScoreLimit > 0) {
				struct ranking rankings[MAX_MPCHRS];
				s32 count = mpGetPlayerRankings(rankings);

				for (i = 0; i < count; i++) {
					if (rankings[i].score >= g_MpScoreLimit) {
						g_NumReasonsToEndMpMatch++;
					}
				}
			}

			if (g_MpTeamScoreLimit > 0) {
				struct ranking rankings[MAX_MPCHRS];
				s32 count = mpGetTeamRankings(rankings);

				for (i = 0; i < count; i++) {
					if (rankings[i].score >= g_MpTeamScoreLimit) {
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
	g_StageTimeElapsed1f = g_StageTimeElapsed60 / PALDOWN(60.0f);

	viSetUseZBuf(true);

	if (g_Vars.stagenum == STAGE_TEST_OLD) {
		titleTickOld();
		musicTick();
	}

	if (g_Vars.stagenum == STAGE_TITLE) {
		titleTick();
		func0f01d860();
		musicTick();
	} else if (g_Vars.stagenum == STAGE_BOOTPAKMENU) {
		setCurrentPlayerNum(0);
#if VERSION >= VERSION_PAL_FINAL
		playerConfigureVi();
#endif
		menuTick();
		musicTick();
		func0f01d860();
		pakExecuteDebugOperations();
	} else if (g_Vars.stagenum == STAGE_4MBMENU) {
		menuTick();
		musicTick();
		func0f01d860();
		pakExecuteDebugOperations();
	} else if (g_Vars.stagenum == STAGE_CREDITS) {
		musicTick();
		func0f01d860();
	} else {
		lvUpdateCutsceneTime();
		vtxstoreTick();
		lvUpdateSoloHandicaps();
		func0f01d8c0();
		func0f01d990();
		casingsTick();
		shardsTick();
		sparksTick();
		wallhitsTick();
		func0f149864();

		if (g_WeatherActive) {
			weatherTick();
		}

		if (g_NbombsActive) {
			nbombsTick();
		}

		lvUpdateMiscSfx();
		sndTick();
		pakExecuteDebugOperations();
		lightingTick();
		func0f0b2904();
		func0f0aefb8();
		amTick();
		menuTick();
		scenarioTick();

		if (!g_MainIsEndscreen) {
			propsTick2();
		}

		musicTick();
		func0f01d860();
		propsTickPadEffects();

		if (mainGetStageNum() == STAGE_CITRAINING) {
			struct trainingdata *trainingdata = dtGetData();

			if ((g_Vars.currentplayer->prop->rooms[0] < ROOM_DISH_HOLO1 || g_Vars.currentplayer->prop->rooms[0] > ROOM_DISH_HOLO4)
					&& g_Vars.currentplayer->prop->rooms[0] != ROOM_DISH_FIRINGRANGE
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

const char var7f1b7738[] = "cutsceneframe: %d\n";
const char var7f1b774c[] = "pos:%s%s %.2f %.2f %.2f\n";
const char var7f1b7768[] = "";
const char var7f1b776c[] = "";

void lvTickPlayer(void)
{
	f32 xdiff;
	f32 zdiff;

	if (var80075d64 == 2) {
		if (var80075d68 == 2) {
			playerTick(true);
		} else {
			playerTick(false);
		}
	}

	xdiff = g_Vars.currentplayer->prop->pos.x - g_Vars.currentplayer->bondprevpos.x;
	zdiff = g_Vars.currentplayer->prop->pos.z - g_Vars.currentplayer->bondprevpos.z;

	g_Vars.currentplayerstats->distance += sqrtf(xdiff * xdiff + zdiff * zdiff);
}

void lvReset(void)
{
	pakStopRumbleForAllPaks(true);

	if (g_MiscAudioHandle && sndGetState(g_MiscAudioHandle)) {
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
	objsReset(); // props/setup related
	weatherReset();
	objectivesAutocomplete();
	stub0f015260();
	func0f015470();
	func0f0150a0();
	musicReset();
	hudmsgsReset();

	if (g_Vars.stagenum < NUM_STAGES) {
		bgReset();
	}

	func00033dd8();

	if (g_FileState == FILESTATE_CHANGINGAGENT) {
		menuPlaySound(MENUSOUND_EXPLOSION);
		g_FileState = FILESTATE_UNSELECTED;
	}

#if VERSION >= VERSION_NTSC_1_0
	func0f01bea0();
#endif
}

void lvCheckPauseStateChanged(void)
{
	u32 paused = mpIsPaused();

	if (paused != var80084010) {
		if (paused) {
			pakDisableRumbleForAllPlayers();
		} else {
			pakEnableRumbleForAllPlayers();
		}
	}

	var80084010 = paused;
}

void lvSetPaused(bool paused)
{
	if (paused) {
		pakDisableRumbleForAllPlayers();
		snd0000fe20();
	} else {
		snd0000fe50();
		pakEnableRumbleForAllPlayers();
	}

	var80084014 = paused;
}

bool lvIsPaused(void)
{
	return var80084014;
}

s32 lvGetDifficulty(void)
{
	return g_Difficulty;
}

void lvSetDifficulty(s32 difficulty)
{
	if (difficulty < DIFF_A || difficulty > DIFF_PD) {
		difficulty = DIFF_A;
	}

	g_Difficulty = difficulty;
}

void lvSetMpTimeLimit60(u32 limit)
{
	g_MpTimeLimit60 = limit;
}

void lvSetMpScoreLimit(u32 limit)
{
	g_MpScoreLimit = limit;
}

void lvSetMpTeamScoreLimit(u32 limit)
{
	g_MpTeamScoreLimit = limit;
}

f32 lvGetStageTimeInSeconds(void)
{
	return g_StageTimeElapsed1f;
}

s32 lvGetStageTime60(void)
{
	return g_StageTimeElapsed60;
}

u32 func0f16ce04(u32 arg0)
{
	return arg0;
}
