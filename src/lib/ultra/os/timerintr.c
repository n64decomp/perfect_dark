#include <libultra_internal.h>
#include "data.h"
#include "bss.h"

OSTimer var8009c760;
OSTime __osCurrentTime;
u32 __osBaseCounter;
u32 __osViIntrCount;
u32 __osTimerCounter;

GLOBAL_ASM(
glabel __osTimerServicesInit
/*    491b0:	3c01800a */ 	lui	$at,%hi(__osCurrentTime)
/*    491b4:	240e0000 */ 	addiu	$t6,$zero,0x0
/*    491b8:	240f0000 */ 	addiu	$t7,$zero,0x0
/*    491bc:	ac2fc784 */ 	sw	$t7,%lo(__osCurrentTime+0x4)($at)
/*    491c0:	ac2ec780 */ 	sw	$t6,%lo(__osCurrentTime)($at)
/*    491c4:	3c01800a */ 	lui	$at,%hi(__osBaseCounter)
/*    491c8:	3c188006 */ 	lui	$t8,%hi(__osTimerList)
/*    491cc:	8f1808a0 */ 	lw	$t8,%lo(__osTimerList)($t8)
/*    491d0:	ac20c788 */ 	sw	$zero,%lo(__osBaseCounter)($at)
/*    491d4:	3c01800a */ 	lui	$at,%hi(__osViIntrCount)
/*    491d8:	ac20c78c */ 	sw	$zero,%lo(__osViIntrCount)($at)
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

// Mismatch: Needs bss relocation for __osCurrentTime
//void __osTimerServicesInit(void)
//{
//	__osCurrentTime = 0;
//	__osBaseCounter = 0;
//	__osViIntrCount = 0;
//
//	__osTimerList->prev = __osTimerList;
//	__osTimerList->next = __osTimerList->prev;
//	__osTimerList->remaining = 0;
//	__osTimerList->interval = __osTimerList->remaining;
//	__osTimerList->mq = NULL;
//	__osTimerList->msg = 0;
//}

void __osTimerInterrupt(void)
{
	OSTimer *t;
	u32 count;
	u32 elapsed_cycles;

	if (__osTimerList->next == __osTimerList) {
		return;
	}

	while (1) {
		t = __osTimerList->next;

		if (t == __osTimerList) {
			__osSetCompare(0);
			__osTimerCounter = 0;
			break;
		}

		count = osGetCount();
		elapsed_cycles = count - __osTimerCounter;
		__osTimerCounter = count;

		if (elapsed_cycles < t->remaining) {
			t->remaining -= elapsed_cycles;
			__osSetTimerIntr(t->remaining);
			return;
		} else {
			t->prev->next = t->next;
			t->next->prev = t->prev;
			t->next = NULL;
			t->prev = NULL;

			if (t->mq != NULL) {
				osSendMesg(t->mq, t->msg, OS_MESG_NOBLOCK);
			}

			if (t->interval != 0) {
				t->remaining = t->interval;
				__osInsertTimer(t);
			}
		}
	}
}

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
