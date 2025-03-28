#ifndef IN_GAME_MPLAYER_MPLAYER_H
#define IN_GAME_MPLAYER_MPLAYER_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

f32 mp_handicap_to_value(u8 handicap);
void mp_start_match(void);
void mp_reset(void);
void mp_calculate_team_is_only_ai(void);
void mp_init_handicaps(s32 playernum);
void mp_init_limits(void);
void mp_player_set_defaults(s32 playernum, bool autonames);
void mp_init(void);
void mp_get_teams_with_default_name(u8 *mask);
void mp_set_team_names_to_default(u8 mask);
void mp_set_default_names_if_empty(void);
s32 mp_calculate_team_score_limit(void);
void mp_apply_limits(void);
s32 mp_get_player_rankings(struct ranking *rankings);
s32 mp_get_team_rankings(struct ranking *rankings);
s32 mp_get_num_mpweapons(void);
s32 mp_get_num_weapon_options(void);
char *mp_get_weapon_label(s32 weaponnum);
void mp_set_weapon_slot(s32 slot, s32 mpweaponnum);
s32 mp_get_weapon_slot(s32 slot);
struct mpweapon *mp_get_mp_weapon_by_location(s32 locationindex);
s32 mp_get_num_weaponset_slots(bool full);
s32 mp_get_custom_weaponset_slot(void);
char *mp_get_weaponset_name_by_slotnum(s32 arg0);
void mp_set_weaponset_slotnum(s32 weaponsetnum);
void mp_apply_weaponset_if_standard(void);
s32 mp_get_weaponset_slotnum(void);
bool mp_is_paused(void);
void mp_set_paused(u8 mode);
Gfx *mp_render_modal_text(Gfx *gdl);
void mp_end_match(void);
s32 mp_get_num_heads2(void);
s32 mp_get_num_heads(void);
s32 mp_get_head_id(u8 headnum);
s32 mp_get_head_required_feature(u8 headnum);
s32 mp_get_beau_head_id(u8 headnum);
u32 mp_get_num_bodies(void);
s32 mp_get_body_id(u8 bodynum);
s32 mp_get_mpbodynum_by_bodynum(u16 bodynum);
char *mp_get_body_name(u8 mpbodynum);
u8 mp_get_body_required_feature(u8 bodynum);
s32 mp_get_mpheadnum_by_mpbodynum(s32 bodynum);
bool mp_set_lock(s32 locktype, s32 playernum);
s32 mp_get_lock_type(void);
u32 mp_get_lock_player_num(void);
bool mp_is_player_locked_out(s32 playernum);
void mp_calculate_lock_if_last_winner_or_loser(void);
s32 mp_get_num_unlocked_tracks(void);
s32 mp_get_track_music_num(s32 slotindex);
char *mp_get_track_name(s32 slotindex);
void mp_set_using_multiple_tunes(bool enable);
bool mp_get_using_multiple_tunes(void);
bool mp_is_multi_track_slot_enabled(s32 slot);
void mp_set_track_slot_enabled(s32 slot);
void mp_enable_all_multi_tracks(void);
void mp_disable_all_multi_tracks(void);
void mp_randomise_multi_tracks(void);
void mp_set_track_to_random(void);
s32 mp_get_current_track_slot_num(void);
s32 mp_choose_track(void);
struct mpchrconfig *mp_get_chr_config_by_slot_num(s32 slot);
s32 mp_get_num_chrs(void);
void mp_create_bot_from_profile(s32 botnum, u8 difficulty);
void mp_set_bot_difficulty(s32 botnum, s32 difficulty);
s32 mp_get_slot_for_new_bot(void);
void mp_remove_simulant(s32 index);
bool mp_has_simulants(void);
bool mp_has_unused_bot_slots(void);
bool mp_is_sim_slot_enabled(s32 slot);
s32 mp_find_bot_profile(s32 type, s32 difficulty);
void mp_generate_bot_names(void);
s32 mp_chr_to_chrindex(struct chrdata *chr);
struct chrdata *mp_chrindex_to_chr(s32 index);
s32 mp_chrindex_to_chrslot(s32 index);
s32 mp_chrslot_to_chrindex(s32 arg0);
void mpplayerfile_get_overview(char *arg0, char *name, u32 *playtime);
s32 mpplayerfile_save(s32 playernum, s32 device, s32 fileid, u16 deviceserial);
s32 mpplayerfile_load(s32 playernum, s32 device, s32 arg2, u16 deviceserial);
s32 mp_get_num_presets(void);
s32 mp_get_num_unlocked_presets(void);
char *mp_get_preset_name_by_slot(s32 slot);
void mp_apply_config(struct mpconfigfull *mpconfig);
void mp_load_preset_by_slotnum(s32 arg0);
void mpsetupfile_get_overview(char *arg0, char *filename, u16 *numsims, u16 *stagenum, u16 *scenarionum);
s32 mpsetupfile_save(s32 device, s32 filenum, u16 deviceserial);
s32 mpsetupfile_load(s32 device, s32 filenum, u16 deviceserial);
void mp_reset_phead_modeldefs(void);
struct modeldef *mp_get_phead_modeldef(s32 index, s32 *headnum);

#endif
