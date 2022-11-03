#ifndef _IN_LIB_PROFILE_H
#define _IN_LIB_PROFILE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void profileInit(void);
void profileTick(void);
void profileReset(void);
void profile00009a98(void);

#ifdef PROFILING
void profileStart(s32 arg0);
void profileEnd(s32 arg0);
void profileHandleRspEvent(s32 event);
#endif

Gfx *profileRender(Gfx *gdl);

#endif
