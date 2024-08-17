#ifndef IN_GAME_MENUITEM_H
#define IN_GAME_MENUITEM_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

s32 menuitem0f0e5d2c(s32 arg0, struct menuitem *item);
s16 menuitem_list_get_offset_y(s16 optionindex, struct menuitem *item);
Gfx *menuitem_list_render_header(Gfx *gdl, s16 x1, s16 y1, s16 width, s16 arg4, s16 height, char *text, struct menudialog *dialog);
Gfx *menuitem_list_overlay(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2);
Gfx *menuitem_list_render(Gfx *gdl, struct menurendercontext *context);
bool menuitem_list_tick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data);

void menuitem_dropdown_init(struct menuitem *item, union menuitemdata *data);
Gfx *menuitem_dropdown_render(Gfx *gdl, struct menurendercontext *context);
bool menuitem_dropdown_tick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data);

Gfx *menuitem_dropdown_overlay(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, struct menudialog *dialog, union menuitemdata *data);
bool menuitem_keyboard_is_string_empty_or_spaces(char *text);
Gfx *menuitem_keyboard_render(Gfx *gdl, struct menurendercontext *thing);
bool menuitem_keyboard_tick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data);
void menuitem_keyboard_init(struct menuitem *item, union menuitemdata *data);

Gfx *menuitem_separator_render(Gfx *gdl, struct menurendercontext *context);

Gfx *menuitem_objectives_render_one(Gfx *gdl, struct menudialog *dialog, s32 index, s32 position, s16 objx, s16 objy, s16 width, s16 height, bool withstatus, bool narrow);
Gfx *menuitem_objectives_render(Gfx *gdl, struct menurendercontext *context);

Gfx *menuitem_model_render(Gfx *gdl, struct menurendercontext *context);

Gfx *menuitem_label_render(Gfx *gdl, struct menurendercontext *context);

Gfx *menuitem_meter_render(Gfx *gdl, struct menurendercontext *context);

Gfx *menuitem_selectable_render(Gfx *gdl, struct menurendercontext *context);
bool menuitem_selectable_tick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags);

Gfx *menuitem_slider_render(Gfx *gdl, struct menurendercontext *context);
bool menuitem_slider_tick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data);
void menuitem_slider_init(union menuitemdata *data);

Gfx *menuitem_carousel_render(Gfx *gdl, struct menurendercontext *context);
bool menuitem_carousel_tick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags);

Gfx *menuitem_checkbox_render(Gfx *gdl, struct menurendercontext *context);
bool menuitem_checkbox_tick(struct menuitem *item, struct menuinputs *inputs, u32 tickflags);

char *menuitem_scrollable_get_text(u32 type);
Gfx *menuitem_scrollable_render(Gfx *gdl, struct menurendercontext *context);
bool menuitem_scrollable_tick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data);
void menuitem_scrollable_init(union menuitemdata *data);

Gfx *menuitem_marquee_render(Gfx *gdl, struct menurendercontext *context);
bool menuitem_marquee_tick(struct menuitem *item, union menuitemdata *data);
void menuitem_marquee_init(union menuitemdata *data);

Gfx *menuitem07_render(Gfx *gdl);

Gfx *menuitem_ranking_render(Gfx *gdl, struct menurendercontext *context);
bool menuitem_ranking_tick(struct menuinputs *inputs, u32 tickflags, union menuitemdata *data);
void menuitem_ranking_init(union menuitemdata *data);

Gfx *menuitem_player_stats_render(Gfx *gdl, struct menurendercontext *context);
bool menuitem_player_stats_tick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data);
Gfx *menuitem_player_stats_overlay(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, struct menudialog *dialog, union menuitemdata *data);
void menuitem_player_stats_init(struct menuitem *item, union menuitemdata *data);

Gfx *menuitem_controller_render_line(Gfx *gdl, s32 speed, s32 x1, s32 y1, s32 x2, s32 y2);
Gfx *menuitem_controller_render_texture(Gfx *gdl, s32 x, s32 y, s32 texturenum, u32 alpha);
Gfx *menuitem_controller_render_lines(Gfx *gdl, struct menurendercontext *context, s32 firstindex, s32 lastindex, s32 padx, s32 pady, u32 alpha);
u16 menuitem_controller_get_button_action(s32 mode, s32 buttonnum);
Gfx *menuitem_controller_render_text(Gfx *gdl, s32 curmode, struct menurendercontext *context, s32 padx, s32 pady, u32 valuecolour, u32 labelcolour, s8 prevmode);
Gfx *menuitem_controller_render_pad(Gfx *gdl, struct menurendercontext *context, s32 padx, s32 pady, s32 curmode, u32 alpha, u32 colour1, u32 colour2, s8 prevmode);
Gfx *menuitem_controller_render(Gfx *gdl, struct menurendercontext *context);
void menuitem_controller_init(union menuitemdata *data);

Gfx *menuitem_render(Gfx *gdl, struct menurendercontext *context);
bool menuitem_tick(struct menuitem *item, struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags, union menuitemdata *data);
void menuitem_init(struct menuitem *item, union menuitemdata *data);
Gfx *menuitem_overlay(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, struct menudialog *dialog, union menuitemdata *data);

#endif
