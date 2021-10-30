#ifndef _IN_LIB_LIB_126B0_H
#define _IN_LIB_LIB_126B0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void memaDefrag(void);
void memaInit(void);
void memaHeapInit(void *ptr, u32 size);
void memaPrint(void);
void *memaAlloc(u32 size);
u32 func00012c3c(void);
void memaFree(void *addr, s32 size);
s32 memaGetLongestFree(void);
u32 func00012d48(void);

#endif
