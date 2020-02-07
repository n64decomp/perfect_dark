#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "types.h"
#include "game/game_097a50.h"
#include "game/game_0b0420.h"
#include "game/cheats.h"
#include "game/game_111600.h"
#include "game/game_16cfa0.h"
#include "game/game_19c990.h"
#include "game/lang.h"

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

GLOBAL_ASM(
glabel func0f11179c
/*  f11179c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1117a0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1117a4:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f1117a8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1117ac:	00802825 */ 	or	$a1,$a0,$zero
/*  f1117b0:	15c1002b */ 	bne	$t6,$at,.L0f111860
/*  f1117b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1117b8:	8c860004 */ 	lw	$a2,0x4($a0)
/*  f1117bc:	10c00028 */ 	beqz	$a2,.L0f111860
/*  f1117c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1117c4:	8cc40004 */ 	lw	$a0,0x4($a2)
/*  f1117c8:	10800025 */ 	beqz	$a0,.L0f111860
/*  f1117cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1117d0:	afa50020 */ 	sw	$a1,0x20($sp)
/*  f1117d4:	0fc44af0 */ 	jal	objGetTextOverride
/*  f1117d8:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f1117dc:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f1117e0:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f1117e4:	10400013 */ 	beqz	$v0,.L0f111834
/*  f1117e8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1117ec:	8c430008 */ 	lw	$v1,0x8($v0)
/*  f1117f0:	18600004 */ 	blez	$v1,.L0f111804
/*  f1117f4:	28610051 */ 	slti	$at,$v1,0x51
/*  f1117f8:	50200003 */ 	beqzl	$at,.L0f111808
/*  f1117fc:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f111800:	00002025 */ 	or	$a0,$zero,$zero
.L0f111804:
/*  f111804:	2401005b */ 	addiu	$at,$zero,0x5b
.L0f111808:
/*  f111808:	54610003 */ 	bnel	$v1,$at,.L0f111818
/*  f11180c:	2401005d */ 	addiu	$at,$zero,0x5d
/*  f111810:	00002025 */ 	or	$a0,$zero,$zero
/*  f111814:	2401005d */ 	addiu	$at,$zero,0x5d
.L0f111818:
/*  f111818:	54610003 */ 	bnel	$v1,$at,.L0f111828
/*  f11181c:	24010057 */ 	addiu	$at,$zero,0x57
/*  f111820:	00002025 */ 	or	$a0,$zero,$zero
/*  f111824:	24010057 */ 	addiu	$at,$zero,0x57
.L0f111828:
/*  f111828:	14610002 */ 	bne	$v1,$at,.L0f111834
/*  f11182c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f111830:	00002025 */ 	or	$a0,$zero,$zero
.L0f111834:
/*  f111834:	1080000a */ 	beqz	$a0,.L0f111860
/*  f111838:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11183c:	90cf0000 */ 	lbu	$t7,0x0($a2)
/*  f111840:	24010001 */ 	addiu	$at,$zero,0x1
/*  f111844:	15e10006 */ 	bne	$t7,$at,.L0f111860
/*  f111848:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11184c:	8cc20004 */ 	lw	$v0,0x4($a2)
/*  f111850:	3c010004 */ 	lui	$at,0x4
/*  f111854:	8c58000c */ 	lw	$t8,0xc($v0)
/*  f111858:	0301c825 */ 	or	$t9,$t8,$at
/*  f11185c:	ac59000c */ 	sw	$t9,0xc($v0)
.L0f111860:
/*  f111860:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f111864:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f111868:	8c680284 */ 	lw	$t0,0x284($v1)
/*  f11186c:	8d021864 */ 	lw	$v0,0x1864($t0)
/*  f111870:	5040000b */ 	beqzl	$v0,.L0f1118a0
/*  f111874:	aca5000c */ 	sw	$a1,0xc($a1)
/*  f111878:	aca2000c */ 	sw	$v0,0xc($a1)
/*  f11187c:	8c690284 */ 	lw	$t1,0x284($v1)
/*  f111880:	8d2a1864 */ 	lw	$t2,0x1864($t1)
/*  f111884:	8d4b0010 */ 	lw	$t3,0x10($t2)
/*  f111888:	acab0010 */ 	sw	$t3,0x10($a1)
/*  f11188c:	ac450010 */ 	sw	$a1,0x10($v0)
/*  f111890:	8cad0010 */ 	lw	$t5,0x10($a1)
/*  f111894:	10000003 */ 	beqz	$zero,.L0f1118a4
/*  f111898:	ada5000c */ 	sw	$a1,0xc($t5)
/*  f11189c:	aca5000c */ 	sw	$a1,0xc($a1)
.L0f1118a0:
/*  f1118a0:	aca50010 */ 	sw	$a1,0x10($a1)
.L0f1118a4:
/*  f1118a4:	8c6e0284 */ 	lw	$t6,0x284($v1)
/*  f1118a8:	00a02025 */ 	or	$a0,$a1,$zero
/*  f1118ac:	0fc44597 */ 	jal	currentPlayerSortInvItem
/*  f1118b0:	adc51864 */ 	sw	$a1,0x1864($t6)
/*  f1118b4:	0fc44bdc */ 	jal	func0f112f70
/*  f1118b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1118bc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1118c0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1118c4:	03e00008 */ 	jr	$ra
/*  f1118c8:	00000000 */ 	sll	$zero,$zero,0x0
);

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

	func0f112f70();
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
	func0f112f70();
	weaponnum = func0f112c44(g_Vars.currentplayer->equipcuritem);
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

bool currentStageForbidsSlayer(void)
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
			func0f11179c(item);
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
				func0f11179c(item);
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

