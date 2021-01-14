#ifndef _IN_GAME_BONDVIEW_H
#define _IN_GAME_BONDVIEW_H
#include <ultra64.h>
#include "types.h"

Gfx *bviewRenderIrRect(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2);
Gfx *bviewRenderLensRect(Gfx *gdl, s32 arg1, s32 top, s32 arg3, s32 arg4, f32 arg5, s32 left, s32 width);
Gfx *bviewRenderFisheyeRect(Gfx *gdl, s32 arg1, f32 arg2, s32 arg3, s32 arg4);
Gfx *bviewPrepareStaticRgba16(Gfx *gdl, u32 colour, u32 alpha);
Gfx *bviewPrepareStaticI8(Gfx *gdl, u32 colour, u32 alpha);
Gfx *bviewRenderMotionBlur(Gfx *gdl, u32 colour, u32 alpha);
Gfx *bviewRenderStatic(Gfx *gdl, u32 arg1, s32 arg2);
Gfx *bviewRenderSlayerRocketLens(Gfx *gdl, u32 arg1, u32 arg2);
Gfx *bviewRenderFilmLens(Gfx *gdl, u32 colour, u32 alpha);
Gfx *bviewRenderZoomBlur(Gfx *gdl, u32 colour, s32 alpha, f32 arg3, f32 arg4);
f32 bview0f142d74(s32 arg0, f32 arg1, f32 arg2, f32 arg3);
Gfx *bviewRenderFisheye(Gfx *gdl, s32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5);
Gfx *bviewRenderEyespySideRect(Gfx *gdl, s32 *points, u8 r, u8 g, u8 b, u8 alpha);
Gfx *bviewRenderEyespyDecorations(Gfx *gdl);
Gfx *bviewRenderNvLens(Gfx *gdl);
Gfx *bviewRenderIrLens(Gfx *gdl);
Gfx *bviewRenderRarePresents(Gfx *gdl);
Gfx *bviewRenderHorizonScanner(Gfx *gdl);
Gfx *bviewRenderIrBinoculars(Gfx *gdl);
void bviewSetBlur(u32 bluramount);
void bviewClearBlur(void);
Gfx *bviewRenderNvBinoculars(Gfx *gdl);

#endif
