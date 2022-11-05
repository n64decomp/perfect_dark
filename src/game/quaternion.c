#include <ultra64.h>
#include "constants.h"
#include "game/acosfasinf.h"
#include "game/quaternion.h"
#include "bss.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

void quaternion0f096ca0(struct coord *angle, f32 quat[4])
{
	f32 cosx = cosf(angle->f[0] * 0.5f);
	f32 sinx = sinf(angle->f[0] * 0.5f);
	f32 cosy = cosf(angle->f[1] * 0.5f);
	f32 siny = sinf(angle->f[1] * 0.5f);
	f32 cosz = cosf(angle->f[2] * 0.5f);
	f32 sinz = sinf(angle->f[2] * 0.5f);

	f32 cosx_cosy = cosx * cosy;
	f32 cosx_siny = cosx * siny;
	f32 sinx_cosy = sinx * cosy;
	f32 sinx_siny = sinx * siny;

	quat[0] = cosx_cosy * cosz + sinx_siny * sinz;
	quat[1] = sinx_cosy * cosz - cosx_siny * sinz;
	quat[2] = cosx_siny * cosz + sinx_cosy * sinz;
	quat[3] = cosx_cosy * sinz - sinx_siny * cosz;
}

void quaternionToMtx(f32 quat[4], Mtxf *mtx)
{
	f32 mult = 2.0f / (quat[0] * quat[0] + quat[1] * quat[1] + quat[2] * quat[2] + quat[3] * quat[3]);
	f32 a = quat[1] * mult;
	f32 b = quat[2] * mult;
	f32 c = quat[3] * mult;

	f32 sp34 = quat[0] * a;
	f32 sp30 = quat[0] * b;
	f32 sp2c = quat[0] * c;
	f32 sp28 = quat[1] * a;
	f32 sp24 = quat[1] * b;
	f32 sp20 = quat[1] * c;
	f32 sp1c = quat[2] * b;
	f32 sp18 = quat[2] * c;
	f32 sp14 = quat[3] * c;

	mtx->m[0][0] = 1.0f - (sp1c + sp14);
	mtx->m[0][1] = sp24 + sp2c;
	mtx->m[0][2] = sp20 - sp30;

	mtx->m[1][0] = sp24 - sp2c;
	mtx->m[1][1] = 1.0f - (sp28 + sp14);
	mtx->m[1][2] = sp18 + sp34;

	mtx->m[2][0] = sp20 + sp30;
	mtx->m[2][1] = sp18 - sp34;
	mtx->m[2][2] = 1.0f - (sp28 + sp1c);

	mtx->m[3][0] = 0.0f;
	mtx->m[3][1] = 0.0f;
	mtx->m[3][2] = 0.0f;

	mtx->m[0][3] = 0.0f;
	mtx->m[1][3] = 0.0f;
	mtx->m[2][3] = 0.0f;
	mtx->m[3][3] = 1.0f;
}

void quaternion0f097044(Mtxf *mtx, f32 arg1[4])
{
	f32 var1;
	f32 var2;
	f32 trace = mtx->m[0][0] + mtx->m[1][1] + mtx->m[2][2] + 1.0f;

	if (trace > 0.01f) {
		var1 = sqrtf(trace);
		var2 = 0.5f / var1;

		arg1[0] = var1 * 0.5f;
		arg1[1] = (mtx->m[1][2] - mtx->m[2][1]) * var2;
		arg1[2] = (mtx->m[2][0] - mtx->m[0][2]) * var2;
		arg1[3] = (mtx->m[0][1] - mtx->m[1][0]) * var2;
	} else {
		s32 i;
		s32 j;
		s32 indices[3] = {1, 2, 0};
		s32 k;

		i = 0;

		if (mtx->m[0][0] < mtx->m[1][1]) {
			i = 1;
		}

		if (mtx->m[i][i] < mtx->m[2][2]) {
			i = 2;
		}

		j = indices[i];
		k = indices[j];

		var1 = sqrtf(mtx->m[i][i] - (mtx->m[j][j] + mtx->m[k][k]) + 1.0f);
		var2 = 0.5f / var1;

		arg1[i + 1] = var1 * 0.5f;
		arg1[    0] = (mtx->m[j][k] - mtx->m[k][j]) * var2;
		arg1[j + 1] = (mtx->m[i][j] + mtx->m[j][i]) * var2;
		arg1[k + 1] = (mtx->m[i][k] + mtx->m[k][i]) * var2;
	}
}

