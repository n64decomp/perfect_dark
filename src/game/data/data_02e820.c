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
#include "game/training/menus.h"
#include "game/game_1a7560.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "stagesetup.h"
#include "types.h"

u32 var800897c0 = 0x1c1d0000;
s8 var800897c4[] = {-73, 0, 5, 0};
u32 var800897c8 = 0x0400ff00;

// 2f7ec
struct hoverprop hoverprops[] = {
	// File ID, Y offset, size
	{ FILE_PDROPSHIP,       7,   8    },
	{ FILE_PHOVERCRATE1,    -5,  600  },
	{ FILE_PHOVBIKE,        -10, 50   },
	{ FILE_PHOOVERBOT,      -20, 1000 },
	{ FILE_PDD_HOVERCOPTER, 35,  30   },
	{ FILE_CCHICROB,        0,   70   },
	{ FILE_PA51INTERCEPTOR, -30, 500  },
	{ FILE_PELVIS_SAUCER,   0,   15   },
	{ FILE_PSK_SHUTTLE,     0,   10   },
};

// 2f858
struct menuitem g_HangarDetailsMenuItems[] = {
	{ MENUITEMTYPE_MODEL,      0,                     0x00200002, 0x00000104,    0x0000002c, menuhandler001a6ea4 },
	{ MENUITEMTYPE_SEPARATOR,  0,                     0x00000002, 0x00000000,    0x00000000, NULL                },
	{ MENUITEMTYPE_SCROLLABLE, DESCRIPTION_HANGARBIO, 0x00000000, 0x00000104,    0x0000005a, NULL                },
	{ MENUITEMTYPE_SEPARATOR,  0,                     0x00000002, 0x00000000,    0x00000000, NULL                },
	{ MENUITEMTYPE_LABEL,      0,                     0x00000022, L_MPMENU(414), 0x00000000, NULL                }, // "Press the B Button to go back."
	{ MENUITEMTYPE_END,        0,                     0x00000000, 0x00000000,    0x00000000, NULL                },
};

// 2f8d0
struct menuitem g_HangarVehicleHolographMenuItems[] = {
	{ MENUITEMTYPE_MODEL,       0, 0x00000002, 0x00000104, 0x0000006e, NULL },
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000002, 0x00000000, 0x00000000, NULL },
	{ MENUITEMTYPE_LABEL,       0, 0x00000022, L_MPMENU(414), 0x00000000, NULL }, // "Press the B Button to go back."
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2f920
struct menudialog g_HangarVehicleHolographMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MISC(471), // "Holograph"
	g_HangarVehicleHolographMenuItems,
	ciHangarHolographMenuDialog,
	0x00000202,
	NULL,
};

// 2f938
struct menudialog g_HangarVehicleDetailsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&bioMenuTextName,
	g_HangarDetailsMenuItems,
	NULL,
	0x00000202,
	&g_HangarVehicleHolographMenuDialog,
};

// 2f950
struct menudialog g_HangarLocationDetailsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	(u32)&bioMenuTextName,
	g_HangarDetailsMenuItems,
	NULL,
	0x00000202,
	NULL,
};

// 2f968
struct menuitem g_HangarListMenuItems[] = {
	{ MENUITEMTYPE_LIST,        0, 0x00000008, 0x000000a0, 0x00000000, ciHangarInformationMenuHandler },
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

// 2f990
struct menudialog g_HangarListMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(415), // "Hangar Information"
	g_HangarListMenuItems,
	NULL,
	0x00000000,
	NULL,
};

