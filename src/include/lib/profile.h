#ifndef _IN_LIB_PROFILE_H
#define _IN_LIB_PROFILE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void profile_init(void);
void profile_tick(void);
void profile_reset(void);
void profile00009a98(void);
void profile_set_marker(u32 arg0);
Gfx *profile_render(Gfx *gdl);

#endif
