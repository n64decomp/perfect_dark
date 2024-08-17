#ifndef _IN_LIB_BOOT_H
#define _IN_LIB_BOOT_H
#include <ultra64.h>

void boot(void);
s32 boot_get_mem_size(void);
void *boot_allocate_stack(s32 threadid, s32 size);
void boot_create_threads(void *arg);
void boot_check_stack_overflow(void);

#endif
