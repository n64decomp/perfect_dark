#include <ultra64.h>
#include "constants.h"
#include "game/atan2f.h"
#include "game/bot.h"
#include "game/challenge.h"
#include "game/chrai.h"
#include "game/chraicommands.h"
#include "game/debug.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/mplayer/scenarios.h"
#include "game/mplayer/setup.h"
#include "game/pad.h"
#include "game/playermgr.h"
#include "game/prop.h"
#include "game/training.h"
#include "bss.h"
#include "lib/dma.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

u8 g_MpFeaturesForceUnlocked[40];
u8 g_MpFeaturesUnlocked[80];

u32 g_MpChallengeIndex = 0;
struct mpconfigfull *g_MpCurrentChallengeConfig = NULL;

struct challenge g_MpChallenges[] = {
	{ L_OPTIONS_406, MPCONFIG_CHALLENGE01 }, // "Challenge 1"
	{ L_OPTIONS_407, MPCONFIG_CHALLENGE02 }, // "Challenge 2"
	{ L_OPTIONS_408, MPCONFIG_CHALLENGE03 }, // "Challenge 3"
	{ L_OPTIONS_409, MPCONFIG_CHALLENGE04 }, // "Challenge 4"
	{ L_OPTIONS_410, MPCONFIG_CHALLENGE05 }, // "Challenge 5"
	{ L_OPTIONS_411, MPCONFIG_CHALLENGE06 }, // "Challenge 6"
	{ L_OPTIONS_412, MPCONFIG_CHALLENGE07 }, // "Challenge 7"
	{ L_OPTIONS_413, MPCONFIG_CHALLENGE08 }, // "Challenge 8"
	{ L_OPTIONS_414, MPCONFIG_CHALLENGE09 }, // "Challenge 9"
	{ L_OPTIONS_415, MPCONFIG_CHALLENGE10 }, // "Challenge 10"
	{ L_OPTIONS_416, MPCONFIG_CHALLENGE11 }, // "Challenge 11"
	{ L_OPTIONS_417, MPCONFIG_CHALLENGE12 }, // "Challenge 12"
	{ L_OPTIONS_418, MPCONFIG_CHALLENGE13 }, // "Challenge 13"
	{ L_OPTIONS_419, MPCONFIG_CHALLENGE14 }, // "Challenge 14"
	{ L_OPTIONS_420, MPCONFIG_CHALLENGE15 }, // "Challenge 15"
	{ L_OPTIONS_421, MPCONFIG_CHALLENGE16 }, // "Challenge 16"
	{ L_OPTIONS_422, MPCONFIG_CHALLENGE17 }, // "Challenge 17"
	{ L_OPTIONS_423, MPCONFIG_CHALLENGE18 }, // "Challenge 18"
	{ L_OPTIONS_424, MPCONFIG_CHALLENGE19 }, // "Challenge 19"
	{ L_OPTIONS_425, MPCONFIG_CHALLENGE20 }, // "Challenge 20"
	{ L_OPTIONS_426, MPCONFIG_CHALLENGE21 }, // "Challenge 21"
	{ L_OPTIONS_427, MPCONFIG_CHALLENGE22 }, // "Challenge 22"
	{ L_OPTIONS_428, MPCONFIG_CHALLENGE23 }, // "Challenge 23"
	{ L_OPTIONS_429, MPCONFIG_CHALLENGE24 }, // "Challenge 24"
	{ L_OPTIONS_430, MPCONFIG_CHALLENGE25 }, // "Challenge 25"
	{ L_OPTIONS_431, MPCONFIG_CHALLENGE26 }, // "Challenge 26"
	{ L_OPTIONS_432, MPCONFIG_CHALLENGE27 }, // "Challenge 27"
	{ L_OPTIONS_433, MPCONFIG_CHALLENGE28 }, // "Challenge 28"
	{ L_OPTIONS_434, MPCONFIG_CHALLENGE29 }, // "Challenge 29"
	{ L_OPTIONS_435, MPCONFIG_CHALLENGE30 }, // "Challenge 30"
};

