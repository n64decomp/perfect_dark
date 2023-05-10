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
s32 g_AmActive;

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

static s32 amPickTargetMenuList(s32 operation, struct menuitem *item, union handlerdata *data)
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
			gdl = textRenderProjected(gdl, &x, &y, g_MpAllChrConfigPtrs[chrindex]->name, g_CharsHandelGothicSm, g_FontHandelGothicSm, colour, g_ViBackData->x, g_ViBackData->y, 0, 0);
			gdl = text0f153780(gdl);
			return (s32)gdl;
		}
	case MENUOP_GETOPTIONHEIGHT:
		data->list.value = LINEHEIGHT;
		break;
	}

	return 0;
}

static s32 amPickTargetMenuDialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
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

static void amSetAiBuddyTemperament(bool aggressive)
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

static void amSetAiBuddyStealth(void)
{
	s32 i;

	for (i = 0; i < g_Vars.numaibuddies; i++) {
		if (g_Vars.aibuddies[i]) {
			struct chrdata *chr = g_Vars.aibuddies[i]->chr;

			if (chr && chr->prop
					&& !chrIsDead(chr)
					&& chr->ailist != &ailist_0015
					&& chr->actiontype != ACT_DRUGGEDDROP
					&& chr->actiontype != ACT_DRUGGEDKO
					&& chr->actiontype != ACT_DRUGGEDCOMINGUP) {
				chrStopFiring(chr);
				chr->ailist = &ailist_0015;
				chr->aioffset = chr->ailist;
			}
		}
	}
}

