#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "lib/lib_481e0.h"
#include "lib/lib_488e0.h"
#include "lib/lib_491b0.h"
#include "lib/lib_51880.h"
#include "types.h"

GLOBAL_ASM(
glabel func000491b0
/*    491b0:	3c01800a */ 	lui	$at,0x800a
/*    491b4:	240e0000 */ 	addiu	$t6,$zero,0x0
/*    491b8:	240f0000 */ 	addiu	$t7,$zero,0x0
/*    491bc:	ac2fc784 */ 	sw	$t7,-0x387c($at)
/*    491c0:	ac2ec780 */ 	sw	$t6,-0x3880($at)
/*    491c4:	3c01800a */ 	lui	$at,0x800a
/*    491c8:	3c188006 */ 	lui	$t8,%hi(var800608a0)
/*    491cc:	8f1808a0 */ 	lw	$t8,%lo(var800608a0)($t8)
/*    491d0:	ac20c788 */ 	sw	$zero,-0x3878($at)
/*    491d4:	3c01800a */ 	lui	$at,0x800a
/*    491d8:	ac20c78c */ 	sw	$zero,-0x3874($at)
/*    491dc:	3c198006 */ 	lui	$t9,%hi(var800608a0)
/*    491e0:	af180004 */ 	sw	$t8,0x4($t8)
/*    491e4:	8f3908a0 */ 	lw	$t9,%lo(var800608a0)($t9)
/*    491e8:	3c098006 */ 	lui	$t1,%hi(var800608a0)
/*    491ec:	240a0000 */ 	addiu	$t2,$zero,0x0
/*    491f0:	8f280004 */ 	lw	$t0,0x4($t9)
/*    491f4:	240b0000 */ 	addiu	$t3,$zero,0x0
/*    491f8:	3c0c8006 */ 	lui	$t4,%hi(var800608a0)
/*    491fc:	af280000 */ 	sw	$t0,0x0($t9)
/*    49200:	8d2908a0 */ 	lw	$t1,%lo(var800608a0)($t1)
/*    49204:	3c0d8006 */ 	lui	$t5,%hi(var800608a0)
/*    49208:	3c188006 */ 	lui	$t8,%hi(var800608a0)
/*    4920c:	ad2a0010 */ 	sw	$t2,0x10($t1)
/*    49210:	ad2b0014 */ 	sw	$t3,0x14($t1)
/*    49214:	8d8c08a0 */ 	lw	$t4,%lo(var800608a0)($t4)
/*    49218:	8d8e0010 */ 	lw	$t6,0x10($t4)
/*    4921c:	8d8f0014 */ 	lw	$t7,0x14($t4)
/*    49220:	ad8e0008 */ 	sw	$t6,0x8($t4)
/*    49224:	ad8f000c */ 	sw	$t7,0xc($t4)
/*    49228:	8dad08a0 */ 	lw	$t5,%lo(var800608a0)($t5)
/*    4922c:	ada00018 */ 	sw	$zero,0x18($t5)
/*    49230:	8f1808a0 */ 	lw	$t8,%lo(var800608a0)($t8)
/*    49234:	03e00008 */ 	jr	$ra
/*    49238:	af00001c */ 	sw	$zero,0x1c($t8)
);

