#ifndef IN_GAME_GAME_197600_H
#define IN_GAME_GAME_197600_H
#include <ultra64.h>
#include "types.h"

u32 func0f197600(void);
void mpAibotApplyCommand(struct chrdata *chr, u32 command);
void func0f197c00(struct chrdata *chr);
u32 func0f197c70(void);
struct invitem *aibotGetInvItem(struct chrdata *chr, u32 weaponnum);
u32 func0f197d94(void);
u32 aibotGetInvItemType(struct chrdata *chr, u32 weaponnum);
void func0f197e8c(struct chrdata *chr, u32 weaponnum);
void aibotGiveDualWeapon(struct chrdata *chr, u32 weaponnum);
s16 aibotGetWeaponPad(struct chrdata *chr, u32 weaponnum);
void aibotGiveProp(struct chrdata *chr, struct prop *prop);
u32 func0f198068(void);
u32 func0f198278(void);
u32 func0f1982d4(void);
u32 func0f198338(void);
u32 func0f198db4(void);
u32 func0f198df8(void);
u32 func0f198e38(void);
u32 func0f198e78(void);
u32 func0f198eec(void);
u32 func0f1994b0(void);
u32 func0f19978c(void);
void func0f199964(struct chrdata *chr, u32 arg1);
u32 func0f199984(void);

#endif
