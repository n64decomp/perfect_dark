#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/debughud.h"
#include "lib/vm.h"
#include "data.h"
#include "types.h"

void vmPrintStatsIfEnabled(void)
{
	char buffer[80];

	if (g_Is4Mb) {
#ifdef DEBUG
		if (g_VmShowStats) {
			dhudSetFgColour(0xff, 0xff, 0xff, 0xff);
			dhudSetBgColour(0, 0, 0, 0xff);

			sprintf(buffer, "VM: Page Misses %d (%d Replaces)", g_VmNumPageMisses, g_VmNumPageReplaces);
			dhudSetPos(2, 1);
			dhudPrintString(buffer);

			sprintf(buffer, "VM: TLB Misses %d", g_VmNumTlbMisses);
			dhudSetPos(2, 2);
			dhudPrintString(buffer);
		}
#endif

		g_VmNumTlbMisses = 0;
		g_VmNumPageMisses = 0;
		g_VmNumPageReplaces = 0;
	}
}
