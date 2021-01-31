#include <libultra_internal.h>
#include "game/data/data_000000.h"
#include "gvars/gvars.h"

GLOBAL_ASM(
glabel __osTimerServicesInit
/*    491b0:	3c01800a */ 	lui	$at,%hi(__osCurrentTime+0x4)
/*    491b4:	240e0000 */ 	addiu	$t6,$zero,0x0
/*    491b8:	240f0000 */ 	addiu	$t7,$zero,0x0
/*    491bc:	ac2fc784 */ 	sw	$t7,%lo(__osCurrentTime+0x4)($at)
/*    491c0:	ac2ec780 */ 	sw	$t6,-0x3880($at)
/*    491c4:	3c01800a */ 	lui	$at,%hi(__osBaseCounter)
/*    491c8:	3c188006 */ 	lui	$t8,%hi(__osTimerList)
/*    491cc:	8f1808a0 */ 	lw	$t8,%lo(__osTimerList)($t8)
/*    491d0:	ac20c788 */ 	sw	$zero,%lo(__osBaseCounter)($at)
/*    491d4:	3c01800a */ 	lui	$at,%hi(var8009c78c)
/*    491d8:	ac20c78c */ 	sw	$zero,%lo(var8009c78c)($at)
/*    491dc:	3c198006 */ 	lui	$t9,%hi(__osTimerList)
/*    491e0:	af180004 */ 	sw	$t8,0x4($t8)
/*    491e4:	8f3908a0 */ 	lw	$t9,%lo(__osTimerList)($t9)
/*    491e8:	3c098006 */ 	lui	$t1,%hi(__osTimerList)
/*    491ec:	240a0000 */ 	addiu	$t2,$zero,0x0
/*    491f0:	8f280004 */ 	lw	$t0,0x4($t9)
/*    491f4:	240b0000 */ 	addiu	$t3,$zero,0x0
/*    491f8:	3c0c8006 */ 	lui	$t4,%hi(__osTimerList)
/*    491fc:	af280000 */ 	sw	$t0,0x0($t9)
/*    49200:	8d2908a0 */ 	lw	$t1,%lo(__osTimerList)($t1)
/*    49204:	3c0d8006 */ 	lui	$t5,%hi(__osTimerList)
/*    49208:	3c188006 */ 	lui	$t8,%hi(__osTimerList)
/*    4920c:	ad2a0010 */ 	sw	$t2,0x10($t1)
/*    49210:	ad2b0014 */ 	sw	$t3,0x14($t1)
/*    49214:	8d8c08a0 */ 	lw	$t4,%lo(__osTimerList)($t4)
/*    49218:	8d8e0010 */ 	lw	$t6,0x10($t4)
/*    4921c:	8d8f0014 */ 	lw	$t7,0x14($t4)
/*    49220:	ad8e0008 */ 	sw	$t6,0x8($t4)
/*    49224:	ad8f000c */ 	sw	$t7,0xc($t4)
/*    49228:	8dad08a0 */ 	lw	$t5,%lo(__osTimerList)($t5)
/*    4922c:	ada00018 */ 	sw	$zero,0x18($t5)
/*    49230:	8f1808a0 */ 	lw	$t8,%lo(__osTimerList)($t8)
/*    49234:	03e00008 */ 	jr	$ra
/*    49238:	af00001c */ 	sw	$zero,0x1c($t8)
);

