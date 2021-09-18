#include <ultra64.h>
#include "lib/sched.h"
#include "constants.h"
#include "game/camdraw.h"
#include "game/cheats.h"
#include "game/debug.h"
#include "game/game_000000.h"
#include "game/game_000090.h"
#include "game/game_000130.h"
#include "game/stubs/game_000840.h"
#include "game/stubs/game_000850.h"
#include "game/stubs/game_000860.h"
#include "game/stubs/game_000870.h"
#include "game/game_000880.h"
#include "game/stubs/game_0008e0.h"
#include "game/stubs/game_0008f0.h"
#include "game/stubs/game_000900.h"
#include "game/stubs/game_000910.h"
#include "game/game_00b190.h"
#include "game/stubs/game_00b180.h"
#include "game/stubs/game_00b200.h"
#include "game/game_00b210.h"
#include "game/game_00b320.h"
#include "game/title.h"
#include "game/game_01b0a0.h"
#include "game/game_095320.h"
#include "game/endscreen.h"
#include "game/game_127910.h"
#include "game/game_1531a0.h"
#include "game/gfxmemory.h"
#include "game/lv.h"
#include "game/timing.h"
#include "game/music.h"
#include "game/stubs/game_175f50.h"
#include "game/game_175f90.h"
#include "game/game_176080.h"
#include "game/game_1a78b0.h"
#include "game/mplayer/mplayer.h"
#include "game/pak/pak.h"
#include "game/splat.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/args.h"
#include "lib/lib_070d0.h"
#include "lib/lib_074f0.h"
#include "lib/lib_09660.h"
#include "lib/lib_09a80.h"
#include "lib/lib_0bfb0.h"
#include "lib/lib_0c000.h"
#include "lib/dma.h"
#include "lib/main.h"
#include "lib/snd.h"
#include "lib/memory.h"
#include "lib/lib_126b0.h"
#include "lib/lib_13750.h"
#include "lib/lib_13790.h"
#include "lib/lib_233c0.h"
#include "lib/rdp.h"
#include "lib/lib_2f490.h"
#include "lib/lib_2fa00.h"
#include "data.h"
#include "types.h"

