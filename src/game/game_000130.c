#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "game/game_000130.h"
#include "game/game_097890.h"
#include "gvars/gvars.h"
#include "library/library_233c0.h"
#include "types.h"

const u32 var7f1a78c0[] = {0x40c907a9};
const u32 var7f1a78c4[] = {0x38c907a9};
const u32 var7f1a78c8[] = {0x3dccccce};
const u32 var7f1a78cc[] = {0x00000000};

GLOBAL_ASM(
glabel func0f000130
/*  f000130:	3c048006 */ 	lui	$a0,%hi(var80062b1c)
/*  f000134:	24842b1c */ 	addiu	$a0,$a0,%lo(var80062b1c)
/*  f000138:	00007080 */ 	sll	$t6,$zero,0x2
/*  f00013c:	008e7821 */ 	addu	$t7,$a0,$t6
/*  f000140:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f000144:	3c038006 */ 	lui	$v1,%hi(var80062b00)
/*  f000148:	24632b00 */ 	addiu	$v1,$v1,%lo(var80062b00)
/*  f00014c:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f000150:	07000009 */ 	bltz	$t8,.L0f000178
/*  f000154:	00001025 */ 	or	$v0,$zero,$zero
/*  f000158:	24590001 */ 	addiu	$t9,$v0,0x1
.L0f00015c:
/*  f00015c:	00194080 */ 	sll	$t0,$t9,0x2
/*  f000160:	00884821 */ 	addu	$t1,$a0,$t0
/*  f000164:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*  f000168:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f00016c:	03201025 */ 	or	$v0,$t9,$zero
/*  f000170:	0543fffa */ 	bgezl	$t2,.L0f00015c
/*  f000174:	24590001 */ 	addiu	$t9,$v0,0x1
.L0f000178:
/*  f000178:	3c048006 */ 	lui	$a0,%hi(var80062c14)
/*  f00017c:	24842c14 */ 	addiu	$a0,$a0,%lo(var80062c14)
/*  f000180:	00005880 */ 	sll	$t3,$zero,0x2
/*  f000184:	008b6021 */ 	addu	$t4,$a0,$t3
/*  f000188:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f00018c:	3c038006 */ 	lui	$v1,%hi(var80062b0c)
/*  f000190:	24632b0c */ 	addiu	$v1,$v1,%lo(var80062b0c)
/*  f000194:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f000198:	05a00009 */ 	bltz	$t5,.L0f0001c0
/*  f00019c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0001a0:	244e0001 */ 	addiu	$t6,$v0,0x1
.L0f0001a4:
/*  f0001a4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0001a8:	008fc021 */ 	addu	$t8,$a0,$t7
/*  f0001ac:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f0001b0:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f0001b4:	01c01025 */ 	or	$v0,$t6,$zero
/*  f0001b8:	0723fffa */ 	bgezl	$t9,.L0f0001a4
/*  f0001bc:	244e0001 */ 	addiu	$t6,$v0,0x1
.L0f0001c0:
/*  f0001c0:	3c048006 */ 	lui	$a0,%hi(var80062c6c)
/*  f0001c4:	24842c6c */ 	addiu	$a0,$a0,%lo(var80062c6c)
/*  f0001c8:	00004080 */ 	sll	$t0,$zero,0x2
/*  f0001cc:	00884821 */ 	addu	$t1,$a0,$t0
/*  f0001d0:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*  f0001d4:	3c038006 */ 	lui	$v1,%hi(var80062b10)
/*  f0001d8:	24632b10 */ 	addiu	$v1,$v1,%lo(var80062b10)
/*  f0001dc:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f0001e0:	05400009 */ 	bltz	$t2,.L0f000208
/*  f0001e4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0001e8:	244b0001 */ 	addiu	$t3,$v0,0x1
.L0f0001ec:
/*  f0001ec:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f0001f0:	008c6821 */ 	addu	$t5,$a0,$t4
/*  f0001f4:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f0001f8:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f0001fc:	01601025 */ 	or	$v0,$t3,$zero
/*  f000200:	05c3fffa */ 	bgezl	$t6,.L0f0001ec
/*  f000204:	244b0001 */ 	addiu	$t3,$v0,0x1
.L0f000208:
/*  f000208:	3c048006 */ 	lui	$a0,%hi(var80062b68)
/*  f00020c:	24842b68 */ 	addiu	$a0,$a0,%lo(var80062b68)
/*  f000210:	00007880 */ 	sll	$t7,$zero,0x2
/*  f000214:	008fc021 */ 	addu	$t8,$a0,$t7
/*  f000218:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f00021c:	3c038006 */ 	lui	$v1,%hi(var80062b04)
/*  f000220:	24632b04 */ 	addiu	$v1,$v1,%lo(var80062b04)
/*  f000224:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f000228:	07200009 */ 	bltz	$t9,.L0f000250
/*  f00022c:	00001025 */ 	or	$v0,$zero,$zero
/*  f000230:	24480001 */ 	addiu	$t0,$v0,0x1
.L0f000234:
/*  f000234:	00084880 */ 	sll	$t1,$t0,0x2
/*  f000238:	00895021 */ 	addu	$t2,$a0,$t1
/*  f00023c:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*  f000240:	ac680000 */ 	sw	$t0,0x0($v1)
/*  f000244:	01001025 */ 	or	$v0,$t0,$zero
/*  f000248:	0563fffa */ 	bgezl	$t3,.L0f000234
/*  f00024c:	24480001 */ 	addiu	$t0,$v0,0x1
.L0f000250:
/*  f000250:	3c048006 */ 	lui	$a0,%hi(var80062c58)
/*  f000254:	24842c58 */ 	addiu	$a0,$a0,%lo(var80062c58)
/*  f000258:	00006080 */ 	sll	$t4,$zero,0x2
/*  f00025c:	008c6821 */ 	addu	$t5,$a0,$t4
/*  f000260:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f000264:	3c038006 */ 	lui	$v1,%hi(var80062b08)
/*  f000268:	24632b08 */ 	addiu	$v1,$v1,%lo(var80062b08)
/*  f00026c:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f000270:	05c00009 */ 	bltz	$t6,.L0f000298
/*  f000274:	00001025 */ 	or	$v0,$zero,$zero
/*  f000278:	244f0001 */ 	addiu	$t7,$v0,0x1
.L0f00027c:
/*  f00027c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f000280:	0098c821 */ 	addu	$t9,$a0,$t8
/*  f000284:	8f280000 */ 	lw	$t0,0x0($t9)
/*  f000288:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f00028c:	01e01025 */ 	or	$v0,$t7,$zero
/*  f000290:	0503fffa */ 	bgezl	$t0,.L0f00027c
/*  f000294:	244f0001 */ 	addiu	$t7,$v0,0x1
.L0f000298:
/*  f000298:	03e00008 */ 	jr	$ra
/*  f00029c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0002a0
/*  f0002a0:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0002a4:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f0002a8:	00049c00 */ 	sll	$s3,$a0,0x10
/*  f0002ac:	00137403 */ 	sra	$t6,$s3,0x10
/*  f0002b0:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f0002b4:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f0002b8:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f0002bc:	00a6082a */ 	slt	$at,$a1,$a2
/*  f0002c0:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0002c4:	00c09025 */ 	or	$s2,$a2,$zero
/*  f0002c8:	01c09825 */ 	or	$s3,$t6,$zero
/*  f0002cc:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0002d0:	afb50038 */ 	sw	$s5,0x38($sp)
/*  f0002d4:	afb40034 */ 	sw	$s4,0x34($sp)
/*  f0002d8:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f0002dc:	10200014 */ 	beqz	$at,.L0f000330
/*  f0002e0:	00008825 */ 	or	$s1,$zero,$zero
/*  f0002e4:	3c148008 */ 	lui	$s4,%hi(stagethinglist_22e60)
/*  f0002e8:	2694ce40 */ 	addiu	$s4,$s4,%lo(stagethinglist_22e60)
/*  f0002ec:	27b50048 */ 	addiu	$s5,$sp,0x48
.L0f0002f0:
/*  f0002f0:	00133c00 */ 	sll	$a3,$s3,0x10
/*  f0002f4:	00077c03 */ 	sra	$t7,$a3,0x10
/*  f0002f8:	01e03825 */ 	or	$a3,$t7,$zero
/*  f0002fc:	00002025 */ 	or	$a0,$zero,$zero
/*  f000300:	00002825 */ 	or	$a1,$zero,$zero
/*  f000304:	02803025 */ 	or	$a2,$s4,$zero
/*  f000308:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f00030c:	afb50014 */ 	sw	$s5,0x14($sp)
/*  f000310:	0c009217 */ 	jal	func0002485c
/*  f000314:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f000318:	02228821 */ 	addu	$s1,$s1,$v0
/*  f00031c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f000320:	3238ffff */ 	andi	$t8,$s1,0xffff
/*  f000324:	0212082a */ 	slt	$at,$s0,$s2
/*  f000328:	1420fff1 */ 	bnez	$at,.L0f0002f0
/*  f00032c:	03008825 */ 	or	$s1,$t8,$zero
.L0f000330:
/*  f000330:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f000334:	02201025 */ 	or	$v0,$s1,$zero
/*  f000338:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f00033c:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f000340:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f000344:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f000348:	8fb40034 */ 	lw	$s4,0x34($sp)
/*  f00034c:	8fb50038 */ 	lw	$s5,0x38($sp)
/*  f000350:	03e00008 */ 	jr	$ra
/*  f000354:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

GLOBAL_ASM(
glabel func0f000358
/*  f000358:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f00035c:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f000360:	00049c00 */ 	sll	$s3,$a0,0x10
/*  f000364:	00137403 */ 	sra	$t6,$s3,0x10
/*  f000368:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f00036c:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f000370:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f000374:	00a6082a */ 	slt	$at,$a1,$a2
/*  f000378:	00a08025 */ 	or	$s0,$a1,$zero
/*  f00037c:	00c09025 */ 	or	$s2,$a2,$zero
/*  f000380:	01c09825 */ 	or	$s3,$t6,$zero
/*  f000384:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f000388:	afb50038 */ 	sw	$s5,0x38($sp)
/*  f00038c:	afb40034 */ 	sw	$s4,0x34($sp)
/*  f000390:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f000394:	10200013 */ 	beqz	$at,.L0f0003e4
/*  f000398:	00008825 */ 	or	$s1,$zero,$zero
/*  f00039c:	3c148008 */ 	lui	$s4,%hi(stagethinglist_22e60)
/*  f0003a0:	2694ce40 */ 	addiu	$s4,$s4,%lo(stagethinglist_22e60)
/*  f0003a4:	27b50044 */ 	addiu	$s5,$sp,0x44
.L0f0003a8:
/*  f0003a8:	00133c00 */ 	sll	$a3,$s3,0x10
/*  f0003ac:	00077c03 */ 	sra	$t7,$a3,0x10
/*  f0003b0:	01e03825 */ 	or	$a3,$t7,$zero
/*  f0003b4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0003b8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0003bc:	02803025 */ 	or	$a2,$s4,$zero
/*  f0003c0:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0003c4:	afb50014 */ 	sw	$s5,0x14($sp)
/*  f0003c8:	0c009217 */ 	jal	func0002485c
/*  f0003cc:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0003d0:	87b80048 */ 	lh	$t8,0x48($sp)
/*  f0003d4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0003d8:	0212082a */ 	slt	$at,$s0,$s2
/*  f0003dc:	1420fff2 */ 	bnez	$at,.L0f0003a8
/*  f0003e0:	02388821 */ 	addu	$s1,$s1,$t8
.L0f0003e4:
/*  f0003e4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0003e8:	02201025 */ 	or	$v0,$s1,$zero
/*  f0003ec:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f0003f0:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f0003f4:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f0003f8:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f0003fc:	8fb40034 */ 	lw	$s4,0x34($sp)
/*  f000400:	8fb50038 */ 	lw	$s5,0x38($sp)
/*  f000404:	03e00008 */ 	jr	$ra
/*  f000408:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

GLOBAL_ASM(
glabel func0f00040c
/*  f00040c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f000410:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f000414:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f000418:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f00041c:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f000420:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f000424:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f000428:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f00042c:	848e0000 */ 	lh	$t6,0x0($a0)
/*  f000430:	00008825 */ 	or	$s1,$zero,$zero
/*  f000434:	00808025 */ 	or	$s0,$a0,$zero
/*  f000438:	11c00032 */ 	beqz	$t6,.L0f000504
/*  f00043c:	3c017f1a */ 	lui	$at,%hi(var7f1a78c0)
/*  f000440:	c43878c0 */ 	lwc1	$f24,%lo(var7f1a78c0)($at)
/*  f000444:	3c017f1a */ 	lui	$at,%hi(var7f1a78c4)
/*  f000448:	4480a000 */ 	mtc1	$zero,$f20
/*  f00044c:	c43678c4 */ 	lwc1	$f22,%lo(var7f1a78c4)($at)
/*  f000450:	34128000 */ 	dli	$s2,0x8000
.L0f000454:
/*  f000454:	0fc25e42 */ 	jal	func0f097908
/*  f000458:	c60c0004 */ 	lwc1	$f12,0x4($s0)
/*  f00045c:	86040000 */ 	lh	$a0,0x0($s0)
/*  f000460:	00002825 */ 	or	$a1,$zero,$zero
/*  f000464:	0fc000a8 */ 	jal	func0f0002a0
/*  f000468:	00403025 */ 	or	$a2,$v0,$zero
/*  f00046c:	c6000004 */ 	lwc1	$f0,0x4($s0)
/*  f000470:	3043ffff */ 	andi	$v1,$v0,0xffff
/*  f000474:	0072082a */ 	slt	$at,$v1,$s2
/*  f000478:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f00047c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f000480:	4502001b */ 	bc1fl	.L0f0004f0
/*  f000484:	e6140008 */ 	swc1	$f20,0x8($s0)
/*  f000488:	5020000d */ 	beqzl	$at,.L0f0004c0
/*  f00048c:	44839000 */ 	mtc1	$v1,$f18
/*  f000490:	44832000 */ 	mtc1	$v1,$f4
/*  f000494:	3c014f80 */ 	lui	$at,0x4f80
/*  f000498:	04610004 */ 	bgez	$v1,.L0f0004ac
/*  f00049c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0004a0:	44814000 */ 	mtc1	$at,$f8
/*  f0004a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0004a8:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f0004ac:
/*  f0004ac:	46163282 */ 	mul.s	$f10,$f6,$f22
/*  f0004b0:	46005403 */ 	div.s	$f16,$f10,$f0
/*  f0004b4:	1000000e */ 	beqz	$zero,.L0f0004f0
/*  f0004b8:	e6100008 */ 	swc1	$f16,0x8($s0)
/*  f0004bc:	44839000 */ 	mtc1	$v1,$f18
.L0f0004c0:
/*  f0004c0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0004c4:	04610004 */ 	bgez	$v1,.L0f0004d8
/*  f0004c8:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0004cc:	44814000 */ 	mtc1	$at,$f8
/*  f0004d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0004d4:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f0004d8:
/*  f0004d8:	46162182 */ 	mul.s	$f6,$f4,$f22
/*  f0004dc:	46183281 */ 	sub.s	$f10,$f6,$f24
/*  f0004e0:	46005403 */ 	div.s	$f16,$f10,$f0
/*  f0004e4:	10000002 */ 	beqz	$zero,.L0f0004f0
/*  f0004e8:	e6100008 */ 	swc1	$f16,0x8($s0)
/*  f0004ec:	e6140008 */ 	swc1	$f20,0x8($s0)
.L0f0004f0:
/*  f0004f0:	860f0048 */ 	lh	$t7,0x48($s0)
/*  f0004f4:	26100048 */ 	addiu	$s0,$s0,0x48
/*  f0004f8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0004fc:	15e0ffd5 */ 	bnez	$t7,.L0f000454
/*  f000500:	00000000 */ 	sll	$zero,$zero,0x0
.L0f000504:
/*  f000504:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f000508:	02201025 */ 	or	$v0,$s1,$zero
/*  f00050c:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f000510:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f000514:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f000518:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f00051c:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f000520:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f000524:	03e00008 */ 	jr	$ra
/*  f000528:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel func0f00052c
/*  f00052c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f000530:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f000534:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f000538:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f00053c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f000540:	00808025 */ 	or	$s0,$a0,$zero
/*  f000544:	00008825 */ 	or	$s1,$zero,$zero
/*  f000548:	24120080 */ 	addiu	$s2,$zero,0x80
.L0f00054c:
/*  f00054c:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f000550:	8c4e0004 */ 	lw	$t6,0x4($v0)
/*  f000554:	05c30006 */ 	bgezl	$t6,.L0f000570
/*  f000558:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f00055c:	0fc00103 */ 	jal	func0f00040c
/*  f000560:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f000564:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f000568:	ade20004 */ 	sw	$v0,0x4($t7)
/*  f00056c:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f000570:
/*  f000570:	1632fff6 */ 	bne	$s1,$s2,.L0f00054c
/*  f000574:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f000578:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f00057c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f000580:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f000584:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f000588:	03e00008 */ 	jr	$ra
/*  f00058c:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f000590
/*  f000590:	848e0000 */ 	lh	$t6,0x0($a0)
/*  f000594:	00001825 */ 	or	$v1,$zero,$zero
/*  f000598:	00801025 */ 	or	$v0,$a0,$zero
/*  f00059c:	19c00006 */ 	blez	$t6,.L0f0005b8
/*  f0005a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0005a4:	844f001c */ 	lh	$t7,0x1c($v0)
.L0f0005a8:
/*  f0005a8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0005ac:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f0005b0:	5de0fffd */ 	bgtzl	$t7,.L0f0005a8
/*  f0005b4:	844f001c */ 	lh	$t7,0x1c($v0)
.L0f0005b8:
/*  f0005b8:	03e00008 */ 	jr	$ra
/*  f0005bc:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f0005c0
/*  f0005c0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0005c4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0005c8:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f0005cc:	0c008dda */ 	jal	animGetNumFrames
/*  f0005d0:	87a40022 */ 	lh	$a0,0x22($sp)
/*  f0005d4:	87a40022 */ 	lh	$a0,0x22($sp)
/*  f0005d8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0005dc:	0fc000d6 */ 	jal	func0f000358
/*  f0005e0:	2446ffff */ 	addiu	$a2,$v0,-1
/*  f0005e4:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0005e8:	0c008dda */ 	jal	animGetNumFrames
/*  f0005ec:	87a40022 */ 	lh	$a0,0x22($sp)
/*  f0005f0:	8fae0018 */ 	lw	$t6,0x18($sp)
/*  f0005f4:	44824000 */ 	mtc1	$v0,$f8
/*  f0005f8:	87a80022 */ 	lh	$t0,0x22($sp)
/*  f0005fc:	448e2000 */ 	mtc1	$t6,$f4
/*  f000600:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f000604:	3c198006 */ 	lui	$t9,0x8006
/*  f000608:	8f39f014 */ 	lw	$t9,-0xfec($t9)
/*  f00060c:	00084840 */ 	sll	$t1,$t0,0x1
/*  f000610:	3c017f1a */ 	lui	$at,%hi(var7f1a78c8)
/*  f000614:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f000618:	03295021 */ 	addu	$t2,$t9,$t1
/*  f00061c:	460a3083 */ 	div.s	$f2,$f6,$f10
/*  f000620:	4600140d */ 	trunc.w.s	$f16,$f2
/*  f000624:	44188000 */ 	mfc1	$t8,$f16
/*  f000628:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00062c:	a5580000 */ 	sh	$t8,0x0($t2)
/*  f000630:	c43278c8 */ 	lwc1	$f18,%lo(var7f1a78c8)($at)
/*  f000634:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f000638:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f00063c:	46121002 */ 	mul.s	$f0,$f2,$f18
/*  f000640:	03e00008 */ 	jr	$ra
/*  f000644:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f000648
/*  f000648:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f00064c:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f000650:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f000654:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f000658:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f00065c:	3c128006 */ 	lui	$s2,%hi(var800652b8)
/*  f000660:	3c138006 */ 	lui	$s3,%hi(var80067fdc)
/*  f000664:	3c158006 */ 	lui	$s5,%hi(var80067ff0)
/*  f000668:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f00066c:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f000670:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f000674:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f000678:	26b57ff0 */ 	addiu	$s5,$s5,%lo(var80067ff0)
/*  f00067c:	26737fdc */ 	addiu	$s3,$s3,%lo(var80067fdc)
/*  f000680:	265252b8 */ 	addiu	$s2,$s2,%lo(var800652b8)
/*  f000684:	2414ffff */ 	addiu	$s4,$zero,-1
.L0f000688:
/*  f000688:	8e430000 */ 	lw	$v1,0x0($s2)
/*  f00068c:	00008025 */ 	or	$s0,$zero,$zero
/*  f000690:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f000694:	00601025 */ 	or	$v0,$v1,$zero
/*  f000698:	528e001e */ 	beql	$s4,$t6,.L0f000714
/*  f00069c:	8e620000 */ 	lw	$v0,0x0($s3)
/*  f0006a0:	8c440004 */ 	lw	$a0,0x4($v0)
.L0f0006a4:
/*  f0006a4:	50800008 */ 	beqzl	$a0,.L0f0006c8
/*  f0006a8:	ac40000c */ 	sw	$zero,0xc($v0)
/*  f0006ac:	0fc00164 */ 	jal	func0f000590
/*  f0006b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0006b4:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f0006b8:	01f0c021 */ 	addu	$t8,$t7,$s0
/*  f0006bc:	10000002 */ 	beqz	$zero,.L0f0006c8
/*  f0006c0:	af02000c */ 	sw	$v0,0xc($t8)
/*  f0006c4:	ac40000c */ 	sw	$zero,0xc($v0)
.L0f0006c8:
/*  f0006c8:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f0006cc:	03301021 */ 	addu	$v0,$t9,$s0
/*  f0006d0:	8c440008 */ 	lw	$a0,0x8($v0)
/*  f0006d4:	50800008 */ 	beqzl	$a0,.L0f0006f8
/*  f0006d8:	ac400010 */ 	sw	$zero,0x10($v0)
/*  f0006dc:	0fc00164 */ 	jal	func0f000590
/*  f0006e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0006e4:	8e480000 */ 	lw	$t0,0x0($s2)
/*  f0006e8:	01104821 */ 	addu	$t1,$t0,$s0
/*  f0006ec:	10000002 */ 	beqz	$zero,.L0f0006f8
/*  f0006f0:	ad220010 */ 	sw	$v0,0x10($t1)
/*  f0006f4:	ac400010 */ 	sw	$zero,0x10($v0)
.L0f0006f8:
/*  f0006f8:	8e4a0000 */ 	lw	$t2,0x0($s2)
/*  f0006fc:	26100014 */ 	addiu	$s0,$s0,0x14
/*  f000700:	01501021 */ 	addu	$v0,$t2,$s0
/*  f000704:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f000708:	568bffe6 */ 	bnel	$s4,$t3,.L0f0006a4
/*  f00070c:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f000710:	8e620000 */ 	lw	$v0,0x0($s3)
.L0f000714:
/*  f000714:	00008025 */ 	or	$s0,$zero,$zero
/*  f000718:	844c0000 */ 	lh	$t4,0x0($v0)
/*  f00071c:	05820010 */ 	bltzl	$t4,.L0f000760
/*  f000720:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f000724:	84510000 */ 	lh	$s1,0x0($v0)
/*  f000728:	00112400 */ 	sll	$a0,$s1,0x10
.L0f00072c:
/*  f00072c:	00046c03 */ 	sra	$t5,$a0,0x10
/*  f000730:	0fc00170 */ 	jal	func0f0005c0
/*  f000734:	01a02025 */ 	or	$a0,$t5,$zero
/*  f000738:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f00073c:	01d07821 */ 	addu	$t7,$t6,$s0
/*  f000740:	e5e00004 */ 	swc1	$f0,0x4($t7)
/*  f000744:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f000748:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f00074c:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f000750:	87310000 */ 	lh	$s1,0x0($t9)
/*  f000754:	0623fff5 */ 	bgezl	$s1,.L0f00072c
/*  f000758:	00112400 */ 	sll	$a0,$s1,0x10
/*  f00075c:	26730004 */ 	addiu	$s3,$s3,0x4
.L0f000760:
/*  f000760:	0275082b */ 	sltu	$at,$s3,$s5
/*  f000764:	1420ffc8 */ 	bnez	$at,.L0f000688
/*  f000768:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f00076c:	3c048006 */ 	lui	$a0,%hi(var80063970)
/*  f000770:	0fc00164 */ 	jal	func0f000590
/*  f000774:	24843970 */ 	addiu	$a0,$a0,%lo(var80063970)
/*  f000778:	3c118006 */ 	lui	$s1,%hi(var80065ae0)
/*  f00077c:	3c128006 */ 	lui	$s2,%hi(var800662d8)
/*  f000780:	3c138006 */ 	lui	$s3,%hi(var800666c8)
/*  f000784:	3c148006 */ 	lui	$s4,%hi(var80066a70)
/*  f000788:	3c158006 */ 	lui	$s5,%hi(var80066ef0)
/*  f00078c:	3c108006 */ 	lui	$s0,%hi(var80067328)
/*  f000790:	3c168006 */ 	lui	$s6,%hi(var80067428)
/*  f000794:	26d67428 */ 	addiu	$s6,$s6,%lo(var80067428)
/*  f000798:	26107328 */ 	addiu	$s0,$s0,%lo(var80067328)
/*  f00079c:	26b56ef0 */ 	addiu	$s5,$s5,%lo(var80066ef0)
/*  f0007a0:	26946a70 */ 	addiu	$s4,$s4,%lo(var80066a70)
/*  f0007a4:	267366c8 */ 	addiu	$s3,$s3,%lo(var800666c8)
/*  f0007a8:	265262d8 */ 	addiu	$s2,$s2,%lo(var800662d8)
/*  f0007ac:	26315ae0 */ 	addiu	$s1,$s1,%lo(var80065ae0)
.L0f0007b0:
/*  f0007b0:	0fc0014b */ 	jal	func0f00052c
/*  f0007b4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0007b8:	0fc0014b */ 	jal	func0f00052c
/*  f0007bc:	02402025 */ 	or	$a0,$s2,$zero
/*  f0007c0:	0fc0014b */ 	jal	func0f00052c
/*  f0007c4:	02602025 */ 	or	$a0,$s3,$zero
/*  f0007c8:	0fc0014b */ 	jal	func0f00052c
/*  f0007cc:	02802025 */ 	or	$a0,$s4,$zero
/*  f0007d0:	0fc0014b */ 	jal	func0f00052c
/*  f0007d4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0007d8:	0fc0014b */ 	jal	func0f00052c
/*  f0007dc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0007e0:	26100080 */ 	addiu	$s0,$s0,0x80
/*  f0007e4:	26310080 */ 	addiu	$s1,$s1,0x80
/*  f0007e8:	26520080 */ 	addiu	$s2,$s2,0x80
/*  f0007ec:	26730080 */ 	addiu	$s3,$s3,0x80
/*  f0007f0:	26940080 */ 	addiu	$s4,$s4,0x80
/*  f0007f4:	1616ffee */ 	bne	$s0,$s6,.L0f0007b0
/*  f0007f8:	26b50080 */ 	addiu	$s5,$s5,0x80
/*  f0007fc:	3c048006 */ 	lui	$a0,%hi(var80067428)
/*  f000800:	0fc00103 */ 	jal	func0f00040c
/*  f000804:	24847428 */ 	addiu	$a0,$a0,%lo(var80067428)
/*  f000808:	3c048006 */ 	lui	$a0,%hi(var80067a10)
/*  f00080c:	0fc00103 */ 	jal	func0f00040c
/*  f000810:	24847a10 */ 	addiu	$a0,$a0,%lo(var80067a10)
/*  f000814:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f000818:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f00081c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f000820:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f000824:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f000828:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f00082c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f000830:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f000834:	03e00008 */ 	jr	$ra
/*  f000838:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f00083c:	00000000 */ 	sll	$zero,$zero,0x0
);
