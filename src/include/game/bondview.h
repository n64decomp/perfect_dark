#ifndef _IN_GAME_BONDVIEW_H
#define _IN_GAME_BONDVIEW_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

Gfx *bviewDrawIrRect(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2);
Gfx *bviewCopyPixels(Gfx *gdl, u16 *fb, s32 top, u32 tile, s32 arg4, f32 arg5, s32 left, s32 width);
Gfx *bviewDrawFisheyeRect(Gfx *gdl, s32 arg1, f32 arg2, s32 arg3, s32 arg4);
Gfx *bviewPrepareStaticRgba16(Gfx *gdl, u32 colour, u32 alpha);
Gfx *bviewPrepareStaticI8(Gfx *gdl, u32 colour, u32 alpha);
Gfx *bviewDrawMotionBlur(Gfx *gdl, u32 colour, u32 alpha);
Gfx *bviewDrawStatic(Gfx *gdl, u32 arg1, s32 arg2);
Gfx *bviewDrawSlayerRocketInterlace(Gfx *gdl, u32 arg1, u32 arg2);
Gfx *bviewDrawFilmInterlace(Gfx *gdl, u32 colour, u32 alpha);
Gfx *bviewDrawZoomBlur(Gfx *gdl, u32 colour, s32 alpha, f32 arg3, f32 arg4);
f32 bview0f142d74(s32 arg0, f32 arg1, f32 arg2, f32 arg3);
Gfx *bviewDrawFisheye(Gfx *gdl, u32 colour, u32 alpha, s32 shuttertime60, s8 startuptimer60, u8 hit);
Gfx *bviewDrawEyespySideRect(Gfx *gdl, s32 *points, u8 r, u8 g, u8 b, u8 alpha);
Gfx *bviewDrawEyespyMetrics(Gfx *gdl);
Gfx *bviewDrawNvLens(Gfx *gdl);
Gfx *bviewDrawIrLens(Gfx *gdl);
Gfx *bviewDrawIntroText(Gfx *gdl);
Gfx *bviewDrawHorizonScanner(Gfx *gdl);
Gfx *bviewDrawIrBinoculars(Gfx *gdl);
void bviewSetMotionBlur(u32 bluramount);
void bviewClearMotionBlur(void);
Gfx *bviewDrawNvBinoculars(Gfx *gdl);

#endif
