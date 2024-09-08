#include <ultra64.h>
#include "constants.h"
#include "game/chraction.h"
#include "game/debug.h"
#include "game/chr.h"
#include "game/ceil.h"
#include "game/gset.h"
#include "game/playermgr.h"
#include "game/mplayer/setup.h"
#include "game/bot.h"
#include "game/botact.h"
#include "game/botcmd.h"
#include "game/botinv.h"
#include "game/mplayer/mplayer.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

struct botweaponconfig g_BotWeaponConfigs[] = {
	//                             score1
	//                             |    score2                                                                                    targetammosec
	//                             |    |    dualscore1                                                                           |    criticalammopri
	//                             |    |    |    dualscore2                                                                      |    |   criticalammosec
	//                             |    |    |    |    haspriammogoal                                                             |    |   |   reloaddelay (seconds)
	//                             |    |    |    |    |  hassecammogoal                                                          |    |   |   |  allowpartialreloaddelay
	//                             |    |    |    |    |  |  pridistconfig              secdistconfig              targetammopri  |    |   |   |  |
	/*WEAPON_NONE             */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  0, 0 },
	/*WEAPON_UNARMED          */ { 13,  13,  13,  13,  1, 1, BOTDISTCFG_CLOSE,          BOTDISTCFG_CLOSE,          0,             0,   0,  0,  0, 0 },
	/*WEAPON_FALCON2          */ { 56,  60,  84,  88,  1, 1, BOTDISTCFG_PISTOL,         BOTDISTCFG_CLOSE,          30,            0,   10, 0,  1, 0 },
	/*WEAPON_FALCON2_SILENCER */ { 52,  60,  80,  88,  1, 1, BOTDISTCFG_PISTOL,         BOTDISTCFG_CLOSE,          30,            0,   10, 0,  1, 0 },
	/*WEAPON_FALCON2_SCOPE    */ { 60,  60,  88,  88,  1, 1, BOTDISTCFG_PISTOL,         BOTDISTCFG_CLOSE,          30,            0,   10, 0,  1, 0 },
	/*WEAPON_MAGSEC4          */ { 76,  88,  104, 120, 1, 1, BOTDISTCFG_PISTOL,         BOTDISTCFG_DEFAULT,        30,            30,  10, 10, 1, 0 },
	/*WEAPON_MAULER           */ { 64,  88,  92,  120, 1, 1, BOTDISTCFG_PISTOL,         BOTDISTCFG_DEFAULT,        30,            30,  10, 10, 1, 0 },
	/*WEAPON_PHOENIX          */ { 72,  76,  100, 120, 1, 1, BOTDISTCFG_PISTOL,         BOTDISTCFG_DEFAULT,        30,            30,  10, 10, 2, 0 },
	/*WEAPON_DY357MAGNUM      */ { 68,  76,  96,  120, 1, 1, BOTDISTCFG_PISTOL,         BOTDISTCFG_CLOSE,          30,            0,   8,  0,  3, 0 },
	/*WEAPON_DY357LX          */ { 180, 188, 184, 188, 1, 1, BOTDISTCFG_PISTOL,         BOTDISTCFG_CLOSE,          20,            0,   6,  0,  3, 0 },
	/*WEAPON_CMP150           */ { 116, 128, 136, 152, 1, 1, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        100,           100, 30, 30, 2, 0 },
	/*WEAPON_CYCLONE          */ { 120, 128, 132, 140, 1, 1, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        150,           150, 50, 50, 2, 0 },
	/*WEAPON_CALLISTO         */ { 152, 176, 0,   0,   1, 1, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        100,           70,  25, 15, 2, 0 },
	/*WEAPON_RCP120           */ { 172, 188, 0,   0,   1, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        300,           0,   40, 0,  2, 0 },
	/*WEAPON_LAPTOPGUN        */ { 128, 140, 0,   0,   1, 1, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        100,           0,   30, 0,  3, 0 },
	/*WEAPON_DRAGON           */ { 124, 148, 0,   0,   1, 1, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        90,            0,   30, 0,  1, 0 },
	/*WEAPON_K7AVENGER        */ { 156, 180, 0,   0,   1, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        150,           0,   40, 0,  2, 0 },
	/*WEAPON_AR34             */ { 148, 176, 0,   0,   1, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        120,           0,   40, 0,  2, 0 },
	/*WEAPON_SUPERDRAGON      */ { 164, 188, 0,   0,   1, 1, BOTDISTCFG_DEFAULT,        BOTDISTCFG_SHOOTEXPLOSIVE, 120,           20,  30, 6,  1, 0 },
	/*WEAPON_SHOTGUN          */ { 140, 156, 0,   0,   1, 1, BOTDISTCFG_PISTOL,         BOTDISTCFG_PISTOL,         18,            18,  8,  8,  6, 1 },
	/*WEAPON_REAPER           */ { 144, 176, 0,   0,   1, 1, BOTDISTCFG_DEFAULT,        BOTDISTCFG_CLOSE,          400,           0,   80, 0,  3, 0 },
	/*WEAPON_SNIPERRIFLE      */ { 28,  40,  0,   0,   1, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        30,            30,  10, 10, 2, 0 },
	/*WEAPON_FARSIGHT         */ { 188, 188, 0,   0,   1, 0, BOTDISTCFG_SHOOTEXPLOSIVE, BOTDISTCFG_FARSIGHT,       16,            0,   4,  0,  2, 0 },
	/*WEAPON_DEVASTATOR       */ { 176, 188, 0,   0,   1, 1, BOTDISTCFG_SHOOTEXPLOSIVE, BOTDISTCFG_SHOOTEXPLOSIVE, 20,            20,  4,  4,  2, 0 },
	/*WEAPON_ROCKETLAUNCHER   */ { 160, 188, 0,   0,   1, 1, BOTDISTCFG_SHOOTEXPLOSIVE, BOTDISTCFG_SHOOTEXPLOSIVE, 2,             2,   1,  1,  2, 0 },
	/*WEAPON_SLAYER           */ { 168, 188, 0,   0,   1, 1, BOTDISTCFG_SHOOTEXPLOSIVE, BOTDISTCFG_SHOOTEXPLOSIVE, 2,             2,   1,  1,  3, 0 },
