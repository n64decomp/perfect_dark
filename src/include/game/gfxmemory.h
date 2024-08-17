#ifndef _IN_GAME_GFXMEMORY_H
#define _IN_GAME_GFXMEMORY_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern u8 *g_GfxBuffers[3];

void gfx_reset(void);
Gfx *gfx_get_master_display_list(void);
Vtx *gfx_allocate_vertices(u32 count);
void *gfx_allocate_matrix(void);
LookAt *gfx_allocate_look_at(s32 count);
Col *gfx_allocate_colours(s32 count);
void *gfx_allocate(u32 size);
void gfx_swap_buffers(void);
s32 gfx_get_free_gfx(Gfx *gdl);

#endif
