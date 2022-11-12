#include <ultra64.h>
#include "constants.h"
#include "game/room.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void roomsTick(void)
{
	s32 i;

	for (i = 0; i < var80082050; i++) {
		if (g_RoomMtxes[i].room2 >= 0) {
			g_RoomMtxes[i].count++;

			if (g_RoomMtxes[i].count > 1) {
				room0f16696c(i);
			}
		}
	}
}
