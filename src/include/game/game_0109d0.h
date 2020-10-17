#ifndef IN_GAME_GAME_0109D0_H
#define IN_GAME_GAME_0109D0_H
#include <ultra64.h>
#include "types.h"

void func0f0109d0(void);
void tagInsert(struct tag *tag);
void briefingInsert(struct briefingobj *obj);
void func0f010a98(struct defaultobj *obj);
void objectiveAddRoomEnteredCriteria(struct criteria_roomentered *criteria);
void objectiveAddMultiroomEnteredCriteria(struct criteria_multiroomentered *criteria);
void objectiveAddHolographCriteria(struct criteria_holograph *criteria);

#endif
