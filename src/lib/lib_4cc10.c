#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_4c090.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004cc10
/*    4cc10:	27bdff88 */ 	addiu	$sp,$sp,-120
/*    4cc14:	afbf003c */ 	sw	$ra,0x3c($sp)
/*    4cc18:	afbe0038 */ 	sw	$s8,0x38($sp)
/*    4cc1c:	afb70034 */ 	sw	$s7,0x34($sp)
/*    4cc20:	afb60030 */ 	sw	$s6,0x30($sp)
/*    4cc24:	afb5002c */ 	sw	$s5,0x2c($sp)
/*    4cc28:	afb40028 */ 	sw	$s4,0x28($sp)
/*    4cc2c:	afb30024 */ 	sw	$s3,0x24($sp)
/*    4cc30:	afb20020 */ 	sw	$s2,0x20($sp)
/*    4cc34:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    4cc38:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4cc3c:	afa5007c */ 	sw	$a1,0x7c($sp)
/*    4cc40:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*    4cc44:	00809025 */ 	or	$s2,$a0,$zero
/*    4cc48:	00e0a825 */ 	or	$s5,$a3,$zero
/*    4cc4c:	31cf0001 */ 	andi	$t7,$t6,0x1
/*    4cc50:	30b7ffff */ 	andi	$s7,$a1,0xffff
/*    4cc54:	15e00003 */ 	bnez	$t7,.L0004cc64
/*    4cc58:	00c0f025 */ 	or	$s8,$a2,$zero
/*    4cc5c:	10000051 */ 	b	.L0004cda4
/*    4cc60:	24020005 */ 	addiu	$v0,$zero,0x5
.L0004cc64:
/*    4cc64:	0c013218 */ 	jal	func0004c860
/*    4cc68:	02402025 */ 	or	$a0,$s2,$zero
/*    4cc6c:	50400004 */ 	beqzl	$v0,.L0004cc80
/*    4cc70:	8e580050 */ 	lw	$t8,0x50($s2)
/*    4cc74:	1000004c */ 	b	.L0004cda8
/*    4cc78:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*    4cc7c:	8e580050 */ 	lw	$t8,0x50($s2)
.L0004cc80:
/*    4cc80:	00009825 */ 	or	$s3,$zero,$zero
/*    4cc84:	27b60050 */ 	addiu	$s6,$sp,0x50
/*    4cc88:	1b000042 */ 	blez	$t8,.L0004cd94
/*    4cc8c:	8fb40088 */ 	lw	$s4,0x88($sp)
/*    4cc90:	27b10060 */ 	addiu	$s1,$sp,0x60
/*    4cc94:	27b00054 */ 	addiu	$s0,$sp,0x54
/*    4cc98:	8e59005c */ 	lw	$t9,0x5c($s2)
.L0004cc9c:
/*    4cc9c:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4cca0:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4cca4:	03333021 */ 	addu	$a2,$t9,$s3
/*    4cca8:	30c8ffff */ 	andi	$t0,$a2,0xffff
/*    4ccac:	01003025 */ 	or	$a2,$t0,$zero
/*    4ccb0:	0c012e18 */ 	jal	__osContRamRead
/*    4ccb4:	02c03825 */ 	or	$a3,$s6,$zero
/*    4ccb8:	50400004 */ 	beqzl	$v0,.L0004cccc
/*    4ccbc:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4ccc0:	10000039 */ 	b	.L0004cda8
/*    4ccc4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*    4ccc8:	8e440004 */ 	lw	$a0,0x4($s2)
.L0004cccc:
/*    4cccc:	0c012ea4 */ 	jal	__osPfsGetStatus
/*    4ccd0:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4ccd4:	10400003 */ 	beqz	$v0,.L0004cce4
/*    4ccd8:	00403025 */ 	or	$a2,$v0,$zero
/*    4ccdc:	10000032 */ 	b	.L0004cda8
/*    4cce0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004cce4:
/*    4cce4:	97a90054 */ 	lhu	$t1,0x54($sp)
/*    4cce8:	8faa0050 */ 	lw	$t2,0x50($sp)
/*    4ccec:	56e90025 */ 	bnel	$s7,$t1,.L0004cd84
/*    4ccf0:	8e580050 */ 	lw	$t8,0x50($s2)
/*    4ccf4:	555e0023 */ 	bnel	$t2,$s8,.L0004cd84
/*    4ccf8:	8e580050 */ 	lw	$t8,0x50($s2)
/*    4ccfc:	12a0000c */ 	beqz	$s5,.L0004cd30
/*    4cd00:	00002025 */ 	or	$a0,$zero,$zero
/*    4cd04:	27a20050 */ 	addiu	$v0,$sp,0x50
/*    4cd08:	02a01825 */ 	or	$v1,$s5,$zero
.L0004cd0c:
/*    4cd0c:	904b0010 */ 	lbu	$t3,0x10($v0)
/*    4cd10:	906c0000 */ 	lbu	$t4,0x0($v1)
/*    4cd14:	24420001 */ 	addiu	$v0,$v0,0x1
/*    4cd18:	116c0003 */ 	beq	$t3,$t4,.L0004cd28
/*    4cd1c:	00000000 */ 	nop
/*    4cd20:	10000003 */ 	b	.L0004cd30
/*    4cd24:	24040001 */ 	addiu	$a0,$zero,0x1
.L0004cd28:
/*    4cd28:	1451fff8 */ 	bne	$v0,$s1,.L0004cd0c
/*    4cd2c:	24630001 */ 	addiu	$v1,$v1,0x1
.L0004cd30:
/*    4cd30:	1280000d */ 	beqz	$s4,.L0004cd68
/*    4cd34:	00000000 */ 	nop
/*    4cd38:	1480000b */ 	bnez	$a0,.L0004cd68
/*    4cd3c:	27a20050 */ 	addiu	$v0,$sp,0x50
/*    4cd40:	02801825 */ 	or	$v1,$s4,$zero
.L0004cd44:
/*    4cd44:	904d000c */ 	lbu	$t5,0xc($v0)
/*    4cd48:	906e0000 */ 	lbu	$t6,0x0($v1)
/*    4cd4c:	24420001 */ 	addiu	$v0,$v0,0x1
/*    4cd50:	11ae0003 */ 	beq	$t5,$t6,.L0004cd60
/*    4cd54:	00000000 */ 	nop
/*    4cd58:	10000003 */ 	b	.L0004cd68
/*    4cd5c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0004cd60:
/*    4cd60:	1450fff8 */ 	bne	$v0,$s0,.L0004cd44
/*    4cd64:	24630001 */ 	addiu	$v1,$v1,0x1
.L0004cd68:
/*    4cd68:	54800006 */ 	bnezl	$a0,.L0004cd84
/*    4cd6c:	8e580050 */ 	lw	$t8,0x50($s2)
/*    4cd70:	8faf008c */ 	lw	$t7,0x8c($sp)
/*    4cd74:	00c01025 */ 	or	$v0,$a2,$zero
/*    4cd78:	1000000a */ 	b	.L0004cda4
/*    4cd7c:	adf30000 */ 	sw	$s3,0x0($t7)
/*    4cd80:	8e580050 */ 	lw	$t8,0x50($s2)
.L0004cd84:
/*    4cd84:	26730001 */ 	addiu	$s3,$s3,0x1
/*    4cd88:	0278082a */ 	slt	$at,$s3,$t8
/*    4cd8c:	5420ffc3 */ 	bnezl	$at,.L0004cc9c
/*    4cd90:	8e59005c */ 	lw	$t9,0x5c($s2)
.L0004cd94:
/*    4cd94:	8fa8008c */ 	lw	$t0,0x8c($sp)
/*    4cd98:	2419ffff */ 	addiu	$t9,$zero,-1
/*    4cd9c:	24020005 */ 	addiu	$v0,$zero,0x5
/*    4cda0:	ad190000 */ 	sw	$t9,0x0($t0)
.L0004cda4:
/*    4cda4:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004cda8:
/*    4cda8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    4cdac:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    4cdb0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    4cdb4:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    4cdb8:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    4cdbc:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*    4cdc0:	8fb60030 */ 	lw	$s6,0x30($sp)
/*    4cdc4:	8fb70034 */ 	lw	$s7,0x34($sp)
/*    4cdc8:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*    4cdcc:	03e00008 */ 	jr	$ra
/*    4cdd0:	27bd0078 */ 	addiu	$sp,$sp,0x78
/*    4cdd4:	00000000 */ 	nop
/*    4cdd8:	00000000 */ 	nop
/*    4cddc:	00000000 */ 	nop
);