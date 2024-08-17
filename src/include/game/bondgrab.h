#ifndef IN_GAME_BONDGRAB_H
#define IN_GAME_BONDGRAB_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bgrab_init(void);
void bgrab_exit(void);
void bgrab0f0ccbf0(struct coord *delta, f32 angle, struct defaultobj *obj);
bool bgrab_try_move_upwards(f32 y);
s32 bgrab_calculate_new_position(struct coord *delta, f32 angle, bool arg2);
bool bgrab_calculate_new_positiont_with_push(struct coord *delta, f32 angle, bool arg2);
bool bgrab0f0cdb04(f32 angle, bool arg2);
bool bgrab0f0cdb68(f32 angle);
void bgrab0f0cdef0(void);
bool bgrab0f0cdf64(struct coord *delta, struct coord *arg1, struct coord *arg2);
s32 bgrab0f0cdfbc(struct coord *delta, struct coord *arg1, struct coord *arg2);
void bgrab0f0ce0bc(struct coord *arg0);
void bgrab_update_prev_pos(void);
void bgrab0f0ce178(void);
void bgrab_update_vertical(void);
void bgrab_handle_activate(void);
void bgrab_update_speed_sideways(f32 targetspeed, f32 accelspeed, s32 mult);
void bgrab_update_speed_forwards(f32 target, f32 speed);
void bgrab_apply_move_data(struct movedata *data);
void bgrab_update_speed_theta(void);
void bgrab0f0ce924(void);
void bgrab_tick(void);

#endif
