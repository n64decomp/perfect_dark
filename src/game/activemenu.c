#include <ultra64.h>
#include "constants.h"
#include "game/chraction.h"
#include "game/game_006900.h"
#include "game/bondgun.h"
#include "game/game_0b0fd0.h"
#include "game/tex.h"
#include "game/savebuffer.h"
#include "game/menu.h"
#include "game/inv.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/bot.h"
#include "game/botcmd.h"
#include "game/gfxmemory.h"
#include "game/training.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "lib/mtx.h"
#include "lib/ailist.h"
#include "lib/str.h"
#include "data.h"
#include "types.h"

struct activemenu g_AmMenus[4];
struct fontchar *g_AmFont1;
struct font *g_AmFont2;
s32 g_AmIndex;

struct menudialogdef g_AmPickTargetMenuDialog;

/**
 * This is a map of weapon numbers (as per the weapon set) to active menu slots.
 * For the purpose of this array, the AM slots are:
 *
 * 0-2 = top left to top right
 * 3,4 = left, right
 * 5-7 = bottom left to bottom right
 *
 * The values in the array are the slot numbers where that weapon will go.
 * For example, the value at index 2 is 6 which means weapon #2 from the
 * weapon set will go into slot 6 which is the bottom slot.
 */
const u8 g_AmMapping[] = {
	0, // unarmed
	1, // weapon #1
	6, // weapon #2
	3, // weapon #3
	4, // weapon #4
	7, // weapon #5
	5, // weapon #6
	2, // unused
};

struct chrdata *currentPlayerGetCommandingAibot(void)
{
	return g_Vars.currentplayer->commandingaibot;
}

void amOpenPickTarget(void)
{
	u32 prevplayernum = g_MpPlayerNum;

	if (!mpIsPaused()) {
		g_AmMenus[g_AmIndex].prevallbots = g_AmMenus[g_AmIndex].allbots;
		g_Vars.currentplayer->activemenumode = AMMODE_CLOSED;
		g_MpPlayerNum = g_Vars.currentplayerstats->mpindex;
		menuPushRootDialog(&g_AmPickTargetMenuDialog, MENUROOT_PICKTARGET);
		g_MpPlayerNum = prevplayernum;
	}
}

s32 amPickTargetMenuList(s32 operation, struct menuitem *item, union handlerdata *data)
{
	static u32 teamcolours[] = {
		0xff666600,
		0xffff0000,
		0x4444ff00,
		0xff00ff00,
		0x00ffff00,
		0xff885500,
		0x8800ff00,
		0x88445500,
	};

	switch (operation) {
	case MENUOP_GETOPTIONCOUNT:
		if (g_AmMenus[g_AmIndex].prevallbots) {
			// All bots: num bot opponents + all human players
			s32 count = 0;
			s32 i;
			struct chrdata *playerchr = g_Vars.currentplayer->prop->chr;

			for (i = PLAYERCOUNT(); i < g_MpNumChrs; i++) {
				if (g_MpAllChrPtrs[i]->team != playerchr->team) {
					count++;
				}
			}

			count += PLAYERCOUNT();
			data->list.value = count;
		} else {
			// Single bot: All except the bot itself
			data->list.value = g_MpNumChrs - 1;
		}
		break;
	case MENUOP_SET:
		{
			s32 numremaining;
			s32 chrindex;
			struct chrdata *botchr;
			struct chrdata *playerchr;
			s32 i;

			chrindex = -1;
			numremaining = data->list.value;
			botchr = g_MpAllChrPtrs[g_Vars.currentplayer->aibuddynums[g_AmMenus[g_AmIndex].screenindex - 2]];
			playerchr = g_Vars.currentplayer->prop->chr;

			do {
				chrindex++;

				if (g_AmMenus[g_AmIndex].prevallbots) {
					if (playerchr == g_MpAllChrPtrs[chrindex] || playerchr->team != g_MpAllChrPtrs[chrindex]->team) {
						numremaining--;
					}
				} else {
					if (botchr != g_MpAllChrPtrs[chrindex]) {
						numremaining--;
					}
				}
			} while (numremaining >= 0);

			if (g_AmMenus[g_AmIndex].prevallbots) {
				g_AmMenus[g_AmIndex].prevallbots = false;

				for (i = 0; i < g_Vars.currentplayer->numaibuddies; i++) {
					botApplyAttack(g_MpAllChrPtrs[g_Vars.currentplayer->aibuddynums[i]], g_MpAllChrPtrs[chrindex]->prop);
				}
			} else {
				botApplyAttack(botchr, g_MpAllChrPtrs[chrindex]->prop);
			}

			menuPopDialog();
		}
		break;
	case MENUOP_GETSELECTEDINDEX:
		data->list.value = 0xfffff;
		break;
	case MENUOP_RENDER:
		{
			Gfx *gdl = data->type19.gdl;
			struct menuitemrenderdata *renderdata = data->type19.renderdata2;
			s32 x;
			s32 y;
			u32 colour;
			s32 numremaining = (s32)data->type19.unk04;
			s32 chrindex = -1;
			struct chrdata *botchr = g_MpAllChrPtrs[g_Vars.currentplayer->aibuddynums[g_AmMenus[g_AmIndex].screenindex - 2]];
			struct chrdata *playerchr = g_Vars.currentplayer->prop->chr;

			do {
				chrindex++;

				if (g_AmMenus[g_AmIndex].prevallbots) {
					if (playerchr == g_MpAllChrPtrs[chrindex] || playerchr->team != g_MpAllChrPtrs[chrindex]->team) {
						numremaining--;
					}
				} else {
					if (botchr != g_MpAllChrPtrs[chrindex]) {
						numremaining--;
					}
				}
			} while (numremaining >= 0);

			colour = teamcolours[g_MpAllChrConfigPtrs[chrindex]->team] | (renderdata->colour & 0xff);

			if (renderdata->unk10) {
				u32 weight = menuGetSinOscFrac(40) * 255;
				colour = colourBlend(renderdata->colour | 0xffffff00, colourBlend(colour, colour & 0xff, 0x7f), weight);
			}

			x = renderdata->x + 10;
			y = renderdata->y + 1;

			gdl = text0f153628(gdl);
			gdl = textRenderProjected(gdl, &x, &y, g_MpAllChrConfigPtrs[chrindex]->name, g_CharsHandelGothicSm, g_FontHandelGothicSm, colour, viGetWidth(), viGetHeight(), 0, 0);
			gdl = text0f153780(gdl);
			return (s32)gdl;
		}
	case MENUOP_GETOPTIONHEIGHT:
		data->list.value = LINEHEIGHT;
		break;
	}

	return 0;
}

s32 amPickTargetMenuDialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	switch (operation) {
	case MENUOP_OPEN:
		g_PlayersWithControl[g_Vars.currentplayernum] = false;
		break;
	case MENUOP_TICK:
		g_PlayersWithControl[g_Vars.currentplayernum] = false;
		break;
	case MENUOP_CLOSE:
		g_PlayersWithControl[g_Vars.currentplayernum] = true;
		break;
	}

	return false;
}

struct menuitem g_AmPickTargetMenuItems[] = {
	{
		MENUITEMTYPE_LIST,
		0,
		MENUITEMFLAG_LIST_CUSTOMRENDER,
		0x0000005a,
		0,
		amPickTargetMenuList,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_AmPickTargetMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_OPTIONS_492, // "Pick Target"
	g_AmPickTargetMenuItems,
	amPickTargetMenuDialog,
	0,
	NULL,
};

void amSetAiBuddyTemperament(bool aggressive)
{
	s32 i;

	for (i = 0; i < g_Vars.numaibuddies; i++) {
		if (g_Vars.aibuddies[i]) {
			struct chrdata *chr = g_Vars.aibuddies[i]->chr;

			if (chr) {
				if (aggressive) {
					chr->hidden &= ~CHRHFLAG_PASSIVE;
				} else {
					chr->hidden |= CHRHFLAG_PASSIVE;
				}
			}
		}
	}
}

#if VERSION >= VERSION_NTSC_1_0
void amSetAiBuddyStealth(void)
{
	s32 i;

	for (i = 0; i < g_Vars.numaibuddies; i++) {
		if (g_Vars.aibuddies[i]) {
			struct chrdata *chr = g_Vars.aibuddies[i]->chr;

			if (chr && chr->prop
					&& !chrIsDead(chr)
					&& chr->ailist != ailistFindById(GAILIST_BUDDY_STEALTH)
					&& chr->actiontype != ACT_DRUGGEDDROP
					&& chr->actiontype != ACT_DRUGGEDKO
					&& chr->actiontype != ACT_DRUGGEDCOMINGUP) {
				chrStopFiring(chr);
				chr->ailist = ailistFindById(GAILIST_BUDDY_STEALTH);
				chr->aioffset = chr->ailist;
			}
		}
	}
}
#endif

s32 amGetFirstBuddyIndex(void)
{
	s32 i;

	for (i = 0; i < g_Vars.numaibuddies; i++) {
		if (g_Vars.aibuddies[i]) {
			struct chrdata *chr = g_Vars.aibuddies[i]->chr;

			if (chr && chr->actiontype != ACT_DIE
					&& chr->actiontype != ACT_DEAD
					&& chr->prop
					&& chr->model) {
				return i;
			}
		}
	}

	return -1;
}

void amApply(s32 slot)
{
	s32 numinvitems;
	s32 invindex;
	bool pass;
	s32 state;
	s32 weaponnum;
	s32 i;

	switch (g_AmMenus[g_AmIndex].screenindex) {
	case 0: // Weapon
		if (slot > 4) {
			slot--;
		}

		invindex = g_AmMenus[g_AmIndex].invindexes[slot];
		numinvitems = invGetCount();

		if (invindex < numinvitems) {
			weaponnum = invGetWeaponNumByIndex(invindex);
			pass = true;

			if (weaponnum) {
				state = currentPlayerGetDeviceState(weaponnum);

				if (state != DEVICESTATE_UNEQUIPPED) {
					pass = false;

					if (state == DEVICESTATE_INACTIVE) {
						currentPlayerSetDeviceActive(weaponnum, true);
					} else {
						currentPlayerSetDeviceActive(weaponnum, false);
					}
				}
			}

			if (pass) {
				pass = true;

				if (g_FrIsValidWeapon) {
					s32 weaponnum = frGetWeaponBySlot(frGetSlot());

					if (g_Vars.currentplayer->hands[HAND_RIGHT].gset.weaponnum == weaponnum) {
						pass = false;
					}
				}

				if (pass) {
					invSetCurrentIndex(invindex);

					if (invHasDoubleWeaponIncAllGuns(weaponnum, weaponnum)) {
						if (bgunGetWeaponNum(HAND_RIGHT) != weaponnum) {
							bgunEquipWeapon2(HAND_RIGHT, weaponnum);
						}

						if (bgunGetWeaponNum(HAND_LEFT) != weaponnum) {
							bgunEquipWeapon2(HAND_LEFT, weaponnum);
						}
					} else {
						if (bgunGetWeaponNum(HAND_RIGHT) != weaponnum) {
							bgunEquipWeapon2(HAND_RIGHT, weaponnum);
						}

						if (bgunGetWeaponNum(HAND_LEFT) != WEAPON_NONE) {
							bgunEquipWeapon2(HAND_LEFT, WEAPON_NONE);
						}
					}
				}
			}
		}
		break;
	case 1: // Function
		if (g_Vars.currentplayer->gunctrl.weaponnum >= WEAPON_UNARMED
				&& g_Vars.currentplayer->gunctrl.weaponnum <= WEAPON_COMBATBOOST
				&& g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].gunfuncs[(g_Vars.currentplayer->gunctrl.weaponnum - 1) >> 3] & (1 << ((g_Vars.currentplayer->gunctrl.weaponnum - 1) & 7))) {
			if (slot == 1) {
				g_AmMenus[g_AmIndex].togglefunc = true;
			}
		} else {
			if (slot != 1) {
				g_AmMenus[g_AmIndex].togglefunc = true;
			}
		}
		break;
	default:
		if (g_MissionConfig.iscoop) {
			if (amGetFirstBuddyIndex() > -1) {
				if (slot == 1) {
					amSetAiBuddyTemperament(true); // aggressive
				} else if (slot == 7) {
					amSetAiBuddyTemperament(false); // passive
#if VERSION >= VERSION_NTSC_1_0
				} else if (slot == 3) {
					amSetAiBuddyStealth();
#endif
				}
			}
		} else if (g_Vars.normmplayerisrunning) {
			if (g_AmMenus[g_AmIndex].allbots) {
				for (i = 0; i < g_Vars.currentplayer->numaibuddies; i++) {
					botcmdApply(g_MpAllChrPtrs[g_Vars.currentplayer->aibuddynums[i]], g_AmBotCommands[slot]);
				}
			} else {
				botcmdApply(g_MpAllChrPtrs[g_Vars.currentplayer->aibuddynums[g_AmMenus[g_AmIndex].screenindex - 2]], g_AmBotCommands[slot]);
			}
		}
	}
}

void amGetSlotDetails(s32 slot, u32 *flags, char *label)
{
	u32 weaponnum;
	s32 qty;
	s32 secs;
	s32 modulo;
	struct weaponfunc *prifunc;
	struct weaponfunc *secfunc;

	switch (g_AmMenus[g_AmIndex].screenindex) {
	case 0: // Weapon screen
		if (slot == 4) {
			strcpy(label, langGet(L_MISC_170)); // "Weapon"
			return;
		}

		if (slot > 4) {
			slot--;
		}

		if (invGetCurrentIndex() == g_AmMenus[g_AmIndex].invindexes[slot]) {
			*flags |= AMSLOTFLAG_CURRENT;
		}

		if (g_AmMenus[g_AmIndex].invindexes[slot] >= invGetCount()) {
			strcpy(label, "");
		} else {
			if (invGetWeaponNumByIndex(g_AmMenus[g_AmIndex].invindexes[slot]) == WEAPON_CLOAKINGDEVICE) {
				// Special case: "Cloak %d"
				qty = bgunGetReservedAmmoCount(AMMOTYPE_CLOAK);
				secs = qty / TICKS(60);
				modulo = (qty - (secs * TICKS(60))) * 100 / TICKS(60);
				sprintf(label, langGet(L_OPTIONS_491), secs + (modulo > 0 ? 1 : 0)); // "cloak %d"
			} else {
				strcpy(label, invGetShortNameByIndex(g_AmMenus[g_AmIndex].invindexes[slot]));
			}
		}

		weaponnum = invGetWeaponNumByIndex(g_AmMenus[g_AmIndex].invindexes[slot]);

		if (currentPlayerGetDeviceState(weaponnum) == DEVICESTATE_ACTIVE) {
			*flags |= AMSLOTFLAG_ACTIVE;
		}

		weaponnum = invGetWeaponNumByIndex(g_AmMenus[g_AmIndex].invindexes[slot]);

		if (!bgunHasAmmoForWeapon(weaponnum)) {
			*flags |= AMSLOTFLAG_NOAMMO;
		}
		break;
	case 1: // Function screen
		strcpy(label, "");

		if (slot == 4) {
			strcpy(label, langGet(L_MISC_171)); // "Function"
		} else if (slot == 1 || slot == 7) {
			prifunc = weaponGetFunction(&g_Vars.currentplayer->hands[HAND_RIGHT].gset, FUNC_PRIMARY);
			secfunc = weaponGetFunction(&g_Vars.currentplayer->hands[HAND_RIGHT].gset, FUNC_SECONDARY);

			if (slot == 1) {
				if (!secfunc || !FUNCISSEC()) {
					*flags |= AMSLOTFLAG_CURRENT;
				}

				if (prifunc) {
					strcpy(label, langGet(prifunc->name));
				}
			} else {
				if (!prifunc || FUNCISSEC()) {
					*flags |= AMSLOTFLAG_CURRENT;
				}

				if (secfunc) {
					strcpy(label, langGet(secfunc->name));
				}
			}
		}
		break;
	default: // Orders screen
		strcpy(label, "");

		if (g_MissionConfig.iscoop) {
			if (slot == 4) {
				strcpy(label, langGet(L_MISC_474)); // "Perfect Buddies"
			} else if (slot == 1) {
				strcpy(label, langGet(L_MISC_472)); // "Aggressive"
			} else if (slot == 7) {
				strcpy(label, langGet(L_MISC_473)); // "Passive"
#if VERSION >= VERSION_NTSC_1_0
			} else if (slot == 3) {
				strcpy(label, langGet(L_MISC_475)); // "Stealth"
#endif
			}
		} else {
			if (slot == 4) {
				strcpy(label, langGet(L_MISC_172)); // "Orders"
			} else {
				strcpy(label, botGetCommandName(g_AmBotCommands[slot]));
			}
		}
		break;
	}
}

void amReset(void)
{
	s32 i;
	s32 j;

	// @bug? Should this be set for each player?
	g_Vars.currentplayer->activemenumode = AMMODE_CLOSED;

	for (i = 0; i < ARRAYCOUNT(g_AmMenus); i++) {
		g_AmMenus[i].togglefunc = false;

		for (j = 0; j < ARRAYCOUNT(g_AmMenus[i].favourites); j++) {
			g_AmMenus[i].favourites[j] = 0xff;
		}

		if (g_Vars.normmplayerisrunning) {
			s32 index = 0;

			g_AmMenus[i].favourites[g_AmMapping[index]] = WEAPON_UNARMED;
			index++;

			for (j = 0; j < ARRAYCOUNT(g_MpSetup.weapons); j++) {
				s32 weaponnum = g_MpWeapons[g_MpSetup.weapons[j]].weaponnum;

				switch (weaponnum) {
				case WEAPON_NONE:
				case WEAPON_MPSHIELD:
				case WEAPON_DISABLED:
					break;
				default:
					g_AmMenus[i].favourites[g_AmMapping[index]] = weaponnum;
					index++;
					break;
				}
			}
		}
	}

#if VERSION == VERSION_JPN_FINAL
	g_AmFont1 = g_CharsHandelGothicSm;
	g_AmFont2 = g_FontHandelGothicSm;
#else
	if (PLAYERCOUNT() >= 2) {
		g_AmFont1 = g_CharsHandelGothicXs;
		g_AmFont2 = g_FontHandelGothicXs;
	} else {
		g_AmFont1 = g_CharsHandelGothicSm;
		g_AmFont2 = g_FontHandelGothicSm;
	}
#endif

	g_AmIndex = 0;
}

