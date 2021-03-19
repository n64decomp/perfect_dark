#include <libultra_internal.h>
#include "data.h"

GLOBAL_ASM(
glabel osGetMemSize
/*    4f530:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*    4f534:	3c0e0040 */ 	lui	$t6,0x40
/*    4f538:	afae0008 */ 	sw	$t6,0x8($sp)
.NB0004f53c:
/*    4f53c:	8faf0008 */ 	lw	$t7,0x8($sp)
/*    4f540:	3c01a000 */ 	lui	$at,0xa000
/*    4f544:	3c19a000 */ 	lui	$t9,0xa000
/*    4f548:	01e1c021 */ 	addu	$t8,$t7,$at
/*    4f54c:	afb8000c */ 	sw	$t8,0xc($sp)
/*    4f550:	032fc821 */ 	addu	$t9,$t9,$t7
/*    4f554:	8f390000 */ 	lw	$t9,0x0($t9)
/*    4f558:	3c08a010 */ 	lui	$t0,0xa010
/*    4f55c:	010f4021 */ 	addu	$t0,$t0,$t7
/*    4f560:	afb90004 */ 	sw	$t9,0x4($sp)
/*    4f564:	8d08fffc */ 	lw	$t0,-0x4($t0)
/*    4f568:	3c09a000 */ 	lui	$t1,0xa000
/*    4f56c:	012f4821 */ 	addu	$t1,$t1,$t7
/*    4f570:	afa80000 */ 	sw	$t0,0x0($sp)
/*    4f574:	8d290000 */ 	lw	$t1,0x0($t1)
/*    4f578:	2401ffff */ 	addiu	$at,$zero,-1
/*    4f57c:	3c0c0010 */ 	lui	$t4,0x10
/*    4f580:	01215026 */ 	xor	$t2,$t1,$at
/*    4f584:	3c01a000 */ 	lui	$at,0xa000
/*    4f588:	002f0821 */ 	addu	$at,$at,$t7
/*    4f58c:	ac2a0000 */ 	sw	$t2,0x0($at)
/*    4f590:	8fab000c */ 	lw	$t3,0xc($sp)
/*    4f594:	2401ffff */ 	addiu	$at,$zero,-1
/*    4f598:	018b6021 */ 	addu	$t4,$t4,$t3
/*    4f59c:	8d8cfffc */ 	lw	$t4,-0x4($t4)
/*    4f5a0:	01816826 */ 	xor	$t5,$t4,$at
/*    4f5a4:	3c010010 */ 	lui	$at,0x10
/*    4f5a8:	002b0821 */ 	addu	$at,$at,$t3
/*    4f5ac:	ac2dfffc */ 	sw	$t5,-0x4($at)
/*    4f5b0:	8fae000c */ 	lw	$t6,0xc($sp)
/*    4f5b4:	8fb90004 */ 	lw	$t9,0x4($sp)
/*    4f5b8:	2401ffff */ 	addiu	$at,$zero,-1
/*    4f5bc:	8dd80000 */ 	lw	$t8,0x0($t6)
/*    4f5c0:	03214026 */ 	xor	$t0,$t9,$at
/*    4f5c4:	17080009 */ 	bne	$t8,$t0,.NB0004f5ec
/*    4f5c8:	00000000 */ 	sll	$zero,$zero,0x0
/*    4f5cc:	3c090010 */ 	lui	$t1,0x10
/*    4f5d0:	8faa0000 */ 	lw	$t2,0x0($sp)
/*    4f5d4:	012e4821 */ 	addu	$t1,$t1,$t6
/*    4f5d8:	8d29fffc */ 	lw	$t1,-0x4($t1)
/*    4f5dc:	2401ffff */ 	addiu	$at,$zero,-1
/*    4f5e0:	01417826 */ 	xor	$t7,$t2,$at
/*    4f5e4:	112f0003 */ 	beq	$t1,$t7,.NB0004f5f4
/*    4f5e8:	00000000 */ 	sll	$zero,$zero,0x0
.NB0004f5ec:
/*    4f5ec:	10000013 */ 	beqz	$zero,.NB0004f63c
/*    4f5f0:	8fa20008 */ 	lw	$v0,0x8($sp)
.NB0004f5f4:
/*    4f5f4:	8fac0004 */ 	lw	$t4,0x4($sp)
/*    4f5f8:	8fad000c */ 	lw	$t5,0xc($sp)
/*    4f5fc:	3c010010 */ 	lui	$at,0x10
/*    4f600:	adac0000 */ 	sw	$t4,0x0($t5)
/*    4f604:	8fb9000c */ 	lw	$t9,0xc($sp)
/*    4f608:	8fab0000 */ 	lw	$t3,0x0($sp)
/*    4f60c:	00390821 */ 	addu	$at,$at,$t9
/*    4f610:	ac2bfffc */ 	sw	$t3,-0x4($at)
/*    4f614:	8fb80008 */ 	lw	$t8,0x8($sp)
/*    4f618:	3c010010 */ 	lui	$at,0x10
/*    4f61c:	03014021 */ 	addu	$t0,$t8,$at
/*    4f620:	afa80008 */ 	sw	$t0,0x8($sp)
/*    4f624:	8fae0008 */ 	lw	$t6,0x8($sp)
/*    4f628:	3c010080 */ 	lui	$at,0x80
/*    4f62c:	01c1082b */ 	sltu	$at,$t6,$at
/*    4f630:	1420ffc2 */ 	bnez	$at,.NB0004f53c
/*    4f634:	00000000 */ 	sll	$zero,$zero,0x0
/*    4f638:	8fa20008 */ 	lw	$v0,0x8($sp)
.NB0004f63c:
/*    4f63c:	03e00008 */ 	jr	$ra
/*    4f640:	27bd0010 */ 	addiu	$sp,$sp,0x10
);;
