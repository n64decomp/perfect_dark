#ifndef _IN_LIB_AUDIOMGR_H
#define _IN_LIB_AUDIOMGR_H
#include <ultra64.h>
#include "types.h"

void amgrAllocateStack(void);
u32 amgrCreate(void);
void amgrStartThread(void);
OSMesgQueue *amgr00009118(void);
void amgrStopThread(void);

#endif
