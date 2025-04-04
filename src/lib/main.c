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
#include "game/text.h"
#include "game/gfxmemory.h"
#include "game/lang.h"
#include "game/lv.h"
#include "game/timing.h"
#include "game/music.h"
#include "game/stubs/game_175f50.h"
#include "game/game_175f90.h"
#include "game/zbuf.h"
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

// main_loop calls rng_set_seed with a u32 argument,
// but the function takes a u64 so an incorrect declaration is needed.
void rng_set_seed(u32 seed);

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

s32 g_MainIsBooting = 1;

extern u8 _accessingpakSegmentRomStart;
extern u8 _accessingpakSegmentRomEnd;
extern u8 _copyrightSegmentRomStart;
extern u8 _copyrightSegmentRomEnd;
extern u8 _bssSegmentEnd;

void main_tick(void);
void func0000e9c0(void);

/**
 * Initialise various subsystems, display the copyright or accessing pak texture,
 * then initialise more subsystems.
 */
void main_init(void)
{
	s32 x;
	s32 dsty;
	OSMesg msg;
	u16 *texture;
	OSTimer timer;
	OSMesgQueue queue;
	s32 i;
	s32 j;
	u16 *fb;
	s32 srcy;
	u32 addr;
	u8 *start;

	fault_init();
	dma_init();
	amgr_init();
	vars_init();
	memp_init();
	mema_init();
	videbug_init();
	vi_configure_for_logos();
	var8005d9b0 = rmon_is_disabled();
	joy_init();
	osCreateMesgQueue(&queue, &msg, 1);

	// Wait a bit, reset the controllers and wait a bit more
	for (i = 0; i < 4; i++) {
		osSetTimer(&timer, OS_CPU_COUNTER / 60 * 6, 0, &queue, &msg);
		osRecvMesg(&queue, &msg, OS_MESG_BLOCK);

		if (i == 1) {
			joy_reset();
		} else if (i >= 2) {
			joy_debug_joy();
		}

#if VERSION >= VERSION_NTSC_1_0
		if (1);
		if (1);
#endif
	}

	if (arg_find_by_prefix(1, "-level_") == NULL) {
		var8005d9b0 = true;
	}

#if VERSION >= VERSION_NTSC_1_0
	// If holding start on any controller, open boot pak menu
	if (joy_get_buttons(0, START_BUTTON) == 0
			&& joy_get_buttons(1, START_BUTTON) == 0
			&& joy_get_buttons(2, START_BUTTON) == 0
			&& joy_get_buttons(3, START_BUTTON) == 0) {
		g_DoBootPakMenu = false;
	} else {
		g_DoBootPakMenu = true;
	}

#if VERSION == VERSION_PAL_BETA
	// In PAL beta, pressing all C buttons during poweron sets g_CrashEnabled.
	// If it's set, a sound effect is played on the legal screen to confirm
	// and the crash screen will be shown if the game crashes.
#define BUTTON_MASK (U_CBUTTONS | D_CBUTTONS | L_CBUTTONS | R_CBUTTONS)

	if (joy_get_buttons(0, BUTTON_MASK) == BUTTON_MASK
			|| joy_get_buttons(1, BUTTON_MASK) == BUTTON_MASK
			|| joy_get_buttons(2, BUTTON_MASK) == BUTTON_MASK
			|| joy_get_buttons(3, BUTTON_MASK) == BUTTON_MASK) {
		g_CrashEnabled = true;
	}
#endif

	{
		s32 numpages;
		OSMesg receivedmsg = NULL;
		OSScMsg scdonemsg = { OS_SC_DONE_MSG };
		u8 scratch[1024 * 5];
#if PAL
		u32 stack[2];
#endif

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
			addr -= 8; // markers for stack overflow detection
			addr -= g_VmNumPages * 8; // vm state table
			addr -= VM_NUM_SLOTS * VM_PAGE_SIZE; // vm loaded pages buffer
			addr -= addr % 0x2000; // align down to a multiple of 0x2000
			addr -= VM_BIGGEST_ZIP; // buffer for single biggest game zip
		} else {
			addr = K0BASE + 8 * 1024 * 1024;
		}

		addr -= 640 * 480 * NUM_FRAMEBUFFERS; // the framebuffer itself
		addr -= 0x40; // align down to a multiple of 0x40

		fb = (u16 *) ALIGN64(PHYS_TO_K0(addr));

		// Prepare space for the unzipped texture immediately before the framebuffer.
		// Both textures are 507x48.
		texture = fb - 507 * 48;

		// DMA the compressed texture from the ROM to the framebuffer.
		// It's using the framebuffer as a temporary data buffer.
		if (g_DoBootPakMenu) {
			dma_exec(fb, (romptr_t) &_accessingpakSegmentRomStart, &_accessingpakSegmentRomEnd - &_accessingpakSegmentRomStart);
		} else {
			dma_exec(fb, (romptr_t) &_copyrightSegmentRomStart, &_copyrightSegmentRomEnd - &_copyrightSegmentRomStart);
		}

		// This is required for a match
		numpages = g_VmNumPages;
		if ((f64) numpages && (f64) numpages);

		// Unzip the compressed texture from fb to texture
		rzip_inflate(fb, texture, scratch);

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

		vi_set_mode(VIMODE_HI);
		vi_configure_for_copyright(fb);

		g_RdpOutBufferStart = texture;
		g_RdpOutBufferEnd = texture + 0x400; // 0x800 bytes, because texture is u16

		while (osRecvMesg(&g_MainMesgQueue, &receivedmsg, OS_MESG_NOBLOCK) == 0) {
			// empty
		}

		j = 0;

		while (j < 6) {
			osRecvMesg(&g_MainMesgQueue, &receivedmsg, OS_MESG_BLOCK);

			if (*(s16 *) receivedmsg == OS_SC_RETRACE_MSG) {
				vi_update_mode();
				rdp_create_task(var8005dcc8, var8005dcc8 + ARRAYCOUNT(var8005dcc8), 0, (s32) &scdonemsg);
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

	if (joy_get_buttons(0, START_BUTTON) == 0
			&& joy_get_buttons(1, START_BUTTON) == 0
			&& joy_get_buttons(2, START_BUTTON) == 0
			&& joy_get_buttons(3, START_BUTTON) == 0) {
		s32 numpages;
		OSMesg receivedmsg = NULL;
		OSScMsg scdonemsg = { OS_SC_DONE_MSG };
		u8 scratch[1024 * 5];

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
			addr -= VM_NUM_SLOTS * VM_PAGE_SIZE; // vm loaded pages buffer
			addr -= addr % 0x2000; // align down to a multiple of 0x2000
			addr -= VM_BIGGEST_ZIP; // buffer for single biggest game zip
		} else {
			addr = K0BASE + 8 * 1024 * 1024;
		}

		addr -= 640 * 480 * NUM_FRAMEBUFFERS; // the framebuffer itself
		addr -= 0x40; // align down to a multiple of 0x40

		fb = (u16 *) ALIGN64(PHYS_TO_K0(addr));

		// Prepare space for the unzipped texture immediately before the framebuffer.
		// Both textures are 507x48.
		texture = fb - 507 * 48;

		// DMA the compressed texture from the ROM to the framebuffer.
		// It's using the framebuffer as a temporary data buffer.
		dma_exec(fb, (romptr_t) &_copyrightSegmentRomStart, &_copyrightSegmentRomEnd - &_copyrightSegmentRomStart);

		numpages = g_VmNumPages;
		if ((f64) numpages && (f64) numpages);

		// Unzip the compressed texture from fb to texture
		rzip_inflate(fb, texture, scratch);

		// Clear the framebuffer except for the bottom 48 rows,
		// because that's where the texture will go.
		// The increment here is too small, so some pixels are zeroed twice.
		for (dsty = 0; dsty < (480 - 48) * 640; dsty += 576) {
			if (1);
			for (i = 0; i < 640; i++) {
				fb[dsty + i] = 0;
			}
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

		vi_set_mode(VIMODE_HI);
		vi_configure_for_copyright(fb);

		g_RdpOutBufferStart = texture;
		g_RdpOutBufferEnd = texture + 0x400; // 0x800 bytes, because texture is u16

		while (osRecvMesg(&g_MainMesgQueue, &receivedmsg, OS_MESG_NOBLOCK) == 0);

		i = 0;

		while (i < 6) {
			osRecvMesg(&g_MainMesgQueue, &receivedmsg, OS_MESG_BLOCK);

			if (*(s16 *) receivedmsg == OS_SC_RETRACE_MSG) {
				vi_update_mode();
				rdp_create_task(var8005dcc8, var8005dcc8 + ARRAYCOUNT(var8005dcc8), 0, (s32) &scdonemsg);
				i++;
			}
		}
	} else {
		g_DoBootPakMenu = true;
	}
#endif

	vm_init();
	func0f1a78b0();
	files_init();
	stub0f175f50();
	func0f175f90();

	if (var8005d9b0) {
		arg_set_string("          -ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400");
	}

	start = (u8 *) PHYS_TO_K0(osVirtualToPhysical(&_bssSegmentEnd));
	if (g_VmMarker);
	memp_set_heap(start, g_VmMarker - start);

	memp_reset_pool(MEMPOOL_8);
	memp_reset_pool(MEMPOOL_PERMANENT);
	crash_reset();
	challenges_init();
	utils_init();
	func000034d0();
	tex_init();
	lang_init();
	lv_init();
	cheats_init();
	func0000e9c0();
	text_init();
	dhud_init();
	playermgr_init();
	frametime_init();
	stub0f00b200();
	profile_init();
	stub0f000870();
	smokes_init();
	stub0f0008e0();
	stub0f0008f0();
	stub0f000900();
	stub0f00b180();
	stub0f000910();
	stub0f000840();
	mp_init();
	camdraw_init();
	paks_init();
	camdraw_init_afterpaks();
	anims_init();
	races_init();
	bodies_init();
	stub0f000850();
	stub0f000860();
	title_init();
	vi_configure_for_legal();
	vi_black(true);

	g_MainIsBooting = 0;

#if VERSION >= VERSION_PAL_BETA && VERSION < VERSION_JPN_FINAL
	if (g_DoBootPakMenu) {
		osGetCount();
	}
#endif
}

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

void main_proc(void)
{
	main_init();
	rdp_init();
	snd_init();

	while (true) {
		main_loop();
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
void main_override_variable(char *name, void *value)
{
	// empty
}

/**
 * This function enters an infinite loop which iterates once per stage load.
 * Within this loop is an inner loop which runs very frequently and decides
 * whether to run main_tick on each iteration.
 *
 * NTSC beta checks two shorts at an offset 64MB into the development board
 * and refuses to continue if they are not any of the allowed values.
 * Decomp patches these reads in its build system so it can be played
 * without the development board.
 */
void main_loop(void)
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
	arg_get_level(&g_StageNum);

	if (g_DoBootPakMenu) {
#if VERSION >= VERSION_NTSC_1_0
		g_Vars.pakstocheck = 0xfd;
#endif
		g_StageNum = STAGE_BOOTPAKMENU;
	}

	if (g_StageNum != STAGE_TITLE) {
		title_set_next_stage(g_StageNum);

		if (g_StageNum < STAGE_TITLE) {
			func0f01b148(0);

			if (arg_find_by_prefix(1, "-hard")) {
				lv_set_difficulty(arg_find_by_prefix(1, "-hard")[0] - '0');
			}
		}
	}

	if (g_StageNum == STAGE_CITRAINING && IS4MB()) {
		g_StageNum = STAGE_4MBMENU;
	}

	rng_set_seed(osGetCount());

	// Outer loop - this is infinite because ending is never changed
	while (!ending) {
		g_MainNumGfxTasks = 0;
		g_MainGameLogicEnabled = true;
		msg = NULL;
		g_MainIsEndscreen = false;

		if (var8005d9b0 && var8005d9c4 == 0) {
			index = -1;

			if (IS4MB()) {
				if (g_StageNum < STAGE_TITLE && get_num_players() >= 2) {
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

				arg_set_string(g_StageAllocations4Mb[index].string);
			} else {
				// 8MB
				if (g_StageNum < STAGE_TITLE && get_num_players() >= 2) {
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

				arg_set_string(g_StageAllocations8Mb[index].string);
			}
		}

		var8005d9c4 = 0;

		memp_reset_pool(MEMPOOL_7);
		memp_reset_pool(MEMPOOL_STAGE);
		files_stop(4);

		if (arg_find_by_prefix(1, "-ma")) {
			g_MainMemaHeapSize = strtol(arg_find_by_prefix(1, "-ma"), NULL, 0) * 1024;
		}

		mema_reset(memp_alloc(g_MainMemaHeapSize, MEMPOOL_STAGE), g_MainMemaHeapSize);
		lang_reset(g_StageNum);
		playermgr_reset();

		if (g_StageNum >= STAGE_TITLE) {
			numplayers = 0;
		} else {
			if (arg_find_by_prefix(1, "-play")) {
				numplayers = strtol(arg_find_by_prefix(1, "-play"), NULL, 0);
			} else {
				numplayers = 1;
			}

			if (get_num_players() >= 2) {
				numplayers = get_num_players();
			}
		}

		if (numplayers < 2) {
			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = -1;
			g_Vars.antiplayernum = -1;
		} else if (arg_find_by_prefix(1, "-coop")) {
			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = 1;
			g_Vars.antiplayernum = -1;
		} else if (arg_find_by_prefix(1, "-anti")) {
			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = -1;
			g_Vars.antiplayernum = 1;
		}

		playermgr_allocate_players(numplayers);

		if (arg_find_by_prefix(1, "-mpbots")) {
			g_Vars.lvmpbotlevel = 1;
		}

		if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
			g_MpSetup.chrslots = 0x03;
			mp_reset();
		} else if (g_Vars.perfectbuddynum) {
			mp_reset();
		} else if (g_Vars.mplayerisrunning == false
				&& (numplayers >= 2 || g_Vars.lvmpbotlevel || arg_find_by_prefix(1, "-play"))) {
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
			mp_reset();
		}

		gfx_reset();
		joy_reset();
		dhud_reset();
		zbuf_reset(g_StageNum);
		lv_reset(g_StageNum);
		vi_reset(g_StageNum);
		frametime_calculate();
		profile_reset();

		while (osRecvMesg(&g_MainMesgQueue, &msg, OS_MESG_NOBLOCK) != -1) {
			// empty
		}

		while (g_MainChangeToStageNum < 0 || g_MainNumGfxTasks != 0) {
			s32 cycles;

			osRecvMesg(&g_MainMesgQueue, &msg, OS_MESG_BLOCK);

#if VERSION < VERSION_NTSC_1_0
			boot_check_stack_overflow();
#endif

			switch (*(s16 *) msg) {
			case OS_SC_RETRACE_MSG:
				cycles = osGetCount() - g_Vars.thisframestartt;

				if (cycles >= g_Vars.mininc60 * CYCLES_PER_FRAME - CYCLES_PER_FRAME / 2) {
					main_tick();
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
					crash_set_message(message);
					CRASH();
				}
				break;
#endif
			}
		}

		lv_stop();
		memp_disable_pool(MEMPOOL_STAGE);
		memp_disable_pool(MEMPOOL_7);
		files_stop(4);
		vi_black(true);
#if VERSION >= VERSION_NTSC_1_0
		pak0f116994();
#endif

		g_StageNum = g_MainChangeToStageNum;
		g_MainChangeToStageNum = -1;
	}

	// Unreachable
	func0f175fc8();
}

void main_tick(void)
{
	Gfx *gdl;
	Gfx *gdlstart;
	OSScMsg msg = {OS_SC_DONE_MSG};
	s32 i;

	if (g_MainChangeToStageNum < 0 && g_MainNumGfxTasks < NUM_GFXTASKS) {
		frametime_calculate();
		profile00009a98();
		profile_reset();
		profile_set_marker(PROFILE_MAINTICK_START);
		func000034d8();
		joy_debug_joy();
		sched_set_crash_enable2(false);

		if (g_MainGameLogicEnabled) {
			gdl = gdlstart = gfx_get_master_display_list();

			gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
			gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

#ifdef DEBUG
			if (g_MainIsDebugMenuOpen || joy_get_buttons(0, U_CBUTTONS | D_CBUTTONS) == (U_CBUTTONS | D_CBUTTONS)) {
				g_MainIsDebugMenuOpen = debug_process_input(joy_get_stick_x(0), joy_get_stick_y(0), joy_get_buttons(0, 0xffff), joy_get_buttons_pressed_this_frame(0, 0xffff));
			} else if (joy_get_buttons(0, START_BUTTON) == 0) {
				var80075d68 = var800786f4nb;
			} else {
				g_MainIsDebugMenuOpen = debug_process_input(joy_get_stick_x(0), joy_get_stick_y(0), joy_get_buttons(0, 0xffff), joy_get_buttons_pressed_this_frame(0, 0xffff));
			}
#endif

			lv_tick();
			playermgr_shuffle();

			if (g_StageNum < STAGE_TITLE) {
				for (i = 0; i < PLAYERCOUNT(); i++) {
					set_current_player_num(playermgr_get_player_at_order(i));

					if (g_StageNum != STAGE_TEST_OLD || !title_is_keeping_mode()) {
						vi_set_view_position(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
						vi_set_fov_aspect_and_size(
								g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
								g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);
					}

					lv_tick_player();
				}
			}

			gdl = lv_render(gdl);
			func000034e0(&gdl);

#ifdef DEBUG
			if (debug_is_line_mode_enabled()) {
				gDPPipeSync(gdl++);
				gDPSetCycleType(gdl++, G_CYC_1CYCLE);
				gDPSetBlendColor(gdl++, 0xff, 0xff, 0xff, 0xff);
				gDPSetPrimDepth(gdl++, 0xffff, 0xffff);
				gDPSetDepthSource(gdl++, G_ZS_PRIM);
				gDPSetRenderMode(gdl++, G_RM_VISCVG, G_RM_VISCVG2);
				gDPFillRectangle(gdl++, 0, 0, vi_get_width() - 1, vi_get_height() - 1);
			}

			gdl = dhud_render(gdl);
			dhud_clear();
#endif

			if (debug_get_profile_mode() >= 2) {
				gdl = profile_render(gdl);
			}

#ifdef DEBUG
			if (g_MainIsDebugMenuOpen) {
				debug_update_menu();
				gdl = dmenu_render(gdl);
			}
#endif

			gDPFullSync(gdl++);
			gSPEndDisplayList(gdl++);
		}

		if (g_MainGameLogicEnabled) {
			gfx_swap_buffers();
			vi_update_mode();
		}

		rdp_create_task(gdlstart, gdl, 0, (s32) &msg);
		g_MainNumGfxTasks++;
		mema_print();
		func0f16cf94();
		profile_set_marker(PROFILE_MAINTICK_END);

#if VERSION == VERSION_PAL_BETA
#ifdef DEBUG
		debug0f119a80nb();
#endif
#endif
	}
}

void main_end_stage(void)
{
	snd_stop_nosedive();

	if (!g_MainIsEndscreen) {
#if VERSION >= VERSION_NTSC_1_0
		pak0f11c6d0();
#endif
		joy_disable_temporarily();

		if (g_Vars.coopplayernum >= 0) {
			s32 prevplayernum = g_Vars.currentplayernum;
			s32 i;

			for (i = 0; i < PLAYERCOUNT(); i++) {
				set_current_player_num(i);
				endscreen_push_coop();
			}

			set_current_player_num(prevplayernum);
			music_start_menu();
		} else if (g_Vars.antiplayernum >= 0) {
			s32 prevplayernum = g_Vars.currentplayernum;
			s32 i;

			for (i = 0; i < PLAYERCOUNT(); i++) {
				set_current_player_num(i);
				endscreen_push_anti();
			}

			set_current_player_num(prevplayernum);
			music_start_menu();
		} else if (g_Vars.normmplayerisrunning) {
			mp_end_match();
		} else {
			endscreen_prepare();
			music_start_menu();
		}
	}

	g_MainIsEndscreen = true;
}

/**
 * Change to the given stage at the end of the current frame.
 */
void main_change_to_stage(s32 stagenum)
{
#if VERSION >= VERSION_NTSC_1_0
	pak0f11c6d0();
#endif

	g_MainChangeToStageNum = stagenum;
}

s32 main_get_stage_num(void)
{
	return g_StageNum;
}

void func0000e990(void)
{
	objectives_check_all();
	objectives_disable_checking();
	main_end_stage();
}

void func0000e9c0(void)
{
	// empty
}
