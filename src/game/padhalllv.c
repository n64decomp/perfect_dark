#include <ultra64.h>
#include "constants.h"
#include "game/prop.h"
#include "game/bg.h"
#include "game/pad.h"
#include "game/padhalllv.h"
#include "bss.h"
#include "lib/collision.h"
#include "lib/rng.h"
#include "lib/anim.h"
#include "lib/libc/ll.h"
#include "data.h"
#include "types.h"

u32 g_WaypointHashes[2] = {0};

void waypointSetHashThing(s32 hash1, s32 hash2)
{
	g_WaypointHashes[0] = hash1;
	g_WaypointHashes[1] = hash2;
}

/**
 * Given a position and the rooms it's in, find the closest waypoint, taking
 * into consideration neighbouring rooms and line of sight tests.
 *
 * This is typically called twice prior to route finding; once with the chr's
 * pos to get their starting waypoint and once with the player's pos to get the
 * ending waypoint.
 *
 * Only waypoints within the position's room and its neighbouring rooms are
 * considered. Because of this, any two directly connected waypoints must be
 * in the same or neighbouring rooms.
 *
 * The function will return NULL if there are no waypoints at all within the
 * position's room or its neighbours.
 */
struct waypoint *waypointFindClosestToPos(struct coord *pos, s16 *rooms)
{
	struct waypoint *closest = NULL;
	s16 allrooms[30];
	s32 candlen = 0;
	s16 neighbours[10];
	s32 i;
	s32 j;
	struct waypoint *candwaypoints[10];
	f32 candsqdists[10];
	bool checkmore[10];
	struct coord sp250[10];
	struct coord sp1d8[10];

	for (i = 0; rooms[i] != -1; i++) {
		allrooms[i] = rooms[i];
	}

	allrooms[i] = -1;

	for (i = 0; rooms[i] != -1; i++) {
		roomGetNeighbours(rooms[i], neighbours, ARRAYCOUNT(neighbours));
		roomsAppend(neighbours, allrooms, ARRAYCOUNT(allrooms));
	}

