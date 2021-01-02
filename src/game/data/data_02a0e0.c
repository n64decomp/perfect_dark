#include <ultra64.h>
#include "game/chr/chraicommands.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/cheats.h"
#include "game/game_107fb0.h"
#include "game/endscreen.h"
#include "game/camdraw.h"
#include "game/timing.h"
#include "game/game_173a00.h"
#include "game/utils.h"
#include "game/mplayer/ingame.h"
#include "game/mplayer/setup.h"
#include "game/mplayer/scenarios.h"
#include "game/game_1a3340.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_02a0e0.h"
#include "stagesetup.h"
#include "types.h"

s32 g_MenuTrack = -1;
u32 var800840c4 = 0x00000000;
s32 g_TemporaryPrimaryTrack = -1;
s32 g_TemporaryAmbientTrack = -1;
s32 var800840d0 = -1;
u32 var800840d4 = 0x00000000;
u32 var800840d8 = 0x00000000;
s32 var800840dc = 0;
u32 var800840e0 = 0x0000000f;
u32 var800840e4 = 0x00000000;
s32 var800840e8 = 0;
u16 var800840ec = 0x5000;
u32 var800840f0 = 0x00000000;
u32 var800840f4 = 0x00000000;
u32 var800840f8 = 0x00000078;
u32 var800840fc = 0x00000000;
u32 var80084100 = (u32)&var7f1b78c0;
u32 var80084104 = (u32)&var7f1b78c8;
u32 var80084108 = (u32)&var7f1b78d4;
u32 var8008410c = (u32)&var7f1b78f4;
u32 var80084110 = (u32)&var7f1b7900;
u32 var80084114 = (u32)&var7f1b7908;
u32 var80084118 = (u32)&var7f1b7910;
u32 var8008411c = 0x00000000;
u32 g_LanguageId = 0;

// 2a144
u16 g_LangFiles[] = {
	/* 0*/ 0,
	/* 1*/ FILE_LAMEE,
	/* 2*/ FILE_LARCHE,
	/* 3*/ FILE_LARKE,
	/* 4*/ FILE_LASHE,
	/* 5*/ FILE_LAZTE,
	/* 6*/ FILE_LCATE,
	/* 7*/ FILE_LCAVEE,
	/* 8*/ FILE_LARECE,
	/* 9*/ FILE_LCRADE,
	/*10*/ FILE_LCRYPE,
	/*11*/ FILE_LDAME,
	/*12*/ FILE_LDEPOE,
	/*13*/ FILE_LDESTE,
	/*14*/ FILE_LDISHE,
	/*15*/ FILE_LEARE,
	/*16*/ FILE_LELDE,
	/*17*/ FILE_LIMPE,
	/*18*/ FILE_LJUNE,
	/*19*/ FILE_LLEEE,
	/*20*/ FILE_LLENE,
	/*21*/ FILE_LLIPE,
	/*22*/ FILE_LLUEE,
	/*23*/ FILE_LOATE,
	/*24*/ FILE_LPAME,
	/*25*/ FILE_LPETEE,
	/*26*/ FILE_LREFE,
	/*27*/ FILE_LRITE,
	/*28*/ FILE_LRUNE,
	/*29*/ FILE_LSEVBE,
	/*30*/ FILE_LSEVE,
	/*31*/ FILE_LSEVXE,
	/*32*/ FILE_LSEVXBE,
	/*33*/ FILE_LSHOE,
	/*34*/ FILE_LSILOE,
	/*35*/ FILE_LSTATE,
	/*36*/ FILE_LTRAE,
	/*37*/ FILE_LWAXE,
	/*38*/ FILE_LGUNE,
	/*39*/ FILE_LTITLEE,
	/*40*/ FILE_LMPMENUE,
	/*41*/ FILE_LPROPOBJE,
	/*42*/ FILE_LMPWEAPONSE,
	/*43*/ FILE_LOPTIONSE,
	/*44*/ FILE_LMISCE,
	/*45*/ FILE_LUFFE,
	/*46*/ FILE_LOLDE,
	/*47*/ FILE_LATEE,
	/*48*/ FILE_LLAME,
	/*49*/ FILE_LMP1E,
	/*50*/ FILE_LMP2E,
	/*51*/ FILE_LMP3E,
	/*52*/ FILE_LMP4E,
	/*53*/ FILE_LMP5E,
	/*54*/ FILE_LMP6E,
	/*55*/ FILE_LMP7E,
	/*56*/ FILE_LMP8E,
	/*57*/ FILE_LMP9E,
	/*58*/ FILE_LMP10E,
	/*59*/ FILE_LMP11E,
	/*60*/ FILE_LMP12E,
	/*61*/ FILE_LMP13E,
	/*62*/ FILE_LMP14E,
	/*63*/ FILE_LMP15E,
	/*64*/ FILE_LMP16E,
	/*65*/ FILE_LMP17E,
	/*66*/ FILE_LMP18E,
	/*67*/ FILE_LMP19E,
	/*68*/ FILE_LMP20E,
};

u32 var800841b0 = 0x0006ddd0;
u32 var800841b4 = 0x00000000;
u32 var800841b8 = 0x00000004;
u32 var800841bc = 0x00000003;
u32 var800841c0 = 0x00000003;
u32 var800841c4 = 0x00000003;
u32 var800841c8 = 0x00000002;
u32 var800841cc = 0x00000002;
u32 var800841d0 = 0x00000001;
u32 var800841d4 = 0x00000001;
u32 var800841d8 = 0x00000001;
u32 var800841dc = 0x00000001;
u32 var800841e0 = 0x00000001;
u32 var800841e4 = 0x00000001;
u32 var800841e8 = 0x00000001;
u32 var800841ec = 0x00000000;
u32 var800841f0 = 0x00000001;
u32 var800841f4 = 0x00000000;
u32 var800841f8 = 0x00000000;
u32 var800841fc = 0x00000000;
u32 var80084200 = 0x00000000;
u32 var80084204 = 0x00000001;
u32 var80084208 = 0x00000000;
u32 var8008420c = 0x00000000;
u32 var80084210 = 0x00000000;
u32 var80084214 = 0x00000000;
u32 var80084218 = 0x00000000;
u32 var8008421c = 0x00000000;
u32 var80084220 = 0x00000100;
u32 var80084224 = 0x00000020;
u32 var80084228 = 0x00000100;
u32 var8008422c = 0x00000020;
u32 var80084230 = 0x00000100;
u32 var80084234 = 0x00000010;
u32 var80084238 = 0x00000008;
u32 var8008423c = 0x00000100;
u32 var80084240 = 0x00000010;
u32 var80084244 = 0x00000100;
u32 var80084248 = 0x00000010;
u32 var8008424c = 0x00000100;
u32 var80084250 = 0x00000010;
u32 var80084254 = 0x00000020;
u32 var80084258 = 0x00000010;
u32 var8008425c = 0x00000018;
u32 var80084260 = 0x0000000f;
u32 var80084264 = 0x00000010;
u32 var80084268 = 0x00000008;
u32 var8008426c = 0x00000004;
u32 var80084270 = 0x00000008;
u32 var80084274 = 0x00000004;
u32 var80084278 = 0x00000010;
u32 var8008427c = 0x00000010;
u32 var80084280 = 0x00000010;
u32 var80084284 = 0x00000010;
u32 var80084288 = 0x00000000;
u32 var8008428c = 0x00000000;
u32 var80084290 = 0x00000000;
u32 var80084294 = 0x00000000;
u32 var80084298 = 0x00000003;
u32 var8008429c = 0x00000003;
u32 var800842a0 = 0x00000003;
u32 var800842a4 = 0x00000004;
u32 var800842a8 = 0x00000004;
u32 var800842ac = 0x00000002;
u32 var800842b0 = 0x00000002;
u32 var800842b4 = 0x00000002;
u32 var800842b8 = 0x00000002;
u32 var800842bc = 0x00000003;
u32 var800842c0 = 0x00000002;
u32 var800842c4 = 0x00000003;
u32 var800842c8 = 0x00000002;
u32 var800842cc = 0x00000002;
u32 var800842d0 = 0x00000001;
u32 var800842d4 = 0x00000000;
u32 var800842d8 = 0x00000001;
u32 var800842dc = 0x00000000;
u32 var800842e0 = 0x00000001;
u32 var800842e4 = 0x00000000;
u32 var800842e8 = 0x00000001;
u32 var800842ec = 0x00000000;
u32 var800842f0 = 0x00000000;
u32 var800842f4 = 0x00000000;
u32 var800842f8 = 0x00000000;
u32 var800842fc = 0x00000000;
u32 var80084300 = 0x00000000;
u32 var80084304 = 0x00000000;
u32 var80084308 = 0x00000000;
u32 var8008430c = 0x00000000;
u32 var80084310 = 0x00000000;
u32 var80084314 = 0x00008000;
u32 var80084318 = 0x00008000;
u32 var8008431c = 0x0000c000;
u32 var80084320 = 0x0000c000;
u32 var80084324 = 0x00000000;
u32 var80084328 = 0x00000000;
u32 var8008432c = 0x00000000;

u32 var80084330 = 0x80878088;
u32 var80084334 = 0x06000000;

// 2a358
struct something something_2a358 = {
	&var80084330, &var80084334, 0x00020001,
};

u32 var80084344 = 0x80878088;
u32 var80084348 = 0x01000000;

// 2a36c
struct something something_2a36c = {
	&var80084344, &var80084348, 0x00020001,
};

u32 var80084358 = 0x807e807f;
u32 var8008435c = 0x10000000;

// 2a380
struct something something_2a380 = {
	&var80084358, &var8008435c, 0x00020001,
};

u32 var8008436c = 0x8079807b;
u32 var80084370 = 0x11000000;

// 2a394
struct something something_2a394 = {
	&var8008436c, &var80084370, 0x00020001,
};

u32 var80084380 = 0x80770000;
u32 var80084384 = 0x03040500;

// 2a3a8
struct something something_2a3a8 = {
	&var80084380, &var80084384, 0x00010003,
};

u32 var80084394 = 0x807d0000;
u32 var80084398 = 0x01000000;

// 2a3bc
struct something something_2a3bc = {
	&var80084394, &var80084398, 0x00010001,
};

u32 var800843a8 = 0x80848085;
u32 var800843ac = 0x02000000;

// 2a3d0
struct something something_2a3d0 = {
	&var800843a8, &var800843ac, 0x00020001,
};

u32 var800843bc = 0x80818082;
u32 var800843c0 = 0x80830000;
u32 var800843c4 = 0x02000000;

// 2a3e8
struct something something_2a3e8 = {
	&var800843bc, &var800843c4, 0x00030001,
};

u32 var800843d4 = 0x80860000;
u32 var800843d8 = 0x01000000;

// 2a3fc
struct something something_2a3fc = {
	&var800843d4, &var800843d8, 0x00010001,
};

