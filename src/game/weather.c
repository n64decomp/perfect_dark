#include <ultra64.h>
#include "constants.h"
#include "game/dlights.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/gfxmemory.h"
#include "game/sparks.h"
#include "game/weather.h"
#include "game/bg.h"
#include "game/file.h"
#include "game/lv.h"
#include "bss.h"
#include "lib/main.h"
#include "lib/snd.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

static Gfx *weatherRenderRain(Gfx *gdl, struct weatherdata *weather, s32 arg2);
static Gfx *weatherRenderSnow(Gfx *gdl, struct weatherdata *weather, s32 arg2);

struct weatherdata *g_WeatherData = NULL;

Gfx *weatherRender(Gfx *gdl)
{
	struct weatherdata *weather;

	if (!g_WeatherData) {
		return gdl;
	}

	if (g_StageIndex == STAGEINDEX_AIRBASE && g_Vars.currentplayer->cam_pos.z < -2000.0f) {
		return gdl;
	}

	if (g_StageIndex == STAGEINDEX_G5BUILDING && g_Vars.tickmode != TICKMODE_CUTSCENE) {
		return gdl;
	}

	weather = g_WeatherData;

	gSPDisplayList(gdl++, &var800613a0);
	gSPDisplayList(gdl++, &var80061380);

	if (weather->type == WEATHERTYPE_SNOW) {
		texSelect(&gdl, &g_TexGeneralConfigs[1], 2, 1, 2, 1, NULL);

		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
		gDPSetColorDither(gdl++, G_CD_NOISE);
		gDPSetRenderMode(gdl++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
		gDPSetAlphaCompare(gdl++, G_AC_NONE);
		gDPSetTextureLOD(gdl++, G_TL_TILE);
		gDPSetTextureConvert(gdl++, G_TC_FILT);
		gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
		gSPSetGeometryMode(gdl++, G_SHADE | G_SHADING_SMOOTH);
		gDPSetAlphaDither(gdl++, G_AD_NOISE);
	}

	switch (weather->type) {
	case WEATHERTYPE_RAIN:
		gdl = weatherRenderRain(gdl, weather, 0);
		break;
	case WEATHERTYPE_SNOW:
		gdl = weatherRenderSnow(gdl, weather, 0);
		break;
	}

	return gdl;
}

struct weatherparticledata *weatherAllocateParticles(void)
{
	struct weatherparticledata *data = mempAlloc(sizeof(struct weatherparticledata), MEMPOOL_STAGE);
	u32 i;

	data->unk3e80.x = 0;
	data->unk3e80.y = 0;
	data->unk3e80.z = 0;

	data->boundarymin.x = -800;
	data->boundarymax.x = 800;
	data->boundaryrange.x = 1600;

	data->boundarymin.z = -800;
	data->boundarymax.z = 800;
	data->boundaryrange.z = 1600;

	if (g_StageIndex == STAGEINDEX_CRASHSITE) {
		data->boundarymin.y = -500;
		data->boundarymax.y = 500;
		data->boundaryrange.y = 1000;
	} else {
		data->boundarymin.y = -800;
		data->boundarymax.y = 800;
		data->boundaryrange.y = 1600;
	}

	i = 0;

	while (i != ARRAYCOUNT(g_WeatherData->particledata[0]->unk3ec8)) {
		data->unk3ec8[i++] = 0;
	}

	for (i = 0; i != (s32)ARRAYCOUNT(g_WeatherData->particledata[0]->particles); i++) {
		struct weatherparticle *particle = &data->particles[i];
		particle->pos.x = RANDOMFRAC() * 1600 - 800;
		particle->pos.y = RANDOMFRAC() * 1600 - 800;
		particle->pos.z = RANDOMFRAC() * 1600 - 800;

		particle->inc.x = RANDOMFRAC() * 10 - 5;
		particle->inc.y = -10 - RANDOMFRAC() * 40;
		particle->inc.z = RANDOMFRAC() * 10 - 5;

		particle->unk1c = RANDOMFRAC() + 0.7f;

		particle->active = false;
	}

	return data;
}

static void func0f131610(struct weatherdata *weather)
{
	weather->unk94 = 0;
	weather->unk98 = (random() & 7) + 1;
	weather->unk9c = (random() & 7) + 1;
	weather->unka0 = (random() & 7) + 1;
	weather->unka4 = (random() & 0xf) + 10;
}

static void func0f131678(s32 arg0)
{
	s32 i;

	for (i = 0; i < arg0 + 1; i++) {
		if ((g_WeatherData->unk58[i].unk08 > 0 && g_WeatherData->unk58[i].unk04 > 0.0f)
				|| (g_WeatherData->unk58[i].unk08 < 1 && g_WeatherData->unk58[i].unk00 > 0)) {
			g_WeatherData->unk58[i].unk04 = 0.0f;
			g_WeatherData->unk58[i].unk08 = 100;

			if (g_WeatherData->unk58[i].unk08 < 0) {
				g_WeatherData->unk58[i].unk08 = -g_WeatherData->unk58[i].unk08;
			}
		}
	}
}

static void weatherSetIntensity(s32 intensity)
{
	s32 dotheloop = -1;
	s32 special = -1;
	s32 i;

	if (intensity == g_WeatherData->intensity) {
		return;
	}

	switch (g_WeatherData->type) {
	case WEATHERTYPE_RAIN:
		if (g_WeatherData->intensity == 0) {
			func0f131610(g_WeatherData);
		}

		special = -1;
		dotheloop = 1;

		switch (intensity) {
		case 0:
			g_WeatherData->unkd4 = 0;
			g_WeatherData->unkbc = 100;
			g_WeatherData->unkc0 = 100;

			if (g_WeatherData->unkc0 < 0) {
				g_WeatherData->unkc0 = -g_WeatherData->unkc0;
			}

			dotheloop = -1;
			g_WeatherData->unkc4 = -1;
			break;
		case 1:
			g_WeatherData->unkc8 = 15;
			g_WeatherData->unkd4 = 200;
			g_WeatherData->unkbc = 100;
			g_WeatherData->unkc0 = 100;

			if (g_WeatherData->unkc0 < 0) {
				g_WeatherData->unkc0 = -g_WeatherData->unkc0;
			}

			special = 0;
			g_WeatherData->unkc4 = 0.001f;
			break;
		case 2:
			g_WeatherData->unkc8 = 18;
			g_WeatherData->unkd4 = 400;
			g_WeatherData->unkbc = 150;
			g_WeatherData->unkc0 = 100;

			if (g_WeatherData->unkc0 < 0) {
				g_WeatherData->unkc0 = -g_WeatherData->unkc0;
			}

			special = 1;
			g_WeatherData->unkc4 = 0.01f;
			break;
		case 3:
			g_WeatherData->unkc8 = 30;
			g_WeatherData->unkd4 = 500;
			g_WeatherData->unkbc = 300;
			g_WeatherData->unkc0 = 100;

			if (g_WeatherData->unkc0 < 0) {
				g_WeatherData->unkc0 = -g_WeatherData->unkc0;
			}

			special = 2;
			g_WeatherData->unkc4 = 0.03f;
			break;
		}
		break;
	case WEATHERTYPE_SNOW:
		switch (intensity) {
		case 0:
			g_WeatherData->unkd4 = 0;
			break;
		case 1:
			g_WeatherData->unkd4 = 500;
			break;
		}
		break;
	}

	if (dotheloop >= 0) {
		for (i = 0; i != 3; i++) {
			if (i != special) {
				g_WeatherData->unk58[i].unk04 = 0;
				g_WeatherData->unk58[i].unk08 = 100;

				if (g_WeatherData->unk58[i].unk08 < 0) {
					g_WeatherData->unk58[i].unk08 = -g_WeatherData->unk58[i].unk08;
				}
			}
		}
	}

	if (special >= 0) {
		g_WeatherData->unk58[special].unk04 = 1;
		g_WeatherData->unk58[special].unk08 = 100;

		if (g_WeatherData->unk58[special].unk08 < 0) {
			g_WeatherData->unk58[special].unk08 = -g_WeatherData->unk58[special].unk08;
		}
	}

	g_WeatherData->intensity = intensity;
}


void weatherTickRain(struct weatherdata *weather)
{ \
	s32 lVar6 = 0;
	s32 relativetotal = 0; // eg. -10 if deleted 10 particles, +10 if created 10
	struct weatherparticledata *data;
	s32 i;
	s32 iVar10;
	f32 rand;
	s32 lvupdate;

	if (weather->unk90 > 0) {
		weather->unk88 += (weather->unk8c - weather->unk88) / weather->unk90;
	}

	weather->unk90--;

	if (weather->unk58[0].unk08 > 0) {
		weather->unk58[0].unk00 += (weather->unk58[0].unk04 - weather->unk58[0].unk00) / weather->unk58[0].unk08;
		weather->unk58[0].unk08--;
	}

	if (weather->unk58[1].unk08 > 0) {
		weather->unk58[1].unk00 += (weather->unk58[1].unk04 - weather->unk58[1].unk00) / weather->unk58[1].unk08;
		weather->unk58[1].unk08--;
	}

	if (weather->unk58[2].unk08 > 0) {
		weather->unk58[2].unk00 += (weather->unk58[2].unk04 - weather->unk58[2].unk00) / weather->unk58[2].unk08;
		weather->unk58[2].unk08--;
	}

	// Rain noise
	for (i = 0; i != 4; i++) {
		s32 sounds[] = {
			0x80b7,
			0x80b6,
			0x80b8,
			-1,
		};

		iVar10 = weather->unk58[i].unk00 * 32767.0f * weather->unk88;

		if (g_LvIsPaused) {
			 iVar10 = 0;
		}

		if (iVar10 > 0) {
			if (weather->audiohandles[i] == 0 && sounds[i] >= 0) {
				weather->unkf8 = sounds[i];
				sndStart(var80095200, weather->unkf8, &weather->audiohandles[i], -1,
						-1, -1, -1, -1);
			}

			if (weather->audiohandles[i] != 0) {
				if (sndGetState(weather->audiohandles[i]) != AL_STOPPED) {
					sndAdjust(&weather->audiohandles[i], 0, iVar10 * 3 / 4, -1,
							weather->unkf8, 1, 1, -1, 1);
				}
			}
		} else {
			if (weather->audiohandles[i] != 0) {
				audioStop(weather->audiohandles[i]);
			}
		}
	}

	if (weather->unkc0 > 0) {
		lvupdate = g_Vars.lvupdate60;

		if (weather->unkc0 < lvupdate) {
			weather->unkb8 = weather->unkbc;
		} else {
			weather->unkb8 += lvupdate * ((weather->unkbc - weather->unkb8) / weather->unkc0);
			weather->unkc0 -= lvupdate;
		}
	}

	if (g_StageIndex == STAGEINDEX_AIRBASE) {
		// Force weather direction - but Air Base doesn't use rain...
		weather->windanglerad = 1.5707963705063f;
		weather->windspeedz = -weather->windspeed;
		weather->windspeedx = 0;
	} else if (weather->unk10 > 0) {
		s32 lvupdate = g_Vars.lvupdate60;

		if (weather->unk10 < lvupdate) {
			weather->windanglerad = weather->unk0c;
		} else {
			weather->windanglerad += lvupdate * ((weather->unk0c - weather->windanglerad) / weather->unk10);
			weather->unk10 -= lvupdate;
		}

		if (weather->windanglerad > M_TAU) {
			weather->windanglerad = 0;
		}

		weather->windspeedx = cosf(weather->windanglerad) * weather->windspeed;
		weather->windspeedz = sinf(weather->windanglerad) * weather->windspeed;
		lVar6 = 1;
	} else if (RANDOMFRAC() > 0.99f) {
		rand = RANDOMFRAC();

		weather->unk0c = (rand + rand) * M_PI;
		weather->unk10 = (weather->unk0c - weather->windanglerad) / (PAL ? 0.012f : 0.01f);

		if (weather->unk10 < 0) {
			weather->unk10 = -weather->unk10;
		}
	}

	data = g_WeatherData->particledata[0];

	for (i = 0; i != ARRAYCOUNT(data->particles); i++) {
		struct weatherparticle *particle = &data->particles[i];

		particle->pos.x += particle->inc.x * LVUPDATE60FREAL();
		particle->pos.y += particle->inc.y * LVUPDATE60FREAL();
		particle->pos.z += particle->inc.z * LVUPDATE60FREAL();

		if (particle->pos.y < data->boundarymin.y) {
			lVar6 = 2;

			// Reset particle
			particle->pos.x = data->boundarymin.x + RANDOMFRAC() * (absf(data->boundarymin.x) + absf(data->boundarymax.x));
			particle->pos.z = data->boundarymin.z + RANDOMFRAC() * (absf(data->boundarymin.z) + absf(data->boundarymax.z));

			particle->unk1c = RANDOMFRAC() + 0.7f;

			particle->inc.y = -(RANDOMFRAC() * 20 + weather->unkc8);

			if (ABS(relativetotal) < 2 && weather->unkd0 != weather->unkd4) {
				if (weather->unkd0 < weather->unkd4) {
					if ((particle->active & 3) == 0) {
						particle->active = true;
						relativetotal++;
						weather->unkd0++;
					}
				} else {
					if (particle->active & 3) {
						particle->active = false;
						relativetotal--;
						weather->unkd0--;
					}
				}
			}
		}

		if (lVar6 > 0) {
			particle->inc.x = weather->windspeedx * particle->unk1c;
			particle->inc.z = weather->windspeedz * particle->unk1c;
		}
	}

	if (weather->intensity == 0 && weather->unkd0 < 100) {
		func0f131678(3);
	}
}

void weatherTickSnow(struct weatherdata *weather)
{ \
	s32 lVar7 = 0;
	s32 relativetotal = 0; // eg. -10 if deleted 10 particles, +10 if created 10
	f32 rand;
	s32 lvupdate;
	s32 i;
	struct weatherparticledata *data;

	if (g_StageIndex == STAGEINDEX_AIRBASE) {
		weather->windanglerad = 1.5707963705063f;
		weather->windspeedz = -weather->windspeed;
		weather->windspeedx = 0;
	} else if (weather->unk10 > 0) {
		s32 lvupdate = g_Vars.lvupdate60;

		if (weather->unk10 < lvupdate) {
			weather->windanglerad = weather->unk0c;
		} else {
			weather->windanglerad += lvupdate * ((weather->unk0c - weather->windanglerad) / weather->unk10);
			weather->unk10 -= lvupdate;
		}

		if (weather->windanglerad > M_TAU) {
			weather->windanglerad = 0;
		}

		weather->windspeedx = cosf(weather->windanglerad) * weather->windspeed;
		weather->windspeedz = sinf(weather->windanglerad) * weather->windspeed;
		lVar7 = 1;
	} else if (RANDOMFRAC() > 0.99f) {
		rand = RANDOMFRAC();

		weather->unk0c = (rand + rand) * M_PI;
		weather->unk10 = (weather->unk0c - weather->windanglerad) / (PAL ? 0.012f : 0.01f);

		if (weather->unk10 < 0) {
			weather->unk10 = -weather->unk10;
		}
	}

	data = g_WeatherData->particledata[0];

	// 0
	data->unk3ec8[0] += 0.04f * LVUPDATE60FREAL();

	if (data->unk3ec8[0] < 0) {
		data->unk3ec8[0] += M_TAU;
	}

	if (data->unk3ec8[0] > M_TAU) {
		data->unk3ec8[0] -= M_TAU;
	}

	// 1
	data->unk3ec8[1] += -0.03f * LVUPDATE60FREAL();

	if (data->unk3ec8[1] < 0) {
		data->unk3ec8[1] += M_TAU;
	}

	if (data->unk3ec8[1] > M_TAU) {
		data->unk3ec8[1] -= M_TAU;
	}

	// 2
	data->unk3ec8[2] += 0.04f * LVUPDATE60FREAL();

	if (data->unk3ec8[2] < 0) {
		data->unk3ec8[2] += M_TAU;
	}

	if (data->unk3ec8[2] > M_TAU) {
		data->unk3ec8[2] -= M_TAU;
	}

	// 3
	data->unk3ec8[3] += 0.03f * LVUPDATE60FREAL();

	if (data->unk3ec8[3] < 0) {
		data->unk3ec8[3] += M_TAU;
	}

	if (data->unk3ec8[3] > M_TAU) {
		data->unk3ec8[3] -= M_TAU;
	}

	// 4
	data->unk3ec8[4] += 0.02f * LVUPDATE60FREAL();

	if (data->unk3ec8[4] < 0) {
		data->unk3ec8[4] += M_TAU;
	}

	if (data->unk3ec8[4] > M_TAU) {
		data->unk3ec8[4] -= M_TAU;
	}

	// 5
	data->unk3ec8[5] += 0.01f * LVUPDATE60FREAL();

	if (data->unk3ec8[5] < 0) {
		data->unk3ec8[5] += M_TAU;
	}

	if (data->unk3ec8[5] > M_TAU) {
		data->unk3ec8[5] -= M_TAU;
	}

	// 6
	data->unk3ec8[6] += -0.01f * LVUPDATE60FREAL();

	if (data->unk3ec8[6] < 0) {
		data->unk3ec8[6] += M_TAU;
	}

	if (data->unk3ec8[6] > M_TAU) {
		data->unk3ec8[6] -= M_TAU;
	}

	// 7
	data->unk3ec8[7] += -0.02f * LVUPDATE60FREAL();

	if (data->unk3ec8[7] < 0) {
		data->unk3ec8[7] += M_TAU;
	}

	if (data->unk3ec8[7] > M_TAU) {
		data->unk3ec8[7] -= M_TAU;
	}

	for (i = 0; i < ARRAYCOUNT(data->particles); i++) {
		struct weatherparticle *particle = &data->particles[i];

		particle->pos.x += particle->inc.x * LVUPDATE60FREAL();
		particle->pos.y += particle->inc.y * LVUPDATE60FREAL();
		particle->pos.z += particle->inc.z * LVUPDATE60FREAL();

		if (particle->pos.y < data->boundarymin.y) {
			lVar7 = 2;

			particle->pos.x = data->boundarymin.f[0] + RANDOMFRAC() * (absf(data->boundarymin.f[0]) + absf(data->boundarymax.f[0]));
			particle->pos.z = data->boundarymin.f[2] + RANDOMFRAC() * (absf(data->boundarymin.f[2]) + absf(data->boundarymax.f[2]));

			particle->unk1c = RANDOMFRAC() + 0.7f;

			particle->inc.y = -(15 / 10.0f) - (RANDOMFRAC() * 10) / 10.0f;
			particle->inc.x = weather->windspeedx * particle->unk1c;
			particle->inc.z = weather->windspeedz * particle->unk1c;

			if (ABS(relativetotal) < 20 && weather->unkd0 != weather->unkd4) {
				if (weather->unkd0 < weather->unkd4) {
					if ((particle->active & 3) == 0) {
						particle->active = true;
						relativetotal++;
						weather->unkd0++;
					}
				} else if (particle->active & 3) {
					particle->active = false;
					relativetotal--;
					weather->unkd0--;
				}
			}
		}

		if (lVar7 > 0) {
			particle->inc.x = weather->windspeedx * particle->unk1c;
			particle->inc.z = weather->windspeedz * particle->unk1c;
		}
	}
}

void weatherConfigureRain(u32 intensity)
{
	if (g_WeatherData) {
		g_WeatherData->type = WEATHERTYPE_RAIN;
		weatherSetIntensity(intensity);
	}
}

void weatherConfigureSnow(u32 intensity)
{
	if (g_WeatherData) {
		g_WeatherData->type = WEATHERTYPE_SNOW;
		weatherSetIntensity(intensity);
	}
}

static bool weatherIsRoomWeatherProof(s32 room)
{
	if (g_StageIndex == STAGEINDEX_CHICAGO) {
		// Rooms listed do not have weather
		if (room == ROOM_PETE_0062
				|| room == ROOM_PETE_0061
				|| room == ROOM_PETE_000F
				|| room == ROOM_PETE_0052
				|| room == ROOM_PETE_0045
				|| room == ROOM_PETE_0044
				|| room == ROOM_PETE_0043
				|| room == ROOM_PETE_003D
				|| room == ROOM_PETE_000E
				|| room == ROOM_PETE_000D
				|| room == ROOM_PETE_000C
				|| room == ROOM_PETE_000B
				|| room == ROOM_PETE_000A
				|| room == ROOM_PETE_0009
				|| room == ROOM_PETE_0008
				|| room == ROOM_PETE_0007
				|| room == ROOM_PETE_0006
				|| room == ROOM_PETE_0005
				|| room == ROOM_PETE_0004
				|| room == ROOM_PETE_0037
				|| room == ROOM_PETE_005B
				|| room == ROOM_PETE_005F
				|| room == ROOM_PETE_0060
				|| room == ROOM_PETE_005D
				|| room == ROOM_PETE_001D
				|| room == ROOM_PETE_001F
				|| room == ROOM_PETE_0027
				|| room == ROOM_PETE_0050
				|| room == ROOM_PETE_002C
				|| room == ROOM_PETE_002F
				|| room == ROOM_PETE_0030
				|| room == ROOM_PETE_0011
				|| room == ROOM_PETE_0024
				|| room == ROOM_PETE_0033
				|| room == ROOM_PETE_0034
				|| room == ROOM_PETE_0035
				|| room == ROOM_PETE_0036
				|| room == ROOM_PETE_003C
				|| room == ROOM_PETE_0046
				|| room == ROOM_PETE_0047
				|| room == ROOM_PETE_0049
				|| room == ROOM_PETE_0055
				|| room == ROOM_PETE_0056
				|| room == ROOM_PETE_005E
				|| room == ROOM_PETE_0063
				|| room == ROOM_PETE_0069
				|| room == ROOM_PETE_0003
				|| room == ROOM_PETE_0016
				|| room == ROOM_PETE_004F
				|| room == ROOM_PETE_004B
				|| room == ROOM_PETE_003F
				|| room == ROOM_PETE_0013
				|| room == ROOM_PETE_0019) {
			return true;
		}

		return false;
	}

	if (g_StageIndex == STAGEINDEX_AIRBASE) {
		// Rooms listed have weather
		if (room == ROOM_CAVE_0088
				|| room == ROOM_CAVE_0091
				|| room == ROOM_CAVE_0087
				|| room == ROOM_CAVE_0090
				|| room == ROOM_CAVE_0086
				|| room == ROOM_CAVE_0080
				|| room == ROOM_CAVE_0083
				|| room == ROOM_CAVE_0084
				|| room == ROOM_CAVE_0085
				|| room == ROOM_CAVE_007F
				|| room == ROOM_CAVE_007E
				|| room == ROOM_CAVE_0082
				|| room == ROOM_CAVE_008F
				|| room == ROOM_CAVE_008E
				|| room == ROOM_CAVE_007B
				|| room == ROOM_CAVE_007C
				|| room == ROOM_CAVE_007D
				|| room == ROOM_CAVE_0081
				|| room == ROOM_CAVE_006F) {
			return false;
		}

		return true;
	}

	if (g_StageIndex == STAGEINDEX_CRASHSITE) {
		// Rooms listed do not have weather
		if (room == ROOM_AZT_001F
				|| room == ROOM_AZT_0020
				|| room == ROOM_AZT_0021
				|| room == ROOM_AZT_0022
				|| room == ROOM_AZT_0023
				|| room == ROOM_AZT_0024
				|| room == ROOM_AZT_0051
				|| room == ROOM_AZT_0052
				|| room == ROOM_AZT_0053
				|| room == ROOM_AZT_0054
				|| room == ROOM_AZT_0055
				|| room == ROOM_AZT_0056
				|| room == ROOM_AZT_0057
				|| room == ROOM_AZT_0058
				|| room == ROOM_AZT_0059
				|| room == ROOM_AZT_005A
				|| room == ROOM_AZT_005B
				|| room == ROOM_AZT_005C
				|| room == ROOM_AZT_005D
				|| room == ROOM_AZT_005E
				|| room == ROOM_AZT_005F
				|| room == ROOM_AZT_0060
				|| room == ROOM_AZT_0061
				|| room == ROOM_AZT_0062
				|| room == ROOM_AZT_0063
				|| room == ROOM_AZT_0064
				|| room == ROOM_AZT_002D
				|| room == ROOM_AZT_0040
				|| room == ROOM_AZT_0041
				|| room == ROOM_AZT_0042
				|| room == ROOM_AZT_0043
				|| room == ROOM_AZT_0044
				|| room == ROOM_AZT_0045
				|| room == ROOM_AZT_0046
				|| room == ROOM_AZT_0047
				|| room == ROOM_AZT_0048
				|| room == ROOM_AZT_0049
				|| room == ROOM_AZT_004A
				|| room == ROOM_AZT_004B
				|| room == ROOM_AZT_004C
				|| room == ROOM_AZT_004D
				|| room == ROOM_AZT_004E
				|| room == ROOM_AZT_004F
				|| room == ROOM_AZT_0050) {
			return true;
		}

		return false;
	}

	return false;
}

static Gfx *weatherRenderRain(Gfx *gdl, struct weatherdata *weather, s32 arg2)
{
	u8 stack[0x10];
	Mtxf *mtx;
	s32 i;
	s32 s0;
	s32 spd80;
	s32 spcb8[50];
	struct coord spca8;
	struct coord spc9c;
	struct coord spc90;
	s32 s1;
	s32 s1_2;
	s32 s2;

	f32 spc84;
	s32 spbbc[50];
	struct coord sp964[50];
	struct coord sp70c[50];
	s32 sp708;
	s32 sp258[50][6];
	bool s3;
	struct gfxvtx *s3_2;
	s32 s4;
	struct weatherparticledata *particledata;
	struct weatherparticle *particle;
	f32 temp_f2_7;
	s32 a2;
	struct coord sp230;
	struct coord sp224;
	f32 f0;
	f32 sp218[2];
	f32 sp214;
	struct gfxvtx *vertices; // 210
	f32 frac;
	s32 a0;
	Mtxf sp1c8;
	struct coord sp198[4];
	s32 sp194;

	s32 j2;
	s32 k;
	u32 *colours;
	struct gfxvtx *v0_2;
	f32 sp174;
	s32 numneighbours;
	s32 j;
	s32 p;
	f32 tmp1;
	f32 tmp2;
	f32 tmp3;
	struct coord sp15c;
	struct coord sp150;
	s16 sp128[20];
	struct coord sp108;
	struct coord spfc;
	struct coord spe4;
	struct coord spd4;

	u32 var8007f0e4 = 0xaaaaaa1f;
	u32 var8007f0e8 = 0x11111844;
	u32 var8007f0ec = 50;
	u32 var8007f0f0 = 2500;
	u32 var8007f0f4 = 1;
	u32 var8007f0f8 = 1;
	u32 var8007f0fc = 22000;

	spd80 = 1;
	s4 = 0;
	sp708 = 0;

	if (g_Vars.lvupdate240 <= 0) {
		spd80 = 0;
	}

	texSelect(&gdl, &g_TexGeneralConfigs[1], 2, 1, 2, 1, NULL);

	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetRenderMode(gdl++, G_RM_AA_ZB_XLU_SURF, G_RM_NOOP2);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureConvert(gdl++, G_TC_FILT);
	gDPSetCombineLERP(gdl++,
			0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0,
			0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0);

	particledata = weather->particledata[arg2];
	sp194 = 0;

	mtx4LoadIdentity(&sp1c8);
	mtx00015be0(g_Vars.currentplayer->worldtoscreenmtx, &sp1c8);

	sp1c8.m[3][0] = 0.0f;
	sp1c8.m[3][1] = 0.0f;
	sp1c8.m[3][2] = 0.0f;

	mtx = gfxAllocateMatrix();

	mtx00016054(&sp1c8, mtx);

	gSPMatrix(gdl++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	sp230.f[0] = g_Vars.currentplayer->cam_pos.f[0];
	sp230.f[1] = g_Vars.currentplayer->cam_pos.f[1];
	sp230.f[2] = g_Vars.currentplayer->cam_pos.f[2];

	sp224.f[0] = sp230.f[0] - particledata->unk3e80.f[0];
	sp224.f[1] = sp230.f[1] - particledata->unk3e80.f[1];
	sp224.f[2] = sp230.f[2] - particledata->unk3e80.f[2];

	if (absf(sp224.f[0]) > absf(particledata->boundarymin.f[0]) + absf(particledata->boundarymax.f[0])
			|| absf(sp224.f[1]) > absf(particledata->boundarymin.f[1]) + absf(particledata->boundarymax.f[1])
			|| absf(sp224.f[2]) > absf(particledata->boundarymin.f[2]) + absf(particledata->boundarymax.f[2])) {
		sp224.f[0] = particledata->boundaryrange.f[0] * 0.5f;
		sp224.f[1] = particledata->boundaryrange.f[1] * 0.5f;
		sp224.f[2] = particledata->boundaryrange.f[2] * 0.5f;
	}

	// 32b0
	for (p = 0; p < 500; p++) {
		particle = &particledata->particles[p];

		// x
		f0 = particle->pos.f[0] - particledata->boundarymin.f[0] - sp224.f[0];

		if (f0 < 0.0f) {
			f0 += particledata->boundaryrange.f[0];
		}

		if (f0 > particledata->boundaryrange.f[0]) {
			f0 -= particledata->boundaryrange.f[0];
		}

		particle->pos.f[0] = particledata->boundarymin.f[0] + f0;

		// y
		f0 = particle->pos.f[1] - particledata->boundarymin.f[1] - sp224.f[1];

		if (f0 < 0.0f) {
			f0 += particledata->boundaryrange.f[1];
		}

		if (f0 > particledata->boundaryrange.f[1]) {
			f0 -= particledata->boundaryrange.f[1];
		}

		particle->pos.f[1] = particledata->boundarymin.f[1] + f0;

		// z
		f0 = particle->pos.f[2] - particledata->boundarymin.f[2] - sp224.f[2];

		if (f0 < 0.0f) {
			f0 += particledata->boundaryrange.f[2];
		}

		if (f0 > particledata->boundaryrange.f[2]) {
			f0 -= particledata->boundaryrange.f[2];
		}

		particle->pos.f[2] = particledata->boundarymin.f[2] + f0;
	}

	// 33a4
	particledata->unk3e80.f[0] = sp230.f[0];
	particledata->unk3e80.f[1] = sp230.f[1];
	particledata->unk3e80.f[2] = sp230.f[2];

	if (weatherIsRoomWeatherProof(g_Vars.currentplayer->cam_room)) {
		if (weather->unk88 > 0.99f) {
			weather->unk8c = 0.65f;
			weather->unk90 = 9;
		}
	} else if (weather->unk88 < 0.66f) {
		weather->unk8c = 1.0f;
		weather->unk90 = 7;
	}

	// 3444
	if (g_Vars.lvupdate240 > 0) {
		g_SkyLightningActive = false;

		if (weather->unk94 < 0) {
			if (RANDOMFRAC() < weather->unkc4) {
				func0f131610(weather);
			}
		} else {
			// 34bc
			if (weather->unk98 - 1 == weather->unk94
					|| weather->unk9c - 1 == weather->unk94
					|| weather->unka0 - 1 == weather->unk94) {
				g_SkyLightningActive = true;
			}

			if (weather->unk98 == weather->unk94
					|| weather->unk9c == weather->unk94
					|| weather->unka0 == weather->unk94) {
				s1 = 150;

				if (weather->unk9c == weather->unk94) {
					s1 = 200;
				}

				// 3534
				for (s0 = 1; s0 < g_Vars.roomcount; s0++) {
					if (!weatherIsRoomWeatherProof(s0)) {
						roomSetUnk52(s0, s1);
					}
				}
			}

			// 3574
			if (weather->unka4 == weather->unk94) {
				s1_2 = 0x80ba;
				sp174 = RANDOMFRAC() * 1.5f + 0.4f;
				frac = RANDOMFRAC();

				if (frac);

				// 608
				if (frac <= 0.2f && frac > .1f) {
					s1_2 = 0x80bb;
				}

				// 63c
				if (frac <= 0.3f && frac > .2f) {
					s1_2 = 0x80bc;
				}

				if (frac <= 0.4f && frac > .3f) {
					s1_2 = 0x80bd;
				}

				if (frac <= 0.5f && frac > .4f) {
					s1_2 = 0x80be;
				}

				if (frac <= 0.6f && frac > .5f) {
					s1_2 = 0x80bf;
				}

				if (frac <= 0.7f && frac > .6f) {
					s1_2 = 0x80c0;
				}

				if (frac <= 0.8f && frac > .7f) {
					s1_2 = 0x80c1;
				}

				if (frac <= 0.9f && frac > .8f) {
					s1_2 = 0x80c2;
				}

				if (frac <= 1.0f && frac > .9f) {
					s1_2 = 0x80c3;
				}

				if (weather->audiohandles[3] == NULL) {
					weather->unkf8 = s1_2;
					sndStart(var80095200, s1_2, &weather->audiohandles[3], -1, -1, -1.0f, -1, -1);
					weather->unk58[3].unk00 = 1.f;

					if (weather->audiohandles[3] != NULL) {
						a2 = weather->unk88;

						if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
							a2 /= 2;
						}

						sndAdjust(&weather->audiohandles[3], 0, a2, -1, weather->unkf8, 1, 1, -1, 1);
						audioPostEvent(weather->audiohandles[3], 0x10, *(s32 *)&sp174);
					}
				}
			}

			weather->unk94++;

			if (weather->unk94 > 150) {
				weather->unk94 = -1;
			}
		}
	}

	// 38c4
	if (var8007f0f4) {
		sp150.f[0] = particledata->boundarymin.f[0] + g_Vars.currentplayer->cam_pos.f[0];
		sp15c.f[0] = particledata->boundarymax.f[0] + g_Vars.currentplayer->cam_pos.f[0];
		sp150.f[1] = particledata->boundarymin.f[1] + g_Vars.currentplayer->cam_pos.f[1];
		sp15c.f[1] = particledata->boundarymax.f[1] + g_Vars.currentplayer->cam_pos.f[1];
		sp150.f[2] = particledata->boundarymin.f[2] + g_Vars.currentplayer->cam_pos.f[2];
		sp15c.f[2] = particledata->boundarymax.f[2] + g_Vars.currentplayer->cam_pos.f[2];

		if (s4 < 50) {
			spcb8[s4] = g_Vars.currentplayer->cam_room;
			s4++;
		}

		spc84 = 1.0f;

		// 3950
		for (s2 = 0; s2 < s4; s2++) {
			numneighbours = roomGetNeighbours(spcb8[s2], sp128, ARRAYCOUNT(sp128));

			// 396c
			for (j2 = 0; j2 < numneighbours; j2++) {
				a0 = true;

				if (g_Rooms[sp128[j2]].flags & ROOMFLAG_ONSCREEN) {
					for (k = 0; k < s4; k++) {
						if (spcb8[k] == sp128[j2]) {
							a0 = false;
						}
					}

					if (a0) {
						if (sp15c.f[0] < g_Rooms[sp128[j2]].bbmin[0] || g_Rooms[sp128[j2]].bbmax[0] < sp150.f[0]) {
							a0 = false;
						}

						if (sp15c.f[1] < g_Rooms[sp128[j2]].bbmin[1] || g_Rooms[sp128[j2]].bbmax[1] < sp150.f[1]) {
							a0 = false;
						}

						if (sp15c.f[2] < g_Rooms[sp128[j2]].bbmin[2] || g_Rooms[sp128[j2]].bbmax[2] < sp150.f[2]) {
							a0 = false;
						}
					}

					if (a0 && s4 < 50) {
						spcb8[s4] = sp128[j2];
						s4++;
					}
				}
			}
		}

		// 3a98
		for (s2 = 0; s2 < s4; s2++) {
			if (weatherIsRoomWeatherProof(spcb8[s2])) {
				sp964[sp708].f[0] = g_Rooms[spcb8[s2]].bbmin[0] / 1.0f;
				sp964[sp708].f[1] = g_Rooms[spcb8[s2]].bbmin[1] / 1.0f;
				sp964[sp708].f[2] = g_Rooms[spcb8[s2]].bbmin[2] / 1.0f;

				sp70c[sp708].f[0] = g_Rooms[spcb8[s2]].bbmax[0] / 1.0f;
				sp70c[sp708].f[1] = g_Rooms[spcb8[s2]].bbmax[1] / 1.0f;
				sp70c[sp708].f[2] = g_Rooms[spcb8[s2]].bbmax[2] / 1.0f;

				if (sp708 < 50) {
					spbbc[sp708] = spcb8[s2];
					sp708++;
				}
			}
		}

		// 3b70
		for (s0 = 0; s0 < sp708; s0++) {
			if (spbbc[s0]);
			sp258[s0][0] = g_Rooms[spbbc[s0]].bbmin[0];
			sp258[s0][1] = g_Rooms[spbbc[s0]].bbmin[1];
			sp258[s0][2] = g_Rooms[spbbc[s0]].bbmin[2];
			sp258[s0][3] = g_Rooms[spbbc[s0]].bbmax[0];
			sp258[s0][4] = g_Rooms[spbbc[s0]].bbmax[1];
			sp258[s0][5] = g_Rooms[spbbc[s0]].bbmax[2];
		}
	}

	colours = gfxAllocateColours(2);
	colours[0] = var8007f0e4;
	colours[1] = var8007f0e8;

	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 2);

	// 3ca4
	for (p = 0; p < 500; p++) {
		s3 = 1;

		if (particledata->particles[p].active & 3) {
			sp108.f[0] = particledata->unk3e80.f[0] + particledata->particles[p].pos.f[0];
			sp108.f[1] = particledata->unk3e80.f[1] + particledata->particles[p].pos.f[1];
			sp108.f[2] = particledata->unk3e80.f[2] + particledata->particles[p].pos.f[2];

			if (cam0f0b5b9c(&sp108, 150)) {
				sp218[0] = particledata->particles[p].pos.f[0];
				sp218[1] = particledata->particles[p].pos.f[2];

				sp214 = sqrtf(sp218[0] * sp218[0] + sp218[1] * sp218[1]);

				if (sp214 < 0.0001f) {
					// empty
				} else {
					s32 tmp = sp194 * 3;

					if (sp194 == 0) {
						vertices = gfxAllocateVertices(12);
					}

					sp218[0] /= sp214;
					sp218[1] /= sp214;

					v0_2 = &vertices[tmp];

					for (j = 0; j < 4; j++) {
						v0_2[j].s = 0;
						v0_2[j].t = 0;

						sp198[j].f[0] = particledata->particles[p].pos.f[0];
						sp198[j].f[1] = particledata->particles[p].pos.f[1];
						sp198[j].f[2] = particledata->particles[p].pos.f[2];
					}

					// 3e0c
					if (var8007f0f4 && sp708 > 0) {
						spca8.f[0] = spc90.f[0] = (particledata->unk3e80.f[0] + particledata->particles[p].pos.f[0]) * spc84;
						spca8.f[1] = spc90.f[1] = (particledata->unk3e80.f[0] + particledata->particles[p].pos.f[1]) * spc84;
						spca8.f[2] = spc90.f[2] = (particledata->unk3e80.f[0] + particledata->particles[p].pos.f[2]) * spc84;

						spc9c.f[0] = (particledata->unk3e80.f[0] + (particledata->particles[p].pos.f[0] - (weather->windspeedx * (var8007f0ec / 10.0f)))) * spc84;
						spc9c.f[1] = (particledata->unk3e80.f[0] + (particledata->particles[p].pos.f[1] + weather->unkb8)) * spc84;
						spc9c.f[2] = (particledata->unk3e80.f[0] + (particledata->particles[p].pos.f[2] - (weather->windspeedz * (var8007f0ec / 10.0f)))) * spc84;

						spfc.f[0] = spc9c.f[0] - spc90.f[0];
						spfc.f[1] = spc9c.f[1] - spc90.f[1];
						spfc.f[2] = spc9c.f[2] - spc90.f[2];

						// 3f24
						if (spca8.f[0] < spc9c.f[0]) {
							tmp1 = spc9c.f[0];
							spc9c.f[0] = spca8.f[0];
							spca8.f[0] = tmp1;
						}

						if (spca8.f[1] < spc9c.f[1]) {
							tmp2 = spca8.f[1];
							spca8.f[1] = spc9c.f[1];
							spc9c.f[1] = tmp2;
						}

						if (spca8.f[2] < spc9c.f[2]) {
							tmp3 = spca8.f[2];
							spca8.f[2] = spc9c.f[2];
							spc9c.f[2] = tmp3;
						}

						// 3f84
						for (s0 = 0; s0 < sp708; s0++) {
							if (spc9c.f[0] <= g_Rooms[spbbc[s0]].bbmax[0]
									&& spca8.f[0] >= g_Rooms[spbbc[s0]].bbmin[0]
									&& spc9c.f[2] <= g_Rooms[spbbc[s0]].bbmax[2]
									&& spca8.f[2] >= g_Rooms[spbbc[s0]].bbmin[2]
									&& spc9c.f[1] <= g_Rooms[spbbc[s0]].bbmax[1]
									&& spca8.f[1] >= g_Rooms[spbbc[s0]].bbmin[1]
									&& var8007f0f8
									&& func0f15f20c(&spc90, &spfc, &sp258[s0][0], &sp258[s0][3])) {
								s3 = 0;
							}
						}
					}

					// 40b8
					if (s3) {
						temp_f2_7 = 1.0f + sp214 / (var8007f0f0 / 10.0f);

						sp198[0].f[0] += -sp218[1] * -temp_f2_7;
						sp198[0].f[2] += sp218[0] * -temp_f2_7;

						sp198[1].f[0] += -sp218[1] * temp_f2_7;
						sp198[1].f[2] += sp218[0] * temp_f2_7;

						sp198[3].f[0] -= weather->windspeedx * (var8007f0ec / 10.0f) + -sp218[1] * temp_f2_7;
						sp198[3].f[1] += weather->unkb8;
						sp198[3].f[2] -= weather->windspeedz * (var8007f0ec / 10.0f) + sp218[0] * temp_f2_7;

						sp198[2].f[0] -= weather->windspeedx * (var8007f0ec / 10.0f) + -sp218[1] * -temp_f2_7;
						sp198[2].f[1] += weather->unkb8;
						sp198[2].f[2] -= weather->windspeedz * (var8007f0ec / 10.0f) + sp218[0] * -temp_f2_7;

						v0_2[0].colour = 0;
						v0_2[1].colour = 0;
						v0_2[2].colour = 4;
						v0_2[3].colour = 4;

						if (spd80 > 0) {
							spe4.f[0] = (particledata->unk3e80.f[0] + particledata->particles[p].pos.f[0]) * spc84;
							spe4.f[1] = (particledata->unk3e80.f[1] + particledata->particles[p].pos.f[1]) * spc84;
							spe4.f[2] = (particledata->unk3e80.f[2] + particledata->particles[p].pos.f[2]) * spc84;

							for (s0 = 0; s0 < s4; s0++) {
								if (spe4.f[0] <= g_Rooms[spcb8[s0]].bbmax[0]
										&& spe4.f[0] >= g_Rooms[spcb8[s0]].bbmin[0]
										&& spe4.f[2] <= g_Rooms[spcb8[s0]].bbmax[2]
										&& spe4.f[2] >= g_Rooms[spcb8[s0]].bbmin[2]
										&& spe4.f[1] <= g_Rooms[spcb8[s0]].bbmax[1]
										&& spe4.f[1] >= g_Rooms[spcb8[s0]].bbmin[1]
										&& spe4.f[1] + spc84 * (particledata->particles[p].inc.f[1] * 1) < g_Rooms[spcb8[s0]].bbmin[1]) {
									spd4.f[0] = particledata->unk3e80.f[0] + particledata->particles[p].pos.f[0];
									spd4.f[1] = g_Rooms[spcb8[s0]].bbmin[1] / spc84;
									spd4.f[2] = particledata->unk3e80.f[2] + particledata->particles[p].pos.f[2];

									sparksCreate(spcb8[s0], NULL, &spd4, &particledata->particles[p].inc, NULL, SPARKTYPE_SHALLOWWATER);

									spd80--;
								}
							}
						}

						v0_2[0].s = 0;
						v0_2[0].t = 256;

						v0_2[1].s = 256;
						v0_2[1].t = 256;

						v0_2[2].s = 256;
						v0_2[2].t = 0;

						v0_2[3].s = 0;
						v0_2[3].t = 0;

						v0_2[0].x = sp198[0].f[0];
						v0_2[0].y = sp198[0].f[1];
						v0_2[0].z = sp198[0].f[2];

						v0_2[1].x = sp198[1].f[0];
						v0_2[1].y = sp198[1].f[1];
						v0_2[1].z = sp198[1].f[2];

						v0_2[2].x = sp198[2].f[0];
						v0_2[2].y = sp198[2].f[1];
						v0_2[2].z = sp198[2].f[2];

						if (sp194 == 3) {
							gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 12);
							gDPTri4(gdl++, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
							sp194 = 0;

						} else {
							sp194++;
						}
					}
				}
			}
		}
	}

	if (sp194 > 0) {
		gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 12);

		if (sp194 == 1) {
			gDPTri1(gdl++, 0, 1, 2);
		}

		if (sp194 == 2) {
			gDPTri2(gdl++, 0, 1, 2, 3, 4, 5);
		}

		if (sp194 == 3) {
			gDPTri3(gdl++, 0, 1, 2, 3, 4, 5, 6, 7, 8);
		}
	}

	return gdl;
}

