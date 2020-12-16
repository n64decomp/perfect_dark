#ifndef IN_GAME_BONDHEAD_H
#define IN_GAME_BONDHEAD_H
#include <ultra64.h>
#include "types.h"

void currentPlayerFlipAnimation(void);
void currentPlayerUpdateIdleHeadRoll(void);
void currentPlayerUpdateHeadPos(struct coord *vel);
void currentPlayerUpdateHeadRot(struct coord *lookvel, struct coord *upvel);
void currentPlayerSetHeadDamp(f32 headdamp);
void currentPlayerUpdateHead(f32 arg0, f32 arg1);
void currentPlayerAdjustHeadAnimation(f32 speed);
void currentPlayerStartDeathAnimation(s16 animnum, u32 flip, f32 fstarttime, f32 speed);
void currentPlayerSetAnimSpeed(f32 speed);
f32 func0f11416c(void);

#endif
