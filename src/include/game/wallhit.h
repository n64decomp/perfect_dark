#ifndef _IN_GAME_WALLHIT_H
#define _IN_GAME_WALLHIT_H
#include <ultra64.h>
#include "types.h"

s16 func0f13e0e0(f32 arg0);
void func0f13e1b0(struct var800a41b0 *arg0);
void func0f13e40c(struct prop *prop, s8 arg1);
bool chrIsUsingPaintball(struct chrdata *chr);
void func0f13e5c8(struct prop *prop);
void func0f13e640(struct var800a41b0 *thing, s32 arg1);
u32 func0f13e744(void);
u32 func0f13e994(void);
void func0f13eb44(void);
u32 func0f13f3f4(void);
u32 func0f13f504(void);
s32 func0f140750(struct coord *coord);
u32 func0f1408a8(void);
u32 func0f140b7c(void);
Gfx *func0f140e20(Gfx *gdl, struct prop *prop, bool withalpha);
u32 func0f1411b0(void);
void func0f141234(void);
void func0f14159c(struct prop *prop);
void func0f141704(struct prop *prop);

#endif
