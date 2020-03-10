#ifndef _IN_LIB_LIB_034F0_H
#define _IN_LIB_LIB_034F0_H
#include <ultra64.h>
#include "types.h"

u32 __osExceptionPreamble(void);
u32 func00003ab8(void);
u32 __osEnqueueAndYield(void);
u32 __osEnqueueThread(void);
u32 __osPopThread(void);
u32 __osDispatchThread(void);

#endif
