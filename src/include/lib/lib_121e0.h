#ifndef _IN_LIB_LIB_121E0_H
#define _IN_LIB_LIB_121E0_H
#include <ultra64.h>
#include "types.h"

void func000121e0(void);
void memInit(u32 heapstart, u32 heaplen);
u32 memGetPool4Available(void);
u32 memGetNextPool4Allocation(void);
u32 memAllocFromBank(struct memorypool *pool, u32 size, u8 poolnum);
void *malloc(u32 len, u8 pool);
s32 memReallocate(u32 allocation, s32 size, u8 poolnum);
u32 memGetFree(u8 poolnum, bool secondary);
void memResetPool(u8 pool);
void memDisablePool(u8 pool);
u32 func000125dc(void);
u32 func00012644(void);

#endif
