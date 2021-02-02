#ifndef _IN_GAME_SIGHT_H
#define _IN_GAME_SIGHT_H
#include <ultra64.h>
#include "types.h"

bool sightIsPropFriendly(struct prop *prop);
bool sightCanTargetProp(struct prop *prop, s32 max);
bool sightIsReactiveToProp(struct prop *prop);
s32 sightFindFreeTargetIndex(s32 max);
void func0f0d7364(void);
void sightTick(bool sighton);
s32 func0f0d789c(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
Gfx *sightRenderTargetBox(Gfx *gdl, struct threat *threat, u32 textid, s32 time);
Gfx *func0f0d7f54(Gfx *gdl, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
Gfx *func0f0d87a8(Gfx *gdl, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
Gfx *sightRenderDefault(Gfx *gdl, bool sighton);
Gfx *sightRenderClassic(Gfx *gdl, bool sighton);
Gfx *sightRenderType2(Gfx *gdl, bool sighton);
u32 func0f0d9948(void);
Gfx *sightRenderSkedar(Gfx *gdl, bool sighton);
Gfx *sightRenderZoom(Gfx *gdl, bool sighton);
Gfx *sightRenderMaian(Gfx *gdl, bool sighton);
Gfx *sightRenderTarget(Gfx *gdl);
bool sightHasTargetWhileAiming(s32 sight);
Gfx *sightRender(Gfx *gdl, bool sighton, s32 sight);

#endif
