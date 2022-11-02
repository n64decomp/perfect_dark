//
// Pipes (MP)
//

#include "stagesetup.h"

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
	intro_weapon(WEAPON_FALCON2, -1)
	ammo(AMMOTYPE_PISTOL, 100)
	endintro
};

struct path paths[] = {
	{ NULL, 0, 0 },
};

struct ailist ailists[] = {
	{ NULL, 0 },
};

