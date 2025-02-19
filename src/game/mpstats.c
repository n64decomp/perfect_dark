#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/inv.h"
#include "game/bondgun.h"
#include "game/gset.h"
#include "game/player.h"
#include "game/hudmsg.h"
#include "game/playermgr.h"
#include "game/mplayer/setup.h"
#include "game/botcmd.h"
#include "game/botinv.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "bss.h"
#include "data.h"
#include "types.h"

bool g_AllowRegionShot = false;

void mpstats_increment_player_shotcount_projectiles(struct gset *gset, s32 region)
{
	if (!gset_has_weapon_flag(gset->weaponnum, WEAPONFLAG_DONTCOUNTSHOTS)) {
		g_Vars.currentplayerstats->shotcount[region]++;
	}
}

/**
 * The usage of g_AllowRegionShot ensures that the sum of region shots does not
 * exceed the total shots.
 *
 * The sequence of calls when firing a shot is:
 * - Call mpstats_increment_player_shotcount with SHOTREGION_TOTAL.
 * - For each hits that landed (there can be multiple with the shotgun),
 *   call mpstats_increment_player_shotcount with that region.
 * - Call mpstats_end_shot so any unexpected region shots will not be counted.
 */
void mpstats_increment_player_shotcount(struct gset *gset, s32 region)
{
	if (region == SHOTREGION_TOTAL) {
		if (!gset_has_weapon_flag(gset->weaponnum, WEAPONFLAG_DONTCOUNTSHOTS)) {
			g_AllowRegionShot = true;
			g_Vars.currentplayerstats->shotcount[region]++;
		}
	} else {
		if (g_AllowRegionShot) {
			if (!gset_has_weapon_flag(gset->weaponnum, WEAPONFLAG_DONTCOUNTSHOTS)) {
				g_Vars.currentplayerstats->shotcount[region]++;
			}

			g_AllowRegionShot = false;
		}
	}
}

void mpstats_end_shot(void)
{
	g_AllowRegionShot = false;
}

s32 mpstats_get_player_shotcount_by_region(s32 region)
{
	return g_Vars.currentplayerstats->shotcount[region];
}

void mpstats_increment_total_kill_count(void)
{
	g_Vars.killcount++;
}

void mpstats_increment_total_knockout_count(void)
{
	g_Vars.knockoutcount++;
}

void mpstats_decrement_total_knockout_count(void)
{
	g_Vars.knockoutcount--;
}

u8 mpstats_get_total_knockout_count(void)
{
	return g_Vars.knockoutcount;
}

u32 mpstats_get_total_kill_count(void)
{
	return g_Vars.killcount;
}

void mpstats_record_player_kill(void)
{
	char text[256];
	s32 simulkills;
	s32 duration;
	s32 time;

	g_Vars.currentplayerstats->killcount++;
	g_Vars.currentplayer->killsthislife++;

	if (g_Vars.normmplayerisrunning) {
		time = player_get_mission_time();

		// Show HUD message
		// "Kill count: %d"
		sprintf(text, "%s: %d\n", lang_get(L_GUN_001), g_Vars.currentplayerstats->killcount);
		hudmsg_create(text, HUDMSGTYPE_DEFAULT);

		// Update slowest/fastest two kills
		if (g_Vars.currentplayerstats->killcount > 1) {
			duration = time - g_Vars.currentplayer->lastkilltime60;

			if (duration > g_Vars.currentplayerstats->slowest2kills) {
				g_Vars.currentplayerstats->slowest2kills = duration;
			}

			if (duration < g_Vars.currentplayerstats->fastest2kills) {
				g_Vars.currentplayerstats->fastest2kills = duration;
			}
		}

		// Update max simultaneous kills
		simulkills = 1;

		g_Vars.currentplayer->lastkilltime60_4 = g_Vars.currentplayer->lastkilltime60_3;
		g_Vars.currentplayer->lastkilltime60_3 = g_Vars.currentplayer->lastkilltime60_2;
		g_Vars.currentplayer->lastkilltime60_2 = g_Vars.currentplayer->lastkilltime60;
		g_Vars.currentplayer->lastkilltime60 = time;

		if (g_Vars.currentplayer->lastkilltime60_2 != -1 && g_Vars.currentplayer->lastkilltime60 - g_Vars.currentplayer->lastkilltime60_2 < 120) {
			simulkills++;

			if (g_Vars.currentplayer->lastkilltime60_3 != -1 && g_Vars.currentplayer->lastkilltime60 - g_Vars.currentplayer->lastkilltime60_3 < 120) {
				simulkills++;

				if (g_Vars.currentplayer->lastkilltime60_4 != -1 && g_Vars.currentplayer->lastkilltime60 - g_Vars.currentplayer->lastkilltime60_4 < 120) {
					simulkills++;
				}
			}
		}

		if (simulkills > g_Vars.currentplayerstats->maxsimulkills) {
			g_Vars.currentplayerstats->maxsimulkills = simulkills;
		}
	}
}

