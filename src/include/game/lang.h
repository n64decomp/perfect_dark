#ifndef IN_GAME_LANG_H
#define IN_GAME_LANG_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 langGetLangBankIndexFromStagenum(s32 stagenum);
u32 func0f16e3fc(void);
s32 langGetFileNumOffset(void);
s32 langGetFileId(s32 bank);
void langSetBankSimple(s32 bank);
void langSetBank(s32 bank, u8 *arg1, s32 arg2);
void langClearBank(s32 bank);
char *langGet(s32 textid);
void func0f16f75c(u32 arg0);

#endif
