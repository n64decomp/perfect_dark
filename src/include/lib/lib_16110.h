#ifndef _IN_LIB_LIB_16110_H
#define _IN_LIB_LIB_16110_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void func00016110(f32 *matrix1, f32 *matrix2);
void func00016140(f32 *realrot, f32 *arg1, f32 *arg2);
void func000161b0(f32 *matrix, f32 src[3], f32 dest[3]);
void func00016208(f32 *matrix, struct coord *coord);
void func00016248(struct coord *coord, f32 angle, Mtxf *matrix);
void func000162e8(f32 angle, Mtxf *matrix);
void func00016374(f32 angle, Mtxf *matrix);
void func00016400(f32 angle, Mtxf *matrix);
void func0001648c(struct coord *coord, Mtxf *dest);
u32 func000165d8(void);
void func000166a4(struct coord *pos, struct coord *rot, Mtxf *matrix);
void func000166dc(struct coord *pos, Mtxf *matrix);
u32 func00016710(void);
void func00016748(f32 arg0);
void func00016760(void);
void func00016784(void);
void func00016798(Mtxf *arg0, Mtxf *arg1);
void func00016820(Mtx *arg0, Mtx *arg1);
void func00016874(Mtxf *matrix, f32 posx, f32 posy, f32 posz, f32 lookx, f32 looky, f32 lookz, f32 upx, f32 upy, f32 upz);
void func00016ae4(Mtxf *matrix, f32 posx, f32 posy, f32 posz, f32 lookx, f32 looky, f32 lookz, f32 upx, f32 upy, f32 upz);
void func00016b58(Mtxf *matrix, f32 posx, f32 posy, f32 posz, f32 lookx, f32 looky, f32 lookz, f32 upx, f32 upy, f32 upz);
void func00016d58(Mtxf *matrix, f32 posx, f32 posy, f32 posz, f32 lookx, f32 looky, f32 lookz, f32 upx, f32 upy, f32 upz);
u32 func00016dcc(f32 arg0, f32 arg1);
u32 func00016e98(void);
u32 func00017028(void);
u32 func00017070(void);
u32 func000170e4(void);
u32 func0001719c(void);
u32 func000172f0(void);
u32 func00017588(void);
u32 func00017614(void);
u32 func00017a78(void);
f32 func00017c2c(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8);
f32 func00017cbc(f32 arg0, f32 arg1, f32 arg2, f32 arg3);

#endif
