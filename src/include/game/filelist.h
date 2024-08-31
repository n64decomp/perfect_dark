#ifndef IN_GAME_FILELIST_H
#define IN_GAME_FILELIST_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void func0f110bf0(void);
void func0f110bf8(void);
void filelist_create(s32 listnum, u8 filetype);
s32 filelist_find_or_create(u8 filetype);
void filelist_invalidate_pak(s32 device);
void filelists_tick(void);

#endif
