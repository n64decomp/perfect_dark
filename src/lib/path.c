#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "game/padhalllv.h"
#include "types.h"

void objSetBlockedPathUnblocked(struct defaultobj *blocker, bool unblocked)
{
	if (blocker->hidden & OBJHFLAG_02000000) {
		struct blockedpathobj *bp = g_BlockedPaths;

		while (bp) {
			if (bp->blocker == blocker) {
				if (unblocked) {
					waypointEnableSegment(&g_StageSetup.waypoints[bp->waypoint1], &g_StageSetup.waypoints[bp->waypoint2]);
					break;
				} else {
					waypointDisableSegment(&g_StageSetup.waypoints[bp->waypoint1], &g_StageSetup.waypoints[bp->waypoint2]);
					break;
				}
			}

			bp = bp->next;
		}
	}
}