#if VERSION == VERSION_JPN_FINAL
	/*WEAPON_COMBATKNIFE      */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
#else
	/*WEAPON_COMBATKNIFE      */ { 20,  40,  24,  40,  1, 1, BOTDISTCFG_CLOSE,          BOTDISTCFG_DEFAULT,        0,             5,   0,  1,  1, 0 },
#endif
	/*WEAPON_CROSSBOW         */ { 108, 176, 0,   0,   1, 1, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        15,            15,  5,  5,  4, 1 },
	/*WEAPON_TRANQUILIZER     */ { 48,  188, 0,   0,   1, 1, BOTDISTCFG_DEFAULT,        BOTDISTCFG_CLOSE,          20,            24,  6,  8,  1, 0 },
	/*WEAPON_LASER            */ { 112, 112, 0,   0,   1, 1, BOTDISTCFG_DEFAULT,        BOTDISTCFG_CLOSE,          0,             0,   0,  0,  1, 0 },
	/*WEAPON_GRENADE          */ { 36,  172, 0,   0,   1, 1, BOTDISTCFG_THROWEXPLOSIVE, BOTDISTCFG_THROWEXPLOSIVE, 6,             6,   2,  2,  1, 0 },
	/*WEAPON_NBOMB            */ { 32,  188, 0,   0,   1, 1, BOTDISTCFG_THROWEXPLOSIVE, BOTDISTCFG_THROWEXPLOSIVE, 3,             3,   1,  1,  1, 0 },
	/*WEAPON_TIMEDMINE        */ { 12,  12,  0,   0,   0, 0, BOTDISTCFG_THROWEXPLOSIVE, BOTDISTCFG_DEFAULT,        5,             5,   1,  1,  1, 0 },
	/*WEAPON_PROXIMITYMINE    */ { 40,  176, 0,   0,   0, 0, BOTDISTCFG_THROWEXPLOSIVE, BOTDISTCFG_DEFAULT,        5,             5,   1,  1,  1, 0 },
	/*WEAPON_REMOTEMINE       */ { 44,  156, 0,   0,   1, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        5,             5,   2,  2,  1, 0 },
	/*WEAPON_COMBATBOOST      */ { 8,   8,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_PP9I             */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_CC13             */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_KL01313          */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_KF7SPECIAL       */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_ZZT              */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_DMC              */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_AR53             */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_RCP45            */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_PSYCHOSISGUN     */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_NIGHTVISION      */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_EYESPY           */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_XRAYSCANNER      */ { 4,   4,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_IRSCANNER        */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
#if VERSION >= VERSION_PAL_FINAL
	/*WEAPON_CLOAKINGDEVICE   */ { 218, 218, 0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        TICKS(1200),   0,   0,  0,  1, 0 },
#else
	/*WEAPON_CLOAKINGDEVICE   */ { 218, 218, 0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        1200,          0,   0,  0,  1, 0 },
#endif
	/*WEAPON_HORIZONSCANNER   */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_TESTER           */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_KINGSCEPTRE      */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_ECMMINE          */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_DATAUPLINK       */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_RTRACKER         */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_PRESIDENTSCANNER */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_DOORDECODER      */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_AUTOSURGEON      */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_EXPLOSIVES       */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_SKEDARBOMB       */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_COMMSRIDER       */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_TRACERBUG        */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_TARGETAMPLIFIER  */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_DISGUISE40       */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_DISGUISE41       */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_FLIGHTPLANS      */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_RESEARCHTAPE     */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_BACKUPDISK       */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_KEYCARD45        */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_KEYCARD46        */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_KEYCARD47        */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_KEYCARD48        */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_KEYCARD49        */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_KEYCARD4A        */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_KEYCARD4B        */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_KEYCARD4C        */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_SUITCASE         */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_BRIEFCASE        */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
#if VERSION >= VERSION_NTSC_1_0
	/*WEAPON_SHIELDTECHITEM   */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
#endif
	/*WEAPON_NECKLACE         */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_HAMMER           */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_SCREWDRIVER      */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_ROCKET           */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_HOMINGROCKET     */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_GRENADEROUND     */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_BOLT             */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_BRIEFCASE2       */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_SKROCKET         */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_CHOPPERGUN       */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_WATCHLASER       */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_MPSHIELD         */ { 220, 220, 0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_DISABLED         */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
	/*WEAPON_SUICIDEPILL      */ { 0,   0,   0,   0,   0, 0, BOTDISTCFG_DEFAULT,        BOTDISTCFG_DEFAULT,        0,             0,   0,  0,  1, 0 },
};

void botinv_score_weapon_by_itself(struct chrdata *chr, s32 weaponnum, s32 funcnum, s32 ifammo, bool dual, s32 *dst1, s32 *dst2);

/**
 * Remove all items from the bot's inventory.
 */
void botinv_clear(struct chrdata *chr)
{
	if (chr && chr->aibot) {
		s32 i = 0;

		for (i = 0; i < chr->aibot->maxitems; i++) {
			chr->aibot->items[i].type = -1;
		}

		dprint();
	}
}

/**
 * Return a free slot from the bot's inventory.
 *
 * In theory this should never fail. The inventory has 10 slots. 6 are for
 * weapons, and 4 are for scenario-specific items such as briefcases and the
 * data uplink.
 */
struct invitem *botinv_get_free_slot(struct chrdata *chr)
{
	s32 i;

	if (!chr || !chr->aibot) {
		return NULL;
	}

	for (i = 0; i < chr->aibot->maxitems; i++) {
		if (chr->aibot->items[i].type == -1) {
			return &chr->aibot->items[i];
		}
	}

	dprint();

	return NULL;
}

/**
 * Retrieve an inventory item from the bot's inventory.
 */
struct invitem *botinv_get_item(struct chrdata *chr, s32 weaponnum)
{
	s32 i;

	if (!chr || !chr->aibot) {
		return NULL;
	}

	for (i = 0; i < chr->aibot->maxitems; i++) {
		struct invitem *item = &chr->aibot->items[i];

		if (item->type == -1) {
			continue;
		}

		if (item->type == INVITEMTYPE_WEAP || item->type == INVITEMTYPE_DUAL) {
			if (item->type_weap.weapon1 == weaponnum) {
				return item;
			}
		}
	}

	return NULL;
}

/**
 * Remove a weapon from the bot's inventory.
 */
void botinv_remove_item(struct chrdata *chr, s32 weaponnum)
{
	s32 i;

	if (!chr || !chr->aibot) {
		return;
	}

	for (i = 0; i < chr->aibot->maxitems; i++) {
		struct invitem *item = &chr->aibot->items[i];

		if (item->type == -1) {
			continue;
		}

		if (item->type == INVITEMTYPE_WEAP || item->type == INVITEMTYPE_DUAL) {
			if (item->type_weap.weapon1 == weaponnum) {
				chr->aibot->items[i].type = -1;
				return;
			}
		}
	}
}

/**
 * Return the item type of the given weapon number.
 *
 * See the INVITEMTYPE constants.
 */
u32 botinv_get_item_type(struct chrdata *chr, u32 weaponnum)
{
	struct invitem *item;

	if (!chr || !chr->aibot) {
		return 0;
	}

	item = botinv_get_item(chr, weaponnum);

	if (item) {
		return item->type;
	}

	return 0;
}

/**
 * Give a single weapon to the bot.
 *
 * There is no pickup pad, so this is likely for dropped items.
 */
bool botinv_give_single_weapon(struct chrdata *chr, u32 weaponnum)
{
	if (!chr || !chr->aibot) {
		return false;
	}

	if (!botinv_get_item_type(chr, weaponnum)) {
		struct invitem *item = botinv_get_free_slot(chr);

		if (item) {
			item->type = INVITEMTYPE_WEAP;
			item->type_weap.weapon1 = weaponnum;
			item->type_weap.pickuppad = -1;
		}

		return true;
	}

	return false;
}

/**
 * Grant a bot dual weapons. They must already have the single weapon in their
 * inventory.
 *
 * This works by converting the single item into a dual item, which makes it
 * impossible for the bot to single wield that weapon while they have dual.
 * This is different to how the player's inventory works, where there are
 * inventory items for both single and dual and the player can choose which one
 * they want to use.
 */
void botinv_give_dual_weapon(struct chrdata *chr, u32 weaponnum)
{
	struct invitem *item = botinv_get_item(chr, weaponnum);

	if (item) {
		item->type = INVITEMTYPE_DUAL;
	}
}

/**
 * Return the pad number that the given weapon was collected from.
 *
 * Usually when you pick up two of the same weapon you get to dual wield, but
 * this does not happen if the second weapon is from the same pad as the first
 * (ie. is the first weapon respawned).
 */
s16 botinv_get_weapon_pad(struct chrdata *chr, u32 weaponnum)
{
	struct invitem *item = botinv_get_item(chr, weaponnum);

	if (item && item->type == INVITEMTYPE_WEAP) {
		return item->type_weap.pickuppad;
	}

	return -1;
}

/**
 * Give a weapon to the bot, either by direct weapon or by ammo crate.
 *
 * This function does not give any ammo to the bot.
 */
bool botinv_give_prop(struct chrdata *chr, struct prop *prop)
{
	bool result = false;
	struct defaultobj *obj;
	s32 i;

	if (!chr || !chr->aibot) {
		return false;
	}

	obj = prop->obj;

	if (prop->type == PROPTYPE_WEAPON) {
		if (obj->type == OBJTYPE_WEAPON) {
			struct weaponobj *weapon = prop->weapon;
			s32 weaponnum = weapon->weaponnum;
			result = botinv_give_single_weapon(chr, weaponnum);

			if (result) {
				struct invitem *item = botinv_get_item(chr, weaponnum);
				item->type_weap.pickuppad = obj->pad;
			}
		}
	} else if (obj->type == OBJTYPE_MULTIAMMOCRATE) {
		struct multiammocrateobj *multi = (struct multiammocrateobj *)prop->obj;

		for (i = 0; i < 19; i++) {
			if (multi->slots[i].quantity > 0) {
				s32 weaponnum = botact_get_weapon_by_ammo_type(i + 1);

				if (weaponnum > 0) {
					botinv_give_single_weapon(chr, weaponnum);
				}
			}
		}
	}

	return result;
}

void botinv0f198060(u32 arg0)
{
	// empty
}

/**
 * Score all weapons in the match's weaponset by themselves and write them to
 * the 3 array pointers, ordered by score1 descending.
 */
void botinv_score_all_weapons(struct chrdata *chr, s32 *weaponnums, s32 *scores1, s32 *scores2)
{
	s32 i;
	s32 pri1;
	s32 pri2;
	s32 sec1;
	s32 sec2;

	// Gather scores for each weapon in the setup,
	// taking the higher score out of both gun functions
	for (i = 0; i < ARRAYCOUNT(g_MpSetup.weapons); i++) {
		s32 weaponnum = g_MpWeapons[g_MpSetup.weapons[i]].weaponnum;
		weaponnums[i] = weaponnum;

		botinv_score_weapon_by_itself(chr, weaponnum, FUNC_PRIMARY, -1, false, &pri1, &pri2);
		botinv_score_weapon_by_itself(chr, weaponnum, FUNC_SECONDARY, -1, false, &sec1, &sec2);

		scores1[i] = pri1 >= sec1 ? pri1 : sec1;
		scores2[i] = pri2 >= sec2 ? pri2 : sec2;
	}

	// Sort all three arrays by score1 descending
	for (i = 0; i < ARRAYCOUNT(g_MpSetup.weapons); i++) {
		s32 swapindex = i;
		s32 tmp;
		s32 j;

		for (j = i + 1; j < ARRAYCOUNT(g_MpSetup.weapons); j++) {
			if (scores1[j] > scores1[swapindex]) {
				swapindex = j;
			}
		}

		if (swapindex != i) {
			tmp = scores1[swapindex];
			scores1[swapindex] = scores1[i];
			scores1[i] = tmp;

			tmp = scores2[swapindex];
			scores2[swapindex] = scores2[i];
			scores2[i] = tmp;

			tmp = weaponnums[swapindex];
			weaponnums[swapindex] = weaponnums[i];
			weaponnums[i] = tmp;
		}
	}
}

/**
 * Return true if the match's weaponset contains a shield.
 */
bool mp_has_shield(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_MpSetup.weapons); i++) {
		s32 weaponnum = g_MpWeapons[g_MpSetup.weapons[i]].weaponnum;

		if (weaponnum == WEAPON_MPSHIELD) {
			return true;
		}
	}

	return false;
}

