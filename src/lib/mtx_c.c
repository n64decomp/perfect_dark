#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "lib/mtx.h"
#include "types.h"

f32 var8005ef10[] = {65536, 65536};

void mtx4LoadIdentity(Mtxf *mtx)
{
	mtx->m[0][0] = 1;
	mtx->m[0][1] = 0;
	mtx->m[0][2] = 0;
	mtx->m[0][3] = 0;

	mtx->m[1][0] = 0;
	mtx->m[1][1] = 1;
	mtx->m[1][2] = 0;
	mtx->m[1][3] = 0;

	mtx->m[2][0] = 0;
	mtx->m[2][1] = 0;
	mtx->m[2][2] = 1;
	mtx->m[2][3] = 0;

	mtx->m[3][0] = 0;
	mtx->m[3][1] = 0;
	mtx->m[3][2] = 0;
	mtx->m[3][3] = 1;
}

void mtx4MultMtx4InPlace(Mtxf *multmtx, Mtxf *subject)
{
	mtx4MultMtx4(multmtx, subject, subject);
}

void mtx4MultMtx4(Mtxf *mtx1, Mtxf *mtx2, Mtxf *dst)
{
	s32 i;
	f32 m00 = mtx2->m[0][0];
	f32 m01 = mtx2->m[0][1];
	f32 m02 = mtx2->m[0][2];
	f32 m03 = mtx2->m[0][3];
	f32 m10 = mtx2->m[1][0];
	f32 m11 = mtx2->m[1][1];
	f32 m12 = mtx2->m[1][2];
	f32 m13 = mtx2->m[1][3];
	f32 m20 = mtx2->m[2][0];
	f32 m21 = mtx2->m[2][1];
	f32 m22 = mtx2->m[2][2];
	f32 m23 = mtx2->m[2][3];
	f32 m30 = mtx2->m[3][0];
	f32 m31 = mtx2->m[3][1];
	f32 m32 = mtx2->m[3][2];
	f32 m33 = mtx2->m[3][3];

	for (i = 0; i < 4; i++) {
		dst->m[0][i] = mtx1->m[0][i] * m00 + mtx1->m[1][i] * m01 + mtx1->m[2][i] * m02 + mtx1->m[3][i] * m03;
		dst->m[1][i] = mtx1->m[0][i] * m10 + mtx1->m[1][i] * m11 + mtx1->m[2][i] * m12 + mtx1->m[3][i] * m13;
		dst->m[2][i] = mtx1->m[0][i] * m20 + mtx1->m[1][i] * m21 + mtx1->m[2][i] * m22 + mtx1->m[3][i] * m23;
		dst->m[3][i] = mtx1->m[0][i] * m30 + mtx1->m[1][i] * m31 + mtx1->m[2][i] * m32 + mtx1->m[3][i] * m33;
	}
}

void mtx4RotateVecInPlace(Mtxf *mtx, struct coord *vec)
{
	mtx4RotateVec(mtx, vec, vec);
}

void mtx4RotateVec(Mtxf *mtx, struct coord *vec, struct coord *dst)
{
	f32 x = vec->x;
	f32 y = vec->y;
	f32 z = vec->z;

	dst->x = mtx->m[0][0] * x + mtx->m[1][0] * y + mtx->m[2][0] * z;
	dst->y = mtx->m[0][1] * x + mtx->m[1][1] * y + mtx->m[2][1] * z;
	dst->z = mtx->m[0][2] * x + mtx->m[1][2] * y + mtx->m[2][2] * z;
}

void mtx4TransformVecInPlace(Mtxf *mtx, struct coord *vec)
{
	mtx4TransformVec(mtx, vec, vec);
}

