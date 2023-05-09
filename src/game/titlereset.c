#include <ultra64.h>
#include "constants.h"
#include "game/getitle.h"
#include "game/title.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

void titleReset(void)
{
	g_TitleMode = -1;
	g_TitleDelayedTimer = 2;
	g_TitleDelayedMode = -1;

	if (var800624f0) {
		g_TitleNextMode = TITLEMODE_SKIP;
	}

	var8009cca0 = mempAlloc(0x47800, MEMPOOL_STAGE);
}
