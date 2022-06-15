#ifndef _IN_GAME_SIGHT_H
#define _IN_GAME_SIGHT_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool sightIsPropFriendly(struct prop *prop);
bool sightCanTargetProp(struct prop *prop, s32 max);
bool sightIsReactiveToProp(struct prop *prop);
s32 sightFindFreeTargetIndex(s32 max);
void func0f0d7364(void);
void sightTick(bool sighton);
s32 func0f0d789c(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
Gfx *sightDrawTargetBox(Gfx *gdl, struct threat *threat, u32 textid, s32 time);
Gfx *func0f0d7f54(Gfx *gdl, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
Gfx *func0f0d87a8(Gfx *gdl, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
Gfx *sightDrawDefault(Gfx *gdl, bool sighton);
Gfx *sightDrawClassic(Gfx *gdl, bool sighton);
Gfx *sightDrawType2(Gfx *gdl, bool sighton);
Gfx *sightDrawSkedarTriangle(Gfx *gdl, s32 x, s32 y, s32 dir, u32 colour);
Gfx *sightDrawSkedar(Gfx *gdl, bool sighton);
Gfx *sightDrawZoom(Gfx *gdl, bool sighton);
Gfx *sightDrawMaian(Gfx *gdl, bool sighton);
Gfx *sightDrawTarget(Gfx *gdl);
bool sightHasTargetWhileAiming(s32 sight);
Gfx *sightDraw(Gfx *gdl, bool sighton, s32 sight);

#endif
