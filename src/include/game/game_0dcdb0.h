#ifndef IN_GAME_GAME_0DCDB0_H
#define IN_GAME_GAME_0DCDB0_H
#include <ultra64.h>
#include "types.h"

u32 func0f0dcdb0(void);
u32 func0f0dcdbc(void);
u32 func0f0dcef4(void);
u32 func0f0dd2ac(void);
u32 func0f0dd848(void);
u32 func0f0ddb1c(void);
void func0f0ddd44(s32 value);
void func0f0ddda0(void);
void hudmsgRemoveAll(void);
s32 func0f0ddeac(s32 param_1);
void hudmsgCreateViaPreset(char *text, s32 confignum);
void func0f0ddfa4(char *text, s32 confignum, s32 arg2);
void hudmsgCreateViaPresetWithColour(char *text, s32 confignum, u8 colour);
void hudmsgCreateViaStruct(char *text, s32 confignum, struct hudmessageconfig *config, s32 arg3);
u32 func0f0de160(void);
u32 func0f0de7fc(void);
u32 hudmsgCreate(char *text, s32 confignum, u8 conf00, u8 conf01, u8 conf02,
		void *conf04, void *conf08, u32 colour, u32 conf10, u8 alignh, s16 conf16,
		u8 alignv, s16 conf18, s32 arg14, s32 arg15);
void func0f0df364(void);
void currentPlayerUnsetFlag(u32 flag);
void currentPlayerSetFlag(u32 flag);
void hudmsgRemoveByPlayer(s32 playernum);
u32 func0f0dfad0(void);
void hudmsgsReset(void);

#endif
