#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void skyReset(u32 stagenum)
{
	g_SkyStageNum = stagenum;
	var800a33a4 = 0;
	var8007db84 = 1;
}
