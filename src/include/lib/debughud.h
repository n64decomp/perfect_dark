#ifndef _IN_LIB_DEBUGHUD_H
#define _IN_LIB_DEBUGHUD_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void dhud_init(void);
void dhud_reset(void);
void dhud_clear(void);
void dhud_set_pos(s32 x, s32 y);
void dhud_set_fg_colour(s32 r, s32 g, s32 b, s32 a);
void dhud_set_bg_colour(s32 r, s32 g, s32 b, s32 a);
void dhud_print_string(char *text);
Gfx *dhud_render(Gfx *gdl);

#endif
