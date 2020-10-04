#include <libultra_internal.h>

GLOBAL_ASM(
glabel osStopTimer
/*    48a30:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    48a34:	afa40030 */ 	sw	$a0,0x30($sp)
/*    48a38:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    48a3c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    48a40:	afb00018 */ 	sw	$s0,0x18($sp)
/*    48a44:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    48a48:	15e00003 */ 	bnez	$t7,.L00048a58
/*    48a4c:	00000000 */ 	nop
/*    48a50:	1000002c */ 	b	.L00048b04
/*    48a54:	2402ffff */ 	addiu	$v0,$zero,-1
.L00048a58:
/*    48a58:	0c01256c */ 	jal	__osDisableInt
/*    48a5c:	00000000 */ 	nop
/*    48a60:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    48a64:	3c088006 */ 	lui	$t0,%hi(var800608a0)
/*    48a68:	8d0808a0 */ 	lw	$t0,%lo(var800608a0)($t0)
/*    48a6c:	8f190000 */ 	lw	$t9,0x0($t8)
/*    48a70:	00408025 */ 	or	$s0,$v0,$zero
/*    48a74:	1328000d */ 	beq	$t9,$t0,.L00048aac
/*    48a78:	afb90028 */ 	sw	$t9,0x28($sp)
/*    48a7c:	27290010 */ 	addiu	$t1,$t9,0x10
/*    48a80:	afa90024 */ 	sw	$t1,0x24($sp)
/*    48a84:	8d2b0004 */ 	lw	$t3,0x4($t1)
/*    48a88:	8f0d0014 */ 	lw	$t5,0x14($t8)
/*    48a8c:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*    48a90:	8f0c0010 */ 	lw	$t4,0x10($t8)
/*    48a94:	016d7821 */ 	addu	$t7,$t3,$t5
/*    48a98:	01ed082b */ 	sltu	$at,$t7,$t5
/*    48a9c:	002a7021 */ 	addu	$t6,$at,$t2
/*    48aa0:	01cc7021 */ 	addu	$t6,$t6,$t4
/*    48aa4:	ad2e0000 */ 	sw	$t6,0x0($t1)
/*    48aa8:	ad2f0004 */ 	sw	$t7,0x4($t1)
.L00048aac:
/*    48aac:	8fa80030 */ 	lw	$t0,0x30($sp)
/*    48ab0:	3c0f8006 */ 	lui	$t7,%hi(var800608a0)
/*    48ab4:	8d190000 */ 	lw	$t9,0x0($t0)
/*    48ab8:	8d180004 */ 	lw	$t8,0x4($t0)
/*    48abc:	af190000 */ 	sw	$t9,0x0($t8)
/*    48ac0:	8faa0030 */ 	lw	$t2,0x30($sp)
/*    48ac4:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*    48ac8:	8d4c0000 */ 	lw	$t4,0x0($t2)
/*    48acc:	ad8b0004 */ 	sw	$t3,0x4($t4)
/*    48ad0:	8fad0030 */ 	lw	$t5,0x30($sp)
/*    48ad4:	ada00000 */ 	sw	$zero,0x0($t5)
/*    48ad8:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    48adc:	adc00004 */ 	sw	$zero,0x4($t6)
/*    48ae0:	8def08a0 */ 	lw	$t7,%lo(var800608a0)($t7)
/*    48ae4:	8de90000 */ 	lw	$t1,0x0($t7)
/*    48ae8:	152f0003 */ 	bne	$t1,$t7,.L00048af8
/*    48aec:	00000000 */ 	nop
/*    48af0:	0c014620 */ 	jal	__osSetCompare
/*    48af4:	00002025 */ 	or	$a0,$zero,$zero
.L00048af8:
/*    48af8:	0c012588 */ 	jal	__osRestoreInt
/*    48afc:	02002025 */ 	or	$a0,$s0,$zero
/*    48b00:	00001025 */ 	or	$v0,$zero,$zero
.L00048b04:
/*    48b04:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    48b08:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    48b0c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    48b10:	03e00008 */ 	jr	$ra
/*    48b14:	00000000 */ 	nop
/*    48b18:	00000000 */ 	nop
/*    48b1c:	00000000 */ 	nop
);
