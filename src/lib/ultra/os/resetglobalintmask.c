#include <os_internal.h>
#include <R4300.h>

extern u32 __osGlobalIntMask;

void __osResetGlobalIntMask(OSHWIntr interrupt)
{
	register u32 saveMask = __osDisableInt();

	__osGlobalIntMask &= ~(interrupt & ~(SR_IBIT3 | SR_IE));

	__osRestoreInt(saveMask);
}
