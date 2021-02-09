#ifndef _IN_GAME_GAME_166E40_H
#define _IN_GAME_GAME_166E40_H
#include <ultra64.h>
#include "types.h"

void *fileGetRomAddress(s32 filenum);
u32 fileGetRomSizeByTableAddress(u32 *filetableaddr);
s32 fileGetRomSizeByFileNum(s32 filenum);
u32 func0f166ea8(void);
void func0f166eb4(void *ptr, u32 len, void *table, struct fileinfo *info);
void func0f166f74(void);
void func0f166ff0(u16 filenum, void *memaddr, s32 offset, u32 len);
u32 func0f167054(u32 filenum);
void *func0f1670fc(u32 filenum, u32 arg1);
void *func0f167200(s32 file_id, s32 arg1, u8 *arg2, s32 arg3);
u32 fileGetSize(s32 filenum);
u32 fileGetUnk04(s32 filenum);
void func0f1672a8(s32 filenum, void *ptr, u32 size, bool resizing);
void func0f1672f0(u8 arg0);
void func0f167330(void);

#endif