u32 var800843e8 = 0x8089808a;
u32 var800843ec = 0x01060000;

// 2a410
struct something something_2a410 = {
	&var800843e8, &var800843ec, 0x00020002,
};

u32 var800843fc = 0x80760000;
u32 var80084400 = 0x02000000;

// 2a424
struct something something_2a424 = {
	&var800843fc, &var80084400, 0x00010001,
};

u32 var80084410 = 0x80770000;
u32 var80084414 = 0x03040500;

// 2a438
struct something something_2a438 = {
	&var80084410, &var80084414, 0x00010003,
};

// 2a444
struct something something_2a444 = {
	NULL, NULL, 0x00000000,
};

u32 var80084430 = 0x80800000;
u32 var80084434 = 0x00000000;

// 2a458
struct something something_2a458 = {
	&var80084430, &var80084434, 0x00010001,
};

u32 var80084444 = 0x80800000;
u32 var80084448 = 0x00000000;

// 2a46c
struct something something_2a46c = {
	&var80084444, &var80084448, 0x00010001,
};

// 2a478
struct something *somethings[] = {
	/* 0*/ &something_2a358,
	/* 1*/ &something_2a36c,
	/* 2*/ &something_2a380,
	/* 3*/ &something_2a394,
	/* 4*/ &something_2a3a8,
	/* 5*/ &something_2a458,
	/* 6*/ &something_2a3bc,
	/* 7*/ &something_2a3d0,
	/* 8*/ &something_2a3e8,
	/* 9*/ &something_2a3fc,
	/*10*/ &something_2a410,
	/*11*/ &something_2a424,
	/*12*/ &something_2a438,
	/*13*/ &something_2a444,
	/*14*/ &something_2a46c,
};

// 2a4b4
u32 somethingpointers[] = {
	/* 0*/ (u32)&var7f1b7ba0,
	/* 1*/ (u32)&var7f1b7ba8,
	/* 2*/ (u32)&var7f1b7bb0,
	/* 3*/ (u32)&var7f1b7bb8,
	/* 4*/ (u32)&var7f1b7bc0,
	/* 5*/ (u32)&var7f1b7bc8,
	/* 6*/ (u32)&var7f1b7bd8,
	/* 7*/ (u32)&var7f1b7be0,
	/* 8*/ (u32)&var7f1b7be8,
	/* 9*/ (u32)&var7f1b7bec,
	/*10*/ (u32)&var7f1b7bf4,
	/*11*/ (u32)&var7f1b7c00,
	/*12*/ (u32)&var7f1b7c04,
	/*13*/ (u32)&var7f1b7c10,
	/*14*/ (u32)&var7f1b7c18,
};

u32 var800844d0 = 0x00000000;
u32 var800844d4 = 0x00000000;
u32 var800844d8 = 0x00000000;
u32 var800844dc = 0x00000000;
u32 var800844e0 = 0x00000103;
u32 var800844e4 = 0x00000000;
u32 var800844e8 = 0x00000000;
u32 var800844ec = 0x00000000;
u32 var800844f0 = 0x00000000;
u32 var800844f4 = 0;
u32 var800844f8 = 0x00000000;
u32 var800844fc = 0x00000000;

// 2a520
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

u32 var800845c8 = 0x00000000;
u32 var800845cc = 0x00000000;
u32 var800845d0 = 0x497423f0;
f32 var800845d4 = 0.00001f;
s32 var800845d8 = 1;
u32 var800845dc = 0x00000000;
u32 var800845e0 = 0x00000000;
u32 var800845e4 = 0x00000000;
u32 var800845e8 = 0x00000000;
u32 var800845ec = 0x3f800000;
u32 var800845f0 = 0x00000000;
u32 var800845f4 = 0x00000000;
u32 var800845f8 = 0x00000000;
u32 var800845fc = 0x3f800000;
u32 var80084600 = 0x3f800000;
u32 var80084604 = 0x00000000;
u32 var80084608 = 0x00000000;
u32 var8008460c = 0xffffffff;
u32 var80084610 = 0x00000000;
u32 var80084614 = 0x00000000;
u32 var80084618 = 0x00000000;
u32 var8008461c = 0x00000004;
u32 var80084620 = 0x00000000;
u32 var80084624 = 0x00000000;
u32 var80084628 = 0x00000000;
u32 var8008462c = 0x00000000;

// 2a650
struct menuitem g_MpEndGameMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x02000020, L_MPMENU(291), 0x00000000, NULL }, // "Are you sure?"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPMENU(292), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000020, L_MPMENU(293), 0x00000000, menuhandlerMpEndGame }, // "End Game"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2a6b4
struct menudialog g_MpEndGameMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU(290), // "End Game"
	g_MpEndGameMenuItems,
	NULL,
	0x00000000,
	NULL,
};

// 2a6cc
struct menuitem g_MpPauseControlMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&mpMenuTextChallengeName, 0x00000000, menuhandler00178018 },
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&mpMenuTextScenarioName, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_MPWEAPONS(162), (u32)&mpMenuTextInGameLimit, menuhandlerMpInGameLimitLabel }, // "Time Limit:"
	{ MENUITEMTYPE_LABEL,       1, 0x00000200, L_MPWEAPONS(163), (u32)&mpMenuTextInGameLimit, menuhandlerMpInGameLimitLabel }, // "Score Limit:"
	{ MENUITEMTYPE_LABEL,       2, 0x00000200, L_MPWEAPONS(164), (u32)&mpMenuTextInGameLimit, menuhandlerMpInGameLimitLabel }, // "Team Score Limit:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(286), (u32)&menutextMatchTime, NULL }, // "Game Time:"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000020, (u32)&menutextPauseOrUnpause, 0x00000000, menuhandlerMpPause },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000024, L_MPMENU(287), 0x00000000, (void *)&g_MpEndGameMenuDialog }, // "End Game"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2a794
struct menudialog g_MpPauseControlMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(285), // "Control"
	g_MpPauseControlMenuItems,
	NULL,
	0x00000000,
	NULL,
};

// 2a7ac
struct menuitem g_MpInventoryMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00000000, 0x00000078, 0x00000042, menuhandler00106178 },
	{ MENUITEMTYPE_MARQUEE,     0, 0x00000a00, (u32)&mpMenuTextWeaponDescription, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2a7e8
struct menudialog g_MpPauseInventoryMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(284), // "Inventory"
	g_MpInventoryMenuItems,
	NULL,
	0x00000000,
	&g_MpPauseControlMenuDialog,
};

// 2a800
struct menudialog menudialog_2a800 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(284), // "Inventory"
	g_MpInventoryMenuItems,
	NULL,
	0x00000000,
	&menudialog_18d78,
};

// 2a818
struct menudialog menudialog_2a818 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(284), // "Inventory"
	g_MpInventoryMenuItems,
	NULL,
	0x00000000,
	&menudialog_18d90,
};

// 2a830
struct menuitem g_MpPlayerStatsMenuItems[] = {
	{ MENUITEMTYPE_PLAYERSTATS, 0, 0x00000000, 0x00000000, 0x00000000, menuhandler00177e00 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2a858
struct menudialog g_MpPausePlayerStatsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f1783a0,
	g_MpPlayerStatsMenuItems,
	NULL,
	0x00000000,
	&g_MpPauseInventoryMenuDialog,
};

// 2a870
struct menudialog g_MpEndscreenPlayerStatsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f1783a0,
	g_MpPlayerStatsMenuItems,
	NULL,
	0x00000000,
	NULL,
};

// 2a888
struct menuitem g_MpPlayerRankingMenuItems[] = {
	{ MENUITEMTYPE_RANKING,     0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2a8b0
struct menudialog g_MpPausePlayerRankingMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(276), // "Player Ranking"
	g_MpPlayerRankingMenuItems,
	NULL,
	0x00000000,
	&g_MpPausePlayerStatsMenuDialog,
};

// 2a8c8
struct menudialog g_MpEndscreenPlayerRankingMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(276), // "Player Ranking"
	g_MpPlayerRankingMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenPlayerStatsMenuDialog,
};

// 2a8e0
struct menuitem g_MpTeamRankingMenuItems[] = {
	{ MENUITEMTYPE_RANKING,     0, 0x00000000, 0x00000001, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2a908
struct menudialog g_MpPauseTeamRankingMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(279), // "Team Ranking"
	g_MpTeamRankingMenuItems,
	NULL,
	0x00000000,
	&g_MpPausePlayerRankingMenuDialog,
};

// 2a920
struct menudialog g_MpEndscreenTeamRankingMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(279), // "Team Ranking"
	g_MpTeamRankingMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenPlayerRankingMenuDialog,
};

// 2a938
u16 g_OrdinalSuffixes[] = {
	L_MPMENU(264), // "1st"
	L_MPMENU(265), // "2nd"
	L_MPMENU(266), // "3rd"
	L_MPMENU(267), // "4th"
	L_MPMENU(268), // "5th"
	L_MPMENU(269), // "6th"
	L_MPMENU(270), // "7th"
	L_MPMENU(271), // "8th"
	L_MPMENU(272), // "9th"
	L_MPMENU(273), // "10th"
	L_MPMENU(274), // "11th"
	L_MPMENU(275), // "12th"
};

// 2a950
struct menuitem g_MpGameOverMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x01000010, (u32)&mpGetCurrentPlayerName, (u32)&mpMenuTextPlacementWithSuffix, menuhandler001785c4 },
	{ MENUITEMTYPE_LABEL,       0, 0x01000000, L_MPMENU(261), (u32)&mpMenuTextPlayerTitle, menuhandler00178a94 }, // "Title:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_MPMENU(262), 0x00000000, NULL }, // "Weapon of Choice:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000120, (u32)&mpMenuTextWeaponOfChoiceName, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00200210, L_MPMENU(263), 0x00000000, menuhandler001786d8 }, // "Awards:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000120, (u32)&mpMenuTextAward1, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000120, (u32)&mpMenuTextAward2, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2aa18
struct menudialog g_MpEndscreenIndividualGameOverMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(260), // "Game Over"
	g_MpGameOverMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenPlayerRankingMenuDialog,
};

// 2aa30
struct menudialog g_MpEndscreenTeamGameOverMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(260), // "Game Over"
	g_MpGameOverMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenTeamRankingMenuDialog,
};

// 2aa48
struct menudialog g_MpEndscreenChallengeCompletedMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPWEAPONS(165), // "Challenge Completed!"
	g_MpTeamRankingMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenIndividualGameOverMenuDialog,
};

// 2aa60
struct menudialog g_MpEndscreenChallengeCheatedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS(167), // "Challenge Cheated!"
	g_MpTeamRankingMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenIndividualGameOverMenuDialog,
};

// 2aa78
struct menudialog g_MpEndscreenChallengeFailedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS(166), // "Challenge Failed!"
	g_MpTeamRankingMenuItems,
	NULL,
	0x00000000,
	&g_MpEndscreenIndividualGameOverMenuDialog,
};

