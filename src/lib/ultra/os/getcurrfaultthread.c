#include <ultra64.h>
#include "game/data/data_000000.h"

OSThread *__osGetCurrFaultedThread()
{
	return __osFaultedThread;
}
