#ifndef _IN_GAME_FMB_H
#define _IN_GAME_FMB_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void fmb_reset(void);
MenuItemHandlerResult fmb_handle_drop_out(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult fmd_handle_abort_game(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult fmb_handle_advanced_setup(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult fmb_handle_accept_challenge(s32 operation, struct menuitem *item, union handlerdata *data);
MenuDialogHandlerResult fmb_handle_main_menu(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);

#endif
