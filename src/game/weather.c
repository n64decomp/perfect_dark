#include <ultra64.h>
#include "constants.h"
#include "../lib/naudio/n_sndp.h"
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

#define ABSF(val) ((val) > 0.0f ? (val) : -(val))

struct weatherdata *g_WeatherData = NULL;

Gfx *weather_render_rain(Gfx *gdl, struct weatherdata *weather, s32 arg2);
Gfx *weather_render_snow(Gfx *gdl, struct weatherdata *weather, s32 arg2);

Gfx *weather_render(Gfx *gdl)
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
		tex_select(&gdl, &g_TexGeneralConfigs[1], 2, 1, 2, 1, NULL);

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
		gdl = weather_render_rain(gdl, weather, 0);
		break;
	case WEATHERTYPE_SNOW:
		gdl = weather_render_snow(gdl, weather, 0);
		break;
	}

	return gdl;
}

void weather_set_boundaries(struct weatherparticledata *data, s32 index, f32 min, f32 max)
{
	((f32 *)(&data->boundarymin))[index] = min;
	((f32 *)(&data->boundarymax))[index] = max;
	((f32 *)(&data->boundaryrange))[index] = ABS(min) + ABS(max);
}

struct weatherparticledata *weather_allocate_particles(void)
{
	struct weatherparticledata *data = memp_alloc(sizeof(struct weatherparticledata), MEMPOOL_STAGE);
	u32 i;

	data->unk3e80.x = 0;
	data->unk3e80.y = 0;
	data->unk3e80.z = 0;

	weather_set_boundaries(data, 0, -800, 800);

	if ((u32)g_StageIndex == STAGEINDEX_CRASHSITE) {
		weather_set_boundaries(data, 1, -500, 500);
	} else {
		weather_set_boundaries(data, 1, -800, 800);
	}

	weather_set_boundaries(data, 2, -800, 800);

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

void func0f131610(struct weatherdata *weather)
{
	weather->unk94 = 0;
	weather->unk98 = (random() & 7) + 1;
	weather->unk9c = (random() & 7) + 1;
	weather->unka0 = (random() & 7) + 1;
	weather->unka4 = (random() & 0xf) + 10;
}

void func0f131678(s32 arg0)
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

void weather_set_intensity(s32 intensity)
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

u32 g_RainSpeedExtra;
u32 g_SnowSpeed;
u32 g_SnowSpeedExtra;

void weather_tick_rain(struct weatherdata *weather)
{ \
	s32 lVar6 = 0;
	s32 relativetotal = 0; // eg. -10 if deleted 10 particles, +10 if created 10
	struct weatherparticledata *data;
	s32 i;
	s32 iVar10;
	f32 rand;
	s32 lvupdate;

	main_override_variable("rainspeedxtra", &g_RainSpeedExtra);

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
			SFX_80B7,
			SFX_80B6,
			SFX_80B8,
			-1,
		};

		iVar10 = weather->unk58[i].unk00 * 32767.0f * weather->unk88;

		if (lv_is_paused()) {
			 iVar10 = 0;
		}

