#include <ultra64.h>
#include "constants.h"
#include "game/atan2f.h"
#include "game/padhalllv.h"
#include "bss.h"
#include "lib/portal.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

u8 var8005ef20 = 254;

u8 var8009a4e0[456][2];

void portal_get_centre(s32 portalnum, struct coord *avg)
{
	struct portalvertices *pvertices = (struct portalvertices *)((uintptr_t)g_BgPortals + g_BgPortals[portalnum].verticesoffset);
	f32 f0;
	s32 i;

	avg->x = pvertices->vertices[0].x;
	avg->y = pvertices->vertices[0].y;
	avg->z = pvertices->vertices[0].z;

	f0 = 1.0f / pvertices->count;

	for (i = 1; i < pvertices->count; i++) {
		avg->x += pvertices->vertices[i].x;
		avg->y += pvertices->vertices[i].y;
		avg->z += pvertices->vertices[i].z;
	}

	avg->x *= f0;
	avg->y *= f0;
	avg->z *= f0;
}

#if VERSION < VERSION_NTSC_1_0
bool portal_uses_room_box(s32 portalnum)
{
	return g_BgPortals[portalnum].flags & PORTALFLAG_USEROOMBOX;
}

void portal_set_use_room_box(s32 portalnum)
{
	g_BgPortals[portalnum].flags |= PORTALFLAG_USEROOMBOX;
}

void portal_unset_use_room_box(s32 portalnum)
{
	g_BgPortals[portalnum].flags &= (~PORTALFLAG_USEROOMBOX & 0xff);
}
#endif

/**
 * Add roomnum to the rooms list, provided it's not already there and there's
 * space available at the end of the list.
 *
 * The list is assumed to have 16 slots, with the last being reserved for the
 * -1 terminator.
 */
void portal_append_room(RoomNum *rooms, RoomNum roomnum)
{
	s32 i;

	for (i = 0; i < 16 && rooms[i] != -1; i++) {
		if (rooms[i] == roomnum) {
			return;
		}
	}

	if (i < 15) {
		rooms[i] = roomnum;
		rooms[i + 1] = -1;
	}
}

/**
 * Determine whether a line from pos1 to pos2 intersects the portal,
 * and if so then in which direction.
 *
 * Return one of:
 * PORTALINTERSECTION_NONE
 * PORTALINTERSECTION_BEHINDTOFRONT
 * PORTALINTERSECTION_FRONTTOBEHIND
 *
 * The portal's normal vector is the front.
 */
s32 portal_calculate_intersection(s32 portalnum, struct coord *pos1, struct coord *pos2)
{
	s32 i;
	struct coord sp60;
	struct portalvertices *pvertices;
	struct coord *curr;
	struct coord *next;
	struct coord sp48;
	u8 lastside;
	f32 sp40[1];
	struct coord sp34;
	f32 value1;
	f32 value2;
	f32 tmp;
	u32 stack;

	lastside = 0;
	pvertices = (struct portalvertices *)((uintptr_t)g_BgPortals + g_BgPortals[portalnum].verticesoffset);
	value1 = pos1->f[0] * (g_PortalMetrics + portalnum)->normal.f[0] + pos1->f[1] * (g_PortalMetrics + portalnum)->normal.f[1] + pos1->f[2] * (g_PortalMetrics + portalnum)->normal.f[2];
	value2 = pos2->f[0] * (g_PortalMetrics + portalnum)->normal.f[0] + pos2->f[1] * (g_PortalMetrics + portalnum)->normal.f[1] + pos2->f[2] * (g_PortalMetrics + portalnum)->normal.f[2];

	if (value1 < (g_PortalMetrics + portalnum)->min) {
		if (value2 < (g_PortalMetrics + portalnum)->min) {
			return PORTALINTERSECTION_NONE;
		}
	} else if ((g_PortalMetrics + portalnum)->max < value1 && (g_PortalMetrics + portalnum)->max < value2) {
		return PORTALINTERSECTION_NONE;
	}

	sp60.f[0] = pos2->f[0] - pos1->f[0];
	sp60.f[1] = pos2->f[1] - pos1->f[1];
	sp60.f[2] = pos2->f[2] - pos1->f[2];

	var8007fcb4 = (value1 + value2) * 0.5f - (g_PortalMetrics + portalnum)->min;

	curr = &pvertices->vertices[0];
	next = &pvertices->vertices[1];

	for (i = 0; i < pvertices->count; i++) {
		if (i + 1 == pvertices->count) {
			next = &pvertices->vertices[0];
		}

		sp48.f[0] = next->f[0] - curr->f[0];
		sp48.f[1] = next->f[1] - curr->f[1];
		sp48.f[2] = next->f[2] - curr->f[2];

		sp34.f[0] = sp48.f[1] * sp60.f[2] - sp48.f[2] * sp60.f[1];
		sp34.f[1] = sp48.f[2] * sp60.f[0] - sp48.f[0] * sp60.f[2];
		sp34.f[2] = sp48.f[0] * sp60.f[1] - sp48.f[1] * sp60.f[0];

		tmp = sp34.f[0] * sp34.f[0] + sp34.f[1] * sp34.f[1] + sp34.f[2] * sp34.f[2];

		if (tmp == 0.0f) {
			return PORTALINTERSECTION_NONE;
		}

		sp40[0] = sp34.f[0] * curr->f[0] + sp34.f[1] * curr->f[1] + sp34.f[2] * curr->f[2];
		tmp = sp34.f[0] * pos1->f[0] + sp34.f[1] * pos1->f[1] + sp34.f[2] * pos1->f[2];

		if (tmp < sp40[0]) {
			if (lastside == 2) {
				return PORTALINTERSECTION_NONE;
			}

			lastside = 1;
		} else {
			if (lastside == 1) {
				return PORTALINTERSECTION_NONE;
			}

			lastside = 2;
		}

		curr++;
		next++;
	}

	return (value1 < (g_PortalMetrics + portalnum)->min)
		? PORTALINTERSECTION_BEHINDTOFRONT
		: PORTALINTERSECTION_FRONTTOBEHIND;
}

