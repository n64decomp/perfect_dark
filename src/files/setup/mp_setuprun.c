//
// Stage ID 0x23
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

u8 unregistered_func1[] = {
	set_function(CHR_SELF, GFUNC_IDLE)
	endfunction
};

u8 unregistered_func2[] = {
	cmd0185_mponly
	rebuild_teams
	rebuild_squadrons
	set_function(CHR_SELF, GFUNC_IDLE)
	endfunction
};

struct ailists functions[] = {
	{ NULL, 0 },
};