void mtx4TransformVec(Mtxf *mtx, struct coord *vec, struct coord *dst)
{
	f32 x = vec->x;
	f32 y = vec->y;
	f32 z = vec->z;

	dst->x = mtx->m[0][0] * x + mtx->m[1][0] * y + mtx->m[2][0] * z;
	dst->y = mtx->m[0][1] * x + mtx->m[1][1] * y + mtx->m[2][1] * z;
	dst->z = mtx->m[0][2] * x + mtx->m[1][2] * y + mtx->m[2][2] * z;

	dst->x += mtx->m[3][0];
	dst->y += mtx->m[3][1];
	dst->z += mtx->m[3][2];
}

void mtx00015be0(Mtxf *matrix1, Mtxf *matrix2)
{
	mtx00015be4(matrix1, matrix2, matrix2);
}

void mtx00015be4(Mtxf *arg0, Mtxf *arg1, Mtxf *dst)
{
	f32 m00 = arg1->m[0][0];
	f32 m01 = arg1->m[0][1];
	f32 m02 = arg1->m[0][2];
	f32 m03 = arg1->m[0][3];
	f32 m10 = arg1->m[1][0];
	f32 m11 = arg1->m[1][1];
	f32 m12 = arg1->m[1][2];
	f32 m13 = arg1->m[1][3];
	f32 m20 = arg1->m[2][0];
	f32 m21 = arg1->m[2][1];
	f32 m22 = arg1->m[2][2];
	f32 m23 = arg1->m[2][3];
	f32 m30 = arg1->m[3][0];
	f32 m31 = arg1->m[3][1];
	f32 m32 = arg1->m[3][2];
	f32 m33 = arg1->m[3][3];

	dst->m[0][0] = arg0->m[0][0] * m00 + arg0->m[1][0] * m01 + arg0->m[2][0] * m02;
	dst->m[0][1] = arg0->m[0][1] * m00 + arg0->m[1][1] * m01 + arg0->m[2][1] * m02;
	dst->m[0][2] = arg0->m[0][2] * m00 + arg0->m[1][2] * m01 + arg0->m[2][2] * m02;
	dst->m[0][3] = 0;

	dst->m[1][0] = arg0->m[0][0] * m10 + arg0->m[1][0] * m11 + arg0->m[2][0] * m12;
	dst->m[1][1] = arg0->m[0][1] * m10 + arg0->m[1][1] * m11 + arg0->m[2][1] * m12;
	dst->m[1][2] = arg0->m[0][2] * m10 + arg0->m[1][2] * m11 + arg0->m[2][2] * m12;
	dst->m[1][3] = 0;

	dst->m[2][0] = arg0->m[0][0] * m20 + arg0->m[1][0] * m21 + arg0->m[2][0] * m22;
	dst->m[2][1] = arg0->m[0][1] * m20 + arg0->m[1][1] * m21 + arg0->m[2][1] * m22;
	dst->m[2][2] = arg0->m[0][2] * m20 + arg0->m[1][2] * m21 + arg0->m[2][2] * m22;
	dst->m[2][3] = 0;

	dst->m[3][0] = arg0->m[0][0] * m30 + arg0->m[1][0] * m31 + arg0->m[2][0] * m32 + arg0->m[3][0];
	dst->m[3][1] = arg0->m[0][1] * m30 + arg0->m[1][1] * m31 + arg0->m[2][1] * m32 + arg0->m[3][1];
	dst->m[3][2] = arg0->m[0][2] * m30 + arg0->m[1][2] * m31 + arg0->m[2][2] * m32 + arg0->m[3][2];
	dst->m[3][3] = 1;
}

void mtx3Copy(f32 src[3][3], f32 dst[3][3])
{
	dst[0][0] = src[0][0];
	dst[0][1] = src[0][1];
	dst[0][2] = src[0][2];

	dst[1][0] = src[1][0];
	dst[1][1] = src[1][1];
	dst[1][2] = src[1][2];

	dst[2][0] = src[2][0];
	dst[2][1] = src[2][1];
	dst[2][2] = src[2][2];
}

void mtx4Copy(Mtxf *src, Mtxf *dst)
{
	*dst = *src;
}

