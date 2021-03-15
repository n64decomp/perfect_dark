#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_4b170.h"
#include "lib/lib_4c090.h"
#include "lib/lib_4d6f0.h"
#include "data.h"
#include "types.h"

u32 var8009c870;
u32 var8009c874;
u32 var8009c878;
u32 var8009c87c;
u32 var8009c880;
u32 var8009c884;
u32 var8009c888;
u32 var8009c88c;
u32 var8009c890;
u32 var8009c894;
u32 var8009c898;
u32 var8009c89c;
u32 var8009c8a0;
u32 var8009c8a4;
u32 var8009c8a8;
u32 var8009c8ac;
u32 var8009c8b0;
u32 var8009c8b4;
u32 var8009c8b8;
u32 var8009c8bc;
u32 var8009c8c0;
u32 var8009c8c4;
u32 var8009c8c8;
u32 var8009c8cc;
u32 var8009c8d0;
u32 var8009c8d4;
u32 var8009c8d8;
u32 var8009c8dc;
u32 var8009c8e0;
u32 var8009c8e4;
u32 var8009c8e8;
u32 var8009c8ec;
u32 var8009c8f0;
u32 var8009c8f4;
u32 var8009c8f8;
u32 var8009c8fc;
u32 var8009c900;
u32 var8009c904;
u32 var8009c908;
u32 var8009c90c;
u32 var8009c910;
u32 var8009c914;
u32 var8009c918;
u32 var8009c91c;
u32 var8009c920;
u32 var8009c924;
u32 var8009c928;
u32 var8009c92c;
u32 var8009c930;
u32 var8009c934;
u32 var8009c938;
u32 var8009c93c;
u32 var8009c940;
u32 var8009c944;
u32 var8009c948;
u32 var8009c94c;
u32 var8009c950;
u32 var8009c954;
u32 var8009c958;
u32 var8009c95c;
u32 var8009c960;
u32 var8009c964;
u32 var8009c968;
u32 var8009c96c;

GLOBAL_ASM(
glabel func0004c090
/*    4c090:	00001825 */ 	or	$v1,$zero,$zero
/*    4c094:	00801025 */ 	or	$v0,$a0,$zero
/*    4c098:	18a00016 */ 	blez	$a1,.L0004c0f4
/*    4c09c:	00003025 */ 	or	$a2,$zero,$zero
/*    4c0a0:	30a70003 */ 	andi	$a3,$a1,0x3
/*    4c0a4:	10e00008 */ 	beqz	$a3,.L0004c0c8
/*    4c0a8:	00e02025 */ 	or	$a0,$a3,$zero
.L0004c0ac:
/*    4c0ac:	904e0000 */ 	lbu	$t6,0x0($v0)
/*    4c0b0:	24c60001 */ 	addiu	$a2,$a2,0x1
/*    4c0b4:	24420001 */ 	addiu	$v0,$v0,0x1
/*    4c0b8:	1486fffc */ 	bne	$a0,$a2,.L0004c0ac
/*    4c0bc:	006e1821 */ 	addu	$v1,$v1,$t6
/*    4c0c0:	50c5000d */ 	beql	$a2,$a1,.L0004c0f8
/*    4c0c4:	00601025 */ 	or	$v0,$v1,$zero
.L0004c0c8:
/*    4c0c8:	904f0000 */ 	lbu	$t7,0x0($v0)
/*    4c0cc:	90580001 */ 	lbu	$t8,0x1($v0)
/*    4c0d0:	90590002 */ 	lbu	$t9,0x2($v0)
/*    4c0d4:	006f1821 */ 	addu	$v1,$v1,$t7
/*    4c0d8:	90480003 */ 	lbu	$t0,0x3($v0)
/*    4c0dc:	00781821 */ 	addu	$v1,$v1,$t8
/*    4c0e0:	24c60004 */ 	addiu	$a2,$a2,0x4
/*    4c0e4:	00791821 */ 	addu	$v1,$v1,$t9
/*    4c0e8:	24420004 */ 	addiu	$v0,$v0,0x4
/*    4c0ec:	14c5fff6 */ 	bne	$a2,$a1,.L0004c0c8
/*    4c0f0:	00681821 */ 	addu	$v1,$v1,$t0
.L0004c0f4:
/*    4c0f4:	00601025 */ 	or	$v0,$v1,$zero
.L0004c0f8:
/*    4c0f8:	3049ffff */ 	andi	$t1,$v0,0xffff
/*    4c0fc:	03e00008 */ 	jr	$ra
/*    4c100:	01201025 */ 	or	$v0,$t1,$zero
);

GLOBAL_ASM(
glabel func0004c104
/*    4c104:	a4c00000 */ 	sh	$zero,0x0($a2)
/*    4c108:	a4a00000 */ 	sh	$zero,0x0($a1)
/*    4c10c:	94820000 */ 	lhu	$v0,0x0($a0)
/*    4c110:	24870004 */ 	addiu	$a3,$a0,0x4
/*    4c114:	24e90002 */ 	addiu	$t1,$a3,0x2
/*    4c118:	0002c021 */ 	addu	$t8,$zero,$v0
/*    4c11c:	a4b80000 */ 	sh	$t8,0x0($a1)
/*    4c120:	94d90000 */ 	lhu	$t9,0x0($a2)
/*    4c124:	00406827 */ 	nor	$t5,$v0,$zero
/*    4c128:	24ea0004 */ 	addiu	$t2,$a3,0x4
/*    4c12c:	032d7021 */ 	addu	$t6,$t9,$t5
/*    4c130:	a4ce0000 */ 	sh	$t6,0x0($a2)
/*    4c134:	94af0000 */ 	lhu	$t7,0x0($a1)
/*    4c138:	94820002 */ 	lhu	$v0,0x2($a0)
/*    4c13c:	2404001c */ 	addiu	$a0,$zero,0x1c
/*    4c140:	24eb0006 */ 	addiu	$t3,$a3,0x6
/*    4c144:	01e2c021 */ 	addu	$t8,$t7,$v0
/*    4c148:	a4b80000 */ 	sh	$t8,0x0($a1)
/*    4c14c:	94d90000 */ 	lhu	$t9,0x0($a2)
/*    4c150:	00406827 */ 	nor	$t5,$v0,$zero
/*    4c154:	24030004 */ 	addiu	$v1,$zero,0x4
/*    4c158:	032d7021 */ 	addu	$t6,$t9,$t5
/*    4c15c:	a4ce0000 */ 	sh	$t6,0x0($a2)
.L0004c160:
/*    4c160:	94e20000 */ 	lhu	$v0,0x0($a3)
/*    4c164:	94af0000 */ 	lhu	$t7,0x0($a1)
/*    4c168:	24630008 */ 	addiu	$v1,$v1,0x8
/*    4c16c:	00406827 */ 	nor	$t5,$v0,$zero
/*    4c170:	01e2c021 */ 	addu	$t8,$t7,$v0
/*    4c174:	a4b80000 */ 	sh	$t8,0x0($a1)
/*    4c178:	94d90000 */ 	lhu	$t9,0x0($a2)
/*    4c17c:	24e70008 */ 	addiu	$a3,$a3,0x8
/*    4c180:	25290008 */ 	addiu	$t1,$t1,0x8
/*    4c184:	032d7021 */ 	addu	$t6,$t9,$t5
/*    4c188:	a4ce0000 */ 	sh	$t6,0x0($a2)
/*    4c18c:	94af0000 */ 	lhu	$t7,0x0($a1)
/*    4c190:	9522fff8 */ 	lhu	$v0,-0x8($t1)
/*    4c194:	254a0008 */ 	addiu	$t2,$t2,0x8
/*    4c198:	256b0008 */ 	addiu	$t3,$t3,0x8
/*    4c19c:	01e2c021 */ 	addu	$t8,$t7,$v0
/*    4c1a0:	a4b80000 */ 	sh	$t8,0x0($a1)
/*    4c1a4:	94d90000 */ 	lhu	$t9,0x0($a2)
/*    4c1a8:	00406827 */ 	nor	$t5,$v0,$zero
/*    4c1ac:	032d7021 */ 	addu	$t6,$t9,$t5
/*    4c1b0:	a4ce0000 */ 	sh	$t6,0x0($a2)
/*    4c1b4:	94af0000 */ 	lhu	$t7,0x0($a1)
/*    4c1b8:	9542fff8 */ 	lhu	$v0,-0x8($t2)
/*    4c1bc:	01e2c021 */ 	addu	$t8,$t7,$v0
/*    4c1c0:	a4b80000 */ 	sh	$t8,0x0($a1)
/*    4c1c4:	94d90000 */ 	lhu	$t9,0x0($a2)
/*    4c1c8:	00406827 */ 	nor	$t5,$v0,$zero
/*    4c1cc:	032d7021 */ 	addu	$t6,$t9,$t5
/*    4c1d0:	a4ce0000 */ 	sh	$t6,0x0($a2)
/*    4c1d4:	94af0000 */ 	lhu	$t7,0x0($a1)
/*    4c1d8:	9562fff8 */ 	lhu	$v0,-0x8($t3)
/*    4c1dc:	01e2c021 */ 	addu	$t8,$t7,$v0
/*    4c1e0:	a4b80000 */ 	sh	$t8,0x0($a1)
/*    4c1e4:	94d90000 */ 	lhu	$t9,0x0($a2)
/*    4c1e8:	00406827 */ 	nor	$t5,$v0,$zero
/*    4c1ec:	032d7021 */ 	addu	$t6,$t9,$t5
/*    4c1f0:	1464ffdb */ 	bne	$v1,$a0,.L0004c160
/*    4c1f4:	a4ce0000 */ 	sh	$t6,0x0($a2)
/*    4c1f8:	03e00008 */ 	jr	$ra
/*    4c1fc:	00001025 */ 	or	$v0,$zero,$zero
);

