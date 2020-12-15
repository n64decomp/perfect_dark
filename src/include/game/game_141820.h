#ifndef _IN_GAME_GAME_141820_H
#define _IN_GAME_GAME_141820_H
#include <ultra64.h>
#include "types.h"

Gfx *hudRenderIrRect(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2);
Gfx *func0f141ab0(Gfx *gdl, u32 arg1, s32 top, u32 arg3, s32 arg4, f32 arg5, s32 left, s32 width);
u32 func0f141ed4(void);
Gfx *func0f1420b0(Gfx *gdl, u32 colour, u32 alpha);
Gfx *func0f142274(Gfx *gdl, u32 colour, u32 alpha);
Gfx *hudRenderMotionBlur(Gfx *gdl, u32 colour, u32 alpha);
Gfx *hudRenderStatic(Gfx *gdl, u32 arg1, s32 arg2);
Gfx *hudRenderSlayerRocketLens(Gfx *gdl, u32 arg1, u32 arg2);
Gfx *func0f14298c(Gfx *gdl, u32 colour, u32 alpha);
Gfx *func0f142bf0(Gfx *gdl, u32 colour, s32 alpha, f32 arg3, f32 arg4);
u32 func0f142d74(void);
Gfx *hudRenderEyespyView(Gfx *gdl, s32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5);
Gfx *hudRenderEyespySideRect(Gfx *gdl, s32 *points, u8 r, u8 g, u8 b, u8 alpha);
Gfx *hudRenderEyespyUi(Gfx *gdl);
Gfx *func0f1472fc(Gfx *gdl);
Gfx *func0f147578(Gfx *gdl);
Gfx *func0f147cf8(Gfx *gdl);
Gfx *hudRenderHorizonScanner(Gfx *gdl);
Gfx *hudRenderIrBinoculars(Gfx *gdl);
void func0f148b40(u32 arg0);
void func0f148b6c(void);
Gfx *func0f147570(Gfx *gdl);

#endif
