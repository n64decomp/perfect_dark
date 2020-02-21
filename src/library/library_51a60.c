#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "library/library_491b0.h"
#include "types.h"

GLOBAL_ASM(
glabel func00051a60
/*    51a60:	3c03a460 */ 	lui	$v1,0xa460
/*    51a64:	34630010 */ 	ori	$v1,$v1,0x10
/*    51a68:	8c620000 */ 	lw	$v0,0x0($v1)
/*    51a6c:	00a03825 */ 	or	$a3,$a1,$zero
/*    51a70:	304e0003 */ 	andi	$t6,$v0,0x3
/*    51a74:	51c00006 */ 	beqzl	$t6,.L00051a90
/*    51a78:	90820009 */ 	lbu	$v0,0x9($a0)
/*    51a7c:	8c620000 */ 	lw	$v0,0x0($v1)
.L00051a80:
/*    51a80:	304f0003 */ 	andi	$t7,$v0,0x3
/*    51a84:	55e0fffe */ 	bnezl	$t7,.L00051a80
/*    51a88:	8c620000 */ 	lw	$v0,0x0($v1)
/*    51a8c:	90820009 */ 	lbu	$v0,0x9($a0)
.L00051a90:
/*    51a90:	3c038006 */ 	lui	$v1,0x8006
/*    51a94:	90990004 */ 	lbu	$t9,0x4($a0)
/*    51a98:	0002c080 */ 	sll	$t8,$v0,0x2
/*    51a9c:	00781821 */ 	addu	$v1,$v1,$t8
/*    51aa0:	8c63cf20 */ 	lw	$v1,-0x30e0($v1)
/*    51aa4:	90680004 */ 	lbu	$t0,0x4($v1)
/*    51aa8:	5328003d */ 	beql	$t9,$t0,.L00051ba0
/*    51aac:	8c8a000c */ 	lw	$t2,0xc($a0)
/*    51ab0:	14400019 */ 	bnez	$v0,.L00051b18
/*    51ab4:	00602825 */ 	or	$a1,$v1,$zero
/*    51ab8:	90820005 */ 	lbu	$v0,0x5($a0)
/*    51abc:	90690005 */ 	lbu	$t1,0x5($v1)
/*    51ac0:	3c0aa460 */ 	lui	$t2,0xa460
/*    51ac4:	3c0ca460 */ 	lui	$t4,0xa460
/*    51ac8:	10490002 */ 	beq	$v0,$t1,.L00051ad4
/*    51acc:	3c0ea460 */ 	lui	$t6,0xa460
/*    51ad0:	ad420014 */ 	sw	$v0,0x14($t2)
.L00051ad4:
/*    51ad4:	90820006 */ 	lbu	$v0,0x6($a0)
/*    51ad8:	90ab0006 */ 	lbu	$t3,0x6($a1)
/*    51adc:	3c18a460 */ 	lui	$t8,0xa460
/*    51ae0:	504b0003 */ 	beql	$v0,$t3,.L00051af0
/*    51ae4:	90820007 */ 	lbu	$v0,0x7($a0)
/*    51ae8:	ad82001c */ 	sw	$v0,0x1c($t4)
/*    51aec:	90820007 */ 	lbu	$v0,0x7($a0)
.L00051af0:
/*    51af0:	90ad0007 */ 	lbu	$t5,0x7($a1)
/*    51af4:	504d0003 */ 	beql	$v0,$t5,.L00051b04
/*    51af8:	90820008 */ 	lbu	$v0,0x8($a0)
/*    51afc:	adc20020 */ 	sw	$v0,0x20($t6)
/*    51b00:	90820008 */ 	lbu	$v0,0x8($a0)
.L00051b04:
/*    51b04:	90af0008 */ 	lbu	$t7,0x8($a1)
/*    51b08:	504f001b */ 	beql	$v0,$t7,.L00051b78
/*    51b0c:	908f0004 */ 	lbu	$t7,0x4($a0)
/*    51b10:	10000018 */ 	beqz	$zero,.L00051b74
/*    51b14:	af020018 */ 	sw	$v0,0x18($t8)
.L00051b18:
/*    51b18:	90820005 */ 	lbu	$v0,0x5($a0)
/*    51b1c:	90b90005 */ 	lbu	$t9,0x5($a1)
/*    51b20:	3c08a460 */ 	lui	$t0,0xa460
/*    51b24:	3c0aa460 */ 	lui	$t2,0xa460
/*    51b28:	10590002 */ 	beq	$v0,$t9,.L00051b34
/*    51b2c:	3c0ca460 */ 	lui	$t4,0xa460
/*    51b30:	ad020024 */ 	sw	$v0,0x24($t0)
.L00051b34:
/*    51b34:	90820006 */ 	lbu	$v0,0x6($a0)
/*    51b38:	90a90006 */ 	lbu	$t1,0x6($a1)
/*    51b3c:	3c0ea460 */ 	lui	$t6,0xa460
/*    51b40:	50490003 */ 	beql	$v0,$t1,.L00051b50
/*    51b44:	90820007 */ 	lbu	$v0,0x7($a0)
/*    51b48:	ad42002c */ 	sw	$v0,0x2c($t2)
/*    51b4c:	90820007 */ 	lbu	$v0,0x7($a0)
.L00051b50:
/*    51b50:	90ab0007 */ 	lbu	$t3,0x7($a1)
/*    51b54:	504b0003 */ 	beql	$v0,$t3,.L00051b64
/*    51b58:	90820008 */ 	lbu	$v0,0x8($a0)
/*    51b5c:	ad820030 */ 	sw	$v0,0x30($t4)
/*    51b60:	90820008 */ 	lbu	$v0,0x8($a0)
.L00051b64:
/*    51b64:	90ad0008 */ 	lbu	$t5,0x8($a1)
/*    51b68:	504d0003 */ 	beql	$v0,$t5,.L00051b78
/*    51b6c:	908f0004 */ 	lbu	$t7,0x4($a0)
/*    51b70:	adc20028 */ 	sw	$v0,0x28($t6)
.L00051b74:
/*    51b74:	908f0004 */ 	lbu	$t7,0x4($a0)
.L00051b78:
/*    51b78:	a0af0004 */ 	sb	$t7,0x4($a1)
/*    51b7c:	90980005 */ 	lbu	$t8,0x5($a0)
/*    51b80:	a0b80005 */ 	sb	$t8,0x5($a1)
/*    51b84:	90990006 */ 	lbu	$t9,0x6($a0)
/*    51b88:	a0b90006 */ 	sb	$t9,0x6($a1)
/*    51b8c:	90880007 */ 	lbu	$t0,0x7($a0)
/*    51b90:	a0a80007 */ 	sb	$t0,0x7($a1)
/*    51b94:	90890008 */ 	lbu	$t1,0x8($a0)
/*    51b98:	a0a90008 */ 	sb	$t1,0x8($a1)
/*    51b9c:	8c8a000c */ 	lw	$t2,0xc($a0)
.L00051ba0:
/*    51ba0:	3c01a000 */ 	lui	$at,0xa000
/*    51ba4:	00001025 */ 	or	$v0,$zero,$zero
/*    51ba8:	01475825 */ 	or	$t3,$t2,$a3
/*    51bac:	01616025 */ 	or	$t4,$t3,$at
/*    51bb0:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*    51bb4:	03e00008 */ 	jr	$ra
/*    51bb8:	accd0000 */ 	sw	$t5,0x0($a2)
/*    51bbc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00051bc0
/*    51bc0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    51bc4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    51bc8:	afa40028 */ 	sw	$a0,0x28($sp)
/*    51bcc:	0c01256c */ 	jal	func000495b0
/*    51bd0:	afb00018 */ 	sw	$s0,0x18($sp)
/*    51bd4:	3c0e8006 */ 	lui	$t6,0x8006
/*    51bd8:	8dcecf70 */ 	lw	$t6,-0x3090($t6)
/*    51bdc:	8faf0028 */ 	lw	$t7,0x28($sp)
/*    51be0:	00408025 */ 	or	$s0,$v0,$zero
/*    51be4:	3c018006 */ 	lui	$at,0x8006
/*    51be8:	01cfc025 */ 	or	$t8,$t6,$t7
/*    51bec:	ac38cf70 */ 	sw	$t8,-0x3090($at)
/*    51bf0:	0c012588 */ 	jal	func00049620
/*    51bf4:	02002025 */ 	or	$a0,$s0,$zero
/*    51bf8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    51bfc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    51c00:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    51c04:	03e00008 */ 	jr	$ra
/*    51c08:	00000000 */ 	sll	$zero,$zero,0x0
/*    51c0c:	00000000 */ 	sll	$zero,$zero,0x0
);