void challenge_apply(void);

bool challenge_is_available(s32 challengeindex)
{
	return (g_MpChallenges[challengeindex].availability & 1) != 0;
}

bool challenge_is_available_to_player(s32 chrnum, s32 challengeindex)
{
	if ((g_MpSetup.chrslots & (1 << chrnum)) == 0) {
		return 0;
	}

	return ((g_MpChallenges[challengeindex].availability & (2 << chrnum)) != 0);
}

bool challenge_is_available_to_any_player(s32 challengeindex)
{
	return (g_MpChallenges[challengeindex].availability & (((g_MpSetup.chrslots & 0xf) << 1) | 1)) != 0;
}

void challenge_determine_unlocked_features(void)
{
	s32 challengeindex;
	s32 numgifted; // number of unlocked but not completed challenges
	u8 flag;
	s32 prev;
	s32 i;
	s32 j;
	s32 k;

	// Clear all challenge availability
	for (challengeindex = 0; challengeindex < ARRAYCOUNT(g_MpChallenges); challengeindex++) {
		g_MpChallenges[challengeindex].availability = 0;
	}

	numgifted = 0;

	// Mark challenges completed by any player
	for (challengeindex = 0; challengeindex < ARRAYCOUNT(g_MpChallenges); challengeindex++) {
		flag = 0;

		if (challenge_is_completed_by_any_player_with_num_players(challengeindex, 1)
				|| challenge_is_completed_by_any_player_with_num_players(challengeindex, 2)
				|| challenge_is_completed_by_any_player_with_num_players(challengeindex, 3)
				|| challenge_is_completed_by_any_player_with_num_players(challengeindex, 4)) {
			// Completed challenge
			flag = 1;
		} else if (challengeindex < 4) {
			// Not yet completed, but challenges 1-4 are always available
			flag = 1;
			numgifted++;
		} else if (challengeindex > 0
				&& (challenge_is_completed_by_any_player_with_num_players(challengeindex - 1, 1)
					|| challenge_is_completed_by_any_player_with_num_players(challengeindex - 1, 2)
					|| challenge_is_completed_by_any_player_with_num_players(challengeindex - 1, 3)
					|| challenge_is_completed_by_any_player_with_num_players(challengeindex - 1, 4))) {
			// Challenges are available if their previous one is complete
			flag = 1;
			numgifted++;
		}
#ifdef DEBUG
		else if (debug_is_all_challenges_enabled()) {
			flag = 1;
		}
#endif

		g_MpChallenges[challengeindex].availability |= flag;
	}

	// Gift up to 4 challenges
	for (challengeindex = 0; numgifted < 4 && challengeindex < ARRAYCOUNT(g_MpChallenges); challengeindex++) {
		if ((g_MpChallenges[challengeindex].availability & 1) == 0) {
			g_MpChallenges[challengeindex].availability |= 1;
			numgifted++;
		}
	}

	// Now same as above, but per player
	for (j = 0; j < MAX_PLAYERS; j++) {
		numgifted = 0;

		for (challengeindex = 0; challengeindex < ARRAYCOUNT(g_MpChallenges); challengeindex++) {
			flag = 0;

			if (challenge_is_completed_by_player_with_num_players(j, challengeindex, 1)
					|| challenge_is_completed_by_player_with_num_players(j, challengeindex, 2)
					|| challenge_is_completed_by_player_with_num_players(j, challengeindex, 3)
					|| challenge_is_completed_by_player_with_num_players(j, challengeindex, 4)) {
				// Completed challenge
				flag = 2 << j;
			} else if (challengeindex < 4) {
				// Not yet completed, but challenges 1-4 are always available
				flag = 2 << j;
				numgifted++;
			} else if (challengeindex > 0) {
				// Challenges are available if their previous one is complete
				prev = challengeindex - 1;

				if (challenge_is_completed_by_player_with_num_players(j, prev, 1)
						|| challenge_is_completed_by_player_with_num_players(j, prev, 2)
						|| challenge_is_completed_by_player_with_num_players(j, prev, 3)
						|| challenge_is_completed_by_player_with_num_players(j, prev, 4)) {
					flag = 2 << j;
					numgifted++;
				}
			}

			g_MpChallenges[challengeindex].availability |= flag;
		}

		// Gift up to 4 challenges
		for (challengeindex = 0; numgifted < 4 && challengeindex < ARRAYCOUNT(g_MpChallenges); challengeindex++) {
			if ((g_MpChallenges[challengeindex].availability & (2 << j)) == 0) {
				g_MpChallenges[challengeindex].availability |= 2 << j;
				numgifted++;
			}
		}
	}

	for (j = 0; j < ARRAYCOUNT(g_MpFeaturesUnlocked); j++) {
		flag = 0;

		for (challengeindex = 0; challengeindex < ARRAYCOUNT(g_MpChallenges); challengeindex++) {
			if (challenge_is_available_to_any_player(challengeindex)) {
				for (i = 0; i < ARRAYCOUNT(g_MpChallenges[challengeindex].unlockfeatures); i++) {
					if (g_MpChallenges[challengeindex].unlockfeatures[i] == j) {
						flag |= 1;
					}
				}
			}
		}

		for (i = 0; i < ARRAYCOUNT(g_MpFeaturesForceUnlocked); i++) {
			if (g_MpFeaturesForceUnlocked[i] == j) {
				flag |= 1;
			}
		}

		for (challengeindex = 0; challengeindex < ARRAYCOUNT(g_MpChallenges); challengeindex++) {
			for (prev = 0; prev < MAX_PLAYERS; prev++) {
				if (challenge_is_available_to_player(prev, challengeindex)) {
					for (i = 0; i < ARRAYCOUNT(g_MpChallenges[challengeindex].unlockfeatures); i++) {
						if (g_MpChallenges[challengeindex].unlockfeatures[i] == j) {
							flag |= 2 << prev;
						}
					}
				}
			}
		}

		g_MpFeaturesUnlocked[j] = flag;
	}

	for (j = 0; j < func0f188bcc(); j++) {
		struct mpweapon *weapon = &g_MpWeapons[j];

		if (weapon->unlockfeature > 0 && fr_is_weapon_available_for_mp(weapon->weaponnum)) {
			g_MpFeaturesUnlocked[weapon->unlockfeature] |= 1;
		}
	}

	func0f1895e8();

	// If the ability to have 8 simulants hasn't been unlocked, limit them to 4
	if (!challenge_is_feature_unlocked(MPFEATURE_8BOTS)) {
		for (k = 4; k < MAX_BOTS; k++) {
			if (g_MpSetup.chrslots & (1 << (MAX_PLAYERS + k))) {
				mp_remove_simulant(k);
			}
		}

		if (g_Vars.mpquickteamnumsims > 4) {
			g_Vars.mpquickteamnumsims = 4;
		}
	}
}

