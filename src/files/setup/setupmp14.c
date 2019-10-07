//
// Stage ID 0x46
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
	outfit(OUTFIT_DEFAULT)
	endintro
};

struct aipaths paths[] = {
	{ NULL, 0, 0 },
};

struct ailists functions[] = {
	{ NULL, 0 },
};

