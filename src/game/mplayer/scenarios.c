#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/dlights.h"
#include "game/game_006900.h"
#include "game/game_00c490.h"
#include "game/prop.h"
#include "game/game_092610.h"
#include "game/atan2f.h"
#include "game/bondgun.h"
#include "game/player.h"
#include "game/savebuffer.h"
#include "game/hudmsg.h"
#include "game/menu.h"
#include "game/inventory/inventory.h"
#include "game/playermgr.h"
#include "game/game_1531a0.h"
#include "game/mplayer/setup.h"
#include "game/mplayer/scenarios.h"
#include "game/radar.h"
#include "game/botcmd.h"
#include "game/game_19aa80.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/snd.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/collision.h"
#include "data.h"
#include "types.h"

/**
 * There are six multiplayer scenarios:
 *
 * - Combat
 * - Hold the Briefcase (HTB)
 * - Capture the Case (CTC)
 * - Hack that Mac (HTM) - labelled as Hacker Central
 * - King of the Hill (KOH)
 * - Pop a Cap (PAC)
 *
 * Each scenario registers callback functions for certain events. For example,
 * code elsewhere in the game may call scenarioTick, then scenarioTick checks
 * if the current scenario has a tick callback defined (eg. htbTick). If so,
 * that scenario's callback is run.
 */

struct mpscenario {
	struct menudialogdef *optionsdialog;
	void (*initfunc)(void);
	s32 (*numpropsfunc)(void);
	void (*initpropsfunc)(void);
	void (*tickfunc)(void);
	void (*tickchrfunc)(struct chrdata *chr);
	Gfx *(*hudfunc)(Gfx *gdl);
	void (*calcscorefunc)(struct mpchrconfig *mpchr, s32 chrnum, s32 *score, s32 *deaths);
	Gfx *(*radarextrafunc)(Gfx *gdl);
	bool (*radarchrfunc)(Gfx **gdl, struct prop *prop);
	bool (*highlightpropfunc)(struct prop *prop, s32 *colour);
	bool (*spawnfunc)(f32 arg0, struct coord *pos, s16 *rooms, struct prop *prop, f32 *arg4);
	s32 (*maxteamsfunc)(void);
	bool (*isroomhighlightedfunc)(s16 room);
	void (*highlightroomfunc)(s16 room, s32 *arg1, s32 *arg2, s32 *arg3);
	void *unk3c; // never hooked into nor fired
	void (*readsavefunc)(struct savebuffer *buffer);
	void (*writesavefunc)(struct savebuffer *buffer);
};

#if VERSION >= VERSION_JPN_FINAL
u8 jpnfill7[0x40];
#endif

struct scenariodata g_ScenarioData;

#if VERSION >= VERSION_JPN_FINAL
char *func0f180440jf(char *arg0, s32 arg1);

GLOBAL_ASM(
glabel func0f180440jf
/*  f180440:	00057100 */ 	sll	$t6,$a1,0x4
/*  f180444:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f180448:	01c57023 */ 	subu	$t6,$t6,$a1
/*  f18044c:	3c0f800b */ 	lui	$t7,0x800b
/*  f180450:	25efcb00 */ 	addiu	$t7,$t7,-13568
/*  f180454:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f180458:	01cf3021 */ 	addu	$a2,$t6,$t7
/*  f18045c:	00c01825 */ 	move	$v1,$a2
/*  f180460:	1040000a */ 	beqz	$v0,.JF0f18048c
/*  f180464:	00403825 */ 	move	$a3,$v0
/*  f180468:	2405000a */ 	li	$a1,0xa
.JF0f18046c:
/*  f18046c:	50a70004 */ 	beql	$a1,$a3,.JF0f180480
/*  f180470:	90820001 */ 	lbu	$v0,0x1($a0)
/*  f180474:	a0620000 */ 	sb	$v0,0x0($v1)
/*  f180478:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f18047c:	90820001 */ 	lbu	$v0,0x1($a0)
.JF0f180480:
/*  f180480:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f180484:	1440fff9 */ 	bnez	$v0,.JF0f18046c
/*  f180488:	00403825 */ 	move	$a3,$v0
.JF0f18048c:
/*  f18048c:	a0600000 */ 	sb	$zero,0x0($v1)
/*  f180490:	03e00008 */ 	jr	$ra
/*  f180494:	00c01025 */ 	move	$v0,$a2
);
#endif

s32 menuhandlerMpDisplayTeam(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKDISABLED) {
		if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
			return false;
		}

		return true;
	}

	return menuhandlerMpCheckboxOption(operation, item, data);
}

s32 menuhandlerMpOneHitKills(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_CHECKDISABLED || operation == MENUOP_CHECKHIDDEN) {
		if (mpIsFeatureUnlocked(MPFEATURE_ONEHITKILLS)) {
			return false;
		}

		return true;
	}

	return menuhandlerMpCheckboxOption(operation, item, data);
}

s32 menuhandlerMpSlowMotion(s32 operation, struct menuitem *item, union handlerdata *data)
{
	u16 labels[] = {
		L_MPMENU_240, // "Off"
		L_MPMENU_241, // "On"
		L_MPMENU_242, // "Smart"
	};

	switch (operation) {
	case MENUOP_CHECKDISABLED:
	case MENUOP_CHECKHIDDEN:
		if (mpIsFeatureUnlocked(MPFEATURE_SLOWMOTION)) {
			return false;
		}
		return true;
	case MENUOP_GETOPTIONCOUNT:
		data->dropdown.value = 3;
		break;
	case MENUOP_GETOPTIONTEXT:
		return (s32)langGet(labels[data->dropdown.value]);
	case MENUOP_SET:
		g_MpSetup.options &= ~(MPOPTION_SLOWMOTION_ON | MPOPTION_SLOWMOTION_SMART);

		if (data->dropdown.value == SLOWMOTION_ON) {
			g_MpSetup.options |= MPOPTION_SLOWMOTION_ON;
		} else if (data->dropdown.value == SLOWMOTION_SMART) {
			g_MpSetup.options |= MPOPTION_SLOWMOTION_SMART;
		}
		break;
	case MENUOP_GETOPTIONVALUE:
		if (g_MpSetup.options & MPOPTION_SLOWMOTION_SMART) {
			data->dropdown.value = SLOWMOTION_SMART;
		} else if (g_MpSetup.options & MPOPTION_SLOWMOTION_ON) {
			data->dropdown.value = SLOWMOTION_ON;
		} else {
			data->dropdown.value = SLOWMOTION_OFF;
		}
		break;
	}

	return 0;
}

// Include the code files where each scenario implements its callbacks
#include "scenarios/combat.inc"
#include "scenarios/holdthebriefcase.inc"
#include "scenarios/capturethecase.inc"
#include "scenarios/kingofthehill.inc"
#include "scenarios/hackthatmac.inc"
#include "scenarios/popacap.inc"

// Define the scenario callbacks
struct mpscenario g_MpScenarios[] = {
	{
		&g_MpCombatOptionsMenuDialog,
	}, {
		&g_HtbOptionsMenuDialog,
		htbInit,
		htbNumProps,
		htbInitProps,
		htbTick,
		htbTickChr,
		htbRenderHud,
		htbCalculatePlayerScore,
		htbRadarExtra,
		htbRadarChr,
		htbHighlightProp,
	}, {
		&g_HtmOptionsMenuDialog,
		htmInit,
		htmNumProps,
		htmInitProps,
		htmTick,
		htmTickChr,
		htmRenderHud,
		htmCalculatePlayerScore,
		htmRadarExtra,
		htmRadarChr,
		htmHighlightProp,
	}, {
		&g_PacOptionsMenuDialog,
		pacInit,
		NULL,
		pacInitProps,
		pacTick,
		NULL,
		pacRenderHud,
		pacCalculatePlayerScore,
		pacRadarExtra,
		pacRadarChr,
		pacHighlightProp,
	}, {
		&g_KohOptionsMenuDialog,
		kohInit,
		NULL,
		kohInitProps,
		kohTick,
		NULL,
		kohRenderHud,
		kohCalculatePlayerScore,
		kohRadarExtra,
		NULL,
		NULL,
		NULL,
		NULL,
		kohIsRoomHighlighted,
		kohHighlightRoom,
		NULL,
		kohReadSave,
		kohWriteSave
	}, {
		&g_CtcOptionsMenuDialog,
		ctcInit,
		ctcNumProps,
		ctcInitProps,
		ctcTick,
		ctcTickChr,
		NULL,
		ctcCalculatePlayerScore,
		ctcRadarExtra,
		ctcRadarChr,
		ctcHighlightProp,
		ctcChooseSpawnLocation,
		ctcGetMaxTeams,
		ctcIsRoomHighlighted,
		ctcHighlightRoom,
	},
};

struct mpscenariooverview g_MpScenarioOverviews[] = {
	// name, short name, require feature, team only
	{ L_MPMENU_246, L_MPMENU_253, 0,                      false }, // "Combat", "Combat"
	{ L_MPMENU_247, L_MPMENU_254, MPFEATURE_SCENARIO_HTB, false }, // "Hold the Briefcase", "Briefcase"
	{ L_MPMENU_248, L_MPMENU_255, MPFEATURE_SCENARIO_HTM, false }, // "Hacker Central", "Hacker"
	{ L_MPMENU_249, L_MPMENU_256, MPFEATURE_SCENARIO_PAC, false }, // "Pop a Cap", "Pop"
	{ L_MPMENU_250, L_MPMENU_257, MPFEATURE_SCENARIO_KOH, true  }, // "King of the Hill", "Hill"
	{ L_MPMENU_251, L_MPMENU_258, MPFEATURE_SCENARIO_CTC, true  }, // "Capture the Case", "Capture"
};

/**
 * While the options dialog is open, check if another player has changed the
 * scenario to a different one. If so, replace this dialog with the new one.
 */
s32 mpOptionsMenuDialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if (g_Menus[g_MpPlayerNum].curdialog->definition != g_MpScenarios[g_MpSetup.scenario].optionsdialog) {
			s32 i;
			s32 end = ARRAYCOUNT(g_MpScenarios);

			for (i = 0; i < end; i++) {
				if (g_Menus[g_MpPlayerNum].curdialog->definition == g_MpScenarios[i].optionsdialog) {
					break;
				}
			}

			if (i < end) {
				menuPopDialog();
				menuPushDialog(g_MpScenarios[g_MpSetup.scenario].optionsdialog);
			}
		}
	}

	return 0;
}

char *mpMenuTextScenarioShortName(struct menuitem *item)
{
	sprintf(g_StringPointer, "%s\n", langGet(g_MpScenarioOverviews[g_MpSetup.scenario].shortname));
	return g_StringPointer;
}

char *mpMenuTextScenarioName(struct menuitem *item)
{
	sprintf(g_StringPointer, "%s\n", langGet(g_MpScenarioOverviews[g_MpSetup.scenario].name));
	return g_StringPointer;
}

struct scenariogroup {
	s32 startindex;
	u16 textid;
};

