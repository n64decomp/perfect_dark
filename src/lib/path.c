#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "game/padhalllv.h"
#include "types.h"

void obj_set_blocked_path_unblocked(struct defaultobj *blocker, bool unblocked)
{
	if (blocker->hidden & OBJHFLAG_BLOCKEDPATH) {
		struct blockedpathobj *bp = g_BlockedPaths;

		while (bp) {
			if (bp->blocker == blocker) {
				if (unblocked) {
					nav_enable_segment(&g_StageSetup.waypoints[bp->waypoint1], &g_StageSetup.waypoints[bp->waypoint2]);
					break;
				} else {
					nav_disable_segment(&g_StageSetup.waypoints[bp->waypoint1], &g_StageSetup.waypoints[bp->waypoint2]);
					break;
				}
			}

			bp = bp->next;
		}
	}
}