void challenge_perform_sanity_checks(void)
{
	if (g_BossFile.locktype == MPLOCKTYPE_CHALLENGE) {
		s32 numplayers = 0;
		s32 i;

		// Reset player handicaps
		for (i = 0; i < MAX_PLAYERS; i++) {
			if (g_MpSetup.chrslots & (1 << i)) {
				g_PlayerConfigsArray[i].handicap = 0x80;
				numplayers++;
			}
		}

		// Turn off all simulants and turn them on if enabled
		// for this number of players
		g_MpSetup.chrslots &= 0x000f;

		for (i = 0; i < MAX_BOTS; i++) {
			g_BotConfigsArray[i].difficulty = g_MpSimulantDifficultiesPerNumPlayers[i][numplayers - 1];

			if (g_BotConfigsArray[i].difficulty != BOTDIFF_DISABLED) {
				g_MpSetup.chrslots |= 1 << (i + MAX_PLAYERS);
			}
		}

		if (g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL) {
			g_Vars.mphilltime = 10;
		}
	} else if (!challenge_is_feature_unlocked(MPFEATURE_8BOTS)) {
		// Limit to 4 players and 4 simulants
		g_MpSetup.chrslots &= 0x00ff;
	}
}

s32 challenge_get_num_available(void)
{
	s32 challengeindex;
	s32 count = 0;

	for (challengeindex = 0; challengeindex < ARRAYCOUNT(g_MpChallenges); challengeindex++) {
		if (challenge_is_available_to_any_player(challengeindex)) {
			count++;
		}
	}

	return count;
}

