#include <ultra64.h>
#include "constants.h"
#include "game/room.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void rooms_tick(void)
{
	s32 i;

	for (i = 0; i < g_RoomMtxNumSlots; i++) {
		if (g_RoomMtxBaseRooms[i] >= 0) {
			g_RoomMtxAges[i]++;

			if (g_RoomMtxAges[i] >= NUM_GFXTASKS) {
				room_free_mtx(i);
			}
		}
	}
}
