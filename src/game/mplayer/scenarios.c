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
#include "game/game_0b69d0.h"
#include "game/savebuffer.h"
#include "game/hudmsg.h"
#include "game/game_0f09f0.h"
#include "game/inventory/inventory.h"
#include "game/game_127910.h"
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

struct scenariodata g_ScenarioData;
u32 var800ac254;

struct weaponobj g_HtbTokenObj;

struct weaponobj g_CtcTokenObj0;
struct weaponobj g_CtcTokenObj1;
struct weaponobj g_CtcTokenObj2;
struct weaponobj g_CtcTokenObj3;

struct weaponobj g_HtmUplinkObj;

struct mpscenario g_MpScenarios[6];

const char var7f1b8440[] = "CaptureTheBriefcaseAddBankPad -> Adding New Pad %d  - Pad Id = %d-> Saving Pad\n";

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

void scenarioHtbInit(void)
{
	g_ScenarioData.htb.token = NULL;
}

void mpHtbAddPad(s16 padnum)
{
	struct scenariodata_htb *data = &g_ScenarioData.htb;

#if VERSION >= VERSION_NTSC_1_0
	if (data->nextindex < ARRAYCOUNT(data->padnums))
#endif
	{
		data->padnums[data->nextindex] = padnum;
		data->nextindex++;
	}
}

s32 scenarioHtbCallback08(void)
{
	return 1;
}

void scenarioHtmRemoveAmmoCrateAtPad(s16 padnum)
{
	struct prop *prop = g_Vars.activeprops;

	while (prop) {
		if (prop->type == PROPTYPE_OBJ) {
			struct defaultobj *obj = prop->obj;

			if (obj->pad == padnum
					&& (obj->type == OBJTYPE_AMMOCRATE || obj->type == OBJTYPE_MULTIAMMOCRATE)
					&& obj->modelnum == MODEL_MULTI_AMMO_CRATE) {
				obj->hidden |= OBJHFLAG_REAPABLE;
				obj->hidden2 &= ~OBJH2FLAG_CANREGEN;
				return;
			}
		}

		prop = prop->next;
	}
}

void func0f180078(void)
{
	s32 i;

	g_ScenarioData.htb.nextindex = 0;

	for (i = 0; i < ARRAYCOUNT(g_ScenarioData.htb.padnums); i++) {
		g_ScenarioData.htb.padnums[i] = -1;
	}
}

struct menuitem g_MpCombatOptionsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_222, MPOPTION_ONEHITKILLS,       menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU_223, 0x00000000,                 menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_224, MPOPTION_FASTMOVEMENT,      menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_225, MPOPTION_DISPLAYTEAM,       menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_226, MPOPTION_NORADAR,           menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_227, MPOPTION_NOAUTOAIM,         menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,    0x00000000,                 NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_228, MPOPTION_NOPLAYERHIGHLIGHT, menuhandlerMpCheckboxOption }, // "No Player Highlight"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_229, MPOPTION_NOPICKUPHIGHLIGHT, menuhandlerMpCheckboxOption }, // "No Pickup Highlight"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,    0x00000000,                 NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU_239, 0x00000000,                 NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,    0x00000000,                 NULL                        },
};

struct menudialog g_MpCombatOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_215, // "Combat Options"
	g_MpCombatOptionsMenuItems,
	mpOptionsMenuDialog,
	0x00000010,
	NULL,
};

struct menuitem g_MpBriefcaseOptionsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_222,  MPOPTION_ONEHITKILLS,            menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU_223,  0x00000000,                      menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_224,  MPOPTION_FASTMOVEMENT,           menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_225,  MPOPTION_DISPLAYTEAM,            menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_226,  MPOPTION_NORADAR,                menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_227,  MPOPTION_NOAUTOAIM,              menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS_493, MPOPTION_KILLSSCORE,             menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                      NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_237,  MPOPTION_HTB_HIGHLIGHTBRIEFCASE, menuhandlerMpCheckboxOption }, // "Highlight Briefcase"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_238,  MPOPTION_HTB_SHOWONRADAR,        menuhandlerMpCheckboxOption }, // "Show on Radar"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                      NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU_239,  0x00000000,                      NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,                      NULL                        },
};

struct menudialog g_MpBriefcaseOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_216, // "Briefcase Options"
	g_MpBriefcaseOptionsMenuItems,
	mpOptionsMenuDialog,
	0x00000010,
	NULL,
};

struct defaultobj *var800869ec = NULL;

void scenarioHtbCreateToken(void)
{
	struct weaponobj template = {
		256,                    // extrascale
		0,                      // hidden2
		OBJTYPE_WEAPON,         // type
		MODEL_CHRBRIEFCASE,     // modelnum
		0,                      // pad
		OBJFLAG_00000001 | OBJFLAG_INVINCIBLE | OBJFLAG_00400000,
		OBJFLAG2_IMMUNETOGUNFIRE | OBJFLAG2_00200000,
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
		WEAPON_BRIEFCASE2,      // weaponnum
		0,                      // unk5d
		0,                      // unk5e
		FUNC_PRIMARY,           // gunfunc
		0,                      // fadeouttimer60
		-1,                     // dualweaponnum
		-1,                     // timer240
		NULL,                   // dualweapon
	};

	struct prop *prop = g_Vars.activeprops;
	struct defaultobj *obj;
	s32 count = 0;
	struct defaultobj *candidates[20];

	// Build a list of candidate objects to replace. Consider only ammocrates.
	// NTSC beta doesn't check the prop type, so it could potentially replace a
	// player, bot, explosion or smoke.
	while (prop && count < 20) {
#if VERSION >= VERSION_NTSC_1_0
		if (prop->type == PROPTYPE_OBJ)
#endif
		{
			obj = prop->obj;

			if (obj->type == OBJTYPE_MULTIAMMOCRATE) {
				candidates[count] = obj;
				count++;
			}
		}

		prop = prop->next;
	}

	// Choose the candidate and remove it
	if (count > 0) {
		count = random() % count;
		var800869ec = candidates[count];
		g_ScenarioData.htb.tokenpad = var800869ec->pad;
		var800869ec->hidden |= OBJHFLAG_REAPABLE;
		var800869ec->hidden2 |= OBJH2FLAG_CANREGEN;
	} else if (g_ScenarioData.htb.nextindex > 0) {
		g_ScenarioData.htb.tokenpad = g_ScenarioData.htb.padnums[random() % g_ScenarioData.htb.nextindex];
	} else {
		g_ScenarioData.htb.tokenpad = 0;
	}

	// Set up the token
	g_HtbTokenObj = template;
	g_HtbTokenObj.base.pad = g_ScenarioData.htb.tokenpad;

	weaponAssignToHome(&g_HtbTokenObj, 999);

	g_HtbTokenObj.base.hidden2 &= ~OBJH2FLAG_CANREGEN;

	g_ScenarioData.htb.token = g_HtbTokenObj.base.prop;

	if (g_ScenarioData.htb.token) {
		g_ScenarioData.htb.token->forcetick = true;
	}
}

void scenarioHtbReset(void)
{
	var800869ec = NULL;
	scenarioHtbCreateToken();
}

void scenarioHtbTick(void)
{
	s32 i;
	u32 prevplayernum = g_Vars.currentplayernum;
	struct prop *prop;

	if (var800869ec && var800869ec->prop) {
		if (g_ScenarioData.htb.token == NULL || g_ScenarioData.htb.token->type != PROPTYPE_WEAPON) {
			var800869ec = NULL;
		} else {
			var800869ec->prop->timetoregen = PALDOWN(1200);
		}
	}

	g_ScenarioData.htb.token = NULL;

	// Check if briefcase is on the ground
	prop = g_Vars.activeprops;

	while (prop) {
		if (prop->type == PROPTYPE_WEAPON) {
			struct weaponobj *weapon = prop->weapon;

			if (weapon->weaponnum == WEAPON_BRIEFCASE2) {
				g_ScenarioData.htb.token = prop;
			}
		}

		prop = prop->next;
	}

	// Check if a player is holding it
	if (g_ScenarioData.htb.token == NULL) {
		for (i = 0; i < PLAYERCOUNT(); i++) {
			setCurrentPlayerNum(i);

			if (invHasBriefcase()) {
				g_ScenarioData.htb.token = g_Vars.currentplayer->prop;
				break;
			}
		}
	}

	setCurrentPlayerNum(prevplayernum);

	// Check if a simulant is holding it
	if (g_ScenarioData.htb.token == NULL) {
		for (i = PLAYERCOUNT(); i < g_MpNumChrs; i++) {
#if VERSION >= VERSION_NTSC_1_0
			if (g_MpAllChrPtrs[i]->prop && g_MpAllChrPtrs[i]->aibot->hasbriefcase)
#else
			if (g_MpAllChrPtrs[i]->aibot->hasbriefcase)
#endif
			{
				g_ScenarioData.htb.token = g_MpAllChrPtrs[i]->prop;
				break;
			}
		}
	}

	if (g_ScenarioData.htb.token == NULL) {
		scenarioHtbCreateToken();
	}

	if (g_ScenarioData.htb.token == NULL) {
		g_ScenarioData.htb.pos.x = 0;
		g_ScenarioData.htb.pos.y = 0;
		g_ScenarioData.htb.pos.z = 0;
	} else {
		struct coord *pos = &g_ScenarioData.htb.pos;
		pos->x = g_ScenarioData.htb.token->pos.x;
		pos->y = g_ScenarioData.htb.token->pos.y;
		pos->z = g_ScenarioData.htb.token->pos.z;
	}
}

void scenarioHtbCallback14(struct chrdata *chr)
{
	if (chr) {
		if (chr->aibot->hasbriefcase) {
			chr->aibot->unk0a0 += g_Vars.lvupdate240;

			if (chr->aibot->unk0a0 >= PALDOWN(7200)) {
				sndStart(var80095200, SFX_MP_SCOREPOINT, NULL, -1, -1, -1, -1, -1);
				g_MpAllChrConfigPtrs[mpPlayerGetIndex(chr)]->numpoints++;
				chr->aibot->unk0a0 = 0;
			}
		} else {
			chr->aibot->unk0a0 = 0;
		}
	} else {
		if (invHasBriefcase()) {
			g_Vars.currentplayerstats->tokenheldtime += g_Vars.lvupdate240;

			if (g_Vars.currentplayerstats->tokenheldtime >= PALDOWN(7200)) {
				sndStart(var80095200, SFX_MP_SCOREPOINT, NULL, -1, -1, -1, -1, -1);
				g_MpAllChrConfigPtrs[g_Vars.currentplayernum]->numpoints++;
				hudmsgCreateWithFlags(langGet(L_MPWEAPONS_024), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE); // "1 Point!"
				g_Vars.currentplayerstats->tokenheldtime = 0;
			}
		} else {
			g_Vars.currentplayerstats->tokenheldtime = 0;
		}
	}
}

/**
 * @bug: In NTSC Final, the calculation of mins and subsequent subtraction from
 * time240 should use 60 * 240 instead of 30 * 240. This has no noticeable
 * effect unless the score duration is increased to above 30 seconds.
 *
 * PAL recognises that mins will always be 0 and simplifies the calculation.
 */
Gfx *scenarioHtbRenderHud(Gfx *gdl)
{
	s32 time240;
	s32 mins;
	s32 secs;
	s32 textwidth;
	s32 textheight;
	s32 x;
	s32 y;
	char text[64];

	if (invHasBriefcase()) {
		x = viGetViewLeft() + viGetViewWidth() / 2;
		y = viGetViewTop() + 10;

#if VERSION >= VERSION_PAL_FINAL
		time240 = (30 * 200) - g_Vars.currentplayerstats->tokenheldtime;
		secs = (time240 + 199) / 200;
		sprintf(text, "%d:%02d", 0, secs);
#else
		time240 = (30 * 240) - g_Vars.currentplayerstats->tokenheldtime;
		mins = time240 / (30 * 240);
		time240 -= (30 * 240) * mins;
		secs = (time240 + 239) / 240;
		sprintf(text, "%d:%02d", mins, secs);
#endif

		gdl = func0f153628(gdl);
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

		x -= textwidth / 2;
		textwidth += x;
		textheight += y;

#if VERSION >= VERSION_NTSC_1_0
		gdl = func0f153990(gdl, x, y, textwidth, textheight);
		gdl = textRender(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, 0x00ff00a0, 0xa0, viGetWidth(), viGetHeight(), 0, 0);
#else
		gdl = func0f153858(gdl, &x, &y, &textwidth, &textheight);
		gdl = textRender(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, 0x00ff00a0, 0x88, viGetWidth(), viGetHeight(), 0, 0);
#endif

		gdl = func0f153780(gdl);
	}

	return gdl;
}

