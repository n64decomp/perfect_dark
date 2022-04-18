#ifndef _IN_GAME_CAMERA_H
#define _IN_GAME_CAMERA_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void camSetScreenSize(f32 width, f32 height);
void camSetScreenPosition(f32 left, f32 top);
void camSetPerspective(f32 near, f32 fovy, f32 aspect);
f32 cam0f0b49b8(f32 arg0);
void camSetScale(void);
void cam0f0b4c3c(f32 *crosspos, struct coord *dst, f32 arg2);
void cam0f0b4d04(struct coord *in, f32 *out);
void cam0f0b4d68(struct coord *in, f32 out[2]);
void cam0f0b4dec(struct coord *in, f32 out[2]);
void cam0f0b4e68(struct coord *in, f32 divisor, struct coord *out);
void cam0f0b4eb8(struct coord *arg0, f32 arg1[2], f32 zoom, f32 aspect);
void camSetUnk1738(void *matrix);
void camSetUnk173c(Mtx *matrix);
Mtx *camGetUnk173c(void);
void camSetUnk006c(Mtxf *matrix);
Mtxf *camGetUnk006c(void);
void camSetUnk1750(void *value);
void *camGetUnk1750(void);
void camSetUnk1758(Mtx *matrix);
Mtx *camGetUnk1758(void);
void camSetMatrix1740(Mtxf *value);
Mtxf *cam0f0b5050(Mtxf *matrix);
void *cam0f0b53a4(u8 *arg0);
Mtxf *camGetMatrix1740(void);
void camSetUnk1754(Mtxf *matrix);
Mtxf *camGetUnk1754(void);
void camSetUnk174c(Mtxf *matrix);
Mtxf *camGetUnk174c(void);
void camSetUnk175c(Mtxf *matrix);
Mtxf *camGetUnk175c(void);
f32 camGetLodScaleZ(void);
f32 camGetScreenWidth(void);
f32 camGetScreenHeight(void);
f32 camGetScreenLeft(void);
f32 camGetScreenTop(void);
f32 camGetPerspAspect(void);
void cam0f0b5838(void);
bool cam0f0b5b9c(struct coord *arg0, f32 arg1);
bool cam0f0b5d38(struct coord *pos, f32 arg1, struct var800a4640_00 *arg2);
bool cam0f0b6260(s16 *rooms, struct coord *coord, f32 arg2);

#endif
