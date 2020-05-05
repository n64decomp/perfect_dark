#ifndef IN_GAME_GAME_113220_H
#define IN_GAME_GAME_113220_H
#include <ultra64.h>
#include "types.h"

void currentPlayerFlipAnimation(void);
void currentPlayerUpdateIdleHeadRoll(void);
void currentPlayerUpdateHeadPos(struct coord *vel);
void currentPlayerUpdateHeadRot(struct coord *lookvel, struct coord *upvel);
void currentPlayerSetHeadAmp(f32 headamp);
void func0f1138a4(f32 arg0, f32 arg1);
void func0f113f10(f32 arg0);
void func0f1140bc(s16 arg0, u32 arg1, f32 arg2, f32 arg3);
void func0f11412c(f32 speed);
f32 func0f11416c(void);

#endif
