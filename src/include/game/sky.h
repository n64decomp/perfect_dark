#ifndef _IN_GAME_SKY_H
#define _IN_GAME_SKY_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void sky_reset(u32 stagenum);

void sky_tick(void);

Gfx *sky_render(Gfx *gdl);
Gfx *sky_render_suns(Gfx *gdl, bool xray);
Gfx *sky_render_artifacts(Gfx *gdl);
void sky_set_overexposure(s32 arg0, s32 arg1, s32 arg2);
Gfx *sky_render_overexposure(Gfx *gdl);

#endif
