#ifndef _IN_GAME_GAME_0D7070_H
#define _IN_GAME_GAME_0D7070_H
#include <ultra64.h>
#include "types.h"

bool func0f0d7070(struct prop *prop);
bool func0f0d716c(struct prop *prop, s32 arg1);
bool func0f0d7240(struct prop *prop);
s32 func0f0d7328(s32 arg0);
void func0f0d7364(void);
void func0f0d7390(s32 arg0);
s32 func0f0d789c(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
u32 func0f0d78f4(void);
u32 func0f0d7f54(void);
u32 func0f0d87a8(void);
Gfx *sightRenderDefault(Gfx *gdl, bool aiming);
Gfx *sightRenderClassic(Gfx *gdl, bool aiming);
Gfx *sightRenderType2(Gfx *gdl, bool aiming);
u32 func0f0d9948(void);
Gfx *sightRenderSkedar(Gfx *gdl, bool aiming);
Gfx *sightRenderZoom(Gfx *gdl, bool aiming);
Gfx *sightRenderMaian(Gfx *gdl, bool aiming);
Gfx *sightRenderTarget(Gfx *gdl);
bool sightHasTargetWhileAiming(s32 sight);
Gfx *sightRender(Gfx *gdl, bool aiming, s32 sight);

#endif