/**
 * Get the weapon slot (0 to 5) by weapon number.
 */
s32 mp_get_weapon_slot_by_weapon_num(s32 weaponnum)
{
	s32 result = -1;
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_MpSetup.weapons); i++) {
		if (g_MpWeapons[g_MpSetup.weapons[i]].weaponnum == weaponnum && i < ARRAYCOUNT(g_MpSetup.weapons)) {
			result = i;
			break;
		}
	}

	return result;
}

/**
 * Calculate scores for the given weapon and function and write them to the
 * dst1 and dst2 pointers.
 *
 * Weapon scoring is used to determine if a weapon is better than another,
 * which affects whether the bot engages in combat or seeks a better weapon.
 */
void botinv_score_weapon(struct chrdata *chr, s32 weaponnum, s32 funcnum, s32 ifammo, bool dual, s32 *dst1, s32 *dst2, bool comparewithtarget, bool learn)
{
	s32 score1 = 0;
	s32 score2 = 0;
	s32 extra = 0;

	// @dangerous: Array overflow can occur if more weapons are added to the
	// game without extending the preferences table
	if (ifammo < 0
			|| (funcnum == FUNC_PRIMARY && ifammo == g_BotWeaponConfigs[weaponnum].haspriammogoal)
			|| (funcnum != FUNC_PRIMARY && ifammo == g_BotWeaponConfigs[weaponnum].hassecammogoal)) {
		if (dual) {
			score1 = g_BotWeaponConfigs[weaponnum].dualscore1;
			score2 = g_BotWeaponConfigs[weaponnum].dualscore2;
		} else {
			score1 = g_BotWeaponConfigs[weaponnum].score1;
			score2 = g_BotWeaponConfigs[weaponnum].score2;
		}

		if (chr && chr->aibot) {
			// Add weighting for explosive weapons for rocket sims
			// and weighting for shields for shield sims, with extra
			// weighting if the sim is meat or easy.
			if (chr->aibot->config->difficulty == BOTDIFF_MEAT) {
				extra = 100;
			} else if (chr->aibot->config->difficulty == BOTDIFF_EASY) {
				extra = 50;
			}

			if (chr->aibot->config->type == BOTTYPE_ROCKET) {
				if (weaponnum == WEAPON_ROCKETLAUNCHER) {
					score1 = extra + 300;
				} else if (weaponnum == WEAPON_SLAYER) {
					score1 = extra + 299;
				} else if (weaponnum == WEAPON_DEVASTATOR) {
					score1 = extra + 280;
				} else if (weaponnum == WEAPON_SUPERDRAGON && funcnum != FUNC_PRIMARY) {
					score1 = extra + 279;
				} else if (weaponnum == WEAPON_PHOENIX && funcnum != FUNC_PRIMARY) {
					score1 = extra + 260;
				} else if (weaponnum == WEAPON_GRENADE) {
					score1 = extra + 240;
				}
			} else if (chr->aibot->config->type == BOTTYPE_SHIELD) {
				if (weaponnum == WEAPON_MPSHIELD) {
					score1 = extra + 300;
				}
			}
		}
	}

	// Missing from this list:
	// Mauler, K7 Avenger, AR34, sniper rifle, Farsight, laser, grenade
	switch (weaponnum) {
	case WEAPON_UNARMED:
		if (comparewithtarget && funcnum != FUNC_PRIMARY) {
			if (chr->target != -1
					&& bot_get_targets_weapon_num(chr) > WEAPON_UNARMED
					&& chr->aibot->config->difficulty > BOTDIFF_MEAT) {
				score1 = 26;
				score2 = 26;
			} else {
				score1 = 0;
				score2 = 0;
			}
		}
		break;
	case WEAPON_FALCON2:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 15;
			score2 = 15;
		}
		break;
	case WEAPON_FALCON2_SILENCER:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 14;
			score2 = 14;
		}
		break;
	case WEAPON_FALCON2_SCOPE:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 16;
			score2 = 16;
		}
		break;
	case WEAPON_MAGSEC4:
		if (funcnum == FUNC_PRIMARY) {
			score1 = dual ? 91 : 63;
		}
		break;
	case WEAPON_PHOENIX:
		if (chr->aibot->config->type != BOTDIFF_HARD) {
			if (funcnum != FUNC_PRIMARY) {
				if ((g_MpSetup.options & MPOPTION_ONEHITKILLS)
						&& chr->aibot->config->difficulty >= BOTDIFF_NORMAL) {
					score1 = 110;
					score2 = 150;
				}
			} else {
				score1 = dual ? 90 : 62;
			}
		}
		break;
	case WEAPON_DY357MAGNUM:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 17;
			score2 = 17;
		}
		break;
	case WEAPON_DY357LX:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 18;
			score2 = 18;
		}
		break;
	case WEAPON_CYCLONE:
		if (funcnum == (chr->aibot->random1 % 2)) {
			score1--;
		}
		break;
	case WEAPON_CALLISTO:
		if (funcnum == (chr->aibot->random1 % 2)) {
			score1--;
		}
		break;
	case WEAPON_RCP120:
		if (chr->aibot->cloakdeviceenabled == false
				&& botact_get_ammo_quantity_by_weapon(chr->aibot, WEAPON_RCP120, FUNC_PRIMARY, true) > 500
				&& chr->aibot->config->difficulty > BOTDIFF_MEAT) {
			score1 += chr->aibot->random1 % 10;
			score2 += chr->aibot->random1 % 10;
		}
		break;
	case WEAPON_LAPTOPGUN:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 0;
			score2 = 0;
		}
		break;
	case WEAPON_DRAGON:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 0;
			score2 = 0;
		}
		break;
	case WEAPON_SUPERDRAGON:
		if (chr->aibot->config->type != BOTDIFF_HARD
				&& (chr->aibot->random1 % 2) == funcnum) {
			score1 -= 15;
		}
		break;
	case WEAPON_SHOTGUN:
		if (funcnum == (chr->aibot->random1 % 2)) {
			score1--;
		}
		break;
	case WEAPON_REAPER:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 19;
			score2 = 80;
		}
		break;
	case WEAPON_DEVASTATOR:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 0;
			score2 = 0;
		}
		break;
	case WEAPON_ROCKETLAUNCHER:
		if (funcnum == (chr->aibot->random1 % 2)) {
			score1--;
		}
		break;
	case WEAPON_SLAYER:
		if (chr->aibot->config->type == BOTDIFF_HARD) {
			if (funcnum != FUNC_PRIMARY) {
				if (chr->aibot->config->difficulty > BOTDIFF_MEAT) {
					if (comparewithtarget) {
						if (chr->target != -1
								&& chr->aibot->chrsinsight[mp_player_get_index(chr_get_target_prop(chr)->chr)] == 0
								&& (chr->aibot->random1 % 2) == 0) {
							score1 += 10;
						} else {
							score1 -= 10;
						}
					}
				} else {
					score1 = 0;
					score2 = 0;
				}
			}
		} else {
			if (funcnum != FUNC_PRIMARY) {
				if (chr->aibot->config->difficulty >= BOTDIFF_NORMAL) {
					if (comparewithtarget) {
						if (chr->target != -1
								&& chr->aibot->chrsinsight[mp_player_get_index(chr_get_target_prop(chr)->chr)] == 0
								&& (chr->aibot->random1 % 2) == 0) {
							score1 = 178;
							score2 = 188;
						} else {
							score1 -= 15;
							score2 -= 15;
						}
					}
				} else {
					score1 = 0;
					score2 = 0;
				}
			}
		}
		break;
	case WEAPON_COMBATKNIFE:
		if (funcnum != FUNC_PRIMARY) {
			score1 = 0;
			score2 = 0;
		}
		break;
	case WEAPON_CROSSBOW:
		if (funcnum != FUNC_PRIMARY) {
			if (chr->aibot->config->difficulty > BOTDIFF_MEAT) {
				score1 = 158;
				score2 = 176;
			} else {
				score1 = 0;
				score2 = 0;
			}
		} else {
			if (comparewithtarget && chr->target != -1 && chr_get_target_prop(chr)->chr->blurdrugamount > TICKS(3500)) {
				score1 = 0;
				score2 = 0;
			} else {
				score1 = 49;
				score2 = 188;
			}
		}
		break;
	case WEAPON_TRANQUILIZER:
		if (comparewithtarget) {
			s32 bluramount = 0;

			if (chr->target != -1) {
				bluramount = chr_get_target_prop(chr)->chr->blurdrugamount;
			}

			if (funcnum != FUNC_PRIMARY) {
				if (chr->aibot->config->difficulty <= BOTDIFF_MEAT) {
					score1 = 0;
					score2 = 0;
				} else if (bluramount > TICKS(3500) && (chr->aibot->random1 % 2) == 0) {
					score1 = chr->aibot->random1 % 140 + 48;
					score2 = 188;
				} else if (chr->aibot->random1 % 10 == 0) {
					score1 = chr->aibot->random1 % 140 + 48;
					score2 = 188;
				} else {
					score1 = 0;
					score2 = 0;
				}
			} else {
				if (bluramount >= TICKS(5000)) {
					score2 = 48;

					if (chr->aibot->random1 % 2) {
						score1 = 0;
						score2 = 0;
					}
				} else if (bluramount > TICKS(3500)) {
					u32 value = (-bluramount * 16 + (PAL ? 66656 : 80000)) / TICKS(1500);

					if (value > 15) {
						value = 15;
					}

					value *= value;
					value *= value;
					value *= value;

					if (value < chr->aibot->random1) {
						score2 = 48;

						if (chr->aibot->random1 % 2) {
							score1 = 0;
							score2 = 0;
						}
					}
				}
			}
		}
		break;
	case WEAPON_NBOMB:
		if (comparewithtarget && chr->target != -1) {
			bot_get_targets_weapon_num(chr);
		}
		break;
	}

	if (learn) {
		// Learn from recent usage stats
		s32 weaponindex;
		s32 extra = 0;
		f32 float1;
		f32 killrate = 1;
		f32 float2;

		if (g_Vars.lvframe60 > 0) {
			killrate = g_Vars.totalkills * TICKS(3600.0f) / (f32)(g_Vars.lvframe60 * g_MpNumChrs);

			if (killrate < 1) {
				killrate = 1;
			}
		}

		weaponindex = mp_get_weapon_slot_by_weapon_num(weaponnum);

		if (weaponindex >= 0) {
			float2 = ceilf(chr->aibot->equipdurations60[weaponindex][funcnum] * (1.0f / TICKS(3600.0f)));

			if (float2 > 0) {
				float1 = chr->aibot->killsbygunfunc[weaponindex][funcnum];

				if (chr->aibot->config->difficulty >= BOTDIFF_NORMAL) {
					float1 -= 3.0f * chr->aibot->suicidesbygunfunc[weaponindex][funcnum];
				}

				float1 = float1 / float2;

				extra = float1 * 10.0f / killrate;
			}

			if (extra > 30) {
				extra = 30;
			}

			extra += chr->aibot->equipextrascores[weaponindex];

			score1 += extra;
			score2 += extra;

			if (score1 < 0) {
				score1 = 0;
			}

			if (score2 < 0) {
				score2 = 0;
			}
		}
	}

	*dst1 = score1;
	*dst2 = score2;
}

