#ifndef _IN_LIB_LIB_481E0_H
#define _IN_LIB_LIB_481E0_H
#include <ultra64.h>
#include "types.h"

void __osSetFpcCsr(void);
void osStartThread(OSThread *thread);
void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msgBuf, s32 count);
void osStopThread(OSThread *thread);
void osSetThreadPri(OSThread *thread, OSPri pri);
u32 osGetCount(void);

#endif
