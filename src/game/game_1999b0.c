#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/debug.h"
#include "game/chr/chr.h"
#include "game/game_092610.h"
#include "game/game_097ba0.h"
#include "game/game_0b0420.h"
#include "game/game_127910.h"
#include "game/game_1999b0.h"
#include "game/pad.h"
#include "game/padhalllv.h"
#include "game/propobj.h"
#include "gvars/gvars.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "types.h"

s32 weaponGetAmmoTypeByFunction(s32 weaponnum, u32 funcnum)
{
	if (weaponnum >= WEAPON_FALCON2 && weaponnum <= WEAPON_SUICIDEPILL) {
		struct inventory_ammo *ammo = weaponGetAmmoByFunction(weaponnum, funcnum);

		if (ammo) {
			return ammo->type;
		}
	}

	return 0;
}

s32 weaponGetClipSizeByFunction(s32 weaponnum, u32 funcnum)
{
	if (weaponnum >= WEAPON_FALCON2 && weaponnum <= WEAPON_SUICIDEPILL) {
		struct inventory_ammo *ammo = weaponGetAmmoByFunction(weaponnum, funcnum);

		if (ammo) {
			return ammo->clipsize;
		}
	}

	return 0;
}

void func0f199a40(struct chrdata *chr, u32 index, bool arg2)
{
	struct aibot *aibot = chr->aibot;
	aibot->unk02c[index] = 0;
	aibot->unk0e4[index] = 0;

	if (chr->weapons_held[index]
			&& func0f19a29c(aibot->weaponnum, aibot->gunfunc) == 0) {
		s32 clipsize = weaponGetClipSizeByFunction(aibot->weaponnum, aibot->gunfunc);

		if (clipsize > 0) {
			s32 a = clipsize - aibot->unk024[index];
			s32 b = func0f199d70(aibot, aibot->weaponnum, aibot->gunfunc, a);

			if (b > 0) {
				aibot->unk024[index] += b;

				if (arg2) {
					if (aibot->weaponnum == WEAPON_FARSIGHTXR20) {
						// FarSight reload sound
						func0f0939f8(NULL, chr->prop, 0x433, -1,
								-1, 1024, 0, 0, 0, -1, 0, -1, -1, -1, -1);
					} else {
						// Normal reload sound
						func0f0939f8(NULL, chr->prop, 0x804f, -1,
								-1, 1024, 0, 0, 0, -1, 0, -1, -1, -1, -1);
					}
				}
			}
		}
	}
}

s32 func0f199be4(struct aibot *aibot, s32 weaponnum, s32 funcnum, bool include_equipped)
{
	s32 qty = 0;
	s32 ammotype;
	s32 equippedammotype;

	if (aibot) {
		if (aibot->unk064 & 1) {
			ammotype = weaponGetAmmoTypeByFunction(weaponnum, funcnum);
			qty = ammotypeGetMaxCapacity(ammotype);
		} else {
			ammotype = weaponGetAmmoTypeByFunction(weaponnum, funcnum);
			qty = aibot->ammoheld[ammotype];
		}

		if (include_equipped) {
			ammotype = weaponGetAmmoTypeByFunction(weaponnum, funcnum);
			equippedammotype = weaponGetAmmoTypeByFunction(aibot->weaponnum, aibot->gunfunc);

			if (equippedammotype == ammotype) {
				qty += aibot->unk024[1] + aibot->unk024[0];
			}
		}
	}

	return qty;
}

s32 aibotGetAmmoQty(struct aibot *aibot, s32 ammotype, bool include_equipped)
{
	s32 qty = 0;

	if (aibot) {
		if (aibot->unk064 & 1) {
			qty = ammotypeGetMaxCapacity(ammotype);
		} else {
			qty = aibot->ammoheld[ammotype];
		}

		if (include_equipped
				&& weaponGetAmmoTypeByFunction(aibot->weaponnum, aibot->gunfunc) == ammotype) {
			qty += aibot->unk024[1] + aibot->unk024[0];
		}
	}

	return qty;
}

s32 func0f199d70(struct aibot *aibot, s32 weaponnum, s32 funcnum, s32 qty)
{
	s32 result;
	s32 *ammoheld = &aibot->ammoheld[weaponGetAmmoTypeByFunction(weaponnum, funcnum)];

	if (!aibot || *ammoheld <= 0 || qty <= 0) {
		return 0;
	}

	if (aibot->unk064 & 1) {
		return qty;
	}

	dprint();
	*ammoheld -= qty;

	if (*ammoheld < 0) {
		result = qty + *ammoheld;
		*ammoheld = 0;

		if (dprint()) {
			return result;
		}
	} else {
		result = qty;
		dprint();
	}

	return result;
}

