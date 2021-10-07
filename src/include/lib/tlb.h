#ifndef _IN_LIB_TLB_H
#define _IN_LIB_TLB_H
#include <ultra64.h>

void tlbInit(void);
s32 tlb000010a4(void);
s32 tlb0000113c(void);
s32 tlbHandleMiss(void);
void tlbUnmapRange(u32 first, u32 last);

#endif
