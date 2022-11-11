#include <ultra64.h>
#include "constants.h"
#include "game/room.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void langTick(void)
{
	s32 i;

	if (g_Jpn) {
		for (i = 0; i != 124; i++) {
			if (var800aabb8[i].unk00_00) {
				var800aabb8[i].unk00_00--;
			}
		}
	}
}
