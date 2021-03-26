#ifndef _IN_LIB_AUDIOMGR_H
#define _IN_LIB_AUDIOMGR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void amgrAllocateStack(void);

#if VERSION >= VERSION_PAL_FINAL
void amgrCreate(ALSynConfig *config, u32 *arg1);
#else
void amgrCreate(ALSynConfig *config);
#endif

void amgrStartThread(void);
OSMesgQueue *amgr00009118(void);
void amgrStopThread(void);

#endif