s32 var8005d9b0 = 0;
s32 g_StageNum = STAGE_TITLE;
u32 var8005d9b8 = 0x0004b000;
s32 var8005d9bc = 0;
s32 var8005d9c0 = 0;
s32 var8005d9c4 = 0;
s32 var8005d9c8 = 1;
u32 var8005d9cc = 0;
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

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel mainInit
/*     d260:	27bdeb20 */ 	addiu	$sp,$sp,-5344
/*     d264:	afbf002c */ 	sw	$ra,0x2c($sp)
/*     d268:	0c002f3c */ 	jal	faultCreateThread
/*     d26c:	afb00028 */ 	sw	$s0,0x28($sp)
/*     d270:	0c003378 */ 	jal	dmaInit
/*     d274:	00000000 */ 	nop
/*     d278:	0c002258 */ 	jal	amgrAllocateStack
/*     d27c:	00000000 */ 	nop
/*     d280:	0c00557c */ 	jal	gvarsInit
/*     d284:	00000000 */ 	nop
/*     d288:	0c0047dc */ 	jal	func000121e0
/*     d28c:	00000000 */ 	nop
/*     d290:	0c0049e7 */ 	jal	func00012a0c
/*     d294:	00000000 */ 	nop
/*     d298:	0c004d3a */ 	jal	func00013758
/*     d29c:	00000000 */ 	nop
/*     d2a0:	0c002668 */ 	jal	func00009ab0
/*     d2a4:	00000000 */ 	nop
/*     d2a8:	0c00bcc2 */ 	jal	rmonIsDisabled
/*     d2ac:	00000000 */ 	nop
/*     d2b0:	3c018006 */ 	lui	$at,0x8006
/*     d2b4:	0c004e87 */ 	jal	joySystemInit
/*     d2b8:	ac22d650 */ 	sw	$v0,-0x29b0($at)
/*     d2bc:	27a41498 */ 	addiu	$a0,$sp,0x1498
/*     d2c0:	27a514d4 */ 	addiu	$a1,$sp,0x14d4
/*     d2c4:	0c011f10 */ 	jal	osCreateMesgQueue
/*     d2c8:	24060001 */ 	li	$a2,0x1
/*     d2cc:	00008025 */ 	move	$s0,$zero
/*     d2d0:	3c070047 */ 	lui	$a3,0x47
.PF0000d2d4:
/*     d2d4:	240e0000 */ 	li	$t6,0x0
/*     d2d8:	240f0000 */ 	li	$t7,0x0
/*     d2dc:	27b81498 */ 	addiu	$t8,$sp,0x1498
/*     d2e0:	27b914d4 */ 	addiu	$t9,$sp,0x14d4
/*     d2e4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*     d2e8:	afb80018 */ 	sw	$t8,0x18($sp)
/*     d2ec:	afaf0014 */ 	sw	$t7,0x14($sp)
/*     d2f0:	afae0010 */ 	sw	$t6,0x10($sp)
/*     d2f4:	34e7868c */ 	ori	$a3,$a3,0x868c
/*     d2f8:	27a414b0 */ 	addiu	$a0,$sp,0x14b0
/*     d2fc:	0c012108 */ 	jal	osSetTimer
/*     d300:	24060000 */ 	li	$a2,0x0
/*     d304:	27a41498 */ 	addiu	$a0,$sp,0x1498
/*     d308:	27a514d4 */ 	addiu	$a1,$sp,0x14d4
/*     d30c:	0c011ffc */ 	jal	osRecvMesg
/*     d310:	24060001 */ 	li	$a2,0x1
/*     d314:	24010001 */ 	li	$at,0x1
/*     d318:	56010006 */ 	bnel	$s0,$at,.PF0000d334
/*     d31c:	2a010002 */ 	slti	$at,$s0,0x2
/*     d320:	0c004ee1 */ 	jal	joy00013dfc
/*     d324:	00000000 */ 	nop
/*     d328:	10000007 */ 	b	.PF0000d348
/*     d32c:	26100001 */ 	addiu	$s0,$s0,0x1
/*     d330:	2a010002 */ 	slti	$at,$s0,0x2
.PF0000d334:
/*     d334:	54200004 */ 	bnezl	$at,.PF0000d348
/*     d338:	26100001 */ 	addiu	$s0,$s0,0x1
/*     d33c:	0c00501e */ 	jal	joyDebugJoy
/*     d340:	00000000 */ 	nop
/*     d344:	26100001 */ 	addiu	$s0,$s0,0x1
.PF0000d348:
/*     d348:	24010004 */ 	li	$at,0x4
/*     d34c:	5601ffe1 */ 	bnel	$s0,$at,.PF0000d2d4
/*     d350:	3c070047 */ 	lui	$a3,0x47
/*     d354:	3c057005 */ 	lui	$a1,0x7005
/*     d358:	24a53738 */ 	addiu	$a1,$a1,0x3738
/*     d35c:	0c004b68 */ 	jal	argFindByPrefix
/*     d360:	24040001 */ 	li	$a0,0x1
/*     d364:	14400004 */ 	bnez	$v0,.PF0000d378
/*     d368:	00002025 */ 	move	$a0,$zero
/*     d36c:	240b0001 */ 	li	$t3,0x1
/*     d370:	3c018006 */ 	lui	$at,0x8006
/*     d374:	ac2bd650 */ 	sw	$t3,-0x29b0($at)
.PF0000d378:
/*     d378:	0c00533a */ 	jal	joyGetButtons
/*     d37c:	24051000 */ 	li	$a1,0x1000
/*     d380:	1440000f */ 	bnez	$v0,.PF0000d3c0
/*     d384:	24040001 */ 	li	$a0,0x1
/*     d388:	0c00533a */ 	jal	joyGetButtons
/*     d38c:	24051000 */ 	li	$a1,0x1000
/*     d390:	1440000b */ 	bnez	$v0,.PF0000d3c0
/*     d394:	24040002 */ 	li	$a0,0x2
/*     d398:	0c00533a */ 	jal	joyGetButtons
/*     d39c:	24051000 */ 	li	$a1,0x1000
/*     d3a0:	14400007 */ 	bnez	$v0,.PF0000d3c0
/*     d3a4:	24040003 */ 	li	$a0,0x3
/*     d3a8:	0c00533a */ 	jal	joyGetButtons
/*     d3ac:	24051000 */ 	li	$a1,0x1000
/*     d3b0:	14400003 */ 	bnez	$v0,.PF0000d3c0
/*     d3b4:	3c018006 */ 	lui	$at,0x8006
/*     d3b8:	10000004 */ 	b	.PF0000d3cc
/*     d3bc:	ac20d674 */ 	sw	$zero,-0x298c($at)
.PF0000d3c0:
/*     d3c0:	240c0001 */ 	li	$t4,0x1
/*     d3c4:	3c018006 */ 	lui	$at,0x8006
/*     d3c8:	ac2cd674 */ 	sw	$t4,-0x298c($at)
.PF0000d3cc:
/*     d3cc:	3c0e8006 */ 	lui	$t6,0x8006
/*     d3d0:	afa01478 */ 	sw	$zero,0x1478($sp)
/*     d3d4:	25ced9bc */ 	addiu	$t6,$t6,-9796
/*     d3d8:	8dc10000 */ 	lw	$at,0x0($t6)
/*     d3dc:	8dd90004 */ 	lw	$t9,0x4($t6)
/*     d3e0:	27ad1458 */ 	addiu	$t5,$sp,0x1458
/*     d3e4:	ada10000 */ 	sw	$at,0x0($t5)
/*     d3e8:	adb90004 */ 	sw	$t9,0x4($t5)
/*     d3ec:	8dd9000c */ 	lw	$t9,0xc($t6)
/*     d3f0:	8dc10008 */ 	lw	$at,0x8($t6)
/*     d3f4:	adb9000c */ 	sw	$t9,0xc($t5)
/*     d3f8:	ada10008 */ 	sw	$at,0x8($t5)
/*     d3fc:	8dc10010 */ 	lw	$at,0x10($t6)
/*     d400:	8dd90014 */ 	lw	$t9,0x14($t6)
/*     d404:	ada10010 */ 	sw	$at,0x10($t5)
/*     d408:	adb90014 */ 	sw	$t9,0x14($t5)
/*     d40c:	8dd9001c */ 	lw	$t9,0x1c($t6)
/*     d410:	8dc10018 */ 	lw	$at,0x18($t6)
/*     d414:	adb9001c */ 	sw	$t9,0x1c($t5)
/*     d418:	0c0005b0 */ 	jal	initGetMemSize
/*     d41c:	ada10018 */ 	sw	$at,0x18($t5)
/*     d420:	3c010040 */ 	lui	$at,0x40
/*     d424:	34210001 */ 	ori	$at,$at,0x1
/*     d428:	0041082a */ 	slt	$at,$v0,$at
/*     d42c:	1020000e */ 	beqz	$at,.PF0000d468
/*     d430:	3c0d8006 */ 	lui	$t5,0x8006
/*     d434:	3c0b8006 */ 	lui	$t3,0x8006
/*     d438:	8d6bcc24 */ 	lw	$t3,-0x33dc($t3)
/*     d43c:	3c18803f */ 	lui	$t8,0x803f
/*     d440:	371850b8 */ 	ori	$t8,$t8,0x50b8
/*     d444:	3c01ffef */ 	lui	$at,0xffef
/*     d448:	000b60c0 */ 	sll	$t4,$t3,0x3
/*     d44c:	030c1023 */ 	subu	$v0,$t8,$t4
/*     d450:	34214000 */ 	ori	$at,$at,0x4000
/*     d454:	00411021 */ 	addu	$v0,$v0,$at
/*     d458:	304f1fff */ 	andi	$t7,$v0,0x1fff
/*     d45c:	004f1023 */ 	subu	$v0,$v0,$t7
/*     d460:	10000002 */ 	b	.PF0000d46c
/*     d464:	2442e380 */ 	addiu	$v0,$v0,-7296
.PF0000d468:
/*     d468:	3c028080 */ 	lui	$v0,0x8080
.PF0000d46c:
/*     d46c:	8dadd674 */ 	lw	$t5,-0x298c($t5)
/*     d470:	3c01fff6 */ 	lui	$at,0xfff6
/*     d474:	3421a000 */ 	ori	$at,$at,0xa000
/*     d478:	00411021 */ 	addu	$v0,$v0,$at
/*     d47c:	11a0000f */ 	beqz	$t5,.PF0000d4bc
/*     d480:	2442ffc0 */ 	addiu	$v0,$v0,-64
/*     d484:	3c018000 */ 	lui	$at,0x8000
/*     d488:	00418025 */ 	or	$s0,$v0,$at
/*     d48c:	2610003f */ 	addiu	$s0,$s0,0x3f
/*     d490:	3c0301ff */ 	lui	$v1,0x1ff
/*     d494:	360e003f */ 	ori	$t6,$s0,0x3f
/*     d498:	3c0b01ff */ 	lui	$t3,0x1ff
/*     d49c:	24656030 */ 	addiu	$a1,$v1,0x6030
/*     d4a0:	256b68e0 */ 	addiu	$t3,$t3,0x68e0
/*     d4a4:	39c4003f */ 	xori	$a0,$t6,0x3f
/*     d4a8:	00808025 */ 	move	$s0,$a0
/*     d4ac:	0c003454 */ 	jal	dmaExec
/*     d4b0:	01653023 */ 	subu	$a2,$t3,$a1
/*     d4b4:	1000000e */ 	b	.PF0000d4f0
/*     d4b8:	3c01ffff */ 	lui	$at,0xffff
.PF0000d4bc:
/*     d4bc:	3c018000 */ 	lui	$at,0x8000
/*     d4c0:	00418025 */ 	or	$s0,$v0,$at
/*     d4c4:	2610003f */ 	addiu	$s0,$s0,0x3f
/*     d4c8:	3c0301ff */ 	lui	$v1,0x1ff
/*     d4cc:	3618003f */ 	ori	$t8,$s0,0x3f
/*     d4d0:	3c0f01ff */ 	lui	$t7,0x1ff
/*     d4d4:	24655500 */ 	addiu	$a1,$v1,0x5500
/*     d4d8:	25ef6030 */ 	addiu	$t7,$t7,0x6030
/*     d4dc:	3b04003f */ 	xori	$a0,$t8,0x3f
/*     d4e0:	00808025 */ 	move	$s0,$a0
/*     d4e4:	0c003454 */ 	jal	dmaExec
/*     d4e8:	01e53023 */ 	subu	$a2,$t7,$a1
/*     d4ec:	3c01ffff */ 	lui	$at,0xffff
.PF0000d4f0:
/*     d4f0:	342141e0 */ 	ori	$at,$at,0x41e0
/*     d4f4:	02012821 */ 	addu	$a1,$s0,$at
/*     d4f8:	afa50048 */ 	sw	$a1,0x48($sp)
/*     d4fc:	02002025 */ 	move	$a0,$s0
/*     d500:	0c001d0c */ 	jal	rzipInflate
/*     d504:	27a60058 */ 	addiu	$a2,$sp,0x58
/*     d508:	3c050004 */ 	lui	$a1,0x4
/*     d50c:	8faa0048 */ 	lw	$t2,0x48($sp)
/*     d510:	34a53800 */ 	ori	$a1,$a1,0x3800
/*     d514:	00003825 */ 	move	$a3,$zero
/*     d518:	24040500 */ 	li	$a0,0x500
/*     d51c:	00076840 */ 	sll	$t5,$a3,0x1
.PF0000d520:
/*     d520:	020d1821 */ 	addu	$v1,$s0,$t5
/*     d524:	00001025 */ 	move	$v0,$zero
.PF0000d528:
/*     d528:	00627021 */ 	addu	$t6,$v1,$v0
/*     d52c:	24420002 */ 	addiu	$v0,$v0,0x2
/*     d530:	1444fffd */ 	bne	$v0,$a0,.PF0000d528
/*     d534:	a5c00000 */ 	sh	$zero,0x0($t6)
/*     d538:	24e70240 */ 	addiu	$a3,$a3,0x240
/*     d53c:	00e5082a */ 	slt	$at,$a3,$a1
/*     d540:	5420fff7 */ 	bnezl	$at,.PF0000d520
/*     d544:	00076840 */ 	sll	$t5,$a3,0x1
/*     d548:	3c198000 */ 	lui	$t9,0x8000
/*     d54c:	8f390300 */ 	lw	$t9,0x300($t9)
/*     d550:	00003825 */ 	move	$a3,$zero
/*     d554:	00003025 */ 	move	$a2,$zero
/*     d558:	17200010 */ 	bnez	$t9,.PF0000d59c
/*     d55c:	24095f10 */ 	li	$t1,0x5f10
/*     d560:	240503f6 */ 	li	$a1,0x3f6
.PF0000d564:
/*     d564:	00075840 */ 	sll	$t3,$a3,0x1
/*     d568:	0006c040 */ 	sll	$t8,$a2,0x1
/*     d56c:	01582021 */ 	addu	$a0,$t2,$t8
/*     d570:	020b1821 */ 	addu	$v1,$s0,$t3
/*     d574:	00001025 */ 	move	$v0,$zero
.PF0000d578:
/*     d578:	00826021 */ 	addu	$t4,$a0,$v0
/*     d57c:	958f0000 */ 	lhu	$t7,0x0($t4)
/*     d580:	00626821 */ 	addu	$t5,$v1,$v0
/*     d584:	24420002 */ 	addiu	$v0,$v0,0x2
/*     d588:	1445fffb */ 	bne	$v0,$a1,.PF0000d578
/*     d58c:	a5af008a */ 	sh	$t7,0x8a($t5)
/*     d590:	24c601fb */ 	addiu	$a2,$a2,0x1fb
/*     d594:	14c9fff3 */ 	bne	$a2,$t1,.PF0000d564
/*     d598:	24e70240 */ 	addiu	$a3,$a3,0x240
.PF0000d59c:
/*     d59c:	0c0029fd */ 	jal	func0000aab0
/*     d5a0:	24040002 */ 	li	$a0,0x2
/*     d5a4:	0c002696 */ 	jal	func00009b50
/*     d5a8:	02002025 */ 	move	$a0,$s0
/*     d5ac:	8faa0048 */ 	lw	$t2,0x48($sp)
/*     d5b0:	3c018006 */ 	lui	$at,0x8006
/*     d5b4:	3c048009 */ 	lui	$a0,0x8009
/*     d5b8:	ac2aecf4 */ 	sw	$t2,-0x130c($at)
/*     d5bc:	3c018006 */ 	lui	$at,0x8006
/*     d5c0:	254e0800 */ 	addiu	$t6,$t2,0x800
/*     d5c4:	ac2eecf0 */ 	sw	$t6,-0x1310($at)
/*     d5c8:	2484e080 */ 	addiu	$a0,$a0,-8064
/*     d5cc:	27a51478 */ 	addiu	$a1,$sp,0x1478
/*     d5d0:	0c011ffc */ 	jal	osRecvMesg
/*     d5d4:	00003025 */ 	move	$a2,$zero
/*     d5d8:	14400007 */ 	bnez	$v0,.PF0000d5f8
.PF0000d5dc:
/*     d5dc:	3c048009 */ 	lui	$a0,0x8009
/*     d5e0:	2484e080 */ 	addiu	$a0,$a0,-8064
/*     d5e4:	27a51478 */ 	addiu	$a1,$sp,0x1478
/*     d5e8:	0c011ffc */ 	jal	osRecvMesg
/*     d5ec:	00003025 */ 	move	$a2,$zero
/*     d5f0:	1040fffa */ 	beqz	$v0,.PF0000d5dc
/*     d5f4:	00000000 */ 	nop
.PF0000d5f8:
/*     d5f8:	00001825 */ 	move	$v1,$zero
.PF0000d5fc:
/*     d5fc:	3c048009 */ 	lui	$a0,0x8009
/*     d600:	2484e080 */ 	addiu	$a0,$a0,-8064
/*     d604:	27a51478 */ 	addiu	$a1,$sp,0x1478
/*     d608:	24060001 */ 	li	$a2,0x1
/*     d60c:	0c011ffc */ 	jal	osRecvMesg
/*     d610:	afa31490 */ 	sw	$v1,0x1490($sp)
/*     d614:	8fb91478 */ 	lw	$t9,0x1478($sp)
/*     d618:	24010001 */ 	li	$at,0x1
/*     d61c:	8fa31490 */ 	lw	$v1,0x1490($sp)
/*     d620:	872b0000 */ 	lh	$t3,0x0($t9)
/*     d624:	27b01458 */ 	addiu	$s0,$sp,0x1458
/*     d628:	5561000d */ 	bnel	$t3,$at,.PF0000d660
/*     d62c:	28610006 */ 	slti	$at,$v1,0x6
/*     d630:	0c0027d9 */ 	jal	func0000a044
/*     d634:	afa31490 */ 	sw	$v1,0x1490($sp)
/*     d638:	3c048006 */ 	lui	$a0,0x8006
/*     d63c:	3c058006 */ 	lui	$a1,0x8006
/*     d640:	24a5d990 */ 	addiu	$a1,$a1,-9840
/*     d644:	2484d968 */ 	addiu	$a0,$a0,-9880
/*     d648:	00003025 */ 	move	$a2,$zero
/*     d64c:	0c00bc7d */ 	jal	rdpCreateTask
/*     d650:	02003825 */ 	move	$a3,$s0
/*     d654:	8fa31490 */ 	lw	$v1,0x1490($sp)
/*     d658:	24630001 */ 	addiu	$v1,$v1,0x1
/*     d65c:	28610006 */ 	slti	$at,$v1,0x6
.PF0000d660:
/*     d660:	1420ffe6 */ 	bnez	$at,.PF0000d5fc
/*     d664:	00000000 */ 	nop
/*     d668:	3c188000 */ 	lui	$t8,0x8000
/*     d66c:	8f180300 */ 	lw	$t8,0x300($t8)
/*     d670:	13000003 */ 	beqz	$t8,.PF0000d680
/*     d674:	00000000 */ 	nop
.PF0000d678:
/*     d678:	1000ffff */ 	b	.PF0000d678
/*     d67c:	00000000 */ 	nop
.PF0000d680:
/*     d680:	0c001c04 */ 	jal	func000070d0
/*     d684:	00000000 */ 	nop
/*     d688:	0fc6a2ac */ 	jal	func0f1a78b0
/*     d68c:	00000000 */ 	nop
/*     d690:	0fc59fbd */ 	jal	func0f166f74
/*     d694:	00000000 */ 	nop
/*     d698:	0fc5dbe0 */ 	jal	stub0f175f50
/*     d69c:	00000000 */ 	nop
/*     d6a0:	0fc5dbf0 */ 	jal	func0f175f90
/*     d6a4:	00000000 */ 	nop
/*     d6a8:	3c0c8006 */ 	lui	$t4,0x8006
/*     d6ac:	8d8cd650 */ 	lw	$t4,-0x29b0($t4)
/*     d6b0:	11800003 */ 	beqz	$t4,.PF0000d6c0
/*     d6b4:	3c047005 */ 	lui	$a0,0x7005
/*     d6b8:	0c004b23 */ 	jal	argSetString
/*     d6bc:	24843740 */ 	addiu	$a0,$a0,0x3740
.PF0000d6c0:
/*     d6c0:	3c04800b */ 	lui	$a0,0x800b
/*     d6c4:	0c012ab0 */ 	jal	osVirtualToPhysical
/*     d6c8:	2484d760 */ 	addiu	$a0,$a0,-10400
/*     d6cc:	3c038009 */ 	lui	$v1,0x8009
/*     d6d0:	8c631050 */ 	lw	$v1,0x1050($v1)
/*     d6d4:	3c018000 */ 	lui	$at,0x8000
/*     d6d8:	00412025 */ 	or	$a0,$v0,$at
/*     d6dc:	0c0047de */ 	jal	memInit
/*     d6e0:	00642823 */ 	subu	$a1,$v1,$a0
/*     d6e4:	0c0048ae */ 	jal	memResetPool
/*     d6e8:	24040008 */ 	li	$a0,0x8
/*     d6ec:	0c0048ae */ 	jal	memResetPool
/*     d6f0:	24040006 */ 	li	$a0,0x6
/*     d6f4:	0c00330e */ 	jal	crashReset
/*     d6f8:	00000000 */ 	nop
/*     d6fc:	0fc02c88 */ 	jal	mpInitPresetFeatures
/*     d700:	00000000 */ 	nop
/*     d704:	0fc5df83 */ 	jal	func0f176ddc
/*     d708:	00000000 */ 	nop
/*     d70c:	0c000d28 */ 	jal	func000034d0
/*     d710:	00000000 */ 	nop
/*     d714:	0fc02c68 */ 	jal	loadTextureList
/*     d718:	00000000 */ 	nop
/*     d71c:	0fc00000 */ 	jal	func0f000000
/*     d720:	00000000 */ 	nop
/*     d724:	0fc5a29e */ 	jal	lv0f167af8
/*     d728:	00000000 */ 	nop
/*     d72c:	0fc41f77 */ 	jal	cheatsDisableAll
/*     d730:	00000000 */ 	nop
/*     d734:	0c0039c8 */ 	jal	func0000e9c0
/*     d738:	00000000 */ 	nop
/*     d73c:	0fc54f94 */ 	jal	func0f1531a0
/*     d740:	00000000 */ 	nop
/*     d744:	0c004d48 */ 	jal	func00013790
/*     d748:	00000000 */ 	nop
/*     d74c:	0fc4a0f8 */ 	jal	func0f127910
/*     d750:	00000000 */ 	nop
/*     d754:	0fc5b718 */ 	jal	frametimeInit
/*     d758:	00000000 */ 	nop
/*     d75c:	0fc02c84 */ 	jal	stub0f00b200
/*     d760:	00000000 */ 	nop
/*     d764:	0c00265c */ 	jal	func00009a80
/*     d768:	00000000 */ 	nop
/*     d76c:	0fc0021c */ 	jal	stub0f000870
/*     d770:	00000000 */ 	nop
/*     d774:	0fc00220 */ 	jal	func0f000880
/*     d778:	00000000 */ 	nop
/*     d77c:	0fc00238 */ 	jal	stub0f0008e0
/*     d780:	00000000 */ 	nop
/*     d784:	0fc0023c */ 	jal	stub0f0008f0
/*     d788:	00000000 */ 	nop
/*     d78c:	0fc00240 */ 	jal	stub0f000900
/*     d790:	00000000 */ 	nop
/*     d794:	0fc02c64 */ 	jal	stub0f00b180
/*     d798:	00000000 */ 	nop
/*     d79c:	0fc00244 */ 	jal	stub0f000910
/*     d7a0:	00000000 */ 	nop
/*     d7a4:	0fc00210 */ 	jal	stub0f000840
/*     d7a8:	00000000 */ 	nop
/*     d7ac:	0fc62468 */ 	jal	mpSetDefaultSetup
/*     d7b0:	00000000 */ 	nop
/*     d7b4:	0fc52bf6 */ 	jal	func0f14a328
/*     d7b8:	00000000 */ 	nop
/*     d7bc:	0fc4652e */ 	jal	pak0f1189d8
/*     d7c0:	00000000 */ 	nop
/*     d7c4:	0fc52c1b */ 	jal	func0f14a3bc
/*     d7c8:	00000000 */ 	nop
/*     d7cc:	0c008b30 */ 	jal	func000233c0
/*     d7d0:	00000000 */ 	nop
/*     d7d4:	0fc00040 */ 	jal	func0f000100
/*     d7d8:	00000000 */ 	nop
/*     d7dc:	0fc0004c */ 	jal	func0f000130
/*     d7e0:	00000000 */ 	nop
/*     d7e4:	0fc00214 */ 	jal	stub0f000850
/*     d7e8:	00000000 */ 	nop
/*     d7ec:	0fc00218 */ 	jal	stub0f000860
/*     d7f0:	00000000 */ 	nop
/*     d7f4:	0fc00024 */ 	jal	func0f000090
/*     d7f8:	00000000 */ 	nop
/*     d7fc:	0c0026c0 */ 	jal	func00009bf8
/*     d800:	00000000 */ 	nop
/*     d804:	0c002779 */ 	jal	func00009ec4
/*     d808:	24040001 */ 	li	$a0,0x1
/*     d80c:	3c0f8006 */ 	lui	$t7,0x8006
/*     d810:	8defd674 */ 	lw	$t7,-0x298c($t7)
/*     d814:	3c018006 */ 	lui	$at,0x8006
/*     d818:	ac20d9b8 */ 	sw	$zero,-0x2648($at)
/*     d81c:	51e00004 */ 	beqzl	$t7,.PF0000d830
/*     d820:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*     d824:	0c011f84 */ 	jal	osGetCount
/*     d828:	00000000 */ 	nop
/*     d82c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.PF0000d830:
/*     d830:	8fb00028 */ 	lw	$s0,0x28($sp)
/*     d834:	27bd14e0 */ 	addiu	$sp,$sp,0x14e0
/*     d838:	03e00008 */ 	jr	$ra
/*     d83c:	00000000 */ 	nop
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel mainInit
/*     d520:	27bdeb28 */ 	addiu	$sp,$sp,-5336
/*     d524:	afbf002c */ 	sw	$ra,0x2c($sp)
/*     d528:	0c002fec */ 	jal	faultCreateThread
/*     d52c:	afb00028 */ 	sw	$s0,0x28($sp)
/*     d530:	0c003428 */ 	jal	dmaInit
/*     d534:	00000000 */ 	nop
/*     d538:	0c002288 */ 	jal	amgrAllocateStack
/*     d53c:	00000000 */ 	nop
/*     d540:	0c005618 */ 	jal	gvarsInit
/*     d544:	00000000 */ 	nop
/*     d548:	0c004878 */ 	jal	func000121e0
/*     d54c:	00000000 */ 	nop
/*     d550:	0c004a83 */ 	jal	func00012a0c
/*     d554:	00000000 */ 	nop
/*     d558:	0c004dd6 */ 	jal	func00013758
/*     d55c:	00000000 */ 	nop
/*     d560:	0c0026ac */ 	jal	func00009ab0
/*     d564:	00000000 */ 	nop
/*     d568:	0c00be82 */ 	jal	rmonIsDisabled
/*     d56c:	00000000 */ 	nop
/*     d570:	3c018006 */ 	lui	$at,%hi(var8005d9b0)
/*     d574:	0c004f25 */ 	jal	joySystemInit
/*     d578:	ac22d9b0 */ 	sw	$v0,%lo(var8005d9b0)($at)
/*     d57c:	27a41490 */ 	addiu	$a0,$sp,0x1490
/*     d580:	27a514cc */ 	addiu	$a1,$sp,0x14cc
/*     d584:	0c0120d0 */ 	jal	osCreateMesgQueue
/*     d588:	24060001 */ 	addiu	$a2,$zero,0x1
/*     d58c:	00008025 */ 	or	$s0,$zero,$zero
/*     d590:	3c070047 */ 	lui	$a3,0x47
.L0000d594:
/*     d594:	240e0000 */ 	addiu	$t6,$zero,0x0
/*     d598:	240f0000 */ 	addiu	$t7,$zero,0x0
/*     d59c:	27b81490 */ 	addiu	$t8,$sp,0x1490
/*     d5a0:	27b914cc */ 	addiu	$t9,$sp,0x14cc
/*     d5a4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*     d5a8:	afb80018 */ 	sw	$t8,0x18($sp)
/*     d5ac:	afaf0014 */ 	sw	$t7,0x14($sp)
/*     d5b0:	afae0010 */ 	sw	$t6,0x10($sp)
/*     d5b4:	34e7868c */ 	ori	$a3,$a3,0x868c
/*     d5b8:	27a414a8 */ 	addiu	$a0,$sp,0x14a8
/*     d5bc:	0c0122c8 */ 	jal	osSetTimer
/*     d5c0:	24060000 */ 	addiu	$a2,$zero,0x0
/*     d5c4:	27a41490 */ 	addiu	$a0,$sp,0x1490
/*     d5c8:	27a514cc */ 	addiu	$a1,$sp,0x14cc
/*     d5cc:	0c0121bc */ 	jal	osRecvMesg
/*     d5d0:	24060001 */ 	addiu	$a2,$zero,0x1
/*     d5d4:	24010001 */ 	addiu	$at,$zero,0x1
/*     d5d8:	56010006 */ 	bnel	$s0,$at,.L0000d5f4
/*     d5dc:	2a010002 */ 	slti	$at,$s0,0x2
/*     d5e0:	0c004f7f */ 	jal	joy00013dfc
/*     d5e4:	00000000 */ 	nop
/*     d5e8:	10000007 */ 	b	.L0000d608
/*     d5ec:	26100001 */ 	addiu	$s0,$s0,0x1
/*     d5f0:	2a010002 */ 	slti	$at,$s0,0x2
.L0000d5f4:
/*     d5f4:	54200004 */ 	bnezl	$at,.L0000d608
/*     d5f8:	26100001 */ 	addiu	$s0,$s0,0x1
/*     d5fc:	0c0050bc */ 	jal	joyDebugJoy
/*     d600:	00000000 */ 	nop
/*     d604:	26100001 */ 	addiu	$s0,$s0,0x1
.L0000d608:
/*     d608:	24010004 */ 	addiu	$at,$zero,0x4
/*     d60c:	5601ffe1 */ 	bnel	$s0,$at,.L0000d594
/*     d610:	3c070047 */ 	lui	$a3,0x47
/*     d614:	3c057005 */ 	lui	$a1,%hi(var70053a98)
/*     d618:	24a53a98 */ 	addiu	$a1,$a1,%lo(var70053a98)
/*     d61c:	0c004c04 */ 	jal	argFindByPrefix
/*     d620:	24040001 */ 	addiu	$a0,$zero,0x1
/*     d624:	14400004 */ 	bnez	$v0,.L0000d638
/*     d628:	00002025 */ 	or	$a0,$zero,$zero
/*     d62c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*     d630:	3c018006 */ 	lui	$at,%hi(var8005d9b0)
/*     d634:	ac2bd9b0 */ 	sw	$t3,%lo(var8005d9b0)($at)
.L0000d638:
/*     d638:	0c0053d8 */ 	jal	joyGetButtons
/*     d63c:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     d640:	14400010 */ 	bnez	$v0,.L0000d684
/*     d644:	24040001 */ 	addiu	$a0,$zero,0x1
/*     d648:	0c0053d8 */ 	jal	joyGetButtons
/*     d64c:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     d650:	1440000c */ 	bnez	$v0,.L0000d684
/*     d654:	24040002 */ 	addiu	$a0,$zero,0x2
/*     d658:	0c0053d8 */ 	jal	joyGetButtons
/*     d65c:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     d660:	14400008 */ 	bnez	$v0,.L0000d684
/*     d664:	24040003 */ 	addiu	$a0,$zero,0x3
/*     d668:	0c0053d8 */ 	jal	joyGetButtons
/*     d66c:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     d670:	14400004 */ 	bnez	$v0,.L0000d684
/*     d674:	3c108006 */ 	lui	$s0,%hi(g_DoBootPakMenu)
/*     d678:	2610d9d4 */ 	addiu	$s0,$s0,%lo(g_DoBootPakMenu)
/*     d67c:	10000005 */ 	b	.L0000d694
/*     d680:	ae000000 */ 	sw	$zero,0x0($s0)
.L0000d684:
/*     d684:	3c108006 */ 	lui	$s0,%hi(g_DoBootPakMenu)
/*     d688:	2610d9d4 */ 	addiu	$s0,$s0,%lo(g_DoBootPakMenu)
/*     d68c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*     d690:	ae0c0000 */ 	sw	$t4,0x0($s0)
.L0000d694:
/*     d694:	3c0e8006 */ 	lui	$t6,%hi(var8005dd1c)
/*     d698:	afa01470 */ 	sw	$zero,0x1470($sp)
/*     d69c:	25cedd1c */ 	addiu	$t6,$t6,%lo(var8005dd1c)
/*     d6a0:	8dc10000 */ 	lw	$at,0x0($t6)
/*     d6a4:	8dd90004 */ 	lw	$t9,0x4($t6)
/*     d6a8:	27ad1450 */ 	addiu	$t5,$sp,0x1450
/*     d6ac:	ada10000 */ 	sw	$at,0x0($t5)
/*     d6b0:	adb90004 */ 	sw	$t9,0x4($t5)
/*     d6b4:	8dd9000c */ 	lw	$t9,0xc($t6)
/*     d6b8:	8dc10008 */ 	lw	$at,0x8($t6)
/*     d6bc:	adb9000c */ 	sw	$t9,0xc($t5)
/*     d6c0:	ada10008 */ 	sw	$at,0x8($t5)
/*     d6c4:	8dc10010 */ 	lw	$at,0x10($t6)
/*     d6c8:	8dd90014 */ 	lw	$t9,0x14($t6)
/*     d6cc:	ada10010 */ 	sw	$at,0x10($t5)
/*     d6d0:	adb90014 */ 	sw	$t9,0x14($t5)
/*     d6d4:	8dd9001c */ 	lw	$t9,0x1c($t6)
/*     d6d8:	8dc10018 */ 	lw	$at,0x18($t6)
/*     d6dc:	adb9001c */ 	sw	$t9,0x1c($t5)
/*     d6e0:	0c0005b0 */ 	jal	initGetMemSize
/*     d6e4:	ada10018 */ 	sw	$at,0x18($t5)
/*     d6e8:	3c010040 */ 	lui	$at,0x40
/*     d6ec:	34210001 */ 	ori	$at,$at,0x1
/*     d6f0:	0041082a */ 	slt	$at,$v0,$at
/*     d6f4:	1020000e */ 	beqz	$at,.L0000d730
/*     d6f8:	3c028080 */ 	lui	$v0,0x8080
/*     d6fc:	3c0b8006 */ 	lui	$t3,%hi(var8005cf84)
/*     d700:	8d6bcf84 */ 	lw	$t3,%lo(var8005cf84)($t3)
/*     d704:	3c18803f */ 	lui	$t8,0x803f
/*     d708:	371850b8 */ 	ori	$t8,$t8,0x50b8
/*     d70c:	3c01ffef */ 	lui	$at,0xffef
/*     d710:	000b60c0 */ 	sll	$t4,$t3,0x3
/*     d714:	030c1023 */ 	subu	$v0,$t8,$t4
/*     d718:	34214000 */ 	ori	$at,$at,0x4000
/*     d71c:	00411021 */ 	addu	$v0,$v0,$at
/*     d720:	304f1fff */ 	andi	$t7,$v0,0x1fff
/*     d724:	004f1023 */ 	subu	$v0,$v0,$t7
/*     d728:	10000001 */ 	b	.L0000d730
/*     d72c:	2442e380 */ 	addiu	$v0,$v0,-7296
.L0000d730:
/*     d730:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*     d734:	3c01fff6 */ 	lui	$at,0xfff6
/*     d738:	3421a000 */ 	ori	$at,$at,0xa000
/*     d73c:	00411021 */ 	addu	$v0,$v0,$at
/*     d740:	11a0000f */ 	beqz	$t5,.L0000d780
/*     d744:	2442ffc0 */ 	addiu	$v0,$v0,-64
/*     d748:	3c018000 */ 	lui	$at,0x8000
/*     d74c:	00418025 */ 	or	$s0,$v0,$at
/*     d750:	2610003f */ 	addiu	$s0,$s0,0x3f
/*     d754:	3c030200 */ 	lui	$v1,%hi(_accessingpakSegmentRomStart)
/*     d758:	360e003f */ 	ori	$t6,$s0,0x3f
/*     d75c:	3c0b0200 */ 	lui	$t3,%hi(_accessingpakSegmentRomEnd)
/*     d760:	2465f550 */ 	addiu	$a1,$v1,%lo(_accessingpakSegmentRomStart)
/*     d764:	256bfe00 */ 	addiu	$t3,$t3,%lo(_accessingpakSegmentRomEnd)
/*     d768:	39c4003f */ 	xori	$a0,$t6,0x3f
/*     d76c:	00808025 */ 	or	$s0,$a0,$zero
/*     d770:	0c003504 */ 	jal	dmaExec
/*     d774:	01653023 */ 	subu	$a2,$t3,$a1
/*     d778:	1000000e */ 	b	.L0000d7b4
/*     d77c:	3c01ffff */ 	lui	$at,0xffff
.L0000d780:
/*     d780:	3c018000 */ 	lui	$at,0x8000
/*     d784:	00418025 */ 	or	$s0,$v0,$at
/*     d788:	2610003f */ 	addiu	$s0,$s0,0x3f
/*     d78c:	3c030200 */ 	lui	$v1,%hi(_copyrightSegmentRomStart)
/*     d790:	3618003f */ 	ori	$t8,$s0,0x3f
/*     d794:	3c0f0200 */ 	lui	$t7,%hi(_copyrightSegmentRomEnd)
/*     d798:	2465ea20 */ 	addiu	$a1,$v1,%lo(_copyrightSegmentRomStart)
/*     d79c:	25eff550 */ 	addiu	$t7,$t7,%lo(_copyrightSegmentRomEnd)
/*     d7a0:	3b04003f */ 	xori	$a0,$t8,0x3f
/*     d7a4:	00808025 */ 	or	$s0,$a0,$zero
/*     d7a8:	0c003504 */ 	jal	dmaExec
/*     d7ac:	01e53023 */ 	subu	$a2,$t7,$a1
/*     d7b0:	3c01ffff */ 	lui	$at,0xffff
.L0000d7b4:
/*     d7b4:	342141e0 */ 	ori	$at,$at,0x41e0
/*     d7b8:	02012821 */ 	addu	$a1,$s0,$at
/*     d7bc:	afa50048 */ 	sw	$a1,0x48($sp)
/*     d7c0:	02002025 */ 	or	$a0,$s0,$zero
/*     d7c4:	0c001d3c */ 	jal	rzipInflate
/*     d7c8:	27a60050 */ 	addiu	$a2,$sp,0x50
/*     d7cc:	3c050004 */ 	lui	$a1,0x4
/*     d7d0:	8faa0048 */ 	lw	$t2,0x48($sp)
/*     d7d4:	34a53800 */ 	ori	$a1,$a1,0x3800
/*     d7d8:	00003825 */ 	or	$a3,$zero,$zero
/*     d7dc:	24040500 */ 	addiu	$a0,$zero,0x500
/*     d7e0:	00076840 */ 	sll	$t5,$a3,0x1
.L0000d7e4:
/*     d7e4:	020d1821 */ 	addu	$v1,$s0,$t5
/*     d7e8:	00001025 */ 	or	$v0,$zero,$zero
.L0000d7ec:
/*     d7ec:	00627021 */ 	addu	$t6,$v1,$v0
/*     d7f0:	24420002 */ 	addiu	$v0,$v0,0x2
/*     d7f4:	1444fffd */ 	bne	$v0,$a0,.L0000d7ec
/*     d7f8:	a5c00000 */ 	sh	$zero,0x0($t6)
/*     d7fc:	24e70240 */ 	addiu	$a3,$a3,0x240
/*     d800:	00e5082a */ 	slt	$at,$a3,$a1
/*     d804:	5420fff7 */ 	bnezl	$at,.L0000d7e4
/*     d808:	00076840 */ 	sll	$t5,$a3,0x1
/*     d80c:	3c198000 */ 	lui	$t9,0x8000
/*     d810:	8f390300 */ 	lw	$t9,0x300($t9)
/*     d814:	00003825 */ 	or	$a3,$zero,$zero
/*     d818:	00003025 */ 	or	$a2,$zero,$zero
/*     d81c:	13200010 */ 	beqz	$t9,.L0000d860
/*     d820:	24095f10 */ 	addiu	$t1,$zero,0x5f10
/*     d824:	240503f6 */ 	addiu	$a1,$zero,0x3f6
.L0000d828:
/*     d828:	00075840 */ 	sll	$t3,$a3,0x1
/*     d82c:	0006c040 */ 	sll	$t8,$a2,0x1
/*     d830:	01582021 */ 	addu	$a0,$t2,$t8
/*     d834:	020b1821 */ 	addu	$v1,$s0,$t3
/*     d838:	00001025 */ 	or	$v0,$zero,$zero
.L0000d83c:
/*     d83c:	00826021 */ 	addu	$t4,$a0,$v0
/*     d840:	958f0000 */ 	lhu	$t7,0x0($t4)
/*     d844:	00626821 */ 	addu	$t5,$v1,$v0
/*     d848:	24420002 */ 	addiu	$v0,$v0,0x2
/*     d84c:	1445fffb */ 	bne	$v0,$a1,.L0000d83c
/*     d850:	a5af008a */ 	sh	$t7,0x8a($t5)
/*     d854:	24c601fb */ 	addiu	$a2,$a2,0x1fb
/*     d858:	14c9fff3 */ 	bne	$a2,$t1,.L0000d828
/*     d85c:	24e70240 */ 	addiu	$a3,$a3,0x240
.L0000d860:
/*     d860:	0c002aac */ 	jal	func0000aab0
/*     d864:	24040002 */ 	addiu	$a0,$zero,0x2
/*     d868:	0c0026d4 */ 	jal	func00009b50
/*     d86c:	02002025 */ 	or	$a0,$s0,$zero
/*     d870:	8faa0048 */ 	lw	$t2,0x48($sp)
/*     d874:	3c018006 */ 	lui	$at,%hi(g_RdpOutBufferStart)
/*     d878:	3c048009 */ 	lui	$a0,%hi(var8008db30)
/*     d87c:	ac2af044 */ 	sw	$t2,%lo(g_RdpOutBufferStart)($at)
/*     d880:	3c018006 */ 	lui	$at,%hi(g_RdpOutBufferEnd)
/*     d884:	254e0800 */ 	addiu	$t6,$t2,0x800
/*     d888:	ac2ef040 */ 	sw	$t6,%lo(g_RdpOutBufferEnd)($at)
/*     d88c:	2484db30 */ 	addiu	$a0,$a0,%lo(var8008db30)
/*     d890:	27a51470 */ 	addiu	$a1,$sp,0x1470
/*     d894:	0c0121bc */ 	jal	osRecvMesg
/*     d898:	00003025 */ 	or	$a2,$zero,$zero
/*     d89c:	14400007 */ 	bnez	$v0,.L0000d8bc
.L0000d8a0:
/*     d8a0:	3c048009 */ 	lui	$a0,%hi(var8008db30)
/*     d8a4:	2484db30 */ 	addiu	$a0,$a0,%lo(var8008db30)
/*     d8a8:	27a51470 */ 	addiu	$a1,$sp,0x1470
/*     d8ac:	0c0121bc */ 	jal	osRecvMesg
/*     d8b0:	00003025 */ 	or	$a2,$zero,$zero
/*     d8b4:	1040fffa */ 	beqz	$v0,.L0000d8a0
/*     d8b8:	00000000 */ 	nop
.L0000d8bc:
/*     d8bc:	00001825 */ 	or	$v1,$zero,$zero
.L0000d8c0:
/*     d8c0:	3c048009 */ 	lui	$a0,%hi(var8008db30)
/*     d8c4:	2484db30 */ 	addiu	$a0,$a0,%lo(var8008db30)
/*     d8c8:	27a51470 */ 	addiu	$a1,$sp,0x1470
/*     d8cc:	24060001 */ 	addiu	$a2,$zero,0x1
/*     d8d0:	0c0121bc */ 	jal	osRecvMesg
/*     d8d4:	afa31488 */ 	sw	$v1,0x1488($sp)
/*     d8d8:	8fb91470 */ 	lw	$t9,0x1470($sp)
/*     d8dc:	24010001 */ 	addiu	$at,$zero,0x1
/*     d8e0:	8fa31488 */ 	lw	$v1,0x1488($sp)
/*     d8e4:	872b0000 */ 	lh	$t3,0x0($t9)
/*     d8e8:	27b01450 */ 	addiu	$s0,$sp,0x1450
/*     d8ec:	5561000d */ 	bnel	$t3,$at,.L0000d924
/*     d8f0:	28610006 */ 	slti	$at,$v1,0x6
/*     d8f4:	0c002811 */ 	jal	func0000a044
/*     d8f8:	afa31488 */ 	sw	$v1,0x1488($sp)
/*     d8fc:	3c048006 */ 	lui	$a0,%hi(var8005dcc8)
/*     d900:	3c058006 */ 	lui	$a1,%hi(var8005dcf0)
/*     d904:	24a5dcf0 */ 	addiu	$a1,$a1,%lo(var8005dcf0)
/*     d908:	2484dcc8 */ 	addiu	$a0,$a0,%lo(var8005dcc8)
/*     d90c:	00003025 */ 	or	$a2,$zero,$zero
/*     d910:	0c00be3d */ 	jal	rdpCreateTask
/*     d914:	02003825 */ 	or	$a3,$s0,$zero
/*     d918:	8fa31488 */ 	lw	$v1,0x1488($sp)
/*     d91c:	24630001 */ 	addiu	$v1,$v1,0x1
/*     d920:	28610006 */ 	slti	$at,$v1,0x6
.L0000d924:
/*     d924:	1420ffe6 */ 	bnez	$at,.L0000d8c0
/*     d928:	00000000 */ 	nop
/*     d92c:	3c188000 */ 	lui	$t8,0x8000
/*     d930:	8f180300 */ 	lw	$t8,0x300($t8)
/*     d934:	17000003 */ 	bnez	$t8,.L0000d944
/*     d938:	00000000 */ 	nop
.L0000d93c:
/*     d93c:	1000ffff */ 	b	.L0000d93c
/*     d940:	00000000 */ 	nop
.L0000d944:
/*     d944:	0c001c34 */ 	jal	func000070d0
/*     d948:	00000000 */ 	nop
/*     d94c:	0fc69e2c */ 	jal	func0f1a78b0
/*     d950:	00000000 */ 	nop
/*     d954:	0fc59bdd */ 	jal	func0f166f74
/*     d958:	00000000 */ 	nop
/*     d95c:	0fc5d7d4 */ 	jal	stub0f175f50
/*     d960:	00000000 */ 	nop
/*     d964:	0fc5d7e4 */ 	jal	func0f175f90
/*     d968:	00000000 */ 	nop
/*     d96c:	3c0c8006 */ 	lui	$t4,%hi(var8005d9b0)
/*     d970:	8d8cd9b0 */ 	lw	$t4,%lo(var8005d9b0)($t4)
/*     d974:	11800003 */ 	beqz	$t4,.L0000d984
/*     d978:	3c047005 */ 	lui	$a0,%hi(var70053aa0)
/*     d97c:	0c004bbf */ 	jal	argSetString
/*     d980:	24843aa0 */ 	addiu	$a0,$a0,%lo(var70053aa0)
.L0000d984:
/*     d984:	3c04800b */ 	lui	$a0,%hi(_bssSegmentEnd)
/*     d988:	0c012d20 */ 	jal	osVirtualToPhysical
/*     d98c:	2484d1c0 */ 	addiu	$a0,$a0,%lo(_bssSegmentEnd)
/*     d990:	3c038009 */ 	lui	$v1,%hi(var80090b00)
/*     d994:	8c630b00 */ 	lw	$v1,%lo(var80090b00)($v1)
/*     d998:	3c018000 */ 	lui	$at,0x8000
/*     d99c:	00412025 */ 	or	$a0,$v0,$at
/*     d9a0:	0c00487a */ 	jal	memInit
/*     d9a4:	00642823 */ 	subu	$a1,$v1,$a0
/*     d9a8:	0c00494a */ 	jal	memResetPool
/*     d9ac:	24040008 */ 	addiu	$a0,$zero,0x8
/*     d9b0:	0c00494a */ 	jal	memResetPool
/*     d9b4:	24040006 */ 	addiu	$a0,$zero,0x6
/*     d9b8:	0c0033be */ 	jal	crashReset
/*     d9bc:	00000000 */ 	nop
/*     d9c0:	0fc02c84 */ 	jal	mpInitPresetFeatures
/*     d9c4:	00000000 */ 	nop
/*     d9c8:	0fc5db77 */ 	jal	func0f176ddc
/*     d9cc:	00000000 */ 	nop
/*     d9d0:	0c000d34 */ 	jal	func000034d0
/*     d9d4:	00000000 */ 	nop
/*     d9d8:	0fc02c64 */ 	jal	loadTextureList
/*     d9dc:	00000000 */ 	nop
/*     d9e0:	0fc00000 */ 	jal	func0f000000
/*     d9e4:	00000000 */ 	nop
/*     d9e8:	0fc59ebe */ 	jal	lv0f167af8
/*     d9ec:	00000000 */ 	nop
/*     d9f0:	0fc41d3b */ 	jal	cheatsDisableAll
/*     d9f4:	00000000 */ 	nop
/*     d9f8:	0c003a70 */ 	jal	func0000e9c0
/*     d9fc:	00000000 */ 	nop
/*     da00:	0fc54c68 */ 	jal	func0f1531a0
/*     da04:	00000000 */ 	nop
/*     da08:	0c004de4 */ 	jal	func00013790
/*     da0c:	00000000 */ 	nop
/*     da10:	0fc49e44 */ 	jal	func0f127910
/*     da14:	00000000 */ 	nop
/*     da18:	0fc5b384 */ 	jal	frametimeInit
/*     da1c:	00000000 */ 	nop
/*     da20:	0fc02c80 */ 	jal	stub0f00b200
/*     da24:	00000000 */ 	nop
/*     da28:	0c0026a0 */ 	jal	func00009a80
/*     da2c:	00000000 */ 	nop
/*     da30:	0fc0021c */ 	jal	stub0f000870
/*     da34:	00000000 */ 	nop
/*     da38:	0fc00220 */ 	jal	func0f000880
/*     da3c:	00000000 */ 	nop
/*     da40:	0fc00238 */ 	jal	stub0f0008e0
/*     da44:	00000000 */ 	nop
/*     da48:	0fc0023c */ 	jal	stub0f0008f0
/*     da4c:	00000000 */ 	nop
/*     da50:	0fc00240 */ 	jal	stub0f000900
/*     da54:	00000000 */ 	nop
/*     da58:	0fc02c60 */ 	jal	stub0f00b180
/*     da5c:	00000000 */ 	nop
/*     da60:	0fc00244 */ 	jal	stub0f000910
/*     da64:	00000000 */ 	nop
/*     da68:	0fc00210 */ 	jal	stub0f000840
/*     da6c:	00000000 */ 	nop
/*     da70:	0fc62084 */ 	jal	mpSetDefaultSetup
/*     da74:	00000000 */ 	nop
/*     da78:	0fc528ca */ 	jal	func0f14a328
/*     da7c:	00000000 */ 	nop
/*     da80:	0fc46276 */ 	jal	pak0f1189d8
/*     da84:	00000000 */ 	nop
/*     da88:	0fc528ef */ 	jal	func0f14a3bc
/*     da8c:	00000000 */ 	nop
/*     da90:	0c008cf0 */ 	jal	func000233c0
/*     da94:	00000000 */ 	nop
/*     da98:	0fc00040 */ 	jal	func0f000100
/*     da9c:	00000000 */ 	nop
/*     daa0:	0fc0004c */ 	jal	func0f000130
/*     daa4:	00000000 */ 	nop
/*     daa8:	0fc00214 */ 	jal	stub0f000850
/*     daac:	00000000 */ 	nop
/*     dab0:	0fc00218 */ 	jal	stub0f000860
/*     dab4:	00000000 */ 	nop
/*     dab8:	0fc00024 */ 	jal	func0f000090
/*     dabc:	00000000 */ 	nop
/*     dac0:	0c0026fe */ 	jal	func00009bf8
/*     dac4:	00000000 */ 	nop
/*     dac8:	0c0027b1 */ 	jal	func00009ec4
/*     dacc:	24040001 */ 	addiu	$a0,$zero,0x1
/*     dad0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*     dad4:	3c018006 */ 	lui	$at,%hi(var8005dd18)
/*     dad8:	8fb00028 */ 	lw	$s0,0x28($sp)
/*     dadc:	ac20dd18 */ 	sw	$zero,%lo(var8005dd18)($at)
/*     dae0:	03e00008 */ 	jr	$ra
/*     dae4:	27bd14d8 */ 	addiu	$sp,$sp,0x14d8
);
#else
GLOBAL_ASM(
glabel mainInit
/*     da80:	27bdeb20 */ 	addiu	$sp,$sp,-5344
/*     da84:	afbf0034 */ 	sw	$ra,0x34($sp)
/*     da88:	afb20030 */ 	sw	$s2,0x30($sp)
/*     da8c:	afb1002c */ 	sw	$s1,0x2c($sp)
/*     da90:	0c003060 */ 	jal	faultCreateThread
/*     da94:	afb00028 */ 	sw	$s0,0x28($sp)
/*     da98:	0c0035b4 */ 	jal	dmaInit
/*     da9c:	00000000 */ 	sll	$zero,$zero,0x0
/*     daa0:	0c0022f0 */ 	jal	amgrAllocateStack
/*     daa4:	00000000 */ 	sll	$zero,$zero,0x0
/*     daa8:	0c0059d4 */ 	jal	gvarsInit
/*     daac:	00000000 */ 	sll	$zero,$zero,0x0
/*     dab0:	0c004994 */ 	jal	func000121e0
/*     dab4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dab8:	0c004beb */ 	jal	func00012a0c
/*     dabc:	00000000 */ 	sll	$zero,$zero,0x0
/*     dac0:	0c004fea */ 	jal	func00013758
/*     dac4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dac8:	0c002714 */ 	jal	func00009ab0
/*     dacc:	00000000 */ 	sll	$zero,$zero,0x0
/*     dad0:	0c00c456 */ 	jal	rmonIsDisabled
/*     dad4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dad8:	3c018006 */ 	lui	$at,0x8006
/*     dadc:	0c0052b6 */ 	jal	joySystemInit
/*     dae0:	ac22f2d0 */ 	sw	$v0,-0xd30($at)
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
/*     db48:	0c005310 */ 	jal	joy00013dfc
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
/*     db7c:	3c057005 */ 	lui	$a1,0x7005
/*     db80:	24a550e8 */ 	addiu	$a1,$a1,0x50e8
/*     db84:	0c004e18 */ 	jal	argFindByPrefix
/*     db88:	24040001 */ 	addiu	$a0,$zero,0x1
/*     db8c:	14400004 */ 	bnez	$v0,.NB0000dba0
/*     db90:	3c198000 */ 	lui	$t9,0x8000
/*     db94:	24180001 */ 	addiu	$t8,$zero,0x1
/*     db98:	3c018006 */ 	lui	$at,0x8006
/*     db9c:	ac38f2d0 */ 	sw	$t8,-0xd30($at)
.NB0000dba0:
/*     dba0:	8f390300 */ 	lw	$t9,0x300($t9)
/*     dba4:	24010001 */ 	addiu	$at,$zero,0x1
/*     dba8:	00002025 */ 	or	$a0,$zero,$zero
/*     dbac:	13210005 */ 	beq	$t9,$at,.NB0000dbc4
/*     dbb0:	24090001 */ 	addiu	$t1,$zero,0x1
/*     dbb4:	3c018006 */ 	lui	$at,0x8006
/*     dbb8:	ac29f2d0 */ 	sw	$t1,-0xd30($at)
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
/*     dc00:	3c0b8006 */ 	lui	$t3,0x8006
/*     dc04:	afa01478 */ 	sw	$zero,0x1478($sp)
/*     dc08:	256bf63c */ 	addiu	$t3,$t3,-2500
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
/*     dc4c:	3c018006 */ 	lui	$at,0x8006
/*     dc50:	ad4e001c */ 	sw	$t6,0x1c($t2)
/*     dc54:	0c013d4c */ 	jal	osGetMemSize
/*     dc58:	ac20f2f4 */ 	sw	$zero,-0xd0c($at)
/*     dc5c:	3c010040 */ 	lui	$at,0x40
/*     dc60:	34210001 */ 	ori	$at,$at,0x1
/*     dc64:	0041082b */ 	sltu	$at,$v0,$at
/*     dc68:	1020000e */ 	beqz	$at,.NB0000dca4
/*     dc6c:	3c0301fb */ 	lui	$v1,0x1fb
/*     dc70:	3c0f8006 */ 	lui	$t7,0x8006
/*     dc74:	8defe720 */ 	lw	$t7,-0x18e0($t7)
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
/*     dcc8:	3c0a01fb */ 	lui	$t2,0x1fb
/*     dccc:	2465bac0 */ 	addiu	$a1,$v1,-17728
/*     dcd0:	254ac5f0 */ 	addiu	$t2,$t2,-14864
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
/*     dd84:	0c002b0c */ 	jal	func0000aab0
/*     dd88:	24040002 */ 	addiu	$a0,$zero,0x2
/*     dd8c:	0c00273c */ 	jal	func00009b50
/*     dd90:	02202025 */ 	or	$a0,$s1,$zero
/*     dd94:	3c018006 */ 	lui	$at,0x8006
/*     dd98:	3c118009 */ 	lui	$s1,0x8009
/*     dd9c:	ac321554 */ 	sw	$s2,0x1554($at)
/*     dda0:	26310160 */ 	addiu	$s1,$s1,0x160
/*     dda4:	3c018006 */ 	lui	$at,0x8006
/*     dda8:	264c0800 */ 	addiu	$t4,$s2,0x800
/*     ddac:	ac2c1550 */ 	sw	$t4,0x1550($at)
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
/*     dddc:	3c128006 */ 	lui	$s2,0x8006
/*     dde0:	00008025 */ 	or	$s0,$zero,$zero
/*     dde4:	2652f5e8 */ 	addiu	$s2,$s2,-2584
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
/*     de10:	0c002871 */ 	jal	func0000a044
/*     de14:	afae0054 */ 	sw	$t6,0x54($sp)
/*     de18:	3c058006 */ 	lui	$a1,0x8006
/*     de1c:	24a5f610 */ 	addiu	$a1,$a1,-2544
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
/*     de4c:	3c018006 */ 	lui	$at,0x8006
/*     de50:	ac2ff2f4 */ 	sw	$t7,-0xd0c($at)
.NB0000de54:
/*     de54:	0c001c6c */ 	jal	func000070d0
/*     de58:	00000000 */ 	sll	$zero,$zero,0x0
/*     de5c:	0fc68554 */ 	jal	func0f1a78b0
/*     de60:	00000000 */ 	sll	$zero,$zero,0x0
/*     de64:	0fc585fd */ 	jal	func0f166f74
/*     de68:	00000000 */ 	sll	$zero,$zero,0x0
/*     de6c:	0fc5c2fc */ 	jal	stub0f175f50
/*     de70:	00000000 */ 	sll	$zero,$zero,0x0
/*     de74:	0fc5c30c */ 	jal	func0f175f90
/*     de78:	00000000 */ 	sll	$zero,$zero,0x0
/*     de7c:	3c198006 */ 	lui	$t9,0x8006
/*     de80:	8f39f2d0 */ 	lw	$t9,-0xd30($t9)
/*     de84:	13200003 */ 	beqz	$t9,.NB0000de94
/*     de88:	3c047005 */ 	lui	$a0,0x7005
/*     de8c:	0c004dd3 */ 	jal	argSetString
/*     de90:	248450f0 */ 	addiu	$a0,$a0,0x50f0
.NB0000de94:
/*     de94:	3c04800b */ 	lui	$a0,0x800b
/*     de98:	0c013100 */ 	jal	osVirtualToPhysical
/*     de9c:	24841a70 */ 	addiu	$a0,$a0,0x1a70
/*     dea0:	3c038009 */ 	lui	$v1,0x8009
/*     dea4:	8c6330f0 */ 	lw	$v1,0x30f0($v1)
/*     dea8:	3c018000 */ 	lui	$at,0x8000
/*     deac:	00412025 */ 	or	$a0,$v0,$at
/*     deb0:	0c004996 */ 	jal	memInit
/*     deb4:	00642823 */ 	subu	$a1,$v1,$a0
/*     deb8:	0c004ab1 */ 	jal	memResetPool
/*     debc:	24040008 */ 	addiu	$a0,$zero,0x8
/*     dec0:	0c004ab1 */ 	jal	memResetPool
/*     dec4:	24040006 */ 	addiu	$a0,$zero,0x6
/*     dec8:	0c003535 */ 	jal	crashReset
/*     decc:	00000000 */ 	sll	$zero,$zero,0x0
/*     ded0:	0fc02bb0 */ 	jal	mpInitPresetFeatures
/*     ded4:	00000000 */ 	sll	$zero,$zero,0x0
/*     ded8:	0fc5c69f */ 	jal	func0f176ddc
/*     dedc:	00000000 */ 	sll	$zero,$zero,0x0
/*     dee0:	0c000dbc */ 	jal	func000034d0
/*     dee4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dee8:	0fc02b90 */ 	jal	loadTextureList
/*     deec:	00000000 */ 	sll	$zero,$zero,0x0
/*     def0:	0fc00000 */ 	jal	func0f000000
/*     def4:	00000000 */ 	sll	$zero,$zero,0x0
/*     def8:	0fc5890e */ 	jal	lv0f167af8
/*     defc:	00000000 */ 	sll	$zero,$zero,0x0
/*     df00:	0fc40c5b */ 	jal	cheatsDisableAll
/*     df04:	00000000 */ 	sll	$zero,$zero,0x0
/*     df08:	0c003c68 */ 	jal	func0000e9c0
/*     df0c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df10:	0fc53628 */ 	jal	func0f1531a0
/*     df14:	00000000 */ 	sll	$zero,$zero,0x0
/*     df18:	0c005002 */ 	jal	func00014008nb
/*     df1c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df20:	0fc48954 */ 	jal	func0f127910
/*     df24:	00000000 */ 	sll	$zero,$zero,0x0
/*     df28:	0fc59ef0 */ 	jal	frametimeInit
/*     df2c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df30:	0fc02bac */ 	jal	stub0f00b200
/*     df34:	00000000 */ 	sll	$zero,$zero,0x0
/*     df38:	0c002708 */ 	jal	func00009a80
/*     df3c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df40:	0fc0021c */ 	jal	stub0f000870
/*     df44:	00000000 */ 	sll	$zero,$zero,0x0
/*     df48:	0fc00220 */ 	jal	func0f000880
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
/*     df80:	0fc60985 */ 	jal	mpSetDefaultSetup
/*     df84:	00000000 */ 	sll	$zero,$zero,0x0
/*     df88:	0fc512be */ 	jal	func0f14a328
/*     df8c:	00000000 */ 	sll	$zero,$zero,0x0
/*     df90:	0fc44b4c */ 	jal	pak0f1189d8
/*     df94:	00000000 */ 	sll	$zero,$zero,0x0
/*     df98:	0fc512e3 */ 	jal	func0f14a3bc
/*     df9c:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfa0:	0c0091e8 */ 	jal	func000233c0
/*     dfa4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfa8:	0fc00040 */ 	jal	func0f000100
/*     dfac:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfb0:	0fc0004c */ 	jal	func0f000130
/*     dfb4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfb8:	0fc00214 */ 	jal	stub0f000850
/*     dfbc:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfc0:	0fc00218 */ 	jal	stub0f000860
/*     dfc4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfc8:	0fc00024 */ 	jal	func0f000090
/*     dfcc:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfd0:	0c002767 */ 	jal	func00009bf8
/*     dfd4:	00000000 */ 	sll	$zero,$zero,0x0
/*     dfd8:	0c00281a */ 	jal	func00009ec4
/*     dfdc:	24040001 */ 	addiu	$a0,$zero,0x1
/*     dfe0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*     dfe4:	3c018006 */ 	lui	$at,0x8006
/*     dfe8:	8fb00028 */ 	lw	$s0,0x28($sp)
/*     dfec:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*     dff0:	8fb20030 */ 	lw	$s2,0x30($sp)
/*     dff4:	ac20f638 */ 	sw	$zero,-0x9c8($at)
/*     dff8:	03e00008 */ 	jr	$ra
/*     dffc:	27bd14e0 */ 	addiu	$sp,$sp,0x14e0
);
#endif

