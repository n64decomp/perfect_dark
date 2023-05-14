#include <ultra64.h>
#include "constants.h"
#include "game/room.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void roomsTick(void)
{
	s32 i;

	for (i = 0; i < g_RoomMtxNumSlots; i++) {
		if (g_RoomMtxBaseRooms[i] >= 0) {
			g_RoomMtxAges[i]++;

			if (g_RoomMtxAges[i] >= NUM_GFXTASKS) {
				roomFreeMtx(i);
			}
		}
	}
}
