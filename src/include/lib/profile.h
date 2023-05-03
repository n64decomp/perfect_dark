#ifndef _IN_LIB_PROFILE_H
#define _IN_LIB_PROFILE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

enum rspevent {
	RSPEVENT_AUD_START,
	RSPEVENT_AUD_FINISH,
	RSPEVENT_GFX_START,
	RSPEVENT_GFX_FINISH
};

void profileInit(void);
void profileTick(void);
void profileReset(void);
void profile00009a98(void);
void profileHandleRspEvent(s32 event);
void profileGetCounters(u32 counters[5]);

#ifdef PROFILING
void profileStart(s32 arg0);
void profileEnd(s32 arg0);
#endif

Gfx *profileRender(Gfx *gdl);
Gfx *profileRenderDynamic(Gfx *gdl);

#endif
