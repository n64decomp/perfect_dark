#ifndef IN_GAME_GAME_006900_H
#define IN_GAME_GAME_006900_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 colourBlend(u32 a, u32 b, u32 weight);
void menuTickTimers(void);
f32 menuGetSinOscFrac(f32 freq);
f32 menuGetCosOscFrac(f32 freq);
f32 menuGetLinearIntervalFrac(f32 freq);
f32 menuGetLinearOscPauseFrac(f32 frac);

#endif
