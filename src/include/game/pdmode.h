#ifndef _IN_GAME_PDMODE_H
#define _IN_GAME_PDMODE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

f32 pdmode_get_enemy_reaction_speed(void);
f32 pdmode_get_enemy_health(void);
f32 pdmode_get_enemy_damage(void);
f32 pdmode_get_enemy_accuracy(void);
void func0f01b148(u32 arg0);
void title_set_next_stage(s32 stagenum);

#endif
