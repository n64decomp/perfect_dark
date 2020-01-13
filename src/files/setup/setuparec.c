//
// Ravine (MP)
//

#include "stagesetup.h"

u8 intro[];
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
	lift(0x0100, MODEL_RAVINELIFT, 0x00bc, 0x035204e8, 0x00304300, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000003e8, 0x00000000, 0x00000000, 0x0fff0000, 0x00bc, 0x00bb, 0x00baffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000071c, 0x0010aaaa, 0x00000000, 0x00000000, 0x00000000, 0x00000000)
	endprops
};

u8 unregistered_func1[] = {
	set_ailist(CHR_SELF, GAILIST_IDLE)
	endlist
};

u8 unregistered_func2[] = {
	set_ailist(CHR_SELF, GAILIST_IDLE)
	endlist
};

u8 intro[] = {
	endintro
};

struct path paths[] = {
	{ NULL, 0, 0 },
};

struct ailist ailists[] = {
	{ NULL, 0 },
};

