#ifndef _IN_GAME_TITLE_H
#define _IN_GAME_TITLE_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern s32 g_NumPlayers;

void titleInit(void);

void titleReset(void);

Gfx *titleClear(Gfx *gdl);

char *mpPlayerGetWeaponOfChoiceName(u32 playernum, u32 slot);
void titleSetNextMode(s32 mode);
void titleTick(void);
bool titleIsChangingMode(void);
bool titleIsKeepingMode(void);
void titleExit(void);
void titleInitFromAiCmd(u32 arg0);
Gfx *titleRender(Gfx *gdl);

#endif
