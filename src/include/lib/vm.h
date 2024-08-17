#ifndef _IN_LIB_VM_H
#define _IN_LIB_VM_H

#ifdef _LANGUAGE_C
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern u8 g_VmShowStats;

void vm_init(void);
#endif

#if VERSION >= VERSION_NTSC_1_0
#define VM_NUM_SLOTS 268
#else
#define VM_NUM_SLOTS 266
#endif

#define VM_PAGE_SIZE_SHIFT 12
#define VM_PAGE_SIZE       (1 << VM_PAGE_SIZE_SHIFT)

#define VM_BIGGEST_ZIP 0x1c80

#define VM_VACANTBITS_LEN ((VM_NUM_SLOTS + 7) / 8)

#define VM_VIRTUAL_ADDR 0x7f000000

#endif
