#include <libultra_internal.h>
#include "game/data/data_000000.h"
#include "gvars/gvars.h"

void osSetEventMesg(OSEvent event, OSMesgQueue *mq, OSMesg msg)
{
	register u32 saveMask = __osDisableInt();
	__OSEventState *es;

	es = &__osEventStateTab[event];
	es->messageQueue = mq;
	es->message = msg;

	if (event == OS_EVENT_PRENMI) {
		if (var8005cf6c != 0 && var80060890 == 0) {
			osSendMesg(mq, msg, OS_MESG_NOBLOCK);
		}

		var80060890 = 1;
	}

	__osRestoreInt(saveMask);
}
