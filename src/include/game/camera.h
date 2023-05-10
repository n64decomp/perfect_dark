#ifndef _IN_GAME_CAMERA_H
#define _IN_GAME_CAMERA_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

f32 cam0f0b49b8(f32 arg0);
void camSetScale(void);
void cam0f0b4c3c(f32 *crosspos, struct coord *dst, f32 arg2);
void cam0f0b4d04(struct coord *in, f32 *out);
void cam0f0b4d68(struct coord *in, f32 out[2]);
void cam0f0b4dec(struct coord *in, f32 out[2]);
void cam0f0b4e68(f32 in[2], f32 divisor, f32 out[2]);
void cam0f0b4eb8(struct coord *arg0, f32 arg1[2], f32 zoom, f32 aspect);
Mtxf *camGetMtxF006c(void);
void camSetWorldToScreenMtxf(Mtxf *mtx);
Mtxf *cam0f0b5050(u8 *arg0);
Mtxf *cam0f0b53a4(u8 *arg0);
void camSetProjectionMtxF(Mtxf *mtx);
void cam0f0b5838(void);
bool cam0f0b5b9c(struct coord *arg0, f32 arg1);
bool camIsPosInScreenBox(struct coord *pos, f32 arg1, struct var800a4640_00 *arg2);
bool camIsPosInFovAndVisibleRoom(s16 *rooms, struct coord *pos, f32 arg2);

#endif
