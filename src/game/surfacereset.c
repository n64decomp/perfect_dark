#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

void surfaceReset(void)
{
	g_TexCacheCount = 0;

	g_TexSharedPool.start = NULL;
	g_TexSharedPool.end = NULL;
	g_TexSharedPool.rightpos = NULL;
}
