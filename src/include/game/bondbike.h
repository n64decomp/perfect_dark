#ifndef IN_GAME_BONDBIKE_H
#define IN_GAME_BONDBIKE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bbike_init(void);
void bbike_exit(void);
void bbike_update_vehicle_offset(void);
void bbike_try_dismount_angle(f32 relativeangle, f32 distance);
void bbike_handle_activate(void);
void bbike_apply_move_data(struct movedata *data);
void bbike0f0d2b40(struct defaultobj *bike, struct coord *arg1, f32 arg2, struct defaultobj *obstacle);
s32 bbike_calculate_new_position(struct coord *arg0, f32 arg1);
s32 bbike_calculate_new_position_with_push(struct coord *arg0, f32 arg1);
void bbike_update_vertical(struct coord *pos);
s32 bbike0f0d3680(struct coord *arg0, struct coord *arg1, struct coord *arg2);
s32 bbike0f0d36d4(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct coord *arg3, struct coord *arg4);
s32 bbike0f0d3840(struct coord *arg0, struct coord *arg1, struct coord *arg2);
s32 bbike0f0d3940(struct coord *arg0, struct coord *arg1, struct coord *arg2);
void bbike0f0d3c60(struct coord *arg0);
void bbike_tick(void);

#endif
