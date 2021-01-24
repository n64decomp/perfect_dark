#ifndef _ULTRA64_H_
#define _ULTRA64_H_

#include <math.h>

#include <PR/ultratypes.h>
#include <PR/os_exception.h>
#include <PR/os_misc.h>
#include <PR/os_rdp.h>
#include <PR/os_thread.h>
#include <PR/os_time.h>
#include <PR/os_message.h>
#include <PR/os_cont.h>
#include <PR/os_tlb.h>
#include <PR/sptask.h>
#include <PR/ucode.h>
#include <PR/os_cache.h>
#include <PR/os_vi.h>
#include <PR/os_pi.h>
#include <PR/os_pfs.h>
#include <PR/os_internal.h>
#include <PR/mbi.h>
#include <PR/os_eeprom.h>
#include <PR/os_libc.h>
#include <PR/gu.h>
#include <PR/os_ai.h>
#include <PR/libaudio.h>
#include <PR/libultra.h>
#include <PR/sched.h>

#define OS_K0_TO_PHYSICAL(x) (u32)(((char *)(x)-0x80000000))
#define OS_K1_TO_PHYSICAL(x) (u32)(((char *)(x)-0xa0000000))
#define OS_PHYSICAL_TO_K0(x) (void *)(((u32)(x)+0x80000000))
#define OS_PHYSICAL_TO_K1(x) (void *)(((u32)(x)+0xa0000000))

#endif