	if (g_StageSetup.waypoints != NULL) {
		// Build the candidates list, sorted by distance (closest first)
		for (i = 0; allrooms[i] != -1; i++) {
			if (g_Rooms[allrooms[i]].numwaypoints != 0) {
				for (j = 0; j < g_Rooms[allrooms[i]].numwaypoints; j++) {
					s32 index = g_Vars.waypointnums[g_Rooms[allrooms[i]].firstwaypoint + j];
					struct waypoint *waypoint = g_StageSetup.waypoints + index;
					f32 sqdist;
					s32 k;
					u32 stack;
					struct pad *pad;

					pad = &g_Pads[waypoint->padnum];

					sqdist = (pos->f[0] - pad->pos.f[0]) * (pos->f[0] - pad->pos.f[0])
						+ (pos->f[1] - pad->pos.f[1]) * (pos->f[1] - pad->pos.f[1])
						+ (pos->f[2] - pad->pos.f[2]) * (pos->f[2] - pad->pos.f[2]);

					// Find the index where this waypoint should go
					// into the candidates list
					for (index = 0; index < candlen; index++) {
						if (sqdist < candsqdists[index]) {
							break;
						}
					}

					// Insert the new candidate
					if (index < ARRAYCOUNT(candwaypoints)) {
						k = candlen - 1;

						if (k > ARRAYCOUNT(candwaypoints) - 2) {
							k = ARRAYCOUNT(candwaypoints) - 2;
						}

						while (k >= index) {
							candwaypoints[k + 1] = candwaypoints[k];
							candsqdists[k + 1] = candsqdists[k];
							k--;
						}

						candwaypoints[index] = waypoint;
						candsqdists[index] = sqdist;

						if (candlen < ARRAYCOUNT(candwaypoints)) {
							candlen++;
						}
					}
				}
			}
		}

		// Check which candidates have line of sight
		for (i = 0; i < candlen; i++) {
			struct pad *pad;
			s16 padrooms[8];

			pad = &g_Pads[candwaypoints[i]->padnum];

			padrooms[0] = pad->room;
			padrooms[1] = -1;

			if (cdTestLos05(pos, rooms, &pad->pos, padrooms, CDTYPE_BG, GEOFLAG_FLOOR1 | GEOFLAG_FLOOR2) != CDRESULT_COLLISION) {
				s32 cdresult = cdExamCylMove05(pos, rooms, &pad->pos, padrooms, CDTYPE_BG | CDTYPE_PATHBLOCKER, true, 0.0f, 0.0f);

				if (cdresult == CDRESULT_ERROR) {
					checkmore[i] = false;
				} else if (cdresult == CDRESULT_COLLISION) {
					checkmore[i] = true;
					cdGetEdge(&sp250[i], &sp1d8[i], 441, "padhalllv.c");
				} else {
					closest = candwaypoints[i];
					break;
				}
			} else {
				checkmore[i] = false;
			}
		}

		if (closest == NULL) {
			// If this is reached, the chr has no line of sight to any waypoint.
			// This should be pretty rare, but it can happen if the pos is
			// inside a lift or out of bounds.
			// This is selecting the first (closest) waypoint that matches some
			// crtieria relating to collisions.
			for (i = 0; i < candlen; i++) {
				if (checkmore[i] && (sp250[i].x != sp1d8[i].x || sp250[i].z != sp1d8[i].z)) {
					s16 padrooms[8];
					struct coord sp98;
					struct coord tmppos;
					s16 tmprooms[8];
					f32 mult;

					padrooms[0] = g_Pads[candwaypoints[i]->padnum].room;
					padrooms[1] = -1;

					sp98.f[0] = sp250[i].x - sp1d8[i].x;
					sp98.f[1] = 0.0f;
					sp98.f[2] = sp250[i].z - sp1d8[i].z;

					mult = 10.0f / sqrtf(sp98.f[0] * sp98.f[0] + sp98.f[2] * sp98.f[2]);

					sp98.x *= mult;
					sp98.z *= mult;

					tmppos.x = sp250[i].f[0] + sp98.f[0];
					tmppos.y = pos->y;
					tmppos.z = sp250[i].f[2] + sp98.f[2];

					if (cdTestCylMove04(pos, rooms, &tmppos, tmprooms, CDTYPE_BG | CDTYPE_PATHBLOCKER, 1, 0.0f, 0.0f) != CDRESULT_COLLISION) {
						closest = candwaypoints[i];
						break;
					}

					tmppos.x = sp1d8[i].x - sp98.x;
					tmppos.y = pos->y;
					tmppos.z = sp1d8[i].z - sp98.z;

					if (cdTestCylMove04(pos, rooms, &tmppos, tmprooms, CDTYPE_BG | CDTYPE_PATHBLOCKER, 1, 0.0f, 0.0f) != CDRESULT_COLLISION) {
						closest = candwaypoints[i];
						break;
					}
				}
			}

			// If the above criteria didn't match anything,
			// just choose the closest waypoint
			if (closest == NULL && candlen > 0) {
				closest = candwaypoints[0];
			}
		}
	}

	return closest;
}

struct waygroup *func0f114810(s32 *groupnums, s32 value, u32 mask)
{
	struct waygroup *groups = g_StageSetup.waygroups;
	struct waygroup *best = NULL;

	while (*groupnums >= 0) {
		if ((*groupnums & mask) == 0) {
			struct waygroup *group = &groups[*groupnums & 0x3fff];

			if (group->unk08 == value) {
				best = group;

				if (!g_Vars.padrandomroutes) {
					break;
				}

				if (!g_WaypointHashes[0] && !g_WaypointHashes[1]) {
					if (random() % 2 == 0) {
						break;
					}
				} else {
					u64 sp50 = ((u64)g_WaypointHashes[0] << 32) | g_WaypointHashes[1];

					if (rngRotateSeed(&sp50) % 2 == 0) {
						break;
					}
				}
			}
		}

		*groupnums++;
	}

	return best;
}

/**
 * For each group number in the given list which matches the mask,
 * assign value to their unk08 if their unk08 has no value (ie. is negative).
 */
void func0f114958(s32 *groupnums, s32 value, u32 mask)
{
	struct waygroup *groups = g_StageSetup.waygroups;

	while (*groupnums >= 0) {
		if ((*groupnums & mask) == 0) {
			struct waygroup *group = &groups[*groupnums & 0x3fff];

			if (group->unk08 < 0) {
				group->unk08 = value;
			}
		}

		groupnums++;
	}
}

