#ifndef IN_GAME_GAME_0B0420_H
#define IN_GAME_GAME_0B0420_H
#include <ultra64.h>
#include "types.h"

u32 func0f0b0420(void);
u32 func0f0b046c(void);
u32 func0f0b0520(void);
u32 func0f0b052c(void);
void incrementKillCount(void);
void incrementKnockoutCount(void);
void decrementKnockoutCount(void);
u8 getKnockoutCount(void);
u32 getKillCount(void);
u32 func0f0b05a4(void);
u32 func0f0b073c(void);
u32 func0f0b0764(void);
u32 func0f0b0818(void);
s32 func0f0b09f4(s32 arg0, s32 arg1);
struct weapon *weaponFindById(s32 itemid);
struct inventory_function *weaponGetFunctionById(s32 weapon_id, s32 which);
u32 func0f0b103c(void);
u32 func0f0b107c(void);
u32 func0f0b10b8(void);
u32 func0f0b10ec(void);
u32 func0f0b11bc(void);
u32 func0f0b11ec(void);
u32 func0f0b12ec(void);
u32 func0f0b131c(void);
u32 func0f0b14d8(void);
u32 func0f0b1588(void);
u32 func0f0b16a4(void);
bool weaponHasFlag(s32 itemid, u32 flag);
u32 func0f0b1804(void);
u32 func0f0b184c(void);
u32 currentPlayerHasWeaponEquipped(u32 arg0);
u32 func0f0b1948(void);
u32 func0f0b1a18(void);
u32 func0f0b1ad0(void);
u32 func0f0b1af0(void);
u32 func0f0b1c24(void);
u32 func0f0b1c78(void);
u32 func0f0b1ce8(void);
u32 func0f0b1d28(s32 weapon_id);
u32 func0f0b1e28(void);
u32 func0f0b1e68(void);
u32 func0f0b1ea8(void);
u32 func0f0b1ee8(void);
u32 func0f0b1f58(void);
u32 func0f0b201c(void);
u32 func0f0b20e8(void);
u32 func0f0b2118(void);

#endif