s32 mpstats_get_player_kill_count(void)
{
	return g_Vars.currentplayerstats->killcount;
}

void mpstats_increment_player_gg_kill_count(void)
{
	g_Vars.currentplayerstats->ggkillcount++;
}

void mpstats_record_player_death(void)
{
	char buffer[256];

	g_Vars.currentplayer->deathcount++;

	if (g_Vars.normmplayerisrunning) {
		if (g_Vars.currentplayer->deathcount == 1) {
			sprintf(buffer, lang_get(L_GUN_002)); // "Died once"
		} else {
			sprintf(buffer, "%s %d %s\n",
					lang_get(L_GUN_003), // "Died"
					g_Vars.currentplayer->deathcount,
					lang_get(L_GUN_004)); // "times"
		}

		hudmsg_create(buffer, HUDMSGTYPE_DEFAULT);
	}
}

void mpstats_record_player_suicide(void)
{
	char text[256];
	s32 simulkills;
	s32 duration;
	s32 time;
	s32 mpindex;
	struct mpchrconfig *mpchr;

	if (g_Vars.normmplayerisrunning) {
		time = player_get_mission_time();
		mpindex = g_Vars.currentplayerstats->mpindex;

		mpchr = MPCHR(mpindex);

		// Show HUD message
		// "Suicide count: %d"
		sprintf(text, "%s: %d\n", lang_get(L_GUN_005), mpchr->killcounts[mpindex]);
		hudmsg_create(text, HUDMSGTYPE_DEFAULT);

		// Update slowest/fastest two kills
		if (g_Vars.currentplayerstats->killcount > 1) {
			duration = time - g_Vars.currentplayer->lastkilltime60;

			if (duration > g_Vars.currentplayerstats->slowest2kills) {
				g_Vars.currentplayerstats->slowest2kills = duration;
			}

			if (duration < g_Vars.currentplayerstats->fastest2kills) {
				g_Vars.currentplayerstats->fastest2kills = duration;
			}
		}

		// Update max simultaneous kills
		simulkills = 1;

		g_Vars.currentplayer->lastkilltime60_4 = g_Vars.currentplayer->lastkilltime60_3;
		g_Vars.currentplayer->lastkilltime60_3 = g_Vars.currentplayer->lastkilltime60_2;
		g_Vars.currentplayer->lastkilltime60_2 = g_Vars.currentplayer->lastkilltime60;
		g_Vars.currentplayer->lastkilltime60 = time;

		if (g_Vars.currentplayer->lastkilltime60_2 != -1 && g_Vars.currentplayer->lastkilltime60 - g_Vars.currentplayer->lastkilltime60_2 < 120) {
			simulkills++;

			if (g_Vars.currentplayer->lastkilltime60_3 != -1 && g_Vars.currentplayer->lastkilltime60 - g_Vars.currentplayer->lastkilltime60_3 < 120) {
				simulkills++;

				if (g_Vars.currentplayer->lastkilltime60_4 != -1 && g_Vars.currentplayer->lastkilltime60 - g_Vars.currentplayer->lastkilltime60_4 < 120) {
					simulkills++;
				}
			}
		}

		if (simulkills > g_Vars.currentplayerstats->maxsimulkills) {
			g_Vars.currentplayerstats->maxsimulkills = simulkills;
		}
	}
}

