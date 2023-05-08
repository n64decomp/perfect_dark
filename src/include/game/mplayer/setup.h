#ifndef _IN_GAME_MPLAYER_SETUP_H
#define _IN_GAME_MPLAYER_SETUP_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

char *mpGetCurrentPlayerName(struct menuitem *item);
s16 mpChooseRandomStage(void);
s32 mpBotDifficultyMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
char *mpMenuTitleEditSimulant(struct menudialogdef *dialogdef);
char *func0f17e318(struct menudialogdef *dialogdef);
s32 menudialog0017e3fc(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
s32 mpChallengesListMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
char *mpMenuTextChallengeName(struct menuitem *item);
s32 mpCombatChallengesMenuDialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
char *mpMenuTextSavePlayerOrCopy(struct menuitem *item);
char *mpMenuTextArenaName(struct menuitem *item);
void mpConfigureQuickTeamSimulants(void);
void func0f17f428(void);
void func0f17fcb0(s32 silent);
char *mpMenuTextScenarioShortName(struct menuitem *item);
char *mpMenuTextScenarioName(struct menuitem *item);
Gfx *scenarioRenderHud(Gfx *gdl);
void scenarioCalculatePlayerScore(struct mpchrconfig *mpchr, s32 chrnum, s32 *arg2, s32 *arg3);
bool scenarioHighlightProp(struct prop *prop, s32 *colour);
void scenarioReset(void);
s32 scenarioPickUpBriefcase(struct chrdata *chr, struct prop *prop);
void scenarioHandleDroppedToken(struct chrdata *chr, struct prop *prop);
s32 scenarioPickUpUplink(struct chrdata *chr, struct prop *prop);
void scenarioHandleActivatedProp(struct chrdata *chr, struct prop *prop);
s32 mpGetNumStages(void);
s32 menuhandlerMpCheckboxOption(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menudialogMpSimulant(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
s32 menuhandlerMpDeleteSimulant(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerMpChangeSimulantType(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerMpLock(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerMpSavePlayer(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerMpSaveSettings(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menudialogMpGameSetup(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
s32 menudialogMpQuickGo(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);

#endif
