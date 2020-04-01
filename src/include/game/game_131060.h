#ifndef _IN_GAME_GAME_131060_H
#define _IN_GAME_GAME_131060_H
#include <ultra64.h>
#include "types.h"

u32 func0f131060(void);
u32 func0f1312d8(void);
u32 func0f131334(void);
u32 func0f131610(void);
u32 func0f131678(void);
void weatherSetIntensity(u32 intensity);
void rainTick(struct weatherdata *weather);
void snowTick(struct weatherdata *weather);
void rainConfigure(u32 intensity);
void snowConfigure(u32 intensity);
u32 func0f132a1c(void);
u32 func0f132e28(void);
u32 func0f1346b0(void);
u32 func0f135bd8(void);

#endif