void botinv_score_weapon_against_target(struct chrdata *chr, s32 weaponnum, s32 funcnum, s32 ifammo, bool dual, s32 *dst1, s32 *dst2)
{
	botinv_score_weapon(chr, weaponnum, funcnum, ifammo, dual, dst1, dst2, true, true);
}

void botinv_score_weapon_by_itself(struct chrdata *chr, s32 weaponnum, s32 funcnum, s32 ifammo, bool dual, s32 *dst1, s32 *dst2)
{
	botinv_score_weapon(chr, weaponnum, funcnum, ifammo, dual, dst1, dst2, false, true);
}

/**
 * Return the aibot's distance configuration index for the given weapon and
 * function.
 */
s32 botinv_get_dist_config(s32 weaponnum, s32 funcnum)
{
	if (funcnum != FUNC_PRIMARY) {
		return g_BotWeaponConfigs[weaponnum].secdistconfig;
	}

	return g_BotWeaponConfigs[weaponnum].pridistconfig;
}

/**
 * Check if the bot's personality permits it to use the given weapon and
 * function.
 */
bool botinv_allows_weapon(struct chrdata *chr, s32 weaponnum, s32 funcnum)
{
	bool allow = true;

	if (chr->aibot->config->type == BOTTYPE_FIST) {
		if (funcnum != FUNC_PRIMARY) {
			if (g_BotWeaponConfigs[weaponnum].secdistconfig != BOTDISTCFG_CLOSE) {
				allow = false;
			}
		} else {
			if (g_BotWeaponConfigs[weaponnum].pridistconfig != BOTDISTCFG_CLOSE) {
				allow = false;
			}
		}
	}

	return allow;
}

