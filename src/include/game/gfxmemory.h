#ifndef _IN_GAME_GFXMEMORY_H
#define _IN_GAME_GFXMEMORY_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void gfxInitMemory(void);
Gfx *gfxGetMasterDisplayList(void);
struct gfxvtx *gfxAllocateVertices(s32 count);
void *gfxAllocateMatrix(void);
void *gfxAllocate4Words(s32 count);
u32 *gfxAllocateColours(s32 count);
void *gfxAllocate(u32 size);
void gfxSwapBuffers(void);

#endif