char *challenge_get_name(s32 challengeindex)
{
	return lang_get(g_MpChallenges[challengeindex].name);
}

char *challenge_get_name_by_slot(s32 slot)
{
	s32 index = 0;
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_MpChallenges); i++) {
		if (challenge_is_available_to_any_player(i)) {
			if (index == slot) {
				return challenge_get_name(i);
			}

			index++;
		}
	}

	return "";
}

void challenge_set_current_by_slot(s32 slotnum)
{
	s32 challengeindex;
	g_MpChallengeIndex = 0;

	for (challengeindex = 0; challengeindex < ARRAYCOUNT(g_MpChallenges); challengeindex++) {
		if (challenge_is_available_to_any_player(challengeindex)) {
			if (slotnum == 0) {
				g_MpChallengeIndex = challengeindex;
				break;
			}

			slotnum--;
		}
	}

	challenge_apply();
}

s32 challenge_get_current(void)
{
	return g_MpChallengeIndex;
}

bool challenge_is_completed_by_any_chr_with_num_players_by_slot(s32 slot, s32 numplayers)
{
	s32 availableindex = 0;
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_MpChallenges); i++) {
		if (challenge_is_available_to_any_player(i)) {
			if (availableindex == slot) {
				return challenge_is_completed_by_any_player_with_num_players(i, numplayers);
			}

			availableindex++;
		}
	}

	return false;
}

bool challenge_is_completed_by_chr_with_num_players_by_slot(s32 mpchrnum, s32 slot, s32 numplayers)
{
	s32 availableindex = 0;
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_MpChallenges); i++) {
		if (challenge_is_available_to_any_player(i)) {
			if (availableindex == slot) {
				return challenge_is_completed_by_player_with_num_players(mpchrnum, i, numplayers);
			}

			availableindex++;
		}
	}

	return false;
}

struct mpconfigfull *challenge_load_config(s32 confignum, u8 *buffer, s32 len)
{
	struct mpconfigfull *mpconfig;
	u8 buffer2[sizeof(struct mpstrings) + 40];
	struct mpstrings *loadedstrings;
	s32 bank;
	u32 language_id = lang_get_file_num_offset();
	extern struct mpconfig _mpconfigsSegmentRomStart[];
	extern struct mpstrings _mpstringsESegmentRomStart;
	extern struct mpstrings _mpstringsJSegmentRomStart;
	extern struct mpstrings _mpstringsPSegmentRomStart;
	extern struct mpstrings _mpstringsGSegmentRomStart;
	extern struct mpstrings _mpstringsFSegmentRomStart;
	extern struct mpstrings _mpstringsSSegmentRomStart;
	extern struct mpstrings _mpstringsISegmentRomStart;
	extern struct mpstrings _mpstringsESegmentRomEnd;
	extern struct mpstrings _mpstringsJSegmentRomEnd;
	extern struct mpstrings _mpstringsPSegmentRomEnd;
	extern struct mpstrings _mpstringsGSegmentRomEnd;
	extern struct mpstrings _mpstringsFSegmentRomEnd;
	extern struct mpstrings _mpstringsSSegmentRomEnd;
	extern struct mpstrings _mpstringsISegmentRomEnd;