const char var70053a98[] = "-level_";
const char var70053aa0[] = "          -ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400";

//extern u8 _accessingpakSegmentRomStart;
//extern u8 _accessingpakSegmentRomEnd;
//extern u8 _copyrightSegmentRomStart;
//extern u8 _copyrightSegmentRomEnd;
//extern u8 _bssSegmentEnd;

// Mismatch: goal saves j to stack in its loop and puts &sp1450 in s0, while the
// below puts j in s0 and calculates &sp1450 each time. The key to solving this
// will probably be to find out what sp1470 and sp1450 are.
//void mainInit(void)
//{
//	s32 x;
//	s32 y;
//	OSMesg msg; // 14cc
//	OSTimer timer; // 14a8
//	OSMesgQueue queue; // 1490
//	s32 j;
//	s32 i;
//	u16 *fb;
//	u16 *texture; // 48?
//	u32 uVar2;
//	u32 iVar5;
//	u32 tmp;
//
//	faultCreateThread();
//	dmaInit();
//	amgrAllocateStack();
//	gvarsInit();
//	func000121e0();
//	func00012a0c();
//	func00013758();
//	func00009ab0();
//	var8005d9b0 = rmonIsDisabled();
//	joySystemInit();
//	osCreateMesgQueue(&queue, &msg, 1);
//
//	for (i = 0; i < 4; i++) {
//		osSetTimer(&timer, 781250 * 6, 0, &queue, &msg);
//		osRecvMesg(&queue, &msg, OS_MESG_BLOCK);
//
//		if (i == 1) {
//			joy00013dfc();
//		} else if (i >= 2) {
//			joyDebugJoy();
//		}
//	}
//
//	if (argFindByPrefix(1, "-level_") == 0) {
//		var8005d9b0 = 1;
//	}
//
//	// If holding start on any controller, open boot pak menu
//	if (joyGetButtons(0, START_BUTTON) == 0
//			&& joyGetButtons(1, START_BUTTON) == 0
//			&& joyGetButtons(2, START_BUTTON) == 0
//			&& joyGetButtons(3, START_BUTTON) == 0) {
//		g_DoBootPakMenu = false;
//	} else {
//		g_DoBootPakMenu = true;
//	}
//
//	{
//		OSMesg sp1470 = NULL;
//		u32 sp1450[] = { 0x20000, 0, 0, 0, 0, 0, 0, 0 };
//		u8 sp50[5120];
//		u32 stack;
//
//		if (initGetMemSize() <= 4 * 1024 * 1024) {
//			iVar5 = 0x803f50b8 - var8005cf84 * 8;
//			iVar5 -= 548864 * 2;
//			iVar5 = iVar5 - (iVar5 & 0x1fff) - 0x1c80;
//		} else {
//			iVar5 = 0x80800000;
//		}
//
//		iVar5 -= 640 * 480 * 2;
//		iVar5 -= 0x40;
//		fb = (u16 *)ALIGN64(iVar5 | 0x80000000);
//
//		// DMA the texture from the ROM to the framebuffer.
//		// It's using the framebuffer as temporary scratch memory, presumably so
//		// the texture format can be changed then copied into the framebuffer in
//		// the correct format.
//		if (g_DoBootPakMenu) {
//			dmaExec(fb, &_accessingpakSegmentRomStart, &_accessingpakSegmentRomEnd - &_accessingpakSegmentRomStart);
//		} else {
//			dmaExec(fb, &_copyrightSegmentRomStart, &_copyrightSegmentRomEnd - &_copyrightSegmentRomStart);
//		}
//
//		// Prepare space for the texture immediately before the framebuffer
//		// Both textures are 507x48
//		texture = fb - 507 * 48;
//
//		// Convert the texture format? Probably reading from fb and writing to texture
//		rzipInflate(fb, texture, &sp50);
//
//		// Clear the framebuffer
//		// This seems a bit wasteful. The buffer is 640x480, so the y increment
//		// should be 640. But it's 576, so some bytes are zeroed multiple times.
//		for (y = 0; y < 480 * 576; y += 576) {
//			for (x = 0; x < 640; x++) {
//				fb[y + x] = 0;
//			}
//		}
//
//		// Copy the texture to the framebuffer
//		if (osTvType != OS_TV_TYPE_PAL) {
//			s32 fby = 0;
//
//			for (y = 0; y < 48 * 507; y += 507) {
//				for (x = 0; x < 507; x++) {
//					fb[fby + x + 69] = texture[y + x];
//				}
//
//				fby += 576;
//			}
//		}
//
//		func0000aab0(2);
//		func00009b50(fb);
//
//		g_RdpOutBufferStart = texture;
//		g_RdpOutBufferEnd = texture + 0x400; // 0x800 bytes, because texture is u16
//
//		while (osRecvMesg(&var8008db30, &sp1470, OS_MESG_NOBLOCK) == 0) {
//			// empty
//		}
//
//		// Mismatch begins here
//		// 8bc
//		j = 0;
//
//		while (j < 6) {
//			osRecvMesg(&var8008db30, &sp1470, OS_MESG_BLOCK);
//
//			if (*(s16 *)sp1470 == 1) {
//				func0000a044();
//				rdpCreateTask(var8005dcc8, var8005dcf0, 0, sp1450);
//				j++;
//			}
//		}
//	}
//
//	// From the N64 SDK:
//	//
//	//     Please design the game program so that it won't execute normally
//	//     when an unexpected television system format is detected by osTvType.
//	//     Design the program to either go into an infinite loop or display a
//	//     message indicating a system error.
//	//
//	if (osTvType == OS_TV_TYPE_PAL) {
//		while (1);
//	}
//
//	func000070d0();
//	func0f1a78b0();
//	func0f166f74();
//	stub0f175f50();
//	func0f175f90();
//
//	if (var8005d9b0) {
//		argSetString("          -ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400");
//	}
//
//	uVar2 = osVirtualToPhysical(&_bssSegmentEnd) | 0x80000000;
//	tmp = var80090b00;
//	memInit(uVar2, tmp - uVar2);
//
//	memResetPool(MEMPOOL_8);
//	memResetPool(MEMPOOL_PERMANENT);
//	crashReset();
//	mpInitPresetFeatures();
//	func0f176ddc();
//	func000034d0();
//	loadTextureList();
//	func0f000000();
//	lv0f167af8();
//	cheatsDisableAll();
//	func0000e9c0();
//	func0f1531a0();
//	func00013790();
//	func0f127910();
//	frametimeInit();
//	stub0f00b200();
//	func00009a80();
//	stub0f000870();
//	func0f000880();
//	stub0f0008e0();
//	stub0f0008f0();
//	stub0f000900();
//	stub0f00b180();
//	stub0f000910();
//	stub0f000840();
//	mpSetDefaultSetup();
//	func0f14a328();
//	pak0f1189d8();
//	func0f14a3bc();
//	func000233c0();
//	func0f000100();
//	func0f000130();
//	stub0f000850();
//	stub0f000860();
//	func0f000090();
//	func00009bf8();
//	func00009ec4(1);
//
//	var8005dd18 = 0;
//}

