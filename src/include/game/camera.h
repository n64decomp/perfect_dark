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
void cam0f0b4c3c(f32 pos2d[2], struct coord *dir2d, f32 arg2);
void cam0f0b4d04(struct coord *in, f32 *out);
void cam0f0b4d68(struct coord *in, f32 out[2]);
void cam0f0b4dec(struct coord *in, f32 out[2]);
void cam0f0b4e68(f32 in[2], f32 divisor, f32 out[2]);
void cam0f0b4eb8(struct coord *arg0, f32 arg1[2], f32 zoom, f32 aspect);
void camSetMtxL1738(Mtx *mtx);
void camSetMtxL173c(Mtx *mtx);
Mtx *camGetMtxL173c(void);
void camSetMtxF006c(Mtxf *mtx);
Mtxf *camGetMtxF006c(void);
void camSetPerspectiveMtxL(Mtx *value);
Mtx *camGetPerspectiveMtxL(void);
void camSetOrthogonalMtxL(Mtx *mtx);
Mtx *camGetOrthogonalMtxL(void);
void camSetWorldToScreenMtxf(Mtxf *mtx);
Mtxf *cam0f0b5050(u8 *arg0);
Mtxf *cam0f0b53a4(u8 *arg0);
Mtxf *camGetWorldToScreenMtxf(void);
void camSetMtxF1754(Mtxf *mtx);
Mtxf *camGetMtxF1754(void);
void camSetProjectionMtxF(Mtxf *mtx);
Mtxf *camGetProjectionMtxF(void);
void camSetLookAt(LookAt *lookat);
LookAt *camGetLookAt(void);
f32 camGetLodScaleZ(void);
f32 camGetScreenWidth(void);
f32 camGetScreenHeight(void);
f32 camGetScreenLeft(void);
f32 camGetScreenTop(void);
f32 camGetPerspAspect(void);
void cam0f0b5838(void);
bool cam0f0b5b9c(struct coord *arg0, f32 arg1);
bool camIsPosInScreenBox(struct coord *pos, f32 arg1, struct drawslot *drawslot);
bool camIsPosInFovAndVisibleRoom(RoomNum *rooms, struct coord *pos, f32 arg2);

#endif