	s32 banks[][2] = {
		{ (s32)&_mpstringsESegmentRomStart, (s32)&_mpstringsESegmentRomEnd },
		{ (s32)&_mpstringsJSegmentRomStart, (s32)&_mpstringsJSegmentRomEnd },
		{ (s32)&_mpstringsPSegmentRomStart, (s32)&_mpstringsPSegmentRomEnd },
		{ (s32)&_mpstringsGSegmentRomStart, (s32)&_mpstringsGSegmentRomEnd },
		{ (s32)&_mpstringsFSegmentRomStart, (s32)&_mpstringsFSegmentRomEnd },
		{ (s32)&_mpstringsSSegmentRomStart, (s32)&_mpstringsSSegmentRomEnd },
		{ (s32)&_mpstringsISegmentRomStart, (s32)&_mpstringsISegmentRomEnd },
	};

	// Load mpconfigs
	mpconfig = dma_exec_with_auto_align(buffer, (s32)&_mpconfigsSegmentRomStart[confignum], sizeof(struct mpconfig));

	// Load mpstrings
	bank = banks[language_id][0];
	loadedstrings = dma_exec_with_auto_align(buffer2, bank + confignum * sizeof(struct mpstrings), sizeof(struct mpstrings));

	mpconfig->strings = *loadedstrings;

	return mpconfig;
}

struct mpconfigfull *challenge_load(s32 challengeindex, u8 *buffer, s32 len)
{
	return challenge_load_config(g_MpChallenges[challengeindex].confignum, buffer, len);
}

struct mpconfigfull *challenge_load_by_slot(s32 n, u8 *buffer, s32 len)
{
	s32 numavailable = 0;
	s32 challengeindex;

	for (challengeindex = 0; challengeindex < ARRAYCOUNT(g_MpChallenges); challengeindex++) {
		if (challenge_is_available_to_any_player(challengeindex)) {
			if (numavailable == n) {
				return challenge_load(challengeindex, buffer, len);
			}

			numavailable++;
		}
	}

	return 0;
}

struct mpconfigfull *challenge_load_current(u8 *buffer, s32 len)
{
	return challenge_load(g_MpChallengeIndex, buffer, len);
}

/**
 * This is adding featurenum to the array, provided it's unique.
 */
s32 challenge_force_unlock_feature(s32 featurenum, u8 *array, s32 tail, s32 len)
{
	s32 i;

	for (i = 0; i < tail; i++) {
		if (array[i] == featurenum) {
			break;
		}
	}

	if (i >= tail && tail < len) {
		array[tail] = featurenum;
		tail++;
	}

	return tail;
}

s32 challenge_force_unlock_setup_features(struct mpsetup *setup, u8 *array, s32 len)
{
	s32 index = 0;
	s32 i;

	// Force unlock the weapons (if never held before)
	for (i = 0; i < ARRAYCOUNT(setup->weapons); i++) {
		s32 featurenum = g_MpWeapons[setup->weapons[i]].unlockfeature;

		if (featurenum) {
			index = challenge_force_unlock_feature(featurenum, array, index, len);
		}
	}

	// Force unlock the stage
	for (i = 0; i < mp_get_num_stages(); i++) {
		if (g_MpArenas[i].stagenum == setup->stagenum) {
			s32 featurenum = g_MpArenas[i].requirefeature;

			if (featurenum) {
				index = challenge_force_unlock_feature(featurenum, array, index, len);
			}
		}
	}

	// Force unlock the scenario
	if (setup->scenario <= MPSCENARIO_CAPTURETHECASE) {
		s32 featurenum = g_MpScenarioOverviews[setup->scenario].requirefeature;

		if (featurenum) {
			index = challenge_force_unlock_feature(featurenum, array, index, len);
		}
	}

	// Force unlock the scenario options
	if (setup->options & MPOPTION_ONEHITKILLS) {
		index = challenge_force_unlock_feature(MPFEATURE_ONEHITKILLS, array, index, len);
	}

	if (setup->options & (MPOPTION_SLOWMOTION_ON | MPOPTION_SLOWMOTION_SMART)) {
		index = challenge_force_unlock_feature(MPFEATURE_SLOWMOTION, array, index, len);
	}

	return index;
}

