#ifndef _IN_LIB_TLB_H
#define _IN_LIB_TLB_H
#include <ultra64.h>

void tlbInit(void);
void tlb000010a4(void);
void tlb0000113c(void);
void tlbHandleMiss(void);
void tlbUnmapRange(u32 first, u32 last);

#endif
