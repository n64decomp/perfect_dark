#ifndef _IN_LIB_LIB_4BA90_H
#define _IN_LIB_LIB_4BA90_H
#include <ultra64.h>
#include "types.h"

u32 __osPfsGetStatus(void);
u32 __osPfsRequestOneChannel(void);
u32 __osPfsGetOneChannelData(void);
s32 osEepromWrite(OSMesgQueue *mq, u8 address, u8 *buffer);
u32 __osPackEepWriteData(void);
u32 __osEepStatus(void);

#endif
