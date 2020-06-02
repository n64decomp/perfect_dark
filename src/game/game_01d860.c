#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_1668e0.h"
#include "gvars/gvars.h"
#include "types.h"

void func0f01d860(void)
{
	s32 i;

	if (g_LanguageId != LANGUAGE_ENGLISH) {
		for (i = 0; i != 124; i++) {
			if (var800aabb8[i].unk00_00) {
				var800aabb8[i].unk00_00--;
			}
		}
	}
}

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
