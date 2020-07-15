#ifndef _IN_GAME_GAME_166E40_H
#define _IN_GAME_GAME_166E40_H
#include <ultra64.h>
#include "types.h"

u32 func0f166e40(void);
u32 fileGetRomSizeByTableAddress(u32 *filetableaddr);
u32 fileGetRomSizeByFileNum(s32 filenum);
u32 func0f166ea8(void);
void func0f166eb4(void *ptr, u32 len, void *table, struct fileinfo *info);
u32 func0f166f74(void);
u32 func0f166ff0(void);
u32 func0f167054(u32 filenum);
void *func0f1670fc(u32 filenum, u32 arg1);
void *func0f167200(s32 file_id, s32 arg1, u8 *arg2, s32 arg3);
u32 fileGetSize(s32 filenum);
u32 fileGetUnk04(s32 filenum);
u32 func0f1672a8(void);
void func0f1672f0(s32 arg0);
void func0f167330(void);
u32 func0f167350(void);
u32 func0f16793c(void);
u32 func0f167964(void);
u32 func0f167998(void);
u32 func0f1679b0(void);
u32 func0f1679cc(void);
struct model0c *func0f1679f4(s32 arg0);
u32 func0f167a18(void);

#endif
