#include <ultra64.h>
#include "constants.h"
#include "game/bondhead.h"
#include "game/bg.h"
#include "game/pad.h"
#include "game/setup.h"
#include "bss.h"
#include "lib/collision.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/model.h"
#include "data.h"
#include "types.h"

/**
 * The function assumes that a pad file's data has been loaded from the ROM
 * and is pointed to by g_StageSetup.padfiledata. These pads are in a packed
 * format. During gameplay, the game uses padUnpack as needed to temporarily
 * populate pad structs from this data.
 *
 * setupPreparePads prepares the packed data by doing the following:
 * - populates the room field (if -1)
 * - multiplies each pad's bounding box by 1 (this is effectively a no op)
 * - sets the g_StageSetup pad/waygroup/waypoint/cover pointers
 * - promotes file offsets to RAM pointers
 * - does similar things for cover by calling setupPrepareCover()
 */
void setupPreparePads(void)
{
	struct packedpad *packedpad;
	s16 *roomsptr;
	s32 padnum;
	s32 numpads;
	s32 roomnum;
	struct pad pad;
	struct waypoint *waypoint;
	struct waygroup *waygroup;
	s16 inrooms[24];
	s16 aboverooms[22];
	s32 offset;

	g_PadsFile = (struct padsfileheader *)g_StageSetup.padfiledata;
	g_Pads = (struct pad *)(g_StageSetup.padfiledata + 0x14);
	padnum = 0;
	numpads = g_PadsFile->numpads;

	for (; padnum < numpads; padnum++) {
		padUnpack(padnum, PADFIELD_POS | PADFIELD_BBOX, &pad);

		// If room is negative (ie. not specified)
		if (g_Pads[padnum].room < 0) {
			roomsptr = NULL;
			bgFindRoomsByPos(&pad.pos, inrooms, aboverooms, 20, NULL);

			if (inrooms[0] != -1) {
				roomsptr = inrooms;
			} else if (aboverooms[0] != -1) {
				roomsptr = aboverooms;
			}

			if (roomsptr != NULL) {
				roomnum = cdFindFloorRoomAtPos(&pad.pos, roomsptr);

				if (roomnum > 0) {
					g_Pads[padnum].room = roomnum;
				} else {
					g_Pads[padnum].room = roomsptr[0];
				}
			}
		}
	}

	g_StageSetup.waypoints = (struct waypoint *) ((u32)g_StageSetup.padfiledata + g_PadsFile->waypointsoffset);
	g_StageSetup.waygroups = (struct waygroup *) ((u32)g_StageSetup.padfiledata + g_PadsFile->waygroupsoffset);
	g_StageSetup.cover = (void *) ((s32)g_StageSetup.padfiledata + g_PadsFile->coversoffset);

	if (g_StageSetup.cover != NULL) {
		setupPrepareCover();
	}

	// Promote offsets to pointers in waypoints
	waypoint = g_StageSetup.waypoints;

	while (waypoint->padnum >= 0) {
		waypoint->neighbours = (s32 *)((u32)g_StageSetup.padfiledata + (u32)waypoint->neighbours);
		waypoint++;
	}

	// Promote offsets to pointers in waygroups
	waygroup = g_StageSetup.waygroups;

	while (waygroup->neighbours != NULL) {
		waygroup->neighbours = (s32 *)((u32)g_StageSetup.padfiledata + (u32)waygroup->neighbours);
		waygroup->waypoints = (s32 *)((u32)g_StageSetup.padfiledata + (u32)waygroup->waypoints);
		waygroup++;
	}
}