GLOBAL_ASM(
glabel aibotGiveAmmoByWeapon
/*  f199e3c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f199e40:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f199e44:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f199e48:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f199e4c:	00a02025 */ 	or	$a0,$a1,$zero
/*  f199e50:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f199e54:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f199e58:	0fc6666c */ 	jal	weaponGetAmmoTypeByFunction
/*  f199e5c:	00c02825 */ 	or	$a1,$a2,$zero
/*  f199e60:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f199e64:	00027080 */ 	sll	$t6,$v0,0x2
/*  f199e68:	8c8f001c */ 	lw	$t7,0x1c($a0)
/*  f199e6c:	1080001d */ 	beqz	$a0,.L0f199ee4
/*  f199e70:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f199e74:	94980064 */ 	lhu	$t8,0x64($a0)
/*  f199e78:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*  f199e7c:	33190001 */ 	andi	$t9,$t8,0x1
/*  f199e80:	57200019 */ 	bnezl	$t9,.L0f199ee8
/*  f199e84:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f199e88:	59000017 */ 	blezl	$t0,.L0f199ee8
/*  f199e8c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f199e90:	0fc47bba */ 	jal	dprint
/*  f199e94:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f199e98:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f199e9c:	8faa002c */ 	lw	$t2,0x2c($sp)
/*  f199ea0:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f199ea4:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f199ea8:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f199eac:	8fa50028 */ 	lw	$a1,0x28($sp)
/*  f199eb0:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f199eb4:	0fc6666c */ 	jal	weaponGetAmmoTypeByFunction
/*  f199eb8:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f199ebc:	0fc2a63d */ 	jal	ammotypeGetMaxCapacity
/*  f199ec0:	00402025 */ 	or	$a0,$v0,$zero
/*  f199ec4:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f199ec8:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f199ecc:	004c082a */ 	slt	$at,$v0,$t4
/*  f199ed0:	10200002 */ 	beqz	$at,.L0f199edc
/*  f199ed4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f199ed8:	ac620000 */ 	sw	$v0,0x0($v1)
.L0f199edc:
/*  f199edc:	0fc47bba */ 	jal	dprint
/*  f199ee0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f199ee4:
/*  f199ee4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f199ee8:
/*  f199ee8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f199eec:	03e00008 */ 	jr	$ra
/*  f199ef0:	00000000 */ 	sll	$zero,$zero,0x0
);

// Mismatches because the target saves the heldquantity pointer to the stack
// before calling to ammotypeGetMaxCapacity, despite it already being saved.
//void aibotGiveAmmoByWeapon(struct aibot *aibot, s32 weaponnum, s32 funcnum, s32 qty)
//{
//	s32 max;
//	s32 *heldquantity = &aibot->ammotypes->quantities[weaponGetAmmoTypeByFunction(weaponnum, funcnum)];
//
//	if (aibot && (aibot->unk064 & 1) == 0 && qty > 0) {
//		dprint();
//		*heldquantity += qty;
//		max = ammotypeGetMaxCapacity(weaponGetAmmoTypeByFunction(weaponnum, funcnum));
//
//		if (*heldquantity > max) {
//			*heldquantity = max;
//		}
//
//		dprint();
//	}
//}

