#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/bondgun.h"
#include "game/game_0b0fd0.h"
#include "game/inv.h"
#include "game/training.h"
#include "game/lang.h"
#include "bss.h"
#include "lib/main.h"
#include "data.h"
#include "types.h"

void inv_clear(void)
{
	s32 i;

	for (i = 0; i < g_Vars.currentplayer->equipmaxitems; i++) {
		g_Vars.currentplayer->equipment[i].type = -1;
	}

	g_Vars.currentplayer->weapons = NULL;
	g_Vars.currentplayer->equipcuritem = 0;
}

/**
 * Sorts subject into its correct position in the inventory list.
 *
 * Subject is expected to initially be at the head of the list. It works by
 * swapping the subject with the item to its right as many times as needed.
 */
void inv_sort_item(struct invitem *subject)
{
	struct invitem *candidate;
	s32 subjweapon1 = -1;
	s32 subjweapon2 = -1;
	s32 candweapon1;
	s32 candweapon2;

	// Prepare subject's properties for comparisons
	if (subject->type == INVITEMTYPE_WEAP) {
		subjweapon1 = subject->type_weap.weapon1;
	} else if (subject->type == INVITEMTYPE_DUAL) {
		subjweapon1 = subject->type_dual.weapon1;
		subjweapon2 = subject->type_dual.weapon2;
	} else if (subject->type == INVITEMTYPE_PROP) {
		subjweapon1 = 2000;
	}

	candidate = subject->next;

	while (g_Vars.currentplayer->weapons != subject->next) {
		// Prepare candidate's properties for comparisons
		candweapon1 = -1;
		candweapon2 = -1;

		if (subject->next->type == INVITEMTYPE_WEAP) {
			candweapon1 = subject->next->type_weap.weapon1;
		} else if (subject->next->type == INVITEMTYPE_DUAL) {
			candweapon1 = subject->next->type_dual.weapon1;
			candweapon2 = subject->next->type_dual.weapon2;
		} else if (subject->next->type == INVITEMTYPE_PROP) {
			candweapon1 = 1000;
		}

		// If the candidate should sort ahead of subject
		// then subject is in the desired position.
		if (candweapon1 >= subjweapon1 &&
				(subjweapon1 != candweapon1 || subjweapon2 <= candweapon2)) {
			return;
		}

		// If there's only two items in the list then there's no point swapping
		// them. Just set the list head to the candidate.
		if (candidate->next == subject) {
			g_Vars.currentplayer->weapons = candidate;
		} else {
			// Swap subject with candidate
			subject->next = candidate->next;
			candidate->prev = subject->prev;
			subject->prev = candidate;
			candidate->next = subject;
			subject->next->prev = subject;
			candidate->prev->next = candidate;

			// Set new list head if subject was the head
			if (subject == g_Vars.currentplayer->weapons) {
				g_Vars.currentplayer->weapons = candidate;
			}
		}

		candidate = subject->next;
	}
}

void inv_insert_item(struct invitem *item)
{
	if (item->type == INVITEMTYPE_PROP) {
		struct prop *prop = item->type_prop.prop;

		if (prop && prop->obj) {
			struct textoverride *override = inv_get_text_override_for_obj(prop->obj);
			bool setflag = true;

			if (override) {
				if (override->weapon >= WEAPON_UNARMED && override->weapon <= WEAPON_NECKLACE) {
					setflag = false;
				}
				if (override->weapon == WEAPON_MPSHIELD) {
					setflag = false;
				}
				if (override->weapon == WEAPON_SUICIDEPILL) {
					setflag = false;
				}
				if (override->weapon == WEAPON_BRIEFCASE2) {
					setflag = false;
				}
			}

			if (setflag && prop->type == PROPTYPE_OBJ) {
				struct defaultobj *obj = prop->obj;
				obj->flags2 |= OBJFLAG2_INVHIDDEN;
			}
		}
	}

	// Place item at head of weapons list
	if (g_Vars.currentplayer->weapons) {
		item->next = g_Vars.currentplayer->weapons;
		item->prev = g_Vars.currentplayer->weapons->prev;
		item->next->prev = item;
		item->prev->next = item;
	} else {
		item->next = item;
		item->prev = item;
	}

	g_Vars.currentplayer->weapons = item;

	inv_sort_item(item);
	inv_calculate_current_index();
}

