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
bool threatCheckCmpFollow(struct threat *threat, s32 index);
void propFindThreats(struct prop *prop, bool inchild, struct coord *playerpos, s32 *activeslots, f32 *param_5);
void func0f168f24(struct prop *prop, bool inchild, struct coord *playerpos, s32 *activeslots, f32 *distances);
void func0f1691c0(void);
Gfx *renderFrame(Gfx *gdl);
void updateSoloHandicaps(void);
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
