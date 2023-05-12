#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "game/activemenu.h"
#include "game/atan2f.h"
#include "game/bg.h"
#include "game/body.h"
#include "game/bondgun.h"
#include "game/bondhead.h"
#include "game/bondmove.h"
#include "game/bondview.h"
#include "game/camdraw.h"
#include "game/casing.h"
#include "game/cheats.h"
#include "game/chr.h"
#include "game/chraction.h"
#include "game/credits.h"
#include "game/dlights.h"
#include "game/explosions.h"
#include "game/filemgr.h"
#include "game/game_006900.h"
#include "game/game_00b820.h"
#include "game/gunfx.h"
#include "game/game_0b0fd0.h"
#include "game/modelmgr.h"
#include "game/portal.h"
#include "game/fmb.h"
#include "game/sky.h"
#include "game/game_13c510.h"
#include "game/game_1531a0.h"
#include "game/game_176080.h"
#include "game/challenge.h"
#include "game/chrmgr.h"
#include "game/env.h"
#include "game/gfxmemory.h"
#include "game/gunfx.h"
#include "game/hudmsg.h"
#include "game/inv.h"
#include "game/lang.h"
#include "game/lv.h"
#include "game/menu.h"
#include "game/mplayer/mplayer.h"
#include "game/mplayer/scenarios.h"
#include "game/mplayer/setup.h"
#include "game/music.h"
#include "game/nbomb.h"
#include "game/objectives.h"
#include "game/pak.h"
#include "game/player.h"
#include "game/playermgr.h"
#include "game/playerreset.h"
#include "game/prop.h"
#include "game/propobj.h"
#include "game/propobjstop.h"
#include "game/propsnd.h"
#include "game/room.h"
#include "game/savebuffer.h"
#include "game/setup.h"
#include "game/shards.h"
#include "game/sky.h"
#include "game/smoke.h"
#include "game/sparks.h"
#include "game/splat.h"
#include "game/stagetable.h"
#include "game/stars.h"
#include "game/stubs/game_013540.h"
#include "game/stubs/game_015260.h"
#include "game/stubs/game_015270.h"
#include "game/stubs/game_0153f0.h"
#include "game/stubs/game_015400.h"
#include "game/stubs/game_015410.h"
#include "game/tex.h"
#include "game/texdecompress.h"
#include "game/tiles.h"
#include "game/title.h"
#include "game/training.h"
#include "game/utils.h"
#include "game/vtxstore.h"
#include "game/wallhit.h"
#include "game/weather.h"
#include "lib/anim.h"
#include "lib/collision.h"
#include "lib/joy.h"
#include "lib/lib_06440.h"
#include "lib/lib_317f0.h"
#include "lib/main.h"
#include "lib/mema.h"
#include "lib/memp.h"
#include "lib/mtx.h"
#include "lib/music.h"
#include "lib/profile.h"
#include "lib/rng.h"
#include "lib/sched.h"
#include "lib/snd.h"
#include "lib/vars.h"
#include "lib/vi.h"
#include "types.h"

struct sndstate *g_MiscSfxAudioHandles[3];
s32 g_MiscSfxActiveTypes[3];
struct stagetableentry *g_CurrentStage;

u32 var80084010 = 0;
bool g_LvIsPaused = false;

s32 g_Difficulty = DIFF_A;

s32 g_StageTimeElapsed60 = 0;
s32 g_MpTimeLimit60 = SECSTOTIME60(60 * 10); // 10 minutes
s32 g_MpScoreLimit = 10;
s32 g_MpTeamScoreLimit = 20;
struct sndstate *g_MiscAudioHandle = NULL;
bool g_MpMatchIsEnding = false;
s32 g_MpTimeState;

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

static void lvResetSoloHandicaps(void);
static void lvCheckPauseStateChanged(void);

void lvInit(void)
{
	g_Vars.lockscreen = 0;
	g_Vars.joydisableframestogo = -1;
}

static void lvResetMiscSfx(void)
{
	s32 i;

	for (i = 0; i != ARRAYCOUNT(g_MiscSfxAudioHandles); i++) {
		g_MiscSfxAudioHandles[i] = NULL;
		g_MiscSfxActiveTypes[i] = -1;
	}
}

static s32 lvGetMiscSfxIndex(u32 type)
{
	s32 i;

	for (i = 0; i != ARRAYCOUNT(g_MiscSfxActiveTypes); i++) {
		if (g_MiscSfxActiveTypes[i] == type) {
			return i;
		}
	}

	return -1;
}

static void lvSetMiscSfxState(u32 type, bool play)
{
	if (play) {
		if (lvGetMiscSfxIndex(type) == -1) {
			s32 index = lvGetMiscSfxIndex(-1);

			if (index != -1 && g_MiscSfxAudioHandles[index] == NULL) {
				sndStart(var80095200, g_MiscSfxSounds[type], &g_MiscSfxAudioHandles[index], -1, -1, -1, -1, -1);
				g_MiscSfxActiveTypes[index] = type;
			}
		}
	} else {
		u32 stack;
		s32 index = lvGetMiscSfxIndex(type);

		if (index != -1) {
			audioStop(g_MiscSfxAudioHandles[index]);
			g_MiscSfxActiveTypes[index] = -1;
		}
	}
}

static void lvUpdateMiscSfx(void)
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

