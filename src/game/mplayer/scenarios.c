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
	g_ScenarioData.koh.unk30 = 0.25;
	g_ScenarioData.koh.unk34 = 1;
	g_ScenarioData.koh.unk38 = 0.25;

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
	g_ScenarioData.koh.unk08 = 0;
	roomSetLighting(g_ScenarioData.koh.hillrooms[0], LIGHTOP_5, 0, 0, 0);
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel scenarioKohTick
.late_rodata
glabel var7f1b893c
.word 0x3f733333
glabel var7f1b8940
.word 0x3d7487fd
glabel var7f1b8944
.word 0x3f70b780
glabel var7f1b8948
.word 0x3f70b780
glabel var7f1b894c
.word 0x3d7487fd
glabel var7f1b8950
.word 0x3d7487fd
.text
/*  f182cf4:	27bdfe78 */ 	addiu	$sp,$sp,-392
/*  f182cf8:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f182cfc:	3c13800b */ 	lui	$s3,0x800b
/*  f182d00:	2673c6b0 */ 	addiu	$s3,$s3,-14672
/*  f182d04:	866e000a */ 	lh	$t6,0xa($s3)
/*  f182d08:	2401ffff */ 	li	$at,-1
/*  f182d0c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f182d10:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f182d14:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f182d18:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f182d1c:	11c1024f */ 	beq	$t6,$at,.PF0f18365c
/*  f182d20:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f182d24:	866f0008 */ 	lh	$t7,0x8($s3)
/*  f182d28:	00003825 */ 	move	$a3,$zero
/*  f182d2c:	3c013f80 */ 	lui	$at,0x3f80
/*  f182d30:	11e00058 */ 	beqz	$t7,.PF0f182e94
/*  f182d34:	00000000 */ 	nop
/*  f182d38:	44811000 */ 	mtc1	$at,$f2
/*  f182d3c:	3c017f1c */ 	lui	$at,0x7f1c
/*  f182d40:	c42c9f8c */ 	lwc1	$f12,-0x6074($at)
/*  f182d44:	c6600030 */ 	lwc1	$f0,0x30($s3)
/*  f182d48:	2418ffff */ 	li	$t8,-1
/*  f182d4c:	a6780004 */ 	sh	$t8,0x4($s3)
/*  f182d50:	4600603e */ 	c.le.s	$f12,$f0
/*  f182d54:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f182d58:	e7a20164 */ 	swc1	$f2,0x164($sp)
/*  f182d5c:	e7a20160 */ 	swc1	$f2,0x160($sp)
/*  f182d60:	45000047 */ 	bc1f	.PF0f182e80
/*  f182d64:	e7a2015c */ 	swc1	$f2,0x15c($sp)
/*  f182d68:	c6640034 */ 	lwc1	$f4,0x34($s3)
/*  f182d6c:	4604603e */ 	c.le.s	$f12,$f4
/*  f182d70:	00000000 */ 	nop
/*  f182d74:	45000042 */ 	bc1f	.PF0f182e80
/*  f182d78:	00000000 */ 	nop
/*  f182d7c:	c6660038 */ 	lwc1	$f6,0x38($s3)
/*  f182d80:	00002825 */ 	move	$a1,$zero
/*  f182d84:	00003025 */ 	move	$a2,$zero
/*  f182d88:	4606603e */ 	c.le.s	$f12,$f6
/*  f182d8c:	00003825 */ 	move	$a3,$zero
/*  f182d90:	4500003b */ 	bc1f	.PF0f182e80
/*  f182d94:	00000000 */ 	nop
/*  f182d98:	8664000e */ 	lh	$a0,0xe($s3)
/*  f182d9c:	0fc00b0a */ 	jal	roomSetLighting
/*  f182da0:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f182da4:	8679000c */ 	lh	$t9,0xc($s3)
/*  f182da8:	00002025 */ 	move	$a0,$zero
/*  f182dac:	2b210002 */ 	slti	$at,$t9,0x2
/*  f182db0:	54200013 */ 	bnezl	$at,.PF0f182e00
/*  f182db4:	a660000a */ 	sh	$zero,0xa($s3)
/*  f182db8:	8670000a */ 	lh	$s0,0xa($s3)
.PF0f182dbc:
/*  f182dbc:	0c004ad4 */ 	jal	random
/*  f182dc0:	00000000 */ 	nop
/*  f182dc4:	8668000c */ 	lh	$t0,0xc($s3)
/*  f182dc8:	0048001b */ 	divu	$zero,$v0,$t0
/*  f182dcc:	00004810 */ 	mfhi	$t1
/*  f182dd0:	a669000a */ 	sh	$t1,0xa($s3)
/*  f182dd4:	8663000a */ 	lh	$v1,0xa($s3)
/*  f182dd8:	15000002 */ 	bnez	$t0,.PF0f182de4
/*  f182ddc:	00000000 */ 	nop
/*  f182de0:	0007000d */ 	break	0x7
.PF0f182de4:
/*  f182de4:	1203fff5 */ 	beq	$s0,$v1,.PF0f182dbc
/*  f182de8:	00000000 */ 	nop
/*  f182dec:	00035040 */ 	sll	$t2,$v1,0x1
/*  f182df0:	026a5821 */ 	addu	$t3,$s3,$t2
/*  f182df4:	10000002 */ 	b	.PF0f182e00
/*  f182df8:	85640012 */ 	lh	$a0,0x12($t3)
/*  f182dfc:	a660000a */ 	sh	$zero,0xa($s3)
.PF0f182e00:
/*  f182e00:	24050042 */ 	li	$a1,0x42
/*  f182e04:	0fc45964 */ 	jal	padUnpack
/*  f182e08:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f182e0c:	8fac00f0 */ 	lw	$t4,0xf0($sp)
/*  f182e10:	c7a800a8 */ 	lwc1	$f8,0xa8($sp)
/*  f182e14:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*  f182e18:	c7b200b0 */ 	lwc1	$f18,0xb0($sp)
/*  f182e1c:	240dffff */ 	li	$t5,-1
/*  f182e20:	3c04800b */ 	lui	$a0,0x800b
/*  f182e24:	3c05800b */ 	lui	$a1,0x800b
/*  f182e28:	a66d0010 */ 	sh	$t5,0x10($s3)
/*  f182e2c:	24a5c6be */ 	addiu	$a1,$a1,-14658
/*  f182e30:	2484c6d4 */ 	addiu	$a0,$a0,-14636
/*  f182e34:	00003025 */ 	move	$a2,$zero
/*  f182e38:	00003825 */ 	move	$a3,$zero
/*  f182e3c:	a66c000e */ 	sh	$t4,0xe($s3)
/*  f182e40:	e6680024 */ 	swc1	$f8,0x24($s3)
/*  f182e44:	e66a0028 */ 	swc1	$f10,0x28($s3)
/*  f182e48:	0c00a71b */ 	jal	cd0002a36c
/*  f182e4c:	e672002c */ 	swc1	$f18,0x2c($s3)
/*  f182e50:	e6600028 */ 	swc1	$f0,0x28($s3)
/*  f182e54:	8664000e */ 	lh	$a0,0xe($s3)
/*  f182e58:	24050005 */ 	li	$a1,0x5
/*  f182e5c:	00003025 */ 	move	$a2,$zero
/*  f182e60:	00003825 */ 	move	$a3,$zero
/*  f182e64:	0fc00b0a */ 	jal	roomSetLighting
/*  f182e68:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f182e6c:	240effff */ 	li	$t6,-1
/*  f182e70:	a66e0004 */ 	sh	$t6,0x4($s3)
/*  f182e74:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f182e78:	a6600008 */ 	sh	$zero,0x8($s3)
/*  f182e7c:	c6600030 */ 	lwc1	$f0,0x30($s3)
.PF0f182e80:
/*  f182e80:	3c14800a */ 	lui	$s4,0x800a
/*  f182e84:	2694a510 */ 	addiu	$s4,$s4,-23280
/*  f182e88:	c66c0034 */ 	lwc1	$f12,0x34($s3)
/*  f182e8c:	10000198 */ 	b	.PF0f1834f0
/*  f182e90:	c6700038 */ 	lwc1	$f16,0x38($s3)
.PF0f182e94:
/*  f182e94:	3c14800a */ 	lui	$s4,0x800a
/*  f182e98:	2694a510 */ 	addiu	$s4,$s4,-23280
/*  f182e9c:	8e83033c */ 	lw	$v1,0x33c($s4)
/*  f182ea0:	00003025 */ 	move	$a2,$zero
/*  f182ea4:	24120003 */ 	li	$s2,0x3
/*  f182ea8:	1060001e */ 	beqz	$v1,.PF0f182f24
/*  f182eac:	24100006 */ 	li	$s0,0x6
/*  f182eb0:	90620000 */ 	lbu	$v0,0x0($v1)
.PF0f182eb4:
/*  f182eb4:	52020004 */ 	beql	$s0,$v0,.PF0f182ec8
/*  f182eb8:	846f0028 */ 	lh	$t7,0x28($v1)
/*  f182ebc:	56420017 */ 	bnel	$s2,$v0,.PF0f182f1c
/*  f182ec0:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f182ec4:	846f0028 */ 	lh	$t7,0x28($v1)
.PF0f182ec8:
/*  f182ec8:	8678000e */ 	lh	$t8,0xe($s3)
/*  f182ecc:	00008825 */ 	move	$s1,$zero
/*  f182ed0:	15f80002 */ 	bne	$t7,$t8,.PF0f182edc
/*  f182ed4:	00000000 */ 	nop
/*  f182ed8:	24110001 */ 	li	$s1,0x1
.PF0f182edc:
/*  f182edc:	5220000f */ 	beqzl	$s1,.PF0f182f1c
/*  f182ee0:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f182ee4:	8c640004 */ 	lw	$a0,0x4($v1)
/*  f182ee8:	afa70170 */ 	sw	$a3,0x170($sp)
/*  f182eec:	afa60174 */ 	sw	$a2,0x174($sp)
/*  f182ef0:	0fc0e706 */ 	jal	chrIsDead
/*  f182ef4:	afa30074 */ 	sw	$v1,0x74($sp)
/*  f182ef8:	8fa30074 */ 	lw	$v1,0x74($sp)
/*  f182efc:	8fa60174 */ 	lw	$a2,0x174($sp)
/*  f182f00:	14400005 */ 	bnez	$v0,.PF0f182f18
/*  f182f04:	8fa70170 */ 	lw	$a3,0x170($sp)
/*  f182f08:	0006c880 */ 	sll	$t9,$a2,0x2
/*  f182f0c:	03b94021 */ 	addu	$t0,$sp,$t9
/*  f182f10:	ad030078 */ 	sw	$v1,0x78($t0)
/*  f182f14:	24c60001 */ 	addiu	$a2,$a2,0x1
.PF0f182f18:
/*  f182f18:	8c630020 */ 	lw	$v1,0x20($v1)
.PF0f182f1c:
/*  f182f1c:	5460ffe5 */ 	bnezl	$v1,.PF0f182eb4
/*  f182f20:	90620000 */ 	lbu	$v0,0x0($v1)
.PF0f182f24:
/*  f182f24:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f182f28:	27a3011c */ 	addiu	$v1,$sp,0x11c
.PF0f182f2c:
/*  f182f2c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f182f30:	0043082b */ 	sltu	$at,$v0,$v1
/*  f182f34:	1420fffd */ 	bnez	$at,.PF0f182f2c
/*  f182f38:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f182f3c:	00008025 */ 	move	$s0,$zero
/*  f182f40:	18c00017 */ 	blez	$a2,.PF0f182fa0
/*  f182f44:	00009025 */ 	move	$s2,$zero
/*  f182f48:	27a30078 */ 	addiu	$v1,$sp,0x78
/*  f182f4c:	27b100fc */ 	addiu	$s1,$sp,0xfc
.PF0f182f50:
/*  f182f50:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f182f54:	8d250004 */ 	lw	$a1,0x4($t1)
/*  f182f58:	90a40125 */ 	lbu	$a0,0x125($a1)
/*  f182f5c:	afa70170 */ 	sw	$a3,0x170($sp)
/*  f182f60:	afa60174 */ 	sw	$a2,0x174($sp)
/*  f182f64:	0fc63e8e */ 	jal	radarGetTeamIndex
/*  f182f68:	afa30050 */ 	sw	$v1,0x50($sp)
/*  f182f6c:	00025080 */ 	sll	$t2,$v0,0x2
/*  f182f70:	022a2021 */ 	addu	$a0,$s1,$t2
/*  f182f74:	8c8b0000 */ 	lw	$t3,0x0($a0)
/*  f182f78:	8fa30050 */ 	lw	$v1,0x50($sp)
/*  f182f7c:	8fa60174 */ 	lw	$a2,0x174($sp)
/*  f182f80:	15600004 */ 	bnez	$t3,.PF0f182f94
/*  f182f84:	8fa70170 */ 	lw	$a3,0x170($sp)
/*  f182f88:	240c0001 */ 	li	$t4,0x1
/*  f182f8c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f182f90:	ac8c0000 */ 	sw	$t4,0x0($a0)
.PF0f182f94:
/*  f182f94:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f182f98:	1606ffed */ 	bne	$s0,$a2,.PF0f182f50
/*  f182f9c:	24630004 */ 	addiu	$v1,$v1,0x4
.PF0f182fa0:
/*  f182fa0:	16400005 */ 	bnez	$s2,.PF0f182fb8
/*  f182fa4:	24010001 */ 	li	$at,0x1
/*  f182fa8:	240dffff */ 	li	$t5,-1
/*  f182fac:	a66d0004 */ 	sh	$t5,0x4($s3)
/*  f182fb0:	10000122 */ 	b	.PF0f18343c
/*  f182fb4:	a6600006 */ 	sh	$zero,0x6($s3)
.PF0f182fb8:
/*  f182fb8:	1641000b */ 	bne	$s2,$at,.PF0f182fe8
/*  f182fbc:	00008025 */ 	move	$s0,$zero
/*  f182fc0:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f182fc4:	24030008 */ 	li	$v1,0x8
.PF0f182fc8:
/*  f182fc8:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f182fcc:	55c0003d */ 	bnezl	$t6,.PF0f1830c4
/*  f182fd0:	866a0004 */ 	lh	$t2,0x4($s3)
/*  f182fd4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f182fd8:	1603fffb */ 	bne	$s0,$v1,.PF0f182fc8
/*  f182fdc:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f182fe0:	10000038 */ 	b	.PF0f1830c4
/*  f182fe4:	866a0004 */ 	lh	$t2,0x4($s3)
.PF0f182fe8:
/*  f182fe8:	00008825 */ 	move	$s1,$zero
/*  f182fec:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f182ff0:	27a4011c */ 	addiu	$a0,$sp,0x11c
/*  f182ff4:	8c430000 */ 	lw	$v1,0x0($v0)
.PF0f182ff8:
/*  f182ff8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f182ffc:	0223082a */ 	slt	$at,$s1,$v1
/*  f183000:	50200003 */ 	beqzl	$at,.PF0f183010
/*  f183004:	0044082b */ 	sltu	$at,$v0,$a0
/*  f183008:	00608825 */ 	move	$s1,$v1
/*  f18300c:	0044082b */ 	sltu	$at,$v0,$a0
.PF0f183010:
/*  f183010:	5420fff9 */ 	bnezl	$at,.PF0f182ff8
/*  f183014:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f183018:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f18301c:	27a3011c */ 	addiu	$v1,$sp,0x11c
/*  f183020:	8c4f0000 */ 	lw	$t7,0x0($v0)
.PF0f183024:
/*  f183024:	522f0003 */ 	beql	$s1,$t7,.PF0f183034
/*  f183028:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18302c:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f183030:	24420004 */ 	addiu	$v0,$v0,0x4
.PF0f183034:
/*  f183034:	0043082b */ 	sltu	$at,$v0,$v1
/*  f183038:	5420fffa */ 	bnezl	$at,.PF0f183024
/*  f18303c:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f183040:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f183044:	27a3011c */ 	addiu	$v1,$sp,0x11c
/*  f183048:	8c580000 */ 	lw	$t8,0x0($v0)
.PF0f18304c:
/*  f18304c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f183050:	0043082b */ 	sltu	$at,$v0,$v1
/*  f183054:	13000002 */ 	beqz	$t8,.PF0f183060
/*  f183058:	00000000 */ 	nop
/*  f18305c:	24e70001 */ 	addiu	$a3,$a3,0x1
.PF0f183060:
/*  f183060:	5420fffa */ 	bnezl	$at,.PF0f18304c
/*  f183064:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f183068:	28e10002 */ 	slti	$at,$a3,0x2
/*  f18306c:	14200003 */ 	bnez	$at,.PF0f18307c
/*  f183070:	00008025 */ 	move	$s0,$zero
/*  f183074:	10000002 */ 	b	.PF0f183080
/*  f183078:	24070001 */ 	li	$a3,0x1
.PF0f18307c:
/*  f18307c:	00003825 */ 	move	$a3,$zero
.PF0f183080:
/*  f183080:	27a200fc */ 	addiu	$v0,$sp,0xfc
.PF0f183084:
/*  f183084:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f183088:	53200005 */ 	beqzl	$t9,.PF0f1830a0
/*  f18308c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f183090:	86680004 */ 	lh	$t0,0x4($s3)
/*  f183094:	52080006 */ 	beql	$s0,$t0,.PF0f1830b0
/*  f183098:	24030008 */ 	li	$v1,0x8
/*  f18309c:	26100001 */ 	addiu	$s0,$s0,0x1
.PF0f1830a0:
/*  f1830a0:	2a010008 */ 	slti	$at,$s0,0x8
/*  f1830a4:	1420fff7 */ 	bnez	$at,.PF0f183084
/*  f1830a8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1830ac:	24030008 */ 	li	$v1,0x8
.PF0f1830b0:
/*  f1830b0:	16030003 */ 	bne	$s0,$v1,.PF0f1830c0
/*  f1830b4:	2409ffff */ 	li	$t1,-1
/*  f1830b8:	a6690004 */ 	sh	$t1,0x4($s3)
/*  f1830bc:	2410ffff */ 	li	$s0,-1
.PF0f1830c0:
/*  f1830c0:	866a0004 */ 	lh	$t2,0x4($s3)
.PF0f1830c4:
/*  f1830c4:	3c048009 */ 	lui	$a0,0x8009
/*  f1830c8:	240505b9 */ 	li	$a1,0x5b9
/*  f1830cc:	120a0070 */ 	beq	$s0,$t2,.PF0f183290
/*  f1830d0:	00003025 */ 	move	$a2,$zero
/*  f1830d4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1830d8:	44812000 */ 	mtc1	$at,$f4
/*  f1830dc:	240bffff */ 	li	$t3,-1
/*  f1830e0:	240cffff */ 	li	$t4,-1
/*  f1830e4:	240dffff */ 	li	$t5,-1
/*  f1830e8:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f1830ec:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f1830f0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f1830f4:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f1830f8:	2407ffff */ 	li	$a3,-1
/*  f1830fc:	00008825 */ 	move	$s1,$zero
/*  f183100:	0c0041a0 */ 	jal	sndStart
/*  f183104:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f183108:	a6700004 */ 	sh	$s0,0x4($s3)
/*  f18310c:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f183110:	0fc5bdaa */ 	jal	langGet
/*  f183114:	24045417 */ 	li	$a0,0x5417
/*  f183118:	00107080 */ 	sll	$t6,$s0,0x2
/*  f18311c:	01d07023 */ 	subu	$t6,$t6,$s0
/*  f183120:	3c0f800b */ 	lui	$t7,0x800b
/*  f183124:	25efd150 */ 	addiu	$t7,$t7,-11952
/*  f183128:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f18312c:	01cf3021 */ 	addu	$a2,$t6,$t7
/*  f183130:	27a4011c */ 	addiu	$a0,$sp,0x11c
/*  f183134:	0c004d11 */ 	jal	sprintf
/*  f183138:	00402825 */ 	move	$a1,$v0
/*  f18313c:	8e98006c */ 	lw	$t8,0x6c($s4)
/*  f183140:	27b0011c */ 	addiu	$s0,$sp,0x11c
/*  f183144:	8e92028c */ 	lw	$s2,0x28c($s4)
/*  f183148:	13000003 */ 	beqz	$t8,.PF0f183158
/*  f18314c:	00002825 */ 	move	$a1,$zero
/*  f183150:	10000001 */ 	b	.PF0f183158
/*  f183154:	24050001 */ 	li	$a1,0x1
.PF0f183158:
/*  f183158:	8e990068 */ 	lw	$t9,0x68($s4)
/*  f18315c:	00002025 */ 	move	$a0,$zero
/*  f183160:	00001825 */ 	move	$v1,$zero
/*  f183164:	13200003 */ 	beqz	$t9,.PF0f183174
/*  f183168:	00001025 */ 	move	$v0,$zero
/*  f18316c:	10000001 */ 	b	.PF0f183174
/*  f183170:	24040001 */ 	li	$a0,0x1
.PF0f183174:
/*  f183174:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f183178:	11000003 */ 	beqz	$t0,.PF0f183188
/*  f18317c:	00000000 */ 	nop
/*  f183180:	10000001 */ 	b	.PF0f183188
/*  f183184:	24030001 */ 	li	$v1,0x1
.PF0f183188:
/*  f183188:	8e890070 */ 	lw	$t1,0x70($s4)
/*  f18318c:	11200003 */ 	beqz	$t1,.PF0f18319c
/*  f183190:	00000000 */ 	nop
/*  f183194:	10000001 */ 	b	.PF0f18319c
/*  f183198:	24020001 */ 	li	$v0,0x1
.PF0f18319c:
/*  f18319c:	00435021 */ 	addu	$t2,$v0,$v1
/*  f1831a0:	01445821 */ 	addu	$t3,$t2,$a0
/*  f1831a4:	01656021 */ 	addu	$t4,$t3,$a1
/*  f1831a8:	19800035 */ 	blez	$t4,.PF0f183280
/*  f1831ac:	00000000 */ 	nop
.PF0f1831b0:
/*  f1831b0:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f1831b4:	02202025 */ 	move	$a0,$s1
/*  f1831b8:	8e8d0284 */ 	lw	$t5,0x284($s4)
/*  f1831bc:	8dae00bc */ 	lw	$t6,0xbc($t5)
/*  f1831c0:	8dc50004 */ 	lw	$a1,0x4($t6)
/*  f1831c4:	0fc63e8e */ 	jal	radarGetTeamIndex
/*  f1831c8:	90a40125 */ 	lbu	$a0,0x125($a1)
/*  f1831cc:	866f0004 */ 	lh	$t7,0x4($s3)
/*  f1831d0:	02002025 */ 	move	$a0,$s0
/*  f1831d4:	24050009 */ 	li	$a1,0x9
/*  f1831d8:	144f0009 */ 	bne	$v0,$t7,.PF0f183200
/*  f1831dc:	00000000 */ 	nop
/*  f1831e0:	0fc5bdaa */ 	jal	langGet
/*  f1831e4:	24045416 */ 	li	$a0,0x5416
/*  f1831e8:	00402025 */ 	move	$a0,$v0
/*  f1831ec:	24050009 */ 	li	$a1,0x9
/*  f1831f0:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f1831f4:	24060001 */ 	li	$a2,0x1
/*  f1831f8:	10000004 */ 	b	.PF0f18320c
/*  f1831fc:	8e98006c */ 	lw	$t8,0x6c($s4)
.PF0f183200:
/*  f183200:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f183204:	24060001 */ 	li	$a2,0x1
/*  f183208:	8e98006c */ 	lw	$t8,0x6c($s4)
.PF0f18320c:
/*  f18320c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f183210:	00002825 */ 	move	$a1,$zero
/*  f183214:	13000003 */ 	beqz	$t8,.PF0f183224
/*  f183218:	00002025 */ 	move	$a0,$zero
/*  f18321c:	10000001 */ 	b	.PF0f183224
/*  f183220:	24050001 */ 	li	$a1,0x1
.PF0f183224:
/*  f183224:	8e990068 */ 	lw	$t9,0x68($s4)
/*  f183228:	00001825 */ 	move	$v1,$zero
/*  f18322c:	00001025 */ 	move	$v0,$zero
/*  f183230:	13200003 */ 	beqz	$t9,.PF0f183240
/*  f183234:	00000000 */ 	nop
/*  f183238:	10000001 */ 	b	.PF0f183240
/*  f18323c:	24040001 */ 	li	$a0,0x1
.PF0f183240:
/*  f183240:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f183244:	11000003 */ 	beqz	$t0,.PF0f183254
/*  f183248:	00000000 */ 	nop
/*  f18324c:	10000001 */ 	b	.PF0f183254
/*  f183250:	24030001 */ 	li	$v1,0x1
.PF0f183254:
/*  f183254:	8e890070 */ 	lw	$t1,0x70($s4)
/*  f183258:	11200003 */ 	beqz	$t1,.PF0f183268
/*  f18325c:	00000000 */ 	nop
/*  f183260:	10000001 */ 	b	.PF0f183268
/*  f183264:	24020001 */ 	li	$v0,0x1
.PF0f183268:
/*  f183268:	00435021 */ 	addu	$t2,$v0,$v1
/*  f18326c:	01445821 */ 	addu	$t3,$t2,$a0
/*  f183270:	01656021 */ 	addu	$t4,$t3,$a1
/*  f183274:	022c082a */ 	slt	$at,$s1,$t4
/*  f183278:	1420ffcd */ 	bnez	$at,.PF0f1831b0
/*  f18327c:	00000000 */ 	nop
.PF0f183280:
/*  f183280:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f183284:	02402025 */ 	move	$a0,$s2
/*  f183288:	1000006d */ 	b	.PF0f183440
/*  f18328c:	86630004 */ 	lh	$v1,0x4($s3)
.PF0f183290:
/*  f183290:	54e0006b */ 	bnezl	$a3,.PF0f183440
/*  f183294:	86630004 */ 	lh	$v1,0x4($s3)
/*  f183298:	8e990484 */ 	lw	$t9,0x484($s4)
/*  f18329c:	866d0006 */ 	lh	$t5,0x6($s3)
/*  f1832a0:	8e8e0034 */ 	lw	$t6,0x34($s4)
/*  f1832a4:	00194080 */ 	sll	$t0,$t9,0x2
/*  f1832a8:	01194023 */ 	subu	$t0,$t0,$t9
/*  f1832ac:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f1832b0:	a66f0006 */ 	sh	$t7,0x6($s3)
/*  f1832b4:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f1832b8:	86780006 */ 	lh	$t8,0x6($s3)
/*  f1832bc:	01194021 */ 	addu	$t0,$t0,$t9
/*  f1832c0:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f1832c4:	250907d0 */ 	addiu	$t1,$t0,0x7d0
/*  f1832c8:	0309082a */ 	slt	$at,$t8,$t1
/*  f1832cc:	1420005b */ 	bnez	$at,.PF0f18343c
/*  f1832d0:	3c048009 */ 	lui	$a0,0x8009
/*  f1832d4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1832d8:	44813000 */ 	mtc1	$at,$f6
/*  f1832dc:	240affff */ 	li	$t2,-1
/*  f1832e0:	240bffff */ 	li	$t3,-1
/*  f1832e4:	240cffff */ 	li	$t4,-1
/*  f1832e8:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f1832ec:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f1832f0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f1832f4:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f1832f8:	240505b8 */ 	li	$a1,0x5b8
/*  f1832fc:	00003025 */ 	move	$a2,$zero
/*  f183300:	2407ffff */ 	li	$a3,-1
/*  f183304:	00009025 */ 	move	$s2,$zero
/*  f183308:	0c0041a0 */ 	jal	sndStart
/*  f18330c:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f183310:	3c03800b */ 	lui	$v1,0x800b
/*  f183314:	8c63cad0 */ 	lw	$v1,-0x3530($v1)
/*  f183318:	3c10800b */ 	lui	$s0,0x800b
/*  f18331c:	2610ca70 */ 	addiu	$s0,$s0,-13712
/*  f183320:	1860001e */ 	blez	$v1,.PF0f18339c
/*  f183324:	00002825 */ 	move	$a1,$zero
/*  f183328:	3c11800b */ 	lui	$s1,0x800b
/*  f18332c:	2631caa0 */ 	addiu	$s1,$s1,-13664
.PF0f183330:
/*  f183330:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f183334:	91a40125 */ 	lbu	$a0,0x125($t5)
/*  f183338:	0fc63e8e */ 	jal	radarGetTeamIndex
/*  f18333c:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f183340:	866e0004 */ 	lh	$t6,0x4($s3)
/*  f183344:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f183348:	144e000c */ 	bne	$v0,$t6,.PF0f18337c
/*  f18334c:	00000000 */ 	nop
/*  f183350:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f183354:	8668000e */ 	lh	$t0,0xe($s3)
/*  f183358:	0225c021 */ 	addu	$t8,$s1,$a1
/*  f18335c:	8de3001c */ 	lw	$v1,0x1c($t7)
/*  f183360:	84790028 */ 	lh	$t9,0x28($v1)
/*  f183364:	17280005 */ 	bne	$t9,$t0,.PF0f18337c
/*  f183368:	00000000 */ 	nop
/*  f18336c:	8f020000 */ 	lw	$v0,0x0($t8)
/*  f183370:	8449003e */ 	lh	$t1,0x3e($v0)
/*  f183374:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f183378:	a44a003e */ 	sh	$t2,0x3e($v0)
.PF0f18337c:
/*  f18337c:	3c03800b */ 	lui	$v1,0x800b
/*  f183380:	8c63cad0 */ 	lw	$v1,-0x3530($v1)
/*  f183384:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f183388:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f18338c:	0243082a */ 	slt	$at,$s2,$v1
/*  f183390:	1420ffe7 */ 	bnez	$at,.PF0f183330
/*  f183394:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f183398:	00009025 */ 	move	$s2,$zero
.PF0f18339c:
/*  f18339c:	1860001b */ 	blez	$v1,.PF0f18340c
/*  f1833a0:	8e91028c */ 	lw	$s1,0x28c($s4)
/*  f1833a4:	3c10800b */ 	lui	$s0,0x800b
/*  f1833a8:	2610ca70 */ 	addiu	$s0,$s0,-13712
/*  f1833ac:	8e020000 */ 	lw	$v0,0x0($s0)
.PF0f1833b0:
/*  f1833b0:	8c4b02d4 */ 	lw	$t3,0x2d4($v0)
/*  f1833b4:	1560000e */ 	bnez	$t3,.PF0f1833f0
/*  f1833b8:	00000000 */ 	nop
/*  f1833bc:	0fc63e8e */ 	jal	radarGetTeamIndex
/*  f1833c0:	90440125 */ 	lbu	$a0,0x125($v0)
/*  f1833c4:	866c0004 */ 	lh	$t4,0x4($s3)
/*  f1833c8:	144c0009 */ 	bne	$v0,$t4,.PF0f1833f0
/*  f1833cc:	00000000 */ 	nop
/*  f1833d0:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f1833d4:	02402025 */ 	move	$a0,$s2
/*  f1833d8:	0fc5bdaa */ 	jal	langGet
/*  f1833dc:	24045415 */ 	li	$a0,0x5415
/*  f1833e0:	00402025 */ 	move	$a0,$v0
/*  f1833e4:	24050009 */ 	li	$a1,0x9
/*  f1833e8:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f1833ec:	24060001 */ 	li	$a2,0x1
.PF0f1833f0:
/*  f1833f0:	3c0d800b */ 	lui	$t5,0x800b
/*  f1833f4:	8dadcad0 */ 	lw	$t5,-0x3530($t5)
/*  f1833f8:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1833fc:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f183400:	024d082a */ 	slt	$at,$s2,$t5
/*  f183404:	5420ffea */ 	bnezl	$at,.PF0f1833b0
/*  f183408:	8e020000 */ 	lw	$v0,0x0($s0)
.PF0f18340c:
/*  f18340c:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f183410:	02202025 */ 	move	$a0,$s1
/*  f183414:	240effff */ 	li	$t6,-1
/*  f183418:	a66e0004 */ 	sh	$t6,0x4($s3)
/*  f18341c:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f183420:	3c0f800b */ 	lui	$t7,0x800b
/*  f183424:	8defd134 */ 	lw	$t7,-0x2ecc($t7)
/*  f183428:	24080001 */ 	li	$t0,0x1
/*  f18342c:	31f98000 */ 	andi	$t9,$t7,0x8000
/*  f183430:	53200003 */ 	beqzl	$t9,.PF0f183440
/*  f183434:	86630004 */ 	lh	$v1,0x4($s3)
/*  f183438:	a6680008 */ 	sh	$t0,0x8($s3)
.PF0f18343c:
/*  f18343c:	86630004 */ 	lh	$v1,0x4($s3)
.PF0f183440:
/*  f183440:	2401ffff */ 	li	$at,-1
/*  f183444:	3c028009 */ 	lui	$v0,0x8009
/*  f183448:	1461000c */ 	bne	$v1,$at,.PF0f18347c
/*  f18344c:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f183450:	3c013f80 */ 	lui	$at,0x3f80
/*  f183454:	44811000 */ 	mtc1	$at,$f2
/*  f183458:	3c013e80 */ 	lui	$at,0x3e80
/*  f18345c:	44817000 */ 	mtc1	$at,$f14
/*  f183460:	c6600030 */ 	lwc1	$f0,0x30($s3)
/*  f183464:	c66c0034 */ 	lwc1	$f12,0x34($s3)
/*  f183468:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f18346c:	e7a20160 */ 	swc1	$f2,0x160($sp)
/*  f183470:	e7ae0164 */ 	swc1	$f14,0x164($sp)
/*  f183474:	1000001e */ 	b	.PF0f1834f0
/*  f183478:	e7ae015c */ 	swc1	$f14,0x15c($sp)
.PF0f18347c:
/*  f18347c:	00581021 */ 	addu	$v0,$v0,$t8
/*  f183480:	8c428214 */ 	lw	$v0,-0x7dec($v0)
/*  f183484:	3c013b00 */ 	lui	$at,0x3b00
/*  f183488:	44811000 */ 	mtc1	$at,$f2
/*  f18348c:	00024e02 */ 	srl	$t1,$v0,0x18
/*  f183490:	312a00ff */ 	andi	$t2,$t1,0xff
/*  f183494:	254b00ff */ 	addiu	$t3,$t2,0xff
/*  f183498:	448b4000 */ 	mtc1	$t3,$f8
/*  f18349c:	00026402 */ 	srl	$t4,$v0,0x10
/*  f1834a0:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f1834a4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f1834a8:	25ae00ff */ 	addiu	$t6,$t5,0xff
/*  f1834ac:	448e2000 */ 	mtc1	$t6,$f4
/*  f1834b0:	00027a02 */ 	srl	$t7,$v0,0x8
/*  f1834b4:	31f900ff */ 	andi	$t9,$t7,0xff
/*  f1834b8:	272800ff */ 	addiu	$t0,$t9,0xff
/*  f1834bc:	46025482 */ 	mul.s	$f18,$f10,$f2
/*  f1834c0:	44885000 */ 	mtc1	$t0,$f10
/*  f1834c4:	c6600030 */ 	lwc1	$f0,0x30($s3)
/*  f1834c8:	c66c0034 */ 	lwc1	$f12,0x34($s3)
/*  f1834cc:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f1834d0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1834d4:	e7b20164 */ 	swc1	$f18,0x164($sp)
/*  f1834d8:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f1834dc:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f1834e0:	00000000 */ 	nop
/*  f1834e4:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f1834e8:	e7a80160 */ 	swc1	$f8,0x160($sp)
/*  f1834ec:	e7a4015c */ 	swc1	$f4,0x15c($sp)
.PF0f1834f0:
/*  f1834f0:	c7a60164 */ 	lwc1	$f6,0x164($sp)
/*  f1834f4:	46003032 */ 	c.eq.s	$f6,$f0
/*  f1834f8:	00000000 */ 	nop
/*  f1834fc:	4503001c */ 	bc1tl	.PF0f183570
/*  f183500:	c7a80160 */ 	lwc1	$f8,0x160($sp)
/*  f183504:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f183508:	00001025 */ 	move	$v0,$zero
/*  f18350c:	3c017f1c */ 	lui	$at,0x7f1c
/*  f183510:	58600017 */ 	blezl	$v1,.PF0f183570
/*  f183514:	c7a80160 */ 	lwc1	$f8,0x160($sp)
/*  f183518:	c4289f90 */ 	lwc1	$f8,-0x6070($at)
/*  f18351c:	3c017f1c */ 	lui	$at,0x7f1c
/*  f183520:	c4209f94 */ 	lwc1	$f0,-0x606c($at)
/*  f183524:	46064082 */ 	mul.s	$f2,$f8,$f6
/*  f183528:	00000000 */ 	nop
/*  f18352c:	c66e0030 */ 	lwc1	$f14,0x30($s3)
/*  f183530:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f183534:	0043082a */ 	slt	$at,$v0,$v1
/*  f183538:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f18353c:	5020000a */ 	beqzl	$at,.PF0f183568
/*  f183540:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f183544:	46121380 */ 	add.s	$f14,$f2,$f18
.PF0f183548:
/*  f183548:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18354c:	0043082a */ 	slt	$at,$v0,$v1
/*  f183550:	e66e0030 */ 	swc1	$f14,0x30($s3)
/*  f183554:	c66e0030 */ 	lwc1	$f14,0x30($s3)
/*  f183558:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f18355c:	5420fffa */ 	bnezl	$at,.PF0f183548
/*  f183560:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f183564:	46121380 */ 	add.s	$f14,$f2,$f18
.PF0f183568:
/*  f183568:	e66e0030 */ 	swc1	$f14,0x30($s3)
/*  f18356c:	c7a80160 */ 	lwc1	$f8,0x160($sp)
.PF0f183570:
/*  f183570:	3c017f1c */ 	lui	$at,0x7f1c
/*  f183574:	c4209f98 */ 	lwc1	$f0,-0x6068($at)
/*  f183578:	460c4032 */ 	c.eq.s	$f8,$f12
/*  f18357c:	00000000 */ 	nop
/*  f183580:	4503001a */ 	bc1tl	.PF0f1835ec
/*  f183584:	c7a6015c */ 	lwc1	$f6,0x15c($sp)
/*  f183588:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f18358c:	00001025 */ 	move	$v0,$zero
/*  f183590:	3c017f1c */ 	lui	$at,0x7f1c
/*  f183594:	58600015 */ 	blezl	$v1,.PF0f1835ec
/*  f183598:	c7a6015c */ 	lwc1	$f6,0x15c($sp)
/*  f18359c:	c4269f9c */ 	lwc1	$f6,-0x6064($at)
/*  f1835a0:	46083082 */ 	mul.s	$f2,$f6,$f8
/*  f1835a4:	00000000 */ 	nop
/*  f1835a8:	c66e0034 */ 	lwc1	$f14,0x34($s3)
/*  f1835ac:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1835b0:	0043082a */ 	slt	$at,$v0,$v1
/*  f1835b4:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f1835b8:	5020000a */ 	beqzl	$at,.PF0f1835e4
/*  f1835bc:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f1835c0:	46121380 */ 	add.s	$f14,$f2,$f18
.PF0f1835c4:
/*  f1835c4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1835c8:	0043082a */ 	slt	$at,$v0,$v1
/*  f1835cc:	e66e0034 */ 	swc1	$f14,0x34($s3)
/*  f1835d0:	c66e0034 */ 	lwc1	$f14,0x34($s3)
/*  f1835d4:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f1835d8:	5420fffa */ 	bnezl	$at,.PF0f1835c4
/*  f1835dc:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f1835e0:	46121380 */ 	add.s	$f14,$f2,$f18
.PF0f1835e4:
/*  f1835e4:	e66e0034 */ 	swc1	$f14,0x34($s3)
/*  f1835e8:	c7a6015c */ 	lwc1	$f6,0x15c($sp)
.PF0f1835ec:
/*  f1835ec:	46103032 */ 	c.eq.s	$f6,$f16
/*  f1835f0:	00000000 */ 	nop
/*  f1835f4:	4503001a */ 	bc1tl	.PF0f183660
/*  f1835f8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1835fc:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f183600:	00001025 */ 	move	$v0,$zero
/*  f183604:	3c017f1c */ 	lui	$at,0x7f1c
/*  f183608:	58600015 */ 	blezl	$v1,.PF0f183660
/*  f18360c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f183610:	c4289fa0 */ 	lwc1	$f8,-0x6060($at)
/*  f183614:	46064082 */ 	mul.s	$f2,$f8,$f6
/*  f183618:	00000000 */ 	nop
/*  f18361c:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f183620:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f183624:	0043082a */ 	slt	$at,$v0,$v1
/*  f183628:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f18362c:	5020000a */ 	beqzl	$at,.PF0f183658
/*  f183630:	46121400 */ 	add.s	$f16,$f2,$f18
/*  f183634:	46121400 */ 	add.s	$f16,$f2,$f18
.PF0f183638:
/*  f183638:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f18363c:	0043082a */ 	slt	$at,$v0,$v1
/*  f183640:	e6700038 */ 	swc1	$f16,0x38($s3)
/*  f183644:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f183648:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f18364c:	5420fffa */ 	bnezl	$at,.PF0f183638
/*  f183650:	46121400 */ 	add.s	$f16,$f2,$f18
/*  f183654:	46121400 */ 	add.s	$f16,$f2,$f18
.PF0f183658:
/*  f183658:	e6700038 */ 	swc1	$f16,0x38($s3)
.PF0f18365c:
/*  f18365c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.PF0f183660:
/*  f183660:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f183664:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f183668:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f18366c:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f183670:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f183674:	03e00008 */ 	jr	$ra
/*  f183678:	27bd0188 */ 	addiu	$sp,$sp,0x188
);
#else
GLOBAL_ASM(
glabel scenarioKohTick
.late_rodata
glabel var7f1b893c
.word 0x3f733333
glabel var7f1b8940
.word 0x3d4ccccd
glabel var7f1b8944
.word 0x3f733333
glabel var7f1b8948
.word 0x3f733333
glabel var7f1b894c
.word 0x3d4ccccd
glabel var7f1b8950
.word 0x3d4ccccd
.text
/*  f181cf0:	27bdfe78 */ 	addiu	$sp,$sp,-392
/*  f181cf4:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f181cf8:	3c13800b */ 	lui	$s3,%hi(g_ScenarioData)
/*  f181cfc:	2673c110 */ 	addiu	$s3,$s3,%lo(g_ScenarioData)
/*  f181d00:	866e000a */ 	lh	$t6,0xa($s3)
/*  f181d04:	2401ffff */ 	addiu	$at,$zero,-1
/*  f181d08:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f181d0c:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f181d10:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f181d14:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f181d18:	11c1024d */ 	beq	$t6,$at,.L0f182650
/*  f181d1c:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f181d20:	866f0008 */ 	lh	$t7,0x8($s3)
/*  f181d24:	00003825 */ 	or	$a3,$zero,$zero
/*  f181d28:	3c013f80 */ 	lui	$at,0x3f80
/*  f181d2c:	11e00058 */ 	beqz	$t7,.L0f181e90
/*  f181d30:	00000000 */ 	nop
/*  f181d34:	44811000 */ 	mtc1	$at,$f2
/*  f181d38:	3c017f1c */ 	lui	$at,%hi(var7f1b893c)
/*  f181d3c:	c42c893c */ 	lwc1	$f12,%lo(var7f1b893c)($at)
/*  f181d40:	c6600030 */ 	lwc1	$f0,0x30($s3)
/*  f181d44:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f181d48:	a6780004 */ 	sh	$t8,0x4($s3)
/*  f181d4c:	4600603e */ 	c.le.s	$f12,$f0
/*  f181d50:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f181d54:	e7a20164 */ 	swc1	$f2,0x164($sp)
/*  f181d58:	e7a20160 */ 	swc1	$f2,0x160($sp)
/*  f181d5c:	45000047 */ 	bc1f	.L0f181e7c
/*  f181d60:	e7a2015c */ 	swc1	$f2,0x15c($sp)
/*  f181d64:	c6640034 */ 	lwc1	$f4,0x34($s3)
/*  f181d68:	4604603e */ 	c.le.s	$f12,$f4
/*  f181d6c:	00000000 */ 	nop
/*  f181d70:	45000042 */ 	bc1f	.L0f181e7c
/*  f181d74:	00000000 */ 	nop
/*  f181d78:	c6660038 */ 	lwc1	$f6,0x38($s3)
/*  f181d7c:	00002825 */ 	or	$a1,$zero,$zero
/*  f181d80:	00003025 */ 	or	$a2,$zero,$zero
/*  f181d84:	4606603e */ 	c.le.s	$f12,$f6
/*  f181d88:	00003825 */ 	or	$a3,$zero,$zero
/*  f181d8c:	4500003b */ 	bc1f	.L0f181e7c
/*  f181d90:	00000000 */ 	nop
/*  f181d94:	8664000e */ 	lh	$a0,0xe($s3)
/*  f181d98:	0fc00b0a */ 	jal	roomSetLighting
/*  f181d9c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f181da0:	8679000c */ 	lh	$t9,0xc($s3)
/*  f181da4:	00002025 */ 	or	$a0,$zero,$zero
/*  f181da8:	2b210002 */ 	slti	$at,$t9,0x2
/*  f181dac:	54200013 */ 	bnezl	$at,.L0f181dfc
/*  f181db0:	a660000a */ 	sh	$zero,0xa($s3)
/*  f181db4:	8670000a */ 	lh	$s0,0xa($s3)
.L0f181db8:
/*  f181db8:	0c004b70 */ 	jal	random
/*  f181dbc:	00000000 */ 	nop
/*  f181dc0:	8668000c */ 	lh	$t0,0xc($s3)
/*  f181dc4:	0048001b */ 	divu	$zero,$v0,$t0
/*  f181dc8:	00004810 */ 	mfhi	$t1
/*  f181dcc:	a669000a */ 	sh	$t1,0xa($s3)
/*  f181dd0:	8663000a */ 	lh	$v1,0xa($s3)
/*  f181dd4:	15000002 */ 	bnez	$t0,.L0f181de0
/*  f181dd8:	00000000 */ 	nop
/*  f181ddc:	0007000d */ 	break	0x7
.L0f181de0:
/*  f181de0:	1203fff5 */ 	beq	$s0,$v1,.L0f181db8
/*  f181de4:	00000000 */ 	nop
/*  f181de8:	00035040 */ 	sll	$t2,$v1,0x1
/*  f181dec:	026a5821 */ 	addu	$t3,$s3,$t2
/*  f181df0:	10000002 */ 	b	.L0f181dfc
/*  f181df4:	85640012 */ 	lh	$a0,0x12($t3)
/*  f181df8:	a660000a */ 	sh	$zero,0xa($s3)
.L0f181dfc:
/*  f181dfc:	24050042 */ 	addiu	$a1,$zero,0x42
/*  f181e00:	0fc456ac */ 	jal	padUnpack
/*  f181e04:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f181e08:	8fac00f0 */ 	lw	$t4,0xf0($sp)
/*  f181e0c:	c7a800a8 */ 	lwc1	$f8,0xa8($sp)
/*  f181e10:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*  f181e14:	c7b200b0 */ 	lwc1	$f18,0xb0($sp)
/*  f181e18:	240dffff */ 	addiu	$t5,$zero,-1
/*  f181e1c:	3c04800b */ 	lui	$a0,%hi(g_ScenarioData+0x24)
/*  f181e20:	3c05800b */ 	lui	$a1,%hi(g_ScenarioData+0xe)
/*  f181e24:	a66d0010 */ 	sh	$t5,0x10($s3)
/*  f181e28:	24a5c11e */ 	addiu	$a1,$a1,%lo(g_ScenarioData+0xe)
/*  f181e2c:	2484c134 */ 	addiu	$a0,$a0,%lo(g_ScenarioData+0x24)
/*  f181e30:	00003025 */ 	or	$a2,$zero,$zero
/*  f181e34:	00003825 */ 	or	$a3,$zero,$zero
/*  f181e38:	a66c000e */ 	sh	$t4,0xe($s3)
/*  f181e3c:	e6680024 */ 	swc1	$f8,0x24($s3)
/*  f181e40:	e66a0028 */ 	swc1	$f10,0x28($s3)
/*  f181e44:	0c00a8db */ 	jal	cd0002a36c
/*  f181e48:	e672002c */ 	swc1	$f18,0x2c($s3)
/*  f181e4c:	e6600028 */ 	swc1	$f0,0x28($s3)
/*  f181e50:	8664000e */ 	lh	$a0,0xe($s3)
/*  f181e54:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f181e58:	00003025 */ 	or	$a2,$zero,$zero
/*  f181e5c:	00003825 */ 	or	$a3,$zero,$zero
/*  f181e60:	0fc00b0a */ 	jal	roomSetLighting
/*  f181e64:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f181e68:	240effff */ 	addiu	$t6,$zero,-1
/*  f181e6c:	a66e0004 */ 	sh	$t6,0x4($s3)
/*  f181e70:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f181e74:	a6600008 */ 	sh	$zero,0x8($s3)
/*  f181e78:	c6600030 */ 	lwc1	$f0,0x30($s3)
.L0f181e7c:
/*  f181e7c:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f181e80:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f181e84:	c66c0034 */ 	lwc1	$f12,0x34($s3)
/*  f181e88:	10000196 */ 	b	.L0f1824e4
/*  f181e8c:	c6700038 */ 	lwc1	$f16,0x38($s3)
.L0f181e90:
/*  f181e90:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f181e94:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f181e98:	8e83033c */ 	lw	$v1,0x33c($s4)
/*  f181e9c:	00003025 */ 	or	$a2,$zero,$zero
/*  f181ea0:	24120003 */ 	addiu	$s2,$zero,0x3
/*  f181ea4:	1060001e */ 	beqz	$v1,.L0f181f20
/*  f181ea8:	24100006 */ 	addiu	$s0,$zero,0x6
/*  f181eac:	90620000 */ 	lbu	$v0,0x0($v1)
.L0f181eb0:
/*  f181eb0:	52020004 */ 	beql	$s0,$v0,.L0f181ec4
/*  f181eb4:	846f0028 */ 	lh	$t7,0x28($v1)
/*  f181eb8:	56420017 */ 	bnel	$s2,$v0,.L0f181f18
/*  f181ebc:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f181ec0:	846f0028 */ 	lh	$t7,0x28($v1)
.L0f181ec4:
/*  f181ec4:	8678000e */ 	lh	$t8,0xe($s3)
/*  f181ec8:	00008825 */ 	or	$s1,$zero,$zero
/*  f181ecc:	15f80002 */ 	bne	$t7,$t8,.L0f181ed8
/*  f181ed0:	00000000 */ 	nop
/*  f181ed4:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f181ed8:
/*  f181ed8:	5220000f */ 	beqzl	$s1,.L0f181f18
/*  f181edc:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f181ee0:	8c640004 */ 	lw	$a0,0x4($v1)
/*  f181ee4:	afa70170 */ 	sw	$a3,0x170($sp)
/*  f181ee8:	afa60174 */ 	sw	$a2,0x174($sp)
/*  f181eec:	0fc0e6a5 */ 	jal	chrIsDead
/*  f181ef0:	afa30074 */ 	sw	$v1,0x74($sp)
/*  f181ef4:	8fa30074 */ 	lw	$v1,0x74($sp)
/*  f181ef8:	8fa60174 */ 	lw	$a2,0x174($sp)
/*  f181efc:	14400005 */ 	bnez	$v0,.L0f181f14
/*  f181f00:	8fa70170 */ 	lw	$a3,0x170($sp)
/*  f181f04:	0006c880 */ 	sll	$t9,$a2,0x2
/*  f181f08:	03b94021 */ 	addu	$t0,$sp,$t9
/*  f181f0c:	ad030078 */ 	sw	$v1,0x78($t0)
/*  f181f10:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f181f14:
/*  f181f14:	8c630020 */ 	lw	$v1,0x20($v1)
.L0f181f18:
/*  f181f18:	5460ffe5 */ 	bnezl	$v1,.L0f181eb0
/*  f181f1c:	90620000 */ 	lbu	$v0,0x0($v1)
.L0f181f20:
/*  f181f20:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f181f24:	27a3011c */ 	addiu	$v1,$sp,0x11c
.L0f181f28:
/*  f181f28:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f181f2c:	0043082b */ 	sltu	$at,$v0,$v1
/*  f181f30:	1420fffd */ 	bnez	$at,.L0f181f28
/*  f181f34:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f181f38:	00008025 */ 	or	$s0,$zero,$zero
/*  f181f3c:	18c00017 */ 	blez	$a2,.L0f181f9c
/*  f181f40:	00009025 */ 	or	$s2,$zero,$zero
/*  f181f44:	27a30078 */ 	addiu	$v1,$sp,0x78
/*  f181f48:	27b100fc */ 	addiu	$s1,$sp,0xfc
.L0f181f4c:
/*  f181f4c:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f181f50:	8d250004 */ 	lw	$a1,0x4($t1)
/*  f181f54:	90a40125 */ 	lbu	$a0,0x125($a1)
/*  f181f58:	afa70170 */ 	sw	$a3,0x170($sp)
/*  f181f5c:	afa60174 */ 	sw	$a2,0x174($sp)
/*  f181f60:	0fc63a5a */ 	jal	radarGetTeamIndex
/*  f181f64:	afa30050 */ 	sw	$v1,0x50($sp)
/*  f181f68:	00025080 */ 	sll	$t2,$v0,0x2
/*  f181f6c:	022a2021 */ 	addu	$a0,$s1,$t2
/*  f181f70:	8c8b0000 */ 	lw	$t3,0x0($a0)
/*  f181f74:	8fa30050 */ 	lw	$v1,0x50($sp)
/*  f181f78:	8fa60174 */ 	lw	$a2,0x174($sp)
/*  f181f7c:	15600004 */ 	bnez	$t3,.L0f181f90
/*  f181f80:	8fa70170 */ 	lw	$a3,0x170($sp)
/*  f181f84:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f181f88:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f181f8c:	ac8c0000 */ 	sw	$t4,0x0($a0)
.L0f181f90:
/*  f181f90:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f181f94:	1606ffed */ 	bne	$s0,$a2,.L0f181f4c
/*  f181f98:	24630004 */ 	addiu	$v1,$v1,0x4
.L0f181f9c:
/*  f181f9c:	16400005 */ 	bnez	$s2,.L0f181fb4
/*  f181fa0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f181fa4:	240dffff */ 	addiu	$t5,$zero,-1
/*  f181fa8:	a66d0004 */ 	sh	$t5,0x4($s3)
/*  f181fac:	10000120 */ 	b	.L0f182430
/*  f181fb0:	a6600006 */ 	sh	$zero,0x6($s3)
.L0f181fb4:
/*  f181fb4:	1641000b */ 	bne	$s2,$at,.L0f181fe4
/*  f181fb8:	00008025 */ 	or	$s0,$zero,$zero
/*  f181fbc:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f181fc0:	24030008 */ 	addiu	$v1,$zero,0x8
.L0f181fc4:
/*  f181fc4:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f181fc8:	55c0003d */ 	bnezl	$t6,.L0f1820c0
/*  f181fcc:	866a0004 */ 	lh	$t2,0x4($s3)
/*  f181fd0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f181fd4:	1603fffb */ 	bne	$s0,$v1,.L0f181fc4
/*  f181fd8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f181fdc:	10000038 */ 	b	.L0f1820c0
/*  f181fe0:	866a0004 */ 	lh	$t2,0x4($s3)
.L0f181fe4:
/*  f181fe4:	00008825 */ 	or	$s1,$zero,$zero
/*  f181fe8:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f181fec:	27a4011c */ 	addiu	$a0,$sp,0x11c
/*  f181ff0:	8c430000 */ 	lw	$v1,0x0($v0)
.L0f181ff4:
/*  f181ff4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f181ff8:	0223082a */ 	slt	$at,$s1,$v1
/*  f181ffc:	50200003 */ 	beqzl	$at,.L0f18200c
/*  f182000:	0044082b */ 	sltu	$at,$v0,$a0
/*  f182004:	00608825 */ 	or	$s1,$v1,$zero
/*  f182008:	0044082b */ 	sltu	$at,$v0,$a0
.L0f18200c:
/*  f18200c:	5420fff9 */ 	bnezl	$at,.L0f181ff4
/*  f182010:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f182014:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f182018:	27a3011c */ 	addiu	$v1,$sp,0x11c
/*  f18201c:	8c4f0000 */ 	lw	$t7,0x0($v0)
.L0f182020:
/*  f182020:	522f0003 */ 	beql	$s1,$t7,.L0f182030
/*  f182024:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f182028:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f18202c:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f182030:
/*  f182030:	0043082b */ 	sltu	$at,$v0,$v1
/*  f182034:	5420fffa */ 	bnezl	$at,.L0f182020
/*  f182038:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f18203c:	27a200fc */ 	addiu	$v0,$sp,0xfc
/*  f182040:	27a3011c */ 	addiu	$v1,$sp,0x11c
/*  f182044:	8c580000 */ 	lw	$t8,0x0($v0)
.L0f182048:
/*  f182048:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f18204c:	0043082b */ 	sltu	$at,$v0,$v1
/*  f182050:	13000002 */ 	beqz	$t8,.L0f18205c
/*  f182054:	00000000 */ 	nop
/*  f182058:	24e70001 */ 	addiu	$a3,$a3,0x1
.L0f18205c:
/*  f18205c:	5420fffa */ 	bnezl	$at,.L0f182048
/*  f182060:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f182064:	28e10002 */ 	slti	$at,$a3,0x2
/*  f182068:	14200003 */ 	bnez	$at,.L0f182078
/*  f18206c:	00008025 */ 	or	$s0,$zero,$zero
/*  f182070:	10000002 */ 	b	.L0f18207c
/*  f182074:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f182078:
/*  f182078:	00003825 */ 	or	$a3,$zero,$zero
.L0f18207c:
/*  f18207c:	27a200fc */ 	addiu	$v0,$sp,0xfc
.L0f182080:
/*  f182080:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f182084:	53200005 */ 	beqzl	$t9,.L0f18209c
/*  f182088:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18208c:	86680004 */ 	lh	$t0,0x4($s3)
/*  f182090:	52080006 */ 	beql	$s0,$t0,.L0f1820ac
/*  f182094:	24030008 */ 	addiu	$v1,$zero,0x8
/*  f182098:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f18209c:
/*  f18209c:	2a010008 */ 	slti	$at,$s0,0x8
/*  f1820a0:	1420fff7 */ 	bnez	$at,.L0f182080
/*  f1820a4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1820a8:	24030008 */ 	addiu	$v1,$zero,0x8
.L0f1820ac:
/*  f1820ac:	16030003 */ 	bne	$s0,$v1,.L0f1820bc
/*  f1820b0:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f1820b4:	a6690004 */ 	sh	$t1,0x4($s3)
/*  f1820b8:	2410ffff */ 	addiu	$s0,$zero,-1
.L0f1820bc:
/*  f1820bc:	866a0004 */ 	lh	$t2,0x4($s3)
.L0f1820c0:
/*  f1820c0:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f1820c4:	240505b9 */ 	addiu	$a1,$zero,0x5b9
/*  f1820c8:	120a0070 */ 	beq	$s0,$t2,.L0f18228c
/*  f1820cc:	00003025 */ 	or	$a2,$zero,$zero
/*  f1820d0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1820d4:	44812000 */ 	mtc1	$at,$f4
/*  f1820d8:	240bffff */ 	addiu	$t3,$zero,-1
/*  f1820dc:	240cffff */ 	addiu	$t4,$zero,-1
/*  f1820e0:	240dffff */ 	addiu	$t5,$zero,-1
/*  f1820e4:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f1820e8:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f1820ec:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f1820f0:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f1820f4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f1820f8:	00008825 */ 	or	$s1,$zero,$zero
/*  f1820fc:	0c004241 */ 	jal	sndStart
/*  f182100:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f182104:	a6700004 */ 	sh	$s0,0x4($s3)
/*  f182108:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f18210c:	0fc5b9f1 */ 	jal	langGet
/*  f182110:	24045416 */ 	addiu	$a0,$zero,0x5416
/*  f182114:	00107080 */ 	sll	$t6,$s0,0x2
/*  f182118:	01d07023 */ 	subu	$t6,$t6,$s0
/*  f18211c:	3c0f800b */ 	lui	$t7,%hi(g_MpSetup+0x28)
/*  f182120:	25efcbb0 */ 	addiu	$t7,$t7,%lo(g_MpSetup+0x28)
/*  f182124:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f182128:	01cf3021 */ 	addu	$a2,$t6,$t7
/*  f18212c:	27a4011c */ 	addiu	$a0,$sp,0x11c
/*  f182130:	0c004dad */ 	jal	sprintf
/*  f182134:	00402825 */ 	or	$a1,$v0,$zero
/*  f182138:	8e98006c */ 	lw	$t8,0x6c($s4)
/*  f18213c:	27b0011c */ 	addiu	$s0,$sp,0x11c
/*  f182140:	8e92028c */ 	lw	$s2,0x28c($s4)
/*  f182144:	13000003 */ 	beqz	$t8,.L0f182154
/*  f182148:	00002825 */ 	or	$a1,$zero,$zero
/*  f18214c:	10000001 */ 	b	.L0f182154
/*  f182150:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f182154:
/*  f182154:	8e990068 */ 	lw	$t9,0x68($s4)
/*  f182158:	00002025 */ 	or	$a0,$zero,$zero
/*  f18215c:	00001825 */ 	or	$v1,$zero,$zero
/*  f182160:	13200003 */ 	beqz	$t9,.L0f182170
/*  f182164:	00001025 */ 	or	$v0,$zero,$zero
/*  f182168:	10000001 */ 	b	.L0f182170
/*  f18216c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f182170:
/*  f182170:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f182174:	11000003 */ 	beqz	$t0,.L0f182184
/*  f182178:	00000000 */ 	nop
/*  f18217c:	10000001 */ 	b	.L0f182184
/*  f182180:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f182184:
/*  f182184:	8e890070 */ 	lw	$t1,0x70($s4)
/*  f182188:	11200003 */ 	beqz	$t1,.L0f182198
/*  f18218c:	00000000 */ 	nop
/*  f182190:	10000001 */ 	b	.L0f182198
/*  f182194:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f182198:
/*  f182198:	00435021 */ 	addu	$t2,$v0,$v1
/*  f18219c:	01445821 */ 	addu	$t3,$t2,$a0
/*  f1821a0:	01656021 */ 	addu	$t4,$t3,$a1
/*  f1821a4:	19800035 */ 	blez	$t4,.L0f18227c
/*  f1821a8:	00000000 */ 	nop
.L0f1821ac:
/*  f1821ac:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f1821b0:	02202025 */ 	or	$a0,$s1,$zero
/*  f1821b4:	8e8d0284 */ 	lw	$t5,0x284($s4)
/*  f1821b8:	8dae00bc */ 	lw	$t6,0xbc($t5)
/*  f1821bc:	8dc50004 */ 	lw	$a1,0x4($t6)
/*  f1821c0:	0fc63a5a */ 	jal	radarGetTeamIndex
/*  f1821c4:	90a40125 */ 	lbu	$a0,0x125($a1)
/*  f1821c8:	866f0004 */ 	lh	$t7,0x4($s3)
/*  f1821cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f1821d0:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1821d4:	144f0009 */ 	bne	$v0,$t7,.L0f1821fc
/*  f1821d8:	00000000 */ 	nop
/*  f1821dc:	0fc5b9f1 */ 	jal	langGet
/*  f1821e0:	24045415 */ 	addiu	$a0,$zero,0x5415
/*  f1821e4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1821e8:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1821ec:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f1821f0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1821f4:	10000004 */ 	b	.L0f182208
/*  f1821f8:	8e98006c */ 	lw	$t8,0x6c($s4)
.L0f1821fc:
/*  f1821fc:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f182200:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f182204:	8e98006c */ 	lw	$t8,0x6c($s4)
.L0f182208:
/*  f182208:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f18220c:	00002825 */ 	or	$a1,$zero,$zero
/*  f182210:	13000003 */ 	beqz	$t8,.L0f182220
/*  f182214:	00002025 */ 	or	$a0,$zero,$zero
/*  f182218:	10000001 */ 	b	.L0f182220
/*  f18221c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f182220:
/*  f182220:	8e990068 */ 	lw	$t9,0x68($s4)
/*  f182224:	00001825 */ 	or	$v1,$zero,$zero
/*  f182228:	00001025 */ 	or	$v0,$zero,$zero
/*  f18222c:	13200003 */ 	beqz	$t9,.L0f18223c
/*  f182230:	00000000 */ 	nop
/*  f182234:	10000001 */ 	b	.L0f18223c
/*  f182238:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f18223c:
/*  f18223c:	8e880064 */ 	lw	$t0,0x64($s4)
/*  f182240:	11000003 */ 	beqz	$t0,.L0f182250
/*  f182244:	00000000 */ 	nop
/*  f182248:	10000001 */ 	b	.L0f182250
/*  f18224c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f182250:
/*  f182250:	8e890070 */ 	lw	$t1,0x70($s4)
/*  f182254:	11200003 */ 	beqz	$t1,.L0f182264
/*  f182258:	00000000 */ 	nop
/*  f18225c:	10000001 */ 	b	.L0f182264
/*  f182260:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f182264:
/*  f182264:	00435021 */ 	addu	$t2,$v0,$v1
/*  f182268:	01445821 */ 	addu	$t3,$t2,$a0
/*  f18226c:	01656021 */ 	addu	$t4,$t3,$a1
/*  f182270:	022c082a */ 	slt	$at,$s1,$t4
/*  f182274:	1420ffcd */ 	bnez	$at,.L0f1821ac
/*  f182278:	00000000 */ 	nop
.L0f18227c:
/*  f18227c:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f182280:	02402025 */ 	or	$a0,$s2,$zero
/*  f182284:	1000006b */ 	b	.L0f182434
/*  f182288:	86630004 */ 	lh	$v1,0x4($s3)
.L0f18228c:
/*  f18228c:	54e00069 */ 	bnezl	$a3,.L0f182434
/*  f182290:	86630004 */ 	lh	$v1,0x4($s3)
/*  f182294:	866d0006 */ 	lh	$t5,0x6($s3)
/*  f182298:	8e8e0034 */ 	lw	$t6,0x34($s4)
/*  f18229c:	8e990484 */ 	lw	$t9,0x484($s4)
/*  f1822a0:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f1822a4:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f1822a8:	a66f0006 */ 	sh	$t7,0x6($s3)
/*  f1822ac:	00194100 */ 	sll	$t0,$t9,0x4
/*  f1822b0:	86780006 */ 	lh	$t8,0x6($s3)
/*  f1822b4:	01194023 */ 	subu	$t0,$t0,$t9
/*  f1822b8:	00084100 */ 	sll	$t0,$t0,0x4
/*  f1822bc:	25090960 */ 	addiu	$t1,$t0,0x960
/*  f1822c0:	0309082a */ 	slt	$at,$t8,$t1
/*  f1822c4:	1420005a */ 	bnez	$at,.L0f182430
/*  f1822c8:	240505b8 */ 	addiu	$a1,$zero,0x5b8
/*  f1822cc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1822d0:	44813000 */ 	mtc1	$at,$f6
/*  f1822d4:	240affff */ 	addiu	$t2,$zero,-1
/*  f1822d8:	240bffff */ 	addiu	$t3,$zero,-1
/*  f1822dc:	240cffff */ 	addiu	$t4,$zero,-1
/*  f1822e0:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f1822e4:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f1822e8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f1822ec:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f1822f0:	00003025 */ 	or	$a2,$zero,$zero
/*  f1822f4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f1822f8:	00009025 */ 	or	$s2,$zero,$zero
/*  f1822fc:	0c004241 */ 	jal	sndStart
/*  f182300:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f182304:	3c03800b */ 	lui	$v1,%hi(g_MpNumChrs)
/*  f182308:	8c63c530 */ 	lw	$v1,%lo(g_MpNumChrs)($v1)
/*  f18230c:	3c10800b */ 	lui	$s0,%hi(g_MpAllChrPtrs)
/*  f182310:	2610c4d0 */ 	addiu	$s0,$s0,%lo(g_MpAllChrPtrs)
/*  f182314:	1860001e */ 	blez	$v1,.L0f182390
/*  f182318:	00002825 */ 	or	$a1,$zero,$zero
/*  f18231c:	3c11800b */ 	lui	$s1,%hi(g_MpAllChrConfigPtrs)
/*  f182320:	2631c500 */ 	addiu	$s1,$s1,%lo(g_MpAllChrConfigPtrs)
.L0f182324:
/*  f182324:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f182328:	91a40125 */ 	lbu	$a0,0x125($t5)
/*  f18232c:	0fc63a5a */ 	jal	radarGetTeamIndex
/*  f182330:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f182334:	866e0004 */ 	lh	$t6,0x4($s3)
/*  f182338:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f18233c:	144e000c */ 	bne	$v0,$t6,.L0f182370
/*  f182340:	00000000 */ 	nop
/*  f182344:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f182348:	8668000e */ 	lh	$t0,0xe($s3)
/*  f18234c:	0225c021 */ 	addu	$t8,$s1,$a1
/*  f182350:	8de3001c */ 	lw	$v1,0x1c($t7)
/*  f182354:	84790028 */ 	lh	$t9,0x28($v1)
/*  f182358:	17280005 */ 	bne	$t9,$t0,.L0f182370
/*  f18235c:	00000000 */ 	nop
/*  f182360:	8f020000 */ 	lw	$v0,0x0($t8)
/*  f182364:	8449003e */ 	lh	$t1,0x3e($v0)
/*  f182368:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f18236c:	a44a003e */ 	sh	$t2,0x3e($v0)
.L0f182370:
/*  f182370:	3c03800b */ 	lui	$v1,%hi(g_MpNumChrs)
/*  f182374:	8c63c530 */ 	lw	$v1,%lo(g_MpNumChrs)($v1)
/*  f182378:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f18237c:	24a50004 */ 	addiu	$a1,$a1,0x0004
/*  f182380:	0243082a */ 	slt	$at,$s2,$v1
/*  f182384:	1420ffe7 */ 	bnez	$at,.L0f182324
/*  f182388:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f18238c:	00009025 */ 	or	$s2,$zero,$zero
.L0f182390:
/*  f182390:	1860001b */ 	blez	$v1,.L0f182400
/*  f182394:	8e91028c */ 	lw	$s1,0x28c($s4)
/*  f182398:	3c10800b */ 	lui	$s0,%hi(g_MpAllChrPtrs)
/*  f18239c:	2610c4d0 */ 	addiu	$s0,$s0,%lo(g_MpAllChrPtrs)
/*  f1823a0:	8e020000 */ 	lw	$v0,0x0($s0)
.L0f1823a4:
/*  f1823a4:	8c4b02d4 */ 	lw	$t3,0x2d4($v0)
/*  f1823a8:	1560000e */ 	bnez	$t3,.L0f1823e4
/*  f1823ac:	00000000 */ 	nop
/*  f1823b0:	0fc63a5a */ 	jal	radarGetTeamIndex
/*  f1823b4:	90440125 */ 	lbu	$a0,0x125($v0)
/*  f1823b8:	866c0004 */ 	lh	$t4,0x4($s3)
/*  f1823bc:	144c0009 */ 	bne	$v0,$t4,.L0f1823e4
/*  f1823c0:	00000000 */ 	nop
/*  f1823c4:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f1823c8:	02402025 */ 	or	$a0,$s2,$zero
/*  f1823cc:	0fc5b9f1 */ 	jal	langGet
/*  f1823d0:	24045414 */ 	addiu	$a0,$zero,0x5414
/*  f1823d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1823d8:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1823dc:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f1823e0:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f1823e4:
/*  f1823e4:	3c0d800b */ 	lui	$t5,%hi(g_MpNumChrs)
/*  f1823e8:	8dadc530 */ 	lw	$t5,%lo(g_MpNumChrs)($t5)
/*  f1823ec:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1823f0:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f1823f4:	024d082a */ 	slt	$at,$s2,$t5
/*  f1823f8:	5420ffea */ 	bnezl	$at,.L0f1823a4
/*  f1823fc:	8e020000 */ 	lw	$v0,0x0($s0)
.L0f182400:
/*  f182400:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f182404:	02202025 */ 	or	$a0,$s1,$zero
/*  f182408:	240effff */ 	addiu	$t6,$zero,-1
/*  f18240c:	a66e0004 */ 	sh	$t6,0x4($s3)
/*  f182410:	a6600006 */ 	sh	$zero,0x6($s3)
/*  f182414:	3c0f800b */ 	lui	$t7,%hi(g_MpSetup+0xc)
/*  f182418:	8defcb94 */ 	lw	$t7,%lo(g_MpSetup+0xc)($t7)
/*  f18241c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f182420:	31f98000 */ 	andi	$t9,$t7,0x8000
/*  f182424:	53200003 */ 	beqzl	$t9,.L0f182434
/*  f182428:	86630004 */ 	lh	$v1,0x4($s3)
/*  f18242c:	a6680008 */ 	sh	$t0,0x8($s3)
.L0f182430:
/*  f182430:	86630004 */ 	lh	$v1,0x4($s3)
.L0f182434:
/*  f182434:	2401ffff */ 	addiu	$at,$zero,-1
/*  f182438:	3c028008 */ 	lui	$v0,%hi(g_TeamColours)
/*  f18243c:	1461000c */ 	bne	$v1,$at,.L0f182470
/*  f182440:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f182444:	3c013f80 */ 	lui	$at,0x3f80
/*  f182448:	44811000 */ 	mtc1	$at,$f2
/*  f18244c:	3c013e80 */ 	lui	$at,0x3e80
/*  f182450:	44817000 */ 	mtc1	$at,$f14
/*  f182454:	c6600030 */ 	lwc1	$f0,0x30($s3)
/*  f182458:	c66c0034 */ 	lwc1	$f12,0x34($s3)
/*  f18245c:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f182460:	e7a20160 */ 	swc1	$f2,0x160($sp)
/*  f182464:	e7ae0164 */ 	swc1	$f14,0x164($sp)
/*  f182468:	1000001e */ 	b	.L0f1824e4
/*  f18246c:	e7ae015c */ 	swc1	$f14,0x15c($sp)
.L0f182470:
/*  f182470:	00581021 */ 	addu	$v0,$v0,$t8
/*  f182474:	8c427cc4 */ 	lw	$v0,%lo(g_TeamColours)($v0)
/*  f182478:	3c013b00 */ 	lui	$at,0x3b00
/*  f18247c:	44811000 */ 	mtc1	$at,$f2
/*  f182480:	00024e02 */ 	srl	$t1,$v0,0x18
/*  f182484:	312a00ff */ 	andi	$t2,$t1,0xff
/*  f182488:	254b00ff */ 	addiu	$t3,$t2,0xff
/*  f18248c:	448b4000 */ 	mtc1	$t3,$f8
/*  f182490:	00026402 */ 	srl	$t4,$v0,0x10
/*  f182494:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f182498:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f18249c:	25ae00ff */ 	addiu	$t6,$t5,0xff
/*  f1824a0:	448e2000 */ 	mtc1	$t6,$f4
/*  f1824a4:	00027a02 */ 	srl	$t7,$v0,0x8
/*  f1824a8:	31f900ff */ 	andi	$t9,$t7,0xff
/*  f1824ac:	272800ff */ 	addiu	$t0,$t9,0xff
/*  f1824b0:	46025482 */ 	mul.s	$f18,$f10,$f2
/*  f1824b4:	44885000 */ 	mtc1	$t0,$f10
/*  f1824b8:	c6600030 */ 	lwc1	$f0,0x30($s3)
/*  f1824bc:	c66c0034 */ 	lwc1	$f12,0x34($s3)
/*  f1824c0:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f1824c4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1824c8:	e7b20164 */ 	swc1	$f18,0x164($sp)
/*  f1824cc:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f1824d0:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f1824d4:	00000000 */ 	nop
/*  f1824d8:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f1824dc:	e7a80160 */ 	swc1	$f8,0x160($sp)
/*  f1824e0:	e7a4015c */ 	swc1	$f4,0x15c($sp)
.L0f1824e4:
/*  f1824e4:	c7a60164 */ 	lwc1	$f6,0x164($sp)
/*  f1824e8:	46003032 */ 	c.eq.s	$f6,$f0
/*  f1824ec:	00000000 */ 	nop
/*  f1824f0:	4503001c */ 	bc1tl	.L0f182564
/*  f1824f4:	c7a80160 */ 	lwc1	$f8,0x160($sp)
/*  f1824f8:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f1824fc:	00001025 */ 	or	$v0,$zero,$zero
/*  f182500:	3c017f1c */ 	lui	$at,%hi(var7f1b8940)
/*  f182504:	58600017 */ 	blezl	$v1,.L0f182564
/*  f182508:	c7a80160 */ 	lwc1	$f8,0x160($sp)
/*  f18250c:	c4288940 */ 	lwc1	$f8,%lo(var7f1b8940)($at)
/*  f182510:	3c017f1c */ 	lui	$at,%hi(var7f1b8944)
/*  f182514:	c4208944 */ 	lwc1	$f0,%lo(var7f1b8944)($at)
/*  f182518:	46064082 */ 	mul.s	$f2,$f8,$f6
/*  f18251c:	00000000 */ 	nop
/*  f182520:	c66e0030 */ 	lwc1	$f14,0x30($s3)
/*  f182524:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f182528:	0043082a */ 	slt	$at,$v0,$v1
/*  f18252c:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f182530:	5020000a */ 	beqzl	$at,.L0f18255c
/*  f182534:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f182538:	46121380 */ 	add.s	$f14,$f2,$f18
.L0f18253c:
/*  f18253c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f182540:	0043082a */ 	slt	$at,$v0,$v1
/*  f182544:	e66e0030 */ 	swc1	$f14,0x30($s3)
/*  f182548:	c66e0030 */ 	lwc1	$f14,0x30($s3)
/*  f18254c:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f182550:	5420fffa */ 	bnezl	$at,.L0f18253c
/*  f182554:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f182558:	46121380 */ 	add.s	$f14,$f2,$f18
.L0f18255c:
/*  f18255c:	e66e0030 */ 	swc1	$f14,0x30($s3)
/*  f182560:	c7a80160 */ 	lwc1	$f8,0x160($sp)
.L0f182564:
/*  f182564:	3c017f1c */ 	lui	$at,%hi(var7f1b8948)
/*  f182568:	c4208948 */ 	lwc1	$f0,%lo(var7f1b8948)($at)
/*  f18256c:	460c4032 */ 	c.eq.s	$f8,$f12
/*  f182570:	00000000 */ 	nop
/*  f182574:	4503001a */ 	bc1tl	.L0f1825e0
/*  f182578:	c7a6015c */ 	lwc1	$f6,0x15c($sp)
/*  f18257c:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f182580:	00001025 */ 	or	$v0,$zero,$zero
/*  f182584:	3c017f1c */ 	lui	$at,%hi(var7f1b894c)
/*  f182588:	58600015 */ 	blezl	$v1,.L0f1825e0
/*  f18258c:	c7a6015c */ 	lwc1	$f6,0x15c($sp)
/*  f182590:	c426894c */ 	lwc1	$f6,%lo(var7f1b894c)($at)
/*  f182594:	46083082 */ 	mul.s	$f2,$f6,$f8
/*  f182598:	00000000 */ 	nop
/*  f18259c:	c66e0034 */ 	lwc1	$f14,0x34($s3)
/*  f1825a0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1825a4:	0043082a */ 	slt	$at,$v0,$v1
/*  f1825a8:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f1825ac:	5020000a */ 	beqzl	$at,.L0f1825d8
/*  f1825b0:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f1825b4:	46121380 */ 	add.s	$f14,$f2,$f18
.L0f1825b8:
/*  f1825b8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1825bc:	0043082a */ 	slt	$at,$v0,$v1
/*  f1825c0:	e66e0034 */ 	swc1	$f14,0x34($s3)
/*  f1825c4:	c66e0034 */ 	lwc1	$f14,0x34($s3)
/*  f1825c8:	460e0482 */ 	mul.s	$f18,$f0,$f14
/*  f1825cc:	5420fffa */ 	bnezl	$at,.L0f1825b8
/*  f1825d0:	46121380 */ 	add.s	$f14,$f2,$f18
/*  f1825d4:	46121380 */ 	add.s	$f14,$f2,$f18
.L0f1825d8:
/*  f1825d8:	e66e0034 */ 	swc1	$f14,0x34($s3)
/*  f1825dc:	c7a6015c */ 	lwc1	$f6,0x15c($sp)
.L0f1825e0:
/*  f1825e0:	46103032 */ 	c.eq.s	$f6,$f16
/*  f1825e4:	00000000 */ 	nop
/*  f1825e8:	4503001a */ 	bc1tl	.L0f182654
/*  f1825ec:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1825f0:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f1825f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1825f8:	3c017f1c */ 	lui	$at,%hi(var7f1b8950)
/*  f1825fc:	58600015 */ 	blezl	$v1,.L0f182654
/*  f182600:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f182604:	c4288950 */ 	lwc1	$f8,%lo(var7f1b8950)($at)
/*  f182608:	46064082 */ 	mul.s	$f2,$f8,$f6
/*  f18260c:	00000000 */ 	nop
/*  f182610:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f182614:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f182618:	0043082a */ 	slt	$at,$v0,$v1
/*  f18261c:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f182620:	5020000a */ 	beqzl	$at,.L0f18264c
/*  f182624:	46121400 */ 	add.s	$f16,$f2,$f18
/*  f182628:	46121400 */ 	add.s	$f16,$f2,$f18
.L0f18262c:
/*  f18262c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f182630:	0043082a */ 	slt	$at,$v0,$v1
/*  f182634:	e6700038 */ 	swc1	$f16,0x38($s3)
/*  f182638:	c6700038 */ 	lwc1	$f16,0x38($s3)
/*  f18263c:	46100482 */ 	mul.s	$f18,$f0,$f16
/*  f182640:	5420fffa */ 	bnezl	$at,.L0f18262c
/*  f182644:	46121400 */ 	add.s	$f16,$f2,$f18
/*  f182648:	46121400 */ 	add.s	$f16,$f2,$f18
.L0f18264c:
/*  f18264c:	e6700038 */ 	swc1	$f16,0x38($s3)
.L0f182650:
/*  f182650:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f182654:
/*  f182654:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f182658:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f18265c:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f182660:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f182664:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f182668:	03e00008 */ 	jr	$ra
/*  f18266c:	27bd0188 */ 	addiu	$sp,$sp,0x188
);
#endif

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

	if (radarGetTeamIndex(chr->team) == g_ScenarioData.koh.occupiedteam && g_ScenarioData.koh.unk08 == 0) {
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
	if (g_MpSetup.options & MPOPTION_KOH_HILLONRADAR && g_ScenarioData.koh.unk08 == 0) {
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

		a *= g_ScenarioData.koh.unk30;
		b *= g_ScenarioData.koh.unk34;
		c *= g_ScenarioData.koh.unk38;

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
