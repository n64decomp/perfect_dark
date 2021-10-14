#include <os_internal.h>
#include <R4300.h>

extern u32 __osGlobalIntMask;

void __osSetGlobalIntMask(OSHWIntr mask)
{
	register u32 saveMask = __osDisableInt();
	__osGlobalIntMask |= mask;
	__osRestoreInt(saveMask);
}
