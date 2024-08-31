#ifndef IN_GAME_FILEMGR_H
#define IN_GAME_FILEMGR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern struct menudialogdef g_ChooseLanguageMenuDialog;

char *filemgr_menu_text_device_name(struct menuitem *item);
void filemgr_get_select_name(char *buffer, struct filelistfile *file, u32 filetype);
void filemgr_set_device1_by_serial(s32 deviceserial);
void filemgr_push_error_dialog(u16 errno);
s32 filemgr_get_device_name_or_start_index(s32 listnum, s32 operation, s32 optionindex);
bool filemgr_save_or_load(struct fileguid *guid, s32 fileop, u32 playernum);
void filemgr_push_select_location_dialog(s32 arg0, u32 filetype);
bool filemgr_consider_pushing_file_select_dialog(void);
void bootmenu_reset(void);
MenuItemHandlerResult filemgr_choose_agent_list_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuDialogHandlerResult filemgr_main_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuItemHandlerResult filemgr_open_copy_file_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_open_delete_file_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);

extern const char var7f1b3214[];
extern const char var7f1b3218[];
extern const char var7f1b321c[];
extern const char var7f1b3220[];

#endif
