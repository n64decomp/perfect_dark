#ifndef _IN_LIB_MTX_H
#define _IN_LIB_MTX_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void mtx000159b0(Mtxf *matrix);
void mtx000159fc(Mtxf *matrix, Mtxf *arg1);
void mtx00015a00(Mtxf *matrix, Mtxf *arg1, Mtxf *arg2);
void mtx00015b10(Mtxf *matrix, struct coord *coord);
void mtx00015b14(Mtxf *matrix, struct coord *coord, struct coord *arg2);
void mtx00015b64(Mtxf *arg0, struct coord *coord);
void mtx00015b68(Mtxf *matrix, struct coord *arg1, struct coord *arg2);
void mtx00015be0(Mtxf *matrix1, Mtxf *matrix2);
void mtx00015be4(Mtxf *arg0, Mtxf *arg1, Mtxf *arg2);
void mtx00015cd8(f32 *arg0, f32 *realrot);
void mtx00015d18(Mtxf *matrix, Mtxf *arg1);
void mtx00015d54(f32 *realrot, Mtxf *matrix);
void mtx00015da0(Mtxf *arg0, f32 *arg1);
void mtx00015dd4(struct coord *pos, Mtxf *matrix);
void mtx00015df0(f32 arg0, Mtxf *matrix);
void mtx00015e24(f32 mult, f32 *matrix);
void mtx00015e4c(f32 arg0, Mtxf *matrix);
void mtx00015e80(f32 mult, f32 *matrix);
u32 mtx00015ea8(void);
void mtx00015edc(f32 mult, Mtxf *matrix);
void mtx00015f04(f32 scale, Mtxf *arg1);
void mtx00015f4c(f32 scale, Mtxf *arg1);
void mtx00015f88(f32 arg0, Mtxf *arg1);
u32 mtxGetObfuscatedRomBase(void);
void mtx00016054(Mtxf *matrix, Mtxf *arg1);
void mtx00016110(f32 *matrix1, f32 *matrix2);
void mtx00016140(f32 *realrot, f32 *arg1, f32 *arg2);
void mtx000161b0(f32 *matrix, f32 src[3], f32 dest[3]);
void mtx00016208(f32 *matrix, struct coord *coord);
void mtx00016248(struct coord *coord, f32 angle, Mtxf *matrix);
void mtx000162e8(f32 angle, Mtxf *matrix);
void mtx00016374(f32 angle, Mtxf *matrix);
void mtx00016400(f32 angle, Mtxf *matrix);
void mtx0001648c(struct coord *coord, Mtxf *dest);
u32 mtx000165d8(void);
void mtx000166a4(struct coord *pos, struct coord *rot, Mtxf *matrix);
void mtx000166dc(struct coord *pos, Mtxf *matrix);
u32 mtx00016710(void);
void mtx00016748(f32 arg0);
void mtx00016760(void);
void mtx00016784(void);
void mtx00016798(Mtxf *arg0, Mtxf *arg1);
void mtx00016820(Mtx *arg0, Mtx *arg1);
void mtx00016874(Mtxf *matrix, f32 posx, f32 posy, f32 posz, f32 lookx, f32 looky, f32 lookz, f32 upx, f32 upy, f32 upz);
void mtx00016ae4(Mtxf *matrix, f32 posx, f32 posy, f32 posz, f32 lookx, f32 looky, f32 lookz, f32 upx, f32 upy, f32 upz);
void mtx00016b58(Mtxf *matrix, f32 posx, f32 posy, f32 posz, f32 lookx, f32 looky, f32 lookz, f32 upx, f32 upy, f32 upz);
void mtx00016d58(Mtxf *matrix, f32 posx, f32 posy, f32 posz, f32 lookx, f32 looky, f32 lookz, f32 upx, f32 upy, f32 upz);
u32 mtx00016dcc(f32 arg0, f32 arg1);
u32 mtx00016e98(void);
u32 mtx00017028(void);
u32 mtx00017070(void);
u32 mtx000170e4(void);
u32 mtx0001719c(void);
u32 mtx000172f0(void);
u32 mtx00017588(void);
u32 mtx00017614(void);
u32 mtx00017a78(void);
f32 mtx00017c2c(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8);
f32 mtx00017cbc(f32 arg0, f32 arg1, f32 arg2, f32 arg3);

#endif