void lvReset(s32 stagenum)
{
	g_FadeNumFrames = 0;
	g_FadeFrac = -1;
	g_FadePrevColour = 0;
	g_FadeColour = 0;
	g_FadeDelay = 0;

	g_LvIsPaused = false;
	var80084010 = 0;

	joy00013900();

	g_Vars.joydisableframestogo = 10;

	g_Vars.paksconnected2 = 0;
	g_Vars.paksconnected = 0;
	g_Vars.stagenum = stagenum;

	g_CurrentStage = stageGetCurrent();

	cheatsReset();

	g_Vars.lvframenum = 0;
	var80084050 = 0;

	g_Vars.lvframe60 = 0;
	g_Vars.lvupdate240 = 4;
	g_Vars.lvupdate60f = 1.0f;
	g_Vars.lvupdate60frealprev = PALUPF(1);

	g_Vars.lvupdate60freal = g_Vars.lvupdate60frealprev;

	g_StageTimeElapsed60 = 0;

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

	musicReset();
	modelmgrSetLvResetting(true);
	surfaceReset();
	texReset();
	textReset();
	hudmsgsReset();

	if (stagenum == STAGE_TITLE) {
		titleReset();
	} else if (stagenum == STAGE_BOOTPAKMENU) {
		// empty
	} else if (stagenum == STAGE_CREDITS) {
		// empty
	} else if (stagenum == STAGE_4MBMENU) {
		// empty
	} else {
		s32 i;
		s32 j;

		tilesReset();
		bgReset(g_Vars.stagenum);
		bgBuildTables(g_Vars.stagenum);
		skyReset(g_Vars.stagenum);

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
	animsReset();
	objectivesReset();
	vtxstoreReset();
	modelmgrReset();
	propsndReset();
	setupLoadFiles(stagenum);
	scenarioReset();
	varsReset();
	propsReset();
	lvResetSoloHandicaps();
	chrmgrReset();
	bodiesReset(stagenum);
	setupCreateProps(stagenum);
	tagsReset();
	explosionsReset();
	smokeReset();
	sparksReset();
	weatherReset();
	lvResetMiscSfx();
	starsReset();
	func0f0099a4();
	boltbeamsReset();
	lasersightsReset();
	shardsReset();
	frReset();

	if (g_Vars.stagenum == STAGE_TITLE) {
		// empty
	} else if (stagenum == STAGE_BOOTPAKMENU) {
		setCurrentPlayerNum(0);
		menuReset();
	} else if (stagenum == STAGE_4MBMENU) {
		setCurrentPlayerNum(0);
		menuReset();
	} else if (stagenum == STAGE_CREDITS) {
		creditsReset();
	} else {
		s32 i;

		casingsReset();

		for (i = 0; i < PLAYERCOUNT(); i++) {
			setCurrentPlayerNum(i);
			g_Vars.currentplayer->usedowntime = 0;
			g_Vars.currentplayer->invdowntime = g_Vars.currentplayer->usedowntime;

			menuReset();
			amReset();
			invReset();
			bgunReset();
			playerLoadDefaults();
			playerReset();
			playerSpawn();
			bheadReset();
			bgunPreload();

			if (g_Vars.normmplayerisrunning && (g_MpSetup.options & MPOPTION_TEAMSENABLED)) {
				playermgrCalculateAiBuddyNums();
			}
		}

		portalsReset();
		lightsReset();
		setCurrentPlayerNum(0);
		bgPreload();
	}

	if (g_Vars.lvmpbotlevel) {
		mpCalculateTeamIsOnlyAi();
	}

	sndResetCurMp3();

	if (stagenum == STAGE_BOOTPAKMENU) {
		bootmenuReset();
	}

	modelmgrSetLvResetting(false);
	schedResetArtifacts();
	lvSetPaused(0);

	g_MpMatchIsEnding = false;
	g_MpTimeState = g_MpTimeLimit60 > 0 ? 1 : 0;
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

static Gfx *lvRenderFade(Gfx *gdl)
{
	u32 colour = g_FadeColour;
	u32 inset = 0;

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
			g_ViBackData->viewleft,
			g_ViBackData->viewtop + inset,
			g_ViBackData->viewleft + g_ViBackData->viewx + 1,
			g_ViBackData->viewtop + g_ViBackData->viewy - inset + 2);

	return text0f153838(gdl);
}

static bool lvUpdateTrackedProp(struct trackedprop *trackedprop, s32 index)
{
	f32 y1;
	f32 x1;
	f32 y2;
	f32 x2;
	struct prop *prop = trackedprop->prop;
	struct chrdata *chr;

	if (trackedprop->prop && prop->chr) {
		switch (trackedprop->prop->type) {
		case PROPTYPE_PLAYER:
			if (playermgrGetPlayerNumByProp(prop) == g_Vars.currentplayernum) {
				return false;
			}
			// fall through
		case PROPTYPE_CHR:
			chr = trackedprop->prop->chr;

			if (chrIsDead(trackedprop->prop->chr)) {
				if (index >= 0) {
					// Existing trackedprop
					if (g_Vars.currentplayer->targetset[index] < TICKS(129)) {
						g_Vars.currentplayer->targetset[index] = TICKS(129);
					}

					if (g_Vars.currentplayer->targetset[index] >= (PAL ? 146 : 175)) {
						trackedprop->prop = NULL;
						return false;
					}
				} else {
					// lookingatprop
					trackedprop->prop = NULL;
					return false;
				}
			}

			if ((trackedprop->prop->flags & PROPFLAG_ONTHISSCREENTHISTICK)
					&& (chr->chrflags & CHRCFLAG_NOAUTOAIM) == 0) {
				struct model *model = chr->model;
				x1 = -1;
				y1 = -1;
				x2 = -2;
				y2 = -2;

				if (modelGetScreenCoords(model, &x2, &x1, &y2, &y1)) {
					break;
				}
				return false;
			}
			return false;
		case PROPTYPE_OBJ:
		case PROPTYPE_WEAPON:
			if (trackedprop->prop->flags & PROPFLAG_ONTHISSCREENTHISTICK) {
				struct defaultobj *obj = trackedprop->prop->obj;
				struct model *model = obj->model;
				x1 = -1;
				y1 = -1;
				x2 = -2;
				y2 = -2;

				if (modelGetScreenCoords(model, &x2, &x1, &y2, &y1)) {
					break;
				}
				return false;
			}
			return false;
		default:
			return false;
		}

		trackedprop->x1 = x1 - 2;
		trackedprop->x2 = x2 + 2;
		trackedprop->y1 = y1 - 2;
		trackedprop->y2 = y2 + 2;
	}

	return true;
}

static void lvFindThreatsForProp(struct prop *prop, bool inchild, struct coord *playerpos, bool *activeslots, f32 *distances)
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
			&& (prop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON))
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
				if (g_Vars.currentplayer->trackedprops[i].prop == prop) {
					pass = false;
				}
			}
		}

		if (pass) {
			sp84 = -1;
			sp88 = -1;
			sp76 = -2;
			sp80 = -2;

			if (!modelGetScreenCoords(model, &sp76, &sp84, &sp80, &sp88)) {
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
				g_Vars.currentplayer->trackedprops[index].prop = prop;
				g_Vars.currentplayer->trackedprops[index].x1 = sp84 - 2;
				g_Vars.currentplayer->trackedprops[index].x2 = sp76 + 2;
				g_Vars.currentplayer->trackedprops[index].y1 = sp88 - 2;
				g_Vars.currentplayer->trackedprops[index].y2 = sp80 + 2;
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

static void func0f168f24(struct prop *prop, bool inchild, struct coord *playerpos, s32 *activeslots, f32 *distances)
{
	s32 i;
	f32 sp128;
	f32 sp124;
	f32 sp120;
	f32 sp116;
	struct model *model;

	for (i = 0; i != 4; i++) {
		if (g_Vars.currentplayer->trackedprops[i].prop == prop
				&& (prop->flags & PROPFLAG_ONTHISSCREENTHISTICK)) {
			model = NULL;

			if (prop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON | PROPTYPE_DOOR)) {
				model = g_Vars.currentplayer->trackedprops[i].prop->obj->model;
			} else {
				if (prop->type == PROPTYPE_CHR
						|| (prop->type == PROPTYPE_PLAYER
							&& playermgrGetPlayerNumByProp(prop) != g_Vars.currentplayernum)) {
					model = g_Vars.currentplayer->trackedprops[i].prop->chr->model;
				}
			}

			if (model) {
				sp124 = -1;
				sp128 = -1;
				sp116 = -2;
				sp120 = -2;

				if (modelGetScreenCoords(model, &sp116, &sp124, &sp120, &sp128)) {
					activeslots[i] = true;
					g_Vars.currentplayer->trackedprops[i].x1 = sp124 - 2;
					g_Vars.currentplayer->trackedprops[i].x2 = sp116 + 2;
					g_Vars.currentplayer->trackedprops[i].y1 = sp128 - 2;
					g_Vars.currentplayer->trackedprops[i].y2 = sp120 + 2;

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

static void lvFindThreats(void)
{
	s32 i;
	struct prop *prop;
	f32 distances[] = {0, 0, 0, 0};
	s32 activeslots[] = {false, false, false, false};
	struct prop **propptr = g_Vars.endonscreenprops - 1;
	struct coord campos;

	campos = g_Vars.currentplayer->cam_pos;

	while (propptr >= g_Vars.onscreenprops) {
		prop = *propptr;

		if (prop) {
			func0f168f24(prop, false, &campos, activeslots, distances);
		}

		propptr--;
	}

	for (i = 0; i != ARRAYCOUNT(activeslots); i++) {
		if (!activeslots[i]) {
			g_Vars.currentplayer->trackedprops[i].prop = NULL;
			g_Vars.currentplayer->trackedprops[i].x1 = -1;
			g_Vars.currentplayer->trackedprops[i].x2 = -2;
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

u8 g_LvShowStats = 0;
u8 g_LvStatsPage = 0;
u8 g_LvRateIndex = 59;
u8 g_LvOom = 0;
u32 g_LvOomSize = 0;
u8 g_LvFrameRates[60];

static void lvRecordRate(void)
{
	g_LvFrameRates[g_LvRateIndex] = OS_CPU_COUNTER / g_Vars.diffframet;

	g_LvRateIndex++;

	if (g_LvRateIndex >= 60) {
		g_LvRateIndex = 0;
	}
}

Gfx *func0f153134(Gfx *gdl);

static Gfx *lvPrintRateGraph(Gfx *gdl)
{
	s32 i;
	s32 top = 10;
	s32 bottom = 70;
	s32 x;
	s32 y;

	gdl = func0f153134(gdl);

	// graph data
	gdl = textSetPrimColour(gdl, 0x00ff00a0);

	for (i = 0; i < 60; i++) {
		s32 index = (g_LvRateIndex + i) % 60;

		x = 10 + i * 2;
		y = top + 60 - g_LvFrameRates[index];

		gDPFillRectangleScaled(gdl++, x, y, x + 2, bottom);
	}

	gdl = text0f153838(gdl);

	// grid lines
	gdl = textSetPrimColour(gdl, 0x000000a0);

	gDPFillRectangleScaled(gdl++, 10, 10, 130, 11);
	gDPFillRectangleScaled(gdl++, 10, 20, 130, 21);
	gDPFillRectangleScaled(gdl++, 10, 30, 130, 31);
	gDPFillRectangleScaled(gdl++, 10, 40, 130, 41);
	gDPFillRectangleScaled(gdl++, 10, 50, 130, 51);
	gDPFillRectangleScaled(gdl++, 10, 60, 130, 61);
	gDPFillRectangleScaled(gdl++, 10, 70, 130, 71);

	// labels
	gdl = func0f0d479c(gdl);

	if (g_FontHandelGothicXs) {
		x = 120 + 15;
		y = 7;
		gdl = textRender(gdl, &x, &y, "60", g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);

		x = 120 + 15;
		y = 37;
		gdl = textRender(gdl, &x, &y, "30", g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);
	}

	return gdl;
}

static Gfx *lvPrintCounter(Gfx *gdl, s32 *y, char *label, u32 cycles, u32 cycles_per_second)
{
	char buffer[32];
	s32 x = 10;
	u32 colour;
	u32 percentage;
	u32 microseconds;
	s32 textwidth;
	s32 textheight;
	u32 target;

	// 100% means 30 FPS
	// 50% means 60 FPS
	target = cycles_per_second / 30;
	percentage = 100 * cycles / target;

	microseconds = (f32) cycles / cycles_per_second * 1000000;

	// Colour green if this counter can achieve 60 FPS
	// Colour yellow if this counter can achieve 30 FPS
	// Colour red if under 30 FPS
	if (percentage <= 50) {
		colour = 0x00ff00a0; // green
	} else if (percentage <= 100) {
		colour = 0xffff00a0; // yellow
	} else {
		colour = 0xff0000a0; // red
	}

	// Label
	x = 10;
	gdl = textRender(gdl, &x, y, label, g_CharsHandelGothicXs, g_FontHandelGothicXs, colour, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);

	// Microseconds
	sprintf(buffer, "%d", microseconds);
	textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
	x = 80 - textwidth;
	gdl = textRender(gdl, &x, y, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, colour, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);

	// Percentage
	sprintf(buffer, "(%d%%)\n", percentage);
	textMeasure(&textheight, &textwidth, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
	x = 120 - textwidth;
	gdl = textRender(gdl, &x, y, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, colour, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);

	// Line
	gdl = textSetPrimColour(gdl, colour);

	gDPFillRectangleScaled(gdl++, 10, *y, 11 + microseconds * 110 / 33333, *y + 1);

	*y += 2;

	return gdl;
}

extern u8 g_ScBottleneck;

static Gfx *lvPrintRateText(Gfx *gdl)
{
	if (g_FontHandelGothicXs) {
		char buffer[64];
		s32 x = 10;
		s32 y = 80;
		s32 i;
		s32 sum = 0;
		s32 count = 0;
		u32 min = 0xffffffff;
		u32 max = 0;

		for (i = 0; i < 60; i++) {
			if (g_LvFrameRates[i]) {
				sum += g_LvFrameRates[i];
				count++;

				if (g_LvFrameRates[i] < min) {
					min = g_LvFrameRates[i];
				}

				if (g_LvFrameRates[i] > max) {
					max = g_LvFrameRates[i];
				}
			}
		}

		if (count) {
			x = 10;
			sprintf(buffer, "min %d", min);
			gdl = textRender(gdl, &x, &y, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);

			x = 50;
			sprintf(buffer, "max %d", max);
			gdl = textRender(gdl, &x, &y, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);

			x = 90;
			sprintf(buffer, "avg %d", sum / count);
			gdl = textRender(gdl, &x, &y, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);

			x = 130;
			sprintf(buffer, "cur %d\n\n", (s32) (OS_CPU_COUNTER / g_Vars.diffframet));
			gdl = textRender(gdl, &x, &y, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);
		}

		{
			u32 counters[5];

			profileGetCounters(counters);

			gdl = lvPrintCounter(gdl, &y, "RSP", counters[0], OS_CLOCK_RATE);
			gdl = lvPrintCounter(gdl, &y, "RDP", counters[1], OS_CLOCK_RATE);
			gdl = lvPrintCounter(gdl, &y, "CPU", counters[2] + counters[3] + counters[4], OS_CPU_COUNTER);
			gdl = lvPrintCounter(gdl, &y, " audio", counters[2], OS_CPU_COUNTER);
			gdl = lvPrintCounter(gdl, &y, " main", counters[3], OS_CPU_COUNTER);
			gdl = lvPrintCounter(gdl, &y, " sched", counters[4], OS_CPU_COUNTER);

			gdl = textRender(gdl, &x, &y, "\n", g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);
		}

		x = 10;

		if (g_ScBottleneck == 'C') {
			gdl = textRender(gdl, &x, &y, "bottleneck CPU\n\n", g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x3333ffa0, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);
		} else if (g_ScBottleneck == 'R') {
			gdl = textRender(gdl, &x, &y, "bottleneck RDP\n\n", g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xff0000a0, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);
		} else if (g_ScBottleneck == 'V') {
			gdl = textRender(gdl, &x, &y, "bottleneck VI\n\n", g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);
		}

		sprintf(buffer, "mema free %d KB\n", memaGetLongestFree() / 1024);
		gdl = textRender(gdl, &x, &y, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);

		sprintf(buffer, "memp free %d KB\n", mempGetStageFree() / 1024);
		gdl = textRender(gdl, &x, &y, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);

		if (g_LvOom) {
			sprintf(buffer, "mem%c OOM %x\n", g_LvOom, g_LvOomSize);
			gdl = textRender(gdl, &x, &y, buffer, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xff0000a0, 0x000000a0, g_ViBackData->x, g_ViBackData->y, 0, 0);
		}
	}

	return gdl;
}

static Gfx *lvPrint(Gfx *gdl)
{
	if (joyGetButtonsPressedThisFrame(0, L_TRIG)) {
		g_LvShowStats = 1 - g_LvShowStats;
	}

#ifdef PROFILING
	if (joyGetButtonsPressedThisFrame(0, R_JPAD)) {
		g_LvStatsPage = (g_LvStatsPage + 1) % 3;
	}
#endif

	lvRecordRate();

	if (g_LvShowStats && g_LvStatsPage == 0) {
		gdl = text0f153628(gdl);
		gdl = lvPrintRateGraph(gdl);
		gdl = lvPrintRateText(gdl);
		gdl = text0f153780(gdl);
	}

	return gdl;
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
Gfx *lvRender(Gfx *gdl)
{
	gSPSegment(gdl++, SPSEGMENT_PHYSICAL, 0x00000000);

	func0f0d5a7c();

	if (g_Vars.stagenum == STAGE_TITLE) {
		gSPDisplayList(gdl++, &var800613a0);
		gSPDisplayList(gdl++, &var80061380);

		gdl = vi0000b280(gdl);
		gdl = vi0000b1d0(gdl);

		gDPSetScissorFrac(gdl++, 0,
				g_ViBackData->viewleft * 4.0f, g_ViBackData->viewtop * 4.0f,
				(g_ViBackData->viewleft + g_ViBackData->viewx) * 4.0f,
				(g_ViBackData->viewtop + g_ViBackData->viewy) * 4.0f);

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
		var8005ef10[0] = 65536;

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

		var8005ef10[0] = 65536;

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
		var8005ef10[0] = 65536;

		gdl = vi0000b1a8(gdl);
		gdl = vi0000b1d0(gdl);
		gdl = viRenderViewportEdges(gdl);
		gdl = creditsDraw(gdl);
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

					chr->blurdrugamount -= g_Vars.lvupdate60 * (chr->blurnumtimesdied + 1);

					if (chr->blurdrugamount < 1) {
						chr->blurdrugamount = 0;
						chr->blurnumtimesdied = 0;
					}
				}
			}

			bviewSetMotionBlur(bluramount);

			gSPDisplayList(gdl++, &var800613a0);
			gSPDisplayList(gdl++, &var80061380);

			profileStart(PROFILEMARKER_LVR_PREPARE);
			viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
			viSetFovAspectAndSize(g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
					g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);
			var8005ef10[0] = 65536 * g_Vars.currentplayerstats->scale_bg2gfx;
			env0f1657f8();
			gdl = vi0000b280(gdl);
			gdl = vi0000b1d0(gdl);
			gdl = currentPlayerScissorToViewport(gdl);
			artifactsClear();
			profileEnd(PROFILEMARKER_LVR_PREPARE);

			profileStart(PROFILEMARKER_LVR_BONDGUN);
			if ((g_Vars.stagenum != STAGE_CITRAINING || (var80087260 <= 0 && g_MenuData.root != MENUROOT_MPSETUP))
					&& g_Vars.lvframenum <= 5
					&& !g_Vars.normmplayerisrunning
					&& g_Vars.tickmode != TICKMODE_CUTSCENE) {
				if (var80084050 < 6) {
					g_Vars.lockscreen = 1;
				}

				var80084050++;
			} else if (g_Vars.currentplayer->gunctrl.unk1583_06
					&& g_Vars.currentplayer->cameramode != CAMERAMODE_THIRDPERSON
					&& g_Vars.currentplayer->cameramode != CAMERAMODE_EYESPY
					&& var8009dfc0 == 0) {
				g_Vars.currentplayer->gunctrl.unk1583_06 = bgun0f09eae4();
			}
			profileEnd(PROFILEMARKER_LVR_BONDGUN);

			if (g_Vars.lockscreen) {
				gdl = bviewDrawMotionBlur(gdl, 0xffffffff, 255);
				g_Vars.lockscreen--;
			} else if (var8009dfc0) {
				gdl = viRenderViewportEdges(gdl);
				gdl = currentPlayerScissorToViewport(gdl);
				var8005ef10[0] = 65536;

				if (g_Vars.currentplayer->menuisactive) {
					PROFILE(PROFILEMARKER_LVR_MENU, gdl = menuRender(gdl));
				}
			} else {
				gdl = playerUpdateShootRot(gdl);

				gdl = viRenderViewportEdges(gdl);
				PROFILE(PROFILEMARKER_LVR_SKY1, gdl = skyRender(gdl));
				PROFILE(PROFILEMARKER_LVR_BGTICK, bgTick());
				PROFILE(PROFILEMARKER_LVR_LIGHTS, lightsTick());
				PROFILE(PROFILEMARKER_LVR_PROPS, propsTickPlayer(islastplayer));
				PROFILE(PROFILEMARKER_LVR_SCENARIOCHR, scenarioTickChr(NULL));
				PROFILE(PROFILEMARKER_LVR_PROPSSORT, propsSort());
				PROFILE(PROFILEMARKER_LVR_AUTOAIM, autoaimTick());
				PROFILE(PROFILEMARKER_LVR_HANDS, handsTickAttack());

				// Calculate lookingatprop
				profileStart(PROFILEMARKER_LVR_LOOKINGAT);

				// Only calculate lookingatprop if:
				// we are using the R-aimer in solo missions (including coop/anti), or
				// we are using the R-aimer in 1 player combat simulator, or
				// we are using the R-aimer in 2+ player combat simulator with a gun that uses prop tracking, or
				// we are playing Holo 1 (Looking Around), which uses lookingatprop
				if ((g_Vars.currentplayer->insightaimmode && (
								PLAYERCOUNT() == 1 || !g_Vars.normmplayerisrunning || weaponHasFlag(bgunGetWeaponNum(HAND_RIGHT), WEAPONFLAG_AIMTRACK)))
						|| (g_Vars.stagenum == STAGE_CITRAINING && (g_StageFlags & 0x00040000))) {
					g_Vars.currentplayer->lookingatprop.prop = func0f061d54(HAND_RIGHT, 0, 0);

					if (g_Vars.currentplayer->lookingatprop.prop) {
						if (g_Vars.currentplayer->lookingatprop.prop->type & (PROPTYPE_CHR | PROPTYPE_PLAYER)) {
							chr = g_Vars.currentplayer->lookingatprop.prop->chr;

							if ((chr->hidden & CHRHFLAG_CLOAKED) && !USINGDEVICE(DEVICE_IRSCANNER)) {
								g_Vars.currentplayer->lookingatprop.prop = NULL;
							}
						} else if (g_Vars.currentplayer->lookingatprop.prop->type & (PROPTYPE_OBJ | PROPTYPE_WEAPON | PROPTYPE_DOOR)) {
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
					s32 weaponnum = bgunGetWeaponNum(HAND_RIGHT);

					if (weaponnum >= WEAPON_FALCON2 && weaponnum <= WEAPON_FALCON2_SCOPE) {
						// Have to call this to make the laser dot appear
						func0f061d54(HAND_RIGHT, 0, 0);
					}

					g_Vars.currentplayer->lookingatprop.prop = NULL;
				}
				profileEnd(PROFILEMARKER_LVR_LOOKINGAT);

				profileStart(PROFILEMARKER_LVR_TRACKEDPROPS);
				if (gsetHasFunctionFlags(&g_Vars.currentplayer->hands[0].gset, FUNCFLAG_THREATDETECTOR)) {
					lvFindThreats();
				} else if (weaponHasFlag(bgunGetWeaponNum(HAND_RIGHT), WEAPONFLAG_AIMTRACK)) {
					s32 j;

					if (frIsInTraining()
							&& g_Vars.currentplayer->lookingatprop.prop
							&& g_Vars.currentplayer->insightaimmode) {
						func0f1a0924(g_Vars.currentplayer->lookingatprop.prop);
					} else if (lvUpdateTrackedProp(&g_Vars.currentplayer->lookingatprop, -1) == 0) {
						g_Vars.currentplayer->lookingatprop.prop = NULL;
					}

					for (j = 0; j < ARRAYCOUNT(g_Vars.currentplayer->trackedprops); j++) {
						if (!lvUpdateTrackedProp(&g_Vars.currentplayer->trackedprops[j], j)) {
							g_Vars.currentplayer->trackedprops[j].x1 = -1;
							g_Vars.currentplayer->trackedprops[j].x2 = -2;
						}
					}
				}
				profileEnd(PROFILEMARKER_LVR_TRACKEDPROPS);

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

							direction = g_Vars.currentplayer->eyespy->look;

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
								EXPLOSIONTYPE_DRAGONBOMBSPY, 0);
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

				PROFILE(PROFILEMARKER_LVR_PICKUP, propsTestForPickup());
				PROFILE(PROFILEMARKER_LVR_BG, gdl = bgRender(gdl));

				if (g_BeamsActive > 0) {
					PROFILE(PROFILEMARKER_LVR_BEAMS, gdl = propsRenderBeams(gdl));
				}

				if (g_ShardsActive) {
					PROFILE(PROFILEMARKER_LVR_SHARDS, gdl = shardsRender(gdl));
				}

				PROFILE(PROFILEMARKER_LVR_SPARKS, gdl = sparksRender(gdl));
				PROFILE(PROFILEMARKER_LVR_WEATHER, gdl = weatherRender(gdl));

				if (g_NbombsActive) {
					PROFILE(PROFILEMARKER_LVR_NBOMBS, gdl = nbombsRender(gdl));
				}

				PROFILE(PROFILEMARKER_LVR_HUD, gdl = playerRenderHud(gdl));

				{
					static struct sndstate *g_CutsceneStaticAudioHandle = NULL;
					static s32 g_CutsceneStaticTimer = 100;
					static u8 g_CutsceneStaticActive = false;
					bool cutscenehasstatic = false;
					u32 alpha;

					if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
						// Handle visual effects in cutscenes
						switch (g_CutsceneAnimNum) {
						case ANIM_CUT_CAVE_INTRO_CAM:
							// Horizon scanner in Air Base intro
							if (g_CutsceneCurAnimFrame60 > 839 && g_CutsceneCurAnimFrame60 < 1411) {
								gdl = bviewDrawHorizonScanner(gdl);
							}
							break;
						case ANIM_CUT_LUE_INTRO_CAM_01:
						case ANIM_CUT_LUE_INTRO_CAM_02:
						case ANIM_CUT_LUE_INTRO_CAM_03:
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

								gdl = bviewDrawFilmInterlace(gdl, 0xffffffff, 0xffffffff);

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
									gdl = bviewDrawStatic(gdl, 0xffffffff, cutscenestatic);
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
						gdl = bviewDrawSlayerRocketInterlace(gdl, 0xffffffff, 0xffffffff);

						if (g_Vars.currentplayer->badrockettime > 0) {
							u32 slayerstatic = g_Vars.currentplayer->badrockettime * 255 / TICKS(90);

							if (slayerstatic > 255) {
								slayerstatic = 255;
							}

							gdl = bviewDrawStatic(gdl, 0x4fffffff, slayerstatic);
						}
					}

					if (g_Vars.currentplayer->visionmode == VISIONMODE_SLAYERROCKETSTATIC) {
						gdl = bviewDrawStatic(gdl, 0x4fffffff, 255);
						g_Vars.currentplayer->visionmode = VISIONMODE_NORMAL;
					}

					if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY
							&& g_Vars.tickmode != TICKMODE_CUTSCENE) {
						s32 xraything = 99;

						if (g_Vars.currentplayer->erasertime < TICKS(200)) {
							xraything = 249 - (g_Vars.currentplayer->erasertime * 3 >> 2);
						}

						gdl = bviewDrawZoomBlur(gdl, 0xffffffff, xraything, 1.05f, 1.05f);
					}

					// Handle combat boosts
					if ((g_Vars.speedpillchange > 0 && g_Vars.speedpillchange < (PAL ? 26 : 30))
							|| (g_Vars.speedpillwant && !g_Vars.speedpillon)
							|| (!g_Vars.speedpillwant && g_Vars.speedpillon)) {
						if (g_Vars.speedpillchange == (PAL ? 26 : 30) && !g_Vars.speedpillwant) {
							sndStart(var80095200, lvGetSlowMotionType() ? SFX_JO_BOOST_ACTIVATE : SFX_ARGH_JO_02AD, 0, -1, -1, -1, -1, -1);
						}

						if (g_Vars.speedpillchange < (PAL ? 13 : 15)) {
							gdl = bviewDrawZoomBlur(gdl, 0xffffffff,
									g_Vars.speedpillchange * 180 / (PAL ? 13 : 15),
									(f32)g_Vars.speedpillchange * (PAL ? 0.023076923564076f : 0.02000000141561f) + 1.1f,
									(f32)g_Vars.speedpillchange * (PAL ? 0.023076923564076f : 0.02000000141561f) + 1.1f);
							gdl = playerDrawFade(gdl, 0xff, 0xff, 0xff,
									g_Vars.speedpillchange * (PAL ? 0.0076923076994717f : 0.0066666668280959f));
						} else {
							gdl = bviewDrawZoomBlur(gdl, 0xffffffff,
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
						bviewClearMotionBlur();
						gdl = bviewDrawMotionBlur(gdl, 0xffffffff, bluramount);
					}

					// Handle blur effect in cutscenes (Extraction intro?)
					if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
						f32 cutsceneblurfrac = playerGetCutsceneBlurFrac();

						if (cutsceneblurfrac > 0) {
							gdl = bviewDrawMotionBlur(gdl, 0xffffff00, cutsceneblurfrac * 255);
						}
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
							gdl = text0f153628(gdl);
							gdl = text0f153a34(gdl,
									g_ViBackData->viewleft, g_ViBackData->viewtop,
									g_ViBackData->viewleft + g_ViBackData->viewx,
									g_ViBackData->viewtop + g_ViBackData->viewy, 0xffffff00 | alpha);
							gdl = text0f153780(gdl);
						}
					}
				}

				PROFILE(PROFILEMARKER_LVR_SCENARIO, gdl = scenarioRenderHud(gdl));
				PROFILE(PROFILEMARKER_LVR_FADE, gdl = lvRenderFade(gdl));

				if (g_FrIsValidWeapon) {
					gdl = frRenderHud(gdl);
				}

				PROFILE(PROFILEMARKER_LVR_SKY2, gdl = sky0f1274d8(gdl));

				if (g_AmActive) {
					PROFILE(PROFILEMARKER_LVR_ACTIVEMENU, gdl = amRender(gdl));
				}

				var8005ef10[0] = 65536;

				if (g_Vars.currentplayer->menuisactive) {
					PROFILE(PROFILEMARKER_LVR_MENU, gdl = menuRender(gdl));
				}

				var8005ef10[0] = 65536 * g_Vars.currentplayerstats->scale_bg2gfx;

				if (g_Vars.mplayerisrunning) {
					gdl = mpRenderModalText(gdl);
				}

				if (g_Vars.currentplayer->dostartnewlife) {
					playerStartNewLife();
				}
			}

			PROFILE(PROFILEMARKER_LVR_ARTIFACTS, artifactsTick());

			if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
					&& playerHasSharedViewport()
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

		{
			g_MissionConfig.iscoop = false;
			g_Vars.mplayerisrunning = false;
			g_Vars.normmplayerisrunning = false;
			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = -1;
			g_Vars.antiplayernum = -1;
			g_MissionConfig.isanti = false;
			g_NumPlayers = 1;
			titleSetNextMode(TITLEMODE_SKIP);
			g_MissionConfig.difficulty = DIFF_A;
			lvSetDifficulty(DIFF_A);
			g_MissionConfig.stageindex = g_Cutscenes[g_Vars.autocutgroupcur].mission;
			g_MissionConfig.stagenum = g_Cutscenes[g_Vars.autocutgroupcur].stage;
			g_TitleNextStage = g_Cutscenes[g_Vars.autocutgroupcur].stage;
			mainChangeToStage(g_Cutscenes[g_Vars.autocutgroupcur].stage);
		}

		g_Vars.autocutgroupleft--;

		if (g_Vars.autocutgroupleft > 0) {
			g_Vars.autocutgroupcur++;
		} else {
			g_Vars.autocutgroupcur = -1;
		}
	}

	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, g_ViBackData->x, g_ViBackData->y);

	gdl = lvPrint(gdl);

	return gdl;
}

static void lvResetSoloHandicaps(void)
{
	if (g_Vars.antiplayernum >= 0) {
		if (g_Difficulty == DIFF_A) {
			g_AutogunAccuracyScale = 0.5f;
			g_AutogunDamageTxScale = 0.5f;
			g_AutogunDamageRxScale = 2;
			g_EnemyAccuracyScale = 0.5f;
			g_PlayerDamageRxScale = 0.35f;
			g_PlayerDamageTxScale = 4;
			g_ExplosionDamageTxScale = 0.25f;
			g_AutoAimScale = 1.5f;
			g_AmmoQuantityScale = 3;
			g_AttackWalkDurationScale = 0.2f;
		} else if (g_Difficulty == DIFF_SA) {
			g_AutogunAccuracyScale = 0.5f;
			g_AutogunDamageTxScale = 0.5f;
			g_AutogunDamageRxScale = 1.5f;
			g_EnemyAccuracyScale = 0.6f;
			g_PlayerDamageRxScale = 0.5f;
			g_PlayerDamageTxScale = 3;
			g_ExplosionDamageTxScale = 0.25f;
			g_AutoAimScale = 1.1f;
			g_AmmoQuantityScale = 2.5f;
			g_AttackWalkDurationScale = 0.5f;
		} else {
			g_AutogunAccuracyScale = 0.5f;
			g_AutogunDamageTxScale = 0.5f;
			g_AutogunDamageRxScale = 1;
			g_EnemyAccuracyScale = 0.7f;
			g_PlayerDamageRxScale = 0.65f;
			g_PlayerDamageTxScale = 2;
			g_ExplosionDamageTxScale = 0.25f;
			g_AutoAimScale = 0.75f;
			g_AmmoQuantityScale = 2;
			g_AttackWalkDurationScale = 1;
		}
	} else if (g_Vars.coopplayernum >= 0) {
		if (g_Difficulty == DIFF_A) {
			g_AutogunAccuracyScale = 0.5f;
			g_AutogunDamageTxScale = 0.5f;
			g_AutogunDamageRxScale = 2;
			g_EnemyAccuracyScale = 0.6f;
			g_PlayerDamageRxScale = 0.5f;
			g_PlayerDamageTxScale = 2;
			g_ExplosionDamageTxScale = 0.25f;
			g_AutoAimScale = 1.5f;
			g_AmmoQuantityScale = 2;
			g_AttackWalkDurationScale = 0.2f;
		} else if (g_Difficulty == DIFF_SA) {
			g_AutogunAccuracyScale = 0.75f;
			g_AutogunDamageTxScale = 1;
			g_AutogunDamageRxScale = 1;
			g_EnemyAccuracyScale = 0.75f;
			g_PlayerDamageRxScale = 1;
			g_PlayerDamageTxScale = 1;
			g_ExplosionDamageTxScale = 1;
			g_AutoAimScale = 0.75f;
			g_AmmoQuantityScale = 1.5f;
			g_AttackWalkDurationScale = 0.5f;
		} else {
			g_AutogunAccuracyScale = 1;
			g_AutogunDamageTxScale = 1.5f;
			g_AutogunDamageRxScale = 1;
			g_EnemyAccuracyScale = 1.5f;
			g_PlayerDamageRxScale = 1.5f;
			g_PlayerDamageTxScale = 1;
			g_ExplosionDamageTxScale = 1.5f;
			g_AutoAimScale = 0.2f;
			g_AmmoQuantityScale = 1;
			g_AttackWalkDurationScale = 1;
		}
	} else {
		if (g_Difficulty == DIFF_A) {
			g_AutogunAccuracyScale = 0.5f;
			g_AutogunDamageTxScale = 0.5f;
			g_AutogunDamageRxScale = 2;
			g_EnemyAccuracyScale = 0.6f;
			g_PlayerDamageRxScale = 0.5f;
			g_PlayerDamageTxScale = 2;
			g_ExplosionDamageTxScale = 0.25f;
			g_AutoAimScale = 1.5f;
			g_AmmoQuantityScale = 2;
			g_AttackWalkDurationScale = 0.2f;
		} else if (g_Difficulty == DIFF_SA) {
			g_AutogunAccuracyScale = 0.75f;
			g_AutogunDamageTxScale = 0.75f;
			g_AutogunDamageRxScale = 1;
			g_EnemyAccuracyScale = 0.8f;
			g_PlayerDamageRxScale = 0.6f;
			g_PlayerDamageTxScale = 1;
			g_ExplosionDamageTxScale = 0.75f;
			g_AutoAimScale = 0.75f;
			g_AmmoQuantityScale = 1.5f;
			g_AttackWalkDurationScale = 0.5f;
		} else if (g_Difficulty == DIFF_PA) {
			g_AutogunAccuracyScale = 1;
			g_AutogunDamageTxScale = 1;
			g_AutogunDamageRxScale = 1;
			g_EnemyAccuracyScale = 1.175f;
			g_PlayerDamageRxScale = 1;
			g_PlayerDamageTxScale = 1;
			g_ExplosionDamageTxScale = 1;
			g_AutoAimScale = 0.2f;
			g_AmmoQuantityScale = 1;
			g_AttackWalkDurationScale = 1;
		} else if (g_Difficulty == DIFF_PD) {
			g_AutogunAccuracyScale = 1;
			g_AutogunDamageTxScale = 1;
			g_AutogunDamageRxScale = 1;
			g_EnemyAccuracyScale = 1.1f;
			g_PlayerDamageRxScale = 1;
			g_PlayerDamageTxScale = 1;
			g_ExplosionDamageTxScale = 1;
			g_AutoAimScale = 1;
			g_AmmoQuantityScale = 1;
			g_AttackWalkDurationScale = 1;
		}
	}
}

static void lvUpdateSoloHandicaps(void)
{
	if (g_Difficulty == DIFF_A && g_Vars.coopplayernum < 0 && g_Vars.antiplayernum < 0) {
		f32 totalhealth;
		f32 frac = 1;

		totalhealth = playerGetHealthFrac() + playerGetShieldFrac();

		if (totalhealth <= 0.125f) {
			frac = 0.5f;
		} else if (totalhealth <= 0.6f) {
			frac = (totalhealth - 0.125f) * 0.5f / 0.47500002384186f + 0.5f;
		}

		g_AutogunAccuracyScale = 0.5f * frac;
		g_AutogunDamageTxScale = 0.5f * frac;
		g_PlayerDamageRxScale = 0.5f * frac;
		g_ExplosionDamageTxScale = 0.25f * frac;
	}
}

s32 lvGetSlowMotionType(void)
{
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
	}

	return SLOWMOTION_OFF;
}

void lvTick(void)
{
	s32 j;
	s32 i;

	lvCheckPauseStateChanged();

	if (g_Vars.unk0004e4) {
		paksTick();
	}

	if (g_Vars.joydisableframestogo > 0) {
		g_Vars.joydisableframestogo--;
	} else if (g_Vars.joydisableframestogo == 0) {
		joy00013938();

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

	for (j = 0; j < PLAYERCOUNT(); j++) {
		g_Vars.players[j]->hands[HAND_LEFT].hasdotinfo = false;
		g_Vars.players[j]->hands[HAND_RIGHT].hasdotinfo = false;
	}

	if (g_LvIsPaused) {
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
											&& roomIsOnPlayerScreen(rooms[r], otherplayernum)) {
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

	g_Vars.lvupdate60 = g_Vars.lvupdate240 + g_Vars.lvupdate240rem;
	g_Vars.lvupdate240rem = g_Vars.lvupdate60 & 3;
	g_Vars.lvupdate60 >>= 2;

	if (g_Vars.lvupdate240 > 0) {
		g_Vars.lvframenum++;
	}

	g_Vars.lvupdate60f = g_Vars.lvupdate240 * 0.25f;
	g_Vars.lvframe60 += g_Vars.lvupdate60;
	g_Vars.lvframe240 += g_Vars.lvupdate240;
	g_Vars.lvupdate60frealprev = g_Vars.lvupdate60freal;
	g_Vars.lvupdate60freal = PALUPF(g_Vars.lvupdate60f);

	bgunTickBoost();

	if (g_HudmsgsActive) {
		PROFILE(PROFILEMARKER_LVT_HUDMSGS, hudmsgsTick());
	}

	if (g_IsTitleDemo && (joyGetButtonsPressedThisFrame(0, 0xffff) != 0
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
				|| joyGetStickY(3) < -10)) {
		if (g_Vars.stagenum != STAGE_TITLE) {
			titleSetNextMode(TITLEMODE_SKIP);
			mainChangeToStage(STAGE_TITLE);
		}

		g_IsTitleDemo = false;
	}

	// Handle MP match ending
	if (g_Vars.normmplayerisrunning && g_Vars.stagenum < STAGE_TITLE) {
		switch (g_MpTimeState) {
		case 0: // no time limit
			break;
		case 1: // waiting for 1 minute mark
			{
				s32 nexttime = g_Vars.lvupdate60 + g_StageTimeElapsed60;
				s32 warntime = TICKS(g_MpTimeLimit60) - TICKS(3600);
				s32 i;

				if (nexttime >= warntime) {
					if (g_MpTimeLimit60 != 60 * 60) {
						for (i = 0; i < PLAYERCOUNT(); i++) {
							setCurrentPlayerNum(i);
							hudmsgCreate(langGet(L_MISC_068), HUDMSGTYPE_DEFAULT); // "One minute left."
						}
					}

					g_MpTimeState++;
				}
			}
			break;
		case 2: // waiting for 10 second mark
			{
				s32 nexttime = g_Vars.lvupdate60 + g_StageTimeElapsed60;

				if (nexttime >= TICKS(g_MpTimeLimit60) - TICKS(600)) {
					g_MpTimeState++;
				}
			}
			break;
		case 3: // sounding alarm and waiting for match end
			{
				if (g_MiscAudioHandle == NULL && !g_LvIsPaused) {
					snd00010718(&g_MiscAudioHandle, 0, 0x7fff, 0x40, SFX_ALARM_DEFAULT, 1, 1, -1, 1);
				}

				if (g_Vars.lvupdate60 + g_StageTimeElapsed60 >= TICKS(g_MpTimeLimit60)) {
					mainEndStage();
					g_MpTimeState++;
				}
			}
			break;
		}

		if (g_Vars.lvupdate240 != 0) {
			if (!g_MpMatchIsEnding) {
				if (g_MpScoreLimit > 0) {
					struct ranking rankings[MAX_MPCHRS];
					s32 count = mpGetPlayerRankings(rankings);

					for (i = 0; i < count; i++) {
						if (rankings[i].score >= g_MpScoreLimit) {
							g_MpMatchIsEnding = true;
							break;
						}
					}
				}

				if (!g_MpMatchIsEnding && g_MpTeamScoreLimit > 0) {
					struct ranking rankings[MAX_MPCHRS];
					s32 count = mpGetTeamRankings(rankings);

					for (i = 0; i < count; i++) {
						if (rankings[i].score >= g_MpTeamScoreLimit) {
							g_MpMatchIsEnding = true;
							break;
						}
					}
				}
			} else {
				bool anyonedying = false;

				for (i = 0; i < PLAYERCOUNT(); i++) {
					if (g_Vars.players[i]->isdead) {
						if (g_Vars.players[i]->redbloodfinished == false
								|| g_Vars.players[i]->deathanimfinished == false
								|| g_Vars.players[i]->colourfadetimemax60 >= 0) {
							anyonedying = true;
							break;
						}
					}
				}

				for (i = 0; i < g_MpNumChrs; i++) {
					if (g_MpAllChrPtrs[i]->actiontype == ACT_DIE) {
						anyonedying = true;
						break;
					}
				}

				if (!anyonedying) {
					mainEndStage();
				}
			}
		}
	}

	g_StageTimeElapsed60 += g_Vars.lvupdate60;

	g_ViBackData->usezbuf = true;

	if (g_Vars.stagenum == STAGE_TITLE) {
		titleTick();
		musicTick();
	} else if (g_Vars.stagenum == STAGE_BOOTPAKMENU) {
		setCurrentPlayerNum(0);
		menuTick();
		musicTick();
		pakExecuteDebugOperations();
	} else if (g_Vars.stagenum == STAGE_4MBMENU) {
		menuTick();
		musicTick();
		pakExecuteDebugOperations();
	} else if (g_Vars.stagenum == STAGE_CREDITS) {
		musicTick();
	} else {
		PROFILE(PROFILEMARKER_LVT_VTXSTORE, vtxstoreTick());
		lvUpdateSoloHandicaps();
		skyTick();
		PROFILE(PROFILEMARKER_LVT_CASINGS, casingsTick());

		if (g_ShardsActive) {
			PROFILE(PROFILEMARKER_LVT_SHARDS, shardsTick());
		}

		PROFILE(PROFILEMARKER_LVT_SPARKS, sparksTick());
		PROFILE(PROFILEMARKER_LVT_WALLHITS, wallhitsTick());

		profileStart(PROFILEMARKER_LVT_WEATHER);
		if (g_WeatherActive) {
			weatherTick();
		}
		profileEnd(PROFILEMARKER_LVT_WEATHER);

		profileStart(PROFILEMARKER_LVT_NBOMBS);
		if (g_NbombsActive) {
			nbombsTick();
		}
		profileEnd(PROFILEMARKER_LVT_NBOMBS);

		PROFILE(PROFILEMARKER_LVT_MISCSFX, lvUpdateMiscSfx());
		PROFILE(PROFILEMARKER_LVT_SND, sndTick());
		PROFILE(PROFILEMARKER_LVT_PAK, pakExecuteDebugOperations());
		PROFILE(PROFILEMARKER_LVT_LIGHTING, lightingTick());
		PROFILE(PROFILEMARKER_LVT_BOLTBEAMS, boltbeamsTick());

		if (g_AmActive) {
			PROFILE(PROFILEMARKER_LVT_ACTIVEMENU, amTick());
		}

		PROFILE(PROFILEMARKER_LVT_MENU, menuTick());
		PROFILE(PROFILEMARKER_LVT_SCENARIO, scenarioTick());

		profileStart(PROFILEMARKER_LVT_PROPS);
		if (!g_MainIsEndscreen) {
			propsTick();
		}
		profileEnd(PROFILEMARKER_LVT_PROPS);

		PROFILE(PROFILEMARKER_LVT_MUSIC, musicTick());
		PROFILE(PROFILEMARKER_LVT_PADEFFECTS, propsTickPadEffects());

		if (g_StageNum == STAGE_CITRAINING) {
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


void lvTickPlayer(void)
{
	f32 xdiff;
	f32 zdiff;

	playerTick(true);

	xdiff = g_Vars.currentplayer->prop->pos.x - g_Vars.currentplayer->bondprevpos.x;
	zdiff = g_Vars.currentplayer->prop->pos.z - g_Vars.currentplayer->bondprevpos.z;

	g_Vars.currentplayerstats->distance += sqrtf(xdiff * xdiff + zdiff * zdiff);
}

void lvStop(void)
{
	paksStop(true);

	if (g_MiscAudioHandle && sndGetState(g_MiscAudioHandle)) {
		audioStop(g_MiscAudioHandle);
	}

	if (g_Vars.stagenum < NUM_STAGES) {
		s32 bank = langGetLangBankIndexFromStagenum(g_Vars.stagenum);
		langClearBank(bank);
	}

	chrmgrStop();
	explosionsStop();
	smokeStop();
	shardsStop();
	propsStop();
	objsStop();
	weatherStop();
	objectivesStop();
	bgunStop();
	propsndStop();
	musicStop();
	hudmsgsStop();

	if (g_Vars.stagenum < NUM_STAGES) {
		bgStop();
	}

	func00033dd8();

	if (g_FileState == FILESTATE_CHANGINGAGENT) {
		menuPlaySound(MENUSOUND_EXPLOSION);
		g_FileState = FILESTATE_UNSELECTED;
	}

	menuStop();
}

static void lvCheckPauseStateChanged(void)
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

	g_LvIsPaused = paused;
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
