#include <ultra64.h>

void guOrthoF(float mf[4][4], float l, float r, float b, float t, float n, float f, float scale)
{
	int	i, j;

	guMtxIdentF(mf);

	mf[0][0] = 2.0f / (r - l);
	mf[1][1] = 2.0f / (t - b);
	mf[2][2] = -2.0f / (f - n);
	mf[3][0] = -(r + l) / (r - l);
	mf[3][1] = -(t + b) / (t - b);
	mf[3][2] = -(f + n) / (f - n);
	mf[3][3] = 1;

	for (i = 0; i < 4; i++) {
	    for (j = 0; j < 4; j++) {
			mf[i][j] *= scale;
		}
	}
}

GLOBAL_ASM(
glabel func0004fdb4
/*    4fdb4:	27bdff98 */ 	addiu	$sp,$sp,-104
/*    4fdb8:	44856000 */ 	mtc1	$a1,$f12
/*    4fdbc:	44867000 */ 	mtc1	$a2,$f14
/*    4fdc0:	44878000 */ 	mtc1	$a3,$f16
/*    4fdc4:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*    4fdc8:	c7a6007c */ 	lwc1	$f6,0x7c($sp)
/*    4fdcc:	c7a80080 */ 	lwc1	$f8,0x80($sp)
/*    4fdd0:	c7aa0084 */ 	lwc1	$f10,0x84($sp)
/*    4fdd4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    4fdd8:	afa40068 */ 	sw	$a0,0x68($sp)
/*    4fddc:	44056000 */ 	mfc1	$a1,$f12
/*    4fde0:	44067000 */ 	mfc1	$a2,$f14
/*    4fde4:	44078000 */ 	mfc1	$a3,$f16
/*    4fde8:	27a40028 */ 	addiu	$a0,$sp,0x28
/*    4fdec:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*    4fdf0:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*    4fdf4:	e7a80018 */ 	swc1	$f8,0x18($sp)
/*    4fdf8:	0c013f18 */ 	jal	guOrthoF
/*    4fdfc:	e7aa001c */ 	swc1	$f10,0x1c($sp)
/*    4fe00:	27a40028 */ 	addiu	$a0,$sp,0x28
/*    4fe04:	0c0128d8 */ 	jal	guMtxF2L
/*    4fe08:	8fa50068 */ 	lw	$a1,0x68($sp)
/*    4fe0c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    4fe10:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*    4fe14:	03e00008 */ 	jr	$ra
/*    4fe18:	00000000 */ 	nop
/*    4fe1c:	00000000 */ 	nop
);
