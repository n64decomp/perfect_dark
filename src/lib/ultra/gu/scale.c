#include <ultra64.h>

void guScaleF(float mf[4][4], float x, float y, float z)
{
	guMtxIdentF(mf);

	mf[0][0] = x;
	mf[1][1] = y;
	mf[2][2] = z;
	mf[3][3] = 1;
}

GLOBAL_ASM(
glabel guScale
/*    500e4:	44856000 */ 	mtc1	$a1,$f12
/*    500e8:	44867000 */ 	mtc1	$a2,$f14
/*    500ec:	44878000 */ 	mtc1	$a3,$f16
/*    500f0:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*    500f4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    500f8:	afa40058 */ 	sw	$a0,0x58($sp)
/*    500fc:	44056000 */ 	mfc1	$a1,$f12
/*    50100:	44067000 */ 	mfc1	$a2,$f14
/*    50104:	44078000 */ 	mfc1	$a3,$f16
/*    50108:	0c014024 */ 	jal	guScaleF
/*    5010c:	27a40018 */ 	addiu	$a0,$sp,0x18
/*    50110:	27a40018 */ 	addiu	$a0,$sp,0x18
/*    50114:	0c0128d8 */ 	jal	guMtxF2L
/*    50118:	8fa50058 */ 	lw	$a1,0x58($sp)
/*    5011c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    50120:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*    50124:	03e00008 */ 	jr	$ra
/*    50128:	00000000 */ 	nop
/*    5012c:	00000000 */ 	nop
);

// Mismatch: Goal moves a3 to f16, while this stores it in the stack.
//void guScale(Mtx *m, float x, float y, float z)
//{
//	f32 mf[4][4];
//
//	guScaleF(mf, x, y, z);
//
//	guMtxF2L(mf, m);
//}
