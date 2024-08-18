#ifndef IN_GAME_GAME_0B0FD0_H
#define IN_GAME_GAME_0B0FD0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

struct weapon *weapon_find_by_id(s32 itemid);
struct weaponfunc *weapon_get_function_by_id(u32 weaponnum, u32 which);
struct weaponfunc *gset_get_weapon_function2(struct gset *gset);
struct weaponfunc *gset_get_weapon_function(struct gset *gset);
struct weaponfunc *weapon_get_function(struct gset *gset, s32 which);
struct weaponfunc *current_player_get_weapon_function(u32 hand);
struct invaimsettings *gset_get_aim_settings(struct gset *gset);
struct inventory_ammo *weapon_get_ammo_by_function(u32 weaponnum, u32 funcnum);
f32 hand_get_xshift(s32 handnum);
f32 hand_get_xpos(s32 handnum);
f32 current_player_get_gun_zoom_fov(void);
void current_player_zoom_out(f32 fovpersec);
void current_player_zoom_in(f32 fovpersec);
bool weapon_has_flag(s32 itemid, u32 flag);
bool weapon_has_aim_flag(s32 weaponnum, u32 flag);
bool weapon_has_ammo_flag(s32 weaponnum, s32 funcnum, u32 flag);
s32 current_player_get_device_state(s32 weaponnum);
void current_player_set_device_active(s32 weaponum, bool active);
u16 weapon_get_file_num(s32 weaponnum);
u16 weapon_get_file_num2(s32 weaponnum);
void gset_populate_from_current_player(s32 handnum, struct gset *gset);
struct inventory_ammo *gset_get_ammo_definition(struct gset *gset);
u8 gset_get_single_penetration(struct gset *gset);
f32 gset_get_impact_force(struct gset *gset);
f32 gset_get_damage(struct gset *gset);
u8 gset_get_fireslot_duration(struct gset *gset);
u16 gset_get_single_shoot_sound(struct gset *gset);
bool gset_has_function_flags(struct gset *gset, u32 flags);
s8 weapon_get_num_ticks_per_shot(u32 weaponnum, u32 funcindex);
u32 current_player_get_sight(void);
void gset_get_noise_settings(struct gset *gset, struct noisesettings *settings);
struct guncmd *gset_get_pri_to_sec_anim(struct gset *gset);
struct guncmd *gset_get_sec_to_pri_anim(struct gset *gset);

#endif
