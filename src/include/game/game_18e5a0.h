#ifndef IN_GAME_GAME_18E5A0_H
#define IN_GAME_GAME_18E5A0_H
#include <ultra64.h>
#include "types.h"

u32 func0f18e5ac(void);
s32 teamGetIndex(s32 team);
Gfx *radarDrawDot(Gfx *gdl, struct prop *prop, struct coord *dist, u32 colour, s32 arg4, s32 arg5);
u32 func0f18f874(void);
Gfx *radarDrawProps(Gfx *gdl);

#endif
