#ifndef IN_GAME_MENUGFX_H
#define IN_GAME_MENUGFX_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void menugfxCreateBlur(void);
Gfx *menugfxRenderBgBlur(Gfx *gdl, u32 colour, s16 arg2, s16 arg3);
Gfx *menugfxRenderDialogBackground(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, struct menudialog *dialog, u32 colour1, u32 colour2, f32 arg8);
Gfx *menugfxRenderBgGreenHaze(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2);
Gfx *menugfxDrawDropdownBackground(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2);

#if VERSION >= VERSION_NTSC_1_0
Gfx *menugfxDrawListGroupHeader(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, s32 x3, u8 alpha);
#else
Gfx *menugfxDrawListGroupHeader(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, s32 x3);
#endif

Gfx *menugfxRenderGradient(Gfx *gdl, s32 x, s32 y, s32 width, s32 height, u32 colour1, u32 colour2, u32 colour3);
Gfx *menugfxRenderSlider(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, s32 markerx, u32 colour);
Gfx *menugfx0f0e2348(Gfx *gdl);
Gfx *menugfx0f0e2498(Gfx *gdl);
Gfx *menugfxDrawTri2(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2, bool arg7);
Gfx *menugfxDrawLine(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2);
Gfx *menugfxDrawProjectedLine(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2);
Gfx *menugfxDrawShimmer(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour, bool arg6, s32 arg7, bool lefttoright);
Gfx *menugfxDrawDialogBorderLine(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2);
Gfx *menugfxDrawFilledRect(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour1, u32 colour2);
Gfx *menugfxDrawCarouselChevron(Gfx *gdl, s32 x, s32 y, s32 size, s32 direction, u32 colour1, u32 colour2);
Gfx *menugfxDrawDialogChevron(Gfx *gdl, s32 x, s32 y, s32 arg2, s32 arg3, u32 colour1, u32 colour2, f32 arg7);
Gfx *menugfxDrawCheckbox(Gfx *gdl, s32 x, s32 y, s32 size, bool fill, u32 bordercolour, u32 fillcolour);
Gfx *menugfxRenderBgFailure(Gfx *gdl);
Gfx *menugfxRenderBgCone(Gfx *gdl);
Gfx *menugfxRenderBgFailureCopy(Gfx *gdl);
void menugfxFreeParticles(void);
u32 menugfxGetParticleArraySize(void);
Gfx *menugfxRenderBgSuccess(Gfx *gdl);

#endif