GLOBAL_ASM(
glabel aibotGiveAmmoByType
/*  f199ef4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f199ef8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f199efc:	8c8e001c */ 	lw	$t6,0x1c($a0)
/*  f199f00:	00057880 */ 	sll	$t7,$a1,0x2
/*  f199f04:	1080001b */ 	beqz	$a0,.L0f199f74
/*  f199f08:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f199f0c:	94980064 */ 	lhu	$t8,0x64($a0)
/*  f199f10:	33190001 */ 	andi	$t9,$t8,0x1
/*  f199f14:	57200018 */ 	bnezl	$t9,.L0f199f78
/*  f199f18:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f199f1c:	58c00016 */ 	blezl	$a2,.L0f199f78
/*  f199f20:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f199f24:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f199f28:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f199f2c:	0fc47bba */ 	jal	dprint
/*  f199f30:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f199f34:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f199f38:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f199f3c:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f199f40:	8c680000 */ 	lw	$t0,0x0($v1)
/*  f199f44:	01064821 */ 	addu	$t1,$t0,$a2
/*  f199f48:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f199f4c:	0fc2a63d */ 	jal	ammotypeGetMaxCapacity
/*  f199f50:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f199f54:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f199f58:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f199f5c:	004a082a */ 	slt	$at,$v0,$t2
/*  f199f60:	10200002 */ 	beqz	$at,.L0f199f6c
/*  f199f64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f199f68:	ac620000 */ 	sw	$v0,0x0($v1)
.L0f199f6c:
/*  f199f6c:	0fc47bba */ 	jal	dprint
/*  f199f70:	00000000 */ 	sll	$zero,$zero,0x0
.L0f199f74:
/*  f199f74:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f199f78:
/*  f199f78:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f199f7c:	03e00008 */ 	jr	$ra
/*  f199f80:	00000000 */ 	sll	$zero,$zero,0x0
);

// Mismatches because the target saves the heldquantity pointer to the stack
// before calling to ammotypeGetMaxCapacity, despite it already being saved.
//void aibotGiveAmmoByType(struct aibot *aibot, u32 ammotype, s32 quantity)
//{
//	s32 max;
//	s32 *heldquantity = &aibot->ammotypes->quantities[ammotype];
//
//	if (!aibot || (aibot->unk064 & 1) || quantity <= 0) {
//		return;
//	}
//
//	dprint();
//
//	*heldquantity += quantity;
//	max = ammotypeGetMaxCapacity(ammotype);
//
//	if (*heldquantity > max) {
//		*heldquantity = max;
//	}
//
//	dprint();
//}

/**
 * This function appears to handle aibots shooting chrs with the Farsight, but
 * is called conditionally and I haven't determined what those conditions are.
 */
bool aibotDoFarsightThing(struct chrdata *chr, u32 arg1, struct coord *arg2, struct coord *arg3)
{
	struct aibot *aibot;
	struct chrdata *oppchr;
	struct prop *oppprop;
	s32 i;
	s32 rand;
	f32 speed;

	if (!chr || !chr->aibot) {
		return false;
	}

	aibot = chr->aibot;

	if (aibot->weaponnum == WEAPON_FARSIGHTXR20) {
		rand = random() % 100;

		// 3 in 10 chance of this passing
		if (rand < 30) {
			s32 sp172 = 0;
			s32 sp168 = 0;
			s32 sp164 = -1;
			s32 sp160 = 200;
			u8 sp156[] = {WEAPON_FARSIGHTXR20, 0, 0, 0};
			f32 fVar14 = func0f0b1d28(sp156);
			s32 fallback = 30;
			s32 value = fallback;

			for (i = 0; i < g_MpNumPlayers; i++) {
				oppchr = g_MpPlayerChrs[i];
				oppprop = g_MpPlayerChrs[i]->prop;

				if (oppprop->type == PROPTYPE_PLAYER) {
					struct player *player = g_Vars.players[propGetPlayerNum(oppprop)];
					speed = player->speedforwards * player->speedforwards
							+ player->speedsideways * player->speedsideways;

					if (speed > 0) {
						value = fallback * 0.05f;
					}
				} else {
					if (oppchr->actiontype != ACT_STAND) {
						value = fallback * 0.05f;
					}
				}

				// value is 30 if player was still, or 1.5 if moving. So if 30
				// then this will always pass, or if 1.5 then this has 1 in 15
				// chance of passing.
				if (oppchr != chr
						&& value > rand
						&& func0f06b39c(arg3, arg2, &oppprop->pos, func0f0278a4(oppchr))) {
					func0f0a7d98(sp156, oppprop, -1);

					if (oppchr->animdata && chrGetShield(oppchr) > 0) {
						func0f03ff2c(oppchr, &oppprop->pos, arg2, &sp172, &sp160, &sp168, &sp164);
					}

					func0f025ea4(oppchr, oppprop, sp160, &oppprop->pos, arg2, chr);
					func0f0341dc(oppchr, fVar14, arg2, sp156, chr->prop, 200, oppprop, sp172, sp168, sp164, 0);
				}
			}

			return true;
		}

		return false;
	}

	return true;
}

s32 func0f19a27c(s32 weapon)
{
	return weaponGetModel(weapon);
}

