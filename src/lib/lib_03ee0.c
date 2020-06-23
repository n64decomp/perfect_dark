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
glabel osCreateThread
/*     3ee0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*     3ee4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     3ee8:	afb00018 */ 	sw	$s0,0x18($sp)
/*     3eec:	ac850014 */ 	sw	$a1,0x14($a0)
/*     3ef0:	8fae0034 */ 	lw	$t6,0x34($sp)
/*     3ef4:	0007c7c3 */ 	sra	$t8,$a3,0x1f
/*     3ef8:	ac800000 */ 	sw	$zero,0x0($a0)
/*     3efc:	ac800008 */ 	sw	$zero,0x8($a0)
/*     3f00:	ac86011c */ 	sw	$a2,0x11c($a0)
/*     3f04:	ac980038 */ 	sw	$t8,0x38($a0)
/*     3f08:	ac87003c */ 	sw	$a3,0x3c($a0)
/*     3f0c:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*     3f10:	8faf0030 */ 	lw	$t7,0x30($sp)
/*     3f14:	3c0c7000 */ 	lui	$t4,%hi(__osCleanupThread)
/*     3f18:	258c3ecc */ 	addiu	$t4,$t4,%lo(__osCleanupThread)
/*     3f1c:	000f47c3 */ 	sra	$t0,$t7,0x1f
/*     3f20:	2de10010 */ 	sltiu	$at,$t7,0x10
/*     3f24:	01015023 */ 	subu	$t2,$t0,$at
/*     3f28:	3c0d0400 */ 	lui	$t5,0x400
/*     3f2c:	3c190100 */ 	lui	$t9,0x100
/*     3f30:	000c77c3 */ 	sra	$t6,$t4,0x1f
/*     3f34:	35adff03 */ 	ori	$t5,$t5,0xff03
/*     3f38:	2418003f */ 	addiu	$t8,$zero,0x3f
/*     3f3c:	37390800 */ 	ori	$t9,$t9,0x800
/*     3f40:	24080001 */ 	addiu	$t0,$zero,0x1
/*     3f44:	25ebfff0 */ 	addiu	$t3,$t7,-16
/*     3f48:	00808025 */ 	or	$s0,$a0,$zero
/*     3f4c:	ac8b00f4 */ 	sw	$t3,0xf4($a0)
/*     3f50:	ac8a00f0 */ 	sw	$t2,0xf0($a0)
/*     3f54:	ac8e0100 */ 	sw	$t6,0x100($a0)
/*     3f58:	ac8c0104 */ 	sw	$t4,0x104($a0)
/*     3f5c:	ac8d0118 */ 	sw	$t5,0x118($a0)
/*     3f60:	ac980128 */ 	sw	$t8,0x128($a0)
/*     3f64:	ac99012c */ 	sw	$t9,0x12c($a0)
/*     3f68:	ac800018 */ 	sw	$zero,0x18($a0)
/*     3f6c:	a4880010 */ 	sh	$t0,0x10($a0)
/*     3f70:	0c01256c */ 	jal	__osDisableInt
/*     3f74:	a4800012 */ 	sh	$zero,0x12($a0)
/*     3f78:	3c038006 */ 	lui	$v1,%hi(var8006093c)
/*     3f7c:	2463093c */ 	addiu	$v1,$v1,%lo(var8006093c)
/*     3f80:	8c690000 */ 	lw	$t1,0x0($v1)
/*     3f84:	00402025 */ 	or	$a0,$v0,$zero
/*     3f88:	ae09000c */ 	sw	$t1,0xc($s0)
/*     3f8c:	0c012588 */ 	jal	__osRestoreInt
/*     3f90:	ac700000 */ 	sw	$s0,0x0($v1)
/*     3f94:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     3f98:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     3f9c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*     3fa0:	03e00008 */ 	jr	$ra
/*     3fa4:	00000000 */ 	nop
/*     3fa8:	00000000 */ 	nop
/*     3fac:	00000000 */ 	nop
);