/**
 * Tick the bot's inventory.
 *
 * The logic for deciding when to switch weapons is here.
 */
void botinv_tick(struct chrdata *chr)
{
	s32 newweaponnum = WEAPON_UNARMED;
	s32 newfuncnum = FUNC_PRIMARY;
	s32 weaponindex;
	struct aibot *aibot;
	bool keepcurrentweapon = false;
	s32 i;

	if (!chr || !chr->aibot) {
		return;
	}

	aibot = chr->aibot;
	weaponindex = mp_get_weapon_slot_by_weapon_num(aibot->weaponnum);

	if (weaponindex >= 0) {
		aibot->equipdurations60[weaponindex][aibot->gunfunc] += g_Vars.lvupdate60;
	}

	// Every 60-61 seconds, decrease suicide values. These values are used when
	// determining which gun to use. The more suicides with a particular gun and
	// function, the less likely the aibot is to use it. This value cools off.
	aibot->dampensuicidesttl60 -= g_Vars.lvupdate60;

	if (aibot->dampensuicidesttl60 < 0) {
		aibot->dampensuicidesttl60 = TICKS(3600) + random() % TICKS(60);

		for (i = 0; i < ARRAYCOUNT(aibot->suicidesbygunfunc); i++) {
			aibot->suicidesbygunfunc[i][0] *= 0.9f;
			aibot->suicidesbygunfunc[i][1] *= 0.9f;
		}
	}

	// Every 10-60 seconds, generate new equipextrascores
	aibot->equipextrascorestimer60 -= g_Vars.lvupdate60;

	if (aibot->equipextrascorestimer60 < 0) {
		aibot->equipextrascorestimer60 = TICKS(600) + random() % TICKS(3000);

		for (i = 0; i < ARRAYCOUNT(aibot->equipextrascores); i++) {
			if (aibot->config->difficulty == BOTDIFF_MEAT) {
				aibot->equipextrascores[i] = random() % 200 - 100; // -100 to +100
			} else if (aibot->config->difficulty == BOTDIFF_EASY) {
				aibot->equipextrascores[i] = random() % 100 - 50; // -50 to +50
			} else {
				aibot->equipextrascores[i] = random() % 30 - 15; // -15 to +15
			}
		}
	}

	// Every 2-12 seconds, generate a new random value which is used as a factor
	// in various aibot logic.
	aibot->random1ttl60 -= g_Vars.lvupdate60;

	if (aibot->random1ttl60 < 0) {
		aibot->random1ttl60 = TICKS(120) + random() % TICKS(600);
		aibot->random1 = random();
	}

	if (aibot->cyclonedischarging[HAND_LEFT] == 0
			&& aibot->cyclonedischarging[HAND_RIGHT] == 0
			&& aibot->burstsdone[HAND_LEFT] <= 0
			&& aibot->burstsdone[HAND_RIGHT] <= 0
			&& aibot->reaperspeed[HAND_LEFT] <= 0
			&& aibot->reaperspeed[HAND_RIGHT] <= 0
			&& aibot->skrocket == NULL) {
		if (chr->myaction == MA_AIBOTDOWNLOAD) {
			keepcurrentweapon = true;
		}

		if (!keepcurrentweapon && aibot->config->type == BOTTYPE_PEACE) {
			newfuncnum = FUNC_SECONDARY;
			keepcurrentweapon = true;
		}

		if (!keepcurrentweapon) {
			s32 bestscore = 0;
			s32 score1;
			s32 score2;
			s32 canuse;
			s32 j;

			for (i = -1; i < aibot->maxitems; i++) {
				s32 weaponnum = -1;
				struct invitem *item = NULL;

				if (i < 0) {
					weaponnum = WEAPON_UNARMED;
				} else {
					item = &aibot->items[i];

					if (item->type == INVITEMTYPE_WEAP || item->type == INVITEMTYPE_DUAL) {
						weaponnum = item->type_weap.weapon1;
					}
				}

				if (weaponnum >= 0) {
					for (j = 1; j >= 0; j--) {
						if (j != FUNC_PRIMARY) {
							canuse = g_BotWeaponConfigs[weaponnum].hassecammogoal;
						} else {
							canuse = g_BotWeaponConfigs[weaponnum].haspriammogoal;
						}

						if (canuse && botinv_allows_weapon(chr, weaponnum, j)) {
							botinv_score_weapon_against_target(chr, weaponnum, j, 1, item && item->type == INVITEMTYPE_DUAL, &score1, &score2);

							if (score1 >= bestscore) {
								if (!botact_get_ammo_type_by_function(weaponnum, j)
										|| botact_get_ammo_quantity_by_weapon(aibot, weaponnum, j, true) > 0) {
									bestscore = score1;
									newweaponnum = weaponnum;
									newfuncnum = j;
								}
							}
						}
					}
				}
			}
		}

		// Consider setting knives to secondary function (throw)
		if (newweaponnum == WEAPON_COMBATKNIFE
				&& botact_get_ammo_quantity_by_weapon(aibot, WEAPON_COMBATKNIFE, FUNC_SECONDARY, true) >= 2
				&& chr->target != -1
				&& chr->aibot->chrdistances[mp_player_get_index(chr_get_target_prop(chr)->chr)] > 200
				&& chr->aibot->chrdistances[mp_player_get_index(chr_get_target_prop(chr)->chr)] < 1500) {
			newfuncnum = FUNC_SECONDARY;
		}

		// Consider setting Phoenix and SuperDragon to their explosive functions
		if (aibot->config->type == BOTTYPE_ROCKET) {
			if (newweaponnum == WEAPON_PHOENIX && botact_get_ammo_quantity_by_weapon(aibot, WEAPON_PHOENIX, FUNC_SECONDARY, true) > 0) {
				newfuncnum = FUNC_SECONDARY;
			} else if (newweaponnum == WEAPON_SUPERDRAGON && botact_get_ammo_quantity_by_weapon(aibot, WEAPON_SUPERDRAGON, FUNC_SECONDARY, true) > 0) {
				newfuncnum = FUNC_SECONDARY;
			}
		}

		botinv_switch_to_weapon(chr, newweaponnum, newfuncnum);
	}
}

