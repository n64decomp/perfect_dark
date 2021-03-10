#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "lib/memory.h"
#include "data.h"
#include "types.h"

void func0f000000(void)
{
	s32 i;

	if (g_LanguageId != LANGUAGE_NTSC_EN) {
		var800aabb4 = malloc(0x2e80, MEMPOOL_PERMANENT);
		var800aabb8 = malloc(0x100, MEMPOOL_PERMANENT);

		for (i = 0; i < 0x7c; i++) {
			var800aabb8[i].unk00_00 = 0;
			var800aabb8[i].unk00_02 = 0x3fff;
		}
	}
}
