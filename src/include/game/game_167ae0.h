#ifndef _IN_GAME_GAME_167AE0_H
#define _IN_GAME_GAME_167AE0_H
#include <ultra64.h>
#include "types.h"

u32 getVar80084040(void);
void func0f167af8(void);
void boostAndSlayerSfxStopAll(void);
s32 boostAndSlayerSfxGetIndex(u32 arg0);
void boostAndSlayerSfxSetEnabled(u32 arg0, bool arg1);
void boostAndSlayerSfxUpdate(void);
void func0f167e7c(s32 stagenum);
Gfx *fadeRender(Gfx *gdl);
void fadeCancel(void);
u32 func0f1688fc(void);
u32 func0f168b4c(void);
u32 func0f168f24(void);
u32 func0f1691c0(void);
u32 func0f169374(void);
void func0f16b0c8(void);
s32 sub54321(s32 value);
void updateCutsceneTime(void);
s32 getEffectiveSlowMotion(void);
void func0f16b96c(void);
void currentPlayerRecordDistanceMoved(void);
void func0f16cce4(void);
void soloSetPaused(bool paused);
void fadeConfigure(u32 color, s16 num_frames);
bool fadeIsActive(void);
void stageLoad(void);
bool soloIsPaused(void);
s32 getDifficulty(void);
void setDifficulty(s32 difficulty);
void mpSetTimeLimit(u32 limit);
void mpSetScoreLimit(u32 limit);
void mpSetTeamScoreLimit(u32 limit);
f32 getUptime(void);
u32 mpGetTimeElapsed(void);

#endif
