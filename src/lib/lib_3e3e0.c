#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_3a100.h"
#include "lib/lib_3e730.h"
#include "data.h"
#include "types.h"

const u32 var70054ae0[] = {0x3dcccccd};
const u32 var70054ae4[] = {0x00000000};
const u32 var70054ae8[] = {0x00000000};
const u32 var70054aec[] = {0x00000000};

GLOBAL_ASM(
glabel func0003e3e0
/*    3e3e0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3e3e4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3e3e8:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3e3ec:	afa50024 */ 	sw	$a1,0x24($sp)
/*    3e3f0:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3e3f4:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    3e3f8:	11e0001f */ 	beqz	$t7,.L0003e478
/*    3e3fc:	00000000 */ 	nop
/*    3e400:	0c00c541 */ 	jal	func00031504
/*    3e404:	00000000 */ 	nop
/*    3e408:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3e40c:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3e410:	17000003 */ 	bnez	$t8,.L0003e420
/*    3e414:	00000000 */ 	nop
/*    3e418:	10000019 */ 	b	.L0003e480
/*    3e41c:	00000000 */ 	nop
.L0003e420:
/*    3e420:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3e424:	3c198006 */ 	lui	$t9,%hi(var8005f114)
/*    3e428:	8f39f114 */ 	lw	$t9,%lo(var8005f114)($t9)
/*    3e42c:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*    3e430:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    3e434:	8f28001c */ 	lw	$t0,0x1c($t9)
/*    3e438:	8d4b0088 */ 	lw	$t3,0x88($t2)
/*    3e43c:	010b6021 */ 	addu	$t4,$t0,$t3
/*    3e440:	adac0004 */ 	sw	$t4,0x4($t5)
/*    3e444:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    3e448:	240e0013 */ 	addiu	$t6,$zero,0x13
/*    3e44c:	a5ee0008 */ 	sh	$t6,0x8($t7)
/*    3e450:	c7a40024 */ 	lwc1	$f4,0x24($sp)
/*    3e454:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3e458:	e704000c */ 	swc1	$f4,0xc($t8)
/*    3e45c:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    3e460:	af200000 */ 	sw	$zero,0x0($t9)
/*    3e464:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3e468:	24050003 */ 	addiu	$a1,$zero,0x3
/*    3e46c:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*    3e470:	0c00fc79 */ 	jal	func0003f1e4
/*    3e474:	8d240008 */ 	lw	$a0,0x8($t1)
.L0003e478:
/*    3e478:	10000001 */ 	b	.L0003e480
/*    3e47c:	00000000 */ 	nop
.L0003e480:
/*    3e480:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3e484:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3e488:	03e00008 */ 	jr	$ra
/*    3e48c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003e490
/*    3e490:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3e494:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3e498:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3e49c:	afa50024 */ 	sw	$a1,0x24($sp)
/*    3e4a0:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3e4a4:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    3e4a8:	11e0001f */ 	beqz	$t7,.L0003e528
/*    3e4ac:	00000000 */ 	nop
/*    3e4b0:	0c00c541 */ 	jal	func00031504
/*    3e4b4:	00000000 */ 	nop
/*    3e4b8:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3e4bc:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3e4c0:	17000003 */ 	bnez	$t8,.L0003e4d0
/*    3e4c4:	00000000 */ 	nop
/*    3e4c8:	10000019 */ 	b	.L0003e530
/*    3e4cc:	00000000 */ 	nop
.L0003e4d0:
/*    3e4d0:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3e4d4:	3c198006 */ 	lui	$t9,%hi(var8005f114)
/*    3e4d8:	8f39f114 */ 	lw	$t9,%lo(var8005f114)($t9)
/*    3e4dc:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*    3e4e0:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    3e4e4:	8f28001c */ 	lw	$t0,0x1c($t9)
/*    3e4e8:	8d4b0088 */ 	lw	$t3,0x88($t2)
/*    3e4ec:	010b6021 */ 	addu	$t4,$t0,$t3
/*    3e4f0:	adac0004 */ 	sw	$t4,0x4($t5)
/*    3e4f4:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    3e4f8:	240e0012 */ 	addiu	$t6,$zero,0x12
/*    3e4fc:	a5ee0008 */ 	sh	$t6,0x8($t7)
/*    3e500:	93b80027 */ 	lbu	$t8,0x27($sp)
/*    3e504:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    3e508:	af38000c */ 	sw	$t8,0xc($t9)
/*    3e50c:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    3e510:	ad200000 */ 	sw	$zero,0x0($t1)
/*    3e514:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3e518:	24050003 */ 	addiu	$a1,$zero,0x3
/*    3e51c:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*    3e520:	0c00fc79 */ 	jal	func0003f1e4
/*    3e524:	8d440008 */ 	lw	$a0,0x8($t2)
.L0003e528:
/*    3e528:	10000001 */ 	b	.L0003e530
/*    3e52c:	00000000 */ 	nop
.L0003e530:
/*    3e530:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3e534:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3e538:	03e00008 */ 	jr	$ra
/*    3e53c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003e540
/*    3e540:	00042400 */ 	sll	$a0,$a0,0x10
/*    3e544:	00042403 */ 	sra	$a0,$a0,0x10
/*    3e548:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    3e54c:	3c0e8006 */ 	lui	$t6,%hi(var8005f114)
/*    3e550:	8dcef114 */ 	lw	$t6,%lo(var8005f114)($t6)
/*    3e554:	8dcf0030 */ 	lw	$t7,0x30($t6)
/*    3e558:	afaf0004 */ 	sw	$t7,0x4($sp)
/*    3e55c:	8fb80004 */ 	lw	$t8,0x4($sp)
/*    3e560:	3c087004 */ 	lui	$t0,%hi(func0003a100)
/*    3e564:	2508a100 */ 	addiu	$t0,$t0,%lo(func0003a100)
/*    3e568:	8f190004 */ 	lw	$t9,0x4($t8)
/*    3e56c:	1728000c */ 	bne	$t9,$t0,.L0003e5a0
/*    3e570:	00000000 */ 	nop
/*    3e574:	3c098006 */ 	lui	$t1,%hi(var8005f114)
/*    3e578:	8d29f114 */ 	lw	$t1,%lo(var8005f114)($t1)
/*    3e57c:	000458c0 */ 	sll	$t3,$a0,0x3
/*    3e580:	01645821 */ 	addu	$t3,$t3,$a0
/*    3e584:	8d2a0034 */ 	lw	$t2,0x34($t1)
/*    3e588:	000b58c0 */ 	sll	$t3,$t3,0x3
/*    3e58c:	014b6021 */ 	addu	$t4,$t2,$t3
/*    3e590:	10000007 */ 	b	.L0003e5b0
/*    3e594:	8d820020 */ 	lw	$v0,0x20($t4)
/*    3e598:	10000003 */ 	b	.L0003e5a8
/*    3e59c:	00000000 */ 	nop
.L0003e5a0:
/*    3e5a0:	10000003 */ 	b	.L0003e5b0
/*    3e5a4:	00001025 */ 	or	$v0,$zero,$zero
.L0003e5a8:
/*    3e5a8:	10000001 */ 	b	.L0003e5b0
/*    3e5ac:	00000000 */ 	nop
.L0003e5b0:
/*    3e5b0:	03e00008 */ 	jr	$ra
/*    3e5b4:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0003e5b8
/*    3e5b8:	00042400 */ 	sll	$a0,$a0,0x10
/*    3e5bc:	00042403 */ 	sra	$a0,$a0,0x10
/*    3e5c0:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    3e5c4:	3c0e8006 */ 	lui	$t6,%hi(var8005f114)
/*    3e5c8:	8dcef114 */ 	lw	$t6,%lo(var8005f114)($t6)
/*    3e5cc:	8dcf0030 */ 	lw	$t7,0x30($t6)
/*    3e5d0:	afaf0004 */ 	sw	$t7,0x4($sp)
/*    3e5d4:	8fb80004 */ 	lw	$t8,0x4($sp)
/*    3e5d8:	3c087004 */ 	lui	$t0,%hi(func0003a100)
/*    3e5dc:	2508a100 */ 	addiu	$t0,$t0,%lo(func0003a100)
/*    3e5e0:	8f190004 */ 	lw	$t9,0x4($t8)
/*    3e5e4:	1728000c */ 	bne	$t9,$t0,.L0003e618
/*    3e5e8:	00000000 */ 	nop
/*    3e5ec:	3c098006 */ 	lui	$t1,%hi(var8005f114)
/*    3e5f0:	8d29f114 */ 	lw	$t1,%lo(var8005f114)($t1)
/*    3e5f4:	000458c0 */ 	sll	$t3,$a0,0x3
/*    3e5f8:	01645821 */ 	addu	$t3,$t3,$a0
/*    3e5fc:	8d2a0034 */ 	lw	$t2,0x34($t1)
/*    3e600:	000b58c0 */ 	sll	$t3,$t3,0x3
/*    3e604:	014b6021 */ 	addu	$t4,$t2,$t3
/*    3e608:	10000007 */ 	b	.L0003e628
/*    3e60c:	8d820044 */ 	lw	$v0,0x44($t4)
/*    3e610:	10000003 */ 	b	.L0003e620
/*    3e614:	00000000 */ 	nop
.L0003e618:
/*    3e618:	10000003 */ 	b	.L0003e628
/*    3e61c:	00001025 */ 	or	$v0,$zero,$zero
.L0003e620:
/*    3e620:	10000001 */ 	b	.L0003e628
/*    3e624:	00000000 */ 	nop
.L0003e628:
/*    3e628:	03e00008 */ 	jr	$ra
/*    3e62c:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func0003e630
/*    3e630:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3e634:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3e638:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3e63c:	afa50024 */ 	sw	$a1,0x24($sp)
/*    3e640:	afa60028 */ 	sw	$a2,0x28($sp)
/*    3e644:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3e648:	afae001c */ 	sw	$t6,0x1c($sp)
/*    3e64c:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    3e650:	87a50026 */ 	lh	$a1,0x26($sp)
/*    3e654:	0c00ea50 */ 	jal	func0003a940
/*    3e658:	8fa60028 */ 	lw	$a2,0x28($sp)
/*    3e65c:	10000001 */ 	b	.L0003e664
/*    3e660:	00000000 */ 	nop
.L0003e664:
/*    3e664:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3e668:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3e66c:	03e00008 */ 	jr	$ra
/*    3e670:	00000000 */ 	nop
);

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
/*    3e6ec:	3c0e8006 */ 	lui	$t6,%hi(var8005f114)
/*    3e6f0:	8dcef114 */ 	lw	$t6,%lo(var8005f114)($t6)
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
/*    3e72c:	00000000 */ 	nop
);