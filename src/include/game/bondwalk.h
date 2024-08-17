#ifndef IN_GAME_BONDWALK_H
#define IN_GAME_BONDWALK_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bwalk_init(void);
void bwalk_set_sway_target(s32 value);
void bwalk_adjust_crouch_pos(s32 value);
void bwalk0f0c3b38(struct coord *param_1, struct defaultobj *obj);
s32 bwalk_try_move_upwards(f32 amount);
bool bwalk_calculate_new_position(struct coord *vel, f32 rotateamount, bool apply, f32 extrawidth, s32 arg4);
bool bwalk_calculate_new_position_with_push(struct coord *delta, f32 rotateamount, bool apply, f32 extrawidth, s32 types);
s32 bwalk0f0c4764(struct coord *delta, struct coord *arg1, struct coord *arg2, s32 types);
s32 bwalk0f0c47d0(struct coord *a, struct coord *b, struct coord *c, struct coord *d, struct coord *e, s32 types);
s32 bwalk0f0c494c(struct coord *a, struct coord *b, struct coord *c, s32 types);
s32 bwalk0f0c4a5c(struct coord *a, struct coord *b, struct coord *c, s32 types);
void bwalk0f0c4d98(void);
void bwalk_update_speed_sideways(f32 targetspeed, f32 accelspeed, s32 mult);
void bwalk_update_speed_forwards(f32 targetspeed, f32 accelspeed);
void bwalk_update_vertical(void);
void bwalk_apply_crouch_speed(void);
void bwalk_update_crouch_offset_real(void);
void bwalk_update_crouch_offset(void);
void bwalk_update_theta(void);
void bwalk0f0c63bc(struct coord *arg0, u32 arg1, s32 types);
void bwalk_update_prev_pos(void);
void bwalk_handle_activate(void);
void bwalk_apply_move_data(struct movedata *data);
void bwalk_update_speed_theta(void);
void bwalk0f0c69b8(void);
void bwalk_tick(void);

#endif
