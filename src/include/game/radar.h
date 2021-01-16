#ifndef IN_GAME_RADAR_H
#define IN_GAME_RADAR_H
#include <ultra64.h>
#include "types.h"

Gfx *radarRenderBackground(Gfx *gdl, struct textureconfig *tconfig, s32 arg2, s32 arg3, s32 arg4);
s32 radarGetTeamIndex(s32 team);
Gfx *radarDrawDot(Gfx *gdl, struct prop *prop, struct coord *dist, u32 colour1, u32 colour2, bool swapcolours);
Gfx *radarRender(Gfx *gdl);
Gfx *radarRenderRTrackedProps(Gfx *gdl);

#endif
