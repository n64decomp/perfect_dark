#include <ultra64.h>
#include "constants.h"
#include "game/body.h"
#include "game/floor.h"
#include "bss.h"
#include "lib/anim.h"
#include "data.h"
#include "types.h"

void bodiesInit(void)
{
	g_NumBondBodies = 0;

	while (g_BondBodies[g_NumBondBodies] >= 0) {
		g_NumBondBodies++;
	}

	g_NumMaleGuardTeamHeads = 0;

	while (g_MaleGuardTeamHeads[g_NumMaleGuardTeamHeads] >= 0) {
		g_NumMaleGuardTeamHeads++;
	}

	g_NumFemaleGuardTeamHeads = 0;

	while (g_FemaleGuardTeamHeads[g_NumFemaleGuardTeamHeads] >= 0) {
		g_NumFemaleGuardTeamHeads++;
	}

	g_NumMaleGuardHeads = 0;

	while (g_MaleGuardHeads[g_NumMaleGuardHeads] >= 0) {
		g_NumMaleGuardHeads++;
	}

	g_NumFemaleGuardHeads = 0;

	while (g_FemaleGuardHeads[g_NumFemaleGuardHeads] >= 0) {
		g_NumFemaleGuardHeads++;
	}
}
