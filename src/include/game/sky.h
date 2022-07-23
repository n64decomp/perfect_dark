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
void skyChooseCloudVtxColour(struct skything18 *arg0, f32 arg1);
void sky0f11f6ec(struct skything18 *arg0, f32 arg1);
Gfx *skyRender(Gfx *gdl);
void sky0f1228d0(struct skything18 *arg0, Mtxf *arg1, s32 arg2, f32 arg3, f32 arg4, struct skything38 *arg5);
bool sky0f122ce8(struct skything38 *arg0, struct skything38 *arg1);
Gfx *sky0f122d4c(Gfx *gdl, struct skything38 *arg1, struct skything38 *arg2, struct skything38 *arg3, f32 arg4, bool arg5);
Gfx *sky0f123fd4(Gfx *gdl, struct skything38 *arg1, struct skything38 *arg2, struct skything38 *arg3, struct skything38 *arg4, f32 arg5);
void sky0f125948(struct bootbufferthingdeep *arg0, s32 x, s32 y);
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
