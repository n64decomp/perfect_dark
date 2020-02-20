//
// Stage ID 0x4b
//

#include "stagesetup.h"

s32 intro[];
u8 props[];
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

u8 props[] = {
	endprops
};

s32 intro[] = {
	outfit(OUTFIT_DEFAULT)
	endintro
};

struct path paths[] = {
	{ NULL, 0, 0 },
};

u8 func1000_0038[] = {
	mp_init_simulants
	rebuild_teams
	rebuild_squadrons
	set_ailist(CHR_SELF, GAILIST_IDLE)
	endlist
};

struct ailist ailists[] = {
	{ func1000_0038, 0x1000 },
	{ NULL, 0 },
};

