#ifndef IN_GAME_INV_H
#define IN_GAME_INV_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern struct noisesettings invnoisesettings_silent;
extern struct invaimsettings invaimsettings_default;
extern struct weapondef *g_Weapons[WEAPON_SUICIDEPILL + 1];

void inv_reset(void);
void inv_init(s32 numdoubles);

void inv_clear(void);
void inv_set_all_guns(bool enable);
struct invitem *inv_find_single_weapon(s32 weaponnum);
bool inv_has_single_weapon_exc_all_guns(s32 weaponnum);
bool inv_has_double_weapon_exc_all_guns(s32 weapon1, s32 weapon2);
bool inv_has_single_weapon_or_prop(s32 weaponnum);
bool inv_has_single_weapon_inc_all_guns(s32 weaponnum);
bool inv_has_double_weapon_inc_all_guns(s32 weapon1, s32 weapon2);
bool inv_give_single_weapon(s32 weaponnum);
bool inv_give_double_weapon(s32 weapon1, s32 weapon2);
void inv_remove_item_by_num(s32 weaponnum);
bool inv_give_prop(struct prop *prop);
void inv_remove_prop(struct prop *prop);
s32 inv_give_weapons_by_prop(struct prop *prop);
void inv_choose_cycle_forward_weapon(s32 *weaponnum1, s32 *weaponnum2, bool arg2);
void inv_choose_cycle_back_weapon(s32 *weaponnum1, s32 *weaponnum2, bool arg2);
bool inv_has_key_flags(u32 wantkeyflags);
bool inv_has_briefcase(void);
bool inv_has_data_uplink(void);
bool inv_has_prop(struct prop *prop);
s32 inv_get_count(void);
struct textoverride *inv_get_text_override_for_obj(struct defaultobj *obj);
s32 inv_get_weapon_num_by_index(s32 index);
u16 inv_get_name_id_by_index(s32 index);
char *inv_get_name_by_index(s32 index);
char *inv_get_short_name_by_index(s32 index);
void inv_insert_text_override(struct textoverride *override);
u32 inv_get_current_index(void);
void inv_set_current_index(u32 item);
void inv_calculate_current_index(void);
char *inv_get_pickup_text_by_obj(struct defaultobj *obj);
char *inv_get_pickup_text_by_weapon_num(s32 weaponnum);
void inv_increment_held_time(s32 param_1, s32 param_2);
void inv_get_weapon_of_choice(s32 *weapon1, s32 *weapon2);

#endif
