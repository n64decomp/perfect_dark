//
// Stage ID 0x4e
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
	tag(0x00, 1)
	stdobject(0x0100, MODEL_A51_CRATE1, -1, OBJFLAG_00000001 | OBJFLAG_00000100 | OBJFLAG_IGNOREFLOORCOLOUR | OBJFLAG_IGNOREROOMCOLOUR | OBJFLAG_INVINCIBLE, 0, 0, 1000)
	tag(0x01, 1)
	stdobject(0x0100, MODEL_A51_CRATE1, -1, OBJFLAG_00000001 | OBJFLAG_00000100 | OBJFLAG_IGNOREFLOORCOLOUR | OBJFLAG_IGNOREROOMCOLOUR | OBJFLAG_INVINCIBLE, 0, 0, 1000)
	tag(0x02, 1)
	stdobject(0x0100, MODEL_A51_CRATE1, -1, OBJFLAG_00000001 | OBJFLAG_00000100 | OBJFLAG_IGNOREFLOORCOLOUR | OBJFLAG_IGNOREROOMCOLOUR | OBJFLAG_INVINCIBLE, 0, 0, 1000)
	endprops
};

s32 intro[] = {
	outfit(OUTFIT_DEFAULT)
	endintro
};

struct path paths[] = {
	{ NULL, 0, 0 },
};
