#ifndef _IN_GAME_GAME_1531A0_H
#define _IN_GAME_GAME_1531A0_H
#include <ultra64.h>
#include "types.h"

u32 func0f1531a0(void);
u32 func0f1531b8(void);
void func0f1531dc(bool arg0);
void fontLoad(void *start, void *end, u32 *arg2, u32 *arg3, u32 arg4);
void fontsLoadForCurrentStage(void);
Gfx *func0f153628(Gfx *gdl);
Gfx *func0f153780(Gfx *gdl);
Gfx *func0f1537dc(Gfx *gdl, u32 colour);
Gfx *func0f153838(Gfx *gdl);
Gfx *func0f153858(Gfx *gdl, s32 *x, s32 *y, s32 *textwidth, s32 *textheight);
u32 func0f1538e4(void);
u32 func0f153990(void);
Gfx *func0f153a34(Gfx *gdl, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5);
u32 func0f153ab0(void);
u32 func0f153b40(void);
u32 func0f153b6c(void);
void func0f153c20(s32 x, s32 y, f32 arg2, s32 arg3);
u32 func0f153c50(void);
void func0f153c88(void);
void func0f153ce8(s32 x1, s32 x2, u32 arg2);
void func0f153d24(void);
void func0f153d3c(void);
u32 func0f153d50(void);
u32 func0f153d88(void);
void func0f153e38(u32 colour1, u32 colour2);
void func0f153e4c(void);
s32 func0f153e58(void);
u32 func0f153e94(void);
u32 func0f1543ac(void);
u32 func0f154ecc(void);
u32 func0f154f38(void);
u32 func0f1552d4(void);
u32 func0f15568c(void);
u32 func0f156024(void);
u32 func0f156030(void);
Gfx *textRenderWhite(Gfx *gdl, s32 *x, s32 *y, char *text, u32 font1, u32 font2, s32 colour, s16 width, s16 height, s32 arg9, u32 arg10);
u32 func0f1566cc(void);
u32 func0f156790(void);
u32 func0f156a24(void);
Gfx *textRender(Gfx *gdl, s32 *x, s32 *y, char *text, u32 arg4, u32 arg5, s32 arg6, u32 colour, s16 arg8, s16 arg9, u32 arg10, u32 arg11);
void textMeasure(s32 *textheight, s32 *textwidth, char *text, u32 font1, u32 font2, u32 arg5);
void textWrap(s32 width, char *in, char *out, u32 font1, u32 font2);
u32 func0f1577f0(void);
u32 func0f1578c8(void);
u32 func0f1579cc(void);

#endif
