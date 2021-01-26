#include <libultra_internal.h>
#include "game/data/data_000000.h"

void __osResetGlobalIntMask(OSHWIntr interrupt)
{
	register u32 saveMask = __osDisableInt();

	__osGlobalIntMask &= ~(interrupt & ~(SR_IBIT3 | SR_IE));

	__osRestoreInt(saveMask);
}
