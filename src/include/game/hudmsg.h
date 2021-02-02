#ifndef IN_GAME_HUDMSG_H
#define IN_GAME_HUDMSG_H
#include <ultra64.h>
#include "types.h"

u8 func0f0dcdb0(void);
s32 hudIsZoomRangeVisible(void);
Gfx *hudRenderMissionTimer(Gfx *gdl, u32 arg1);
Gfx *hudRenderZoomRange(Gfx *gdl, s32 arg1);
Gfx *hudRenderMessageBox(Gfx *gdl, s32 x, s32 y, s32 width, s32 height, f32 bgopacity, u32 bordercolour, f32 textopacity);
s32 func0f0ddb1c(u32 *arg0, u32 arg1);
void func0f0ddd44(s32 value);
void hudmsgsInit(void);
void hudmsgRemoveAll(void);
s32 hudmsgGetNext(s32 refid);
void hudmsgCreateViaPreset(char *text, s32 type);
void func0f0ddfa4(char *text, s32 type, s32 arg2);
void hudmsgCreateViaPresetWithColour(char *text, s32 type, u8 colour);
void hudmsgCreateViaStruct(char *text, s32 type, struct hudmessageconfig *config, s32 arg3);
u32 func0f0de160(void);
void func0f0de7fc(struct hudmessage *msg);
void hudmsgCreate(char *text, s32 type, s32 conf00, s32 conf01, s32 conf02,
		struct hudmessagething *conf04, struct hudmessagething *conf08,
		u32 textcolour, u32 shadowcolour,
		u32 alignh, s32 conf16, u32 alignv, s32 conf18, s32 arg14, u32 flags);
void hudmsgsTick(void);
void currentPlayerUnsetFlag(u32 flag);
void currentPlayerSetFlag(u32 flag);
void hudmsgRemoveForDeadPlayer(s32 playernum);
Gfx *hudmsgsRender(Gfx *gdl);
void hudmsgsReset(void);

#endif