s32 scenarioScenarioMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	struct scenariogroup groups[] = {
		{ 0, L_MPMENU_244 }, // "Free for All!"
		{ 4, L_MPMENU_245 }, // "-Teamwork-"
	};

	s32 i;
	s32 count = 0;
	bool teamgame = true;

	if (item->param) {
		if (g_Vars.mpquickteam == MPQUICKTEAM_PLAYERSONLY || g_Vars.mpquickteam == MPQUICKTEAM_PLAYERSANDSIMS) {
			teamgame = false;
		}
	}

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		for (i = 0; i < ARRAYCOUNT(g_MpScenarioOverviews); i++) {
			if (mpIsFeatureUnlocked(g_MpScenarioOverviews[i].requirefeature)
					&& (teamgame || g_MpScenarioOverviews[i].teamonly == false)) {
				count++;
			}
		}

		data->list.value = count;
		break;
	case MENUOP_GETOPTIONTEXT:
		for (i = 0; i < ARRAYCOUNT(g_MpScenarioOverviews); i++) {
			if (mpIsFeatureUnlocked(g_MpScenarioOverviews[i].requirefeature)
					&& (teamgame || g_MpScenarioOverviews[i].teamonly == false)) {
				if (count == data->list.value) {
					return (s32)langGet(g_MpScenarioOverviews[i].name);
				}

				count++;
			}
		}

		break;
	case MENUOP_SET:
		for (i = 0; i < ARRAYCOUNT(g_MpScenarioOverviews); i++) {
			if (mpIsFeatureUnlocked(g_MpScenarioOverviews[i].requirefeature)
					&& (teamgame || g_MpScenarioOverviews[i].teamonly == false)) {
				if (count == data->list.value) {
					g_MpSetup.scenario = i;
					break;
				}

				count++;
			}
		}

		scenarioInit();
		break;
	case MENUOP_GETOPTIONVALUE:
		for (i = 0; i < ARRAYCOUNT(g_MpScenarioOverviews); i++) {
			if (mpIsFeatureUnlocked(g_MpScenarioOverviews[i].requirefeature)
					&& (teamgame || g_MpScenarioOverviews[i].teamonly == false)) {
				if (i == g_MpSetup.scenario) {
					data->list.value = count;
					break;
				}

				count++;
			}
		}

		break;
	case MENUOP_GETOPTGROUPCOUNT:
		data->list.value = 2;

		if (!teamgame || (!mpIsFeatureUnlocked(MPFEATURE_SCENARIO_KOH) && !mpIsFeatureUnlocked(MPFEATURE_SCENARIO_CTC))) {
			data->list.value--;
		}
		break;
	case MENUOP_GETOPTGROUPTEXT:
		return (s32)langGet(groups[data->list.value].textid);
	case MENUOP_GETGROUPSTARTINDEX:
		for (i = 0; i < groups[data->list.value].startindex; i++) {
			if (mpIsFeatureUnlocked(g_MpScenarioOverviews[i].requirefeature)
					&& (teamgame || g_MpScenarioOverviews[i].teamonly == false)) {
				count++;
			}
		}

		data->list.groupstartindex = count;
		break;
	}

	return 0;
}

s32 menuhandlerMpOpenOptions(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPushDialog(g_MpScenarios[g_MpSetup.scenario].optionsdialog);
	}

	return 0;
}

/**
 * Allow a callback to read data from the setup file's save file buffer.
 *
 * There is one byte available to be read. If not handled, the byte will be
 * consumed and ignored.
 *
 * Used by KOH to read the mphilltime.
 */
void scenarioReadSave(struct savebuffer *buffer)
{
	if (g_MpScenarios[g_MpSetup.scenario].readsavefunc) {
		g_MpScenarios[g_MpSetup.scenario].readsavefunc(buffer);
	} else {
		savebufferReadBits(buffer, 8);
	}
}

/**
 * Allow a callback to write data to the setup file's save file buffer.
 *
 * There is one byte available to be written. If not handled, the byte will be
 * written as 0.
 *
 * Used by KOH to write the mphilltime.
 */
void scenarioWriteSave(struct savebuffer *buffer)
{
	if (g_MpScenarios[g_MpSetup.scenario].writesavefunc) {
		g_MpScenarios[g_MpSetup.scenario].writesavefunc(buffer);
	} else {
		savebufferOr(buffer, 0, 8);
	}
}

/**
 * Called whenever a scenario is selected/applied in the match settings.
 *
 * The callback should initialise all the properties in g_ScenarioData.
 */
void scenarioInit(void)
{
	if (g_MpScenarios[g_MpSetup.scenario].initfunc) {
		g_MpScenarios[g_MpSetup.scenario].initfunc();
	}
}

/**
 * Return the number of additional props that will be created, such as
 * briefcases and uplinks.
 */
s32 scenarioNumProps(void)
{
	s32 result = 0;

	if (g_MpScenarios[g_MpSetup.scenario].numpropsfunc) {
		result = g_MpScenarios[g_MpSetup.scenario].numpropsfunc();
	}

	return result;
}

/**
 * Create the additional props, such as briefcases and uplinks.
 */
void scenarioInitProps(void)
{
	if (g_MpScenarios[g_MpSetup.scenario].initpropsfunc) {
		g_MpScenarios[g_MpSetup.scenario].initpropsfunc();
	}
}

/**
 * At the start of each match, a hud message appears for all players containing
 * the challenge name if it's a challenge, or the scenario name if not.
 */
void scenarioCreateMatchStartHudmsgs(void)
{
	s32 i;
	s32 prevplayernum = g_Vars.currentplayernum;
	char challengename[60];
	char scenarioname[60];

	if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
#if VERSION >= VERSION_JPN_FINAL
		sprintf(challengename, "%s\n", mpGetChallengeNameBySlot(mpGetCurrentChallengeIndex()));
#else
		sprintf(challengename, "%s:\n", mpGetChallengeNameBySlot(mpGetCurrentChallengeIndex()));
#endif
	}

	sprintf(scenarioname, "%s\n", langGet(g_MpScenarioOverviews[g_MpSetup.scenario].name));

	for (i = 0; i < g_MpNumChrs; i++) {
		if (g_MpAllChrPtrs[i]->aibot == NULL) {
			setCurrentPlayerNum(i);

			if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
#if VERSION >= VERSION_JPN_FINAL
				hudmsgCreateWithFlags(challengename, HUDMSGTYPE_DEFAULT, HUDMSGFLAG_ONLYIFALIVE | HUDMSGFLAG_20);
#else
				hudmsgCreateWithFlags(challengename, HUDMSGTYPE_DEFAULT, HUDMSGFLAG_ONLYIFALIVE);
#endif
			}

#if VERSION >= VERSION_JPN_FINAL
			hudmsgCreateWithFlags(scenarioname, HUDMSGTYPE_DEFAULT, HUDMSGFLAG_ONLYIFALIVE | HUDMSGFLAG_20);
#else
			hudmsgCreateWithFlags(scenarioname, HUDMSGTYPE_DEFAULT, HUDMSGFLAG_ONLYIFALIVE);
#endif
		}
	}

	setCurrentPlayerNum(prevplayernum);
}

/**
 * Called on every frame during a match, including while paused.
 */
void scenarioTick(void)
{
	if (g_Vars.normmplayerisrunning) {
		if (g_Vars.lvframenum == 5) {
			scenarioCreateMatchStartHudmsgs();
		}

		if (g_MpScenarios[g_MpSetup.scenario].tickfunc) {
			g_MpScenarios[g_MpSetup.scenario].tickfunc();
		}
	}
}

/**
 * Tick a single chr.
 *
 * If chr is provided then it will be a bot.
 * If chr is NULL then the handler should tick the current player instead.
 */
void scenarioTickChr(struct chrdata *chr)
{
	if (g_Vars.normmplayerisrunning && g_MpScenarios[g_MpSetup.scenario].tickchrfunc) {
		g_MpScenarios[g_MpSetup.scenario].tickchrfunc(chr);
	}
}

/**
 * Render any HUD information such as timers.
 */
Gfx *scenarioRenderHud(Gfx *gdl)
{
	s32 viewleft;
	s32 viewright;
	s32 viewtop;
	s32 viewheight;
	s32 cplayernum;
	s32 playercount;
	struct chrdata *chr;
	u32 colour;

	if (g_Vars.normmplayerisrunning) {
		if (g_MpScenarios[g_MpSetup.scenario].hudfunc) {
#if VERSION >= VERSION_NTSC_1_0
			if (g_MpSetup.paused != MPPAUSEMODE_GAMEOVER && g_NumReasonsToEndMpMatch == 0) {
				gDPSetTextureFilter(gdl++, G_TF_POINT);
				gDPSetColorDither(gdl++, G_CD_DISABLE);
				gSPClearGeometryMode(gdl++, G_ZBUFFER);
				gDPPipeSync(gdl++);
				gDPSetTexturePersp(gdl++, G_TP_NONE);
				gDPSetCycleType(gdl++, G_CYC_FILL);
				gDPSetRenderMode(gdl++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
				gDPPipelineMode(gdl++, G_PM_1PRIMITIVE);

				gdl = g_MpScenarios[g_MpSetup.scenario].hudfunc(gdl);
			}
#else
			gdl = g_MpScenarios[g_MpSetup.scenario].hudfunc(gdl);
#endif
		}

		playercount = PLAYERCOUNT();

		if ((g_MpSetup.options & MPOPTION_TEAMSENABLED)
				&& (g_MpSetup.options & MPOPTION_DISPLAYTEAM)
				&& playercount >= 2) {
			chr = g_Vars.currentplayer->prop->chr;
			cplayernum = g_Vars.currentplayernum;

			gDPSetTextureFilter(gdl++, G_TF_POINT);
			gDPSetColorDither(gdl++, G_CD_DISABLE);
			gSPClearGeometryMode(gdl++, G_ZBUFFER);
			gDPPipeSync(gdl++);
			gDPSetTexturePersp(gdl++, G_TP_NONE);
			gDPSetCycleType(gdl++, G_CYC_FILL);
			gDPSetRenderMode(gdl++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
			gDPPipelineMode(gdl++, G_PM_1PRIMITIVE);

			colour = var80087ce4[radarGetTeamIndex(chr->team)];
			gDPSetFillColor(gdl++, colour);

			viewleft = viGetViewLeft();
			viewright = viewleft + viGetViewWidth();
			viewtop = viGetViewTop();
			viewheight = viGetViewHeight();

			if (playercount >= 3) {
				if (cplayernum <= 1) {
					// Player on top quarter - draw line at bottom of viewport
					gDPFillRectangle(gdl++, viewleft, viewheight + viewtop - 1, viewright - 1, viewheight + viewtop - 1);
				} else {
					// Player on bottom quarter - draw line at top of viewport
					gDPFillRectangle(gdl++, viewleft, viewtop, viewright - 1, viewtop);
				}
			}
#if VERSION >= VERSION_NTSC_1_0
			else if (g_Vars.fourmeg2player) {
				// Draw line at bottom of viewport
				gDPFillRectangle(gdl++, viewleft, viewheight + viewtop - 2, viewright - 1, viewheight + viewtop - 2);
			}
#endif
			else {
				// @bug: No consideration is made for vertical splits here,
				// however when using a vertical split neither line is visible.
				// It's suspected that a screen border is drawn over the top of it.
				if (cplayernum == 0) {
					// Player on top half - draw line at bottom of viewport
					gDPFillRectangle(gdl++, viewleft, viewheight + viewtop - 1, viewright - 1, viewheight + viewtop - 1);
				} else {
					// Player on bottom half - draw line at top of viewport
					gDPFillRectangle(gdl++, viewleft, viewtop, viewright - 1, viewtop);
				}
			}
		}
	}

	return gdl;
}

/**
 * Calculate the score and number of deaths for the given mpchr.
 *
 * If no callback is registered, the default calculation below will apply.
 */
void scenarioCalculatePlayerScore(struct mpchrconfig *mpchr, s32 chrnum, s32 *score, s32 *deaths)
{
	struct mpchrconfig *othermpchr;
	s32 i;

	if (g_MpScenarios[g_MpSetup.scenario].calcscorefunc) {
		g_MpScenarios[g_MpSetup.scenario].calcscorefunc(mpchr, chrnum, score, deaths);
	} else {
		*score = 0;

		for (i = 0; i < MAX_MPCHRS; i++) {
			if (i == chrnum) {
				*score -= mpchr->killcounts[i];
			} else if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				othermpchr = MPCHR(i);

				if (othermpchr->team == mpchr->team) {
					*score -= mpchr->killcounts[i];
				} else {
					*score += mpchr->killcounts[i];
				}
			} else {
				*score += mpchr->killcounts[i];
			}
		}

		*deaths = mpchr->numdeaths;
	}
}

/**
 * Draw anything extra to the radar, such as props or the king of the hill room.
 */
Gfx *scenarioRadarExtra(Gfx *gdl)
{
	if (g_Vars.normmplayerisrunning && g_MpScenarios[g_MpSetup.scenario].radarextrafunc) {
		return g_MpScenarios[g_MpSetup.scenario].radarextrafunc(gdl);
	}

	return gdl;
}

/**
 * Render a player or bot on the radar.
 *
 * Return true if handled or false if the generic radar code should render it.
 */
bool scenarioRadarChr(Gfx **gdl, struct prop *prop)
{
	if (g_Vars.normmplayerisrunning && g_MpScenarios[g_MpSetup.scenario].radarchrfunc) {
		return g_MpScenarios[g_MpSetup.scenario].radarchrfunc(gdl, prop);
	}

	return false;
}

/**
 * Set the highlight colour of the given prop.
 *
 * The prop may be a chr, weapon or object.
 */
bool scenarioHighlightProp(struct prop *prop, s32 *colour)
{
	if (g_MpScenarios[g_MpSetup.scenario].highlightpropfunc) {
		if (g_MpScenarios[g_MpSetup.scenario].highlightpropfunc(prop, colour)) {
			return true;
		}
	}

	if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_DOOR || prop->type == PROPTYPE_WEAPON) {
		struct defaultobj *obj = prop->obj;

		if ((g_MpSetup.scenario != MPSCENARIO_COMBAT || (g_MpSetup.options & MPOPTION_NOPICKUPHIGHLIGHT) == 0)
				&& (g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].base.displayoptions & MPDISPLAYOPTION_HIGHLIGHTPICKUPS)) {
			switch (obj->type) {
			case OBJTYPE_AMMOCRATE:
			case OBJTYPE_WEAPON:
			case OBJTYPE_LINKGUNS:
			case OBJTYPE_MULTIAMMOCRATE:
			case OBJTYPE_SHIELD:
				colour[0] = 0;
				colour[1] = 0xcd;
				colour[2] = 0xff;
				colour[3] = func0f006b08(20) * 255;
				return true;
			}
		}
	} else if (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER) {
		bool pulse = false;
		bool isunselectedbot = false;
		bool useblue = false;
		bool useteamcolour = false;

		if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
			struct chrdata *botchr = currentPlayerGetCommandingAibot();

			if (botchr) {
				if (botchr == prop->chr) {
					pulse = true;
					useteamcolour = true;
				} else {
					isunselectedbot = true;
				}
			}
		}

		if (!pulse && !isunselectedbot
				&& (g_MpSetup.scenario != MPSCENARIO_COMBAT || (g_MpSetup.options & MPOPTION_NOPLAYERHIGHLIGHT) == 0)) {
			if ((g_MpSetup.options & MPOPTION_TEAMSENABLED)
					&& (g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].base.displayoptions & MPDISPLAYOPTION_HIGHLIGHTTEAMS)) {
				useteamcolour = true;
			} else if (g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].base.displayoptions & MPDISPLAYOPTION_HIGHLIGHTPLAYERS) {
				useblue = true;
			}
		}

		if (useteamcolour) {
			u32 tmp = g_TeamColours[radarGetTeamIndex(prop->chr->team)];

			colour[0] = tmp >> 24 & 0xff;
			colour[1] = tmp >> 16 & 0xff;
			colour[2] = tmp >> 8 & 0xff;
			colour[3] = pulse ? (s32)(func0f006b08(20) * 128) : 75;
			return true;
		}

		if (useblue) {
			colour[0] = 0;
			colour[1] = 0xcd;
			colour[2] = 0xff;
			colour[3] = func0f006b08(20) * 205;
			return true;
		}
	}

	return false;
}

