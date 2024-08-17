#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/dma.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

void tex_init(void)
{
	extern u8 _textureslistSegmentRomStart;
	extern u8 _textureslistSegmentRomEnd;

	u32 len = ((&_textureslistSegmentRomEnd - &_textureslistSegmentRomStart) + 15) & -16;

	g_Textures = memp_alloc(len, MEMPOOL_PERMANENT);

	dma_exec(g_Textures, (romptr_t) &_textureslistSegmentRomStart, len);
}
