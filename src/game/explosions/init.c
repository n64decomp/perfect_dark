#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "lib/memory.h"
#include "data.h"
#include "types.h"

void explosionsInit(void)
{
	s32 i;
	s32 j;

	var8007e4a0 = 0;
	var8007e4a4 = 0;
	var8007e4a8 = 1;

	g_MaxExplosions = 6;

	if (g_Vars.stagenum >= STAGE_TITLE) {
		g_MaxExplosions = 0;
	}

	if (g_MaxExplosions == 0) {
		g_Explosions = NULL;
	} else {
		g_Explosions = malloc((g_MaxExplosions * sizeof(struct explosion) + 0xf) & ~0xf, MEMPOOL_STAGE);

		for (i = 0; i < g_MaxExplosions; i++) {
			g_Explosions[i].prop = NULL;

			for (j = 0; j < ARRAYCOUNT(g_Explosions[i].parts); j++) {
				g_Explosions[i].parts[j].frame = 0;
			}
		}
	}
}
