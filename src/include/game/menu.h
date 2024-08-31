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
bool func0f0f0c68(void);
void menu_set_banner(s32 bannernum, bool allplayers);

#if VERSION >= VERSION_NTSC_1_0
#else
#endif

struct menudfc *func0f0f1338(struct menuitem *item);
void func0f0f139c(struct menuitem *item, f32 arg1);
void func0f0f13ec(struct menuitem *item);
char *menu_resolve_text(uintptr_t thing, void *dialogoritem);
char *menu_resolve_param2_text(struct menuitem *item);
s32 dialog_find_item(struct menudialog *dialog, struct menuitem *item, s32 *rowindex, s32 *colindex);
bool menu_is_scrollable_unscrollable(struct menuitem *item);
bool menu_is_item_disabled(struct menuitem *item, struct menudialog *dialog);
void menu_push_dialog(struct menudialogdef *dialogdef);

#if VERSION >= VERSION_NTSC_1_0
bool func0f0f3220(s32 arg0);
#else
void func0f0f3220(s32 arg0);
#endif

void menu_close_dialog(void);
void menu_update_cur_frame(void);
void menu_pop_dialog(void);
void func0f0f3704(struct menudialogdef *dialogdef);
void menu_configure_model(struct menumodel *menumodel, f32 x, f32 y, f32 z, f32 rotx, f32 roty, f32 rotz, f32 scale, u8 flags);
void menu_unset_model(struct menumodel *menumodel);
Gfx *menu_render_model(Gfx *gdl, struct menumodel *menumodel, s32 modeltype);
Gfx *menu_apply_scissor(Gfx *gdl);

#if VERSION >= VERSION_JPN_FINAL
#else
#endif

void func0f0f8120(void);
void func0f0f820c(struct menudialogdef *dialogdef, s32 root);
void func0f0f8300(void);
void menu_push_root_dialog(struct menudialogdef *dialogdef, s32 arg1);
void func0f0f85e0(struct menudialogdef *dialogdef, s32 root);
void menu_reset_model(struct menumodel *menumodel, u32 allocationlen, bool allocate);
void menu_reset(void);
void func0f0fa6ac(void);
void menu_process_input(void);
Gfx *menu_render(Gfx *gdl);
u32 menu_choose_music(void);
u32 menu_get_root(void);
bool menu_is_ready_for_pak_error(s32 device, s32 arg1);
void menu_push_pak_error_dialog(s32 arg0, s32 arg1);
void func0f0fd494(struct coord *pos);
void func0f0fd548(s32 arg0);
struct menudialog *menu_is_dialog_open(struct menudialogdef *dialogdef);
struct chrdata *current_player_get_commanding_aibot(void);


extern const char var7f1b2658[];
extern const char var7f1b265c[];
extern const char var7f1b2660[];
extern const char var7f1b2664[];

#endif
