#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "game/game_014f10.h"
#include "game/game_01e250.h"
#include "game/game_0601b0.h"
#include "game/game_066310.h"
#include "gvars/gvars.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f014f10
/*  f014f10:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f014f14:	3c038006 */ 	lui	$v1,0x8006
/*  f014f18:	8c63298c */ 	lw	$v1,0x298c($v1)
/*  f014f1c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f014f20:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f014f24:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f014f28:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f014f2c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f014f30:	18600024 */ 	blez	$v1,.L0f014fc4
/*  f014f34:	00009025 */ 	or	$s2,$zero,$zero
/*  f014f38:	3c118006 */ 	lui	$s1,%hi(g_ChrsA)
/*  f014f3c:	26312988 */ 	addiu	$s1,$s1,%lo(g_ChrsA)
/*  f014f40:	00008025 */ 	or	$s0,$zero,$zero
/*  f014f44:	24130003 */ 	addiu	$s3,$zero,0x3
.L0f014f48:
/*  f014f48:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f014f4c:	01d01021 */ 	addu	$v0,$t6,$s0
/*  f014f50:	844f0000 */ 	lh	$t7,0x0($v0)
/*  f014f54:	05e20018 */ 	bltzl	$t7,.L0f014fb8
/*  f014f58:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f014f5c:	8c44001c */ 	lw	$a0,0x1c($v0)
/*  f014f60:	50800015 */ 	beqzl	$a0,.L0f014fb8
/*  f014f64:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f014f68:	90980000 */ 	lbu	$t8,0x0($a0)
/*  f014f6c:	56780012 */ 	bnel	$s3,$t8,.L0f014fb8
/*  f014f70:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f014f74:	0fc08351 */ 	jal	func0f020d44
/*  f014f78:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f014f7c:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f014f80:	03304021 */ 	addu	$t0,$t9,$s0
/*  f014f84:	0fc18171 */ 	jal	func0f0605c4
/*  f014f88:	8d04001c */ 	lw	$a0,0x1c($t0)
/*  f014f8c:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f014f90:	01305021 */ 	addu	$t2,$t1,$s0
/*  f014f94:	0fc180c0 */ 	jal	func0f060300
/*  f014f98:	8d44001c */ 	lw	$a0,0x1c($t2)
/*  f014f9c:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f014fa0:	01706021 */ 	addu	$t4,$t3,$s0
/*  f014fa4:	0fc1810e */ 	jal	propFree
/*  f014fa8:	8d84001c */ 	lw	$a0,0x1c($t4)
/*  f014fac:	3c038006 */ 	lui	$v1,0x8006
/*  f014fb0:	8c63298c */ 	lw	$v1,0x298c($v1)
/*  f014fb4:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f014fb8:
/*  f014fb8:	0243082a */ 	slt	$at,$s2,$v1
/*  f014fbc:	1420ffe2 */ 	bnez	$at,.L0f014f48
/*  f014fc0:	26100368 */ 	addiu	$s0,$s0,0x368
.L0f014fc4:
/*  f014fc4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f014fc8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f014fcc:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f014fd0:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f014fd4:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f014fd8:	03e00008 */ 	jr	$ra
/*  f014fdc:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

void func0f014fe0(void)
{
	alarmDeactivate();
	func0f0904e0();
}
