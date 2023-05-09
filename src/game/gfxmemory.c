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
u32 g_GfxRequestedDisplayList;

u32 g_GfxSizesByPlayerCount[] = {
	0x00010000,
	0x00018000,
	0x00020000,
	0x00028000,
};

u32 g_VtxSizesByPlayerCount[] = {
	0x00010000,
	0x00018000,
	0x00020000,
	0x00028000,
};

s32 g_GfxNumSwapsPerBuffer[2] = {0, 1};
u32 g_GfxNumSwaps = 0x00000002;

extern s32 g_StageNum;
extern struct stageallocation g_StageAllocations8Mb[];

void gfxReset(void)
{
	s32 index = 0;
	s32 gfx;

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

	g_GfxSizesByPlayerCount[PLAYERCOUNT() - 1] = gfx * 1024;
	g_VtxSizesByPlayerCount[PLAYERCOUNT() - 1] = g_StageAllocations8Mb[index].mvtx * 1024;

	g_GfxBuffers[0] = mempAlloc(g_GfxSizesByPlayerCount[PLAYERCOUNT() - 1] * 2, MEMPOOL_STAGE);
	g_GfxBuffers[1] = g_GfxBuffers[0] + g_GfxSizesByPlayerCount[PLAYERCOUNT() - 1];
	g_GfxBuffers[2] = g_GfxBuffers[1] + g_GfxSizesByPlayerCount[PLAYERCOUNT() - 1];

	g_VtxBuffers[0] = mempAlloc(g_VtxSizesByPlayerCount[PLAYERCOUNT() - 1] * 2, MEMPOOL_STAGE);
	g_VtxBuffers[1] = g_VtxBuffers[0] + g_VtxSizesByPlayerCount[PLAYERCOUNT() - 1];
	g_VtxBuffers[2] = g_VtxBuffers[1] + g_VtxSizesByPlayerCount[PLAYERCOUNT() - 1];

	g_GfxActiveBufferIndex = 0;
	g_GfxRequestedDisplayList = false;
	g_GfxMemPos = g_VtxBuffers[0];
}

Gfx *gfxGetMasterDisplayList(void)
{
	g_GfxRequestedDisplayList = true;

	return (Gfx *) UNCACHED(g_GfxBuffers[g_GfxActiveBufferIndex]);
}

struct gfxvtx *gfxAllocateVertices(u32 count)
{
	void *ptr = g_GfxMemPos;
	g_GfxMemPos += count * sizeof(struct gfxvtx);
	g_GfxMemPos = (u8 *)ALIGN16((u32)g_GfxMemPos);

	return UNCACHED(ptr);
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
	g_GfxMemPos += count * 0x10;

	return UNCACHED(ptr);
}

void *gfxAllocateColours(s32 count)
{
	void *ptr = g_GfxMemPos;
	count = ALIGN16(count * sizeof(u32));
	g_GfxMemPos += count;

	return UNCACHED(ptr);
}

void *gfxAllocate(u32 size)
{
	void *ptr = g_GfxMemPos;
	size = ALIGN16(size);
	g_GfxMemPos += size;

	return ptr;
}

extern s32 g_GfxNumSwapsPerBuffer[2];

void gfxSwapBuffers(void)
{
	g_GfxActiveBufferIndex ^= 1;
	g_GfxRequestedDisplayList = false;
	g_GfxMemPos = g_VtxBuffers[g_GfxActiveBufferIndex];
	g_GfxNumSwapsPerBuffer[g_GfxActiveBufferIndex] = g_GfxNumSwaps;
	g_GfxNumSwaps++;

	if (g_GfxNumSwaps == -1) {
		g_GfxNumSwaps = 2;
	}
}
