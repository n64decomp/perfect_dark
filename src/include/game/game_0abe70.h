#ifndef IN_GAME_GAME_0ABE70_H
#define IN_GAME_GAME_0ABE70_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 func0f0abe70(void);
u32 func0f0ac138(void);
Gfx *func0f0ac4b8(Gfx *gdl, struct textureconfig *arg1, f32 arg2, struct coord *arg3, u32 colour1, f32 arg5, struct coord *arg6, u32 colour2);
Gfx *func0f0acb90(Gfx *gdl, struct beam *beam, bool arg2, u32 arg3);
void beamTick(struct beam *beam);
u32 func0f0adcc8(void);
u32 func0f0ade00(void);
u32 func0f0ae964(void);
u32 func0f0aebe0(void);
s32 func0f0aec54(s32 arg0);
s32 func0f0aeca8(s32 arg0);
void func0f0aed3c(s32 index, struct coord *coord);
void func0f0aed70(s32 index, struct coord *coord);
u32 func0f0aeda4(void);
void func0f0aeea8(s32 index, f32 arg1);
Gfx *func0f0aeed8(Gfx *gdl);
void func0f0aefb8(void);
bool lasersightExists(s32 id, s32 *index);
Gfx *func0f0af158(Gfx *gdl);
u32 func0f0afa4c(void);
void func0f0b0268(s32 id, s32 arg1, struct coord *near, struct coord *far);
void lasersightSetDot(s32 arg0, struct coord *pos, struct coord *rot);
void lasersightFree(s32 arg0);

#endif
