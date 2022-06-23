#ifndef _IN_GAME_HEALTHBAR_H
#define _IN_GAME_HEALTHBAR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

Gfx *healthbarDraw(Gfx *gdl, struct chrdata *chr, s32 offy, f32 heightfrac);

#endif
