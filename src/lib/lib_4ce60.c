#include <ultra64.h>
#include "libultra_internal.h"
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func0004ce60
/*    4ce60:	27bdfeb0 */ 	addiu	$sp,$sp,-336
/*    4ce64:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    4ce68:	afb50028 */ 	sw	$s5,0x28($sp)
/*    4ce6c:	afb40024 */ 	sw	$s4,0x24($sp)
/*    4ce70:	afb30020 */ 	sw	$s3,0x20($sp)
/*    4ce74:	afb2001c */ 	sw	$s2,0x1c($sp)
/*    4ce78:	afb10018 */ 	sw	$s1,0x18($sp)
/*    4ce7c:	afb00014 */ 	sw	$s0,0x14($sp)
/*    4ce80:	afa50154 */ 	sw	$a1,0x154($sp)
/*    4ce84:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*    4ce88:	0080a025 */ 	or	$s4,$a0,$zero
/*    4ce8c:	00008025 */ 	or	$s0,$zero,$zero
/*    4ce90:	31cf0001 */ 	andi	$t7,$t6,0x1
/*    4ce94:	15e00003 */ 	bnez	$t7,.L0004cea4
/*    4ce98:	00000000 */ 	nop
/*    4ce9c:	1000004d */ 	b	.L0004cfd4
/*    4cea0:	24020005 */ 	addiu	$v0,$zero,0x5
.L0004cea4:
/*    4cea4:	0c013218 */ 	jal	__osCheckId
/*    4cea8:	02802025 */ 	or	$a0,$s4,$zero
/*    4ceac:	50400004 */ 	beqzl	$v0,.L0004cec0
/*    4ceb0:	92980064 */ 	lbu	$t8,0x64($s4)
/*    4ceb4:	10000048 */ 	b	.L0004cfd8
/*    4ceb8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    4cebc:	92980064 */ 	lbu	$t8,0x64($s4)
.L0004cec0:
/*    4cec0:	00009825 */ 	or	$s3,$zero,$zero
/*    4cec4:	24150080 */ 	addiu	$s5,$zero,0x80
/*    4cec8:	1b00003e */ 	blez	$t8,.L0004cfc4
/*    4cecc:	27b20148 */ 	addiu	$s2,$sp,0x148
/*    4ced0:	24110003 */ 	addiu	$s1,$zero,0x3
.L0004ced4:
/*    4ced4:	02802025 */ 	or	$a0,$s4,$zero
/*    4ced8:	27a50048 */ 	addiu	$a1,$sp,0x48
/*    4cedc:	00003025 */ 	or	$a2,$zero,$zero
/*    4cee0:	0c01324d */ 	jal	__osPfsRWInode
/*    4cee4:	326700ff */ 	andi	$a3,$s3,0xff
/*    4cee8:	10400003 */ 	beqz	$v0,.L0004cef8
/*    4ceec:	00000000 */ 	nop
/*    4cef0:	10000039 */ 	b	.L0004cfd8
/*    4cef4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0004cef8:
/*    4cef8:	5a600004 */ 	blezl	$s3,.L0004cf0c
/*    4cefc:	8e850060 */ 	lw	$a1,0x60($s4)
/*    4cf00:	10000002 */ 	b	.L0004cf0c
/*    4cf04:	24050001 */ 	addiu	$a1,$zero,0x1
/*    4cf08:	8e850060 */ 	lw	$a1,0x60($s4)
.L0004cf0c:
/*    4cf0c:	28a10080 */ 	slti	$at,$a1,0x80
/*    4cf10:	10200026 */ 	beqz	$at,.L0004cfac
/*    4cf14:	00a01825 */ 	or	$v1,$a1,$zero
/*    4cf18:	02a53023 */ 	subu	$a2,$s5,$a1
/*    4cf1c:	30d90003 */ 	andi	$t9,$a2,0x3
/*    4cf20:	1320000c */ 	beqz	$t9,.L0004cf54
/*    4cf24:	03252021 */ 	addu	$a0,$t9,$a1
/*    4cf28:	00054040 */ 	sll	$t0,$a1,0x1
/*    4cf2c:	27a90048 */ 	addiu	$t1,$sp,0x48
/*    4cf30:	01091021 */ 	addu	$v0,$t0,$t1
.L0004cf34:
/*    4cf34:	944a0000 */ 	lhu	$t2,0x0($v0)
/*    4cf38:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4cf3c:	162a0002 */ 	bne	$s1,$t2,.L0004cf48
/*    4cf40:	00000000 */ 	nop
/*    4cf44:	26100001 */ 	addiu	$s0,$s0,0x1
.L0004cf48:
/*    4cf48:	1483fffa */ 	bne	$a0,$v1,.L0004cf34
/*    4cf4c:	24420002 */ 	addiu	$v0,$v0,0x2
/*    4cf50:	10750016 */ 	beq	$v1,$s5,.L0004cfac
.L0004cf54:
/*    4cf54:	00035840 */ 	sll	$t3,$v1,0x1
/*    4cf58:	27ac0048 */ 	addiu	$t4,$sp,0x48
/*    4cf5c:	016c1021 */ 	addu	$v0,$t3,$t4
/*    4cf60:	944d0000 */ 	lhu	$t5,0x0($v0)
.L0004cf64:
/*    4cf64:	562d0003 */ 	bnel	$s1,$t5,.L0004cf74
/*    4cf68:	944e0002 */ 	lhu	$t6,0x2($v0)
/*    4cf6c:	26100001 */ 	addiu	$s0,$s0,0x1
/*    4cf70:	944e0002 */ 	lhu	$t6,0x2($v0)
.L0004cf74:
/*    4cf74:	562e0003 */ 	bnel	$s1,$t6,.L0004cf84
/*    4cf78:	944f0004 */ 	lhu	$t7,0x4($v0)
/*    4cf7c:	26100001 */ 	addiu	$s0,$s0,0x1
/*    4cf80:	944f0004 */ 	lhu	$t7,0x4($v0)
.L0004cf84:
/*    4cf84:	562f0003 */ 	bnel	$s1,$t7,.L0004cf94
/*    4cf88:	94580006 */ 	lhu	$t8,0x6($v0)
/*    4cf8c:	26100001 */ 	addiu	$s0,$s0,0x1
/*    4cf90:	94580006 */ 	lhu	$t8,0x6($v0)
.L0004cf94:
/*    4cf94:	24420008 */ 	addiu	$v0,$v0,0x8
/*    4cf98:	16380002 */ 	bne	$s1,$t8,.L0004cfa4
/*    4cf9c:	00000000 */ 	nop
/*    4cfa0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0004cfa4:
/*    4cfa4:	5452ffef */ 	bnel	$v0,$s2,.L0004cf64
/*    4cfa8:	944d0000 */ 	lhu	$t5,0x0($v0)
.L0004cfac:
/*    4cfac:	92880064 */ 	lbu	$t0,0x64($s4)
/*    4cfb0:	26730001 */ 	addiu	$s3,$s3,0x1
/*    4cfb4:	327900ff */ 	andi	$t9,$s3,0xff
/*    4cfb8:	0328082a */ 	slt	$at,$t9,$t0
/*    4cfbc:	1420ffc5 */ 	bnez	$at,.L0004ced4
/*    4cfc0:	03209825 */ 	or	$s3,$t9,$zero
.L0004cfc4:
/*    4cfc4:	8faa0154 */ 	lw	$t2,0x154($sp)
/*    4cfc8:	00104a00 */ 	sll	$t1,$s0,0x8
/*    4cfcc:	00001025 */ 	or	$v0,$zero,$zero
/*    4cfd0:	ad490000 */ 	sw	$t1,0x0($t2)
.L0004cfd4:
/*    4cfd4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0004cfd8:
/*    4cfd8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    4cfdc:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    4cfe0:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*    4cfe4:	8fb30020 */ 	lw	$s3,0x20($sp)
/*    4cfe8:	8fb40024 */ 	lw	$s4,0x24($sp)
/*    4cfec:	8fb50028 */ 	lw	$s5,0x28($sp)
/*    4cff0:	03e00008 */ 	jr	$ra
/*    4cff4:	27bd0150 */ 	addiu	$sp,$sp,0x150
);
