#ifndef _IN_LIB_LIB_06440_H
#define _IN_LIB_LIB_06440_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 osEepromLongWrite(OSMesgQueue *mq, u8 address, u8 *buffer, int nbytes);

#endif
