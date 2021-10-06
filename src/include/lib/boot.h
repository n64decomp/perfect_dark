#ifndef _IN_LIB_BOOT_H
#define _IN_LIB_BOOT_H
#include <ultra64.h>

void bootPhase1(void);
s32 bootGetMemSize(void);
void *bootAllocateStack(s32 threadid, s32 size);
void bootPhase2(void *arg);

#endif
