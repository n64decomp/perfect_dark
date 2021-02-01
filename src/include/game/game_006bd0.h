#ifndef IN_GAME_GAME_006BD0_H
#define IN_GAME_GAME_006BD0_H
#include <ultra64.h>
#include "types.h"

f32 func0f006bd0(f32 arg0);
u32 func0f006c80(void);
u32 func0f008558(void);
u32 func0f0094b4(void);
s32 nbombCalculateAlpha(struct nbomb *nbomb);
Gfx *nbombAllocateGdl(void);
Gfx *nbombRender(Gfx *gdl, struct nbomb *nbomb, Gfx *subgdl);
void func0f0099a4(void);
void func0f0099e4(struct nbomb *nbomb);
void nbombTick(struct nbomb *nbomb);
void nbombsTick(void);
Gfx *nbombsRender(Gfx *gdl);
u32 func0f00a1f8(void);
f32 gasGetDoorFrac(s32 tagnum);
Gfx *func0f00a490(Gfx *gdl);
Gfx *gasRender(Gfx *gdl);
void func0f00b180(void);

#endif