s16 amCalculateSlotWidth(void)
{
	s32 textheight;
	s32 textwidth;
	s32 max = 0;
	s32 i;
	u32 flags;
	char text[32];

	for (i = 0; i != 9; i++) {
		amGetSlotDetails(i, &flags, text);
		textMeasure(&textheight, &textwidth, text, g_AmFont1, g_AmFont2, 0);

		if (textwidth > max) {
			max = textwidth;
		}
	}

#if VERSION >= VERSION_NTSC_1_0
	if (PLAYERCOUNT() > 1) {
		max += 3;
	} else {
		max += 4;
	}
#else
	max += 4;
#endif

	return max;
}

void amChangeScreen(s32 step)
{
	s32 maxscreenindex;

	g_AmMenus[g_AmIndex].screenindex += step;

	if (g_Vars.normmplayerisrunning && (g_MpSetup.options & MPOPTION_TEAMSENABLED)) {
		if (g_AmMenus[g_AmIndex].allbots) {
			// Weapon selection, second function, and bot command menu

			// @bug: This is missing a check to see if there are any bots on
			// your team. In most cases this isn't a problem because the player
			// opens the screen for a single bot then uses R to switch to all
			// bots. When they do this without buddy bots the else part below
			// runs first, limits the max screen index to 1 and all is good.
			// But if you hold R as you switch to the bot command menu then this
			// part runs first and sets the screen index to an invalid value,
			// causing a crash.
			maxscreenindex = 2;
		} else {
			// Weapon selection, second function and one for each AI buddy
			maxscreenindex = g_Vars.currentplayer->numaibuddies + 1;
		}
	} else {
		// Solo missions, or MP with no teams
		if (g_MissionConfig.iscoop && amGetFirstBuddyIndex() >= 0) {
			// Weapon selection, second function and AI buddy commands
			maxscreenindex = 2;
		} else {
			// Weapon selection and second function
			maxscreenindex = 1;
		}
	}

	if (g_AmMenus[g_AmIndex].screenindex > maxscreenindex) {
		g_AmMenus[g_AmIndex].screenindex = 0;
	}

	if (g_AmMenus[g_AmIndex].screenindex < 0) {
		g_AmMenus[g_AmIndex].screenindex = maxscreenindex;
	}

	g_AmMenus[g_AmIndex].xradius = 10;
	g_AmMenus[g_AmIndex].dstx = -123;
	g_AmMenus[g_AmIndex].slotnum = 4;
	g_AmMenus[g_AmIndex].returntimer = 0;
	g_AmMenus[g_AmIndex].cornertimer = 0;
	g_AmMenus[g_AmIndex].alphafrac = 0;
	g_AmMenus[g_AmIndex].slotwidth = amCalculateSlotWidth();
}

void amAssignWeaponSlots(void)
{
	s32 numitems = invGetCount();
	u8 weaponnum;
	s32 i;
	s32 j;

	g_AmMenus[g_AmIndex].numitems = numitems;

	// Reset inventory indexes
	for (i = 0; i < ARRAYCOUNT(g_AmMenus[g_AmIndex].invindexes);) {
		g_AmMenus[g_AmIndex].invindexes[i] = 0xff;
		i++;
	}

	// Assign favourites
	for (i = 0; i < numitems; i++) {
		weaponnum = invGetWeaponNumByIndex(i);

		if ((weaponnum >= WEAPON_UNARMED && weaponnum <= WEAPON_DISGUISE41)
				|| weaponnum == WEAPON_SUICIDEPILL
				|| weaponnum == WEAPON_BACKUPDISK
				|| weaponnum == WEAPON_SUITCASE) {
			for (j = 0; j < ARRAYCOUNT(g_AmMenus[g_AmIndex].favourites); j++) {
				if (g_AmMenus[g_AmIndex].favourites[j] == weaponnum) {
					if (g_AmMenus[g_AmIndex].invindexes[j] == 0xff) {
						g_AmMenus[g_AmIndex].invindexes[j] = i;
					} else {
						// empty
					}
					break;
				}
			}
		}
	}

	// If there are still unused slots, fill the remaining slots in inventory
	// order with unfavourited weapons.
	for (i = 0; i < numitems; i++) {
		bool isfavourited = false;

		for (j = 0; j < ARRAYCOUNT(g_AmMenus[g_AmIndex].invindexes); j++) {
			if (g_AmMenus[g_AmIndex].invindexes[j] == i) {
				isfavourited = true;
			}
		}

		if (!isfavourited) {
			weaponnum = invGetWeaponNumByIndex(i);

			if ((weaponnum >= WEAPON_UNARMED && weaponnum <= WEAPON_DISGUISE41)
					|| weaponnum == WEAPON_SUICIDEPILL
					|| weaponnum == WEAPON_SUITCASE) {
				s32 useindex = -1;
				s32 j;

				// Try to find any mapping which is not yet used.
				// While it could just iterate the invitems or weaponnums arrays
				// directly, doing it using the mapping makes it allocate these
				// somewhat randomly rather than in slot order.
				for (j = 0; j < ARRAYCOUNT(g_AmMapping); j++) {
					if (g_AmMenus[g_AmIndex].favourites[g_AmMapping[j]] == 0xff) {
						useindex = j;
						break;
					}
				}

				if (useindex == -1) {
					// This part is pointless. If this part of the code is
					// reached then all the mappings were in use, and therefore
					// all the slots are in use too. There's no way this can
					// find any new slots.
					for (j = 0; j < ARRAYCOUNT(g_AmMapping); j++) {
						if (g_AmMenus[g_AmIndex].invindexes[g_AmMapping[j]] == 0xff) {
							useindex = j;
							break;
						}
					}
				}

				if (useindex >= 0) {
					g_AmMenus[g_AmIndex].invindexes[g_AmMapping[useindex]] = i;
					g_AmMenus[g_AmIndex].favourites[g_AmMapping[useindex]] = weaponnum;
				}
			}
		}
	}
}

void amOpen(void)
{
	if (g_Vars.currentplayer->gunctrl.passivemode == false) {
		g_AmIndex = g_Vars.currentplayernum;
		g_Vars.currentplayer->activemenumode = AMMODE_VIEW;
		g_PlayersWithControl[g_Vars.currentplayernum] = false;
		g_AmMenus[g_AmIndex].screenindex = 0;
		g_AmMenus[g_AmIndex].selpulse = 0;
		amAssignWeaponSlots();
		amChangeScreen(0);
		g_AmMenus[g_AmIndex].xradius = g_AmMenus[g_AmIndex].slotwidth + 5;
		g_AmMenus[g_AmIndex].alphafrac = 0.3;
		g_AmMenus[g_AmIndex].origscreennum = 0;
		g_AmMenus[g_AmIndex].prevallbots = 0;
		g_AmMenus[g_AmIndex].allbots = false;
	}
}

void amClose(void)
{
	if (g_AmMenus[g_AmIndex].slotnum != 4) {
		amApply(g_AmMenus[g_AmIndex].slotnum);
	}

	g_Vars.currentplayer->activemenumode = AMMODE_CLOSED;
	g_Vars.currentplayer->joybutinhibit = 0xffffffff;
	g_PlayersWithControl[g_Vars.currentplayernum] = 1;
}

bool amIsCramped(void)
{
#if VERSION == VERSION_JPN_FINAL
	if (PLAYERCOUNT() >= 3 && g_AmMenus[g_AmIndex].screenindex != 1) {
		return true;
	}

	if (IS4MB() && PLAYERCOUNT() == 2) {
		return true;
	}

	if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL
			&& PLAYERCOUNT() == 2
			&& g_AmMenus[g_AmIndex].screenindex != 1) {
		return true;
	}

	return false;
#else
	return (g_AmMenus[g_AmIndex].screenindex == 0 && PLAYERCOUNT() >= 3)
		|| (IS4MB() && PLAYERCOUNT() == 2)
		|| (PLAYERCOUNT() == 2 && optionsGetScreenSplit() == SCREENSPLIT_VERTICAL);
#endif
}

void amCalculateSlotPosition(s16 column, s16 row, s16 *x, s16 *y)
{
#if VERSION == VERSION_JPN_FINAL
	s32 playercount = PLAYERCOUNT();

	*x = g_AmMenus[g_AmIndex].xradius * (column - 1);
	*y = (row - 1) * 50;

	if (column != 1 && row != 1) {
		*x = *x / 2;
		*y = *y / 2;
	}

	if (amIsCramped()) {
		s32 offset = 1;

		if (row == 1) {
			offset = 3;
		}

		if (column == 0) {
			*x = -(g_AmMenus[g_AmIndex].slotwidth / 2) - offset;
		} else if (column == 2) {
			*x = g_AmMenus[g_AmIndex].slotwidth / 2 + offset;
		}
	} else {
		if (playercount >= 2) {
			if (row == 1 && !amIsCramped()) {
				*x = (*x * 6) / 7;
			}
		} else {
			if (playercount >= 3 && row == 1 && !amIsCramped()) {
				*x = (*x * 6) / 14;
			}
		}
	}

	if (playercount >= 2) {
		*y = (*y * 7) / 10;
	}

	*x += viGetViewLeft() / g_ScaleX + viGetViewWidth() / (g_ScaleX * 2);
	*y += viGetViewTop() + viGetViewHeight() / 2;

	if (playercount >= 2) {
		*y += 4;
	}

	if ((playercount == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB()))
			|| playercount >= 3) {
		if ((g_Vars.currentplayernum % 2) == 0) {
			*x += 8;
		} else {
			*x -= 8;
		}
	}
#elif VERSION >= VERSION_NTSC_1_0
	s32 playercount = PLAYERCOUNT();

	*x = g_AmMenus[g_AmIndex].xradius * (column - 1);
	*y = (row - 1) * 50;

	if (column != 1 && row != 1) {
		*x = *x / 2;
		*y = *y / 2;
	}

	if (amIsCramped()) {
		s32 offset = 1;

		if (row == 1) {
			offset = 3;
		}

		if (column == 0) {
			*x = -(g_AmMenus[g_AmIndex].slotwidth / 2) - offset;
		} else if (column == 2) {
			*x = g_AmMenus[g_AmIndex].slotwidth / 2 + offset;
		}
	} else {
		if (playercount >= 2) {
			if (row == 1 && !amIsCramped()) {
				*x = (*x * 6) / 7;
			}
		} else {
			if (playercount >= 3 && row == 1 && !amIsCramped()) {
				*x = (*x * 6) / 14;
			}
		}
	}

	if (playercount >= 2) {
		*y = (*y * 3) / 5;
	} else if (playercount >= 3) {
		*y = (*y * 3) / 5;
	}

	*x += viGetViewLeft() / g_ScaleX + viGetViewWidth() / (g_ScaleX * 2);
	*y += viGetViewTop() + viGetViewHeight() / 2;

	if ((playercount == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB()))
			|| playercount >= 3) {
		if ((g_Vars.currentplayernum % 2) == 0) {
			*x += 8;
		} else {
			*x -= 8;
		}
	}
#else
	s32 playercount = PLAYERCOUNT();

	*x = g_AmMenus[g_AmIndex].xradius * (column - 1);
	*y = (row - 1) * 50;

	if (column != 1 && row != 1) {
		*x = *x / 2;
		*y = *y / 2;

		if (1);
	}

	if (row == 1 && amIsCramped() && column != 1) {
		*x = *x / 2;

		if (*x < 0) {
			*x -= 4;
		} else {
			*x += 4;
		}
	}

	if (playercount >= 2) {
		if (row == 1 && !amIsCramped()) {
			*x = (*x * 6) / 7;
		}

		*y = (*y * 3) / 5;
	} else if (playercount >= 3) {
		if (row == 1 && !amIsCramped()) {
			*x = (*x * 6) / 14;
		}

		*y = (*y * 3) / 5;
	}

	*x += viGetViewLeft() / g_ScaleX + viGetViewWidth() / (g_ScaleX * 2);
	*y += viGetViewTop() + viGetViewHeight() / 2;

	if ((playercount == 2 && optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) || playercount >= 3) {
		if ((g_Vars.currentplayernum % 2) == 0) {
			*x += 8;
		} else {
			*x -= 8;
		}
	}
#endif
}

Gfx *amRenderText(Gfx *gdl, char *text, u32 colour, s16 left, s16 top)
{
	s32 x;
	s32 y;
	s32 textwidth;
	s32 textheight;

	textMeasure(&textheight, &textwidth, text, g_AmFont1, g_AmFont2, 0);

	x = left - (textwidth / 2);
	y = top - 4;
	gdl = textRenderProjected(gdl, &x, &y, text, g_AmFont1, g_AmFont2, colour, 320, 240, 0, 0);

	return gdl;
}

Gfx *amRenderAibotInfo(Gfx *gdl, s32 buddynum)
{
	s32 x;
	s32 y;
	s32 textwidth;
	s32 textheight;
	s32 weaponnum;
	char *weaponname;
	char *aibotname;
	s32 offset = 0;
#if VERSION >= VERSION_NTSC_1_0
	bool wide = false;
#endif

#if VERSION >= VERSION_NTSC_1_0
	if (PLAYERCOUNT() == 1 && optionsGetEffectiveScreenSize() != SCREENSIZE_FULL) {
		wide = true;
	}
#endif

#if VERSION >= VERSION_NTSC_1_0
	if ((PLAYERCOUNT() == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB())) || PLAYERCOUNT() >= 3)
#else
	if ((PLAYERCOUNT() == 2 && optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) || PLAYERCOUNT() >= 3)
#endif
	{
		if ((g_Vars.currentplayernum % 2) == 0) {
			offset = 8;
		} else {
			offset = -8;
		}
	}

	if (!g_AmMenus[g_AmIndex].allbots) {
		buddynum = g_Vars.currentplayer->aibuddynums[buddynum];
		aibotname = g_MpAllChrConfigPtrs[buddynum]->name;

		if (g_MpAllChrPtrs[buddynum]->aibot) {
			weaponnum = g_MpAllChrPtrs[buddynum]->aibot->weaponnum;
		} else {
			weaponnum = 0;
		}

		if (weaponnum < WEAPON_FALCON2 || weaponnum > WEAPON_HORIZONSCANNER) {
			weaponname = langGet(L_MISC_173); // "No Weapon"
		} else {
			weaponname = bgunGetShortName(weaponnum);
		}

		textMeasure(&textheight, &textwidth, aibotname, g_AmFont1, g_AmFont2, 0);

		x = viGetViewLeft() / g_ScaleX
			+ (s32)(viGetViewWidth() / g_ScaleX * 0.5f)
			- (s32)(textwidth * 0.5f)
			+ offset;

		if (PLAYERCOUNT() >= 2) {
			y = viGetViewTop() + 5;
		} else {
			y = viGetViewTop() + 10;
		}

#if VERSION >= VERSION_NTSC_1_0
		if (wide) {
			x = viGetViewLeft() / g_ScaleX + 32;
		}
#endif

#if VERSION >= VERSION_JPN_FINAL
		gdl = func0f1574d0jf(gdl, &x, &y, aibotname, g_AmFont1, g_AmFont2, -1,
				0x000000ff, 320, 240, 0, 0);

		y += (PLAYERCOUNT() >= 2) ? 0 : (s32)(textheight * 1.1f);
#else
		gdl = textRender(gdl, &x, &y, aibotname, g_AmFont1, g_AmFont2, -1,
				0x000000ff, 320, 240, 0, 0);

		y += (PLAYERCOUNT() >= 2) ? 0 : (s32)(textheight * 1.1f);
		textMeasure(&textheight, &textwidth, weaponname, g_AmFont1, g_AmFont2, 0);

		x = viGetViewLeft() / g_ScaleX
			+ (s32)(viGetViewWidth() / g_ScaleX * 0.5f)
			- (s32)(textwidth * 0.5f)
			+ offset;

#if VERSION >= VERSION_NTSC_1_0
		if (wide) {
			x = viGetViewLeft() / g_ScaleX + 32;
		}
#endif

		gdl = textRender(gdl, &x, &y, weaponname, g_AmFont1, g_AmFont2, -1,
				0x000000ff, 320, 240, 0, 0);
#endif

		g_Vars.currentplayer->commandingaibot = g_MpAllChrPtrs[buddynum];
	} else {
		char *title = langGet(L_MISC_215); // "All Simulants"

		textMeasure(&textheight, &textwidth, title, g_AmFont1, g_AmFont2, 0);

		x = viGetViewLeft() / g_ScaleX
			+ (s32)(viGetViewWidth() / g_ScaleX * 0.5f)
			- (s32)(textwidth * 0.5f)
			+ offset;

		if (PLAYERCOUNT() >= 2) {
			y = viGetViewTop() + 5;
		} else {
			y = viGetViewTop() + 10;
		}

#if VERSION >= VERSION_NTSC_1_0
		if (wide) {
			x = viGetViewLeft() / g_ScaleX + 32;
		}
#endif

#if VERSION >= VERSION_JPN_FINAL
		gdl = func0f1574d0jf(gdl, &x, &y, title, g_AmFont1, g_AmFont2, -1,
				0x000000ff, 320, 240, 0, 0);
#else
		gdl = textRender(gdl, &x, &y, title, g_AmFont1, g_AmFont2, -1,
				0x000000ff, 320, 240, 0, 0);
#endif
	}

	return gdl;
}

const char var7f1b2b34[] = "Here is where the activemenu sets favourites\n";
const char var7f1b2b64[] = "slot %d = guntype %d\n";
const char var7f1b2b7c[] = "put it in %d\n";

#if VERSION < VERSION_JPN_FINAL
const char var7f1b2b8c[] = "activemenu: setting up for multiplayer\n";
const char var7f1b2bb4[] = "activemenu: setting up for single player\n";
#endif

const char var7f1b2be0[] = "Put guntype %d in slot %d\n";
const char var7f1b2bfc[] = "ActiveMenu: Two or more equipped items of guntype %d\n";
const char var7f1b2c34[] = "FAV: Added gun %d to slot %d\n";

u8 var800719a0[][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8} };

