#include <ultra64.h>
#include "game/chr/chraicommands.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/cheats.h"
#include "game/game_107fb0.h"
#include "game/game_10ccd0.h"
#include "game/utils.h"
#include "game/game_1a3340.h"
#include "gvars/gvars.h"
#include "game/data/cheats.h"
#include "stagesetup.h"
#include "types.h"

struct cheat g_Cheats[NUM_CHEATS] = {
	{ L_MPWEAPONS(75),  123, SOLOSTAGEINDEX_EXTRACTION,     DIFF_A,  CHEATFLAG_TIMED | CHEATFLAG_TRANSFERPAK      }, // Hurricane Fists
	{ L_MPWEAPONS(76),  100, SOLOSTAGEINDEX_G5BUILDING,     DIFF_A,  CHEATFLAG_TIMED | CHEATFLAG_TRANSFERPAK      }, // Cloaking Device
	{ L_MPWEAPONS(77),  230, SOLOSTAGEINDEX_ESCAPE,         DIFF_A,  CHEATFLAG_TIMED                              }, // Invincible
	{ L_MPWEAPONS(78),  331, SOLOSTAGEINDEX_SKEDARRUINS,    DIFF_PA, CHEATFLAG_TIMED | CHEATFLAG_TRANSFERPAK      }, // All Guns in Solo
	{ L_MPWEAPONS(79),  427, SOLOSTAGEINDEX_PELAGIC,        DIFF_SA, CHEATFLAG_TIMED                              }, // Unlimited Ammo
	{ L_MPWEAPONS(80),  191, SOLOSTAGEINDEX_AIRBASE,        DIFF_SA, CHEATFLAG_TIMED                              }, // Unlimited Ammo, No Reloads
	{ L_MPWEAPONS(81),  0,   SOLOSTAGEINDEX_INVESTIGATION,  DIFF_A,  CHEATFLAG_COMPLETION                         }, // Slo-mo Single Player
	{ L_MPWEAPONS(82),  0,   SOLOSTAGEINDEX_CHICAGO,        DIFF_A,  CHEATFLAG_COMPLETION                         }, // DK Mode
	{ L_MPWEAPONS(83),  170, SOLOSTAGEINDEX_CRASHSITE,      DIFF_A,  CHEATFLAG_TIMED                              }, // Trent's Magnum
	{ L_MPWEAPONS(84),  447, SOLOSTAGEINDEX_DEEPSEA,        DIFF_PA, CHEATFLAG_TIMED                              }, // FarSight
	{ L_MPWEAPONS(85),  0,   SOLOSTAGEINDEX_G5BUILDING,     DIFF_A,  CHEATFLAG_COMPLETION                         }, // Small Jo
	{ L_MPWEAPONS(86),  0,   SOLOSTAGEINDEX_INFILTRATION,   DIFF_A,  CHEATFLAG_COMPLETION                         }, // Small Characters
	{ L_MPWEAPONS(87),  0,   SOLOSTAGEINDEX_DEFENSE,        DIFF_A,  CHEATFLAG_COMPLETION                         }, // Enemy Shields
	{ L_MPWEAPONS(88),  0,   SOLOSTAGEINDEX_DEEPSEA,        DIFF_A,  CHEATFLAG_COMPLETION                         }, // Jo Shield
	{ L_MPWEAPONS(89),  105, SOLOSTAGEINDEX_DEFENSE,        DIFF_A,  CHEATFLAG_TIMED                              }, // Super Shield
	{ L_MPWEAPONS(90),  0,   SOLOSTAGEINDEX_DEFECTION,      DIFF_A,  CHEATFLAG_COMPLETION                         }, // Classic Sight
	{ L_MPWEAPONS(91),  0,   SOLOSTAGEINDEX_AIRBASE,        DIFF_A,  CHEATFLAG_COMPLETION                         }, // Team Heads Only
	{ L_MPWEAPONS(92),  479, SOLOSTAGEINDEX_RESCUE,         DIFF_PA, CHEATFLAG_TIMED                              }, // Play as Elvis
	{ L_MPWEAPONS(93),  0,   SOLOSTAGEINDEX_PELAGIC,        DIFF_A,  CHEATFLAG_COMPLETION                         }, // Enemy Rockets
	{ L_MPWEAPONS(94),  235, SOLOSTAGEINDEX_AIRFORCEONE,    DIFF_PA, CHEATFLAG_TIMED                              }, // Unlimited Ammo - Laptop Sentry Gun
	{ L_MPWEAPONS(95),  90,  SOLOSTAGEINDEX_DEFECTION,      DIFF_SA, CHEATFLAG_TIMED                              }, // Marquis of Queensbury Rules
	{ L_MPWEAPONS(96),  0,   SOLOSTAGEINDEX_CRASHSITE,      DIFF_A,  CHEATFLAG_COMPLETION                         }, // Perfect Darkness
	{ L_MPWEAPONS(97),  390, SOLOSTAGEINDEX_INVESTIGATION,  DIFF_PA, CHEATFLAG_TIMED                              }, // Pugilist
	{ L_MPWEAPONS(98),  300, SOLOSTAGEINDEX_INFILTRATION,   DIFF_SA, CHEATFLAG_TIMED                              }, // Hotshot
	{ L_MPWEAPONS(99),  150, SOLOSTAGEINDEX_VILLA,          DIFF_SA, CHEATFLAG_TIMED                              }, // Hit and Run
	{ L_MPWEAPONS(100), 317, SOLOSTAGEINDEX_ATTACKSHIP,     DIFF_SA, CHEATFLAG_TIMED                              }, // Alien
	{ L_MPWEAPONS(101), 0,   SOLOSTAGEINDEX_SKEDARRUINS,    DIFF_A,  CHEATFLAG_COMPLETION | CHEATFLAG_TRANSFERPAK }, // R-Tracker/Weapon Cache Locations
	{ L_MPWEAPONS(102), 0,   SOLOSTAGEINDEX_EXTRACTION,     DIFF_A,  CHEATFLAG_COMPLETION                         }, // Rocket Launcher
	{ L_MPWEAPONS(103), 0,   SOLOSTAGEINDEX_VILLA,          DIFF_A,  CHEATFLAG_COMPLETION                         }, // Sniper Rifle
	{ L_MPWEAPONS(104), 0,   SOLOSTAGEINDEX_RESCUE,         DIFF_A,  CHEATFLAG_COMPLETION                         }, // X-Ray Scanner
	{ L_MPWEAPONS(105), 0,   SOLOSTAGEINDEX_ESCAPE,         DIFF_A,  CHEATFLAG_COMPLETION                         }, // SuperDragon
	{ L_MPWEAPONS(106), 0,   SOLOSTAGEINDEX_AIRFORCEONE,    DIFF_A,  CHEATFLAG_COMPLETION                         }, // Laptop Gun
	{ L_MPWEAPONS(107), 0,   SOLOSTAGEINDEX_ATTACKSHIP,     DIFF_A,  CHEATFLAG_COMPLETION                         }, // Phoenix
	{ L_MPWEAPONS(108), 120, SOLOSTAGEINDEX_CHICAGO,        DIFF_PA, CHEATFLAG_TIMED                              }, // Psychosis Gun
	{ L_MPWEAPONS(109), 36,  0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // PP9i
	{ L_MPWEAPONS(110), 37,  0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // CC13
	{ L_MPWEAPONS(111), 38,  0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // KL01313
	{ L_MPWEAPONS(112), 39,  0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // KF7 Special
	{ L_MPWEAPONS(113), 40,  0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // ZZT (9mm)
	{ L_MPWEAPONS(114), 41,  0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // DMC
	{ L_MPWEAPONS(115), 42,  0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // AR53
	{ L_MPWEAPONS(116), 43,  0,                             0,       CHEATFLAG_FIRINGRANGE                        }, // RC-P45
};

struct menu_item g_CheatWarningMenuItems[] = {
	{ MENUITEMTYPE_LABEL,       0, 0x00000000, L_MPMENU(479), 0x00000000, NULL }, // "If you activate any cheats, then you will be unable to progress further in the game while those cheats are active."
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPMENU(480), 0x00000000, NULL }, // "OK"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPMENU(481), 0x00000000, NULL }, // "Cancel"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menu_dialog g_CheatWarningMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPMENU(478), // "Warning"
	g_CheatWarningMenuItems,
	NULL,
	0x00000000,
	NULL,
};

struct menu_item g_CheatsFunMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,     7, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    10, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    11, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    16, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    17, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,     6, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, 0x00000096, 0x00000000, NULL },
	{ MENUITEMTYPE_MARQUEE,      0, 0x00000a00, (u32) &cheatGetMarquee, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, 0x00000096, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,   0, 0x00000028, L_MPMENU(477), 0x00000000, NULL }, // "Done"
	{ MENUITEMTYPE_END,          0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menu_dialog g_CheatsFunMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(118), // "Fun"
	g_CheatsFunMenuItems,
	cheatMenuHandleDialog,
	0x00000000,
	NULL,
};

struct menu_item g_CheatsGameplayMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,     2, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,     1, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    20, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    13, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    14, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    12, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    18, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    21, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, 0x00000096, 0x00000000, NULL },
	{ MENUITEMTYPE_MARQUEE,      0, 0x00000a00, (u32) &cheatGetMarquee, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, 0x00000096, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,   0, 0x00000028, L_MPMENU(477), 0x00000000, NULL }, // "Done"
	{ MENUITEMTYPE_END,          0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menu_dialog g_CheatsGameplayMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(119), // "Gameplay"
	g_CheatsGameplayMenuItems,
	cheatMenuHandleDialog,
	0x00000000,
	NULL,
};

struct menu_item g_CheatsSoloWeaponsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,    27, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    28, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    30, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    31, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    32, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    33, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,     8, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,     9, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, 0x00000096, 0x00000000, NULL },
	{ MENUITEMTYPE_MARQUEE,      0, 0x00000a00, (u32) &cheatGetMarquee, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, 0x00000096, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,   0, 0x00000028, L_MPMENU(477), 0x00000000, NULL }, // "Done"
	{ MENUITEMTYPE_END,          0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menu_dialog g_CheatsSoloWeaponsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(122), // "Weapons for Jo in Solo"
	g_CheatsSoloWeaponsMenuItems,
	cheatMenuHandleDialog,
	0x00000000,
	NULL,
};

struct menu_item g_CheatsClassicWeaponsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,    34, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    35, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    36, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    37, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    38, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    39, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    40, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    41, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, 0x000000c8, 0x00000000, NULL },
	{ MENUITEMTYPE_MARQUEE,      0, 0x00000a00, 0x00005490, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, 0x000000c8, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,   0, 0x00000028, 0x000051dd, 0x00000000, NULL },
	{ MENUITEMTYPE_END,          0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menu_dialog g_CheatsClassicWeaponsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(123), // "Classic Weapons for Jo in Solo"
	g_CheatsClassicWeaponsMenuItems,
	cheatMenuHandleDialog,
	0x00000000,
	NULL,
};

struct menu_item g_CheatsWeaponsMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,    15, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    19, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,     0, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,     4, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,     5, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    29, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    26, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_CHECKBOX,     3, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleCheatCheckbox },
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, 0x00000096, 0x00000000, NULL },
	{ MENUITEMTYPE_MARQUEE,      0, 0x00000a00, (u32) &cheatGetMarquee, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, 0x00000096, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,   0, 0x00000028, L_MPMENU(477), 0x00000000, NULL }, // "Done"
	{ MENUITEMTYPE_END,          0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menu_dialog g_CheatsWeaponsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(120), // "Weapons"
	g_CheatsWeaponsMenuItems,
	cheatMenuHandleDialog,
	0x00000000,
	NULL,
};

