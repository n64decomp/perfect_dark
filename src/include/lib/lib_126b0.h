#ifndef _IN_LIB_LIB_126B0_H
#define _IN_LIB_LIB_126B0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void memaDefrag(void);
u32 func00012800(void);
u32 func00012914(void);
void memaInit(void);
void memaHeapInit(void *ptr, u32 arg1);
void memaPrint(void);
void *memaAlloc(u32 size);
u32 func00012c3c(void);
void func00012cb4(void *arg0, s32 arg1);
s32 memaGetLongestFree(void);
u32 func00012d48(void);

#endif
