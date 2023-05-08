#include <ultra64.h>
#include "constants.h"
#include "lib/sched.h"
#include "lib/str.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/inv.h"
#include "game/playermgr.h"
#include "game/training.h"
#include "game/gamefile.h"
#include "game/lang.h"
#include "game/pak.h"
#include "bss.h"
#include "data.h"
#include "types.h"

u32 g_CheatsActiveBank0;
u32 g_CheatsActiveBank1;
u32 g_CheatsEnabledBank0;
u32 g_CheatsEnabledBank1;

struct menuitem g_CheatsBuddiesMenuItems[];
struct menudialogdef g_CheatsBuddiesMenuDialog;

#define TIME(mins, secs) (mins * 60 + secs)
#define m
#define s

struct cheat g_Cheats[NUM_CHEATS] = {
	{ L_MPWEAPONS_075, TIME(2 m,  3 s),   SOLOSTAGEINDEX_EXTRACTION,     DIFF_A,  CHEATFLAG_TIMED | CHEATFLAG_TRANSFERPAK      }, // Hurricane Fists
	{ L_MPWEAPONS_076, TIME(1 m, 40 s),   SOLOSTAGEINDEX_G5BUILDING,     DIFF_A,  CHEATFLAG_TIMED | CHEATFLAG_TRANSFERPAK      }, // Cloaking Device
	{ L_MPWEAPONS_077, TIME(3 m, 50 s),   SOLOSTAGEINDEX_ESCAPE,         DIFF_A,  CHEATFLAG_TIMED                              }, // Invincible
	{ L_MPWEAPONS_078, TIME(5 m, 31 s),   SOLOSTAGEINDEX_SKEDARRUINS,    DIFF_PA, CHEATFLAG_TIMED | CHEATFLAG_TRANSFERPAK      }, // All Guns in Solo
	{ L_MPWEAPONS_079, TIME(7 m,  7 s),   SOLOSTAGEINDEX_PELAGIC,        DIFF_SA, CHEATFLAG_TIMED                              }, // Unlimited Ammo
	{ L_MPWEAPONS_080, TIME(3 m, 11 s),   SOLOSTAGEINDEX_AIRBASE,        DIFF_SA, CHEATFLAG_TIMED                              }, // Unlimited Ammo, No Reloads
	{ L_MPWEAPONS_081, 0,                 SOLOSTAGEINDEX_INVESTIGATION,  DIFF_A,  CHEATFLAG_COMPLETION                         }, // Slo-mo Single Player
	{ L_MPWEAPONS_082, 0,                 SOLOSTAGEINDEX_CHICAGO,        DIFF_A,  CHEATFLAG_COMPLETION                         }, // DK Mode
	{ L_MPWEAPONS_083, TIME(2 m, 50 s),   SOLOSTAGEINDEX_CRASHSITE,      DIFF_A,  CHEATFLAG_TIMED                              }, // Trent's Magnum
	{ L_MPWEAPONS_084, TIME(7 m, 27 s),   SOLOSTAGEINDEX_DEEPSEA,        DIFF_PA, CHEATFLAG_TIMED                              }, // FarSight
	{ L_MPWEAPONS_085, 0,                 SOLOSTAGEINDEX_G5BUILDING,     DIFF_A,  CHEATFLAG_COMPLETION                         }, // Small Jo
	{ L_MPWEAPONS_086, 0,                 SOLOSTAGEINDEX_INFILTRATION,   DIFF_A,  CHEATFLAG_COMPLETION                         }, // Small Characters
	{ L_MPWEAPONS_087, 0,                 SOLOSTAGEINDEX_DEFENSE,        DIFF_A,  CHEATFLAG_COMPLETION                         }, // Enemy Shields
	{ L_MPWEAPONS_088, 0,                 SOLOSTAGEINDEX_DEEPSEA,        DIFF_A,  CHEATFLAG_COMPLETION                         }, // Jo Shield
	{ L_MPWEAPONS_089, TIME(1 m, 45 s),   SOLOSTAGEINDEX_DEFENSE,        DIFF_A,  CHEATFLAG_TIMED                              }, // Super Shield
	{ L_MPWEAPONS_090, 0,                 SOLOSTAGEINDEX_DEFECTION,      DIFF_A,  CHEATFLAG_COMPLETION                         }, // Classic Sight
	{ L_MPWEAPONS_091, 0,                 SOLOSTAGEINDEX_AIRBASE,        DIFF_A,  CHEATFLAG_COMPLETION                         }, // Team Heads Only
	{ L_MPWEAPONS_092, TIME(7 m, 59 s),   SOLOSTAGEINDEX_RESCUE,         DIFF_PA, CHEATFLAG_TIMED                              }, // Play as Elvis
	{ L_MPWEAPONS_093, 0,                 SOLOSTAGEINDEX_PELAGIC,        DIFF_A,  CHEATFLAG_COMPLETION                         }, // Enemy Rockets
	{ L_MPWEAPONS_094, TIME(3 m, 55 s),   SOLOSTAGEINDEX_AIRFORCEONE,    DIFF_PA, CHEATFLAG_TIMED                              }, // Unlimited Ammo - Laptop Sentry Gun
	{ L_MPWEAPONS_095, TIME(1 m, 30 s),   SOLOSTAGEINDEX_DEFECTION,      DIFF_SA, CHEATFLAG_TIMED                              }, // Marquis of Queensbury Rules
	{ L_MPWEAPONS_096, 0,                 SOLOSTAGEINDEX_CRASHSITE,      DIFF_A,  CHEATFLAG_COMPLETION                         }, // Perfect Darkness
	{ L_MPWEAPONS_097, TIME(6 m, 30 s),   SOLOSTAGEINDEX_INVESTIGATION,  DIFF_PA, CHEATFLAG_TIMED                              }, // Pugilist
	{ L_MPWEAPONS_098, TIME(5 m,  0 s),   SOLOSTAGEINDEX_INFILTRATION,   DIFF_SA, CHEATFLAG_TIMED                              }, // Hotshot
	{ L_MPWEAPONS_099, TIME(2 m, 30 s),   SOLOSTAGEINDEX_VILLA,          DIFF_SA, CHEATFLAG_TIMED                              }, // Hit and Run
	{ L_MPWEAPONS_100, TIME(5 m, 17 s),   SOLOSTAGEINDEX_ATTACKSHIP,     DIFF_SA, CHEATFLAG_TIMED                              }, // Alien
	{ L_MPWEAPONS_101, 0,                 SOLOSTAGEINDEX_SKEDARRUINS,    DIFF_A,  CHEATFLAG_COMPLETION | CHEATFLAG_TRANSFERPAK }, // R-Tracker/Weapon Cache Locations
	{ L_MPWEAPONS_102, 0,                 SOLOSTAGEINDEX_EXTRACTION,     DIFF_A,  CHEATFLAG_COMPLETION                         }, // Rocket Launcher
	{ L_MPWEAPONS_103, 0,                 SOLOSTAGEINDEX_VILLA,          DIFF_A,  CHEATFLAG_COMPLETION                         }, // Sniper Rifle
	{ L_MPWEAPONS_104, 0,                 SOLOSTAGEINDEX_RESCUE,         DIFF_A,  CHEATFLAG_COMPLETION                         }, // X-Ray Scanner
	{ L_MPWEAPONS_105, 0,                 SOLOSTAGEINDEX_ESCAPE,         DIFF_A,  CHEATFLAG_COMPLETION                         }, // SuperDragon
	{ L_MPWEAPONS_106, 0,                 SOLOSTAGEINDEX_AIRFORCEONE,    DIFF_A,  CHEATFLAG_COMPLETION                         }, // Laptop Gun
	{ L_MPWEAPONS_107, 0,                 SOLOSTAGEINDEX_ATTACKSHIP,     DIFF_A,  CHEATFLAG_COMPLETION                         }, // Phoenix
	{ L_MPWEAPONS_108, TIME(2 m,  0 s),   SOLOSTAGEINDEX_CHICAGO,        DIFF_PA, CHEATFLAG_TIMED                              }, // Psychosis Gun
	{ L_MPWEAPONS_109, WEAPON_PP9I,       0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // PP9i
	{ L_MPWEAPONS_110, WEAPON_CC13,       0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // CC13
	{ L_MPWEAPONS_111, WEAPON_KL01313,    0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // KL01313
	{ L_MPWEAPONS_112, WEAPON_KF7SPECIAL, 0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // KF7 Special
	{ L_MPWEAPONS_113, WEAPON_ZZT,        0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // ZZT (9mm)
	{ L_MPWEAPONS_114, WEAPON_DMC,        0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // DMC
	{ L_MPWEAPONS_115, WEAPON_AR53,       0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // AR53
	{ L_MPWEAPONS_116, WEAPON_RCP45,      0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // RC-P45
};

u32 cheatIsUnlocked(s32 cheat_id)
{
	struct cheat *cheat = &g_Cheats[cheat_id];
	u32 unlocked = 0;

	if (cheat->flags & CHEATFLAG_FIRINGRANGE) {
		if (frIsClassicWeaponUnlocked(cheat->time)) {
			unlocked++;
		}
	} else if (cheat->flags & CHEATFLAG_COMPLETION) {
		if (g_GameFile.besttimes[cheat->stage_index][0]) {
			unlocked++;
		}
		if (g_GameFile.besttimes[cheat->stage_index][1]) {
			unlocked++;
		}
		if (g_GameFile.besttimes[cheat->stage_index][2]) {
			unlocked++;
		}
	} else {
		if (g_GameFile.besttimes[cheat->stage_index][cheat->difficulty] &&
				g_GameFile.besttimes[cheat->stage_index][cheat->difficulty] <= cheat->time) {
			unlocked++;
		}
	}

	if ((cheat->flags & CHEATFLAG_TRANSFERPAK) && gamefileHasFlag(GAMEFILEFLAG_USED_TRANSFERPAK)) {
		unlocked++;
	}

	return unlocked;
}

bool cheatIsActive(s32 cheat_id)
{
	if (cheat_id < 32) {
		return g_CheatsActiveBank0 & (1 << cheat_id);
	}

	return g_CheatsActiveBank1 & (1 << cheat_id);
}

static void cheatActivate(s32 cheat_id)
{
	u32 prevplayernum;
	s32 playernum;

	switch (cheat_id) {
	case CHEAT_INVINCIBLE:
		// Make all players invincible
		prevplayernum = g_Vars.currentplayernum;

		for (playernum = 0; playernum < PLAYERCOUNT(); playernum++) {
			setCurrentPlayerNum(playernum);
			g_Vars.currentplayer->invincible = 1;
		}

		setCurrentPlayerNum(prevplayernum);
		break;
	case CHEAT_ALLGUNS:
		// Give all guns if only one player playing
		if (PLAYERCOUNT() == 1 && g_Vars.normmplayerisrunning == false) {
			prevplayernum = g_Vars.currentplayernum;

			for (playernum = 0; playernum < PLAYERCOUNT(); playernum++) {
				setCurrentPlayerNum(playernum);
				invSetAllGuns(true);
			}

			setCurrentPlayerNum(prevplayernum);
		}
		break;
	}

	if (cheat_id < 32) {
		g_CheatsActiveBank0 = g_CheatsActiveBank0 | (1 << cheat_id);
	} else {
		g_CheatsActiveBank1 = g_CheatsActiveBank1 | (1 << cheat_id);
	}
}

void cheatsInit(void)
{
	g_CheatsActiveBank0 = 0;
	g_CheatsActiveBank1 = 0;
	g_CheatsEnabledBank0 = 0;
	g_CheatsEnabledBank1 = 0;
}

/**
 * Apply cheats at level startup.
 */
void cheatsReset(void)
{
	s32 cheat_id;

	// Copy enabled cheats to active cheats, unless in CI training
	// or weapon cheats not in solo
	if (g_Vars.stagenum != STAGE_CITRAINING) {
		g_CheatsActiveBank0 = g_CheatsEnabledBank0;
		g_CheatsActiveBank1 = g_CheatsEnabledBank1;

		if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0 || g_Vars.normmplayerisrunning) {
			// Co-op/counter-op/multi - deactivate "Weapons for Jo in Solo" cheats
			g_CheatsActiveBank0 &= ~(
				(1 << CHEAT_TRENTSMAGNUM) |
				(1 << CHEAT_FARSIGHT) |
				(1 << CHEAT_ROCKETLAUNCHER) |
				(1 << CHEAT_SNIPERRIFLE) |
				(1 << CHEAT_XRAYSCANNER) |
				(1 << CHEAT_SUPERDRAGON) |
				(1 << CHEAT_LAPTOPGUN)
			);
			g_CheatsActiveBank1 &= ~(
				(1 << (CHEAT_PHOENIX - 32)) |
				(1 << (CHEAT_PSYCHOSISGUN - 32)) |
				(1 << (CHEAT_PP9I - 32)) |
				(1 << (CHEAT_CC13 - 32)) |
				(1 << (CHEAT_KL01313 - 32)) |
				(1 << (CHEAT_KF7SPECIAL - 32)) |
				(1 << (CHEAT_ZZT - 32)) |
				(1 << (CHEAT_DMC - 32)) |
				(1 << (CHEAT_AR53 - 32)) |
				(1 << (CHEAT_RCP45 - 32))
			);
		}
	} else {
		g_CheatsActiveBank0 = 0;
		g_CheatsActiveBank1 = 0;
	}

	// Set any "always on" cheats to active and properly activate all active cheats
	for (cheat_id = 0; cheat_id != NUM_CHEATS; cheat_id++) {
		if (g_Cheats[cheat_id].flags & CHEATFLAG_ALWAYSON) {
			if (cheatIsUnlocked(cheat_id)) {
				if (cheat_id < 32) {
					g_CheatsActiveBank0 = g_CheatsActiveBank0 | (1 << cheat_id);
				} else {
					g_CheatsActiveBank1 = g_CheatsActiveBank1 | (1 << cheat_id);
				}
			} else {
				if (cheat_id < 32) {
					g_CheatsActiveBank0 = g_CheatsActiveBank0 & ~(1 << cheat_id);
				} else {
					g_CheatsActiveBank1 = g_CheatsActiveBank1 & ~(1 << cheat_id);
				}
			}
		}

		if (cheatIsActive(cheat_id)) {
			cheatActivate(cheat_id);
		}
	}
}

static s32 cheatCheckboxMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GET:
		if (item->param < 32) {
			if (g_CheatsEnabledBank0 & (1 << item->param)) {
				return true;
			}

			return false;
		}

		if (g_CheatsEnabledBank1 & (1 << item->param)) {
			return true;
		}

		return false;
	case MENUOP_SET:
		if (cheatIsUnlocked(item->param)) {
			if (item->param < 32) {
				// Bank 0
				if (g_CheatsEnabledBank0 & (1 << item->param)) {
					g_CheatsEnabledBank0 = g_CheatsEnabledBank0 & ~(1 << item->param);
				} else {
					// If enabling Marquis or enemy rockets, turn off the other
					if (item->param == CHEAT_MARQUIS) {
						g_CheatsEnabledBank0 &= ~(1 << CHEAT_ENEMYROCKETS);
					}

					if (item->param == CHEAT_ENEMYROCKETS) {
						g_CheatsEnabledBank0 &= ~(1 << CHEAT_MARQUIS);
					}

					g_CheatsEnabledBank0 = g_CheatsEnabledBank0 | 1 << item->param;
				}
			} else {
				// Bank 1
				if (g_CheatsEnabledBank1 & (1 << item->param)) {
					if (1);
					g_CheatsEnabledBank1 = g_CheatsEnabledBank1 & ~(1 << item->param);
				} else {
					g_CheatsEnabledBank1 = g_CheatsEnabledBank1 | 1 << item->param;
				}
			}
		}
		break;
	}

	return 0;
}

static s32 cheatMenuHandleBuddyCheckbox(s32 operation, struct menuitem *item, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_GET:
		if (item->param == 0) {
			if (g_CheatsEnabledBank0 & (1 << CHEAT_PUGILIST | 1 << CHEAT_HOTSHOT | 1 << CHEAT_HITANDRUN | 1 << CHEAT_ALIEN)) {
				return false;
			}

			return true;
		}

		if (g_CheatsEnabledBank0 & (1 << item->param)) {
			return true;
		}

		return false;
	case MENUOP_SET:
		if (item->param == 0) {
			// Velvet
			g_CheatsEnabledBank0 &= ~(
				(1 << CHEAT_PUGILIST) |
				(1 << CHEAT_HOTSHOT) |
				(1 << CHEAT_HITANDRUN) |
				(1 << CHEAT_ALIEN)
			);
		} else if (cheatIsUnlocked(item->param)) {
			// Not Velvet
			g_CheatsEnabledBank0 = g_CheatsEnabledBank0 & ~(
				(1 << CHEAT_PUGILIST) |
				(1 << CHEAT_HOTSHOT) |
				(1 << CHEAT_HITANDRUN) |
				(1 << CHEAT_ALIEN)
			);
			g_CheatsEnabledBank0 = g_CheatsEnabledBank0 | (1 << item->param);
		}
	}

	return 0;
}

static char *cheatGetNameIfUnlocked(struct menuitem *item)
{
	if (cheatIsUnlocked(item->param)) {
		return langGet(g_Cheats[item->param].nametextid);
	}

	return langGet(L_MPWEAPONS_074); // "----------"
}

s32 cheatMenuHandleDialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_OPEN) {
		if (gbpakIsAnyPerfectDark()) {
			gamefileSetFlag(GAMEFILEFLAG_USED_TRANSFERPAK);
		}
	}

	if (operation == MENUOP_CLOSE) {
		if (gbpakIsAnyPerfectDark()) {
			gamefileSetFlag(GAMEFILEFLAG_USED_TRANSFERPAK);
		}
	}

	return 0;
}

/**
 * NTSC Beta uses g_StringPointer while newer versions use g_CheatMarqueeString.
 *
 * PAL Final introduces a string length check which ultimately doesn't do
 * anything.
 *
 * JPN final removes the colon characters from the format strings.
 */
static char *cheatGetMarquee(struct menuitem *arg0)
{
	u32 cheat_id;
	char *ptr;
	char difficultyname[256];
	char cheatname[256];

	if (g_Menus[g_MpPlayerNum].curdialog
			&& g_Menus[g_MpPlayerNum].curdialog->focuseditem
			&& g_Menus[g_MpPlayerNum].curdialog->focuseditem->type == MENUITEMTYPE_CHECKBOX) {
		cheat_id = g_Menus[g_MpPlayerNum].curdialog->focuseditem->param;

		if (g_Menus[g_MpPlayerNum].curdialog->definition == &g_CheatsBuddiesMenuDialog
				&& g_Menus[g_MpPlayerNum].curdialog->focuseditem == &g_CheatsBuddiesMenuItems[0]) {
			// Velvet
			sprintf(g_CheatMarqueeString, "%s: %s", langGet(L_MPWEAPONS_143), langGet(L_MPWEAPONS_117)); // "Buddy Available", "Velvet Dark"
		} else if (cheatIsUnlocked(cheat_id)) {
			// Show cheat name
			sprintf(g_CheatMarqueeString, "%s: %s\n",
					g_Menus[g_MpPlayerNum].curdialog->definition == &g_CheatsBuddiesMenuDialog ? langGet(L_MPWEAPONS_143) : langGet(L_MPWEAPONS_136), // "Buddy Available", "Cheat available"
					langGet(g_Cheats[cheat_id].nametextid)
			);
		} else {
			// Locked
			strcpy(cheatname, langGet(g_Cheats[cheat_id].nametextid));
			ptr = cheatname;

			while (*ptr != '\n') {
				ptr++;
			}

			*ptr = '\0';

			if (g_Cheats[cheat_id].flags & CHEATFLAG_COMPLETION) {
				sprintf(g_CheatMarqueeString, "%s %s: %s %s %s",
						langGet(L_MPWEAPONS_137), // "Complete"
						langGet(g_StageNames[g_Cheats[cheat_id].stage_index].name1),
						langGet(g_StageNames[g_Cheats[cheat_id].stage_index].name2),
						langGet(L_MPWEAPONS_138), // "for cheat:"
						&cheatname
				);
			} else {
				// Timed
				strcpy(difficultyname, langGet(L_OPTIONS_251 + g_Cheats[cheat_id].difficulty));
				ptr = difficultyname;

				while (*ptr != '\n') {
					ptr++;
				}

				*ptr = '\0';

				sprintf(g_CheatMarqueeString, "%s %s: %s %s %s %s %d:%02d %s %s",
						langGet(L_MPWEAPONS_137), // "Complete"
						langGet(g_StageNames[g_Cheats[cheat_id].stage_index].name1),
						langGet(g_StageNames[g_Cheats[cheat_id].stage_index].name2),
						langGet(L_MPWEAPONS_139), // "on"
						&difficultyname,
						langGet(L_MPWEAPONS_140), // "in under"
						g_Cheats[cheat_id].time / 60,
						g_Cheats[cheat_id].time % 60,
						langGet(L_MPWEAPONS_138), // "for cheat:"
						&cheatname
				);
			}

			if (g_Cheats[cheat_id].flags & CHEATFLAG_TRANSFERPAK) {
				strcat(g_CheatMarqueeString, langGet(L_MPWEAPONS_141)); // " or insert Game Boy ..."
			}

			strcat(g_CheatMarqueeString, "\n");
		}

		return g_CheatMarqueeString;
	}

	// No cheat selected
	return langGet(L_MPWEAPONS_142); // "Select cheat for information"
}

static s32 cheatMenuHandleTurnOffAllCheats(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		g_CheatsEnabledBank0 = 0;
		g_CheatsEnabledBank1 = 0;
	}

	return false;
}

s32 cheatGetByTimedStageIndex(s32 stage_index, s32 difficulty)
{
	s32 cheat_id;

	for (cheat_id = 0; cheat_id < NUM_CHEATS; cheat_id++) {
		if (g_Cheats[cheat_id].stage_index == stage_index &&
				g_Cheats[cheat_id].difficulty == difficulty &&
				(g_Cheats[cheat_id].flags & CHEATFLAG_COMPLETION) == 0 &&
				(g_Cheats[cheat_id].flags & CHEATFLAG_FIRINGRANGE) == 0) {
			return cheat_id;
		}
	}

	return -1;
}

s32 cheatGetByCompletedStageIndex(s32 stage_index)
{
	s32 cheat_id;

	for (cheat_id = 0; cheat_id < NUM_CHEATS; cheat_id++) {
		if (g_Cheats[cheat_id].stage_index == stage_index && (g_Cheats[cheat_id].flags & CHEATFLAG_COMPLETION)) {
			return cheat_id;
		}
	}

	return -1;
}

s32 cheatGetTime(s32 cheat_id)
{
	return g_Cheats[cheat_id].time;
}

char *cheatGetName(s32 cheat_id)
{
	return langGet(g_Cheats[cheat_id].nametextid);
}

struct menuitem g_CheatsFunMenuItems[] = {
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_DKMODE,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_SMALLJO,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_SMALLCHARACTERS,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_TEAMHEADSONLY,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_PLAYASELVIS,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_SLOMO,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000096,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_MARQUEE,
		0,
		MENUITEMFLAG_SMALLFONT | MENUITEMFLAG_MARQUEE_FADEBOTHSIDES,
		(u32)&cheatGetMarquee,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000096,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPMENU_477, // "Done"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_CheatsFunMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS_118, // "Fun"
	g_CheatsFunMenuItems,
	cheatMenuHandleDialog,
	0,
	NULL,
};

struct menuitem g_CheatsGameplayMenuItems[] = {
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_INVINCIBLE,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_CLOAKINGDEVICE,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_MARQUIS,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_JOSHIELD,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_SUPERSHIELD,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_ENEMYSHIELDS,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_ENEMYROCKETS,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_PERFECTDARKNESS,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000096,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_MARQUEE,
		0,
		MENUITEMFLAG_SMALLFONT | MENUITEMFLAG_MARQUEE_FADEBOTHSIDES,
		(u32)&cheatGetMarquee,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000096,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPMENU_477, // "Done"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_CheatsGameplayMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS_119, // "Gameplay"
	g_CheatsGameplayMenuItems,
	cheatMenuHandleDialog,
	0,
	NULL,
};

struct menuitem g_CheatsSoloWeaponsMenuItems[] = {
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_ROCKETLAUNCHER,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_SNIPERRIFLE,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_SUPERDRAGON,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_LAPTOPGUN,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_PHOENIX,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_PSYCHOSISGUN,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_TRENTSMAGNUM,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_FARSIGHT,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000096,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_MARQUEE,
		0,
		MENUITEMFLAG_SMALLFONT | MENUITEMFLAG_MARQUEE_FADEBOTHSIDES,
		(u32)&cheatGetMarquee,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000096,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPMENU_477, // "Done"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_CheatsSoloWeaponsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS_122, // "Weapons for Jo in Solo"
	g_CheatsSoloWeaponsMenuItems,
	cheatMenuHandleDialog,
	0,
	NULL,
};

struct menuitem g_CheatsClassicWeaponsMenuItems[] = {
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_PP9I,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_CC13,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_KL01313,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_KF7SPECIAL,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_ZZT,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_DMC,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_AR53,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_RCP45,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x000000c8,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_MARQUEE,
		0,
		MENUITEMFLAG_SMALLFONT | MENUITEMFLAG_MARQUEE_FADEBOTHSIDES,
		L_MPWEAPONS_144, // "Win Golds on the firing range to enable classic guns."
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x000000c8,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPMENU_477, // "Done"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_CheatsClassicWeaponsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS_123, // "Classic Weapons for Jo in Solo"
	g_CheatsClassicWeaponsMenuItems,
	cheatMenuHandleDialog,
	0,
	NULL,
};

struct menuitem g_CheatsWeaponsMenuItems[] = {
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_CLASSICSIGHT,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_UNLIMITEDAMMOLAPTOP,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_HURRICANEFISTS,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_UNLIMITEDAMMO,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_UNLIMITEDAMMONORELOADS,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_XRAYSCANNER,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_RTRACKER,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_ALLGUNS,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatCheckboxMenuHandler,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000096,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_MARQUEE,
		0,
		MENUITEMFLAG_SMALLFONT | MENUITEMFLAG_MARQUEE_FADEBOTHSIDES,
		(u32)&cheatGetMarquee,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000096,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPMENU_477, // "Done"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_CheatsWeaponsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS_120, // "Weapons"
	g_CheatsWeaponsMenuItems,
	cheatMenuHandleDialog,
	0,
	NULL,
};

struct menuitem g_CheatsBuddiesMenuItems[] = {
	{
		MENUITEMTYPE_CHECKBOX,
		0,
		0,
		L_MPWEAPONS_117, // "Velvet Dark"
		0,
		cheatMenuHandleBuddyCheckbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_PUGILIST,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatMenuHandleBuddyCheckbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_HOTSHOT,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatMenuHandleBuddyCheckbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_HITANDRUN,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatMenuHandleBuddyCheckbox,
	},
	{
		MENUITEMTYPE_CHECKBOX,
		CHEAT_ALIEN,
		0,
		(u32)&cheatGetNameIfUnlocked,
		0,
		cheatMenuHandleBuddyCheckbox,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000096,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_MARQUEE,
		0,
		MENUITEMFLAG_SMALLFONT | MENUITEMFLAG_MARQUEE_FADEBOTHSIDES,
		(u32)&cheatGetMarquee,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000096,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPMENU_477, // "Done"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_CheatsBuddiesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS_121, // "Buddies"
	g_CheatsBuddiesMenuItems,
	cheatMenuHandleDialog,
	0,
	NULL,
};

struct menuitem g_CheatsMenuItems[] = {
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPWEAPONS_118, // "Fun"
		0,
		(void *)&g_CheatsFunMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPWEAPONS_119, // "Gameplay"
		0,
		(void *)&g_CheatsGameplayMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPWEAPONS_122, // "Weapons for Jo in Solo"
		0,
		(void *)&g_CheatsSoloWeaponsMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPWEAPONS_123, // "Classic Weapons for Jo in Solo"
		0,
		(void *)&g_CheatsClassicWeaponsMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPWEAPONS_120, // "Weapons"
		0,
		(void *)&g_CheatsWeaponsMenuDialog,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_OPENSDIALOG,
		L_MPWEAPONS_121, // "Buddies"
		0,
		(void *)&g_CheatsBuddiesMenuDialog,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000096,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPWEAPONS_217, // "Turn off all Cheats"
		0,
		cheatMenuHandleTurnOffAllCheats,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000096,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPMENU_477, // "Done"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_CheatsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU_476, // "Cheats"
	g_CheatsMenuItems,
	cheatMenuHandleDialog,
	0,
	NULL,
};
