#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

u16 *g_FrameBuffers[2];

extern s32 var8009d140jf;

void langInit(void)
{
	s32 i;

#if VERSION >= VERSION_JPN_FINAL
	var8009d140jf = IS4MB() ? 124 : 174;

	var800aabb4 = mempAlloc(var8009d140jf * (sizeof(struct var800aabb4) * 8), MEMPOOL_PERMANENT);
	var800aabb8 = mempAlloc(ALIGN16(var8009d140jf * sizeof(struct var800aabb8)), MEMPOOL_PERMANENT);

	for (i = 0; i < var8009d140jf; i++) {
		var800aabb8[i].unk00_00 = 0;
		var800aabb8[i].unk00_02 = 0x3fff;
	}
#else
	if (g_Jpn) {
		var800aabb4 = mempAlloc(124 * (sizeof(struct var800aabb4) * 8), MEMPOOL_PERMANENT);
		var800aabb8 = mempAlloc(ALIGN16(124 * sizeof(struct var800aabb8)), MEMPOOL_PERMANENT);

		for (i = 0; i < 124; i++) {
			var800aabb8[i].unk00_00 = 0;
			var800aabb8[i].unk00_02 = 0x3fff;
		}
	}
#endif
}