u32 var8005dd1c = 0x00020000;
u32 var8005dd20 = 0x00000000;
u32 var8005dd24 = 0x00000000;
u32 var8005dd28 = 0x00000000;
u32 var8005dd2c = 0x00000000;
u32 var8005dd30 = 0x00000000;
u32 var8005dd34 = 0x00000000;
u32 var8005dd38 = 0x00000000;

u32 var8005dd3c = 0x00000000;
u32 var8005dd40 = 0x00000000;
u32 var8005dd44 = 0x00000000;
u32 var8005dd48 = 0x00000000;
u32 var8005dd4c = 0x00000000;
u32 var8005dd50 = 0x00000000;
s32 g_MainStageNum = -1;
u32 var8005dd58 = 0x00000000;

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0000e000nb
/*     e000:	240e0001 */ 	addiu	$t6,$zero,0x1
/*     e004:	3c018006 */ 	lui	$at,0x8006
/*     e008:	03e00008 */ 	jr	$ra
/*     e00c:	ac2ef2dc */ 	sw	$t6,-0xd24($at)
);
#endif

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0000e010nb
/*     e010:	3c028006 */ 	lui	$v0,0x8006
/*     e014:	2442f2e0 */ 	addiu	$v0,$v0,-3360
/*     e018:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*     e01c:	39cf0001 */ 	xori	$t7,$t6,0x1
/*     e020:	03e00008 */ 	jr	$ra
/*     e024:	ac4f0000 */ 	sw	$t7,0x0($v0)
);
#endif

