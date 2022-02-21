#include <ultra64.h>
#include "constants.h"
#include "game/acosfasinf.h"
#include "game/game_096ca0.h"
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

void quaternionSetRotationAroundX(f32 angle, f32 quat[4])
{
	quat[0] = cosf(angle * 0.5f);
	quat[1] = sinf(angle * 0.5f);
	quat[2] = 0.0f;
	quat[3] = 0.0f;
}

void quaternionSetRotationAroundY(f32 angle, f32 quat[4])
{
	quat[0] = cosf(angle * 0.5f);
	quat[1] = 0.0f;
	quat[2] = sinf(angle * 0.5f);
	quat[3] = 0.0f;
}

void quaternionSetRotationAroundZ(f32 angle, f32 quat[4])
{
	quat[0] = cosf(angle * 0.5f);
	quat[1] = 0.0f;
	quat[2] = 0.0f;
	quat[3] = sinf(angle * 0.5f);
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

GLOBAL_ASM(
glabel func0f097518
.late_rodata
glabel var7f1ab87c
.word 0xbf7fff58
glabel var7f1ab880
.word 0x3f7fff58
.text
/*  f097518:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f09751c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f097520:	c4800000 */ 	lwc1	$f0,0x0($a0)
/*  f097524:	44802000 */ 	mtc1	$zero,$f4
/*  f097528:	3c013f80 */ 	lui	$at,0x3f80
/*  f09752c:	44811000 */ 	mtc1	$at,$f2
/*  f097530:	4604003c */ 	c.lt.s	$f0,$f4
/*  f097534:	44857000 */ 	mtc1	$a1,$f14
/*  f097538:	3c017f1b */ 	lui	$at,%hi(var7f1ab87c)
/*  f09753c:	46000306 */ 	mov.s	$f12,$f0
/*  f097540:	45000003 */ 	bc1f	.L0f097550
/*  f097544:	46001406 */ 	mov.s	$f16,$f2
/*  f097548:	46006307 */ 	neg.s	$f12,$f12
/*  f09754c:	46001407 */ 	neg.s	$f16,$f2
.L0f097550:
/*  f097550:	c426b87c */ 	lwc1	$f6,%lo(var7f1ab87c)($at)
/*  f097554:	3c017f1b */ 	lui	$at,%hi(var7f1ab880)
/*  f097558:	4606603c */ 	c.lt.s	$f12,$f6
/*  f09755c:	00000000 */ 	nop
/*  f097560:	45000011 */ 	bc1f	.L0f0975a8
/*  f097564:	00000000 */ 	nop
/*  f097568:	460e1281 */ 	sub.s	$f10,$f2,$f14
/*  f09756c:	460e0202 */ 	mul.s	$f8,$f0,$f14
/*  f097570:	00000000 */ 	nop
/*  f097574:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f097578:	46124101 */ 	sub.s	$f4,$f8,$f18
/*  f09757c:	e4c40000 */ 	swc1	$f4,0x0($a2)
/*  f097580:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f097584:	460e3282 */ 	mul.s	$f10,$f6,$f14
/*  f097588:	e4ca0004 */ 	swc1	$f10,0x4($a2)
/*  f09758c:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f097590:	460e4482 */ 	mul.s	$f18,$f8,$f14
/*  f097594:	e4d20008 */ 	swc1	$f18,0x8($a2)
/*  f097598:	c484000c */ 	lwc1	$f4,0xc($a0)
/*  f09759c:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f0975a0:	10000043 */ 	b	.L0f0976b0
/*  f0975a4:	e4c6000c */ 	swc1	$f6,0xc($a2)
.L0f0975a8:
/*  f0975a8:	c42ab880 */ 	lwc1	$f10,%lo(var7f1ab880)($at)
/*  f0975ac:	460a603e */ 	c.le.s	$f12,$f10
/*  f0975b0:	00000000 */ 	nop
/*  f0975b4:	45020030 */ 	bc1fl	.L0f097678
/*  f0975b8:	460e1201 */ 	sub.s	$f8,$f2,$f14
/*  f0975bc:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0975c0:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0975c4:	e7ae003c */ 	swc1	$f14,0x3c($sp)
/*  f0975c8:	0fc25a74 */ 	jal	acosf
/*  f0975cc:	e7b00030 */ 	swc1	$f16,0x30($sp)
/*  f0975d0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0975d4:	44811000 */ 	mtc1	$at,$f2
/*  f0975d8:	c7ae003c */ 	lwc1	$f14,0x3c($sp)
/*  f0975dc:	46000306 */ 	mov.s	$f12,$f0
/*  f0975e0:	460e1481 */ 	sub.s	$f18,$f2,$f14
/*  f0975e4:	46007202 */ 	mul.s	$f8,$f14,$f0
/*  f0975e8:	00000000 */ 	nop
/*  f0975ec:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0975f0:	e7a80028 */ 	swc1	$f8,0x28($sp)
/*  f0975f4:	0c0068f7 */ 	jal	sinf
/*  f0975f8:	e7a40024 */ 	swc1	$f4,0x24($sp)
/*  f0975fc:	e7a00020 */ 	swc1	$f0,0x20($sp)
/*  f097600:	0c0068f7 */ 	jal	sinf
/*  f097604:	c7ac0028 */ 	lwc1	$f12,0x28($sp)
/*  f097608:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*  f09760c:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*  f097610:	46060083 */ 	div.s	$f2,$f0,$f6
/*  f097614:	0c0068f7 */ 	jal	sinf
/*  f097618:	e7a2001c */ 	swc1	$f2,0x1c($sp)
/*  f09761c:	c7b20020 */ 	lwc1	$f18,0x20($sp)
/*  f097620:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f097624:	c7a2001c */ 	lwc1	$f2,0x1c($sp)
/*  f097628:	46120103 */ 	div.s	$f4,$f0,$f18
/*  f09762c:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f097630:	c7b00030 */ 	lwc1	$f16,0x30($sp)
/*  f097634:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f097638:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f09763c:	00000000 */ 	nop
/*  f097640:	46102182 */ 	mul.s	$f6,$f4,$f16
/*  f097644:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f097648:	e4ca0000 */ 	swc1	$f10,0x0($a2)
/*  f09764c:	c4920004 */ 	lwc1	$f18,0x4($a0)
/*  f097650:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f097654:	e4c40004 */ 	swc1	$f4,0x4($a2)
/*  f097658:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f09765c:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f097660:	e4c60008 */ 	swc1	$f6,0x8($a2)
/*  f097664:	c48a000c */ 	lwc1	$f10,0xc($a0)
/*  f097668:	46025482 */ 	mul.s	$f18,$f10,$f2
/*  f09766c:	10000010 */ 	b	.L0f0976b0
/*  f097670:	e4d2000c */ 	swc1	$f18,0xc($a2)
/*  f097674:	460e1201 */ 	sub.s	$f8,$f2,$f14
.L0f097678:
/*  f097678:	460e0102 */ 	mul.s	$f4,$f0,$f14
/*  f09767c:	00000000 */ 	nop
/*  f097680:	46104182 */ 	mul.s	$f6,$f8,$f16
/*  f097684:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f097688:	e4ca0000 */ 	swc1	$f10,0x0($a2)
/*  f09768c:	c4920004 */ 	lwc1	$f18,0x4($a0)
/*  f097690:	460e9202 */ 	mul.s	$f8,$f18,$f14
/*  f097694:	e4c80004 */ 	swc1	$f8,0x4($a2)
/*  f097698:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f09769c:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f0976a0:	e4c60008 */ 	swc1	$f6,0x8($a2)
/*  f0976a4:	c48a000c */ 	lwc1	$f10,0xc($a0)
/*  f0976a8:	460e5482 */ 	mul.s	$f18,$f10,$f14
/*  f0976ac:	e4d2000c */ 	swc1	$f18,0xc($a2)
.L0f0976b0:
/*  f0976b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0976b4:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0976b8:	03e00008 */ 	jr	$ra
/*  f0976bc:	00000000 */ 	nop
);

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

void quaternionMultQuaternionInPlace(f32 a[4], f32 dst[4])
{
	f32 tmp[4];

	quaternionMultQuaternion(a, dst, tmp);

	dst[0] = tmp[0];
	dst[1] = tmp[1];
	dst[2] = tmp[2];
	dst[3] = tmp[3];
}
