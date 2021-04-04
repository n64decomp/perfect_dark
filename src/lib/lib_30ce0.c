#include <ultra64.h>
#include "PR/synthInternals.h"
#include "constants.h"
#include "bss.h"
#include "lib/lib_30ce0.h"
#include "lib/lib_39fe0.h"
#include "lib/lib_3a100.h"
#include "lib/lib_3c430.h"
#include "data.h"
#include "types.h"

GLOBAL_ASM(
glabel n_alSynNew
/*    30ce0:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*    30ce4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    30ce8:	afa40040 */ 	sw	$a0,0x40($sp)
/*    30cec:	8fae0040 */ 	lw	$t6,0x40($sp)
/*    30cf0:	8dcf0014 */ 	lw	$t7,0x14($t6)
/*    30cf4:	afaf002c */ 	sw	$t7,0x2c($sp)
/*    30cf8:	3c188006 */ 	lui	$t8,%hi(n_syn)
/*    30cfc:	8f18f114 */ 	lw	$t8,%lo(n_syn)($t8)
/*    30d00:	af000000 */ 	sw	$zero,0x0($t8)
/*    30d04:	8fb90040 */ 	lw	$t9,0x40($sp)
/*    30d08:	3c098006 */ 	lui	$t1,%hi(n_syn)
/*    30d0c:	8d29f114 */ 	lw	$t1,%lo(n_syn)($t1)
/*    30d10:	8f280004 */ 	lw	$t0,0x4($t9)
/*    30d14:	ad280038 */ 	sw	$t0,0x38($t1)
/*    30d18:	3c0a8006 */ 	lui	$t2,%hi(n_syn)
/*    30d1c:	8d4af114 */ 	lw	$t2,%lo(n_syn)($t2)
/*    30d20:	ad400020 */ 	sw	$zero,0x20($t2)
/*    30d24:	3c0b8006 */ 	lui	$t3,%hi(n_syn)
/*    30d28:	8d6bf114 */ 	lw	$t3,%lo(n_syn)($t3)
/*    30d2c:	ad60001c */ 	sw	$zero,0x1c($t3)
/*    30d30:	8fac0040 */ 	lw	$t4,0x40($sp)
/*    30d34:	3c0e8006 */ 	lui	$t6,%hi(n_syn)
/*    30d38:	8dcef114 */ 	lw	$t6,%lo(n_syn)($t6)
/*    30d3c:	8d8d0018 */ 	lw	$t5,0x18($t4)
/*    30d40:	adcd0040 */ 	sw	$t5,0x40($t6)
/*    30d44:	3c188006 */ 	lui	$t8,%hi(n_syn)
/*    30d48:	8f18f114 */ 	lw	$t8,%lo(n_syn)($t8)
/*    30d4c:	240f00b8 */ 	addiu	$t7,$zero,0xb8
/*    30d50:	af0f0044 */ 	sw	$t7,0x44($t8)
/*    30d54:	8fb90040 */ 	lw	$t9,0x40($sp)
/*    30d58:	3c098006 */ 	lui	$t1,%hi(n_syn)
/*    30d5c:	8d29f114 */ 	lw	$t1,%lo(n_syn)($t1)
/*    30d60:	8f280010 */ 	lw	$t0,0x10($t9)
/*    30d64:	ad280024 */ 	sw	$t0,0x24($t1)
/*    30d68:	3c0a8006 */ 	lui	$t2,%hi(n_syn)
/*    30d6c:	8d4af114 */ 	lw	$t2,%lo(n_syn)($t2)
/*    30d70:	ad400048 */ 	sw	$zero,0x48($t2)
/*    30d74:	3c0c8006 */ 	lui	$t4,%hi(n_syn)
/*    30d78:	8d8cf114 */ 	lw	$t4,%lo(n_syn)($t4)
/*    30d7c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*    30d80:	ad8b004c */ 	sw	$t3,0x4c($t4)
/*    30d84:	8fad0040 */ 	lw	$t5,0x40($sp)
/*    30d88:	8dae000c */ 	lw	$t6,0xc($t5)
/*    30d8c:	29c10003 */ 	slti	$at,$t6,0x3
/*    30d90:	14200006 */ 	bnez	$at,.L00030dac
/*    30d94:	00000000 */ 	nop
/*    30d98:	3c188006 */ 	lui	$t8,%hi(n_syn)
/*    30d9c:	8f18f114 */ 	lw	$t8,%lo(n_syn)($t8)
/*    30da0:	240f0002 */ 	addiu	$t7,$zero,0x2
/*    30da4:	1000000f */ 	b	.L00030de4
/*    30da8:	af0f003c */ 	sw	$t7,0x3c($t8)
.L00030dac:
/*    30dac:	8fb90040 */ 	lw	$t9,0x40($sp)
/*    30db0:	8f28000c */ 	lw	$t0,0xc($t9)
/*    30db4:	1d000006 */ 	bgtz	$t0,.L00030dd0
/*    30db8:	00000000 */ 	nop
/*    30dbc:	3c0a8006 */ 	lui	$t2,%hi(n_syn)
/*    30dc0:	8d4af114 */ 	lw	$t2,%lo(n_syn)($t2)
/*    30dc4:	24090001 */ 	addiu	$t1,$zero,0x1
/*    30dc8:	10000006 */ 	b	.L00030de4
/*    30dcc:	ad49003c */ 	sw	$t1,0x3c($t2)
.L00030dd0:
/*    30dd0:	8fab0040 */ 	lw	$t3,0x40($sp)
/*    30dd4:	3c0d8006 */ 	lui	$t5,%hi(n_syn)
/*    30dd8:	8dadf114 */ 	lw	$t5,%lo(n_syn)($t5)
/*    30ddc:	8d6c000c */ 	lw	$t4,0xc($t3)
/*    30de0:	adac003c */ 	sw	$t4,0x3c($t5)
.L00030de4:
/*    30de4:	3c0e8006 */ 	lui	$t6,%hi(n_syn)
/*    30de8:	8dcef114 */ 	lw	$t6,%lo(n_syn)($t6)
/*    30dec:	240f0048 */ 	addiu	$t7,$zero,0x48
/*    30df0:	00002025 */ 	or	$a0,$zero,$zero
/*    30df4:	8dc7003c */ 	lw	$a3,0x3c($t6)
/*    30df8:	afaf0010 */ 	sw	$t7,0x10($sp)
/*    30dfc:	00002825 */ 	or	$a1,$zero,$zero
/*    30e00:	0c00bec5 */ 	jal	alHeapDBAlloc
/*    30e04:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*    30e08:	3c188006 */ 	lui	$t8,%hi(n_syn)
/*    30e0c:	8f18f114 */ 	lw	$t8,%lo(n_syn)($t8)
/*    30e10:	af020034 */ 	sw	$v0,0x34($t8)
/*    30e14:	3c198006 */ 	lui	$t9,%hi(n_syn)
/*    30e18:	8f39f114 */ 	lw	$t9,%lo(n_syn)($t9)
/*    30e1c:	afa0003c */ 	sw	$zero,0x3c($sp)
/*    30e20:	8f28003c */ 	lw	$t0,0x3c($t9)
/*    30e24:	19000088 */ 	blez	$t0,.L00031048
/*    30e28:	00000000 */ 	nop
.L00030e2c:
/*    30e2c:	3c098006 */ 	lui	$t1,%hi(n_syn)
/*    30e30:	8d29f114 */ 	lw	$t1,%lo(n_syn)($t1)
/*    30e34:	8fab003c */ 	lw	$t3,0x3c($sp)
/*    30e38:	8d2a0034 */ 	lw	$t2,0x34($t1)
/*    30e3c:	000b60c0 */ 	sll	$t4,$t3,0x3
/*    30e40:	018b6021 */ 	addu	$t4,$t4,$t3
/*    30e44:	000c60c0 */ 	sll	$t4,$t4,0x3
/*    30e48:	014c6821 */ 	addu	$t5,$t2,$t4
/*    30e4c:	ada00014 */ 	sw	$zero,0x14($t5)
/*    30e50:	3c188006 */ 	lui	$t8,%hi(n_syn)
/*    30e54:	8f18f114 */ 	lw	$t8,%lo(n_syn)($t8)
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
/*    30e9c:	3c0d8006 */ 	lui	$t5,%hi(n_syn)
/*    30ea0:	8dadf114 */ 	lw	$t5,%lo(n_syn)($t5)
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
/*    30ee8:	3c0c8006 */ 	lui	$t4,%hi(n_syn)
/*    30eec:	8d8cf114 */ 	lw	$t4,%lo(n_syn)($t4)
/*    30ef0:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*    30ef4:	8d8d0034 */ 	lw	$t5,0x34($t4)
/*    30ef8:	001870c0 */ 	sll	$t6,$t8,0x3
/*    30efc:	01d87021 */ 	addu	$t6,$t6,$t8
/*    30f00:	000e70c0 */ 	sll	$t6,$t6,0x3
/*    30f04:	01ae4021 */ 	addu	$t0,$t5,$t6
/*    30f08:	1000000a */ 	b	.L00030f34
/*    30f0c:	ad020020 */ 	sw	$v0,0x20($t0)
.L00030f10:
/*    30f10:	3c198006 */ 	lui	$t9,%hi(n_syn)
/*    30f14:	8f39f114 */ 	lw	$t9,%lo(n_syn)($t9)
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
/*    30f50:	3c188006 */ 	lui	$t8,%hi(n_syn)
/*    30f54:	8f18f114 */ 	lw	$t8,%lo(n_syn)($t8)
/*    30f58:	8fae003c */ 	lw	$t6,0x3c($sp)
/*    30f5c:	8f0d0034 */ 	lw	$t5,0x34($t8)
/*    30f60:	000e40c0 */ 	sll	$t0,$t6,0x3
/*    30f64:	010e4021 */ 	addu	$t0,$t0,$t6
/*    30f68:	000840c0 */ 	sll	$t0,$t0,0x3
/*    30f6c:	01a8c821 */ 	addu	$t9,$t5,$t0
/*    30f70:	af220044 */ 	sw	$v0,0x44($t9)
/*    30f74:	3c0f8006 */ 	lui	$t7,%hi(n_syn)
/*    30f78:	8deff114 */ 	lw	$t7,%lo(n_syn)($t7)
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
/*    30fb8:	3c0d8006 */ 	lui	$t5,%hi(n_syn)
/*    30fbc:	8dadf114 */ 	lw	$t5,%lo(n_syn)($t5)
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
/*    30ffc:	3c0c8006 */ 	lui	$t4,%hi(n_syn)
/*    31000:	8d8cf114 */ 	lw	$t4,%lo(n_syn)($t4)
/*    31004:	8fae003c */ 	lw	$t6,0x3c($sp)
/*    31008:	8d980034 */ 	lw	$t8,0x34($t4)
/*    3100c:	000e68c0 */ 	sll	$t5,$t6,0x3
/*    31010:	01ae6821 */ 	addu	$t5,$t5,$t6
/*    31014:	000d68c0 */ 	sll	$t5,$t5,0x3
/*    31018:	030dc821 */ 	addu	$t9,$t8,$t5
/*    3101c:	8f280044 */ 	lw	$t0,0x44($t9)
/*    31020:	ad020030 */ 	sw	$v0,0x30($t0)
/*    31024:	8faf003c */ 	lw	$t7,0x3c($sp)
/*    31028:	3c098006 */ 	lui	$t1,%hi(n_syn)
/*    3102c:	8d29f114 */ 	lw	$t1,%lo(n_syn)($t1)
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
/*    31064:	3c0e8006 */ 	lui	$t6,%hi(n_syn)
/*    31068:	8dcef114 */ 	lw	$t6,%lo(n_syn)($t6)
/*    3106c:	adc20030 */ 	sw	$v0,0x30($t6)
/*    31070:	3c0d8006 */ 	lui	$t5,%hi(n_syn)
/*    31074:	8dadf114 */ 	lw	$t5,%lo(n_syn)($t5)
/*    31078:	3c187004 */ 	lui	$t8,%hi(func0003a100)
/*    3107c:	2718a100 */ 	addiu	$t8,$t8,%lo(func0003a100)
/*    31080:	8db90030 */ 	lw	$t9,0x30($t5)
/*    31084:	af380004 */ 	sw	$t8,0x4($t9)
/*    31088:	3c088006 */ 	lui	$t0,%hi(n_syn)
/*    3108c:	8d08f114 */ 	lw	$t0,%lo(n_syn)($t0)
/*    31090:	ad000004 */ 	sw	$zero,0x4($t0)
/*    31094:	3c0f8006 */ 	lui	$t7,%hi(n_syn)
/*    31098:	8deff114 */ 	lw	$t7,%lo(n_syn)($t7)
/*    3109c:	ade00008 */ 	sw	$zero,0x8($t7)
/*    310a0:	3c098006 */ 	lui	$t1,%hi(n_syn)
/*    310a4:	8d29f114 */ 	lw	$t1,%lo(n_syn)($t1)
/*    310a8:	ad200014 */ 	sw	$zero,0x14($t1)
/*    310ac:	3c0b8006 */ 	lui	$t3,%hi(n_syn)
/*    310b0:	8d6bf114 */ 	lw	$t3,%lo(n_syn)($t3)
/*    310b4:	ad600018 */ 	sw	$zero,0x18($t3)
/*    310b8:	3c0a8006 */ 	lui	$t2,%hi(n_syn)
/*    310bc:	8d4af114 */ 	lw	$t2,%lo(n_syn)($t2)
/*    310c0:	ad40000c */ 	sw	$zero,0xc($t2)
/*    310c4:	3c0c8006 */ 	lui	$t4,%hi(n_syn)
/*    310c8:	8d8cf114 */ 	lw	$t4,%lo(n_syn)($t4)
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
/*    31124:	3c058006 */ 	lui	$a1,%hi(n_syn)
/*    31128:	8ca5f114 */ 	lw	$a1,%lo(n_syn)($a1)
/*    3112c:	8fa40034 */ 	lw	$a0,0x34($sp)
/*    31130:	0c00c5dc */ 	jal	alLink
/*    31134:	24a50004 */ 	addiu	$a1,$a1,4
/*    31138:	8faa0034 */ 	lw	$t2,0x34($sp)
/*    3113c:	ad400008 */ 	sw	$zero,0x8($t2)
/*    31140:	3c0c8006 */ 	lui	$t4,%hi(n_syn)
/*    31144:	8d8cf114 */ 	lw	$t4,%lo(n_syn)($t4)
/*    31148:	8fa40034 */ 	lw	$a0,0x34($sp)
/*    3114c:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*    31150:	0c00f085 */ 	jal	func0003c214
/*    31154:	8d850024 */ 	lw	$a1,0x24($t4)
/*    31158:	3c0e8006 */ 	lui	$t6,%hi(n_syn)
/*    3115c:	8dcef114 */ 	lw	$t6,%lo(n_syn)($t6)
/*    31160:	afa00038 */ 	sw	$zero,0x38($sp)
/*    31164:	8dcd003c */ 	lw	$t5,0x3c($t6)
/*    31168:	19a00023 */ 	blez	$t5,.L000311f8
/*    3116c:	00000000 */ 	nop
.L00031170:
/*    31170:	3c198006 */ 	lui	$t9,%hi(n_syn)
/*    31174:	8f39f114 */ 	lw	$t9,%lo(n_syn)($t9)
/*    31178:	8faf0038 */ 	lw	$t7,0x38($sp)
/*    3117c:	8fb80034 */ 	lw	$t8,0x34($sp)
/*    31180:	8f280034 */ 	lw	$t0,0x34($t9)
/*    31184:	000f48c0 */ 	sll	$t1,$t7,0x3
/*    31188:	012f4821 */ 	addu	$t1,$t1,$t7
/*    3118c:	000948c0 */ 	sll	$t1,$t1,0x3
/*    31190:	01095821 */ 	addu	$t3,$t0,$t1
/*    31194:	8d6c0014 */ 	lw	$t4,0x14($t3)
/*    31198:	8d6a001c */ 	lw	$t2,0x1c($t3)
/*    3119c:	3c198006 */ 	lui	$t9,%hi(n_syn)
/*    311a0:	000c7080 */ 	sll	$t6,$t4,0x2
/*    311a4:	014e6821 */ 	addu	$t5,$t2,$t6
/*    311a8:	adb80000 */ 	sw	$t8,0x0($t5)
/*    311ac:	8fa80038 */ 	lw	$t0,0x38($sp)
/*    311b0:	8f39f114 */ 	lw	$t9,%lo(n_syn)($t9)
/*    311b4:	000848c0 */ 	sll	$t1,$t0,0x3
/*    311b8:	8f2f0034 */ 	lw	$t7,0x34($t9)
/*    311bc:	01284821 */ 	addu	$t1,$t1,$t0
/*    311c0:	000948c0 */ 	sll	$t1,$t1,0x3
/*    311c4:	01e95821 */ 	addu	$t3,$t7,$t1
/*    311c8:	8d6c0014 */ 	lw	$t4,0x14($t3)
/*    311cc:	258a0001 */ 	addiu	$t2,$t4,0x1
/*    311d0:	ad6a0014 */ 	sw	$t2,0x14($t3)
/*    311d4:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    311d8:	3c0d8006 */ 	lui	$t5,%hi(n_syn)
/*    311dc:	8dadf114 */ 	lw	$t5,%lo(n_syn)($t5)
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
/*    3123c:	3c0e8006 */ 	lui	$t6,%hi(n_syn)
/*    31240:	8dcef114 */ 	lw	$t6,%lo(n_syn)($t6)
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
/*    31278:	3c0c8006 */ 	lui	$t4,%hi(n_syn)
/*    3127c:	8d8cf114 */ 	lw	$t4,%lo(n_syn)($t4)
/*    31280:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    31284:	8d8a002c */ 	lw	$t2,0x2c($t4)
/*    31288:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*    3128c:	3c0d8006 */ 	lui	$t5,%hi(n_syn)
/*    31290:	8dadf114 */ 	lw	$t5,%lo(n_syn)($t5)
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
/*    312bc:	3c0c8006 */ 	lui	$t4,%hi(n_syn)
/*    312c0:	8d8cf114 */ 	lw	$t4,%lo(n_syn)($t4)
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

s32 __nextSampleTime(ALPlayer **client);
s32 _timeToSamplesNoRound(s32 micros);

Acmd *alAudioFrame(Acmd *cmdList, s32 *cmdLen, s16 *outBuf, s32 outLen)
{
	ALPlayer    *client;
	Acmd        *cmdlEnd = cmdList;
	Acmd        *cmdPtr;
	s32         nOut;
	s16         *lOutBuf = outBuf;

	if (n_syn->drvr.head == 0) {
		*cmdLen = 0;
		return cmdList;         /* nothing to do */
	}

	/*
	 * run down list of clients and execute callback if needed this
	 * subframe. Here we do all the work for the frame at the
	 * start. Time offsets that occur before the next frame are
	 * executed "early".
	 */

	/*
	 * paramSamples = time of next parameter change.
	 * curSamples = current sample time.
	 * so paramSamples - curSamples is the time until the next parameter change.
	 * if the next parameter change occurs within this frame time (outLen),
	 * then call back the client that contains the parameter change.
	 * Note, paramSamples must be rounded down to 16 sample boundary for use
	 * during the client handler.
	 */

	for (n_syn->drvr.paramSamples = __nextSampleTime(&client);
			n_syn->drvr.paramSamples - n_syn->drvr.curSamples < outLen;
			n_syn->drvr.paramSamples = __nextSampleTime(&client)) {
		n_syn->drvr.paramSamples &= ~0xf;
		client->samplesLeft += _timeToSamplesNoRound((*client->handler)(client));
	}

	/* for safety's sake, always store paramSamples aligned to 16 sample boundary.
	 * this way, if an voice handler routine gets called outside the ALVoiceHandler
	 * routine (alSynAllocVoice) it will get timestamped with an aligned value and
	 * will be processed immediately next audio frame.
	 */
	n_syn->drvr.paramSamples &= ~0xf;

	/*
	 * Now build the command list in small chunks
	 */
	while (outLen > 0) {
		nOut = MIN(n_syn->drvr.outputRate, outLen);

		cmdPtr = cmdlEnd;
		n_syn->drvr.maxOutSamples = (s32)lOutBuf;

		cmdlEnd = func0003c430(n_syn->drvr.curSamples, cmdPtr);

		outLen -= nOut;
		lOutBuf += nOut << 1;     /* For Stereo */
		n_syn->drvr.curSamples += nOut;
	}

	*cmdLen = (s32) (cmdlEnd - cmdList);

	_collectPVoices(); /* collect free physical voices */

	return cmdlEnd;
}

ALParam *__allocParam()
{
	ALParam *update = NULL;

	if (n_syn->drvr.paramList) {
		update = n_syn->drvr.paramList;
		n_syn->drvr.paramList = n_syn->drvr.paramList->next;
		update->next = 0;
	}

	return update;
}

void __freeParam(ALParam *param)
{
    param->next = n_syn->drvr.paramList;
    n_syn->drvr.paramList = param;
}

void _collectPVoices(void)
{
	ALLink *dl;

	while ((dl = n_syn->drvr.pLameList.next) != 0) {
		alUnlink(dl);
		alLink(dl, &n_syn->drvr.pFreeList);
	}
}

void _freePVoice(PVoice *pvoice)
{
	/*
	 * move the voice from the allocated list to the lame list
	 */
	alUnlink((ALLink *)pvoice);
	alLink((ALLink *)pvoice, &n_syn->drvr.pLameList);
}

s32 _timeToSamplesNoRound(s32 micros)
{
	// Should be outputRate but struct is not sized correctly
	f32 tmp = ((f32)micros) * n_syn->drvr.maxAuxBusses / 1000000.0f + 0.5f;

	return (s32)tmp;
}

GLOBAL_ASM(
glabel _timeToSamples
/*    31698:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*    3169c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    316a0:	afa40018 */ 	sw	$a0,0x18($sp)
/*    316a4:	0c00c58d */ 	jal	_timeToSamplesNoRound
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

s32 __nextSampleTime(ALPlayer **client)
{
	ALMicroTime delta = 0x7fffffff;     /* max delta for s32 */
	ALPlayer *cl;

	*client = 0;

	for (cl = n_syn->drvr.head; cl != 0; cl = cl->next) {
		if ((cl->samplesLeft - n_syn->drvr.curSamples) < delta) {
			*client = cl;
			delta = cl->samplesLeft - n_syn->drvr.curSamples;
		}
	}

	return (*client)->samplesLeft;
}

void alLink(ALLink *ln, ALLink *to)
{
	ln->next = to->next;
	ln->prev = to;

	if (to->next) {
		to->next->prev = ln;
	}

	to->next = ln;
}

void alUnlink(ALLink *ln)
{
	if (ln->next) {
		ln->next->prev = ln->prev;
	}

	if (ln->prev) {
		ln->prev->next = ln->next;
	}
}
