#ifndef IN_GAME_BONDBIKE_H
#define IN_GAME_BONDBIKE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void bbikeInit(void);
void bbikeExit(void);
void bbikeHandleActivate(void);
void bbikeApplyMoveData(struct movedata *data);
void bbikeTick(void);

#endif
