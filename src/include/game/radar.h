#ifndef IN_GAME_RADAR_H
#define IN_GAME_RADAR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

Gfx *radar_render_background(Gfx *gdl, struct textureconfig *tconfig, s32 arg2, s32 arg3, s32 arg4);
s32 radar_get_team_index(s32 team);
Gfx *radar_draw_dot(Gfx *gdl, struct prop *prop, struct coord *dist, u32 colour1, u32 colour2, bool swapcolours);
Gfx *radar_render(Gfx *gdl);
Gfx *radar_render_r_tracked_props(Gfx *gdl);

#endif
