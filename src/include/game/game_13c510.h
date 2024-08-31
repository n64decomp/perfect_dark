#ifndef _IN_GAME_GAME_13C510_H
#define _IN_GAME_GAME_13C510_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void artifacts_clear(void);
void artifacts_tick(void);
void artifacts_calculate_glares_for_room(s32 roomnum);
Gfx *artifacts_configure_for_glares(Gfx *gdl);
Gfx *artifacts_unconfigure_for_glares(Gfx *gdl);
Gfx *artifacts_render_glares_for_room(Gfx *gdl, s32 roomnum);

#endif
