#ifndef _IN_LIB_MEMP_H
#define _IN_LIB_MEMP_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void mempInit(void);
void mempSetHeap(u8 *heapstart, u32 heaplen);
u32 mempGetStageFree(void);
void *mempGetNextStageAllocation(void);
void *mempAlloc(u32 len, u8 pool);
s32 mempRealloc(void *allocation, s32 newsize, u8 poolnum);
u32 mempGetPoolFree(u8 poolnum, u32 bank);
u32 mempGetPoolSize(u8 poolnum, u32 bank);
void mempResetPool(u8 pool);
void mempDisablePool(u8 pool);
void *mempAllocFromRight(u32 len, u8 pool);

#endif
