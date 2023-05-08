#ifndef IN_GAME_GAME_176080_H
#define IN_GAME_GAME_176080_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void *mblurGetAllocation(void);
void mblurReset(s32 stagenum);
void mblur0f176298(void);
Gfx *mblur0f1762ac(Gfx *gdl);
Gfx *mblur0f1763f4(Gfx *gdl);
Gfx *mblurRender(Gfx *gdl);

#endif
