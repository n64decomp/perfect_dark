#ifndef _IN_LIB_LIB_4D480_H
#define _IN_LIB_LIB_4D480_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 osPfsDeleteFile(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name);
s32 __osPfsReleasePages(OSPfs *pfs, __OSInode *inode, u8 initialPage, u8 bank, __OSInodeUnit* final_page);

#endif
