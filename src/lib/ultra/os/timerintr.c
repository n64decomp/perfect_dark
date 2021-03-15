#include <libultra_internal.h>
#include "data.h"
#include "bss.h"

OSTimer var8009c760;
OSTime __osCurrentTime;
u32 __osBaseCounter;
u32 __osViIntrCount;
u32 __osTimerCounter;

void __osTimerServicesInit(void)
{
	__osCurrentTime = 0;
	__osBaseCounter = 0;
	__osViIntrCount = 0;

	__osTimerList->prev = __osTimerList;
	__osTimerList->next = __osTimerList->prev;
	__osTimerList->remaining = 0;
	__osTimerList->interval = __osTimerList->remaining;
	__osTimerList->mq = NULL;
	__osTimerList->msg = 0;
}

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