bool func0f19a29c(u32 weaponnum, bool is_secondary)
{
	switch (weaponnum) {
	case WEAPON_LAPTOPGUN:
	case WEAPON_DRAGON:
	case WEAPON_COMBATKNIFE:
		return is_secondary;
	case WEAPON_GRENADE:
	case WEAPON_NBOMB:
	case WEAPON_TIMEDMINE:
	case WEAPON_PROXIMITYMINE:
	case WEAPON_REMOTEMINE:
		return true;
	}

	return false;
}

u32 aibotGetProjectileThrowInterval(u32 weapon)
{
	switch (weapon) {
	case WEAPON_COMBATKNIFE:
		return 120;
	case WEAPON_GRENADE:
	case WEAPON_NBOMB:
		return 90;
	case WEAPON_CROSSBOW:
	case WEAPON_TRANQUILIZER:
	case WEAPON_LASER:
	case WEAPON_TIMEDMINE:
	case WEAPON_PROXIMITYMINE:
	case WEAPON_REMOTEMINE:
	default:
		return 60;
	}
}

u32 ammotypeGetWeapon(u32 ammotype)
{
	switch (ammotype) {
	case AMMOTYPE_NBOMB:       return WEAPON_NBOMB;
	case AMMOTYPE_GRENADE:     return WEAPON_GRENADE;
	case AMMOTYPE_KNIFE:       return WEAPON_COMBATKNIFE;
	case AMMOTYPE_REMOTE_MINE: return WEAPON_REMOTEMINE;
	case AMMOTYPE_PROXY_MINE:  return WEAPON_PROXIMITYMINE;
	case AMMOTYPE_TIMED_MINE:  return WEAPON_TIMEDMINE;
	}

	return 0;
}

void func0f19a37c(struct chrdata *chr)
{
	struct coord sp228 = {0, 0, 0};
	f32 sp164[16];
	f32 sp152[3];
	struct prop *prop = chr->prop;
	f32 sp84[16];
	f32 sp80 = func0f03e5f0(chr);
	u32 stack;
	u8 sp72[] = {0, 0, 0, 0};
	struct prop *target = chrGetTargetProp(chr);
	struct coord sp56;
	f32 mult;

	sp72[0] = chr->aibot->weaponnum;
	sp72[3] = chr->aibot->gunfunc;

	if (func0f049068(chr, WEAPON_GRENADE, 0)) {
		sp56.x = target->pos.x;
		sp56.z = target->pos.z;

		if (chr->aibot->weaponnum == WEAPON_GRENADE || chr->aibot->weaponnum == WEAPON_NBOMB) {
			sp56.y = target->chr->manground;
		} else {
			sp56.y = target->pos.y;

			if (target->type == PROPTYPE_PLAYER) {
				sp56.y -= 25.0f;
			}
		}

		func0f04031c(&prop->pos, 16.666666f, &sp56, sp152);
	} else {
		// These numbers are about 2 billionths away from DEG2RAD(20),
		// but tweaking the multiplier in DEG2RAD doesn't make this match
		// without creating mismatches in other places :(
		sp152[0] = cosf(0.34901028871536f) * sinf(sp80);
		sp152[1] = sinf(0.34901028871536f);
		sp152[2] = cosf(0.34901028871536f) * cosf(sp80);
	}

	mult = 16.666666f;

	sp228.x = sp152[0] * mult;
	sp228.y = sp152[1] * mult;
	sp228.z = sp152[2] * mult;

	func000159b0(sp164);

	if (chr->aibot->weaponnum == WEAPON_COMBATKNIFE) {
		func00016400(M_BADPI * 1.5f, sp164);
		func000162e8(M_BADPI, sp84);
		func000159fc(sp84, sp164);
	}

	func000162e8(0.34901028871536f, sp84);
	func00015be0(sp84, sp164);
	func00016374(sp80, sp84);
	func00015be0(sp84, sp164);

	func0f09ee18(chr, sp72, &prop->pos, prop->rooms, sp164, &sp228);

	if (sp72[0] == WEAPON_REMOTEMINE) {
		chr->aibot->unk064 |= 0x1000;
	}
}

