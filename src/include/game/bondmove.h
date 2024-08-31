#ifndef IN_GAME_BONDMOVE_H
#define IN_GAME_BONDMOVE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bmove_set_automovecentre_enabled(bool enabled);
void bmove_set_autoaim_y(bool enabled);
bool bmove_is_autoaim_y_enabled_for_current_weapon(void);
bool bmove_is_in_sight_aim_mode(void);
void bmove_update_autoaim_y_prop(struct prop *prop, f32 autoaimy);
void bmove_set_autoaim_x(bool enabled);
bool bmove_is_autoaim_x_enabled_for_current_weapon(void);
void bmove_update_autoaim_x_prop(struct prop *prop, f32 autoaimx);
struct prop *bmove_get_hoverbike(void);
struct prop *bmove_get_grabbed_prop(void);
void bmove_grab_prop(struct prop *prop);
void bmove_set_mode(u32 movemode);
void bmove_set_mode_for_all_players(u32 movemode);
void bmove_find_entered_rooms_by_pos(struct player *player, struct coord *arg1, RoomNum *rooms);
void bmove_update_rooms(struct player *player);
void bmove_dampen_shotspeed(struct coord *shotspeed);
void bmove_shotspeed_to_lateral(f32 *forward, f32 *sideways, struct coord *shotspeed, f32 sintheta, f32 costheta);
void bmove_update_move_init_speed(struct coord *newpos);
void bmove_tick(bool allowc1x, bool allowc1y, bool allowc1buttons, bool ignorec2);
void bmove_update_verta(void);
void bmove_set_pos(struct coord *pos);
void bmove_update_head_with_mtx(f32 heartrate, f32 speedforwards, f32 speedsideways, Mtxf *mtx, f32 arg4);
void bmove_update_head(f32 heartrate, f32 speedforwards, f32 speedsideways);
s32 bmove_get_crouch_pos(void);
s32 bmove_get_crouch_pos_by_player(s32 playernum);

#endif
