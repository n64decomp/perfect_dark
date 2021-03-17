#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_3c4d0.h"
#include "lib/lib_3e730.h"
#include "lib/lib_4b170.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func0003c4d0
/*    3c4d0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3c4d4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3c4d8:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3c4dc:	afa50024 */ 	sw	$a1,0x24($sp)
/*    3c4e0:	afa60028 */ 	sw	$a2,0x28($sp)
/*    3c4e4:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3c4e8:	adc00010 */ 	sw	$zero,0x10($t6)
/*    3c4ec:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3c4f0:	ade00008 */ 	sw	$zero,0x8($t7)
/*    3c4f4:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    3c4f8:	af00000c */ 	sw	$zero,0xc($t8)
/*    3c4fc:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    3c500:	af200000 */ 	sw	$zero,0x0($t9)
/*    3c504:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    3c508:	ad000004 */ 	sw	$zero,0x4($t0)
/*    3c50c:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    3c510:	afa0001c */ 	sw	$zero,0x1c($sp)
/*    3c514:	1920000f */ 	blez	$t1,.L0003c554
/*    3c518:	00000000 */ 	nop
.L0003c51c:
/*    3c51c:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    3c520:	8fac0024 */ 	lw	$t4,0x24($sp)
/*    3c524:	8fa50020 */ 	lw	$a1,0x20($sp)
/*    3c528:	000a58c0 */ 	sll	$t3,$t2,0x3
/*    3c52c:	016a5823 */ 	subu	$t3,$t3,$t2
/*    3c530:	000b5880 */ 	sll	$t3,$t3,0x2
/*    3c534:	0c00c5dc */ 	jal	alLink
/*    3c538:	016c2021 */ 	addu	$a0,$t3,$t4
/*    3c53c:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    3c540:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    3c544:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*    3c548:	01cf082a */ 	slt	$at,$t6,$t7
/*    3c54c:	1420fff3 */ 	bnez	$at,.L0003c51c
/*    3c550:	afae001c */ 	sw	$t6,0x1c($sp)
.L0003c554:
/*    3c554:	10000001 */ 	b	.L0003c55c
/*    3c558:	00000000 */ 	nop
.L0003c55c:
/*    3c55c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3c560:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3c564:	03e00008 */ 	jr	$ra
/*    3c568:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003c56c
/*    3c56c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    3c570:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3c574:	afa40028 */ 	sw	$a0,0x28($sp)
/*    3c578:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    3c57c:	0c012194 */ 	jal	osSetIntMask
/*    3c580:	24040001 */ 	addiu	$a0,$zero,0x1
/*    3c584:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3c588:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    3c58c:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    3c590:	afaf0024 */ 	sw	$t7,0x24($sp)
/*    3c594:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    3c598:	1300000f */ 	beqz	$t8,.L0003c5d8
/*    3c59c:	00000000 */ 	nop
/*    3c5a0:	0c00c5e9 */ 	jal	alUnlink
/*    3c5a4:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    3c5a8:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    3c5ac:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*    3c5b0:	24060010 */ 	addiu	$a2,$zero,0x10
/*    3c5b4:	0c012c5c */ 	jal	bcopy
/*    3c5b8:	2484000c */ 	addiu	$a0,$a0,0xc
/*    3c5bc:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    3c5c0:	0c00c5dc */ 	jal	alLink
/*    3c5c4:	8fa50028 */ 	lw	$a1,0x28($sp)
/*    3c5c8:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    3c5cc:	8f280008 */ 	lw	$t0,0x8($t9)
/*    3c5d0:	10000005 */ 	b	.L0003c5e8
/*    3c5d4:	afa80020 */ 	sw	$t0,0x20($sp)
.L0003c5d8:
/*    3c5d8:	8faa002c */ 	lw	$t2,0x2c($sp)
/*    3c5dc:	2409ffff */ 	addiu	$t1,$zero,-1
/*    3c5e0:	a5490000 */ 	sh	$t1,0x0($t2)
/*    3c5e4:	afa00020 */ 	sw	$zero,0x20($sp)
.L0003c5e8:
/*    3c5e8:	0c012194 */ 	jal	osSetIntMask
/*    3c5ec:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    3c5f0:	10000003 */ 	b	.L0003c600
/*    3c5f4:	8fa20020 */ 	lw	$v0,0x20($sp)
/*    3c5f8:	10000001 */ 	b	.L0003c600
/*    3c5fc:	00000000 */ 	nop
.L0003c600:
/*    3c600:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3c604:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    3c608:	03e00008 */ 	jr	$ra
/*    3c60c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel alEvtqPostEvent
/*    3c610:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    3c614:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3c618:	afa40030 */ 	sw	$a0,0x30($sp)
/*    3c61c:	afa50034 */ 	sw	$a1,0x34($sp)
/*    3c620:	afa60038 */ 	sw	$a2,0x38($sp)
/*    3c624:	afa7003c */ 	sw	$a3,0x3c($sp)
/*    3c628:	afa00020 */ 	sw	$zero,0x20($sp)
/*    3c62c:	0c012194 */ 	jal	osSetIntMask
/*    3c630:	24040001 */ 	addiu	$a0,$zero,0x1
/*    3c634:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3c638:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    3c63c:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    3c640:	afaf002c */ 	sw	$t7,0x2c($sp)
/*    3c644:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    3c648:	17000005 */ 	bnez	$t8,.L0003c660
/*    3c64c:	00000000 */ 	nop
/*    3c650:	0c012194 */ 	jal	osSetIntMask
/*    3c654:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    3c658:	10000055 */ 	b	.L0003c7b0
/*    3c65c:	00000000 */ 	nop
.L0003c660:
/*    3c660:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    3c664:	8f280000 */ 	lw	$t0,0x0($t9)
/*    3c668:	15000008 */ 	bnez	$t0,.L0003c68c
/*    3c66c:	00000000 */ 	nop
/*    3c670:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*    3c674:	15200005 */ 	bnez	$t1,.L0003c68c
/*    3c678:	00000000 */ 	nop
/*    3c67c:	0c012194 */ 	jal	osSetIntMask
/*    3c680:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    3c684:	1000004a */ 	b	.L0003c7b0
/*    3c688:	00000000 */ 	nop
.L0003c68c:
/*    3c68c:	0c00c5e9 */ 	jal	alUnlink
/*    3c690:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    3c694:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*    3c698:	8fa40034 */ 	lw	$a0,0x34($sp)
/*    3c69c:	24060010 */ 	addiu	$a2,$zero,0x10
/*    3c6a0:	0c012c5c */ 	jal	bcopy
/*    3c6a4:	24a5000c */ 	addiu	$a1,$a1,0xc
/*    3c6a8:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    3c6ac:	3c017fff */ 	lui	$at,0x7fff
/*    3c6b0:	3421ffff */ 	ori	$at,$at,0xffff
/*    3c6b4:	15410003 */ 	bne	$t2,$at,.L0003c6c4
/*    3c6b8:	00000000 */ 	nop
/*    3c6bc:	240bffff */ 	addiu	$t3,$zero,-1
/*    3c6c0:	afab0020 */ 	sw	$t3,0x20($sp)
.L0003c6c4:
/*    3c6c4:	8fac0030 */ 	lw	$t4,0x30($sp)
/*    3c6c8:	258d0008 */ 	addiu	$t5,$t4,0x8
/*    3c6cc:	11a00034 */ 	beqz	$t5,.L0003c7a0
/*    3c6d0:	afad0024 */ 	sw	$t5,0x24($sp)
.L0003c6d4:
/*    3c6d4:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    3c6d8:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    3c6dc:	15e00011 */ 	bnez	$t7,.L0003c724
/*    3c6e0:	00000000 */ 	nop
/*    3c6e4:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    3c6e8:	13000004 */ 	beqz	$t8,.L0003c6fc
/*    3c6ec:	00000000 */ 	nop
/*    3c6f0:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    3c6f4:	10000004 */ 	b	.L0003c708
/*    3c6f8:	af200008 */ 	sw	$zero,0x8($t9)
.L0003c6fc:
/*    3c6fc:	8fa80038 */ 	lw	$t0,0x38($sp)
/*    3c700:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    3c704:	ad280008 */ 	sw	$t0,0x8($t1)
.L0003c708:
/*    3c708:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    3c70c:	0c00c5dc */ 	jal	alLink
/*    3c710:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    3c714:	10000022 */ 	b	.L0003c7a0
/*    3c718:	00000000 */ 	nop
/*    3c71c:	1000001c */ 	b	.L0003c790
/*    3c720:	00000000 */ 	nop
.L0003c724:
/*    3c724:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    3c728:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*    3c72c:	afab0028 */ 	sw	$t3,0x28($sp)
/*    3c730:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    3c734:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    3c738:	8dae0008 */ 	lw	$t6,0x8($t5)
/*    3c73c:	018e082a */ 	slt	$at,$t4,$t6
/*    3c740:	1020000e */ 	beqz	$at,.L0003c77c
/*    3c744:	00000000 */ 	nop
/*    3c748:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    3c74c:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    3c750:	af0f0008 */ 	sw	$t7,0x8($t8)
/*    3c754:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    3c758:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    3c75c:	8f280008 */ 	lw	$t0,0x8($t9)
/*    3c760:	01095023 */ 	subu	$t2,$t0,$t1
/*    3c764:	af2a0008 */ 	sw	$t2,0x8($t9)
/*    3c768:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    3c76c:	0c00c5dc */ 	jal	alLink
/*    3c770:	8fa50024 */ 	lw	$a1,0x24($sp)
/*    3c774:	1000000a */ 	b	.L0003c7a0
/*    3c778:	00000000 */ 	nop
.L0003c77c:
/*    3c77c:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    3c780:	8fab0038 */ 	lw	$t3,0x38($sp)
/*    3c784:	8dac0008 */ 	lw	$t4,0x8($t5)
/*    3c788:	016c7023 */ 	subu	$t6,$t3,$t4
/*    3c78c:	afae0038 */ 	sw	$t6,0x38($sp)
.L0003c790:
/*    3c790:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    3c794:	8df80000 */ 	lw	$t8,0x0($t7)
/*    3c798:	1700ffce */ 	bnez	$t8,.L0003c6d4
/*    3c79c:	afb80024 */ 	sw	$t8,0x24($sp)
.L0003c7a0:
/*    3c7a0:	0c012194 */ 	jal	osSetIntMask
/*    3c7a4:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    3c7a8:	10000001 */ 	b	.L0003c7b0
/*    3c7ac:	00000000 */ 	nop
.L0003c7b0:
/*    3c7b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3c7b4:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    3c7b8:	03e00008 */ 	jr	$ra
/*    3c7bc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003c7c0
/*    3c7c0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    3c7c4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3c7c8:	afa40030 */ 	sw	$a0,0x30($sp)
/*    3c7cc:	afa50034 */ 	sw	$a1,0x34($sp)
/*    3c7d0:	0c012194 */ 	jal	osSetIntMask
/*    3c7d4:	24040001 */ 	addiu	$a0,$zero,0x1
/*    3c7d8:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3c7dc:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    3c7e0:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    3c7e4:	afaf002c */ 	sw	$t7,0x2c($sp)
/*    3c7e8:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    3c7ec:	13000020 */ 	beqz	$t8,.L0003c870
/*    3c7f0:	00000000 */ 	nop
.L0003c7f4:
/*    3c7f4:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    3c7f8:	8f280000 */ 	lw	$t0,0x0($t9)
/*    3c7fc:	afa80028 */ 	sw	$t0,0x28($sp)
/*    3c800:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    3c804:	afa90024 */ 	sw	$t1,0x24($sp)
/*    3c808:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    3c80c:	afaa0020 */ 	sw	$t2,0x20($sp)
/*    3c810:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    3c814:	87ad0036 */ 	lh	$t5,0x36($sp)
/*    3c818:	856c000c */ 	lh	$t4,0xc($t3)
/*    3c81c:	158d000f */ 	bne	$t4,$t5,.L0003c85c
/*    3c820:	00000000 */ 	nop
/*    3c824:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3c828:	11c00007 */ 	beqz	$t6,.L0003c848
/*    3c82c:	00000000 */ 	nop
/*    3c830:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3c834:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    3c838:	8df80008 */ 	lw	$t8,0x8($t7)
/*    3c83c:	8f280008 */ 	lw	$t0,0x8($t9)
/*    3c840:	03084821 */ 	addu	$t1,$t8,$t0
/*    3c844:	ade90008 */ 	sw	$t1,0x8($t7)
.L0003c848:
/*    3c848:	0c00c5e9 */ 	jal	alUnlink
/*    3c84c:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    3c850:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*    3c854:	0c00c5dc */ 	jal	alLink
/*    3c858:	8fa50030 */ 	lw	$a1,0x30($sp)
.L0003c85c:
/*    3c85c:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    3c860:	afaa002c */ 	sw	$t2,0x2c($sp)
/*    3c864:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    3c868:	1560ffe2 */ 	bnez	$t3,.L0003c7f4
/*    3c86c:	00000000 */ 	nop
.L0003c870:
/*    3c870:	0c012194 */ 	jal	osSetIntMask
/*    3c874:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    3c878:	10000001 */ 	b	.L0003c880
/*    3c87c:	00000000 */ 	nop
.L0003c880:
/*    3c880:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3c884:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    3c888:	03e00008 */ 	jr	$ra
/*    3c88c:	00000000 */ 	nop
/*    3c890:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3c894:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3c898:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3c89c:	0c012194 */ 	jal	osSetIntMask
/*    3c8a0:	24040001 */ 	addiu	$a0,$zero,0x1
/*    3c8a4:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3c8a8:	3c0e8006 */ 	lui	$t6,%hi(var8005f114)
/*    3c8ac:	8dcef114 */ 	lw	$t6,%lo(var8005f114)($t6)
/*    3c8b0:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    3c8b4:	8dcf0020 */ 	lw	$t7,0x20($t6)
/*    3c8b8:	af0f0010 */ 	sw	$t7,0x10($t8)
/*    3c8bc:	3c198006 */ 	lui	$t9,%hi(var8005f114)
/*    3c8c0:	8f39f114 */ 	lw	$t9,%lo(var8005f114)($t9)
/*    3c8c4:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3c8c8:	8f280000 */ 	lw	$t0,0x0($t9)
/*    3c8cc:	ad280000 */ 	sw	$t0,0x0($t1)
/*    3c8d0:	3c0b8006 */ 	lui	$t3,%hi(var8005f114)
/*    3c8d4:	8d6bf114 */ 	lw	$t3,%lo(var8005f114)($t3)
/*    3c8d8:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3c8dc:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*    3c8e0:	0c012194 */ 	jal	osSetIntMask
/*    3c8e4:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    3c8e8:	10000001 */ 	b	.L0003c8f0
/*    3c8ec:	00000000 */ 	nop
.L0003c8f0:
/*    3c8f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3c8f4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3c8f8:	03e00008 */ 	jr	$ra
/*    3c8fc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003c900
/*    3c900:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3c904:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3c908:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3c90c:	0c012194 */ 	jal	osSetIntMask
/*    3c910:	24040001 */ 	addiu	$a0,$zero,0x1
/*    3c914:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3c918:	3c0e8006 */ 	lui	$t6,%hi(var8005f114)
/*    3c91c:	8dcef114 */ 	lw	$t6,%lo(var8005f114)($t6)
/*    3c920:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    3c924:	8dcf0020 */ 	lw	$t7,0x20($t6)
/*    3c928:	af0f0010 */ 	sw	$t7,0x10($t8)
/*    3c92c:	3c198006 */ 	lui	$t9,%hi(var8005f114)
/*    3c930:	8f39f114 */ 	lw	$t9,%lo(var8005f114)($t9)
/*    3c934:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3c938:	8f280000 */ 	lw	$t0,0x0($t9)
/*    3c93c:	ad280000 */ 	sw	$t0,0x0($t1)
/*    3c940:	3c0b8006 */ 	lui	$t3,%hi(var8005f114)
/*    3c944:	8d6bf114 */ 	lw	$t3,%lo(var8005f114)($t3)
/*    3c948:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3c94c:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*    3c950:	0c012194 */ 	jal	osSetIntMask
/*    3c954:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    3c958:	10000001 */ 	b	.L0003c960
/*    3c95c:	00000000 */ 	nop
.L0003c960:
/*    3c960:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3c964:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3c968:	03e00008 */ 	jr	$ra
/*    3c96c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003c970
/*    3c970:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3c974:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3c978:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3c97c:	0c012194 */ 	jal	osSetIntMask
/*    3c980:	24040001 */ 	addiu	$a0,$zero,0x1
/*    3c984:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3c988:	3c0e8006 */ 	lui	$t6,%hi(var8005f114)
/*    3c98c:	8dcef114 */ 	lw	$t6,%lo(var8005f114)($t6)
/*    3c990:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    3c994:	8dcf0020 */ 	lw	$t7,0x20($t6)
/*    3c998:	af0f0010 */ 	sw	$t7,0x10($t8)
/*    3c99c:	3c198006 */ 	lui	$t9,%hi(var8005f114)
/*    3c9a0:	8f39f114 */ 	lw	$t9,%lo(var8005f114)($t9)
/*    3c9a4:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3c9a8:	8f280000 */ 	lw	$t0,0x0($t9)
/*    3c9ac:	ad280000 */ 	sw	$t0,0x0($t1)
/*    3c9b0:	3c0b8006 */ 	lui	$t3,%hi(var8005f114)
/*    3c9b4:	8d6bf114 */ 	lw	$t3,%lo(var8005f114)($t3)
/*    3c9b8:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3c9bc:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*    3c9c0:	0c012194 */ 	jal	osSetIntMask
/*    3c9c4:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    3c9c8:	10000001 */ 	b	.L0003c9d0
/*    3c9cc:	00000000 */ 	nop
.L0003c9d0:
/*    3c9d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3c9d4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3c9d8:	03e00008 */ 	jr	$ra
/*    3c9dc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003c9e0
/*    3c9e0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    3c9e4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3c9e8:	afa40028 */ 	sw	$a0,0x28($sp)
/*    3c9ec:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    3c9f0:	afa00024 */ 	sw	$zero,0x24($sp)
/*    3c9f4:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    3c9f8:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    3c9fc:	85cf0000 */ 	lh	$t7,0x0($t6)
/*    3ca00:	a70f0016 */ 	sh	$t7,0x16($t8)
/*    3ca04:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*    3ca08:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    3ca0c:	93280004 */ 	lbu	$t0,0x4($t9)
/*    3ca10:	a528001a */ 	sh	$t0,0x1a($t1)
/*    3ca14:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    3ca18:	ad40000c */ 	sw	$zero,0xc($t2)
/*    3ca1c:	8fab002c */ 	lw	$t3,0x2c($sp)
/*    3ca20:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    3ca24:	856c0002 */ 	lh	$t4,0x2($t3)
/*    3ca28:	a5ac0018 */ 	sh	$t4,0x18($t5)
/*    3ca2c:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    3ca30:	a5c00014 */ 	sh	$zero,0x14($t6)
/*    3ca34:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    3ca38:	ade00008 */ 	sw	$zero,0x8($t7)
/*    3ca3c:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*    3ca40:	27a40024 */ 	addiu	$a0,$sp,0x24
/*    3ca44:	0c00f2ed */ 	jal	func0003cbb4
/*    3ca48:	87050000 */ 	lh	$a1,0x0($t8)
/*    3ca4c:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3ca50:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    3ca54:	1320004e */ 	beqz	$t9,.L0003cb90
/*    3ca58:	00000000 */ 	nop
/*    3ca5c:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*    3ca60:	11000043 */ 	beqz	$t0,.L0003cb70
/*    3ca64:	00000000 */ 	nop
/*    3ca68:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    3ca6c:	24090228 */ 	addiu	$t1,$zero,0x228
/*    3ca70:	ad490088 */ 	sw	$t1,0x88($t2)
/*    3ca74:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    3ca78:	8d6c0008 */ 	lw	$t4,0x8($t3)
/*    3ca7c:	ad800008 */ 	sw	$zero,0x8($t4)
/*    3ca80:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    3ca84:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    3ca88:	adcd0008 */ 	sw	$t5,0x8($t6)
/*    3ca8c:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    3ca90:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    3ca94:	af0f0008 */ 	sw	$t7,0x8($t8)
/*    3ca98:	0c00c541 */ 	jal	func00031504
/*    3ca9c:	00000000 */ 	nop
/*    3caa0:	afa20020 */ 	sw	$v0,0x20($sp)
/*    3caa4:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    3caa8:	13200015 */ 	beqz	$t9,.L0003cb00
/*    3caac:	00000000 */ 	nop
/*    3cab0:	3c088006 */ 	lui	$t0,%hi(var8005f114)
/*    3cab4:	8d08f114 */ 	lw	$t0,%lo(var8005f114)($t0)
/*    3cab8:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3cabc:	8d09001c */ 	lw	$t1,0x1c($t0)
/*    3cac0:	ad490004 */ 	sw	$t1,0x4($t2)
/*    3cac4:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    3cac8:	240b000b */ 	addiu	$t3,$zero,0xb
/*    3cacc:	a58b0008 */ 	sh	$t3,0x8($t4)
/*    3cad0:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    3cad4:	ada0000c */ 	sw	$zero,0xc($t5)
/*    3cad8:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3cadc:	240e0170 */ 	addiu	$t6,$zero,0x170
/*    3cae0:	adee0010 */ 	sw	$t6,0x10($t7)
/*    3cae4:	8fb80028 */ 	lw	$t8,0x28($sp)
/*    3cae8:	24050003 */ 	addiu	$a1,$zero,0x3
/*    3caec:	8fa60020 */ 	lw	$a2,0x20($sp)
/*    3caf0:	0c00fc79 */ 	jal	func0003f1e4
/*    3caf4:	8f040008 */ 	lw	$a0,0x8($t8)
/*    3caf8:	10000001 */ 	b	.L0003cb00
/*    3cafc:	00000000 */ 	nop
.L0003cb00:
/*    3cb00:	0c00c541 */ 	jal	func00031504
/*    3cb04:	00000000 */ 	nop
/*    3cb08:	afa20020 */ 	sw	$v0,0x20($sp)
/*    3cb0c:	8fb90020 */ 	lw	$t9,0x20($sp)
/*    3cb10:	13200015 */ 	beqz	$t9,.L0003cb68
/*    3cb14:	00000000 */ 	nop
/*    3cb18:	3c088006 */ 	lui	$t0,%hi(var8005f114)
/*    3cb1c:	8d08f114 */ 	lw	$t0,%lo(var8005f114)($t0)
/*    3cb20:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    3cb24:	8fad0020 */ 	lw	$t5,0x20($sp)
/*    3cb28:	8d09001c */ 	lw	$t1,0x1c($t0)
/*    3cb2c:	8d4b0088 */ 	lw	$t3,0x88($t2)
/*    3cb30:	012b6021 */ 	addu	$t4,$t1,$t3
/*    3cb34:	adac0004 */ 	sw	$t4,0x4($t5)
/*    3cb38:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3cb3c:	240e000f */ 	addiu	$t6,$zero,0xf
/*    3cb40:	a5ee0008 */ 	sh	$t6,0x8($t7)
/*    3cb44:	8fb80020 */ 	lw	$t8,0x20($sp)
/*    3cb48:	af000000 */ 	sw	$zero,0x0($t8)
/*    3cb4c:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    3cb50:	24050003 */ 	addiu	$a1,$zero,0x3
/*    3cb54:	8fa60020 */ 	lw	$a2,0x20($sp)
/*    3cb58:	0c00fc79 */ 	jal	func0003f1e4
/*    3cb5c:	8f240008 */ 	lw	$a0,0x8($t9)
/*    3cb60:	10000001 */ 	b	.L0003cb68
/*    3cb64:	00000000 */ 	nop
.L0003cb68:
/*    3cb68:	10000009 */ 	b	.L0003cb90
/*    3cb6c:	00000000 */ 	nop
.L0003cb70:
/*    3cb70:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    3cb74:	ad000088 */ 	sw	$zero,0x88($t0)
/*    3cb78:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    3cb7c:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    3cb80:	ad2a0008 */ 	sw	$t2,0x8($t1)
/*    3cb84:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    3cb88:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    3cb8c:	ad8b0008 */ 	sw	$t3,0x8($t4)
.L0003cb90:
/*    3cb90:	8fa20024 */ 	lw	$v0,0x24($sp)
/*    3cb94:	10000003 */ 	b	.L0003cba4
/*    3cb98:	0002102b */ 	sltu	$v0,$zero,$v0
/*    3cb9c:	10000001 */ 	b	.L0003cba4
/*    3cba0:	00000000 */ 	nop
.L0003cba4:
/*    3cba4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3cba8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    3cbac:	03e00008 */ 	jr	$ra
/*    3cbb0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0003cbb4
/*    3cbb4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    3cbb8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3cbbc:	afa40028 */ 	sw	$a0,0x28($sp)
/*    3cbc0:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    3cbc4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*    3cbc8:	3c0e8006 */ 	lui	$t6,%hi(var8005f114)
/*    3cbcc:	8dcef114 */ 	lw	$t6,%lo(var8005f114)($t6)
/*    3cbd0:	8dcf0014 */ 	lw	$t7,0x14($t6)
/*    3cbd4:	11e0000d */ 	beqz	$t7,.L0003cc0c
/*    3cbd8:	afaf0024 */ 	sw	$t7,0x24($sp)
/*    3cbdc:	8fb80024 */ 	lw	$t8,0x24($sp)
/*    3cbe0:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    3cbe4:	af380000 */ 	sw	$t8,0x0($t9)
/*    3cbe8:	0c00c5e9 */ 	jal	alUnlink
/*    3cbec:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    3cbf0:	3c058006 */ 	lui	$a1,%hi(var8005f114)
/*    3cbf4:	8ca5f114 */ 	lw	$a1,%lo(var8005f114)($a1)
/*    3cbf8:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    3cbfc:	0c00c5dc */ 	jal	alLink
/*    3cc00:	24a5000c */ 	addiu	$a1,$a1,12
/*    3cc04:	10000030 */ 	b	.L0003ccc8
/*    3cc08:	00000000 */ 	nop
.L0003cc0c:
/*    3cc0c:	3c088006 */ 	lui	$t0,%hi(var8005f114)
/*    3cc10:	8d08f114 */ 	lw	$t0,%lo(var8005f114)($t0)
/*    3cc14:	8d090004 */ 	lw	$t1,0x4($t0)
/*    3cc18:	1120000d */ 	beqz	$t1,.L0003cc50
/*    3cc1c:	afa90024 */ 	sw	$t1,0x24($sp)
/*    3cc20:	8faa0024 */ 	lw	$t2,0x24($sp)
/*    3cc24:	8fab0028 */ 	lw	$t3,0x28($sp)
/*    3cc28:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*    3cc2c:	0c00c5e9 */ 	jal	alUnlink
/*    3cc30:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    3cc34:	3c058006 */ 	lui	$a1,%hi(var8005f114)
/*    3cc38:	8ca5f114 */ 	lw	$a1,%lo(var8005f114)($a1)
/*    3cc3c:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    3cc40:	0c00c5dc */ 	jal	alLink
/*    3cc44:	24a5000c */ 	addiu	$a1,$a1,12
/*    3cc48:	1000001f */ 	b	.L0003ccc8
/*    3cc4c:	00000000 */ 	nop
.L0003cc50:
/*    3cc50:	3c0c8006 */ 	lui	$t4,%hi(var8005f114)
/*    3cc54:	8d8cf114 */ 	lw	$t4,%lo(var8005f114)($t4)
/*    3cc58:	8d8d000c */ 	lw	$t5,0xc($t4)
/*    3cc5c:	11a0001a */ 	beqz	$t5,.L0003ccc8
/*    3cc60:	afad0024 */ 	sw	$t5,0x24($sp)
.L0003cc64:
/*    3cc64:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    3cc68:	afae0020 */ 	sw	$t6,0x20($sp)
/*    3cc6c:	8faf0020 */ 	lw	$t7,0x20($sp)
/*    3cc70:	87a8002e */ 	lh	$t0,0x2e($sp)
/*    3cc74:	8df80008 */ 	lw	$t8,0x8($t7)
/*    3cc78:	87190016 */ 	lh	$t9,0x16($t8)
/*    3cc7c:	0119082a */ 	slt	$at,$t0,$t9
/*    3cc80:	1420000d */ 	bnez	$at,.L0003ccb8
/*    3cc84:	00000000 */ 	nop
/*    3cc88:	8de90088 */ 	lw	$t1,0x88($t7)
/*    3cc8c:	1520000a */ 	bnez	$t1,.L0003ccb8
/*    3cc90:	00000000 */ 	nop
/*    3cc94:	8faa0020 */ 	lw	$t2,0x20($sp)
/*    3cc98:	8fab0028 */ 	lw	$t3,0x28($sp)
/*    3cc9c:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*    3cca0:	8fac0020 */ 	lw	$t4,0x20($sp)
/*    3cca4:	8d8d0008 */ 	lw	$t5,0x8($t4)
/*    3cca8:	85ae0016 */ 	lh	$t6,0x16($t5)
/*    3ccac:	a7ae002e */ 	sh	$t6,0x2e($sp)
/*    3ccb0:	24180001 */ 	addiu	$t8,$zero,0x1
/*    3ccb4:	afb8001c */ 	sw	$t8,0x1c($sp)
.L0003ccb8:
/*    3ccb8:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    3ccbc:	8f280000 */ 	lw	$t0,0x0($t9)
/*    3ccc0:	1500ffe8 */ 	bnez	$t0,.L0003cc64
/*    3ccc4:	afa80024 */ 	sw	$t0,0x24($sp)
.L0003ccc8:
/*    3ccc8:	10000003 */ 	b	.L0003ccd8
/*    3cccc:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*    3ccd0:	10000001 */ 	b	.L0003ccd8
/*    3ccd4:	00000000 */ 	nop
.L0003ccd8:
/*    3ccd8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3ccdc:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    3cce0:	03e00008 */ 	jr	$ra
/*    3cce4:	00000000 */ 	nop
);
