//
// Ravine (MP)
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
	lift(0x0100, MODEL_RAVINELIFT, PAD_AREC_00BC, OBJFLAG_00000008 | OBJFLAG_00000020 | OBJFLAG_00000040 | OBJFLAG_00000080 | OBJFLAG_IGNOREFLOORCOLOUR | OBJFLAG_INVINCIBLE | OBJFLAG_UNCOLLECTABLE | OBJFLAG_00400000 | OBJFLAG_01000000 | OBJFLAG_CANNOT_ACTIVATE, OBJFLAG2_00000100 | OBJFLAG2_00000200 | OBJFLAG2_IMMUNETOGUNFIRE | OBJFLAG2_BULLETPROOF | OBJFLAG2_00200000, 0, 1000, 0x00bc, 0x00bb, 0x00ba, -1, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000071c, 0x0010aaaa, 0x00000000)
	endprops
};

u8 unregistered_func1[] = {
	terminate
	endlist
};

u8 unregistered_func2[] = {
	terminate
	endlist
};

s32 intro[] = {
	endintro
};

struct path paths[] = {
	{ NULL, 0, 0 },
};

struct ailist ailists[] = {
	{ NULL, 0 },
};
