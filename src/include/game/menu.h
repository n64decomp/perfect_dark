#ifndef IN_GAME_MENU_H
#define IN_GAME_MENU_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern const struct menucolourpalette g_MenuColours[];
extern const struct menucolourpalette g_MenuWave1Colours[];
extern const struct menucolourpalette g_MenuWave2Colours[];

void menu_tick(void);

void menu_stop(void);

void menu_play_sound(s32 menusound);
bool current_player_is_menu_open_in_solo_or_mp(void);
bool menu_has_no_background(void);
void menu_set_banner(s32 bannernum, bool allplayers);

#if VERSION >= VERSION_NTSC_1_0
#else
#endif

struct menuitemredrawinfo *menu_find_item_redraw_info(struct menuitem *item);
void menu_set_item_redraw_timer(struct menuitem *item, f32 timer60);
void menu_remove_item_redraw_info(struct menuitem *item);
char *menu_resolve_text(uintptr_t thing, void *dialogoritem);
char *menu_resolve_param2_text(struct menuitem *item);
s32 dialog_find_item(struct menudialog *dialog, struct menuitem *item, s32 *rowindex, s32 *colindex);
bool menu_is_scrollable_unscrollable(struct menuitem *item);
bool menu_is_item_disabled(struct menuitem *item, struct menudialog *dialog);
void menu_push_dialog(struct menudialogdef *dialogdef);

#if VERSION >= VERSION_NTSC_1_0
bool menu_save_file(s32 arg0);
#else
void menu_save_file(s32 arg0);
#endif

void menu_close_dialog(void);
void menu_update_cur_frame(void);
void menu_pop_dialog(void);
void menu_replace_current_dialog(struct menudialogdef *dialogdef);
void menu_configure_model(struct menumodel *menumodel, f32 x, f32 y, f32 z, f32 rotx, f32 roty, f32 rotz, f32 scale, u8 flags);
void menu_unset_model(struct menumodel *menumodel);
Gfx *menu_render_model(Gfx *gdl, struct menumodel *menumodel, s32 modeltype);
Gfx *menu_apply_scissor(Gfx *gdl);

#if VERSION >= VERSION_JPN_FINAL
#else
#endif

void menu_save_and_close_all(void);
void menu_save_and_push_root_dialog(struct menudialogdef *dialogdef, s32 root);
void menu_hide_pressstart_labels(void);
void menu_push_root_dialog(struct menudialogdef *dialogdef, s32 arg1);
void menu_push_root_dialog_and_pause(struct menudialogdef *dialogdef, s32 root);
void menu_reset_model(struct menumodel *menumodel, u32 allocationlen, bool allocate);
void menu_reset(void);
void menu_consider_unpause(void);
void menu_process_input(void);
Gfx *menu_render(Gfx *gdl);
u32 menu_choose_music(void);
u32 menu_get_root(void);
bool menu_is_ready_for_pak_error(s32 device, s32 arg1);
void menu_push_pak_error_dialog(s32 arg0, s32 arg1);
void menu_set_source_pos(struct coord *pos);
void menu_queue_save(s32 playernum);
struct menudialog *menu_is_dialog_open(struct menudialogdef *dialogdef);
struct chrdata *current_player_get_commanding_aibot(void);


extern const char var7f1b2658[];
extern const char var7f1b265c[];
extern const char var7f1b2660[];
extern const char var7f1b2664[];

#endif
