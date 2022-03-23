#ifndef _IN_GAME_FMB_H
#define _IN_GAME_FMB_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void fmbReset(void);
s32 fmbHandleDropOut(s32 operation, struct menuitem *item, union handlerdata *data);
s32 fmdHandleAbortGame(s32 operation, struct menuitem *item, union handlerdata *data);
s32 fmbHandleAdvancedSetup(s32 operation, struct menuitem *item, union handlerdata *data);
s32 fmbHandleAcceptChallenge(s32 operation, struct menuitem *item, union handlerdata *data);
s32 fmbHandleMainMenu(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);

#endif
