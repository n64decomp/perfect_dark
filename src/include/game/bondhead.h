#ifndef IN_GAME_BONDHEAD_H
#define IN_GAME_BONDHEAD_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bhead_reset(void);

void bhead_flip_animation(void);
void bhead_update_idle_roll(void);
void bhead_update_pos(struct coord *vel);
void bhead_update_rot(struct coord *lookvel, struct coord *upvel);
void bhead_set_damp(f32 headdamp);
void bhead_update(f32 speedforwards, f32 speedsideways);
void bhead_adjust_animation(f32 speed);
void bhead_start_death_animation(s16 animnum, u32 flip, f32 fstarttime, f32 speed);
void bhead_set_speed(f32 speed);
f32 bhead_get_breathing_value(void);

#endif
