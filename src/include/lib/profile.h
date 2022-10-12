#ifndef _IN_LIB_PROFILE_H
#define _IN_LIB_PROFILE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void profileInit(void);
void profileTick(void);
void profileReset(void);
void profile00009a98(void);
void profileSetMarker(u32 arg0);
Gfx *profileRender(Gfx *gdl);

#endif
