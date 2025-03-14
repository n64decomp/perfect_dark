#ifndef IN_GAME_BONDWALK_H
#define IN_GAME_BONDWALK_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bwalk_init(void);
void bwalk_adjust_crouch_pos(s32 value);
s32 bwalk_try_move_upwards(f32 amount);
void bwalk_resolve_posdelta(struct coord *deltapos, bool notrleaning, s32 cdtypes);
void bwalk_handle_activate(void);
void bwalk_apply_move_data(struct movedata *data);
void bwalk_update_speed_theta(void);
void bwalk_tick(void);

#endif