GLOBAL_ASM(
glabel __osTimerInterrupt
/*    4923c:	3c0e8006 */ 	lui	$t6,%hi(__osTimerList)
/*    49240:	8dce08a0 */ 	lw	$t6,%lo(__osTimerList)($t6)
/*    49244:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*    49248:	afbf0014 */ 	sw	$ra,0x14($sp)
/*    4924c:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*    49250:	11ee0054 */ 	beq	$t7,$t6,.L000493a4
/*    49254:	00000000 */ 	nop
.L00049258:
/*    49258:	3c188006 */ 	lui	$t8,%hi(__osTimerList)
/*    4925c:	8f1808a0 */ 	lw	$t8,%lo(__osTimerList)($t8)
/*    49260:	8f190000 */ 	lw	$t9,0x0($t8)
/*    49264:	17380006 */ 	bne	$t9,$t8,.L00049280
/*    49268:	afb90024 */ 	sw	$t9,0x24($sp)
/*    4926c:	0c014620 */ 	jal	__osSetCompare
/*    49270:	00002025 */ 	or	$a0,$zero,$zero
/*    49274:	3c01800a */ 	lui	$at,%hi(__osTimerCounter)
/*    49278:	1000004a */ 	b	.L000493a4
/*    4927c:	ac20c790 */ 	sw	$zero,%lo(__osTimerCounter)($at)
.L00049280:
/*    49280:	0c012144 */ 	jal	osGetCount
/*    49284:	00000000 */ 	nop
/*    49288:	afa20020 */ 	sw	$v0,0x20($sp)
/*    4928c:	3c09800a */ 	lui	$t1,%hi(__osTimerCounter)
/*    49290:	8d29c790 */ 	lw	$t1,%lo(__osTimerCounter)($t1)
/*    49294:	8fa80020 */ 	lw	$t0,0x20($sp)
/*    49298:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    4929c:	3c01800a */ 	lui	$at,%hi(__osTimerCounter)
/*    492a0:	01095023 */ 	subu	$t2,$t0,$t1
/*    492a4:	afaa001c */ 	sw	$t2,0x1c($sp)
/*    492a8:	ac28c790 */ 	sw	$t0,%lo(__osTimerCounter)($at)
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
/*    492dc:	00000000 */ 	nop
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
/*    49310:	0c0124ed */ 	jal	__osSetTimerIntr
/*    49314:	8dc50014 */ 	lw	$a1,0x14($t6)
/*    49318:	10000022 */ 	b	.L000493a4
/*    4931c:	00000000 */ 	nop
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
/*    4935c:	00000000 */ 	nop
/*    49360:	01c02025 */ 	or	$a0,$t6,$zero
/*    49364:	8f25001c */ 	lw	$a1,0x1c($t9)
/*    49368:	0c012238 */ 	jal	osSendMesg
/*    4936c:	00003025 */ 	or	$a2,$zero,$zero
.L00049370:
/*    49370:	8faf0024 */ 	lw	$t7,0x24($sp)
/*    49374:	8df80008 */ 	lw	$t8,0x8($t7)
/*    49378:	8df9000c */ 	lw	$t9,0xc($t7)
/*    4937c:	17000003 */ 	bnez	$t8,.L0004938c
/*    49380:	00000000 */ 	nop
/*    49384:	1320ffb4 */ 	beqz	$t9,.L00049258
/*    49388:	00000000 */ 	nop
.L0004938c:
/*    4938c:	adf80010 */ 	sw	$t8,0x10($t7)
/*    49390:	adf90014 */ 	sw	$t9,0x14($t7)
/*    49394:	0c01250a */ 	jal	__osInsertTimer
/*    49398:	8fa40024 */ 	lw	$a0,0x24($sp)
/*    4939c:	1000ffae */ 	b	.L00049258
/*    493a0:	00000000 */ 	nop
.L000493a4:
/*    493a4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*    493a8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*    493ac:	03e00008 */ 	jr	$ra
/*    493b0:	00000000 */ 	nop
);

void __osSetTimerIntr(OSTime tim)
{
	OSTime NewTime;
	u32 savedMask;

	savedMask = __osDisableInt();

	__osTimerCounter = osGetCount();
	NewTime = tim + __osTimerCounter;
	__osSetCompare(NewTime);

	__osRestoreInt(savedMask);
}

OSTime __osInsertTimer(OSTimer *t)
{
	OSTimer *timep;
	OSTime tim;
	u32 savedMask;

	savedMask = __osDisableInt();

	for (timep = __osTimerList->next, tim = t->remaining;
			timep != __osTimerList && tim > timep->remaining;
			tim -= timep->remaining, timep = timep->next) {
		;
	}

	t->remaining = tim;

	if (timep != __osTimerList) {
		timep->remaining -= tim;
	}

	t->next = timep;
	t->prev = timep->prev;
	timep->prev->next = t;
	timep->prev = t;

	__osRestoreInt(savedMask);

	return tim;
}
