#ifndef IN_GAME_GAME_0E5CE0_H
#define IN_GAME_GAME_0E5CE0_H
#include <ultra64.h>
#include "types.h"

u32 func0f0e5d2c(void);
u32 func0f0e5ef8(void);
u32 func0f0e6038(void);
Gfx *func0f0e6298(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2);
Gfx *menuRenderItemCustom(Gfx *gdl);
bool menuTickItemCustom(struct menuitem *item, void *arg1, u32 arg2, u16 *arg3);
void func0f0e7998(struct menuitem *item, u16 *arg1);
Gfx *menuRenderItemDropdown(Gfx *gdl);
bool menuTickItemDropdown(struct menuitem *item, void *arg1, void *arg2, u32 arg3, u16 *arg4);
Gfx *func0f0e8290(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, u32 arg6, u32 arg7);
u32 func0f0e855c(void);
Gfx *menuRenderItemKeyboard(Gfx *gdl);
bool menuTickItemKeyboard(struct menuitem *item, void *arg1, u32 arg2, u16 *arg3);
void func0f0e9744(struct menuitem *item, u16 *arg1);
Gfx *menuRenderItemSeparator(Gfx *gdl, struct menurenderthing *thing);
Gfx *menuRenderObjective(Gfx *gfx, struct menurenderthing10 *thing10, s32 index, s32 position, s32 x, s32 y, s32 width, s32 height, s32 arg8, s32 arg9);
Gfx *menuRenderItemObjectives(Gfx *gdl, struct menurenderthing *thing);
Gfx *menuRenderItemModel(Gfx *gdl, struct menurenderthing *thing);
Gfx *menuRenderItemLabel(Gfx *gdl, struct menurenderthing *thing);
Gfx *menuRenderItemMeter(Gfx *gdl, struct menurenderthing *thing);
Gfx *menuRenderItemSelectable(Gfx *gdl, struct menurenderthing *thing);
bool menuTickItemSelectable(struct menuitem *item, void *arg1, u32 arg2);
Gfx *menuRenderItemSlider(Gfx *gdl);
bool menuTickItemSlider(struct menuitem *item, void *arg1, void *arg2, u32 arg3, u16 *arg4);
void func0f0ec220(u16 *arg0);
Gfx *menuRenderItemCarousel(Gfx *gdl, struct menurenderthing *thing);
bool menuTickItemCarousel(struct menuitem *item, void *arg1, u32 arg2);
Gfx *menuRenderItemCheckbox(Gfx *gdl, struct menurenderthing *thing);
bool menuTickItemCheckbox(struct menuitem *item, void *arg1, u32 arg2);
char *menuItemScrollableGetText(u32 type);
Gfx *menuRenderItemScrollable(Gfx *gdl, struct menurenderthing *thing);
bool menuTickItemScrollable(struct menuitem *item, void *arg1, void *arg2, u32 arg3, u16 *arg4);
void func0f0ed514(u16 *arg0);
Gfx *menuRenderItemMarquee(Gfx *gdl, struct menurenderthing *thing);
bool menuTickItemMarquee(struct menuitem *item, u16 *arg1);
void func0f0edb50(u16 *arg0);
Gfx *menuRenderItem07(Gfx *gdl);
Gfx *menuRenderItemRanking(Gfx *gdl);
bool menuTickItemRanking(void *arg1, u32 arg2, u16 *arg3);
void func0f0ee640(u16 *arg0);
Gfx *menuRenderItemPlayerStats(Gfx *gdl);
bool menuTickItemPlayerStats(struct menuitem *item, void *arg1, void *arg2, u32 arg3, u16 *arg4);
Gfx *func0f0ef2fc(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, u32 arg6, u32 arg7);
void func0f0ef360(struct menuitem *item, u16 *arg1);
u32 func0f0ef394(void);
Gfx *menuRenderControllerTexture(Gfx *gdl, s32 x, s32 y, s32 texturenum, u32 alpha);
Gfx *menuRenderControllerLines(Gfx *gdl, struct menurenderthing *thing, s32 arg2, s32 arg3, s32 x, s32 y, u32 alpha);
u16 menuControllerGetButtonAction(s32 mode, s32 buttonnum);
Gfx *menuRenderControllerText(Gfx *gdl, s32 curmode, struct menurenderthing *thing, s32 x, s32 y, u32 valuecolour, u32 labelcolour, s8 prevmode);
Gfx *menuRenderControllerInfo(Gfx *gdl, struct menurenderthing *thing, s32 x, s32 y, s32 curmode, u32 alpha, u32 colour1, u32 colour2, s8 prevmode);
Gfx *menuRenderItemController(Gfx *gdl, struct menurenderthing *thing);
void func0f0f057c(u16 *arg0);
Gfx *menuRenderItem(Gfx *gdl, struct menurenderthing *thing);
bool menuTickItem(struct menuitem *item, void *arg1, void *arg2, u32 arg3, u16 *arg4);
void func0f0f0860(struct menuitem *ite, u16 *arg1);
Gfx *func0f0f0918(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, u32 arg6, u32 arg7);

#endif
