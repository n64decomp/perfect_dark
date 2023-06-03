#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

void psReset(void)
{
	s32 i;

	g_PsChannels = mempAlloc(ALIGN16((IS4MB() ? 30 : 40) * sizeof(struct pschannel)), MEMPOOL_STAGE);

	for (i = 0; i < (IS4MB() ? 30 : 40); i++) {
		g_PsChannels[i].flags = PSFLAG_FREE;
		g_PsChannels[i].audiohandle = NULL;
		g_PsChannels[i].distance = -1;
	}
}