		if (iVar10 > 0) {
			if (weather->audiohandles[i] == 0 && sounds[i] >= 0) {
				weather->unkf8 = sounds[i];
				snd_start(var80095200, weather->unkf8, &weather->audiohandles[i], -1,
						-1, -1, -1, -1);
			}

			if (weather->audiohandles[i] != 0) {
				if (sndGetState(weather->audiohandles[i]) != AL_STOPPED) {
					snd_adjust(&weather->audiohandles[i], 0, iVar10 * 3 / 4, -1,
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
		weather->windanglerad = DTOR(90);
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

		if (weather->windanglerad > DTOR(360)) {
			weather->windanglerad = 0;
		}

		weather->windspeedx = cosf(weather->windanglerad) * weather->windspeed;
		weather->windspeedz = sinf(weather->windanglerad) * weather->windspeed;
		lVar6 = 1;
	} else if (RANDOMFRAC() > 0.99f) {
		rand = RANDOMFRAC();

		weather->unk0c = (rand + rand) * DTOR(180);
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
			particle->pos.x = data->boundarymin.x + RANDOMFRAC() * (ABS(data->boundarymin.x) + ABS(data->boundarymax.x));
			particle->pos.z = data->boundarymin.z + RANDOMFRAC() * (ABS(data->boundarymin.z) + ABS(data->boundarymax.z));

			particle->unk1c = RANDOMFRAC() + 0.7f;

			particle->inc.y = -(RANDOMFRAC() * g_RainSpeedExtra + weather->unkc8);

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

u32 g_RainSpeedExtra = 20;
u32 g_SnowSpeed = 15;
u32 g_SnowSpeedExtra = 10;

void weather_tick_snow(struct weatherdata *weather)
{ \
	s32 lVar7 = 0;
	s32 relativetotal = 0; // eg. -10 if deleted 10 particles, +10 if created 10
	f32 rand;
	s32 lvupdate;
	s32 i;
	struct weatherparticledata *data;

	main_override_variable("snowspeed", &g_SnowSpeed);
	main_override_variable("snowspeedxtra", &g_SnowSpeedExtra);

	if (g_StageIndex == STAGEINDEX_AIRBASE) {
		weather->windanglerad = DTOR(90);
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

		if (weather->windanglerad > DTOR(360)) {
			weather->windanglerad = 0;
		}

		weather->windspeedx = cosf(weather->windanglerad) * weather->windspeed;
		weather->windspeedz = sinf(weather->windanglerad) * weather->windspeed;
		lVar7 = 1;
	} else if (RANDOMFRAC() > 0.99f) {
		rand = RANDOMFRAC();

		weather->unk0c = (rand + rand) * DTOR(180);
		weather->unk10 = (weather->unk0c - weather->windanglerad) / (PAL ? 0.012f : 0.01f);

		if (weather->unk10 < 0) {
			weather->unk10 = -weather->unk10;
		}
	}

	data = g_WeatherData->particledata[0];

	// 0
	data->unk3ec8[0] += 0.04f * LVUPDATE60FREAL();

	if (data->unk3ec8[0] < 0) {
		data->unk3ec8[0] += DTOR(360);
	}

	if (data->unk3ec8[0] > DTOR(360)) {
		data->unk3ec8[0] -= DTOR(360);
	}

	// 1
	data->unk3ec8[1] += -0.03f * LVUPDATE60FREAL();

	if (data->unk3ec8[1] < 0) {
		data->unk3ec8[1] += DTOR(360);
	}

	if (data->unk3ec8[1] > DTOR(360)) {
		data->unk3ec8[1] -= DTOR(360);
	}

	// 2
	data->unk3ec8[2] += 0.04f * LVUPDATE60FREAL();

	if (data->unk3ec8[2] < 0) {
		data->unk3ec8[2] += DTOR(360);
	}

	if (data->unk3ec8[2] > DTOR(360)) {
		data->unk3ec8[2] -= DTOR(360);
	}

	// 3
	data->unk3ec8[3] += 0.03f * LVUPDATE60FREAL();

	if (data->unk3ec8[3] < 0) {
		data->unk3ec8[3] += DTOR(360);
	}

	if (data->unk3ec8[3] > DTOR(360)) {
		data->unk3ec8[3] -= DTOR(360);
	}

	// 4
	data->unk3ec8[4] += 0.02f * LVUPDATE60FREAL();

	if (data->unk3ec8[4] < 0) {
		data->unk3ec8[4] += DTOR(360);
	}

	if (data->unk3ec8[4] > DTOR(360)) {
		data->unk3ec8[4] -= DTOR(360);
	}

	// 5
	data->unk3ec8[5] += 0.01f * LVUPDATE60FREAL();

	if (data->unk3ec8[5] < 0) {
		data->unk3ec8[5] += DTOR(360);
	}

	if (data->unk3ec8[5] > DTOR(360)) {
		data->unk3ec8[5] -= DTOR(360);
	}

	// 6
	data->unk3ec8[6] += -0.01f * LVUPDATE60FREAL();

	if (data->unk3ec8[6] < 0) {
		data->unk3ec8[6] += DTOR(360);
	}

	if (data->unk3ec8[6] > DTOR(360)) {
		data->unk3ec8[6] -= DTOR(360);
	}

	// 7
	data->unk3ec8[7] += -0.02f * LVUPDATE60FREAL();

	if (data->unk3ec8[7] < 0) {
		data->unk3ec8[7] += DTOR(360);
	}

	if (data->unk3ec8[7] > DTOR(360)) {
		data->unk3ec8[7] -= DTOR(360);
	}

	for (i = 0; i < ARRAYCOUNT(data->particles); i++) {
		struct weatherparticle *particle = &data->particles[i];

		particle->pos.x += particle->inc.x * LVUPDATE60FREAL();
		particle->pos.y += particle->inc.y * LVUPDATE60FREAL();
		particle->pos.z += particle->inc.z * LVUPDATE60FREAL();

		if (particle->pos.y < data->boundarymin.y) {
			lVar7 = 2;

			particle->pos.x = data->boundarymin.f[0] + RANDOMFRAC() * (ABS(data->boundarymin.f[0]) + ABS(data->boundarymax.f[0]));
			particle->pos.z = data->boundarymin.f[2] + RANDOMFRAC() * (ABS(data->boundarymin.f[2]) + ABS(data->boundarymax.f[2]));

			particle->unk1c = RANDOMFRAC() + 0.7f;

			particle->inc.y = -(g_SnowSpeed / 10.0f) - (RANDOMFRAC() * g_SnowSpeedExtra) / 10.0f;
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

void weather_configure_rain(u32 intensity)
{
	if (g_WeatherData) {
		g_WeatherData->type = WEATHERTYPE_RAIN;
		weather_set_intensity(intensity);
	}
}

void weather_configure_snow(u32 intensity)
{
	if (g_WeatherData) {
		g_WeatherData->type = WEATHERTYPE_SNOW;
		weather_set_intensity(intensity);
	}
}

bool weather_is_room_weatherproof(s32 room)
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

Gfx *weather_render_rain(Gfx *gdl, struct weatherdata *weather, s32 arg2)
{
	s32 numtestrooms;
	u32 stack;
	s32 p;
	s32 i;
	s32 timings1[10];
	struct weatherparticledata *particledata;
	Mtxf *mtx;
	struct weatherparticle *particle;
	s32 timings2[8];
	s32 numsparksavailable;
	s32 testrooms[50];
	f32 f0;
	struct coord spca8;
	struct coord spc9c;
	struct coord spc90;
	s32 brightness;
	s32 soundnum;
	f32 scale;
	s32 badrooms[50];
	struct coord badbbmin[50];
	struct coord badbbmax[50];
	s32 numbadrooms;
	s32 bboxes[50][6];

	static u32 rainwidth = 1;
	static u32 raincol1 = 0xaaaaaa1f;
	static u32 raincol2 = 0x11111844;
	static u32 rainout = 50;
	static u32 cddiv = 2500;
	static u32 wetclip = 1;
	static u32 bounder = 1;
	static u32 trypitch = 22000;

	numsparksavailable = 1;
	numtestrooms = 0;
	numbadrooms = 0;

	main_override_variable("raincol1", &raincol1);
	main_override_variable("raincol2", &raincol2);
	main_override_variable("rainwidth", &rainwidth);
	main_override_variable("rainout", &rainout);
	main_override_variable("cddiv", &cddiv);
	main_override_variable("wetclip", &wetclip);
	main_override_variable("bounder", &bounder);
	main_override_variable("trypitch", &trypitch);

	if (g_Vars.lvupdate240 <= 0) {
		numsparksavailable = 0;
	}

	osGetCount();

	for (i = 0; i < ARRAYCOUNT(timings1); i++) {
		timings1[i] = 0;
	}

	tex_select(&gdl, &g_TexGeneralConfigs[1], 2, 1, 2, 1, NULL);

	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetRenderMode(gdl++, G_RM_AA_ZB_XLU_SURF, G_RM_NOOP2);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureConvert(gdl++, G_TC_FILT);
	gDPSetCombineLERP(gdl++,
			0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0,
			0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0);

	{
		struct coord campos;
		struct coord sp224;
		s32 numneighbours;
		f32 sp218[2];
		f32 sp214;
		Vtx *vertices;
		s32 n;
		bool ok;
		Mtxf worldtoscreenmtx;
		struct coord positions[4];
		s32 numtris;
		f32 cddiv2;
		f32 rainout2;
		f32 f2;
		f32 frac;
		s32 volume;
		s32 t;
		s32 j;
		f32 pitch;
		Col *colours;
		f32 tmp;
		u32 stack2;
		struct coord distcamtobbmax;
		struct coord distcamtobbmin;
		RoomNum neighbours[20];

		particledata = weather->particledata[arg2];
		numtris = 0;

		mtx4_load_identity(&worldtoscreenmtx);
		mtx00015be0(cam_get_world_to_screen_mtxf(), &worldtoscreenmtx);

		worldtoscreenmtx.m[3][0] = 0.0f;
		worldtoscreenmtx.m[3][1] = 0.0f;
		worldtoscreenmtx.m[3][2] = 0.0f;

		mtx = gfx_allocate_matrix();

		mtx_f2l(&worldtoscreenmtx, mtx);

		gSPMatrix(gdl++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

		campos.f[0] = g_Vars.currentplayer->cam_pos.f[0];
		campos.f[1] = g_Vars.currentplayer->cam_pos.f[1];
		campos.f[2] = g_Vars.currentplayer->cam_pos.f[2];

		sp224.f[0] = campos.f[0] - particledata->unk3e80.f[0];
		sp224.f[1] = campos.f[1] - particledata->unk3e80.f[1];
		sp224.f[2] = campos.f[2] - particledata->unk3e80.f[2];

		if (ABSF(sp224.f[0]) > ABSF(particledata->boundarymin.f[0]) + ABSF(particledata->boundarymax.f[0])
				|| ABSF(sp224.f[1]) > ABSF(particledata->boundarymin.f[1]) + ABSF(particledata->boundarymax.f[1])
				|| ABSF(sp224.f[2]) > ABSF(particledata->boundarymin.f[2]) + ABSF(particledata->boundarymax.f[2])) {
			sp224.f[0] = particledata->boundaryrange.f[0] / 2.0f;
			sp224.f[1] = particledata->boundaryrange.f[1] / 2.0f;
			sp224.f[2] = particledata->boundaryrange.f[2] / 2.0f;
		}

		for (p = 0; p < ARRAYCOUNT(particledata->particles); p++) {
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

		particledata->unk3e80.f[0] = campos.f[0];
		particledata->unk3e80.f[1] = campos.f[1];
		particledata->unk3e80.f[2] = campos.f[2];

		// Increase or decrease rain volume depending on whether the camera
		// is in a weatherproof room or not.
		if (weather_is_room_weatherproof(g_Vars.currentplayer->cam_room)) {
			if (weather->unk88 > 0.99f) {
				weather->unk8c = 0.65f;
				weather->unk90 = 9;
			}
		} else {
			if (weather->unk88 < 0.66f) {
				weather->unk8c = 1.0f;
				weather->unk90 = 7;
			}
		}

		// Update thunder and lightning
		if (g_Vars.lvupdate240 > 0) {
			g_SkyLightningActive = false;

			if (weather->unk94 < 0) {
				if (RANDOMFRAC() < weather->unkc4) {
					func0f131610(weather);
				}
			} else {
				if (weather->unk98 - 1 == weather->unk94
						|| weather->unk9c - 1 == weather->unk94
						|| weather->unka0 - 1 == weather->unk94) {
					g_SkyLightningActive = true;
				}

				if (weather->unk98 == weather->unk94
						|| weather->unk9c == weather->unk94
						|| weather->unka0 == weather->unk94) {
					brightness = 150;

					if (weather->unk9c == weather->unk94) {
						brightness = 200;
					}

					for (i = 1; i < g_Vars.roomcount; i++) {
						if (!weather_is_room_weatherproof(i)) {
							room_set_flash_brightness(i, brightness);
						}
					}
				}

				if (weather->unka4 == weather->unk94) {
					soundnum = SFX_80BA_THUNDER;
					pitch = 0.4f + RANDOMFRAC() * 1.5f;
					frac = RANDOMFRAC();

					if (frac <= 0.2f && frac > .1f) {
						soundnum = SFX_80BB_THUNDER;
					}

					if (frac <= 0.3f && frac > 0.20000001788139f) {
						soundnum = SFX_80BC_THUNDER;
					}

					if (frac <= 0.4f && frac > .3f) {
						soundnum = SFX_80BD_THUNDER;
					}

					if (frac <= 0.5f && frac > .4f) {
						soundnum = SFX_80BE_THUNDER;
					}

					if (frac <= 0.6f && frac > .5f) {
						soundnum = SFX_80BF_LIGHTNING;
					}

					if (frac <= 0.7f && frac > 0.59999996423721f) {
						soundnum = SFX_80C0_LIGHTNING;
					}

					if (frac <= 0.8f && frac > .7f) {
						soundnum = SFX_80C1_LIGHTNING;
					}

					if (frac <= 0.9f && frac > 0.79999995231628f) {
						soundnum = SFX_80C2_LIGHTNING;
					}

					if (frac <= 1.0f && frac > .9f) {
						soundnum = SFX_80C3_LIGHTNING;
					}

					if (weather->audiohandles[3] == NULL) {
						weather->unkf8 = soundnum;
						snd_start(var80095200, soundnum, &weather->audiohandles[3], -1, -1, -1, -1, -1);
						weather->unk58[3].unk00 = 1;

						if (weather->audiohandles[3] != NULL) {
							volume = weather->unk88;

							if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
								volume /= 2;
							}

							snd_adjust(&weather->audiohandles[3], 0, volume, -1, weather->unkf8, 1.00f, 1, -1, 1);
							audioPostEvent(weather->audiohandles[3], AL_SNDP_PITCH_EVT, *(s32 *)&pitch);
						}
					}
				}

				weather->unk94++;

				if (weather->unk94 > 150) {
					weather->unk94 = -1;
				}
			}
		}

		if (wetclip) {
			distcamtobbmin.f[0] = particledata->boundarymin.f[0] + g_Vars.currentplayer->cam_pos.f[0];
			distcamtobbmax.f[0] = particledata->boundarymax.f[0] + g_Vars.currentplayer->cam_pos.f[0];
			distcamtobbmin.f[1] = particledata->boundarymin.f[1] + g_Vars.currentplayer->cam_pos.f[1];
			distcamtobbmax.f[1] = particledata->boundarymax.f[1] + g_Vars.currentplayer->cam_pos.f[1];
			distcamtobbmin.f[2] = particledata->boundarymin.f[2] + g_Vars.currentplayer->cam_pos.f[2];
			distcamtobbmax.f[2] = particledata->boundarymax.f[2] + g_Vars.currentplayer->cam_pos.f[2];

			if (numtestrooms < ARRAYCOUNT(testrooms)) {
				testrooms[numtestrooms] = g_Vars.currentplayer->cam_room;
				numtestrooms++;
			}

			for (scale = 1.0f, t = 0; t < numtestrooms; t++) {
				numneighbours = bg_room_get_neighbours(testrooms[t], neighbours, ARRAYCOUNT(neighbours));

				for (n = 0; n < numneighbours; n++) {
					if (g_Rooms[neighbours[n]].flags & ROOMFLAG_ONSCREEN) {
						ok = true;

						for (j = 0; j < numtestrooms; j++) {
							if (testrooms[j] == neighbours[n]) {
								ok = false;
							}
						}

						if (ok) {
							if (distcamtobbmax.f[0] < g_Rooms[neighbours[n]].bbmin[0] || distcamtobbmin.f[0] > g_Rooms[neighbours[n]].bbmax[0]) {
								ok = false;
							}

							if (distcamtobbmax.f[1] < g_Rooms[neighbours[n]].bbmin[1] || distcamtobbmin.f[1] > g_Rooms[neighbours[n]].bbmax[1]) {
								ok = false;
							}

							if (distcamtobbmax.f[2] < g_Rooms[neighbours[n]].bbmin[2] || distcamtobbmin.f[2] > g_Rooms[neighbours[n]].bbmax[2]) {
								ok = false;
							}
						}

						if (ok) {
							if (numtestrooms < ARRAYCOUNT(testrooms)) {
								testrooms[numtestrooms] = neighbours[n];
								numtestrooms++;
							} else {
								// empty
							}
						}
					}
				}
			}

			for (t = 0; t < numtestrooms; t++) {
				if (weather_is_room_weatherproof(testrooms[t])) {
					// @bug: Overflowing badbbmin and badbbmax if badrooms is full.
					// (These writes should be inside the if statement).
					badbbmin[numbadrooms].f[0] = g_Rooms[testrooms[t]].bbmin[0] / scale;
					badbbmin[numbadrooms].f[1] = g_Rooms[testrooms[t]].bbmin[1] / scale;
					badbbmin[numbadrooms].f[2] = g_Rooms[testrooms[t]].bbmin[2] / scale;

					badbbmax[numbadrooms].f[0] = g_Rooms[testrooms[t]].bbmax[0] / scale;
					badbbmax[numbadrooms].f[1] = g_Rooms[testrooms[t]].bbmax[1] / scale;
					badbbmax[numbadrooms].f[2] = g_Rooms[testrooms[t]].bbmax[2] / scale;

					if (numbadrooms < ARRAYCOUNT(badrooms)) {
						badrooms[numbadrooms] = testrooms[t];
						numbadrooms++;
					}
				}

				if (1);
			}

			for (i = 0; i < numbadrooms; i++) {
				bboxes[i][0] = g_Rooms[badrooms[i]].bbmin[0];
				bboxes[i][1] = g_Rooms[badrooms[i]].bbmin[1];
				bboxes[i][2] = g_Rooms[badrooms[i]].bbmin[2];
				bboxes[i][3] = g_Rooms[badrooms[i]].bbmax[0];
				bboxes[i][4] = g_Rooms[badrooms[i]].bbmax[1];
				bboxes[i][5] = g_Rooms[badrooms[i]].bbmax[2];
			}
		}

		colours = gfx_allocate_colours(2);
		colours[0].word = raincol1;
		colours[1].word = raincol2;

		gSPColor(gdl++, osVirtualToPhysical(colours), 2);

		timings2[0] = osGetCount();

		for (p = 0; p < ARRAYCOUNT(particledata->particles); p++) {
			u32 stack[3];
			struct coord sp108;
			struct coord spfc;
			u32 stack2;
			struct weatherparticle *particle2 = &particledata->particles[p];
			s32 vtxindex = numtris * 3;
			struct coord spe4;
			bool draw = true;
			struct coord spd4;

			if (particle2->active & 3) {
				timings2[7] = osGetCount();

				sp108.f[0] = particle2->pos.f[0] + particledata->unk3e80.f[0];
				sp108.f[1] = particle2->pos.f[1] + particledata->unk3e80.f[1];
				sp108.f[2] = particle2->pos.f[2] + particledata->unk3e80.f[2];

				if (cam0f0b5b9c(&sp108, 150)) {
					timings1[7] = timings1[7] + osGetCount() - timings2[7];

					sp218[0] = particle2->pos.f[0];
					sp218[1] = particle2->pos.f[2];

					sp214 = sqrtf(sp218[0] * sp218[0] + sp218[1] * sp218[1]);

					if (sp214 < 0.00001f) {
						// empty
					} else {
						if (numtris == 0) {
							vertices = gfx_allocate_vertices(12);
						}

						sp218[0] /= sp214;
						sp218[1] /= sp214;

						for (i = 0; i < 4; i++) {
							vertices[i + vtxindex].s = 0;
							vertices[i + vtxindex].t = 0;

							positions[i].f[0] = particle2->pos.f[0];
							positions[i].f[1] = particle2->pos.f[1];
							positions[i].f[2] = particle2->pos.f[2];
						}

						timings2[1] = osGetCount();
						timings2[2] = osGetCount();

						if (wetclip && numbadrooms > 0) {
							spca8.f[0] = spc90.f[0] = (particle2->pos.f[0] + particledata->unk3e80.f[0]) * scale;
							spca8.f[1] = spc90.f[1] = (particle2->pos.f[1] + particledata->unk3e80.f[1]) * scale;
							spca8.f[2] = spc90.f[2] = (particle2->pos.f[2] + particledata->unk3e80.f[2]) * scale;

							spc9c.f[0] = ((particle2->pos.f[0] - (weather->windspeedx * (rainout / 10.0f))) + particledata->unk3e80.f[0]) * scale;
							spc9c.f[1] = ((particle2->pos.f[1] + weather->unkb8) + particledata->unk3e80.f[1]) * scale;
							spc9c.f[2] = ((particle2->pos.f[2] - (weather->windspeedz * (rainout / 10.0f))) + particledata->unk3e80.f[2]) * scale;

							spfc.f[0] = spc9c.f[0] - spc90.f[0];
							spfc.f[1] = spc9c.f[1] - spc90.f[1];
							spfc.f[2] = spc9c.f[2] - spc90.f[2];

							if (spca8.f[0] < spc9c.f[0]) {
								tmp = spc9c.f[0];
								spc9c.f[0] = spca8.f[0];
								spca8.f[0] = tmp;
							}

							if (spca8.f[1] < spc9c.f[1]) {
								tmp = spca8.f[1];
								spca8.f[1] = spc9c.f[1];
								spc9c.f[1] = tmp;
							}

							if (spca8.f[2] < spc9c.f[2]) {
								tmp = spca8.f[2];
								spca8.f[2] = spc9c.f[2];
								spc9c.f[2] = tmp;
							}

							timings2[3] = osGetCount();

							for (i = 0; i < numbadrooms; i++) {
								if (spc9c.f[0] <= g_Rooms[badrooms[i]].bbmax[0]
										&& spca8.f[0] >= g_Rooms[badrooms[i]].bbmin[0]
										&& spc9c.f[2] <= g_Rooms[badrooms[i]].bbmax[2]
										&& spca8.f[2] >= g_Rooms[badrooms[i]].bbmin[2]
										&& spc9c.f[1] <= g_Rooms[badrooms[i]].bbmax[1]
										&& spca8.f[1] >= g_Rooms[badrooms[i]].bbmin[1]
										&& bounder
										&& bg_test_line_intersects_int_bbox(&spc90, &spfc, &bboxes[i][0], &bboxes[i][3])) {
									draw = false;
								}
							}

							timings1[3] = timings1[3] + osGetCount() - timings2[3];
						}

						timings1[2] = timings1[2] + osGetCount() - timings2[2];

						if (draw) {
							timings2[4] = osGetCount();

							cddiv2 = cddiv / 10.0f;
							rainout2 = rainout / 10.0f;
							f2 = rainwidth * (1.0f + sp214 / cddiv2);

							positions[0].f[0] += -sp218[1] * -f2;
							positions[0].f[2] += sp218[0] * -f2;

							positions[1].f[0] += -sp218[1] * f2;
							positions[1].f[2] += sp218[0] * f2;

							positions[3].f[0] -= weather->windspeedx * rainout2 + -sp218[1] * f2;
							positions[3].f[1] += weather->unkb8;
							positions[3].f[2] -= weather->windspeedz * rainout2 + sp218[0] * f2;

							positions[2].f[0] -= weather->windspeedx * rainout2 + -sp218[1] * -f2;
							positions[2].f[1] += weather->unkb8;
							positions[2].f[2] -= weather->windspeedz * rainout2 + sp218[0] * -f2;

							// @bug: Writing to offset 3 overflows the vertices allocation.
							// The vertices array has 12 elements and is iterated 4 times,
							// incrementing vtxindex by 3 each time. This is harmless though,
							// as it writes into unallocated space unless the displaylist is full.
							// And if it's full then you have bigger problems to worry about.
							// Writes also occur with the s and t values further below.
							vertices[vtxindex + 0].colour = 0;
							vertices[vtxindex + 1].colour = 0;
							vertices[vtxindex + 2].colour = 4;
							vertices[vtxindex + 3].colour = 4;

							if (numsparksavailable > 0) {
								spe4.f[0] = (particle2->pos.f[0] + particledata->unk3e80.f[0]) * scale;
								spe4.f[1] = (particle2->pos.f[1] + particledata->unk3e80.f[1]) * scale;
								spe4.f[2] = (particle2->pos.f[2] + particledata->unk3e80.f[2]) * scale;

								for (i = 0; i < numtestrooms; i++) {
									if (spe4.f[0] <= g_Rooms[testrooms[i]].bbmax[0]
											&& spe4.f[0] >= g_Rooms[testrooms[i]].bbmin[0]
											&& spe4.f[2] <= g_Rooms[testrooms[i]].bbmax[2]
											&& spe4.f[2] >= g_Rooms[testrooms[i]].bbmin[2]
											&& spe4.f[1] <= g_Rooms[testrooms[i]].bbmax[1]
											&& spe4.f[1] >= g_Rooms[testrooms[i]].bbmin[1]
											&& spe4.f[1] + scale * (particle2->inc.f[1] * 1) < g_Rooms[testrooms[i]].bbmin[1]) {
										spd4.f[0] = particle2->pos.f[0] + particledata->unk3e80.f[0];
										spd4.f[1] = g_Rooms[testrooms[i]].bbmin[1] / scale;
										spd4.f[2] = particle2->pos.f[2] + particledata->unk3e80.f[2];

										sparks_create(testrooms[i], NULL, &spd4, &particle2->inc, NULL, SPARKTYPE_SHALLOWWATER);

										numsparksavailable--;
									}
								}
							}

							timings1[4] = timings1[4] + osGetCount() - timings2[4];
							timings2[5] = osGetCount();

							vertices[vtxindex + 0].t = 256;
							vertices[vtxindex + 1].s = 256;
							vertices[vtxindex + 1].t = 256;
							vertices[vtxindex + 2].s = 256;
							vertices[vtxindex + 3].t = 0;
							vertices[vtxindex + 3].s = 0;
							vertices[vtxindex + 2].t = 0;
							vertices[vtxindex + 0].s = 0;

							timings1[5] = timings1[5] + osGetCount() - timings2[5];
							timings2[6] = osGetCount();

							vertices[vtxindex + 0].x = positions[0].f[0];
							vertices[vtxindex + 0].y = positions[0].f[1];
							vertices[vtxindex + 0].z = positions[0].f[2];

							vertices[vtxindex + 1].x = positions[1].f[0];
							vertices[vtxindex + 1].y = positions[1].f[1];
							vertices[vtxindex + 1].z = positions[1].f[2];

							vertices[vtxindex + 2].x = positions[2].f[0];
							vertices[vtxindex + 2].y = positions[2].f[1];
							vertices[vtxindex + 2].z = positions[2].f[2];

							if (numtris == 3) {
								gSPVertex(gdl++, osVirtualToPhysical(vertices), 12, 0);
								gSPTri4(gdl++, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
								numtris = 0;
							} else {
								numtris++;
							}

							timings1[6] = timings1[6] + osGetCount() - timings2[6];
							timings1[1] = timings1[1] + osGetCount() - timings2[1];
						}
					}

					if (numtris);
				}
			}
		}

		if (numtris > 0) {
			gSPVertex(gdl++, osVirtualToPhysical(vertices), 12, 0);

			if (numtris == 1) {
				gSPTri1(gdl++, 0, 1, 2);
			}

			if (numtris == 2) {
				gSPTri2(gdl++, 0, 1, 2, 3, 4, 5);
			}

			if (numtris == 3) {
				gSPTri3(gdl++, 0, 1, 2, 3, 4, 5, 6, 7, 8);
			}
		}
	}

	osGetCount();

	return gdl;
}

Gfx *weather_render_snow(Gfx *gdl, struct weatherdata *weather, s32 arg2)
{
	struct weatherparticledata *particledata;
	struct weatherparticle *particle;
	s32 j;
	s32 k;
	s32 p;
	bool ok;
	u32 sp137c[1];
	u32 sp1354[10];
	bool draw;
	f32 f22 = 0.0f;
	u32 stack[6];
	s32 testrooms[50];
	s32 numtestrooms = 0;
	f32 sp1168[8][4][2];
	struct coord sp115c;
	struct coord sp1150;
	f32 sp114c;
	f32 sp1148;
	f32 sp1144;
	s32 n;
	s32 badrooms[50];
	struct coord badbbmin[50];
	struct coord badbbmax[50];
	s32 numbadrooms = 0;
	f32 sp264[50][12];
	f32 sp260;
	Col *colours;

	static u32 var8007f100 = 50;
	static u32 snowwidth = 5;
	static u32 snowheight = 10;
	static u32 snowcol1 = 0x8888aaff;
	static u32 snowcol2 = 0xffffff7f;

	tex_select(&gdl, &g_TexGeneralConfigs[0], 4, 0, 2, 1, NULL);

	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetRenderMode(gdl++, G_RM_AA_ZB_XLU_SURF, G_RM_NOOP2);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureConvert(gdl++, G_TC_FILT);
	gDPSetCombineLERP(gdl++,
			0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0,
			0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0);

	main_override_variable("snowwidth", &snowwidth);
	main_override_variable("snowheight", &snowheight);
	main_override_variable("snowcol1", &snowcol1);
	main_override_variable("snowcol2", &snowcol2);

	{
		struct coord sp234;
		struct coord sp228;
		f32 f0;
		f32 sp220;
		f32 sp21c;
		Mtxf *mtx;
		Vtx *vertices;
		Vtx *vtxbatch;
		f32 range = 150.0f;
		Mtxf sp1cc;
		struct coord sp19c[4];
		s32 sp198;
		f32 f20;
		s32 numcolours = 16;
		s32 stack;
		s32 vtxindex;
		s32 i;
		struct coord distcamtobbmax;
		struct coord distcamtobbmin;
		RoomNum neighbours[20];
		s32 numneighbours;

		particledata = weather->particledata[arg2];

		sp198 = 0;

		mtx4_load_identity(&sp1cc);
		mtx00015be0(cam_get_world_to_screen_mtxf(), &sp1cc);

		sp1cc.m[3][0] = 0.0f;
		sp1cc.m[3][1] = 0.0f;
		sp1cc.m[3][2] = 0.0f;

		mtx = gfx_allocate_matrix();

		mtx_f2l(&sp1cc, mtx);

		gSPMatrix(gdl++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

		sp234.f[0] = g_Vars.currentplayer->cam_pos.f[0];
		sp234.f[1] = g_Vars.currentplayer->cam_pos.f[1];
		sp234.f[2] = g_Vars.currentplayer->cam_pos.f[2];

		sp228.f[0] = sp234.f[0] - particledata->unk3e80.f[0];
		sp228.f[1] = sp234.f[1] - particledata->unk3e80.f[1];
		sp228.f[2] = sp234.f[2] - particledata->unk3e80.f[2];

		if (ABSF(sp228.f[0]) > ABSF(particledata->boundarymin.f[0]) + ABSF(particledata->boundarymax.f[0])
				|| ABSF(sp228.f[1]) > ABSF(particledata->boundarymin.f[1]) + ABSF(particledata->boundarymax.f[1])
				|| ABSF(sp228.f[2]) > ABSF(particledata->boundarymin.f[2]) + ABSF(particledata->boundarymax.f[2])) {
			sp228.f[0] = particledata->boundaryrange.f[0] / 2.0f;
			sp228.f[1] = particledata->boundaryrange.f[1] / 2.0f;
			sp228.f[2] = particledata->boundaryrange.f[2] / 2.0f;
		}

		for (p = 0; p < 500; p++) {
			particle = &particledata->particles[p];

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

		particledata->unk3e80.f[0] = sp234.f[0];
		particledata->unk3e80.f[1] = sp234.f[1];
		particledata->unk3e80.f[2] = sp234.f[2];

		distcamtobbmin.f[0] = particledata->boundarymin.f[0] + g_Vars.currentplayer->cam_pos.f[0];
		distcamtobbmax.f[0] = particledata->boundarymax.f[0] + g_Vars.currentplayer->cam_pos.f[0];
		distcamtobbmin.f[1] = particledata->boundarymin.f[1] + g_Vars.currentplayer->cam_pos.f[1];
		distcamtobbmax.f[1] = particledata->boundarymax.f[1] + g_Vars.currentplayer->cam_pos.f[1];
		distcamtobbmin.f[2] = particledata->boundarymin.f[2] + g_Vars.currentplayer->cam_pos.f[2];
		distcamtobbmax.f[2] = particledata->boundarymax.f[2] + g_Vars.currentplayer->cam_pos.f[2];

		if (numtestrooms < ARRAYCOUNT(testrooms)) {
			testrooms[numtestrooms] = g_Vars.currentplayer->cam_room;
			numtestrooms++;
		}

		for (i = 0; i < numtestrooms; i++) {
			numneighbours = bg_room_get_neighbours(testrooms[i], neighbours, ARRAYCOUNT(neighbours));

			for (n = 0; n < numneighbours; n++) {
				if (g_Rooms[neighbours[n]].flags & ROOMFLAG_ONSCREEN) {
					ok = true;

					for (k = 0; k < numtestrooms; k++) {
						if (testrooms[k] == neighbours[n]) {
							ok = false;
						}
					}

					if (ok) {
						if (distcamtobbmax.f[0] < g_Rooms[neighbours[n]].bbmin[0] || distcamtobbmin.f[0] > g_Rooms[neighbours[n]].bbmax[0]) {
							ok = false;
						}

						if (distcamtobbmax.f[1] < g_Rooms[neighbours[n]].bbmin[1] || distcamtobbmin.f[1] > g_Rooms[neighbours[n]].bbmax[1]) {
							ok = false;
						}

						if (distcamtobbmax.f[2] < g_Rooms[neighbours[n]].bbmin[2] || distcamtobbmin.f[2] > g_Rooms[neighbours[n]].bbmax[2]) {
							ok = false;
						}
					}

					if (ok) {
						if (numtestrooms < ARRAYCOUNT(testrooms)) {
							testrooms[numtestrooms] = neighbours[n];
							numtestrooms++;
						} else {
							// empty
						}
					}
				}
			}
		}

		for (i = 0; i < numtestrooms; i++) {
			if (weather_is_room_weatherproof(testrooms[i])) {
				// @bug: Overflowing badbbmin and badbbmax if badrooms is full.
				// (These writes should be inside the if statement).
				badbbmin[numbadrooms].f[0] = g_Rooms[testrooms[i]].bbmin[0] / 1;
				badbbmin[numbadrooms].f[1] = g_Rooms[testrooms[i]].bbmin[1] / 1;
				badbbmin[numbadrooms].f[2] = g_Rooms[testrooms[i]].bbmin[2] / 1;

				badbbmax[numbadrooms].f[0] = g_Rooms[testrooms[i]].bbmax[0] / 1;
				badbbmax[numbadrooms].f[1] = g_Rooms[testrooms[i]].bbmax[1] / 1;
				badbbmax[numbadrooms].f[2] = g_Rooms[testrooms[i]].bbmax[2] / 1;

				if (numbadrooms < ARRAYCOUNT(badrooms)) {
					badrooms[numbadrooms] = testrooms[i];
					numbadrooms++;
				} else {
					// empty
				}
			}
		}

		for (j = 0; j < numbadrooms; j++) {
			if (0);
			sp264[j][6] = sp264[j][0] = g_Rooms[badrooms[j]].bbmin[0] / 1 - snowwidth;
			sp264[j][9] = sp264[j][3] = g_Rooms[badrooms[j]].bbmax[0] / 1 + snowwidth;
			sp264[j][6] -= var8007f100;
			sp264[j][9] += var8007f100;

			sp264[j][7] = sp264[j][1] = g_Rooms[badrooms[j]].bbmin[1] / 1 - snowwidth;
			sp264[j][10] = sp264[j][4] = g_Rooms[badrooms[j]].bbmax[1] / 1 + snowwidth;
			sp264[j][7] -= var8007f100;
			sp264[j][10] += var8007f100;

			sp264[j][8] = sp264[j][2] = g_Rooms[badrooms[j]].bbmin[2] / 1 - snowwidth;
			sp264[j][11] = sp264[j][5] = g_Rooms[badrooms[j]].bbmax[2] / 1 + snowwidth;
			sp264[j][8] -= var8007f100;
			sp264[j][11] += var8007f100;
		}

		for (j = 0; j < 8; j++) {
			sp1168[j][0][0] = sinf(particledata->unk3ec8[j]);
			sp1168[j][0][1] = cosf(particledata->unk3ec8[j]);
			sp1168[j][1][0] = sinf(particledata->unk3ec8[j] + DTOR(180) * 0.5f);
			sp1168[j][1][1] = cosf(particledata->unk3ec8[j] + DTOR(180) * 0.5f);
			sp1168[j][2][0] = sinf(particledata->unk3ec8[j] + DTOR(180));
			sp1168[j][2][1] = cosf(particledata->unk3ec8[j] + DTOR(180));
			sp1168[j][3][0] = sinf(particledata->unk3ec8[j] + DTOR(180) * 1.5f);
			sp1168[j][3][1] = cosf(particledata->unk3ec8[j] + DTOR(180) * 1.5f);
		}

		colours = gfx_allocate_colours(numcolours);

		for (j = 0; j < numcolours; j++) {
			u32 alpha = ((numcolours + 1) * 255 - j * 255) / (numcolours + 1);
			colours[j].word = (snowcol1 & 0xffffff00) | alpha;
		}

		gSPColor(gdl++, osVirtualToPhysical(colours), numcolours);

		for (p = 0; p < 500; p++) {
			struct weatherparticle *particle = &particledata->particles[p];
			struct coord sp124;
			struct coord sp118;

			vtxindex = sp198 * 4;
			draw = true;

			if (particle->active & 3) {
				sp1354[0] = osGetCount();

				sp124.f[0] = particle->pos.f[0] + particledata->unk3e80.f[0];
				sp124.f[1] = particle->pos.f[1] + particledata->unk3e80.f[1];
				sp124.f[2] = particle->pos.f[2] + particledata->unk3e80.f[2];

				if (cam0f0b5b9c(&sp124, 5)) {
					sp137c[0] = sp137c[0] + osGetCount() - sp1354[0];

					sp21c = particle->pos.f[0];
					sp220 = particle->pos.f[2];

					f20 = sqrtf(sp220 * sp220 + sp21c * sp21c);

					if (f20 < 0.00001f) {
						// empty
					} else {
						if (sp198 == 0) {
							vertices = gfx_allocate_vertices(8);
						}

						sp260 = 0.0f;

						sp21c /= f20;
						sp220 /= f20;

						for (j = 0; j < 4; j++) {
							vertices[j + vtxindex].s = 0;
							vertices[j + vtxindex].t = 0;

							sp19c[j].f[0] = particle->pos.f[0];
							sp19c[j].f[1] = particle->pos.f[1];
							sp19c[j].f[2] = particle->pos.f[2];
						}

						if (numbadrooms > 0) {
							sp118.f[0] = particle->pos.f[0] + particledata->unk3e80.f[0];
							sp118.f[1] = particle->pos.f[1] + particledata->unk3e80.f[1];
							sp118.f[2] = particle->pos.f[2] + particledata->unk3e80.f[2];

							for (j = 0; j < numbadrooms; j++) {
								if (draw
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
										draw = false;
									} else {
										f32 f2 = 0.0f;

										if (sp264[j][0] > sp118.f[0]) {
											f2 = sp118.f[0] - sp264[j][6];
										}

										if (sp264[j][3] < sp118.f[0]) {
											f2 = sp118.f[0] - sp264[j][9];
										}

										f2 = ABSF(f2) / var8007f100;

										if (f2 > sp260) {
											sp260 = f2;
										}

										if (sp264[j][2] > sp118.f[2]) {
											f2 = sp118.f[2] - sp264[j][8];
										}

										if (sp264[j][5] < sp118.f[2]) {
											f2 = sp118.f[2] - sp264[j][11];
										}

										f2 = ABSF(f2) / var8007f100;

										if (f2 > sp260) {
											sp260 = f2;
										}
									}
								}
							}
						}

						if (draw) {
							f32 f16;
							f32 sp10c;
							f32 sp108;
							f32 sp104;
							f32 f0_3;
							f32 val1;
							f32 val2;
							f32 val3;
							s32 colourindex;
							s32 xindex = (p & 1) >> 0;
							s32 yindex = (p & 2) >> 1;

							if (range);

							f0_3 = sqrtf(particle->pos.f[0] * particle->pos.f[0]
									+ particle->pos.f[1] * particle->pos.f[1]
									+ particle->pos.f[2] * particle->pos.f[2]);

							sp10c = particle->pos.f[0] / f0_3;
							sp108 = particle->pos.f[1] / f0_3;
							sp104 = particle->pos.f[2] / f0_3;

							f0_3 = sqrtf(sp10c * sp10c + sp104 * sp104);

							val2 = sp10c / f0_3;
							val1 = sp104 / f0_3;
							val3 = -val2;

							sp114c = sp108 * val2;
							sp1148 = -f0_3;
							sp1144 = sp108 * val1;

							sp115c.f[0] = -sp220;
							sp115c.f[1] = 1.0f;
							sp115c.f[2] = sp21c;

							for (j = 0; j < 4; j++) {
								sp19c[j].f[0] += snowwidth * val1 * sp1168[(p >> 2) & 7][j][0] + snowwidth * sp114c * sp1168[(p >> 2) & 7][j][1];
								sp19c[j].f[1] += snowwidth *  f22 * sp1168[(p >> 2) & 7][j][0] + snowwidth * sp1148 * sp1168[(p >> 2) & 7][j][1];
								sp19c[j].f[2] += snowwidth * val3 * sp1168[(p >> 2) & 7][j][0] + snowwidth * sp1144 * sp1168[(p >> 2) & 7][j][1];
							}

							// x
							f16 = 0.0f;

							if (particle->pos.f[0] < particledata->boundarymin.f[0] + range) {
								f16 = particle->pos.f[0] - particledata->boundarymin.f[0] - range;
							}

							if (particle->pos.f[0] > particledata->boundarymax.f[0] - range) {
								f16 = particle->pos.f[0] - particledata->boundarymax.f[0] + range;
							}

							f16 = ABSF(f16) / range;

							if (f16 > sp260) {
								sp260 = f16;
							}

							// y
							f16 = 0.0f;

							if (particle->pos.f[1] < particledata->boundarymin.f[1] + range) {
								f16 = particle->pos.f[1] - particledata->boundarymin.f[1] - range;
							}

							if (particle->pos.f[1] > particledata->boundarymax.f[1] - range) {
								f16 = particle->pos.f[1] - particledata->boundarymax.f[1] + range;
							}

							f16 = ABSF(f16) / range;

							if (f16 > sp260) {
								sp260 = f16;
							}

							// z
							f16 = 0.0f;

							if (particle->pos.f[2] < particledata->boundarymin.f[2] + range) {
								f16 = particle->pos.f[2] - particledata->boundarymin.f[2] - range;
							}

							if (particle->pos.f[2] > particledata->boundarymax.f[2] - range) {
								f16 = particle->pos.f[2] - particledata->boundarymax.f[2] + range;
							}

							f16 = ABSF(f16) / range;

							if (f16 > sp260) {
								sp260 = f16;
							}

							colourindex = sp260 * 16.0f;

							vertices[vtxindex + 0].colour = colourindex * 4;
							vertices[vtxindex + 1].colour = colourindex * 4;
							vertices[vtxindex + 2].colour = colourindex * 4;
							vertices[vtxindex + 3].colour = colourindex * 4;

							vertices[vtxindex + 0].s = (xindex * 8) << 5;
							vertices[vtxindex + 0].t = (yindex * 8 + 8) << 5;
							vertices[vtxindex + 1].s = (xindex * 8 + 8) << 5;
							vertices[vtxindex + 1].t = (yindex * 8 + 8) << 5;
							vertices[vtxindex + 2].s = (xindex * 8 + 8) << 5;
							vertices[vtxindex + 2].t = (yindex * 8) << 5;
							vertices[vtxindex + 3].s = (xindex * 8) << 5;
							vertices[vtxindex + 3].t = (yindex * 8) << 5;

							vertices[vtxindex + 0].x = sp19c[0].f[0];
							vertices[vtxindex + 0].y = sp19c[0].f[1];
							vertices[vtxindex + 0].z = sp19c[0].f[2];

							vertices[vtxindex + 1].x = sp19c[1].f[0];
							vertices[vtxindex + 1].y = sp19c[1].f[1];
							vertices[vtxindex + 1].z = sp19c[1].f[2];

							vertices[vtxindex + 2].x = sp19c[2].f[0];
							vertices[vtxindex + 2].y = sp19c[2].f[1];
							vertices[vtxindex + 2].z = sp19c[2].f[2];

							vertices[vtxindex + 3].x = sp19c[3].f[0];
							vertices[vtxindex + 3].y = sp19c[3].f[1];
							vertices[vtxindex + 3].z = sp19c[3].f[2];

							if (sp198 == 1) {
								gSPVertex(gdl++, osVirtualToPhysical(vertices), 8, 0);
								gSPTri4(gdl++, 0, 1, 2, 2, 3, 0, 4, 5, 6, 6, 7, 4);
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
			gSPVertex(gdl++, osVirtualToPhysical(vertices), 8, 0);
			gSPTri2(gdl++, 0, 1, 2, 2, 3, 0);
		}
	}

	return gdl;
}

void weather_stop(void)
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
