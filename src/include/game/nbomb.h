#ifndef IN_GAME_NBOMB_H
#define IN_GAME_NBOMB_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void func0f0099a4(void);
void nbombsTick(void);
Gfx *nbombsRender(Gfx *gdl);
void nbombCreateStorm(struct coord *pos, struct prop *ownerprop);
Gfx *nbombRenderOverlay(Gfx *gdl);
Gfx *gasRender(Gfx *gdl);

#endif
