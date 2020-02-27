#ifndef IN_GAME_GAME_113220_H
#define IN_GAME_GAME_113220_H
#include <ultra64.h>
#include "types.h"

u32 func0f113220(void);
u32 func0f11323c(void);
void currentPlayerUpdateHeadPos(struct coord *vel);
void currentPlayerUpdateHeadRot(struct coord *lookvel, struct coord *upvel);
void currentPlayerSetHeadAmp(f32 headamp);
u32 func0f1138a4(void);
u32 func0f113f10(void);
u32 func0f1140bc(void);
u32 func0f11412c(void);
u32 func0f11416c(void);

#endif
