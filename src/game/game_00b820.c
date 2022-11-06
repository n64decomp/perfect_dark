#include <ultra64.h>
#include "constants.h"
#include "game/game_00b820.h"
#include "game/playerreset.h"
#include "game/body.h"
#include "game/setuputils.h"
#include "bss.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "data.h"
#include "types.h"

struct prop *g_DangerousProps[MAX_DANGEROUSPROPS];

void resetSomeStageThings(void)
{
	s32 i;

	for (i = 0; i != MAX_DANGEROUSPROPS; i++) {
		g_DangerousProps[i] = NULL;
	}

	g_StageFlags = 0;

	g_EnemyAccuracyScale = 1;
	g_PlayerDamageRxScale = 1;
	g_PlayerDamageTxScale = 1;
	g_AttackWalkDurationScale = 1;

	g_NumChrsSeenPlayerRecently2 = 0;
}
