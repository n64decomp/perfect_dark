#ifndef IN_GAME_FOOTSTEP_H
#define IN_GAME_FOOTSTEP_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 footstep_choose_sound(struct chrdata *chr, s32 index);
void footstep_check_default(struct chrdata *chr);
void footstep_check_magic(struct chrdata *chr);

#endif
