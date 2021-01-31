#include <libultra_internal.h>
#include "game/data/data_000000.h"

int osSetTimer(OSTimer *t, OSTime value, OSTime interval, OSMesgQueue *mq, OSMesg msg)
{
	OSTime time;

	t->next = NULL;
	t->prev = NULL;
	t->interval = interval;

	if (value != 0) {
		t->remaining = value;
	} else {
		t->remaining = interval;
	}

	t->mq = mq;
	t->msg = msg;
	time = __osInsertTimer(t);

	if (__osTimerList->next == t) {
		__osSetTimerIntr(time);
	}

	return 0;
}
