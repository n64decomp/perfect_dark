#ifndef IN_GAME_DEBUG_H
#define IN_GAME_DEBUG_H
#include <ultra64.h>
#include "types.h"

u32 dprint();
bool debug0f11ed70(void);
bool debug0f11ed78(void);
bool debug0f11ed80(void);
bool debug0f11edb0(void);
bool debug0f11edb8(void);
bool debug0f11edc0(void);
s32 debugIsTurboModeEnabled(void);
bool debugForceAllObjectivesComplete(void);
bool debug0f11ee28(void);
bool debug0f11ee40(void);
u32 debugGetSlowMotion(void);
bool debug0f11ee88(void);
bool debug0f11ee90(void);
bool debug0f11eea8(void);
bool debug0f11eeb0(void);
bool debug0f11eed8(void);
bool debug0f11eef8(void);
bool debugAllowEndLevel(void);
bool debug0f11ef78(void);
bool debug0f11ef80(void);

#endif
