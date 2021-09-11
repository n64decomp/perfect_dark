#include <ultra64.h>
#include "constants.h"
#include "game/game_0125a0.h"
#include "game/game_013ee0.h"
#include "game/bondhead.h"
#include "game/bg.h"
#include "game/pad.h"
#include "bss.h"
#include "lib/lib_159b0.h"
#include "lib/lib_233c0.h"
#include "lib/model.h"
#include "data.h"
#include "types.h"

/**
 * The function assumes that a pad file's data has been loaded from the ROM
 * and is pointed to by g_StageSetup.padfiledata. These pads are in a packed
 * format. During gameplay, the game uses padUnpack as needed to temporarily
 * populate pad structs from this data.
 *
 * padsPrepare prepares the packed data by doing the following:
 * - populates the room field (if -1)
 * - multiplies each pad's bounding box by 1 (this is effectively a no op)
 * - sets the g_StageSetup pad/waygroup/waypoint/cover pointers
 * - promotes file offsets to RAM pointers
 * - does similar things for cover by calling coverPrepare()
 */
void padsPrepare(void)
{
	struct packedpad *packedpad;
	s16 *roomsptr;
	s32 padnum;
	s32 numpads;
	s32 roomnum;
	struct pad pad;
	struct waypoint *waypoint;
	struct waygroup *waygroup;
	s16 sp90[24];
	s16 sp64[22];
	s32 offset;

	g_PadsFile = (struct padsfileheader *)g_StageSetup.padfiledata;
	g_PadOffsets = (u16 *)(g_StageSetup.padfiledata + 0x14);
	padnum = 0;
	numpads = g_PadsFile->numpads;

	for (; padnum < numpads; padnum++) {
		offset = g_PadOffsets[padnum];
		packedpad = (struct packedpad *) &g_StageSetup.padfiledata[offset];
		padUnpack(padnum, PADFIELD_POS | PADFIELD_BBOX, &pad);

		// If room is negative (ie. not specified)
		if (packedpad->room < 0) {
			roomsptr = NULL;
			func0f162194(&pad.pos, sp90, sp64, 20, 0);

			if (sp90[0] != -1) {
				roomsptr = sp90;
			} else if (sp64[0] != -1) {
				roomsptr = sp64;
			}

			if (roomsptr != NULL) {
				roomnum = func0002a400(&pad.pos, roomsptr);

				if (roomnum > 0) {
					packedpad->room = roomnum;
				} else {
					packedpad->room = roomsptr[0];
				}
			}
		}

		// Scale the bbox by 1 and save it back into the packed pad data.
		// Yeah, this is effectively doing nothing.
		if ((*(u32 *) packedpad >> 14) & PADFLAG_HASBBOXDATA) {
			f32 scale = 1;

			pad.bbox.xmin *= scale;
			pad.bbox.xmax *= scale;
			pad.bbox.ymin *= scale;
			pad.bbox.ymax *= scale;
			pad.bbox.zmin *= scale;
			pad.bbox.zmax *= scale;

			padCopyBboxFromPad(padnum, &pad);
		}
	}

	g_StageSetup.waypoints = (struct waypoint *) ((u32)g_StageSetup.padfiledata + g_PadsFile->waypointsoffset);
	g_StageSetup.waygroups = (struct waygroup *) ((u32)g_StageSetup.padfiledata + g_PadsFile->waygroupsoffset);
	g_StageSetup.cover = (void *) ((s32)g_StageSetup.padfiledata + g_PadsFile->coversoffset);

	if (g_StageSetup.cover != NULL) {
		coverPrepare();
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
