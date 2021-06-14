#ifndef IN_GAME_GAME_1657C0_H
#define IN_GAME_GAME_1657C0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

struct var80081058 *func0f1657cc(void);
f32 func0f1657e4(void);
void func0f1657f8(void);
void skyApplyType1(struct skytype1 *sky);
void skyApplyType2(struct skytype2 *sky);
void skySetStageNum(s32 stagenum);
void skyChooseAndApply(s32 stagenum, bool arg1);
void skySetTransitionFrac(f32 arg0);
Gfx *func0f1664a0(Gfx *gdl, bool arg1);
Gfx *gfxConsiderDisableFog(Gfx *gdl);
bool func0f1666f8(struct coord *pos, f32 arg1);
struct coord *func0f1667e8(void);
s32 func0f1667f4(struct prop *prop, f32 *arg1);

#endif
