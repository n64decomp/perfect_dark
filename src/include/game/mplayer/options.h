#ifndef _IN_GAME_MPLAYER_OPTIONS_H
#define _IN_GAME_MPLAYER_OPTIONS_H
#include <ultra64.h>
#include "types.h"

s32 menuhandlerMpOpenOptions(s32 operation, struct menuitem *item, union handlerdata *data);
void scenarioCallback40(s32 *arg0);
void scenarioCallback44(s32 *arg0);
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
