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

GLOBAL_ASM(
glabel func0f199f84
.late_rodata
glabel var7f1b90a0
.word 0x3d4ccccd
.text
/*  f199f84:	27bdff38 */ 	addiu	$sp,$sp,-200
/*  f199f88:	afb7006c */ 	sw	$s7,0x6c($sp)
/*  f199f8c:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f199f90:	00c09825 */ 	or	$s3,$a2,$zero
/*  f199f94:	0080b825 */ 	or	$s7,$a0,$zero
/*  f199f98:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f199f9c:	afbe0070 */ 	sw	$s8,0x70($sp)
/*  f199fa0:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f199fa4:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f199fa8:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f199fac:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f199fb0:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f199fb4:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f199fb8:	f7b80048 */ 	sdc1	$f24,0x48($sp)
/*  f199fbc:	f7b60040 */ 	sdc1	$f22,0x40($sp)
/*  f199fc0:	f7b40038 */ 	sdc1	$f20,0x38($sp)
/*  f199fc4:	afa500cc */ 	sw	$a1,0xcc($sp)
/*  f199fc8:	10800004 */ 	beqz	$a0,.L0f199fdc
/*  f199fcc:	afa700d4 */ 	sw	$a3,0xd4($sp)
/*  f199fd0:	8c8302d4 */ 	lw	$v1,0x2d4($a0)
/*  f199fd4:	54600004 */ 	bnezl	$v1,.L0f199fe8
/*  f199fd8:	8c6e0020 */ 	lw	$t6,0x20($v1)
.L0f199fdc:
/*  f199fdc:	10000098 */ 	beqz	$zero,.L0f19a240
/*  f199fe0:	00001025 */ 	or	$v0,$zero,$zero
/*  f199fe4:	8c6e0020 */ 	lw	$t6,0x20($v1)
.L0f199fe8:
/*  f199fe8:	24010016 */ 	addiu	$at,$zero,0x16
/*  f199fec:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f199ff0:	15c10093 */ 	bne	$t6,$at,.L0f19a240
/*  f199ff4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f199ff8:	0c004b70 */ 	jal	random
/*  f199ffc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a000:	24010064 */ 	addiu	$at,$zero,0x64
/*  f19a004:	0041001b */ 	divu	$zero,$v0,$at
/*  f19a008:	00001810 */ 	mfhi	$v1
/*  f19a00c:	2861001e */ 	slti	$at,$v1,0x1e
/*  f19a010:	10200089 */ 	beqz	$at,.L0f19a238
/*  f19a014:	afa300b4 */ 	sw	$v1,0xb4($sp)
/*  f19a018:	240fffff */ 	addiu	$t7,$zero,-1
/*  f19a01c:	241800c8 */ 	addiu	$t8,$zero,0xc8
/*  f19a020:	3c198009 */ 	lui	$t9,%hi(var80088490)
/*  f19a024:	afa000ac */ 	sw	$zero,0xac($sp)
/*  f19a028:	afa000a8 */ 	sw	$zero,0xa8($sp)
/*  f19a02c:	afaf00a4 */ 	sw	$t7,0xa4($sp)
/*  f19a030:	afb800a0 */ 	sw	$t8,0xa0($sp)
/*  f19a034:	27398490 */ 	addiu	$t9,$t9,%lo(var80088490)
/*  f19a038:	8f210000 */ 	lw	$at,0x0($t9)
/*  f19a03c:	27be009c */ 	addiu	$s8,$sp,0x9c
/*  f19a040:	03c02025 */ 	or	$a0,$s8,$zero
/*  f19a044:	0fc2c74a */ 	jal	func0f0b1d28
/*  f19a048:	afc10000 */ 	sw	$at,0x0($s8)
/*  f19a04c:	3c0b800b */ 	lui	$t3,%hi(g_MpNumPlayers)
/*  f19a050:	8d6bc530 */ 	lw	$t3,%lo(g_MpNumPlayers)($t3)
/*  f19a054:	46000606 */ 	mov.s	$f24,$f0
/*  f19a058:	2414001e */ 	addiu	$s4,$zero,0x1e
/*  f19a05c:	19600074 */ 	blez	$t3,.L0f19a230
/*  f19a060:	0000a825 */ 	or	$s5,$zero,$zero
/*  f19a064:	3c16800b */ 	lui	$s6,%hi(g_MpPlayerChrs)
/*  f19a068:	3c017f1c */ 	lui	$at,%hi(var7f1b90a0)
/*  f19a06c:	4480a000 */ 	mtc1	$zero,$f20
/*  f19a070:	c43690a0 */ 	lwc1	$f22,%lo(var7f1b90a0)($at)
/*  f19a074:	26d6c4d0 */ 	addiu	$s6,$s6,%lo(g_MpPlayerChrs)
/*  f19a078:	8ed00000 */ 	lw	$s0,0x0($s6)
.L0f19a07c:
/*  f19a07c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f19a080:	8e12001c */ 	lw	$s2,0x1c($s0)
/*  f19a084:	924c0000 */ 	lbu	$t4,0x0($s2)
/*  f19a088:	5581001b */ 	bnel	$t4,$at,.L0f19a0f8
/*  f19a08c:	82180007 */ 	lb	$t8,0x7($s0)
/*  f19a090:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f19a094:	02402025 */ 	or	$a0,$s2,$zero
/*  f19a098:	00026880 */ 	sll	$t5,$v0,0x2
/*  f19a09c:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x64)
/*  f19a0a0:	006d1821 */ 	addu	$v1,$v1,$t5
/*  f19a0a4:	8c63a024 */ 	lw	$v1,%lo(g_Vars+0x64)($v1)
/*  f19a0a8:	240e001e */ 	addiu	$t6,$zero,0x1e
/*  f19a0ac:	c4600170 */ 	lwc1	$f0,0x170($v1)
/*  f19a0b0:	c4620168 */ 	lwc1	$f2,0x168($v1)
/*  f19a0b4:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f19a0b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a0bc:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f19a0c0:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f19a0c4:	460ca03c */ 	c.lt.s	$f20,$f12
/*  f19a0c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a0cc:	45000015 */ 	bc1f	.L0f19a124
/*  f19a0d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a0d4:	448e4000 */ 	mtc1	$t6,$f8
/*  f19a0d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a0dc:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f19a0e0:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f19a0e4:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f19a0e8:	44149000 */ 	mfc1	$s4,$f18
/*  f19a0ec:	1000000d */ 	beqz	$zero,.L0f19a124
/*  f19a0f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a0f4:	82180007 */ 	lb	$t8,0x7($s0)
.L0f19a0f8:
/*  f19a0f8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f19a0fc:	2409001e */ 	addiu	$t1,$zero,0x1e
/*  f19a100:	13010008 */ 	beq	$t8,$at,.L0f19a124
/*  f19a104:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a108:	44892000 */ 	mtc1	$t1,$f4
/*  f19a10c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a110:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f19a114:	46163202 */ 	mul.s	$f8,$f6,$f22
/*  f19a118:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f19a11c:	44145000 */ 	mfc1	$s4,$f10
/*  f19a120:	00000000 */ 	sll	$zero,$zero,0x0
.L0f19a124:
/*  f19a124:	1217003b */ 	beq	$s0,$s7,.L0f19a214
/*  f19a128:	8fb900b4 */ 	lw	$t9,0xb4($sp)
/*  f19a12c:	0334082a */ 	slt	$at,$t9,$s4
/*  f19a130:	10200038 */ 	beqz	$at,.L0f19a214
/*  f19a134:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a138:	0fc09e29 */ 	jal	func0f0278a4
/*  f19a13c:	02002025 */ 	or	$a0,$s0,$zero
/*  f19a140:	26510008 */ 	addiu	$s1,$s2,0x8
/*  f19a144:	44070000 */ 	mfc1	$a3,$f0
/*  f19a148:	02203025 */ 	or	$a2,$s1,$zero
/*  f19a14c:	8fa400d4 */ 	lw	$a0,0xd4($sp)
/*  f19a150:	0fc1ace7 */ 	jal	func0f06b39c
/*  f19a154:	02602825 */ 	or	$a1,$s3,$zero
/*  f19a158:	1040002e */ 	beqz	$v0,.L0f19a214
/*  f19a15c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f19a160:	02402825 */ 	or	$a1,$s2,$zero
/*  f19a164:	0fc29f66 */ 	jal	func0f0a7d98
/*  f19a168:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f19a16c:	8e0a0020 */ 	lw	$t2,0x20($s0)
/*  f19a170:	51400011 */ 	beqzl	$t2,.L0f19a1b8
/*  f19a174:	02002025 */ 	or	$a0,$s0,$zero
/*  f19a178:	0fc0cfe8 */ 	jal	chrGetShield
/*  f19a17c:	02002025 */ 	or	$a0,$s0,$zero
/*  f19a180:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f19a184:	02002025 */ 	or	$a0,$s0,$zero
/*  f19a188:	02202825 */ 	or	$a1,$s1,$zero
/*  f19a18c:	02603025 */ 	or	$a2,$s3,$zero
/*  f19a190:	45000008 */ 	bc1f	.L0f19a1b4
/*  f19a194:	27a700ac */ 	addiu	$a3,$sp,0xac
/*  f19a198:	27ab00a0 */ 	addiu	$t3,$sp,0xa0
/*  f19a19c:	27ac00a8 */ 	addiu	$t4,$sp,0xa8
/*  f19a1a0:	27ad00a4 */ 	addiu	$t5,$sp,0xa4
/*  f19a1a4:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f19a1a8:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f19a1ac:	0fc0ffcb */ 	jal	func0f03ff2c
/*  f19a1b0:	afab0010 */ 	sw	$t3,0x10($sp)
.L0f19a1b4:
/*  f19a1b4:	02002025 */ 	or	$a0,$s0,$zero
.L0f19a1b8:
/*  f19a1b8:	02402825 */ 	or	$a1,$s2,$zero
/*  f19a1bc:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*  f19a1c0:	02203825 */ 	or	$a3,$s1,$zero
/*  f19a1c4:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f19a1c8:	0fc097a9 */ 	jal	func0f025ea4
/*  f19a1cc:	afb70014 */ 	sw	$s7,0x14($sp)
/*  f19a1d0:	8eee001c */ 	lw	$t6,0x1c($s7)
/*  f19a1d4:	8fb800ac */ 	lw	$t8,0xac($sp)
/*  f19a1d8:	8fa900a8 */ 	lw	$t1,0xa8($sp)
/*  f19a1dc:	8fa800a4 */ 	lw	$t0,0xa4($sp)
/*  f19a1e0:	4405c000 */ 	mfc1	$a1,$f24
/*  f19a1e4:	240f00c8 */ 	addiu	$t7,$zero,0xc8
/*  f19a1e8:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f19a1ec:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f19a1f0:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f19a1f4:	02002025 */ 	or	$a0,$s0,$zero
/*  f19a1f8:	02603025 */ 	or	$a2,$s3,$zero
/*  f19a1fc:	03c03825 */ 	or	$a3,$s8,$zero
/*  f19a200:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f19a204:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f19a208:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f19a20c:	0fc0d077 */ 	jal	func0f0341dc
/*  f19a210:	afa80024 */ 	sw	$t0,0x24($sp)
.L0f19a214:
/*  f19a214:	3c19800b */ 	lui	$t9,%hi(g_MpNumPlayers)
/*  f19a218:	8f39c530 */ 	lw	$t9,%lo(g_MpNumPlayers)($t9)
/*  f19a21c:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f19a220:	26d60004 */ 	addiu	$s6,$s6,0x4
/*  f19a224:	02b9082a */ 	slt	$at,$s5,$t9
/*  f19a228:	5420ff94 */ 	bnezl	$at,.L0f19a07c
/*  f19a22c:	8ed00000 */ 	lw	$s0,0x0($s6)
.L0f19a230:
/*  f19a230:	10000003 */ 	beqz	$zero,.L0f19a240
/*  f19a234:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f19a238:
/*  f19a238:	10000001 */ 	beqz	$zero,.L0f19a240
/*  f19a23c:	00001025 */ 	or	$v0,$zero,$zero
.L0f19a240:
/*  f19a240:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f19a244:	d7b40038 */ 	ldc1	$f20,0x38($sp)
/*  f19a248:	d7b60040 */ 	ldc1	$f22,0x40($sp)
/*  f19a24c:	d7b80048 */ 	ldc1	$f24,0x48($sp)
/*  f19a250:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f19a254:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f19a258:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f19a25c:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f19a260:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f19a264:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f19a268:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f19a26c:	8fb7006c */ 	lw	$s7,0x6c($sp)
/*  f19a270:	8fbe0070 */ 	lw	$s8,0x70($sp)
/*  f19a274:	03e00008 */ 	jr	$ra
/*  f19a278:	27bd00c8 */ 	addiu	$sp,$sp,0xc8
/*  f19a27c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f19a280:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f19a284:	0fc4a2bd */ 	jal	weaponGetModel
/*  f19a288:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a28c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f19a290:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f19a294:	03e00008 */ 	jr	$ra
/*  f19a298:	00000000 */ 	sll	$zero,$zero,0x0
);

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