/**
 * Equip the given weapon and switch to the given function.
 *
 * The weapon must already exist in the bot's inventory,
 * otherwise unarmed will be equipped instead.
 */
bool botinv_switch_to_weapon(struct chrdata *chr, s32 weaponnum, s32 funcnum)
{
	struct invitem *item;
	struct funcdef *func;
	struct aibot *aibot;
	s32 i;
	s32 modelnum;
	bool changinggun;
	bool changingfunc;

	if (!chr || !chr->aibot) {
		return false;
	}

	aibot = chr->aibot;

	if (weaponnum == WEAPON_BRIEFCASE2) {
		return true;
	}

	// If changing to anything other than unarmed, make sure the aibot has the
	// weapon in their inventory. Otherwise make them switch to unarmed.
	if (weaponnum != WEAPON_UNARMED) {
		item = botinv_get_item(chr, weaponnum);

		if (!item) {
			weaponnum = WEAPON_UNARMED;
			funcnum = FUNC_PRIMARY;
		}
	}

	changinggun = weaponnum != aibot->weaponnum;
	changingfunc = funcnum != aibot->gunfunc;

	if (changinggun) {
		aibot->changeguntimer60 = TICKS(60);

		for (i = 0; i < 2; i++) {
			aibot->cyclonedischarging[i] = false;
			aibot->burstsdone[i] = 0;
			aibot->reaperspeed[i] = 0;

			if (chr->weapons_held[i]) {
				chr->weapons_held[i]->obj->hidden |= OBJHFLAG_DELETING;
				chr->weapons_held[i] = NULL;
			}
		}
	}

	// Return any loaded ammo to reserve
	if (changingfunc || changinggun) {
		for (i = 0; i < 2; i++) {
			if (aibot->loadedammo[i] > 0) {
				botact_give_ammo_by_weapon(aibot, aibot->weaponnum, aibot->gunfunc, aibot->loadedammo[i]);
				aibot->loadedammo[i] = 0;
			}
		}
	}

	// Assign new weapon and function
	aibot->gunfunc = funcnum;
	aibot->weaponnum = weaponnum;

	// Load ammo from reserve into new weapon
	if (changingfunc && !changinggun) {
		for (i = 0; i < 2; i++) {
			if (chr->weapons_held[i]) {
				botact_reload(chr, i, false);
			}
		}
	}

	if (!changinggun) {
		modelnum = playermgr_get_model_of_weapon(weaponnum);

		// @dangerous: item is uninitialised if weaponnum is WEAPON_UNARMED.
		// This function assumes playermgr_get_model_of_weapon returns a negative value for
		// WEAPON_UNARMED which is a dangerous assumption to make, but correct.
		if (modelnum >= 0 && item && item->type == INVITEMTYPE_DUAL && chr->weapons_held[HAND_LEFT] == NULL) {
			chr_give_weapon(chr, modelnum, weaponnum, OBJFLAG_WEAPON_LEFTHANDED);
			botact_reload(chr, HAND_LEFT, false);
		}
	}

	func = gset_get_funcdef_by_weaponnum_funcnum(weaponnum, funcnum);

	aibot->ismeleeweapon = func && func->type == INVENTORYFUNCTYPE_MELEE;

	for (i = 0; i < 2; i++) {
		if (chr->weapons_held[i]) {
			chr->weapons_held[i]->weapon->gunfunc = chr->aibot->gunfunc;
		}
	}

	return true;
}

