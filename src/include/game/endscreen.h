#ifndef IN_GAME_ENDSCREEN_H
#define IN_GAME_ENDSCREEN_H
#include <ultra64.h>
#include "types.h"

void menudialogRetryMission(u32 operation, struct menudialog *dialog, struct menuthing **thingptr);
s32 menudialogSolo2PEndscreenCompleted(u32, u32, u32 *);
s32 menudialogSolo2PEndscreenFailed(u32, u32, u32 *);
s32 menuhandlerDeclineMission(u32 operation, struct menuitem *item, s32 *value);
s32 menuhandlerEndscreenCheats(u32 operation, struct menuitem *item, u32 *values);
s32 menuhandlerContinueMission(u32 operation, struct menuitem *item, s32 *value);
s32 menuhandlerReplayLastLevel(u32 operation, struct menuitem *item, s32 *value);
s32 menuhandlerReplayPreviousMission(u32 operation, struct menuitem *item, s32 *value);
char *menuDialogTitleRetryStageName(struct menudialog *dialog);
char *menuDialogTitleNextMissionStageName(struct menudialog *dialog);
char *soloMenuTextNumKills(struct menuitem *item);
char *soloMenuTextNumShots(struct menuitem *item);
char *soloMenuTextNumHeadShots(struct menuitem *item);
char *soloMenuTextNumBodyShots(struct menuitem *item);
char *soloMenuTextNumLimbShots(struct menuitem *item);
char *soloMenuTextNumOtherShots(struct menuitem *item);
char *soloMenuTextAccuracy(struct menuitem *item);
char *soloMenuTextMissionStatus(struct menuitem *item);
char *soloMenuTextAgentStatus(struct menuitem *item);
char *menuTitleStageCompleted(struct menuitem *item);
char *menuTextCurrentStageName3(struct menuitem *item);
char *menuTitleStageFailed(struct menuitem *item);
char *soloMenuTextMissionTime(struct menuitem *item);
struct menudialog *func0f10d730(void);
void func0f10d770(void);
void endscreenHandleContinue(s32 context);
char *soloMenuTextTimedCheatName(struct menuitem *item);
char *soloMenuTextCompletionCheatName(struct menuitem *item);
char *soloMenuTextTargetTime(struct menuitem *item);
void endscreenSetCoopCompleted(void);
void endscreenPrepare(void);
void soloPushCoopModeEndscreen(void);
void soloPushSoloModeEndscreen(void);
void soloPushAntiModeEndscreen(void);

#endif
