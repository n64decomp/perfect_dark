#ifndef _IN_LIB_BOOT_H
#define _IN_LIB_BOOT_H
#include <ultra64.h>

void boot(void);
s32 boot000010a4(void);
s32 boot0000113c(void);
s32 boot00001180(void);
void bootUnmapTLBRange(s32 first, s32 last);

#endif
