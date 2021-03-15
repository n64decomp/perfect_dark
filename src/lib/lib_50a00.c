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
/*    50b94:	0c012c5c */ 	jal	func0004b170
/*    50b98:	ac580004 */ 	sw	$t8,0x4($v0)
/*    50b9c:	8fa50168 */ 	lw	$a1,0x168($sp)
/*    50ba0:	27a40044 */ 	addiu	$a0,$sp,0x44
/*    50ba4:	24060004 */ 	addiu	$a2,$zero,0x4
/*    50ba8:	0c012c5c */ 	jal	func0004b170
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
/*    50bdc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00050be0
/*    50be0:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*    50be4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    50be8:	afb10018 */ 	sw	$s1,0x18($sp)
/*    50bec:	afb00014 */ 	sw	$s0,0x14($sp)
/*    50bf0:	00a08025 */ 	or	$s0,$a1,$zero
/*    50bf4:	00808825 */ 	or	$s1,$a0,$zero
/*    50bf8:	27a70028 */ 	addiu	$a3,$sp,0x28
/*    50bfc:	8e250008 */ 	lw	$a1,0x8($s1)
/*    50c00:	8c840004 */ 	lw	$a0,0x4($a0)
/*    50c04:	0c012e18 */ 	jal	__osContRamRead
/*    50c08:	24060400 */ 	addiu	$a2,$zero,0x400
/*    50c0c:	24010002 */ 	addiu	$at,$zero,0x2
/*    50c10:	10410005 */ 	beq	$v0,$at,.L00050c28
/*    50c14:	27a70028 */ 	addiu	$a3,$sp,0x28
/*    50c18:	93ae0047 */ 	lbu	$t6,0x47($sp)
/*    50c1c:	24010084 */ 	addiu	$at,$zero,0x84
/*    50c20:	51c1000a */ 	beql	$t6,$at,.L00050c4c
/*    50c24:	8e240004 */ 	lw	$a0,0x4($s1)
.L00050c28:
/*    50c28:	8e240004 */ 	lw	$a0,0x4($s1)
/*    50c2c:	02202825 */ 	or	$a1,$s1,$zero
/*    50c30:	0c001840 */ 	jal	func00006100
/*    50c34:	8e260008 */ 	lw	$a2,0x8($s1)
/*    50c38:	10400003 */ 	beqz	$v0,.L00050c48
/*    50c3c:	27a70028 */ 	addiu	$a3,$sp,0x28
/*    50c40:	10000042 */ 	b	.L00050d4c
/*    50c44:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00050c48:
/*    50c48:	8e240004 */ 	lw	$a0,0x4($s1)
.L00050c4c:
/*    50c4c:	8e250008 */ 	lw	$a1,0x8($s1)
/*    50c50:	0c012e18 */ 	jal	__osContRamRead
/*    50c54:	24060580 */ 	addiu	$a2,$zero,0x580
/*    50c58:	14400036 */ 	bnez	$v0,.L00050d34
/*    50c5c:	00402825 */ 	or	$a1,$v0,$zero
/*    50c60:	8e240004 */ 	lw	$a0,0x4($s1)
/*    50c64:	0c012ea4 */ 	jal	__osPfsGetStatus
/*    50c68:	8e250008 */ 	lw	$a1,0x8($s1)
/*    50c6c:	27a70028 */ 	addiu	$a3,$sp,0x28
/*    50c70:	10400003 */ 	beqz	$v0,.L00050c80
/*    50c74:	00402825 */ 	or	$a1,$v0,$zero
/*    50c78:	10000034 */ 	b	.L00050d4c
/*    50c7c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00050c80:
/*    50c80:	93b80028 */ 	lbu	$t8,0x28($sp)
/*    50c84:	24030004 */ 	addiu	$v1,$zero,0x4
/*    50c88:	24040020 */ 	addiu	$a0,$zero,0x20
/*    50c8c:	a2180000 */ 	sb	$t8,0x0($s0)
/*    50c90:	93b90029 */ 	lbu	$t9,0x29($sp)
/*    50c94:	03194825 */ 	or	$t1,$t8,$t9
/*    50c98:	a2090000 */ 	sb	$t1,0x0($s0)
/*    50c9c:	93aa002a */ 	lbu	$t2,0x2a($sp)
/*    50ca0:	012a6025 */ 	or	$t4,$t1,$t2
/*    50ca4:	a20c0000 */ 	sb	$t4,0x0($s0)
/*    50ca8:	93ad002b */ 	lbu	$t5,0x2b($sp)
/*    50cac:	018d7025 */ 	or	$t6,$t4,$t5
/*    50cb0:	a20e0000 */ 	sb	$t6,0x0($s0)
.L00050cb4:
/*    50cb4:	00e31021 */ 	addu	$v0,$a3,$v1
/*    50cb8:	90580000 */ 	lbu	$t8,0x0($v0)
/*    50cbc:	920f0000 */ 	lbu	$t7,0x0($s0)
/*    50cc0:	24630004 */ 	addiu	$v1,$v1,0x4
/*    50cc4:	01f84025 */ 	or	$t0,$t7,$t8
/*    50cc8:	a2080000 */ 	sb	$t0,0x0($s0)
/*    50ccc:	90490001 */ 	lbu	$t1,0x1($v0)
/*    50cd0:	01095825 */ 	or	$t3,$t0,$t1
/*    50cd4:	a20b0000 */ 	sb	$t3,0x0($s0)
/*    50cd8:	904c0002 */ 	lbu	$t4,0x2($v0)
/*    50cdc:	016c6825 */ 	or	$t5,$t3,$t4
/*    50ce0:	a20d0000 */ 	sb	$t5,0x0($s0)
/*    50ce4:	904f0003 */ 	lbu	$t7,0x3($v0)
/*    50ce8:	31ae00ff */ 	andi	$t6,$t5,0xff
/*    50cec:	01cfc025 */ 	or	$t8,$t6,$t7
/*    50cf0:	1464fff0 */ 	bne	$v1,$a0,.L00050cb4
/*    50cf4:	a2180000 */ 	sb	$t8,0x0($s0)
/*    50cf8:	33090044 */ 	andi	$t1,$t8,0x44
/*    50cfc:	a2090000 */ 	sb	$t1,0x0($s0)
/*    50d00:	93aa0047 */ 	lbu	$t2,0x47($sp)
/*    50d04:	012a5825 */ 	or	$t3,$t1,$t2
/*    50d08:	316200ff */ 	andi	$v0,$t3,0xff
/*    50d0c:	304c0080 */ 	andi	$t4,$v0,0x80
/*    50d10:	15800003 */ 	bnez	$t4,.L00050d20
/*    50d14:	a20b0000 */ 	sb	$t3,0x0($s0)
/*    50d18:	1000000a */ 	b	.L00050d44
/*    50d1c:	2405000c */ 	addiu	$a1,$zero,0xc
.L00050d20:
/*    50d20:	304d0040 */ 	andi	$t5,$v0,0x40
/*    50d24:	51a00008 */ 	beqzl	$t5,.L00050d48
/*    50d28:	00a01025 */ 	or	$v0,$a1,$zero
/*    50d2c:	10000005 */ 	b	.L00050d44
/*    50d30:	2405000d */ 	addiu	$a1,$zero,0xd
.L00050d34:
/*    50d34:	24010002 */ 	addiu	$at,$zero,0x2
/*    50d38:	54410003 */ 	bnel	$v0,$at,.L00050d48
/*    50d3c:	00a01025 */ 	or	$v0,$a1,$zero
/*    50d40:	24050004 */ 	addiu	$a1,$zero,0x4
.L00050d44:
/*    50d44:	00a01025 */ 	or	$v0,$a1,$zero
.L00050d48:
/*    50d48:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00050d4c:
/*    50d4c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    50d50:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    50d54:	03e00008 */ 	jr	$ra
/*    50d58:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*    50d5c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00050d60
/*    50d60:	27bdff70 */ 	addiu	$sp,$sp,-144
/*    50d64:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    50d68:	afa50094 */ 	sw	$a1,0x94($sp)
/*    50d6c:	afa40090 */ 	sw	$a0,0x90($sp)
/*    50d70:	afa60098 */ 	sw	$a2,0x98($sp)
/*    50d74:	0c0142f8 */ 	jal	func00050be0
/*    50d78:	00c02825 */ 	or	$a1,$a2,$zero
/*    50d7c:	2401000d */ 	addiu	$at,$zero,0xd
/*    50d80:	14410005 */ 	bne	$v0,$at,.L00050d98
/*    50d84:	00403825 */ 	or	$a3,$v0,$zero
/*    50d88:	8fa40090 */ 	lw	$a0,0x90($sp)
/*    50d8c:	0c0142f8 */ 	jal	func00050be0
/*    50d90:	8fa50098 */ 	lw	$a1,0x98($sp)
/*    50d94:	00403825 */ 	or	$a3,$v0,$zero
.L00050d98:
/*    50d98:	2401000d */ 	addiu	$at,$zero,0xd
/*    50d9c:	14410003 */ 	bne	$v0,$at,.L00050dac
/*    50da0:	00000000 */ 	nop
/*    50da4:	10000058 */ 	b	.L00050f08
/*    50da8:	24020004 */ 	addiu	$v0,$zero,0x4
.L00050dac:
/*    50dac:	14400055 */ 	bnez	$v0,.L00050f04
/*    50db0:	8fae0098 */ 	lw	$t6,0x98($sp)
/*    50db4:	91cf0000 */ 	lbu	$t7,0x0($t6)
/*    50db8:	8fa40090 */ 	lw	$a0,0x90($sp)
/*    50dbc:	31f80001 */ 	andi	$t8,$t7,0x1
/*    50dc0:	57000008 */ 	bnezl	$t8,.L00050de4
/*    50dc4:	24190060 */ 	addiu	$t9,$zero,0x60
/*    50dc8:	0c0018cc */ 	jal	func00006330
/*    50dcc:	24050001 */ 	addiu	$a1,$zero,0x1
/*    50dd0:	50400004 */ 	beqzl	$v0,.L00050de4
/*    50dd4:	24190060 */ 	addiu	$t9,$zero,0x60
/*    50dd8:	1000004c */ 	b	.L00050f0c
/*    50ddc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    50de0:	24190060 */ 	addiu	$t9,$zero,0x60
.L00050de4:
/*    50de4:	afb90010 */ 	sw	$t9,0x10($sp)
/*    50de8:	8fa40090 */ 	lw	$a0,0x90($sp)
/*    50dec:	00002825 */ 	or	$a1,$zero,$zero
/*    50df0:	24060100 */ 	addiu	$a2,$zero,0x100
/*    50df4:	0c0144ec */ 	jal	func000513b0
/*    50df8:	27a70024 */ 	addiu	$a3,$sp,0x24
/*    50dfc:	10400003 */ 	beqz	$v0,.L00050e0c
/*    50e00:	8fa40090 */ 	lw	$a0,0x90($sp)
/*    50e04:	10000041 */ 	b	.L00050f0c
/*    50e08:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00050e0c:
/*    50e0c:	0c0142f8 */ 	jal	func00050be0
/*    50e10:	8fa50098 */ 	lw	$a1,0x98($sp)
/*    50e14:	2401000d */ 	addiu	$at,$zero,0xd
/*    50e18:	14410002 */ 	bne	$v0,$at,.L00050e24
/*    50e1c:	00403825 */ 	or	$a3,$v0,$zero
/*    50e20:	24070004 */ 	addiu	$a3,$zero,0x4
.L00050e24:
/*    50e24:	10e00003 */ 	beqz	$a3,.L00050e34
/*    50e28:	3c048006 */ 	lui	$a0,%hi(var800611f0)
/*    50e2c:	10000036 */ 	b	.L00050f08
/*    50e30:	00e01025 */ 	or	$v0,$a3,$zero
.L00050e34:
/*    50e34:	248411f0 */ 	addiu	$a0,$a0,%lo(var800611f0)
/*    50e38:	27a50028 */ 	addiu	$a1,$sp,0x28
/*    50e3c:	24060030 */ 	addiu	$a2,$zero,0x30
/*    50e40:	0c013824 */ 	jal	func0004e090
/*    50e44:	afa70088 */ 	sw	$a3,0x88($sp)
/*    50e48:	10400003 */ 	beqz	$v0,.L00050e58
/*    50e4c:	8fa70088 */ 	lw	$a3,0x88($sp)
/*    50e50:	1000002d */ 	b	.L00050f08
/*    50e54:	24020004 */ 	addiu	$v0,$zero,0x4
.L00050e58:
/*    50e58:	93a20058 */ 	lbu	$v0,0x58($sp)
/*    50e5c:	93a80059 */ 	lbu	$t0,0x59($sp)
/*    50e60:	27a3005a */ 	addiu	$v1,$sp,0x5a
/*    50e64:	27a40072 */ 	addiu	$a0,$sp,0x72
/*    50e68:	00481021 */ 	addu	$v0,$v0,$t0
/*    50e6c:	304900ff */ 	andi	$t1,$v0,0xff
/*    50e70:	01201025 */ 	or	$v0,$t1,$zero
.L00050e74:
/*    50e74:	906a0000 */ 	lbu	$t2,0x0($v1)
/*    50e78:	906c0001 */ 	lbu	$t4,0x1($v1)
/*    50e7c:	906e0002 */ 	lbu	$t6,0x2($v1)
/*    50e80:	90780003 */ 	lbu	$t8,0x3($v1)
/*    50e84:	004a5821 */ 	addu	$t3,$v0,$t2
/*    50e88:	016c6821 */ 	addu	$t5,$t3,$t4
/*    50e8c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*    50e90:	01f81021 */ 	addu	$v0,$t7,$t8
/*    50e94:	305900ff */ 	andi	$t9,$v0,0xff
/*    50e98:	24630004 */ 	addiu	$v1,$v1,0x4
/*    50e9c:	1464fff5 */ 	bne	$v1,$a0,.L00050e74
/*    50ea0:	03201025 */ 	or	$v0,$t9,$zero
/*    50ea4:	27280019 */ 	addiu	$t0,$t9,0x19
/*    50ea8:	310900ff */ 	andi	$t1,$t0,0xff
/*    50eac:	11200003 */ 	beqz	$t1,.L00050ebc
/*    50eb0:	27a40024 */ 	addiu	$a0,$sp,0x24
/*    50eb4:	10000014 */ 	b	.L00050f08
/*    50eb8:	24020004 */ 	addiu	$v0,$zero,0x4
.L00050ebc:
/*    50ebc:	8fa50094 */ 	lw	$a1,0x94($sp)
/*    50ec0:	24060050 */ 	addiu	$a2,$zero,0x50
/*    50ec4:	0c012c5c */ 	jal	func0004b170
/*    50ec8:	afa70088 */ 	sw	$a3,0x88($sp)
/*    50ecc:	8faa0094 */ 	lw	$t2,0x94($sp)
/*    50ed0:	3c0b8006 */ 	lui	$t3,%hi(var80061220)
/*    50ed4:	8fa70088 */ 	lw	$a3,0x88($sp)
/*    50ed8:	91420047 */ 	lbu	$v0,0x47($t2)
/*    50edc:	8fac0090 */ 	lw	$t4,0x90($sp)
/*    50ee0:	28410014 */ 	slti	$at,$v0,0x14
/*    50ee4:	10200003 */ 	beqz	$at,.L00050ef4
/*    50ee8:	01625821 */ 	addu	$t3,$t3,$v0
/*    50eec:	916b1220 */ 	lbu	$t3,%lo(var80061220)($t3)
/*    50ef0:	ad8b004c */ 	sw	$t3,0x4c($t4)
.L00050ef4:
/*    50ef4:	8fad0094 */ 	lw	$t5,0x94($sp)
/*    50ef8:	8faf0090 */ 	lw	$t7,0x90($sp)
/*    50efc:	91ae0049 */ 	lbu	$t6,0x49($t5)
/*    50f00:	adee0050 */ 	sw	$t6,0x50($t7)
.L00050f04:
/*    50f04:	00e01025 */ 	or	$v0,$a3,$zero
.L00050f08:
/*    50f08:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L00050f0c:
/*    50f0c:	27bd0090 */ 	addiu	$sp,$sp,0x90
/*    50f10:	03e00008 */ 	jr	$ra
/*    50f14:	00000000 */ 	nop
/*    50f18:	00000000 */ 	nop
/*    50f1c:	00000000 */ 	nop
);