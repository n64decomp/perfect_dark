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
#include "lib/lib_034f0.h"
#include "lib/lib_481e0.h"
#include "lib/lib_491b0.h"
#include "types.h"

GLOBAL_ASM(
glabel func00051ec0
/*    51ec0:	3c0ea450 */ 	lui	$t6,0xa450
/*    51ec4:	8dc4000c */ 	lw	$a0,0xc($t6)
/*    51ec8:	3c018000 */ 	lui	$at,0x8000
/*    51ecc:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    51ed0:	00817824 */ 	and	$t7,$a0,$at
/*    51ed4:	11e00003 */ 	beqz	$t7,.L00051ee4
/*    51ed8:	00000000 */ 	nop
/*    51edc:	10000002 */ 	b	.L00051ee8
/*    51ee0:	24020001 */ 	addiu	$v0,$zero,0x1
.L00051ee4:
/*    51ee4:	00001025 */ 	or	$v0,$zero,$zero
.L00051ee8:
/*    51ee8:	03e00008 */ 	jr	$ra
/*    51eec:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel osJamMesg
/*    51ef0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    51ef4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    51ef8:	afa40028 */ 	sw	$a0,0x28($sp)
/*    51efc:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    51f00:	afa60030 */ 	sw	$a2,0x30($sp)
/*    51f04:	afb10018 */ 	sw	$s1,0x18($sp)
/*    51f08:	0c01256c */ 	jal	__osDisableInt
/*    51f0c:	afb00014 */ 	sw	$s0,0x14($sp)
/*    51f10:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    51f14:	00408025 */ 	or	$s0,$v0,$zero
/*    51f18:	8dcf0008 */ 	lw	$t7,0x8($t6)
/*    51f1c:	8dd80010 */ 	lw	$t8,0x10($t6)
/*    51f20:	01f8082a */ 	slt	$at,$t7,$t8
/*    51f24:	14200018 */ 	bnez	$at,.L00051f88
/*    51f28:	00000000 */ 	nop
.L00051f2c:
/*    51f2c:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    51f30:	24010001 */ 	addiu	$at,$zero,0x1
/*    51f34:	1721000a */ 	bne	$t9,$at,.L00051f60
/*    51f38:	00000000 */ 	nop
/*    51f3c:	3c098006 */ 	lui	$t1,%hi(__osRunningThread)
/*    51f40:	8d290940 */ 	lw	$t1,%lo(__osRunningThread)($t1)
/*    51f44:	24080008 */ 	addiu	$t0,$zero,0x8
/*    51f48:	a5280010 */ 	sh	$t0,0x10($t1)
/*    51f4c:	8fa40028 */ 	lw	$a0,0x28($sp)
/*    51f50:	0c000ee8 */ 	jal	__osEnqueueAndYield
/*    51f54:	24840004 */ 	addiu	$a0,$a0,0x4
/*    51f58:	10000005 */ 	b	.L00051f70
/*    51f5c:	00000000 */ 	nop
.L00051f60:
/*    51f60:	0c012588 */ 	jal	__osRestoreInt
/*    51f64:	02002025 */ 	or	$a0,$s0,$zero
/*    51f68:	10000030 */ 	b	.L0005202c
/*    51f6c:	2402ffff */ 	addiu	$v0,$zero,-1
.L00051f70:
/*    51f70:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    51f74:	8d4b0008 */ 	lw	$t3,0x8($t2)
/*    51f78:	8d4c0010 */ 	lw	$t4,0x10($t2)
/*    51f7c:	016c082a */ 	slt	$at,$t3,$t4
/*    51f80:	1020ffea */ 	beqz	$at,.L00051f2c
/*    51f84:	00000000 */ 	nop
.L00051f88:
/*    51f88:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    51f8c:	8dae000c */ 	lw	$t6,0xc($t5)
/*    51f90:	8daf0010 */ 	lw	$t7,0x10($t5)
/*    51f94:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    51f98:	2719ffff */ 	addiu	$t9,$t8,-1
/*    51f9c:	032f001a */ 	div	$zero,$t9,$t7
/*    51fa0:	00004010 */ 	mfhi	$t0
/*    51fa4:	ada8000c */ 	sw	$t0,0xc($t5)
/*    51fa8:	8faa0028 */ 	lw	$t2,0x28($sp)
/*    51fac:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    51fb0:	15e00002 */ 	bnez	$t7,.L00051fbc
/*    51fb4:	00000000 */ 	nop
/*    51fb8:	0007000d */ 	break	0x7
.L00051fbc:
/*    51fbc:	2401ffff */ 	addiu	$at,$zero,-1
/*    51fc0:	15e10004 */ 	bne	$t7,$at,.L00051fd4
/*    51fc4:	3c018000 */ 	lui	$at,0x8000
/*    51fc8:	17210002 */ 	bne	$t9,$at,.L00051fd4
/*    51fcc:	00000000 */ 	nop
/*    51fd0:	0006000d */ 	break	0x6
.L00051fd4:
/*    51fd4:	8d4c000c */ 	lw	$t4,0xc($t2)
/*    51fd8:	8d4b0014 */ 	lw	$t3,0x14($t2)
/*    51fdc:	000c7080 */ 	sll	$t6,$t4,0x2
/*    51fe0:	016ec021 */ 	addu	$t8,$t3,$t6
/*    51fe4:	af090000 */ 	sw	$t1,0x0($t8)
/*    51fe8:	8fb90028 */ 	lw	$t9,0x28($sp)
/*    51fec:	8f2f0008 */ 	lw	$t7,0x8($t9)
/*    51ff0:	25e80001 */ 	addiu	$t0,$t7,0x1
/*    51ff4:	af280008 */ 	sw	$t0,0x8($t9)
/*    51ff8:	8fad0028 */ 	lw	$t5,0x28($sp)
/*    51ffc:	8daa0000 */ 	lw	$t2,0x0($t5)
/*    52000:	8d4c0000 */ 	lw	$t4,0x0($t2)
/*    52004:	11800006 */ 	beqz	$t4,.L00052020
/*    52008:	00000000 */ 	nop
/*    5200c:	0c000f40 */ 	jal	__osPopThread
/*    52010:	01a02025 */ 	or	$a0,$t5,$zero
/*    52014:	00408825 */ 	or	$s1,$v0,$zero
/*    52018:	0c01207c */ 	jal	osStartThread
/*    5201c:	02202025 */ 	or	$a0,$s1,$zero
.L00052020:
/*    52020:	0c012588 */ 	jal	__osRestoreInt
/*    52024:	02002025 */ 	or	$a0,$s0,$zero
/*    52028:	00001025 */ 	or	$v0,$zero,$zero
.L0005202c:
/*    5202c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    52030:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    52034:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    52038:	03e00008 */ 	jr	$ra
/*    5203c:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel osPiGetCmdQueue
/*    52040:	3c0e8006 */ 	lui	$t6,%hi(var8005cf00)
/*    52044:	8dcecf00 */ 	lw	$t6,%lo(var8005cf00)($t6)
/*    52048:	15c00003 */ 	bnez	$t6,.L00052058
/*    5204c:	00000000 */ 	nop
/*    52050:	03e00008 */ 	jr	$ra
/*    52054:	00001025 */ 	or	$v0,$zero,$zero
.L00052058:
/*    52058:	3c028006 */ 	lui	$v0,%hi(var8005cf08)
/*    5205c:	8c42cf08 */ 	lw	$v0,%lo(var8005cf08)($v0)
/*    52060:	03e00008 */ 	jr	$ra
/*    52064:	00000000 */ 	nop
/*    52068:	00000000 */ 	nop
/*    5206c:	00000000 */ 	nop
);