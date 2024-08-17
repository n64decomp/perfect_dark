#ifndef _IN_GAME_CHALLENGE_H
#define _IN_GAME_CHALLENGE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern u32 g_MpChallengeIndex;
extern struct mpconfigfull *g_MpCurrentChallengeConfig;

void challenges_init(void);

void challenge_determine_unlocked_features(void);
void challenge_perform_sanity_checks(void);
char *challenge_get_name_by_slot(s32 slot);
bool challenge_is_completed_by_any_chr_with_num_players_by_slot(s32 slot, s32 numplayers);
struct mpconfigfull *challenge_load_config(s32 confignum, u8 *buffer, s32 len);
s32 challenge_force_unlock_feature(s32 featurenum, u8 *array, s32 tail, s32 len);
s32 challenge_force_unlock_setup_features(struct mpsetup *mpsetup, u8 *array, s32 len);
void challenge_force_unlock_config_features(struct mpconfig *config, u8 *array, s32 len, s32 challengeindex);
void challenge_force_unlock_bot_features(void);
void challenge_apply(void);
char *challenge_get_current_description(void);
char *challenge_get_config_description(struct mpconfigfull *mpconfig);
bool challenge_is_complete_for_endscreen(void);
bool ai_mp_init_simulants(void);
void vm_print_stats_if_enabled(void);
bool challenge_is_available_to_player(s32 chrnum, s32 challengeindex);
bool challenge_is_available_to_any_player(s32 challengeindex);
s32 challenge_get_num_available(void);
char *challenge_get_name(s32 challengeindex);
void challenge_set_current_by_slot(s32 slotnum);
s32 challenge_get_current(void);
struct mpconfigfull *challenge_load(s32 challengeindex, u8 *buffer, s32 len);
struct mpconfigfull *challenge_load_by_slot(s32 n, u8 *buffer, s32 len);
struct mpconfigfull *challenge_load_current(u8 *buffer, s32 len);
void challenge_remove_force_unlocks(void);
s32 challenge_remove_player_lock(void);
void challenge_load_and_store_current(u8 *buffer, s32 len);
void challenge_unset_current(void);
bool challenge_is_loaded(void);
s32 challenge_get_auto_focused_index(s32 mpchrnum);
char *challenge_get_name2(s32 playernum, s32 challengeindex);
bool challenge_is_completed_by_player_with_num_players2(s32 mpchrnum, s32 index, s32 numplayers);
bool challenge_is_completed_by_any_player_with_num_players(s32 index, s32 numplayers);
void challenge_set_completed_by_any_player_with_num_players(s32 index, s32 numplayers, bool completed);
bool challenge_is_completed_by_player_with_num_players(s32 mpchrnum, s32 index, s32 numplayers);
void challenge_set_completed_by_player_with_num_players(u32 mpchrnum, s32 index, s32 numplayers, bool completed);
void challenge_consider_marking_complete(void);
bool challenge_is_feature_unlocked(s32 feature);

#endif
