#ifndef _IN_GAME_GAME_0B4950_H
#define _IN_GAME_GAME_0B4950_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

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
void func0f0b4eb8(struct coord *arg0, f32 arg1[2], f32 zoom, f32 aspect);
void currentPlayerSetUnk1738(void *matrix);
void currentPlayerSetUnk173c(Mtx *matrix);
Mtx *currentPlayerGetUnk173c(void);
void currentPlayerSetUnk006c(Mtxf *matrix);
Mtxf *currentPlayerGetUnk006c(void);
void currentPlayerSetUnk1750(void *value);
void *currentPlayerGetUnk1750(void);
void currentPlayerSetUnk1758(Mtx *matrix);
Mtx *currentPlayerGetUnk1758(void);
void currentPlayerSetMatrix1740(Mtxf *value);
Mtxf *func0f0b5050(Mtxf *matrix);
u32 func0f0b53a4(void);
Mtxf *currentPlayerGetMatrix1740(void);
void currentPlayerSetUnk1754(Mtxf *matrix);
Mtxf *currentPlayerGetUnk1754(void);
void currentPlayerSetUnk174c(Mtxf *matrix);
Mtxf *currentPlayerGetUnk174c(void);
void currentPlayerSetUnk175c(void *value);
void *currentPlayerGetUnk175c(void);
f32 currentPlayerGetLodScaleZ(void);
f32 currentPlayerGetScreenWidth(void);
f32 currentPlayerGetScreenHeight(void);
f32 currentPlayerGetScreenLeft(void);
f32 currentPlayerGetScreenTop(void);
f32 currentPlayerGetPerspAspect(void);
void func0f0b5838(void);
u32 func0f0b5b9c(void);
u32 func0f0b5d38(void);
u32 func0f0b6260(void);

#endif
