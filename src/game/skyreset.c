#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void sky_reset(u32 stagenum)
{
	g_SkyStageNum = stagenum;
	g_SkyLightningActive = false;
	g_SkyWindSpeed = 1;
}
