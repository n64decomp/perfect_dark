#ifndef IN_GAME_GAME_0E5CE0_H
#define IN_GAME_GAME_0E5CE0_H
#include <ultra64.h>
#include "types.h"

u32 func0f0e5d2c(void);
s32 func0f0e5ef8(s16 arg0, struct menuitem *item);
u32 func0f0e6038(void);
Gfx *func0f0e6298(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2);
Gfx *menuRenderItemCustom(Gfx *gdl);
bool menuTickItemCustom(struct menuitem *item, struct somemenuitemtickarg *arg1, u32 arg2, union menuitemtickdata *data);
void menuInitItemDropdown(struct menuitem *item, union menuitemtickdata *data);
Gfx *menuRenderItemDropdown(Gfx *gdl);
bool menuTickItemDropdown(struct menuitem *item, struct menuframe *frame, struct somemenuitemtickarg *arg2, u32 arg3, union menuitemtickdata *data);
Gfx *func0f0e8290(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, u32 arg6, u32 arg7);
u32 func0f0e855c(void);
Gfx *menuRenderItemKeyboard(Gfx *gdl);
bool menuTickItemKeyboard(struct menuitem *item, struct somemenuitemtickarg *arg1, u32 arg2, union menuitemtickdata *data);
void menuInitItemKeyboard(struct menuitem *item, union menuitemtickdata *data);
Gfx *menuRenderItemSeparator(Gfx *gdl, struct menurenderthing *thing);
Gfx *menuRenderObjective(Gfx *gfx, struct menurenderthing10 *thing10, s32 index, s32 position, s32 x, s32 y, s32 width, s32 height, s32 arg8, s32 arg9);
Gfx *menuRenderItemObjectives(Gfx *gdl, struct menurenderthing *thing);
Gfx *menuRenderItemModel(Gfx *gdl, struct menurenderthing *thing);
Gfx *menuRenderItemLabel(Gfx *gdl, struct menurenderthing *thing);
Gfx *menuRenderItemMeter(Gfx *gdl, struct menurenderthing *thing);
Gfx *menuRenderItemSelectable(Gfx *gdl, struct menurenderthing *thing);
bool menuTickItemSelectable(struct menuitem *item, struct somemenuitemtickarg *arg1, u32 arg2);
Gfx *menuRenderItemSlider(Gfx *gdl);
bool menuTickItemSlider(struct menuitem *item, struct menuframe *frame, struct somemenuitemtickarg *arg2, u32 arg3, union menuitemtickdata *data);
void menuInitItemSlider(union menuitemtickdata *data);
Gfx *menuRenderItemCarousel(Gfx *gdl, struct menurenderthing *thing);
bool menuTickItemCarousel(struct menuitem *item, struct somemenuitemtickarg *arg1, u32 arg2);
Gfx *menuRenderItemCheckbox(Gfx *gdl, struct menurenderthing *thing);
bool menuTickItemCheckbox(struct menuitem *item, struct somemenuitemtickarg *arg1, u32 arg2);
char *menuItemScrollableGetText(u32 type);
Gfx *menuRenderItemScrollable(Gfx *gdl, struct menurenderthing *thing);
bool menuTickItemScrollable(struct menuitem *item, struct menuframe *frame, struct somemenuitemtickarg *arg2, u32 arg3, union menuitemtickdata *data);
void menuInitItemScrollable(union menuitemtickdata *data);
Gfx *menuRenderItemMarquee(Gfx *gdl, struct menurenderthing *thing);
bool menuTickItemMarquee(struct menuitem *item, union menuitemtickdata *data);
void menuInitItemMarquee(union menuitemtickdata *data);
Gfx *menuRenderItem07(Gfx *gdl);
Gfx *menuRenderItemRanking(Gfx *gdl);
bool menuTickItemRanking(struct somemenuitemtickarg *arg0, u32 arg1, union menuitemtickdata *data);
void menuInitItemRanking(union menuitemtickdata *data);
Gfx *menuRenderItemPlayerStats(Gfx *gdl);
bool menuTickItemPlayerStats(struct menuitem *item, struct menuframe *frame, struct somemenuitemtickarg *arg2, u32 arg3, union menuitemtickdata *data);
Gfx *func0f0ef2fc(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, u32 arg6, u32 arg7);
void menuInitItemPlayerStats(struct menuitem *item, union menuitemtickdata *data);
u32 func0f0ef394(void);
Gfx *menuRenderControllerTexture(Gfx *gdl, s32 x, s32 y, s32 texturenum, u32 alpha);
Gfx *menuRenderControllerLines(Gfx *gdl, struct menurenderthing *thing, s32 arg2, s32 arg3, s32 x, s32 y, u32 alpha);
u16 menuControllerGetButtonAction(s32 mode, s32 buttonnum);
Gfx *menuRenderControllerText(Gfx *gdl, s32 curmode, struct menurenderthing *thing, s32 x, s32 y, u32 valuecolour, u32 labelcolour, s8 prevmode);
Gfx *menuRenderControllerInfo(Gfx *gdl, struct menurenderthing *thing, s32 x, s32 y, s32 curmode, u32 alpha, u32 colour1, u32 colour2, s8 prevmode);
Gfx *menuRenderItemController(Gfx *gdl, struct menurenderthing *thing);
void menuInitItemController(union menuitemtickdata *data);
Gfx *menuRenderItem(Gfx *gdl, struct menurenderthing *thing);
bool menuTickItem(struct menuitem *item, struct menuframe *frame, struct somemenuitemtickarg *arg2, u32 arg3, union menuitemtickdata *data);
void menuInitItem(struct menuitem *item, union menuitemtickdata *data);
Gfx *func0f0f0918(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, u32 arg6, u32 arg7);

#endif