/**
 * Drop one or all items. The item does not need to be the equipped item but it
 * must exist in the bot's inventory.
 *
 * dropall is used when the bot is killed.
 */
void botinv_drop(struct chrdata *chr, s32 weaponnum, u8 dropall)
{
	s32 i;

	if (!chr || !chr->aibot) {
		return;
	}

	for (i = 0; i < chr->aibot->maxitems; i++) {
		struct invitem *item = &chr->aibot->items[i];

		if (item->type == -1) {
			continue;
		}

		if ((item->type == INVITEMTYPE_WEAP || item->type == INVITEMTYPE_DUAL)
				&& (dropall || weaponnum == item->type_weap.weapon1)) {
			if (!gset_has_weapon_flag(item->type_weap.weapon1, WEAPONFLAG_UNDROPPABLE)
					|| (g_Vars.normmplayerisrunning
						&& g_MpSetup.scenario == MPSCENARIO_HACKERCENTRAL
						&& item->type_weap.weapon1 == WEAPON_DATAUPLINK)) {
				s32 modelnum = playermgr_get_model_of_weapon(item->type_weap.weapon1);

				if (modelnum > 0) {
					struct prop *prop = weapon_create_for_chr(chr, modelnum, item->type_weap.weapon1, OBJFLAG_WEAPON_AICANNOTUSE, NULL, NULL);

					if (prop) {
						obj_set_dropped(prop, DROPTYPE_DEFAULT);
						obj_drop(prop, true);

						if (item->type_weap.weapon1 == WEAPON_BRIEFCASE2) {
							scenario_handle_dropped_token(chr, prop);
						}
					}
				}
			}
		}
	}

	if ((dropall && weaponnum >= WEAPON_FALCON2)
			|| (!dropall && weaponnum == chr->aibot->weaponnum)) {
		botinv_switch_to_weapon(chr, WEAPON_UNARMED, FUNC_PRIMARY);
	}

	chr->hidden |= CHRHFLAG_DROPPINGITEM;

	if (!dropall) {
		botinv_remove_item(chr, weaponnum);
	}
}

void botinv_drop_all(struct chrdata *chr, u32 weaponnum)
{
	botinv_drop(chr, weaponnum, true);
}

void botinv_drop_one(struct chrdata *chr, u32 weaponnum)
{
	botinv_drop(chr, weaponnum, false);
}
