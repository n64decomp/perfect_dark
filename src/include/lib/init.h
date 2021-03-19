#ifndef _IN_BOOT_INIT_H
#define _IN_BOOT_INIT_H
#include <ultra64.h>

void init(void);
s32 initGetMemSize(void);
void *allocateStack(s32 threadid, s32 size);
void mainproc(void *arg);

#endif
