#include <ultra64.h>
#include "game/chr/chraicommands.h"
#include "game/game_0f09f0.h"
#include "game/game_0fd660.h"
#include "game/game_102240.h"
#include "game/cheats.h"
#include "game/game_107fb0.h"
#include "game/endscreen.h"
#include "game/utils.h"
#include "game/game_177e00.h"
#include "game/game_1a3340.h"
#include "gvars/gvars.h"
#include "game/data/data_000000.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "stagesetup.h"
#include "types.h"

u32 var80070500 = 0x00000000;
u32 var80070504 = 0x00000000;
u32 var80070508 = 0x00000000;
u32 var8007050c = 0x00000000;
u32 var80070510 = 0x00000000;
u32 var80070514 = 0x00000000;
u32 var80070518 = 0x00000000;
u32 var8007051c = 0x00000000;
u32 var80070520 = 0x00000000;
s32 var80070524 = 0x00000000;
u32 var80070528 = 0x00000000;
u32 var8007052c = 0x00000000;
u32 var80070530 = 0x00000000;
u32 var80070534 = 0x00000000;
u32 var80070538 = 0x00000001;
u32 var8007053c = 0x00000003;
u32 var80070540 = 0x00000000;
u32 var80070544 = 0x00000000;
u32 var80070548 = 0x00000000;
u32 var8007054c = 0x00000000;
u32 var80070550 = 0x00000000;
u32 var80070554 = 0x00000000;
u32 var80070558 = 0x00000000;
u32 var8007055c = 0x00000000;
u32 var80070560 = 0x00000000;
u32 var80070564 = 0x00000000;
u32 var80070568 = 0x00000000;
u32 var8007056c = 0x00000000;
u32 var80070570 = 0x00000000;
u32 var80070574 = 0x00000320;
u32 var80070578 = 0x00001b58;
u32 var8007057c = 0x00002328;
u32 var80070580 = 0x00000018;
u32 var80070584 = 0x00000006;
u32 var80070588 = 0x00000000;
u32 var8007058c = 0x00000000;
u32 var80070590 = 0x00000000;
u32 var80070594 = 0x00000000;
u32 var80070598 = 0x00000000;
u32 var8007059c = 0x00000000;
u32 var800705a0 = 0x00000000;
u32 var800705a4 = 0x00000000;
bool var800705a8 = false;
u32 var800705ac = 0x00000000;
u32 var800705b0 = 0x00000000;
u32 var800705b4 = 0x00000000;
u32 var800705b8 = 0x00000000;
u32 var800705bc = 0x00000000;

struct var800705c0 var800705c0[] = {
	{ 320, 220, 320, 1,                1, 220, 0,  180, 20, 136, 42  },
	{ 640, 220, 640, 0.5,              1, 220, 0,  180, 20, 136, 42  },
	{ 320, 480, 320, 2,                2, 440, 20, 360, 60, 272, 104 },
	{ 440, 330, 440, 1,                1, 330, 0,  330, 0,  330, 0   },
	{ 440, 240, 440, 0.72727274894714, 1, 220, 0,  180, 0,  136, 0   },
	{ 400, 300, 400, 1,                2, 300, 0,  300, 0,  300, 0   },
};

s32 g_HiResActive = 0;
bool g_HiResEnabled = false;
u32 var800706d0 = 0x00000000;
u32 var800706d4 = 0x00000000;
u32 var800706d8 = 0x00000000;
u32 var800706dc = 0x00000000;
u32 var800706e0 = 0x00000000;
u32 var800706e4 = 0xbf800000;
u32 var800706e8 = 0x00000000;
u32 var800706ec = 0x3f800000;
u32 var800706f0 = 0x00000000;
u32 var800706f4 = 0x00000000;
u32 var800706f8 = 0x3f800000;
u32 var800706fc = 0x00000000;
u32 var80070700 = 0x00000000;
u32 var80070704 = 0x3f800000;
u32 var80070708 = 0x00000000;
u32 var8007070c = 0x00000000;
u32 var80070710 = 0x00000000;
u32 var80070714 = 0x00000000;
u32 var80070718 = 0x00000000;
u32 var8007071c = 0x00000000;
u32 var80070720 = 0x00000000;
u32 var80070724 = 0x00000000;
u32 var80070728 = 0x3f800000;
u32 var8007072c = 1;
u32 var80070730 = 0xffffffff;
u32 var80070734 = 0xffffffff;
u32 var80070738 = 0;
u32 var8007073c = 0;
struct gecreditsdata *g_CurrentGeCreditsData = NULL;
u32 var80070744 = 0;
u32 var80070748 = 0;
u32 var8007074c = 0;

// 80070750
bool g_PlayersWithControl[] = {
	true, true, true, true
};

bool g_PlayerInvincible = false;
s32 var80070764 = 0x00000000;

s16 g_DeathAnimations[] = {
	ANIM_DEATH_001A,
	ANIM_DEATH_001C,
	ANIM_DEATH_0020,
	ANIM_DEATH_0021,
	ANIM_DEATH_0022,
	ANIM_DEATH_0023,
	ANIM_DEATH_0024,
	ANIM_DEATH_0025,
	0,
};

u32 g_NumDeathAnimations = 0;

