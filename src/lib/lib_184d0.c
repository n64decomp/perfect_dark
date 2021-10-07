#include <ultra64.h>
#include "constants.h"
#include "game/atan2f.h"
#include "game/padhalllv.h"
#include "bss.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_184d0.h"
#include "data.h"
#include "types.h"

s32 g_NumGlobalAilists = 0;
s32 g_NumLvAilists = 0;

u8 *ailistFindById(s32 ailistid)
{
	s32 lower;
	s32 upper;
	s32 index;

	if (ailistid >= 0x401) {
		if (g_StageSetup.ailists) {
			lower = 0;
			upper = g_NumLvAilists;
			index;

			while (upper >= lower) {
				index = (lower + upper) / 2;

				if (g_StageSetup.ailists[index].id == ailistid) {
					return g_StageSetup.ailists[index].list;
				}

				if (ailistid < g_StageSetup.ailists[index].id) {
					upper = index - 1;
				} else {
					lower = index + 1;
				}
			}
		}
	} else {
		lower = 0;
		upper = g_NumGlobalAilists;
		index;

		while (upper >= lower) {
			index = (lower + upper) / 2;

			if (g_GlobalAilists[index].id == ailistid) {
				return g_GlobalAilists[index].list;
			}

			if (ailistid < g_GlobalAilists[index].id) {
				upper = index - 1;
			} else {
				lower = index + 1;
			}
		}
	}

	return NULL;
}

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
