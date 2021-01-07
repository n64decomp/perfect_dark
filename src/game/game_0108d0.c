#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/memory.h"
#include "types.h"

void func0f0108d0(void)
{
	s32 i;

	var8006ae10 = malloc(ALIGN16((IS4MB() ? 30 : 40) * sizeof(struct var8006ae10)), MEMPOOL_STAGE);

	for (i = 0; i < (IS4MB() ? 30 : 40); i++) {
		var8006ae10[i].unk30 = 1;
		var8006ae10[i].audiohandle = NULL;
		var8006ae10[i].unk4c = -1;
	}
}