void inv_remove_item(struct invitem *item)
{
	struct invitem *next = item->next;
	struct invitem *prev = item->prev;

	if (g_Vars.currentplayer->weapons == item) {
		if (item == item->next) {
			g_Vars.currentplayer->weapons = NULL;
		} else {
			g_Vars.currentplayer->weapons = item->next;
		}
	}

	next->prev = prev;
	prev->next = next;
	item->type = -1;

	inv_calculate_current_index();
}

struct invitem *inv_find_unused_slot(void)
{
	s32 i;

	for (i = 0; i < g_Vars.currentplayer->equipmaxitems; i++) {
		if (g_Vars.currentplayer->equipment[i].type == -1) {
			return &g_Vars.currentplayer->equipment[i];
		}
	}

	return NULL;
}

void inv_set_all_guns(bool enable)
{
	s32 weaponnum;

	g_Vars.currentplayer->equipallguns = enable;
	inv_calculate_current_index();
	weaponnum = inv_get_weapon_num_by_index(g_Vars.currentplayer->equipcuritem);
	bgun_equip_weapon(weaponnum);
}

bool inv_has_all_guns(void)
{
	return g_Vars.currentplayer->equipallguns;
}

struct invitem *inv_find_single_weapon(s32 weaponnum)
{
	struct invitem *first = g_Vars.currentplayer->weapons;
	struct invitem *item = first;

	while (item) {
		if (item->type == INVITEMTYPE_WEAP && item->type_weap.weapon1 == weaponnum) {
			return item;
		}

		item = item->next;

		if (item == first) {
			break;
		}
	}

	return NULL;
}

bool inv_has_single_weapon_exc_all_guns(s32 weaponnum)
{
	return inv_find_single_weapon(weaponnum) != NULL;
}

struct invitem *inv_find_double_weapon(s32 weapon1, s32 weapon2)
{
	struct invitem *first = g_Vars.currentplayer->weapons;
	struct invitem *item = first;

	while (item) {
		if (item->type == INVITEMTYPE_DUAL
				&& item->type_dual.weapon1 == weapon1
				&& item->type_dual.weapon2 == weapon2) {
			return item;
		}

		item = item->next;

		if (item == first) {
			break;
		}
	}

	return NULL;
}

bool inv_has_double_weapon_exc_all_guns(s32 weapon1, s32 weapon2)
{
	return inv_find_double_weapon(weapon1, weapon2) != NULL;
}

bool inv_has_single_weapon_or_prop(s32 weaponnum)
{
	struct invitem *item = g_Vars.currentplayer->weapons;

	while (item) {
		if (item->type == INVITEMTYPE_WEAP) {
			if (weaponnum == item->type_weap.weapon1) {
				return true;
			}
		} else if (item->type == INVITEMTYPE_PROP) {
			struct prop *prop = item->type_prop.prop;

			if (prop && prop->type == PROPTYPE_WEAPON) {
				struct defaultobj *obj = prop->obj;

				if (obj && obj->type == OBJTYPE_WEAPON) {
					struct weaponobj *weapon = (struct weaponobj *)prop->obj;

					if (weapon->weaponnum == weaponnum) {
						return true;
					}
				}
			}
		}

		item = item->next;

		if (item == g_Vars.currentplayer->weapons) {
			break;
		}
	}

	return false;
}

s32 inv_add_one_if_cant_have_slayer(s32 index)
{
	if (main_get_stage_num());

	if (main_get_stage_num() != STAGE_ATTACKSHIP
			&& main_get_stage_num() != STAGE_SKEDARRUINS
			&& index >= WEAPON_SLAYER) {
		index++;
	}

#if VERSION >= VERSION_JPN_FINAL
	if (index >= 26) {
		index++;
	}
#endif

	return index;
}

s32 current_stage_forbids_slayer(void)
{
	bool value = VERSION >= VERSION_JPN_FINAL ? 1 : 0;

	if (main_get_stage_num() != STAGE_ATTACKSHIP && main_get_stage_num() != STAGE_SKEDARRUINS) {
		value++;
	}

	return value;
}

