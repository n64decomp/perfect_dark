#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "library/library_30ce0.h"
#include "library/library_3e730.h"
#include "types.h"

GLOBAL_ASM(
glabel func0003ccf0
/*    3ccf0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    3ccf4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    3ccf8:	afa40020 */ 	sw	$a0,0x20($sp)
/*    3ccfc:	afa50024 */ 	sw	$a1,0x24($sp)
/*    3cd00:	afa60028 */ 	sw	$a2,0x28($sp)
/*    3cd04:	8fae0020 */ 	lw	$t6,0x20($sp)
/*    3cd08:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    3cd0c:	11e00023 */ 	beqz	$t7,.L0003cd9c
/*    3cd10:	00000000 */ 	sll	$zero,$zero,0x0
/*    3cd14:	0c00c541 */ 	jal	func00031504
/*    3cd18:	00000000 */ 	sll	$zero,$zero,0x0
/*    3cd1c:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    3cd20:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*    3cd24:	17000003 */ 	bnez	$t8,.L0003cd34
/*    3cd28:	00000000 */ 	sll	$zero,$zero,0x0
/*    3cd2c:	1000001d */ 	beqz	$zero,.L0003cda4
/*    3cd30:	00000000 */ 	sll	$zero,$zero,0x0
.L0003cd34:
/*    3cd34:	8fa90020 */ 	lw	$t1,0x20($sp)
/*    3cd38:	3c198006 */ 	lui	$t9,0x8006
/*    3cd3c:	8f39f114 */ 	lw	$t9,-0xeec($t9)
/*    3cd40:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*    3cd44:	8fad001c */ 	lw	$t5,0x1c($sp)
/*    3cd48:	8f28001c */ 	lw	$t0,0x1c($t9)
/*    3cd4c:	8d4b0088 */ 	lw	$t3,0x88($t2)
/*    3cd50:	010b6021 */ 	addu	$t4,$t0,$t3
/*    3cd54:	adac0004 */ 	sw	$t4,0x4($t5)
/*    3cd58:	8faf001c */ 	lw	$t7,0x1c($sp)
/*    3cd5c:	240e000b */ 	addiu	$t6,$zero,0xb
/*    3cd60:	a5ee0008 */ 	sh	$t6,0x8($t7)
/*    3cd64:	87b80026 */ 	lh	$t8,0x26($sp)
/*    3cd68:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*    3cd6c:	af38000c */ 	sw	$t8,0xc($t9)
/*    3cd70:	0c00c5a6 */ 	jal	func00031698
/*    3cd74:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    3cd78:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*    3cd7c:	ad220010 */ 	sw	$v0,0x10($t1)
/*    3cd80:	8faa001c */ 	lw	$t2,0x1c($sp)
/*    3cd84:	ad400000 */ 	sw	$zero,0x0($t2)
/*    3cd88:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    3cd8c:	24050003 */ 	addiu	$a1,$zero,0x3
/*    3cd90:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*    3cd94:	0c00fc79 */ 	jal	func0003f1e4
/*    3cd98:	8d040008 */ 	lw	$a0,0x8($t0)
.L0003cd9c:
/*    3cd9c:	10000001 */ 	beqz	$zero,.L0003cda4
/*    3cda0:	00000000 */ 	sll	$zero,$zero,0x0
.L0003cda4:
/*    3cda4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    3cda8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    3cdac:	03e00008 */ 	jr	$ra
/*    3cdb0:	00000000 */ 	sll	$zero,$zero,0x0
/*    3cdb4:	00000000 */ 	sll	$zero,$zero,0x0
/*    3cdb8:	00000000 */ 	sll	$zero,$zero,0x0
/*    3cdbc:	00000000 */ 	sll	$zero,$zero,0x0
);