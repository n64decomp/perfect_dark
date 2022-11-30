#ifndef IN_GAME_RACE_H
#define IN_GAME_RACE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void racesInit(void);

u16 raceGetAnimSumAngleAsInt(s16 animnum, s32 frame, s32 endframe);
s32 raceGetAnimSumForwardAsInt(s16 animnum, s32 startframe, s32 endframe);
s32 raceInitAnimGroup(struct attackanimconfig *configs);
void raceInitAnimGroups(struct attackanimgroup **groups);
s32 raceCountAnims(struct animtablerow *rows);
f32 race0f0005c0(s16 animnum);
void raceInitAnims(void);

#endif
