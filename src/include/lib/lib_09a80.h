#ifndef _IN_LIB_LIB_09A80_H
#define _IN_LIB_LIB_09A80_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void func00009a80(void);
void func00009a88(void);
void func00009a90(void);
void func00009a98(void);
void func00009aa0(u32 arg0);
Gfx *debugRenderSomething(Gfx *gdl);
void func00009ab0(void);
void func00009b50(void *fb);
void func00009bf8(void);
void func00009c3c(s32 stagenum);
void func00009ec4(s32 arg0);
u32 func00009ed4(void);
void func0000a044(void);
void func0000aa50(f32 arg0);
void func0000aab0(u32 arg0);
void *viGetUnk28(void);
void *vi2GetUnk28(void);
u32 func0000ab4c(void);
u32 func0000ab6c(void);
u32 func0000ab78(void);
u32 func0000aca4(void);
u32 func0000ad5c(void);
u32 func0000af00(void);
u32 func0000b0e8(void);
Gfx *func0000b1a8(Gfx *gdl);
Gfx *func0000b1d0(Gfx *gdl);
Gfx *func0000b280(Gfx *gdl);
Gfx *func0000b2c4(Gfx *gdl);
Gfx *func0000b330(Gfx *gdl);
void viSetBuf(s16 x, s16 y);
s16 viGetBufX(void);
s16 viGetBufY(void);
void viSetXY(s16 x, s16 y);
s16 viGetWidth(void);
s16 viGetHeight(void);
void viSetViewSize(s16 x, s16 y);
s16 viGetViewWidth(void);
s16 viGetViewHeight(void);
void viSetViewPosition(s16 left, s16 top);
s16 viGetViewLeft(void);
s16 viGetViewTop(void);
void viSetUseZBuf(bool use);
void viSetFovY(f32 fovy);
void viSetAspect(f32 aspect);
f32 viGetAspect(void);
void viSetFovAspectAndSize(f32 fovy, f32 aspect, s16 width, s16 height);
f32 viGetFovY(void);
void viSetZRange(f32 arg0, f32 arg1);
void viGetZRange(struct zrange *zrange);
u32 func0000bf04(void);

#endif
