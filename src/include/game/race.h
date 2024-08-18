#ifndef IN_GAME_RACE_H
#define IN_GAME_RACE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void races_init(void);

u16 race_get_anim_sum_angle_as_int(s16 animnum, s32 frame, s32 endframe);
s32 race_get_anim_sum_forward_as_int(s16 animnum, s32 startframe, s32 endframe);
s32 race_init_anim_group(struct attackanimconfig *configs);
void race_init_anim_groups(struct attackanimgroup **groups);
s32 race_count_anims(struct animtablerow *rows);
void race_init_anims(void);

#endif
