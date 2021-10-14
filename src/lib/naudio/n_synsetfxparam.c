#include "n_synthInternals.h"

const u32 var70054ae0[] = {0x3dcccccd};

void n_alSynSetFXParam(ALFxRef fx, s16 paramID, void *param)
{
	ALFx *f = (ALFx *)fx;

	n_alFxParamHdl(f, (s32)paramID, param);
}

GLOBAL_ASM(
glabel func0003e674
/*    3e674:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    3e678:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3e67c:	afa40018 */ 	sw	$a0,0x18($sp)
/*    3e680:	afa5001c */ 	sw	$a1,0x1c($sp)
/*    3e684:	afa60020 */ 	sw	$a2,0x20($sp)
/*    3e688:	87ae001e */ 	lh	$t6,0x1e($sp)
/*    3e68c:	24010008 */ 	addiu	$at,$zero,0x8
/*    3e690:	15c1000e */ 	bne	$t6,$at,.L0003e6cc
/*    3e694:	00000000 */ 	nop
/*    3e698:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3e69c:	3c017005 */ 	lui	$at,%hi(var70054ae0)
/*    3e6a0:	c4284ae0 */ 	lwc1	$f8,%lo(var70054ae0)($at)
/*    3e6a4:	8df80000 */ 	lw	$t8,0x0($t7)
/*    3e6a8:	8fa90018 */ 	lw	$t1,0x18($sp)
/*    3e6ac:	44982000 */ 	mtc1	$t8,$f4
/*    3e6b0:	00000000 */ 	nop
/*    3e6b4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    3e6b8:	46083282 */ 	mul.s	$f10,$f6,$f8
/*    3e6bc:	4600540d */ 	trunc.w.s	$f16,$f10
/*    3e6c0:	44088000 */ 	mfc1	$t0,$f16
/*    3e6c4:	10000009 */ 	b	.L0003e6ec
/*    3e6c8:	a5280002 */ 	sh	$t0,0x2($t1)
.L0003e6cc:
/*    3e6cc:	87aa001e */ 	lh	$t2,0x1e($sp)
/*    3e6d0:	24010009 */ 	addiu	$at,$zero,0x9
/*    3e6d4:	15410005 */ 	bne	$t2,$at,.L0003e6ec
/*    3e6d8:	00000000 */ 	nop
/*    3e6dc:	8fab0020 */ 	lw	$t3,0x20($sp)
/*    3e6e0:	8fad0018 */ 	lw	$t5,0x18($sp)
/*    3e6e4:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*    3e6e8:	a5ac0000 */ 	sh	$t4,0x0($t5)
.L0003e6ec:
/*    3e6ec:	3c0e8006 */ 	lui	$t6,%hi(n_syn)
/*    3e6f0:	8dcef114 */ 	lw	$t6,%lo(n_syn)($t6)
/*    3e6f4:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    3e6f8:	8dcf0040 */ 	lw	$t7,0x40($t6)
/*    3e6fc:	448f9000 */ 	mtc1	$t7,$f18
/*    3e700:	00000000 */ 	nop
/*    3e704:	468094a0 */ 	cvt.s.w	$f18,$f18
/*    3e708:	44059000 */ 	mfc1	$a1,$f18
/*    3e70c:	0c00ee99 */ 	jal	func0003ba64
/*    3e710:	00000000 */ 	nop
/*    3e714:	10000001 */ 	b	.L0003e71c
/*    3e718:	00000000 */ 	nop
.L0003e71c:
/*    3e71c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3e720:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    3e724:	03e00008 */ 	jr	$ra
/*    3e728:	00000000 */ 	nop
);
