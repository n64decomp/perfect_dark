#ifndef IN_GAME_DEBUG_H
#define IN_GAME_DEBUG_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 dprint();
s32 debug0f11ed70(void);
bool debugEnableBgRendering(void);
bool debugEnablePropRendering(void);
bool debug0f11edb0(void);
bool debug0f11edb8(void);
bool debugIsRoomStateDebugEnabled(void);
s32 debugIsTurboModeEnabled(void);
bool debugForceAllObjectivesComplete(void);
bool debug0f11ee28(void);
bool debug0f11ee40(void);
u32 debugGetSlowMotion(void);
bool debug0f11ee88(void);
bool debug0f11ee90(void);
bool debug0f11eea8(void);
bool debugDangerousProps(void);
s32 debugGetMotionBlur(void);
bool debugEnableFootsteps(void);
bool debugAllowEndLevel(void);
bool debug0f11ef78(void);
bool debug0f11ef80(void);

#endif
