#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void casingsReset(void)
{
	s32 i;
	struct casing *end;
	struct casing *casing;

	var8009d0d0[0] = 0;
	var8009d0d0[1] = 0;
	var8009d0d8 = 0;

	for (i = 0; i != ARRAYCOUNT(g_BgunAudioHandles); i++) {
		g_BgunAudioHandles[i] = 0;
	}

	end = g_Casings + ARRAYCOUNT(g_Casings);
	casing = g_Casings;

	while (casing < end) {
		casing->unk40 = 0;
		casing++;
	}

	g_CasingsActive = 0;

	for (i = 0; i < ARRAYCOUNT(g_Fireslots); i++) {
		g_Fireslots[i].endlvframe = -1;
	}

	g_Vars.killcount = 0;
	g_Vars.knockoutcount = 0;
}