void quaternionToTransformMtx(struct coord *pos, f32 rot[4], Mtxf *mtx)
{
	quaternionToMtx(rot, mtx);

	mtx->m[3][0] = pos->x;
	mtx->m[3][1] = pos->y;
	mtx->m[3][2] = pos->z;
}

#define EPSILON 0.00001001f

void quaternionSlerp(f32 q1[4], f32 q2[4], f32 t, f32 result[4])
{
	f32 dot = q1[0] * q2[0] + q1[1] * q2[1] + q1[2] * q2[2] + q1[3] * q2[3];
	f32 theta;
	f32 theta_q1;
	f32 theta_q2;
	f32 sine;
	f32 coeff_q1;
	f32 coeff_q2;

	if (dot < -1.0f + EPSILON) {
		result[0] = (1.0f - t) * q1[0] - q2[0] * t;
		result[1] = (1.0f - t) * q1[1] - q2[1] * t;
		result[2] = (1.0f - t) * q1[2] - q2[2] * t;
		result[3] = (1.0f - t) * q1[3] - q2[3] * t;
	} else if (dot <= 1.0f - EPSILON) {
		theta = acosf(dot);
		theta_q1 = (1.0f - t) * theta;
		theta_q2 = t * theta;
		sine = sinf(theta);
		coeff_q1 = sinf(theta_q1) / sine;
		coeff_q2 = sinf(theta_q2) / sine;
		result[0] = coeff_q1 * q1[0] + q2[0] * coeff_q2;
		result[1] = coeff_q1 * q1[1] + q2[1] * coeff_q2;
		result[2] = coeff_q1 * q1[2] + q2[2] * coeff_q2;
		result[3] = coeff_q1 * q1[3] + q2[3] * coeff_q2;
	} else {
		result[0] = (1.0f - t) * q1[0] + q2[0] * t;
		result[1] = (1.0f - t) * q1[1] + q2[1] * t;
		result[2] = (1.0f - t) * q1[2] + q2[2] * t;
		result[3] = (1.0f - t) * q1[3] + q2[3] * t;
	}
}

void quaternion0f097518(f32 q[4], f32 t, f32 result[4])
{
	f32 sp34 = q[0];
	f32 sp30 = 1.0f;
	f32 sp2c;
	f32 sp28;
	f32 sp24;
	f32 sp20;
	f32 sp1c;
	f32 sp18;

	if (q[0] < 0.0f) {
		sp34 = -sp34;
		sp30 = -sp30;
	}

	if (sp34 < -0.99998999f) {
		result[0] = q[0] * t - (1.0f - t) * sp30;
		result[1] = q[1] * t;
		result[2] = q[2] * t;
		result[3] = q[3] * t;
	} else if (sp34 <= 0.99998999f) {
		sp2c = acosf(sp34);
		sp28 = t * sp2c;
		sp24 = (1.0f - t) * sp2c;
		sp20 = sinf(sp2c);
		sp1c = sinf(sp28) / sp20;
		sp18 = sinf(sp24) / sp20;

		result[0] = q[0] * sp1c + sp18 * sp30;
		result[1] = q[1] * sp1c;
		result[2] = q[2] * sp1c;
		result[3] = q[3] * sp1c;
	} else {
		result[0] = q[0] * t + (1.0f - t) * sp30;
		result[1] = q[1] * t;
		result[2] = q[2] * t;
		result[3] = q[3] * t;
	}
}

void quaternion0f0976c0(f32 q1[4], f32 q2[4])
{
	f32 dot = q1[0] * q2[0] + q1[1] * q2[1] + q1[2] * q2[2] + q1[3] * q2[3];

	if (dot < 0.0f) {
		q2[0] = -q2[0];
		q2[1] = -q2[1];
		q2[2] = -q2[2];
		q2[3] = -q2[3];
	}
}

void quaternionMultQuaternion(f32 a[4], f32 b[4], f32 result[4])
{
	result[0] = a[0] * b[0] - a[1] * b[1] - a[2] * b[2] - a[3] * b[3];
	result[1] = a[0] * b[1] + b[0] * a[1] + a[2] * b[3] - a[3] * b[2];
	result[2] = a[0] * b[2] + b[0] * a[2] + a[3] * b[1] - a[1] * b[3];
	result[3] = a[0] * b[3] + b[0] * a[3] + a[1] * b[2] - a[2] * b[1];
}
