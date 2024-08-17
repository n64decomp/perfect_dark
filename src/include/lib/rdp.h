#ifndef _IN_LIB_RDP_H
#define _IN_LIB_RDP_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void rdp_init(void);
void rdp_create_task(Gfx *gdlstart, Gfx *gdlend, u32 arg2, s32 msg);

#endif
