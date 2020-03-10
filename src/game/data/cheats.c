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
	// name, time, stage index, difficulty, flags
	{ 0x544b, 123, 2,  DIFF_A,  CHEATFLAG_TIMED | CHEATFLAG_TRANSFERPAK      }, // Hurricane Fists
	{ 0x544c, 100, 5,  DIFF_A,  CHEATFLAG_TIMED | CHEATFLAG_TRANSFERPAK      }, // Cloaking Device
	{ 0x544d, 230, 8,  DIFF_A,  CHEATFLAG_TIMED                              }, // Invincible
	{ 0x544e, 331, 16, DIFF_PA, CHEATFLAG_TIMED | CHEATFLAG_TRANSFERPAK      }, // All Guns in Solo
	{ 0x544f, 427, 12, DIFF_SA, CHEATFLAG_TIMED                              }, // Unlimited Ammo
	{ 0x5450, 191, 9,  DIFF_SA, CHEATFLAG_TIMED                              }, // Unlimited Ammo, No Reloads
	{ 0x5451, 0,   1,  DIFF_A,  CHEATFLAG_COMPLETION                         }, // Slo-mo Single Player
	{ 0x5452, 0,   4,  DIFF_A,  CHEATFLAG_COMPLETION                         }, // DK Mode
	{ 0x5453, 170, 11, DIFF_A,  CHEATFLAG_TIMED                              }, // Trent's Magnum
	{ 0x5454, 447, 13, DIFF_PA, CHEATFLAG_TIMED                              }, // FarSight
	{ 0x5455, 0,   5,  DIFF_A,  CHEATFLAG_COMPLETION                         }, // Small Jo
	{ 0x5456, 0,   6,  DIFF_A,  CHEATFLAG_COMPLETION                         }, // Small Characters
	{ 0x5457, 0,   14, DIFF_A,  CHEATFLAG_COMPLETION                         }, // Enemy Shields
	{ 0x5458, 0,   13, DIFF_A,  CHEATFLAG_COMPLETION                         }, // Jo Shield
	{ 0x5459, 105, 14, DIFF_A,  CHEATFLAG_TIMED                              }, // Super Shield
	{ 0x545a, 0,   0,  DIFF_A,  CHEATFLAG_COMPLETION                         }, // Classic Sight
	{ 0x545b, 0,   9,  DIFF_A,  CHEATFLAG_COMPLETION                         }, // Team Heads Only
	{ 0x545c, 479, 7,  DIFF_PA, CHEATFLAG_TIMED                              }, // Play as Elvis
	{ 0x545d, 0,   12, DIFF_A,  CHEATFLAG_COMPLETION                         }, // Enemy Rockets
	{ 0x545e, 235, 10, DIFF_PA, CHEATFLAG_TIMED                              }, // Unlimited Ammo - Laptop Sentry Gun
	{ 0x545f, 90,  0,  DIFF_SA, CHEATFLAG_TIMED                              }, // Marquis of Queensbury Rules
	{ 0x5460, 0,   11, DIFF_A,  CHEATFLAG_COMPLETION                         }, // Perfect Darkness
	{ 0x5461, 390, 1,  DIFF_PA, CHEATFLAG_TIMED                              }, // Pugilist
	{ 0x5462, 300, 6,  DIFF_SA, CHEATFLAG_TIMED                              }, // Hotshot
	{ 0x5463, 150, 3,  DIFF_SA, CHEATFLAG_TIMED                              }, // Hit and Run
	{ 0x5464, 317, 15, DIFF_SA, CHEATFLAG_TIMED                              }, // Alien
	{ 0x5465, 0,   16, DIFF_A,  CHEATFLAG_COMPLETION | CHEATFLAG_TRANSFERPAK }, // R-Tracker/Weapon Cache Locations
	{ 0x5466, 0,   2,  DIFF_A,  CHEATFLAG_COMPLETION                         }, // Rocket Launcher
	{ 0x5467, 0,   3,  DIFF_A,  CHEATFLAG_COMPLETION                         }, // Sniper Rifle
	{ 0x5468, 0,   7,  DIFF_A,  CHEATFLAG_COMPLETION                         }, // X-Ray Scanner
	{ 0x5469, 0,   8,  DIFF_A,  CHEATFLAG_COMPLETION                         }, // SuperDragon
	{ 0x546a, 0,   10, DIFF_A,  CHEATFLAG_COMPLETION                         }, // Laptop Gun
	{ 0x546b, 0,   15, DIFF_A,  CHEATFLAG_COMPLETION                         }, // Phoenix
	{ 0x546c, 120, 4,  DIFF_PA, CHEATFLAG_TIMED                              }, // Psychosis Gun
	{ 0x546d, 36,  0,  DIFF_A,  CHEATFLAG_FIRINGRANGE                        }, // PP9i
	{ 0x546e, 37,  0,  DIFF_A,  CHEATFLAG_FIRINGRANGE                        }, // CC13
	{ 0x546f, 38,  0,  DIFF_A,  CHEATFLAG_FIRINGRANGE                        }, // KL01313
	{ 0x5470, 39,  0,  DIFF_A,  CHEATFLAG_FIRINGRANGE                        }, // KF7 Special
	{ 0x5471, 40,  0,  DIFF_A,  CHEATFLAG_FIRINGRANGE                        }, // ZZT (9mm)
	{ 0x5472, 41,  0,  DIFF_A,  CHEATFLAG_FIRINGRANGE                        }, // DMC
	{ 0x5473, 42,  0,  DIFF_A,  CHEATFLAG_FIRINGRANGE                        }, // AR53
	{ 0x5474, 43,  0,  DIFF_A,  CHEATFLAG_FIRINGRANGE                        }, // RC-P45
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
