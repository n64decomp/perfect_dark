#include <ultra64.h>
#include "constants.h"
#include "game/bg.h"
#include "game/pad.h"
#include "bss.h"
#include "lib/memp.h"
#include "lib/anim.h"
#include "data.h"
#include "types.h"

void roomsReset(void)
{
	s32 i;

	var80082050 = PLAYERCOUNT() >= 2 ? 200 : 120;

	var800a6660 = mempAlloc(ALIGN16(var80082050), MEMPOOL_STAGE);
	var800a6664 = mempAlloc(ALIGN16(var80082050 * sizeof(s16)), MEMPOOL_STAGE);
	var800a6668 = mempAlloc(ALIGN16(var80082050 * sizeof(s16)), MEMPOOL_STAGE);
	var800a666c = mempAlloc(ALIGN16(var80082050 * sizeof(f32)), MEMPOOL_STAGE);
	var800a6670 = mempAlloc(ALIGN16(var80082050 * sizeof(Mtxf)), MEMPOOL_STAGE);

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
