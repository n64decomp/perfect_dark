#ifndef _IN_LIB_LIB_491B0_H
#define _IN_LIB_LIB_491B0_H
#include <ultra64.h>
#include "types.h"

u32 __osTimerServicesInit(void);
u32 __osTimerInterrupt(void);
u32 __osSetTimerIntr(void);
u32 __osInsertTimer(void);
u32 __osDisableInt(void);
u32 __osRestoreInt(void);

#endif