u32 func0f19a2dc(u32 value)
{
	switch (value) {
	case 26:
		return 120;
	case 30:
	case 31:
		return 90;
	case 27:
	case 28:
	case 29:
	case 32:
	case 33:
	case 34:
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

u32 var800884a0 = 0x00000000;

GLOBAL_ASM(
glabel func0f19a37c
.late_rodata
glabel var7f1b914c
.word 0x41855555
glabel var7f1b9150
.word 0x3eb2b17a
glabel var7f1b9154
.word 0x3eb2b17a
glabel var7f1b9158
.word 0x3eb2b17a
glabel var7f1b915c
.word 0x41855555
glabel var7f1b9160
.word 0x4096c5bf
glabel var7f1b9164
.word 0x404907a9
glabel var7f1b9168
.word 0x3eb2b17a
.text
/*  f19a37c:	27bdff10 */ 	addiu	$sp,$sp,-240
/*  f19a380:	3c0f8009 */ 	lui	$t7,%hi(var80088494)
/*  f19a384:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f19a388:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f19a38c:	25ef8494 */ 	addiu	$t7,$t7,%lo(var80088494)
/*  f19a390:	8de10000 */ 	lw	$at,0x0($t7)
/*  f19a394:	27ae00e4 */ 	addiu	$t6,$sp,0xe4
/*  f19a398:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f19a39c:	adc10000 */ 	sw	$at,0x0($t6)
/*  f19a3a0:	8de10008 */ 	lw	$at,0x8($t7)
/*  f19a3a4:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f19a3a8:	00808025 */ 	or	$s0,$a0,$zero
/*  f19a3ac:	adc10008 */ 	sw	$at,0x8($t6)
/*  f19a3b0:	8c89001c */ 	lw	$t1,0x1c($a0)
/*  f19a3b4:	0fc0f97c */ 	jal	func0f03e5f0
/*  f19a3b8:	afa90094 */ 	sw	$t1,0x94($sp)
/*  f19a3bc:	3c0a8009 */ 	lui	$t2,%hi(var800884a0)
/*  f19a3c0:	8d4a84a0 */ 	lw	$t2,%lo(var800884a0)($t2)
/*  f19a3c4:	e7a00050 */ 	swc1	$f0,0x50($sp)
/*  f19a3c8:	02002025 */ 	or	$a0,$s0,$zero
/*  f19a3cc:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f19a3d0:	afaa0048 */ 	sw	$t2,0x48($sp)
/*  f19a3d4:	8e0b02d4 */ 	lw	$t3,0x2d4($s0)
/*  f19a3d8:	02002025 */ 	or	$a0,$s0,$zero
/*  f19a3dc:	2405001e */ 	addiu	$a1,$zero,0x1e
/*  f19a3e0:	8d6c0020 */ 	lw	$t4,0x20($t3)
/*  f19a3e4:	00003025 */ 	or	$a2,$zero,$zero
/*  f19a3e8:	a3ac0048 */ 	sb	$t4,0x48($sp)
/*  f19a3ec:	8e0d02d4 */ 	lw	$t5,0x2d4($s0)
/*  f19a3f0:	8db9004c */ 	lw	$t9,0x4c($t5)
/*  f19a3f4:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f19a3f8:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f19a3fc:	001877c2 */ 	srl	$t6,$t8,0x1f
/*  f19a400:	0fc1241a */ 	jal	func0f049068
/*  f19a404:	a3ae004b */ 	sb	$t6,0x4b($sp)
/*  f19a408:	10400026 */ 	beqz	$v0,.L0f19a4a4
/*  f19a40c:	8fa30044 */ 	lw	$v1,0x44($sp)
/*  f19a410:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f19a414:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f19a418:	3c054185 */ 	lui	$a1,0x4185
/*  f19a41c:	e7a40038 */ 	swc1	$f4,0x38($sp)
/*  f19a420:	c4660010 */ 	lwc1	$f6,0x10($v1)
/*  f19a424:	34a55555 */ 	ori	$a1,$a1,0x5555
/*  f19a428:	e7a60040 */ 	swc1	$f6,0x40($sp)
/*  f19a42c:	8e0f02d4 */ 	lw	$t7,0x2d4($s0)
/*  f19a430:	8de20020 */ 	lw	$v0,0x20($t7)
/*  f19a434:	10410003 */ 	beq	$v0,$at,.L0f19a444
/*  f19a438:	2401001f */ 	addiu	$at,$zero,0x1f
/*  f19a43c:	54410006 */ 	bnel	$v0,$at,.L0f19a458
/*  f19a440:	c46a000c */ 	lwc1	$f10,0xc($v1)
.L0f19a444:
/*  f19a444:	8c680004 */ 	lw	$t0,0x4($v1)
/*  f19a448:	c50800b4 */ 	lwc1	$f8,0xb4($t0)
/*  f19a44c:	1000000c */ 	beqz	$zero,.L0f19a480
/*  f19a450:	e7a8003c */ 	swc1	$f8,0x3c($sp)
/*  f19a454:	c46a000c */ 	lwc1	$f10,0xc($v1)
.L0f19a458:
/*  f19a458:	24010006 */ 	addiu	$at,$zero,0x6
/*  f19a45c:	e7aa003c */ 	swc1	$f10,0x3c($sp)
/*  f19a460:	90690000 */ 	lbu	$t1,0x0($v1)
/*  f19a464:	c7b0003c */ 	lwc1	$f16,0x3c($sp)
/*  f19a468:	15210005 */ 	bne	$t1,$at,.L0f19a480
/*  f19a46c:	3c0141c8 */ 	lui	$at,0x41c8
/*  f19a470:	44819000 */ 	mtc1	$at,$f18
/*  f19a474:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a478:	46128101 */ 	sub.s	$f4,$f16,$f18
/*  f19a47c:	e7a4003c */ 	swc1	$f4,0x3c($sp)
.L0f19a480:
/*  f19a480:	8fa40094 */ 	lw	$a0,0x94($sp)
/*  f19a484:	27a60038 */ 	addiu	$a2,$sp,0x38
/*  f19a488:	27a70098 */ 	addiu	$a3,$sp,0x98
/*  f19a48c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f19a490:	0fc100c7 */ 	jal	func0f04031c
/*  f19a494:	afa4002c */ 	sw	$a0,0x2c($sp)
/*  f19a498:	3c017f1c */ 	lui	$at,%hi(var7f1b914c)
/*  f19a49c:	1000001c */ 	beqz	$zero,.L0f19a510
/*  f19a4a0:	c420914c */ 	lwc1	$f0,%lo(var7f1b914c)($at)
.L0f19a4a4:
/*  f19a4a4:	3c017f1c */ 	lui	$at,%hi(var7f1b9150)
/*  f19a4a8:	0c0068f4 */ 	jal	cosf
/*  f19a4ac:	c42c9150 */ 	lwc1	$f12,%lo(var7f1b9150)($at)
/*  f19a4b0:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f19a4b4:	0c0068f7 */ 	jal	sinf
/*  f19a4b8:	c7ac0050 */ 	lwc1	$f12,0x50($sp)
/*  f19a4bc:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*  f19a4c0:	3c017f1c */ 	lui	$at,%hi(var7f1b9154)
/*  f19a4c4:	c42c9154 */ 	lwc1	$f12,%lo(var7f1b9154)($at)
/*  f19a4c8:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f19a4cc:	0c0068f7 */ 	jal	sinf
/*  f19a4d0:	e7a80098 */ 	swc1	$f8,0x98($sp)
/*  f19a4d4:	3c017f1c */ 	lui	$at,%hi(var7f1b9158)
/*  f19a4d8:	e7a0009c */ 	swc1	$f0,0x9c($sp)
/*  f19a4dc:	0c0068f4 */ 	jal	cosf
/*  f19a4e0:	c42c9158 */ 	lwc1	$f12,%lo(var7f1b9158)($at)
/*  f19a4e4:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f19a4e8:	0c0068f4 */ 	jal	cosf
/*  f19a4ec:	c7ac0050 */ 	lwc1	$f12,0x50($sp)
/*  f19a4f0:	c7aa0030 */ 	lwc1	$f10,0x30($sp)
/*  f19a4f4:	8faa0094 */ 	lw	$t2,0x94($sp)
/*  f19a4f8:	3c017f1c */ 	lui	$at,%hi(var7f1b915c)
/*  f19a4fc:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f19a500:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f19a504:	afab002c */ 	sw	$t3,0x2c($sp)
/*  f19a508:	c420915c */ 	lwc1	$f0,%lo(var7f1b915c)($at)
/*  f19a50c:	e7b000a0 */ 	swc1	$f16,0xa0($sp)
.L0f19a510:
/*  f19a510:	c7b20098 */ 	lwc1	$f18,0x98($sp)
/*  f19a514:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
/*  f19a518:	c7aa00a0 */ 	lwc1	$f10,0xa0($sp)
/*  f19a51c:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f19a520:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f19a524:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f19a528:	00000000 */ 	sll	$zero,$zero,0x0
/*  f19a52c:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f19a530:	e7a400e4 */ 	swc1	$f4,0xe4($sp)
/*  f19a534:	e7a800e8 */ 	swc1	$f8,0xe8($sp)
/*  f19a538:	0c00566c */ 	jal	func000159b0
/*  f19a53c:	e7b000ec */ 	swc1	$f16,0xec($sp)
/*  f19a540:	8e0c02d4 */ 	lw	$t4,0x2d4($s0)
/*  f19a544:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f19a548:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f19a54c:	8d8d0020 */ 	lw	$t5,0x20($t4)
/*  f19a550:	15a1000a */ 	bne	$t5,$at,.L0f19a57c
/*  f19a554:	3c017f1c */ 	lui	$at,%hi(var7f1b9160)
/*  f19a558:	0c005900 */ 	jal	func00016400
/*  f19a55c:	c42c9160 */ 	lwc1	$f12,%lo(var7f1b9160)($at)
/*  f19a560:	3c017f1c */ 	lui	$at,%hi(var7f1b9164)
/*  f19a564:	c42c9164 */ 	lwc1	$f12,%lo(var7f1b9164)($at)
/*  f19a568:	0c0058ba */ 	jal	func000162e8
/*  f19a56c:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f19a570:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f19a574:	0c00567f */ 	jal	func000159fc
/*  f19a578:	27a500a4 */ 	addiu	$a1,$sp,0xa4
.L0f19a57c:
/*  f19a57c:	3c017f1c */ 	lui	$at,%hi(var7f1b9168)
/*  f19a580:	c42c9168 */ 	lwc1	$f12,%lo(var7f1b9168)($at)
/*  f19a584:	0c0058ba */ 	jal	func000162e8
/*  f19a588:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f19a58c:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f19a590:	0c0056f8 */ 	jal	func00015be0
/*  f19a594:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f19a598:	c7ac0050 */ 	lwc1	$f12,0x50($sp)
/*  f19a59c:	0c0058dd */ 	jal	func00016374
/*  f19a5a0:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f19a5a4:	27a40054 */ 	addiu	$a0,$sp,0x54
/*  f19a5a8:	0c0056f8 */ 	jal	func00015be0
/*  f19a5ac:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f19a5b0:	8fa70094 */ 	lw	$a3,0x94($sp)
/*  f19a5b4:	27b900a4 */ 	addiu	$t9,$sp,0xa4
/*  f19a5b8:	27b800e4 */ 	addiu	$t8,$sp,0xe4
/*  f19a5bc:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f19a5c0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f19a5c4:	02002025 */ 	or	$a0,$s0,$zero
/*  f19a5c8:	27a50048 */ 	addiu	$a1,$sp,0x48
/*  f19a5cc:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f19a5d0:	0fc27b86 */ 	jal	func0f09ee18
/*  f19a5d4:	24e70028 */ 	addiu	$a3,$a3,0x28
/*  f19a5d8:	93ae0048 */ 	lbu	$t6,0x48($sp)
/*  f19a5dc:	24010022 */ 	addiu	$at,$zero,0x22
/*  f19a5e0:	55c10006 */ 	bnel	$t6,$at,.L0f19a5fc
/*  f19a5e4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f19a5e8:	8e0202d4 */ 	lw	$v0,0x2d4($s0)
/*  f19a5ec:	944f0064 */ 	lhu	$t7,0x64($v0)
/*  f19a5f0:	35e81000 */ 	ori	$t0,$t7,0x1000
/*  f19a5f4:	a4480064 */ 	sh	$t0,0x64($v0)
/*  f19a5f8:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f19a5fc:
/*  f19a5fc:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f19a600:	27bd00f0 */ 	addiu	$sp,$sp,0xf0
/*  f19a604:	03e00008 */ 	jr	$ra
/*  f19a608:	00000000 */ 	sll	$zero,$zero,0x0
);

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