bool inv_can_have_all_guns_weapon(s32 weaponnum)
{
	bool canhave = true;

#if VERSION == VERSION_JPN_FINAL
	if (weaponnum == WEAPON_COMBATKNIFE) {
		canhave = false;
	}
#endif

	if (weaponnum == WEAPON_SLAYER) {
		canhave = false;
	}

	// @bug: The stage conditions need an OR. This condition can never pass.
	if ((main_get_stage_num() == STAGE_ATTACKSHIP && main_get_stage_num() == STAGE_SKEDARRUINS)
			&& weaponnum == WEAPON_SLAYER) {
		canhave = true;
	}

	return canhave;
}

bool inv_has_single_weapon_inc_all_guns(s32 weaponnum)
{
	if (g_Vars.currentplayer->equipallguns &&
			weaponnum && weaponnum <= WEAPON_PSYCHOSISGUN &&
			inv_can_have_all_guns_weapon(weaponnum)) {
		return true;
	}

	return inv_has_single_weapon_exc_all_guns(weaponnum);
}

bool inv_has_double_weapon_inc_all_guns(s32 weapon1, s32 weapon2)
{
	if (weapon2 == WEAPON_NONE) {
		return true;
	}

	if (g_Vars.currentplayer->equipallguns &&
			weapon1 <= WEAPON_PSYCHOSISGUN &&
			weapon1 == weapon2 &&
			weapon_has_flag(weapon1, WEAPONFLAG_DUALWIELD) &&
			inv_can_have_all_guns_weapon(weapon1)) {
		return true;
	}

	return inv_has_double_weapon_exc_all_guns(weapon1, weapon2);
}

bool inv_give_single_weapon(s32 weaponnum)
{
	fr_set_weapon_found(weaponnum);

	if (inv_has_single_weapon_exc_all_guns(weaponnum) == 0) {
		struct invitem *item;

		if (g_Vars.currentplayer->equipallguns &&
				weaponnum <= WEAPON_PSYCHOSISGUN &&
				inv_can_have_all_guns_weapon(weaponnum)) {
			return false;
		}

		item = inv_find_unused_slot();

		if (item) {
			item->type = INVITEMTYPE_WEAP;
			item->type_weap.weapon1 = weaponnum;
			item->type_weap.pickuppad = -1;
			inv_insert_item(item);
		}

		return true;
	}

	return false;
}

