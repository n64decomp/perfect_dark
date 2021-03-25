#ifndef _IN_LIB_LIB_4F5E0_H
#define _IN_LIB_LIB_4F5E0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 osMotorAccess(OSPfs *pfs, u32 vibrate);
void osSetUpMempakWrite(s32 channel, OSPifRam* buf);
bool func0004f854(OSMesgQueue *mq, OSPfs *pfs, s32 arg2);
u32 func0004f9b0(void);
u32 func0004fbc0(void);
u32 func0004fbf0(void);

#endif
