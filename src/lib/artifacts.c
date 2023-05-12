#include <ultra64.h>
#include "lib/boot.h"
#include "lib/sched.h"
#include "constants.h"
#include "game/menugfx.h"
#include "bss.h"
#include "lib/audiomgr.h"
#include "lib/reset.h"
#include "lib/rzip.h"
#include "lib/main.h"
#include "lib/snd.h"
#include "lib/pimgr.h"
#include "lib/profile.h"
#include "lib/lib_48150.h"
#include "lib/vi.h"
#include "lib/joy.h"
#include "data.h"
#include "types.h"

struct artifact g_ArtifactLists[3][120];
u8 g_SchedSpecialArtifactIndexes[3];
s32 g_SchedWriteArtifactsIndex;
s32 g_SchedFrontArtifactsIndex;
s32 g_SchedPendingArtifactsIndex;

void schedInitArtifacts(void)
{
	s32 i;
	s32 j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < MAX_ARTIFACTS; j++) {
			g_ArtifactLists[i][j].type = ARTIFACTTYPE_FREE;
		}

		g_SchedSpecialArtifactIndexes[i] = 0;
	}
}

void schedResetArtifacts(void)
{
	g_SchedWriteArtifactsIndex = 0;
	g_SchedFrontArtifactsIndex = 1;
	g_SchedPendingArtifactsIndex = 0;
}

void schedUpdatePendingArtifacts(void)
{
	struct artifact *artifacts = g_ArtifactLists[g_SchedPendingArtifactsIndex];
	s32 i;

	for (i = 0; i < MAX_ARTIFACTS; i++) {
		struct artifact *artifact = &artifacts[i];

		if (artifact->type != ARTIFACTTYPE_FREE) {
			u16 *unk08 = artifact->unk08;
			u16 value08 = unk08[0];

			if (g_SchedSpecialArtifactIndexes[g_SchedPendingArtifactsIndex] == 1) {
				u16 *unk0c = artifact->unk0c.u16p;
				u16 value0c = unk0c[0];

				if (value0c > value08) {
					artifact->unk02 = value08;
				} else {
					artifact->unk02 = value0c;
				}
			} else {
				artifact->unk02 = value08;
			}
		}
	}

	g_SchedSpecialArtifactIndexes[g_SchedPendingArtifactsIndex] = 0;

	g_SchedPendingArtifactsIndex++;

	if (g_SchedPendingArtifactsIndex >= 3) {
		g_SchedPendingArtifactsIndex = 0;
	}
}
