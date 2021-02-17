#ifndef _IN_LIB_MEMORY_H
#define _IN_LIB_MEMORY_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void func000121e0(void);
void memInit(u32 heapstart, u32 heaplen);
u32 memGetPool4Available(void);
u32 memGetNextPool4Allocation(void);
u32 memAllocFromBank(struct memorypool *pool, u32 size, u8 poolnum);
void *malloc(u32 len, u8 pool);
s32 memReallocate(u32 allocation, s32 size, u8 poolnum);
u32 memGetFree(u8 poolnum, u32 bank);
void memResetPool(u8 pool);
void memDisablePool(u8 pool);
u32 memAllocFromBankRight(void);
u32 mallocFromRight(void);

#endif
