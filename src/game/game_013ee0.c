#include <ultra64.h>
#include "constants.h"
#include "game/game_013ee0.h"
#include "game/room.h"
#include "game/pad.h"
#include "bss.h"
#include "lib/memory.h"
#include "lib/lib_233c0.h"
#include "data.h"
#include "types.h"

void func0f013ee0(void)
{
	s32 i;

	var80082050 = PLAYERCOUNT() >= 2 ? 200 : 120;

	var800a6660 = malloc(ALIGN16(var80082050), MEMPOOL_STAGE);
	var800a6664 = malloc(ALIGN16(var80082050 * sizeof(s16)), MEMPOOL_STAGE);
	var800a6668 = malloc(ALIGN16(var80082050 * sizeof(s16)), MEMPOOL_STAGE);
	var800a666c = malloc(ALIGN16(var80082050 * sizeof(f32)), MEMPOOL_STAGE);
	var800a6670 = malloc(ALIGN16(var80082050 * 0x40), MEMPOOL_STAGE);

	for (i = 0; i < PLAYERCOUNT(); i++) {
		g_Vars.players[i]->lastroomforoffset = -1;
	}

	for (i = 0; i < var80082050; i++) {
		var800a6664[i] = -1;
		var800a6660[i] = 2;
		var800a6668[i] = -1;
		var800a666c[i] = 1;
	}

	for (i = 0; i < g_Vars.roomcount; i++) {
		g_Rooms[i].unk10 = -1;
	}
}

void coverAllocateSpecial(u16 *specialcovernums)
{
	s32 i;

	g_SpecialCoverNums = malloc(ALIGN16(g_NumSpecialCovers * sizeof(u16)), MEMPOOL_STAGE);

	if (g_SpecialCoverNums != NULL) {
		for (i = 0; i < g_NumSpecialCovers; i++) {
			g_SpecialCoverNums[i] = specialcovernums[i];
		}
	}
}

void coverLoad(void)
{
	s32 i;
	s32 numcovers = g_PadsFile[1];
	s16 *roomsptr;
	f32 scale = 1;
	struct coord aimpos;
	struct cover cover;
	u16 specialcovernums[1024];
	s16 rooms1[21];
	s16 rooms2[21];

	g_CoverFlags = malloc(ALIGN16(numcovers * sizeof(u16)), MEMPOOL_STAGE);
	g_CoverRooms = malloc(ALIGN16(numcovers * sizeof(s32)), MEMPOOL_STAGE);
	var800a2368 = malloc(ALIGN16(numcovers * 0x10), MEMPOOL_STAGE);

	g_NumSpecialCovers = 0;
	g_SpecialCoverNums = NULL;

	if (g_CoverFlags && g_CoverRooms && var800a2368) {
		for (i = 0; i < numcovers; i++) {
			roomsptr = NULL;
			g_CoverFlags[i] = 0;

			if (coverUnpack(i, &cover)
					&& (cover.look->x != 0.0f || cover.look->y != 0.0f || cover.look->z != 0.0f)) {
				if (coverIsSpecial(&cover)) {
					specialcovernums[g_NumSpecialCovers] = i;
					g_NumSpecialCovers++;
				}

				cover.pos->x *= scale;
				cover.pos->y *= scale;
				cover.pos->z *= scale;

				if (cover.look->x == 1.0f && cover.look->y == 1.0f && cover.look->z == 1.0f) {
					g_CoverFlags[i] |= COVERFLAG_OMNIDIRECTIONAL;
				} else if (!coverIsSpecial(&cover)) {
					struct coord *look = cover.look;
					look->y = 0;
					guNormalize(&look->x, &look->y, &look->z);
				}

				// Find room
				func0f162194(cover.pos, rooms1, rooms2, 20, NULL);

				if (rooms1[0] != -1) {
					roomsptr = rooms1;
				} else if (rooms2[0] != -1) {
					roomsptr = rooms2;
				}

				g_CoverRooms[i] = -1;

				if (roomsptr != NULL) {
					s32 room = func0002a400(cover.pos, roomsptr);

					if (room > 0) {
						g_CoverRooms[i] = (s16)room;
					} else {
						g_CoverRooms[i] = roomsptr[0];
					}
				}

				// Determine if aim is in the same room or not
				if (g_CoverRooms[i] < 0) {
					g_CoverFlags[i] |= COVERFLAG_AIMSAMEROOM;
				} else if ((g_CoverFlags[i] & COVERFLAG_OMNIDIRECTIONAL) == 0) {
					aimpos.x = cover.pos->x + cover.look->f[0] * 600;
					aimpos.y = cover.pos->y;
					aimpos.z = cover.pos->z + cover.look->f[2] * 600;

					func0f162194(&aimpos, rooms1, rooms2, 20, NULL);

					if (rooms1[0] != -1) {
						roomsptr = rooms1;
					} else if (rooms2[0] != -1) {
						roomsptr = rooms2;
					}

					if (roomsptr) {
						s32 aimroom = func0002a400(&aimpos, roomsptr);

						if (aimroom > 0) {
							g_CoverFlags[i] |= (g_CoverRooms[i] == (s16)aimroom) ? COVERFLAG_AIMSAMEROOM : COVERFLAG_AIMDIFFROOM;
						} else {
							g_CoverFlags[i] |= (g_CoverRooms[i] == roomsptr[0]) ? COVERFLAG_AIMSAMEROOM : COVERFLAG_AIMDIFFROOM;
						}
					} else {
						g_CoverFlags[i] |= COVERFLAG_AIMDIFFROOM;
					}
				}
			}
		}

		coverAllocateSpecial(specialcovernums);
	}
}
