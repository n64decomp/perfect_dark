#ifndef _IN_GAME_PLAYERMGR_H
#define _IN_GAME_PLAYERMGR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void playermgr_init(void);
void playermgr_reset(void);
void playermgr_allocate_players(s32 count);
void playermgr_allocate_player(s32 index);
void playermgr_calculate_ai_buddy_nums(void);
void set_current_player_num(s32 playernum);
s32 playermgr_get_player_num_by_prop(struct prop *prop);
void playermgr_set_view_size(s32 viewx, s32 viewy);
void playermgr_set_view_position(s32 viewleft, s32 viewtop);
void playermgr_set_fov_y(f32 fovy);
void playermgr_set_aspect_ratio(f32 aspect);
s32 playermgr_get_model_of_weapon(s32 weapon);
void playermgr_delete_weapon(s32 hand);
void playermgr_create_weapon(s32 hand);
void playermgr_shuffle(void);
s32 playermgr_get_order_of_player(s32 playernum);
s32 playermgr_get_player_at_order(s32 ordernum);

#endif
