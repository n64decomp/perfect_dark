#ifndef IN_GAME_ZBUF_H
#define IN_GAME_ZBUF_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void *zbuf_get_allocation(void);
void zbuf_reset(s32 stagenum);
void zbuf_swap(void);
Gfx *zbuf_configure_rdp(Gfx *gdl);
Gfx *zbuf_clear(Gfx *gdl);
Gfx *zbuf_draw_artifacts_offscreen(Gfx *gdl);

#endif
