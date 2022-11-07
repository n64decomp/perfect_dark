#include <ultra64.h>
#include "constants.h"
#include "game/chraction.h"
#include "game/dlights.h"
#include "game/footstep.h"
#include "game/game_006900.h"
#include "game/chr.h"
#include "game/body.h"
#include "game/prop.h"
#include "game/propsnd.h"
#include "game/atan2f.h"
#include "game/acosfasinf.h"
#include "game/bondgun.h"
#include "game/gunfx.h"
#include "game/game_0b0fd0.h"
#include "game/modelmgr.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/player.h"
#include "game/inv.h"
#include "game/playermgr.h"
#include "game/explosions.h"
#include "game/sparks.h"
#include "game/bg.h"
#include "game/game_1531a0.h"
#include "game/stagetable.h"
#include "game/env.h"
#include "game/lv.h"
#include "game/bot.h"
#include "game/botact.h"
#include "game/botcmd.h"
#include "game/botinv.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "game/padhalllv.h"
#include "game/pak.h"
#include "game/propobj.h"
#include "game/wallhit.h"
#include "game/mpstats.h"
#include "bss.h"
#include "lib/joy.h"
#include "lib/lib_17ce0.h"
#include "lib/main.h"
#include "lib/model.h"
#include "lib/snd.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/collision.h"
#include "lib/vi.h"
#include "data.h"
#include "types.h"

s32 g_RecentQuipsPlayed[5];
u32 var8009cd84;
u32 var8009cd88;
u32 var8009cd8c;
u32 var8009cd90;
u32 var8009cd94;
u8 g_RecentQuipsIndex;

f32 g_EnemyAccuracyScale = 1;
f32 g_PlayerDamageRxScale = 1;
f32 g_PlayerDamageTxScale = 1;
f32 g_AttackWalkDurationScale = 1;

#if VERSION >= VERSION_NTSC_1_0
s32 g_NumChrsWithPlayerTarget = 0;
s32 g_NumChrsSeenPlayer = 0;
s32 g_NumChrsSeenPlayerRecently = 0;
#endif

s32 g_NumChrsSeenPlayerRecently2 = 0;

