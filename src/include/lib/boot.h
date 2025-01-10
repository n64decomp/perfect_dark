#ifndef _IN_LIB_BOOT_H
#define _IN_LIB_BOOT_H
#include <ultra64.h>

#if VERSION >= VERSION_NTSC_1_0
extern s32 osGetMemSize(void);
#else
extern u32 osGetMemSize(void);
#endif

void boot(void);
void *boot_allocate_stack(s32 threadid, s32 size);
void boot_check_stack_overflow(void);

#endif
