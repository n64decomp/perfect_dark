#include <ultra64.h>
#include "constants.h"
#include "game/sky.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void skyTick(void)
{
	g_SkyCloudOffset += g_Vars.lvupdate60freal * g_SkyWindSpeed;

	if (g_SkyCloudOffset > 4096) {
		g_SkyCloudOffset -= 4096;
	}
}
