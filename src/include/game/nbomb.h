#ifndef IN_GAME_NBOMB_H
#define IN_GAME_NBOMB_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void func0f0099a4(void);
void nbombs_tick(void);
Gfx *nbombs_render(Gfx *gdl);
void nbomb_create_storm(struct coord *pos, struct prop *ownerprop);
Gfx *nbomb_render_overlay(Gfx *gdl);
Gfx *gas_render(Gfx *gdl);

#endif
