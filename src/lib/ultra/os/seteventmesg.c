#include <libultra_internal.h>
#include "data.h"
#include "bss.h"

__OSEventState __osEventStateTab[15];

u32 var80060890 = 0;

void osSetEventMesg(OSEvent event, OSMesgQueue *mq, OSMesg msg)
{
	register u32 saveMask = __osDisableInt();
	__OSEventState *es;

	es = &__osEventStateTab[event];
	es->messageQueue = mq;
	es->message = msg;

	if (event == OS_EVENT_PRENMI) {
		if (_osShutdown != 0 && var80060890 == 0) {
			osSendMesg(mq, msg, OS_MESG_NOBLOCK);
		}

		var80060890 = 1;
	}

	__osRestoreInt(saveMask);
}
