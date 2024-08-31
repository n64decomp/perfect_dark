#ifndef IN_GAME_RADAR_H
#define IN_GAME_RADAR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 radar_get_team_index(s32 team);
Gfx *radar_draw_dot(Gfx *gdl, struct prop *prop, struct coord *dist, u32 colour1, u32 colour2, bool swapcolours);
Gfx *radar_render(Gfx *gdl);

#endif
