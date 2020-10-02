#ifndef _IN_GAME_GAME_0B3350_H
#define _IN_GAME_GAME_0B3350_H
#include <ultra64.h>
#include "types.h"

s32 func0f0b3350(s32 value);
u32 func0f0b33f8(void);
u32 func0f0b3468(void);
u32 func0f0b34d8(void);
u32 func0f0b3548(void);
u32 func0f0b35b8(void);
u32 func0f0b3988(void);
void func0f0b39c0(Gfx **gdl, struct var800ab5a8 *arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6);
void currentPlayerSetScreenSize(f32 width, f32 height);
void currentPlayerSetScreenPosition(f32 left, f32 top);
void currentPlayerSetPerspective(f32 near, f32 fovy, f32 aspect);
f32 func0f0b49b8(f32 arg0);
void currentPlayerSetCameraScale(void);
void func0f0b4c3c(f32 *crosspos, struct coord *arg1, f32 arg2);
void func0f0b4d04(struct coord *in, f32 *out);
void func0f0b4d68(struct coord *in, struct coord *out);
void func0f0b4dec(struct coord *in, struct coord *out);
void func0f0b4e68(struct coord *in, f32 divisor, struct coord *out);
u32 func0f0b4eb8(void);
void currentPlayerSetUnk1738(u32 value);
void currentPlayerSetUnk173c(u32 value);
u32 currentPlayerGetUnk173c(void);
void currentPlayerSetUnk006c(u32 value);
u32 currentPlayerGetUnk006c(void);
void currentPlayerSetUnk1750(u32 value);
u32 currentPlayerGetUnk1750(void);
void currentPlayerSetUnk1758(u32 value);
u32 currentPlayerGetUnk1758(void);
void currentPlayerSetMatrix(f32 *value);
u32 func0f0b5050(void);
u32 func0f0b53a4(void);
f32 *currentPlayerGetMatrix(void);
void currentPlayerSetUnk1754(u32 value);
u32 currentPlayerGetUnk1754(void);
void currentPlayerSetUnk174c(u32 value);
u32 currentPlayerGetUnk174c(void);
void currentPlayerSetUnk175c(u32 value);
u32 currentPlayerGetUnk175c(void);
f32 currentPlayerGetLodScaleZ(void);
f32 currentPlayerGetScreenWidth(void);
f32 currentPlayerGetScreenHeight(void);
f32 currentPlayerGetScreenLeft(void);
f32 currentPlayerGetScreenTop(void);
f32 currentPlayerGetPerspAspect(void);
u32 func0f0b5838(void);
u32 func0f0b5b9c(void);
u32 func0f0b5d38(void);
u32 func0f0b6260(void);

#endif
