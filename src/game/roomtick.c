#include <ultra64.h>
#include "constants.h"
#include "game/room.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void roomsTick(void)
{
	struct roommtx *roommtx = g_RoomMtxesUsed;

	while (roommtx) {
		struct roommtx *next = roommtx->next;

		roommtx->count++;

		if (roommtx->count > 1) {
			room0f16696c(roommtx);
		}

		roommtx = next;
	}
}