// 2aa90
struct menuitem g_MpEndscreenConfirmPlayerNameMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS(250), 0x00000000, NULL }, // "Confirm player name:"
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000000, menuhandler00178bf4 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2aacc
struct menudialog g_MpEndscreenConfirmPlayerNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(142), // "Player Name"
	g_MpEndscreenConfirmPlayerNameMenuItems,
	NULL,
	0x00000000,
	NULL,
};

// 2aae4
struct menuitem g_MpEndscreenSavePlayerMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPWEAPONS(247), 0x00000000, NULL }, // "Save new player and statistics?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x0000002c, L_MPWEAPONS(248), 0x00000000, (void *)&g_MpEndscreenConfirmPlayerNameMenuDialog }, // "Save Now"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPWEAPONS(249), 0x00000000, NULL }, // "No Thanks!"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2ab34
struct menudialog g_MpEndscreenSavePlayerMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(246), // "Save Player"
	g_MpEndscreenSavePlayerMenuItems,
	NULL,
	0x00000004,
	NULL,
};

u32 var80084b2c = 0x00000000;

// 2ab50
struct menuitem menuitems_2ab50[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(196), 0x00000000, NULL }, // "Are you sure you want to drop out?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(197), 0x00000000, menuhandlerMpDropOut }, // "Drop Out"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(198), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2aba0
struct menudialog menudialog_2aba0 = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU(195), // "Drop Out"
	menuitems_2ab50,
	NULL,
	0x00000000,
	NULL,
};

// 2abb8
struct mparena g_MpArenas[] = {
	// Stage, unlock, name
	{ STAGE_MP_SKEDAR,     0,                          L_MPMENU(119) },
	{ STAGE_MP_PIPES,      0,                          L_MPMENU(120) },
	{ STAGE_MP_RAVINE,     MPFEATURE_STAGE_RAVINE,     L_MPMENU(121) },
	{ STAGE_MP_G5BUILDING, MPFEATURE_STAGE_G5BUILDING, L_MPMENU(122) },
	{ STAGE_MP_SEWERS,     MPFEATURE_STAGE_SEWERS,     L_MPMENU(123) },
	{ STAGE_MP_WAREHOUSE,  MPFEATURE_STAGE_WAREHOUSE,  L_MPMENU(124) },
	{ STAGE_MP_GRID,       MPFEATURE_STAGE_GRID,       L_MPMENU(125) },
	{ STAGE_MP_RUINS,      MPFEATURE_STAGE_RUINS,      L_MPMENU(126) },
	{ STAGE_MP_AREA52,     0,                          L_MPMENU(127) },
	{ STAGE_MP_BASE,       MPFEATURE_STAGE_BASE,       L_MPMENU(128) },
	{ STAGE_MP_FORTRESS,   MPFEATURE_STAGE_FORTRESS,   L_MPMENU(130) },
	{ STAGE_MP_VILLA,      MPFEATURE_STAGE_VILLA,      L_MPMENU(131) },
	{ STAGE_MP_CARPARK,    MPFEATURE_STAGE_CARPARK,    L_MPMENU(132) },
	{ STAGE_MP_TEMPLE,     MPFEATURE_STAGE_TEMPLE,     L_MPMENU(133) },
	{ STAGE_MP_COMPLEX,    MPFEATURE_STAGE_COMPLEX,    L_MPMENU(134) },
	{ STAGE_MP_FELICITY,   MPFEATURE_STAGE_FELICITY,   L_MPMENU(135) },
	{ 1,                   0,                          L_MPMENU(136) }, // "Random"
};

// 2ac20
u32 var80084c00[] = {
	0x00000000, 0x50740000, // "Dark"
	0x0000000d, 0x50750000, // "Classic"
	0x00000010, 0x50760000, // "Custom"
};

// 2ac38
u16 g_MpControlStyleLabels[] = {
	L_OPTIONS(239), // "1.1"
	L_OPTIONS(240), // "1.2"
	L_OPTIONS(241), // "1.3"
	L_OPTIONS(242), // "1.4"
};

// 2ac40
u16 g_MpAimModeLabels[] = {
	L_MPMENU(213), // "Hold"
	L_MPMENU(214), // "Toggle"
};

// 2ac44
struct menuitem menuitems_mpsavechr[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(191), 0x00000000, NULL }, // "Your player file is always saved automatically."
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(192), 0x00000000, NULL }, // "Save a copy now?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(193), 0x00000000, NULL }, // "No"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(194), 0x00000000, menuhandlerMpConfirmSaveChr }, // "Yes"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2aca8
struct menudialog g_MpSaveChrMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(190), // "Confirm"
	menuitems_mpsavechr,
	NULL,
	0x00000000,
	NULL,
};

// 2acc0
struct menuitem menuitems_mpsavesetupname[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(189), 0x00000000, NULL }, // "Enter a name for your game setup file:"
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000000, menuhandlerMpPlayerName },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2acfc
struct menudialog menudialog_mpsavesetupname = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(188), // "Game File Name"
	menuitems_mpsavesetupname,
	NULL,
	0x00000000,
	NULL,
};

// 2ad14
struct menuitem menuitems_mpsavesetup[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_MPWEAPONS(230), (u32)&mpMenuTextSetupName, NULL }, // "Name:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000230, (u32)&filemgrMenuTextDeviceName, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(184), 0x00000000, NULL }, // "Do you want to save over your original game file?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(185), 0x00000000, menuhandlerMpSaveSetupOverwrite }, // "Save Over Original"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(186), 0x00000000, menuhandlerMpSaveSetupCopy }, // "Save Copy"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(187), 0x00000000, NULL }, // "Do Not Save"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2ada0
struct menudialog menudialog_mpsavesetup = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(183), // "Save Game Setup"
	menuitems_mpsavesetup,
	NULL,
	0x00000000,
	NULL,
};

// 2adb8
struct menuitem menuitems_mpweapons[] = {
	{ MENUITEMTYPE_DROPDOWN,    1, 0x00020090, L_MPMENU(174), 0x00000000, menuhandlerMpWeaponSetDropdown }, // "Set:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000212, L_MPMENU(175), 0x00000000, NULL }, // "Current Weapon Setup:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU(176), 0x00000000, menuhandlerMpWeaponSlot }, // "1:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU(177), 0x00000001, menuhandlerMpWeaponSlot }, // "2:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU(178), 0x00000002, menuhandlerMpWeaponSlot }, // "3:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU(179), 0x00000003, menuhandlerMpWeaponSlot }, // "4:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU(180), 0x00000004, menuhandlerMpWeaponSlot }, // "5:"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x000a0080, L_MPMENU(181), 0x00000005, menuhandlerMpWeaponSlot }, // "6:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(182), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2aea8
struct menudialog menudialog_mpweapons = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(173), // "Weapons"
	menuitems_mpweapons,
	NULL,
	0x00000010,
	NULL,
};

// 2aec0
struct menuitem menuitems_mpweapons2[] = {
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020090, L_MPMENU(174), 0x00000000, menuhandlerMpWeaponSetDropdown }, // "Set:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000002, L_MPMENU(176), (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "1:"
	{ MENUITEMTYPE_LABEL,       1, 0x00000002, L_MPMENU(177), (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "2:"
	{ MENUITEMTYPE_LABEL,       2, 0x00000002, L_MPMENU(178), (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "3:"
	{ MENUITEMTYPE_LABEL,       3, 0x00000002, L_MPMENU(179), (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "4:"
	{ MENUITEMTYPE_LABEL,       4, 0x00000002, L_MPMENU(180), (u32)&mpMenuTextWeaponNameForSlot, NULL }, // "5:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(182), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2af88
struct menudialog menudialog_mpweapons2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(173), // "Weapons"
	menuitems_mpweapons2,
	NULL,
	0x00000010,
	NULL,
};

// 2afa0
struct menuitem menuitems_mpoptions[] = {
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(168), 0x00000002, menuhandlerMpDisplayOptionCheckbox }, // "Highlight Pickups"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(169), 0x00000001, menuhandlerMpDisplayOptionCheckbox }, // "Highlight Players"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(170), 0x00000008, menuhandlerMpDisplayOptionCheckbox }, // "Highlight Teams"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(171), 0x00000004, menuhandlerMpDisplayOptionCheckbox }, // "Radar"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(172), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b02c
struct menudialog menudialog_mpoptions = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(167), // "Options"
	menuitems_mpoptions,
	NULL,
	0x00000000,
	NULL,
};

// 2b044
struct menuitem menuitems_mpcontrol[] = {
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MPMENU(200), 0x00000000, menuhandlerMpControlStyle }, // "Control Style"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(201), 0x00000001, menuhandlerMpControlCheckbox }, // "Reverse Pitch"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(202), 0x00000002, menuhandlerMpControlCheckbox }, // "Look Ahead"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(203), 0x00000080, menuhandlerMpControlCheckbox }, // "Head Roll"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(204), 0x00000008, menuhandlerMpControlCheckbox }, // "Auto-Aim"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MPMENU(205), 0x00000000, menuhandlerMpAimControl }, // "Aim Control"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(206), 0x00000004, menuhandlerMpControlCheckbox }, // "Sight on Screen"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(207), L_AME(0), menuhandlerMpControlCheckbox }, // "Show Target"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(208), L_ARCH(0), menuhandlerMpControlCheckbox }, // "Show Zoom Range"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(209), 0x00000020, menuhandlerMpControlCheckbox }, // "Ammo on Screen"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(210), 0x00000040, menuhandlerMpControlCheckbox }, // "Gun Function"
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00000000, L_MPMENU(211), L_ASH(0), menuhandlerMpControlCheckbox }, // "Paintball"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(212), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b184
struct menudialog menudialog_mpcontrol = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(199), // "Control"
	menuitems_mpcontrol,
	NULL,
	0x00000000,
	NULL,
};

// 2b19c
struct menuitem menuitems_mpcompletedchallenges[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00200000, 0x00000078, 0x0000004d, menuhandler0017a20c },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b1c4
struct menudialog menudialog_mpcompletedchallenges = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(165), // "Completed Challenges"
	menuitems_mpcompletedchallenges,
	NULL,
	0x00000048,
	NULL,
};

u32 var800851bc = 0x4e806f76;
u32 var800851c0 = 0x7ca688ab;
u32 var800851c4 = 0x95bfa6ad;
u32 var800851c8 = 0xee888700;
u32 var800851cc = 0x5e6d5e7f;
u32 var800851d0 = 0x416c7d95;
u32 var800851d4 = 0x2e280000;

// 2b1f8
struct menuitem menuitems_mpplayerstats[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(146), (u32)&mpMenuTextKills, NULL }, // "Kills:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(147), (u32)&mpMenuTextDeaths, NULL }, // "Deaths:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(148), (u32)&mpMenuTextAccuracy, NULL }, // "Accuracy:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(149), (u32)&mpMenuTextHeadShots, NULL }, // "Head Shots:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(150), (u32)&mpMenuTextAmmoUsed, NULL }, // "Ammo Used:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(151), (u32)&mpMenuTextDamageDealt, NULL }, // "Damage Dealt:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(152), (u32)&mpMenuTextPainReceived, NULL }, // "Pain Received:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(153), (u32)&mpMenuTextGamesPlayed, NULL }, // "Games Played:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(154), (u32)&mpMenuTextGamesWon, NULL }, // "Games Won:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(155), (u32)&mpMenuTextGamesLost, NULL }, // "Games Lost:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(156), (u32)&mpMenuTextTime, NULL }, // "Time:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(157), (u32)&mpMenuTextDistance, NULL }, // "Distance:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000210, L_MPMENU(158), 0x00000000, NULL }, // "Medals Won:"
	{ MENUITEMTYPE_LABEL,       2, 0x00200000, L_MPMENU(159), (u32)&mpMenuTextMedalAccuracy, menuhandlerMpMedal }, // "Accuracy:"
	{ MENUITEMTYPE_LABEL,       1, 0x00200000, L_MPMENU(160), (u32)&mpMenuTextMedalHeadShot, menuhandlerMpMedal }, // "Head Shot:"
	{ MENUITEMTYPE_LABEL,       0, 0x00200000, L_MPMENU(161), (u32)&mpMenuTextMedalKillMaster, menuhandlerMpMedal }, // "KillMaster:"
	{ MENUITEMTYPE_LABEL,       3, 0x00200000, L_MPMENU(162), (u32)&mpMenuTextMedalSurvivor, menuhandlerMpMedal }, // "Survivor:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(163), 0x00000000, NULL }, // "Your Title:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000020, (u32)&mpMenuTextPlayerTitle, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_MPWEAPONS(219), 0x00000000, menuhandlerMpUsernamePassword }, // "USERNAME:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000220, (u32)&mpMenuTextUsernamePassword, 0x00000000, menuhandlerMpUsernamePassword },
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_MPWEAPONS(220), 0x00000000, menuhandlerMpUsernamePassword }, // "PASSWORD:"
	{ MENUITEMTYPE_LABEL,       1, 0x00000220, (u32)&mpMenuTextUsernamePassword, 0x00000000, menuhandlerMpUsernamePassword },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(164), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b450