static s32 amGetFirstBuddyIndex(void)
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
				} else if (slot == 3) {
					amSetAiBuddyStealth();
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
			label[0] = '\0';
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
		label[0] = '\0';

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
		label[0] = '\0';

		if (g_MissionConfig.iscoop) {
			if (slot == 4) {
				strcpy(label, langGet(L_MISC_474)); // "Perfect Buddies"
			} else if (slot == 1) {
				strcpy(label, langGet(L_MISC_472)); // "Aggressive"
			} else if (slot == 7) {
				strcpy(label, langGet(L_MISC_473)); // "Passive"
			} else if (slot == 3) {
				strcpy(label, langGet(L_MISC_475)); // "Stealth"
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

	if (PLAYERCOUNT() >= 2) {
		g_AmFont1 = g_CharsHandelGothicXs;
		g_AmFont2 = g_FontHandelGothicXs;
	} else {
		g_AmFont1 = g_CharsHandelGothicSm;
		g_AmFont2 = g_FontHandelGothicSm;
	}

	g_AmIndex = 0;
	g_AmActive = false;
}

static s16 amCalculateSlotWidth(void)
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

	if (PLAYERCOUNT() > 1) {
		max += 3;
	} else {
		max += 4;
	}

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
		g_AmActive = true;
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

static bool amIsCramped(void)
{
	return (g_AmMenus[g_AmIndex].screenindex == 0 && PLAYERCOUNT() >= 3)
		|| (PLAYERCOUNT() == 2 && g_ScreenSplit == SCREENSPLIT_VERTICAL);
}

static void amCalculateSlotPosition(s16 column, s16 row, s16 *x, s16 *y)
{
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

	*x += g_ViBackData->viewleft + g_ViBackData->viewx / 2;
	*y += g_ViBackData->viewtop + g_ViBackData->viewy / 2;

	if ((playercount == 2 && g_ScreenSplit == SCREENSPLIT_VERTICAL) || playercount >= 3) {
		if ((g_Vars.currentplayernum % 2) == 0) {
			*x += 8;
		} else {
			*x -= 8;
		}
	}
}

static Gfx *amRenderText(Gfx *gdl, char *text, u32 colour, s16 left, s16 top)
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

static Gfx *amRenderAibotInfo(Gfx *gdl, s32 buddynum)
{
	s32 x;
	s32 y;
	s32 textwidth;
	s32 textheight;
	s32 weaponnum;
	char *weaponname;
	char *aibotname;
	s32 offset = 0;
	bool wide = false;

	if (PLAYERCOUNT() == 1 && optionsGetEffectiveScreenSize() != SCREENSIZE_FULL) {
		wide = true;
	}

	if ((PLAYERCOUNT() == 2 && g_ScreenSplit == SCREENSPLIT_VERTICAL) || PLAYERCOUNT() >= 3) {
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

		x = g_ViBackData->viewleft
			+ (s32)(g_ViBackData->viewx * 0.5f)
			- (s32)(textwidth * 0.5f)
			+ offset;

		if (PLAYERCOUNT() >= 2) {
			y = g_ViBackData->viewtop + 5;
		} else {
			y = g_ViBackData->viewtop + 10;
		}

		if (wide) {
			x = g_ViBackData->viewleft + 32;
		}

		gdl = textRender(gdl, &x, &y, aibotname, g_AmFont1, g_AmFont2, -1,
				0x000000ff, 320, 240, 0, 0);

		y += (PLAYERCOUNT() >= 2) ? 0 : (s32)(textheight * 1.1f);
		textMeasure(&textheight, &textwidth, weaponname, g_AmFont1, g_AmFont2, 0);

		x = g_ViBackData->viewleft
			+ (s32)(g_ViBackData->viewx * 0.5f)
			- (s32)(textwidth * 0.5f)
			+ offset;

		if (wide) {
			x = g_ViBackData->viewleft + 32;
		}

		gdl = textRender(gdl, &x, &y, weaponname, g_AmFont1, g_AmFont2, -1,
				0x000000ff, 320, 240, 0, 0);

		g_Vars.currentplayer->commandingaibot = g_MpAllChrPtrs[buddynum];
	} else {
		char *title = langGet(L_MISC_215); // "All Simulants"

		textMeasure(&textheight, &textwidth, title, g_AmFont1, g_AmFont2, 0);

		x = g_ViBackData->viewleft
			+ (s32)(g_ViBackData->viewx * 0.5f)
			- (s32)(textwidth * 0.5f)
			+ offset;

		if (PLAYERCOUNT() >= 2) {
			y = g_ViBackData->viewtop + 5;
		} else {
			y = g_ViBackData->viewtop + 10;
		}

		if (wide) {
			x = g_ViBackData->viewleft + 32;
		}

		gdl = textRender(gdl, &x, &y, title, g_AmFont1, g_AmFont2, -1,
				0x000000ff, 320, 240, 0, 0);
	}

	return gdl;
}



u8 var800719a0[][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8} };

static Gfx *amRenderSlot(Gfx *gdl, char *text, s16 x, s16 y, s32 mode, s32 flags)
{
	u32 obcol = 0xff00004f; // outer border
	u32 ibcol = 0x3f00008f; // inner background
	u32 defcol = 0xff4f00ff; // text
	u32 favcol = 0xffff7fff; // unused
	u32 pickcol = 0xff4f00ff; // unused
	u32 pickcol2 = 0xff4f00ff; // unused

	u32 colour;
	s32 paddingtop;
	s32 paddingbottom;

	paddingtop = 6;
	paddingbottom = 6;

	if (PLAYERCOUNT() >= 2) {
		paddingtop = 5;
		paddingbottom = 3;
	}

	if (text == NULL || text[0] == '\0') {
		return gdl;
	}

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

						if (var800719a0[row][column] == 7) {
							if (chr->hidden & CHRHFLAG_PASSIVE) {
								mode = AMSLOTMODE_CURRENT;
							}
						} else if (var800719a0[row][column] == 1) {
							if ((chr->hidden & CHRHFLAG_PASSIVE) == 0) {
								mode = AMSLOTMODE_CURRENT;
							}
						}
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

			if (!(g_MissionConfig.iscoop && amGetFirstBuddyIndex() >= 0)
					&& vars->normmplayerisrunning
					&& g_AmMenus[g_AmIndex].screenindex >= 2) {
				gdl = amRenderAibotInfo(gdl, g_AmMenus[g_AmIndex].screenindex - 2);
			}
		}

		// Note: the column and row values will never be 1 here, so this
		// condition always passes. Looks like they intended to skip drawing the
		// selection box on the simulants screen if the middle box was selected.
		if (g_AmMenus[g_AmIndex].screenindex < 2 || column != 1 || row != 1) {
			// Render selection
			s32 halfwidth;
			s16 above;
			s16 below;

			above = 6;
			below = 6;

			if (PLAYERCOUNT() >= 2) {
				above = 5;
				below = 3;
			}

			colour = (sinf(g_AmMenus[g_AmIndex].selpulse) + 1) * 127;
			colour = 0xff0000ff | colour << 8 | colour << 16;

			if (g_Vars.currentplayer->activemenumode == AMMODE_EDIT) {
				colour = 0x4f4f4f7f;
			}

			gdl = textSetPrimColour(gdl, colour);

			halfwidth = g_AmMenus[g_AmIndex].slotwidth / 2;

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

		if ((PLAYERCOUNT() == 2 && g_ScreenSplit == SCREENSPLIT_VERTICAL) || PLAYERCOUNT() >= 3) {
			xoffset = (g_Vars.currentplayernum & 1) == 0 ? 8 : -8;
		}

		if (PLAYERCOUNT() == 1 && optionsGetEffectiveScreenSize() != SCREENSIZE_FULL) {
			part1left = g_ViBackData->viewleft + 32;
		} else {
			part1left = (s32) (g_ViBackData->viewx * 0.5f)
				+ (s32) (g_ViBackData->viewleft)
				- (s32) (barwidth * 0.5f)
				+ xoffset;
		}

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

		y = g_ViBackData->viewtop + g_ViBackData->viewy - (PLAYERCOUNT() >= 2 ? 19 : 34);

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

	return gdl;
}
