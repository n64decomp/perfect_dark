#ifndef _IN_GAME_CORE_H
#define _IN_GAME_CORE_H
#include <ultra64.h>
#include "types.h"

u32 getVar80084040(void);
void func0f167af8(void);
void coreStopAllMiscSfx(void);
s32 coreGetMiscSfxIndex(u32 arg0);
void coreSetMiscSfxState(u32 type, bool play);
void coreUpdateMiscSfx(void);
void coreLoadStage(s32 stagenum);
Gfx *coreRenderFade(Gfx *gdl);
void coreCancelFade(void);
bool coreCheckCmpFollowThreat(struct threat *threat, s32 index);
void coreFindThreatsForProp(struct prop *prop, bool inchild, struct coord *playerpos, s32 *activeslots, f32 *param_5);
void func0f168f24(struct prop *prop, bool inchild, struct coord *playerpos, s32 *activeslots, f32 *distances);
void coreFindThreats(void);
Gfx *coreRender(Gfx *gdl);
void coreUpdateSoloHandicaps(void);
s32 sub54321(s32 value);
void coreUpdateCutsceneTime(void);
s32 coreGetSlowMotionType(void);
void coreTick(void);
void coreRecordDistanceMoved(void);
void coreCheckPauseStateChanged(void);
void coreSetPaused(bool paused);
void coreConfigureFade(u32 color, s16 num_frames);
bool coreIsFadeActive(void);
void coreUnloadStage(void);
bool coreIsPaused(void);
s32 coreGetDifficulty(void);
void coreSetDifficulty(s32 difficulty);
void coreSetMpTimeLimit60(u32 limit);
void coreSetMpScoreLimit(u32 limit);
void coreSetMpTeamScoreLimit(u32 limit);
f32 coreGetStageTimeInSeconds(void);
u32 coreGetStageTime60(void);

#endif