Gfx *amRenderSlot(Gfx *gdl, char *text, s16 x, s16 y, s32 mode, s32 flags)
{
	static u32 obcol = 0xff00004f; // outer border
	static u32 ibcol = VERSION >= VERSION_NTSC_1_0 ? 0x3f00008f : 0x3f00006f; // inner background
	static u32 defcol = 0xff4f00ff; // text
	static u32 favcol = 0xffff7fff; // unused
	static u32 pickcol = 0xff4f00ff; // unused
	static u32 pickcol2 = 0xff4f00ff; // unused

	u32 colour;
	s32 paddingtop;
	s32 paddingbottom;

#if VERSION == VERSION_JPN_FINAL
	paddingtop = 7;
	paddingbottom = 7;
#else
	paddingtop = 6;
	paddingbottom = 6;

	if (PLAYERCOUNT() >= 2) {
		paddingtop = 5;
		paddingbottom = 3;
	}
#endif

	if (text == NULL || strcmp(text, "") == 0) {
		return gdl;
	}

	mainOverrideVariable("obcol", &obcol);
	mainOverrideVariable("ibcol", &ibcol);
	mainOverrideVariable("defcol", &defcol);
	mainOverrideVariable("favcol", &favcol);
	mainOverrideVariable("pickcol", &pickcol);
	mainOverrideVariable("pickcol2", &pickcol2);

	// Render background colour
	colour = (u32)(g_AmMenus[g_AmIndex].alphafrac * (ibcol & 0xff)) | (ibcol & 0xffffff00);

	if (mode == AMSLOTMODE_FOCUSED) {
		colour &= 0x000000ff;
	}

	if (mode == AMSLOTMODE_CURRENT || (flags & AMSLOTFLAG_CURRENT)) {
		colour &= 0x000000ff;
	}

	if (flags & AMSLOTFLAG_NOAMMO) {
		colour &= 0x000000ff;
	}

	if (g_Vars.currentplayer->activemenumode == AMMODE_EDIT) {
		colour = 0x0000006f;
	}

	gdl = textSetPrimColour(gdl, colour);

	gDPFillRectangleScaled(gdl++,
			x - g_AmMenus[g_AmIndex].slotwidth / 2 + 1,
			y - paddingtop + 1,
			x + g_AmMenus[g_AmIndex].slotwidth / 2,
			y + paddingbottom);

	gdl = text0f153838(gdl);

	// Render borders
	colour = obcol;

	if (flags & AMSLOTFLAG_NOAMMO) {
		colour &= 0x000000ff;
	}

	if (mode == AMSLOTMODE_CURRENT || (flags & AMSLOTFLAG_CURRENT)) {
		colour = 0xffffff8f;
	}

	colour = (u32)(g_AmMenus[g_AmIndex].alphafrac * (colour & 0xff)) | (colour & 0xffffff00);

	if (g_Vars.currentplayer->activemenumode == AMMODE_EDIT) {
		colour = 0x4f4f4f7f;
	}

	gdl = textSetPrimColour(gdl, colour);

	// Top border
	gDPFillRectangleScaled(gdl++,
			x - g_AmMenus[g_AmIndex].slotwidth / 2,
			y - paddingtop,
			x + g_AmMenus[g_AmIndex].slotwidth / 2 + 1,
			y - paddingtop + 1);

	// Bottom border
	gDPFillRectangleScaled(gdl++,
			x - g_AmMenus[g_AmIndex].slotwidth / 2,
			y + paddingbottom,
			x + g_AmMenus[g_AmIndex].slotwidth / 2 + 1,
			y + paddingbottom + 1);

	// Left border
	gDPFillRectangleScaled(gdl++,
			x - g_AmMenus[g_AmIndex].slotwidth / 2,
			y - paddingtop + 1,
			x - g_AmMenus[g_AmIndex].slotwidth / 2 + 1,
			y + paddingbottom);

	// Right border
	gDPFillRectangleScaled(gdl++,
			x + g_AmMenus[g_AmIndex].slotwidth / 2,
			y - paddingtop + 1,
			x + g_AmMenus[g_AmIndex].slotwidth / 2 + 1,
			y + paddingbottom);

	gdl = text0f153838(gdl);

	// Render text
	colour = defcol;

	if (mode == AMSLOTMODE_CURRENT || (flags & AMSLOTFLAG_CURRENT)) {
		colour = 0xffffffff;
	}

	if (flags & AMSLOTFLAG_ACTIVE) {
		colour = colourBlend(0xffaf8fff, colour, menuGetCosOscFrac(10) * 255.0f);
	}

	colour = (u32)(g_AmMenus[g_AmIndex].alphafrac * (colour & 0xff)) | (colour & 0xffffff00);

	if (g_Vars.currentplayer->activemenumode == AMMODE_EDIT) {
		colour = 0x4f4f4f7f;
	}

	gdl = amRenderText(gdl, text, colour, x, y);

	return gdl;
}

#if VERSION >= VERSION_NTSC_1_0
Gfx *amRender(Gfx *gdl)
{
	struct chrdata *chr;
	u32 flags;
	u32 *colours;
	struct gfxvtx *vertices;
	s32 mpchrnum;
	s16 column;
	s16 row;
	u32 colour;
	s16 slotx;
	s16 sloty;
	s16 tmp1;
	s16 tmp2;

#if PAL
	g_ScaleX = 1;
#else
	g_ScaleX = g_ViRes == VIRES_HI ? 2 : 1;
#endif

	g_AmIndex = g_Vars.currentplayernum;
	g_Vars.currentplayer->commandingaibot = NULL;

	if (g_Vars.currentplayer->activemenumode != AMMODE_CLOSED) {
		// Draw diamond
		gdl = text0f153628(gdl);

		if (g_Vars.normmplayerisrunning
				&& g_AmMenus[g_AmIndex].screenindex >= 2) {
			mpchrnum = g_Vars.currentplayer->aibuddynums[g_AmMenus[g_AmIndex].screenindex - 2];
		}

		if (g_AmMenus[g_AmIndex].dstx == -123) {
			amCalculateSlotPosition(
					g_AmMenus[g_AmIndex].slotnum % 3,
					g_AmMenus[g_AmIndex].slotnum / 3,
					&g_AmMenus[g_AmIndex].selx,
					&g_AmMenus[g_AmIndex].sely);
			g_AmMenus[g_AmIndex].dstx = g_AmMenus[g_AmIndex].selx;
			g_AmMenus[g_AmIndex].dsty = g_AmMenus[g_AmIndex].sely;
		} else {
			amCalculateSlotPosition(
					g_AmMenus[g_AmIndex].slotnum % 3,
					g_AmMenus[g_AmIndex].slotnum / 3,
					&g_AmMenus[g_AmIndex].dstx,
					&g_AmMenus[g_AmIndex].dsty);
		}

		gdl = func0f0d479c(gdl);

		colours = gfxAllocateColours(2);
		vertices = gfxAllocateVertices(8);

		gDPPipeSync(gdl++);
		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
		gDPSetAlphaCompare(gdl++, G_AC_NONE);
		gDPSetAlphaDither(gdl++, G_AD_NOISE);
		gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
		gSPClearGeometryMode(gdl++, G_CULL_BOTH);

		texSelect(&gdl, NULL, 2, 0, 2, 1, NULL);

		gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

		// Top
		amCalculateSlotPosition(1, 0, &slotx, &sloty);

		vertices[0].x = slotx * 10;
		vertices[0].y = sloty * 10;
		vertices[0].z = -10;

		// Right
		amCalculateSlotPosition(2, 1, &slotx, &sloty);

		vertices[1].x = slotx * 10;
		vertices[1].y = sloty * 10;
		vertices[1].z = -10;

		// Bottom
		amCalculateSlotPosition(1, 2, &slotx, &sloty);

		vertices[2].x = slotx * 10;
		vertices[2].y = sloty * 10;
		vertices[2].z = -10;

		// Left
		amCalculateSlotPosition(0, 1, &slotx, &sloty);

		vertices[3].x = slotx * 10;
		vertices[3].y = sloty * 10;
		vertices[3].z = -10;

		vertices[4].z = -10;
		vertices[5].z = -10;
		vertices[6].z = -10;
		vertices[7].z = -10;

		tmp2 = (vertices[1].x - vertices[3].x) / 8;
		tmp1 = (vertices[2].y - vertices[0].y) / 8;

		vertices[4].x = vertices[0].x;
		vertices[4].y = vertices[0].y + tmp1;
		vertices[5].x = vertices[1].x - tmp2;
		vertices[5].y = vertices[1].y;
		vertices[6].x = vertices[2].x;
		vertices[6].y = vertices[2].y - tmp1;
		vertices[7].x = vertices[3].x + tmp2;
		vertices[7].y = vertices[3].y;

		vertices[0].colour = 0;
		vertices[1].colour = 0;
		vertices[2].colour = 0;
		vertices[3].colour = 0;
		vertices[4].colour = 4;
		vertices[5].colour = 4;
		vertices[6].colour = 4;
		vertices[7].colour = 4;

		colours[0] = 0x22222200;
		colours[1] = 0x0000004f;

		gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 2);
		gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 8);

		gDPTri2(gdl++, 4, 5, 6, 6, 7, 4);
		gDPTri4(gdl++, 0, 4, 7, 7, 3, 0, 0, 1, 5, 5, 4, 0);
		gDPTri4(gdl++, 1, 2, 6, 6, 5, 1, 6, 2, 3, 3, 7, 6);

		gdl = func0f0d49c8(gdl);

		// Draw slots
		for (column = 0; column < 3; column++) {
			for (row = 0; row < 3; row++) {
				s16 slotx;
				s16 sloty;
				u32 mode;
				char text[32];
				s32 buddynum;

				mode = AMSLOTMODE_DEFAULT;
				amCalculateSlotPosition(column, row, &slotx, &sloty);
				flags = 0;

				if (column + row * 3 == g_AmMenus[g_AmIndex].slotnum) {
					mode = AMSLOTMODE_FOCUSED;
				}

				if (g_MissionConfig.iscoop && (buddynum = amGetFirstBuddyIndex(), buddynum >= 0)) {
					if (mode == AMSLOTMODE_DEFAULT && g_AmMenus[g_AmIndex].screenindex >= 2) {
						struct chrdata *chr = g_Vars.aibuddies[buddynum]->chr;

#if VERSION >= VERSION_NTSC_1_0
						if (var800719a0[row][column] == 7) {
							if (chr->hidden & CHRHFLAG_PASSIVE) {
								mode = AMSLOTMODE_CURRENT;
							}
						} else if (var800719a0[row][column] == 1) {
							if ((chr->hidden & CHRHFLAG_PASSIVE) == 0) {
								mode = AMSLOTMODE_CURRENT;
							}
						}
#else
						if (chr->hidden & CHRHFLAG_PASSIVE) {
							if (var800719a0[row][column] == 7) {
								mode = AMSLOTMODE_CURRENT;
							}
						} else {
							if (var800719a0[row][column] == 1) {
								mode = AMSLOTMODE_CURRENT;
							}
						}
#endif
					}
				} else {
					if (g_Vars.normmplayerisrunning
							&& mode == AMSLOTMODE_DEFAULT
							&& g_AmMenus[g_AmIndex].screenindex >= 2) {
						s32 slotcmd = g_AmBotCommands[var800719a0[row][column]];
						s32 botcmd = g_MpAllChrPtrs[mpchrnum]->aibot->command;

						if (slotcmd == botcmd) {
							mode = AMSLOTMODE_CURRENT;
						}
					}
				}

				colour = 0xffffffff;

				if (g_Vars.currentplayer->activemenumode == AMMODE_EDIT) {
					colour = 0x4f4f4f7f;
				}

				amGetSlotDetails(column + row * 3, &flags, text);

				if (column == 1 && row == 1) {
					if (!amIsCramped()) {
						gdl = amRenderText(gdl, text, colour, slotx, sloty);
					}
				} else {
					gdl = amRenderSlot(gdl, text, slotx, sloty, mode, flags);
				}
			}
		}

		// Render AI bot name and weapon
		{
			struct g_vars *vars = &g_Vars;

#if VERSION >= VERSION_JPN_FINAL
			if (!(g_MissionConfig.iscoop && amGetFirstBuddyIndex() >= 0)
					&& g_Vars.normmplayerisrunning
					&& g_AmMenus[g_AmIndex].screenindex >= 2) {
				gdl = amRenderAibotInfo(gdl, g_AmMenus[g_AmIndex].screenindex - 2);
			}
#else
			if (!(g_MissionConfig.iscoop && amGetFirstBuddyIndex() >= 0)
					&& vars->normmplayerisrunning
					&& g_AmMenus[g_AmIndex].screenindex >= 2) {
				gdl = amRenderAibotInfo(gdl, g_AmMenus[g_AmIndex].screenindex - 2);
			}
#endif
		}

		// Note: the column and row values will never be 1 here, so this
		// condition always passes. Looks like they intended to skip drawing the
		// selection box on the simulants screen if the middle box was selected.
		if (g_AmMenus[g_AmIndex].screenindex < 2 || column != 1 || row != 1) {
			// Render selection
			s32 halfwidth;
			s16 above;
			s16 below;

#if VERSION == VERSION_JPN_FINAL
			above = 7;
			below = 7;
#else
			above = 6;
			below = 6;

			if (PLAYERCOUNT() >= 2) {
				above = 5;
				below = 3;
			}
#endif

			colour = (sinf(g_AmMenus[g_AmIndex].selpulse) + 1) * 127;
			colour = 0xff0000ff | colour << 8 | colour << 16;

			if (g_Vars.currentplayer->activemenumode == AMMODE_EDIT) {
				colour = 0x4f4f4f7f;
			}

			gdl = textSetPrimColour(gdl, colour);

			halfwidth = g_AmMenus[g_AmIndex].slotwidth / 2;

#if VERSION >= VERSION_NTSC_1_0
			if (g_AmMenus[g_AmIndex].slotnum == 4) {
				if (amIsCramped()) {
					halfwidth = 1;
					above = 2;
					below = 0;
				} else if (PLAYERCOUNT() >= 2) {
					s32 textheight;
					s32 textwidth;
					char text[32];
					u32 flags;

					amGetSlotDetails(4, &flags, text);
					textMeasure(&textheight, &textwidth, text, g_AmFont1, g_AmFont2, 0);

					halfwidth = textwidth / 2 + 2;
				}
			}
#else
			if (g_AmMenus[g_AmIndex].slotnum == 4 && amIsCramped()) {
				halfwidth = 4;
			}
#endif

			// Top
			gDPFillRectangleScaled(gdl++,
					g_AmMenus[g_AmIndex].selx - halfwidth,
					g_AmMenus[g_AmIndex].sely - above,
					g_AmMenus[g_AmIndex].selx + halfwidth + 1,
					g_AmMenus[g_AmIndex].sely - above + 1);

			// Bottom
			gDPFillRectangleScaled(gdl++,
					g_AmMenus[g_AmIndex].selx - halfwidth,
					g_AmMenus[g_AmIndex].sely + below,
					g_AmMenus[g_AmIndex].selx + halfwidth + 1,
					g_AmMenus[g_AmIndex].sely + below + 1);

			// Left
			gDPFillRectangleScaled(gdl++,
					g_AmMenus[g_AmIndex].selx - halfwidth,
					g_AmMenus[g_AmIndex].sely - above + 1,
					g_AmMenus[g_AmIndex].selx - halfwidth + 1,
					g_AmMenus[g_AmIndex].sely + below);

			// Right
			gDPFillRectangleScaled(gdl++,
					g_AmMenus[g_AmIndex].selx + halfwidth,
					g_AmMenus[g_AmIndex].sely - above + 1,
					g_AmMenus[g_AmIndex].selx + halfwidth + 1,
					g_AmMenus[g_AmIndex].sely + below);

			gdl = text0f153838(gdl);
		}

		gdl = text0f153780(gdl);
	}

#if VERSION != VERSION_JPN_FINAL
	chr = g_Vars.currentplayer->commandingaibot;

	if (chr) {
		// Render health bar
		f32 healthfrac = (chr->maxdamage - chr->damage) / chr->maxdamage;
		f32 shieldfrac = chr->cshield * 0.125f;
		bool redhealth = false;
		s32 xoffset;
		s32 barwidth;
		s32 barheight;
		s32 part1width;
		s32 part1left;
		s32 part2left;
		s32 y;
		s32 a2;

		if (healthfrac < 0.25f) {
			redhealth = true;
		}

		barwidth = PLAYERCOUNT() >= 2 ? 48 : 64;
		barheight = PLAYERCOUNT() >= 2 ? 7 : 11;
		xoffset = 0;

#if VERSION >= VERSION_NTSC_1_0
		if ((PLAYERCOUNT() == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB())) || PLAYERCOUNT() >= 3) {
			xoffset = (g_Vars.currentplayernum & 1) == 0 ? 8 : -8;
		}

		if (PLAYERCOUNT() == 1 && optionsGetEffectiveScreenSize() != SCREENSIZE_FULL) {
			part1left = viGetViewLeft() / g_ScaleX + 32;
		} else {
			part1left = (s32) ((viGetViewWidth() / g_ScaleX) * 0.5f)
				+ (s32) (viGetViewLeft() / g_ScaleX)
				- (s32) (barwidth * 0.5f)
				+ xoffset;
		}
#else
		if ((PLAYERCOUNT() == 2 && optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) || PLAYERCOUNT() >= 3) {
			xoffset = (g_Vars.currentplayernum & 1) == 0 ? 8 : -8;
		}

		part1left = (s32) ((viGetViewWidth() / g_ScaleX) * 0.5f)
			+ (s32) (viGetViewLeft() / g_ScaleX)
			- (s32) (barwidth * 0.5f)
			+ xoffset;
#endif

		part1width = (s32) (barwidth * 0.25f) - 1;
		if (part1width);
		part2left = part1left + part1width + 2;

		if (healthfrac < 0) {
			healthfrac = 0;
		}

		gDPPipeSync(gdl++);
		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
		gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
		gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

		y = viGetViewTop() + viGetViewHeight() - (PLAYERCOUNT() >= 2 ? 19 : 34);

		if (redhealth) {
			a2 = part1left + part1width - (s32) (part1width * (0.25f - healthfrac) * 4.0f);

			gDPSetPrimColorViaWord(gdl++, 0, 0, 0xff000060);

			// Part 1 red
			gDPFillRectangleScaled(gdl++, a2, y, part1left + part1width, y + barheight);

			gDPSetPrimColorViaWord(gdl++, 0, 0, 0x00000080);

			// Part 1 black
			gDPFillRectangleScaled(gdl++, part1left, y, a2, y + barheight);

			// Part 2 black
			gDPFillRectangleScaled(gdl++, part2left, y, part1left + barwidth, y + barheight);
		} else {
			gDPSetPrimColorViaWord(gdl++, 0, 0, 0x00c00060);

			// Part 1 green
			gDPFillRectangleScaled(gdl++, part1left, y, part1left + part1width, y + barheight);

			// Part 2 green
			a2 = part1left + (s32) (barwidth * healthfrac);

			gDPFillRectangleScaled(gdl++, part2left, y, a2, y + barheight);

			gDPSetPrimColorViaWord(gdl++, 0, 0, 0x00000080);

			// Part 2 black
			gDPFillRectangleScaled(gdl++, a2, y, part1left + barwidth, y + barheight);
		}

		// Render shield bar
		y = y + barheight + 2;
		barheight = barheight * 0.75f;

		gDPSetPrimColorViaWord(gdl++, 0, 0, 0x00c00060);

		a2 = part1left + (s32) (barwidth * shieldfrac);

		gDPFillRectangleScaled(gdl++, part1left, y, a2, y + barheight);

		gDPSetPrimColorViaWord(gdl++, 0, 0, 0x00000080);

		gDPFillRectangleScaled(gdl++, a2, y, part1left + barwidth, y + barheight);
	}
