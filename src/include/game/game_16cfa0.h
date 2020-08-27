#ifndef IN_GAME_GAME_16CFA0_H
#define IN_GAME_GAME_16CFA0_H
#include <ultra64.h>
#include "types.h"

u16 func0f16cfa0(void);
void func0f16cfe8(u16 volume);
bool func0f16d0a8(s32 arg0, s32 arg1);
u32 func0f16d124(void);
void func0f16d1bc(u32 arg0, u32 tracknum, f32 arg2, u16 volume);
void func0f16d240(s32 arg0);
void func0f16d2ac(s32 arg0, f32 arg1, s32 arg2);
void func0f16d324(void);
void func0f16d3d0(void);
void func0f16d430(void);
void func0f16d44c(void);
void func0f16d4b8(f32 arg0);
void func0f16d548(f32 arg0);
u32 func0f16d6c0(void);
void func0f16d89c(f32 arg0);
void audioSetBgMusic(s32 tracknum);
void func0f16d9a8(s32 stagenum);
void func0f16d9f0(s32 stagenum);
u32 func0f16d9fc(void);
void func0f16da2c(void);
void func0f16daa4(void);
void audioSetBgMusicForMenu(void);
void func0f16db3c(void);
void audioPlaySoloDeathTrack(void);
void audioPlayMpDeathTrack(f32 arg0);
void func0f16dd14(void);
void func0f16ddb0(void);
void audioPlayTrack(s32 tracknum);
void audioRestartTrack(void);
void func0f16deb8(s32 tracknum);
void audioSetTrack(s32 tracknum);
void audioRestartDefaultTrack(void);
void audioSetAuxTrack(s32 tracknum);
void audioRestartAuxTrack(void);
void audioPlayXTrack(s32 index, u32 arg1, u32 duration);
void audioStopTrack(s32 index);
u32 func0f16e138(void);

#endif
