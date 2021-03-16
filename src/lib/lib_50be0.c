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
);
