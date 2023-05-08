#ifndef _IN_GAME_SKY_H
#define _IN_GAME_SKY_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void skyReset(u32 stagenum);

void skyTick(void);

Gfx *skyRender(Gfx *gdl);
Gfx *skyRenderSuns(Gfx *gdl, bool xray);
Gfx *skyRenderArtifacts(Gfx *gdl);
void sky0f127334(s32 arg0, s32 arg1, s32 arg2);
Gfx *sky0f1274d8(Gfx *gdl);

#endif
