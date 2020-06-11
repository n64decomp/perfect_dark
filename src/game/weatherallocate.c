#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/weather.h"
#include "gvars/gvars.h"
#include "lib/lib_121e0.h"
#include "types.h"

u32 var800623b0 = 0x00000000;
u32 var800623b4 = 0x00000001;
u32 var800623b8 = 0x00000003;
u32 var800623bc = 0x00000000;
u32 var800623c0 = 0x00000000;
u32 var800623c4 = 0x00000000;
u32 var800623c8 = 0x00000000;
u32 var800623cc = 0x00000000;
u32 var800623d0 = 0x00000000;
u32 var800623d4 = 0x00000000;
u32 var800623d8 = 0x00000000;
u32 var800623dc = 0x00000000;
u32 var800623e0 = 0x00000000;
u32 var800623e4 = 0x00000000;
u32 var800623e8 = 0x00000000;
u32 var800623ec = 0x00000000;
s32 g_WeatherEnabled = false;
u32 var800623f4 = 0x00000000;
u32 var800623f8 = 0x00000000;
u32 var800623fc = 0x00000000;
u32 var80062400 = 0x00000000;
u32 var80062404 = 0x00000000;
u32 var80062408 = 0x00000000;
u32 var8006240c = 0x00000000;
u32 var80062410 = 0x00000000;
u32 var80062414 = 0x03000000;
u32 var80062418 = 0x00dc0000;
u32 var8006241c = 0x00dc0000;
u32 var80062420 = 0x00ff0000;
u32 var80062424 = 0x00ff0000;
u32 var80062428 = 0x007f0000;
u32 var8006242c = 0x00000000;
u32 var80062430 = 0xdcdcdc00;
u32 var80062434 = 0xdcdcdc00;
u32 var80062438 = 0xffffff00;
u32 var8006243c = 0xffffff00;
u32 var80062440 = 0x007f0000;
u32 var80062444 = 0x00000000;
u32 var80062448 = 0xffffff00;
u32 var8006244c = 0xffffff00;
u32 var80062450 = 0x00000000;
u32 var80062454 = 0x00000000;
u32 var80062458 = 0x00000000;
u32 var8006245c = 0x00000000;
u32 var80062460 = 0x00000000;
u32 var80062464 = 0x00000000;
u32 var80062468 = 0x45989800;
u32 var8006246c = 0x00000000;
u32 var80062470 = 0x00000000;
u32 var80062474 = 0xbf800000;
u32 var80062478 = 0x00000000;
u32 var8006247c = 0x3f800000;
u32 var80062480 = 0x00000000;
u32 var80062484 = 0x00000000;
u32 var80062488 = 0x3f800000;
u32 var8006248c = 0x00000000;
u32 var80062490 = 0x00000000;
u32 var80062494 = 0x00000001;
u32 var80062498 = 0x00000000;
u32 var8006249c = 0x00000000;

void weatherAllocate(void)
{
	g_WeatherEnabled = false;
	g_WeatherData = NULL;

	if ((g_StageIndex == STAGEINDEX_CHICAGO
				|| g_StageIndex == STAGEINDEX_AIRBASE
				|| g_StageIndex == STAGEINDEX_G5BUILDING
				|| g_StageIndex == STAGEINDEX_CRASHSITE)
			&& PLAYERCOUNT() < 2) {
		g_WeatherData = malloc(sizeof(struct weatherdata), 4);
		g_WeatherData->particledata = weatherAllocateParticles();
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

		g_WeatherEnabled = true;
	}
}
