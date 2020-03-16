#ifndef _IN_GAME_GAME_0B3350_H
#define _IN_GAME_GAME_0B3350_H
#include <ultra64.h>
#include "types.h"

u32 func0f0b3350(void);
u32 func0f0b33f8(void);
u32 func0f0b3468(void);
u32 func0f0b34d8(void);
u32 func0f0b3548(void);
u32 func0f0b35b8(void);
u32 func0f0b3988(void);
u32 func0f0b39c0(void);
void currentPlayerSetScreenSize(f32 width, f32 height);
void currentPlayerSetScreenPosition(f32 left, f32 top);
void currentPlayerSetPerspective(f32 near, f32 fovy, f32 aspect);
f32 func0f0b49b8(f32 arg0);
void currentPlayerSetCameraScale(void);
u32 func0f0b4c3c(void);
void func0f0b4d04(struct coord *in, struct coord *out);
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
void currentPlayerSetUnk1740(f32 *value);
u32 func0f0b5050(void);
u32 func0f0b53a4(void);
f32 *currentPlayerGetUnk1740(void);
void currentPlayerSetUnk1754(u32 value);
u32 currentPlayerGetUnk1754(void);
void currentPlayerSetUnk174c(u32 value);
u32 currentPlayerGetUnk174c(void);
void currentPlayerSetUnk175c(u32 value);
u32 func0f0b57a8(void);
u32 func0f0b57b8(void);
f32 func0f0b57d8(void);
f32 func0f0b57e8(void);
f32 func0f0b57f8(void);
f32 func0f0b5808(void);
u32 func0f0b5828(void);
u32 func0f0b5838(void);
u32 func0f0b5b9c(void);
u32 func0f0b5d38(void);
u32 func0f0b6260(void);

#endif
