#ifndef _IN_LIB_TLB_H
#define _IN_LIB_TLB_H
#include <ultra64.h>

void vm_boot(void);
void vm_init_vars(void);
void vm_init_vacant(void);
void vm_handle_miss(void);
void vm_unmap_range(u32 first, u32 last);

#endif
