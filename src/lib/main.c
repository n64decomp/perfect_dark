#include <ultra64.h>
#include <sched.h>
#include "lib/sched.h"
#include "lib/vars.h"
#include "constants.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/debug.h"
#include "game/file.h"
#include "game/lang.h"
#include "game/race.h"
#include "game/body.h"
#include "game/stubs/game_000840.h"
#include "game/stubs/game_000850.h"
#include "game/stubs/game_000860.h"
#include "game/stubs/game_000870.h"
#include "game/smoke.h"
#include "game/stubs/game_0008e0.h"
#include "game/stubs/game_0008f0.h"
#include "game/stubs/game_000900.h"
#include "game/stubs/game_000910.h"
#include "game/tex.h"
#include "game/stubs/game_00b180.h"
#include "game/stubs/game_00b200.h"
#include "game/challenge.h"
#include "game/title.h"
#include "game/pdmode.h"
#include "game/objectives.h"
#include "game/endscreen.h"
#include "game/playermgr.h"
#include "game/game_1531a0.h"
#include "game/gfxmemory.h"
#include "game/lang.h"
#include "game/lv.h"
#include "game/timing.h"
#include "game/music.h"
#include "game/stubs/game_175f50.h"
#include "game/game_175f90.h"
#include "game/game_176080.h"
#include "game/game_1a78b0.h"
#include "game/mplayer/mplayer.h"
#include "game/pak.h"
#include "game/splat.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/audiomgr.h"
#include "lib/args.h"
#include "lib/boot.h"
#include "lib/vm.h"
#include "lib/rzip.h"
#include "lib/vi.h"
#include "lib/fault.h"
#include "lib/crash.h"
#include "lib/dma.h"
#include "lib/joy.h"
#include "lib/main.h"
#include "lib/snd.h"
#include "lib/memp.h"
#include "lib/mema.h"
#include "lib/profile.h"
#include "lib/videbug.h"
#include "lib/debughud.h"
#include "lib/anim.h"
#include "lib/rdp.h"
#include "lib/lib_34d0.h"
#include "lib/lib_2f490.h"
#include "lib/rmon.h"
#include "lib/rng.h"
#include "lib/str.h"
#include "data.h"
#include "types.h"

// mainLoop calls rngSetSeed with a u32 argument,
// but the function takes a u64 so an incorrect declaration is needed.
void rngSetSeed(u32 seed);

bool var8005d9b0 = false;
s32 g_StageNum = STAGE_TITLE;
u32 g_MainMemaHeapSize = 1024 * 300;
bool var8005d9bc = false;
s32 var8005d9c0 = 0;
s32 var8005d9c4 = 0;
bool g_MainGameLogicEnabled = true;
u32 g_MainNumGfxTasks = 0;
bool g_MainIsEndscreen = false;
s32 g_DoBootPakMenu = 0;

