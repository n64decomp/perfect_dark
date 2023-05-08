#ifndef _IN_GAME_BONDVIEW_H
#define _IN_GAME_BONDVIEW_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

Gfx *bviewDrawMotionBlur(Gfx *gdl, u32 colour, u32 alpha);
Gfx *bviewDrawStatic(Gfx *gdl, u32 arg1, s32 arg2);
Gfx *bviewDrawSlayerRocketInterlace(Gfx *gdl, u32 arg1, u32 arg2);
Gfx *bviewDrawFilmInterlace(Gfx *gdl, u32 colour, u32 alpha);
Gfx *bviewDrawZoomBlur(Gfx *gdl, u32 colour, s32 alpha, f32 arg3, f32 arg4);
Gfx *bviewDrawFisheye(Gfx *gdl, u32 colour, u32 alpha, s32 shuttertime60, s8 startuptimer60, u8 hit);
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
