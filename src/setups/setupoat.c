//
// Skedar (MP)
//

#include "stagesetup.h"

// AI Lists
#define AILIST_INIT_ENEMY 0x0401
#define AILIST_INIT_MAIAN 0x0402

extern s32 intro[];
extern u32 props[];
extern struct path paths[];
extern struct ailist ailists[];

struct stagesetup setup = {
	NULL,
	NULL,
	NULL,
	intro,
	props,
	paths,
	NULL,
	NULL,
};

u32 props[] = {
	endprops
};

s32 intro[] = {
	spawn(PAD_OAT_0063)
	outfit(OUTFIT_DEFAULT)
	intro_weapon(WEAPON_FALCON2, -1)
	intro_weapon(WEAPON_CMP150, -1)
	intro_weapon(WEAPON_AR34, -1)
	intro_weapon(WEAPON_REAPER, -1)
	ammo(AMMOTYPE_PISTOL, 500)
	ammo(AMMOTYPE_RIFLE, 500)
	endintro
};

s32 path00[] = {
	PAD_OAT_0014,
	PAD_OAT_0015,
	-1,
};

s32 path01[] = {
	PAD_OAT_0064,
	PAD_OAT_0066,
	-1,
};

s32 path02[] = {
	PAD_OAT_0037,
	PAD_OAT_0033,
	PAD_OAT_0034,
	-1,
};

s32 path03[] = {
	PAD_OAT_0038,
	PAD_OAT_0039,
	PAD_OAT_003A,
	-1,
};

s32 path04[] = {
	PAD_OAT_0033,
	PAD_OAT_0037,
	PAD_OAT_0036,
	PAD_OAT_003D,
	PAD_OAT_003E,
	PAD_OAT_003F,
	PAD_OAT_0045,
	PAD_OAT_0048,
	PAD_OAT_003B,
	PAD_OAT_003A,
	PAD_OAT_0039,
	-1,
};

struct path paths[] = {
	{ path00, 0, 0 },
	{ path01, 1, 0 },
	{ path00, 0, 0 },
	{ path02, 2, 0 },
	{ path03, 3, 0 },
	{ path04, 4, 0 },
	{ NULL, 0, 0 },
};