GLOBAL_ASM(
glabel func0f111ea4
/*  f111ea4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f111ea8:	3c0e800a */ 	lui	$t6,0x800a
/*  f111eac:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f111eb0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f111eb4:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f111eb8:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f111ebc:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f111ec0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f111ec4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f111ec8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f111ecc:	8dc31864 */ 	lw	$v1,0x1864($t6)
/*  f111ed0:	00808825 */ 	or	$s1,$a0,$zero
/*  f111ed4:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f111ed8:	10600033 */ 	beqz	$v1,.L0f111fa8
/*  f111edc:	24150003 */ 	addiu	$s5,$zero,0x3
/*  f111ee0:	8c70000c */ 	lw	$s0,0xc($v1)
/*  f111ee4:	24130002 */ 	addiu	$s3,$zero,0x2
.L0f111ee8:
/*  f111ee8:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f111eec:	8e12000c */ 	lw	$s2,0xc($s0)
/*  f111ef0:	1662000f */ 	bne	$s3,$v0,.L0f111f30
/*  f111ef4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f111ef8:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f111efc:	0fc44af0 */ 	jal	objGetTextOverride
/*  f111f00:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f111f04:	10400006 */ 	beqz	$v0,.L0f111f20
/*  f111f08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f111f0c:	8c4f0008 */ 	lw	$t7,0x8($v0)
/*  f111f10:	162f0003 */ 	bne	$s1,$t7,.L0f111f20
/*  f111f14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f111f18:	0fc44633 */ 	jal	currentPlayerRemoveInvItem
/*  f111f1c:	02002025 */ 	or	$a0,$s0,$zero
.L0f111f20:
/*  f111f20:	3c18800a */ 	lui	$t8,0x800a
/*  f111f24:	8f18a244 */ 	lw	$t8,-0x5dbc($t8)
/*  f111f28:	10000019 */ 	beqz	$zero,.L0f111f90
/*  f111f2c:	8f031864 */ 	lw	$v1,0x1864($t8)
.L0f111f30:
/*  f111f30:	1682000a */ 	bne	$s4,$v0,.L0f111f5c
/*  f111f34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f111f38:	86190004 */ 	lh	$t9,0x4($s0)
/*  f111f3c:	16390014 */ 	bne	$s1,$t9,.L0f111f90
/*  f111f40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f111f44:	0fc44633 */ 	jal	currentPlayerRemoveInvItem
/*  f111f48:	02002025 */ 	or	$a0,$s0,$zero
/*  f111f4c:	3c08800a */ 	lui	$t0,0x800a
/*  f111f50:	8d08a244 */ 	lw	$t0,-0x5dbc($t0)
/*  f111f54:	1000000e */ 	beqz	$zero,.L0f111f90
/*  f111f58:	8d031864 */ 	lw	$v1,0x1864($t0)
.L0f111f5c:
/*  f111f5c:	16a2000c */ 	bne	$s5,$v0,.L0f111f90
/*  f111f60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f111f64:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f111f68:	12290004 */ 	beq	$s1,$t1,.L0f111f7c
/*  f111f6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f111f70:	8e0a0008 */ 	lw	$t2,0x8($s0)
/*  f111f74:	162a0006 */ 	bne	$s1,$t2,.L0f111f90
/*  f111f78:	00000000 */ 	sll	$zero,$zero,0x0
.L0f111f7c:
/*  f111f7c:	0fc44633 */ 	jal	currentPlayerRemoveInvItem
/*  f111f80:	02002025 */ 	or	$a0,$s0,$zero
/*  f111f84:	3c0b800a */ 	lui	$t3,0x800a
/*  f111f88:	8d6ba244 */ 	lw	$t3,-0x5dbc($t3)
/*  f111f8c:	8d631864 */ 	lw	$v1,0x1864($t3)
.L0f111f90:
/*  f111f90:	52030006 */ 	beql	$s0,$v1,.L0f111fac
/*  f111f94:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f111f98:	50600004 */ 	beqzl	$v1,.L0f111fac
/*  f111f9c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f111fa0:	1000ffd1 */ 	beqz	$zero,.L0f111ee8
/*  f111fa4:	02408025 */ 	or	$s0,$s2,$zero
.L0f111fa8:
/*  f111fa8:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f111fac:
/*  f111fac:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f111fb0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f111fb4:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f111fb8:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f111fbc:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f111fc0:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f111fc4:	03e00008 */ 	jr	$ra
/*  f111fc8:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

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
		func0f11179c(item);
	}

	return true;
}

GLOBAL_ASM(
glabel func0f112054
/*  f112054:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f112058:	3c0e800a */ 	lui	$t6,0x800a
/*  f11205c:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f112060:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f112064:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f112068:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f11206c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f112070:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f112074:	8dc21864 */ 	lw	$v0,0x1864($t6)
/*  f112078:	00809025 */ 	or	$s2,$a0,$zero
/*  f11207c:	24130002 */ 	addiu	$s3,$zero,0x2
/*  f112080:	50400015 */ 	beqzl	$v0,.L0f1120d8
/*  f112084:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f112088:	8c50000c */ 	lw	$s0,0xc($v0)
.L0f11208c:
/*  f11208c:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f112090:	8e11000c */ 	lw	$s1,0xc($s0)
/*  f112094:	166f0009 */ 	bne	$s3,$t7,.L0f1120bc
/*  f112098:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11209c:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f1120a0:	16580006 */ 	bne	$s2,$t8,.L0f1120bc
/*  f1120a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1120a8:	0fc44633 */ 	jal	currentPlayerRemoveInvItem
/*  f1120ac:	02002025 */ 	or	$a0,$s0,$zero
/*  f1120b0:	3c19800a */ 	lui	$t9,0x800a
/*  f1120b4:	8f39a244 */ 	lw	$t9,-0x5dbc($t9)
/*  f1120b8:	8f221864 */ 	lw	$v0,0x1864($t9)
.L0f1120bc:
/*  f1120bc:	52020006 */ 	beql	$s0,$v0,.L0f1120d8
/*  f1120c0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1120c4:	50400004 */ 	beqzl	$v0,.L0f1120d8
/*  f1120c8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1120cc:	1000ffef */ 	beqz	$zero,.L0f11208c
/*  f1120d0:	02208025 */ 	or	$s0,$s1,$zero
/*  f1120d4:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f1120d8:
/*  f1120d8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1120dc:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1120e0:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f1120e4:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f1120e8:	03e00008 */ 	jr	$ra
/*  f1120ec:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

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
glabel func0f112790
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
/*  f11283c:	03e00008 */ 	jr	$ra
/*  f112840:	00001025 */ 	or	$v0,$zero,$zero
);

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

