#ifndef IN_GAME_BONDEYESPY_H
#define IN_GAME_BONDEYESPY_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

f32 eyespy_find_ground(RoomNum *floorroom);
s32 eyespy_try_move_upwards(f32 yvel);
s32 eyespy_calculate_new_position(struct coord *vel);
bool eyespy_calculate_new_position_with_push(struct coord *vel);
void eyespy_update_position(void);
bool eyespy_try_launch(void);
void eyespy_process_input(bool allowbuttons);

#endif