s32 func0f19a60c(s32 weaponnum, s32 funcnum)
{
	s32 stack[2];
	s32 iVar4 = 1;
	struct weapon *weapon = weaponFindById(weaponnum);

	if (weapon) {
		struct weaponfunc *func = weapon->functions[funcnum];

		if (func) {
			if (func->type == INVENTORYFUNCTYPE_SHOOT_SINGLE) {
				struct weaponfunc_shootsingle *func2 = (struct weaponfunc_shootsingle *)func;
				iVar4 = func2->unk24 + func2->unk25;
			} else if (func->type == INVENTORYFUNCTYPE_SHOOT_AUTOMATIC) {
				struct weaponfunc_shootauto *func2 = (struct weaponfunc_shootauto *)func;
				iVar4 = func2->unk24 + func2->unk25;
			} else if (func->type == INVENTORYFUNCTYPE_SHOOT_PROJECTILE) {
				struct weaponfunc_shootprojectile *func2 = (struct weaponfunc_shootprojectile *)func;
				iVar4 = func2->unk24 + func2->unk25;
			} else if (func->type == INVENTORYFUNCTYPE_CLOSE && weaponnum != WEAPON_REAPER) {
				iVar4 = 60;
			}
		}
	}

	return iVar4;
}

bool func0f19a6d0(struct chrdata *chr, struct coord *frompos, struct coord *topos, s16 *fromrooms, s16 *torooms, struct obj48 *obj48)
{
	s32 *fromwaypoint = waypointFindClosestToPos(frompos, fromrooms);
	s32 *towaypoint = waypointFindClosestToPos(topos, torooms);
	s32 *waypoints[6];
	s32 numwaypoints;

	if (fromwaypoint && towaypoint) {
		s32 hash = (g_Vars.lvframe60 >> 9) * 128 + chr->chrnum * 8;
		waypointSetHashThing(hash, hash);

		numwaypoints = waypointFindRoute(fromwaypoint, towaypoint, waypoints, 6);
		waypointSetHashThing(0, 0);

		if (numwaypoints > 1) {
			s32 i = 0;

			while (waypoints[i]) {
				obj48->waypoints[i] = *waypoints[i];
				i++;
			}

			obj48->unk105 = 0;
			obj48->unk104 = i;

			return true;
		}
	}

	return false;
}

void func0f19a7d0(u16 padnum, struct coord *pos)
{
	struct pad pad;
	s16 rooms[2];

	padUnpack(padnum, PADFIELD_ROOM | PADFIELD_POS, &pad);

	rooms[0] = pad.room;
	rooms[1] = -1;

	pos->x = pad.pos.x;
	pos->y = func0002a36c(&pad.pos, rooms, 0, 0) + 150;
	pos->z = pad.pos.z;
}

void aibotCreateSlayerRocket(struct chrdata *chr)
{
	struct weaponobj *rocket = func0f08b880(MODEL_CHRSKROCKETMIS, WEAPON_ROCKET2, chr);

	if (rocket) {
		f32 sp260[16];
		f32 sp196[16];
		f32 sp132[16];
		struct coord sp120 = {0, 0, 0};
		f32 a;
		f32 b;
		f32 sp100[3];

		a = func0f03e5f0(chr);
		b = func0f03e754(chr);

		sp100[0] = cosf(b) * sinf(a);
		sp100[1] = sinf(b);
		sp100[2] = cosf(b) * cosf(a); // @bug? Should one of these be sinf?

		func000162e8(b, sp196);
		func00016374(a, sp132);
		func00015be0(sp132, sp196);
		func000159b0(sp260);

		func0f09ebcc(&rocket->base, &chr->prop->pos, chr->prop->rooms, sp196, sp100, sp260, chr->prop, &chr->prop->pos);

		if (rocket->base.hidden & OBJHFLAG_00000080) {
			struct prop *target = chrGetTargetProp(chr);
			rocket->unk62 = -1;
			rocket->base.unk48->unk010 = 7.5;
			rocket->base.unk48->unk014 = b;
			rocket->base.unk48->unk018 = a;
			rocket->base.unk48->unk0f4 = 0;
			rocket->base.unk48->unk0b4 = 0x20000000;

			// Fire rocket sound
			func0f0939f8(NULL, rocket->base.prop, 0x8053, -1,
					-1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1);

			if (!func0f19a6d0(chr, &chr->prop->pos, &target->pos, chr->prop->rooms, target->rooms, rocket->base.unk48)) {
				rocket->unk62 = 0;
			} else {
				func0f19a7d0(rocket->base.unk48->waypoints[0], &rocket->base.unk48->pos);
				chr->aibot->unk044 = rocket->base.prop;
			}
		}
	}
}
