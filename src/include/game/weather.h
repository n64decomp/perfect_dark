#ifndef _IN_GAME_WEATHER_H
#define _IN_GAME_WEATHER_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void weather_reset(void);

void weather_tick(void);

Gfx *weather_render(Gfx *gdl);
struct weatherparticledata *weather_allocate_particles(void);
void weather_tick_rain(struct weatherdata *weather);
void weather_tick_snow(struct weatherdata *weather);
void weather_configure_rain(u32 intensity);
void weather_configure_snow(u32 intensity);
void weather_stop(void);

#endif
