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
#include "game/playerinit.h"
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
#include "game/gfxmemory.h"
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
#include "game/objectives.h"
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
#include "game/playermgr.h"
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
			bgunInit();
			playerLoadDefaults();
			playerInit();
			playerSpawn();
			currentPlayerInitAnimation();

			if (g_Vars.normmplayerisrunning && (g_MpSetup.options & MPOPTION_TEAMSENABLED)) {
				playermgrCalculateAiBuddyNums();
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
#if VERSION >= VERSION_PAL_BETA
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
			if (playermgrGetPlayerNumByProp(prop) == g_Vars.currentplayernum) {
				return false;
			}
			// fall through
		case PROPTYPE_CHR:
			chr = threat->prop->chr;

			if (chrIsDead(threat->prop->chr)) {
				if (index >= 0) {
					// Existing threat
					if (g_Vars.currentplayer->targetset[index] < TICKS(129)) {
						g_Vars.currentplayer->targetset[index] = TICKS(129);
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

#if VERSION == VERSION_NTSC_BETA || VERSION == VERSION_PAL_BETA
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
							&& playermgrGetPlayerNumByProp(prop) != g_Vars.currentplayernum)) {
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

#if VERSION >= VERSION_JPN_FINAL
u32 var800846d4jf[] = {0, 0, 0, 0x1e000000};
struct sndstate *g_CutsceneStaticAudioHandle = NULL;
s32 g_CutsceneStaticTimer = 100;
u8 g_CutsceneStaticActive = false;

GLOBAL_ASM(
glabel lvRender
.late_rodata
glabel var7f1b8770jf
.word 0x3f866666
.word 0x3ca3d70b
.word 0x3f8ccccd
.word 0x3bda740e
.word 0x3ca3d70b
.word 0x3f8ccccd
.word 0x3bda740e
.text
/*  f169784:	27bdfe90 */ 	addiu	$sp,$sp,-368
/*  f169788:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f16978c:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f169790:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f169794:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f169798:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f16979c:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f1697a0:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f1697a4:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f1697a8:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f1697ac:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f1697b0:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f1697b4:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f1697b8:	35ce0006 */ 	ori	$t6,$t6,0x6
/*  f1697bc:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1697c0:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f1697c4:	0fc35acf */ 	jal	func0f0d5a7c
/*  f1697c8:	24930008 */ 	addiu	$s3,$a0,0x8
/*  f1697cc:	3c12800a */ 	lui	$s2,0x800a
/*  f1697d0:	2652a630 */ 	addiu	$s2,$s2,-22992
/*  f1697d4:	8e4204b4 */ 	lw	$v0,0x4b4($s2)
/*  f1697d8:	2401005a */ 	li	$at,0x5a
/*  f1697dc:	10410006 */ 	beq	$v0,$at,.JF0f1697f8
/*  f1697e0:	2401004e */ 	li	$at,0x4e
/*  f1697e4:	5441005f */ 	bnel	$v0,$at,.JF0f169964
/*  f1697e8:	8e4204b4 */ 	lw	$v0,0x4b4($s2)
/*  f1697ec:	0fc06f4a */ 	jal	titleIsKeepingMode
/*  f1697f0:	00000000 */ 	nop
/*  f1697f4:	1040005a */ 	beqz	$v0,.JF0f169960
.JF0f1697f8:
/*  f1697f8:	02601025 */ 	move	$v0,$s3
/*  f1697fc:	3c188006 */ 	lui	$t8,0x8006
/*  f169800:	27181280 */ 	addiu	$t8,$t8,0x1280
/*  f169804:	3c0f0600 */ 	lui	$t7,0x600
/*  f169808:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f16980c:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f169810:	0fc47c8a */ 	jal	debugIsZBufferDisabled
/*  f169814:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f169818:	10400008 */ 	beqz	$v0,.JF0f16983c
/*  f16981c:	02601025 */ 	move	$v0,$s3
/*  f169820:	3c0a8006 */ 	lui	$t2,0x8006
/*  f169824:	254a1240 */ 	addiu	$t2,$t2,0x1240
/*  f169828:	3c190600 */ 	lui	$t9,0x600
/*  f16982c:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f169830:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f169834:	10000008 */ 	b	.JF0f169858
/*  f169838:	26730008 */ 	addiu	$s3,$s3,0x8
.JF0f16983c:
/*  f16983c:	02601025 */ 	move	$v0,$s3
/*  f169840:	3c0c8006 */ 	lui	$t4,0x8006
/*  f169844:	258c1260 */ 	addiu	$t4,$t4,0x1260
/*  f169848:	3c0b0600 */ 	lui	$t3,0x600
/*  f16984c:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f169850:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f169854:	26730008 */ 	addiu	$s3,$s3,0x8
.JF0f169858:
/*  f169858:	0c002c89 */ 	jal	vi0000b280
/*  f16985c:	02602025 */ 	move	$a0,$s3
/*  f169860:	0c002c5d */ 	jal	vi0000b1d0
/*  f169864:	00402025 */ 	move	$a0,$v0
/*  f169868:	00408825 */ 	move	$s1,$v0
/*  f16986c:	0c002f29 */ 	jal	viGetViewLeft
/*  f169870:	24530008 */ 	addiu	$s3,$v0,0x8
/*  f169874:	00028400 */ 	sll	$s0,$v0,0x10
/*  f169878:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f16987c:	0c002f2d */ 	jal	viGetViewTop
/*  f169880:	01a08025 */ 	move	$s0,$t5
/*  f169884:	44822000 */ 	mtc1	$v0,$f4
/*  f169888:	44908000 */ 	mtc1	$s0,$f16
/*  f16988c:	3c014080 */ 	lui	$at,0x4080
/*  f169890:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f169894:	4481a000 */ 	mtc1	$at,$f20
/*  f169898:	3c01ed00 */ 	lui	$at,0xed00
/*  f16989c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f1698a0:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f1698a4:	00000000 */ 	nop
/*  f1698a8:	46149102 */ 	mul.s	$f4,$f18,$f20
/*  f1698ac:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f1698b0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f1698b4:	440f5000 */ 	mfc1	$t7,$f10
/*  f1698b8:	440b3000 */ 	mfc1	$t3,$f6
/*  f1698bc:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f1698c0:	0301c825 */ 	or	$t9,$t8,$at
/*  f1698c4:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f1698c8:	000c6b00 */ 	sll	$t5,$t4,0xc
/*  f1698cc:	032d7025 */ 	or	$t6,$t9,$t5
/*  f1698d0:	0c002f0b */ 	jal	viGetViewWidth
/*  f1698d4:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f1698d8:	0c002f29 */ 	jal	viGetViewLeft
/*  f1698dc:	a7a2008e */ 	sh	$v0,0x8e($sp)
/*  f1698e0:	0c002f2d */ 	jal	viGetViewTop
/*  f1698e4:	a7a20090 */ 	sh	$v0,0x90($sp)
/*  f1698e8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1698ec:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f1698f0:	0c002f0f */ 	jal	viGetViewHeight
/*  f1698f4:	01e08025 */ 	move	$s0,$t7
/*  f1698f8:	87b80090 */ 	lh	$t8,0x90($sp)
/*  f1698fc:	87aa008e */ 	lh	$t2,0x8e($sp)
/*  f169900:	00507821 */ 	addu	$t7,$v0,$s0
/*  f169904:	448f2000 */ 	mtc1	$t7,$f4
/*  f169908:	030a5821 */ 	addu	$t3,$t8,$t2
/*  f16990c:	448b4000 */ 	mtc1	$t3,$f8
/*  f169910:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f169914:	02602025 */ 	move	$a0,$s3
/*  f169918:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f16991c:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f169920:	00000000 */ 	nop
/*  f169924:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f169928:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f16992c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f169930:	44199000 */ 	mfc1	$t9,$f18
/*  f169934:	440a5000 */ 	mfc1	$t2,$f10
/*  f169938:	332d0fff */ 	andi	$t5,$t9,0xfff
/*  f16993c:	000d7300 */ 	sll	$t6,$t5,0xc
/*  f169940:	314b0fff */ 	andi	$t3,$t2,0xfff
/*  f169944:	016e6025 */ 	or	$t4,$t3,$t6
/*  f169948:	0fc07020 */ 	jal	titleRender
/*  f16994c:	ae2c0004 */ 	sw	$t4,0x4($s1)
/*  f169950:	0fc5a27a */ 	jal	lvRenderFade
/*  f169954:	00402025 */ 	move	$a0,$v0
/*  f169958:	100005e0 */ 	b	.JF0f16b0dc
/*  f16995c:	00409825 */ 	move	$s3,$v0
.JF0f169960:
/*  f169960:	8e4204b4 */ 	lw	$v0,0x4b4($s2)
.JF0f169964:
/*  f169964:	2401005b */ 	li	$at,0x5b
/*  f169968:	24070002 */ 	li	$a3,0x2
/*  f16996c:	14410040 */ 	bne	$v0,$at,.JF0f169a70
/*  f169970:	3408fffe */ 	li	$t0,0xfffe
/*  f169974:	02601025 */ 	move	$v0,$s3
/*  f169978:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16997c:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f169980:	37390404 */ 	ori	$t9,$t9,0x404
/*  f169984:	02601825 */ 	move	$v1,$s3
/*  f169988:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16998c:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f169990:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f169994:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f169998:	35ad0c04 */ 	ori	$t5,$t5,0xc04
/*  f16999c:	02602025 */ 	move	$a0,$s3
/*  f1699a0:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f1699a4:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f1699a8:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f1699ac:	35ef1404 */ 	ori	$t7,$t7,0x1404
/*  f1699b0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1699b4:	02602825 */ 	move	$a1,$s3
/*  f1699b8:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f1699bc:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f1699c0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1699c4:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f1699c8:	37181c04 */ 	ori	$t8,$t8,0x1c04
/*  f1699cc:	02603025 */ 	move	$a2,$s3
/*  f1699d0:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1699d4:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f1699d8:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1699dc:	3c0a8006 */ 	lui	$t2,0x8006
/*  f1699e0:	3c090600 */ 	lui	$t1,0x600
/*  f1699e4:	254a1280 */ 	addiu	$t2,$t2,0x1280
/*  f1699e8:	02601025 */ 	move	$v0,$s3
/*  f1699ec:	3c0b8006 */ 	lui	$t3,0x8006
/*  f1699f0:	acca0004 */ 	sw	$t2,0x4($a2)
/*  f1699f4:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f1699f8:	256b1260 */ 	addiu	$t3,$t3,0x1260
/*  f1699fc:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f169a00:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f169a04:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f169a08:	0fc4a34d */ 	jal	setCurrentPlayerNum
/*  f169a0c:	00002025 */ 	move	$a0,$zero
/*  f169a10:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f169a14:	86040634 */ 	lh	$a0,0x634($s0)
/*  f169a18:	0c002f13 */ 	jal	viSetViewPosition
/*  f169a1c:	86050636 */ 	lh	$a1,0x636($s0)
/*  f169a20:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f169a24:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f169a28:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f169a2c:	86060630 */ 	lh	$a2,0x630($s0)
/*  f169a30:	0c002f5f */ 	jal	viSetFovAspectAndSize
/*  f169a34:	86070632 */ 	lh	$a3,0x632($s0)
/*  f169a38:	3c013f80 */ 	lui	$at,0x3f80
/*  f169a3c:	44816000 */ 	mtc1	$at,$f12
/*  f169a40:	0c0059ba */ 	jal	mtx00016748
/*  f169a44:	00000000 */ 	nop
/*  f169a48:	0c002c5d */ 	jal	vi0000b1d0
/*  f169a4c:	02602025 */ 	move	$a0,$s3
/*  f169a50:	0c002cb5 */ 	jal	viRenderViewportEdges
/*  f169a54:	00402025 */ 	move	$a0,$v0
/*  f169a58:	0fc573e1 */ 	jal	currentPlayerScissorToViewport
/*  f169a5c:	00402025 */ 	move	$a0,$v0
/*  f169a60:	0fc3f249 */ 	jal	menuRender
/*  f169a64:	00402025 */ 	move	$a0,$v0
/*  f169a68:	1000059c */ 	b	.JF0f16b0dc
/*  f169a6c:	00409825 */ 	move	$s3,$v0
.JF0f169a70:
/*  f169a70:	2401005d */ 	li	$at,0x5d
/*  f169a74:	14410063 */ 	bne	$v0,$at,.JF0f169c04
/*  f169a78:	24070002 */ 	li	$a3,0x2
/*  f169a7c:	02601025 */ 	move	$v0,$s3
/*  f169a80:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f169a84:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f169a88:	35ce0404 */ 	ori	$t6,$t6,0x404
/*  f169a8c:	02601825 */ 	move	$v1,$s3
/*  f169a90:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f169a94:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f169a98:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f169a9c:	3c0cbc00 */ 	lui	$t4,0xbc00
/*  f169aa0:	358c0c04 */ 	ori	$t4,$t4,0xc04
/*  f169aa4:	02602025 */ 	move	$a0,$s3
/*  f169aa8:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f169aac:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f169ab0:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f169ab4:	3408fffe */ 	li	$t0,0xfffe
/*  f169ab8:	37391404 */ 	ori	$t9,$t9,0x1404
/*  f169abc:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f169ac0:	02602825 */ 	move	$a1,$s3
/*  f169ac4:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f169ac8:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f169acc:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f169ad0:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f169ad4:	35ad1c04 */ 	ori	$t5,$t5,0x1c04
/*  f169ad8:	02603025 */ 	move	$a2,$s3
/*  f169adc:	acad0000 */ 	sw	$t5,0x0($a1)
/*  f169ae0:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f169ae4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f169ae8:	3c0f8006 */ 	lui	$t7,0x8006
/*  f169aec:	3c090600 */ 	lui	$t1,0x600
/*  f169af0:	25ef1280 */ 	addiu	$t7,$t7,0x1280
/*  f169af4:	02601025 */ 	move	$v0,$s3
/*  f169af8:	3c188006 */ 	lui	$t8,0x8006
/*  f169afc:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f169b00:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f169b04:	27181260 */ 	addiu	$t8,$t8,0x1260
/*  f169b08:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f169b0c:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f169b10:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f169b14:	0fc4a34d */ 	jal	setCurrentPlayerNum
/*  f169b18:	00002025 */ 	move	$a0,$zero
/*  f169b1c:	0c002a95 */ 	jal	viSetMode
/*  f169b20:	24040001 */ 	li	$a0,0x1
/*  f169b24:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f169b28:	86040634 */ 	lh	$a0,0x634($s0)
/*  f169b2c:	0c002f13 */ 	jal	viSetViewPosition
/*  f169b30:	86050636 */ 	lh	$a1,0x636($s0)
/*  f169b34:	0fc2f53a */ 	jal	playerGetFbWidth
/*  f169b38:	00000000 */ 	nop
/*  f169b3c:	0fc2f545 */ 	jal	playerGetFbHeight
/*  f169b40:	a7a20090 */ 	sh	$v0,0x90($sp)
/*  f169b44:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f169b48:	00055403 */ 	sra	$t2,$a1,0x10
/*  f169b4c:	01402825 */ 	move	$a1,$t2
/*  f169b50:	0c002ee2 */ 	jal	viSetSize
/*  f169b54:	87a40090 */ 	lh	$a0,0x90($sp)
/*  f169b58:	0fc2f53a */ 	jal	playerGetFbWidth
/*  f169b5c:	00000000 */ 	nop
/*  f169b60:	0fc2f545 */ 	jal	playerGetFbHeight
/*  f169b64:	a7a20090 */ 	sh	$v0,0x90($sp)
/*  f169b68:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f169b6c:	00055c03 */ 	sra	$t3,$a1,0x10
/*  f169b70:	01602825 */ 	move	$a1,$t3
/*  f169b74:	0c002ed1 */ 	jal	viSetBufSize
/*  f169b78:	87a40090 */ 	lh	$a0,0x90($sp)
/*  f169b7c:	0fc2f53a */ 	jal	playerGetFbWidth
/*  f169b80:	00000000 */ 	nop
/*  f169b84:	0fc2f545 */ 	jal	playerGetFbHeight
/*  f169b88:	a7a20090 */ 	sh	$v0,0x90($sp)
/*  f169b8c:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f169b90:	00057403 */ 	sra	$t6,$a1,0x10
/*  f169b94:	01c02825 */ 	move	$a1,$t6
/*  f169b98:	0c002ef3 */ 	jal	viSetViewSize
/*  f169b9c:	87a40090 */ 	lh	$a0,0x90($sp)
/*  f169ba0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f169ba4:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f169ba8:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f169bac:	86060630 */ 	lh	$a2,0x630($s0)
/*  f169bb0:	0c002f5f */ 	jal	viSetFovAspectAndSize
/*  f169bb4:	86070632 */ 	lh	$a3,0x632($s0)
/*  f169bb8:	3c013f80 */ 	lui	$at,0x3f80
/*  f169bbc:	44816000 */ 	mtc1	$at,$f12
/*  f169bc0:	0c0059ba */ 	jal	mtx00016748
/*  f169bc4:	00000000 */ 	nop
/*  f169bc8:	0c002c5d */ 	jal	vi0000b1d0
/*  f169bcc:	02602025 */ 	move	$a0,$s3
/*  f169bd0:	0fc573e1 */ 	jal	currentPlayerScissorToViewport
/*  f169bd4:	00402025 */ 	move	$a0,$v0
/*  f169bd8:	0fc3f249 */ 	jal	menuRender
/*  f169bdc:	00402025 */ 	move	$a0,$v0
/*  f169be0:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f169be4:	00409825 */ 	move	$s3,$v0
/*  f169be8:	8d991a24 */ 	lw	$t9,0x1a24($t4)
/*  f169bec:	5320053c */ 	beqzl	$t9,.JF0f16b0e0
/*  f169bf0:	824d04d3 */ 	lb	$t5,0x4d3($s2)
/*  f169bf4:	0fc2ef7b */ 	jal	playerTickPauseMenu
/*  f169bf8:	00000000 */ 	nop
/*  f169bfc:	10000538 */ 	b	.JF0f16b0e0
/*  f169c00:	824d04d3 */ 	lb	$t5,0x4d3($s2)
.JF0f169c04:
/*  f169c04:	2401005c */ 	li	$at,0x5c
/*  f169c08:	14410041 */ 	bne	$v0,$at,.JF0f169d10
/*  f169c0c:	24070002 */ 	li	$a3,0x2
/*  f169c10:	02601025 */ 	move	$v0,$s3
/*  f169c14:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f169c18:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f169c1c:	35ad0404 */ 	ori	$t5,$t5,0x404
/*  f169c20:	02601825 */ 	move	$v1,$s3
/*  f169c24:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f169c28:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f169c2c:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f169c30:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f169c34:	35ef0c04 */ 	ori	$t7,$t7,0xc04
/*  f169c38:	02602025 */ 	move	$a0,$s3
/*  f169c3c:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f169c40:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f169c44:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f169c48:	3408fffe */ 	li	$t0,0xfffe
/*  f169c4c:	37181404 */ 	ori	$t8,$t8,0x1404
/*  f169c50:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f169c54:	02602825 */ 	move	$a1,$s3
/*  f169c58:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f169c5c:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f169c60:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f169c64:	3c0abc00 */ 	lui	$t2,0xbc00
/*  f169c68:	354a1c04 */ 	ori	$t2,$t2,0x1c04
/*  f169c6c:	02603025 */ 	move	$a2,$s3
/*  f169c70:	acaa0000 */ 	sw	$t2,0x0($a1)
/*  f169c74:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f169c78:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f169c7c:	3c0b8006 */ 	lui	$t3,0x8006
/*  f169c80:	3c090600 */ 	lui	$t1,0x600
/*  f169c84:	256b1280 */ 	addiu	$t3,$t3,0x1280
/*  f169c88:	02601025 */ 	move	$v0,$s3
/*  f169c8c:	3c0e8006 */ 	lui	$t6,0x8006
/*  f169c90:	accb0004 */ 	sw	$t3,0x4($a2)
/*  f169c94:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f169c98:	25ce1260 */ 	addiu	$t6,$t6,0x1260
/*  f169c9c:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f169ca0:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f169ca4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f169ca8:	0fc4a34d */ 	jal	setCurrentPlayerNum
/*  f169cac:	00002025 */ 	move	$a0,$zero
/*  f169cb0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f169cb4:	86040634 */ 	lh	$a0,0x634($s0)
/*  f169cb8:	0c002f13 */ 	jal	viSetViewPosition
/*  f169cbc:	86050636 */ 	lh	$a1,0x636($s0)
/*  f169cc0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f169cc4:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f169cc8:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f169ccc:	86060630 */ 	lh	$a2,0x630($s0)
/*  f169cd0:	0c002f5f */ 	jal	viSetFovAspectAndSize
/*  f169cd4:	86070632 */ 	lh	$a3,0x632($s0)
/*  f169cd8:	3c013f80 */ 	lui	$at,0x3f80
/*  f169cdc:	44816000 */ 	mtc1	$at,$f12
/*  f169ce0:	0c0059ba */ 	jal	mtx00016748
/*  f169ce4:	00000000 */ 	nop
/*  f169ce8:	0c002c53 */ 	jal	vi0000b1a8
/*  f169cec:	02602025 */ 	move	$a0,$s3
/*  f169cf0:	0c002c5d */ 	jal	vi0000b1d0
/*  f169cf4:	00402025 */ 	move	$a0,$v0
/*  f169cf8:	0c002cb5 */ 	jal	viRenderViewportEdges
/*  f169cfc:	00402025 */ 	move	$a0,$v0
/*  f169d00:	0fc4ed14 */ 	jal	creditsRender
/*  f169d04:	00402025 */ 	move	$a0,$v0
/*  f169d08:	100004f4 */ 	b	.JF0f16b0dc
/*  f169d0c:	00409825 */ 	move	$s3,$v0
.JF0f169d10:
/*  f169d10:	8e500298 */ 	lw	$s0,0x298($s2)
/*  f169d14:	06010006 */ 	bgez	$s0,.JF0f169d30
/*  f169d18:	00000000 */ 	nop
/*  f169d1c:	8e50029c */ 	lw	$s0,0x29c($s2)
/*  f169d20:	2a190000 */ 	slti	$t9,$s0,0x0
/*  f169d24:	3b300001 */ 	xori	$s0,$t9,0x1
/*  f169d28:	12000004 */ 	beqz	$s0,.JF0f169d3c
/*  f169d2c:	00000000 */ 	nop
.JF0f169d30:
/*  f169d30:	0fc2f557 */ 	jal	playerHasSharedViewport
/*  f169d34:	00000000 */ 	nop
/*  f169d38:	0002802b */ 	sltu	$s0,$zero,$v0
.JF0f169d3c:
/*  f169d3c:	12000004 */ 	beqz	$s0,.JF0f169d50
/*  f169d40:	afb00104 */ 	sw	$s0,0x104($sp)
/*  f169d44:	240d0001 */ 	li	$t5,0x1
/*  f169d48:	1000001c */ 	b	.JF0f169dbc
/*  f169d4c:	afad010c */ 	sw	$t5,0x10c($sp)
.JF0f169d50:
/*  f169d50:	8e4f006c */ 	lw	$t7,0x6c($s2)
/*  f169d54:	00002025 */ 	move	$a0,$zero
/*  f169d58:	00001825 */ 	move	$v1,$zero
/*  f169d5c:	11e00003 */ 	beqz	$t7,.JF0f169d6c
/*  f169d60:	00001025 */ 	move	$v0,$zero
/*  f169d64:	10000001 */ 	b	.JF0f169d6c
/*  f169d68:	24040001 */ 	li	$a0,0x1
.JF0f169d6c:
/*  f169d6c:	8e580068 */ 	lw	$t8,0x68($s2)
/*  f169d70:	00008025 */ 	move	$s0,$zero
/*  f169d74:	13000003 */ 	beqz	$t8,.JF0f169d84
/*  f169d78:	00000000 */ 	nop
/*  f169d7c:	10000001 */ 	b	.JF0f169d84
/*  f169d80:	24030001 */ 	li	$v1,0x1
.JF0f169d84:
/*  f169d84:	8e4a0064 */ 	lw	$t2,0x64($s2)
/*  f169d88:	11400003 */ 	beqz	$t2,.JF0f169d98
/*  f169d8c:	00000000 */ 	nop
/*  f169d90:	10000001 */ 	b	.JF0f169d98
/*  f169d94:	24020001 */ 	li	$v0,0x1
.JF0f169d98:
/*  f169d98:	8e4b0070 */ 	lw	$t3,0x70($s2)
/*  f169d9c:	11600003 */ 	beqz	$t3,.JF0f169dac
/*  f169da0:	00000000 */ 	nop
/*  f169da4:	10000001 */ 	b	.JF0f169dac
/*  f169da8:	24100001 */ 	li	$s0,0x1
.JF0f169dac:
/*  f169dac:	02027021 */ 	addu	$t6,$s0,$v0
/*  f169db0:	01c36021 */ 	addu	$t4,$t6,$v1
/*  f169db4:	0184c821 */ 	addu	$t9,$t4,$a0
/*  f169db8:	afb9010c */ 	sw	$t9,0x10c($sp)
.JF0f169dbc:
/*  f169dbc:	02601025 */ 	move	$v0,$s3
/*  f169dc0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f169dc4:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f169dc8:	24070002 */ 	li	$a3,0x2
/*  f169dcc:	35ad0404 */ 	ori	$t5,$t5,0x404
/*  f169dd0:	02601825 */ 	move	$v1,$s3
/*  f169dd4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f169dd8:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f169ddc:	ac470004 */ 	sw	$a3,0x4($v0)
/*  f169de0:	3c0fbc00 */ 	lui	$t7,0xbc00
/*  f169de4:	35ef0c04 */ 	ori	$t7,$t7,0xc04
/*  f169de8:	02602025 */ 	move	$a0,$s3
/*  f169dec:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f169df0:	ac670004 */ 	sw	$a3,0x4($v1)
/*  f169df4:	3c18bc00 */ 	lui	$t8,0xbc00
/*  f169df8:	3408fffe */ 	li	$t0,0xfffe
/*  f169dfc:	37181404 */ 	ori	$t8,$t8,0x1404
/*  f169e00:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f169e04:	02602825 */ 	move	$a1,$s3
/*  f169e08:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f169e0c:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f169e10:	3c0abc00 */ 	lui	$t2,0xbc00
/*  f169e14:	354a1c04 */ 	ori	$t2,$t2,0x1c04
/*  f169e18:	acaa0000 */ 	sw	$t2,0x0($a1)
/*  f169e1c:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f169e20:	8fab010c */ 	lw	$t3,0x10c($sp)
/*  f169e24:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f169e28:	00008025 */ 	move	$s0,$zero
/*  f169e2c:	196004ab */ 	blez	$t3,.JF0f16b0dc
/*  f169e30:	3c0e8006 */ 	lui	$t6,0x8006
/*  f169e34:	3c01bf80 */ 	lui	$at,0xbf80
/*  f169e38:	25ce1280 */ 	addiu	$t6,$t6,0x1280
/*  f169e3c:	4481a000 */ 	mtc1	$at,$f20
/*  f169e40:	afae006c */ 	sw	$t6,0x6c($sp)
/*  f169e44:	241e0001 */ 	li	$s8,0x1
/*  f169e48:	2417ffff */ 	li	$s7,-1
/*  f169e4c:	2416fffe */ 	li	$s6,-2
/*  f169e50:	24150004 */ 	li	$s5,0x4
/*  f169e54:	8fac0104 */ 	lw	$t4,0x104($sp)
.JF0f169e58:
/*  f169e58:	0000a025 */ 	move	$s4,$zero
/*  f169e5c:	afb30108 */ 	sw	$s3,0x108($sp)
/*  f169e60:	11800007 */ 	beqz	$t4,.JF0f169e80
/*  f169e64:	00002025 */ 	move	$a0,$zero
/*  f169e68:	0fc4a34d */ 	jal	setCurrentPlayerNum
/*  f169e6c:	24110001 */ 	li	$s1,0x1
/*  f169e70:	26190001 */ 	addiu	$t9,$s0,0x1
/*  f169e74:	ae400290 */ 	sw	$zero,0x290($s2)
/*  f169e78:	1000000a */ 	b	.JF0f169ea4
/*  f169e7c:	afb90064 */ 	sw	$t9,0x64($sp)
.JF0f169e80:
/*  f169e80:	0fc4a4b4 */ 	jal	playermgrGetPlayerAtOrder
/*  f169e84:	02002025 */ 	move	$a0,$s0
/*  f169e88:	0fc4a34d */ 	jal	setCurrentPlayerNum
/*  f169e8c:	00402025 */ 	move	$a0,$v0
/*  f169e90:	8fad010c */ 	lw	$t5,0x10c($sp)
/*  f169e94:	26020001 */ 	addiu	$v0,$s0,0x1
/*  f169e98:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f169e9c:	01a28826 */ 	xor	$s1,$t5,$v0
/*  f169ea0:	2e310001 */ 	sltiu	$s1,$s1,0x1
.JF0f169ea4:
/*  f169ea4:	8e4f02ac */ 	lw	$t7,0x2ac($s2)
/*  f169ea8:	24010006 */ 	li	$at,0x6
/*  f169eac:	11e10029 */ 	beq	$t7,$at,.JF0f169f54
/*  f169eb0:	00000000 */ 	nop
/*  f169eb4:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f169eb8:	8e1800bc */ 	lw	$t8,0xbc($s0)
/*  f169ebc:	8f020004 */ 	lw	$v0,0x4($t8)
/*  f169ec0:	844402d8 */ 	lh	$a0,0x2d8($v0)
/*  f169ec4:	18800023 */ 	blez	$a0,.JF0f169f54
/*  f169ec8:	00000000 */ 	nop
/*  f169ecc:	920a1922 */ 	lbu	$t2,0x1922($s0)
/*  f169ed0:	15400020 */ 	bnez	$t2,.JF0f169f54
/*  f169ed4:	00000000 */ 	nop
/*  f169ed8:	8e0b1c08 */ 	lw	$t3,0x1c08($s0)
/*  f169edc:	24011388 */ 	li	$at,0x1388
/*  f169ee0:	1560001c */ 	bnez	$t3,.JF0f169f54
/*  f169ee4:	00000000 */ 	nop
/*  f169ee8:	0004a180 */ 	sll	$s4,$a0,0x6
/*  f169eec:	0284a021 */ 	addu	$s4,$s4,$a0
/*  f169ef0:	0014a040 */ 	sll	$s4,$s4,0x1
/*  f169ef4:	0281001a */ 	div	$zero,$s4,$at
/*  f169ef8:	00007012 */ 	mflo	$t6
/*  f169efc:	25d40064 */ 	addiu	$s4,$t6,0x64
/*  f169f00:	2e8100e7 */ 	sltiu	$at,$s4,0xe7
/*  f169f04:	14200002 */ 	bnez	$at,.JF0f169f10
/*  f169f08:	240c1388 */ 	li	$t4,0x1388
/*  f169f0c:	241400e6 */ 	li	$s4,0xe6
.JF0f169f10:
/*  f169f10:	28811389 */ 	slti	$at,$a0,0x1389
/*  f169f14:	54200004 */ 	bnezl	$at,.JF0f169f28
/*  f169f18:	904d02ff */ 	lbu	$t5,0x2ff($v0)
/*  f169f1c:	a44c02d8 */ 	sh	$t4,0x2d8($v0)
/*  f169f20:	844402d8 */ 	lh	$a0,0x2d8($v0)
/*  f169f24:	904d02ff */ 	lbu	$t5,0x2ff($v0)
.JF0f169f28:
/*  f169f28:	8e590038 */ 	lw	$t9,0x38($s2)
/*  f169f2c:	25af0001 */ 	addiu	$t7,$t5,0x1
/*  f169f30:	032f0019 */ 	multu	$t9,$t7
/*  f169f34:	0000c012 */ 	mflo	$t8
/*  f169f38:	00985023 */ 	subu	$t2,$a0,$t8
/*  f169f3c:	a44a02d8 */ 	sh	$t2,0x2d8($v0)
/*  f169f40:	844b02d8 */ 	lh	$t3,0x2d8($v0)
/*  f169f44:	1d600003 */ 	bgtz	$t3,.JF0f169f54
/*  f169f48:	00000000 */ 	nop
/*  f169f4c:	a44002d8 */ 	sh	$zero,0x2d8($v0)
/*  f169f50:	a04002ff */ 	sb	$zero,0x2ff($v0)
.JF0f169f54:
/*  f169f54:	0fc523ca */ 	jal	bviewSetBlur
/*  f169f58:	02802025 */ 	move	$a0,$s4
/*  f169f5c:	02601025 */ 	move	$v0,$s3
/*  f169f60:	3c0e0600 */ 	lui	$t6,0x600
/*  f169f64:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f169f68:	8fac006c */ 	lw	$t4,0x6c($sp)
/*  f169f6c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f169f70:	0fc47c8a */ 	jal	debugIsZBufferDisabled
/*  f169f74:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f169f78:	10400009 */ 	beqz	$v0,.JF0f169fa0
/*  f169f7c:	3c0f0600 */ 	lui	$t7,0x600
/*  f169f80:	02601025 */ 	move	$v0,$s3
/*  f169f84:	3c198006 */ 	lui	$t9,0x8006
/*  f169f88:	27391240 */ 	addiu	$t9,$t9,0x1240
/*  f169f8c:	3c0d0600 */ 	lui	$t5,0x600
/*  f169f90:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f169f94:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f169f98:	10000007 */ 	b	.JF0f169fb8
/*  f169f9c:	26730008 */ 	addiu	$s3,$s3,0x8
.JF0f169fa0:
/*  f169fa0:	02601025 */ 	move	$v0,$s3
/*  f169fa4:	3c188006 */ 	lui	$t8,0x8006
/*  f169fa8:	27181260 */ 	addiu	$t8,$t8,0x1260
/*  f169fac:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f169fb0:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f169fb4:	26730008 */ 	addiu	$s3,$s3,0x8
.JF0f169fb8:
/*  f169fb8:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f169fbc:	86040634 */ 	lh	$a0,0x634($s0)
/*  f169fc0:	0c002f13 */ 	jal	viSetViewPosition
/*  f169fc4:	86050636 */ 	lh	$a1,0x636($s0)
/*  f169fc8:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f169fcc:	c60c1854 */ 	lwc1	$f12,0x1854($s0)
/*  f169fd0:	c60e1858 */ 	lwc1	$f14,0x1858($s0)
/*  f169fd4:	86060630 */ 	lh	$a2,0x630($s0)
/*  f169fd8:	0c002f5f */ 	jal	viSetFovAspectAndSize
/*  f169fdc:	86070632 */ 	lh	$a3,0x632($s0)
/*  f169fe0:	8e4a0288 */ 	lw	$t2,0x288($s2)
/*  f169fe4:	0c0059ba */ 	jal	mtx00016748
/*  f169fe8:	c54c0074 */ 	lwc1	$f12,0x74($t2)
/*  f169fec:	0fc59702 */ 	jal	env0f1657f8
/*  f169ff0:	00000000 */ 	nop
/*  f169ff4:	0fc5d9ba */ 	jal	func0f176298
/*  f169ff8:	00000000 */ 	nop
/*  f169ffc:	0c002c89 */ 	jal	vi0000b280
/*  f16a000:	02602025 */ 	move	$a0,$s3
/*  f16a004:	0c002c5d */ 	jal	vi0000b1d0
/*  f16a008:	00402025 */ 	move	$a0,$v0
/*  f16a00c:	0fc573e1 */ 	jal	currentPlayerScissorToViewport
/*  f16a010:	00402025 */ 	move	$a0,$v0
/*  f16a014:	0fc4f244 */ 	jal	func0f13c510
/*  f16a018:	00409825 */ 	move	$s3,$v0
/*  f16a01c:	8e4b04b4 */ 	lw	$t3,0x4b4($s2)
/*  f16a020:	24010026 */ 	li	$at,0x26
/*  f16a024:	3c0e8008 */ 	lui	$t6,0x8008
/*  f16a028:	5561000a */ 	bnel	$t3,$at,.JF0f16a054
/*  f16a02c:	8e4d000c */ 	lw	$t5,0xc($s2)
/*  f16a030:	8dce78e0 */ 	lw	$t6,0x78e0($t6)
/*  f16a034:	3c0c800a */ 	lui	$t4,0x800a
/*  f16a038:	5dc0001a */ 	bgtzl	$t6,.JF0f16a0a4
/*  f16a03c:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a040:	8d8c20c4 */ 	lw	$t4,0x20c4($t4)
/*  f16a044:	24010003 */ 	li	$at,0x3
/*  f16a048:	51810016 */ 	beql	$t4,$at,.JF0f16a0a4
/*  f16a04c:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a050:	8e4d000c */ 	lw	$t5,0xc($s2)
.JF0f16a054:
/*  f16a054:	29a10006 */ 	slti	$at,$t5,0x6
/*  f16a058:	50200012 */ 	beqzl	$at,.JF0f16a0a4
/*  f16a05c:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a060:	8e590318 */ 	lw	$t9,0x318($s2)
/*  f16a064:	5720000f */ 	bnezl	$t9,.JF0f16a0a4
/*  f16a068:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a06c:	8e4f02ac */ 	lw	$t7,0x2ac($s2)
/*  f16a070:	24010006 */ 	li	$at,0x6
/*  f16a074:	3c028008 */ 	lui	$v0,0x8008
/*  f16a078:	51e1000a */ 	beql	$t7,$at,.JF0f16a0a4
/*  f16a07c:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a080:	8c4246a0 */ 	lw	$v0,0x46a0($v0)
/*  f16a084:	28410006 */ 	slti	$at,$v0,0x6
/*  f16a088:	10200002 */ 	beqz	$at,.JF0f16a094
/*  f16a08c:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f16a090:	ae5e0320 */ 	sw	$s8,0x320($s2)
.JF0f16a094:
/*  f16a094:	3c018008 */ 	lui	$at,0x8008
/*  f16a098:	1000001d */ 	b	.JF0f16a110
/*  f16a09c:	ac3846a0 */ 	sw	$t8,0x46a0($at)
/*  f16a0a0:	8e500284 */ 	lw	$s0,0x284($s2)
.JF0f16a0a4:
/*  f16a0a4:	3c0c8007 */ 	lui	$t4,0x8007
/*  f16a0a8:	8e0a1580 */ 	lw	$t2,0x1580($s0)
/*  f16a0ac:	000a7780 */ 	sll	$t6,$t2,0x1e
/*  f16a0b0:	05c30018 */ 	bgezl	$t6,.JF0f16a114
/*  f16a0b4:	8e4c0320 */ 	lw	$t4,0x320($s2)
/*  f16a0b8:	8d8c6350 */ 	lw	$t4,0x6350($t4)
/*  f16a0bc:	24010002 */ 	li	$at,0x2
/*  f16a0c0:	55810014 */ 	bnel	$t4,$at,.JF0f16a114
/*  f16a0c4:	8e4c0320 */ 	lw	$t4,0x320($s2)
/*  f16a0c8:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f16a0cc:	24010002 */ 	li	$at,0x2
/*  f16a0d0:	53c20010 */ 	beql	$s8,$v0,.JF0f16a114
/*  f16a0d4:	8e4c0320 */ 	lw	$t4,0x320($s2)
/*  f16a0d8:	1041000d */ 	beq	$v0,$at,.JF0f16a110
/*  f16a0dc:	3c0d800a */ 	lui	$t5,0x800a
/*  f16a0e0:	8dade6c0 */ 	lw	$t5,-0x1940($t5)
/*  f16a0e4:	55a0000b */ 	bnezl	$t5,.JF0f16a114
/*  f16a0e8:	8e4c0320 */ 	lw	$t4,0x320($s2)
/*  f16a0ec:	0fc27e82 */ 	jal	bgun0f09eae4
/*  f16a0f0:	00000000 */ 	nop
/*  f16a0f4:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a0f8:	00027840 */ 	sll	$t7,$v0,0x1
/*  f16a0fc:	31f80002 */ 	andi	$t8,$t7,0x2
/*  f16a100:	920a1583 */ 	lbu	$t2,0x1583($s0)
/*  f16a104:	314bfffd */ 	andi	$t3,$t2,0xfffd
/*  f16a108:	030b7025 */ 	or	$t6,$t8,$t3
/*  f16a10c:	a20e1583 */ 	sb	$t6,0x1583($s0)
.JF0f16a110:
/*  f16a110:	8e4c0320 */ 	lw	$t4,0x320($s2)
.JF0f16a114:
/*  f16a114:	02602025 */ 	move	$a0,$s3
/*  f16a118:	2405ffff */ 	li	$a1,-1
/*  f16a11c:	11800008 */ 	beqz	$t4,.JF0f16a140
/*  f16a120:	3c0f800a */ 	lui	$t7,0x800a
/*  f16a124:	0fc50a0e */ 	jal	bviewRenderMotionBlur
/*  f16a128:	240600ff */ 	li	$a2,0xff
/*  f16a12c:	8e4d0320 */ 	lw	$t5,0x320($s2)
/*  f16a130:	00409825 */ 	move	$s3,$v0
/*  f16a134:	25b9ffff */ 	addiu	$t9,$t5,-1
/*  f16a138:	100003d4 */ 	b	.JF0f16b08c
/*  f16a13c:	ae590320 */ 	sw	$t9,0x320($s2)
.JF0f16a140:
/*  f16a140:	8defe6c0 */ 	lw	$t7,-0x1940($t7)
/*  f16a144:	3c0e8007 */ 	lui	$t6,0x8007
/*  f16a148:	11e00012 */ 	beqz	$t7,.JF0f16a194
/*  f16a14c:	00000000 */ 	nop
/*  f16a150:	0c002cb5 */ 	jal	viRenderViewportEdges
/*  f16a154:	02602025 */ 	move	$a0,$s3
/*  f16a158:	0fc573e1 */ 	jal	currentPlayerScissorToViewport
/*  f16a15c:	00402025 */ 	move	$a0,$v0
/*  f16a160:	3c013f80 */ 	lui	$at,0x3f80
/*  f16a164:	44816000 */ 	mtc1	$at,$f12
/*  f16a168:	0c0059ba */ 	jal	mtx00016748
/*  f16a16c:	00409825 */ 	move	$s3,$v0
/*  f16a170:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f16a174:	8d581c50 */ 	lw	$t8,0x1c50($t2)
/*  f16a178:	00185fc2 */ 	srl	$t3,$t8,0x1f
/*  f16a17c:	116003c3 */ 	beqz	$t3,.JF0f16b08c
/*  f16a180:	00000000 */ 	nop
/*  f16a184:	0fc3f249 */ 	jal	menuRender
/*  f16a188:	02602025 */ 	move	$a0,$s3
/*  f16a18c:	100003bf */ 	b	.JF0f16b08c
/*  f16a190:	00409825 */ 	move	$s3,$v0
.JF0f16a194:
/*  f16a194:	8dce6350 */ 	lw	$t6,0x6350($t6)
/*  f16a198:	24010002 */ 	li	$at,0x2
/*  f16a19c:	15c10004 */ 	bne	$t6,$at,.JF0f16a1b0
/*  f16a1a0:	00000000 */ 	nop
/*  f16a1a4:	0fc30421 */ 	jal	playerUpdateShootRot
/*  f16a1a8:	02602025 */ 	move	$a0,$s3
/*  f16a1ac:	00409825 */ 	move	$s3,$v0
.JF0f16a1b0:
/*  f16a1b0:	0c002cb5 */ 	jal	viRenderViewportEdges
/*  f16a1b4:	02602025 */ 	move	$a0,$s3
/*  f16a1b8:	0fc47f61 */ 	jal	func0f11f984
/*  f16a1bc:	00402025 */ 	move	$a0,$v0
/*  f16a1c0:	0fc57384 */ 	jal	bgTick
/*  f16a1c4:	00409825 */ 	move	$s3,$v0
/*  f16a1c8:	0fc010e9 */ 	jal	func0f004314
/*  f16a1cc:	00000000 */ 	nop
/*  f16a1d0:	0fc19053 */ 	jal	propsTick
/*  f16a1d4:	02202025 */ 	move	$a0,$s1
/*  f16a1d8:	0fc61780 */ 	jal	scenarioTickChr
/*  f16a1dc:	00002025 */ 	move	$a0,$zero
/*  f16a1e0:	0fc184b4 */ 	jal	propsSort
/*  f16a1e4:	00000000 */ 	nop
/*  f16a1e8:	0fc19782 */ 	jal	autoaimTick
/*  f16a1ec:	00000000 */ 	nop
/*  f16a1f0:	0fc18f13 */ 	jal	handsTickAttack
/*  f16a1f4:	00000000 */ 	nop
/*  f16a1f8:	8e4c006c */ 	lw	$t4,0x6c($s2)
/*  f16a1fc:	00002025 */ 	move	$a0,$zero
/*  f16a200:	00001825 */ 	move	$v1,$zero
/*  f16a204:	11800003 */ 	beqz	$t4,.JF0f16a214
/*  f16a208:	00001025 */ 	move	$v0,$zero
/*  f16a20c:	10000001 */ 	b	.JF0f16a214
/*  f16a210:	03c02025 */ 	move	$a0,$s8
.JF0f16a214:
/*  f16a214:	8e4d0068 */ 	lw	$t5,0x68($s2)
/*  f16a218:	00008025 */ 	move	$s0,$zero
/*  f16a21c:	11a00003 */ 	beqz	$t5,.JF0f16a22c
/*  f16a220:	00000000 */ 	nop
/*  f16a224:	10000001 */ 	b	.JF0f16a22c
/*  f16a228:	03c01825 */ 	move	$v1,$s8
.JF0f16a22c:
/*  f16a22c:	8e590064 */ 	lw	$t9,0x64($s2)
/*  f16a230:	13200003 */ 	beqz	$t9,.JF0f16a240
/*  f16a234:	00000000 */ 	nop
/*  f16a238:	10000001 */ 	b	.JF0f16a240
/*  f16a23c:	03c01025 */ 	move	$v0,$s8
.JF0f16a240:
/*  f16a240:	8e4f0070 */ 	lw	$t7,0x70($s2)
/*  f16a244:	11e00003 */ 	beqz	$t7,.JF0f16a254
/*  f16a248:	00000000 */ 	nop
/*  f16a24c:	10000001 */ 	b	.JF0f16a254
/*  f16a250:	03c08025 */ 	move	$s0,$s8
.JF0f16a254:
/*  f16a254:	02025021 */ 	addu	$t2,$s0,$v0
/*  f16a258:	0143c021 */ 	addu	$t8,$t2,$v1
/*  f16a25c:	03045821 */ 	addu	$t3,$t8,$a0
/*  f16a260:	53cb0012 */ 	beql	$s8,$t3,.JF0f16a2ac
/*  f16a264:	00002025 */ 	move	$a0,$zero
/*  f16a268:	8e4e0298 */ 	lw	$t6,0x298($s2)
/*  f16a26c:	05c3000f */ 	bgezl	$t6,.JF0f16a2ac
/*  f16a270:	00002025 */ 	move	$a0,$zero
/*  f16a274:	8e4c029c */ 	lw	$t4,0x29c($s2)
/*  f16a278:	0583000c */ 	bgezl	$t4,.JF0f16a2ac
/*  f16a27c:	00002025 */ 	move	$a0,$zero
/*  f16a280:	0fc28a44 */ 	jal	bgunGetWeaponNum
/*  f16a284:	00002025 */ 	move	$a0,$zero
/*  f16a288:	00402025 */ 	move	$a0,$v0
/*  f16a28c:	0fc2ca10 */ 	jal	weaponHasFlag
/*  f16a290:	3c054000 */ 	lui	$a1,0x4000
/*  f16a294:	50400050 */ 	beqzl	$v0,.JF0f16a3d8
/*  f16a298:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f16a29c:	0fc322ec */ 	jal	bmoveIsInSightAimMode
/*  f16a2a0:	00000000 */ 	nop
/*  f16a2a4:	1040004b */ 	beqz	$v0,.JF0f16a3d4
/*  f16a2a8:	00002025 */ 	move	$a0,$zero
.JF0f16a2ac:
/*  f16a2ac:	00002825 */ 	move	$a1,$zero
/*  f16a2b0:	0fc18b9d */ 	jal	func0f061d54
/*  f16a2b4:	00003025 */ 	move	$a2,$zero
/*  f16a2b8:	8e4d0284 */ 	lw	$t5,0x284($s2)
/*  f16a2bc:	ada21624 */ 	sw	$v0,0x1624($t5)
/*  f16a2c0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a2c4:	8e041624 */ 	lw	$a0,0x1624($s0)
/*  f16a2c8:	50800046 */ 	beqzl	$a0,.JF0f16a3e4
/*  f16a2cc:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f16a2d0:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f16a2d4:	24010003 */ 	li	$at,0x3
/*  f16a2d8:	10410003 */ 	beq	$v0,$at,.JF0f16a2e8
/*  f16a2dc:	24010006 */ 	li	$at,0x6
/*  f16a2e0:	1441001f */ 	bne	$v0,$at,.JF0f16a360
/*  f16a2e4:	00000000 */ 	nop
.JF0f16a2e8:
/*  f16a2e8:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f16a2ec:	8c590014 */ 	lw	$t9,0x14($v0)
/*  f16a2f0:	00197880 */ 	sll	$t7,$t9,0x2
/*  f16a2f4:	05e3003b */ 	bgezl	$t7,.JF0f16a3e4
/*  f16a2f8:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f16a2fc:	8e0a00d8 */ 	lw	$t2,0xd8($s0)
/*  f16a300:	3c188007 */ 	lui	$t8,0x8007
/*  f16a304:	55400014 */ 	bnezl	$t2,.JF0f16a358
/*  f16a308:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f16a30c:	8f180cb4 */ 	lw	$t8,0xcb4($t8)
/*  f16a310:	57000011 */ 	bnezl	$t8,.JF0f16a358
/*  f16a314:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f16a318:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f16a31c:	50400007 */ 	beqzl	$v0,.JF0f16a33c
/*  f16a320:	8e0c1c54 */ 	lw	$t4,0x1c54($s0)
/*  f16a324:	5040000c */ 	beqzl	$v0,.JF0f16a358
/*  f16a328:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f16a32c:	804b0037 */ 	lb	$t3,0x37($v0)
/*  f16a330:	55600009 */ 	bnezl	$t3,.JF0f16a358
/*  f16a334:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f16a338:	8e0c1c54 */ 	lw	$t4,0x1c54($s0)
.JF0f16a33c:
/*  f16a33c:	8e0e00c4 */ 	lw	$t6,0xc4($s0)
/*  f16a340:	01806827 */ 	nor	$t5,$t4,$zero
/*  f16a344:	01cdc824 */ 	and	$t9,$t6,$t5
/*  f16a348:	332f0008 */ 	andi	$t7,$t9,0x8
/*  f16a34c:	55e00025 */ 	bnezl	$t7,.JF0f16a3e4
/*  f16a350:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f16a354:	ae001624 */ 	sw	$zero,0x1624($s0)
.JF0f16a358:
/*  f16a358:	10000021 */ 	b	.JF0f16a3e0
/*  f16a35c:	8e500284 */ 	lw	$s0,0x284($s2)
.JF0f16a360:
/*  f16a360:	53c20006 */ 	beql	$s8,$v0,.JF0f16a37c
/*  f16a364:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f16a368:	12a20003 */ 	beq	$s5,$v0,.JF0f16a378
/*  f16a36c:	24010002 */ 	li	$at,0x2
/*  f16a370:	54410016 */ 	bnel	$v0,$at,.JF0f16a3cc
/*  f16a374:	ae001624 */ 	sw	$zero,0x1624($s0)
.JF0f16a378:
/*  f16a378:	8c830004 */ 	lw	$v1,0x4($a0)
.JF0f16a37c:
/*  f16a37c:	8c6a0010 */ 	lw	$t2,0x10($v1)
/*  f16a380:	31588000 */ 	andi	$t8,$t2,0x8000
/*  f16a384:	57000017 */ 	bnezl	$t8,.JF0f16a3e4
/*  f16a388:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f16a38c:	8e4b04b4 */ 	lw	$t3,0x4b4($s2)
/*  f16a390:	24010026 */ 	li	$at,0x26
/*  f16a394:	5561000a */ 	bnel	$t3,$at,.JF0f16a3c0
/*  f16a398:	ae001624 */ 	sw	$zero,0x1624($s0)
/*  f16a39c:	84620004 */ 	lh	$v0,0x4($v1)
/*  f16a3a0:	2401014c */ 	li	$at,0x14c
/*  f16a3a4:	1041000e */ 	beq	$v0,$at,.JF0f16a3e0
/*  f16a3a8:	240101aa */ 	li	$at,0x1aa
/*  f16a3ac:	1041000c */ 	beq	$v0,$at,.JF0f16a3e0
/*  f16a3b0:	240100b0 */ 	li	$at,0xb0
/*  f16a3b4:	5041000b */ 	beql	$v0,$at,.JF0f16a3e4
/*  f16a3b8:	26040638 */ 	addiu	$a0,$s0,0x638
/*  f16a3bc:	ae001624 */ 	sw	$zero,0x1624($s0)
.JF0f16a3c0:
/*  f16a3c0:	10000007 */ 	b	.JF0f16a3e0
/*  f16a3c4:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a3c8:	ae001624 */ 	sw	$zero,0x1624($s0)
.JF0f16a3cc:
/*  f16a3cc:	10000004 */ 	b	.JF0f16a3e0
/*  f16a3d0:	8e500284 */ 	lw	$s0,0x284($s2)
.JF0f16a3d4:
/*  f16a3d4:	8e4c0284 */ 	lw	$t4,0x284($s2)
.JF0f16a3d8:
/*  f16a3d8:	ad801624 */ 	sw	$zero,0x1624($t4)
/*  f16a3dc:	8e500284 */ 	lw	$s0,0x284($s2)
.JF0f16a3e0:
/*  f16a3e0:	26040638 */ 	addiu	$a0,$s0,0x638
.JF0f16a3e4:
/*  f16a3e4:	0fc2cbcb */ 	jal	gsetHasFunctionFlags
/*  f16a3e8:	3c050008 */ 	lui	$a1,0x8
/*  f16a3ec:	10400005 */ 	beqz	$v0,.JF0f16a404
/*  f16a3f0:	00000000 */ 	nop
/*  f16a3f4:	0fc5a574 */ 	jal	lvFindThreats
/*  f16a3f8:	00000000 */ 	nop
/*  f16a3fc:	10000033 */ 	b	.JF0f16a4cc
/*  f16a400:	8e500284 */ 	lw	$s0,0x284($s2)
.JF0f16a404:
/*  f16a404:	0fc28a44 */ 	jal	bgunGetWeaponNum
/*  f16a408:	00002025 */ 	move	$a0,$zero
/*  f16a40c:	00402025 */ 	move	$a0,$v0
/*  f16a410:	0fc2ca10 */ 	jal	weaponHasFlag
/*  f16a414:	3c054000 */ 	lui	$a1,0x4000
/*  f16a418:	5040002c */ 	beqzl	$v0,.JF0f16a4cc
/*  f16a41c:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a420:	0fc68567 */ 	jal	frIsInTraining
/*  f16a424:	00000000 */ 	nop
/*  f16a428:	5040000f */ 	beqzl	$v0,.JF0f16a468
/*  f16a42c:	8e440284 */ 	lw	$a0,0x284($s2)
/*  f16a430:	8e4e0284 */ 	lw	$t6,0x284($s2)
/*  f16a434:	8dcd1624 */ 	lw	$t5,0x1624($t6)
/*  f16a438:	51a0000b */ 	beqzl	$t5,.JF0f16a468
/*  f16a43c:	8e440284 */ 	lw	$a0,0x284($s2)
/*  f16a440:	0fc322ec */ 	jal	bmoveIsInSightAimMode
/*  f16a444:	00000000 */ 	nop
/*  f16a448:	50400007 */ 	beqzl	$v0,.JF0f16a468
/*  f16a44c:	8e440284 */ 	lw	$a0,0x284($s2)
/*  f16a450:	8e590284 */ 	lw	$t9,0x284($s2)
/*  f16a454:	0fc684a4 */ 	jal	func0f1a0924
/*  f16a458:	8f241624 */ 	lw	$a0,0x1624($t9)
/*  f16a45c:	1000000a */ 	b	.JF0f16a488
/*  f16a460:	00008825 */ 	move	$s1,$zero
/*  f16a464:	8e440284 */ 	lw	$a0,0x284($s2)
.JF0f16a468:
/*  f16a468:	02e02825 */ 	move	$a1,$s7
/*  f16a46c:	0fc5a343 */ 	jal	lvCheckCmpFollowThreat
/*  f16a470:	24841624 */ 	addiu	$a0,$a0,0x1624
/*  f16a474:	54400004 */ 	bnezl	$v0,.JF0f16a488
/*  f16a478:	00008825 */ 	move	$s1,$zero
/*  f16a47c:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f16a480:	ade01624 */ 	sw	$zero,0x1624($t7)
/*  f16a484:	00008825 */ 	move	$s1,$zero
.JF0f16a488:
/*  f16a488:	00008025 */ 	move	$s0,$zero
.JF0f16a48c:
/*  f16a48c:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f16a490:	02202825 */ 	move	$a1,$s1
/*  f16a494:	01502021 */ 	addu	$a0,$t2,$s0
/*  f16a498:	0fc5a343 */ 	jal	lvCheckCmpFollowThreat
/*  f16a49c:	24841630 */ 	addiu	$a0,$a0,0x1630
/*  f16a4a0:	14400007 */ 	bnez	$v0,.JF0f16a4c0
/*  f16a4a4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f16a4a8:	8e580284 */ 	lw	$t8,0x284($s2)
/*  f16a4ac:	03105821 */ 	addu	$t3,$t8,$s0
/*  f16a4b0:	a5771634 */ 	sh	$s7,0x1634($t3)
/*  f16a4b4:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f16a4b8:	01907021 */ 	addu	$t6,$t4,$s0
/*  f16a4bc:	a5d61638 */ 	sh	$s6,0x1638($t6)
.JF0f16a4c0:
/*  f16a4c0:	1635fff2 */ 	bne	$s1,$s5,.JF0f16a48c
/*  f16a4c4:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f16a4c8:	8e500284 */ 	lw	$s0,0x284($s2)
.JF0f16a4cc:
/*  f16a4cc:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f16a4d0:	50400071 */ 	beqzl	$v0,.JF0f16a698
/*  f16a4d4:	8e0e00d0 */ 	lw	$t6,0xd0($s0)
/*  f16a4d8:	8e191c54 */ 	lw	$t9,0x1c54($s0)
/*  f16a4dc:	8e0d00c4 */ 	lw	$t5,0xc4($s0)
/*  f16a4e0:	03207827 */ 	nor	$t7,$t9,$zero
/*  f16a4e4:	01af5024 */ 	and	$t2,$t5,$t7
/*  f16a4e8:	31580004 */ 	andi	$t8,$t2,0x4
/*  f16a4ec:	5300006a */ 	beqzl	$t8,.JF0f16a698
/*  f16a4f0:	8e0e00d0 */ 	lw	$t6,0xd0($s0)
/*  f16a4f4:	804b0039 */ 	lb	$t3,0x39($v0)
/*  f16a4f8:	51600067 */ 	beqzl	$t3,.JF0f16a698
/*  f16a4fc:	8e0e00d0 */ 	lw	$t6,0xd0($s0)
/*  f16a500:	9043006b */ 	lbu	$v1,0x6b($v0)
/*  f16a504:	3c0143c8 */ 	lui	$at,0x43c8
/*  f16a508:	14600010 */ 	bnez	$v1,.JF0f16a54c
/*  f16a50c:	00000000 */ 	nop
/*  f16a510:	44816000 */ 	mtc1	$at,$f12
/*  f16a514:	0fc25b8a */ 	jal	objectiveCheckHolograph
/*  f16a518:	00000000 */ 	nop
/*  f16a51c:	3c048009 */ 	lui	$a0,0x8009
/*  f16a520:	8c845870 */ 	lw	$a0,0x5870($a0)
/*  f16a524:	240504ff */ 	li	$a1,0x4ff
/*  f16a528:	00003025 */ 	move	$a2,$zero
/*  f16a52c:	02e03825 */ 	move	$a3,$s7
/*  f16a530:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16a534:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16a538:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16a53c:	0c004230 */ 	jal	sndStart
/*  f16a540:	afb7001c */ 	sw	$s7,0x1c($sp)
/*  f16a544:	10000053 */ 	b	.JF0f16a694
/*  f16a548:	8e500284 */ 	lw	$s0,0x284($s2)
.JF0f16a54c:
/*  f16a54c:	17c30032 */ 	bne	$s8,$v1,.JF0f16a618
/*  f16a550:	3c0e8008 */ 	lui	$t6,0x8008
/*  f16a554:	8e0c0490 */ 	lw	$t4,0x490($s0)
/*  f16a558:	3c048009 */ 	lui	$a0,0x8009
/*  f16a55c:	24058052 */ 	li	$a1,-32686
/*  f16a560:	11800024 */ 	beqz	$t4,.JF0f16a5f4
/*  f16a564:	00003025 */ 	move	$a2,$zero
/*  f16a568:	3c048009 */ 	lui	$a0,0x8009
/*  f16a56c:	8c845870 */ 	lw	$a0,0x5870($a0)
/*  f16a570:	24058057 */ 	li	$a1,-32681
/*  f16a574:	00003025 */ 	move	$a2,$zero
/*  f16a578:	02e03825 */ 	move	$a3,$s7
/*  f16a57c:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16a580:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16a584:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16a588:	0c004230 */ 	jal	sndStart
/*  f16a58c:	afb7001c */ 	sw	$s7,0x1c($sp)
/*  f16a590:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a594:	240b001c */ 	li	$t3,0x1c
/*  f16a598:	00002825 */ 	move	$a1,$zero
/*  f16a59c:	8e0e0490 */ 	lw	$t6,0x490($s0)
/*  f16a5a0:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f16a5a4:	25d9ffff */ 	addiu	$t9,$t6,-1
/*  f16a5a8:	ae190490 */ 	sw	$t9,0x490($s0)
/*  f16a5ac:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a5b0:	8e0d0480 */ 	lw	$t5,0x480($s0)
/*  f16a5b4:	c5b00004 */ 	lwc1	$f16,0x4($t5)
/*  f16a5b8:	e7b000c0 */ 	swc1	$f16,0xc0($sp)
/*  f16a5bc:	8e0f0480 */ 	lw	$t7,0x480($s0)
/*  f16a5c0:	c5f20008 */ 	lwc1	$f18,0x8($t7)
/*  f16a5c4:	e7b200c4 */ 	swc1	$f18,0xc4($sp)
/*  f16a5c8:	8e0a0480 */ 	lw	$t2,0x480($s0)
/*  f16a5cc:	c544000c */ 	lwc1	$f4,0xc($t2)
/*  f16a5d0:	e7a400c8 */ 	swc1	$f4,0xc8($sp)
/*  f16a5d4:	8e180480 */ 	lw	$t8,0x480($s0)
/*  f16a5d8:	8f040000 */ 	lw	$a0,0x0($t8)
/*  f16a5dc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f16a5e0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f16a5e4:	0fc24818 */ 	jal	projectileCreate
/*  f16a5e8:	24860008 */ 	addiu	$a2,$a0,0x8
/*  f16a5ec:	10000008 */ 	b	.JF0f16a610
/*  f16a5f0:	00000000 */ 	nop
.JF0f16a5f4:
/*  f16a5f4:	8c845870 */ 	lw	$a0,0x5870($a0)
/*  f16a5f8:	02e03825 */ 	move	$a3,$s7
/*  f16a5fc:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16a600:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16a604:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16a608:	0c004230 */ 	jal	sndStart
/*  f16a60c:	afb7001c */ 	sw	$s7,0x1c($sp)
.JF0f16a610:
/*  f16a610:	10000020 */ 	b	.JF0f16a694
/*  f16a614:	8e500284 */ 	lw	$s0,0x284($s2)
.JF0f16a618:
/*  f16a618:	25ce46d8 */ 	addiu	$t6,$t6,0x46d8
/*  f16a61c:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f16a620:	27ac00b4 */ 	addiu	$t4,$sp,0xb4
/*  f16a624:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f16a628:	ad810000 */ 	sw	$at,0x0($t4)
/*  f16a62c:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f16a630:	3c0a8008 */ 	lui	$t2,0x8008
/*  f16a634:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f16a638:	ad810008 */ 	sw	$at,0x8($t4)
/*  f16a63c:	8d4a46e4 */ 	lw	$t2,0x46e4($t2)
/*  f16a640:	24070017 */ 	li	$a3,0x17
/*  f16a644:	afaa00b0 */ 	sw	$t2,0xb0($sp)
/*  f16a648:	8e180480 */ 	lw	$t8,0x480($s0)
/*  f16a64c:	8f040000 */ 	lw	$a0,0x0($t8)
/*  f16a650:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f16a654:	24850008 */ 	addiu	$a1,$a0,0x8
/*  f16a658:	0fc4a740 */ 	jal	explosionCreateSimple
/*  f16a65c:	24860028 */ 	addiu	$a2,$a0,0x28
/*  f16a660:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f16a664:	27ac00b0 */ 	addiu	$t4,$sp,0xb0
/*  f16a668:	27a500b4 */ 	addiu	$a1,$sp,0xb4
/*  f16a66c:	8d6d0480 */ 	lw	$t5,0x480($t3)
/*  f16a670:	24060000 */ 	li	$a2,0x0
/*  f16a674:	00003825 */ 	move	$a3,$zero
/*  f16a678:	8db90000 */ 	lw	$t9,0x0($t5)
/*  f16a67c:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f16a680:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f16a684:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f16a688:	0fc0caea */ 	jal	chrBeginDeath
/*  f16a68c:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f16a690:	8e500284 */ 	lw	$s0,0x284($s2)
.JF0f16a694:
/*  f16a694:	8e0e00d0 */ 	lw	$t6,0xd0($s0)
.JF0f16a698:
/*  f16a698:	51c0000c */ 	beqzl	$t6,.JF0f16a6cc
/*  f16a69c:	8e020480 */ 	lw	$v0,0x480($s0)
/*  f16a6a0:	0fc18fe5 */ 	jal	currentPlayerInteract
/*  f16a6a4:	00002025 */ 	move	$a0,$zero
/*  f16a6a8:	10400012 */ 	beqz	$v0,.JF0f16a6f4
/*  f16a6ac:	00000000 */ 	nop
/*  f16a6b0:	0fc28c60 */ 	jal	bgunReloadIfPossible
/*  f16a6b4:	00002025 */ 	move	$a0,$zero
/*  f16a6b8:	0fc28c60 */ 	jal	bgunReloadIfPossible
/*  f16a6bc:	03c02025 */ 	move	$a0,$s8
/*  f16a6c0:	1000000c */ 	b	.JF0f16a6f4
/*  f16a6c4:	00000000 */ 	nop
/*  f16a6c8:	8e020480 */ 	lw	$v0,0x480($s0)
.JF0f16a6cc:
/*  f16a6cc:	10400009 */ 	beqz	$v0,.JF0f16a6f4
/*  f16a6d0:	00000000 */ 	nop
/*  f16a6d4:	804f0037 */ 	lb	$t7,0x37($v0)
/*  f16a6d8:	11e00006 */ 	beqz	$t7,.JF0f16a6f4
/*  f16a6dc:	00000000 */ 	nop
/*  f16a6e0:	904a006a */ 	lbu	$t2,0x6a($v0)
/*  f16a6e4:	11400003 */ 	beqz	$t2,.JF0f16a6f4
/*  f16a6e8:	00000000 */ 	nop
/*  f16a6ec:	0fc18fe5 */ 	jal	currentPlayerInteract
/*  f16a6f0:	03c02025 */ 	move	$a0,$s8
.JF0f16a6f4:
/*  f16a6f4:	0fc194c5 */ 	jal	func0f0641f4
/*  f16a6f8:	00000000 */ 	nop
/*  f16a6fc:	0fc573bc */ 	jal	bgRender
/*  f16a700:	02602025 */ 	move	$a0,$s3
/*  f16a704:	3c108007 */ 	lui	$s0,0x8007
/*  f16a708:	8e106358 */ 	lw	$s0,0x6358($s0)
/*  f16a70c:	00409825 */ 	move	$s3,$v0
/*  f16a710:	3a18000f */ 	xori	$t8,$s0,0xf
/*  f16a714:	2f100001 */ 	sltiu	$s0,$t8,0x1
/*  f16a718:	16000005 */ 	bnez	$s0,.JF0f16a730
/*  f16a71c:	00000000 */ 	nop
/*  f16a720:	3c108006 */ 	lui	$s0,0x8006
/*  f16a724:	8e10eee0 */ 	lw	$s0,-0x1120($s0)
/*  f16a728:	0010582b */ 	sltu	$t3,$zero,$s0
/*  f16a72c:	01608025 */ 	move	$s0,$t3
.JF0f16a730:
/*  f16a730:	0fc0a598 */ 	jal	chr0f028498
/*  f16a734:	02002025 */ 	move	$a0,$s0
/*  f16a738:	0fc201e2 */ 	jal	propsRenderBeams
/*  f16a73c:	02602025 */ 	move	$a0,$s3
/*  f16a740:	0fc54741 */ 	jal	shardsRender
/*  f16a744:	00402025 */ 	move	$a0,$v0
/*  f16a748:	0fc4c111 */ 	jal	sparksRender
/*  f16a74c:	00402025 */ 	move	$a0,$v0
/*  f16a750:	0fc4c518 */ 	jal	weatherRender
/*  f16a754:	00402025 */ 	move	$a0,$v0
/*  f16a758:	3c0d8006 */ 	lui	$t5,0x8006
/*  f16a75c:	8dad1520 */ 	lw	$t5,0x1520($t5)
/*  f16a760:	00409825 */ 	move	$s3,$v0
/*  f16a764:	11a00004 */ 	beqz	$t5,.JF0f16a778
/*  f16a768:	00000000 */ 	nop
/*  f16a76c:	0fc0287c */ 	jal	nbombsRender
/*  f16a770:	00402025 */ 	move	$a0,$v0
/*  f16a774:	00409825 */ 	move	$s3,$v0
.JF0f16a778:
/*  f16a778:	3c198007 */ 	lui	$t9,0x8007
/*  f16a77c:	8f396350 */ 	lw	$t9,0x6350($t9)
/*  f16a780:	24010002 */ 	li	$at,0x2
/*  f16a784:	17210005 */ 	bne	$t9,$at,.JF0f16a79c
/*  f16a788:	00000000 */ 	nop
/*  f16a78c:	0fc30620 */ 	jal	playerRenderHud
/*  f16a790:	02602025 */ 	move	$a0,$s3
/*  f16a794:	1000000b */ 	b	.JF0f16a7c4
/*  f16a798:	00409825 */ 	move	$s3,$v0
.JF0f16a79c:
/*  f16a79c:	0fc2bfd6 */ 	jal	func0f0aeed8
/*  f16a7a0:	02602025 */ 	move	$a0,$s3
/*  f16a7a4:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f16a7a8:	00409825 */ 	move	$s3,$v0
/*  f16a7ac:	958e0010 */ 	lhu	$t6,0x10($t4)
/*  f16a7b0:	13ce0004 */ 	beq	$s8,$t6,.JF0f16a7c4
/*  f16a7b4:	00000000 */ 	nop
/*  f16a7b8:	0fc56d49 */ 	jal	func0f15b114
/*  f16a7bc:	00402025 */ 	move	$a0,$v0
/*  f16a7c0:	00409825 */ 	move	$s3,$v0
.JF0f16a7c4:
/*  f16a7c4:	3c0f8007 */ 	lui	$t7,0x8007
/*  f16a7c8:	8def6368 */ 	lw	$t7,0x6368($t7)
/*  f16a7cc:	1de001ee */ 	bgtz	$t7,.JF0f16af88
/*  f16a7d0:	00000000 */ 	nop
/*  f16a7d4:	8e4a02ac */ 	lw	$t2,0x2ac($s2)
/*  f16a7d8:	24010006 */ 	li	$at,0x6
/*  f16a7dc:	00008825 */ 	move	$s1,$zero
/*  f16a7e0:	1541006f */ 	bne	$t2,$at,.JF0f16a9a0
/*  f16a7e4:	3c10800a */ 	lui	$s0,0x800a
/*  f16a7e8:	8610e4ec */ 	lh	$s0,-0x1b14($s0)
/*  f16a7ec:	24010181 */ 	li	$at,0x181
/*  f16a7f0:	3c048008 */ 	lui	$a0,0x8008
/*  f16a7f4:	12010011 */ 	beq	$s0,$at,.JF0f16a83c
/*  f16a7f8:	24010183 */ 	li	$at,0x183
/*  f16a7fc:	1201000f */ 	beq	$s0,$at,.JF0f16a83c
/*  f16a800:	24010188 */ 	li	$at,0x188
/*  f16a804:	1201000d */ 	beq	$s0,$at,.JF0f16a83c
/*  f16a808:	240101e5 */ 	li	$at,0x1e5
/*  f16a80c:	16010064 */ 	bne	$s0,$at,.JF0f16a9a0
/*  f16a810:	3c02800a */ 	lui	$v0,0x800a
/*  f16a814:	8c42e4e0 */ 	lw	$v0,-0x1b20($v0)
/*  f16a818:	28410348 */ 	slti	$at,$v0,0x348
/*  f16a81c:	14200060 */ 	bnez	$at,.JF0f16a9a0
/*  f16a820:	28410583 */ 	slti	$at,$v0,0x583
/*  f16a824:	1020005e */ 	beqz	$at,.JF0f16a9a0
/*  f16a828:	00000000 */ 	nop
/*  f16a82c:	0fc52083 */ 	jal	bviewRenderHorizonScanner
/*  f16a830:	02602025 */ 	move	$a0,$s3
/*  f16a834:	1000005a */ 	b	.JF0f16a9a0
/*  f16a838:	00409825 */ 	move	$s3,$v0
.JF0f16a83c:
/*  f16a83c:	8c8446e8 */ 	lw	$a0,0x46e8($a0)
/*  f16a840:	00008025 */ 	move	$s0,$zero
/*  f16a844:	03c08825 */ 	move	$s1,$s8
/*  f16a848:	1480000b */ 	bnez	$a0,.JF0f16a878
/*  f16a84c:	2405059f */ 	li	$a1,0x59f
/*  f16a850:	3c048009 */ 	lui	$a0,0x8009
/*  f16a854:	3c068008 */ 	lui	$a2,0x8008
/*  f16a858:	24c646e8 */ 	addiu	$a2,$a2,0x46e8
/*  f16a85c:	8c845870 */ 	lw	$a0,0x5870($a0)
/*  f16a860:	02e03825 */ 	move	$a3,$s7
/*  f16a864:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16a868:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16a86c:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16a870:	0c004230 */ 	jal	sndStart
/*  f16a874:	afb7001c */ 	sw	$s7,0x1c($sp)
.JF0f16a878:
/*  f16a878:	3c188008 */ 	lui	$t8,0x8008
/*  f16a87c:	8f1846ec */ 	lw	$t8,0x46ec($t8)
/*  f16a880:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f16a884:	3c018008 */ 	lui	$at,0x8008
/*  f16a888:	030b6823 */ 	subu	$t5,$t8,$t3
/*  f16a88c:	05a1000b */ 	bgez	$t5,.JF0f16a8bc
/*  f16a890:	ac2d46ec */ 	sw	$t5,0x46ec($at)
/*  f16a894:	0c004b60 */ 	jal	random
/*  f16a898:	00000000 */ 	nop
/*  f16a89c:	240100c8 */ 	li	$at,0xc8
/*  f16a8a0:	0041001b */ 	divu	$zero,$v0,$at
/*  f16a8a4:	0000c810 */ 	mfhi	$t9
/*  f16a8a8:	272c0028 */ 	addiu	$t4,$t9,0x28
/*  f16a8ac:	3c018008 */ 	lui	$at,0x8008
/*  f16a8b0:	ac2c46ec */ 	sw	$t4,0x46ec($at)
/*  f16a8b4:	3c018008 */ 	lui	$at,0x8008
/*  f16a8b8:	a02046f0 */ 	sb	$zero,0x46f0($at)
.JF0f16a8bc:
/*  f16a8bc:	02602025 */ 	move	$a0,$s3
/*  f16a8c0:	2405ffff */ 	li	$a1,-1
/*  f16a8c4:	0fc50b63 */ 	jal	bviewRenderFilmLens
/*  f16a8c8:	2406ffff */ 	li	$a2,-1
/*  f16a8cc:	3c0e8008 */ 	lui	$t6,0x8008
/*  f16a8d0:	8dce46ec */ 	lw	$t6,0x46ec($t6)
/*  f16a8d4:	00409825 */ 	move	$s3,$v0
/*  f16a8d8:	3c0f8008 */ 	lui	$t7,0x8008
/*  f16a8dc:	29c1000f */ 	slti	$at,$t6,0xf
/*  f16a8e0:	10200017 */ 	beqz	$at,.JF0f16a940
/*  f16a8e4:	00000000 */ 	nop
/*  f16a8e8:	91ef46f0 */ 	lbu	$t7,0x46f0($t7)
/*  f16a8ec:	240a0001 */ 	li	$t2,0x1
/*  f16a8f0:	3c018008 */ 	lui	$at,0x8008
/*  f16a8f4:	15e0000b */ 	bnez	$t7,.JF0f16a924
/*  f16a8f8:	3c048009 */ 	lui	$a0,0x8009
/*  f16a8fc:	a02a46f0 */ 	sb	$t2,0x46f0($at)
/*  f16a900:	8c845870 */ 	lw	$a0,0x5870($a0)
/*  f16a904:	2405059e */ 	li	$a1,0x59e
/*  f16a908:	00003025 */ 	move	$a2,$zero
/*  f16a90c:	02e03825 */ 	move	$a3,$s7
/*  f16a910:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16a914:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16a918:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16a91c:	0c004230 */ 	jal	sndStart
/*  f16a920:	afb7001c */ 	sw	$s7,0x1c($sp)
.JF0f16a924:
/*  f16a924:	3c188008 */ 	lui	$t8,0x8008
/*  f16a928:	8f1846ec */ 	lw	$t8,0x46ec($t8)
/*  f16a92c:	240d00e1 */ 	li	$t5,0xe1
/*  f16a930:	00185880 */ 	sll	$t3,$t8,0x2
/*  f16a934:	01785821 */ 	addu	$t3,$t3,$t8
/*  f16a938:	000b5840 */ 	sll	$t3,$t3,0x1
/*  f16a93c:	01ab8023 */ 	subu	$s0,$t5,$t3
.JF0f16a940:
/*  f16a940:	0c004b60 */ 	jal	random
/*  f16a944:	00000000 */ 	nop
/*  f16a948:	2401003c */ 	li	$at,0x3c
/*  f16a94c:	0041001b */ 	divu	$zero,$v0,$at
/*  f16a950:	0000c810 */ 	mfhi	$t9
/*  f16a954:	24010001 */ 	li	$at,0x1
/*  f16a958:	1721000b */ 	bne	$t9,$at,.JF0f16a988
/*  f16a95c:	3c048009 */ 	lui	$a0,0x8009
/*  f16a960:	241000ff */ 	li	$s0,0xff
/*  f16a964:	8c845870 */ 	lw	$a0,0x5870($a0)
/*  f16a968:	2405059d */ 	li	$a1,0x59d
/*  f16a96c:	00003025 */ 	move	$a2,$zero
/*  f16a970:	02e03825 */ 	move	$a3,$s7
/*  f16a974:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16a978:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16a97c:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16a980:	0c004230 */ 	jal	sndStart
/*  f16a984:	afb7001c */ 	sw	$s7,0x1c($sp)
.JF0f16a988:
/*  f16a988:	12000005 */ 	beqz	$s0,.JF0f16a9a0
/*  f16a98c:	02602025 */ 	move	$a0,$s3
/*  f16a990:	2405ffff */ 	li	$a1,-1
/*  f16a994:	0fc50a91 */ 	jal	bviewRenderStatic
/*  f16a998:	02003025 */ 	move	$a2,$s0
/*  f16a99c:	00409825 */ 	move	$s3,$v0
.JF0f16a9a0:
/*  f16a9a0:	3c048008 */ 	lui	$a0,0x8008
/*  f16a9a4:	8c8446e8 */ 	lw	$a0,0x46e8($a0)
/*  f16a9a8:	50800006 */ 	beqzl	$a0,.JF0f16a9c4
/*  f16a9ac:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a9b0:	56200004 */ 	bnezl	$s1,.JF0f16a9c4
/*  f16a9b4:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a9b8:	0c00cd8d */ 	jal	audioStop
/*  f16a9bc:	00000000 */ 	nop
/*  f16a9c0:	8e500284 */ 	lw	$s0,0x284($s2)
.JF0f16a9c4:
/*  f16a9c4:	24010002 */ 	li	$at,0x2
/*  f16a9c8:	960c0010 */ 	lhu	$t4,0x10($s0)
/*  f16a9cc:	5581001c */ 	bnel	$t4,$at,.JF0f16aa40
/*  f16a9d0:	96030010 */ 	lhu	$v1,0x10($s0)
/*  f16a9d4:	8e4e02ac */ 	lw	$t6,0x2ac($s2)
/*  f16a9d8:	24010006 */ 	li	$at,0x6
/*  f16a9dc:	02602025 */ 	move	$a0,$s3
/*  f16a9e0:	11c10016 */ 	beq	$t6,$at,.JF0f16aa3c
/*  f16a9e4:	2405ffff */ 	li	$a1,-1
/*  f16a9e8:	0fc50add */ 	jal	bviewRenderSlayerRocketLens
/*  f16a9ec:	2406ffff */ 	li	$a2,-1
/*  f16a9f0:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16a9f4:	00409825 */ 	move	$s3,$v0
/*  f16a9f8:	2401005a */ 	li	$at,0x5a
/*  f16a9fc:	8e0300c8 */ 	lw	$v1,0xc8($s0)
/*  f16aa00:	02602025 */ 	move	$a0,$s3
/*  f16aa04:	3c054fff */ 	lui	$a1,0x4fff
/*  f16aa08:	1860000c */ 	blez	$v1,.JF0f16aa3c
/*  f16aa0c:	00033200 */ 	sll	$a2,$v1,0x8
/*  f16aa10:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f16aa14:	00c1001a */ 	div	$zero,$a2,$at
/*  f16aa18:	00003012 */ 	mflo	$a2
/*  f16aa1c:	2cc10100 */ 	sltiu	$at,$a2,0x100
/*  f16aa20:	14200002 */ 	bnez	$at,.JF0f16aa2c
/*  f16aa24:	00000000 */ 	nop
/*  f16aa28:	240600ff */ 	li	$a2,0xff
.JF0f16aa2c:
/*  f16aa2c:	0fc50a91 */ 	jal	bviewRenderStatic
/*  f16aa30:	34a5ffff */ 	ori	$a1,$a1,0xffff
/*  f16aa34:	00409825 */ 	move	$s3,$v0
/*  f16aa38:	8e500284 */ 	lw	$s0,0x284($s2)
.JF0f16aa3c:
/*  f16aa3c:	96030010 */ 	lhu	$v1,0x10($s0)
.JF0f16aa40:
/*  f16aa40:	24010003 */ 	li	$at,0x3
/*  f16aa44:	02602025 */ 	move	$a0,$s3
/*  f16aa48:	14610009 */ 	bne	$v1,$at,.JF0f16aa70
/*  f16aa4c:	3c054fff */ 	lui	$a1,0x4fff
/*  f16aa50:	34a5ffff */ 	ori	$a1,$a1,0xffff
/*  f16aa54:	0fc50a91 */ 	jal	bviewRenderStatic
/*  f16aa58:	240600ff */ 	li	$a2,0xff
/*  f16aa5c:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f16aa60:	00409825 */ 	move	$s3,$v0
/*  f16aa64:	a5400010 */ 	sh	$zero,0x10($t2)
/*  f16aa68:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16aa6c:	96030010 */ 	lhu	$v1,0x10($s0)
.JF0f16aa70:
/*  f16aa70:	57c30017 */ 	bnel	$s8,$v1,.JF0f16aad0
/*  f16aa74:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f16aa78:	8e5802ac */ 	lw	$t8,0x2ac($s2)
/*  f16aa7c:	24010006 */ 	li	$at,0x6
/*  f16aa80:	53010013 */ 	beql	$t8,$at,.JF0f16aad0
/*  f16aa84:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f16aa88:	8e020254 */ 	lw	$v0,0x254($s0)
/*  f16aa8c:	24060063 */ 	li	$a2,0x63
/*  f16aa90:	241900f9 */ 	li	$t9,0xf9
/*  f16aa94:	284100c8 */ 	slti	$at,$v0,0xc8
/*  f16aa98:	10200004 */ 	beqz	$at,.JF0f16aaac
/*  f16aa9c:	00026880 */ 	sll	$t5,$v0,0x2
/*  f16aaa0:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f16aaa4:	000d5883 */ 	sra	$t3,$t5,0x2
/*  f16aaa8:	032b3023 */ 	subu	$a2,$t9,$t3
.JF0f16aaac:
/*  f16aaac:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16aab0:	c4208770 */ 	lwc1	$f0,-0x7890($at)
/*  f16aab4:	02602025 */ 	move	$a0,$s3
/*  f16aab8:	2405ffff */ 	li	$a1,-1
/*  f16aabc:	44070000 */ 	mfc1	$a3,$f0
/*  f16aac0:	0fc50bfc */ 	jal	bviewRenderZoomBlur
/*  f16aac4:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f16aac8:	00409825 */ 	move	$s3,$v0
/*  f16aacc:	8e430460 */ 	lw	$v1,0x460($s2)
.JF0f16aad0:
/*  f16aad0:	18600003 */ 	blez	$v1,.JF0f16aae0
/*  f16aad4:	2861001e */ 	slti	$at,$v1,0x1e
/*  f16aad8:	5420000c */ 	bnezl	$at,.JF0f16ab0c
/*  f16aadc:	2401001e */ 	li	$at,0x1e
.JF0f16aae0:
/*  f16aae0:	8e420464 */ 	lw	$v0,0x464($s2)
/*  f16aae4:	10400004 */ 	beqz	$v0,.JF0f16aaf8
/*  f16aae8:	00000000 */ 	nop
/*  f16aaec:	8e4c0468 */ 	lw	$t4,0x468($s2)
/*  f16aaf0:	51800006 */ 	beqzl	$t4,.JF0f16ab0c
/*  f16aaf4:	2401001e */ 	li	$at,0x1e
.JF0f16aaf8:
/*  f16aaf8:	54400085 */ 	bnezl	$v0,.JF0f16ad10
/*  f16aafc:	28610010 */ 	slti	$at,$v1,0x10
/*  f16ab00:	8e4e0468 */ 	lw	$t6,0x468($s2)
/*  f16ab04:	11c00081 */ 	beqz	$t6,.JF0f16ad0c
/*  f16ab08:	2401001e */ 	li	$at,0x1e
.JF0f16ab0c:
/*  f16ab0c:	54610018 */ 	bnel	$v1,$at,.JF0f16ab70
/*  f16ab10:	2861000f */ 	slti	$at,$v1,0xf
/*  f16ab14:	8e4f0464 */ 	lw	$t7,0x464($s2)
/*  f16ab18:	55e00015 */ 	bnezl	$t7,.JF0f16ab70
/*  f16ab1c:	2861000f */ 	slti	$at,$v1,0xf
/*  f16ab20:	0fc5ae7b */ 	jal	lvGetSlowMotionType
/*  f16ab24:	00000000 */ 	nop
/*  f16ab28:	10400003 */ 	beqz	$v0,.JF0f16ab38
/*  f16ab2c:	3c048009 */ 	lui	$a0,0x8009
/*  f16ab30:	10000002 */ 	b	.JF0f16ab3c
/*  f16ab34:	241005c9 */ 	li	$s0,0x5c9
.JF0f16ab38:
/*  f16ab38:	241002ad */ 	li	$s0,0x2ad
.JF0f16ab3c:
/*  f16ab3c:	00102c00 */ 	sll	$a1,$s0,0x10
/*  f16ab40:	00055403 */ 	sra	$t2,$a1,0x10
/*  f16ab44:	01402825 */ 	move	$a1,$t2
/*  f16ab48:	8c845870 */ 	lw	$a0,0x5870($a0)
/*  f16ab4c:	00003025 */ 	move	$a2,$zero
/*  f16ab50:	02e03825 */ 	move	$a3,$s7
/*  f16ab54:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f16ab58:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f16ab5c:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f16ab60:	0c004230 */ 	jal	sndStart
/*  f16ab64:	afb7001c */ 	sw	$s7,0x1c($sp)
/*  f16ab68:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f16ab6c:	2861000f */ 	slti	$at,$v1,0xf
.JF0f16ab70:
/*  f16ab70:	10200026 */ 	beqz	$at,.JF0f16ac0c
/*  f16ab74:	2419001e */ 	li	$t9,0x1e
/*  f16ab78:	2401000f */ 	li	$at,0xf
/*  f16ab7c:	00033080 */ 	sll	$a2,$v1,0x2
/*  f16ab80:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f16ab84:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16ab88:	00c33023 */ 	subu	$a2,$a2,$v1
/*  f16ab8c:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16ab90:	00c33021 */ 	addu	$a2,$a2,$v1
/*  f16ab94:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16ab98:	00c1001a */ 	div	$zero,$a2,$at
/*  f16ab9c:	44833000 */ 	mtc1	$v1,$f6
/*  f16aba0:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16aba4:	c42a8774 */ 	lwc1	$f10,-0x788c($at)
/*  f16aba8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f16abac:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16abb0:	c4328778 */ 	lwc1	$f18,-0x7888($at)
/*  f16abb4:	00003012 */ 	mflo	$a2
/*  f16abb8:	02602025 */ 	move	$a0,$s3
/*  f16abbc:	2405ffff */ 	li	$a1,-1
/*  f16abc0:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f16abc4:	46128000 */ 	add.s	$f0,$f16,$f18
/*  f16abc8:	44070000 */ 	mfc1	$a3,$f0
/*  f16abcc:	0fc50bfc */ 	jal	bviewRenderZoomBlur
/*  f16abd0:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f16abd4:	8e4d0460 */ 	lw	$t5,0x460($s2)
/*  f16abd8:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16abdc:	c428877c */ 	lwc1	$f8,-0x7884($at)
/*  f16abe0:	448d2000 */ 	mtc1	$t5,$f4
/*  f16abe4:	00402025 */ 	move	$a0,$v0
/*  f16abe8:	240500ff */ 	li	$a1,0xff
/*  f16abec:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f16abf0:	240600ff */ 	li	$a2,0xff
/*  f16abf4:	240700ff */ 	li	$a3,0xff
/*  f16abf8:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f16abfc:	0fc2f033 */ 	jal	playerDrawFade
/*  f16ac00:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f16ac04:	10000029 */ 	b	.JF0f16acac
/*  f16ac08:	00409825 */ 	move	$s3,$v0
.JF0f16ac0c:
/*  f16ac0c:	2401000f */ 	li	$at,0xf
/*  f16ac10:	03231023 */ 	subu	$v0,$t9,$v1
/*  f16ac14:	00023080 */ 	sll	$a2,$v0,0x2
/*  f16ac18:	00c23023 */ 	subu	$a2,$a2,$v0
/*  f16ac1c:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16ac20:	00c23023 */ 	subu	$a2,$a2,$v0
/*  f16ac24:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16ac28:	00c23021 */ 	addu	$a2,$a2,$v0
/*  f16ac2c:	00063080 */ 	sll	$a2,$a2,0x2
/*  f16ac30:	00c1001a */ 	div	$zero,$a2,$at
/*  f16ac34:	44828000 */ 	mtc1	$v0,$f16
/*  f16ac38:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16ac3c:	c4248780 */ 	lwc1	$f4,-0x7880($at)
/*  f16ac40:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f16ac44:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16ac48:	c4288784 */ 	lwc1	$f8,-0x787c($at)
/*  f16ac4c:	00003012 */ 	mflo	$a2
/*  f16ac50:	02602025 */ 	move	$a0,$s3
/*  f16ac54:	2405ffff */ 	li	$a1,-1
/*  f16ac58:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f16ac5c:	46083000 */ 	add.s	$f0,$f6,$f8
/*  f16ac60:	44070000 */ 	mfc1	$a3,$f0
/*  f16ac64:	0fc50bfc */ 	jal	bviewRenderZoomBlur
/*  f16ac68:	e7a00010 */ 	swc1	$f0,0x10($sp)
/*  f16ac6c:	8e4c0460 */ 	lw	$t4,0x460($s2)
/*  f16ac70:	3c0141f0 */ 	lui	$at,0x41f0
/*  f16ac74:	44815000 */ 	mtc1	$at,$f10
/*  f16ac78:	448c8000 */ 	mtc1	$t4,$f16
/*  f16ac7c:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16ac80:	c4268788 */ 	lwc1	$f6,-0x7878($at)
/*  f16ac84:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f16ac88:	00402025 */ 	move	$a0,$v0
/*  f16ac8c:	240500ff */ 	li	$a1,0xff
/*  f16ac90:	240600ff */ 	li	$a2,0xff
/*  f16ac94:	240700ff */ 	li	$a3,0xff
/*  f16ac98:	46125101 */ 	sub.s	$f4,$f10,$f18
/*  f16ac9c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f16aca0:	0fc2f033 */ 	jal	playerDrawFade
/*  f16aca4:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f16aca8:	00409825 */ 	move	$s3,$v0
.JF0f16acac:
/*  f16acac:	8e4e028c */ 	lw	$t6,0x28c($s2)
/*  f16acb0:	55c0000c */ 	bnezl	$t6,.JF0f16ace4
/*  f16acb4:	8e430460 */ 	lw	$v1,0x460($s2)
/*  f16acb8:	8e4f0464 */ 	lw	$t7,0x464($s2)
/*  f16acbc:	51e00006 */ 	beqzl	$t7,.JF0f16acd8
/*  f16acc0:	8e4d0460 */ 	lw	$t5,0x460($s2)
/*  f16acc4:	8e4a0460 */ 	lw	$t2,0x460($s2)
/*  f16acc8:	25580001 */ 	addiu	$t8,$t2,0x1
/*  f16accc:	10000004 */ 	b	.JF0f16ace0
/*  f16acd0:	ae580460 */ 	sw	$t8,0x460($s2)
/*  f16acd4:	8e4d0460 */ 	lw	$t5,0x460($s2)
.JF0f16acd8:
/*  f16acd8:	25b9ffff */ 	addiu	$t9,$t5,-1
/*  f16acdc:	ae590460 */ 	sw	$t9,0x460($s2)
.JF0f16ace0:
/*  f16ace0:	8e430460 */ 	lw	$v1,0x460($s2)
.JF0f16ace4:
/*  f16ace4:	2861001f */ 	slti	$at,$v1,0x1f
/*  f16ace8:	14200004 */ 	bnez	$at,.JF0f16acfc
/*  f16acec:	00000000 */ 	nop
/*  f16acf0:	2403001e */ 	li	$v1,0x1e
/*  f16acf4:	10000005 */ 	b	.JF0f16ad0c
/*  f16acf8:	ae430460 */ 	sw	$v1,0x460($s2)
.JF0f16acfc:
/*  f16acfc:	04630004 */ 	bgezl	$v1,.JF0f16ad10
/*  f16ad00:	28610010 */ 	slti	$at,$v1,0x10
/*  f16ad04:	ae400460 */ 	sw	$zero,0x460($s2)
/*  f16ad08:	00001825 */ 	move	$v1,$zero
.JF0f16ad0c:
/*  f16ad0c:	28610010 */ 	slti	$at,$v1,0x10
.JF0f16ad10:
/*  f16ad10:	54200004 */ 	bnezl	$at,.JF0f16ad24
/*  f16ad14:	ae400468 */ 	sw	$zero,0x468($s2)
/*  f16ad18:	10000002 */ 	b	.JF0f16ad24
/*  f16ad1c:	ae5e0468 */ 	sw	$s8,0x468($s2)
/*  f16ad20:	ae400468 */ 	sw	$zero,0x468($s2)
.JF0f16ad24:
/*  f16ad24:	52800009 */ 	beqzl	$s4,.JF0f16ad4c
/*  f16ad28:	8e4c02ac */ 	lw	$t4,0x2ac($s2)
/*  f16ad2c:	0fc523d5 */ 	jal	bviewClearBlur
/*  f16ad30:	00000000 */ 	nop
/*  f16ad34:	02602025 */ 	move	$a0,$s3
/*  f16ad38:	2405ffff */ 	li	$a1,-1
/*  f16ad3c:	0fc50a0e */ 	jal	bviewRenderMotionBlur
/*  f16ad40:	02803025 */ 	move	$a2,$s4
/*  f16ad44:	00409825 */ 	move	$s3,$v0
/*  f16ad48:	8e4c02ac */ 	lw	$t4,0x2ac($s2)
.JF0f16ad4c:
/*  f16ad4c:	24010006 */ 	li	$at,0x6
/*  f16ad50:	15810031 */ 	bne	$t4,$at,.JF0f16ae18
/*  f16ad54:	00000000 */ 	nop
/*  f16ad58:	0fc2ee2e */ 	jal	playerGetCutsceneBlurFrac
/*  f16ad5c:	00000000 */ 	nop
/*  f16ad60:	44808000 */ 	mtc1	$zero,$f16
/*  f16ad64:	3c01437f */ 	lui	$at,0x437f
/*  f16ad68:	4600803c */ 	c.lt.s	$f16,$f0
/*  f16ad6c:	00000000 */ 	nop
/*  f16ad70:	45000029 */ 	bc1f	.JF0f16ae18
/*  f16ad74:	00000000 */ 	nop
/*  f16ad78:	44815000 */ 	mtc1	$at,$f10
/*  f16ad7c:	24060001 */ 	li	$a2,0x1
/*  f16ad80:	3c014f00 */ 	lui	$at,0x4f00
/*  f16ad84:	460a0482 */ 	mul.s	$f18,$f0,$f10
/*  f16ad88:	02602025 */ 	move	$a0,$s3
/*  f16ad8c:	2405ff00 */ 	li	$a1,-256
/*  f16ad90:	444ef800 */ 	cfc1	$t6,$31
/*  f16ad94:	44c6f800 */ 	ctc1	$a2,$31
/*  f16ad98:	00000000 */ 	nop
/*  f16ad9c:	46009124 */ 	cvt.w.s	$f4,$f18
/*  f16ada0:	4446f800 */ 	cfc1	$a2,$31
/*  f16ada4:	00000000 */ 	nop
/*  f16ada8:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f16adac:	50c00013 */ 	beqzl	$a2,.JF0f16adfc
/*  f16adb0:	44062000 */ 	mfc1	$a2,$f4
/*  f16adb4:	44812000 */ 	mtc1	$at,$f4
/*  f16adb8:	24060001 */ 	li	$a2,0x1
/*  f16adbc:	46049101 */ 	sub.s	$f4,$f18,$f4
/*  f16adc0:	44c6f800 */ 	ctc1	$a2,$31
/*  f16adc4:	00000000 */ 	nop
/*  f16adc8:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f16adcc:	4446f800 */ 	cfc1	$a2,$31
/*  f16add0:	00000000 */ 	nop
/*  f16add4:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f16add8:	14c00005 */ 	bnez	$a2,.JF0f16adf0
/*  f16addc:	00000000 */ 	nop
/*  f16ade0:	44062000 */ 	mfc1	$a2,$f4
/*  f16ade4:	3c018000 */ 	lui	$at,0x8000
/*  f16ade8:	10000007 */ 	b	.JF0f16ae08
/*  f16adec:	00c13025 */ 	or	$a2,$a2,$at
.JF0f16adf0:
/*  f16adf0:	10000005 */ 	b	.JF0f16ae08
/*  f16adf4:	2406ffff */ 	li	$a2,-1
/*  f16adf8:	44062000 */ 	mfc1	$a2,$f4
.JF0f16adfc:
/*  f16adfc:	00000000 */ 	nop
/*  f16ae00:	04c0fffb */ 	bltz	$a2,.JF0f16adf0
/*  f16ae04:	00000000 */ 	nop
.JF0f16ae08:
/*  f16ae08:	44cef800 */ 	ctc1	$t6,$31
/*  f16ae0c:	0fc50a0e */ 	jal	bviewRenderMotionBlur
/*  f16ae10:	00000000 */ 	nop
/*  f16ae14:	00409825 */ 	move	$s3,$v0
.JF0f16ae18:
/*  f16ae18:	0fc47cb6 */ 	jal	debugGetMotionBlur
/*  f16ae1c:	00000000 */ 	nop
/*  f16ae20:	145e0006 */ 	bne	$v0,$s8,.JF0f16ae3c
/*  f16ae24:	02602025 */ 	move	$a0,$s3
/*  f16ae28:	2405ff00 */ 	li	$a1,-256
/*  f16ae2c:	0fc50a0e */ 	jal	bviewRenderMotionBlur
/*  f16ae30:	24060080 */ 	li	$a2,0x80
/*  f16ae34:	10000014 */ 	b	.JF0f16ae88
/*  f16ae38:	00409825 */ 	move	$s3,$v0
.JF0f16ae3c:
/*  f16ae3c:	0fc47cb6 */ 	jal	debugGetMotionBlur
/*  f16ae40:	00000000 */ 	nop
/*  f16ae44:	24010002 */ 	li	$at,0x2
/*  f16ae48:	14410006 */ 	bne	$v0,$at,.JF0f16ae64
/*  f16ae4c:	02602025 */ 	move	$a0,$s3
/*  f16ae50:	2405ff00 */ 	li	$a1,-256
/*  f16ae54:	0fc50a0e */ 	jal	bviewRenderMotionBlur
/*  f16ae58:	240600c0 */ 	li	$a2,0xc0
/*  f16ae5c:	1000000a */ 	b	.JF0f16ae88
/*  f16ae60:	00409825 */ 	move	$s3,$v0
.JF0f16ae64:
/*  f16ae64:	0fc47cb6 */ 	jal	debugGetMotionBlur
/*  f16ae68:	00000000 */ 	nop
/*  f16ae6c:	24010003 */ 	li	$at,0x3
/*  f16ae70:	14410005 */ 	bne	$v0,$at,.JF0f16ae88
/*  f16ae74:	02602025 */ 	move	$a0,$s3
/*  f16ae78:	2405ff00 */ 	li	$a1,-256
/*  f16ae7c:	0fc50a0e */ 	jal	bviewRenderMotionBlur
/*  f16ae80:	240600e6 */ 	li	$a2,0xe6
/*  f16ae84:	00409825 */ 	move	$s3,$v0
.JF0f16ae88:
/*  f16ae88:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f16ae8c:	24010003 */ 	li	$at,0x3
/*  f16ae90:	92031bfc */ 	lbu	$v1,0x1bfc($s0)
/*  f16ae94:	1860003c */ 	blez	$v1,.JF0f16af88
/*  f16ae98:	00000000 */ 	nop
/*  f16ae9c:	14610002 */ 	bne	$v1,$at,.JF0f16aea8
/*  f16aea0:	00008825 */ 	move	$s1,$zero
/*  f16aea4:	241100ff */ 	li	$s1,0xff
.JF0f16aea8:
/*  f16aea8:	56a30009 */ 	bnel	$s5,$v1,.JF0f16aed0
/*  f16aeac:	24010002 */ 	li	$at,0x2
/*  f16aeb0:	92021bfd */ 	lbu	$v0,0x1bfd($s0)
/*  f16aeb4:	28410010 */ 	slti	$at,$v0,0x10
/*  f16aeb8:	50200005 */ 	beqzl	$at,.JF0f16aed0
/*  f16aebc:	24010002 */ 	li	$at,0x2
/*  f16aec0:	00028823 */ 	negu	$s1,$v0
/*  f16aec4:	00117900 */ 	sll	$t7,$s1,0x4
/*  f16aec8:	25f100f0 */ 	addiu	$s1,$t7,0xf0
/*  f16aecc:	24010002 */ 	li	$at,0x2
.JF0f16aed0:
/*  f16aed0:	1461000b */ 	bne	$v1,$at,.JF0f16af00
/*  f16aed4:	00000000 */ 	nop
/*  f16aed8:	92021bfd */ 	lbu	$v0,0x1bfd($s0)
/*  f16aedc:	28410021 */ 	slti	$at,$v0,0x21
/*  f16aee0:	54200004 */ 	bnezl	$at,.JF0f16aef4
/*  f16aee4:	24010030 */ 	li	$at,0x30
/*  f16aee8:	00028900 */ 	sll	$s1,$v0,0x4
/*  f16aeec:	2631fe00 */ 	addiu	$s1,$s1,-512
/*  f16aef0:	24010030 */ 	li	$at,0x30
.JF0f16aef4:
/*  f16aef4:	14410002 */ 	bne	$v0,$at,.JF0f16af00
/*  f16aef8:	00000000 */ 	nop
/*  f16aefc:	241100ff */ 	li	$s1,0xff
.JF0f16af00:
/*  f16af00:	12200021 */ 	beqz	$s1,.JF0f16af88
/*  f16af04:	00000000 */ 	nop
/*  f16af08:	0fc54b55 */ 	jal	func0f153628
/*  f16af0c:	02602025 */ 	move	$a0,$s3
/*  f16af10:	0c002f29 */ 	jal	viGetViewLeft
/*  f16af14:	00409825 */ 	move	$s3,$v0
/*  f16af18:	0c002f2d */ 	jal	viGetViewTop
/*  f16af1c:	a7a20072 */ 	sh	$v0,0x72($sp)
/*  f16af20:	00028400 */ 	sll	$s0,$v0,0x10
/*  f16af24:	00105403 */ 	sra	$t2,$s0,0x10
/*  f16af28:	0c002f29 */ 	jal	viGetViewLeft
/*  f16af2c:	01408025 */ 	move	$s0,$t2
/*  f16af30:	0c002f0b */ 	jal	viGetViewWidth
/*  f16af34:	a7a20076 */ 	sh	$v0,0x76($sp)
/*  f16af38:	0c002f2d */ 	jal	viGetViewTop
/*  f16af3c:	a7a2008e */ 	sh	$v0,0x8e($sp)
/*  f16af40:	0c002f0f */ 	jal	viGetViewHeight
/*  f16af44:	a7a20090 */ 	sh	$v0,0x90($sp)
/*  f16af48:	87b90090 */ 	lh	$t9,0x90($sp)
/*  f16af4c:	87b8008e */ 	lh	$t8,0x8e($sp)
/*  f16af50:	87ad0076 */ 	lh	$t5,0x76($sp)
/*  f16af54:	2401ff00 */ 	li	$at,-256
/*  f16af58:	02216025 */ 	or	$t4,$s1,$at
/*  f16af5c:	00595821 */ 	addu	$t3,$v0,$t9
/*  f16af60:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f16af64:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f16af68:	02602025 */ 	move	$a0,$s3
/*  f16af6c:	87a50072 */ 	lh	$a1,0x72($sp)
/*  f16af70:	02003025 */ 	move	$a2,$s0
/*  f16af74:	0fc54c68 */ 	jal	func0f153a34
/*  f16af78:	030d3821 */ 	addu	$a3,$t8,$t5
/*  f16af7c:	0fc54bb7 */ 	jal	func0f153780
/*  f16af80:	00402025 */ 	move	$a0,$v0
/*  f16af84:	00409825 */ 	move	$s3,$v0
.JF0f16af88:
/*  f16af88:	0fc61795 */ 	jal	scenarioRenderHud
/*  f16af8c:	02602025 */ 	move	$a0,$s3
/*  f16af90:	0fc5a27a */ 	jal	lvRenderFade
/*  f16af94:	00402025 */ 	move	$a0,$v0
/*  f16af98:	3c0e8009 */ 	lui	$t6,0x8009
/*  f16af9c:	91ce8e74 */ 	lbu	$t6,-0x718c($t6)
/*  f16afa0:	00409825 */ 	move	$s3,$v0
/*  f16afa4:	11c00004 */ 	beqz	$t6,.JF0f16afb8
/*  f16afa8:	00000000 */ 	nop
/*  f16afac:	0fc68e8b */ 	jal	frRenderHud
/*  f16afb0:	00402025 */ 	move	$a0,$v0
/*  f16afb4:	00409825 */ 	move	$s3,$v0
.JF0f16afb8:
/*  f16afb8:	0fc47ca2 */ 	jal	debugGetTilesDebugMode
/*  f16afbc:	00000000 */ 	nop
/*  f16afc0:	14400013 */ 	bnez	$v0,.JF0f16b010
/*  f16afc4:	00000000 */ 	nop
/*  f16afc8:	0fc47ca4 */ 	jal	debugGetPadsDebugMode
/*  f16afcc:	00000000 */ 	nop
/*  f16afd0:	1440000f */ 	bnez	$v0,.JF0f16b010
/*  f16afd4:	00000000 */ 	nop
/*  f16afd8:	0fc47caa */ 	jal	debug0f11eea8
/*  f16afdc:	00000000 */ 	nop
/*  f16afe0:	1440000b */ 	bnez	$v0,.JF0f16b010
/*  f16afe4:	00000000 */ 	nop
/*  f16afe8:	0fc47ce0 */ 	jal	debug0f11ef80
/*  f16afec:	00000000 */ 	nop
/*  f16aff0:	14400007 */ 	bnez	$v0,.JF0f16b010
/*  f16aff4:	00000000 */ 	nop
/*  f16aff8:	0fc47cde */ 	jal	debugIsChrStatsEnabled
/*  f16affc:	00000000 */ 	nop
/*  f16b000:	14400003 */ 	bnez	$v0,.JF0f16b010
/*  f16b004:	00000000 */ 	nop
/*  f16b008:	0fc47c90 */ 	jal	debug0f11ee40
/*  f16b00c:	00000000 */ 	nop
.JF0f16b010:
/*  f16b010:	0fc49e36 */ 	jal	func0f1274d8
/*  f16b014:	02602025 */ 	move	$a0,$s3
/*  f16b018:	0fc40547 */ 	jal	amRender
/*  f16b01c:	00402025 */ 	move	$a0,$v0
/*  f16b020:	3c013f80 */ 	lui	$at,0x3f80
/*  f16b024:	44816000 */ 	mtc1	$at,$f12
/*  f16b028:	0c0059ba */ 	jal	mtx00016748
/*  f16b02c:	00409825 */ 	move	$s3,$v0
/*  f16b030:	8e4f0284 */ 	lw	$t7,0x284($s2)
/*  f16b034:	8dea1c50 */ 	lw	$t2,0x1c50($t7)
/*  f16b038:	000ac7c2 */ 	srl	$t8,$t2,0x1f
/*  f16b03c:	53000005 */ 	beqzl	$t8,.JF0f16b054
/*  f16b040:	8e4d0288 */ 	lw	$t5,0x288($s2)
/*  f16b044:	0fc3f249 */ 	jal	menuRender
/*  f16b048:	02602025 */ 	move	$a0,$s3
/*  f16b04c:	00409825 */ 	move	$s3,$v0
/*  f16b050:	8e4d0288 */ 	lw	$t5,0x288($s2)
.JF0f16b054:
/*  f16b054:	0c0059ba */ 	jal	mtx00016748
/*  f16b058:	c5ac0074 */ 	lwc1	$f12,0x74($t5)
/*  f16b05c:	8e590314 */ 	lw	$t9,0x314($s2)
/*  f16b060:	53200005 */ 	beqzl	$t9,.JF0f16b078
/*  f16b064:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f16b068:	0fc627dc */ 	jal	mpRenderModalText
/*  f16b06c:	02602025 */ 	move	$a0,$s3
/*  f16b070:	00409825 */ 	move	$s3,$v0
/*  f16b074:	8e4b0284 */ 	lw	$t3,0x284($s2)
.JF0f16b078:
/*  f16b078:	916c19b3 */ 	lbu	$t4,0x19b3($t3)
/*  f16b07c:	11800003 */ 	beqz	$t4,.JF0f16b08c
/*  f16b080:	00000000 */ 	nop
/*  f16b084:	0fc2e0d7 */ 	jal	playerStartNewLife
/*  f16b088:	00000000 */ 	nop
.JF0f16b08c:
/*  f16b08c:	0fc4f253 */ 	jal	func0f13c54c
/*  f16b090:	00000000 */ 	nop
/*  f16b094:	8e4e0298 */ 	lw	$t6,0x298($s2)
/*  f16b098:	05c10004 */ 	bgez	$t6,.JF0f16b0ac
/*  f16b09c:	00000000 */ 	nop
/*  f16b0a0:	8e4f029c */ 	lw	$t7,0x29c($s2)
/*  f16b0a4:	05e2000a */ 	bltzl	$t7,.JF0f16b0d0
/*  f16b0a8:	8fb00064 */ 	lw	$s0,0x64($sp)
.JF0f16b0ac:
/*  f16b0ac:	0fc2f557 */ 	jal	playerHasSharedViewport
/*  f16b0b0:	00000000 */ 	nop
/*  f16b0b4:	50400006 */ 	beqzl	$v0,.JF0f16b0d0
/*  f16b0b8:	8fb00064 */ 	lw	$s0,0x64($sp)
/*  f16b0bc:	8e4a028c */ 	lw	$t2,0x28c($s2)
/*  f16b0c0:	51400003 */ 	beqzl	$t2,.JF0f16b0d0
/*  f16b0c4:	8fb00064 */ 	lw	$s0,0x64($sp)
/*  f16b0c8:	8fb30108 */ 	lw	$s3,0x108($sp)
/*  f16b0cc:	8fb00064 */ 	lw	$s0,0x64($sp)
.JF0f16b0d0:
/*  f16b0d0:	8fb8010c */ 	lw	$t8,0x10c($sp)
/*  f16b0d4:	5618fb60 */ 	bnel	$s0,$t8,.JF0f169e58
/*  f16b0d8:	8fac0104 */ 	lw	$t4,0x104($sp)
.JF0f16b0dc:
/*  f16b0dc:	824d04d3 */ 	lb	$t5,0x4d3($s2)
.JF0f16b0e0:
/*  f16b0e0:	3c014080 */ 	lui	$at,0x4080
/*  f16b0e4:	4481a000 */ 	mtc1	$at,$f20
/*  f16b0e8:	11a00013 */ 	beqz	$t5,.JF0f16b138
/*  f16b0ec:	2417ffff */ 	li	$s7,-1
/*  f16b0f0:	825904d6 */ 	lb	$t9,0x4d6($s2)
/*  f16b0f4:	53200011 */ 	beqzl	$t9,.JF0f16b13c
/*  f16b0f8:	824f04d3 */ 	lb	$t7,0x4d3($s2)
/*  f16b0fc:	824b04d7 */ 	lb	$t3,0x4d7($s2)
/*  f16b100:	a24004d3 */ 	sb	$zero,0x4d3($s2)
/*  f16b104:	a24004d6 */ 	sb	$zero,0x4d6($s2)
/*  f16b108:	51600004 */ 	beqzl	$t3,.JF0f16b11c
/*  f16b10c:	824c04d4 */ 	lb	$t4,0x4d4($s2)
/*  f16b110:	a25704d4 */ 	sb	$s7,0x4d4($s2)
/*  f16b114:	a24004d5 */ 	sb	$zero,0x4d5($s2)
/*  f16b118:	824c04d4 */ 	lb	$t4,0x4d4($s2)
.JF0f16b11c:
/*  f16b11c:	05830007 */ 	bgezl	$t4,.JF0f16b13c
/*  f16b120:	824f04d3 */ 	lb	$t7,0x4d3($s2)
/*  f16b124:	824e04d5 */ 	lb	$t6,0x4d5($s2)
/*  f16b128:	5dc00004 */ 	bgtzl	$t6,.JF0f16b13c
/*  f16b12c:	824f04d3 */ 	lb	$t7,0x4d3($s2)
/*  f16b130:	0c003a3f */ 	jal	mainChangeToStage
/*  f16b134:	2404005a */ 	li	$a0,0x5a
.JF0f16b138:
/*  f16b138:	824f04d3 */ 	lb	$t7,0x4d3($s2)
.JF0f16b13c:
/*  f16b13c:	55e00042 */ 	bnezl	$t7,.JF0f16b248
/*  f16b140:	02608825 */ 	move	$s1,$s3
/*  f16b144:	824a04d4 */ 	lb	$t2,0x4d4($s2)
/*  f16b148:	0542003f */ 	bltzl	$t2,.JF0f16b248
/*  f16b14c:	02608825 */ 	move	$s1,$s3
/*  f16b150:	825804d5 */ 	lb	$t8,0x4d5($s2)
/*  f16b154:	5b00003c */ 	blezl	$t8,.JF0f16b248
/*  f16b158:	02608825 */ 	move	$s1,$s3
/*  f16b15c:	0fc37bed */ 	jal	hudmsgRemoveAll
/*  f16b160:	00000000 */ 	nop
/*  f16b164:	824d04d4 */ 	lb	$t5,0x4d4($s2)
/*  f16b168:	2414000c */ 	li	$s4,0xc
/*  f16b16c:	3c118007 */ 	lui	$s1,0x8007
/*  f16b170:	01b40019 */ 	multu	$t5,$s4
/*  f16b174:	26313cb0 */ 	addiu	$s1,$s1,0x3cb0
/*  f16b178:	3c10800a */ 	lui	$s0,0x800a
/*  f16b17c:	2610e6e8 */ 	addiu	$s0,$s0,-6424
/*  f16b180:	920e0003 */ 	lbu	$t6,0x3($s0)
/*  f16b184:	24040001 */ 	li	$a0,0x1
/*  f16b188:	31caff7f */ 	andi	$t2,$t6,0xff7f
/*  f16b18c:	315800bf */ 	andi	$t8,$t2,0xbf
/*  f16b190:	0000c812 */ 	mflo	$t9
/*  f16b194:	02395821 */ 	addu	$t3,$s1,$t9
/*  f16b198:	8d6c0004 */ 	lw	$t4,0x4($t3)
/*  f16b19c:	a20a0003 */ 	sb	$t2,0x3($s0)
/*  f16b1a0:	ae400314 */ 	sw	$zero,0x314($s2)
/*  f16b1a4:	ae400318 */ 	sw	$zero,0x318($s2)
/*  f16b1a8:	ae400294 */ 	sw	$zero,0x294($s2)
/*  f16b1ac:	ae570298 */ 	sw	$s7,0x298($s2)
/*  f16b1b0:	ae57029c */ 	sw	$s7,0x29c($s2)
/*  f16b1b4:	a2180003 */ 	sb	$t8,0x3($s0)
/*  f16b1b8:	0fc06c4c */ 	jal	setNumPlayers
/*  f16b1bc:	a24c04d2 */ 	sb	$t4,0x4d2($s2)
/*  f16b1c0:	0fc06e49 */ 	jal	titleSetNextMode
/*  f16b1c4:	24040005 */ 	li	$a0,0x5
/*  f16b1c8:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f16b1cc:	00002025 */ 	move	$a0,$zero
/*  f16b1d0:	31b9ff01 */ 	andi	$t9,$t5,0xff01
/*  f16b1d4:	0fc5b3d2 */ 	jal	lvSetDifficulty
/*  f16b1d8:	a2190000 */ 	sb	$t9,0x0($s0)
/*  f16b1dc:	824b04d4 */ 	lb	$t3,0x4d4($s2)
/*  f16b1e0:	01740019 */ 	multu	$t3,$s4
/*  f16b1e4:	00006012 */ 	mflo	$t4
/*  f16b1e8:	022c1021 */ 	addu	$v0,$s1,$t4
/*  f16b1ec:	844e0002 */ 	lh	$t6,0x2($v0)
/*  f16b1f0:	84440000 */ 	lh	$a0,0x0($v0)
/*  f16b1f4:	a20e0002 */ 	sb	$t6,0x2($s0)
/*  f16b1f8:	0fc070bd */ 	jal	titleSetNextStage
/*  f16b1fc:	a2040001 */ 	sb	$a0,0x1($s0)
/*  f16b200:	824f04d4 */ 	lb	$t7,0x4d4($s2)
/*  f16b204:	01f40019 */ 	multu	$t7,$s4
/*  f16b208:	00005012 */ 	mflo	$t2
/*  f16b20c:	022ac021 */ 	addu	$t8,$s1,$t2
/*  f16b210:	0c003a3f */ 	jal	mainChangeToStage
/*  f16b214:	87040000 */ 	lh	$a0,0x0($t8)
/*  f16b218:	824d04d5 */ 	lb	$t5,0x4d5($s2)
/*  f16b21c:	25b9ffff */ 	addiu	$t9,$t5,-1
/*  f16b220:	a25904d5 */ 	sb	$t9,0x4d5($s2)
/*  f16b224:	824b04d5 */ 	lb	$t3,0x4d5($s2)
/*  f16b228:	59600006 */ 	blezl	$t3,.JF0f16b244
/*  f16b22c:	a25704d4 */ 	sb	$s7,0x4d4($s2)
/*  f16b230:	824c04d4 */ 	lb	$t4,0x4d4($s2)
/*  f16b234:	258e0001 */ 	addiu	$t6,$t4,0x1
/*  f16b238:	10000002 */ 	b	.JF0f16b244
/*  f16b23c:	a24e04d4 */ 	sb	$t6,0x4d4($s2)
/*  f16b240:	a25704d4 */ 	sb	$s7,0x4d4($s2)
.JF0f16b244:
/*  f16b244:	02608825 */ 	move	$s1,$s3
.JF0f16b248:
/*  f16b248:	3c0fed00 */ 	lui	$t7,0xed00
/*  f16b24c:	ae2f0000 */ 	sw	$t7,0x0($s1)
/*  f16b250:	0c002eeb */ 	jal	viGetWidth
/*  f16b254:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f16b258:	00028400 */ 	sll	$s0,$v0,0x10
/*  f16b25c:	00105403 */ 	sra	$t2,$s0,0x10
/*  f16b260:	0c002eef */ 	jal	viGetHeight
/*  f16b264:	01408025 */ 	move	$s0,$t2
/*  f16b268:	44823000 */ 	mtc1	$v0,$f6
/*  f16b26c:	44909000 */ 	mtc1	$s0,$f18
/*  f16b270:	02601025 */ 	move	$v0,$s3
/*  f16b274:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f16b278:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f16b27c:	46144402 */ 	mul.s	$f16,$f8,$f20
/*  f16b280:	00000000 */ 	nop
/*  f16b284:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f16b288:	4600828d */ 	trunc.w.s	$f10,$f16
/*  f16b28c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f16b290:	440d5000 */ 	mfc1	$t5,$f10
/*  f16b294:	440c4000 */ 	mfc1	$t4,$f8
/*  f16b298:	31b90fff */ 	andi	$t9,$t5,0xfff
/*  f16b29c:	318e0fff */ 	andi	$t6,$t4,0xfff
/*  f16b2a0:	000e7b00 */ 	sll	$t7,$t6,0xc
/*  f16b2a4:	032f5025 */ 	or	$t2,$t9,$t7
/*  f16b2a8:	ae2a0004 */ 	sw	$t2,0x4($s1)
/*  f16b2ac:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f16b2b0:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f16b2b4:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f16b2b8:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f16b2bc:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f16b2c0:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f16b2c4:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f16b2c8:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f16b2cc:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f16b2d0:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f16b2d4:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f16b2d8:	03e00008 */ 	jr	$ra
/*  f16b2dc:	27bd0170 */ 	addiu	$sp,$sp,0x170
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
Gfx *lvRender(Gfx *gdl)
{
	gSPSegment(gdl++, 0x00, 0x00000000);

#if VERSION >= VERSION_NTSC_1_0
	func0f0d5a7c();
#endif

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

#if PAL
		viSetMode(VIMODE_LO);
		viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
		viSetSize(playerGetFbWidth(), playerGetFbHeight());
		viSetBufSize(playerGetFbWidth(), playerGetFbHeight());
		viSetViewSize(playerGetFbWidth(), playerGetFbHeight());
#else
		viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
#endif

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
#if VERSION >= VERSION_NTSC_1_0
		bool forcesingleplayer = (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
			&& playerHasSharedViewport();
#else
		bool forcesingleplayer = (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
			&& ((g_InCutscene && !g_MainIsEndscreen) || menuGetRoot() == MENUROOT_COOPCONTINUE);
#endif
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
				setCurrentPlayerNum(playermgrGetPlayerAtOrder(i));
				islastplayer = playercount == nextplayernum;
			}

			// Calculate bluramount - this will be used later
			if (g_Vars.tickmode != TICKMODE_CUTSCENE) {
				player = g_Vars.currentplayer;
				chr = player->prop->chr;

				if (chr->blurdrugamount > 0
						&& !g_Vars.currentplayer->invincible
						&& !g_Vars.currentplayer->training) {
					bluramount = (chr->blurdrugamount * 130) / TICKS(5000) + 100;

					if (bluramount > 230) {
						bluramount = 230;
					}

					if (chr->blurdrugamount > TICKS(5000)) {
						chr->blurdrugamount = TICKS(5000);
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
			env0f1657f8();
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

#if VERSION == VERSION_NTSC_BETA || VERSION == VERSION_PAL_BETA
					gdl = lvRenderManPosIfEnabled(gdl);
#endif
				} else {
					gdl = func0f0aeed8(gdl);

					if (g_Vars.currentplayer->visionmode != VISIONMODE_XRAY) {
						gdl = func0f15b114(gdl);
					}
				}

				if (g_DebugScreenshotRgb <= 0) {
					static struct sndstate *g_CutsceneStaticAudioHandle = NULL;
					static s32 g_CutsceneStaticTimer = 100;
					static u8 g_CutsceneStaticActive = false;
					bool cutscenehasstatic = false;
					u32 alpha;

					if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
						// This chunk of code is unreachable
						// (STAGE_TEST_OLD is not used)
#if VERSION < VERSION_PAL_BETA
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
#endif

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
									g_CutsceneStaticTimer = random() % TICKS(200) + TICKS(40);
									g_CutsceneStaticActive = false;
								}

								gdl = bviewRenderFilmLens(gdl, 0xffffffff, 0xffffffff);

								if (g_CutsceneStaticTimer < TICKS(15)) {
									if (g_CutsceneStaticActive == false) {
										g_CutsceneStaticActive = true;
										sndStart(var80095200, SFX_INFIL_STATIC_MEDIUM, NULL, -1, -1, -1, -1, -1);
									}

									cutscenestatic = 225 - g_CutsceneStaticTimer * PALUP(10);
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
							u32 slayerstatic = g_Vars.currentplayer->badrockettime * 255 / TICKS(90);

							if (slayerstatic > 255) {
								slayerstatic = 255;
							}

							gdl = bviewRenderStatic(gdl, 0x4fffffff, slayerstatic);
						}
					}

#if VERSION >= VERSION_NTSC_1_0
					if (g_Vars.currentplayer->visionmode == VISIONMODE_SLAYERROCKETSTATIC) {
						gdl = bviewRenderStatic(gdl, 0x4fffffff, 255);
						g_Vars.currentplayer->visionmode = VISIONMODE_NORMAL;
					}
#endif

					if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY
							&& g_Vars.tickmode != TICKMODE_CUTSCENE) {
						s32 xraything = 99;

						if (g_Vars.currentplayer->erasertime < TICKS(200)) {
#if VERSION >= VERSION_PAL_BETA
							xraything = 249 - ((g_Vars.currentplayer->erasertime * 180 / 50) >> 2);
#else
							xraything = 249 - (g_Vars.currentplayer->erasertime * 3 >> 2);
#endif
						}

						gdl = bviewRenderZoomBlur(gdl, 0xffffffff, xraything, 1.05f, 1.05f);
					}

					// Handle combat boosts
					if ((g_Vars.speedpillchange > 0 && g_Vars.speedpillchange < (PAL ? 26 : 30))
							|| (g_Vars.speedpillwant && !g_Vars.speedpillon)
							|| (!g_Vars.speedpillwant && g_Vars.speedpillon)) {
						if (g_Vars.speedpillchange == (PAL ? 26 : 30) && !g_Vars.speedpillwant) {
							sndStart(var80095200, lvGetSlowMotionType() ? SFX_JO_BOOST_ACTIVATE : SFX_ARGH_JO_02AD, 0, -1, -1, -1, -1, -1);
						}

						if (g_Vars.speedpillchange < (PAL ? 13 : 15)) {
							gdl = bviewRenderZoomBlur(gdl, 0xffffffff,
									g_Vars.speedpillchange * 180 / (PAL ? 13 : 15),
									(f32)g_Vars.speedpillchange * (PAL ? 0.023076923564076f : 0.02000000141561f) + 1.1f,
									(f32)g_Vars.speedpillchange * (PAL ? 0.023076923564076f : 0.02000000141561f) + 1.1f);
							gdl = playerDrawFade(gdl, 0xff, 0xff, 0xff,
									g_Vars.speedpillchange * (PAL ? 0.0076923076994717f : 0.0066666668280959f));
						} else {
							gdl = bviewRenderZoomBlur(gdl, 0xffffffff,
									((PAL ? 26 : 30) - g_Vars.speedpillchange) * 180 / (PAL ? 13 : 15),
									(f32)((PAL ? 26 : 30) - g_Vars.speedpillchange) * (PAL ? 0.023076923564076f : 0.02000000141561f) + 1.1f,
									(f32)((PAL ? 26 : 30) - g_Vars.speedpillchange) * (PAL ? 0.023076923564076f : 0.02000000141561f) + 1.1f);
							gdl = playerDrawFade(gdl, 0xff, 0xff, 0xff,
									((PAL ? 26.0f : 30.0f) - g_Vars.speedpillchange) * (PAL ? 0.0076923076994717f : 0.0066666668280959f));
						}

						if (g_Vars.currentplayernum == 0) {
							if (g_Vars.speedpillwant) {
								g_Vars.speedpillchange++;
							} else {
								g_Vars.speedpillchange--;
							}
						}

						if (g_Vars.speedpillchange > (PAL ? 26 : 30)) {
							g_Vars.speedpillchange = (PAL ? 26 : 30);
						} else if (g_Vars.speedpillchange < 0) {
							g_Vars.speedpillchange = 0;
						}
					}

					if (g_Vars.speedpillchange > (PAL ? 13 : 15)) {
						g_Vars.speedpillon = true;
					} else {
						g_Vars.speedpillon = false;
					}

					if (bluramount) {
						bviewClearBlur();
						gdl = bviewRenderMotionBlur(gdl, 0xffffffff, bluramount);
					}

					// Handle blur effect in cutscenes (Extraction intro?)
					if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
						f32 cutsceneblurfrac = playerGetCutsceneBlurFrac();

						if (cutsceneblurfrac > 0) {
#if VERSION < VERSION_PAL_BETA
							u32 stack;
#endif
							gdl = bviewRenderMotionBlur(gdl, 0xffffff00, cutsceneblurfrac * 255);
						}
					}

#if VERSION >= VERSION_PAL_FINAL
					if (bluramount);
					if (bluramount);
					if (bluramount);
#elif VERSION >= VERSION_NTSC_1_0
					if (bluramount);
					if (bluramount);
#else
					if (bluramount);
					if (bluramount);
					if (bluramount);
#endif

					if (debugGetMotionBlur() == 1) {
						gdl = bviewRenderMotionBlur(gdl, 0xffffff00, 128);
					} else if (debugGetMotionBlur() == 2) {
						gdl = bviewRenderMotionBlur(gdl, 0xffffff00, 192);
					} else if (debugGetMotionBlur() == 3) {
						gdl = bviewRenderMotionBlur(gdl, 0xffffff00, 230);
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

#if VERSION >= VERSION_NTSC_1_0
				gdl = scenarioRenderHud(gdl);
				gdl = lvRenderFade(gdl);
#else
				gdl = lvRenderFade(gdl);
				gdl = scenarioRenderHud(gdl);
#endif

				if (g_FrIsValidWeapon) {
					gdl = frRenderHud(gdl);
				}

				if (debugGetTilesDebugMode() != 0
						|| debugGetPadsDebugMode() != 0
						|| debug0f11eea8()
						|| debug0f11ef80()
						|| debugIsChrStatsEnabled()
						|| debug0f11ee40()) {
#if VERSION < VERSION_NTSC_1_0
					s16 spc8[21];
					s16 spb0[11];
					s16 sp9c[10];
					s32 j;

					sp9c[0] = g_Vars.currentplayer->memcamroom;
					sp9c[1] = -1;

					for (j = 0; sp9c[j] != -1; j++) {
						spc8[j] = sp9c[j];
					}

					spc8[j] = -1;

					for (j = 0; sp9c[j] != -1; j++) {
						roomGetNeighbours(sp9c[j], spb0, 10);
						roomsAppend(spb0, spc8, 20);
					}

					if (debugIsChrStatsEnabled()) {
						gdl = chrsRenderChrStats(gdl, spc8);
					}
#endif
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
#if VERSION >= VERSION_NTSC_1_0
					&& playerHasSharedViewport()
#else
					&& ((g_InCutscene && !g_MainIsEndscreen) || menuGetRoot() == MENUROOT_COOPCONTINUE)
#endif
					&& g_Vars.currentplayernum != 0) {
				gdl = savedgdl;
			}
		} // end of player loop
	} // end of stage if-statements

	if (g_Vars.autocutplaying && g_Vars.autocutfinished) {
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

	// Advance the cutscenes when autoplaying
	if (!g_Vars.autocutplaying && g_Vars.autocutgroupcur >= 0 && g_Vars.autocutgroupleft > 0) {
		hudmsgRemoveAll();

		g_Vars.autocutnum = g_Cutscenes[g_Vars.autocutgroupcur].scene;

#if VERSION < VERSION_NTSC_1_0
		if (mainGetStageNum() != g_Cutscenes[g_Vars.autocutgroupcur].stage)
#endif
		{
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
		}

		g_Vars.autocutgroupleft--;

		if (g_Vars.autocutgroupleft > 0) {
			g_Vars.autocutgroupcur++;
		} else {
			g_Vars.autocutgroupcur = -1;
		}
	}

	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, viGetWidth(), viGetHeight());

#if VERSION < VERSION_NTSC_1_0
	if ((u32)gdl < (u32)g_GfxBuffers[g_GfxActiveBufferIndex]
			|| (u32)gdl > (u32)g_GfxBuffers[g_GfxActiveBufferIndex + 1]) {
		crashSetMessage("lv.c Master DL overrun!");
		CRASH();
	}
#endif

	return gdl;
}
#endif

const char var7f1b7730[] = "fr: %d\n";

u32 g_CutsceneTime240_60 = 0;

#if VERSION >= VERSION_NTSC_1_0
u32 var800840a8 = 0;
u32 var800840ac = 0;
u32 var800840b0 = 0;
#else
u32 var80086930nb = 0;
u32 var800840a8 = 0;
u32 var800840ac = 0;
u32 var800840b0 = 0;
#endif

u32 var800840b4 = 0;
u32 var800840b8 = 0;
u32 var800840bc = 0;

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel lvUpdateSoloHandicaps
.late_rodata
glabel var7f1b878cjf
.word 0x3eb33333
.word 0x3e4ccccd
.word 0x3f19999a
.word 0x3f8ccccd
.word 0x3f333333
.word 0x3f266666
.word 0x3f19999a
.word 0x3e4ccccd
.word 0x3e4ccccd
.word 0x3f19999a
.word 0x3ef33334
.word 0x3f19999a
.word 0x3e4ccccd
.word 0x3f4ccccd
.word 0x3f19999a
.word 0x3f966666
.word 0x3e4ccccd
.word 0x3f8ccccd
.text
/*  f16b2e0:	3c02800a */ 	lui	$v0,0x800a
/*  f16b2e4:	2442a630 */ 	addiu	$v0,$v0,-22992
/*  f16b2e8:	8c43029c */ 	lw	$v1,0x29c($v0)
/*  f16b2ec:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f16b2f0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16b2f4:	04620081 */ 	bltzl	$v1,.JF0f16b4fc
/*  f16b2f8:	8c440298 */ 	lw	$a0,0x298($v0)
/*  f16b2fc:	3c028008 */ 	lui	$v0,0x8008
/*  f16b300:	8c424670 */ 	lw	$v0,0x4670($v0)
/*  f16b304:	24010001 */ 	li	$at,0x1
/*  f16b308:	1440002a */ 	bnez	$v0,.JF0f16b3b4
/*  f16b30c:	00000000 */ 	nop
/*  f16b310:	3c014000 */ 	lui	$at,0x4000
/*  f16b314:	44811000 */ 	mtc1	$at,$f2
/*  f16b318:	3c013f00 */ 	lui	$at,0x3f00
/*  f16b31c:	44816000 */ 	mtc1	$at,$f12
/*  f16b320:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f16b324:	44818000 */ 	mtc1	$at,$f16
/*  f16b328:	3c018007 */ 	lui	$at,0x8007
/*  f16b32c:	e4229898 */ 	swc1	$f2,-0x6768($at)
/*  f16b330:	3c018007 */ 	lui	$at,0x8007
/*  f16b334:	e422989c */ 	swc1	$f2,-0x6764($at)
/*  f16b338:	3c018007 */ 	lui	$at,0x8007
/*  f16b33c:	e42c98a0 */ 	swc1	$f12,-0x6760($at)
/*  f16b340:	3c018007 */ 	lui	$at,0x8007
/*  f16b344:	e42c98a4 */ 	swc1	$f12,-0x675c($at)
/*  f16b348:	3c018007 */ 	lui	$at,0x8007
/*  f16b34c:	e42298a8 */ 	swc1	$f2,-0x6758($at)
/*  f16b350:	3c018006 */ 	lui	$at,0x8006
/*  f16b354:	e42c2bf0 */ 	swc1	$f12,0x2bf0($at)
/*  f16b358:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b35c:	c424878c */ 	lwc1	$f4,-0x7874($at)
/*  f16b360:	3c018006 */ 	lui	$at,0x8006
/*  f16b364:	e4242bf4 */ 	swc1	$f4,0x2bf4($at)
/*  f16b368:	3c014080 */ 	lui	$at,0x4080
/*  f16b36c:	44813000 */ 	mtc1	$at,$f6
/*  f16b370:	3c018006 */ 	lui	$at,0x8006
/*  f16b374:	e4262bf8 */ 	swc1	$f6,0x2bf8($at)
/*  f16b378:	3c013e80 */ 	lui	$at,0x3e80
/*  f16b37c:	44814000 */ 	mtc1	$at,$f8
/*  f16b380:	3c018008 */ 	lui	$at,0x8008
/*  f16b384:	e428eaa8 */ 	swc1	$f8,-0x1558($at)
/*  f16b388:	3c018007 */ 	lui	$at,0x8007
/*  f16b38c:	e43097d0 */ 	swc1	$f16,-0x6830($at)
/*  f16b390:	3c014040 */ 	lui	$at,0x4040
/*  f16b394:	44815000 */ 	mtc1	$at,$f10
/*  f16b398:	3c018007 */ 	lui	$at,0x8007
/*  f16b39c:	e42a98ac */ 	swc1	$f10,-0x6754($at)
/*  f16b3a0:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b3a4:	c4328790 */ 	lwc1	$f18,-0x7870($at)
/*  f16b3a8:	3c018006 */ 	lui	$at,0x8006
/*  f16b3ac:	10000176 */ 	b	.JF0f16b988
/*  f16b3b0:	e4322bfc */ 	swc1	$f18,0x2bfc($at)
.JF0f16b3b4:
/*  f16b3b4:	14410029 */ 	bne	$v0,$at,.JF0f16b45c
/*  f16b3b8:	3c014000 */ 	lui	$at,0x4000
/*  f16b3bc:	44811000 */ 	mtc1	$at,$f2
/*  f16b3c0:	3c013f00 */ 	lui	$at,0x3f00
/*  f16b3c4:	44816000 */ 	mtc1	$at,$f12
/*  f16b3c8:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f16b3cc:	44818000 */ 	mtc1	$at,$f16
/*  f16b3d0:	3c018007 */ 	lui	$at,0x8007
/*  f16b3d4:	e4229898 */ 	swc1	$f2,-0x6768($at)
/*  f16b3d8:	3c018007 */ 	lui	$at,0x8007
/*  f16b3dc:	e430989c */ 	swc1	$f16,-0x6764($at)
/*  f16b3e0:	3c018007 */ 	lui	$at,0x8007
/*  f16b3e4:	e42c98a0 */ 	swc1	$f12,-0x6760($at)
/*  f16b3e8:	3c018007 */ 	lui	$at,0x8007
/*  f16b3ec:	e42c98a4 */ 	swc1	$f12,-0x675c($at)
/*  f16b3f0:	3c018007 */ 	lui	$at,0x8007
/*  f16b3f4:	e43098a8 */ 	swc1	$f16,-0x6758($at)
/*  f16b3f8:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b3fc:	c4248794 */ 	lwc1	$f4,-0x786c($at)
/*  f16b400:	3c018006 */ 	lui	$at,0x8006
/*  f16b404:	e4242bf0 */ 	swc1	$f4,0x2bf0($at)
/*  f16b408:	3c018006 */ 	lui	$at,0x8006
/*  f16b40c:	e42c2bf4 */ 	swc1	$f12,0x2bf4($at)
/*  f16b410:	3c014040 */ 	lui	$at,0x4040
/*  f16b414:	44813000 */ 	mtc1	$at,$f6
/*  f16b418:	3c018006 */ 	lui	$at,0x8006
/*  f16b41c:	e4262bf8 */ 	swc1	$f6,0x2bf8($at)
/*  f16b420:	3c013e80 */ 	lui	$at,0x3e80
/*  f16b424:	44814000 */ 	mtc1	$at,$f8
/*  f16b428:	3c018008 */ 	lui	$at,0x8008
/*  f16b42c:	e428eaa8 */ 	swc1	$f8,-0x1558($at)
/*  f16b430:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b434:	c42a8798 */ 	lwc1	$f10,-0x7868($at)
/*  f16b438:	3c018007 */ 	lui	$at,0x8007
/*  f16b43c:	e42a97d0 */ 	swc1	$f10,-0x6830($at)
/*  f16b440:	3c014020 */ 	lui	$at,0x4020
/*  f16b444:	44819000 */ 	mtc1	$at,$f18
/*  f16b448:	3c018007 */ 	lui	$at,0x8007
/*  f16b44c:	e43298ac */ 	swc1	$f18,-0x6754($at)
/*  f16b450:	3c018006 */ 	lui	$at,0x8006
/*  f16b454:	1000014c */ 	b	.JF0f16b988
/*  f16b458:	e42c2bfc */ 	swc1	$f12,0x2bfc($at)
.JF0f16b45c:
/*  f16b45c:	3c013f80 */ 	lui	$at,0x3f80
/*  f16b460:	44810000 */ 	mtc1	$at,$f0
/*  f16b464:	3c014000 */ 	lui	$at,0x4000
/*  f16b468:	44811000 */ 	mtc1	$at,$f2
/*  f16b46c:	3c013f00 */ 	lui	$at,0x3f00
/*  f16b470:	44816000 */ 	mtc1	$at,$f12
/*  f16b474:	3c013f40 */ 	lui	$at,0x3f40
/*  f16b478:	44817000 */ 	mtc1	$at,$f14
/*  f16b47c:	3c018007 */ 	lui	$at,0x8007
/*  f16b480:	e4229898 */ 	swc1	$f2,-0x6768($at)
/*  f16b484:	3c018007 */ 	lui	$at,0x8007
/*  f16b488:	e420989c */ 	swc1	$f0,-0x6764($at)
/*  f16b48c:	3c018007 */ 	lui	$at,0x8007
/*  f16b490:	e42c98a0 */ 	swc1	$f12,-0x6760($at)
/*  f16b494:	3c018007 */ 	lui	$at,0x8007
/*  f16b498:	e42c98a4 */ 	swc1	$f12,-0x675c($at)
/*  f16b49c:	3c018007 */ 	lui	$at,0x8007
/*  f16b4a0:	e42098a8 */ 	swc1	$f0,-0x6758($at)
/*  f16b4a4:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b4a8:	c424879c */ 	lwc1	$f4,-0x7864($at)
/*  f16b4ac:	3c018006 */ 	lui	$at,0x8006
/*  f16b4b0:	e4242bf0 */ 	swc1	$f4,0x2bf0($at)
/*  f16b4b4:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b4b8:	c42687a0 */ 	lwc1	$f6,-0x7860($at)
/*  f16b4bc:	3c018006 */ 	lui	$at,0x8006
/*  f16b4c0:	e4262bf4 */ 	swc1	$f6,0x2bf4($at)
/*  f16b4c4:	3c018006 */ 	lui	$at,0x8006
/*  f16b4c8:	e4222bf8 */ 	swc1	$f2,0x2bf8($at)
/*  f16b4cc:	3c013e80 */ 	lui	$at,0x3e80
/*  f16b4d0:	44814000 */ 	mtc1	$at,$f8
/*  f16b4d4:	3c018008 */ 	lui	$at,0x8008
/*  f16b4d8:	e428eaa8 */ 	swc1	$f8,-0x1558($at)
/*  f16b4dc:	3c018007 */ 	lui	$at,0x8007
/*  f16b4e0:	e42e97d0 */ 	swc1	$f14,-0x6830($at)
/*  f16b4e4:	3c018007 */ 	lui	$at,0x8007
/*  f16b4e8:	e42298ac */ 	swc1	$f2,-0x6754($at)
/*  f16b4ec:	3c018006 */ 	lui	$at,0x8006
/*  f16b4f0:	10000125 */ 	b	.JF0f16b988
/*  f16b4f4:	e4202bfc */ 	swc1	$f0,0x2bfc($at)
/*  f16b4f8:	8c440298 */ 	lw	$a0,0x298($v0)
.JF0f16b4fc:
/*  f16b4fc:	3c028008 */ 	lui	$v0,0x8008
/*  f16b500:	0480006c */ 	bltz	$a0,.JF0f16b6b4
/*  f16b504:	00000000 */ 	nop
/*  f16b508:	3c028008 */ 	lui	$v0,0x8008
/*  f16b50c:	8c424670 */ 	lw	$v0,0x4670($v0)
/*  f16b510:	24010001 */ 	li	$at,0x1
/*  f16b514:	14400026 */ 	bnez	$v0,.JF0f16b5b0
/*  f16b518:	00000000 */ 	nop
/*  f16b51c:	3c014000 */ 	lui	$at,0x4000
/*  f16b520:	44811000 */ 	mtc1	$at,$f2
/*  f16b524:	3c013f00 */ 	lui	$at,0x3f00
/*  f16b528:	44816000 */ 	mtc1	$at,$f12
/*  f16b52c:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f16b530:	44818000 */ 	mtc1	$at,$f16
/*  f16b534:	3c018007 */ 	lui	$at,0x8007
/*  f16b538:	e4229898 */ 	swc1	$f2,-0x6768($at)
/*  f16b53c:	3c018007 */ 	lui	$at,0x8007
/*  f16b540:	e422989c */ 	swc1	$f2,-0x6764($at)
/*  f16b544:	3c018007 */ 	lui	$at,0x8007
/*  f16b548:	e42c98a0 */ 	swc1	$f12,-0x6760($at)
/*  f16b54c:	3c018007 */ 	lui	$at,0x8007
/*  f16b550:	e42c98a4 */ 	swc1	$f12,-0x675c($at)
/*  f16b554:	3c018007 */ 	lui	$at,0x8007
/*  f16b558:	e42298a8 */ 	swc1	$f2,-0x6758($at)
/*  f16b55c:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b560:	c42a87a4 */ 	lwc1	$f10,-0x785c($at)
/*  f16b564:	3c018006 */ 	lui	$at,0x8006
/*  f16b568:	e42a2bf0 */ 	swc1	$f10,0x2bf0($at)
/*  f16b56c:	3c018006 */ 	lui	$at,0x8006
/*  f16b570:	e42c2bf4 */ 	swc1	$f12,0x2bf4($at)
/*  f16b574:	3c018006 */ 	lui	$at,0x8006
/*  f16b578:	e4222bf8 */ 	swc1	$f2,0x2bf8($at)
/*  f16b57c:	3c013e80 */ 	lui	$at,0x3e80
/*  f16b580:	44819000 */ 	mtc1	$at,$f18
/*  f16b584:	3c018008 */ 	lui	$at,0x8008
/*  f16b588:	e432eaa8 */ 	swc1	$f18,-0x1558($at)
/*  f16b58c:	3c018007 */ 	lui	$at,0x8007
/*  f16b590:	e43097d0 */ 	swc1	$f16,-0x6830($at)
/*  f16b594:	3c018007 */ 	lui	$at,0x8007
/*  f16b598:	e42298ac */ 	swc1	$f2,-0x6754($at)
/*  f16b59c:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b5a0:	c42487a8 */ 	lwc1	$f4,-0x7858($at)
/*  f16b5a4:	3c018006 */ 	lui	$at,0x8006
/*  f16b5a8:	100000f7 */ 	b	.JF0f16b988
/*  f16b5ac:	e4242bfc */ 	swc1	$f4,0x2bfc($at)
.JF0f16b5b0:
/*  f16b5b0:	14410021 */ 	bne	$v0,$at,.JF0f16b638
/*  f16b5b4:	3c013f80 */ 	lui	$at,0x3f80
/*  f16b5b8:	44810000 */ 	mtc1	$at,$f0
/*  f16b5bc:	3c013f00 */ 	lui	$at,0x3f00
/*  f16b5c0:	44816000 */ 	mtc1	$at,$f12
/*  f16b5c4:	3c013f40 */ 	lui	$at,0x3f40
/*  f16b5c8:	44817000 */ 	mtc1	$at,$f14
/*  f16b5cc:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f16b5d0:	44818000 */ 	mtc1	$at,$f16
/*  f16b5d4:	3c018007 */ 	lui	$at,0x8007
/*  f16b5d8:	e4209898 */ 	swc1	$f0,-0x6768($at)
/*  f16b5dc:	3c018007 */ 	lui	$at,0x8007
/*  f16b5e0:	e420989c */ 	swc1	$f0,-0x6764($at)
/*  f16b5e4:	3c018007 */ 	lui	$at,0x8007
/*  f16b5e8:	e42e98a0 */ 	swc1	$f14,-0x6760($at)
/*  f16b5ec:	3c018007 */ 	lui	$at,0x8007
/*  f16b5f0:	e42098a4 */ 	swc1	$f0,-0x675c($at)
/*  f16b5f4:	3c018007 */ 	lui	$at,0x8007
/*  f16b5f8:	e42098a8 */ 	swc1	$f0,-0x6758($at)
/*  f16b5fc:	3c018006 */ 	lui	$at,0x8006
/*  f16b600:	e42e2bf0 */ 	swc1	$f14,0x2bf0($at)
/*  f16b604:	3c018006 */ 	lui	$at,0x8006
/*  f16b608:	e4202bf4 */ 	swc1	$f0,0x2bf4($at)
/*  f16b60c:	3c018006 */ 	lui	$at,0x8006
/*  f16b610:	e4202bf8 */ 	swc1	$f0,0x2bf8($at)
/*  f16b614:	3c018008 */ 	lui	$at,0x8008
/*  f16b618:	e420eaa8 */ 	swc1	$f0,-0x1558($at)
/*  f16b61c:	3c018007 */ 	lui	$at,0x8007
/*  f16b620:	e42e97d0 */ 	swc1	$f14,-0x6830($at)
/*  f16b624:	3c018007 */ 	lui	$at,0x8007
/*  f16b628:	e43098ac */ 	swc1	$f16,-0x6754($at)
/*  f16b62c:	3c018006 */ 	lui	$at,0x8006
/*  f16b630:	100000d5 */ 	b	.JF0f16b988
/*  f16b634:	e42c2bfc */ 	swc1	$f12,0x2bfc($at)
.JF0f16b638:
/*  f16b638:	3c013f80 */ 	lui	$at,0x3f80
/*  f16b63c:	44810000 */ 	mtc1	$at,$f0
/*  f16b640:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f16b644:	44818000 */ 	mtc1	$at,$f16
/*  f16b648:	3c018007 */ 	lui	$at,0x8007
/*  f16b64c:	e4209898 */ 	swc1	$f0,-0x6768($at)
/*  f16b650:	3c018007 */ 	lui	$at,0x8007
/*  f16b654:	e420989c */ 	swc1	$f0,-0x6764($at)
/*  f16b658:	3c018007 */ 	lui	$at,0x8007
/*  f16b65c:	e42098a0 */ 	swc1	$f0,-0x6760($at)
/*  f16b660:	3c018007 */ 	lui	$at,0x8007
/*  f16b664:	e43098a4 */ 	swc1	$f16,-0x675c($at)
/*  f16b668:	3c018007 */ 	lui	$at,0x8007
/*  f16b66c:	e42098a8 */ 	swc1	$f0,-0x6758($at)
/*  f16b670:	3c018006 */ 	lui	$at,0x8006
/*  f16b674:	e4302bf0 */ 	swc1	$f16,0x2bf0($at)
/*  f16b678:	3c018006 */ 	lui	$at,0x8006
/*  f16b67c:	e4302bf4 */ 	swc1	$f16,0x2bf4($at)
/*  f16b680:	3c018006 */ 	lui	$at,0x8006
/*  f16b684:	e4202bf8 */ 	swc1	$f0,0x2bf8($at)
/*  f16b688:	3c018008 */ 	lui	$at,0x8008
/*  f16b68c:	e430eaa8 */ 	swc1	$f16,-0x1558($at)
/*  f16b690:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b694:	c42687ac */ 	lwc1	$f6,-0x7854($at)
/*  f16b698:	3c018007 */ 	lui	$at,0x8007
/*  f16b69c:	e42697d0 */ 	swc1	$f6,-0x6830($at)
/*  f16b6a0:	3c018007 */ 	lui	$at,0x8007
/*  f16b6a4:	e42098ac */ 	swc1	$f0,-0x6754($at)
/*  f16b6a8:	3c018006 */ 	lui	$at,0x8006
/*  f16b6ac:	100000b6 */ 	b	.JF0f16b988
/*  f16b6b0:	e4202bfc */ 	swc1	$f0,0x2bfc($at)
.JF0f16b6b4:
/*  f16b6b4:	8c424670 */ 	lw	$v0,0x4670($v0)
/*  f16b6b8:	24010001 */ 	li	$at,0x1
/*  f16b6bc:	1440004d */ 	bnez	$v0,.JF0f16b7f4
/*  f16b6c0:	00000000 */ 	nop
/*  f16b6c4:	3c013f80 */ 	lui	$at,0x3f80
/*  f16b6c8:	44817000 */ 	mtc1	$at,$f14
/*  f16b6cc:	04830023 */ 	bgezl	$a0,.JF0f16b75c
/*  f16b6d0:	3c014000 */ 	lui	$at,0x4000
/*  f16b6d4:	04630021 */ 	bgezl	$v1,.JF0f16b75c
/*  f16b6d8:	3c014000 */ 	lui	$at,0x4000
/*  f16b6dc:	0fc30c93 */ 	jal	playerGetHealthFrac
/*  f16b6e0:	e7ae0020 */ 	swc1	$f14,0x20($sp)
/*  f16b6e4:	0fc30c97 */ 	jal	playerGetShieldFrac
/*  f16b6e8:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f16b6ec:	c7a8001c */ 	lwc1	$f8,0x1c($sp)
/*  f16b6f0:	3c013e00 */ 	lui	$at,0x3e00
/*  f16b6f4:	44818000 */ 	mtc1	$at,$f16
/*  f16b6f8:	46080080 */ 	add.s	$f2,$f0,$f8
/*  f16b6fc:	c7ae0020 */ 	lwc1	$f14,0x20($sp)
/*  f16b700:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b704:	4610103e */ 	c.le.s	$f2,$f16
/*  f16b708:	00000000 */ 	nop
/*  f16b70c:	45000005 */ 	bc1f	.JF0f16b724
/*  f16b710:	00000000 */ 	nop
/*  f16b714:	3c013f00 */ 	lui	$at,0x3f00
/*  f16b718:	44817000 */ 	mtc1	$at,$f14
/*  f16b71c:	1000000f */ 	b	.JF0f16b75c
/*  f16b720:	3c014000 */ 	lui	$at,0x4000
.JF0f16b724:
/*  f16b724:	c42a87b0 */ 	lwc1	$f10,-0x7850($at)
/*  f16b728:	3c013f00 */ 	lui	$at,0x3f00
/*  f16b72c:	460a103e */ 	c.le.s	$f2,$f10
/*  f16b730:	00000000 */ 	nop
/*  f16b734:	45020009 */ 	bc1fl	.JF0f16b75c
/*  f16b738:	3c014000 */ 	lui	$at,0x4000
/*  f16b73c:	46101481 */ 	sub.s	$f18,$f2,$f16
/*  f16b740:	44816000 */ 	mtc1	$at,$f12
/*  f16b744:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b748:	c42687b4 */ 	lwc1	$f6,-0x784c($at)
/*  f16b74c:	460c9102 */ 	mul.s	$f4,$f18,$f12
/*  f16b750:	46062203 */ 	div.s	$f8,$f4,$f6
/*  f16b754:	460c4380 */ 	add.s	$f14,$f8,$f12
/*  f16b758:	3c014000 */ 	lui	$at,0x4000
.JF0f16b75c:
/*  f16b75c:	44811000 */ 	mtc1	$at,$f2
/*  f16b760:	3c013f00 */ 	lui	$at,0x3f00
/*  f16b764:	44816000 */ 	mtc1	$at,$f12
/*  f16b768:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f16b76c:	44818000 */ 	mtc1	$at,$f16
/*  f16b770:	460e6002 */ 	mul.s	$f0,$f12,$f14
/*  f16b774:	3c018007 */ 	lui	$at,0x8007
/*  f16b778:	e4229898 */ 	swc1	$f2,-0x6768($at)
/*  f16b77c:	3c018007 */ 	lui	$at,0x8007
/*  f16b780:	e422989c */ 	swc1	$f2,-0x6764($at)
/*  f16b784:	3c018007 */ 	lui	$at,0x8007
/*  f16b788:	e42098a0 */ 	swc1	$f0,-0x6760($at)
/*  f16b78c:	3c018007 */ 	lui	$at,0x8007
/*  f16b790:	e42098a4 */ 	swc1	$f0,-0x675c($at)
/*  f16b794:	3c018007 */ 	lui	$at,0x8007
/*  f16b798:	e42298a8 */ 	swc1	$f2,-0x6758($at)
/*  f16b79c:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b7a0:	c42a87b8 */ 	lwc1	$f10,-0x7848($at)
/*  f16b7a4:	3c018006 */ 	lui	$at,0x8006
/*  f16b7a8:	e42a2bf0 */ 	swc1	$f10,0x2bf0($at)
/*  f16b7ac:	3c018006 */ 	lui	$at,0x8006
/*  f16b7b0:	e4202bf4 */ 	swc1	$f0,0x2bf4($at)
/*  f16b7b4:	3c018006 */ 	lui	$at,0x8006
/*  f16b7b8:	e4222bf8 */ 	swc1	$f2,0x2bf8($at)
/*  f16b7bc:	3c013e80 */ 	lui	$at,0x3e80
/*  f16b7c0:	44819000 */ 	mtc1	$at,$f18
/*  f16b7c4:	3c018008 */ 	lui	$at,0x8008
/*  f16b7c8:	460e9102 */ 	mul.s	$f4,$f18,$f14
/*  f16b7cc:	e424eaa8 */ 	swc1	$f4,-0x1558($at)
/*  f16b7d0:	3c018007 */ 	lui	$at,0x8007
/*  f16b7d4:	e43097d0 */ 	swc1	$f16,-0x6830($at)
/*  f16b7d8:	3c018007 */ 	lui	$at,0x8007
/*  f16b7dc:	e42298ac */ 	swc1	$f2,-0x6754($at)
/*  f16b7e0:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b7e4:	c42687bc */ 	lwc1	$f6,-0x7844($at)
/*  f16b7e8:	3c018006 */ 	lui	$at,0x8006
/*  f16b7ec:	10000066 */ 	b	.JF0f16b988
/*  f16b7f0:	e4262bfc */ 	swc1	$f6,0x2bfc($at)
.JF0f16b7f4:
/*  f16b7f4:	14410025 */ 	bne	$v0,$at,.JF0f16b88c
/*  f16b7f8:	3c013f80 */ 	lui	$at,0x3f80
/*  f16b7fc:	44810000 */ 	mtc1	$at,$f0
/*  f16b800:	3c013f00 */ 	lui	$at,0x3f00
/*  f16b804:	44816000 */ 	mtc1	$at,$f12
/*  f16b808:	3c013f40 */ 	lui	$at,0x3f40
/*  f16b80c:	44817000 */ 	mtc1	$at,$f14
/*  f16b810:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f16b814:	44818000 */ 	mtc1	$at,$f16
/*  f16b818:	3c018007 */ 	lui	$at,0x8007
/*  f16b81c:	e4209898 */ 	swc1	$f0,-0x6768($at)
/*  f16b820:	3c018007 */ 	lui	$at,0x8007
/*  f16b824:	e420989c */ 	swc1	$f0,-0x6764($at)
/*  f16b828:	3c018007 */ 	lui	$at,0x8007
/*  f16b82c:	e42e98a0 */ 	swc1	$f14,-0x6760($at)
/*  f16b830:	3c018007 */ 	lui	$at,0x8007
/*  f16b834:	e42e98a4 */ 	swc1	$f14,-0x675c($at)
/*  f16b838:	3c018007 */ 	lui	$at,0x8007
/*  f16b83c:	e42098a8 */ 	swc1	$f0,-0x6758($at)
/*  f16b840:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b844:	c42887c0 */ 	lwc1	$f8,-0x7840($at)
/*  f16b848:	3c018006 */ 	lui	$at,0x8006
/*  f16b84c:	e4282bf0 */ 	swc1	$f8,0x2bf0($at)
/*  f16b850:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b854:	c42a87c4 */ 	lwc1	$f10,-0x783c($at)
/*  f16b858:	3c018006 */ 	lui	$at,0x8006
/*  f16b85c:	e42a2bf4 */ 	swc1	$f10,0x2bf4($at)
/*  f16b860:	3c018006 */ 	lui	$at,0x8006
/*  f16b864:	e4202bf8 */ 	swc1	$f0,0x2bf8($at)
/*  f16b868:	3c018008 */ 	lui	$at,0x8008
/*  f16b86c:	e42eeaa8 */ 	swc1	$f14,-0x1558($at)
/*  f16b870:	3c018007 */ 	lui	$at,0x8007
/*  f16b874:	e42e97d0 */ 	swc1	$f14,-0x6830($at)
/*  f16b878:	3c018007 */ 	lui	$at,0x8007
/*  f16b87c:	e43098ac */ 	swc1	$f16,-0x6754($at)
/*  f16b880:	3c018006 */ 	lui	$at,0x8006
/*  f16b884:	10000040 */ 	b	.JF0f16b988
/*  f16b888:	e42c2bfc */ 	swc1	$f12,0x2bfc($at)
.JF0f16b88c:
/*  f16b88c:	24010002 */ 	li	$at,0x2
/*  f16b890:	1441001f */ 	bne	$v0,$at,.JF0f16b910
/*  f16b894:	3c013f80 */ 	lui	$at,0x3f80
/*  f16b898:	44810000 */ 	mtc1	$at,$f0
/*  f16b89c:	3c018007 */ 	lui	$at,0x8007
/*  f16b8a0:	e4209898 */ 	swc1	$f0,-0x6768($at)
/*  f16b8a4:	3c018007 */ 	lui	$at,0x8007
/*  f16b8a8:	e420989c */ 	swc1	$f0,-0x6764($at)
/*  f16b8ac:	3c018007 */ 	lui	$at,0x8007
/*  f16b8b0:	e42098a0 */ 	swc1	$f0,-0x6760($at)
/*  f16b8b4:	3c018007 */ 	lui	$at,0x8007
/*  f16b8b8:	e42098a4 */ 	swc1	$f0,-0x675c($at)
/*  f16b8bc:	3c018007 */ 	lui	$at,0x8007
/*  f16b8c0:	e42098a8 */ 	swc1	$f0,-0x6758($at)
/*  f16b8c4:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b8c8:	c43287c8 */ 	lwc1	$f18,-0x7838($at)
/*  f16b8cc:	3c018006 */ 	lui	$at,0x8006
/*  f16b8d0:	e4322bf0 */ 	swc1	$f18,0x2bf0($at)
/*  f16b8d4:	3c018006 */ 	lui	$at,0x8006
/*  f16b8d8:	e4202bf4 */ 	swc1	$f0,0x2bf4($at)
/*  f16b8dc:	3c018006 */ 	lui	$at,0x8006
/*  f16b8e0:	e4202bf8 */ 	swc1	$f0,0x2bf8($at)
/*  f16b8e4:	3c018008 */ 	lui	$at,0x8008
/*  f16b8e8:	e420eaa8 */ 	swc1	$f0,-0x1558($at)
/*  f16b8ec:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b8f0:	c42487cc */ 	lwc1	$f4,-0x7834($at)
/*  f16b8f4:	3c018007 */ 	lui	$at,0x8007
/*  f16b8f8:	e42497d0 */ 	swc1	$f4,-0x6830($at)
/*  f16b8fc:	3c018007 */ 	lui	$at,0x8007
/*  f16b900:	e42098ac */ 	swc1	$f0,-0x6754($at)
/*  f16b904:	3c018006 */ 	lui	$at,0x8006
/*  f16b908:	1000001f */ 	b	.JF0f16b988
/*  f16b90c:	e4202bfc */ 	swc1	$f0,0x2bfc($at)
.JF0f16b910:
/*  f16b910:	24010003 */ 	li	$at,0x3
/*  f16b914:	1441001c */ 	bne	$v0,$at,.JF0f16b988
/*  f16b918:	3c013f80 */ 	lui	$at,0x3f80
/*  f16b91c:	44810000 */ 	mtc1	$at,$f0
/*  f16b920:	3c018007 */ 	lui	$at,0x8007
/*  f16b924:	e4209898 */ 	swc1	$f0,-0x6768($at)
/*  f16b928:	3c018007 */ 	lui	$at,0x8007
/*  f16b92c:	e420989c */ 	swc1	$f0,-0x6764($at)
/*  f16b930:	3c018007 */ 	lui	$at,0x8007
/*  f16b934:	e42098a0 */ 	swc1	$f0,-0x6760($at)
/*  f16b938:	3c018007 */ 	lui	$at,0x8007
/*  f16b93c:	e42098a4 */ 	swc1	$f0,-0x675c($at)
/*  f16b940:	3c018007 */ 	lui	$at,0x8007
/*  f16b944:	e42098a8 */ 	swc1	$f0,-0x6758($at)
/*  f16b948:	3c017f1c */ 	lui	$at,0x7f1c
/*  f16b94c:	c42687d0 */ 	lwc1	$f6,-0x7830($at)
/*  f16b950:	3c018006 */ 	lui	$at,0x8006
/*  f16b954:	e4262bf0 */ 	swc1	$f6,0x2bf0($at)
/*  f16b958:	3c018006 */ 	lui	$at,0x8006
/*  f16b95c:	e4202bf4 */ 	swc1	$f0,0x2bf4($at)
/*  f16b960:	3c018006 */ 	lui	$at,0x8006
/*  f16b964:	e4202bf8 */ 	swc1	$f0,0x2bf8($at)
/*  f16b968:	3c018008 */ 	lui	$at,0x8008
/*  f16b96c:	e420eaa8 */ 	swc1	$f0,-0x1558($at)
/*  f16b970:	3c018007 */ 	lui	$at,0x8007
/*  f16b974:	e42097d0 */ 	swc1	$f0,-0x6830($at)
/*  f16b978:	3c018007 */ 	lui	$at,0x8007
/*  f16b97c:	e42098ac */ 	swc1	$f0,-0x6754($at)
/*  f16b980:	3c018006 */ 	lui	$at,0x8006
/*  f16b984:	e4202bfc */ 	swc1	$f0,0x2bfc($at)
.JF0f16b988:
/*  f16b988:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f16b98c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f16b990:	03e00008 */ 	jr	$ra
/*  f16b994:	00000000 */ 	nop
);
#else
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
#endif

#if PIRACYCHECKS

#if PAL
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
#if PAL
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
			s32 warntime = TICKS(g_MpTimeLimit60) - TICKS(3600);

			// Show HUD message at one minute remaining
			if (elapsed < warntime && nexttime >= warntime) {
				s32 i;

				for (i = 0; i < PLAYERCOUNT(); i++) {
					setCurrentPlayerNum(i);
					hudmsgCreate(langGet(L_MISC_068), HUDMSGTYPE_DEFAULT); // "One minute left."
				}
			}

			if (elapsed < TICKS(g_MpTimeLimit60) && nexttime >= TICKS(g_MpTimeLimit60)) {
				// Match is ending due to time limit reached
				mainEndStage();
			}

			// Sound alarm at 10 seconds remaining
			if (nexttime >= TICKS(g_MpTimeLimit60) - TICKS(600)
					&& g_MiscAudioHandle == NULL
					&& !lvIsPaused()
					&& nexttime < TICKS(g_MpTimeLimit60)) {
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
	g_StageTimeElapsed1f = g_StageTimeElapsed60 / TICKS(60.0f);

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
#if VERSION >= VERSION_PAL_BETA
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
