#ifndef IN_GAME_GAME_0F09F0_H
#define IN_GAME_GAME_0F09F0_H
#include <ultra64.h>
#include "types.h"

extern const struct menucolourpalette g_MenuColourPalettes[];
extern const struct menucolourpalette g_MenuColourPalettes2[];
extern const struct menucolourpalette g_MenuColourPalettes3[];

void func0f0f09f0(s32 arg0);
bool menuIsSoloMissionOrMp(void);
bool currentPlayerIsMenuOpenInSoloOrMp(void);
bool func0f0f0c68(void);
void func0f0f0ca0(s32 value, bool allplayers);
u32 func0f0f0ce8(void);
struct menudfc *func0f0f1338(struct menuitem *item);
void func0f0f139c(struct menuitem *item, f32 arg1);
void func0f0f13ec(struct menuitem *item);
void func0f0f1418(void);
void func0f0f1494(void);
char *menuResolveText(u32 thing, struct menuitem *item);
char *menuResolveParam2Text(struct menuitem *item);
char *menuResolveParam1Text(struct menuitem *item);
void func0f0f15a4(u8 *arg0, u32 *arg1);
void func0f0f1618(struct menuitem *item, void *arg1, void *arg2, struct menurenderthing10 *arg3);
void func0f0f1d6c(struct menudialog *dialog, struct menuframe *frame, struct menu *menu);
u32 func0f0f1ef4(void);
void func0f0f2134(struct menudialog *dialog, struct menuframe *frame, struct menu *menu);
void func0f0f2354(struct menurenderthing10 *thing10, struct menuitem *item, u32 *arg2, u32 *arg3);
bool menuIsScrollableUnscrollable(struct menuitem *item);
bool menuIsItemDisabled(struct menuitem *item, struct menurenderthing10 *thing10);
bool func0f0f2674(struct menuitem *item, struct menurenderthing10 *thing10, u32 arg2);
u32 func0f0f26fc(void);
struct menuitem *func0f0f288c(struct menuframe *frame);
u32 func0f0f2928(void);
u32 func0f0f29cc(void);
u32 func0f0f2b2c(void);
u32 func0f0f2c44(void);
void menuOpenDialog(struct menudialog *dialog, struct menuframe *arg1, struct menu *menu);
void menuPushDialog(struct menudialog *dialog);
void func0f0f3220(s32 arg0);
void menuCloseDialog(void);
void menuUpdateCurFrame(void);
void menuPopDialog(void);
void func0f0f3704(struct menudialog *dialog);
void func0f0f372c(u8 *arg0, f32 x, f32 y, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 arg8);
void func0f0f37a4(u8 *arg0);
u32 func0f0f38b0(void);
u32 func0f0f5004(void);
Gfx *func0f0f50fc(Gfx *gdl);
u32 func0f0f5360(void);
u32 func0f0f74a8(void);
u32 func0f0f7594(void);
u32 func0f0f7728(void);
void func0f0f7e98(struct menuframe *frame);
void func0f0f8040(void);
void func0f0f8120(void);
void func0f0f820c(struct menudialog *dialog, s32 arg1);
bool func0f0f82a8(s32 arg0);
void func0f0f8300(void);
void menuPushRootDialog(struct menudialog *dialog, s32 arg1);
void func0f0f85e0(struct menudialog *dialog, s32 root);
u32 func0f0f8634(void);
u32 func0f0f86a8(void);
void func0f0f8bb4(u8 *arg0, u32 arg1, u32 arg2);
void func0f0f8c98(void);
u32 func0f0f9030(void);
u32 func0f0f935c(void);
void func0f0fa574(struct menuframe *frame);
void func0f0fa6ac(void);
void func0f0fa704(void);
u32 func0f0fb488(void);
Gfx *func0f0fbba0(Gfx *gdl, u8 param_2, s32 arg2);
u32 func0f0fbc30(void);
u32 menuChooseMusic(void);
u32 menuGetRoot(void);
u32 func0f0fce8c(void);
char *menuTextSaveDeviceName(struct menuitem *item);
u32 func0f0fd118(u32 arg0);
bool func0f0fd1f4(u32 arg0, u32 arg1);
u32 func0f0fd320(void);
void func0f0fd494(struct coord *pos);
void func0f0fd548(s32 arg0);
u32 func0f0fd570(void);
bool currentPlayerGetUnk1c04(void);

extern const char var7f1b2658[];
extern const char var7f1b265c[];
extern const char var7f1b2660[];
extern const char var7f1b2664[];

#endif