u32 var80089988 = 0x00000000;
u32 var8008998c = 0x00000000;
u32 var80089990 = (u32) &stagethinglist_22e60;
u32 var80089994 = (u32) &stagethinglist_221cc;
u32 var80089998 = (u32) &stagethinglist_22200;
u32 var8008999c = (u32) &stagethinglist_22220;
u32 var800899a0 = (u32) &stagethinglist_2208c;
u32 var800899a4 = (u32) &stagethinglist_20e54;
u32 var800899a8 = (u32) &stagethinglist_20ef8;
u32 var800899ac = (u32) &stagethinglist_20ea4;
u32 var800899b0 = (u32) &stagethinglist_20eec;
u32 var800899b4 = (u32) &stagethinglist_20ec8;
u32 var800899b8 = (u32) &stagethinglist_20e60;
u32 var800899bc = (u32) &stagethinglist_20e6c;
u32 var800899c0 = (u32) &stagethinglist_20e94;
u32 var800899c4 = (u32) &stagethinglist_20f0c;
u32 var800899c8 = (u32) &stagethinglist_20edc;
u32 var800899cc = (u32) &stagethinglist_20e80;
u32 var800899d0 = (u32) &stagethinglist_221a4;
u32 var800899d4 = (u32) &stagethinglist_220d0;
u32 var800899d8 = (u32) &stagethinglist_221e4;
u32 var800899dc = (u32) &stagethinglist_220a4;
u32 var800899e0 = (u32) &stagethinglist_20f18;
u32 var800899e4 = (u32) &stagethinglist_2224c;
u32 var800899e8 = (u32) &stagethinglist_20e48;
u32 var800899ec = (u32) &stagethinglist_22eb8;
u32 var800899f0 = (u32) &stagethinglist_20f24;
u32 var800899f4 = (u32) &stagethinglist_20f50;
u32 var800899f8 = (u32) &stagethinglist_20f5c;
u32 var800899fc = (u32) &stagethinglist_20f74;
u32 var80089a00 = (u32) &stagethinglist_221b4;
u32 var80089a04 = (u32) &stagethinglist_222b4;
u32 var80089a08 = (u32) &stagethinglist_22f0c;
u32 var80089a0c = (u32) &stagethinglist_22318;
u32 var80089a10 = (u32) &stagethinglist_22374;
u32 var80089a14 = (u32) &stagethinglist_20f84;
u32 var80089a18 = (u32) &stagethinglist_223d4;
u32 var80089a1c = (u32) &stagethinglist_22424;
u32 var80089a20 = (u32) &stagethinglist_22ec8;
u32 var80089a24 = (u32) &stagethinglist_20fb8;
u32 var80089a28 = (u32) &stagethinglist_2247c;
u32 var80089a2c = (u32) &stagethinglist_20fd8;
u32 var80089a30 = (u32) &stagethinglist_224d8;
u32 var80089a34 = (u32) &stagethinglist_22538;
u32 var80089a38 = (u32) &stagethinglist_2258c;
u32 var80089a3c = (u32) &stagethinglist_225d8;
u32 var80089a40 = (u32) &stagethinglist_22630;
u32 var80089a44 = (u32) &stagethinglist_22698;
u32 var80089a48 = (u32) &stagethinglist_226e8;
u32 var80089a4c = (u32) &stagethinglist_22754;
u32 var80089a50 = (u32) &stagethinglist_20e10;
u32 var80089a54 = (u32) &stagethinglist_227ac;
u32 var80089a58 = (u32) &stagethinglist_22804;
u32 var80089a5c = (u32) &stagethinglist_22f1c;
u32 var80089a60 = (u32) &stagethinglist_2285c;
u32 var80089a64 = (u32) &stagethinglist_228b4;
u32 var80089a68 = (u32) &stagethinglist_2291c;
u32 var80089a6c = (u32) &stagethinglist_22970;
u32 var80089a70 = (u32) &stagethinglist_229c4;
u32 var80089a74 = (u32) &stagethinglist_22a20;
u32 var80089a78 = (u32) &stagethinglist_22a78;
u32 var80089a7c = (u32) &stagethinglist_22adc;
u32 var80089a80 = (u32) &stagethinglist_22c54;
u32 var80089a84 = (u32) &stagethinglist_22b28;
u32 var80089a88 = (u32) &stagethinglist_22b80;
u32 var80089a8c = (u32) &stagethinglist_22be0;
u32 var80089a90 = (u32) &stagethinglist_22ca0;
u32 var80089a94 = (u32) &stagethinglist_22c3c;
u32 var80089a98 = (u32) &stagethinglist_20e3c;
u32 var80089a9c = (u32) &stagethinglist_22cf0;
u32 var80089aa0 = (u32) &stagethinglist_20fe8;
u32 var80089aa4 = (u32) &stagethinglist_22d40;
u32 var80089aa8 = (u32) &stagethinglist_20ff8;
u32 var80089aac = (u32) &stagethinglist_2100c;
u32 var80089ab0 = (u32) &stagethinglist_21018;
u32 var80089ab4 = (u32) &stagethinglist_22d90;
u32 var80089ab8 = (u32) &stagethinglist_22de0;
u32 var80089abc = (u32) &stagethinglist_21024;
u32 var80089ac0 = (u32) &stagethinglist_21034;
u32 var80089ac4 = (u32) &stagethinglist_22e34;
u32 var80089ac8 = (u32) &stagethinglist_21084;