struct stageallocation g_StageAllocations8Mb[] = {
#if VERSION >= VERSION_NTSC_1_0
	{ STAGE_CITRAINING,    "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_DEFECTION,     "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_INVESTIGATION, "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_EXTRACTION,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_CHICAGO,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_G5BUILDING,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_VILLA,         "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma600" },
	{ STAGE_INFILTRATION,  "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500" },
	{ STAGE_RESCUE,        "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500" },
	{ STAGE_ESCAPE,        "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500" },
	{ STAGE_AIRBASE,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_AIRFORCEONE,   "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_CRASHSITE,     "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_PELAGIC,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_DEEPSEA,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_DEFENSE,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_ATTACKSHIP,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_SKEDARRUINS,   "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_MP_SKEDAR,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_RAVINE,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_PIPES,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_G5BUILDING, "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_SEWERS,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_WAREHOUSE,  "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_BASE,       "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_COMPLEX,    "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_TEMPLE,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_FELICITY,   "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_AREA52,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_GRID,       "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_CARPARK,    "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_RUINS,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_FORTRESS,   "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_VILLA,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_RUN,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP2,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP6,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP7,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP8,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP14,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP16,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP17,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP18,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP19,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP20,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_ASH,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_28,            "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_MBR,           "-ml0 -me0 -mgfx120 -mvtx100 -ma700"            },
	{ STAGE_TEST_SILO,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_24,            "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_MAIANSOS,      "-ml0 -me0 -mgfx120 -mvtx100 -ma500"            },
	{ STAGE_RETAKING,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_TEST_DEST,     "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_2B,            "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_WAR,           "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_TEST_UFF,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_TEST_OLD,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_DUEL,          "-ml0 -me0 -mgfx120 -mvtx100 -ma700"            },
	{ STAGE_TEST_LAM,      "-ml0 -me0 -mgfx120 -mvtx98 -ma400"             },
	{ STAGE_TEST_ARCH,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_LEN,      "-ml0 -me0 -mgfx120 -mvtx98 -ma300"             },
	{ STAGE_TITLE,         "-ml0 -me0 -mgfx80 -mvtx20 -ma001"              },
	{ 0,                   "-ml0 -me0 -mgfx120 -mvtx98 -ma300"             },
#else
	// ntsc-beta
	{ STAGE_CITRAINING,    "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_DEFECTION,     "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_INVESTIGATION, "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_EXTRACTION,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma700" },
	{ STAGE_CHICAGO,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500" },
	{ STAGE_G5BUILDING,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma500" },
	{ STAGE_VILLA,         "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma600" },
	{ STAGE_INFILTRATION,  "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_RESCUE,        "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_ESCAPE,        "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_AIRBASE,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_AIRFORCEONE,   "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_CRASHSITE,     "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_PELAGIC,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_DEEPSEA,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_DEFENSE,       "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_ATTACKSHIP,    "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_SKEDARRUINS,   "-ml0 -me0 -mgfx110 -mgfxtra80 -mvtx100 -ma400" },
	{ STAGE_MP_SKEDAR,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_RAVINE,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_PIPES,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_G5BUILDING, "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_SEWERS,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_WAREHOUSE,  "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_BASE,       "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_COMPLEX,    "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_TEMPLE,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_FELICITY,   "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_AREA52,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_GRID,       "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_CARPARK,    "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_RUINS,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_FORTRESS,   "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_MP_VILLA,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_RUN,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP2,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP6,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP7,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP8,      "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP14,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP16,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP17,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP18,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP19,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_MP20,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_ASH,      "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_28,            "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_MBR,           "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_TEST_SILO,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_24,            "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_MAIANSOS,      "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_RETAKING,      "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_TEST_DEST,     "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_2B,            "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_WAR,           "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_TEST_UFF,      "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_TEST_OLD,      "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_DUEL,          "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_TEST_LAM,      "-ml0 -me0 -mgfx120 -mvtx100 -ma400"            },
	{ STAGE_TEST_ARCH,     "-ml0 -me0 -mgfx200 -mvtx200 -ma400"            },
	{ STAGE_TEST_LEN,      "-ml0 -me0 -mgfx120 -mvtx100 -ma300"            },
	{ STAGE_TITLE,         "-ml0 -me0 -mgfx80 -mvtx20 -ma001"              },
	{ 0,                   "-ml0 -me0 -mgfx120 -mvtx100 -ma300"            },
#endif
};

struct stageallocation g_StageAllocations4Mb[] = {
#if VERSION >= VERSION_NTSC_1_0
	{ STAGE_MP_SKEDAR,     "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_PIPES,      "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_AREA52,     "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_RAVINE,     "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_G5BUILDING, "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_SEWERS,     "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_WAREHOUSE,  "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_BASE,       "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_COMPLEX,    "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_TEMPLE,     "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_FELICITY,   "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_GRID,       "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_TEST_RUN,      "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_CARPARK,    "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_RUINS,      "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_MP_FORTRESS,   "-ml0 -me0 -mgfx96 -mvtx96 -ma130"              },
	{ STAGE_MP_VILLA,      "-ml0 -me0 -mgfx96 -mvtx96 -ma140"              },
	{ STAGE_TEST_MP2,      "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP6,      "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP7,      "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP8,      "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP14,     "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP16,     "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP17,     "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP18,     "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP19,     "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_MP20,     "-ml0 -me0 -mgfx96 -mvtx96 -ma115"              },
	{ STAGE_TEST_LEN,      "-ml0 -me0 -mgfx100 -mvtx96 -ma120"             },
	{ STAGE_4MBMENU,       "-mgfx100 -mvtx50 -ma50"                        },
	{ STAGE_TITLE,         "-ml0 -me0 -mgfx80 -mvtx20 -ma001"              },
	{ 0,                   "-ml0 -me0 -mgfx100 -mvtx96 -ma300"             },
#else
	// ntsc-beta
	{ STAGE_MP_SKEDAR,     "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_MP_PIPES,      "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_MP_AREA52,     "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_MP_RAVINE,     "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_MP_G5BUILDING, "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_MP_SEWERS,     "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_MP_WAREHOUSE,  "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_MP_BASE,       "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_MP_COMPLEX,    "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_MP_TEMPLE,     "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_MP_FELICITY,   "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_MP_GRID,       "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_TEST_RUN,      "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_MP_CARPARK,    "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_MP_RUINS,      "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_MP_FORTRESS,   "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_MP_VILLA,      "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_TEST_MP2,      "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_TEST_MP6,      "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_TEST_MP7,      "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_TEST_MP8,      "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_TEST_MP14,     "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_TEST_MP16,     "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_TEST_MP17,     "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_TEST_MP18,     "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_TEST_MP19,     "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_TEST_MP20,     "-ml0 -me0 -mgfx100 -mvtx100 -ma105"            },
	{ STAGE_TEST_LEN,      "-ml0 -me0 -mgfx100 -mvtx100 -ma120"            },
	{ STAGE_4MBMENU,       "-mgfx100 -mvtx50 -ma50"                        },
	{ STAGE_TITLE,         "-ml0 -me0 -mgfx80 -mvtx20 -ma001"              },
	{ 0,                   "-ml0 -me0 -mgfx100 -mvtx100 -ma300"            },
#endif
};

Gfx var8005dcc8[] = {
	gsSPSegment(0x00, 0x00000000),
	gsSPDisplayList(&var800613a0),
	gsSPDisplayList(&var80061380),
	gsDPFullSync(),
	gsSPEndDisplayList(),
};

Gfx var8005dcf0[] = {
	gsSPSegment(0x00, 0x00000000),
	gsSPDisplayList(&var800613a0),
	gsSPDisplayList(&var80061380),
	gsDPFullSync(),
	gsSPEndDisplayList(),
};

s32 var8005dd18 = 1;

extern u8 _accessingpakSegmentRomStart;
extern u8 _accessingpakSegmentRomEnd;
extern u8 _copyrightSegmentRomStart;
extern u8 _copyrightSegmentRomEnd;
extern u8 _bssSegmentEnd;

#if !MATCHING || VERSION >= VERSION_NTSC_1_0
/**
 * Initialise various subsystems, display the copyright or accessing pak texture,
 * then initialise more subsystems.
 */
void mainInit(void)
{
	s32 x;
	s32 dsty;
	OSMesg msg;
	OSTimer timer;
	OSMesgQueue queue;
	s32 i;
	s32 j;
	u16 *fb;
	s32 srcy;
	u32 addr;
	u8 *start;
	u8 *end;

	faultInit();
	dmaInit();
	amgrInit();
	varsInit();
	mempInit();
	memaInit();
	videbugInit();
	viConfigureForLogos();
	var8005d9b0 = rmonIsDisabled();
	joyInit();
	osCreateMesgQueue(&queue, &msg, 1);

	// Wait a bit, reset the controllers and wait a bit more
	for (i = 0; i < 4; i++) {
		osSetTimer(&timer, OS_CPU_COUNTER / 60 * 6, 0, &queue, &msg);
		osRecvMesg(&queue, &msg, OS_MESG_BLOCK);

		if (i == 1) {
			joyReset();
		} else if (i >= 2) {
			joyDebugJoy();
		}

#if VERSION >= VERSION_NTSC_1_0
		if (1);
		if (1);
#endif
	}

	if (argFindByPrefix(1, "-level_") == NULL) {
		var8005d9b0 = true;
	}

#if VERSION >= VERSION_NTSC_1_0
	// If holding start on any controller, open boot pak menu
	if (joyGetButtons(0, START_BUTTON) == 0
			&& joyGetButtons(1, START_BUTTON) == 0
			&& joyGetButtons(2, START_BUTTON) == 0
			&& joyGetButtons(3, START_BUTTON) == 0) {
		g_DoBootPakMenu = false;
	} else {
		g_DoBootPakMenu = true;
	}

#if VERSION == VERSION_PAL_BETA
	// In PAL beta, pressing all C buttons during poweron sets g_CrashEnabled.
	// If it's set, a sound effect is played on the legal screen to confirm
	// and the crash screen will be shown if the game crashes.
#define BUTTON_MASK (U_CBUTTONS | D_CBUTTONS | L_CBUTTONS | R_CBUTTONS)

	if (joyGetButtons(0, BUTTON_MASK) == BUTTON_MASK
			|| joyGetButtons(1, BUTTON_MASK) == BUTTON_MASK
			|| joyGetButtons(2, BUTTON_MASK) == BUTTON_MASK
			|| joyGetButtons(3, BUTTON_MASK) == BUTTON_MASK) {
		g_CrashEnabled = true;
	}
#endif

	{
		OSMesg receivedmsg = NULL;
		OSScMsg scdonemsg = { OS_SC_DONE_MSG };
		u16 *texture;
		s32 numpages;
		u8 scratch[1024 * 5 - 8];
#if PAL
		u32 stack[2];
#endif

		// Choose where to place the temporary framebuffer.
		// In 4MB mode, place it close to the end of memory,
		// but before the thread stacks and VM system.
		// In 8MB mode, put it at the end of the expansion pak.
		if (bootGetMemSize() <= 4 * 1024 * 1024) {
			addr = K0BASE + 4 * 1024 * 1024;
			addr -= STACKSIZE_MAIN;
			addr -= STACKSIZE_IDLE;
			addr -= STACKSIZE_RMON;
			addr -= STACKSIZE_SCHED;
			addr -= STACKSIZE_AUDIO;
			addr -= 8; // markers for stack overflow detection
			addr -= g_VmNumPages * 8; // vm state table
			addr -= 268 * 4096; // vm loaded pages buffer
			addr -= addr % 0x2000; // align down to a multiple of 0x2000
			addr -= 0x1c80; // buffer for single biggest game zip
		} else {
			addr = K0BASE + 8 * 1024 * 1024;
		}

		addr -= 640 * 480 * 2; // the framebuffer itself
		addr -= 0x40; // align down to a multiple of 0x40

		fb = (u16 *) ALIGN64(PHYS_TO_K0(addr));

		// Prepare space for the unzipped texture immediately before the framebuffer.
		// Both textures are 507x48.
		texture = fb - 507 * 48;

		// DMA the compressed texture from the ROM to the framebuffer.
		// It's using the framebuffer as a temporary data buffer.
		if (g_DoBootPakMenu) {
			start = &_accessingpakSegmentRomStart;
			end = &_accessingpakSegmentRomEnd;
			dmaExec(fb, (romptr_t) start, end - start);
		} else {
			start = &_copyrightSegmentRomStart;
			end = &_copyrightSegmentRomEnd;
			dmaExec(fb, (romptr_t) start, end - start);
		}

		// This is required for a match
		numpages = g_VmNumPages;

		if ((f64) numpages && (f64) numpages);

		// Unzip the compressed texture from fb to texture
		rzipInflate(fb, texture, scratch);

		// Clear the framebuffer except for the bottom 48 rows,
		// because that's where the texture will go.
		// The increment here is too small, so some pixels are zeroed twice.
		for (dsty = 0; dsty < (480 - 48) * 640; dsty += 576) {
			for (x = 0; x < 640; x++) {
				fb[dsty + x] = 0;
			}
		}

#if VERSION >= VERSION_JPN_FINAL
		if (osTvType == OS_TV_NTSC)
#elif PAL
		if (osTvType == OS_TV_PAL)
#else
		if (osTvType != OS_TV_PAL)
#endif
		{
			// Copy the texture to the framebuffer.
			// The framebuffer will be displayed at 576 wide,
			// and the texture is right aligned.
			dsty = 0;

			for (srcy = 0; srcy < 507 * 48; srcy += 507) {
				for (x = 0; x < 507; x++) {
					fb[dsty + (576 - 507) + x] = texture[srcy + x];
				}

				dsty += 576;
			}
		}

		viSetMode(VIMODE_HI);
		viConfigureForCopyright(fb);

		g_RdpOutBufferStart = texture;
		g_RdpOutBufferEnd = texture + 0x400; // 0x800 bytes, because texture is u16

		while (osRecvMesg(&g_MainMesgQueue, &receivedmsg, OS_MESG_NOBLOCK) == 0) {
			// empty
		}

		j = 0;

		while (j < 6) {
			osRecvMesg(&g_MainMesgQueue, &receivedmsg, OS_MESG_BLOCK);

			i = (s32) &scdonemsg;

			if (*(s16 *) receivedmsg == OS_SC_RETRACE_MSG) {
				viUpdateMode();
				rdpCreateTask(var8005dcc8, var8005dcf0, 0, (void *) i);
				j++;
			}
		}
	}

	// From the N64 SDK:
	//
	//     Please design the game program so that it won't execute normally
	//     when an unexpected television system format is detected by osTvType.
	//     Design the program to either go into an infinite loop or display a
	//     message indicating a system error.
	//
#if VERSION >= VERSION_JPN_FINAL
	if (osTvType != OS_TV_NTSC) {
		while (1);
	}
#elif PAL
	if (osTvType != OS_TV_PAL) {
		while (1);
	}
#else
	if (osTvType == OS_TV_PAL) {
		while (1);
	}
#endif

#else
	// NTSC beta
	if (osTvType != OS_TV_NTSC) {
		var8005d9b0 = true;

		while (1);
	}

	if (joyGetButtons(0, START_BUTTON) == 0
			&& joyGetButtons(1, START_BUTTON) == 0
			&& joyGetButtons(2, START_BUTTON) == 0
			&& joyGetButtons(3, START_BUTTON) == 0) {
		OSMesg receivedmsg = NULL;
		OSScMsg scdonemsg = { OS_SC_DONE_MSG };
		u8 scratch[1024 * 5];
		u16 *texture;
		s32 numpages;

		g_DoBootPakMenu = false;

		// Choose where to place the temporary framebuffer.
		// In 4MB mode, place it close to the end of memory,
		// but before the thread stacks and VM system.
		// In 8MB mode, put it at the end of the expansion pak.
		if (osGetMemSize() <= 4 * 1024 * 1024) {
			addr = K0BASE + 4 * 1024 * 1024;
			addr -= STACKSIZE_MAIN;
			addr -= STACKSIZE_IDLE;
			addr -= STACKSIZE_RMON;
			addr -= STACKSIZE_SCHED;
			addr -= STACKSIZE_AUDIO;
			addr -= g_VmNumPages * 8; // vm state table
			addr -= 266 * 4096; // vm loaded pages buffer
			addr -= addr % 0x2000; // align down to a multiple of 0x2000
			addr -= 0x1c80; // buffer for single biggest game zip
		} else {
			addr = K0BASE + 8 * 1024 * 1024;
		}

		addr -= 640 * 480 * 2; // the framebuffer itself
		addr -= 0x40; // align down to a multiple of 0x40

		fb = (u16 *) ALIGN64(PHYS_TO_K0(addr));

		// Prepare space for the unzipped texture immediately before the framebuffer.
		// Both textures are 507x48.
		texture = fb - 507 * 48;

		// DMA the compressed texture from the ROM to the framebuffer.
		// It's using the framebuffer as a temporary data buffer.
		start = &_copyrightSegmentRomStart;
		end = &_copyrightSegmentRomEnd;
		dmaExec(fb, (romptr_t) start, end - start);

		// Unzip the compressed texture from fb to texture
		rzipInflate(fb, texture, scratch);

		// Clear the framebuffer except for the bottom 48 rows,
		// because that's where the texture will go.
		// The increment here is too small, so some pixels are zeroed twice.
		for (dsty = 0; dsty < (480 - 48) * 640; dsty += 576) {
			for (x = 0; x < 640; x++) {
				fb[dsty + x] = 0;
			}

			if (1);
		}

		// Copy the texture to the framebuffer.
		// The framebuffer will be displayed at 576 wide,
		// and the texture is right aligned.
		dsty = 0;

		for (srcy = 0; srcy < 507 * 48; srcy += 507) {
			for (x = 0; x < 507; x++) {
				fb[dsty + (576 - 507) + x] = texture[srcy + x];
			}

			dsty += 576;
		}

		viSetMode(VIMODE_HI);
		viConfigureForCopyright(fb);

		g_RdpOutBufferStart = texture;
		g_RdpOutBufferEnd = texture + 0x400; // 0x800 bytes, because texture is u16

		while (osRecvMesg(&g_MainMesgQueue, &receivedmsg, OS_MESG_NOBLOCK) == 0) {
			if (i);
		}

		i = 0;

		while (i < 6) {
			osRecvMesg(&g_MainMesgQueue, &receivedmsg, OS_MESG_BLOCK);

			j = (s32) &scdonemsg;

			if (*(s16 *) receivedmsg == OS_SC_RETRACE_MSG) {
				viUpdateMode();
				rdpCreateTask(var8005dcc8, var8005dcf0, 0, (void *) j);
				i++;
			}
		}
	} else {
		g_DoBootPakMenu = true;
	}
#endif

	vmInit();
	func0f1a78b0();
	filesInit();
	stub0f175f50();
	func0f175f90();

	if (var8005d9b0) {
		argSetString("          -ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400");
	}

	start = (u8 *) PHYS_TO_K0(osVirtualToPhysical(&_bssSegmentEnd));
	end = g_VmMarker;
	mempSetHeap(start, end - start);

	mempResetPool(MEMPOOL_8);
	mempResetPool(MEMPOOL_PERMANENT);
	crashReset();
	challengesInit();
	utilsInit();
	func000034d0();
	texInit();
	langInit();
	lvInit();
	cheatsInit();
	func0000e9c0();
	textInit();
	dhudInit();
	playermgrInit();
	frametimeInit();
	stub0f00b200();
	profileInit();
	stub0f000870();
	smokesInit();
	stub0f0008e0();
	stub0f0008f0();
	stub0f000900();
	stub0f00b180();
	stub0f000910();
	stub0f000840();
	mpInit();
	pheadInit();
	paksInit();
	pheadInit2();
	animsInit();
	racesInit();
	bodiesInit();
	stub0f000850();
	stub0f000860();
	titleInit();
	viConfigureForLegal();
	viBlack(true);

	var8005dd18 = 0;

#if VERSION >= VERSION_PAL_BETA && VERSION < VERSION_JPN_FINAL
	if (g_DoBootPakMenu) {
		osGetCount();
	}
#endif
}
#else
const char var70053a98[] = "-level_";
const char var70053aa0[] = "          -ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400";

u32 var8005dd1c = 0x00020000;
u32 var8005dd20 = 0x00000000;
u32 var8005dd24 = 0x00000000;
u32 var8005dd28 = 0x00000000;
u32 var8005dd2c = 0x00000000;
u32 var8005dd30 = 0x00000000;
u32 var8005dd34 = 0x00000000;
u32 var8005dd38 = 0x00000000;

GLOBAL_ASM(
glabel mainInit
/*     da80:	27bdeb20 */ 	addiu	$sp,$sp,-5344
/*     da84:	afbf0034 */ 	sw	$ra,0x34($sp)
/*     da88:	afb20030 */ 	sw	$s2,0x30($sp)
/*     da8c:	afb1002c */ 	sw	$s1,0x2c($sp)
/*     da90:	0c003060 */ 	jal	faultInit
/*     da94:	afb00028 */ 	sw	$s0,0x28($sp)
/*     da98:	0c0035b4 */ 	jal	dmaInit
/*     da9c:	00000000 */ 	sll	$zero,$zero,0x0
/*     daa0:	0c0022f0 */ 	jal	amgrInit
/*     daa4:	00000000 */ 	sll	$zero,$zero,0x0
/*     daa8:	0c0059d4 */ 	jal	varsInit
/*     daac:	00000000 */ 	sll	$zero,$zero,0x0
/*     dab0:	0c004994 */ 	jal	mempInit
/*     dab4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dab8:	0c004beb */ 	jal	memaInit
/*     dabc:	00000000 */ 	sll	$zero,$zero,0x0
/*     dac0:	0c004fea */ 	jal	videbugInit
/*     dac4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dac8:	0c002714 */ 	jal	viConfigureForLogos
/*     dacc:	00000000 */ 	sll	$zero,$zero,0x0
/*     dad0:	0c00c456 */ 	jal	rmonIsDisabled
/*     dad4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dad8:	3c018006 */ 	lui	$at,%hi(var8005d9b0)
/*     dadc:	0c0052b6 */ 	jal	joyInit
/*     dae0:	ac22f2d0 */ 	sw	$v0,%lo(var8005d9b0)($at)
/*     dae4:	27b11498 */ 	addiu	$s1,$sp,0x1498
/*     dae8:	27b214d4 */ 	addiu	$s2,$sp,0x14d4
/*     daec:	02402825 */ 	or	$a1,$s2,$zero
/*     daf0:	02202025 */ 	or	$a0,$s1,$zero
/*     daf4:	0c0125c4 */ 	jal	osCreateMesgQueue
/*     daf8:	24060001 */ 	addiu	$a2,$zero,0x1
/*     dafc:	00008025 */ 	or	$s0,$zero,$zero
/*     db00:	3c070047 */ 	lui	$a3,0x47
.NB0000db04:
/*     db04:	240e0000 */ 	addiu	$t6,$zero,0x0
/*     db08:	240f0000 */ 	addiu	$t7,$zero,0x0
/*     db0c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*     db10:	afae0010 */ 	sw	$t6,0x10($sp)
/*     db14:	34e7868c */ 	ori	$a3,$a3,0x868c
/*     db18:	27a414b0 */ 	addiu	$a0,$sp,0x14b0
/*     db1c:	24060000 */ 	addiu	$a2,$zero,0x0
/*     db20:	afb10018 */ 	sw	$s1,0x18($sp)
/*     db24:	0c0127bc */ 	jal	osSetTimer
/*     db28:	afb2001c */ 	sw	$s2,0x1c($sp)
/*     db2c:	02202025 */ 	or	$a0,$s1,$zero
/*     db30:	02402825 */ 	or	$a1,$s2,$zero
/*     db34:	0c0126b0 */ 	jal	osRecvMesg
/*     db38:	24060001 */ 	addiu	$a2,$zero,0x1
/*     db3c:	24010001 */ 	addiu	$at,$zero,0x1
/*     db40:	56010006 */ 	bnel	$s0,$at,.NB0000db5c
/*     db44:	2a010002 */ 	slti	$at,$s0,0x2
/*     db48:	0c005310 */ 	jal	joyReset
/*     db4c:	00000000 */ 	sll	$zero,$zero,0x0
/*     db50:	10000007 */ 	beqz	$zero,.NB0000db70
/*     db54:	26100001 */ 	addiu	$s0,$s0,0x1
/*     db58:	2a010002 */ 	slti	$at,$s0,0x2
.NB0000db5c:
/*     db5c:	54200004 */ 	bnezl	$at,.NB0000db70
/*     db60:	26100001 */ 	addiu	$s0,$s0,0x1
/*     db64:	0c005477 */ 	jal	joyDebugJoy
/*     db68:	00000000 */ 	sll	$zero,$zero,0x0
/*     db6c:	26100001 */ 	addiu	$s0,$s0,0x1
.NB0000db70:
/*     db70:	24010004 */ 	addiu	$at,$zero,0x4
/*     db74:	5601ffe3 */ 	bnel	$s0,$at,.NB0000db04
/*     db78:	3c070047 */ 	lui	$a3,0x47
/*     db7c:	3c057005 */ 	lui	$a1,%hi(var70053a98)
/*     db80:	24a550e8 */ 	addiu	$a1,$a1,%lo(var70053a98)
/*     db84:	0c004e18 */ 	jal	argFindByPrefix
/*     db88:	24040001 */ 	addiu	$a0,$zero,0x1
/*     db8c:	14400004 */ 	bnez	$v0,.NB0000dba0
/*     db90:	3c198000 */ 	lui	$t9,%hi(osTvType)
/*     db94:	24180001 */ 	addiu	$t8,$zero,0x1
/*     db98:	3c018006 */ 	lui	$at,%hi(var8005d9b0)
/*     db9c:	ac38f2d0 */ 	sw	$t8,%lo(var8005d9b0)($at)
.NB0000dba0:
/*     dba0:	8f390300 */ 	lw	$t9,%lo(osTvType)($t9)
/*     dba4:	24010001 */ 	addiu	$at,$zero,0x1
/*     dba8:	00002025 */ 	or	$a0,$zero,$zero
/*     dbac:	13210005 */ 	beq	$t9,$at,.NB0000dbc4
/*     dbb0:	24090001 */ 	addiu	$t1,$zero,0x1
/*     dbb4:	3c018006 */ 	lui	$at,%hi(var8005d9b0)
/*     dbb8:	ac29f2d0 */ 	sw	$t1,%lo(var8005d9b0)($at)
.NB0000dbbc:
/*     dbbc:	1000ffff */ 	beqz	$zero,.NB0000dbbc
/*     dbc0:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000dbc4:
/*     dbc4:	0c005790 */ 	jal	joyGetButtons
/*     dbc8:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     dbcc:	1440009e */ 	bnez	$v0,.NB0000de48
/*     dbd0:	24040001 */ 	addiu	$a0,$zero,0x1
/*     dbd4:	0c005790 */ 	jal	joyGetButtons
/*     dbd8:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     dbdc:	1440009a */ 	bnez	$v0,.NB0000de48
/*     dbe0:	24040002 */ 	addiu	$a0,$zero,0x2
/*     dbe4:	0c005790 */ 	jal	joyGetButtons
/*     dbe8:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     dbec:	14400096 */ 	bnez	$v0,.NB0000de48
/*     dbf0:	24040003 */ 	addiu	$a0,$zero,0x3
/*     dbf4:	0c005790 */ 	jal	joyGetButtons
/*     dbf8:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     dbfc:	14400092 */ 	bnez	$v0,.NB0000de48
/*     dc00:	3c0b8006 */ 	lui	$t3,%hi(var8005dd1c)
/*     dc04:	afa01478 */ 	sw	$zero,0x1478($sp)
/*     dc08:	256bf63c */ 	addiu	$t3,$t3,%lo(var8005dd1c)
/*     dc0c:	8d610000 */ 	lw	$at,0x0($t3)
/*     dc10:	8d6e0004 */ 	lw	$t6,0x4($t3)
/*     dc14:	27aa1458 */ 	addiu	$t2,$sp,0x1458
/*     dc18:	ad410000 */ 	sw	$at,0x0($t2)
/*     dc1c:	8d610008 */ 	lw	$at,0x8($t3)
/*     dc20:	ad4e0004 */ 	sw	$t6,0x4($t2)
/*     dc24:	8d6e000c */ 	lw	$t6,0xc($t3)
/*     dc28:	ad410008 */ 	sw	$at,0x8($t2)
/*     dc2c:	8d610010 */ 	lw	$at,0x10($t3)
/*     dc30:	ad4e000c */ 	sw	$t6,0xc($t2)
/*     dc34:	8d6e0014 */ 	lw	$t6,0x14($t3)
/*     dc38:	ad410010 */ 	sw	$at,0x10($t2)
/*     dc3c:	8d610018 */ 	lw	$at,0x18($t3)
/*     dc40:	ad4e0014 */ 	sw	$t6,0x14($t2)
/*     dc44:	8d6e001c */ 	lw	$t6,0x1c($t3)
/*     dc48:	ad410018 */ 	sw	$at,0x18($t2)
/*     dc4c:	3c018006 */ 	lui	$at,%hi(g_DoBootPakMenu)
/*     dc50:	ad4e001c */ 	sw	$t6,0x1c($t2)
/*     dc54:	0c013d4c */ 	jal	osGetMemSize
/*     dc58:	ac20f2f4 */ 	sw	$zero,%lo(g_DoBootPakMenu)($at)
/*     dc5c:	3c010040 */ 	lui	$at,0x40
/*     dc60:	34210001 */ 	ori	$at,$at,0x1
/*     dc64:	0041082b */ 	sltu	$at,$v0,$at
/*     dc68:	1020000e */ 	beqz	$at,.NB0000dca4
/*     dc6c:	3c0301fb */ 	lui	$v1,%hi(_copyrightSegmentRomStart)
/*     dc70:	3c0f8006 */ 	lui	$t7,%hi(g_VmNumPages)
/*     dc74:	8defe720 */ 	lw	$t7,%lo(g_VmNumPages)($t7)
/*     dc78:	3c19803f */ 	lui	$t9,0x803f
/*     dc7c:	373950c0 */ 	ori	$t9,$t9,0x50c0
/*     dc80:	3c01ffef */ 	lui	$at,0xffef
/*     dc84:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*     dc88:	03381023 */ 	subu	$v0,$t9,$t8
/*     dc8c:	34216000 */ 	ori	$at,$at,0x6000
/*     dc90:	00411021 */ 	addu	$v0,$v0,$at
/*     dc94:	30491fff */ 	andi	$t1,$v0,0x1fff
/*     dc98:	00491023 */ 	subu	$v0,$v0,$t1
/*     dc9c:	10000002 */ 	beqz	$zero,.NB0000dca8
/*     dca0:	2442e380 */ 	addiu	$v0,$v0,-7296
.NB0000dca4:
/*     dca4:	3c028080 */ 	lui	$v0,0x8080
.NB0000dca8:
/*     dca8:	3c01fff6 */ 	lui	$at,0xfff6
/*     dcac:	3421a000 */ 	ori	$at,$at,0xa000
/*     dcb0:	00411021 */ 	addu	$v0,$v0,$at
/*     dcb4:	2442ffc0 */ 	addiu	$v0,$v0,-64
/*     dcb8:	3c018000 */ 	lui	$at,0x8000
/*     dcbc:	00418825 */ 	or	$s1,$v0,$at
/*     dcc0:	2631003f */ 	addiu	$s1,$s1,0x3f
/*     dcc4:	362d003f */ 	ori	$t5,$s1,0x3f
/*     dcc8:	3c0a01fb */ 	lui	$t2,%hi(_copyrightSegmentRomEnd)
/*     dccc:	2465bac0 */ 	addiu	$a1,$v1,%lo(_copyrightSegmentRomStart)
/*     dcd0:	254ac5f0 */ 	addiu	$t2,$t2,%lo(_copyrightSegmentRomEnd)
/*     dcd4:	39a4003f */ 	xori	$a0,$t5,0x3f
/*     dcd8:	00808825 */ 	or	$s1,$a0,$zero
/*     dcdc:	0c003664 */ 	jal	dmaExec
/*     dce0:	01453023 */ 	subu	$a2,$t2,$a1
/*     dce4:	3c01ffff */ 	lui	$at,0xffff
/*     dce8:	342141e0 */ 	ori	$at,$at,0x41e0
/*     dcec:	02219021 */ 	addu	$s2,$s1,$at
/*     dcf0:	02402825 */ 	or	$a1,$s2,$zero
/*     dcf4:	02202025 */ 	or	$a0,$s1,$zero
/*     dcf8:	0c001da4 */ 	jal	rzipInflate
/*     dcfc:	27a60058 */ 	addiu	$a2,$sp,0x58
/*     dd00:	3c050004 */ 	lui	$a1,0x4
/*     dd04:	34a53800 */ 	ori	$a1,$a1,0x3800
/*     dd08:	00003825 */ 	or	$a3,$zero,$zero
/*     dd0c:	24040500 */ 	addiu	$a0,$zero,0x500
/*     dd10:	00075840 */ 	sll	$t3,$a3,0x1
.NB0000dd14:
/*     dd14:	022b1821 */ 	addu	$v1,$s1,$t3
/*     dd18:	00001025 */ 	or	$v0,$zero,$zero
.NB0000dd1c:
/*     dd1c:	00627021 */ 	addu	$t6,$v1,$v0
/*     dd20:	24420002 */ 	addiu	$v0,$v0,0x2
/*     dd24:	1444fffd */ 	bne	$v0,$a0,.NB0000dd1c
/*     dd28:	a5c00000 */ 	sh	$zero,0x0($t6)
/*     dd2c:	24e70240 */ 	addiu	$a3,$a3,0x240
/*     dd30:	00e5082a */ 	slt	$at,$a3,$a1
/*     dd34:	5420fff7 */ 	bnezl	$at,.NB0000dd14
/*     dd38:	00075840 */ 	sll	$t3,$a3,0x1
/*     dd3c:	00003825 */ 	or	$a3,$zero,$zero
/*     dd40:	00003025 */ 	or	$a2,$zero,$zero
/*     dd44:	240503f6 */ 	addiu	$a1,$zero,0x3f6
.NB0000dd48:
/*     dd48:	00077840 */ 	sll	$t7,$a3,0x1
/*     dd4c:	0006c840 */ 	sll	$t9,$a2,0x1
/*     dd50:	02592021 */ 	addu	$a0,$s2,$t9
/*     dd54:	022f1821 */ 	addu	$v1,$s1,$t7
/*     dd58:	00001025 */ 	or	$v0,$zero,$zero
.NB0000dd5c:
/*     dd5c:	0082c021 */ 	addu	$t8,$a0,$v0
/*     dd60:	97090000 */ 	lhu	$t1,0x0($t8)
/*     dd64:	00626821 */ 	addu	$t5,$v1,$v0
/*     dd68:	24420002 */ 	addiu	$v0,$v0,0x2
/*     dd6c:	1445fffb */ 	bne	$v0,$a1,.NB0000dd5c
/*     dd70:	a5a9008a */ 	sh	$t1,0x8a($t5)
/*     dd74:	24c601fb */ 	addiu	$a2,$a2,0x1fb
/*     dd78:	28c15f10 */ 	slti	$at,$a2,0x5f10
/*     dd7c:	1420fff2 */ 	bnez	$at,.NB0000dd48
/*     dd80:	24e70240 */ 	addiu	$a3,$a3,0x240
/*     dd84:	0c002b0c */ 	jal	viSetMode
/*     dd88:	24040002 */ 	addiu	$a0,$zero,0x2
/*     dd8c:	0c00273c */ 	jal	viConfigureForCopyright
/*     dd90:	02202025 */ 	or	$a0,$s1,$zero
/*     dd94:	3c018006 */ 	lui	$at,%hi(g_RdpOutBufferStart)
/*     dd98:	3c118009 */ 	lui	$s1,%hi(g_MainMesgQueue)
/*     dd9c:	ac321554 */ 	sw	$s2,%lo(g_RdpOutBufferStart)($at)
/*     dda0:	26310160 */ 	addiu	$s1,$s1,%lo(g_MainMesgQueue)
/*     dda4:	3c018006 */ 	lui	$at,%hi(g_RdpOutBufferEnd)
/*     dda8:	264c0800 */ 	addiu	$t4,$s2,0x800
/*     ddac:	ac2c1550 */ 	sw	$t4,%lo(g_RdpOutBufferEnd)($at)
/*     ddb0:	02202025 */ 	or	$a0,$s1,$zero
/*     ddb4:	27a51478 */ 	addiu	$a1,$sp,0x1478
/*     ddb8:	0c0126b0 */ 	jal	osRecvMesg
/*     ddbc:	00003025 */ 	or	$a2,$zero,$zero
/*     ddc0:	14400006 */ 	bnez	$v0,.NB0000dddc
/*     ddc4:	02202025 */ 	or	$a0,$s1,$zero
.NB0000ddc8:
/*     ddc8:	27a51478 */ 	addiu	$a1,$sp,0x1478
/*     ddcc:	0c0126b0 */ 	jal	osRecvMesg
/*     ddd0:	00003025 */ 	or	$a2,$zero,$zero
/*     ddd4:	5040fffc */ 	beqzl	$v0,.NB0000ddc8
/*     ddd8:	02202025 */ 	or	$a0,$s1,$zero
.NB0000dddc:
/*     dddc:	3c128006 */ 	lui	$s2,%hi(var8005dcc8)
/*     dde0:	00008025 */ 	or	$s0,$zero,$zero
/*     dde4:	2652f5e8 */ 	addiu	$s2,$s2,%lo(var8005dcc8)
/*     dde8:	02202025 */ 	or	$a0,$s1,$zero
.NB0000ddec:
/*     ddec:	27a51478 */ 	addiu	$a1,$sp,0x1478
/*     ddf0:	0c0126b0 */ 	jal	osRecvMesg
/*     ddf4:	24060001 */ 	addiu	$a2,$zero,0x1
/*     ddf8:	8faa1478 */ 	lw	$t2,0x1478($sp)
/*     ddfc:	24010001 */ 	addiu	$at,$zero,0x1
/*     de00:	27ae1458 */ 	addiu	$t6,$sp,0x1458
/*     de04:	854b0000 */ 	lh	$t3,0x0($t2)
/*     de08:	5561000b */ 	bnel	$t3,$at,.NB0000de38
/*     de0c:	2a010006 */ 	slti	$at,$s0,0x6
/*     de10:	0c002871 */ 	jal	viUpdateMode
/*     de14:	afae0054 */ 	sw	$t6,0x54($sp)
/*     de18:	3c058006 */ 	lui	$a1,%hi(var8005dcf0)
/*     de1c:	24a5f610 */ 	addiu	$a1,$a1,%lo(var8005dcf0)
/*     de20:	02402025 */ 	or	$a0,$s2,$zero
/*     de24:	00003025 */ 	or	$a2,$zero,$zero
/*     de28:	0c00c411 */ 	jal	rdpCreateTask
/*     de2c:	8fa70054 */ 	lw	$a3,0x54($sp)
/*     de30:	26100001 */ 	addiu	$s0,$s0,0x1
/*     de34:	2a010006 */ 	slti	$at,$s0,0x6
.NB0000de38:
/*     de38:	5420ffec */ 	bnezl	$at,.NB0000ddec
/*     de3c:	02202025 */ 	or	$a0,$s1,$zero
/*     de40:	10000004 */ 	beqz	$zero,.NB0000de54
/*     de44:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000de48:
/*     de48:	240f0001 */ 	addiu	$t7,$zero,0x1
/*     de4c:	3c018006 */ 	lui	$at,%hi(g_DoBootPakMenu)
/*     de50:	ac2ff2f4 */ 	sw	$t7,%lo(g_DoBootPakMenu)($at)
.NB0000de54:
/*     de54:	0c001c6c */ 	jal	vmInit
/*     de58:	00000000 */ 	sll	$zero,$zero,0x0
/*     de5c:	0fc68554 */ 	jal	func0f1a78b0
/*     de60:	00000000 */ 	sll	$zero,$zero,0x0
/*     de64:	0fc585fd */ 	jal	filesInit
/*     de68:	00000000 */ 	sll	$zero,$zero,0x0
/*     de6c:	0fc5c2fc */ 	jal	stub0f175f50
/*     de70:	00000000 */ 	sll	$zero,$zero,0x0
/*     de74:	0fc5c30c */ 	jal	func0f175f90
/*     de78:	00000000 */ 	sll	$zero,$zero,0x0
/*     de7c:	3c198006 */ 	lui	$t9,%hi(var8005d9b0)
/*     de80:	8f39f2d0 */ 	lw	$t9,%lo(var8005d9b0)($t9)
/*     de84:	13200003 */ 	beqz	$t9,.NB0000de94
/*     de88:	3c047005 */ 	lui	$a0,%hi(var70053aa0)
/*     de8c:	0c004dd3 */ 	jal	argSetString
/*     de90:	248450f0 */ 	addiu	$a0,$a0,%lo(var70053aa0)
.NB0000de94:
/*     de94:	3c04800b */ 	lui	$a0,%hi(_bssSegmentEnd)
/*     de98:	0c013100 */ 	jal	osVirtualToPhysical
/*     de9c:	24841a70 */ 	addiu	$a0,$a0,%lo(_bssSegmentEnd)
/*     dea0:	3c038009 */ 	lui	$v1,%hi(g_VmMarker)
/*     dea4:	8c6330f0 */ 	lw	$v1,%lo(g_VmMarker)($v1)
/*     dea8:	3c018000 */ 	lui	$at,0x8000
/*     deac:	00412025 */ 	or	$a0,$v0,$at
/*     deb0:	0c004996 */ 	jal	mempSetHeap
/*     deb4:	00642823 */ 	subu	$a1,$v1,$a0
/*     deb8:	0c004ab1 */ 	jal	mempResetPool
/*     debc:	24040008 */ 	addiu	$a0,$zero,0x8
/*     dec0:	0c004ab1 */ 	jal	mempResetPool
/*     dec4:	24040006 */ 	addiu	$a0,$zero,0x6
/*     dec8:	0c003535 */ 	jal	crashReset
/*     decc:	00000000 */ 	sll	$zero,$zero,0x0
/*     ded0:	0fc02bb0 */ 	jal	challengesInit
/*     ded4:	00000000 */ 	sll	$zero,$zero,0x0
/*     ded8:	0fc5c69f */ 	jal	utilsInit
/*     dedc:	00000000 */ 	sll	$zero,$zero,0x0
/*     dee0:	0c000dbc */ 	jal	func000034d0
/*     dee4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dee8:	0fc02b90 */ 	jal	texInit
/*     deec:	00000000 */ 	sll	$zero,$zero,0x0
/*     def0:	0fc00000 */ 	jal	langInit
/*     def4:	00000000 */ 	sll	$zero,$zero,0x0
/*     def8:	0fc5890e */ 	jal	lvInit
/*     defc:	00000000 */ 	sll	$zero,$zero,0x0
/*     df00:	0fc40c5b */ 	jal	cheatsInit
/*     df04:	00000000 */ 	sll	$zero,$zero,0x0
/*     df08:	0c003c68 */ 	jal	func0000e9c0
/*     df0c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df10:	0fc53628 */ 	jal	textInit
/*     df14:	00000000 */ 	sll	$zero,$zero,0x0
/*     df18:	0c005002 */ 	jal	dhudInit
/*     df1c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df20:	0fc48954 */ 	jal	playermgrInit
/*     df24:	00000000 */ 	sll	$zero,$zero,0x0
/*     df28:	0fc59ef0 */ 	jal	frametimeInit
/*     df2c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df30:	0fc02bac */ 	jal	stub0f00b200
/*     df34:	00000000 */ 	sll	$zero,$zero,0x0
/*     df38:	0c002708 */ 	jal	profileInit
/*     df3c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df40:	0fc0021c */ 	jal	stub0f000870
/*     df44:	00000000 */ 	sll	$zero,$zero,0x0
/*     df48:	0fc00220 */ 	jal	smokesInit
/*     df4c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df50:	0fc00238 */ 	jal	stub0f0008e0
/*     df54:	00000000 */ 	sll	$zero,$zero,0x0
/*     df58:	0fc0023c */ 	jal	stub0f0008f0
/*     df5c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df60:	0fc00240 */ 	jal	stub0f000900
/*     df64:	00000000 */ 	sll	$zero,$zero,0x0
/*     df68:	0fc02b8c */ 	jal	stub0f00b180
/*     df6c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df70:	0fc00244 */ 	jal	stub0f000910
/*     df74:	00000000 */ 	sll	$zero,$zero,0x0
/*     df78:	0fc00210 */ 	jal	stub0f000840
/*     df7c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df80:	0fc60985 */ 	jal	mpInit
/*     df84:	00000000 */ 	sll	$zero,$zero,0x0
/*     df88:	0fc512be */ 	jal	pheadInit
/*     df8c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df90:	0fc44b4c */ 	jal	paksInit
/*     df94:	00000000 */ 	sll	$zero,$zero,0x0
/*     df98:	0fc512e3 */ 	jal	pheadInit2
/*     df9c:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfa0:	0c0091e8 */ 	jal	animsInit
/*     dfa4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfa8:	0fc00040 */ 	jal	racesInit
/*     dfac:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfb0:	0fc0004c */ 	jal	bodiesInit
/*     dfb4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfb8:	0fc00214 */ 	jal	stub0f000850
/*     dfbc:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfc0:	0fc00218 */ 	jal	stub0f000860
/*     dfc4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfc8:	0fc00024 */ 	jal	titleInit
/*     dfcc:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfd0:	0c002767 */ 	jal	viConfigureForLegal
/*     dfd4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfd8:	0c00281a */ 	jal	viBlack
/*     dfdc:	24040001 */ 	addiu	$a0,$zero,0x1
/*     dfe0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*     dfe4:	3c018006 */ 	lui	$at,%hi(var8005dd18)
/*     dfe8:	8fb00028 */ 	lw	$s0,0x28($sp)
/*     dfec:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*     dff0:	8fb20030 */ 	lw	$s2,0x30($sp)
/*     dff4:	ac20f638 */ 	sw	$zero,%lo(var8005dd18)($at)
/*     dff8:	03e00008 */ 	jr	$ra
/*     dffc:	27bd14e0 */ 	addiu	$sp,$sp,0x14e0
);
#endif

u32 var8005dd3c = 0x00000000;
u32 var8005dd40 = 0x00000000;
u32 var8005dd44 = 0x00000000;
u32 var8005dd48 = 0x00000000;
u32 var8005dd4c = 0x00000000;
u32 var8005dd50 = 0x00000000;
s32 g_MainChangeToStageNum = -1;
bool g_MainIsDebugMenuOpen = false;

#if VERSION < VERSION_NTSC_1_0
void main000e000nb(void)
{
	var8005d9bc = true;
}

void main000e010nb(void)
{
	var8005d9c0 ^= 1;
}
#endif

void mainProc(void)
{
	mainInit();
	rdpInit();
	sndInit();

	while (true) {
		mainLoop();
	}
}

/**
 * It's suspected that this function would have allowed developers to override
 * the value of variables while the game is running in order to view their
 * effects immediately rather than having to recompile the game each time.
 *
 * The developers would have used rmon to create a table of name/value pairs,
 * then this function would have looked up the given variable name in the table
 * and written the new value to the variable's address.
 */
void mainOverrideVariable(char *name, void *value)
{
	// empty
}

/**
 * This function enters an infinite loop which iterates once per stage load.
 * Within this loop is an inner loop which runs very frequently and decides
 * whether to run mainTick on each iteration.
 *
 * NTSC beta checks two shorts at an offset 64MB into the development board
 * and refuses to continue if they are not any of the allowed values.
 * Decomp patches these reads in its build system so it can be played
 * without the development board.
 */
void mainLoop(void)
{
	s32 ending = false;
	OSScMsg msg2 = {OS_SC_DONE_MSG};
#if VERSION < VERSION_NTSC_1_0
	s16 *ptr = (s16 *) PHYS_TO_K1(GIO_BASE_REG + 64 * 1024 * 1024);
	bool fail = false;
#endif
	OSMesg msg;
	s32 index;
	s32 numplayers;
	u32 stack;

#if VERSION < VERSION_NTSC_1_0 && MATCHING
	if ((ptr[0] != 'OJ' && ptr[0] != 'LS' && ptr[0] != 'PM' && ptr[0] != 'MP')
			|| (ptr[1] != 'FS' && ptr[1] != 'RE')) {
		fail = true;
	}

	if (fail) {
		while (1);
	}
#endif

	func0f175f98();

	var8005d9c4 = 0;
	argGetLevel(&g_StageNum);

	if (g_DoBootPakMenu) {
#if VERSION >= VERSION_NTSC_1_0
		g_Vars.unk0004e4 = 0xfd;
#endif
		g_StageNum = STAGE_BOOTPAKMENU;
	}

	if (g_StageNum != STAGE_TITLE) {
		titleSetNextStage(g_StageNum);

		if (g_StageNum < STAGE_TITLE) {
			func0f01b148(0);

			if (argFindByPrefix(1, "-hard")) {
				lvSetDifficulty(argFindByPrefix(1, "-hard")[0] - '0');
			}
		}
	}

	if (g_StageNum == STAGE_CITRAINING && IS4MB()) {
		g_StageNum = STAGE_4MBMENU;
	}

	rngSetSeed(osGetCount());

	// Outer loop - this is infinite because ending is never changed
	while (!ending) {
		g_MainNumGfxTasks = 0;
		g_MainGameLogicEnabled = true;
		msg = NULL;
		g_MainIsEndscreen = false;

		if (var8005d9b0 && var8005d9c4 == 0) {
			index = -1;

			if (IS4MB()) {
				if (g_StageNum < STAGE_TITLE && getNumPlayers() >= 2) {
					index = 0; \
					while (g_StageAllocations4Mb[index].stagenum) { \
						if (g_StageAllocations4Mb[index].stagenum == g_StageNum + 400) { \
							break; \
						} \
						index++;
					}

					if (g_StageAllocations4Mb[index].stagenum == 0) {
						index = -1;
					}
				}

				if (index);

				if (index < 0) {
					index = 0;
					while (g_StageAllocations4Mb[index].stagenum) {
						if (g_StageNum == g_StageAllocations4Mb[index].stagenum) {
							break;
						}

						index++;
					}
				}

				argSetString(g_StageAllocations4Mb[index].string);
			} else {
				// 8MB
				if (g_StageNum < STAGE_TITLE && getNumPlayers() >= 2) {
					index = 0; \
					while (g_StageAllocations8Mb[index].stagenum) { \
						if (g_StageNum + 400 == g_StageAllocations8Mb[index].stagenum) { \
							break; \
						} \
						index++;
					}

					if (g_StageAllocations8Mb[index].stagenum == 0) {
						index = -1;
					}
				}

				if (index < 0) {
					index = 0;

					while (g_StageAllocations8Mb[index].stagenum) {
						if (g_StageNum == g_StageAllocations8Mb[index].stagenum) {
							break;
						}

						index++;
					}
				}

				argSetString(g_StageAllocations8Mb[index].string);
			}
		}

		var8005d9c4 = 0;

		mempResetPool(MEMPOOL_7);
		mempResetPool(MEMPOOL_STAGE);
		filesStop(4);

		if (argFindByPrefix(1, "-ma")) {
			g_MainMemaHeapSize = strtol(argFindByPrefix(1, "-ma"), NULL, 0) * 1024;
		}

		memaReset(mempAlloc(g_MainMemaHeapSize, MEMPOOL_STAGE), g_MainMemaHeapSize);
		langReset(g_StageNum);
		playermgrReset();

		if (g_StageNum >= STAGE_TITLE) {
			numplayers = 0;
		} else {
			if (argFindByPrefix(1, "-play")) {
				numplayers = strtol(argFindByPrefix(1, "-play"), NULL, 0);
			} else {
				numplayers = 1;
			}

			if (getNumPlayers() >= 2) {
				numplayers = getNumPlayers();
			}
		}

		if (numplayers < 2) {
			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = -1;
			g_Vars.antiplayernum = -1;
		} else if (argFindByPrefix(1, "-coop")) {
			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = 1;
			g_Vars.antiplayernum = -1;
		} else if (argFindByPrefix(1, "-anti")) {
			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = -1;
			g_Vars.antiplayernum = 1;
		}

		playermgrAllocatePlayers(numplayers);

		if (argFindByPrefix(1, "-mpbots")) {
			g_Vars.lvmpbotlevel = 1;
		}

		if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
			g_MpSetup.chrslots = 0x03;
			mpReset();
		} else if (g_Vars.perfectbuddynum) {
			mpReset();
		} else if (g_Vars.mplayerisrunning == false
				&& (numplayers >= 2 || g_Vars.lvmpbotlevel || argFindByPrefix(1, "-play"))) {
			g_MpSetup.chrslots = 1;

			if (numplayers >= 2) {
				g_MpSetup.chrslots |= 1 << 1;
			}

			if (numplayers >= 3) {
				g_MpSetup.chrslots |= 1 << 2;
			}

			if (numplayers >= 4) {
				g_MpSetup.chrslots |= 1 << 3;
			}

			g_MpSetup.stagenum = g_StageNum;
			mpReset();
		}

		gfxReset();
		joyReset();
		dhudReset();
		mblurReset(g_StageNum);
		lvReset(g_StageNum);
		viReset(g_StageNum);
		frametimeCalculate();
		profileReset();

		while (osRecvMesg(&g_MainMesgQueue, &msg, OS_MESG_NOBLOCK) != -1) {
			// empty
		}

		while (g_MainChangeToStageNum < 0 || g_MainNumGfxTasks != 0) {
			s32 cycles;

			osRecvMesg(&g_MainMesgQueue, &msg, OS_MESG_BLOCK);

#if VERSION < VERSION_NTSC_1_0
			bootCheckStackOverflow();
#endif

			switch (*(s16 *) msg) {
			case OS_SC_RETRACE_MSG:
				cycles = osGetCount() - g_Vars.thisframestartt;

				if (cycles >= g_Vars.mininc60 * CYCLES_PER_FRAME - CYCLES_PER_FRAME / 2) {
					mainTick();
				}
				break;
			case OS_SC_DONE_MSG:
				g_MainNumGfxTasks--;
				break;
			case OS_SC_PRE_NMI_MSG:
				// This seems to be a hack to get this loop to keep ticking...
				// maybe graphics tasks stop being created after pre NMI?
				g_MainNumGfxTasks = 4;
				break;
#if VERSION < VERSION_NTSC_1_0
			default:
				{
					char message[80];
					u32 stack2;
					sprintf(message, "boss.c default: %08x type %d\n", (s32) msg, *(s16 *) msg);
					crashSetMessage(message);
					CRASH();
				}
				break;
#endif
			}
		}

		lvStop();
		mempDisablePool(MEMPOOL_STAGE);
		mempDisablePool(MEMPOOL_7);
		filesStop(4);
		viBlack(true);
#if VERSION >= VERSION_NTSC_1_0
		pak0f116994();
#endif

		g_StageNum = g_MainChangeToStageNum;
		g_MainChangeToStageNum = -1;
	}

	// Unreachable
	func0f175fc8();
}

void mainTick(void)
{
	Gfx *gdl;
	Gfx *gdlstart;
	OSScMsg msg = {OS_SC_DONE_MSG};
	s32 i;

	if (g_MainChangeToStageNum < 0 && g_MainNumGfxTasks < 2) {
		frametimeCalculate();
		profile00009a98();
		profileReset();
		profileSetMarker(PROFILE_MAINTICK_START);
		func000034d8();
		joyDebugJoy();
		schedSetCrashEnable2(false);

		if (g_MainGameLogicEnabled) {
			gdl = gdlstart = gfxGetMasterDisplayList();

			gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
			gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

#ifdef DEBUG
			if (g_MainIsDebugMenuOpen || joyGetButtons(0, U_CBUTTONS | D_CBUTTONS) == (U_CBUTTONS | D_CBUTTONS)) {
				g_MainIsDebugMenuOpen = debugProcessInput(joyGetStickX(0), joyGetStickY(0), joyGetButtons(0, 0xffff), joyGetButtonsPressedThisFrame(0, 0xffff));
			} else if (joyGetButtons(0, START_BUTTON) == 0) {
				var80075d68 = var800786f4nb;
			} else {
				g_MainIsDebugMenuOpen = debugProcessInput(joyGetStickX(0), joyGetStickY(0), joyGetButtons(0, 0xffff), joyGetButtonsPressedThisFrame(0, 0xffff));
			}
#endif

			lvTick();
			playermgrShuffle();

			if (g_StageNum < STAGE_TITLE) {
				for (i = 0; i < PLAYERCOUNT(); i++) {
					setCurrentPlayerNum(playermgrGetPlayerAtOrder(i));

					if (g_StageNum != STAGE_TEST_OLD || !titleIsKeepingMode()) {
						viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
						viSetFovAspectAndSize(
								g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
								g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);
					}

					lvTickPlayer();
				}
			}

			gdl = lvRender(gdl);
			func000034e0(&gdl);

#ifdef DEBUG
			if (debugIsLineModeEnabled()) {
				gDPPipeSync(gdl++);
				gDPSetCycleType(gdl++, G_CYC_1CYCLE);
				gDPSetBlendColor(gdl++, 0xff, 0xff, 0xff, 0xff);
				gDPSetPrimDepth(gdl++, 0xffff, 0xffff);
				gDPSetDepthSource(gdl++, G_ZS_PRIM);
				gDPSetRenderMode(gdl++, G_RM_VISCVG, G_RM_VISCVG2);
				gDPFillRectangle(gdl++, 0, 0, viGetWidth() - 1, viGetHeight() - 1);
			}

			gdl = dhudRender(gdl);
			dhudClear();
#endif

			if (debugGetProfileMode() >= 2) {
				gdl = profileRender(gdl);
			}

#ifdef DEBUG
			if (g_MainIsDebugMenuOpen) {
				debugUpdateMenu();
				gdl = dmenuRender(gdl);
			}
#endif

			gDPFullSync(gdl++);
			gSPEndDisplayList(gdl++);
		}

		if (g_MainGameLogicEnabled) {
			gfxSwapBuffers();
			viUpdateMode();
		}

		rdpCreateTask(gdlstart, gdl, 0, &msg);
		g_MainNumGfxTasks++;
		memaPrint();
		func0f16cf94();
		profileSetMarker(PROFILE_MAINTICK_END);

#if VERSION == VERSION_PAL_BETA
		debug0f119a80nb();
#endif
	}
}

void mainEndStage(void)
{
	sndStopNosedive();

	if (!g_MainIsEndscreen) {
#if VERSION >= VERSION_NTSC_1_0
		pak0f11c6d0();
#endif
		joyDisableTemporarily();

		if (g_Vars.coopplayernum >= 0) {
			s32 prevplayernum = g_Vars.currentplayernum;
			s32 i;

			for (i = 0; i < PLAYERCOUNT(); i++) {
				setCurrentPlayerNum(i);
				endscreenPushCoop();
			}

			setCurrentPlayerNum(prevplayernum);
			musicStartMenu();
		} else if (g_Vars.antiplayernum >= 0) {
			s32 prevplayernum = g_Vars.currentplayernum;
			s32 i;

			for (i = 0; i < PLAYERCOUNT(); i++) {
				setCurrentPlayerNum(i);
				endscreenPushAnti();
			}

			setCurrentPlayerNum(prevplayernum);
			musicStartMenu();
		} else if (g_Vars.normmplayerisrunning) {
			mpEndMatch();
		} else {
			endscreenPrepare();
			musicStartMenu();
		}
	}

	g_MainIsEndscreen = true;
}

/**
 * Change to the given stage at the end of the current frame.
 */
void mainChangeToStage(s32 stagenum)
{
#if VERSION >= VERSION_NTSC_1_0
	pak0f11c6d0();
#endif

	g_MainChangeToStageNum = stagenum;
}

s32 mainGetStageNum(void)
{
	return g_StageNum;
}

void func0000e990(void)
{
	objectivesCheckAll();
	objectivesDisableChecking();
	mainEndStage();
}

void func0000e9c0(void)
{
	// empty
}
