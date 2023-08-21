#ifndef IN_GAME_ENDSCREEN_H
#define IN_GAME_ENDSCREEN_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

MenuDialogHandlerResult endscreenHandleRetryMission(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult endscreenHandle2PCompleted(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult endscreenHandle2PFailed(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuItemHandlerResult endscreenHandleDeclineMission(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult endscreenHandleCheatInfo(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult endscreenHandleContinueMission(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult endscreenHandleReplayLastLevel(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult endscreenHandleReplayPreviousMission(s32 operation, struct menuitem *item, union handlerdata *data);
char *endscreenMenuTitleRetryMission(struct menudialogdef *dialogdef);
char *endscreenMenuTitleNextMission(struct menudialogdef *dialogdef);
char *endscreenMenuTextNumKills(struct menuitem *item);
char *endscreenMenuTextNumShots(struct menuitem *item);
char *endscreenMenuTextNumHeadShots(struct menuitem *item);
char *endscreenMenuTextNumBodyShots(struct menuitem *item);
char *endscreenMenuTextNumLimbShots(struct menuitem *item);
char *endscreenMenuTextNumOtherShots(struct menuitem *item);
char *endscreenMenuTextAccuracy(struct menuitem *item);
char *endscreenMenuTextMissionStatus(struct menuitem *item);
char *endscreenMenuTextAgentStatus(struct menuitem *item);
char *endscreenMenuTitleStageCompleted(struct menuitem *item);
char *endscreenMenuTextCurrentStageName3(struct menuitem *item);
char *endscreenMenuTitleStageFailed(struct menuitem *item);
char *endscreenMenuTextMissionTime(struct menuitem *item);
struct menudialogdef *endscreenAdvance(void);
void endscreenResetModels(void);
void endscreenContinue(s32 context);
char *endscreenMenuTextTimedCheatName(struct menuitem *item);
char *endscreenMenuTextCompletionCheatName(struct menuitem *item);
char *endscreenMenuTextTargetTime(struct menuitem *item);
void endscreenSetCoopCompleted(void);
void endscreenPrepare(void);
void endscreenPushCoop(void);
void endscreenPushSolo(void);
void endscreenPushAnti(void);

#endif
