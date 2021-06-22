#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/bondgun.h"
#include "game/game_0b0fd0.h"
#include "game/inventory/inventory.h"
#include "game/training/training.h"
#include "game/lang.h"
#include "bss.h"
#include "lib/main.h"
#include "data.h"
#include "types.h"

void invClear(void)
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
void invSortItem(struct invitem *subject)
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

void invInsertItem(struct invitem *item)
{
	if (item->type == INVITEMTYPE_PROP) {
		struct prop *prop = item->type_prop.prop;

		if (prop && prop->obj) {
			struct textoverride *override = invGetTextOverrideForObj(prop->obj);
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

	invSortItem(item);
	invCalculateCurrentIndex();
}

void invRemoveItem(struct invitem *item)
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

	invCalculateCurrentIndex();
}

struct invitem *invFindUnusedSlot(void)
{
	s32 i;

	for (i = 0; i < g_Vars.currentplayer->equipmaxitems; i++) {
		if (g_Vars.currentplayer->equipment[i].type == -1) {
			return &g_Vars.currentplayer->equipment[i];
		}
	}

	return NULL;
}

void invSetAllGuns(bool enable)
{
	s32 weaponnum;

	g_Vars.currentplayer->equipallguns = enable;
	invCalculateCurrentIndex();
	weaponnum = invGetWeaponNumByIndex(g_Vars.currentplayer->equipcuritem);
	bgunEquipWeapon(weaponnum);
}

bool invHasAllGuns(void)
{
	return g_Vars.currentplayer->equipallguns;
}

struct invitem *invFindSingleWeapon(s32 weaponnum)
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

bool invHasSingleWeaponExcAllGuns(s32 weaponnum)
{
	return invFindSingleWeapon(weaponnum) != NULL;
}

struct invitem *invFindDoubleWeapon(s32 weapon1, s32 weapon2)
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

bool invHasDoubleWeaponExcAllGuns(s32 weapon1, s32 weapon2)
{
	return invFindDoubleWeapon(weapon1, weapon2) != NULL;
}

bool invHasSingleWeaponOrProp(s32 weaponnum)
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

s32 invAddOneIfCantHaveSlayer(s32 index)
{
	if (mainGetStageNum());

	if (mainGetStageNum() != STAGE_ATTACKSHIP
			&& mainGetStageNum() != STAGE_SKEDARRUINS
			&& index >= WEAPON_SLAYER) {
		index++;
	}

	return index;
}

s32 currentStageForbidsSlayer(void)
{
	bool forbids = false;

	if (mainGetStageNum() != STAGE_ATTACKSHIP && mainGetStageNum() != STAGE_SKEDARRUINS) {
		forbids = true;
	}

	return forbids;
}

bool invCanHaveAllGunsWeapon(s32 weaponnum)
{
	bool canhave = true;

	if (weaponnum == WEAPON_SLAYER) {
		canhave = false;
	}

	// @bug: The stage conditions need an OR. This condition can never pass.
	if ((mainGetStageNum() == STAGE_ATTACKSHIP && mainGetStageNum() == STAGE_SKEDARRUINS)
			&& weaponnum == WEAPON_SLAYER) {
		canhave = true;
	}

	return canhave;
}

bool invHasSingleWeaponIncAllGuns(s32 weaponnum)
{
	if (g_Vars.currentplayer->equipallguns &&
			weaponnum && weaponnum <= WEAPON_PSYCHOSISGUN &&
			invCanHaveAllGunsWeapon(weaponnum)) {
		return true;
	}

	return invHasSingleWeaponExcAllGuns(weaponnum);
}

bool invHasDoubleWeaponIncAllGuns(s32 weapon1, s32 weapon2)
{
	if (weapon2 == WEAPON_NONE) {
		return true;
	}

	if (g_Vars.currentplayer->equipallguns &&
			weapon1 <= WEAPON_PSYCHOSISGUN &&
			weapon1 == weapon2 &&
			weaponHasFlag(weapon1, WEAPONFLAG_DUALWIELD) &&
			invCanHaveAllGunsWeapon(weapon1)) {
		return true;
	}

	return invHasDoubleWeaponExcAllGuns(weapon1, weapon2);
}

bool invGiveSingleWeapon(s32 weaponnum)
{
	frSetWeaponFound(weaponnum);

	if (invHasSingleWeaponExcAllGuns(weaponnum) == 0) {
		struct invitem *item;

		if (g_Vars.currentplayer->equipallguns &&
				weaponnum <= WEAPON_PSYCHOSISGUN &&
				invCanHaveAllGunsWeapon(weaponnum)) {
			return false;
		}

		item = invFindUnusedSlot();

		if (item) {
			item->type = INVITEMTYPE_WEAP;
			item->type_weap.weapon1 = weaponnum;
			item->type_weap.pickuppad = -1;
			invInsertItem(item);
		}

		return true;
	}

	return false;
}

bool invGiveDoubleWeapon(s32 weapon1, s32 weapon2)
{
	if (invHasDoubleWeaponExcAllGuns(weapon1, weapon2) == 0) {
		if (weaponHasFlag(weapon1, WEAPONFLAG_DUALWIELD)) {
			struct invitem *item = invFindUnusedSlot();

			if (item) {
				item->type = INVITEMTYPE_DUAL;
				item->type_dual.weapon1 = weapon1;
				item->type_dual.weapon2 = weapon2;
				invInsertItem(item);
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

void invRemoveItemByNum(s32 weaponnum)
{
	if (g_Vars.currentplayer->weapons) {
		// Begin iterating from the second item in the list. This is required
		// because the item might be removed from the list when iterating it,
		// and it needs to determine when the end of the list has been reached.
		struct invitem *item = g_Vars.currentplayer->weapons->next;

		while (true) {
			// Have to preload this because item->next shouldn't be trusted
			// after calling invRemoveItem()
			struct invitem *next = item->next;

			if (item->type == INVITEMTYPE_PROP) {
				struct prop *prop = item->type_prop.prop;
				struct textoverride *override = invGetTextOverrideForObj(prop->obj);

				if (override && override->weapon == weaponnum) {
					invRemoveItem(item);
				}
			} else if (item->type == INVITEMTYPE_WEAP) {
				if (item->type_weap.weapon1 == weaponnum) {
					invRemoveItem(item);
				}
			} else if (item->type == INVITEMTYPE_DUAL) {
				if (item->type_dual.weapon1 == weaponnum || item->type_dual.weapon2 == weaponnum) {
					invRemoveItem(item);
				}
			}

			if (item == g_Vars.currentplayer->weapons || !g_Vars.currentplayer->weapons) {
				break;
			}

			item = next;
		}
	}
}

bool invGiveProp(struct prop *prop)
{
	struct invitem *item;

	// Don't add duplicate night vision to inventory
	// (night vision is already there when using perfect darkness)
	// Note that this check doesn't work on Investigation because it uses the
	// IR specs model. See bug note in Investigation's setup file (setupear.c).
	if (cheatIsActive(CHEAT_PERFECTDARKNESS)
			&& prop->type == PROPTYPE_OBJ
			&& prop->obj
			&& prop->obj->modelnum == MODEL_CHRNIGHTSIGHT) {
		return true;
	}

	item = invFindUnusedSlot();

	if (item) {
		item->type = INVITEMTYPE_PROP;
		item->type_prop.prop = prop;
		invInsertItem(item);
	}

	return true;
}

void invRemoveProp(struct prop *prop)
{
	if (g_Vars.currentplayer->weapons) {
		struct invitem *item = g_Vars.currentplayer->weapons->next;

		while (true) {
			struct invitem *next = item->next;

			if (item->type == INVITEMTYPE_PROP && item->type_prop.prop == prop) {
				invRemoveItem(item);
			}

			if (item == g_Vars.currentplayer->weapons || !g_Vars.currentplayer->weapons) {
				break;
			}

			item = next;
		}
	}
}

s32 invGiveWeaponsByProp(struct prop *prop)
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

			if (cheatIsActive(CHEAT_PERFECTDARKNESS) && weaponnum == WEAPON_NIGHTVISION) {
				return 1;
			}

			if (invGiveSingleWeapon(weaponnum)) {
				numgiven = 1;
			}

			if (g_Vars.normmplayerisrunning
					&& weaponHasFlag(weaponnum, WEAPONFLAG_DUALWIELD)
					&& !invHasDoubleWeaponExcAllGuns(weaponnum, weaponnum)) {
				struct invitem *invitem = invFindSingleWeapon(weaponnum);

				if (invitem) {
					if (invitem->type_weap.pickuppad < 0) {
						if (obj->pad >= 0) {
							invitem->type_weap.pickuppad = obj->pad;
						}
					} else if (obj->pad >= 0 && invitem->type_weap.pickuppad != obj->pad) {
						if (invGiveDoubleWeapon(weaponnum, weaponnum)) {
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
					numgiven = invHasDoubleWeaponExcAllGuns(otherweapon->weaponnum, weaponnum) == 0;
				} else {
					numgiven = invHasDoubleWeaponExcAllGuns(weaponnum, otherweapon->weaponnum) == 0;
				}

				weapon->dualweapon->dualweaponnum = weaponnum;
				weapon->dualweapon->dualweapon = NULL;
				weapon->dualweapon = NULL;
			} else if (weapon->dualweaponnum >= 0) {
				if (weapon->base.flags & OBJFLAG_WEAPON_LEFTHANDED) {
					if (invGiveDoubleWeapon(weapon->dualweaponnum, weaponnum)) {
						numgiven = 2;
					} else {
						numgiven = 0;
					}
				} else {
					if (invGiveDoubleWeapon(weaponnum, weapon->dualweaponnum)) {
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

GLOBAL_ASM(
glabel invChooseCycleForwardWeapon
/*  f1122ec:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f1122f0:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f1122f4:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
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
/*  f11235c:	00000000 */ 	nop
/*  f112360:	00e09025 */ 	or	$s2,$a3,$zero
/*  f112364:	10000069 */ 	b	.L0f11250c
/*  f112368:	00e0a025 */ 	or	$s4,$a3,$zero
.L0f11236c:
/*  f11236c:	260a0001 */ 	addiu	$t2,$s0,0x1
.L0f112370:
/*  f112370:	0151001a */ 	div	$zero,$t2,$s1
/*  f112374:	00008010 */ 	mfhi	$s0
/*  f112378:	260b0001 */ 	addiu	$t3,$s0,0x1
/*  f11237c:	16200002 */ 	bnez	$s1,.L0f112388
/*  f112380:	00000000 */ 	nop
/*  f112384:	0007000d */ 	break	0x7
.L0f112388:
/*  f112388:	2401ffff */ 	addiu	$at,$zero,-1
/*  f11238c:	16210004 */ 	bne	$s1,$at,.L0f1123a0
/*  f112390:	3c018000 */ 	lui	$at,0x8000
/*  f112394:	15410002 */ 	bne	$t2,$at,.L0f1123a0
/*  f112398:	00000000 */ 	nop
/*  f11239c:	0006000d */ 	break	0x6
.L0f1123a0:
/*  f1123a0:	1600000c */ 	bnez	$s0,.L0f1123d4
/*  f1123a4:	00000000 */ 	nop
/*  f1123a8:	0171001a */ 	div	$zero,$t3,$s1
/*  f1123ac:	00008010 */ 	mfhi	$s0
/*  f1123b0:	16200002 */ 	bnez	$s1,.L0f1123bc
/*  f1123b4:	00000000 */ 	nop
/*  f1123b8:	0007000d */ 	break	0x7
.L0f1123bc:
/*  f1123bc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1123c0:	16210004 */ 	bne	$s1,$at,.L0f1123d4
/*  f1123c4:	3c018000 */ 	lui	$at,0x8000
/*  f1123c8:	15610002 */ 	bne	$t3,$at,.L0f1123d4
/*  f1123cc:	00000000 */ 	nop
/*  f1123d0:	0006000d */ 	break	0x6
.L0f1123d4:
/*  f1123d4:	12600005 */ 	beqz	$s3,.L0f1123ec
/*  f1123d8:	00000000 */ 	nop
/*  f1123dc:	0fc28684 */ 	jal	bgun0f0a1a10
/*  f1123e0:	02002025 */ 	or	$a0,$s0,$zero
/*  f1123e4:	10400008 */ 	beqz	$v0,.L0f112408
/*  f1123e8:	00000000 */ 	nop
.L0f1123ec:
/*  f1123ec:	0fc4470c */ 	jal	invCanHaveAllGunsWeapon
/*  f1123f0:	02002025 */ 	or	$a0,$s0,$zero
/*  f1123f4:	10400004 */ 	beqz	$v0,.L0f112408
/*  f1123f8:	00000000 */ 	nop
/*  f1123fc:	02009025 */ 	or	$s2,$s0,$zero
/*  f112400:	10000042 */ 	b	.L0f11250c
/*  f112404:	0000a025 */ 	or	$s4,$zero,$zero
.L0f112408:
/*  f112408:	5612ffd9 */ 	bnel	$s0,$s2,.L0f112370
/*  f11240c:	260a0001 */ 	addiu	$t2,$s0,0x1
/*  f112410:	1000003f */ 	b	.L0f112510
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
/*  f112434:	00000000 */ 	nop
/*  f112438:	86040004 */ 	lh	$a0,0x4($s0)
/*  f11243c:	2881002d */ 	slti	$at,$a0,0x2d
/*  f112440:	10200026 */ 	beqz	$at,.L0f1124dc
/*  f112444:	0244082a */ 	slt	$at,$s2,$a0
/*  f112448:	10200024 */ 	beqz	$at,.L0f1124dc
/*  f11244c:	00000000 */ 	nop
/*  f112450:	52600007 */ 	beqzl	$s3,.L0f112470
/*  f112454:	00809025 */ 	or	$s2,$a0,$zero
/*  f112458:	0fc28684 */ 	jal	bgun0f0a1a10
/*  f11245c:	00000000 */ 	nop
/*  f112460:	1040001e */ 	beqz	$v0,.L0f1124dc
/*  f112464:	00000000 */ 	nop
/*  f112468:	86040004 */ 	lh	$a0,0x4($s0)
/*  f11246c:	00809025 */ 	or	$s2,$a0,$zero
.L0f112470:
/*  f112470:	10000026 */ 	b	.L0f11250c
/*  f112474:	0000a025 */ 	or	$s4,$zero,$zero
.L0f112478:
/*  f112478:	14410018 */ 	bne	$v0,$at,.L0f1124dc
/*  f11247c:	00000000 */ 	nop
/*  f112480:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f112484:	0244082a */ 	slt	$at,$s2,$a0
/*  f112488:	14200007 */ 	bnez	$at,.L0f1124a8
/*  f11248c:	00000000 */ 	nop
/*  f112490:	16440012 */ 	bne	$s2,$a0,.L0f1124dc
/*  f112494:	00000000 */ 	nop
/*  f112498:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*  f11249c:	028c082a */ 	slt	$at,$s4,$t4
/*  f1124a0:	1020000e */ 	beqz	$at,.L0f1124dc
/*  f1124a4:	00000000 */ 	nop
.L0f1124a8:
/*  f1124a8:	5260000a */ 	beqzl	$s3,.L0f1124d4
/*  f1124ac:	8e120004 */ 	lw	$s2,0x4($s0)
/*  f1124b0:	0fc28684 */ 	jal	bgun0f0a1a10
/*  f1124b4:	00000000 */ 	nop
/*  f1124b8:	54400006 */ 	bnezl	$v0,.L0f1124d4
/*  f1124bc:	8e120004 */ 	lw	$s2,0x4($s0)
/*  f1124c0:	0fc28684 */ 	jal	bgun0f0a1a10
/*  f1124c4:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f1124c8:	10400004 */ 	beqz	$v0,.L0f1124dc
/*  f1124cc:	00000000 */ 	nop
/*  f1124d0:	8e120004 */ 	lw	$s2,0x4($s0)
.L0f1124d4:
/*  f1124d4:	1000000d */ 	b	.L0f11250c
/*  f1124d8:	8e140008 */ 	lw	$s4,0x8($s0)
.L0f1124dc:
/*  f1124dc:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x284)
/*  f1124e0:	8dada244 */ 	lw	$t5,%lo(g_Vars+0x284)($t5)
/*  f1124e4:	8e10000c */ 	lw	$s0,0xc($s0)
/*  f1124e8:	8dae1864 */ 	lw	$t6,0x1864($t5)
/*  f1124ec:	160e0005 */ 	bne	$s0,$t6,.L0f112504
/*  f1124f0:	00000000 */ 	nop
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

void invChooseCycleBackWeapon(s32 *ptr1, s32 *ptr2, bool arg2)
{
	s32 weapon1 = *ptr1;
	s32 weapon2 = *ptr2;

	if (g_Vars.currentplayer->equipallguns) {
		s32 candidate = *ptr1;

		if (weaponHasFlag(weapon1, WEAPONFLAG_DUALWIELD) && weapon1 == weapon2) {
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
			} while ((arg2 && !bgun0f0a1a10(candidate)) || !invCanHaveAllGunsWeapon(candidate));

			if (weaponHasFlag(candidate, WEAPONFLAG_DUALWIELD)) {
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

bool invHasKeyFlags(u32 wantkeyflags)
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

bool func0f11283c(void)
{
	return false;
}

bool invHasBriefcase(void)
{
	if (g_Vars.currentplayer->isdead == false) {
		return invHasSingleWeaponExcAllGuns(WEAPON_BRIEFCASE2);
	}

	return false;
}

bool invHasDataUplink(void)
{
	if (g_Vars.currentplayer->isdead == false) {
		return invHasSingleWeaponExcAllGuns(WEAPON_DATAUPLINK);
	}

	return false;
}

bool func0f1128c4(void)
{
	return false;
}

bool invHasProp(struct prop *prop)
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

s32 invGetCount(void)
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
						if (obj->hidden & OBJHFLAG_HASTEXTOVERRIDE) {
							numitems++;
						}
					} else if (prop->type == PROPTYPE_OBJ) {
						if ((obj->flags2 & OBJFLAG2_00040000) == 0) {
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

struct invitem *invGetItemByIndex(s32 index)
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
						if (obj->hidden & OBJHFLAG_HASTEXTOVERRIDE) {
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

struct textoverride *invGetTextOverrideForObj(struct defaultobj *obj)
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

struct textoverride *invGetTextOverrideForWeapon(s32 weaponnum)
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

s32 invGetWeaponNumByIndex(s32 index)
{
	struct invitem *item = invGetItemByIndex(index);

	if (item) {
		if (item->type == INVITEMTYPE_PROP) {
			struct prop *prop = item->type_prop.prop;
			struct textoverride *override = invGetTextOverrideForObj(prop->obj);

			if (override) {
				return override->weapon;
			}
		} else if (item->type == INVITEMTYPE_WEAP) {
			return item->type_weap.weapon1;
		}
	} else if (g_Vars.currentplayer->equipallguns) {
		if (index < WEAPON_PSYCHOSISGUN - currentStageForbidsSlayer()) {
			index++;
			return invAddOneIfCantHaveSlayer(index);
		}
	}

	return 0;
}

u16 invGetNameIdByIndex(s32 index)
{
	struct invitem *item = invGetItemByIndex(index);
	s32 weaponnum = 0;
	struct textoverride *override;

	if (item) {
		if (item->type == INVITEMTYPE_PROP) {
			struct prop *prop = item->type_prop.prop;
			override = invGetTextOverrideForObj(prop->obj);

			if (override) {
				if (override->unk14) {
					return override->unk14;
				}

				weaponnum = override->weapon;
			}
		} else if (item->type == INVITEMTYPE_WEAP) {
			weaponnum = item->type_weap.weapon1;
			override = invGetTextOverrideForWeapon(weaponnum);

			if (override && override->unk14) {
				return override->unk14;
			}
		}
	} else {
		if (g_Vars.currentplayer->equipallguns) {
			if (index < WEAPON_PSYCHOSISGUN - currentStageForbidsSlayer()) {
				index++;
				return bgunGetNameId(invAddOneIfCantHaveSlayer(index));
			}
		}
	}

	return bgunGetNameId(weaponnum);
}

char *invGetNameByIndex(s32 index)
{
	return langGet(invGetNameIdByIndex(index));
}

char *invGetShortNameByIndex(s32 index)
{
	struct invitem *item = invGetItemByIndex(index);
	s32 weaponnum = 0;
	struct textoverride *override;

	if (item) {
		if (item->type == INVITEMTYPE_PROP) {
			struct prop *prop = item->type_prop.prop;
			override = invGetTextOverrideForObj(prop->obj);

			if (override) {
				if (override->unk14) {
					return langGet(override->unk14);
				}

				weaponnum = override->weapon;
			}
		} else if (item->type == INVITEMTYPE_WEAP) {
			weaponnum = item->type_weap.weapon1;
			override = invGetTextOverrideForWeapon(weaponnum);

			if (override && override->unk14) {
				return langGet(override->unk14);
			}
		}
	} else if (g_Vars.currentplayer->equipallguns) {
		if (index < WEAPON_PSYCHOSISGUN - currentStageForbidsSlayer()) {
			index++;
			return bgunGetShortName(invAddOneIfCantHaveSlayer(index));
		}
	}

	return bgunGetShortName(weaponnum);
}

void invInsertTextOverride(struct textoverride *override)
{
	override->next = g_Vars.textoverrides;
	g_Vars.textoverrides = override;
}

u32 invGetCurrentIndex(void)
{
	return g_Vars.currentplayer->equipcuritem;
}

void invSetCurrentIndex(u32 item)
{
	g_Vars.currentplayer->equipcuritem = item;
}

void invCalculateCurrentIndex(void)
{
	s32 curweaponnum = bgunGetWeaponNum(HAND_RIGHT);
	s32 i;

	g_Vars.currentplayer->equipcuritem = 0;

	for (i = 0; i < invGetCount(); i++) {
		if (invGetWeaponNumByIndex(i) == curweaponnum) {
			g_Vars.currentplayer->equipcuritem = i;
			break;
		}
	}
}

char *invGetActivatedTextByObj(struct defaultobj *obj)
{
	struct textoverride *override = invGetTextOverrideForObj(obj);

	if (override && override->activatetextid) {
		return langGet(override->activatetextid);
	}

	return NULL;
}

char *invGetActivatedTextByWeaponNum(s32 weaponnum)
{
	struct textoverride *override = invGetTextOverrideForWeapon(weaponnum);

	if (override && override->activatetextid) {
		return langGet(override->activatetextid);
	}

	return NULL;
}

void invIncrementHeldTime(s32 weapon1, s32 weapon2)
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

	for (i = 0; i < ARRAYCOUNT(g_Vars.currentplayer->gunheldarr); i++) {
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
			i = ARRAYCOUNT(g_Vars.currentplayer->gunheldarr);
			break;
		}
	}

	if (i == ARRAYCOUNT(g_Vars.currentplayer->gunheldarr)) {
		g_Vars.currentplayer->gunheldarr[leastusedindex].totaltime240_60 = g_Vars.lvupdate240_60;
		g_Vars.currentplayer->gunheldarr[leastusedindex].weapon1 = weapon1;
		g_Vars.currentplayer->gunheldarr[leastusedindex].weapon2 = weapon2;
	}
}

void invGetWeaponOfChoice(s32 *weapon1, s32 *weapon2)
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