struct menudialog menudialog_mpplayerstats = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTitleStatsForPlayerName,
	menuitems_mpplayerstats,
	NULL,
	0x00000048,
	&menudialog_mpcompletedchallenges,
};

u32 var80085448 = 0x00000300;
u32 var8008544c = 0x0400ff00;

// 2b470
struct menuitem menuitems_mpcharacter[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00004230, (u32)&mpMenuTextBodyName, 0x00000000, NULL },
	{ MENUITEMTYPE_CAROUSEL,    0, 0x00000000, 0x00000000, 0x00000022, menuhandlerMpCharacterHead },
	{ MENUITEMTYPE_CAROUSEL,    0, 0x00000000, 0x00000000, 0x0000001b, menuhandlerMpCharacterBody },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b4c0
struct menudialog menudialog_mpcharacter = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(143), // "Character"
	menuitems_mpcharacter,
	menudialog0017a174,
	0x00000002,
	NULL,
};

// 2b4d8
struct menuitem menuitems_mpplayername[] = {
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000000, menuhandler0017b91c },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b500
struct menudialog menudialog_mpplayername = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(142), // "Player Name"
	menuitems_mpplayername,
	NULL,
	0x00000000,
	NULL,
};

// 2b518
struct menuitem menuitems_mploadgamesettingstype0[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00000000, 0x00000078, 0x00000042, menuhandler0017bab4 },
	{ MENUITEMTYPE_MARQUEE,     0, 0x00000a00, (u32)&func0f17be2c, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b554
struct menudialog menudialog_mploadgamesettingstype0 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(139), // "Load Game Settings"
	menuitems_mploadgamesettingstype0,
	NULL,
	0x00000001,
	NULL,
};

// 2b56c
struct menuitem menuitems_mploadgamesettingstype1[] = {
	{ MENUITEMTYPE_LIST,        1, 0x00000000, 0x00000078, 0x00000042, menuhandler0017bab4 },
	{ MENUITEMTYPE_MARQUEE,     0, 0x00000a00, (u32)&func0f17be2c, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b5a8
struct menudialog menudialog_mploadgamesettingstype1 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(139), // "Load Game Settings"
	menuitems_mploadgamesettingstype1,
	NULL,
	0x00000000,
	NULL,
};

// 2b5c0
struct menuitem menuitems_mploadplayer[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00000000, 0x0000007e, 0x00000042, menuhandler0017bfc0 },
	{ MENUITEMTYPE_LABEL,       0, 0x00000200, L_MPMENU(138), 0x00000000, NULL }, // "B Button to cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b5fc
struct menudialog menudialog_mploadplayer = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(137), // "Load Player"
	menuitems_mploadplayer,
	NULL,
	0x00000000,
	NULL,
};

// 2b614
struct menuitem menuitems_mparena[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00020000, 0x00000078, 0x0000004d, menuhandler001791c8 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b63c
struct menudialog menudialog_mparena = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(115), // "Arena"
	menuitems_mparena,
	NULL,
	0x00000011,
	NULL,
};

// 2b654
struct menuitem menuitems_mplimits[] = {
	{ MENUITEMTYPE_SLIDER,      0, 0x00020010, L_MPMENU(108), 0x0000003c, menuhandlerMpTimeLimitSlider }, // "Time"
	{ MENUITEMTYPE_SLIDER,      0, 0x00020010, L_MPMENU(109), 0x00000064, menuhandlerMpScoreLimitSlider }, // "Score"
	{ MENUITEMTYPE_SLIDER,      0, 0x00020010, L_MISC(447), 0x00000190, menuhandlerMpTeamScoreLimitSlider }, // "Team Score"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU(110), 0x00000000, menuhandlerMpRestoreScoreDefaults }, // "Restore Defaults"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(111), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b6e0
struct menudialog menudialog_mplimits = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(107), // "Limits"
	menuitems_mplimits,
	NULL,
	0x00000010,
	NULL,
};

// 2b6f8
struct menuitem menuitems_mpplayerhandicaps[] = {
	{ MENUITEMTYPE_SLIDER,      0, 0x00020010, (u32)&mpMenuTextHandicapPlayerName, 0x000000ff, menuhandlerMpHandicapPlayer },
	{ MENUITEMTYPE_SLIDER,      1, 0x00020010, (u32)&mpMenuTextHandicapPlayerName, 0x000000ff, menuhandlerMpHandicapPlayer },
	{ MENUITEMTYPE_SLIDER,      2, 0x00020010, (u32)&mpMenuTextHandicapPlayerName, 0x000000ff, menuhandlerMpHandicapPlayer },
	{ MENUITEMTYPE_SLIDER,      3, 0x00020010, (u32)&mpMenuTextHandicapPlayerName, 0x000000ff, menuhandlerMpHandicapPlayer },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU(110), 0x00000000, menuhandlerMpRestoreHandicapDefaults }, // "Restore Defaults"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(111), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b798
struct menudialog menudialog_mpplayerhandicaps = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(184), // "Player Handicaps"
	menuitems_mpplayerhandicaps,
	NULL,
	0x00000010,
	NULL,
};

// 2b7b0
struct menuitem menuitems_mpready[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(106), 0x00000000, NULL }, // "...and waiting"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b7d8
struct menudialog g_MpReadyMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPMENU(105), // "Ready!"
	menuitems_mpready,
	menudialogMpReady,
	0x00000001,
	NULL,
};

u32 var800857d0 = 0x00000000;
u32 var800857d4 = 0x50670000; // "Normal Simulants"
u32 var800857d8 = 0x00000006;
u32 var800857dc = 0x50680000; // "Special Simulants"

// 2b800
struct menuitem menuitems_mpaddchangesimulant[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00020000, 0x00000078, 0x00000042, menuhandler0017c6a4 },
	{ MENUITEMTYPE_MARQUEE,     0, 0x00000a00, (u32)&mpMenuTextSimulantDescription, 0x00000000, NULL },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b83c
struct menudialog g_MpAddSimulantMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(101), // "Add Simulant"
	menuitems_mpaddchangesimulant,
	NULL,
	0x00000011,
	NULL,
};

// 2b854
struct menudialog g_MpChangeSimulantMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(102), // "Change Simulant"
	menuitems_mpaddchangesimulant,
	menudialogMpSimulant,
	0x00000011,
	NULL,
};

// 2b86c
struct menuitem menuitems_mpsimulantcharacter[] = {
	 { MENUITEMTYPE_CAROUSEL,    0, 0x00020000, 0x00000000, 0x00000025, menuhandlerMpSimulantHead },
	 { MENUITEMTYPE_CAROUSEL,    0, 0x00020000, 0x00000000, 0x0000001b, menuhandlerMpSimulantBody },
	 { MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b8a8
struct menudialog menudialog_mpsimulantcharacter = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(100), // "Simulant Character"
	menuitems_mpsimulantcharacter,
	menudialog0017ccfc,
	0x00000012,
	NULL,
};

// 2b8c0
struct menuitem menuitems_mpeditsimulant[] = {
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020000, L_MPMENU(95), 0x00000000, menuhandlerMpSimulantDifficulty }, // "Difficulty:"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(96), 0x00000000, menuhandlerMpChangeSimulantType }, // "Change Type..."
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(97), 0x00000000, (void *)&menudialog_mpsimulantcharacter }, // "Character..."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(98), 0x00000000, menuhandlerMpDeleteSimulant }, // "Delete Simulant"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(99), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2b94c
struct menudialog g_MpEditSimulantMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17cfc0,
	menuitems_mpeditsimulant,
	menudialogMpSimulant,
	0x00000010,
	NULL,
};

// 2b964
struct menuitem menuitems_mpsimulants[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(84), 0x00000000, menuhandlerMpAddSimulant }, // "Add Simulant..."
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(85), (u32)&func0f17d378, menuhandlerMpSimulantSlot }, // "1:"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00000000, L_MPMENU(86), (u32)&func0f17d378, menuhandlerMpSimulantSlot }, // "2:"
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00000000, L_MPMENU(87), (u32)&func0f17d378, menuhandlerMpSimulantSlot }, // "3:"
	{ MENUITEMTYPE_SELECTABLE,  3, 0x00000000, L_MPMENU(88), (u32)&func0f17d378, menuhandlerMpSimulantSlot }, // "4:"
	{ MENUITEMTYPE_SELECTABLE,  4, 0x00000000, L_MPMENU(89), (u32)&func0f17d378, menuhandlerMpSimulantSlot }, // "5:"
	{ MENUITEMTYPE_SELECTABLE,  5, 0x00000000, L_MPMENU(90), (u32)&func0f17d378, menuhandlerMpSimulantSlot }, // "6:"
	{ MENUITEMTYPE_SELECTABLE,  6, 0x00000000, L_MPMENU(91), (u32)&func0f17d378, menuhandlerMpSimulantSlot }, // "7:"
	{ MENUITEMTYPE_SELECTABLE,  7, 0x00000000, L_MPMENU(92), (u32)&func0f17d378, menuhandlerMpSimulantSlot }, // "8:"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(93), 0x00000000, menuhandlerMpClearAllSimulants }, // "Clear All"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(94), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2ba7c
