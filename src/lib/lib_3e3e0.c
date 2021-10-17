#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_3a100.h"
#include "data.h"
#include "types.h"

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
/*    3e4b0:	0c00c541 */ 	jal	__n_allocParam
/*    3e4b4:	00000000 */ 	nop
/*    3e4b8:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3e4bc:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3e4c0:	17000003 */ 	bnez	$t8,.L0003e4d0
/*    3e4c4:	00000000 */ 	nop
/*    3e4c8:	10000019 */ 	b	.L0003e530
/*    3e4cc:	00000000 */ 	nop
.L0003e4d0:
/*    3e4d0:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3e4d4:	3c198006 */ 	lui	$t9,%hi(n_syn)
/*    3e4d8:	8f39f114 */ 	lw	$t9,%lo(n_syn)($t9)
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
/*    3e520:	0c00fc79 */ 	jal	n_alEnvmixerParam
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
/*    3e54c:	3c0e8006 */ 	lui	$t6,%hi(n_syn)
/*    3e550:	8dcef114 */ 	lw	$t6,%lo(n_syn)($t6)
/*    3e554:	8dcf0030 */ 	lw	$t7,0x30($t6)
/*    3e558:	afaf0004 */ 	sw	$t7,0x4($sp)
/*    3e55c:	8fb80004 */ 	lw	$t8,0x4($sp)
/*    3e560:	3c087004 */ 	lui	$t0,%hi(n_alAuxBusPull)
/*    3e564:	2508a100 */ 	addiu	$t0,$t0,%lo(n_alAuxBusPull)
/*    3e568:	8f190004 */ 	lw	$t9,0x4($t8)
/*    3e56c:	1728000c */ 	bne	$t9,$t0,.L0003e5a0
/*    3e570:	00000000 */ 	nop
/*    3e574:	3c098006 */ 	lui	$t1,%hi(n_syn)
/*    3e578:	8d29f114 */ 	lw	$t1,%lo(n_syn)($t1)
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
/*    3e5c4:	3c0e8006 */ 	lui	$t6,%hi(n_syn)
/*    3e5c8:	8dcef114 */ 	lw	$t6,%lo(n_syn)($t6)
/*    3e5cc:	8dcf0030 */ 	lw	$t7,0x30($t6)
/*    3e5d0:	afaf0004 */ 	sw	$t7,0x4($sp)
/*    3e5d4:	8fb80004 */ 	lw	$t8,0x4($sp)
/*    3e5d8:	3c087004 */ 	lui	$t0,%hi(n_alAuxBusPull)
/*    3e5dc:	2508a100 */ 	addiu	$t0,$t0,%lo(n_alAuxBusPull)
/*    3e5e0:	8f190004 */ 	lw	$t9,0x4($t8)
/*    3e5e4:	1728000c */ 	bne	$t9,$t0,.L0003e618
/*    3e5e8:	00000000 */ 	nop
/*    3e5ec:	3c098006 */ 	lui	$t1,%hi(n_syn)
/*    3e5f0:	8d29f114 */ 	lw	$t1,%lo(n_syn)($t1)
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
