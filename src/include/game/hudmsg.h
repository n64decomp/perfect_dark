#ifndef IN_GAME_HUDMSG_H
#define IN_GAME_HUDMSG_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u8 hudmsgsAreActive(void);
void hudmsgsHideByChannel(s32 value);
void hudmsgsReset(void);
void hudmsgRemoveAll(void);
void hudmsgCreate(char *text, s32 type);
void hudmsgCreateWithFlags(char *text, s32 type, u32 flags);
void hudmsgCreateWithColour(char *text, s32 type, u8 colour);
void hudmsgCreateAsSubtitle(char *text, s32 type, u8 colourindex, s32 audiochannelnum);
void hudmsgsTick(void);
void hudmsgsSetOn(u32 reason);
void hudmsgsSetOff(u32 reason);
void hudmsgsRemoveForDeadPlayer(s32 playernum);
Gfx *hudmsgsRender(Gfx *gdl);
void hudmsgsStop(void);

#endif