struct menudialog menudialog_mpsimulants = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(83), // "Simulants"
	menuitems_mpsimulants,
	menudialogMpSimulants,
	0x00000010,
	NULL,
};

u32 var80085a74 = 0x00000000;
u32 var80085a78 = 0x00000000;
u32 var80085a7c = 0x00000000;
u32 var80085a80 = 0x00000000;
u8 g_TeamIdsForPairing[] = {0, 1, 2, 3};

// 2baa8
struct menuitem menuitems_mpautoteam[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(76), 0x00000000, menuhandlerMpTwoTeams }, // "Two Teams"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(77), 0x00000000, menuhandlerMpThreeTeams }, // "Three Teams"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(78), 0x00000000, menuhandlerMpFourTeams }, // "Four Teams"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(79), 0x00000000, menuhandlerMpMaximumTeams }, // "Maximum Teams"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(80), 0x00000000, menuhandlerMpHumansVsSimulants }, // "Humans vs. Simulants"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_MPMENU(81), 0x00000000, menuhandlerMpHumanSimulantPairs }, // "Human-Simulant Pairs"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(82), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2bb5c
struct menudialog menudialog_mpautoteam = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(75), // "Auto Team"
	menuitems_mpautoteam,
	NULL,
	0x00000010,
	NULL,
};

// 2bb74
struct menuitem menuitems_mpteamcontrol[] = {
	{ MENUITEMTYPE_CHECKBOX,     0, 0x00020000, L_MPMENU(71), 0x00000002, menuhandlerMpTeamsEnabled }, // "Teams Enabled"
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,        0, 0x00000010, L_MPMENU(72), 0x00000000, menuhandlerMpTeamsLabel }, // "Teams:"
	{ MENUITEMTYPE_DROPDOWN,     0, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     1, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     2, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     3, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     4, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     5, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     6, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     7, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     8, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,     9, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,    10, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_DROPDOWN,    11, 0x00020000, (u32)&mpMenuTextChrNameForTeamSetup, 0x00000000, menuhandlerMpTeamSlot },
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,   0, 0x00000004, L_MPMENU(73), 0x00000000, (void *)&menudialog_mpautoteam }, // "Auto Team..."
	{ MENUITEMTYPE_SELECTABLE,   0, 0x00000008, L_MPMENU(74), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,          0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2bcf0
struct menudialog menudialog_mpteamcontrol = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(70), // "Team Control"
	menuitems_mpteamcontrol,
	NULL,
	0x00000010,
	NULL,
};

u32 var80085ce8 = L_MISC(166); // "Random"
u32 var80085cec = L_MISC(167); // "Select All"
u32 var80085cf0 = L_MISC(168); // "Select None"
u32 var80085cf4 = L_MISC(169); // "Randomize"

// 2bd18
struct menuitem menuitems_2bd18[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00020000, 0x00000078, 0x0000004d, menuhandler0017dc84 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2bd40
struct menudialog menudialog_2bd40 = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTextSelectTuneOrTunes,
	menuitems_2bd18,
	menudialogMpSelectTune,
	0x00000010,
	NULL,
};

// 2bd58
struct menuitem menuitems_mpsoundtrack[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(63), 0x00000000, NULL }, // "Current:"
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_OPTIONS(3), (u32)&mpMenuTextCurrentTrack, NULL }, // ""
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, (u32)&mpMenuTextSelectTuneOrTunes, 0x00000000, (void *)&menudialog_2bd40 },
	{ MENUITEMTYPE_CHECKBOX,    0, 0x00020000, L_MPMENU(64), 0x00000000, menuhandlerMpMultipleTunes }, // "Multiple Tunes"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(65), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2bdf8
struct menudialog menudialog_mpsoundtrack = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(62), // "Soundtrack"
	menuitems_mpsoundtrack,
	NULL,
	0x00000010,
	NULL,
};

// 2be10
struct menuitem menuitems_mpchangeteamname[] = {
	{ MENUITEMTYPE_KEYBOARD,    0, 0x00000000, 0x00000000, 0x00000000, menuhandler0017e06c },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2be38
struct menudialog g_MpChangeTeamNameMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(61), // "Change Team Name"
	menuitems_mpchangeteamname,
	NULL,
	0x00000000,
	NULL,
};

// 2be50
struct menuitem menuitems_mpteamnames[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS(8), (u32)&func0f17e288, menuhandlerMpTeamNameSlot }, // "Red"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS(9), (u32)&func0f17e288, menuhandlerMpTeamNameSlot }, // "Yellow"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS(10), (u32)&func0f17e288, menuhandlerMpTeamNameSlot }, // "Blue"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS(11), (u32)&func0f17e288, menuhandlerMpTeamNameSlot }, // "Magenta"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS(12), (u32)&func0f17e288, menuhandlerMpTeamNameSlot }, // "Cyan"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS(13), (u32)&func0f17e288, menuhandlerMpTeamNameSlot }, // "Orange"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS(14), (u32)&func0f17e288, menuhandlerMpTeamNameSlot }, // "Pink"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020000, L_OPTIONS(15), (u32)&func0f17e288, menuhandlerMpTeamNameSlot }, // "Brown"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(60), 0x00000000, NULL }, // "Back"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2bf2c
struct menudialog menudialog_mpteamnames = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(59), // "Team Names"
	menuitems_mpteamnames,
	NULL,
	0x00000010,
	NULL,
};

// 2bf44
struct menuitem menuitems_2bf44[] = {
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_MPCONFIG, 0x00000000, 0x0000007c,   0x00000037, NULL                },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00060000, L_MPMENU(57), 0x00000000, menuhandler0017e38c }, // "Accept"
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000008, L_MPMENU(58), 0x00000000, NULL                }, // "Cancel"
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
};

// 2bfa8
struct menudialog menudialog_2bfa8 = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17e318,
	menuitems_2bf44,
	menudialog0017e3fc,
	0x00000014,
	NULL,
};

// 2bfc0
struct menuitem menuitems_mpchallengedetails[] = {
	{ MENUITEMTYPE_LIST,       0,                       0x00200000, 0x00000078,       0x0000004d, menuhandler0017e4d4         },
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_MPCHALLENGE, 0x00000000, 0x0000007c,       0x00000037, menuhandler0017e9d8         },
	{ MENUITEMTYPE_SEPARATOR,  0,                       0x00000000, 0x00000000,       0x00000000, menuhandler0017e9d8         },
	{ MENUITEMTYPE_SELECTABLE, 0,                       0x00000000, L_MPWEAPONS(171), 0x00000000, menuhandlerMpStartChallenge }, // "Start Challenge"
	{ MENUITEMTYPE_SELECTABLE, 0,                       0x00000000, L_MPMENU(51),     0x00000000, menuhandlerMpAbortChallenge }, // "Abort Challenge"
	{ MENUITEMTYPE_END,        0,                       0x00000000, 0x00000000,       0x00000000, NULL                        },
};

// 2c038
struct menudialog menudialog_mpchallengedetails = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTextChallengeName,
	menuitems_mpchallengedetails,
	mpCombatChallengesMenuDialog,
	0x00000808,
	NULL,
};

struct menudialog menudialog_mpgamesetup2;

// 2c050
struct menudialog menudialog_mpchallengedetails2 = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&mpMenuTextChallengeName,
	menuitems_mpchallengedetails,
	mpCombatChallengesMenuDialog,
	0x00000808,
	&menudialog_mpgamesetup2,
};

// 2c068
struct menuitem menuitems_2c068[] = {
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_MPCONFIG, 0x00000000, 0x0000007c,   0x00000037, NULL                },
	{ MENUITEMTYPE_SEPARATOR,  0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000000, L_MPMENU(57), 0x00000000, menuhandler0017ec64 }, // "Accept"
	{ MENUITEMTYPE_SELECTABLE, 0,                    0x00000008, L_MPMENU(58), 0x00000000, NULL                }, // "Cancel"
	{ MENUITEMTYPE_END,        0,                    0x00000000, 0x00000000,   0x00000000, NULL                },
};

// 2c0cc
struct menudialog menudialog_2c0cc = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&func0f17e318,
	menuitems_2c068,
	menudialog0017e3fc,
	0x00000004,
	NULL,
};

// 2c0e4
struct menuitem menuitems_mpcombatchallenges2[] = {
	{ MENUITEMTYPE_LIST,        1, 0x00200000, 0x00000078, 0x0000004d, menuhandler0017e4d4 },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2c10c
struct menudialog menudialog_mpcombatchallenges2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(50), // "Combat Challenges"
	menuitems_mpcombatchallenges2,
	mpCombatChallengesMenuDialog,
	0x00000000,
	NULL,
};

// 2c124
u16 mplockoptions[4] = {
	L_MPMENU(45), // "None"
	L_MPMENU(46), // "Last Winner"
	L_MPMENU(47), // "Last Loser"
	L_MPMENU(48), // "Random"
};

struct menudialog menudialog_mpabort2;

// 2c12c
struct menuitem menuitems_mpstuff[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(41), 0x00000000, (void *)&menudialog_mpsoundtrack }, // "Soundtrack"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(42), 0x00000000, (void *)&menudialog_mpteamnames }, // "Team Names"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00020000, L_MPMENU(44), 0x00000000, menuhandlerMpLock }, // "Lock"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_OPTIONS(216), 0x00000000, menuhandlerScreenRatio }, // "Ratio"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MPWEAPONS(154), 0x00000000, menuhandlerScreenSplit }, // "Split"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(36), 0x00000000, (void *)&g_MpReadyMenuDialog }, // "Start Game"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(37), 0x00000000, (void *)&menudialog_2aba0 }, // "Drop Out"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(27), 0x00000000, (void *)&menudialog_mpabort2 }, // "Abort Game"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2c208
struct menudialog menudialog_mpstuff = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(40), // "Stuff"
	menuitems_mpstuff,
	NULL,
	0x00000810,
	&menudialog_mpchallengedetails,
};

// 2c220
struct menudialog menudialog_mpstuff2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(40), // "Stuff"
	menuitems_mpstuff,
	NULL,
	0x00000810,
	NULL,
};

