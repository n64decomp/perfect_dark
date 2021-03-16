#include <ultra64.h>
#include "constants.h"
#include "game/game_1668e0.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void func0f01d8c0(void)
{
	s32 i;

	for (i = 0; i < var80082050; i++) {
		if (var800a6668[i] >= 0) {
			var800a6660[i]++;

			if (var800a6660[i] > 1) {
				func0f16696c(i);
			}
		}
	}
}
