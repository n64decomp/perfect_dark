#ifndef _IN_GAME_BONDGUN_H
#define _IN_GAME_BONDGUN_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bgun_reset(void);

void bgun_stop(void);

bool bgun_test_gun_vis_command(struct gunviscmd *cmd, struct hand *hand);
void bgun_execute_gun_vis_commands(struct hand *hand, struct modeldef *arg1, struct gunviscmd *command);
s32 bgun_get_min_clip_qty(s32 weaponnum, s32 funcnum);
void bgun_init_hand_anims(void);
f32 bgun_get_noise_radius(s32 handnum);
void bgun_calculate_blend(s32 hand);
void bgun0f09d8dc(f32 breathing, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
u8 *bgun_get_gun_mem(void);
u32 bgun_calculate_gun_mem_capacity(void);
void bgun_free_gun_mem(void);
bool bgun_change_gun_mem(s32 newowner);
bool bgun_load_all(void);
struct modeldef *bgun_get_cart_modeldef(void);
void bgun0f09ebcc(struct defaultobj *obj, struct coord *coord, RoomNum *rooms, Mtxf *matrix1, struct coord *velocity, Mtxf *matrix2, struct prop *prop, struct coord *pos);
struct defaultobj *bgun_create_thrown_projectile2(struct chrdata *chr, struct gset *gset, struct coord *pos, RoomNum *rooms, Mtxf *arg4, struct coord *velocity);
void bgun_create_thrown_projectile(s32 handnum, struct gset *gset);
void bgun_create_fired_projectile(s32 handnum);
void bgun_swivel(f32 autoaimx, f32 autoaimy, f32 crossdamp, f32 aimdamp);
void bgun_swivel_with_damp(f32 screenx, f32 screeny, f32 damp);
void bgun_swivel_without_damp(f32 arg0, f32 arg1);
void bgun_get_cross_pos(f32 *x, f32 *y);
void bgun0f0a0c08(struct coord *arg0, struct coord *arg1);
void bgun_calculate_player_shot_spread(struct coord *arg0, struct coord *arg1, s32 handnum, bool dorandom);
void bgun_calculate_bot_shot_spread(struct coord *arg0, s32 weaponnum, s32 funcnum, bool arg3, s32 crouchpos, bool dual);
void bgun_set_last_shoot_info(struct coord *pos, struct coord *dir, s32 handnum);
s32 bgun_get_shots_to_take(s32 handnum);
void bgun_equip_weapon(s32 weaponnum);
s32 bgun_get_weapon_num(s32 handnum);
bool bgun0f0a1a10(s32 weaponnum);
void bgun_cycle_forward(void);
void bgun_cycle_back(void);
bool bgun_has_ammo_for_weapon(s32 weaponnum);
void bgun_equip_weapon2(s32 handnum, s32 weaponnum);
s32 bgun_is_firing(s32 handnum);
s32 bgun_get_attack_type(s32 handnum);
char *bgun_get_name(s32 weaponnum);
u16 bgun_get_name_id(s32 weaponnum);
char *bgun_get_short_name(s32 arg0);
void bgun_reload_if_possible(s32 handnum);
void bgun_set_adjust_pos(f32 angle);
bool bgun_allows_fullscreen_autoaim(void);
void bgun_handle_player_dead(void);
bool bgun_is_mission_critical(s32 weaponnum);
void bgun_disarm(struct prop *attacker);
void bgun_start_detonate_animation(s32 playernum);
void bgun_tick_gameplay2(void);
s32 bgun_allocate_fireslot(void);
void bgun_render(Gfx **gdl);
void bgun_play_prop_hit_sound(struct gset *gset, struct prop *prop, s32 texturenum);
void bgun_play_glass_hit_sound(struct coord *pos, RoomNum *rooms, s32 texturenum);
void bgun_play_bg_hit_sound(struct gset *gset, struct coord *hitpos, s32 texturenum, RoomNum *rooms);
s32 bgun_consider_toggle_gun_function(s32 usedowntime, bool trigpressed, bool fromactivemenu);
void bgun0f0a8c50(void);
void bgun_tick_gameplay(bool triggeron);
void bgun_set_passive_mode(bool enable);
void bgun_set_aim_type(u32 aimtype);
void bgun_set_hit_pos(struct coord *coord);
void bgun0f0a9494(u32 operation);
void bgun0f0a94d0(u32 operation, struct coord *pos, struct coord *rot);
void bgun_set_gun_ammo_visible(u32 reason, bool enable);
void bgun_set_ammo_quantity(s32 ammotype, s32 quantity);
s32 bgun_get_reserved_ammo_count(s32 type);
s32 bgun_get_ammo_count(s32 ammotype);
s32 bgun_get_capacity_by_ammotype(s32 ammotype);
void bgun_give_max_ammo(bool force);
u32 bgun_get_ammo_type_for_weapon(u32 weaponnum, u32 func);
s32 bgun_get_ammo_qty_for_weapon(u32 weaponnum, u32 func);
void bgun_set_ammo_qty_for_weapon(u32 weaponnum, u32 func, u32 quantity);
s32 bgun_get_ammo_capacity_for_weapon(s32 weaponnum, s32 func);
Gfx *bgun_draw_hud_string(Gfx *gdl, char *text, s32 x, bool halign, s32 y, s32 valign, u32 colour);
Gfx *bgun_draw_hud_integer(Gfx *gdl, s32 value, s32 x, bool halign, s32 y, s32 valign, u32 colour);
Gfx *bgun_draw_hud(Gfx *gdl);
void bgun_apply_boost(void);
void bgun_revert_boost(void);
void bgun_tick_boost(void);
void bgun_set_sight_visible(u32 bits, bool visible);
Gfx *bgun_draw_sight(Gfx *gdl);
s32 bgun_get_weapon_num2(s32 handnum);
s8 bgun_free_fireslot_wrapper(s32 fireslot);
s8 bgun_free_fireslot(s32 fireslot);

#endif