void mainEntry(void)
{
	mainInit();
	rdpInit();
	sndInit();

	while (true) {
		mainLoop();
	}
}

void func0000db30(char *string, void *ptr)
{
	// empty
}

#if VERSION >= VERSION_NTSC_1_0
/**
 * This function enters an infinite loop which iterates once per stage load.
 * Within this loop is an inner loop which runs very frequently and decides
 * whether to run mainTick on each iteration.
 */
void mainLoop(void)
{
	s32 ending = false;
	u32 array[] = {0x20000, 0, 0, 0, 0, 0, 0, 0};
	OSMesg msg;
	s32 index;
	s32 numplayers;

	func0f175f98();

	var8005d9c4 = 0;
	argGetLevel(&g_StageNum);

	if (g_DoBootPakMenu) {
		g_Vars.unk0004e4 = 253;
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
		var8005d9cc = 0;
		var8005d9c8 = 1;
		msg = NULL;
		g_MainIsEndscreen = false;

		if (var8005d9b0 && var8005d9c4 == 0) {
			index = -1;

			if (IS4MB()) {
				if (g_StageNum < STAGE_TITLE && getNumPlayers() >= 2) {
					index = 0;

					while (g_StageAllocations4Mb[index].stagenum) {
						if (g_StageAllocations4Mb[index].stagenum == g_StageNum + 400) {
							break;
						}

						index++;
					}

					if (g_StageAllocations4Mb[index].stagenum == 0) {
						index = -1;
					}
				}

				if (index) {
					// empty
				}

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
					index = 0;

					while (g_StageAllocations8Mb[index].stagenum) {
						if (g_StageNum + 400 == g_StageAllocations8Mb[index].stagenum) {
							break;
						}

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

		memResetPool(MEMPOOL_7);
		memResetPool(MEMPOOL_STAGE);
		func0f1672f0(4);

		if (argFindByPrefix(1, "-ma")) {
			var8005d9b8 = strtol(argFindByPrefix(1, "-ma"), NULL, 0) * 1024;
		}

		func00012a14(malloc(var8005d9b8, MEMPOOL_STAGE), var8005d9b8);
		stageLoadCommonLang(g_StageNum);
		playersUnrefAll();

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

		playersAllocate(numplayers);

		if (argFindByPrefix(1, "-mpbots")) {
			g_Vars.lvmpbotlevel = 1;
		}

		if (g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) {
			g_MpSetup.chrslots = 0x03;
			mpInit();
		} else if (g_Vars.perfectbuddynum) {
			mpInit();
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
			mpInit();
		}

		gfxInitMemory();
		joy00013dfc();
		func00013798();
		func0f17608c(g_StageNum);
		lvInit(g_StageNum);
		func00009c3c(g_StageNum);
		frametimeCalculate();
		func00009a90();

		while (osRecvMesg(&var8008db30, &msg, OS_MESG_NOBLOCK) != -1) {
			// empty
		}

		while (g_MainStageNum < 0 || var8005d9cc != 0) {
			s32 tmp;
			osRecvMesg(&var8008db30, &msg, OS_MESG_BLOCK);

			switch (*(s16 *)msg) {
			case 1:
				tmp = osGetCount() - g_Vars.thisframetime;
#if PAL
				if (tmp >= g_Vars.mininc60 * 937500 - 937500 / 2) {
					mainTick();
				}
#else
				if (tmp >= g_Vars.mininc60 * 781250 - 781250 / 2) {
					mainTick();
				}
#endif
				break;
			case 2:
				var8005d9cc--;
				break;
			case 5:
				var8005d9cc = 4;
				break;
			}
		}

		lvReset();
		memDisablePool(MEMPOOL_STAGE);
		memDisablePool(MEMPOOL_7);
		func0f1672f0(4);
		func00009ec4(1);
		pak0f116994();

		g_StageNum = g_MainStageNum;
		g_MainStageNum = -1;
	}

	// Unreachable
	func0f175fc8();
}
#else
const char mainrodata00[] = "-hard";
const char mainrodata01[] = "-hard";
const char mainrodata02[] = "-ma";
const char mainrodata03[] = "-ma";
const char mainrodata04[] = "-play";
const char mainrodata05[] = "-play";
const char mainrodata06[] = "-coop";
const char mainrodata07[] = "-anti";
const char mainrodata08[] = "-mpbots";
const char mainrodata09[] = "-play";
const char mainrodata10[] = "boss.c default: %08x type %d\n";

GLOBAL_ASM(
glabel mainLoop
/*     e07c:	27bdff18 */ 	addiu	$sp,$sp,-232
/*     e080:	3c0f8006 */ 	lui	$t7,0x8006
/*     e084:	afbf003c */ 	sw	$ra,0x3c($sp)
/*     e088:	afbe0038 */ 	sw	$s8,0x38($sp)
/*     e08c:	afb70034 */ 	sw	$s7,0x34($sp)
/*     e090:	afb60030 */ 	sw	$s6,0x30($sp)
/*     e094:	afb5002c */ 	sw	$s5,0x2c($sp)
/*     e098:	afb40028 */ 	sw	$s4,0x28($sp)
/*     e09c:	afb30024 */ 	sw	$s3,0x24($sp)
/*     e0a0:	afb20020 */ 	sw	$s2,0x20($sp)
/*     e0a4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*     e0a8:	afb00018 */ 	sw	$s0,0x18($sp)
/*     e0ac:	afa000e4 */ 	sw	$zero,0xe4($sp)
/*     e0b0:	25eff67c */ 	addiu	$t7,$t7,-2436
/*     e0b4:	8de10000 */ 	lw	$at,0x0($t7)
/*     e0b8:	8de80004 */ 	lw	$t0,0x4($t7)
/*     e0bc:	27ae00c4 */ 	addiu	$t6,$sp,0xc4
/*     e0c0:	adc10000 */ 	sw	$at,0x0($t6)
/*     e0c4:	adc80004 */ 	sw	$t0,0x4($t6)
/*     e0c8:	8de8000c */ 	lw	$t0,0xc($t7)
/*     e0cc:	8de10008 */ 	lw	$at,0x8($t7)
/*     e0d0:	3c04bc00 */ 	lui	$a0,0xbc00
/*     e0d4:	adc8000c */ 	sw	$t0,0xc($t6)
/*     e0d8:	adc10008 */ 	sw	$at,0x8($t6)
/*     e0dc:	8de10010 */ 	lw	$at,0x10($t7)
/*     e0e0:	8de80014 */ 	lw	$t0,0x14($t7)
/*     e0e4:	00001825 */ 	or	$v1,$zero,$zero
/*     e0e8:	adc10010 */ 	sw	$at,0x10($t6)
/*     e0ec:	adc80014 */ 	sw	$t0,0x14($t6)
/*     e0f0:	8de8001c */ 	lw	$t0,0x1c($t7)
/*     e0f4:	8de10018 */ 	lw	$at,0x18($t7)
/*     e0f8:	adc8001c */ 	sw	$t0,0x1c($t6)
/*     e0fc:	adc10018 */ 	sw	$at,0x18($t6)
/*     e100:	24024f4a */ 	addiu	$v0,$zero,0x4f4a
/*     e104:	24014f4a */ 	addiu	$at,$zero,0x4f4a
/*     e108:	10410007 */ 	beq	$v0,$at,.NB0000e128
/*     e10c:	24014c53 */ 	addiu	$at,$zero,0x4c53
/*     e110:	10410005 */ 	beq	$v0,$at,.NB0000e128
/*     e114:	2401504d */ 	addiu	$at,$zero,0x504d
/*     e118:	10410003 */ 	beq	$v0,$at,.NB0000e128
/*     e11c:	24014d50 */ 	addiu	$at,$zero,0x4d50
/*     e120:	54410008 */ 	bnel	$v0,$at,.NB0000e144
/*     e124:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0000e128:
/*     e128:	24024653 */ 	addiu	$v0,$zero,0x4653
/*     e12c:	24014653 */ 	addiu	$at,$zero,0x4653
/*     e130:	10410004 */ 	beq	$v0,$at,.NB0000e144
/*     e134:	24015245 */ 	addiu	$at,$zero,0x5245
/*     e138:	10410002 */ 	beq	$v0,$at,.NB0000e144
/*     e13c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e140:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0000e144:
/*     e144:	10600003 */ 	beqz	$v1,.NB0000e154
/*     e148:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000e14c:
/*     e14c:	1000ffff */ 	beqz	$zero,.NB0000e14c
/*     e150:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000e154:
/*     e154:	0fc5c30e */ 	jal	func0f175f98
/*     e158:	00000000 */ 	sll	$zero,$zero,0x0
/*     e15c:	3c018006 */ 	lui	$at,0x8006
/*     e160:	3c048006 */ 	lui	$a0,0x8006
/*     e164:	ac20f2e4 */ 	sw	$zero,-0xd1c($at)
/*     e168:	0c004e49 */ 	jal	argGetLevel
/*     e16c:	2484f2d4 */ 	addiu	$a0,$a0,-3372
/*     e170:	3c098006 */ 	lui	$t1,0x8006
/*     e174:	8d29f2f4 */ 	lw	$t1,-0xd0c($t1)
/*     e178:	3c028006 */ 	lui	$v0,0x8006
/*     e17c:	2442f2d4 */ 	addiu	$v0,$v0,-3372
/*     e180:	11200002 */ 	beqz	$t1,.NB0000e18c
/*     e184:	240a005b */ 	addiu	$t2,$zero,0x5b
/*     e188:	ac4a0000 */ 	sw	$t2,0x0($v0)
.NB0000e18c:
/*     e18c:	3c028006 */ 	lui	$v0,0x8006
/*     e190:	2442f2d4 */ 	addiu	$v0,$v0,-3372
/*     e194:	8c440000 */ 	lw	$a0,0x0($v0)
/*     e198:	2401005a */ 	addiu	$at,$zero,0x5a
/*     e19c:	10810016 */ 	beq	$a0,$at,.NB0000e1f8
/*     e1a0:	00000000 */ 	sll	$zero,$zero,0x0
/*     e1a4:	0fc06ba1 */ 	jal	titleSetNextStage
/*     e1a8:	00000000 */ 	sll	$zero,$zero,0x0
/*     e1ac:	3c0b8006 */ 	lui	$t3,0x8006
/*     e1b0:	8d6bf2d4 */ 	lw	$t3,-0xd2c($t3)
/*     e1b4:	2961005a */ 	slti	$at,$t3,0x5a
/*     e1b8:	1020000f */ 	beqz	$at,.NB0000e1f8
/*     e1bc:	00000000 */ 	sll	$zero,$zero,0x0
/*     e1c0:	0fc06b9e */ 	jal	func0f01b148
/*     e1c4:	00002025 */ 	or	$a0,$zero,$zero
/*     e1c8:	3c057005 */ 	lui	$a1,0x7005
/*     e1cc:	24a55124 */ 	addiu	$a1,$a1,0x5124
/*     e1d0:	0c004e18 */ 	jal	argFindByPrefix
/*     e1d4:	24040001 */ 	addiu	$a0,$zero,0x1
/*     e1d8:	10400007 */ 	beqz	$v0,.NB0000e1f8
/*     e1dc:	24040001 */ 	addiu	$a0,$zero,0x1
/*     e1e0:	3c057005 */ 	lui	$a1,0x7005
/*     e1e4:	0c004e18 */ 	jal	argFindByPrefix
/*     e1e8:	24a5512c */ 	addiu	$a1,$a1,0x512c
/*     e1ec:	90440000 */ 	lbu	$a0,0x0($v0)
/*     e1f0:	0fc59ed6 */ 	jal	lvSetDifficulty
/*     e1f4:	2484ffd0 */ 	addiu	$a0,$a0,-48
.NB0000e1f8:
/*     e1f8:	3c028006 */ 	lui	$v0,0x8006
/*     e1fc:	2442f2d4 */ 	addiu	$v0,$v0,-3372
/*     e200:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*     e204:	24010026 */ 	addiu	$at,$zero,0x26
/*     e208:	3c0d8009 */ 	lui	$t5,0x8009
/*     e20c:	15810007 */ 	bne	$t4,$at,.NB0000e22c
/*     e210:	00000000 */ 	sll	$zero,$zero,0x0
/*     e214:	91ad30e0 */ 	lbu	$t5,0x30e0($t5)
/*     e218:	24170001 */ 	addiu	$s7,$zero,0x1
/*     e21c:	2419005d */ 	addiu	$t9,$zero,0x5d
/*     e220:	16ed0002 */ 	bne	$s7,$t5,.NB0000e22c
/*     e224:	00000000 */ 	sll	$zero,$zero,0x0
/*     e228:	ac590000 */ 	sw	$t9,0x0($v0)
.NB0000e22c:
/*     e22c:	0c012638 */ 	jal	osGetCount
/*     e230:	24170001 */ 	addiu	$s7,$zero,0x1
/*     e234:	0c004d96 */ 	jal	rngSetSeed
/*     e238:	00402025 */ 	or	$a0,$v0,$zero
/*     e23c:	3c1e8006 */ 	lui	$s8,0x8006
/*     e240:	3c138009 */ 	lui	$s3,0x8009
/*     e244:	3c12800a */ 	lui	$s2,0x800a
/*     e248:	3c108006 */ 	lui	$s0,0x8006
/*     e24c:	2610f2ec */ 	addiu	$s0,$s0,-3348
/*     e250:	2652e6c0 */ 	addiu	$s2,$s2,-6464
/*     e254:	26730160 */ 	addiu	$s3,$s3,0x160
/*     e258:	27def674 */ 	addiu	$s8,$s8,-2444
/*     e25c:	2416ffff */ 	addiu	$s6,$zero,-1
/*     e260:	27b50058 */ 	addiu	$s5,$sp,0x58
/*     e264:	27b400b8 */ 	addiu	$s4,$sp,0xb8
.NB0000e268:
/*     e268:	ae000000 */ 	sw	$zero,0x0($s0)
/*     e26c:	3c188006 */ 	lui	$t8,0x8006
/*     e270:	8f18f2d0 */ 	lw	$t8,-0xd30($t8)
/*     e274:	3c018006 */ 	lui	$at,0x8006
/*     e278:	ac37f2e8 */ 	sw	$s7,-0xd18($at)
/*     e27c:	3c018006 */ 	lui	$at,0x8006
/*     e280:	afa000b8 */ 	sw	$zero,0xb8($sp)
/*     e284:	1300007e */ 	beqz	$t8,.NB0000e480
/*     e288:	ac20f2f0 */ 	sw	$zero,-0xd10($at)
/*     e28c:	3c0e8006 */ 	lui	$t6,0x8006
/*     e290:	8dcef2e4 */ 	lw	$t6,-0xd1c($t6)
/*     e294:	3c0f8009 */ 	lui	$t7,0x8009
/*     e298:	15c00079 */ 	bnez	$t6,.NB0000e480
/*     e29c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e2a0:	91ef30e0 */ 	lbu	$t7,0x30e0($t7)
/*     e2a4:	02c02825 */ 	or	$a1,$s6,$zero
/*     e2a8:	3c088006 */ 	lui	$t0,0x8006
/*     e2ac:	16ef003c */ 	bne	$s7,$t7,.NB0000e3a0
/*     e2b0:	00000000 */ 	sll	$zero,$zero,0x0
/*     e2b4:	3c088006 */ 	lui	$t0,0x8006
/*     e2b8:	8d08f2d4 */ 	lw	$t0,-0xd2c($t0)
/*     e2bc:	2901005a */ 	slti	$at,$t0,0x5a
/*     e2c0:	1020001f */ 	beqz	$at,.NB0000e340
/*     e2c4:	00000000 */ 	sll	$zero,$zero,0x0
/*     e2c8:	0fc0681e */ 	jal	getNumPlayers
/*     e2cc:	afa500b4 */ 	sw	$a1,0xb4($sp)
/*     e2d0:	28410002 */ 	slti	$at,$v0,0x2
/*     e2d4:	1420001a */ 	bnez	$at,.NB0000e340
/*     e2d8:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*     e2dc:	3c098006 */ 	lui	$t1,0x8006
/*     e2e0:	8d29f4f0 */ 	lw	$t1,-0xb10($t1)
/*     e2e4:	3c068006 */ 	lui	$a2,0x8006
/*     e2e8:	24c6f4f0 */ 	addiu	$a2,$a2,-2832
/*     e2ec:	1120000e */ 	beqz	$t1,.NB0000e328
/*     e2f0:	00002825 */ 	or	$a1,$zero,$zero
/*     e2f4:	3c048006 */ 	lui	$a0,0x8006
/*     e2f8:	8c84f2d4 */ 	lw	$a0,-0xd2c($a0)
/*     e2fc:	3c0a8006 */ 	lui	$t2,0x8006
/*     e300:	2542f4f0 */ 	addiu	$v0,$t2,-2832
/*     e304:	8c430000 */ 	lw	$v1,0x0($v0)
/*     e308:	24840190 */ 	addiu	$a0,$a0,0x190
.NB0000e30c:
/*     e30c:	50830007 */ 	beql	$a0,$v1,.NB0000e32c
/*     e310:	000558c0 */ 	sll	$t3,$a1,0x3
/*     e314:	8c430008 */ 	lw	$v1,0x8($v0)
/*     e318:	24a50001 */ 	addiu	$a1,$a1,0x1
/*     e31c:	24420008 */ 	addiu	$v0,$v0,0x8
/*     e320:	1460fffa */ 	bnez	$v1,.NB0000e30c
/*     e324:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000e328:
/*     e328:	000558c0 */ 	sll	$t3,$a1,0x3
.NB0000e32c:
/*     e32c:	00cb6021 */ 	addu	$t4,$a2,$t3
/*     e330:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*     e334:	15a00002 */ 	bnez	$t5,.NB0000e340
/*     e338:	00000000 */ 	sll	$zero,$zero,0x0
/*     e33c:	02c02825 */ 	or	$a1,$s6,$zero
.NB0000e340:
/*     e340:	3c068006 */ 	lui	$a2,0x8006
/*     e344:	04a10010 */ 	bgez	$a1,.NB0000e388
/*     e348:	24c6f4f0 */ 	addiu	$a2,$a2,-2832
/*     e34c:	8cd90000 */ 	lw	$t9,0x0($a2)
/*     e350:	00002825 */ 	or	$a1,$zero,$zero
/*     e354:	3c048006 */ 	lui	$a0,0x8006
/*     e358:	1320000b */ 	beqz	$t9,.NB0000e388
/*     e35c:	3c188006 */ 	lui	$t8,0x8006
/*     e360:	2702f4f0 */ 	addiu	$v0,$t8,-2832
/*     e364:	8c430000 */ 	lw	$v1,0x0($v0)
/*     e368:	8c84f2d4 */ 	lw	$a0,-0xd2c($a0)
.NB0000e36c:
/*     e36c:	50830007 */ 	beql	$a0,$v1,.NB0000e38c
/*     e370:	000570c0 */ 	sll	$t6,$a1,0x3
/*     e374:	8c430008 */ 	lw	$v1,0x8($v0)
/*     e378:	24a50001 */ 	addiu	$a1,$a1,0x1
/*     e37c:	24420008 */ 	addiu	$v0,$v0,0x8
/*     e380:	1460fffa */ 	bnez	$v1,.NB0000e36c
/*     e384:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000e388:
/*     e388:	000570c0 */ 	sll	$t6,$a1,0x3
.NB0000e38c:
/*     e38c:	00ce7821 */ 	addu	$t7,$a2,$t6
/*     e390:	0c004dd3 */ 	jal	argSetString
/*     e394:	8de40004 */ 	lw	$a0,0x4($t7)
/*     e398:	10000039 */ 	beqz	$zero,.NB0000e480
/*     e39c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000e3a0:
/*     e3a0:	8d08f2d4 */ 	lw	$t0,-0xd2c($t0)
/*     e3a4:	2901005a */ 	slti	$at,$t0,0x5a
/*     e3a8:	1020001f */ 	beqz	$at,.NB0000e428
/*     e3ac:	00000000 */ 	sll	$zero,$zero,0x0
/*     e3b0:	0fc0681e */ 	jal	getNumPlayers
/*     e3b4:	afa500b4 */ 	sw	$a1,0xb4($sp)
/*     e3b8:	28410002 */ 	slti	$at,$v0,0x2
/*     e3bc:	1420001a */ 	bnez	$at,.NB0000e428
/*     e3c0:	8fa500b4 */ 	lw	$a1,0xb4($sp)
/*     e3c4:	3c098006 */ 	lui	$t1,0x8006
/*     e3c8:	8d29f2f8 */ 	lw	$t1,-0xd08($t1)
/*     e3cc:	3c068006 */ 	lui	$a2,0x8006
/*     e3d0:	24c6f2f8 */ 	addiu	$a2,$a2,-3336
/*     e3d4:	1120000e */ 	beqz	$t1,.NB0000e410
/*     e3d8:	00002825 */ 	or	$a1,$zero,$zero
/*     e3dc:	3c048006 */ 	lui	$a0,0x8006
/*     e3e0:	8c84f2d4 */ 	lw	$a0,-0xd2c($a0)
/*     e3e4:	3c0a8006 */ 	lui	$t2,0x8006
/*     e3e8:	2542f2f8 */ 	addiu	$v0,$t2,-3336
/*     e3ec:	8c430000 */ 	lw	$v1,0x0($v0)
/*     e3f0:	24840190 */ 	addiu	$a0,$a0,0x190
.NB0000e3f4:
/*     e3f4:	50830007 */ 	beql	$a0,$v1,.NB0000e414
/*     e3f8:	000558c0 */ 	sll	$t3,$a1,0x3
/*     e3fc:	8c430008 */ 	lw	$v1,0x8($v0)
/*     e400:	24a50001 */ 	addiu	$a1,$a1,0x1
/*     e404:	24420008 */ 	addiu	$v0,$v0,0x8
/*     e408:	1460fffa */ 	bnez	$v1,.NB0000e3f4
/*     e40c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000e410:
/*     e410:	000558c0 */ 	sll	$t3,$a1,0x3
.NB0000e414:
/*     e414:	00cb6021 */ 	addu	$t4,$a2,$t3
/*     e418:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*     e41c:	15a00002 */ 	bnez	$t5,.NB0000e428
/*     e420:	00000000 */ 	sll	$zero,$zero,0x0
/*     e424:	02c02825 */ 	or	$a1,$s6,$zero
.NB0000e428:
/*     e428:	3c068006 */ 	lui	$a2,0x8006
/*     e42c:	04a10010 */ 	bgez	$a1,.NB0000e470
/*     e430:	24c6f2f8 */ 	addiu	$a2,$a2,-3336
/*     e434:	8cd90000 */ 	lw	$t9,0x0($a2)
/*     e438:	00002825 */ 	or	$a1,$zero,$zero
/*     e43c:	3c048006 */ 	lui	$a0,0x8006
/*     e440:	1320000b */ 	beqz	$t9,.NB0000e470
/*     e444:	3c188006 */ 	lui	$t8,0x8006
/*     e448:	2702f2f8 */ 	addiu	$v0,$t8,-3336
/*     e44c:	8c430000 */ 	lw	$v1,0x0($v0)
/*     e450:	8c84f2d4 */ 	lw	$a0,-0xd2c($a0)
.NB0000e454:
/*     e454:	50830007 */ 	beql	$a0,$v1,.NB0000e474
/*     e458:	000570c0 */ 	sll	$t6,$a1,0x3
/*     e45c:	8c430008 */ 	lw	$v1,0x8($v0)
/*     e460:	24a50001 */ 	addiu	$a1,$a1,0x1
/*     e464:	24420008 */ 	addiu	$v0,$v0,0x8
/*     e468:	1460fffa */ 	bnez	$v1,.NB0000e454
/*     e46c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000e470:
/*     e470:	000570c0 */ 	sll	$t6,$a1,0x3
.NB0000e474:
/*     e474:	00ce7821 */ 	addu	$t7,$a2,$t6
/*     e478:	0c004dd3 */ 	jal	argSetString
/*     e47c:	8de40004 */ 	lw	$a0,0x4($t7)
.NB0000e480:
/*     e480:	3c018006 */ 	lui	$at,0x8006
/*     e484:	ac20f2e4 */ 	sw	$zero,-0xd1c($at)
/*     e488:	0c004ab1 */ 	jal	memResetPool
/*     e48c:	24040007 */ 	addiu	$a0,$zero,0x7
/*     e490:	0c004ab1 */ 	jal	memResetPool
/*     e494:	24040004 */ 	addiu	$a0,$zero,0x4
/*     e498:	0fc58709 */ 	jal	func0f1672f0
/*     e49c:	24040004 */ 	addiu	$a0,$zero,0x4
/*     e4a0:	3c057005 */ 	lui	$a1,0x7005
/*     e4a4:	24a55134 */ 	addiu	$a1,$a1,0x5134
/*     e4a8:	0c004e18 */ 	jal	argFindByPrefix
/*     e4ac:	02e02025 */ 	or	$a0,$s7,$zero
/*     e4b0:	1040000b */ 	beqz	$v0,.NB0000e4e0
/*     e4b4:	02e02025 */ 	or	$a0,$s7,$zero
/*     e4b8:	3c057005 */ 	lui	$a1,0x7005
/*     e4bc:	0c004e18 */ 	jal	argFindByPrefix
/*     e4c0:	24a55138 */ 	addiu	$a1,$a1,0x5138
/*     e4c4:	00402025 */ 	or	$a0,$v0,$zero
/*     e4c8:	00002825 */ 	or	$a1,$zero,$zero
/*     e4cc:	0c004f16 */ 	jal	strtol
/*     e4d0:	00003025 */ 	or	$a2,$zero,$zero
/*     e4d4:	00024280 */ 	sll	$t0,$v0,0xa
/*     e4d8:	3c018006 */ 	lui	$at,0x8006
/*     e4dc:	ac28f2d8 */ 	sw	$t0,-0xd28($at)
.NB0000e4e0:
/*     e4e0:	3c048006 */ 	lui	$a0,0x8006
/*     e4e4:	8c84f2d8 */ 	lw	$a0,-0xd28($a0)
/*     e4e8:	0c004a0e */ 	jal	malloc
/*     e4ec:	24050004 */ 	addiu	$a1,$zero,0x4
/*     e4f0:	3c058006 */ 	lui	$a1,0x8006
/*     e4f4:	8ca5f2d8 */ 	lw	$a1,-0xd28($a1)
/*     e4f8:	0c004bed */ 	jal	func00012a14
/*     e4fc:	00402025 */ 	or	$a0,$v0,$zero
/*     e500:	3c048006 */ 	lui	$a0,0x8006
/*     e504:	0fc02bf4 */ 	jal	stageLoadCommonLang
/*     e508:	8c84f2d4 */ 	lw	$a0,-0xd2c($a0)
/*     e50c:	0fc48964 */ 	jal	playersUnrefAll
/*     e510:	00000000 */ 	sll	$zero,$zero,0x0
/*     e514:	3c098006 */ 	lui	$t1,0x8006
/*     e518:	8d29f2d4 */ 	lw	$t1,-0xd2c($t1)
/*     e51c:	02e02025 */ 	or	$a0,$s7,$zero
/*     e520:	3c057005 */ 	lui	$a1,0x7005
/*     e524:	2921005a */ 	slti	$at,$t1,0x5a
/*     e528:	14200003 */ 	bnez	$at,.NB0000e538
/*     e52c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e530:	10000017 */ 	beqz	$zero,.NB0000e590
/*     e534:	00008825 */ 	or	$s1,$zero,$zero
.NB0000e538:
/*     e538:	0c004e18 */ 	jal	argFindByPrefix
/*     e53c:	24a5513c */ 	addiu	$a1,$a1,0x513c
/*     e540:	1040000b */ 	beqz	$v0,.NB0000e570
/*     e544:	02e08825 */ 	or	$s1,$s7,$zero
/*     e548:	3c057005 */ 	lui	$a1,0x7005
/*     e54c:	24a55144 */ 	addiu	$a1,$a1,0x5144
/*     e550:	0c004e18 */ 	jal	argFindByPrefix
/*     e554:	02e02025 */ 	or	$a0,$s7,$zero
/*     e558:	00402025 */ 	or	$a0,$v0,$zero
/*     e55c:	00002825 */ 	or	$a1,$zero,$zero
/*     e560:	0c004f16 */ 	jal	strtol
/*     e564:	00003025 */ 	or	$a2,$zero,$zero
/*     e568:	10000001 */ 	beqz	$zero,.NB0000e570
/*     e56c:	00408825 */ 	or	$s1,$v0,$zero
.NB0000e570:
/*     e570:	0fc0681e */ 	jal	getNumPlayers
/*     e574:	00000000 */ 	sll	$zero,$zero,0x0
/*     e578:	28410002 */ 	slti	$at,$v0,0x2
/*     e57c:	54200005 */ 	bnezl	$at,.NB0000e594
/*     e580:	2a210002 */ 	slti	$at,$s1,0x2
/*     e584:	0fc0681e */ 	jal	getNumPlayers
/*     e588:	00000000 */ 	sll	$zero,$zero,0x0
/*     e58c:	00408825 */ 	or	$s1,$v0,$zero
.NB0000e590:
/*     e590:	2a210002 */ 	slti	$at,$s1,0x2
.NB0000e594:
/*     e594:	10200005 */ 	beqz	$at,.NB0000e5ac
/*     e598:	02e02025 */ 	or	$a0,$s7,$zero
/*     e59c:	ae400294 */ 	sw	$zero,0x294($s2)
/*     e5a0:	ae560298 */ 	sw	$s6,0x298($s2)
/*     e5a4:	10000012 */ 	beqz	$zero,.NB0000e5f0
/*     e5a8:	ae56029c */ 	sw	$s6,0x29c($s2)
.NB0000e5ac:
/*     e5ac:	3c057005 */ 	lui	$a1,0x7005
/*     e5b0:	0c004e18 */ 	jal	argFindByPrefix
/*     e5b4:	24a5514c */ 	addiu	$a1,$a1,0x514c
/*     e5b8:	10400005 */ 	beqz	$v0,.NB0000e5d0
/*     e5bc:	02e02025 */ 	or	$a0,$s7,$zero
/*     e5c0:	ae400294 */ 	sw	$zero,0x294($s2)
/*     e5c4:	ae570298 */ 	sw	$s7,0x298($s2)
/*     e5c8:	10000009 */ 	beqz	$zero,.NB0000e5f0
/*     e5cc:	ae56029c */ 	sw	$s6,0x29c($s2)
.NB0000e5d0:
/*     e5d0:	3c057005 */ 	lui	$a1,0x7005
/*     e5d4:	0c004e18 */ 	jal	argFindByPrefix
/*     e5d8:	24a55154 */ 	addiu	$a1,$a1,0x5154
/*     e5dc:	10400004 */ 	beqz	$v0,.NB0000e5f0
/*     e5e0:	00000000 */ 	sll	$zero,$zero,0x0
/*     e5e4:	ae400294 */ 	sw	$zero,0x294($s2)
/*     e5e8:	ae560298 */ 	sw	$s6,0x298($s2)
/*     e5ec:	ae57029c */ 	sw	$s7,0x29c($s2)
.NB0000e5f0:
/*     e5f0:	0fc48979 */ 	jal	playersAllocate
/*     e5f4:	02202025 */ 	or	$a0,$s1,$zero
/*     e5f8:	3c057005 */ 	lui	$a1,0x7005
/*     e5fc:	24a5515c */ 	addiu	$a1,$a1,0x515c
/*     e600:	0c004e18 */ 	jal	argFindByPrefix
/*     e604:	02e02025 */ 	or	$a0,$s7,$zero
/*     e608:	10400002 */ 	beqz	$v0,.NB0000e614
/*     e60c:	240c0003 */ 	addiu	$t4,$zero,0x3
/*     e610:	ae57031c */ 	sw	$s7,0x31c($s2)
.NB0000e614:
/*     e614:	8e4a0298 */ 	lw	$t2,0x298($s2)
/*     e618:	3c01800b */ 	lui	$at,0x800b
/*     e61c:	05410004 */ 	bgez	$t2,.NB0000e630
/*     e620:	00000000 */ 	sll	$zero,$zero,0x0
/*     e624:	8e4b029c */ 	lw	$t3,0x29c($s2)
/*     e628:	05620006 */ 	bltzl	$t3,.NB0000e644
/*     e62c:	8e4d0470 */ 	lw	$t5,0x470($s2)
.NB0000e630:
/*     e630:	0fc60755 */ 	jal	mpInit
/*     e634:	a42c144e */ 	sh	$t4,0x144e($at)
/*     e638:	10000033 */ 	beqz	$zero,.NB0000e708
/*     e63c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e640:	8e4d0470 */ 	lw	$t5,0x470($s2)
.NB0000e644:
/*     e644:	51a00006 */ 	beqzl	$t5,.NB0000e660
/*     e648:	8e590314 */ 	lw	$t9,0x314($s2)
/*     e64c:	0fc60755 */ 	jal	mpInit
/*     e650:	00000000 */ 	sll	$zero,$zero,0x0
/*     e654:	1000002c */ 	beqz	$zero,.NB0000e708
/*     e658:	00000000 */ 	sll	$zero,$zero,0x0
/*     e65c:	8e590314 */ 	lw	$t9,0x314($s2)
.NB0000e660:
/*     e660:	2a210002 */ 	slti	$at,$s1,0x2
/*     e664:	17200028 */ 	bnez	$t9,.NB0000e708
/*     e668:	00000000 */ 	sll	$zero,$zero,0x0
/*     e66c:	5020000a */ 	beqzl	$at,.NB0000e698
/*     e670:	240e0001 */ 	addiu	$t6,$zero,0x1
/*     e674:	8e58031c */ 	lw	$t8,0x31c($s2)
/*     e678:	02e02025 */ 	or	$a0,$s7,$zero
/*     e67c:	3c057005 */ 	lui	$a1,0x7005
/*     e680:	57000005 */ 	bnezl	$t8,.NB0000e698
/*     e684:	240e0001 */ 	addiu	$t6,$zero,0x1
/*     e688:	0c004e18 */ 	jal	argFindByPrefix
/*     e68c:	24a55164 */ 	addiu	$a1,$a1,0x5164
/*     e690:	1040001d */ 	beqz	$v0,.NB0000e708
/*     e694:	240e0001 */ 	addiu	$t6,$zero,0x1
.NB0000e698:
/*     e698:	3c01800b */ 	lui	$at,0x800b
/*     e69c:	a42e144e */ 	sh	$t6,0x144e($at)
/*     e6a0:	2a210002 */ 	slti	$at,$s1,0x2
/*     e6a4:	14200006 */ 	bnez	$at,.NB0000e6c0
/*     e6a8:	3c0d8006 */ 	lui	$t5,0x8006
/*     e6ac:	3c02800b */ 	lui	$v0,0x800b
/*     e6b0:	24421438 */ 	addiu	$v0,$v0,0x1438
/*     e6b4:	944f0016 */ 	lhu	$t7,0x16($v0)
/*     e6b8:	35e80002 */ 	ori	$t0,$t7,0x2
/*     e6bc:	a4480016 */ 	sh	$t0,0x16($v0)
.NB0000e6c0:
/*     e6c0:	2a210003 */ 	slti	$at,$s1,0x3
/*     e6c4:	14200005 */ 	bnez	$at,.NB0000e6dc
/*     e6c8:	3c02800b */ 	lui	$v0,0x800b
/*     e6cc:	24421438 */ 	addiu	$v0,$v0,0x1438
/*     e6d0:	94490016 */ 	lhu	$t1,0x16($v0)
/*     e6d4:	352a0004 */ 	ori	$t2,$t1,0x4
/*     e6d8:	a44a0016 */ 	sh	$t2,0x16($v0)
.NB0000e6dc:
/*     e6dc:	2a210004 */ 	slti	$at,$s1,0x4
/*     e6e0:	14200005 */ 	bnez	$at,.NB0000e6f8
/*     e6e4:	3c0b800b */ 	lui	$t3,0x800b
/*     e6e8:	956b144e */ 	lhu	$t3,0x144e($t3)
/*     e6ec:	3c01800b */ 	lui	$at,0x800b
/*     e6f0:	356c0008 */ 	ori	$t4,$t3,0x8
/*     e6f4:	a42c144e */ 	sh	$t4,0x144e($at)
.NB0000e6f8:
/*     e6f8:	8dadf2d4 */ 	lw	$t5,-0xd2c($t5)
/*     e6fc:	3c01800b */ 	lui	$at,0x800b
/*     e700:	0fc60755 */ 	jal	mpInit
/*     e704:	a02d1449 */ 	sb	$t5,0x1449($at)
.NB0000e708:
/*     e708:	0fc58724 */ 	jal	gfxInitMemory
/*     e70c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e710:	0c005310 */ 	jal	joy00013dfc
/*     e714:	00000000 */ 	sll	$zero,$zero,0x0
/*     e718:	0c005049 */ 	jal	func00014124nb
/*     e71c:	00000000 */ 	sll	$zero,$zero,0x0
/*     e720:	3c048006 */ 	lui	$a0,0x8006
/*     e724:	0fc5c34b */ 	jal	func0f17608c
/*     e728:	8c84f2d4 */ 	lw	$a0,-0xd2c($a0)
/*     e72c:	3c048006 */ 	lui	$a0,0x8006
/*     e730:	0fc589ee */ 	jal	lvInit
/*     e734:	8c84f2d4 */ 	lw	$a0,-0xd2c($a0)
/*     e738:	3c048006 */ 	lui	$a0,0x8006
/*     e73c:	0c002778 */ 	jal	func00009c3c
/*     e740:	8c84f2d4 */ 	lw	$a0,-0xd2c($a0)
/*     e744:	0fc59f11 */ 	jal	frametimeCalculate
/*     e748:	00000000 */ 	sll	$zero,$zero,0x0
/*     e74c:	0c00270c */ 	jal	func00009a90
/*     e750:	00000000 */ 	sll	$zero,$zero,0x0
/*     e754:	02602025 */ 	or	$a0,$s3,$zero
/*     e758:	02802825 */ 	or	$a1,$s4,$zero
/*     e75c:	0c0126b0 */ 	jal	osRecvMesg
/*     e760:	00003025 */ 	or	$a2,$zero,$zero
/*     e764:	10560006 */ 	beq	$v0,$s6,.NB0000e780
/*     e768:	02602025 */ 	or	$a0,$s3,$zero
.NB0000e76c:
/*     e76c:	02802825 */ 	or	$a1,$s4,$zero
/*     e770:	0c0126b0 */ 	jal	osRecvMesg
/*     e774:	00003025 */ 	or	$a2,$zero,$zero
/*     e778:	5456fffc */ 	bnel	$v0,$s6,.NB0000e76c
/*     e77c:	02602025 */ 	or	$a0,$s3,$zero
.NB0000e780:
/*     e780:	8fd90000 */ 	lw	$t9,0x0($s8)
/*     e784:	07220004 */ 	bltzl	$t9,.NB0000e798
/*     e788:	02602025 */ 	or	$a0,$s3,$zero
/*     e78c:	8e180000 */ 	lw	$t8,0x0($s0)
/*     e790:	13000038 */ 	beqz	$t8,.NB0000e874
/*     e794:	02602025 */ 	or	$a0,$s3,$zero
.NB0000e798:
/*     e798:	02802825 */ 	or	$a1,$s4,$zero
/*     e79c:	0c0126b0 */ 	jal	osRecvMesg
/*     e7a0:	02e03025 */ 	or	$a2,$s7,$zero
/*     e7a4:	0c0006fd */ 	jal	func00001bf4nb
/*     e7a8:	00000000 */ 	sll	$zero,$zero,0x0
/*     e7ac:	8fae00b8 */ 	lw	$t6,0xb8($sp)
/*     e7b0:	24010002 */ 	addiu	$at,$zero,0x2
/*     e7b4:	85c70000 */ 	lh	$a3,0x0($t6)
/*     e7b8:	10f70007 */ 	beq	$a3,$s7,.NB0000e7d8
/*     e7bc:	00000000 */ 	sll	$zero,$zero,0x0
/*     e7c0:	10e10018 */ 	beq	$a3,$at,.NB0000e824
/*     e7c4:	24010005 */ 	addiu	$at,$zero,0x5
/*     e7c8:	10e1001a */ 	beq	$a3,$at,.NB0000e834
/*     e7cc:	240d0004 */ 	addiu	$t5,$zero,0x4
/*     e7d0:	1000001a */ 	beqz	$zero,.NB0000e83c
/*     e7d4:	02a02025 */ 	or	$a0,$s5,$zero
.NB0000e7d8:
/*     e7d8:	0c012638 */ 	jal	osGetCount
/*     e7dc:	00000000 */ 	sll	$zero,$zero,0x0
/*     e7e0:	8e480028 */ 	lw	$t0,0x28($s2)
/*     e7e4:	3c01000b */ 	lui	$at,0xb
/*     e7e8:	3421ebc2 */ 	ori	$at,$at,0xebc2
/*     e7ec:	01010019 */ 	multu	$t0,$at
/*     e7f0:	8e4f0018 */ 	lw	$t7,0x18($s2)
/*     e7f4:	3c01fffa */ 	lui	$at,0xfffa
/*     e7f8:	34210a1f */ 	ori	$at,$at,0xa1f
/*     e7fc:	004f1823 */ 	subu	$v1,$v0,$t7
/*     e800:	00004812 */ 	mflo	$t1
/*     e804:	01215021 */ 	addu	$t2,$t1,$at
/*     e808:	006a082b */ 	sltu	$at,$v1,$t2
/*     e80c:	54200014 */ 	bnezl	$at,.NB0000e860
/*     e810:	8fd80000 */ 	lw	$t8,0x0($s8)
/*     e814:	0c003a3b */ 	jal	mainTick
/*     e818:	00000000 */ 	sll	$zero,$zero,0x0
/*     e81c:	10000010 */ 	beqz	$zero,.NB0000e860
/*     e820:	8fd80000 */ 	lw	$t8,0x0($s8)
.NB0000e824:
/*     e824:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*     e828:	256cffff */ 	addiu	$t4,$t3,-1
/*     e82c:	1000000b */ 	beqz	$zero,.NB0000e85c
/*     e830:	ae0c0000 */ 	sw	$t4,0x0($s0)
.NB0000e834:
/*     e834:	10000009 */ 	beqz	$zero,.NB0000e85c
/*     e838:	ae0d0000 */ 	sw	$t5,0x0($s0)
.NB0000e83c:
/*     e83c:	3c057005 */ 	lui	$a1,0x7005
/*     e840:	24a5516c */ 	addiu	$a1,$a1,0x516c
/*     e844:	0c004fc1 */ 	jal	sprintf
/*     e848:	8fa600b8 */ 	lw	$a2,0xb8($sp)
/*     e84c:	0c003074 */ 	jal	func0000c1d0nb
/*     e850:	02a02025 */ 	or	$a0,$s5,$zero
/*     e854:	24190045 */ 	addiu	$t9,$zero,0x45
/*     e858:	a0190000 */ 	sb	$t9,0x0($zero)
.NB0000e85c:
/*     e85c:	8fd80000 */ 	lw	$t8,0x0($s8)
.NB0000e860:
/*     e860:	0702ffcd */ 	bltzl	$t8,.NB0000e798
/*     e864:	02602025 */ 	or	$a0,$s3,$zero
/*     e868:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*     e86c:	55c0ffca */ 	bnezl	$t6,.NB0000e798
/*     e870:	02602025 */ 	or	$a0,$s3,$zero
.NB0000e874:
/*     e874:	0fc59e56 */ 	jal	lvReset
/*     e878:	00000000 */ 	sll	$zero,$zero,0x0
/*     e87c:	0c004acc */ 	jal	memDisablePool
/*     e880:	24040004 */ 	addiu	$a0,$zero,0x4
/*     e884:	0c004acc */ 	jal	memDisablePool
/*     e888:	24040007 */ 	addiu	$a0,$zero,0x7
/*     e88c:	0fc58709 */ 	jal	func0f1672f0
/*     e890:	24040004 */ 	addiu	$a0,$zero,0x4
/*     e894:	0c00281a */ 	jal	func00009ec4
/*     e898:	02e02025 */ 	or	$a0,$s7,$zero
/*     e89c:	8fcf0000 */ 	lw	$t7,0x0($s8)
/*     e8a0:	8fa800e4 */ 	lw	$t0,0xe4($sp)
/*     e8a4:	3c018006 */ 	lui	$at,0x8006
/*     e8a8:	ac2ff2d4 */ 	sw	$t7,-0xd2c($at)
/*     e8ac:	1100fe6e */ 	beqz	$t0,.NB0000e268
/*     e8b0:	afd60000 */ 	sw	$s6,0x0($s8)
/*     e8b4:	0fc5c31a */ 	jal	func0f175fc8
/*     e8b8:	00000000 */ 	sll	$zero,$zero,0x0
/*     e8bc:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*     e8c0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*     e8c4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*     e8c8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*     e8cc:	8fb30024 */ 	lw	$s3,0x24($sp)
/*     e8d0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*     e8d4:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*     e8d8:	8fb60030 */ 	lw	$s6,0x30($sp)
/*     e8dc:	8fb70034 */ 	lw	$s7,0x34($sp)
/*     e8e0:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*     e8e4:	03e00008 */ 	jr	$ra
/*     e8e8:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
);
#endif

#if VERSION >= VERSION_NTSC_1_0
void mainTick(void)
{
	Gfx *gdl;
	Gfx *gdlstart;
	u32 array[] = {0x20000, 0, 0, 0, 0, 0, 0, 0};
	s32 i;

	if (g_MainStageNum < 0 && var8005d9cc < 2) {
		frametimeCalculate();
		func00009a98();
		func00009a90();
		func00009aa0(0x20000);
		func000034d8();
		joyDebugJoy();
		func00001b28(0);

		if (var8005d9c8) {
			gdl = gdlstart = gfxGetMasterDisplayList();

			gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
			gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

			lvTick();
			randomisePlayerOrder();

			if (g_StageNum < STAGE_TITLE) {
				for (i = 0; i < PLAYERCOUNT(); i++) {
					setCurrentPlayerNum(getPlayerByOrderNum(i));

					if (g_StageNum != STAGE_TEST_OLD || !titleIsKeepingMode()) {
						viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
						viSetFovAspectAndSize(
								g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
								g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);
					}

					lvRecordDistanceMoved();
				}
			}

			gdl = lvRender(gdl);
			func000034e0(&gdl);

			if (debug0f11ed70() >= 2) {
				gdl = debugRenderSomething(gdl);
			}

			gDPFullSync(gdl++);
			gSPEndDisplayList(gdl++);
		}

		if (var8005d9c8) {
			gfxSwapBuffers();
			func0000a044();
		}

		rdpCreateTask(gdlstart, gdl, 0, array);
		var8005d9cc++;
		func00012a8c();
		func0f16cf94();
		func00009aa0(0x10000);
	}
}
#else
GLOBAL_ASM(
glabel mainTick
/*     e8ec:	27bdff68 */ 	addiu	$sp,$sp,-152
/*     e8f0:	3c0f8006 */ 	lui	$t7,0x8006
/*     e8f4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     e8f8:	afb10018 */ 	sw	$s1,0x18($sp)
/*     e8fc:	afb00014 */ 	sw	$s0,0x14($sp)
/*     e900:	25eff69c */ 	addiu	$t7,$t7,-2404
/*     e904:	8de10000 */ 	lw	$at,0x0($t7)
/*     e908:	8de80004 */ 	lw	$t0,0x4($t7)
/*     e90c:	27ae0070 */ 	addiu	$t6,$sp,0x70
/*     e910:	adc10000 */ 	sw	$at,0x0($t6)
/*     e914:	adc80004 */ 	sw	$t0,0x4($t6)
/*     e918:	8de8000c */ 	lw	$t0,0xc($t7)
/*     e91c:	8de10008 */ 	lw	$at,0x8($t7)
/*     e920:	3c098006 */ 	lui	$t1,0x8006
/*     e924:	adc8000c */ 	sw	$t0,0xc($t6)
/*     e928:	adc10008 */ 	sw	$at,0x8($t6)
/*     e92c:	8de10010 */ 	lw	$at,0x10($t7)
/*     e930:	8de80014 */ 	lw	$t0,0x14($t7)
/*     e934:	3c0a8006 */ 	lui	$t2,0x8006
/*     e938:	adc10010 */ 	sw	$at,0x10($t6)
/*     e93c:	adc80014 */ 	sw	$t0,0x14($t6)
/*     e940:	8de8001c */ 	lw	$t0,0x1c($t7)
/*     e944:	8de10018 */ 	lw	$at,0x18($t7)
/*     e948:	adc8001c */ 	sw	$t0,0x1c($t6)
/*     e94c:	adc10018 */ 	sw	$at,0x18($t6)
/*     e950:	8d29f674 */ 	lw	$t1,-0x98c($t1)
/*     e954:	05230148 */ 	bgezl	$t1,.NB0000ee78
/*     e958:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     e95c:	8d4af2ec */ 	lw	$t2,-0xd14($t2)
/*     e960:	2d410002 */ 	sltiu	$at,$t2,0x2
/*     e964:	50200144 */ 	beqzl	$at,.NB0000ee78
/*     e968:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     e96c:	0fc59f11 */ 	jal	frametimeCalculate
/*     e970:	00000000 */ 	sll	$zero,$zero,0x0
/*     e974:	0c00270e */ 	jal	func00009a98
/*     e978:	00000000 */ 	sll	$zero,$zero,0x0
/*     e97c:	0c00270c */ 	jal	func00009a90
/*     e980:	00000000 */ 	sll	$zero,$zero,0x0
/*     e984:	0c002710 */ 	jal	func00009aa0
/*     e988:	3c040002 */ 	lui	$a0,0x2
/*     e98c:	0c000dbe */ 	jal	func000034d8
/*     e990:	00000000 */ 	sll	$zero,$zero,0x0
/*     e994:	0c005477 */ 	jal	joyDebugJoy
/*     e998:	00000000 */ 	sll	$zero,$zero,0x0
/*     e99c:	0c00073e */ 	jal	func00001b28
/*     e9a0:	00002025 */ 	or	$a0,$zero,$zero
/*     e9a4:	3c048006 */ 	lui	$a0,0x8006
/*     e9a8:	8c84f2e8 */ 	lw	$a0,-0xd18($a0)
/*     e9ac:	1080011c */ 	beqz	$a0,.NB0000ee20
/*     e9b0:	00000000 */ 	sll	$zero,$zero,0x0
/*     e9b4:	0fc5889f */ 	jal	gfxGetMasterDisplayList
/*     e9b8:	00000000 */ 	sll	$zero,$zero,0x0
/*     e9bc:	244b0008 */ 	addiu	$t3,$v0,0x8
/*     e9c0:	afa20090 */ 	sw	$v0,0x90($sp)
/*     e9c4:	afab0094 */ 	sw	$t3,0x94($sp)
/*     e9c8:	3c0cf510 */ 	lui	$t4,0xf510
/*     e9cc:	3c0d0700 */ 	lui	$t5,0x700
/*     e9d0:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*     e9d4:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*     e9d8:	8fb90094 */ 	lw	$t9,0x94($sp)
/*     e9dc:	3c0ef500 */ 	lui	$t6,0xf500
/*     e9e0:	35ce0100 */ 	ori	$t6,$t6,0x100
/*     e9e4:	27380008 */ 	addiu	$t8,$t9,0x8
/*     e9e8:	afb80094 */ 	sw	$t8,0x94($sp)
/*     e9ec:	3c0f0600 */ 	lui	$t7,0x600
/*     e9f0:	3c088006 */ 	lui	$t0,0x8006
/*     e9f4:	af2f0004 */ 	sw	$t7,0x4($t9)
/*     e9f8:	af2e0000 */ 	sw	$t6,0x0($t9)
/*     e9fc:	8d08f678 */ 	lw	$t0,-0x988($t0)
/*     ea00:	15000006 */ 	bnez	$t0,.NB0000ea1c
/*     ea04:	00002025 */ 	or	$a0,$zero,$zero
/*     ea08:	0c005790 */ 	jal	joyGetButtons
/*     ea0c:	2405000c */ 	addiu	$a1,$zero,0xc
/*     ea10:	2401000c */ 	addiu	$at,$zero,0xc
/*     ea14:	1441001a */ 	bne	$v0,$at,.NB0000ea80
/*     ea18:	00002025 */ 	or	$a0,$zero,$zero
.NB0000ea1c:
/*     ea1c:	0c00573c */ 	jal	joyGetStickX
/*     ea20:	00002025 */ 	or	$a0,$zero,$zero
/*     ea24:	00028e00 */ 	sll	$s1,$v0,0x18
/*     ea28:	00114e03 */ 	sra	$t1,$s1,0x18
/*     ea2c:	01208825 */ 	or	$s1,$t1,$zero
/*     ea30:	0c005766 */ 	jal	joyGetStickY
/*     ea34:	00002025 */ 	or	$a0,$zero,$zero
/*     ea38:	a3a2003b */ 	sb	$v0,0x3b($sp)
/*     ea3c:	00002025 */ 	or	$a0,$zero,$zero
/*     ea40:	0c005790 */ 	jal	joyGetButtons
/*     ea44:	3405ffff */ 	dli	$a1,0xffff
/*     ea48:	3050ffff */ 	andi	$s0,$v0,0xffff
/*     ea4c:	00002025 */ 	or	$a0,$zero,$zero
/*     ea50:	0c0057c0 */ 	jal	joyGetButtonsPressedThisFrame
/*     ea54:	3405ffff */ 	dli	$a1,0xffff
/*     ea58:	00112600 */ 	sll	$a0,$s1,0x18
/*     ea5c:	00045603 */ 	sra	$t2,$a0,0x18
/*     ea60:	01402025 */ 	or	$a0,$t2,$zero
/*     ea64:	83a5003b */ 	lb	$a1,0x3b($sp)
/*     ea68:	3206ffff */ 	andi	$a2,$s0,0xffff
/*     ea6c:	0fc4651b */ 	jal	debug0f11946cnb
/*     ea70:	3047ffff */ 	andi	$a3,$v0,0xffff
/*     ea74:	3c018006 */ 	lui	$at,0x8006
/*     ea78:	10000021 */ 	beqz	$zero,.NB0000eb00
/*     ea7c:	ac22f678 */ 	sw	$v0,-0x988($at)
.NB0000ea80:
/*     ea80:	0c005790 */ 	jal	joyGetButtons
/*     ea84:	24051000 */ 	addiu	$a1,$zero,0x1000
/*     ea88:	14400005 */ 	bnez	$v0,.NB0000eaa0
/*     ea8c:	3c0b8008 */ 	lui	$t3,0x8008
/*     ea90:	8d6b86f4 */ 	lw	$t3,-0x790c($t3)
/*     ea94:	3c018008 */ 	lui	$at,0x8008
/*     ea98:	10000019 */ 	beqz	$zero,.NB0000eb00
/*     ea9c:	ac2b86f0 */ 	sw	$t3,-0x7910($at)
.NB0000eaa0:
/*     eaa0:	0c00573c */ 	jal	joyGetStickX
/*     eaa4:	00002025 */ 	or	$a0,$zero,$zero
/*     eaa8:	00028e00 */ 	sll	$s1,$v0,0x18
/*     eaac:	00116603 */ 	sra	$t4,$s1,0x18
/*     eab0:	01808825 */ 	or	$s1,$t4,$zero
/*     eab4:	0c005766 */ 	jal	joyGetStickY
/*     eab8:	00002025 */ 	or	$a0,$zero,$zero
/*     eabc:	a3a2003b */ 	sb	$v0,0x3b($sp)
/*     eac0:	00002025 */ 	or	$a0,$zero,$zero
/*     eac4:	0c005790 */ 	jal	joyGetButtons
/*     eac8:	3405ffff */ 	dli	$a1,0xffff
/*     eacc:	3050ffff */ 	andi	$s0,$v0,0xffff
/*     ead0:	00002025 */ 	or	$a0,$zero,$zero
/*     ead4:	0c0057c0 */ 	jal	joyGetButtonsPressedThisFrame
/*     ead8:	3405ffff */ 	dli	$a1,0xffff
/*     eadc:	00112600 */ 	sll	$a0,$s1,0x18
/*     eae0:	00046e03 */ 	sra	$t5,$a0,0x18
/*     eae4:	01a02025 */ 	or	$a0,$t5,$zero
/*     eae8:	83a5003b */ 	lb	$a1,0x3b($sp)
/*     eaec:	3206ffff */ 	andi	$a2,$s0,0xffff
/*     eaf0:	0fc4651b */ 	jal	debug0f11946cnb
/*     eaf4:	3047ffff */ 	andi	$a3,$v0,0xffff
/*     eaf8:	3c018006 */ 	lui	$at,0x8006
/*     eafc:	ac22f678 */ 	sw	$v0,-0x988($at)
.NB0000eb00:
/*     eb00:	0fc599c9 */ 	jal	lvTick
/*     eb04:	00000000 */ 	sll	$zero,$zero,0x0
/*     eb08:	0fc48e7f */ 	jal	randomisePlayerOrder
/*     eb0c:	00000000 */ 	sll	$zero,$zero,0x0
/*     eb10:	3c198006 */ 	lui	$t9,0x8006
/*     eb14:	8f39f2d4 */ 	lw	$t9,-0xd2c($t9)
/*     eb18:	3c10800a */ 	lui	$s0,0x800a
/*     eb1c:	2610e6c0 */ 	addiu	$s0,$s0,-6464
/*     eb20:	2b21005a */ 	slti	$at,$t9,0x5a
/*     eb24:	10200055 */ 	beqz	$at,.NB0000ec7c
/*     eb28:	00000000 */ 	sll	$zero,$zero,0x0
/*     eb2c:	8e18006c */ 	lw	$t8,0x6c($s0)
/*     eb30:	00008825 */ 	or	$s1,$zero,$zero
/*     eb34:	00002825 */ 	or	$a1,$zero,$zero
/*     eb38:	13000003 */ 	beqz	$t8,.NB0000eb48
/*     eb3c:	00002025 */ 	or	$a0,$zero,$zero
/*     eb40:	10000001 */ 	beqz	$zero,.NB0000eb48
/*     eb44:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0000eb48:
/*     eb48:	8e0e0068 */ 	lw	$t6,0x68($s0)
/*     eb4c:	00001825 */ 	or	$v1,$zero,$zero
/*     eb50:	00001025 */ 	or	$v0,$zero,$zero
/*     eb54:	11c00003 */ 	beqz	$t6,.NB0000eb64
/*     eb58:	00000000 */ 	sll	$zero,$zero,0x0
/*     eb5c:	10000001 */ 	beqz	$zero,.NB0000eb64
/*     eb60:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0000eb64:
/*     eb64:	8e0f0064 */ 	lw	$t7,0x64($s0)
/*     eb68:	11e00003 */ 	beqz	$t7,.NB0000eb78
/*     eb6c:	00000000 */ 	sll	$zero,$zero,0x0
/*     eb70:	10000001 */ 	beqz	$zero,.NB0000eb78
/*     eb74:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0000eb78:
/*     eb78:	8e080070 */ 	lw	$t0,0x70($s0)
/*     eb7c:	11000003 */ 	beqz	$t0,.NB0000eb8c
/*     eb80:	00000000 */ 	sll	$zero,$zero,0x0
/*     eb84:	10000001 */ 	beqz	$zero,.NB0000eb8c
/*     eb88:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0000eb8c:
/*     eb8c:	00434821 */ 	addu	$t1,$v0,$v1
/*     eb90:	01245021 */ 	addu	$t2,$t1,$a0
/*     eb94:	01455821 */ 	addu	$t3,$t2,$a1
/*     eb98:	19600038 */ 	blez	$t3,.NB0000ec7c
/*     eb9c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000eba0:
/*     eba0:	0fc48ec2 */ 	jal	getPlayerByOrderNum
/*     eba4:	02202025 */ 	or	$a0,$s1,$zero
/*     eba8:	0fc48d5b */ 	jal	setCurrentPlayerNum
/*     ebac:	00402025 */ 	or	$a0,$v0,$zero
/*     ebb0:	3c0c8006 */ 	lui	$t4,0x8006
/*     ebb4:	8d8cf2d4 */ 	lw	$t4,-0xd2c($t4)
/*     ebb8:	2401004e */ 	addiu	$at,$zero,0x4e
/*     ebbc:	55810006 */ 	bnel	$t4,$at,.NB0000ebd8
/*     ebc0:	8e020284 */ 	lw	$v0,0x284($s0)
/*     ebc4:	0fc06a36 */ 	jal	titleIsKeepingMode
/*     ebc8:	00000000 */ 	sll	$zero,$zero,0x0
/*     ebcc:	1440000b */ 	bnez	$v0,.NB0000ebfc
/*     ebd0:	00000000 */ 	sll	$zero,$zero,0x0
/*     ebd4:	8e020284 */ 	lw	$v0,0x284($s0)
.NB0000ebd8:
/*     ebd8:	84440634 */ 	lh	$a0,0x634($v0)
/*     ebdc:	0c002f9f */ 	jal	viSetViewPosition
/*     ebe0:	84450636 */ 	lh	$a1,0x636($v0)
/*     ebe4:	8e020284 */ 	lw	$v0,0x284($s0)
/*     ebe8:	c44c1854 */ 	lwc1	$f12,0x1854($v0)
/*     ebec:	c44e1858 */ 	lwc1	$f14,0x1858($v0)
/*     ebf0:	84460630 */ 	lh	$a2,0x630($v0)
/*     ebf4:	0c002feb */ 	jal	viSetFovAspectAndSize
/*     ebf8:	84470632 */ 	lh	$a3,0x632($v0)
.NB0000ebfc:
/*     ebfc:	0fc59e2f */ 	jal	lvRecordDistanceMoved
/*     ec00:	00000000 */ 	sll	$zero,$zero,0x0
/*     ec04:	8e0d006c */ 	lw	$t5,0x6c($s0)
/*     ec08:	26310001 */ 	addiu	$s1,$s1,0x1
/*     ec0c:	00002825 */ 	or	$a1,$zero,$zero
/*     ec10:	11a00003 */ 	beqz	$t5,.NB0000ec20
/*     ec14:	00002025 */ 	or	$a0,$zero,$zero
/*     ec18:	10000001 */ 	beqz	$zero,.NB0000ec20
/*     ec1c:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0000ec20:
/*     ec20:	8e190068 */ 	lw	$t9,0x68($s0)
/*     ec24:	00001825 */ 	or	$v1,$zero,$zero
/*     ec28:	00001025 */ 	or	$v0,$zero,$zero
/*     ec2c:	13200003 */ 	beqz	$t9,.NB0000ec3c
/*     ec30:	00000000 */ 	sll	$zero,$zero,0x0
/*     ec34:	10000001 */ 	beqz	$zero,.NB0000ec3c
/*     ec38:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0000ec3c:
/*     ec3c:	8e180064 */ 	lw	$t8,0x64($s0)
/*     ec40:	13000003 */ 	beqz	$t8,.NB0000ec50
/*     ec44:	00000000 */ 	sll	$zero,$zero,0x0
/*     ec48:	10000001 */ 	beqz	$zero,.NB0000ec50
/*     ec4c:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0000ec50:
/*     ec50:	8e0e0070 */ 	lw	$t6,0x70($s0)
/*     ec54:	11c00003 */ 	beqz	$t6,.NB0000ec64
/*     ec58:	00000000 */ 	sll	$zero,$zero,0x0
/*     ec5c:	10000001 */ 	beqz	$zero,.NB0000ec64
/*     ec60:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0000ec64:
/*     ec64:	00437821 */ 	addu	$t7,$v0,$v1
/*     ec68:	01e44021 */ 	addu	$t0,$t7,$a0
/*     ec6c:	01054821 */ 	addu	$t1,$t0,$a1
/*     ec70:	0229082a */ 	slt	$at,$s1,$t1
/*     ec74:	1420ffca */ 	bnez	$at,.NB0000eba0
/*     ec78:	00000000 */ 	sll	$zero,$zero,0x0
.NB0000ec7c:
/*     ec7c:	0fc59012 */ 	jal	lvRender
/*     ec80:	8fa40094 */ 	lw	$a0,0x94($sp)
/*     ec84:	afa20094 */ 	sw	$v0,0x94($sp)
/*     ec88:	0c000dc0 */ 	jal	func000034e0
/*     ec8c:	27a40094 */ 	addiu	$a0,$sp,0x94
/*     ec90:	0fc4665b */ 	jal	debug0f11996cnb
/*     ec94:	00000000 */ 	sll	$zero,$zero,0x0
/*     ec98:	1040003e */ 	beqz	$v0,.NB0000ed94
/*     ec9c:	2407ffff */ 	addiu	$a3,$zero,-1
/*     eca0:	8faa0094 */ 	lw	$t2,0x94($sp)
/*     eca4:	3c0ce700 */ 	lui	$t4,0xe700
/*     eca8:	3c18ba00 */ 	lui	$t8,0xba00
/*     ecac:	254b0008 */ 	addiu	$t3,$t2,0x8
/*     ecb0:	afab0094 */ 	sw	$t3,0x94($sp)
/*     ecb4:	ad400004 */ 	sw	$zero,0x4($t2)
/*     ecb8:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*     ecbc:	8fad0094 */ 	lw	$t5,0x94($sp)
/*     ecc0:	37181402 */ 	ori	$t8,$t8,0x1402
/*     ecc4:	3c08f900 */ 	lui	$t0,0xf900
/*     ecc8:	25b90008 */ 	addiu	$t9,$t5,0x8
/*     eccc:	afb90094 */ 	sw	$t9,0x94($sp)
/*     ecd0:	ada00004 */ 	sw	$zero,0x4($t5)
/*     ecd4:	adb80000 */ 	sw	$t8,0x0($t5)
/*     ecd8:	8fae0094 */ 	lw	$t6,0x94($sp)
/*     ecdc:	3c0bee00 */ 	lui	$t3,0xee00
/*     ece0:	3c19b900 */ 	lui	$t9,0xb900
/*     ece4:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*     ece8:	afaf0094 */ 	sw	$t7,0x94($sp)
/*     ecec:	adc70004 */ 	sw	$a3,0x4($t6)
/*     ecf0:	adc80000 */ 	sw	$t0,0x0($t6)
/*     ecf4:	8fa90094 */ 	lw	$t1,0x94($sp)
/*     ecf8:	37390201 */ 	ori	$t9,$t9,0x201
/*     ecfc:	24180004 */ 	addiu	$t8,$zero,0x4
/*     ed00:	252a0008 */ 	addiu	$t2,$t1,0x8
/*     ed04:	afaa0094 */ 	sw	$t2,0x94($sp)
/*     ed08:	ad270004 */ 	sw	$a3,0x4($t1)
/*     ed0c:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*     ed10:	8fac0094 */ 	lw	$t4,0x94($sp)
/*     ed14:	3c090fa5 */ 	lui	$t1,0xfa5
/*     ed18:	3c08b900 */ 	lui	$t0,0xb900
/*     ed1c:	258d0008 */ 	addiu	$t5,$t4,0x8
/*     ed20:	afad0094 */ 	sw	$t5,0x94($sp)
/*     ed24:	ad980004 */ 	sw	$t8,0x4($t4)
/*     ed28:	ad990000 */ 	sw	$t9,0x0($t4)
/*     ed2c:	8fae0094 */ 	lw	$t6,0x94($sp)
/*     ed30:	3508031d */ 	ori	$t0,$t0,0x31d
/*     ed34:	35294040 */ 	ori	$t1,$t1,0x4040
/*     ed38:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*     ed3c:	afaf0094 */ 	sw	$t7,0x94($sp)
/*     ed40:	adc90004 */ 	sw	$t1,0x4($t6)
/*     ed44:	adc80000 */ 	sw	$t0,0x0($t6)
/*     ed48:	8fb00094 */ 	lw	$s0,0x94($sp)
/*     ed4c:	260b0008 */ 	addiu	$t3,$s0,0x8
/*     ed50:	0c002f77 */ 	jal	viGetWidth
/*     ed54:	afab0094 */ 	sw	$t3,0x94($sp)
/*     ed58:	00028c00 */ 	sll	$s1,$v0,0x10
/*     ed5c:	00116403 */ 	sra	$t4,$s1,0x10
/*     ed60:	0c002f7b */ 	jal	viGetHeight
/*     ed64:	01808825 */ 	or	$s1,$t4,$zero
/*     ed68:	244dffff */ 	addiu	$t5,$v0,-1
/*     ed6c:	31b903ff */ 	andi	$t9,$t5,0x3ff
/*     ed70:	262fffff */ 	addiu	$t7,$s1,-1
/*     ed74:	31e803ff */ 	andi	$t0,$t7,0x3ff
/*     ed78:	0019c080 */ 	sll	$t8,$t9,0x2
/*     ed7c:	3c01f600 */ 	lui	$at,0xf600
/*     ed80:	03017025 */ 	or	$t6,$t8,$at
/*     ed84:	00084b80 */ 	sll	$t1,$t0,0xe
/*     ed88:	01c95025 */ 	or	$t2,$t6,$t1
/*     ed8c:	ae0a0000 */ 	sw	$t2,0x0($s0)
/*     ed90:	ae000004 */ 	sw	$zero,0x4($s0)
.NB0000ed94:
/*     ed94:	0c0051a1 */ 	jal	func00013814
/*     ed98:	8fa40094 */ 	lw	$a0,0x94($sp)
/*     ed9c:	0c0050b5 */ 	jal	func000142d4nb
/*     eda0:	afa20094 */ 	sw	$v0,0x94($sp)
/*     eda4:	0fc4663a */ 	jal	debug0f1198e8nb
/*     eda8:	00000000 */ 	sll	$zero,$zero,0x0
/*     edac:	28410002 */ 	slti	$at,$v0,0x2
/*     edb0:	14200004 */ 	bnez	$at,.NB0000edc4
/*     edb4:	00000000 */ 	sll	$zero,$zero,0x0
/*     edb8:	0c002712 */ 	jal	debugRenderSomething
/*     edbc:	8fa40094 */ 	lw	$a0,0x94($sp)
/*     edc0:	afa20094 */ 	sw	$v0,0x94($sp)
.NB0000edc4:
/*     edc4:	3c0b8006 */ 	lui	$t3,0x8006
/*     edc8:	8d6bf678 */ 	lw	$t3,-0x988($t3)
/*     edcc:	51600007 */ 	beqzl	$t3,.NB0000edec
/*     edd0:	8fac0094 */ 	lw	$t4,0x94($sp)
/*     edd4:	0fc4649c */ 	jal	debug0f119270nb
/*     edd8:	00000000 */ 	sll	$zero,$zero,0x0
/*     eddc:	0fc4633d */ 	jal	debug0f118cf4nb
/*     ede0:	8fa40094 */ 	lw	$a0,0x94($sp)
/*     ede4:	afa20094 */ 	sw	$v0,0x94($sp)
/*     ede8:	8fac0094 */ 	lw	$t4,0x94($sp)
.NB0000edec:
/*     edec:	3c19e900 */ 	lui	$t9,0xe900
/*     edf0:	3c08b800 */ 	lui	$t0,0xb800
/*     edf4:	258d0008 */ 	addiu	$t5,$t4,0x8
/*     edf8:	afad0094 */ 	sw	$t5,0x94($sp)
/*     edfc:	ad800004 */ 	sw	$zero,0x4($t4)
/*     ee00:	ad990000 */ 	sw	$t9,0x0($t4)
/*     ee04:	8fb80094 */ 	lw	$t8,0x94($sp)
/*     ee08:	3c048006 */ 	lui	$a0,0x8006
/*     ee0c:	270f0008 */ 	addiu	$t7,$t8,0x8
/*     ee10:	afaf0094 */ 	sw	$t7,0x94($sp)
/*     ee14:	af000004 */ 	sw	$zero,0x4($t8)
/*     ee18:	af080000 */ 	sw	$t0,0x0($t8)
/*     ee1c:	8c84f2e8 */ 	lw	$a0,-0xd18($a0)
.NB0000ee20:
/*     ee20:	50800006 */ 	beqzl	$a0,.NB0000ee3c
/*     ee24:	8fa40090 */ 	lw	$a0,0x90($sp)
/*     ee28:	0fc588d6 */ 	jal	gfxSwapBuffers
/*     ee2c:	00000000 */ 	sll	$zero,$zero,0x0
/*     ee30:	0c002871 */ 	jal	func0000a044
/*     ee34:	00000000 */ 	sll	$zero,$zero,0x0
/*     ee38:	8fa40090 */ 	lw	$a0,0x90($sp)
.NB0000ee3c:
/*     ee3c:	8fa50094 */ 	lw	$a1,0x94($sp)
/*     ee40:	00003025 */ 	or	$a2,$zero,$zero
/*     ee44:	0c00c411 */ 	jal	rdpCreateTask
/*     ee48:	27a70070 */ 	addiu	$a3,$sp,0x70
/*     ee4c:	3c028006 */ 	lui	$v0,0x8006
/*     ee50:	2442f2ec */ 	addiu	$v0,$v0,-3348
/*     ee54:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*     ee58:	25c90001 */ 	addiu	$t1,$t6,0x1
/*     ee5c:	0c004c0a */ 	jal	func00012a8c
/*     ee60:	ac490000 */ 	sw	$t1,0x0($v0)
/*     ee64:	0fc59f51 */ 	jal	func0f16cf94
/*     ee68:	00000000 */ 	sll	$zero,$zero,0x0
/*     ee6c:	0c002710 */ 	jal	func00009aa0
/*     ee70:	3c040001 */ 	lui	$a0,0x1
/*     ee74:	8fbf001c */ 	lw	$ra,0x1c($sp)
.NB0000ee78:
/*     ee78:	8fb00014 */ 	lw	$s0,0x14($sp)
/*     ee7c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*     ee80:	03e00008 */ 	jr	$ra
/*     ee84:	27bd0098 */ 	addiu	$sp,$sp,0x98
);
#endif

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
				soloPushCoopModeEndscreen();
			}

			setCurrentPlayerNum(prevplayernum);
			musicStartForMenu();
		} else if (g_Vars.antiplayernum >= 0) {
			s32 prevplayernum = g_Vars.currentplayernum;
			s32 i;

			for (i = 0; i < PLAYERCOUNT(); i++) {
				setCurrentPlayerNum(i);
				soloPushAntiModeEndscreen();
			}

			setCurrentPlayerNum(prevplayernum);
			musicStartForMenu();
		} else if (g_Vars.normmplayerisrunning) {
			mpEndMatch();
		} else {
			endscreenPrepare();
			musicStartForMenu();
		}
	}

	g_MainIsEndscreen = true;
}

void mainSetStageNum(s32 stagenum)
{
#if VERSION >= VERSION_NTSC_1_0
	pak0f11c6d0();
#endif

	g_MainStageNum = stagenum;
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
