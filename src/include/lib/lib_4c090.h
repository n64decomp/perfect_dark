#ifndef _IN_LIB_LIB_4C090_H
#define _IN_LIB_LIB_4C090_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u16 __osSumCalc(u8 *ptr, int length);
s32 __osIdCheckSum(u16 *ptr, u16 *csum, u16 *icsum);
s32 __osRepairPackId(OSPfs *pfs, __OSPackId *badid, __OSPackId *newid);
s32 __osCheckPackId(OSPfs *pfs, __OSPackId *temp);
s32 __osGetId(OSPfs *pfs);
u32 func0004c860(void);
u32 func0004c934(void);

#endif
