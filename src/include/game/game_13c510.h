#ifndef _IN_GAME_GAME_13C510_H
#define _IN_GAME_GAME_13C510_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void artifactsClear(void);
void artifactsTick(void);
u16 func0f13c574(f32 arg0);
s32 func0f13c710(f32 arg0);
void artifactsCalculateGlaresForRoom(s32 roomnum);
u8 func0f13d3c4(u8 arg0, u8 arg1);
Gfx *artifactsConfigureForGlares(Gfx *gdl);
Gfx *artifactsUnconfigureForGlares(Gfx *gdl);
Gfx *artifactsRenderGlaresForRoom(Gfx *gdl, s32 roomnum);

#endif
