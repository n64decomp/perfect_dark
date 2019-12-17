//
// WAR!
//

#include "stagesetup.h"

u8 intro[];
u8 props[];
struct aipaths paths[];
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

u8 intro[] = {
	endintro
};

struct aipaths paths[] = {
	{ NULL, 0, 0 },
};

struct ailist ailists[] = {
	{ NULL, 0 },
};

