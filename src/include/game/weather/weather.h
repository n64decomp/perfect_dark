#ifndef _IN_GAME_WEATHER_WEATHER_H
#define _IN_GAME_WEATHER_WEATHER_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

Gfx *weatherRender(Gfx *gdl);
void weatherSetBoundaries(struct weatherparticledata *data, s32 index, f32 min, f32 max);
struct weatherparticledata *weatherAllocateParticles(void);
void func0f131610(struct weatherdata *weather);
void func0f131678(s32 arg0);
void weatherSetIntensity(s32 intensity);
void weatherTickRain(struct weatherdata *weather);
void weatherTickSnow(struct weatherdata *weather);
void weatherConfigureRain(u32 intensity);
void weatherConfigureSnow(u32 intensity);
bool weatherIsRoomWeatherProof(s32 room);
Gfx *weatherRenderRain(Gfx *gdl, struct weatherdata *weather, s32 arg2);
Gfx *weatherRenderSnow(Gfx *gdl, struct weatherdata *weather, s32 arg2);
void weatherReset(void);

#endif