void scenarioHtbCalculatePlayerScore(struct mpchrconfig *mpchr, s32 mpchrnum, s32 *score, s32 *deaths)
{
	struct mpchrconfig *loopmpchr;
	s32 i;

	*score = 0;
	*score += mpchr->numpoints;

	if (g_MpSetup.options & MPOPTION_KILLSSCORE) {
		for (i = 0; i != MAX_MPCHRS; i++) {
			if (i == mpchrnum) {
				*score -= mpchr->killcounts[i];
			} else if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				if (i < 4) {
					loopmpchr = &g_PlayerConfigsArray[i].base;
				} else {
					loopmpchr = &g_BotConfigsArray[i - 4].base;
				}

				if (loopmpchr->team == mpchr->team) {
					*score -= mpchr->killcounts[i];
				} else {
					*score += mpchr->killcounts[i];
				}
			} else {
				*score += mpchr->killcounts[i];
			}
		}
	}

	*deaths = mpchr->numdeaths;
}

Gfx *scenarioHtbRadar(Gfx *gdl)
{
	if ((g_MpSetup.options & MPOPTION_HTB_SHOWONRADAR) &&
			g_ScenarioData.htb.token != NULL &&
			g_ScenarioData.htb.token->type != PROPTYPE_PLAYER &&
			g_ScenarioData.htb.token->type != PROPTYPE_CHR) {
		struct coord dist;
		dist.x = g_ScenarioData.htb.pos.x - g_Vars.currentplayer->prop->pos.x;
		dist.y = g_ScenarioData.htb.pos.y - g_Vars.currentplayer->prop->pos.y;
		dist.z = g_ScenarioData.htb.pos.z - g_Vars.currentplayer->prop->pos.z;
		gdl = radarDrawDot(gdl, g_ScenarioData.htb.token, &dist, 0xff0000, 0, 1);
	}

	return gdl;
}

bool scenarioHtbRadar2(Gfx **gdl, struct prop *prop)
{
	if ((g_MpSetup.options & MPOPTION_HTB_SHOWONRADAR) &&
			g_ScenarioData.htb.token &&
			prop == g_ScenarioData.htb.token) {
		if (prop->type == PROPTYPE_PLAYER || prop->type == PROPTYPE_CHR) {
			struct coord dist;
			dist.x = prop->pos.x - g_Vars.currentplayer->prop->pos.x;
			dist.y = prop->pos.y - g_Vars.currentplayer->prop->pos.y;
			dist.z = prop->pos.z - g_Vars.currentplayer->prop->pos.z;

			if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				u32 colour = g_TeamColours[radarGetTeamIndex(prop->chr->team)];
				*gdl = radarDrawDot(*gdl, g_ScenarioData.htb.token, &dist, colour, 0, 1);
			} else {
				*gdl = radarDrawDot(*gdl, g_ScenarioData.htb.token, &dist, 0xff0000, 0, 1);
			}

			return true;
		}
	}

	return false;
}

bool scenarioHtbHighlight(struct prop *prop, s32 *colour)
{
	if ((g_MpSetup.options & MPOPTION_HTB_HIGHLIGHTBRIEFCASE) && prop == g_ScenarioData.htb.token) {
		colour[0] = 0;
		colour[1] = 0xff;
		colour[2] = 0;
		colour[3] = 0x40;

		return true;
	}

	return false;
}

void scenarioCtcInit(void)
{
	s32 i, j, k;
	g_MpSetup.options |= MPOPTION_TEAMSENABLED;

	for (i = 0; i < 4; i++) {
		s32 j;
		g_ScenarioData.ctc.spawnpadsperteam[i].homepad = i;
		g_ScenarioData.ctc.spawnpadsperteam[i].numspawnpads = 0;

		for (j = 0; j < 6; j++) {
			g_ScenarioData.ctc.spawnpadsperteam[i].spawnpads[j] = -1;
		}
	}

	for (i = 0; i != 4; i++) {
		g_ScenarioData.ctc.playercountsperteam[i] = 0;
		g_ScenarioData.ctc.teamindexes[i] = -1;
	}

	for (k = 0; k < MAX_MPCHRS; k++) {
		if (g_MpSetup.chrslots & (1 << k)) {
			struct mpchrconfig *basedata;

			if (k < 4) {
				basedata = &g_PlayerConfigsArray[k].base;
			} else {
				basedata = &g_BotConfigsArray[k - 4].base;
			}

			while (basedata->team >= scenarioGetMaxTeams()) {
				basedata->team -= scenarioGetMaxTeams();
			}
		}
	}
}

s32 scenarioCtcCallback08(void)
{
	return 4;
}

void scenarioCtcTick(void)
{
	// empty
}

void scenarioCtcCallback14(struct chrdata *chr)
{
	if (chr);
}

struct menuitem g_MpCaptureOptionsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_222,  MPOPTION_ONEHITKILLS,     menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU_223,  0x00000000,               menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_224,  MPOPTION_FASTMOVEMENT,    menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_225,  MPOPTION_DISPLAYTEAM,     menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_226,  MPOPTION_NORADAR,         menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_227,  MPOPTION_NOAUTOAIM,       menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS_493, MPOPTION_KILLSSCORE,      menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_236,  MPOPTION_CTC_SHOWONRADAR, menuhandlerMpCheckboxOption }, // "Show on Radar"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU_239,  0x00000000,               NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
};

struct menudialog g_MpCaptureOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_220, // "Capture Options"
	g_MpCaptureOptionsMenuItems,
	mpOptionsMenuDialog,
	0x00000010,
	NULL,
};

void scenarioCtcReset(void)
{
	struct mpchrconfig *mpchr;
	struct weaponobj *tmp;
	s32 mpindex;
	u32 stack;
	bool teamsdone[4];

	struct weaponobj template = {
		256,                    // extrascale
		0,                      // hidden2
		OBJTYPE_WEAPON,         // type
		MODEL_CHRBRIEFCASE,     // modelnum
		0,                      // pad
		OBJFLAG_00000001 | OBJFLAG_INVINCIBLE | OBJFLAG_00400000,
		OBJFLAG2_IMMUNETOGUNFIRE | OBJFLAG2_00200000,
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
		WEAPON_BRIEFCASE2,      // weaponnum
		0,                      // unk5d
		0,                      // unk5e
		FUNC_PRIMARY,           // gunfunc
		0,                      // fadeouttimer60
		-1,                     // dualweaponnum
		-1,                     // timer240
		NULL,                   // dualweapon
	};

	s32 i;
	s32 j;
	s32 k;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 6; j++) {
		}
	}

	for (i = 0; i < 4; i++) {
		teamsdone[i] = false;
		g_ScenarioData.ctc.playercountsperteam[i] = 0;
	}

	for (i = 0; i != 4; i++) {
		do {
			g_ScenarioData.ctc.teamindexes[i] = random() % 4;
		} while (teamsdone[g_ScenarioData.ctc.teamindexes[i]]);

		teamsdone[g_ScenarioData.ctc.teamindexes[i]] = true;
	}

	for (k = 0; k < 12; k++) {
		if (g_MpSetup.chrslots & (1 << k)) {
			if (k < 4) {
				mpchr = &g_PlayerConfigsArray[k].base;
			} else {
				mpchr = &g_BotConfigsArray[k - 4].base;
			}

			while (mpchr->team >= scenarioGetMaxTeams()) {
				mpchr->team -= scenarioGetMaxTeams();
			}

#if VERSION >= VERSION_NTSC_1_0
			mpindex = func0f18d0e8(k);

			if (mpindex >= 0) {
				struct chrdata *chr = mpGetChrFromPlayerIndex(mpindex);

				if (chr) {
					chr->team = 1 << mpchr->team;
				}
			}
#else
			if (func0f18d0e8(k) >= 0) {
				struct chrdata *chr = mpGetChrFromPlayerIndex(func0f18d0e8(k));

				if (chr) {
					chr->team = 1 << mpchr->team;
				}
			}
#endif

			g_ScenarioData.ctc.playercountsperteam[mpchr->team]++;
		}
	}

	for (i = 0; i < 4; i++) {
		if (g_ScenarioData.ctc.playercountsperteam[i] == 0) {
			g_ScenarioData.ctc.teamindexes[i] = -1;
		}
	}

	for (i = 0; i < 4; i++) {
		// empty
	}

	for (i = 0; i < 4; i++) {
		g_ScenarioData.ctc.tokens[i] = NULL;
	}

	for (i = 0; i < 4; i++) {
		g_ScenarioData.ctc.baserooms[i] = -1;
	}

	if (g_ScenarioData.ctc.playercountsperteam[0] != 0) {
		g_CtcTokenObj0 = template;
		tmp = &g_CtcTokenObj0;
		tmp->base.pad = g_ScenarioData.ctc.spawnpadsperteam[g_ScenarioData.ctc.teamindexes[0]].homepad;

		weaponAssignToHome(tmp, 1000);

		g_ScenarioData.ctc.tokens[0] = tmp->base.prop;

		tmp->base.hidden2 &= ~OBJH2FLAG_CANREGEN;
		tmp->team = 0;

		g_ScenarioData.ctc.baserooms[0] = g_ScenarioData.ctc.tokens[0]->rooms[0];
	}

	if (g_ScenarioData.ctc.playercountsperteam[1] != 0) {
		g_CtcTokenObj1 = template;
		tmp = &g_CtcTokenObj1;
		tmp->base.pad = g_ScenarioData.ctc.spawnpadsperteam[g_ScenarioData.ctc.teamindexes[1]].homepad;

		weaponAssignToHome(tmp, 1001);

		g_ScenarioData.ctc.tokens[1] = tmp->base.prop;

		tmp->base.hidden2 &= ~OBJH2FLAG_CANREGEN;
		tmp->team = 1;

		g_ScenarioData.ctc.baserooms[1] = g_ScenarioData.ctc.tokens[1]->rooms[0];
	}

	if (g_ScenarioData.ctc.playercountsperteam[2] != 0) {
		g_CtcTokenObj2 = template;
		tmp = &g_CtcTokenObj2;
		tmp->base.pad = g_ScenarioData.ctc.spawnpadsperteam[g_ScenarioData.ctc.teamindexes[2]].homepad;

		weaponAssignToHome(tmp, 1002);

		g_ScenarioData.ctc.tokens[2] = tmp->base.prop;

		tmp->base.hidden2 &= ~OBJH2FLAG_CANREGEN;
		tmp->team = 2;

		g_ScenarioData.ctc.baserooms[2] = g_ScenarioData.ctc.tokens[2]->rooms[0];
	}

	if (g_ScenarioData.ctc.playercountsperteam[3] != 0) {
		g_CtcTokenObj3 = template;
		tmp = &g_CtcTokenObj3;
		tmp->base.pad = g_ScenarioData.ctc.spawnpadsperteam[g_ScenarioData.ctc.teamindexes[3]].homepad;

		weaponAssignToHome(tmp, 1003);

		g_ScenarioData.ctc.tokens[3] = tmp->base.prop;

		tmp->base.hidden2 &= ~OBJH2FLAG_CANREGEN;
		tmp->team = 3;

		g_ScenarioData.ctc.baserooms[3] = g_ScenarioData.ctc.tokens[3]->rooms[0];
	}

	for (i = 0; i < 4; i++) {
		if (g_ScenarioData.ctc.playercountsperteam[i] && g_ScenarioData.ctc.baserooms[i] != -1) {
			roomSetLighting(g_ScenarioData.ctc.baserooms[i], 5, 0, 0, 0);
		}
	}
}

void scenarioCtcCalculatePlayerScore(struct mpchrconfig *mpchr, s32 mpchrnum, s32 *score, s32 *deaths)
{
	struct mpchrconfig *loopmpchr;
	s32 i;

	*score = 0;
	*score += mpchr->numpoints * 3;

	if (g_MpSetup.options & MPOPTION_KILLSSCORE) {
		for (i = 0; i != MAX_MPCHRS; i++) {
			if (i == mpchrnum) {
				*score -= mpchr->killcounts[i];
			} else {
				if (i < 4) {
					loopmpchr = &g_PlayerConfigsArray[i].base;
				} else {
					loopmpchr = &g_BotConfigsArray[i - 4].base;
				}

				if (loopmpchr->team == mpchr->team) {
					*score -= mpchr->killcounts[i];
				} else {
					*score += mpchr->killcounts[i];
				}
			}
		}
	}

	*deaths = mpchr->numdeaths;
}