/**
 * Iterate the given groups and find any with an unk08 matching arg1.
 * For all groups that match, iterate their neighbouring groups and set their
 * unk08s to arg1 + 1, but only if their groupnum matches the given mask and
 * they have no existing unk08 value.
 *
 * Return true if any matched.
 */
bool func0f1149b0(struct waygroup *group, s32 arg1, u32 mask)
{
	bool result = false;

	while (group->neighbours) {
		if (group->unk08 == arg1) {
			result = true;
			func0f114958(group->neighbours, arg1 + 1, mask);
		}

		group++;
	}

	return result;
}

bool func0f114a2c(struct waygroup *from, struct waygroup *to, struct waygroup *groups, s32 arg3, u32 mask)
{
	bool result = true;
	struct waygroup *group;
	s32 i;

	for (group = groups; group->neighbours; group++) {
		group->unk08 = -1;
	}

	from->unk08 = 0;

	for (i = 0; (arg3 || to->unk08 < 0) && result; i++) {
		result = func0f1149b0(groups, i, mask);
	}

	return result;
}

bool func0f114aec(struct waygroup *from, struct waygroup *to, struct waygroup *groups)
{
	u32 stack[2];
	bool result = func0f114a2c(from, to, groups, 0, 0x8000);

	if (result) {
		struct waygroup *curto = to;
		s32 i = curto->unk08 - 1;

		while (i >= 0) {
			curto->unk08 += 10000;
			curto = func0f114810(curto->neighbours, i, 0x4000);
			i--;
		}

		curto->unk08 += 10000;
	}

	return result;
}

struct waypoint *func0f114b7c(s32 *pointnums, s32 arg1, s32 groupnum, u32 mask)
{
	struct waypoint *points = g_StageSetup.waypoints;
	struct waypoint *best = NULL;

	while (*pointnums >= 0) {
		if ((*pointnums & mask) == 0) {
			struct waypoint *point = &points[*pointnums & 0x3fff];

			if (point->groupnum == groupnum && point->unk0c == arg1) {
				best = point;

				if (!g_Vars.padrandomroutes) {
					break;
				}

				if (!g_WaypointHashes[0] && !g_WaypointHashes[1]) {
					if (random() % 2 == 0) {
						break;
					}
				} else {
					u64 sp50 = ((u64)g_WaypointHashes[0] << 32) | g_WaypointHashes[1];

					if (rngRotateSeed(&sp50) % 2 == 0) {
						break;
					}
				}
			}
		}

		*pointnums++;
	}

	return best;
}

/**
 * For each pointnum, if it matches the mask, belongs to the given group and has
 * no unk0c, set its unk0c to the given value.
 */
void func0f114ccc(s32 *pointnums, s32 value, s32 groupnum, u32 mask)
{
	struct waypoint *waypoints = g_StageSetup.waypoints;

	while (*pointnums >= 0) {
		if ((*pointnums & mask) == 0) {
			struct waypoint *waypoint = &waypoints[*pointnums & 0x3fff];

			if (waypoint->groupnum == groupnum && waypoint->unk0c < 0) {
				waypoint->unk0c = value;
			}
		}

		*pointnums++;
	}
}

bool func0f114d34(s32 *pointnums, s32 arg1, s32 groupnum, u32 mask)
{
	bool result = false;
	struct waypoint *points = g_StageSetup.waypoints;

	while (*pointnums >= 0) {
		struct waypoint *point = &points[*pointnums];

		if (arg1 == point->unk0c && point->neighbours) {
			result = true;
			func0f114ccc(point->neighbours, arg1 + 1, groupnum, mask);
		}

		pointnums++;
	}

	return result;
}

void func0f114de0(struct waypoint *from, struct waypoint *to, s32 arg2, u32 mask)
{
	struct waygroup *groups = g_StageSetup.waygroups;
	struct waypoint *points = g_StageSetup.waypoints;
	struct waypoint *point;
	s32 *pointnums = groups[from->groupnum].waypoints;
	s32 i;
	bool more;

	while (*pointnums >= 0) {
		point = &points[*pointnums];
		point->unk0c = -1;
		pointnums++;
	}

	from->unk0c = 0;

	more = true;

	for (i = 0; (arg2 || to->unk0c < 0) && more; i++) {
		more = func0f114d34(groups[from->groupnum].waypoints, i, from->groupnum, mask);
	}
}