void mtx3ToMtx4(f32 src[3][3], Mtxf *dst)
{
	dst->m[0][0] = src[0][0];
	dst->m[0][1] = src[0][1];
	dst->m[0][2] = src[0][2];
	dst->m[0][3] = 0;

	dst->m[1][0] = src[1][0];
	dst->m[1][1] = src[1][1];
	dst->m[1][2] = src[1][2];
	dst->m[1][3] = 0;

	dst->m[2][0] = src[2][0];
	dst->m[2][1] = src[2][1];
	dst->m[2][2] = src[2][2];
	dst->m[2][3] = 0;

	dst->m[3][0] = 0;
	dst->m[3][1] = 0;
	dst->m[3][2] = 0;
	dst->m[3][3] = 1;
}

void mtx4ToMtx3(Mtxf *src, f32 dst[3][3])
{
	dst[0][0] = src->m[0][0];
	dst[0][1] = src->m[0][1];
	dst[0][2] = src->m[0][2];

	dst[1][0] = src->m[1][0];
	dst[1][1] = src->m[1][1];
	dst[1][2] = src->m[1][2];

	dst[2][0] = src->m[2][0];
	dst[2][1] = src->m[2][1];
	dst[2][2] = src->m[2][2];
}

void mtx4SetTranslation(struct coord *pos, Mtxf *mtx)
{
	mtx->m[3][0] = pos->x;
	mtx->m[3][1] = pos->y;
	mtx->m[3][2] = pos->z;
}

void mtx00015df0(f32 mult, Mtxf *mtx)
{
	mtx->m[0][0] *= mult;
	mtx->m[0][1] *= mult;
	mtx->m[0][2] *= mult;
	mtx->m[0][3] *= mult;
}

void mtx00015e24(f32 mult, Mtxf *mtx)
{
	mtx->m[0][0] *= mult;
	mtx->m[0][1] *= mult;
	mtx->m[0][2] *= mult;
}

void mtx00015e4c(f32 mult, Mtxf *mtx)
{
	mtx->m[1][0] *= mult;
	mtx->m[1][1] *= mult;
	mtx->m[1][2] *= mult;
	mtx->m[1][3] *= mult;
}

void mtx00015e80(f32 mult, Mtxf *mtx)
{
	mtx->m[1][0] *= mult;
	mtx->m[1][1] *= mult;
	mtx->m[1][2] *= mult;
}

void mtx00015ea8(f32 mult, Mtxf *mtx)
{
	mtx->m[2][0] *= mult;
	mtx->m[2][1] *= mult;
	mtx->m[2][2] *= mult;
	mtx->m[2][3] *= mult;
}

void mtx00015edc(f32 mult, Mtxf *mtx)
{
	mtx->m[2][0] *= mult;
	mtx->m[2][1] *= mult;
	mtx->m[2][2] *= mult;
}

void mtx00015f04(f32 mult, Mtxf *mtx)
{
	mtx->m[0][0] *= mult;
	mtx->m[0][1] *= mult;
	mtx->m[0][2] *= mult;
	mtx->m[0][3] *= mult;

	mtx->m[1][0] *= mult;
	mtx->m[1][1] *= mult;
	mtx->m[1][2] *= mult;
	mtx->m[1][3] *= mult;

	mtx->m[2][0] *= mult;
	mtx->m[2][1] *= mult;
	mtx->m[2][2] *= mult;
	mtx->m[2][3] *= mult;
}

void mtx00015f4c(f32 mult, Mtxf *mtx)
{
	mtx->m[0][0] *= mult;
	mtx->m[0][1] *= mult;
	mtx->m[0][2] *= mult;

	mtx->m[1][0] *= mult;
	mtx->m[1][1] *= mult;
	mtx->m[1][2] *= mult;

	mtx->m[2][0] *= mult;
	mtx->m[2][1] *= mult;
	mtx->m[2][2] *= mult;
}