struct animtablerow g_DeathAnimsHumanLfoot[] = {
	{ ANIM_DEATH_0020, 0, -1, 0.5, 0, 26, -1 },
	{ 0,      0,  0, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsHumanLshin[] = {
	{ ANIM_DEATH_0020, 0, -1, 0.5, 0, 26, -1 },
	{ 0,      0,  0, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsHumanLthigh[] = {
	{ ANIM_DEATH_0020, 0, -1, 0.5, 1, 26, -1  },
	{ ANIM_DEATH_STOMACH_LONG, 1, -1, 0.5, 0, -1, -1  },
	{ ANIM_0092, 1, -1, 0.4, 0, 42, 103 },
	{ ANIM_0258, 1, -1, 0.5, 0, 43, 100 },
	{ 0,      0, 0,  0.5, 0, -1, -1  },
};

struct animtablerow g_DeathAnimsHumanRfoot[] = {
	{ ANIM_DEATH_0020, 1, -1, 0.5, 0, 26, -1 },
	{ 0,      0, 0,  0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsHumanRshin[] = {
	{ ANIM_DEATH_0020, 1, -1, 0.5, 0, 26, -1 },
	{ 0,      0, 0,  0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsHumanRthigh[] = {
	{ ANIM_DEATH_0020, 1, -1, 0.5, 1, 26, -1  },
	{ ANIM_DEATH_STOMACH_LONG, 0, -1, 0.5, 0, -1, -1  },
	{ ANIM_0092, 0, -1, 0.4, 0, 42, 103 },
	{ ANIM_0258, 0, -1, 0.5, 0, 43, 100 },
	{ 0,      0, 0,  0.5, 0, -1, -1  },
};

struct animtablerow g_DeathAnimsHumanPelvis[] = {
	{ ANIM_DEATH_001A, 0, -1, 0.5, 0, 55,  39  },
	{ ANIM_DEATH_001A, 1, -1, 0.5, 0, 55,  39  },
	{ ANIM_DEATH_001C, 0, -1, 0.5, 1, 29,  -1  },
	{ ANIM_DEATH_001C, 1, -1, 0.5, 1, 29,  -1  },
	{ ANIM_DEATH_0021, 0, -1, 0.5, 0, 97,  64  },
	{ ANIM_DEATH_0021, 1, -1, 0.5, 0, 97,  64  },
	{ ANIM_DEATH_0023, 0, -1, 0.5, 0, 31,  -1  },
	{ ANIM_DEATH_0023, 1, -1, 0.5, 0, 31,  -1  },
	{ ANIM_DEATH_0024, 0, -1, 0.5, 0, 36,  -1  },
	{ ANIM_DEATH_0024, 1, -1, 0.5, 0, 36,  -1  },
	{ ANIM_DEATH_0025, 0, -1, 0.5, 0, 28,  -1  },
	{ ANIM_DEATH_0025, 1, -1, 0.5, 0, 28,  -1  },
	{ ANIM_0090, 0, -1, 0.6, 0, 157, 234 },
	{ ANIM_0090, 1, -1, 0.6, 0, 157, 234 },
	{ ANIM_0091, 0, -1, 0.6, 0, 75,  265 },
	{ ANIM_0091, 1, -1, 0.6, 0, 75,  265 },
	{ ANIM_0250, 0, -1, 0.5, 0, 65,  105 },
	{ ANIM_0250, 1, -1, 0.5, 0, 65,  105 },
	{ 0,      0, -1, 0.5, 0, -1,  -1  },
};

struct animtablerow g_DeathAnimsHumanHead[] = {
	{ ANIM_DEATH_001A, 0, -1, 0.5, 0, 55,  39  },
	{ ANIM_DEATH_001A, 1, -1, 0.5, 0, 55,  39  },
	{ ANIM_DEATH_001C, 0, -1, 0.5, 1, 29,  -1  },
	{ ANIM_DEATH_001C, 1, -1, 0.5, 1, 29,  -1  },
	{ ANIM_DEATH_0020, 0, -1, 0.5, 1, 26,  -1  },
	{ ANIM_DEATH_0020, 1, -1, 0.5, 1, 26,  -1  },
	{ ANIM_DEATH_0021, 0, -1, 0.5, 0, 97,  64  },
	{ ANIM_DEATH_0021, 1, -1, 0.5, 0, 97,  64  },
	{ ANIM_DEATH_0022, 0, -1, 0.5, 0, 94,  66  },
	{ ANIM_DEATH_0022, 1, -1, 0.5, 0, 94,  66  },
	{ ANIM_DEATH_0023, 0, -1, 0.5, 0, 31,  -1  },
	{ ANIM_DEATH_0023, 1, -1, 0.5, 0, 31,  -1  },
	{ ANIM_DEATH_0024, 0, -1, 0.5, 0, 36,  -1  },
	{ ANIM_DEATH_0024, 1, -1, 0.5, 0, 36,  -1  },
	{ ANIM_DEATH_0025, 0, -1, 0.5, 0, 28,  -1  },
	{ ANIM_DEATH_0025, 1, -1, 0.5, 0, 28,  -1  },
	{ ANIM_0038, 0, -1, 0.5, 0, -1,  -1  },
	{ ANIM_0038, 1, -1, 0.5, 0, -1,  -1  },
	{ ANIM_0251, 0, -1, 0.5, 0, 132, 201 },
	{ ANIM_0251, 1, -1, 0.5, 0, 132, 201 },
	{ ANIM_0252, 0, -1, 0.5, 0, 83,  150 },
	{ ANIM_0252, 1, -1, 0.5, 0, 83,  150 },
	{ ANIM_0256, 0, -1, 0.5, 0, 63,  -1  },
	{ ANIM_0256, 1, -1, 0.5, 0, 63,  -1  },
	{ 0,      0, -1, 0.5, 0, -1,  -1  },
};

struct animtablerow g_DeathAnimsHumanLhand[] = {
	{ ANIM_DEATH_0020, 0, -1, 0.5, 0, 26, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsHumanForearm[] = {
	{ ANIM_DEATH_0020, 0, -1, 0.5, 0, 26, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsHumanLbicep[] = {
	{ ANIM_DEATH_0020, 0, -1, 0.5,  1, 26, -1 },
	{ ANIM_008F, 1, -1, 0.45, 1, 52, -1 },
	{ 0,      0, -1, 0.5,  0, -1, -1 },
};

struct animtablerow g_DeathAnimsHumanRhand[] = {
	{ ANIM_DEATH_0020, 1, -1, 0.5, 0, 26, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsHumanRforearm[] = {
	{ ANIM_DEATH_0020, 1, -1, 0.5, 0, 26, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsHumanRbicep[] = {
	{ ANIM_DEATH_0020, 1, -1, 0.5,  1, 26, -1 },
	{ ANIM_008F, 0, -1, 0.45, 1, 52, -1 },
	{ 0,      0, -1, 0.5,  0, -1, -1 },
};

struct animtablerow g_DeathAnimsHumanTorso[] = {
	{ ANIM_DEATH_001A, 0, -1, 0.5, 0, 55, 39 },
	{ ANIM_DEATH_001A, 1, -1, 0.5, 0, 55, 39 },
	{ ANIM_DEATH_001C, 0, -1, 0.5, 1, 29, -1 },
	{ ANIM_DEATH_001C, 1, -1, 0.5, 1, 29, -1 },
	{ ANIM_DEATH_0020, 0, -1, 0.5, 1, 26, -1 },
	{ ANIM_DEATH_0020, 1, -1, 0.5, 1, 26, -1 },
	{ ANIM_DEATH_0021, 0, -1, 0.5, 0, 97, 64 },
	{ ANIM_DEATH_0021, 1, -1, 0.5, 0, 97, 64 },
	{ ANIM_DEATH_0022, 0, -1, 0.5, 0, 94, 66 },
	{ ANIM_DEATH_0022, 1, -1, 0.5, 0, 94, 66 },
	{ ANIM_DEATH_0023, 0, -1, 0.5, 0, 31, -1 },
	{ ANIM_DEATH_0023, 1, -1, 0.5, 0, 31, -1 },
	{ ANIM_DEATH_0024, 0, -1, 0.5, 0, 36, -1 },
	{ ANIM_DEATH_0024, 1, -1, 0.5, 0, 36, -1 },
	{ ANIM_DEATH_0025, 0, -1, 0.5, 0, 28, -1 },
	{ ANIM_DEATH_0025, 1, -1, 0.5, 0, 28, -1 },
	{ ANIM_024E, 0, -1, 0.4, 0, 60, -1 },
	{ ANIM_024E, 1, -1, 0.4, 0, 60, -1 },
	{ ANIM_024F, 0, -1, 0.5, 0, 49, 80 },
	{ ANIM_024F, 1, -1, 0.5, 0, 49, 80 },
	{ ANIM_0253, 0, -1, 0.5, 1, 22, -1 },
	{ ANIM_0253, 1, -1, 0.5, 1, 22, -1 },
	{ ANIM_0254, 0, -1, 0.5, 0, 52, 75 },
	{ ANIM_0254, 1, -1, 0.5, 0, 52, 75 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsHumanGun[] = {
	{ ANIM_DEATH_001A, 0, -1, 0.5, 0, 55, 39 },
	{ ANIM_DEATH_001A, 1, -1, 0.5, 0, 55, 39 },
	{ ANIM_DEATH_001C, 0, -1, 0.5, 1, 29, -1 },
	{ ANIM_DEATH_001C, 1, -1, 0.5, 1, 29, -1 },
	{ ANIM_DEATH_0021, 0, -1, 0.5, 0, 97, 64 },
	{ ANIM_DEATH_0021, 1, -1, 0.5, 0, 97, 64 },
	{ ANIM_DEATH_0022, 0, -1, 0.5, 0, 94, 66 },
	{ ANIM_DEATH_0022, 1, -1, 0.5, 0, 94, 66 },
	{ ANIM_DEATH_0023, 0, -1, 0.5, 0, 31, -1 },
	{ ANIM_DEATH_0023, 1, -1, 0.5, 0, 31, -1 },
	{ ANIM_DEATH_0024, 0, -1, 0.5, 0, 36, -1 },
	{ ANIM_DEATH_0024, 1, -1, 0.5, 0, 36, -1 },
	{ ANIM_DEATH_0025, 0, -1, 0.5, 0, 28, -1 },
	{ ANIM_DEATH_0025, 1, -1, 0.5, 0, 28, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_AnimTableHumanSlumped[] = {
	{ ANIM_0019, 0, -1, 0.5, 0, 67, 54 },
	{ ANIM_0019, 1, -1, 0.5, 0, 67, 54 },
	{ ANIM_0257, 0, -1, 0.5, 0, 15, 80 },
	{ ANIM_0257, 1, -1, 0.5, 0, 15, 80 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsHumanLfoot[] = {
	{ ANIM_0014, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_0015, 1, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsHumanLshin[] = {
	{ ANIM_0014, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_0015, 1, -1, 0.5, 0, -1, -1 },
	{ ANIM_00BC, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_00BD, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsHumanLthigh[] = {
	{ ANIM_0014, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_0015, 1, -1, 0.5, 0, -1, -1 },
	{ ANIM_DEATH_STOMACH_LONG, 1, 20, 0.4, 0, -1, -1 },
	{ ANIM_00BA, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsHumanRfoot[] = {
	{ ANIM_0015, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_0014, 1, -1, 0.5, 0, -1, -1 },
	{ ANIM_0236, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsHumanRshin[] = {
	{ ANIM_0015, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_0014, 1, -1, 0.5, 0, -1, -1 },
	{ ANIM_00BE, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsHumanRthigh[] = {
	{ ANIM_0015, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_0014, 1, -1, 0.5, 0, -1, -1 },
	{ ANIM_DEATH_STOMACH_LONG, 0, 20, 0.4, 0, -1, -1 },
	{ ANIM_00BF, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsHumanPelvis[] = {
	{ ANIM_DEATH_0022, 0, 20, 0.5,  0, -1, -1 },
	{ ANIM_DEATH_0022, 1, 20, 0.5,  0, -1, -1 },
	{ ANIM_DEATH_001A, 0, 15, 0.5,  0, -1, -1 },
	{ ANIM_DEATH_001A, 1, 15, 0.5,  0, -1, -1 },
	{ ANIM_DEATH_0023, 0, 10, 0.25, 0, -1, -1 },
	{ ANIM_DEATH_0023, 1, 10, 0.25, 0, -1, -1 },
	{ ANIM_00DA, 0, -1, 0.5,  0, -1, -1 },
	{ ANIM_00F4, 0, -1, 0.5,  0, -1, -1 },
	{ 0,      0, -1, 0.5,  0, -1, -1 },
};

struct animtablerow g_InjuryAnimsHumanHead[] = {
	{ ANIM_DEATH_0022, 0, 20, 0.5, 0, -1, -1 },
	{ ANIM_DEATH_0022, 1, 20, 0.5, 0, -1, -1 },
	{ ANIM_DEATH_001A, 0, 15, 0.5, 0, -1, -1 },
	{ ANIM_DEATH_001A, 1, 15, 0.5, 0, -1, -1 },
	{ ANIM_00F8, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_00FB, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_0101, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_0113, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsHumanLhand[] = {
	{ ANIM_0012, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_0013, 1, -1, 0.5, 0, -1, -1 },
	{ ANIM_00B8, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsHumanForearm[] = {
	{ ANIM_0010, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_0011, 1, -1, 0.5, 0, -1, -1 },
	{ ANIM_00B4, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_021B, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsHumanLbicep[] = {
	{ ANIM_000E, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_000F, 1, -1, 0.5, 0, -1, -1 },
	{ ANIM_DEATH_0022, 0, 20, 0.5, 0, -1, -1 },
	{ ANIM_00B0, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_00B1, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_021C, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_00B5, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsHumanRhand[] = {
	{ ANIM_0013, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_0012, 1, -1, 0.5, 0, -1, -1 },
	{ ANIM_00B9, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsHumanRforearm[] = {
	{ ANIM_0011, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_0010, 1, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsHumanRbicep[] = {
	{ ANIM_000F, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_000E, 1, -1, 0.5, 0, -1, -1 },
	{ ANIM_DEATH_0022, 1, 20, 0.5, 0, -1, -1 },
	{ ANIM_0190, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_00B2, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_00B3, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_00B6, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_00B7, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsHumanTorso[] = {
	{ ANIM_DEATH_0022, 0, 20, 0.5, 0, -1, -1 },
	{ ANIM_DEATH_0022, 1, 20, 0.5, 0, -1, -1 },
	{ ANIM_DEATH_001A, 0, 15, 0.5, 0, -1, -1 },
	{ ANIM_DEATH_001A, 1, 15, 0.5, 0, -1, -1 },
	{ ANIM_0114, 1, -1, 0.5, 0, -1, -1 },
	{ ANIM_0130, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsHumanGun[] = {
	{ ANIM_DEATH_0022, 0, 20, 0.5, 0, -1, -1 },
	{ ANIM_DEATH_0022, 1, 20, 0.5, 0, -1, -1 },
	{ ANIM_DEATH_001A, 0, 15, 0.5, 0, -1, -1 },
	{ ANIM_DEATH_001A, 1, 15, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsSkedarLfoot[] = {
	{ ANIM_0337, 1, -1, 0.5, 0, -1, -1 },
	{ ANIM_033C, 1, -1, 0.5, 0, -1, -1 },
	{ ANIM_033B, 1, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsSkedarLshin[] = {
	{ ANIM_0337, 1, -1, 0.5, 0, -1, -1 },
	{ ANIM_033C, 1, -1, 0.5, 0, -1, -1 },
	{ ANIM_033B, 1, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsSkedarLthigh[] = {
	{ ANIM_0337, 1, -1, 0.5, 0, -1, -1 },
	{ ANIM_033C, 1, -1, 0.5, 0, -1, -1 },
	{ ANIM_033B, 1, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsSkedarRfoot[] = {
	{ ANIM_0337, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_033C, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_033B, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsSkedarRshin[] = {
	{ ANIM_0337, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_033C, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_033B, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsSkedarRthigh[] = {
	{ ANIM_0337, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_033C, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_033B, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsSkedarPelvis[] = {
	{ ANIM_0336, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsSkedarHead[] = {
	{ ANIM_0339, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_0338, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_033A, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsSkedarLhand[] = {
	{ ANIM_0336, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_033D, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsSkedarLforearm[] = {
	{ ANIM_0336, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_033D, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsSkedarLbicep[] = {
	{ ANIM_0336, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_033D, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsSkedarRhand[] = {
	{ ANIM_0336, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_033D, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsSkedarRforearm[] = {
	{ ANIM_0336, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_033D, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsSkedarRbicep[] = {
	{ ANIM_0336, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_033D, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsSkedarTorso[] = {
	{ ANIM_0336, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_033D, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsSkedarGun[] = {
	{ ANIM_0336, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_033D, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_DeathAnimsSkedarTail[] = {
	{ ANIM_0336, 0, -1, 0.5, 0, -1, -1 },
	{ ANIM_033D, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsSkedarLfoot[] = {
	{ ANIM_038E, 0, -1, 1,   0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsSkedarLshin[] = {
	{ ANIM_0390, 0, -1, 0.9, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsSkedarLthigh[] = {
	{ ANIM_0390, 0, -1, 0.9, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsSkedarRfoot[] = {
	{ ANIM_038E, 1, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsSkedarRshin[] = {
	{ ANIM_0390, 1, -1, 0.9, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsSkedarRthigh[] = {
	{ ANIM_0390, 1, -1, 0.9, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsSkedarPelvis[] = {
	{ ANIM_038C, 0, -1, 0.9, 0, -1, -1 },
	{ ANIM_038C, 1, -1, 0.9, 0, -1, -1 },
	{ ANIM_0341, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsSkedarHead[] = {
	{ ANIM_0341, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsSkedarLhand[] = {
	{ ANIM_0343, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsSkedarLforearm[] = {
	{ ANIM_038B, 0, -1, 0.9, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsSkedarLbicep[] = {
	{ ANIM_038B, 0, -1, 0.9, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsSkedarRhand[] = {
	{ ANIM_0343, 1, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsSkedarRforearm[] = {
	{ ANIM_038B, 1, -1, 0.9, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsSkedarRbicep[] = {
	{ ANIM_038B, 1, -1, 0.9, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsSkedarTorso[] = {
	{ ANIM_038C, 0, -1, 0.9, 0, -1, -1 },
	{ ANIM_038C, 1, -1, 0.9, 0, -1, -1 },
	{ ANIM_0341, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsSkedarGun[] = {
	{ ANIM_0343, 0, -1, 0.5, 0, -1, -1 },
	{ 0,      0, -1, 0.5, 0, -1, -1 },
};

struct animtablerow g_InjuryAnimsSkedarTail[] = {
	{ ANIM_0341, 0, -1, 0.5, 0, -1,  -1  },
	{ 0,      0, -1, 0.5, 0, -1,  -1  },
};

struct animtablerow g_SpecialDieAnims[] = {
	{ ANIM_SPECIALDIE_FALLBACK,    0, -1, 0.5, 0, 149, 175 },
	{ ANIM_SPECIALDIE_ROLL1,       0, -1, 0.5, 0, 115, 152 },
	{ ANIM_SPECIALDIE_ROLL2,       0, -1, 0.5, 0, 115, 152 },
	{ ANIM_SPECIALDIE_ROLL3,       0, -1, 0.5, 0, 115, 152 },
	{ ANIM_SPECIALDIE_OVERRAILING, 0, -1, 0.5, 0, 83,  99  },
	{ ANIM_022B,                   0, -1, 0.5, 0, 0,   0   },
	{ ANIM_022C,                   0, -1, 0.5, 0, 0,   0   },
	{ ANIM_022D,                   0, -1, 0.5, 0, 0,   0   },
	{ ANIM_022E,                   0, -1, 0.5, 0, 0,   0   },
	{ 0,                           0, -1, 0.5, 0, -1,  -1  },
};

struct animtable g_AnimTablesHuman[] = {
	{ 0,                NULL,                      NULL,                       0, 0 },
	{ HITPART_LFOOT,    g_DeathAnimsHumanLfoot,    g_InjuryAnimsHumanLfoot,    0, 0 },
	{ HITPART_LSHIN,    g_DeathAnimsHumanLshin,    g_InjuryAnimsHumanLshin,    0, 0 },
	{ HITPART_LTHIGH,   g_DeathAnimsHumanLthigh,   g_InjuryAnimsHumanLthigh,   0, 0 },
	{ HITPART_RFOOT,    g_DeathAnimsHumanRfoot,    g_InjuryAnimsHumanRfoot,    0, 0 },
	{ HITPART_RSHIN,    g_DeathAnimsHumanRshin,    g_InjuryAnimsHumanRshin,    0, 0 },
	{ HITPART_RTHIGH,   g_DeathAnimsHumanRthigh,   g_InjuryAnimsHumanRthigh,   0, 0 },
	{ HITPART_PELVIS,   g_DeathAnimsHumanPelvis,   g_InjuryAnimsHumanPelvis,   0, 0 },
	{ HITPART_HEAD,     g_DeathAnimsHumanHead,     g_InjuryAnimsHumanHead,     0, 0 },
	{ HITPART_LHAND,    g_DeathAnimsHumanLhand,    g_InjuryAnimsHumanLhand,    0, 0 },
	{ HITPART_LFOREARM, g_DeathAnimsHumanForearm,  g_InjuryAnimsHumanForearm,  0, 0 },
	{ HITPART_LBICEP,   g_DeathAnimsHumanLbicep,   g_InjuryAnimsHumanLbicep,   0, 0 },
	{ HITPART_RHAND,    g_DeathAnimsHumanRhand,    g_InjuryAnimsHumanRhand,    0, 0 },
	{ HITPART_RFOREARM, g_DeathAnimsHumanRforearm, g_InjuryAnimsHumanRforearm, 0, 0 },
	{ HITPART_RBICEP,   g_DeathAnimsHumanRbicep,   g_InjuryAnimsHumanRbicep,   0, 0 },
	{ HITPART_TORSO,    g_DeathAnimsHumanTorso,    g_InjuryAnimsHumanTorso,    0, 0 },
	{ HITPART_GUN,      g_DeathAnimsHumanGun,      g_InjuryAnimsHumanGun,      0, 0 },
	{ HITPART_HAT,      NULL,                      NULL,                       0, 0 },
	{ -1,               NULL,                      NULL,                       0, 0 },
};

struct animtable g_AnimTablesSkedar[] = {
	{ 0,                NULL,                       NULL,                        0, 0 },
	{ HITPART_LFOOT,    g_DeathAnimsSkedarLfoot,    g_InjuryAnimsSkedarLfoot,    0, 0 },
	{ HITPART_LSHIN,    g_DeathAnimsSkedarLshin,    g_InjuryAnimsSkedarLshin,    0, 0 },
	{ HITPART_LTHIGH,   g_DeathAnimsSkedarLthigh,   g_InjuryAnimsSkedarLthigh,   0, 0 },
	{ HITPART_RFOOT,    g_DeathAnimsSkedarRfoot,    g_InjuryAnimsSkedarRfoot,    0, 0 },
	{ HITPART_RSHIN,    g_DeathAnimsSkedarRshin,    g_InjuryAnimsSkedarRshin,    0, 0 },
	{ HITPART_RTHIGH,   g_DeathAnimsSkedarRthigh,   g_InjuryAnimsSkedarRthigh,   0, 0 },
	{ HITPART_PELVIS,   g_DeathAnimsSkedarPelvis,   g_InjuryAnimsSkedarPelvis,   0, 0 },
	{ HITPART_HEAD,     g_DeathAnimsSkedarHead,     g_InjuryAnimsSkedarHead,     0, 0 },
	{ HITPART_LHAND,    g_DeathAnimsSkedarLhand,    g_InjuryAnimsSkedarLhand,    0, 0 },
	{ HITPART_LFOREARM, g_DeathAnimsSkedarLforearm, g_InjuryAnimsSkedarLforearm, 0, 0 },
	{ HITPART_LBICEP,   g_DeathAnimsSkedarLbicep,   g_InjuryAnimsSkedarLbicep,   0, 0 },
	{ HITPART_RHAND,    g_DeathAnimsSkedarRhand,    g_InjuryAnimsSkedarRhand,    0, 0 },
	{ HITPART_RFOREARM, g_DeathAnimsSkedarRforearm, g_InjuryAnimsSkedarRforearm, 0, 0 },
	{ HITPART_RBICEP,   g_DeathAnimsSkedarRbicep,   g_InjuryAnimsSkedarRbicep,   0, 0 },
	{ HITPART_TORSO,    g_DeathAnimsSkedarTorso,    g_InjuryAnimsSkedarTorso,    0, 0 },
	{ HITPART_GUN,      g_DeathAnimsSkedarGun,      g_InjuryAnimsSkedarGun,      0, 0 },
	{ HITPART_HAT,      g_DeathAnimsSkedarHead,     g_InjuryAnimsSkedarHead,     0, 0 },
	{ HITPART_TAIL,     g_DeathAnimsSkedarTail,     g_InjuryAnimsSkedarTail,     0, 0 },
	{ -1,               NULL,                       NULL,                        0, 0 },
};

struct animtable g_AnimTablesDrCaroll[] = {
	{ 0,  NULL, NULL, 0, 0 },
	{ -1, NULL, NULL, 0, 0 },
};

struct animtable g_AnimTablesEyespy[] = {
	{ 0,  NULL, NULL, 0, 0 },
	{ -1, NULL, NULL, 0, 0 },
};

struct animtable g_AnimTablesRobot[] = {
	{ 0,  NULL, NULL, 0, 0 },
	{ -1, NULL, NULL, 0, 0 },
};

struct animtable *g_AnimTablesByRace[] = {
	g_AnimTablesHuman,
	g_AnimTablesSkedar,
	g_AnimTablesDrCaroll,
	g_AnimTablesEyespy,
	g_AnimTablesRobot,
};

/**
 * A yeet anim is an animation config for a chr being launched by an explosion.
 */
struct yeetanim {
	s16 animnum;
	bool flip;
	f32 speed;
	f32 startframe;
	f32 thudframe;
	f32 endframe;
};

struct yeetanim g_YeetAnimsHuman[] = {
	/* 0*/ { ANIM_0082, 0, 0.5, 9,  29, -1 },
	/* 1*/ { ANIM_0082, 1, 0.5, 9,  29, -1 },
	/* 2*/ { ANIM_008A, 0, 0.5, 11, 31, -1 },
	/* 3*/ { ANIM_008A, 1, 0.5, 11, 31, -1 },
	/* 4*/ { ANIM_0089, 0, 0.5, 6,  27, -1 },
	/* 5*/ { ANIM_0089, 1, 0.5, 6,  27, -1 },
	/* 6*/ { ANIM_008C, 0, 0.5, 29, 48, -1 },
	/* 7*/ { ANIM_008C, 1, 0.5, 29, 48, -1 },
	/* 8*/ { ANIM_008D, 0, 0.5, 29, 49, -1 },
	/* 9*/ { ANIM_008D, 1, 0.5, 29, 49, -1 },
	/*10*/ { ANIM_008E, 0, 0.5, 19, 42, -1 },
	/*11*/ { ANIM_008E, 1, 0.5, 19, 42, -1 },
	/*12*/ { ANIM_0086, 0, 0.5, 0,  60, -1 },
	/*13*/ { ANIM_0086, 1, 0.5, 0,  60, -1 },
	/*14*/ { ANIM_0087, 0, 0.5, 6,  29, -1 },
	/*15*/ { ANIM_0087, 1, 0.5, 6,  29, -1 },
	/*16*/ { ANIM_0084, 0, 0.5, 8,  25, -1 },
	/*17*/ { ANIM_0084, 1, 0.5, 8,  25, -1 },
	/*18*/ { ANIM_0085, 0, 0.5, 8,  25, -1 },
	/*19*/ { ANIM_0085, 1, 0.5, 8,  25, -1 },
	/*20*/ { ANIM_0088, 0, 0.5, 12, 29, -1 },
	/*21*/ { ANIM_0088, 1, 0.5, 12, 29, -1 },
	/*22*/ { ANIM_008B, 0, 0.5, 22, 41, -1 },
	/*23*/ { ANIM_008B, 1, 0.5, 22, 41, -1 },
	/*24*/ { 0,         0, 0.5, 0,  0,  -1 },
};

s8 g_YeetAnimIndexesHumanAngle0[] = { 0,  1,  2,  3, 4, 5 };
s8 g_YeetAnimIndexesHumanAngle1[] = { 7,  9,  11          };
s8 g_YeetAnimIndexesHumanAngle2[] = { 6,  8,  10          };
s8 g_YeetAnimIndexesHumanAngle3[] = { 12, 15, 0           };
s8 g_YeetAnimIndexesHumanAngle4[] = { 13, 14, 0           };
s8 g_YeetAnimIndexesHumanAngle5[] = { 18, 19, 20, 21      };
s8 g_YeetAnimIndexesHumanAngle6[] = { 16, 22              };
s8 g_YeetAnimIndexesHumanAngle7[] = { 17, 23              };

struct yeetanim g_YeetAnimsSkedar[] = {
	/* 0*/ { ANIM_033F, 0, 0.5, 0, -1, -1 },
	/* 1*/ { ANIM_033F, 0, 0.5, 0, -1, -1 },
	/* 2*/ { ANIM_033F, 0, 0.5, 0, -1, -1 },
	/* 3*/ { ANIM_033F, 0, 0.5, 0, -1, -1 },
	/* 4*/ { ANIM_033F, 0, 0.5, 0, -1, -1 },
	/* 5*/ { ANIM_033F, 0, 0.5, 0, -1, -1 },
	/* 6*/ { ANIM_033F, 0, 0.5, 0, -1, -1 },
	/* 7*/ { ANIM_033F, 0, 0.5, 0, -1, -1 },
	/* 8*/ { 0,         0, 0.5, 0, 0,  -1 },
};

s8 g_YeetAnimIndexesSkedarAngle0[] = { 0 };
s8 g_YeetAnimIndexesSkedarAngle1[] = { 1 };
s8 g_YeetAnimIndexesSkedarAngle2[] = { 2 };
s8 g_YeetAnimIndexesSkedarAngle3[] = { 3 };
s8 g_YeetAnimIndexesSkedarAngle4[] = { 4 };
s8 g_YeetAnimIndexesSkedarAngle5[] = { 7 };
s8 g_YeetAnimIndexesSkedarAngle6[] = { 5 };
s8 g_YeetAnimIndexesSkedarAngle7[] = { 6 };

struct yeetanimindexlist {
	s8 *indexes;
	s32 count;
};

struct yeetanimindexlist g_YeetAnimIndexesByRaceAngle[][8] = {
	{
		{ g_YeetAnimIndexesHumanAngle0, 6 },
		{ g_YeetAnimIndexesHumanAngle1, 3 },
		{ g_YeetAnimIndexesHumanAngle3, 3 },
		{ g_YeetAnimIndexesHumanAngle6, 2 },
		{ g_YeetAnimIndexesHumanAngle5, 4 },
		{ g_YeetAnimIndexesHumanAngle7, 2 },
		{ g_YeetAnimIndexesHumanAngle4, 3 },
		{ g_YeetAnimIndexesHumanAngle2, 3 },
	}, {
		{ g_YeetAnimIndexesSkedarAngle0, 1 },
		{ g_YeetAnimIndexesSkedarAngle1, 1 },
		{ g_YeetAnimIndexesSkedarAngle3, 1 },
		{ g_YeetAnimIndexesSkedarAngle6, 1 },
		{ g_YeetAnimIndexesSkedarAngle5, 1 },
		{ g_YeetAnimIndexesSkedarAngle7, 1 },
		{ g_YeetAnimIndexesSkedarAngle4, 1 },
		{ g_YeetAnimIndexesSkedarAngle2, 1 },
	},
};

struct attackanimconfig var800656c0[] = {
	{ ANIM_0002, 28, 0, 0, 0, -1, 23, 54, -1, -1, 18, 54, 0.87252569198608, -0.52351540327072, 1.0470308065414, -0.34901028871536, 1.6000000238419, 1.7999999523163 },
	{ 0, 0,  0, 0, 0, -1, 0,  0,  0,  0,  0,  0,  0,                0,                 0,               0,                 0,               0               },
};

struct attackanimgroup var80065750 = { var800656c0, 0xffffffff };

struct attackanimconfig var80065758[] = {
	{ ANIM_0032, 37, 0, 0, 0, -1, 30, 81, -1, -1, 25, 81, 0.87252569198608, -0.69802057743073, 0.69802057743073, -0.69802057743073, 1.6000000238419, 1.75 },
	{ ANIM_0003, 27, 0, 0, 0, -1, 22, 61, -1, -1, 17, 61, 0.87252569198608, -0.26175770163536, 0.69802057743073, -0.69802057743073, 2,               1    },
	{ 0, 0,  0, 0, 0, -1, 0,  0,  0,  0,  0,  0,  0,                0,                 0,                0,                 0,               0    },
};

struct attackanimgroup var80065830 = { var80065758, 0xffffffff };

struct attackanimconfig var80065838[] = {
	{ ANIM_0032, 37, 0, 0, 0, -1, 30, 81, -1, -1, 25, 81, 0.87252569198608, -0.69802057743073, 0.69802057743073, -0.69802057743073, 1.6000000238419, 1.75 },
	{ ANIM_0003, 27, 0, 0, 0, -1, 22, 61, -1, -1, 17, 61, 0.87252569198608, -0.26175770163536, 0.69802057743073, -0.69802057743073, 2,               1    },
	{ 0, 0,  0, 0, 0, -1, 0,  0,  0,  0,  0,  0,  0,                0,                 0,                0,                 0,               0    },
};

struct attackanimgroup var80065910 = { var80065838, 0xffffffff };

struct attackanimconfig var80065918[] = {
	{ ANIM_0004, 19, 0, 1.5707963705063, 0, -1, 19, 61, -1, -1, 14, 61, 0.87252569198608, -0.34901028871536, 0.43626284599304, -1.0470308065414, 2.5, 2.5 },
	{ 0, 0,  0, 0,               0, -1, 0,  0,  0,  0,  0,  0,  0,                0,                 0,                0,                0,   0   },
};

struct attackanimgroup var800659a8 = { var80065918, 0xffffffff };

struct attackanimconfig var800659b0[] = {
	{ ANIM_0006, 27, 0, 0, 0, -1, 39, 74, -1, -1, 34, 74, 0.87252569198608, -0.69802057743073, 0.7852731347084, -0.69802057743073, 1.5, 1.5 },
	{ 0, 0,  0, 0, 0, -1, 0,  0,  0,  0,  0,  0,  0,                0,                 0,               0,                 0,   0   },
};

struct attackanimgroup var80065a40 = { var800659b0, 0xffffffff };

struct attackanimconfig var80065a48[] = {
	{ ANIM_034A, 20, 0, 0, 0, -1, 25, 50, -1, -1, 10, 50, 0.34901028871536, -0.34901028871536, 0.52351540327072, -0.52351540327072, 1, 1 },
	{ 0, 0,  0, 0, 0, -1, 0,  0,  0,  0,  0,  0,  0,                0,                 0,                0,                 0, 0 },
};

struct attackanimgroup var80065ad8 = { var80065a48, 0xffffffff };

struct attackanimgroup *g_StandHeavyAttackAnims[][32] = {
	{
		// RACE_HUMAN
		&var80065750, &var80065830, &var80065830, &var80065830,
		&var80065830, &var80065830, &var80065830, &var80065830,
		&var80065830, &var80065830, &var800659a8, &var800659a8,
		&var800659a8, &var800659a8, &var800659a8, &var800659a8,
		&var80065a40, &var80065a40, &var80065a40, &var80065a40,
		&var80065a40, &var80065a40, &var80065910, &var80065910,
		&var80065910, &var80065910, &var80065910, &var80065910,
		&var80065910, &var80065910, &var80065910, &var80065750,
	}, {
		// RACE_SKEDAR
		&var80065ad8, &var80065ad8, &var80065ad8, &var80065ad8,
		&var80065ad8, &var80065ad8, &var80065ad8, &var80065ad8,
		&var80065ad8, &var80065ad8, &var80065ad8, &var80065ad8,
		&var80065ad8, &var80065ad8, &var80065ad8, &var80065ad8,
		&var80065ad8, &var80065ad8, &var80065ad8, &var80065ad8,
		&var80065ad8, &var80065ad8, &var80065ad8, &var80065ad8,
		&var80065ad8, &var80065ad8, &var80065ad8, &var80065ad8,
		&var80065ad8, &var80065ad8, &var80065ad8, &var80065ad8,
	},
};

struct attackanimconfig var80065be0[] = {
	{ ANIM_0041, 26, 0, 0, 12, 140, 58, 92, 60, 79, 20, 120, 0.87252569198608, -0.69802057743073, 0.69802057743073, -0.69802057743073, 0, 0 },
	{ ANIM_0044, 0,  0, 0, 17, 100, 25, 87, 30, 55, 20, 93,  0.87252569198608, -0.69802057743073, 0.69802057743073, -1.0470308065414,  0, 0 },
	{ ANIM_0045, 0,  0, 0, 12, 64,  19, 51, 24, 46, 14, 58,  0.87252569198608, -0.69802057743073, 0.52351540327072, -0.7852731347084,  0, 0 },
	{ ANIM_0046, 22, 0, 0, 4,  69,  22, 49, 22, 33, 8,  58,  0.87252569198608, -0.69802057743073, 0.43626284599304, -0.7852731347084,  0, 0 },
	{ 0, 0,  0, 0, 0,  -1,  0,  0,  0,  0,  0,  0,   0,                0,                 0,                0,                 0, 0 },
};

struct attackanimgroup var80065d48 = { var80065be0, 0xffffffff };

struct attackanimconfig var80065d50[] = {
	{ ANIM_0041, 26, 0, 0, 12, 140, 58, 92, 60, 79, 20, 120, 0.87252569198608, -0.69802057743073, 0.69802057743073, -0.69802057743073, 0, 0 },
	{ ANIM_0046, 22, 0, 0, 4,  69,  22, 49, 22, 33, 8,  58,  0.87252569198608, -0.69802057743073, 0.43626284599304, -0.7852731347084,  0, 0 },
	{ 0, 0,  0, 0, 0,  -1,  0,  0,  0,  0,  0,  0,   0,                0,                 0,                0,                 0, 0 },
};

struct attackanimgroup var80065e28 = { var80065d50, 0xffffffff };

struct attackanimconfig var80065e30[] = {
	{ ANIM_0041, 26, 0, 0,               12, 140, 58, 92, 60, 79, 20, 120, 0.87252569198608, -0.69802057743073, 0.69802057743073, -0.69802057743073, 0, 0 },
	{ ANIM_0046, 22, 0, 0,               4,  69,  22, 49, 22, 33, 8,  58,  0.87252569198608, -0.69802057743073, 0.43626284599304, -0.7852731347084,  0, 0 },
	{ ANIM_0049, 0,  0, 1.5707963705063, 7,  130, 45, 93, 56, 73, 26, 107, 0.87252569198608, -0.69802057743073, 0.34901028871536, -0.52351540327072, 0, 0 },
	{ ANIM_004A, 15, 0, 1.5707963705063, 5,  76,  20, 31, 31, 38, 15, 49,  0.87252569198608, -0.69802057743073, 0.52351540327072, -1.0470308065414,  0, 0 },
	{ 0, 0,  0, 0,               0,  -1,  0,  0,  0,  0,  0,  0,   0,                0,                 0,                0,                 0, 0 },
};

struct attackanimgroup var80065f98 = { var80065e30, 0xffffffff };

struct attackanimconfig var80065fa0[] = {
	{ ANIM_0041, 26, 0, 0,               12, 140, 58, 92,  60, 79, 20, 120, 0.87252569198608, -0.69802057743073, 0.69802057743073, -0.69802057743073, 0, 0 },
	{ ANIM_0046, 22, 0, 0,               4,  69,  22, 49,  22, 33, 8,  58,  0.87252569198608, -0.69802057743073, 0.43626284599304, -0.7852731347084,  0, 0 },
	{ ANIM_0047, 0,  0, 4.7123889923096, 7,  139, 54, 105, 61, 88, 26, 120, 0.87252569198608, -0.69802057743073, 0.69802057743073, -0.61076802015305, 0, 0 },
	{ ANIM_0048, 19, 0, 4.7123889923096, 4,  79,  21, 50,  26, 42, 10, 64,  0.87252569198608, -0.69802057743073, 0.69802057743073, -0.61076802015305, 0, 0 },
	{ 0, 0,  0, 0,               0,  -1,  0,  0,   0,  0,  0,  0,   0,                0,                 0,                0,                 0, 0 },
};

struct attackanimgroup var80066108 = { var80065fa0, 0xffffffff };

struct attackanimconfig var80066110[] = {
	{ ANIM_004A, 19, 0, 1.5707963705063, 5, 76, 20, 31, 31, 38, 15, 49, 0.87252569198608, -0.69802057743073, 0.52351540327072, -1.0470308065414, 0, 0 },
	{ 0, 0,  0, 0,               0, -1, 0,  0,  0,  0,  0,  0,  0,                0,                 0,                0,                0, 0 },
};

struct attackanimgroup var800661a0 = { var80066110, 0xffffffff };

struct attackanimconfig var800661a8[] = {
	{ ANIM_0048, 19, 0, 4.7123889923096, 4, 79, 21, 50, 26, 42, 10, 64, 0.87252569198608, -0.69802057743073, 0.69802057743073, -0.61076802015305, 0, 0 },
	{ 0, 0,  0, 0,               0, -1, 0,  0,  0,  0,  0,  0,  0,                0,                 0,                0,                 0, 0 },
};

struct attackanimgroup var80066238 = { var800661a8, 0xffffffff };

struct attackanimconfig var80066240[] = {
	{ ANIM_034A, 20, 0, 0, 0, -1, 25, 50, -1, -1, 10, 50, 0.34901028871536, -0.34901028871536, 0.52351540327072, -0.52351540327072, 1, 1 },
	{ 0, 0,  0, 0, 0, -1, 0,  0,  0,  0,  0,  0,  0,                0,                 0,                0,                 0, 0 },
};

struct attackanimgroup var800662d0 = { var80066240, 0xffffffff };

struct attackanimgroup *g_StandLightAttackAnims[][32] = {
	{
		// RACE_HUMAN
		&var80065d48, &var80065d48, &var80065e28, &var80065e28,
		&var80065e28, &var80065f98, &var80065f98, &var80065f98,
		&var80065f98, &var80065f98, &var800661a0, &var800661a0,
		&var800661a0, &var800661a0, &var800661a0, &var800661a0,
		&var80066238, &var80066238, &var80066238, &var80066238,
		&var80066238, &var80066238, &var80066108, &var80066108,
		&var80066108, &var80066108, &var80066108, &var80065e28,
		&var80065e28, &var80065e28, &var80065d48, &var80065d48,
	}, {
		// RACE_SKEDAR
		&var800662d0, &var800662d0, &var800662d0, &var800662d0,
		&var800662d0, &var800662d0, &var800662d0, &var800662d0,
		&var800662d0, &var800662d0, &var800662d0, &var800662d0,
		&var800662d0, &var800662d0, &var800662d0, &var800662d0,
		&var800662d0, &var800662d0, &var800662d0, &var800662d0,
		&var800662d0, &var800662d0, &var800662d0, &var800662d0,
		&var800662d0, &var800662d0, &var800662d0, &var800662d0,
		&var800662d0, &var800662d0, &var800662d0, &var800662d0,
	},
};


struct attackanimconfig var800663d8[] = {
	{ ANIM_007A, 26, 0, 0, 7, 92, 28, 68, -1, -1, 11, 73, 0.87252569198608, -0.69802057743073, 0.69802057743073, -0.69802057743073, 0, 0 },
	{ 0, 0,  0, 0, 0, -1, 0,  0,  0,  0,  0,  0,  0,                0,                 0,                0,                 0, 0 },
};

struct attackanimgroup var80066468 = { var800663d8, 0xffffffff };

struct attackanimconfig var80066470[] = {
	{ ANIM_007B, 26, 0, 1.5707963705063, 9,  112, 38, 87, -1, -1, 19, 98, 0.87252569198608, -0.69802057743073, 0.43626284599304, -0.43626284599304, 0, 0 },
	{ ANIM_007D, 25, 0, 1.5707963705063, 10, 112, 32, 86, -1, -1, 19, 97, 0.87252569198608, -0.69802057743073, 0.43626284599304, -0.43626284599304, 0, 0 },
	{ 0, 0,  0, 0,               0,  -1,  0,  0,  0,  0,  0,  0,  0,                0,                 0,                0,                 0, 0 },
};

struct attackanimgroup var80066548 = { var80066470, 0xffffffff };

struct attackanimconfig var80066550[] = {
	{ ANIM_007C, 39, 0, 4.7123889923096, 22, 127, 44, 102, -1, -1, 28, 112, 0.87252569198608, -0.69802057743073, 0.43626284599304, -0.43626284599304, 0, 0 },
	{ ANIM_007E, 39, 0, 4.7123889923096, 23, 130, 46, 100, -1, -1, 30, 110, 0.87252569198608, -0.69802057743073, 0.43626284599304, -0.43626284599304, 0, 0 },
	{ 0, 0,  0, 0,               0,  -1,  0,  0,   0,  0,  0,  0,   0,                0,                 0,                0,                 0, 0 },
};

struct attackanimgroup var80066628 = { var80066550, 0xffffffff };

struct attackanimconfig var80066630[] = {
	{ ANIM_034A, 20, 0, 0, 0, -1, 25, 50, -1, -1, 10, 50, 0.34901028871536, -0.34901028871536, 0.52351540327072, -0.52351540327072, 1, 1 },
	{ 0, 0,  0, 0, 0, -1, 0,  0,  0,  0,  0,  0,  0,                0,                 0,                0,                 0, 0 },
};

struct attackanimgroup var800666c0 = { var80066630, 0xffffffff };

struct attackanimgroup *g_StandDualAttackAnims[][32] = {
	{
		// RACE_HUMAN
		&var80066468, &var80066468, &var80066468, &var80066468,
		&var80066468, &var80066548, &var80066548, &var80066548,
		&var80066548, &var80066548, &var80066548, &var80066548,
		&var80066548, &var80066548, &var80066548, &var80066548,
		&var80066628, &var80066628, &var80066628, &var80066628,
		&var80066628, &var80066628, &var80066628, &var80066628,
		&var80066628, &var80066628, &var80066628, &var80066468,
		&var80066468, &var80066468, &var80066468, &var80066468,
	}, {
		// RACE_SKEDAR
		&var800666c0, &var800666c0, &var800666c0, &var800666c0,
		&var800666c0, &var800666c0, &var800666c0, &var800666c0,
		&var800666c0, &var800666c0, &var800666c0, &var800666c0,
		&var800666c0, &var800666c0, &var800666c0, &var800666c0,
		&var800666c0, &var800666c0, &var800666c0, &var800666c0,
		&var800666c0, &var800666c0, &var800666c0, &var800666c0,
		&var800666c0, &var800666c0, &var800666c0, &var800666c0,
		&var800666c0, &var800666c0, &var800666c0, &var800666c0,
	},
};

struct attackanimconfig var800667c8[] = {
	{ ANIM_0007, 27, 0, 0, 0, -1, 35, 75, -1, -1, 31, 75, 0.87252569198608, -0.69802057743073, 0.90742671489716, -0.69802057743073, 1.5,             1.5             },
	{ ANIM_KNEEL_TWO_HANDED_GUN, 24, 0, 0, 0, -1, 46, 98, -1, -1, 41, 98, 0.87252569198608, -0.52351540327072, 1.1342834234238,  -0.69802057743073, 1.6000000238419, 1.6000000238419 },
	{ 0, 0,  0, 0, 0, -1, 0,  0,  0,  0,  0,  0,  0,                0,                 0,                0,                 0,               0               },
};

struct attackanimgroup var800668a0 = { var800667c8, 0xffffffff };

struct attackanimconfig var800668a8[] = {
	{ ANIM_0009, 26, 0, 0, 0, -1, 34, 87, -1, -1, 29, 87, 0.87252569198608, -0.52351540327072, 0.69802057743073, -0.95977824926376, 1.6000000238419, 2 },
	{ 0, 0,  0, 0, 0, -1, 0,  0,  0,  0,  0,  0,  0,                0,                 0,                0,                 0,               0 },
};

struct attackanimgroup var80066938 = { var800668a8, 0xffffffff };

struct attackanimconfig var80066940[] = {
	{ ANIM_000A, 28, 0, 0, 0, -1, 36, 88, -1, -1, 31, 88, 0.87252569198608, -0.69802057743073, 0.87252569198608, -0.43626284599304, 1.6000000238419, 1.5 },
	{ 0, 0,  0, 0, 0, -1, 0,  0,  0,  0,  0,  0,  0,                0,                 0,                0,                 0,               0   },
};

struct attackanimgroup var800669d0 = { var80066940, 0xffffffff };

struct attackanimconfig var800669d8[] = {
	{ ANIM_034A, 20, 0, 0, 0, -1, 25, 50, -1, -1, 10, 50, 0.34901028871536, -0.34901028871536, 0.52351540327072, -0.52351540327072, 1, 1 },
	{ 0, 0,  0, 0, 0, -1, 0,  0,  0,  0,  0,  0,  0,                0,                 0,                0,                 0, 0 },
};

struct attackanimgroup var80066a68 = { var800669d8, 0xffffffff };

struct attackanimgroup *g_KneelHeavyAttackAnims[][32] = {
	{
		&var800668a0, &var800668a0, &var800668a0, &var800668a0,
		&var800668a0, &var800668a0, &var800668a0, &var800668a0,
		&var800668a0, &var800668a0, &var80066938, &var80066938,
		&var80066938, &var80066938, &var80066938, &var80066938,
		&var800669d0, &var800669d0, &var800669d0, &var800669d0,
		&var800669d0, &var800669d0, &var800668a0, &var800668a0,
		&var800668a0, &var800668a0, &var800668a0, &var800668a0,
		&var800668a0, &var800668a0, &var800668a0, &var800668a0,
	}, {
		&var80066a68, &var80066a68, &var80066a68, &var80066a68,
		&var80066a68, &var80066a68, &var80066a68, &var80066a68,
		&var80066a68, &var80066a68, &var80066a68, &var80066a68,
		&var80066a68, &var80066a68, &var80066a68, &var80066a68,
		&var80066a68, &var80066a68, &var80066a68, &var80066a68,
		&var80066a68, &var80066a68, &var80066a68, &var80066a68,
		&var80066a68, &var80066a68, &var80066a68, &var80066a68,
		&var80066a68, &var80066a68, &var80066a68, &var80066a68,
	},
};

struct attackanimconfig var80066b70[] = {
	{ ANIM_KNEEL_SHOOT_RIGHT_HAND, 25, 0, 0, 12, 132, 55, 87, 67, 87, 26, 111, 0.87252569198608, -0.69802057743073, 0.61076802015305, -0.7852731347084, 0, 0 },
	{ ANIM_004C, 26, 0, 0, 8,  89,  31, 63, 41, 51, 21, 80,  0.87252569198608, -0.69802057743073, 0.34901028871536, -1.1342834234238, 0, 0 },
	{ 0, 0,  0, 0, 0,  -1,  0,  0,  0,  0,  0,  0,   0,                0,                 0,                0,                0, 0 },
};

struct attackanimgroup var80066c48 = { var80066b70, 0xffffffff };

struct attackanimconfig var80066c50[] = {
	{ ANIM_004F, 47, 0, 1.5707963705063, 7,  128, 33, 86, 47, 74, 23, 106, 0.87252569198608, -0.52351540327072,  0.52351540327072, -0.7852731347084,  0,   0 },
	{ ANIM_0050, 18, 0, 1.5707963705063, 7,  78,  28, 52, 35, 45, 15, 66,  0.87252569198608, -0.087252572178841, 0.69802057743073, -0.7852731347084,  1.5, 1 },
	{ ANIM_0051, 20, 0, 1.5707963705063, 13, 92,  37, 67, 42, 55, 25, 84,  0.87252569198608, -0.52351540327072,  0.34901028871536, -0.69802057743073, 0,   0 },
	{ 0, 0,  0, 0,               0,  -1,  0,  0,  0,  0,  0,  0,   0,                0,                  0,                0,                 0,   0 },
};

struct attackanimgroup var80066d70 = { var80066c50, 0xffffffff };

struct attackanimconfig var80066d78[] = {
	{ ANIM_004D, 28, 0, 4.7123889923096, 15, 124, 38, 97, 60, 84, 20, 106, 0.87252569198608, -0.69802057743073, 0.52351540327072, -0.87252569198608, 0, 0 },
	{ ANIM_004E, 23, 0, 4.7123889923096, 0,  85,  32, 38, 38, 60, 14, 71,  0.87252569198608, -0.69802057743073, 0.61076802015305, -0.95977824926376, 0, 0 },
	{ 0, 0,  0, 0,               0,  -1,  0,  0,  0,  0,  0,  0,   0,                0,                 0,                0,                 0, 0 },
};

struct attackanimgroup var80066e50 = { var80066d78, 0xffffffff };

struct attackanimconfig var80066e58[] = {
	{ ANIM_034A, 20, 0, 0, 0, -1, 25, 50, -1, -1, 10, 50, 0.34901028871536, -0.34901028871536, 0.52351540327072, -0.52351540327072, 1, 1 },
	{ 0, 0,  0, 0, 0, -1, 0,  0,  0,  0,  0,  0,  0,                0,                 0,                0,                 0, 0 },
};

struct attackanimgroup var80066ee8 = { var80066e58, 0xffffffff };

struct attackanimgroup *g_KneelLightAttackAnims[][32] = {
	{
		&var80066c48, &var80066c48, &var80066c48, &var80066c48,
		&var80066c48, &var80066c48, &var80066c48, &var80066c48,
		&var80066c48, &var80066c48, &var80066d70, &var80066d70,
		&var80066d70, &var80066d70, &var80066d70, &var80066d70,
		&var80066e50, &var80066e50, &var80066e50, &var80066e50,
		&var80066e50, &var80066e50, &var80066c48, &var80066c48,
		&var80066c48, &var80066c48, &var80066c48, &var80066c48,
		&var80066c48, &var80066c48, &var80066c48, &var80066c48,
	}, {
		&var80066ee8, &var80066ee8, &var80066ee8, &var80066ee8,
		&var80066ee8, &var80066ee8, &var80066ee8, &var80066ee8,
		&var80066ee8, &var80066ee8, &var80066ee8, &var80066ee8,
		&var80066ee8, &var80066ee8, &var80066ee8, &var80066ee8,
		&var80066ee8, &var80066ee8, &var80066ee8, &var80066ee8,
		&var80066ee8, &var80066ee8, &var80066ee8, &var80066ee8,
		&var80066ee8, &var80066ee8, &var80066ee8, &var80066ee8,
		&var80066ee8, &var80066ee8, &var80066ee8, &var80066ee8,
	},
};

struct attackanimconfig var80066ff0[] = {
	{ ANIM_0074, 22, 0, 0, 10, 111, 34, 87, -1, -1, 17, 104, 0.87252569198608, -0.69802057743073, 0.61076802015305, -0.7852731347084, 0, 0 },
	{ ANIM_0077, 25, 0, 0, 9,  92,  33, 62, -1, -1, 18, 69,  0.87252569198608, -0.69802057743073, 0.61076802015305, -0.7852731347084, 0, 0 },
	{ 0, 0,  0, 0, 0,  -1,  0,  0,  0,  0,  0,  0,   0,                0,                 0,                0,                0, 0 },
};

struct attackanimgroup var800670c8 = { var80066ff0, 0xffffffff };

struct attackanimconfig var800670d0[] = {
	{ ANIM_0075, 28, 0, 1.5707963705063, 15, 108, 34, 73, -1, -1, 17, 93, 0.87252569198608, -0.69802057743073, 0.52351540327072, -0.7852731347084, 0,   0 },
	{ ANIM_0078, 19, 0, 1.5707963705063, 3,  95,  30, 64, -1, -1, 14, 71, 0.87252569198608, -0.69802057743073, 0.52351540327072, -0.7852731347084, 1.5, 1 },
	{ 0, 0,  0, 0,               0,  -1,  0,  0,  0,  0,  0,  0,  0,                0,                 0,                0,                0,   0 },
};

struct attackanimgroup var800671a8 = { var800670d0, 0xffffffff };

struct attackanimconfig var800671b0[] = {
	{ ANIM_0076, 31, 0, 4.7123889923096, 14, 111, 40, 83, -1, -1, 21, 94, 0.87252569198608, -0.69802057743073, 0.52351540327072, -0.7852731347084, 0, 0 },
	{ ANIM_0079, 26, 0, 4.7123889923096, 7,  89,  34, 60, -1, -1, 20, 68, 0.87252569198608, -0.69802057743073, 0.52351540327072, -0.7852731347084, 0, 0 },
	{ 0, 0,  0, 0,               0,  -1,  0,  0,  0,  0,  0,  0,  0,                0,                 0,                0,                0, 0 },
};

struct attackanimgroup var80067288 = { var800671b0, 0xffffffff };

struct attackanimconfig var80067290[] = {
	{ ANIM_034A, 20, 0, 0, 0, -1, 25, 50, -1, -1, 10, 50, 0.34901028871536, -0.34901028871536, 0.52351540327072, -0.52351540327072, 1, 1 },
	{ 0, 0,  0, 0, 0, -1, 0,  0,  0,  0,  0,  0,  0,                0,                 0,                0,                 0, 0 },
};

struct attackanimgroup var80067320 = { var80067290, 0xffffffff };

struct attackanimgroup *g_KneelDualAttackAnims[][32] = {
	{
		&var800670c8, &var800670c8, &var800670c8, &var800670c8,
		&var800670c8, &var800670c8, &var800670c8, &var800670c8,
		&var800670c8, &var800670c8, &var800671a8, &var800671a8,
		&var800671a8, &var800671a8, &var800671a8, &var800671a8,
		&var80067288, &var80067288, &var80067288, &var80067288,
		&var80067288, &var80067288, &var800670c8, &var800670c8,
		&var800670c8, &var800670c8, &var800670c8, &var800670c8,
		&var800670c8, &var800670c8, &var800670c8, &var800670c8,
	}, {
		&var80067320, &var80067320, &var80067320, &var80067320,
		&var80067320, &var80067320, &var80067320, &var80067320,
		&var80067320, &var80067320, &var80067320, &var80067320,
		&var80067320, &var80067320, &var80067320, &var80067320,
		&var80067320, &var80067320, &var80067320, &var80067320,
		&var80067320, &var80067320, &var80067320, &var80067320,
		&var80067320, &var80067320, &var80067320, &var80067320,
		&var80067320, &var80067320, &var80067320, &var80067320,
	},
};

struct attackanimconfig g_RollAttackAnims[] = {
	{ ANIM_000B, 76, 0, 0,               20, -1,  98, 161, -1, -1, 93, 161, 0.87252569198608, -0.52351540327072,  0.69802057743073, -0.69802057743073, 1.7000000476837, 2               },
	{ ANIM_000C, 58, 0, 0,               10, -1,  77, 104, -1, -1, 72, 104, 0.87252569198608, -0.34901028871536,  0.61076802015305, -0.69802057743073, 1.5499999523163, 1.5             },
	{ ANIM_000D, 61, 0, 0,               10, -1,  83, 128, -1, -1, 78, 128, 0.87252569198608, -0.52351540327072,  0.87252569198608, -0.52351540327072, 1.2000000476837, 1.2999999523163 },
	{ ANIM_0027, 63, 0, 0,               10, -1,  73, 114, -1, -1, 68, 114, 0.87252569198608, -0.52351540327072,  0.61076802015305, -0.61076802015305, 1.6499999761581, 1.5             },
	{ ANIM_000B, 76, 0, 0,               20, 76,  98, 161, -1, -1, 93, 161, 0.87252569198608, -0.52351540327072,  0.69802057743073, -0.69802057743073, 1.7000000476837, 2               },
	{ ANIM_000C, 58, 0, 0,               10, 63,  77, 104, -1, -1, 72, 104, 0.87252569198608, -0.34901028871536,  0.61076802015305, -0.69802057743073, 1.5499999523163, 1.5             },
	{ ANIM_000D, 61, 0, 0,               10, 56,  83, 128, -1, -1, 78, 128, 0.87252569198608, -0.52351540327072,  0.87252569198608, -0.52351540327072, 1.2000000476837, 1.2999999523163 },
	{ ANIM_0027, 63, 0, 0,               10, 50,  73, 114, -1, -1, 68, 114, 0.87252569198608, -0.52351540327072,  0.61076802015305, -0.61076802015305, 1.6499999761581, 1.5             },
	{ ANIM_0045, 0,  0, 0,               7,  64,  19, 51,  24, 46, 14, 58,  0.87252569198608, -0.69802057743073,  0.52351540327072, -0.7852731347084,  0,               0               },
	{ ANIM_004A, 0,  0, 1.5707963705063, 14, 76,  26, 31,  31, 38, 15, 49,  0.87252569198608, -0.69802057743073,  0.52351540327072, -1.0470308065414,  0,               0               },
	{ ANIM_004C, 26, 0, 0,               25, 89,  41, 63,  41, 51, 21, 80,  0.87252569198608, -0.69802057743073,  0.34901028871536, -1.1342834234238,  0,               0               },
	{ ANIM_0050, 18, 0, 1.5707963705063, 11, 78,  33, 52,  35, 45, 15, 66,  0.87252569198608, -0.087252572178841, 0.69802057743073, -0.7852731347084,  1.5,             1               },
	{ ANIM_007A, 26, 0, 0,               7,  92,  28, 68,  -1, -1, 11, 73,  0.87252569198608, -0.69802057743073,  0.69802057743073, -0.69802057743073, 0,               0               },
	{ ANIM_007B, 26, 0, 1.5707963705063, 9,  112, 38, 87,  -1, -1, 19, 98,  0.87252569198608, -0.69802057743073,  0.43626284599304, -0.43626284599304, 0,               0               },
	{ ANIM_0074, 22, 0, 0,               10, 11,  34, 87,  -1, -1, 17, 104, 0.87252569198608, -0.69802057743073,  0.61076802015305, -0.7852731347084,  0,               0               },
	{ ANIM_0075, 28, 0, 1.5707963705063, 15, 108, 34, 73,  -1, -1, 17, 93,  0.87252569198608, -0.69802057743073,  0.52351540327072, -0.7852731347084,  0,               0               },
	{ ANIM_007A, 26, 0, 0,               7,  92,  28, 68,  -1, -1, 11, 73,  0.87252569198608, -0.69802057743073,  0.69802057743073, -0.69802057743073, 0,               0               },
	{ ANIM_007D, 25, 0, 1.5707963705063, 10, 112, 32, 86,  -1, -1, 19, 97,  0.87252569198608, -0.69802057743073,  0.43626284599304, -0.43626284599304, 0,               0               },
	{ ANIM_0077, 25, 0, 0,               9,  92,  33, 62,  -1, -1, 18, 69,  0.87252569198608, -0.69802057743073,  0.61076802015305, -0.7852731347084,  0,               0               },
	{ ANIM_0078, 19, 0, 1.5707963705063, 3,  95,  30, 64,  -1, -1, 14, 71,  0.87252569198608, -0.69802057743073,  0.52351540327072, -0.7852731347084,  1.5,             1               },
	{ 0, 0,  0, 0,               0,  -1,  0,  0,   0,  0,  0,  0,   0,                0,                  0,                0,                 0,               0               },
};

struct attackanimconfig g_AttackAnimHeavyWalk       = { ANIM_0030, 0, 0, 0, 0, -1, 0, 0, -1, -1, 0, 0, 0.87252569198608, -0.52351540327072, 0.52351540327072, -0.52351540327072, 1.3999999761581, 1.2999999523163 };
struct attackanimconfig g_AttackAnimHeavyRun        = { ANIM_0031, 0, 0, 0, 0, -1, 0, 0, -1, -1, 0, 0, 0.87252569198608, -0.52351540327072, 0.52351540327072, -0.52351540327072, 1.1000000238419, 1.2000000476837 };
struct attackanimconfig g_AttackAnimLightWalk       = { ANIM_0052, 0, 0, 0, 0, -1, 0, 0, -1, -1, 0, 0, 0.87252569198608, -0.52351540327072, 0.52351540327072, -0.52351540327072, 0,               0               };
struct attackanimconfig g_AttackAnimLightRun        = { ANIM_0055, 0, 0, 0, 0, -1, 0, 0, -1, -1, 0, 0, 0.87252569198608, -0.52351540327072, 0.52351540327072, -0.52351540327072, 0,               0               };
struct attackanimconfig g_AttackAnimDualWalk        = { ANIM_006C, 0, 0, 0, 0, -1, 0, 0, -1, -1, 0, 0, 0.87252569198608, -0.52351540327072, 0.52351540327072, -0.52351540327072, 0,               0               };
struct attackanimconfig g_AttackAnimDualRun         = { ANIM_006E, 0, 0, 0, 0, -1, 0, 0, -1, -1, 0, 0, 0.87252569198608, -0.52351540327072, 0.52351540327072, -0.52351540327072, 0,               0               };
struct attackanimconfig g_AttackAnimDualCrossedWalk = { ANIM_006D, 0, 0, 0, 0, -1, 0, 0, -1, -1, 0, 0, 0.87252569198608, -0.52351540327072, 0.52351540327072, -0.52351540327072, 0,               0               };
struct attackanimconfig g_AttackAnimDualCrossedRun  = { ANIM_006F, 0, 0, 0, 0, -1, 0, 0, -1, -1, 0, 0, 0.87252569198608, -0.52351540327072, 0.52351540327072, -0.52351540327072, 0,               0               };

struct attackanimconfig var80067c50[] = {
	{ ANIM_0057, 0, 0, 1.5707963705063, 0, -1, 0, 0, -1, -1, 0, 0, 0.87252569198608, -0.52351540327072, 0.52351540327072, -0.52351540327072, 0, 0 },
	{ ANIM_0056, 0, 0, 4.7123889923096, 0, -1, 0, 0, -1, -1, 0, 0, 0.87252569198608, -0.52351540327072, 0.52351540327072, -0.52351540327072, 0, 0 },
	{ 0, 0, 0, 0,               0, -1, 0, 0, 0,  0,  0, 0, 0,                0,                 0,                0,                 0, 0 },
};

struct attackanimconfig var80067d28[] = { ANIM_SNIPING_GETDOWN, 0, 0, 0, 0, 236, 0, 0, -1, -1, 0, 0, 0.87252569198608, -0.52351540327072, 0.52351540327072, -0.52351540327072, 0, 0 };

struct attackanimconfig var80067d70[] = {
	{ ANIM_SNIPING_ONGROUND, 0, 0, 0, 0, -1, 0, 0, -1, -1, 0, 0, 0.87252569198608, -0.52351540327072, 0.52351540327072, -0.52351540327072, 0, 0 },
	{ ANIM_SNIPING_GETUP, 0, 0, 0, 0, -1, 0, 0, -1, -1, 0, 0, 0.87252569198608, -0.52351540327072, 0.52351540327072, -0.52351540327072, 0, 0 },
	{ 0, 0, 0, 0, 0, -1, 0, 0, 0,  0,  0, 0, 0,                0,                 0,                0,                 0, 0 },
};

struct attackanimgroup var80067e48 = { var80067d28, 0xffffffff };

struct attackanimgroup *g_LieAttackAnims = &var80067e48;

u32 g_StageFlags = 0;

struct var80067e6c var80067e6c[] = {
	{ ANIM_0028, 0 },
	{ ANIM_RUNNING_TWOHANDGUN, 0 },
	{ ANIM_0029, 0 },
	{ ANIM_006B, 0 },
	{ ANIM_RUNNING_ONEHANDGUN, 0 },
	{ ANIM_005A, 0 },
	{ ANIM_0072, 0 },
	{ ANIM_0073, 0 },
	{ ANIM_005A, 0 },
	{ ANIM_006C, 0 },
	{ ANIM_0030, 0 },
	{ ANIM_0031, 0 },
	{ ANIM_0052, 0 },
	{ ANIM_0055, 0 },
	{ ANIM_006E, 0 },
	{ ANIM_006F, 0 },
	{ ANIM_0057, 0 },
	{ ANIM_0056, 0 },
	{ ANIM_006D, 0 },
	{ ANIM_RUNNING_ONEHANDGUN, 0 },
	{ ANIM_020A, 0 },
	{ ANIM_020D, 0 },
	{ ANIM_01F9, 0 },
	{ ANIM_01F8, 0 },
	{ ANIM_021D, 0 },
	{ ANIM_0016, 0 },
	{ ANIM_0018, 0 },
	{ ANIM_001B, 0 },
	{ ANIM_001D, 0 },
	{ ANIM_001E, 0 },
	{ ANIM_005C, 0 },
	{ ANIM_005D, 0 },
	{ ANIM_005E, 0 },
	{ ANIM_005F, 0 },
	{ -1 },
};

struct var80067e6c var80067f84[] = {
	{ ANIM_0392, 0 },
	{ ANIM_0393, 0 },
	{ ANIM_SKEDAR_RUNNING, 0 },
	{ -1 },
};

struct var80067e6c var80067fa4[] = {
	{ ANIM_015F, 0 },
	{ ANIM_0160, 0 },
	{ -1 },
};

struct var80067e6c var80067fbc[] = {
	{ ANIM_015F, 0 },
	{ -1 },
};

struct var80067e6c var80067fcc[] = {
	{ ANIM_0238, 0 },
	{ -1 },
};

struct var80067e6c *var80067fdc[] = {
	var80067e6c,
	var80067f84,
	var80067fa4,
	var80067fbc,
	var80067fcc,
};

f32 func0f02dff0(s16 animnum)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(var80067fdc); i++) {
		s32 j = 0;
		s16 thisanimnum = var80067fdc[i][j].animnum;

		while (thisanimnum >= 0) {
			if (thisanimnum == animnum) {
				return var80067fdc[i][j].value;
			}

			j++;
			thisanimnum = var80067fdc[i][j].animnum;
		}
	}

	return 1.0f;
}

bool chrGoPosIsWaiting(struct chrdata *chr)
{
	static s16 list1[] = { ANIM_TWO_GUN_HOLD, ANIM_006A, -1 };
	static s16 list2[] = { ANIM_00C0, -1 };
	static s16 list3[] = { ANIM_013E, -1 };
	static s16 list4[] = { ANIM_013E, -1 };
	static s16 list5[] = { ANIM_0237, -1 };
	static s16 *waitableanims[] = { list1, list2, list3, list4, list5 };

	if (chr->aibot) {
		if (chr->actiontype == ACT_STAND
				|| (chr->actiontype == ACT_GOPOS && (chr->act_gopos.flags & GOPOSFLAG_WAITING))) {
			return true;
		}
	} else {
		s16 animnum = modelGetAnimNum(chr->model);
		s32 i;

		for (i = 0; i < ARRAYCOUNT(waitableanims); i++) {
			s16 thisanimnum;
			s32 j;

			for (j = 0; (thisanimnum = waitableanims[i][j]) >= 0; j++) {
				if (thisanimnum == animnum) {
					return true;
				}
			}
		}
	}

	return false;
}

bool weaponIsOneHanded(struct prop *prop)
{
	if (prop) {
		struct weaponobj *weapon = prop->weapon;
		return weaponHasFlag(weapon->weaponnum, WEAPONFLAG_ONEHANDED);
	}

	return false;
}

/**
 * Returns a value between min and max based on the chr's speedrating property.
 *
 * chr->speedrating is between 0 and 100. The result is scaled between min and
 * max accordingly.
 *
 * This function also applies the PD mode reaction speed, but the PD mode
 * reaction speed is always zero because PD doesn't have it in the settings.
 * It was used in GE but disabled in PD.
 */
f32 chrGetRangedSpeed(struct chrdata *chr, f32 min, f32 max)
{
	f32 speedrating = chr->speedrating;

	return (max - min) * speedrating * 0.01f + min;
}

/**
 * Calculates a percentage of how slow the chr is.
 *
 * percentage is expected to be between 0 and 100.
 * chr->speedrating is between 0 and 100.
 *
 * This function takes the difference between the speedrating and the max (100),
 * then multiplies that amount by the given percentage and returns it.
 *
 * For example, if the chr's speedrating is 10 (out of 100) and the given
 * percentage is 50, the result will be 45.
 */
s32 chrGetPercentageOfSlowness(struct chrdata *chr, s32 percentage)
{
	s32 speedrating = chr->speedrating;

	return (100 - speedrating) * percentage / 100;
}

f32 chrGetAttackEntityRelativeAngle(struct chrdata *chr, s32 attackflags, s32 entityid)
{
	f32 angle;
	struct coord pos;
	s16 rooms[8];

	if (attackflags & ATTACKFLAG_AIMFORWARD) {
		return 0;
	}

	if (attackflags & ATTACKFLAG_AIMATDIRECTION) {
		angle = entityid * (M_BADTAU / 65536);
		angle -= chrGetInverseTheta(chr);

		if (angle < 0) {
			angle += M_BADTAU;
		}

		return angle;
	}

	chrGetAttackEntityPos(chr, attackflags, entityid, &pos, rooms);

	return chrGetAngleToPos(chr, &pos);
}

f32 chrGetAttackEntityDistance(struct chrdata *chr, u32 attackflags, s32 entityid)
{
	if (attackflags & ATTACKFLAG_AIMATTARGET) {
		return chrGetDistanceToTarget(chr);
	}

	if (attackflags & ATTACKFLAG_AIMATCHR) {
		return chrGetDistanceToChr(chr, entityid);
	}

	if (attackflags & ATTACKFLAG_AIMATPAD) {
		return chrGetDistanceToPad(chr, entityid);
	}

	return 0;
}

void func0f02e3dc(struct coord *a, struct coord *b,struct coord *c, struct coord *d, struct coord *dst)
{
	f32 value = d->z * (b->x - a->x) - (b->z - a->z) * d->x;

	if (value != 0) {
		f32 tmp = ((b->z - a->z) * (c->x - a->x) + (a->z - c->z) * (b->x - a->x)) / value;
		dst->x = d->x * tmp + c->x;
		dst->y = d->y * tmp + c->y;
		dst->z = d->z * tmp + c->z;
	} else if (d->x == 0 && d->z == 0) {
		dst->x = c->x;
		dst->y = c->y;
		dst->z = c->z;
	} else {
		dst->x = a->x;
		dst->y = a->y;
		dst->z = a->z;
	}
}

void func0f02e4f8(struct coord *arg0, struct coord *arg1, struct coord *dst)
{
	struct coord sp2c;
	struct coord sp20;

#if VERSION >= VERSION_PAL_FINAL
	cdGetEdge(&sp2c, &sp20, 2298, "chr/chraction.c");
#elif VERSION >= VERSION_NTSC_1_0
	cdGetEdge(&sp2c, &sp20, 2298, "chraction.c");
#else
	cdGetEdge(&sp2c, &sp20, 2338, "chraction.c");
#endif

	func0f02e3dc(&sp2c, &sp20, arg0, arg1, dst);
}

void chrChooseStandAnimation(struct chrdata *chr, f32 mergetime)
{
	struct prop *gun1 = chrGetHeldProp(chr, HAND_LEFT);
	struct prop *gun2 = chrGetHeldProp(chr, HAND_RIGHT);
	s32 race = CHRRACE(chr);
	s32 prevanimnum = modelGetAnimNum(chr->model);

	if (chr->actiontype == ACT_GOPOS) {
		chr->act_gopos.flags |= GOPOSFLAG_WAITING;
	}

	if (chr->aibot) {
		return;
	}

	if (race == RACE_HUMAN) {
		if (prevanimnum == ANIM_SNIPING_GETDOWN
				|| prevanimnum == ANIM_SNIPING_GETUP
				|| prevanimnum == ANIM_SNIPING_ONGROUND) {
			modelSetAnimation(chr->model, ANIM_SNIPING_GETUP, chr->model->anim->flip, -1, chrGetRangedSpeed(chr, 0.5, 0.8), 16);
		} else if ((gun1 && gun2) || (!gun1 && !gun2)
				|| weaponIsOneHanded(gun1)
				|| weaponIsOneHanded(gun2)) {
			modelSetAnimation(chr->model, ANIM_006A, random() % 2, 0, 0.25, mergetime);
			modelSetAnimLooping(chr->model, 0, 16);
		} else if (gun2 || gun1) {
			modelSetAnimation(chr->model, ANIM_TWO_GUN_HOLD, gun1 != NULL, 0, 0.25, mergetime);
			modelSetAnimLooping(chr->model, 0, 16);
			modelSetAnimEndFrame(chr->model, 120);
		}
	}
}

void func0f02e9a0(struct chrdata *chr, f32 mergetime)
{
	f32 limit = 127;
	f32 fsleep;

	chrStopFiring(chr);
	chr->actiontype = ACT_STAND;
	chr->act_stand.prestand = false;
	chr->act_stand.flags = 0;
	chr->act_stand.entityid = 0;
	chr->act_stand.reaim = 0;
	chr->act_stand.turning = TURNSTATE_OFF;
	chr->act_stand.checkfacingwall = false;
	chr->act_stand.wallcount = random() % 120 + 180; // 180 to 299
	chr->act_stand.mergetime = mergetime;
	chr->act_stand.playwalkanim = false;

	fsleep = mergetime;

	if (chr->model->anim->playspeed != PALUPF(1.0f)) {
		fsleep *= PALUPF(1.0f) / chr->model->anim->playspeed;
	}

	if (fsleep > limit) {
		fsleep = limit;
	}

	chr->sleep = fsleep;

	chrChooseStandAnimation(chr, mergetime);
	chr->hidden &= ~CHRHFLAG_NEEDANIM;
}

void chrStand(struct chrdata *chr)
{
	s32 race = CHRRACE(chr);
	f32 result;

	chrStopFiring(chr);
	func0f02e9a0(chr, 16);
}

void func0f02ed28(struct chrdata *chr, f32 mergetime)
{
	func0f02e9a0(chr, mergetime);

	chr->act_stand.checkfacingwall = true;
}

void chrStop(struct chrdata *chr)
{
	chrStand(chr);

	chr->act_stand.checkfacingwall = true;
}

void chrBeginDead(struct chrdata *chr)
{
	if (chr->actiontype != ACT_DEAD) {
		chrStopFiring(chr);

		if (chr->cover != -1) {
			coverSetInUse(chr->cover, false);
			chr->cover = -1;
		}

		chr->actiontype = ACT_DEAD;
		chr->act_dead.fadetimer60 = chr->aibot ? 0 : -1;
		chr->act_dead.fadenow = false;
		chr->act_dead.fadewheninvis = false;
		chr->act_dead.invistimer60 = 0;
		chr->act_dead.notifychrindex = 0;
		chr->sleep = 0;
	}
}

void func0f031254(struct chrdata *chr)
{
	struct model *model = chr->model;
	struct attackanimconfig *animcfg = chr->act_attack.animcfg;

	if (chr->act_attack.flags & ATTACKFLAG_AIMONLY) {
		if (animcfg->unk20 >= 0 && animcfg->unk20 < animcfg->unk18) {
			modelSetAnimEndFrame(model, animcfg->unk20);
		} else {
			modelSetAnimEndFrame(model, animcfg->unk18);
		}
	} else if (chr->act_attack.dorecoil) {
		if (animcfg->unk20 >= 0) {
			modelSetAnimEndFrame(model, animcfg->unk20);
		} else {
			modelSetAnimEndFrame(model, animcfg->unk18);
		}
	} else {
		if (animcfg->unk20 >= 0) {
			modelSetAnimEndFrame(model, animcfg->unk20);
		} else if (animcfg->unk14 >= 0) {
			modelSetAnimEndFrame(model, animcfg->unk14);
		} else {
			modelSetAnimEndFrame(model, -1);
		}
	}
}

u8 var80068080 = 50;

s32 gsetGetBlurAmount(struct gset *gset)
{
	s32 amount = TICKS(1000);

	if (g_Vars.normmplayerisrunning == false) {
		amount = TICKS(250);
	}

	if (gset->weaponnum == WEAPON_TRANQUILIZER) {
		amount = TICKS(2000);
	}

	if (gset->weaponnum == WEAPON_BOLT) {
		amount = TICKS(5000);
	}

	if (gset->weaponnum == WEAPON_NBOMB) {
		amount = TICKS(100);
	}

	return amount;
}

void chrChoke(struct chrdata *chr, s32 choketype)
{
	bool male = false;
	s16 soundnum = -1;
	s32 race = CHRRACE(chr);
	s32 playernum;
	s32 allowoverride = false;

	static s32 nextindexmaian = 0;
	static s32 nextindexshock = 0;
	static s32 nextindexmale = 0;
	static s32 nextindexfemale = 0;

	if (chr->prop->type == PROPTYPE_PLAYER) {
		playernum = playermgrGetPlayerNumByProp(chr->prop);

		if (g_Vars.players[playernum]->isdead) {
			return;
		}
	}

	if (g_HeadsAndBodies[chr->headnum].ismale) {
		male = true;
	}

	if (chr->headnum == HEAD_THEKING
			|| chr->headnum == HEAD_ELVIS
			|| chr->headnum == HEAD_MAIAN_S
			|| chr->headnum == HEAD_ELVIS_GOGS) {
		s16 sounds[] = {
			SFX_ARGH_MAIAN_05DF,
			SFX_ARGH_MAIAN_05E0,
			SFX_ARGH_MAIAN_05E1
		};

		soundnum = sounds[random() % 3];
		nextindexmaian++;

		if (nextindexmaian >= ARRAYCOUNT(sounds)) {
			nextindexmaian = 0;
		}
	} else if (chr->headnum == HEAD_DDSHOCK) {
		s16 sounds[] = {
			SFX_ARGH_MALE_0086,
			SFX_ARGH_MALE_0088,
			SFX_ARGH_MALE_008A,
			SFX_ARGH_MALE_008C,
			SFX_ARGH_MALE_008E,
			SFX_ARGH_MALE_0090,
			SFX_ARGH_MALE_0092,
			SFX_ARGH_MALE_0094,
			SFX_ARGH_MALE_0096,
			SFX_ARGH_MALE_0098,
			SFX_ARGH_MALE_009A,
			SFX_ARGH_MALE_009C,
			SFX_ARGH_MALE_009E,
			SFX_ARGH_MALE_0087,
		};

		soundnum = sounds[nextindexshock];
		nextindexshock++;

		if (nextindexshock >= ARRAYCOUNT(sounds)) {
			nextindexshock = 0;
		}

		allowoverride = true;
	} else if (male) {
		s16 sounds[] = {
			SFX_ARGH_MALE_0086,
			SFX_ARGH_MALE_0087,
			SFX_ARGH_MALE_0088,
			SFX_ARGH_MALE_0089,
			SFX_ARGH_MALE_008A,
			SFX_ARGH_MALE_008B,
			SFX_ARGH_MALE_008C,
			SFX_ARGH_MALE_008D,
			SFX_ARGH_MALE_008E,
			SFX_ARGH_MALE_008F,
			SFX_ARGH_MALE_0090,
			SFX_ARGH_MALE_0091,
			SFX_ARGH_MALE_0092,
			SFX_ARGH_MALE_0093,
			SFX_ARGH_MALE_0094,
			SFX_ARGH_MALE_0095,
			SFX_ARGH_MALE_0096,
			SFX_ARGH_MALE_0097,
			SFX_ARGH_MALE_0098,
			SFX_ARGH_MALE_0099,
			SFX_ARGH_MALE_009A,
			SFX_ARGH_MALE_009B,
			SFX_ARGH_MALE_009C,
			SFX_ARGH_MALE_009D,
			SFX_ARGH_MALE_009E,
		};

		soundnum = sounds[nextindexmale];
		nextindexmale++;

		allowoverride = true;

		if (nextindexmale >= ARRAYCOUNT(sounds)) {
			nextindexmale = 0;
		}
	} else if (chr->headnum == HEAD_DARK_COMBAT
			|| chr->headnum == HEAD_DARK_FROCK
			|| chr->headnum == HEAD_DARKAQUA
			|| chr->headnum == HEAD_DARK_SNOW) {
		s16 sounds[] = {
			SFX_ARGH_JO_02AA,
			SFX_ARGH_JO_02AB,
			SFX_ARGH_JO_02AC,
			SFX_ARGH_JO_02AD,
			SFX_ARGH_JO_02AE,
			SFX_ARGH_JO_02AF,
			SFX_ARGH_JO_02B0,
			SFX_ARGH_JO_02B1,
			SFX_ARGH_JO_02B2,
			SFX_ARGH_JO_02B3,
		};

		soundnum = sounds[random() % 10];
		allowoverride = true;
	} else {
		s16 sounds[] = {
			SFX_ARGH_FEMALE_000D,
			SFX_ARGH_FEMALE_000E,
			SFX_ARGH_FEMALE_000F,
		};

		soundnum = sounds[nextindexfemale];
		nextindexfemale++;

		if (nextindexfemale >= ARRAYCOUNT(sounds)) {
			nextindexfemale = 0;
		}

		allowoverride = true;
	}

	if (allowoverride) {
		if (choketype == CHOKETYPE_GURGLE) {
			s32 sounds[] = {
				SFX_M1_CHOKING,
				SFX_GURGLE_05B1,
				SFX_GURGLE_05B2,
			};

			if ((random() % 8) == 0) {
				soundnum = sounds[random() % 3];
			}

			chr->soundgap = 10;
			chr->soundtimer = 0;
		} else if (choketype == CHOKETYPE_COUGH) {
			if (male) {
				if ((random() % 2) == 0) {
					soundnum = SFX_COUGH_04AF;
				} else {
					soundnum = SFX_COUGH_04B0;
				}
			} else {
				s32 index = random() % 4;
				s32 sounds[] = {
					SFX_COUGH_05AB,
					SFX_COUGH_05AC,
					SFX_COUGH_05AD,
					SFX_COUGH_05AE,
				};

				soundnum = sounds[index];
			}

			chr->soundgap = 10;
			chr->soundtimer = 0;
		}
	}

	if (soundnum >= 0) {
		if (chr->prop->type == PROPTYPE_PLAYER) {
			if (g_Vars.players[playernum]->chokehandle == NULL) {
				sndStart(var80095200, soundnum, &g_Vars.players[playernum]->chokehandle, -1, -1, -1, -1, -1);
			}
		} else {
			func0f0926bc(chr->prop, 9, 0);

			if (!func0f092610(chr->prop, 13)) {
				propsnd0f0939f8(NULL, chr->prop, soundnum, -1,
						-1, 0, 0, 13, NULL, -1, NULL, -1, -1, -1, -1);
			}
		}
	}
}

f32 chrGetShield(struct chrdata *chr)
{
	return chr->cshield;
}

void chrSetShield(struct chrdata *chr, f32 amount)
{
	if (amount < 0) {
		amount = 0;
	}

	chr->cshield = amount;

	if ((chr->hidden & CHRHFLAG_INFINITESHIELD) && chr->cshield < 1) {
		chr->cshield = 1;
	}

	if (chr->prop->type == PROPTYPE_PLAYER) {
		s32 playernum = playermgrGetPlayerNumByProp(chr->prop);

		if (playernum >= 0) {
			s32 prevplayernum = g_Vars.currentplayernum;
			setCurrentPlayerNum(playernum);
			playerDisplayHealth();
			g_Vars.currentplayerstats->armourcount += amount * 0.125f;
			setCurrentPlayerNum(prevplayernum);
		}
	}
}

bool func0f034080(struct chrdata *chr, struct modelnode *node, struct prop *prop, struct model *model, s32 side, s16 *arg5)
{
	if (chrGetShield(chr) > 0) {
		if (node && (node->type & 0xff) == MODELNODETYPE_BBOX) {
			shieldhitCreate(chr->prop, chrGetShield(chr), prop, node, model, side, arg5);
		}

		return true;
	}

	return false;
}

/**
 * Damage the chr, bypassing any shield.
 *
 * Used for knife poison, nbomb damage, Investigation radioactivity and Escape gas.
 */
void chrDamageByMisc(struct chrdata *chr, f32 damage, struct coord *vector, struct gset *gset, struct prop *prop)
{
	chrDamage(chr, damage, vector, gset, prop, HITPART_GENERAL,
			false,     // damageshield
			NULL,      // prop2
			NULL,      // node
			NULL,      // model
			-1,        // side
			NULL,      // arg11
			false,     // explosion
			NULL);     // explosionpos
}

void chrDamageByLaser(struct chrdata *chr, f32 damage, struct coord *vector, struct gset *gset, struct prop *prop)
{
	chrDamage(chr, damage, vector, gset, prop, HITPART_GENERAL,
			true,      // damageshield
			chr->prop, // prop2
			NULL,      // node
			NULL,      // model
			-1,        // side
			NULL,      // arg11
			false,     // explosion
			NULL);     // explosionpos
}

void func0f0341dc(struct chrdata *chr, f32 damage, struct coord *vector, struct gset *gset, struct prop *prop, s32 hitpart, struct prop *prop2, struct modelnode *node, struct model *model, s32 side, s16 *arg10)
{
	chrDamage(chr, damage, vector, gset, prop, hitpart,
			true,      // damageshield
			prop2,     // prop2
			node,      // node
			model,     // model
			side,      // side
			arg10,     // arg11
			false,     // explosion
			NULL);     // explosionpos
}

/**
 * Used for punching, but also used by AI commands to make chrs take damage.
 */
void chrDamageByImpact(struct chrdata *chr, f32 damage, struct coord *vector, struct gset *gset, struct prop *prop, s32 hitpart)
{
	struct modelnode *node = NULL;
	struct model *model = NULL;
	s32 side = 0;

	if (chrGetShield(chr) >= 0 && chr->model) {
		chrCalculateShieldHit(chr, &chr->prop->pos, vector, &node, &hitpart, &model, &side);
	}

	chrDamage(chr, damage, vector, gset, prop, hitpart,
			true,      // damageshield
			chr->prop, // prop2
			node,      // node
			model,     // model
			side,      // side
			NULL,      // arg11
			false,     // explosion
			NULL);     // explosionpos
}

void chrDamageByExplosion(struct chrdata *chr, f32 damage, struct coord *vector, struct prop *prop, struct coord *explosionpos)
{
	chrDamage(chr, damage, vector, NULL, prop, HITPART_GENERAL,
			true,      // damageshield
			chr->prop, // prop2
			NULL,      // node
			NULL,      // model
			-1,        // side
			NULL,      // arg11
			true,      // explosion
			explosionpos);
}

void playerUpdateDamageStats(struct prop *attacker, struct prop *victim, f32 damage)
{
	s32 playernum;

	if (attacker && attacker->type == PROPTYPE_PLAYER) {
		playernum = playermgrGetPlayerNumByProp(attacker);

		if (playernum >= 0) {
			g_Vars.playerstats[playernum].damtransmitted += damage;
		}
	}

	if (victim && victim->type == PROPTYPE_PLAYER) {
		playernum = playermgrGetPlayerNumByProp(victim);

		if (playernum >= 0) {
			g_Vars.playerstats[playernum].damreceived += damage;
		}
	}
}

/**
 * Handle a chr being damaged.
 *
 * Calculates and damage based on many factors and applies it to the chr,
 * killing them if needed.
 *
 * The chr can be a player, aibot or regular chr. The chr can also be of any
 * race (human, Skedar, Dr Caroll, robot or eyespy).
 *
 * chr - the chr being damaged
 * damage - the base amount of damage to deal, prior to scaling factors
 * vector - position of the attacker?
 * gset - gun settings struct
 * aprop - the attacker's prop struct
 * hitpart - "i've been hit" value, ie. the body part (see HITPART constants)
 * damageshield - false if attack should bypass shield if any
 * prop2 - ?
 * node - if shielded, model node (of type bbox) which was hit
 * model - if shielded, model of chr
 * side - if shielded, side of the model node's bounding box which was hit (0-5)
 * arg11 - ?
 * explosion - true if damage is coming from an explosion
 * explosionpos - position of said explosion
 */
void chrDamage(struct chrdata *chr, f32 damage, struct coord *vector, struct gset *gset,
		struct prop *aprop, s32 hitpart, bool damageshield, struct prop *prop2,
		struct modelnode *node, struct model *model, s32 side, s16 *arg11,
		bool explosion, struct coord *explosionpos)
{
	bool onehitko = false;
	s32 race = CHRRACE(chr);
	f32 shield;
	bool makedizzy;
	bool isclose;
	struct prop *vprop = chr->prop;
	f32 headshotdamagescale = 1;
	bool usedshield = false;
	bool showshield = false;
	bool showdamage = false;
	struct gset gset2 = {0};
	f32 explosionforce = damage;
	f32 healthscale = 1;
	f32 armourscale = 1;
	bool isfar = true;
	bool forceapplydamage = false;
	struct weaponfunc *func;
	f32 amount;
	bool canchoke = true;
	s32 aplayernum = -1;
	s32 choketype = CHOKETYPE_NONE;

	if (hitpart == HITPART_HEAD) {
		choketype = CHOKETYPE_GURGLE;
	}

	if (gset) {
		if (gset->weaponnum == WEAPON_COMBATKNIFE) {
			if (gset->weaponfunc == FUNC_2) {
				canchoke = false;
			}

			if (gset->weaponfunc == FUNC_POISON) {
				choketype = CHOKETYPE_COUGH;
			}
		} else if (gset->weaponnum == WEAPON_TRANQUILIZER) {
			if (gset->weaponfunc == FUNC_SECONDARY) {
				choketype = CHOKETYPE_GURGLE;
			}
		}
	}

	// Don't damage if in CI training outside of training session
	if (chr->prop == g_Vars.currentplayer->prop
			&& g_Vars.currentplayer->training == false
			&& mainGetStageNum() == STAGE_CITRAINING) {
		return;
	}

	if (gset == NULL) {
		gset = &gset2;
	}

	func = gsetGetWeaponFunction(gset);
	isclose = func && (func->type & 0xff) == INVENTORYFUNCTYPE_CLOSE;
	makedizzy = gsetHasFunctionFlags(gset, FUNCFLAG_MAKEDIZZY);

	if (chr->prop == g_Vars.currentplayer->prop && g_Vars.currentplayer->invincible) {
		return;
	}

	if (isclose) {
		isfar = false;
	}

	// Set a flag on the victim that makes them switch to their "shot" AI list
	chr->chrflags |= CHRCFLAG_TRIGGERSHOTLIST;

	// Set a flag on the attacker so their AI scripting can tell that they've
	// hit their target
	if (aprop
			&& aprop->type == PROPTYPE_CHR
			&& chrGetTargetProp(aprop->chr) == chr->prop) {
		aprop->chr->chrflags |= CHRCFLAG_INJUREDTARGET;
	}

	// Disarm only hurts the victim in solo missions and if the victim is an NPC
	if (gsetHasFunctionFlags(gset, FUNCFLAG_DISARM)
			&& gset->weaponnum == WEAPON_UNARMED
			&& (vprop->type == PROPTYPE_PLAYER || g_Vars.normmplayerisrunning)) {
		damage = 0;
	}

	if (vprop->type == PROPTYPE_PLAYER) {
		s32 prevplayernum = g_Vars.currentplayernum;
		setCurrentPlayerNum(playermgrGetPlayerNumByProp(vprop));
		damage *= g_Vars.currentplayerstats->damagescale;
		setCurrentPlayerNum(prevplayernum);
	}

	// Apply rumble
	if (vprop->type == PROPTYPE_PLAYER) {
		s32 prevplayernum = g_Vars.currentplayernum;

#if VERSION >= VERSION_NTSC_1_0
		s32 contpad1;
		s32 contpad2;

		setCurrentPlayerNum(playermgrGetPlayerNumByProp(vprop));

		joyGetContpadNumsForPlayer(g_Vars.currentplayernum, &contpad1, &contpad2);

		if (contpad1 >= 0) {
			pakRumble(contpad1, 0.25f, -1, -1);
		}

		if (contpad2 >= 0) {
			pakRumble(contpad2, 0.25f, -1, -1);
		}
#else
		setCurrentPlayerNum(playermgrGetPlayerNumByProp(vprop));

		pakRumble((s8)g_Vars.currentplayernum, 0.25f, -1, -1);

		if (optionsGetControlMode(g_Vars.currentplayerstats->mpindex) >= CONTROLMODE_21) {
			pakRumble((s8)(PLAYERCOUNT() + g_Vars.currentplayernum), 0.25f, -1, -1);
		}
#endif

		setCurrentPlayerNum(prevplayernum);
	}

	// Find the attacker's player number if possible
	// (includes MP aibots, not applicable for solo chrs)
	if (g_Vars.mplayerisrunning) {
		if (aprop && (aprop->type == PROPTYPE_PLAYER || aprop->type == PROPTYPE_CHR)) {
			aplayernum = aprop->chr->chrnum;
		}
	} else {
		if (aprop && aprop->type == PROPTYPE_PLAYER) {
			aplayernum = playermgrGetPlayerNumByProp(aprop);
		}
	}

	// If using the shotgun, scale the damage based on distance
	if (aprop && aprop->type == PROPTYPE_CHR && gset->weaponnum == WEAPON_SHOTGUN) {
		f32 xdiff = aprop->pos.x - vprop->pos.x;
		f32 ydiff = aprop->pos.y - vprop->pos.y;
		f32 zdiff = aprop->pos.z - vprop->pos.z;
		f32 sqdist = xdiff * xdiff + ydiff * ydiff + zdiff * zdiff;

		if (sqdist < 200 * 200) {
			damage *= 4.0f + (s32)(random() % 3); // 4, 5 or 6
		} else if (sqdist < 400 * 400) {
			damage *= 3.0f + (s32)(random() % 2); // 3 or 4
		} else if (sqdist < 800 * 800) {
			damage *= 2.0f + (s32)(random() % 2); // 2 or 3
		} else if (sqdist < 1600 * 1600) {
			damage *= 1.0f + (s32)(random() % 2); // 1 or 2
		}
	}

	// damageshield is an argument to this function,
	// but is forced on if using the Farsight.
	if (gset && gset->weaponnum == WEAPON_FARSIGHT) {
		damageshield = true;
		damage *= 10;
	}

	// Handle shield damage
	if (damageshield) {
		shield = chrGetShield(chr);

		if (chr->aibot && chr->aibot->config->type == BOTTYPE_TURTLE) {
			armourscale = 4;
		}

		if (shield > 0) {
			if (g_Vars.normmplayerisrunning) {
#if VERSION >= VERSION_PAL_FINAL
				// Fixing a @bug?
				damage = damage * mpHandicapToDamageScale(g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].handicap);
#else
				damage /= mpHandicapToDamageScale(g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].handicap);
#endif
			}

			chr->chrflags |= CHRCFLAG_SHIELDDAMAGED;

			if (prop2 && node && chr->model) {
				func0f034080(chr, node, prop2, model, side, arg11);
			} else {
				shieldhitCreate(chr->prop, chrGetShield(chr), NULL, NULL, NULL, 0, 0);
			}

			if (g_Vars.normmplayerisrunning && (g_MpSetup.options & MPOPTION_ONEHITKILLS)) {
				damage = 0;
				chrSetShield(chr, 0);
			} else if (shield >= damage / armourscale) {
				// Has enough shield to sustain the damage
				shield -= damage / armourscale;
				damage = 0;
				chrSetShield(chr, shield);
			} else {
				// Shield is now gone
				damage = 0;
				chrSetShield(chr, 0);
			}

			showshield = true;
			usedshield = true;
		}
	}

	// Handle incrementing player shot count
	if (aprop && aprop->type == PROPTYPE_PLAYER && !explosion) {
		bool alreadydead = false;
		s32 prevplayernum = g_Vars.currentplayernum;
		setCurrentPlayerNum(playermgrGetPlayerNumByProp(aprop));

		// ACT_DIE is not checked here, so it would appear that shooting
		// a chr as they're dying will increment the shots hit count
		if (chr && chr->actiontype == ACT_DEAD) {
			alreadydead = true;
		}

		if (vprop->type == PROPTYPE_PLAYER && g_Vars.players[playermgrGetPlayerNumByProp(vprop)]->isdead) {
			alreadydead = true;
		}

		if (!alreadydead && hitpart) {
			switch (hitpart) {
			case HITPART_HEAD:
				mpstatsIncrementPlayerShotCount2(gset, SHOTREGION_HEAD);
				break;
			case HITPART_GUN:
				mpstatsIncrementPlayerShotCount2(gset, SHOTREGION_GUN);
				break;
			case HITPART_HAT:
				mpstatsIncrementPlayerShotCount2(gset, SHOTREGION_HAT);
				break;
			case HITPART_PELVIS:
			case HITPART_TORSO:
				mpstatsIncrementPlayerShotCount2(gset, SHOTREGION_BODY);
				break;
			default:
				mpstatsIncrementPlayerShotCount2(gset, SHOTREGION_LIMB);
				break;
			}
		}

		setCurrentPlayerNum(prevplayernum);
	}

	// If the chr is invincible, make them flinch then we're done
	if (chr->chrflags & CHRCFLAG_INVINCIBLE) {
		chrFlinchBody(chr);
		return;
	}

	// If chr is dying or already dead, consider making their head flinch
	// then we're done
	if (chr->actiontype == ACT_DIE || chr->actiontype == ACT_DEAD) {
		if (hitpart == HITPART_HEAD && chr->actiontype == ACT_DIE && isfar) {
			struct coord pos;
			pos.x = vprop->pos.x - vector->x;
			pos.y = vprop->pos.y - vector->y;
			pos.z = vprop->pos.z - vector->z;
			chrFlinchHead(chr, chrGetAngleToPos(chr, &pos));
		}

		return;
	}

	// At this point the chr is known to be alive before they were shot
	{
		struct prop *weapon;
		struct coord sp9c;
		f32 angle;

		sp9c.x = vprop->pos.x - vector->x;
		sp9c.y = vprop->pos.y - vector->y;
		sp9c.z = vprop->pos.z - vector->z;
		angle = chrGetAngleToPos(chr, &sp9c);

		// Knife in the back to an unalerted chr is lethal
		if (gset->weaponnum == WEAPON_COMBATKNIFE
				&& gset->weaponfunc == FUNC_PRIMARY
				&& angle > 2.0940616130829f
				&& angle < 4.1881237030029f
				&& (chr->alertness < 100 || chr->lastseetarget60 == 0)) {
			damage *= 1000;
		}

		// Punching and pistol whipping is less effective from the front
		if (gsetHasFunctionFlags(gset, FUNCFLAG_BLUNTIMPACT)) {
			if (angle < 1.0470308065414f || angle > 5.2351541519165f) {
				damage *= 0.4f;
			} else if (angle < 2.0940616130829f || angle > 4.1881237030029f) {
				damage *= 0.7f;
			} else if (chr->alertness < 100) {
				onehitko = true;
			}

			if (chrGetHeldProp(chr, HAND_RIGHT) == NULL
					&& chrGetHeldProp(chr, HAND_LEFT) == NULL
					&& chr->gunprop == NULL) {
				// Chr is unarmed and has no hope of getting their gun
				onehitko = true;
			}

			forceapplydamage = true;
		}

		if (hitpart == HITPART_GENERAL) {
			// Halve the damage because it's doubled for torso below
			hitpart = HITPART_TORSO;
			damage *= 0.5f;
		} else if (hitpart == HITPART_GENERALHALF) {
			// Likewise, quarter it here so it becomes half below
			hitpart = HITPART_TORSO;
			damage *= 0.25f;
		}

		// Apply damage multipliers based on which body parts were hit,
		// and flinch head if shot in the head
		if (hitpart == HITPART_HEAD) {
			damage *= 4;

			if (isfar && !usedshield) {
				chrFlinchHead(chr, angle);
				damage *= headshotdamagescale;

				if (gset->weaponnum == WEAPON_COMBATKNIFE && gset->weaponfunc != FUNC_POISON) {
					damage += damage;
				}
			}
		} else if (hitpart == HITPART_TORSO) {
			// Double damage for torso hits
			damage += damage;
		} else if (hitpart == HITPART_GUN) {
			// No damage for gun hits
			damage = 0;
			makedizzy = false;
		} else if (hitpart == HITPART_HAT) {
			// No damage for hat hits
			damage = 0;
			makedizzy = false;
		}

		// Handle situations where the player is the one being shot, then return
		if (vprop->type == PROPTYPE_PLAYER) {
			s32 prevplayernum = g_Vars.currentplayernum;
			setCurrentPlayerNum(playermgrGetPlayerNumByProp(vprop));

			if (g_Vars.normmplayerisrunning) {
				damage /= mpHandicapToDamageScale(g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].handicap);
			}

			if (g_Vars.currentplayer->isdead == false && !g_PlayerInvincible) {
				f32 boostscale;

				// Handle player losing gun
				if (gsetHasFunctionFlags(gset, FUNCFLAG_DISARM)) {
					bgunDisarm(aprop);
				}

				// Handle player dizziness
				if (makedizzy && g_Vars.currentplayer->invincible == false) {
					f32 blurscale = 1;
					struct chrdata *achr = NULL;

					if (aprop) {
						achr = aprop->chr;
					}

					if (!achr
							|| !achr->aibot
							|| !gsetHasFunctionFlags(gset, FUNCFLAG_00400000)
							|| chr->blurdrugamount < TICKS(4500)) {
						chr->blurdrugamount += gsetGetBlurAmount(gset) * blurscale;
					}

					chr->blurnumtimesdied = 0;
				}

				// Handle player damage
				if (g_Vars.currentplayer->invincible == false && damage > 0) {
					f32 statsamount = amount = damage * 0.125f;

					if (statsamount > g_Vars.currentplayer->bondhealth) {
						statsamount = g_Vars.currentplayer->bondhealth;
					}

					if (g_Vars.normmplayerisrunning && (g_MpSetup.options & MPOPTION_ONEHITKILLS)) {
						statsamount = g_Vars.currentplayer->bondhealth;
					}

					playerUpdateDamageStats(aprop, vprop, statsamount);
					playerDisplayHealth();

					if (g_Vars.normmplayerisrunning && (g_MpSetup.options & MPOPTION_ONEHITKILLS)) {
						g_Vars.currentplayer->bondhealth = 0;
					}

					g_Vars.currentplayer->bondhealth -= amount / healthscale;

					chr->lastattacker = (aprop ? aprop->chr : NULL);

					showdamage = true;

					if (g_Vars.currentplayer->training == false
							&& g_Vars.currentplayer->bondhealth <= 0) {
						playerDieByShooter(aplayernum, false);
						chr->blurnumtimesdied++;
					}

					if (!lvIsPaused() && canchoke) {
						chrChoke(chr, choketype);
					}

					chrFlinchBody(chr);
				}

				// Handle player boost
				if (isclose && gset->weaponnum == WEAPON_REAPER) {
					boostscale = 0.1f;
				} else if (g_Vars.normmplayerisrunning) {
					boostscale = 0.75f;
				} else {
					boostscale = 1;
				}

				g_Vars.currentplayer->bondshotspeed.x += vector->x * boostscale;
				g_Vars.currentplayer->bondshotspeed.z += vector->z * boostscale;

				if (showdamage) {
					playerDisplayDamage();
				}

				if (showshield) {
					playerDisplayShield();
				}

				if (g_Vars.normmplayerisrunning && aprop && aprop->type == PROPTYPE_PLAYER) {
					playerCheckIfShotInBack(prevplayernum, vector->x, vector->z);
				}
			}

			setCurrentPlayerNum(prevplayernum);
			return;
		}

		// This check is pointless - a similar check and return exists earlier
		if (chr->actiontype == ACT_DIE || chr->actiontype == ACT_DEAD) {
			return;
		}

		// At this point we know we're dealing with a NPC being shot, and the
		// NPC was alive prior to being shot.

		// Handle aibot/chr losing gun
		if (gsetHasFunctionFlags(gset, FUNCFLAG_DISARM) && chr->aibot) {
			botDisarm(chr, aprop);
		}

		// Handle chr damage
		if (chr->damage < chr->maxdamage) {
			f32 sp80 = 0;

			chr->numarghs++;

			// Handle chr dizziness and psychosis
			if (makedizzy) {
				if (gsetHasFunctionFlags(gset, FUNCFLAG_PSYCHOSIS)) {
					chr->hidden |= CHRHFLAG_PSYCHOSISED;
				} else {
					chr->blurdrugamount += gsetGetBlurAmount(gset);
					chr->blurnumtimesdied = 0;
				}
			}

			// Handle chr boost
			{
				f32 boostscale;

				if (isclose && gset->weaponnum == WEAPON_REAPER) {
					boostscale = 0.1f;
				} else {
					boostscale = 0.75f;
				}

				chr->aibot->shotspeed.x += vector->x * boostscale;
				chr->aibot->shotspeed.z += vector->z * boostscale;
			}

			if (gset->weaponnum == WEAPON_UNARMED) {
				sp80 = 2;
			}

			if (gset->weaponnum == WEAPON_TRANQUILIZER || gset->weaponnum == WEAPON_PSYCHOSISGUN) {
				forceapplydamage = true;
			}

			// Handle applying damage to NPCs
			// Don't enter this branch if there is no damage to give,
			// or we are making a chr dizzy in solo mode (unless force is set)
			if (damage > 0) {
				f32 amount = damage;

				if (chr->damage + damage > chr->maxdamage) {
					amount = chr->maxdamage - chr->damage;
				}

				amount *= 0.125f;

				playerUpdateDamageStats(aprop, vprop, amount);

				chr->damage += damage;
				chr->lastattacker = (aprop ? aprop->chr : NULL);
				chr->chrflags |= CHRCFLAG_JUST_INJURED;

				if (g_MpSetup.options & MPOPTION_ONEHITKILLS) {
					chr->damage = chr->maxdamage;
				}

				if (canchoke) {
					chrChoke(chr, choketype);
				}

				chrFlinchBody(chr);

				if (chr->damage >= chr->maxdamage) {
					chrDie(chr, aplayernum);
				}

				if (sp80 > 0) {
					chr->timeextra = sp80 * 15;
					chr->elapseextra = 0;

					chr->extraspeed.x = prop2->pos.x - aprop->pos.x;
					chr->extraspeed.y = prop2->pos.y - aprop->pos.y;
					chr->extraspeed.z = prop2->pos.z - aprop->pos.z;

					guNormalize(&chr->extraspeed.x, &chr->extraspeed.y, &chr->extraspeed.z);

					chr->extraspeed.x *= sp80;
					chr->extraspeed.y *= sp80;
					chr->extraspeed.z *= sp80;
				}
			}
		}
	}
}

void chrDie(struct chrdata *chr, s32 aplayernum)
{
	if (chr->actiontype != ACT_DIE) {
		chrStopFiring(chr);
		chrUncloak(chr, true);

		chr->actiontype = ACT_DIE;
		chr->act_die.notifychrindex = 0;
		chr->sleep = 0;
		chr->blurnumtimesdied++;
		chr->act_die.thudframe1 = -1;
		chr->act_die.thudframe2 = -1;
		chr->act_die.timeextra = 0;

		mpstatsRecordDeath(aplayernum, chr->chrnum);
		botinvDropAll(chr, chr->aibot->weaponnum);

#if VERSION >= VERSION_NTSC_1_0
		chr->aibot->hasbriefcase = false;
		chr->aibot->hascase = false;
		chr->aibot->unk04c_04 = false;
		chr->aibot->unk04c_03 = false;
		chr->aibot->hasuplink = false;
#endif
	}
}

bool func0f03645c(struct chrdata *chr, struct coord *arg1, s16 *arg2, struct coord *arg3, struct coord *arg4, s32 arg5)
{
	bool result = false;
	f32 ymax;
	f32 ymin;
	f32 radius;
	s16 rooms[8];
	struct prop *prop = chr->prop;

	chrGetBbox(prop, &radius, &ymax, &ymin);
	chrSetPerimEnabled(chr, false);

	if (cdTestCylMove04(arg1, arg2, arg3, rooms, arg5, 1, ymax - prop->pos.y, ymin - prop->pos.y) != CDRESULT_COLLISION) {
		if (cdTestCylMove01(arg3, rooms, arg4, arg5, 1, ymax - prop->pos.y, ymin - prop->pos.y) != CDRESULT_COLLISION) {
			result = true;
		}
	}

	chrSetPerimEnabled(chr, true);

	return result;
}

bool func0f03654c(struct chrdata *chr, struct coord *pos, s16 *rooms, struct coord *pos2, s16 *rooms2, struct coord *vector, f32 arg6, u32 types)
{
	struct coord tmp;
	f32 a;
	f32 b;
	struct prop *prop;
	bool result = false;
	f32 ymax;
	f32 ymin;
	f32 radius;
	struct coord sp5c;
	struct coord sp50;
	s16 sp40[8];
	f32 mult;

	prop = chr->prop;

	chrSetPerimEnabled(chr, false);
	chrGetBbox(prop, &radius, &ymax, &ymin);

	if ((rooms2 && cdTestCylMove02(pos, rooms, pos2, rooms2, types, true, ymax - prop->pos.y, ymin - prop->pos.y))
			|| (rooms2 == NULL && cdTestCylMove01(pos, rooms, pos2, types, 1, ymax - prop->pos.y, ymin - prop->pos.y))) {
		if (vector == NULL) {
			vector = &tmp;

			tmp.x = pos2->x - pos->x;
			tmp.y = 0;
			tmp.z = pos2->z - pos->z;

			if (tmp.f[0] == 0 && tmp.f[2] == 0) {
				// @bug: Needs to call chrSetPerimEnabled(chr, true)
				// before returning
				return true;
			}

			mult = 1.0f / sqrtf(tmp.f[0] * tmp.f[0] + tmp.f[2] * tmp.f[2]);
			tmp.x *= mult;
			tmp.z *= mult;
		}

		a = vector->x * arg6;
		b = vector->z * arg6;

		sp5c.x = pos->x + b;
		sp5c.y = pos->y;
		sp5c.z = pos->z - a;

		sp50.x = pos2->x + b;
		sp50.y = pos2->y;
		sp50.z = pos2->z - a;

		if (cdTestCylMove04(pos, rooms, &sp5c, sp40, types, 1, ymax - prop->pos.y, ymin - prop->pos.y)
				&& cdTestCylMove01(&sp5c, sp40, &sp50, types, 1, ymax - prop->pos.y, ymin - prop->pos.y)) {
			sp5c.x = pos->x - b;
			sp5c.y = pos->y;
			sp5c.z = pos->z + a;

			sp50.x = pos2->x - b;
			sp50.y = pos2->y;
			sp50.z = pos2->z + a;

			if (cdTestCylMove04(pos, rooms, &sp5c, sp40, types, 1, ymax - prop->pos.y, ymin - prop->pos.y)
					&& cdTestCylMove01(&sp5c, sp40, &sp50, types, 1, ymax - prop->pos.y, ymin - prop->pos.y)) {
				result = true;
			}
		}
	}

	chrSetPerimEnabled(chr, true);

	return result;
}

bool chrIsRoomOffScreen(struct chrdata *chr, struct coord *waypos, s16 *wayrooms)
{
	struct prop *prop = chr->prop;
	s16 sp7c[20];
	u32 stack;
	s32 i;
	s16 sp64[8];
	bool offscreen = true;
	s16 sp50[8];

	if ((chr->hidden & CHRHFLAG_CLOAKED) == 0) {
		func0f065dfc(&prop->pos, prop->rooms, waypos, sp64, sp7c, 20);

		if (g_Vars.mplayerisrunning) {
			for (i = 0; sp7c[i] != -1; i++) {
				if (g_MpRoomVisibility[sp7c[i]] & 0x0f) {
					offscreen = false;
					break;
				}
			}
		} else {
			for (i = 0; sp7c[i] != -1; i++) {
				if (g_Rooms[sp7c[i]].flags & ROOMFLAG_ONSCREEN) {
					offscreen = false;
					break;
				}
			}
		}
	}

	if (offscreen) {
		for (i = 0; i < PLAYERCOUNT(); i++) {
			portal00018148(waypos, &g_Vars.players[i]->prop->pos, wayrooms, sp50, 0, 0);

			if (arrayIntersects(g_Vars.players[i]->prop->rooms, sp50)) {
				offscreen = false;
				break;
			}
		}
	}

	return offscreen;
}

void chrGoPosInitMagic(struct chrdata *chr, struct waydata *waydata, struct coord *padpos, struct coord *chrpos)
{
	f32 xdiff1 = padpos->x - chr->prop->pos.x;
	f32 zdiff1 = padpos->z - chr->prop->pos.z;

	f32 angle = atan2f(xdiff1, zdiff1);

	f32 xdiff2 = padpos->x - chrpos->x;
	f32 zdiff2 = padpos->z - chrpos->z;

	waydata->mode = WAYMODE_MAGIC;

	waydata->magictotal = sqrtf(xdiff1 * xdiff1 + zdiff1 * zdiff1);
	waydata->magicdone = waydata->magictotal - sqrtf(xdiff2 * xdiff2 + zdiff2 * zdiff2);

	chrSetLookAngle(chr, angle);
}

void chrGoPosGetCurWaypointInfoWithFlags(struct chrdata *chr, struct coord *pos, s16 *rooms, u32 *flags)
{
	struct waypoint *waypoint = chr->act_gopos.waypoints[chr->act_gopos.curindex];
	struct pad pad;

	if (waypoint) {
		padUnpack(waypoint->padnum, PADFIELD_POS | PADFIELD_ROOM | PADFIELD_FLAGS, &pad);

		pos->x = pad.pos.x;
		pos->y = pad.pos.y;
		pos->z = pad.pos.z;

		rooms[0] = pad.room;
		rooms[1] = -1;

		if (flags) {
			*flags = pad.flags;
		}
	} else {
		pos->x = chr->act_gopos.endpos.x;
		pos->y = chr->act_gopos.endpos.y;
		pos->z = chr->act_gopos.endpos.z;

		rooms[0] = chr->act_gopos.endrooms[0];
		rooms[1] = -1;

		if (flags) {
			*flags = 0;
		}
	}
}

void chrGoPosGetCurWaypointInfo(struct chrdata *chr, struct coord *pos, s16 *rooms)
{
	chrGoPosGetCurWaypointInfoWithFlags(chr, pos, rooms, NULL);
}

f32 func0f0370a8(struct chrdata *chr)
{
	f32 result;

	if (chr->aibot) {
		result = botCalculateMaxSpeed(chr);
	} else {
		s16 animnum = modelGetAnimNum(chr->model);
		result = func0f02dff0(animnum) * (chr->model->scale * 9.999999f);
	}

	return result;
}

s32 chrGoPosCalculateBaseTtl(struct chrdata *chr)
{
	f32 xdiff;
	f32 zdiff;
	u32 stack;
	struct coord pos;
	s16 rooms[8];
	f32 speed;

	chrGoPosGetCurWaypointInfo(chr, &pos, rooms);

	xdiff = pos.x - chr->prop->pos.x;
	zdiff = pos.z - chr->prop->pos.z;

	if (xdiff < 0) {
		xdiff = -xdiff;
	}

	if (zdiff < 0) {
		zdiff = -zdiff;
	}

	speed = func0f0370a8(chr);

	if (speed < 0.001f) {
		speed = 0.001f;
	}

	return (xdiff + zdiff) / speed;
}

void chrGoPosClearRestartTtl(struct chrdata *chr)
{
	chr->act_gopos.restartttl = 0;
}

void chrGoPosConsiderRestart(struct chrdata *chr)
{
	if (chr->act_gopos.waydata.mode != WAYMODE_MAGIC
			&& chr->liftaction != LIFTACTION_WAITINGONLIFT
			&& chr->liftaction != LIFTACTION_WAITINGFORLIFT) {
		if (chr->act_gopos.restartttl == 0) {
#if PAL
			s32 value = (chrGoPosCalculateBaseTtl(chr) * 100 + 15000) / 60;
#else
			s32 value = chrGoPosCalculateBaseTtl(chr) * 2 + 300;
#endif

			if (value > 0xffff) {
				value = 0xffff;
			}

			chr->act_gopos.restartttl = value;
		} else if (chr->act_gopos.restartttl <= (u16)g_Vars.lvupdate60) {
			botCheckFetch(chr);
		} else {
			chr->act_gopos.restartttl -= (u16)g_Vars.lvupdate60;
		}
	}
}

void chrGoPosInitExpensive(struct chrdata *chr)
{
	struct coord pos;
	s16 rooms[8];

	chrGoPosGetCurWaypointInfo(chr, &pos, rooms);

	chr->act_gopos.waydata.mode = WAYMODE_INIT;
	chr->act_gopos.waydata.iter = 0;
	chr->act_gopos.waydata.gotaimpos = false;
	chr->act_gopos.waydata.aimpos.x = pos.x;
	chr->act_gopos.waydata.aimpos.y = pos.y;
	chr->act_gopos.waydata.aimpos.z = pos.z;

	chrGoPosClearRestartTtl(chr);
}

/**
 * Advance the chr's current waypoint index to the next one in the route.
 *
 * The waypoints array allows 6 waypoints and it's important that they have a
 * couple loaded in front of their current one. So if the index is moving too
 * far into the array, new pathfinding will be done and the array and index will
 * be reset.
 */
void chrGoPosAdvanceWaypoint(struct chrdata *chr)
{
	if (chr->act_gopos.curindex < 3) {
		chr->act_gopos.curindex++;
	} else {
		struct waypoint *from = chr->act_gopos.waypoints[chr->act_gopos.curindex];
		u32 hash;
		chr->act_gopos.curindex = 1;

		hash = (g_Vars.lvframe60 >> 9) * 0x80 + chr->chrnum * 8;

		waypointSetHashThing(hash, hash);
		waypointFindRoute(from, chr->act_gopos.target, chr->act_gopos.waypoints, MAX_CHRWAYPOINTS);
		waypointSetHashThing(0, 0);
	}

	chrGoPosInitExpensive(chr);
}

void chrNavTickMagic(struct chrdata *chr, struct waydata *waydata, f32 speed, struct coord *arg3, s16 *rooms)
{
	s16 sp118[8];
	f32 ymax;
	f32 ymin;
	f32 radius;
	f32 ground;
	u16 floorcol;
	u8 floortype;
	s16 floorroom;
	struct coord spf4;
	struct prop *prop = chr->prop;
	union modelrwdata *rwdata;
	struct waypoint *waypoint;
	struct coord spdc;
	s16 spcc[8];
	u32 stack[4];
	struct pad pad;
	struct coord sp5c;
	s16 sp4c[8];

	chr->invalidmove = 0;
	chr->lastmoveok60 = g_Vars.lvframe60;

	waydata->magicdone += speed * modelGetAbsAnimSpeed(chr->model) * g_Vars.lvupdate60freal;

	if (waydata->magicdone >= waydata->magictotal) {
		// Reached end of segment
		chrSetPerimEnabled(chr, false);
		roomsCopy(rooms, sp118);
		chr0f021fa8(chr, arg3, sp118);

		ground = cdFindGroundInfoAtCyl(arg3, chr->radius, sp118, &floorcol, &floortype, 0, &floorroom, NULL, NULL);

		spf4.x = arg3->x;
		spf4.y = prop->pos.y - chr->ground + ground;
		spf4.z = arg3->z;

		roomsCopy(rooms, sp118);
		chr0f021fa8(chr, &spf4, sp118);
		chrGetBbox(chr->prop, &radius, &ymax, &ymin);

		if (cdTestVolume(&spf4, chr->radius, sp118, CDTYPE_ALL, CHECKVERTICAL_YES, ymax - prop->pos.y, ymin - prop->pos.y) != CDRESULT_COLLISION) {
			// Reached end of segment with no collision
			prop->pos.x = spf4.x;
			prop->pos.y = spf4.y;
			prop->pos.z = spf4.z;

			chr->ground = ground;
			chr->manground = ground;
			chr->sumground = ground * (PAL ? 8.4175090789795f : 9.999998f);

			chr->floorcol = floorcol;
			chr->floortype = floortype;
			chr->floorroom = floorroom;

			propDeregisterRooms(prop);
			roomsCopy(sp118, prop->rooms);
			propRegisterRooms(prop);

			modelSetRootPosition(chr->model, &prop->pos);

			rwdata = modelGetNodeRwData(chr->model, chr->model->filedata->rootnode);
			rwdata->chrinfo.ground = ground;

			chr->chrflags |= CHRCFLAG_00000001;

			if (chr->actiontype == ACT_GOPOS) {
				if (chr->act_gopos.waypoints[chr->act_gopos.curindex] == NULL) {
					// Reached the end of the route
					if (chr->act_gopos.curindex >= 2) {
						waypoint = chr->act_gopos.waypoints[chr->act_gopos.curindex - 2];
						padUnpack(waypoint->padnum, PADFIELD_POS, &pad);
						chrSetLookAngle(chr, atan2f(prop->pos.x - pad.pos.x, prop->pos.z - pad.pos.z));
					}

					if (CHRRACE(chr) == RACE_HUMAN) {
						chrStop(chr);
					}
				} else {
					// Advance to next segment, still using magic
					chrGoPosAdvanceWaypoint(chr);
					chrGoPosGetCurWaypointInfo(chr, &sp5c, sp4c);
					chrGoPosInitMagic(chr, waydata, &sp5c, &prop->pos);
				}
			}
		} else {
			// Collision
			waydata->magicdone = waydata->magictotal;

			chr->act_gopos.waydata.lastvisible60 = g_Vars.lvframe60;
			chrGoPosInitExpensive(chr);
		}

		chrSetPerimEnabled(chr, true);
	}
}

/**
 * Calculate the chr's position when using the magic method of navigating.
 *
 * The magic method is used when the chr is off-screen. It measures the distance
 * between two consecutive pads in the route and simply increments a distance
 * value along that segment on each tick, ignoring collisions. Meanwhile, the
 * chr's prop->pos is left as the original location where this segment started.
 *
 * The calculation is finding the fraction of the distance travelled in this
 * segment, then finding the position between the starting pos and the pad's
 * pos.
 *
 * The pos variable is used for both loading the next pad's position and for
 * returning the new position, which means there's less stack usage.
 */
void chrCalculatePosition(struct chrdata *chr, struct coord *pos)
{
	s16 rooms[8];
	f32 frac;

	if (chr->actiontype == ACT_GOPOS && chr->act_gopos.waydata.mode == WAYMODE_MAGIC) {
		chrGoPosGetCurWaypointInfo(chr, pos, rooms);

		if (!(chr->act_gopos.waydata.magicdone >= chr->act_gopos.waydata.magictotal)
				&& chr->act_gopos.waydata.magictotal > 0) {
			frac = chr->act_gopos.waydata.magicdone / chr->act_gopos.waydata.magictotal;
			pos->x = (pos->x - chr->prop->pos.x) * frac + chr->prop->pos.x;
			pos->y = (pos->y - chr->prop->pos.y) * frac + chr->prop->pos.y;
			pos->z = (pos->z - chr->prop->pos.z) * frac + chr->prop->pos.z;
		}
	} else {
		pos->x = chr->prop->pos.x;
		pos->y = chr->prop->pos.y;
		pos->z = chr->prop->pos.z;
	}
}

void chrGoPosChooseAnimation(struct chrdata *chr)
{
	if (chr->actiontype == ACT_GOPOS) {
		chr->act_gopos.flags &= ~GOPOSFLAG_WAITING;
	}
}

bool chrGoToRoomPos(struct chrdata *chr, struct coord *pos, s16 *room, u32 goposflags)
{
	struct prop *prop = chr->prop;
	struct waypoint *nextwaypoint;
	struct waypoint *lastwaypoint;
	struct waypoint *waypoints[MAX_CHRWAYPOINTS];
	s32 i;
	struct coord curwppos;
	s16 curwprooms[8];
	s32 isgopos = chr->actiontype == ACT_GOPOS
		&& (chr->act_gopos.flags & GOPOSMASK_SPEED) == (goposflags & 0xff & GOPOSMASK_SPEED)
		&& !chrGoPosIsWaiting(chr);
	s32 ismagic = isgopos && chr->act_gopos.waydata.mode == WAYMODE_MAGIC;
	struct coord prevpos;
	s32 numwaypoints = 0;

	for (i = 0; chr->prop->rooms[i] != -1; i++) {
		chr->oldrooms[i] = chr->prop->rooms[i];
	}

	chr->oldrooms[i] = -1;

	if (isgopos && ismagic && chr->act_gopos.waypoints[chr->act_gopos.curindex]) {
		nextwaypoint = chr->act_gopos.waypoints[chr->act_gopos.curindex];
	} else {
		nextwaypoint = waypointFindClosestToPos(&prop->pos, prop->rooms);
	}

	lastwaypoint = waypointFindClosestToPos(pos, room);

	if (nextwaypoint && lastwaypoint) {
		waypointSetHashThing(
				((g_Vars.lvframe60 >> 9) << 7) + chr->chrnum * 8,
				((g_Vars.lvframe60 >> 9) << 7) + chr->chrnum * 8);
		numwaypoints = waypointFindRoute(nextwaypoint, lastwaypoint, waypoints, MAX_CHRWAYPOINTS);
		waypointSetHashThing(0, 0);
	}

	if (numwaypoints > 1) {
		if (isgopos && ismagic) {
			chrCalculatePosition(chr, &prevpos);
		} else {
			prevpos.x = prop->pos.x;
			prevpos.y = prop->pos.y;
			prevpos.z = prop->pos.z;
		}

		chrStopFiring(chr);

		chr->actiontype = ACT_GOPOS;
		chr->act_gopos.endpos.x = pos->x;
		chr->act_gopos.endpos.y = pos->y;
		chr->act_gopos.endpos.z = pos->z;
		roomsCopy(room, chr->act_gopos.endrooms);

		chr->act_gopos.target = lastwaypoint;
		chr->act_gopos.curindex = 0;
		chr->act_gopos.flags = goposflags | GOPOSFLAG_INIT;
		chr->act_gopos.turnspeed = 0;
		chr->unk32c_21 = 0;
		chr->act_gopos.waydata.age = random() % 100;
		chr->act_gopos.waydata.gotaimposobj = 0;

		if (!isgopos) {
			chr->act_gopos.waydata.lastvisible60 = -1;
		}

		for (i = 0; i < MAX_CHRWAYPOINTS; i++) {
			chr->act_gopos.waypoints[i] = waypoints[i];
		}

		chrGoPosInitExpensive(chr);
#if VERSION >= VERSION_NTSC_1_0
		chr->goposforce = -1;
#endif
		chr->sleep = 0;
		chr->liftaction = 0;
		chr->act_gopos.flags &= ~(GOPOSFLAG_WALKDIRECT | GOPOSFLAG_DUCK | GOPOSFLAG_WAITING);
		chrGoPosGetCurWaypointInfo(chr, &curwppos, curwprooms);

		if ((!isgopos || ismagic)
				&& g_Vars.normmplayerisrunning == false
				&& (prop->flags & (PROPFLAG_ONANYSCREENPREVTICK | PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONTHISSCREENTHISTICK)) == 0
				&& chrIsRoomOffScreen(chr, &curwppos, curwprooms)
				&& chr->inlift == false) {
			chrGoPosInitMagic(chr, &chr->act_gopos.waydata, &curwppos, &prevpos);
		}

		if (!isgopos) {
			chrGoPosChooseAnimation(chr);
		}

		chr->hidden &= ~CHRHFLAG_NEEDANIM;
		return true;
	}

	return false;
}

void chrRecordLastVisibleTargetTime(struct chrdata *chr)
{
	chr->lastvisibletarget60 = g_Vars.lvframe60;
}

bool chrCanSeeEntity(struct chrdata *chr, struct coord *chrpos, s16 *chrrooms, bool allowextraheight, u32 attackflags, u32 entityid)
{
	bool result = false;
	struct coord targetpos;
	s16 targetrooms[8];
	struct prop *targetprop;
	struct chrdata *targetchr;
	u32 types;
	struct prop *weaponprop;

	if (attackflags & ATTACKFLAG_AIMFORWARD) {
		result = true;
	} else {
		types = CDTYPE_DOORSWITHOUTFLAG | CDTYPE_ALL;
		weaponprop = chrGetHeldProp(chr, HAND_RIGHT);

		if (weaponprop == NULL) {
			weaponprop = chrGetHeldProp(chr, HAND_LEFT);
		}

		if (weaponprop) {
			struct weaponobj *weapon = weaponprop->weapon;

			if (weapon->weaponnum == WEAPON_ROCKETLAUNCHER
					|| weapon->weaponnum == WEAPON_SLAYER
					|| weapon->weaponnum == WEAPON_ROCKETLAUNCHER_34) {
				types = CDTYPE_DOORSWITHOUTFLAG | CDTYPE_OBJSWITHFLAG2 | CDTYPE_ALL;
			} else {
				types = CDTYPE_DOORSWITHOUTFLAG | CDTYPE_OBJSWITHFLAG | CDTYPE_ALL;
			}
		}

		chrGetAttackEntityPos(chr, attackflags, entityid, &targetpos, targetrooms);
		chrSetPerimEnabled(chr, false);

		if ((attackflags & ATTACKFLAG_AIMATTARGET)) {
			targetprop = chrGetTargetProp(chr);

			if (targetprop->type != PROPTYPE_PLAYER || g_Vars.bondvisible) {
				propSetPerimEnabled(targetprop, false);

				if (allowextraheight && (chr->chrflags & CHRCFLAG_LOSEXTRAHEIGHT)) {
					struct coord frompos;
					s16 fromrooms[8];

					frompos.x = chrpos->x;
					frompos.y = chrpos->y + 70;
					frompos.z = chrpos->z;

					func0f065dd8(chrpos, chrrooms, &frompos, fromrooms);

					if (cdTestLos05(&frompos, fromrooms, &targetpos, targetrooms, types, GEOFLAG_BLOCK_SHOOT)) {
						chrRecordLastVisibleTargetTime(chr);
						result = true;
					}
				} else {
					if (cdTestLos05(chrpos, chrrooms, &targetpos, targetrooms, types, GEOFLAG_BLOCK_SHOOT)) {
						chrRecordLastVisibleTargetTime(chr);
						result = true;
					}
				}

				propSetPerimEnabled(targetprop, true);
			}
		} else if (attackflags & ATTACKFLAG_AIMATCHR) {
			targetchr = chrFindById(chr, entityid);

			if (!targetchr || !targetchr->prop) {
				targetchr = chr;
			}

			chrSetPerimEnabled(targetchr, false);

			if (cdTestLos05(chrpos, chrrooms, &targetpos, targetrooms, types, GEOFLAG_BLOCK_SHOOT)) {
				result = true;
			}

			chrSetPerimEnabled(targetchr, true);
		} else if (attackflags & ATTACKFLAG_AIMATPAD) {
			if (cdTestLos05(chrpos, chrrooms, &targetpos, targetrooms, types, GEOFLAG_BLOCK_SHOOT)) {
				result = true;
			}
		}

		chrSetPerimEnabled(chr, true);
	}

	return result;
}

bool chrCanSeeAttackTarget(struct chrdata *chr, struct coord *pos, s16 *rooms, bool allowextraheight)
{
	u32 attackflags = ATTACKFLAG_AIMATTARGET;
	u32 entityid = 0;

	if (chr->actiontype == ACT_ATTACK) {
		attackflags = chr->act_attack.flags;
		entityid = chr->act_attack.entityid;
	}

	return chrCanSeeEntity(chr, pos, rooms, allowextraheight, attackflags, entityid);
}

bool chrCanSeeChr(struct chrdata *chr, struct chrdata *target, s16 *room)
{
	bool cansee = false;
	u32 stack;
	s16 sp88[] = {-1, 0, 0, 0, 0, 0, 0, 0};

	if (botIsTargetInvisible(chr, target) == 0) {
		struct prop *prop = chr->prop;
		struct coord pos;
		s16 rooms[8];

		pos.x = prop->pos.x;
		pos.y = chr->ground + chr->height - 20;
		pos.z = prop->pos.z;

		chrSetPerimEnabled(chr, false);
		chrSetPerimEnabled(target, false);

		func0f065e74(&prop->pos, prop->rooms, &pos, rooms);

		if (cdTestLos07(&pos, rooms, &target->prop->pos, target->prop->rooms, sp88,
					CDTYPE_OBJS | CDTYPE_DOORS | CDTYPE_PATHBLOCKER | CDTYPE_BG | CDTYPE_AIOPAQUE,
					GEOFLAG_BLOCK_SIGHT)) {
			cansee = true;
		}

		chrSetPerimEnabled(chr, true);
		chrSetPerimEnabled(target, true);
	}

	if (room) {
		*room = sp88[0];
	}

	return cansee;
}

bool chrCanSeeTarget(struct chrdata *chr)
{
	bool cansee;
	struct prop *prop;

#if VERSION >= VERSION_JPN_FINAL
	cansee = false;
	prop = chrGetTargetProp(chr);

	if (prop && prop->chr) {
		cansee = chrCanSeeChr(chr, prop->chr, NULL);

		if (cansee) {
			chrRecordLastVisibleTargetTime(chr);
		}
	}
#else
	prop = chrGetTargetProp(chr);
	cansee = chrCanSeeChr(chr, prop->chr, NULL);

	if (cansee) {
		chrRecordLastVisibleTargetTime(chr);
	}
#endif

	return cansee;
}

bool chrHasLineOfSightToPos(struct chrdata *chr, struct coord *pos, s16 *rooms)
{
	struct prop *prop = chr->prop;
	bool result = false;
	struct coord eyepos;
	s16 chrrooms[8];

	eyepos.x = prop->pos.x;
	eyepos.y = chr->ground + chr->height - 20;
	eyepos.z = prop->pos.z;

	chrSetPerimEnabled(chr, false);
	func0f065e74(&prop->pos, prop->rooms, &eyepos, chrrooms);

	if (cdTestLos05(&eyepos, chrrooms, pos, rooms,
				CDTYPE_OBJS | CDTYPE_DOORS | CDTYPE_PATHBLOCKER | CDTYPE_BG | CDTYPE_AIOPAQUE,
				GEOFLAG_BLOCK_SIGHT)) {
		result = true;
	}

	chrSetPerimEnabled(chr, true);

	return result;
}

bool chrCanSeePos(struct chrdata *chr, struct coord *pos, s16 *rooms)
{
	f32 facingangle = chrGetInverseTheta(chr);
	f32 posangle = atan2f(pos->x - chr->prop->pos.x, pos->z - chr->prop->pos.z);
	f32 diffangle = posangle - facingangle;

	if (posangle < facingangle) {
		diffangle += M_BADTAU;
	}

	// This check is pointless because chrHasLineOfSightToPos is called
	// with the same arguments regardless.
	if ((diffangle < 1.7450513839722f || diffangle > 4.5371336936951f)
			&& chrHasFlag(chr, CHRFLAG1_NOOP_00200000, BANK_1) == false) {
		return chrHasLineOfSightToPos(chr, pos, rooms);
	}

	return chrHasLineOfSightToPos(chr, pos, rooms);
}

void chrRecordLastSeeTargetTime(struct chrdata *chr)
{
	chr->lastseetarget60 = g_Vars.lvframe60;
}

void chrRecordLastHearTargetTime(struct chrdata *chr)
{
	chr->hidden |= CHRHFLAG_IS_HEARING_TARGET;
	chr->lastheartarget60 = g_Vars.lvframe60;
}

bool chrCheckTargetInSight(struct chrdata *chr)
{
	struct prop *prop = chr->prop;
	struct prop *target = chrGetTargetProp(chr);
	f32 sqdistance;
	f32 fVar5 = chrGetInverseTheta(chr);

	f32 x = target->pos.x - prop->pos.x;
	f32 y = target->pos.y - prop->pos.y;
	f32 z = target->pos.z - prop->pos.z;

	f32 fVar6 = atan2f(x, z);
	f32 angle = fVar6 - fVar5;
	bool result = false;

	if (fVar6 < fVar5) {
		angle += M_BADTAU;
	}

	sqdistance = x * x + y * y + z * z;

	if ((sqdistance < chr->visionrange * chr->visionrange * 10000.0f && (angle < 1.9195564985275f || angle > 4.3626284599304f))
			|| (sqdistance < 40000.0f && (angle < 1.9195564985275f || angle > 4.3626284599304f))) {
		result = false;

		if (sqdistance < env0f1657e4()) {
			f32 tmp;
			s32 iVar8 = (sqrtf(sqdistance) * 0.0018749999580905f);
			s32 tmp2;

			if (angle > 0.7852731347084f && angle < 5.4969120025635f) {
				tmp = angle;

				if (tmp > M_PI) {
					tmp = M_BADTAU - angle;
				}

				tmp -= 0.7852731347084f;
				tmp2 = tmp * 3.8203268051147f;
				iVar8 *= 1 + tmp2;
			}

			iVar8 = chrGetPercentageOfSlowness(chr, iVar8) + 1;
			result = random() % iVar8 == 0;
		}
	}

	if (result) {
		result = chrCanSeeTarget(chr);
	}

	if (result) {
		chrRecordLastSeeTargetTime(chr);
	}

	return result;
}

bool chrIsReadyForOrders(struct chrdata *chr)
{
	if (chr->onladder) {
		return false;
	}

	switch (chr->actiontype) {
	case ACT_DIE:
	case ACT_DEAD:
	case ACT_DRUGGEDDROP:
	case ACT_DRUGGEDKO:
	case ACT_DRUGGEDCOMINGUP:
#if VERSION < VERSION_NTSC_1_0
	case ACT_ARGH:
	case 0x200:
#endif
		return false;
#if VERSION >= VERSION_NTSC_1_0
	case ACT_ARGH:
		if ((chr->chrflags & CHRCFLAG_00000200) == 0) {
			return false;
		}
		break;
#endif
	}

	return true;
}

bool chrIsDead(struct chrdata *chr)
{
	if (!chr || chr->actiontype == ACT_DIE || chr->actiontype == ACT_DEAD) {
		return true;
	}

	if (chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);

		if (g_Vars.players[playernum]->isdead) {
			return true;
		}
	}

	return false;
}

bool chrGoToProp(struct chrdata *chr, struct prop *prop, u32 goposflags)
{
	if (chrIsReadyForOrders(chr) && prop) {
		if (chrGoToRoomPos(chr, &prop->pos, prop->rooms, goposflags)) {
			return true;
		}
	}

	return false;
}

bool chrTryStop(struct chrdata *chr)
{
	if (chrIsReadyForOrders(chr)) {
		chrStop(chr);
		return true;
	}

	return false;
}

void chrPunchInflictDamage(struct chrdata *chr, s32 damage, s32 range, u8 reverse)
{
	struct prop *targetprop = chrGetTargetProp(chr);
	struct gset gset = {WEAPON_UNARMED, 0, 0, FUNC_PRIMARY};
	struct coord vector;

	if (chr->aibot) {
		gset.weaponnum = chr->aibot->weaponnum;
		gset.weaponfunc = chr->aibot->gunfunc;
	}

	if (chrIsTargetInFov(chr, 20, reverse)
			&& chrGetDistanceToTarget(chr) < range
			&& cdTestLos04(&chr->prop->pos, chr->prop->rooms, &targetprop->pos,
				CDTYPE_OBJS | CDTYPE_DOORS | CDTYPE_PATHBLOCKER | CDTYPE_BG)) {
		vector.x = targetprop->pos.x - chr->prop->pos.x;
		vector.y = 0;
		vector.z = targetprop->pos.z - chr->prop->pos.z;

		guNormalize(&vector.x, &vector.y, &vector.z);

		bgunPlayPropHitSound(&gset, targetprop, -1);

		if (targetprop->type == PROPTYPE_PLAYER || targetprop->type == PROPTYPE_CHR) {
			chrDamageByImpact(targetprop->chr, gsetGetDamage(&gset) * damage, &vector, &gset, chr->prop, 200);
		}
	}

	weaponPlayWhooshSound(gset.weaponnum, chr->prop);
}

struct punchanim {
	s32 animnum;
	u32 damage;
	s16 hitframe;
	f32 endframe;
};

struct punchanim g_HumanPunchAnims[] = {
	{ 0x027c, 5, 20, 60 },
	{ 0x027d, 5, 20, 31 },
	{ 0x027e, 5, 20, 48 },
	{ 0x027f, 5, 20, 69 },
	{ 0x0212, 5, 20, 64 },
	{ 0x0213, 5, 20, 52 },
	{ 0x0214, 5, 20, 51 },
	{ 0x020e, 5, 20, 53 },
	{ 0x020f, 5, 20, 89 },
	{ 0x0210, 5, 20, 71 },
	{ 0x0215, 5, 20, 62 },
	{ 0x0211, 5, 20, 72 },
};

struct punchanim g_SkedarPunchAnims[] = {
	{ 0x034c, 15, 25, 100 },
	{ 0x034d, 15, 25, -1  },
	{ 0x0395, 15, 25, -1  },
	{ 0x0346, 15, 25, -1  },
	{ 0x0347, 15, 25, -1  },
	{ 0x034f, 15, 25, -1  },
};

void chrTickStand(struct chrdata *chr)
{
	s32 race;
	s32 i;
	s32 j;
	s32 stack2;
	struct prop *leftgun;
	struct prop *rightgun;
	u32 stack[2];
	f32 angle;
	f32 sp74[8];
	f32 sp70;
	f32 sp6c;
	s32 tmp;
	s32 index;
	s32 sp44[8];

	if (chr->hidden & CHRHFLAG_NEEDANIM) {
		if (modelIsAnimMerging(chr->model)) {
			return;
		}

		chrChooseStandAnimation(chr, chr->act_stand.mergetime);
		chr->hidden &= ~CHRHFLAG_NEEDANIM;
	}

	if (chr->sleep > 0) {
		return;
	}

	race = CHRRACE(chr);

	if (chr->act_stand.prestand) {
		if (modelGetCurAnimFrame(chr->model) >= modelGetAnimEndFrame(chr->model)) {
			chrChooseStandAnimation(chr, 8);
			chr->act_stand.prestand = 0;
		}

		chr->sleep = 0;
		return;
	}
}

void chrFadeCorpse(struct chrdata *chr)
{
	if (chr->actiontype == ACT_DEAD || chr->actiontype == ACT_DRUGGEDKO) {
		chr->act_dead.fadenow = true;
	}
}

void chrFadeCorpseWhenOffScreen(struct chrdata *chr)
{
	if (chr->actiontype == ACT_DEAD) {
		chr->act_dead.fadewheninvis = true;
	}
}

void chrTickDead(struct chrdata *chr)
{
	struct aibot *aibot = chr->aibot;

	// If fade is active, handle it
	if (chr->act_dead.fadetimer60 >= 0) {
		chr->act_dead.fadetimer60 += g_Vars.lvupdate60;

		if (chr->act_dead.fadetimer60 >= TICKS(90)) {
			// Fade finished
			chr->fadealpha = 0;

			if (aibot) {
				botSpawn(chr, true);
			} else {
				chr->hidden |= CHRHFLAG_REAPED;
			}
		} else {
			// Still fading
			chr->fadealpha = (TICKS(90) - chr->act_dead.fadetimer60) * 255 / TICKS(90);
		}
	} else {
		// If fade has been triggered (this can happen when the corpse is on
		// screen and there's lots of other chrs around)
		if (chr->act_dead.fadenow) {
			chr->act_dead.fadetimer60 = 0;
			chrDropItemsForOwnerReap(chr);
		}

		if (chr->prop->flags & PROPFLAG_ONANYSCREENPREVTICK) {
			// Keep corpse for now
			chr->act_dead.invistimer60 = 0;
		} else {
			chr->act_dead.invistimer60 += g_Vars.lvupdate60;
		}

		if (chr->act_dead.fadewheninvis && chr->act_dead.invistimer60 >= TICKS(120)) {
			// Remove corpse (off-screen)
			if (aibot == NULL) {
				chr->hidden |= CHRHFLAG_REAPED;
			}

			chr->fadealpha = 0;

			chrDropItemsForOwnerReap(chr);
		}
	}
}

/**
 * This function is called when a chr is injured or killed. It iterates other
 * chrs within 2000 units who can see the chr and updates their chrseeshot or
 * chrseedie properties.
 *
 * The search stops once 7 chrs have been found in range, regardless of whether
 * they can see the chr, presumably to avoid doing too many expensive line of
 * sight checks in one tick. The last iterated chr index is stored and continued
 * from there next time the function is called. The function is called on
 * subsequent ticks while the chr is still in their injured or dying action.
 */
void chrAlertOthersOfInjury(struct chrdata *chr, bool dying)
{
	s32 index = 0;
	s32 numinrange = 0;
	s32 numchrs = chrsGetNumSlots();

	if (chr->actiontype == ACT_ARGH) {
		index = chr->act_argh.notifychrindex;
	} else if (chr->actiontype == ACT_DIE || chr->actiontype == ACT_DRUGGEDDROP) {
		index = chr->act_die.notifychrindex;
	} else if (chr->actiontype == ACT_DEAD) {
		index = chr->act_dead.notifychrindex;
	}

	for (; index < numchrs && numinrange < 7; index++) {
		struct chrdata *loopchr = &g_ChrSlots[index];

		if (loopchr->model && loopchr->prop && (loopchr->prop->flags & PROPFLAG_ENABLED)) {
			f32 xdiff = loopchr->prop->pos.x - chr->prop->pos.x;
			f32 ydiff = loopchr->prop->pos.y - chr->prop->pos.y;
			f32 zdiff = loopchr->prop->pos.z - chr->prop->pos.z;

			if (xdiff * xdiff + ydiff * ydiff + zdiff * zdiff < 4000000.0f) {
				numinrange++;

				if (chrCanSeePos(loopchr, &chr->prop->pos, chr->prop->rooms)) {
					if (dying == false) {
						loopchr->chrseeshot = chr->chrnum;
					} else {
						loopchr->chrseedie = chr->chrnum;
					}
				}
			}
		}
	}

	if (chr->actiontype == ACT_ARGH) {
		chr->act_argh.notifychrindex = index;
	} else if (chr->actiontype == ACT_DIE || chr->actiontype == ACT_DRUGGEDDROP) {
		chr->act_die.notifychrindex = index;
	} else if (chr->actiontype == ACT_DEAD) {
		chr->act_dead.notifychrindex = index;
	}
}

void chrTickDie(struct chrdata *chr)
{
	struct model *model = chr->model;
	u32 race = CHRRACE(chr);

	u16 thuds[] = {
		SFX_THUD_808D,
		SFX_THUD_808E,
		SFX_THUD_808F,
		SFX_THUD_8090,
		SFX_THUD_8091,
		SFX_THUD_8092,
		SFX_THUD_8093,
		SFX_THUD_8094,
		SFX_THUD_8095,
		SFX_THUD_8096,
		SFX_THUD_8097,
	};

	u16 specialdiesounds[] = {
#if VERSION >= VERSION_NTSC_1_0
		SFX_M1_NOOO, // "Noooo!"
		SFX_M1_SCREAM, // Death scream
		SFX_M2_NOOO, // "Noooo!"
		SFX_M2_NOOO, // "Noooo!"
		SFX_M1_SCREAM, // Death scream
#else
		SFX_0313,
		SFX_034C,
		SFX_0411,
		SFX_0411,
		SFX_034C,
#endif
		SFX_THUD_8092,
		SFX_THUD_8093,
		SFX_THUD_8094,
		SFX_THUD_8095,
		SFX_THUD_8096,
		SFX_THUD_8097,
	};

	static s32 thudindex = 0;

	// Human or Skedar
	// If due, play thud 1 sound
	if (chr->act_die.thudframe1 >= 0 && modelGetCurAnimFrame(model) >= chr->act_die.thudframe1) {
		if (chr->specialdie == 0) {
			propsnd0f0939f8(NULL, chr->prop, thuds[thudindex], -1,
					-1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1);
		} else if (chr->specialdie != SPECIALDIE_OVERRAILING) {
			propsnd0f0939f8(NULL, chr->prop, specialdiesounds[chr->specialdie - 1], -1,
					-1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1);
		}

		thudindex++;

		if (thudindex > 10) {
			thudindex = 0;
		}

		chr->act_die.thudframe1 = -1;
	}

	// If due, play thud 2 sound
	if (chr->act_die.thudframe2 >= 0 && modelGetCurAnimFrame(model) >= chr->act_die.thudframe2) {
		if (chr->specialdie < 5) {
			propsnd0f0939f8(NULL, chr->prop, SFX_THUD_808E, -1,
					-1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1);
		} else {
			propsnd0f0939f8(NULL, chr->prop, thuds[thudindex], -1,
					-1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1);
		}

		thudindex++;

		if (thudindex > 10) {
			thudindex = 0;
		}

		chr->act_die.thudframe2 = -1;
	}

	// Check for end of death animation and switch to ACT_DEAD
	if (modelGetCurAnimFrame(model) >= modelGetAnimEndFrame(model)) {
		if (CHRRACE(chr) == RACE_HUMAN && modelGetAnimNum(model) == ANIM_DEATH_STOMACH_LONG) {
			modelSetAnimation(model, ANIM_003C, !modelIsFlipped(model), 50, 0.3, animGetNumFrames(ANIM_003C) - 51.0f);
			modelSetAnimSpeed(model, 0.5, animGetNumFrames(ANIM_003C) - 51.0f);
			return;
		}

		chrBeginDead(chr);
	}

	chrAlertOthersOfInjury(chr, true);
}

void chrTickDruggedComingUp(struct chrdata *chr)
{
	u16 thuds[] = {
		SFX_THUD_808D,
		SFX_THUD_808E,
		SFX_THUD_808F,
		SFX_THUD_8090,
		SFX_THUD_8091,
		SFX_THUD_8092,
		SFX_THUD_8093,
		SFX_THUD_8094,
		SFX_THUD_8095,
		SFX_THUD_8096,
		SFX_THUD_8097,
	};

	chr->act_druggedcomingup.timer60 += g_Vars.lvupdate60;

	if (chr->act_druggedcomingup.timer60 > 0) {
		struct animtablerow *row;
		s32 race = CHRRACE(chr);
		struct model *model = chr->model;
		s32 i = 0;
		bool done = false;
		struct prop *weapon;

		chrUncloak(chr, true);

		chr->actiontype = ACT_DRUGGEDDROP;

		while (!done) {
			if (i >= 0
					&& g_AnimTablesByRace[race][i].deathanims != NULL
					&& g_AnimTablesByRace[race][i].deathanimcount > 0) {
				s32 index = random() % g_AnimTablesByRace[race][i].deathanimcount;
				row = &g_AnimTablesByRace[race][i].deathanims[index];

				chr->act_die.thudframe1 = row->thudframe1;
				chr->act_die.thudframe2 = row->thudframe2;

				modelSetAnimationWithMerge(model, row->animnum, row->flip, 0, row->speed, 16, true);

				if (row->endframe >= 0) {
					modelSetAnimEndFrame(model, row->endframe);
				}

				done = true;
			}

			if (!done) {
				i++;

				if (g_AnimTablesByRace[race][i].hitpart == -1) {
					done = true;
				}
			}
		}

		weapon = chr->weapons_held[HAND_RIGHT];

		if (weapon && (weapon->obj->flags & OBJFLAG_AIUNDROPPABLE) == 0) {
			objSetDropped(weapon, DROPTYPE_DEFAULT);
			chr->hidden |= CHRHFLAG_00000001;
		}

		weapon = chr->weapons_held[HAND_LEFT];

		if (weapon && (weapon->obj->flags & OBJFLAG_AIUNDROPPABLE) == 0) {
			objSetDropped(weapon, DROPTYPE_DEFAULT);
			chr->hidden |= CHRHFLAG_00000001;
		}

		chrDropConcealedItems(chr);
	}
}

void chrTickDruggedDrop(struct chrdata *chr)
{
	struct model *model = chr->model;

	u16 thuds[] = {
		SFX_THUD_808D,
		SFX_THUD_808E,
		SFX_THUD_808F,
		SFX_THUD_8090,
		SFX_THUD_8091,
		SFX_THUD_8092,
		SFX_THUD_8093,
		SFX_THUD_8094,
		SFX_THUD_8095,
		SFX_THUD_8096,
		SFX_THUD_8097,
	};

	static s32 thudindex = 0;

	// If due, play thud 1 sound
	if (chr->act_die.thudframe1 >= 0 && modelGetCurAnimFrame(model) >= chr->act_die.thudframe1) {
		propsnd0f0939f8(NULL, chr->prop, thuds[thudindex], -1,
				-1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1);

		thudindex++;

		if (thudindex > 10) {
			thudindex = 0;
		}

		chr->act_die.thudframe1 = -1;
	}

	// If due, play thud 2 sound
	if (chr->act_die.thudframe2 >= 0 && modelGetCurAnimFrame(model) >= chr->act_die.thudframe2) {
		propsnd0f0939f8(NULL, chr->prop, thuds[thudindex], -1,
				-1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1);

		thudindex++;

		if (thudindex > 10) {
			thudindex = 0;
		}

		chr->act_die.thudframe2 = -1;
	}

	// If falling animation finished, assign ACT_DRUGGEDKO
	if (modelGetCurAnimFrame(model) >= modelGetAnimEndFrame(model)) {
		chr->actiontype = ACT_DRUGGEDKO;
		chr->act_dead.fadetimer60 = chr->aibot ? 0 : -1;
		chr->act_dead.fadenow = false;
		chr->act_dead.fadewheninvis = false;
		chr->act_dead.invistimer60 = 0;
		chr->act_dead.notifychrindex = 0;
		chr->sleep = 0;
	}

	chrAlertOthersOfInjury(chr, true);
}

void chrTickDruggedKo(struct chrdata *chr)
{
	bool reap = false;

	// If fade is active, handle it
	if (chr->act_dead.fadetimer60 >= 0) {
		chr->act_dead.fadetimer60 += g_Vars.lvupdate60;

		if (chr->act_dead.fadetimer60 >= TICKS(90)) {
			reap = true;
		} else {
			chr->fadealpha = (TICKS(90) - chr->act_dead.fadetimer60) * 255 / TICKS(90);
		}
	} else if ((chr->chrflags & CHRCFLAG_KEEPCORPSEKO) == 0) {
		if (chr->act_dead.fadenow) {
			chr->act_dead.fadetimer60 = 0;
		}

		if (chr->prop->flags & PROPFLAG_ONANYSCREENPREVTICK) {
			chr->act_dead.invistimer60 = 0;
		} else {
			chr->act_dead.invistimer60 += g_Vars.lvupdate60;
		}

		if (chr->act_dead.fadewheninvis && chr->act_dead.invistimer60 >= TICKS(120)) {
			reap = true;
		}
	}

	if (reap) {
		chr->fadealpha = 0;
		chr->hidden |= CHRHFLAG_REAPED;
		chrDropItemsForOwnerReap(chr);
	}
}

void chrTickArgh(struct chrdata *chr)
{
	struct model *model = chr->model;

	if (modelGetCurAnimFrame(model) >= modelGetAnimEndFrame(model)) {
		chrRecordLastSeeTargetTime(chr);

		if (CHRRACE(chr) == RACE_HUMAN && modelGetAnimNum(model) == ANIM_DEATH_STOMACH_LONG) {
			func0f02ed28(chr, 26);
		} else {
			chrStop(chr);
		}
	}

	chrAlertOthersOfInjury(chr, false);
}

void chrCreateFireslot(struct chrdata *chr, s32 handnum, bool withsound, bool withbeam, struct coord *from, struct coord *to)
{
	struct prop *weaponprop;
	struct weaponobj *weapon;
	s32 weaponnum;
	bool playsound = false;
	u8 duration;
	u16 soundnum;

	weaponprop = chrGetHeldProp(chr, handnum);

	if (weaponprop) {
		weapon = weaponprop->weapon;
		weaponnum = weapon->weaponnum;
		duration = gsetGetFireslotDuration(&weapon->gset);
		soundnum = gsetGetSingleShootSound(&weapon->gset);

		if (chr->fireslots[handnum] < 0) {
			chr->fireslots[handnum] = bgunAllocateFireslot();
		}

		if (chr->fireslots[handnum] >= 0) {
			struct fireslot *fireslot = &g_Fireslots[chr->fireslots[handnum]];

			if (withsound) {
				if (duration > 0) {
#if VERSION >= VERSION_NTSC_1_0
					if (chr->hidden2 & CHRH2FLAG_0020)
#else
					if (chr->hidden & CHRHFLAG_00000080)
#endif
					{
						playsound = false;
					} else {
						if (g_Vars.lvframe60 > fireslot->endlvframe) {
							playsound = true;
						} else {
							playsound = false;
						}
					}
				} else {
					playsound = true;
				}
			}

			if (playsound) {
#if VERSION >= VERSION_NTSC_1_0
				propsnd0f0939f8(NULL, chr->prop, soundnum, -1, -1, 0x400, 4, 0x11, NULL, -1, NULL, -1, -1, -1, -1);
				fireslot->endlvframe = (u32)g_Vars.lvframe60 + duration;
				chr->hidden2 |= CHRH2FLAG_0020;
#else
				propsnd0f0939f8(NULL, chr->prop, soundnum, -1, -1, 0x400, 4, 0, NULL, -1, NULL, -1, -1, -1, -1);
				fireslot->endlvframe = (u32)g_Vars.lvframe60 + duration;
				chr->hidden |= CHRHFLAG_00000080;

				if (chr);
#endif
			}

			if (withbeam) {
				beamCreate(&fireslot->beam, weaponnum, from, to);
			}
		}
	}
}

/**
 * Returns the chr's turn angle difference to 360 degrees, in radians.
 */
f32 chrGetInverseTheta(struct chrdata *chr)
{
	if (chr->aibot) {
		return chr->aibot->unk0b0;
	}

	if (chr->model == NULL && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		struct player *player = g_Vars.players[playermgrGetPlayerNumByProp(chr->prop)];
		f32 angle = (360.0f - player->vv_theta) * 0.017450513318181f;

		if (angle >= M_BADTAU) {
			angle -= M_BADTAU;
		} else if (angle < 0) {
			angle += M_BADTAU;
		}

		return angle;
	}

	return model0001ae44(chr->model);
}

void chrSetLookAngle(struct chrdata *chr, f32 angle)
{
	if (chr->aibot) {
		chr->aibot->unk0b0 = angle;
	} else {
		model0001ae90(chr->model, angle);
	}
}

f32 func0f03e578(struct chrdata *chr)
{
	if (chr->aibot) {
		return chr->aibot->unk0a4;
	}

	return model0001ae44(chr->model);
}

void func0f03e5b0(struct chrdata *chr, f32 arg1)
{
	if (chr->aibot) {
		chr->aibot->unk0a4 = arg1;
	} else {
		model0001ae90(chr->model, arg1);
	}
}

f32 chrGetAimAngle(struct chrdata *chr)
{
	f32 angle = chrGetInverseTheta(chr) + chr->aimsideback;
	f32 offset = 0;

	if (angle >= M_BADTAU) {
		angle -= M_BADTAU;
	} else if (angle < 0) {
		angle += M_BADTAU;
	}

	if (chr->aibot) {
		if (chr->aibot->unk068) {
			// empty
		}
	} else if (chr->actiontype == ACT_ATTACK
			|| chr->actiontype == ACT_BOT_ATTACKSTAND
			|| chr->actiontype == ACT_BOT_ATTACKKNEEL
			|| chr->actiontype == ACT_BOT_ATTACKSTRAFE) {
		offset = chr->act_attack.animcfg->unk0c;
	} else if (chr->prop->type == PROPTYPE_PLAYER) {
		offset += g_Vars.players[playermgrGetPlayerNumByProp(chr->prop)]->angleoffset;
	}

	if (offset) {
		if (chr->model->anim->flip) {
			offset = M_BADTAU - offset;
		}

		angle += offset;

		if (angle >= M_BADTAU) {
			angle -= M_BADTAU;
		} else if (angle < M_BADTAU) {
			angle += M_BADTAU;
		}
	}

	return angle;
}

f32 chrGetPitchAngle(struct chrdata *chr)
{
	f32 sum = chr->aimuprshoulder + chr->aimupback;

	if (sum < 0) {
		sum += M_BADTAU;
	}

	return sum;
}

/**
 * Turn the chr slightly towards their target.
 */
s32 chrTurn(struct chrdata *chr, s32 turning, f32 endanimframe, f32 speed, f32 toleranceangle)
{
	if (turning != TURNSTATE_OFF) {
		struct model *model = chr->model;
		f32 curframe = modelGetCurAnimFrame(model);
		u32 stack;
		f32 finalangle = chrGetInverseTheta(chr);
		f32 remainingangle;
		f32 increment = M_BADTAU / 100.0f * speed * g_Vars.lvupdate60f * model->anim->playspeed;

		if (chr->aibot) {
			struct prop *target = chrGetTargetProp(chr);
			remainingangle = chrGetAngleToPos(chr, &target->pos);
		} else if (chr->actiontype == ACT_ATTACK
				|| chr->actiontype == ACT_BOT_ATTACKSTAND
				|| chr->actiontype == ACT_BOT_ATTACKKNEEL
				|| chr->actiontype == ACT_BOT_ATTACKSTRAFE) {
			remainingangle = chrGetAttackEntityRelativeAngle(chr, chr->act_attack.flags, chr->act_attack.entityid);
		} else if (chr->actiontype == ACT_STAND) {
			remainingangle = chrGetAttackEntityRelativeAngle(chr, chr->act_stand.flags, chr->act_stand.entityid);
		} else {
			struct prop *target = chrGetTargetProp(chr);
			remainingangle = chrGetAngleToPos(chr, &target->pos);
		}

		remainingangle -= toleranceangle;

		if (remainingangle < 0) {
			remainingangle += M_BADTAU;
		}

		if (increment > remainingangle || M_BADTAU - increment < remainingangle) {
			// Close enough to stop
			finalangle += remainingangle;

			if (finalangle >= M_BADTAU) {
				finalangle -= M_BADTAU;
			}

			chrSetLookAngle(chr, finalangle);
			turning = TURNSTATE_ONTARGET;
		} else if (remainingangle < M_PI) {
			// Turning in one direction
			finalangle += increment;

			if (finalangle >= M_BADTAU) {
				finalangle -= M_BADTAU;
			}

			chrSetLookAngle(chr, finalangle);
		} else {
			// Turning in the other direction
			finalangle -= increment;

			if (finalangle < 0) {
				finalangle += M_BADTAU;
			}

			chrSetLookAngle(chr, finalangle);
		}

		if (curframe >= endanimframe) {
			turning = TURNSTATE_OFF;
		}
	}

	return turning;
}

bool func0f03e9f4(struct chrdata *chr, struct attackanimconfig *animcfg, bool firingleft, bool firingright, f32 arg4)
{
	f32 shootrotx = 0.0f;
	f32 aimendsideback = 0.0f;
	u32 flags = ATTACKFLAG_AIMATTARGET;
	s32 entityid = 0;
	bool result = true;

	if (!chr->aibot) {
		if (chr->actiontype == ACT_ATTACK
				|| chr->actiontype == ACT_BOT_ATTACKSTAND
				|| chr->actiontype == ACT_BOT_ATTACKKNEEL
				|| chr->actiontype == ACT_BOT_ATTACKSTRAFE) {
			flags = chr->act_attack.flags;
			entityid = chr->act_attack.entityid;
		} else if (chr->actiontype == ACT_STAND) {
			flags = chr->act_stand.flags;
			entityid = chr->act_stand.entityid;
		}
	}

	if ((flags & ATTACKFLAG_AIMFORWARD) == 0) {
		f32 sp178;
		f32 sp174;
		f32 sp170;
		struct prop *chrprop = chr->prop;
		struct prop *targetprop = chrGetTargetProp(chr);
		f32 sqdist;
		bool holdturn;
		struct coord targetpos;
		s16 targetrooms[8];

		sp178 = targetprop->pos.x - chrprop->pos.x;
		sp174 = targetprop->pos.y - chrprop->pos.y;
		sp170 = targetprop->pos.z - chrprop->pos.z;

		sqdist = sp178 * sp178 + sp174 * sp174 + sp170 * sp170;

		if (chr->aibot) {
			holdturn = false;
		} else if (flags & ATTACKFLAG_AIMATTARGET) {
			if (flags & ATTACKFLAG_DONTTURN) {
				holdturn = true;
			} else {
				holdturn = chrCanSeeTarget(chr);
			}
		} else {
			holdturn = true;
		}

		if ((flags & ATTACKFLAG_AIMATTARGET) && targetprop->type == PROPTYPE_PLAYER) {
			f32 eyeheight = g_Vars.players[playermgrGetPlayerNumByProp(targetprop)]->vv_eyeheight;

			targetpos.x = targetprop->pos.x;
			targetpos.y = targetprop->pos.y;
			targetpos.z = targetprop->pos.z;

			if (chr->aibot) {
				sp174 -= eyeheight * (0.4f + (0.05f * RANDOMFRAC() * arg4));
			} else if (chr->chrflags & CHRCFLAG_LOSEXTRAHEIGHT) {
				if (sqdist < 400.0f * 400.0f) {
					if (chrprop->pos.y < targetpos.y - 2.0f * eyeheight) {
						sp174 -= eyeheight * (0.55f + 0.1f * RANDOMFRAC() * arg4);
					} else if (chrprop->pos.y > targetpos.y - eyeheight * 0.5f) {
						sp174 -= eyeheight * (0.15f + 0.1f * RANDOMFRAC() * arg4);
					} else {
						sp174 = (RANDOMFRAC() * 0.1f * arg4 + 1.0f) * 40.0f;
					}
				} else {
					sp174 += eyeheight * (0.025f - 0.05f * RANDOMFRAC() * arg4);
				}
			} else if (sqdist > 1000.0f * 1000.0f) {
				if ((random() % 3) == 0) {
					sp174 += eyeheight * (0.05f + 0.1f * RANDOMFRAC() * arg4);
				} else {
					sp174 -= eyeheight * (0.05f + 0.55f * RANDOMFRAC() * arg4);
				}
			} else {
				if (chrprop->pos.y < targetpos.y - eyeheight) {
					sp174 -= eyeheight * (0.55f + 0.1f * RANDOMFRAC() * arg4);
				} else if (chrprop->pos.y > targetpos.y - eyeheight * 0.5f) {
					sp174 -= eyeheight * (0.15f + 0.1f * RANDOMFRAC() * arg4);
				} else {
					sp174 = (RANDOMFRAC() * 0.1f * arg4 - 0.05f) * eyeheight;
				}
			}
		} else {
			struct coord chrpos;

			modelGetRootPosition(chr->model, &chrpos);
			chrGetAttackEntityPos(chr, flags, entityid, &targetpos, targetrooms);

			sp178 = targetpos.x - chrpos.x;
			sp174 = targetpos.y - chrpos.y;
			sp170 = targetpos.z - chrpos.z;
		}

		if ((flags & ATTACKFLAG_NOVERTICAL) == 0) {
			shootrotx = atan2f(sp174, sqrtf(sp178 * sp178 + sp170 * sp170));

			if (shootrotx >= M_PI) {
				shootrotx -= M_BADTAU;
			}
		}

		if (holdturn) {
			f32 aimangle = chrGetAimAngle(chr);
			struct prop *gunprop;
			struct modelnode *posnode;
			struct model *gunmodel;
			struct coord sp118;
			s32 sp114;
			struct modelnode *burstnode;
			struct modelrwdata_chrinfo *chrrwdata;
			Mtxf *sp108;
			Mtxf spc8;
			struct modelrodata_chrgunfire *burstrodata;
			struct coord spb8;
			Mtxf *spb4;
			Mtxf *spb0;
			Mtxf sp70;
			Mtxf *sp6c;
			struct coord sp60;
			struct coord sp54;
			struct coord sp48;
			f32 anglev;

			if (flags & ATTACKFLAG_AIMATTARGET) {
				if (firingright) {
					gunprop = chrGetHeldProp(chr, HAND_RIGHT);
				} else {
					gunprop = chrGetHeldProp(chr, HAND_LEFT);
				}

				if (PLAYERCOUNT() == 1
						&& gunprop
						&& (gunprop->flags & PROPFLAG_ONANYSCREENPREVTICK)
						&& sqdist < 1000.0f * 1000.0f) {
					struct defaultobj *gun = gunprop->obj;
					gunmodel = gun->model;
					sp114 = 0;
					burstnode = modelGetPart(gunmodel->filedata, MODELPART_CHRGUN_GUNFIRE);

					if (burstnode) {
						sp108 = model0001a5cc(gunmodel, burstnode, 0);
						burstrodata = &burstnode->rodata->chrgunfire;
						spb4 = cam0f0b53a4((u8 *)sp108);

						if (spb4) {
							mtx00016798(sp108, &spc8);
							mtx00015be0(spb4, &spc8);

							spb8.x = burstrodata->pos.x;
							spb8.y = burstrodata->pos.y;
							spb8.z = burstrodata->pos.z;

							mtx4TransformVecInPlace(&spc8, &spb8);

							sp114 = 1;
							sp118.x = spb8.x;
							sp118.y = spb8.y;
							sp118.z = spb8.z;
						}
					} else {
						posnode = modelGetPart(gunmodel->filedata, MODELPART_CHRGUN_0001);

						if (posnode) {
							spb0 = model0001a5cc(gunmodel, posnode, 0);
							sp6c = cam0f0b53a4((u8 *)spb0);

							if (sp6c) {
								mtx00016798(spb0, &sp70);
								mtx00015be0(sp6c, &sp70);

								sp114 = 1;
								sp118.x = sp70.m[3][0];
								sp118.y = sp70.m[3][1];
								sp118.z = sp70.m[3][2];
							}
						}
					}

					if (sp114) {
						sp54.x = sinf(aimangle);
						sp54.y = 0.0f;
						sp54.z = cosf(aimangle);

						sp48.x = chrprop->pos.x - sp170;
						sp48.y = chrprop->pos.y;
						sp48.z = chrprop->pos.z + sp178;

						func0f02e3dc(&chrprop->pos, &sp48, &sp118, &sp54, &sp60);

						sp178 = targetpos.x - sp60.x;
						sp170 = targetpos.z - sp60.z;
					}
				}
			}

			anglev = atan2f(sp178, sp170);
			aimendsideback = anglev - aimangle;

			if (anglev < aimangle) {
				aimendsideback += M_BADTAU;
			}

			chrrwdata = modelGetNodeRwData(chr->model, chr->model->filedata->rootnode);

			if (chrrwdata->unk5c > 0.0f) {
				aimendsideback -= chrrwdata->unk5c * chrrwdata->unk58;

				if (aimendsideback < 0.0f) {
					aimendsideback += M_BADTAU;
				}

				if (aimendsideback >= M_BADTAU) {
					aimendsideback -= M_BADTAU;
				}
			}

			if (!chr->aibot
					&& (flags & ATTACKFLAG_AIMATTARGET)
					&& ((flags & (ATTACKFLAG_AIMONLY | ATTACKFLAG_DONTTURN)) == 0)
					&& targetprop->type == PROPTYPE_PLAYER) {
				if (1);
				aimendsideback += chrGetAimLimitAngle(sqdist) * 0.5f * sinf((((s32) (g_Vars.lvframe60 * chr->model->anim->playspeed) + chr->chrnum) % 60) * 0.10470308f);

				if (aimendsideback < 0.0f) {
					aimendsideback += M_BADTAU;
				}

				if (aimendsideback >= M_BADTAU) {
					aimendsideback -= M_BADTAU;
				}
			}

			if (aimendsideback >= M_PI) {
				aimendsideback -= M_BADTAU;
			}

			aimendsideback += chr->aimsideback;

			if (animcfg) {
				if (chr->model->anim->flip) {
					if (aimendsideback < -animcfg->unk38) {
						aimendsideback = -animcfg->unk38;
						result = false;
					} else if (aimendsideback > -animcfg->unk3c) {
						aimendsideback = -animcfg->unk3c;
						result = false;
					}
				} else {
					if (aimendsideback > animcfg->unk38) {
						aimendsideback = animcfg->unk38;
						result = false;
					} else if (aimendsideback < animcfg->unk3c) {
						aimendsideback = animcfg->unk3c;
						result = false;
					}
				}
			}
		}
	}

	chrCalculateAimEndProperties(chr, animcfg, firingleft, firingright, shootrotx);

	chr->aimendsideback = aimendsideback;
	chr->aimendcount = 10;

	return result;
}

void chrCalculateAimEndProperties(struct chrdata *chr, struct attackanimconfig *animcfg, bool firingleft, bool firingright, f32 shootrotx)
{
	f32 aimfreeshoulder = 0;
	f32 aimendback = 0;
	f32 aimgunshoulder = shootrotx;

	if (animcfg != NULL) {
		if (shootrotx > animcfg->unk30) {
			aimendback = shootrotx - animcfg->unk30;
			aimgunshoulder = animcfg->unk30;
		} else if (shootrotx < animcfg->unk34) {
			aimendback = shootrotx - animcfg->unk34;
			aimgunshoulder = animcfg->unk34;
		}

		if (aimgunshoulder > 0) {
			aimfreeshoulder = animcfg->unk40 * aimgunshoulder;
		} else {
			aimfreeshoulder = animcfg->unk44 * aimgunshoulder;
		}
	}

	if (firingright) {
		chr->aimendrshoulder = aimgunshoulder;

		if (firingleft) {
			chr->aimendlshoulder = aimgunshoulder;
		} else {
			chr->aimendlshoulder = aimfreeshoulder;
		}
	} else {
		chr->aimendrshoulder = aimfreeshoulder;
		chr->aimendlshoulder = aimgunshoulder;
	}

	chr->aimendback = aimendback;
}

void chrResetAimEndProperties(struct chrdata *chr)
{
	chr->aimendcount = 10;
	chr->aimendrshoulder = 0;
	chr->aimendlshoulder = 0;
	chr->aimendback = 0;
	chr->aimendsideback = 0;
}

void chrSetFiring(struct chrdata *chr, s32 hand, bool firing)
{
	struct prop *prop = chrGetHeldProp(chr, hand);

	chr->prop->forcetick = firing ? true : false;

	if (prop) {
		weaponSetGunfireVisible(prop, firing, chr->prop->rooms[0]);
	}
}

void chrStopFiring(struct chrdata *chr)
{
	u8 race = CHRRACE(chr);

	if (chr->aibot == NULL) {
		chrSetFiring(chr, HAND_RIGHT, false);
		chrSetFiring(chr, HAND_LEFT, false);

		chrResetAimEndProperties(chr);

		chr->fireslots[0] = bgunFreeFireslot(chr->fireslots[0]);
		chr->fireslots[1] = bgunFreeFireslot(chr->fireslots[1]);
	}
}

void chrSetHandFiring(struct chrdata *chr, s32 hand, bool firing)
{
	if (firing) {
		if (hand == HAND_LEFT) {
			chr->hidden |= CHRHFLAG_FIRINGLEFT;
		} else {
			chr->hidden |= CHRHFLAG_FIRINGRIGHT;
		}
	} else {
		if (hand == HAND_LEFT) {
			chr->hidden &= ~CHRHFLAG_FIRINGLEFT;
		} else {
			chr->hidden &= ~CHRHFLAG_FIRINGRIGHT;
		}
	}

	if (!firing) {
		chrSetFiring(chr, hand, false);
	}
}

f32 chrGetAimLimitAngle(f32 sqdist)
{
	if (sqdist > 1600 * 1600) {
		return 0.018752790987492f;
	}

	if (sqdist > 800 * 800) {
		return 0.03761787340045f;
	}

	if (sqdist > 400 * 400) {
		return 0.07478791475296f;
	}

	if (sqdist > 200 * 200) {
		return 0.14957582950592f;
	}

	return 0.2512874007225f;
}

/**
 * Calculate whether a chr's shot hits their target on this tick.
 *
 * Each chr maintains a shotbondsum property which is a float ranging from
 * 0 to 1. Each time this function is called, the value is increased slightly
 * based on the chr's accuracy and other factors. Once it reaches 1, the target
 * is considered to be hit and the value is reset to 0.
 *
 * The function writes to the angleokptr argument if the angle to their target
 * is within range, and writes to the hit argument to indicate if the target is
 * being hit or not.
 */
void chrCalculateHit(struct chrdata *chr, bool *angleokptr, bool *hit, struct gset *gset)
{
	struct prop *prop;
	struct prop *target;
	f32 xdist;
	f32 ydist;
	f32 zdist;
	f32 angletotarget;
	f32 angleaiming;
	f32 anglediff;
	f32 limitangle;
	bool angleok;
	u32 stack;
	f32 taperdist;
	f32 sqdist;

	taperdist = 300;

	// Check that the chr's aim angle is within an acceptable range to their
	// target.
	prop = chr->prop;
	target = chrGetTargetProp(chr);

	xdist = target->pos.x - prop->pos.x;
	ydist = target->pos.y - prop->pos.y;
	zdist = target->pos.z - prop->pos.z;

	angletotarget = atan2f(xdist, zdist);
	angleaiming = chrGetAimAngle(chr);
	anglediff = angletotarget - angleaiming;

	sqdist = xdist * xdist + ydist * ydist + zdist * zdist;
	limitangle = chrGetAimLimitAngle(sqdist);

	if (anglediff < 0) {
		anglediff += M_BADTAU;
	}

	angleok = anglediff < limitangle || anglediff > M_BADTAU - limitangle;

	*angleokptr = angleok;
	*hit = false;

	// Determine the distance at which accuracy starts to taper off
	switch (gset->weaponnum) {
	case WEAPON_FALCON2:
	case WEAPON_FALCON2_SILENCER:
	case WEAPON_MAULER:
	case WEAPON_PHOENIX:
	case WEAPON_DY357MAGNUM:
	case WEAPON_DY357LX:
	case WEAPON_CMP150:
	case WEAPON_CYCLONE:
	case WEAPON_CALLISTO:
	case WEAPON_RCP120:
	case WEAPON_LAPTOPGUN:
	case WEAPON_DRAGON:
	case WEAPON_K7AVENGER:
	case WEAPON_AR34:
	case WEAPON_SUPERDRAGON:
	case WEAPON_SHOTGUN:
	case WEAPON_REAPER:
	case WEAPON_DEVASTATOR:
	case WEAPON_ROCKETLAUNCHER:
	case WEAPON_SLAYER:
	case WEAPON_COMBATKNIFE:
	case WEAPON_CROSSBOW:
	case WEAPON_TRANQUILIZER:
	case WEAPON_LASER:
	case WEAPON_GRENADE:
	case WEAPON_NBOMB:
	case WEAPON_TIMEDMINE:
	case WEAPON_PROXIMITYMINE:
	case WEAPON_REMOTEMINE:
	case WEAPON_COMBATBOOST:
	case WEAPON_PP9I:
	case WEAPON_CC13:
	case WEAPON_KL01313:
	case WEAPON_KF7SPECIAL:
	case WEAPON_ZZT:
	case WEAPON_DMC:
	case WEAPON_AR53:
	case WEAPON_RCP45:
	case WEAPON_PSYCHOSISGUN:
	default:
		// Use default distance (300)
		break;
	case WEAPON_FALCON2_SCOPE:
	case WEAPON_MAGSEC4:
		taperdist = 600;
		break;
	case WEAPON_SNIPERRIFLE:
	case WEAPON_FARSIGHT:
		taperdist = 1200;
		break;
	}

	if (angleok) {
		f32 dist = sqrtf(xdist * xdist + ydist * ydist + zdist * zdist);
		f32 accuracy = 0.16f;

		// Decrease accuracy if further than taperdist
		if (dist > taperdist) {
			accuracy *= taperdist / dist;
		}

		// Scale accuracy up or down based on chr's accuracyrating
		if (chr->accuracyrating > 0) {
			accuracy *= 1 + chr->accuracyrating * 0.1f;
		} else if (chr->accuracyrating < 0) {
			if (chr->accuracyrating <= -100) {
				accuracy = 0;
			} else {
				accuracy *= (chr->accuracyrating + 100) * 0.01f;
			}
		}

		// Apply difficulty multiplier (solo A = 0.6, SA = 0.8, PA = 1.175)
		accuracy *= g_EnemyAccuracyScale;

		// If the weapon fires more than once per tick, double the value to
		// account for it. No weapons meet this criteria, however.
		if (weaponGetNumTicksPerShot(gset->weaponnum, gset->weaponfunc) <= 0) {
			accuracy += accuracy;
		}

		// Shotgun doubles the value due to more bullets
		if (gset->weaponnum == WEAPON_SHOTGUN) {
			accuracy += accuracy;
		}

		chr->shotbondsum += accuracy;

		if (chr->hidden & CHRHFLAG_PERFECTACCURACY) {
			chr->shotbondsum += 1.1f;
		}

		if (chr->shotbondsum >= 1) {
			*hit = true;
			chr->shotbondsum = 0;
		}
	}
}

/**
 * If the chr's gun is on screen, populate gunpos with the world coordinates of
 * their gun and return true.
 *
 * If the chr's gun is off screen, return false without populating gunpos.
 */
bool chrGetGunPos(struct chrdata *chr, s32 handnum, struct coord *gunpos)
{
	struct prop *weaponprop = chrGetHeldProp(chr, handnum);
	struct defaultobj *obj;
	struct model *model;
	bool result = false;
	struct modelnode *part0;
	struct modelnode *part1;
	Mtxf *spac;
	Mtxf sp6c;
	struct modelrodata_chrgunfire *rodata;
	Mtxf *sp64;
	Mtxf sp24;

	if (weaponprop) {
		obj = weaponprop->obj;
		model = obj->model;

		if ((chr->prop->flags & PROPFLAG_ONTHISSCREENTHISTICK) && (weaponprop->flags & PROPFLAG_ONTHISSCREENTHISTICK)) {
			if ((part0 = modelGetPart(model->filedata, MODELPART_0000))) {
				spac = model0001a5cc(model, part0, 0);
				rodata = &part0->rodata->chrgunfire;

				gunpos->x = rodata->pos.x;
				gunpos->y = rodata->pos.y;
				gunpos->z = rodata->pos.z;

				mtx00015be4(camGetProjectionMtxF(), spac, &sp6c);
				mtx4TransformVecInPlace(&sp6c, gunpos);
				result = true;
			} else if ((part1 = modelGetPart(model->filedata, MODELPART_0001))) {
				sp64 = model0001a5cc(model, part1, 0);

				mtx00015be4(camGetProjectionMtxF(), sp64, &sp24);

				gunpos->x = sp24.m[3][0];
				gunpos->y = sp24.m[3][1];
				gunpos->z = sp24.m[3][2];

				result = true;
			}
		}
	}

	return result;
}

/**
 * For a shielded chr, determine which model node has been shot and populate the
 * last 4 pointer arguments with information about the hit.
 *
 * Shield hits are calculated using the bounding box of each body part.
 * This gives a bit of padding around the chr which can register as a hit.
 *
 * nodeptr    - will be populated with a pointer to the bbox model node.
 * hitpartptr - will be populated with the HITPART constant value.
 * modelptr   - will be populated with a pointer to the chr's model.
 * sideptr    - will be populated with an index in the range 0-5 which
 *              represents which side of the node's bounding box was hit.
 */
void chrCalculateShieldHit(struct chrdata *chr, struct coord *pos, struct coord *vector,
		struct modelnode **nodeptr, s32 *hitpartptr, struct model **modelptr, s32 *sideptr)
{
	u32 stack1;
	struct prop *prop = chr->prop;
	bool done = false;
	bool isdifferentmtx;
	struct coord sp124;
	struct coord sp118;
	s32 i;
	struct modelnode *bestnode;
	u32 stack2[2];
	Mtxf spc8;
	f32 bestvolume;
	Mtxf *worldtoscreenmtx;
	struct modelnode *node;
	f32 x;
	f32 y;
	f32 z;
	f32 volume;
	Mtxf *mtxptr1;
	Mtxf *mtxptr2;
	f32 sides[6];
	u32 stack3;

	if (prop->type != PROPTYPE_PLAYER || g_Vars.normmplayerisrunning || chrGetShield(chr) > 0) {
		if (prop->flags & (PROPFLAG_ONTHISSCREENTHISTICK | PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONANYSCREENPREVTICK)) {
			bestnode = NULL;
			bestvolume = MAXFLOAT;
			worldtoscreenmtx = cam0f0b5050((u8 *)chr->model->matrices);

			if (worldtoscreenmtx) {
				mtx4TransformVec(worldtoscreenmtx, pos, &sp124);
				mtx4RotateVec(worldtoscreenmtx, vector, &sp118);

				isdifferentmtx = (camGetWorldToScreenMtxf() != worldtoscreenmtx);
				node = chr->model->filedata->rootnode;

				while (node) {
					if ((node->type & 0xff) == MODELNODETYPE_BBOX) {
						mtxptr1 = model0001a5cc(chr->model, node, 0);

						if (isdifferentmtx) {
							mtx00016798(mtxptr1, &spc8);
							mtxptr1 = &spc8;
						}

						x = mtxptr1->m[3][0] - sp124.f[0];
						y = mtxptr1->m[3][1] - sp124.f[1];
						z = mtxptr1->m[3][2] - sp124.f[2];

						volume = x * x + y * y + z * z;

						if (volume < bestvolume) {
							bestvolume = volume;
							bestnode = node;
						}
					}

					// Iterate all nodes recursively except headspot's chidlren
					if (node->child && (node->type & 0xff) != MODELNODETYPE_HEADSPOT) {
						node = node->child;
					} else {
						while (node) {
							if (node->next) {
								node = node->next;
								break;
							}

							node = node->parent;
						}
					}
				}

				if (bestvolume);

#if VERSION >= VERSION_NTSC_1_0
				if (bestnode != NULL)
#endif
				{
					Mtxf sp48;
					struct modelrodata_bbox *rodata = &bestnode->rodata->bbox;

					*hitpartptr = rodata->hitpart;
					*nodeptr = bestnode;
					*modelptr = chr->model;
					*sideptr = 0;

					mtxptr2 = model0001a5cc(chr->model, bestnode, 0);

					if (isdifferentmtx) {
						mtx00016798(mtxptr2, &sp48);
						mtxptr2 = &sp48;
					}

					bestvolume = -2;

					x = (sp118.f[0] * mtxptr2->m[0][0]) + (sp118.f[1] * mtxptr2->m[0][1]) + (sp118.f[2] * mtxptr2->m[0][2]);
					y = (sp118.f[0] * mtxptr2->m[1][0]) + (sp118.f[1] * mtxptr2->m[1][1]) + (sp118.f[2] * mtxptr2->m[1][2]);
					z = (sp118.f[0] * mtxptr2->m[2][0]) + (sp118.f[1] * mtxptr2->m[2][1]) + (sp118.f[2] * mtxptr2->m[2][2]);

					sides[0] = x;
					sides[1] = -x;
					sides[2] = y;
					sides[3] = -y;
					sides[4] = z;
					sides[5] = -z;

					for (i = 0; i < 6; i++) {
						if (sides[i] > bestvolume) {
							bestvolume = sides[i];
							*sideptr = i;
						}
					}

					done = true;
				}
			}
		}

		// If no node was found above, search the model for the torso bbox
		// and return that.
		if (!done) {
			node = chr->model->filedata->rootnode;

			while (node) {

				if ((node->type & 0xff) == MODELNODETYPE_BBOX) {
					struct modelrodata_bbox *rodata = &node->rodata->bbox;

					if (rodata->hitpart == HITPART_TORSO) {
						*hitpartptr = rodata->hitpart;
						*nodeptr = node;
						*modelptr = chr->model;
						*sideptr = 0;
						return;
					}
				}

				if (node->child) {
					node = node->child;
				} else {
					while (node) {
						if (node->next) {
							node = node->next;
							break;
						}

						node = node->parent;
					}
				}
			}
		}
	}
}

/**
 * Calculates the trajectory for thrown items.
 */
void chrCalculateTrajectory(struct coord *frompos, f32 arg1, struct coord *aimpos, struct coord *arg3)
{
	f32 xvel;
	f32 yvel;
	f32 zvel;
	f32 latvel;
	f32 vel;
	f32 sp40;
	f32 sp3c;
	f32 sp38;
	f32 sp30;
	f32 sp2c;
	f32 sp24;
	f32 sp28;
	f32 sp20;

	arg1 *= 0.59999999f;

	xvel = (aimpos->x - frompos->x) * 0.01f;
	yvel = (aimpos->y - frompos->y) * 0.01f;
	zvel = (aimpos->z - frompos->z) * 0.01f;

	vel = sqrtf(xvel * xvel + yvel * yvel + zvel * zvel);
	latvel = sqrtf(xvel * xvel + zvel * zvel);
	sp38 = latvel / vel;
	sp40 = acosf(sp38);

	if (yvel < 0) {
		sp40 = -sp40;
	}

	sp2c = (vel * 9.81f * sp38 * sp38) / (arg1 * arg1) + yvel / vel;

	if (sp2c < -1) {
		sp2c = -1;
	} else if (sp2c > 1) {
		sp2c = 1;
	}

	sp3c = (asinf(sp2c) - sp40) * 0.5f + sp40;
	sp28 = cosf(sp3c);
	sp30 = sinf(sp3c);

	arg3->x = xvel / latvel * sp28;
	arg3->y = sp30;
	arg3->z = zvel / latvel * sp28;
}

const char var7f1a8ae4[] = "aimadjust=%d";

/**
 * Fire the chr's gun, check what was hit and do all the appropriate things
 * such as dealing damage, creating beams and sparks and playing sounds.
 *
 * This should be called on every frame while the chr is shooting.
 * The function takes care of the gun's fire rate.
 */
void chrTickShoot(struct chrdata *chr, s32 handnum)
{
	struct prop *chrprop = chr->prop;
	struct prop *gunprop;
	u8 isaibot = false;
	u8 normalshoot = true;

	if (chr->aibot) {
		isaibot = true;
	}

	gunprop = chrGetHeldProp(chr, handnum);

	if (gunprop) {
		bool firingthisframe = false;
		struct weaponobj *weapon = gunprop->weapon;
		struct gset gset;
		struct prop *targetprop = chrGetTargetProp(chr);
		u32 attackflags;
		bool shotdue;
		bool makebeam;
		struct coord gunpos;
		s16 gunrooms[8];
		struct coord hitpos;
		bool hitsomething;
		s16 hitrooms[8];
		bool queriedhitrooms;
		s32 tickspershot;

		gset = weapon->gset;
		attackflags = ATTACKFLAG_AIMATTARGET;

		if (chr->actiontype == ACT_ATTACK
				|| chr->actiontype == ACT_BOT_ATTACKSTAND
				|| chr->actiontype == ACT_BOT_ATTACKKNEEL
				|| chr->actiontype == ACT_BOT_ATTACKSTRAFE) {
			attackflags = chr->act_attack.flags;
		}

		shotdue = false;
		makebeam = false;
		hitsomething = false;
		queriedhitrooms = false;

		// Most guns can fire at most once every few ticks - even automatics.
		// The chr's firecount property tracks how many ticks have elapsed since
		// the last bullet, which is used to determine if another bullet should
		// be discharged on this tick.
		tickspershot = weaponGetNumTicksPerShot(gset.weaponnum, gset.weaponfunc);

		if (tickspershot <= 0) {
			shotdue = true;
			makebeam = true;
		} else {
			if (chr->aibot
					&& chr->aibot->weaponnum == WEAPON_REAPER
					&& chr->aibot->gunfunc == FUNC_PRIMARY) {
				f32 sp208 = (TICKS(90) - chr->aibot->reaperspeed[handnum]) * (1.0f / TICKS(18.0f));
				tickspershot *= 1 + sp208;
			}

			chr->firecount[handnum] += g_Vars.lvupdate60;

			if (chr->firecount[handnum] >= tickspershot) {
				chr->firecount[handnum] = 0;
				chr->unk32c_12 ^= 1 << handnum;

				shotdue = true;

				if ((chr->unk32c_12 & (1 << handnum)) || gset.weaponnum == WEAPON_LASER) {
					makebeam = true;
				}
			}
		}

		if (shotdue) {
			f32 roty = chrGetAimAngle(chr);
			f32 rotx = chrGetPitchAngle(chr);
			bool extracdtypes = isaibot ? CDTYPE_PLAYERS : 0;

			firingthisframe = true;

			if (!chrGetGunPos(chr, handnum, &gunpos)) {
				// Gun is off screen - use a quick but inexact calculation
				gunpos.x = chrprop->pos.x;
				gunpos.y = chrprop->pos.y + 30;
				gunpos.z = chrprop->pos.z;

				if (handnum == HAND_LEFT) {
					gunpos.x += cosf(roty) * 10.0f;
					gunpos.z += -sinf(roty) * 10.0f;
				} else {
					gunpos.x += -cosf(roty) * 10.0f;
					gunpos.z += sinf(roty) * 10.0f;
				}
			}

			// Check that the chr isn't clipping their gun through anything such
			// as another chr or a closed door. If they are, the shot won't be
			// taken because that wouldn't be fair.
			// How nice of the developers to check for this!
			chrSetPerimEnabled(chr, false);

			if (cdTestLos10(&chrprop->pos, chrprop->rooms, &gunpos, gunrooms,
						CDTYPE_DOORS | CDTYPE_CHRS | CDTYPE_BG | CDTYPE_DOORSWITHOUTFLAG | extracdtypes,
						GEOFLAG_BLOCK_SHOOT) == CDRESULT_COLLISION) {
				firingthisframe = false;
			}

			chrSetPerimEnabled(chr, true);

			if (firingthisframe) {
				bool angleok = false;
				bool hitplayer = false;
				bool effective = true;
				s32 zero = 0;
				struct coord vector;
				f32 xdiff;
				f32 ydiff;
				f32 zdiff;
				f32 sqshotdist;
				struct prop *hitprop = NULL;
				u32 cdtypes = isaibot
					? CDTYPE_OBJS | CDTYPE_DOORS | CDTYPE_CHRS | CDTYPE_PATHBLOCKER | CDTYPE_BG | CDTYPE_DOORSWITHOUTFLAG | CDTYPE_PLAYERS
					: CDTYPE_OBJS | CDTYPE_DOORS | CDTYPE_CHRS | CDTYPE_PATHBLOCKER | CDTYPE_BG | CDTYPE_DOORSWITHOUTFLAG;
				u32 stack;

				vector.x = cosf(rotx) * sinf(roty);
				vector.y = sinf(rotx);
				vector.z = cosf(rotx) * cosf(roty);

				if (isaibot) {
					bgunCalculateBotShotSpread(&vector,
							chr->aibot->weaponnum, chr->aibot->gunfunc,
							chr->aibot->burstsdone[handnum], botGuessCrouchPos(chr),
							chr->weapons_held[0] && chr->weapons_held[1]);
				}

				// Handle Farsight shots by aibots specially
				// because they can shoot through walls.
				if (chr->aibot && gset.weaponnum == WEAPON_FARSIGHT && !chr->aibot->targetinsight) {
					makebeam = true;

					// This function can never return 2 though...
					if (botactShootFarsight(chr + zero, 0, &vector, &gunpos) == 2) {
						normalshoot = random() % 255 > 200;
					}
				}

				// Check if the shot would hit anything
				hitpos.x = gunpos.x + vector.x * 65536.0f;
				hitpos.y = gunpos.y + vector.y * 65536.0f;
				hitpos.z = gunpos.z + vector.z * 65536.0f;

				chrSetPerimEnabled(chr, false);

				if (isaibot) {
					g_Vars.useperimshoot = true;
				}

				if (cdExamLos08(&gunpos, gunrooms, &hitpos, cdtypes, GEOFLAG_BLOCK_SHOOT) == CDRESULT_COLLISION) {
					hitsomething = true;
#if VERSION >= VERSION_JPN_FINAL
					cdGetPos(&hitpos, 12080, "chr/chraction.c");
#elif VERSION >= VERSION_PAL_FINAL
					cdGetPos(&hitpos, 12077, "chr/chraction.c");
#elif VERSION >= VERSION_NTSC_1_0
					cdGetPos(&hitpos, 12072, "chraction.c");
#else
					cdGetPos(&hitpos, 12086, "chraction.c");
#endif
					hitprop = cdGetObstacleProp();
				}

				chrSetPerimEnabled(chr, true);

				if (isaibot) {
					g_Vars.useperimshoot = false;
				}

				xdiff = hitpos.x - gunpos.x;
				ydiff = hitpos.y - gunpos.y;
				zdiff = hitpos.z - gunpos.z;

				sqshotdist = xdiff * xdiff + ydiff * ydiff + zdiff * zdiff;

				// Handle projectile launchers specially
				if (gset.weaponnum == WEAPON_ROCKETLAUNCHER
						|| gset.weaponnum == WEAPON_SLAYER
						|| (gset.weaponnum == WEAPON_SUPERDRAGON && gset.weaponfunc == FUNC_SECONDARY)
						|| gset.weaponnum == WEAPON_DEVASTATOR
						|| gset.weaponnum == WEAPON_CROSSBOW
						|| gset.weaponnum == WEAPON_ROCKETLAUNCHER_34) {
					makebeam = false;

					// Solo chrs won't fire their projectile weapon
					// in less than 4 metres of space
					if (isaibot || sqshotdist > 400.0f * 400.0f) {
						struct weaponobj *projectileobj;
						Mtxf identmtx;
						struct coord sp16c;
						f32 sp168;
						struct coord sp15c;
						Mtxf projectilemtx;
						Mtxf yrotmtx;
						struct weapon *weapondef = weaponFindById(gset.weaponnum);
						struct weaponfunc_shootprojectile *func = weapondef->functions[gset.weaponfunc];

						// Handle creating the projectile
						if (gset.weaponnum == WEAPON_ROCKETLAUNCHER
								|| gset.weaponnum == WEAPON_ROCKETLAUNCHER_34
								|| gset.weaponnum == WEAPON_SLAYER) {
							s32 rocketweaponnum = WEAPON_ROCKET;

							if (func->base.base.flags & FUNCFLAG_HOMINGROCKET) {
								rocketweaponnum = WEAPON_HOMINGROCKET;
							}

							projectileobj = weaponCreateProjectileFromWeaponNum(func->projectilemodelnum, rocketweaponnum, chr);
						} else if (gset.weaponnum == WEAPON_CROSSBOW) {
							projectileobj = weaponCreateProjectileFromWeaponNum(func->projectilemodelnum, WEAPON_BOLT, chr);

							if (projectileobj) {
								projectileobj->gunfunc = gset.weaponfunc;
							}
						} else if (gset.weaponnum == WEAPON_DEVASTATOR) {
							projectileobj = weaponCreateProjectileFromWeaponNum(func->projectilemodelnum, WEAPON_GRENADEROUND, chr);

							if (projectileobj) {
								projectileobj->gunfunc = gset.weaponfunc;
							}
						} else if (gset.weaponnum == WEAPON_SUPERDRAGON) {
							projectileobj = weaponCreateProjectileFromWeaponNum(func->projectilemodelnum, WEAPON_GRENADEROUND, chr);

							if (projectileobj) {
								projectileobj->gunfunc = FUNC_2;
							}
						} else {
							// Unreachable
							projectileobj = weaponCreateProjectileFromGset(func->projectilemodelnum, &gset, g_Vars.currentplayer->prop->chr);
						}

						if (projectileobj) {
							f32 spcc;

							sp168 = func->speed * (1.0f / 0.6f) / 60.0f;
							spcc = func->traveldist * (1.0f / 0.6f);

							// AI bots are a bit smarter than solo chrs
							// with regard to how they aim their projectiles
							if (isaibot && chrIsTargetInFov(chr, 30, 0)) {
								bool hasaimpos = false;
								u32 stack;
								struct coord aimpos;

								if (gset.weaponfunc == FUNC_PRIMARY &&
										(gset.weaponnum == WEAPON_ROCKETLAUNCHER
										 || gset.weaponnum == WEAPON_ROCKETLAUNCHER_34
										 || gset.weaponnum == WEAPON_SLAYER)) {
									if (targetprop->type == PROPTYPE_CHR || targetprop->type == PROPTYPE_PLAYER) {
										// Rockets - aim at target's feet
										aimpos.x = targetprop->pos.x;
										aimpos.y = targetprop->chr->manground;
										aimpos.z = targetprop->pos.z;

										vector.x = aimpos.x - gunpos.x;
										vector.y = aimpos.y - gunpos.y;
										vector.z = aimpos.z - gunpos.z;

										guNormalize(&vector.x, &vector.y, &vector.z);
										hasaimpos = true;
									}
								} else if ((gset.weaponnum == WEAPON_DEVASTATOR && gset.weaponfunc == FUNC_PRIMARY)
										|| gset.weaponnum == WEAPON_SUPERDRAGON) {
									if (targetprop->type == PROPTYPE_CHR || targetprop->type == PROPTYPE_PLAYER) {
										// Grenades - aim at target's feet
										aimpos.x = targetprop->pos.x;
										aimpos.y = targetprop->chr->manground;
										aimpos.z = targetprop->pos.z;

										chrCalculateTrajectory(&gunpos, spcc, &aimpos, &vector);
										hasaimpos = true;
									}
								} else if ((gset.weaponnum == WEAPON_DEVASTATOR && gset.weaponfunc == FUNC_SECONDARY)
										|| gset.weaponnum == WEAPON_CROSSBOW) {
									// Wall hugger grenade or crossbow - aim at target directly
									aimpos.x = targetprop->pos.x;
									aimpos.y = targetprop->pos.y;
									aimpos.z = targetprop->pos.z;

									if (targetprop->type == PROPTYPE_PLAYER) {
										aimpos.y -= 25;
									}

									chrCalculateTrajectory(&gunpos, spcc, &aimpos, &vector);
									hasaimpos = true;
								}

								if (hasaimpos) {
									f32 angle = chrGetAngleToPos(chr, &aimpos);
									f32 cos = cosf(angle);
									f32 sin = sinf(angle);
									f32 x = vector.f[0];
									f32 z = vector.f[2];
									u32 stack;

									vector.x = sin * z + cos * x;
									vector.z = cos * z - sin * x;
								}
							}

							// Calculate and projectile's matrix,
							// spawn position and speed
							mtx4LoadIdentity(&identmtx);
							mtx4LoadXRotation(rotx, &projectilemtx);
							mtx4LoadYRotation(roty, &yrotmtx);
							mtx00015be0(&yrotmtx, &projectilemtx);

							sp15c.x = vector.x * sp168;
							sp15c.y = vector.y * sp168;
							sp15c.z = vector.z * sp168;

							sp16c.x = sp15c.f[0] * g_Vars.lvupdate60freal + vector.f[0] * spcc;
							sp16c.y = sp15c.f[1] * g_Vars.lvupdate60freal + vector.f[1] * spcc;
							sp16c.z = sp15c.f[2] * g_Vars.lvupdate60freal + vector.f[2] * spcc;

							projectileobj->timer240 = func->timer60;

							if (projectileobj->timer240 != -1) {
#if PAL
								projectileobj->timer240 = projectileobj->timer240 * 200 / 60;
#else
								projectileobj->timer240 *= 4;
#endif
							}

							bgun0f09ebcc(&projectileobj->base, &gunpos, gunrooms, &projectilemtx, &sp16c, &identmtx, chrprop, &gunpos);

							if (projectileobj->base.hidden & OBJHFLAG_PROJECTILE) {
								if (func->base.base.flags & FUNCFLAG_PROJECTILE_LIGHTWEIGHT) {
									projectileobj->base.projectile->flags |= PROJECTILEFLAG_LIGHTWEIGHT;
								} else if (func->base.base.flags & FUNCFLAG_PROJECTILE_POWERED) {
									projectileobj->base.projectile->flags |= PROJECTILEFLAG_POWERED;
								}

								projectileobj->base.projectile->unk010 = sp15c.x;
								projectileobj->base.projectile->unk014 = sp15c.y;
								projectileobj->base.projectile->unk018 = sp15c.z;

								projectileobj->base.projectile->pickuptimer240 = TICKS(240);
								projectileobj->base.projectile->unk08c = func->reflectangle;
								projectileobj->base.projectile->unk098 = func->unk50 * (1.0f / 0.6f);

								projectileobj->base.projectile->targetprop = chrGetTargetProp(chr);

								// Play sound
								if (func->soundnum > 0) {
									propsnd0f0939f8(NULL, projectileobj->base.prop, func->soundnum, -1,
											-1, 0, 0, 0, NULL, -1, NULL, -1, -1, -1, -1);
								}
							}
						}
					} else {
						firingthisframe = false;
					}

					normalshoot = false;
				} else if (gset.weaponnum == WEAPON_MAULER && isaibot && gset.weaponfunc == FUNC_SECONDARY) {
					gset.unk063a = (s32) (chr->aibot->maulercharge[handnum] * 10.0f);
					chr->aibot->maulercharge[handnum] = 0;
				}

				if (normalshoot) {
					if (!isaibot) {
						if ((attackflags & ATTACKFLAG_AIMATTARGET)
								&& targetprop->type == PROPTYPE_PLAYER
								&& chrCanSeeAttackTarget(chr, &gunpos, gunrooms, false)
#if VERSION >= VERSION_NTSC_1_0
								&& chrCompareTeams(targetprop->chr, chr, COMPARE_ENEMIES)
#endif
								) {
							// Solo chr shooting at a player
							xdiff = targetprop->pos.x - gunpos.x - vector.x * 15.0f;
							ydiff = targetprop->pos.y - gunpos.y - vector.y * 15.0f;
							zdiff = targetprop->pos.z - gunpos.z - vector.z * 15.0f;

							if (xdiff * xdiff + ydiff * ydiff + zdiff * zdiff <= sqshotdist) {
								// Player has a chance of being hit
								chrCalculateHit(chr, &angleok, &hitplayer, &gset);

								// If the player was hit then turn off effective
								// (There's no need to check other props for
								// hits later on in this function)
								effective = !hitplayer;

								if (angleok
										&& (chr->actiontype == ACT_ATTACK
										 || chr->actiontype == ACT_BOT_ATTACKSTAND
										 || chr->actiontype == ACT_BOT_ATTACKKNEEL
										 || chr->actiontype == ACT_BOT_ATTACKSTRAFE)) {
									chr->act_attack.lastontarget60 = g_Vars.lvframe60;
								}
							}
						} else {
							// Solo chr shooting at something else
							if (chr->actiontype == ACT_ATTACK
									|| chr->actiontype == ACT_BOT_ATTACKSTAND
									|| chr->actiontype == ACT_BOT_ATTACKKNEEL
									|| chr->actiontype == ACT_BOT_ATTACKSTRAFE) {
								chr->act_attack.lastontarget60 = g_Vars.lvframe60;
							}
						}

						if (hitplayer) {
							f32 damage = gsetGetDamage(&gset);
							struct modelnode *node = NULL;
							struct model *model = NULL;
							s32 side = -1;
							s32 hitpart = HITPART_GENERAL;
							struct chrdata *targetchr = targetprop->chr;

							hitpos.x = targetprop->pos.x;
							hitpos.y = targetprop->pos.y;
							hitpos.z = targetprop->pos.z;

							if (random() % 2) {
								hitpos.y += 2 + random() % 10;
							} else {
								hitpos.y -= 2 + random() % 10;
							}

							bgunPlayPropHitSound(&gset, targetprop, -1);

							if (targetchr->model && chrGetShield(targetchr) > 0) {
								chrCalculateShieldHit(targetchr, &hitpos, &vector, &node, &hitpart, &model, &side);
							}

							func0f0341dc(targetchr, damage, &vector, &gset, chr->prop, HITPART_GENERAL, targetprop, node, model, side, NULL);
						} else if ((hitprop == NULL || (hitprop->type != PROPTYPE_CHR && hitprop->type != PROPTYPE_PLAYER))
								&& sqshotdist < 100.0f * 100.0f) {
							// Hit the background or something other than a
							// player or chr, and the shot distance was less
							// than 1 metre. Don't bother applying damage etc.
							effective = false;
						}
					}

					if (effective) {
						if (hitprop) {
							if (hitprop->type == PROPTYPE_PLAYER || hitprop->type == PROPTYPE_CHR) {
								// Hit a player or chr other than the one they
								// were aiming for
								if (isaibot
										|| ((chr->chrflags & CHRCFLAG_00000040) && chrCompareTeams(hitprop->chr, chr, COMPARE_ENEMIES))) {
									struct modelnode *node = NULL;
									struct model *model = NULL;
									s32 side = -1;
									s32 hitpart = HITPART_GENERAL;
									f32 damage = gsetGetDamage(&gset);
									struct chrdata *hitchr = hitprop->chr;

									bgunPlayPropHitSound(&gset, hitprop, -1);

									if (hitchr->model && chrGetShield(hitchr) > 0) {
										chrCalculateShieldHit(hitchr, &hitpos, &vector, &node, &hitpart, &model, &side);
									}

									chrEmitSparks(hitchr, hitprop, hitpart, &hitpos, &vector, chr);
									func0f0341dc(hitchr, damage, &vector, &gset, chr->prop, HITPART_GENERAL, hitprop, node, model, side, NULL);
								} else {
									makebeam = false;
									firingthisframe = false;
								}
							} else if (hitprop->type == PROPTYPE_OBJ
									|| hitprop->type == PROPTYPE_WEAPON
									|| hitprop->type == PROPTYPE_DOOR) {
								// Hit an object
								struct defaultobj *hitobj = hitprop->obj;
								s32 playernum = -1;

								if (g_Vars.mplayerisrunning) {
									playernum = chr->chrnum;
								}

								bgunPlayPropHitSound(&gset, hitprop, -1);
								func0f065e74(&gunpos, gunrooms, &hitpos, hitrooms);
								queriedhitrooms = true;

								if (chrIsUsingPaintball(chr)) {
									sparksCreate(hitrooms[0], hitprop, &hitpos, NULL, NULL, SPARKTYPE_PAINT);
								} else {
									sparksCreate(hitrooms[0], hitprop, &hitpos, NULL, NULL, SPARKTYPE_DEFAULT);
								}

								objTakeGunfire(hitobj, gsetGetDamage(&gset), &hitpos, gset.weaponnum, playernum);
							}
						} else if (hitsomething) {
							// Hit the background
							func0f065e74(&gunpos, gunrooms, &hitpos, hitrooms);
							queriedhitrooms = true;
							bgunPlayBgHitSound(&gset, &hitpos, -1, hitrooms);

							if (chrIsUsingPaintball(chr)) {
								sparksCreate(hitrooms[0], 0, &hitpos, NULL, NULL, SPARKTYPE_PAINT);
							} else {
								sparksCreate(hitrooms[0], 0, &hitpos, NULL, NULL, SPARKTYPE_DEFAULT);
							}
						}

						// Create explosion if using Phoenix
						if (gset.weaponnum == WEAPON_PHOENIX && gset.weaponfunc == FUNC_SECONDARY) {
							s32 playernum = chr->aibot ? chr->chrnum : g_Vars.currentplayernum;

							if (!queriedhitrooms) {
								func0f065e74(&gunpos, gunrooms, &hitpos, hitrooms);
							}

							explosionCreateSimple(NULL, &hitpos, hitrooms, EXPLOSIONTYPE_PHOENIX, playernum);
						}
					}
				}
			}
		}

		if (makebeam) {
			switch (gset.weaponnum) {
			case WEAPON_FALCON2:
			case WEAPON_FALCON2_SILENCER:
			case WEAPON_FALCON2_SCOPE:
			case WEAPON_MAGSEC4:
			case WEAPON_MAULER:
			case WEAPON_PHOENIX:
			case WEAPON_DY357MAGNUM:
			case WEAPON_DY357LX:
			case WEAPON_CMP150:
			case WEAPON_CYCLONE:
			case WEAPON_CALLISTO:
			case WEAPON_RCP120:
			case WEAPON_LAPTOPGUN:
			case WEAPON_DRAGON:
			case WEAPON_K7AVENGER:
			case WEAPON_AR34:
			case WEAPON_SUPERDRAGON:
			case WEAPON_REAPER:
			case WEAPON_SNIPERRIFLE:
			case WEAPON_FARSIGHT:
			case WEAPON_TRANQUILIZER:
			case WEAPON_LASER:
			case WEAPON_PP9I:
			case WEAPON_CC13:
			case WEAPON_KL01313:
			case WEAPON_KF7SPECIAL:
			case WEAPON_ZZT:
			case WEAPON_DMC:
			case WEAPON_AR53:
			case WEAPON_RCP45:
				makebeam = true;
				break;
			default:
				makebeam = false;
				break;
			}
		}

		// osSyncPrintf is defined to nothing, so these print statements
		// get optimised out but leave their strings in rodata.
		// The on/off strings are surely used in a ternary statement in the
		// previous string, but making this a ternary creates a mismatch.
		osSyncPrintf("firing(%d) %d, beam(%d) %s", handnum, firingthisframe, handnum);
		osSyncPrintf("on");
		osSyncPrintf("off");

		chrCreateFireslot(chr, handnum, firingthisframe, firingthisframe && makebeam, &gunpos, &hitpos);

		if (isaibot) {
			if (firingthisframe) {
				osSyncPrintf("firecount(%d) = %d", handnum, chr->aibot->loadedammo[handnum]);

				if (chr->aibot->loadedammo[handnum] > 0) {
					chr->aibot->loadedammo[handnum]--;
				}

				osSyncPrintf("numshots(%d) = %d", handnum, chr->aibot->loadedammo[handnum]);
			}

			chrSetFiring(chr, handnum, firingthisframe && normalshoot);
		} else {
			chrSetFiring(chr, handnum, firingthisframe);
		}
	}
}

void func0f041a74(struct chrdata *chr)
{
#if VERSION >= VERSION_NTSC_1_0
	chr->hidden2 &= ~CHRH2FLAG_0020;
#else
	chr->hidden &= ~CHRHFLAG_00000080;
#endif

	if (chr->hidden & CHRHFLAG_FIRINGRIGHT) {
		chrTickShoot(chr, HAND_RIGHT);
		chr->hidden &= ~CHRHFLAG_FIRINGRIGHT;
	}

	if (chr->hidden & CHRHFLAG_FIRINGLEFT) {
		chrTickShoot(chr, HAND_LEFT);
		chr->hidden &= ~CHRHFLAG_FIRINGLEFT;
	}
}

bool func0f041c44(struct chrdata *chr)
{
	if (CHRRACE(chr) == RACE_HUMAN) {
		if (chr->act_attack.animcfg == &g_RollAttackAnims[2] || chr->act_attack.animcfg == &g_RollAttackAnims[3]) {
			struct model *model = chr->model;
			struct attackanimconfig *animcfg = &g_RollAttackAnims[1];
			bool flip = model->anim->flip;

			chr->act_attack.turning = TURNSTATE_OFF;
			chr->act_attack.animcfg = animcfg;
			chr->sleep = 0;

			modelSetAnimation(model, animcfg->animnum, flip, animcfg->unk1c, chrGetRangedSpeed(chr, 0.7f, 1.12f), 22);

			if (animcfg->unk14 >= 0) {
				modelSetAnimEndFrame(model, animcfg->unk14);
			}

			return true;
		}
	}

	return false;
}

void chrAttackAmountUpdateAnimation(struct chrdata *chr)
{
	struct model *model = chr->model;

	if (chr->act_attack.animcfg->unk24 > 0) {
		modelSetAnimation(model,
				modelGetAnimNum(model),
				model->anim->flip,
				chr->act_attack.animcfg->unk24,
				chrGetRangedSpeed(chr, 0.5f, 0.8f),
				8);
	} else {
		modelSetAnimation(model,
				modelGetAnimNum(model),
				model->anim->flip,
				chr->act_attack.animcfg->unk1c,
				chrGetRangedSpeed(chr, 0.5f, 0.8f),
				8);
	}

	if (chr->act_attack.animcfg->unk14 >= 0) {
		modelSetAnimEndFrame(model, chr->act_attack.animcfg->unk14);
	}
}

void chrTickFire(struct chrdata *chr)
{
	struct model *model = chr->model;
	f32 curframe = modelGetCurAnimFrame(model);
	s32 i;

	if (chr->act_attack.lastontarget60 < chr->act_attack.lastfire60 - TICKS(30)
			&& model->anim->animnum2 == 0
			&& curframe > chr->act_attack.animcfg->unk18 + 10
			&& curframe < chr->act_attack.animcfg->unk1c
			&& (chr->act_attack.animcfg->unk24 < 0 || curframe < chr->act_attack.animcfg->unk24)) {
		if (!chr->act_attack.dorecoil) {
			if (!func0f041c44(chr)) {
				modelSetAnimation(model, modelGetAnimNum(model), model->anim->flip,
						chr->act_attack.animcfg->unk1c, chrGetRangedSpeed(chr, 0.5f, 0.8f), 8);

				if (chr->act_attack.animcfg->unk14 >= 0) {
					modelSetAnimEndFrame(model, chr->act_attack.animcfg->unk14);
				}
			}
		} else {
			chrAttackAmountUpdateAnimation(chr);
		}

		chr->act_attack.numshots = chr->act_attack.maxshots + 1;

		curframe = modelGetCurAnimFrame(model);
	}

	if (curframe >= modelGetAnimEndFrame(model)) {
		if (chr->act_attack.dooneburst || chr->act_attack.numshots > chr->act_attack.maxshots) {
			if (!func0f041c44(chr)) {
				if (chr->act_attack.flags & ATTACKFLAG_AIMATTARGET) {
					chrRecordLastSeeTargetTime(chr);
				}

				chrStop(chr);
				return;
			}
		} else if (chr->act_attack.numshots == chr->act_attack.maxshots) {
			chr->act_attack.numshots++;
			chrAttackAmountUpdateAnimation(chr);
		} else if (chr->act_attack.fired) {
			f32 f2 = 0.5f;
			f32 startframe;
			f32 endframe;
			f32 diff;

			if (chr->act_attack.dorecoil) {
				if (chr->act_attack.animcfg->unk20 > 0) {
					startframe = chr->act_attack.animcfg->unk20;
				} else {
					startframe = chr->act_attack.animcfg->unk18;
				}

				if (chr->act_attack.animcfg->unk24 > 0) {
					endframe = chr->act_attack.animcfg->unk24;
				} else {
					endframe = chr->act_attack.animcfg->unk1c;
				}
			} else {
				startframe = chr->act_attack.animcfg->unk18;

				if (chr->act_attack.animcfg->unk20 > 0) {
					endframe = chr->act_attack.animcfg->unk20;
				} else {
					endframe = chr->act_attack.animcfg->unk1c;
				}
			}

			diff = endframe - startframe;

			if (diff < 12) {
				f2 = diff * (1.0f / 24.0f);
			} else if (diff > 16) {
				f2 = diff * (1.0f / 32.0f);
			}

			if (chr->act_attack.everytick[HAND_RIGHT] && chr->act_attack.everytick[HAND_LEFT]) {
				f2 = f2 + f2;
			}

			chr->act_attack.fired = false;

			modelSetAnimation(model, modelGetAnimNum(model), model->anim->flip, startframe, f2, 8);
			modelSetAnimEndFrame(model, endframe);
		}

		curframe = modelGetCurAnimFrame(model);
	}

	if ((chr->act_attack.flags & ATTACKFLAG_DONTTURN) == 0) {
		f32 f2 = chr->act_attack.animcfg->unk0c;
		f32 f12 = chr->act_attack.animcfg->unk04;

		if ((chr->act_attack.flags & ATTACKFLAG_AIMONLY) && f12 > modelGetAnimEndFrame(model)) {
			f12 = modelGetAnimEndFrame(model);
		}

		if (model->anim->flip) {
			f2 = M_BADTAU - f2;
		}

		chr->act_attack.turning = chrTurn(chr, chr->act_attack.turning, f12, chrGetRangedSpeed(chr, 1, 1.6f), f2);
	}

	if (curframe > chr->act_attack.animcfg->unk28 && curframe < chr->act_attack.animcfg->unk2c) {
		func0f03e9f4(chr, chr->act_attack.animcfg, chr->act_attack.firegun[HAND_LEFT], chr->act_attack.firegun[HAND_RIGHT], 1);
	} else {
		chrResetAimEndProperties(chr);
	}

	for (i = 0; i < 2; i++) {
		if (chr->act_attack.firegun[i]) {
			if (chr->act_attack.everytick[i] == 0) {
				if (curframe >= chr->act_attack.animcfg->unk18 && curframe < chr->act_attack.animcfg->unk1c) {
					chrSetHandFiring(chr, i, true);

					chr->act_attack.lastfire60 = g_Vars.lvframe60;

					modelSetAnimSpeed(model, 0.5f, 0);
				} else {
					chrSetHandFiring(chr, i, false);

					modelSetAnimSpeed(model, chrGetRangedSpeed(chr, 0.5f, 0.8f), 0);
				}
			} else if ((!chr->act_attack.fired && (i == chr->act_attack.nextgun || !chr->act_attack.everytick[chr->act_attack.nextgun]))
					&& ((chr->act_attack.animcfg->unk20 >= 0 && curframe >= chr->act_attack.animcfg->unk20 && curframe <= chr->act_attack.animcfg->unk24)
						|| (chr->act_attack.animcfg->unk20 < 0 && curframe >= chr->act_attack.animcfg->unk18))) {
				chr->act_attack.fired = true;
				chr->act_attack.nextgun = 1 - chr->act_attack.nextgun;
				chr->act_attack.numshots++;
				chr->act_attack.lastfire60 = g_Vars.lvframe60;

				chrSetHandFiring(chr, i, true);
			} else {
				chrSetHandFiring(chr, i, false);
			}
		} else {
			chrSetHandFiring(chr, i, false);
		}
	}
}

void chrTickAttack(struct chrdata *chr)
{
	struct model *model = chr->model;
	f32 curframe = modelGetCurAnimFrame(model);

	if (chr->hidden & CHRHFLAG_NEEDANIM) {
		if (modelIsAnimMerging(chr->model)) {
			return;
		}

		modelSetAnimation(model, chr->act_attack.animcfg->animnum, chr->act_attack.flip,
				chr->act_attack.animcfg->unk10, chrGetRangedSpeed(chr, 0.5f, 0.8f), 16);
		func0f031254(chr);
		chr->hidden &= ~CHRHFLAG_NEEDANIM;
	}

	chrTickFire(chr);
}

void propUnsetDangerous(struct prop *prop)
{
	s32 i;

	for (i = 0; i != MAX_DANGEROUSPROPS; i++) {
		if (g_DangerousProps[i] == prop) {
			g_DangerousProps[i] = NULL;
			return;
		}
	}
}

void propSetDangerous(struct prop *prop)
{
	s32 i;

	for (i = 0; i != MAX_DANGEROUSPROPS; i++) {
		if (g_DangerousProps[i] == NULL) {
			g_DangerousProps[i] = prop;
			return;
		}
	}
}

bool func0f043f2c(struct chrdata *chr, struct coord *runpos, u32 arg2, f32 *turnspeed)
{
	struct prop *prop = chr->prop;
	struct model *model = chr->model;
	f32 accel;
	f32 maxspeed;
	f32 angle1;
	f32 finalangle;
	f32 angle2;
	f32 angle3;
	f32 xdiff = runpos->f[0] - prop->pos.f[0];
	f32 zdiff = runpos->f[2] - prop->pos.f[2];
	bool result;

	result = false;
	angle1 = atan2f(xdiff, zdiff);
	finalangle = func0f03e578(chr);
	angle2 = angle1 - finalangle;

	if (finalangle > angle1) {
		angle2 += M_BADTAU;
	}

	if (chr->aibot) {
		if (chr->blurdrugamount > 0) {
			angle1 += chr->blurdrugamount * PALUPF(0.00031410926021636f) * sinf((g_Vars.lvframe60 % TICKS(1200)) * PALUPF(0.0052351541817188f));

			if (angle1 >= M_BADTAU) {
				angle1 -= M_BADTAU;
			}

			angle1 += M_BADTAU;
		}

		finalangle = angle1;
		*turnspeed = 0;
		result = true;
	} else {
		angle3 = angle2;

		if (angle2 > M_BADPI) {
			angle3 = M_BADTAU - angle3;
		}

		if ((arg2 % 4) == 2) {
			maxspeed = 0.29915165901184f;
			accel = 0.014957583509386f;
		} else if ((arg2 % 4) == 1) {
			if (angle3 < 0.3926365673542f) {
				maxspeed = 0.019631829112768f;
			} else if (angle3 < 1.2564370632172f) {
				maxspeed = 0.098159141838551f;
			} else {
				maxspeed = 0.1963182836771f;
			}

			accel = 0.014957583509386f;
		} else {
			if (angle3 < 0.3926365673542f) {
				maxspeed = 0.0098159145563841f;
			} else if (angle3 < 1.2564370632172f) {
				maxspeed = 0.049079570919275f;
			} else {
				maxspeed = 0.12564370036125f;
			}

			accel = 0.0098159145563841f;
		}

		maxspeed *= model->anim->playspeed;
		accel *= model->anim->playspeed;

		applyRotation(&finalangle, angle1, turnspeed, accel, accel + accel, maxspeed);

		if (ABS(finalangle - angle1) < 0.01f) {
			*turnspeed = 0;
			result = true;
		}
	}

	func0f03e5b0(chr, finalangle);

	return result;
}

/**
 * This function might be misnamed. It was named by isolating it and testing it
 * with different inputs to see what it returns, but I couldn't determine how
 * the range affects the latter part of the function.
 */
bool posIsMovingTowardsPosOrStoppedInRange(struct coord *prevpos, struct coord *moveddelta, struct coord *targetpos, f32 range)
{
	struct coord prevdist;
	f32 tmp;

	prevdist.x = targetpos->x - prevpos->x;
	prevdist.z = targetpos->z - prevpos->z;

	if (moveddelta->f[0] == 0 && moveddelta->f[2] == 0) {
		return prevdist.f[0] * prevdist.f[0] + prevdist.f[2] * prevdist.f[2] <= range * range;
	}

	tmp = moveddelta->f[0] * prevdist.f[0] + moveddelta->f[2] * prevdist.f[2];

	if (tmp > 0) {
		f32 sqmoveddist = moveddelta->f[0] * moveddelta->f[0] + moveddelta->f[2] * moveddelta->f[2];
		f32 sqprevdist = prevdist.f[0] * prevdist.f[0] + prevdist.f[2] * prevdist.f[2];

		if ((sqprevdist - range * range) * sqmoveddist <= tmp * tmp) {
			return true;
		}

		return false;
	}

	return false;
}

/**
 * Return true if:
 * - either prevpos or curpos is within the given range of targetpos, and
 * - the prev -> cur delta is moving towards the targetpos or is stopped inside
 *   the range.
 *
 * This is a lateral check, meaning the Y value is not considered.
 */
bool posIsArrivingLaterallyAtPos(struct coord *prevpos, struct coord *curpos, struct coord *targetpos, f32 range)
{
	struct coord moveddelta;

	if (prevpos->x <= targetpos->x - range && curpos->x <= targetpos->x - range) {
		return false;
	}

	if (prevpos->x >= targetpos->x + range && curpos->x >= targetpos->x + range) {
		return false;
	}

	if (prevpos->z <= targetpos->z - range && curpos->z <= targetpos->z - range) {
		return false;
	}

	if (prevpos->z >= targetpos->z + range && curpos->z >= targetpos->z + range) {
		return false;
	}

	moveddelta.x = curpos->x - prevpos->x;
	moveddelta.y = 0;
	moveddelta.z = curpos->z - prevpos->z;

	return posIsMovingTowardsPosOrStoppedInRange(prevpos, &moveddelta, targetpos, range);
}

/**
 * Return true if:
 * - either prevpos or curpos is within the given range of targetpos,
 * - the prev -> cur delta is moving towards the targetpos or is stopped inside
 *   the range, and
 * - either prevpos or curpos is within 150cm vertically of targetpos.
 */
bool posIsArrivingAtPos(struct coord *prevpos, struct coord *curpos, struct coord *targetpos, f32 range)
{
	if (prevpos->y <= targetpos->y - 150 && curpos->y <= targetpos->y - 150) {
		return false;
	}

	if (prevpos->y >= targetpos->y + 150 && curpos->y >= targetpos->y + 150) {
		return false;
	}

	return posIsArrivingLaterallyAtPos(prevpos, curpos, targetpos, range);
}

void func0f044b68(struct coord *arg0, struct coord *arg1, struct coord *arg2)
{
	struct coord sp0c;
	struct coord sp00;

	sp0c.x = arg1->x - arg0->x;
	sp0c.y = arg1->y - arg0->y;
	sp0c.z = arg1->z - arg0->z;

	sp00.x = -arg2->z;
	sp00.y = 0;
	sp00.z = arg2->x;

	if (sp00.f[0] * sp0c.f[0] + sp00.f[2] * sp0c.f[2] > 0) {
		// empty
	} else {
		sp0c.x = arg0->x;
		sp0c.y = arg0->y;
		sp0c.z = arg0->z;

		arg0->x = arg1->x;
		arg0->y = arg1->y;
		arg0->z = arg1->z;

		arg1->x = sp0c.x;
		arg1->y = sp0c.y;
		arg1->z = sp0c.z;
	}
}

/**
 * Check to see if the chr can see the next pos in their route.
 *
 * If an obstacle is found, set the leftpos and rightpos coordinates to the
 * left and right corners of the object from the chr's perspective and return
 * false.
 *
 * Return true if path ahead is clear.
 *
 * This is similar to chrNavCheckForObstacle. The difference between the two are
 * not yet understood.
 */
bool chrNavCanSeeNextPos(struct chrdata *chr, struct coord *chrpos, s16 *chrrooms, struct coord *aimpos, struct coord *leftpos, struct coord *rightpos, f32 negchrradius, f32 chrradius, s32 cdtypes, s32 arg9)
{
	struct coord spd4;
	f32 spd0;
	f32 spcc;
	f32 spc8;
	f32 spc4;
	f32 norm;
	bool spbc = false;
	bool spb8 = false;
	struct coord spac;
	struct coord spa0;
	struct coord sp94;
	struct coord sp88;
	bool result = false;
	f32 ymax;
	f32 ymin;
	f32 radius2;
	struct coord sp6c;
	struct coord sp60;
	s16 sp50[8];
	s16 sp40[8];
	struct prop *prop = chr->prop;

	chrGetBbox(prop, &radius2, &ymax, &ymin);

	spd4.x = aimpos->x - chrpos->x;
	spd4.y = 0.0f;
	spd4.z = aimpos->z - chrpos->z;

	if (spd4.f[0] == 0.0f && spd4.f[2] == 0.0f) {
		return true;
	}

	norm = 1.0f / sqrtf(spd4.f[0] * spd4.f[0] + spd4.f[2] * spd4.f[2]);
	spd4.x *= norm;
	spd4.z *= norm;

	spd0 = spd4.x * chrradius * 0.95f;
	spcc = spd4.z * chrradius * 0.95f;
	spc8 = spd4.x * chrradius * 1.2f;
	spc4 = spd4.z * chrradius * 1.2f;

	chrSetPerimEnabled(chr, false);

	sp6c.x = chrpos->x + spcc;
	sp6c.y = chrpos->y;
	sp6c.z = chrpos->z - spd0;
	sp60.x = (spd4.x * negchrradius) + (aimpos->x + spc4);
	sp60.y = aimpos->y;
	sp60.z = (spd4.z * negchrradius) + (aimpos->z - spc8);

	if (cdExamCylMove07(chrpos, chrrooms, &sp6c, sp50, cdtypes, 1, ymax - prop->pos.y, ymin - prop->pos.y) == CDRESULT_COLLISION
			|| cdExamCylMove03(&sp6c, sp50, &sp60, cdtypes, 1, ymax - prop->pos.y, ymin - prop->pos.y) == CDRESULT_COLLISION) {
		spbc = true;
#if VERSION >= VERSION_JPN_FINAL
		cdGetEdge(&spac, &spa0, 14154, "chr/chraction.c");
#elif VERSION >= VERSION_PAL_FINAL
		cdGetEdge(&spac, &spa0, 14151, "chr/chraction.c");
#elif VERSION >= VERSION_PAL_BETA
		cdGetEdge(&spac, &spa0, 14146, "chraction.c");
#elif VERSION >= VERSION_NTSC_1_0
		cdGetEdge(&spac, &spa0, 14145, "chraction.c");
#else
		cdGetEdge(&spac, &spa0, 14158, "chraction.c");
#endif
		func0f044b68(&spac, &spa0, &spd4);
	}

	sp6c.x = chrpos->x - spcc;
	sp6c.y = chrpos->y;
	sp6c.z = chrpos->z + spd0;

	sp60.x = (spd4.x * negchrradius) + (aimpos->x - spc4);
	sp60.y = aimpos->y;
	sp60.z = (spd4.z * negchrradius) + (aimpos->z + spc8);

	if (cdExamCylMove07(chrpos, chrrooms, &sp6c, sp50, cdtypes, 1, ymax - prop->pos.y, ymin - prop->pos.y) == CDRESULT_COLLISION
			|| cdExamCylMove03(&sp6c, chrrooms, &sp60, cdtypes, 1, ymax - prop->pos.y, ymin - prop->pos.y) == CDRESULT_COLLISION) {
		spb8 = true;
#if VERSION >= VERSION_JPN_FINAL
		cdGetEdge(&sp94, &sp88, 14169, "chr/chraction.c");
#elif VERSION >= VERSION_PAL_FINAL
		cdGetEdge(&sp94, &sp88, 14166, "chr/chraction.c");
#elif VERSION >= VERSION_PAL_BETA
		cdGetEdge(&sp94, &sp88, 14161, "chraction.c");
#elif VERSION >= VERSION_NTSC_1_0
		cdGetEdge(&sp94, &sp88, 14160, "chraction.c");
#else
		cdGetEdge(&sp94, &sp88, 14173, "chraction.c");
#endif
		func0f044b68(&sp94, &sp88, &spd4);
	}

	if (spbc && spb8) {
		func0f044b68(&spac, &sp94, &spd4);
		func0f044b68(&spa0, &sp88, &spd4);

		leftpos->x = spac.x;
		leftpos->y = spac.y;
		leftpos->z = spac.z;

		rightpos->x = sp88.x;
		rightpos->y = sp88.y;
		rightpos->z = sp88.z;
	} else if (spbc) {
		leftpos->x = spac.x;
		leftpos->y = spac.y;
		leftpos->z = spac.z;

		rightpos->x = spa0.x;
		rightpos->y = spa0.y;
		rightpos->z = spa0.z;
	} else if (spb8) {
		leftpos->x = sp94.x;
		leftpos->y = sp94.y;
		leftpos->z = sp94.z;

		rightpos->x = sp88.x;
		rightpos->y = sp88.y;
		rightpos->z = sp88.z;
	} else if (cdExamCylMove07(chrpos, chrrooms, aimpos, sp40, cdtypes, 1, ymax - prop->pos.y, ymin - prop->pos.y) != CDRESULT_COLLISION
			&& (!arg9 || cdExamCylMove01(chrpos, aimpos, chrradius, sp40, cdtypes, CHECKVERTICAL_YES, ymax - prop->pos.y, ymin - prop->pos.y) != CDRESULT_COLLISION)) {
		result = true;
	} else {
#if VERSION >= VERSION_JPN_FINAL
		cdGetEdge(leftpos, rightpos, 14239, "chr/chraction.c");
#elif VERSION >= VERSION_PAL_FINAL
		cdGetEdge(leftpos, rightpos, 14236, "chr/chraction.c");
#elif VERSION >= VERSION_PAL_BETA
		cdGetEdge(leftpos, rightpos, 14231, "chraction.c");
#elif VERSION >= VERSION_NTSC_1_0
		cdGetEdge(leftpos, rightpos, 14230, "chraction.c");
#else
		cdGetEdge(leftpos, rightpos, 14243, "chraction.c");
#endif
		func0f044b68(leftpos, rightpos, &spd4);
	}

	chrSetPerimEnabled(chr, true);

	return result;
}

/**
 * Check if the path ahead contains an obstacle that the chr should route
 * around.
 *
 * If an obstacle is found, set the leftpos and rightpos coordinates to the
 * left and right corners of the object from the chr's perspective and return
 * false.
 *
 * Return true if path ahead is clear.
 *
 * This is similar to chrNavCanSeeNextPos. The only difference is this one uses
 * the value1 and value2 variables.
 */
bool chrNavCheckForObstacle(struct chrdata *chr, struct coord *chrpos, s16 *chrrooms, struct coord *aimpos, struct coord *leftpos, struct coord *rightpos, f32 negchrradius, f32 chrradius, s32 cdtypes, bool hasobstacle)
{
	struct coord spd4;
	f32 spd0;
	f32 spcc;
	f32 spc8;
	f32 spc4;
	f32 norm;
	bool spbc = false;
	bool spb8 = false;
	struct coord spac;
	struct coord spa0;
	struct coord sp94;
	struct coord sp88;
	bool result = false;
	f32 value1;
	f32 value2;
	f32 ymax;
	f32 ymin;
	f32 radius2;
	struct coord sp6c;
	struct coord sp60;
	s16 sp50[8];
	s16 sp40[8];
	struct prop *prop = chr->prop;

	chrGetBbox(prop, &radius2, &ymax, &ymin);

	spd4.x = aimpos->x - chrpos->x;
	spd4.y = 0.0f;
	spd4.z = aimpos->z - chrpos->z;

	if (spd4.f[0] == 0.0f && spd4.f[2] == 0.0f) {
		return true;
	}

	norm = 1.0f / sqrtf(spd4.f[0] * spd4.f[0] + spd4.f[2] * spd4.f[2]);
	spd4.x *= norm;
	spd4.z *= norm;

	spd0 = spd4.x * chrradius * 0.95f;
	spcc = spd4.z * chrradius * 0.95f;
	spc8 = spd4.x * chrradius * 1.2f;
	spc4 = spd4.z * chrradius * 1.2f;

	chrSetPerimEnabled(chr, false);

	sp6c.x = chrpos->x + spcc;
	sp6c.y = chrpos->y;
	sp6c.z = chrpos->z - spd0;
	sp60.x = (spd4.x * negchrradius) + (aimpos->x + spc4);
	sp60.y = aimpos->y;
	sp60.z = (spd4.z * negchrradius) + (aimpos->z - spc8);

	if (cdExamCylMove07(chrpos, chrrooms, &sp6c, sp50, cdtypes, 1, ymax - prop->pos.y, ymin - prop->pos.y) == CDRESULT_COLLISION
			|| cdExamCylMove03(&sp6c, sp50, &sp60, cdtypes, 1, ymax - prop->pos.y, ymin - prop->pos.y) == CDRESULT_COLLISION) {
		spbc = true;
#if VERSION >= VERSION_JPN_FINAL
		cdGetEdge(&spac, &spa0, 14319, "chr/chraction.c");
#elif VERSION >= VERSION_PAL_FINAL
		cdGetEdge(&spac, &spa0, 14316, "chr/chraction.c");
#elif VERSION >= VERSION_PAL_BETA
		cdGetEdge(&spac, &spa0, 14311, "chraction.c");
#elif VERSION >= VERSION_NTSC_1_0
		cdGetEdge(&spac, &spa0, 14310, "chraction.c");
#else
		cdGetEdge(&spac, &spa0, 14323, "chraction.c");
#endif
		func0f044b68(&spac, &spa0, &spd4);
		value1 = cd00024e40();
	}

	sp6c.x = chrpos->x - spcc;
	sp6c.y = chrpos->y;
	sp6c.z = chrpos->z + spd0;

	sp60.x = (spd4.x * negchrradius) + (aimpos->x - spc4);
	sp60.y = aimpos->y;
	sp60.z = (spd4.z * negchrradius) + (aimpos->z + spc8);

	if (cdExamCylMove07(chrpos, chrrooms, &sp6c, sp50, cdtypes, 1, ymax - prop->pos.y, ymin - prop->pos.y) == CDRESULT_COLLISION
			|| cdExamCylMove03(&sp6c, chrrooms, &sp60, cdtypes, 1, ymax - prop->pos.y, ymin - prop->pos.y) == CDRESULT_COLLISION) {
		spb8 = true;
#if VERSION >= VERSION_JPN_FINAL
		cdGetEdge(&sp94, &sp88, 14334, "chr/chraction.c");
#elif VERSION >= VERSION_PAL_FINAL
		cdGetEdge(&sp94, &sp88, 14331, "chr/chraction.c");
#elif VERSION >= VERSION_PAL_BETA
		cdGetEdge(&sp94, &sp88, 14326, "chraction.c");
#elif VERSION >= VERSION_NTSC_1_0
		cdGetEdge(&sp94, &sp88, 14325, "chraction.c");
#else
		cdGetEdge(&sp94, &sp88, 14338, "chraction.c");
#endif
		func0f044b68(&sp94, &sp88, &spd4);
		value2 = cd00024e40();
	}

	if (spbc && spb8) {
		if (value1 < value2) {
			leftpos->x = spac.x;
			leftpos->y = spac.y;
			leftpos->z = spac.z;

			rightpos->x = spa0.x;
			rightpos->y = spa0.y;
			rightpos->z = spa0.z;
		} else {
			leftpos->x = sp94.x;
			leftpos->y = sp94.y;
			leftpos->z = sp94.z;

			rightpos->x = sp88.x;
			rightpos->y = sp88.y;
			rightpos->z = sp88.z;
		}
	} else if (spbc) {
		leftpos->x = spac.x;
		leftpos->y = spac.y;
		leftpos->z = spac.z;

		rightpos->x = spa0.x;
		rightpos->y = spa0.y;
		rightpos->z = spa0.z;
	} else if (spb8) {
		leftpos->x = sp94.x;
		leftpos->y = sp94.y;
		leftpos->z = sp94.z;

		rightpos->x = sp88.x;
		rightpos->y = sp88.y;
		rightpos->z = sp88.z;
	} else if (cdExamCylMove07(chrpos, chrrooms, aimpos, sp40, cdtypes, 1, ymax - prop->pos.y, ymin - prop->pos.y) != CDRESULT_COLLISION
			&& (!hasobstacle || cdExamCylMove01(chrpos, aimpos, chrradius, sp40, cdtypes, CHECKVERTICAL_YES, ymax - prop->pos.y, ymin - prop->pos.y) != CDRESULT_COLLISION)) {
		result = true;
	} else {
#if VERSION >= VERSION_JPN_FINAL
		cdGetEdge(leftpos, rightpos, 14404, "chr/chraction.c");
#elif VERSION >= VERSION_PAL_FINAL
		cdGetEdge(leftpos, rightpos, 14401, "chr/chraction.c");
#elif VERSION >= VERSION_PAL_BETA
		cdGetEdge(leftpos, rightpos, 14396, "chraction.c");
#elif VERSION >= VERSION_NTSC_1_0
		cdGetEdge(leftpos, rightpos, 14395, "chraction.c");
#else
		cdGetEdge(leftpos, rightpos, 14408, "chraction.c");
#endif
		func0f044b68(leftpos, rightpos, &spd4);
	}

	chrSetPerimEnabled(chr, true);

	return result;
}

bool chrNavTryObstacle(struct chrdata *chr, struct coord *arg1, bool arg2, struct coord *arg3, f32 radius, bool arg5, struct coord *nextpos, struct waydata *waydata, f32 arg8, s32 cdtypes, s32 arg10)
{
	struct prop *prop = chr->prop;
	struct coord sp68;
	struct coord sp5c;
	f32 norm;
	f32 angle;
	struct coord sp48;
	struct coord *sp44;
	struct coord *sp40;

	if (arg2) {
		sp44 = arg1;
		sp40 = arg3;
	} else {
		sp44 = arg3;
		sp40 = arg1;
	}

	sp68.x = arg1->x - prop->pos.x;
	sp68.y = 0.0f;
	sp68.z = arg1->z - prop->pos.z;

	if (sp68.f[0] != 0.0f || sp68.f[2] != 0.0f) {
		norm = sqrtf(sp68.f[0] * sp68.f[0] + sp68.f[2] * sp68.f[2]);

		if (norm > 0.0f) {
			norm = 1.0f / norm;
			sp68.x *= radius * norm;
			sp68.z *= radius * norm;
		} else {
			norm = 1.0f;
			sp68.z = radius * norm;
		}
	} else {
		norm = 1.0f;
		sp68.z = radius * norm;
	}

	if (radius * norm > 1.0f) {
		angle = 0.7852731347084f;
	} else {
		angle = acosf(radius * norm);
	}

	if (!arg2 && angle != 0.0f) {
		angle = M_BADTAU - angle;
	}

	sp48.x = -cosf(angle) * sp68.f[0] + sinf(angle) * sp68.f[2];
	sp48.y = 0.0f;
	sp48.z = -sinf(angle) * sp68.f[0] - cosf(angle) * sp68.f[2];

	sp5c.x = arg1->x + sp48.f[0];
	sp5c.y = arg1->y;
	sp5c.z = arg1->z + sp48.f[2];

	if (chrNavCanSeeNextPos(chr, &prop->pos, prop->rooms, &sp5c, sp44, sp40, arg8, chr->radius, cdtypes, 1)) {
		if (!arg5 || func0f03645c(chr, &prop->pos, prop->rooms, &sp5c, nextpos, cdtypes)) {
			if (arg10) {
				waydata->gotaimposobj = true;
				waydata->aimposobj.x = sp5c.x;
				waydata->aimposobj.y = sp5c.y;
				waydata->aimposobj.z = sp5c.z;
			} else {
				waydata->gotaimpos = true;
				waydata->aimpos.x = sp5c.x;
				waydata->aimpos.y = sp5c.y;
				waydata->aimpos.z = sp5c.z;
			}

			return true;
		}
	}

	return false;
}

#if VERSION >=  VERSION_NTSC_1_0
const char var7f1a8be8[] = "CHARS -> FRAMETIMESCALEI(240)  = %d";
const char var7f1a8c0c[] = "CHARS -> numseenbond1      \t= %d/%d";
const char var7f1a8c30[] = "CHARS -> numseenbond2      \t= %d/%d";
const char var7f1a8c54[] = "CHARS -> numseenbond3      \t= %d/%d";
const char var7f1a8c78[] = "CHARS -> numseenbond       \t= %d/%d";
#endif

const char var7f1a8c9c[] = "CHARS -> DEAD = %d/%d";
const char var7f1a8cb4[] = "chrdisttopad : %x -> %d : Dist=%f";

/**
 * Check for doors in front of the chr and open them if possible.
 *
 * I'm guessing the coord argument is a position in front of the chr, and the
 * collision check is looking for doors between the chr and that point.
 *
 * - Multiplayer simulants can open any doors
 * - Solo chrs cannot open doors with OBJFLAG2_AICANNOTUSE
 * - In ntsc-beta, solo chrs can bring down lasers even if they have that flag
 *
 * The chr must be within 200cm of the door unless it's a laser.
 */
struct prop *chrOpenDoor(struct chrdata *chr, struct coord *rangepos)
{
	struct prop *doorprop = NULL;

	if (cdExamCylMove03(&chr->prop->pos, chr->prop->rooms, rangepos,
				CDTYPE_BG | CDTYPE_CLOSEDDOORS | CDTYPE_AJARDOORS,
				1, 0, 0) == CDRESULT_COLLISION) {
		doorprop = cdGetObstacleProp();
	}

	if (doorprop) {
		struct doorobj *door = doorprop->door;

#if VERSION >= VERSION_NTSC_1_0
		if (chr->aibot || (door->base.flags2 & OBJFLAG2_AICANNOTUSE) == 0)
#else
		if (chr->aibot
				|| (door->base.flags2 & OBJFLAG2_AICANNOTUSE) == 0
				|| (door->doorflags & DOORFLAG_DAMAGEONCONTACT))
#endif
		{
			f32 xdiff = doorprop->pos.x - chr->prop->pos.x;
			f32 zdiff = doorprop->pos.z - chr->prop->pos.z;

			if (xdiff * xdiff + zdiff * zdiff < 200 * 200 || (door->doorflags & DOORFLAG_DAMAGEONCONTACT)) {
				chrGoPosClearRestartTtl(chr);
				doorsChooseSwingDirection(chr->prop, doorprop->door);

				if (!doorCallLift(doorprop, false)) {
					doorsRequestMode(doorprop->door, DOORMODE_OPENING);
				}
			} else {
				doorprop = NULL;
			}
		} else {
			doorprop = NULL;
		}
	}

	return doorprop;
}

/**
 * Tick a chr's navigation process when they are using the "main" method of
 * navigating.
 *
 * Main refers to the chr being on screen or close to on screen, where all
 * collision checks are enabled. This is opposed to the magic method, where
 * they are off screen and the collision checks are skipped.
 *
 * The chr will generally move towards the nextpos, which is the position of the
 * next pad/corner in the route, and open doors along the way. However they must
 * also check for obstacles ahead of them such as other chrs or doors which have
 * opened into their path. If one is found, the chr routes around the obstacle
 * and then to the next pos again.
 */
void chrNavTickMain(struct chrdata *chr, struct coord *nextpos, struct waydata *waydata, bool arg3)
{
	struct prop *prop = chr->prop;
	struct coord sp100;
	struct coord spf4;
	s32 i;
	s32 cdtypes;

	// By default, do collision checks for everything except doors that AI can
	// open, but if they're blocking a door then include all doors
	cdtypes = (CDTYPE_ALL & ~CDTYPE_DOORS) | CDTYPE_DOORSLOCKEDTOAI;

	if (chr->hidden & CHRHFLAG_BLOCKINGDOOR) {
		cdtypes = CDTYPE_ALL;
	}

	for (i = 0; i < 1; i++) {
		if (0.0f);

		if (waydata->mode == WAYMODE_INIT || waydata->mode == WAYMODE_RETRY) {
			sp100.x = nextpos->x;
			sp100.y = nextpos->y;
			sp100.z = nextpos->z;

			// Check to see if the chr can see the next pad. This is almost
			// always true, but if the chr has tried to avoid an object they
			// may have gone behind a wall and can't see the pad any more.
			if (chrNavCanSeeNextPos(chr, &prop->pos, prop->rooms, &sp100, &waydata->obstacleleft, &waydata->obstacleright, -chr->radius, chr->radius, CDTYPE_PATHBLOCKER | CDTYPE_BG, arg3)) {
				// Can see the next pad
				waydata->gotaimpos = true;
				waydata->aimpos.x = sp100.x;
				waydata->aimpos.y = sp100.y;
				waydata->aimpos.z = sp100.z;
				waydata->mode = WAYMODE_HAVEAIMPOS;
			} else if (waydata->mode == WAYMODE_INIT) {
				waydata->mode = WAYMODE_LOST1;
				waydata->iter = 0;
			} else if (waydata->mode == WAYMODE_RETRY) {
				waydata->mode = WAYMODE_LOST2;
				waydata->iter = 0;
			}
		} else if (waydata->mode == WAYMODE_LOST1) {
			// Chr has tried to avoid an obstacle, and in the process can no
			// longer see the next pad. The chr will try to get back on the
			// route by navigating to either side of the obstacle they were
			// trying to avoid.
			f32 wantclearance = chr->radius * 1.26f;

			if (chrNavTryObstacle(chr, &waydata->obstacleleft, true, &spf4, wantclearance, true, nextpos, waydata, 0, CDTYPE_PATHBLOCKER | CDTYPE_BG, 0)) {
				// Will go to left side
				waydata->mode = WAYMODE_HAVEAIMPOS;
			} else if (chrNavTryObstacle(chr, &waydata->obstacleright, false, &spf4, wantclearance, true, nextpos, waydata, 0, CDTYPE_PATHBLOCKER | CDTYPE_BG, 0)) {
				// Will go to right side
				waydata->mode = WAYMODE_HAVEAIMPOS;
			} else {
				// Can't see the obstacle either!
				// Remain in LOST1 for 5 iterations to see if line of sight
				// comes back. If not, retry the next pad again.
				waydata->iter++;

				if (waydata->iter > 5) {
					waydata->mode = WAYMODE_RETRY;
				}
			}
		} else if (waydata->mode == WAYMODE_LOST2) {
			// Chr has gone through LOST1 without seeing the obstacle, then
			// tried to find the next pad but can't see that either. Try
			// navigating to the obstacle again, but with different arguments.
			// This is a more desparate attempt at returning to the path.
			f32 wantclearance = chr->radius * 1.26f;
			u32 stack;

			if (chrNavTryObstacle(chr, &waydata->obstacleleft, true, &spf4, wantclearance, false, NULL, waydata, 0, CDTYPE_PATHBLOCKER | CDTYPE_BG, 0)) {
				// Will go to left side
				waydata->mode = WAYMODE_HAVEAIMPOS;
			} else if (chrNavTryObstacle(chr, &waydata->obstacleright, false, &spf4, wantclearance, false, NULL, waydata, 0, CDTYPE_PATHBLOCKER | CDTYPE_BG, 0)) {
				// Will go to right side
				waydata->mode = WAYMODE_HAVEAIMPOS;
			} else {
				// Still can't see the obstacle using the desparate check.
				// Remain in LOST2 for 5 iterations to see if line of sight
				// comes back.
				waydata->iter++;

				if (waydata->iter > 5) {
					// Clear any references to the obstacle we were trying to
					// avoid and attempt to restart the process. I don't think
					// this is likely to work, but there's nothing else that can
					// be done.
					waydata->gotaimposobj = waydata->gotaimpos = false;
					waydata->aimposobj.x = waydata->aimpos.x = nextpos->x;
					waydata->aimposobj.y = waydata->aimpos.y = nextpos->y;
					waydata->aimposobj.z = waydata->aimpos.z = nextpos->z;
					waydata->mode = WAYMODE_INIT;
				}
			}
		} else if (waydata->mode == WAYMODE_HAVEAIMPOS) {
			// Chr is happily walking towards a position (aim pos).
			// The position could be the next pad, or it could be an arbitrary
			// position next to an obstacle that has to be routed around.
			// Either way, check that there's no new obstacles between the chr
			// and their aim pos.
			bool hasobstacle = true;

			if (!arg3
					&& nextpos->x == waydata->aimpos.x
					&& nextpos->y == waydata->aimpos.y
					&& nextpos->z == waydata->aimpos.z) {
				hasobstacle = false;
			}

			if (chrNavCheckForObstacle(chr, &prop->pos, prop->rooms, &waydata->aimpos, &waydata->obstacleleft, &waydata->obstacleright, -chr->radius, chr->radius, cdtypes, hasobstacle)) {
				// No obstacle ahead
				waydata->gotaimposobj = true;
				waydata->mode = WAYMODE_INIT;
				waydata->aimposobj.x = waydata->aimpos.x;
				waydata->aimposobj.y = waydata->aimpos.y;
				waydata->aimposobj.z = waydata->aimpos.z;
			} else {
				// Obstacle ahead
				waydata->mode = WAYMODE_NEWOBSTACLE;
				waydata->iter = 0;
			}
		} else if (waydata->mode == WAYMODE_NEWOBSTACLE) {
			// Chr has just noticed an obstacle ahead of them which they need to
			// route around. The obstacleleft and obstacleright coordinates are
			// already populated and they indicate the left and right corners of
			// the object. This part of the code decides which side to use and
			// calculates some turning angles.
			f32 f20;
			u32 stack;
			f32 spd0;
			f32 spcc;
			u32 stack2;
			f32 f24 = chr->radius * 1.26f;

			f20 = atan2f(waydata->aimpos.x - prop->pos.x, waydata->aimpos.z - prop->pos.z);
			spd0 = f20 - atan2f(waydata->obstacleleft.x - prop->pos.x, waydata->obstacleleft.z - prop->pos.z);
			spcc = f20 - atan2f(waydata->obstacleright.x - prop->pos.x, waydata->obstacleright.z - prop->pos.z);

			if (spd0 < 0) {
				spd0 += M_BADTAU;
			}

			if (spd0 >= M_BADPI) {
				spd0 -= M_BADTAU;
			}

			if (spd0 < 0) {
				spd0 = -spd0;
			}

			if (spcc < 0) {
				spcc += M_BADTAU;
			}

			if (spcc >= M_BADPI) {
				spcc -= M_BADTAU;
			}

			if (spcc < 0) {
				spcc = -spcc;
			}

			if (spd0 < spcc) {
				f32 spc0;
				f32 spbc;
				u32 stack;
				f32 f22 = f24 * 1.1f;

				if (chrNavTryObstacle(chr, &waydata->obstacleleft, true, &spf4, f24, false, NULL, waydata, f22, cdtypes, 1)) {
					waydata->mode = WAYMODE_INIT;
					break;
				}

				spc0 = f20 - atan2f(waydata->obstacleleft.x - prop->pos.x, waydata->obstacleleft.z - prop->pos.z);
				spbc = f20 - atan2f(spf4.x - prop->pos.x, spf4.z - prop->pos.z);

				if (spc0 < 0) {
					spc0 += M_BADTAU;
				}

				if (spc0 >= M_BADPI) {
					spc0 -= M_BADTAU;
				}

				if (spc0 < 0) {
					spc0 = -spc0;
				}

				if (spbc < 0) {
					spbc += M_BADTAU;
				}

				if (spbc >= M_BADPI) {
					spbc -= M_BADTAU;
				}

				if (spbc < 0) {
					spbc = -spbc;
				}

				if (spbc < spc0) {
					if (chrNavTryObstacle(chr, &spf4, false, &spf4, f24, false, NULL, waydata, f22, cdtypes, 1)) {
						waydata->mode = WAYMODE_INIT;
						break;
					}
				}
			} else {
				f32 spb0;
				f32 spac;
				f32 f22 = f24 * 1.1f;

				if (chrNavTryObstacle(chr, &waydata->obstacleright, false, &spf4, f24, false, NULL, waydata, f22, cdtypes, 1)) {
					waydata->mode = WAYMODE_INIT;
					break;
				}

				spb0 = f20 - atan2f(waydata->obstacleright.x - prop->pos.x, waydata->obstacleright.z - prop->pos.z);
				spac = f20 - atan2f(spf4.x - prop->pos.x, spf4.z - prop->pos.z);

				if (spb0 < 0) {
					spb0 += M_BADTAU;
				}

				if (spb0 >= M_BADPI) {
					spb0 -= M_BADTAU;
				}

				if (spb0 < 0) {
					spb0 = -spb0;
				}

				if (spac < 0) {
					spac += M_BADTAU;
				}

				if (spac >= M_BADPI) {
					spac -= M_BADTAU;
				}

				if (spac < 0) {
					spac = -spac;
				}

				if (spac < spb0) {
					if (chrNavTryObstacle(chr, &spf4, true, &spf4, f24, false, NULL, waydata, f22, cdtypes, 1)) {
						waydata->mode = WAYMODE_INIT;
						break;
					}
				}
			}

			waydata->iter++;

			if (waydata->iter > 5) {
				waydata->gotaimposobj = false;
				waydata->mode = WAYMODE_INIT;
			}
		}
	}

	if (!waydata->gotaimposobj) {
		waydata->aimposobj.x = waydata->aimpos.x;
		waydata->aimposobj.y = waydata->aimpos.y;
		waydata->aimposobj.z = waydata->aimpos.z;
	}

	// Every 10 ticks, attempt to open any door in front of the chr
	if (waydata->age % 10 == 0) {
		struct prop *doorprop = chrOpenDoor(chr, &waydata->aimposobj);

		// Consider returning to stand animation while door is opening
		if (doorprop
				&& chr->aibot == NULL
				&& (chr->hidden & CHRHFLAG_BLOCKINGDOOR) == 0
				&& !chrGoPosIsWaiting(chr)) {
			chrChooseStandAnimation(chr, 16);
			chr->lastmoveok60 = g_Vars.lvframe60;
		}

		// Resume moving if there's no longer a door in the way
		// or if the chr is blocking the door
		if (!doorprop || (chr->hidden & CHRHFLAG_BLOCKINGDOOR)) {
			if (chr->aibot == NULL
					&& chrGoPosIsWaiting(chr)
					&& chr->liftaction != LIFTACTION_WAITINGFORLIFT
					&& chr->liftaction != LIFTACTION_WAITINGONLIFT) {
				chrGoPosChooseAnimation(chr);
			}

			if (!doorprop) {
				chr->hidden &= ~CHRHFLAG_BLOCKINGDOOR;
			}
		}
	}

	// Handle turning and anim speed
	{
		chr->unk32c_21 = chr->act_gopos.turnspeed != 0;

		func0f043f2c(chr, &waydata->aimposobj, chr->act_gopos.flags, &chr->act_gopos.turnspeed);

		if (chr->aibot == NULL && !chrGoPosIsWaiting(chr)) {
			if ((chr->act_gopos.flags & GOPOSMASK_SPEED) == GOPOSFLAG_RUN) {
				if (chr->act_gopos.turnspeed) {
					if (!chr->unk32c_21) {
						modelSetAnimSpeed(chr->model, 0.25f, 8);
					}
				} else {
					if (chr->unk32c_21) {
						if (chr->chrflags & CHRCFLAG_RUNFASTER) {
							modelSetAnimSpeed(chr->model, 0.65f, 32);
						} else {
							modelSetAnimSpeed(chr->model, 0.5f, 32);
						}
					}
				}
			} else if ((chr->act_gopos.flags & GOPOSMASK_SPEED) == GOPOSFLAG_JOG) {
				if (chr->act_gopos.turnspeed) {
					modelSetAnimSpeed(chr->model, 0.4f, 0);
				} else {
					modelSetAnimSpeed(chr->model, 0.5f, 0);
				}
			}
		}
	}
}

bool chrGoPosUpdateLiftAction(struct chrdata *chr, u32 curpadflags, bool arg2, bool arrivingatlift, s16 curpadnum, s32 nextpadnum)
{
	bool advance = false;
	struct pad nextpad;
	u32 nextpadflags = 0;
	f32 nextground;
	f32 lifty;
	struct liftobj *lift;
	struct prop *liftprop = liftFindByPad(curpadnum);
	u32 stack;

	if (!liftprop) {
		return false;
	}

	lift = (struct liftobj *) liftprop->obj;

	lifty = liftGetY(lift);

	if (nextpadnum >= 0) {
		padUnpack(nextpadnum, PADFIELD_POS | PADFIELD_ROOM | PADFIELD_FLAGS, &nextpad);
		nextpadflags = nextpad.flags;
	}

	if (curpadflags & PADFLAG_AIWAITLIFT) {
		if (nextpadflags & PADFLAG_AIONLIFT) {
			if (arrivingatlift || chr->liftaction == LIFTACTION_WAITINGFORLIFT) {
				if (nextpadflags);

				// Begin entering lift if lift is under 40cm above this level
				advance = (lifty <= chr->manground + 40);

				// ...and (if solo mode) lift is over 1m under this level
				// (this logic allows MP simulants to drop down onto lifts)
				if (!g_Vars.normmplayerisrunning && advance) {
					advance = (lifty > chr->manground - 100);
				}

				// ...and if the lift has a door, is at least halfway open
				if (advance && lift->doors[lift->levelcur] && lift->doors[lift->levelcur]->frac < 0.5f) {
					advance = false;
				}
			}

			if (!advance) {
				if (arrivingatlift && chr->liftaction != LIFTACTION_WAITINGFORLIFT) {
					// Just arrived at lift
					chr->liftaction = LIFTACTION_WAITINGFORLIFT;

					chrChooseStandAnimation(chr, 16);

					if (nextpadnum >= 0) {
						// Call the lift
						chrOpenDoor(chr, &nextpad.pos);
					}
				}
			} else {
				// Enter lift
				chr->liftaction = LIFTACTION_NOTUSINGLIFT;

				if (chrGoPosIsWaiting(chr)) {
					chrGoPosChooseAnimation(chr);
				}
			}
		} else {
			// On a wait lift pad, but the next pad in the route is not on the
			// lift, so the chr is running past the lift without using it.
			if (arrivingatlift) {
				advance = true;
				chr->liftaction = LIFTACTION_NOTUSINGLIFT;
			}
		}
	} else if (curpadflags & PADFLAG_AIONLIFT) {
		if (nextpadflags & PADFLAG_AIWAITLIFT) {
			// Waiting for door to close or lift to arrive at destination
			if (arg2 || chr->liftaction == LIFTACTION_WAITINGONLIFT) {
				// Continue waiting
				s16 rooms[] = {0, -1};
				u32 stack2;

				rooms[0] = nextpad.room;

				nextground = cdFindFloorYColourTypeAtPos(&nextpad.pos, rooms, NULL, NULL);

				// Begin exiting lift if lift is 30cm under destination or higher
				advance = (lifty >= nextground - 30);

				// ...and (if solo) lift is under 1m above destination
				if (!g_Vars.normmplayerisrunning && advance) {
					advance = (lifty < nextground + 100);
				}

				// ...and if the lift has a door, is at least halfway open
				if (advance && lift->doors[lift->levelcur] && lift->doors[lift->levelcur]->frac < 0.5f) {
					advance = false;
				}
			}

			if (!advance) {
				if (arg2 && chr->liftaction != LIFTACTION_WAITINGONLIFT) {
					// Just arrived inside lift
					chr->liftaction = LIFTACTION_WAITINGONLIFT;
					chrChooseStandAnimation(chr, 16);
				}
			} else {
				// Start disembarking
				chr->liftaction = LIFTACTION_ONLIFT;

				if (chrGoPosIsWaiting(chr)) {
					chrGoPosChooseAnimation(chr);
				}
			}
		} else {
			// Not our stop? Not sure why advance is true here. I guess the chr
			// can't go anywhere anyway because the next pad is above or below
			// them.
			if (arg2) {
				advance = true;
				chr->liftaction = LIFTACTION_ONLIFT;
			}
		}
	}

	return advance;
}

s16 chrGoPosGetNextPadNum(struct chrdata *chr)
{
	if (chr->act_gopos.waypoints[chr->act_gopos.curindex + 1]) {
		return chr->act_gopos.waypoints[chr->act_gopos.curindex + 1]->padnum;
	}

	return -1;
}

void chrTickGoPos(struct chrdata *chr)
{
	struct waypoint *waypoint;
	struct coord nextpos;
	s16 nextrooms[8];
	struct prop *prop = chr->prop;
	bool enteringmagic = false;
	struct pad pad;
	bool sp240 = true;
	struct coord curwppos;
	s16 curwprooms[8];
	u32 curwpflags;

	chr->act_gopos.flags &= ~(GOPOSFLAG_DUCK | GOPOSFLAG_WALKDIRECT);

	if (chr->hidden & CHRHFLAG_NEEDANIM) {
		if (modelIsAnimMerging(chr->model)) {
			return;
		}

		chrGoPosChooseAnimation(chr);

		chr->hidden &= ~CHRHFLAG_NEEDANIM;
	}

	chr->act_gopos.waydata.age++;

	// If stuck for 1 second
	if (chr->lastmoveok60 < g_Vars.lvframe60 - TICKS(60)) {
#if VERSION >= VERSION_NTSC_1_0
		if (chr->goposforce >= 0) {
			// Try and warp the chr past whatever obstacle is blocking them?
			struct coord sp196 = {0, 0, 0};

			chrDamageByMisc(chr, 1, &sp196, NULL, NULL);

			chr->lastmoveok60 = g_Vars.lvframe60;
			return;
		}
#endif

		// Goposforce was not set - restart the action to try and find a new route
		chrGoToRoomPos(chr, &chr->act_gopos.endpos, chr->act_gopos.endrooms, chr->act_gopos.flags);
	}

	chrGoPosConsiderRestart(chr);
	chrGoPosGetCurWaypointInfoWithFlags(chr, &curwppos, curwprooms, &curwpflags);

	// If magic mode ended over 3 seconds ago, not multiplayer, not in view of
	// eyespy, pad is nothing special and not in lift, then enter the magic move
	// mode.
	if (chr->act_gopos.waydata.mode != WAYMODE_MAGIC
			&& chr->act_gopos.waydata.lastvisible60 + TICKS(180) < g_Vars.lvframe60
			&& g_Vars.normmplayerisrunning == false
			&& chrIsRoomOffScreen(chr, &curwppos, curwprooms) // related to eyespy
			&& (curwpflags & (PADFLAG_AIWAITLIFT | PADFLAG_AIONLIFT)) == 0
			&& chr->inlift == false) {
		enteringmagic = true;
		chrGoPosInitMagic(chr, &chr->act_gopos.waydata, &curwppos, &prop->pos);
	}

#if VERSION >= VERSION_NTSC_1_0
	if (g_NumChrsSeenPlayerRecently2 >= 9
			&& (chr->hidden & CHRHFLAG_00400000)
			&& (chr->flags & CHRFLAG0_ACTIVATEALARM) == 0) {
		chrStop(chr);
		return;
	}
#else
	if (g_NumChrsSeenPlayerRecently2 >= 10) {
		chrStop(chr);
		return;
	}
#endif

	// If goposforce is set then decrease it on each tick. If it's reached -1
	// then stop the chr. I guess goposforce is not only used to warp past
	// obstacles, but is also used as a run countdown timer.
#if VERSION >= VERSION_NTSC_1_0
	if (chr->goposforce >= 0) {
		chr->goposforce -= g_Vars.lvupdate60;

		if (chr->goposforce < 0) {
			chrStop(chr);
			return;
		}
	}
#endif

	// Check if chr needs to exit magic mode
	if (chr->act_gopos.waydata.mode == WAYMODE_MAGIC) {
		if ((!enteringmagic && ((prop->flags & (PROPFLAG_ONANYSCREENPREVTICK | PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONTHISSCREENTHISTICK)) || !chrIsRoomOffScreen(chr, &curwppos, curwprooms)))
				|| (curwpflags & (PADFLAG_AIWAITLIFT | PADFLAG_AIONLIFT))
				|| chr->inlift) {
			// Exiting magic mode
			chrGoPosInitExpensive(chr);
			chr->act_gopos.waydata.lastvisible60 = g_Vars.lvframe60;
			return;
		}

		chrNavTickMagic(chr, &chr->act_gopos.waydata, func0f0370a8(chr), &curwppos, curwprooms);
	} else {
		bool advance = false;
		bool sp188;
		bool sp184;
		f32 sp180;
		f32 sp176;
		f32 sp172;
		f32 sp168;
		bool candosomething;
		f32 sp160;
		f32 sp156;
		struct waypoint *next;
		struct pad pad2;

		waypoint = chr->act_gopos.waypoints[chr->act_gopos.curindex];

		if (waypoint) {
			padUnpack(waypoint->padnum, PADFIELD_FLAGS | PADFIELD_POS, &pad);

			// Both of these functions are calculating something with the coords
			// and are returning a boolean. There are no write operations.
			sp188 = posIsArrivingAtPos(&chr->prevpos, &prop->pos, &pad.pos, 30);
			sp184 = posIsArrivingLaterallyAtPos(&chr->prevpos, &prop->pos, &pad.pos, 30);

			if (pad.flags & PADFLAG_AIDUCK) {
				chr->act_gopos.flags |= GOPOSFLAG_DUCK;
			} else if (pad.flags & PADFLAG_10000) {
				chr->act_gopos.flags |= GOPOSFLAG_WALKDIRECT;
			}

			if ((pad.flags & PADFLAG_AIWAITLIFT) || (pad.flags & PADFLAG_AIONLIFT)) {
				advance = chrGoPosUpdateLiftAction(chr, pad.flags, sp184, sp188, waypoint->padnum, chrGoPosGetNextPadNum(chr));
			} else {
				if (sp188 || (sp184 && (chr->inlift || (pad.flags & PADFLAG_8000)))) {
					advance = true;
				}
			}
		} else {
			// No more waypoints - chr is finished
			if (posIsArrivingAtPos(&chr->prevpos, &prop->pos, &chr->act_gopos.endpos, 30) ||
					(chr->inlift && posIsArrivingLaterallyAtPos(&chr->prevpos, &prop->pos, &chr->act_gopos.endpos, 30))) {
				chrStop(chr);
				return;
			}
		}

		if (advance) {
			chrGoPosAdvanceWaypoint(chr);
		}

		// Every 10 ticks: Check something a couple of waypoints ahead
		// This might be checking if the chr has line of sight to that pad and can
		// walk straight to it.
		if (chr->act_gopos.waydata.age % 10 == 5 || (chr->act_gopos.flags & GOPOSFLAG_INIT)) {
			// Load waypoint that the chr is running to
			waypoint = chr->act_gopos.waypoints[chr->act_gopos.curindex];

			if (waypoint) {
				padUnpack(waypoint->padnum, PADFIELD_FLAGS, &pad);

				if ((pad.flags & PADFLAG_AIWALKDIRECT) == 0) {
					// The waypoint the chr is running to doesn't have
					// PADFLAG_AIWALKDIRECT, so the chr is able to ignore it and run
					// towards the next one if it's in sight.

					// Load the next waypoint after the one the chr is running to
					waypoint = chr->act_gopos.waypoints[chr->act_gopos.curindex + 1];

					if (waypoint) {
						padUnpack(waypoint->padnum, PADFIELD_FLAGS, &pad);

						if ((pad.flags & PADFLAG_AIWALKDIRECT) == 0) {
							// And this one doesn't have PADFLAG_AIWALKDIRECT either,
							// so the chr can consider skipping this one too.
							waypoint = chr->act_gopos.waypoints[chr->act_gopos.curindex + 2];

							if (waypoint) {
								padUnpack(waypoint->padnum, PADFIELD_ROOM | PADFIELD_POS, &pad);

								nextpos.x = pad.pos.x;
								nextpos.y = pad.pos.y;
								nextpos.z = pad.pos.z;

								nextrooms[0] = pad.room;
								nextrooms[1] = -1;
							} else {
								nextpos.x = chr->act_gopos.endpos.x;
								nextpos.y = chr->act_gopos.endpos.y;
								nextpos.z = chr->act_gopos.endpos.z;

								roomsCopy(chr->act_gopos.endrooms, nextrooms);
							}

							// Some bbox related check
							if (func0f03654c(chr, &prop->pos, prop->rooms, &nextpos, nextrooms, NULL, chr->radius * 1.2f, CDTYPE_PATHBLOCKER | CDTYPE_BG)) {
								chrGoPosAdvanceWaypoint(chr);
								chrGoPosAdvanceWaypoint(chr);
							}
						}
					}
				}
			}
		}

		if (chr->act_gopos.waydata.age % 10 == 0 || (chr->act_gopos.flags & GOPOSFLAG_INIT)) {
			waypoint = chr->act_gopos.waypoints[chr->act_gopos.curindex];

			if (waypoint) {
				candosomething = (chr->act_gopos.flags & GOPOSFLAG_INIT) != 0;
				padUnpack(waypoint->padnum, PADFIELD_FLAGS | PADFIELD_POS, &pad);

				next = chr->act_gopos.waypoints[chr->act_gopos.curindex + 1];

				if (next) {
					padUnpack(next->padnum, PADFIELD_ROOM | PADFIELD_POS, &pad2);

					if ((pad.flags & (PADFLAG_AIWAITLIFT | PADFLAG_AIONLIFT))
							&& (pad2.flags & (PADFLAG_AIWAITLIFT | PADFLAG_AIONLIFT))) {
						candosomething = false;
					}
				}

				if ((pad.flags & PADFLAG_AIWALKDIRECT) == 0 || candosomething) {
					if (next) {
						nextpos.x = pad2.pos.x;
						nextpos.y = pad2.pos.y;
						nextpos.z = pad2.pos.z;

						nextrooms[0] = pad2.room;
						nextrooms[1] = -1;
					} else {
						nextpos.x = chr->act_gopos.endpos.x;
						nextpos.y = chr->act_gopos.endpos.y;
						nextpos.z = chr->act_gopos.endpos.z;

						roomsCopy(chr->act_gopos.endrooms, nextrooms);
					}

					// I suspect this is making the chr turn to face the next pad
					if ((pad.flags & PADFLAG_AIWALKDIRECT) && candosomething) {
						if (true) {
							sp180 = prop->pos.x - pad.pos.x;
							sp176 = prop->pos.z - pad.pos.z;
							sp172 = nextpos.x - pad.pos.x;
							sp168 = nextpos.z - pad.pos.z;
						}

						sp156 = sqrtf((sp180 * sp180 + sp176 * sp176) * (sp172 * sp172 + sp168 * sp168));

						if (sp156 > 0) {
							sp160 = acosf((sp180 * sp172 + sp176 * sp168) / sp156);

							// sp160 < DEG2RAD(45) || sp160 > DEG2RAD(315)
							if (sp160 < 0.7852731347084f || sp160 > 5.4969120025635f) {
								if (func0f03654c(chr, &prop->pos, prop->rooms, &nextpos, nextrooms, NULL, chr->radius * 1.2f, CDTYPE_PATHBLOCKER | CDTYPE_BG)) {
									chrGoPosAdvanceWaypoint(chr);
								}
							}
						}
					} else {
						if (func0f03654c(chr, &prop->pos, prop->rooms, &nextpos, nextrooms, NULL, chr->radius * 1.2f, CDTYPE_PATHBLOCKER | CDTYPE_BG)) {
							chrGoPosAdvanceWaypoint(chr);
						}
					}
				}
			}

			chr->act_gopos.flags &= ~GOPOSFLAG_INIT;
		}

		waypoint = chr->act_gopos.waypoints[chr->act_gopos.curindex];

		if (waypoint) {
			padUnpack(waypoint->padnum, PADFIELD_POS, &pad);

			nextpos.x = pad.pos.x;
			nextpos.y = pad.pos.y;
			nextpos.z = pad.pos.z;
		} else {
			nextpos.x = chr->act_gopos.endpos.x;
			nextpos.y = chr->act_gopos.endpos.y;
			nextpos.z = chr->act_gopos.endpos.z;

			if (chr->aibot && chr->myaction == MA_AIBOTGETITEM) {
				sp240 = false;
			}
		}

		chrNavTickMain(chr, &nextpos, &chr->act_gopos.waydata, sp240);
	}
}

void chraTick(struct chrdata *chr)
{
	u32 race = CHRRACE(chr);

	if (g_Vars.lvupdate240 < 1) {
		return;
	}

	if (chr->actiontype == ACT_INIT) {
		chr->chrflags |= CHRCFLAG_00000001;
		func0f02e9a0(chr, 0);
		chr->sleep = 0;
	}

	chr->soundtimer += g_Vars.lvupdate60;
	chr->talktimer += g_Vars.lvupdate60;

#if VERSION < VERSION_PAL_BETA
	if (chr->aibot) {
		chr->aibot->unk030 += g_Vars.lvupdate60;
	}
#endif

	if (chr->hidden & CHRHFLAG_TIMER_RUNNING) {
		chr->timer60 += g_Vars.lvupdate60;
	}

	chr->sleep -= g_Vars.lvupdate60;

	if (chr->sleep < 0
			|| (chr->chrflags & CHRCFLAG_00040000)
			|| chr->alertness >= 65
			|| (chr->aibot && (chr->actiontype == ACT_DIE || chr->actiontype == ACT_DEAD))) {
		u8 pass = race == RACE_HUMAN;
		chr->sleep = 0;

		if (chr->prop) {
			switch (chr->actiontype) {
			case ACT_STAND:           chrTickStand(chr);           break;
			case ACT_DIE:             chrTickDie(chr);             break;
			case ACT_ARGH:            chrTickArgh(chr);            break;
			case ACT_DEAD:            chrTickDead(chr);            break;
			case ACT_ATTACK:          chrTickAttack(chr);          break;
			case ACT_GOPOS:           chrTickGoPos(chr);           break;
			case ACT_DRUGGEDCOMINGUP: chrTickDruggedComingUp(chr); break;
			case ACT_DRUGGEDDROP:     chrTickDruggedDrop(chr);     break;
			case ACT_DRUGGEDKO:       chrTickDruggedKo(chr);       break;
			}
		}

#if VERSION >= VERSION_NTSC_1_0
		chr->hidden &= ~CHRHFLAG_IS_HEARING_TARGET;
		chr->hidden2 &= ~CHRH2FLAG_0040;
#else
		chr->hidden &= ~(CHRHFLAG_IS_HEARING_TARGET | CHRHFLAG_00000200);
#endif

		if (pass) {
			footstepCheckDefault(chr);
		}
	} else {
		footstepCheckMagic(chr);
	}
}

/**
 * Execute background tasks.
 *
 * - Calculate number of engaged chrs
 * - Handle switching to new cutscenes when playing all
 * - Run BG scripts
 * - Choose which corpses to fade
 */
void chraTickBg(void)
{
	s32 i;
	s32 numchrs = chrsGetNumSlots();
	s32 numaliveonscreen;
	s32 numdeadonscreen;
	s32 onscreenlen;
	s32 offscreenlen;
#if VERSION >= VERSION_NTSC_1_0
	s32 spawnslen;
#endif
	struct chrdata *onscreen[5];
	struct chrdata *offscreen[5];
#if VERSION >= VERSION_NTSC_1_0
	struct chrdata *spawns[10];
#endif
	s32 writeindex;
	s32 maxdeadonscreen;

#if VERSION >= VERSION_NTSC_1_0
	static u32 var80068454 = 0;
#endif

	static s32 mosteveralive = 0;

	numaliveonscreen = 0;

#if VERSION >= VERSION_NTSC_1_0
	spawnslen = 0;
	numdeadonscreen = 0;
#else
	numdeadonscreen = 0;
	onscreenlen = 0;
	offscreenlen = 0;
#endif

	// Count the number of chrs who are engaged with the player.
	// When these numbers are high, chrs can ignore gopos commands.
	// NTSC beta has a simple version of this logic in a loop
	// near the end of this function.
	g_NumChrsWithPlayerTarget = 0;
	g_NumChrsSeenPlayer = 0;
	g_NumChrsSeenPlayerRecently = 0;
	g_NumChrsSeenPlayerRecently2 = 0;

	var80068454++;

	if (var80068454 > 10) {
		var80068454 = 0;
	}

	// Calculate alive/dead counters. For *spawned* chrs that have died,
	// allow 10 corpses and start fading if there's more.
	{
		s32 numalive = 0;

		for (i = 0; i < numchrs; i++) {
			struct chrdata *chr = &g_ChrSlots[i];

			if (chr->model && chr->prop) {
				if (chr->actiontype != ACT_DEAD && chr->actiontype != ACT_DRUGGEDKO) {
					numalive++;
				}

				if (chr->prop->flags & PROPFLAG_ONANYSCREENPREVTICK) {
					if (chr->actiontype != ACT_DEAD && chr->actiontype != ACT_DRUGGEDKO) {
						numaliveonscreen++;
					} else if (chr->actiontype == ACT_DRUGGEDKO) {
						if ((chr->chrflags & CHRCFLAG_KEEPCORPSEKO) == 0) {
							numdeadonscreen++;
						}
					} else {
						numdeadonscreen++;
					}
				}

				if (chr->actiontype == ACT_DEAD
						|| (chr->actiontype == ACT_DRUGGEDKO && (chr->chrflags & CHRCFLAG_KEEPCORPSEKO) == 0)) {
					if (chr->hidden2 & CHRH2FLAG_SPAWNED) {
						spawns[spawnslen] = chr;
						spawnslen++;

						if (spawnslen >= 10) {
							writeindex = random() % spawnslen;
							chrFadeCorpse(spawns[writeindex]);
							spawns[writeindex] = spawns[spawnslen - 1];
							spawnslen--;
						}
					}
				}
			}
		}

		if (numalive > mosteveralive) {
			mosteveralive = numalive;
		}
	}

	// Calculate how many corpses are allowed on screen. Ideally no more than
	// 5 chrs (alive or dead) to keep the number of polygons low.
	maxdeadonscreen = 5 - numaliveonscreen;

	// If the game is lagging, take the number of 60ths over 6 since the
	// previous frame and reduce the limit by that amount. So if it's been, say,
	// 8 60ths since the last frame then the max corpses will be reduced by 2.
	// This is why corpses are more likely to fade on screen when you change
	// weapons - the lag spike from changing guns triggers a lower corpse limit.
	if (g_Vars.lvupdate60 > 6) {
		maxdeadonscreen = maxdeadonscreen - g_Vars.lvupdate60 + 6;
	}

	if (maxdeadonscreen < 0) {
		maxdeadonscreen = 0;
	}

	// Decide which corpses to fade.
	// NTSC Beta implements its engagement counter here.
	if (numdeadonscreen) {
		numdeadonscreen = 0;
		onscreenlen = 0;
		offscreenlen = 0;

		for (i = 0; i < numchrs; i++) {
			struct chrdata *chr = &g_ChrSlots[i];

			if (chr->model) {
				if (chr->actiontype == ACT_DEAD
						|| (chr->actiontype == ACT_DRUGGEDKO && chr->prop && (chr->chrflags & CHRCFLAG_KEEPCORPSEKO) == 0)) {
					if (chr->prop->flags & PROPFLAG_ONANYSCREENPREVTICK) {
						// On-screen
						if (chr->act_dead.fadetimer60 < 0 && !chr->act_dead.fadenow) {
							chrFadeCorpse(chr);
						}
					} else {
						// Off-screen
						if (!chr->act_dead.fadewheninvis) {
							offscreen[offscreenlen] = chr;
							offscreenlen++;

							// Allow up to 5 corpses off-screen
							if (offscreenlen >= (VERSION >= VERSION_NTSC_1_0 ? 5 : 6)) {
								writeindex = random() % offscreenlen;

								if (offscreen[writeindex]->actiontype != ACT_DEAD) {
									chrBeginDead(offscreen[writeindex]);
								}

								chrFadeCorpseWhenOffScreen(offscreen[writeindex]);
								offscreen[writeindex] = offscreen[offscreenlen - 1];
								offscreenlen--;
							}
						}
					}
				}
			}
		}
	}

	if (1);
}

f32 chrGetAngleToPos(struct chrdata *chr, struct coord *pos)
{
	f32 fVar3;
	f32 fVar2;
	f32 fVar4;
	struct prop *prop;

	if (chr->prop->type == PROPTYPE_PLAYER) {
		u32 playernum = playermgrGetPlayerNumByProp(chr->prop);
		fVar3 = (360 - g_Vars.players[playernum]->vv_theta) * (M_BADTAU / 360);
	} else {
		fVar3 = chrGetInverseTheta(chr);
	}

	prop = chr->prop;
	fVar2 = atan2f(pos->x - prop->pos.x, pos->z - prop->pos.z);
	fVar4 = fVar2 - fVar3;

	if (fVar2 < fVar3) {
		fVar4 += M_BADTAU;
	}

	return fVar4;
}

void chrGetAttackEntityPos(struct chrdata *chr, u32 attackflags, s32 entityid, struct coord *pos, s16 *rooms)
{
	struct prop *targetprop;
	struct chrdata *targetchr;
	struct pad pad;

	if (attackflags & ATTACKFLAG_AIMATCHR) {
		// Aiming at a chr by chrnum
		targetchr = chrFindById(chr, entityid);

		if (!targetchr || !targetchr->prop) {
			targetchr = chr;
		}

		pos->x = targetchr->prop->pos.x;
		pos->y = targetchr->prop->pos.y;
		pos->z = targetchr->prop->pos.z;

		if (targetchr) {
			chr = targetprop->chr;
		} else {
			chr = NULL;
		}

		if (chr);

		roomsCopy(targetchr->prop->rooms, rooms);
	} else if (attackflags & ATTACKFLAG_AIMATPAD) {
		// Aiming at a pad by padnum
		s32 padnum = chrResolvePadId(chr, entityid);
		padUnpack(padnum, PADFIELD_POS | PADFIELD_ROOM, &pad);

		pos->x = pad.pos.x;
		pos->y = pad.pos.y;
		pos->z = pad.pos.z;

		rooms[0] = pad.room;
		rooms[1] = -1;
	} else {
		// Aiming at the chr's preconfigured target
		targetprop = chrGetTargetProp(chr);

		pos->x = targetprop->pos.x;
		pos->y = targetprop->pos.y;
		pos->z = targetprop->pos.z;

		if (targetprop->type == PROPTYPE_CHR && targetprop->chr) {
			chr = targetprop->chr;
		} else {
			chr = NULL;
		}

		if (chr);

		roomsCopy(targetprop->rooms, rooms);
	}
}

f32 func0f048fcc(struct chrdata *chr, u8 reverse)
{
	f32 result;

	struct prop *chrprop = chr->prop;
	struct prop *targetprop = chrGetTargetProp(chr);

	f32 xdiff = chrprop->pos.x - targetprop->pos.x;
	f32 zdiff = chrprop->pos.z - targetprop->pos.z;

	f32 angle1 = atan2f(-xdiff, -zdiff);
	f32 angle2 = chrGetInverseTheta(chr) + M_PI * (s32)reverse;

	result = angle1 - angle2;

	if (angle1 < angle2) {
		result += M_BADTAU;
	}

	return result;
}

bool chrIsTargetInFov(struct chrdata *chr, u8 arg1, u8 reverse)
{
	f32 angle = func0f048fcc(chr, reverse);

	if ((angle < arg1 * 0.024539785459638f && angle < M_PI)
			|| (angle > M_BADTAU - arg1 * 0.024539785459638f && angle > M_PI)) {
		return true;
	}

	return false;
}

bool chrIsLookingAtPos(struct chrdata *chr, struct coord *pos, u8 arg2)
{
	f32 angle = chrGetAngleToPos(chr, pos);

	if ((angle < arg2 * 0.024539785459638f && angle < M_PI) ||
			(M_BADTAU - arg2 * 0.024539785459638f < angle && M_PI < angle)) {
		return true;
	}

	return false;
}

f32 chrGetDistanceToTarget(struct chrdata *chr)
{
	struct prop *prop = chrGetTargetProp(chr);
	return propGetDistanceToProp(chr->prop, prop);
}

f32 chrGetDistanceToCurrentPlayer(struct chrdata *chr)
{
	return propGetDistanceToProp(chr->prop, g_Vars.currentplayer->prop);
}

f32 propGetDistanceToProp(struct prop *a, struct prop *b)
{
	f32 xdiff = a->pos.x - b->pos.x;
	f32 ydiff = a->pos.y - b->pos.y;
	f32 zdiff = a->pos.z - b->pos.z;

	return sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);
}

f32 chrGetDistanceToPad(struct chrdata *chr, s32 pad_id)
{
	struct prop *prop = chr->prop;
	f32 xdiff, ydiff, zdiff;
	f32 distance = 0;
	struct pad pad;
	pad_id = chrResolvePadId(chr, pad_id);

#if VERSION >= VERSION_NTSC_1_0
	if (pad_id >= 0)
#endif
	{
		padUnpack(pad_id, PADFIELD_POS, &pad);
		xdiff = pad.pos.x - prop->pos.x;
		ydiff = pad.pos.y - prop->pos.y;
		zdiff = pad.pos.z - prop->pos.z;
		distance = sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);
	}

	return distance;
}

f32 chrGetDistanceToCoord(struct chrdata *chr, struct coord *pos)
{
	f32 xdiff = pos->x - chr->prop->pos.x;
	f32 ydiff = pos->y - chr->prop->pos.y;
	f32 zdiff = pos->z - chr->prop->pos.z;

	return sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);
}

f32 chrGetLateralDistanceToCoord(struct chrdata *chr, struct coord *pos)
{
	f32 xdiff = pos->x - chr->prop->pos.x;
	f32 zdiff = pos->z - chr->prop->pos.z;

	return sqrtf(xdiff * xdiff + zdiff * zdiff);
}

f32 chrGetSquaredDistanceToCoord(struct chrdata *chr, struct coord *pos)
{
	f32 xdiff = pos->x - chr->prop->pos.x;
	f32 ydiff = pos->y - chr->prop->pos.y;
	f32 zdiff = pos->z - chr->prop->pos.z;

	return xdiff * xdiff + ydiff * ydiff + zdiff * zdiff;
}

s32 chrResolvePadId(struct chrdata *chr, s32 pad_id)
{
	if (pad_id == 9000) {
		pad_id = chr->padpreset1;
	}

	return pad_id;
}

s32 chrResolveId(struct chrdata *ref, s32 id)
{
	if (ref) {
		switch (id) {
		case CHR_SEESHOT:
			id = ref->chrseeshot;
			break;
		case CHR_SEEDIE:
			id = ref->chrseedie;
			break;
		case CHR_PRESET:
			id = ref->chrpreset1;
			break;
		case CHR_SELF:
			id = ref->chrnum;
			break;
		case CHR_CLONE:
			id = ref->chrdup;
			break;
		case CHR_BOND:
			if (g_Vars.bond && g_Vars.bond->prop && g_Vars.bond->prop->chr) {
				id = g_Vars.bond->prop->chr->chrnum;
			}
			break;
		case CHR_P1P2:
			{
				u32 index = g_Vars.bondplayernum;
				struct player *player = g_Vars.players[index];
				if (player && player->prop && player->prop->chr) {
					id = player->prop->chr->chrnum;
				}
			}
			break;
		case CHR_TARGET:
			{
				struct prop *target = chrGetTargetProp(ref);
				if ((target->type == PROPTYPE_CHR || target->type == PROPTYPE_PLAYER) && target->chr) {
					id = target->chr->chrnum;
				}
			}
			break;
		}
	} else { // ref is NULL
		switch (id) {
		case CHR_BOND:
			if (g_Vars.bond && g_Vars.bond->prop && g_Vars.bond->prop->chr) {
				id = g_Vars.bond->prop->chr->chrnum;
			}
			break;
		case CHR_P1P2:
			{
				struct player *player = g_Vars.players[g_Vars.bondplayernum];
				if (player && player->prop && player->prop->chr) {
					id = player->prop->chr->chrnum;
				}
			}
			break;
		}
	}

	return id;
}

struct chrdata *chrFindById(struct chrdata *basechr, s32 chrnum)
{
	struct chrdata *chr;
	s32 lower;
	s32 upper;
	s32 i;

	chrnum = chrResolveId(basechr, chrnum);
	return chrFindByLiteralId(chrnum);
}

s32 propGetIndexByChrId(struct chrdata *basechr, s32 chrnum)
{
	s32 index;

	if (chrnum == CHR_BOND || chrnum == CHR_BOND) {
		index = g_Vars.bond->prop - g_Vars.props;
	} else {
		struct chrdata *chr = chrFindById(basechr, chrnum);

		if (chr && chr->prop) {
			index = chr->prop - g_Vars.props;
		} else {
			index = -1;
		}
	}

	return index;
}

f32 chrGetDistanceToChr(struct chrdata *chr1, s32 chr2num)
{
	struct prop *prop1 = chr1->prop;
	struct chrdata *chr2 = chrFindById(chr1, chr2num);
	f32 distance = 0;

	if (chr2 && chr2->prop) {
		f32 xdiff = chr2->prop->pos.x - prop1->pos.x;
		f32 ydiff = chr2->prop->pos.y - prop1->pos.y;
		f32 zdiff = chr2->prop->pos.z - prop1->pos.z;
		distance = sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);
	}

	return distance;
}

bool chrHasFlag(struct chrdata *chr, u32 flag, u8 bank)
{
	if (bank == 0) {
		return (chr->flags & flag) != 0;
	} else {
		return (chr->flags2 & flag) != 0;
	}
}

bool chrHasStageFlag(struct chrdata *chr, u32 flag)
{
	return (g_StageFlags & flag) != 0;
}

bool chrCompareTeams(struct chrdata *chr1, struct chrdata *chr2, u8 checktype)
{
	if (chr1 && chr1->prop) {
		if (checktype == COMPARE_ANY) {
			return true;
		}

		if (checktype == COMPARE_FRIENDS) { // Return true if chrs are friends
			if ((g_MpSetup.options & MPOPTION_TEAMSENABLED) && chr2->team == chr1->team) {
				return true;
			}
		} else if (checktype == COMPARE_ENEMIES) { // Return true if chrs are enemies
			if ((g_MpSetup.options & MPOPTION_TEAMSENABLED) == 0 || chr2->team != chr1->team) {
				return true;
			}
		}
	}

	return false;
}

bool chrIsPosOffScreen(struct coord *pos, s16 *rooms)
{
	bool offscreen = true;
	s32 i;

	if (env0f1666f8(pos, 0)) {
		for (i = 0; rooms[i] != -1; i++) {
			if (roomIsOnscreen(rooms[i])) {
				break;
			}
		}

		if (rooms[i] != -1) {
			// Room is visible by player
			offscreen = !camIsPosInScreenBox(pos, 200, func0f158140(rooms[i]));
		}
	}

	return offscreen;
}

/**
 * Test if a chr can be spawned into or nearby the given position, taking into
 * consideration collision checks.
 *
 * If the spawn can happen, the position and rooms are updated with the actual
 * position to be used and the function returns true.
 *
 * If the spawn cannot happen, the function return false.
 */
#if VERSION >= VERSION_NTSC_1_0
bool chrAdjustPosForSpawn(f32 chrradius, struct coord *pos, s16 *rooms, f32 angle, bool allowonscreen, bool ignorebg, bool arg6)
{
	struct coord testpos;
	s32 i;
	u32 types;
	s16 testrooms[8];
	f32 ymin;
	f32 ymax = 200;
	f32 curangle = angle;
	f32 ground;

	if (ignorebg) {
		types = CDTYPE_ALL & ~CDTYPE_BG;
		allowonscreen = true;
	} else {
		types = CDTYPE_ALL;
	}

	if (arg6) {
		// Skip testing the given pos, and just do the surrounding checks below.
		// Add 45 degrees to the angle here, but this isn't necessary.
		curangle += 0.7852731347084f;

		if (curangle >= M_BADTAU) {
			curangle -= M_BADTAU;
		}
	} else {
		// Check that the chr isn't being spawned out of bounds, and do a volume
		// test reaching 200cm above and below the chr's feet... unless there is
		// ground under the chr (highly likely), in which case reduce the volume
		// to be tested to the ground Y value. I'm not sure why this is useful,
		// because if the chr was being spawned on top of another chr or object
		// then the calculated ground value would be raised.
		ymin = -200;
		ground = cdFindGroundAtCyl(pos, chrradius, rooms, NULL, NULL);

		if (ground > -100000 && ground - pos->y < -200) {
			ymin = ground - pos->y;
		}

		if (cdTestVolume(pos, chrradius, rooms, types, CHECKVERTICAL_YES, ymax, ymin) != CDRESULT_COLLISION
				&& (allowonscreen || chrIsPosOffScreen(pos, rooms))) {
			return true;
		}
	}

	// Try 60cm in 8 directions
	for (i = 0; i < 8; i++) {
		testpos.x = pos->x + sinf(curangle) * 60;
		testpos.y = pos->y;
		testpos.z = pos->z + cosf(curangle) * 60;

		if ((arg6 && cdTestCylMove04(pos, rooms, &testpos, testrooms, CDTYPE_ALL & ~CDTYPE_PLAYERS, 1, ymax, -200) != CDRESULT_COLLISION)
				|| (!arg6 && cdTestLos11(pos, rooms, &testpos, testrooms, CDTYPE_BG))) {
			chr0f021fa8(NULL, &testpos, testrooms);
			ground = cdFindGroundAtCyl(&testpos, chrradius, testrooms, 0, 0);
			ymin = -200;

			if (ground > -100000 && ground - pos->y < -200) {
				ymin = ground - pos->y;
			}

			if (cdTestVolume(&testpos, chrradius, testrooms, CDTYPE_ALL, CHECKVERTICAL_YES, ymax, ymin) != CDRESULT_COLLISION
					&& (allowonscreen || chrIsPosOffScreen(&testpos, testrooms))
					&& (!arg6 || ground > -100000)) {
				pos->x = testpos.x;
				pos->y = testpos.y;
				pos->z = testpos.z;
				roomsCopy(testrooms, rooms);
				return true;
			}
		}

		curangle += 0.7852731347084f;

		if (curangle >= M_BADTAU) {
			curangle -= M_BADTAU;
		}
	}

	return false;
}
#else
/**
 * ntsc-beta's version of this function doesn't have the arg6 argument
 * nor out of bounds checking, and lacks the reduction for the volume test.
 */
bool chrAdjustPosForSpawn(f32 chrradius, struct coord *pos, s16 *rooms, f32 angle, bool allowonscreen, bool ignorebg)
{
	struct coord testpos;
	s32 i;
	u32 types;
	s16 testrooms[8];
	f32 curangle = angle;

	if (ignorebg) {
		types = CDTYPE_ALL & ~CDTYPE_BG;
		allowonscreen = true;
	} else {
		types = CDTYPE_ALL;
	}

	if (cdTestVolume(pos, chrradius, rooms, types, CHECKVERTICAL_YES, 200, -200) != CDRESULT_COLLISION
			&& (allowonscreen || chrIsPosOffScreen(pos, rooms))) {
		return true;
	}

	for (i = 0; i < 8; i++) {
		testpos.x = sinf(curangle) * 60 + pos->x;
		testpos.y = pos->y;
		testpos.z = cosf(curangle) * 60 + pos->z;

		if (cdTestLos11(pos, rooms, &testpos, testrooms, CDTYPE_BG)
				&& cdTestVolume(&testpos, chrradius, testrooms, CDTYPE_ALL, CHECKVERTICAL_YES, 200, -200.0f) != CDRESULT_COLLISION
				&& (allowonscreen || chrIsPosOffScreen(&testpos, testrooms))) {
			pos->x = testpos.x;
			pos->y = testpos.y;
			pos->z = testpos.z;
			roomsCopy(testrooms, rooms);
			return true;
		}

		curangle += 0.7852731347084f;

		if (curangle >= M_BADTAU) {
			curangle -= M_BADTAU;
		}
	}

	return false;
}
#endif

bool chrMoveToPos(struct chrdata *chr, struct coord *pos, s16 *rooms, f32 angle, bool allowonscreen)
{
	struct coord pos2;
	s16 rooms2[8];
	bool result = false;
	u32 nodetype;
	union modelrwdata *rwdata;
	struct player *player;
	f32 ground;

	pos2.x = pos->x;
	pos2.y = pos->y;
	pos2.z = pos->z;

	roomsCopy(rooms, rooms2);
	propSetPerimEnabled(chr->prop, false);

#if VERSION >= VERSION_NTSC_1_0
	if (chrAdjustPosForSpawn(chr->radius, &pos2, rooms2, angle, (chr->hidden & CHRHFLAG_00100000) != 0, allowonscreen, (chr->hidden & CHRHFLAG_00000200) != 0))
#else
	if (chrAdjustPosForSpawn(chr->radius, &pos2, rooms2, angle, (chr->hidden & CHRHFLAG_00100000) != 0, allowonscreen))
#endif
	{
		ground = cdFindGroundInfoAtCyl(&pos2, chr->radius, rooms2, &chr->floorcol,
				&chr->floortype, NULL, &chr->floorroom, NULL, NULL);

		chr->ground = ground;
		chr->manground = ground;
		chr->sumground = ground * (PAL ? 8.4175090789795f : 9.999998f);
		chr->prop->pos.x = pos2.x;
		chr->prop->pos.y = pos2.y;
		chr->prop->pos.z = pos2.z;

		propDeregisterRooms(chr->prop);
		roomsCopy(rooms2, chr->prop->rooms);
		chr0f0220ac(chr);
		modelSetRootPosition(chr->model, &pos2);

		nodetype = chr->model->filedata->rootnode->type;

		if ((nodetype & 0xff) == MODELNODETYPE_CHRINFO) {
			rwdata = modelGetNodeRwData(chr->model, chr->model->filedata->rootnode);
			rwdata->chrinfo.ground = ground;
		}

		chr->chrflags |= CHRCFLAG_00000001;
		chrSetLookAngle(chr, angle);

		if (chr->prop->type == PROPTYPE_PLAYER) {
			player = g_Vars.players[playermgrGetPlayerNumByProp(chr->prop)];
			player->vv_manground = ground;
			player->vv_ground = ground;
			player->vv_theta = ((M_BADTAU - angle) * 360.0f) / M_BADTAU;
			player->vv_verta = 0;
			player->unk1c64 = 1;
		}

		result = true;
	}

	propSetPerimEnabled(chr->prop, true);

	return result;
}

bool chrRunFromPos(struct chrdata *chr, u32 goposflags, f32 rundist, struct coord *frompos)
{
	f32 curdistfrompos;
	struct coord delta;
	s16 rooms[8];

	if (chrIsReadyForOrders(chr)) {
		delta.x = chr->prop->pos.x - frompos->x;
		delta.y = chr->prop->pos.y;
		delta.z = chr->prop->pos.z - frompos->z;

		// @bug: This check should be &&. The runfrompos will fail if the
		// frompos is on the same X or Z axis as the chr, which is unlikely
		// because it's a floating point number.
		if (delta.f[0] == 0.0f || delta.f[2] == 0.0f) {
			return false;
		}

		curdistfrompos = sqrtf(delta.f[0] * delta.f[0] + delta.f[2] * delta.f[2]);
		delta.x *= rundist / curdistfrompos;
		delta.z *= rundist / curdistfrompos;

		chrSetPerimEnabled(chr, false);

		if (cdExamLos08(&chr->prop->pos, chr->prop->rooms, &delta, CDTYPE_ALL, GEOFLAG_WALL) == CDRESULT_COLLISION) {
#if VERSION >= VERSION_JPN_FINAL
			cdGetPos(&delta, 18592, "chr/chraction.c");
#elif VERSION >= VERSION_PAL_FINAL
			cdGetPos(&delta, 18555, "chr/chraction.c");
#elif VERSION >= VERSION_PAL_BETA
			cdGetPos(&delta, 18550, "chraction.c");
#elif VERSION >= VERSION_NTSC_1_0
			cdGetPos(&delta, 18547, "chraction.c");
#else
			cdGetPos(&delta, 18277, "chraction.c");
#endif
		}

		chrSetPerimEnabled(chr, true);

		func0f065e74(&chr->prop->pos, chr->prop->rooms, &delta, rooms);

		return chrGoToRoomPos(chr, &delta, rooms, goposflags);
	}

	return false;
}
