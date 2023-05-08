#ifndef IN_GAME_BONDHEAD_H
#define IN_GAME_BONDHEAD_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bheadReset(void);

void bheadFlipAnimation(void);
void bheadUpdateIdleRoll(void);
void bheadUpdate(f32 arg0, f32 arg1);
void bheadAdjustAnimation(f32 speed);
void bheadStartDeathAnimation(s16 animnum, u32 flip, f32 fstarttime, f32 speed);
void bheadSetSpeed(f32 speed);
f32 bheadGetBreathingValue(void);

#endif
