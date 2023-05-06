#include <ultra64.h>
#include "constants.h"
#include "game/weather.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

s32 g_WeatherActive = false;

void weatherReset(void)
{
	g_WeatherActive = false;
	g_WeatherData = NULL;

	if ((g_StageIndex == STAGEINDEX_CHICAGO
				|| g_StageIndex == STAGEINDEX_AIRBASE
				|| g_StageIndex == STAGEINDEX_G5BUILDING
				|| g_StageIndex == STAGEINDEX_CRASHSITE)
			&& PLAYERCOUNT() < 2) {
		g_WeatherData = mempAlloc(sizeof(struct weatherdata), MEMPOOL_STAGE);
		g_WeatherData->particledata[0] = weatherAllocateParticles();
		g_WeatherData->type = -1;
		g_WeatherData->windanglerad = 0;
		g_WeatherData->unk0c = 0;
		g_WeatherData->unk10 = 1;

		if (g_StageIndex == STAGEINDEX_CHICAGO || g_StageIndex == STAGEINDEX_G5BUILDING) {
			g_WeatherData->windspeed = 20;
		} else if (g_StageIndex == STAGEINDEX_CRASHSITE) {
			g_WeatherData->windspeed = 10;
		} else {
			g_WeatherData->windspeed = 5;
		}

		g_WeatherData->audiohandles[0] = 0;
		g_WeatherData->audiohandles[1] = 0;
		g_WeatherData->audiohandles[2] = 0;
		g_WeatherData->audiohandles[3] = 0;
		g_WeatherData->unk44 = 0;
		g_WeatherData->unk94 = -1;
		g_WeatherData->unk48 = 1;
		g_WeatherData->unk4c = 0;
		g_WeatherData->unk50 = 0;
		g_WeatherData->unk54 = 0;
		g_WeatherData->unk58[0].unk00 = 0;
		g_WeatherData->unk58[1].unk00 = 0;
		g_WeatherData->unk58[2].unk00 = 0;
		g_WeatherData->unk58[3].unk00 = 1;
		g_WeatherData->unk58[0].unk04 = 1;
		g_WeatherData->unk58[0].unk08 = 10;

		if (g_WeatherData->unk58[0].unk08 < 0) {
			g_WeatherData->unk58[0].unk08 = -g_WeatherData->unk58[0].unk08;
		}

		g_WeatherData->unk58[0].unk08 = 0;
		g_WeatherData->unk58[1].unk08 = 0;
		g_WeatherData->unk58[2].unk08 = 0;
		g_WeatherData->unk58[3].unk08 = 0;
		g_WeatherData->unkb8 = 150;
		g_WeatherData->unkc0 = 0;
		g_WeatherData->unkc4 = 0;
		g_WeatherData->unkc8 = 15;
		g_WeatherData->unk88 = 1;
		g_WeatherData->unk90 = 0;
		g_WeatherData->intensity = 0;
		g_WeatherData->unkd0 = 0;
		g_WeatherData->unkd4 = 0;

		g_WeatherActive = true;
	}
}
