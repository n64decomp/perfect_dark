#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "library/library.h"

GLOBAL_ASM(
glabel func0f000000
/* f000000:	3c0e8008 */ 	lui	$t6,0x8008
/*  f000004:	8dce4120 */ 	lw	$t6,0x4120($t6)
/*  f000008:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f00000c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f000010:	11c00019 */ 	beqz	$t6,.L0f000078
/*  f000014:	24042e80 */ 	addiu	$a0,$zero,0x2e80
/*  f000018:	0c0048f2 */ 	jal	func000123c8
/*  f00001c:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f000020:	3c01800b */ 	lui	$at,0x800b
/*  f000024:	ac22abb4 */ 	sw	$v0,-0x544c($at)
/*  f000028:	24040100 */ 	addiu	$a0,$zero,0x100
/*  f00002c:	0c0048f2 */ 	jal	func000123c8
/*  f000030:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f000034:	3c04800b */ 	lui	$a0,%hi(var800aabb8)
/*  f000038:	2484abb8 */ 	addiu	$a0,$a0,%lo(var800aabb8)
/*  f00003c:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f000040:	00001825 */ 	or	$v1,$zero,$zero
/*  f000044:	240500f8 */ 	addiu	$a1,$zero,0xf8
.L0f000048:
/*  f000048:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f00004c:	01e31021 */ 	addu	$v0,$t7,$v1
/*  f000050:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f000054:	3319ff3f */ 	andi	$t9,$t8,0xff3f
/*  f000058:	a0590000 */ 	sb	$t9,0x0($v0)
/*  f00005c:	8c880000 */ 	lw	$t0,0x0($a0)
/*  f000060:	01031021 */ 	addu	$v0,$t0,$v1
/*  f000064:	944a0000 */ 	lhu	$t2,0x0($v0)
/*  f000068:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f00006c:	354b3fff */ 	ori	$t3,$t2,0x3fff
/*  f000070:	1465fff5 */ 	bne	$v1,$a1,.L0f000048
/*  f000074:	a44b0000 */ 	sh	$t3,0x0($v0)
.L0f000078:
/*  f000078:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f00007c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f000080:	03e00008 */ 	jr	$ra
/*  f000084:	00000000 */ 	sll	$zero,$zero,0x0
/*  f000088:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00008c:	00000000 */ 	sll	$zero,$zero,0x0
);