#ifndef _IN_LIB_BOOT_H
#define _IN_LIB_BOOT_H
#include <ultra64.h>

extern u32 g_OsMemSize;

void bootPhase1(void);
void *bootAllocateStack(s32 threadid, s32 size);

#endif
