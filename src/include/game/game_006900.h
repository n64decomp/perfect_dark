#ifndef IN_GAME_GAME_006900_H
#define IN_GAME_GAME_006900_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 colour_blend(u32 a, u32 b, u32 weight);
void menu_tick_timers(void);
f32 menu_get_sin_osc_frac(f32 freq);
f32 menu_get_cos_osc_frac(f32 freq);
f32 menu_get_linear_interval_frac(f32 freq);
f32 menu_get_linear_osc_pause_frac(f32 frac);

#endif
