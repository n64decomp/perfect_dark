#ifndef _IN_GAME_MPLAYER_SCENARIOS_H
#define _IN_GAME_MPLAYER_SCENARIOS_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern struct menudialog g_MpScenarioMenuDialog;
extern struct menudialog g_MpQuickTeamScenarioMenuDialog;

void scenarioHtbInit(void);
s32 scenarioHtbCallback08(void);
void scenarioHtbReset(void);
void scenarioHtbTick(void);
void scenarioHtbCallback14(struct chrdata *chr);
void scenarioHtbKill(struct mpchr *mpchr, s32 mpchrnum, s32 *score, s32 *arg3);
Gfx *scenarioHtbRadar(Gfx *gdl);
bool scenarioHtbRadar2(Gfx **gdl, struct prop *prop);
bool scenarioHtbHighlight(struct prop *prop, u32 *colour);
void scenarioCtcInit(void);
s32 scenarioCtcCallback08(void);
void scenarioCtcTick(void);
void scenarioCtcCallback14(struct chrdata *chr);
void scenarioCtcKill(struct mpchr *mpchr, s32 mpchrnum, s32 *score, s32 *arg3);
Gfx *scenarioCtcRadar(Gfx *gdl);
bool scenarioCtcRadar2(Gfx **gdl, struct prop *prop);
bool scenarioCtcChooseSpawnLocation(f32 arg0, struct coord *pos, s16 *rooms, struct prop *prop, f32 *arg4);
s32 scenarioCtcGetMaxTeams(void);
bool scenarioCtcIsRoomHighlighted(s16 room);
s32 menuhandlerMpHillTime(s32 operation, struct menuitem *item, union handlerdata *data);
void scenarioKohReadSave(struct savebuffer *buffer);
void scenarioKohWriteSave(struct savebuffer *buffer);
void scenarioKohInit(void);
void scenarioKohReset(void);
void scenarioKohKill(struct mpchr *mpchr, s32 mpchrnum, s32 *score, s32 *arg3);
Gfx *scenarioKohRadar(Gfx *gdl);
bool scenarioKohIsRoomHighlighted(s16 arg0);
void scenarioHtmInit(void);
s32 scenarioHtmCallback08(void);
void scenarioHtmTick(void);
void scenarioHtmKill(struct mpchr *mpchr, s32 mpchrnum, s32 *score, s32 *arg3);
bool scenarioHtmRadar2(Gfx **gdl, struct prop *prop);
bool scenarioHtmHighlight(struct prop *prop, u32 *colour);
void scenarioPacInit(void);
void scenarioPacReset(void);
void scenarioPacKill(struct mpchr *mpchr, s32 mpchrnum, s32 *score, s32 *arg3);
Gfx *scenarioPacRadar(Gfx *gdl);
s32 menuhandlerMpOpenOptions(s32 operation, struct menuitem *item, union handlerdata *data);
void scenarioReadSave(struct savebuffer *buffer);
void scenarioWriteSave(struct savebuffer *buffer);
void scenarioInit(void);
s32 scenarioCallback08(void);
void scenarioReset(void);
void scenarioTick(void);
void scenarioCallback14(struct chrdata *chr);
Gfx *scenarioRadar(Gfx *gdl);
bool scenarioRadar2(Gfx **gdl, struct prop *prop);
f32 scenarioChooseSpawnLocation(f32 arg0, struct coord *pos, s16 *rooms, struct prop *prop);
s32 scenarioGetMaxTeams(void);
void scenarioCallback38(s16 arg0, s32 *arg1, s32 *arg2, s32 *arg3);

#endif
