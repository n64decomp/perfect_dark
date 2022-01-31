#ifndef IN_GAME_GAME_0E0770_H
#define IN_GAME_GAME_0E0770_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void menuCreateBlur(void);
Gfx *menugfxRenderBgBlur(Gfx *gdl, u32 colour, s32 arg2, s32 arg3);
Gfx *menugfxRenderDialogBackground(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, struct menudialog *dialog, u32 colour1, u32 colour2, f32 arg8);
u32 func0f0e1668(void);
u32 func0f0e194c(void);
Gfx *menugfxRenderGradient(Gfx *gdl, s32 x, s32 y, s32 width, s32 height, u32 colour1, u32 colour2, u32 colour3);
u32 func0f0e1fac(void);
Gfx *func0f0e2348(Gfx *gdl);
Gfx *func0f0e2498(Gfx *gdl);
Gfx *gfxDrawTri2(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2, bool arg7);
Gfx *gfxDrawLine(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2);
Gfx *gfxDrawTessellatedRect(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2);
Gfx *func0f0e2aa4(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colourleft, u32 arg6, u32 arg7, u32 arg8);
Gfx *menugfxRenderDialogBorderLine(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2);
Gfx *gfxDrawFilledRect(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2);
Gfx *gfxDrawEquTri(Gfx *gdl, s32 x, s32 y, s32 size, s32 direction, u32 colour1, u32 colour2);
Gfx *func0f0e3324(Gfx *gdl, s32 x, s32 y, s32 arg2, s32 arg3, u32 colour1, u32 colour2, f32 arg7);
Gfx *gfxDrawSquare(Gfx *gdl, s32 x, s32 y, s32 size, bool fill, u32 bordercolour, u32 fillcolour);
Gfx *menugfxRenderBgFailure(Gfx *gdl);
Gfx *func0f0e4190(Gfx *gdl);
void func0f0e4fd4(void);
u32 func0f0e4fe0(void);
Gfx *menugfxRenderBgSuccess(Gfx *gdl);

#endif