void challenge_force_unlock_config_features(struct mpconfig *config, u8 *array, s32 len, s32 challengeindex)
{
	s32 index = challenge_force_unlock_setup_features(&config->setup, array, len);
	s32 featurenum;
	s32 numplayers;
	s32 i;

	for (i = 0; i < MAX_BOTS; i++) {
		s32 simtype = mp_find_bot_profile(config->simulants[i].type, BOTDIFF_NORMAL);

		if (simtype >= 0) {
			featurenum = g_BotProfiles[simtype].requirefeature;

			if (featurenum) {
				index = challenge_force_unlock_feature(featurenum, array, index, len);
			}
		}

		for (numplayers = 0; numplayers < MAX_PLAYERS; numplayers++) {
			simtype = mp_find_bot_profile(0, config->simulants[i].difficulties[numplayers]);

			if (simtype >= 0) {
				featurenum = g_BotProfiles[simtype].requirefeature;

				if (featurenum) {
					index = challenge_force_unlock_feature(featurenum, array, index, len);
				}
			}
		}

		if (config->simulants[i].mpbodynum < ARRAYCOUNT(g_MpBodies)) {
			featurenum = g_MpBodies[config->simulants[i].mpbodynum].requirefeature;

			if (featurenum) {
				index = challenge_force_unlock_feature(featurenum, array, index, len);
			}
		}

		if (config->simulants[i].mpheadnum < ARRAYCOUNT(g_MpHeads)) {
			featurenum = g_MpHeads[config->simulants[i].mpheadnum].requirefeature;

			if (featurenum) {
				index = challenge_force_unlock_feature(featurenum, array, index, len);
			}
		}
	}

#if VERSION >= VERSION_NTSC_1_0
	if (challengeindex >= 25) {
		index = challenge_force_unlock_feature(MPFEATURE_BOTDIFF_DARK, array, index, len);
	} else if (challengeindex >= 20) {
		index = challenge_force_unlock_feature(MPFEATURE_STAGE_CARPARK, array, index, len);
	} else if (challengeindex >= 15) {
		index = challenge_force_unlock_feature(MPFEATURE_SCENARIO_PAC, array, index, len);
	}

	if (challengeindex >= 10) {
		index = challenge_force_unlock_feature(MPFEATURE_8BOTS, array, index, len);
	}
#else
	if (challengeindex >= 10) {
		index = challenge_force_unlock_feature(MPFEATURE_8BOTS, array, index, len);
	}

	if (challengeindex >= 15) {
		index = challenge_force_unlock_feature(MPFEATURE_SCENARIO_PAC, array, index, len);
	}

	if (challengeindex >= 20) {
		index = challenge_force_unlock_feature(MPFEATURE_STAGE_CARPARK, array, index, len);
	}
#endif

	// Clear the remainder of the array
	for (i = index; i < len; i++) {
		array[i] = 0;
	}
}

