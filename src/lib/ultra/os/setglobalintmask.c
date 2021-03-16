#include <libultra_internal.h>
#include "data.h"

void __osSetGlobalIntMask(OSHWIntr mask)
{
	register u32 saveMask = __osDisableInt();
	__osGlobalIntMask |= mask;
	__osRestoreInt(saveMask);
}
