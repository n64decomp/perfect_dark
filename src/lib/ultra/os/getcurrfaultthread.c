#include <os_internal.h>
#include "osint.h"

OSThread *__osGetCurrFaultedThread()
{
	return __osFaultedThread;
}