void challenge_force_unlock_bot_features(void)
{
	s32 numsims = 0;
	s32 index = challenge_force_unlock_setup_features(&g_MpSetup, g_MpFeaturesForceUnlocked, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_BotConfigsArray); i++) {
		// Force unlock the simulant type
		s32 simtypeindex = mp_find_bot_profile(g_BotConfigsArray[i].type, BOTDIFF_NORMAL);

		if (simtypeindex >= 0) {
			s32 featurenum = g_BotProfiles[simtypeindex].requirefeature;

			if (featurenum) {
				index = challenge_force_unlock_feature(featurenum, g_MpFeaturesForceUnlocked, index, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
			}
		}

		// Force unlock the simulant difficulty
		simtypeindex = mp_find_bot_profile(BOTTYPE_GENERAL, g_BotConfigsArray[i].difficulty);

		if (simtypeindex >= 0) {
			s32 featurenum = g_BotProfiles[simtypeindex].requirefeature;

			if (featurenum) {
				index = challenge_force_unlock_feature(featurenum, g_MpFeaturesForceUnlocked, index, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
			}
		}

		if (simtypeindex >= 0) {
			numsims++;
		}

		// Force unlock the simulant's body
		if (g_BotConfigsArray[i].base.mpbodynum < ARRAYCOUNT(g_MpBodies)) {
			s32 featurenum = g_MpBodies[g_BotConfigsArray[i].base.mpbodynum].requirefeature;

			if (featurenum) {
				index = challenge_force_unlock_feature(featurenum, g_MpFeaturesForceUnlocked, index, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
			}
		}

		// Force unlock the simulant's head
		if (g_BotConfigsArray[i].base.mpheadnum < ARRAYCOUNT(g_MpHeads)) {
			s32 featurenum = g_MpHeads[g_BotConfigsArray[i].base.mpheadnum].requirefeature;

			if (featurenum) {
				index = challenge_force_unlock_feature(featurenum, g_MpFeaturesForceUnlocked, index, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
			}
		}
	}

	// Force unlock 8 simulants
	if (numsims > 4) {
		index = challenge_force_unlock_feature(MPFEATURE_8BOTS, g_MpFeaturesForceUnlocked, index, ARRAYCOUNT(g_MpFeaturesForceUnlocked));
	}

	// Clear the remainder of the array
	for (i = index; i < ARRAYCOUNT(g_MpFeaturesForceUnlocked); i++) {
		g_MpFeaturesForceUnlocked[i] = 0;
	}

	challenge_determine_unlocked_features();
}

void challenge_remove_force_unlocks(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_MpFeaturesForceUnlocked); i++) {
		g_MpFeaturesForceUnlocked[i] = 0;
	}

	challenge_determine_unlocked_features();
}

void challenge_apply(void)
{
	s32 i;
	u8 buffer[0x1ca];

	mp_apply_config(challenge_load_current(buffer, 0x1ca));
	mp_set_lock(MPLOCKTYPE_CHALLENGE, 5);

	for (i = 0; i < MAX_PLAYERS; i++) {
		g_PlayerConfigsArray[i].base.team = 0;
	}
}

s32 challenge_remove_player_lock(void)
{
	return mp_set_lock(MPLOCKTYPE_NONE, 0);
}

void challenge_load_and_store_current(u8 *buffer, s32 len)
{
	g_MpCurrentChallengeConfig = challenge_load_current(buffer, len);
}

void challenge_unset_current(void)
{
	g_MpCurrentChallengeConfig = NULL;
}

bool challenge_is_loaded(void)
{
	return g_MpCurrentChallengeConfig != NULL;
}

char *challenge_get_current_description(void)
{
	if (g_MpCurrentChallengeConfig) {
		return g_MpCurrentChallengeConfig->strings.description;
	}

	return "";
}

char *challenge_get_config_description(struct mpconfigfull *mpconfig)
{
	if (mpconfig) {
		return mpconfig->strings.description;
	}

	return "";
}

/**
 * Return the index of the first incomplete challenge, but if it's in the first
 * 4 then return index 4 because the first 4 are always shown.
 */
s32 challenge_get_auto_focused_index(s32 mpchrnum)
{
	s32 challengeindex;
	s32 index = 0;

	for (challengeindex = ARRAYCOUNT(g_MpChallenges) - 1; challengeindex >= 0; challengeindex--) {
		if (challenge_is_completed_by_player_with_num_players(mpchrnum, challengeindex, 1) ||
				challenge_is_completed_by_player_with_num_players(mpchrnum, challengeindex, 2) ||
				challenge_is_completed_by_player_with_num_players(mpchrnum, challengeindex, 3) ||
				challenge_is_completed_by_player_with_num_players(mpchrnum, challengeindex, 4)) {
			index = challengeindex + 1;
			break;
		}
	}

	if (index < 4) {
		index = 4;
	}

	return index;
}

char *challenge_get_name2(s32 playernum, s32 challengeindex)
{
	return lang_get(g_MpChallenges[challengeindex].name);
}

bool challenge_is_completed_by_player_with_num_players2(s32 mpchrnum, s32 index, s32 numplayers)
{
	return challenge_is_completed_by_player_with_num_players(mpchrnum, index, numplayers);
}

bool challenge_is_completed_by_any_player_with_num_players(s32 index, s32 numplayers)
{
	return (g_MpChallenges[index].completions[numplayers - 1] & 1) != 0;
}

void challenge_set_completed_by_any_player_with_num_players(s32 index, s32 numplayers, bool completed)
{
	if (completed) {
		g_MpChallenges[index].completions[numplayers - 1] |= 1;
		return;
	}

	g_MpChallenges[index].completions[numplayers - 1] &= ~1;
}

bool challenge_is_completed_by_player_with_num_players(s32 mpchrnum, s32 index, s32 numplayers)
{
	return (g_MpChallenges[index].completions[numplayers - 1] & (2 << mpchrnum)) != 0;
}

void challenge_set_completed_by_player_with_num_players(u32 mpchrnum, s32 index, s32 numplayers, bool completed)
{
	if (completed) {
		g_MpChallenges[index].completions[numplayers - 1] |= 2 << mpchrnum;
		return;
	}

	g_MpChallenges[index].completions[numplayers - 1] &= ~(2 << mpchrnum);
}

bool challenge_is_complete_for_endscreen(void)
{
	s32 prevplayernum = g_Vars.currentplayernum;
	s32 result = false;
	s32 aborted = false;
	s32 i;
	u32 stack;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		set_current_player_num(i);

		if (g_Vars.currentplayer->aborted) {
			aborted = true;
		}
	}

	set_current_player_num(prevplayernum);

	if (!aborted) {
		struct ranking rankings[MAX_MPCHRS];
		mp_get_team_rankings(rankings);

		if (rankings[0].teamnum == 0) {
			result = true;
		}
	}

	return result;
}

