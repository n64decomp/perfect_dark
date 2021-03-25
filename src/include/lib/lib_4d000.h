#ifndef _IN_LIB_LIB_4D000_H
#define _IN_LIB_LIB_4D000_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 osPfsAllocateFile(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name, s32 num_bytes, s32 *file_no);
s32 __osPfsDeclearPage(OSPfs *pfs, __OSInode *inode, s32 fileSizeInPages, s32 *startPage, u8 bank, s32 *decleared, s32 *finalPage);

#endif
