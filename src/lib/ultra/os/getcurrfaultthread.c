#include <ultra64.h>
#include "data.h"

OSThread *__osGetCurrFaultedThread()
{
	return __osFaultedThread;
}
