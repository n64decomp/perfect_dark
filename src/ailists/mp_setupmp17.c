//
// Stage ID 0x49
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

u8 func1001_0038[] = {
	set_wind_speed(130)
	terminate
	endlist
};

u8 func1000_0044[] = {
	mp_init_simulants
	rebuild_teams
	rebuild_squadrons
	terminate
	endlist
};

struct ailist ailists[] = {
	{ func1000_0044, 0x1000 },
	{ func1001_0038, 0x1001 },
	{ NULL, 0 },
};

