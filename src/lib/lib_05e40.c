#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_05e40.h"
#include "lib/lib_4ad80.h"
#include "lib/lib_4b170.h"
#include "lib/lib_4b480.h"
#include "lib/lib_4b500.h"
#include "lib/lib_4b550.h"
#include "lib/lib_4b5e0.h"
#include "types.h"

GLOBAL_ASM(
glabel func00005e40
/*     5e40:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     5e44:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     5e48:	3c058009 */ 	lui	$a1,%hi(var80090a70)
/*     5e4c:	24a50a70 */ 	addiu	$a1,$a1,%lo(var80090a70)
/*     5e50:	0c012c5c */ 	jal	func0004b170
/*     5e54:	24060040 */ 	addiu	$a2,$zero,0x40
/*     5e58:	3c048009 */ 	lui	$a0,%hi(var80090a80)
/*     5e5c:	8c840a80 */ 	lw	$a0,%lo(var80090a80)($a0)
/*     5e60:	10800005 */ 	beqz	$a0,.L00005e78
/*     5e64:	00000000 */ 	sll	$zero,$zero,0x0
/*     5e68:	0c012d20 */ 	jal	osVirtualToPhysical
/*     5e6c:	00000000 */ 	sll	$zero,$zero,0x0
/*     5e70:	3c018009 */ 	lui	$at,0x8009
/*     5e74:	ac220a80 */ 	sw	$v0,0xa80($at)
.L00005e78:
/*     5e78:	3c048009 */ 	lui	$a0,%hi(var80090a88)
/*     5e7c:	8c840a88 */ 	lw	$a0,%lo(var80090a88)($a0)
/*     5e80:	10800005 */ 	beqz	$a0,.L00005e98
/*     5e84:	00000000 */ 	sll	$zero,$zero,0x0
/*     5e88:	0c012d20 */ 	jal	osVirtualToPhysical
/*     5e8c:	00000000 */ 	sll	$zero,$zero,0x0
/*     5e90:	3c018009 */ 	lui	$at,0x8009
/*     5e94:	ac220a88 */ 	sw	$v0,0xa88($at)
.L00005e98:
/*     5e98:	3c048009 */ 	lui	$a0,%hi(var80090a90)
/*     5e9c:	8c840a90 */ 	lw	$a0,%lo(var80090a90)($a0)
/*     5ea0:	10800005 */ 	beqz	$a0,.L00005eb8
/*     5ea4:	00000000 */ 	sll	$zero,$zero,0x0
/*     5ea8:	0c012d20 */ 	jal	osVirtualToPhysical
/*     5eac:	00000000 */ 	sll	$zero,$zero,0x0
/*     5eb0:	3c018009 */ 	lui	$at,0x8009
/*     5eb4:	ac220a90 */ 	sw	$v0,0xa90($at)
.L00005eb8:
/*     5eb8:	3c048009 */ 	lui	$a0,%hi(var80090a98)
/*     5ebc:	8c840a98 */ 	lw	$a0,%lo(var80090a98)($a0)
/*     5ec0:	10800005 */ 	beqz	$a0,.L00005ed8
/*     5ec4:	00000000 */ 	sll	$zero,$zero,0x0
/*     5ec8:	0c012d20 */ 	jal	osVirtualToPhysical
/*     5ecc:	00000000 */ 	sll	$zero,$zero,0x0
/*     5ed0:	3c018009 */ 	lui	$at,0x8009
/*     5ed4:	ac220a98 */ 	sw	$v0,0xa98($at)
.L00005ed8:
/*     5ed8:	3c048009 */ 	lui	$a0,%hi(var80090a9c)
/*     5edc:	8c840a9c */ 	lw	$a0,%lo(var80090a9c)($a0)
/*     5ee0:	10800005 */ 	beqz	$a0,.L00005ef8
/*     5ee4:	00000000 */ 	sll	$zero,$zero,0x0
/*     5ee8:	0c012d20 */ 	jal	osVirtualToPhysical
/*     5eec:	00000000 */ 	sll	$zero,$zero,0x0
/*     5ef0:	3c018009 */ 	lui	$at,0x8009
/*     5ef4:	ac220a9c */ 	sw	$v0,0xa9c($at)
.L00005ef8:
/*     5ef8:	3c048009 */ 	lui	$a0,%hi(var80090aa0)
/*     5efc:	8c840aa0 */ 	lw	$a0,%lo(var80090aa0)($a0)
/*     5f00:	10800005 */ 	beqz	$a0,.L00005f18
/*     5f04:	00000000 */ 	sll	$zero,$zero,0x0
/*     5f08:	0c012d20 */ 	jal	osVirtualToPhysical
/*     5f0c:	00000000 */ 	sll	$zero,$zero,0x0
/*     5f10:	3c018009 */ 	lui	$at,0x8009
/*     5f14:	ac220aa0 */ 	sw	$v0,0xaa0($at)
.L00005f18:
/*     5f18:	3c048009 */ 	lui	$a0,%hi(var80090aa8)
/*     5f1c:	8c840aa8 */ 	lw	$a0,%lo(var80090aa8)($a0)
/*     5f20:	50800006 */ 	beqzl	$a0,.L00005f3c
/*     5f24:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     5f28:	0c012d20 */ 	jal	osVirtualToPhysical
/*     5f2c:	00000000 */ 	sll	$zero,$zero,0x0
/*     5f30:	3c018009 */ 	lui	$at,0x8009
/*     5f34:	ac220aa8 */ 	sw	$v0,0xaa8($at)
/*     5f38:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L00005f3c:
/*     5f3c:	3c028009 */ 	lui	$v0,%hi(var80090a70)
/*     5f40:	24420a70 */ 	addiu	$v0,$v0,%lo(var80090a70)
/*     5f44:	03e00008 */ 	jr	$ra
/*     5f48:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func00005f4c
/*     5f4c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*     5f50:	afbf0024 */ 	sw	$ra,0x24($sp)
/*     5f54:	afb00014 */ 	sw	$s0,0x14($sp)
/*     5f58:	00808025 */ 	or	$s0,$a0,$zero
/*     5f5c:	afb30020 */ 	sw	$s3,0x20($sp)
/*     5f60:	afb2001c */ 	sw	$s2,0x1c($sp)
/*     5f64:	0c001790 */ 	jal	func00005e40
/*     5f68:	afb10018 */ 	sw	$s1,0x18($sp)
/*     5f6c:	8c4e0004 */ 	lw	$t6,0x4($v0)
/*     5f70:	00409025 */ 	or	$s2,$v0,$zero
/*     5f74:	02402025 */ 	or	$a0,$s2,$zero
/*     5f78:	31cf0001 */ 	andi	$t7,$t6,0x1
/*     5f7c:	11e00013 */ 	beqz	$t7,.L00005fcc
/*     5f80:	00000000 */ 	sll	$zero,$zero,0x0
/*     5f84:	8c580038 */ 	lw	$t8,0x38($v0)
/*     5f88:	8c59003c */ 	lw	$t9,0x3c($v0)
/*     5f8c:	2401fffe */ 	addiu	$at,$zero,-2
/*     5f90:	ac580018 */ 	sw	$t8,0x18($v0)
/*     5f94:	ac59001c */ 	sw	$t9,0x1c($v0)
/*     5f98:	8e080004 */ 	lw	$t0,0x4($s0)
/*     5f9c:	01014824 */ 	and	$t1,$t0,$at
/*     5fa0:	ae090004 */ 	sw	$t1,0x4($s0)
/*     5fa4:	8c4a0004 */ 	lw	$t2,0x4($v0)
/*     5fa8:	314b0004 */ 	andi	$t3,$t2,0x4
/*     5fac:	11600007 */ 	beqz	$t3,.L00005fcc
/*     5fb0:	00000000 */ 	sll	$zero,$zero,0x0
/*     5fb4:	8e0c0038 */ 	lw	$t4,0x38($s0)
/*     5fb8:	3c01a000 */ 	lui	$at,0xa000
/*     5fbc:	258d0bfc */ 	addiu	$t5,$t4,0xbfc
/*     5fc0:	01a17025 */ 	or	$t6,$t5,$at
/*     5fc4:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*     5fc8:	ac4f0010 */ 	sw	$t7,0x10($v0)
.L00005fcc:
/*     5fcc:	0c012b60 */ 	jal	osWritebackDCache
/*     5fd0:	24050040 */ 	addiu	$a1,$zero,0x40
/*     5fd4:	0c012d40 */ 	jal	func0004b500
/*     5fd8:	24042b00 */ 	addiu	$a0,$zero,0x2b00
/*     5fdc:	3c130400 */ 	lui	$s3,0x400
/*     5fe0:	36731000 */ 	ori	$s3,$s3,0x1000
/*     5fe4:	0c012d44 */ 	jal	func0004b510
/*     5fe8:	02602025 */ 	or	$a0,$s3,$zero
/*     5fec:	2411ffff */ 	addiu	$s1,$zero,-1
/*     5ff0:	54510006 */ 	bnel	$v0,$s1,.L0000600c
/*     5ff4:	3c100400 */ 	lui	$s0,0x400
.L00005ff8:
/*     5ff8:	0c012d44 */ 	jal	func0004b510
/*     5ffc:	02602025 */ 	or	$a0,$s3,$zero
/*     6000:	1051fffd */ 	beq	$v0,$s1,.L00005ff8
/*     6004:	00000000 */ 	sll	$zero,$zero,0x0
/*     6008:	3c100400 */ 	lui	$s0,0x400
.L0000600c:
/*     600c:	36100fc0 */ 	ori	$s0,$s0,0xfc0
/*     6010:	02002825 */ 	or	$a1,$s0,$zero
/*     6014:	24040001 */ 	addiu	$a0,$zero,0x1
/*     6018:	02403025 */ 	or	$a2,$s2,$zero
/*     601c:	0c012d54 */ 	jal	func0004b550
/*     6020:	24070040 */ 	addiu	$a3,$zero,0x40
/*     6024:	14510007 */ 	bne	$v0,$s1,.L00006044
/*     6028:	24040001 */ 	addiu	$a0,$zero,0x1
.L0000602c:
/*     602c:	02002825 */ 	or	$a1,$s0,$zero
/*     6030:	02403025 */ 	or	$a2,$s2,$zero
/*     6034:	0c012d54 */ 	jal	func0004b550
/*     6038:	24070040 */ 	addiu	$a3,$zero,0x40
/*     603c:	5051fffb */ 	beql	$v0,$s1,.L0000602c
/*     6040:	24040001 */ 	addiu	$a0,$zero,0x1
.L00006044:
/*     6044:	0c012d78 */ 	jal	func0004b5e0
/*     6048:	00000000 */ 	sll	$zero,$zero,0x0
/*     604c:	50400006 */ 	beqzl	$v0,.L00006068
/*     6050:	24040001 */ 	addiu	$a0,$zero,0x1
.L00006054:
/*     6054:	0c012d78 */ 	jal	func0004b5e0
/*     6058:	00000000 */ 	sll	$zero,$zero,0x0
/*     605c:	1440fffd */ 	bnez	$v0,.L00006054
/*     6060:	00000000 */ 	sll	$zero,$zero,0x0
/*     6064:	24040001 */ 	addiu	$a0,$zero,0x1
.L00006068:
/*     6068:	02602825 */ 	or	$a1,$s3,$zero
/*     606c:	8e460008 */ 	lw	$a2,0x8($s2)
/*     6070:	0c012d54 */ 	jal	func0004b550
/*     6074:	8e47000c */ 	lw	$a3,0xc($s2)
/*     6078:	14510007 */ 	bne	$v0,$s1,.L00006098
/*     607c:	24040001 */ 	addiu	$a0,$zero,0x1
.L00006080:
/*     6080:	02602825 */ 	or	$a1,$s3,$zero
/*     6084:	8e460008 */ 	lw	$a2,0x8($s2)
/*     6088:	0c012d54 */ 	jal	func0004b550
/*     608c:	8e47000c */ 	lw	$a3,0xc($s2)
/*     6090:	5051fffb */ 	beql	$v0,$s1,.L00006080
/*     6094:	24040001 */ 	addiu	$a0,$zero,0x1
.L00006098:
/*     6098:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*     609c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*     60a0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*     60a4:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*     60a8:	8fb30020 */ 	lw	$s3,0x20($sp)
/*     60ac:	03e00008 */ 	jr	$ra
/*     60b0:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func000060b4
/*     60b4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     60b8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     60bc:	0c012d78 */ 	jal	func0004b5e0
/*     60c0:	afa40018 */ 	sw	$a0,0x18($sp)
/*     60c4:	10400005 */ 	beqz	$v0,.L000060dc
/*     60c8:	00000000 */ 	sll	$zero,$zero,0x0
.L000060cc:
/*     60cc:	0c012d78 */ 	jal	func0004b5e0
/*     60d0:	00000000 */ 	sll	$zero,$zero,0x0
/*     60d4:	1440fffd */ 	bnez	$v0,.L000060cc
/*     60d8:	00000000 */ 	sll	$zero,$zero,0x0
.L000060dc:
/*     60dc:	0c012d40 */ 	jal	func0004b500
/*     60e0:	24040125 */ 	addiu	$a0,$zero,0x125
/*     60e4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     60e8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     60ec:	03e00008 */ 	jr	$ra
/*     60f0:	00000000 */ 	sll	$zero,$zero,0x0
/*     60f4:	00000000 */ 	sll	$zero,$zero,0x0
/*     60f8:	00000000 */ 	sll	$zero,$zero,0x0
/*     60fc:	00000000 */ 	sll	$zero,$zero,0x0
);