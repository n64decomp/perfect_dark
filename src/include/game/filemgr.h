#ifndef IN_GAME_FILEMGR_H
#define IN_GAME_FILEMGR_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern struct menudialogdef g_ChooseLanguageMenuDialog;

char *filemgr_get_device_name(s32 index);
char *filemgr_menu_text_device_name(struct menuitem *item);
void filemgr_get_select_name(char *buffer, struct filelistfile *file, u32 filetype);
char *filemgr_menu_text_delete_file_name(struct menuitem *item);
void filemgr_set_device1_by_serial(s32 deviceserial);
void filemgr_set_device1_by_file(struct filelistfile *file);
void filemgr_set_file_to_delete(struct filelistfile *file, s32 filetype);
char *filemgr_menu_text_fail_reason(struct menuitem *item);
char *filemgr_menu_text_device_name_for_error(struct menuitem *item);
void filemgr_push_error_dialog(u16 errno);
s32 filemgr_get_device_name_or_start_index(s32 listnum, s32 operation, s32 optionindex);
char *filemgr_menu_text_error_title(struct menuitem *item);
char *filemgr_menu_text_file_type(struct menuitem *item);
void func0f10898c(void);
void filemgr_handle_success(void);
void filemgr_erase_corrupt_file(void);
char *filemgr_menu_text_insert_original_pak(struct menuitem *item);
void filemgr_retry_save(s32 arg0);
bool filemgr_attempt_operation(s32 device, bool closeonsuccess);
bool filemgr_save_or_load(struct fileguid *guid, s32 fileop, u32 playernum);
void filemgr_delete_current_file(void);
void func0f1097d0(s32 device);
void filemgr_save_game_to_device(s32 device);
void filemgr_get_file_name(char *dst, struct filelistfile *file);
void filemgr_get_rename_name(char *buffer);
void filemgr_set_rename_name(char *name);
bool filemgr_is_name_available(s32 arg0);
void filemgr_save_to_device(void);
char *filemgr_menu_text_device_name_containing_duplicate_file(struct menuitem *item);
char *filemgr_menu_text_duplicate_file_name(struct menuitem *item);
char *filemgr_menu_text_location_name2(struct menuitem *item);
char *filemgr_menu_text_save_location_spaces(struct menuitem *item);
void filemgr_push_select_location_dialog(s32 arg0, u32 filetype);
char *filemgr_menu_text_file_in_use_description(struct menuitem *item);
Gfx *filemgr_render_perfect_head_thumbnail(Gfx *gdl, struct menuitemrenderdata *renderdata, s32 filenum, s32 deviceserial);
bool filemgr_is_file_in_use(struct filelistfile *file);
MenuItemHandlerResult filemgr_file_to_copy_or_delete_list_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data, bool isdelete);
void filemgr_push_delete_file_dialog(s32 listnum);
char *pak_menu_text_pages_free(struct menuitem *item);
char *pak_menu_text_pages_used(struct menuitem *item);
char *pak_menu_text_status_message(struct menuitem *item);
char *pak_menu_text_editing_pak_name(struct menuitem *item);
bool filemgr_consider_pushing_file_select_dialog(void);
void bootmenu_reset(void);
MenuItemHandlerResult filemgr_choose_agent_list_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult pak_game_note_list_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_file_to_copy_list_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_file_to_delete_list_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuDialogHandlerResult filemgr_insert_original_pak_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult filemgr_copy_or_delete_list_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult pak_game_notes_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult pak_choose_pak_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuDialogHandlerResult filemgr_main_menu_dialog(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data);
MenuItemHandlerResult filemgr_device_name_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_file_name_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_device_name_for_error_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_retry_save_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_cancel_save2_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_acknowledge_file_lost_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_reinserted_ok_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_reinserted_cancel_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_duplicate_rename_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_duplicate_cancel_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_cancel_save_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_delete_files_for_save_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_confirm_delete_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult pak_delete_game_note_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult pak_selection_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_agent_name_keyboard_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_open_copy_file_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_open_delete_file_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_confirm_rename_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_save_elsewhere_yes_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);
MenuItemHandlerResult filemgr_select_location_menu_handler(s32 operation, struct menuitem *item, union handlerdata *data);

extern const char var7f1b3214[];
extern const char var7f1b3218[];
extern const char var7f1b321c[];
extern const char var7f1b3220[];

#endif
