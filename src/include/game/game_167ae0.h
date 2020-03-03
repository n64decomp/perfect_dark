#ifndef _IN_GAME_GAME_167AE0_H
#define _IN_GAME_GAME_167AE0_H
#include <ultra64.h>
#include "types.h"

u32 func0f167ae0(void);
u32 func0f167af8(void);
u32 func0f167b10(void);
u32 func0f167b48(void);
u32 func0f167b84(void);
u32 func0f167c88(void);
u32 func0f167e7c(void);
u32 func0f1685d8(void);
u32 func0f1688c8(void);
u32 func0f1688fc(void);
u32 func0f168b4c(void);
u32 func0f168f24(void);
u32 func0f1691c0(void);
u32 func0f169374(void);
u32 func0f16b0c8(void);
u32 func0f16b800(u32 arg0);
u32 func0f16b810(void);
u32 getEffectiveSlowMotion(void);
u32 func0f16b96c(void);
u32 func0f16cb04(void);
void func0f16cce4(void);
u32 func0f16cd40(void);
void fadeConfigure(u32 color, s16 num_frames);
bool fadeIsActive(void);
void stageLoad(void);
u32 getVar80084014(void);
s32 getDifficulty(void);
void setDifficulty(s32 difficulty);
void setVar80084028(u32 arg0);
void setVar8008402c(u32 arg0);
void setVar80084030(u32 arg0);
f32 getUptime(void);
u32 mpGetMatchTime(void);

#endif
