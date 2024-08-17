#ifndef _IN_GAME_CREDITS_H
#define _IN_GAME_CREDITS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

Gfx *credits_draw(Gfx *gdl);
void credits_reset(void);
void credits_request_alt_title(void);
void credits0f13ae04(Mtxf *mtx);

#endif
