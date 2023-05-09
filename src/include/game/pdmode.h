#ifndef _IN_GAME_PDMODE_H
#define _IN_GAME_PDMODE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

f32 pdmodeGetEnemyReactionSpeed(void);
f32 pdmodeGetEnemyHealth(void);
f32 pdmodeGetEnemyDamage(void);
f32 pdmodeGetEnemyAccuracy(void);
void titleSetNextStage(s32 stagenum);

#endif
