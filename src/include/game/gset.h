#ifndef IN_GAME_GSET_H
#define IN_GAME_GSET_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

struct weapondef *gset_get_weapondef(s32 itemid);
struct funcdef *gset_get_funcdef_by_weaponnum_funcnum(u32 weaponnum, u32 which);
struct funcdef *gset_get_funcdef_by_gset2(struct gset *gset);
struct funcdef *gset_get_funcdef_by_gset(struct gset *gset);
struct funcdef *gset_get_funcdef_by_gset_funcnum(struct gset *gset, s32 which);
struct funcdef *gset_get_current_funcdef(u32 hand);
struct invaimsettings *gset_get_aim_settings(struct gset *gset);
struct ammodef *gset_get_ammodef(u32 weaponnum, u32 funcnum);
f32 gset_get_xshift(s32 handnum);
f32 gset_get_xpos(s32 handnum);
f32 gset_get_gun_zoom_fov(void);
void gset_zoom_out(f32 fovpersec);
void gset_zoom_in(f32 fovpersec);
bool gset_has_weapon_flag(s32 itemid, u32 flag);
bool gset_has_aim_flag(s32 weaponnum, u32 flag);
bool gset_has_ammo_flag(s32 weaponnum, s32 funcnum, u32 flag);
s32 gset_get_device_state(s32 weaponnum);
void gset_set_device_active(s32 weaponum, bool active);
u16 gset_get_filenum(s32 weaponnum);
u16 gset_get_filenum2(s32 weaponnum);
void gset_populate(s32 handnum, struct gset *gset);
u8 gset_get_single_penetration(struct gset *gset);
f32 gset_get_impact_force(struct gset *gset);
f32 gset_get_damage(struct gset *gset);
u8 gset_get_fireslot_duration(struct gset *gset);
u16 gset_get_single_shoot_sound(struct gset *gset);
bool gset_has_function_flags(struct gset *gset, u32 flags);
s8 weapon_get_num_ticks_per_shot(u32 weaponnum, u32 funcindex);
u32 gset_get_sight(void);
void gset_get_noise_settings(struct gset *gset, struct noisesettings *settings);
struct guncmd *gset_get_pritosec_anim(struct gset *gset);
struct guncmd *gset_get_sectopri_anim(struct gset *gset);

#endif
