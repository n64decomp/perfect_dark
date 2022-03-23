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
		if (var800a6668[i] >= 0) {
			var800a6660[i]++;

			if (var800a6660[i] > 1) {
				room0f16696c(i);
			}
		}
	}
}
