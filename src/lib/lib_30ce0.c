#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_2faf0.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_39fe0.h"
#include "lib/lib_3a100.h"
#include "lib/lib_3c430.h"
#include "data.h"
#include "types.h"

const u32 var70054730[] = {0x49742400};
const u32 var70054734[] = {0x00000000};
const u32 var70054738[] = {0x00000000};
const u32 var7005473c[] = {0x00000000};

GLOBAL_ASM(
glabel func00030ce0
/*    30ce0:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*    30ce4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    30ce8:	afa40040 */ 	sw	$a0,0x40($sp)
/*    30cec:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    30cf0:	8dcf0014 */ 	lw	$t7,0x14($t6)
/*    30cf4:	afaf002c */ 	sw	$t7,0x2c($sp)
/*    30cf8:	3c188006 */ 	lui	$t8,%hi(var8005f114)
/*    30cfc:	8f18f114 */ 	lw	$t8,%lo(var8005f114)($t8)
/*    30d00:	af000000 */ 	sw	$zero,0x0($t8)
/*    30d04:	8fb90040 */ 	lw	$t9,0x40($sp)
/*    30d08:	3c098006 */ 	lui	$t1,%hi(var8005f114)
/*    30d0c:	8d29f114 */ 	lw	$t1,%lo(var8005f114)($t1)
/*    30d10:	8f280004 */ 	lw	$t0,0x4($t9)
/*    30d14:	ad280038 */ 	sw	$t0,0x38($t1)
/*    30d18:	3c0a8006 */ 	lui	$t2,%hi(var8005f114)
/*    30d1c:	8d4af114 */ 	lw	$t2,%lo(var8005f114)($t2)
/*    30d20:	ad400020 */ 	sw	$zero,0x20($t2)
/*    30d24:	3c0b8006 */ 	lui	$t3,%hi(var8005f114)
/*    30d28:	8d6bf114 */ 	lw	$t3,%lo(var8005f114)($t3)
/*    30d2c:	ad60001c */ 	sw	$zero,0x1c($t3)
/*    30d30:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    30d34:	3c0e8006 */ 	lui	$t6,%hi(var8005f114)
/*    30d38:	8dcef114 */ 	lw	$t6,%lo(var8005f114)($t6)
/*    30d3c:	8d8d0018 */ 	lw	$t5,0x18($t4)
/*    30d40:	adcd0040 */ 	sw	$t5,0x40($t6)
/*    30d44:	3c188006 */ 	lui	$t8,%hi(var8005f114)
/*    30d48:	8f18f114 */ 	lw	$t8,%lo(var8005f114)($t8)
/*    30d4c:	240f00b8 */ 	addiu	$t7,$zero,0xb8
/*    30d50:	af0f0044 */ 	sw	$t7,0x44($t8)
/*    30d54:	8fb90040 */ 	lw	$t9,0x40($sp)
/*    30d58:	3c098006 */ 	lui	$t1,%hi(var8005f114)
/*    30d5c:	8d29f114 */ 	lw	$t1,%lo(var8005f114)($t1)
/*    30d60:	8f280010 */ 	lw	$t0,0x10($t9)
/*    30d64:	ad280024 */ 	sw	$t0,0x24($t1)
/*    30d68:	3c0a8006 */ 	lui	$t2,%hi(var8005f114)
/*    30d6c:	8d4af114 */ 	lw	$t2,%lo(var8005f114)($t2)
/*    30d70:	ad400048 */ 	sw	$zero,0x48($t2)
/*    30d74:	3c0c8006 */ 	lui	$t4,%hi(var8005f114)
/*    30d78:	8d8cf114 */ 	lw	$t4,%lo(var8005f114)($t4)
/*    30d7c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    30d80:	ad8b004c */ 	sw	$t3,0x4c($t4)
/*    30d84:	8fad0040 */ 	lw	$t5,0x40($sp)
/*    30d88:	8dae000c */ 	lw	$t6,0xc($t5)
/*    30d8c:	29c10003 */ 	slti	$at,$t6,0x3
/*    30d90:	14200006 */ 	bnez	$at,.L00030dac
/*    30d94:	00000000 */ 	nop
/*    30d98:	3c188006 */ 	lui	$t8,%hi(var8005f114)
/*    30d9c:	8f18f114 */ 	lw	$t8,%lo(var8005f114)($t8)
/*    30da0:	240f0002 */ 	addiu	$t7,$zero,0x2
/*    30da4:	1000000f */ 	b	.L00030de4
/*    30da8:	af0f003c */ 	sw	$t7,0x3c($t8)
.L00030dac:
/*    30dac:	8fb90040 */ 	lw	$t9,0x40($sp)
/*    30db0:	8f28000c */ 	lw	$t0,0xc($t9)
/*    30db4:	1d000006 */ 	bgtz	$t0,.L00030dd0
/*    30db8:	00000000 */ 	nop
/*    30dbc:	3c0a8006 */ 	lui	$t2,%hi(var8005f114)
/*    30dc0:	8d4af114 */ 	lw	$t2,%lo(var8005f114)($t2)
/*    30dc4:	24090001 */ 	addiu	$t1,$zero,0x1
/*    30dc8:	10000006 */ 	b	.L00030de4
/*    30dcc:	ad49003c */ 	sw	$t1,0x3c($t2)
.L00030dd0:
/*    30dd0:	8fab0040 */ 	lw	$t3,0x40($sp)
/*    30dd4:	3c0d8006 */ 	lui	$t5,%hi(var8005f114)
/*    30dd8:	8dadf114 */ 	lw	$t5,%lo(var8005f114)($t5)
/*    30ddc:	8d6c000c */ 	lw	$t4,0xc($t3)
/*    30de0:	adac003c */ 	sw	$t4,0x3c($t5)
.L00030de4:
/*    30de4:	3c0e8006 */ 	lui	$t6,%hi(var8005f114)
/*    30de8:	8dcef114 */ 	lw	$t6,%lo(var8005f114)($t6)
/*    30dec:	240f0048 */ 	addiu	$t7,$zero,0x48
/*    30df0:	00002025 */ 	or	$a0,$zero,$zero
/*    30df4:	8dc7003c */ 	lw	$a3,0x3c($t6)
/*    30df8:	afaf0010 */ 	sw	$t7,0x10($sp)
/*    30dfc:	00002825 */ 	or	$a1,$zero,$zero
/*    30e00:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    30e04:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*    30e08:	3c188006 */ 	lui	$t8,%hi(var8005f114)
/*    30e0c:	8f18f114 */ 	lw	$t8,%lo(var8005f114)($t8)
/*    30e10:	af020034 */ 	sw	$v0,0x34($t8)
/*    30e14:	3c198006 */ 	lui	$t9,%hi(var8005f114)
/*    30e18:	8f39f114 */ 	lw	$t9,%lo(var8005f114)($t9)
/*    30e1c:	afa0003c */ 	sw	$zero,0x3c($sp)
/*    30e20:	8f28003c */ 	lw	$t0,0x3c($t9)
/*    30e24:	19000088 */ 	blez	$t0,.L00031048
/*    30e28:	00000000 */ 	nop
.L00030e2c:
/*    30e2c:	3c098006 */ 	lui	$t1,%hi(var8005f114)
/*    30e30:	8d29f114 */ 	lw	$t1,%lo(var8005f114)($t1)
/*    30e34:	8fab003c */ 	lw	$t3,0x3c($sp)
/*    30e38:	8d2a0034 */ 	lw	$t2,0x34($t1)
/*    30e3c:	000b60c0 */ 	sll	$t4,$t3,0x3
/*    30e40:	018b6021 */ 	addu	$t4,$t4,$t3
/*    30e44:	000c60c0 */ 	sll	$t4,$t4,0x3
/*    30e48:	014c6821 */ 	addu	$t5,$t2,$t4
/*    30e4c:	ada00014 */ 	sw	$zero,0x14($t5)
/*    30e50:	3c188006 */ 	lui	$t8,%hi(var8005f114)
/*    30e54:	8f18f114 */ 	lw	$t8,%lo(var8005f114)($t8)
/*    30e58:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*    30e5c:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    30e60:	8f190034 */ 	lw	$t9,0x34($t8)
/*    30e64:	000848c0 */ 	sll	$t1,$t0,0x3
/*    30e68:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*    30e6c:	01284821 */ 	addu	$t1,$t1,$t0
/*    30e70:	000948c0 */ 	sll	$t1,$t1,0x3
/*    30e74:	03295821 */ 	addu	$t3,$t9,$t1
/*    30e78:	ad6f0018 */ 	sw	$t7,0x18($t3)
/*    30e7c:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    30e80:	240c0004 */ 	addiu	$t4,$zero,0x4
/*    30e84:	00002025 */ 	or	$a0,$zero,$zero
/*    30e88:	8d470004 */ 	lw	$a3,0x4($t2)
/*    30e8c:	afac0010 */ 	sw	$t4,0x10($sp)
/*    30e90:	00002825 */ 	or	$a1,$zero,$zero
/*    30e94:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    30e98:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*    30e9c:	3c0d8006 */ 	lui	$t5,%hi(var8005f114)
/*    30ea0:	8dadf114 */ 	lw	$t5,%lo(var8005f114)($t5)
/*    30ea4:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*    30ea8:	8dae0034 */ 	lw	$t6,0x34($t5)
/*    30eac:	001840c0 */ 	sll	$t0,$t8,0x3
/*    30eb0:	01184021 */ 	addu	$t0,$t0,$t8
/*    30eb4:	000840c0 */ 	sll	$t0,$t0,0x3
/*    30eb8:	01c8c821 */ 	addu	$t9,$t6,$t0
/*    30ebc:	af22001c */ 	sw	$v0,0x1c($t9)
/*    30ec0:	8fa90040 */ 	lw	$t1,0x40($sp)
/*    30ec4:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    30ec8:	012f5821 */ 	addu	$t3,$t1,$t7
/*    30ecc:	916a001c */ 	lbu	$t2,0x1c($t3)
/*    30ed0:	1140000f */ 	beqz	$t2,.L00030f10
/*    30ed4:	00000000 */ 	nop
/*    30ed8:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*    30edc:	8fa50040 */ 	lw	$a1,0x40($sp)
/*    30ee0:	0c00e81c */ 	jal	func0003a070
/*    30ee4:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*    30ee8:	3c0c8006 */ 	lui	$t4,%hi(var8005f114)
/*    30eec:	8d8cf114 */ 	lw	$t4,%lo(var8005f114)($t4)
/*    30ef0:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*    30ef4:	8d8d0034 */ 	lw	$t5,0x34($t4)
/*    30ef8:	001870c0 */ 	sll	$t6,$t8,0x3
/*    30efc:	01d87021 */ 	addu	$t6,$t6,$t8
/*    30f00:	000e70c0 */ 	sll	$t6,$t6,0x3
/*    30f04:	01ae4021 */ 	addu	$t0,$t5,$t6
/*    30f08:	1000000a */ 	b	.L00030f34
/*    30f0c:	ad020020 */ 	sw	$v0,0x20($t0)
.L00030f10:
/*    30f10:	3c198006 */ 	lui	$t9,%hi(var8005f114)
/*    30f14:	8f39f114 */ 	lw	$t9,%lo(var8005f114)($t9)
/*    30f18:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    30f1c:	8f290034 */ 	lw	$t1,0x34($t9)
/*    30f20:	000f58c0 */ 	sll	$t3,$t7,0x3
/*    30f24:	016f5821 */ 	addu	$t3,$t3,$t7
/*    30f28:	000b58c0 */ 	sll	$t3,$t3,0x3
/*    30f2c:	012b5021 */ 	addu	$t2,$t1,$t3
/*    30f30:	ad400020 */ 	sw	$zero,0x20($t2)
.L00030f34:
/*    30f34:	240c0038 */ 	addiu	$t4,$zero,0x38
/*    30f38:	afac0010 */ 	sw	$t4,0x10($sp)
/*    30f3c:	00002025 */ 	or	$a0,$zero,$zero
/*    30f40:	00002825 */ 	or	$a1,$zero,$zero
/*    30f44:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*    30f48:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    30f4c:	24070001 */ 	addiu	$a3,$zero,0x1
/*    30f50:	3c188006 */ 	lui	$t8,%hi(var8005f114)
/*    30f54:	8f18f114 */ 	lw	$t8,%lo(var8005f114)($t8)
/*    30f58:	8fae003c */ 	lw	$t6,0x3c($sp)
/*    30f5c:	8f0d0034 */ 	lw	$t5,0x34($t8)
/*    30f60:	000e40c0 */ 	sll	$t0,$t6,0x3
/*    30f64:	010e4021 */ 	addu	$t0,$t0,$t6
/*    30f68:	000840c0 */ 	sll	$t0,$t0,0x3
/*    30f6c:	01a8c821 */ 	addu	$t9,$t5,$t0
/*    30f70:	af220044 */ 	sw	$v0,0x44($t9)
/*    30f74:	3c0f8006 */ 	lui	$t7,%hi(var8005f114)
/*    30f78:	8deff114 */ 	lw	$t7,%lo(var8005f114)($t7)
/*    30f7c:	8fab003c */ 	lw	$t3,0x3c($sp)
/*    30f80:	8de90034 */ 	lw	$t1,0x34($t7)
/*    30f84:	000b50c0 */ 	sll	$t2,$t3,0x3
/*    30f88:	014b5021 */ 	addu	$t2,$t2,$t3
/*    30f8c:	000a50c0 */ 	sll	$t2,$t2,0x3
/*    30f90:	012a6021 */ 	addu	$t4,$t1,$t2
/*    30f94:	8d980044 */ 	lw	$t8,0x44($t4)
/*    30f98:	a7000002 */ 	sh	$zero,0x2($t8)
/*    30f9c:	240e0008 */ 	addiu	$t6,$zero,0x8
/*    30fa0:	afae0010 */ 	sw	$t6,0x10($sp)
/*    30fa4:	00002025 */ 	or	$a0,$zero,$zero
/*    30fa8:	00002825 */ 	or	$a1,$zero,$zero
/*    30fac:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*    30fb0:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    30fb4:	24070001 */ 	addiu	$a3,$zero,0x1
/*    30fb8:	3c0d8006 */ 	lui	$t5,%hi(var8005f114)
/*    30fbc:	8dadf114 */ 	lw	$t5,%lo(var8005f114)($t5)
/*    30fc0:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    30fc4:	8da80034 */ 	lw	$t0,0x34($t5)
/*    30fc8:	001978c0 */ 	sll	$t7,$t9,0x3
/*    30fcc:	01f97821 */ 	addu	$t7,$t7,$t9
/*    30fd0:	000f78c0 */ 	sll	$t7,$t7,0x3
/*    30fd4:	010f5821 */ 	addu	$t3,$t0,$t7
/*    30fd8:	8d690044 */ 	lw	$t1,0x44($t3)
/*    30fdc:	ad22002c */ 	sw	$v0,0x2c($t1)
/*    30fe0:	240a0008 */ 	addiu	$t2,$zero,0x8
/*    30fe4:	afaa0010 */ 	sw	$t2,0x10($sp)
/*    30fe8:	00002025 */ 	or	$a0,$zero,$zero
/*    30fec:	00002825 */ 	or	$a1,$zero,$zero
/*    30ff0:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*    30ff4:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    30ff8:	24070001 */ 	addiu	$a3,$zero,0x1
/*    30ffc:	3c0c8006 */ 	lui	$t4,%hi(var8005f114)
/*    31000:	8d8cf114 */ 	lw	$t4,%lo(var8005f114)($t4)
/*    31004:	8fae003c */ 	lw	$t6,0x3c($sp)
/*    31008:	8d980034 */ 	lw	$t8,0x34($t4)
/*    3100c:	000e68c0 */ 	sll	$t5,$t6,0x3
/*    31010:	01ae6821 */ 	addu	$t5,$t5,$t6
/*    31014:	000d68c0 */ 	sll	$t5,$t5,0x3
/*    31018:	030dc821 */ 	addu	$t9,$t8,$t5
/*    3101c:	8f280044 */ 	lw	$t0,0x44($t9)
/*    31020:	ad020030 */ 	sw	$v0,0x30($t0)
/*    31024:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    31028:	3c098006 */ 	lui	$t1,%hi(var8005f114)
/*    3102c:	8d29f114 */ 	lw	$t1,%lo(var8005f114)($t1)
/*    31030:	25eb0001 */ 	addiu	$t3,$t7,0x1
/*    31034:	afab003c */ 	sw	$t3,0x3c($sp)
/*    31038:	8d2a003c */ 	lw	$t2,0x3c($t1)
/*    3103c:	016a082a */ 	slt	$at,$t3,$t2
/*    31040:	1420ff7a */ 	bnez	$at,.L00030e2c
/*    31044:	00000000 */ 	nop
.L00031048:
/*    31048:	240c0014 */ 	addiu	$t4,$zero,0x14
/*    3104c:	afac0010 */ 	sw	$t4,0x10($sp)
/*    31050:	00002025 */ 	or	$a0,$zero,$zero
/*    31054:	00002825 */ 	or	$a1,$zero,$zero
/*    31058:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*    3105c:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    31060:	24070001 */ 	addiu	$a3,$zero,0x1
/*    31064:	3c0e8006 */ 	lui	$t6,%hi(var8005f114)
/*    31068:	8dcef114 */ 	lw	$t6,%lo(var8005f114)($t6)
/*    3106c:	adc20030 */ 	sw	$v0,0x30($t6)
/*    31070:	3c0d8006 */ 	lui	$t5,%hi(var8005f114)
/*    31074:	8dadf114 */ 	lw	$t5,%lo(var8005f114)($t5)
/*    31078:	3c187004 */ 	lui	$t8,%hi(func0003a100)
/*    3107c:	2718a100 */ 	addiu	$t8,$t8,%lo(func0003a100)
/*    31080:	8db90030 */ 	lw	$t9,0x30($t5)
/*    31084:	af380004 */ 	sw	$t8,0x4($t9)
/*    31088:	3c088006 */ 	lui	$t0,%hi(var8005f114)
/*    3108c:	8d08f114 */ 	lw	$t0,%lo(var8005f114)($t0)
/*    31090:	ad000004 */ 	sw	$zero,0x4($t0)
/*    31094:	3c0f8006 */ 	lui	$t7,%hi(var8005f114)
/*    31098:	8deff114 */ 	lw	$t7,%lo(var8005f114)($t7)
/*    3109c:	ade00008 */ 	sw	$zero,0x8($t7)
/*    310a0:	3c098006 */ 	lui	$t1,%hi(var8005f114)
/*    310a4:	8d29f114 */ 	lw	$t1,%lo(var8005f114)($t1)
/*    310a8:	ad200014 */ 	sw	$zero,0x14($t1)
/*    310ac:	3c0b8006 */ 	lui	$t3,%hi(var8005f114)
/*    310b0:	8d6bf114 */ 	lw	$t3,%lo(var8005f114)($t3)
/*    310b4:	ad600018 */ 	sw	$zero,0x18($t3)
/*    310b8:	3c0a8006 */ 	lui	$t2,%hi(var8005f114)
/*    310bc:	8d4af114 */ 	lw	$t2,%lo(var8005f114)($t2)
/*    310c0:	ad40000c */ 	sw	$zero,0xc($t2)
/*    310c4:	3c0c8006 */ 	lui	$t4,%hi(var8005f114)
/*    310c8:	8d8cf114 */ 	lw	$t4,%lo(var8005f114)($t4)
/*    310cc:	ad800010 */ 	sw	$zero,0x10($t4)
/*    310d0:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    310d4:	240d00c0 */ 	addiu	$t5,$zero,0xc0
/*    310d8:	00002025 */ 	or	$a0,$zero,$zero
/*    310dc:	8dc70004 */ 	lw	$a3,0x4($t6)
/*    310e0:	afad0010 */ 	sw	$t5,0x10($sp)
/*    310e4:	00002825 */ 	or	$a1,$zero,$zero
/*    310e8:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    310ec:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*    310f0:	afa20030 */ 	sw	$v0,0x30($sp)
/*    310f4:	8fb80040 */ 	lw	$t8,0x40($sp)
/*    310f8:	afa0003c */ 	sw	$zero,0x3c($sp)
/*    310fc:	8f190004 */ 	lw	$t9,0x4($t8)
/*    31100:	1b200045 */ 	blez	$t9,.L00031218
/*    31104:	00000000 */ 	nop
.L00031108:
/*    31108:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*    3110c:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    31110:	00087880 */ 	sll	$t7,$t0,0x2
/*    31114:	01e87823 */ 	subu	$t7,$t7,$t0
/*    31118:	000f7980 */ 	sll	$t7,$t7,0x6
/*    3111c:	01e95821 */ 	addu	$t3,$t7,$t1
/*    31120:	afab0034 */ 	sw	$t3,0x34($sp)
/*    31124:	3c058006 */ 	lui	$a1,%hi(var8005f114)
/*    31128:	8ca5f114 */ 	lw	$a1,%lo(var8005f114)($a1)
/*    3112c:	8fa40034 */ 	lw	$a0,0x34($sp)
/*    31130:	0c00c5dc */ 	jal	alLink
/*    31134:	24a50004 */ 	addiu	$a1,$a1,4
/*    31138:	8faa0034 */ 	lw	$t2,0x34($sp)
/*    3113c:	ad400008 */ 	sw	$zero,0x8($t2)
/*    31140:	3c0c8006 */ 	lui	$t4,%hi(var8005f114)
/*    31144:	8d8cf114 */ 	lw	$t4,%lo(var8005f114)($t4)
/*    31148:	8fa40034 */ 	lw	$a0,0x34($sp)
/*    3114c:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*    31150:	0c00f085 */ 	jal	func0003c214
/*    31154:	8d850024 */ 	lw	$a1,0x24($t4)
/*    31158:	3c0e8006 */ 	lui	$t6,%hi(var8005f114)
/*    3115c:	8dcef114 */ 	lw	$t6,%lo(var8005f114)($t6)
/*    31160:	afa00038 */ 	sw	$zero,0x38($sp)
/*    31164:	8dcd003c */ 	lw	$t5,0x3c($t6)
/*    31168:	19a00023 */ 	blez	$t5,.L000311f8
/*    3116c:	00000000 */ 	nop
.L00031170:
/*    31170:	3c198006 */ 	lui	$t9,%hi(var8005f114)
/*    31174:	8f39f114 */ 	lw	$t9,%lo(var8005f114)($t9)
/*    31178:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    3117c:	8fb80034 */ 	lw	$t8,0x34($sp)
/*    31180:	8f280034 */ 	lw	$t0,0x34($t9)
/*    31184:	000f48c0 */ 	sll	$t1,$t7,0x3
/*    31188:	012f4821 */ 	addu	$t1,$t1,$t7
/*    3118c:	000948c0 */ 	sll	$t1,$t1,0x3
/*    31190:	01095821 */ 	addu	$t3,$t0,$t1
/*    31194:	8d6c0014 */ 	lw	$t4,0x14($t3)
/*    31198:	8d6a001c */ 	lw	$t2,0x1c($t3)
/*    3119c:	3c198006 */ 	lui	$t9,%hi(var8005f114)
/*    311a0:	000c7080 */ 	sll	$t6,$t4,0x2
/*    311a4:	014e6821 */ 	addu	$t5,$t2,$t6
/*    311a8:	adb80000 */ 	sw	$t8,0x0($t5)
/*    311ac:	8fa80038 */ 	lw	$t0,0x38($sp)
/*    311b0:	8f39f114 */ 	lw	$t9,%lo(var8005f114)($t9)
/*    311b4:	000848c0 */ 	sll	$t1,$t0,0x3
/*    311b8:	8f2f0034 */ 	lw	$t7,0x34($t9)
/*    311bc:	01284821 */ 	addu	$t1,$t1,$t0
/*    311c0:	000948c0 */ 	sll	$t1,$t1,0x3
/*    311c4:	01e95821 */ 	addu	$t3,$t7,$t1
/*    311c8:	8d6c0014 */ 	lw	$t4,0x14($t3)
/*    311cc:	258a0001 */ 	addiu	$t2,$t4,0x1
/*    311d0:	ad6a0014 */ 	sw	$t2,0x14($t3)
/*    311d4:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    311d8:	3c0d8006 */ 	lui	$t5,%hi(var8005f114)
/*    311dc:	8dadf114 */ 	lw	$t5,%lo(var8005f114)($t5)
/*    311e0:	25d80001 */ 	addiu	$t8,$t6,0x1
/*    311e4:	afb80038 */ 	sw	$t8,0x38($sp)
/*    311e8:	8db9003c */ 	lw	$t9,0x3c($t5)
/*    311ec:	0319082a */ 	slt	$at,$t8,$t9
/*    311f0:	1420ffdf */ 	bnez	$at,.L00031170
/*    311f4:	00000000 */ 	nop
.L000311f8:
/*    311f8:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*    311fc:	8fa90040 */ 	lw	$t1,0x40($sp)
/*    31200:	250f0001 */ 	addiu	$t7,$t0,0x1
/*    31204:	afaf003c */ 	sw	$t7,0x3c($sp)
/*    31208:	8d2c0004 */ 	lw	$t4,0x4($t1)
/*    3120c:	01ec082a */ 	slt	$at,$t7,$t4
/*    31210:	1420ffbd */ 	bnez	$at,.L00031108
/*    31214:	00000000 */ 	nop
.L00031218:
/*    31218:	8faa0040 */ 	lw	$t2,0x40($sp)
/*    3121c:	240b0024 */ 	addiu	$t3,$zero,0x24
/*    31220:	00002025 */ 	or	$a0,$zero,$zero
/*    31224:	8d470008 */ 	lw	$a3,0x8($t2)
/*    31228:	afab0010 */ 	sw	$t3,0x10($sp)
/*    3122c:	00002825 */ 	or	$a1,$zero,$zero
/*    31230:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    31234:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*    31238:	afa20028 */ 	sw	$v0,0x28($sp)
/*    3123c:	3c0e8006 */ 	lui	$t6,%hi(var8005f114)
/*    31240:	8dcef114 */ 	lw	$t6,%lo(var8005f114)($t6)
/*    31244:	adc0002c */ 	sw	$zero,0x2c($t6)
/*    31248:	8fad0040 */ 	lw	$t5,0x40($sp)
/*    3124c:	afa0003c */ 	sw	$zero,0x3c($sp)
/*    31250:	8db80008 */ 	lw	$t8,0x8($t5)
/*    31254:	1b000019 */ 	blez	$t8,.L000312bc
/*    31258:	00000000 */ 	nop
.L0003125c:
/*    3125c:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*    31260:	8fa90028 */ 	lw	$t1,0x28($sp)
/*    31264:	001940c0 */ 	sll	$t0,$t9,0x3
/*    31268:	01194021 */ 	addu	$t0,$t0,$t9
/*    3126c:	00084080 */ 	sll	$t0,$t0,0x2
/*    31270:	01097821 */ 	addu	$t7,$t0,$t1
/*    31274:	afaf0024 */ 	sw	$t7,0x24($sp)
/*    31278:	3c0c8006 */ 	lui	$t4,%hi(var8005f114)
/*    3127c:	8d8cf114 */ 	lw	$t4,%lo(var8005f114)($t4)
/*    31280:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    31284:	8d8a002c */ 	lw	$t2,0x2c($t4)
/*    31288:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*    3128c:	3c0d8006 */ 	lui	$t5,%hi(var8005f114)
/*    31290:	8dadf114 */ 	lw	$t5,%lo(var8005f114)($t5)
/*    31294:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    31298:	adae002c */ 	sw	$t6,0x2c($t5)
/*    3129c:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*    312a0:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    312a4:	27190001 */ 	addiu	$t9,$t8,0x1
/*    312a8:	afb9003c */ 	sw	$t9,0x3c($sp)
/*    312ac:	8d090008 */ 	lw	$t1,0x8($t0)
/*    312b0:	0329082a */ 	slt	$at,$t9,$t1
/*    312b4:	1420ffe9 */ 	bnez	$at,.L0003125c
/*    312b8:	00000000 */ 	nop
.L000312bc:
/*    312bc:	3c0c8006 */ 	lui	$t4,%hi(var8005f114)
/*    312c0:	8d8cf114 */ 	lw	$t4,%lo(var8005f114)($t4)
/*    312c4:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    312c8:	ad8f0028 */ 	sw	$t7,0x28($t4)
/*    312cc:	10000001 */ 	b	.L000312d4
/*    312d0:	00000000 */ 	nop
.L000312d4:
/*    312d4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    312d8:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*    312dc:	03e00008 */ 	jr	$ra
/*    312e0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel alAudioFrame
/*    312e4:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*    312e8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    312ec:	afa40040 */ 	sw	$a0,0x40($sp)
/*    312f0:	afa50044 */ 	sw	$a1,0x44($sp)
/*    312f4:	afa60048 */ 	sw	$a2,0x48($sp)
/*    312f8:	afa7004c */ 	sw	$a3,0x4c($sp)
/*    312fc:	afb10018 */ 	sw	$s1,0x18($sp)
/*    31300:	afb00014 */ 	sw	$s0,0x14($sp)
/*    31304:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    31308:	afae0038 */ 	sw	$t6,0x38($sp)
/*    3130c:	8faf0048 */ 	lw	$t7,0x48($sp)
/*    31310:	afaf002c */ 	sw	$t7,0x2c($sp)
/*    31314:	3c188006 */ 	lui	$t8,%hi(var8005f114)
/*    31318:	8f18f114 */ 	lw	$t8,%lo(var8005f114)($t8)
/*    3131c:	8f190000 */ 	lw	$t9,0x0($t8)
/*    31320:	17200005 */ 	bnez	$t9,.L00031338
/*    31324:	00000000 */ 	nop
/*    31328:	8fa80044 */ 	lw	$t0,0x44($sp)
/*    3132c:	ad000000 */ 	sw	$zero,0x0($t0)
/*    31330:	1000006f */ 	b	.L000314f0
/*    31334:	8fa20040 */ 	lw	$v0,0x40($sp)
.L00031338:
/*    31338:	0c00c5b4 */ 	jal	func000316d0
/*    3133c:	27a4003c */ 	addiu	$a0,$sp,0x3c
/*    31340:	3c098006 */ 	lui	$t1,%hi(var8005f114)
/*    31344:	8d29f114 */ 	lw	$t1,%lo(var8005f114)($t1)
/*    31348:	3c0a8006 */ 	lui	$t2,%hi(var8005f114)
/*    3134c:	ad22001c */ 	sw	$v0,0x1c($t1)
/*    31350:	8d4af114 */ 	lw	$t2,%lo(var8005f114)($t2)
/*    31354:	8fae004c */ 	lw	$t6,0x4c($sp)
/*    31358:	8d4b001c */ 	lw	$t3,0x1c($t2)
/*    3135c:	8d4c0020 */ 	lw	$t4,0x20($t2)
/*    31360:	016c6823 */ 	subu	$t5,$t3,$t4
/*    31364:	01ae082a */ 	slt	$at,$t5,$t6
/*    31368:	10200022 */ 	beqz	$at,.L000313f4
/*    3136c:	00000000 */ 	nop
.L00031370:
/*    31370:	3c0f8006 */ 	lui	$t7,%hi(var8005f114)
/*    31374:	8deff114 */ 	lw	$t7,%lo(var8005f114)($t7)
/*    31378:	2401fff0 */ 	addiu	$at,$zero,-16
/*    3137c:	8df8001c */ 	lw	$t8,0x1c($t7)
/*    31380:	0301c824 */ 	and	$t9,$t8,$at
/*    31384:	adf9001c */ 	sw	$t9,0x1c($t7)
/*    31388:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*    3138c:	8d190008 */ 	lw	$t9,0x8($t0)
/*    31390:	01002025 */ 	or	$a0,$t0,$zero
/*    31394:	0320f809 */ 	jalr	$t9
/*    31398:	00000000 */ 	nop
/*    3139c:	00408825 */ 	or	$s1,$v0,$zero
/*    313a0:	0c00c58d */ 	jal	func00031634
/*    313a4:	02202025 */ 	or	$a0,$s1,$zero
/*    313a8:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*    313ac:	00408025 */ 	or	$s0,$v0,$zero
/*    313b0:	8d2a0010 */ 	lw	$t2,0x10($t1)
/*    313b4:	01505821 */ 	addu	$t3,$t2,$s0
/*    313b8:	ad2b0010 */ 	sw	$t3,0x10($t1)
/*    313bc:	0c00c5b4 */ 	jal	func000316d0
/*    313c0:	27a4003c */ 	addiu	$a0,$sp,0x3c
/*    313c4:	3c0c8006 */ 	lui	$t4,%hi(var8005f114)
/*    313c8:	8d8cf114 */ 	lw	$t4,%lo(var8005f114)($t4)
/*    313cc:	3c0d8006 */ 	lui	$t5,%hi(var8005f114)
/*    313d0:	ad82001c */ 	sw	$v0,0x1c($t4)
/*    313d4:	8dadf114 */ 	lw	$t5,%lo(var8005f114)($t5)
/*    313d8:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*    313dc:	8dae001c */ 	lw	$t6,0x1c($t5)
/*    313e0:	8db80020 */ 	lw	$t8,0x20($t5)
/*    313e4:	01d87823 */ 	subu	$t7,$t6,$t8
/*    313e8:	01e8082a */ 	slt	$at,$t7,$t0
/*    313ec:	1420ffe0 */ 	bnez	$at,.L00031370
/*    313f0:	00000000 */ 	nop
.L000313f4:
/*    313f4:	3c198006 */ 	lui	$t9,%hi(var8005f114)
/*    313f8:	8f39f114 */ 	lw	$t9,%lo(var8005f114)($t9)
/*    313fc:	2401fff0 */ 	addiu	$at,$zero,-16
/*    31400:	8f2a001c */ 	lw	$t2,0x1c($t9)
/*    31404:	01415824 */ 	and	$t3,$t2,$at
/*    31408:	af2b001c */ 	sw	$t3,0x1c($t9)
/*    3140c:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*    31410:	1920002b */ 	blez	$t1,.L000314c0
/*    31414:	00000000 */ 	nop
.L00031418:
/*    31418:	3c0c8006 */ 	lui	$t4,%hi(var8005f114)
/*    3141c:	8d8cf114 */ 	lw	$t4,%lo(var8005f114)($t4)
/*    31420:	8fae004c */ 	lw	$t6,0x4c($sp)
/*    31424:	8d8d0044 */ 	lw	$t5,0x44($t4)
/*    31428:	01ae082a */ 	slt	$at,$t5,$t6
/*    3142c:	10200003 */ 	beqz	$at,.L0003143c
/*    31430:	00000000 */ 	nop
/*    31434:	10000003 */ 	b	.L00031444
/*    31438:	afad0030 */ 	sw	$t5,0x30($sp)
.L0003143c:
/*    3143c:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*    31440:	afb80030 */ 	sw	$t8,0x30($sp)
.L00031444:
/*    31444:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    31448:	afaf0034 */ 	sw	$t7,0x34($sp)
/*    3144c:	3c0a8006 */ 	lui	$t2,%hi(var8005f114)
/*    31450:	8d4af114 */ 	lw	$t2,%lo(var8005f114)($t2)
/*    31454:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*    31458:	ad480048 */ 	sw	$t0,0x48($t2)
/*    3145c:	3c0b8006 */ 	lui	$t3,%hi(var8005f114)
/*    31460:	8d6bf114 */ 	lw	$t3,%lo(var8005f114)($t3)
/*    31464:	8fa50034 */ 	lw	$a1,0x34($sp)
/*    31468:	0c00f10c */ 	jal	func0003c430
/*    3146c:	8d640020 */ 	lw	$a0,0x20($t3)
/*    31470:	afa20038 */ 	sw	$v0,0x38($sp)
/*    31474:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*    31478:	8fa90030 */ 	lw	$t1,0x30($sp)
/*    3147c:	03296023 */ 	subu	$t4,$t9,$t1
/*    31480:	afac004c */ 	sw	$t4,0x4c($sp)
/*    31484:	8fad0030 */ 	lw	$t5,0x30($sp)
/*    31488:	8fae002c */ 	lw	$t6,0x2c($sp)
/*    3148c:	000dc040 */ 	sll	$t8,$t5,0x1
/*    31490:	00187840 */ 	sll	$t7,$t8,0x1
/*    31494:	01cf4021 */ 	addu	$t0,$t6,$t7
/*    31498:	afa8002c */ 	sw	$t0,0x2c($sp)
/*    3149c:	3c0a8006 */ 	lui	$t2,%hi(var8005f114)
/*    314a0:	8d4af114 */ 	lw	$t2,%lo(var8005f114)($t2)
/*    314a4:	8fb90030 */ 	lw	$t9,0x30($sp)
/*    314a8:	8d4b0020 */ 	lw	$t3,0x20($t2)
/*    314ac:	01794821 */ 	addu	$t1,$t3,$t9
/*    314b0:	ad490020 */ 	sw	$t1,0x20($t2)
/*    314b4:	8fac004c */ 	lw	$t4,0x4c($sp)
/*    314b8:	1d80ffd7 */ 	bgtz	$t4,.L00031418
/*    314bc:	00000000 */ 	nop
.L000314c0:
/*    314c0:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    314c4:	8fb80040 */ 	lw	$t8,0x40($sp)
/*    314c8:	8fa80044 */ 	lw	$t0,0x44($sp)
/*    314cc:	01b87023 */ 	subu	$t6,$t5,$t8
/*    314d0:	000e78c3 */ 	sra	$t7,$t6,0x3
/*    314d4:	ad0f0000 */ 	sw	$t7,0x0($t0)
/*    314d8:	0c00c564 */ 	jal	func00031590
/*    314dc:	00000000 */ 	nop
/*    314e0:	10000003 */ 	b	.L000314f0
/*    314e4:	8fa20038 */ 	lw	$v0,0x38($sp)
/*    314e8:	10000001 */ 	b	.L000314f0
/*    314ec:	00000000 */ 	nop
.L000314f0:
/*    314f0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    314f4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    314f8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    314fc:	03e00008 */ 	jr	$ra
/*    31500:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel func00031504
/*    31504:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    31508:	afa00004 */ 	sw	$zero,0x4($sp)
/*    3150c:	3c0e8006 */ 	lui	$t6,%hi(var8005f114)
/*    31510:	8dcef114 */ 	lw	$t6,%lo(var8005f114)($t6)
/*    31514:	8dcf002c */ 	lw	$t7,0x2c($t6)
/*    31518:	11e0000c */ 	beqz	$t7,.L0003154c
/*    3151c:	00000000 */ 	nop
/*    31520:	3c188006 */ 	lui	$t8,%hi(var8005f114)
/*    31524:	8f18f114 */ 	lw	$t8,%lo(var8005f114)($t8)
/*    31528:	8f19002c */ 	lw	$t9,0x2c($t8)
/*    3152c:	afb90004 */ 	sw	$t9,0x4($sp)
/*    31530:	3c088006 */ 	lui	$t0,%hi(var8005f114)
/*    31534:	8d08f114 */ 	lw	$t0,%lo(var8005f114)($t0)
/*    31538:	8d09002c */ 	lw	$t1,0x2c($t0)
/*    3153c:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*    31540:	ad0a002c */ 	sw	$t2,0x2c($t0)
/*    31544:	8fab0004 */ 	lw	$t3,0x4($sp)
/*    31548:	ad600000 */ 	sw	$zero,0x0($t3)
.L0003154c:
/*    3154c:	10000003 */ 	b	.L0003155c
/*    31550:	8fa20004 */ 	lw	$v0,0x4($sp)
/*    31554:	10000001 */ 	b	.L0003155c
/*    31558:	00000000 */ 	nop
.L0003155c:
/*    3155c:	03e00008 */ 	jr	$ra
/*    31560:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func00031564
/*    31564:	3c0e8006 */ 	lui	$t6,%hi(var8005f114)
/*    31568:	8dcef114 */ 	lw	$t6,%lo(var8005f114)($t6)
/*    3156c:	8dcf002c */ 	lw	$t7,0x2c($t6)
/*    31570:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*    31574:	3c188006 */ 	lui	$t8,%hi(var8005f114)
/*    31578:	8f18f114 */ 	lw	$t8,%lo(var8005f114)($t8)
/*    3157c:	af04002c */ 	sw	$a0,0x2c($t8)
/*    31580:	03e00008 */ 	jr	$ra
/*    31584:	00000000 */ 	nop
/*    31588:	03e00008 */ 	jr	$ra
/*    3158c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00031590
/*    31590:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*    31594:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    31598:	3c0e8006 */ 	lui	$t6,%hi(var8005f114)
/*    3159c:	8dcef114 */ 	lw	$t6,%lo(var8005f114)($t6)
/*    315a0:	8dcf0014 */ 	lw	$t7,0x14($t6)
/*    315a4:	11e0000d */ 	beqz	$t7,.L000315dc
/*    315a8:	afaf001c */ 	sw	$t7,0x1c($sp)
.L000315ac:
/*    315ac:	0c00c5e9 */ 	jal	alUnlink
/*    315b0:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    315b4:	3c058006 */ 	lui	$a1,%hi(var8005f114)
/*    315b8:	8ca5f114 */ 	lw	$a1,%lo(var8005f114)($a1)
/*    315bc:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    315c0:	0c00c5dc */ 	jal	alLink
/*    315c4:	24a50004 */ 	addiu	$a1,$a1,4
/*    315c8:	3c188006 */ 	lui	$t8,%hi(var8005f114)
/*    315cc:	8f18f114 */ 	lw	$t8,%lo(var8005f114)($t8)
/*    315d0:	8f190014 */ 	lw	$t9,0x14($t8)
/*    315d4:	1720fff5 */ 	bnez	$t9,.L000315ac
/*    315d8:	afb9001c */ 	sw	$t9,0x1c($sp)
.L000315dc:
/*    315dc:	10000001 */ 	b	.L000315e4
/*    315e0:	00000000 */ 	nop
.L000315e4:
/*    315e4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    315e8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*    315ec:	03e00008 */ 	jr	$ra
/*    315f0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func000315f4
/*    315f4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    315f8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    315fc:	afa40018 */ 	sw	$a0,0x18($sp)
/*    31600:	0c00c5e9 */ 	jal	alUnlink
/*    31604:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    31608:	3c058006 */ 	lui	$a1,%hi(var8005f114)
/*    3160c:	8ca5f114 */ 	lw	$a1,%lo(var8005f114)($a1)
/*    31610:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    31614:	0c00c5dc */ 	jal	alLink
/*    31618:	24a50014 */ 	addiu	$a1,$a1,20
/*    3161c:	10000001 */ 	b	.L00031624
/*    31620:	00000000 */ 	nop
.L00031624:
/*    31624:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    31628:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    3162c:	03e00008 */ 	jr	$ra
/*    31630:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func00031634
/*    31634:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    31638:	3c0e8006 */ 	lui	$t6,%hi(var8005f114)
/*    3163c:	8dcef114 */ 	lw	$t6,%lo(var8005f114)($t6)
/*    31640:	44842000 */ 	mtc1	$a0,$f4
/*    31644:	3c017005 */ 	lui	$at,%hi(var70054730)
/*    31648:	8dcf0040 */ 	lw	$t7,0x40($t6)
/*    3164c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*    31650:	c4324730 */ 	lwc1	$f18,%lo(var70054730)($at)
/*    31654:	448f4000 */ 	mtc1	$t7,$f8
/*    31658:	3c013f00 */ 	lui	$at,0x3f00
/*    3165c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*    31660:	44814000 */ 	mtc1	$at,$f8
/*    31664:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*    31668:	46128103 */ 	div.s	$f4,$f16,$f18
/*    3166c:	46082180 */ 	add.s	$f6,$f4,$f8
/*    31670:	e7a60004 */ 	swc1	$f6,0x4($sp)
/*    31674:	c7aa0004 */ 	lwc1	$f10,0x4($sp)
/*    31678:	4600540d */ 	trunc.w.s	$f16,$f10
/*    3167c:	44028000 */ 	mfc1	$v0,$f16
/*    31680:	10000003 */ 	b	.L00031690
/*    31684:	00000000 */ 	nop
/*    31688:	10000001 */ 	b	.L00031690
/*    3168c:	00000000 */ 	nop
.L00031690:
/*    31690:	03e00008 */ 	jr	$ra
/*    31694:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel func00031698
/*    31698:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    3169c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    316a0:	afa40018 */ 	sw	$a0,0x18($sp)
/*    316a4:	0c00c58d */ 	jal	func00031634
/*    316a8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*    316ac:	2401fff0 */ 	addiu	$at,$zero,-16
/*    316b0:	10000003 */ 	b	.L000316c0
/*    316b4:	00411024 */ 	and	$v0,$v0,$at
/*    316b8:	10000001 */ 	b	.L000316c0
/*    316bc:	00000000 */ 	nop
.L000316c0:
/*    316c0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    316c4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*    316c8:	03e00008 */ 	jr	$ra
/*    316cc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func000316d0
/*    316d0:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*    316d4:	3c0e7fff */ 	lui	$t6,0x7fff
/*    316d8:	35ceffff */ 	ori	$t6,$t6,0xffff
/*    316dc:	afae0004 */ 	sw	$t6,0x4($sp)
/*    316e0:	ac800000 */ 	sw	$zero,0x0($a0)
/*    316e4:	3c0f8006 */ 	lui	$t7,%hi(var8005f114)
/*    316e8:	8deff114 */ 	lw	$t7,%lo(var8005f114)($t7)
/*    316ec:	8df80000 */ 	lw	$t8,0x0($t7)
/*    316f0:	13000018 */ 	beqz	$t8,.L00031754
/*    316f4:	afb80000 */ 	sw	$t8,0x0($sp)
.L000316f8:
/*    316f8:	3c098006 */ 	lui	$t1,%hi(var8005f114)
/*    316fc:	8d29f114 */ 	lw	$t1,%lo(var8005f114)($t1)
/*    31700:	8fb90000 */ 	lw	$t9,0x0($sp)
/*    31704:	8fac0004 */ 	lw	$t4,0x4($sp)
/*    31708:	8d2a0020 */ 	lw	$t2,0x20($t1)
/*    3170c:	8f280010 */ 	lw	$t0,0x10($t9)
/*    31710:	010a5823 */ 	subu	$t3,$t0,$t2
/*    31714:	016c082a */ 	slt	$at,$t3,$t4
/*    31718:	1020000a */ 	beqz	$at,.L00031744
/*    3171c:	00000000 */ 	nop
/*    31720:	8fad0000 */ 	lw	$t5,0x0($sp)
/*    31724:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*    31728:	3c188006 */ 	lui	$t8,%hi(var8005f114)
/*    3172c:	8f18f114 */ 	lw	$t8,%lo(var8005f114)($t8)
/*    31730:	8fae0000 */ 	lw	$t6,0x0($sp)
/*    31734:	8f190020 */ 	lw	$t9,0x20($t8)
/*    31738:	8dcf0010 */ 	lw	$t7,0x10($t6)
/*    3173c:	01f94823 */ 	subu	$t1,$t7,$t9
/*    31740:	afa90004 */ 	sw	$t1,0x4($sp)
.L00031744:
/*    31744:	8fa80000 */ 	lw	$t0,0x0($sp)
/*    31748:	8d0a0000 */ 	lw	$t2,0x0($t0)
/*    3174c:	1540ffea */ 	bnez	$t2,.L000316f8
/*    31750:	afaa0000 */ 	sw	$t2,0x0($sp)
.L00031754:
/*    31754:	8c8b0000 */ 	lw	$t3,0x0($a0)
/*    31758:	10000003 */ 	b	.L00031768
/*    3175c:	8d620010 */ 	lw	$v0,0x10($t3)
/*    31760:	10000001 */ 	b	.L00031768
/*    31764:	00000000 */ 	nop
.L00031768:
/*    31768:	03e00008 */ 	jr	$ra
/*    3176c:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel alLink
/*    31770:	8cae0000 */ 	lw	$t6,0x0($a1)
/*    31774:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*    31778:	ac850004 */ 	sw	$a1,0x4($a0)
/*    3177c:	8caf0000 */ 	lw	$t7,0x0($a1)
/*    31780:	11e00003 */ 	beqz	$t7,.L00031790
/*    31784:	00000000 */ 	nop
/*    31788:	8cb80000 */ 	lw	$t8,0x0($a1)
/*    3178c:	af040004 */ 	sw	$a0,0x4($t8)
.L00031790:
/*    31790:	aca40000 */ 	sw	$a0,0x0($a1)
/*    31794:	03e00008 */ 	jr	$ra
/*    31798:	00000000 */ 	nop
/*    3179c:	03e00008 */ 	jr	$ra
/*    317a0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel alUnlink
/*    317a4:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*    317a8:	11c00004 */ 	beqz	$t6,.L000317bc
/*    317ac:	00000000 */ 	nop
/*    317b0:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*    317b4:	8c980000 */ 	lw	$t8,0x0($a0)
/*    317b8:	af0f0004 */ 	sw	$t7,0x4($t8)
.L000317bc:
/*    317bc:	8c990004 */ 	lw	$t9,0x4($a0)
/*    317c0:	13200004 */ 	beqz	$t9,.L000317d4
/*    317c4:	00000000 */ 	nop
/*    317c8:	8c880000 */ 	lw	$t0,0x0($a0)
/*    317cc:	8c890004 */ 	lw	$t1,0x4($a0)
/*    317d0:	ad280000 */ 	sw	$t0,0x0($t1)
.L000317d4:
/*    317d4:	03e00008 */ 	jr	$ra
/*    317d8:	00000000 */ 	nop
/*    317dc:	03e00008 */ 	jr	$ra
/*    317e0:	00000000 */ 	nop
);
