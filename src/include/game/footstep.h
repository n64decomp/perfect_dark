#ifndef IN_GAME_FOOTSTEP_H
#define IN_GAME_FOOTSTEP_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 footstepChooseSound(struct chrdata *chr, s32 index);
void footstepCheckDefault(struct chrdata *chr);
void footstepCheckMagic(struct chrdata *chr);

#endif
