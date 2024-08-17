#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/debughud.h"
#include "lib/vm.h"
#include "data.h"
#include "types.h"

void vm_print_stats_if_enabled(void)
{
	char buffer[80];

	if (g_Is4Mb) {
#ifdef DEBUG
		if (g_VmShowStats) {
			dhud_set_fg_colour(0xff, 0xff, 0xff, 0xff);
			dhud_set_bg_colour(0, 0, 0, 0xff);

			sprintf(buffer, "VM: Page Misses %d (%d Replaces)", g_VmNumPageMisses, g_VmNumPageReplaces);
			dhud_set_pos(2, 1);
			dhud_print_string(buffer);

			sprintf(buffer, "VM: TLB Misses %d", g_VmNumTlbMisses);
			dhud_set_pos(2, 2);
			dhud_print_string(buffer);
		}
#endif

		g_VmNumTlbMisses = 0;
		g_VmNumPageMisses = 0;
		g_VmNumPageReplaces = 0;
	}
}
