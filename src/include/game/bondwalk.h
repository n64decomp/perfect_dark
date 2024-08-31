#ifndef IN_GAME_BONDWALK_H
#define IN_GAME_BONDWALK_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bwalk_init(void);
void bwalk_adjust_crouch_pos(s32 value);
s32 bwalk_try_move_upwards(f32 amount);
void bwalk0f0c63bc(struct coord *arg0, u32 arg1, s32 types);
void bwalk_handle_activate(void);
void bwalk_apply_move_data(struct movedata *data);
void bwalk_update_speed_theta(void);
void bwalk_tick(void);

#endif
