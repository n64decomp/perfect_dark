#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "library/library_034f0.h"
#include "library/library_481e0.h"
#include "library/library_491b0.h"
#include "library/library_51880.h"
#include "types.h"

GLOBAL_ASM(
glabel func000488e0
/*    488e0:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    488e4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*    488e8:	afa40038 */ 	sw	$a0,0x38($sp)
/*    488ec:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    488f0:	afa60040 */ 	sw	$a2,0x40($sp)
/*    488f4:	afb20020 */ 	sw	$s2,0x20($sp)
/*    488f8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    488fc:	0c01256c */ 	jal	func000495b0
/*    48900:	afb00018 */ 	sw	$s0,0x18($sp)
/*    48904:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    48908:	00408025 */ 	or	$s0,$v0,$zero
/*    4890c:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    48910:	8dd80010 */ 	lw	$t8,0x10($t6)
/*    48914:	01f8082a */ 	slt	$at,$t7,$t8
/*    48918:	14200018 */ 	bnez	$at,.L0004897c
/*    4891c:	00000000 */ 	sll	$zero,$zero,0x0
.L00048920:
/*    48920:	8fb90040 */ 	lw	$t9,0x40($sp)
/*    48924:	24010001 */ 	addiu	$at,$zero,0x1
/*    48928:	1721000a */ 	bne	$t9,$at,.L00048954
/*    4892c:	00000000 */ 	sll	$zero,$zero,0x0
/*    48930:	3c098006 */ 	lui	$t1,0x8006
/*    48934:	8d290940 */ 	lw	$t1,0x940($t1)
/*    48938:	24080008 */ 	addiu	$t0,$zero,0x8
/*    4893c:	a5280010 */ 	sh	$t0,0x10($t1)
/*    48940:	8fa40038 */ 	lw	$a0,0x38($sp)
/*    48944:	0c000ee8 */ 	jal	func00003ba0
/*    48948:	24840004 */ 	addiu	$a0,$a0,0x4
/*    4894c:	10000005 */ 	beqz	$zero,.L00048964
/*    48950:	00000000 */ 	sll	$zero,$zero,0x0
.L00048954:
/*    48954:	0c012588 */ 	jal	func00049620
/*    48958:	02002025 */ 	or	$a0,$s0,$zero
/*    4895c:	1000002d */ 	beqz	$zero,.L00048a14
/*    48960:	2402ffff */ 	addiu	$v0,$zero,-1
.L00048964:
/*    48964:	8faa0038 */ 	lw	$t2,0x38($sp)
/*    48968:	8d4b0008 */ 	lw	$t3,0x8($t2)
/*    4896c:	8d4c0010 */ 	lw	$t4,0x10($t2)
/*    48970:	016c082a */ 	slt	$at,$t3,$t4
/*    48974:	1020ffea */ 	beqz	$at,.L00048920
/*    48978:	00000000 */ 	sll	$zero,$zero,0x0
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
/*    489b4:	00000000 */ 	sll	$zero,$zero,0x0
/*    489b8:	0007000d */ 	break	0x7
.L000489bc:
/*    489bc:	2401ffff */ 	addiu	$at,$zero,-1
/*    489c0:	17210004 */ 	bne	$t9,$at,.L000489d4
/*    489c4:	3c018000 */ 	lui	$at,0x8000
/*    489c8:	17010002 */ 	bne	$t8,$at,.L000489d4
/*    489cc:	00000000 */ 	sll	$zero,$zero,0x0
/*    489d0:	0006000d */ 	break	0x6
.L000489d4:
/*    489d4:	8d8e0008 */ 	lw	$t6,0x8($t4)
/*    489d8:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*    489dc:	ad8f0008 */ 	sw	$t7,0x8($t4)
/*    489e0:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    489e4:	8f190000 */ 	lw	$t9,0x0($t8)
/*    489e8:	8f2d0000 */ 	lw	$t5,0x0($t9)
/*    489ec:	11a00006 */ 	beqz	$t5,.L00048a08
/*    489f0:	00000000 */ 	sll	$zero,$zero,0x0
/*    489f4:	0c000f40 */ 	jal	func00003d00
/*    489f8:	03002025 */ 	or	$a0,$t8,$zero
/*    489fc:	00409025 */ 	or	$s2,$v0,$zero
/*    48a00:	0c01207c */ 	jal	func000481f0
/*    48a04:	02402025 */ 	or	$a0,$s2,$zero
.L00048a08:
/*    48a08:	0c012588 */ 	jal	func00049620
/*    48a0c:	02002025 */ 	or	$a0,$s0,$zero
/*    48a10:	00001025 */ 	or	$v0,$zero,$zero
.L00048a14:
/*    48a14:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*    48a18:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    48a1c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    48a20:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    48a24:	03e00008 */ 	jr	$ra
/*    48a28:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*    48a2c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00048a30
/*    48a30:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*    48a34:	afa40030 */ 	sw	$a0,0x30($sp)
/*    48a38:	8fae0030 */ 	lw	$t6,0x30($sp)
/*    48a3c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    48a40:	afb00018 */ 	sw	$s0,0x18($sp)
/*    48a44:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    48a48:	15e00003 */ 	bnez	$t7,.L00048a58
/*    48a4c:	00000000 */ 	sll	$zero,$zero,0x0
/*    48a50:	1000002c */ 	beqz	$zero,.L00048b04
/*    48a54:	2402ffff */ 	addiu	$v0,$zero,-1
.L00048a58:
/*    48a58:	0c01256c */ 	jal	func000495b0
/*    48a5c:	00000000 */ 	sll	$zero,$zero,0x0
/*    48a60:	8fb80030 */ 	lw	$t8,0x30($sp)
/*    48a64:	3c088006 */ 	lui	$t0,0x8006
/*    48a68:	8d0808a0 */ 	lw	$t0,0x8a0($t0)
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
/*    48ab0:	3c0f8006 */ 	lui	$t7,0x8006
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
/*    48ae0:	8def08a0 */ 	lw	$t7,0x8a0($t7)
/*    48ae4:	8de90000 */ 	lw	$t1,0x0($t7)
/*    48ae8:	152f0003 */ 	bne	$t1,$t7,.L00048af8
/*    48aec:	00000000 */ 	sll	$zero,$zero,0x0
/*    48af0:	0c014620 */ 	jal	func00051880
/*    48af4:	00002025 */ 	or	$a0,$zero,$zero
.L00048af8:
/*    48af8:	0c012588 */ 	jal	func00049620
/*    48afc:	02002025 */ 	or	$a0,$s0,$zero
/*    48b00:	00001025 */ 	or	$v0,$zero,$zero
.L00048b04:
/*    48b04:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    48b08:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    48b0c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*    48b10:	03e00008 */ 	jr	$ra
/*    48b14:	00000000 */ 	sll	$zero,$zero,0x0
/*    48b18:	00000000 */ 	sll	$zero,$zero,0x0
/*    48b1c:	00000000 */ 	sll	$zero,$zero,0x0
);