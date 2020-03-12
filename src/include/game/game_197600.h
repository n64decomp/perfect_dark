#ifndef IN_GAME_GAME_197600_H
#define IN_GAME_GAME_197600_H
#include <ultra64.h>
#include "types.h"

u32 func0f197600(void);
void mpAibotApplyCommand(struct chrdata *chr, u32 command);
void func0f197c00(struct chrdata *chr);
u32 func0f197c70(void);
u32 func0f197cf0(void);
u32 func0f197d94(void);
bool chrHasWeapon(struct chrdata *chr, u32 weaponnum);
u32 func0f197e8c(void);
void chrGiveDualWeapon(struct chrdata *chr, u32 weaponnum);
u32 chrGetWeaponPad(struct chrdata *chr, u32 weaponnum);
void chrGiveWeapon(struct chrdata *chr, struct prop *prop);
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
