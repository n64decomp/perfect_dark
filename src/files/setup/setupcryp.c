//
// G5 Building (MP)
//

#include "stagesetup.h"

u8 intro[];
u8 props[];
struct aipaths paths[];
struct ailists functions[];

void *setup[] = {
	NULL,
	NULL,
	NULL,
	intro,
	props,
	paths,
	functions,
	NULL,
};

u8 props[] = {
	endprops
};

u8 intro[] = {
	intro_weapon(WEAPON_FALCON2, -1)
	endintro
};

struct aipaths paths[] = {
	{ NULL, 0, 0 },
};

struct ailists functions[] = {
	{ NULL, 0 },
};

