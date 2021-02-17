#ifndef _IN_LIB_LIB_06550_H
#define _IN_LIB_LIB_06550_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 func00006550(struct var800a3180 *arg0, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, u32 numbytes);
s32 func00006d60(OSMesgQueue *mq, struct var800a3180 *arg1, s32 channel, s32 arg3);
u32 func00006f98(void);
u32 func00007084(void);

#endif