/**
 * Given frompos, fromrooms and a topos,
 * use portals to figure out the new rooms list.
 *
 * The final rooms are written to finalrooms,
 * which should only ever have 0 or 1 room in it.
 *
 * The caller may optionally pass intersecting and its length,
 * which will be populated with all traversed rooms.
 *
 * This is overengineered. It allows a room to have multiple
 * *overlapping* portals. This is dumb and never happens.
 */
void portal_find_rooms(struct coord *frompos, struct coord *topos, RoomNum *fromrooms, RoomNum *finalrooms, RoomNum *intersecting, s32 maxintersecting)
{
	s32 i;
	s32 j;
	s32 roomnum;
	s32 numportals;
	s16 *portalnums;
	RoomNum srcrooms[16];
	RoomNum foundrooms[16];
	RoomNum allrooms[16];

	for (i = 0; i < 8; i++) {
		srcrooms[i] = fromrooms[i];
		allrooms[i] = fromrooms[i];

		if (fromrooms[i] == -1) {
			break;
		}
	}

	var8005ef20++;

	if (var8005ef20 == 255) {
		for (i = 0; i < g_BgNumPortalCameraCacheItems; i++) {
			var8009a4e0[i][0] = 0xff;
		}

		var8005ef20 = 0;
	}

	// Iterate outwards
	do {
		foundrooms[0] = -1;

		// Iterate source rooms
		for (j = 0; (roomnum = srcrooms[j]) != -1 && j < 16; j++) {
			numportals = g_Rooms[roomnum].numportals;
			portalnums = &g_RoomPortals[g_Rooms[roomnum].roomportallistoffset];

			// Iterate this source room's portals
			for (i = 0; i < numportals; i++) {
				s32 portalnum = *portalnums;
				u8 *s1 = var8009a4e0[portalnum];

				if (s1[0] != var8005ef20) {
					s1[0] = var8005ef20;
					s1[1] = portal_calculate_intersection(portalnum, frompos, topos);
				}

				if (s1[1] != PORTALINTERSECTION_NONE) {
					if (s1[1] == PORTALINTERSECTION_BEHINDTOFRONT) {
						if (roomnum == g_BgPortals[portalnum].roomnum1) {
							portal_append_room(foundrooms, g_BgPortals[portalnum].roomnum2);
							portal_append_room(allrooms, g_BgPortals[portalnum].roomnum2);
							s1[1] = PORTALINTERSECTION_NONE;
						}
					}

					if (s1[1] == PORTALINTERSECTION_FRONTTOBEHIND) {
						if (roomnum == g_BgPortals[portalnum].roomnum2) {
							portal_append_room(foundrooms, g_BgPortals[portalnum].roomnum1);
							portal_append_room(allrooms, g_BgPortals[portalnum].roomnum1);
							s1[1] = PORTALINTERSECTION_NONE;
						}
					}
				}

				portalnums++;
			}
		}

		if (foundrooms[0] == -1) {
			break;
		}

		// Replace srcrooms with the newly found rooms so the newly
		// found rooms are used as the source on the next iteration.
		for (i = 0; i < 16; i++) {
			srcrooms[i] = foundrooms[i];

			if (foundrooms[i] == -1) {
				break;
			}
		}
	} while (foundrooms[0] != -1);

	for (i = 0; i < 7 && srcrooms[i] != -1; i++) {
		finalrooms[i] = srcrooms[i];
	}

	finalrooms[i] = -1;

	if (intersecting != NULL) {
		for (i = 0; i < maxintersecting; i++) {
			intersecting[i] = allrooms[i];

			if (allrooms[i] == -1) {
				break;
			}
		}

		intersecting[i] = -1;
	}
}
