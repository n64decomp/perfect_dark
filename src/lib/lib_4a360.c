#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_4a360.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004a360
/*    4a360:	3c014780 */ 	lui	$at,0x4780
/*    4a364:	44810000 */ 	mtc1	$at,$f0
/*    4a368:	00a01025 */ 	or	$v0,$a1,$zero
/*    4a36c:	24a30020 */ 	addiu	$v1,$a1,0x20
/*    4a370:	00003025 */ 	or	$a2,$zero,$zero
/*    4a374:	00803825 */ 	or	$a3,$a0,$zero
/*    4a378:	240c0004 */ 	addiu	$t4,$zero,0x4
/*    4a37c:	240b0002 */ 	addiu	$t3,$zero,0x2
/*    4a380:	3c0affff */ 	lui	$t2,0xffff
.L0004a384:
/*    4a384:	00002025 */ 	or	$a0,$zero,$zero
/*    4a388:	00e04025 */ 	or	$t0,$a3,$zero
/*    4a38c:	c50e0004 */ 	lwc1	$f14,0x4($t0)
/*    4a390:	24840001 */ 	addiu	$a0,$a0,0x1
/*    4a394:	c5120000 */ 	lwc1	$f18,0x0($t0)
/*    4a398:	46007402 */ 	mul.s	$f16,$f14,$f0
/*    4a39c:	108b0019 */ 	beq	$a0,$t3,.L0004a404
/*    4a3a0:	00000000 */ 	sll	$zero,$zero,0x0
.L0004a3a4:
/*    4a3a4:	46009382 */ 	mul.s	$f14,$f18,$f0
/*    4a3a8:	24840001 */ 	addiu	$a0,$a0,0x1
/*    4a3ac:	24420004 */ 	addiu	$v0,$v0,0x4
/*    4a3b0:	24630004 */ 	addiu	$v1,$v1,0x4
/*    4a3b4:	25080008 */ 	addiu	$t0,$t0,0x8
/*    4a3b8:	4600830d */ 	trunc.w.s	$f12,$f16
/*    4a3bc:	4600738d */ 	trunc.w.s	$f14,$f14
/*    4a3c0:	44096000 */ 	mfc1	$t1,$f12
/*    4a3c4:	44057000 */ 	mfc1	$a1,$f14
/*    4a3c8:	0009cc03 */ 	sra	$t9,$t1,0x10
/*    4a3cc:	332dffff */ 	andi	$t5,$t9,0xffff
/*    4a3d0:	00aac024 */ 	and	$t8,$a1,$t2
/*    4a3d4:	030d7025 */ 	or	$t6,$t8,$t5
/*    4a3d8:	00057c00 */ 	sll	$t7,$a1,0x10
/*    4a3dc:	01eac824 */ 	and	$t9,$t7,$t2
/*    4a3e0:	ac4efffc */ 	sw	$t6,-0x4($v0)
/*    4a3e4:	3138ffff */ 	andi	$t8,$t1,0xffff
/*    4a3e8:	03386825 */ 	or	$t5,$t9,$t8
/*    4a3ec:	ac6dfffc */ 	sw	$t5,-0x4($v1)
/*    4a3f0:	c50e0004 */ 	lwc1	$f14,0x4($t0)
/*    4a3f4:	c5120000 */ 	lwc1	$f18,0x0($t0)
/*    4a3f8:	46007402 */ 	mul.s	$f16,$f14,$f0
/*    4a3fc:	148bffe9 */ 	bne	$a0,$t3,.L0004a3a4
/*    4a400:	00000000 */ 	sll	$zero,$zero,0x0
.L0004a404:
/*    4a404:	46009382 */ 	mul.s	$f14,$f18,$f0
/*    4a408:	25080008 */ 	addiu	$t0,$t0,0x8
/*    4a40c:	24420004 */ 	addiu	$v0,$v0,0x4
/*    4a410:	24630004 */ 	addiu	$v1,$v1,0x4
/*    4a414:	4600830d */ 	trunc.w.s	$f12,$f16
/*    4a418:	4600738d */ 	trunc.w.s	$f14,$f14
/*    4a41c:	44096000 */ 	mfc1	$t1,$f12
/*    4a420:	44057000 */ 	mfc1	$a1,$f14
/*    4a424:	0009cc03 */ 	sra	$t9,$t1,0x10
/*    4a428:	332dffff */ 	andi	$t5,$t9,0xffff
/*    4a42c:	00aac024 */ 	and	$t8,$a1,$t2
/*    4a430:	030d7025 */ 	or	$t6,$t8,$t5
/*    4a434:	00057c00 */ 	sll	$t7,$a1,0x10
/*    4a438:	01eac824 */ 	and	$t9,$t7,$t2
/*    4a43c:	3138ffff */ 	andi	$t8,$t1,0xffff
/*    4a440:	ac4efffc */ 	sw	$t6,-0x4($v0)
/*    4a444:	03386825 */ 	or	$t5,$t9,$t8
/*    4a448:	ac6dfffc */ 	sw	$t5,-0x4($v1)
/*    4a44c:	24c60001 */ 	addiu	$a2,$a2,0x1
/*    4a450:	14ccffcc */ 	bne	$a2,$t4,.L0004a384
/*    4a454:	24e70010 */ 	addiu	$a3,$a3,0x10
/*    4a458:	03e00008 */ 	jr	$ra
/*    4a45c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0004a460
/*    4a460:	3c013f80 */ 	lui	$at,0x3f80
/*    4a464:	00801825 */ 	or	$v1,$a0,$zero
/*    4a468:	44810000 */ 	mtc1	$at,$f0
/*    4a46c:	44801000 */ 	mtc1	$zero,$f2
/*    4a470:	24040001 */ 	addiu	$a0,$zero,0x1
/*    4a474:	00001025 */ 	or	$v0,$zero,$zero
/*    4a478:	24070004 */ 	addiu	$a3,$zero,0x4
/*    4a47c:	24060003 */ 	addiu	$a2,$zero,0x3
/*    4a480:	24050002 */ 	addiu	$a1,$zero,0x2
.L0004a484:
/*    4a484:	54400004 */ 	bnezl	$v0,.L0004a498
/*    4a488:	e4620000 */ 	swc1	$f2,0x0($v1)
/*    4a48c:	10000002 */ 	beqz	$zero,.L0004a498
/*    4a490:	e4600000 */ 	swc1	$f0,0x0($v1)
/*    4a494:	e4620000 */ 	swc1	$f2,0x0($v1)
.L0004a498:
/*    4a498:	54440004 */ 	bnel	$v0,$a0,.L0004a4ac
/*    4a49c:	e4620004 */ 	swc1	$f2,0x4($v1)
/*    4a4a0:	10000002 */ 	beqz	$zero,.L0004a4ac
/*    4a4a4:	e4600004 */ 	swc1	$f0,0x4($v1)
/*    4a4a8:	e4620004 */ 	swc1	$f2,0x4($v1)
.L0004a4ac:
/*    4a4ac:	54450004 */ 	bnel	$v0,$a1,.L0004a4c0
/*    4a4b0:	e4620008 */ 	swc1	$f2,0x8($v1)
/*    4a4b4:	10000002 */ 	beqz	$zero,.L0004a4c0
/*    4a4b8:	e4600008 */ 	swc1	$f0,0x8($v1)
/*    4a4bc:	e4620008 */ 	swc1	$f2,0x8($v1)
.L0004a4c0:
/*    4a4c0:	54460004 */ 	bnel	$v0,$a2,.L0004a4d4
/*    4a4c4:	e462000c */ 	swc1	$f2,0xc($v1)
/*    4a4c8:	10000002 */ 	beqz	$zero,.L0004a4d4
/*    4a4cc:	e460000c */ 	swc1	$f0,0xc($v1)
/*    4a4d0:	e462000c */ 	swc1	$f2,0xc($v1)
.L0004a4d4:
/*    4a4d4:	24420001 */ 	addiu	$v0,$v0,0x1
/*    4a4d8:	1447ffea */ 	bne	$v0,$a3,.L0004a484
/*    4a4dc:	24630010 */ 	addiu	$v1,$v1,0x10
/*    4a4e0:	03e00008 */ 	jr	$ra
/*    4a4e4:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a4e8:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*    4a4ec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4a4f0:	afa40058 */ 	sw	$a0,0x58($sp)
/*    4a4f4:	0c012918 */ 	jal	func0004a460
/*    4a4f8:	27a40018 */ 	addiu	$a0,$sp,0x18
/*    4a4fc:	27a40018 */ 	addiu	$a0,$sp,0x18
/*    4a500:	0c0128d8 */ 	jal	func0004a360
/*    4a504:	8fa50058 */ 	lw	$a1,0x58($sp)
/*    4a508:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4a50c:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*    4a510:	03e00008 */ 	jr	$ra
/*    4a514:	00000000 */ 	sll	$zero,$zero,0x0
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
/*    4a5cc:	00000000 */ 	sll	$zero,$zero,0x0
);

// func0004a5d0
GLOBAL_ASM(
glabel sqrtf
/*    4a5d0:	03e00008 */ 	jr	$ra
/*    4a5d4:	46006004 */ 	sqrt.s	$f0,$f12
/*    4a5d8:	00000000 */ 	sll	$zero,$zero,0x0
/*    4a5dc:	00000000 */ 	sll	$zero,$zero,0x0
);