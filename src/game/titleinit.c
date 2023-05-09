#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void titleInit(void)
{
	g_TitleMode = -1;
	g_TitleNextMode = TITLEMODE_LEGAL;
	g_TitleTimer = 0;
	g_TitleNextStage = -1;
	var800624f0 = 0;
	g_MissionConfig.pdmodereaction = 0;
	g_MissionConfig.pdmodehealth = 128;
	g_MissionConfig.pdmodedamage = 128;
	g_MissionConfig.pdmodeaccuracy = 128;
}
