#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_06100.h"
#include "lib/lib_06330.h"
#include "lib/lib_4b170.h"
#include "lib/lib_4c090.h"
#include "lib/lib_4d6f0.h"
#include "lib/lib_50a00.h"
#include "lib/lib_513b0.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel func00050a00
/*    50a00:	27bdfea0 */ 	addiu	$sp,$sp,-352
/*    50a04:	afbf002c */ 	sw	$ra,0x2c($sp)
/*    50a08:	afb40028 */ 	sw	$s4,0x28($sp)
/*    50a0c:	afb30024 */ 	sw	$s3,0x24($sp)
/*    50a10:	afb20020 */ 	sw	$s2,0x20($sp)
/*    50a14:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    50a18:	afb00018 */ 	sw	$s0,0x18($sp)
/*    50a1c:	afa60168 */ 	sw	$a2,0x168($sp)
/*    50a20:	8c8e0050 */ 	lw	$t6,0x50($a0)
/*    50a24:	00a08025 */ 	or	$s0,$a1,$zero
/*    50a28:	00809825 */ 	or	$s3,$a0,$zero
/*    50a2c:	00ae082a */ 	slt	$at,$a1,$t6
/*    50a30:	10200003 */ 	beqz	$at,.L00050a40
/*    50a34:	00000000 */ 	nop
/*    50a38:	04a30004 */ 	bgezl	$a1,.L00050a4c
/*    50a3c:	8e6f0000 */ 	lw	$t7,0x0($s3)
.L00050a40:
/*    50a40:	1000005e */ 	b	.L00050bbc
/*    50a44:	24020005 */ 	addiu	$v0,$zero,0x5
/*    50a48:	8e6f0000 */ 	lw	$t7,0x0($s3)
.L00050a4c:
/*    50a4c:	31f80001 */ 	andi	$t8,$t7,0x1
/*    50a50:	17000003 */ 	bnez	$t8,.L00050a60
/*    50a54:	00000000 */ 	nop
/*    50a58:	10000058 */ 	b	.L00050bbc
/*    50a5c:	24020005 */ 	addiu	$v0,$zero,0x5
.L00050a60:
/*    50a60:	0c013218 */ 	jal	func0004c860
/*    50a64:	02602025 */ 	or	$a0,$s3,$zero
/*    50a68:	50400004 */ 	beqzl	$v0,.L00050a7c
/*    50a6c:	92790065 */ 	lbu	$t9,0x65($s3)
/*    50a70:	10000053 */ 	b	.L00050bc0
/*    50a74:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    50a78:	92790065 */ 	lbu	$t9,0x65($s3)
.L00050a7c:
/*    50a7c:	02602025 */ 	or	$a0,$s3,$zero
/*    50a80:	53200008 */ 	beqzl	$t9,.L00050aa4
/*    50a84:	8e68005c */ 	lw	$t0,0x5c($s3)
/*    50a88:	0c013378 */ 	jal	__osPfsSelectBank
/*    50a8c:	00002825 */ 	or	$a1,$zero,$zero
/*    50a90:	50400004 */ 	beqzl	$v0,.L00050aa4
/*    50a94:	8e68005c */ 	lw	$t0,0x5c($s3)
/*    50a98:	10000049 */ 	b	.L00050bc0
/*    50a9c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*    50aa0:	8e68005c */ 	lw	$t0,0x5c($s3)
.L00050aa4:
/*    50aa4:	8e640004 */ 	lw	$a0,0x4($s3)
/*    50aa8:	8e650008 */ 	lw	$a1,0x8($s3)
/*    50aac:	01103021 */ 	addu	$a2,$t0,$s0
/*    50ab0:	30c9ffff */ 	andi	$t1,$a2,0xffff
/*    50ab4:	01203025 */ 	or	$a2,$t1,$zero
/*    50ab8:	0c012e18 */ 	jal	__osContRamRead
/*    50abc:	27a70038 */ 	addiu	$a3,$sp,0x38
/*    50ac0:	10400003 */ 	beqz	$v0,.L00050ad0
/*    50ac4:	97aa003c */ 	lhu	$t2,0x3c($sp)
/*    50ac8:	1000003d */ 	b	.L00050bc0
/*    50acc:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L00050ad0:
/*    50ad0:	11400003 */ 	beqz	$t2,.L00050ae0
/*    50ad4:	8fab0038 */ 	lw	$t3,0x38($sp)
/*    50ad8:	15600003 */ 	bnez	$t3,.L00050ae8
/*    50adc:	27b40034 */ 	addiu	$s4,$sp,0x34
.L00050ae0:
/*    50ae0:	10000036 */ 	b	.L00050bbc
/*    50ae4:	24020005 */ 	addiu	$v0,$zero,0x5
.L00050ae8:
/*    50ae8:	27ac003e */ 	addiu	$t4,$sp,0x3e
/*    50aec:	95810000 */ 	lhu	$at,0x0($t4)
/*    50af0:	00009025 */ 	or	$s2,$zero,$zero
/*    50af4:	241000ff */ 	addiu	$s0,$zero,0xff
/*    50af8:	27b10058 */ 	addiu	$s1,$sp,0x58
/*    50afc:	a6810000 */ 	sh	$at,0x0($s4)
.L00050b00:
/*    50b00:	97af0034 */ 	lhu	$t7,0x34($sp)
/*    50b04:	8e780060 */ 	lw	$t8,0x60($s3)
/*    50b08:	93b90034 */ 	lbu	$t9,0x34($sp)
/*    50b0c:	02602025 */ 	or	$a0,$s3,$zero
/*    50b10:	01f8082a */ 	slt	$at,$t7,$t8
/*    50b14:	14200011 */ 	bnez	$at,.L00050b5c
/*    50b18:	02202825 */ 	or	$a1,$s1,$zero
/*    50b1c:	12190008 */ 	beq	$s0,$t9,.L00050b40
/*    50b20:	00003025 */ 	or	$a2,$zero,$zero
/*    50b24:	03208025 */ 	or	$s0,$t9,$zero
/*    50b28:	0c01324d */ 	jal	func0004c934
/*    50b2c:	332700ff */ 	andi	$a3,$t9,0xff
/*    50b30:	50400004 */ 	beqzl	$v0,.L00050b44
/*    50b34:	93a80035 */ 	lbu	$t0,0x35($sp)
/*    50b38:	10000021 */ 	b	.L00050bc0
/*    50b3c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L00050b40:
/*    50b40:	93a80035 */ 	lbu	$t0,0x35($sp)
.L00050b44:
/*    50b44:	26520001 */ 	addiu	$s2,$s2,0x1
/*    50b48:	00084840 */ 	sll	$t1,$t0,0x1
/*    50b4c:	02295021 */ 	addu	$t2,$s1,$t1
/*    50b50:	95410000 */ 	lhu	$at,0x0($t2)
/*    50b54:	1000ffea */ 	b	.L00050b00
/*    50b58:	a6810000 */ 	sh	$at,0x0($s4)
.L00050b5c:
/*    50b5c:	97ac0034 */ 	lhu	$t4,0x34($sp)
/*    50b60:	24010001 */ 	addiu	$at,$zero,0x1
/*    50b64:	8fa20168 */ 	lw	$v0,0x168($sp)
/*    50b68:	11810003 */ 	beq	$t4,$at,.L00050b78
/*    50b6c:	00127200 */ 	sll	$t6,$s2,0x8
/*    50b70:	10000012 */ 	b	.L00050bbc
/*    50b74:	24020003 */ 	addiu	$v0,$zero,0x3
.L00050b78:
/*    50b78:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*    50b7c:	97af003c */ 	lhu	$t7,0x3c($sp)
/*    50b80:	27a40048 */ 	addiu	$a0,$sp,0x48
/*    50b84:	2445000e */ 	addiu	$a1,$v0,0xe
/*    50b88:	a44f0008 */ 	sh	$t7,0x8($v0)
/*    50b8c:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    50b90:	24060010 */ 	addiu	$a2,$zero,0x10
/*    50b94:	0c012c5c */ 	jal	bcopy
/*    50b98:	ac580004 */ 	sw	$t8,0x4($v0)
/*    50b9c:	8fa50168 */ 	lw	$a1,0x168($sp)
/*    50ba0:	27a40044 */ 	addiu	$a0,$sp,0x44
/*    50ba4:	24060004 */ 	addiu	$a2,$zero,0x4
/*    50ba8:	0c012c5c */ 	jal	bcopy
/*    50bac:	24a5000a */ 	addiu	$a1,$a1,0xa
/*    50bb0:	8e640004 */ 	lw	$a0,0x4($s3)
/*    50bb4:	0c012ea4 */ 	jal	__osPfsGetStatus
/*    50bb8:	8e650008 */ 	lw	$a1,0x8($s3)
.L00050bbc:
/*    50bbc:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L00050bc0:
/*    50bc0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    50bc4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    50bc8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    50bcc:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    50bd0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    50bd4:	03e00008 */ 	jr	$ra
/*    50bd8:	27bd0160 */ 	addiu	$sp,$sp,0x160
);
