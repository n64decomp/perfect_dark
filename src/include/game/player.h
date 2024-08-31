#ifndef _IN_GAME_PLAYER_H
#define _IN_GAME_PLAYER_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

f32 player_choose_spawn_location(f32 chrradius, struct coord *dstpos, RoomNum *dstrooms, struct prop *prop, s16 *spawnpads, s32 numspawnpads);
f32 player_choose_general_spawn_location(f32 chrradius, struct coord *pos, RoomNum *rooms, struct prop *prop);
void player_start_new_life(void);
void player_load_defaults(void);
void player_spawn(void);
void player_reset_bond(struct playerbond *pb, struct coord *pos);
void player_choose_body_and_head(s32 *bodynum, s32 *headnum, s32 *arg2);
void player_remove_chr_body(void);
void player_start_cutscene(s16 anim_id);
void player_reorient_for_cutscene_stop(s32 tweenduration60);
f32 player_get_cutscene_blur_frac(void);
void player_tween_fov_y(f32 targetfovy);
void player_update_zoom(void);
void player_tick_pause_menu(void);
void player_pause(s32 root);
void player_unpause(void);
Gfx *player_draw_fade(Gfx *gdl, u32 r, u32 g, u32 b, f32 frac);
void player_display_health(void);
void player_display_damage(void);
Gfx *player_render_health_bar(Gfx *gdl);
void player_surround_with_explosions(s32 arg0);
void player_reset_lo_res_if_4mb(void);
s16 player_get_fb_width(void);
s16 player_get_fb_height(void);
bool player_has_shared_viewport(void);
f32 player_get_aspect_ratio(void);
void player_configure_vi(void);
void player_tick(bool arg0);
Gfx *player_update_shoot_rot(Gfx *gdl);
void player_display_shield(void);
Gfx *player_render_hud(Gfx *gdl);
void player_die(bool force);
void player_die_by_shooter(u32 shooter, bool force);
void player_check_if_shot_in_back(s32 attackerplayernum, f32 x, f32 z);
f32 player_get_health_bar_height_frac(void);
void player_set_perim_enabled(struct prop *prop, bool enable);
bool player_get_geometry(struct prop *prop, u8 **start, u8 **end);
void player_update_perim_info(void);
void player_get_bbox(struct prop *prop, f32 *radius, f32 *ymax, f32 *ymin);
f32 player_get_health_frac(void);
f32 player_get_shield_frac(void);
void player_set_shield_frac(f32 frac);
s32 player_get_mission_time(void);
s32 player_tick_beams(struct prop *prop);
s32 player_tick_third_person(struct prop *prop);
void player_choose_third_person_animation(struct chrdata *chr, s32 crouchpos, f32 speedsideways, f32 speedforwards, f32 speedtheta, f32 *angleoffset, struct attackanimconfig **animcfg);
Gfx *player_render(struct prop *prop, Gfx *gdl, bool xlupass);
Gfx *player_load_matrix(Gfx *gdl);
void player0f0c3320(Mtxf *matrices, s32 count);
void player_set_tick_mode(s32 tickmode);
void players_begin_mp_swirl(void);
void player0f0b9a20(void);
void player_end_cutscene(void);
void player_prepare_move_camera_to_pad(s16 pad_id);
void player_prepare_move_camera_to_preset(struct camerapresetobj *preset, bool hasdir, s32 arg2);
void player_prepare_move_camera_to_pos(f32 posangle, f32 rotangle, f32 range, f32 height1, f32 height2, s32 padnum);
void player_set_fade_colour(s32 r, s32 g, s32 b, f32 a);
void player_set_fade_frac(f32 maxfadetime, f32 frac);
void player_set_hi_res_enabled(bool enable);
void player_auto_walk(s16 aimpad, u8 walkspeed, u8 turnspeed, u8 lookup, u8 dist);
void player_launch_slayer_rocket(struct weaponobj *rocket);
bool player_is_health_visible(void);
void player_set_cam_properties_in_bounds(struct coord *pos, struct coord *up, struct coord *look, s32 room);

#endif
