#include <libultra_internal.h>

GLOBAL_ASM(
glabel osSendMesg
/*    488e0:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    488e4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    488e8:	afa40038 */ 	sw	$a0,0x38($sp)
/*    488ec:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    488f0:	afa60040 */ 	sw	$a2,0x40($sp)
/*    488f4:	afb20020 */ 	sw	$s2,0x20($sp)
/*    488f8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    488fc:	0c01256c */ 	jal	__osDisableInt
/*    48900:	afb00018 */ 	sw	$s0,0x18($sp)
/*    48904:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    48908:	00408025 */ 	or	$s0,$v0,$zero
/*    4890c:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    48910:	8dd80010 */ 	lw	$t8,0x10($t6)
/*    48914:	01f8082a */ 	slt	$at,$t7,$t8
/*    48918:	14200018 */ 	bnez	$at,.L0004897c
/*    4891c:	00000000 */ 	nop
.L00048920:
/*    48920:	8fb90040 */ 	lw	$t9,0x40($sp)
/*    48924:	24010001 */ 	addiu	$at,$zero,0x1
/*    48928:	1721000a */ 	bne	$t9,$at,.L00048954
/*    4892c:	00000000 */ 	nop
/*    48930:	3c098006 */ 	lui	$t1,%hi(__osRunningThread)
/*    48934:	8d290940 */ 	lw	$t1,%lo(__osRunningThread)($t1)
/*    48938:	24080008 */ 	addiu	$t0,$zero,0x8
/*    4893c:	a5280010 */ 	sh	$t0,0x10($t1)
/*    48940:	8fa40038 */ 	lw	$a0,0x38($sp)
/*    48944:	0c000ee8 */ 	jal	__osEnqueueAndYield
/*    48948:	24840004 */ 	addiu	$a0,$a0,0x4
/*    4894c:	10000005 */ 	b	.L00048964
/*    48950:	00000000 */ 	nop
.L00048954:
/*    48954:	0c012588 */ 	jal	__osRestoreInt
/*    48958:	02002025 */ 	or	$a0,$s0,$zero
/*    4895c:	1000002d */ 	b	.L00048a14
/*    48960:	2402ffff */ 	addiu	$v0,$zero,-1
.L00048964:
/*    48964:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    48968:	8d4b0008 */ 	lw	$t3,0x8($t2)
/*    4896c:	8d4c0010 */ 	lw	$t4,0x10($t2)
/*    48970:	016c082a */ 	slt	$at,$t3,$t4
/*    48974:	1020ffea */ 	beqz	$at,.L00048920
/*    48978:	00000000 */ 	nop
.L0004897c:
/*    4897c:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    48980:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*    48984:	8dae000c */ 	lw	$t6,0xc($t5)
/*    48988:	8daf0008 */ 	lw	$t7,0x8($t5)
/*    4898c:	8db90010 */ 	lw	$t9,0x10($t5)
/*    48990:	8da90014 */ 	lw	$t1,0x14($t5)
/*    48994:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    48998:	0319001a */ 	div	$zero,$t8,$t9
/*    4899c:	00008810 */ 	mfhi	$s1
/*    489a0:	00115080 */ 	sll	$t2,$s1,0x2
/*    489a4:	012a5821 */ 	addu	$t3,$t1,$t2
/*    489a8:	ad680000 */ 	sw	$t0,0x0($t3)
/*    489ac:	8fac0038 */ 	lw	$t4,0x38($sp)
/*    489b0:	17200002 */ 	bnez	$t9,.L000489bc
/*    489b4:	00000000 */ 	nop
/*    489b8:	0007000d */ 	break	0x7
.L000489bc:
/*    489bc:	2401ffff */ 	addiu	$at,$zero,-1
/*    489c0:	17210004 */ 	bne	$t9,$at,.L000489d4
/*    489c4:	3c018000 */ 	lui	$at,0x8000
/*    489c8:	17010002 */ 	bne	$t8,$at,.L000489d4
/*    489cc:	00000000 */ 	nop
/*    489d0:	0006000d */ 	break	0x6
.L000489d4:
/*    489d4:	8d8e0008 */ 	lw	$t6,0x8($t4)
/*    489d8:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*    489dc:	ad8f0008 */ 	sw	$t7,0x8($t4)
/*    489e0:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    489e4:	8f190000 */ 	lw	$t9,0x0($t8)
/*    489e8:	8f2d0000 */ 	lw	$t5,0x0($t9)
/*    489ec:	11a00006 */ 	beqz	$t5,.L00048a08
/*    489f0:	00000000 */ 	nop
/*    489f4:	0c000f40 */ 	jal	__osPopThread
/*    489f8:	03002025 */ 	or	$a0,$t8,$zero
/*    489fc:	00409025 */ 	or	$s2,$v0,$zero
/*    48a00:	0c01207c */ 	jal	osStartThread
/*    48a04:	02402025 */ 	or	$a0,$s2,$zero
.L00048a08:
/*    48a08:	0c012588 */ 	jal	__osRestoreInt
/*    48a0c:	02002025 */ 	or	$a0,$s0,$zero
/*    48a10:	00001025 */ 	or	$v0,$zero,$zero
.L00048a14:
/*    48a14:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    48a18:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    48a1c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    48a20:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    48a24:	03e00008 */ 	jr	$ra
/*    48a28:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    48a2c:	00000000 */ 	nop
);
