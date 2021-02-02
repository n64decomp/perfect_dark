#ifndef IN_GAME_GAME_006BD0_H
#define IN_GAME_GAME_006BD0_H
#include <ultra64.h>
#include "types.h"

f32 func0f006bd0(f32 arg0);
u32 func0f006c80(void);
Gfx *func0f008558(Gfx *gdl, s32 arg1);
void nbombResetAge(struct nbomb *nbomb);
s32 nbombCalculateAlpha(struct nbomb *nbomb);
Gfx *nbombCreateGdl(void);
Gfx *nbombRender(Gfx *gdl, struct nbomb *nbomb, Gfx *subgdl);
void func0f0099a4(void);
void nbombInflictDamage(struct nbomb *nbomb);
void nbombTick(struct nbomb *nbomb);
void nbombsTick(void);
Gfx *nbombsRender(Gfx *gdl);
void nbombCreate(struct coord *pos, struct prop *prop);
f32 gasGetDoorFrac(s32 tagnum);
Gfx *func0f00a490(Gfx *gdl);
Gfx *gasRender(Gfx *gdl);
void func0f00b180(void);

#endif