Gfx *scenarioCtcRadar(Gfx *gdl)
{
	if (g_MpSetup.options & MPOPTION_CTC_SHOWONRADAR) {
		s32 i;

		for (i = 0; i < scenarioGetMaxTeams(); i++) {
			if (g_ScenarioData.ctc.tokens[i] &&
					g_ScenarioData.ctc.tokens[i]->type != PROPTYPE_CHR &&
					g_ScenarioData.ctc.tokens[i]->type != PROPTYPE_PLAYER) {
				struct coord dist;
				dist.x = g_ScenarioData.ctc.tokens[i]->pos.x - g_Vars.currentplayer->prop->pos.x;
				dist.y = g_ScenarioData.ctc.tokens[i]->pos.y - g_Vars.currentplayer->prop->pos.y;
				dist.z = g_ScenarioData.ctc.tokens[i]->pos.z - g_Vars.currentplayer->prop->pos.z;
				gdl = radarDrawDot(gdl, g_ScenarioData.ctc.tokens[i], &dist, g_TeamColours[i], 0, 1);
			}
		}
	}

	return gdl;
}

bool scenarioCtcRadar2(Gfx **gdl, struct prop *prop)
{
	s32 i;

	if (g_MpSetup.options & MPOPTION_CTC_SHOWONRADAR) {
		for (i = 0; i < scenarioGetMaxTeams(); i++) {
			if (prop == g_ScenarioData.ctc.tokens[i] &&
					(g_ScenarioData.ctc.tokens[i]->type == PROPTYPE_CHR || g_ScenarioData.ctc.tokens[i]->type == PROPTYPE_PLAYER)) {
				struct coord dist;
				s32 colour = g_TeamColours[radarGetTeamIndex(prop->chr->team)];
				dist.x = g_ScenarioData.ctc.tokens[i]->pos.x - g_Vars.currentplayer->prop->pos.x;
				dist.y = g_ScenarioData.ctc.tokens[i]->pos.y - g_Vars.currentplayer->prop->pos.y;
				dist.z = g_ScenarioData.ctc.tokens[i]->pos.z - g_Vars.currentplayer->prop->pos.z;
				*gdl = radarDrawDot(*gdl, g_ScenarioData.ctc.tokens[i], &dist,
						g_TeamColours[i], colour, 1);
				return true;
			}
		}
	}

	return false;
}

bool scenarioCtcHighlight(struct prop *prop, s32 *colour)
{
	struct defaultobj *obj = prop->obj;

	if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_DOOR) {
		if (obj->type == OBJTYPE_WEAPON) {
			struct weaponobj *weapon = prop->weapon;

			if (weapon->weaponnum == WEAPON_BRIEFCASE2) {
				u32 teamcolour = g_TeamColours[weapon->team];

				colour[0] = teamcolour >> 24 & 0xff;
				colour[1] = teamcolour >> 16 & 0xff;
				colour[2] = teamcolour >> 8 & 0xff;
				colour[3] = 75;

				return true;
			}
		}
	}

	return false;
}

void mpCtcAddPad(s32 *cmd)
{
	s32 i;

	if (cmd[0] == INTROCMD_CASE) {
		g_ScenarioData.ctc.spawnpadsperteam[cmd[1]].homepad = cmd[2];
	}

	if (cmd[0] == INTROCMD_CASERESPAWN) {
		for (i = 0; i != ARRAYCOUNT(g_ScenarioData.ctc.spawnpadsperteam[cmd[1]].spawnpads); i++) {
			if (g_ScenarioData.ctc.spawnpadsperteam[cmd[1]].spawnpads[i] == -1) {
				g_ScenarioData.ctc.spawnpadsperteam[cmd[1]].spawnpads[i] = cmd[2];
				g_ScenarioData.ctc.spawnpadsperteam[cmd[1]].numspawnpads++;
				return;
			}
		}
	}
}

bool scenarioCtcChooseSpawnLocation(f32 arg0, struct coord *pos, s16 *rooms, struct prop *prop, f32 *arg4)
{
	struct chrdata *chr = prop->chr;
	s32 index = radarGetTeamIndex(chr->team);

	if (g_ScenarioData.ctc.spawnpadsperteam[g_ScenarioData.ctc.teamindexes[index]].numspawnpads > 0) {
		*arg4 = playerChooseSpawnLocation(arg0, pos, rooms, prop,
				g_ScenarioData.ctc.spawnpadsperteam[g_ScenarioData.ctc.teamindexes[index]].spawnpads,
				g_ScenarioData.ctc.spawnpadsperteam[g_ScenarioData.ctc.teamindexes[index]].numspawnpads);
		return true;
	}

	return false;
}

s32 scenarioCtcGetMaxTeams(void)
{
	return 4;
}

bool scenarioCtcIsRoomHighlighted(s16 room)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (g_ScenarioData.ctc.baserooms[i] == room && g_ScenarioData.ctc.teamindexes[i] != -1) {
			return true;
		}
	}

	return false;
}

void scenarioCtcCallback38(s16 roomnum, s32 *arg1, s32 *arg2, s32 *arg3)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (g_ScenarioData.ctc.baserooms[i] == roomnum) {
			u32 colour = g_TeamColours[i];
			f32 a = *arg1;
			f32 b = *arg2;
			f32 c = *arg3;

			a *= (s32)((colour >> 24 & 0xff) + 0xff) * (1.0f / 512.0f);
			b *= (s32)((colour >> 16 & 0xff) + 0xff) * (1.0f / 512.0f);
			c *= (s32)((colour >> 8 & 0xff) + 0xff) * (1.0f / 512.0f);

			*arg1 = a;
			*arg2 = b;
			*arg3 = c;
			return;
		}
	}
}

s32 menuhandlerMpHillTime(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GETSLIDER:
		data->slider.value = g_Vars.mphilltime;
		break;
	case MENUOP_SET:
		g_Vars.mphilltime = (u8)data->slider.value;
		break;
	case MENUOP_GETSLIDERLABEL:
		sprintf(data->slider.label, langGet(L_MPWEAPONS_023), data->slider.value + 10); // "%ds/Point"
		break;
	}

	return 0;
}

void scenarioKohReadSave(struct savebuffer *buffer)
{
	g_Vars.mphilltime = savebufferReadBits(buffer, 8);
}

void scenarioKohWriteSave(struct savebuffer *buffer)
{
	savebufferOr(buffer, g_Vars.mphilltime, 8);
}

void scenarioKohInit(void)
{
	s32 i;

	g_MpSetup.options |= MPOPTION_TEAMSENABLED;
	g_ScenarioData.koh.hillindex = -1;
	g_ScenarioData.koh.hillcount = 0;
	g_ScenarioData.koh.unk00 = 0;
	g_ScenarioData.koh.occupiedteam = -1;
	g_ScenarioData.koh.elapsed240 = 0;
	g_ScenarioData.koh.hillrooms[0] = -1;
	g_ScenarioData.koh.hillrooms[1] = -1;
	g_ScenarioData.koh.hillpos.x = 0;
	g_ScenarioData.koh.hillpos.y = 0;
	g_ScenarioData.koh.hillpos.z = 0;
	g_ScenarioData.koh.colourfracr = 0.25;
	g_ScenarioData.koh.colourfracg = 1;
	g_ScenarioData.koh.colourfracb = 0.25;

	for (i = 0; i < 9; i++) {
		g_ScenarioData.koh.hillpads[i] = -1;
	}
}

void scenarioKohReset(void)
{
	s16 pad_id = 0;
	struct pad pad;

	if (g_ScenarioData.koh.hillcount > 1) {
		g_ScenarioData.koh.hillindex = random() % g_ScenarioData.koh.hillcount;
		pad_id = g_ScenarioData.koh.hillpads[g_ScenarioData.koh.hillindex];
	} else {
		// @bug: If a stage setup file only has one hill, pad_id is not assigned
		// so it will always use the room that contains pad zero.
		g_ScenarioData.koh.hillindex = 0;
	}

	padUnpack(pad_id, PADFIELD_POS | PADFIELD_ROOM, &pad);
	g_ScenarioData.koh.hillrooms[0] = pad.room;
	g_ScenarioData.koh.hillrooms[1] = -1;
	g_ScenarioData.koh.hillpos.x = pad.pos.x;
	g_ScenarioData.koh.hillpos.y = pad.pos.y;
	g_ScenarioData.koh.hillpos.z = pad.pos.z;
	g_ScenarioData.koh.hillpos.y = cd0002a36c(&g_ScenarioData.koh.hillpos, &g_ScenarioData.koh.hillrooms[0], 0, 0);
	g_ScenarioData.koh.movehill = false;
	roomSetLighting(g_ScenarioData.koh.hillrooms[0], LIGHTOP_5, 0, 0, 0);
}

/**
 * A match for this function has only been possible by making heavy reuse of
 * variables, but this impacts readability significantly.
 *
 * To make this code readable, constants have been used to map appropriate names
 * to the underlying variable.
 */
