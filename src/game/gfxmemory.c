#include <ultra64.h>
#include "constants.h"
#include "game/gfxmemory.h"
#include "game/stubs/game_175f50.h"
#include "bss.h"
#include "lib/rzip.h"
#include "lib/dma.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "lib/str.h"
#include "data.h"
#include "types.h"

/**
 * This file handles memory usage for graphics related tasks.
 *
 * There are two pools, "gfx" and "vtx", which are used to store different data.
 *
 * The gfx pool (g_GfxBuffers) is sized based on the stage's -mgfx and -mgfxtra
 * arguments. It contains only the master display list's GBI bytecode.
 * The master gdl is passed through all rendering functions in the game engine,
 * where each appends to the display list.
 *
 * The vtx pool (g_VtxBuffers) is sized based on the stage's -mvtx argument.
 * It is used for auxiliary graphics data such as vertex arrays, matrices and
 * colours.
 *
 * Both the gfx and vtx pools are split into two buffers of equal size.
 * Only one buffer is active at a time - the other is being drawn to the screen
 * while the active one is being built. Each time a frame is finished the active
 * buffer index is swapped to the other one.
 *
 * Both the gfx and vtx pools have a third element in them, but this is just a
 * marker for the end of the second element's allocation.
 */

u8 *g_GfxBuffers[3];
u8 *g_VtxBuffers[3];
u8 *g_GfxMemPos;
u8 g_GfxActiveBufferIndex;

u32 g_GfxNumSwaps = 2;

extern s32 g_StageNum;
extern struct stageallocation g_StageAllocations8Mb[];

void gfxReset(void)
{
	s32 index = 0;
	s32 gfx;
	s32 vtx;

	while (g_StageAllocations8Mb[index].stagenum) {
		if (g_StageNum == g_StageAllocations8Mb[index].stagenum) {
			break;
		}

		index++;
	}

	gfx = g_StageAllocations8Mb[index].gfx;

	if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) && PLAYERCOUNT() == 2) {
		gfx += g_StageAllocations8Mb[index].gfxtra;
	}

	vtx = g_StageAllocations8Mb[index].mvtx;

	gfx *= 1024;
	vtx *= 1024;

	g_GfxBuffers[0] = UNCACHED(mempAlloc(gfx * 2, MEMPOOL_STAGE));
	g_GfxBuffers[1] = g_GfxBuffers[0] + gfx;
	g_GfxBuffers[2] = g_GfxBuffers[1] + gfx;

	g_VtxBuffers[0] = UNCACHED(mempAlloc(vtx * 2, MEMPOOL_STAGE));
	g_VtxBuffers[1] = g_VtxBuffers[0] + vtx;
	g_VtxBuffers[2] = g_VtxBuffers[1] + vtx;

	g_GfxActiveBufferIndex = 0;
	g_GfxMemPos = g_VtxBuffers[0];
}

Gfx *gfxGetMasterDisplayList(void)
{
	return (Gfx *) g_GfxBuffers[g_GfxActiveBufferIndex];
}

struct gfxvtx *gfxAllocateVertices(u32 count)
{
	void *ptr = g_GfxMemPos;
	g_GfxMemPos += count * sizeof(struct gfxvtx);
	g_GfxMemPos = (u8 *)ALIGN16((u32)g_GfxMemPos);

	return ptr;
}

void *gfxAllocateMatrix(void)
{
	void *ptr = g_GfxMemPos;
	g_GfxMemPos += sizeof(Mtx);

	return ptr;
}

void *gfxAllocateLookAt(s32 count)
{
	void *ptr = g_GfxMemPos;
	g_GfxMemPos += count * sizeof(LookAt);

	return ptr;
}

void *gfxAllocateColours(s32 count)
{
	void *ptr = g_GfxMemPos;
	count = ALIGN16(count * sizeof(u32));
	g_GfxMemPos += count;

	return ptr;
}

void *gfxAllocate(u32 size)
{
	void *ptr = g_GfxMemPos;
	size = ALIGN16(size);
	g_GfxMemPos += size;

	return ptr;
}

void gfxSwapBuffers(void)
{
	g_GfxActiveBufferIndex ^= 1;
	g_GfxMemPos = g_VtxBuffers[g_GfxActiveBufferIndex];
	g_GfxNumSwaps++;

	if (g_GfxNumSwaps == 0xffffffff) {
		g_GfxNumSwaps = 2;
	}
}
