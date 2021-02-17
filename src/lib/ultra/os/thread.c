#include <libultra_internal.h>
#include "data.h"

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
