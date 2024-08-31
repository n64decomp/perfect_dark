#ifndef _IN_LIB_MTX_H
#define _IN_LIB_MTX_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void mtx4_load_identity(Mtxf *mtx);
void mtx4_mult_mtx4_in_place(Mtxf *multmtx, Mtxf *subject);
void mtx4_mult_mtx4(Mtxf *mtx1, Mtxf *mtx2, Mtxf *dst);
void mtx4_rotate_vec_in_place(Mtxf *mtx, struct coord *vec);
void mtx4_rotate_vec(Mtxf *mtx, struct coord *vec, struct coord *dst);
void mtx4_transform_vec_in_place(Mtxf *mtx, struct coord *vec);
void mtx4_transform_vec(Mtxf *mtx, struct coord *vec, struct coord *dst);
void mtx00015be0(Mtxf *matrix1, Mtxf *matrix2);
void mtx00015be4(Mtxf *arg0, Mtxf *arg1, Mtxf *dst);
void mtx3_copy(f32 src[3][3], f32 dst[3][3]);
void mtx4_copy(Mtxf *src, Mtxf *dst);
void mtx3_to_mtx4(f32 src[3][3], Mtxf *dst);
void mtx4_to_mtx3(Mtxf *src, f32 dst[3][3]);
void mtx4_set_translation(struct coord *pos, Mtxf *mtx);
void mtx00015df0(f32 arg0, Mtxf *mtx);
void mtx00015e24(f32 mult, Mtxf *mtx);
void mtx00015e4c(f32 arg0, Mtxf *mtx);
void mtx00015e80(f32 mult, Mtxf *mtx);
void mtx00015ea8(f32 arg0, Mtxf *mtx);
void mtx00015edc(f32 mult, Mtxf *mtx);
void mtx00015f04(f32 scale, Mtxf *arg1);
void mtx00015f4c(f32 scale, Mtxf *arg1);
void mtx00015f88(f32 arg0, Mtxf *arg1);
u32 mtx_get_obfuscated_rom_base(void);
void mtx_f2l(Mtxf *src, Mtxf *dst);
void mtx00016110(f32 mtx1[3][3], f32 mtx2[3][3]);
void mtx00016140(f32 mtx1[3][3], f32 mtx2[3][3], f32 dst[3][3]);
void mtx00016208(f32 mtx[3][3], struct coord *coord);
void mtx4_load_y_rotation_with_translation(struct coord *pos, f32 radians, Mtxf *mtx);
void mtx4_load_x_rotation(f32 radians, Mtxf *mtx);
void mtx4_load_y_rotation(f32 radians, Mtxf *mtx);
void mtx4_load_z_rotation(f32 radians, Mtxf *mtx);
void mtx4_load_rotation(struct coord *rot, Mtxf *mtx);
void mtx4_get_rotation(f32 mtx[4][4], struct coord *dst);
void mtx4_load_rotation_and_translation(struct coord *pos, struct coord *rot, Mtxf *mtx);
void mtx4_load_translation(struct coord *pos, Mtxf *mtx);
void mtx00016710(f32 mult, f32 mtx[4][4]);
void mtx00016748(f32 arg0);
void mtx00016760(void);
void mtx00016784(void);
void mtx00016798(Mtxf *src, Mtxf *dst);
void mtx00016820(Mtx *src, Mtx *dst);
void mtx00016874(Mtxf *mtx, f32 posx, f32 posy, f32 posz, f32 lookx, f32 looky, f32 lookz, f32 upx, f32 upy, f32 upz);
void mtx00016ae4(Mtxf *mtx, f32 posx, f32 posy, f32 posz, f32 lookx, f32 looky, f32 lookz, f32 upx, f32 upy, f32 upz);
void mtx00016b58(Mtxf *mtx, f32 posx, f32 posy, f32 posz, f32 lookx, f32 looky, f32 lookz, f32 upx, f32 upy, f32 upz);
void mtx00016d58(Mtxf *mtx, f32 posx, f32 posy, f32 posz, f32 lookx, f32 looky, f32 lookz, f32 upx, f32 upy, f32 upz);
u32 mtx00016dcc(f32 arg0, f32 arg1);
void mtx00016e98(f32 mtx[4][4], f32 angle, f32 x, f32 y, f32 z);
void mtx4_align(f32 mtx[4][4], f32 radians, f32 x, f32 y, f32 z);
void mtx4_load_rotation_from(f32 src[4][4], f32 dst[4][4]);
void mtx000170e4(f32 src[4][4], f32 dst[4][4]);
void mtx0001719c(f32 arg0[4][4], f32 arg1[4][4]);
void mtx000172f0(f32 arg0[4][4], f32 arg1[4][4]);
void mtx00017588(f32 arg0[4][4], f32 arg1[4][4]);

#endif
