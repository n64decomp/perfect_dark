#ifndef _IN_LIB_LIB_48650_H
#define _IN_LIB_LIB_48650_H
#include <ultra64.h>
#include "types.h"

OSIntMask osSetIntMask(OSIntMask);
s32 osRecvMesg(OSMesgQueue *mq, OSMesg *msg, s32 flag);

#endif