/**
 * Choose a spawn location for a chr.
 *
 * CTC uses this to ensure the chrs spawn near their base.
 */
f32 scenarioChooseSpawnLocation(f32 arg0, struct coord *pos, s16 *rooms, struct prop *prop)
{
	f32 result;

	if (g_Vars.normmplayerisrunning && g_MpScenarios[g_MpSetup.scenario].spawnfunc &&
			g_MpScenarios[g_MpSetup.scenario].spawnfunc(arg0, pos, rooms, prop, &result)) {
		return result;
	}

	return playerChooseGeneralSpawnLocation(arg0, pos, rooms, prop);
}

/**
 * Called when starting a match.
 *
 * The function clears anything in the g_ScenarioData struct that is
 * stage specific such as pad and room numbers, then re-reads the setup
 * file to reload that information.
 */
void scenarioReset(void)
{
	s32 i;
	s32 j;
	s32 *cmd = g_StageSetup.intro;

	switch (g_MpSetup.scenario) {
	case MPSCENARIO_KINGOFTHEHILL:
		g_ScenarioData.koh.hillcount = 0;
		break;
	case MPSCENARIO_CAPTURETHECASE:
		for (i = 0; i < ARRAYCOUNT(g_ScenarioData.ctc.spawnpadsperteam); i++) {
			g_ScenarioData.ctc.spawnpadsperteam[i].homepad = -1;
			g_ScenarioData.ctc.spawnpadsperteam[i].numspawnpads = 0;

			for (j = 0; j < ARRAYCOUNT(g_ScenarioData.ctc.spawnpadsperteam[i].spawnpads); j++) {
				g_ScenarioData.ctc.spawnpadsperteam[i].spawnpads[j] = -1;
			}
		}

		for (i = 0; i < ARRAYCOUNT(g_ScenarioData.ctc.playercountsperteam); i++) {
			g_ScenarioData.ctc.playercountsperteam[i] = 0;
			g_ScenarioData.ctc.teamindexes[i] = -1;
		}
		break;
	case MPSCENARIO_HACKERCENTRAL:
		htmReset();
		break;
	case MPSCENARIO_HOLDTHEBRIEFCASE:
		htbReset();
		break;
	case MPSCENARIO_POPACAP:
		break;
	}

	if (cmd) {
		while (cmd[0] != INTROCMD_END) {
			switch (cmd[0]) {
			case INTROCMD_SPAWN:
				cmd += 3;
				break;
			case INTROCMD_CASE:
			case INTROCMD_CASERESPAWN:
				if (g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE) {
					ctcAddPad(cmd);
				} else if (g_MpSetup.scenario == MPSCENARIO_HACKERCENTRAL) {
					htmAddPad(cmd[2]);
				} else if (g_MpSetup.scenario == MPSCENARIO_HOLDTHEBRIEFCASE) {
					htbAddPad(cmd[2]);
				}
				cmd += 3;
				break;
			case INTROCMD_HILL:
				if (g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL) {
					kohAddHill(cmd);
				}
				cmd += 2;
				break;
			case INTROCMD_WEAPON:
				cmd += 4;
				break;
			case INTROCMD_AMMO:
				cmd += 4;
				break;
			case INTROCMD_3:
				cmd += 8;
				break;
			case INTROCMD_4:
				cmd += 2;
				break;
			case INTROCMD_OUTFIT:
				cmd += 2;
				break;
			case INTROCMD_6:
				cmd += 10;
				break;
			case INTROCMD_WATCHTIME:
				cmd += 3;
				break;
			case INTROCMD_CREDITOFFSET:
				cmd += 2;
				break;
			default:
				cmd++;
				break;
			}
		}
	}
}

/**
 * Return the maximum number of teams permitted for this scenario.
 *
 * CTC sets this to 4, while the others use the default limit of 8.
 */
s32 scenarioGetMaxTeams(void)
{
	if (g_MpScenarios[g_MpSetup.scenario].maxteamsfunc) {
		return g_MpScenarios[g_MpSetup.scenario].maxteamsfunc();
	}

	return MAX_TEAMS;
}

/**
 * This callback is unused.
 */
bool scenarioIsRoomHighlighted(s16 room)
{
	if (g_MpScenarios[g_MpSetup.scenario].isroomhighlightedfunc) {
		return g_MpScenarios[g_MpSetup.scenario].isroomhighlightedfunc(room);
	}

	return false;
}

/**
 * Override the colour for the given room.
 *
 * Used in CTC for the team bases and in KOH for the hill.
 */
void scenarioHighlightRoom(s16 room, s32 *arg1, s32 *arg2, s32 *arg3)
{
	if (g_MpScenarios[g_MpSetup.scenario].highlightroomfunc) {
		g_MpScenarios[g_MpSetup.scenario].highlightroomfunc(room, arg1, arg2, arg3);
	}
}

