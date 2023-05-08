#ifndef IN_GAME_MENU_H
#define IN_GAME_MENU_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern const struct menucolourpalette g_MenuColourPalettes[];
extern const struct menucolourpalette g_MenuColourPalettes2[];
extern const struct menucolourpalette g_MenuColourPalettes3[];

void menuTick(void);

void menuStop(void);

void menuPlaySound(s32 menusound);
bool currentPlayerIsMenuOpenInSoloOrMp(void);
bool func0f0f0c68(void);
void menuSetBanner(s32 bannernum, bool allplayers);
struct menudfc *func0f0f1338(struct menuitem *item);
void func0f0f139c(struct menuitem *item, f32 arg1);
void func0f0f13ec(struct menuitem *item);
char *menuResolveText(u32 thing, void *dialogoritem);
char *menuResolveParam2Text(struct menuitem *item);
s32 dialogFindItem(struct menudialog *dialog, struct menuitem *item, s32 *rowindex, s32 *colindex);
bool menuIsScrollableUnscrollable(struct menuitem *item);
bool menuIsItemDisabled(struct menuitem *item, struct menudialog *dialog);
void menuPushDialog(struct menudialogdef *dialogdef);
bool func0f0f3220(s32 arg0);
void menuCloseDialog(void);
void menuUpdateCurFrame(void);
void menuPopDialog(void);
void func0f0f3704(struct menudialogdef *dialogdef);
void func0f0f372c(struct menu840 *arg0, f32 x, f32 y, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, u8 flags);
void func0f0f37a4(struct menu840 *arg0);
Gfx *menuRenderModels(Gfx *gdl, struct menu840 *arg1, s32 arg2);
Gfx *menuApplyScissor(Gfx *gdl);
void func0f0f8120(void);
void func0f0f820c(struct menudialogdef *dialogdef, s32 root);
void func0f0f8300(void);
void menuPushRootDialog(struct menudialogdef *dialogdef, s32 arg1);
void func0f0f85e0(struct menudialogdef *dialogdef, s32 root);
void func0f0f8bb4(struct menu840 *arg0, u32 arg1, u32 arg2);
void menuReset(void);
void func0f0fa6ac(void);
void menuProcessInput(void);
Gfx *menuRender(Gfx *gdl);
u32 menuChooseMusic(void);
u32 menuGetRoot(void);
bool func0f0fd1f4(s32 device, s32 arg1);
void func0f0fd320(s32 arg0, s32 arg1);
void func0f0fd494(struct coord *pos);
void func0f0fd548(s32 arg0);
struct menudialog *menuIsDialogOpen(struct menudialogdef *dialogdef);
struct chrdata *currentPlayerGetCommandingAibot(void);

#endif
