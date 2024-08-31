#ifndef IN_GAME_BOTINV_H
#define IN_GAME_BOTINV_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void botinv_clear(struct chrdata *chr);
struct invitem *botinv_get_item(struct chrdata *chr, s32 weaponnum);
void botinv_remove_item(struct chrdata *chr, s32 weaponnum);
u32 botinv_get_item_type(struct chrdata *chr, u32 weaponnum);
bool botinv_give_single_weapon(struct chrdata *chr, u32 weaponnum);
void botinv_give_dual_weapon(struct chrdata *chr, u32 weaponnum);
s16 botinv_get_weapon_pad(struct chrdata *chr, u32 weaponnum);
bool botinv_give_prop(struct chrdata *chr, struct prop *prop);
void botinv_score_all_weapons(struct chrdata *chr, s32 *weaponnums, s32 *scores1, s32 *scores2);
bool mp_has_shield(void);
s32 mp_get_weapon_slot_by_weapon_num(s32 weaponnum);
void botinv_score_weapon(struct chrdata *chr, s32 weaponnum, s32 funcnum, s32 ifammo, bool dual, s32 *dst1, s32 *dst2, bool arg7, bool learn);
s32 botinv_get_dist_config(s32 weaponnum, s32 funcnum);
bool botinv_allows_weapon(struct chrdata *chr, s32 weaponnum, s32 funcnum);
void botinv_tick(struct chrdata *chr);
bool botinv_switch_to_weapon(struct chrdata *chr, s32 weaponnum, s32 funcnum);
void botinv_drop_all(struct chrdata *chr, u32 weaponnum);
void botinv_drop_one(struct chrdata *chr, u32 weaponnum);

#endif