struct menuitem g_MpScenarioMenuItems[] = {
	 { MENUITEMTYPE_LIST,        0, 0x00020040, 0x00000078, 0x0000004d, scenarioScenarioMenuHandler },
	 { MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_MpScenarioMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_243, // "Scenario"
	g_MpScenarioMenuItems,
	NULL,
	MENUDIALOGFLAG_CLOSEONSELECT | MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

struct menuitem g_MpQuickTeamScenarioMenuItems[] = {
	 { MENUITEMTYPE_LIST,        1, 0x00020040, 0x00000078, 0x0000004d, scenarioScenarioMenuHandler },
	 { MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialogdef g_MpQuickTeamScenarioMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_243, // "Scenario"
	g_MpQuickTeamScenarioMenuItems,
	NULL,
	MENUDIALOGFLAG_CLOSEONSELECT | MENUDIALOGFLAG_MPLOCKABLE,
	NULL,
};

/**
 * Create a general object.
 *
 * This is a helper function used by HTM to create the terminal.
 */
struct prop *scenarioCreateObj(s32 modelnum, s16 padnum, f32 arg2, u32 flags, u32 flags2, u32 flags3)
{
	struct defaultobj template = {
		256,                    // extrascale
		0,                      // hidden2
		OBJTYPE_BASIC,          // type
		MODEL_A51_CRATE1,       // modelnum
		-1,                     // pad
		0,                      // flags
		0,                      // flags2
		0,                      // flags3
		NULL,                   // prop
		NULL,                   // model
		1, 0, 0,                // realrot
		0, 1, 0,
		0, 0, 1,
		0,                      // hidden
		NULL,                   // geo
		NULL,                   // projectile
		0,                      // damage
		1000,                   // maxdamage
		0xff, 0xff, 0xff, 0x00, // shadecol
		0xff, 0xff, 0xff, 0x00, // nextcol
		0x0fff,                 // floorcol
		0,                      // tiles
	};

	struct defaultobj *obj = mempAlloc(ALIGN16(sizeof(struct defaultobj)), MEMPOOL_STAGE);
	*obj = template;

	obj->modelnum = modelnum;
	obj->pad = padnum;
	obj->flags = flags;
	obj->flags2 = flags2;
	obj->flags3 = flags3;
	obj->extrascale = arg2 * 256;
	obj->hidden2 &= ~OBJHFLAG_REAPABLE;

	setupGenericObject(obj, 123);
	propActivate(obj->prop);
	propEnable(obj->prop);

	return obj->prop;
}

/**
 * Create a HUD message for the given player.
 *
 * This is a helper function used by PAC.
 */
void scenarioCreateHudmsg(s32 playernum, char *message)
{
	if (playernum >= 0 && playernum < PLAYERCOUNT()) {
		s32 prevplayernum = g_Vars.currentplayernum;

		setCurrentPlayerNum(playernum);
#if VERSION >= VERSION_JPN_FINAL
		hudmsgCreateWithFlags(message, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE | HUDMSGFLAG_20);
#else
		hudmsgCreateWithFlags(message, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
#endif
		setCurrentPlayerNum(prevplayernum);
	}
}

/**
 * CHeck if two player numbers are on the same team.
 *
 * This is a helper function used by PAC.
 */
bool scenarioChrsAreSameTeam(s32 playernum1, s32 playernum2)
{
	struct mpchrconfig *achr;
	struct mpchrconfig *bchr;

	if ((g_MpSetup.options & MPOPTION_TEAMSENABLED) && playernum1 >= 0 && playernum2 >= 0) {
		s32 a = func0f18d074(playernum1);
		s32 b = func0f18d074(playernum2);

		if (a >= 0 && b >= 0) {
			achr = MPCHR(a);
			bchr = MPCHR(b);

			return (achr->team == bchr->team) ? true : false;
		}
	}

	return false;
}

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel scenarioPickUpBriefcase
/*  f186f78:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f186f7c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f186f80:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f186f84:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f186f88:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f186f8c:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f186f90:	afa40130 */ 	sw	$a0,0x130($sp)
/*  f186f94:	afa50134 */ 	sw	$a1,0x134($sp)
/*  f186f98:	3c03800b */ 	lui	$v1,0x800b
/*  f186f9c:	8ca20004 */ 	lw	$v0,0x4($a1)
/*  f186fa0:	9063d5c8 */ 	lbu	$v1,-0x2a38($v1)
/*  f186fa4:	24010001 */ 	li	$at,0x1
/*  f186fa8:	afa2012c */ 	sw	$v0,0x12c($sp)
/*  f186fac:	146100a9 */ 	bne	$v1,$at,.JF0f187254
/*  f186fb0:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f186fb4:	8c98001c */ 	lw	$t8,0x1c($a0)
/*  f186fb8:	3c01800b */ 	lui	$at,0x800b
/*  f186fbc:	ac38cb44 */ 	sw	$t8,-0x34bc($at)
/*  f186fc0:	8c9902d4 */ 	lw	$t9,0x2d4($a0)
/*  f186fc4:	13200016 */ 	beqz	$t9,.JF0f187020
/*  f186fc8:	00000000 */ 	nop
/*  f186fcc:	0fc63641 */ 	jal	0xf18d904
/*  f186fd0:	00000000 */ 	nop
/*  f186fd4:	00024080 */ 	sll	$t0,$v0,0x2
/*  f186fd8:	3c09800b */ 	lui	$t1,0x800b
/*  f186fdc:	01284821 */ 	addu	$t1,$t1,$t0
/*  f186fe0:	8d29cf30 */ 	lw	$t1,-0x30d0($t1)
/*  f186fe4:	8faa0128 */ 	lw	$t2,0x128($sp)
/*  f186fe8:	8fa40134 */ 	lw	$a0,0x134($sp)
/*  f186fec:	afa90058 */ 	sw	$t1,0x58($sp)
/*  f186ff0:	0fc222fe */ 	jal	0xf088bf8
/*  f186ff4:	9145005c */ 	lbu	$a1,0x5c($t2)
/*  f186ff8:	8fa40130 */ 	lw	$a0,0x130($sp)
/*  f186ffc:	24050057 */ 	li	$a1,0x57
/*  f187000:	8c8302d4 */ 	lw	$v1,0x2d4($a0)
/*  f187004:	906c009c */ 	lbu	$t4,0x9c($v1)
/*  f187008:	358d0080 */ 	ori	$t5,$t4,0x80
/*  f18700c:	0fc661fb */ 	jal	0xf1987ec
/*  f187010:	a06d009c */ 	sb	$t5,0x9c($v1)
/*  f187014:	3c13800a */ 	lui	$s3,0x800a
/*  f187018:	10000022 */ 	b	.JF0f1870a4
/*  f18701c:	2673a630 */ 	addiu	$s3,$s3,-22992
.JF0f187020:
/*  f187020:	3c13800a */ 	lui	$s3,0x800a
/*  f187024:	2673a630 */ 	addiu	$s3,$s3,-22992
/*  f187028:	8e6e028c */ 	lw	$t6,0x28c($s3)
/*  f18702c:	3c0c800b */ 	lui	$t4,0x800b
/*  f187030:	3c08800b */ 	lui	$t0,0x800b
/*  f187034:	000ec1c0 */ 	sll	$t8,$t6,0x7
/*  f187038:	0278c821 */ 	addu	$t9,$s3,$t8
/*  f18703c:	8f2200e4 */ 	lw	$v0,0xe4($t9)
/*  f187040:	2508d1e8 */ 	addiu	$t0,$t0,-11800
/*  f187044:	258ccf68 */ 	addiu	$t4,$t4,-12440
/*  f187048:	28410004 */ 	slti	$at,$v0,0x4
/*  f18704c:	10200007 */ 	beqz	$at,.JF0f18706c
/*  f187050:	00025080 */ 	sll	$t2,$v0,0x2
/*  f187054:	00027880 */ 	sll	$t7,$v0,0x2
/*  f187058:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f18705c:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f187060:	01e84821 */ 	addu	$t1,$t7,$t0
/*  f187064:	10000008 */ 	b	.JF0f187088
/*  f187068:	afa90058 */ 	sw	$t1,0x58($sp)
.JF0f18706c:
/*  f18706c:	01425021 */ 	addu	$t2,$t2,$v0
/*  f187070:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f187074:	01425023 */ 	subu	$t2,$t2,$v0
/*  f187078:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f18707c:	254bfed0 */ 	addiu	$t3,$t2,-304
/*  f187080:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f187084:	afad0058 */ 	sw	$t5,0x58($sp)
.JF0f187088:
/*  f187088:	0fc44863 */ 	jal	0xf11218c
/*  f18708c:	24040057 */ 	li	$a0,0x57
/*  f187090:	24040057 */ 	li	$a0,0x57
/*  f187094:	0fc22553 */ 	jal	0xf08954c
/*  f187098:	00002825 */ 	move	$a1,$zero
/*  f18709c:	0fc2233f */ 	jal	0xf088cfc
/*  f1870a0:	24040057 */ 	li	$a0,0x57
.JF0f1870a4:
/*  f1870a4:	0fc5baa5 */ 	jal	0xf16ea94
/*  f1870a8:	24045401 */ 	li	$a0,0x5401
/*  f1870ac:	00408825 */ 	move	$s1,$v0
/*  f1870b0:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f1870b4:	0fc60110 */ 	jal	0xf180440
/*  f1870b8:	00002825 */ 	move	$a1,$zero
/*  f1870bc:	00408025 */ 	move	$s0,$v0
/*  f1870c0:	0fc28c4e */ 	jal	0xf0a3138
/*  f1870c4:	24040057 */ 	li	$a0,0x57
/*  f1870c8:	27a400dc */ 	addiu	$a0,$sp,0xdc
/*  f1870cc:	02202825 */ 	move	$a1,$s1
/*  f1870d0:	02003025 */ 	move	$a2,$s0
/*  f1870d4:	0c004d95 */ 	jal	0x13654
/*  f1870d8:	00403825 */ 	move	$a3,$v0
/*  f1870dc:	8e67006c */ 	lw	$a3,0x6c($s3)
/*  f1870e0:	8e6e028c */ 	lw	$t6,0x28c($s3)
/*  f1870e4:	00009025 */ 	move	$s2,$zero
/*  f1870e8:	10e00003 */ 	beqz	$a3,.JF0f1870f8
/*  f1870ec:	afae0120 */ 	sw	$t6,0x120($sp)
/*  f1870f0:	10000002 */ 	b	.JF0f1870fc
/*  f1870f4:	24030001 */ 	li	$v1,0x1
.JF0f1870f8:
/*  f1870f8:	00001825 */ 	move	$v1,$zero
.JF0f1870fc:
/*  f1870fc:	8e660068 */ 	lw	$a2,0x68($s3)
/*  f187100:	00008825 */ 	move	$s1,$zero
/*  f187104:	00008025 */ 	move	$s0,$zero
/*  f187108:	10c00003 */ 	beqz	$a2,.JF0f187118
/*  f18710c:	00001025 */ 	move	$v0,$zero
/*  f187110:	10000001 */ 	b	.JF0f187118
/*  f187114:	24110001 */ 	li	$s1,0x1
.JF0f187118:
/*  f187118:	8e650064 */ 	lw	$a1,0x64($s3)
/*  f18711c:	10a00003 */ 	beqz	$a1,.JF0f18712c
/*  f187120:	00000000 */ 	nop
/*  f187124:	10000001 */ 	b	.JF0f18712c
/*  f187128:	24100001 */ 	li	$s0,0x1
.JF0f18712c:
/*  f18712c:	8e640070 */ 	lw	$a0,0x70($s3)
/*  f187130:	10800003 */ 	beqz	$a0,.JF0f187140
/*  f187134:	00000000 */ 	nop
/*  f187138:	10000001 */ 	b	.JF0f187140
/*  f18713c:	24020001 */ 	li	$v0,0x1
.JF0f187140:
/*  f187140:	0050c021 */ 	addu	$t8,$v0,$s0
/*  f187144:	0311c821 */ 	addu	$t9,$t8,$s1
/*  f187148:	03237821 */ 	addu	$t7,$t9,$v1
/*  f18714c:	19e0002d */ 	blez	$t7,.JF0f187204
/*  f187150:	00000000 */ 	nop
/*  f187154:	8fa80130 */ 	lw	$t0,0x130($sp)
.JF0f187158:
/*  f187158:	8faa0120 */ 	lw	$t2,0x120($sp)
/*  f18715c:	8d0902d4 */ 	lw	$t1,0x2d4($t0)
/*  f187160:	15200003 */ 	bnez	$t1,.JF0f187170
/*  f187164:	00000000 */ 	nop
/*  f187168:	124a000f */ 	beq	$s2,$t2,.JF0f1871a8
/*  f18716c:	00000000 */ 	nop
.JF0f187170:
/*  f187170:	0fc4a34d */ 	jal	0xf128d34
/*  f187174:	02402025 */ 	move	$a0,$s2
/*  f187178:	27a400dc */ 	addiu	$a0,$sp,0xdc
/*  f18717c:	24050009 */ 	li	$a1,0x9
/*  f187180:	0fc37c3e */ 	jal	0xf0df0f8
/*  f187184:	24060021 */ 	li	$a2,0x21
/*  f187188:	3c07800a */ 	lui	$a3,0x800a
/*  f18718c:	3c06800a */ 	lui	$a2,0x800a
/*  f187190:	3c05800a */ 	lui	$a1,0x800a
/*  f187194:	3c04800a */ 	lui	$a0,0x800a
/*  f187198:	8c84a6a0 */ 	lw	$a0,-0x5960($a0)
/*  f18719c:	8ca5a694 */ 	lw	$a1,-0x596c($a1)
/*  f1871a0:	8cc6a698 */ 	lw	$a2,-0x5968($a2)
/*  f1871a4:	8ce7a69c */ 	lw	$a3,-0x5964($a3)
.JF0f1871a8:
/*  f1871a8:	10e00003 */ 	beqz	$a3,.JF0f1871b8
/*  f1871ac:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1871b0:	10000002 */ 	b	.JF0f1871bc
/*  f1871b4:	24030001 */ 	li	$v1,0x1
.JF0f1871b8:
/*  f1871b8:	00001825 */ 	move	$v1,$zero
.JF0f1871bc:
/*  f1871bc:	10c00003 */ 	beqz	$a2,.JF0f1871cc
/*  f1871c0:	00008825 */ 	move	$s1,$zero
/*  f1871c4:	10000001 */ 	b	.JF0f1871cc
/*  f1871c8:	24110001 */ 	li	$s1,0x1
.JF0f1871cc:
/*  f1871cc:	10a00003 */ 	beqz	$a1,.JF0f1871dc
/*  f1871d0:	00008025 */ 	move	$s0,$zero
/*  f1871d4:	10000001 */ 	b	.JF0f1871dc
/*  f1871d8:	24100001 */ 	li	$s0,0x1
.JF0f1871dc:
/*  f1871dc:	10800003 */ 	beqz	$a0,.JF0f1871ec
/*  f1871e0:	00001025 */ 	move	$v0,$zero
/*  f1871e4:	10000001 */ 	b	.JF0f1871ec
/*  f1871e8:	24020001 */ 	li	$v0,0x1
.JF0f1871ec:
/*  f1871ec:	00505821 */ 	addu	$t3,$v0,$s0
/*  f1871f0:	01716021 */ 	addu	$t4,$t3,$s1
/*  f1871f4:	01836821 */ 	addu	$t5,$t4,$v1
/*  f1871f8:	024d082a */ 	slt	$at,$s2,$t5
/*  f1871fc:	5420ffd6 */ 	bnezl	$at,.JF0f187158
/*  f187200:	8fa80130 */ 	lw	$t0,0x130($sp)
.JF0f187204:
/*  f187204:	0fc4a34d */ 	jal	0xf128d34
/*  f187208:	8fa40120 */ 	lw	$a0,0x120($sp)
/*  f18720c:	8fae0130 */ 	lw	$t6,0x130($sp)
/*  f187210:	8fa3012c */ 	lw	$v1,0x12c($sp)
/*  f187214:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f187218:	8dd802d4 */ 	lw	$t8,0x2d4($t6)
/*  f18721c:	53000007 */ 	beqzl	$t8,.JF0f18723c
/*  f187220:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f187224:	8c790040 */ 	lw	$t9,0x40($v1)
/*  f187228:	00001025 */ 	move	$v0,$zero
/*  f18722c:	372f0004 */ 	ori	$t7,$t9,0x4
/*  f187230:	100001d6 */ 	b	.JF0f18798c
/*  f187234:	ac6f0040 */ 	sw	$t7,0x40($v1)
/*  f187238:	90860002 */ 	lbu	$a2,0x2($a0)
.JF0f18723c:
/*  f18723c:	00002825 */ 	move	$a1,$zero
/*  f187240:	30c90004 */ 	andi	$t1,$a2,0x4
/*  f187244:	0fc1af91 */ 	jal	0xf06be44
/*  f187248:	01203025 */ 	move	$a2,$t1
/*  f18724c:	100001cf */ 	b	.JF0f18798c
/*  f187250:	24020001 */ 	li	$v0,0x1
.JF0f187254:
/*  f187254:	24010005 */ 	li	$at,0x5
/*  f187258:	146101c6 */ 	bne	$v1,$at,.JF0f187974
/*  f18725c:	8fad0130 */ 	lw	$t5,0x130($sp)
/*  f187260:	8faa0130 */ 	lw	$t2,0x130($sp)
/*  f187264:	3c13800a */ 	lui	$s3,0x800a
/*  f187268:	2673a630 */ 	addiu	$s3,$s3,-22992
/*  f18726c:	8d4302d4 */ 	lw	$v1,0x2d4($t2)
/*  f187270:	5060000e */ 	beqzl	$v1,.JF0f1872ac
/*  f187274:	8e6e028c */ 	lw	$t6,0x28c($s3)
/*  f187278:	0fc63641 */ 	jal	0xf18d904
/*  f18727c:	01402025 */ 	move	$a0,$t2
/*  f187280:	00025880 */ 	sll	$t3,$v0,0x2
/*  f187284:	3c0c800b */ 	lui	$t4,0x800b
/*  f187288:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f18728c:	8d8ccf30 */ 	lw	$t4,-0x30d0($t4)
/*  f187290:	8fad0130 */ 	lw	$t5,0x130($sp)
/*  f187294:	3c13800a */ 	lui	$s3,0x800a
/*  f187298:	afac0058 */ 	sw	$t4,0x58($sp)
/*  f18729c:	2673a630 */ 	addiu	$s3,$s3,-22992
/*  f1872a0:	10000019 */ 	b	.JF0f187308
/*  f1872a4:	8da302d4 */ 	lw	$v1,0x2d4($t5)
/*  f1872a8:	8e6e028c */ 	lw	$t6,0x28c($s3)
.JF0f1872ac:
/*  f1872ac:	3c0c800b */ 	lui	$t4,0x800b
/*  f1872b0:	3c08800b */ 	lui	$t0,0x800b
/*  f1872b4:	000ec1c0 */ 	sll	$t8,$t6,0x7
/*  f1872b8:	0278c821 */ 	addu	$t9,$s3,$t8
/*  f1872bc:	8f2200e4 */ 	lw	$v0,0xe4($t9)
/*  f1872c0:	2508d1e8 */ 	addiu	$t0,$t0,-11800
/*  f1872c4:	258ccf68 */ 	addiu	$t4,$t4,-12440
/*  f1872c8:	28410004 */ 	slti	$at,$v0,0x4
/*  f1872cc:	10200007 */ 	beqz	$at,.JF0f1872ec
/*  f1872d0:	00025080 */ 	sll	$t2,$v0,0x2
/*  f1872d4:	00027880 */ 	sll	$t7,$v0,0x2
/*  f1872d8:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f1872dc:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f1872e0:	01e84821 */ 	addu	$t1,$t7,$t0
/*  f1872e4:	10000008 */ 	b	.JF0f187308
/*  f1872e8:	afa90058 */ 	sw	$t1,0x58($sp)
.JF0f1872ec:
/*  f1872ec:	01425021 */ 	addu	$t2,$t2,$v0
/*  f1872f0:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f1872f4:	01425023 */ 	subu	$t2,$t2,$v0
/*  f1872f8:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f1872fc:	254bfed0 */ 	addiu	$t3,$t2,-304
/*  f187300:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f187304:	afad0058 */ 	sw	$t5,0x58($sp)
.JF0f187308:
/*  f187308:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f18730c:	8fb90128 */ 	lw	$t9,0x128($sp)
/*  f187310:	91d80011 */ 	lbu	$t8,0x11($t6)
/*  f187314:	872f0062 */ 	lh	$t7,0x62($t9)
/*  f187318:	170f00cc */ 	bne	$t8,$t7,.JF0f18764c
/*  f18731c:	00000000 */ 	nop
/*  f187320:	10600005 */ 	beqz	$v1,.JF0f187338
/*  f187324:	00000000 */ 	nop
/*  f187328:	8c68009c */ 	lw	$t0,0x9c($v1)
/*  f18732c:	00085040 */ 	sll	$t2,$t0,0x1
/*  f187330:	05420008 */ 	bltzl	$t2,.JF0f187354
/*  f187334:	8fab0058 */ 	lw	$t3,0x58($sp)
.JF0f187338:
/*  f187338:	546000bd */ 	bnezl	$v1,.JF0f187630
/*  f18733c:	8fa90130 */ 	lw	$t1,0x130($sp)
/*  f187340:	0fc44b12 */ 	jal	0xf112c48
/*  f187344:	00000000 */ 	nop
/*  f187348:	504000b9 */ 	beqzl	$v0,.JF0f187630
/*  f18734c:	8fa90130 */ 	lw	$t1,0x130($sp)
/*  f187350:	8fab0058 */ 	lw	$t3,0x58($sp)
.JF0f187354:
/*  f187354:	3c02800b */ 	lui	$v0,0x800b
/*  f187358:	2442cb40 */ 	addiu	$v0,$v0,-13504
/*  f18735c:	856c003e */ 	lh	$t4,0x3e($t3)
/*  f187360:	00009025 */ 	move	$s2,$zero
/*  f187364:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f187368:	a56d003e */ 	sh	$t5,0x3e($t3)
/*  f18736c:	8fae0130 */ 	lw	$t6,0x130($sp)
/*  f187370:	8fb80130 */ 	lw	$t8,0x130($sp)
/*  f187374:	8dc3001c */ 	lw	$v1,0x1c($t6)
.JF0f187378:
/*  f187378:	8c590058 */ 	lw	$t9,0x58($v0)
/*  f18737c:	50790006 */ 	beql	$v1,$t9,.JF0f187398
/*  f187380:	8f0f02d4 */ 	lw	$t7,0x2d4($t8)
/*  f187384:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f187388:	2a410004 */ 	slti	$at,$s2,0x4
/*  f18738c:	1420fffa */ 	bnez	$at,.JF0f187378
/*  f187390:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f187394:	8f0f02d4 */ 	lw	$t7,0x2d4($t8)
.JF0f187398:
/*  f187398:	11e00009 */ 	beqz	$t7,.JF0f1873c0
/*  f18739c:	03002025 */ 	move	$a0,$t8
/*  f1873a0:	0fc668b9 */ 	jal	0xf19a2e4
/*  f1873a4:	24050057 */ 	li	$a1,0x57
/*  f1873a8:	8fa80130 */ 	lw	$t0,0x130($sp)
/*  f1873ac:	8d0302d4 */ 	lw	$v1,0x2d4($t0)
/*  f1873b0:	9069009c */ 	lbu	$t1,0x9c($v1)
/*  f1873b4:	312affbf */ 	andi	$t2,$t1,0xffbf
/*  f1873b8:	10000014 */ 	b	.JF0f18740c
/*  f1873bc:	a06a009c */ 	sb	$t2,0x9c($v1)
.JF0f1873c0:
/*  f1873c0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1873c4:	44812000 */ 	mtc1	$at,$f4
/*  f1873c8:	3c048009 */ 	lui	$a0,0x8009
/*  f1873cc:	240cffff */ 	li	$t4,-1
/*  f1873d0:	240dffff */ 	li	$t5,-1
/*  f1873d4:	240bffff */ 	li	$t3,-1
/*  f1873d8:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f1873dc:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f1873e0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f1873e4:	8c845870 */ 	lw	$a0,0x5870($a0)
/*  f1873e8:	240505b8 */ 	li	$a1,0x5b8
/*  f1873ec:	00003025 */ 	move	$a2,$zero
/*  f1873f0:	2407ffff */ 	li	$a3,-1
/*  f1873f4:	0c004230 */ 	jal	0x108c0
/*  f1873f8:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f1873fc:	0fc247f5 */ 	jal	0xf091fd4
/*  f187400:	24040057 */ 	li	$a0,0x57
/*  f187404:	0fc448aa */ 	jal	0xf1122a8
/*  f187408:	24040057 */ 	li	$a0,0x57
.JF0f18740c:
/*  f18740c:	0fc5baa5 */ 	jal	0xf16ea94
/*  f187410:	24045405 */ 	li	$a0,0x5405
/*  f187414:	00127080 */ 	sll	$t6,$s2,0x2
/*  f187418:	01d27023 */ 	subu	$t6,$t6,$s2
/*  f18741c:	3c19800b */ 	lui	$t9,0x800b
/*  f187420:	2739d5e0 */ 	addiu	$t9,$t9,-10784
/*  f187424:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f187428:	01d92021 */ 	addu	$a0,$t6,$t9
/*  f18742c:	afa40044 */ 	sw	$a0,0x44($sp)
/*  f187430:	00408025 */ 	move	$s0,$v0
/*  f187434:	0fc60110 */ 	jal	0xf180440
/*  f187438:	00002825 */ 	move	$a1,$zero
/*  f18743c:	27a400dc */ 	addiu	$a0,$sp,0xdc
/*  f187440:	02002825 */ 	move	$a1,$s0
/*  f187444:	0c004d95 */ 	jal	0x13654
/*  f187448:	00403025 */ 	move	$a2,$v0
/*  f18744c:	0fc5baa5 */ 	jal	0xf16ea94
/*  f187450:	24045406 */ 	li	$a0,0x5406
/*  f187454:	00408025 */ 	move	$s0,$v0
/*  f187458:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f18745c:	0fc60110 */ 	jal	0xf180440
/*  f187460:	00002825 */ 	move	$a1,$zero
/*  f187464:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f187468:	02002825 */ 	move	$a1,$s0
/*  f18746c:	0c004d95 */ 	jal	0x13654
/*  f187470:	00403025 */ 	move	$a2,$v0
/*  f187474:	0fc5baa5 */ 	jal	0xf16ea94
/*  f187478:	24045407 */ 	li	$a0,0x5407
/*  f18747c:	00408825 */ 	move	$s1,$v0
/*  f187480:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f187484:	0fc60110 */ 	jal	0xf180440
/*  f187488:	00002825 */ 	move	$a1,$zero
/*  f18748c:	00408025 */ 	move	$s0,$v0
/*  f187490:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f187494:	0fc60110 */ 	jal	0xf180440
/*  f187498:	24050001 */ 	li	$a1,0x1
/*  f18749c:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f1874a0:	02202825 */ 	move	$a1,$s1
/*  f1874a4:	02003025 */ 	move	$a2,$s0
/*  f1874a8:	0c004d95 */ 	jal	0x13654
/*  f1874ac:	00403825 */ 	move	$a3,$v0
/*  f1874b0:	8e78006c */ 	lw	$t8,0x6c($s3)
/*  f1874b4:	8e6f028c */ 	lw	$t7,0x28c($s3)
/*  f1874b8:	afb2011c */ 	sw	$s2,0x11c($sp)
/*  f1874bc:	00009025 */ 	move	$s2,$zero
/*  f1874c0:	13000003 */ 	beqz	$t8,.JF0f1874d0
/*  f1874c4:	afaf0120 */ 	sw	$t7,0x120($sp)
/*  f1874c8:	10000002 */ 	b	.JF0f1874d4
/*  f1874cc:	24030001 */ 	li	$v1,0x1
.JF0f1874d0:
/*  f1874d0:	00001825 */ 	move	$v1,$zero
.JF0f1874d4:
/*  f1874d4:	8e680068 */ 	lw	$t0,0x68($s3)
/*  f1874d8:	00008825 */ 	move	$s1,$zero
/*  f1874dc:	00008025 */ 	move	$s0,$zero
/*  f1874e0:	11000003 */ 	beqz	$t0,.JF0f1874f0
/*  f1874e4:	00001025 */ 	move	$v0,$zero
/*  f1874e8:	10000001 */ 	b	.JF0f1874f0
/*  f1874ec:	24110001 */ 	li	$s1,0x1
.JF0f1874f0:
/*  f1874f0:	8e690064 */ 	lw	$t1,0x64($s3)
/*  f1874f4:	11200003 */ 	beqz	$t1,.JF0f187504
/*  f1874f8:	00000000 */ 	nop
/*  f1874fc:	10000001 */ 	b	.JF0f187504
/*  f187500:	24100001 */ 	li	$s0,0x1
.JF0f187504:
/*  f187504:	8e6a0070 */ 	lw	$t2,0x70($s3)
/*  f187508:	11400003 */ 	beqz	$t2,.JF0f187518
/*  f18750c:	00000000 */ 	nop
/*  f187510:	10000001 */ 	b	.JF0f187518
/*  f187514:	24020001 */ 	li	$v0,0x1
.JF0f187518:
/*  f187518:	00506021 */ 	addu	$t4,$v0,$s0
/*  f18751c:	01916821 */ 	addu	$t5,$t4,$s1
/*  f187520:	01a35821 */ 	addu	$t3,$t5,$v1
/*  f187524:	1960003f */ 	blez	$t3,.JF0f187624
/*  f187528:	00000000 */ 	nop
.JF0f18752c:
/*  f18752c:	0fc4a34d */ 	jal	0xf128d34
/*  f187530:	02402025 */ 	move	$a0,$s2
/*  f187534:	8fae0130 */ 	lw	$t6,0x130($sp)
/*  f187538:	00124080 */ 	sll	$t0,$s2,0x2
/*  f18753c:	3c09800b */ 	lui	$t1,0x800b
/*  f187540:	8dd902d4 */ 	lw	$t9,0x2d4($t6)
/*  f187544:	8faf0120 */ 	lw	$t7,0x120($sp)
/*  f187548:	01284821 */ 	addu	$t1,$t1,$t0
/*  f18754c:	17200008 */ 	bnez	$t9,.JF0f187570
/*  f187550:	00000000 */ 	nop
/*  f187554:	164f0006 */ 	bne	$s2,$t7,.JF0f187570
/*  f187558:	27a400dc */ 	addiu	$a0,$sp,0xdc
/*  f18755c:	24050009 */ 	li	$a1,0x9
/*  f187560:	0fc37c3e */ 	jal	0xf0df0f8
/*  f187564:	24060021 */ 	li	$a2,0x21
/*  f187568:	10000011 */ 	b	.JF0f1875b0
/*  f18756c:	8e6c006c */ 	lw	$t4,0x6c($s3)
.JF0f187570:
/*  f187570:	8d29cf30 */ 	lw	$t1,-0x30d0($t1)
/*  f187574:	8fb8011c */ 	lw	$t8,0x11c($sp)
/*  f187578:	24060021 */ 	li	$a2,0x21
/*  f18757c:	912a0011 */ 	lbu	$t2,0x11($t1)
/*  f187580:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f187584:	24050009 */ 	li	$a1,0x9
/*  f187588:	170a0006 */ 	bne	$t8,$t2,.JF0f1875a4
/*  f18758c:	00000000 */ 	nop
/*  f187590:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f187594:	0fc37c3e */ 	jal	0xf0df0f8
/*  f187598:	24050009 */ 	li	$a1,0x9
/*  f18759c:	10000004 */ 	b	.JF0f1875b0
/*  f1875a0:	8e6c006c */ 	lw	$t4,0x6c($s3)
.JF0f1875a4:
/*  f1875a4:	0fc37c3e */ 	jal	0xf0df0f8
/*  f1875a8:	24060021 */ 	li	$a2,0x21
/*  f1875ac:	8e6c006c */ 	lw	$t4,0x6c($s3)
.JF0f1875b0:
/*  f1875b0:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1875b4:	00001825 */ 	move	$v1,$zero
/*  f1875b8:	11800003 */ 	beqz	$t4,.JF0f1875c8
/*  f1875bc:	00008825 */ 	move	$s1,$zero
/*  f1875c0:	10000001 */ 	b	.JF0f1875c8
/*  f1875c4:	24030001 */ 	li	$v1,0x1
.JF0f1875c8:
/*  f1875c8:	8e6d0068 */ 	lw	$t5,0x68($s3)
/*  f1875cc:	00008025 */ 	move	$s0,$zero
/*  f1875d0:	00001025 */ 	move	$v0,$zero
/*  f1875d4:	11a00003 */ 	beqz	$t5,.JF0f1875e4
/*  f1875d8:	00000000 */ 	nop
/*  f1875dc:	10000001 */ 	b	.JF0f1875e4
/*  f1875e0:	24110001 */ 	li	$s1,0x1
.JF0f1875e4:
/*  f1875e4:	8e6b0064 */ 	lw	$t3,0x64($s3)
/*  f1875e8:	11600003 */ 	beqz	$t3,.JF0f1875f8
/*  f1875ec:	00000000 */ 	nop
/*  f1875f0:	10000001 */ 	b	.JF0f1875f8
/*  f1875f4:	24100001 */ 	li	$s0,0x1
.JF0f1875f8:
/*  f1875f8:	8e6e0070 */ 	lw	$t6,0x70($s3)
/*  f1875fc:	11c00003 */ 	beqz	$t6,.JF0f18760c
/*  f187600:	00000000 */ 	nop
/*  f187604:	10000001 */ 	b	.JF0f18760c
/*  f187608:	24020001 */ 	li	$v0,0x1
.JF0f18760c:
/*  f18760c:	0050c821 */ 	addu	$t9,$v0,$s0
/*  f187610:	03317821 */ 	addu	$t7,$t9,$s1
/*  f187614:	01e34021 */ 	addu	$t0,$t7,$v1
/*  f187618:	0248082a */ 	slt	$at,$s2,$t0
/*  f18761c:	1420ffc3 */ 	bnez	$at,.JF0f18752c
/*  f187620:	00000000 */ 	nop
.JF0f187624:
/*  f187624:	0fc4a34d */ 	jal	0xf128d34
/*  f187628:	8fa40120 */ 	lw	$a0,0x120($sp)
/*  f18762c:	8fa90130 */ 	lw	$t1,0x130($sp)
.JF0f187630:
/*  f187630:	8d3802d4 */ 	lw	$t8,0x2d4($t1)
/*  f187634:	13000003 */ 	beqz	$t8,.JF0f187644
/*  f187638:	00000000 */ 	nop
/*  f18763c:	100000d3 */ 	b	.JF0f18798c
/*  f187640:	00001025 */ 	move	$v0,$zero
.JF0f187644:
/*  f187644:	100000d1 */ 	b	.JF0f18798c
/*  f187648:	00001025 */ 	move	$v0,$zero
.JF0f18764c:
/*  f18764c:	10600005 */ 	beqz	$v1,.JF0f187664
/*  f187650:	00000000 */ 	nop
/*  f187654:	8c6a009c */ 	lw	$t2,0x9c($v1)
/*  f187658:	000a6840 */ 	sll	$t5,$t2,0x1
/*  f18765c:	05a10008 */ 	bgez	$t5,.JF0f187680
/*  f187660:	00000000 */ 	nop
.JF0f187664:
/*  f187664:	546000bc */ 	bnezl	$v1,.JF0f187958
/*  f187668:	8faa0130 */ 	lw	$t2,0x130($sp)
/*  f18766c:	0fc44b12 */ 	jal	0xf112c48
/*  f187670:	00000000 */ 	nop
/*  f187674:	144000b7 */ 	bnez	$v0,.JF0f187954
/*  f187678:	8fab0130 */ 	lw	$t3,0x130($sp)
/*  f18767c:	8d6302d4 */ 	lw	$v1,0x2d4($t3)
.JF0f187680:
/*  f187680:	50600009 */ 	beqzl	$v1,.JF0f1876a8
/*  f187684:	8faa0128 */ 	lw	$t2,0x128($sp)
/*  f187688:	9079009c */ 	lbu	$t9,0x9c($v1)
/*  f18768c:	372f0040 */ 	ori	$t7,$t9,0x40
/*  f187690:	a06f009c */ 	sb	$t7,0x9c($v1)
/*  f187694:	8fa80128 */ 	lw	$t0,0x128($sp)
/*  f187698:	8fa40134 */ 	lw	$a0,0x134($sp)
/*  f18769c:	0fc222fe */ 	jal	0xf088bf8
/*  f1876a0:	9105005c */ 	lbu	$a1,0x5c($t0)
/*  f1876a4:	8faa0128 */ 	lw	$t2,0x128($sp)
.JF0f1876a8:
/*  f1876a8:	8fa90130 */ 	lw	$t1,0x130($sp)
/*  f1876ac:	3c01800b */ 	lui	$at,0x800b
/*  f1876b0:	854c0062 */ 	lh	$t4,0x62($t2)
/*  f1876b4:	8d38001c */ 	lw	$t8,0x1c($t1)
/*  f1876b8:	24045402 */ 	li	$a0,0x5402
/*  f1876bc:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f1876c0:	002d0821 */ 	addu	$at,$at,$t5
/*  f1876c4:	0fc5baa5 */ 	jal	0xf16ea94
/*  f1876c8:	ac38cb98 */ 	sw	$t8,-0x3468($at)
/*  f1876cc:	00408825 */ 	move	$s1,$v0
/*  f1876d0:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f1876d4:	0fc60110 */ 	jal	0xf180440
/*  f1876d8:	00002825 */ 	move	$a1,$zero
/*  f1876dc:	8fab0128 */ 	lw	$t3,0x128($sp)
/*  f1876e0:	3c12800b */ 	lui	$s2,0x800b
/*  f1876e4:	2652d5e0 */ 	addiu	$s2,$s2,-10784
/*  f1876e8:	856e0062 */ 	lh	$t6,0x62($t3)
/*  f1876ec:	00408025 */ 	move	$s0,$v0
/*  f1876f0:	24050001 */ 	li	$a1,0x1
/*  f1876f4:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f1876f8:	032ec823 */ 	subu	$t9,$t9,$t6
/*  f1876fc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f187700:	0fc60110 */ 	jal	0xf180440
/*  f187704:	02592021 */ 	addu	$a0,$s2,$t9
/*  f187708:	27a400dc */ 	addiu	$a0,$sp,0xdc
/*  f18770c:	02202825 */ 	move	$a1,$s1
/*  f187710:	02003025 */ 	move	$a2,$s0
/*  f187714:	0c004d95 */ 	jal	0x13654
/*  f187718:	00403825 */ 	move	$a3,$v0
/*  f18771c:	0fc5baa5 */ 	jal	0xf16ea94
/*  f187720:	24045403 */ 	li	$a0,0x5403
/*  f187724:	00408025 */ 	move	$s0,$v0
/*  f187728:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f18772c:	0fc60110 */ 	jal	0xf180440
/*  f187730:	00002825 */ 	move	$a1,$zero
/*  f187734:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f187738:	02002825 */ 	move	$a1,$s0
/*  f18773c:	0c004d95 */ 	jal	0x13654
/*  f187740:	00403025 */ 	move	$a2,$v0
/*  f187744:	0fc5baa5 */ 	jal	0xf16ea94
/*  f187748:	24045404 */ 	li	$a0,0x5404
/*  f18774c:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f187750:	00408025 */ 	move	$s0,$v0
/*  f187754:	00002825 */ 	move	$a1,$zero
/*  f187758:	85e80062 */ 	lh	$t0,0x62($t7)
/*  f18775c:	00084880 */ 	sll	$t1,$t0,0x2
/*  f187760:	01284823 */ 	subu	$t1,$t1,$t0
/*  f187764:	00094880 */ 	sll	$t1,$t1,0x2
/*  f187768:	0fc60110 */ 	jal	0xf180440
/*  f18776c:	02492021 */ 	addu	$a0,$s2,$t1
/*  f187770:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f187774:	02002825 */ 	move	$a1,$s0
/*  f187778:	0c004d95 */ 	jal	0x13654
/*  f18777c:	00403025 */ 	move	$a2,$v0
/*  f187780:	8e6c006c */ 	lw	$t4,0x6c($s3)
/*  f187784:	8e6a028c */ 	lw	$t2,0x28c($s3)
/*  f187788:	00009025 */ 	move	$s2,$zero
/*  f18778c:	11800003 */ 	beqz	$t4,.JF0f18779c
/*  f187790:	afaa0120 */ 	sw	$t2,0x120($sp)
/*  f187794:	10000002 */ 	b	.JF0f1877a0
/*  f187798:	24030001 */ 	li	$v1,0x1
.JF0f18779c:
/*  f18779c:	00001825 */ 	move	$v1,$zero
.JF0f1877a0:
/*  f1877a0:	8e780068 */ 	lw	$t8,0x68($s3)
/*  f1877a4:	00008825 */ 	move	$s1,$zero
/*  f1877a8:	00008025 */ 	move	$s0,$zero
/*  f1877ac:	13000003 */ 	beqz	$t8,.JF0f1877bc
/*  f1877b0:	00001025 */ 	move	$v0,$zero
/*  f1877b4:	10000001 */ 	b	.JF0f1877bc
/*  f1877b8:	24110001 */ 	li	$s1,0x1
.JF0f1877bc:
/*  f1877bc:	8e6d0064 */ 	lw	$t5,0x64($s3)
/*  f1877c0:	11a00003 */ 	beqz	$t5,.JF0f1877d0
/*  f1877c4:	00000000 */ 	nop
/*  f1877c8:	10000001 */ 	b	.JF0f1877d0
/*  f1877cc:	24100001 */ 	li	$s0,0x1
.JF0f1877d0:
/*  f1877d0:	8e6b0070 */ 	lw	$t3,0x70($s3)
/*  f1877d4:	11600003 */ 	beqz	$t3,.JF0f1877e4
/*  f1877d8:	00000000 */ 	nop
/*  f1877dc:	10000001 */ 	b	.JF0f1877e4
/*  f1877e0:	24020001 */ 	li	$v0,0x1
.JF0f1877e4:
/*  f1877e4:	00507021 */ 	addu	$t6,$v0,$s0
/*  f1877e8:	01d1c821 */ 	addu	$t9,$t6,$s1
/*  f1877ec:	03237821 */ 	addu	$t7,$t9,$v1
/*  f1877f0:	19e0003f */ 	blez	$t7,.JF0f1878f0
/*  f1877f4:	00000000 */ 	nop
.JF0f1877f8:
/*  f1877f8:	0fc4a34d */ 	jal	0xf128d34
/*  f1877fc:	02402025 */ 	move	$a0,$s2
/*  f187800:	8fa80130 */ 	lw	$t0,0x130($sp)
/*  f187804:	00126880 */ 	sll	$t5,$s2,0x2
/*  f187808:	3c0b800b */ 	lui	$t3,0x800b
/*  f18780c:	8d0902d4 */ 	lw	$t1,0x2d4($t0)
/*  f187810:	8faa0120 */ 	lw	$t2,0x120($sp)
/*  f187814:	016d5821 */ 	addu	$t3,$t3,$t5
/*  f187818:	15200008 */ 	bnez	$t1,.JF0f18783c
/*  f18781c:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f187820:	164a0006 */ 	bne	$s2,$t2,.JF0f18783c
/*  f187824:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f187828:	24050009 */ 	li	$a1,0x9
/*  f18782c:	0fc37c3e */ 	jal	0xf0df0f8
/*  f187830:	24060021 */ 	li	$a2,0x21
/*  f187834:	10000011 */ 	b	.JF0f18787c
/*  f187838:	8e79006c */ 	lw	$t9,0x6c($s3)
.JF0f18783c:
/*  f18783c:	8d6bcf30 */ 	lw	$t3,-0x30d0($t3)
/*  f187840:	85980062 */ 	lh	$t8,0x62($t4)
/*  f187844:	24060021 */ 	li	$a2,0x21
/*  f187848:	916e0011 */ 	lbu	$t6,0x11($t3)
/*  f18784c:	27a400dc */ 	addiu	$a0,$sp,0xdc
/*  f187850:	24050009 */ 	li	$a1,0x9
/*  f187854:	170e0006 */ 	bne	$t8,$t6,.JF0f187870
/*  f187858:	00000000 */ 	nop
/*  f18785c:	27a4009c */ 	addiu	$a0,$sp,0x9c
/*  f187860:	0fc37c3e */ 	jal	0xf0df0f8
/*  f187864:	24050009 */ 	li	$a1,0x9
/*  f187868:	10000004 */ 	b	.JF0f18787c
/*  f18786c:	8e79006c */ 	lw	$t9,0x6c($s3)
.JF0f187870:
/*  f187870:	0fc37c3e */ 	jal	0xf0df0f8
/*  f187874:	24060021 */ 	li	$a2,0x21
/*  f187878:	8e79006c */ 	lw	$t9,0x6c($s3)
.JF0f18787c:
/*  f18787c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f187880:	00001825 */ 	move	$v1,$zero
/*  f187884:	13200003 */ 	beqz	$t9,.JF0f187894
/*  f187888:	00008825 */ 	move	$s1,$zero
/*  f18788c:	10000001 */ 	b	.JF0f187894
/*  f187890:	24030001 */ 	li	$v1,0x1
.JF0f187894:
/*  f187894:	8e6f0068 */ 	lw	$t7,0x68($s3)
/*  f187898:	00008025 */ 	move	$s0,$zero
/*  f18789c:	00001025 */ 	move	$v0,$zero
/*  f1878a0:	11e00003 */ 	beqz	$t7,.JF0f1878b0
/*  f1878a4:	00000000 */ 	nop
/*  f1878a8:	10000001 */ 	b	.JF0f1878b0
/*  f1878ac:	24110001 */ 	li	$s1,0x1
.JF0f1878b0:
/*  f1878b0:	8e680064 */ 	lw	$t0,0x64($s3)
/*  f1878b4:	11000003 */ 	beqz	$t0,.JF0f1878c4
/*  f1878b8:	00000000 */ 	nop
/*  f1878bc:	10000001 */ 	b	.JF0f1878c4
/*  f1878c0:	24100001 */ 	li	$s0,0x1
.JF0f1878c4:
/*  f1878c4:	8e690070 */ 	lw	$t1,0x70($s3)
/*  f1878c8:	11200003 */ 	beqz	$t1,.JF0f1878d8
/*  f1878cc:	00000000 */ 	nop
/*  f1878d0:	10000001 */ 	b	.JF0f1878d8
/*  f1878d4:	24020001 */ 	li	$v0,0x1
.JF0f1878d8:
/*  f1878d8:	00505021 */ 	addu	$t2,$v0,$s0
/*  f1878dc:	01516021 */ 	addu	$t4,$t2,$s1
/*  f1878e0:	01836821 */ 	addu	$t5,$t4,$v1
/*  f1878e4:	024d082a */ 	slt	$at,$s2,$t5
/*  f1878e8:	1420ffc3 */ 	bnez	$at,.JF0f1877f8
/*  f1878ec:	00000000 */ 	nop
.JF0f1878f0:
/*  f1878f0:	0fc4a34d */ 	jal	0xf128d34
/*  f1878f4:	8fa40120 */ 	lw	$a0,0x120($sp)
/*  f1878f8:	8fab0130 */ 	lw	$t3,0x130($sp)
/*  f1878fc:	8d7802d4 */ 	lw	$t8,0x2d4($t3)
/*  f187900:	01602025 */ 	move	$a0,$t3
/*  f187904:	13000009 */ 	beqz	$t8,.JF0f18792c
/*  f187908:	00000000 */ 	nop
/*  f18790c:	0fc661fb */ 	jal	0xf1987ec
/*  f187910:	24050057 */ 	li	$a1,0x57
/*  f187914:	8fae012c */ 	lw	$t6,0x12c($sp)
/*  f187918:	00001025 */ 	move	$v0,$zero
/*  f18791c:	8dd90040 */ 	lw	$t9,0x40($t6)
/*  f187920:	372f0004 */ 	ori	$t7,$t9,0x4
/*  f187924:	10000019 */ 	b	.JF0f18798c
/*  f187928:	adcf0040 */ 	sw	$t7,0x40($t6)
.JF0f18792c:
/*  f18792c:	0fc4493d */ 	jal	0xf1124f4
/*  f187930:	8fa40134 */ 	lw	$a0,0x134($sp)
/*  f187934:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f187938:	00002825 */ 	move	$a1,$zero
/*  f18793c:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f187940:	30c90004 */ 	andi	$t1,$a2,0x4
/*  f187944:	0fc1af91 */ 	jal	0xf06be44
/*  f187948:	01203025 */ 	move	$a2,$t1
/*  f18794c:	1000000f */ 	b	.JF0f18798c
/*  f187950:	24020001 */ 	li	$v0,0x1
.JF0f187954:
/*  f187954:	8faa0130 */ 	lw	$t2,0x130($sp)
.JF0f187958:
/*  f187958:	8d4c02d4 */ 	lw	$t4,0x2d4($t2)
/*  f18795c:	11800003 */ 	beqz	$t4,.JF0f18796c
/*  f187960:	00000000 */ 	nop
/*  f187964:	10000009 */ 	b	.JF0f18798c
/*  f187968:	00001025 */ 	move	$v0,$zero
.JF0f18796c:
/*  f18796c:	10000007 */ 	b	.JF0f18798c
/*  f187970:	00001025 */ 	move	$v0,$zero
.JF0f187974:
/*  f187974:	8db802d4 */ 	lw	$t8,0x2d4($t5)
/*  f187978:	00001025 */ 	move	$v0,$zero
/*  f18797c:	13000003 */ 	beqz	$t8,.JF0f18798c
/*  f187980:	00000000 */ 	nop
/*  f187984:	10000001 */ 	b	.JF0f18798c
/*  f187988:	00001025 */ 	move	$v0,$zero
.JF0f18798c:
/*  f18798c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f187990:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f187994:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f187998:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f18799c:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f1879a0:	03e00008 */ 	jr	$ra
/*  f1879a4:	27bd0130 */ 	addiu	$sp,$sp,0x130
);
#else
/**
 * Handle a player or bot picking up a briefcase, regardless of which scenario
 * it is.
 *
 * The return value is a TICKOP constant.
 */
s32 scenarioPickUpBriefcase(struct chrdata *chr, struct prop *prop)
{
	struct defaultobj *obj = prop->obj;
	struct weaponobj *weapon = prop->weapon;
	s32 i;
	s32 prevplayernum;
	s32 caseteam;
	char text1[64];
	char text2[64];
	char text3[64];
	struct mpchrconfig *mpchr;

	if (g_MpSetup.scenario == MPSCENARIO_HOLDTHEBRIEFCASE) {
		// Player or bot has picked up the briefcase
		g_ScenarioData.htb.token = chr->prop;

		if (chr->aibot) {
			mpchr = g_MpAllChrConfigPtrs[mpPlayerGetIndex(chr)];
			propPlayPickupSound(prop, weapon->weaponnum);
			chr->aibot->hasbriefcase = true;
			botinvGiveSingleWeapon(chr, WEAPON_BRIEFCASE2);
		} else {
			mpchr = MPCHR(g_Vars.playerstats[g_Vars.currentplayernum].mpindex);

			invGiveSingleWeapon(WEAPON_BRIEFCASE2);
			currentPlayerQueuePickupWeaponHudmsg(WEAPON_BRIEFCASE2, false);
			weaponPlayPickupSound(WEAPON_BRIEFCASE2);
		}

#if VERSION >= VERSION_PAL_BETA
		// "%shas the Briefcase"
		sprintf(text1, langGet(L_MPWEAPONS_000_2), mpchr->name, bgunGetShortName(WEAPON_BRIEFCASE2));
#else
		// "%shas the\n%s"
		sprintf(text1, langGet(L_MPWEAPONS_000), mpchr->name, bgunGetShortName(WEAPON_BRIEFCASE2));
#endif

		prevplayernum = g_Vars.currentplayernum;

		for (i = 0; i < PLAYERCOUNT(); i++) {
			if (chr->aibot || i != prevplayernum) {
				setCurrentPlayerNum(i);
#if VERSION >= VERSION_JPN_FINAL
				hudmsgCreateWithFlags(text1, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE | HUDMSGFLAG_20);
#else
				hudmsgCreateWithFlags(text1, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
#endif
			}
		}

		setCurrentPlayerNum(prevplayernum);

		if (chr->aibot) {
			obj->hidden |= OBJHFLAG_REAPABLE;
			return TICKOP_NONE;
		}

#if VERSION >= VERSION_NTSC_1_0
		objFree(obj, false, obj->hidden2 & OBJH2FLAG_CANREGEN);
		return TICKOP_FREE;
#else
		return TICKOP_GIVETOPLAYER;
#endif
	} else if (g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE) {
		if (chr->aibot) {
			mpchr = g_MpAllChrConfigPtrs[mpPlayerGetIndex(chr)];
		} else {
			mpchr = MPCHR(g_Vars.playerstats[g_Vars.currentplayernum].mpindex);
		}

		if (weapon->team == mpchr->team) {
			if ((chr->aibot && chr->aibot->hascase) || (!chr->aibot && invHasBriefcase())) {
				// The chr already has a case and they are "picking up"
				// their home case. ie. A point has just been scored
				mpchr->numpoints++;

				for (i = 0; i < 4; i++) {
					if (g_ScenarioData.ctc.tokens[i] == chr->prop) {
						break;
					}
				}

				if (chr->aibot) {
					botinvDropOne(chr, WEAPON_BRIEFCASE2);
					chr->aibot->hascase = false;
				} else {
					sndStart(var80095200, SFX_MP_SCOREPOINT, NULL, -1, -1, -1, -1, -1);
					weaponCreateForPlayerDrop(WEAPON_BRIEFCASE2);
					invRemoveItemByNum(WEAPON_BRIEFCASE2);
				}

#if VERSION >= VERSION_PAL_BETA
				// "You captured the %s Briefcase"
				sprintf(text1, langGet(L_MPWEAPONS_004), g_BossFile.teamnames[i]);

				// "%scaptured our Briefcase"
				sprintf(text2, langGet(L_MPWEAPONS_005), mpchr->name);

				// "%scaptured the %s Briefcase"
				sprintf(text3, langGet(L_MPWEAPONS_006), mpchr->name, g_BossFile.teamnames[i]);
#else
				// "You captured the %s%s"
				sprintf(text1, langGet(L_MPWEAPONS_004), g_BossFile.teamnames[i], bgunGetShortName(WEAPON_BRIEFCASE2));

				// "%scaptured our %s"
				sprintf(text2, langGet(L_MPWEAPONS_005), mpchr->name, bgunGetShortName(WEAPON_BRIEFCASE2));

				// "%scaptured the %s%s"
				sprintf(text3, langGet(L_MPWEAPONS_006), mpchr->name, g_BossFile.teamnames[i], bgunGetShortName(WEAPON_BRIEFCASE2));
#endif

				prevplayernum = g_Vars.currentplayernum;

				caseteam = i;

				for (i = 0; i < PLAYERCOUNT(); i++) {
					setCurrentPlayerNum(i);

					if (!chr->aibot && i == prevplayernum) {
						hudmsgCreateWithFlags(text1, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
					} else if (caseteam == g_MpAllChrConfigPtrs[i]->team) {
						hudmsgCreateWithFlags(text2, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
					} else {
						hudmsgCreateWithFlags(text3, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
					}
				}

				setCurrentPlayerNum(prevplayernum);
			}

			if (chr->aibot) {
				return TICKOP_NONE;
			}

			return TICKOP_NONE;
		} else {
			// Picking up another team's case
			if ((chr->aibot && !chr->aibot->hascase) || (!chr->aibot && !invHasBriefcase())) {
				// And we have no case currently, so go ahead and pick it up
				if (chr->aibot) {
					chr->aibot->hascase = true;
					propPlayPickupSound(prop, weapon->weaponnum);
				}

				g_ScenarioData.ctc.tokens[weapon->team] = chr->prop;

#if VERSION >= VERSION_PAL_BETA
				// "%shas the %s Briefcase"
				sprintf(text1, langGet(L_MPWEAPONS_000_3), mpchr->name, g_BossFile.teamnames[weapon->team]);

				// "%shas our\nBriefcase"
				sprintf(text2, langGet(L_MPWEAPONS_002), mpchr->name);

				// "Got the %s Briefcase"
				sprintf(text3, langGet(L_MPWEAPONS_003), g_BossFile.teamnames[weapon->team]);
#else
				// "%shas the %s%s"
				sprintf(text1, langGet(L_MPWEAPONS_001), mpchr->name, g_BossFile.teamnames[weapon->team], bgunGetShortName(WEAPON_BRIEFCASE2));

				// "%shas our %s"
				sprintf(text2, langGet(L_MPWEAPONS_002), mpchr->name, bgunGetShortName(WEAPON_BRIEFCASE2));

				// "Got the %s%s"
				sprintf(text3, langGet(L_MPWEAPONS_003), g_BossFile.teamnames[weapon->team], bgunGetShortName(WEAPON_BRIEFCASE2));
#endif

				prevplayernum = g_Vars.currentplayernum;

				for (i = 0; i < PLAYERCOUNT(); i++) {
					setCurrentPlayerNum(i);

					if (!chr->aibot && i == prevplayernum) {
						hudmsgCreateWithFlags(text3, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
					} else if (weapon->team == g_MpAllChrConfigPtrs[i]->team) {
						hudmsgCreateWithFlags(text2, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
					} else {
						hudmsgCreateWithFlags(text1, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
					}
				}

				setCurrentPlayerNum(prevplayernum);

				if (chr->aibot) {
					botinvGiveSingleWeapon(chr, WEAPON_BRIEFCASE2);
					obj->hidden |= OBJHFLAG_REAPABLE;
					return TICKOP_NONE;
				} else {
					invGiveWeaponsByProp(prop);
#if VERSION >= VERSION_NTSC_1_0
					objFree(obj, false, obj->hidden2 & OBJH2FLAG_CANREGEN);
					return TICKOP_FREE;
#else
					return TICKOP_GIVETOPLAYER;
#endif
				}
			} else {
				// Already holding another team's case, so ignore the pickup
				if (chr->aibot) {
					return TICKOP_NONE;
				}

				return TICKOP_NONE;
			}
		}
	} else {
		if (chr->aibot) {
			return TICKOP_NONE;
		}

		return TICKOP_NONE;
	}

	return TICKOP_NONE;
}
#endif

/**
 * Handle a token (briefcase) being dropped due to the holder being killed.
 *
 * For CTC, the token is warped back to its home base.
 */
void scenarioHandleDroppedToken(struct chrdata *chr, struct prop *prop)
{
	s32 i;
	struct weaponobj *weapon = prop->weapon;
	struct defaultobj *obj;
	struct pad pad;
	Mtxf mtx;
	s16 rooms[2];

	if (g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE) {
		for (i = 0; i < 4; i++) {
			if (chr->prop == g_ScenarioData.ctc.tokens[i]) {
				objEndFlight(&weapon->base);

				g_ScenarioData.ctc.tokens[i] = prop;
				weapon->team = i;
				obj = prop->obj;

				padUnpack(g_ScenarioData.ctc.spawnpadsperteam[g_ScenarioData.ctc.teamindexes[i]].homepad,
						PADFIELD_POS | PADFIELD_LOOK | PADFIELD_UP | PADFIELD_ROOM, &pad);
				mtx00016d58(&mtx, 0, 0, 0, -pad.look.x, -pad.look.y, -pad.look.z, pad.up.x, pad.up.y, pad.up.z);

				if (obj->model) {
					mtx00015f04(obj->model->scale, &mtx);
				}

				rooms[0] = pad.room;
				rooms[1] = -1;

				func0f06a730(obj, &pad.pos, &mtx, rooms, &pad.pos);
			}
		}
	}
}

/**
 * Handle a player or bot picking up a data uplink, regardless of which scenario
 * it is.
 *
 * The return value is a TICKOP constant.
 */
s32 scenarioPickUpUplink(struct chrdata *chr, struct prop *prop)
{
	s32 i;
	char message[64];
	struct mpchrconfig *mpchr;
	u32 playernum;

	if (g_MpSetup.scenario == MPSCENARIO_HACKERCENTRAL) {
#if VERSION >= VERSION_NTSC_1_0
		struct defaultobj *obj = prop->obj;
#endif

		g_ScenarioData.htm.uplink = chr->prop;

		if (chr->aibot) {
			mpchr = g_MpAllChrConfigPtrs[mpPlayerGetIndex(chr)];
		} else {
			mpchr = MPCHR(g_Vars.playerstats[g_Vars.currentplayernum].mpindex);
		}

#if VERSION >= VERSION_JPN_FINAL
		// "%shas the\nData Uplink%s"
		sprintf(message, langGet(L_MPWEAPONS_000), func0f180440jf(mpchr->name, 0));
#elif VERSION >= VERSION_PAL_BETA
		// "%shas the\nData Uplink%s"
		sprintf(message, langGet(L_MPWEAPONS_000), mpchr->name);
#else
		// "%shas the\n%s"
		sprintf(message, langGet(L_MPWEAPONS_000), mpchr->name, bgunGetShortName(WEAPON_DATAUPLINK));
#endif
		playernum = g_Vars.currentplayernum;

		for (i = 0; i < PLAYERCOUNT(); i++) {
			if (chr->aibot || i != playernum) {
				setCurrentPlayerNum(i);

#if VERSION >= VERSION_JPN_FINAL
				hudmsgCreateWithFlags(message, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE | HUDMSGFLAG_20);
#else
				hudmsgCreateWithFlags(message, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
#endif
			}
		}

		setCurrentPlayerNum(playernum);

		if (chr->aibot) {
			propPlayPickupSound(prop, WEAPON_DATAUPLINK);
			botinvGiveSingleWeapon(chr, WEAPON_DATAUPLINK);
			chr->aibot->hasuplink = true;

#if VERSION >= VERSION_NTSC_1_0
			obj->hidden |= OBJHFLAG_REAPABLE;
#else
			prop->obj->hidden |= OBJHFLAG_REAPABLE;
#endif

			return TICKOP_NONE;
		} else {
			invGiveSingleWeapon(WEAPON_DATAUPLINK);
			currentPlayerQueuePickupWeaponHudmsg(WEAPON_DATAUPLINK, false);
			weaponPlayPickupSound(WEAPON_DATAUPLINK);

#if VERSION >= VERSION_NTSC_1_0
			objFree(obj, false, obj->hidden2 & OBJH2FLAG_CANREGEN);
			return TICKOP_FREE;
#else
			return TICKOP_GIVETOPLAYER;
#endif

		}
	} else if (chr->aibot) {
		return TICKOP_NONE;
	}

	return TICKOP_NONE;
}

/**
 * Handle a terminal being activated with the data uplink.
 */
void scenarioHandleActivatedProp(struct chrdata *chr, struct prop *prop)
{
	if (g_MpSetup.scenario == MPSCENARIO_HACKERCENTRAL) {
		struct defaultobj *obj = prop->obj;

		if (obj->flags3 & OBJFLAG3_HTMTERMINAL) {
			u32 mpindex = mpPlayerGetIndex(chr);

			if ((obj->hidden & OBJHFLAG_ACTIVATED_BY_BOND) == 0) {
				obj->hidden &= 0x0fffffff;
				obj->hidden |= (mpindex << 28) & 0xf0000000;
				obj->hidden |= OBJHFLAG_ACTIVATED_BY_BOND;
			}
		}
	}
}
