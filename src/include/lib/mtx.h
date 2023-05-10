#ifndef _IN_LIB_MTX_H
#define _IN_LIB_MTX_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void mtx4LoadIdentity(Mtxf *mtx);
void mtx4MultMtx4InPlace(Mtxf *multmtx, Mtxf *subject);
void mtx4MultMtx4(Mtxf *mtx1, Mtxf *mtx2, Mtxf *dst);
void mtx4RotateVecInPlace(Mtxf *mtx, struct coord *vec);
void mtx4RotateVec(Mtxf *mtx, struct coord *vec, struct coord *dst);
void mtx4TransformVecInPlace(Mtxf *mtx, struct coord *vec);
void mtx4TransformVec(Mtxf *mtx, struct coord *vec, struct coord *dst);
void mtx00015be0(Mtxf *matrix1, Mtxf *matrix2);
void mtx00015be4(Mtxf *arg0, Mtxf *arg1, Mtxf *arg2);
void mtx3Copy(f32 src[3][3], f32 dst[3][3]);
void mtx4Copy(Mtxf *src, Mtxf *dst);
void mtx3ToMtx4(f32 src[3][3], Mtxf *dst);
void mtx4ToMtx3(Mtxf *src, f32 dst[3][3]);
void mtx4SetTranslation(struct coord *pos, Mtxf *mtx);
void mtx00015df0(f32 arg0, Mtxf *mtx);
void mtx00015e24(f32 mult, Mtxf *mtx);
void mtx00015e4c(f32 arg0, Mtxf *mtx);
void mtx00015e80(f32 mult, Mtxf *mtx);
void mtx00015ea8(f32 arg0, Mtxf *mtx);
void mtx00015edc(f32 mult, Mtxf *mtx);
void mtx00015f04(f32 scale, Mtxf *arg1);
void mtx00015f4c(f32 scale, Mtxf *arg1);
void mtx00015f88(f32 arg0, Mtxf *arg1);
u32 mtxGetObfuscatedRomBase(void);
void mtx00016054(Mtxf *mtx, Mtxf *arg1);
void mtx00016110(f32 mtx1[3][3], f32 mtx2[3][3]);
void mtx00016140(f32 mtx1[3][3], f32 mtx2[3][3], f32 dst[3][3]);
void mtx00016208(f32 mtx[3][3], struct coord *coord);
void mtx4LoadYRotationWithTranslation(struct coord *pos, f32 radians, Mtxf *mtx);
void mtx4LoadXRotation(f32 radians, Mtxf *mtx);
void mtx4LoadYRotation(f32 radians, Mtxf *mtx);
void mtx4LoadZRotation(f32 radians, Mtxf *mtx);
void mtx4LoadRotation(struct coord *rot, Mtxf *mtx);
void mtx4GetRotation(f32 mtx[4][4], struct coord *dst);
void mtx4LoadRotationAndTranslation(struct coord *pos, struct coord *rot, Mtxf *mtx);
void mtx4LoadTranslation(struct coord *pos, Mtxf *mtx);
void mtx00016710(f32 mult, f32 mtx[4][4]);
void mtx00016760(void);
void mtx00016798(Mtxf *src, Mtxf *dst);
void mtx00016820(Mtx *src, Mtx *dst);
void mtx00016874(Mtxf *mtx, f32 posx, f32 posy, f32 posz, f32 lookx, f32 looky, f32 lookz, f32 upx, f32 upy, f32 upz);
void mtx00016ae4(Mtxf *mtx, f32 posx, f32 posy, f32 posz, f32 lookx, f32 looky, f32 lookz, f32 upx, f32 upy, f32 upz);
void mtx00016b58(Mtxf *mtx, f32 posx, f32 posy, f32 posz, f32 lookx, f32 looky, f32 lookz, f32 upx, f32 upy, f32 upz);
void mtx00016d58(Mtxf *mtx, f32 posx, f32 posy, f32 posz, f32 lookx, f32 looky, f32 lookz, f32 upx, f32 upy, f32 upz);
u32 mtx00016dcc(f32 arg0, f32 arg1);
void mtx00016e98(f32 mtx[4][4], f32 angle, f32 x, f32 y, f32 z);
void mtx4Align(f32 mtx[4][4], f32 radians, f32 x, f32 y, f32 z);
void mtx4LoadRotationFrom(f32 src[4][4], f32 dst[4][4]);
void mtx000170e4(f32 src[4][4], f32 dst[4][4]);
void mtx0001719c(f32 arg0[4][4], f32 arg1[4][4]);
void mtx000172f0(f32 arg0[4][4], f32 arg1[4][4]);
void mtx00017588(f32 arg0[4][4], f32 arg1[4][4]);

#endif