void func0f114ee4(struct waypoint *from, struct waypoint *to)
{
	struct waypoint *curto;
	s32 value;

	func0f114de0(from, to, 0, 0x8000);

	value = to->unk0c - 1;
	curto = to;

	while (value >= 0) {
		curto->unk0c += 10000;
		curto = func0f114b7c(curto->neighbours, value, from->groupnum, 0x4000);

		value--;
	}

	curto->unk0c += 10000;
}

s32 func0f114f70(struct waypoint *from, struct waypoint *to, struct waypoint **arr, s32 arrlen)
{
	struct waypoint **arrptr = arr;
	struct waypoint *curfrom;
	s32 i;

	if (arrlen >= 2) {
		func0f114ee4(from, to);

		*arr = from;
		arrptr++;

		curfrom = from;
		arrlen += 9999;
		i = 10001;

		while (i <= to->unk0c && i < arrlen) {
			curfrom = func0f114b7c(curfrom->neighbours, i, from->groupnum, 0x8000);
			*arrptr = curfrom;
			arrptr++;
			i++;
		}
	}

	*arrptr = NULL;
	arrptr++;

	return arrptr - arr;
}

void func0f11505c(struct waygroup *groupa, struct waygroup *groupb, struct waypoint **pointa, struct waypoint **pointb)
{
	struct waypoint *points = g_StageSetup.waypoints;
	struct waygroup *groups = g_StageSetup.waygroups;
	s32 *groupapointnums = groupa->waypoints;
	s32 stack;

	*pointb = NULL;
	*pointa = NULL;

	while (*groupapointnums >= 0) {
		struct waypoint *groupapoint = &points[*groupapointnums];
		s32 *neighbournums = groupapoint->neighbours;

		while (*neighbournums >= 0) {
			if ((*neighbournums & 0x8000) == 0) {
				struct waypoint *neighbour = &points[*neighbournums & 0x3fff];

				if (groupb == &groups[neighbour->groupnum]) {
					*pointa = groupapoint;
					*pointb = neighbour;

					if (!g_Vars.padrandomroutes) {
						break;
					}

					if (!g_WaypointHashes[0] && !g_WaypointHashes[1]) {
						if (random() % 2 == 0) {
							break;
						}
					} else {
						u64 sp50 = ((u64)g_WaypointHashes[0] << 32) | g_WaypointHashes[1];

						if ((rngRotateSeed(&sp50) % 2) == 0) {
							break;
						}
					}
				}
			}

			neighbournums++;
		}

		groupapointnums++;
	}
}

/**
 * Find a route from frompoint to topoint. The arr argument will be populated
 * with pointers to the route's waypoints. If arr is not big enough then only
 * the first part of the route will be populated into the array.
 *
 * The return value is the number of elements populated into the array.
 */
s32 waypointFindRoute(struct waypoint *frompoint, struct waypoint *topoint, struct waypoint **arr, s32 arrlen)
{
	struct waypoint **arrptr = arr;
	struct waygroup *groups = g_StageSetup.waygroups;

	if (groups && frompoint && topoint) {
		struct waygroup *fromgroup = &groups[frompoint->groupnum];
		struct waygroup *togroup = &groups[topoint->groupnum];

		if (func0f114aec(fromgroup, togroup, groups)) {
			struct waypoint *curfrompoint = frompoint;
			struct waygroup *curfromgroup = fromgroup;
			s32 i;

			for (i = fromgroup->unk08 + 1; i <= togroup->unk08 && arrlen >= 2; i++) {
				s32 numwritten;
				struct waygroup *nextfromgroup = func0f114810(curfromgroup->neighbours, i, 0x8000);
				struct waypoint *tmppoint;
				struct waypoint *nextfrompoint;

				func0f11505c(curfromgroup, nextfromgroup, &tmppoint, &nextfrompoint);
				numwritten = func0f114f70(curfrompoint, tmppoint, arrptr, arrlen) - 1;

				arrlen -= numwritten;
				arrptr += numwritten;

				curfrompoint = nextfrompoint;
				curfromgroup = nextfromgroup;
			}

			arrptr += func0f114f70(curfrompoint, topoint, arrptr, arrlen) - 1;
		}
	}

	*arrptr = NULL;
	arrptr++;

	return arrptr - arr;
}

