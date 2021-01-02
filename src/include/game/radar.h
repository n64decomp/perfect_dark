#ifndef IN_GAME_RADAR_H
#define IN_GAME_RADAR_H
#include <ultra64.h>
#include "types.h"

u32 func0f18e5ac(void);
s32 teamGetIndex(s32 team);
Gfx *radarDrawDot(Gfx *gdl, struct prop *prop, struct coord *dist, u32 colour, s32 arg4, s32 arg5);
Gfx *radarRender(Gfx *gdl);
Gfx *radarDrawProps(Gfx *gdl);

#endif