void challenge_consider_marking_complete(void)
{
	bool result = challenge_is_complete_for_endscreen();

#if VERSION >= VERSION_NTSC_1_0 && defined(DEBUG)
	if ((g_CheatsActiveBank0 == 0 && g_CheatsActiveBank1 == 0) && (result || debug_is_set_complete_enabled()))
#elif VERSION >= VERSION_NTSC_1_0
	if (g_CheatsActiveBank0 == 0 && g_CheatsActiveBank1 == 0 && result)
#else
	if (result && g_CheatsActiveBank0 == 0 && g_CheatsActiveBank1 == 0)
#endif
	{
		u32 prevplayernum;
		s32 i;

		challenge_set_completed_by_any_player_with_num_players(g_MpChallengeIndex, PLAYERCOUNT(), 1);
		prevplayernum = g_Vars.currentplayernum;

		for (i = 0; i < PLAYERCOUNT(); i++) {
			set_current_player_num(i);
			challenge_set_completed_by_player_with_num_players(g_Vars.currentplayerstats->mpindex, g_MpChallengeIndex, PLAYERCOUNT(), true);
		}

		set_current_player_num(prevplayernum);
		challenge_determine_unlocked_features();
	}
}

bool challenge_is_feature_unlocked(s32 featurenum)
{
	if (featurenum == 0) {
		return true;
	}

	return (g_MpFeaturesUnlocked[featurenum] & 1) != 0;
}

bool challenge_is_feature_unlocked_by_player(u32 numplayers, s32 featurenum)
{
	if (featurenum == 0) {
		return true;
	}

	return (g_MpFeaturesUnlocked[featurenum] & (2 << numplayers)) != 0;
}

bool challenge_is_feature_unlocked_by_default(s32 featurenum)
{
	if (featurenum) {
		return false;
	}

	return true;
}
