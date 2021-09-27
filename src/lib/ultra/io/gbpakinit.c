#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

u32 var80090ab0;
u32 var80090ab4;
u32 var80090ab8;
u32 var80090abc;
u32 var80090ac0;
u32 var80090ac4;
u32 var80090ac8;
u32 var80090acc;
u32 var80090ad0;
u32 var80090ad4;
u32 var80090ad8;
u32 var80090adc;
u32 var80090ae0;
u32 var80090ae4;
u32 var80090ae8;
u32 var80090aec;

GLOBAL_ASM(
glabel osGbpakInit
/*     6100:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*     6104:	afa40058 */ 	sw	$a0,0x58($sp)
/*     6108:	afbf0024 */ 	sw	$ra,0x24($sp)
/*     610c:	afa5005c */ 	sw	$a1,0x5c($sp)
/*     6110:	afa60060 */ 	sw	$a2,0x60($sp)
/*     6114:	aca00000 */ 	sw	$zero,0x0($a1)
/*     6118:	27a40050 */ 	addiu	$a0,$sp,0x50
/*     611c:	27a20030 */ 	addiu	$v0,$sp,0x30
/*     6120:	240300fe */ 	addiu	$v1,$zero,0xfe
.L00006124:
/*     6124:	24420001 */ 	addiu	$v0,$v0,0x1
/*     6128:	0044082b */ 	sltu	$at,$v0,$a0
/*     612c:	1420fffd */ 	bnez	$at,.L00006124
/*     6130:	a043ffff */ 	sb	$v1,-0x1($v0)
/*     6134:	8fa40058 */ 	lw	$a0,0x58($sp)
/*     6138:	8fa50060 */ 	lw	$a1,0x60($sp)
/*     613c:	24060400 */ 	addiu	$a2,$zero,0x400
/*     6140:	27a70030 */ 	addiu	$a3,$sp,0x30
/*     6144:	0c012d84 */ 	jal	__osContRamWrite
/*     6148:	afa00010 */ 	sw	$zero,0x10($sp)
/*     614c:	24010002 */ 	addiu	$at,$zero,0x2
/*     6150:	14410008 */ 	bne	$v0,$at,.L00006174
/*     6154:	00401825 */ 	or	$v1,$v0,$zero
/*     6158:	8fa40058 */ 	lw	$a0,0x58($sp)
/*     615c:	8fa50060 */ 	lw	$a1,0x60($sp)
/*     6160:	24060400 */ 	addiu	$a2,$zero,0x400
/*     6164:	27a70030 */ 	addiu	$a3,$sp,0x30
/*     6168:	0c012d84 */ 	jal	__osContRamWrite
/*     616c:	afa00010 */ 	sw	$zero,0x10($sp)
/*     6170:	00401825 */ 	or	$v1,$v0,$zero
.L00006174:
/*     6174:	10400003 */ 	beqz	$v0,.L00006184
/*     6178:	8fa40058 */ 	lw	$a0,0x58($sp)
/*     617c:	10000065 */ 	b	.L00006314
/*     6180:	00601025 */ 	or	$v0,$v1,$zero
.L00006184:
/*     6184:	8fa50060 */ 	lw	$a1,0x60($sp)
/*     6188:	24060400 */ 	addiu	$a2,$zero,0x400
/*     618c:	0c012e18 */ 	jal	__osContRamRead
/*     6190:	27a70030 */ 	addiu	$a3,$sp,0x30
/*     6194:	24010002 */ 	addiu	$at,$zero,0x2
/*     6198:	14410002 */ 	bne	$v0,$at,.L000061a4
/*     619c:	00401825 */ 	or	$v1,$v0,$zero
/*     61a0:	24030004 */ 	addiu	$v1,$zero,0x4
.L000061a4:
/*     61a4:	10600003 */ 	beqz	$v1,.L000061b4
/*     61a8:	93af004f */ 	lbu	$t7,0x4f($sp)
/*     61ac:	10000059 */ 	b	.L00006314
/*     61b0:	00601025 */ 	or	$v0,$v1,$zero
.L000061b4:
/*     61b4:	240100fe */ 	addiu	$at,$zero,0xfe
/*     61b8:	15e10003 */ 	bne	$t7,$at,.L000061c8
/*     61bc:	27a20030 */ 	addiu	$v0,$sp,0x30
/*     61c0:	10000054 */ 	b	.L00006314
/*     61c4:	2402000b */ 	addiu	$v0,$zero,0xb
.L000061c8:
/*     61c8:	24080084 */ 	addiu	$t0,$zero,0x84
/*     61cc:	27a30050 */ 	addiu	$v1,$sp,0x50
.L000061d0:
/*     61d0:	24420001 */ 	addiu	$v0,$v0,0x1
/*     61d4:	1443fffe */ 	bne	$v0,$v1,.L000061d0
/*     61d8:	a048ffff */ 	sb	$t0,-0x1($v0)
/*     61dc:	8fa40058 */ 	lw	$a0,0x58($sp)
/*     61e0:	8fa50060 */ 	lw	$a1,0x60($sp)
/*     61e4:	24060400 */ 	addiu	$a2,$zero,0x400
/*     61e8:	27a70030 */ 	addiu	$a3,$sp,0x30
/*     61ec:	0c012d84 */ 	jal	__osContRamWrite
/*     61f0:	afa00010 */ 	sw	$zero,0x10($sp)
/*     61f4:	24010002 */ 	addiu	$at,$zero,0x2
/*     61f8:	14410002 */ 	bne	$v0,$at,.L00006204
/*     61fc:	00401825 */ 	or	$v1,$v0,$zero
/*     6200:	24030004 */ 	addiu	$v1,$zero,0x4
.L00006204:
/*     6204:	10600003 */ 	beqz	$v1,.L00006214
/*     6208:	8fa40058 */ 	lw	$a0,0x58($sp)
/*     620c:	10000041 */ 	b	.L00006314
/*     6210:	00601025 */ 	or	$v0,$v1,$zero
.L00006214:
/*     6214:	8fa50060 */ 	lw	$a1,0x60($sp)
/*     6218:	24060400 */ 	addiu	$a2,$zero,0x400
/*     621c:	0c012e18 */ 	jal	__osContRamRead
/*     6220:	27a70030 */ 	addiu	$a3,$sp,0x30
/*     6224:	24010002 */ 	addiu	$at,$zero,0x2
/*     6228:	14410002 */ 	bne	$v0,$at,.L00006234
/*     622c:	00401825 */ 	or	$v1,$v0,$zero
/*     6230:	24030004 */ 	addiu	$v1,$zero,0x4
.L00006234:
/*     6234:	10600003 */ 	beqz	$v1,.L00006244
/*     6238:	93b8004f */ 	lbu	$t8,0x4f($sp)
/*     623c:	10000035 */ 	b	.L00006314
/*     6240:	00601025 */ 	or	$v0,$v1,$zero
.L00006244:
/*     6244:	24010084 */ 	addiu	$at,$zero,0x84
/*     6248:	13010003 */ 	beq	$t8,$at,.L00006258
/*     624c:	8fa40058 */ 	lw	$a0,0x58($sp)
/*     6250:	10000030 */ 	b	.L00006314
/*     6254:	2402000b */ 	addiu	$v0,$zero,0xb
.L00006258:
/*     6258:	0c012ea4 */ 	jal	__osPfsGetStatus
/*     625c:	8fa50060 */ 	lw	$a1,0x60($sp)
/*     6260:	10400003 */ 	beqz	$v0,.L00006270
/*     6264:	3c048009 */ 	lui	$a0,%hi(var80090ad0)
/*     6268:	1000002b */ 	b	.L00006318
/*     626c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L00006270:
/*     6270:	3c058009 */ 	lui	$a1,%hi(var80090ae8)
/*     6274:	24a50ae8 */ 	addiu	$a1,$a1,%lo(var80090ae8)
/*     6278:	24840ad0 */ 	addiu	$a0,$a0,%lo(var80090ad0)
/*     627c:	0c0120d0 */ 	jal	osCreateMesgQueue
/*     6280:	24060001 */ 	addiu	$a2,$zero,0x1
/*     6284:	3c198009 */ 	lui	$t9,%hi(var80090ad0)
/*     6288:	3c098009 */ 	lui	$t1,%hi(var80090ae8)
/*     628c:	25290ae8 */ 	addiu	$t1,$t1,%lo(var80090ae8)
/*     6290:	27390ad0 */ 	addiu	$t9,$t9,%lo(var80090ad0)
/*     6294:	3c048009 */ 	lui	$a0,%hi(var80090ab0)
/*     6298:	3c07000e */ 	lui	$a3,0xe
/*     629c:	240a0000 */ 	addiu	$t2,$zero,0x0
/*     62a0:	240b0000 */ 	addiu	$t3,$zero,0x0
/*     62a4:	afab0014 */ 	sw	$t3,0x14($sp)
/*     62a8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*     62ac:	34e74e1c */ 	ori	$a3,$a3,0x4e1c
/*     62b0:	24840ab0 */ 	addiu	$a0,$a0,%lo(var80090ab0)
/*     62b4:	afb90018 */ 	sw	$t9,0x18($sp)
/*     62b8:	afa9001c */ 	sw	$t1,0x1c($sp)
/*     62bc:	0c0122c8 */ 	jal	osSetTimer
/*     62c0:	24060000 */ 	addiu	$a2,$zero,0x0
/*     62c4:	3c048009 */ 	lui	$a0,%hi(var80090ad0)
/*     62c8:	24840ad0 */ 	addiu	$a0,$a0,%lo(var80090ad0)
/*     62cc:	00002825 */ 	or	$a1,$zero,$zero
/*     62d0:	0c0121bc */ 	jal	osRecvMesg
/*     62d4:	24060001 */ 	addiu	$a2,$zero,0x1
/*     62d8:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*     62dc:	8fac0058 */ 	lw	$t4,0x58($sp)
/*     62e0:	240d0010 */ 	addiu	$t5,$zero,0x10
/*     62e4:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*     62e8:	ac8c0004 */ 	sw	$t4,0x4($a0)
/*     62ec:	8fae0060 */ 	lw	$t6,0x60($sp)
/*     62f0:	240300ff */ 	addiu	$v1,$zero,0xff
/*     62f4:	24080084 */ 	addiu	$t0,$zero,0x84
/*     62f8:	240f00ff */ 	addiu	$t7,$zero,0xff
/*     62fc:	00001025 */ 	or	$v0,$zero,$zero
/*     6300:	a0880065 */ 	sb	$t0,0x65($a0)
/*     6304:	a08f0064 */ 	sb	$t7,0x64($a0)
/*     6308:	ac83004c */ 	sw	$v1,0x4c($a0)
/*     630c:	ac830050 */ 	sw	$v1,0x50($a0)
/*     6310:	ac8e0008 */ 	sw	$t6,0x8($a0)
.L00006314:
/*     6314:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L00006318:
/*     6318:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*     631c:	03e00008 */ 	jr	$ra
/*     6320:	00000000 */ 	nop
);
