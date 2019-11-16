//
// Complex (MP)
//

#include "stagesetup.h"

u8 intro[];
u8 props[];
struct aipaths paths[];
struct ailist ailists[];

void *setup[] = {
	NULL,
	NULL,
	NULL,
	intro,
	props,
	paths,
	ailists,
	NULL,
};

u8 props[] = {
	endprops
};

u8 intro[] = {
	intro_weapon(WEAPON_PP9I, -1)
	ammo(AMMOTYPE_PISTOL, 100)
	outfit(OUTFIT_DEFAULT)
	endintro
};

struct aipaths paths[] = {
	{ NULL, 0, 0 },
};

struct ailist ailists[] = {
	{ NULL, 0 },
};