struct menu_item g_CheatsBuddiesMenuItems[] = {
	{ MENUITEMTYPE_CHECKBOX,     0, 0x00000000, L_MPWEAPONS(117), 0x00000000, cheatMenuHandleBuddyCheckbox }, // "Velvet Dark"
	{ MENUITEMTYPE_CHECKBOX,    22, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleBuddyCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    23, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleBuddyCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    24, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleBuddyCheckbox },
	{ MENUITEMTYPE_CHECKBOX,    25, 0x00000000, (u32) &cheatGetNameIfUnlocked, 0x00000000, cheatMenuHandleBuddyCheckbox },
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, 0x00000096, 0x00000000, NULL },
	{ MENUITEMTYPE_MARQUEE,      0, 0x00000a00, (u32) &cheatGetMarquee, 0x00000000, NULL },
	{ MENUITEMTYPE_SEPARATOR,    0, 0x00000000, 0x00000096, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,   0, 0x00000028, L_MPMENU(477), 0x00000000, NULL }, // "Done"
	{ MENUITEMTYPE_END,          0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menu_dialog g_CheatsBuddiesMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPWEAPONS(121), // "Buddies"
	g_CheatsBuddiesMenuItems,
	cheatMenuHandleDialog,
	0x00000000,
	NULL,
};

