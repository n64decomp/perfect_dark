#ifndef _IN_GAME_GAME_17F9300_H
#define _IN_GAME_GAME_17F9300_H
#include <ultra64.h>
#include "types.h"

bool menudialogCombatSimulator(u32 operation, struct menu_dialog *dialog, struct menustackitem *stackitem);
s32 menuhandlerMpAdvancedSetup(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandlerMpDisplayTeam(u32 operation, struct menu_item *item, s32 *value);
s32 menuhandlerMpOneHitKills(u32 operation, struct menu_item *item, s32 *value);
void scenarioHtbInit(void);
s32 scenarioHtbCallback08(void);
void scenarioHtbReset(void);
void scenarioHtbCallback10(void);
void scenarioHtbCallback14(struct chrdata *chr);
void scenarioHtbKill(struct mpchr *mpchr, s32 arg1, s32 *score, s32 *arg3);
Gfx *scenarioHtbRadar(Gfx *gdl);
bool scenarioHtbRadar2(Gfx **gdl, struct prop *prop);
bool scenarioHtbHighlight(struct prop *prop, u32 *colour);
void scenarioCtcInit(void);
s32 scenarioCtcCallback08(void);
void scenarioCtcCallback10(void);
void scenarioCtcCallback14();
void scenarioCtcKill(struct mpchr *mpchr, s32 arg1, s32 *score, s32 *arg3);
Gfx *scenarioCtcRadar(Gfx *gdl);
bool scenarioCtcRadar2(Gfx **gdl, struct prop *prop);
bool scenarioCtcCallback2c(f32 arg0, struct coord *pos, s16 *arg2, struct prop *prop, f32 *arg4);
s32 scenarioCtcGetMaxTeams(void);
bool scenarioCtcIsRoomHighlighted(s16 room);
s32 menuhandlerMpHillTime(u32 operation, struct menu_item *item, struct numandtext *value);
void scenarioKohCallback40(s32 *arg0);
void scenarioKohCallback44(s32 *arg0);
void scenarioKohInit(void);
void scenarioKohReset(void);
void scenarioKohKill(struct mpchr *mpchr, s32 arg1, s32 *score, s32 *arg3);
Gfx *scenarioKohRadar(Gfx *gdl);
bool scenarioKohIsRoomHighlighted(s16 arg0);
void scenarioHtmInit(void);
s32 scenarioHtmCallback08(void);
void scenarioHtmCallback10(void);
void scenarioHtmKill(struct mpchr *mpchr, s32 arg1, s32 *score, s32 *arg3);
bool scenarioHtmRadar2(Gfx **gdl, struct prop *prop);
bool scenarioHtmHighlight(struct prop *prop, u32 *colour);
void scenarioPacInit(void);
void scenarioPacReset(void);
void scenarioPacKill(struct mpchr *mpchr, s32 arg1, s32 *score, s32 *arg3);
Gfx *scenarioPacRadar(Gfx *gdl);
s32 menuhandlerMpOpenOptions(u32 operation, struct menu_item *item, s32 *value);
void scenarioCallback40(s32 *arg0);
void scenarioCallback44(s32 *arg0);
void scenarioInit(void);
s32 scenarioCallback08(void);
void scenarioReset(void);
void scenarioCallback10(void);
void scenarioCallback14(struct chrdata *chr);
Gfx *scenarioRadar(Gfx *gdl);
bool scenarioRadar2(Gfx **gdl, struct prop *prop);
f32 scenarioCallback2c(f32 arg0, struct coord *pos, s16 *arg2, struct prop *prop);
s32 scenarioGetMaxTeams(void);
void scenarioCallback38(s16 arg0, s32 *arg1, s32 *arg2, s32 *arg3);

#endif
