#ifndef _IN_GAME_LV_H
#define _IN_GAME_LV_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern bool g_LvIsPaused;
extern s32 g_StageTimeElapsed60;
extern s32 g_Difficulty;

void lvInit(void);
void lvReset(s32 stagenum);
Gfx *lvRender(Gfx *gdl);
s32 lvGetSlowMotionType(void);
void lvTick(void);
void lvTickPlayer(void);
void lvSetPaused(bool paused);
void lvConfigureFade(u32 color, s16 num_frames);
bool lvIsFadeActive(void);
void lvStop(void);
bool lvIsPaused(void);
void lvSetDifficulty(s32 difficulty);
void lvSetMpTimeLimit60(u32 limit);
void lvSetMpScoreLimit(u32 limit);
void lvSetMpTeamScoreLimit(u32 limit);
f32 lvGetStageTimeInSeconds(void);
s32 lvGetStageTime60(void);

#endif
