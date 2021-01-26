#ifndef _IN_BOOT_INIT_H
#define _IN_BOOT_INIT_H
#include <ultra64.h>

s32 func000016cc(void);
s32 osGetMemSize(void);
void *allocateStack(s32 threadid, s32 size);

#endif
