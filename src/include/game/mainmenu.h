#ifndef IN_GAME_MAINMENU_H
#define IN_GAME_MAINMENU_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern u16 g_ControlStyleOptions[];

extern struct menudialogdef g_AcceptMissionMenuDialog;
extern struct menudialogdef g_PreAndPostMissionBriefingMenuDialog;
extern struct menudialogdef g_RetryMissionMenuDialog;
extern struct menudialogdef g_NextMissionMenuDialog;

char *solo_menu_text_difficulty(struct menuitem *item);
bool is_stage_difficulty_unlocked(s32 stageindex, s32 difficulty);
void mainmenu_prepare_weapon_menumodel(s32 weaponnum);
bool solo_choose_pause_dialog(void);
MenuDialogHandlerResult menudialog_accept_mission(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult menudialog_mainmenu_options(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult solo_menu_dialog_pause_status(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuItemHandlerResult menuhandler_accept_mission(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_inventory_list(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_music_volume(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_screen_ratio(s32 operation, struct menuitem *item, union handlerdata *data);
#if PAL
MenuItemHandlerResult menuhandler_language(s32 operation, struct menuitem *item, union handlerdata *data);
#endif
MenuItemHandlerResult menuhandler_screen_split(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_sfx_volume(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult menuhandler_sound_mode(s32 operation, struct menuitem *item, union handlerdata *data);

#endif