struct menu_item g_CheatsMenuItems[] = {
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPWEAPONS(118), 0x00000000, &g_CheatsFunMenuDialog }, // "Fun"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPWEAPONS(119), 0x00000000, &g_CheatsGameplayMenuDialog }, // "Gameplay"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPWEAPONS(122), 0x00000000, &g_CheatsSoloWeaponsMenuDialog }, // "Weapons for Jo in Solo"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPWEAPONS(123), 0x00000000, &g_CheatsClassicWeaponsMenuDialog }, // "Classic Weapons for Jo in Solo"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPWEAPONS(120), 0x00000000, &g_CheatsWeaponsMenuDialog }, // "Weapons"
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000004, L_MPWEAPONS(121), 0x00000000, &g_CheatsBuddiesMenuDialog }, // "Buddies"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000096, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000000, L_MPWEAPONS(217), 0x00000000, cheatMenuHandleTurnOffAllCheats }, // "Turn of all Cheats"
	{ MENUITEMTYPE_SEPARATOR,   0, 0x00000000, 0x00000096, 0x00000000, NULL },
	{ MENUITEMTYPE_SELECTABLE,  0, 0x00000028, L_MPMENU(477), 0x00000000, NULL }, // "Done"
	{ MENUITEMTYPE_END,         0, 0x00000000, 0x00000000, 0x00000000, NULL },
};

struct menu_dialog g_CheatsMenuDialog = {
	MENUDIALOGTYPE_DEFAULT,
	L_MPMENU(476), // "Cheats"
	g_CheatsMenuItems,
	cheatMenuHandleDialog,
	0x00000000,
	NULL,
};