void mtx00015f88(f32 mult, Mtxf *mtx)
{
	mtx->m[0][0] *= mult;
	mtx->m[0][1] *= mult;
	mtx->m[0][2] *= mult;

	mtx->m[1][0] *= mult;
	mtx->m[1][1] *= mult;
	mtx->m[1][2] *= mult;

	mtx->m[2][0] *= mult;
	mtx->m[2][1] *= mult;
	mtx->m[2][2] *= mult;

	mtx->m[3][0] *= mult;
	mtx->m[3][1] *= mult;
	mtx->m[3][2] *= mult;
}

u32 mtxGetObfuscatedRomBase(void)
{
#ifdef PLATFORM_N64
	u32 value;

	osRecvMesg(&__osPiAccessQueue, NULL, OS_MESG_BLOCK * 0x10000);

	while (IO_READ(PI_STATUS_REG) & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY));

	// osRomBase is 0xb0000000
	// load address is 0xb0000a5c
	// value is 0x1740fff9
	value = *(u32 *) (((uintptr_t) osRomBase | 0xb764b4fd) ^ 0x0764bea1);

	osSendMesg(&__osPiAccessQueue, 0, 0);

	return value;
#else
	return 0;
#endif
}

void mtxF2L(Mtxf *src, Mtxf *dst)
{
#ifndef GBI_FLOATS
	u32 src00 = (s32) (src->m[0][0] * var8005ef10[0]);
	u32 src01 = (s32) (src->m[0][1] * var8005ef10[0]);
	u32 src02 = (s32) (src->m[0][2] * var8005ef10[0]);
	u32 src03 = (s32) (src->m[0][3] * var8005ef10[1]);
	u32 src10 = (s32) (src->m[1][0] * var8005ef10[0]);
	u32 src11 = (s32) (src->m[1][1] * var8005ef10[0]);
	u32 src12 = (s32) (src->m[1][2] * var8005ef10[0]);
	u32 src13 = (s32) (src->m[1][3] * var8005ef10[1]);
	u32 src20 = (s32) (src->m[2][0] * var8005ef10[0]);
	u32 src21 = (s32) (src->m[2][1] * var8005ef10[0]);
	u32 src22 = (s32) (src->m[2][2] * var8005ef10[0]);
	u32 src23 = (s32) (src->m[2][3] * var8005ef10[1]);
	u32 src30 = (s32) (src->m[3][0] * var8005ef10[0]);
	u32 src31 = (s32) (src->m[3][1] * var8005ef10[0]);
	u32 src32 = (s32) (src->m[3][2] * var8005ef10[0]);
	u32 src33 = (s32) (src->m[3][3] * var8005ef10[1]);

	dst->l[0][0] = (src00 & 0xffff0000) | src01 >> 16;
	dst->l[0][1] = (src02 & 0xffff0000) | src03 >> 16;
	dst->l[0][2] = (src10 & 0xffff0000) | src11 >> 16;
	dst->l[0][3] = (src12 & 0xffff0000) | src13 >> 16;
	dst->l[1][0] = (src20 & 0xffff0000) | src21 >> 16;
	dst->l[1][1] = (src22 & 0xffff0000) | src23 >> 16;
	dst->l[1][2] = (src30 & 0xffff0000) | src31 >> 16;
	dst->l[1][3] = (src32 & 0xffff0000) | src33 >> 16;

	dst->l[2][0] = src00 << 16 | (src01 & 0xffff);
	dst->l[2][1] = src02 << 16 | (src03 & 0xffff);
	dst->l[2][2] = src10 << 16 | (src11 & 0xffff);
	dst->l[2][3] = src12 << 16 | (src13 & 0xffff);
	dst->l[3][0] = src20 << 16 | (src21 & 0xffff);
	dst->l[3][1] = src22 << 16 | (src23 & 0xffff);
	dst->l[3][2] = src30 << 16 | (src31 & 0xffff);
	dst->l[3][3] = src32 << 16 | (src33 & 0xffff);
#else
	bcopy(src, dst, sizeof(*dst));
#endif
}