void scenarioKohTick(void)
{
	s32 i;
	s32 hillteam;
	s32 s1;
	s32 s2;
	s32 numchrsinhill;
	s32 dualoccupancy;
	s32 s0;
	s32 previndex;
	f32 targetr;
	f32 targetg;
	f32 targetb;
	char text[64];
	s32 teamsinhill[8];
	struct pad pad;
	struct prop *chrsinhill[12];
	struct prop *prop;
	struct chrdata *chr;
	s32 padnum;
	s32 teamindex;

#define hillteam       s0
#define inhill         s1
#define mostchrs       s1
#define playernum1     s1
#define prevplayernum1 s1
#define numteamsinhill s2
#define prevplayernum2 s2
#define playernum2     s2

	if (g_ScenarioData.koh.hillindex == -1) {
		return;
	}

	dualoccupancy = 0;

	if (g_ScenarioData.koh.movehill) {
		// The hill is moving, but first it needs to be returned to the natural
		// colour. This is done using a fade over several frames.
		g_ScenarioData.koh.occupiedteam = -1;
		g_ScenarioData.koh.elapsed240 = 0;

		targetr = 1;
		targetg = 1;
		targetb = 1;

		if (g_ScenarioData.koh.colourfracr >= .95f
				&& g_ScenarioData.koh.colourfracg >= .95f
				&& g_ScenarioData.koh.colourfracb >= .95f) {
			// The old hill is now "natural enough" to set it back to full
			// natural colour and actually choose a new hill.
			roomSetLighting(g_ScenarioData.koh.hillrooms[0], 0, 0, 0, 0);

			// Choose the new hill. Note that hillcount refers to the number of
			// hill options, which is always >= 2.
			padnum = 0;

			if (g_ScenarioData.koh.hillcount >= 2) {
				previndex = g_ScenarioData.koh.hillindex;

				do {
					g_ScenarioData.koh.hillindex = random() % g_ScenarioData.koh.hillcount;
				} while (g_ScenarioData.koh.hillindex == previndex);

				padnum = g_ScenarioData.koh.hillpads[g_ScenarioData.koh.hillindex];
			} else {
				g_ScenarioData.koh.hillindex = 0;
			}

			padUnpack(padnum, PADFIELD_POS | PADFIELD_ROOM, &pad);

			g_ScenarioData.koh.hillrooms[0] = pad.room;
			g_ScenarioData.koh.hillrooms[1] = -1;

			g_ScenarioData.koh.hillpos.x = pad.pos.x;
			g_ScenarioData.koh.hillpos.y = pad.pos.y;
			g_ScenarioData.koh.hillpos.z = pad.pos.z;

			g_ScenarioData.koh.hillpos.y = cd0002a36c(&g_ScenarioData.koh.hillpos, g_ScenarioData.koh.hillrooms, NULL, NULL);

			roomSetLighting(g_ScenarioData.koh.hillrooms[0], 5, 0, 0, 0);

			g_ScenarioData.koh.occupiedteam = -1;
			g_ScenarioData.koh.elapsed240 = 0;
			g_ScenarioData.koh.movehill = false;
		}
	} else {
		// The hill is not moving on this frame
		// Build an array of chr props who are in the hill
		numchrsinhill = 0;
		prop = g_Vars.activeprops;

		while (prop) {
			if (prop->type == PROPTYPE_PLAYER || prop->type == PROPTYPE_CHR) {
				inhill = false;

				if (prop->rooms[0] == g_ScenarioData.koh.hillrooms[0]) {
					inhill = true;
				}

				if (inhill) {
					chr = prop->chr;

					if (!chrIsDead(chr)) {
						chrsinhill[numchrsinhill] = prop;
						numchrsinhill++;
					}
				}
			}

			prop = prop->next;
		}

		// Use the chrshillhill array to build an array of all teams who have
		// chrs in the hill. During development, this array likely stored a
		// count of that team's chrs but was later changed to just be 0 or 1
		// to denote if they have any chrs in the hill.
		for (s0 = 0; s0 < 8; s0++) {
			teamsinhill[s0] = 0;
		}

		for (s0 = 0, numteamsinhill = 0; s0 < numchrsinhill; s0++) {
			chr = chrsinhill[s0]->chr;
			teamindex = radarGetTeamIndex(chr->team);

			if (teamsinhill[teamindex] == 0) {
				numteamsinhill++;
				teamsinhill[teamindex] = 1;
			}
		}

		if (numteamsinhill == 0) {
			g_ScenarioData.koh.occupiedteam = -1;
			g_ScenarioData.koh.elapsed240 = 0;
		} else {
			if (numteamsinhill == 1) {
				// Set hillteam for later
				for (hillteam = 0; hillteam < 8; hillteam++) {
					if (teamsinhill[hillteam]) {
						break;
					}
				}
			} else {
				// There are multiple teams in the hill.
				// This code attempts to filter the teamsinhill array to only
				// those which have the most chrs, but the teamsinhill array
				// only contains values 0 or 1 so it effectively does nothing.
				mostchrs = 0;

				for (s0 = 0; s0 < 8; s0++) {
					if (teamsinhill[s0] > mostchrs) {
						mostchrs = teamsinhill[s0];
					}
				}

				for (s0 = 0; s0 < 8; s0++) {
					if (teamsinhill[s0] != mostchrs) {
						teamsinhill[s0] = false;
					}
				}

				// Count the number of teams who are tied for the most chrs in
				// the hill. Or rather, because the teamsinhill array only
				// contains 0 or 1 values, this is just recounting the number of
				// teams who have presence in the hill.
				for (s0 = 0; s0 < 8; s0++) {
					if (teamsinhill[s0]) {
						dualoccupancy++;
					}
				}

				dualoccupancy = dualoccupancy >= 2 ? true : false;

				// Set the hillteam to whoever was holding it previously
				// so the hill remains the same colour
				for (hillteam = 0; hillteam < 8; hillteam++) {
					if (teamsinhill[hillteam] && hillteam == g_ScenarioData.koh.occupiedteam) {
						break;
					}
				}

				if (hillteam == 8) {
					// This happens if the controlling team leaves the hill
					// and there are two other teams still in the hill.
					// The hill goes green until one team holds it exclusively.
					g_ScenarioData.koh.occupiedteam = -1;
					hillteam = -1;
				}
			}

			// At this point we know there is a team in the hill on this frame.
			// So if these don't match then the hill is turning into a team
			// colour rather than going green.
			if (hillteam != g_ScenarioData.koh.occupiedteam) {
				sndStart(var80095200, SFX_MP_HILLENTERED, 0, -1, -1, -1, -1, -1);

				g_ScenarioData.koh.occupiedteam = hillteam;
				g_ScenarioData.koh.elapsed240 = 0;

				// "%has captured the Hill!"
				sprintf(text, langGet(L_MPWEAPONS_022), &g_BossFile.teamnames[hillteam]);

				prevplayernum2 = g_Vars.currentplayernum;

				for (playernum1 = 0; playernum1 < PLAYERCOUNT(); playernum1++) {
					setCurrentPlayerNum(playernum1);

					chr = g_Vars.currentplayer->prop->chr;

					if (radarGetTeamIndex(chr->team) == g_ScenarioData.koh.occupiedteam) {
						// "We have the Hill!"
						hudmsgCreateWithFlags(langGet(L_MPWEAPONS_021), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
					} else {
						hudmsgCreateWithFlags(text, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
					}
				}

				setCurrentPlayerNum(prevplayernum2);
			} else {
				// A team is remaining in the hill.
				// Only tick the hill timer if they have exclusive occupancy.
				if (!dualoccupancy) {
					g_ScenarioData.koh.elapsed240 += g_Vars.lvupdate240;

					if (g_ScenarioData.koh.elapsed240 >= g_Vars.mphilltime * PALDOWN(240) + PALDOWN(2400)) {
						// Scored a point
						sndStart(var80095200, SFX_MP_SCOREPOINT, 0, -1, -1, -1, -1, -1);

						// @bug: There is no check for a chr being dead here.
						// If a player dies in the hill and waits on the
						// "press start" screen while their team mate scores the
						// hill, the dead player will always be awarded a point.
						for (playernum2 = 0; playernum2 < g_MpNumChrs; playernum2++) {
							if (radarGetTeamIndex(g_MpAllChrPtrs[playernum2]->team) == g_ScenarioData.koh.occupiedteam) {
								prop = g_MpAllChrPtrs[playernum2]->prop;

								if (prop->rooms[0] == g_ScenarioData.koh.hillrooms[0]) {
									g_MpAllChrConfigPtrs[playernum2]->numpoints++;
								}
							}
						}

						prevplayernum1 = g_Vars.currentplayernum;

						for (playernum2 = 0; playernum2 < g_MpNumChrs; playernum2++) {
							if (g_MpAllChrPtrs[playernum2]->aibot == NULL
									&& radarGetTeamIndex(g_MpAllChrPtrs[playernum2]->team) == g_ScenarioData.koh.occupiedteam) {
								setCurrentPlayerNum(playernum2);

								// "King of the Hill!"
								hudmsgCreateWithFlags(langGet(L_MPWEAPONS_020), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
							}
						}

						setCurrentPlayerNum(prevplayernum1);

						g_ScenarioData.koh.occupiedteam = -1;
						g_ScenarioData.koh.elapsed240 = 0;

						if (g_MpSetup.options & MPOPTION_KOH_MOBILEHILL) {
							g_ScenarioData.koh.movehill = true;
						}
					}
				}
			}
		}

		// Calculate what colour the hill should tween towards
		if (g_ScenarioData.koh.occupiedteam == -1) {
			targetr = 0.25f;
			targetg = 1;
			targetb = 0.25f;
		} else {
			u32 colour = g_TeamColours[g_ScenarioData.koh.occupiedteam];
			targetr = ((s32)(colour >> 24 & 0xff) + 0xff) * (1.0f / 512.0f);
			targetg = ((s32)(colour >> 16 & 0xff) + 0xff) * (1.0f / 512.0f);
			targetb = ((s32)(colour >> 8 & 0xff) + 0xff) * (1.0f / 512.0f);
		}
	}

	// Tween the colour components towards the target colour.
	// @bug: This increments using g_Vars.diffframe60, which is updated while
	// the game is paused. Because of this, if you pause as soon as a hill is
	// scored then the colour fade and selection of the new hill will happen
	// while paused.
	if (g_ScenarioData.koh.colourfracr != targetr) {
		for (i = 0; i < g_Vars.diffframe60; i++) {
#if PAL
			g_ScenarioData.koh.colourfracr = 0.0597f * targetr + 0.9403f * g_ScenarioData.koh.colourfracr;
#else
			g_ScenarioData.koh.colourfracr = 0.05f * targetr + 0.95f * g_ScenarioData.koh.colourfracr;
#endif
		}
	}

	if (g_ScenarioData.koh.colourfracg != targetg) {
		for (i = 0; i < g_Vars.diffframe60; i++) {
#if PAL
			g_ScenarioData.koh.colourfracg = 0.0597f * targetg + 0.9403f * g_ScenarioData.koh.colourfracg;
#else
			g_ScenarioData.koh.colourfracg = 0.05f * targetg + 0.95f * g_ScenarioData.koh.colourfracg;
#endif
		}
	}

	if (g_ScenarioData.koh.colourfracb != targetb) {
		for (i = 0; i < g_Vars.diffframe60; i++) {
#if PAL
			g_ScenarioData.koh.colourfracb = 0.0597f * targetb + 0.9403f * g_ScenarioData.koh.colourfracb;
#else
			g_ScenarioData.koh.colourfracb = 0.05f * targetb + 0.95f * g_ScenarioData.koh.colourfracb;
#endif
		}
	}
}

Gfx *scenarioKohRenderHud(Gfx *gdl)
{
	s32 time240;
	s32 mins;
	s32 secs;
	s32 textwidth;
	s32 textheight;
	s32 x;
	s32 y;
	struct chrdata *chr = g_Vars.currentplayer->prop->chr;
	char text[64];

	if (radarGetTeamIndex(chr->team) == g_ScenarioData.koh.occupiedteam && !g_ScenarioData.koh.movehill) {
		x = viGetViewLeft() + viGetViewWidth() / 2;
		y = viGetViewTop() + 10;

		time240 = g_Vars.mphilltime * PALDOWN(240) - g_ScenarioData.koh.elapsed240;
		time240 += PAL ? 2199 : 2400;
		mins = time240 / PALDOWN(60 * 240);
		time240 -= PALDOWN(60 * 240) * mins;

#if PAL
		secs = time240 / PALDOWN(240);
#else
		secs = (time240 + (PALDOWN(240) - 1)) / PALDOWN(240);
#endif

		if ((g_Vars.mphilltime * 60 + 600) / 3600) {
			sprintf(text, "%d:%02d", mins, secs);
		} else {
			sprintf(text, "%02d", secs);
		}

		gdl = func0f153628(gdl);
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

		x -= textwidth / 2;
		textwidth += x;
		textheight += y;

#if VERSION >= VERSION_NTSC_1_0
		gdl = func0f153990(gdl, x, y, textwidth, textheight);
		gdl = textRender(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, 0x00ff00a0, 0xa0, viGetWidth(), viGetHeight(), 0, 0);
#else
		gdl = func0f153858(gdl, &x, &y, &textwidth, &textheight);
		gdl = textRender(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, 0x00ff00a0, 0x88, viGetWidth(), viGetHeight(), 0, 0);
#endif
		gdl = func0f153780(gdl);
	}

	return gdl;
}

const char var7f1b84a8[] = "HackThatMacAddBankPad -> Adding New Pad %d  - Pad Id = %d-> Saving Pad\n";
const char var7f1b84f0[] = "HackThatMacReset -> Working\n";

void scenarioKohCalculatePlayerScore(struct mpchrconfig *mpchr, s32 mpchrnum, s32 *score, s32 *deaths)
{
	struct mpchrconfig *loopmpchr;
	s32 i;

	*score = 0;
	*score += mpchr->numpoints;

	if (g_MpSetup.options & MPOPTION_KILLSSCORE) {
		for (i = 0; i != MAX_MPCHRS; i++) {
			if (i == mpchrnum) {
				*score -= mpchr->killcounts[i];
			} else {
				if (i < 4) {
					loopmpchr = &g_PlayerConfigsArray[i].base;
				} else {
					loopmpchr = &g_BotConfigsArray[i - 4].base;
				}

				if (loopmpchr->team == mpchr->team) {
					*score -= mpchr->killcounts[i];
				} else {
					*score += mpchr->killcounts[i];
				}
			}
		}
	}

	*deaths = mpchr->numdeaths;
}

Gfx *scenarioKohRadar(Gfx *gdl)
{
	if (g_MpSetup.options & MPOPTION_KOH_HILLONRADAR && !g_ScenarioData.koh.movehill) {
		struct coord dist;
		u32 colour;
		dist.x = g_ScenarioData.koh.hillpos.x - g_Vars.currentplayer->prop->pos.x;
		dist.y = g_ScenarioData.koh.hillpos.y - g_Vars.currentplayer->prop->pos.y;
		dist.z = g_ScenarioData.koh.hillpos.z - g_Vars.currentplayer->prop->pos.z;

		if (g_ScenarioData.koh.occupiedteam == -1) {
			colour = 0xff0000;
		} else {
			colour = g_TeamColours[g_ScenarioData.koh.occupiedteam];
		}

		gdl = radarDrawDot(gdl, NULL, &dist, colour, 0, 1);
	}

	return gdl;
}

void mpKohAddHill(s32 *cmd)
{
	if (g_ScenarioData.koh.hillcount < ARRAYCOUNT(g_ScenarioData.koh.hillpads)) {
		g_ScenarioData.koh.hillpads[g_ScenarioData.koh.hillcount] = cmd[1];
		g_ScenarioData.koh.hillcount++;
	}
}

bool scenarioKohIsRoomHighlighted(s16 room)
{
	return room == g_ScenarioData.koh.hillrooms[0];
}

void scenarioKohCallback38(s16 roomnum, s32 *arg1, s32 *arg2, s32 *arg3)
{
	if (roomnum == g_ScenarioData.koh.hillrooms[0]) {
		f32 a = *arg1;
		f32 b = *arg2;
		f32 c = *arg3;

		a *= g_ScenarioData.koh.colourfracr;
		b *= g_ScenarioData.koh.colourfracg;
		c *= g_ScenarioData.koh.colourfracb;

		*arg1 = a;
		*arg2 = b;
		*arg3 = c;
	}
}

void scenarioHtmInit(void)
{
	g_ScenarioData.htm.uplink = NULL;
}

s32 scenarioHtmCallback08(void)
{
	return 2;
}

void mpHtmAddPad(s16 padnum)
{
	struct scenariodata_htm *data = &g_ScenarioData.htm;

#if VERSION >= VERSION_NTSC_1_0
	if (data->nextindex < 60)
#endif
	{
		data->padnums[data->nextindex] = padnum;
		data->nextindex++;
	}
}

void func0f182bf4(void)
{
	s32 i;

	g_ScenarioData.htm.nextindex = 0;
	g_ScenarioData.htm.unk002 = 0;
	g_ScenarioData.htm.unk138 = 0;
	g_ScenarioData.htm.dlplayernum = -1;
	g_ScenarioData.htm.playernuminrange = -1;
	g_ScenarioData.htm.dlterminalnum = -1;
	g_ScenarioData.htm.unk140 = 0;

	for (i = 0; i < ARRAYCOUNT(g_ScenarioData.htm.numpoints); i++) {
		g_ScenarioData.htm.numpoints[i] = 0;
		g_ScenarioData.htm.dltime240[i] = 0;
	}

	for (i = 0; i < ARRAYCOUNT(g_ScenarioData.htm.padnums); i++) {
		g_ScenarioData.htm.padnums[i] = -1;
	}

	for (i = 0; i < 1; i++) {
		g_ScenarioData.htm.terminals[i].unk00 = 0;
		g_ScenarioData.htm.terminals[i].prop = NULL;
		g_ScenarioData.htm.terminals[i].padnum = -1;
		g_ScenarioData.htm.terminals[i].team = 255;
		g_ScenarioData.htm.terminals[i].unk0b = 255;
	}
}

struct menuitem g_MpHillOptionsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_222,  MPOPTION_ONEHITKILLS,     menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU_223,  0x00000000,               menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_224,  MPOPTION_FASTMOVEMENT,    menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_225,  MPOPTION_DISPLAYTEAM,     menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_226,  MPOPTION_NORADAR,         menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_227,  MPOPTION_NOAUTOAIM,       menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS_493, MPOPTION_KILLSSCORE,      menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_233,  MPOPTION_KOH_HILLONRADAR, menuhandlerMpCheckboxOption }, // "Hill on Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_234,  MPOPTION_KOH_MOBILEHILL,  menuhandlerMpCheckboxOption }, // "Mobile Hill"
	{ MENUITEMTYPE_SLIDER,     0, 0x00020000, L_MPMENU_235,  0x0000006e,               menuhandlerMpHillTime       }, // "Time"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU_239,  0x00000000,               NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
};

struct menudialog g_MpHillOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_219, // "Hill Options"
	g_MpHillOptionsMenuItems,
	mpOptionsMenuDialog,
	0x00000010,
	NULL,
};