void func0f115390(void)
{
	struct waypoint *waypoint = g_StageSetup.waypoints;

	while (waypoint->padnum >= 0) {
		waypoint->unk0c = -1;
		waypoint++;
	}
}

struct waypoint *func0f1153c4(s32 *pointnums, s32 arg1)
{
	s32 len = 0;
	s32 randomindex;
	s32 i;

	while (pointnums[len] >= 0) {
		len++;
	}

	// This is effectively randomly dividing the pointnums list into two,
	// then checking the upper portion before the lower portion. Both loops
	// have the same logic so this seems unusual, but there is reason to do
	// this if they want the returned waypoint to be any random waypoint that
	// meets the arg1 criteria, with equal weighting.

	randomindex = random() % len;

	for (i = randomindex; i < len; i++) {
		struct waypoint *point = &g_StageSetup.waypoints[pointnums[i] & 0x3fff];

		if (point->unk0c == arg1) {
			return point;
		}
	}

	for (i = 0; i < randomindex; i++) {
		struct waypoint *point = &g_StageSetup.waypoints[pointnums[i] & 0x3fff];

		if (point->unk0c == arg1) {
			return point;
		}
	}

	return NULL;
}

struct waygroup *func0f1154cc(s32 *groupnums, s32 arg1)
{
	s32 len = 0;
	s32 randomindex;
	s32 i;

	while (groupnums[len] >= 0) {
		len++;
	}

	// Similar to the above function, return a random waygroup
	// which matches the arg1 criteria.
	randomindex = random() % len;

	for (i = randomindex; i < len; i++) {
		struct waygroup *group = &g_StageSetup.waygroups[groupnums[i] & 0x3fff];

		if (group->unk08 == arg1) {
			return group;
		}
	}

	for (i = 0; i < randomindex; i++) {
		struct waygroup *group = &g_StageSetup.waygroups[groupnums[i] & 0x3fff];

		if (group->unk08 == arg1) {
			return group;
		}
	}

	return NULL;
}

struct waypoint *func0f1155e0(struct waypoint *pointa, struct waypoint *pointb)
{
	if (g_StageSetup.waygroups) {
		struct waygroup *groupa = &g_StageSetup.waygroups[pointa->groupnum];
		struct waygroup *groupb = &g_StageSetup.waygroups[pointb->groupnum];
		struct waypoint *result;
		s32 stack;

		if (groupa == groupb) {
			func0f115390();
			func0f114de0(pointb, pointa, 1, 0);

			result = func0f1153c4(pointa->neighbours, -1);

			if (result) {
				return result;
			}

			result = func0f1153c4(pointa->neighbours, pointa->unk0c + 1);

			if (result) {
				return result;
			}
		} else {
			func0f114a2c(groupb, groupa, g_StageSetup.waygroups, 0, 0x8000);

			if (groupa->unk08 >= 0) {
				struct waygroup *tmpgroup = func0f1154cc(groupa->neighbours, -1);

				if (tmpgroup) {
					struct waypoint *sp48;
					struct waypoint *sp44;
					struct waypoint *arr[3];

					func0f11505c(groupa, tmpgroup, &sp48, &sp44);

					if (sp48 == pointa) {
						return sp44;
					}

					if (func0f114f70(pointa, sp48, arr, 3) >= 3) {
						return arr[1];
					}
				} else {
					struct waygroup *tmpgroup = func0f114810(groupa->neighbours, groupa->unk08 - 1, 0x8000);

					if (tmpgroup) {
						struct waypoint *sp30;
						struct waypoint *sp2c;

						func0f11505c(groupa, tmpgroup, &sp30, &sp2c);
						func0f114de0(sp30, pointa, 1, 0);
						result = func0f114b7c(pointa->neighbours, pointa->unk0c + 1, pointa->groupnum, 0x8000);

						if (result) {
							return result;
						}
					}
				}
			}
		}
	}

