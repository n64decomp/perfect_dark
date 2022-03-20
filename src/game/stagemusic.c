#include <ultra64.h>
#include "constants.h"
#include "lib/sched.h"
#include "game/player.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

struct stagemusic g_StageTracks[] = {
	// stage,              main theme,           background sfx,          X theme
	{ STAGE_CITRAINING,    MUSIC_CI,             -1,                      MUSIC_DEFENSE_X       },
	{ STAGE_DEFECTION,     MUSIC_DEFECTION,      MUSIC_DDTOWER_SFX,       MUSIC_DEFECTION_X     },
	{ STAGE_INVESTIGATION, MUSIC_INVESTIGATION,  MUSIC_INVESTIGATION_SFX, MUSIC_INVESTIGATION_X },
	{ STAGE_EXTRACTION,    MUSIC_EXTRACTION,     MUSIC_DDTOWER_SFX,       MUSIC_EXTRACTION_X    },
	{ STAGE_VILLA,         MUSIC_VILLA,          MUSIC_OCEAN,             MUSIC_VILLA_X         },
	{ STAGE_CHICAGO,       MUSIC_CHICAGO,        MUSIC_TRAFFIC,           MUSIC_CHICAGO_X       },
	{ STAGE_G5BUILDING,    MUSIC_G5,             MUSIC_TRAFFIC,           MUSIC_G5_X            },
	{ STAGE_INFILTRATION,  MUSIC_INFILTRATION,   MUSIC_INFILTRATION_SFX,  MUSIC_INFILTRATION_X  },
	{ STAGE_RESCUE,        MUSIC_RESCUE,         MUSIC_A51_LOUDSPEAKER1,  MUSIC_RESCUE_X        },
	{ STAGE_ESCAPE,        MUSIC_ESCAPE,         MUSIC_A51_LOUDSPEAKER2,  MUSIC_ESCAPE_X        },
	{ STAGE_AIRBASE,       MUSIC_AIRBASE,        MUSIC_WIND,              MUSIC_AIRBASE_X       },
	{ STAGE_AIRFORCEONE,   MUSIC_AIRFORCEONE,    MUSIC_AIRFORCEONE_SFX,   MUSIC_AIRFORCEONE_X   },
	{ STAGE_CRASHSITE,     MUSIC_CRASHSITE,      MUSIC_CRASHSITE_WIND,    MUSIC_CRASHSITE_X     },
	{ STAGE_PELAGIC,       MUSIC_PELAGIC,        MUSIC_OCEAN,             MUSIC_PELAGIC_X       },
	{ STAGE_DEEPSEA,       MUSIC_DEEPSEA,        MUSIC_DEEPSEA_SFX,       MUSIC_DEEPSEA_X       },
	{ STAGE_DEFENSE,       MUSIC_DEFENSE,        -1,                      MUSIC_DEFENSE_X       },
	{ STAGE_ATTACKSHIP,    MUSIC_ATTACKSHIP,     MUSIC_ATTACKSHIP_SFX,    MUSIC_ATTACKSHIP_X    },
	{ STAGE_SKEDARRUINS,   MUSIC_SKEDARRUINS,    MUSIC_SKEDAR_WIND,       MUSIC_SKEDARRUINS_X   },
	{ STAGE_MBR,           MUSIC_DARK_COMBAT,    MUSIC_DDTOWER_SFX,       MUSIC_DARK_COMBAT     },
	{ STAGE_MAIANSOS,      MUSIC_MAIAN_TEARS,    MUSIC_A51_LOUDSPEAKER2,  MUSIC_MAIAN_TEARS     },
	{ STAGE_RETAKING,      MUSIC_CI_OPERATIVE,   -1,                      MUSIC_CI_OPERATIVE    },
	{ STAGE_WAR,           MUSIC_ALIEN_CONFLICT, MUSIC_SKEDAR_WIND,       MUSIC_ALIEN_CONFLICT  },
	{ STAGE_DUEL,          MUSIC_CREDITS,        -1,                      MUSIC_CREDITS         },
	{ STAGE_CREDITS,       MUSIC_ALIEN_CONFLICT, -1,                      MUSIC_ALIEN_CONFLICT  },
	{ 0,                   0,                    0,                       0  },
};

s32 stageGetPrimaryTrack(s32 stagenum)
{
	s32 i;

	if (g_Vars.normmplayerisrunning) {
		return mpChooseTrack();
	}

	i = 0;

	while (g_StageTracks[i].stagenum) {
		if (g_StageTracks[i].stagenum == stagenum) {
			if (g_StageTracks[i].primarytrack == -1) {
				return mpChooseTrack();
			}

			return g_StageTracks[i].primarytrack;
		}

		i++;
	}

	return mpChooseTrack();
}

s32 stageGetAmbientTrack(s32 stagenum)
{
	s32 i = 0;

	while (g_StageTracks[i].stagenum) {
		if (g_StageTracks[i].stagenum == stagenum) {
			return g_StageTracks[i].ambienttrack;
		}

		i++;
	}

	return -1;
}

s32 stageGetNrgTrack(s32 stagenum)
{
	s32 i = 0;

	while (g_StageTracks[i].stagenum) {
		if (g_StageTracks[i].stagenum == stagenum) {
			return g_StageTracks[i].xtrack;
		}

		i++;
	}

	return -1;
}