struct menuitem g_MpHackerOptionsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_222,  MPOPTION_ONEHITKILLS,           menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU_223,  0x00000000,                     menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_224,  MPOPTION_FASTMOVEMENT,          menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_225,  MPOPTION_DISPLAYTEAM,           menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_226,  MPOPTION_NORADAR,               menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_227,  MPOPTION_NOAUTOAIM,             menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS_493, MPOPTION_KILLSSCORE,            menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                     NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_231,  MPOPTION_HTM_HIGHLIGHTTERMINAL, menuhandlerMpCheckboxOption }, // "Highlight Terminal"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_238,  MPOPTION_HTM_SHOWONRADAR,       menuhandlerMpCheckboxOption }, // "Show on Radar"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                     NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU_239,  0x00000000,                     NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,                     NULL                        },
};

struct menudialog g_MpHackerOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_217, // "Hacker Options"
	g_MpHackerOptionsMenuItems,
	mpOptionsMenuDialog,
	0x00000010,
	NULL,
};

void scenarioHtmCreateUplink(void)
{
	struct weaponobj template = {
		512,                    // extrascale
		0,                      // hidden2
		OBJTYPE_WEAPON,         // type
		MODEL_CHRDATATHIEF,     // modelnum
		0,                      // pad
		OBJFLAG_00000001 | OBJFLAG_INVINCIBLE | OBJFLAG_00400000,
		OBJFLAG2_IMMUNETOGUNFIRE | OBJFLAG2_00200000,
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
		WEAPON_DATAUPLINK,      // weaponnum
		0,                      // unk5d
		0,                      // unk5e
		FUNC_PRIMARY,           // gunfunc
		0,                      // fadeouttimer60
		-1,                     // dualweaponnum
		-1,                     // timer240
		NULL,                   // dualweapon
	};

	struct prop *prop = g_Vars.activeprops;
	struct defaultobj *obj;
	s32 padnum;
	s32 count = 0;
	struct defaultobj *candidates[20];

	while (prop && count < 20) {
#if VERSION >= VERSION_NTSC_1_0
		if (prop->type == PROPTYPE_OBJ)
#endif
		{
			obj = prop->obj;

			if (obj->type == OBJTYPE_MULTIAMMOCRATE) {
				candidates[count] = obj;
				count++;
			}
		}

		prop = prop->next;
	}

	if (count > 0) {
		count = random() % count;
		var800869ec = candidates[count];
		var800869ec->hidden |= OBJHFLAG_REAPABLE;
		var800869ec->hidden2 |= OBJH2FLAG_CANREGEN;
		padnum = var800869ec->pad;
	} else if (g_ScenarioData.htm.nextindex > 0) {
		padnum = g_ScenarioData.htm.padnums[random() % g_ScenarioData.htm.nextindex];
	} else {
		padnum = 0;
	}

	g_HtmUplinkObj = template;
	g_HtmUplinkObj.base.pad = padnum;

	weaponAssignToHome(&g_HtmUplinkObj, 999);

	g_HtmUplinkObj.base.hidden2 &= ~OBJH2FLAG_CANREGEN;

	g_ScenarioData.htm.uplink = g_HtmUplinkObj.base.prop;

	if (g_ScenarioData.htm.uplink) {
		g_ScenarioData.htm.uplink->forcetick = true;
	}
}

void scenarioHtmReset(void)
{
	struct scenariodata_htm *data = &g_ScenarioData.htm;
	struct prop *prop = g_Vars.activeprops;
	s32 i = 0;
	s32 rand;

	osSyncPrintf("HackThatMacInitProps -> Start : %d Bank Pads\n", data->unk002);

	while (prop) {
		if (prop->type == PROPTYPE_OBJ) {
			struct defaultobj *obj = prop->obj;

			if (obj->type == OBJTYPE_AMMOCRATE || obj->type == OBJTYPE_MULTIAMMOCRATE) {
				if (obj->modelnum == MODEL_MULTI_AMMO_CRATE) {
					osSyncPrintf("HackThatMacInitProps -> Adding prop %d (%x)\n", i, obj->pad);
					mpHtmAddPad(obj->pad);
				}
			}
		}

		prop = prop->next;
		i++;
	}

	osSyncPrintf("HackThatMacInitProps -> Mid : %d Bank Pads\n", data->nextindex);
	osSyncPrintf("HackThatMacInitProps -> Generating %d random box pads from %d in the bank\n", scenarioHtmCallback08(), data->nextindex);

	data->unk002 = 0;

	while (data->unk002 < scenarioHtmCallback08()) {
		s32 padnum;

		do {
			rand = random() % data->nextindex;
			padnum = data->padnums[rand];
		} while (padnum <= 0);

		data->terminals[data->unk002].padnum = padnum;
		data->unk002++;
		data->padnums[rand] = -1;
	}

	osSyncPrintf("HackThatMacInitProps -> %d/%d Random box pads generated - Listing\n", data->unk002, scenarioHtmCallback08());

	for (i = 0; i < data->unk002; i++) {
		osSyncPrintf("Pad %d -> Pad Id = %d\n", i, data->terminals[i].padnum);
	}

	for (i = 0; i < 1; i++) {
		data->terminals[i].prop = scenarioCreateObj(MODEL_GOODPC, data->terminals[i].padnum, 0.2f,
				OBJFLAG_00000001 | OBJFLAG_INVINCIBLE | OBJFLAG_00400000,
				OBJFLAG2_IMMUNETOGUNFIRE | OBJFLAG2_00200000,
				OBJFLAG3_HTMTERMINAL | OBJFLAG3_INTERACTABLE);
		osSyncPrintf("HackThatMacInitProps -> Building and adding custom prop %d - Pad=%d, Ptr=%08x\n",
				i, data->terminals[i].padnum, data->terminals[i].prop);
		scenarioHtmRemoveAmmoCrateAtPad(data->terminals[i].padnum);
	}

	var800869ec = NULL;

	scenarioHtmCreateUplink();

	osSyncPrintf("HackThatMacInitProps -> End\n");
}

void scenarioHtmTick(void)
{
	u8 stack[8];
	s32 i;
	u32 prevplayernum = g_Vars.currentplayernum;
	struct prop *prop;

	if (var800869ec && var800869ec->prop) {
		if (g_ScenarioData.htm.uplink == NULL || g_ScenarioData.htm.uplink->type != PROPTYPE_WEAPON) {
			var800869ec = NULL;
		} else {
			var800869ec->prop->timetoregen = PALDOWN(1200);
		}
	}

	g_ScenarioData.htm.uplink = NULL;

	// Check if uplink is on the ground
	prop = g_Vars.activeprops;

	while (prop) {
		if (prop->type == PROPTYPE_WEAPON) {
			struct weaponobj *weapon = prop->weapon;

			if (weapon->weaponnum == WEAPON_DATAUPLINK) {
				g_ScenarioData.htm.uplink = prop;
			}
		}

		prop = prop->next;
	}

	// Check if a player is holding it
	if (g_ScenarioData.htm.uplink == NULL) {
		for (i = 0; i < PLAYERCOUNT(); i++) {
			setCurrentPlayerNum(i);

			if (invHasDataUplink()) {
				g_ScenarioData.htm.uplink = g_Vars.currentplayer->prop;
				break;
			}
		}
	}

	setCurrentPlayerNum(prevplayernum);

	// Check if a simulant is holding it
	if (g_ScenarioData.htm.uplink == NULL) {
		for (i = PLAYERCOUNT(); i < g_MpNumChrs; i++) {
			if (g_MpAllChrPtrs[i]->aibot->hasuplink) {
				g_ScenarioData.htm.uplink = g_MpAllChrPtrs[i]->prop;
				break;
			}
		}
	}

	if (g_ScenarioData.htm.uplink == NULL) {
		scenarioHtmCreateUplink();
	}
}

