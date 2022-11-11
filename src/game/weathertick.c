#include <ultra64.h>
#include "constants.h"
#include "game/weather.h"
#include "bss.h"
#include "lib/main.h"
#include "data.h"
#include "types.h"

void weatherTick(void)
{
	if (!g_WeatherData
			|| (g_StageIndex == STAGEINDEX_AIRBASE && g_Vars.currentplayer->cam_pos.z < -2000.0f)
			|| (g_StageIndex == STAGEINDEX_G5BUILDING && g_Vars.tickmode != TICKMODE_CUTSCENE)) {
		return;
	}

	switch (g_WeatherData->type) {
	case WEATHERTYPE_RAIN:
		weatherTickRain(g_WeatherData);
		break;
	case WEATHERTYPE_SNOW:
		weatherTickSnow(g_WeatherData);
		break;
	}
}
