#ifndef _IN_LIB_LIB_121E0_H
#define _IN_LIB_LIB_121E0_H
#include <ultra64.h>
#include "types.h"

void func000121e0(void);
void memInit(u32 heapstart, u32 heaplen);
u32 func000122e0(void);
u32 func00012324(void);
void *func00012354(struct memorypool *pools, u32 len, u8 pool);
void *malloc(u32 len, u8 pool);
void func00012430(void *ptr, u32 len, u8 pool);
u32 func000124d4(u8 poolnum, bool secondary);
void func00012528(u8 pool);
void func00012594(u8 pool);
u32 func000125dc(void);
u32 func00012644(void);

#endif
