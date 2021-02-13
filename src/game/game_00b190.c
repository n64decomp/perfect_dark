#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/dma.h"
#include "lib/memory.h"
#include "types.h"

void loadTextureList(void)
{
	extern u8 _textureslistSegmentRomStart;
	extern u8 _textureslistSegmentRomEnd;

	u32 len = ((&_textureslistSegmentRomEnd - &_textureslistSegmentRomStart) + 15) & -16;

	g_Textures = malloc(len, MEMPOOL_PERMANENT);

	dmaExec(g_Textures, &_textureslistSegmentRomStart, len);
}
