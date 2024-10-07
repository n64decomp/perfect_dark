#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

void vtxstore_reset(void)
{
	s32 i;
	s32 j;
	s32 numbatches;
	s32 maxunits;

	for (i = 0; i < ARRAYCOUNT(g_VtxstoreTypes); i++) {
		if (PLAYERCOUNT() >= 2) {
			maxunits = g_VtxstoreTypes[i].mpmaxunits;
			numbatches = g_VtxstoreTypes[i].mpnumbatches;
		} else if (g_Vars.stagenum >= STAGE_TITLE) {
			maxunits = g_VtxstoreTypes[i].othermaxunits;
			numbatches = g_VtxstoreTypes[i].othernumbatches;
		} else {
			maxunits = g_VtxstoreTypes[i].spmaxunits;
			numbatches = g_VtxstoreTypes[i].spnumbatches;
		}

		if (numbatches > 0) {
			g_VtxstoreTypes[i].batches = memp_alloc(numbatches * sizeof(struct vtxstorebatch), MEMPOOL_STAGE);
		}

		for (j = 0; j < numbatches; j++) {
			g_VtxstoreTypes[i].batches[j].refcount = 0;
		}

		g_VtxstoreTypes[i].numbatches = numbatches;
		g_VtxstoreTypes[i].numunitsmax = maxunits;
		g_VtxstoreTypes[i].numunitsfree = maxunits;
	}
}
