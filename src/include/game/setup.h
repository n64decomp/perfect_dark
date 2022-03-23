#ifndef IN_GAME_SETUP_H
#define IN_GAME_SETUP_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void setupPreparePads(void);
void setupLoadWaypoints(void);
void setupPrepareCover(void);

void propsReset(void);
void setupCreateLiftDoor(struct linkliftdoorobj *link);
void setupCreatePadlockedDoor(struct padlockeddoorobj *link);
void setupCreateSafeItem(struct safeitemobj *link);
void setupCreateConditionalScenery(struct linksceneryobj *link);
void setupCreateBlockedPath(struct blockedpathobj *link);
void setupReset0f00cc8c(void);
void setupResetProxyMines(void);
s32 setupCountCommandType(u32 type);
void setupCreateObject(struct defaultobj *obj, s32 cmdindex);
void setupPlaceWeapon(struct weaponobj *weapon, s32 cmdindex);
void setupCreateHat(struct hatobj *hat, s32 cmdindex);
void setupCreateKey(struct keyobj *key, s32 cmdindex);
void setupCreateMine(struct mineobj *mine, s32 cmdindex);
void setupCreateCctv(struct cctvobj *camera, s32 cmdindex);
void setupCreateAutogun(struct autogunobj *autogun, s32 cmdindex);
void setupCreateHangingMonitors(struct hangingmonitorsobj *monitors, s32 cmdindex);
void setupCreateSingleMonitor(struct singlemonitorobj *monitor, s32 cmdindex);
void setupCreateMultiMonitor(struct multimonitorobj *monitor, s32 cmdindex);
s32 setupGetPortalByPad(s32 padnum);
s32 setupGetPortalByDoorPad(s32 padnum);
void setupCreateDoor(struct doorobj *door, s32 cmdindex);
void setupCreateHov(struct defaultobj *obj, struct hov *hov);
void setupLoadBriefing(s32 stagenum, u8 *buffer, s32 bufferlen, struct briefing *briefing);
void setupLoadFiles(s32 stagenum);
void setupCreateProps(s32 stagenum);

#endif
