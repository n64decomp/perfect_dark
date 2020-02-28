#ifndef _IN_LIB_LIB_4A810_H
#define _IN_LIB_LIB_4A810_H
#include <ultra64.h>
#include "types.h"

u32 __osSiCreateAccessQueue(void);
u32 __osSiGetAccess(void);
u32 __osSiRelAccess(void);
u32 __osSiRawStartDma(void);

#endif
