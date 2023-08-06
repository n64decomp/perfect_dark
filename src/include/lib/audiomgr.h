#ifndef _IN_LIB_AUDIOMGR_H
#define _IN_LIB_AUDIOMGR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void amgrInit(void);

#if VERSION >= VERSION_PAL_BETA
void amgrCreate(ALSynConfig *config, u32 *settings);
#else
void amgrCreate(ALSynConfig *config);
#endif

void amgrStartThread(void);
OSMesgQueue *amgrGetFrameMesgQueue(void);
void amgrStopThread(void);

#ifndef PLATFORM_N64
void amgrFrame(void);
#endif

#endif
