#ifndef _IN_LIB_LIB_06550_H
#define _IN_LIB_LIB_06550_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 osPfsReSizeFile(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, u32 numbytes);

#if VERSION >= VERSION_NTSC_1_0
s32 osPfsInitPak(OSMesgQueue *mq, OSPfs *pfs, s32 channel, s32 *arg3);
#else
s32 osPfsInitPak(OSMesgQueue *mq, OSPfs *pfs, s32 channel);
#endif

s32 func00007084(OSPfs *pfs);

#endif
