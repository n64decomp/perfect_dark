#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_097ba0.h"
#include "game/game_0b0420.h"
#include "game/game_111600.h"
#include "game/game_19c990.h"
#include "game/lang.h"
#include "gvars/gvars.h"
#include "lib/lib_0d520.h"
#include "types.h"

void currentPlayerClearInventory(void)
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
void currentPlayerSortInvItem(struct invitem *subject)
{
	struct invitem *candidate;
	s32 subjweapon1 = -1;
	s32 subjweapon2 = -1;
	s32 candweapon1;
	s32 candweapon2;

	// Prepare subject's properties for comparisons
	if (subject->type == INVITEMTYPE_1) {
		subjweapon1 = subject->type1.weapon1;
	} else if (subject->type == INVITEMTYPE_3) {
		subjweapon1 = subject->type3.weapon1;
		subjweapon2 = subject->type3.weapon2;
	} else if (subject->type == INVITEMTYPE_PROP) {
		subjweapon1 = 2000;
	}

	candidate = subject->next;

	while (g_Vars.currentplayer->weapons != subject->next) {
		// Prepare candidate's properties for comparisons
		candweapon1 = -1;
		candweapon2 = -1;

		if (subject->next->type == INVITEMTYPE_1) {
			candweapon1 = subject->next->type1.weapon1;
		} else if (subject->next->type == INVITEMTYPE_3) {
			candweapon1 = subject->next->type3.weapon1;
			candweapon2 = subject->next->type3.weapon2;
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

void currentPlayerInsertInvItem(struct invitem *item)
{
	if (item->type == INVITEMTYPE_PROP) {
		struct prop *prop = item->type_prop.prop;

		if (prop && prop->obj) {
			struct textoverride *override = objGetTextOverride(prop->obj);
			bool setflag = true;

			if (override) {
				if (override->weapon >= WEAPON_UNARMED && override->weapon <= WEAPON_NECKLACE) {
					setflag = false;
				}
				if (override->weapon == WEAPON_5B) {
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
				obj->flags2 = obj->flags2 | OBJFLAG2_00040000;
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

	currentPlayerSortInvItem(item);
	currentPlayerCalculateEquipCurItem();
}

void currentPlayerRemoveInvItem(struct invitem *item)
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

	currentPlayerCalculateEquipCurItem();
}

struct invitem *currentPlayerGetUnusedInvItem(void)
{
	s32 i;

	for (i = 0; i < g_Vars.currentplayer->equipmaxitems; i++) {
		if (g_Vars.currentplayer->equipment[i].type == -1) {
			return &g_Vars.currentplayer->equipment[i];
		}
	}

	return NULL;
}

void currentPlayerSetAllGuns(bool enable)
{
	s32 weaponnum;

	g_Vars.currentplayer->equipallguns = enable;
	currentPlayerCalculateEquipCurItem();
	weaponnum = currentPlayerGetWeaponNumByInvIndex(g_Vars.currentplayer->equipcuritem);
	currentPlayerEquipWeaponInCutscene(weaponnum);
}

bool currentPlayerHasAllGuns(void)
{
	return g_Vars.currentplayer->equipallguns;
}

struct invitem *currentPlayerGetWeaponInvItem(s32 weaponnum)
{
	struct invitem *first = g_Vars.currentplayer->weapons;
	struct invitem *item = first;

	while (item) {
		if (item->type == INVITEMTYPE_1 && item->type1.weapon1 == weaponnum) {
			return item;
		}

		item = item->next;

		if (item == first) {
			break;
		}
	}

	return NULL;
}

bool currentPlayerHasWeapon(s32 weaponnum)
{
	return currentPlayerGetWeaponInvItem(weaponnum) != NULL;
}

struct invitem *func0f111a4c(s32 weapon1, s32 weapon2)
{
	struct invitem *first = g_Vars.currentplayer->weapons;
	struct invitem *item = first;

	while (item) {
		if (item->type == INVITEMTYPE_3
				&& item->type3.weapon1 == weapon1
				&& item->type3.weapon2 == weapon2) {
			return item;
		}

		item = item->next;

		if (item == first) {
			break;
		}
	}

	return NULL;
}

bool func0f111ab0(s32 weapon1, s32 weapon2)
{
	return func0f111a4c(weapon1, weapon2) != NULL;
}

GLOBAL_ASM(
glabel func0f111ad4
/*  f111ad4:	3c0e800a */ 	lui	$t6,0x800a
/*  f111ad8:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f111adc:	00802825 */ 	or	$a1,$a0,$zero
/*  f111ae0:	240b0008 */ 	addiu	$t3,$zero,0x8
/*  f111ae4:	8dc31864 */ 	lw	$v1,0x1864($t6)
/*  f111ae8:	240a0004 */ 	addiu	$t2,$zero,0x4
/*  f111aec:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f111af0:	10600022 */ 	beqz	$v1,.L0f111b7c
/*  f111af4:	00601025 */ 	or	$v0,$v1,$zero
/*  f111af8:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f111afc:	8c440000 */ 	lw	$a0,0x0($v0)
.L0f111b00:
/*  f111b00:	15040006 */ 	bne	$t0,$a0,.L0f111b1c
/*  f111b04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f111b08:	844f0004 */ 	lh	$t7,0x4($v0)
/*  f111b0c:	54af0017 */ 	bnel	$a1,$t7,.L0f111b6c
/*  f111b10:	8c42000c */ 	lw	$v0,0xc($v0)
/*  f111b14:	03e00008 */ 	jr	$ra
/*  f111b18:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f111b1c:
/*  f111b1c:	55240013 */ 	bnel	$t1,$a0,.L0f111b6c
/*  f111b20:	8c42000c */ 	lw	$v0,0xc($v0)
/*  f111b24:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f111b28:	50800010 */ 	beqzl	$a0,.L0f111b6c
/*  f111b2c:	8c42000c */ 	lw	$v0,0xc($v0)
/*  f111b30:	90980000 */ 	lbu	$t8,0x0($a0)
/*  f111b34:	5558000d */ 	bnel	$t2,$t8,.L0f111b6c
/*  f111b38:	8c42000c */ 	lw	$v0,0xc($v0)
/*  f111b3c:	8c870004 */ 	lw	$a3,0x4($a0)
/*  f111b40:	50e0000a */ 	beqzl	$a3,.L0f111b6c
/*  f111b44:	8c42000c */ 	lw	$v0,0xc($v0)
/*  f111b48:	90f90003 */ 	lbu	$t9,0x3($a3)
/*  f111b4c:	55790007 */ 	bnel	$t3,$t9,.L0f111b6c
/*  f111b50:	8c42000c */ 	lw	$v0,0xc($v0)
/*  f111b54:	90ec005c */ 	lbu	$t4,0x5c($a3)
/*  f111b58:	54ac0004 */ 	bnel	$a1,$t4,.L0f111b6c
/*  f111b5c:	8c42000c */ 	lw	$v0,0xc($v0)
/*  f111b60:	03e00008 */ 	jr	$ra
/*  f111b64:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f111b68:	8c42000c */ 	lw	$v0,0xc($v0)
.L0f111b6c:
/*  f111b6c:	50430004 */ 	beql	$v0,$v1,.L0f111b80
/*  f111b70:	00001025 */ 	or	$v0,$zero,$zero
/*  f111b74:	5440ffe2 */ 	bnezl	$v0,.L0f111b00
/*  f111b78:	8c440000 */ 	lw	$a0,0x0($v0)
.L0f111b7c:
/*  f111b7c:	00001025 */ 	or	$v0,$zero,$zero
.L0f111b80:
/*  f111b80:	03e00008 */ 	jr	$ra
/*  f111b84:	00000000 */ 	sll	$zero,$zero,0x0
);

// regalloc
//bool func0f111ad4(s32 weaponnum)
//{
//	struct invitem *item = g_Vars.currentplayer->weapons;
//
//	while (item) {
//		if (item->type == INVITEMTYPE_1) {
//			if (weaponnum == item->type1.weapon1) {
//				return true;
//			}
//		} else if (item->type == INVITEMTYPE_PROP) {
//			struct prop *prop = item->type_prop.prop;
//
//			if (prop && prop->type == PROPTYPE_WEAPON) {
//				struct defaultobj *obj = prop->obj;
//
//				if (obj && obj->type == OBJTYPE_WEAPON) {
//					struct weaponobj *weapon = (struct weaponobj *)obj;
//
//					if (weapon->weapon_id == weaponnum) {
//						return true;
//					}
//				}
//			}
//		}
//
//		item = item->next;
//
//		if (item == g_Vars.currentplayer->weapons) {
//			break;
//		}
//	}
//
//	return false;
//}

GLOBAL_ASM(
glabel func0f111b88
/*  f111b88:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f111b8c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f111b90:	0c003a61 */ 	jal	getCurrentStageId
/*  f111b94:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f111b98:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f111b9c:	0c003a61 */ 	jal	getCurrentStageId
/*  f111ba0:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f111ba4:	24010034 */ 	addiu	$at,$zero,0x34
/*  f111ba8:	1041000a */ 	beq	$v0,$at,.L0f111bd4
/*  f111bac:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f111bb0:	0c003a61 */ 	jal	getCurrentStageId
/*  f111bb4:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f111bb8:	2401002a */ 	addiu	$at,$zero,0x2a
/*  f111bbc:	10410005 */ 	beq	$v0,$at,.L0f111bd4
/*  f111bc0:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f111bc4:	28610019 */ 	slti	$at,$v1,0x19
/*  f111bc8:	54200003 */ 	bnezl	$at,.L0f111bd8
/*  f111bcc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f111bd0:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f111bd4:
/*  f111bd4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f111bd8:
/*  f111bd8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f111bdc:	00601025 */ 	or	$v0,$v1,$zero
/*  f111be0:	03e00008 */ 	jr	$ra
/*  f111be4:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 currentStageForbidsSlayer(void)
{
	bool forbids = false;

	if (getCurrentStageId() != STAGE_ATTACKSHIP && getCurrentStageId() != STAGE_SKEDARRUINS) {
		forbids = true;
	}

	return forbids;
}

bool currentPlayerCanHaveAllGunsWeapon(s32 weaponnum)
{
	bool canhave = true;

	if (weaponnum == WEAPON_SLAYER) {
		canhave = false;
	}

	// @bug: The stage conditions need an OR. This condition can never pass.
	if ((getCurrentStageId() == STAGE_ATTACKSHIP && getCurrentStageId() == STAGE_SKEDARRUINS)
			&& weaponnum == WEAPON_SLAYER) {
		canhave = true;
	}

	return canhave;
}

bool currentPlayerCanHaveWeapon(s32 weaponnum)
{
	if (g_Vars.currentplayer->equipallguns &&
			weaponnum && weaponnum <= WEAPON_PSYCHOSISGUN &&
			currentPlayerCanHaveAllGunsWeapon(weaponnum)) {
		return true;
	}

	return currentPlayerHasWeapon(weaponnum);
}

bool func0f111cf8(s32 weapon1, s32 weapon2)
{
	if (weapon2 == WEAPON_NONE) {
		return true;
	}

	if (g_Vars.currentplayer->equipallguns &&
			weapon1 <= WEAPON_PSYCHOSISGUN &&
			weapon1 == weapon2 &&
			weaponHasFlag(weapon1, WEAPONFLAG_00001000) &&
			currentPlayerCanHaveAllGunsWeapon(weapon1)) {
		return true;
	}

	return func0f111ab0(weapon1, weapon2);
}

bool currentPlayerGiveWeapon(s32 weaponnum)
{
	func0f19cb38(weaponnum);

	if (currentPlayerHasWeapon(weaponnum) == 0) {
		struct invitem *item;

		if (g_Vars.currentplayer->equipallguns &&
				weaponnum <= WEAPON_PSYCHOSISGUN &&
				currentPlayerCanHaveAllGunsWeapon(weaponnum)) {
			return false;
		}

		item = currentPlayerGetUnusedInvItem();

		if (item) {
			item->type = INVITEMTYPE_1;
			item->type1.weapon1 = weaponnum;
			item->type1.weapon2 = -1;
			currentPlayerInsertInvItem(item);
		}

		return true;
	}

	return false;
}

bool currentPlayerGiveWeaponWithArgument(s32 weapon1, s32 weapon2)
{
	if (func0f111ab0(weapon1, weapon2) == 0) {
		if (weaponHasFlag(weapon1, WEAPONFLAG_00001000)) {
			struct invitem *item = currentPlayerGetUnusedInvItem();

			if (item) {
				item->type = INVITEMTYPE_3;
				item->type3.weapon1 = weapon1;
				item->type3.weapon2 = weapon2;
				currentPlayerInsertInvItem(item);
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

void currentPlayerRemoveWeapon(s32 weaponnum)
{
	if (g_Vars.currentplayer->weapons) {
		// Begin iterating from the second item in the list. This is required
		// because the item might be removed from the list when iterating it,
		// and it needs to determine when the end of the list has been reached.
		struct invitem *item = g_Vars.currentplayer->weapons->next;

		while (true) {
			// Have to preload this because item->next shouldn't be trusted
			// after calling currentPlayerRemoveInvItem()
			struct invitem *next = item->next;

			if (item->type == INVITEMTYPE_PROP) {
				struct prop *prop = item->type_prop.prop;
				struct textoverride *override = objGetTextOverride(prop->obj);

				if (override && override->weapon == weaponnum) {
					currentPlayerRemoveInvItem(item);
				}
			} else if (item->type == INVITEMTYPE_1) {
				if (item->type1.weapon1 == weaponnum) {
					currentPlayerRemoveInvItem(item);
				}
			} else if (item->type == INVITEMTYPE_3) {
				if (item->type3.weapon1 == weaponnum || item->type3.weapon2 == weaponnum) {
					currentPlayerRemoveInvItem(item);
				}
			}

			if (item == g_Vars.currentplayer->weapons || !g_Vars.currentplayer->weapons) {
				break;
			}

			item = next;
		}
	}
}

bool currentPlayerGiveProp(struct prop *prop)
{
	struct invitem *item;

	// Don't add duplicate night vision to inventory
	// (night vision is already there when using perfect darkness)
	// Note that this check doesn't work on Investigation because it uses the
	// IR specs model. See bug note in Investigation's setup file (setupear.c).
	if (cheatIsActive(CHEAT_PERFECTDARKNESS)
			&& prop->type == PROPTYPE_OBJ
			&& prop->obj
			&& prop->obj->obj == MODEL_CHRNIGHTSIGHT) {
		return true;
	}

	item = currentPlayerGetUnusedInvItem();

	if (item) {
		item->type = INVITEMTYPE_PROP;
		item->type_prop.prop = prop;
		currentPlayerInsertInvItem(item);
	}

	return true;
}

void currentPlayerRemoveProp(struct prop *prop)
{
	if (g_Vars.currentplayer->weapons) {
		struct invitem *item = g_Vars.currentplayer->weapons->next;

		while (true) {
			struct invitem *next = item->next;

			if (item->type == INVITEMTYPE_PROP && item->type_prop.prop == prop) {
				currentPlayerRemoveInvItem(item);
			}

			if (item == g_Vars.currentplayer->weapons || !g_Vars.currentplayer->weapons) {
				break;
			}

			item = next;
		}
	}
}

GLOBAL_ASM(
glabel func0f1120f0
/*  f1120f0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f1120f4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1120f8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1120fc:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f112100:	24010004 */ 	addiu	$at,$zero,0x4
/*  f112104:	00003825 */ 	or	$a3,$zero,$zero
/*  f112108:	55c10073 */ 	bnel	$t6,$at,.L0f1122d8
/*  f11210c:	00e01025 */ 	or	$v0,$a3,$zero
/*  f112110:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f112114:	24010008 */ 	addiu	$at,$zero,0x8
/*  f112118:	24040015 */ 	addiu	$a0,$zero,0x15
/*  f11211c:	904f0003 */ 	lbu	$t7,0x3($v0)
/*  f112120:	55e1006d */ 	bnel	$t7,$at,.L0f1122d8
/*  f112124:	00e01025 */ 	or	$v0,$a3,$zero
/*  f112128:	9050005c */ 	lbu	$s0,0x5c($v0)
/*  f11212c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f112130:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f112134:	0fc41b99 */ 	jal	cheatIsActive
/*  f112138:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f11213c:	10400006 */ 	beqz	$v0,.L0f112158
/*  f112140:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f112144:	2401002d */ 	addiu	$at,$zero,0x2d
/*  f112148:	56010004 */ 	bnel	$s0,$at,.L0f11215c
/*  f11214c:	02002025 */ 	or	$a0,$s0,$zero
/*  f112150:	10000061 */ 	beqz	$zero,.L0f1122d8
/*  f112154:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f112158:
/*  f112158:	02002025 */ 	or	$a0,$s0,$zero
.L0f11215c:
/*  f11215c:	0fc44762 */ 	jal	currentPlayerGiveWeapon
/*  f112160:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f112164:	10400002 */ 	beqz	$v0,.L0f112170
/*  f112168:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f11216c:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f112170:
/*  f112170:	3c18800a */ 	lui	$t8,0x800a
/*  f112174:	8f18a2d8 */ 	lw	$t8,-0x5d28($t8)
/*  f112178:	02002025 */ 	or	$a0,$s0,$zero
/*  f11217c:	24051000 */ 	addiu	$a1,$zero,0x1000
/*  f112180:	53000026 */ 	beqzl	$t8,.L0f11221c
/*  f112184:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f112188:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f11218c:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f112190:	10400021 */ 	beqz	$v0,.L0f112218
/*  f112194:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f112198:	02002025 */ 	or	$a0,$s0,$zero
/*  f11219c:	02002825 */ 	or	$a1,$s0,$zero
/*  f1121a0:	0fc446ac */ 	jal	func0f111ab0
/*  f1121a4:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f1121a8:	1440001b */ 	bnez	$v0,.L0f112218
/*  f1121ac:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f1121b0:	02002025 */ 	or	$a0,$s0,$zero
/*  f1121b4:	0fc44674 */ 	jal	currentPlayerGetWeaponInvItem
/*  f1121b8:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f1121bc:	10400016 */ 	beqz	$v0,.L0f112218
/*  f1121c0:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f1121c4:	84440006 */ 	lh	$a0,0x6($v0)
/*  f1121c8:	8fb90028 */ 	lw	$t9,0x28($sp)
/*  f1121cc:	8fa80028 */ 	lw	$t0,0x28($sp)
/*  f1121d0:	04830007 */ 	bgezl	$a0,.L0f1121f0
/*  f1121d4:	85030006 */ 	lh	$v1,0x6($t0)
/*  f1121d8:	87230006 */ 	lh	$v1,0x6($t9)
/*  f1121dc:	0462000f */ 	bltzl	$v1,.L0f11221c
/*  f1121e0:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f1121e4:	1000000c */ 	beqz	$zero,.L0f112218
/*  f1121e8:	a4430006 */ 	sh	$v1,0x6($v0)
/*  f1121ec:	85030006 */ 	lh	$v1,0x6($t0)
.L0f1121f0:
/*  f1121f0:	0462000a */ 	bltzl	$v1,.L0f11221c
/*  f1121f4:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f1121f8:	10640007 */ 	beq	$v1,$a0,.L0f112218
/*  f1121fc:	02002825 */ 	or	$a1,$s0,$zero
/*  f112200:	0fc4478a */ 	jal	currentPlayerGiveWeaponWithArgument
/*  f112204:	02002025 */ 	or	$a0,$s0,$zero
/*  f112208:	10400003 */ 	beqz	$v0,.L0f112218
/*  f11220c:	00003825 */ 	or	$a3,$zero,$zero
/*  f112210:	10000001 */ 	beqz	$zero,.L0f112218
/*  f112214:	24070002 */ 	addiu	$a3,$zero,0x2
.L0f112218:
/*  f112218:	8fa30024 */ 	lw	$v1,0x24($sp)
.L0f11221c:
/*  f11221c:	8c620064 */ 	lw	$v0,0x64($v1)
/*  f112220:	50400016 */ 	beqzl	$v0,.L0f11227c
/*  f112224:	80660061 */ 	lb	$a2,0x61($v1)
/*  f112228:	8c690008 */ 	lw	$t1,0x8($v1)
/*  f11222c:	02002825 */ 	or	$a1,$s0,$zero
/*  f112230:	02002025 */ 	or	$a0,$s0,$zero
/*  f112234:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f112238:	05410005 */ 	bgez	$t2,.L0f112250
/*  f11223c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112240:	0fc446ac */ 	jal	func0f111ab0
/*  f112244:	9044005c */ 	lbu	$a0,0x5c($v0)
/*  f112248:	10000004 */ 	beqz	$zero,.L0f11225c
/*  f11224c:	2c470001 */ 	sltiu	$a3,$v0,0x1
.L0f112250:
/*  f112250:	0fc446ac */ 	jal	func0f111ab0
/*  f112254:	9045005c */ 	lbu	$a1,0x5c($v0)
/*  f112258:	2c470001 */ 	sltiu	$a3,$v0,0x1
.L0f11225c:
/*  f11225c:	8fab0024 */ 	lw	$t3,0x24($sp)
/*  f112260:	8d6c0064 */ 	lw	$t4,0x64($t3)
/*  f112264:	a1900061 */ 	sb	$s0,0x61($t4)
/*  f112268:	8d6d0064 */ 	lw	$t5,0x64($t3)
/*  f11226c:	ada00064 */ 	sw	$zero,0x64($t5)
/*  f112270:	10000018 */ 	beqz	$zero,.L0f1122d4
/*  f112274:	ad600064 */ 	sw	$zero,0x64($t3)
/*  f112278:	80660061 */ 	lb	$a2,0x61($v1)
.L0f11227c:
/*  f11227c:	04c20016 */ 	bltzl	$a2,.L0f1122d8
/*  f112280:	00e01025 */ 	or	$v0,$a3,$zero
/*  f112284:	8c6e0008 */ 	lw	$t6,0x8($v1)
/*  f112288:	02002825 */ 	or	$a1,$s0,$zero
/*  f11228c:	02002025 */ 	or	$a0,$s0,$zero
/*  f112290:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f112294:	05e10009 */ 	bgez	$t7,.L0f1122bc
/*  f112298:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11229c:	0fc4478a */ 	jal	currentPlayerGiveWeaponWithArgument
/*  f1122a0:	00c02025 */ 	or	$a0,$a2,$zero
/*  f1122a4:	10400003 */ 	beqz	$v0,.L0f1122b4
/*  f1122a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1122ac:	10000009 */ 	beqz	$zero,.L0f1122d4
/*  f1122b0:	24070002 */ 	addiu	$a3,$zero,0x2
.L0f1122b4:
/*  f1122b4:	10000007 */ 	beqz	$zero,.L0f1122d4
/*  f1122b8:	00003825 */ 	or	$a3,$zero,$zero
.L0f1122bc:
/*  f1122bc:	0fc4478a */ 	jal	currentPlayerGiveWeaponWithArgument
/*  f1122c0:	00c02825 */ 	or	$a1,$a2,$zero
/*  f1122c4:	10400003 */ 	beqz	$v0,.L0f1122d4
/*  f1122c8:	00003825 */ 	or	$a3,$zero,$zero
/*  f1122cc:	10000001 */ 	beqz	$zero,.L0f1122d4
/*  f1122d0:	24070002 */ 	addiu	$a3,$zero,0x2
.L0f1122d4:
/*  f1122d4:	00e01025 */ 	or	$v0,$a3,$zero
.L0f1122d8:
/*  f1122d8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1122dc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1122e0:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f1122e4:	03e00008 */ 	jr	$ra
/*  f1122e8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1122ec
/*  f1122ec:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f1122f0:	3c02800a */ 	lui	$v0,0x800a
/*  f1122f4:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f1122f8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f1122fc:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f112300:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f112304:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f112308:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f11230c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f112310:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f112314:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f112318:	8c581870 */ 	lw	$t8,0x1870($v0)
/*  f11231c:	8c870000 */ 	lw	$a3,0x0($a0)
/*  f112320:	00c09825 */ 	or	$s3,$a2,$zero
/*  f112324:	8cb40000 */ 	lw	$s4,0x0($a1)
/*  f112328:	1300003b */ 	beqz	$t8,.L0f112418
/*  f11232c:	00e09025 */ 	or	$s2,$a3,$zero
/*  f112330:	00e08025 */ 	or	$s0,$a3,$zero
/*  f112334:	00e02025 */ 	or	$a0,$a3,$zero
/*  f112338:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f11233c:	24051000 */ 	addiu	$a1,$zero,0x1000
/*  f112340:	1040000a */ 	beqz	$v0,.L0f11236c
/*  f112344:	2411002d */ 	addiu	$s1,$zero,0x2d
/*  f112348:	8fb90030 */ 	lw	$t9,0x30($sp)
/*  f11234c:	8fa80034 */ 	lw	$t0,0x34($sp)
/*  f112350:	8f270000 */ 	lw	$a3,0x0($t9)
/*  f112354:	8d090000 */ 	lw	$t1,0x0($t0)
/*  f112358:	11270004 */ 	beq	$t1,$a3,.L0f11236c
/*  f11235c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112360:	00e09025 */ 	or	$s2,$a3,$zero
/*  f112364:	10000069 */ 	beqz	$zero,.L0f11250c
/*  f112368:	00e0a025 */ 	or	$s4,$a3,$zero
.L0f11236c:
/*  f11236c:	260a0001 */ 	addiu	$t2,$s0,0x1
.L0f112370:
/*  f112370:	0151001a */ 	div	$zero,$t2,$s1
/*  f112374:	00008010 */ 	mfhi	$s0
/*  f112378:	260b0001 */ 	addiu	$t3,$s0,0x1
/*  f11237c:	16200002 */ 	bnez	$s1,.L0f112388
/*  f112380:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112384:	0007000d */ 	break	0x7
.L0f112388:
/*  f112388:	2401ffff */ 	addiu	$at,$zero,-1
/*  f11238c:	16210004 */ 	bne	$s1,$at,.L0f1123a0
/*  f112390:	3c018000 */ 	lui	$at,0x8000
/*  f112394:	15410002 */ 	bne	$t2,$at,.L0f1123a0
/*  f112398:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11239c:	0006000d */ 	break	0x6
.L0f1123a0:
/*  f1123a0:	1600000c */ 	bnez	$s0,.L0f1123d4
/*  f1123a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1123a8:	0171001a */ 	div	$zero,$t3,$s1
/*  f1123ac:	00008010 */ 	mfhi	$s0
/*  f1123b0:	16200002 */ 	bnez	$s1,.L0f1123bc
/*  f1123b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1123b8:	0007000d */ 	break	0x7
.L0f1123bc:
/*  f1123bc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1123c0:	16210004 */ 	bne	$s1,$at,.L0f1123d4
/*  f1123c4:	3c018000 */ 	lui	$at,0x8000
/*  f1123c8:	15610002 */ 	bne	$t3,$at,.L0f1123d4
/*  f1123cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1123d0:	0006000d */ 	break	0x6
.L0f1123d4:
/*  f1123d4:	12600005 */ 	beqz	$s3,.L0f1123ec
/*  f1123d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1123dc:	0fc28684 */ 	jal	func0f0a1a10
/*  f1123e0:	02002025 */ 	or	$a0,$s0,$zero
/*  f1123e4:	10400008 */ 	beqz	$v0,.L0f112408
/*  f1123e8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1123ec:
/*  f1123ec:	0fc4470c */ 	jal	currentPlayerCanHaveAllGunsWeapon
/*  f1123f0:	02002025 */ 	or	$a0,$s0,$zero
/*  f1123f4:	10400004 */ 	beqz	$v0,.L0f112408
/*  f1123f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1123fc:	02009025 */ 	or	$s2,$s0,$zero
/*  f112400:	10000042 */ 	beqz	$zero,.L0f11250c
/*  f112404:	0000a025 */ 	or	$s4,$zero,$zero
.L0f112408:
/*  f112408:	5612ffd9 */ 	bnel	$s0,$s2,.L0f112370
/*  f11240c:	260a0001 */ 	addiu	$t2,$s0,0x1
/*  f112410:	1000003f */ 	beqz	$zero,.L0f112510
/*  f112414:	8faf0030 */ 	lw	$t7,0x30($sp)
.L0f112418:
/*  f112418:	8c501864 */ 	lw	$s0,0x1864($v0)
/*  f11241c:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f112420:	5200003b */ 	beqzl	$s0,.L0f112510
/*  f112424:	8faf0030 */ 	lw	$t7,0x30($sp)
/*  f112428:	8e020000 */ 	lw	$v0,0x0($s0)
.L0f11242c:
/*  f11242c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f112430:	16220011 */ 	bne	$s1,$v0,.L0f112478
/*  f112434:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112438:	86040004 */ 	lh	$a0,0x4($s0)
/*  f11243c:	2881002d */ 	slti	$at,$a0,0x2d
/*  f112440:	10200026 */ 	beqz	$at,.L0f1124dc
/*  f112444:	0244082a */ 	slt	$at,$s2,$a0
/*  f112448:	10200024 */ 	beqz	$at,.L0f1124dc
/*  f11244c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112450:	52600007 */ 	beqzl	$s3,.L0f112470
/*  f112454:	00809025 */ 	or	$s2,$a0,$zero
/*  f112458:	0fc28684 */ 	jal	func0f0a1a10
/*  f11245c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112460:	1040001e */ 	beqz	$v0,.L0f1124dc
/*  f112464:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112468:	86040004 */ 	lh	$a0,0x4($s0)
/*  f11246c:	00809025 */ 	or	$s2,$a0,$zero
.L0f112470:
/*  f112470:	10000026 */ 	beqz	$zero,.L0f11250c
/*  f112474:	0000a025 */ 	or	$s4,$zero,$zero
.L0f112478:
/*  f112478:	14410018 */ 	bne	$v0,$at,.L0f1124dc
/*  f11247c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112480:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f112484:	0244082a */ 	slt	$at,$s2,$a0
/*  f112488:	14200007 */ 	bnez	$at,.L0f1124a8
/*  f11248c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112490:	16440012 */ 	bne	$s2,$a0,.L0f1124dc
/*  f112494:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112498:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*  f11249c:	028c082a */ 	slt	$at,$s4,$t4
/*  f1124a0:	1020000e */ 	beqz	$at,.L0f1124dc
/*  f1124a4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1124a8:
/*  f1124a8:	5260000a */ 	beqzl	$s3,.L0f1124d4
/*  f1124ac:	8e120004 */ 	lw	$s2,0x4($s0)
/*  f1124b0:	0fc28684 */ 	jal	func0f0a1a10
/*  f1124b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1124b8:	54400006 */ 	bnezl	$v0,.L0f1124d4
/*  f1124bc:	8e120004 */ 	lw	$s2,0x4($s0)
/*  f1124c0:	0fc28684 */ 	jal	func0f0a1a10
/*  f1124c4:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f1124c8:	10400004 */ 	beqz	$v0,.L0f1124dc
/*  f1124cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1124d0:	8e120004 */ 	lw	$s2,0x4($s0)
.L0f1124d4:
/*  f1124d4:	1000000d */ 	beqz	$zero,.L0f11250c
/*  f1124d8:	8e140008 */ 	lw	$s4,0x8($s0)
.L0f1124dc:
/*  f1124dc:	3c0d800a */ 	lui	$t5,0x800a
/*  f1124e0:	8dada244 */ 	lw	$t5,-0x5dbc($t5)
/*  f1124e4:	8e10000c */ 	lw	$s0,0xc($s0)
/*  f1124e8:	8dae1864 */ 	lw	$t6,0x1864($t5)
/*  f1124ec:	160e0005 */ 	bne	$s0,$t6,.L0f112504
/*  f1124f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1124f4:	56600006 */ 	bnezl	$s3,.L0f112510
/*  f1124f8:	8faf0030 */ 	lw	$t7,0x30($sp)
/*  f1124fc:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f112500:	2414ffff */ 	addiu	$s4,$zero,-1
.L0f112504:
/*  f112504:	5600ffc9 */ 	bnezl	$s0,.L0f11242c
/*  f112508:	8e020000 */ 	lw	$v0,0x0($s0)
.L0f11250c:
/*  f11250c:	8faf0030 */ 	lw	$t7,0x30($sp)
.L0f112510:
/*  f112510:	adf20000 */ 	sw	$s2,0x0($t7)
/*  f112514:	8fb80034 */ 	lw	$t8,0x34($sp)
/*  f112518:	af140000 */ 	sw	$s4,0x0($t8)
/*  f11251c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f112520:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f112524:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f112528:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f11252c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f112530:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f112534:	03e00008 */ 	jr	$ra
/*  f112538:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f11253c
/*  f11253c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f112540:	3c03800a */ 	lui	$v1,0x800a
/*  f112544:	8c63a244 */ 	lw	$v1,-0x5dbc($v1)
/*  f112548:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f11254c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f112550:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f112554:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f112558:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f11255c:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f112560:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f112564:	8c781870 */ 	lw	$t8,0x1870($v1)
/*  f112568:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f11256c:	00c09025 */ 	or	$s2,$a2,$zero
/*  f112570:	8cb30000 */ 	lw	$s3,0x0($a1)
/*  f112574:	1300003a */ 	beqz	$t8,.L0f112660
/*  f112578:	00408825 */ 	or	$s1,$v0,$zero
/*  f11257c:	00408025 */ 	or	$s0,$v0,$zero
/*  f112580:	00402025 */ 	or	$a0,$v0,$zero
/*  f112584:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f112588:	24051000 */ 	addiu	$a1,$zero,0x1000
/*  f11258c:	50400006 */ 	beqzl	$v0,.L0f1125a8
/*  f112590:	2411002d */ 	addiu	$s1,$zero,0x2d
/*  f112594:	16330003 */ 	bne	$s1,$s3,.L0f1125a4
/*  f112598:	02008825 */ 	or	$s1,$s0,$zero
/*  f11259c:	10000071 */ 	beqz	$zero,.L0f112764
/*  f1125a0:	00009825 */ 	or	$s3,$zero,$zero
.L0f1125a4:
/*  f1125a4:	2411002d */ 	addiu	$s1,$zero,0x2d
.L0f1125a8:
/*  f1125a8:	2619002c */ 	addiu	$t9,$s0,0x2c
.L0f1125ac:
/*  f1125ac:	0331001a */ 	div	$zero,$t9,$s1
/*  f1125b0:	00008010 */ 	mfhi	$s0
/*  f1125b4:	2608002c */ 	addiu	$t0,$s0,0x2c
/*  f1125b8:	16200002 */ 	bnez	$s1,.L0f1125c4
/*  f1125bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1125c0:	0007000d */ 	break	0x7
.L0f1125c4:
/*  f1125c4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1125c8:	16210004 */ 	bne	$s1,$at,.L0f1125dc
/*  f1125cc:	3c018000 */ 	lui	$at,0x8000
/*  f1125d0:	17210002 */ 	bne	$t9,$at,.L0f1125dc
/*  f1125d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1125d8:	0006000d */ 	break	0x6
.L0f1125dc:
/*  f1125dc:	1600000c */ 	bnez	$s0,.L0f112610
/*  f1125e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1125e4:	0111001a */ 	div	$zero,$t0,$s1
/*  f1125e8:	00008010 */ 	mfhi	$s0
/*  f1125ec:	16200002 */ 	bnez	$s1,.L0f1125f8
/*  f1125f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1125f4:	0007000d */ 	break	0x7
.L0f1125f8:
/*  f1125f8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1125fc:	16210004 */ 	bne	$s1,$at,.L0f112610
/*  f112600:	3c018000 */ 	lui	$at,0x8000
/*  f112604:	15010002 */ 	bne	$t0,$at,.L0f112610
/*  f112608:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11260c:	0006000d */ 	break	0x6
.L0f112610:
/*  f112610:	12400005 */ 	beqz	$s2,.L0f112628
/*  f112614:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112618:	0fc28684 */ 	jal	func0f0a1a10
/*  f11261c:	02002025 */ 	or	$a0,$s0,$zero
/*  f112620:	5040ffe2 */ 	beqzl	$v0,.L0f1125ac
/*  f112624:	2619002c */ 	addiu	$t9,$s0,0x2c
.L0f112628:
/*  f112628:	0fc4470c */ 	jal	currentPlayerCanHaveAllGunsWeapon
/*  f11262c:	02002025 */ 	or	$a0,$s0,$zero
/*  f112630:	5040ffde */ 	beqzl	$v0,.L0f1125ac
/*  f112634:	2619002c */ 	addiu	$t9,$s0,0x2c
/*  f112638:	02002025 */ 	or	$a0,$s0,$zero
/*  f11263c:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f112640:	24051000 */ 	addiu	$a1,$zero,0x1000
/*  f112644:	10400004 */ 	beqz	$v0,.L0f112658
/*  f112648:	02008825 */ 	or	$s1,$s0,$zero
/*  f11264c:	02008825 */ 	or	$s1,$s0,$zero
/*  f112650:	10000044 */ 	beqz	$zero,.L0f112764
/*  f112654:	02009825 */ 	or	$s3,$s0,$zero
.L0f112658:
/*  f112658:	10000042 */ 	beqz	$zero,.L0f112764
/*  f11265c:	00009825 */ 	or	$s3,$zero,$zero
.L0f112660:
/*  f112660:	8c621864 */ 	lw	$v0,0x1864($v1)
/*  f112664:	50400040 */ 	beqzl	$v0,.L0f112768
/*  f112668:	8fac0028 */ 	lw	$t4,0x28($sp)
/*  f11266c:	8c500010 */ 	lw	$s0,0x10($v0)
.L0f112670:
/*  f112670:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f112674:	24010001 */ 	addiu	$at,$zero,0x1
/*  f112678:	54410016 */ 	bnel	$v0,$at,.L0f1126d4
/*  f11267c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f112680:	86040004 */ 	lh	$a0,0x4($s0)
/*  f112684:	2881002d */ 	slti	$at,$a0,0x2d
/*  f112688:	1020002b */ 	beqz	$at,.L0f112738
/*  f11268c:	0091082a */ 	slt	$at,$a0,$s1
/*  f112690:	14200005 */ 	bnez	$at,.L0f1126a8
/*  f112694:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112698:	16240027 */ 	bne	$s1,$a0,.L0f112738
/*  f11269c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1126a0:	1a600025 */ 	blez	$s3,.L0f112738
/*  f1126a4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1126a8:
/*  f1126a8:	52400007 */ 	beqzl	$s2,.L0f1126c8
/*  f1126ac:	00808825 */ 	or	$s1,$a0,$zero
/*  f1126b0:	0fc28684 */ 	jal	func0f0a1a10
/*  f1126b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1126b8:	1040001f */ 	beqz	$v0,.L0f112738
/*  f1126bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1126c0:	86040004 */ 	lh	$a0,0x4($s0)
/*  f1126c4:	00808825 */ 	or	$s1,$a0,$zero
.L0f1126c8:
/*  f1126c8:	10000026 */ 	beqz	$zero,.L0f112764
/*  f1126cc:	00009825 */ 	or	$s3,$zero,$zero
/*  f1126d0:	24010003 */ 	addiu	$at,$zero,0x3
.L0f1126d4:
/*  f1126d4:	14410018 */ 	bne	$v0,$at,.L0f112738
/*  f1126d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1126dc:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f1126e0:	0091082a */ 	slt	$at,$a0,$s1
/*  f1126e4:	14200007 */ 	bnez	$at,.L0f112704
/*  f1126e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1126ec:	16240012 */ 	bne	$s1,$a0,.L0f112738
/*  f1126f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1126f4:	8e090008 */ 	lw	$t1,0x8($s0)
/*  f1126f8:	0133082a */ 	slt	$at,$t1,$s3
/*  f1126fc:	1020000e */ 	beqz	$at,.L0f112738
/*  f112700:	00000000 */ 	sll	$zero,$zero,0x0
.L0f112704:
/*  f112704:	5240000a */ 	beqzl	$s2,.L0f112730
/*  f112708:	8e110004 */ 	lw	$s1,0x4($s0)
/*  f11270c:	0fc28684 */ 	jal	func0f0a1a10
/*  f112710:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112714:	54400006 */ 	bnezl	$v0,.L0f112730
/*  f112718:	8e110004 */ 	lw	$s1,0x4($s0)
/*  f11271c:	0fc28684 */ 	jal	func0f0a1a10
/*  f112720:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f112724:	10400004 */ 	beqz	$v0,.L0f112738
/*  f112728:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11272c:	8e110004 */ 	lw	$s1,0x4($s0)
.L0f112730:
/*  f112730:	1000000c */ 	beqz	$zero,.L0f112764
/*  f112734:	8e130008 */ 	lw	$s3,0x8($s0)
.L0f112738:
/*  f112738:	3c0a800a */ 	lui	$t2,0x800a
/*  f11273c:	8d4aa244 */ 	lw	$t2,-0x5dbc($t2)
/*  f112740:	8d4b1864 */ 	lw	$t3,0x1864($t2)
/*  f112744:	160b0005 */ 	bne	$s0,$t3,.L0f11275c
/*  f112748:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11274c:	56400006 */ 	bnezl	$s2,.L0f112768
/*  f112750:	8fac0028 */ 	lw	$t4,0x28($sp)
/*  f112754:	241103e8 */ 	addiu	$s1,$zero,0x3e8
/*  f112758:	241303e8 */ 	addiu	$s3,$zero,0x3e8
.L0f11275c:
/*  f11275c:	1000ffc4 */ 	beqz	$zero,.L0f112670
/*  f112760:	8e100010 */ 	lw	$s0,0x10($s0)
.L0f112764:
/*  f112764:	8fac0028 */ 	lw	$t4,0x28($sp)
.L0f112768:
/*  f112768:	ad910000 */ 	sw	$s1,0x0($t4)
/*  f11276c:	8fad002c */ 	lw	$t5,0x2c($sp)
/*  f112770:	adb30000 */ 	sw	$s3,0x0($t5)
/*  f112774:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f112778:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f11277c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f112780:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f112784:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f112788:	03e00008 */ 	jr	$ra
/*  f11278c:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel currentPlayerHasKeyFlags
/*  f112790:	3c0e800a */ 	lui	$t6,0x800a
/*  f112794:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f112798:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f11279c:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f1127a0:	8dc51864 */ 	lw	$a1,0x1864($t6)
/*  f1127a4:	00808025 */ 	or	$s0,$a0,$zero
/*  f1127a8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1127ac:	10a0001f */ 	beqz	$a1,.L0f11282c
/*  f1127b0:	00a01825 */ 	or	$v1,$a1,$zero
/*  f1127b4:	240a0004 */ 	addiu	$t2,$zero,0x4
/*  f1127b8:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f1127bc:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f1127c0:	8c6f0000 */ 	lw	$t7,0x0($v1)
.L0f1127c4:
/*  f1127c4:	550f0015 */ 	bnel	$t0,$t7,.L0f11281c
/*  f1127c8:	8c63000c */ 	lw	$v1,0xc($v1)
/*  f1127cc:	8c640004 */ 	lw	$a0,0x4($v1)
/*  f1127d0:	50800012 */ 	beqzl	$a0,.L0f11281c
/*  f1127d4:	8c63000c */ 	lw	$v1,0xc($v1)
/*  f1127d8:	90980000 */ 	lbu	$t8,0x0($a0)
/*  f1127dc:	5538000f */ 	bnel	$t1,$t8,.L0f11281c
/*  f1127e0:	8c63000c */ 	lw	$v1,0xc($v1)
/*  f1127e4:	8c870004 */ 	lw	$a3,0x4($a0)
/*  f1127e8:	50e0000c */ 	beqzl	$a3,.L0f11281c
/*  f1127ec:	8c63000c */ 	lw	$v1,0xc($v1)
/*  f1127f0:	90f90003 */ 	lbu	$t9,0x3($a3)
/*  f1127f4:	55590009 */ 	bnel	$t2,$t9,.L0f11281c
/*  f1127f8:	8c63000c */ 	lw	$v1,0xc($v1)
/*  f1127fc:	8ceb005c */ 	lw	$t3,0x5c($a3)
/*  f112800:	004b1025 */ 	or	$v0,$v0,$t3
/*  f112804:	02026024 */ 	and	$t4,$s0,$v0
/*  f112808:	560c0004 */ 	bnel	$s0,$t4,.L0f11281c
/*  f11280c:	8c63000c */ 	lw	$v1,0xc($v1)
/*  f112810:	10000007 */ 	beqz	$zero,.L0f112830
/*  f112814:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f112818:	8c63000c */ 	lw	$v1,0xc($v1)
.L0f11281c:
/*  f11281c:	50650004 */ 	beql	$v1,$a1,.L0f112830
/*  f112820:	00001025 */ 	or	$v0,$zero,$zero
/*  f112824:	5460ffe7 */ 	bnezl	$v1,.L0f1127c4
/*  f112828:	8c6f0000 */ 	lw	$t7,0x0($v1)
.L0f11282c:
/*  f11282c:	00001025 */ 	or	$v0,$zero,$zero
.L0f112830:
/*  f112830:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f112834:	03e00008 */ 	jr	$ra
/*  f112838:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

//bool currentPlayerHasKeyFlags(u32 wantkeyflags)
//{
//	struct invitem *item = g_Vars.currentplayer->weapons;
//	u32 heldkeyflags = 0;
//	bool unlocked = false;
//
//	while (item) {
//		if (item->type == INVITEMTYPE_PROP) {
//			struct prop *prop = item->type_prop.prop;
//
//			if (prop && prop->type == PROPTYPE_OBJ) {
//				struct defaultobj *obj = prop->obj;
//
//				if (obj && obj->type == OBJTYPE_KEY) {
//					struct keyobj *key = (struct keyobj *)obj;
//
//					heldkeyflags |= key->keyflags;
//
//					if ((wantkeyflags & heldkeyflags) == wantkeyflags) {
//						unlocked = true;
//						break;
//					}
//				}
//			}
//		}
//
//		item = item->next;
//
//		if (item == g_Vars.currentplayer->weapons) {
//			break;
//		}
//	}
//
//	return unlocked;
//}

bool func0f11283c(void)
{
	return false;
}

bool currentPlayerHasBriefcase(void)
{
	if (g_Vars.currentplayer->isdead == false) {
		return currentPlayerHasWeapon(WEAPON_BRIEFCASE2);
	}

	return false;
}

bool currentPlayerHasDataUplink(void)
{
	if (g_Vars.currentplayer->isdead == false) {
		return currentPlayerHasWeapon(WEAPON_DATAUPLINK);
	}

	return false;
}

bool func0f1128c4(void)
{
	return false;
}

bool currentPlayerHasProp(struct prop *prop)
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

s32 currentPlayerGetNumInvItems(void)
{
	s32 numitems = 0;
	struct invitem *item;

	if (g_Vars.currentplayer->equipallguns) {
		numitems = WEAPON_PSYCHOSISGUN - currentStageForbidsSlayer();
	}

	item = g_Vars.currentplayer->weapons;

	while (item) {
		if (item->type == INVITEMTYPE_PROP) {
			struct prop *prop = item->type_prop.prop;

			if (prop) {
				struct defaultobj *obj = prop->obj;

				if (obj) {
					if (prop->type == PROPTYPE_WEAPON) {
						if (obj->hidden & OBJHFLAG_00000400) {
							numitems++;
						}
					} else if (prop->type == PROPTYPE_OBJ) {
						if ((obj->flags2 & OBJFLAG2_00040000) == 0) {
							numitems++;
						}
					}
				}
			}
		} else if (item->type == INVITEMTYPE_1) {
			if (g_Vars.currentplayer->equipallguns == false
					|| item->type1.weapon1 > WEAPON_PSYCHOSISGUN) {
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

struct invitem *currentPlayerGetInvItemByIndex(s32 index)
{
	struct invitem *item;

	if (g_Vars.currentplayer->equipallguns) {
		if (index < WEAPON_PSYCHOSISGUN - currentStageForbidsSlayer()) {
			return NULL;
		}

		index += currentStageForbidsSlayer() - WEAPON_PSYCHOSISGUN;
	}

	item = g_Vars.currentplayer->weapons;

	while (item) {
		if (item->type == INVITEMTYPE_PROP) {
			struct prop *prop = item->type_prop.prop;

			if (prop) {
				struct defaultobj *obj = prop->obj;

				if (obj) {
					if (prop->type == PROPTYPE_WEAPON) {
						if (obj->hidden & OBJHFLAG_00000400) {
							if (index == 0) {
								return item;
							}
							index--;
						}
					} else if (prop->type == PROPTYPE_OBJ) {
						if ((obj->flags2 & OBJFLAG2_00040000) == 0) {
							if (index == 0) {
								return item;
							}
							index--;
						}
					}
				}
			}
		} else if (item->type == INVITEMTYPE_1) {
			if (g_Vars.currentplayer->equipallguns == false
					|| item->type1.weapon1 > WEAPON_PSYCHOSISGUN) {
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

struct textoverride *objGetTextOverride(struct defaultobj *obj)
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

struct textoverride *weaponGetTextOverride(s32 weaponnum)
{
	struct textoverride *override = g_Vars.textoverrides;

	while (override) {
		if (override->unk04 == 0 && override->weapon == weaponnum) {
			return override;
		}

		override = override->next;
	}

	return NULL;
}

s32 currentPlayerGetWeaponNumByInvIndex(s32 index)
{
	struct invitem *item = currentPlayerGetInvItemByIndex(index);

	if (item) {
		if (item->type == INVITEMTYPE_PROP) {
			struct prop *prop = item->type_prop.prop;
			struct textoverride *override = objGetTextOverride(prop->obj);

			if (override) {
				return override->weapon;
			}
		} else if (item->type == INVITEMTYPE_1) {
			return item->type1.weapon1;
		}
	} else if (g_Vars.currentplayer->equipallguns) {
		if (index < WEAPON_PSYCHOSISGUN - currentStageForbidsSlayer()) {
			index++;
			return func0f111b88(index);
		}
	}

	return 0;
}

u16 currentPlayerGetInvNameIdByIndex(s32 index)
{
	struct invitem *item = currentPlayerGetInvItemByIndex(index);
	s32 weaponnum = 0;
	struct textoverride *override;

	if (item) {
		if (item->type == INVITEMTYPE_PROP) {
			struct prop *prop = item->type_prop.prop;
			override = objGetTextOverride(prop->obj);

			if (override) {
				if (override->unk14) {
					return override->unk14;
				}

				weaponnum = override->weapon;
			}
		} else if (item->type == INVITEMTYPE_1) {
			weaponnum = item->type1.weapon1;
			override = weaponGetTextOverride(weaponnum);

			if (override && override->unk14) {
				return override->unk14;
			}
		}
	} else {
		if (g_Vars.currentplayer->equipallguns) {
			if (index < WEAPON_PSYCHOSISGUN - currentStageForbidsSlayer()) {
				index++;
				return func0f0a21a4(func0f111b88(index));
			}
		}
	}

	return func0f0a21a4(weaponnum);
}

char *currentPlayerGetInvNameByIndex(s32 index)
{
	return langGet(currentPlayerGetInvNameIdByIndex(index));
}

char *currentPlayerGetInvShortNameByIndex(s32 index)
{
	struct invitem *item = currentPlayerGetInvItemByIndex(index);
	s32 weaponnum = 0;
	struct textoverride *override;

	if (item) {
		if (item->type == INVITEMTYPE_PROP) {
			struct prop *prop = item->type_prop.prop;
			override = objGetTextOverride(prop->obj);

			if (override) {
				if (override->unk14) {
					return langGet(override->unk14);
				}

				weaponnum = override->weapon;
			}
		} else if (item->type == INVITEMTYPE_1) {
			weaponnum = item->type1.weapon1;
			override = weaponGetTextOverride(weaponnum);

			if (override && override->unk14) {
				return langGet(override->unk14);
			}
		}
	} else if (g_Vars.currentplayer->equipallguns) {
		if (index < WEAPON_PSYCHOSISGUN - currentStageForbidsSlayer()) {
			index++;
			return func0f0a21d0(func0f111b88(index));
		}
	}

	return func0f0a21d0(weaponnum);
}

void textoverrideInsert(struct textoverride *override)
{
	override->next = g_Vars.textoverrides;
	g_Vars.textoverrides = override;
}

u32 currentPlayerGetEquipCurItem(void)
{
	return g_Vars.currentplayer->equipcuritem;
}

void currentPlayerSetEquipCurItem(u32 item)
{
	g_Vars.currentplayer->equipcuritem = item;
}

void currentPlayerCalculateEquipCurItem(void)
{
	s32 curweaponnum = getCurrentPlayerWeaponId(0);
	s32 i;

	g_Vars.currentplayer->equipcuritem = 0;

	for (i = 0; i < currentPlayerGetNumInvItems(); i++) {
		if (currentPlayerGetWeaponNumByInvIndex(i) == curweaponnum) {
			g_Vars.currentplayer->equipcuritem = i;
			break;
		}
	}
}

char *objGetActivatedText(struct defaultobj *obj)
{
	struct textoverride *override = objGetTextOverride(obj);

	if (override && override->activatetextid) {
		return langGet(override->activatetextid);
	}

	return NULL;
}

char *weaponGetActivatedText(s32 weaponnum)
{
	struct textoverride *override = weaponGetTextOverride(weaponnum);

	if (override && override->activatetextid) {
		return langGet(override->activatetextid);
	}

	return NULL;
}

void currentPlayerIncrementGunHeldTime(s32 weapon1, s32 weapon2)
{
	s32 leastusedtime;
	s32 leastusedindex;
	s32 i;

	if (!weaponHasFlag(weapon1, WEAPONFLAG_TRACKTIMEUSED)) {
		return;
	}

	leastusedtime = 0x7fffffff;
	leastusedindex = 0;

	if (!weaponHasFlag(weapon2, WEAPONFLAG_TRACKTIMEUSED)) {
		weapon2 = 0;
	}

	for (i = 0; i < MAX_GUNHELD; i++) {
		s32 time = g_Vars.currentplayer->gunheldarr[i].totaltime240_60;

		if (time >= 0) {
			if (weapon1 == g_Vars.currentplayer->gunheldarr[i].weapon1 &&
					weapon2 == g_Vars.currentplayer->gunheldarr[i].weapon2) {
				g_Vars.currentplayer->gunheldarr[i].totaltime240_60 = time + g_Vars.lvupdate240_60;
				break;
			}

			if (time < leastusedtime) {
				leastusedtime = time;
				leastusedindex = i;
			}
		} else {
			leastusedindex = i;
			i = MAX_GUNHELD;
			break;
		}
	}

	if (i == MAX_GUNHELD) {
		g_Vars.currentplayer->gunheldarr[leastusedindex].totaltime240_60 = g_Vars.lvupdate240_60;
		g_Vars.currentplayer->gunheldarr[leastusedindex].weapon1 = weapon1;
		g_Vars.currentplayer->gunheldarr[leastusedindex].weapon2 = weapon2;
	}
}

GLOBAL_ASM(
glabel currentPlayerGetWeaponOfChoice
/*  f1131ac:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f1131b0:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f1131b4:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f1131b8:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f1131bc:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f1131c0:	00003025 */ 	or	$a2,$zero,$zero
/*  f1131c4:	24090078 */ 	addiu	$t1,$zero,0x78
/*  f1131c8:	8d0e0284 */ 	lw	$t6,0x284($t0)
.L0f1131cc:
/*  f1131cc:	01c61821 */ 	addu	$v1,$t6,$a2
/*  f1131d0:	8c671880 */ 	lw	$a3,0x1880($v1)
/*  f1131d4:	04e0000a */ 	bltz	$a3,.L0f113200
/*  f1131d8:	0047082a */ 	slt	$at,$v0,$a3
/*  f1131dc:	50200009 */ 	beqzl	$at,.L0f113204
/*  f1131e0:	24c6000c */ 	addiu	$a2,$a2,0xc
/*  f1131e4:	8c6f1878 */ 	lw	$t7,0x1878($v1)
/*  f1131e8:	00e01025 */ 	or	$v0,$a3,$zero
/*  f1131ec:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f1131f0:	8d180284 */ 	lw	$t8,0x284($t0)
/*  f1131f4:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f1131f8:	8f2a187c */ 	lw	$t2,0x187c($t9)
/*  f1131fc:	acaa0000 */ 	sw	$t2,0x0($a1)
.L0f113200:
/*  f113200:	24c6000c */ 	addiu	$a2,$a2,0xc
.L0f113204:
/*  f113204:	54c9fff1 */ 	bnel	$a2,$t1,.L0f1131cc
/*  f113208:	8d0e0284 */ 	lw	$t6,0x284($t0)
/*  f11320c:	03e00008 */ 	jr	$ra
/*  f113210:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113214:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113218:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11321c:	00000000 */ 	sll	$zero,$zero,0x0
);

// regalloc
//void currentPlayerGetWeaponOfChoice(s32 *weapon1, s32 *weapon2)
//{
//	s32 mosttime = -1;
//	s32 i;
//
//	*weapon1 = 0;
//	*weapon2 = 0;
//
//	for (i = 0; i != MAX_GUNHELD; i++) {
//		s32 time = g_Vars.currentplayer->gunheldarr[i].totaltime240_60;
//
//		if (time >= 0 && time > mosttime) {
//			*weapon1 = g_Vars.currentplayer->gunheldarr[i].weapon1;
//			*weapon2 = g_Vars.currentplayer->gunheldarr[i].weapon2;
//			mosttime = time;
//		}
//	}
//}