void scenarioHtmCallback14(struct chrdata *chr)
{
	struct scenariodata_htm *data = &g_ScenarioData.htm;
	bool hasuplink;
	s32 playernum;
	s32 i;
	s32 *time;

	if (chr) {
		hasuplink = chr->aibot->hasuplink;
		playernum = mpPlayerGetIndex(chr);
	} else {
		hasuplink = invHasDataUplink() && bgunGetWeaponNum(HAND_RIGHT) == WEAPON_DATAUPLINK;
		playernum = g_Vars.currentplayernum;
	}

	time = &data->dltime240[playernum];

	for (i = 0; i < 1; i++) {
		if (data->terminals[i].prop) {
			struct prop *prop = data->terminals[i].prop;
			struct defaultobj *obj = prop->obj;
			s32 activatedbyplayernum = -1;

			if (chr) {
				if (hasuplink) {
					activatedbyplayernum = playernum;
				}
			} else {
				if (obj->hidden & OBJHFLAG_ACTIVATED_BY_BOND) {
					activatedbyplayernum = (obj->hidden & 0xf0000000) >> 28;
				}
			}

			if (playernum == activatedbyplayernum) {
				obj->hidden &= ~OBJHFLAG_ACTIVATED_BY_BOND;
				obj->hidden &= ~0xf0000000;

				if (hasuplink) {
					if (data->dlterminalnum == -1) {
						data->dlterminalnum = i;
						data->dlplayernum = playernum;
						data->playernuminrange = playernum;
						*time = 0;

						if (chr == NULL) {
							hudmsgCreateWithFlags(langGet(L_MPWEAPONS_018), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE); // "Starting download."
							func0f0939f8(NULL, data->terminals[data->dlterminalnum].prop, SFX_01BF, -1,
									-1, 2, 2, 0, NULL, -1, NULL, -1, -1, -1, -1);
						}
					}
				} else {
					if (chr == NULL) {
						hudmsgCreateWithFlags(langGet(L_MPWEAPONS_019), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE); // "You need to use the Data Uplink."
						snd00010718(NULL, 0, 0x7fff, 0x40, SFX_01CC, 1, 1, -1, 1);
					}
				}
			}
		}
	}

	if (playernum == data->dlplayernum && data->dlterminalnum != -1) {
		struct coord *terminalpos = &data->terminals[data->dlterminalnum].prop->pos;
		f32 angle;
		f32 relangle;
		f32 rangexz;
		f32 rangey;
		struct coord *chrpos;
		struct coord dist;
		bool holdinguplink;

		if (chr) {
			chrpos = &chr->prop->pos;
			angle = (M_BADTAU - chrGetInverseTheta(chr)) * 57.295776367188f;
			holdinguplink = chr->aibot->weaponnum == WEAPON_UNARMED;
		} else {
			chrpos = &g_Vars.currentplayer->prop->pos;
			angle = g_Vars.currentplayer->vv_theta;
			holdinguplink = bgunGetWeaponNum(HAND_RIGHT) == WEAPON_DATAUPLINK;
		}

		dist.x = terminalpos->x - chrpos->x;
		dist.y = terminalpos->y - chrpos->y;
		dist.z = terminalpos->z - chrpos->z;

		rangexz = sqrtf(dist.x * dist.x + dist.z * dist.z);

		rangey = ABS(dist.y);

		relangle = atan2f(dist.x, dist.z) * 57.295776367188f + angle;

		while (relangle < 180) {
			relangle += 360;
		}

		while (relangle > 180) {
			relangle -= 360;
		}

		if (relangle > 0) {
			// empty
		} else {
			relangle = -relangle;
		}

		osSyncPrintf("HTM : Player %d - Term Pos = (%d,%d,%d)", playernum, (s32)terminalpos->x, (s32)terminalpos->y, (s32)terminalpos->z);
		osSyncPrintf("HTM : Player %d - Play Pos = (%d,%d,%d)", playernum, (s32)chrpos->x, (s32)chrpos->y, (s32)chrpos->z);
		osSyncPrintf("HTM : Player %d - T/P  Rel = (%d,%d,%d)", playernum, (s32)dist.x, (s32)dist.y, (s32)dist.z);

		osSyncPrintf("HTM : Player %d - Range XZ = %d", playernum, rangexz);
		osSyncPrintf("HTM : Player %d - Range Y  = %d", playernum, rangey);
		osSyncPrintf("HTM : Player %d - Angle XZ = %d", playernum, relangle);

		if (rangexz > 250 || rangey > 200 || relangle > 45 || !holdinguplink) {
			if (rangexz < 250 && rangey < 200) {
				data->playernuminrange = playernum;
			} else {
				data->playernuminrange = -1;
			}

			if (chr == NULL) {
				// "Connection broken."
				hudmsgCreateWithFlags(langGet(L_MPWEAPONS_017), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
				func0f0926bc(data->terminals[data->dlterminalnum].prop, 1, 0xffff);
				snd00010718(NULL, 0, 0x7fff, 0x40, SFX_01CC, 1, 1, -1, 1);
			}

			data->dlterminalnum = -1;
			data->dlplayernum = -1;
			*time = 0;
		} else {
			*time += g_Vars.lvupdate240;

			if (*time > 20 * PALDOWN(240)) {
				data->numpoints[playernum]++;
				data->playernuminrange = playernum;

				if (chr == NULL) {
					// "Download successful."
					hudmsgCreateWithFlags(langGet(L_MPWEAPONS_016), HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
					func0f0926bc(data->terminals[data->dlterminalnum].prop, 1, 0xffff);
					snd00010718(NULL, 0, 0x7fff, 0x40, SFX_01C1, 1, 1, -1, 1);
				}

				data->dlterminalnum = -1;
				data->dlplayernum = -1;
				*time = 0;
			}
		}

		osSyncPrintf("HTM : Player %d - Dwnld Plr=%d, Dwnld Prop=%d\n", playernum, data->playernuminrange, data->terminals[data->dlterminalnum].prop);
		osSyncPrintf("HTM : Player %d - Download Time = %d", playernum, *time);
	}
}

const char var7f1b87e4[] = "PopACapReset -> num_mplayers=%d : Working\n";
const char var7f1b8810[] = "PopACapReset -> Generated %d victims for this game : Listing\n";
const char var7f1b8850[] = "PopACapReset -> Victim %d is player %d\n";
const char var7f1b8878[] = "PopACapReset -> Done\n";
const char var7f1b8890[] = "PopACapTick : Current Victim = %d (Player %d)\n";

Gfx *scenarioHtmRenderHud(Gfx *gdl)
{
	struct scenariodata_htm *data = &g_ScenarioData.htm;
	s32 dltime;
	s32 viewleft;
	s32 viewright;
	s32 viewtop;
	s32 a0;
	s32 a1;
	s32 barleft;
	s32 barright;
	s32 t1;
	s32 t6;
	s32 v1;
	s32 s1;

	dltime = data->dltime240[g_Vars.currentplayernum];

	if (data->dlterminalnum != -1 && g_Vars.currentplayernum == data->dlplayernum) {
		viewleft = viGetViewLeft();
		viewright = viGetViewLeft() + viGetViewWidth();
		viewtop = viGetViewTop();
		t6 = (viewleft + viewright) / 2;
		a1 = viGetViewWidth() / 3;
		barleft = t6 - a1 / 2;
		barright = t6 + a1 / 2;
		s1 = barleft + (s32) (a1 * (dltime / PALDOWN(4800.0f)));

		gdl = func0f153628(gdl);
		gdl = gfxSetPrimColour(gdl, 0x60000060);

		gDPFillRectangle(gdl++, barleft, viewtop + 8, barright, viewtop + 16);

		gdl = func0f153838(gdl);
		gdl = gfxSetPrimColour(gdl, 0xc00000d0);

		v1 = barleft + 1;
		a0 = barleft;

		while (v1 < s1) {
			gDPFillRectangle(gdl++, a0, viewtop + 8, v1, viewtop + 16);
			v1 += 2;
			a0 += 2;
		}

		gdl = func0f153838(gdl);
		gdl = func0f153780(gdl);
	}

	return gdl;
}

void scenarioHtmCalculatePlayerScore(struct mpchrconfig *mpchr, s32 mpchrnum, s32 *score, s32 *deaths)
{
	struct mpchrconfig *loopmpchr;
	s32 i;
	s32 index;

	*score = 0;
	index = func0f18d0e8(mpchrnum);

	if (index >= 0) {
		*score += g_ScenarioData.htm.numpoints[index] * 2;
	}

	if (g_MpSetup.options & MPOPTION_KILLSSCORE) {
		for (i = 0; i != MAX_MPCHRS; i++) {
			if (i == mpchrnum) {
				*score -= mpchr->killcounts[i];
			} else if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				if (i < 4) {
					loopmpchr = &g_PlayerConfigsArray[i].base;
				} else {
					loopmpchr = &g_BotConfigsArray[i - 4].base;
				}

				if (loopmpchr->team == mpchr->team) {
					*score -= mpchr->killcounts[i];
				} else {
					*score += mpchr->killcounts[i];
				}
			} else {
				*score += mpchr->killcounts[i];
			}
		}
	}

	*deaths = mpchr->numdeaths;
}

Gfx *scenarioHtmRadar(Gfx *gdl)
{
	struct scenariodata_htm *data = &g_ScenarioData.htm;
	struct coord dist;
	s32 i;
	struct coord sp88;

	// Red/green/blue/alpha as float and integer
	f32 rf;
	f32 gf;
	f32 bf;
	f32 af;

	u32 ri;
	u32 gi;
	u32 bi;
	u32 ai;

	if (g_MpSetup.options & MPOPTION_HTM_SHOWONRADAR) {
		// Show the uplink
		if (data->uplink && data->uplink->type != PROPTYPE_PLAYER && data->uplink->type != PROPTYPE_CHR) {
			dist.x = data->uplink->pos.x - g_Vars.currentplayer->prop->pos.x;
			dist.y = data->uplink->pos.y - g_Vars.currentplayer->prop->pos.y;
			dist.z = data->uplink->pos.z - g_Vars.currentplayer->prop->pos.z;

			gdl = radarDrawDot(gdl, data->uplink, &dist, 0x00ff0000, 0x00000000, true);
		}

		// Show the terminal
		for (i = 0; i < 1; i++) {
			if (data->terminals[i].prop) {
				sp88.x = data->terminals[i].prop->pos.x - g_Vars.currentplayer->prop->pos.x;
				sp88.y = data->terminals[i].prop->pos.y - g_Vars.currentplayer->prop->pos.y;
				sp88.z = data->terminals[i].prop->pos.z - g_Vars.currentplayer->prop->pos.z;

				if (data->terminals[i].team == 255) {
					rf = 0;
					gf = 255;
					bf = 0;
					af = 0;
				} else if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
					u32 colour = g_TeamColours[radarGetTeamIndex(data->terminals[i].team)];
					rf = (colour >> 24) & 0xff;
					gf = ((colour >> 16) & 0xff);
					bf = ((colour >> 8) & 0xff);
					af = colour & 0xff;
				} else {
					rf = 0;
					gf = 255;
					bf = 0;
					af = 0;
				}

				ri = rf;
				gi = gf;
				bi = bf;
				ai = af;

				if (ri > 255) {
					ri = 255;
				}

				if (gi > 255) {
					gi = 255;
				}

				if (bi > 255) {
					bi = 255;
				}

				if (ai > 255) {
					ai = 255;
				}

				gdl = radarDrawDot(gdl, data->terminals[i].prop, &sp88,
						(ri << 24) | (gi << 16) | (bi << 8) | ai,
						0x00000000, true);
			}
		}
	}

	return gdl;
}

bool scenarioHtmRadar2(Gfx **gdl, struct prop *prop)
{
	if ((g_MpSetup.options & MPOPTION_HTM_SHOWONRADAR) && g_ScenarioData.htm.uplink) {
		if (prop == g_ScenarioData.htm.uplink &&
				(prop->type == PROPTYPE_PLAYER || prop->type == PROPTYPE_CHR)) {
			struct coord dist;
			dist.x = prop->pos.x - g_Vars.currentplayer->prop->pos.x;
			dist.y = prop->pos.y - g_Vars.currentplayer->prop->pos.y;
			dist.z = prop->pos.z - g_Vars.currentplayer->prop->pos.z;

			if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				u32 colour = g_TeamColours[radarGetTeamIndex(prop->chr->team)];
				*gdl = radarDrawDot(*gdl, g_ScenarioData.htm.uplink, &dist, colour, 0, 1);
			} else {
				*gdl = radarDrawDot(*gdl, g_ScenarioData.htm.uplink, &dist, 0x00ff0000, 0, 1);
			}

			return true;
		}
	}

	return false;
}