GLOBAL_ASM(
glabel currentPlayerHasProp
/*  f1128cc:	3c03800a */ 	lui	$v1,0x800a
/*  f1128d0:	8c63a244 */ 	lw	$v1,-0x5dbc($v1)
/*  f1128d4:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f1128d8:	8c651864 */ 	lw	$a1,0x1864($v1)
/*  f1128dc:	10a0000e */ 	beqz	$a1,.L0f112918
/*  f1128e0:	00a01025 */ 	or	$v0,$a1,$zero
/*  f1128e4:	8c4e0000 */ 	lw	$t6,0x0($v0)
.L0f1128e8:
/*  f1128e8:	54ce0007 */ 	bnel	$a2,$t6,.L0f112908
/*  f1128ec:	8c42000c */ 	lw	$v0,0xc($v0)
/*  f1128f0:	8c4f0004 */ 	lw	$t7,0x4($v0)
/*  f1128f4:	548f0004 */ 	bnel	$a0,$t7,.L0f112908
/*  f1128f8:	8c42000c */ 	lw	$v0,0xc($v0)
/*  f1128fc:	03e00008 */ 	jr	$ra
/*  f112900:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f112904:	8c42000c */ 	lw	$v0,0xc($v0)
.L0f112908:
/*  f112908:	50450004 */ 	beql	$v0,$a1,.L0f11291c
/*  f11290c:	8c7800bc */ 	lw	$t8,0xbc($v1)
/*  f112910:	5440fff5 */ 	bnezl	$v0,.L0f1128e8
/*  f112914:	8c4e0000 */ 	lw	$t6,0x0($v0)
.L0f112918:
/*  f112918:	8c7800bc */ 	lw	$t8,0xbc($v1)
.L0f11291c:
/*  f11291c:	8f02001c */ 	lw	$v0,0x1c($t8)
/*  f112920:	50400009 */ 	beqzl	$v0,.L0f112948
/*  f112924:	00001025 */ 	or	$v0,$zero,$zero
.L0f112928:
/*  f112928:	54440004 */ 	bnel	$v0,$a0,.L0f11293c
/*  f11292c:	8c420020 */ 	lw	$v0,0x20($v0)
/*  f112930:	03e00008 */ 	jr	$ra
/*  f112934:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f112938:	8c420020 */ 	lw	$v0,0x20($v0)
.L0f11293c:
/*  f11293c:	1440fffa */ 	bnez	$v0,.L0f112928
/*  f112940:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112944:	00001025 */ 	or	$v0,$zero,$zero
.L0f112948:
/*  f112948:	03e00008 */ 	jr	$ra
/*  f11294c:	00000000 */ 	sll	$zero,$zero,0x0
);

// regalloc when assigning item and first
//bool currentPlayerHasProp(struct prop *prop)
//{
//	struct invitem *item = g_Vars.currentplayer->weapons;
//	struct invitem *first = item;
//	struct prop *child;
//
//	while (item) {
//		if (item->type == INVITEMTYPE_PROP && item->type_prop.prop == prop) {
//			return true;
//		}
//
//		item = item->next;
//
//		if (item == first) {
//			break;
//		}
//	}
//
//	child = g_Vars.currentplayer->prop->child;
//
//	while (child) {
//		if (child == prop) {
//			return true;
//		}
//
//		child = child->next;
//	}
//
//	return false;
//}

GLOBAL_ASM(
glabel func0f112950
/*  f112950:	3c08800a */ 	lui	$t0,0x800a
/*  f112954:	8d08a244 */ 	lw	$t0,-0x5dbc($t0)
/*  f112958:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f11295c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f112960:	8d0e1870 */ 	lw	$t6,0x1870($t0)
/*  f112964:	00003025 */ 	or	$a2,$zero,$zero
/*  f112968:	51c00008 */ 	beqzl	$t6,.L0f11298c
/*  f11296c:	8d091864 */ 	lw	$t1,0x1864($t0)
/*  f112970:	0fc446fa */ 	jal	currentStageForbidsSlayer
/*  f112974:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112978:	240f002c */ 	addiu	$t7,$zero,0x2c
/*  f11297c:	3c08800a */ 	lui	$t0,0x800a
/*  f112980:	8d08a244 */ 	lw	$t0,-0x5dbc($t0)
/*  f112984:	01e23023 */ 	subu	$a2,$t7,$v0
/*  f112988:	8d091864 */ 	lw	$t1,0x1864($t0)
.L0f11298c:
/*  f11298c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f112990:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f112994:	1120002e */ 	beqz	$t1,.L0f112a50
/*  f112998:	01202825 */ 	or	$a1,$t1,$zero
/*  f11299c:	3c0c0004 */ 	lui	$t4,0x4
/*  f1129a0:	240b0004 */ 	addiu	$t3,$zero,0x4
/*  f1129a4:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f1129a8:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f1129ac:	8ca20000 */ 	lw	$v0,0x0($a1)
.L0f1129b0:
/*  f1129b0:	15420018 */ 	bne	$t2,$v0,.L0f112a14
/*  f1129b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1129b8:	8ca20004 */ 	lw	$v0,0x4($a1)
/*  f1129bc:	50400020 */ 	beqzl	$v0,.L0f112a40
/*  f1129c0:	8ca5000c */ 	lw	$a1,0xc($a1)
/*  f1129c4:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f1129c8:	5060001d */ 	beqzl	$v1,.L0f112a40
/*  f1129cc:	8ca5000c */ 	lw	$a1,0xc($a1)
/*  f1129d0:	90440000 */ 	lbu	$a0,0x0($v0)
/*  f1129d4:	15640007 */ 	bne	$t3,$a0,.L0f1129f4
/*  f1129d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1129dc:	8c780040 */ 	lw	$t8,0x40($v1)
/*  f1129e0:	33190400 */ 	andi	$t9,$t8,0x400
/*  f1129e4:	53200016 */ 	beqzl	$t9,.L0f112a40
/*  f1129e8:	8ca5000c */ 	lw	$a1,0xc($a1)
/*  f1129ec:	10000013 */ 	beqz	$zero,.L0f112a3c
/*  f1129f0:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f1129f4:
/*  f1129f4:	54e40012 */ 	bnel	$a3,$a0,.L0f112a40
/*  f1129f8:	8ca5000c */ 	lw	$a1,0xc($a1)
/*  f1129fc:	8c6d000c */ 	lw	$t5,0xc($v1)
/*  f112a00:	01ac7024 */ 	and	$t6,$t5,$t4
/*  f112a04:	55c0000e */ 	bnezl	$t6,.L0f112a40
/*  f112a08:	8ca5000c */ 	lw	$a1,0xc($a1)
/*  f112a0c:	1000000b */ 	beqz	$zero,.L0f112a3c
/*  f112a10:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f112a14:
/*  f112a14:	54e2000a */ 	bnel	$a3,$v0,.L0f112a40
/*  f112a18:	8ca5000c */ 	lw	$a1,0xc($a1)
/*  f112a1c:	8d0f1870 */ 	lw	$t7,0x1870($t0)
/*  f112a20:	51e00006 */ 	beqzl	$t7,.L0f112a3c
/*  f112a24:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f112a28:	84b80004 */ 	lh	$t8,0x4($a1)
/*  f112a2c:	2b01002d */ 	slti	$at,$t8,0x2d
/*  f112a30:	54200003 */ 	bnezl	$at,.L0f112a40
/*  f112a34:	8ca5000c */ 	lw	$a1,0xc($a1)
/*  f112a38:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f112a3c:
/*  f112a3c:	8ca5000c */ 	lw	$a1,0xc($a1)
.L0f112a40:
/*  f112a40:	10a90003 */ 	beq	$a1,$t1,.L0f112a50
/*  f112a44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112a48:	54a0ffd9 */ 	bnezl	$a1,.L0f1129b0
/*  f112a4c:	8ca20000 */ 	lw	$v0,0x0($a1)
.L0f112a50:
/*  f112a50:	03e00008 */ 	jr	$ra
/*  f112a54:	00c01025 */ 	or	$v0,$a2,$zero
);

