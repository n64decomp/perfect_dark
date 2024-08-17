#ifndef IN_GAME_TRAINING_TRAINING_H
#define IN_GAME_TRAINING_TRAINING_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern u8 g_FrIsValidWeapon;
extern s32 g_FrWeaponNum;
extern u8 g_ChrBioSlot;
extern u8 var80088bb4;
extern u8 g_HangarBioSlot;
extern u8 g_DtSlot;

bool ci_is_tour_done(void);
u8 ci_get_firing_range_score(s32 weaponindex);
void fr_save_score_if_best(s32 weaponindex, s32 difficulty);
u8 fr_is_weapon_found(s32 weapon);
void fr_set_weapon_found(s32 weaponnum);
s32 ci_is_stage_complete(s32 stageindex);
bool func0f19cbcc(s32 weapon);
bool fr_is_weapon_available(s32 weapon);
u32 fr_get_weapon_index_by_weapon(u32 weaponnum);
u32 fr_get_weapon_script_index(u32 weaponnum);
s32 fr_is_classic_weapon_unlocked(u32 weapon);
s32 fr_get_slot(void);
void fr_set_slot(s32 slot);
u32 fr_get_weapon_by_slot(s32 slot);
s32 fr_get_num_weapons_available(void);
void fr_init_lighting(void);
void fr_restore_lighting(void);
void fr_reset(void);
void *fr_load_rom_data(u32 len);
void fr_set_difficulty(s32 difficulty);
u32 fr_get_difficulty(void);
void fr_init_defaults(void);
struct frdata *fr_get_data(void);
u32 fr_resolve_fr_pad(u32 arg0);
bool fr_is_difficulty(u32 difficulties);
void fr_execute_weapon_script(s32 scriptindex);
void fr_set_target_props(void);
bool fr_target_is_at_script_start(s32 targetnum);
char *fr_get_instructional_text(u32 index);
void fr_execute_help_script(void);
bool fr_execute_target_script(s32 targetnum);
void fr_hide_all_targets(void);
void fr_init_targets(void);
void fr_close_and_lock_door(void);
void fr_unlock_door(void);
void fr_load_data(void);
u32 fr_init_ammo(s32 weapon);
void fr_begin_session(s32 weapon);
char *fr_get_weapon_description(void);
void fr_end_session(bool hidetargets);
bool fr_was_too_inaccurate(void);
void fr_set_fail_reason(s32 failreason);
void fr_set_completed(void);
bool fr_is_target_one_hit_explodable(struct prop *prop);
f32 fr_get_target_angle_to_pos(struct coord *a, f32 angle, struct coord *b);
bool fr_is_target_facing_pos(struct prop *prop, struct coord *pos);
struct prop *fr_choose_autogun_target(struct coord *autogunpos);
bool fr_is_ammo_wasted(void);
void fr_tick(void);
void func0f1a0924(struct prop *prop);
bool fr_choose_farsight_target(void);
s32 fr_is_in_training(void);
void fr_calculate_hit(struct defaultobj *obj, struct coord *hitpos, f32 maulercharge);
void fr_increment_num_shots(void);
bool ci_is_chr_bio_unlocked(u32 bodynum);
struct chrbio *ci_get_chr_bio_by_bodynum(u32 bodynum);
char *ci_get_chr_bio_description(void);
s32 ci_get_num_unlocked_chr_bios(void);
s32 ci_get_chr_bio_bodynum_by_slot(s32 slot);
struct miscbio *ci_get_misc_bio(s32 index);
bool ci_is_misc_bio_unlocked(s32 index);
s32 ci_get_num_unlocked_misc_bios(void);
s32 ci_get_misc_bio_index_by_slot(s32 slot);
char *ci_get_misc_bio_description(void);
bool ci_is_hangar_bio_a_vehicle(s32 index);
struct hangarbio *ci_get_hangar_bio(s32 index);
bool ci_is_hangar_bio_unlocked(u32 bioindex);
s32 ci_get_num_unlocked_location_bios(void);
s32 ci_get_num_unlocked_hangar_bios(void);
s32 ci_get_hangar_bio_index_by_slot(s32 slot);
char *ci_get_hangar_bio_description(void);
struct trainingdata *dt_get_data(void);
void dt_restore_player(void);
void dt_push_endscreen(void);
void dt_tick(void);
void func0f1a1ac0(void);
void dt_begin(void);
void dt_end(void);
bool dt_is_available(s32 deviceindex);
s32 dt_get_num_available(void);
s32 dt_get_index_by_slot(s32 wantindex);
u32 dt_get_weapon_by_device_index(s32 deviceindex);
u32 ci_get_stage_flag_by_device_index(u32 deviceindex);
char *dt_get_description(void);
char *dt_get_tip1(void);
char *dt_get_tip2(void);
struct trainingdata *get_holo_training_data(void);
void ht_push_endscreen(void);
void ht_tick(void);
void func0f1a2198(void);
void ht_begin(void);
void ht_end(void);
bool ht_is_unlocked(u32 value);
s32 ht_get_num_unlocked(void);
s32 ht_get_index_by_slot(s32 slot);
char *ht_get_name(s32 index);
u32 func0f1a25c0(s32 index);
char *ht_get_description(void);
char *ht_get_tip1(void);
char *ht_get_tip2(void);

#if VERSION >= VERSION_JPN_FINAL
void fr_get_goal_targets_text(char *buffer1, char *buffer2);
void fr_get_goal_score_text(char *buffer1, char *buffer2);
bool fr_get_min_accuracy(char *buffer1, f32 accuracy, char *buffer2);
bool fr_get_hud_middle_subtext(char *buffer1, char *buffer2);
bool fr_get_feedback(char *score, char *zone, char *extrabuffer);
Gfx *fr_render_hud_element(Gfx *gdl, s32 x, s32 y, char *string1, char *string2, char *string3, u32 colour, u8 alpha);
#else
void fr_get_goal_targets_text(char *buffer);
void fr_get_goal_score_text(char *buffer);
bool fr_get_min_accuracy(char *buffer, f32 accuracy);
bool fr_get_hud_middle_subtext(char *buffer);
bool fr_get_feedback(char *score, char *zone);
Gfx *fr_render_hud_element(Gfx *gdl, s32 x, s32 y, char *string1, char *string2, u32 colour, u8 alpha);
#endif

void fr_get_targets_destroyed_value(char *buffer);
void fr_get_score_value(char *buffer);
f32 fr_get_accuracy(char *buffer);
bool fr_format_time(char *buffer);
Gfx *fr_render_hud(Gfx *gdl);

#endif