bool scenarioHtmHighlight(struct prop *prop, s32 *colour)
{
	if (g_MpSetup.options & MPOPTION_HTM_HIGHLIGHTTERMINAL) {
		bool highlight = false;

		if (prop == g_ScenarioData.htm.uplink) {
			highlight = true;
		} else {
			s32 i;

			for (i = 0; i < 1; i++) {
				if (g_ScenarioData.htm.terminals[i].prop == prop) {
					highlight = true;
					break;
				}
			}
		}

		if (highlight) {
			colour[0] = 0;
			colour[1] = 0xff;
			colour[2] = 0;
			colour[3] = 0x40;

			return true;
		}
	}

	return false;
}

void scenarioPacChooseVictims(void)
{
	s32 i;
	s32 j;
	struct scenariodata_pac *data = &g_ScenarioData.pac;

	data->victimindex = -1;
	data->age240 = 0;

	for (i = 0; i != MAX_MPCHRS; i++) {
		data->unk20[i] = 0;
		data->wincounts[i] = 0;
	}

	i = 0;

	while (i < g_MpNumChrs) {
		bool isnew;
		s32 victimplayernum = random() % g_MpNumChrs;

		for (j = 0, isnew = true; j < i; j++) {
			if (data->victims[j] == victimplayernum) {
				isnew = false;
				break;
			}
		}

		if (isnew) {
			data->victims[i] = victimplayernum;
			i++;
		}
	}

	for (j = 0; j < g_MpNumChrs; j++) {
		// This loop probably printed debug messages
	}
}

void scenarioPacInit(void)
{
	scenarioPacChooseVictims();
}

void scenarioPacReset(void)
{
	scenarioPacChooseVictims();
}

bool scenarioPacHighlight(struct prop *prop, s32 *colour)
{
	struct scenariodata_pac *data = &g_ScenarioData.pac;

	if (g_MpSetup.options & MPOPTION_PAC_HIGHLIGHTTARGET
			&& (prop->type == PROPTYPE_PLAYER || prop->type == PROPTYPE_CHR)
			&& data->victimindex != -1
			&& prop->chr == g_MpAllChrPtrs[data->victims[data->victimindex]]) {
		colour[0] = 0;
		colour[1] = 0xff;
		colour[2] = 0;
		colour[3] = 0x40;
		return true;
	}

	return false;
}

void scenarioPacApplyNextVictim(void)
{
	struct scenariodata_pac *data = &g_ScenarioData.pac;
	s32 vplayernum;
	char text[64];
	s32 i;

	data->victimindex++;

	if (data->victimindex == g_MpNumChrs) {
		data->victimindex = 0;
	}

	data->age240 = 0;

	vplayernum = data->victims[data->victimindex];

	for (i = 0; i < PLAYERCOUNT(); i++) {
		if (vplayernum == i) {
			sprintf(text, langGet(L_MPWEAPONS_013)); // "You are the victim!"
		} else if (mpChrsAreSameTeam(vplayernum, i)) {
			sprintf(text, langGet(L_MPWEAPONS_014), g_MpAllChrConfigPtrs[vplayernum]->name); // "Protect %s!"
		} else {
			sprintf(text, langGet(L_MPWEAPONS_015), g_MpAllChrConfigPtrs[vplayernum]->name); // "Get %s!"
		}

		mpCreateScenarioHudmsg(i, text);
	}
}

void scenarioPacHandleDeath(s32 aplayernum, s32 vplayernum)
{
	struct scenariodata_pac *data = &g_ScenarioData.pac;

	if (data->victimindex >= 0 && vplayernum == data->victims[data->victimindex]) {
		if (aplayernum != vplayernum) {
			if (aplayernum >= 0) {
				if (mpChrsAreSameTeam(aplayernum, vplayernum)) {
					mpCreateScenarioHudmsg(aplayernum, langGet(L_MPWEAPONS_008)); // "You're supposed to look"
					mpCreateScenarioHudmsg(aplayernum, langGet(L_MPWEAPONS_009)); // "after your friends!"
				} else {
					data->unk20[aplayernum]++;
					mpCreateScenarioHudmsg(aplayernum, langGet(L_MPWEAPONS_010)); // "Well done!"
					mpCreateScenarioHudmsg(aplayernum, langGet(L_MPWEAPONS_011)); // "You popped a cap!"
					mpCreateScenarioHudmsg(aplayernum, langGet(L_MPWEAPONS_012)); // "Have 2 Points..."
				}
			}

			scenarioPacApplyNextVictim();
		} else {
#if VERSION >= VERSION_NTSC_1_0
			data->age240 = 0;
#endif
		}
	}
}

void scenarioPacTick(void)
{
	struct scenariodata_pac *data = &g_ScenarioData.pac;

	if (data->victimindex == -1) {
		scenarioPacApplyNextVictim();
	}

	if (data->victimindex >= 0) {
#if VERSION >= VERSION_NTSC_1_0
		if (data->victims[data->victimindex] >= PLAYERCOUNT() ||
				g_Vars.players[data->victims[data->victimindex]]->isdead == false)
#endif
		{
			data->age240 += g_Vars.lvupdate240;

			if (data->age240 > (u32)PALDOWN(240 * 60)) {
				data->age240 = 0;
				data->wincounts[data->victims[data->victimindex]]++;
				mpCreateScenarioHudmsg(data->victims[data->victimindex], langGet(L_MPWEAPONS_007)); // "Have a point for living!"
			}
		}
	}
}

Gfx *scenarioPacRenderHud(Gfx *gdl)
{
	struct scenariodata_pac *data = &g_ScenarioData.pac;
	s32 time240;
	s32 mins;
	s32 secs;
	s32 textwidth;
	s32 textheight;
	s32 x;
	s32 y;
	char text[64];

#if VERSION >= VERSION_NTSC_1_0
	if (g_Vars.currentplayernum == data->victims[data->victimindex] && !g_Vars.currentplayer->isdead)
#else
	if (g_Vars.currentplayernum == data->victims[data->victimindex])
#endif
	{
		time240 = PALDOWN(60 * 240) - data->age240;
		x = viGetViewLeft() + viGetViewWidth() / 2;
		y = viGetViewTop() + 10;

		if (time240 < 0) {
			time240 = 0;
		}

		mins = time240 / PALDOWN(60 * 240);
		time240 -= PALDOWN(60 * 240) * mins;
		secs = (time240 + (PALDOWN(240) - 1)) / PALDOWN(240);
		sprintf(text, "%d:%02d", mins, secs);

		gdl = func0f153628(gdl);
		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

		x -= textwidth / 2;
		textwidth += x;
		textheight += y;

#if VERSION >= VERSION_NTSC_1_0
		gdl = func0f153990(gdl, x, y, textwidth, textheight);
		gdl = textRender(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, 0x00ff00a0, 0xa0, viGetWidth(), viGetHeight(), 0, 0);
#else
		gdl = func0f153858(gdl, &x, &y, &textwidth, &textheight);
		gdl = textRender(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, 0x00ff00a0, 0x88, viGetWidth(), viGetHeight(), 0, 0);
#endif
		gdl = func0f153780(gdl);
	}

	return gdl;
}

void scenarioPacCalculatePlayerScore(struct mpchrconfig *mpchr, s32 mpchrnum, s32 *score, s32 *arg3)
{
	struct mpchrconfig *loopmpchr;
	s32 i;
	s32 index;

	*score = 0;
	index = func0f18d0e8(mpchrnum);

	if (index >= 0) {
		*score += g_ScenarioData.pac.unk20[index] * 2;
		*score += g_ScenarioData.pac.wincounts[index];
	}

	if (g_MpSetup.options & MPOPTION_KILLSSCORE) {
		for (i = 0; i != MAX_MPCHRS; i++) {
			if (i == mpchrnum) {
				*score -= mpchr->killcounts[i];
			} else if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				if (i < 4) {
					loopmpchr = &g_PlayerConfigsArray[i].base;
				} else {
					loopmpchr = &g_BotConfigsArray[i - 4].base;
				}

				if (loopmpchr->team == mpchr->team) {
					*score -= mpchr->killcounts[i];
				} else {
					*score += mpchr->killcounts[i];
				}
			} else {
				*score += mpchr->killcounts[i];
			}
		}
	}

	*arg3 = mpchr->numdeaths;
}

Gfx *scenarioPacRadar(Gfx *gdl)
{
	return gdl;
}

bool scenarioPacRadar2(Gfx **gdl, struct prop *prop)
{
	struct scenariodata_pac *data = &g_ScenarioData.pac;
	struct coord dist;

	if ((g_MpSetup.options & MPOPTION_PAC_SHOWONRADAR) && data->victimindex >= 0) {
		struct prop *vprop = g_MpAllChrPtrs[data->victims[data->victimindex]]->prop;

		if (vprop == prop) {
			dist.x = prop->pos.x - g_Vars.currentplayer->prop->pos.x;
			dist.y = prop->pos.y - g_Vars.currentplayer->prop->pos.y;
			dist.z = prop->pos.z - g_Vars.currentplayer->prop->pos.z;

			if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				u32 colour = g_TeamColours[radarGetTeamIndex(prop->chr->team)];
				*gdl = radarDrawDot(*gdl, vprop, &dist, colour, 0, 1);
			} else {
				*gdl = radarDrawDot(*gdl, vprop, &dist, 0xff0000, 0, 1);
			}

			return true;
		}
	}

	return false;
}

/**
 * While the options dialog is open, check if another player has changed the
 * scenario to a different one. If so, replace this dialog with the new one.
 */
