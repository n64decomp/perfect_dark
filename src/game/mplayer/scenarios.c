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

u32 var800ac460;
u32 var800ac464;
u32 var800ac468;
u32 var800ac46c;
u32 var800ac470;
u32 var800ac474;
u32 var800ac478;
u32 var800ac47c;
u32 var800ac480;
u32 var800ac484;
u32 var800ac488;
u32 var800ac48c;
u32 var800ac490;
u32 var800ac494;
u32 var800ac498;
u32 var800ac49c;
u32 var800ac4a0;
u32 var800ac4a4;
u32 var800ac4a8;
u32 var800ac4ac;
u32 var800ac4b0;
u32 var800ac4b4;
u32 var800ac4b8;
u32 var800ac4bc;
u32 var800ac4c0;
u32 var800ac4c4;
u32 var800ac4c8;
u32 var800ac4cc;

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
		tmp->timer240 = 0;

		g_ScenarioData.ctc.baserooms[0] = g_ScenarioData.ctc.tokens[0]->rooms[0];
	}

	if (g_ScenarioData.ctc.playercountsperteam[1] != 0) {
		g_CtcTokenObj1 = template;
		tmp = &g_CtcTokenObj1;
		tmp->base.pad = g_ScenarioData.ctc.spawnpadsperteam[g_ScenarioData.ctc.teamindexes[1]].homepad;

		weaponAssignToHome(tmp, 1001);

		g_ScenarioData.ctc.tokens[1] = tmp->base.prop;

		tmp->base.hidden2 &= ~OBJH2FLAG_CANREGEN;
		tmp->timer240 = 1;

		g_ScenarioData.ctc.baserooms[1] = g_ScenarioData.ctc.tokens[1]->rooms[0];
	}

	if (g_ScenarioData.ctc.playercountsperteam[2] != 0) {
		g_CtcTokenObj2 = template;
		tmp = &g_CtcTokenObj2;
		tmp->base.pad = g_ScenarioData.ctc.spawnpadsperteam[g_ScenarioData.ctc.teamindexes[2]].homepad;

		weaponAssignToHome(tmp, 1002);

		g_ScenarioData.ctc.tokens[2] = tmp->base.prop;

		tmp->base.hidden2 &= ~OBJH2FLAG_CANREGEN;
		tmp->timer240 = 2;

		g_ScenarioData.ctc.baserooms[2] = g_ScenarioData.ctc.tokens[2]->rooms[0];
	}

	if (g_ScenarioData.ctc.playercountsperteam[3] != 0) {
		g_CtcTokenObj3 = template;
		tmp = &g_CtcTokenObj3;
		tmp->base.pad = g_ScenarioData.ctc.spawnpadsperteam[g_ScenarioData.ctc.teamindexes[3]].homepad;

		weaponAssignToHome(tmp, 1003);

		g_ScenarioData.ctc.tokens[3] = tmp->base.prop;

		tmp->base.hidden2 &= ~OBJH2FLAG_CANREGEN;
		tmp->timer240 = 3;

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
				u32 teamcolour = g_TeamColours[weapon->timer240];

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
	g_ScenarioData.htm.unk0d0 = -1;
	g_ScenarioData.htm.uplinkingplayernum = -1;
	g_ScenarioData.htm.unk0d4 = -1;
	g_ScenarioData.htm.unk140 = 0;

	for (i = 0; i < ARRAYCOUNT(g_ScenarioData.htm.unk0d8); i++) {
		g_ScenarioData.htm.unk0d8[i] = 0;
		g_ScenarioData.htm.unk108[i] = 0;
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

u32 var80086e14 = 0x02000008;
u32 var80086e18 = 0x00130000;
u32 var80086e1c = 0x00420001;
u32 var80086e20 = 0x00204000;
u32 var80086e24 = 0x00000000;
u32 var80086e28 = 0x00000000;
u32 var80086e2c = 0x00000000;
u32 var80086e30 = 0x3f800000;
u32 var80086e34 = 0x00000000;
u32 var80086e38 = 0x00000000;
u32 var80086e3c = 0x00000000;
u32 var80086e40 = 0x3f800000;
u32 var80086e44 = 0x00000000;
u32 var80086e48 = 0x00000000;
u32 var80086e4c = 0x00000000;
u32 var80086e50 = 0x3f800000;
u32 var80086e54 = 0x00000000;
u32 var80086e58 = 0x00000000;
u32 var80086e5c = 0x00000000;
u32 var80086e60 = 0x000003e8;
u32 var80086e64 = 0xffffff00;
u32 var80086e68 = 0xffffff00;
u32 var80086e6c = 0x0fff0000;
u32 var80086e70 = 0x36000000;
u32 var80086e74 = 0x00ffffff;
u32 var80086e78 = 0x00000000;

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f182c98
/*  f182c98:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f182c9c:	3c0f8008 */ 	lui	$t7,%hi(var80086e14)
/*  f182ca0:	25ef6e14 */ 	addiu	$t7,$t7,%lo(var80086e14)
/*  f182ca4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f182ca8:	25e80060 */ 	addiu	$t0,$t7,0x60
/*  f182cac:	27ae0080 */ 	addiu	$t6,$sp,0x80
.L0f182cb0:
/*  f182cb0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f182cb4:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f182cb8:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f182cbc:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f182cc0:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f182cc4:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f182cc8:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f182ccc:	15e8fff8 */ 	bne	$t7,$t0,.L0f182cb0
/*  f182cd0:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f182cd4:	8de10000 */ 	lw	$at,0x0($t7)
/*  f182cd8:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f182cdc:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x33c)
/*  f182ce0:	adc10000 */ 	sw	$at,0x0($t6)
/*  f182ce4:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f182ce8:	8c42a2fc */ 	lw	$v0,%lo(g_Vars+0x33c)($v0)
/*  f182cec:	00002025 */ 	or	$a0,$zero,$zero
/*  f182cf0:	27a70020 */ 	addiu	$a3,$sp,0x20
/*  f182cf4:	10400013 */ 	beqz	$v0,.L0f182d44
/*  f182cf8:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f182cfc:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f182d00:	90490000 */ 	lbu	$t1,0x0($v0)
.L0f182d04:
/*  f182d04:	54a9000a */ 	bnel	$a1,$t1,.L0f182d30
/*  f182d08:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f182d0c:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f182d10:	00045880 */ 	sll	$t3,$a0,0x2
/*  f182d14:	00eb6021 */ 	addu	$t4,$a3,$t3
/*  f182d18:	906a0003 */ 	lbu	$t2,0x3($v1)
/*  f182d1c:	54ca0004 */ 	bnel	$a2,$t2,.L0f182d30
/*  f182d20:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f182d24:	ad830000 */ 	sw	$v1,0x0($t4)
/*  f182d28:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f182d2c:	8c420020 */ 	lw	$v0,0x20($v0)
.L0f182d30:
/*  f182d30:	28810014 */ 	slti	$at,$a0,0x14
/*  f182d34:	10400003 */ 	beqz	$v0,.L0f182d44
/*  f182d38:	00000000 */ 	nop
/*  f182d3c:	5420fff1 */ 	bnezl	$at,.L0f182d04
/*  f182d40:	90490000 */ 	lbu	$t1,0x0($v0)
.L0f182d44:
/*  f182d44:	1880001a */ 	blez	$a0,.L0f182db0
/*  f182d48:	00000000 */ 	nop
/*  f182d4c:	0c004b70 */ 	jal	random
/*  f182d50:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f182d54:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f182d58:	27a70020 */ 	addiu	$a3,$sp,0x20
/*  f182d5c:	3c058008 */ 	lui	$a1,%hi(var800869ec)
/*  f182d60:	0044001b */ 	divu	$zero,$v0,$a0
/*  f182d64:	24a569ec */ 	addiu	$a1,$a1,%lo(var800869ec)
/*  f182d68:	14800002 */ 	bnez	$a0,.L0f182d74
/*  f182d6c:	00000000 */ 	nop
/*  f182d70:	0007000d */ 	break	0x7
.L0f182d74:
/*  f182d74:	00002010 */ 	mfhi	$a0
/*  f182d78:	00046880 */ 	sll	$t5,$a0,0x2
/*  f182d7c:	00edc821 */ 	addu	$t9,$a3,$t5
/*  f182d80:	8f380000 */ 	lw	$t8,0x0($t9)
/*  f182d84:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f182d88:	8f080040 */ 	lw	$t0,0x40($t8)
/*  f182d8c:	350f0004 */ 	ori	$t7,$t0,0x4
/*  f182d90:	af0f0040 */ 	sw	$t7,0x40($t8)
/*  f182d94:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f182d98:	906e0002 */ 	lbu	$t6,0x2($v1)
/*  f182d9c:	35c90004 */ 	ori	$t1,$t6,0x4
/*  f182da0:	a0690002 */ 	sb	$t1,0x2($v1)
/*  f182da4:	8caa0000 */ 	lw	$t2,0x0($a1)
/*  f182da8:	10000015 */ 	b	.L0f182e00
/*  f182dac:	85460006 */ 	lh	$a2,0x6($t2)
.L0f182db0:
/*  f182db0:	3c0b800b */ 	lui	$t3,%hi(g_ScenarioData)
/*  f182db4:	856bc110 */ 	lh	$t3,%lo(g_ScenarioData)($t3)
/*  f182db8:	59600011 */ 	blezl	$t3,.L0f182e00
/*  f182dbc:	00003025 */ 	or	$a2,$zero,$zero
/*  f182dc0:	0c004b70 */ 	jal	random
/*  f182dc4:	00000000 */ 	nop
/*  f182dc8:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f182dcc:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f182dd0:	846c0000 */ 	lh	$t4,0x0($v1)
/*  f182dd4:	004c001b */ 	divu	$zero,$v0,$t4
/*  f182dd8:	00006810 */ 	mfhi	$t5
/*  f182ddc:	000dc840 */ 	sll	$t9,$t5,0x1
/*  f182de0:	0079c021 */ 	addu	$t8,$v1,$t9
/*  f182de4:	15800002 */ 	bnez	$t4,.L0f182df0
/*  f182de8:	00000000 */ 	nop
/*  f182dec:	0007000d */ 	break	0x7
.L0f182df0:
/*  f182df0:	87060004 */ 	lh	$a2,0x4($t8)
/*  f182df4:	10000002 */ 	b	.L0f182e00
/*  f182df8:	00000000 */ 	nop
/*  f182dfc:	00003025 */ 	or	$a2,$zero,$zero
.L0f182e00:
/*  f182e00:	3c04800b */ 	lui	$a0,%hi(var800ac460)
/*  f182e04:	2484c460 */ 	addiu	$a0,$a0,%lo(var800ac460)
/*  f182e08:	27a80080 */ 	addiu	$t0,$sp,0x80
/*  f182e0c:	250e0060 */ 	addiu	$t6,$t0,0x60
/*  f182e10:	00804825 */ 	or	$t1,$a0,$zero
.L0f182e14:
/*  f182e14:	8d010000 */ 	lw	$at,0x0($t0)
/*  f182e18:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f182e1c:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f182e20:	ad21fff4 */ 	sw	$at,-0xc($t1)
/*  f182e24:	8d01fff8 */ 	lw	$at,-0x8($t0)
/*  f182e28:	ad21fff8 */ 	sw	$at,-0x8($t1)
/*  f182e2c:	8d01fffc */ 	lw	$at,-0x4($t0)
/*  f182e30:	150efff8 */ 	bne	$t0,$t6,.L0f182e14
/*  f182e34:	ad21fffc */ 	sw	$at,-0x4($t1)
/*  f182e38:	8d010000 */ 	lw	$at,0x0($t0)
/*  f182e3c:	240503e7 */ 	addiu	$a1,$zero,0x3e7
/*  f182e40:	ad210000 */ 	sw	$at,0x0($t1)
/*  f182e44:	8d0e0004 */ 	lw	$t6,0x4($t0)
/*  f182e48:	ad2e0004 */ 	sw	$t6,0x4($t1)
/*  f182e4c:	0fc0359c */ 	jal	weaponAssignToHome
/*  f182e50:	a4860006 */ 	sh	$a2,0x6($a0)
/*  f182e54:	3c04800b */ 	lui	$a0,%hi(var800ac460)
/*  f182e58:	2484c460 */ 	addiu	$a0,$a0,%lo(var800ac460)
/*  f182e5c:	908a0002 */ 	lbu	$t2,0x2($a0)
/*  f182e60:	8c8c0014 */ 	lw	$t4,0x14($a0)
/*  f182e64:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f182e68:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f182e6c:	314bfffb */ 	andi	$t3,$t2,0xfffb
/*  f182e70:	a08b0002 */ 	sb	$t3,0x2($a0)
/*  f182e74:	11800004 */ 	beqz	$t4,.L0f182e88
/*  f182e78:	ac6c013c */ 	sw	$t4,0x13c($v1)
/*  f182e7c:	9199003f */ 	lbu	$t9,0x3f($t4)
/*  f182e80:	37380020 */ 	ori	$t8,$t9,0x20
/*  f182e84:	a198003f */ 	sb	$t8,0x3f($t4)
.L0f182e88:
/*  f182e88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f182e8c:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
/*  f182e90:	03e00008 */ 	jr	$ra
/*  f182e94:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel func0f182c98
/*  f17d2ec:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f17d2f0:	3c0f8009 */ 	lui	$t7,0x8009
/*  f17d2f4:	25ef9594 */ 	addiu	$t7,$t7,-27244
/*  f17d2f8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f17d2fc:	25e80060 */ 	addiu	$t0,$t7,0x60
/*  f17d300:	27ae0080 */ 	addiu	$t6,$sp,0x80
.NB0f17d304:
/*  f17d304:	8de10000 */ 	lw	$at,0x0($t7)
/*  f17d308:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f17d30c:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f17d310:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f17d314:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f17d318:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f17d31c:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f17d320:	15e8fff8 */ 	bne	$t7,$t0,.NB0f17d304
/*  f17d324:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f17d328:	8de10000 */ 	lw	$at,0x0($t7)
/*  f17d32c:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f17d330:	3c03800a */ 	lui	$v1,0x800a
/*  f17d334:	adc10000 */ 	sw	$at,0x0($t6)
/*  f17d338:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f17d33c:	8c63e9fc */ 	lw	$v1,-0x1604($v1)
/*  f17d340:	00002025 */ 	or	$a0,$zero,$zero
/*  f17d344:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f17d348:	1060000f */ 	beqz	$v1,.NB0f17d388
/*  f17d34c:	24050014 */ 	addiu	$a1,$zero,0x14
/*  f17d350:	8c620004 */ 	lw	$v0,0x4($v1)
.NB0f17d354:
/*  f17d354:	00045080 */ 	sll	$t2,$a0,0x2
/*  f17d358:	00ca5821 */ 	addu	$t3,$a2,$t2
/*  f17d35c:	90490003 */ 	lbu	$t1,0x3($v0)
/*  f17d360:	54a90004 */ 	bnel	$a1,$t1,.NB0f17d374
/*  f17d364:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f17d368:	ad620000 */ 	sw	$v0,0x0($t3)
/*  f17d36c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f17d370:	8c630020 */ 	lw	$v1,0x20($v1)
.NB0f17d374:
/*  f17d374:	28810014 */ 	slti	$at,$a0,0x14
/*  f17d378:	10600003 */ 	beqz	$v1,.NB0f17d388
/*  f17d37c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d380:	5420fff4 */ 	bnezl	$at,.NB0f17d354
/*  f17d384:	8c620004 */ 	lw	$v0,0x4($v1)
.NB0f17d388:
/*  f17d388:	1880001a */ 	blez	$a0,.NB0f17d3f4
/*  f17d38c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d390:	0c004d84 */ 	jal	random
/*  f17d394:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f17d398:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f17d39c:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f17d3a0:	3c058009 */ 	lui	$a1,0x8009
/*  f17d3a4:	0044001b */ 	divu	$zero,$v0,$a0
/*  f17d3a8:	24a5916c */ 	addiu	$a1,$a1,-28308
/*  f17d3ac:	14800002 */ 	bnez	$a0,.NB0f17d3b8
/*  f17d3b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d3b4:	0007000d */ 	break	0x7
.NB0f17d3b8:
/*  f17d3b8:	00002010 */ 	mfhi	$a0
/*  f17d3bc:	00046080 */ 	sll	$t4,$a0,0x2
/*  f17d3c0:	00cc6821 */ 	addu	$t5,$a2,$t4
/*  f17d3c4:	8db90000 */ 	lw	$t9,0x0($t5)
/*  f17d3c8:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f17d3cc:	8f380040 */ 	lw	$t8,0x40($t9)
/*  f17d3d0:	37080004 */ 	ori	$t0,$t8,0x4
/*  f17d3d4:	af280040 */ 	sw	$t0,0x40($t9)
/*  f17d3d8:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f17d3dc:	906f0002 */ 	lbu	$t7,0x2($v1)
/*  f17d3e0:	35ee0004 */ 	ori	$t6,$t7,0x4
/*  f17d3e4:	a06e0002 */ 	sb	$t6,0x2($v1)
/*  f17d3e8:	8ca90000 */ 	lw	$t1,0x0($a1)
/*  f17d3ec:	10000015 */ 	beqz	$zero,.NB0f17d444
/*  f17d3f0:	85270006 */ 	lh	$a3,0x6($t1)
.NB0f17d3f4:
/*  f17d3f4:	3c0a800b */ 	lui	$t2,0x800b
/*  f17d3f8:	854a09c0 */ 	lh	$t2,0x9c0($t2)
/*  f17d3fc:	59400011 */ 	blezl	$t2,.NB0f17d444
/*  f17d400:	00003825 */ 	or	$a3,$zero,$zero
/*  f17d404:	0c004d84 */ 	jal	random
/*  f17d408:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d40c:	3c03800b */ 	lui	$v1,0x800b
/*  f17d410:	246309c0 */ 	addiu	$v1,$v1,0x9c0
/*  f17d414:	846b0000 */ 	lh	$t3,0x0($v1)
/*  f17d418:	004b001b */ 	divu	$zero,$v0,$t3
/*  f17d41c:	00006010 */ 	mfhi	$t4
/*  f17d420:	000c6840 */ 	sll	$t5,$t4,0x1
/*  f17d424:	006dc821 */ 	addu	$t9,$v1,$t5
/*  f17d428:	15600002 */ 	bnez	$t3,.NB0f17d434
/*  f17d42c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d430:	0007000d */ 	break	0x7
.NB0f17d434:
/*  f17d434:	87270004 */ 	lh	$a3,0x4($t9)
/*  f17d438:	10000002 */ 	beqz	$zero,.NB0f17d444
/*  f17d43c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f17d440:	00003825 */ 	or	$a3,$zero,$zero
.NB0f17d444:
/*  f17d444:	3c04800b */ 	lui	$a0,0x800b
/*  f17d448:	24840d10 */ 	addiu	$a0,$a0,0xd10
/*  f17d44c:	27b80080 */ 	addiu	$t8,$sp,0x80
/*  f17d450:	270f0060 */ 	addiu	$t7,$t8,0x60
/*  f17d454:	00807025 */ 	or	$t6,$a0,$zero
.NB0f17d458:
/*  f17d458:	8f010000 */ 	lw	$at,0x0($t8)
/*  f17d45c:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f17d460:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f17d464:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f17d468:	8f01fff8 */ 	lw	$at,-0x8($t8)
/*  f17d46c:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f17d470:	8f01fffc */ 	lw	$at,-0x4($t8)
/*  f17d474:	170ffff8 */ 	bne	$t8,$t7,.NB0f17d458
/*  f17d478:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f17d47c:	8f010000 */ 	lw	$at,0x0($t8)
/*  f17d480:	240503e7 */ 	addiu	$a1,$zero,0x3e7
/*  f17d484:	adc10000 */ 	sw	$at,0x0($t6)
/*  f17d488:	8f0f0004 */ 	lw	$t7,0x4($t8)
/*  f17d48c:	adcf0004 */ 	sw	$t7,0x4($t6)
/*  f17d490:	0fc034c8 */ 	jal	weaponAssignToHome
/*  f17d494:	a4870006 */ 	sh	$a3,0x6($a0)
/*  f17d498:	3c04800b */ 	lui	$a0,0x800b
/*  f17d49c:	24840d10 */ 	addiu	$a0,$a0,0xd10
/*  f17d4a0:	90890002 */ 	lbu	$t1,0x2($a0)
/*  f17d4a4:	8c8b0014 */ 	lw	$t3,0x14($a0)
/*  f17d4a8:	3c03800b */ 	lui	$v1,0x800b
/*  f17d4ac:	246309c0 */ 	addiu	$v1,$v1,0x9c0
/*  f17d4b0:	312afffb */ 	andi	$t2,$t1,0xfffb
/*  f17d4b4:	a08a0002 */ 	sb	$t2,0x2($a0)
/*  f17d4b8:	11600004 */ 	beqz	$t3,.NB0f17d4cc
/*  f17d4bc:	ac6b013c */ 	sw	$t3,0x13c($v1)
/*  f17d4c0:	916d003f */ 	lbu	$t5,0x3f($t3)
/*  f17d4c4:	35b90020 */ 	ori	$t9,$t5,0x20
/*  f17d4c8:	a179003f */ 	sb	$t9,0x3f($t3)
.NB0f17d4cc:
/*  f17d4cc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f17d4d0:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
/*  f17d4d4:	03e00008 */ 	jr	$ra
/*  f17d4d8:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

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

	func0f182c98();

	osSyncPrintf("HackThatMacInitProps -> End\n");
}

const char var7f1b86b4[] = "HTM : Player %d - Term Pos = (%d,%d,%d)";
const char var7f1b86dc[] = "HTM : Player %d - Play Pos = (%d,%d,%d)";
const char var7f1b8704[] = "HTM : Player %d - T/P  Rel = (%d,%d,%d)";
const char var7f1b872c[] = "HTM : Player %d - Range XZ = %d";
const char var7f1b874c[] = "HTM : Player %d - Range Y  = %d";
const char var7f1b876c[] = "HTM : Player %d - Angle XZ = %d";
const char var7f1b878c[] = "HTM : Player %d - Dwnld Plr=%d, Dwnld Prop=%d\n";
const char var7f1b87bc[] = "HTM : Player %d - Download Time = %d";
const char var7f1b87e4[] = "PopACapReset -> num_mplayers=%d : Working\n";
const char var7f1b8810[] = "PopACapReset -> Generated %d victims for this game : Listing\n";
const char var7f1b8850[] = "PopACapReset -> Victim %d is player %d\n";
const char var7f1b8878[] = "PopACapReset -> Done\n";
const char var7f1b8890[] = "PopACapTick : Current Victim = %d (Player %d)\n";

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
		func0f182c98();
	}
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel scenarioHtmCallback14
.late_rodata
glabel var7f1b8958
.word 0x40c907a9
glabel var7f1b895c
.word 0x42652ee0
glabel var7f1b8960
.word 0x42652ee0
.text
/*  f183380:	27bdff40 */ 	addiu	$sp,$sp,-192
/*  f183384:	afb4005c */ 	sw	$s4,0x5c($sp)
/*  f183388:	0080a025 */ 	or	$s4,$a0,$zero
/*  f18338c:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f183390:	afb50060 */ 	sw	$s5,0x60($sp)
/*  f183394:	afb30058 */ 	sw	$s3,0x58($sp)
/*  f183398:	afb20054 */ 	sw	$s2,0x54($sp)
/*  f18339c:	afb10050 */ 	sw	$s1,0x50($sp)
/*  f1833a0:	afb0004c */ 	sw	$s0,0x4c($sp)
/*  f1833a4:	10800008 */ 	beqz	$a0,.L0f1833c8
/*  f1833a8:	f7b40040 */ 	sdc1	$f20,0x40($sp)
/*  f1833ac:	8c8e02d4 */ 	lw	$t6,0x2d4($a0)
/*  f1833b0:	8dd3004c */ 	lw	$s3,0x4c($t6)
/*  f1833b4:	00137940 */ 	sll	$t7,$s3,0x5
/*  f1833b8:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1833bc:	000f9fc2 */ 	srl	$s3,$t7,0x1f
/*  f1833c0:	1000000d */ 	b	.L0f1833f8
/*  f1833c4:	00409025 */ 	or	$s2,$v0,$zero
.L0f1833c8:
/*  f1833c8:	0fc44a21 */ 	jal	invHasDataUplink
/*  f1833cc:	00000000 */ 	nop
/*  f1833d0:	0002202b */ 	sltu	$a0,$zero,$v0
/*  f1833d4:	10800005 */ 	beqz	$a0,.L0f1833ec
/*  f1833d8:	00000000 */ 	nop
/*  f1833dc:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f1833e0:	00002025 */ 	or	$a0,$zero,$zero
/*  f1833e4:	38440036 */ 	xori	$a0,$v0,0x36
/*  f1833e8:	2c840001 */ 	sltiu	$a0,$a0,0x1
.L0f1833ec:
/*  f1833ec:	3c12800a */ 	lui	$s2,%hi(g_Vars+0x28c)
/*  f1833f0:	00809825 */ 	or	$s3,$a0,$zero
/*  f1833f4:	8e52a24c */ 	lw	$s2,%lo(g_Vars+0x28c)($s2)
.L0f1833f8:
/*  f1833f8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1833fc:	3c11800b */ 	lui	$s1,%hi(g_ScenarioData)
/*  f183400:	3c15800b */ 	lui	$s5,%hi(g_ScenarioData)
/*  f183404:	4481a000 */ 	mtc1	$at,$f20
/*  f183408:	26b5c110 */ 	addiu	$s5,$s5,%lo(g_ScenarioData)
/*  f18340c:	2631c110 */ 	addiu	$s1,$s1,%lo(g_ScenarioData)
/*  f183410:	00008025 */ 	or	$s0,$zero,$zero
.L0f183414:
/*  f183414:	8e240080 */ 	lw	$a0,0x80($s1)
/*  f183418:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f18341c:	50800061 */ 	beqzl	$a0,.L0f1835a4
/*  f183420:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f183424:	12800005 */ 	beqz	$s4,.L0f18343c
/*  f183428:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f18342c:	1260000b */ 	beqz	$s3,.L0f18345c
/*  f183430:	00000000 */ 	nop
/*  f183434:	10000009 */ 	b	.L0f18345c
/*  f183438:	02402825 */ 	or	$a1,$s2,$zero
.L0f18343c:
/*  f18343c:	8c620040 */ 	lw	$v0,0x40($v1)
/*  f183440:	3c01f000 */ 	lui	$at,0xf000
/*  f183444:	30594000 */ 	andi	$t9,$v0,0x4000
/*  f183448:	13200004 */ 	beqz	$t9,.L0f18345c
/*  f18344c:	00000000 */ 	nop
/*  f183450:	00412824 */ 	and	$a1,$v0,$at
/*  f183454:	00054702 */ 	srl	$t0,$a1,0x1c
/*  f183458:	01002825 */ 	or	$a1,$t0,$zero
.L0f18345c:
/*  f18345c:	56450051 */ 	bnel	$s2,$a1,.L0f1835a4
/*  f183460:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f183464:	8c690040 */ 	lw	$t1,0x40($v1)
/*  f183468:	2401bfff */ 	addiu	$at,$zero,-16385
/*  f18346c:	3c0d800b */ 	lui	$t5,%hi(g_ScenarioData+0xd4)
/*  f183470:	01215024 */ 	and	$t2,$t1,$at
/*  f183474:	3c010fff */ 	lui	$at,0xfff
/*  f183478:	3421ffff */ 	ori	$at,$at,0xffff
/*  f18347c:	ac6a0040 */ 	sw	$t2,0x40($v1)
/*  f183480:	01416024 */ 	and	$t4,$t2,$at
/*  f183484:	1260002e */ 	beqz	$s3,.L0f183540
/*  f183488:	ac6c0040 */ 	sw	$t4,0x40($v1)
/*  f18348c:	8dadc1e4 */ 	lw	$t5,%lo(g_ScenarioData+0xd4)($t5)
/*  f183490:	2401ffff */ 	addiu	$at,$zero,-1
/*  f183494:	00127080 */ 	sll	$t6,$s2,0x2
/*  f183498:	15a10041 */ 	bne	$t5,$at,.L0f1835a0
/*  f18349c:	02ae7821 */ 	addu	$t7,$s5,$t6
/*  f1834a0:	3c01800b */ 	lui	$at,%hi(g_ScenarioData)
/*  f1834a4:	ac30c1e4 */ 	sw	$s0,%lo(g_ScenarioData+0xd4)($at)
/*  f1834a8:	a432c1e0 */ 	sh	$s2,%lo(g_ScenarioData+0xd0)($at)
/*  f1834ac:	a432c1e2 */ 	sh	$s2,%lo(g_ScenarioData+0xd2)($at)
/*  f1834b0:	1680003b */ 	bnez	$s4,.L0f1835a0
/*  f1834b4:	ade00108 */ 	sw	$zero,0x108($t7)
/*  f1834b8:	0fc5b9f1 */ 	jal	langGet
/*  f1834bc:	24045412 */ 	addiu	$a0,$zero,0x5413
/*  f1834c0:	00402025 */ 	or	$a0,$v0,$zero
/*  f1834c4:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1834c8:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f1834cc:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1834d0:	3c18800b */ 	lui	$t8,%hi(g_ScenarioData+0xd4)
/*  f1834d4:	8f18c1e4 */ 	lw	$t8,%lo(g_ScenarioData+0xd4)($t8)
/*  f1834d8:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f1834dc:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f1834e0:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1834e4:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f1834e8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1834ec:	02b94021 */ 	addu	$t0,$s5,$t9
/*  f1834f0:	8d050080 */ 	lw	$a1,0x80($t0)
/*  f1834f4:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f1834f8:	240cffff */ 	addiu	$t4,$zero,-1
/*  f1834fc:	afac002c */ 	sw	$t4,0x2c($sp)
/*  f183500:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f183504:	e7b40038 */ 	swc1	$f20,0x38($sp)
/*  f183508:	e7b40034 */ 	swc1	$f20,0x34($sp)
/*  f18350c:	e7b40030 */ 	swc1	$f20,0x30($sp)
/*  f183510:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f183514:	e7b40024 */ 	swc1	$f20,0x24($sp)
/*  f183518:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f18351c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f183520:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f183524:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f183528:	00002025 */ 	or	$a0,$zero,$zero
/*  f18352c:	240601bf */ 	addiu	$a2,$zero,0x1bf
/*  f183530:	0fc24e7e */ 	jal	func0f0939f8
/*  f183534:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f183538:	1000001a */ 	b	.L0f1835a4
/*  f18353c:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f183540:
/*  f183540:	56800018 */ 	bnezl	$s4,.L0f1835a4
/*  f183544:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f183548:	0fc5b9f1 */ 	jal	langGet
/*  f18354c:	24045413 */ 	addiu	$a0,$zero,0x5414
/*  f183550:	00402025 */ 	or	$a0,$v0,$zero
/*  f183554:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f183558:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f18355c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f183560:	3c013f80 */ 	lui	$at,0x3f80
/*  f183564:	44812000 */ 	mtc1	$at,$f4
/*  f183568:	240d01cc */ 	addiu	$t5,$zero,0x1cc
/*  f18356c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f183570:	240fffff */ 	addiu	$t7,$zero,-1
/*  f183574:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f183578:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f18357c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f183580:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f183584:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f183588:	00002025 */ 	or	$a0,$zero,$zero
/*  f18358c:	00002825 */ 	or	$a1,$zero,$zero
/*  f183590:	24067fff */ 	addiu	$a2,$zero,0x7fff
/*  f183594:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f183598:	0c0041c6 */ 	jal	snd00010718
/*  f18359c:	e7a40014 */ 	swc1	$f4,0x14($sp)
.L0f1835a0:
/*  f1835a0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1835a4:
/*  f1835a4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1835a8:	1601ff9a */ 	bne	$s0,$at,.L0f183414
/*  f1835ac:	2631000c */ 	addiu	$s1,$s1,0xc
/*  f1835b0:	3c19800b */ 	lui	$t9,%hi(g_ScenarioData+0xd0)
/*  f1835b4:	8739c1e0 */ 	lh	$t9,%lo(g_ScenarioData+0xd0)($t9)
/*  f1835b8:	3c08800b */ 	lui	$t0,%hi(g_ScenarioData+0xd4)
/*  f1835bc:	565900f1 */ 	bnel	$s2,$t9,.L0f183984
/*  f1835c0:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f1835c4:	8d08c1e4 */ 	lw	$t0,%lo(g_ScenarioData+0xd4)($t0)
/*  f1835c8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1835cc:	00125880 */ 	sll	$t3,$s2,0x2
/*  f1835d0:	110100eb */ 	beq	$t0,$at,.L0f183980
/*  f1835d4:	00084880 */ 	sll	$t1,$t0,0x2
/*  f1835d8:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1835dc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1835e0:	02a95021 */ 	addu	$t2,$s5,$t1
/*  f1835e4:	8d510080 */ 	lw	$s1,0x80($t2)
/*  f1835e8:	02ab9821 */ 	addu	$s3,$s5,$t3
/*  f1835ec:	266c0108 */ 	addiu	$t4,$s3,0x108
/*  f1835f0:	afac006c */ 	sw	$t4,0x6c($sp)
/*  f1835f4:	12800011 */ 	beqz	$s4,.L0f18363c
/*  f1835f8:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f1835fc:	8e90001c */ 	lw	$s0,0x1c($s4)
/*  f183600:	02802025 */ 	or	$a0,$s4,$zero
/*  f183604:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f183608:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f18360c:	3c017f1c */ 	lui	$at,%hi(var7f1b8958)
/*  f183610:	c4268958 */ 	lwc1	$f6,%lo(var7f1b8958)($at)
/*  f183614:	3c017f1c */ 	lui	$at,%hi(var7f1b895c)
/*  f183618:	c42a895c */ 	lwc1	$f10,%lo(var7f1b895c)($at)
/*  f18361c:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f183620:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f183624:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f183628:	8e8d02d4 */ 	lw	$t5,0x2d4($s4)
/*  f18362c:	8da30020 */ 	lw	$v1,0x20($t5)
/*  f183630:	386e0001 */ 	xori	$t6,$v1,0x1
/*  f183634:	1000000b */ 	b	.L0f183664
/*  f183638:	2dc30001 */ 	sltiu	$v1,$t6,0x1
.L0f18363c:
/*  f18363c:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f183640:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f183644:	00002025 */ 	or	$a0,$zero,$zero
/*  f183648:	8c5000bc */ 	lw	$s0,0xbc($v0)
/*  f18364c:	c4460144 */ 	lwc1	$f6,0x144($v0)
/*  f183650:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f183654:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f183658:	e7a60098 */ 	swc1	$f6,0x98($sp)
/*  f18365c:	38430036 */ 	xori	$v1,$v0,0x36
/*  f183660:	2c630001 */ 	sltiu	$v1,$v1,0x1
.L0f183664:
/*  f183664:	c6280000 */ 	lwc1	$f8,0x0($s1)
/*  f183668:	c60a0000 */ 	lwc1	$f10,0x0($s0)
/*  f18366c:	c6240004 */ 	lwc1	$f4,0x4($s1)
/*  f183670:	c6060004 */ 	lwc1	$f6,0x4($s0)
/*  f183674:	460a4501 */ 	sub.s	$f20,$f8,$f10
/*  f183678:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f18367c:	c6280008 */ 	lwc1	$f8,0x8($s1)
/*  f183680:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f183684:	4614a102 */ 	mul.s	$f4,$f20,$f20
/*  f183688:	afa30078 */ 	sw	$v1,0x78($sp)
/*  f18368c:	460a4381 */ 	sub.s	$f14,$f8,$f10
/*  f183690:	e7a20080 */ 	swc1	$f2,0x80($sp)
/*  f183694:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f183698:	e7ae0084 */ 	swc1	$f14,0x84($sp)
/*  f18369c:	0c012974 */ 	jal	sqrtf
/*  f1836a0:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f1836a4:	c7a20080 */ 	lwc1	$f2,0x80($sp)
/*  f1836a8:	44804000 */ 	mtc1	$zero,$f8
/*  f1836ac:	8fa30078 */ 	lw	$v1,0x78($sp)
/*  f1836b0:	c7ae0084 */ 	lwc1	$f14,0x84($sp)
/*  f1836b4:	4602403c */ 	c.lt.s	$f8,$f2
/*  f1836b8:	46000486 */ 	mov.s	$f18,$f0
/*  f1836bc:	4600a306 */ 	mov.s	$f12,$f20
/*  f1836c0:	45020004 */ 	bc1fl	.L0f1836d4
/*  f1836c4:	46001407 */ 	neg.s	$f16,$f2
/*  f1836c8:	10000002 */ 	b	.L0f1836d4
/*  f1836cc:	46001406 */ 	mov.s	$f16,$f2
/*  f1836d0:	46001407 */ 	neg.s	$f16,$f2
.L0f1836d4:
/*  f1836d4:	afa30078 */ 	sw	$v1,0x78($sp)
/*  f1836d8:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*  f1836dc:	0fc259d4 */ 	jal	atan2f
/*  f1836e0:	e7b20090 */ 	swc1	$f18,0x90($sp)
/*  f1836e4:	3c014334 */ 	lui	$at,0x4334
/*  f1836e8:	44816000 */ 	mtc1	$at,$f12
/*  f1836ec:	3c017f1c */ 	lui	$at,%hi(var7f1b8960)
/*  f1836f0:	c42a8960 */ 	lwc1	$f10,%lo(var7f1b8960)($at)
/*  f1836f4:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f1836f8:	44804000 */ 	mtc1	$zero,$f8
/*  f1836fc:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f183700:	8fa30078 */ 	lw	$v1,0x78($sp)
/*  f183704:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*  f183708:	c7b20090 */ 	lwc1	$f18,0x90($sp)
/*  f18370c:	3c0143b4 */ 	lui	$at,0x43b4
/*  f183710:	46062080 */ 	add.s	$f2,$f4,$f6
/*  f183714:	460c103c */ 	c.lt.s	$f2,$f12
/*  f183718:	00000000 */ 	nop
/*  f18371c:	45020009 */ 	bc1fl	.L0f183744
/*  f183720:	4602603c */ 	c.lt.s	$f12,$f2
/*  f183724:	44810000 */ 	mtc1	$at,$f0
/*  f183728:	00000000 */ 	nop
/*  f18372c:	46001080 */ 	add.s	$f2,$f2,$f0
.L0f183730:
/*  f183730:	460c103c */ 	c.lt.s	$f2,$f12
/*  f183734:	00000000 */ 	nop
/*  f183738:	4503fffd */ 	bc1tl	.L0f183730
/*  f18373c:	46001080 */ 	add.s	$f2,$f2,$f0
/*  f183740:	4602603c */ 	c.lt.s	$f12,$f2
.L0f183744:
/*  f183744:	3c0143b4 */ 	lui	$at,0x43b4
/*  f183748:	44810000 */ 	mtc1	$at,$f0
/*  f18374c:	3c01437a */ 	lui	$at,0x437a
/*  f183750:	45020007 */ 	bc1fl	.L0f183770
/*  f183754:	4602403c */ 	c.lt.s	$f8,$f2
/*  f183758:	46001081 */ 	sub.s	$f2,$f2,$f0
.L0f18375c:
/*  f18375c:	4602603c */ 	c.lt.s	$f12,$f2
/*  f183760:	00000000 */ 	nop
/*  f183764:	4503fffd */ 	bc1tl	.L0f18375c
/*  f183768:	46001081 */ 	sub.s	$f2,$f2,$f0
/*  f18376c:	4602403c */ 	c.lt.s	$f8,$f2
.L0f183770:
/*  f183770:	44810000 */ 	mtc1	$at,$f0
/*  f183774:	3c014348 */ 	lui	$at,0x4348
/*  f183778:	45030003 */ 	bc1tl	.L0f183788
/*  f18377c:	4612003c */ 	c.lt.s	$f0,$f18
/*  f183780:	46001087 */ 	neg.s	$f2,$f2
/*  f183784:	4612003c */ 	c.lt.s	$f0,$f18
.L0f183788:
/*  f183788:	00000000 */ 	nop
/*  f18378c:	45030010 */ 	bc1tl	.L0f1837d0
/*  f183790:	4600903c */ 	c.lt.s	$f18,$f0
/*  f183794:	44815000 */ 	mtc1	$at,$f10
/*  f183798:	3c014234 */ 	lui	$at,0x4234
/*  f18379c:	4610503c */ 	c.lt.s	$f10,$f16
/*  f1837a0:	00000000 */ 	nop
/*  f1837a4:	4503000a */ 	bc1tl	.L0f1837d0
/*  f1837a8:	4600903c */ 	c.lt.s	$f18,$f0
/*  f1837ac:	44812000 */ 	mtc1	$at,$f4
/*  f1837b0:	00000000 */ 	nop
/*  f1837b4:	4602203c */ 	c.lt.s	$f4,$f2
/*  f1837b8:	00000000 */ 	nop
/*  f1837bc:	45030004 */ 	bc1tl	.L0f1837d0
/*  f1837c0:	4600903c */ 	c.lt.s	$f18,$f0
/*  f1837c4:	1460003a */ 	bnez	$v1,.L0f1838b0
/*  f1837c8:	8fa2006c */ 	lw	$v0,0x6c($sp)
/*  f1837cc:	4600903c */ 	c.lt.s	$f18,$f0
.L0f1837d0:
/*  f1837d0:	3c014348 */ 	lui	$at,0x4348
/*  f1837d4:	240fffff */ 	addiu	$t7,$zero,-1
/*  f1837d8:	45000009 */ 	bc1f	.L0f183800
/*  f1837dc:	00000000 */ 	nop
/*  f1837e0:	44813000 */ 	mtc1	$at,$f6
/*  f1837e4:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0xd2)
/*  f1837e8:	4606803c */ 	c.lt.s	$f16,$f6
/*  f1837ec:	00000000 */ 	nop
/*  f1837f0:	45000003 */ 	bc1f	.L0f183800
/*  f1837f4:	00000000 */ 	nop
/*  f1837f8:	10000003 */ 	b	.L0f183808
/*  f1837fc:	a432c1e2 */ 	sh	$s2,%lo(g_ScenarioData+0xd2)($at)
.L0f183800:
/*  f183800:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0xd2)
/*  f183804:	a42fc1e2 */ 	sh	$t7,%lo(g_ScenarioData+0xd2)($at)
.L0f183808:
/*  f183808:	16800021 */ 	bnez	$s4,.L0f183890
/*  f18380c:	00000000 */ 	nop
/*  f183810:	0fc5b9f1 */ 	jal	langGet
/*  f183814:	24045411 */ 	addiu	$a0,$zero,0x5412
/*  f183818:	00402025 */ 	or	$a0,$v0,$zero
/*  f18381c:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f183820:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f183824:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f183828:	3c18800b */ 	lui	$t8,%hi(g_ScenarioData+0xd4)
/*  f18382c:	8f18c1e4 */ 	lw	$t8,%lo(g_ScenarioData+0xd4)($t8)
/*  f183830:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f183834:	3406ffff */ 	dli	$a2,0xffff
/*  f183838:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f18383c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f183840:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f183844:	02b94021 */ 	addu	$t0,$s5,$t9
/*  f183848:	0fc249af */ 	jal	func0f0926bc
/*  f18384c:	8d040080 */ 	lw	$a0,0x80($t0)
/*  f183850:	3c013f80 */ 	lui	$at,0x3f80
/*  f183854:	44814000 */ 	mtc1	$at,$f8
/*  f183858:	240901cc */ 	addiu	$t1,$zero,0x1cc
/*  f18385c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f183860:	240bffff */ 	addiu	$t3,$zero,-1
/*  f183864:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f183868:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f18386c:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f183870:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f183874:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f183878:	00002025 */ 	or	$a0,$zero,$zero
/*  f18387c:	00002825 */ 	or	$a1,$zero,$zero
/*  f183880:	24067fff */ 	addiu	$a2,$zero,0x7fff
/*  f183884:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f183888:	0c0041c6 */ 	jal	snd00010718
/*  f18388c:	e7a80014 */ 	swc1	$f8,0x14($sp)
.L0f183890:
/*  f183890:	3c01800b */ 	lui	$at,%hi(g_ScenarioData)
/*  f183894:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f183898:	240dffff */ 	addiu	$t5,$zero,-1
/*  f18389c:	240effff */ 	addiu	$t6,$zero,-1
/*  f1838a0:	ac2dc1e4 */ 	sw	$t5,%lo(g_ScenarioData+0xd4)($at)
/*  f1838a4:	a42ec1e0 */ 	sh	$t6,%lo(g_ScenarioData+0xd0)($at)
/*  f1838a8:	10000035 */ 	b	.L0f183980
/*  f1838ac:	ade00000 */ 	sw	$zero,0x0($t7)
.L0f1838b0:
/*  f1838b0:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x34)
/*  f1838b4:	8f399ff4 */ 	lw	$t9,%lo(g_Vars+0x34)($t9)
/*  f1838b8:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f1838bc:	03194021 */ 	addu	$t0,$t8,$t9
/*  f1838c0:	290112c1 */ 	slti	$at,$t0,0xfa1
/*  f1838c4:	1420002e */ 	bnez	$at,.L0f183980
/*  f1838c8:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f1838cc:	8e6a00d8 */ 	lw	$t2,0xd8($s3)
/*  f1838d0:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0xd2)
/*  f1838d4:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f1838d8:	ae6b00d8 */ 	sw	$t3,0xd8($s3)
/*  f1838dc:	16800022 */ 	bnez	$s4,.L0f183968
/*  f1838e0:	a432c1e2 */ 	sh	$s2,%lo(g_ScenarioData+0xd2)($at)
/*  f1838e4:	0fc5b9f1 */ 	jal	langGet
/*  f1838e8:	24045410 */ 	addiu	$a0,$zero,0x5411
/*  f1838ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f1838f0:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1838f4:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f1838f8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1838fc:	3c0c800b */ 	lui	$t4,%hi(g_ScenarioData+0xd4)
/*  f183900:	8d8cc1e4 */ 	lw	$t4,%lo(g_ScenarioData+0xd4)($t4)
/*  f183904:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f183908:	3406ffff */ 	dli	$a2,0xffff
/*  f18390c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f183910:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f183914:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f183918:	02ad7021 */ 	addu	$t6,$s5,$t5
/*  f18391c:	0fc249af */ 	jal	func0f0926bc
/*  f183920:	8dc40080 */ 	lw	$a0,0x80($t6)
/*  f183924:	3c013f80 */ 	lui	$at,0x3f80
/*  f183928:	44815000 */ 	mtc1	$at,$f10
/*  f18392c:	240f01c1 */ 	addiu	$t7,$zero,0x1c1
/*  f183930:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f183934:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f183938:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f18393c:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f183940:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f183944:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f183948:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f18394c:	00002025 */ 	or	$a0,$zero,$zero
/*  f183950:	00002825 */ 	or	$a1,$zero,$zero
/*  f183954:	24067fff */ 	addiu	$a2,$zero,0x7fff
/*  f183958:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f18395c:	0c0041c6 */ 	jal	snd00010718
/*  f183960:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f183964:	8fa2006c */ 	lw	$v0,0x6c($sp)
.L0f183968:
/*  f183968:	3c01800b */ 	lui	$at,%hi(g_ScenarioData)
/*  f18396c:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f183970:	240affff */ 	addiu	$t2,$zero,-1
/*  f183974:	ac29c1e4 */ 	sw	$t1,%lo(g_ScenarioData+0xd4)($at)
/*  f183978:	a42ac1e0 */ 	sh	$t2,%lo(g_ScenarioData+0xd0)($at)
/*  f18397c:	ac400000 */ 	sw	$zero,0x0($v0)
.L0f183980:
/*  f183980:	8fbf0064 */ 	lw	$ra,0x64($sp)
.L0f183984:
/*  f183984:	d7b40040 */ 	ldc1	$f20,0x40($sp)
/*  f183988:	8fb0004c */ 	lw	$s0,0x4c($sp)
/*  f18398c:	8fb10050 */ 	lw	$s1,0x50($sp)
/*  f183990:	8fb20054 */ 	lw	$s2,0x54($sp)
/*  f183994:	8fb30058 */ 	lw	$s3,0x58($sp)
/*  f183998:	8fb4005c */ 	lw	$s4,0x5c($sp)
/*  f18399c:	8fb50060 */ 	lw	$s5,0x60($sp)
/*  f1839a0:	03e00008 */ 	jr	$ra
/*  f1839a4:	27bd00c0 */ 	addiu	$sp,$sp,0xc0
);
#else
GLOBAL_ASM(
glabel scenarioHtmCallback14
.late_rodata
glabel var7f1b8958
.word 0x40c907a9
glabel var7f1b895c
.word 0x42652ee0
glabel var7f1b8960
.word 0x42652ee0
.text
/*  f183380:	27bdff40 */ 	addiu	$sp,$sp,-192
/*  f183384:	afb4005c */ 	sw	$s4,0x5c($sp)
/*  f183388:	0080a025 */ 	or	$s4,$a0,$zero
/*  f18338c:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f183390:	afb50060 */ 	sw	$s5,0x60($sp)
/*  f183394:	afb30058 */ 	sw	$s3,0x58($sp)
/*  f183398:	afb20054 */ 	sw	$s2,0x54($sp)
/*  f18339c:	afb10050 */ 	sw	$s1,0x50($sp)
/*  f1833a0:	afb0004c */ 	sw	$s0,0x4c($sp)
/*  f1833a4:	10800008 */ 	beqz	$a0,.L0f1833c8
/*  f1833a8:	f7b40040 */ 	sdc1	$f20,0x40($sp)
/*  f1833ac:	8c8e02d4 */ 	lw	$t6,0x2d4($a0)
/*  f1833b0:	8dd3004c */ 	lw	$s3,0x4c($t6)
/*  f1833b4:	00137940 */ 	sll	$t7,$s3,0x5
/*  f1833b8:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1833bc:	000f9fc2 */ 	srl	$s3,$t7,0x1f
/*  f1833c0:	1000000d */ 	b	.L0f1833f8
/*  f1833c4:	00409025 */ 	or	$s2,$v0,$zero
.L0f1833c8:
/*  f1833c8:	0fc44a21 */ 	jal	invHasDataUplink
/*  f1833cc:	00000000 */ 	nop
/*  f1833d0:	0002202b */ 	sltu	$a0,$zero,$v0
/*  f1833d4:	10800005 */ 	beqz	$a0,.L0f1833ec
/*  f1833d8:	00000000 */ 	nop
/*  f1833dc:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f1833e0:	00002025 */ 	or	$a0,$zero,$zero
/*  f1833e4:	38440036 */ 	xori	$a0,$v0,0x36
/*  f1833e8:	2c840001 */ 	sltiu	$a0,$a0,0x1
.L0f1833ec:
/*  f1833ec:	3c12800a */ 	lui	$s2,%hi(g_Vars+0x28c)
/*  f1833f0:	00809825 */ 	or	$s3,$a0,$zero
/*  f1833f4:	8e52a24c */ 	lw	$s2,%lo(g_Vars+0x28c)($s2)
.L0f1833f8:
/*  f1833f8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1833fc:	3c11800b */ 	lui	$s1,%hi(g_ScenarioData)
/*  f183400:	3c15800b */ 	lui	$s5,%hi(g_ScenarioData)
/*  f183404:	4481a000 */ 	mtc1	$at,$f20
/*  f183408:	26b5c110 */ 	addiu	$s5,$s5,%lo(g_ScenarioData)
/*  f18340c:	2631c110 */ 	addiu	$s1,$s1,%lo(g_ScenarioData)
/*  f183410:	00008025 */ 	or	$s0,$zero,$zero
.L0f183414:
/*  f183414:	8e240080 */ 	lw	$a0,0x80($s1)
/*  f183418:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f18341c:	50800061 */ 	beqzl	$a0,.L0f1835a4
/*  f183420:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f183424:	12800005 */ 	beqz	$s4,.L0f18343c
/*  f183428:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f18342c:	1260000b */ 	beqz	$s3,.L0f18345c
/*  f183430:	00000000 */ 	nop
/*  f183434:	10000009 */ 	b	.L0f18345c
/*  f183438:	02402825 */ 	or	$a1,$s2,$zero
.L0f18343c:
/*  f18343c:	8c620040 */ 	lw	$v0,0x40($v1)
/*  f183440:	3c01f000 */ 	lui	$at,0xf000
/*  f183444:	30594000 */ 	andi	$t9,$v0,0x4000
/*  f183448:	13200004 */ 	beqz	$t9,.L0f18345c
/*  f18344c:	00000000 */ 	nop
/*  f183450:	00412824 */ 	and	$a1,$v0,$at
/*  f183454:	00054702 */ 	srl	$t0,$a1,0x1c
/*  f183458:	01002825 */ 	or	$a1,$t0,$zero
.L0f18345c:
/*  f18345c:	56450051 */ 	bnel	$s2,$a1,.L0f1835a4
/*  f183460:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f183464:	8c690040 */ 	lw	$t1,0x40($v1)
/*  f183468:	2401bfff */ 	addiu	$at,$zero,-16385
/*  f18346c:	3c0d800b */ 	lui	$t5,%hi(g_ScenarioData+0xd4)
/*  f183470:	01215024 */ 	and	$t2,$t1,$at
/*  f183474:	3c010fff */ 	lui	$at,0xfff
/*  f183478:	3421ffff */ 	ori	$at,$at,0xffff
/*  f18347c:	ac6a0040 */ 	sw	$t2,0x40($v1)
/*  f183480:	01416024 */ 	and	$t4,$t2,$at
/*  f183484:	1260002e */ 	beqz	$s3,.L0f183540
/*  f183488:	ac6c0040 */ 	sw	$t4,0x40($v1)
/*  f18348c:	8dadc1e4 */ 	lw	$t5,%lo(g_ScenarioData+0xd4)($t5)
/*  f183490:	2401ffff */ 	addiu	$at,$zero,-1
/*  f183494:	00127080 */ 	sll	$t6,$s2,0x2
/*  f183498:	15a10041 */ 	bne	$t5,$at,.L0f1835a0
/*  f18349c:	02ae7821 */ 	addu	$t7,$s5,$t6
/*  f1834a0:	3c01800b */ 	lui	$at,%hi(g_ScenarioData)
/*  f1834a4:	ac30c1e4 */ 	sw	$s0,%lo(g_ScenarioData+0xd4)($at)
/*  f1834a8:	a432c1e0 */ 	sh	$s2,%lo(g_ScenarioData+0xd0)($at)
/*  f1834ac:	a432c1e2 */ 	sh	$s2,%lo(g_ScenarioData+0xd2)($at)
/*  f1834b0:	1680003b */ 	bnez	$s4,.L0f1835a0
/*  f1834b4:	ade00108 */ 	sw	$zero,0x108($t7)
/*  f1834b8:	0fc5b9f1 */ 	jal	langGet
/*  f1834bc:	24045412 */ 	addiu	$a0,$zero,0x5412
/*  f1834c0:	00402025 */ 	or	$a0,$v0,$zero
/*  f1834c4:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1834c8:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f1834cc:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1834d0:	3c18800b */ 	lui	$t8,%hi(g_ScenarioData+0xd4)
/*  f1834d4:	8f18c1e4 */ 	lw	$t8,%lo(g_ScenarioData+0xd4)($t8)
/*  f1834d8:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f1834dc:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f1834e0:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1834e4:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f1834e8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1834ec:	02b94021 */ 	addu	$t0,$s5,$t9
/*  f1834f0:	8d050080 */ 	lw	$a1,0x80($t0)
/*  f1834f4:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f1834f8:	240cffff */ 	addiu	$t4,$zero,-1
/*  f1834fc:	afac002c */ 	sw	$t4,0x2c($sp)
/*  f183500:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f183504:	e7b40038 */ 	swc1	$f20,0x38($sp)
/*  f183508:	e7b40034 */ 	swc1	$f20,0x34($sp)
/*  f18350c:	e7b40030 */ 	swc1	$f20,0x30($sp)
/*  f183510:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f183514:	e7b40024 */ 	swc1	$f20,0x24($sp)
/*  f183518:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f18351c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f183520:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f183524:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f183528:	00002025 */ 	or	$a0,$zero,$zero
/*  f18352c:	240601bf */ 	addiu	$a2,$zero,0x1bf
/*  f183530:	0fc24e7e */ 	jal	func0f0939f8
/*  f183534:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f183538:	1000001a */ 	b	.L0f1835a4
/*  f18353c:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f183540:
/*  f183540:	56800018 */ 	bnezl	$s4,.L0f1835a4
/*  f183544:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f183548:	0fc5b9f1 */ 	jal	langGet
/*  f18354c:	24045413 */ 	addiu	$a0,$zero,0x5413
/*  f183550:	00402025 */ 	or	$a0,$v0,$zero
/*  f183554:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f183558:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f18355c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f183560:	3c013f80 */ 	lui	$at,0x3f80
/*  f183564:	44812000 */ 	mtc1	$at,$f4
/*  f183568:	240d01cc */ 	addiu	$t5,$zero,0x1cc
/*  f18356c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f183570:	240fffff */ 	addiu	$t7,$zero,-1
/*  f183574:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f183578:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f18357c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f183580:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f183584:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f183588:	00002025 */ 	or	$a0,$zero,$zero
/*  f18358c:	00002825 */ 	or	$a1,$zero,$zero
/*  f183590:	24067fff */ 	addiu	$a2,$zero,0x7fff
/*  f183594:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f183598:	0c0041c6 */ 	jal	snd00010718
/*  f18359c:	e7a40014 */ 	swc1	$f4,0x14($sp)
.L0f1835a0:
/*  f1835a0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1835a4:
/*  f1835a4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1835a8:	1601ff9a */ 	bne	$s0,$at,.L0f183414
/*  f1835ac:	2631000c */ 	addiu	$s1,$s1,0xc
/*  f1835b0:	3c19800b */ 	lui	$t9,%hi(g_ScenarioData+0xd0)
/*  f1835b4:	8739c1e0 */ 	lh	$t9,%lo(g_ScenarioData+0xd0)($t9)
/*  f1835b8:	3c08800b */ 	lui	$t0,%hi(g_ScenarioData+0xd4)
/*  f1835bc:	565900f1 */ 	bnel	$s2,$t9,.L0f183984
/*  f1835c0:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f1835c4:	8d08c1e4 */ 	lw	$t0,%lo(g_ScenarioData+0xd4)($t0)
/*  f1835c8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1835cc:	00125880 */ 	sll	$t3,$s2,0x2
/*  f1835d0:	110100eb */ 	beq	$t0,$at,.L0f183980
/*  f1835d4:	00084880 */ 	sll	$t1,$t0,0x2
/*  f1835d8:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1835dc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1835e0:	02a95021 */ 	addu	$t2,$s5,$t1
/*  f1835e4:	8d510080 */ 	lw	$s1,0x80($t2)
/*  f1835e8:	02ab9821 */ 	addu	$s3,$s5,$t3
/*  f1835ec:	266c0108 */ 	addiu	$t4,$s3,0x108
/*  f1835f0:	afac006c */ 	sw	$t4,0x6c($sp)
/*  f1835f4:	12800011 */ 	beqz	$s4,.L0f18363c
/*  f1835f8:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f1835fc:	8e90001c */ 	lw	$s0,0x1c($s4)
/*  f183600:	02802025 */ 	or	$a0,$s4,$zero
/*  f183604:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f183608:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f18360c:	3c017f1c */ 	lui	$at,%hi(var7f1b8958)
/*  f183610:	c4268958 */ 	lwc1	$f6,%lo(var7f1b8958)($at)
/*  f183614:	3c017f1c */ 	lui	$at,%hi(var7f1b895c)
/*  f183618:	c42a895c */ 	lwc1	$f10,%lo(var7f1b895c)($at)
/*  f18361c:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f183620:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f183624:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f183628:	8e8d02d4 */ 	lw	$t5,0x2d4($s4)
/*  f18362c:	8da30020 */ 	lw	$v1,0x20($t5)
/*  f183630:	386e0001 */ 	xori	$t6,$v1,0x1
/*  f183634:	1000000b */ 	b	.L0f183664
/*  f183638:	2dc30001 */ 	sltiu	$v1,$t6,0x1
.L0f18363c:
/*  f18363c:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f183640:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f183644:	00002025 */ 	or	$a0,$zero,$zero
/*  f183648:	8c5000bc */ 	lw	$s0,0xbc($v0)
/*  f18364c:	c4460144 */ 	lwc1	$f6,0x144($v0)
/*  f183650:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f183654:	0fc2866a */ 	jal	bgunGetWeaponNum
/*  f183658:	e7a60098 */ 	swc1	$f6,0x98($sp)
/*  f18365c:	38430036 */ 	xori	$v1,$v0,0x36
/*  f183660:	2c630001 */ 	sltiu	$v1,$v1,0x1
.L0f183664:
/*  f183664:	c6280000 */ 	lwc1	$f8,0x0($s1)
/*  f183668:	c60a0000 */ 	lwc1	$f10,0x0($s0)
/*  f18366c:	c6240004 */ 	lwc1	$f4,0x4($s1)
/*  f183670:	c6060004 */ 	lwc1	$f6,0x4($s0)
/*  f183674:	460a4501 */ 	sub.s	$f20,$f8,$f10
/*  f183678:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f18367c:	c6280008 */ 	lwc1	$f8,0x8($s1)
/*  f183680:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f183684:	4614a102 */ 	mul.s	$f4,$f20,$f20
/*  f183688:	afa30078 */ 	sw	$v1,0x78($sp)
/*  f18368c:	460a4381 */ 	sub.s	$f14,$f8,$f10
/*  f183690:	e7a20080 */ 	swc1	$f2,0x80($sp)
/*  f183694:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f183698:	e7ae0084 */ 	swc1	$f14,0x84($sp)
/*  f18369c:	0c012974 */ 	jal	sqrtf
/*  f1836a0:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f1836a4:	c7a20080 */ 	lwc1	$f2,0x80($sp)
/*  f1836a8:	44804000 */ 	mtc1	$zero,$f8
/*  f1836ac:	8fa30078 */ 	lw	$v1,0x78($sp)
/*  f1836b0:	c7ae0084 */ 	lwc1	$f14,0x84($sp)
/*  f1836b4:	4602403c */ 	c.lt.s	$f8,$f2
/*  f1836b8:	46000486 */ 	mov.s	$f18,$f0
/*  f1836bc:	4600a306 */ 	mov.s	$f12,$f20
/*  f1836c0:	45020004 */ 	bc1fl	.L0f1836d4
/*  f1836c4:	46001407 */ 	neg.s	$f16,$f2
/*  f1836c8:	10000002 */ 	b	.L0f1836d4
/*  f1836cc:	46001406 */ 	mov.s	$f16,$f2
/*  f1836d0:	46001407 */ 	neg.s	$f16,$f2
.L0f1836d4:
/*  f1836d4:	afa30078 */ 	sw	$v1,0x78($sp)
/*  f1836d8:	e7b0008c */ 	swc1	$f16,0x8c($sp)
/*  f1836dc:	0fc259d4 */ 	jal	atan2f
/*  f1836e0:	e7b20090 */ 	swc1	$f18,0x90($sp)
/*  f1836e4:	3c014334 */ 	lui	$at,0x4334
/*  f1836e8:	44816000 */ 	mtc1	$at,$f12
/*  f1836ec:	3c017f1c */ 	lui	$at,%hi(var7f1b8960)
/*  f1836f0:	c42a8960 */ 	lwc1	$f10,%lo(var7f1b8960)($at)
/*  f1836f4:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f1836f8:	44804000 */ 	mtc1	$zero,$f8
/*  f1836fc:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f183700:	8fa30078 */ 	lw	$v1,0x78($sp)
/*  f183704:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*  f183708:	c7b20090 */ 	lwc1	$f18,0x90($sp)
/*  f18370c:	3c0143b4 */ 	lui	$at,0x43b4
/*  f183710:	46062080 */ 	add.s	$f2,$f4,$f6
/*  f183714:	460c103c */ 	c.lt.s	$f2,$f12
/*  f183718:	00000000 */ 	nop
/*  f18371c:	45020009 */ 	bc1fl	.L0f183744
/*  f183720:	4602603c */ 	c.lt.s	$f12,$f2
/*  f183724:	44810000 */ 	mtc1	$at,$f0
/*  f183728:	00000000 */ 	nop
/*  f18372c:	46001080 */ 	add.s	$f2,$f2,$f0
.L0f183730:
/*  f183730:	460c103c */ 	c.lt.s	$f2,$f12
/*  f183734:	00000000 */ 	nop
/*  f183738:	4503fffd */ 	bc1tl	.L0f183730
/*  f18373c:	46001080 */ 	add.s	$f2,$f2,$f0
/*  f183740:	4602603c */ 	c.lt.s	$f12,$f2
.L0f183744:
/*  f183744:	3c0143b4 */ 	lui	$at,0x43b4
/*  f183748:	44810000 */ 	mtc1	$at,$f0
/*  f18374c:	3c01437a */ 	lui	$at,0x437a
/*  f183750:	45020007 */ 	bc1fl	.L0f183770
/*  f183754:	4602403c */ 	c.lt.s	$f8,$f2
/*  f183758:	46001081 */ 	sub.s	$f2,$f2,$f0
.L0f18375c:
/*  f18375c:	4602603c */ 	c.lt.s	$f12,$f2
/*  f183760:	00000000 */ 	nop
/*  f183764:	4503fffd */ 	bc1tl	.L0f18375c
/*  f183768:	46001081 */ 	sub.s	$f2,$f2,$f0
/*  f18376c:	4602403c */ 	c.lt.s	$f8,$f2
.L0f183770:
/*  f183770:	44810000 */ 	mtc1	$at,$f0
/*  f183774:	3c014348 */ 	lui	$at,0x4348
/*  f183778:	45030003 */ 	bc1tl	.L0f183788
/*  f18377c:	4612003c */ 	c.lt.s	$f0,$f18
/*  f183780:	46001087 */ 	neg.s	$f2,$f2
/*  f183784:	4612003c */ 	c.lt.s	$f0,$f18
.L0f183788:
/*  f183788:	00000000 */ 	nop
/*  f18378c:	45030010 */ 	bc1tl	.L0f1837d0
/*  f183790:	4600903c */ 	c.lt.s	$f18,$f0
/*  f183794:	44815000 */ 	mtc1	$at,$f10
/*  f183798:	3c014234 */ 	lui	$at,0x4234
/*  f18379c:	4610503c */ 	c.lt.s	$f10,$f16
/*  f1837a0:	00000000 */ 	nop
/*  f1837a4:	4503000a */ 	bc1tl	.L0f1837d0
/*  f1837a8:	4600903c */ 	c.lt.s	$f18,$f0
/*  f1837ac:	44812000 */ 	mtc1	$at,$f4
/*  f1837b0:	00000000 */ 	nop
/*  f1837b4:	4602203c */ 	c.lt.s	$f4,$f2
/*  f1837b8:	00000000 */ 	nop
/*  f1837bc:	45030004 */ 	bc1tl	.L0f1837d0
/*  f1837c0:	4600903c */ 	c.lt.s	$f18,$f0
/*  f1837c4:	1460003a */ 	bnez	$v1,.L0f1838b0
/*  f1837c8:	8fa2006c */ 	lw	$v0,0x6c($sp)
/*  f1837cc:	4600903c */ 	c.lt.s	$f18,$f0
.L0f1837d0:
/*  f1837d0:	3c014348 */ 	lui	$at,0x4348
/*  f1837d4:	240fffff */ 	addiu	$t7,$zero,-1
/*  f1837d8:	45000009 */ 	bc1f	.L0f183800
/*  f1837dc:	00000000 */ 	nop
/*  f1837e0:	44813000 */ 	mtc1	$at,$f6
/*  f1837e4:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0xd2)
/*  f1837e8:	4606803c */ 	c.lt.s	$f16,$f6
/*  f1837ec:	00000000 */ 	nop
/*  f1837f0:	45000003 */ 	bc1f	.L0f183800
/*  f1837f4:	00000000 */ 	nop
/*  f1837f8:	10000003 */ 	b	.L0f183808
/*  f1837fc:	a432c1e2 */ 	sh	$s2,%lo(g_ScenarioData+0xd2)($at)
.L0f183800:
/*  f183800:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0xd2)
/*  f183804:	a42fc1e2 */ 	sh	$t7,%lo(g_ScenarioData+0xd2)($at)
.L0f183808:
/*  f183808:	16800021 */ 	bnez	$s4,.L0f183890
/*  f18380c:	00000000 */ 	nop
/*  f183810:	0fc5b9f1 */ 	jal	langGet
/*  f183814:	24045411 */ 	addiu	$a0,$zero,0x5411
/*  f183818:	00402025 */ 	or	$a0,$v0,$zero
/*  f18381c:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f183820:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f183824:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f183828:	3c18800b */ 	lui	$t8,%hi(g_ScenarioData+0xd4)
/*  f18382c:	8f18c1e4 */ 	lw	$t8,%lo(g_ScenarioData+0xd4)($t8)
/*  f183830:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f183834:	3406ffff */ 	dli	$a2,0xffff
/*  f183838:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f18383c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f183840:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f183844:	02b94021 */ 	addu	$t0,$s5,$t9
/*  f183848:	0fc249af */ 	jal	func0f0926bc
/*  f18384c:	8d040080 */ 	lw	$a0,0x80($t0)
/*  f183850:	3c013f80 */ 	lui	$at,0x3f80
/*  f183854:	44814000 */ 	mtc1	$at,$f8
/*  f183858:	240901cc */ 	addiu	$t1,$zero,0x1cc
/*  f18385c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f183860:	240bffff */ 	addiu	$t3,$zero,-1
/*  f183864:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f183868:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f18386c:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f183870:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f183874:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f183878:	00002025 */ 	or	$a0,$zero,$zero
/*  f18387c:	00002825 */ 	or	$a1,$zero,$zero
/*  f183880:	24067fff */ 	addiu	$a2,$zero,0x7fff
/*  f183884:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f183888:	0c0041c6 */ 	jal	snd00010718
/*  f18388c:	e7a80014 */ 	swc1	$f8,0x14($sp)
.L0f183890:
/*  f183890:	3c01800b */ 	lui	$at,%hi(g_ScenarioData)
/*  f183894:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f183898:	240dffff */ 	addiu	$t5,$zero,-1
/*  f18389c:	240effff */ 	addiu	$t6,$zero,-1
/*  f1838a0:	ac2dc1e4 */ 	sw	$t5,%lo(g_ScenarioData+0xd4)($at)
/*  f1838a4:	a42ec1e0 */ 	sh	$t6,%lo(g_ScenarioData+0xd0)($at)
/*  f1838a8:	10000035 */ 	b	.L0f183980
/*  f1838ac:	ade00000 */ 	sw	$zero,0x0($t7)
.L0f1838b0:
/*  f1838b0:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x34)
/*  f1838b4:	8f399ff4 */ 	lw	$t9,%lo(g_Vars+0x34)($t9)
/*  f1838b8:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f1838bc:	03194021 */ 	addu	$t0,$t8,$t9
/*  f1838c0:	290112c1 */ 	slti	$at,$t0,0x12c1
/*  f1838c4:	1420002e */ 	bnez	$at,.L0f183980
/*  f1838c8:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f1838cc:	8e6a00d8 */ 	lw	$t2,0xd8($s3)
/*  f1838d0:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0xd2)
/*  f1838d4:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f1838d8:	ae6b00d8 */ 	sw	$t3,0xd8($s3)
/*  f1838dc:	16800022 */ 	bnez	$s4,.L0f183968
/*  f1838e0:	a432c1e2 */ 	sh	$s2,%lo(g_ScenarioData+0xd2)($at)
/*  f1838e4:	0fc5b9f1 */ 	jal	langGet
/*  f1838e8:	24045410 */ 	addiu	$a0,$zero,0x5410
/*  f1838ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f1838f0:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1838f4:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f1838f8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1838fc:	3c0c800b */ 	lui	$t4,%hi(g_ScenarioData+0xd4)
/*  f183900:	8d8cc1e4 */ 	lw	$t4,%lo(g_ScenarioData+0xd4)($t4)
/*  f183904:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f183908:	3406ffff */ 	dli	$a2,0xffff
/*  f18390c:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f183910:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f183914:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f183918:	02ad7021 */ 	addu	$t6,$s5,$t5
/*  f18391c:	0fc249af */ 	jal	func0f0926bc
/*  f183920:	8dc40080 */ 	lw	$a0,0x80($t6)
/*  f183924:	3c013f80 */ 	lui	$at,0x3f80
/*  f183928:	44815000 */ 	mtc1	$at,$f10
/*  f18392c:	240f01c1 */ 	addiu	$t7,$zero,0x1c1
/*  f183930:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f183934:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f183938:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f18393c:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f183940:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f183944:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f183948:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f18394c:	00002025 */ 	or	$a0,$zero,$zero
/*  f183950:	00002825 */ 	or	$a1,$zero,$zero
/*  f183954:	24067fff */ 	addiu	$a2,$zero,0x7fff
/*  f183958:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f18395c:	0c0041c6 */ 	jal	snd00010718
/*  f183960:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f183964:	8fa2006c */ 	lw	$v0,0x6c($sp)
.L0f183968:
/*  f183968:	3c01800b */ 	lui	$at,%hi(g_ScenarioData)
/*  f18396c:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f183970:	240affff */ 	addiu	$t2,$zero,-1
/*  f183974:	ac29c1e4 */ 	sw	$t1,%lo(g_ScenarioData+0xd4)($at)
/*  f183978:	a42ac1e0 */ 	sh	$t2,%lo(g_ScenarioData+0xd0)($at)
/*  f18397c:	ac400000 */ 	sw	$zero,0x0($v0)
.L0f183980:
/*  f183980:	8fbf0064 */ 	lw	$ra,0x64($sp)
.L0f183984:
/*  f183984:	d7b40040 */ 	ldc1	$f20,0x40($sp)
/*  f183988:	8fb0004c */ 	lw	$s0,0x4c($sp)
/*  f18398c:	8fb10050 */ 	lw	$s1,0x50($sp)
/*  f183990:	8fb20054 */ 	lw	$s2,0x54($sp)
/*  f183994:	8fb30058 */ 	lw	$s3,0x58($sp)
/*  f183998:	8fb4005c */ 	lw	$s4,0x5c($sp)
/*  f18399c:	8fb50060 */ 	lw	$s5,0x60($sp)
/*  f1839a0:	03e00008 */ 	jr	$ra
/*  f1839a4:	27bd00c0 */ 	addiu	$sp,$sp,0xc0
);
#endif

Gfx *scenarioHtmRenderHud(Gfx *gdl)
{
	struct scenariodata_htm *data = &g_ScenarioData.htm;
	s32 sp60;
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

	sp60 = data->unk108[g_Vars.currentplayernum];

	if (data->unk0d4 != -1 && g_Vars.currentplayernum == data->unk0d0) {
		viewleft = viGetViewLeft();
		viewright = viGetViewLeft() + viGetViewWidth();
		viewtop = viGetViewTop();
		t6 = (viewleft + viewright) / 2;
		a1 = viGetViewWidth() / 3;
		barleft = t6 - a1 / 2;
		barright = t6 + a1 / 2;
		s1 = barleft + (s32) (a1 * (sp60 / PALDOWN(4800.0f)));

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
		*score += g_ScenarioData.htm.unk0d8[index] * 2;
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

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel chrGiveBriefcase
/*  f18789c:	27bdfed8 */ 	addiu	$sp,$sp,-296
/*  f1878a0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f1878a4:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f1878a8:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f1878ac:	afa40128 */ 	sw	$a0,0x128($sp)
/*  f1878b0:	afa5012c */ 	sw	$a1,0x12c($sp)
/*  f1878b4:	3c03800b */ 	lui	$v1,0x800b
/*  f1878b8:	8ca20004 */ 	lw	$v0,0x4($a1)
/*  f1878bc:	9063d138 */ 	lbu	$v1,-0x2ec8($v1)
/*  f1878c0:	24010001 */ 	li	$at,0x1
/*  f1878c4:	afa20124 */ 	sw	$v0,0x124($sp)
/*  f1878c8:	146100a5 */ 	bne	$v1,$at,.PF0f187b60
/*  f1878cc:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f1878d0:	8c98001c */ 	lw	$t8,0x1c($a0)
/*  f1878d4:	3c01800b */ 	lui	$at,0x800b
/*  f1878d8:	3c11800a */ 	lui	$s1,0x800a
/*  f1878dc:	ac38c6b4 */ 	sw	$t8,-0x394c($at)
/*  f1878e0:	8c9902d4 */ 	lw	$t9,0x2d4($a0)
/*  f1878e4:	2631a510 */ 	addiu	$s1,$s1,-23280
/*  f1878e8:	53200017 */ 	beqzl	$t9,.PF0f187948
/*  f1878ec:	8e39028c */ 	lw	$t9,0x28c($s1)
/*  f1878f0:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f1878f4:	00000000 */ 	nop
/*  f1878f8:	00025080 */ 	sll	$t2,$v0,0x2
/*  f1878fc:	3c0b800b */ 	lui	$t3,0x800b
/*  f187900:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f187904:	8d6bcaa0 */ 	lw	$t3,-0x3560($t3)
/*  f187908:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f18790c:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f187910:	afab0050 */ 	sw	$t3,0x50($sp)
/*  f187914:	0fc21f5f */ 	jal	propPlayPickupSound
/*  f187918:	9185005c */ 	lbu	$a1,0x5c($t4)
/*  f18791c:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f187920:	24050057 */ 	li	$a1,0x57
/*  f187924:	8c8302d4 */ 	lw	$v1,0x2d4($a0)
/*  f187928:	906e009c */ 	lbu	$t6,0x9c($v1)
/*  f18792c:	35d80080 */ 	ori	$t8,$t6,0x80
/*  f187930:	0fc663e3 */ 	jal	botinvGiveSingleWeapon
/*  f187934:	a078009c */ 	sb	$t8,0x9c($v1)
/*  f187938:	3c11800a */ 	lui	$s1,0x800a
/*  f18793c:	10000020 */ 	b	.PF0f1879c0
/*  f187940:	2631a510 */ 	addiu	$s1,$s1,-23280
/*  f187944:	8e39028c */ 	lw	$t9,0x28c($s1)
.PF0f187948:
/*  f187948:	3c0c800b */ 	lui	$t4,0x800b
/*  f18794c:	258ccd58 */ 	addiu	$t4,$t4,-12968
/*  f187950:	001979c0 */ 	sll	$t7,$t9,0x7
/*  f187954:	022f5021 */ 	addu	$t2,$s1,$t7
/*  f187958:	8d4200e4 */ 	lw	$v0,0xe4($t2)
/*  f18795c:	3c19800b */ 	lui	$t9,0x800b
/*  f187960:	2739cad8 */ 	addiu	$t9,$t9,-13608
/*  f187964:	28410004 */ 	slti	$at,$v0,0x4
/*  f187968:	10200007 */ 	beqz	$at,.PF0f187988
/*  f18796c:	00027080 */ 	sll	$t6,$v0,0x2
/*  f187970:	00025880 */ 	sll	$t3,$v0,0x2
/*  f187974:	01625821 */ 	addu	$t3,$t3,$v0
/*  f187978:	000b5940 */ 	sll	$t3,$t3,0x5
/*  f18797c:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f187980:	10000008 */ 	b	.PF0f1879a4
/*  f187984:	afad0050 */ 	sw	$t5,0x50($sp)
.PF0f187988:
/*  f187988:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f18798c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f187990:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f187994:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f187998:	25d8fed0 */ 	addiu	$t8,$t6,-304
/*  f18799c:	03197821 */ 	addu	$t7,$t8,$t9
/*  f1879a0:	afaf0050 */ 	sw	$t7,0x50($sp)
.PF0f1879a4:
/*  f1879a4:	0fc44a1a */ 	jal	invGiveSingleWeapon
/*  f1879a8:	24040057 */ 	li	$a0,0x57
/*  f1879ac:	24040057 */ 	li	$a0,0x57
/*  f1879b0:	0fc221bd */ 	jal	currentPlayerQueuePickupWeaponHudmsg
/*  f1879b4:	00002825 */ 	move	$a1,$zero
/*  f1879b8:	0fc21fa0 */ 	jal	weaponPlayPickupSound
/*  f1879bc:	24040057 */ 	li	$a0,0x57
.PF0f1879c0:
/*  f1879c0:	0fc5bdaa */ 	jal	langGet
/*  f1879c4:	24045401 */ 	li	$a0,0x5401
/*  f1879c8:	24040057 */ 	li	$a0,0x57
/*  f1879cc:	0fc28941 */ 	jal	bgunGetShortName
/*  f1879d0:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f1879d4:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f1879d8:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f1879dc:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f1879e0:	0c004d11 */ 	jal	sprintf
/*  f1879e4:	00403825 */ 	move	$a3,$v0
/*  f1879e8:	8e29006c */ 	lw	$t1,0x6c($s1)
/*  f1879ec:	8e2a028c */ 	lw	$t2,0x28c($s1)
/*  f1879f0:	00008025 */ 	move	$s0,$zero
/*  f1879f4:	11200003 */ 	beqz	$t1,.PF0f187a04
/*  f1879f8:	afaa0118 */ 	sw	$t2,0x118($sp)
/*  f1879fc:	10000002 */ 	b	.PF0f187a08
/*  f187a00:	24040001 */ 	li	$a0,0x1
.PF0f187a04:
/*  f187a04:	00002025 */ 	move	$a0,$zero
.PF0f187a08:
/*  f187a08:	8e280068 */ 	lw	$t0,0x68($s1)
/*  f187a0c:	00001825 */ 	move	$v1,$zero
/*  f187a10:	00002825 */ 	move	$a1,$zero
/*  f187a14:	11000003 */ 	beqz	$t0,.PF0f187a24
/*  f187a18:	00001025 */ 	move	$v0,$zero
/*  f187a1c:	10000001 */ 	b	.PF0f187a24
/*  f187a20:	24030001 */ 	li	$v1,0x1
.PF0f187a24:
/*  f187a24:	8e270064 */ 	lw	$a3,0x64($s1)
/*  f187a28:	10e00003 */ 	beqz	$a3,.PF0f187a38
/*  f187a2c:	00000000 */ 	nop
/*  f187a30:	10000001 */ 	b	.PF0f187a38
/*  f187a34:	24050001 */ 	li	$a1,0x1
.PF0f187a38:
/*  f187a38:	8e260070 */ 	lw	$a2,0x70($s1)
/*  f187a3c:	10c00003 */ 	beqz	$a2,.PF0f187a4c
/*  f187a40:	00000000 */ 	nop
/*  f187a44:	10000001 */ 	b	.PF0f187a4c
/*  f187a48:	24020001 */ 	li	$v0,0x1
.PF0f187a4c:
/*  f187a4c:	00455821 */ 	addu	$t3,$v0,$a1
/*  f187a50:	01636021 */ 	addu	$t4,$t3,$v1
/*  f187a54:	01846821 */ 	addu	$t5,$t4,$a0
/*  f187a58:	19a0002d */ 	blez	$t5,.PF0f187b10
/*  f187a5c:	00000000 */ 	nop
/*  f187a60:	8fae0128 */ 	lw	$t6,0x128($sp)
.PF0f187a64:
/*  f187a64:	8fb90118 */ 	lw	$t9,0x118($sp)
/*  f187a68:	8dd802d4 */ 	lw	$t8,0x2d4($t6)
/*  f187a6c:	17000003 */ 	bnez	$t8,.PF0f187a7c
/*  f187a70:	00000000 */ 	nop
/*  f187a74:	1219000f */ 	beq	$s0,$t9,.PF0f187ab4
/*  f187a78:	00000000 */ 	nop
.PF0f187a7c:
/*  f187a7c:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f187a80:	02002025 */ 	move	$a0,$s0
/*  f187a84:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f187a88:	24050009 */ 	li	$a1,0x9
/*  f187a8c:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f187a90:	24060001 */ 	li	$a2,0x1
/*  f187a94:	3c09800a */ 	lui	$t1,0x800a
/*  f187a98:	3c08800a */ 	lui	$t0,0x800a
/*  f187a9c:	3c07800a */ 	lui	$a3,0x800a
/*  f187aa0:	3c06800a */ 	lui	$a2,0x800a
/*  f187aa4:	8cc6a580 */ 	lw	$a2,-0x5a80($a2)
/*  f187aa8:	8ce7a574 */ 	lw	$a3,-0x5a8c($a3)
/*  f187aac:	8d08a578 */ 	lw	$t0,-0x5a88($t0)
/*  f187ab0:	8d29a57c */ 	lw	$t1,-0x5a84($t1)
.PF0f187ab4:
/*  f187ab4:	11200003 */ 	beqz	$t1,.PF0f187ac4
/*  f187ab8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f187abc:	10000002 */ 	b	.PF0f187ac8
/*  f187ac0:	24040001 */ 	li	$a0,0x1
.PF0f187ac4:
/*  f187ac4:	00002025 */ 	move	$a0,$zero
.PF0f187ac8:
/*  f187ac8:	11000003 */ 	beqz	$t0,.PF0f187ad8
/*  f187acc:	00001825 */ 	move	$v1,$zero
/*  f187ad0:	10000001 */ 	b	.PF0f187ad8
/*  f187ad4:	24030001 */ 	li	$v1,0x1
.PF0f187ad8:
/*  f187ad8:	10e00003 */ 	beqz	$a3,.PF0f187ae8
/*  f187adc:	00002825 */ 	move	$a1,$zero
/*  f187ae0:	10000001 */ 	b	.PF0f187ae8
/*  f187ae4:	24050001 */ 	li	$a1,0x1
.PF0f187ae8:
/*  f187ae8:	10c00003 */ 	beqz	$a2,.PF0f187af8
/*  f187aec:	00001025 */ 	move	$v0,$zero
/*  f187af0:	10000001 */ 	b	.PF0f187af8
/*  f187af4:	24020001 */ 	li	$v0,0x1
.PF0f187af8:
/*  f187af8:	00457821 */ 	addu	$t7,$v0,$a1
/*  f187afc:	01e35021 */ 	addu	$t2,$t7,$v1
/*  f187b00:	01445821 */ 	addu	$t3,$t2,$a0
/*  f187b04:	020b082a */ 	slt	$at,$s0,$t3
/*  f187b08:	5420ffd6 */ 	bnezl	$at,.PF0f187a64
/*  f187b0c:	8fae0128 */ 	lw	$t6,0x128($sp)
.PF0f187b10:
/*  f187b10:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f187b14:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f187b18:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f187b1c:	8fa30124 */ 	lw	$v1,0x124($sp)
/*  f187b20:	8fa40124 */ 	lw	$a0,0x124($sp)
/*  f187b24:	8d8d02d4 */ 	lw	$t5,0x2d4($t4)
/*  f187b28:	51a00007 */ 	beqzl	$t5,.PF0f187b48
/*  f187b2c:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f187b30:	8c6e0040 */ 	lw	$t6,0x40($v1)
/*  f187b34:	00001025 */ 	move	$v0,$zero
/*  f187b38:	35d80004 */ 	ori	$t8,$t6,0x4
/*  f187b3c:	100001b6 */ 	b	.PF0f188218
/*  f187b40:	ac780040 */ 	sw	$t8,0x40($v1)
/*  f187b44:	90860002 */ 	lbu	$a2,0x2($a0)
.PF0f187b48:
/*  f187b48:	00002825 */ 	move	$a1,$zero
/*  f187b4c:	30cf0004 */ 	andi	$t7,$a2,0x4
/*  f187b50:	0fc1abed */ 	jal	objFree
/*  f187b54:	01e03025 */ 	move	$a2,$t7
/*  f187b58:	100001af */ 	b	.PF0f188218
/*  f187b5c:	24020001 */ 	li	$v0,0x1
.PF0f187b60:
/*  f187b60:	24010005 */ 	li	$at,0x5
/*  f187b64:	146101a6 */ 	bne	$v1,$at,.PF0f188200
/*  f187b68:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f187b6c:	8faa0128 */ 	lw	$t2,0x128($sp)
/*  f187b70:	3c11800a */ 	lui	$s1,0x800a
/*  f187b74:	2631a510 */ 	addiu	$s1,$s1,-23280
/*  f187b78:	8d4302d4 */ 	lw	$v1,0x2d4($t2)
/*  f187b7c:	5060000e */ 	beqzl	$v1,.PF0f187bb8
/*  f187b80:	8e2e028c */ 	lw	$t6,0x28c($s1)
/*  f187b84:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f187b88:	01402025 */ 	move	$a0,$t2
/*  f187b8c:	00025880 */ 	sll	$t3,$v0,0x2
/*  f187b90:	3c0c800b */ 	lui	$t4,0x800b
/*  f187b94:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f187b98:	8d8ccaa0 */ 	lw	$t4,-0x3560($t4)
/*  f187b9c:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f187ba0:	3c11800a */ 	lui	$s1,0x800a
/*  f187ba4:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f187ba8:	2631a510 */ 	addiu	$s1,$s1,-23280
/*  f187bac:	10000019 */ 	b	.PF0f187c14
/*  f187bb0:	8da302d4 */ 	lw	$v1,0x2d4($t5)
/*  f187bb4:	8e2e028c */ 	lw	$t6,0x28c($s1)
.PF0f187bb8:
/*  f187bb8:	3c0a800b */ 	lui	$t2,0x800b
/*  f187bbc:	254acd58 */ 	addiu	$t2,$t2,-12968
/*  f187bc0:	000ec1c0 */ 	sll	$t8,$t6,0x7
/*  f187bc4:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f187bc8:	8f2200e4 */ 	lw	$v0,0xe4($t9)
/*  f187bcc:	3c0e800b */ 	lui	$t6,0x800b
/*  f187bd0:	25cecad8 */ 	addiu	$t6,$t6,-13608
/*  f187bd4:	28410004 */ 	slti	$at,$v0,0x4
/*  f187bd8:	10200007 */ 	beqz	$at,.PF0f187bf8
/*  f187bdc:	00026080 */ 	sll	$t4,$v0,0x2
/*  f187be0:	00027880 */ 	sll	$t7,$v0,0x2
/*  f187be4:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f187be8:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f187bec:	01ea5821 */ 	addu	$t3,$t7,$t2
/*  f187bf0:	10000008 */ 	b	.PF0f187c14
/*  f187bf4:	afab0050 */ 	sw	$t3,0x50($sp)
.PF0f187bf8:
/*  f187bf8:	01826021 */ 	addu	$t4,$t4,$v0
/*  f187bfc:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f187c00:	01826023 */ 	subu	$t4,$t4,$v0
/*  f187c04:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f187c08:	258dfed0 */ 	addiu	$t5,$t4,-304
/*  f187c0c:	01aec021 */ 	addu	$t8,$t5,$t6
/*  f187c10:	afb80050 */ 	sw	$t8,0x50($sp)
.PF0f187c14:
/*  f187c14:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f187c18:	8faa0120 */ 	lw	$t2,0x120($sp)
/*  f187c1c:	932f0011 */ 	lbu	$t7,0x11($t9)
/*  f187c20:	854b0062 */ 	lh	$t3,0x62($t2)
/*  f187c24:	15eb00bc */ 	bne	$t7,$t3,.PF0f187f18
/*  f187c28:	00000000 */ 	nop
/*  f187c2c:	10600005 */ 	beqz	$v1,.PF0f187c44
/*  f187c30:	00000000 */ 	nop
/*  f187c34:	8c6c009c */ 	lw	$t4,0x9c($v1)
/*  f187c38:	000c7040 */ 	sll	$t6,$t4,0x1
/*  f187c3c:	05c20008 */ 	bltzl	$t6,.PF0f187c60
/*  f187c40:	8fb80050 */ 	lw	$t8,0x50($sp)
.PF0f187c44:
/*  f187c44:	546000ad */ 	bnezl	$v1,.PF0f187efc
/*  f187c48:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f187c4c:	0fc44cc9 */ 	jal	invHasBriefcase
/*  f187c50:	00000000 */ 	nop
/*  f187c54:	504000a9 */ 	beqzl	$v0,.PF0f187efc
/*  f187c58:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f187c5c:	8fb80050 */ 	lw	$t8,0x50($sp)
.PF0f187c60:
/*  f187c60:	3c02800b */ 	lui	$v0,0x800b
/*  f187c64:	2442c6b0 */ 	addiu	$v0,$v0,-14672
/*  f187c68:	8719003e */ 	lh	$t9,0x3e($t8)
/*  f187c6c:	00008025 */ 	move	$s0,$zero
/*  f187c70:	272a0001 */ 	addiu	$t2,$t9,0x1
/*  f187c74:	a70a003e */ 	sh	$t2,0x3e($t8)
/*  f187c78:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f187c7c:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f187c80:	8de3001c */ 	lw	$v1,0x1c($t7)
.PF0f187c84:
/*  f187c84:	8c4b0058 */ 	lw	$t3,0x58($v0)
/*  f187c88:	506b0006 */ 	beql	$v1,$t3,.PF0f187ca4
/*  f187c8c:	8d8d02d4 */ 	lw	$t5,0x2d4($t4)
/*  f187c90:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f187c94:	2a010004 */ 	slti	$at,$s0,0x4
/*  f187c98:	1420fffa */ 	bnez	$at,.PF0f187c84
/*  f187c9c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f187ca0:	8d8d02d4 */ 	lw	$t5,0x2d4($t4)
.PF0f187ca4:
/*  f187ca4:	11a00009 */ 	beqz	$t5,.PF0f187ccc
/*  f187ca8:	01802025 */ 	move	$a0,$t4
/*  f187cac:	0fc66aa1 */ 	jal	botinvDropOne
/*  f187cb0:	24050057 */ 	li	$a1,0x57
/*  f187cb4:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f187cb8:	8dc302d4 */ 	lw	$v1,0x2d4($t6)
/*  f187cbc:	9079009c */ 	lbu	$t9,0x9c($v1)
/*  f187cc0:	332affbf */ 	andi	$t2,$t9,0xffbf
/*  f187cc4:	10000014 */ 	b	.PF0f187d18
/*  f187cc8:	a06a009c */ 	sb	$t2,0x9c($v1)
.PF0f187ccc:
/*  f187ccc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f187cd0:	44812000 */ 	mtc1	$at,$f4
/*  f187cd4:	3c048009 */ 	lui	$a0,0x8009
/*  f187cd8:	2418ffff */ 	li	$t8,-1
/*  f187cdc:	240fffff */ 	li	$t7,-1
/*  f187ce0:	240bffff */ 	li	$t3,-1
/*  f187ce4:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f187ce8:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f187cec:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f187cf0:	8c845750 */ 	lw	$a0,0x5750($a0)
/*  f187cf4:	240505b8 */ 	li	$a1,0x5b8
/*  f187cf8:	00003025 */ 	move	$a2,$zero
/*  f187cfc:	2407ffff */ 	li	$a3,-1
/*  f187d00:	0c0041a0 */ 	jal	sndStart
/*  f187d04:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f187d08:	0fc24454 */ 	jal	weaponCreateForPlayerDrop
/*  f187d0c:	24040057 */ 	li	$a0,0x57
/*  f187d10:	0fc44a61 */ 	jal	invRemoveItemByNum
/*  f187d14:	24040057 */ 	li	$a0,0x57
.PF0f187d18:
/*  f187d18:	0fc5bdaa */ 	jal	langGet
/*  f187d1c:	24045405 */ 	li	$a0,0x5405
/*  f187d20:	00106880 */ 	sll	$t5,$s0,0x2
/*  f187d24:	01b06823 */ 	subu	$t5,$t5,$s0
/*  f187d28:	3c0c800b */ 	lui	$t4,0x800b
/*  f187d2c:	258cd150 */ 	addiu	$t4,$t4,-11952
/*  f187d30:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f187d34:	01ac3021 */ 	addu	$a2,$t5,$t4
/*  f187d38:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f187d3c:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f187d40:	0c004d11 */ 	jal	sprintf
/*  f187d44:	00402825 */ 	move	$a1,$v0
/*  f187d48:	0fc5bdaa */ 	jal	langGet
/*  f187d4c:	24045406 */ 	li	$a0,0x5406
/*  f187d50:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f187d54:	00402825 */ 	move	$a1,$v0
/*  f187d58:	0c004d11 */ 	jal	sprintf
/*  f187d5c:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f187d60:	0fc5bdaa */ 	jal	langGet
/*  f187d64:	24045407 */ 	li	$a0,0x5407
/*  f187d68:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f187d6c:	00402825 */ 	move	$a1,$v0
/*  f187d70:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f187d74:	0c004d11 */ 	jal	sprintf
/*  f187d78:	8fa7003c */ 	lw	$a3,0x3c($sp)
/*  f187d7c:	8e39006c */ 	lw	$t9,0x6c($s1)
/*  f187d80:	8e2e028c */ 	lw	$t6,0x28c($s1)
/*  f187d84:	afb00114 */ 	sw	$s0,0x114($sp)
/*  f187d88:	00008025 */ 	move	$s0,$zero
/*  f187d8c:	13200003 */ 	beqz	$t9,.PF0f187d9c
/*  f187d90:	afae0118 */ 	sw	$t6,0x118($sp)
/*  f187d94:	10000002 */ 	b	.PF0f187da0
/*  f187d98:	24040001 */ 	li	$a0,0x1
.PF0f187d9c:
/*  f187d9c:	00002025 */ 	move	$a0,$zero
.PF0f187da0:
/*  f187da0:	8e2a0068 */ 	lw	$t2,0x68($s1)
/*  f187da4:	00001825 */ 	move	$v1,$zero
/*  f187da8:	00002825 */ 	move	$a1,$zero
/*  f187dac:	11400003 */ 	beqz	$t2,.PF0f187dbc
/*  f187db0:	00001025 */ 	move	$v0,$zero
/*  f187db4:	10000001 */ 	b	.PF0f187dbc
/*  f187db8:	24030001 */ 	li	$v1,0x1
.PF0f187dbc:
/*  f187dbc:	8e380064 */ 	lw	$t8,0x64($s1)
/*  f187dc0:	13000003 */ 	beqz	$t8,.PF0f187dd0
/*  f187dc4:	00000000 */ 	nop
/*  f187dc8:	10000001 */ 	b	.PF0f187dd0
/*  f187dcc:	24050001 */ 	li	$a1,0x1
.PF0f187dd0:
/*  f187dd0:	8e2f0070 */ 	lw	$t7,0x70($s1)
/*  f187dd4:	11e00003 */ 	beqz	$t7,.PF0f187de4
/*  f187dd8:	00000000 */ 	nop
/*  f187ddc:	10000001 */ 	b	.PF0f187de4
/*  f187de0:	24020001 */ 	li	$v0,0x1
.PF0f187de4:
/*  f187de4:	00455821 */ 	addu	$t3,$v0,$a1
/*  f187de8:	01636821 */ 	addu	$t5,$t3,$v1
/*  f187dec:	01a46021 */ 	addu	$t4,$t5,$a0
/*  f187df0:	1980003f */ 	blez	$t4,.PF0f187ef0
/*  f187df4:	00000000 */ 	nop
.PF0f187df8:
/*  f187df8:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f187dfc:	02002025 */ 	move	$a0,$s0
/*  f187e00:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f187e04:	00107880 */ 	sll	$t7,$s0,0x2
/*  f187e08:	3c0b800b */ 	lui	$t3,0x800b
/*  f187e0c:	8dd902d4 */ 	lw	$t9,0x2d4($t6)
/*  f187e10:	8faa0118 */ 	lw	$t2,0x118($sp)
/*  f187e14:	016f5821 */ 	addu	$t3,$t3,$t7
/*  f187e18:	17200008 */ 	bnez	$t9,.PF0f187e3c
/*  f187e1c:	00000000 */ 	nop
/*  f187e20:	160a0006 */ 	bne	$s0,$t2,.PF0f187e3c
/*  f187e24:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f187e28:	24050009 */ 	li	$a1,0x9
/*  f187e2c:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f187e30:	24060001 */ 	li	$a2,0x1
/*  f187e34:	10000011 */ 	b	.PF0f187e7c
/*  f187e38:	8e2c006c */ 	lw	$t4,0x6c($s1)
.PF0f187e3c:
/*  f187e3c:	8d6bcaa0 */ 	lw	$t3,-0x3560($t3)
/*  f187e40:	8fb80114 */ 	lw	$t8,0x114($sp)
/*  f187e44:	24060001 */ 	li	$a2,0x1
/*  f187e48:	916d0011 */ 	lbu	$t5,0x11($t3)
/*  f187e4c:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f187e50:	24050009 */ 	li	$a1,0x9
/*  f187e54:	170d0006 */ 	bne	$t8,$t5,.PF0f187e70
/*  f187e58:	00000000 */ 	nop
/*  f187e5c:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f187e60:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f187e64:	24050009 */ 	li	$a1,0x9
/*  f187e68:	10000004 */ 	b	.PF0f187e7c
/*  f187e6c:	8e2c006c */ 	lw	$t4,0x6c($s1)
.PF0f187e70:
/*  f187e70:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f187e74:	24060001 */ 	li	$a2,0x1
/*  f187e78:	8e2c006c */ 	lw	$t4,0x6c($s1)
.PF0f187e7c:
/*  f187e7c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f187e80:	00002025 */ 	move	$a0,$zero
/*  f187e84:	11800003 */ 	beqz	$t4,.PF0f187e94
/*  f187e88:	00001825 */ 	move	$v1,$zero
/*  f187e8c:	10000001 */ 	b	.PF0f187e94
/*  f187e90:	24040001 */ 	li	$a0,0x1
.PF0f187e94:
/*  f187e94:	8e2e0068 */ 	lw	$t6,0x68($s1)
/*  f187e98:	00002825 */ 	move	$a1,$zero
/*  f187e9c:	00001025 */ 	move	$v0,$zero
/*  f187ea0:	11c00003 */ 	beqz	$t6,.PF0f187eb0
/*  f187ea4:	00000000 */ 	nop
/*  f187ea8:	10000001 */ 	b	.PF0f187eb0
/*  f187eac:	24030001 */ 	li	$v1,0x1
.PF0f187eb0:
/*  f187eb0:	8e390064 */ 	lw	$t9,0x64($s1)
/*  f187eb4:	13200003 */ 	beqz	$t9,.PF0f187ec4
/*  f187eb8:	00000000 */ 	nop
/*  f187ebc:	10000001 */ 	b	.PF0f187ec4
/*  f187ec0:	24050001 */ 	li	$a1,0x1
.PF0f187ec4:
/*  f187ec4:	8e2a0070 */ 	lw	$t2,0x70($s1)
/*  f187ec8:	11400003 */ 	beqz	$t2,.PF0f187ed8
/*  f187ecc:	00000000 */ 	nop
/*  f187ed0:	10000001 */ 	b	.PF0f187ed8
/*  f187ed4:	24020001 */ 	li	$v0,0x1
.PF0f187ed8:
/*  f187ed8:	00457821 */ 	addu	$t7,$v0,$a1
/*  f187edc:	01e35821 */ 	addu	$t3,$t7,$v1
/*  f187ee0:	0164c021 */ 	addu	$t8,$t3,$a0
/*  f187ee4:	0218082a */ 	slt	$at,$s0,$t8
/*  f187ee8:	1420ffc3 */ 	bnez	$at,.PF0f187df8
/*  f187eec:	00000000 */ 	nop
.PF0f187ef0:
/*  f187ef0:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f187ef4:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f187ef8:	8fad0128 */ 	lw	$t5,0x128($sp)
.PF0f187efc:
/*  f187efc:	8dac02d4 */ 	lw	$t4,0x2d4($t5)
/*  f187f00:	11800003 */ 	beqz	$t4,.PF0f187f10
/*  f187f04:	00000000 */ 	nop
/*  f187f08:	100000c3 */ 	b	.PF0f188218
/*  f187f0c:	00001025 */ 	move	$v0,$zero
.PF0f187f10:
/*  f187f10:	100000c1 */ 	b	.PF0f188218
/*  f187f14:	00001025 */ 	move	$v0,$zero
.PF0f187f18:
/*  f187f18:	10600005 */ 	beqz	$v1,.PF0f187f30
/*  f187f1c:	00000000 */ 	nop
/*  f187f20:	8c6e009c */ 	lw	$t6,0x9c($v1)
/*  f187f24:	000e5040 */ 	sll	$t2,$t6,0x1
/*  f187f28:	05410008 */ 	bgez	$t2,.PF0f187f4c
/*  f187f2c:	00000000 */ 	nop
.PF0f187f30:
/*  f187f30:	546000ac */ 	bnezl	$v1,.PF0f1881e4
/*  f187f34:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f187f38:	0fc44cc9 */ 	jal	invHasBriefcase
/*  f187f3c:	00000000 */ 	nop
/*  f187f40:	144000a7 */ 	bnez	$v0,.PF0f1881e0
/*  f187f44:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f187f48:	8de302d4 */ 	lw	$v1,0x2d4($t7)
.PF0f187f4c:
/*  f187f4c:	50600009 */ 	beqzl	$v1,.PF0f187f74
/*  f187f50:	8faa0120 */ 	lw	$t2,0x120($sp)
/*  f187f54:	9078009c */ 	lbu	$t8,0x9c($v1)
/*  f187f58:	370d0040 */ 	ori	$t5,$t8,0x40
/*  f187f5c:	a06d009c */ 	sb	$t5,0x9c($v1)
/*  f187f60:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f187f64:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f187f68:	0fc21f5f */ 	jal	propPlayPickupSound
/*  f187f6c:	9185005c */ 	lbu	$a1,0x5c($t4)
/*  f187f70:	8faa0120 */ 	lw	$t2,0x120($sp)
.PF0f187f74:
/*  f187f74:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f187f78:	3c01800b */ 	lui	$at,0x800b
/*  f187f7c:	854f0062 */ 	lh	$t7,0x62($t2)
/*  f187f80:	8dd9001c */ 	lw	$t9,0x1c($t6)
/*  f187f84:	24045402 */ 	li	$a0,0x5402
/*  f187f88:	000f5880 */ 	sll	$t3,$t7,0x2
/*  f187f8c:	002b0821 */ 	addu	$at,$at,$t3
/*  f187f90:	0fc5bdaa */ 	jal	langGet
/*  f187f94:	ac39c708 */ 	sw	$t9,-0x38f8($at)
/*  f187f98:	8fb80120 */ 	lw	$t8,0x120($sp)
/*  f187f9c:	3c10800b */ 	lui	$s0,0x800b
/*  f187fa0:	2610d150 */ 	addiu	$s0,$s0,-11952
/*  f187fa4:	870d0062 */ 	lh	$t5,0x62($t8)
/*  f187fa8:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f187fac:	00402825 */ 	move	$a1,$v0
/*  f187fb0:	000d6080 */ 	sll	$t4,$t5,0x2
/*  f187fb4:	018d6023 */ 	subu	$t4,$t4,$t5
/*  f187fb8:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f187fbc:	020c3821 */ 	addu	$a3,$s0,$t4
/*  f187fc0:	0c004d11 */ 	jal	sprintf
/*  f187fc4:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f187fc8:	0fc5bdaa */ 	jal	langGet
/*  f187fcc:	24045403 */ 	li	$a0,0x5403
/*  f187fd0:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f187fd4:	00402825 */ 	move	$a1,$v0
/*  f187fd8:	0c004d11 */ 	jal	sprintf
/*  f187fdc:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f187fe0:	0fc5bdaa */ 	jal	langGet
/*  f187fe4:	24045404 */ 	li	$a0,0x5404
/*  f187fe8:	8fae0120 */ 	lw	$t6,0x120($sp)
/*  f187fec:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f187ff0:	00402825 */ 	move	$a1,$v0
/*  f187ff4:	85ca0062 */ 	lh	$t2,0x62($t6)
/*  f187ff8:	000a7880 */ 	sll	$t7,$t2,0x2
/*  f187ffc:	01ea7823 */ 	subu	$t7,$t7,$t2
/*  f188000:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f188004:	0c004d11 */ 	jal	sprintf
/*  f188008:	020f3021 */ 	addu	$a2,$s0,$t7
/*  f18800c:	8e2b006c */ 	lw	$t3,0x6c($s1)
/*  f188010:	8e39028c */ 	lw	$t9,0x28c($s1)
/*  f188014:	00008025 */ 	move	$s0,$zero
/*  f188018:	11600003 */ 	beqz	$t3,.PF0f188028
/*  f18801c:	afb90118 */ 	sw	$t9,0x118($sp)
/*  f188020:	10000002 */ 	b	.PF0f18802c
/*  f188024:	24040001 */ 	li	$a0,0x1
.PF0f188028:
/*  f188028:	00002025 */ 	move	$a0,$zero
.PF0f18802c:
/*  f18802c:	8e380068 */ 	lw	$t8,0x68($s1)
/*  f188030:	00001825 */ 	move	$v1,$zero
/*  f188034:	00002825 */ 	move	$a1,$zero
/*  f188038:	13000003 */ 	beqz	$t8,.PF0f188048
/*  f18803c:	00001025 */ 	move	$v0,$zero
/*  f188040:	10000001 */ 	b	.PF0f188048
/*  f188044:	24030001 */ 	li	$v1,0x1
.PF0f188048:
/*  f188048:	8e2d0064 */ 	lw	$t5,0x64($s1)
/*  f18804c:	11a00003 */ 	beqz	$t5,.PF0f18805c
/*  f188050:	00000000 */ 	nop
/*  f188054:	10000001 */ 	b	.PF0f18805c
/*  f188058:	24050001 */ 	li	$a1,0x1
.PF0f18805c:
/*  f18805c:	8e2c0070 */ 	lw	$t4,0x70($s1)
/*  f188060:	11800003 */ 	beqz	$t4,.PF0f188070
/*  f188064:	00000000 */ 	nop
/*  f188068:	10000001 */ 	b	.PF0f188070
/*  f18806c:	24020001 */ 	li	$v0,0x1
.PF0f188070:
/*  f188070:	00457021 */ 	addu	$t6,$v0,$a1
/*  f188074:	01c35021 */ 	addu	$t2,$t6,$v1
/*  f188078:	01447821 */ 	addu	$t7,$t2,$a0
/*  f18807c:	19e0003f */ 	blez	$t7,.PF0f18817c
/*  f188080:	00000000 */ 	nop
.PF0f188084:
/*  f188084:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f188088:	02002025 */ 	move	$a0,$s0
/*  f18808c:	8fb90128 */ 	lw	$t9,0x128($sp)
/*  f188090:	00107080 */ 	sll	$t6,$s0,0x2
/*  f188094:	3c0a800b */ 	lui	$t2,0x800b
/*  f188098:	8f2b02d4 */ 	lw	$t3,0x2d4($t9)
/*  f18809c:	8fb80118 */ 	lw	$t8,0x118($sp)
/*  f1880a0:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f1880a4:	15600008 */ 	bnez	$t3,.PF0f1880c8
/*  f1880a8:	8fad0120 */ 	lw	$t5,0x120($sp)
/*  f1880ac:	16180006 */ 	bne	$s0,$t8,.PF0f1880c8
/*  f1880b0:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f1880b4:	24050009 */ 	li	$a1,0x9
/*  f1880b8:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f1880bc:	24060001 */ 	li	$a2,0x1
/*  f1880c0:	10000011 */ 	b	.PF0f188108
/*  f1880c4:	8e39006c */ 	lw	$t9,0x6c($s1)
.PF0f1880c8:
/*  f1880c8:	8d4acaa0 */ 	lw	$t2,-0x3560($t2)
/*  f1880cc:	85ac0062 */ 	lh	$t4,0x62($t5)
/*  f1880d0:	24060001 */ 	li	$a2,0x1
/*  f1880d4:	914f0011 */ 	lbu	$t7,0x11($t2)
/*  f1880d8:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f1880dc:	24050009 */ 	li	$a1,0x9
/*  f1880e0:	158f0006 */ 	bne	$t4,$t7,.PF0f1880fc
/*  f1880e4:	00000000 */ 	nop
/*  f1880e8:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f1880ec:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f1880f0:	24050009 */ 	li	$a1,0x9
/*  f1880f4:	10000004 */ 	b	.PF0f188108
/*  f1880f8:	8e39006c */ 	lw	$t9,0x6c($s1)
.PF0f1880fc:
/*  f1880fc:	0fc37976 */ 	jal	hudmsgCreateWithFlags
/*  f188100:	24060001 */ 	li	$a2,0x1
/*  f188104:	8e39006c */ 	lw	$t9,0x6c($s1)
.PF0f188108:
/*  f188108:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18810c:	00002025 */ 	move	$a0,$zero
/*  f188110:	13200003 */ 	beqz	$t9,.PF0f188120
/*  f188114:	00001825 */ 	move	$v1,$zero
/*  f188118:	10000001 */ 	b	.PF0f188120
/*  f18811c:	24040001 */ 	li	$a0,0x1
.PF0f188120:
/*  f188120:	8e2b0068 */ 	lw	$t3,0x68($s1)
/*  f188124:	00002825 */ 	move	$a1,$zero
/*  f188128:	00001025 */ 	move	$v0,$zero
/*  f18812c:	11600003 */ 	beqz	$t3,.PF0f18813c
/*  f188130:	00000000 */ 	nop
/*  f188134:	10000001 */ 	b	.PF0f18813c
/*  f188138:	24030001 */ 	li	$v1,0x1
.PF0f18813c:
/*  f18813c:	8e380064 */ 	lw	$t8,0x64($s1)
/*  f188140:	13000003 */ 	beqz	$t8,.PF0f188150
/*  f188144:	00000000 */ 	nop
/*  f188148:	10000001 */ 	b	.PF0f188150
/*  f18814c:	24050001 */ 	li	$a1,0x1
.PF0f188150:
/*  f188150:	8e2d0070 */ 	lw	$t5,0x70($s1)
/*  f188154:	11a00003 */ 	beqz	$t5,.PF0f188164
/*  f188158:	00000000 */ 	nop
/*  f18815c:	10000001 */ 	b	.PF0f188164
/*  f188160:	24020001 */ 	li	$v0,0x1
.PF0f188164:
/*  f188164:	00457021 */ 	addu	$t6,$v0,$a1
/*  f188168:	01c35021 */ 	addu	$t2,$t6,$v1
/*  f18816c:	01446021 */ 	addu	$t4,$t2,$a0
/*  f188170:	020c082a */ 	slt	$at,$s0,$t4
/*  f188174:	1420ffc3 */ 	bnez	$at,.PF0f188084
/*  f188178:	00000000 */ 	nop
.PF0f18817c:
/*  f18817c:	0fc4a4ff */ 	jal	setCurrentPlayerNum
/*  f188180:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f188184:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f188188:	8df902d4 */ 	lw	$t9,0x2d4($t7)
/*  f18818c:	01e02025 */ 	move	$a0,$t7
/*  f188190:	13200009 */ 	beqz	$t9,.PF0f1881b8
/*  f188194:	00000000 */ 	nop
/*  f188198:	0fc663e3 */ 	jal	botinvGiveSingleWeapon
/*  f18819c:	24050057 */ 	li	$a1,0x57
/*  f1881a0:	8fab0124 */ 	lw	$t3,0x124($sp)
/*  f1881a4:	00001025 */ 	move	$v0,$zero
/*  f1881a8:	8d780040 */ 	lw	$t8,0x40($t3)
/*  f1881ac:	370d0004 */ 	ori	$t5,$t8,0x4
/*  f1881b0:	10000019 */ 	b	.PF0f188218
/*  f1881b4:	ad6d0040 */ 	sw	$t5,0x40($t3)
.PF0f1881b8:
/*  f1881b8:	0fc44af4 */ 	jal	invGiveWeaponsByProp
/*  f1881bc:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f1881c0:	8fa40124 */ 	lw	$a0,0x124($sp)
/*  f1881c4:	00002825 */ 	move	$a1,$zero
/*  f1881c8:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f1881cc:	30ca0004 */ 	andi	$t2,$a2,0x4
/*  f1881d0:	0fc1abed */ 	jal	objFree
/*  f1881d4:	01403025 */ 	move	$a2,$t2
/*  f1881d8:	1000000f */ 	b	.PF0f188218
/*  f1881dc:	24020001 */ 	li	$v0,0x1
.PF0f1881e0:
/*  f1881e0:	8fac0128 */ 	lw	$t4,0x128($sp)
.PF0f1881e4:
/*  f1881e4:	8d9902d4 */ 	lw	$t9,0x2d4($t4)
/*  f1881e8:	13200003 */ 	beqz	$t9,.PF0f1881f8
/*  f1881ec:	00000000 */ 	nop
/*  f1881f0:	10000009 */ 	b	.PF0f188218
/*  f1881f4:	00001025 */ 	move	$v0,$zero
.PF0f1881f8:
/*  f1881f8:	10000007 */ 	b	.PF0f188218
/*  f1881fc:	00001025 */ 	move	$v0,$zero
.PF0f188200:
/*  f188200:	8df802d4 */ 	lw	$t8,0x2d4($t7)
/*  f188204:	00001025 */ 	move	$v0,$zero
/*  f188208:	13000003 */ 	beqz	$t8,.PF0f188218
/*  f18820c:	00000000 */ 	nop
/*  f188210:	10000001 */ 	b	.PF0f188218
/*  f188214:	00001025 */ 	move	$v0,$zero
.PF0f188218:
/*  f188218:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f18821c:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f188220:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f188224:	03e00008 */ 	jr	$ra
/*  f188228:	27bd0128 */ 	addiu	$sp,$sp,0x128
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel chrGiveBriefcase
/*  f186898:	27bdfed8 */ 	addiu	$sp,$sp,-296
/*  f18689c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f1868a0:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f1868a4:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f1868a8:	afa40128 */ 	sw	$a0,0x128($sp)
/*  f1868ac:	afa5012c */ 	sw	$a1,0x12c($sp)
/*  f1868b0:	3c03800b */ 	lui	$v1,%hi(g_MpSetup+0x10)
/*  f1868b4:	8ca20004 */ 	lw	$v0,0x4($a1)
/*  f1868b8:	9063cb98 */ 	lbu	$v1,%lo(g_MpSetup+0x10)($v1)
/*  f1868bc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1868c0:	afa20124 */ 	sw	$v0,0x124($sp)
/*  f1868c4:	146100a5 */ 	bne	$v1,$at,.L0f186b5c
/*  f1868c8:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f1868cc:	8c98001c */ 	lw	$t8,0x1c($a0)
/*  f1868d0:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0x4)
/*  f1868d4:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f1868d8:	ac38c114 */ 	sw	$t8,%lo(g_ScenarioData+0x4)($at)
/*  f1868dc:	8c9902d4 */ 	lw	$t9,0x2d4($a0)
/*  f1868e0:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f1868e4:	53200017 */ 	beqzl	$t9,.L0f186944
/*  f1868e8:	8e39028c */ 	lw	$t9,0x28c($s1)
/*  f1868ec:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f1868f0:	00000000 */ 	nop
/*  f1868f4:	00025080 */ 	sll	$t2,$v0,0x2
/*  f1868f8:	3c0b800b */ 	lui	$t3,%hi(g_MpAllChrConfigPtrs)
/*  f1868fc:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f186900:	8d6bc500 */ 	lw	$t3,%lo(g_MpAllChrConfigPtrs)($t3)
/*  f186904:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f186908:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f18690c:	afab0050 */ 	sw	$t3,0x50($sp)
/*  f186910:	0fc21f03 */ 	jal	propPlayPickupSound
/*  f186914:	9185005c */ 	lbu	$a1,0x5c($t4)
/*  f186918:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f18691c:	24050057 */ 	addiu	$a1,$zero,0x57
/*  f186920:	8c8302d4 */ 	lw	$v1,0x2d4($a0)
/*  f186924:	906e009c */ 	lbu	$t6,0x9c($v1)
/*  f186928:	35d80080 */ 	ori	$t8,$t6,0x80
/*  f18692c:	0fc65fa3 */ 	jal	botinvGiveSingleWeapon
/*  f186930:	a078009c */ 	sb	$t8,0x9c($v1)
/*  f186934:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f186938:	10000020 */ 	b	.L0f1869bc
/*  f18693c:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f186940:	8e39028c */ 	lw	$t9,0x28c($s1)
.L0f186944:
/*  f186944:	3c0c800b */ 	lui	$t4,%hi(g_PlayerConfigsArray)
/*  f186948:	258cc7b8 */ 	addiu	$t4,$t4,%lo(g_PlayerConfigsArray)
/*  f18694c:	001979c0 */ 	sll	$t7,$t9,0x7
/*  f186950:	022f5021 */ 	addu	$t2,$s1,$t7
/*  f186954:	8d4200e4 */ 	lw	$v0,0xe4($t2)
/*  f186958:	3c19800b */ 	lui	$t9,%hi(g_BotConfigsArray)
/*  f18695c:	2739c538 */ 	addiu	$t9,$t9,%lo(g_BotConfigsArray)
/*  f186960:	28410004 */ 	slti	$at,$v0,0x4
/*  f186964:	10200007 */ 	beqz	$at,.L0f186984
/*  f186968:	00027080 */ 	sll	$t6,$v0,0x2
/*  f18696c:	00025880 */ 	sll	$t3,$v0,0x2
/*  f186970:	01625821 */ 	addu	$t3,$t3,$v0
/*  f186974:	000b5940 */ 	sll	$t3,$t3,0x5
/*  f186978:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f18697c:	10000008 */ 	b	.L0f1869a0
/*  f186980:	afad0050 */ 	sw	$t5,0x50($sp)
.L0f186984:
/*  f186984:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f186988:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f18698c:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f186990:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f186994:	25d8fed0 */ 	addiu	$t8,$t6,-304
/*  f186998:	03197821 */ 	addu	$t7,$t8,$t9
/*  f18699c:	afaf0050 */ 	sw	$t7,0x50($sp)
.L0f1869a0:
/*  f1869a0:	0fc44762 */ 	jal	invGiveSingleWeapon
/*  f1869a4:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f1869a8:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f1869ac:	0fc221f2 */ 	jal	currentPlayerQueuePickupWeaponHudmsg
/*  f1869b0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1869b4:	0fc21f44 */ 	jal	weaponPlayPickupSound
/*  f1869b8:	24040057 */ 	addiu	$a0,$zero,0x57
.L0f1869bc:
/*  f1869bc:	0fc5b9f1 */ 	jal	langGet
/*  f1869c0:	24045400 */ 	addiu	$a0,$zero,0x5400
/*  f1869c4:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f1869c8:	0fc28874 */ 	jal	bgunGetShortName
/*  f1869cc:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f1869d0:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f1869d4:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f1869d8:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f1869dc:	0c004dad */ 	jal	sprintf
/*  f1869e0:	00403825 */ 	or	$a3,$v0,$zero
/*  f1869e4:	8e29006c */ 	lw	$t1,0x6c($s1)
/*  f1869e8:	8e2a028c */ 	lw	$t2,0x28c($s1)
/*  f1869ec:	00008025 */ 	or	$s0,$zero,$zero
/*  f1869f0:	11200003 */ 	beqz	$t1,.L0f186a00
/*  f1869f4:	afaa0118 */ 	sw	$t2,0x118($sp)
/*  f1869f8:	10000002 */ 	b	.L0f186a04
/*  f1869fc:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f186a00:
/*  f186a00:	00002025 */ 	or	$a0,$zero,$zero
.L0f186a04:
/*  f186a04:	8e280068 */ 	lw	$t0,0x68($s1)
/*  f186a08:	00001825 */ 	or	$v1,$zero,$zero
/*  f186a0c:	00002825 */ 	or	$a1,$zero,$zero
/*  f186a10:	11000003 */ 	beqz	$t0,.L0f186a20
/*  f186a14:	00001025 */ 	or	$v0,$zero,$zero
/*  f186a18:	10000001 */ 	b	.L0f186a20
/*  f186a1c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f186a20:
/*  f186a20:	8e270064 */ 	lw	$a3,0x64($s1)
/*  f186a24:	10e00003 */ 	beqz	$a3,.L0f186a34
/*  f186a28:	00000000 */ 	nop
/*  f186a2c:	10000001 */ 	b	.L0f186a34
/*  f186a30:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f186a34:
/*  f186a34:	8e260070 */ 	lw	$a2,0x70($s1)
/*  f186a38:	10c00003 */ 	beqz	$a2,.L0f186a48
/*  f186a3c:	00000000 */ 	nop
/*  f186a40:	10000001 */ 	b	.L0f186a48
/*  f186a44:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f186a48:
/*  f186a48:	00455821 */ 	addu	$t3,$v0,$a1
/*  f186a4c:	01636021 */ 	addu	$t4,$t3,$v1
/*  f186a50:	01846821 */ 	addu	$t5,$t4,$a0
/*  f186a54:	19a0002d */ 	blez	$t5,.L0f186b0c
/*  f186a58:	00000000 */ 	nop
/*  f186a5c:	8fae0128 */ 	lw	$t6,0x128($sp)
.L0f186a60:
/*  f186a60:	8fb90118 */ 	lw	$t9,0x118($sp)
/*  f186a64:	8dd802d4 */ 	lw	$t8,0x2d4($t6)
/*  f186a68:	17000003 */ 	bnez	$t8,.L0f186a78
/*  f186a6c:	00000000 */ 	nop
/*  f186a70:	1219000f */ 	beq	$s0,$t9,.L0f186ab0
/*  f186a74:	00000000 */ 	nop
.L0f186a78:
/*  f186a78:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f186a7c:	02002025 */ 	or	$a0,$s0,$zero
/*  f186a80:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f186a84:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f186a88:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f186a8c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f186a90:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x6c)
/*  f186a94:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x68)
/*  f186a98:	3c07800a */ 	lui	$a3,%hi(g_Vars+0x64)
/*  f186a9c:	3c06800a */ 	lui	$a2,%hi(g_Vars+0x70)
/*  f186aa0:	8cc6a030 */ 	lw	$a2,%lo(g_Vars+0x70)($a2)
/*  f186aa4:	8ce7a024 */ 	lw	$a3,%lo(g_Vars+0x64)($a3)
/*  f186aa8:	8d08a028 */ 	lw	$t0,%lo(g_Vars+0x68)($t0)
/*  f186aac:	8d29a02c */ 	lw	$t1,%lo(g_Vars+0x6c)($t1)
.L0f186ab0:
/*  f186ab0:	11200003 */ 	beqz	$t1,.L0f186ac0
/*  f186ab4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f186ab8:	10000002 */ 	b	.L0f186ac4
/*  f186abc:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f186ac0:
/*  f186ac0:	00002025 */ 	or	$a0,$zero,$zero
.L0f186ac4:
/*  f186ac4:	11000003 */ 	beqz	$t0,.L0f186ad4
/*  f186ac8:	00001825 */ 	or	$v1,$zero,$zero
/*  f186acc:	10000001 */ 	b	.L0f186ad4
/*  f186ad0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f186ad4:
/*  f186ad4:	10e00003 */ 	beqz	$a3,.L0f186ae4
/*  f186ad8:	00002825 */ 	or	$a1,$zero,$zero
/*  f186adc:	10000001 */ 	b	.L0f186ae4
/*  f186ae0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f186ae4:
/*  f186ae4:	10c00003 */ 	beqz	$a2,.L0f186af4
/*  f186ae8:	00001025 */ 	or	$v0,$zero,$zero
/*  f186aec:	10000001 */ 	b	.L0f186af4
/*  f186af0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f186af4:
/*  f186af4:	00457821 */ 	addu	$t7,$v0,$a1
/*  f186af8:	01e35021 */ 	addu	$t2,$t7,$v1
/*  f186afc:	01445821 */ 	addu	$t3,$t2,$a0
/*  f186b00:	020b082a */ 	slt	$at,$s0,$t3
/*  f186b04:	5420ffd6 */ 	bnezl	$at,.L0f186a60
/*  f186b08:	8fae0128 */ 	lw	$t6,0x128($sp)
.L0f186b0c:
/*  f186b0c:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f186b10:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f186b14:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f186b18:	8fa30124 */ 	lw	$v1,0x124($sp)
/*  f186b1c:	8fa40124 */ 	lw	$a0,0x124($sp)
/*  f186b20:	8d8d02d4 */ 	lw	$t5,0x2d4($t4)
/*  f186b24:	51a00007 */ 	beqzl	$t5,.L0f186b44
/*  f186b28:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f186b2c:	8c6e0040 */ 	lw	$t6,0x40($v1)
/*  f186b30:	00001025 */ 	or	$v0,$zero,$zero
/*  f186b34:	35d80004 */ 	ori	$t8,$t6,0x4
/*  f186b38:	100001ce */ 	b	.L0f187274
/*  f186b3c:	ac780040 */ 	sw	$t8,0x40($v1)
/*  f186b40:	90860002 */ 	lbu	$a2,0x2($a0)
.L0f186b44:
/*  f186b44:	00002825 */ 	or	$a1,$zero,$zero
/*  f186b48:	30cf0004 */ 	andi	$t7,$a2,0x4
/*  f186b4c:	0fc1ab4b */ 	jal	objFree
/*  f186b50:	01e03025 */ 	or	$a2,$t7,$zero
/*  f186b54:	100001c7 */ 	b	.L0f187274
/*  f186b58:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f186b5c:
/*  f186b5c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f186b60:	146101be */ 	bne	$v1,$at,.L0f18725c
/*  f186b64:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f186b68:	8faa0128 */ 	lw	$t2,0x128($sp)
/*  f186b6c:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f186b70:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f186b74:	8d4302d4 */ 	lw	$v1,0x2d4($t2)
/*  f186b78:	5060000e */ 	beqzl	$v1,.L0f186bb4
/*  f186b7c:	8e2e028c */ 	lw	$t6,0x28c($s1)
/*  f186b80:	0fc633fe */ 	jal	mpPlayerGetIndex
/*  f186b84:	01402025 */ 	or	$a0,$t2,$zero
/*  f186b88:	00025880 */ 	sll	$t3,$v0,0x2
/*  f186b8c:	3c0c800b */ 	lui	$t4,%hi(g_MpAllChrConfigPtrs)
/*  f186b90:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f186b94:	8d8cc500 */ 	lw	$t4,%lo(g_MpAllChrConfigPtrs)($t4)
/*  f186b98:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f186b9c:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f186ba0:	afac0050 */ 	sw	$t4,0x50($sp)
/*  f186ba4:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f186ba8:	10000019 */ 	b	.L0f186c10
/*  f186bac:	8da302d4 */ 	lw	$v1,0x2d4($t5)
/*  f186bb0:	8e2e028c */ 	lw	$t6,0x28c($s1)
.L0f186bb4:
/*  f186bb4:	3c0a800b */ 	lui	$t2,%hi(g_PlayerConfigsArray)
/*  f186bb8:	254ac7b8 */ 	addiu	$t2,$t2,%lo(g_PlayerConfigsArray)
/*  f186bbc:	000ec1c0 */ 	sll	$t8,$t6,0x7
/*  f186bc0:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f186bc4:	8f2200e4 */ 	lw	$v0,0xe4($t9)
/*  f186bc8:	3c0e800b */ 	lui	$t6,%hi(g_BotConfigsArray)
/*  f186bcc:	25cec538 */ 	addiu	$t6,$t6,%lo(g_BotConfigsArray)
/*  f186bd0:	28410004 */ 	slti	$at,$v0,0x4
/*  f186bd4:	10200007 */ 	beqz	$at,.L0f186bf4
/*  f186bd8:	00026080 */ 	sll	$t4,$v0,0x2
/*  f186bdc:	00027880 */ 	sll	$t7,$v0,0x2
/*  f186be0:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f186be4:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f186be8:	01ea5821 */ 	addu	$t3,$t7,$t2
/*  f186bec:	10000008 */ 	b	.L0f186c10
/*  f186bf0:	afab0050 */ 	sw	$t3,0x50($sp)
.L0f186bf4:
/*  f186bf4:	01826021 */ 	addu	$t4,$t4,$v0
/*  f186bf8:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f186bfc:	01826023 */ 	subu	$t4,$t4,$v0
/*  f186c00:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f186c04:	258dfed0 */ 	addiu	$t5,$t4,-304
/*  f186c08:	01aec021 */ 	addu	$t8,$t5,$t6
/*  f186c0c:	afb80050 */ 	sw	$t8,0x50($sp)
.L0f186c10:
/*  f186c10:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f186c14:	8faa0120 */ 	lw	$t2,0x120($sp)
/*  f186c18:	932f0011 */ 	lbu	$t7,0x11($t9)
/*  f186c1c:	854b0062 */ 	lh	$t3,0x62($t2)
/*  f186c20:	15eb00c8 */ 	bne	$t7,$t3,.L0f186f44
/*  f186c24:	00000000 */ 	nop
/*  f186c28:	10600005 */ 	beqz	$v1,.L0f186c40
/*  f186c2c:	00000000 */ 	nop
/*  f186c30:	8c6c009c */ 	lw	$t4,0x9c($v1)
/*  f186c34:	000c7040 */ 	sll	$t6,$t4,0x1
/*  f186c38:	05c20008 */ 	bltzl	$t6,.L0f186c5c
/*  f186c3c:	8fb80050 */ 	lw	$t8,0x50($sp)
.L0f186c40:
/*  f186c40:	546000b9 */ 	bnezl	$v1,.L0f186f28
/*  f186c44:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f186c48:	0fc44a11 */ 	jal	invHasBriefcase
/*  f186c4c:	00000000 */ 	nop
/*  f186c50:	504000b5 */ 	beqzl	$v0,.L0f186f28
/*  f186c54:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f186c58:	8fb80050 */ 	lw	$t8,0x50($sp)
.L0f186c5c:
/*  f186c5c:	3c02800b */ 	lui	$v0,%hi(g_ScenarioData)
/*  f186c60:	2442c110 */ 	addiu	$v0,$v0,%lo(g_ScenarioData)
/*  f186c64:	8719003e */ 	lh	$t9,0x3e($t8)
/*  f186c68:	00008025 */ 	or	$s0,$zero,$zero
/*  f186c6c:	272a0001 */ 	addiu	$t2,$t9,0x1
/*  f186c70:	a70a003e */ 	sh	$t2,0x3e($t8)
/*  f186c74:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f186c78:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f186c7c:	8de3001c */ 	lw	$v1,0x1c($t7)
.L0f186c80:
/*  f186c80:	8c4b0058 */ 	lw	$t3,0x58($v0)
/*  f186c84:	506b0006 */ 	beql	$v1,$t3,.L0f186ca0
/*  f186c88:	8d8d02d4 */ 	lw	$t5,0x2d4($t4)
/*  f186c8c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f186c90:	2a010004 */ 	slti	$at,$s0,0x4
/*  f186c94:	1420fffa */ 	bnez	$at,.L0f186c80
/*  f186c98:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f186c9c:	8d8d02d4 */ 	lw	$t5,0x2d4($t4)
.L0f186ca0:
/*  f186ca0:	11a00009 */ 	beqz	$t5,.L0f186cc8
/*  f186ca4:	01802025 */ 	or	$a0,$t4,$zero
/*  f186ca8:	0fc66661 */ 	jal	botinvDropOne
/*  f186cac:	24050057 */ 	addiu	$a1,$zero,0x57
/*  f186cb0:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f186cb4:	8dc302d4 */ 	lw	$v1,0x2d4($t6)
/*  f186cb8:	9079009c */ 	lbu	$t9,0x9c($v1)
/*  f186cbc:	332affbf */ 	andi	$t2,$t9,0xffbf
/*  f186cc0:	10000014 */ 	b	.L0f186d14
/*  f186cc4:	a06a009c */ 	sb	$t2,0x9c($v1)
.L0f186cc8:
/*  f186cc8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f186ccc:	44812000 */ 	mtc1	$at,$f4
/*  f186cd0:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f186cd4:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f186cd8:	240fffff */ 	addiu	$t7,$zero,-1
/*  f186cdc:	240bffff */ 	addiu	$t3,$zero,-1
/*  f186ce0:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f186ce4:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f186ce8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f186cec:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f186cf0:	240505b8 */ 	addiu	$a1,$zero,0x5b8
/*  f186cf4:	00003025 */ 	or	$a2,$zero,$zero
/*  f186cf8:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f186cfc:	0c004241 */ 	jal	sndStart
/*  f186d00:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f186d04:	0fc24494 */ 	jal	weaponCreateForPlayerDrop
/*  f186d08:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f186d0c:	0fc447a9 */ 	jal	invRemoveItemByNum
/*  f186d10:	24040057 */ 	addiu	$a0,$zero,0x57
.L0f186d14:
/*  f186d14:	0fc5b9f1 */ 	jal	langGet
/*  f186d18:	24045404 */ 	addiu	$a0,$zero,0x5404
/*  f186d1c:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f186d20:	0fc28874 */ 	jal	bgunGetShortName
/*  f186d24:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f186d28:	00106880 */ 	sll	$t5,$s0,0x2
/*  f186d2c:	01b06823 */ 	subu	$t5,$t5,$s0
/*  f186d30:	3c0c800b */ 	lui	$t4,%hi(g_MpSetup+0x28)
/*  f186d34:	258ccbb0 */ 	addiu	$t4,$t4,%lo(g_MpSetup+0x28)
/*  f186d38:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f186d3c:	01ac3021 */ 	addu	$a2,$t5,$t4
/*  f186d40:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f186d44:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f186d48:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f186d4c:	0c004dad */ 	jal	sprintf
/*  f186d50:	00403825 */ 	or	$a3,$v0,$zero
/*  f186d54:	0fc5b9f1 */ 	jal	langGet
/*  f186d58:	24045405 */ 	addiu	$a0,$zero,0x5405
/*  f186d5c:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f186d60:	0fc28874 */ 	jal	bgunGetShortName
/*  f186d64:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f186d68:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f186d6c:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f186d70:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f186d74:	0c004dad */ 	jal	sprintf
/*  f186d78:	00403825 */ 	or	$a3,$v0,$zero
/*  f186d7c:	0fc5b9f1 */ 	jal	langGet
/*  f186d80:	24045406 */ 	addiu	$a0,$zero,0x5406
/*  f186d84:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f186d88:	0fc28874 */ 	jal	bgunGetShortName
/*  f186d8c:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f186d90:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f186d94:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f186d98:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f186d9c:	8fa7003c */ 	lw	$a3,0x3c($sp)
/*  f186da0:	0c004dad */ 	jal	sprintf
/*  f186da4:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f186da8:	8e39006c */ 	lw	$t9,0x6c($s1)
/*  f186dac:	8e2e028c */ 	lw	$t6,0x28c($s1)
/*  f186db0:	afb00114 */ 	sw	$s0,0x114($sp)
/*  f186db4:	00008025 */ 	or	$s0,$zero,$zero
/*  f186db8:	13200003 */ 	beqz	$t9,.L0f186dc8
/*  f186dbc:	afae0118 */ 	sw	$t6,0x118($sp)
/*  f186dc0:	10000002 */ 	b	.L0f186dcc
/*  f186dc4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f186dc8:
/*  f186dc8:	00002025 */ 	or	$a0,$zero,$zero
.L0f186dcc:
/*  f186dcc:	8e2a0068 */ 	lw	$t2,0x68($s1)
/*  f186dd0:	00001825 */ 	or	$v1,$zero,$zero
/*  f186dd4:	00002825 */ 	or	$a1,$zero,$zero
/*  f186dd8:	11400003 */ 	beqz	$t2,.L0f186de8
/*  f186ddc:	00001025 */ 	or	$v0,$zero,$zero
/*  f186de0:	10000001 */ 	b	.L0f186de8
/*  f186de4:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f186de8:
/*  f186de8:	8e380064 */ 	lw	$t8,0x64($s1)
/*  f186dec:	13000003 */ 	beqz	$t8,.L0f186dfc
/*  f186df0:	00000000 */ 	nop
/*  f186df4:	10000001 */ 	b	.L0f186dfc
/*  f186df8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f186dfc:
/*  f186dfc:	8e2f0070 */ 	lw	$t7,0x70($s1)
/*  f186e00:	11e00003 */ 	beqz	$t7,.L0f186e10
/*  f186e04:	00000000 */ 	nop
/*  f186e08:	10000001 */ 	b	.L0f186e10
/*  f186e0c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f186e10:
/*  f186e10:	00455821 */ 	addu	$t3,$v0,$a1
/*  f186e14:	01636821 */ 	addu	$t5,$t3,$v1
/*  f186e18:	01a46021 */ 	addu	$t4,$t5,$a0
/*  f186e1c:	1980003f */ 	blez	$t4,.L0f186f1c
/*  f186e20:	00000000 */ 	nop
.L0f186e24:
/*  f186e24:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f186e28:	02002025 */ 	or	$a0,$s0,$zero
/*  f186e2c:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f186e30:	00107880 */ 	sll	$t7,$s0,0x2
/*  f186e34:	3c0b800b */ 	lui	$t3,%hi(g_MpAllChrConfigPtrs)
/*  f186e38:	8dd902d4 */ 	lw	$t9,0x2d4($t6)
/*  f186e3c:	8faa0118 */ 	lw	$t2,0x118($sp)
/*  f186e40:	016f5821 */ 	addu	$t3,$t3,$t7
/*  f186e44:	17200008 */ 	bnez	$t9,.L0f186e68
/*  f186e48:	00000000 */ 	nop
/*  f186e4c:	160a0006 */ 	bne	$s0,$t2,.L0f186e68
/*  f186e50:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f186e54:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f186e58:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f186e5c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f186e60:	10000011 */ 	b	.L0f186ea8
/*  f186e64:	8e2c006c */ 	lw	$t4,0x6c($s1)
.L0f186e68:
/*  f186e68:	8d6bc500 */ 	lw	$t3,%lo(g_MpAllChrConfigPtrs)($t3)
/*  f186e6c:	8fb80114 */ 	lw	$t8,0x114($sp)
/*  f186e70:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f186e74:	916d0011 */ 	lbu	$t5,0x11($t3)
/*  f186e78:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f186e7c:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f186e80:	170d0006 */ 	bne	$t8,$t5,.L0f186e9c
/*  f186e84:	00000000 */ 	nop
/*  f186e88:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f186e8c:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f186e90:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f186e94:	10000004 */ 	b	.L0f186ea8
/*  f186e98:	8e2c006c */ 	lw	$t4,0x6c($s1)
.L0f186e9c:
/*  f186e9c:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f186ea0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f186ea4:	8e2c006c */ 	lw	$t4,0x6c($s1)
.L0f186ea8:
/*  f186ea8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f186eac:	00002025 */ 	or	$a0,$zero,$zero
/*  f186eb0:	11800003 */ 	beqz	$t4,.L0f186ec0
/*  f186eb4:	00001825 */ 	or	$v1,$zero,$zero
/*  f186eb8:	10000001 */ 	b	.L0f186ec0
/*  f186ebc:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f186ec0:
/*  f186ec0:	8e2e0068 */ 	lw	$t6,0x68($s1)
/*  f186ec4:	00002825 */ 	or	$a1,$zero,$zero
/*  f186ec8:	00001025 */ 	or	$v0,$zero,$zero
/*  f186ecc:	11c00003 */ 	beqz	$t6,.L0f186edc
/*  f186ed0:	00000000 */ 	nop
/*  f186ed4:	10000001 */ 	b	.L0f186edc
/*  f186ed8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f186edc:
/*  f186edc:	8e390064 */ 	lw	$t9,0x64($s1)
/*  f186ee0:	13200003 */ 	beqz	$t9,.L0f186ef0
/*  f186ee4:	00000000 */ 	nop
/*  f186ee8:	10000001 */ 	b	.L0f186ef0
/*  f186eec:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f186ef0:
/*  f186ef0:	8e2a0070 */ 	lw	$t2,0x70($s1)
/*  f186ef4:	11400003 */ 	beqz	$t2,.L0f186f04
/*  f186ef8:	00000000 */ 	nop
/*  f186efc:	10000001 */ 	b	.L0f186f04
/*  f186f00:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f186f04:
/*  f186f04:	00457821 */ 	addu	$t7,$v0,$a1
/*  f186f08:	01e35821 */ 	addu	$t3,$t7,$v1
/*  f186f0c:	0164c021 */ 	addu	$t8,$t3,$a0
/*  f186f10:	0218082a */ 	slt	$at,$s0,$t8
/*  f186f14:	1420ffc3 */ 	bnez	$at,.L0f186e24
/*  f186f18:	00000000 */ 	nop
.L0f186f1c:
/*  f186f1c:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f186f20:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f186f24:	8fad0128 */ 	lw	$t5,0x128($sp)
.L0f186f28:
/*  f186f28:	8dac02d4 */ 	lw	$t4,0x2d4($t5)
/*  f186f2c:	11800003 */ 	beqz	$t4,.L0f186f3c
/*  f186f30:	00000000 */ 	nop
/*  f186f34:	100000cf */ 	b	.L0f187274
/*  f186f38:	00001025 */ 	or	$v0,$zero,$zero
.L0f186f3c:
/*  f186f3c:	100000cd */ 	b	.L0f187274
/*  f186f40:	00001025 */ 	or	$v0,$zero,$zero
.L0f186f44:
/*  f186f44:	10600005 */ 	beqz	$v1,.L0f186f5c
/*  f186f48:	00000000 */ 	nop
/*  f186f4c:	8c6e009c */ 	lw	$t6,0x9c($v1)
/*  f186f50:	000e5040 */ 	sll	$t2,$t6,0x1
/*  f186f54:	05410008 */ 	bgez	$t2,.L0f186f78
/*  f186f58:	00000000 */ 	nop
.L0f186f5c:
/*  f186f5c:	546000b8 */ 	bnezl	$v1,.L0f187240
/*  f186f60:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f186f64:	0fc44a11 */ 	jal	invHasBriefcase
/*  f186f68:	00000000 */ 	nop
/*  f186f6c:	144000b3 */ 	bnez	$v0,.L0f18723c
/*  f186f70:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f186f74:	8de302d4 */ 	lw	$v1,0x2d4($t7)
.L0f186f78:
/*  f186f78:	50600009 */ 	beqzl	$v1,.L0f186fa0
/*  f186f7c:	8faa0120 */ 	lw	$t2,0x120($sp)
/*  f186f80:	9078009c */ 	lbu	$t8,0x9c($v1)
/*  f186f84:	370d0040 */ 	ori	$t5,$t8,0x40
/*  f186f88:	a06d009c */ 	sb	$t5,0x9c($v1)
/*  f186f8c:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f186f90:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f186f94:	0fc21f03 */ 	jal	propPlayPickupSound
/*  f186f98:	9185005c */ 	lbu	$a1,0x5c($t4)
/*  f186f9c:	8faa0120 */ 	lw	$t2,0x120($sp)
.L0f186fa0:
/*  f186fa0:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f186fa4:	3c01800b */ 	lui	$at,%hi(g_ScenarioData+0x58)
/*  f186fa8:	854f0062 */ 	lh	$t7,0x62($t2)
/*  f186fac:	8dd9001c */ 	lw	$t9,0x1c($t6)
/*  f186fb0:	24045401 */ 	addiu	$a0,$zero,0x5401
/*  f186fb4:	000f5880 */ 	sll	$t3,$t7,0x2
/*  f186fb8:	002b0821 */ 	addu	$at,$at,$t3
/*  f186fbc:	0fc5b9f1 */ 	jal	langGet
/*  f186fc0:	ac39c168 */ 	sw	$t9,%lo(g_ScenarioData+0x58)($at)
/*  f186fc4:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f186fc8:	0fc28874 */ 	jal	bgunGetShortName
/*  f186fcc:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f186fd0:	8fb80120 */ 	lw	$t8,0x120($sp)
/*  f186fd4:	3c10800b */ 	lui	$s0,%hi(g_MpSetup+0x28)
/*  f186fd8:	2610cbb0 */ 	addiu	$s0,$s0,%lo(g_MpSetup+0x28)
/*  f186fdc:	870d0062 */ 	lh	$t5,0x62($t8)
/*  f186fe0:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f186fe4:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f186fe8:	000d6080 */ 	sll	$t4,$t5,0x2
/*  f186fec:	018d6023 */ 	subu	$t4,$t4,$t5
/*  f186ff0:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f186ff4:	020c3821 */ 	addu	$a3,$s0,$t4
/*  f186ff8:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f186ffc:	0c004dad */ 	jal	sprintf
/*  f187000:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f187004:	0fc5b9f1 */ 	jal	langGet
/*  f187008:	24045402 */ 	addiu	$a0,$zero,0x5402
/*  f18700c:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f187010:	0fc28874 */ 	jal	bgunGetShortName
/*  f187014:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f187018:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f18701c:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f187020:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f187024:	0c004dad */ 	jal	sprintf
/*  f187028:	00403825 */ 	or	$a3,$v0,$zero
/*  f18702c:	0fc5b9f1 */ 	jal	langGet
/*  f187030:	24045403 */ 	addiu	$a0,$zero,0x5403
/*  f187034:	24040057 */ 	addiu	$a0,$zero,0x57
/*  f187038:	0fc28874 */ 	jal	bgunGetShortName
/*  f18703c:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f187040:	8fae0120 */ 	lw	$t6,0x120($sp)
/*  f187044:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f187048:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f18704c:	85ca0062 */ 	lh	$t2,0x62($t6)
/*  f187050:	00403825 */ 	or	$a3,$v0,$zero
/*  f187054:	000a7880 */ 	sll	$t7,$t2,0x2
/*  f187058:	01ea7823 */ 	subu	$t7,$t7,$t2
/*  f18705c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f187060:	0c004dad */ 	jal	sprintf
/*  f187064:	020f3021 */ 	addu	$a2,$s0,$t7
/*  f187068:	8e2b006c */ 	lw	$t3,0x6c($s1)
/*  f18706c:	8e39028c */ 	lw	$t9,0x28c($s1)
/*  f187070:	00008025 */ 	or	$s0,$zero,$zero
/*  f187074:	11600003 */ 	beqz	$t3,.L0f187084
/*  f187078:	afb90118 */ 	sw	$t9,0x118($sp)
/*  f18707c:	10000002 */ 	b	.L0f187088
/*  f187080:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f187084:
/*  f187084:	00002025 */ 	or	$a0,$zero,$zero
.L0f187088:
/*  f187088:	8e380068 */ 	lw	$t8,0x68($s1)
/*  f18708c:	00001825 */ 	or	$v1,$zero,$zero
/*  f187090:	00002825 */ 	or	$a1,$zero,$zero
/*  f187094:	13000003 */ 	beqz	$t8,.L0f1870a4
/*  f187098:	00001025 */ 	or	$v0,$zero,$zero
/*  f18709c:	10000001 */ 	b	.L0f1870a4
/*  f1870a0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f1870a4:
/*  f1870a4:	8e2d0064 */ 	lw	$t5,0x64($s1)
/*  f1870a8:	11a00003 */ 	beqz	$t5,.L0f1870b8
/*  f1870ac:	00000000 */ 	nop
/*  f1870b0:	10000001 */ 	b	.L0f1870b8
/*  f1870b4:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f1870b8:
/*  f1870b8:	8e2c0070 */ 	lw	$t4,0x70($s1)
/*  f1870bc:	11800003 */ 	beqz	$t4,.L0f1870cc
/*  f1870c0:	00000000 */ 	nop
/*  f1870c4:	10000001 */ 	b	.L0f1870cc
/*  f1870c8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1870cc:
/*  f1870cc:	00457021 */ 	addu	$t6,$v0,$a1
/*  f1870d0:	01c35021 */ 	addu	$t2,$t6,$v1
/*  f1870d4:	01447821 */ 	addu	$t7,$t2,$a0
/*  f1870d8:	19e0003f */ 	blez	$t7,.L0f1871d8
/*  f1870dc:	00000000 */ 	nop
.L0f1870e0:
/*  f1870e0:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f1870e4:	02002025 */ 	or	$a0,$s0,$zero
/*  f1870e8:	8fb90128 */ 	lw	$t9,0x128($sp)
/*  f1870ec:	00107080 */ 	sll	$t6,$s0,0x2
/*  f1870f0:	3c0a800b */ 	lui	$t2,%hi(g_MpAllChrConfigPtrs)
/*  f1870f4:	8f2b02d4 */ 	lw	$t3,0x2d4($t9)
/*  f1870f8:	8fb80118 */ 	lw	$t8,0x118($sp)
/*  f1870fc:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f187100:	15600008 */ 	bnez	$t3,.L0f187124
/*  f187104:	8fad0120 */ 	lw	$t5,0x120($sp)
/*  f187108:	16180006 */ 	bne	$s0,$t8,.L0f187124
/*  f18710c:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f187110:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f187114:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f187118:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f18711c:	10000011 */ 	b	.L0f187164
/*  f187120:	8e39006c */ 	lw	$t9,0x6c($s1)
.L0f187124:
/*  f187124:	8d4ac500 */ 	lw	$t2,%lo(g_MpAllChrConfigPtrs)($t2)
/*  f187128:	85ac0062 */ 	lh	$t4,0x62($t5)
/*  f18712c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f187130:	914f0011 */ 	lbu	$t7,0x11($t2)
/*  f187134:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f187138:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f18713c:	158f0006 */ 	bne	$t4,$t7,.L0f187158
/*  f187140:	00000000 */ 	nop
/*  f187144:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f187148:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f18714c:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f187150:	10000004 */ 	b	.L0f187164
/*  f187154:	8e39006c */ 	lw	$t9,0x6c($s1)
.L0f187158:
/*  f187158:	0fc377e9 */ 	jal	hudmsgCreateWithFlags
/*  f18715c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f187160:	8e39006c */ 	lw	$t9,0x6c($s1)
.L0f187164:
/*  f187164:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f187168:	00002025 */ 	or	$a0,$zero,$zero
/*  f18716c:	13200003 */ 	beqz	$t9,.L0f18717c
/*  f187170:	00001825 */ 	or	$v1,$zero,$zero
/*  f187174:	10000001 */ 	b	.L0f18717c
/*  f187178:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f18717c:
/*  f18717c:	8e2b0068 */ 	lw	$t3,0x68($s1)
/*  f187180:	00002825 */ 	or	$a1,$zero,$zero
/*  f187184:	00001025 */ 	or	$v0,$zero,$zero
/*  f187188:	11600003 */ 	beqz	$t3,.L0f187198
/*  f18718c:	00000000 */ 	nop
/*  f187190:	10000001 */ 	b	.L0f187198
/*  f187194:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f187198:
/*  f187198:	8e380064 */ 	lw	$t8,0x64($s1)
/*  f18719c:	13000003 */ 	beqz	$t8,.L0f1871ac
/*  f1871a0:	00000000 */ 	nop
/*  f1871a4:	10000001 */ 	b	.L0f1871ac
/*  f1871a8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f1871ac:
/*  f1871ac:	8e2d0070 */ 	lw	$t5,0x70($s1)
/*  f1871b0:	11a00003 */ 	beqz	$t5,.L0f1871c0
/*  f1871b4:	00000000 */ 	nop
/*  f1871b8:	10000001 */ 	b	.L0f1871c0
/*  f1871bc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1871c0:
/*  f1871c0:	00457021 */ 	addu	$t6,$v0,$a1
/*  f1871c4:	01c35021 */ 	addu	$t2,$t6,$v1
/*  f1871c8:	01446021 */ 	addu	$t4,$t2,$a0
/*  f1871cc:	020c082a */ 	slt	$at,$s0,$t4
/*  f1871d0:	1420ffc3 */ 	bnez	$at,.L0f1870e0
/*  f1871d4:	00000000 */ 	nop
.L0f1871d8:
/*  f1871d8:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f1871dc:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f1871e0:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f1871e4:	8df902d4 */ 	lw	$t9,0x2d4($t7)
/*  f1871e8:	01e02025 */ 	or	$a0,$t7,$zero
/*  f1871ec:	13200009 */ 	beqz	$t9,.L0f187214
/*  f1871f0:	00000000 */ 	nop
/*  f1871f4:	0fc65fa3 */ 	jal	botinvGiveSingleWeapon
/*  f1871f8:	24050057 */ 	addiu	$a1,$zero,0x57
/*  f1871fc:	8fab0124 */ 	lw	$t3,0x124($sp)
/*  f187200:	00001025 */ 	or	$v0,$zero,$zero
/*  f187204:	8d780040 */ 	lw	$t8,0x40($t3)
/*  f187208:	370d0004 */ 	ori	$t5,$t8,0x4
/*  f18720c:	10000019 */ 	b	.L0f187274
/*  f187210:	ad6d0040 */ 	sw	$t5,0x40($t3)
.L0f187214:
/*  f187214:	0fc4483c */ 	jal	invGiveWeaponsByProp
/*  f187218:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f18721c:	8fa40124 */ 	lw	$a0,0x124($sp)
/*  f187220:	00002825 */ 	or	$a1,$zero,$zero
/*  f187224:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f187228:	30ca0004 */ 	andi	$t2,$a2,0x4
/*  f18722c:	0fc1ab4b */ 	jal	objFree
/*  f187230:	01403025 */ 	or	$a2,$t2,$zero
/*  f187234:	1000000f */ 	b	.L0f187274
/*  f187238:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f18723c:
/*  f18723c:	8fac0128 */ 	lw	$t4,0x128($sp)
.L0f187240:
/*  f187240:	8d9902d4 */ 	lw	$t9,0x2d4($t4)
/*  f187244:	13200003 */ 	beqz	$t9,.L0f187254
/*  f187248:	00000000 */ 	nop
/*  f18724c:	10000009 */ 	b	.L0f187274
/*  f187250:	00001025 */ 	or	$v0,$zero,$zero
.L0f187254:
/*  f187254:	10000007 */ 	b	.L0f187274
/*  f187258:	00001025 */ 	or	$v0,$zero,$zero
.L0f18725c:
/*  f18725c:	8df802d4 */ 	lw	$t8,0x2d4($t7)
/*  f187260:	00001025 */ 	or	$v0,$zero,$zero
/*  f187264:	13000003 */ 	beqz	$t8,.L0f187274
/*  f187268:	00000000 */ 	nop
/*  f18726c:	10000001 */ 	b	.L0f187274
/*  f187270:	00001025 */ 	or	$v0,$zero,$zero
.L0f187274:
/*  f187274:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f187278:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f18727c:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f187280:	03e00008 */ 	jr	$ra
/*  f187284:	27bd0128 */ 	addiu	$sp,$sp,0x128
);
#else
GLOBAL_ASM(
glabel chrGiveBriefcase
/*  f180d00:	27bdfed8 */ 	addiu	$sp,$sp,-296
/*  f180d04:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f180d08:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f180d0c:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f180d10:	afa40128 */ 	sw	$a0,0x128($sp)
/*  f180d14:	afa5012c */ 	sw	$a1,0x12c($sp)
/*  f180d18:	3c03800b */ 	lui	$v1,0x800b
/*  f180d1c:	8ca20004 */ 	lw	$v0,0x4($a1)
/*  f180d20:	90631448 */ 	lbu	$v1,0x1448($v1)
/*  f180d24:	24010001 */ 	addiu	$at,$zero,0x1
/*  f180d28:	afa20124 */ 	sw	$v0,0x124($sp)
/*  f180d2c:	1461009f */ 	bne	$v1,$at,.NB0f180fac
/*  f180d30:	afa20120 */ 	sw	$v0,0x120($sp)
/*  f180d34:	8c98001c */ 	lw	$t8,0x1c($a0)
/*  f180d38:	3c01800b */ 	lui	$at,0x800b
/*  f180d3c:	3c11800a */ 	lui	$s1,0x800a
/*  f180d40:	ac3809c4 */ 	sw	$t8,0x9c4($at)
/*  f180d44:	8c9902d4 */ 	lw	$t9,0x2d4($a0)
/*  f180d48:	2631e6c0 */ 	addiu	$s1,$s1,-6464
/*  f180d4c:	53200017 */ 	beqzl	$t9,.NB0f180dac
/*  f180d50:	8e39028c */ 	lw	$t9,0x28c($s1)
/*  f180d54:	0fc61c7f */ 	jal	mpPlayerGetIndex
/*  f180d58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180d5c:	00025080 */ 	sll	$t2,$v0,0x2
/*  f180d60:	3c0b800b */ 	lui	$t3,0x800b
/*  f180d64:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f180d68:	8d6b0db0 */ 	lw	$t3,0xdb0($t3)
/*  f180d6c:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f180d70:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f180d74:	afab0050 */ 	sw	$t3,0x50($sp)
/*  f180d78:	0fc2191a */ 	jal	propPlayPickupSound
/*  f180d7c:	9185005c */ 	lbu	$a1,0x5c($t4)
/*  f180d80:	8fa40128 */ 	lw	$a0,0x128($sp)
/*  f180d84:	24050056 */ 	addiu	$a1,$zero,0x56
/*  f180d88:	8c8302d4 */ 	lw	$v1,0x2d4($a0)
/*  f180d8c:	906e009c */ 	lbu	$t6,0x9c($v1)
/*  f180d90:	35d80080 */ 	ori	$t8,$t6,0x80
/*  f180d94:	0fc6479b */ 	jal	botinvGiveSingleWeapon
/*  f180d98:	a078009c */ 	sb	$t8,0x9c($v1)
/*  f180d9c:	3c11800a */ 	lui	$s1,0x800a
/*  f180da0:	10000020 */ 	beqz	$zero,.NB0f180e24
/*  f180da4:	2631e6c0 */ 	addiu	$s1,$s1,-6464
/*  f180da8:	8e39028c */ 	lw	$t9,0x28c($s1)
.NB0f180dac:
/*  f180dac:	3c0c800b */ 	lui	$t4,0x800b
/*  f180db0:	258c1068 */ 	addiu	$t4,$t4,0x1068
/*  f180db4:	001979c0 */ 	sll	$t7,$t9,0x7
/*  f180db8:	022f5021 */ 	addu	$t2,$s1,$t7
/*  f180dbc:	8d4200e4 */ 	lw	$v0,0xe4($t2)
/*  f180dc0:	3c19800b */ 	lui	$t9,0x800b
/*  f180dc4:	27390de8 */ 	addiu	$t9,$t9,0xde8
/*  f180dc8:	28410004 */ 	slti	$at,$v0,0x4
/*  f180dcc:	10200007 */ 	beqz	$at,.NB0f180dec
/*  f180dd0:	00027080 */ 	sll	$t6,$v0,0x2
/*  f180dd4:	00025880 */ 	sll	$t3,$v0,0x2
/*  f180dd8:	01625821 */ 	addu	$t3,$t3,$v0
/*  f180ddc:	000b5940 */ 	sll	$t3,$t3,0x5
/*  f180de0:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f180de4:	10000008 */ 	beqz	$zero,.NB0f180e08
/*  f180de8:	afad0050 */ 	sw	$t5,0x50($sp)
.NB0f180dec:
/*  f180dec:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f180df0:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f180df4:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f180df8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f180dfc:	25d8fed0 */ 	addiu	$t8,$t6,-304
/*  f180e00:	03197821 */ 	addu	$t7,$t8,$t9
/*  f180e04:	afaf0050 */ 	sw	$t7,0x50($sp)
.NB0f180e08:
/*  f180e08:	0fc4307a */ 	jal	invGiveSingleWeapon
/*  f180e0c:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f180e10:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f180e14:	0fc21c09 */ 	jal	currentPlayerQueuePickupWeaponHudmsg
/*  f180e18:	00002825 */ 	or	$a1,$zero,$zero
/*  f180e1c:	0fc2195b */ 	jal	weaponPlayPickupSound
/*  f180e20:	24040056 */ 	addiu	$a0,$zero,0x56
.NB0f180e24:
/*  f180e24:	0fc5a4dd */ 	jal	langGet
/*  f180e28:	24045400 */ 	addiu	$a0,$zero,0x5400
/*  f180e2c:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f180e30:	0fc27fd3 */ 	jal	bgunGetShortName
/*  f180e34:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f180e38:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f180e3c:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f180e40:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f180e44:	0c004fc1 */ 	jal	sprintf
/*  f180e48:	00403825 */ 	or	$a3,$v0,$zero
/*  f180e4c:	8e29006c */ 	lw	$t1,0x6c($s1)
/*  f180e50:	8e2a028c */ 	lw	$t2,0x28c($s1)
/*  f180e54:	00008025 */ 	or	$s0,$zero,$zero
/*  f180e58:	11200003 */ 	beqz	$t1,.NB0f180e68
/*  f180e5c:	afaa0118 */ 	sw	$t2,0x118($sp)
/*  f180e60:	10000002 */ 	beqz	$zero,.NB0f180e6c
/*  f180e64:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f180e68:
/*  f180e68:	00002025 */ 	or	$a0,$zero,$zero
.NB0f180e6c:
/*  f180e6c:	8e280068 */ 	lw	$t0,0x68($s1)
/*  f180e70:	00001825 */ 	or	$v1,$zero,$zero
/*  f180e74:	00002825 */ 	or	$a1,$zero,$zero
/*  f180e78:	11000003 */ 	beqz	$t0,.NB0f180e88
/*  f180e7c:	00001025 */ 	or	$v0,$zero,$zero
/*  f180e80:	10000001 */ 	beqz	$zero,.NB0f180e88
/*  f180e84:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f180e88:
/*  f180e88:	8e270064 */ 	lw	$a3,0x64($s1)
/*  f180e8c:	10e00003 */ 	beqz	$a3,.NB0f180e9c
/*  f180e90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180e94:	10000001 */ 	beqz	$zero,.NB0f180e9c
/*  f180e98:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f180e9c:
/*  f180e9c:	8e260070 */ 	lw	$a2,0x70($s1)
/*  f180ea0:	10c00003 */ 	beqz	$a2,.NB0f180eb0
/*  f180ea4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180ea8:	10000001 */ 	beqz	$zero,.NB0f180eb0
/*  f180eac:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f180eb0:
/*  f180eb0:	00455821 */ 	addu	$t3,$v0,$a1
/*  f180eb4:	01636021 */ 	addu	$t4,$t3,$v1
/*  f180eb8:	01846821 */ 	addu	$t5,$t4,$a0
/*  f180ebc:	19a0002d */ 	blez	$t5,.NB0f180f74
/*  f180ec0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180ec4:	8fae0128 */ 	lw	$t6,0x128($sp)
.NB0f180ec8:
/*  f180ec8:	8fb90118 */ 	lw	$t9,0x118($sp)
/*  f180ecc:	8dd802d4 */ 	lw	$t8,0x2d4($t6)
/*  f180ed0:	17000003 */ 	bnez	$t8,.NB0f180ee0
/*  f180ed4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180ed8:	1219000f */ 	beq	$s0,$t9,.NB0f180f18
/*  f180edc:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f180ee0:
/*  f180ee0:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f180ee4:	02002025 */ 	or	$a0,$s0,$zero
/*  f180ee8:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f180eec:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f180ef0:	0fc36d6f */ 	jal	hudmsgCreateWithFlags
/*  f180ef4:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f180ef8:	3c09800a */ 	lui	$t1,0x800a
/*  f180efc:	3c08800a */ 	lui	$t0,0x800a
/*  f180f00:	3c07800a */ 	lui	$a3,0x800a
/*  f180f04:	3c06800a */ 	lui	$a2,0x800a
/*  f180f08:	8cc6e730 */ 	lw	$a2,-0x18d0($a2)
/*  f180f0c:	8ce7e724 */ 	lw	$a3,-0x18dc($a3)
/*  f180f10:	8d08e728 */ 	lw	$t0,-0x18d8($t0)
/*  f180f14:	8d29e72c */ 	lw	$t1,-0x18d4($t1)
.NB0f180f18:
/*  f180f18:	11200003 */ 	beqz	$t1,.NB0f180f28
/*  f180f1c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f180f20:	10000002 */ 	beqz	$zero,.NB0f180f2c
/*  f180f24:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f180f28:
/*  f180f28:	00002025 */ 	or	$a0,$zero,$zero
.NB0f180f2c:
/*  f180f2c:	11000003 */ 	beqz	$t0,.NB0f180f3c
/*  f180f30:	00001825 */ 	or	$v1,$zero,$zero
/*  f180f34:	10000001 */ 	beqz	$zero,.NB0f180f3c
/*  f180f38:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f180f3c:
/*  f180f3c:	10e00003 */ 	beqz	$a3,.NB0f180f4c
/*  f180f40:	00002825 */ 	or	$a1,$zero,$zero
/*  f180f44:	10000001 */ 	beqz	$zero,.NB0f180f4c
/*  f180f48:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f180f4c:
/*  f180f4c:	10c00003 */ 	beqz	$a2,.NB0f180f5c
/*  f180f50:	00001025 */ 	or	$v0,$zero,$zero
/*  f180f54:	10000001 */ 	beqz	$zero,.NB0f180f5c
/*  f180f58:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f180f5c:
/*  f180f5c:	00457821 */ 	addu	$t7,$v0,$a1
/*  f180f60:	01e35021 */ 	addu	$t2,$t7,$v1
/*  f180f64:	01445821 */ 	addu	$t3,$t2,$a0
/*  f180f68:	020b082a */ 	slt	$at,$s0,$t3
/*  f180f6c:	5420ffd6 */ 	bnezl	$at,.NB0f180ec8
/*  f180f70:	8fae0128 */ 	lw	$t6,0x128($sp)
.NB0f180f74:
/*  f180f74:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f180f78:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f180f7c:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f180f80:	8fae0124 */ 	lw	$t6,0x124($sp)
/*  f180f84:	8d8d02d4 */ 	lw	$t5,0x2d4($t4)
/*  f180f88:	11a00006 */ 	beqz	$t5,.NB0f180fa4
/*  f180f8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f180f90:	8dd80040 */ 	lw	$t8,0x40($t6)
/*  f180f94:	00001025 */ 	or	$v0,$zero,$zero
/*  f180f98:	37190004 */ 	ori	$t9,$t8,0x4
/*  f180f9c:	100001c3 */ 	beqz	$zero,.NB0f1816ac
/*  f180fa0:	add90040 */ 	sw	$t9,0x40($t6)
.NB0f180fa4:
/*  f180fa4:	100001c1 */ 	beqz	$zero,.NB0f1816ac
/*  f180fa8:	24020004 */ 	addiu	$v0,$zero,0x4
.NB0f180fac:
/*  f180fac:	24010005 */ 	addiu	$at,$zero,0x5
/*  f180fb0:	146101b8 */ 	bne	$v1,$at,.NB0f181694
/*  f180fb4:	8fab0128 */ 	lw	$t3,0x128($sp)
/*  f180fb8:	8faf0128 */ 	lw	$t7,0x128($sp)
/*  f180fbc:	3c11800a */ 	lui	$s1,0x800a
/*  f180fc0:	2631e6c0 */ 	addiu	$s1,$s1,-6464
/*  f180fc4:	8de302d4 */ 	lw	$v1,0x2d4($t7)
/*  f180fc8:	5060000e */ 	beqzl	$v1,.NB0f181004
/*  f180fcc:	8e2d028c */ 	lw	$t5,0x28c($s1)
/*  f180fd0:	0fc61c7f */ 	jal	mpPlayerGetIndex
/*  f180fd4:	01e02025 */ 	or	$a0,$t7,$zero
/*  f180fd8:	00025080 */ 	sll	$t2,$v0,0x2
/*  f180fdc:	3c0b800b */ 	lui	$t3,0x800b
/*  f180fe0:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f180fe4:	8d6b0db0 */ 	lw	$t3,0xdb0($t3)
/*  f180fe8:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f180fec:	3c11800a */ 	lui	$s1,0x800a
/*  f180ff0:	afab0050 */ 	sw	$t3,0x50($sp)
/*  f180ff4:	2631e6c0 */ 	addiu	$s1,$s1,-6464
/*  f180ff8:	10000019 */ 	beqz	$zero,.NB0f181060
/*  f180ffc:	8d8302d4 */ 	lw	$v1,0x2d4($t4)
/*  f181000:	8e2d028c */ 	lw	$t5,0x28c($s1)
.NB0f181004:
/*  f181004:	3c0f800b */ 	lui	$t7,0x800b
/*  f181008:	25ef1068 */ 	addiu	$t7,$t7,0x1068
/*  f18100c:	000dc1c0 */ 	sll	$t8,$t5,0x7
/*  f181010:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f181014:	8f2200e4 */ 	lw	$v0,0xe4($t9)
/*  f181018:	3c0d800b */ 	lui	$t5,0x800b
/*  f18101c:	25ad0de8 */ 	addiu	$t5,$t5,0xde8
/*  f181020:	28410004 */ 	slti	$at,$v0,0x4
/*  f181024:	10200007 */ 	beqz	$at,.NB0f181044
/*  f181028:	00025880 */ 	sll	$t3,$v0,0x2
/*  f18102c:	00027080 */ 	sll	$t6,$v0,0x2
/*  f181030:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f181034:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f181038:	01cf5021 */ 	addu	$t2,$t6,$t7
/*  f18103c:	10000008 */ 	beqz	$zero,.NB0f181060
/*  f181040:	afaa0050 */ 	sw	$t2,0x50($sp)
.NB0f181044:
/*  f181044:	01625821 */ 	addu	$t3,$t3,$v0
/*  f181048:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f18104c:	01625823 */ 	subu	$t3,$t3,$v0
/*  f181050:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f181054:	256cfed0 */ 	addiu	$t4,$t3,-304
/*  f181058:	018dc021 */ 	addu	$t8,$t4,$t5
/*  f18105c:	afb80050 */ 	sw	$t8,0x50($sp)
.NB0f181060:
/*  f181060:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f181064:	8faf0120 */ 	lw	$t7,0x120($sp)
/*  f181068:	932e0011 */ 	lbu	$t6,0x11($t9)
/*  f18106c:	85ea0062 */ 	lh	$t2,0x62($t7)
/*  f181070:	15ca00c8 */ 	bne	$t6,$t2,.NB0f181394
/*  f181074:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181078:	10600005 */ 	beqz	$v1,.NB0f181090
/*  f18107c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181080:	8c6b009c */ 	lw	$t3,0x9c($v1)
/*  f181084:	000b6840 */ 	sll	$t5,$t3,0x1
/*  f181088:	05a20008 */ 	bltzl	$t5,.NB0f1810ac
/*  f18108c:	8fb80050 */ 	lw	$t8,0x50($sp)
.NB0f181090:
/*  f181090:	546000b9 */ 	bnezl	$v1,.NB0f181378
/*  f181094:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f181098:	0fc43329 */ 	jal	invHasBriefcase
/*  f18109c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1810a0:	504000b5 */ 	beqzl	$v0,.NB0f181378
/*  f1810a4:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f1810a8:	8fb80050 */ 	lw	$t8,0x50($sp)
.NB0f1810ac:
/*  f1810ac:	3c02800b */ 	lui	$v0,0x800b
/*  f1810b0:	244209c0 */ 	addiu	$v0,$v0,0x9c0
/*  f1810b4:	8719003e */ 	lh	$t9,0x3e($t8)
/*  f1810b8:	00008025 */ 	or	$s0,$zero,$zero
/*  f1810bc:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f1810c0:	a70f003e */ 	sh	$t7,0x3e($t8)
/*  f1810c4:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f1810c8:	8fab0128 */ 	lw	$t3,0x128($sp)
/*  f1810cc:	8dc3001c */ 	lw	$v1,0x1c($t6)
.NB0f1810d0:
/*  f1810d0:	8c4a0058 */ 	lw	$t2,0x58($v0)
/*  f1810d4:	506a0006 */ 	beql	$v1,$t2,.NB0f1810f0
/*  f1810d8:	8d6c02d4 */ 	lw	$t4,0x2d4($t3)
/*  f1810dc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1810e0:	2a010004 */ 	slti	$at,$s0,0x4
/*  f1810e4:	1420fffa */ 	bnez	$at,.NB0f1810d0
/*  f1810e8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f1810ec:	8d6c02d4 */ 	lw	$t4,0x2d4($t3)
.NB0f1810f0:
/*  f1810f0:	11800009 */ 	beqz	$t4,.NB0f181118
/*  f1810f4:	01602025 */ 	or	$a0,$t3,$zero
/*  f1810f8:	0fc64e59 */ 	jal	botinvDropOne
/*  f1810fc:	24050056 */ 	addiu	$a1,$zero,0x56
/*  f181100:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f181104:	8da302d4 */ 	lw	$v1,0x2d4($t5)
/*  f181108:	9079009c */ 	lbu	$t9,0x9c($v1)
/*  f18110c:	332fffbf */ 	andi	$t7,$t9,0xffbf
/*  f181110:	10000014 */ 	beqz	$zero,.NB0f181164
/*  f181114:	a06f009c */ 	sb	$t7,0x9c($v1)
.NB0f181118:
/*  f181118:	3c01bf80 */ 	lui	$at,0xbf80
/*  f18111c:	44812000 */ 	mtc1	$at,$f4
/*  f181120:	3c04800a */ 	lui	$a0,0x800a
/*  f181124:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f181128:	240effff */ 	addiu	$t6,$zero,-1
/*  f18112c:	240affff */ 	addiu	$t2,$zero,-1
/*  f181130:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f181134:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f181138:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f18113c:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f181140:	240505b8 */ 	addiu	$a1,$zero,0x5b8
/*  f181144:	00003025 */ 	or	$a2,$zero,$zero
/*  f181148:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f18114c:	0c004338 */ 	jal	sndStart
/*  f181150:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f181154:	0fc23e12 */ 	jal	weaponCreateForPlayerDrop
/*  f181158:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f18115c:	0fc430c1 */ 	jal	invRemoveItemByNum
/*  f181160:	24040056 */ 	addiu	$a0,$zero,0x56
.NB0f181164:
/*  f181164:	0fc5a4dd */ 	jal	langGet
/*  f181168:	24045404 */ 	addiu	$a0,$zero,0x5404
/*  f18116c:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f181170:	0fc27fd3 */ 	jal	bgunGetShortName
/*  f181174:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f181178:	00106080 */ 	sll	$t4,$s0,0x2
/*  f18117c:	01906023 */ 	subu	$t4,$t4,$s0
/*  f181180:	3c0b800b */ 	lui	$t3,0x800b
/*  f181184:	256b1460 */ 	addiu	$t3,$t3,0x1460
/*  f181188:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f18118c:	018b3021 */ 	addu	$a2,$t4,$t3
/*  f181190:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f181194:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f181198:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f18119c:	0c004fc1 */ 	jal	sprintf
/*  f1811a0:	00403825 */ 	or	$a3,$v0,$zero
/*  f1811a4:	0fc5a4dd */ 	jal	langGet
/*  f1811a8:	24045405 */ 	addiu	$a0,$zero,0x5405
/*  f1811ac:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f1811b0:	0fc27fd3 */ 	jal	bgunGetShortName
/*  f1811b4:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f1811b8:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f1811bc:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f1811c0:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f1811c4:	0c004fc1 */ 	jal	sprintf
/*  f1811c8:	00403825 */ 	or	$a3,$v0,$zero
/*  f1811cc:	0fc5a4dd */ 	jal	langGet
/*  f1811d0:	24045406 */ 	addiu	$a0,$zero,0x5406
/*  f1811d4:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f1811d8:	0fc27fd3 */ 	jal	bgunGetShortName
/*  f1811dc:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f1811e0:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f1811e4:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f1811e8:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f1811ec:	8fa7003c */ 	lw	$a3,0x3c($sp)
/*  f1811f0:	0c004fc1 */ 	jal	sprintf
/*  f1811f4:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f1811f8:	8e39006c */ 	lw	$t9,0x6c($s1)
/*  f1811fc:	8e2d028c */ 	lw	$t5,0x28c($s1)
/*  f181200:	afb00114 */ 	sw	$s0,0x114($sp)
/*  f181204:	00008025 */ 	or	$s0,$zero,$zero
/*  f181208:	13200003 */ 	beqz	$t9,.NB0f181218
/*  f18120c:	afad0118 */ 	sw	$t5,0x118($sp)
/*  f181210:	10000002 */ 	beqz	$zero,.NB0f18121c
/*  f181214:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f181218:
/*  f181218:	00002025 */ 	or	$a0,$zero,$zero
.NB0f18121c:
/*  f18121c:	8e2f0068 */ 	lw	$t7,0x68($s1)
/*  f181220:	00001825 */ 	or	$v1,$zero,$zero
/*  f181224:	00002825 */ 	or	$a1,$zero,$zero
/*  f181228:	11e00003 */ 	beqz	$t7,.NB0f181238
/*  f18122c:	00001025 */ 	or	$v0,$zero,$zero
/*  f181230:	10000001 */ 	beqz	$zero,.NB0f181238
/*  f181234:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f181238:
/*  f181238:	8e380064 */ 	lw	$t8,0x64($s1)
/*  f18123c:	13000003 */ 	beqz	$t8,.NB0f18124c
/*  f181240:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181244:	10000001 */ 	beqz	$zero,.NB0f18124c
/*  f181248:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f18124c:
/*  f18124c:	8e2e0070 */ 	lw	$t6,0x70($s1)
/*  f181250:	11c00003 */ 	beqz	$t6,.NB0f181260
/*  f181254:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181258:	10000001 */ 	beqz	$zero,.NB0f181260
/*  f18125c:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f181260:
/*  f181260:	00455021 */ 	addu	$t2,$v0,$a1
/*  f181264:	01436021 */ 	addu	$t4,$t2,$v1
/*  f181268:	01845821 */ 	addu	$t3,$t4,$a0
/*  f18126c:	1960003f */ 	blez	$t3,.NB0f18136c
/*  f181270:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f181274:
/*  f181274:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f181278:	02002025 */ 	or	$a0,$s0,$zero
/*  f18127c:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f181280:	00107080 */ 	sll	$t6,$s0,0x2
/*  f181284:	3c0a800b */ 	lui	$t2,0x800b
/*  f181288:	8db902d4 */ 	lw	$t9,0x2d4($t5)
/*  f18128c:	8faf0118 */ 	lw	$t7,0x118($sp)
/*  f181290:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f181294:	17200008 */ 	bnez	$t9,.NB0f1812b8
/*  f181298:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18129c:	160f0006 */ 	bne	$s0,$t7,.NB0f1812b8
/*  f1812a0:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f1812a4:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1812a8:	0fc36d6f */ 	jal	hudmsgCreateWithFlags
/*  f1812ac:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1812b0:	10000011 */ 	beqz	$zero,.NB0f1812f8
/*  f1812b4:	8e2b006c */ 	lw	$t3,0x6c($s1)
.NB0f1812b8:
/*  f1812b8:	8d4a0db0 */ 	lw	$t2,0xdb0($t2)
/*  f1812bc:	8fb80114 */ 	lw	$t8,0x114($sp)
/*  f1812c0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1812c4:	914c0011 */ 	lbu	$t4,0x11($t2)
/*  f1812c8:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f1812cc:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1812d0:	170c0006 */ 	bne	$t8,$t4,.NB0f1812ec
/*  f1812d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1812d8:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f1812dc:	0fc36d6f */ 	jal	hudmsgCreateWithFlags
/*  f1812e0:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1812e4:	10000004 */ 	beqz	$zero,.NB0f1812f8
/*  f1812e8:	8e2b006c */ 	lw	$t3,0x6c($s1)
.NB0f1812ec:
/*  f1812ec:	0fc36d6f */ 	jal	hudmsgCreateWithFlags
/*  f1812f0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1812f4:	8e2b006c */ 	lw	$t3,0x6c($s1)
.NB0f1812f8:
/*  f1812f8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1812fc:	00002025 */ 	or	$a0,$zero,$zero
/*  f181300:	11600003 */ 	beqz	$t3,.NB0f181310
/*  f181304:	00001825 */ 	or	$v1,$zero,$zero
/*  f181308:	10000001 */ 	beqz	$zero,.NB0f181310
/*  f18130c:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f181310:
/*  f181310:	8e2d0068 */ 	lw	$t5,0x68($s1)
/*  f181314:	00002825 */ 	or	$a1,$zero,$zero
/*  f181318:	00001025 */ 	or	$v0,$zero,$zero
/*  f18131c:	11a00003 */ 	beqz	$t5,.NB0f18132c
/*  f181320:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181324:	10000001 */ 	beqz	$zero,.NB0f18132c
/*  f181328:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f18132c:
/*  f18132c:	8e390064 */ 	lw	$t9,0x64($s1)
/*  f181330:	13200003 */ 	beqz	$t9,.NB0f181340
/*  f181334:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181338:	10000001 */ 	beqz	$zero,.NB0f181340
/*  f18133c:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f181340:
/*  f181340:	8e2f0070 */ 	lw	$t7,0x70($s1)
/*  f181344:	11e00003 */ 	beqz	$t7,.NB0f181354
/*  f181348:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18134c:	10000001 */ 	beqz	$zero,.NB0f181354
/*  f181350:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f181354:
/*  f181354:	00457021 */ 	addu	$t6,$v0,$a1
/*  f181358:	01c35021 */ 	addu	$t2,$t6,$v1
/*  f18135c:	0144c021 */ 	addu	$t8,$t2,$a0
/*  f181360:	0218082a */ 	slt	$at,$s0,$t8
/*  f181364:	1420ffc3 */ 	bnez	$at,.NB0f181274
/*  f181368:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f18136c:
/*  f18136c:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f181370:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f181374:	8fac0128 */ 	lw	$t4,0x128($sp)
.NB0f181378:
/*  f181378:	8d8b02d4 */ 	lw	$t3,0x2d4($t4)
/*  f18137c:	11600003 */ 	beqz	$t3,.NB0f18138c
/*  f181380:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181384:	100000c9 */ 	beqz	$zero,.NB0f1816ac
/*  f181388:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18138c:
/*  f18138c:	100000c7 */ 	beqz	$zero,.NB0f1816ac
/*  f181390:	00001025 */ 	or	$v0,$zero,$zero
.NB0f181394:
/*  f181394:	10600005 */ 	beqz	$v1,.NB0f1813ac
/*  f181398:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18139c:	8c6d009c */ 	lw	$t5,0x9c($v1)
/*  f1813a0:	000d7840 */ 	sll	$t7,$t5,0x1
/*  f1813a4:	05e10008 */ 	bgez	$t7,.NB0f1813c8
/*  f1813a8:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f1813ac:
/*  f1813ac:	546000b2 */ 	bnezl	$v1,.NB0f181678
/*  f1813b0:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f1813b4:	0fc43329 */ 	jal	invHasBriefcase
/*  f1813b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1813bc:	144000ad */ 	bnez	$v0,.NB0f181674
/*  f1813c0:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f1813c4:	8dc302d4 */ 	lw	$v1,0x2d4($t6)
.NB0f1813c8:
/*  f1813c8:	50600009 */ 	beqzl	$v1,.NB0f1813f0
/*  f1813cc:	8faf0120 */ 	lw	$t7,0x120($sp)
/*  f1813d0:	9078009c */ 	lbu	$t8,0x9c($v1)
/*  f1813d4:	370c0040 */ 	ori	$t4,$t8,0x40
/*  f1813d8:	a06c009c */ 	sb	$t4,0x9c($v1)
/*  f1813dc:	8fab0120 */ 	lw	$t3,0x120($sp)
/*  f1813e0:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f1813e4:	0fc2191a */ 	jal	propPlayPickupSound
/*  f1813e8:	9165005c */ 	lbu	$a1,0x5c($t3)
/*  f1813ec:	8faf0120 */ 	lw	$t7,0x120($sp)
.NB0f1813f0:
/*  f1813f0:	8fad0128 */ 	lw	$t5,0x128($sp)
/*  f1813f4:	3c01800b */ 	lui	$at,0x800b
/*  f1813f8:	85ee0062 */ 	lh	$t6,0x62($t7)
/*  f1813fc:	8db9001c */ 	lw	$t9,0x1c($t5)
/*  f181400:	24045401 */ 	addiu	$a0,$zero,0x5401
/*  f181404:	000e5080 */ 	sll	$t2,$t6,0x2
/*  f181408:	002a0821 */ 	addu	$at,$at,$t2
/*  f18140c:	0fc5a4dd */ 	jal	langGet
/*  f181410:	ac390a18 */ 	sw	$t9,0xa18($at)
/*  f181414:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f181418:	0fc27fd3 */ 	jal	bgunGetShortName
/*  f18141c:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f181420:	8fb80120 */ 	lw	$t8,0x120($sp)
/*  f181424:	3c10800b */ 	lui	$s0,0x800b
/*  f181428:	26101460 */ 	addiu	$s0,$s0,0x1460
/*  f18142c:	870c0062 */ 	lh	$t4,0x62($t8)
/*  f181430:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f181434:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f181438:	000c5880 */ 	sll	$t3,$t4,0x2
/*  f18143c:	016c5823 */ 	subu	$t3,$t3,$t4
/*  f181440:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f181444:	020b3821 */ 	addu	$a3,$s0,$t3
/*  f181448:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f18144c:	0c004fc1 */ 	jal	sprintf
/*  f181450:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f181454:	0fc5a4dd */ 	jal	langGet
/*  f181458:	24045402 */ 	addiu	$a0,$zero,0x5402
/*  f18145c:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f181460:	0fc27fd3 */ 	jal	bgunGetShortName
/*  f181464:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f181468:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f18146c:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f181470:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f181474:	0c004fc1 */ 	jal	sprintf
/*  f181478:	00403825 */ 	or	$a3,$v0,$zero
/*  f18147c:	0fc5a4dd */ 	jal	langGet
/*  f181480:	24045403 */ 	addiu	$a0,$zero,0x5403
/*  f181484:	24040056 */ 	addiu	$a0,$zero,0x56
/*  f181488:	0fc27fd3 */ 	jal	bgunGetShortName
/*  f18148c:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f181490:	8fad0120 */ 	lw	$t5,0x120($sp)
/*  f181494:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f181498:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f18149c:	85af0062 */ 	lh	$t7,0x62($t5)
/*  f1814a0:	00403825 */ 	or	$a3,$v0,$zero
/*  f1814a4:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f1814a8:	01cf7023 */ 	subu	$t6,$t6,$t7
/*  f1814ac:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1814b0:	0c004fc1 */ 	jal	sprintf
/*  f1814b4:	020e3021 */ 	addu	$a2,$s0,$t6
/*  f1814b8:	8e2a006c */ 	lw	$t2,0x6c($s1)
/*  f1814bc:	8e39028c */ 	lw	$t9,0x28c($s1)
/*  f1814c0:	00008025 */ 	or	$s0,$zero,$zero
/*  f1814c4:	11400003 */ 	beqz	$t2,.NB0f1814d4
/*  f1814c8:	afb90118 */ 	sw	$t9,0x118($sp)
/*  f1814cc:	10000002 */ 	beqz	$zero,.NB0f1814d8
/*  f1814d0:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f1814d4:
/*  f1814d4:	00002025 */ 	or	$a0,$zero,$zero
.NB0f1814d8:
/*  f1814d8:	8e380068 */ 	lw	$t8,0x68($s1)
/*  f1814dc:	00001825 */ 	or	$v1,$zero,$zero
/*  f1814e0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1814e4:	13000003 */ 	beqz	$t8,.NB0f1814f4
/*  f1814e8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1814ec:	10000001 */ 	beqz	$zero,.NB0f1814f4
/*  f1814f0:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f1814f4:
/*  f1814f4:	8e2c0064 */ 	lw	$t4,0x64($s1)
/*  f1814f8:	11800003 */ 	beqz	$t4,.NB0f181508
/*  f1814fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181500:	10000001 */ 	beqz	$zero,.NB0f181508
/*  f181504:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f181508:
/*  f181508:	8e2b0070 */ 	lw	$t3,0x70($s1)
/*  f18150c:	11600003 */ 	beqz	$t3,.NB0f18151c
/*  f181510:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181514:	10000001 */ 	beqz	$zero,.NB0f18151c
/*  f181518:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f18151c:
/*  f18151c:	00456821 */ 	addu	$t5,$v0,$a1
/*  f181520:	01a37821 */ 	addu	$t7,$t5,$v1
/*  f181524:	01e47021 */ 	addu	$t6,$t7,$a0
/*  f181528:	19c0003f */ 	blez	$t6,.NB0f181628
/*  f18152c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f181530:
/*  f181530:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f181534:	02002025 */ 	or	$a0,$s0,$zero
/*  f181538:	8fb90128 */ 	lw	$t9,0x128($sp)
/*  f18153c:	00106880 */ 	sll	$t5,$s0,0x2
/*  f181540:	3c0f800b */ 	lui	$t7,0x800b
/*  f181544:	8f2a02d4 */ 	lw	$t2,0x2d4($t9)
/*  f181548:	8fb80118 */ 	lw	$t8,0x118($sp)
/*  f18154c:	01ed7821 */ 	addu	$t7,$t7,$t5
/*  f181550:	15400008 */ 	bnez	$t2,.NB0f181574
/*  f181554:	8fac0120 */ 	lw	$t4,0x120($sp)
/*  f181558:	16180006 */ 	bne	$s0,$t8,.NB0f181574
/*  f18155c:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f181560:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f181564:	0fc36d6f */ 	jal	hudmsgCreateWithFlags
/*  f181568:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f18156c:	10000011 */ 	beqz	$zero,.NB0f1815b4
/*  f181570:	8e39006c */ 	lw	$t9,0x6c($s1)
.NB0f181574:
/*  f181574:	8def0db0 */ 	lw	$t7,0xdb0($t7)
/*  f181578:	858b0062 */ 	lh	$t3,0x62($t4)
/*  f18157c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f181580:	91ee0011 */ 	lbu	$t6,0x11($t7)
/*  f181584:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f181588:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f18158c:	156e0006 */ 	bne	$t3,$t6,.NB0f1815a8
/*  f181590:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181594:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f181598:	0fc36d6f */ 	jal	hudmsgCreateWithFlags
/*  f18159c:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f1815a0:	10000004 */ 	beqz	$zero,.NB0f1815b4
/*  f1815a4:	8e39006c */ 	lw	$t9,0x6c($s1)
.NB0f1815a8:
/*  f1815a8:	0fc36d6f */ 	jal	hudmsgCreateWithFlags
/*  f1815ac:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1815b0:	8e39006c */ 	lw	$t9,0x6c($s1)
.NB0f1815b4:
/*  f1815b4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1815b8:	00002025 */ 	or	$a0,$zero,$zero
/*  f1815bc:	13200003 */ 	beqz	$t9,.NB0f1815cc
/*  f1815c0:	00001825 */ 	or	$v1,$zero,$zero
/*  f1815c4:	10000001 */ 	beqz	$zero,.NB0f1815cc
/*  f1815c8:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f1815cc:
/*  f1815cc:	8e2a0068 */ 	lw	$t2,0x68($s1)
/*  f1815d0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1815d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1815d8:	11400003 */ 	beqz	$t2,.NB0f1815e8
/*  f1815dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1815e0:	10000001 */ 	beqz	$zero,.NB0f1815e8
/*  f1815e4:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f1815e8:
/*  f1815e8:	8e380064 */ 	lw	$t8,0x64($s1)
/*  f1815ec:	13000003 */ 	beqz	$t8,.NB0f1815fc
/*  f1815f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1815f4:	10000001 */ 	beqz	$zero,.NB0f1815fc
/*  f1815f8:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f1815fc:
/*  f1815fc:	8e2c0070 */ 	lw	$t4,0x70($s1)
/*  f181600:	11800003 */ 	beqz	$t4,.NB0f181610
/*  f181604:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181608:	10000001 */ 	beqz	$zero,.NB0f181610
/*  f18160c:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f181610:
/*  f181610:	00456821 */ 	addu	$t5,$v0,$a1
/*  f181614:	01a37821 */ 	addu	$t7,$t5,$v1
/*  f181618:	01e45821 */ 	addu	$t3,$t7,$a0
/*  f18161c:	020b082a */ 	slt	$at,$s0,$t3
/*  f181620:	1420ffc3 */ 	bnez	$at,.NB0f181530
/*  f181624:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f181628:
/*  f181628:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*  f18162c:	8fa40118 */ 	lw	$a0,0x118($sp)
/*  f181630:	8fae0128 */ 	lw	$t6,0x128($sp)
/*  f181634:	8dd902d4 */ 	lw	$t9,0x2d4($t6)
/*  f181638:	01c02025 */ 	or	$a0,$t6,$zero
/*  f18163c:	13200009 */ 	beqz	$t9,.NB0f181664
/*  f181640:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181644:	0fc6479b */ 	jal	botinvGiveSingleWeapon
/*  f181648:	24050056 */ 	addiu	$a1,$zero,0x56
/*  f18164c:	8faa0124 */ 	lw	$t2,0x124($sp)
/*  f181650:	00001025 */ 	or	$v0,$zero,$zero
/*  f181654:	8d580040 */ 	lw	$t8,0x40($t2)
/*  f181658:	370c0004 */ 	ori	$t4,$t8,0x4
/*  f18165c:	10000013 */ 	beqz	$zero,.NB0f1816ac
/*  f181660:	ad4c0040 */ 	sw	$t4,0x40($t2)
.NB0f181664:
/*  f181664:	0fc43154 */ 	jal	invGiveWeaponsByProp
/*  f181668:	8fa4012c */ 	lw	$a0,0x12c($sp)
/*  f18166c:	1000000f */ 	beqz	$zero,.NB0f1816ac
/*  f181670:	24020004 */ 	addiu	$v0,$zero,0x4
.NB0f181674:
/*  f181674:	8fad0128 */ 	lw	$t5,0x128($sp)
.NB0f181678:
/*  f181678:	8daf02d4 */ 	lw	$t7,0x2d4($t5)
/*  f18167c:	11e00003 */ 	beqz	$t7,.NB0f18168c
/*  f181680:	00000000 */ 	sll	$zero,$zero,0x0
/*  f181684:	10000009 */ 	beqz	$zero,.NB0f1816ac
/*  f181688:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18168c:
/*  f18168c:	10000007 */ 	beqz	$zero,.NB0f1816ac
/*  f181690:	00001025 */ 	or	$v0,$zero,$zero
.NB0f181694:
/*  f181694:	8d7902d4 */ 	lw	$t9,0x2d4($t3)
/*  f181698:	00001025 */ 	or	$v0,$zero,$zero
/*  f18169c:	13200003 */ 	beqz	$t9,.NB0f1816ac
/*  f1816a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1816a4:	10000001 */ 	beqz	$zero,.NB0f1816ac
/*  f1816a8:	00001025 */ 	or	$v0,$zero,$zero
.NB0f1816ac:
/*  f1816ac:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f1816b0:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f1816b4:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f1816b8:	03e00008 */ 	jr	$ra
/*  f1816bc:	27bd0128 */ 	addiu	$sp,$sp,0x128
);
#endif

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
				weapon->timer240 = i;
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