GLOBAL_ASM(
glabel func0f112a58
/*  f112a58:	3c08800a */ 	lui	$t0,0x800a
/*  f112a5c:	8d08a244 */ 	lw	$t0,-0x5dbc($t0)
/*  f112a60:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f112a64:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f112a68:	8d0e1870 */ 	lw	$t6,0x1870($t0)
/*  f112a6c:	00802825 */ 	or	$a1,$a0,$zero
/*  f112a70:	51c00013 */ 	beqzl	$t6,.L0f112ac0
/*  f112a74:	8d091864 */ 	lw	$t1,0x1864($t0)
/*  f112a78:	0fc446fa */ 	jal	currentStageForbidsSlayer
/*  f112a7c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f112a80:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f112a84:	240f002c */ 	addiu	$t7,$zero,0x2c
/*  f112a88:	01e2c023 */ 	subu	$t8,$t7,$v0
/*  f112a8c:	00b8082a */ 	slt	$at,$a1,$t8
/*  f112a90:	10200003 */ 	beqz	$at,.L0f112aa0
/*  f112a94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112a98:	10000045 */ 	beqz	$zero,.L0f112bb0
/*  f112a9c:	00001025 */ 	or	$v0,$zero,$zero
.L0f112aa0:
/*  f112aa0:	0fc446fa */ 	jal	currentStageForbidsSlayer
/*  f112aa4:	afa50018 */ 	sw	$a1,0x18($sp)
/*  f112aa8:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f112aac:	3c08800a */ 	lui	$t0,0x800a
/*  f112ab0:	8d08a244 */ 	lw	$t0,-0x5dbc($t0)
/*  f112ab4:	00a22821 */ 	addu	$a1,$a1,$v0
/*  f112ab8:	24a5ffd4 */ 	addiu	$a1,$a1,-44
/*  f112abc:	8d091864 */ 	lw	$t1,0x1864($t0)
.L0f112ac0:
/*  f112ac0:	3c0c0004 */ 	lui	$t4,0x4
/*  f112ac4:	240b0004 */ 	addiu	$t3,$zero,0x4
/*  f112ac8:	11200038 */ 	beqz	$t1,.L0f112bac
/*  f112acc:	01203025 */ 	or	$a2,$t1,$zero
/*  f112ad0:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f112ad4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f112ad8:	8cc20000 */ 	lw	$v0,0x0($a2)
.L0f112adc:
/*  f112adc:	15420020 */ 	bne	$t2,$v0,.L0f112b60
/*  f112ae0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112ae4:	8cc20004 */ 	lw	$v0,0x4($a2)
/*  f112ae8:	5040002c */ 	beqzl	$v0,.L0f112b9c
/*  f112aec:	8cc6000c */ 	lw	$a2,0xc($a2)
/*  f112af0:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f112af4:	50600029 */ 	beqzl	$v1,.L0f112b9c
/*  f112af8:	8cc6000c */ 	lw	$a2,0xc($a2)
/*  f112afc:	90440000 */ 	lbu	$a0,0x0($v0)
/*  f112b00:	1564000b */ 	bne	$t3,$a0,.L0f112b30
/*  f112b04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112b08:	8c790040 */ 	lw	$t9,0x40($v1)
/*  f112b0c:	332d0400 */ 	andi	$t5,$t9,0x400
/*  f112b10:	51a00022 */ 	beqzl	$t5,.L0f112b9c
/*  f112b14:	8cc6000c */ 	lw	$a2,0xc($a2)
/*  f112b18:	14a00003 */ 	bnez	$a1,.L0f112b28
/*  f112b1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112b20:	10000023 */ 	beqz	$zero,.L0f112bb0
/*  f112b24:	00c01025 */ 	or	$v0,$a2,$zero
.L0f112b28:
/*  f112b28:	1000001b */ 	beqz	$zero,.L0f112b98
/*  f112b2c:	24a5ffff */ 	addiu	$a1,$a1,-1
.L0f112b30:
/*  f112b30:	54e4001a */ 	bnel	$a3,$a0,.L0f112b9c
/*  f112b34:	8cc6000c */ 	lw	$a2,0xc($a2)
/*  f112b38:	8c6e000c */ 	lw	$t6,0xc($v1)
/*  f112b3c:	01cc7824 */ 	and	$t7,$t6,$t4
/*  f112b40:	55e00016 */ 	bnezl	$t7,.L0f112b9c
/*  f112b44:	8cc6000c */ 	lw	$a2,0xc($a2)
/*  f112b48:	14a00003 */ 	bnez	$a1,.L0f112b58
/*  f112b4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112b50:	10000017 */ 	beqz	$zero,.L0f112bb0
/*  f112b54:	00c01025 */ 	or	$v0,$a2,$zero
.L0f112b58:
/*  f112b58:	1000000f */ 	beqz	$zero,.L0f112b98
/*  f112b5c:	24a5ffff */ 	addiu	$a1,$a1,-1
.L0f112b60:
/*  f112b60:	54e2000e */ 	bnel	$a3,$v0,.L0f112b9c
/*  f112b64:	8cc6000c */ 	lw	$a2,0xc($a2)
/*  f112b68:	8d181870 */ 	lw	$t8,0x1870($t0)
/*  f112b6c:	13000005 */ 	beqz	$t8,.L0f112b84
/*  f112b70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112b74:	84d90004 */ 	lh	$t9,0x4($a2)
/*  f112b78:	2b21002d */ 	slti	$at,$t9,0x2d
/*  f112b7c:	54200007 */ 	bnezl	$at,.L0f112b9c
/*  f112b80:	8cc6000c */ 	lw	$a2,0xc($a2)
.L0f112b84:
/*  f112b84:	54a00004 */ 	bnezl	$a1,.L0f112b98
/*  f112b88:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f112b8c:	10000008 */ 	beqz	$zero,.L0f112bb0
/*  f112b90:	00c01025 */ 	or	$v0,$a2,$zero
/*  f112b94:	24a5ffff */ 	addiu	$a1,$a1,-1
.L0f112b98:
/*  f112b98:	8cc6000c */ 	lw	$a2,0xc($a2)
.L0f112b9c:
/*  f112b9c:	50c90004 */ 	beql	$a2,$t1,.L0f112bb0
/*  f112ba0:	00001025 */ 	or	$v0,$zero,$zero
/*  f112ba4:	54c0ffcd */ 	bnezl	$a2,.L0f112adc
/*  f112ba8:	8cc20000 */ 	lw	$v0,0x0($a2)
.L0f112bac:
/*  f112bac:	00001025 */ 	or	$v0,$zero,$zero
.L0f112bb0:
/*  f112bb0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f112bb4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f112bb8:	03e00008 */ 	jr	$ra
/*  f112bbc:	00000000 */ 	sll	$zero,$zero,0x0
);

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