s32 mpOptionsMenuDialog(s32 operation, struct menudialog *dialog, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if (g_Menus[g_MpPlayerNum].curframe->dialog != g_MpScenarios[g_MpSetup.scenario].optionsdialog) {
			s32 i;
			s32 end = ARRAYCOUNT(g_MpScenarios);

			for (i = 0; i < end; i++) {
				if (g_Menus[g_MpPlayerNum].curframe->dialog == g_MpScenarios[i].optionsdialog) {
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

struct menuitem g_MpPopacapOptionsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_222,  MPOPTION_ONEHITKILLS,         menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU_223,  0x00000000,                   menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_224,  MPOPTION_FASTMOVEMENT,        menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_225,  MPOPTION_DISPLAYTEAM,         menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_226,  MPOPTION_NORADAR,             menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_227,  MPOPTION_NOAUTOAIM,           menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS_493, MPOPTION_KILLSSCORE,          menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                   NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_230,  MPOPTION_PAC_HIGHLIGHTTARGET, menuhandlerMpCheckboxOption }, // "Highlight Target"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU_238,  MPOPTION_PAC_SHOWONRADAR,     menuhandlerMpCheckboxOption }, // "Show on Radar"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                   NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU_239,  0x00000000,                   NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,                   NULL                        },
};

struct menudialog g_MpPopacapOptionsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_218, // "Pop a Cap Options"
	g_MpPopacapOptionsMenuItems,
	mpOptionsMenuDialog,
	0x00000010,
	NULL,
};

struct mpscenario g_MpScenarios[6] = {
	{
		&g_MpCombatOptionsMenuDialog,
	}, {
		&g_MpBriefcaseOptionsMenuDialog,
		scenarioHtbInit,
		scenarioHtbCallback08,
		scenarioHtbReset,
		scenarioHtbTick,
		scenarioHtbCallback14,
		scenarioHtbRenderHud,
		scenarioHtbCalculatePlayerScore,
		scenarioHtbRadar,
		scenarioHtbRadar2,
		scenarioHtbHighlight,
	}, {
		&g_MpHackerOptionsMenuDialog,
		scenarioHtmInit,
		scenarioHtmCallback08,
		scenarioHtmReset,
		scenarioHtmTick,
		scenarioHtmCallback14,
		scenarioHtmRenderHud,
		scenarioHtmCalculatePlayerScore,
		scenarioHtmRadar,
		scenarioHtmRadar2,
		scenarioHtmHighlight,
	}, {
		&g_MpPopacapOptionsMenuDialog,
		scenarioPacInit,
		NULL,
		scenarioPacReset,
		scenarioPacTick,
		NULL,
		scenarioPacRenderHud,
		scenarioPacCalculatePlayerScore,
		scenarioPacRadar,
		scenarioPacRadar2,
		scenarioPacHighlight,
	}, {
		&g_MpHillOptionsMenuDialog,
		scenarioKohInit,
		NULL,
		scenarioKohReset,
		scenarioKohTick,
		NULL,
		scenarioKohRenderHud,
		scenarioKohCalculatePlayerScore,
		scenarioKohRadar,
		NULL,
		NULL,
		NULL,
		NULL,
		scenarioKohIsRoomHighlighted,
		scenarioKohCallback38,
		NULL,
		scenarioKohReadSave,
		scenarioKohWriteSave
	}, {
		&g_MpCaptureOptionsMenuDialog,
		scenarioCtcInit,
		scenarioCtcCallback08,
		scenarioCtcReset,
		scenarioCtcTick,
		scenarioCtcCallback14,
		NULL,
		scenarioCtcCalculatePlayerScore,
		scenarioCtcRadar,
		scenarioCtcRadar2,
		scenarioCtcHighlight,
		scenarioCtcChooseSpawnLocation,
		scenarioCtcGetMaxTeams,
		scenarioCtcIsRoomHighlighted,
		scenarioCtcCallback38,
	},
};

struct mpscenariooverview g_MpScenarioOverviews[] = {
	// Full name, short name, require feature, team only
	{ L_MPMENU_246, L_MPMENU_253, 0, false }, // "Combat", "Combat"
	{ L_MPMENU_247, L_MPMENU_254, MPFEATURE_SCENARIO_HTB, false }, // "Hold the Briefcase", "Briefcase"
	{ L_MPMENU_248, L_MPMENU_255, MPFEATURE_SCENARIO_HTM, false }, // "Hacker Central", "Hacker"
	{ L_MPMENU_249, L_MPMENU_256, MPFEATURE_SCENARIO_PAC, false }, // "Pop a Cap", "Pop"
	{ L_MPMENU_250, L_MPMENU_257, MPFEATURE_SCENARIO_KOH, true }, // "King of the Hill", "Hill"
	{ L_MPMENU_251, L_MPMENU_258, MPFEATURE_SCENARIO_CTC, true }, // "Capture the Case", "Capture"
};

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

void scenarioReadSave(struct savebuffer *buffer)
{
	if (g_MpScenarios[g_MpSetup.scenario].readsavefunc) {
		g_MpScenarios[g_MpSetup.scenario].readsavefunc(buffer);
	} else {
		savebufferReadBits(buffer, 8);
	}
}

void scenarioWriteSave(struct savebuffer *buffer)
{
	if (g_MpScenarios[g_MpSetup.scenario].writesavefunc) {
		g_MpScenarios[g_MpSetup.scenario].writesavefunc(buffer);
	} else {
		savebufferOr(buffer, 0, 8);
	}
}

void scenarioInit(void)
{
	if (g_MpScenarios[g_MpSetup.scenario].initfunc) {
		g_MpScenarios[g_MpSetup.scenario].initfunc();
	}
}

s32 scenarioCallback08(void)
{
	s32 result = 0;

	if (g_MpScenarios[g_MpSetup.scenario].unk08) {
		result = g_MpScenarios[g_MpSetup.scenario].unk08();
	}

	return result;
}

void scenarioReset(void)
{
	if (g_MpScenarios[g_MpSetup.scenario].resetfunc) {
		g_MpScenarios[g_MpSetup.scenario].resetfunc();
	}
}

void mpCreateMatchStartHudmsgs(void)
{
	s32 i;
	s32 prevplayernum = g_Vars.currentplayernum;
	char challengename[60];
	char scenarioname[60];

	if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
		sprintf(challengename, "%s:\n", mpGetChallengeNameBySlot(mpGetCurrentChallengeIndex()));
	}

	sprintf(scenarioname, "%s\n", langGet(g_MpScenarioOverviews[g_MpSetup.scenario].name));

	for (i = 0; i < g_MpNumChrs; i++) {
		if (g_MpAllChrPtrs[i]->aibot == NULL) {
			setCurrentPlayerNum(i);

			if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
				hudmsgCreateWithFlags(challengename, HUDMSGTYPE_DEFAULT, HUDMSGFLAG_ONLYIFALIVE);
			}

			hudmsgCreateWithFlags(scenarioname, HUDMSGTYPE_DEFAULT, HUDMSGFLAG_ONLYIFALIVE);
		}
	}

	setCurrentPlayerNum(prevplayernum);
}

void scenarioTick(void)
{
	if (g_Vars.normmplayerisrunning) {
		if (g_Vars.lvframenum == 5) {
			mpCreateMatchStartHudmsgs();
		}

		if (g_MpScenarios[g_MpSetup.scenario].tickfunc) {
			g_MpScenarios[g_MpSetup.scenario].tickfunc();
		}
	}
}

void scenarioCallback14(struct chrdata *chr)
{
	if (g_Vars.normmplayerisrunning && g_MpScenarios[g_MpSetup.scenario].unk14) {
		g_MpScenarios[g_MpSetup.scenario].unk14(chr);
	}
}

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

void scenarioCalculatePlayerScore(struct mpchrconfig *mpchr, s32 chrnum, s32 *score, s32 *deaths)
{
	struct mpchrconfig *othermpchr;
	s32 i;

	if (g_MpScenarios[g_MpSetup.scenario].calcscorefunc) {
		g_MpScenarios[g_MpSetup.scenario].calcscorefunc(mpchr, chrnum, score, deaths);
	} else {
		*score = 0;

		for (i = 0; i < 12; i++) {
			if (i == chrnum) {
				*score -= mpchr->killcounts[i];
			} else if (g_MpSetup.options & MPOPTION_TEAMSENABLED) {
				if (i < 4) {
					othermpchr = &g_PlayerConfigsArray[i].base;
				} else {
					othermpchr = &g_BotConfigsArray[i - 4].base;
				}

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

Gfx *scenarioRadar(Gfx *gdl)
{
	if (g_Vars.normmplayerisrunning && g_MpScenarios[g_MpSetup.scenario].radarfunc) {
		return g_MpScenarios[g_MpSetup.scenario].radarfunc(gdl);
	}

	return gdl;
}

bool scenarioRadar2(Gfx **gdl, struct prop *prop)
{
	if (g_Vars.normmplayerisrunning && g_MpScenarios[g_MpSetup.scenario].radar2func) {
		return g_MpScenarios[g_MpSetup.scenario].radar2func(gdl, prop);
	}

	return false;
}

bool scenarioHighlight(struct prop *prop, s32 *colour)
{
	if (g_MpScenarios[g_MpSetup.scenario].highlightfunc) {
		if (g_MpScenarios[g_MpSetup.scenario].highlightfunc(prop, colour)) {
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

f32 scenarioChooseSpawnLocation(f32 arg0, struct coord *pos, s16 *rooms, struct prop *prop)
{
	f32 result;

	if (g_Vars.normmplayerisrunning && g_MpScenarios[g_MpSetup.scenario].spawnfunc &&
			g_MpScenarios[g_MpSetup.scenario].spawnfunc(arg0, pos, rooms, prop, &result)) {
		return result;
	}

	return playerChooseGeneralSpawnLocation(arg0, pos, rooms, prop);
}

void mpPrepareScenario(void)
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
		func0f182bf4();
		break;
	case MPSCENARIO_HOLDTHEBRIEFCASE:
		func0f180078();
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
					mpCtcAddPad(cmd);
				} else if (g_MpSetup.scenario == MPSCENARIO_HACKERCENTRAL) {
					mpHtmAddPad(cmd[2]);
				} else if (g_MpSetup.scenario == MPSCENARIO_HOLDTHEBRIEFCASE) {
					mpHtbAddPad(cmd[2]);
				}
				cmd += 3;
				break;
			case INTROCMD_HILL:
				if (g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL) {
					mpKohAddHill(cmd);
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

s32 scenarioGetMaxTeams(void)
{
	if (g_MpScenarios[g_MpSetup.scenario].maxteamsfunc) {
		return g_MpScenarios[g_MpSetup.scenario].maxteamsfunc();
	}

	return MAX_TEAMS;
}

bool scenarioIsRoomHighlighted(s16 room)
{
	if (g_MpScenarios[g_MpSetup.scenario].isroomhighlightedfunc) {
		return g_MpScenarios[g_MpSetup.scenario].isroomhighlightedfunc(room);
	}

	return false;
}

void scenarioCallback38(s16 arg0, s32 *arg1, s32 *arg2, s32 *arg3)
{
	if (g_MpScenarios[g_MpSetup.scenario].unk38) {
		g_MpScenarios[g_MpSetup.scenario].unk38(arg0, arg1, arg2, arg3);
	}
}

struct menuitem g_MpScenarioMenuItems[] = {
	 { MENUITEMTYPE_LIST,        0, 0x00020040, 0x00000078, 0x0000004d, scenarioScenarioMenuHandler },
	 { MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpScenarioMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_243, // "Scenario"
	g_MpScenarioMenuItems,
	NULL,
	0x00000011,
	NULL,
};

struct menuitem g_MpQuickTeamScenarioMenuItems[] = {
	 { MENUITEMTYPE_LIST,        1, 0x00020040, 0x00000078, 0x0000004d, scenarioScenarioMenuHandler },
	 { MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menudialog g_MpQuickTeamScenarioMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_243, // "Scenario"
	g_MpQuickTeamScenarioMenuItems,
	NULL,
	0x00000011,
	NULL,
};

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

void mpCreateScenarioHudmsg(s32 playernum, char *message)
{
	if (playernum >= 0 && playernum < PLAYERCOUNT()) {
		s32 prevplayernum = g_Vars.currentplayernum;

		setCurrentPlayerNum(playernum);
		hudmsgCreateWithFlags(message, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
		setCurrentPlayerNum(prevplayernum);
	}
}

bool mpChrsAreSameTeam(s32 arg0, s32 arg1)
{
	struct mpchrconfig *achr;
	struct mpchrconfig *bchr;

	if ((g_MpSetup.options & MPOPTION_TEAMSENABLED) && arg0 >= 0 && arg1 >= 0) {
		s32 a = func0f18d074(arg0);
		s32 b = func0f18d074(arg1);

		if (a >= 0 && b >= 0) {
			if (a < 4) {
				achr = &g_PlayerConfigsArray[a].base;
			} else {
				achr = &g_BotConfigsArray[a - 4].base;
			}

			if (b < 4) {
				bchr = &g_PlayerConfigsArray[b].base;
			} else {
				bchr = &g_BotConfigsArray[b - 4].base;
			}

			return (achr->team == bchr->team) ? true : false;
		}
	}

	return false;
}

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

#if VERSION >= VERSION_PAL_FINAL
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
				hudmsgCreateWithFlags(text1, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
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

#if VERSION >= VERSION_PAL_FINAL
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

#if VERSION >= VERSION_PAL_FINAL
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

void scenarioReleaseToken(struct chrdata *chr, struct prop *prop)
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

				func0f06a730(obj, &pad, &mtx, rooms, &pad);
			}
		}
	}
}

s32 chrGiveUplink(struct chrdata *chr, struct prop *prop)
{
	s32 i;
	struct mpchrconfig *mpchr;
	char message[60];
	s32 mpindex;
	u32 playernum;

	if (g_MpSetup.scenario == MPSCENARIO_HACKERCENTRAL) {
#if VERSION >= VERSION_NTSC_1_0
		struct defaultobj *obj = prop->obj;
#endif

		g_ScenarioData.htm.uplink = chr->prop;

		if (chr->aibot) {
			mpchr = g_MpAllChrConfigPtrs[mpPlayerGetIndex(chr)];
		} else {
			mpindex = g_Vars.playerstats[g_Vars.currentplayernum].mpindex;

			if (mpindex < 4) {
				mpchr = &g_PlayerConfigsArray[mpindex].base;
			} else {
				mpchr = &g_BotConfigsArray[mpindex - 4].base;
			}
		}

#if PAL
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
				hudmsgCreateWithFlags(message, HUDMSGTYPE_MPSCENARIO, HUDMSGFLAG_ONLYIFALIVE);
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

			return 0;
		} else {
			invGiveSingleWeapon(WEAPON_DATAUPLINK);
			currentPlayerQueuePickupWeaponHudmsg(WEAPON_DATAUPLINK, false);
			weaponPlayPickupSound(WEAPON_DATAUPLINK);

#if VERSION >= VERSION_NTSC_1_0
			objFree(obj, false, obj->hidden2 & OBJH2FLAG_CANREGEN);
			return 1;
#else
			return 4;
#endif

		}
	} else if (chr->aibot) {
		return 0;
	}

	return 0;
}

void scenarioHtmActivateUplink(struct chrdata *chr, struct prop *terminal)
{
	if (g_MpSetup.scenario == MPSCENARIO_HACKERCENTRAL) {
		struct defaultobj *obj = terminal->obj;

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
