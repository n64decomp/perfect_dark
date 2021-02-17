#include <ultra64.h>
#include "constants.h"
#include "game/pad.h"
#include "gvars/gvars.h"
#include "lib/memory.h"
#include "data.h"
#include "types.h"

void waypointsLoad(void)
{
	struct waypoint *waypoints;
	s32 numwaypoints;
	struct waypoint *waypoint;
	struct waypoint *waypoint2;
	s32 numinserted;
	s32 j;
	s32 k;
	struct pad pad;
	struct pad pad2;
	s32 i;
	s32 currentroom;

	// Count the number of waypoints. The "waypoints" pointer is mostly used in
	// this function to point to the head of the waypoints array, but is being
	// reused here to iterate the waypoints one at a time.
	waypoints = g_StageSetup.waypoints;

	for (numwaypoints = 0; waypoints->padnum >= 0; numwaypoints++) {
		waypoints++;
	}

	waypoints = g_StageSetup.waypoints;

	// Allocate memory for the waypoint numbers array
	g_Vars.waypointnums = malloc(ALIGN16(numwaypoints * sizeof(s16)), MEMPOOL_STAGE);

	numinserted = 0;

	// Populate g_Vars.waypointnums, ordering them by roomnum asc, padnum asc
	for (i = 0; i < numwaypoints; i++) {
		waypoint = &waypoints[i];
		padUnpack(waypoint->padnum, PADFIELD_ROOM | PADFIELD_FLAGS, &pad);

		// Iterate previously processed waypoints and bail if the outer loop's
		// waypoint should be inserted prior to this one
		for (j = 0; j < numinserted; j++) {
			waypoint2 = &waypoints[g_Vars.waypointnums[j]];
			padUnpack(waypoint2->padnum, PADFIELD_ROOM | PADFIELD_FLAGS, &pad2);

			if (pad.room < pad2.room) {
				break;
			}

			if (pad.room == pad2.room
					&& ((pad2.flags & PADFLAG_AIDROP) || waypoint->padnum < waypoint2->padnum)) {
				break;
			}
		}

		// Move elements forward in the ordered array and then insert
		for (k = numinserted - 1; k >= j; k--) {
			g_Vars.waypointnums[k + 1] = g_Vars.waypointnums[k];
		}

		g_Vars.waypointnums[j] = i;
		numinserted++;
	}

	// Next, populate the properties in each room that are related to waypoints.
	// Start by resetting them in all rooms, then iterate the waypoints in
	// order and calculate them.
	for (i = 0; i < g_Vars.roomcount; i++) {
		g_Rooms[i].numwaypoints = 0;
		g_Rooms[i].firstwaypoint = 0;
	}

	currentroom = -1;

	for (i = 0; i < numwaypoints; i++) {
		waypoint = &g_StageSetup.waypoints[g_Vars.waypointnums[i]];
		padUnpack(waypoint->padnum, PADFIELD_ROOM | PADFIELD_FLAGS, &pad);

		if (pad.room != currentroom) {
			currentroom = pad.room;
			g_Rooms[currentroom].firstwaypoint = i;
		}

		if ((pad.flags & PADFLAG_AIDROP) == 0 && currentroom != -1) {
			g_Rooms[currentroom].numwaypoints++;
		}
	}

	g_Vars.padrandomroutes = true;
}