static Gfx *weatherRenderSnow(Gfx *gdl, struct weatherdata *weather, s32 arg2)
{
	struct weatherparticledata *particledata;
	struct weatherparticle *particle;
	s32 j;
	s32 k;
	s32 s8;
	f32 tmp;
	u32 sp137c;
	u8 stack[0x3c];
	u32 sp1354;
	bool a0;
	bool s1;
	s32 sp126c[50];
	s32 sp1268;
	f32 sp1168[8][4][2];
	struct coord sp115c;
	struct coord sp1150;
	struct coord sp1144;
	s32 j2;
	s32 sp1078[50];
	struct coord spe20[50];
	struct coord spbc8[50];
	f32 f0_2;
	f32 sp264[50][12];
	f32 sp260;
	s32 s7;
	u32 *colours;
	f32 *fptr;
	f32 f0;
	s32 numneighbours;
	f32 f20;
	f32 f2;
	f32 f0_3;
	struct coord sp234;
	struct coord sp228;
	f32 f0_4;
	f32 sp220;
	f32 sp21c;
	Mtxf *mtx;
	struct gfxvtx *vertices; // 214
	struct gfxvtx *v0;
	struct gfxvtx *v0_2;
	Mtxf sp1cc;
	struct coord sp19c[4];
	s32 sp198;
	s32 stack3[3];
	f32 f24;
	s32 i; // 184
	struct coord sp178;
	struct coord sp16c;
	s16 sp144[20];
	struct coord sp124;
	struct coord sp118;
	f32 f26;
	f32 sp108;
	f32 f16;
	s32 index;
	s32 stack2[2];

	u32 var8007f100 = 50;
	u32 var8007f104 = 5;
	u32 var8007f108 = 10;
	u32 var8007f10c = 0x8888aaff;
	u32 var8007f110 = 0xffffff7f;

	s7 = 0;
	sp1268 = 0;

	texSelect(&gdl, &g_TexGeneralConfigs[0], 4, 0, 2, 1, NULL);

	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetRenderMode(gdl++, G_RM_AA_ZB_XLU_SURF, G_RM_NOOP2);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureConvert(gdl++, G_TC_FILT);
	gDPSetCombineLERP(gdl++,
			0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0,
			0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0);

	particledata = weather->particledata[arg2];

	sp198 = 0;

	mtx4LoadIdentity(&sp1cc);
	mtx00015be0(g_Vars.currentplayer->worldtoscreenmtx, &sp1cc);

	sp1cc.m[3][0] = 0.0f;
	sp1cc.m[3][1] = 0.0f;
	sp1cc.m[3][2] = 0.0f;

	mtx = gfxAllocateMatrix();

	mtx00016054(&sp1cc, mtx);

	gSPMatrix(gdl++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	sp234.f[0] = g_Vars.currentplayer->cam_pos.f[0];
	sp234.f[1] = g_Vars.currentplayer->cam_pos.f[1];
	sp234.f[2] = g_Vars.currentplayer->cam_pos.f[2];

	sp228.f[0] = sp234.f[0] - particledata->unk3e80.f[0];
	sp228.f[1] = sp234.f[1] - particledata->unk3e80.f[1];
	sp228.f[2] = sp234.f[2] - particledata->unk3e80.f[2];

	if (absf(sp228.f[0]) > absf(particledata->boundarymin.f[0]) + absf(particledata->boundarymax.f[0])
			|| absf(sp228.f[1]) > absf(particledata->boundarymin.f[1]) + absf(particledata->boundarymax.f[1])
			|| absf(sp228.f[2]) > absf(particledata->boundarymin.f[2]) + absf(particledata->boundarymax.f[2])) {
		sp228.f[0] = particledata->boundaryrange.f[0] * 0.5f;
		sp228.f[1] = particledata->boundaryrange.f[1] * 0.5f;
		sp228.f[2] = particledata->boundaryrange.f[2] * 0.5f;
	}

	// 4ac8
	for (s8 = 0; s8 < 500; s8++) {
		particle = &particledata->particles[s8];

		// x
		f0 = particle->pos.f[0] - particledata->boundarymin.f[0] - sp228.f[0];

		if (f0 < 0.0f) {
			f0 += particledata->boundaryrange.f[0];
		}

		if (f0 > particledata->boundaryrange.f[0]) {
			f0 -= particledata->boundaryrange.f[0];
		}

		particle->pos.f[0] = particledata->boundarymin.f[0] + f0;

		// y
		f0 = particle->pos.f[1] - particledata->boundarymin.f[1] - sp228.f[1];

		if (f0 < 0.0f) {
			f0 += particledata->boundaryrange.f[1];
		}

		if (f0 > particledata->boundaryrange.f[1]) {
			f0 -= particledata->boundaryrange.f[1];
		}

		particle->pos.f[1] = particledata->boundarymin.f[1] + f0;

		// z
		f0 = particle->pos.f[2] - particledata->boundarymin.f[2] - sp228.f[2];

		if (f0 < 0.0f) {
			f0 += particledata->boundaryrange.f[2];
		}

		if (f0 > particledata->boundaryrange.f[2]) {
			f0 -= particledata->boundaryrange.f[2];
		}

		particle->pos.f[2] = particledata->boundarymin.f[2] + f0;
	}

	// 4bbc
	particledata->unk3e80.f[0] = sp234.f[0];
	particledata->unk3e80.f[1] = sp234.f[1];
	particledata->unk3e80.f[2] = sp234.f[2];

	sp16c.f[0] = particledata->boundarymin.f[0] + g_Vars.currentplayer->cam_pos.f[0];
	sp178.f[0] = particledata->boundarymax.f[0] + g_Vars.currentplayer->cam_pos.f[0];
	sp16c.f[1] = particledata->boundarymin.f[1] + g_Vars.currentplayer->cam_pos.f[1];
	sp178.f[1] = particledata->boundarymax.f[1] + g_Vars.currentplayer->cam_pos.f[1];
	sp16c.f[2] = particledata->boundarymin.f[2] + g_Vars.currentplayer->cam_pos.f[2];
	sp178.f[2] = particledata->boundarymax.f[2] + g_Vars.currentplayer->cam_pos.f[2];

	if (sp1268 < 50) {
		sp126c[sp1268] = g_Vars.currentplayer->cam_room;
		sp1268++;
	}

	// 4c54
	for (i = 0; i < sp1268; i++) {
		numneighbours = roomGetNeighbours(sp126c[i], sp144, ARRAYCOUNT(sp144));

		for (j2 = 0; j2 < numneighbours; j2++) {
			a0 = true;

			if (g_Rooms[sp144[j2]].flags & ROOMFLAG_ONSCREEN) {
				for (k = 0; k < sp1268; k++) {
					if (sp126c[k] == sp144[j2]) {
						a0 = false;
					}
				}

				if (a0) {
					if (sp178.f[0] < g_Rooms[sp144[j2]].bbmin[0] || g_Rooms[sp144[j2]].bbmax[0] < sp16c.f[0]) {
						a0 = false;
					}

					if (sp178.f[1] < g_Rooms[sp144[j2]].bbmin[1] || g_Rooms[sp144[j2]].bbmax[1] < sp16c.f[1]) {
						a0 = false;
					}

					if (sp178.f[2] < g_Rooms[sp144[j2]].bbmin[2] || g_Rooms[sp144[j2]].bbmax[2] < sp16c.f[2]) {
						a0 = false;
					}
				}

				if (a0 && sp1268 < 50) {
					sp126c[sp1268] = sp144[j2];
					sp1268++;
				} else {
					// empty
				}
			}
		}
	}

	// 4dc0
	for (i = 0; i < sp1268; i++) {
		if (weatherIsRoomWeatherProof(sp126c[i])) {
			spe20[s7].f[0] = g_Rooms[sp126c[i]].bbmin[0] / 1;
			spe20[s7].f[1] = g_Rooms[sp126c[i]].bbmin[1] / 1;
			spe20[s7].f[2] = g_Rooms[sp126c[i]].bbmin[2] / 1;

			spbc8[s7].f[0] = g_Rooms[sp126c[i]].bbmax[0] / 1;
			spbc8[s7].f[1] = g_Rooms[sp126c[i]].bbmax[1] / 1;
			spbc8[s7].f[2] = g_Rooms[sp126c[i]].bbmax[2] / 1;

			if (s7 < 50) {
				sp1078[s7] = sp126c[i];
				s7++;
			} else {
				// empty
			}
		}
	}

	// 4ea4
	for (j = 0; j < s7; j++) {
		if (1);

		sp264[j][6] = sp264[j][0] = g_Rooms[sp1078[j]].bbmin[0] / 1 - var8007f104;
		sp264[j][9] = sp264[j][3] = g_Rooms[sp1078[j]].bbmax[0] / 1 + var8007f104;
		sp264[j][6] -= var8007f100;
		sp264[j][9] += var8007f100;

		sp264[j][7] = sp264[j][1] = g_Rooms[sp1078[j]].bbmin[1] / 1 - var8007f104;
		sp264[j][10] = sp264[j][4] = g_Rooms[sp1078[j]].bbmax[1] / 1 + var8007f104;
		sp264[j][7] -= var8007f100;
		sp264[j][10] += var8007f100;

		sp264[j][8] = sp264[j][2] = g_Rooms[sp1078[j]].bbmin[2] / 1 - var8007f104;
		sp264[j][11] = sp264[j][5] = g_Rooms[sp1078[j]].bbmax[2] / 1 + var8007f104;
		sp264[j][8] -= var8007f100;
		sp264[j][11] += var8007f100;
	}

	// 4ff0
	for (j = 0; j < 8; j++) {
		sp1168[j][0][0] = sinf(particledata->unk3ec8[j]);
		sp1168[j][0][1] = cosf(particledata->unk3ec8[j]);
		sp1168[j][1][0] = sinf(particledata->unk3ec8[j] + 1.5707963705063f);
		sp1168[j][1][1] = cosf(particledata->unk3ec8[j] + 1.5707963705063f);
		sp1168[j][2][0] = sinf(particledata->unk3ec8[j] + M_PI);
		sp1168[j][2][1] = cosf(particledata->unk3ec8[j] + M_PI);
		sp1168[j][3][0] = sinf(particledata->unk3ec8[j] + 4.7123889923096f);
		sp1168[j][3][1] = cosf(particledata->unk3ec8[j] + 4.7123889923096f);
	}

	// 514c
	colours = gfxAllocateColours(16);

	for (j = 0; j < 16; j++) {
		colours[j] = (var8007f10c & 0xffffff00) | ((0xff * 17 - j * 0xff) / 17);
	}

	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 16);

	// 51f8
	for (s8 = 0; s8 < 500; s8++) {
		s1 = true;

		if (particledata->particles[s8].active & 3) {
			sp124.f[0] = particledata->particles[s8].pos.f[0] + particledata->unk3e80.f[0];
			sp124.f[1] = particledata->particles[s8].pos.f[1] + particledata->unk3e80.f[1];
			sp124.f[2] = particledata->particles[s8].pos.f[2] + particledata->unk3e80.f[2];

			if (cam0f0b5b9c(&sp124, 5)) {
				sp21c = particledata->particles[s8].pos.f[0];
				sp220 = particledata->particles[s8].pos.f[2];

				f20 = sqrtf(sp220 * sp220 + sp21c * sp21c);

				if (f20 < 0.00001f) {
					// empty
				} else {
					s32 tmp2 = sp198 * 4;

					if (sp198 == 0) {
						vertices = gfxAllocateVertices(8);
					}

					v0_2 = &vertices[tmp2];

					sp260 = 0.0f;

					sp21c /= f20;
					sp220 /= f20;

					for (j = 0; j < 4; j++) {
						v0_2[j].s = 0;
						v0_2[j].t = 0;

						sp19c[j].f[0] = particledata->particles[s8].pos.f[0];
						sp19c[j].f[1] = particledata->particles[s8].pos.f[1];
						sp19c[j].f[2] = particledata->particles[s8].pos.f[2];
					}

					// 5344
					if (s7 > 0) {
						sp118.f[0] = particledata->particles[s8].pos.f[0] + particledata->unk3e80.f[0];
						sp118.f[1] = particledata->particles[s8].pos.f[1] + particledata->unk3e80.f[1];
						sp118.f[2] = particledata->particles[s8].pos.f[2] + particledata->unk3e80.f[2];

						for (j = 0; j < s7; j++) {
							// 5398
							if (s1
									&& sp264[j][6] < sp118.f[0]
									&& sp264[j][9] > sp118.f[0]
									&& sp264[j][7] < sp118.f[1]
									&& sp264[j][10] > sp118.f[1]
									&& sp264[j][8] < sp118.f[2]
									&& sp264[j][11] > sp118.f[2]) {
								if (sp264[j][0] < sp118.f[0]
										&& sp264[j][3] > sp118.f[0]
										&& sp264[j][1] < sp118.f[1]
										&& sp264[j][4] > sp118.f[1]
										&& sp264[j][2] < sp118.f[2]
										&& sp264[j][5] > sp118.f[2]) {
									s1 = false;
								} else {
									// 54a8
									f2 = 0.0f;

									// 54d8
									if (sp264[j][0] > sp118.f[0]) {
										f2 = sp118.f[0] - sp264[j][6];
									}

									// 54ec
									if (sp264[j][3] < sp118.f[0]) {
										f2 = sp118.f[0] - sp264[j][9];
									}

									// 5500
									tmp = absf(f2) / var8007f100;
									f2 = tmp;

									// 5524
									if (tmp > sp260) {
										sp260 = tmp;
									}

									if (sp264[j][2] > sp118.f[2]) {
										f2 = sp118.f[2] - sp264[j][8];
									}

									if (sp264[j][5] < sp118.f[2]) {
										f2 = sp118.f[2] - sp264[j][11];
									}

									f2 = absf(f2) / var8007f100;

									if (f2 > sp260) {
										sp260 = f2;
									}
								}
							}
						}
					}

					// 559c
					if (s1) {
						s32 j;

						f0_3 = sqrtf(particledata->particles[s8].pos.f[0] * particledata->particles[s8].pos.f[0]
								+ particledata->particles[s8].pos.f[1] * particledata->particles[s8].pos.f[1]
								+ particledata->particles[s8].pos.f[2] * particledata->particles[s8].pos.f[2]);

						f24 = particledata->particles[s8].pos.f[0] / f0_3;
						sp108 = particledata->particles[s8].pos.f[1] / f0_3;
						f26 = particledata->particles[s8].pos.f[2] / f0_3;

						// 55fc
						f0_4 = sqrtf(f24 * f24 + f26 * f26);

						sp1144.f[0] = sp108 * (f26 / f0_4);
						sp1144.f[1] = -f0_4;
						sp1144.f[2] = sp108 * (f24 / f0_4);

						sp115c.f[0] = -sp220;
						sp115c.f[1] = 1.0f;
						sp115c.f[2] = sp21c;

						// 5720
						index = (s8 >> 2) & 7;

						for (j = 0; j < 4; j++) {
							f32 a;
							f32 b;
							f32 c;

							a = var8007f104 * (f26 / f0_4) * sp1168[index][j][0];
							b = 0.0f;
							c = var8007f104 * -(f24 / f0_4) * sp1168[index][j][0];

							a += var8007f104 * sp1144.f[2] * sp1168[index][j][1];
							b += var8007f104 * sp1144.f[1] * sp1168[index][j][1];
							c += var8007f104 * sp1144.f[0] * sp1168[index][j][1];

							sp19c[j].f[1] += b;
							sp19c[j].f[0] += a;
							sp19c[j].f[2] += c;
						}

						// 5784
						// x
						f16 = 0.0f;

						if (particledata->particles[s8].pos.f[0] < particledata->boundarymin.f[0] + 150.0f) {
							f16 = particledata->particles[s8].pos.f[0] - particledata->boundarymin.f[0] - 150.0f;
						}

						if (particledata->particles[s8].pos.f[0] > particledata->boundarymax.f[0] - 150.0f) {
							f16 = particledata->particles[s8].pos.f[0] - particledata->boundarymax.f[0] + 150.0f;
						}

						f16 = absf(f16) / 150.0f;

						if (f16 > sp260) {
							sp260 = f16;
						}

						// 5870
						// y
						f16 = 0.0f;

						if (particledata->particles[s8].pos.f[1] < particledata->boundarymin.f[1] + 150.0f) {
							f16 = particledata->particles[s8].pos.f[1] - particledata->boundarymin.f[1] - 150.0f;
						}

						if (particledata->particles[s8].pos.f[1] > particledata->boundarymax.f[1] - 150.0f) {
							f16 = particledata->particles[s8].pos.f[1] - particledata->boundarymax.f[1] + 150.0f;
						}

						f16 = absf(f16) / 150.0f;

						if (f16 > sp260) {
							sp260 = f16;
						}

						// 58f8
						// z
						f16 = 0.0f;

						if (particledata->particles[s8].pos.f[2] < particledata->boundarymin.f[2] + 150.0f) {
							f16 = particledata->particles[s8].pos.f[2] - particledata->boundarymin.f[2] - 150.0f;
						}

						if (particledata->particles[s8].pos.f[2] > particledata->boundarymax.f[2] - 150.0f) {
							f16 = particledata->particles[s8].pos.f[2] - particledata->boundarymax.f[2] + 150.0f;
						}

						f16 = absf(f16) / 150.0f;

						if (f16 > sp260) {
							sp260 = f16;
						}

						// 5978
						{
							s16 a;
							s16 b;

							b = (s16) (((s8 & 2) >> 1) * 8);
							a = (s16) ((s8 & 1) * 8);

							vertices[sp198 * 4 + 0].colour = (s32) (sp260 * 16.0f) * 4;
							vertices[sp198 * 4 + 1].colour = (s32) (sp260 * 16.0f) * 4;
							vertices[sp198 * 4 + 2].colour = (s32) (sp260 * 16.0f) * 4;
							vertices[sp198 * 4 + 3].colour = (s32) (sp260 * 16.0f) * 4;

							vertices[sp198 * 4 + 0].s = (s16) (a) * 32;
							vertices[sp198 * 4 + 1].s = (s16) (a + 8) * 32;
							vertices[sp198 * 4 + 2].s = (s16) (a + 8) * 32;
							vertices[sp198 * 4 + 3].s = (s16) (a) * 32;

							vertices[sp198 * 4 + 0].t = (s16) (b + 8) * 32;
							vertices[sp198 * 4 + 1].t = (s16) (b + 8) * 32;
							vertices[sp198 * 4 + 2].t = (s16) (b) * 32;
							vertices[sp198 * 4 + 3].t = (s16) (b) * 32;
						}

						vertices[sp198 * 4 + 0].x = sp19c[0].f[0];
						vertices[sp198 * 4 + 0].y = sp19c[0].f[1];
						vertices[sp198 * 4 + 0].z = sp19c[0].f[2];

						vertices[sp198 * 4 + 1].x = sp19c[1].f[0];
						vertices[sp198 * 4 + 1].y = sp19c[1].f[1];
						vertices[sp198 * 4 + 1].z = sp19c[1].f[2];

						vertices[sp198 * 4 + 2].x = sp19c[2].f[0];
						vertices[sp198 * 4 + 2].y = sp19c[2].f[1];
						vertices[sp198 * 4 + 2].z = sp19c[2].f[2];

						vertices[sp198 * 4 + 3].x = sp19c[3].f[0];
						vertices[sp198 * 4 + 3].y = sp19c[3].f[1];
						vertices[sp198 * 4 + 3].z = sp19c[3].f[2];

						if (sp198 == 1) {
							gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 8);
							gDPTri4(gdl++, 0, 1, 2, 2, 3, 0, 4, 5, 6, 6, 7, 4);
							sp198 = 0;
						} else {
							sp198 = 1;
						}
					}
				}
			}
		}
	}

	if (sp198 > 0) {
		gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 8);
		gDPTri2(gdl++, 0, 1, 2, 2, 3, 0);
	}

	return gdl;
}

void weatherStop(void)
{
	if (g_WeatherData) {
		if (g_WeatherData->audiohandles[0]) {
			audioStop(g_WeatherData->audiohandles[0]);
		}

		if (g_WeatherData->audiohandles[1]) {
			audioStop(g_WeatherData->audiohandles[1]);
		}

		if (g_WeatherData->audiohandles[2]) {
			audioStop(g_WeatherData->audiohandles[2]);
		}

		if (g_WeatherData->audiohandles[3]) {
			audioStop(g_WeatherData->audiohandles[3]);
		}

		g_WeatherData = NULL;
	}
}