void mpstats_record_death(s32 aplayernum, s32 vplayernum)
{
	s32 vmpindex = -1;
	struct mpchrconfig *vmpchr = NULL;
	s32 ampindex;
	struct mpchrconfig *ampchr = NULL;
	s32 prevplayernum;
	char text[256];

	if (g_Vars.normmplayerisrunning && g_MpSetup.scenario == MPSCENARIO_POPACAP) {
		pac_handle_death(aplayernum, vplayernum);
	}

	// Find attacker and victim mpchrs
	if (aplayernum >= 0) {
		ampindex = mp_chrindex_to_chrslot(aplayernum);

		if (ampindex >= 0) {
			ampchr = MPCHR(ampindex);
		}
	}

	if (vplayernum >= 0) {
		vmpindex = mp_chrindex_to_chrslot(vplayernum);

		if (vmpindex >= 0) {
			vmpchr = MPCHR(vmpindex);
		}
	}

	if (vplayernum >= 0 && aplayernum == vplayernum) {
		// Player suicide
		if (vmpchr && vmpindex >= 0) {
			vmpchr->numdeaths++;
			vmpchr->killcounts[vmpindex]++;
		}

		if (vplayernum < PLAYERCOUNT()) {
			prevplayernum = g_Vars.currentplayernum;
			set_current_player_num(vplayernum);
			mpstats_record_player_suicide();
			set_current_player_num(prevplayernum);
		}
	} else {
		// Normal kill
		if (vplayernum >= 0) {
			if (vmpchr) {
				vmpchr->numdeaths++;
			}

			if (vplayernum < PLAYERCOUNT()) {
				// Victim was a player
				prevplayernum = g_Vars.currentplayernum;
				set_current_player_num(vplayernum);

				if (g_Vars.normmplayerisrunning && aplayernum >= 0) {
					// "Killed by %s"
					sprintf(text, "%s %s", lang_get(L_MISC_183), g_MpAllChrConfigPtrs[aplayernum]->name);
					hudmsg_create(text, HUDMSGTYPE_DEFAULT);
				}

				mpstats_record_player_death();
				set_current_player_num(prevplayernum);
			}
		}

		if (ampchr && vmpindex >= 0) {
			ampchr->killcounts[vmpindex]++;
		}

		if (aplayernum >= 0 && aplayernum < PLAYERCOUNT()) {
			// Attacker was a player
			prevplayernum = g_Vars.currentplayernum;
			set_current_player_num(aplayernum);

			if (g_Vars.normmplayerisrunning && vplayernum >= 0) {
				// "Killed %s"
				sprintf(text, "%s %s", lang_get(L_MISC_184), g_MpAllChrConfigPtrs[vplayernum]->name);
				hudmsg_create(text, HUDMSGTYPE_DEFAULT);
			}

			mpstats_record_player_kill();
			set_current_player_num(prevplayernum);
		}

		// If someone killed an aibot
		if (g_Vars.normmplayerisrunning
				&& aplayernum >= 0
				&& vplayernum >= PLAYERCOUNT()
				&& aplayernum != vplayernum) {
			g_MpAllChrPtrs[vplayernum]->aibot->lastkilledbyplayernum = aplayernum;
		}
	}

	if (g_Vars.normmplayerisrunning && aplayernum >= 0 && g_MpAllChrPtrs[aplayernum]->aibot) {
		s32 index = mp_get_weapon_slot_by_weapon_num(g_MpAllChrPtrs[aplayernum]->aibot->weaponnum);

		if (index >= 0) {
			if (aplayernum == vplayernum) {
				g_MpAllChrPtrs[aplayernum]->aibot->suicidesbygunfunc[index][g_MpAllChrPtrs[aplayernum]->aibot->gunfunc]++;
			} else {
				g_MpAllChrPtrs[aplayernum]->aibot->killsbygunfunc[index][g_MpAllChrPtrs[aplayernum]->aibot->gunfunc]++;
			}
		}
	}

	g_Vars.totalkills++;
}
