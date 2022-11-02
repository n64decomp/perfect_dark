//
// Area 52 (MP)
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

u8 func1000_0038[] = {
	set_wind_speed(20)
	terminate
	endlist
};

struct ailist ailists[] = {
	{ func1000_0038, 0x1000 },
	{ NULL, 0 },
};