GLOBAL_ASM(
glabel func0f112bfc
/*  f112bfc:	3c03800a */ 	lui	$v1,0x800a
/*  f112c00:	8c63a278 */ 	lw	$v1,-0x5d88($v1)
/*  f112c04:	00001025 */ 	or	$v0,$zero,$zero
/*  f112c08:	1060000c */ 	beqz	$v1,.L0f112c3c
/*  f112c0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112c10:	8c6e0004 */ 	lw	$t6,0x4($v1)
.L0f112c14:
/*  f112c14:	55c00007 */ 	bnezl	$t6,.L0f112c34
/*  f112c18:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f112c1c:	8c6f0008 */ 	lw	$t7,0x8($v1)
/*  f112c20:	548f0004 */ 	bnel	$a0,$t7,.L0f112c34
/*  f112c24:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f112c28:	03e00008 */ 	jr	$ra
/*  f112c2c:	00601025 */ 	or	$v0,$v1,$zero
/*  f112c30:	8c630020 */ 	lw	$v1,0x20($v1)
.L0f112c34:
/*  f112c34:	5460fff7 */ 	bnezl	$v1,.L0f112c14
/*  f112c38:	8c6e0004 */ 	lw	$t6,0x4($v1)
.L0f112c3c:
/*  f112c3c:	03e00008 */ 	jr	$ra
/*  f112c40:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f112c44
/*  f112c44:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f112c48:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f112c4c:	0fc44a96 */ 	jal	func0f112a58
/*  f112c50:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f112c54:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f112c58:	10400011 */ 	beqz	$v0,.L0f112ca0
/*  f112c5c:	00401825 */ 	or	$v1,$v0,$zero
/*  f112c60:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f112c64:	24010002 */ 	addiu	$at,$zero,0x2
/*  f112c68:	54810009 */ 	bnel	$a0,$at,.L0f112c90
/*  f112c6c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f112c70:	8c420004 */ 	lw	$v0,0x4($v0)
/*  f112c74:	0fc44af0 */ 	jal	objGetTextOverride
/*  f112c78:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f112c7c:	5040001a */ 	beqzl	$v0,.L0f112ce8
/*  f112c80:	00001025 */ 	or	$v0,$zero,$zero
/*  f112c84:	10000018 */ 	beqz	$zero,.L0f112ce8
/*  f112c88:	8c420008 */ 	lw	$v0,0x8($v0)
/*  f112c8c:	24010001 */ 	addiu	$at,$zero,0x1
.L0f112c90:
/*  f112c90:	54810015 */ 	bnel	$a0,$at,.L0f112ce8
/*  f112c94:	00001025 */ 	or	$v0,$zero,$zero
/*  f112c98:	10000013 */ 	beqz	$zero,.L0f112ce8
/*  f112c9c:	84620004 */ 	lh	$v0,0x4($v1)
.L0f112ca0:
/*  f112ca0:	3c0e800a */ 	lui	$t6,0x800a
/*  f112ca4:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f112ca8:	8dcf1870 */ 	lw	$t7,0x1870($t6)
/*  f112cac:	51e0000e */ 	beqzl	$t7,.L0f112ce8
/*  f112cb0:	00001025 */ 	or	$v0,$zero,$zero
/*  f112cb4:	0fc446fa */ 	jal	currentStageForbidsSlayer
/*  f112cb8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f112cbc:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f112cc0:	2418002c */ 	addiu	$t8,$zero,0x2c
/*  f112cc4:	0302c823 */ 	subu	$t9,$t8,$v0
/*  f112cc8:	0099082a */ 	slt	$at,$a0,$t9
/*  f112ccc:	50200006 */ 	beqzl	$at,.L0f112ce8
/*  f112cd0:	00001025 */ 	or	$v0,$zero,$zero
/*  f112cd4:	0fc446e2 */ 	jal	func0f111b88
/*  f112cd8:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f112cdc:	10000003 */ 	beqz	$zero,.L0f112cec
/*  f112ce0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f112ce4:	00001025 */ 	or	$v0,$zero,$zero
.L0f112ce8:
/*  f112ce8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f112cec:
/*  f112cec:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f112cf0:	03e00008 */ 	jr	$ra
/*  f112cf4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f112cf8
/*  f112cf8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f112cfc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f112d00:	0fc44a96 */ 	jal	func0f112a58
/*  f112d04:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f112d08:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f112d0c:	00401825 */ 	or	$v1,$v0,$zero
/*  f112d10:	10400020 */ 	beqz	$v0,.L0f112d94
/*  f112d14:	00002825 */ 	or	$a1,$zero,$zero
/*  f112d18:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f112d1c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f112d20:	54810010 */ 	bnel	$a0,$at,.L0f112d64
/*  f112d24:	24010001 */ 	addiu	$at,$zero,0x1
/*  f112d28:	8c420004 */ 	lw	$v0,0x4($v0)
/*  f112d2c:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f112d30:	0fc44af0 */ 	jal	objGetTextOverride
/*  f112d34:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f112d38:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f112d3c:	10400029 */ 	beqz	$v0,.L0f112de4
/*  f112d40:	00401825 */ 	or	$v1,$v0,$zero
/*  f112d44:	8c4e0014 */ 	lw	$t6,0x14($v0)
/*  f112d48:	11c00003 */ 	beqz	$t6,.L0f112d58
/*  f112d4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112d50:	10000026 */ 	beqz	$zero,.L0f112dec
/*  f112d54:	94620016 */ 	lhu	$v0,0x16($v1)
.L0f112d58:
/*  f112d58:	10000022 */ 	beqz	$zero,.L0f112de4
/*  f112d5c:	8c450008 */ 	lw	$a1,0x8($v0)
/*  f112d60:	24010001 */ 	addiu	$at,$zero,0x1
.L0f112d64:
/*  f112d64:	1481001f */ 	bne	$a0,$at,.L0f112de4
/*  f112d68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112d6c:	84640004 */ 	lh	$a0,0x4($v1)
/*  f112d70:	0fc44aff */ 	jal	func0f112bfc
/*  f112d74:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f112d78:	1040001a */ 	beqz	$v0,.L0f112de4
/*  f112d7c:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f112d80:	8c4f0014 */ 	lw	$t7,0x14($v0)
/*  f112d84:	11e00017 */ 	beqz	$t7,.L0f112de4
/*  f112d88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112d8c:	10000017 */ 	beqz	$zero,.L0f112dec
/*  f112d90:	94420016 */ 	lhu	$v0,0x16($v0)
.L0f112d94:
/*  f112d94:	3c18800a */ 	lui	$t8,0x800a
/*  f112d98:	8f18a244 */ 	lw	$t8,-0x5dbc($t8)
/*  f112d9c:	8f191870 */ 	lw	$t9,0x1870($t8)
/*  f112da0:	13200010 */ 	beqz	$t9,.L0f112de4
/*  f112da4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112da8:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f112dac:	0fc446fa */ 	jal	currentStageForbidsSlayer
/*  f112db0:	afa50018 */ 	sw	$a1,0x18($sp)
/*  f112db4:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f112db8:	2408002c */ 	addiu	$t0,$zero,0x2c
/*  f112dbc:	01024823 */ 	subu	$t1,$t0,$v0
/*  f112dc0:	0089082a */ 	slt	$at,$a0,$t1
/*  f112dc4:	10200007 */ 	beqz	$at,.L0f112de4
/*  f112dc8:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f112dcc:	0fc446e2 */ 	jal	func0f111b88
/*  f112dd0:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f112dd4:	0fc28869 */ 	jal	func0f0a21a4
/*  f112dd8:	00402025 */ 	or	$a0,$v0,$zero
/*  f112ddc:	10000004 */ 	beqz	$zero,.L0f112df0
/*  f112de0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f112de4:
/*  f112de4:	0fc28869 */ 	jal	func0f0a21a4
/*  f112de8:	00a02025 */ 	or	$a0,$a1,$zero
.L0f112dec:
/*  f112dec:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f112df0:
/*  f112df0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f112df4:	03e00008 */ 	jr	$ra
/*  f112df8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f112dfc
/*  f112dfc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f112e00:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f112e04:	0fc44b3e */ 	jal	func0f112cf8
/*  f112e08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112e0c:	0fc5b9f1 */ 	jal	langGet
/*  f112e10:	00402025 */ 	or	$a0,$v0,$zero
/*  f112e14:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f112e18:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f112e1c:	03e00008 */ 	jr	$ra
/*  f112e20:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f112e24
/*  f112e24:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f112e28:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f112e2c:	0fc44a96 */ 	jal	func0f112a58
/*  f112e30:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f112e34:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f112e38:	00401825 */ 	or	$v1,$v0,$zero
/*  f112e3c:	10400024 */ 	beqz	$v0,.L0f112ed0
/*  f112e40:	00002825 */ 	or	$a1,$zero,$zero
/*  f112e44:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f112e48:	24010002 */ 	addiu	$at,$zero,0x2
/*  f112e4c:	54810012 */ 	bnel	$a0,$at,.L0f112e98
/*  f112e50:	24010001 */ 	addiu	$at,$zero,0x1
/*  f112e54:	8c420004 */ 	lw	$v0,0x4($v0)
/*  f112e58:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f112e5c:	0fc44af0 */ 	jal	objGetTextOverride
/*  f112e60:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f112e64:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f112e68:	1040002d */ 	beqz	$v0,.L0f112f20
/*  f112e6c:	00401825 */ 	or	$v1,$v0,$zero
/*  f112e70:	8c4e0014 */ 	lw	$t6,0x14($v0)
/*  f112e74:	11c00005 */ 	beqz	$t6,.L0f112e8c
/*  f112e78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112e7c:	0fc5b9f1 */ 	jal	langGet
/*  f112e80:	8c640014 */ 	lw	$a0,0x14($v1)
/*  f112e84:	10000029 */ 	beqz	$zero,.L0f112f2c
/*  f112e88:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f112e8c:
/*  f112e8c:	10000024 */ 	beqz	$zero,.L0f112f20
/*  f112e90:	8c450008 */ 	lw	$a1,0x8($v0)
/*  f112e94:	24010001 */ 	addiu	$at,$zero,0x1
.L0f112e98:
/*  f112e98:	14810021 */ 	bne	$a0,$at,.L0f112f20
/*  f112e9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112ea0:	84640004 */ 	lh	$a0,0x4($v1)
/*  f112ea4:	0fc44aff */ 	jal	func0f112bfc
/*  f112ea8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f112eac:	1040001c */ 	beqz	$v0,.L0f112f20
/*  f112eb0:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f112eb4:	8c4f0014 */ 	lw	$t7,0x14($v0)
/*  f112eb8:	11e00019 */ 	beqz	$t7,.L0f112f20
/*  f112ebc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112ec0:	0fc5b9f1 */ 	jal	langGet
/*  f112ec4:	8c440014 */ 	lw	$a0,0x14($v0)
/*  f112ec8:	10000018 */ 	beqz	$zero,.L0f112f2c
/*  f112ecc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f112ed0:
/*  f112ed0:	3c18800a */ 	lui	$t8,0x800a
/*  f112ed4:	8f18a244 */ 	lw	$t8,-0x5dbc($t8)
/*  f112ed8:	8f191870 */ 	lw	$t9,0x1870($t8)
/*  f112edc:	13200010 */ 	beqz	$t9,.L0f112f20
/*  f112ee0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112ee4:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f112ee8:	0fc446fa */ 	jal	currentStageForbidsSlayer
/*  f112eec:	afa50018 */ 	sw	$a1,0x18($sp)
/*  f112ef0:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f112ef4:	2408002c */ 	addiu	$t0,$zero,0x2c
/*  f112ef8:	01024823 */ 	subu	$t1,$t0,$v0
/*  f112efc:	0089082a */ 	slt	$at,$a0,$t1
/*  f112f00:	10200007 */ 	beqz	$at,.L0f112f20
/*  f112f04:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f112f08:	0fc446e2 */ 	jal	func0f111b88
/*  f112f0c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f112f10:	0fc28874 */ 	jal	func0f0a21d0
/*  f112f14:	00402025 */ 	or	$a0,$v0,$zero
/*  f112f18:	10000004 */ 	beqz	$zero,.L0f112f2c
/*  f112f1c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f112f20:
/*  f112f20:	0fc28874 */ 	jal	func0f0a21d0
/*  f112f24:	00a02025 */ 	or	$a0,$a1,$zero
/*  f112f28:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f112f2c:
/*  f112f2c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f112f30:	03e00008 */ 	jr	$ra
/*  f112f34:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f112f38
/*  f112f38:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f112f3c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f112f40:	8c4e02b8 */ 	lw	$t6,0x2b8($v0)
/*  f112f44:	ac8e0020 */ 	sw	$t6,0x20($a0)
/*  f112f48:	03e00008 */ 	jr	$ra
/*  f112f4c:	ac4402b8 */ 	sw	$a0,0x2b8($v0)
);