// 2c238
struct menuitem menuitems_mpplayersetup4[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(30), (u32)&mpGetCurrentPlayerName, (void *)&menudialog_mpplayername }, // "Name"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(31), 0x00000000, (void *)&menudialog_mpcharacter }, // "Character"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(33), 0x00000000, (void *)&menudialog_mpcontrol }, // "Control"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(34), 0x00000000, (void *)&menudialog_mpoptions }, // "Player Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(35), 0x00000000, (void *)&menudialog_mpplayerstats }, // "Statistics"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(29), 0x00000000, (void *)&menudialog_mploadplayer }, // "Load Player"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, (u32)&mpMenuTextSavePlayerOrCopy, 0x00000000, menuhandlerMpSavePlayer },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2c2ec
struct menudialog menudialog_mpplayersetup4 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(28), // "Player Setup"
	menuitems_mpplayersetup4,
	NULL,
	0x00000800,
	&menudialog_mpstuff,
};

// 2c304
struct menudialog menudialog_mpplayersetup2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(28), // "Player Setup"
	menuitems_mpplayersetup4,
	NULL,
	0x00000800,
	&menudialog_mpstuff2,
};

// 2c31c
struct menudialog menudialog_mpplayersetup3 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(28), // "Player Setup"
	menuitems_mpplayersetup4,
	NULL,
	0x00000000,
	NULL,
};

// 2c334
struct menuitem menuitems_mpabort2[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000010, L_MPMENU(53), 0x00000000, NULL }, // "Are you sure you want to abort the game?"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(54), 0x00000000, menuhandler0017ef30 }, // "Abort"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000008, L_MPMENU(55), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2c384
struct menudialog menudialog_mpabort2 = {
	MENUDIALOGTYPE_DANGER,
	L_MPMENU(52), // "Abort"
	menuitems_mpabort2,
	NULL,
	0x00000000,
	NULL,
};

struct menudialog menudialog_mpscenario;

// 2c39c
struct menuitem menuitems_mpgamesetup3[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020004, L_MPMENU(19), (u32)&mpMenuTextScenarioShortName, (void *)&menudialog_mpscenario }, // "Scenario"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(21), 0x00000000, menuhandlerMpOpenOptions }, // "Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(20), (u32)&mpMenuTextArenaName, (void *)&menudialog_mparena }, // "Arena"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(23), 0x00000000, (void *)&menudialog_mpweapons }, // "Weapons"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(24), 0x00000000, (void *)&menudialog_mplimits }, // "Limits"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPWEAPONS(184), 0x00000000, (void *)&menudialog_mpplayerhandicaps }, // "Player Handicaps"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(25), 0x00000000, (void *)&menudialog_mpsimulants }, // "Simulants"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(22), 0x00000000, (void *)&menudialog_mpteamcontrol }, // "Teams"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060004, L_MPMENU(18), 0x00000000, (void *)&menudialog_mploadgamesettingstype0 }, // "Load Settings"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU(26), 0x00000000, menuhandlerMpSaveSettings }, // "Save Settings"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2c48c
struct menudialog menudialog_mpgamesetup3 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(17), // "Game Setup"
	menuitems_mpgamesetup3,
	menudialogMpGameSetup,
	0x00000810,
	&menudialog_mpplayersetup4,
};

// 2c4a4
struct menudialog menudialog_mpgamesetup2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(17), // "Game Setup"
	menuitems_mpgamesetup3,
	menudialogMpGameSetup,
	0x00000810,
	&menudialog_mpplayersetup2,
};

// 2c4bc
struct menuitem menuitems_mpquickgo[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(456), 0x00000000, (void *)&g_MpReadyMenuDialog }, // "Start Game"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(29), 0x00000000, (void *)&menudialog_mploadplayer }, // "Load Player"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(458), 0x00000000, (void *)&menudialog_mpplayersetup3 }, // "Player Settings"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MISC(457), 0x00000000, (void *)&menudialog_2aba0 }, // "Drop Out"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2c520
struct menudialog g_MpQuickGoMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC(460), // "Quick Go"
	menuitems_mpquickgo,
	menudialogMpQuickGo,
	0x00000000,
	NULL,
};

struct menudialog menudialog_mpscenario2;

// 2c538
struct menuitem menuitems_mpquickteamgamesetup[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00020004, L_MPMENU(19), (u32)&mpMenuTextScenarioShortName, (void *)&menudialog_mpscenario2 }, // "Scenario"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPMENU(21), 0x00000000, menuhandlerMpOpenOptions }, // "Options"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(20), (u32)&mpMenuTextArenaName, (void *)&menudialog_mparena }, // "Arena"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(23), (u32)&mpMenuTextWeaponSetName, (void *)&menudialog_mpweapons2 }, // "Weapons"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPMENU(24), 0x00000000, (void *)&menudialog_mplimits }, // "Limits"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, menuhandlerQuickTeamSeparator },
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MISC(449), 0x00000000, menuhandlerPlayerTeam }, // "Player 1 Team"
	{ MENUITEMTYPE_DROPDOWN,    1, 0x00000000, L_MISC(450), 0x00000000, menuhandlerPlayerTeam }, // "Player 2 Team"
	{ MENUITEMTYPE_DROPDOWN,    2, 0x00000000, L_MISC(451), 0x00000000, menuhandlerPlayerTeam }, // "Player 3 Team"
	{ MENUITEMTYPE_DROPDOWN,    3, 0x00000000, L_MISC(452), 0x00000000, menuhandlerPlayerTeam }, // "Player 4 Team"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MISC(453), 0x00000000, menuhandlerMpNumberOfSimulants }, // "Number Of Simulants"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MISC(454), 0x00000000, menuhandlerMpSimulantsPerTeam }, // "Simulants Per Team"
	{ MENUITEMTYPE_DROPDOWN,    0, 0x00000000, L_MISC(455), 0x00000000, menuhandler0017f74c }, // "Simulant Difficulty"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MISC(448), 0x00000000, menuhandlerMpFinishedSetup }, // "Finished Setup"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00060000, L_MPMENU(26), 0x00000000, menuhandlerMpSaveSettings }, // "Save Settings"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2c6a0
struct menudialog g_MpQuickTeamGameSetupMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(17), // "Game Setup"
	menuitems_mpquickteamgamesetup,
	NULL,
	0x00000000,
	NULL,
};

// 2c6b8
struct menuitem menuitems_mpquickteam[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400000, L_MISC(463), 0x00000000, menuhandlerMpQuickTeamOption }, // "Players Only"
	{ MENUITEMTYPE_SELECTABLE,  1, 0x00400000, L_MISC(464), 0x00000000, menuhandlerMpQuickTeamOption }, // "Players and Simulants"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000082, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  2, 0x00400000, L_MISC(465), 0x00000000, menuhandlerMpQuickTeamOption }, // "Player Teams"
	{ MENUITEMTYPE_SELECTABLE,  3, 0x00400000, L_MISC(466), 0x00000000, menuhandlerMpQuickTeamOption }, // "Players vs. Simulants"
	{ MENUITEMTYPE_SELECTABLE,  4, 0x00400000, L_MISC(467), 0x00000000, menuhandlerMpQuickTeamOption }, // "Player-Simulant Teams"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2c744
struct menudialog menudialog_mpquickteam = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC(462), // "Quick Team"
	menuitems_mpquickteam,
	NULL,
	0x00000004,
	NULL,
};

// 2c75c
struct menuitem menuitems_mpcombatsimulator[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC(441), 0x00000000, (void *)&menudialog_mpcombatchallenges2 }, // "Challenges"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC(442), 0x00000001, (void *)&menudialog_mploadgamesettingstype1 }, // "Load/Preset Games"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400004, L_MISC(443), 0x00000002, (void *)&menudialog_mpquickteam }, // "Quick Start"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00400000, L_MISC(444), 0x00000003, menuhandlerMpAdvancedSetup }, // "Advanced Setup"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2c7c0
struct menudialog g_CombatSimulatorMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC(445), // "Combat Simulator"
	menuitems_mpcombatsimulator,
	menudialogCombatSimulator,
	0x00000004,
	NULL,
};

u32 var800867b8 = 0x00000000;
u32 var800867bc = 0x00000000;

// 2c7e0
u16 mpslowmotionoptions[] = {
	L_MPMENU(240), // "Off"
	L_MPMENU(241), // "On"
	L_MPMENU(242), // "Smart"
	0x0000,
};

// 2c7e8
struct menuitem menuitems_mpcombatoptions[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(222), MPOPTION_ONEHITKILLS,       menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU(223), 0x00000000,                 menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(224), MPOPTION_FASTMOVEMENT,      menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(225), MPOPTION_DISPLAYTEAM,       menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(226), MPOPTION_NORADAR,           menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(227), MPOPTION_NOAUTOAIM,         menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,    0x00000000,                 NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(228), MPOPTION_NOPLAYERHIGHLIGHT, menuhandlerMpCheckboxOption }, // "No Player Highlight"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(229), MPOPTION_NOPICKUPHIGHLIGHT, menuhandlerMpCheckboxOption }, // "No Pickup Highlight"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,    0x00000000,                 NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU(239), 0x00000000,                 NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,    0x00000000,                 NULL                        },
};

// 2c8d8
struct menudialog menudialog_mpcombatoptions = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(215), // "Combat Options"
	menuitems_mpcombatoptions,
	mpOptionsMenuDialog,
	0x00000010,
	NULL,
};

// 2c8f0
struct menuitem menuitems_mpbriefcaseoptions[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(222),  MPOPTION_ONEHITKILLS,            menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU(223),  0x00000000,                      menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(224),  MPOPTION_FASTMOVEMENT,           menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(225),  MPOPTION_DISPLAYTEAM,            menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(226),  MPOPTION_NORADAR,                menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(227),  MPOPTION_NOAUTOAIM,              menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS(493), MPOPTION_KILLSSCORE,             menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                      NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(237),  MPOPTION_HTB_HIGHLIGHTBRIEFCASE, menuhandlerMpCheckboxOption }, // "Highlight Briefcase"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(238),  MPOPTION_HTB_SHOWONRADAR,        menuhandlerMpCheckboxOption }, // "Show on Radar"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                      NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU(239),  0x00000000,                      NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,                      NULL                        },
};

// 2c9f4
struct menudialog menudialog_mpbriefcaseoptions = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(216), // "Briefcase Options"
	menuitems_mpbriefcaseoptions,
	mpOptionsMenuDialog,
	0x00000010,
	NULL,
};

struct defaultobj *var800869ec = NULL;
u32 var800869f0 = 0x01000008;
u32 var800869f4 = 0x00110000;
u32 var800869f8 = 0x00420001;
u32 var800869fc = 0x00204000;
u32 var80086a00 = 0x00000000;
u32 var80086a04 = 0x00000000;
u32 var80086a08 = 0x00000000;
u32 var80086a0c = 0x3f800000;
u32 var80086a10 = 0x00000000;
u32 var80086a14 = 0x00000000;
u32 var80086a18 = 0x00000000;
u32 var80086a1c = 0x3f800000;
u32 var80086a20 = 0x00000000;
u32 var80086a24 = 0x00000000;
u32 var80086a28 = 0x00000000;
u32 var80086a2c = 0x3f800000;
u32 var80086a30 = 0x00000000;
u32 var80086a34 = 0x00000000;
u32 var80086a38 = 0x00000000;
u32 var80086a3c = 0x000003e8;
u32 var80086a40 = 0xffffff00;
u32 var80086a44 = 0xffffff00;
u32 var80086a48 = 0x0fff0000;
u32 var80086a4c = 0x57000000;
u32 var80086a50 = 0x00ffffff;
u32 var80086a54 = 0x00000000;

