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
bool memaGrow(u32 arg0, u32 arg1);
void _memaFree(s32 addr, s32 size);
void memaFree(void *addr, s32 size);
s32 memaGetLongestFree(void);
bool memaRealloc(s32 addr, u32 oldsize, u32 newsize);

#endif
