#ifndef _IN_GAME_SPARKS_H
#define _IN_GAME_SPARKS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void sparks_reset(void);

void sparks_tick(void);

void sparks_create(s32 room, struct prop *prop, struct coord *pos, struct coord *arg3, struct coord *dir, s32 type);
Gfx *sparks_render(Gfx *gdl);

#endif
