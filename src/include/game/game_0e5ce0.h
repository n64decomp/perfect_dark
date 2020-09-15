#ifndef IN_GAME_GAME_0E5CE0_H
#define IN_GAME_GAME_0E5CE0_H
#include <ultra64.h>
#include "types.h"

u32 func0f0e5d2c(void);
u32 func0f0e5ef8(void);
u32 func0f0e6038(void);
u32 func0f0e6298(void);
Gfx *menuRenderItemCustom(Gfx *gdl);
u32 func0f0e75a0(void);
void func0f0e7998(struct menuitem *item, u16 *arg1);
Gfx *menuRenderItemDropdown(Gfx *gdl);
u32 func0f0e8138(void);
u32 func0f0e8290(void);
u32 func0f0e855c(void);
Gfx *menuRenderItemKeyboard(Gfx *gdl);
u32 func0f0e91d0(void);
void func0f0e9744(struct menuitem *item, u16 *arg1);
Gfx *menuRenderItemSeparator(Gfx *gdl, struct menurenderthing *thing);
Gfx *menuRenderObjective(Gfx *gfx, struct menurenderthing10 *thing10, s32 index, s32 position, s32 x, s32 y, s32 width, s32 height, s32 arg8, s32 arg9);
Gfx *menuRenderItemObjectives(Gfx *gdl, struct menurenderthing *thing);
Gfx *menuRenderItemModel(Gfx *gdl, struct menurenderthing *thing);
Gfx *menuRenderItemLabel(Gfx *gdl);
Gfx *menuRenderItemMeter(Gfx *gdl, struct menurenderthing *thing);
Gfx *menuRenderItemSelectable(Gfx *gdl);
u32 func0f0eb46c(void);
Gfx *menuRenderItemSlider(Gfx *gdl);
u32 func0f0ebec8(void);
void func0f0ec220(u16 *arg0);
Gfx *menuRenderItemCarousel(Gfx *gdl);
u32 func0f0ec4e4(void);
Gfx *menuRenderItemCheckbox(Gfx *gdl);
u32 func0f0ecbfc(void);
char *menuTrainGetDescription(u32 type);
Gfx *menuRenderItemScrollable(Gfx *gdl);
u32 func0f0ed264(void);
void func0f0ed514(u16 *arg0);
Gfx *menuRenderItemMarquee(Gfx *gdl);
u32 func0f0eda34(void);
void func0f0edb50(u16 *arg0);
Gfx *menuRenderItem07(Gfx *gdl);
Gfx *menuRenderItemRanking(Gfx *gdl);
u32 func0f0ee574(void);
void func0f0ee640(u16 *arg0);
Gfx *menuRenderItemPlayerStats(Gfx *gdl);
u32 func0f0ef200(void);
u32 func0f0ef2fc(void);
void func0f0ef360(struct menuitem *item, u16 *arg1);
u32 func0f0ef394(void);
u32 func0f0ef4bc(void);
u32 func0f0ef758(void);
u16 func0f0efa90(s32 row, s32 col);
u32 func0f0efbb4(void);
u32 func0f0efe30(void);
Gfx *menuRenderItemController(Gfx *gdl);
void func0f0f057c(u16 *arg0);
Gfx *menuRenderItem(Gfx *gdl, struct menurenderthing *thing);
u32 func0f0f0704(void);
void func0f0f0860(struct menuitem *ite, u16 *arg1);
u32 func0f0f0918(void);

#endif
