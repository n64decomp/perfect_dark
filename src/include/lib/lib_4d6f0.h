#ifndef _IN_LIB_LIB_4D6F0_H
#define _IN_LIB_LIB_4D6F0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 osPfsChecker(OSPfs *pfs);
u32 func0004dc28(void);
u32 func0004def4(void);
s32 func0004e090(u8 *id, u8 *buffer, u32 len);
void osMapTLB(s32 index, OSPageMask pm, void *vaddr, u32 evenpaddr, u32 oddpaddr, s32 asid);

#endif
