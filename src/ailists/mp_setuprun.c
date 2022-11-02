//
// Stage ID 0x23
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
	ailists,
	NULL,
};

u32 props[] = {
	endprops
};

s32 intro[] = {
	outfit(OUTFIT_DEFAULT)
	endintro
};

struct path paths[] = {
	{ NULL, 0, 0 },
};

u8 unregistered_func1[] = {
	terminate
	endlist
};

u8 unregistered_func2[] = {
	mp_init_simulants
	rebuild_teams
	rebuild_squadrons
	terminate
	endlist
};

struct ailist ailists[] = {
	{ NULL, 0 },
};