GLOBAL_ASM(
glabel func0004c200
/*    4c200:	27bdff60 */ 	addiu	$sp,$sp,-160
/*    4c204:	afbf003c */ 	sw	$ra,0x3c($sp)
/*    4c208:	afb60038 */ 	sw	$s6,0x38($sp)
/*    4c20c:	afb50034 */ 	sw	$s5,0x34($sp)
/*    4c210:	afb40030 */ 	sw	$s4,0x30($sp)
/*    4c214:	afb3002c */ 	sw	$s3,0x2c($sp)
/*    4c218:	afb20028 */ 	sw	$s2,0x28($sp)
/*    4c21c:	afb10024 */ 	sw	$s1,0x24($sp)
/*    4c220:	afb00020 */ 	sw	$s0,0x20($sp)
/*    4c224:	240effff */ 	addiu	$t6,$zero,-1
/*    4c228:	00809025 */ 	or	$s2,$a0,$zero
/*    4c22c:	00c0a025 */ 	or	$s4,$a2,$zero
/*    4c230:	00a0b025 */ 	or	$s6,$a1,$zero
/*    4c234:	00009825 */ 	or	$s3,$zero,$zero
/*    4c238:	0c012144 */ 	jal	osGetCount
/*    4c23c:	acce0000 */ 	sw	$t6,0x0($a2)
/*    4c240:	ae820004 */ 	sw	$v0,0x4($s4)
/*    4c244:	8ed9000c */ 	lw	$t9,0xc($s6)
/*    4c248:	8ed80008 */ 	lw	$t8,0x8($s6)
/*    4c24c:	02402025 */ 	or	$a0,$s2,$zero
/*    4c250:	ae99000c */ 	sw	$t9,0xc($s4)
/*    4c254:	ae980008 */ 	sw	$t8,0x8($s4)
/*    4c258:	8ec90014 */ 	lw	$t1,0x14($s6)
/*    4c25c:	8ec80010 */ 	lw	$t0,0x10($s6)
/*    4c260:	ae890014 */ 	sw	$t1,0x14($s4)
/*    4c264:	ae880010 */ 	sw	$t0,0x10($s4)
/*    4c268:	924f0065 */ 	lbu	$t7,0x65($s2)
/*    4c26c:	51e00008 */ 	beqzl	$t7,.L0004c290
/*    4c270:	27b1007c */ 	addiu	$s1,$sp,0x7c
/*    4c274:	0c013378 */ 	jal	__osPfsSelectBank
/*    4c278:	00002825 */ 	or	$a1,$zero,$zero
/*    4c27c:	50400004 */ 	beqzl	$v0,.L0004c290
/*    4c280:	27b1007c */ 	addiu	$s1,$sp,0x7c
/*    4c284:	100000a9 */ 	b	.L0004c52c
/*    4c288:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*    4c28c:	27b1007c */ 	addiu	$s1,$sp,0x7c
.L0004c290:
/*    4c290:	0220a825 */ 	or	$s5,$s1,$zero
/*    4c294:	27b0009c */ 	addiu	$s0,$sp,0x9c
/*    4c298:	02402025 */ 	or	$a0,$s2,$zero
.L0004c29c:
/*    4c29c:	0c013378 */ 	jal	__osPfsSelectBank
/*    4c2a0:	326500ff */ 	andi	$a1,$s3,0xff
/*    4c2a4:	10400003 */ 	beqz	$v0,.L0004c2b4
/*    4c2a8:	00003025 */ 	or	$a2,$zero,$zero
/*    4c2ac:	1000009f */ 	b	.L0004c52c
/*    4c2b0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c2b4:
/*    4c2b4:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4c2b8:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4c2bc:	0c012e18 */ 	jal	__osContRamRead
/*    4c2c0:	02a03825 */ 	or	$a3,$s5,$zero
/*    4c2c4:	10400003 */ 	beqz	$v0,.L0004c2d4
/*    4c2c8:	366b0080 */ 	ori	$t3,$s3,0x80
/*    4c2cc:	10000097 */ 	b	.L0004c52c
/*    4c2d0:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c2d4:
/*    4c2d4:	a3ab007c */ 	sb	$t3,0x7c($sp)
/*    4c2d8:	27a2007d */ 	addiu	$v0,$sp,0x7d
.L0004c2dc:
/*    4c2dc:	904c0000 */ 	lbu	$t4,0x0($v0)
/*    4c2e0:	24420001 */ 	addiu	$v0,$v0,0x1
/*    4c2e4:	0050082b */ 	sltu	$at,$v0,$s0
/*    4c2e8:	01806827 */ 	nor	$t5,$t4,$zero
/*    4c2ec:	1420fffb */ 	bnez	$at,.L0004c2dc
/*    4c2f0:	a04dffff */ 	sb	$t5,-0x1($v0)
/*    4c2f4:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4c2f8:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4c2fc:	afa00010 */ 	sw	$zero,0x10($sp)
/*    4c300:	00003025 */ 	or	$a2,$zero,$zero
/*    4c304:	0c012d84 */ 	jal	__osContRamWrite
/*    4c308:	02a03825 */ 	or	$a3,$s5,$zero
/*    4c30c:	10400003 */ 	beqz	$v0,.L0004c31c
/*    4c310:	00003025 */ 	or	$a2,$zero,$zero
/*    4c314:	10000085 */ 	b	.L0004c52c
/*    4c318:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c31c:
/*    4c31c:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4c320:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4c324:	0c012e18 */ 	jal	__osContRamRead
/*    4c328:	27a7005c */ 	addiu	$a3,$sp,0x5c
/*    4c32c:	10400003 */ 	beqz	$v0,.L0004c33c
/*    4c330:	27a3005c */ 	addiu	$v1,$sp,0x5c
/*    4c334:	1000007d */ 	b	.L0004c52c
/*    4c338:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c33c:
/*    4c33c:	27a2007c */ 	addiu	$v0,$sp,0x7c
.L0004c340:
/*    4c340:	906e0000 */ 	lbu	$t6,0x0($v1)
/*    4c344:	90580000 */ 	lbu	$t8,0x0($v0)
/*    4c348:	55d80006 */ 	bnel	$t6,$t8,.L0004c364
/*    4c34c:	27b9007c */ 	addiu	$t9,$sp,0x7c
/*    4c350:	24630001 */ 	addiu	$v1,$v1,0x1
/*    4c354:	0071082b */ 	sltu	$at,$v1,$s1
/*    4c358:	1420fff9 */ 	bnez	$at,.L0004c340
/*    4c35c:	24420001 */ 	addiu	$v0,$v0,0x1
/*    4c360:	27b9007c */ 	addiu	$t9,$sp,0x7c
.L0004c364:
/*    4c364:	14790018 */ 	bne	$v1,$t9,.L0004c3c8
/*    4c368:	02402025 */ 	or	$a0,$s2,$zero
/*    4c36c:	5a600013 */ 	blezl	$s3,.L0004c3bc
/*    4c370:	26730001 */ 	addiu	$s3,$s3,0x1
/*    4c374:	0c013378 */ 	jal	__osPfsSelectBank
/*    4c378:	00002825 */ 	or	$a1,$zero,$zero
/*    4c37c:	10400003 */ 	beqz	$v0,.L0004c38c
/*    4c380:	00003025 */ 	or	$a2,$zero,$zero
/*    4c384:	10000069 */ 	b	.L0004c52c
/*    4c388:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c38c:
/*    4c38c:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4c390:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4c394:	0c012e18 */ 	jal	__osContRamRead
/*    4c398:	02a03825 */ 	or	$a3,$s5,$zero
/*    4c39c:	10400003 */ 	beqz	$v0,.L0004c3ac
/*    4c3a0:	93a8007c */ 	lbu	$t0,0x7c($sp)
/*    4c3a4:	10000061 */ 	b	.L0004c52c
/*    4c3a8:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c3ac:
/*    4c3ac:	24010080 */ 	addiu	$at,$zero,0x80
/*    4c3b0:	55010006 */ 	bnel	$t0,$at,.L0004c3cc
/*    4c3b4:	92490065 */ 	lbu	$t1,0x65($s2)
/*    4c3b8:	26730001 */ 	addiu	$s3,$s3,0x1
.L0004c3bc:
/*    4c3bc:	2a61003e */ 	slti	$at,$s3,0x3e
/*    4c3c0:	5420ffb6 */ 	bnezl	$at,.L0004c29c
/*    4c3c4:	02402025 */ 	or	$a0,$s2,$zero
.L0004c3c8:
/*    4c3c8:	92490065 */ 	lbu	$t1,0x65($s2)
.L0004c3cc:
/*    4c3cc:	02402025 */ 	or	$a0,$s2,$zero
/*    4c3d0:	11200007 */ 	beqz	$t1,.L0004c3f0
/*    4c3d4:	00000000 */ 	nop
/*    4c3d8:	0c013378 */ 	jal	__osPfsSelectBank
/*    4c3dc:	00002825 */ 	or	$a1,$zero,$zero
/*    4c3e0:	10400003 */ 	beqz	$v0,.L0004c3f0
/*    4c3e4:	00000000 */ 	nop
/*    4c3e8:	10000050 */ 	b	.L0004c52c
/*    4c3ec:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c3f0:
/*    4c3f0:	1a600003 */ 	blez	$s3,.L0004c400
/*    4c3f4:	02802025 */ 	or	$a0,$s4,$zero
/*    4c3f8:	10000002 */ 	b	.L0004c404
/*    4c3fc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0004c400:
/*    4c400:	00001025 */ 	or	$v0,$zero,$zero
.L0004c404:
/*    4c404:	96cf0018 */ 	lhu	$t7,0x18($s6)
/*    4c408:	a293001a */ 	sb	$s3,0x1a($s4)
/*    4c40c:	2685001c */ 	addiu	$a1,$s4,0x1c
/*    4c410:	31eafffe */ 	andi	$t2,$t7,0xfffe
/*    4c414:	01425825 */ 	or	$t3,$t2,$v0
/*    4c418:	a68b0018 */ 	sh	$t3,0x18($s4)
/*    4c41c:	92cc001b */ 	lbu	$t4,0x1b($s6)
/*    4c420:	2686001e */ 	addiu	$a2,$s4,0x1e
/*    4c424:	0c013041 */ 	jal	func0004c104
/*    4c428:	a28c001b */ 	sb	$t4,0x1b($s4)
/*    4c42c:	240d0001 */ 	addiu	$t5,$zero,0x1
/*    4c430:	240e0003 */ 	addiu	$t6,$zero,0x3
/*    4c434:	24180004 */ 	addiu	$t8,$zero,0x4
/*    4c438:	24190006 */ 	addiu	$t9,$zero,0x6
/*    4c43c:	a7ad0048 */ 	sh	$t5,0x48($sp)
/*    4c440:	a7ae004a */ 	sh	$t6,0x4a($sp)
/*    4c444:	a7b8004c */ 	sh	$t8,0x4c($sp)
/*    4c448:	a7b9004e */ 	sh	$t9,0x4e($sp)
/*    4c44c:	27b00048 */ 	addiu	$s0,$sp,0x48
/*    4c450:	27b10050 */ 	addiu	$s1,$sp,0x50
/*    4c454:	8e440004 */ 	lw	$a0,0x4($s2)
.L0004c458:
/*    4c458:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4c45c:	96060000 */ 	lhu	$a2,0x0($s0)
/*    4c460:	24080001 */ 	addiu	$t0,$zero,0x1
/*    4c464:	afa80010 */ 	sw	$t0,0x10($sp)
/*    4c468:	0c012d84 */ 	jal	__osContRamWrite
/*    4c46c:	02803825 */ 	or	$a3,$s4,$zero
/*    4c470:	10400003 */ 	beqz	$v0,.L0004c480
/*    4c474:	26100002 */ 	addiu	$s0,$s0,0x2
/*    4c478:	1000002c */ 	b	.L0004c52c
/*    4c47c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c480:
/*    4c480:	0211082b */ 	sltu	$at,$s0,$s1
/*    4c484:	5420fff4 */ 	bnezl	$at,.L0004c458
/*    4c488:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4c48c:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4c490:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4c494:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4c498:	0c012e18 */ 	jal	__osContRamRead
/*    4c49c:	02a03825 */ 	or	$a3,$s5,$zero
/*    4c4a0:	10400003 */ 	beqz	$v0,.L0004c4b0
/*    4c4a4:	02801825 */ 	or	$v1,$s4,$zero
/*    4c4a8:	10000020 */ 	b	.L0004c52c
/*    4c4ac:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c4b0:
/*    4c4b0:	27a2007c */ 	addiu	$v0,$sp,0x7c
/*    4c4b4:	27a4009c */ 	addiu	$a0,$sp,0x9c
.L0004c4b8:
/*    4c4b8:	90490000 */ 	lbu	$t1,0x0($v0)
/*    4c4bc:	906f0000 */ 	lbu	$t7,0x0($v1)
/*    4c4c0:	512f0004 */ 	beql	$t1,$t7,.L0004c4d4
/*    4c4c4:	904a0001 */ 	lbu	$t2,0x1($v0)
/*    4c4c8:	10000017 */ 	b	.L0004c528
/*    4c4cc:	2402000b */ 	addiu	$v0,$zero,0xb
/*    4c4d0:	904a0001 */ 	lbu	$t2,0x1($v0)
.L0004c4d4:
/*    4c4d4:	906b0001 */ 	lbu	$t3,0x1($v1)
/*    4c4d8:	514b0004 */ 	beql	$t2,$t3,.L0004c4ec
/*    4c4dc:	904c0002 */ 	lbu	$t4,0x2($v0)
/*    4c4e0:	10000011 */ 	b	.L0004c528
/*    4c4e4:	2402000b */ 	addiu	$v0,$zero,0xb
/*    4c4e8:	904c0002 */ 	lbu	$t4,0x2($v0)
.L0004c4ec:
/*    4c4ec:	906d0002 */ 	lbu	$t5,0x2($v1)
/*    4c4f0:	518d0004 */ 	beql	$t4,$t5,.L0004c504
/*    4c4f4:	904e0003 */ 	lbu	$t6,0x3($v0)
/*    4c4f8:	1000000b */ 	b	.L0004c528
/*    4c4fc:	2402000b */ 	addiu	$v0,$zero,0xb
/*    4c500:	904e0003 */ 	lbu	$t6,0x3($v0)
.L0004c504:
/*    4c504:	90780003 */ 	lbu	$t8,0x3($v1)
/*    4c508:	24420004 */ 	addiu	$v0,$v0,0x4
/*    4c50c:	11d80003 */ 	beq	$t6,$t8,.L0004c51c
/*    4c510:	00000000 */ 	nop
/*    4c514:	10000004 */ 	b	.L0004c528
/*    4c518:	2402000b */ 	addiu	$v0,$zero,0xb
.L0004c51c:
/*    4c51c:	1444ffe6 */ 	bne	$v0,$a0,.L0004c4b8
/*    4c520:	24630004 */ 	addiu	$v1,$v1,0x4
/*    4c524:	00001025 */ 	or	$v0,$zero,$zero
.L0004c528:
/*    4c528:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c52c:
/*    4c52c:	8fb00020 */ 	lw	$s0,0x20($sp)
/*    4c530:	8fb10024 */ 	lw	$s1,0x24($sp)
/*    4c534:	8fb20028 */ 	lw	$s2,0x28($sp)
/*    4c538:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*    4c53c:	8fb40030 */ 	lw	$s4,0x30($sp)
/*    4c540:	8fb50034 */ 	lw	$s5,0x34($sp)
/*    4c544:	8fb60038 */ 	lw	$s6,0x38($sp)
/*    4c548:	03e00008 */ 	jr	$ra
/*    4c54c:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
);

GLOBAL_ASM(
glabel func0004c550
/*    4c550:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*    4c554:	afbf003c */ 	sw	$ra,0x3c($sp)
/*    4c558:	afb60038 */ 	sw	$s6,0x38($sp)
/*    4c55c:	afb50034 */ 	sw	$s5,0x34($sp)
/*    4c560:	afb40030 */ 	sw	$s4,0x30($sp)
/*    4c564:	afb3002c */ 	sw	$s3,0x2c($sp)
/*    4c568:	afb20028 */ 	sw	$s2,0x28($sp)
/*    4c56c:	afb10024 */ 	sw	$s1,0x24($sp)
/*    4c570:	afb00020 */ 	sw	$s0,0x20($sp)
/*    4c574:	908e0065 */ 	lbu	$t6,0x65($a0)
/*    4c578:	00a09025 */ 	or	$s2,$a1,$zero
/*    4c57c:	00809825 */ 	or	$s3,$a0,$zero
/*    4c580:	51c00008 */ 	beqzl	$t6,.L0004c5a4
/*    4c584:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    4c588:	0c013378 */ 	jal	__osPfsSelectBank
/*    4c58c:	00002825 */ 	or	$a1,$zero,$zero
/*    4c590:	50400004 */ 	beqzl	$v0,.L0004c5a4
/*    4c594:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    4c598:	1000003d */ 	b	.L0004c690
/*    4c59c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*    4c5a0:	240f0001 */ 	addiu	$t7,$zero,0x1
.L0004c5a4:
/*    4c5a4:	24180003 */ 	addiu	$t8,$zero,0x3
/*    4c5a8:	24190004 */ 	addiu	$t9,$zero,0x4
/*    4c5ac:	24080006 */ 	addiu	$t0,$zero,0x6
/*    4c5b0:	a7af0058 */ 	sh	$t7,0x58($sp)
/*    4c5b4:	a7b8005a */ 	sh	$t8,0x5a($sp)
/*    4c5b8:	a7b9005c */ 	sh	$t9,0x5c($sp)
/*    4c5bc:	a7a8005e */ 	sh	$t0,0x5e($sp)
/*    4c5c0:	24110001 */ 	addiu	$s1,$zero,0x1
/*    4c5c4:	27b0005a */ 	addiu	$s0,$sp,0x5a
/*    4c5c8:	27b60050 */ 	addiu	$s6,$sp,0x50
/*    4c5cc:	24150004 */ 	addiu	$s5,$zero,0x4
/*    4c5d0:	27b40052 */ 	addiu	$s4,$sp,0x52
.L0004c5d4:
/*    4c5d4:	8e640004 */ 	lw	$a0,0x4($s3)
/*    4c5d8:	8e650008 */ 	lw	$a1,0x8($s3)
/*    4c5dc:	96060000 */ 	lhu	$a2,0x0($s0)
/*    4c5e0:	0c012e18 */ 	jal	__osContRamRead
/*    4c5e4:	02403825 */ 	or	$a3,$s2,$zero
/*    4c5e8:	10400003 */ 	beqz	$v0,.L0004c5f8
/*    4c5ec:	02402025 */ 	or	$a0,$s2,$zero
/*    4c5f0:	10000027 */ 	b	.L0004c690
/*    4c5f4:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c5f8:
/*    4c5f8:	02802825 */ 	or	$a1,$s4,$zero
/*    4c5fc:	0c013041 */ 	jal	func0004c104
/*    4c600:	02c03025 */ 	or	$a2,$s6,$zero
/*    4c604:	97a90052 */ 	lhu	$t1,0x52($sp)
/*    4c608:	964a001c */ 	lhu	$t2,0x1c($s2)
/*    4c60c:	97ab0050 */ 	lhu	$t3,0x50($sp)
/*    4c610:	552a0005 */ 	bnel	$t1,$t2,.L0004c628
/*    4c614:	26310001 */ 	addiu	$s1,$s1,0x1
/*    4c618:	964c001e */ 	lhu	$t4,0x1e($s2)
/*    4c61c:	116c0004 */ 	beq	$t3,$t4,.L0004c630
/*    4c620:	00000000 */ 	nop
/*    4c624:	26310001 */ 	addiu	$s1,$s1,0x1
.L0004c628:
/*    4c628:	1635ffea */ 	bne	$s1,$s5,.L0004c5d4
/*    4c62c:	26100002 */ 	addiu	$s0,$s0,0x2
.L0004c630:
/*    4c630:	16350003 */ 	bne	$s1,$s5,.L0004c640
/*    4c634:	00008025 */ 	or	$s0,$zero,$zero
/*    4c638:	10000014 */ 	b	.L0004c68c
/*    4c63c:	2402000a */ 	addiu	$v0,$zero,0xa
.L0004c640:
/*    4c640:	27b40058 */ 	addiu	$s4,$sp,0x58
.L0004c644:
/*    4c644:	1211000d */ 	beq	$s0,$s1,.L0004c67c
/*    4c648:	00106840 */ 	sll	$t5,$s0,0x1
/*    4c64c:	028d7021 */ 	addu	$t6,$s4,$t5
/*    4c650:	95c60000 */ 	lhu	$a2,0x0($t6)
/*    4c654:	8e640004 */ 	lw	$a0,0x4($s3)
/*    4c658:	8e650008 */ 	lw	$a1,0x8($s3)
/*    4c65c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*    4c660:	afaf0010 */ 	sw	$t7,0x10($sp)
/*    4c664:	0c012d84 */ 	jal	__osContRamWrite
/*    4c668:	02403825 */ 	or	$a3,$s2,$zero
/*    4c66c:	50400004 */ 	beqzl	$v0,.L0004c680
/*    4c670:	26100001 */ 	addiu	$s0,$s0,0x1
/*    4c674:	10000006 */ 	b	.L0004c690
/*    4c678:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c67c:
/*    4c67c:	26100001 */ 	addiu	$s0,$s0,0x1
.L0004c680:
/*    4c680:	1615fff0 */ 	bne	$s0,$s5,.L0004c644
/*    4c684:	00000000 */ 	nop
/*    4c688:	00001025 */ 	or	$v0,$zero,$zero
.L0004c68c:
/*    4c68c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0004c690:
/*    4c690:	8fb00020 */ 	lw	$s0,0x20($sp)
/*    4c694:	8fb10024 */ 	lw	$s1,0x24($sp)
/*    4c698:	8fb20028 */ 	lw	$s2,0x28($sp)
/*    4c69c:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*    4c6a0:	8fb40030 */ 	lw	$s4,0x30($sp)
/*    4c6a4:	8fb50034 */ 	lw	$s5,0x34($sp)
/*    4c6a8:	8fb60038 */ 	lw	$s6,0x38($sp)
/*    4c6ac:	03e00008 */ 	jr	$ra
/*    4c6b0:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0004c6b4
/*    4c6b4:	27bdff90 */ 	addiu	$sp,$sp,-112
/*    4c6b8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    4c6bc:	afb10018 */ 	sw	$s1,0x18($sp)
/*    4c6c0:	afb00014 */ 	sw	$s0,0x14($sp)
/*    4c6c4:	908e0065 */ 	lbu	$t6,0x65($a0)
/*    4c6c8:	00808025 */ 	or	$s0,$a0,$zero
/*    4c6cc:	51c00008 */ 	beqzl	$t6,.L0004c6f0
/*    4c6d0:	8e040004 */ 	lw	$a0,0x4($s0)
/*    4c6d4:	0c013378 */ 	jal	__osPfsSelectBank
/*    4c6d8:	00002825 */ 	or	$a1,$zero,$zero
/*    4c6dc:	50400004 */ 	beqzl	$v0,.L0004c6f0
/*    4c6e0:	8e040004 */ 	lw	$a0,0x4($s0)
/*    4c6e4:	1000005a */ 	b	.L0004c850
/*    4c6e8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    4c6ec:	8e040004 */ 	lw	$a0,0x4($s0)
.L0004c6f0:
/*    4c6f0:	8e050008 */ 	lw	$a1,0x8($s0)
/*    4c6f4:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4c6f8:	0c012e18 */ 	jal	__osContRamRead
/*    4c6fc:	27a7004c */ 	addiu	$a3,$sp,0x4c
/*    4c700:	10400003 */ 	beqz	$v0,.L0004c710
/*    4c704:	27a4004c */ 	addiu	$a0,$sp,0x4c
/*    4c708:	10000051 */ 	b	.L0004c850
/*    4c70c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0004c710:
/*    4c710:	27a5006e */ 	addiu	$a1,$sp,0x6e
/*    4c714:	0c013041 */ 	jal	func0004c104
/*    4c718:	27a6006c */ 	addiu	$a2,$sp,0x6c
/*    4c71c:	97af006e */ 	lhu	$t7,0x6e($sp)
/*    4c720:	97b80068 */ 	lhu	$t8,0x68($sp)
/*    4c724:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*    4c728:	00a08825 */ 	or	$s1,$a1,$zero
/*    4c72c:	15f80004 */ 	bne	$t7,$t8,.L0004c740
/*    4c730:	97b9006c */ 	lhu	$t9,0x6c($sp)
/*    4c734:	97a9006a */ 	lhu	$t1,0x6a($sp)
/*    4c738:	53290015 */ 	beql	$t9,$t1,.L0004c790
/*    4c73c:	962a0018 */ 	lhu	$t2,0x18($s1)
.L0004c740:
/*    4c740:	0c013154 */ 	jal	func0004c550
/*    4c744:	02002025 */ 	or	$a0,$s0,$zero
/*    4c748:	2401000a */ 	addiu	$at,$zero,0xa
/*    4c74c:	1441000b */ 	bne	$v0,$at,.L0004c77c
/*    4c750:	00401825 */ 	or	$v1,$v0,$zero
/*    4c754:	02002025 */ 	or	$a0,$s0,$zero
/*    4c758:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*    4c75c:	0c013080 */ 	jal	func0004c200
/*    4c760:	27a60028 */ 	addiu	$a2,$sp,0x28
/*    4c764:	10400003 */ 	beqz	$v0,.L0004c774
/*    4c768:	00000000 */ 	nop
/*    4c76c:	10000038 */ 	b	.L0004c850
/*    4c770:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0004c774:
/*    4c774:	10000005 */ 	b	.L0004c78c
/*    4c778:	27b10028 */ 	addiu	$s1,$sp,0x28
.L0004c77c:
/*    4c77c:	50400004 */ 	beqzl	$v0,.L0004c790
/*    4c780:	962a0018 */ 	lhu	$t2,0x18($s1)
/*    4c784:	10000031 */ 	b	.L0004c84c
/*    4c788:	00601025 */ 	or	$v0,$v1,$zero
.L0004c78c:
/*    4c78c:	962a0018 */ 	lhu	$t2,0x18($s1)
.L0004c790:
/*    4c790:	02002025 */ 	or	$a0,$s0,$zero
/*    4c794:	02202825 */ 	or	$a1,$s1,$zero
/*    4c798:	314b0001 */ 	andi	$t3,$t2,0x1
/*    4c79c:	5560000d */ 	bnezl	$t3,.L0004c7d4
/*    4c7a0:	02202025 */ 	or	$a0,$s1,$zero
/*    4c7a4:	0c013080 */ 	jal	func0004c200
/*    4c7a8:	27a60028 */ 	addiu	$a2,$sp,0x28
/*    4c7ac:	10400003 */ 	beqz	$v0,.L0004c7bc
/*    4c7b0:	97ac0040 */ 	lhu	$t4,0x40($sp)
/*    4c7b4:	10000026 */ 	b	.L0004c850
/*    4c7b8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0004c7bc:
/*    4c7bc:	318d0001 */ 	andi	$t5,$t4,0x1
/*    4c7c0:	15a00003 */ 	bnez	$t5,.L0004c7d0
/*    4c7c4:	27b10028 */ 	addiu	$s1,$sp,0x28
/*    4c7c8:	10000020 */ 	b	.L0004c84c
/*    4c7cc:	2402000b */ 	addiu	$v0,$zero,0xb
.L0004c7d0:
/*    4c7d0:	02202025 */ 	or	$a0,$s1,$zero
.L0004c7d4:
/*    4c7d4:	2605000c */ 	addiu	$a1,$s0,0xc
/*    4c7d8:	0c012c5c */ 	jal	func0004b170
/*    4c7dc:	24060020 */ 	addiu	$a2,$zero,0x20
/*    4c7e0:	922e001b */ 	lbu	$t6,0x1b($s1)
/*    4c7e4:	24090010 */ 	addiu	$t1,$zero,0x10
/*    4c7e8:	240a0008 */ 	addiu	$t2,$zero,0x8
/*    4c7ec:	ae0e004c */ 	sw	$t6,0x4c($s0)
/*    4c7f0:	922f001a */ 	lbu	$t7,0x1a($s1)
/*    4c7f4:	ae090050 */ 	sw	$t1,0x50($s0)
/*    4c7f8:	ae0a0054 */ 	sw	$t2,0x54($s0)
/*    4c7fc:	31e200ff */ 	andi	$v0,$t7,0xff
/*    4c800:	000218c0 */ 	sll	$v1,$v0,0x3
/*    4c804:	0002c040 */ 	sll	$t8,$v0,0x1
/*    4c808:	24680008 */ 	addiu	$t0,$v1,0x8
/*    4c80c:	27190003 */ 	addiu	$t9,$t8,0x3
/*    4c810:	01035821 */ 	addu	$t3,$t0,$v1
/*    4c814:	ae190060 */ 	sw	$t9,0x60($s0)
/*    4c818:	ae080058 */ 	sw	$t0,0x58($s0)
/*    4c81c:	ae0b005c */ 	sw	$t3,0x5c($s0)
/*    4c820:	8e040004 */ 	lw	$a0,0x4($s0)
/*    4c824:	8e050008 */ 	lw	$a1,0x8($s0)
/*    4c828:	24060007 */ 	addiu	$a2,$zero,0x7
/*    4c82c:	2607002c */ 	addiu	$a3,$s0,0x2c
/*    4c830:	0c012e18 */ 	jal	__osContRamRead
/*    4c834:	a20f0064 */ 	sb	$t7,0x64($s0)
/*    4c838:	50400004 */ 	beqzl	$v0,.L0004c84c
/*    4c83c:	00001025 */ 	or	$v0,$zero,$zero
/*    4c840:	10000003 */ 	b	.L0004c850
/*    4c844:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*    4c848:	00001025 */ 	or	$v0,$zero,$zero
.L0004c84c:
/*    4c84c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0004c850:
/*    4c850:	8fb00014 */ 	lw	$s0,0x14($sp)
/*    4c854:	8fb10018 */ 	lw	$s1,0x18($sp)
/*    4c858:	03e00008 */ 	jr	$ra
/*    4c85c:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

GLOBAL_ASM(
glabel func0004c860
/*    4c860:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*    4c864:	afbf001c */ 	sw	$ra,0x1c($sp)
/*    4c868:	afb00018 */ 	sw	$s0,0x18($sp)
/*    4c86c:	908e0065 */ 	lbu	$t6,0x65($a0)
/*    4c870:	00808025 */ 	or	$s0,$a0,$zero
/*    4c874:	51c0000f */ 	beqzl	$t6,.L0004c8b4
/*    4c878:	8e040004 */ 	lw	$a0,0x4($s0)
/*    4c87c:	0c013378 */ 	jal	__osPfsSelectBank
/*    4c880:	00002825 */ 	or	$a1,$zero,$zero
/*    4c884:	24010002 */ 	addiu	$at,$zero,0x2
/*    4c888:	14410005 */ 	bne	$v0,$at,.L0004c8a0
/*    4c88c:	00401825 */ 	or	$v1,$v0,$zero
/*    4c890:	02002025 */ 	or	$a0,$s0,$zero
/*    4c894:	0c013378 */ 	jal	__osPfsSelectBank
/*    4c898:	00002825 */ 	or	$a1,$zero,$zero
/*    4c89c:	00401825 */ 	or	$v1,$v0,$zero
.L0004c8a0:
/*    4c8a0:	50400004 */ 	beqzl	$v0,.L0004c8b4
/*    4c8a4:	8e040004 */ 	lw	$a0,0x4($s0)
/*    4c8a8:	1000001d */ 	b	.L0004c920
/*    4c8ac:	00601025 */ 	or	$v0,$v1,$zero
/*    4c8b0:	8e040004 */ 	lw	$a0,0x4($s0)
.L0004c8b4:
/*    4c8b4:	8e050008 */ 	lw	$a1,0x8($s0)
/*    4c8b8:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4c8bc:	0c012e18 */ 	jal	__osContRamRead
/*    4c8c0:	27a70028 */ 	addiu	$a3,$sp,0x28
/*    4c8c4:	1040000d */ 	beqz	$v0,.L0004c8fc
/*    4c8c8:	24010002 */ 	addiu	$at,$zero,0x2
/*    4c8cc:	10410003 */ 	beq	$v0,$at,.L0004c8dc
/*    4c8d0:	24060001 */ 	addiu	$a2,$zero,0x1
/*    4c8d4:	10000013 */ 	b	.L0004c924
/*    4c8d8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0004c8dc:
/*    4c8dc:	8e040004 */ 	lw	$a0,0x4($s0)
/*    4c8e0:	8e050008 */ 	lw	$a1,0x8($s0)
/*    4c8e4:	0c012e18 */ 	jal	__osContRamRead
/*    4c8e8:	27a70028 */ 	addiu	$a3,$sp,0x28
/*    4c8ec:	50400004 */ 	beqzl	$v0,.L0004c900
/*    4c8f0:	2604000c */ 	addiu	$a0,$s0,0xc
/*    4c8f4:	1000000b */ 	b	.L0004c924
/*    4c8f8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0004c8fc:
/*    4c8fc:	2604000c */ 	addiu	$a0,$s0,0xc
.L0004c900:
/*    4c900:	27a50028 */ 	addiu	$a1,$sp,0x28
/*    4c904:	0c013824 */ 	jal	func0004e090
/*    4c908:	24060020 */ 	addiu	$a2,$zero,0x20
/*    4c90c:	50400004 */ 	beqzl	$v0,.L0004c920
/*    4c910:	00001025 */ 	or	$v0,$zero,$zero
/*    4c914:	10000002 */ 	b	.L0004c920
/*    4c918:	24020002 */ 	addiu	$v0,$zero,0x2
/*    4c91c:	00001025 */ 	or	$v0,$zero,$zero
.L0004c920:
/*    4c920:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0004c924:
/*    4c924:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    4c928:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*    4c92c:	03e00008 */ 	jr	$ra
/*    4c930:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0004c934
/*    4c934:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*    4c938:	afb40030 */ 	sw	$s4,0x30($sp)
/*    4c93c:	30d400ff */ 	andi	$s4,$a2,0xff
/*    4c940:	afb20028 */ 	sw	$s2,0x28($sp)
/*    4c944:	00809025 */ 	or	$s2,$a0,$zero
/*    4c948:	afbf0034 */ 	sw	$ra,0x34($sp)
/*    4c94c:	afb3002c */ 	sw	$s3,0x2c($sp)
/*    4c950:	afb10024 */ 	sw	$s1,0x24($sp)
/*    4c954:	afb00020 */ 	sw	$s0,0x20($sp)
/*    4c958:	afa5005c */ 	sw	$a1,0x5c($sp)
/*    4c95c:	afa60060 */ 	sw	$a2,0x60($sp)
/*    4c960:	16800011 */ 	bnez	$s4,.L0004c9a8
/*    4c964:	afa70064 */ 	sw	$a3,0x64($sp)
/*    4c968:	3c0f8006 */ 	lui	$t7,%hi(var80060984)
/*    4c96c:	91ef0984 */ 	lbu	$t7,%lo(var80060984)($t7)
/*    4c970:	93b80067 */ 	lbu	$t8,0x67($sp)
/*    4c974:	3c198006 */ 	lui	$t9,%hi(var80060980)
/*    4c978:	55f8000c */ 	bnel	$t7,$t8,.L0004c9ac
/*    4c97c:	92490065 */ 	lbu	$t1,0x65($s2)
/*    4c980:	8f390980 */ 	lw	$t9,%lo(var80060980)($t9)
/*    4c984:	8c880008 */ 	lw	$t0,0x8($a0)
/*    4c988:	3c04800a */ 	lui	$a0,%hi(var8009c870)
/*    4c98c:	2484c870 */ 	addiu	$a0,$a0,%lo(var8009c870)
/*    4c990:	57280006 */ 	bnel	$t9,$t0,.L0004c9ac
/*    4c994:	92490065 */ 	lbu	$t1,0x65($s2)
/*    4c998:	0c012c5c */ 	jal	func0004b170
/*    4c99c:	24060100 */ 	addiu	$a2,$zero,0x100
/*    4c9a0:	10000091 */ 	b	.L0004cbe8
/*    4c9a4:	00001025 */ 	or	$v0,$zero,$zero
.L0004c9a8:
/*    4c9a8:	92490065 */ 	lbu	$t1,0x65($s2)
.L0004c9ac:
/*    4c9ac:	02402025 */ 	or	$a0,$s2,$zero
/*    4c9b0:	51200008 */ 	beqzl	$t1,.L0004c9d4
/*    4c9b4:	93a30067 */ 	lbu	$v1,0x67($sp)
/*    4c9b8:	0c013378 */ 	jal	__osPfsSelectBank
/*    4c9bc:	00002825 */ 	or	$a1,$zero,$zero
/*    4c9c0:	50400004 */ 	beqzl	$v0,.L0004c9d4
/*    4c9c4:	93a30067 */ 	lbu	$v1,0x67($sp)
/*    4c9c8:	10000088 */ 	b	.L0004cbec
/*    4c9cc:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*    4c9d0:	93a30067 */ 	lbu	$v1,0x67($sp)
.L0004c9d4:
/*    4c9d4:	24020001 */ 	addiu	$v0,$zero,0x1
/*    4c9d8:	240a0001 */ 	addiu	$t2,$zero,0x1
/*    4c9dc:	58600004 */ 	blezl	$v1,.L0004c9f0
/*    4c9e0:	8e4b0060 */ 	lw	$t3,0x60($s2)
/*    4c9e4:	10000003 */ 	b	.L0004c9f4
/*    4c9e8:	afaa0048 */ 	sw	$t2,0x48($sp)
/*    4c9ec:	8e4b0060 */ 	lw	$t3,0x60($s2)
.L0004c9f0:
/*    4c9f0:	afab0048 */ 	sw	$t3,0x48($sp)
.L0004c9f4:
/*    4c9f4:	1454000c */ 	bne	$v0,$s4,.L0004ca28
/*    4c9f8:	8fad0048 */ 	lw	$t5,0x48($sp)
/*    4c9fc:	8fac005c */ 	lw	$t4,0x5c($sp)
/*    4ca00:	000d2823 */ 	negu	$a1,$t5
/*    4ca04:	00057840 */ 	sll	$t7,$a1,0x1
/*    4ca08:	000d7040 */ 	sll	$t6,$t5,0x1
/*    4ca0c:	25e50100 */ 	addiu	$a1,$t7,0x100
/*    4ca10:	afa3003c */ 	sw	$v1,0x3c($sp)
/*    4ca14:	0c013024 */ 	jal	func0004c090
/*    4ca18:	018e2021 */ 	addu	$a0,$t4,$t6
/*    4ca1c:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    4ca20:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*    4ca24:	a3020001 */ 	sb	$v0,0x1($t8)
.L0004ca28:
/*    4ca28:	00008025 */ 	or	$s0,$zero,$zero
/*    4ca2c:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*    4ca30:	000398c0 */ 	sll	$s3,$v1,0x3
.L0004ca34:
/*    4ca34:	24020001 */ 	addiu	$v0,$zero,0x1
/*    4ca38:	14540016 */ 	bne	$v0,$s4,.L0004ca94
/*    4ca3c:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4ca40:	8e590054 */ 	lw	$t9,0x54($s2)
/*    4ca44:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4ca48:	afa00010 */ 	sw	$zero,0x10($sp)
/*    4ca4c:	03334021 */ 	addu	$t0,$t9,$s3
/*    4ca50:	01103021 */ 	addu	$a2,$t0,$s0
/*    4ca54:	30c9ffff */ 	andi	$t1,$a2,0xffff
/*    4ca58:	01203025 */ 	or	$a2,$t1,$zero
/*    4ca5c:	0c012d84 */ 	jal	__osContRamWrite
/*    4ca60:	02203825 */ 	or	$a3,$s1,$zero
/*    4ca64:	8e4a0058 */ 	lw	$t2,0x58($s2)
/*    4ca68:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4ca6c:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4ca70:	01535821 */ 	addu	$t3,$t2,$s3
/*    4ca74:	01703021 */ 	addu	$a2,$t3,$s0
/*    4ca78:	30ccffff */ 	andi	$t4,$a2,0xffff
/*    4ca7c:	01803025 */ 	or	$a2,$t4,$zero
/*    4ca80:	afa00010 */ 	sw	$zero,0x10($sp)
/*    4ca84:	0c012d84 */ 	jal	__osContRamWrite
/*    4ca88:	02203825 */ 	or	$a3,$s1,$zero
/*    4ca8c:	1000000a */ 	b	.L0004cab8
/*    4ca90:	00401825 */ 	or	$v1,$v0,$zero
.L0004ca94:
/*    4ca94:	8e4e0054 */ 	lw	$t6,0x54($s2)
/*    4ca98:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4ca9c:	02203825 */ 	or	$a3,$s1,$zero
/*    4caa0:	01d36821 */ 	addu	$t5,$t6,$s3
/*    4caa4:	01b03021 */ 	addu	$a2,$t5,$s0
/*    4caa8:	30cfffff */ 	andi	$t7,$a2,0xffff
/*    4caac:	0c012e18 */ 	jal	__osContRamRead
/*    4cab0:	01e03025 */ 	or	$a2,$t7,$zero
/*    4cab4:	00401825 */ 	or	$v1,$v0,$zero
.L0004cab8:
/*    4cab8:	10400003 */ 	beqz	$v0,.L0004cac8
/*    4cabc:	26100001 */ 	addiu	$s0,$s0,0x1
/*    4cac0:	10000049 */ 	b	.L0004cbe8
/*    4cac4:	00601025 */ 	or	$v0,$v1,$zero
.L0004cac8:
/*    4cac8:	2a010008 */ 	slti	$at,$s0,0x8
/*    4cacc:	1420ffd9 */ 	bnez	$at,.L0004ca34
/*    4cad0:	26310020 */ 	addiu	$s1,$s1,0x20
/*    4cad4:	16800038 */ 	bnez	$s4,.L0004cbb8
/*    4cad8:	8fb90048 */ 	lw	$t9,0x48($sp)
/*    4cadc:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*    4cae0:	00192823 */ 	negu	$a1,$t9
/*    4cae4:	00054840 */ 	sll	$t1,$a1,0x1
/*    4cae8:	00194040 */ 	sll	$t0,$t9,0x1
/*    4caec:	25250100 */ 	addiu	$a1,$t1,0x100
/*    4caf0:	0308a021 */ 	addu	$s4,$t8,$t0
/*    4caf4:	02802025 */ 	or	$a0,$s4,$zero
/*    4caf8:	0c013024 */ 	jal	func0004c090
/*    4cafc:	afa5003c */ 	sw	$a1,0x3c($sp)
/*    4cb00:	8fab005c */ 	lw	$t3,0x5c($sp)
/*    4cb04:	304a00ff */ 	andi	$t2,$v0,0xff
/*    4cb08:	00008025 */ 	or	$s0,$zero,$zero
/*    4cb0c:	916c0001 */ 	lbu	$t4,0x1($t3)
/*    4cb10:	01608825 */ 	or	$s1,$t3,$zero
/*    4cb14:	514c0029 */ 	beql	$t2,$t4,.L0004cbbc
/*    4cb18:	93ab0067 */ 	lbu	$t3,0x67($sp)
.L0004cb1c:
/*    4cb1c:	8e4e0058 */ 	lw	$t6,0x58($s2)
/*    4cb20:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4cb24:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4cb28:	01d36821 */ 	addu	$t5,$t6,$s3
/*    4cb2c:	01b03021 */ 	addu	$a2,$t5,$s0
/*    4cb30:	30cfffff */ 	andi	$t7,$a2,0xffff
/*    4cb34:	01e03025 */ 	or	$a2,$t7,$zero
/*    4cb38:	0c012e18 */ 	jal	__osContRamRead
/*    4cb3c:	02203825 */ 	or	$a3,$s1,$zero
/*    4cb40:	26100001 */ 	addiu	$s0,$s0,0x1
/*    4cb44:	2a010008 */ 	slti	$at,$s0,0x8
/*    4cb48:	1420fff4 */ 	bnez	$at,.L0004cb1c
/*    4cb4c:	26310020 */ 	addiu	$s1,$s1,0x20
/*    4cb50:	02802025 */ 	or	$a0,$s4,$zero
/*    4cb54:	0c013024 */ 	jal	func0004c090
/*    4cb58:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*    4cb5c:	8fa8005c */ 	lw	$t0,0x5c($sp)
/*    4cb60:	305800ff */ 	andi	$t8,$v0,0xff
/*    4cb64:	00008025 */ 	or	$s0,$zero,$zero
/*    4cb68:	91190001 */ 	lbu	$t9,0x1($t0)
/*    4cb6c:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*    4cb70:	13190003 */ 	beq	$t8,$t9,.L0004cb80
/*    4cb74:	00000000 */ 	nop
/*    4cb78:	1000001b */ 	b	.L0004cbe8
/*    4cb7c:	24020003 */ 	addiu	$v0,$zero,0x3
.L0004cb80:
/*    4cb80:	8e490054 */ 	lw	$t1,0x54($s2)
/*    4cb84:	8e440004 */ 	lw	$a0,0x4($s2)
/*    4cb88:	8e450008 */ 	lw	$a1,0x8($s2)
/*    4cb8c:	01335021 */ 	addu	$t2,$t1,$s3
/*    4cb90:	01503021 */ 	addu	$a2,$t2,$s0
/*    4cb94:	30ccffff */ 	andi	$t4,$a2,0xffff
/*    4cb98:	01803025 */ 	or	$a2,$t4,$zero
/*    4cb9c:	afa00010 */ 	sw	$zero,0x10($sp)
/*    4cba0:	0c012d84 */ 	jal	__osContRamWrite
/*    4cba4:	02203825 */ 	or	$a3,$s1,$zero
/*    4cba8:	26100001 */ 	addiu	$s0,$s0,0x1
/*    4cbac:	24010008 */ 	addiu	$at,$zero,0x8
/*    4cbb0:	1601fff3 */ 	bne	$s0,$at,.L0004cb80
/*    4cbb4:	26310020 */ 	addiu	$s1,$s1,0x20
.L0004cbb8:
/*    4cbb8:	93ab0067 */ 	lbu	$t3,0x67($sp)
.L0004cbbc:
/*    4cbbc:	3c018006 */ 	lui	$at,%hi(var80060984)
/*    4cbc0:	3c05800a */ 	lui	$a1,%hi(var8009c870)
/*    4cbc4:	24a5c870 */ 	addiu	$a1,$a1,%lo(var8009c870)
/*    4cbc8:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*    4cbcc:	24060100 */ 	addiu	$a2,$zero,0x100
/*    4cbd0:	0c012c5c */ 	jal	func0004b170
/*    4cbd4:	a02b0984 */ 	sb	$t3,%lo(var80060984)($at)
/*    4cbd8:	8e4e0008 */ 	lw	$t6,0x8($s2)
/*    4cbdc:	3c018006 */ 	lui	$at,%hi(var80060980)
/*    4cbe0:	00001025 */ 	or	$v0,$zero,$zero
/*    4cbe4:	ac2e0980 */ 	sw	$t6,%lo(var80060980)($at)
.L0004cbe8:
/*    4cbe8:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0004cbec:
/*    4cbec:	8fb00020 */ 	lw	$s0,0x20($sp)
/*    4cbf0:	8fb10024 */ 	lw	$s1,0x24($sp)
/*    4cbf4:	8fb20028 */ 	lw	$s2,0x28($sp)
/*    4cbf8:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*    4cbfc:	8fb40030 */ 	lw	$s4,0x30($sp)
/*    4cc00:	03e00008 */ 	jr	$ra
/*    4cc04:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*    4cc08:	00000000 */ 	nop
/*    4cc0c:	00000000 */ 	nop
);