GLOBAL_ASM(
glabel func0f112f50
/*  f112f50:	3c0e800a */ 	lui	$t6,0x800a
/*  f112f54:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f112f58:	03e00008 */ 	jr	$ra
/*  f112f5c:	8dc21874 */ 	lw	$v0,0x1874($t6)
);

GLOBAL_ASM(
glabel func0f112f60
/*  f112f60:	3c0e800a */ 	lui	$t6,0x800a
/*  f112f64:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f112f68:	03e00008 */ 	jr	$ra
/*  f112f6c:	adc41874 */ 	sw	$a0,0x1874($t6)
);

GLOBAL_ASM(
glabel func0f112f70
/*  f112f70:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f112f74:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f112f78:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f112f7c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f112f80:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f112f84:	00002025 */ 	or	$a0,$zero,$zero
/*  f112f88:	3c0e800a */ 	lui	$t6,0x800a
/*  f112f8c:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f112f90:	00408825 */ 	or	$s1,$v0,$zero
/*  f112f94:	00008025 */ 	or	$s0,$zero,$zero
/*  f112f98:	0fc44a54 */ 	jal	func0f112950
/*  f112f9c:	adc01874 */ 	sw	$zero,0x1874($t6)
/*  f112fa0:	5840000e */ 	blezl	$v0,.L0f112fdc
/*  f112fa4:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f112fa8:
/*  f112fa8:	0fc44b11 */ 	jal	func0f112c44
/*  f112fac:	02002025 */ 	or	$a0,$s0,$zero
/*  f112fb0:	14510004 */ 	bne	$v0,$s1,.L0f112fc4
/*  f112fb4:	3c0f800a */ 	lui	$t7,0x800a
/*  f112fb8:	8defa244 */ 	lw	$t7,-0x5dbc($t7)
/*  f112fbc:	10000006 */ 	beqz	$zero,.L0f112fd8
/*  f112fc0:	adf01874 */ 	sw	$s0,0x1874($t7)
.L0f112fc4:
/*  f112fc4:	0fc44a54 */ 	jal	func0f112950
/*  f112fc8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f112fcc:	0202082a */ 	slt	$at,$s0,$v0
/*  f112fd0:	1420fff5 */ 	bnez	$at,.L0f112fa8
/*  f112fd4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f112fd8:
/*  f112fd8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f112fdc:
/*  f112fdc:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f112fe0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f112fe4:	03e00008 */ 	jr	$ra
/*  f112fe8:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f112fec
/*  f112fec:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f112ff0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f112ff4:	0fc44af0 */ 	jal	objGetTextOverride
/*  f112ff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f112ffc:	50400009 */ 	beqzl	$v0,.L0f113024
/*  f113000:	00001025 */ 	or	$v0,$zero,$zero
/*  f113004:	8c4e001c */ 	lw	$t6,0x1c($v0)
/*  f113008:	51c00006 */ 	beqzl	$t6,.L0f113024
/*  f11300c:	00001025 */ 	or	$v0,$zero,$zero
/*  f113010:	0fc5b9f1 */ 	jal	langGet
/*  f113014:	8c44001c */ 	lw	$a0,0x1c($v0)
/*  f113018:	10000003 */ 	beqz	$zero,.L0f113028
/*  f11301c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f113020:	00001025 */ 	or	$v0,$zero,$zero
.L0f113024:
/*  f113024:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f113028:
/*  f113028:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f11302c:	03e00008 */ 	jr	$ra
/*  f113030:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f113034
/*  f113034:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f113038:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11303c:	0fc44aff */ 	jal	func0f112bfc
/*  f113040:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113044:	50400009 */ 	beqzl	$v0,.L0f11306c
/*  f113048:	00001025 */ 	or	$v0,$zero,$zero
/*  f11304c:	8c4e001c */ 	lw	$t6,0x1c($v0)
/*  f113050:	51c00006 */ 	beqzl	$t6,.L0f11306c
/*  f113054:	00001025 */ 	or	$v0,$zero,$zero
/*  f113058:	0fc5b9f1 */ 	jal	langGet
/*  f11305c:	8c44001c */ 	lw	$a0,0x1c($v0)
/*  f113060:	10000003 */ 	beqz	$zero,.L0f113070
/*  f113064:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f113068:	00001025 */ 	or	$v0,$zero,$zero
.L0f11306c:
/*  f11306c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f113070:
/*  f113070:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f113074:	03e00008 */ 	jr	$ra
/*  f113078:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11307c
/*  f11307c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f113080:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f113084:	00a08025 */ 	or	$s0,$a1,$zero
/*  f113088:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f11308c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f113090:	00808825 */ 	or	$s1,$a0,$zero
/*  f113094:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f113098:	24050200 */ 	addiu	$a1,$zero,0x200
/*  f11309c:	1040003e */ 	beqz	$v0,.L0f113198
/*  f1130a0:	3c067fff */ 	lui	$a2,0x7fff
/*  f1130a4:	34c6ffff */ 	ori	$a2,$a2,0xffff
/*  f1130a8:	afa60024 */ 	sw	$a2,0x24($sp)
/*  f1130ac:	02002025 */ 	or	$a0,$s0,$zero
/*  f1130b0:	24050200 */ 	addiu	$a1,$zero,0x200
/*  f1130b4:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f1130b8:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f1130bc:	8fa60024 */ 	lw	$a2,0x24($sp)
/*  f1130c0:	14400002 */ 	bnez	$v0,.L0f1130cc
/*  f1130c4:	8fa70020 */ 	lw	$a3,0x20($sp)
/*  f1130c8:	00008025 */ 	or	$s0,$zero,$zero
.L0f1130cc:
/*  f1130cc:	3c02800a */ 	lui	$v0,%hi(var800a000c)
/*  f1130d0:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f1130d4:	00002025 */ 	or	$a0,$zero,$zero
.L0f1130d8:
/*  f1130d8:	8c431880 */ 	lw	$v1,0x1880($v0)
/*  f1130dc:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f1130e0:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f1130e4:	04620014 */ 	bltzl	$v1,.L0f113138
/*  f1130e8:	00803825 */ 	or	$a3,$a0,$zero
/*  f1130ec:	8c4e1878 */ 	lw	$t6,0x1878($v0)
/*  f1130f0:	562e000b */ 	bnel	$s1,$t6,.L0f113120
/*  f1130f4:	0066082a */ 	slt	$at,$v1,$a2
/*  f1130f8:	8c4f187c */ 	lw	$t7,0x187c($v0)
/*  f1130fc:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f113100:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f113104:	560f0006 */ 	bnel	$s0,$t7,.L0f113120
/*  f113108:	0066082a */ 	slt	$at,$v1,$a2
/*  f11310c:	8cb80038 */ 	lw	$t8,0x38($a1)
/*  f113110:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f113114:	10000010 */ 	beqz	$zero,.L0f113158
/*  f113118:	ac591880 */ 	sw	$t9,0x1880($v0)
/*  f11311c:	0066082a */ 	slt	$at,$v1,$a2
.L0f113120:
/*  f113120:	50200008 */ 	beqzl	$at,.L0f113144
/*  f113124:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f113128:	00603025 */ 	or	$a2,$v1,$zero
/*  f11312c:	10000004 */ 	beqz	$zero,.L0f113140
/*  f113130:	00803825 */ 	or	$a3,$a0,$zero
/*  f113134:	00803825 */ 	or	$a3,$a0,$zero
.L0f113138:
/*  f113138:	10000007 */ 	beqz	$zero,.L0f113158
/*  f11313c:	2404000a */ 	addiu	$a0,$zero,0xa
.L0f113140:
/*  f113140:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f113144:
/*  f113144:	2881000a */ 	slti	$at,$a0,0xa
/*  f113148:	1420ffe3 */ 	bnez	$at,.L0f1130d8
/*  f11314c:	2442000c */ 	addiu	$v0,$v0,%lo(var800a000c)
/*  f113150:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f113154:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
.L0f113158:
/*  f113158:	2401000a */ 	addiu	$at,$zero,0xa
/*  f11315c:	5481000f */ 	bnel	$a0,$at,.L0f11319c
/*  f113160:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f113164:	8ca90284 */ 	lw	$t1,0x284($a1)
/*  f113168:	00071080 */ 	sll	$v0,$a3,0x2
/*  f11316c:	8ca80038 */ 	lw	$t0,0x38($a1)
/*  f113170:	00471023 */ 	subu	$v0,$v0,$a3
/*  f113174:	00021080 */ 	sll	$v0,$v0,0x2
/*  f113178:	01225021 */ 	addu	$t2,$t1,$v0
/*  f11317c:	ad481880 */ 	sw	$t0,0x1880($t2)
/*  f113180:	8cab0284 */ 	lw	$t3,0x284($a1)
/*  f113184:	01626021 */ 	addu	$t4,$t3,$v0
/*  f113188:	ad911878 */ 	sw	$s1,0x1878($t4)
/*  f11318c:	8cad0284 */ 	lw	$t5,0x284($a1)
/*  f113190:	01a27021 */ 	addu	$t6,$t5,$v0
/*  f113194:	add0187c */ 	sw	$s0,0x187c($t6)
.L0f113198:
/*  f113198:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f11319c:
/*  f11319c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1131a0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1131a4:	03e00008 */ 	jr	$ra
/*  f1131a8:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f1131ac
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
