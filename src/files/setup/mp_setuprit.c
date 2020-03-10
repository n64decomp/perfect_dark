//
// Air Force One
//

#include "stagesetup.h"

s32 intro[];
u32 props[];
struct path paths[];
struct ailist ailists[];

struct stagesetup setup = {
	NULL,
	NULL,
	NULL,
	intro,
	props,
	paths,
	ailists,
	NULL,
};

u32 props[] = {
	endprops
};

s32 intro[] = {
	intro_weapon(WEAPON_UNARMED, -1)
	outfit(OUTFIT_DEFAULT)
	endintro
};

s32 path00[] = {
	-1,
};

struct path paths[] = {
	{ NULL, 0, 0 },
};

u8 func0000_004c[] = {
	endlist
};

struct ailist ailists[] = {
	{ NULL, 0 },
};