// 2ca78
struct menuitem menuitems_mpcaptureoptions[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(222),  MPOPTION_ONEHITKILLS,     menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU(223),  0x00000000,               menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(224),  MPOPTION_FASTMOVEMENT,    menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(225),  MPOPTION_DISPLAYTEAM,     menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(226),  MPOPTION_NORADAR,         menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(227),  MPOPTION_NOAUTOAIM,       menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS(493), MPOPTION_KILLSSCORE,      menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(236),  MPOPTION_CTC_SHOWONRADAR, menuhandlerMpCheckboxOption }, // "Show on Radar"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU(239),  0x00000000,               NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
};

// 2cb68
struct menudialog menudialog_mpcaptureoptions = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(220), // "Capture Options"
	menuitems_mpcaptureoptions,
	mpOptionsMenuDialog,
	0x00000010,
	NULL,
};

u32 var80086b60 = 0x01000008;
u32 var80086b64 = 0x00110000;
u32 var80086b68 = 0x00420001;
u32 var80086b6c = 0x00204000;
u32 var80086b70 = 0x00000000;
u32 var80086b74 = 0x00000000;
u32 var80086b78 = 0x00000000;
u32 var80086b7c = 0x3f800000;
u32 var80086b80 = 0x00000000;
u32 var80086b84 = 0x00000000;
u32 var80086b88 = 0x00000000;
u32 var80086b8c = 0x3f800000;
u32 var80086b90 = 0x00000000;
u32 var80086b94 = 0x00000000;
u32 var80086b98 = 0x00000000;
u32 var80086b9c = 0x3f800000;
u32 var80086ba0 = 0x00000000;
u32 var80086ba4 = 0x00000000;
u32 var80086ba8 = 0x00000000;
u32 var80086bac = 0x000003e8;
u32 var80086bb0 = 0xffffff00;
u32 var80086bb4 = 0xffffff00;
u32 var80086bb8 = 0x0fff0000;
u32 var80086bbc = 0x57000000;
u32 var80086bc0 = 0x00ffffff;
u32 var80086bc4 = 0x00000000;

// 2cbe8
struct menuitem menuitems_mphilloptions[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(222),  MPOPTION_ONEHITKILLS,     menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU(223),  0x00000000,               menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(224),  MPOPTION_FASTMOVEMENT,    menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(225),  MPOPTION_DISPLAYTEAM,     menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(226),  MPOPTION_NORADAR,         menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(227),  MPOPTION_NOAUTOAIM,       menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS(493), MPOPTION_KILLSSCORE,      menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(233),  MPOPTION_KOH_HILLONRADAR, menuhandlerMpCheckboxOption }, // "Hill on Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(234),  MPOPTION_KOH_MOBILEHILL,  menuhandlerMpCheckboxOption }, // "Mobile Hill"
	{ MENUITEMTYPE_SLIDER,     0, 0x00020000, L_MPMENU(235),  0x0000006e,               menuhandlerMpHillTime       }, // "Time"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU(239),  0x00000000,               NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,               NULL                        },
};

// 2cd00
struct menudialog menudialog_mphilloptions = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(219), // "Hill Options"
	menuitems_mphilloptions,
	mpOptionsMenuDialog,
	0x00000010,
	NULL,
};

// 2cd18
struct menuitem menuitems_mphackeroptions[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(222),  MPOPTION_ONEHITKILLS,           menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU(223),  0x00000000,                     menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(224),  MPOPTION_FASTMOVEMENT,          menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(225),  MPOPTION_DISPLAYTEAM,           menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(226),  MPOPTION_NORADAR,               menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(227),  MPOPTION_NOAUTOAIM,             menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS(493), MPOPTION_KILLSSCORE,            menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                     NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(231),  MPOPTION_HTM_HIGHLIGHTTERMINAL, menuhandlerMpCheckboxOption }, // "Highlight Terminal"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(238),  MPOPTION_HTM_SHOWONRADAR,       menuhandlerMpCheckboxOption }, // "Show on Radar"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                     NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU(239),  0x00000000,                     NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,                     NULL                        },
};

// 2ce1c
struct menudialog menudialog_mphackeroptions = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(217), // "Hacker Options"
	menuitems_mphackeroptions,
	mpOptionsMenuDialog,
	0x00000010,
	NULL,
};

u32 var80086e14 = 0x02000008;
u32 var80086e18 = 0x00130000;
u32 var80086e1c = 0x00420001;
u32 var80086e20 = 0x00204000;
u32 var80086e24 = 0x00000000;
u32 var80086e28 = 0x00000000;
u32 var80086e2c = 0x00000000;
u32 var80086e30 = 0x3f800000;
u32 var80086e34 = 0x00000000;
u32 var80086e38 = 0x00000000;
u32 var80086e3c = 0x00000000;
u32 var80086e40 = 0x3f800000;
u32 var80086e44 = 0x00000000;
u32 var80086e48 = 0x00000000;
u32 var80086e4c = 0x00000000;
u32 var80086e50 = 0x3f800000;
u32 var80086e54 = 0x00000000;
u32 var80086e58 = 0x00000000;
u32 var80086e5c = 0x00000000;
u32 var80086e60 = 0x000003e8;
u32 var80086e64 = 0xffffff00;
u32 var80086e68 = 0xffffff00;
u32 var80086e6c = 0x0fff0000;
u32 var80086e70 = 0x36000000;
u32 var80086e74 = 0x00ffffff;
u32 var80086e78 = 0x00000000;

// 2ce9c
struct menuitem menuitems_mppopacapoptions[] = {
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(222),  MPOPTION_ONEHITKILLS,         menuhandlerMpOneHitKills    }, // "One-Hit Kills"
	{ MENUITEMTYPE_DROPDOWN,   0, 0x00020000, L_MPMENU(223),  0x00000000,                   menuhandlerMpSlowMotion     }, // "Slow Motion"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(224),  MPOPTION_FASTMOVEMENT,        menuhandlerMpCheckboxOption }, // "Fast Movement"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(225),  MPOPTION_DISPLAYTEAM,         menuhandlerMpDisplayTeam    }, // "Display Team"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(226),  MPOPTION_NORADAR,             menuhandlerMpCheckboxOption }, // "No Radar"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(227),  MPOPTION_NOAUTOAIM,           menuhandlerMpCheckboxOption }, // "No Auto-Aim"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_OPTIONS(493), MPOPTION_KILLSSCORE,          menuhandlerMpCheckboxOption }, // "Kills Score"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                   NULL                        },
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(230),  MPOPTION_PAC_HIGHLIGHTTARGET, menuhandlerMpCheckboxOption }, // "Highlight Target"
	{ MENUITEMTYPE_CHECKBOX,   0, 0x00020000, L_MPMENU(238),  MPOPTION_PAC_SHOWONRADAR,     menuhandlerMpCheckboxOption }, // "Show on Radar"
	{ MENUITEMTYPE_SEPARATOR,  0, 0x00000000, 0x00000000,     0x00000000,                   NULL                        },
	{ MENUITEMTYPE_SELECTABLE, 0, 0x00000008, L_MPMENU(239),  0x00000000,                   NULL                        }, // "Back"
	{ MENUITEMTYPE_END,        0, 0x00000000, 0x00000000,     0x00000000,                   NULL                        },
};

// 2cfa0
struct menudialog menudialog_mppopacapoptions = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(218), // "Pop a Cap Options"
	menuitems_mppopacapoptions,
	mpOptionsMenuDialog,
	0x00000010,
	NULL,
};

// 2cfb8
struct mpscenario g_MpScenarios[] = {
	{ &menudialog_mpcombatoptions,    NULL,            NULL,                  NULL,             NULL,                  NULL,                  NULL,                  NULL,            NULL,             NULL,              NULL,                 NULL,                  NULL,                   NULL,                         NULL,                  NULL, NULL,                  NULL                  },
	{ &menudialog_mpbriefcaseoptions, scenarioHtbInit, scenarioHtbCallback08, scenarioHtbReset, scenarioHtbCallback10, scenarioHtbCallback14, scenarioHtbCallback18, scenarioHtbKill, scenarioHtbRadar, scenarioHtbRadar2, scenarioHtbHighlight, NULL,                  NULL,                   NULL,                         NULL,                  NULL, NULL,                  NULL                  },
	{ &menudialog_mphackeroptions,    scenarioHtmInit, scenarioHtmCallback08, scenarioHtmReset, scenarioHtmCallback10, scenarioHtmCallback14, scenarioHtmCallback18, scenarioHtmKill, scenarioHtmRadar, scenarioHtmRadar2, scenarioHtmHighlight, NULL,                  NULL,                   NULL,                         NULL,                  NULL, NULL,                  NULL                  },
	{ &menudialog_mppopacapoptions,   scenarioPacInit, NULL,                  scenarioPacReset, scenarioPacCallback10, NULL,                  scenarioPacCallback18, scenarioPacKill, scenarioPacRadar, scenarioPacRadar2, scenarioPacHighlight, NULL,                  NULL,                   NULL,                         NULL,                  NULL, NULL,                  NULL                  },
	{ &menudialog_mphilloptions,      scenarioKohInit, NULL,                  scenarioKohReset, scenarioKohCallback10, NULL,                  scenarioKohCallback18, scenarioKohKill, scenarioKohRadar, NULL,              NULL,                 NULL,                  NULL,                   scenarioKohIsRoomHighlighted, scenarioKohCallback38, NULL, scenarioKohCallback40, scenarioKohCallback44 },
	{ &menudialog_mpcaptureoptions,   scenarioCtcInit, scenarioCtcCallback08, scenarioCtcReset, scenarioCtcCallback10, scenarioCtcCallback14, NULL,                  scenarioCtcKill, scenarioCtcRadar, scenarioCtcRadar2, scenarioCtcHighlight, scenarioCtcCallback2c, scenarioCtcGetMaxTeams, scenarioCtcIsRoomHighlighted, scenarioCtcCallback38, NULL, NULL,                  NULL                  },
};

// 2d168
struct mpscenariooverview g_MpScenarioOverviews[] = {
	// Full name, short name, unlock flags?
	{ L_MPMENU(246), L_MPMENU(253), 0x00, false }, // "Combat", "Combat"
	{ L_MPMENU(247), L_MPMENU(254), 0x20, false }, // "Hold the Briefcase", "Briefcase"
	{ L_MPMENU(248), L_MPMENU(255), 0x4e, false }, // "Hacker Central", "Hacker"
	{ L_MPMENU(249), L_MPMENU(256), 0x4d, false }, // "Pop a Cap", "Pop"
	{ L_MPMENU(250), L_MPMENU(257), 0x1f, true  }, // "King of the Hill", "Hill"
	{ L_MPMENU(251), L_MPMENU(258), 0x21, true  }, // "Capture the Case", "Capture"
};

