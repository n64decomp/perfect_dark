#include <ultra64.h>
#include "constants.h"
#include "game/atan2f.h"
#include "game/padhalllv.h"
#include "bss.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

u8 var8005ef20 = 254;

u8 var8009a4e0[456][2];

void portalGetAvgVertexPos(s32 portalnum, struct coord *avg)
{
	struct portalvertices *pvertices = (struct portalvertices *)((u32)g_BgPortals + g_BgPortals[portalnum].verticesoffset);
	f32 f0;
	s32 i;

	*avg = pvertices->vertices[0];

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
bool portal00018e34nb(s32 portalnum)
{
	return g_BgPortals[portalnum].flags & PORTALFLAG_02;
}

void portal00018e54nb(s32 portalnum)
{
	g_BgPortals[portalnum].flags |= PORTALFLAG_02;
}

void portal00018e74nb(s32 portalnum)
{
	g_BgPortals[portalnum].flags &= (~PORTALFLAG_02 & 0xff);
}
#endif

/**
 * Add roomnum to the rooms list, provided it's not already there and there's
 * space available at the end of the list.
 *
 * The list is assumed to have 16 slots, with the last being reserved for the
 * -1 terminator.
 */
void portal00017dc4(s16 *rooms, s16 roomnum)
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

s32 portal00017e30(s32 portalnum, struct coord *arg1, struct coord *arg2)
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
	pvertices = (struct portalvertices *)((u32)g_BgPortals + g_BgPortals[portalnum].verticesoffset);
	value1 = arg1->f[0] * (var800a4ccc + portalnum)->coord.f[0] + arg1->f[1] * (var800a4ccc + portalnum)->coord.f[1] + arg1->f[2] * (var800a4ccc + portalnum)->coord.f[2];
	value2 = arg2->f[0] * (var800a4ccc + portalnum)->coord.f[0] + arg2->f[1] * (var800a4ccc + portalnum)->coord.f[1] + arg2->f[2] * (var800a4ccc + portalnum)->coord.f[2];

	if (value1 < (var800a4ccc + portalnum)->min) {
		if (value2 < (var800a4ccc + portalnum)->min) {
			return 0;
		}
	} else if ((var800a4ccc + portalnum)->max < value1 && (var800a4ccc + portalnum)->max < value2) {
		return 0;
	}

	sp60.f[0] = arg2->f[0] - arg1->f[0];
	sp60.f[1] = arg2->f[1] - arg1->f[1];
	sp60.f[2] = arg2->f[2] - arg1->f[2];

	var8007fcb4 = (value1 + value2) * 0.5f - (var800a4ccc + portalnum)->min;

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
			return 0;
		}

		sp40[0] = sp34.f[0] * curr->f[0] + sp34.f[1] * curr->f[1] + sp34.f[2] * curr->f[2];
		tmp = sp34.f[0] * arg1->f[0] + sp34.f[1] * arg1->f[1] + sp34.f[2] * arg1->f[2];

		if (tmp < sp40[0]) {
			if (lastside == 2) {
				return 0;
			}

			lastside = 1;
		} else {
			if (lastside == 1) {
				return 0;
			}

			lastside = 2;
		}

		curr++;
		next++;
	}

	return (value1 < (var800a4ccc + portalnum)->min) ? 1 : 2;
}

void portal00018148(struct coord *pos1, struct coord *pos2, s16 *rooms1, s16 *rooms2, s16 *rooms3, s32 arg5)
{
	s32 i;
	s32 j;
	s32 roomnum;
	s32 numportals;
	s16 *portalnums;
	s16 rooms9c[16];
	s16 rooms7c[16];
	s16 rooms5c[16];

	for (i = 0; i < 8; i++) {
		rooms9c[i] = rooms1[i];
		rooms5c[i] = rooms1[i];

		if (rooms1[i] == -1) {
			break;
		}
	}

	var8005ef20++;

	if (var8005ef20 == 255) {
		for (i = 0; i < g_NumPortalThings; i++) {
			var8009a4e0[i][0] = 0xff;
		}

		var8005ef20 = 0;
	}

	do {
		rooms7c[0] = -1;

		for (j = 0; (roomnum = rooms9c[j]) != -1 && j < 16; j++) {
			numportals = g_Rooms[roomnum].numportals;
			portalnums = &g_RoomPortals[g_Rooms[roomnum].roomportallistoffset];

			for (i = 0; i < numportals; i++) {
				s32 portalnum = *portalnums;
				u8 *s1 = var8009a4e0[portalnum];

				if (s1[0] != var8005ef20) {
					s1[0] = var8005ef20;
					s1[1] = portal00017e30(portalnum, pos1, pos2);
				}

				if (s1[1] != 0) {
					if (s1[1] == 1) {
						if (roomnum == g_BgPortals[portalnum].roomnum1) {
							portal00017dc4(rooms7c, g_BgPortals[portalnum].roomnum2);
							portal00017dc4(rooms5c, g_BgPortals[portalnum].roomnum2);
							s1[1] = 0;
						}
					}

					if (s1[1] == 2) {
						if (roomnum == g_BgPortals[portalnum].roomnum2) {
							portal00017dc4(rooms7c, g_BgPortals[portalnum].roomnum1);
							portal00017dc4(rooms5c, g_BgPortals[portalnum].roomnum1);
							s1[1] = 0;
						}
					}
				}

				portalnums++;
			}
		}

		if (rooms7c[0] == -1) {
			break;
		}

		for (i = 0; i < 16; i++) {
			rooms9c[i] = rooms7c[i];

			if (rooms7c[i] == -1) {
				break;
			}
		}
	} while (rooms7c[0] != -1);

	for (i = 0; i < 7 && rooms9c[i] != -1; i++) {
		rooms2[i] = rooms9c[i];
	}

	rooms2[i] = -1;

	if (rooms3 != NULL) {
		for (i = 0; i < arg5; i++) {
			rooms3[i] = rooms5c[i];

			if (rooms5c[i] == -1) {
				break;
			}
		}

		rooms3[i] = -1;
	}
}
