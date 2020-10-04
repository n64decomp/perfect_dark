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
#include "types.h"

GLOBAL_ASM(
glabel func00048f50
/*    48f50:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    48f54:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    48f58:	0c01256c */ 	jal	__osDisableInt
/*    48f5c:	afa40018 */ 	sw	$a0,0x18($sp)
/*    48f60:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    48f64:	00402825 */ 	or	$a1,$v0,$zero
/*    48f68:	3c038006 */ 	lui	$v1,%hi(var80060914)
/*    48f6c:	308e0001 */ 	andi	$t6,$a0,0x1
/*    48f70:	11c00006 */ 	beqz	$t6,.L00048f8c
/*    48f74:	30990002 */ 	andi	$t9,$a0,0x2
/*    48f78:	24630914 */ 	addiu	$v1,$v1,%lo(var80060914)
/*    48f7c:	8c620000 */ 	lw	$v0,0x0($v1)
/*    48f80:	8c4f000c */ 	lw	$t7,0xc($v0)
/*    48f84:	35f80008 */ 	ori	$t8,$t7,0x8
/*    48f88:	ac58000c */ 	sw	$t8,0xc($v0)
.L00048f8c:
/*    48f8c:	3c038006 */ 	lui	$v1,%hi(var80060914)
/*    48f90:	13200006 */ 	beqz	$t9,.L00048fac
/*    48f94:	24630914 */ 	addiu	$v1,$v1,%lo(var80060914)
/*    48f98:	8c620000 */ 	lw	$v0,0x0($v1)
/*    48f9c:	2401fff7 */ 	addiu	$at,$zero,-9
/*    48fa0:	8c48000c */ 	lw	$t0,0xc($v0)
/*    48fa4:	01014824 */ 	and	$t1,$t0,$at
/*    48fa8:	ac49000c */ 	sw	$t1,0xc($v0)
.L00048fac:
/*    48fac:	308a0004 */ 	andi	$t2,$a0,0x4
/*    48fb0:	11400005 */ 	beqz	$t2,.L00048fc8
/*    48fb4:	308d0008 */ 	andi	$t5,$a0,0x8
/*    48fb8:	8c620000 */ 	lw	$v0,0x0($v1)
/*    48fbc:	8c4b000c */ 	lw	$t3,0xc($v0)
/*    48fc0:	356c0004 */ 	ori	$t4,$t3,0x4
/*    48fc4:	ac4c000c */ 	sw	$t4,0xc($v0)
.L00048fc8:
/*    48fc8:	11a00006 */ 	beqz	$t5,.L00048fe4
/*    48fcc:	30980010 */ 	andi	$t8,$a0,0x10
/*    48fd0:	8c620000 */ 	lw	$v0,0x0($v1)
/*    48fd4:	2401fffb */ 	addiu	$at,$zero,-5
/*    48fd8:	8c4e000c */ 	lw	$t6,0xc($v0)
/*    48fdc:	01c17824 */ 	and	$t7,$t6,$at
/*    48fe0:	ac4f000c */ 	sw	$t7,0xc($v0)
.L00048fe4:
/*    48fe4:	13000005 */ 	beqz	$t8,.L00048ffc
/*    48fe8:	30890020 */ 	andi	$t1,$a0,0x20
/*    48fec:	8c620000 */ 	lw	$v0,0x0($v1)
/*    48ff0:	8c59000c */ 	lw	$t9,0xc($v0)
/*    48ff4:	37280010 */ 	ori	$t0,$t9,0x10
/*    48ff8:	ac48000c */ 	sw	$t0,0xc($v0)
.L00048ffc:
/*    48ffc:	11200006 */ 	beqz	$t1,.L00049018
/*    49000:	308c0040 */ 	andi	$t4,$a0,0x40
/*    49004:	8c620000 */ 	lw	$v0,0x0($v1)
/*    49008:	2401ffef */ 	addiu	$at,$zero,-17
/*    4900c:	8c4a000c */ 	lw	$t2,0xc($v0)
/*    49010:	01415824 */ 	and	$t3,$t2,$at
/*    49014:	ac4b000c */ 	sw	$t3,0xc($v0)
.L00049018:
/*    49018:	1180000b */ 	beqz	$t4,.L00049048
/*    4901c:	30990080 */ 	andi	$t9,$a0,0x80
/*    49020:	8c620000 */ 	lw	$v0,0x0($v1)
/*    49024:	3c010001 */ 	lui	$at,0x1
/*    49028:	8c4d000c */ 	lw	$t5,0xc($v0)
/*    4902c:	01a17025 */ 	or	$t6,$t5,$at
/*    49030:	ac4e000c */ 	sw	$t6,0xc($v0)
/*    49034:	8c620000 */ 	lw	$v0,0x0($v1)
/*    49038:	2401fcff */ 	addiu	$at,$zero,-769
/*    4903c:	8c4f000c */ 	lw	$t7,0xc($v0)
/*    49040:	01e1c024 */ 	and	$t8,$t7,$at
/*    49044:	ac58000c */ 	sw	$t8,0xc($v0)
.L00049048:
/*    49048:	5320000f */ 	beqzl	$t9,.L00049088
/*    4904c:	8c620000 */ 	lw	$v0,0x0($v1)
/*    49050:	8c620000 */ 	lw	$v0,0x0($v1)
/*    49054:	3c01fffe */ 	lui	$at,0xfffe
/*    49058:	3421ffff */ 	ori	$at,$at,0xffff
/*    4905c:	8c48000c */ 	lw	$t0,0xc($v0)
/*    49060:	01014824 */ 	and	$t1,$t0,$at
/*    49064:	ac49000c */ 	sw	$t1,0xc($v0)
/*    49068:	8c620000 */ 	lw	$v0,0x0($v1)
/*    4906c:	8c4b0008 */ 	lw	$t3,0x8($v0)
/*    49070:	8c4a000c */ 	lw	$t2,0xc($v0)
/*    49074:	8d6c0004 */ 	lw	$t4,0x4($t3)
/*    49078:	318d0300 */ 	andi	$t5,$t4,0x300
/*    4907c:	014d7025 */ 	or	$t6,$t2,$t5
/*    49080:	ac4e000c */ 	sw	$t6,0xc($v0)
/*    49084:	8c620000 */ 	lw	$v0,0x0($v1)
.L00049088:
/*    49088:	00a02025 */ 	or	$a0,$a1,$zero
/*    4908c:	944f0000 */ 	lhu	$t7,0x0($v0)
/*    49090:	35f80008 */ 	ori	$t8,$t7,0x8
/*    49094:	0c012588 */ 	jal	__osRestoreInt
/*    49098:	a4580000 */ 	sh	$t8,0x0($v0)
/*    4909c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    490a0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    490a4:	03e00008 */ 	jr	$ra
/*    490a8:	00000000 */ 	nop
/*    490ac:	00000000 */ 	nop
);