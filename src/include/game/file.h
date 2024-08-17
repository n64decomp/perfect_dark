#ifndef _IN_GAME_GAME_166E40_H
#define _IN_GAME_GAME_166E40_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

romptr_t file_get_rom_address(s32 filenum);
s32 file_get_rom_size(s32 filenum);
void files_init(void);
void file_load_part_to_addr(u16 filenum, void *memaddr, s32 offset, u32 len);
u32 file_get_inflated_size(s32 filenum);
void *file_load_to_new(s32 filenum, u32 method);
void *file_load_to_addr(s32 filenum, s32 method, u8 *ptr, u32 size);
u32 file_get_loaded_size(s32 filenum);
u32 file_get_allocation_size(s32 filenum);
void file_set_size(s32 filenum, void *ptr, u32 size, bool reallocate);
void files_stop(u8 arg0);
void func0f167330(void);

#endif