#endif

	g_ScaleX = 1;

	return gdl;
}
#else
GLOBAL_ASM(
glabel amRender
/*  f0fcc34:	27bdfe50 */ 	addiu	$sp,$sp,-432
/*  f0fcc38:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0fcc3c:	8dce2d88 */ 	lw	$t6,0x2d88($t6)
/*  f0fcc40:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fcc44:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0fcc48:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f0fcc4c:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f0fcc50:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f0fcc54:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f0fcc58:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f0fcc5c:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f0fcc60:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f0fcc64:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f0fcc68:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0fcc6c:	15c10005 */ 	bne	$t6,$at,.NB0f0fcc84
/*  f0fcc70:	afa401b0 */ 	sw	$a0,0x1b0($sp)
/*  f0fcc74:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0fcc78:	3c018008 */ 	lui	$at,0x8008
/*  f0fcc7c:	10000004 */ 	beqz	$zero,.NB0f0fcc90
/*  f0fcc80:	ac2f2320 */ 	sw	$t7,0x2320($at)
.NB0f0fcc84:
/*  f0fcc84:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0fcc88:	3c018008 */ 	lui	$at,0x8008
/*  f0fcc8c:	ac382320 */ 	sw	$t8,0x2320($at)
.NB0f0fcc90:
/*  f0fcc90:	3c0a800a */ 	lui	$t2,0x800a
/*  f0fcc94:	254ae6c0 */ 	addiu	$t2,$t2,-6464
/*  f0fcc98:	8d59028c */ 	lw	$t9,0x28c($t2)
/*  f0fcc9c:	3c01800a */ 	lui	$at,0x800a
/*  f0fcca0:	ac3966a8 */ 	sw	$t9,0x66a8($at)
/*  f0fcca4:	8d4e0284 */ 	lw	$t6,0x284($t2)
/*  f0fcca8:	adc01c04 */ 	sw	$zero,0x1c04($t6)
/*  f0fccac:	8d430284 */ 	lw	$v1,0x284($t2)
/*  f0fccb0:	906f0250 */ 	lbu	$t7,0x250($v1)
/*  f0fccb4:	51e0031f */ 	beqzl	$t7,.NB0f0fd934
/*  f0fccb8:	8c621c04 */ 	lw	$v0,0x1c04($v1)
/*  f0fccbc:	0fc5374a */ 	jal	text0f153628
/*  f0fccc0:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0fccc4:	3c08800a */ 	lui	$t0,0x800a
/*  f0fccc8:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f0fcccc:	8d180318 */ 	lw	$t8,0x318($t0)
/*  f0fccd0:	afa201b0 */ 	sw	$v0,0x1b0($sp)
/*  f0fccd4:	13000010 */ 	beqz	$t8,.NB0f0fcd18
/*  f0fccd8:	3c19800a */ 	lui	$t9,0x800a
/*  f0fccdc:	8f3966a8 */ 	lw	$t9,0x66a8($t9)
/*  f0fcce0:	241e0038 */ 	addiu	$s8,$zero,0x38
/*  f0fcce4:	3c17800a */ 	lui	$s7,0x800a
/*  f0fcce8:	033e0019 */ 	multu	$t9,$s8
/*  f0fccec:	26f765c0 */ 	addiu	$s7,$s7,0x65c0
/*  f0fccf0:	00007012 */ 	mflo	$t6
/*  f0fccf4:	02ee7821 */ 	addu	$t7,$s7,$t6
/*  f0fccf8:	81e20000 */ 	lb	$v0,0x0($t7)
/*  f0fccfc:	28410002 */ 	slti	$at,$v0,0x2
/*  f0fcd00:	14200005 */ 	bnez	$at,.NB0f0fcd18
/*  f0fcd04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcd08:	8d180284 */ 	lw	$t8,0x284($t0)
/*  f0fcd0c:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f0fcd10:	932e1be5 */ 	lbu	$t6,0x1be5($t9)
/*  f0fcd14:	afae019c */ 	sw	$t6,0x19c($sp)
.NB0f0fcd18:
/*  f0fcd18:	3c0f800a */ 	lui	$t7,0x800a
/*  f0fcd1c:	8def66a8 */ 	lw	$t7,0x66a8($t7)
/*  f0fcd20:	241e0038 */ 	addiu	$s8,$zero,0x38
/*  f0fcd24:	3c17800a */ 	lui	$s7,0x800a
/*  f0fcd28:	01fe0019 */ 	multu	$t7,$s8
/*  f0fcd2c:	26f765c0 */ 	addiu	$s7,$s7,0x65c0
/*  f0fcd30:	2401ff85 */ 	addiu	$at,$zero,-123
/*  f0fcd34:	0000c012 */ 	mflo	$t8
/*  f0fcd38:	02f88021 */ 	addu	$s0,$s7,$t8
/*  f0fcd3c:	8619000a */ 	lh	$t9,0xa($s0)
/*  f0fcd40:	57210021 */ 	bnel	$t9,$at,.NB0f0fcdc8
/*  f0fcd44:	9202000e */ 	lbu	$v0,0xe($s0)
/*  f0fcd48:	9202000e */ 	lbu	$v0,0xe($s0)
/*  f0fcd4c:	24030003 */ 	addiu	$v1,$zero,0x3
/*  f0fcd50:	26060006 */ 	addiu	$a2,$s0,0x6
/*  f0fcd54:	0043001a */ 	div	$zero,$v0,$v1
/*  f0fcd58:	00002010 */ 	mfhi	$a0
/*  f0fcd5c:	00002812 */ 	mflo	$a1
/*  f0fcd60:	0005c400 */ 	sll	$t8,$a1,0x10
/*  f0fcd64:	00047400 */ 	sll	$t6,$a0,0x10
/*  f0fcd68:	14600002 */ 	bnez	$v1,.NB0f0fcd74
/*  f0fcd6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcd70:	0007000d */ 	break	0x7
.NB0f0fcd74:
/*  f0fcd74:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fcd78:	14610004 */ 	bne	$v1,$at,.NB0f0fcd8c
/*  f0fcd7c:	3c018000 */ 	lui	$at,0x8000
/*  f0fcd80:	14410002 */ 	bne	$v0,$at,.NB0f0fcd8c
/*  f0fcd84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcd88:	0006000d */ 	break	0x6
.NB0f0fcd8c:
/*  f0fcd8c:	000e2403 */ 	sra	$a0,$t6,0x10
/*  f0fcd90:	00182c03 */ 	sra	$a1,$t8,0x10
/*  f0fcd94:	0fc3ed87 */ 	jal	amCalculateSlotPosition
/*  f0fcd98:	26070008 */ 	addiu	$a3,$s0,0x8
/*  f0fcd9c:	3c0e800a */ 	lui	$t6,0x800a
/*  f0fcda0:	8dce66a8 */ 	lw	$t6,0x66a8($t6)
/*  f0fcda4:	01de0019 */ 	multu	$t6,$s8
/*  f0fcda8:	00007812 */ 	mflo	$t7
/*  f0fcdac:	02ef8021 */ 	addu	$s0,$s7,$t7
/*  f0fcdb0:	86180006 */ 	lh	$t8,0x6($s0)
/*  f0fcdb4:	86190008 */ 	lh	$t9,0x8($s0)
/*  f0fcdb8:	a618000a */ 	sh	$t8,0xa($s0)
/*  f0fcdbc:	1000000d */ 	beqz	$zero,.NB0f0fcdf4
/*  f0fcdc0:	a619000c */ 	sh	$t9,0xc($s0)
/*  f0fcdc4:	9202000e */ 	lbu	$v0,0xe($s0)
.NB0f0fcdc8:
/*  f0fcdc8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0fcdcc:	2606000a */ 	addiu	$a2,$s0,0xa
/*  f0fcdd0:	0041001a */ 	div	$zero,$v0,$at
/*  f0fcdd4:	00002010 */ 	mfhi	$a0
/*  f0fcdd8:	00002812 */ 	mflo	$a1
/*  f0fcddc:	0005c400 */ 	sll	$t8,$a1,0x10
/*  f0fcde0:	00047400 */ 	sll	$t6,$a0,0x10
/*  f0fcde4:	000e2403 */ 	sra	$a0,$t6,0x10
/*  f0fcde8:	00182c03 */ 	sra	$a1,$t8,0x10
/*  f0fcdec:	0fc3ed87 */ 	jal	amCalculateSlotPosition
/*  f0fcdf0:	2607000c */ 	addiu	$a3,$s0,0xc
.NB0f0fcdf4:
/*  f0fcdf4:	0fc347cf */ 	jal	func0f0d479c
/*  f0fcdf8:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0fcdfc:	afa201b0 */ 	sw	$v0,0x1b0($sp)
/*  f0fce00:	0fc588c3 */ 	jal	gfxAllocateColours
/*  f0fce04:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0fce08:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0fce0c:	0fc588a9 */ 	jal	gfxAllocateVertices
/*  f0fce10:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f0fce14:	8fae01b0 */ 	lw	$t6,0x1b0($sp)
/*  f0fce18:	3c18e700 */ 	lui	$t8,0xe700
/*  f0fce1c:	00408025 */ 	or	$s0,$v0,$zero
/*  f0fce20:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0fce24:	afaf01b0 */ 	sw	$t7,0x1b0($sp)
/*  f0fce28:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0fce2c:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0fce30:	8fb901b0 */ 	lw	$t9,0x1b0($sp)
/*  f0fce34:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0fce38:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*  f0fce3c:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f0fce40:	afae01b0 */ 	sw	$t6,0x1b0($sp)
/*  f0fce44:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0fce48:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f0fce4c:	8fb801b0 */ 	lw	$t8,0x1b0($sp)
/*  f0fce50:	3c0eb900 */ 	lui	$t6,0xb900
/*  f0fce54:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f0fce58:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0fce5c:	afb901b0 */ 	sw	$t9,0x1b0($sp)
/*  f0fce60:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0fce64:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f0fce68:	8faf01b0 */ 	lw	$t7,0x1b0($sp)
/*  f0fce6c:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0fce70:	37390402 */ 	ori	$t9,$t9,0x402
/*  f0fce74:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0fce78:	afb801b0 */ 	sw	$t8,0x1b0($sp)
/*  f0fce7c:	240e0020 */ 	addiu	$t6,$zero,0x20
/*  f0fce80:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f0fce84:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0fce88:	8faf01b0 */ 	lw	$t7,0x1b0($sp)
/*  f0fce8c:	3c19fc12 */ 	lui	$t9,0xfc12
/*  f0fce90:	37397e24 */ 	ori	$t9,$t9,0x7e24
/*  f0fce94:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0fce98:	afb801b0 */ 	sw	$t8,0x1b0($sp)
/*  f0fce9c:	240ef9fc */ 	addiu	$t6,$zero,-1540
/*  f0fcea0:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f0fcea4:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0fcea8:	8faf01b0 */ 	lw	$t7,0x1b0($sp)
/*  f0fceac:	3c19b600 */ 	lui	$t9,0xb600
/*  f0fceb0:	240e3000 */ 	addiu	$t6,$zero,0x3000
/*  f0fceb4:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0fceb8:	afb801b0 */ 	sw	$t8,0x1b0($sp)
/*  f0fcebc:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f0fcec0:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0fcec4:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0fcec8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0fcecc:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0fced0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0fced4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0fced8:	27a401b0 */ 	addiu	$a0,$sp,0x1b0
/*  f0fcedc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fcee0:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0fcee4:	0fc2c5c8 */ 	jal	texSelect
/*  f0fcee8:	00003825 */ 	or	$a3,$zero,$zero
/*  f0fceec:	8fb901b0 */ 	lw	$t9,0x1b0($sp)
/*  f0fcef0:	3c0fb900 */ 	lui	$t7,0xb900
/*  f0fcef4:	3c180050 */ 	lui	$t8,0x50
/*  f0fcef8:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f0fcefc:	27b30192 */ 	addiu	$s3,$sp,0x192
/*  f0fcf00:	27b40190 */ 	addiu	$s4,$sp,0x190
/*  f0fcf04:	afae01b0 */ 	sw	$t6,0x1b0($sp)
/*  f0fcf08:	37184240 */ 	ori	$t8,$t8,0x4240
/*  f0fcf0c:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f0fcf10:	02803825 */ 	or	$a3,$s4,$zero
/*  f0fcf14:	02603025 */ 	or	$a2,$s3,$zero
/*  f0fcf18:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0fcf1c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fcf20:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f0fcf24:	0fc3ed87 */ 	jal	amCalculateSlotPosition
/*  f0fcf28:	af380004 */ 	sw	$t8,0x4($t9)
/*  f0fcf2c:	87b90192 */ 	lh	$t9,0x192($sp)
/*  f0fcf30:	2411000a */ 	addiu	$s1,$zero,0xa
/*  f0fcf34:	2412fff6 */ 	addiu	$s2,$zero,-10
/*  f0fcf38:	03310019 */ 	multu	$t9,$s1
/*  f0fcf3c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0fcf40:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0fcf44:	02603025 */ 	or	$a2,$s3,$zero
/*  f0fcf48:	02803825 */ 	or	$a3,$s4,$zero
/*  f0fcf4c:	00007012 */ 	mflo	$t6
/*  f0fcf50:	a60e0000 */ 	sh	$t6,0x0($s0)
/*  f0fcf54:	87af0190 */ 	lh	$t7,0x190($sp)
/*  f0fcf58:	a6120004 */ 	sh	$s2,0x4($s0)
/*  f0fcf5c:	01f10019 */ 	multu	$t7,$s1
/*  f0fcf60:	0000c012 */ 	mflo	$t8
/*  f0fcf64:	a6180002 */ 	sh	$t8,0x2($s0)
/*  f0fcf68:	0fc3ed87 */ 	jal	amCalculateSlotPosition
/*  f0fcf6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcf70:	87b90192 */ 	lh	$t9,0x192($sp)
/*  f0fcf74:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0fcf78:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f0fcf7c:	03310019 */ 	multu	$t9,$s1
/*  f0fcf80:	02603025 */ 	or	$a2,$s3,$zero
/*  f0fcf84:	02803825 */ 	or	$a3,$s4,$zero
/*  f0fcf88:	00007012 */ 	mflo	$t6
/*  f0fcf8c:	a60e000c */ 	sh	$t6,0xc($s0)
/*  f0fcf90:	87af0190 */ 	lh	$t7,0x190($sp)
/*  f0fcf94:	a6120010 */ 	sh	$s2,0x10($s0)
/*  f0fcf98:	01f10019 */ 	multu	$t7,$s1
/*  f0fcf9c:	0000c012 */ 	mflo	$t8
/*  f0fcfa0:	a618000e */ 	sh	$t8,0xe($s0)
/*  f0fcfa4:	0fc3ed87 */ 	jal	amCalculateSlotPosition
/*  f0fcfa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcfac:	87b90192 */ 	lh	$t9,0x192($sp)
/*  f0fcfb0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fcfb4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0fcfb8:	03310019 */ 	multu	$t9,$s1
/*  f0fcfbc:	02603025 */ 	or	$a2,$s3,$zero
/*  f0fcfc0:	02803825 */ 	or	$a3,$s4,$zero
/*  f0fcfc4:	00007012 */ 	mflo	$t6
/*  f0fcfc8:	a60e0018 */ 	sh	$t6,0x18($s0)
/*  f0fcfcc:	87af0190 */ 	lh	$t7,0x190($sp)
/*  f0fcfd0:	a612001c */ 	sh	$s2,0x1c($s0)
/*  f0fcfd4:	01f10019 */ 	multu	$t7,$s1
/*  f0fcfd8:	0000c012 */ 	mflo	$t8
/*  f0fcfdc:	a618001a */ 	sh	$t8,0x1a($s0)
/*  f0fcfe0:	0fc3ed87 */ 	jal	amCalculateSlotPosition
/*  f0fcfe4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fcfe8:	87b90192 */ 	lh	$t9,0x192($sp)
/*  f0fcfec:	8602000c */ 	lh	$v0,0xc($s0)
/*  f0fcff0:	8607001a */ 	lh	$a3,0x1a($s0)
/*  f0fcff4:	03310019 */ 	multu	$t9,$s1
/*  f0fcff8:	86030002 */ 	lh	$v1,0x2($s0)
/*  f0fcffc:	00e33023 */ 	subu	$a2,$a3,$v1
/*  f0fd000:	00007012 */ 	mflo	$t6
/*  f0fd004:	a60e0024 */ 	sh	$t6,0x24($s0)
/*  f0fd008:	87af0190 */ 	lh	$t7,0x190($sp)
/*  f0fd00c:	86050024 */ 	lh	$a1,0x24($s0)
/*  f0fd010:	a6120028 */ 	sh	$s2,0x28($s0)
/*  f0fd014:	01f10019 */ 	multu	$t7,$s1
/*  f0fd018:	00452023 */ 	subu	$a0,$v0,$a1
/*  f0fd01c:	a6120034 */ 	sh	$s2,0x34($s0)
/*  f0fd020:	a6120040 */ 	sh	$s2,0x40($s0)
/*  f0fd024:	a612004c */ 	sh	$s2,0x4c($s0)
/*  f0fd028:	a6120058 */ 	sh	$s2,0x58($s0)
/*  f0fd02c:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f0fd030:	a2000013 */ 	sb	$zero,0x13($s0)
/*  f0fd034:	a200001f */ 	sb	$zero,0x1f($s0)
/*  f0fd038:	a200002b */ 	sb	$zero,0x2b($s0)
/*  f0fd03c:	0000c012 */ 	mflo	$t8
/*  f0fd040:	a6180026 */ 	sh	$t8,0x26($s0)
/*  f0fd044:	04810003 */ 	bgez	$a0,.NB0f0fd054
/*  f0fd048:	0004c8c3 */ 	sra	$t9,$a0,0x3
/*  f0fd04c:	24810007 */ 	addiu	$at,$a0,0x7
/*  f0fd050:	0001c8c3 */ 	sra	$t9,$at,0x3
.NB0f0fd054:
/*  f0fd054:	00197400 */ 	sll	$t6,$t9,0x10
/*  f0fd058:	000e7c03 */ 	sra	$t7,$t6,0x10
/*  f0fd05c:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0fd060:	860f0000 */ 	lh	$t7,0x0($s0)
/*  f0fd064:	860e000e */ 	lh	$t6,0xe($s0)
/*  f0fd068:	04c10003 */ 	bgez	$a2,.NB0f0fd078
/*  f0fd06c:	0006c0c3 */ 	sra	$t8,$a2,0x3
/*  f0fd070:	24c10007 */ 	addiu	$at,$a2,0x7
/*  f0fd074:	0001c0c3 */ 	sra	$t8,$at,0x3
.NB0f0fd078:
/*  f0fd078:	03003025 */ 	or	$a2,$t8,$zero
/*  f0fd07c:	0044c823 */ 	subu	$t9,$v0,$a0
/*  f0fd080:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f0fd084:	860f0018 */ 	lh	$t7,0x18($s0)
/*  f0fd088:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f0fd08c:	0066c021 */ 	addu	$t8,$v1,$a2
/*  f0fd090:	a60e003e */ 	sh	$t6,0x3e($s0)
/*  f0fd094:	860e0026 */ 	lh	$t6,0x26($s0)
/*  f0fd098:	a6180032 */ 	sh	$t8,0x32($s0)
/*  f0fd09c:	a619003c */ 	sh	$t9,0x3c($s0)
/*  f0fd0a0:	00e6c023 */ 	subu	$t8,$a3,$a2
/*  f0fd0a4:	a618004a */ 	sh	$t8,0x4a($s0)
/*  f0fd0a8:	00a4c821 */ 	addu	$t9,$a1,$a0
/*  f0fd0ac:	a60f0048 */ 	sh	$t7,0x48($s0)
/*  f0fd0b0:	a6190054 */ 	sh	$t9,0x54($s0)
/*  f0fd0b4:	a2020037 */ 	sb	$v0,0x37($s0)
/*  f0fd0b8:	a2020043 */ 	sb	$v0,0x43($s0)
/*  f0fd0bc:	a202004f */ 	sb	$v0,0x4f($s0)
/*  f0fd0c0:	a202005b */ 	sb	$v0,0x5b($s0)
/*  f0fd0c4:	3c0f2222 */ 	lui	$t7,0x2222
/*  f0fd0c8:	a60e0056 */ 	sh	$t6,0x56($s0)
/*  f0fd0cc:	35ef2200 */ 	ori	$t7,$t7,0x2200
/*  f0fd0d0:	2418004f */ 	addiu	$t8,$zero,0x4f
/*  f0fd0d4:	aeaf0000 */ 	sw	$t7,0x0($s5)
/*  f0fd0d8:	aeb80004 */ 	sw	$t8,0x4($s5)
/*  f0fd0dc:	8fb101b0 */ 	lw	$s1,0x1b0($sp)
/*  f0fd0e0:	3c0f0704 */ 	lui	$t7,0x704
/*  f0fd0e4:	35ef0008 */ 	ori	$t7,$t7,0x8
/*  f0fd0e8:	262e0008 */ 	addiu	$t6,$s1,0x8
/*  f0fd0ec:	afae01b0 */ 	sw	$t6,0x1b0($sp)
/*  f0fd0f0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0fd0f4:	0c013100 */ 	jal	osVirtualToPhysical
/*  f0fd0f8:	ae2f0000 */ 	sw	$t7,0x0($s1)
/*  f0fd0fc:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0fd100:	8fb201b0 */ 	lw	$s2,0x1b0($sp)
/*  f0fd104:	3c0e0470 */ 	lui	$t6,0x470
/*  f0fd108:	35ce0060 */ 	ori	$t6,$t6,0x60
/*  f0fd10c:	26590008 */ 	addiu	$t9,$s2,0x8
/*  f0fd110:	afb901b0 */ 	sw	$t9,0x1b0($sp)
/*  f0fd114:	02002025 */ 	or	$a0,$s0,$zero
/*  f0fd118:	0c013100 */ 	jal	osVirtualToPhysical
/*  f0fd11c:	ae4e0000 */ 	sw	$t6,0x0($s2)
/*  f0fd120:	ae420004 */ 	sw	$v0,0x4($s2)
/*  f0fd124:	8faf01b0 */ 	lw	$t7,0x1b0($sp)
/*  f0fd128:	3c19b100 */ 	lui	$t9,0xb100
/*  f0fd12c:	37390046 */ 	ori	$t9,$t9,0x46
/*  f0fd130:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0fd134:	afb801b0 */ 	sw	$t8,0x1b0($sp)
/*  f0fd138:	240e7654 */ 	addiu	$t6,$zero,0x7654
/*  f0fd13c:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f0fd140:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0fd144:	8faf01b0 */ 	lw	$t7,0x1b0($sp)
/*  f0fd148:	3c19b100 */ 	lui	$t9,0xb100
/*  f0fd14c:	3c0e4510 */ 	lui	$t6,0x4510
/*  f0fd150:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0fd154:	afb801b0 */ 	sw	$t8,0x1b0($sp)
/*  f0fd158:	35ce3740 */ 	ori	$t6,$t6,0x3740
/*  f0fd15c:	37390507 */ 	ori	$t9,$t9,0x507
/*  f0fd160:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0fd164:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f0fd168:	8faf01b0 */ 	lw	$t7,0x1b0($sp)
/*  f0fd16c:	3c0e7326 */ 	lui	$t6,0x7326
/*  f0fd170:	3c19b100 */ 	lui	$t9,0xb100
/*  f0fd174:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0fd178:	afb801b0 */ 	sw	$t8,0x1b0($sp)
/*  f0fd17c:	37396316 */ 	ori	$t9,$t9,0x6316
/*  f0fd180:	35ce5621 */ 	ori	$t6,$t6,0x5621
/*  f0fd184:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f0fd188:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0fd18c:	0fc34852 */ 	jal	func0f0d49c8
/*  f0fd190:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0fd194:	3c158007 */ 	lui	$s5,0x8007
/*  f0fd198:	afa201b0 */ 	sw	$v0,0x1b0($sp)
/*  f0fd19c:	26b53f30 */ 	addiu	$s5,$s5,0x3f30
/*  f0fd1a0:	00009025 */ 	or	$s2,$zero,$zero
/*  f0fd1a4:	27b60134 */ 	addiu	$s6,$sp,0x134
/*  f0fd1a8:	00008825 */ 	or	$s1,$zero,$zero
.NB0f0fd1ac:
/*  f0fd1ac:	00122400 */ 	sll	$a0,$s2,0x10
.NB0f0fd1b0:
/*  f0fd1b0:	00112c00 */ 	sll	$a1,$s1,0x10
/*  f0fd1b4:	0005c403 */ 	sra	$t8,$a1,0x10
/*  f0fd1b8:	00047c03 */ 	sra	$t7,$a0,0x10
/*  f0fd1bc:	00008025 */ 	or	$s0,$zero,$zero
/*  f0fd1c0:	01e02025 */ 	or	$a0,$t7,$zero
/*  f0fd1c4:	03002825 */ 	or	$a1,$t8,$zero
/*  f0fd1c8:	27a6015a */ 	addiu	$a2,$sp,0x15a
/*  f0fd1cc:	27a70158 */ 	addiu	$a3,$sp,0x158
/*  f0fd1d0:	0fc3ed87 */ 	jal	amCalculateSlotPosition
/*  f0fd1d4:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f0fd1d8:	3c0e800a */ 	lui	$t6,0x800a
/*  f0fd1dc:	8dce66a8 */ 	lw	$t6,0x66a8($t6)
/*  f0fd1e0:	0011c880 */ 	sll	$t9,$s1,0x2
/*  f0fd1e4:	0331c823 */ 	subu	$t9,$t9,$s1
/*  f0fd1e8:	01de0019 */ 	multu	$t6,$s8
/*  f0fd1ec:	02599821 */ 	addu	$s3,$s2,$t9
/*  f0fd1f0:	afa001a8 */ 	sw	$zero,0x1a8($sp)
/*  f0fd1f4:	3c0e800a */ 	lui	$t6,0x800a
/*  f0fd1f8:	00007812 */ 	mflo	$t7
/*  f0fd1fc:	02efc021 */ 	addu	$t8,$s7,$t7
/*  f0fd200:	9319000e */ 	lbu	$t9,0xe($t8)
/*  f0fd204:	16790002 */ 	bne	$s3,$t9,.NB0f0fd210
/*  f0fd208:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd20c:	24100001 */ 	addiu	$s0,$zero,0x1
.NB0f0fd210:
/*  f0fd210:	81cf27ab */ 	lb	$t7,0x27ab($t6)
/*  f0fd214:	05e1002b */ 	bgez	$t7,.NB0f0fd2c4
/*  f0fd218:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd21c:	0fc3e8bd */ 	jal	amGetFirstBuddyIndex
/*  f0fd220:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd224:	04400027 */ 	bltz	$v0,.NB0f0fd2c4
/*  f0fd228:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd22c:	16000044 */ 	bnez	$s0,.NB0f0fd340
/*  f0fd230:	3c18800a */ 	lui	$t8,0x800a
/*  f0fd234:	8f1866a8 */ 	lw	$t8,0x66a8($t8)
/*  f0fd238:	031e0019 */ 	multu	$t8,$s8
/*  f0fd23c:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f0fd240:	0000c812 */ 	mflo	$t9
/*  f0fd244:	02f97021 */ 	addu	$t6,$s7,$t9
/*  f0fd248:	81cf0000 */ 	lb	$t7,0x0($t6)
/*  f0fd24c:	3c19800a */ 	lui	$t9,0x800a
/*  f0fd250:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0fd254:	29e10002 */ 	slti	$at,$t7,0x2
/*  f0fd258:	14200039 */ 	bnez	$at,.NB0f0fd340
/*  f0fd25c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd260:	8f39eb78 */ 	lw	$t9,-0x1488($t9)
/*  f0fd264:	0011c080 */ 	sll	$t8,$s1,0x2
/*  f0fd268:	0311c023 */ 	subu	$t8,$t8,$s1
/*  f0fd26c:	8f230004 */ 	lw	$v1,0x4($t9)
/*  f0fd270:	02b8c821 */ 	addu	$t9,$s5,$t8
/*  f0fd274:	8c6e0014 */ 	lw	$t6,0x14($v1)
/*  f0fd278:	31cf0400 */ 	andi	$t7,$t6,0x400
/*  f0fd27c:	11e0000b */ 	beqz	$t7,.NB0f0fd2ac
/*  f0fd280:	03327021 */ 	addu	$t6,$t9,$s2
/*  f0fd284:	0011c080 */ 	sll	$t8,$s1,0x2
/*  f0fd288:	0311c023 */ 	subu	$t8,$t8,$s1
/*  f0fd28c:	02b8c821 */ 	addu	$t9,$s5,$t8
/*  f0fd290:	03327021 */ 	addu	$t6,$t9,$s2
/*  f0fd294:	91cf0000 */ 	lbu	$t7,0x0($t6)
/*  f0fd298:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0fd29c:	15e10028 */ 	bne	$t7,$at,.NB0f0fd340
/*  f0fd2a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd2a4:	10000026 */ 	beqz	$zero,.NB0f0fd340
/*  f0fd2a8:	24100002 */ 	addiu	$s0,$zero,0x2
.NB0f0fd2ac:
/*  f0fd2ac:	91cf0000 */ 	lbu	$t7,0x0($t6)
/*  f0fd2b0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fd2b4:	15e10022 */ 	bne	$t7,$at,.NB0f0fd340
/*  f0fd2b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd2bc:	10000020 */ 	beqz	$zero,.NB0f0fd340
/*  f0fd2c0:	24100002 */ 	addiu	$s0,$zero,0x2
.NB0f0fd2c4:
/*  f0fd2c4:	3c18800a */ 	lui	$t8,0x800a
/*  f0fd2c8:	8f18e9d8 */ 	lw	$t8,-0x1628($t8)
/*  f0fd2cc:	1300001c */ 	beqz	$t8,.NB0f0fd340
/*  f0fd2d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd2d4:	1600001a */ 	bnez	$s0,.NB0f0fd340
/*  f0fd2d8:	3c19800a */ 	lui	$t9,0x800a
/*  f0fd2dc:	8f3966a8 */ 	lw	$t9,0x66a8($t9)
/*  f0fd2e0:	033e0019 */ 	multu	$t9,$s8
/*  f0fd2e4:	0011c880 */ 	sll	$t9,$s1,0x2
/*  f0fd2e8:	0331c823 */ 	subu	$t9,$t9,$s1
/*  f0fd2ec:	00007012 */ 	mflo	$t6
/*  f0fd2f0:	02ee7821 */ 	addu	$t7,$s7,$t6
/*  f0fd2f4:	81f80000 */ 	lb	$t8,0x0($t7)
/*  f0fd2f8:	02b97021 */ 	addu	$t6,$s5,$t9
/*  f0fd2fc:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f0fd300:	2b010002 */ 	slti	$at,$t8,0x2
/*  f0fd304:	1420000e */ 	bnez	$at,.NB0f0fd340
/*  f0fd308:	8fb9019c */ 	lw	$t9,0x19c($sp)
/*  f0fd30c:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f0fd310:	3c0f800b */ 	lui	$t7,0x800b
/*  f0fd314:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0fd318:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0fd31c:	8def0d80 */ 	lw	$t7,0xd80($t7)
/*  f0fd320:	3c02800b */ 	lui	$v0,0x800b
/*  f0fd324:	00581021 */ 	addu	$v0,$v0,$t8
/*  f0fd328:	8df802d4 */ 	lw	$t8,0x2d4($t7)
/*  f0fd32c:	90421428 */ 	lbu	$v0,0x1428($v0)
/*  f0fd330:	93030079 */ 	lbu	$v1,0x79($t8)
/*  f0fd334:	14430002 */ 	bne	$v0,$v1,.NB0f0fd340
/*  f0fd338:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd33c:	24100002 */ 	addiu	$s0,$zero,0x2
.NB0f0fd340:
/*  f0fd340:	3c19800a */ 	lui	$t9,0x800a
/*  f0fd344:	8f39e944 */ 	lw	$t9,-0x16bc($t9)
/*  f0fd348:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0fd34c:	02602025 */ 	or	$a0,$s3,$zero
/*  f0fd350:	932e0250 */ 	lbu	$t6,0x250($t9)
/*  f0fd354:	27a501a8 */ 	addiu	$a1,$sp,0x1a8
/*  f0fd358:	15c10003 */ 	bne	$t6,$at,.NB0f0fd368
/*  f0fd35c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd360:	3c144f4f */ 	lui	$s4,0x4f4f
/*  f0fd364:	36944f7f */ 	ori	$s4,$s4,0x4f7f
.NB0f0fd368:
/*  f0fd368:	0fc3e9b3 */ 	jal	amGetSlotDetails
/*  f0fd36c:	02c03025 */ 	or	$a2,$s6,$zero
/*  f0fd370:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0fd374:	1642000f */ 	bne	$s2,$v0,.NB0f0fd3b4
/*  f0fd378:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0fd37c:	5622000e */ 	bnel	$s1,$v0,.NB0f0fd3b8
/*  f0fd380:	8fb801a8 */ 	lw	$t8,0x1a8($sp)
/*  f0fd384:	0fc3ed19 */ 	jal	amIsCramped
/*  f0fd388:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd38c:	14400011 */ 	bnez	$v0,.NB0f0fd3d4
/*  f0fd390:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0fd394:	87af0158 */ 	lh	$t7,0x158($sp)
/*  f0fd398:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0fd39c:	02803025 */ 	or	$a2,$s4,$zero
/*  f0fd3a0:	87a7015a */ 	lh	$a3,0x15a($sp)
/*  f0fd3a4:	0fc3ee7c */ 	jal	amRenderText
/*  f0fd3a8:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0fd3ac:	10000009 */ 	beqz	$zero,.NB0f0fd3d4
/*  f0fd3b0:	afa201b0 */ 	sw	$v0,0x1b0($sp)
.NB0f0fd3b4:
/*  f0fd3b4:	8fb801a8 */ 	lw	$t8,0x1a8($sp)
.NB0f0fd3b8:
/*  f0fd3b8:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0fd3bc:	87a6015a */ 	lh	$a2,0x15a($sp)
/*  f0fd3c0:	87a70158 */ 	lh	$a3,0x158($sp)
/*  f0fd3c4:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0fd3c8:	0fc3f0a3 */ 	jal	amRenderSlot
/*  f0fd3cc:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0fd3d0:	afa201b0 */ 	sw	$v0,0x1b0($sp)
.NB0f0fd3d4:
/*  f0fd3d4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0fd3d8:	0011cc00 */ 	sll	$t9,$s1,0x10
/*  f0fd3dc:	00198c03 */ 	sra	$s1,$t9,0x10
/*  f0fd3e0:	2a210003 */ 	slti	$at,$s1,0x3
/*  f0fd3e4:	5420ff72 */ 	bnezl	$at,.NB0f0fd1b0
/*  f0fd3e8:	00122400 */ 	sll	$a0,$s2,0x10
/*  f0fd3ec:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0fd3f0:	00127c00 */ 	sll	$t7,$s2,0x10
/*  f0fd3f4:	000f9403 */ 	sra	$s2,$t7,0x10
/*  f0fd3f8:	2a410003 */ 	slti	$at,$s2,0x3
/*  f0fd3fc:	5420ff6b */ 	bnezl	$at,.NB0f0fd1ac
/*  f0fd400:	00008825 */ 	or	$s1,$zero,$zero
/*  f0fd404:	3c19800a */ 	lui	$t9,0x800a
/*  f0fd408:	832e27ab */ 	lb	$t6,0x27ab($t9)
/*  f0fd40c:	05c10004 */ 	bgez	$t6,.NB0f0fd420
/*  f0fd410:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd414:	0fc3e8bd */ 	jal	amGetFirstBuddyIndex
/*  f0fd418:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd41c:	04410011 */ 	bgez	$v0,.NB0f0fd464
.NB0f0fd420:
/*  f0fd420:	3c0f800a */ 	lui	$t7,0x800a
/*  f0fd424:	8defe9d8 */ 	lw	$t7,-0x1628($t7)
/*  f0fd428:	3c18800a */ 	lui	$t8,0x800a
/*  f0fd42c:	11e0000d */ 	beqz	$t7,.NB0f0fd464
/*  f0fd430:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd434:	8f1866a8 */ 	lw	$t8,0x66a8($t8)
/*  f0fd438:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0fd43c:	031e0019 */ 	multu	$t8,$s8
/*  f0fd440:	0000c812 */ 	mflo	$t9
/*  f0fd444:	02f97021 */ 	addu	$t6,$s7,$t9
/*  f0fd448:	81c20000 */ 	lb	$v0,0x0($t6)
/*  f0fd44c:	28410002 */ 	slti	$at,$v0,0x2
/*  f0fd450:	14200004 */ 	bnez	$at,.NB0f0fd464
/*  f0fd454:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd458:	0fc3eeae */ 	jal	amRenderAibotInfo
/*  f0fd45c:	2445fffe */ 	addiu	$a1,$v0,-2
/*  f0fd460:	afa201b0 */ 	sw	$v0,0x1b0($sp)
.NB0f0fd464:
/*  f0fd464:	3c0f800a */ 	lui	$t7,0x800a
/*  f0fd468:	8def66a8 */ 	lw	$t7,0x66a8($t7)
/*  f0fd46c:	3c02800a */ 	lui	$v0,0x800a
/*  f0fd470:	2442e6c0 */ 	addiu	$v0,$v0,-6464
/*  f0fd474:	01fe0019 */ 	multu	$t7,$s8
/*  f0fd478:	0000c012 */ 	mflo	$t8
/*  f0fd47c:	02f88021 */ 	addu	$s0,$s7,$t8
/*  f0fd480:	82190000 */ 	lb	$t9,0x0($s0)
/*  f0fd484:	2b210002 */ 	slti	$at,$t9,0x2
/*  f0fd488:	14200005 */ 	bnez	$at,.NB0f0fd4a0
/*  f0fd48c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fd490:	16410003 */ 	bne	$s2,$at,.NB0f0fd4a0
/*  f0fd494:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fd498:	1221011e */ 	beq	$s1,$at,.NB0f0fd914
/*  f0fd49c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0fd4a0:
/*  f0fd4a0:	8c4e006c */ 	lw	$t6,0x6c($v0)
/*  f0fd4a4:	24120006 */ 	addiu	$s2,$zero,0x6
/*  f0fd4a8:	24130006 */ 	addiu	$s3,$zero,0x6
/*  f0fd4ac:	51c00004 */ 	beqzl	$t6,.NB0f0fd4c0
/*  f0fd4b0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fd4b4:	10000002 */ 	beqz	$zero,.NB0f0fd4c0
/*  f0fd4b8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0fd4bc:	00003025 */ 	or	$a2,$zero,$zero
.NB0f0fd4c0:
/*  f0fd4c0:	8c4f0068 */ 	lw	$t7,0x68($v0)
/*  f0fd4c4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fd4c8:	11e00003 */ 	beqz	$t7,.NB0f0fd4d8
/*  f0fd4cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd4d0:	10000001 */ 	beqz	$zero,.NB0f0fd4d8
/*  f0fd4d4:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f0fd4d8:
/*  f0fd4d8:	8c580064 */ 	lw	$t8,0x64($v0)
/*  f0fd4dc:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fd4e0:	13000003 */ 	beqz	$t8,.NB0f0fd4f0
/*  f0fd4e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd4e8:	10000001 */ 	beqz	$zero,.NB0f0fd4f0
/*  f0fd4ec:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f0fd4f0:
/*  f0fd4f0:	8c590070 */ 	lw	$t9,0x70($v0)
/*  f0fd4f4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fd4f8:	13200003 */ 	beqz	$t9,.NB0f0fd508
/*  f0fd4fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd500:	10000001 */ 	beqz	$zero,.NB0f0fd508
/*  f0fd504:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f0fd508:
/*  f0fd508:	00647021 */ 	addu	$t6,$v1,$a0
/*  f0fd50c:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f0fd510:	01e6c021 */ 	addu	$t8,$t7,$a2
/*  f0fd514:	2b010002 */ 	slti	$at,$t8,0x2
/*  f0fd518:	14200003 */ 	bnez	$at,.NB0f0fd528
/*  f0fd51c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd520:	24120005 */ 	addiu	$s2,$zero,0x5
/*  f0fd524:	24130003 */ 	addiu	$s3,$zero,0x3
.NB0f0fd528:
/*  f0fd528:	0c006d55 */ 	jal	sinf
/*  f0fd52c:	c60c001c */ 	lwc1	$f12,0x1c($s0)
/*  f0fd530:	3c013f80 */ 	lui	$at,0x3f80
/*  f0fd534:	44812000 */ 	mtc1	$at,$f4
/*  f0fd538:	3c0142fe */ 	lui	$at,0x42fe
/*  f0fd53c:	44814000 */ 	mtc1	$at,$f8
/*  f0fd540:	46040180 */ 	add.s	$f6,$f0,$f4
/*  f0fd544:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0fd548:	3c014f00 */ 	lui	$at,0x4f00
/*  f0fd54c:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0fd550:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0fd554:	4459f800 */ 	cfc1	$t9,$31
/*  f0fd558:	44c2f800 */ 	ctc1	$v0,$31
/*  f0fd55c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd560:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f0fd564:	4442f800 */ 	cfc1	$v0,$31
/*  f0fd568:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd56c:	30420078 */ 	andi	$v0,$v0,0x78
/*  f0fd570:	50400013 */ 	beqzl	$v0,.NB0f0fd5c0
/*  f0fd574:	44028000 */ 	mfc1	$v0,$f16
/*  f0fd578:	44818000 */ 	mtc1	$at,$f16
/*  f0fd57c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0fd580:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f0fd584:	44c2f800 */ 	ctc1	$v0,$31
/*  f0fd588:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd58c:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f0fd590:	4442f800 */ 	cfc1	$v0,$31
/*  f0fd594:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd598:	30420078 */ 	andi	$v0,$v0,0x78
/*  f0fd59c:	14400005 */ 	bnez	$v0,.NB0f0fd5b4
/*  f0fd5a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd5a4:	44028000 */ 	mfc1	$v0,$f16
/*  f0fd5a8:	3c018000 */ 	lui	$at,0x8000
/*  f0fd5ac:	10000007 */ 	beqz	$zero,.NB0f0fd5cc
/*  f0fd5b0:	00411025 */ 	or	$v0,$v0,$at
.NB0f0fd5b4:
/*  f0fd5b4:	10000005 */ 	beqz	$zero,.NB0f0fd5cc
/*  f0fd5b8:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0fd5bc:	44028000 */ 	mfc1	$v0,$f16
.NB0f0fd5c0:
/*  f0fd5c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd5c4:	0440fffb */ 	bltz	$v0,.NB0f0fd5b4
/*  f0fd5c8:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0fd5cc:
/*  f0fd5cc:	44d9f800 */ 	ctc1	$t9,$31
/*  f0fd5d0:	3c19800a */ 	lui	$t9,0x800a
/*  f0fd5d4:	8f39e944 */ 	lw	$t9,-0x16bc($t9)
/*  f0fd5d8:	3c01ff00 */ 	lui	$at,0xff00
/*  f0fd5dc:	342100ff */ 	ori	$at,$at,0xff
/*  f0fd5e0:	00027200 */ 	sll	$t6,$v0,0x8
/*  f0fd5e4:	01c17825 */ 	or	$t7,$t6,$at
/*  f0fd5e8:	932e0250 */ 	lbu	$t6,0x250($t9)
/*  f0fd5ec:	0002c400 */ 	sll	$t8,$v0,0x10
/*  f0fd5f0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0fd5f4:	15c10003 */ 	bne	$t6,$at,.NB0f0fd604
/*  f0fd5f8:	01f8a025 */ 	or	$s4,$t7,$t8
/*  f0fd5fc:	3c144f4f */ 	lui	$s4,0x4f4f
/*  f0fd600:	36944f7f */ 	ori	$s4,$s4,0x4f7f
.NB0f0fd604:
/*  f0fd604:	0fc537b7 */ 	jal	textSetPrimColour
/*  f0fd608:	02802825 */ 	or	$a1,$s4,$zero
/*  f0fd60c:	3c0f800a */ 	lui	$t7,0x800a
/*  f0fd610:	8def66a8 */ 	lw	$t7,0x66a8($t7)
/*  f0fd614:	afa201b0 */ 	sw	$v0,0x1b0($sp)
/*  f0fd618:	01fe0019 */ 	multu	$t7,$s8
/*  f0fd61c:	0000c012 */ 	mflo	$t8
/*  f0fd620:	02f88021 */ 	addu	$s0,$s7,$t8
/*  f0fd624:	86110004 */ 	lh	$s1,0x4($s0)
/*  f0fd628:	920e000e */ 	lbu	$t6,0xe($s0)
/*  f0fd62c:	06210003 */ 	bgez	$s1,.NB0f0fd63c
/*  f0fd630:	0011c843 */ 	sra	$t9,$s1,0x1
/*  f0fd634:	26210001 */ 	addiu	$at,$s1,0x1
/*  f0fd638:	0001c843 */ 	sra	$t9,$at,0x1
.NB0f0fd63c:
/*  f0fd63c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0fd640:	15c10006 */ 	bne	$t6,$at,.NB0f0fd65c
/*  f0fd644:	03208825 */ 	or	$s1,$t9,$zero
/*  f0fd648:	0fc3ed19 */ 	jal	amIsCramped
/*  f0fd64c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd650:	10400002 */ 	beqz	$v0,.NB0f0fd65c
/*  f0fd654:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd658:	24110004 */ 	addiu	$s1,$zero,0x4
.NB0f0fd65c:
/*  f0fd65c:	3c19800a */ 	lui	$t9,0x800a
/*  f0fd660:	8f3966a8 */ 	lw	$t9,0x66a8($t9)
/*  f0fd664:	8fa201b0 */ 	lw	$v0,0x1b0($sp)
/*  f0fd668:	3c068008 */ 	lui	$a2,0x8008
/*  f0fd66c:	033e0019 */ 	multu	$t9,$s8
/*  f0fd670:	24c62320 */ 	addiu	$a2,$a2,0x2320
/*  f0fd674:	24580008 */ 	addiu	$t8,$v0,0x8
/*  f0fd678:	afb801b0 */ 	sw	$t8,0x1b0($sp)
/*  f0fd67c:	3c14f600 */ 	lui	$s4,0xf600
/*  f0fd680:	00007012 */ 	mflo	$t6
/*  f0fd684:	02ee8021 */ 	addu	$s0,$s7,$t6
/*  f0fd688:	860f0006 */ 	lh	$t7,0x6($s0)
/*  f0fd68c:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f0fd690:	01f1c021 */ 	addu	$t8,$t7,$s1
/*  f0fd694:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0fd698:	032e0019 */ 	multu	$t9,$t6
/*  f0fd69c:	860e0008 */ 	lh	$t6,0x8($s0)
/*  f0fd6a0:	00007812 */ 	mflo	$t7
/*  f0fd6a4:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0fd6a8:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0fd6ac:	01d27823 */ 	subu	$t7,$t6,$s2
/*  f0fd6b0:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f0fd6b4:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0fd6b8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0fd6bc:	01f4c025 */ 	or	$t8,$t7,$s4
/*  f0fd6c0:	03197025 */ 	or	$t6,$t8,$t9
/*  f0fd6c4:	3c0f800a */ 	lui	$t7,0x800a
/*  f0fd6c8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0fd6cc:	8def66a8 */ 	lw	$t7,0x66a8($t7)
/*  f0fd6d0:	01fe0019 */ 	multu	$t7,$s8
/*  f0fd6d4:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f0fd6d8:	0000c012 */ 	mflo	$t8
/*  f0fd6dc:	02f88021 */ 	addu	$s0,$s7,$t8
/*  f0fd6e0:	86190006 */ 	lh	$t9,0x6($s0)
/*  f0fd6e4:	03317023 */ 	subu	$t6,$t9,$s1
/*  f0fd6e8:	01cf0019 */ 	multu	$t6,$t7
/*  f0fd6ec:	860f0008 */ 	lh	$t7,0x8($s0)
/*  f0fd6f0:	0000c012 */ 	mflo	$t8
/*  f0fd6f4:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0fd6f8:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0fd6fc:	01f2c023 */ 	subu	$t8,$t7,$s2
/*  f0fd700:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0fd704:	00197880 */ 	sll	$t7,$t9,0x2
/*  f0fd708:	01eec025 */ 	or	$t8,$t7,$t6
/*  f0fd70c:	3c0e800a */ 	lui	$t6,0x800a
/*  f0fd710:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f0fd714:	8dce66a8 */ 	lw	$t6,0x66a8($t6)
/*  f0fd718:	8fa301b0 */ 	lw	$v1,0x1b0($sp)
/*  f0fd71c:	01de0019 */ 	multu	$t6,$s8
/*  f0fd720:	246f0008 */ 	addiu	$t7,$v1,0x8
/*  f0fd724:	afaf01b0 */ 	sw	$t7,0x1b0($sp)
/*  f0fd728:	0000c012 */ 	mflo	$t8
/*  f0fd72c:	02f88021 */ 	addu	$s0,$s7,$t8
/*  f0fd730:	86190006 */ 	lh	$t9,0x6($s0)
/*  f0fd734:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f0fd738:	03317821 */ 	addu	$t7,$t9,$s1
/*  f0fd73c:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f0fd740:	01d80019 */ 	multu	$t6,$t8
/*  f0fd744:	86180008 */ 	lh	$t8,0x8($s0)
/*  f0fd748:	0000c812 */ 	mflo	$t9
/*  f0fd74c:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0fd750:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0fd754:	0313c821 */ 	addu	$t9,$t8,$s3
/*  f0fd758:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f0fd75c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0fd760:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0fd764:	03347825 */ 	or	$t7,$t9,$s4
/*  f0fd768:	01eec025 */ 	or	$t8,$t7,$t6
/*  f0fd76c:	3c19800a */ 	lui	$t9,0x800a
/*  f0fd770:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f0fd774:	8f3966a8 */ 	lw	$t9,0x66a8($t9)
/*  f0fd778:	033e0019 */ 	multu	$t9,$s8
/*  f0fd77c:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f0fd780:	00007812 */ 	mflo	$t7
/*  f0fd784:	02ef8021 */ 	addu	$s0,$s7,$t7
/*  f0fd788:	860e0006 */ 	lh	$t6,0x6($s0)
/*  f0fd78c:	01d1c023 */ 	subu	$t8,$t6,$s1
/*  f0fd790:	03190019 */ 	multu	$t8,$t9
/*  f0fd794:	86190008 */ 	lh	$t9,0x8($s0)
/*  f0fd798:	00007812 */ 	mflo	$t7
/*  f0fd79c:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0fd7a0:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f0fd7a4:	03337821 */ 	addu	$t7,$t9,$s3
/*  f0fd7a8:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0fd7ac:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f0fd7b0:	03387825 */ 	or	$t7,$t9,$t8
/*  f0fd7b4:	3c18800a */ 	lui	$t8,0x800a
/*  f0fd7b8:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f0fd7bc:	8f1866a8 */ 	lw	$t8,0x66a8($t8)
/*  f0fd7c0:	8fa501b0 */ 	lw	$a1,0x1b0($sp)
/*  f0fd7c4:	031e0019 */ 	multu	$t8,$s8
/*  f0fd7c8:	24b90008 */ 	addiu	$t9,$a1,0x8
/*  f0fd7cc:	afb901b0 */ 	sw	$t9,0x1b0($sp)
/*  f0fd7d0:	00007812 */ 	mflo	$t7
/*  f0fd7d4:	02ef8021 */ 	addu	$s0,$s7,$t7
/*  f0fd7d8:	860e0006 */ 	lh	$t6,0x6($s0)
/*  f0fd7dc:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f0fd7e0:	01d1c823 */ 	subu	$t9,$t6,$s1
/*  f0fd7e4:	27380001 */ 	addiu	$t8,$t9,0x1
/*  f0fd7e8:	030f0019 */ 	multu	$t8,$t7
/*  f0fd7ec:	860f0008 */ 	lh	$t7,0x8($s0)
/*  f0fd7f0:	00007012 */ 	mflo	$t6
/*  f0fd7f4:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0fd7f8:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f0fd7fc:	01f37021 */ 	addu	$t6,$t7,$s3
/*  f0fd800:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0fd804:	00197880 */ 	sll	$t7,$t9,0x2
/*  f0fd808:	01f47025 */ 	or	$t6,$t7,$s4
/*  f0fd80c:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0fd810:	3c0f800a */ 	lui	$t7,0x800a
/*  f0fd814:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f0fd818:	8def66a8 */ 	lw	$t7,0x66a8($t7)
/*  f0fd81c:	01fe0019 */ 	multu	$t7,$s8
/*  f0fd820:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f0fd824:	00007012 */ 	mflo	$t6
/*  f0fd828:	02ee8021 */ 	addu	$s0,$s7,$t6
/*  f0fd82c:	86180006 */ 	lh	$t8,0x6($s0)
/*  f0fd830:	0311c823 */ 	subu	$t9,$t8,$s1
/*  f0fd834:	032f0019 */ 	multu	$t9,$t7
/*  f0fd838:	860f0008 */ 	lh	$t7,0x8($s0)
/*  f0fd83c:	00007012 */ 	mflo	$t6
/*  f0fd840:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f0fd844:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0fd848:	01f27023 */ 	subu	$t6,$t7,$s2
/*  f0fd84c:	25d80001 */ 	addiu	$t8,$t6,0x1
/*  f0fd850:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f0fd854:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f0fd858:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f0fd85c:	3c19800a */ 	lui	$t9,0x800a
/*  f0fd860:	acb80004 */ 	sw	$t8,0x4($a1)
/*  f0fd864:	8f3966a8 */ 	lw	$t9,0x66a8($t9)
/*  f0fd868:	8fa201b0 */ 	lw	$v0,0x1b0($sp)
/*  f0fd86c:	033e0019 */ 	multu	$t9,$s8
/*  f0fd870:	244e0008 */ 	addiu	$t6,$v0,0x8
/*  f0fd874:	afae01b0 */ 	sw	$t6,0x1b0($sp)
/*  f0fd878:	0000c012 */ 	mflo	$t8
/*  f0fd87c:	02f88021 */ 	addu	$s0,$s7,$t8
/*  f0fd880:	860f0006 */ 	lh	$t7,0x6($s0)
/*  f0fd884:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f0fd888:	01f17021 */ 	addu	$t6,$t7,$s1
/*  f0fd88c:	25d90001 */ 	addiu	$t9,$t6,0x1
/*  f0fd890:	03380019 */ 	multu	$t9,$t8
/*  f0fd894:	86180008 */ 	lh	$t8,0x8($s0)
/*  f0fd898:	00007812 */ 	mflo	$t7
/*  f0fd89c:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0fd8a0:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0fd8a4:	03137821 */ 	addu	$t7,$t8,$s3
/*  f0fd8a8:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0fd8ac:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f0fd8b0:	03147825 */ 	or	$t7,$t8,$s4
/*  f0fd8b4:	01f97025 */ 	or	$t6,$t7,$t9
/*  f0fd8b8:	3c18800a */ 	lui	$t8,0x800a
/*  f0fd8bc:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0fd8c0:	8f1866a8 */ 	lw	$t8,0x66a8($t8)
/*  f0fd8c4:	031e0019 */ 	multu	$t8,$s8
/*  f0fd8c8:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f0fd8cc:	00007812 */ 	mflo	$t7
/*  f0fd8d0:	02ef8021 */ 	addu	$s0,$s7,$t7
/*  f0fd8d4:	86190006 */ 	lh	$t9,0x6($s0)
/*  f0fd8d8:	03317021 */ 	addu	$t6,$t9,$s1
/*  f0fd8dc:	01d80019 */ 	multu	$t6,$t8
/*  f0fd8e0:	86180008 */ 	lh	$t8,0x8($s0)
/*  f0fd8e4:	00007812 */ 	mflo	$t7
/*  f0fd8e8:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f0fd8ec:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0fd8f0:	03127823 */ 	subu	$t7,$t8,$s2
/*  f0fd8f4:	25f90001 */ 	addiu	$t9,$t7,0x1
/*  f0fd8f8:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f0fd8fc:	00187880 */ 	sll	$t7,$t8,0x2
/*  f0fd900:	01eec825 */ 	or	$t9,$t7,$t6
/*  f0fd904:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0fd908:	0fc537ce */ 	jal	text0f153838
/*  f0fd90c:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0fd910:	afa201b0 */ 	sw	$v0,0x1b0($sp)
.NB0f0fd914:
/*  f0fd914:	0fc537a0 */ 	jal	text0f153780
/*  f0fd918:	8fa401b0 */ 	lw	$a0,0x1b0($sp)
/*  f0fd91c:	3c03800a */ 	lui	$v1,0x800a
/*  f0fd920:	3c0a800a */ 	lui	$t2,0x800a
/*  f0fd924:	254ae6c0 */ 	addiu	$t2,$t2,-6464
/*  f0fd928:	8c63e944 */ 	lw	$v1,-0x16bc($v1)
/*  f0fd92c:	afa201b0 */ 	sw	$v0,0x1b0($sp)
/*  f0fd930:	8c621c04 */ 	lw	$v0,0x1c04($v1)
.NB0f0fd934:
/*  f0fd934:	3c14f600 */ 	lui	$s4,0xf600
/*  f0fd938:	504001e0 */ 	beqzl	$v0,.NB0f0fe0bc
/*  f0fd93c:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0fd940:	c4400104 */ 	lwc1	$f0,0x104($v0)
/*  f0fd944:	c4520100 */ 	lwc1	$f18,0x100($v0)
/*  f0fd948:	3c013e00 */ 	lui	$at,0x3e00
/*  f0fd94c:	44814000 */ 	mtc1	$at,$f8
/*  f0fd950:	46120101 */ 	sub.s	$f4,$f0,$f18
/*  f0fd954:	c4460180 */ 	lwc1	$f6,0x180($v0)
/*  f0fd958:	3c013e80 */ 	lui	$at,0x3e80
/*  f0fd95c:	44818000 */ 	mtc1	$at,$f16
/*  f0fd960:	46002383 */ 	div.s	$f14,$f4,$f0
/*  f0fd964:	0000b025 */ 	or	$s6,$zero,$zero
/*  f0fd968:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0fd96c:	e7aa0100 */ 	swc1	$f10,0x100($sp)
/*  f0fd970:	4610703c */ 	c.lt.s	$f14,$f16
/*  f0fd974:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fd978:	45020003 */ 	bc1fl	.NB0f0fd988
/*  f0fd97c:	8d47006c */ 	lw	$a3,0x6c($t2)
/*  f0fd980:	24160001 */ 	addiu	$s6,$zero,0x1
/*  f0fd984:	8d47006c */ 	lw	$a3,0x6c($t2)
.NB0f0fd988:
/*  f0fd988:	50e00004 */ 	beqzl	$a3,.NB0f0fd99c
/*  f0fd98c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fd990:	10000002 */ 	beqz	$zero,.NB0f0fd99c
/*  f0fd994:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0fd998:	00003025 */ 	or	$a2,$zero,$zero
.NB0f0fd99c:
/*  f0fd99c:	8d420068 */ 	lw	$v0,0x68($t2)
/*  f0fd9a0:	50400004 */ 	beqzl	$v0,.NB0f0fd9b4
/*  f0fd9a4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fd9a8:	10000002 */ 	beqz	$zero,.NB0f0fd9b4
/*  f0fd9ac:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0fd9b0:	00002825 */ 	or	$a1,$zero,$zero
.NB0f0fd9b4:
/*  f0fd9b4:	8d480064 */ 	lw	$t0,0x64($t2)
/*  f0fd9b8:	51000004 */ 	beqzl	$t0,.NB0f0fd9cc
/*  f0fd9bc:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fd9c0:	10000002 */ 	beqz	$zero,.NB0f0fd9cc
/*  f0fd9c4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0fd9c8:	00002025 */ 	or	$a0,$zero,$zero
.NB0f0fd9cc:
/*  f0fd9cc:	8d490070 */ 	lw	$t1,0x70($t2)
/*  f0fd9d0:	51200004 */ 	beqzl	$t1,.NB0f0fd9e4
/*  f0fd9d4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fd9d8:	10000002 */ 	beqz	$zero,.NB0f0fd9e4
/*  f0fd9dc:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0fd9e0:	00001825 */ 	or	$v1,$zero,$zero
.NB0f0fd9e4:
/*  f0fd9e4:	0064c021 */ 	addu	$t8,$v1,$a0
/*  f0fd9e8:	03057821 */ 	addu	$t7,$t8,$a1
/*  f0fd9ec:	01e67021 */ 	addu	$t6,$t7,$a2
/*  f0fd9f0:	29c10002 */ 	slti	$at,$t6,0x2
/*  f0fd9f4:	54200004 */ 	bnezl	$at,.NB0f0fda08
/*  f0fd9f8:	24150040 */ 	addiu	$s5,$zero,0x40
/*  f0fd9fc:	10000002 */ 	beqz	$zero,.NB0f0fda08
/*  f0fda00:	24150030 */ 	addiu	$s5,$zero,0x30
/*  f0fda04:	24150040 */ 	addiu	$s5,$zero,0x40
.NB0f0fda08:
/*  f0fda08:	50e00004 */ 	beqzl	$a3,.NB0f0fda1c
/*  f0fda0c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fda10:	10000002 */ 	beqz	$zero,.NB0f0fda1c
/*  f0fda14:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0fda18:	00003025 */ 	or	$a2,$zero,$zero
.NB0f0fda1c:
/*  f0fda1c:	50400004 */ 	beqzl	$v0,.NB0f0fda30
/*  f0fda20:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fda24:	10000002 */ 	beqz	$zero,.NB0f0fda30
/*  f0fda28:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0fda2c:	00002825 */ 	or	$a1,$zero,$zero
.NB0f0fda30:
/*  f0fda30:	51000004 */ 	beqzl	$t0,.NB0f0fda44
/*  f0fda34:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fda38:	10000002 */ 	beqz	$zero,.NB0f0fda44
/*  f0fda3c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0fda40:	00002025 */ 	or	$a0,$zero,$zero
.NB0f0fda44:
/*  f0fda44:	51200004 */ 	beqzl	$t1,.NB0f0fda58
/*  f0fda48:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fda4c:	10000002 */ 	beqz	$zero,.NB0f0fda58
/*  f0fda50:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0fda54:	00001825 */ 	or	$v1,$zero,$zero
.NB0f0fda58:
/*  f0fda58:	0064c821 */ 	addu	$t9,$v1,$a0
/*  f0fda5c:	0325c021 */ 	addu	$t8,$t9,$a1
/*  f0fda60:	03067821 */ 	addu	$t7,$t8,$a2
/*  f0fda64:	29e10002 */ 	slti	$at,$t7,0x2
/*  f0fda68:	54200004 */ 	bnezl	$at,.NB0f0fda7c
/*  f0fda6c:	2412000b */ 	addiu	$s2,$zero,0xb
/*  f0fda70:	10000002 */ 	beqz	$zero,.NB0f0fda7c
/*  f0fda74:	24120007 */ 	addiu	$s2,$zero,0x7
/*  f0fda78:	2412000b */ 	addiu	$s2,$zero,0xb
.NB0f0fda7c:
/*  f0fda7c:	10e00003 */ 	beqz	$a3,.NB0f0fda8c
/*  f0fda80:	00009825 */ 	or	$s3,$zero,$zero
/*  f0fda84:	10000002 */ 	beqz	$zero,.NB0f0fda90
/*  f0fda88:	24060001 */ 	addiu	$a2,$zero,0x1
.NB0f0fda8c:
/*  f0fda8c:	00003025 */ 	or	$a2,$zero,$zero
.NB0f0fda90:
/*  f0fda90:	10400003 */ 	beqz	$v0,.NB0f0fdaa0
/*  f0fda94:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0fda98:	10000002 */ 	beqz	$zero,.NB0f0fdaa4
/*  f0fda9c:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f0fdaa0:
/*  f0fdaa0:	00002825 */ 	or	$a1,$zero,$zero
.NB0f0fdaa4:
/*  f0fdaa4:	51000004 */ 	beqzl	$t0,.NB0f0fdab8
/*  f0fdaa8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fdaac:	10000002 */ 	beqz	$zero,.NB0f0fdab8
/*  f0fdab0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0fdab4:	00002025 */ 	or	$a0,$zero,$zero
.NB0f0fdab8:
/*  f0fdab8:	51200004 */ 	beqzl	$t1,.NB0f0fdacc
/*  f0fdabc:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fdac0:	10000002 */ 	beqz	$zero,.NB0f0fdacc
/*  f0fdac4:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0fdac8:	00001825 */ 	or	$v1,$zero,$zero
.NB0f0fdacc:
/*  f0fdacc:	00647021 */ 	addu	$t6,$v1,$a0
/*  f0fdad0:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f0fdad4:	0326c021 */ 	addu	$t8,$t9,$a2
/*  f0fdad8:	1701000e */ 	bne	$t8,$at,.NB0f0fdb14
/*  f0fdadc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdae0:	0fc53588 */ 	jal	optionsGetScreenSplit
/*  f0fdae4:	e7ae0104 */ 	swc1	$f14,0x104($sp)
/*  f0fdae8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0fdaec:	1041001f */ 	beq	$v0,$at,.NB0f0fdb6c
/*  f0fdaf0:	c7ae0104 */ 	lwc1	$f14,0x104($sp)
/*  f0fdaf4:	3c07800a */ 	lui	$a3,0x800a
/*  f0fdaf8:	3c02800a */ 	lui	$v0,0x800a
/*  f0fdafc:	3c08800a */ 	lui	$t0,0x800a
/*  f0fdb00:	3c09800a */ 	lui	$t1,0x800a
/*  f0fdb04:	8d29e730 */ 	lw	$t1,-0x18d0($t1)
/*  f0fdb08:	8d08e724 */ 	lw	$t0,-0x18dc($t0)
/*  f0fdb0c:	8c42e728 */ 	lw	$v0,-0x18d8($v0)
/*  f0fdb10:	8ce7e72c */ 	lw	$a3,-0x18d4($a3)
.NB0f0fdb14:
/*  f0fdb14:	10e00003 */ 	beqz	$a3,.NB0f0fdb24
/*  f0fdb18:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fdb1c:	10000001 */ 	beqz	$zero,.NB0f0fdb24
/*  f0fdb20:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f0fdb24:
/*  f0fdb24:	10400003 */ 	beqz	$v0,.NB0f0fdb34
/*  f0fdb28:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fdb2c:	10000002 */ 	beqz	$zero,.NB0f0fdb38
/*  f0fdb30:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f0fdb34:
/*  f0fdb34:	00001025 */ 	or	$v0,$zero,$zero
.NB0f0fdb38:
/*  f0fdb38:	11000003 */ 	beqz	$t0,.NB0f0fdb48
/*  f0fdb3c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0fdb40:	10000001 */ 	beqz	$zero,.NB0f0fdb48
/*  f0fdb44:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f0fdb48:
/*  f0fdb48:	11200003 */ 	beqz	$t1,.NB0f0fdb58
/*  f0fdb4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdb50:	10000001 */ 	beqz	$zero,.NB0f0fdb58
/*  f0fdb54:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f0fdb58:
/*  f0fdb58:	00647821 */ 	addu	$t7,$v1,$a0
/*  f0fdb5c:	01e27021 */ 	addu	$t6,$t7,$v0
/*  f0fdb60:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f0fdb64:	2b210003 */ 	slti	$at,$t9,0x3
/*  f0fdb68:	14200009 */ 	bnez	$at,.NB0f0fdb90
.NB0f0fdb6c:
/*  f0fdb6c:	3c0a800a */ 	lui	$t2,0x800a
/*  f0fdb70:	254ae6c0 */ 	addiu	$t2,$t2,-6464
/*  f0fdb74:	8d58028c */ 	lw	$t8,0x28c($t2)
/*  f0fdb78:	2413fff8 */ 	addiu	$s3,$zero,-8
/*  f0fdb7c:	330f0001 */ 	andi	$t7,$t8,0x1
/*  f0fdb80:	15e00003 */ 	bnez	$t7,.NB0f0fdb90
/*  f0fdb84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdb88:	10000001 */ 	beqz	$zero,.NB0f0fdb90
/*  f0fdb8c:	24130008 */ 	addiu	$s3,$zero,0x8
.NB0f0fdb90:
/*  f0fdb90:	0c002f97 */ 	jal	viGetViewWidth
/*  f0fdb94:	e7ae0104 */ 	swc1	$f14,0x104($sp)
/*  f0fdb98:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0fdb9c:	00117403 */ 	sra	$t6,$s1,0x10
/*  f0fdba0:	0c002fb5 */ 	jal	viGetViewLeft
/*  f0fdba4:	01c08825 */ 	or	$s1,$t6,$zero
/*  f0fdba8:	3c038008 */ 	lui	$v1,0x8008
/*  f0fdbac:	8c632320 */ 	lw	$v1,0x2320($v1)
/*  f0fdbb0:	44959000 */ 	mtc1	$s5,$f18
/*  f0fdbb4:	3c013f00 */ 	lui	$at,0x3f00
/*  f0fdbb8:	0043001a */ 	div	$zero,$v0,$v1
/*  f0fdbbc:	0000c812 */ 	mflo	$t9
/*  f0fdbc0:	44810000 */ 	mtc1	$at,$f0
/*  f0fdbc4:	468090a0 */ 	cvt.s.w	$f2,$f18
/*  f0fdbc8:	0223001a */ 	div	$zero,$s1,$v1
/*  f0fdbcc:	0000c012 */ 	mflo	$t8
/*  f0fdbd0:	44982000 */ 	mtc1	$t8,$f4
/*  f0fdbd4:	44806000 */ 	mtc1	$zero,$f12
/*  f0fdbd8:	c7ae0104 */ 	lwc1	$f14,0x104($sp)
/*  f0fdbdc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0fdbe0:	14600002 */ 	bnez	$v1,.NB0f0fdbec
/*  f0fdbe4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdbe8:	0007000d */ 	break	0x7
.NB0f0fdbec:
/*  f0fdbec:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fdbf0:	14610004 */ 	bne	$v1,$at,.NB0f0fdc04
/*  f0fdbf4:	3c018000 */ 	lui	$at,0x8000
/*  f0fdbf8:	14410002 */ 	bne	$v0,$at,.NB0f0fdc04
/*  f0fdbfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdc00:	0006000d */ 	break	0x6
.NB0f0fdc04:
/*  f0fdc04:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0fdc08:	460c703c */ 	c.lt.s	$f14,$f12
/*  f0fdc0c:	8faf01b0 */ 	lw	$t7,0x1b0($sp)
/*  f0fdc10:	46001402 */ 	mul.s	$f16,$f2,$f0
/*  f0fdc14:	14600002 */ 	bnez	$v1,.NB0f0fdc20
/*  f0fdc18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdc1c:	0007000d */ 	break	0x7
.NB0f0fdc20:
/*  f0fdc20:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0fdc24:	14610004 */ 	bne	$v1,$at,.NB0f0fdc38
/*  f0fdc28:	3c018000 */ 	lui	$at,0x8000
/*  f0fdc2c:	16210002 */ 	bne	$s1,$at,.NB0f0fdc38
/*  f0fdc30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdc34:	0006000d */ 	break	0x6
.NB0f0fdc38:
/*  f0fdc38:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0fdc3c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0fdc40:	440e5000 */ 	mfc1	$t6,$f10
/*  f0fdc44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdc48:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f0fdc4c:	44199000 */ 	mfc1	$t9,$f18
/*  f0fdc50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdc54:	03197023 */ 	subu	$t6,$t8,$t9
/*  f0fdc58:	01d38021 */ 	addu	$s0,$t6,$s3
/*  f0fdc5c:	45000002 */ 	bc1f	.NB0f0fdc68
/*  f0fdc60:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0fdc64:	46006386 */ 	mov.s	$f14,$f12
.NB0f0fdc68:
/*  f0fdc68:	afb801b0 */ 	sw	$t8,0x1b0($sp)
/*  f0fdc6c:	3c19e700 */ 	lui	$t9,0xe700
/*  f0fdc70:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0fdc74:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f0fdc78:	8fae01b0 */ 	lw	$t6,0x1b0($sp)
/*  f0fdc7c:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0fdc80:	37181402 */ 	ori	$t8,$t8,0x1402
/*  f0fdc84:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0fdc88:	afaf01b0 */ 	sw	$t7,0x1b0($sp)
/*  f0fdc8c:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0fdc90:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0fdc94:	8fb901b0 */ 	lw	$t9,0x1b0($sp)
/*  f0fdc98:	3c180050 */ 	lui	$t8,0x50
/*  f0fdc9c:	3c0fb900 */ 	lui	$t7,0xb900
/*  f0fdca0:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f0fdca4:	afae01b0 */ 	sw	$t6,0x1b0($sp)
/*  f0fdca8:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f0fdcac:	37184240 */ 	ori	$t8,$t8,0x4240
/*  f0fdcb0:	af380004 */ 	sw	$t8,0x4($t9)
/*  f0fdcb4:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f0fdcb8:	8fb901b0 */ 	lw	$t9,0x1b0($sp)
/*  f0fdcbc:	3c0ffcff */ 	lui	$t7,0xfcff
/*  f0fdcc0:	3c18fffd */ 	lui	$t8,0xfffd
/*  f0fdcc4:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f0fdcc8:	afae01b0 */ 	sw	$t6,0x1b0($sp)
/*  f0fdccc:	3718f6fb */ 	ori	$t8,$t8,0xf6fb
/*  f0fdcd0:	35efffff */ 	ori	$t7,$t7,0xffff
/*  f0fdcd4:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f0fdcd8:	af380004 */ 	sw	$t8,0x4($t9)
/*  f0fdcdc:	e7ae0104 */ 	swc1	$f14,0x104($sp)
/*  f0fdce0:	0c002f9b */ 	jal	viGetViewHeight
/*  f0fdce4:	e7a2006c */ 	swc1	$f2,0x6c($sp)
/*  f0fdce8:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0fdcec:	0011cc03 */ 	sra	$t9,$s1,0x10
/*  f0fdcf0:	0c002fb9 */ 	jal	viGetViewTop
/*  f0fdcf4:	03208825 */ 	or	$s1,$t9,$zero
/*  f0fdcf8:	3c0e800a */ 	lui	$t6,0x800a
/*  f0fdcfc:	8dcee72c */ 	lw	$t6,-0x18d4($t6)
/*  f0fdd00:	c7a2006c */ 	lwc1	$f2,0x6c($sp)
/*  f0fdd04:	c7ae0104 */ 	lwc1	$f14,0x104($sp)
/*  f0fdd08:	11c00003 */ 	beqz	$t6,.NB0f0fdd18
/*  f0fdd0c:	3c0f800a */ 	lui	$t7,0x800a
/*  f0fdd10:	10000002 */ 	beqz	$zero,.NB0f0fdd1c
/*  f0fdd14:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f0fdd18:
/*  f0fdd18:	00001825 */ 	or	$v1,$zero,$zero
.NB0f0fdd1c:
/*  f0fdd1c:	8defe728 */ 	lw	$t7,-0x18d8($t7)
/*  f0fdd20:	3c18800a */ 	lui	$t8,0x800a
/*  f0fdd24:	3c19800a */ 	lui	$t9,0x800a
/*  f0fdd28:	11e00003 */ 	beqz	$t7,.NB0f0fdd38
/*  f0fdd2c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0fdd30:	10000001 */ 	beqz	$zero,.NB0f0fdd38
/*  f0fdd34:	24060001 */ 	addiu	$a2,$zero,0x1
.NB0f0fdd38:
/*  f0fdd38:	8f18e724 */ 	lw	$t8,-0x18dc($t8)
/*  f0fdd3c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0fdd40:	00002025 */ 	or	$a0,$zero,$zero
/*  f0fdd44:	13000003 */ 	beqz	$t8,.NB0f0fdd54
/*  f0fdd48:	3c0cfa00 */ 	lui	$t4,0xfa00
/*  f0fdd4c:	10000001 */ 	beqz	$zero,.NB0f0fdd54
/*  f0fdd50:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f0fdd54:
/*  f0fdd54:	8f39e730 */ 	lw	$t9,-0x18d0($t9)
/*  f0fdd58:	320703ff */ 	andi	$a3,$s0,0x3ff
/*  f0fdd5c:	13200003 */ 	beqz	$t9,.NB0f0fdd6c
/*  f0fdd60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fdd64:	10000001 */ 	beqz	$zero,.NB0f0fdd6c
/*  f0fdd68:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f0fdd6c:
/*  f0fdd6c:	00857021 */ 	addu	$t6,$a0,$a1
/*  f0fdd70:	01c67821 */ 	addu	$t7,$t6,$a2
/*  f0fdd74:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f0fdd78:	2b010002 */ 	slti	$at,$t8,0x2
/*  f0fdd7c:	14200003 */ 	bnez	$at,.NB0f0fdd8c
/*  f0fdd80:	0002cc00 */ 	sll	$t9,$v0,0x10
/*  f0fdd84:	10000002 */ 	beqz	$zero,.NB0f0fdd90
/*  f0fdd88:	24030013 */ 	addiu	$v1,$zero,0x13
.NB0f0fdd8c:
/*  f0fdd8c:	24030022 */ 	addiu	$v1,$zero,0x22
.NB0f0fdd90:
/*  f0fdd90:	00197403 */ 	sra	$t6,$t9,0x10
/*  f0fdd94:	01d17821 */ 	addu	$t7,$t6,$s1
/*  f0fdd98:	12c00050 */ 	beqz	$s6,.NB0f0fdedc
/*  f0fdd9c:	01e34023 */ 	subu	$t0,$t7,$v1
/*  f0fdda0:	3c013e80 */ 	lui	$at,0x3e80
/*  f0fdda4:	44810000 */ 	mtc1	$at,$f0
/*  f0fdda8:	3c014080 */ 	lui	$at,0x4080
/*  f0fddac:	8fb801b0 */ 	lw	$t8,0x1b0($sp)
/*  f0fddb0:	46001102 */ 	mul.s	$f4,$f2,$f0
/*  f0fddb4:	460e0401 */ 	sub.s	$f16,$f0,$f14
/*  f0fddb8:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0fddbc:	afb901b0 */ 	sw	$t9,0x1b0($sp)
/*  f0fddc0:	3c0eff00 */ 	lui	$t6,0xff00
/*  f0fddc4:	3c0cfa00 */ 	lui	$t4,0xfa00
/*  f0fddc8:	35ce0060 */ 	ori	$t6,$t6,0x60
/*  f0fddcc:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0fddd0:	44812000 */ 	mtc1	$at,$f4
/*  f0fddd4:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f0fddd8:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f0fdddc:	44053000 */ 	mfc1	$a1,$f6
/*  f0fdde0:	8fa701b0 */ 	lw	$a3,0x1b0($sp)
/*  f0fdde4:	01124821 */ 	addu	$t1,$t0,$s2
/*  f0fdde8:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f0fddec:	44854000 */ 	mtc1	$a1,$f8
/*  f0fddf0:	02052021 */ 	addu	$a0,$s0,$a1
/*  f0fddf4:	24f80008 */ 	addiu	$t8,$a3,0x8
/*  f0fddf8:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0fddfc:	afb801b0 */ 	sw	$t8,0x1b0($sp)
/*  f0fde00:	308f03ff */ 	andi	$t7,$a0,0x3ff
/*  f0fde04:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0fde08:	0314c825 */ 	or	$t9,$t8,$s4
/*  f0fde0c:	312303ff */ 	andi	$v1,$t1,0x3ff
/*  f0fde10:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0fde14:	00037080 */ 	sll	$t6,$v1,0x2
/*  f0fde18:	01c01825 */ 	or	$v1,$t6,$zero
/*  f0fde1c:	032e7025 */ 	or	$t6,$t9,$t6
/*  f0fde20:	acee0000 */ 	sw	$t6,0x0($a3)
/*  f0fde24:	310203ff */ 	andi	$v0,$t0,0x3ff
/*  f0fde28:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f0fde2c:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0fde30:	03201025 */ 	or	$v0,$t9,$zero
/*  f0fde34:	240d0080 */ 	addiu	$t5,$zero,0x80
/*  f0fde38:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0fde3c:	44184000 */ 	mfc1	$t8,$f8
/*  f0fde40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0fde44:	00985823 */ 	subu	$t3,$a0,$t8
/*  f0fde48:	316e03ff */ 	andi	$t6,$t3,0x3ff
/*  f0fde4c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0fde50:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f0fde54:	acf80004 */ 	sw	$t8,0x4($a3)
/*  f0fde58:	8fb901b0 */ 	lw	$t9,0x1b0($sp)
/*  f0fde5c:	320703ff */ 	andi	$a3,$s0,0x3ff
/*  f0fde60:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f0fde64:	afae01b0 */ 	sw	$t6,0x1b0($sp)
/*  f0fde68:	af2d0004 */ 	sw	$t5,0x4($t9)
/*  f0fde6c:	af2c0000 */ 	sw	$t4,0x0($t9)
/*  f0fde70:	8fa501b0 */ 	lw	$a1,0x1b0($sp)
/*  f0fde74:	317903ff */ 	andi	$t9,$t3,0x3ff
/*  f0fde78:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0fde7c:	24b80008 */ 	addiu	$t8,$a1,0x8
/*  f0fde80:	afb801b0 */ 	sw	$t8,0x1b0($sp)
/*  f0fde84:	01d47825 */ 	or	$t7,$t6,$s4
/*  f0fde88:	0007cb80 */ 	sll	$t9,$a3,0xe
/*  f0fde8c:	03227025 */ 	or	$t6,$t9,$v0
/*  f0fde90:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0fde94:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f0fde98:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f0fde9c:	8fa601b0 */ 	lw	$a2,0x1b0($sp)
/*  f0fdea0:	03203825 */ 	or	$a3,$t9,$zero
/*  f0fdea4:	0215c821 */ 	addu	$t9,$s0,$s5
/*  f0fdea8:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0fdeac:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0fdeb0:	24d80008 */ 	addiu	$t8,$a2,0x8
/*  f0fdeb4:	afb801b0 */ 	sw	$t8,0x1b0($sp)
/*  f0fdeb8:	01f44025 */ 	or	$t0,$t7,$s4
/*  f0fdebc:	24990002 */ 	addiu	$t9,$a0,0x2
/*  f0fdec0:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0fdec4:	0103c025 */ 	or	$t8,$t0,$v1
/*  f0fdec8:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0fdecc:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f0fded0:	01e2c025 */ 	or	$t8,$t7,$v0
/*  f0fded4:	10000046 */ 	beqz	$zero,.NB0f0fdff0
/*  f0fded8:	acd80004 */ 	sw	$t8,0x4($a2)
.NB0f0fdedc:
/*  f0fdedc:	3c013e80 */ 	lui	$at,0x3e80
/*  f0fdee0:	44815000 */ 	mtc1	$at,$f10
/*  f0fdee4:	8fb901b0 */ 	lw	$t9,0x1b0($sp)
/*  f0fdee8:	3c0f00c0 */ 	lui	$t7,0xc0
/*  f0fdeec:	460a1402 */ 	mul.s	$f16,$f2,$f10
/*  f0fdef0:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f0fdef4:	afae01b0 */ 	sw	$t6,0x1b0($sp)
/*  f0fdef8:	35ef0060 */ 	ori	$t7,$t7,0x60
/*  f0fdefc:	af2f0004 */ 	sw	$t7,0x4($t9)
/*  f0fdf00:	af2c0000 */ 	sw	$t4,0x0($t9)
/*  f0fdf04:	8fa601b0 */ 	lw	$a2,0x1b0($sp)
/*  f0fdf08:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0fdf0c:	460e1102 */ 	mul.s	$f4,$f2,$f14
/*  f0fdf10:	24d90008 */ 	addiu	$t9,$a2,0x8
/*  f0fdf14:	afb901b0 */ 	sw	$t9,0x1b0($sp)
/*  f0fdf18:	440f9000 */ 	mfc1	$t7,$f18
/*  f0fdf1c:	01124821 */ 	addu	$t1,$t0,$s2
/*  f0fdf20:	312303ff */ 	andi	$v1,$t1,0x3ff
/*  f0fdf24:	020f2021 */ 	addu	$a0,$s0,$t7
/*  f0fdf28:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f0fdf2c:	309903ff */ 	andi	$t9,$a0,0x3ff
/*  f0fdf30:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0fdf34:	01d47825 */ 	or	$t7,$t6,$s4
/*  f0fdf38:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f0fdf3c:	03001825 */ 	or	$v1,$t8,$zero
/*  f0fdf40:	310203ff */ 	andi	$v0,$t0,0x3ff
/*  f0fdf44:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0fdf48:	00027080 */ 	sll	$t6,$v0,0x2
/*  f0fdf4c:	01f8c025 */ 	or	$t8,$t7,$t8
/*  f0fdf50:	0007cb80 */ 	sll	$t9,$a3,0xe
/*  f0fdf54:	032e7825 */ 	or	$t7,$t9,$t6
/*  f0fdf58:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f0fdf5c:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f0fdf60:	8fab01b0 */ 	lw	$t3,0x1b0($sp)
/*  f0fdf64:	440f3000 */ 	mfc1	$t7,$f6
/*  f0fdf68:	03203825 */ 	or	$a3,$t9,$zero
/*  f0fdf6c:	25790008 */ 	addiu	$t9,$t3,0x8
/*  f0fdf70:	01f05021 */ 	addu	$t2,$t7,$s0
/*  f0fdf74:	315803ff */ 	andi	$t8,$t2,0x3ff
/*  f0fdf78:	afb901b0 */ 	sw	$t9,0x1b0($sp)
/*  f0fdf7c:	01c01025 */ 	or	$v0,$t6,$zero
/*  f0fdf80:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0fdf84:	03347025 */ 	or	$t6,$t9,$s4
/*  f0fdf88:	01c37825 */ 	or	$t7,$t6,$v1
/*  f0fdf8c:	24980002 */ 	addiu	$t8,$a0,0x2
/*  f0fdf90:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0fdf94:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0fdf98:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f0fdf9c:	01c27825 */ 	or	$t7,$t6,$v0
/*  f0fdfa0:	ad6f0004 */ 	sw	$t7,0x4($t3)
/*  f0fdfa4:	8fb801b0 */ 	lw	$t8,0x1b0($sp)
/*  f0fdfa8:	240d0080 */ 	addiu	$t5,$zero,0x80
/*  f0fdfac:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0fdfb0:	afb901b0 */ 	sw	$t9,0x1b0($sp)
/*  f0fdfb4:	af0d0004 */ 	sw	$t5,0x4($t8)
/*  f0fdfb8:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f0fdfbc:	8fa601b0 */ 	lw	$a2,0x1b0($sp)
/*  f0fdfc0:	0215c021 */ 	addu	$t8,$s0,$s5
/*  f0fdfc4:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0fdfc8:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0fdfcc:	24cf0008 */ 	addiu	$t7,$a2,0x8
/*  f0fdfd0:	afaf01b0 */ 	sw	$t7,0x1b0($sp)
/*  f0fdfd4:	01d44025 */ 	or	$t0,$t6,$s4
/*  f0fdfd8:	315803ff */ 	andi	$t8,$t2,0x3ff
/*  f0fdfdc:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0fdfe0:	03227025 */ 	or	$t6,$t9,$v0
/*  f0fdfe4:	01037825 */ 	or	$t7,$t0,$v1
/*  f0fdfe8:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f0fdfec:	acce0004 */ 	sw	$t6,0x4($a2)
.NB0f0fdff0:
/*  f0fdff0:	44924000 */ 	mtc1	$s2,$f8
/*  f0fdff4:	8fb801b0 */ 	lw	$t8,0x1b0($sp)
/*  f0fdff8:	3c013f40 */ 	lui	$at,0x3f40
/*  f0fdffc:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0fe000:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0fe004:	44818000 */ 	mtc1	$at,$f16
/*  f0fe008:	afb901b0 */ 	sw	$t9,0x1b0($sp)
/*  f0fe00c:	3c0e00c0 */ 	lui	$t6,0xc0
/*  f0fe010:	35ce0060 */ 	ori	$t6,$t6,0x60
/*  f0fe014:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f0fe018:	af0c0000 */ 	sw	$t4,0x0($t8)
/*  f0fe01c:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0fe020:	c7a60100 */ 	lwc1	$f6,0x100($sp)
/*  f0fe024:	8fa301b0 */ 	lw	$v1,0x1b0($sp)
/*  f0fe028:	25240002 */ 	addiu	$a0,$t1,0x2
/*  f0fe02c:	46061202 */ 	mul.s	$f8,$f2,$f6
/*  f0fe030:	24780008 */ 	addiu	$t8,$v1,0x8
/*  f0fe034:	afb801b0 */ 	sw	$t8,0x1b0($sp)
/*  f0fe038:	308603ff */ 	andi	$a2,$a0,0x3ff
/*  f0fe03c:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0fe040:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0fe044:	44122000 */ 	mfc1	$s2,$f4
/*  f0fe048:	440e5000 */ 	mfc1	$t6,$f10
/*  f0fe04c:	00922821 */ 	addu	$a1,$a0,$s2
/*  f0fe050:	30af03ff */ 	andi	$t7,$a1,0x3ff
/*  f0fe054:	01d05021 */ 	addu	$t2,$t6,$s0
/*  f0fe058:	315903ff */ 	andi	$t9,$t2,0x3ff
/*  f0fe05c:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0fe060:	000f2880 */ 	sll	$a1,$t7,0x2
/*  f0fe064:	01d47825 */ 	or	$t7,$t6,$s4
/*  f0fe068:	0006c880 */ 	sll	$t9,$a2,0x2
/*  f0fe06c:	00f97025 */ 	or	$t6,$a3,$t9
/*  f0fe070:	01e5c025 */ 	or	$t8,$t7,$a1
/*  f0fe074:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f0fe078:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f0fe07c:	8faf01b0 */ 	lw	$t7,0x1b0($sp)
/*  f0fe080:	03203025 */ 	or	$a2,$t9,$zero
/*  f0fe084:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0fe088:	afb801b0 */ 	sw	$t8,0x1b0($sp)
/*  f0fe08c:	aded0004 */ 	sw	$t5,0x4($t7)
/*  f0fe090:	adec0000 */ 	sw	$t4,0x0($t7)
/*  f0fe094:	8fa201b0 */ 	lw	$v0,0x1b0($sp)
/*  f0fe098:	315803ff */ 	andi	$t8,$t2,0x3ff
/*  f0fe09c:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0fe0a0:	244e0008 */ 	addiu	$t6,$v0,0x8
/*  f0fe0a4:	afae01b0 */ 	sw	$t6,0x1b0($sp)
/*  f0fe0a8:	03267025 */ 	or	$t6,$t9,$a2
/*  f0fe0ac:	01057825 */ 	or	$t7,$t0,$a1
/*  f0fe0b0:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0fe0b4:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0fe0b8:	8fbf004c */ 	lw	$ra,0x4c($sp)
.NB0f0fe0bc:
/*  f0fe0bc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0fe0c0:	3c018008 */ 	lui	$at,0x8008
/*  f0fe0c4:	8fa201b0 */ 	lw	$v0,0x1b0($sp)
/*  f0fe0c8:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0fe0cc:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f0fe0d0:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f0fe0d4:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f0fe0d8:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f0fe0dc:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f0fe0e0:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f0fe0e4:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f0fe0e8:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f0fe0ec:	ac2f2320 */ 	sw	$t7,0x2320($at)
/*  f0fe0f0:	03e00008 */ 	jr	$ra
/*  f0fe0f4:	27bd01b0 */ 	addiu	$sp,$sp,0x1b0
);
#endif
