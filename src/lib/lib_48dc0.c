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
#include "lib/lib_491b0.h"
#include "types.h"

GLOBAL_ASM(
glabel func00048dc0
/*    48dc0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    48dc4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    48dc8:	e7ac0028 */ 	swc1	$f12,0x28($sp)
/*    48dcc:	afb10018 */ 	sw	$s1,0x18($sp)
/*    48dd0:	0c01256c */ 	jal	__osDisableInt
/*    48dd4:	afb00014 */ 	sw	$s0,0x14($sp)
/*    48dd8:	3c0e8006 */ 	lui	$t6,%hi(var80060914)
/*    48ddc:	8dce0914 */ 	lw	$t6,%lo(var80060914)($t6)
/*    48de0:	c7a40028 */ 	lwc1	$f4,0x28($sp)
/*    48de4:	3c0f8006 */ 	lui	$t7,%hi(var80060914)
/*    48de8:	3c088006 */ 	lui	$t0,%hi(var80060914)
/*    48dec:	e5c40018 */ 	swc1	$f4,0x18($t6)
/*    48df0:	8def0914 */ 	lw	$t7,%lo(var80060914)($t7)
/*    48df4:	00408825 */ 	or	$s1,$v0,$zero
/*    48df8:	95f80000 */ 	lhu	$t8,0x0($t7)
/*    48dfc:	37190002 */ 	ori	$t9,$t8,0x2
/*    48e00:	a5f90000 */ 	sh	$t9,0x0($t7)
/*    48e04:	8d080914 */ 	lw	$t0,%lo(var80060914)($t0)
/*    48e08:	8d090008 */ 	lw	$t1,0x8($t0)
/*    48e0c:	c5060018 */ 	lwc1	$f6,0x18($t0)
/*    48e10:	8d300020 */ 	lw	$s0,0x20($t1)
/*    48e14:	320a0fff */ 	andi	$t2,$s0,0xfff
/*    48e18:	01408025 */ 	or	$s0,$t2,$zero
/*    48e1c:	44904000 */ 	mtc1	$s0,$f8
/*    48e20:	06010005 */ 	bgez	$s0,.L00048e38
/*    48e24:	468042a0 */ 	cvt.s.w	$f10,$f8
/*    48e28:	3c014f80 */ 	lui	$at,0x4f80
/*    48e2c:	44818000 */ 	mtc1	$at,$f16
/*    48e30:	00000000 */ 	sll	$zero,$zero,0x0
/*    48e34:	46105280 */ 	add.s	$f10,$f10,$f16
.L00048e38:
/*    48e38:	460a3482 */ 	mul.s	$f18,$f6,$f10
/*    48e3c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*    48e40:	444bf800 */ 	cfc1	$t3,$31
/*    48e44:	44ccf800 */ 	ctc1	$t4,$31
/*    48e48:	00000000 */ 	sll	$zero,$zero,0x0
/*    48e4c:	46009124 */ 	cvt.w.s	$f4,$f18
/*    48e50:	444cf800 */ 	cfc1	$t4,$31
/*    48e54:	00000000 */ 	sll	$zero,$zero,0x0
/*    48e58:	31810004 */ 	andi	$at,$t4,0x4
/*    48e5c:	318c0078 */ 	andi	$t4,$t4,0x78
/*    48e60:	11800013 */ 	beqz	$t4,.L00048eb0
/*    48e64:	3c014f00 */ 	lui	$at,0x4f00
/*    48e68:	44812000 */ 	mtc1	$at,$f4
/*    48e6c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*    48e70:	46049101 */ 	sub.s	$f4,$f18,$f4
/*    48e74:	44ccf800 */ 	ctc1	$t4,$31
/*    48e78:	00000000 */ 	sll	$zero,$zero,0x0
/*    48e7c:	46002124 */ 	cvt.w.s	$f4,$f4
/*    48e80:	444cf800 */ 	cfc1	$t4,$31
/*    48e84:	00000000 */ 	sll	$zero,$zero,0x0
/*    48e88:	31810004 */ 	andi	$at,$t4,0x4
/*    48e8c:	318c0078 */ 	andi	$t4,$t4,0x78
/*    48e90:	15800005 */ 	bnez	$t4,.L00048ea8
/*    48e94:	00000000 */ 	sll	$zero,$zero,0x0
/*    48e98:	440c2000 */ 	mfc1	$t4,$f4
/*    48e9c:	3c018000 */ 	lui	$at,0x8000
/*    48ea0:	10000007 */ 	beqz	$zero,.L00048ec0
/*    48ea4:	01816025 */ 	or	$t4,$t4,$at
.L00048ea8:
/*    48ea8:	10000005 */ 	beqz	$zero,.L00048ec0
/*    48eac:	240cffff */ 	addiu	$t4,$zero,-1
.L00048eb0:
/*    48eb0:	440c2000 */ 	mfc1	$t4,$f4
/*    48eb4:	00000000 */ 	sll	$zero,$zero,0x0
/*    48eb8:	0580fffb */ 	bltz	$t4,.L00048ea8
/*    48ebc:	00000000 */ 	sll	$zero,$zero,0x0
.L00048ec0:
/*    48ec0:	44cbf800 */ 	ctc1	$t3,$31
/*    48ec4:	318d0fff */ 	andi	$t5,$t4,0xfff
/*    48ec8:	ad0d0020 */ 	sw	$t5,0x20($t0)
/*    48ecc:	0c012588 */ 	jal	__osRestoreInt
/*    48ed0:	02202025 */ 	or	$a0,$s1,$zero
/*    48ed4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    48ed8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    48edc:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    48ee0:	03e00008 */ 	jr	$ra
/*    48ee4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    48ee8:	00000000 */ 	sll	$zero,$zero,0x0
/*    48eec:	00000000 */ 	sll	$zero,$zero,0x0
);