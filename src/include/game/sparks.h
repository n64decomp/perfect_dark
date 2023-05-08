#ifndef _IN_GAME_SPARKS_H
#define _IN_GAME_SPARKS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void sparksReset(void);

void sparksTick(void);

void sparksCreate(s32 room, struct prop *prop, struct coord *pos, struct coord *arg3, struct coord *dir, s32 type);
Gfx *sparksRender(Gfx *gdl);

#endif
