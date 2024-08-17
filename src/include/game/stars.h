#ifndef _IN_GAME_STARS_H
#define _IN_GAME_STARS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void stars0f135c70(void);
void star_insert(s32 arg0, struct coord *arg1);
void stars_reset(void);
Gfx *stars_render(Gfx *gdl);

#endif