u32 var8008716c = 0x00000000;
u32 var80087170 = 0x50f40000; // "Free for All!"
u32 var80087174 = 0x00000004;
u32 var80087178 = 0x50f50000; // "-Teamwork-"

// 2d19c
struct menuitem menuitems_mpscenario[] = {
	 { MENUITEMTYPE_LIST,        0, 0x00020040, 0x00000078, 0x0000004d, menuhandler00185068 },
	 { MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2d1c4
struct menudialog menudialog_mpscenario = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(243), // "Scenario"
	menuitems_mpscenario,
	NULL,
	0x00000011,
	NULL,
};

// 2d1dc
struct menuitem menuitems_mpscenario2[] = {
	 { MENUITEMTYPE_LIST,        1, 0x00020040, 0x00000078, 0x0000004d, menuhandler00185068 },
	 { MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2d204
struct menudialog menudialog_mpscenario2 = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(243), // "Scenario"
	menuitems_mpscenario2,
	NULL,
	0x00000011,
	NULL,
};

u32 var800871fc = 0x01000003;
u32 var80087200 = 0x0020ffff;
u32 var80087204 = 0x00000000;
u32 var80087208 = 0x00000000;
u32 var8008720c = 0x00000000;
u32 var80087210 = 0x00000000;
u32 var80087214 = 0x00000000;
u32 var80087218 = 0x3f800000;
u32 var8008721c = 0x00000000;
u32 var80087220 = 0x00000000;
u32 var80087224 = 0x00000000;
u32 var80087228 = 0x3f800000;
u32 var8008722c = 0x00000000;
u32 var80087230 = 0x00000000;
u32 var80087234 = 0x00000000;
u32 var80087238 = 0x3f800000;
u32 var8008723c = 0x00000000;
u32 var80087240 = 0x00000000;
u32 var80087244 = 0x00000000;
u32 var80087248 = 0x000003e8;
u32 var8008724c = 0xffffff00;
u32 var80087250 = 0xffffff00;
u32 var80087254 = 0x0fff0000;
u32 var80087258 = 0x00000000;
u32 var8008725c = 0x00000000;
s32 var80087260 = 0x00000000;
u32 var80087264 = 0x00000000;

// 2d288
struct mpweapon g_MpWeapons[] = {
	/*0x00*/ { WEAPON_NONE,             0x00, 0x00, 0x00, 0x00, 1, 0,                                MODEL_CHRTT33,          0x0100 },
	/*0x01*/ { WEAPON_FALCON2,          0x01, 0x50, 0x00, 0x00, 1, 0,                                MODEL_CHRFALCON2,       0x0100 },
	/*0x02*/ { WEAPON_FALCON2_SILENCER, 0x01, 0x50, 0x00, 0x00, 1, MPFEATURE_WEAPON_FALCON2SILENCED, MODEL_CHRFALCON2SIL,    0x0100 },
	/*0x03*/ { WEAPON_FALCON2_SCOPE,    0x01, 0x50, 0x00, 0x00, 1, MPFEATURE_WEAPON_FALCON2SCOPE,    MODEL_CHRFALCON2SCOPE,  0x0100 },
	/*0x04*/ { WEAPON_MAGSEC4,          0x01, 0x50, 0x00, 0x00, 1, 0,                                MODEL_CHRLEEGUN1,       0x0100 },
	/*0x05*/ { WEAPON_MAULER,           0x01, 0x5c, 0x00, 0x00, 1, MPFEATURE_WEAPON_MAULER,          MODEL_CHRMAULER,        0x0100 },
	/*0x06*/ { WEAPON_PHOENIX,          0x01, 0x40, 0x00, 0x00, 1, MPFEATURE_WEAPON_PHOENIX,         MODEL_CHRMAIANPISTOL,   0x0100 },
	/*0x07*/ { WEAPON_DY357MAGNUM,      0x0a, 0x32, 0x00, 0x00, 1, 0,                                MODEL_CHRDY357,         0x0100 },
	/*0x08*/ { WEAPON_DY357LX,          0x0a, 0x32, 0x00, 0x00, 1, MPFEATURE_WEAPON_DY357LX,         MODEL_CHRDY357TRENT,    0x0100 },
	/*0x09*/ { WEAPON_CMP150,           0x02, 0x64, 0x00, 0x00, 1, 0,                                MODEL_CHRCMP150,        0x0100 },
	/*0x0a*/ { WEAPON_CYCLONE,          0x02, 0x96, 0x00, 0x00, 1, 0,                                MODEL_CHRCYCLONE,       0x0100 },
	/*0x0b*/ { WEAPON_CALLISTONTG,      0x02, 0x96, 0x00, 0x00, 1, MPFEATURE_WEAPON_CALLISTO,        MODEL_CHRMAIANSMG,      0x0100 },
	/*0x0c*/ { WEAPON_RCP120,           0x02, 0x96, 0x00, 0x00, 1, MPFEATURE_WEAPON_RCP120,          MODEL_CHRRCP120,        0x0100 },
	/*0x0d*/ { WEAPON_LAPTOPGUN,        0x02, 0x96, 0x00, 0x00, 1, MPFEATURE_WEAPON_LAPTOPGUN,       MODEL_CHRPCGUN,         0x0100 },
	/*0x0e*/ { WEAPON_DRAGON,           0x04, 0x96, 0x00, 0x00, 1, 0,                                MODEL_CHRDRAGON,        0x0100 },
	/*0x0f*/ { WEAPON_K7AVENGER,        0x04, 0x96, 0x00, 0x00, 1, MPFEATURE_WEAPON_K7AVENGER,       MODEL_CHRAVENGER,       0x0100 },
	/*0x10*/ { WEAPON_AR34,             0x04, 0x64, 0x00, 0x00, 1, 0,                                MODEL_CHRAR34,          0x0100 },
	/*0x11*/ { WEAPON_SUPERDRAGON,      0x04, 0x96, 0x0b, 0x10, 1, MPFEATURE_WEAPON_SUPERDRAGON,     MODEL_CHRSUPERDRAGON,   0x0100 },
	/*0x12*/ { WEAPON_SHOTGUN,          0x05, 0x10, 0x00, 0x00, 1, MPFEATURE_WEAPON_SHOTGUN,         MODEL_CHRSHOTGUN,       0x0100 },
	/*0x13*/ { WEAPON_REAPER,           0x0f, 0xc8, 0x00, 0x00, 1, MPFEATURE_WEAPON_REAPER,          MODEL_CHRSKMINIGUN,     0x0100 },
	/*0x14*/ { WEAPON_SNIPERRIFLE,      0x04, 0x32, 0x00, 0x00, 1, 0,                                MODEL_CHRSNIPERRIFLE,   0x0100 },
	/*0x15*/ { WEAPON_FARSIGHTXR20,     0x06, 0x0a, 0x00, 0x00, 1, MPFEATURE_WEAPON_FARSIGHT,        MODEL_CHRZ2020,         0x0100 },
	/*0x16*/ { WEAPON_DEVASTATOR,       0x0b, 0x10, 0x00, 0x00, 1, MPFEATURE_WEAPON_DEVASTATOR,      MODEL_CHRDEVASTATOR,    0x0100 },
	/*0x17*/ { WEAPON_ROCKETLAUNCHER,   0x08, 0x03, 0x00, 0x00, 1, 0,                                MODEL_CHRDYROCKET,      0x0100 },
	/*0x18*/ { WEAPON_SLAYER,           0x08, 0x03, 0x00, 0x00, 1, MPFEATURE_WEAPON_SLAYER,          MODEL_CHRSKROCKET,      0x0100 },
	/*0x19*/ { WEAPON_COMBATKNIFE,      0x09, 0x05, 0x00, 0x00, 1, 0,                                MODEL_CHRKNIFE,         0x0100 },
	/*0x1a*/ { WEAPON_CROSSBOW,         0x03, 0x0a, 0x00, 0x00, 1, MPFEATURE_WEAPON_CROSSBOW,        MODEL_CHRCROSSBOW,      0x0100 },
	/*0x1b*/ { WEAPON_TRANQUILIZER,     0x13, 0x32, 0x00, 0x00, 1, MPFEATURE_WEAPON_TRANQUILIZER,    MODEL_CHRDRUGGUN,       0x0100 },
	/*0x1c*/ { WEAPON_GRENADE,          0x07, 0x05, 0x00, 0x00, 0, 0,                                MODEL_CHRGRENADE,       0x0100 },
	/*0x1d*/ { WEAPON_NBOMB,            0x12, 0x03, 0x00, 0x00, 0, MPFEATURE_WEAPON_NBOMB,           MODEL_CHRNBOMB,         0x0100 },
	/*0x1e*/ { WEAPON_TIMEDMINE,        0x0e, 0x05, 0x00, 0x00, 0, 0,                                MODEL_CHRTIMEDMINE,     0x0180 },
	/*0x1f*/ { WEAPON_PROXIMITYMINE,    0x0d, 0x05, 0x00, 0x00, 0, MPFEATURE_WEAPON_PROXIMITYMINE,   MODEL_CHRPROXIMITYMINE, 0x0180 },
	/*0x20*/ { WEAPON_REMOTEMINE,       0x0c, 0x05, 0x00, 0x00, 0, MPFEATURE_WEAPON_REMOTEMINE,      MODEL_CHRREMOTEMINE,    0x0180 },
	/*0x21*/ { WEAPON_LASER,            0x00, 0x00, 0x00, 0x00, 1, MPFEATURE_WEAPON_LASER,           MODEL_CHRLASER,         0x0200 },
	/*0x22*/ { WEAPON_XRAYSCANNER,      0x00, 0x00, 0x00, 0x00, 1, MPFEATURE_WEAPON_XRAYSCANNER,     MODEL_CHRNIGHTSIGHT,    0x0100 },
	/*0x23*/ { WEAPON_CLOAKINGDEVICE,   0x00, 0x00, 0x00, 0x00, 1, MPFEATURE_WEAPON_CLOAKINGDEVICE,  MODEL_CHRCLOAKER,       0x0100 },
	/*0x24*/ { WEAPON_COMBATBOOST,      0x00, 0x00, 0x00, 0x00, 1, MPFEATURE_WEAPON_COMBATBOOST,     MODEL_CHRSPEEDPILL,     0x0100 },
	/*0x25*/ { WEAPON_MPSHIELD,         0x00, 0x00, 0x00, 0x00, 1, MPFEATURE_WEAPON_SHIELD,          MODEL_CHRSHIELD,        0x0100 },
	/*0x26*/ { WEAPON_DISABLED,         0x00, 0x00, 0x00, 0x00, 0, 0x00,                             0,                      0x0000 },
};
