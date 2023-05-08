#ifndef IN_GAME_SETUP_H
#define IN_GAME_SETUP_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void setupPreparePads(void);
void setupLoadWaypoints(void);
void setupPrepareCover(void);

void propsReset(void);
void setupCreatePadlockedDoor(struct padlockeddoorobj *link);
void setupCreateSafeItem(struct safeitemobj *link);
void setupCreateObject(struct defaultobj *obj, s32 cmdindex);
void setupPlaceWeapon(struct weaponobj *weapon, s32 cmdindex);
void setupLoadBriefing(s32 stagenum, u8 *buffer, s32 bufferlen, struct briefing *briefing);
void setupLoadFiles(s32 stagenum);
void setupCreateProps(s32 stagenum);

#endif
