#ifndef _IN_GAME_MPLAYER_INGAME_H
#define _IN_GAME_MPLAYER_INGAME_H
#include <ultra64.h>
#include "types.h"

s32 mpStatsForPlayerDropdownHandler(s32 operation, struct menuitem *item, union handlerdata *data);
char *mpMenuTextInGameLimit(struct menuitem *item);
char *menutextPauseOrUnpause(s32 arg0);
char *menutextMatchTime(s32 arg0);
char *mpMenuTextWeaponDescription(struct menuitem *item);
char *mpMenuTitleStatsFor(struct menudialog *dialog);
char *mpMenuTextWeaponOfChoiceName(struct menuitem *item);
char *mpMenuTextAward1(struct menuitem *item);
char *mpMenuTextAward2(struct menuitem *item);
char *mpMenuTextPlacementWithSuffix(struct menuitem *item);
s32 mpPlacementMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandler001786d8(s32 operation, struct menuitem *item, union handlerdata *data);
s32 mpPlayerTitleMenuHandler(s32 operation, struct menuitem *item, union handlerdata *data);
char *mpMenuTextPlayerTitle(s32 arg0);
s32 menuhandler00178bf4(s32 operation, struct menuitem *item, union handlerdata *data);
void mpPushPauseDialog(void);
void mpPushEndscreenDialog(u32 arg0, u32 playernum);
s32 menuhandlerMpEndGame(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandler00178018(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerMpInGameLimitLabel(s32 operation, struct menuitem *item, union handlerdata *data);
s32 menuhandlerMpPause(s32 operation, struct menuitem *item, union handlerdata *data);

#endif
