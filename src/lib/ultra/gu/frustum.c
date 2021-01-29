#include <ultra64.h>

void guFrustumF(float mf[4][4], float l, float r, float b, float t, float n, float f, float scale)
{
	int i, j;

	guMtxIdentF(mf);

	mf[0][0] = 2 * n / (r - l);
	mf[1][1] = 2 * n / (t - b);
	mf[2][0] = (r + l) / (r - l);
	mf[2][1] = (t + b) / (t - b);
	mf[2][2] = -(f + n) / (f - n);
	mf[2][3] = -1;
	mf[3][2] = -2 * f * n / (f - n);
	mf[3][3] = 0;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			mf[i][j] *= scale;
		}
	}
}

GLOBAL_ASM(
glabel guFrustum
/*    4ff80:	27bdff98 */ 	addiu	$sp,$sp,-104
/*    4ff84:	44856000 */ 	mtc1	$a1,$f12
/*    4ff88:	44867000 */ 	mtc1	$a2,$f14
/*    4ff8c:	44878000 */ 	mtc1	$a3,$f16
/*    4ff90:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*    4ff94:	c7a6007c */ 	lwc1	$f6,0x7c($sp)
/*    4ff98:	c7a80080 */ 	lwc1	$f8,0x80($sp)
/*    4ff9c:	c7aa0084 */ 	lwc1	$f10,0x84($sp)
/*    4ffa0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    4ffa4:	afa40068 */ 	sw	$a0,0x68($sp)
/*    4ffa8:	44056000 */ 	mfc1	$a1,$f12
/*    4ffac:	44067000 */ 	mfc1	$a2,$f14
/*    4ffb0:	44078000 */ 	mfc1	$a3,$f16
/*    4ffb4:	27a40028 */ 	addiu	$a0,$sp,0x28
/*    4ffb8:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*    4ffbc:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*    4ffc0:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*    4ffc4:	0c013f88 */ 	jal	guFrustumF
/*    4ffc8:	e7aa001c */ 	swc1	$f10,0x1c($sp)
/*    4ffcc:	27a40028 */ 	addiu	$a0,$sp,0x28
/*    4ffd0:	0c0128d8 */ 	jal	guMtxF2L
/*    4ffd4:	8fa50068 */ 	lw	$a1,0x68($sp)
/*    4ffd8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    4ffdc:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*    4ffe0:	03e00008 */ 	jr	$ra
/*    4ffe4:	00000000 */ 	nop
/*    4ffe8:	00000000 */ 	nop
/*    4ffec:	00000000 */ 	nop
);

// Mismatch: Goal moves a3 to f16, while this stores it in the stack.
//void guFrustum(Mtx *m, float l, float r, float b, float t, float n, float f, float scale)
//{
//	float mf[4][4];
//
//	guFrustumF(mf, l, r, b, t, n, f, scale);
//
//	guMtxF2L(mf, m);
//}
