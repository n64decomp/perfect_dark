#ifndef _IN_GAME_WEATHER_H
#define _IN_GAME_WEATHER_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void weather_reset(void);

void weather_tick(void);

Gfx *weather_render(Gfx *gdl);
void weather_set_boundaries(struct weatherparticledata *data, s32 index, f32 min, f32 max);
struct weatherparticledata *weather_allocate_particles(void);
void func0f131610(struct weatherdata *weather);
void func0f131678(s32 arg0);
void weather_set_intensity(s32 intensity);
void weather_tick_rain(struct weatherdata *weather);
void weather_tick_snow(struct weatherdata *weather);
void weather_configure_rain(u32 intensity);
void weather_configure_snow(u32 intensity);
bool weather_is_room_weather_proof(s32 room);
Gfx *weather_render_rain(Gfx *gdl, struct weatherdata *weather, s32 arg2);
Gfx *weather_render_snow(Gfx *gdl, struct weatherdata *weather, s32 arg2);
void weather_stop(void);

#endif
