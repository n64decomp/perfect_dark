#ifndef IN_GAME_BONDEYESPY_H
#define IN_GAME_BONDEYESPY_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

f32 eyespy_find_ground(RoomNum *floorroom);
s32 eyespy_try_move_upwards(f32 yvel);
s32 eyespy_calculate_new_position(struct coord *vel);
bool eyespy_calculate_new_position_with_push(struct coord *vel);
s32 eyespy0f0cf890(struct coord *arg0, struct coord *arg1, struct coord *arg2, struct coord *arg3, struct coord *arg4);
s32 eyespy0f0cf9f8(struct coord *arg0, struct coord *arg1, struct coord *arg2);
s32 eyespy0f0cfafc(struct coord *arg0, struct coord *arg1, struct coord *arg2);
s32 eyespy0f0cfdd0(struct coord *vel, struct coord *arg1, struct coord *arg2);
void eyespy_update_vertical(void);
bool eyespy_try_launch(void);
void eyespy_process_input(bool allowbuttons);

#endif
