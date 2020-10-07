#ifndef IN_GAME_GAME_0E5CE0_H
#define IN_GAME_GAME_0E5CE0_H
#include <ultra64.h>
#include "types.h"

u32 func0f0e5d2c(void);
s32 func0f0e5ef8(s16 arg0, struct menuitem *item);
u32 func0f0e6038(void);
Gfx *menuRenderOverlayList(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2);
Gfx *menuRenderItemList(Gfx *gdl, struct menurendercontext *context);
bool menuTickItemList(struct menuitem *item, struct menuinputs *inputs, u32 arg2, union menuitemdata *data);

void menuInitItemDropdown(struct menuitem *item, union menuitemdata *data);
Gfx *menuRenderItemDropdown(Gfx *gdl);
bool menuTickItemDropdown(struct menuitem *item, struct menuframe *frame, struct menuinputs *inputs, u32 arg3, union menuitemdata *data);

Gfx *menuRenderOverlayDropdown(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, struct menuframe *frame, union menuitemdata *data);
bool menuIsStringEmptyOrSpaces(char *text);
Gfx *menuRenderItemKeyboard(Gfx *gdl, struct menurendercontext *thing);
bool menuTickItemKeyboard(struct menuitem *item, struct menuinputs *inputs, u32 arg2, union menuitemdata *data);
void menuInitItemKeyboard(struct menuitem *item, union menuitemdata *data);

Gfx *menuRenderItemSeparator(Gfx *gdl, struct menurendercontext *context);

Gfx *menuRenderObjective(Gfx *gfx, struct menuframe *frame, s32 index, s32 position, s32 x, s32 y, s32 width, s32 height, s32 arg8, s32 arg9);
Gfx *menuRenderItemObjectives(Gfx *gdl, struct menurendercontext *context);

Gfx *menuRenderItemModel(Gfx *gdl, struct menurendercontext *context);

Gfx *menuRenderItemLabel(Gfx *gdl, struct menurendercontext *context);

Gfx *menuRenderItemMeter(Gfx *gdl, struct menurendercontext *context);

Gfx *menuRenderItemSelectable(Gfx *gdl, struct menurendercontext *context);
bool menuTickItemSelectable(struct menuitem *item, struct menuinputs *inputs, u32 arg2);

Gfx *menuRenderItemSlider(Gfx *gdl);
bool menuTickItemSlider(struct menuitem *item, struct menuframe *frame, struct menuinputs *inputs, u32 arg3, union menuitemdata *data);
void menuInitItemSlider(union menuitemdata *data);

Gfx *menuRenderItemCarousel(Gfx *gdl, struct menurendercontext *context);
bool menuTickItemCarousel(struct menuitem *item, struct menuinputs *inputs, u32 arg2);

Gfx *menuRenderItemCheckbox(Gfx *gdl, struct menurendercontext *context);
bool menuTickItemCheckbox(struct menuitem *item, struct menuinputs *inputs, u32 arg2);

char *menuItemScrollableGetText(u32 type);
Gfx *menuRenderItemScrollable(Gfx *gdl, struct menurendercontext *context);
bool menuTickItemScrollable(struct menuitem *item, struct menuframe *frame, struct menuinputs *inputs, u32 arg3, union menuitemdata *data);
void menuInitItemScrollable(union menuitemdata *data);

Gfx *menuRenderItemMarquee(Gfx *gdl, struct menurendercontext *context);
bool menuTickItemMarquee(struct menuitem *item, union menuitemdata *data);
void menuInitItemMarquee(union menuitemdata *data);

Gfx *menuRenderItem07(Gfx *gdl);

Gfx *menuRenderItemRanking(Gfx *gdl, struct menurendercontext *context);
bool menuTickItemRanking(struct menuinputs *inputs, u32 arg1, union menuitemdata *data);
void menuInitItemRanking(union menuitemdata *data);

Gfx *menuRenderItemPlayerStats(Gfx *gdl, struct menurendercontext *context);
bool menuTickItemPlayerStats(struct menuitem *item, struct menuframe *frame, struct menuinputs *inputs, u32 arg3, union menuitemdata *data);
Gfx *menuRenderOverlayPlayerStats(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, struct menuframe *frame, union menuitemdata *data);
void menuInitItemPlayerStats(struct menuitem *item, union menuitemdata *data);

u32 func0f0ef394(void);
Gfx *menuRenderControllerTexture(Gfx *gdl, s32 x, s32 y, s32 texturenum, u32 alpha);
Gfx *menuRenderControllerLines(Gfx *gdl, struct menurendercontext *context, s32 arg2, s32 arg3, s32 x, s32 y, u32 alpha);
u16 menuControllerGetButtonAction(s32 mode, s32 buttonnum);
Gfx *menuRenderControllerText(Gfx *gdl, s32 curmode, struct menurendercontext *context, s32 x, s32 y, u32 valuecolour, u32 labelcolour, s8 prevmode);
Gfx *menuRenderControllerInfo(Gfx *gdl, struct menurendercontext *context, s32 x, s32 y, s32 curmode, u32 alpha, u32 colour1, u32 colour2, s8 prevmode);
Gfx *menuRenderItemController(Gfx *gdl, struct menurendercontext *context);
void menuInitItemController(union menuitemdata *data);

Gfx *menuRenderItem(Gfx *gdl, struct menurendercontext *context);
bool menuTickItem(struct menuitem *item, struct menuframe *frame, struct menuinputs *inputs, u32 arg3, union menuitemdata *data);
void menuInitItem(struct menuitem *item, union menuitemdata *data);
Gfx *menuRenderOverlay(Gfx *gdl, s16 x, s16 y, s16 x2, s16 y2, struct menuitem *item, struct menuframe *frame, union menuitemdata *data);

#endif
