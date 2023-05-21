#ifndef _IN_LIB_TLB_H
#define _IN_LIB_TLB_H
#include <ultra64.h>

void vmBoot(void);
void vmInitVars(void);
void vmInitVacant(void);
void vmHandleMiss(void);
void vmUnmapRange(u32 first, u32 last);

#endif
