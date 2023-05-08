#ifndef _IN_GAME_WEATHER_H
#define _IN_GAME_WEATHER_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void weatherReset(void);

void weatherTick(void);

Gfx *weatherRender(Gfx *gdl);
struct weatherparticledata *weatherAllocateParticles(void);
void weatherTickRain(struct weatherdata *weather);
void weatherTickSnow(struct weatherdata *weather);
void weatherConfigureRain(u32 intensity);
void weatherConfigureSnow(u32 intensity);
void weatherStop(void);

#endif
