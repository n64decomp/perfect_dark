#ifndef IN_GAME_GAME_006BD0_H
#define IN_GAME_GAME_006BD0_H
#include <ultra64.h>
#include "types.h"

f32 func0f006bd0(f32 arg0);
u32 func0f006c80(void);
u32 func0f008558(void);
u32 func0f0094b4(void);
s32 func0f0094bc(struct gaspart *part);
s32 func0f009504(void);
Gfx *func0f009818(Gfx *gdl, struct gaspart *arg1, s32 arg2);
void func0f0099a4(void);
u32 func0f0099e4(void);
void func0f009d10(struct gaspart *part);
void gasTick(void);
Gfx *func0f00a168(Gfx *gdl);
u32 func0f00a1f8(void);
f32 doorGetFrac(s32 tagnum);
Gfx *func0f00a490(Gfx *gdl);
Gfx *hudRenderGasIfEnabled(Gfx *gdl);
void func0f00b180(void);

#endif
