#ifndef IN_GAME_GAME_005FD0_H
#define IN_GAME_GAME_005FD0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool func0f005fd0(s32 animnum);
s32 chrChooseFootstepSound(struct chrdata *chr, s32 index);
void chrCheckFootstep(struct chrdata *chr);
void chrCheckFootstepMagic(struct chrdata *chr);

#endif
