#include <ultra64.h>

void guMtxF2L(f32 mf[4][4], Mtx *m)
{
	int	i, j;
	int	e1, e2;
	int	*ai, *af;

	ai = (int *) &m->m[0][0];
	af = (int *) &m->m[2][0];

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 2; j++) {
			e1 = FTOFIX32(mf[i][j * 2]);
			e2 = FTOFIX32(mf[i][j * 2 + 1]);

			*(ai++) = (e1 & 0xffff0000) | ((e2 >> 16) & 0xffff);
			*(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff);
		}
	}
}

void guMtxIdentF(float mf[4][4])
{
	int	i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			mf[i][j] = i == j ? 1 : 0;
		}
	}
}

GLOBAL_ASM(
glabel func0004a4e8
/*    4a4e8:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*    4a4ec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4a4f0:	afa40058 */ 	sw	$a0,0x58($sp)
/*    4a4f4:	0c012918 */ 	jal	guMtxIdentF
/*    4a4f8:	27a40018 */ 	addiu	$a0,$sp,0x18
/*    4a4fc:	27a40018 */ 	addiu	$a0,$sp,0x18
/*    4a500:	0c0128d8 */ 	jal	guMtxF2L
/*    4a504:	8fa50058 */ 	lw	$a1,0x58($sp)
/*    4a508:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4a50c:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*    4a510:	03e00008 */ 	jr	$ra
/*    4a514:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0004a518
/*    4a518:	3c013780 */ 	lui	$at,0x3780
/*    4a51c:	44810000 */ 	mtc1	$at,$f0
/*    4a520:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*    4a524:	00a01025 */ 	or	$v0,$a1,$zero
/*    4a528:	24a30020 */ 	addiu	$v1,$a1,0x20
/*    4a52c:	00003025 */ 	or	$a2,$zero,$zero
/*    4a530:	00804025 */ 	or	$t0,$a0,$zero
/*    4a534:	240c0004 */ 	addiu	$t4,$zero,0x4
/*    4a538:	240b0002 */ 	addiu	$t3,$zero,0x2
/*    4a53c:	3c0affff */ 	lui	$t2,0xffff
.L0004a540:
/*    4a540:	00002025 */ 	or	$a0,$zero,$zero
/*    4a544:	01004825 */ 	or	$t1,$t0,$zero
.L0004a548:
/*    4a548:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*    4a54c:	8c590000 */ 	lw	$t9,0x0($v0)
/*    4a550:	24840001 */ 	addiu	$a0,$a0,0x1
/*    4a554:	000e7c02 */ 	srl	$t7,$t6,0x10
/*    4a558:	31f8ffff */ 	andi	$t8,$t7,0xffff
/*    4a55c:	032a6824 */ 	and	$t5,$t9,$t2
/*    4a560:	030d7025 */ 	or	$t6,$t8,$t5
/*    4a564:	afae0004 */ 	sw	$t6,0x4($sp)
/*    4a568:	8c580000 */ 	lw	$t8,0x0($v0)
/*    4a56c:	8fa50004 */ 	lw	$a1,0x4($sp)
/*    4a570:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*    4a574:	00186c00 */ 	sll	$t5,$t8,0x10
/*    4a578:	44852000 */ 	mtc1	$a1,$f4
/*    4a57c:	01aa7024 */ 	and	$t6,$t5,$t2
/*    4a580:	31f9ffff */ 	andi	$t9,$t7,0xffff
/*    4a584:	032e3825 */ 	or	$a3,$t9,$t6
/*    4a588:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    4a58c:	44875000 */ 	mtc1	$a3,$f10
/*    4a590:	afa70000 */ 	sw	$a3,0x0($sp)
/*    4a594:	25290008 */ 	addiu	$t1,$t1,0x8
/*    4a598:	24420004 */ 	addiu	$v0,$v0,0x4
/*    4a59c:	46805420 */ 	cvt.s.w	$f16,$f10
/*    4a5a0:	46003202 */ 	mul.s	$f8,$f6,$f0
/*    4a5a4:	24630004 */ 	addiu	$v1,$v1,0x4
/*    4a5a8:	46008482 */ 	mul.s	$f18,$f16,$f0
/*    4a5ac:	e528fff8 */ 	swc1	$f8,-0x8($t1)
/*    4a5b0:	148bffe5 */ 	bne	$a0,$t3,.L0004a548
/*    4a5b4:	e532fffc */ 	swc1	$f18,-0x4($t1)
/*    4a5b8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*    4a5bc:	14ccffe0 */ 	bne	$a2,$t4,.L0004a540
/*    4a5c0:	25080010 */ 	addiu	$t0,$t0,0x10
/*    4a5c4:	03e00008 */ 	jr	$ra
/*    4a5c8:	27bd0010 */ 	addiu	$sp,$sp,0x10
/*    4a5cc:	00000000 */ 	nop
);
