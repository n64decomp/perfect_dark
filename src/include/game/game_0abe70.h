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
s32 func0f0aec54(struct prop *prop);
s32 func0f0aeca8(struct prop *prop);
void func0f0aed3c(s32 index, struct coord *pos);
void func0f0aed70(s32 index, struct coord *pos);
void func0f0aeda4(s32 arg0, f32 arg1, u32 arg2);
void func0f0aeea8(s32 index, f32 arg1);
Gfx *func0f0aeed8(Gfx *gdl);
void func0f0aefb8(void);
bool lasersightExists(s32 id, s32 *index);
Gfx *lasersightRenderDot(Gfx *gdl);
Gfx *lasersightRenderBeam(Gfx *gdl);
void func0f0b0268(s32 id, s32 arg1, struct coord *near, struct coord *far);
void lasersightSetDot(s32 arg0, struct coord *pos, struct coord *rot);
void lasersightFree(s32 arg0);

#endif
