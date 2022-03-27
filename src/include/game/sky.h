#ifndef _IN_GAME_SKY_H
#define _IN_GAME_SKY_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void skyReset(u32 stagenum);

void skyTick(void);

void sky0f11f000(f32 left, f32 top, struct coord *arg2);
bool sky0f11f07c(struct coord *arg0, struct coord *arg1, f32 *arg2);
bool sky0f11f1fc(struct coord *arg0, struct coord *arg1, f32 *arg2);
void sky0f11f384(struct coord *arg0, struct coord *arg1, struct coord *out);
f32 skyClamp(f32 value, f32 min, f32 max);
f32 skyRound(f32 value);
u32 sky0f11f438(void);
u32 sky0f11f6ec(void);
Gfx *skyRender(Gfx *gdl);
u32 sky0f1228d0(void);
u32 sky0f122ce8(void);
u32 sky0f122d4c(void);
u32 sky0f123fd4(void);
void sky0f125948(struct bootbufferthingdeep *arg0, s32 arg1, s32 arg2);
f32 sky0f125a1c(struct bootbufferthingdeep *arg0);
Gfx *skyRenderSuns(Gfx *gdl, bool xray);
Gfx *sky0f126384(Gfx *gdl, f32 x, f32 y, f32 arg3, f32 orbsize, s32 arg5, f32 arg6);
Gfx *sky0f126c3c(Gfx *gdl, f32 x, f32 y, f32 z, f32 arg4, f32 arg5);
Gfx *sky0f126de8(Gfx *gdl);
Gfx *sky0f12715c(Gfx *gdl);
void sky0f127334(s32 arg0, s32 arg1, s32 arg2);
s32 sky0f127490(s32 arg0, s32 arg1);
Gfx *sky0f1274d8(Gfx *gdl);

#endif