	return NULL;
}

/**
 * Disable the segment from A to B.
 *
 * This works by removing B from A's neighbour list. If B isn't a neighbour of
 * A (ie. segment is already disabled) then no operation is performed.
 *
 * Once B is removed from A's list, the function then updates the group
 * neighbours too. If the segment being removed is the last link between
 * A's group and B's group then group B is removed from group A's neighbour
 * list.
 */
void waypointDisableSegmentInDirection(struct waypoint *a, struct waypoint *b)
{
	struct waygroup *agroup = &g_StageSetup.waygroups[a->groupnum];
	s32 bindex = b - g_StageSetup.waypoints;
	s32 bgroupnum = b->groupnum;
	bool foundlink = false;
	s32 i;
	s32 j;
	s32 tmp;

	// Find index of the neighbour point to remove, or index of end if not found
	for (i = 0; (tmp = a->neighbours[i]) >= 0 && (tmp & 0x3fff) != bindex; i++);

	// If neighbour was found, shuffle the rest of the neighbour list back by
	// one, effectively removing it.
	if ((tmp & 0x3fff) == bindex) {
		for (; a->neighbours[i] >= 0; i++) {
			a->neighbours[i] = a->neighbours[i + 1];
		}
	}

	// Check if group A still contains any waypoints who have neighbours in
	// group B.
	for (i = 0; (tmp = agroup->waypoints[i]) >= 0 && !foundlink; i++) {
		struct waypoint *apoint = &g_StageSetup.waypoints[tmp];

		for (j = 0; (tmp = apoint->neighbours[j]) >= 0 && !foundlink; j++) {
			struct waypoint *neighbour = &g_StageSetup.waypoints[tmp & 0x3fff];

			if (neighbour->groupnum == bgroupnum) {
				foundlink = true;
			}
		}
	}

	// If no link was found, remove group B from group A's neighbour list
	if (!foundlink) {
		for (i = 0; (tmp = agroup->neighbours[i]) >= 0 && (tmp & 0x3fff) != bgroupnum; i++);

		if ((tmp & 0x3fff) == bgroupnum) {
			for (; agroup->neighbours[i] >= 0; i++) {
				agroup->neighbours[i] = agroup->neighbours[i + 1];
			}
		}
	}
}

/**
 * Enable the segment from A to B.
 *
 * This works by adding B to A's neighbour list. If B is already a neighbour of
 * A (ie. segment is already enabled) then no operation is performed.
 *
 * This code assumes that A's neighbours array is big enough to add the new
 * neighbour, which it will be if B was disabled previously.
 */
void waypointEnableSegmentInDirection(struct waypoint *a, struct waypoint *b)
{
	struct waygroup *agroup = &g_StageSetup.waygroups[a->groupnum];
	s32 bpointnum = b - g_StageSetup.waypoints;
	s32 bgroupnum = b->groupnum;
	s32 neighbournum;
	s32 i;

	// Find index in A's neighbour list where B can be added.
	// This will either be at the -1 terminator, or if B already exists in the
	// list then the index of B.
	for (i = 0; (neighbournum = a->neighbours[i]) >= 0 && (neighbournum & 0x3fff) != bpointnum; i++);

	// Add B to A's neighbour list if it doesn't exist
	if ((neighbournum & 0x3fff) != bpointnum) {
		a->neighbours[i] = bpointnum;
		a->neighbours[i + 1] = -1;
	}

	// Now the same for groups. Make sure B's group is a neighbour of A's group.
	for (i = 0; (neighbournum = agroup->neighbours[i]) >= 0 && (neighbournum & 0x3fff) != bgroupnum; i++);

	if (bgroupnum != (neighbournum & 0x3fff)) {
		agroup->neighbours[i] = bgroupnum;
		agroup->neighbours[i + 1] = -1;
	}
}

void waypointDisableSegment(struct waypoint *a, struct waypoint *b)
{
	waypointDisableSegmentInDirection(a, b);
	waypointDisableSegmentInDirection(b, a);
}

void waypointEnableSegment(struct waypoint *a, struct waypoint *b)
{
	waypointEnableSegmentInDirection(a, b);
	waypointEnableSegmentInDirection(b, a);
}
