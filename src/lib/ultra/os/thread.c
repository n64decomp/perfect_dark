#include <libultra_internal.h>
#include "data.h"

u32 __osThreadTail = 0x00000000;
u32 var80060934 = 0xffffffff;
OSThread *__osRunQueue = (OSThread *)&__osThreadTail;
OSThread *__osActiveQueue = (OSThread *)&__osThreadTail;
OSThread *__osRunningThread = NULL;
OSThread *__osFaultedThread = NULL;

void __osDequeueThread(OSThread **queue, OSThread *t)
{
	register OSThread *pred;
	register OSThread *succ;
	pred = (OSThread *)queue; //this is actually legit..
	succ = pred->next;

	while (succ != NULL) {
		if (succ == t) {
			pred->next = t->next;
			return;
		}

		pred = succ;
		succ = pred->next;
	}
}
