#include <ultra64.h>
#include "constants.h"
#include "game/chrai.h"
#include "game/chraicommands.h"
#include "game/prop.h"
#include "game/atan2f.h"
#include "game/playermgr.h"
#include "game/mplayer/setup.h"
#include "game/bot.h"
#include "game/challenge.h"
#include "game/training.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/mplayer/scenarios.h"
#include "game/pad.h"
#include "bss.h"
#include "lib/dma.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

/**
 * Find a position inside the given room and populate the pointer arguments with
 * information about the position.
 *
 * Used by bots in King of the Hill scenarios only. The room argument is always
 * a hill room.
 *
 * @bug: There is a possible array overflow in both the covernums and padnums
 * arrays. The for loops stop when the array is full, but the outer loop makes
 * them iterate again, and the check is only at the end of each for loop rather
 * than at the start.
 *
 * For covernums, the three variables declared above it are never written to the
 * stack, so the outer loop would need to iterate three times while covernums is
 * full in order to write into the caller's stack space. The only caller is
 * botTickUnpaused, and its first stack usage is 0x20 where it backs up s0.
 * So the outer loop would need to iterate 11 times before any damage could be
 * done.
 *
 * For padnums, any overflow will write into the rooms array, likely clearing
 * the -1 terminator in rooms[1] and affecting cover selection. Further
 * iterations of the outer loop would write into the cover struct, but this is
 * written before it's read so there's no issue there.
 *
 * It's likely that these don't ever overflow, or they overflow minimally which
 * has no serious effect, but this should be investigated further.
 */
bool botroomFindPos(s16 room, struct coord *pos, f32 *angleptr, s32 *padnumptr, s32 *covernumptr)
{
	s32 i;
	struct waypoint *waypoint;
	s32 waypointnum;
	s32 covernums[40]; /// written to stack
	s32 covercount;
	struct cover cover; // written to stack
	s16 rooms[2]; // written to stack
	s32 padnums[40]; // written to stack
	s32 padcount;
	s32 totalcount;
	struct pad *pad;
	bool sp54;
	bool sp50;
	s32 count;

	covercount = 0;
	padcount = 0;

	sp50 = 0;

	rooms[0] = room;
	rooms[1] = -1;

	totalcount = 0;

	do {
		sp54 = false;
		count = coverGetCount();

		for (i = 0; i < count; i++) {
			if (coverUnpack(i, &cover) && !coverIsSpecial(&cover) && arrayIntersects(cover.rooms, rooms)) {
				if (sp50 && (cover.flags & COVERFLAG_0100)) {
					coverUnsetFlag(i, COVERFLAG_0100);
					covernums[covercount] = i;
					covercount++;
					totalcount++;
				} else if ((cover.flags & COVERFLAG_0100) == 0) {
					covernums[covercount] = i;
					covercount++;
					totalcount++;
				} else {
					sp54 = true;
				}

				if (covercount >= ARRAYCOUNT(covernums)) {
					break;
				}
			}
		}

		if (g_StageSetup.waypoints != NULL) {
			count = g_Rooms[room].numwaypoints;

			for (i = 0; i < count; i++) {
				waypointnum = g_Vars.waypointnums[g_Rooms[room].firstwaypoint + i];
				waypoint = &g_StageSetup.waypoints[waypointnum];

				if (sp50 && (g_Pads[waypoint->padnum].flags & PADFLAG_20000)) {
					padUnsetFlag(waypoint->padnum, PADFLAG_20000);
					padnums[padcount] = waypoint->padnum;
					padcount++;
					totalcount++;
				} else if ((g_Pads[waypoint->padnum].flags & PADFLAG_20000) == 0) {
					padnums[padcount] = waypoint->padnum;
					padcount++;
					totalcount++;
				} else {
					sp54 = true;
				}

				if (padcount >= ARRAYCOUNT(padnums)) {
					break;
				}
			}
		}

		if (1);

		sp50 = sp54;
	} while (sp54 && !totalcount);

	if (!totalcount) {
		return false;
	}

	i = random() % totalcount;

	if (i < covercount) {
		coverUnpack(covernums[i], &cover);

		pos->x = cover.pos->x;
		pos->y = cover.pos->y;
		pos->z = cover.pos->z;

		*angleptr = atan2f(cover.look->z, cover.look->x);
		*padnumptr = -1;
		*covernumptr = covernums[i];
	} else {
		i -= covercount;

		pad = &g_Pads[padnums[i]];

		pos->x = pad->pos.x;
		pos->y = pad->pos.y;
		pos->z = pad->pos.z;

		*angleptr = atan2f(pad->look.z, pad->look.x);
		*padnumptr = padnums[i];
		*covernumptr = -1;
	}

	return true;
}
