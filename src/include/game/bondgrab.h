#ifndef IN_GAME_BONDGRAB_H
#define IN_GAME_BONDGRAB_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bgrabInit(void);
void bgrabExit(void);
void bgrabHandleActivate(void);
void bgrabApplyMoveData(struct movedata *data);
void bgrabUpdateSpeedTheta(void);
void bgrabTick(void);

#endif