bool inv_give_double_weapon(s32 weapon1, s32 weapon2)
{
	if (inv_has_double_weapon_exc_all_guns(weapon1, weapon2) == 0) {
		if (weapon_has_flag(weapon1, WEAPONFLAG_DUALWIELD)) {
			struct invitem *item = inv_find_unused_slot();

			if (item) {
				item->type = INVITEMTYPE_DUAL;
				item->type_dual.weapon1 = weapon1;
				item->type_dual.weapon2 = weapon2;
				inv_insert_item(item);
			}

			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}

	return false;
}

void inv_remove_item_by_num(s32 weaponnum)
{
	if (g_Vars.currentplayer->weapons) {
		// Begin iterating from the second item in the list. This is required
		// because the item might be removed from the list when iterating it,
		// and it needs to determine when the end of the list has been reached.
		struct invitem *item = g_Vars.currentplayer->weapons->next;

		while (true) {
			// Have to preload this because item->next shouldn't be trusted
			// after calling inv_remove_item()
			struct invitem *next = item->next;

			if (item->type == INVITEMTYPE_PROP) {
				struct prop *prop = item->type_prop.prop;
				struct textoverride *override = inv_get_text_override_for_obj(prop->obj);

				if (override && override->weapon == weaponnum) {
					inv_remove_item(item);
				}
			} else if (item->type == INVITEMTYPE_WEAP) {
				if (item->type_weap.weapon1 == weaponnum) {
					inv_remove_item(item);
				}
			} else if (item->type == INVITEMTYPE_DUAL) {
				if (item->type_dual.weapon1 == weaponnum || item->type_dual.weapon2 == weaponnum) {
					inv_remove_item(item);
				}
			}

			if (item == g_Vars.currentplayer->weapons || !g_Vars.currentplayer->weapons) {
				break;
			}

			item = next;
		}
	}
}

bool inv_give_prop(struct prop *prop)
{
	struct invitem *item;

	// Don't add duplicate night vision to inventory
	// (night vision is already there when using perfect darkness)
	// Note that this check doesn't work on Investigation because it uses the
	// IR specs model. See bug note in Investigation's setup file (setupear.c).
	if (cheat_is_active(CHEAT_PERFECTDARKNESS)
			&& prop->type == PROPTYPE_OBJ
			&& prop->obj
			&& prop->obj->modelnum == MODEL_CHRNIGHTSIGHT) {
		return true;
	}

	item = inv_find_unused_slot();

	if (item) {
		item->type = INVITEMTYPE_PROP;
		item->type_prop.prop = prop;
		inv_insert_item(item);
	}

	return true;
}

void inv_remove_prop(struct prop *prop)
{
	if (g_Vars.currentplayer->weapons) {
		struct invitem *item = g_Vars.currentplayer->weapons->next;

		while (true) {
			struct invitem *next = item->next;

			if (item->type == INVITEMTYPE_PROP && item->type_prop.prop == prop) {
				inv_remove_item(item);
			}

			if (item == g_Vars.currentplayer->weapons || !g_Vars.currentplayer->weapons) {
				break;
			}

			item = next;
		}
	}
}

s32 inv_give_weapons_by_prop(struct prop *prop)
{
	s32 numgiven = 0;

	if (prop->type == PROPTYPE_WEAPON) {
		struct defaultobj *obj = prop->obj;
		struct weaponobj *weapon;
		struct weaponobj *otherweapon;
		s32 weaponnum;
		s32 otherweaponnum;

		if (obj->type == OBJTYPE_WEAPON) {
			weapon = prop->weapon;
			weaponnum = weapon->weaponnum;
			otherweaponnum;

			if (cheat_is_active(CHEAT_PERFECTDARKNESS) && weaponnum == WEAPON_NIGHTVISION) {
				return 1;
			}

			if (inv_give_single_weapon(weaponnum)) {
				numgiven = 1;
			}

			if (g_Vars.normmplayerisrunning
					&& weapon_has_flag(weaponnum, WEAPONFLAG_DUALWIELD)
					&& !inv_has_double_weapon_exc_all_guns(weaponnum, weaponnum)) {
				struct invitem *invitem = inv_find_single_weapon(weaponnum);

				if (invitem) {
					if (invitem->type_weap.pickuppad < 0) {
						if (obj->pad >= 0) {
							invitem->type_weap.pickuppad = obj->pad;
						}
					} else if (obj->pad >= 0 && invitem->type_weap.pickuppad != obj->pad) {
						if (inv_give_double_weapon(weaponnum, weaponnum)) {
							numgiven = 2;
						} else {
							numgiven = 0;
						}
					}
				}
			}

			otherweapon = weapon->dualweapon;

			if (otherweapon) {
				if (weapon->base.flags & OBJFLAG_WEAPON_LEFTHANDED) {
					numgiven = inv_has_double_weapon_exc_all_guns(otherweapon->weaponnum, weaponnum) == 0;
				} else {
					numgiven = inv_has_double_weapon_exc_all_guns(weaponnum, otherweapon->weaponnum) == 0;
				}

				weapon->dualweapon->dualweaponnum = weaponnum;
				weapon->dualweapon->dualweapon = NULL;
				weapon->dualweapon = NULL;
			} else if (weapon->dualweaponnum >= 0) {
				if (weapon->base.flags & OBJFLAG_WEAPON_LEFTHANDED) {
					if (inv_give_double_weapon(weapon->dualweaponnum, weaponnum)) {
						numgiven = 2;
					} else {
						numgiven = 0;
					}
				} else {
					if (inv_give_double_weapon(weaponnum, weapon->dualweaponnum)) {
						numgiven = 2;
					} else {
						numgiven = 0;
					}
				}
			}
		}
	}

	return numgiven;
}

void inv_choose_cycle_forward_weapon(s32 *ptr1, s32 *ptr2, bool arg2)
{
	s32 weapon1 = *ptr1;
	s32 weapon2 = *ptr2;

	if (g_Vars.currentplayer->equipallguns) {
		s32 candidate = *ptr1;

		if (weapon_has_flag(*ptr1, WEAPONFLAG_DUALWIELD) && *ptr2 != *ptr1) {
			// Switching to dual from single
			weapon1 = *ptr1;
			weapon2 = *ptr1;
		} else {
			// Find next weapon
			do {
				candidate = (candidate + 1) % NUM_CYCLEABLE_WEAPONS;

				if (candidate == WEAPON_NONE) {
					candidate = (candidate + 1) % NUM_CYCLEABLE_WEAPONS;
				}

				if ((!arg2 || bgun0f0a1a10(candidate)) && inv_can_have_all_guns_weapon(candidate)) {
					weapon1 = candidate;
					weapon2 = WEAPON_NONE;
					break;
				}
			} while (candidate != weapon1);
		}
	} else {
		struct invitem *item = g_Vars.currentplayer->weapons;

		while (item) {
			if (item->type == INVITEMTYPE_WEAP) {
				if (item->type_weap.weapon1 < NUM_CYCLEABLE_WEAPONS && item->type_weap.weapon1 > weapon1) {
					if (!arg2 || bgun0f0a1a10(item->type_weap.weapon1)) {
						weapon1 = item->type_weap.weapon1;
						weapon2 = WEAPON_NONE;
						break;
					}
				}
			} else if (item->type == INVITEMTYPE_DUAL) {
				if (item->type_dual.weapon1 > weapon1
						|| (weapon1 == item->type_dual.weapon1 && item->type_dual.weapon2 > weapon2)) {
					if (!arg2 || bgun0f0a1a10(item->type_dual.weapon1) || bgun0f0a1a10(item->type_dual.weapon2)) {
						weapon1 = item->type_dual.weapon1;
						weapon2 = item->type_dual.weapon2;
						break;
					}
				}
			}

			item = item->next;

			if (item == g_Vars.currentplayer->weapons) {
				if (arg2) {
					break;
				}

				weapon1 = -1;
				weapon2 = -1;
			}
		}
	}

	*ptr1 = weapon1;
	*ptr2 = weapon2;
}

void inv_choose_cycle_back_weapon(s32 *ptr1, s32 *ptr2, bool arg2)
{
	s32 weapon1 = *ptr1;
	s32 weapon2 = *ptr2;

	if (g_Vars.currentplayer->equipallguns) {
		s32 candidate = *ptr1;

		if (weapon_has_flag(weapon1, WEAPONFLAG_DUALWIELD) && weapon1 == weapon2) {
			// Switching from dual to single
			weapon1 = candidate;
			weapon2 = WEAPON_NONE;
		} else {
			// Find prev weapon
			do {
				candidate = (candidate + NUM_CYCLEABLE_WEAPONS - 1) % NUM_CYCLEABLE_WEAPONS;

				if (candidate == WEAPON_NONE) {
					candidate = (candidate + NUM_CYCLEABLE_WEAPONS - 1) % NUM_CYCLEABLE_WEAPONS;
				}
			} while ((arg2 && !bgun0f0a1a10(candidate)) || !inv_can_have_all_guns_weapon(candidate));

			if (weapon_has_flag(candidate, WEAPONFLAG_DUALWIELD)) {
				weapon1 = candidate;
				weapon2 = candidate;
			} else {
				weapon1 = candidate;
				weapon2 = WEAPON_NONE;
			}
		}
	} else if (g_Vars.currentplayer->weapons != NULL) {
		struct invitem *item = g_Vars.currentplayer->weapons->prev;

		while (true) {
			if (item->type == INVITEMTYPE_WEAP) {
				if (item->type_weap.weapon1 < NUM_CYCLEABLE_WEAPONS
						&& (item->type_weap.weapon1 < weapon1 || (weapon1 == item->type_weap.weapon1 && weapon2 > 0))) {
					if (!arg2 || bgun0f0a1a10(item->type_weap.weapon1)) {
						weapon1 = item->type_weap.weapon1;
						weapon2 = WEAPON_NONE;
						break;
					}
				}
			} else if (item->type == INVITEMTYPE_DUAL) {
				if (item->type_dual.weapon1 < weapon1
						|| (weapon1 == item->type_dual.weapon1 && item->type_dual.weapon2 < weapon2)) {
					if (!arg2 || bgun0f0a1a10(item->type_dual.weapon1) || bgun0f0a1a10(item->type_dual.weapon2)) {
						weapon1 = item->type_dual.weapon1;
						weapon2 = item->type_dual.weapon2;
						break;
					}
				}
			}

			if (item == g_Vars.currentplayer->weapons) {
				if (arg2) {
					break;
				}

				weapon1 = 1000;
				weapon2 = 1000;
			}

			item = item->prev;
		}
	}

	*ptr1 = weapon1;
	*ptr2 = weapon2;
}

bool inv_has_key_flags(u32 wantkeyflags)
{
	u32 heldkeyflags = 0;
	struct invitem *item = g_Vars.currentplayer->weapons;

	while (item) {
		if (item->type == INVITEMTYPE_PROP) {
			struct prop *prop = item->type_prop.prop;

			if (prop && prop->type == PROPTYPE_OBJ) {
				struct defaultobj *obj = prop->obj;

				if (obj && obj->type == OBJTYPE_KEY) {
					struct keyobj *key = (struct keyobj *)prop->obj;

					heldkeyflags |= key->keyflags;

					if ((wantkeyflags & heldkeyflags) == wantkeyflags) {
						return true;
					}
				}
			}
		}

		item = item->next;

		if (item == g_Vars.currentplayer->weapons) {
			break;
		}
	}

	return false;
}

bool inv_has_goldeneyekey(void)
{
	return false;
}

bool inv_has_briefcase(void)
{
	if (g_Vars.currentplayer->isdead == false) {
		return inv_has_single_weapon_exc_all_guns(WEAPON_BRIEFCASE2);
	}

	return false;
}

bool inv_has_data_uplink(void)
{
	if (g_Vars.currentplayer->isdead == false) {
		return inv_has_single_weapon_exc_all_guns(WEAPON_DATAUPLINK);
	}

	return false;
}

bool inv_has_goldengun(void)
{
	return false;
}

bool inv_has_prop(struct prop *prop)
{
	struct invitem *item = g_Vars.currentplayer->weapons;
	struct prop *child;

	while (item) {
		if (item->type == INVITEMTYPE_PROP && item->type_prop.prop == prop) {
			return true;
		}

		item = item->next;

		if (item == g_Vars.currentplayer->weapons) {
			break;
		}
	}

	child = g_Vars.currentplayer->prop->child;

	while (child) {
		if (child == prop) {
			return true;
		}

		child = child->next;
	}

	return false;
}

s32 inv_get_count(void)
{
	s32 numitems = 0;
	struct invitem *item;

	if (g_Vars.currentplayer->equipallguns) {
		numitems = WEAPON_PSYCHOSISGUN - current_stage_forbids_slayer();
	}

	item = g_Vars.currentplayer->weapons;

	while (item) {
		if (item->type == INVITEMTYPE_PROP) {
			struct prop *prop = item->type_prop.prop;

			if (prop) {
				struct defaultobj *obj = prop->obj;

				if (obj) {
					if (prop->type == PROPTYPE_WEAPON) {
						if (obj->hidden & OBJHFLAG_HASTEXTOVERRIDE) {
							numitems++;
						}
					} else if (prop->type == PROPTYPE_OBJ) {
						if ((obj->flags2 & OBJFLAG2_INVHIDDEN) == 0) {
							numitems++;
						}
					}
				}
			}
		} else if (item->type == INVITEMTYPE_WEAP) {
			if (g_Vars.currentplayer->equipallguns == false
					|| item->type_weap.weapon1 > WEAPON_PSYCHOSISGUN) {
				numitems++;
			}
		}

		item = item->next;

		if (item == g_Vars.currentplayer->weapons) {
			break;
		}
	}

	return numitems;
}

struct invitem *inv_get_item_by_index(s32 index)
{
	struct invitem *item;

	if (g_Vars.currentplayer->equipallguns) {
		if (index < WEAPON_PSYCHOSISGUN - current_stage_forbids_slayer()) {
			return NULL;
		}

		index += current_stage_forbids_slayer() - WEAPON_PSYCHOSISGUN;
	}

	item = g_Vars.currentplayer->weapons;

	while (item) {
		if (item->type == INVITEMTYPE_PROP) {
			struct prop *prop = item->type_prop.prop;

			if (prop) {
				struct defaultobj *obj = prop->obj;

				if (obj) {
					if (prop->type == PROPTYPE_WEAPON) {
						if (obj->hidden & OBJHFLAG_HASTEXTOVERRIDE) {
							if (index == 0) {
								return item;
							}
							index--;
						}
					} else if (prop->type == PROPTYPE_OBJ) {
						if ((obj->flags2 & OBJFLAG2_INVHIDDEN) == 0) {
							if (index == 0) {
								return item;
							}
							index--;
						}
					}
				}
			}
		} else if (item->type == INVITEMTYPE_WEAP) {
			if (g_Vars.currentplayer->equipallguns == false
					|| item->type_weap.weapon1 > WEAPON_PSYCHOSISGUN) {
				if (index == 0) {
					return item;
				}
				index--;
			}
		}

		item = item->next;

		if (item == g_Vars.currentplayer->weapons) {
			break;
		}
	}

	return NULL;
}

struct textoverride *inv_get_text_override_for_obj(struct defaultobj *obj)
{
	struct textoverride *override = g_Vars.textoverrides;

	while (override) {
		if (override->obj == obj) {
			return override;
		}

		override = override->next;
	}

	return NULL;
}

struct textoverride *inv_get_text_override_for_weapon(s32 weaponnum)
{
	struct textoverride *override = g_Vars.textoverrides;

	while (override) {
		if (override->objoffset == 0 && override->weapon == weaponnum) {
			return override;
		}

		override = override->next;
	}

	return NULL;
}

s32 inv_get_weapon_num_by_index(s32 index)
{
	struct invitem *item = inv_get_item_by_index(index);

	if (item) {
		if (item->type == INVITEMTYPE_PROP) {
			struct prop *prop = item->type_prop.prop;
			struct textoverride *override = inv_get_text_override_for_obj(prop->obj);

			if (override) {
				return override->weapon;
			}
		} else if (item->type == INVITEMTYPE_WEAP) {
			return item->type_weap.weapon1;
		}
	} else if (g_Vars.currentplayer->equipallguns) {
		if (index < WEAPON_PSYCHOSISGUN - current_stage_forbids_slayer()) {
			index++;
			return inv_add_one_if_cant_have_slayer(index);
		}
	}

	return 0;
}

u16 inv_get_name_id_by_index(s32 index)
{
	struct invitem *item = inv_get_item_by_index(index);
	s32 weaponnum = 0;
	struct textoverride *override;

	if (item) {
		if (item->type == INVITEMTYPE_PROP) {
			struct prop *prop = item->type_prop.prop;
			override = inv_get_text_override_for_obj(prop->obj);

			if (override) {
				if (override->inventorytext) {
					return override->inventorytext;
				}

				weaponnum = override->weapon;
			}
		} else if (item->type == INVITEMTYPE_WEAP) {
			weaponnum = item->type_weap.weapon1;
			override = inv_get_text_override_for_weapon(weaponnum);

			if (override && override->inventorytext) {
				return override->inventorytext;
			}
		}
	} else {
		if (g_Vars.currentplayer->equipallguns) {
			if (index < WEAPON_PSYCHOSISGUN - current_stage_forbids_slayer()) {
				index++;
				return bgun_get_name_id(inv_add_one_if_cant_have_slayer(index));
			}
		}
	}

	return bgun_get_name_id(weaponnum);
}

char *inv_get_name_by_index(s32 index)
{
	return lang_get(inv_get_name_id_by_index(index));
}

char *inv_get_short_name_by_index(s32 index)
{
	struct invitem *item = inv_get_item_by_index(index);
	s32 weaponnum = 0;
	struct textoverride *override;

	if (item) {
		if (item->type == INVITEMTYPE_PROP) {
			struct prop *prop = item->type_prop.prop;
			override = inv_get_text_override_for_obj(prop->obj);

			if (override) {
#if VERSION < VERSION_JPN_FINAL
				if (override->inventorytext) {
					return lang_get(override->inventorytext);
				}
#endif

				weaponnum = override->weapon;
			}
		} else if (item->type == INVITEMTYPE_WEAP) {
			weaponnum = item->type_weap.weapon1;
#if VERSION < VERSION_JPN_FINAL
			override = inv_get_text_override_for_weapon(weaponnum);

			if (override && override->inventorytext) {
				return lang_get(override->inventorytext);
			}
#endif
		}
	} else if (g_Vars.currentplayer->equipallguns) {
		if (index < WEAPON_PSYCHOSISGUN - current_stage_forbids_slayer()) {
			index++;
			return bgun_get_short_name(inv_add_one_if_cant_have_slayer(index));
		}
	}

	return bgun_get_short_name(weaponnum);
}

void inv_insert_text_override(struct textoverride *override)
{
	override->next = g_Vars.textoverrides;
	g_Vars.textoverrides = override;
}

u32 inv_get_current_index(void)
{
	return g_Vars.currentplayer->equipcuritem;
}

void inv_set_current_index(u32 item)
{
	g_Vars.currentplayer->equipcuritem = item;
}

void inv_calculate_current_index(void)
{
	s32 curweaponnum = bgun_get_weapon_num(HAND_RIGHT);
	s32 i;

	g_Vars.currentplayer->equipcuritem = 0;

	for (i = 0; i < inv_get_count(); i++) {
		if (inv_get_weapon_num_by_index(i) == curweaponnum) {
			g_Vars.currentplayer->equipcuritem = i;
			break;
		}
	}
}

char *inv_get_pickup_text_by_obj(struct defaultobj *obj)
{
	struct textoverride *override = inv_get_text_override_for_obj(obj);

	if (override && override->pickuptext) {
		return lang_get(override->pickuptext);
	}

	return NULL;
}

char *inv_get_pickup_text_by_weapon_num(s32 weaponnum)
{
	struct textoverride *override = inv_get_text_override_for_weapon(weaponnum);

	if (override && override->pickuptext) {
		return lang_get(override->pickuptext);
	}

	return NULL;
}

void inv_increment_held_time(s32 weapon1, s32 weapon2)
{
	s32 leastusedtime;
	s32 leastusedindex;
	s32 i;

	if (!weapon_has_flag(weapon1, WEAPONFLAG_TRACKTIMEUSED)) {
		return;
	}

	leastusedtime = 0x7fffffff;
	leastusedindex = 0;

	if (!weapon_has_flag(weapon2, WEAPONFLAG_TRACKTIMEUSED)) {
		weapon2 = 0;
	}

	for (i = 0; i < ARRAYCOUNT(g_Vars.currentplayer->gunheldarr); i++) {
		s32 time = g_Vars.currentplayer->gunheldarr[i].totaltime240_60;

		if (time >= 0) {
			if (weapon1 == g_Vars.currentplayer->gunheldarr[i].weapon1 &&
					weapon2 == g_Vars.currentplayer->gunheldarr[i].weapon2) {
				g_Vars.currentplayer->gunheldarr[i].totaltime240_60 = time + g_Vars.lvupdate60;
				break;
			}

			if (time < leastusedtime) {
				leastusedtime = time;
				leastusedindex = i;
			}
		} else {
			leastusedindex = i;
			i = ARRAYCOUNT(g_Vars.currentplayer->gunheldarr);
			break;
		}
	}

	if (i == ARRAYCOUNT(g_Vars.currentplayer->gunheldarr)) {
		g_Vars.currentplayer->gunheldarr[leastusedindex].totaltime240_60 = g_Vars.lvupdate60;
		g_Vars.currentplayer->gunheldarr[leastusedindex].weapon1 = weapon1;
		g_Vars.currentplayer->gunheldarr[leastusedindex].weapon2 = weapon2;
	}
}

void inv_get_weapon_of_choice(s32 *weapon1, s32 *weapon2)
{
	s32 mosttime = -1;
	s32 i;

	*weapon1 = 0;
	*weapon2 = 0;

	for (i = 0; i < ARRAYCOUNT(g_Vars.currentplayer->gunheldarr); i++) {
		if (g_Vars.currentplayer->gunheldarr[i].totaltime240_60 >= 0
				&& g_Vars.currentplayer->gunheldarr[i].totaltime240_60 > mosttime) {
			mosttime = g_Vars.currentplayer->gunheldarr[i].totaltime240_60;
			*weapon1 = g_Vars.currentplayer->gunheldarr[i].weapon1;
			*weapon2 = g_Vars.currentplayer->gunheldarr[i].weapon2;
		}
	}
}
