#ifndef _IN_LIB_LIB_4D6F0_H
#define _IN_LIB_LIB_4D6F0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 func0004d6f0(void);
u32 func0004dc28(void);
u32 func0004def4(void);
u32 func0004e090(void);
void osMapTLB(s32 index, OSPageMask pm, void *vaddr, u32 evenpaddr, u32 oddpaddr, s32 asid);

#endif
