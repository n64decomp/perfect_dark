#ifndef _IN_LIB_LIB_08A20_H
#define _IN_LIB_LIB_08A20_H
#include <ultra64.h>
#include "types.h"

void amgrAllocateStack(void);
u32 amgrCreate(void);
void amgrStartThread(void);
OSMesgQueue *amgr0009118(void);
void amgrStopThread(void);

#endif
