#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/pad.h"
#include "gvars/gvars.h"
#include "lib/lib_121e0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f012d50
/*  f012d50:	27bdfee0 */ 	addiu	$sp,$sp,-288
/*  f012d54:	3c03800a */ 	lui	$v1,%hi(g_StageSetup)
/*  f012d58:	8c63d030 */ 	lw	$v1,%lo(g_StageSetup)($v1)
/*  f012d5c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f012d60:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f012d64:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f012d68:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f012d6c:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f012d70:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f012d74:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f012d78:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f012d7c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f012d80:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f012d84:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f012d88:	00001025 */ 	or	$v0,$zero,$zero
/*  f012d8c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f012d90:	05c00007 */ 	bltz	$t6,.L0f012db0
/*  f012d94:	0060b025 */ 	or	$s6,$v1,$zero
/*  f012d98:	8ecf0010 */ 	lw	$t7,0x10($s6)
.L0f012d9c:
/*  f012d9c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f012da0:	26d60010 */ 	addiu	$s6,$s6,0x10
/*  f012da4:	05e3fffd */ 	bgezl	$t7,.L0f012d9c
/*  f012da8:	8ecf0010 */ 	lw	$t7,0x10($s6)
/*  f012dac:	0060b025 */ 	or	$s6,$v1,$zero
.L0f012db0:
/*  f012db0:	00022040 */ 	sll	$a0,$v0,0x1
/*  f012db4:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f012db8:	3498000f */ 	ori	$t8,$a0,0xf
/*  f012dbc:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f012dc0:	0c0048f2 */ 	jal	malloc
/*  f012dc4:	afa20118 */ 	sw	$v0,0x118($sp)
/*  f012dc8:	8fa80118 */ 	lw	$t0,0x118($sp)
/*  f012dcc:	3c15800a */ 	lui	$s5,%hi(g_Vars)
/*  f012dd0:	26b59fc0 */ 	addiu	$s5,$s5,%lo(g_Vars)
/*  f012dd4:	aea20060 */ 	sw	$v0,0x60($s5)
/*  f012dd8:	0000a025 */ 	or	$s4,$zero,$zero
/*  f012ddc:	1900003c */ 	blez	$t0,.L0f012ed0
/*  f012de0:	0000f025 */ 	or	$s8,$zero,$zero
/*  f012de4:	27b7005c */ 	addiu	$s7,$sp,0x5c
/*  f012de8:	001e4900 */ 	sll	$t1,$s8,0x4
.L0f012dec:
/*  f012dec:	01369821 */ 	addu	$s3,$t1,$s6
/*  f012df0:	8e640000 */ 	lw	$a0,0x0($s3)
/*  f012df4:	240500c0 */ 	addiu	$a1,$zero,0xc0
/*  f012df8:	27a600b0 */ 	addiu	$a2,$sp,0xb0
/*  f012dfc:	0fc456ac */ 	jal	padUnpack
/*  f012e00:	00009025 */ 	or	$s2,$zero,$zero
/*  f012e04:	1a80001c */ 	blez	$s4,.L0f012e78
/*  f012e08:	00008825 */ 	or	$s1,$zero,$zero
.L0f012e0c:
/*  f012e0c:	8eaa0060 */ 	lw	$t2,0x60($s5)
/*  f012e10:	240500c0 */ 	addiu	$a1,$zero,0xc0
/*  f012e14:	02e03025 */ 	or	$a2,$s7,$zero
/*  f012e18:	01515821 */ 	addu	$t3,$t2,$s1
/*  f012e1c:	856c0000 */ 	lh	$t4,0x0($t3)
/*  f012e20:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f012e24:	01b68021 */ 	addu	$s0,$t5,$s6
/*  f012e28:	0fc456ac */ 	jal	padUnpack
/*  f012e2c:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f012e30:	8fa200f8 */ 	lw	$v0,0xf8($sp)
/*  f012e34:	8fa300a4 */ 	lw	$v1,0xa4($sp)
/*  f012e38:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f012e3c:	0043082a */ 	slt	$at,$v0,$v1
/*  f012e40:	1420000d */ 	bnez	$at,.L0f012e78
/*  f012e44:	31cf2000 */ 	andi	$t7,$t6,0x2000
/*  f012e48:	54430009 */ 	bnel	$v0,$v1,.L0f012e70
/*  f012e4c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f012e50:	55e0000a */ 	bnezl	$t7,.L0f012e7c
/*  f012e54:	2682ffff */ 	addiu	$v0,$s4,-1
/*  f012e58:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f012e5c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f012e60:	0319082a */ 	slt	$at,$t8,$t9
/*  f012e64:	54200005 */ 	bnezl	$at,.L0f012e7c
/*  f012e68:	2682ffff */ 	addiu	$v0,$s4,-1
/*  f012e6c:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f012e70:
/*  f012e70:	1654ffe6 */ 	bne	$s2,$s4,.L0f012e0c
/*  f012e74:	26310002 */ 	addiu	$s1,$s1,0x2
.L0f012e78:
/*  f012e78:	2682ffff */ 	addiu	$v0,$s4,-1
.L0f012e7c:
/*  f012e7c:	0052082a */ 	slt	$at,$v0,$s2
/*  f012e80:	1420000a */ 	bnez	$at,.L0f012eac
/*  f012e84:	00128840 */ 	sll	$s1,$s2,0x1
/*  f012e88:	00021840 */ 	sll	$v1,$v0,0x1
/*  f012e8c:	2642ffff */ 	addiu	$v0,$s2,-1
/*  f012e90:	00022040 */ 	sll	$a0,$v0,0x1
.L0f012e94:
/*  f012e94:	8ea80060 */ 	lw	$t0,0x60($s5)
/*  f012e98:	01031021 */ 	addu	$v0,$t0,$v1
/*  f012e9c:	84490000 */ 	lh	$t1,0x0($v0)
/*  f012ea0:	2463fffe */ 	addiu	$v1,$v1,-2
/*  f012ea4:	1464fffb */ 	bne	$v1,$a0,.L0f012e94
/*  f012ea8:	a4490002 */ 	sh	$t1,0x2($v0)
.L0f012eac:
/*  f012eac:	8eaa0060 */ 	lw	$t2,0x60($s5)
/*  f012eb0:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f012eb4:	01515821 */ 	addu	$t3,$t2,$s1
/*  f012eb8:	a57e0000 */ 	sh	$s8,0x0($t3)
/*  f012ebc:	8fac0118 */ 	lw	$t4,0x118($sp)
/*  f012ec0:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f012ec4:	57ccffc9 */ 	bnel	$s8,$t4,.L0f012dec
/*  f012ec8:	001e4900 */ 	sll	$t1,$s8,0x4
/*  f012ecc:	0000f025 */ 	or	$s8,$zero,$zero
.L0f012ed0:
/*  f012ed0:	8ead02bc */ 	lw	$t5,0x2bc($s5)
/*  f012ed4:	3c12800a */ 	lui	$s2,%hi(g_RoomPtrs)
/*  f012ed8:	26524928 */ 	addiu	$s2,$s2,%lo(g_RoomPtrs)
/*  f012edc:	19a0000e */ 	blez	$t5,.L0f012f18
/*  f012ee0:	00001025 */ 	or	$v0,$zero,$zero
/*  f012ee4:	8e4e0000 */ 	lw	$t6,0x0($s2)
.L0f012ee8:
/*  f012ee8:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f012eec:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f012ef0:	a1e00009 */ 	sb	$zero,0x9($t7)
/*  f012ef4:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f012ef8:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f012efc:	a720000c */ 	sh	$zero,0xc($t9)
/*  f012f00:	8ea802bc */ 	lw	$t0,0x2bc($s5)
/*  f012f04:	2442008c */ 	addiu	$v0,$v0,0x8c
/*  f012f08:	03c8082a */ 	slt	$at,$s8,$t0
/*  f012f0c:	5420fff6 */ 	bnezl	$at,.L0f012ee8
/*  f012f10:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f012f14:	0000f025 */ 	or	$s8,$zero,$zero
.L0f012f18:
/*  f012f18:	8fa90118 */ 	lw	$t1,0x118($sp)
/*  f012f1c:	3c12800a */ 	lui	$s2,%hi(g_RoomPtrs)
/*  f012f20:	26524928 */ 	addiu	$s2,$s2,%lo(g_RoomPtrs)
/*  f012f24:	1920002a */ 	blez	$t1,.L0f012fd0
/*  f012f28:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f012f2c:	00008825 */ 	or	$s1,$zero,$zero
/*  f012f30:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f012f34:	2413008c */ 	addiu	$s3,$zero,0x8c
/*  f012f38:	8eaa0060 */ 	lw	$t2,0x60($s5)
.L0f012f3c:
/*  f012f3c:	3c0e800a */ 	lui	$t6,%hi(g_StageSetup)
/*  f012f40:	8dced030 */ 	lw	$t6,%lo(g_StageSetup)($t6)
/*  f012f44:	01515821 */ 	addu	$t3,$t2,$s1
/*  f012f48:	856c0000 */ 	lh	$t4,0x0($t3)
/*  f012f4c:	240500c0 */ 	addiu	$a1,$zero,0xc0
/*  f012f50:	27a600b0 */ 	addiu	$a2,$sp,0xb0
/*  f012f54:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f012f58:	01ae1021 */ 	addu	$v0,$t5,$t6
/*  f012f5c:	0fc456ac */ 	jal	padUnpack
/*  f012f60:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f012f64:	8faf00f8 */ 	lw	$t7,0xf8($sp)
/*  f012f68:	51f00008 */ 	beql	$t7,$s0,.L0f012f8c
/*  f012f6c:	8fa900fc */ 	lw	$t1,0xfc($sp)
/*  f012f70:	01f30019 */ 	multu	$t7,$s3
/*  f012f74:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f012f78:	01e08025 */ 	or	$s0,$t7,$zero
/*  f012f7c:	0000c812 */ 	mflo	$t9
/*  f012f80:	03194021 */ 	addu	$t0,$t8,$t9
/*  f012f84:	a51e000c */ 	sh	$s8,0xc($t0)
/*  f012f88:	8fa900fc */ 	lw	$t1,0xfc($sp)
.L0f012f8c:
/*  f012f8c:	312a2000 */ 	andi	$t2,$t1,0x2000
/*  f012f90:	5540000b */ 	bnezl	$t2,.L0f012fc0
/*  f012f94:	8faf0118 */ 	lw	$t7,0x118($sp)
/*  f012f98:	52140009 */ 	beql	$s0,$s4,.L0f012fc0
/*  f012f9c:	8faf0118 */ 	lw	$t7,0x118($sp)
/*  f012fa0:	02130019 */ 	multu	$s0,$s3
/*  f012fa4:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f012fa8:	00006012 */ 	mflo	$t4
/*  f012fac:	016c1021 */ 	addu	$v0,$t3,$t4
/*  f012fb0:	904d0009 */ 	lbu	$t5,0x9($v0)
/*  f012fb4:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f012fb8:	a04e0009 */ 	sb	$t6,0x9($v0)
/*  f012fbc:	8faf0118 */ 	lw	$t7,0x118($sp)
.L0f012fc0:
/*  f012fc0:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f012fc4:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f012fc8:	57cfffdc */ 	bnel	$s8,$t7,.L0f012f3c
/*  f012fcc:	8eaa0060 */ 	lw	$t2,0x60($s5)
.L0f012fd0:
/*  f012fd0:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f012fd4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f012fd8:	aeb80330 */ 	sw	$t8,0x330($s5)
/*  f012fdc:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f012fe0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f012fe4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f012fe8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f012fec:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f012ff0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f012ff4:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f012ff8:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f012ffc:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f013000:	03e00008 */ 	jr	$ra
/*  f013004:	27bd0120 */ 	addiu	$sp,$sp,0x120
/*  f013008:	00000000 */ 	sll	$zero,$zero,0x0
/*  f01300c:	00000000 */ 	sll	$zero,$zero,0x0
);
