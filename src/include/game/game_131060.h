#ifndef _IN_GAME_GAME_131060_H
#define _IN_GAME_GAME_131060_H
#include <ultra64.h>
#include "types.h"

u32 weatherRender(void);
u32 func0f1312d8(void);
u32 func0f131334(void);
void func0f131610(struct weatherdata *weather);
void func0f131678(s32 arg0);
void weatherSetIntensity(s32 intensity);
void weatherTickRain(struct weatherdata *weather);
void weatherTickSnow(struct weatherdata *weather);
void weatherConfigureRain(u32 intensity);
void weatherConfigureSnow(u32 intensity);
bool weatherIsRoomWeatherProof(u32 param_1);
u32 weatherRenderRain(void);
u32 weatherRenderSnow(void);
void weatherFree(void);

#endif
