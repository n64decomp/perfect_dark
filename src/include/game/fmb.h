#ifndef _IN_GAME_FMB_H
#define _IN_GAME_FMB_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void fmbReset(void);
MenuItemHandlerResult fmbHandleDropOut(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult fmdHandleAbortGame(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult fmbHandleAdvancedSetup(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult fmbHandleAcceptChallenge(s32 operation, struct menuitem *item, union handlerdata *data);
MenuDialogHandlerResult fmbHandleMainMenu(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);

#endif
