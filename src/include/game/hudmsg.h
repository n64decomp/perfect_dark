#ifndef IN_GAME_HUDMSG_H
#define IN_GAME_HUDMSG_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u8 hudmsgsAreActive(void);
s32 hudmsgIsZoomRangeVisible(void);
Gfx *hudmsgRenderMissionTimer(Gfx *gdl, u32 arg1);
Gfx *hudmsgRenderZoomRange(Gfx *gdl, s32 arg1);
Gfx *hudmsgRenderBox(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, f32 bgopacity, u32 bordercolour, f32 textopacity);
s32 func0f0ddb1c(u32 *arg0, u32 arg1);
void hudmsgsHideByChannel(s32 value);
void hudmsgsInit(void);
void hudmsgRemoveAll(void);
s32 hudmsgGetNext(s32 refid);
void hudmsgCreate(char *text, s32 type);
void hudmsgCreateWithFlags(char *text, s32 type, u32 flags);
void hudmsgCreateWithColour(char *text, s32 type, u8 colour);
void hudmsgCreateWithDuration(char *text, s32 type, struct hudmsgtype *config, s32 duration60);
u32 func0f0de160(void);
void hudmsgCalculatePosition(struct hudmessage *msg);
void hudmsgCreateFromArgs(char *text, s32 type, s32 conf00, s32 conf01, s32 conf02,
		struct hudmessagething *conf04, struct hudmessagething *conf08,
		u32 textcolour, u32 shadowcolour,
		u32 alignh, s32 conf16, u32 alignv, s32 conf18, s32 arg14, u32 flags);
void hudmsgsTick(void);
void currentPlayerSetHudmsgsOn(u32 reason);
void currentPlayerSetHudmsgsOff(u32 reason);
void hudmsgRemoveForDeadPlayer(s32 playernum);
Gfx *hudmsgsRender(Gfx *gdl);
void hudmsgsReset(void);

#endif
