#ifndef IN_GAME_DEBUG_H
#define IN_GAME_DEBUG_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void debug0f119a80nb(void);
u32 dprint();
s32 debug0f11ed70(void);
bool debugIsBgRenderingEnabled(void);
bool debugIsPropRenderingEnabled(void);
bool debug0f11990cnb(void);
bool debugIsManPosEnabled(void);
bool debug0f11edb0(void);
bool debugIsObjDeformDebugEnabled(void);
bool debugIsRoomStateDebugEnabled(void);
s32 debugIsTurboModeEnabled(void);
bool debugForceAllObjectivesComplete(void);
bool debugIsZBufferDisabled(void);
bool debug0f11ee40(void);
bool debug0f1199f0nb(void);
bool debug0f119a14nb(void);
s32 debugGetSlowMotion(void);
s32 debugGetTilesDebugMode(void);
s32 debugGetPadsDebugMode(void);
bool debug0f11eea8(void);
bool debugDangerousProps(void);
s32 debugGetMotionBlur(void);
bool debugIsFootstepsEnabled(void);
bool debugIsAllChallengesEnabled(void);
bool debugIsAllBuddiesEnabled(void);
bool debugIsSetCompleteEnabled(void);
bool debugIsAllTrainingEnabled(void);
bool debugAllowEndLevel(void);
bool debugIsChrStatsEnabled(void);
bool debug0f11ef80(void);
bool debugIsMemInfoEnabled(void);

s32 dmenuGetSelectedOption(void);
void dmenuSetSelectedOption(s32 option);
void dmenuSetMenu(char **labels, s32 (*positions)[2], s32 *offsets);
void dmenuNavigateRight(void);
void dmenuNavigateLeft(void);
void dmenuNavigateUp(void);
void dmenuNavigateDown(void);
Gfx *dmenuRender(Gfx *gdl);

void debugUpdateMenu(void);
bool debugProcessInput(s8 stickx, s8 sticky, u16 buttons, u16 buttonsthisframe);
bool debugIsLineModeEnabled(void);

extern s32 var800786f4nb;
extern s32 g_DebugMenuPositions[][2];
extern char *g_DebugMenuLabels[];

#endif
