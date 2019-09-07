//
// Stage ID 0x3a
//

#include "../include/setup.h"

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
	endintro
};

s32 path00[] = {
	-1,
};

struct aipaths paths[] = {
	{ NULL, 0, 0 },
};

u8 unregistered_func1[] = {
	endfunction
};

u8 unregistered_func2[] = {
	cmd0185_mponly
	cmd0145_rebuild_groups
	cmd0146_rebuild_groups
	set_function(CHR_SELF, GFUNC_IDLE)
	endfunction
};

struct ailists functions[] = {
	{ NULL, 0 },
};