GLOBAL_ASM(
glabel func0004923c
/*    4923c:	3c0e8006 */ 	lui	$t6,%hi(var800608a0)
/*    49240:	8dce08a0 */ 	lw	$t6,%lo(var800608a0)($t6)
/*    49244:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    49248:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4924c:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    49250:	11ee0054 */ 	beq	$t7,$t6,.L000493a4
/*    49254:	00000000 */ 	sll	$zero,$zero,0x0
.L00049258:
/*    49258:	3c188006 */ 	lui	$t8,%hi(var800608a0)
/*    4925c:	8f1808a0 */ 	lw	$t8,%lo(var800608a0)($t8)
/*    49260:	8f190000 */ 	lw	$t9,0x0($t8)
/*    49264:	17380006 */ 	bne	$t9,$t8,.L00049280
/*    49268:	afb90024 */ 	sw	$t9,0x24($sp)
/*    4926c:	0c014620 */ 	jal	func00051880
/*    49270:	00002025 */ 	or	$a0,$zero,$zero
/*    49274:	3c01800a */ 	lui	$at,0x800a
/*    49278:	1000004a */ 	beqz	$zero,.L000493a4
/*    4927c:	ac20c790 */ 	sw	$zero,-0x3870($at)
.L00049280:
/*    49280:	0c012144 */ 	jal	func00048510
/*    49284:	00000000 */ 	sll	$zero,$zero,0x0
/*    49288:	afa20020 */ 	sw	$v0,0x20($sp)
/*    4928c:	3c09800a */ 	lui	$t1,%hi(var8009c790)
/*    49290:	8d29c790 */ 	lw	$t1,%lo(var8009c790)($t1)
/*    49294:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    49298:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    4929c:	3c01800a */ 	lui	$at,0x800a
/*    492a0:	01095023 */ 	subu	$t2,$t0,$t1
/*    492a4:	afaa001c */ 	sw	$t2,0x1c($sp)
/*    492a8:	ac28c790 */ 	sw	$t0,-0x3870($at)
/*    492ac:	8dee0010 */ 	lw	$t6,0x10($t7)
/*    492b0:	8fab001c */ 	lw	$t3,0x1c($sp)
/*    492b4:	240c0000 */ 	addiu	$t4,$zero,0x0
/*    492b8:	01e0c825 */ 	or	$t9,$t7,$zero
/*    492bc:	01cc082b */ 	sltu	$at,$t6,$t4
/*    492c0:	8def0014 */ 	lw	$t7,0x14($t7)
/*    492c4:	14200016 */ 	bnez	$at,.L00049320
/*    492c8:	01606825 */ 	or	$t5,$t3,$zero
/*    492cc:	018e082b */ 	sltu	$at,$t4,$t6
/*    492d0:	14200003 */ 	bnez	$at,.L000492e0
/*    492d4:	01af082b */ 	sltu	$at,$t5,$t7
/*    492d8:	10200011 */ 	beqz	$at,.L00049320
/*    492dc:	00000000 */ 	sll	$zero,$zero,0x0
.L000492e0:
/*    492e0:	27380010 */ 	addiu	$t8,$t9,0x10
/*    492e4:	afb80018 */ 	sw	$t8,0x18($sp)
/*    492e8:	8f2b0014 */ 	lw	$t3,0x14($t9)
/*    492ec:	8f2a0010 */ 	lw	$t2,0x10($t9)
/*    492f0:	016d082b */ 	sltu	$at,$t3,$t5
/*    492f4:	014c4023 */ 	subu	$t0,$t2,$t4
/*    492f8:	01014023 */ 	subu	$t0,$t0,$at
/*    492fc:	016d4823 */ 	subu	$t1,$t3,$t5
/*    49300:	af290014 */ 	sw	$t1,0x14($t9)
/*    49304:	af280010 */ 	sw	$t0,0x10($t9)
/*    49308:	8fae0024 */ 	lw	$t6,0x24($sp)
/*    4930c:	8dc40010 */ 	lw	$a0,0x10($t6)
/*    49310:	0c0124ed */ 	jal	func000493b4
/*    49314:	8dc50014 */ 	lw	$a1,0x14($t6)
/*    49318:	10000022 */ 	beqz	$zero,.L000493a4
/*    4931c:	00000000 */ 	sll	$zero,$zero,0x0
.L00049320:
/*    49320:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    49324:	8df80000 */ 	lw	$t8,0x0($t7)
/*    49328:	8dea0004 */ 	lw	$t2,0x4($t7)
/*    4932c:	ad580000 */ 	sw	$t8,0x0($t2)
/*    49330:	8fab0024 */ 	lw	$t3,0x24($sp)
/*    49334:	8d6c0004 */ 	lw	$t4,0x4($t3)
/*    49338:	8d6d0000 */ 	lw	$t5,0x0($t3)
/*    4933c:	adac0004 */ 	sw	$t4,0x4($t5)
/*    49340:	8fa80024 */ 	lw	$t0,0x24($sp)
/*    49344:	ad000000 */ 	sw	$zero,0x0($t0)
/*    49348:	8fa90024 */ 	lw	$t1,0x24($sp)
/*    4934c:	ad200004 */ 	sw	$zero,0x4($t1)
/*    49350:	8fb90024 */ 	lw	$t9,0x24($sp)
/*    49354:	8f2e0018 */ 	lw	$t6,0x18($t9)
/*    49358:	11c00005 */ 	beqz	$t6,.L00049370
/*    4935c:	00000000 */ 	sll	$zero,$zero,0x0
/*    49360:	01c02025 */ 	or	$a0,$t6,$zero
/*    49364:	8f25001c */ 	lw	$a1,0x1c($t9)
/*    49368:	0c012238 */ 	jal	osSendMesg
/*    4936c:	00003025 */ 	or	$a2,$zero,$zero
.L00049370:
/*    49370:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    49374:	8df80008 */ 	lw	$t8,0x8($t7)
/*    49378:	8df9000c */ 	lw	$t9,0xc($t7)
/*    4937c:	17000003 */ 	bnez	$t8,.L0004938c
/*    49380:	00000000 */ 	sll	$zero,$zero,0x0
/*    49384:	1320ffb4 */ 	beqz	$t9,.L00049258
/*    49388:	00000000 */ 	sll	$zero,$zero,0x0
.L0004938c:
/*    4938c:	adf80010 */ 	sw	$t8,0x10($t7)
/*    49390:	adf90014 */ 	sw	$t9,0x14($t7)
/*    49394:	0c01250a */ 	jal	func00049428
/*    49398:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    4939c:	1000ffae */ 	beqz	$zero,.L00049258
/*    493a0:	00000000 */ 	sll	$zero,$zero,0x0
.L000493a4:
/*    493a4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    493a8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    493ac:	03e00008 */ 	jr	$ra
/*    493b0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func000493b4
/*    493b4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    493b8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    493bc:	afa40028 */ 	sw	$a0,0x28($sp)
/*    493c0:	0c01256c */ 	jal	__osDisableInt
/*    493c4:	afa5002c */ 	sw	$a1,0x2c($sp)
/*    493c8:	0c012144 */ 	jal	func00048510
/*    493cc:	afa2001c */ 	sw	$v0,0x1c($sp)
/*    493d0:	3c01800a */ 	lui	$at,0x800a
/*    493d4:	ac22c790 */ 	sw	$v0,-0x3870($at)
/*    493d8:	3c0e800a */ 	lui	$t6,%hi(var8009c790)
/*    493dc:	8dcec790 */ 	lw	$t6,%lo(var8009c790)($t6)
/*    493e0:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    493e4:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    493e8:	01c0c825 */ 	or	$t9,$t6,$zero
/*    493ec:	03295821 */ 	addu	$t3,$t9,$t1
/*    493f0:	24180000 */ 	addiu	$t8,$zero,0x0
/*    493f4:	0169082b */ 	sltu	$at,$t3,$t1
/*    493f8:	00385021 */ 	addu	$t2,$at,$t8
/*    493fc:	01485021 */ 	addu	$t2,$t2,$t0
/*    49400:	afaa0020 */ 	sw	$t2,0x20($sp)
/*    49404:	afab0024 */ 	sw	$t3,0x24($sp)
/*    49408:	0c014620 */ 	jal	func00051880
/*    4940c:	01602025 */ 	or	$a0,$t3,$zero
/*    49410:	0c012588 */ 	jal	__osRestoreInt
/*    49414:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*    49418:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    4941c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    49420:	03e00008 */ 	jr	$ra
/*    49424:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func00049428
/*    49428:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*    4942c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    49430:	0c01256c */ 	jal	__osDisableInt
/*    49434:	afa40038 */ 	sw	$a0,0x38($sp)
/*    49438:	3c0e8006 */ 	lui	$t6,%hi(var800608a0)
/*    4943c:	8dce08a0 */ 	lw	$t6,%lo(var800608a0)($t6)
/*    49440:	afa20024 */ 	sw	$v0,0x24($sp)
/*    49444:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    49448:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    4944c:	afaf0034 */ 	sw	$t7,0x34($sp)
/*    49450:	8f090014 */ 	lw	$t1,0x14($t8)
/*    49454:	8f080010 */ 	lw	$t0,0x10($t8)
/*    49458:	afa9002c */ 	sw	$t1,0x2c($sp)
/*    4945c:	11ee0029 */ 	beq	$t7,$t6,.L00049504
/*    49460:	afa80028 */ 	sw	$t0,0x28($sp)
/*    49464:	8dea0010 */ 	lw	$t2,0x10($t7)
/*    49468:	8deb0014 */ 	lw	$t3,0x14($t7)
/*    4946c:	010a082b */ 	sltu	$at,$t0,$t2
/*    49470:	14200024 */ 	bnez	$at,.L00049504
/*    49474:	0148082b */ 	sltu	$at,$t2,$t0
/*    49478:	14200003 */ 	bnez	$at,.L00049488
/*    4947c:	0169082b */ 	sltu	$at,$t3,$t1
/*    49480:	10200020 */ 	beqz	$at,.L00049504
/*    49484:	00000000 */ 	sll	$zero,$zero,0x0
.L00049488:
/*    49488:	27b90028 */ 	addiu	$t9,$sp,0x28
/*    4948c:	8fb80034 */ 	lw	$t8,0x34($sp)
/*    49490:	afb90020 */ 	sw	$t9,0x20($sp)
/*    49494:	8f2d0004 */ 	lw	$t5,0x4($t9)
/*    49498:	8f2c0000 */ 	lw	$t4,0x0($t9)
/*    4949c:	8f0f0014 */ 	lw	$t7,0x14($t8)
/*    494a0:	8f0e0010 */ 	lw	$t6,0x10($t8)
/*    494a4:	3c188006 */ 	lui	$t8,%hi(var800608a0)
/*    494a8:	01af082b */ 	sltu	$at,$t5,$t7
/*    494ac:	018e4023 */ 	subu	$t0,$t4,$t6
/*    494b0:	01014023 */ 	subu	$t0,$t0,$at
/*    494b4:	01af4823 */ 	subu	$t1,$t5,$t7
/*    494b8:	af290004 */ 	sw	$t1,0x4($t9)
/*    494bc:	af280000 */ 	sw	$t0,0x0($t9)
/*    494c0:	8faa0034 */ 	lw	$t2,0x34($sp)
/*    494c4:	8f1808a0 */ 	lw	$t8,%lo(var800608a0)($t8)
/*    494c8:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*    494cc:	1178000d */ 	beq	$t3,$t8,.L00049504
/*    494d0:	afab0034 */ 	sw	$t3,0x34($sp)
/*    494d4:	8fac0028 */ 	lw	$t4,0x28($sp)
/*    494d8:	8d6e0010 */ 	lw	$t6,0x10($t3)
/*    494dc:	8fad002c */ 	lw	$t5,0x2c($sp)
/*    494e0:	8d6f0014 */ 	lw	$t7,0x14($t3)
/*    494e4:	01cc082b */ 	sltu	$at,$t6,$t4
/*    494e8:	1420ffe7 */ 	bnez	$at,.L00049488
/*    494ec:	00000000 */ 	sll	$zero,$zero,0x0
/*    494f0:	018e082b */ 	sltu	$at,$t4,$t6
/*    494f4:	14200003 */ 	bnez	$at,.L00049504
/*    494f8:	01ed082b */ 	sltu	$at,$t7,$t5
/*    494fc:	1420ffe2 */ 	bnez	$at,.L00049488
/*    49500:	00000000 */ 	sll	$zero,$zero,0x0
.L00049504:
/*    49504:	8fb90038 */ 	lw	$t9,0x38($sp)
/*    49508:	8fa80028 */ 	lw	$t0,0x28($sp)
/*    4950c:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*    49510:	3c188006 */ 	lui	$t8,%hi(var800608a0)
/*    49514:	af280010 */ 	sw	$t0,0x10($t9)
/*    49518:	af290014 */ 	sw	$t1,0x14($t9)
/*    4951c:	8f1808a0 */ 	lw	$t8,%lo(var800608a0)($t8)
/*    49520:	8faa0034 */ 	lw	$t2,0x34($sp)
/*    49524:	1158000d */ 	beq	$t2,$t8,.L0004955c
/*    49528:	00000000 */ 	sll	$zero,$zero,0x0
/*    4952c:	254b0010 */ 	addiu	$t3,$t2,0x10
/*    49530:	afab001c */ 	sw	$t3,0x1c($sp)
/*    49534:	8d4d0014 */ 	lw	$t5,0x14($t2)
/*    49538:	8d4c0010 */ 	lw	$t4,0x10($t2)
/*    4953c:	8fae0028 */ 	lw	$t6,0x28($sp)
/*    49540:	8faf002c */ 	lw	$t7,0x2c($sp)
/*    49544:	018e4023 */ 	subu	$t0,$t4,$t6
/*    49548:	01af082b */ 	sltu	$at,$t5,$t7
/*    4954c:	01014023 */ 	subu	$t0,$t0,$at
/*    49550:	01af4823 */ 	subu	$t1,$t5,$t7
/*    49554:	ad490014 */ 	sw	$t1,0x14($t2)
/*    49558:	ad480010 */ 	sw	$t0,0x10($t2)
.L0004955c:
/*    4955c:	8fb90034 */ 	lw	$t9,0x34($sp)
/*    49560:	8fb80038 */ 	lw	$t8,0x38($sp)
/*    49564:	af190000 */ 	sw	$t9,0x0($t8)
/*    49568:	8fab0034 */ 	lw	$t3,0x34($sp)
/*    4956c:	8fad0038 */ 	lw	$t5,0x38($sp)
/*    49570:	8d6c0004 */ 	lw	$t4,0x4($t3)
/*    49574:	adac0004 */ 	sw	$t4,0x4($t5)
/*    49578:	8faf0034 */ 	lw	$t7,0x34($sp)
/*    4957c:	8fae0038 */ 	lw	$t6,0x38($sp)
/*    49580:	8de80004 */ 	lw	$t0,0x4($t7)
/*    49584:	ad0e0000 */ 	sw	$t6,0x0($t0)
/*    49588:	8faa0034 */ 	lw	$t2,0x34($sp)
/*    4958c:	8fa90038 */ 	lw	$t1,0x38($sp)
/*    49590:	ad490004 */ 	sw	$t1,0x4($t2)
/*    49594:	0c012588 */ 	jal	__osRestoreInt
/*    49598:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    4959c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    495a0:	8fa20028 */ 	lw	$v0,0x28($sp)
/*    495a4:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*    495a8:	03e00008 */ 	jr	$ra
/*    495ac:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel __osDisableInt
/*    495b0:	3c0a8006 */ 	lui	$t2,%hi(var8005cf70)
/*    495b4:	254acf70 */ 	addiu	$t2,$t2,%lo(var8005cf70)
/*    495b8:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*    495bc:	316bff00 */ 	andi	$t3,$t3,0xff00
/*    495c0:	40086000 */ 	mfc0	$t0,$12
/*    495c4:	2401fffe */ 	addiu	$at,$zero,-2
/*    495c8:	01014824 */ 	and	$t1,$t0,$at
/*    495cc:	40896000 */ 	mtc0	$t1,$12
/*    495d0:	31020001 */ 	andi	$v0,$t0,0x1
/*    495d4:	8d480000 */ 	lw	$t0,0x0($t2)
/*    495d8:	3108ff00 */ 	andi	$t0,$t0,0xff00
/*    495dc:	110b000e */ 	beq	$t0,$t3,.L00049618
/*    495e0:	3c0a8006 */ 	lui	$t2,%hi(var80060940)
/*    495e4:	254a0940 */ 	addiu	$t2,$t2,%lo(var80060940)
/*    495e8:	8d490118 */ 	lw	$t1,0x118($t2)
/*    495ec:	312aff00 */ 	andi	$t2,$t1,0xff00
/*    495f0:	01485024 */ 	and	$t2,$t2,$t0
/*    495f4:	3c01ffff */ 	lui	$at,0xffff
/*    495f8:	342100ff */ 	ori	$at,$at,0xff
/*    495fc:	01214824 */ 	and	$t1,$t1,$at
/*    49600:	012a4825 */ 	or	$t1,$t1,$t2
/*    49604:	2401fffe */ 	addiu	$at,$zero,-2
/*    49608:	01214824 */ 	and	$t1,$t1,$at
/*    4960c:	40896000 */ 	mtc0	$t1,$12
/*    49610:	00000000 */ 	sll	$zero,$zero,0x0
/*    49614:	00000000 */ 	sll	$zero,$zero,0x0
.L00049618:
/*    49618:	03e00008 */ 	jr	$ra
/*    4961c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel __osRestoreInt
/*    49620:	40086000 */ 	mfc0	$t0,$12
/*    49624:	01044025 */ 	or	$t0,$t0,$a0
/*    49628:	40886000 */ 	mtc0	$t0,$12
/*    4962c:	00000000 */ 	sll	$zero,$zero,0x0
/*    49630:	00000000 */ 	sll	$zero,$zero,0x0
/*    49634:	03e00008 */ 	jr	$ra
/*    49638:	00000000 */ 	sll	$zero,$zero,0x0
/*    4963c:	00000000 */ 	sll	$zero,$zero,0x0
);