#include <ultra64.h>
#include "constants.h"
#include "game/weather.h"
#include "bss.h"
#include "lib/main.h"
#include "data.h"
#include "types.h"

u32 var80062950 = 100;
bool g_WeatherTickEnabled = true;

void weather_tick(void)
{
	if (!g_WeatherData
			|| (g_StageIndex == STAGEINDEX_AIRBASE && g_Vars.currentplayer->cam_pos.z < -2000.0f)
			|| (g_StageIndex == STAGEINDEX_G5BUILDING && g_Vars.tickmode != TICKMODE_CUTSCENE)) {
		return;
	}

	main_override_variable("wettick", (u32 *)&g_WeatherTickEnabled);
	main_override_variable("windspeed", &var80062950);

	if (g_WeatherTickEnabled) {
		switch (g_WeatherData->type) {
		case WEATHERTYPE_RAIN:
			weather_tick_rain(g_WeatherData);
			break;
		case WEATHERTYPE_SNOW:
			weather_tick_snow(g_WeatherData);
			break;
		}
	}
}
