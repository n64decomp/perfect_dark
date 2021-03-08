#ifndef _IN_BOOT_ENTRY_H
#define _IN_BOOT_ENTRY_H
#include <ultra64.h>

s32 boot000010a4(void);
s32 boot0000113c(void);
s32 boot00001180(void);
void bootUnmapTLBRange(s32 first, s32 last);

#endif
