#ifndef IN_GAME_TRAINING_TRAINING_H
#define IN_GAME_TRAINING_TRAINING_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

#define FRSCORE_INCOMPLETE 0
#define FRSCORE_BRONZE     1
#define FRSCORE_SILVER     2
#define FRSCORE_GOLD       3

extern u8 g_FrIsValidWeapon;
extern s32 g_FrWeaponNum;
extern u8 g_ChrBioSlot;
extern u8 g_HtSlot;
extern u8 g_HangarBioSlot;
extern u8 g_DtSlot;

bool ci_is_tour_done(void);
u8 fr_get_score(s32 weaponindex);
u8 fr_is_weapon_found(s32 weapon);
void fr_set_weapon_found(s32 weaponnum);
bool fr_is_weapon_available_for_mp(s32 weapon);
u32 fr_weaponnum_to_frweaponnum(u32 weaponnum);
s32 fr_is_classic_weapon_unlocked(u32 weapon);
s32 fr_get_slot(void);
void fr_set_slot(s32 slot);
u32 fr_get_weapon_by_slot(s32 slot);
s32 fr_get_num_weapons_available(void);
void fr_reset(void);
void fr_set_difficulty(s32 difficulty);
u32 fr_get_difficulty(void);
struct frdata *fr_get_data(void);
void fr_load_data(void);
u32 fr_init_ammo(s32 weapon);
void fr_begin_session(s32 weapon);
char *fr_get_weapon_description(void);
void fr_end_session(bool hidetargets);
bool fr_is_target_one_hit_explodable(struct prop *prop);
bool fr_is_target_facing_pos(struct prop *prop, struct coord *pos);
struct prop *fr_choose_autogun_target(struct coord *autogunpos);
void fr_tick(void);
void fr_track_target(struct prop *prop);
bool fr_choose_farsight_target(void);
s32 fr_is_in_training(void);
void fr_calculate_hit(struct defaultobj *obj, struct coord *hitpos, f32 maulercharge);
void fr_increment_num_shots(void);
struct chrbio *ci_get_chr_bio_by_bodynum(u32 bodynum);
char *ci_get_chr_bio_description(void);
s32 ci_get_num_unlocked_chr_bios(void);
s32 ci_get_chr_bio_bodynum_by_slot(s32 slot);
struct miscbio *ci_get_misc_bio(s32 index);
s32 ci_get_num_unlocked_misc_bios(void);
s32 ci_get_misc_bio_index_by_slot(s32 slot);
char *ci_get_misc_bio_description(void);
struct hangarbio *ci_get_hangar_bio(s32 index);
s32 ci_get_num_unlocked_location_bios(void);
s32 ci_get_num_unlocked_hangar_bios(void);
s32 ci_get_hangar_bio_index_by_slot(s32 slot);
char *ci_get_hangar_bio_description(void);
struct trainingdata *dt_get_data(void);
void dt_push_endscreen(void);
void dt_tick(void);
void dt_reset(void);
void dt_begin(void);
void dt_end(void);
s32 dt_get_num_available(void);
s32 dt_get_index_by_slot(s32 wantindex);
u32 dt_get_weapon_by_device_index(s32 deviceindex);
char *dt_get_description(void);
char *dt_get_tip1(void);
char *dt_get_tip2(void);
struct trainingdata *get_holo_training_data(void);
void ht_push_endscreen(void);
void ht_tick(void);
void ht_reset(void);
void ht_begin(void);
void ht_end(void);
s32 ht_get_num_unlocked(void);
s32 ht_get_index_by_slot(s32 slot);
char *ht_get_name(s32 index);
char *ht_get_description(void);
char *ht_get_tip1(void);
char *ht_get_tip2(void);

#if VERSION >= VERSION_JPN_FINAL
#else
#endif

Gfx *fr_render_hud(Gfx *gdl);

#endif
