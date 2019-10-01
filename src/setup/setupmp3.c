//
// Area 52 (MP)
//

#include "../include/stagesetup.h"

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

u8 func1000_0038[] = {
	cmd01b2_mponly(20)
	set_function(CHR_SELF, GFUNC_IDLE)
	endfunction
};

struct ailists functions[] = {
	{ func1000_0038, 0x1000 },
	{ NULL, 0 },
};

