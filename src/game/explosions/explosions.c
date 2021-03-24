#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/dlights.h"
#include "game/chr/chr.h"
#include "game/prop.h"
#include "game/game_091e10.h"
#include "game/game_092610.h"
#include "game/game_0b3350.h"
#include "game/game_0b4950.h"
#include "game/explosions/explosions.h"
#include "game/smoke/smoke.h"
#include "game/room.h"
#include "game/game_1668e0.h"
#include "game/file.h"
#include "game/gfxmemory.h"
#include "game/mplayer/mplayer.h"
#include "game/propobj.h"
#include "game/utils.h"
#include "game/wallhit.h"
#include "bss.h"
#include "lib/lib_09a80.h"
#include "lib/main.h"
#include "lib/rng.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "data.h"
#include "types.h"

struct explosion *g_Explosions;
s32 g_MaxExplosions;

u32 var8007e4a0 = 0x00000000;
u32 var8007e4a4 = 0x00000000;
f32 var8007e4a8 = 1;
u32 var8007e4ac = 0x0000004b;
u32 var8007e4b0 = 0x000001e0;
u32 var8007e4b4 = 0x000000a8;

struct explosiontype g_ExplosionTypes[NUM_EXPLOSIONTYPES] = {
	//       rangeh
	//       |    rangev
	//       |    |    changerateh
	//       |    |    |    changeratev
	//       |    |    |    |     innersize
	//       |    |    |    |     |     blastradius
	//       |    |    |    |     |     |     damageradius
	//       |    |    |    |     |     |     |     duration
	//       |    |    |    |     |     |     |     |    propagationrate
	//       |    |    |    |     |     |     |     |    |  flarespeed
	//       |    |    |    |     |     |     |     |    |  |  smoketype
	//       |    |    |    |     |     |     |     |    |  |  |                       sound
	//       |    |    |    |     |     |     |     |    |  |  |                       |       damage
	//       |    |    |    |     |     |     |     |    |  |  |                       |       |
	/*00*/ { 0.1, 0.1, 0,   0,    0.1,  0,    0,    1,   1, 1, SMOKETYPE_NONE,         0x0000, 0     },
	/*01*/ { 1,   1,   0,   0,    1,    0,    0,    30,  1, 1, SMOKETYPE_BULLETIMPACT, 0x0000, 0     },
	/*02*/ { 20,  20,  0,   0,    30,   50,   50,   40,  1, 3, SMOKETYPE_MINI,         0x8099, 0.125 },
	/*03*/ { 50,  50,  0,   0,    50,   100,  100,  45,  1, 4, SMOKETYPE_MINI,         0x809a, 0.5   },
	/*04*/ { 60,  80,  2,   0.6,  100,  130,  240,  60,  2, 5, SMOKETYPE_ELECTRICAL,   0x809e, 1     },
	/*05*/ { 60,  120, 2,   0.6,  150,  160,  280,  60,  2, 5, SMOKETYPE_ELECTRICAL,   0x809e, 2     },
	/*06*/ { 20,  20,  0,   0,    22,   40,   40,   60,  1, 3, SMOKETYPE_MINI,         0x8099, 0.5   },
	/*07*/ { 35,  40,  0,   0,    35,   70,   70,   60,  1, 4, SMOKETYPE_MINI,         0x809a, 1     },
	/*08*/ { 50,  80,  2,   0.6,  50,   100,  160,  60,  2, 5, SMOKETYPE_ELECTRICAL,   0x809e, 2     },
	/*09*/ { 60,  120, 2,   0.6,  50,   130,  180,  60,  2, 5, SMOKETYPE_ELECTRICAL,   0x809e, 2     },
	/*10*/ { 40,  40,  0.8, 0.5,  70,   80,   160,  80,  4, 5, SMOKETYPE_SMALL,        0x80a0, 1     },
	/*11*/ { 50,  50,  1.2, 0.8,  100,  100,  200,  90,  1, 4, SMOKETYPE_SMALL,        0x809e, 2     },
	/*12*/ { 70,  60,  2,   1.2,  150,  140,  280,  90,  2, 5, SMOKETYPE_MEDIUM,       0x809e, 4     },
	/*13*/ { 80,  60,  4,   1.4,  200,  200,  400,  90,  2, 5, SMOKETYPE_LARGE,        0x809f, 4     },
	/*14*/ { 50,  50,  0,   0,    120,  150,  300,  150, 4, 4, SMOKETYPE_SMALL,        0x809f, 4     },
	/*15*/ { 1,   1,   0,   0,    1,    0,    0,    1,   1, 1, SMOKETYPE_BULLETIMPACT, 0x809c, 0     },
	/*16*/ { 1,   1,   0,   0,    1,    0,    0,    1,   1, 1, SMOKETYPE_BULLETIMPACT, 0x809c, 0     },
	/*17*/ { 80,  60,  10,  5,    1500, 2200, 3600, 500, 1, 2, SMOKETYPE_NONE,         0x80a5, 4     },
	/*18*/ { 80,  60,  3,   1,    300,  450,  640,  60,  1, 2, SMOKETYPE_NONE,         0x809f, 4     },
	/*19*/ { 90,  75,  2.5, 0.87, 250,  375,  600,  180, 2, 5, SMOKETYPE_LARGE,        0x809f, 4     },
	/*20*/ { 160, 120, 6,   2,    600,  450,  640,  60,  1, 2, SMOKETYPE_NONE,         0x809f, 4     },
	/*21*/ { 40,  30,  2,   0.7,  100,  140,  270,  45,  2, 5, SMOKETYPE_SMALL,        0x809f, 3.5   },
	/*22*/ { 20,  20,  0,   0,    30,   100,  200,  40,  1, 3, SMOKETYPE_MINI,         0x8099, 0.25  },
	/*23*/ { 100, 80,  4,   1.4,  210,  220,  500,  90,  2, 5, SMOKETYPE_LARGE,        0x809f, 4     },
	/*24*/ { 80,  60,  4,   1.4,  500,  200,  400,  90,  2, 5, SMOKETYPE_LARGE,        0x809f, 4     },
	/*25*/ { 640, 480, 32,  11.2, 1600, 1000, 1000, 180, 2, 5, SMOKETYPE_NONE,         0x80a4, 4     },
};

u32 var8007e930 = 0x00000000;
u32 var8007e934 = 0x00000000;
u32 var8007e938 = 0x00000000;

bool explosionCreateSimple(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, s32 playernum)
{
	return explosionCreate(prop, pos, rooms, type, playernum, false, NULL, 0, NULL);
}

bool explosionCreateComplex(struct prop *prop, struct coord *pos, s16 *rooms, s16 type, s32 playernum)
{
	struct coord sp100;
	struct coord sp88;
	struct explosiontype *etype;
	bool sp80 = true;
	s16 ret;
	f32 y;
	bool sp68;

	if (type == EXPLOSIONTYPE_0) {
		return false;
	}

	if (prop) {
		ret = func0002a564(&prop->pos, prop->rooms, &y, 0, &sp88, &sp68);
		sp100.x = prop->pos.x;
		sp100.y = y;
		sp100.z = prop->pos.z;
	} else {
		ret = func0002a564(pos, rooms, &y, 0, &sp88, &sp68);
		sp100.x = pos->x;
		sp100.y = y;
		sp100.z = pos->z;
	}

	etype = &g_ExplosionTypes[type];

	if (sp68 || ret <= 0
			|| !(pos->y - y <= (etype->rangev + etype->changeratev * etype->duration + etype->innersize) * 0.5f || pos->y - y <= 75)) {
		sp80 = false;
	}

	return explosionCreate(prop, pos, rooms, type, playernum, sp80, &sp100, ret, &sp88);
}

f32 explosionGetHorizontalRangeAtFrame(struct explosion *exp, s32 frame)
{
	struct explosiontype *type = &g_ExplosionTypes[exp->type];
	f32 changerate = PALUPF(type->changerateh);
	f32 result;

	if (exp->type == EXPLOSIONTYPE_14 && frame > PALDOWN(32)) {
		result = frame * PALUPF(3.0f) + 40.0f;

		if (result > 300) {
			result = 300;
		}
	} else {
		result = type->rangeh + changerate * frame;
	}

	return result;
}

f32 explosionGetVerticalRangeAtFrame(struct explosion *exp, s32 frame)
{
	struct explosiontype *type = &g_ExplosionTypes[exp->type];
	f32 changerate = PALUPF(type->changeratev);
	f32 result;

	if (exp->type == EXPLOSIONTYPE_14 && frame > PALDOWN(32)) {
		result = 20;
	} else {
		result = type->rangev + changerate * frame;
	}

	return result;
}

void explosionGetBboxAtFrame(struct coord *lower, struct coord *upper, s32 frame, struct prop *prop)
{
	struct explosion *exp = prop->explosion;
	struct explosiontype *type = &g_ExplosionTypes[exp->type];

	f32 rangeh = explosionGetHorizontalRangeAtFrame(exp, frame);
	f32 rangev = explosionGetVerticalRangeAtFrame(exp, frame);

	rangeh = rangeh * 0.5f + type->innersize * 1.5f;
	rangev = rangev * 0.5f + type->innersize * 1.5f;

	lower->x = prop->pos.x - rangeh;
	lower->y = prop->pos.y - rangev;
	lower->z = prop->pos.z - rangeh;

	upper->x = prop->pos.x + rangeh;
	upper->y = prop->pos.y + rangev;
	upper->z = prop->pos.z + rangeh;
}

void explosionAlertChrs(f32 *radius, struct coord *noisepos)
{
	u32 stack[2];
	s32 *end = (s32 *)&doorDestroyGlass;
	s32 i;

	for (i = 0; i < g_NumChrSlots; i++) {
		if (g_ChrSlots[i].model
				&& chrGetTargetProp(&g_ChrSlots[i]) == g_Vars.currentplayer->prop
				&& g_ChrSlots[i].prop
				&& g_ChrSlots[i].prop->type == PROPTYPE_CHR
				&& (g_ChrSlots[i].prop->flags & PROPFLAG_TANGIBLE)) {
			f32 distance = chrGetDistanceToCoord(&g_ChrSlots[i], noisepos);

			if (distance == 0) {
				distance = 2;
			} else {
				distance = (10.0f * *radius * g_ChrSlots[i].hearingscale) / distance;
			}

			if (distance > 1) {
				chrRecordLastHearTargetTime(&g_ChrSlots[i]);
			}
		}
	}

#if PIRACYCHECKS
	{
		u32 checksum = 0;
		s32 *ptr = (s32 *)&func0f084cf0;

		while (ptr < end) {
			checksum ^= *ptr;
			checksum <<= 1;
			ptr++;
		}

		if (checksum != CHECKSUM_PLACEHOLDER) {
			struct explosiontype *type = &g_ExplosionTypes[0];
			s32 i;

			for (i = 0; i != NUM_EXPLOSIONTYPES - 1; i++) {
				type->rangeh = 80;
				type->rangev = 60;
				type->changerateh = 15;
				type->changeratev = 5;
				type->innersize = 1500;
				type->blastradius = 200;
				type->damageradius = 3600;
				type++;
			}
		}
	}
#endif
}

GLOBAL_ASM(
glabel explosionCreate
.late_rodata
glabel var7f1b557c
.word 0x481c4000
glabel var7f1b5580
.word 0x497423fe
glabel var7f1b5584
.word 0x40c907a9
.text
/*  f129f54:	27bdfea0 */ 	addiu	$sp,$sp,-352
/*  f129f58:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f129f5c:	0007bc00 */ 	sll	$s7,$a3,0x10
/*  f129f60:	00177403 */ 	sra	$t6,$s7,0x10
/*  f129f64:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f129f68:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f129f6c:	00c0a025 */ 	or	$s4,$a2,$zero
/*  f129f70:	0080f025 */ 	or	$s8,$a0,$zero
/*  f129f74:	01c0b825 */ 	or	$s7,$t6,$zero
/*  f129f78:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f129f7c:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f129f80:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f129f84:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f129f88:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f129f8c:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f129f90:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f129f94:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f129f98:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f129f9c:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f129fa0:	afa50164 */ 	sw	$a1,0x164($sp)
/*  f129fa4:	afa7016c */ 	sw	$a3,0x16c($sp)
/*  f129fa8:	11c00006 */ 	beqz	$t6,.L0f129fc4
/*  f129fac:	00005025 */ 	or	$t2,$zero,$zero
/*  f129fb0:	84cf0000 */ 	lh	$t7,0x0($a2)
/*  f129fb4:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f129fb8:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f129fbc:	16cf0003 */ 	bne	$s6,$t7,.L0f129fcc
/*  f129fc0:	00000000 */ 	nop
.L0f129fc4:
/*  f129fc4:	10000334 */ 	b	.L0f12ac98
/*  f129fc8:	00001025 */ 	or	$v0,$zero,$zero
.L0f129fcc:
/*  f129fcc:	16e7003f */ 	bne	$s7,$a3,.L0f12a0cc
/*  f129fd0:	00000000 */ 	nop
/*  f129fd4:	0fc2d5ee */ 	jal	currentPlayerGetLodScaleZ
/*  f129fd8:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f129fdc:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f129fe0:	8fa30164 */ 	lw	$v1,0x164($sp)
/*  f129fe4:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f129fe8:	3c017f1b */ 	lui	$at,%hi(var7f1b557c)
/*  f129fec:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f129ff0:	c4461bb0 */ 	lwc1	$f6,0x1bb0($v0)
/*  f129ff4:	c4680004 */ 	lwc1	$f8,0x4($v1)
/*  f129ff8:	c44a1bb4 */ 	lwc1	$f10,0x1bb4($v0)
/*  f129ffc:	46062081 */ 	sub.s	$f2,$f4,$f6
/*  f12a000:	c4700008 */ 	lwc1	$f16,0x8($v1)
/*  f12a004:	c4521bb8 */ 	lwc1	$f18,0x1bb8($v0)
/*  f12a008:	460a4301 */ 	sub.s	$f12,$f8,$f10
/*  f12a00c:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f12a010:	c424557c */ 	lwc1	$f4,%lo(var7f1b557c)($at)
/*  f12a014:	46128381 */ 	sub.s	$f14,$f16,$f18
/*  f12a018:	460c6202 */ 	mul.s	$f8,$f12,$f12
/*  f12a01c:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12a020:	24421bb0 */ 	addiu	$v0,$v0,7088
/*  f12a024:	460e7402 */ 	mul.s	$f16,$f14,$f14
/*  f12a028:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f12a02c:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f12a030:	46009182 */ 	mul.s	$f6,$f18,$f0
/*  f12a034:	00000000 */ 	nop
/*  f12a038:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f12a03c:	4608203c */ 	c.lt.s	$f4,$f8
/*  f12a040:	00000000 */ 	nop
/*  f12a044:	45000021 */ 	bc1f	.L0f12a0cc
/*  f12a048:	00000000 */ 	nop
/*  f12a04c:	0c004b70 */ 	jal	random
/*  f12a050:	00000000 */ 	nop
/*  f12a054:	30580001 */ 	andi	$t8,$v0,0x1
/*  f12a058:	1700001a */ 	bnez	$t8,.L0f12a0c4
/*  f12a05c:	00000000 */ 	nop
/*  f12a060:	13c0000e */ 	beqz	$s8,.L0f12a09c
/*  f12a064:	8fa40164 */ 	lw	$a0,0x164($sp)
/*  f12a068:	0017c880 */ 	sll	$t9,$s7,0x2
/*  f12a06c:	0337c823 */ 	subu	$t9,$t9,$s7
/*  f12a070:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12a074:	0337c823 */ 	subu	$t9,$t9,$s7
/*  f12a078:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12a07c:	3c068008 */ 	lui	$a2,%hi(g_ExplosionTypes+0x24)
/*  f12a080:	00d93021 */ 	addu	$a2,$a2,$t9
/*  f12a084:	90c6e4dc */ 	lbu	$a2,%lo(g_ExplosionTypes+0x24)($a2)
/*  f12a088:	27c40008 */ 	addiu	$a0,$s8,0x8
/*  f12a08c:	0fc4ba08 */ 	jal	smokeCreateSimple
/*  f12a090:	27c50028 */ 	addiu	$a1,$s8,0x28
/*  f12a094:	10000300 */ 	b	.L0f12ac98
/*  f12a098:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f12a09c:
/*  f12a09c:	00176080 */ 	sll	$t4,$s7,0x2
/*  f12a0a0:	01976023 */ 	subu	$t4,$t4,$s7
/*  f12a0a4:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f12a0a8:	01976023 */ 	subu	$t4,$t4,$s7
/*  f12a0ac:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f12a0b0:	3c068008 */ 	lui	$a2,%hi(g_ExplosionTypes+0x24)
/*  f12a0b4:	00cc3021 */ 	addu	$a2,$a2,$t4
/*  f12a0b8:	90c6e4dc */ 	lbu	$a2,%lo(g_ExplosionTypes+0x24)($a2)
/*  f12a0bc:	0fc4ba08 */ 	jal	smokeCreateSimple
/*  f12a0c0:	02802825 */ 	or	$a1,$s4,$zero
.L0f12a0c4:
/*  f12a0c4:	100002f4 */ 	b	.L0f12ac98
/*  f12a0c8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f12a0cc:
/*  f12a0cc:	3c05800a */ 	lui	$a1,%hi(g_MaxExplosions)
/*  f12a0d0:	8ca53434 */ 	lw	$a1,%lo(g_MaxExplosions)($a1)
/*  f12a0d4:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f12a0d8:	00008825 */ 	or	$s1,$zero,$zero
/*  f12a0dc:	18a0000d */ 	blez	$a1,.L0f12a114
/*  f12a0e0:	3c04800a */ 	lui	$a0,%hi(g_Explosions)
/*  f12a0e4:	8c843430 */ 	lw	$a0,%lo(g_Explosions)($a0)
/*  f12a0e8:	00001825 */ 	or	$v1,$zero,$zero
/*  f12a0ec:	00801025 */ 	or	$v0,$a0,$zero
.L0f12a0f0:
/*  f12a0f0:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f12a0f4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f12a0f8:	0225082a */ 	slt	$at,$s1,$a1
/*  f12a0fc:	15a00003 */ 	bnez	$t5,.L0f12a10c
/*  f12a100:	24420478 */ 	addiu	$v0,$v0,0x478
/*  f12a104:	10000003 */ 	b	.L0f12a114
/*  f12a108:	00645021 */ 	addu	$t2,$v1,$a0
.L0f12a10c:
/*  f12a10c:	1420fff8 */ 	bnez	$at,.L0f12a0f0
/*  f12a110:	24630478 */ 	addiu	$v1,$v1,0x478
.L0f12a114:
/*  f12a114:	15400025 */ 	bnez	$t2,.L0f12a1ac
/*  f12a118:	02c02025 */ 	or	$a0,$s6,$zero
/*  f12a11c:	02c03025 */ 	or	$a2,$s6,$zero
/*  f12a120:	18a00010 */ 	blez	$a1,.L0f12a164
/*  f12a124:	00008825 */ 	or	$s1,$zero,$zero
/*  f12a128:	3c02800a */ 	lui	$v0,%hi(g_Explosions)
/*  f12a12c:	8c423430 */ 	lw	$v0,%lo(g_Explosions)($v0)
.L0f12a130:
/*  f12a130:	804e03cc */ 	lb	$t6,0x3cc($v0)
/*  f12a134:	54ee0008 */ 	bnel	$a3,$t6,.L0f12a158
/*  f12a138:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f12a13c:	844303c8 */ 	lh	$v1,0x3c8($v0)
/*  f12a140:	0083082a */ 	slt	$at,$a0,$v1
/*  f12a144:	50200004 */ 	beqzl	$at,.L0f12a158
/*  f12a148:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f12a14c:	00602025 */ 	or	$a0,$v1,$zero
/*  f12a150:	02203025 */ 	or	$a2,$s1,$zero
/*  f12a154:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f12a158:
/*  f12a158:	0225082a */ 	slt	$at,$s1,$a1
/*  f12a15c:	1420fff4 */ 	bnez	$at,.L0f12a130
/*  f12a160:	24420478 */ 	addiu	$v0,$v0,1144
.L0f12a164:
/*  f12a164:	04c00011 */ 	bltz	$a2,.L0f12a1ac
/*  f12a168:	3c11800a */ 	lui	$s1,%hi(g_Explosions)
/*  f12a16c:	000680c0 */ 	sll	$s0,$a2,0x3
/*  f12a170:	26313430 */ 	addiu	$s1,$s1,%lo(g_Explosions)
/*  f12a174:	02068021 */ 	addu	$s0,$s0,$a2
/*  f12a178:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f12a17c:	00108100 */ 	sll	$s0,$s0,0x4
/*  f12a180:	02068023 */ 	subu	$s0,$s0,$a2
/*  f12a184:	001080c0 */ 	sll	$s0,$s0,0x3
/*  f12a188:	01f0c021 */ 	addu	$t8,$t7,$s0
/*  f12a18c:	8f040000 */ 	lw	$a0,0x0($t8)
/*  f12a190:	0fc18ad9 */ 	jal	func0f062b64
/*  f12a194:	00e02825 */ 	or	$a1,$a3,$zero
/*  f12a198:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f12a19c:	03306021 */ 	addu	$t4,$t9,$s0
/*  f12a1a0:	ad800000 */ 	sw	$zero,0x0($t4)
/*  f12a1a4:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f12a1a8:	020d5021 */ 	addu	$t2,$s0,$t5
.L0f12a1ac:
/*  f12a1ac:	514002ba */ 	beqzl	$t2,.L0f12ac98
/*  f12a1b0:	000a102b */ 	sltu	$v0,$zero,$t2
/*  f12a1b4:	0fc180d6 */ 	jal	propAllocate
/*  f12a1b8:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12a1bc:	24010010 */ 	addiu	$at,$zero,0x10
/*  f12a1c0:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12a1c4:	12e10006 */ 	beq	$s7,$at,.L0f12a1e0
/*  f12a1c8:	0040a825 */ 	or	$s5,$v0,$zero
/*  f12a1cc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f12a1d0:	12e10003 */ 	beq	$s7,$at,.L0f12a1e0
/*  f12a1d4:	240e0006 */ 	addiu	$t6,$zero,0x6
/*  f12a1d8:	3c018008 */ 	lui	$at,%hi(var8007e4a0)
/*  f12a1dc:	ac2ee4a0 */ 	sw	$t6,%lo(var8007e4a0)($at)
.L0f12a1e0:
/*  f12a1e0:	104002ac */ 	beqz	$v0,.L0f12ac94
/*  f12a1e4:	8fa70164 */ 	lw	$a3,0x164($sp)
/*  f12a1e8:	240f0007 */ 	addiu	$t7,$zero,0x7
/*  f12a1ec:	a04f0000 */ 	sb	$t7,0x0($v0)
/*  f12a1f0:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f12a1f4:	c4ea0000 */ 	lwc1	$f10,0x0($a3)
/*  f12a1f8:	00008825 */ 	or	$s1,$zero,$zero
/*  f12a1fc:	e44a0008 */ 	swc1	$f10,0x8($v0)
/*  f12a200:	c4f00004 */ 	lwc1	$f16,0x4($a3)
/*  f12a204:	e450000c */ 	swc1	$f16,0xc($v0)
/*  f12a208:	c4f20008 */ 	lwc1	$f18,0x8($a3)
/*  f12a20c:	e4520010 */ 	swc1	$f18,0x10($v0)
/*  f12a210:	86980000 */ 	lh	$t8,0x0($s4)
/*  f12a214:	12d80020 */ 	beq	$s6,$t8,.L0f12a298
/*  f12a218:	0017c880 */ 	sll	$t9,$s7,0x2
/*  f12a21c:	0337c823 */ 	subu	$t9,$t9,$s7
/*  f12a220:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12a224:	0337c823 */ 	subu	$t9,$t9,$s7
/*  f12a228:	3c0c8008 */ 	lui	$t4,%hi(g_ExplosionTypes)
/*  f12a22c:	00111040 */ 	sll	$v0,$s1,0x1
/*  f12a230:	02828021 */ 	addu	$s0,$s4,$v0
/*  f12a234:	258ce4b8 */ 	addiu	$t4,$t4,%lo(g_ExplosionTypes)
/*  f12a238:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12a23c:	032c1821 */ 	addu	$v1,$t9,$t4
/*  f12a240:	86130000 */ 	lh	$s3,0x0($s0)
/*  f12a244:	afa3009c */ 	sw	$v1,0x9c($sp)
/*  f12a248:	24140007 */ 	addiu	$s4,$zero,0x7
/*  f12a24c:	02a29021 */ 	addu	$s2,$s5,$v0
/*  f12a250:	8fa3009c */ 	lw	$v1,0x9c($sp)
.L0f12a254:
/*  f12a254:	a6530028 */ 	sh	$s3,0x28($s2)
/*  f12a258:	86040000 */ 	lh	$a0,0x0($s0)
/*  f12a25c:	c4660000 */ 	lwc1	$f6,0x0($v1)
/*  f12a260:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12a264:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f12a268:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f12a26c:	44052000 */ 	mfc1	$a1,$f4
/*  f12a270:	0fc010e3 */ 	jal	roomAdjustLighting
/*  f12a274:	00000000 */ 	nop
/*  f12a278:	86130002 */ 	lh	$s3,0x2($s0)
/*  f12a27c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f12a280:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f12a284:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f12a288:	12d30003 */ 	beq	$s6,$s3,.L0f12a298
/*  f12a28c:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12a290:	5634fff0 */ 	bnel	$s1,$s4,.L0f12a254
/*  f12a294:	8fa3009c */ 	lw	$v1,0x9c($sp)
.L0f12a298:
/*  f12a298:	0017c080 */ 	sll	$t8,$s7,0x2
/*  f12a29c:	0317c023 */ 	subu	$t8,$t8,$s7
/*  f12a2a0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f12a2a4:	00117040 */ 	sll	$t6,$s1,0x1
/*  f12a2a8:	0317c023 */ 	subu	$t8,$t8,$s7
/*  f12a2ac:	3c198008 */ 	lui	$t9,%hi(g_ExplosionTypes)
/*  f12a2b0:	02ae7821 */ 	addu	$t7,$s5,$t6
/*  f12a2b4:	2739e4b8 */ 	addiu	$t9,$t9,%lo(g_ExplosionTypes)
/*  f12a2b8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f12a2bc:	a5f60028 */ 	sh	$s6,0x28($t7)
/*  f12a2c0:	03196021 */ 	addu	$t4,$t8,$t9
/*  f12a2c4:	afac009c */ 	sw	$t4,0x9c($sp)
/*  f12a2c8:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12a2cc:	0fc1814e */ 	jal	propAppendToList1
/*  f12a2d0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f12a2d4:	0fc180bc */ 	jal	propShow
/*  f12a2d8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f12a2dc:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12a2e0:	3c188008 */ 	lui	$t8,%hi(g_ExplosionTypes+0x2c)
/*  f12a2e4:	2718e4e4 */ 	addiu	$t8,$t8,%lo(g_ExplosionTypes+0x2c)
/*  f12a2e8:	a15703cc */ 	sb	$s7,0x3cc($t2)
/*  f12a2ec:	ad550000 */ 	sw	$s5,0x0($t2)
/*  f12a2f0:	ad5e0004 */ 	sw	$s8,0x4($t2)
/*  f12a2f4:	a54003c8 */ 	sh	$zero,0x3c8($t2)
/*  f12a2f8:	8fad0174 */ 	lw	$t5,0x174($sp)
/*  f12a2fc:	3c198008 */ 	lui	$t9,%hi(g_ExplosionTypes+0x3c8)
/*  f12a300:	2739e880 */ 	addiu	$t9,$t9,%lo(g_ExplosionTypes+0x3c8)
/*  f12a304:	a14d03cd */ 	sb	$t5,0x3cd($t2)
/*  f12a308:	8fae0170 */ 	lw	$t6,0x170($sp)
/*  f12a30c:	a14e03ce */ 	sb	$t6,0x3ce($t2)
/*  f12a310:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f12a314:	51f80007 */ 	beql	$t7,$t8,.L0f12a334
/*  f12a318:	86ac0028 */ 	lh	$t4,0x28($s5)
/*  f12a31c:	11f90004 */ 	beq	$t7,$t9,.L0f12a330
/*  f12a320:	02a02025 */ 	or	$a0,$s5,$zero
/*  f12a324:	0fc10e70 */ 	jal	propSetDangerous
/*  f12a328:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12a32c:	8faa0158 */ 	lw	$t2,0x158($sp)
.L0f12a330:
/*  f12a330:	86ac0028 */ 	lh	$t4,0x28($s5)
.L0f12a334:
/*  f12a334:	8fad009c */ 	lw	$t5,0x9c($sp)
/*  f12a338:	27a400d4 */ 	addiu	$a0,$sp,0xd4
/*  f12a33c:	afac012c */ 	sw	$t4,0x12c($sp)
/*  f12a340:	85a6001c */ 	lh	$a2,0x1c($t5)
/*  f12a344:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12a348:	27a500c8 */ 	addiu	$a1,$sp,0xc8
/*  f12a34c:	0fc4a702 */ 	jal	explosionGetBboxAtFrame
/*  f12a350:	02a03825 */ 	or	$a3,$s5,$zero
/*  f12a354:	3c013f80 */ 	lui	$at,0x3f80
/*  f12a358:	4481b000 */ 	mtc1	$at,$f22
/*  f12a35c:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f12a360:	c7b000d8 */ 	lwc1	$f16,0xd8($sp)
/*  f12a364:	c7a600dc */ 	lwc1	$f6,0xdc($sp)
/*  f12a368:	46164282 */ 	mul.s	$f10,$f8,$f22
/*  f12a36c:	c7a800c8 */ 	lwc1	$f8,0xc8($sp)
/*  f12a370:	8fab012c */ 	lw	$t3,0x12c($sp)
/*  f12a374:	46168482 */ 	mul.s	$f18,$f16,$f22
/*  f12a378:	c7b000cc */ 	lwc1	$f16,0xcc($sp)
/*  f12a37c:	3c09800a */ 	lui	$t1,%hi(g_Rooms)
/*  f12a380:	46163102 */ 	mul.s	$f4,$f6,$f22
/*  f12a384:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f12a388:	c7a600d0 */ 	lwc1	$f6,0xd0($sp)
/*  f12a38c:	46164282 */ 	mul.s	$f10,$f8,$f22
/*  f12a390:	e7b200d8 */ 	swc1	$f18,0xd8($sp)
/*  f12a394:	000b40c0 */ 	sll	$t0,$t3,0x3
/*  f12a398:	46168482 */ 	mul.s	$f18,$f16,$f22
/*  f12a39c:	e7a400dc */ 	swc1	$f4,0xdc($sp)
/*  f12a3a0:	25294928 */ 	addiu	$t1,$t1,%lo(g_Rooms)
/*  f12a3a4:	46163102 */ 	mul.s	$f4,$f6,$f22
/*  f12a3a8:	010b4021 */ 	addu	$t0,$t0,$t3
/*  f12a3ac:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f12a3b0:	00084080 */ 	sll	$t0,$t0,0x2
/*  f12a3b4:	010b4023 */ 	subu	$t0,$t0,$t3
/*  f12a3b8:	00084080 */ 	sll	$t0,$t0,0x2
/*  f12a3bc:	e7aa00c8 */ 	swc1	$f10,0xc8($sp)
/*  f12a3c0:	e7b200cc */ 	swc1	$f18,0xcc($sp)
/*  f12a3c4:	e7a400d0 */ 	swc1	$f4,0xd0($sp)
/*  f12a3c8:	01c8c021 */ 	addu	$t8,$t6,$t0
/*  f12a3cc:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12a3d0:	c7080018 */ 	lwc1	$f8,0x18($t8)
/*  f12a3d4:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f12a3d8:	24010019 */ 	addiu	$at,$zero,0x19
/*  f12a3dc:	e54803e8 */ 	swc1	$f8,0x3e8($t2)
/*  f12a3e0:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f12a3e4:	01e8c821 */ 	addu	$t9,$t7,$t0
/*  f12a3e8:	c72a001c */ 	lwc1	$f10,0x1c($t9)
/*  f12a3ec:	e54a03ec */ 	swc1	$f10,0x3ec($t2)
/*  f12a3f0:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*  f12a3f4:	01886821 */ 	addu	$t5,$t4,$t0
/*  f12a3f8:	c5b00020 */ 	lwc1	$f16,0x20($t5)
/*  f12a3fc:	e55003f0 */ 	swc1	$f16,0x3f0($t2)
/*  f12a400:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f12a404:	01c8c021 */ 	addu	$t8,$t6,$t0
/*  f12a408:	c7120024 */ 	lwc1	$f18,0x24($t8)
/*  f12a40c:	814e03cc */ 	lb	$t6,0x3cc($t2)
/*  f12a410:	e55203f4 */ 	swc1	$f18,0x3f4($t2)
/*  f12a414:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f12a418:	01e8c821 */ 	addu	$t9,$t7,$t0
/*  f12a41c:	c7260028 */ 	lwc1	$f6,0x28($t9)
/*  f12a420:	e54603f8 */ 	swc1	$f6,0x3f8($t2)
/*  f12a424:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*  f12a428:	01886821 */ 	addu	$t5,$t4,$t0
/*  f12a42c:	c5a4002c */ 	lwc1	$f4,0x2c($t5)
/*  f12a430:	a54b0400 */ 	sh	$t3,0x400($t2)
/*  f12a434:	a5560402 */ 	sh	$s6,0x402($t2)
/*  f12a438:	a14303cf */ 	sb	$v1,0x3cf($t2)
/*  f12a43c:	15c10003 */ 	bne	$t6,$at,.L0f12a44c
/*  f12a440:	e54403fc */ 	swc1	$f4,0x3fc($t2)
/*  f12a444:	100001c2 */ 	b	.L0f12ab50
/*  f12a448:	a14003cf */ 	sb	$zero,0x3cf($t2)
.L0f12a44c:
/*  f12a44c:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f12a450:	27b700e0 */ 	addiu	$s7,$sp,0xe0
/*  f12a454:	03087821 */ 	addu	$t7,$t8,$t0
/*  f12a458:	c5e80018 */ 	lwc1	$f8,0x18($t7)
/*  f12a45c:	e54803e8 */ 	swc1	$f8,0x3e8($t2)
/*  f12a460:	8d390000 */ 	lw	$t9,0x0($t1)
/*  f12a464:	03286021 */ 	addu	$t4,$t9,$t0
/*  f12a468:	c58a001c */ 	lwc1	$f10,0x1c($t4)
/*  f12a46c:	e54a03ec */ 	swc1	$f10,0x3ec($t2)
/*  f12a470:	8d2d0000 */ 	lw	$t5,0x0($t1)
/*  f12a474:	01a87021 */ 	addu	$t6,$t5,$t0
/*  f12a478:	c5d00020 */ 	lwc1	$f16,0x20($t6)
/*  f12a47c:	e55003f0 */ 	swc1	$f16,0x3f0($t2)
/*  f12a480:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f12a484:	03087821 */ 	addu	$t7,$t8,$t0
/*  f12a488:	c5f20024 */ 	lwc1	$f18,0x24($t7)
/*  f12a48c:	e55203f4 */ 	swc1	$f18,0x3f4($t2)
/*  f12a490:	8d390000 */ 	lw	$t9,0x0($t1)
/*  f12a494:	03286021 */ 	addu	$t4,$t9,$t0
/*  f12a498:	c5860028 */ 	lwc1	$f6,0x28($t4)
/*  f12a49c:	e54603f8 */ 	swc1	$f6,0x3f8($t2)
/*  f12a4a0:	8d2d0000 */ 	lw	$t5,0x0($t1)
/*  f12a4a4:	01a87021 */ 	addu	$t6,$t5,$t0
/*  f12a4a8:	c5c4002c */ 	lwc1	$f4,0x2c($t6)
/*  f12a4ac:	a54b0400 */ 	sh	$t3,0x400($t2)
/*  f12a4b0:	a5560402 */ 	sh	$s6,0x402($t2)
/*  f12a4b4:	a14303cf */ 	sb	$v1,0x3cf($t2)
/*  f12a4b8:	e54403fc */ 	swc1	$f4,0x3fc($t2)
/*  f12a4bc:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f12a4c0:	afa00120 */ 	sw	$zero,0x120($sp)
/*  f12a4c4:	03081021 */ 	addu	$v0,$t8,$t0
/*  f12a4c8:	804f0005 */ 	lb	$t7,0x5($v0)
/*  f12a4cc:	59e0018f */ 	blezl	$t7,.L0f12ab0c
/*  f12a4d0:	c55203e8 */ 	lwc1	$f18,0x3e8($t2)
/*  f12a4d4:	4480c000 */ 	mtc1	$zero,$f24
/*  f12a4d8:	afa00090 */ 	sw	$zero,0x90($sp)
/*  f12a4dc:	afa80094 */ 	sw	$t0,0x94($sp)
/*  f12a4e0:	844c000e */ 	lh	$t4,0xe($v0)
.L0f12a4e4:
/*  f12a4e4:	3c19800a */ 	lui	$t9,%hi(g_RoomPortals)
/*  f12a4e8:	8f394ce0 */ 	lw	$t9,%lo(g_RoomPortals)($t9)
/*  f12a4ec:	8fa70090 */ 	lw	$a3,0x90($sp)
/*  f12a4f0:	000c6840 */ 	sll	$t5,$t4,0x1
/*  f12a4f4:	032d7021 */ 	addu	$t6,$t9,$t5
/*  f12a4f8:	01c7c021 */ 	addu	$t8,$t6,$a3
/*  f12a4fc:	87040000 */ 	lh	$a0,0x0($t8)
/*  f12a500:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12a504:	27a50104 */ 	addiu	$a1,$sp,0x104
/*  f12a508:	27a600f8 */ 	addiu	$a2,$sp,0xf8
/*  f12a50c:	0fc59401 */ 	jal	func0f165004
/*  f12a510:	afa40118 */ 	sw	$a0,0x118($sp)
/*  f12a514:	27a40104 */ 	addiu	$a0,$sp,0x104
/*  f12a518:	27a500f8 */ 	addiu	$a1,$sp,0xf8
/*  f12a51c:	27a600d4 */ 	addiu	$a2,$sp,0xd4
/*  f12a520:	0fc593e7 */ 	jal	func0f164f9c
/*  f12a524:	27a700c8 */ 	addiu	$a3,$sp,0xc8
/*  f12a528:	3c09800a */ 	lui	$t1,%hi(g_Rooms)
/*  f12a52c:	25294928 */ 	addiu	$t1,$t1,%lo(g_Rooms)
/*  f12a530:	10400168 */ 	beqz	$v0,.L0f12aad4
/*  f12a534:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12a538:	8fa50118 */ 	lw	$a1,0x118($sp)
/*  f12a53c:	3c0c800a */ 	lui	$t4,%hi(g_BgPortals)
/*  f12a540:	8d8c4cc8 */ 	lw	$t4,%lo(g_BgPortals)($t4)
/*  f12a544:	240fffff */ 	addiu	$t7,$zero,-1
/*  f12a548:	0005c8c0 */ 	sll	$t9,$a1,0x3
/*  f12a54c:	a7af00c4 */ 	sh	$t7,0xc4($sp)
/*  f12a550:	01991021 */ 	addu	$v0,$t4,$t9
/*  f12a554:	84430002 */ 	lh	$v1,0x2($v0)
/*  f12a558:	8fad012c */ 	lw	$t5,0x12c($sp)
/*  f12a55c:	00002025 */ 	or	$a0,$zero,$zero
/*  f12a560:	0000b025 */ 	or	$s6,$zero,$zero
/*  f12a564:	15a30004 */ 	bne	$t5,$v1,.L0f12a578
/*  f12a568:	0005c080 */ 	sll	$t8,$a1,0x2
/*  f12a56c:	844e0004 */ 	lh	$t6,0x4($v0)
/*  f12a570:	10000002 */ 	b	.L0f12a57c
/*  f12a574:	a7ae00c6 */ 	sh	$t6,0xc6($sp)
.L0f12a578:
/*  f12a578:	a7a300c6 */ 	sh	$v1,0xc6($sp)
.L0f12a57c:
/*  f12a57c:	3c0f800a */ 	lui	$t7,%hi(var800a4ccc)
/*  f12a580:	8def4ccc */ 	lw	$t7,%lo(var800a4ccc)($t7)
/*  f12a584:	0305c021 */ 	addu	$t8,$t8,$a1
/*  f12a588:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f12a58c:	030f1021 */ 	addu	$v0,$t8,$t7
/*  f12a590:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f12a594:	27a500f8 */ 	addiu	$a1,$sp,0xf8
/*  f12a598:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f12a59c:	e7a800ac */ 	swc1	$f8,0xac($sp)
/*  f12a5a0:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f12a5a4:	c44a0004 */ 	lwc1	$f10,0x4($v0)
/*  f12a5a8:	4618903c */ 	c.lt.s	$f18,$f24
/*  f12a5ac:	e7aa00b0 */ 	swc1	$f10,0xb0($sp)
/*  f12a5b0:	c4500008 */ 	lwc1	$f16,0x8($v0)
/*  f12a5b4:	45000003 */ 	bc1f	.L0f12a5c4
/*  f12a5b8:	e7b000b4 */ 	swc1	$f16,0xb4($sp)
/*  f12a5bc:	46009187 */ 	neg.s	$f6,$f18
/*  f12a5c0:	e7a600ac */ 	swc1	$f6,0xac($sp)
.L0f12a5c4:
/*  f12a5c4:	c7a000b0 */ 	lwc1	$f0,0xb0($sp)
/*  f12a5c8:	c7a200b4 */ 	lwc1	$f2,0xb4($sp)
/*  f12a5cc:	4618003c */ 	c.lt.s	$f0,$f24
/*  f12a5d0:	00000000 */ 	nop
/*  f12a5d4:	45020003 */ 	bc1fl	.L0f12a5e4
/*  f12a5d8:	4618103c */ 	c.lt.s	$f2,$f24
/*  f12a5dc:	46000007 */ 	neg.s	$f0,$f0
/*  f12a5e0:	4618103c */ 	c.lt.s	$f2,$f24
.L0f12a5e4:
/*  f12a5e4:	00000000 */ 	nop
/*  f12a5e8:	45020004 */ 	bc1fl	.L0f12a5fc
/*  f12a5ec:	c7a400ac */ 	lwc1	$f4,0xac($sp)
/*  f12a5f0:	46001087 */ 	neg.s	$f2,$f2
/*  f12a5f4:	e7a200b4 */ 	swc1	$f2,0xb4($sp)
/*  f12a5f8:	c7a400ac */ 	lwc1	$f4,0xac($sp)
.L0f12a5fc:
/*  f12a5fc:	e7a000b0 */ 	swc1	$f0,0xb0($sp)
/*  f12a600:	4600203c */ 	c.lt.s	$f4,$f0
/*  f12a604:	00000000 */ 	nop
/*  f12a608:	45020003 */ 	bc1fl	.L0f12a618
/*  f12a60c:	00041080 */ 	sll	$v0,$a0,0x2
/*  f12a610:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f12a614:	00041080 */ 	sll	$v0,$a0,0x2
.L0f12a618:
/*  f12a618:	afa2008c */ 	sw	$v0,0x8c($sp)
/*  f12a61c:	03a26021 */ 	addu	$t4,$sp,$v0
/*  f12a620:	c58800ac */ 	lwc1	$f8,0xac($t4)
/*  f12a624:	c7aa00b4 */ 	lwc1	$f10,0xb4($sp)
/*  f12a628:	24020008 */ 	addiu	$v0,$zero,0x8
/*  f12a62c:	460a403c */ 	c.lt.s	$f8,$f10
/*  f12a630:	00000000 */ 	nop
/*  f12a634:	45020004 */ 	bc1fl	.L0f12a648
/*  f12a638:	24990001 */ 	addiu	$t9,$a0,0x1
/*  f12a63c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f12a640:	afa2008c */ 	sw	$v0,0x8c($sp)
/*  f12a644:	24990001 */ 	addiu	$t9,$a0,0x1
.L0f12a648:
/*  f12a648:	0326001a */ 	div	$zero,$t9,$a2
/*  f12a64c:	0000a010 */ 	mfhi	$s4
/*  f12a650:	248e0002 */ 	addiu	$t6,$a0,0x2
/*  f12a654:	27a20104 */ 	addiu	$v0,$sp,0x104
/*  f12a658:	01c6001a */ 	div	$zero,$t6,$a2
/*  f12a65c:	0000a810 */ 	mfhi	$s5
/*  f12a660:	00146880 */ 	sll	$t5,$s4,0x2
/*  f12a664:	0015c080 */ 	sll	$t8,$s5,0x2
/*  f12a668:	00adf021 */ 	addu	$s8,$a1,$t5
/*  f12a66c:	004d1821 */ 	addu	$v1,$v0,$t5
/*  f12a670:	00b83821 */ 	addu	$a3,$a1,$t8
/*  f12a674:	00584021 */ 	addu	$t0,$v0,$t8
/*  f12a678:	c4720000 */ 	lwc1	$f18,0x0($v1)
/*  f12a67c:	c7d00000 */ 	lwc1	$f16,0x0($s8)
/*  f12a680:	c5040000 */ 	lwc1	$f4,0x0($t0)
/*  f12a684:	c4e60000 */ 	lwc1	$f6,0x0($a3)
/*  f12a688:	14c00002 */ 	bnez	$a2,.L0f12a694
/*  f12a68c:	00000000 */ 	nop
/*  f12a690:	0007000d */ 	break	0x7
.L0f12a694:
/*  f12a694:	2401ffff */ 	addiu	$at,$zero,-1
/*  f12a698:	14c10004 */ 	bne	$a2,$at,.L0f12a6ac
/*  f12a69c:	3c018000 */ 	lui	$at,0x8000
/*  f12a6a0:	17210002 */ 	bne	$t9,$at,.L0f12a6ac
/*  f12a6a4:	00000000 */ 	nop
/*  f12a6a8:	0006000d */ 	break	0x6
.L0f12a6ac:
/*  f12a6ac:	46128001 */ 	sub.s	$f0,$f16,$f18
/*  f12a6b0:	8fab008c */ 	lw	$t3,0x8c($sp)
/*  f12a6b4:	27af0104 */ 	addiu	$t7,$sp,0x104
/*  f12a6b8:	46043081 */ 	sub.s	$f2,$f6,$f4
/*  f12a6bc:	01a0a025 */ 	or	$s4,$t5,$zero
/*  f12a6c0:	14c00002 */ 	bnez	$a2,.L0f12a6cc
/*  f12a6c4:	00000000 */ 	nop
/*  f12a6c8:	0007000d */ 	break	0x7
.L0f12a6cc:
/*  f12a6cc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f12a6d0:	14c10004 */ 	bne	$a2,$at,.L0f12a6e4
/*  f12a6d4:	3c018000 */ 	lui	$at,0x8000
/*  f12a6d8:	15c10002 */ 	bne	$t6,$at,.L0f12a6e4
/*  f12a6dc:	00000000 */ 	nop
/*  f12a6e0:	0006000d */ 	break	0x6
.L0f12a6e4:
/*  f12a6e4:	4600103c */ 	c.lt.s	$f2,$f0
/*  f12a6e8:	0300a825 */ 	or	$s5,$t8,$zero
/*  f12a6ec:	27ac00f8 */ 	addiu	$t4,$sp,0xf8
/*  f12a6f0:	016f2821 */ 	addu	$a1,$t3,$t7
/*  f12a6f4:	45020003 */ 	bc1fl	.L0f12a704
/*  f12a6f8:	016c3021 */ 	addu	$a2,$t3,$t4
/*  f12a6fc:	46001006 */ 	mov.s	$f0,$f2
/*  f12a700:	016c3021 */ 	addu	$a2,$t3,$t4
.L0f12a704:
/*  f12a704:	c4a80000 */ 	lwc1	$f8,0x0($a1)
/*  f12a708:	c4d00000 */ 	lwc1	$f16,0x0($a2)
/*  f12a70c:	8d240000 */ 	lw	$a0,0x0($t1)
/*  f12a710:	46004281 */ 	sub.s	$f10,$f8,$f0
/*  f12a714:	46008480 */ 	add.s	$f18,$f16,$f0
/*  f12a718:	e4aa0000 */ 	swc1	$f10,0x0($a1)
/*  f12a71c:	c4a20000 */ 	lwc1	$f2,0x0($a1)
/*  f12a720:	e4d20000 */ 	swc1	$f18,0x0($a2)
/*  f12a724:	8fb9012c */ 	lw	$t9,0x12c($sp)
/*  f12a728:	001968c0 */ 	sll	$t5,$t9,0x3
/*  f12a72c:	01b96821 */ 	addu	$t5,$t5,$t9
/*  f12a730:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f12a734:	01b96823 */ 	subu	$t5,$t5,$t9
/*  f12a738:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f12a73c:	008d7021 */ 	addu	$t6,$a0,$t5
/*  f12a740:	01cb1021 */ 	addu	$v0,$t6,$t3
/*  f12a744:	c44c0018 */ 	lwc1	$f12,0x18($v0)
/*  f12a748:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f12a74c:	afa50070 */ 	sw	$a1,0x70($sp)
/*  f12a750:	460c103c */ 	c.lt.s	$f2,$f12
/*  f12a754:	00000000 */ 	nop
/*  f12a758:	45020004 */ 	bc1fl	.L0f12a76c
/*  f12a75c:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f12a760:	e4ac0000 */ 	swc1	$f12,0x0($a1)
/*  f12a764:	c4a20000 */ 	lwc1	$f2,0x0($a1)
/*  f12a768:	8fb80068 */ 	lw	$t8,0x68($sp)
.L0f12a76c:
/*  f12a76c:	c44c0024 */ 	lwc1	$f12,0x24($v0)
/*  f12a770:	c7000000 */ 	lwc1	$f0,0x0($t8)
/*  f12a774:	4600603c */ 	c.lt.s	$f12,$f0
/*  f12a778:	00000000 */ 	nop
/*  f12a77c:	45020004 */ 	bc1fl	.L0f12a790
/*  f12a780:	87af00c6 */ 	lh	$t7,0xc6($sp)
/*  f12a784:	e70c0000 */ 	swc1	$f12,0x0($t8)
/*  f12a788:	c7000000 */ 	lwc1	$f0,0x0($t8)
/*  f12a78c:	87af00c6 */ 	lh	$t7,0xc6($sp)
.L0f12a790:
/*  f12a790:	8fad008c */ 	lw	$t5,0x8c($sp)
/*  f12a794:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f12a798:	000f60c0 */ 	sll	$t4,$t7,0x3
/*  f12a79c:	018f6021 */ 	addu	$t4,$t4,$t7
/*  f12a7a0:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f12a7a4:	018f6023 */ 	subu	$t4,$t4,$t7
/*  f12a7a8:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f12a7ac:	008cc821 */ 	addu	$t9,$a0,$t4
/*  f12a7b0:	032d1021 */ 	addu	$v0,$t9,$t5
/*  f12a7b4:	c44c0018 */ 	lwc1	$f12,0x18($v0)
/*  f12a7b8:	4602603c */ 	c.lt.s	$f12,$f2
/*  f12a7bc:	00000000 */ 	nop
/*  f12a7c0:	45020003 */ 	bc1fl	.L0f12a7d0
/*  f12a7c4:	c4420024 */ 	lwc1	$f2,0x24($v0)
/*  f12a7c8:	e5cc0000 */ 	swc1	$f12,0x0($t6)
/*  f12a7cc:	c4420024 */ 	lwc1	$f2,0x24($v0)
.L0f12a7d0:
/*  f12a7d0:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f12a7d4:	4602003c */ 	c.lt.s	$f0,$f2
/*  f12a7d8:	00000000 */ 	nop
/*  f12a7dc:	45020003 */ 	bc1fl	.L0f12a7ec
/*  f12a7e0:	87b300c6 */ 	lh	$s3,0xc6($sp)
/*  f12a7e4:	e7020000 */ 	swc1	$f2,0x0($t8)
/*  f12a7e8:	87b300c6 */ 	lh	$s3,0xc6($sp)
.L0f12a7ec:
/*  f12a7ec:	001378c0 */ 	sll	$t7,$s3,0x3
/*  f12a7f0:	01f37821 */ 	addu	$t7,$t7,$s3
/*  f12a7f4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f12a7f8:	01f37823 */ 	subu	$t7,$t7,$s3
/*  f12a7fc:	000f9880 */ 	sll	$s3,$t7,0x2
/*  f12a800:	00931021 */ 	addu	$v0,$a0,$s3
/*  f12a804:	804c0005 */ 	lb	$t4,0x5($v0)
/*  f12a808:	5980006b */ 	blezl	$t4,.L0f12a9b8
/*  f12a80c:	c7aa0104 */ 	lwc1	$f10,0x104($sp)
/*  f12a810:	00008825 */ 	or	$s1,$zero,$zero
/*  f12a814:	844d000e */ 	lh	$t5,0xe($v0)
.L0f12a818:
/*  f12a818:	3c19800a */ 	lui	$t9,%hi(g_RoomPortals)
/*  f12a81c:	8f394ce0 */ 	lw	$t9,%lo(g_RoomPortals)($t9)
/*  f12a820:	000d7040 */ 	sll	$t6,$t5,0x1
/*  f12a824:	8fac0118 */ 	lw	$t4,0x118($sp)
/*  f12a828:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f12a82c:	03117821 */ 	addu	$t7,$t8,$s1
/*  f12a830:	85f00000 */ 	lh	$s0,0x0($t7)
/*  f12a834:	27a500ec */ 	addiu	$a1,$sp,0xec
/*  f12a838:	02e03025 */ 	or	$a2,$s7,$zero
/*  f12a83c:	120c0055 */ 	beq	$s0,$t4,.L0f12a994
/*  f12a840:	02002025 */ 	or	$a0,$s0,$zero
/*  f12a844:	3c014120 */ 	lui	$at,0x4120
/*  f12a848:	44813000 */ 	mtc1	$at,$f6
/*  f12a84c:	02859021 */ 	addu	$s2,$s4,$a1
/*  f12a850:	afa30080 */ 	sw	$v1,0x80($sp)
/*  f12a854:	46163502 */ 	mul.s	$f20,$f6,$f22
/*  f12a858:	afa70078 */ 	sw	$a3,0x78($sp)
/*  f12a85c:	afa80074 */ 	sw	$t0,0x74($sp)
/*  f12a860:	0fc59401 */ 	jal	func0f165004
/*  f12a864:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12a868:	8fa30080 */ 	lw	$v1,0x80($sp)
/*  f12a86c:	c64a0000 */ 	lwc1	$f10,0x0($s2)
/*  f12a870:	3c09800a */ 	lui	$t1,%hi(g_Rooms)
/*  f12a874:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f12a878:	25294928 */ 	addiu	$t1,$t1,%lo(g_Rooms)
/*  f12a87c:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f12a880:	46142200 */ 	add.s	$f8,$f4,$f20
/*  f12a884:	8fa80074 */ 	lw	$t0,0x74($sp)
/*  f12a888:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12a88c:	4608503e */ 	c.le.s	$f10,$f8
/*  f12a890:	00000000 */ 	nop
/*  f12a894:	45020040 */ 	bc1fl	.L0f12a998
/*  f12a898:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f12a89c:	c5100000 */ 	lwc1	$f16,0x0($t0)
/*  f12a8a0:	03b5c821 */ 	addu	$t9,$sp,$s5
/*  f12a8a4:	c72600ec */ 	lwc1	$f6,0xec($t9)
/*  f12a8a8:	46148480 */ 	add.s	$f18,$f16,$f20
/*  f12a8ac:	4612303e */ 	c.le.s	$f6,$f18
/*  f12a8b0:	00000000 */ 	nop
/*  f12a8b4:	45020038 */ 	bc1fl	.L0f12a998
/*  f12a8b8:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f12a8bc:	c7c80000 */ 	lwc1	$f8,0x0($s8)
/*  f12a8c0:	02f47021 */ 	addu	$t6,$s7,$s4
/*  f12a8c4:	c5c40000 */ 	lwc1	$f4,0x0($t6)
/*  f12a8c8:	46144281 */ 	sub.s	$f10,$f8,$f20
/*  f12a8cc:	4604503e */ 	c.le.s	$f10,$f4
/*  f12a8d0:	00000000 */ 	nop
/*  f12a8d4:	45020030 */ 	bc1fl	.L0f12a998
/*  f12a8d8:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f12a8dc:	c4f20000 */ 	lwc1	$f18,0x0($a3)
/*  f12a8e0:	02f5c021 */ 	addu	$t8,$s7,$s5
/*  f12a8e4:	c7100000 */ 	lwc1	$f16,0x0($t8)
/*  f12a8e8:	46149181 */ 	sub.s	$f6,$f18,$f20
/*  f12a8ec:	4610303e */ 	c.le.s	$f6,$f16
/*  f12a8f0:	00000000 */ 	nop
/*  f12a8f4:	45000027 */ 	bc1f	.L0f12a994
/*  f12a8f8:	3c0f800a */ 	lui	$t7,%hi(g_BgPortals)
/*  f12a8fc:	8def4cc8 */ 	lw	$t7,%lo(g_BgPortals)($t7)
/*  f12a900:	001060c0 */ 	sll	$t4,$s0,0x3
/*  f12a904:	87ad00c6 */ 	lh	$t5,0xc6($sp)
/*  f12a908:	01ec1021 */ 	addu	$v0,$t7,$t4
/*  f12a90c:	84430002 */ 	lh	$v1,0x2($v0)
/*  f12a910:	55a30005 */ 	bnel	$t5,$v1,.L0f12a928
/*  f12a914:	a7a300c4 */ 	sh	$v1,0xc4($sp)
/*  f12a918:	84590004 */ 	lh	$t9,0x4($v0)
/*  f12a91c:	10000002 */ 	b	.L0f12a928
/*  f12a920:	a7b900c4 */ 	sh	$t9,0xc4($sp)
/*  f12a924:	a7a300c4 */ 	sh	$v1,0xc4($sp)
.L0f12a928:
/*  f12a928:	87b800c4 */ 	lh	$t8,0xc4($sp)
/*  f12a92c:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f12a930:	8fad008c */ 	lw	$t5,0x8c($sp)
/*  f12a934:	001878c0 */ 	sll	$t7,$t8,0x3
/*  f12a938:	01f87821 */ 	addu	$t7,$t7,$t8
/*  f12a93c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f12a940:	01f87823 */ 	subu	$t7,$t7,$t8
/*  f12a944:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f12a948:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f12a94c:	01cf6021 */ 	addu	$t4,$t6,$t7
/*  f12a950:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f12a954:	c4400018 */ 	lwc1	$f0,0x18($v0)
/*  f12a958:	c7280000 */ 	lwc1	$f8,0x0($t9)
/*  f12a95c:	4608003c */ 	c.lt.s	$f0,$f8
/*  f12a960:	00000000 */ 	nop
/*  f12a964:	45020003 */ 	bc1fl	.L0f12a974
/*  f12a968:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f12a96c:	e7200000 */ 	swc1	$f0,0x0($t9)
/*  f12a970:	8fb80068 */ 	lw	$t8,0x68($sp)
.L0f12a974:
/*  f12a974:	c4400024 */ 	lwc1	$f0,0x24($v0)
/*  f12a978:	c7040000 */ 	lwc1	$f4,0x0($t8)
/*  f12a97c:	4600203c */ 	c.lt.s	$f4,$f0
/*  f12a980:	00000000 */ 	nop
/*  f12a984:	4502000c */ 	bc1fl	.L0f12a9b8
/*  f12a988:	c7aa0104 */ 	lwc1	$f10,0x104($sp)
/*  f12a98c:	10000009 */ 	b	.L0f12a9b4
/*  f12a990:	e7000000 */ 	swc1	$f0,0x0($t8)
.L0f12a994:
/*  f12a994:	8d2e0000 */ 	lw	$t6,0x0($t1)
.L0f12a998:
/*  f12a998:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f12a99c:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f12a9a0:	01d31021 */ 	addu	$v0,$t6,$s3
/*  f12a9a4:	804f0005 */ 	lb	$t7,0x5($v0)
/*  f12a9a8:	02cf082a */ 	slt	$at,$s6,$t7
/*  f12a9ac:	5420ff9a */ 	bnezl	$at,.L0f12a818
/*  f12a9b0:	844d000e */ 	lh	$t5,0xe($v0)
.L0f12a9b4:
/*  f12a9b4:	c7aa0104 */ 	lwc1	$f10,0x104($sp)
.L0f12a9b8:
/*  f12a9b8:	c7b00108 */ 	lwc1	$f16,0x108($sp)
/*  f12a9bc:	c7a8010c */ 	lwc1	$f8,0x10c($sp)
/*  f12a9c0:	46165482 */ 	mul.s	$f18,$f10,$f22
/*  f12a9c4:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f12a9c8:	2403001c */ 	addiu	$v1,$zero,0x1c
/*  f12a9cc:	46168182 */ 	mul.s	$f6,$f16,$f22
/*  f12a9d0:	e7b20104 */ 	swc1	$f18,0x104($sp)
/*  f12a9d4:	46164102 */ 	mul.s	$f4,$f8,$f22
/*  f12a9d8:	e7a60108 */ 	swc1	$f6,0x108($sp)
/*  f12a9dc:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f12a9e0:	c7a600fc */ 	lwc1	$f6,0xfc($sp)
/*  f12a9e4:	e7a4010c */ 	swc1	$f4,0x10c($sp)
/*  f12a9e8:	46163202 */ 	mul.s	$f8,$f6,$f22
/*  f12a9ec:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*  f12a9f0:	e7b000f8 */ 	swc1	$f16,0xf8($sp)
/*  f12a9f4:	46162282 */ 	mul.s	$f10,$f4,$f22
/*  f12a9f8:	e7a800fc */ 	swc1	$f8,0xfc($sp)
/*  f12a9fc:	e7aa0100 */ 	swc1	$f10,0x100($sp)
/*  f12aa00:	914c03cf */ 	lbu	$t4,0x3cf($t2)
/*  f12aa04:	01830019 */ 	multu	$t4,$v1
/*  f12aa08:	00006812 */ 	mflo	$t5
/*  f12aa0c:	014dc821 */ 	addu	$t9,$t2,$t5
/*  f12aa10:	e73203e8 */ 	swc1	$f18,0x3e8($t9)
/*  f12aa14:	915803cf */ 	lbu	$t8,0x3cf($t2)
/*  f12aa18:	c7b00108 */ 	lwc1	$f16,0x108($sp)
/*  f12aa1c:	03030019 */ 	multu	$t8,$v1
/*  f12aa20:	00007012 */ 	mflo	$t6
/*  f12aa24:	014e7821 */ 	addu	$t7,$t2,$t6
/*  f12aa28:	e5f003ec */ 	swc1	$f16,0x3ec($t7)
/*  f12aa2c:	914c03cf */ 	lbu	$t4,0x3cf($t2)
/*  f12aa30:	c7a6010c */ 	lwc1	$f6,0x10c($sp)
/*  f12aa34:	01830019 */ 	multu	$t4,$v1
/*  f12aa38:	00006812 */ 	mflo	$t5
/*  f12aa3c:	014dc821 */ 	addu	$t9,$t2,$t5
/*  f12aa40:	e72603f0 */ 	swc1	$f6,0x3f0($t9)
/*  f12aa44:	915803cf */ 	lbu	$t8,0x3cf($t2)
/*  f12aa48:	c7a800f8 */ 	lwc1	$f8,0xf8($sp)
/*  f12aa4c:	03030019 */ 	multu	$t8,$v1
/*  f12aa50:	00007012 */ 	mflo	$t6
/*  f12aa54:	014e7821 */ 	addu	$t7,$t2,$t6
/*  f12aa58:	e5e803f4 */ 	swc1	$f8,0x3f4($t7)
/*  f12aa5c:	914c03cf */ 	lbu	$t4,0x3cf($t2)
/*  f12aa60:	c7a400fc */ 	lwc1	$f4,0xfc($sp)
/*  f12aa64:	01830019 */ 	multu	$t4,$v1
/*  f12aa68:	00006812 */ 	mflo	$t5
/*  f12aa6c:	014dc821 */ 	addu	$t9,$t2,$t5
/*  f12aa70:	e72403f8 */ 	swc1	$f4,0x3f8($t9)
/*  f12aa74:	915803cf */ 	lbu	$t8,0x3cf($t2)
/*  f12aa78:	c7aa0100 */ 	lwc1	$f10,0x100($sp)
/*  f12aa7c:	03030019 */ 	multu	$t8,$v1
/*  f12aa80:	00007012 */ 	mflo	$t6
/*  f12aa84:	014e7821 */ 	addu	$t7,$t2,$t6
/*  f12aa88:	e5ea03fc */ 	swc1	$f10,0x3fc($t7)
/*  f12aa8c:	914d03cf */ 	lbu	$t5,0x3cf($t2)
/*  f12aa90:	87ac00c6 */ 	lh	$t4,0xc6($sp)
/*  f12aa94:	01a30019 */ 	multu	$t5,$v1
/*  f12aa98:	0000c812 */ 	mflo	$t9
/*  f12aa9c:	0159c021 */ 	addu	$t8,$t2,$t9
/*  f12aaa0:	a70c0400 */ 	sh	$t4,0x400($t8)
/*  f12aaa4:	914f03cf */ 	lbu	$t7,0x3cf($t2)
/*  f12aaa8:	87ae00c4 */ 	lh	$t6,0xc4($sp)
/*  f12aaac:	01e30019 */ 	multu	$t7,$v1
/*  f12aab0:	00006812 */ 	mflo	$t5
/*  f12aab4:	014dc821 */ 	addu	$t9,$t2,$t5
/*  f12aab8:	a72e0402 */ 	sh	$t6,0x402($t9)
/*  f12aabc:	914c03cf */ 	lbu	$t4,0x3cf($t2)
/*  f12aac0:	25980001 */ 	addiu	$t8,$t4,0x1
/*  f12aac4:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f12aac8:	29e10005 */ 	slti	$at,$t7,0x5
/*  f12aacc:	1020000e */ 	beqz	$at,.L0f12ab08
/*  f12aad0:	a15803cf */ 	sb	$t8,0x3cf($t2)
.L0f12aad4:
/*  f12aad4:	8fad0090 */ 	lw	$t5,0x90($sp)
/*  f12aad8:	8fa40120 */ 	lw	$a0,0x120($sp)
/*  f12aadc:	8d390000 */ 	lw	$t9,0x0($t1)
/*  f12aae0:	8fac0094 */ 	lw	$t4,0x94($sp)
/*  f12aae4:	25ae0002 */ 	addiu	$t6,$t5,0x2
/*  f12aae8:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f12aaec:	afa40120 */ 	sw	$a0,0x120($sp)
/*  f12aaf0:	afae0090 */ 	sw	$t6,0x90($sp)
/*  f12aaf4:	032c1021 */ 	addu	$v0,$t9,$t4
/*  f12aaf8:	80580005 */ 	lb	$t8,0x5($v0)
/*  f12aafc:	0098082a */ 	slt	$at,$a0,$t8
/*  f12ab00:	5420fe78 */ 	bnezl	$at,.L0f12a4e4
/*  f12ab04:	844c000e */ 	lh	$t4,0xe($v0)
.L0f12ab08:
/*  f12ab08:	c55203e8 */ 	lwc1	$f18,0x3e8($t2)
.L0f12ab0c:
/*  f12ab0c:	c54603ec */ 	lwc1	$f6,0x3ec($t2)
/*  f12ab10:	c54403f0 */ 	lwc1	$f4,0x3f0($t2)
/*  f12ab14:	46169402 */ 	mul.s	$f16,$f18,$f22
/*  f12ab18:	c55203f4 */ 	lwc1	$f18,0x3f4($t2)
/*  f12ab1c:	46163202 */ 	mul.s	$f8,$f6,$f22
/*  f12ab20:	c54603f8 */ 	lwc1	$f6,0x3f8($t2)
/*  f12ab24:	46162282 */ 	mul.s	$f10,$f4,$f22
/*  f12ab28:	e55003e8 */ 	swc1	$f16,0x3e8($t2)
/*  f12ab2c:	c54403fc */ 	lwc1	$f4,0x3fc($t2)
/*  f12ab30:	46169402 */ 	mul.s	$f16,$f18,$f22
/*  f12ab34:	e54803ec */ 	swc1	$f8,0x3ec($t2)
/*  f12ab38:	46163202 */ 	mul.s	$f8,$f6,$f22
/*  f12ab3c:	e54a03f0 */ 	swc1	$f10,0x3f0($t2)
/*  f12ab40:	46162282 */ 	mul.s	$f10,$f4,$f22
/*  f12ab44:	e55003f4 */ 	swc1	$f16,0x3f4($t2)
/*  f12ab48:	e54803f8 */ 	swc1	$f8,0x3f8($t2)
/*  f12ab4c:	e54a03fc */ 	swc1	$f10,0x3fc($t2)
.L0f12ab50:
/*  f12ab50:	8faf0174 */ 	lw	$t7,0x174($sp)
/*  f12ab54:	8fa20178 */ 	lw	$v0,0x178($sp)
/*  f12ab58:	3c017f1b */ 	lui	$at,%hi(var7f1b5580)
/*  f12ab5c:	11e00011 */ 	beqz	$t7,.L0f12aba4
/*  f12ab60:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f12ab64:	c4520000 */ 	lwc1	$f18,0x0($v0)
/*  f12ab68:	8fa30180 */ 	lw	$v1,0x180($sp)
/*  f12ab6c:	e55203d0 */ 	swc1	$f18,0x3d0($t2)
/*  f12ab70:	c4500004 */ 	lwc1	$f16,0x4($v0)
/*  f12ab74:	e55003d4 */ 	swc1	$f16,0x3d4($t2)
/*  f12ab78:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f12ab7c:	e54603d8 */ 	swc1	$f6,0x3d8($t2)
/*  f12ab80:	87ad017e */ 	lh	$t5,0x17e($sp)
/*  f12ab84:	a54d03ca */ 	sh	$t5,0x3ca($t2)
/*  f12ab88:	c4680000 */ 	lwc1	$f8,0x0($v1)
/*  f12ab8c:	e54803dc */ 	swc1	$f8,0x3dc($t2)
/*  f12ab90:	c4640004 */ 	lwc1	$f4,0x4($v1)
/*  f12ab94:	e54403e0 */ 	swc1	$f4,0x3e0($t2)
/*  f12ab98:	c46a0008 */ 	lwc1	$f10,0x8($v1)
/*  f12ab9c:	10000003 */ 	b	.L0f12abac
/*  f12aba0:	e54a03e4 */ 	swc1	$f10,0x3e4($t2)
.L0f12aba4:
/*  f12aba4:	c4325580 */ 	lwc1	$f18,%lo(var7f1b5580)($at)
/*  f12aba8:	e55203d0 */ 	swc1	$f18,0x3d0($t2)
.L0f12abac:
/*  f12abac:	a54e001c */ 	sh	$t6,0x1c($t2)
/*  f12abb0:	8fb90164 */ 	lw	$t9,0x164($sp)
/*  f12abb4:	c7300000 */ 	lwc1	$f16,0x0($t9)
/*  f12abb8:	e5500008 */ 	swc1	$f16,0x8($t2)
/*  f12abbc:	8fac0164 */ 	lw	$t4,0x164($sp)
/*  f12abc0:	c5860004 */ 	lwc1	$f6,0x4($t4)
/*  f12abc4:	e546000c */ 	swc1	$f6,0xc($t2)
/*  f12abc8:	8fb80164 */ 	lw	$t8,0x164($sp)
/*  f12abcc:	c7080008 */ 	lwc1	$f8,0x8($t8)
/*  f12abd0:	e5480010 */ 	swc1	$f8,0x10($t2)
/*  f12abd4:	0c004b70 */ 	jal	random
/*  f12abd8:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12abdc:	44822000 */ 	mtc1	$v0,$f4
/*  f12abe0:	3c012f80 */ 	lui	$at,0x2f80
/*  f12abe4:	4481a000 */ 	mtc1	$at,$f20
/*  f12abe8:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12abec:	04410005 */ 	bgez	$v0,.L0f12ac04
/*  f12abf0:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f12abf4:	3c014f80 */ 	lui	$at,0x4f80
/*  f12abf8:	44819000 */ 	mtc1	$at,$f18
/*  f12abfc:	00000000 */ 	nop
/*  f12ac00:	46125280 */ 	add.s	$f10,$f10,$f18
.L0f12ac04:
/*  f12ac04:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f12ac08:	3c013f00 */ 	lui	$at,0x3f00
/*  f12ac0c:	44813000 */ 	mtc1	$at,$f6
/*  f12ac10:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f12ac14:	c5f20010 */ 	lwc1	$f18,0x10($t7)
/*  f12ac18:	46068202 */ 	mul.s	$f8,$f16,$f6
/*  f12ac1c:	46164100 */ 	add.s	$f4,$f8,$f22
/*  f12ac20:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f12ac24:	0c004b70 */ 	jal	random
/*  f12ac28:	e54a0014 */ 	swc1	$f10,0x14($t2)
/*  f12ac2c:	44828000 */ 	mtc1	$v0,$f16
/*  f12ac30:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12ac34:	04410005 */ 	bgez	$v0,.L0f12ac4c
/*  f12ac38:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f12ac3c:	3c014f80 */ 	lui	$at,0x4f80
/*  f12ac40:	44814000 */ 	mtc1	$at,$f8
/*  f12ac44:	00000000 */ 	nop
/*  f12ac48:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f12ac4c:
/*  f12ac4c:	46143102 */ 	mul.s	$f4,$f6,$f20
/*  f12ac50:	3c017f1b */ 	lui	$at,%hi(var7f1b5584)
/*  f12ac54:	c4325584 */ 	lwc1	$f18,%lo(var7f1b5584)($at)
/*  f12ac58:	a140001e */ 	sb	$zero,0x1e($t2)
/*  f12ac5c:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x314)
/*  f12ac60:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f12ac64:	e54a0018 */ 	swc1	$f10,0x18($t2)
/*  f12ac68:	8dada2d4 */ 	lw	$t5,%lo(g_Vars+0x314)($t5)
/*  f12ac6c:	51a00005 */ 	beqzl	$t5,.L0f12ac84
/*  f12ac70:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*  f12ac74:	0fc4bd7e */ 	jal	smokeClearSomeTypes
/*  f12ac78:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12ac7c:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f12ac80:	8fa4009c */ 	lw	$a0,0x9c($sp)
.L0f12ac84:
/*  f12ac84:	8fa50164 */ 	lw	$a1,0x164($sp)
/*  f12ac88:	0fc4a73f */ 	jal	explosionAlertChrs
/*  f12ac8c:	afaa0158 */ 	sw	$t2,0x158($sp)
/*  f12ac90:	8faa0158 */ 	lw	$t2,0x158($sp)
.L0f12ac94:
/*  f12ac94:	000a102b */ 	sltu	$v0,$zero,$t2
.L0f12ac98:
/*  f12ac98:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f12ac9c:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f12aca0:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f12aca4:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f12aca8:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f12acac:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f12acb0:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f12acb4:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f12acb8:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f12acbc:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f12acc0:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f12acc4:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f12acc8:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f12accc:	03e00008 */ 	jr	$ra
/*  f12acd0:	27bd0160 */ 	addiu	$sp,$sp,0x160
/*  f12acd4:	24020006 */ 	addiu	$v0,$zero,0x6
/*  f12acd8:	3c018008 */ 	lui	$at,%hi(var8007e4a0)
/*  f12acdc:	ac22e4a0 */ 	sw	$v0,%lo(var8007e4a0)($at)
/*  f12ace0:	3c018008 */ 	lui	$at,%hi(var8007e4a4)
/*  f12ace4:	03e00008 */ 	jr	$ra
/*  f12ace8:	ac22e4a4 */ 	sw	$v0,%lo(var8007e4a4)($at)
);

GLOBAL_ASM(
glabel func0f12acec
.late_rodata
glabel var7f1b5588
.word 0x3f4ccccd
glabel var7f1b558c
.word 0x38d1b717
.text
/*  f12acec:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f12acf0:	3c0e8008 */ 	lui	$t6,%hi(var8007e4a0)
/*  f12acf4:	8dcee4a0 */ 	lw	$t6,%lo(var8007e4a0)($t6)
/*  f12acf8:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f12acfc:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f12ad00:	00a08825 */ 	or	$s1,$a1,$zero
/*  f12ad04:	00809025 */ 	or	$s2,$a0,$zero
/*  f12ad08:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f12ad0c:	afb50048 */ 	sw	$s5,0x48($sp)
/*  f12ad10:	afb40044 */ 	sw	$s4,0x44($sp)
/*  f12ad14:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f12ad18:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f12ad1c:	f7ba0028 */ 	sdc1	$f26,0x28($sp)
/*  f12ad20:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f12ad24:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f12ad28:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f12ad2c:	15c00006 */ 	bnez	$t6,.L0f12ad48
/*  f12ad30:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f12ad34:	44806000 */ 	mtc1	$zero,$f12
/*  f12ad38:	0c002a94 */ 	jal	func0000aa50
/*  f12ad3c:	00000000 */ 	nop
/*  f12ad40:	1000007a */ 	b	.L0f12af2c
/*  f12ad44:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f12ad48:
/*  f12ad48:	3c017f1b */ 	lui	$at,%hi(var7f1b5588)
/*  f12ad4c:	c4345588 */ 	lwc1	$f20,%lo(var7f1b5588)($at)
/*  f12ad50:	0c0068f4 */ 	jal	cosf
/*  f12ad54:	4600a306 */ 	mov.s	$f12,$f20
/*  f12ad58:	46000606 */ 	mov.s	$f24,$f0
/*  f12ad5c:	0c0068f7 */ 	jal	sinf
/*  f12ad60:	4600a306 */ 	mov.s	$f12,$f20
/*  f12ad64:	c6240000 */ 	lwc1	$f4,0x0($s1)
/*  f12ad68:	c6280008 */ 	lwc1	$f8,0x8($s1)
/*  f12ad6c:	4600a306 */ 	mov.s	$f12,$f20
/*  f12ad70:	4604c182 */ 	mul.s	$f6,$f24,$f4
/*  f12ad74:	00000000 */ 	nop
/*  f12ad78:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f12ad7c:	460a3401 */ 	sub.s	$f16,$f6,$f10
/*  f12ad80:	0c0068f7 */ 	jal	sinf
/*  f12ad84:	e7b00054 */ 	swc1	$f16,0x54($sp)
/*  f12ad88:	46000606 */ 	mov.s	$f24,$f0
/*  f12ad8c:	0c0068f4 */ 	jal	cosf
/*  f12ad90:	4600a306 */ 	mov.s	$f12,$f20
/*  f12ad94:	c6320008 */ 	lwc1	$f18,0x8($s1)
/*  f12ad98:	c6280000 */ 	lwc1	$f8,0x0($s1)
/*  f12ad9c:	3c04800a */ 	lui	$a0,%hi(g_MaxExplosions)
/*  f12ada0:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f12ada4:	8c843434 */ 	lw	$a0,%lo(g_MaxExplosions)($a0)
/*  f12ada8:	4480b000 */ 	mtc1	$zero,$f22
/*  f12adac:	4608c182 */ 	mul.s	$f6,$f24,$f8
/*  f12adb0:	3c14800a */ 	lui	$s4,%hi(g_Explosions)
/*  f12adb4:	26943430 */ 	addiu	$s4,$s4,%lo(g_Explosions)
/*  f12adb8:	00008825 */ 	or	$s1,$zero,$zero
/*  f12adbc:	00008025 */ 	or	$s0,$zero,$zero
/*  f12adc0:	3c02800a */ 	lui	$v0,%hi(g_Explosions)
/*  f12adc4:	3c014170 */ 	lui	$at,0x4170
/*  f12adc8:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f12adcc:	2415002c */ 	addiu	$s5,$zero,0x2c
/*  f12add0:	4600b506 */ 	mov.s	$f20,$f22
/*  f12add4:	1880002f */ 	blez	$a0,.L0f12ae94
/*  f12add8:	e7aa0050 */ 	swc1	$f10,0x50($sp)
/*  f12addc:	4481d000 */ 	mtc1	$at,$f26
/*  f12ade0:	3c017f1b */ 	lui	$at,%hi(var7f1b558c)
/*  f12ade4:	3c138008 */ 	lui	$s3,%hi(g_ExplosionTypes)
/*  f12ade8:	2673e4b8 */ 	addiu	$s3,$s3,%lo(g_ExplosionTypes)
/*  f12adec:	c438558c */ 	lwc1	$f24,%lo(var7f1b558c)($at)
/*  f12adf0:	8c423430 */ 	lw	$v0,%lo(g_Explosions)($v0)
.L0f12adf4:
/*  f12adf4:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f12adf8:	50600022 */ 	beqzl	$v1,.L0f12ae84
/*  f12adfc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f12ae00:	c4700008 */ 	lwc1	$f16,0x8($v1)
/*  f12ae04:	c6520000 */ 	lwc1	$f18,0x0($s2)
/*  f12ae08:	c468000c */ 	lwc1	$f8,0xc($v1)
/*  f12ae0c:	c6440004 */ 	lwc1	$f4,0x4($s2)
/*  f12ae10:	46128001 */ 	sub.s	$f0,$f16,$f18
/*  f12ae14:	c4660010 */ 	lwc1	$f6,0x10($v1)
/*  f12ae18:	c64a0008 */ 	lwc1	$f10,0x8($s2)
/*  f12ae1c:	46044081 */ 	sub.s	$f2,$f8,$f4
/*  f12ae20:	46000402 */ 	mul.s	$f16,$f0,$f0
/*  f12ae24:	460a3381 */ 	sub.s	$f14,$f6,$f10
/*  f12ae28:	46021482 */ 	mul.s	$f18,$f2,$f2
/*  f12ae2c:	46128200 */ 	add.s	$f8,$f16,$f18
/*  f12ae30:	460e7102 */ 	mul.s	$f4,$f14,$f14
/*  f12ae34:	0c012974 */ 	jal	sqrtf
/*  f12ae38:	46044300 */ 	add.s	$f12,$f8,$f4
/*  f12ae3c:	46160032 */ 	c.eq.s	$f0,$f22
/*  f12ae40:	46000086 */ 	mov.s	$f2,$f0
/*  f12ae44:	45020003 */ 	bc1fl	.L0f12ae54
/*  f12ae48:	8e8f0000 */ 	lw	$t7,0x0($s4)
/*  f12ae4c:	4600c086 */ 	mov.s	$f2,$f24
/*  f12ae50:	8e8f0000 */ 	lw	$t7,0x0($s4)
.L0f12ae54:
/*  f12ae54:	3c04800a */ 	lui	$a0,%hi(g_MaxExplosions)
/*  f12ae58:	8c843434 */ 	lw	$a0,%lo(g_MaxExplosions)($a0)
/*  f12ae5c:	01f11021 */ 	addu	$v0,$t7,$s1
/*  f12ae60:	805803cc */ 	lb	$t8,0x3cc($v0)
/*  f12ae64:	03150019 */ 	multu	$t8,$s5
/*  f12ae68:	0000c812 */ 	mflo	$t9
/*  f12ae6c:	02794021 */ 	addu	$t0,$s3,$t9
/*  f12ae70:	c5060010 */ 	lwc1	$f6,0x10($t0)
/*  f12ae74:	46023003 */ 	div.s	$f0,$f6,$f2
/*  f12ae78:	461a0282 */ 	mul.s	$f10,$f0,$f26
/*  f12ae7c:	460aa500 */ 	add.s	$f20,$f20,$f10
/*  f12ae80:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f12ae84:
/*  f12ae84:	0204082a */ 	slt	$at,$s0,$a0
/*  f12ae88:	26310478 */ 	addiu	$s1,$s1,0x478
/*  f12ae8c:	1420ffd9 */ 	bnez	$at,.L0f12adf4
/*  f12ae90:	24420478 */ 	addiu	$v0,$v0,1144
.L0f12ae94:
/*  f12ae94:	3c038008 */ 	lui	$v1,%hi(var8007e4a4)
/*  f12ae98:	2463e4a4 */ 	addiu	$v1,$v1,%lo(var8007e4a4)
/*  f12ae9c:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f12aea0:	3c013f80 */ 	lui	$at,0x3f80
/*  f12aea4:	18400005 */ 	blez	$v0,.L0f12aebc
/*  f12aea8:	00000000 */ 	nop
/*  f12aeac:	44818000 */ 	mtc1	$at,$f16
/*  f12aeb0:	2449ffff */ 	addiu	$t1,$v0,-1
/*  f12aeb4:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f12aeb8:	4610a500 */ 	add.s	$f20,$f20,$f16
.L0f12aebc:
/*  f12aebc:	3c038008 */ 	lui	$v1,%hi(var8007e4a0)
/*  f12aec0:	2463e4a0 */ 	addiu	$v1,$v1,%lo(var8007e4a0)
/*  f12aec4:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f12aec8:	254bffff */ 	addiu	$t3,$t2,-1
/*  f12aecc:	316d0002 */ 	andi	$t5,$t3,0x2
/*  f12aed0:	11a00005 */ 	beqz	$t5,.L0f12aee8
/*  f12aed4:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f12aed8:	8fa20070 */ 	lw	$v0,0x70($sp)
/*  f12aedc:	e4540004 */ 	swc1	$f20,0x4($v0)
/*  f12aee0:	10000004 */ 	b	.L0f12aef4
/*  f12aee4:	4600a507 */ 	neg.s	$f20,$f20
.L0f12aee8:
/*  f12aee8:	8fa20070 */ 	lw	$v0,0x70($sp)
/*  f12aeec:	4600a487 */ 	neg.s	$f18,$f20
/*  f12aef0:	e4520004 */ 	swc1	$f18,0x4($v0)
.L0f12aef4:
/*  f12aef4:	c7a80054 */ 	lwc1	$f8,0x54($sp)
/*  f12aef8:	4608a102 */ 	mul.s	$f4,$f20,$f8
/*  f12aefc:	e4440000 */ 	swc1	$f4,0x0($v0)
/*  f12af00:	c7a60050 */ 	lwc1	$f6,0x50($sp)
/*  f12af04:	4606a282 */ 	mul.s	$f10,$f20,$f6
/*  f12af08:	e44a0008 */ 	swc1	$f10,0x8($v0)
/*  f12af0c:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f12af10:	448f8000 */ 	mtc1	$t7,$f16
/*  f12af14:	00000000 */ 	nop
/*  f12af18:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f12af1c:	46149302 */ 	mul.s	$f12,$f18,$f20
/*  f12af20:	0c002a94 */ 	jal	func0000aa50
/*  f12af24:	00000000 */ 	nop
/*  f12af28:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f12af2c:
/*  f12af2c:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f12af30:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f12af34:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f12af38:	d7ba0028 */ 	ldc1	$f26,0x28($sp)
/*  f12af3c:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f12af40:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f12af44:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f12af48:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f12af4c:	8fb40044 */ 	lw	$s4,0x44($sp)
/*  f12af50:	8fb50048 */ 	lw	$s5,0x48($sp)
/*  f12af54:	03e00008 */ 	jr	$ra
/*  f12af58:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

bool func0f12af5c(struct explosion *exp, struct prop *prop, struct coord *pos1, struct coord *pos2)
{
	bool result = false;
	s32 i;
	s16 rooms[8];

	if (exp->type == EXPLOSIONTYPE_25) {
		result = true;
	} else {
		for (i = 0; i < exp->numbb; i++) {
			rooms[0] = exp->bbs[i].room;

			if (exp->bbs[i].room2 != -1) {
				rooms[1] = exp->bbs[i].room2;
			} else {
				rooms[1] = -1;
			}

			rooms[2] = -1;

			if (arrayIntersects(prop->rooms, rooms)
					&& pos1->x <= exp->bbs[i].unk0c.x
					&& pos1->y <= exp->bbs[i].unk0c.y
					&& pos1->z <= exp->bbs[i].unk0c.z
					&& pos2->x >= exp->bbs[i].unk00.x
					&& pos2->y >= exp->bbs[i].unk00.y
					&& pos2->z >= exp->bbs[i].unk00.z) {
				result = true;
				break;
			}
		}
	}

	return result;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f12b0e0
.late_rodata
glabel var7f1b688cpf
.word 0x3f555555
glabel var7f1b6890pf
.word 0x3f555555
glabel var7f1b6894pf
.word 0x3f333333
glabel var7f1b6898pf
.word 0x3e99999a
glabel var7f1b689cpf
.word 0x3d4ccccd
glabel var7f1b68a0pf
.word 0x3d4ccccd
.text
/*  f12bbc8:	27bdfc58 */ 	addiu	$sp,$sp,-936
/*  f12bbcc:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f12bbd0:	afbe0070 */ 	sw	$s8,0x70($sp)
/*  f12bbd4:	afb7006c */ 	sw	$s7,0x6c($sp)
/*  f12bbd8:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f12bbdc:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f12bbe0:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f12bbe4:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f12bbe8:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f12bbec:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f12bbf0:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f12bbf4:	f7be0048 */ 	sdc1	$f30,0x48($sp)
/*  f12bbf8:	f7bc0040 */ 	sdc1	$f28,0x40($sp)
/*  f12bbfc:	f7ba0038 */ 	sdc1	$f26,0x38($sp)
/*  f12bc00:	f7b80030 */ 	sdc1	$f24,0x30($sp)
/*  f12bc04:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f12bc08:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f12bc0c:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*  f12bc10:	3c088008 */ 	lui	$t0,0x8008
/*  f12bc14:	2508e988 */ 	addiu	$t0,$t0,-5752
/*  f12bc18:	afae03a0 */ 	sw	$t6,0x3a0($sp)
/*  f12bc1c:	81d803cc */ 	lb	$t8,0x3cc($t6)
/*  f12bc20:	3c1e800a */ 	lui	$s8,0x800a
/*  f12bc24:	27dea510 */ 	addiu	$s8,$s8,-23280
/*  f12bc28:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f12bc2c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f12bc30:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12bc34:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f12bc38:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12bc3c:	03284821 */ 	addu	$t1,$t9,$t0
/*  f12bc40:	afa9039c */ 	sw	$t1,0x39c($sp)
/*  f12bc44:	85c203c8 */ 	lh	$v0,0x3c8($t6)
/*  f12bc48:	8fcb0038 */ 	lw	$t3,0x38($s8)
/*  f12bc4c:	0080b825 */ 	move	$s7,$a0
/*  f12bc50:	284a0001 */ 	slti	$t2,$v0,0x1
/*  f12bc54:	19600290 */ 	blez	$t3,.PF0f12c698
/*  f12bc58:	afaa0194 */ 	sw	$t2,0x194($sp)
/*  f12bc5c:	4480e000 */ 	mtc1	$zero,$f28
/*  f12bc60:	c5240028 */ 	lwc1	$f4,0x28($t1)
/*  f12bc64:	461c203e */ 	c.le.s	$f4,$f28
/*  f12bc68:	00000000 */ 	nop
/*  f12bc6c:	4503028b */ 	bc1tl	.PF0f12c69c
/*  f12bc70:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f12bc74:	11400006 */ 	beqz	$t2,.PF0f12bc90
/*  f12bc78:	8fb9039c */ 	lw	$t9,0x39c($sp)
/*  f12bc7c:	8538001c */ 	lh	$t8,0x1c($t1)
/*  f12bc80:	c53a0018 */ 	lwc1	$f26,0x18($t1)
/*  f12bc84:	44983000 */ 	mtc1	$t8,$f6
/*  f12bc88:	10000015 */ 	b	.PF0f12bce0
/*  f12bc8c:	46803320 */ 	cvt.s.w	$f12,$f6
.PF0f12bc90:
/*  f12bc90:	8728001c */ 	lh	$t0,0x1c($t9)
/*  f12bc94:	44822000 */ 	mtc1	$v0,$f4
/*  f12bc98:	c7200014 */ 	lwc1	$f0,0x14($t9)
/*  f12bc9c:	c7220018 */ 	lwc1	$f2,0x18($t9)
/*  f12bca0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f12bca4:	44884000 */ 	mtc1	$t0,$f8
/*  f12bca8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f12bcac:	c424688c */ 	lwc1	$f4,0x688c($at)
/*  f12bcb0:	46001281 */ 	sub.s	$f10,$f2,$f0
/*  f12bcb4:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f12bcb8:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f12bcbc:	00000000 */ 	nop
/*  f12bcc0:	46046282 */ 	mul.s	$f10,$f12,$f4
/*  f12bcc4:	460a4183 */ 	div.s	$f6,$f8,$f10
/*  f12bcc8:	46060680 */ 	add.s	$f26,$f0,$f6
/*  f12bccc:	461a103c */ 	c.lt.s	$f2,$f26
/*  f12bcd0:	00000000 */ 	nop
/*  f12bcd4:	45000002 */ 	bc1f	.PF0f12bce0
/*  f12bcd8:	00000000 */ 	nop
/*  f12bcdc:	46001686 */ 	mov.s	$f26,$f2
.PF0f12bce0:
/*  f12bce0:	8fa9039c */ 	lw	$t1,0x39c($sp)
/*  f12bce4:	3c0140e0 */ 	lui	$at,0x40e0
/*  f12bce8:	44812000 */ 	mtc1	$at,$f4
/*  f12bcec:	c5280020 */ 	lwc1	$f8,0x20($t1)
/*  f12bcf0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f12bcf4:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f12bcf8:	c4246890 */ 	lwc1	$f4,0x6890($at)
/*  f12bcfc:	460a6180 */ 	add.s	$f6,$f12,$f10
/*  f12bd00:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f12bd04:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f12bd08:	440a5000 */ 	mfc1	$t2,$f10
/*  f12bd0c:	00000000 */ 	nop
/*  f12bd10:	0142082a */ 	slt	$at,$t2,$v0
/*  f12bd14:	54200261 */ 	bnezl	$at,.PF0f12c69c
/*  f12bd18:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f12bd1c:	86e20028 */ 	lh	$v0,0x28($s7)
/*  f12bd20:	2401ffff */ 	li	$at,-1
/*  f12bd24:	02e0b025 */ 	move	$s6,$s7
/*  f12bd28:	50410015 */ 	beql	$v0,$at,.PF0f12bd80
/*  f12bd2c:	2401ffff */ 	li	$at,-1
.PF0f12bd30:
/*  f12bd30:	0c004ad4 */ 	jal	random
/*  f12bd34:	00000000 */ 	nop
/*  f12bd38:	304b07ff */ 	andi	$t3,$v0,0x7ff
/*  f12bd3c:	2d6100f1 */ 	sltiu	$at,$t3,0xf1
/*  f12bd40:	10200008 */ 	beqz	$at,.PF0f12bd64
/*  f12bd44:	8fac039c */ 	lw	$t4,0x39c($sp)
/*  f12bd48:	c5860000 */ 	lwc1	$f6,0x0($t4)
/*  f12bd4c:	86c40028 */ 	lh	$a0,0x28($s6)
/*  f12bd50:	240600ff */ 	li	$a2,0xff
/*  f12bd54:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f12bd58:	44052000 */ 	mfc1	$a1,$f4
/*  f12bd5c:	0fc010e3 */ 	jal	roomAdjustLighting
/*  f12bd60:	00000000 */ 	nop
.PF0f12bd64:
/*  f12bd64:	86ce002a */ 	lh	$t6,0x2a($s6)
/*  f12bd68:	2401ffff */ 	li	$at,-1
/*  f12bd6c:	26d60002 */ 	addiu	$s6,$s6,0x2
/*  f12bd70:	15c1ffef */ 	bne	$t6,$at,.PF0f12bd30
/*  f12bd74:	00000000 */ 	nop
/*  f12bd78:	86e20028 */ 	lh	$v0,0x28($s7)
/*  f12bd7c:	2401ffff */ 	li	$at,-1
.PF0f12bd80:
/*  f12bd80:	10410049 */ 	beq	$v0,$at,.PF0f12bea8
/*  f12bd84:	02e0b025 */ 	move	$s6,$s7
/*  f12bd88:	86e20028 */ 	lh	$v0,0x28($s7)
/*  f12bd8c:	27b50158 */ 	addiu	$s5,$sp,0x158
/*  f12bd90:	27b4014c */ 	addiu	$s4,$sp,0x14c
/*  f12bd94:	27b30164 */ 	addiu	$s3,$sp,0x164
.PF0f12bd98:
/*  f12bd98:	1040003e */ 	beqz	$v0,.PF0f12be94
/*  f12bd9c:	00408825 */ 	move	$s1,$v0
/*  f12bda0:	0002c8c0 */ 	sll	$t9,$v0,0x3
/*  f12bda4:	0322c821 */ 	addu	$t9,$t9,$v0
/*  f12bda8:	3c09800a */ 	lui	$t1,0x800a
/*  f12bdac:	8d295264 */ 	lw	$t1,0x5264($t1)
/*  f12bdb0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12bdb4:	3c18800a */ 	lui	$t8,0x800a
/*  f12bdb8:	00027880 */ 	sll	$t7,$v0,0x2
/*  f12bdbc:	8f184ec8 */ 	lw	$t8,0x4ec8($t8)
/*  f12bdc0:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f12bdc4:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f12bdc8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f12bdcc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12bdd0:	012f1021 */ 	addu	$v0,$t1,$t7
/*  f12bdd4:	03194021 */ 	addu	$t0,$t8,$t9
/*  f12bdd8:	81120008 */ 	lb	$s2,0x8($t0)
/*  f12bddc:	c6f40008 */ 	lwc1	$f20,0x8($s7)
/*  f12bde0:	c6f6000c */ 	lwc1	$f22,0xc($s7)
/*  f12bde4:	c6f80010 */ 	lwc1	$f24,0x10($s7)
/*  f12bde8:	c4480004 */ 	lwc1	$f8,0x4($v0)
/*  f12bdec:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f12bdf0:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f12bdf4:	00008025 */ 	move	$s0,$zero
/*  f12bdf8:	4608a501 */ 	sub.s	$f20,$f20,$f8
/*  f12bdfc:	460ab581 */ 	sub.s	$f22,$f22,$f10
/*  f12be00:	1a400024 */ 	blez	$s2,.PF0f12be94
/*  f12be04:	4606c601 */ 	sub.s	$f24,$f24,$f6
/*  f12be08:	02202025 */ 	move	$a0,$s1
.PF0f12be0c:
/*  f12be0c:	0fc003d4 */ 	jal	lightIsHealthy
/*  f12be10:	02002825 */ 	move	$a1,$s0
/*  f12be14:	1040001c */ 	beqz	$v0,.PF0f12be88
/*  f12be18:	02202025 */ 	move	$a0,$s1
/*  f12be1c:	0fc003e5 */ 	jal	lightIsVulnerable
/*  f12be20:	02002825 */ 	move	$a1,$s0
/*  f12be24:	10400018 */ 	beqz	$v0,.PF0f12be88
/*  f12be28:	02202025 */ 	move	$a0,$s1
/*  f12be2c:	02002825 */ 	move	$a1,$s0
/*  f12be30:	0fc0037f */ 	jal	lightGetBboxCentre
/*  f12be34:	02603025 */ 	move	$a2,$s3
/*  f12be38:	10400013 */ 	beqz	$v0,.PF0f12be88
/*  f12be3c:	c7a40164 */ 	lwc1	$f4,0x164($sp)
/*  f12be40:	46142201 */ 	sub.s	$f8,$f4,$f20
/*  f12be44:	c7a4016c */ 	lwc1	$f4,0x16c($sp)
/*  f12be48:	c7aa0168 */ 	lwc1	$f10,0x168($sp)
/*  f12be4c:	e7ba0158 */ 	swc1	$f26,0x158($sp)
/*  f12be50:	e7a8014c */ 	swc1	$f8,0x14c($sp)
/*  f12be54:	46182201 */ 	sub.s	$f8,$f4,$f24
/*  f12be58:	e7ba015c */ 	swc1	$f26,0x15c($sp)
/*  f12be5c:	e7ba0160 */ 	swc1	$f26,0x160($sp)
/*  f12be60:	46165181 */ 	sub.s	$f6,$f10,$f22
/*  f12be64:	e7a80154 */ 	swc1	$f8,0x154($sp)
/*  f12be68:	02802025 */ 	move	$a0,$s4
/*  f12be6c:	02a02825 */ 	move	$a1,$s5
/*  f12be70:	0fc5e0fe */ 	jal	func0f1773c8
/*  f12be74:	e7a60150 */ 	swc1	$f6,0x150($sp)
/*  f12be78:	10400003 */ 	beqz	$v0,.PF0f12be88
/*  f12be7c:	02202025 */ 	move	$a0,$s1
/*  f12be80:	0fc006de */ 	jal	roomSetLightBroken
/*  f12be84:	02002825 */ 	move	$a1,$s0
.PF0f12be88:
/*  f12be88:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f12be8c:	5612ffdf */ 	bnel	$s0,$s2,.PF0f12be0c
/*  f12be90:	02202025 */ 	move	$a0,$s1
.PF0f12be94:
/*  f12be94:	86c2002a */ 	lh	$v0,0x2a($s6)
/*  f12be98:	2401ffff */ 	li	$at,-1
/*  f12be9c:	26d60002 */ 	addiu	$s6,$s6,0x2
/*  f12bea0:	1441ffbd */ 	bne	$v0,$at,.PF0f12bd98
/*  f12bea4:	00000000 */ 	nop
.PF0f12bea8:
/*  f12bea8:	27b00198 */ 	addiu	$s0,$sp,0x198
/*  f12beac:	02002825 */ 	move	$a1,$s0
/*  f12beb0:	26e40028 */ 	addiu	$a0,$s7,0x28
/*  f12beb4:	0fc19884 */ 	jal	roomGetProps
/*  f12beb8:	24060100 */ 	li	$a2,0x100
/*  f12bebc:	87aa0198 */ 	lh	$t2,0x198($sp)
/*  f12bec0:	0200a025 */ 	move	$s4,$s0
/*  f12bec4:	27ab0198 */ 	addiu	$t3,$sp,0x198
/*  f12bec8:	054001f3 */ 	bltz	$t2,.PF0f12c698
/*  f12becc:	3c013f80 */ 	lui	$at,0x3f80
/*  f12bed0:	4481f000 */ 	mtc1	$at,$f30
/*  f12bed4:	85620000 */ 	lh	$v0,0x0($t3)
/*  f12bed8:	24160004 */ 	li	$s6,0x4
/*  f12bedc:	24150003 */ 	li	$s5,0x3
/*  f12bee0:	8fae03a0 */ 	lw	$t6,0x3a0($sp)
.PF0f12bee4:
/*  f12bee4:	8fcd0338 */ 	lw	$t5,0x338($s8)
/*  f12bee8:	000260c0 */ 	sll	$t4,$v0,0x3
/*  f12beec:	8dd80004 */ 	lw	$t8,0x4($t6)
/*  f12bef0:	01826021 */ 	addu	$t4,$t4,$v0
/*  f12bef4:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f12bef8:	018d8021 */ 	addu	$s0,$t4,$t5
/*  f12befc:	521801e3 */ 	beql	$s0,$t8,.PF0f12c68c
/*  f12bf00:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12bf04:	86190002 */ 	lh	$t9,0x2($s0)
/*  f12bf08:	572001e0 */ 	bnezl	$t9,.PF0f12c68c
/*  f12bf0c:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12bf10:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f12bf14:	24010001 */ 	li	$at,0x1
/*  f12bf18:	50410006 */ 	beql	$v0,$at,.PF0f12bf34
/*  f12bf1c:	8e110004 */ 	lw	$s1,0x4($s0)
/*  f12bf20:	12c20003 */ 	beq	$s6,$v0,.PF0f12bf30
/*  f12bf24:	24010002 */ 	li	$at,0x2
/*  f12bf28:	14410105 */ 	bne	$v0,$at,.PF0f12c340
/*  f12bf2c:	00000000 */ 	nop
.PF0f12bf30:
/*  f12bf30:	8e110004 */ 	lw	$s1,0x4($s0)
.PF0f12bf34:
/*  f12bf34:	c6120008 */ 	lwc1	$f18,0x8($s0)
/*  f12bf38:	c6f00008 */ 	lwc1	$f16,0x8($s7)
/*  f12bf3c:	c60e000c */ 	lwc1	$f14,0xc($s0)
/*  f12bf40:	c6ec000c */ 	lwc1	$f12,0xc($s7)
/*  f12bf44:	46109501 */ 	sub.s	$f20,$f18,$f16
/*  f12bf48:	c6100010 */ 	lwc1	$f16,0x10($s0)
/*  f12bf4c:	c6f20010 */ 	lwc1	$f18,0x10($s7)
/*  f12bf50:	460c7581 */ 	sub.s	$f22,$f14,$f12
/*  f12bf54:	00009025 */ 	move	$s2,$zero
/*  f12bf58:	122001cb */ 	beqz	$s1,.PF0f12c688
/*  f12bf5c:	46128601 */ 	sub.s	$f24,$f16,$f18
/*  f12bf60:	461aa03e */ 	c.le.s	$f20,$f26
/*  f12bf64:	00000000 */ 	nop
/*  f12bf68:	45000024 */ 	bc1f	.PF0f12bffc
/*  f12bf6c:	00000000 */ 	nop
/*  f12bf70:	4600d007 */ 	neg.s	$f0,$f26
/*  f12bf74:	4614003e */ 	c.le.s	$f0,$f20
/*  f12bf78:	00000000 */ 	nop
/*  f12bf7c:	4500001f */ 	bc1f	.PF0f12bffc
/*  f12bf80:	00000000 */ 	nop
/*  f12bf84:	461ab03e */ 	c.le.s	$f22,$f26
/*  f12bf88:	00000000 */ 	nop
/*  f12bf8c:	4500001b */ 	bc1f	.PF0f12bffc
/*  f12bf90:	00000000 */ 	nop
/*  f12bf94:	4616003e */ 	c.le.s	$f0,$f22
/*  f12bf98:	00000000 */ 	nop
/*  f12bf9c:	45000017 */ 	bc1f	.PF0f12bffc
/*  f12bfa0:	00000000 */ 	nop
/*  f12bfa4:	461ac03e */ 	c.le.s	$f24,$f26
/*  f12bfa8:	00000000 */ 	nop
/*  f12bfac:	45000013 */ 	bc1f	.PF0f12bffc
/*  f12bfb0:	00000000 */ 	nop
/*  f12bfb4:	4618003e */ 	c.le.s	$f0,$f24
/*  f12bfb8:	02202025 */ 	move	$a0,$s1
/*  f12bfbc:	27a50130 */ 	addiu	$a1,$sp,0x130
/*  f12bfc0:	4500000e */ 	bc1f	.PF0f12bffc
/*  f12bfc4:	00000000 */ 	nop
/*  f12bfc8:	0fc24881 */ 	jal	func0f092304
/*  f12bfcc:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f12bfd0:	10400009 */ 	beqz	$v0,.PF0f12bff8
/*  f12bfd4:	8fa403a0 */ 	lw	$a0,0x3a0($sp)
/*  f12bfd8:	02002825 */ 	move	$a1,$s0
/*  f12bfdc:	27a60130 */ 	addiu	$a2,$sp,0x130
/*  f12bfe0:	0fc4ae91 */ 	jal	func0f12af5c
/*  f12bfe4:	27a70124 */ 	addiu	$a3,$sp,0x124
/*  f12bfe8:	10400004 */ 	beqz	$v0,.PF0f12bffc
/*  f12bfec:	00000000 */ 	nop
/*  f12bff0:	10000002 */ 	b	.PF0f12bffc
/*  f12bff4:	24120001 */ 	li	$s2,0x1
.PF0f12bff8:
/*  f12bff8:	24120001 */ 	li	$s2,0x1
.PF0f12bffc:
/*  f12bffc:	1240000c */ 	beqz	$s2,.PF0f12c030
/*  f12c000:	00000000 */ 	nop
/*  f12c004:	92080000 */ 	lbu	$t0,0x0($s0)
/*  f12c008:	16c80009 */ 	bne	$s6,$t0,.PF0f12c030
/*  f12c00c:	00000000 */ 	nop
/*  f12c010:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f12c014:	10400006 */ 	beqz	$v0,.PF0f12c030
/*  f12c018:	00000000 */ 	nop
/*  f12c01c:	9049005c */ 	lbu	$t1,0x5c($v0)
/*  f12c020:	24010058 */ 	li	$at,0x58
/*  f12c024:	15210002 */ 	bne	$t1,$at,.PF0f12c030
/*  f12c028:	00000000 */ 	nop
/*  f12c02c:	a4400062 */ 	sh	$zero,0x62($v0)
.PF0f12c030:
/*  f12c030:	12400195 */ 	beqz	$s2,.PF0f12c688
/*  f12c034:	3c017f1b */ 	lui	$at,0x7f1b
/*  f12c038:	461aa003 */ 	div.s	$f0,$f20,$f26
/*  f12c03c:	8faf039c */ 	lw	$t7,0x39c($sp)
/*  f12c040:	8fc3029c */ 	lw	$v1,0x29c($s8)
/*  f12c044:	8faa03a0 */ 	lw	$t2,0x3a0($sp)
/*  f12c048:	8fae0194 */ 	lw	$t6,0x194($sp)
/*  f12c04c:	c5f00028 */ 	lwc1	$f16,0x28($t7)
/*  f12c050:	461c003c */ 	c.lt.s	$f0,$f28
/*  f12c054:	46000086 */ 	mov.s	$f2,$f0
/*  f12c058:	45020003 */ 	bc1fl	.PF0f12c068
/*  f12c05c:	461ab003 */ 	div.s	$f0,$f22,$f26
/*  f12c060:	46000087 */ 	neg.s	$f2,$f0
/*  f12c064:	461ab003 */ 	div.s	$f0,$f22,$f26
.PF0f12c068:
/*  f12c068:	4602f081 */ 	sub.s	$f2,$f30,$f2
/*  f12c06c:	461c003c */ 	c.lt.s	$f0,$f28
/*  f12c070:	46000306 */ 	mov.s	$f12,$f0
/*  f12c074:	45020003 */ 	bc1fl	.PF0f12c084
/*  f12c078:	461ac003 */ 	div.s	$f0,$f24,$f26
/*  f12c07c:	46000307 */ 	neg.s	$f12,$f0
/*  f12c080:	461ac003 */ 	div.s	$f0,$f24,$f26
.PF0f12c084:
/*  f12c084:	460cf301 */ 	sub.s	$f12,$f30,$f12
/*  f12c088:	461c003c */ 	c.lt.s	$f0,$f28
/*  f12c08c:	46000386 */ 	mov.s	$f14,$f0
/*  f12c090:	45020003 */ 	bc1fl	.PF0f12c0a0
/*  f12c094:	4602603c */ 	c.lt.s	$f12,$f2
/*  f12c098:	46000387 */ 	neg.s	$f14,$f0
/*  f12c09c:	4602603c */ 	c.lt.s	$f12,$f2
.PF0f12c0a0:
/*  f12c0a0:	46001506 */ 	mov.s	$f20,$f2
/*  f12c0a4:	460ef381 */ 	sub.s	$f14,$f30,$f14
/*  f12c0a8:	45020003 */ 	bc1fl	.PF0f12c0b8
/*  f12c0ac:	4614703c */ 	c.lt.s	$f14,$f20
/*  f12c0b0:	46006506 */ 	mov.s	$f20,$f12
/*  f12c0b4:	4614703c */ 	c.lt.s	$f14,$f20
.PF0f12c0b8:
/*  f12c0b8:	00000000 */ 	nop
/*  f12c0bc:	45000002 */ 	bc1f	.PF0f12c0c8
/*  f12c0c0:	00000000 */ 	nop
/*  f12c0c4:	46007506 */ 	mov.s	$f20,$f14
.PF0f12c0c8:
/*  f12c0c8:	c4246894 */ 	lwc1	$f4,0x6894($at)
/*  f12c0cc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f12c0d0:	c42a6898 */ 	lwc1	$f10,0x6898($at)
/*  f12c0d4:	4604a202 */ 	mul.s	$f8,$f20,$f4
/*  f12c0d8:	460a4180 */ 	add.s	$f6,$f8,$f10
/*  f12c0dc:	46103502 */ 	mul.s	$f20,$f6,$f16
/*  f12c0e0:	04600008 */ 	bltz	$v1,.PF0f12c104
/*  f12c0e4:	00000000 */ 	nop
/*  f12c0e8:	814b03ce */ 	lb	$t3,0x3ce($t2)
/*  f12c0ec:	146b0005 */ 	bne	$v1,$t3,.PF0f12c104
/*  f12c0f0:	00000000 */ 	nop
/*  f12c0f4:	8e2c000c */ 	lw	$t4,0xc($s1)
/*  f12c0f8:	318d0001 */ 	andi	$t5,$t4,0x1
/*  f12c0fc:	55a00163 */ 	bnezl	$t5,.PF0f12c68c
/*  f12c100:	86820002 */ 	lh	$v0,0x2($s4)
.PF0f12c104:
/*  f12c104:	11c00060 */ 	beqz	$t6,.PF0f12c288
/*  f12c108:	02202025 */ 	move	$a0,$s1
/*  f12c10c:	0fc19a57 */ 	jal	objUpdateLinkedScenery
/*  f12c110:	02e02825 */ 	move	$a1,$s7
/*  f12c114:	8e220040 */ 	lw	$v0,0x40($s1)
/*  f12c118:	30581000 */ 	andi	$t8,$v0,0x1000
/*  f12c11c:	57000023 */ 	bnezl	$t8,.PF0f12c1ac
/*  f12c120:	00025140 */ 	sll	$t2,$v0,0x5
/*  f12c124:	8e39000c */ 	lw	$t9,0xc($s1)
/*  f12c128:	3c010020 */ 	lui	$at,0x20
/*  f12c12c:	34210400 */ 	ori	$at,$at,0x400
/*  f12c130:	03214024 */ 	and	$t0,$t9,$at
/*  f12c134:	5500001d */ 	bnezl	$t0,.PF0f12c1ac
/*  f12c138:	00025140 */ 	sll	$t2,$v0,0x5
/*  f12c13c:	0c004ad4 */ 	jal	random
/*  f12c140:	00000000 */ 	nop
/*  f12c144:	44822000 */ 	mtc1	$v0,$f4
/*  f12c148:	02002025 */ 	move	$a0,$s0
/*  f12c14c:	04410005 */ 	bgez	$v0,.PF0f12c164
/*  f12c150:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f12c154:	3c014f80 */ 	lui	$at,0x4f80
/*  f12c158:	44815000 */ 	mtc1	$at,$f10
/*  f12c15c:	00000000 */ 	nop
/*  f12c160:	460a4200 */ 	add.s	$f8,$f8,$f10
.PF0f12c164:
/*  f12c164:	3c012f80 */ 	lui	$at,0x2f80
/*  f12c168:	44813000 */ 	mtc1	$at,$f6
/*  f12c16c:	3c013f00 */ 	lui	$at,0x3f00
/*  f12c170:	44815000 */ 	mtc1	$at,$f10
/*  f12c174:	46064102 */ 	mul.s	$f4,$f8,$f6
/*  f12c178:	8fa903a0 */ 	lw	$t1,0x3a0($sp)
/*  f12c17c:	26060008 */ 	addiu	$a2,$s0,0x8
/*  f12c180:	24070022 */ 	li	$a3,0x22
/*  f12c184:	812f03ce */ 	lb	$t7,0x3ce($t1)
/*  f12c188:	460a2202 */ 	mul.s	$f8,$f4,$f10
/*  f12c18c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f12c190:	461e4180 */ 	add.s	$f6,$f8,$f30
/*  f12c194:	46143102 */ 	mul.s	$f4,$f6,$f20
/*  f12c198:	44052000 */ 	mfc1	$a1,$f4
/*  f12c19c:	0fc214a8 */ 	jal	func0f085050
/*  f12c1a0:	00000000 */ 	nop
/*  f12c1a4:	8e220040 */ 	lw	$v0,0x40($s1)
/*  f12c1a8:	00025140 */ 	sll	$t2,$v0,0x5
.PF0f12c1ac:
/*  f12c1ac:	05400136 */ 	bltz	$t2,.PF0f12c688
/*  f12c1b0:	00025900 */ 	sll	$t3,$v0,0x4
/*  f12c1b4:	05620135 */ 	bltzl	$t3,.PF0f12c68c
/*  f12c1b8:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12c1bc:	8e2c0010 */ 	lw	$t4,0x10($s1)
/*  f12c1c0:	318d0001 */ 	andi	$t5,$t4,0x1
/*  f12c1c4:	51a00131 */ 	beqzl	$t5,.PF0f12c68c
/*  f12c1c8:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12c1cc:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f12c1d0:	c6e80008 */ 	lwc1	$f8,0x8($s7)
/*  f12c1d4:	e7bc00f8 */ 	swc1	$f28,0xf8($sp)
/*  f12c1d8:	46085181 */ 	sub.s	$f6,$f10,$f8
/*  f12c1dc:	e7a600f4 */ 	swc1	$f6,0xf4($sp)
/*  f12c1e0:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
/*  f12c1e4:	c6ea0010 */ 	lwc1	$f10,0x10($s7)
/*  f12c1e8:	c6040010 */ 	lwc1	$f4,0x10($s0)
/*  f12c1ec:	4606e032 */ 	c.eq.s	$f28,$f6
/*  f12c1f0:	460a2201 */ 	sub.s	$f8,$f4,$f10
/*  f12c1f4:	45000006 */ 	bc1f	.PF0f12c210
/*  f12c1f8:	e7a800fc */ 	swc1	$f8,0xfc($sp)
/*  f12c1fc:	c7a400fc */ 	lwc1	$f4,0xfc($sp)
/*  f12c200:	4604e032 */ 	c.eq.s	$f28,$f4
/*  f12c204:	00000000 */ 	nop
/*  f12c208:	45030017 */ 	bc1tl	.PF0f12c268
/*  f12c20c:	4406e000 */ 	mfc1	$a2,$f28
.PF0f12c210:
/*  f12c210:	c7aa00fc */ 	lwc1	$f10,0xfc($sp)
/*  f12c214:	c7ae00f4 */ 	lwc1	$f14,0xf4($sp)
/*  f12c218:	460a5202 */ 	mul.s	$f8,$f10,$f10
/*  f12c21c:	00000000 */ 	nop
/*  f12c220:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f12c224:	0c0127b4 */ 	jal	sqrtf
/*  f12c228:	46064300 */ 	add.s	$f12,$f8,$f6
/*  f12c22c:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f12c230:	3c014080 */ 	lui	$at,0x4080
/*  f12c234:	4502000c */ 	bc1fl	.PF0f12c268
/*  f12c238:	4406e000 */ 	mfc1	$a2,$f28
/*  f12c23c:	44812000 */ 	mtc1	$at,$f4
/*  f12c240:	c7ae00f4 */ 	lwc1	$f14,0xf4($sp)
/*  f12c244:	c7a800fc */ 	lwc1	$f8,0xfc($sp)
/*  f12c248:	4604a282 */ 	mul.s	$f10,$f20,$f4
/*  f12c24c:	46005083 */ 	div.s	$f2,$f10,$f0
/*  f12c250:	46027382 */ 	mul.s	$f14,$f14,$f2
/*  f12c254:	00000000 */ 	nop
/*  f12c258:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f12c25c:	e7ae00f4 */ 	swc1	$f14,0xf4($sp)
/*  f12c260:	e7a600fc */ 	swc1	$f6,0xfc($sp)
/*  f12c264:	4406e000 */ 	mfc1	$a2,$f28
.PF0f12c268:
/*  f12c268:	240e0001 */ 	li	$t6,0x1
/*  f12c26c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f12c270:	02202025 */ 	move	$a0,$s1
/*  f12c274:	27a500f4 */ 	addiu	$a1,$sp,0xf4
/*  f12c278:	0fc20b1b */ 	jal	func0f082a1c
/*  f12c27c:	24070001 */ 	li	$a3,0x1
/*  f12c280:	10000102 */ 	b	.PF0f12c68c
/*  f12c284:	86820002 */ 	lh	$v0,0x2($s4)
.PF0f12c288:
/*  f12c288:	0fc21afe */ 	jal	objIsHealthy
/*  f12c28c:	02202025 */ 	move	$a0,$s1
/*  f12c290:	104000fd */ 	beqz	$v0,.PF0f12c688
/*  f12c294:	3c017f1b */ 	lui	$at,0x7f1b
/*  f12c298:	c424689c */ 	lwc1	$f4,0x689c($at)
/*  f12c29c:	c7ca004c */ 	lwc1	$f10,0x4c($s8)
/*  f12c2a0:	8e380040 */ 	lw	$t8,0x40($s1)
/*  f12c2a4:	460a2202 */ 	mul.s	$f8,$f4,$f10
/*  f12c2a8:	33191000 */ 	andi	$t9,$t8,0x1000
/*  f12c2ac:	4608a502 */ 	mul.s	$f20,$f20,$f8
/*  f12c2b0:	572000f6 */ 	bnezl	$t9,.PF0f12c68c
/*  f12c2b4:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12c2b8:	8e28000c */ 	lw	$t0,0xc($s1)
/*  f12c2bc:	3c010020 */ 	lui	$at,0x20
/*  f12c2c0:	34210400 */ 	ori	$at,$at,0x400
/*  f12c2c4:	01014824 */ 	and	$t1,$t0,$at
/*  f12c2c8:	552000f0 */ 	bnezl	$t1,.PF0f12c68c
/*  f12c2cc:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12c2d0:	0c004ad4 */ 	jal	random
/*  f12c2d4:	00000000 */ 	nop
/*  f12c2d8:	44823000 */ 	mtc1	$v0,$f6
/*  f12c2dc:	02002025 */ 	move	$a0,$s0
/*  f12c2e0:	04410005 */ 	bgez	$v0,.PF0f12c2f8
/*  f12c2e4:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f12c2e8:	3c014f80 */ 	lui	$at,0x4f80
/*  f12c2ec:	44815000 */ 	mtc1	$at,$f10
/*  f12c2f0:	00000000 */ 	nop
/*  f12c2f4:	460a2100 */ 	add.s	$f4,$f4,$f10
.PF0f12c2f8:
/*  f12c2f8:	3c012f80 */ 	lui	$at,0x2f80
/*  f12c2fc:	44814000 */ 	mtc1	$at,$f8
/*  f12c300:	3c013f00 */ 	lui	$at,0x3f00
/*  f12c304:	44815000 */ 	mtc1	$at,$f10
/*  f12c308:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f12c30c:	8faf03a0 */ 	lw	$t7,0x3a0($sp)
/*  f12c310:	26060008 */ 	addiu	$a2,$s0,0x8
/*  f12c314:	24070022 */ 	li	$a3,0x22
/*  f12c318:	81ea03ce */ 	lb	$t2,0x3ce($t7)
/*  f12c31c:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f12c320:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f12c324:	461e2200 */ 	add.s	$f8,$f4,$f30
/*  f12c328:	46144182 */ 	mul.s	$f6,$f8,$f20
/*  f12c32c:	44053000 */ 	mfc1	$a1,$f6
/*  f12c330:	0fc214a8 */ 	jal	func0f085050
/*  f12c334:	00000000 */ 	nop
/*  f12c338:	100000d4 */ 	b	.PF0f12c68c
/*  f12c33c:	86820002 */ 	lh	$v0,0x2($s4)
.PF0f12c340:
/*  f12c340:	12a20003 */ 	beq	$s5,$v0,.PF0f12c350
/*  f12c344:	24010006 */ 	li	$at,0x6
/*  f12c348:	544100d0 */ 	bnel	$v0,$at,.PF0f12c68c
/*  f12c34c:	86820002 */ 	lh	$v0,0x2($s4)
.PF0f12c350:
/*  f12c350:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f12c354:	c6e40008 */ 	lwc1	$f4,0x8($s7)
/*  f12c358:	c608000c */ 	lwc1	$f8,0xc($s0)
/*  f12c35c:	c6e6000c */ 	lwc1	$f6,0xc($s7)
/*  f12c360:	46045581 */ 	sub.s	$f22,$f10,$f4
/*  f12c364:	c6e40010 */ 	lwc1	$f4,0x10($s7)
/*  f12c368:	c60a0010 */ 	lwc1	$f10,0x10($s0)
/*  f12c36c:	00008825 */ 	move	$s1,$zero
/*  f12c370:	461ab03e */ 	c.le.s	$f22,$f26
/*  f12c374:	46064501 */ 	sub.s	$f20,$f8,$f6
/*  f12c378:	4500003d */ 	bc1f	.PF0f12c470
/*  f12c37c:	46045601 */ 	sub.s	$f24,$f10,$f4
/*  f12c380:	4600d007 */ 	neg.s	$f0,$f26
/*  f12c384:	4616003e */ 	c.le.s	$f0,$f22
/*  f12c388:	00000000 */ 	nop
/*  f12c38c:	45000038 */ 	bc1f	.PF0f12c470
/*  f12c390:	00000000 */ 	nop
/*  f12c394:	461aa03e */ 	c.le.s	$f20,$f26
/*  f12c398:	00000000 */ 	nop
/*  f12c39c:	45000034 */ 	bc1f	.PF0f12c470
/*  f12c3a0:	00000000 */ 	nop
/*  f12c3a4:	4614003e */ 	c.le.s	$f0,$f20
/*  f12c3a8:	00000000 */ 	nop
/*  f12c3ac:	45000030 */ 	bc1f	.PF0f12c470
/*  f12c3b0:	00000000 */ 	nop
/*  f12c3b4:	461ac03e */ 	c.le.s	$f24,$f26
/*  f12c3b8:	00000000 */ 	nop
/*  f12c3bc:	4500002c */ 	bc1f	.PF0f12c470
/*  f12c3c0:	00000000 */ 	nop
/*  f12c3c4:	4618003e */ 	c.le.s	$f0,$f24
/*  f12c3c8:	02002025 */ 	move	$a0,$s0
/*  f12c3cc:	27a500e0 */ 	addiu	$a1,$sp,0xe0
/*  f12c3d0:	27a600dc */ 	addiu	$a2,$sp,0xdc
/*  f12c3d4:	45000026 */ 	bc1f	.PF0f12c470
/*  f12c3d8:	00000000 */ 	nop
/*  f12c3dc:	0fc19925 */ 	jal	propGetBbox
/*  f12c3e0:	27a700d8 */ 	addiu	$a3,$sp,0xd8
/*  f12c3e4:	3c0141a0 */ 	lui	$at,0x41a0
/*  f12c3e8:	c7a000e0 */ 	lwc1	$f0,0xe0($sp)
/*  f12c3ec:	44814000 */ 	mtc1	$at,$f8
/*  f12c3f0:	00000000 */ 	nop
/*  f12c3f4:	46080001 */ 	sub.s	$f0,$f0,$f8
/*  f12c3f8:	461c003e */ 	c.le.s	$f0,$f28
/*  f12c3fc:	e7a000e0 */ 	swc1	$f0,0xe0($sp)
/*  f12c400:	45020003 */ 	bc1fl	.PF0f12c410
/*  f12c404:	c6060008 */ 	lwc1	$f6,0x8($s0)
/*  f12c408:	e7bc00e0 */ 	swc1	$f28,0xe0($sp)
/*  f12c40c:	c6060008 */ 	lwc1	$f6,0x8($s0)
.PF0f12c410:
/*  f12c410:	c7aa00e0 */ 	lwc1	$f10,0xe0($sp)
/*  f12c414:	c7a800d8 */ 	lwc1	$f8,0xd8($sp)
/*  f12c418:	8fa403a0 */ 	lw	$a0,0x3a0($sp)
/*  f12c41c:	460a3101 */ 	sub.s	$f4,$f6,$f10
/*  f12c420:	e7a800d0 */ 	swc1	$f8,0xd0($sp)
/*  f12c424:	02002825 */ 	move	$a1,$s0
/*  f12c428:	27a600cc */ 	addiu	$a2,$sp,0xcc
/*  f12c42c:	e7a400cc */ 	swc1	$f4,0xcc($sp)
/*  f12c430:	c6060010 */ 	lwc1	$f6,0x10($s0)
/*  f12c434:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f12c438:	460a3101 */ 	sub.s	$f4,$f6,$f10
/*  f12c43c:	e7a400d4 */ 	swc1	$f4,0xd4($sp)
/*  f12c440:	c6080008 */ 	lwc1	$f8,0x8($s0)
/*  f12c444:	c7a400dc */ 	lwc1	$f4,0xdc($sp)
/*  f12c448:	460a4180 */ 	add.s	$f6,$f8,$f10
/*  f12c44c:	e7a400c4 */ 	swc1	$f4,0xc4($sp)
/*  f12c450:	e7a600c0 */ 	swc1	$f6,0xc0($sp)
/*  f12c454:	c6080010 */ 	lwc1	$f8,0x10($s0)
/*  f12c458:	460a4180 */ 	add.s	$f6,$f8,$f10
/*  f12c45c:	0fc4ae91 */ 	jal	func0f12af5c
/*  f12c460:	e7a600c8 */ 	swc1	$f6,0xc8($sp)
/*  f12c464:	10400002 */ 	beqz	$v0,.PF0f12c470
/*  f12c468:	00000000 */ 	nop
/*  f12c46c:	24110001 */ 	li	$s1,0x1
.PF0f12c470:
/*  f12c470:	52200086 */ 	beqzl	$s1,.PF0f12c68c
/*  f12c474:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12c478:	461ab083 */ 	div.s	$f2,$f22,$f26
/*  f12c47c:	3c0c8008 */ 	lui	$t4,0x8008
/*  f12c480:	258cee00 */ 	addiu	$t4,$t4,-4608
/*  f12c484:	8d810000 */ 	lw	$at,0x0($t4)
/*  f12c488:	27ab00a0 */ 	addiu	$t3,$sp,0xa0
/*  f12c48c:	8d8e0004 */ 	lw	$t6,0x4($t4)
/*  f12c490:	ad610000 */ 	sw	$at,0x0($t3)
/*  f12c494:	8d810008 */ 	lw	$at,0x8($t4)
/*  f12c498:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f12c49c:	00008825 */ 	move	$s1,$zero
/*  f12c4a0:	ad610008 */ 	sw	$at,0x8($t3)
/*  f12c4a4:	8e120004 */ 	lw	$s2,0x4($s0)
/*  f12c4a8:	26f30008 */ 	addiu	$s3,$s7,0x8
/*  f12c4ac:	461aa383 */ 	div.s	$f14,$f20,$f26
/*  f12c4b0:	46001006 */ 	mov.s	$f0,$f2
/*  f12c4b4:	461c103c */ 	c.lt.s	$f2,$f28
/*  f12c4b8:	461ac483 */ 	div.s	$f18,$f24,$f26
/*  f12c4bc:	46007306 */ 	mov.s	$f12,$f14
/*  f12c4c0:	45000002 */ 	bc1f	.PF0f12c4cc
/*  f12c4c4:	46009406 */ 	mov.s	$f16,$f18
/*  f12c4c8:	46001007 */ 	neg.s	$f0,$f2
.PF0f12c4cc:
/*  f12c4cc:	461c703c */ 	c.lt.s	$f14,$f28
/*  f12c4d0:	4600f501 */ 	sub.s	$f20,$f30,$f0
/*  f12c4d4:	45020003 */ 	bc1fl	.PF0f12c4e4
/*  f12c4d8:	461c903c */ 	c.lt.s	$f18,$f28
/*  f12c4dc:	46007307 */ 	neg.s	$f12,$f14
/*  f12c4e0:	461c903c */ 	c.lt.s	$f18,$f28
.PF0f12c4e4:
/*  f12c4e4:	460cf301 */ 	sub.s	$f12,$f30,$f12
/*  f12c4e8:	45020003 */ 	bc1fl	.PF0f12c4f8
/*  f12c4ec:	4614603c */ 	c.lt.s	$f12,$f20
/*  f12c4f0:	46009407 */ 	neg.s	$f16,$f18
/*  f12c4f4:	4614603c */ 	c.lt.s	$f12,$f20
.PF0f12c4f8:
/*  f12c4f8:	4610f401 */ 	sub.s	$f16,$f30,$f16
/*  f12c4fc:	45020003 */ 	bc1fl	.PF0f12c50c
/*  f12c500:	4614803c */ 	c.lt.s	$f16,$f20
/*  f12c504:	46006506 */ 	mov.s	$f20,$f12
/*  f12c508:	4614803c */ 	c.lt.s	$f16,$f20
.PF0f12c50c:
/*  f12c50c:	00000000 */ 	nop
/*  f12c510:	45000002 */ 	bc1f	.PF0f12c51c
/*  f12c514:	00000000 */ 	nop
/*  f12c518:	46008506 */ 	mov.s	$f20,$f16
.PF0f12c51c:
/*  f12c51c:	4614a502 */ 	mul.s	$f20,$f20,$f20
/*  f12c520:	8fb8039c */ 	lw	$t8,0x39c($sp)
/*  f12c524:	3c014100 */ 	lui	$at,0x4100
/*  f12c528:	44815000 */ 	mtc1	$at,$f10
/*  f12c52c:	c7040028 */ 	lwc1	$f4,0x28($t8)
/*  f12c530:	8fb90194 */ 	lw	$t9,0x194($sp)
/*  f12c534:	3c017f1b */ 	lui	$at,0x7f1b
/*  f12c538:	46142202 */ 	mul.s	$f8,$f4,$f20
/*  f12c53c:	00000000 */ 	nop
/*  f12c540:	460a4502 */ 	mul.s	$f20,$f8,$f10
/*  f12c544:	1320001a */ 	beqz	$t9,.PF0f12c5b0
/*  f12c548:	00000000 */ 	nop
/*  f12c54c:	461cb032 */ 	c.eq.s	$f22,$f28
/*  f12c550:	00000000 */ 	nop
/*  f12c554:	45000005 */ 	bc1f	.PF0f12c56c
/*  f12c558:	00000000 */ 	nop
/*  f12c55c:	461cc032 */ 	c.eq.s	$f24,$f28
/*  f12c560:	00000000 */ 	nop
/*  f12c564:	45030019 */ 	bc1tl	.PF0f12c5cc
/*  f12c568:	8fc80318 */ 	lw	$t0,0x318($s8)
.PF0f12c56c:
/*  f12c56c:	4616b182 */ 	mul.s	$f6,$f22,$f22
/*  f12c570:	00000000 */ 	nop
/*  f12c574:	4618c102 */ 	mul.s	$f4,$f24,$f24
/*  f12c578:	0c0127b4 */ 	jal	sqrtf
/*  f12c57c:	46043300 */ 	add.s	$f12,$f6,$f4
/*  f12c580:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f12c584:	00000000 */ 	nop
/*  f12c588:	45020010 */ 	bc1fl	.PF0f12c5cc
/*  f12c58c:	8fc80318 */ 	lw	$t0,0x318($s8)
/*  f12c590:	4600f083 */ 	div.s	$f2,$f30,$f0
/*  f12c594:	e7bc00a4 */ 	swc1	$f28,0xa4($sp)
/*  f12c598:	4602b582 */ 	mul.s	$f22,$f22,$f2
/*  f12c59c:	00000000 */ 	nop
/*  f12c5a0:	4602c602 */ 	mul.s	$f24,$f24,$f2
/*  f12c5a4:	e7b600a0 */ 	swc1	$f22,0xa0($sp)
/*  f12c5a8:	10000007 */ 	b	.PF0f12c5c8
/*  f12c5ac:	e7b800a8 */ 	swc1	$f24,0xa8($sp)
.PF0f12c5b0:
/*  f12c5b0:	c42868a0 */ 	lwc1	$f8,0x68a0($at)
/*  f12c5b4:	c7ca004c */ 	lwc1	$f10,0x4c($s8)
/*  f12c5b8:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f12c5bc:	00000000 */ 	nop
/*  f12c5c0:	4606a502 */ 	mul.s	$f20,$f20,$f6
/*  f12c5c4:	00000000 */ 	nop
.PF0f12c5c8:
/*  f12c5c8:	8fc80318 */ 	lw	$t0,0x318($s8)
.PF0f12c5cc:
/*  f12c5cc:	8fa903a0 */ 	lw	$t1,0x3a0($sp)
/*  f12c5d0:	8faf03a0 */ 	lw	$t7,0x3a0($sp)
/*  f12c5d4:	51000008 */ 	beqzl	$t0,.PF0f12c5f8
/*  f12c5d8:	81e203ce */ 	lb	$v0,0x3ce($t7)
/*  f12c5dc:	0fc63843 */ 	jal	mpGetChrFromPlayerIndex
/*  f12c5e0:	812403ce */ 	lb	$a0,0x3ce($t1)
/*  f12c5e4:	5040001a */ 	beqzl	$v0,.PF0f12c650
/*  f12c5e8:	4405a000 */ 	mfc1	$a1,$f20
/*  f12c5ec:	10000017 */ 	b	.PF0f12c64c
/*  f12c5f0:	8c51001c */ 	lw	$s1,0x1c($v0)
/*  f12c5f4:	81e203ce */ 	lb	$v0,0x3ce($t7)
.PF0f12c5f8:
/*  f12c5f8:	8fca0294 */ 	lw	$t2,0x294($s8)
/*  f12c5fc:	55420005 */ 	bnel	$t2,$v0,.PF0f12c614
/*  f12c600:	8fc30298 */ 	lw	$v1,0x298($s8)
/*  f12c604:	8fcd02a0 */ 	lw	$t5,0x2a0($s8)
/*  f12c608:	10000010 */ 	b	.PF0f12c64c
/*  f12c60c:	8db100bc */ 	lw	$s1,0xbc($t5)
/*  f12c610:	8fc30298 */ 	lw	$v1,0x298($s8)
.PF0f12c614:
/*  f12c614:	04620007 */ 	bltzl	$v1,.PF0f12c634
/*  f12c618:	8fc3029c */ 	lw	$v1,0x29c($s8)
/*  f12c61c:	54620005 */ 	bnel	$v1,$v0,.PF0f12c634
/*  f12c620:	8fc3029c */ 	lw	$v1,0x29c($s8)
/*  f12c624:	8fcb02a4 */ 	lw	$t3,0x2a4($s8)
/*  f12c628:	10000008 */ 	b	.PF0f12c64c
/*  f12c62c:	8d7100bc */ 	lw	$s1,0xbc($t3)
/*  f12c630:	8fc3029c */ 	lw	$v1,0x29c($s8)
.PF0f12c634:
/*  f12c634:	04620006 */ 	bltzl	$v1,.PF0f12c650
/*  f12c638:	4405a000 */ 	mfc1	$a1,$f20
/*  f12c63c:	54620004 */ 	bnel	$v1,$v0,.PF0f12c650
/*  f12c640:	4405a000 */ 	mfc1	$a1,$f20
/*  f12c644:	8fcc02a8 */ 	lw	$t4,0x2a8($s8)
/*  f12c648:	8d9100bc */ 	lw	$s1,0xbc($t4)
.PF0f12c64c:
/*  f12c64c:	4405a000 */ 	mfc1	$a1,$f20
.PF0f12c650:
/*  f12c650:	02402025 */ 	move	$a0,$s2
/*  f12c654:	27a600a0 */ 	addiu	$a2,$sp,0xa0
/*  f12c658:	02203825 */ 	move	$a3,$s1
/*  f12c65c:	0fc0d15e */ 	jal	func0f034410
/*  f12c660:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f12c664:	920e0000 */ 	lbu	$t6,0x0($s0)
/*  f12c668:	8fb80194 */ 	lw	$t8,0x194($sp)
/*  f12c66c:	56ae0007 */ 	bnel	$s5,$t6,.PF0f12c68c
/*  f12c670:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12c674:	17000004 */ 	bnez	$t8,.PF0f12c688
/*  f12c678:	02402025 */ 	move	$a0,$s2
/*  f12c67c:	4406d000 */ 	mfc1	$a2,$f26
/*  f12c680:	0fc09c86 */ 	jal	func0f0270f4
/*  f12c684:	02602825 */ 	move	$a1,$s3
.PF0f12c688:
/*  f12c688:	86820002 */ 	lh	$v0,0x2($s4)
.PF0f12c68c:
/*  f12c68c:	26940002 */ 	addiu	$s4,$s4,0x2
/*  f12c690:	0443fe14 */ 	bgezl	$v0,.PF0f12bee4
/*  f12c694:	8fae03a0 */ 	lw	$t6,0x3a0($sp)
.PF0f12c698:
/*  f12c698:	8fbf0074 */ 	lw	$ra,0x74($sp)
.PF0f12c69c:
/*  f12c69c:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f12c6a0:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f12c6a4:	d7b80030 */ 	ldc1	$f24,0x30($sp)
/*  f12c6a8:	d7ba0038 */ 	ldc1	$f26,0x38($sp)
/*  f12c6ac:	d7bc0040 */ 	ldc1	$f28,0x40($sp)
/*  f12c6b0:	d7be0048 */ 	ldc1	$f30,0x48($sp)
/*  f12c6b4:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f12c6b8:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f12c6bc:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f12c6c0:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f12c6c4:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f12c6c8:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f12c6cc:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f12c6d0:	8fb7006c */ 	lw	$s7,0x6c($sp)
/*  f12c6d4:	8fbe0070 */ 	lw	$s8,0x70($sp)
/*  f12c6d8:	03e00008 */ 	jr	$ra
/*  f12c6dc:	27bd03a8 */ 	addiu	$sp,$sp,0x3a8
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f12b0e0
.late_rodata
glabel var7f1b5590
.word 0x3f333333
glabel var7f1b5594
.word 0x3e99999a
glabel var7f1b5598
.word 0x3d4ccccd
glabel var7f1b559c
.word 0x3d4ccccd
.text
/*  f12b0e0:	27bdfc58 */ 	addiu	$sp,$sp,-936
/*  f12b0e4:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f12b0e8:	afbe0070 */ 	sw	$s8,0x70($sp)
/*  f12b0ec:	afb7006c */ 	sw	$s7,0x6c($sp)
/*  f12b0f0:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f12b0f4:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f12b0f8:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f12b0fc:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f12b100:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f12b104:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f12b108:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f12b10c:	f7be0048 */ 	sdc1	$f30,0x48($sp)
/*  f12b110:	f7bc0040 */ 	sdc1	$f28,0x40($sp)
/*  f12b114:	f7ba0038 */ 	sdc1	$f26,0x38($sp)
/*  f12b118:	f7b80030 */ 	sdc1	$f24,0x30($sp)
/*  f12b11c:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f12b120:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f12b124:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*  f12b128:	3c088008 */ 	lui	$t0,%hi(g_ExplosionTypes)
/*  f12b12c:	2508e4b8 */ 	addiu	$t0,$t0,%lo(g_ExplosionTypes)
/*  f12b130:	afae03a0 */ 	sw	$t6,0x3a0($sp)
/*  f12b134:	81d803cc */ 	lb	$t8,0x3cc($t6)
/*  f12b138:	3c1e800a */ 	lui	$s8,%hi(g_Vars)
/*  f12b13c:	27de9fc0 */ 	addiu	$s8,$s8,%lo(g_Vars)
/*  f12b140:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f12b144:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f12b148:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12b14c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f12b150:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12b154:	03284821 */ 	addu	$t1,$t9,$t0
/*  f12b158:	afa9039c */ 	sw	$t1,0x39c($sp)
/*  f12b15c:	85c203c8 */ 	lh	$v0,0x3c8($t6)
/*  f12b160:	8fcb0038 */ 	lw	$t3,0x38($s8)
/*  f12b164:	0080b825 */ 	or	$s7,$a0,$zero
/*  f12b168:	284a0001 */ 	slti	$t2,$v0,0x1
/*  f12b16c:	19600289 */ 	blez	$t3,.L0f12bb94
/*  f12b170:	afaa0194 */ 	sw	$t2,0x194($sp)
/*  f12b174:	4480e000 */ 	mtc1	$zero,$f28
/*  f12b178:	c5240028 */ 	lwc1	$f4,0x28($t1)
/*  f12b17c:	461c203e */ 	c.le.s	$f4,$f28
/*  f12b180:	00000000 */ 	nop
/*  f12b184:	45030284 */ 	bc1tl	.L0f12bb98
/*  f12b188:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f12b18c:	11400006 */ 	beqz	$t2,.L0f12b1a8
/*  f12b190:	8fb9039c */ 	lw	$t9,0x39c($sp)
/*  f12b194:	8538001c */ 	lh	$t8,0x1c($t1)
/*  f12b198:	c53a0018 */ 	lwc1	$f26,0x18($t1)
/*  f12b19c:	44983000 */ 	mtc1	$t8,$f6
/*  f12b1a0:	10000011 */ 	b	.L0f12b1e8
/*  f12b1a4:	46803320 */ 	cvt.s.w	$f12,$f6
.L0f12b1a8:
/*  f12b1a8:	44822000 */ 	mtc1	$v0,$f4
/*  f12b1ac:	c7200014 */ 	lwc1	$f0,0x14($t9)
/*  f12b1b0:	c7220018 */ 	lwc1	$f2,0x18($t9)
/*  f12b1b4:	8728001c */ 	lh	$t0,0x1c($t9)
/*  f12b1b8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f12b1bc:	44884000 */ 	mtc1	$t0,$f8
/*  f12b1c0:	46001281 */ 	sub.s	$f10,$f2,$f0
/*  f12b1c4:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f12b1c8:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f12b1cc:	460c4103 */ 	div.s	$f4,$f8,$f12
/*  f12b1d0:	46040680 */ 	add.s	$f26,$f0,$f4
/*  f12b1d4:	461a103c */ 	c.lt.s	$f2,$f26
/*  f12b1d8:	00000000 */ 	nop
/*  f12b1dc:	45020003 */ 	bc1fl	.L0f12b1ec
/*  f12b1e0:	8fa9039c */ 	lw	$t1,0x39c($sp)
/*  f12b1e4:	46001686 */ 	mov.s	$f26,$f2
.L0f12b1e8:
/*  f12b1e8:	8fa9039c */ 	lw	$t1,0x39c($sp)
.L0f12b1ec:
/*  f12b1ec:	3c0140e0 */ 	lui	$at,0x40e0
/*  f12b1f0:	44815000 */ 	mtc1	$at,$f10
/*  f12b1f4:	c5260020 */ 	lwc1	$f6,0x20($t1)
/*  f12b1f8:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f12b1fc:	46086100 */ 	add.s	$f4,$f12,$f8
/*  f12b200:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f12b204:	440a5000 */ 	mfc1	$t2,$f10
/*  f12b208:	00000000 */ 	nop
/*  f12b20c:	0142082a */ 	slt	$at,$t2,$v0
/*  f12b210:	54200261 */ 	bnezl	$at,.L0f12bb98
/*  f12b214:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f12b218:	86e20028 */ 	lh	$v0,0x28($s7)
/*  f12b21c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f12b220:	02e0b025 */ 	or	$s6,$s7,$zero
/*  f12b224:	50410015 */ 	beql	$v0,$at,.L0f12b27c
/*  f12b228:	2401ffff */ 	addiu	$at,$zero,-1
.L0f12b22c:
/*  f12b22c:	0c004b70 */ 	jal	random
/*  f12b230:	00000000 */ 	nop
/*  f12b234:	304b07ff */ 	andi	$t3,$v0,0x7ff
/*  f12b238:	2d6100f1 */ 	sltiu	$at,$t3,0xf1
/*  f12b23c:	10200008 */ 	beqz	$at,.L0f12b260
/*  f12b240:	8fac039c */ 	lw	$t4,0x39c($sp)
/*  f12b244:	c5860000 */ 	lwc1	$f6,0x0($t4)
/*  f12b248:	86c40028 */ 	lh	$a0,0x28($s6)
/*  f12b24c:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f12b250:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f12b254:	44054000 */ 	mfc1	$a1,$f8
/*  f12b258:	0fc010e3 */ 	jal	roomAdjustLighting
/*  f12b25c:	00000000 */ 	nop
.L0f12b260:
/*  f12b260:	86ce002a */ 	lh	$t6,0x2a($s6)
/*  f12b264:	2401ffff */ 	addiu	$at,$zero,-1
/*  f12b268:	26d60002 */ 	addiu	$s6,$s6,0x2
/*  f12b26c:	15c1ffef */ 	bne	$t6,$at,.L0f12b22c
/*  f12b270:	00000000 */ 	nop
/*  f12b274:	86e20028 */ 	lh	$v0,0x28($s7)
/*  f12b278:	2401ffff */ 	addiu	$at,$zero,-1
.L0f12b27c:
/*  f12b27c:	10410049 */ 	beq	$v0,$at,.L0f12b3a4
/*  f12b280:	02e0b025 */ 	or	$s6,$s7,$zero
/*  f12b284:	86e20028 */ 	lh	$v0,0x28($s7)
/*  f12b288:	27b50158 */ 	addiu	$s5,$sp,0x158
/*  f12b28c:	27b4014c */ 	addiu	$s4,$sp,0x14c
/*  f12b290:	27b30164 */ 	addiu	$s3,$sp,0x164
.L0f12b294:
/*  f12b294:	1040003e */ 	beqz	$v0,.L0f12b390
/*  f12b298:	00408825 */ 	or	$s1,$v0,$zero
/*  f12b29c:	0002c8c0 */ 	sll	$t9,$v0,0x3
/*  f12b2a0:	0322c821 */ 	addu	$t9,$t9,$v0
/*  f12b2a4:	3c09800a */ 	lui	$t1,%hi(g_BgRooms)
/*  f12b2a8:	8d294cc4 */ 	lw	$t1,%lo(g_BgRooms)($t1)
/*  f12b2ac:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12b2b0:	3c18800a */ 	lui	$t8,%hi(g_Rooms)
/*  f12b2b4:	00027880 */ 	sll	$t7,$v0,0x2
/*  f12b2b8:	8f184928 */ 	lw	$t8,%lo(g_Rooms)($t8)
/*  f12b2bc:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f12b2c0:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f12b2c4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f12b2c8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12b2cc:	012f1021 */ 	addu	$v0,$t1,$t7
/*  f12b2d0:	03194021 */ 	addu	$t0,$t8,$t9
/*  f12b2d4:	81120008 */ 	lb	$s2,0x8($t0)
/*  f12b2d8:	c6f40008 */ 	lwc1	$f20,0x8($s7)
/*  f12b2dc:	c6f6000c */ 	lwc1	$f22,0xc($s7)
/*  f12b2e0:	c6f80010 */ 	lwc1	$f24,0x10($s7)
/*  f12b2e4:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f12b2e8:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f12b2ec:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f12b2f0:	00008025 */ 	or	$s0,$zero,$zero
/*  f12b2f4:	4604a501 */ 	sub.s	$f20,$f20,$f4
/*  f12b2f8:	460ab581 */ 	sub.s	$f22,$f22,$f10
/*  f12b2fc:	1a400024 */ 	blez	$s2,.L0f12b390
/*  f12b300:	4606c601 */ 	sub.s	$f24,$f24,$f6
/*  f12b304:	02202025 */ 	or	$a0,$s1,$zero
.L0f12b308:
/*  f12b308:	0fc003d4 */ 	jal	lightIsHealthy
/*  f12b30c:	02002825 */ 	or	$a1,$s0,$zero
/*  f12b310:	1040001c */ 	beqz	$v0,.L0f12b384
/*  f12b314:	02202025 */ 	or	$a0,$s1,$zero
/*  f12b318:	0fc003e5 */ 	jal	lightIsVulnerable
/*  f12b31c:	02002825 */ 	or	$a1,$s0,$zero
/*  f12b320:	10400018 */ 	beqz	$v0,.L0f12b384
/*  f12b324:	02202025 */ 	or	$a0,$s1,$zero
/*  f12b328:	02002825 */ 	or	$a1,$s0,$zero
/*  f12b32c:	0fc0037f */ 	jal	lightGetBboxCentre
/*  f12b330:	02603025 */ 	or	$a2,$s3,$zero
/*  f12b334:	10400013 */ 	beqz	$v0,.L0f12b384
/*  f12b338:	c7a80164 */ 	lwc1	$f8,0x164($sp)
/*  f12b33c:	46144101 */ 	sub.s	$f4,$f8,$f20
/*  f12b340:	c7a8016c */ 	lwc1	$f8,0x16c($sp)
/*  f12b344:	c7aa0168 */ 	lwc1	$f10,0x168($sp)
/*  f12b348:	e7ba0158 */ 	swc1	$f26,0x158($sp)
/*  f12b34c:	e7a4014c */ 	swc1	$f4,0x14c($sp)
/*  f12b350:	46184101 */ 	sub.s	$f4,$f8,$f24
/*  f12b354:	e7ba015c */ 	swc1	$f26,0x15c($sp)
/*  f12b358:	e7ba0160 */ 	swc1	$f26,0x160($sp)
/*  f12b35c:	46165181 */ 	sub.s	$f6,$f10,$f22
/*  f12b360:	e7a40154 */ 	swc1	$f4,0x154($sp)
/*  f12b364:	02802025 */ 	or	$a0,$s4,$zero
/*  f12b368:	02a02825 */ 	or	$a1,$s5,$zero
/*  f12b36c:	0fc5dcf2 */ 	jal	func0f1773c8
/*  f12b370:	e7a60150 */ 	swc1	$f6,0x150($sp)
/*  f12b374:	10400003 */ 	beqz	$v0,.L0f12b384
/*  f12b378:	02202025 */ 	or	$a0,$s1,$zero
/*  f12b37c:	0fc006de */ 	jal	roomSetLightBroken
/*  f12b380:	02002825 */ 	or	$a1,$s0,$zero
.L0f12b384:
/*  f12b384:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f12b388:	5612ffdf */ 	bnel	$s0,$s2,.L0f12b308
/*  f12b38c:	02202025 */ 	or	$a0,$s1,$zero
.L0f12b390:
/*  f12b390:	86c2002a */ 	lh	$v0,0x2a($s6)
/*  f12b394:	2401ffff */ 	addiu	$at,$zero,-1
/*  f12b398:	26d60002 */ 	addiu	$s6,$s6,0x2
/*  f12b39c:	1441ffbd */ 	bne	$v0,$at,.L0f12b294
/*  f12b3a0:	00000000 */ 	nop
.L0f12b3a4:
/*  f12b3a4:	27b00198 */ 	addiu	$s0,$sp,0x198
/*  f12b3a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f12b3ac:	26e40028 */ 	addiu	$a0,$s7,0x28
/*  f12b3b0:	0fc197e0 */ 	jal	roomGetProps
/*  f12b3b4:	24060100 */ 	addiu	$a2,$zero,0x100
/*  f12b3b8:	87aa0198 */ 	lh	$t2,0x198($sp)
/*  f12b3bc:	0200a025 */ 	or	$s4,$s0,$zero
/*  f12b3c0:	27ab0198 */ 	addiu	$t3,$sp,0x198
/*  f12b3c4:	054001f3 */ 	bltz	$t2,.L0f12bb94
/*  f12b3c8:	3c013f80 */ 	lui	$at,0x3f80
/*  f12b3cc:	4481f000 */ 	mtc1	$at,$f30
/*  f12b3d0:	85620000 */ 	lh	$v0,0x0($t3)
/*  f12b3d4:	24160004 */ 	addiu	$s6,$zero,0x4
/*  f12b3d8:	24150003 */ 	addiu	$s5,$zero,0x3
/*  f12b3dc:	8fae03a0 */ 	lw	$t6,0x3a0($sp)
.L0f12b3e0:
/*  f12b3e0:	8fcd0338 */ 	lw	$t5,0x338($s8)
/*  f12b3e4:	000260c0 */ 	sll	$t4,$v0,0x3
/*  f12b3e8:	8dd80004 */ 	lw	$t8,0x4($t6)
/*  f12b3ec:	01826021 */ 	addu	$t4,$t4,$v0
/*  f12b3f0:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f12b3f4:	018d8021 */ 	addu	$s0,$t4,$t5
/*  f12b3f8:	521801e3 */ 	beql	$s0,$t8,.L0f12bb88
/*  f12b3fc:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12b400:	86190002 */ 	lh	$t9,0x2($s0)
/*  f12b404:	572001e0 */ 	bnezl	$t9,.L0f12bb88
/*  f12b408:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12b40c:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f12b410:	24010001 */ 	addiu	$at,$zero,0x1
/*  f12b414:	50410006 */ 	beql	$v0,$at,.L0f12b430
/*  f12b418:	8e110004 */ 	lw	$s1,0x4($s0)
/*  f12b41c:	12c20003 */ 	beq	$s6,$v0,.L0f12b42c
/*  f12b420:	24010002 */ 	addiu	$at,$zero,0x2
/*  f12b424:	14410105 */ 	bne	$v0,$at,.L0f12b83c
/*  f12b428:	00000000 */ 	nop
.L0f12b42c:
/*  f12b42c:	8e110004 */ 	lw	$s1,0x4($s0)
.L0f12b430:
/*  f12b430:	c6120008 */ 	lwc1	$f18,0x8($s0)
/*  f12b434:	c6f00008 */ 	lwc1	$f16,0x8($s7)
/*  f12b438:	c60e000c */ 	lwc1	$f14,0xc($s0)
/*  f12b43c:	c6ec000c */ 	lwc1	$f12,0xc($s7)
/*  f12b440:	46109501 */ 	sub.s	$f20,$f18,$f16
/*  f12b444:	c6100010 */ 	lwc1	$f16,0x10($s0)
/*  f12b448:	c6f20010 */ 	lwc1	$f18,0x10($s7)
/*  f12b44c:	460c7581 */ 	sub.s	$f22,$f14,$f12
/*  f12b450:	00009025 */ 	or	$s2,$zero,$zero
/*  f12b454:	122001cb */ 	beqz	$s1,.L0f12bb84
/*  f12b458:	46128601 */ 	sub.s	$f24,$f16,$f18
/*  f12b45c:	461aa03e */ 	c.le.s	$f20,$f26
/*  f12b460:	00000000 */ 	nop
/*  f12b464:	45000024 */ 	bc1f	.L0f12b4f8
/*  f12b468:	00000000 */ 	nop
/*  f12b46c:	4600d007 */ 	neg.s	$f0,$f26
/*  f12b470:	4614003e */ 	c.le.s	$f0,$f20
/*  f12b474:	00000000 */ 	nop
/*  f12b478:	4500001f */ 	bc1f	.L0f12b4f8
/*  f12b47c:	00000000 */ 	nop
/*  f12b480:	461ab03e */ 	c.le.s	$f22,$f26
/*  f12b484:	00000000 */ 	nop
/*  f12b488:	4500001b */ 	bc1f	.L0f12b4f8
/*  f12b48c:	00000000 */ 	nop
/*  f12b490:	4616003e */ 	c.le.s	$f0,$f22
/*  f12b494:	00000000 */ 	nop
/*  f12b498:	45000017 */ 	bc1f	.L0f12b4f8
/*  f12b49c:	00000000 */ 	nop
/*  f12b4a0:	461ac03e */ 	c.le.s	$f24,$f26
/*  f12b4a4:	00000000 */ 	nop
/*  f12b4a8:	45000013 */ 	bc1f	.L0f12b4f8
/*  f12b4ac:	00000000 */ 	nop
/*  f12b4b0:	4618003e */ 	c.le.s	$f0,$f24
/*  f12b4b4:	02202025 */ 	or	$a0,$s1,$zero
/*  f12b4b8:	27a50130 */ 	addiu	$a1,$sp,0x130
/*  f12b4bc:	4500000e */ 	bc1f	.L0f12b4f8
/*  f12b4c0:	00000000 */ 	nop
/*  f12b4c4:	0fc248c1 */ 	jal	func0f092304
/*  f12b4c8:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f12b4cc:	10400009 */ 	beqz	$v0,.L0f12b4f4
/*  f12b4d0:	8fa403a0 */ 	lw	$a0,0x3a0($sp)
/*  f12b4d4:	02002825 */ 	or	$a1,$s0,$zero
/*  f12b4d8:	27a60130 */ 	addiu	$a2,$sp,0x130
/*  f12b4dc:	0fc4abd7 */ 	jal	func0f12af5c
/*  f12b4e0:	27a70124 */ 	addiu	$a3,$sp,0x124
/*  f12b4e4:	10400004 */ 	beqz	$v0,.L0f12b4f8
/*  f12b4e8:	00000000 */ 	nop
/*  f12b4ec:	10000002 */ 	b	.L0f12b4f8
/*  f12b4f0:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f12b4f4:
/*  f12b4f4:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f12b4f8:
/*  f12b4f8:	1240000c */ 	beqz	$s2,.L0f12b52c
/*  f12b4fc:	00000000 */ 	nop
/*  f12b500:	92080000 */ 	lbu	$t0,0x0($s0)
/*  f12b504:	16c80009 */ 	bne	$s6,$t0,.L0f12b52c
/*  f12b508:	00000000 */ 	nop
/*  f12b50c:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f12b510:	10400006 */ 	beqz	$v0,.L0f12b52c
/*  f12b514:	00000000 */ 	nop
/*  f12b518:	9049005c */ 	lbu	$t1,0x5c($v0)
/*  f12b51c:	24010058 */ 	addiu	$at,$zero,0x58
/*  f12b520:	15210002 */ 	bne	$t1,$at,.L0f12b52c
/*  f12b524:	00000000 */ 	nop
/*  f12b528:	a4400062 */ 	sh	$zero,0x62($v0)
.L0f12b52c:
/*  f12b52c:	12400195 */ 	beqz	$s2,.L0f12bb84
/*  f12b530:	3c017f1b */ 	lui	$at,%hi(var7f1b5590)
/*  f12b534:	461aa003 */ 	div.s	$f0,$f20,$f26
/*  f12b538:	8faf039c */ 	lw	$t7,0x39c($sp)
/*  f12b53c:	8fc3029c */ 	lw	$v1,0x29c($s8)
/*  f12b540:	8faa03a0 */ 	lw	$t2,0x3a0($sp)
/*  f12b544:	8fae0194 */ 	lw	$t6,0x194($sp)
/*  f12b548:	c5f00028 */ 	lwc1	$f16,0x28($t7)
/*  f12b54c:	461c003c */ 	c.lt.s	$f0,$f28
/*  f12b550:	46000086 */ 	mov.s	$f2,$f0
/*  f12b554:	45020003 */ 	bc1fl	.L0f12b564
/*  f12b558:	461ab003 */ 	div.s	$f0,$f22,$f26
/*  f12b55c:	46000087 */ 	neg.s	$f2,$f0
/*  f12b560:	461ab003 */ 	div.s	$f0,$f22,$f26
.L0f12b564:
/*  f12b564:	4602f081 */ 	sub.s	$f2,$f30,$f2
/*  f12b568:	461c003c */ 	c.lt.s	$f0,$f28
/*  f12b56c:	46000306 */ 	mov.s	$f12,$f0
/*  f12b570:	45020003 */ 	bc1fl	.L0f12b580
/*  f12b574:	461ac003 */ 	div.s	$f0,$f24,$f26
/*  f12b578:	46000307 */ 	neg.s	$f12,$f0
/*  f12b57c:	461ac003 */ 	div.s	$f0,$f24,$f26
.L0f12b580:
/*  f12b580:	460cf301 */ 	sub.s	$f12,$f30,$f12
/*  f12b584:	461c003c */ 	c.lt.s	$f0,$f28
/*  f12b588:	46000386 */ 	mov.s	$f14,$f0
/*  f12b58c:	45020003 */ 	bc1fl	.L0f12b59c
/*  f12b590:	4602603c */ 	c.lt.s	$f12,$f2
/*  f12b594:	46000387 */ 	neg.s	$f14,$f0
/*  f12b598:	4602603c */ 	c.lt.s	$f12,$f2
.L0f12b59c:
/*  f12b59c:	46001506 */ 	mov.s	$f20,$f2
/*  f12b5a0:	460ef381 */ 	sub.s	$f14,$f30,$f14
/*  f12b5a4:	45020003 */ 	bc1fl	.L0f12b5b4
/*  f12b5a8:	4614703c */ 	c.lt.s	$f14,$f20
/*  f12b5ac:	46006506 */ 	mov.s	$f20,$f12
/*  f12b5b0:	4614703c */ 	c.lt.s	$f14,$f20
.L0f12b5b4:
/*  f12b5b4:	00000000 */ 	nop
/*  f12b5b8:	45000002 */ 	bc1f	.L0f12b5c4
/*  f12b5bc:	00000000 */ 	nop
/*  f12b5c0:	46007506 */ 	mov.s	$f20,$f14
.L0f12b5c4:
/*  f12b5c4:	c4285590 */ 	lwc1	$f8,%lo(var7f1b5590)($at)
/*  f12b5c8:	3c017f1b */ 	lui	$at,%hi(var7f1b5594)
/*  f12b5cc:	c42a5594 */ 	lwc1	$f10,%lo(var7f1b5594)($at)
/*  f12b5d0:	4608a102 */ 	mul.s	$f4,$f20,$f8
/*  f12b5d4:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f12b5d8:	46103502 */ 	mul.s	$f20,$f6,$f16
/*  f12b5dc:	04600008 */ 	bltz	$v1,.L0f12b600
/*  f12b5e0:	00000000 */ 	nop
/*  f12b5e4:	814b03ce */ 	lb	$t3,0x3ce($t2)
/*  f12b5e8:	146b0005 */ 	bne	$v1,$t3,.L0f12b600
/*  f12b5ec:	00000000 */ 	nop
/*  f12b5f0:	8e2c000c */ 	lw	$t4,0xc($s1)
/*  f12b5f4:	318d0001 */ 	andi	$t5,$t4,0x1
/*  f12b5f8:	55a00163 */ 	bnezl	$t5,.L0f12bb88
/*  f12b5fc:	86820002 */ 	lh	$v0,0x2($s4)
.L0f12b600:
/*  f12b600:	11c00060 */ 	beqz	$t6,.L0f12b784
/*  f12b604:	02202025 */ 	or	$a0,$s1,$zero
/*  f12b608:	0fc199b3 */ 	jal	objUpdateLinkedScenery
/*  f12b60c:	02e02825 */ 	or	$a1,$s7,$zero
/*  f12b610:	8e220040 */ 	lw	$v0,0x40($s1)
/*  f12b614:	30581000 */ 	andi	$t8,$v0,0x1000
/*  f12b618:	57000023 */ 	bnezl	$t8,.L0f12b6a8
/*  f12b61c:	00025140 */ 	sll	$t2,$v0,0x5
/*  f12b620:	8e39000c */ 	lw	$t9,0xc($s1)
/*  f12b624:	3c010020 */ 	lui	$at,0x20
/*  f12b628:	34210400 */ 	ori	$at,$at,0x400
/*  f12b62c:	03214024 */ 	and	$t0,$t9,$at
/*  f12b630:	5500001d */ 	bnezl	$t0,.L0f12b6a8
/*  f12b634:	00025140 */ 	sll	$t2,$v0,0x5
/*  f12b638:	0c004b70 */ 	jal	random
/*  f12b63c:	00000000 */ 	nop
/*  f12b640:	44824000 */ 	mtc1	$v0,$f8
/*  f12b644:	02002025 */ 	or	$a0,$s0,$zero
/*  f12b648:	04410005 */ 	bgez	$v0,.L0f12b660
/*  f12b64c:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f12b650:	3c014f80 */ 	lui	$at,0x4f80
/*  f12b654:	44815000 */ 	mtc1	$at,$f10
/*  f12b658:	00000000 */ 	nop
/*  f12b65c:	460a2100 */ 	add.s	$f4,$f4,$f10
.L0f12b660:
/*  f12b660:	3c012f80 */ 	lui	$at,0x2f80
/*  f12b664:	44813000 */ 	mtc1	$at,$f6
/*  f12b668:	3c013f00 */ 	lui	$at,0x3f00
/*  f12b66c:	44815000 */ 	mtc1	$at,$f10
/*  f12b670:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f12b674:	8fa903a0 */ 	lw	$t1,0x3a0($sp)
/*  f12b678:	26060008 */ 	addiu	$a2,$s0,0x8
/*  f12b67c:	24070022 */ 	addiu	$a3,$zero,0x22
/*  f12b680:	812f03ce */ 	lb	$t7,0x3ce($t1)
/*  f12b684:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f12b688:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f12b68c:	461e2180 */ 	add.s	$f6,$f4,$f30
/*  f12b690:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f12b694:	44054000 */ 	mfc1	$a1,$f8
/*  f12b698:	0fc21414 */ 	jal	func0f085050
/*  f12b69c:	00000000 */ 	nop
/*  f12b6a0:	8e220040 */ 	lw	$v0,0x40($s1)
/*  f12b6a4:	00025140 */ 	sll	$t2,$v0,0x5
.L0f12b6a8:
/*  f12b6a8:	05400136 */ 	bltz	$t2,.L0f12bb84
/*  f12b6ac:	00025900 */ 	sll	$t3,$v0,0x4
/*  f12b6b0:	05620135 */ 	bltzl	$t3,.L0f12bb88
/*  f12b6b4:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12b6b8:	8e2c0010 */ 	lw	$t4,0x10($s1)
/*  f12b6bc:	318d0001 */ 	andi	$t5,$t4,0x1
/*  f12b6c0:	51a00131 */ 	beqzl	$t5,.L0f12bb88
/*  f12b6c4:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12b6c8:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f12b6cc:	c6e40008 */ 	lwc1	$f4,0x8($s7)
/*  f12b6d0:	e7bc00f8 */ 	swc1	$f28,0xf8($sp)
/*  f12b6d4:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f12b6d8:	e7a600f4 */ 	swc1	$f6,0xf4($sp)
/*  f12b6dc:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
/*  f12b6e0:	c6ea0010 */ 	lwc1	$f10,0x10($s7)
/*  f12b6e4:	c6080010 */ 	lwc1	$f8,0x10($s0)
/*  f12b6e8:	4606e032 */ 	c.eq.s	$f28,$f6
/*  f12b6ec:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f12b6f0:	45000006 */ 	bc1f	.L0f12b70c
/*  f12b6f4:	e7a400fc */ 	swc1	$f4,0xfc($sp)
/*  f12b6f8:	c7a800fc */ 	lwc1	$f8,0xfc($sp)
/*  f12b6fc:	4608e032 */ 	c.eq.s	$f28,$f8
/*  f12b700:	00000000 */ 	nop
/*  f12b704:	45030017 */ 	bc1tl	.L0f12b764
/*  f12b708:	4406e000 */ 	mfc1	$a2,$f28
.L0f12b70c:
/*  f12b70c:	c7aa00fc */ 	lwc1	$f10,0xfc($sp)
/*  f12b710:	c7ae00f4 */ 	lwc1	$f14,0xf4($sp)
/*  f12b714:	460a5102 */ 	mul.s	$f4,$f10,$f10
/*  f12b718:	00000000 */ 	nop
/*  f12b71c:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f12b720:	0c012974 */ 	jal	sqrtf
/*  f12b724:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f12b728:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f12b72c:	3c014080 */ 	lui	$at,0x4080
/*  f12b730:	4502000c */ 	bc1fl	.L0f12b764
/*  f12b734:	4406e000 */ 	mfc1	$a2,$f28
/*  f12b738:	44814000 */ 	mtc1	$at,$f8
/*  f12b73c:	c7ae00f4 */ 	lwc1	$f14,0xf4($sp)
/*  f12b740:	c7a400fc */ 	lwc1	$f4,0xfc($sp)
/*  f12b744:	4608a282 */ 	mul.s	$f10,$f20,$f8
/*  f12b748:	46005083 */ 	div.s	$f2,$f10,$f0
/*  f12b74c:	46027382 */ 	mul.s	$f14,$f14,$f2
/*  f12b750:	00000000 */ 	nop
/*  f12b754:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f12b758:	e7ae00f4 */ 	swc1	$f14,0xf4($sp)
/*  f12b75c:	e7a600fc */ 	swc1	$f6,0xfc($sp)
/*  f12b760:	4406e000 */ 	mfc1	$a2,$f28
.L0f12b764:
/*  f12b764:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f12b768:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f12b76c:	02202025 */ 	or	$a0,$s1,$zero
/*  f12b770:	27a500f4 */ 	addiu	$a1,$sp,0xf4
/*  f12b774:	0fc20a87 */ 	jal	func0f082a1c
/*  f12b778:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f12b77c:	10000102 */ 	b	.L0f12bb88
/*  f12b780:	86820002 */ 	lh	$v0,0x2($s4)
.L0f12b784:
/*  f12b784:	0fc21a6a */ 	jal	objIsHealthy
/*  f12b788:	02202025 */ 	or	$a0,$s1,$zero
/*  f12b78c:	104000fd */ 	beqz	$v0,.L0f12bb84
/*  f12b790:	3c017f1b */ 	lui	$at,%hi(var7f1b5598)
/*  f12b794:	c4285598 */ 	lwc1	$f8,%lo(var7f1b5598)($at)
/*  f12b798:	c7ca004c */ 	lwc1	$f10,0x4c($s8)
/*  f12b79c:	8e380040 */ 	lw	$t8,0x40($s1)
/*  f12b7a0:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f12b7a4:	33191000 */ 	andi	$t9,$t8,0x1000
/*  f12b7a8:	4604a502 */ 	mul.s	$f20,$f20,$f4
/*  f12b7ac:	572000f6 */ 	bnezl	$t9,.L0f12bb88
/*  f12b7b0:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12b7b4:	8e28000c */ 	lw	$t0,0xc($s1)
/*  f12b7b8:	3c010020 */ 	lui	$at,0x20
/*  f12b7bc:	34210400 */ 	ori	$at,$at,0x400
/*  f12b7c0:	01014824 */ 	and	$t1,$t0,$at
/*  f12b7c4:	552000f0 */ 	bnezl	$t1,.L0f12bb88
/*  f12b7c8:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12b7cc:	0c004b70 */ 	jal	random
/*  f12b7d0:	00000000 */ 	nop
/*  f12b7d4:	44823000 */ 	mtc1	$v0,$f6
/*  f12b7d8:	02002025 */ 	or	$a0,$s0,$zero
/*  f12b7dc:	04410005 */ 	bgez	$v0,.L0f12b7f4
/*  f12b7e0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f12b7e4:	3c014f80 */ 	lui	$at,0x4f80
/*  f12b7e8:	44815000 */ 	mtc1	$at,$f10
/*  f12b7ec:	00000000 */ 	nop
/*  f12b7f0:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f12b7f4:
/*  f12b7f4:	3c012f80 */ 	lui	$at,0x2f80
/*  f12b7f8:	44812000 */ 	mtc1	$at,$f4
/*  f12b7fc:	3c013f00 */ 	lui	$at,0x3f00
/*  f12b800:	44815000 */ 	mtc1	$at,$f10
/*  f12b804:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f12b808:	8faf03a0 */ 	lw	$t7,0x3a0($sp)
/*  f12b80c:	26060008 */ 	addiu	$a2,$s0,0x8
/*  f12b810:	24070022 */ 	addiu	$a3,$zero,0x22
/*  f12b814:	81ea03ce */ 	lb	$t2,0x3ce($t7)
/*  f12b818:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f12b81c:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f12b820:	461e4100 */ 	add.s	$f4,$f8,$f30
/*  f12b824:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f12b828:	44053000 */ 	mfc1	$a1,$f6
/*  f12b82c:	0fc21414 */ 	jal	func0f085050
/*  f12b830:	00000000 */ 	nop
/*  f12b834:	100000d4 */ 	b	.L0f12bb88
/*  f12b838:	86820002 */ 	lh	$v0,0x2($s4)
.L0f12b83c:
/*  f12b83c:	12a20003 */ 	beq	$s5,$v0,.L0f12b84c
/*  f12b840:	24010006 */ 	addiu	$at,$zero,0x6
/*  f12b844:	544100d0 */ 	bnel	$v0,$at,.L0f12bb88
/*  f12b848:	86820002 */ 	lh	$v0,0x2($s4)
.L0f12b84c:
/*  f12b84c:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f12b850:	c6e80008 */ 	lwc1	$f8,0x8($s7)
/*  f12b854:	c604000c */ 	lwc1	$f4,0xc($s0)
/*  f12b858:	c6e6000c */ 	lwc1	$f6,0xc($s7)
/*  f12b85c:	46085581 */ 	sub.s	$f22,$f10,$f8
/*  f12b860:	c6e80010 */ 	lwc1	$f8,0x10($s7)
/*  f12b864:	c60a0010 */ 	lwc1	$f10,0x10($s0)
/*  f12b868:	00008825 */ 	or	$s1,$zero,$zero
/*  f12b86c:	461ab03e */ 	c.le.s	$f22,$f26
/*  f12b870:	46062501 */ 	sub.s	$f20,$f4,$f6
/*  f12b874:	4500003d */ 	bc1f	.L0f12b96c
/*  f12b878:	46085601 */ 	sub.s	$f24,$f10,$f8
/*  f12b87c:	4600d007 */ 	neg.s	$f0,$f26
/*  f12b880:	4616003e */ 	c.le.s	$f0,$f22
/*  f12b884:	00000000 */ 	nop
/*  f12b888:	45000038 */ 	bc1f	.L0f12b96c
/*  f12b88c:	00000000 */ 	nop
/*  f12b890:	461aa03e */ 	c.le.s	$f20,$f26
/*  f12b894:	00000000 */ 	nop
/*  f12b898:	45000034 */ 	bc1f	.L0f12b96c
/*  f12b89c:	00000000 */ 	nop
/*  f12b8a0:	4614003e */ 	c.le.s	$f0,$f20
/*  f12b8a4:	00000000 */ 	nop
/*  f12b8a8:	45000030 */ 	bc1f	.L0f12b96c
/*  f12b8ac:	00000000 */ 	nop
/*  f12b8b0:	461ac03e */ 	c.le.s	$f24,$f26
/*  f12b8b4:	00000000 */ 	nop
/*  f12b8b8:	4500002c */ 	bc1f	.L0f12b96c
/*  f12b8bc:	00000000 */ 	nop
/*  f12b8c0:	4618003e */ 	c.le.s	$f0,$f24
/*  f12b8c4:	02002025 */ 	or	$a0,$s0,$zero
/*  f12b8c8:	27a500e0 */ 	addiu	$a1,$sp,0xe0
/*  f12b8cc:	27a600dc */ 	addiu	$a2,$sp,0xdc
/*  f12b8d0:	45000026 */ 	bc1f	.L0f12b96c
/*  f12b8d4:	00000000 */ 	nop
/*  f12b8d8:	0fc19881 */ 	jal	propGetBbox
/*  f12b8dc:	27a700d8 */ 	addiu	$a3,$sp,0xd8
/*  f12b8e0:	3c0141a0 */ 	lui	$at,0x41a0
/*  f12b8e4:	c7a000e0 */ 	lwc1	$f0,0xe0($sp)
/*  f12b8e8:	44812000 */ 	mtc1	$at,$f4
/*  f12b8ec:	00000000 */ 	nop
/*  f12b8f0:	46040001 */ 	sub.s	$f0,$f0,$f4
/*  f12b8f4:	461c003e */ 	c.le.s	$f0,$f28
/*  f12b8f8:	e7a000e0 */ 	swc1	$f0,0xe0($sp)
/*  f12b8fc:	45020003 */ 	bc1fl	.L0f12b90c
/*  f12b900:	c6060008 */ 	lwc1	$f6,0x8($s0)
/*  f12b904:	e7bc00e0 */ 	swc1	$f28,0xe0($sp)
/*  f12b908:	c6060008 */ 	lwc1	$f6,0x8($s0)
.L0f12b90c:
/*  f12b90c:	c7aa00e0 */ 	lwc1	$f10,0xe0($sp)
/*  f12b910:	c7a400d8 */ 	lwc1	$f4,0xd8($sp)
/*  f12b914:	8fa403a0 */ 	lw	$a0,0x3a0($sp)
/*  f12b918:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*  f12b91c:	e7a400d0 */ 	swc1	$f4,0xd0($sp)
/*  f12b920:	02002825 */ 	or	$a1,$s0,$zero
/*  f12b924:	27a600cc */ 	addiu	$a2,$sp,0xcc
/*  f12b928:	e7a800cc */ 	swc1	$f8,0xcc($sp)
/*  f12b92c:	c6060010 */ 	lwc1	$f6,0x10($s0)
/*  f12b930:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f12b934:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*  f12b938:	e7a800d4 */ 	swc1	$f8,0xd4($sp)
/*  f12b93c:	c6040008 */ 	lwc1	$f4,0x8($s0)
/*  f12b940:	c7a800dc */ 	lwc1	$f8,0xdc($sp)
/*  f12b944:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f12b948:	e7a800c4 */ 	swc1	$f8,0xc4($sp)
/*  f12b94c:	e7a600c0 */ 	swc1	$f6,0xc0($sp)
/*  f12b950:	c6040010 */ 	lwc1	$f4,0x10($s0)
/*  f12b954:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f12b958:	0fc4abd7 */ 	jal	func0f12af5c
/*  f12b95c:	e7a600c8 */ 	swc1	$f6,0xc8($sp)
/*  f12b960:	10400002 */ 	beqz	$v0,.L0f12b96c
/*  f12b964:	00000000 */ 	nop
/*  f12b968:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f12b96c:
/*  f12b96c:	52200086 */ 	beqzl	$s1,.L0f12bb88
/*  f12b970:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12b974:	461ab083 */ 	div.s	$f2,$f22,$f26
/*  f12b978:	3c0c8008 */ 	lui	$t4,%hi(var8007e930)
/*  f12b97c:	258ce930 */ 	addiu	$t4,$t4,%lo(var8007e930)
/*  f12b980:	8d810000 */ 	lw	$at,0x0($t4)
/*  f12b984:	27ab00a0 */ 	addiu	$t3,$sp,0xa0
/*  f12b988:	8d8e0004 */ 	lw	$t6,0x4($t4)
/*  f12b98c:	ad610000 */ 	sw	$at,0x0($t3)
/*  f12b990:	8d810008 */ 	lw	$at,0x8($t4)
/*  f12b994:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f12b998:	00008825 */ 	or	$s1,$zero,$zero
/*  f12b99c:	ad610008 */ 	sw	$at,0x8($t3)
/*  f12b9a0:	8e120004 */ 	lw	$s2,0x4($s0)
/*  f12b9a4:	26f30008 */ 	addiu	$s3,$s7,0x8
/*  f12b9a8:	461aa383 */ 	div.s	$f14,$f20,$f26
/*  f12b9ac:	46001006 */ 	mov.s	$f0,$f2
/*  f12b9b0:	461c103c */ 	c.lt.s	$f2,$f28
/*  f12b9b4:	461ac483 */ 	div.s	$f18,$f24,$f26
/*  f12b9b8:	46007306 */ 	mov.s	$f12,$f14
/*  f12b9bc:	45000002 */ 	bc1f	.L0f12b9c8
/*  f12b9c0:	46009406 */ 	mov.s	$f16,$f18
/*  f12b9c4:	46001007 */ 	neg.s	$f0,$f2
.L0f12b9c8:
/*  f12b9c8:	461c703c */ 	c.lt.s	$f14,$f28
/*  f12b9cc:	4600f501 */ 	sub.s	$f20,$f30,$f0
/*  f12b9d0:	45020003 */ 	bc1fl	.L0f12b9e0
/*  f12b9d4:	461c903c */ 	c.lt.s	$f18,$f28
/*  f12b9d8:	46007307 */ 	neg.s	$f12,$f14
/*  f12b9dc:	461c903c */ 	c.lt.s	$f18,$f28
.L0f12b9e0:
/*  f12b9e0:	460cf301 */ 	sub.s	$f12,$f30,$f12
/*  f12b9e4:	45020003 */ 	bc1fl	.L0f12b9f4
/*  f12b9e8:	4614603c */ 	c.lt.s	$f12,$f20
/*  f12b9ec:	46009407 */ 	neg.s	$f16,$f18
/*  f12b9f0:	4614603c */ 	c.lt.s	$f12,$f20
.L0f12b9f4:
/*  f12b9f4:	4610f401 */ 	sub.s	$f16,$f30,$f16
/*  f12b9f8:	45020003 */ 	bc1fl	.L0f12ba08
/*  f12b9fc:	4614803c */ 	c.lt.s	$f16,$f20
/*  f12ba00:	46006506 */ 	mov.s	$f20,$f12
/*  f12ba04:	4614803c */ 	c.lt.s	$f16,$f20
.L0f12ba08:
/*  f12ba08:	00000000 */ 	nop
/*  f12ba0c:	45000002 */ 	bc1f	.L0f12ba18
/*  f12ba10:	00000000 */ 	nop
/*  f12ba14:	46008506 */ 	mov.s	$f20,$f16
.L0f12ba18:
/*  f12ba18:	4614a502 */ 	mul.s	$f20,$f20,$f20
/*  f12ba1c:	8fb8039c */ 	lw	$t8,0x39c($sp)
/*  f12ba20:	3c014100 */ 	lui	$at,0x4100
/*  f12ba24:	44815000 */ 	mtc1	$at,$f10
/*  f12ba28:	c7080028 */ 	lwc1	$f8,0x28($t8)
/*  f12ba2c:	8fb90194 */ 	lw	$t9,0x194($sp)
/*  f12ba30:	3c017f1b */ 	lui	$at,%hi(var7f1b559c)
/*  f12ba34:	46144102 */ 	mul.s	$f4,$f8,$f20
/*  f12ba38:	00000000 */ 	nop
/*  f12ba3c:	460a2502 */ 	mul.s	$f20,$f4,$f10
/*  f12ba40:	1320001a */ 	beqz	$t9,.L0f12baac
/*  f12ba44:	00000000 */ 	nop
/*  f12ba48:	461cb032 */ 	c.eq.s	$f22,$f28
/*  f12ba4c:	00000000 */ 	nop
/*  f12ba50:	45000005 */ 	bc1f	.L0f12ba68
/*  f12ba54:	00000000 */ 	nop
/*  f12ba58:	461cc032 */ 	c.eq.s	$f24,$f28
/*  f12ba5c:	00000000 */ 	nop
/*  f12ba60:	45030019 */ 	bc1tl	.L0f12bac8
/*  f12ba64:	8fc80318 */ 	lw	$t0,0x318($s8)
.L0f12ba68:
/*  f12ba68:	4616b182 */ 	mul.s	$f6,$f22,$f22
/*  f12ba6c:	00000000 */ 	nop
/*  f12ba70:	4618c202 */ 	mul.s	$f8,$f24,$f24
/*  f12ba74:	0c012974 */ 	jal	sqrtf
/*  f12ba78:	46083300 */ 	add.s	$f12,$f6,$f8
/*  f12ba7c:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f12ba80:	00000000 */ 	nop
/*  f12ba84:	45020010 */ 	bc1fl	.L0f12bac8
/*  f12ba88:	8fc80318 */ 	lw	$t0,0x318($s8)
/*  f12ba8c:	4600f083 */ 	div.s	$f2,$f30,$f0
/*  f12ba90:	e7bc00a4 */ 	swc1	$f28,0xa4($sp)
/*  f12ba94:	4602b582 */ 	mul.s	$f22,$f22,$f2
/*  f12ba98:	00000000 */ 	nop
/*  f12ba9c:	4602c602 */ 	mul.s	$f24,$f24,$f2
/*  f12baa0:	e7b600a0 */ 	swc1	$f22,0xa0($sp)
/*  f12baa4:	10000007 */ 	b	.L0f12bac4
/*  f12baa8:	e7b800a8 */ 	swc1	$f24,0xa8($sp)
.L0f12baac:
/*  f12baac:	c424559c */ 	lwc1	$f4,%lo(var7f1b559c)($at)
/*  f12bab0:	c7ca004c */ 	lwc1	$f10,0x4c($s8)
/*  f12bab4:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f12bab8:	00000000 */ 	nop
/*  f12babc:	4606a502 */ 	mul.s	$f20,$f20,$f6
/*  f12bac0:	00000000 */ 	nop
.L0f12bac4:
/*  f12bac4:	8fc80318 */ 	lw	$t0,0x318($s8)
.L0f12bac8:
/*  f12bac8:	8fa903a0 */ 	lw	$t1,0x3a0($sp)
/*  f12bacc:	8faf03a0 */ 	lw	$t7,0x3a0($sp)
/*  f12bad0:	51000008 */ 	beqzl	$t0,.L0f12baf4
/*  f12bad4:	81e203ce */ 	lb	$v0,0x3ce($t7)
/*  f12bad8:	0fc63410 */ 	jal	mpGetChrFromPlayerIndex
/*  f12badc:	812403ce */ 	lb	$a0,0x3ce($t1)
/*  f12bae0:	5040001a */ 	beqzl	$v0,.L0f12bb4c
/*  f12bae4:	4405a000 */ 	mfc1	$a1,$f20
/*  f12bae8:	10000017 */ 	b	.L0f12bb48
/*  f12baec:	8c51001c */ 	lw	$s1,0x1c($v0)
/*  f12baf0:	81e203ce */ 	lb	$v0,0x3ce($t7)
.L0f12baf4:
/*  f12baf4:	8fca0294 */ 	lw	$t2,0x294($s8)
/*  f12baf8:	55420005 */ 	bnel	$t2,$v0,.L0f12bb10
/*  f12bafc:	8fc30298 */ 	lw	$v1,0x298($s8)
/*  f12bb00:	8fcd02a0 */ 	lw	$t5,0x2a0($s8)
/*  f12bb04:	10000010 */ 	b	.L0f12bb48
/*  f12bb08:	8db100bc */ 	lw	$s1,0xbc($t5)
/*  f12bb0c:	8fc30298 */ 	lw	$v1,0x298($s8)
.L0f12bb10:
/*  f12bb10:	04620007 */ 	bltzl	$v1,.L0f12bb30
/*  f12bb14:	8fc3029c */ 	lw	$v1,0x29c($s8)
/*  f12bb18:	54620005 */ 	bnel	$v1,$v0,.L0f12bb30
/*  f12bb1c:	8fc3029c */ 	lw	$v1,0x29c($s8)
/*  f12bb20:	8fcb02a4 */ 	lw	$t3,0x2a4($s8)
/*  f12bb24:	10000008 */ 	b	.L0f12bb48
/*  f12bb28:	8d7100bc */ 	lw	$s1,0xbc($t3)
/*  f12bb2c:	8fc3029c */ 	lw	$v1,0x29c($s8)
.L0f12bb30:
/*  f12bb30:	04620006 */ 	bltzl	$v1,.L0f12bb4c
/*  f12bb34:	4405a000 */ 	mfc1	$a1,$f20
/*  f12bb38:	54620004 */ 	bnel	$v1,$v0,.L0f12bb4c
/*  f12bb3c:	4405a000 */ 	mfc1	$a1,$f20
/*  f12bb40:	8fcc02a8 */ 	lw	$t4,0x2a8($s8)
/*  f12bb44:	8d9100bc */ 	lw	$s1,0xbc($t4)
.L0f12bb48:
/*  f12bb48:	4405a000 */ 	mfc1	$a1,$f20
.L0f12bb4c:
/*  f12bb4c:	02402025 */ 	or	$a0,$s2,$zero
/*  f12bb50:	27a600a0 */ 	addiu	$a2,$sp,0xa0
/*  f12bb54:	02203825 */ 	or	$a3,$s1,$zero
/*  f12bb58:	0fc0d104 */ 	jal	func0f034410
/*  f12bb5c:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f12bb60:	920e0000 */ 	lbu	$t6,0x0($s0)
/*  f12bb64:	8fb80194 */ 	lw	$t8,0x194($sp)
/*  f12bb68:	56ae0007 */ 	bnel	$s5,$t6,.L0f12bb88
/*  f12bb6c:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12bb70:	17000004 */ 	bnez	$t8,.L0f12bb84
/*  f12bb74:	02402025 */ 	or	$a0,$s2,$zero
/*  f12bb78:	4406d000 */ 	mfc1	$a2,$f26
/*  f12bb7c:	0fc09c3d */ 	jal	func0f0270f4
/*  f12bb80:	02602825 */ 	or	$a1,$s3,$zero
.L0f12bb84:
/*  f12bb84:	86820002 */ 	lh	$v0,0x2($s4)
.L0f12bb88:
/*  f12bb88:	26940002 */ 	addiu	$s4,$s4,0x2
/*  f12bb8c:	0443fe14 */ 	bgezl	$v0,.L0f12b3e0
/*  f12bb90:	8fae03a0 */ 	lw	$t6,0x3a0($sp)
.L0f12bb94:
/*  f12bb94:	8fbf0074 */ 	lw	$ra,0x74($sp)
.L0f12bb98:
/*  f12bb98:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f12bb9c:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f12bba0:	d7b80030 */ 	ldc1	$f24,0x30($sp)
/*  f12bba4:	d7ba0038 */ 	ldc1	$f26,0x38($sp)
/*  f12bba8:	d7bc0040 */ 	ldc1	$f28,0x40($sp)
/*  f12bbac:	d7be0048 */ 	ldc1	$f30,0x48($sp)
/*  f12bbb0:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f12bbb4:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f12bbb8:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f12bbbc:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f12bbc0:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f12bbc4:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f12bbc8:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f12bbcc:	8fb7006c */ 	lw	$s7,0x6c($sp)
/*  f12bbd0:	8fbe0070 */ 	lw	$s8,0x70($sp)
/*  f12bbd4:	03e00008 */ 	jr	$ra
/*  f12bbd8:	27bd03a8 */ 	addiu	$sp,$sp,0x3a8
);
#else
GLOBAL_ASM(
glabel func0f12b0e0
.late_rodata
glabel var7f1b5590
.word 0x3f333333
glabel var7f1b5594
.word 0x3e99999a
glabel var7f1b5598
.word 0x3d4ccccd
glabel var7f1b559c
.word 0x3d4ccccd
.text
/*  f125c7c:	27bdfc58 */ 	addiu	$sp,$sp,-936
/*  f125c80:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f125c84:	afbe0070 */ 	sw	$s8,0x70($sp)
/*  f125c88:	afb7006c */ 	sw	$s7,0x6c($sp)
/*  f125c8c:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f125c90:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f125c94:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f125c98:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f125c9c:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f125ca0:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f125ca4:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f125ca8:	f7be0048 */ 	sdc1	$f30,0x48($sp)
/*  f125cac:	f7bc0040 */ 	sdc1	$f28,0x40($sp)
/*  f125cb0:	f7ba0038 */ 	sdc1	$f26,0x38($sp)
/*  f125cb4:	f7b80030 */ 	sdc1	$f24,0x30($sp)
/*  f125cb8:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f125cbc:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f125cc0:	8c8e0004 */ 	lw	$t6,0x4($a0)
/*  f125cc4:	3c088008 */ 	lui	$t0,0x8008
/*  f125cc8:	25080d18 */ 	addiu	$t0,$t0,0xd18
/*  f125ccc:	afae03a0 */ 	sw	$t6,0x3a0($sp)
/*  f125cd0:	81d803cc */ 	lb	$t8,0x3cc($t6)
/*  f125cd4:	3c1e800a */ 	lui	$s8,0x800a
/*  f125cd8:	27dee6c0 */ 	addiu	$s8,$s8,-6464
/*  f125cdc:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f125ce0:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f125ce4:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f125ce8:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f125cec:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f125cf0:	03284821 */ 	addu	$t1,$t9,$t0
/*  f125cf4:	afa9039c */ 	sw	$t1,0x39c($sp)
/*  f125cf8:	85c203c8 */ 	lh	$v0,0x3c8($t6)
/*  f125cfc:	8fcb0038 */ 	lw	$t3,0x38($s8)
/*  f125d00:	0080b825 */ 	or	$s7,$a0,$zero
/*  f125d04:	284a0001 */ 	slti	$t2,$v0,0x1
/*  f125d08:	19600286 */ 	blez	$t3,.NB0f126724
/*  f125d0c:	afaa0194 */ 	sw	$t2,0x194($sp)
/*  f125d10:	4480e000 */ 	mtc1	$zero,$f28
/*  f125d14:	c5240028 */ 	lwc1	$f4,0x28($t1)
/*  f125d18:	461c203e */ 	c.le.s	$f4,$f28
/*  f125d1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f125d20:	45030281 */ 	bc1tl	.NB0f126728
/*  f125d24:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f125d28:	11400006 */ 	beqz	$t2,.NB0f125d44
/*  f125d2c:	8fb9039c */ 	lw	$t9,0x39c($sp)
/*  f125d30:	8538001c */ 	lh	$t8,0x1c($t1)
/*  f125d34:	c53a0018 */ 	lwc1	$f26,0x18($t1)
/*  f125d38:	44983000 */ 	mtc1	$t8,$f6
/*  f125d3c:	10000011 */ 	beqz	$zero,.NB0f125d84
/*  f125d40:	46803320 */ 	cvt.s.w	$f12,$f6
.NB0f125d44:
/*  f125d44:	44822000 */ 	mtc1	$v0,$f4
/*  f125d48:	c7200014 */ 	lwc1	$f0,0x14($t9)
/*  f125d4c:	c7220018 */ 	lwc1	$f2,0x18($t9)
/*  f125d50:	8728001c */ 	lh	$t0,0x1c($t9)
/*  f125d54:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f125d58:	44884000 */ 	mtc1	$t0,$f8
/*  f125d5c:	46001281 */ 	sub.s	$f10,$f2,$f0
/*  f125d60:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f125d64:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f125d68:	460c4103 */ 	div.s	$f4,$f8,$f12
/*  f125d6c:	46040680 */ 	add.s	$f26,$f0,$f4
/*  f125d70:	461a103c */ 	c.lt.s	$f2,$f26
/*  f125d74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f125d78:	45020003 */ 	bc1fl	.NB0f125d88
/*  f125d7c:	8fa9039c */ 	lw	$t1,0x39c($sp)
/*  f125d80:	46001686 */ 	mov.s	$f26,$f2
.NB0f125d84:
/*  f125d84:	8fa9039c */ 	lw	$t1,0x39c($sp)
.NB0f125d88:
/*  f125d88:	3c0140e0 */ 	lui	$at,0x40e0
/*  f125d8c:	44815000 */ 	mtc1	$at,$f10
/*  f125d90:	c5260020 */ 	lwc1	$f6,0x20($t1)
/*  f125d94:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f125d98:	46086100 */ 	add.s	$f4,$f12,$f8
/*  f125d9c:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f125da0:	440a5000 */ 	mfc1	$t2,$f10
/*  f125da4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f125da8:	0142082a */ 	slt	$at,$t2,$v0
/*  f125dac:	5420025e */ 	bnezl	$at,.NB0f126728
/*  f125db0:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f125db4:	86e20028 */ 	lh	$v0,0x28($s7)
/*  f125db8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f125dbc:	02e0b025 */ 	or	$s6,$s7,$zero
/*  f125dc0:	50410015 */ 	beql	$v0,$at,.NB0f125e18
/*  f125dc4:	2401ffff */ 	addiu	$at,$zero,-1
.NB0f125dc8:
/*  f125dc8:	0c004d84 */ 	jal	random
/*  f125dcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f125dd0:	304b07ff */ 	andi	$t3,$v0,0x7ff
/*  f125dd4:	2d6100f1 */ 	sltiu	$at,$t3,0xf1
/*  f125dd8:	10200008 */ 	beqz	$at,.NB0f125dfc
/*  f125ddc:	8fac039c */ 	lw	$t4,0x39c($sp)
/*  f125de0:	c5860000 */ 	lwc1	$f6,0x0($t4)
/*  f125de4:	86c40028 */ 	lh	$a0,0x28($s6)
/*  f125de8:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f125dec:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f125df0:	44054000 */ 	mfc1	$a1,$f8
/*  f125df4:	0fc01035 */ 	jal	roomAdjustLighting
/*  f125df8:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f125dfc:
/*  f125dfc:	86ce002a */ 	lh	$t6,0x2a($s6)
/*  f125e00:	2401ffff */ 	addiu	$at,$zero,-1
/*  f125e04:	26d60002 */ 	addiu	$s6,$s6,0x2
/*  f125e08:	15c1ffef */ 	bne	$t6,$at,.NB0f125dc8
/*  f125e0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f125e10:	86e20028 */ 	lh	$v0,0x28($s7)
/*  f125e14:	2401ffff */ 	addiu	$at,$zero,-1
.NB0f125e18:
/*  f125e18:	10410049 */ 	beq	$v0,$at,.NB0f125f40
/*  f125e1c:	02e0b025 */ 	or	$s6,$s7,$zero
/*  f125e20:	86e20028 */ 	lh	$v0,0x28($s7)
/*  f125e24:	27b50158 */ 	addiu	$s5,$sp,0x158
/*  f125e28:	27b4014c */ 	addiu	$s4,$sp,0x14c
/*  f125e2c:	27b30164 */ 	addiu	$s3,$sp,0x164
.NB0f125e30:
/*  f125e30:	1040003e */ 	beqz	$v0,.NB0f125f2c
/*  f125e34:	00408825 */ 	or	$s1,$v0,$zero
/*  f125e38:	0002c8c0 */ 	sll	$t9,$v0,0x3
/*  f125e3c:	0322c821 */ 	addu	$t9,$t9,$v0
/*  f125e40:	3c09800b */ 	lui	$t1,0x800b
/*  f125e44:	8d299444 */ 	lw	$t1,-0x6bbc($t1)
/*  f125e48:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f125e4c:	3c18800b */ 	lui	$t8,0x800b
/*  f125e50:	00027880 */ 	sll	$t7,$v0,0x2
/*  f125e54:	8f1890a8 */ 	lw	$t8,-0x6f58($t8)
/*  f125e58:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f125e5c:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f125e60:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f125e64:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f125e68:	012f1021 */ 	addu	$v0,$t1,$t7
/*  f125e6c:	03194021 */ 	addu	$t0,$t8,$t9
/*  f125e70:	81120008 */ 	lb	$s2,0x8($t0)
/*  f125e74:	c6f40008 */ 	lwc1	$f20,0x8($s7)
/*  f125e78:	c6f6000c */ 	lwc1	$f22,0xc($s7)
/*  f125e7c:	c6f80010 */ 	lwc1	$f24,0x10($s7)
/*  f125e80:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f125e84:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f125e88:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f125e8c:	00008025 */ 	or	$s0,$zero,$zero
/*  f125e90:	4604a501 */ 	sub.s	$f20,$f20,$f4
/*  f125e94:	460ab581 */ 	sub.s	$f22,$f22,$f10
/*  f125e98:	1a400024 */ 	blez	$s2,.NB0f125f2c
/*  f125e9c:	4606c601 */ 	sub.s	$f24,$f24,$f6
/*  f125ea0:	02202025 */ 	or	$a0,$s1,$zero
.NB0f125ea4:
/*  f125ea4:	0fc003d4 */ 	jal	lightIsHealthy
/*  f125ea8:	02002825 */ 	or	$a1,$s0,$zero
/*  f125eac:	1040001c */ 	beqz	$v0,.NB0f125f20
/*  f125eb0:	02202025 */ 	or	$a0,$s1,$zero
/*  f125eb4:	0fc003e5 */ 	jal	lightIsVulnerable
/*  f125eb8:	02002825 */ 	or	$a1,$s0,$zero
/*  f125ebc:	10400018 */ 	beqz	$v0,.NB0f125f20
/*  f125ec0:	02202025 */ 	or	$a0,$s1,$zero
/*  f125ec4:	02002825 */ 	or	$a1,$s0,$zero
/*  f125ec8:	0fc0037f */ 	jal	lightGetBboxCentre
/*  f125ecc:	02603025 */ 	or	$a2,$s3,$zero
/*  f125ed0:	10400013 */ 	beqz	$v0,.NB0f125f20
/*  f125ed4:	c7a80164 */ 	lwc1	$f8,0x164($sp)
/*  f125ed8:	46144101 */ 	sub.s	$f4,$f8,$f20
/*  f125edc:	c7a8016c */ 	lwc1	$f8,0x16c($sp)
/*  f125ee0:	c7aa0168 */ 	lwc1	$f10,0x168($sp)
/*  f125ee4:	e7ba0158 */ 	swc1	$f26,0x158($sp)
/*  f125ee8:	e7a4014c */ 	swc1	$f4,0x14c($sp)
/*  f125eec:	46184101 */ 	sub.s	$f4,$f8,$f24
/*  f125ef0:	e7ba015c */ 	swc1	$f26,0x15c($sp)
/*  f125ef4:	e7ba0160 */ 	swc1	$f26,0x160($sp)
/*  f125ef8:	46165181 */ 	sub.s	$f6,$f10,$f22
/*  f125efc:	e7a40154 */ 	swc1	$f4,0x154($sp)
/*  f125f00:	02802025 */ 	or	$a0,$s4,$zero
/*  f125f04:	02a02825 */ 	or	$a1,$s5,$zero
/*  f125f08:	0fc5c81a */ 	jal	func0f1773c8
/*  f125f0c:	e7a60150 */ 	swc1	$f6,0x150($sp)
/*  f125f10:	10400003 */ 	beqz	$v0,.NB0f125f20
/*  f125f14:	02202025 */ 	or	$a0,$s1,$zero
/*  f125f18:	0fc00704 */ 	jal	roomSetLightBroken
/*  f125f1c:	02002825 */ 	or	$a1,$s0,$zero
.NB0f125f20:
/*  f125f20:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f125f24:	5612ffdf */ 	bnel	$s0,$s2,.NB0f125ea4
/*  f125f28:	02202025 */ 	or	$a0,$s1,$zero
.NB0f125f2c:
/*  f125f2c:	86c2002a */ 	lh	$v0,0x2a($s6)
/*  f125f30:	2401ffff */ 	addiu	$at,$zero,-1
/*  f125f34:	26d60002 */ 	addiu	$s6,$s6,0x2
/*  f125f38:	1441ffbd */ 	bne	$v0,$at,.NB0f125e30
/*  f125f3c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f125f40:
/*  f125f40:	27b00198 */ 	addiu	$s0,$sp,0x198
/*  f125f44:	02002825 */ 	or	$a1,$s0,$zero
/*  f125f48:	26e40028 */ 	addiu	$a0,$s7,0x28
/*  f125f4c:	0fc1947a */ 	jal	roomGetProps
/*  f125f50:	24060100 */ 	addiu	$a2,$zero,0x100
/*  f125f54:	87aa0198 */ 	lh	$t2,0x198($sp)
/*  f125f58:	0200a025 */ 	or	$s4,$s0,$zero
/*  f125f5c:	27ab0198 */ 	addiu	$t3,$sp,0x198
/*  f125f60:	054001f0 */ 	bltz	$t2,.NB0f126724
/*  f125f64:	3c013f80 */ 	lui	$at,0x3f80
/*  f125f68:	4481f000 */ 	mtc1	$at,$f30
/*  f125f6c:	85620000 */ 	lh	$v0,0x0($t3)
/*  f125f70:	24160004 */ 	addiu	$s6,$zero,0x4
/*  f125f74:	24150003 */ 	addiu	$s5,$zero,0x3
/*  f125f78:	8fae03a0 */ 	lw	$t6,0x3a0($sp)
.NB0f125f7c:
/*  f125f7c:	8fcd0338 */ 	lw	$t5,0x338($s8)
/*  f125f80:	000260c0 */ 	sll	$t4,$v0,0x3
/*  f125f84:	8dd80004 */ 	lw	$t8,0x4($t6)
/*  f125f88:	01826021 */ 	addu	$t4,$t4,$v0
/*  f125f8c:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f125f90:	018d8021 */ 	addu	$s0,$t4,$t5
/*  f125f94:	521801e0 */ 	beql	$s0,$t8,.NB0f126718
/*  f125f98:	86820002 */ 	lh	$v0,0x2($s4)
/*  f125f9c:	86190002 */ 	lh	$t9,0x2($s0)
/*  f125fa0:	572001dd */ 	bnezl	$t9,.NB0f126718
/*  f125fa4:	86820002 */ 	lh	$v0,0x2($s4)
/*  f125fa8:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f125fac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f125fb0:	50410006 */ 	beql	$v0,$at,.NB0f125fcc
/*  f125fb4:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f125fb8:	12c20003 */ 	beq	$s6,$v0,.NB0f125fc8
/*  f125fbc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f125fc0:	14410102 */ 	bne	$v0,$at,.NB0f1263cc
/*  f125fc4:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f125fc8:
/*  f125fc8:	c60a0008 */ 	lwc1	$f10,0x8($s0)
.NB0f125fcc:
/*  f125fcc:	c6e60008 */ 	lwc1	$f6,0x8($s7)
/*  f125fd0:	c608000c */ 	lwc1	$f8,0xc($s0)
/*  f125fd4:	c6e4000c */ 	lwc1	$f4,0xc($s7)
/*  f125fd8:	46065501 */ 	sub.s	$f20,$f10,$f6
/*  f125fdc:	c6e60010 */ 	lwc1	$f6,0x10($s7)
/*  f125fe0:	c60a0010 */ 	lwc1	$f10,0x10($s0)
/*  f125fe4:	8e120004 */ 	lw	$s2,0x4($s0)
/*  f125fe8:	461aa03e */ 	c.le.s	$f20,$f26
/*  f125fec:	00008825 */ 	or	$s1,$zero,$zero
/*  f125ff0:	46044581 */ 	sub.s	$f22,$f8,$f4
/*  f125ff4:	45000024 */ 	bc1f	.NB0f126088
/*  f125ff8:	46065601 */ 	sub.s	$f24,$f10,$f6
/*  f125ffc:	4600d007 */ 	neg.s	$f0,$f26
/*  f126000:	4614003e */ 	c.le.s	$f0,$f20
/*  f126004:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126008:	4500001f */ 	bc1f	.NB0f126088
/*  f12600c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126010:	461ab03e */ 	c.le.s	$f22,$f26
/*  f126014:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126018:	4500001b */ 	bc1f	.NB0f126088
/*  f12601c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126020:	4616003e */ 	c.le.s	$f0,$f22
/*  f126024:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126028:	45000017 */ 	bc1f	.NB0f126088
/*  f12602c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126030:	461ac03e */ 	c.le.s	$f24,$f26
/*  f126034:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126038:	45000013 */ 	bc1f	.NB0f126088
/*  f12603c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126040:	4618003e */ 	c.le.s	$f0,$f24
/*  f126044:	02402025 */ 	or	$a0,$s2,$zero
/*  f126048:	27a50130 */ 	addiu	$a1,$sp,0x130
/*  f12604c:	4500000e */ 	bc1f	.NB0f126088
/*  f126050:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126054:	0fc24252 */ 	jal	func0f092304
/*  f126058:	27a60124 */ 	addiu	$a2,$sp,0x124
/*  f12605c:	10400009 */ 	beqz	$v0,.NB0f126084
/*  f126060:	8fa403a0 */ 	lw	$a0,0x3a0($sp)
/*  f126064:	02002825 */ 	or	$a1,$s0,$zero
/*  f126068:	27a60130 */ 	addiu	$a2,$sp,0x130
/*  f12606c:	0fc496be */ 	jal	func0f12af5c
/*  f126070:	27a70124 */ 	addiu	$a3,$sp,0x124
/*  f126074:	10400004 */ 	beqz	$v0,.NB0f126088
/*  f126078:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12607c:	10000002 */ 	beqz	$zero,.NB0f126088
/*  f126080:	24110001 */ 	addiu	$s1,$zero,0x1
.NB0f126084:
/*  f126084:	24110001 */ 	addiu	$s1,$zero,0x1
.NB0f126088:
/*  f126088:	1220000c */ 	beqz	$s1,.NB0f1260bc
/*  f12608c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126090:	92080000 */ 	lbu	$t0,0x0($s0)
/*  f126094:	16c80009 */ 	bne	$s6,$t0,.NB0f1260bc
/*  f126098:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12609c:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f1260a0:	10400006 */ 	beqz	$v0,.NB0f1260bc
/*  f1260a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1260a8:	9049005c */ 	lbu	$t1,0x5c($v0)
/*  f1260ac:	24010057 */ 	addiu	$at,$zero,0x57
/*  f1260b0:	15210002 */ 	bne	$t1,$at,.NB0f1260bc
/*  f1260b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1260b8:	a4400062 */ 	sh	$zero,0x62($v0)
.NB0f1260bc:
/*  f1260bc:	12200195 */ 	beqz	$s1,.NB0f126714
/*  f1260c0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1260c4:	461aa003 */ 	div.s	$f0,$f20,$f26
/*  f1260c8:	8faf039c */ 	lw	$t7,0x39c($sp)
/*  f1260cc:	8fc3029c */ 	lw	$v1,0x29c($s8)
/*  f1260d0:	8faa03a0 */ 	lw	$t2,0x3a0($sp)
/*  f1260d4:	8fae0194 */ 	lw	$t6,0x194($sp)
/*  f1260d8:	c5f00028 */ 	lwc1	$f16,0x28($t7)
/*  f1260dc:	461c003c */ 	c.lt.s	$f0,$f28
/*  f1260e0:	46000086 */ 	mov.s	$f2,$f0
/*  f1260e4:	45020003 */ 	bc1fl	.NB0f1260f4
/*  f1260e8:	461ab003 */ 	div.s	$f0,$f22,$f26
/*  f1260ec:	46000087 */ 	neg.s	$f2,$f0
/*  f1260f0:	461ab003 */ 	div.s	$f0,$f22,$f26
.NB0f1260f4:
/*  f1260f4:	4602f081 */ 	sub.s	$f2,$f30,$f2
/*  f1260f8:	461c003c */ 	c.lt.s	$f0,$f28
/*  f1260fc:	46000306 */ 	mov.s	$f12,$f0
/*  f126100:	45020003 */ 	bc1fl	.NB0f126110
/*  f126104:	461ac003 */ 	div.s	$f0,$f24,$f26
/*  f126108:	46000307 */ 	neg.s	$f12,$f0
/*  f12610c:	461ac003 */ 	div.s	$f0,$f24,$f26
.NB0f126110:
/*  f126110:	460cf301 */ 	sub.s	$f12,$f30,$f12
/*  f126114:	461c003c */ 	c.lt.s	$f0,$f28
/*  f126118:	46000386 */ 	mov.s	$f14,$f0
/*  f12611c:	45020003 */ 	bc1fl	.NB0f12612c
/*  f126120:	4602603c */ 	c.lt.s	$f12,$f2
/*  f126124:	46000387 */ 	neg.s	$f14,$f0
/*  f126128:	4602603c */ 	c.lt.s	$f12,$f2
.NB0f12612c:
/*  f12612c:	46001506 */ 	mov.s	$f20,$f2
/*  f126130:	460ef381 */ 	sub.s	$f14,$f30,$f14
/*  f126134:	45020003 */ 	bc1fl	.NB0f126144
/*  f126138:	4614703c */ 	c.lt.s	$f14,$f20
/*  f12613c:	46006506 */ 	mov.s	$f20,$f12
/*  f126140:	4614703c */ 	c.lt.s	$f14,$f20
.NB0f126144:
/*  f126144:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126148:	45000002 */ 	bc1f	.NB0f126154
/*  f12614c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126150:	46007506 */ 	mov.s	$f20,$f14
.NB0f126154:
/*  f126154:	c428facc */ 	lwc1	$f8,-0x534($at)
/*  f126158:	3c017f1b */ 	lui	$at,0x7f1b
/*  f12615c:	c42afad0 */ 	lwc1	$f10,-0x530($at)
/*  f126160:	4608a102 */ 	mul.s	$f4,$f20,$f8
/*  f126164:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f126168:	46103502 */ 	mul.s	$f20,$f6,$f16
/*  f12616c:	04600008 */ 	bltz	$v1,.NB0f126190
/*  f126170:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126174:	814b03ce */ 	lb	$t3,0x3ce($t2)
/*  f126178:	146b0005 */ 	bne	$v1,$t3,.NB0f126190
/*  f12617c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126180:	8e4c000c */ 	lw	$t4,0xc($s2)
/*  f126184:	318d0001 */ 	andi	$t5,$t4,0x1
/*  f126188:	55a00163 */ 	bnezl	$t5,.NB0f126718
/*  f12618c:	86820002 */ 	lh	$v0,0x2($s4)
.NB0f126190:
/*  f126190:	11c00060 */ 	beqz	$t6,.NB0f126314
/*  f126194:	02402025 */ 	or	$a0,$s2,$zero
/*  f126198:	0fc19653 */ 	jal	objUpdateLinkedScenery
/*  f12619c:	02e02825 */ 	or	$a1,$s7,$zero
/*  f1261a0:	8e420040 */ 	lw	$v0,0x40($s2)
/*  f1261a4:	30581000 */ 	andi	$t8,$v0,0x1000
/*  f1261a8:	57000023 */ 	bnezl	$t8,.NB0f126238
/*  f1261ac:	00025140 */ 	sll	$t2,$v0,0x5
/*  f1261b0:	8e59000c */ 	lw	$t9,0xc($s2)
/*  f1261b4:	3c010020 */ 	lui	$at,0x20
/*  f1261b8:	34210400 */ 	ori	$at,$at,0x400
/*  f1261bc:	03214024 */ 	and	$t0,$t9,$at
/*  f1261c0:	5500001d */ 	bnezl	$t0,.NB0f126238
/*  f1261c4:	00025140 */ 	sll	$t2,$v0,0x5
/*  f1261c8:	0c004d84 */ 	jal	random
/*  f1261cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1261d0:	44824000 */ 	mtc1	$v0,$f8
/*  f1261d4:	02002025 */ 	or	$a0,$s0,$zero
/*  f1261d8:	04410005 */ 	bgez	$v0,.NB0f1261f0
/*  f1261dc:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f1261e0:	3c014f80 */ 	lui	$at,0x4f80
/*  f1261e4:	44815000 */ 	mtc1	$at,$f10
/*  f1261e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1261ec:	460a2100 */ 	add.s	$f4,$f4,$f10
.NB0f1261f0:
/*  f1261f0:	3c012f80 */ 	lui	$at,0x2f80
/*  f1261f4:	44813000 */ 	mtc1	$at,$f6
/*  f1261f8:	3c013f00 */ 	lui	$at,0x3f00
/*  f1261fc:	44815000 */ 	mtc1	$at,$f10
/*  f126200:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f126204:	8fa903a0 */ 	lw	$t1,0x3a0($sp)
/*  f126208:	26060008 */ 	addiu	$a2,$s0,0x8
/*  f12620c:	24070022 */ 	addiu	$a3,$zero,0x22
/*  f126210:	812f03ce */ 	lb	$t7,0x3ce($t1)
/*  f126214:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f126218:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f12621c:	461e2180 */ 	add.s	$f6,$f4,$f30
/*  f126220:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f126224:	44054000 */ 	mfc1	$a1,$f8
/*  f126228:	0fc20e40 */ 	jal	func0f085050
/*  f12622c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126230:	8e420040 */ 	lw	$v0,0x40($s2)
/*  f126234:	00025140 */ 	sll	$t2,$v0,0x5
.NB0f126238:
/*  f126238:	05400136 */ 	bltz	$t2,.NB0f126714
/*  f12623c:	00025900 */ 	sll	$t3,$v0,0x4
/*  f126240:	05620135 */ 	bltzl	$t3,.NB0f126718
/*  f126244:	86820002 */ 	lh	$v0,0x2($s4)
/*  f126248:	8e4c0010 */ 	lw	$t4,0x10($s2)
/*  f12624c:	318d0001 */ 	andi	$t5,$t4,0x1
/*  f126250:	51a00131 */ 	beqzl	$t5,.NB0f126718
/*  f126254:	86820002 */ 	lh	$v0,0x2($s4)
/*  f126258:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f12625c:	c6e40008 */ 	lwc1	$f4,0x8($s7)
/*  f126260:	e7bc00f8 */ 	swc1	$f28,0xf8($sp)
/*  f126264:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f126268:	e7a600f4 */ 	swc1	$f6,0xf4($sp)
/*  f12626c:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
/*  f126270:	c6ea0010 */ 	lwc1	$f10,0x10($s7)
/*  f126274:	c6080010 */ 	lwc1	$f8,0x10($s0)
/*  f126278:	4606e032 */ 	c.eq.s	$f28,$f6
/*  f12627c:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f126280:	45000006 */ 	bc1f	.NB0f12629c
/*  f126284:	e7a400fc */ 	swc1	$f4,0xfc($sp)
/*  f126288:	c7a800fc */ 	lwc1	$f8,0xfc($sp)
/*  f12628c:	4608e032 */ 	c.eq.s	$f28,$f8
/*  f126290:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126294:	45030017 */ 	bc1tl	.NB0f1262f4
/*  f126298:	4406e000 */ 	mfc1	$a2,$f28
.NB0f12629c:
/*  f12629c:	c7aa00fc */ 	lwc1	$f10,0xfc($sp)
/*  f1262a0:	c7ae00f4 */ 	lwc1	$f14,0xf4($sp)
/*  f1262a4:	460a5102 */ 	mul.s	$f4,$f10,$f10
/*  f1262a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1262ac:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f1262b0:	0c012e84 */ 	jal	sqrtf
/*  f1262b4:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f1262b8:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f1262bc:	3c014080 */ 	lui	$at,0x4080
/*  f1262c0:	4502000c */ 	bc1fl	.NB0f1262f4
/*  f1262c4:	4406e000 */ 	mfc1	$a2,$f28
/*  f1262c8:	44814000 */ 	mtc1	$at,$f8
/*  f1262cc:	c7ae00f4 */ 	lwc1	$f14,0xf4($sp)
/*  f1262d0:	c7a400fc */ 	lwc1	$f4,0xfc($sp)
/*  f1262d4:	4608a282 */ 	mul.s	$f10,$f20,$f8
/*  f1262d8:	46005083 */ 	div.s	$f2,$f10,$f0
/*  f1262dc:	46027382 */ 	mul.s	$f14,$f14,$f2
/*  f1262e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1262e4:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f1262e8:	e7ae00f4 */ 	swc1	$f14,0xf4($sp)
/*  f1262ec:	e7a600fc */ 	swc1	$f6,0xfc($sp)
/*  f1262f0:	4406e000 */ 	mfc1	$a2,$f28
.NB0f1262f4:
/*  f1262f4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1262f8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1262fc:	02402025 */ 	or	$a0,$s2,$zero
/*  f126300:	27a500f4 */ 	addiu	$a1,$sp,0xf4
/*  f126304:	0fc20525 */ 	jal	func0f082a1c
/*  f126308:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f12630c:	10000102 */ 	beqz	$zero,.NB0f126718
/*  f126310:	86820002 */ 	lh	$v0,0x2($s4)
.NB0f126314:
/*  f126314:	0fc21481 */ 	jal	objIsHealthy
/*  f126318:	02402025 */ 	or	$a0,$s2,$zero
/*  f12631c:	104000fd */ 	beqz	$v0,.NB0f126714
/*  f126320:	3c017f1b */ 	lui	$at,0x7f1b
/*  f126324:	c428fad4 */ 	lwc1	$f8,-0x52c($at)
/*  f126328:	c7ca004c */ 	lwc1	$f10,0x4c($s8)
/*  f12632c:	8e580040 */ 	lw	$t8,0x40($s2)
/*  f126330:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f126334:	33191000 */ 	andi	$t9,$t8,0x1000
/*  f126338:	4604a502 */ 	mul.s	$f20,$f20,$f4
/*  f12633c:	572000f6 */ 	bnezl	$t9,.NB0f126718
/*  f126340:	86820002 */ 	lh	$v0,0x2($s4)
/*  f126344:	8e48000c */ 	lw	$t0,0xc($s2)
/*  f126348:	3c010020 */ 	lui	$at,0x20
/*  f12634c:	34210400 */ 	ori	$at,$at,0x400
/*  f126350:	01014824 */ 	and	$t1,$t0,$at
/*  f126354:	552000f0 */ 	bnezl	$t1,.NB0f126718
/*  f126358:	86820002 */ 	lh	$v0,0x2($s4)
/*  f12635c:	0c004d84 */ 	jal	random
/*  f126360:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126364:	44823000 */ 	mtc1	$v0,$f6
/*  f126368:	02002025 */ 	or	$a0,$s0,$zero
/*  f12636c:	04410005 */ 	bgez	$v0,.NB0f126384
/*  f126370:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f126374:	3c014f80 */ 	lui	$at,0x4f80
/*  f126378:	44815000 */ 	mtc1	$at,$f10
/*  f12637c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126380:	460a4200 */ 	add.s	$f8,$f8,$f10
.NB0f126384:
/*  f126384:	3c012f80 */ 	lui	$at,0x2f80
/*  f126388:	44812000 */ 	mtc1	$at,$f4
/*  f12638c:	3c013f00 */ 	lui	$at,0x3f00
/*  f126390:	44815000 */ 	mtc1	$at,$f10
/*  f126394:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f126398:	8faf03a0 */ 	lw	$t7,0x3a0($sp)
/*  f12639c:	26060008 */ 	addiu	$a2,$s0,0x8
/*  f1263a0:	24070022 */ 	addiu	$a3,$zero,0x22
/*  f1263a4:	81ea03ce */ 	lb	$t2,0x3ce($t7)
/*  f1263a8:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f1263ac:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f1263b0:	461e4100 */ 	add.s	$f4,$f8,$f30
/*  f1263b4:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f1263b8:	44053000 */ 	mfc1	$a1,$f6
/*  f1263bc:	0fc20e40 */ 	jal	func0f085050
/*  f1263c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1263c4:	100000d4 */ 	beqz	$zero,.NB0f126718
/*  f1263c8:	86820002 */ 	lh	$v0,0x2($s4)
.NB0f1263cc:
/*  f1263cc:	12a20003 */ 	beq	$s5,$v0,.NB0f1263dc
/*  f1263d0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f1263d4:	544100d0 */ 	bnel	$v0,$at,.NB0f126718
/*  f1263d8:	86820002 */ 	lh	$v0,0x2($s4)
.NB0f1263dc:
/*  f1263dc:	c60a0008 */ 	lwc1	$f10,0x8($s0)
/*  f1263e0:	c6e80008 */ 	lwc1	$f8,0x8($s7)
/*  f1263e4:	c604000c */ 	lwc1	$f4,0xc($s0)
/*  f1263e8:	c6e6000c */ 	lwc1	$f6,0xc($s7)
/*  f1263ec:	46085581 */ 	sub.s	$f22,$f10,$f8
/*  f1263f0:	c6e80010 */ 	lwc1	$f8,0x10($s7)
/*  f1263f4:	c60a0010 */ 	lwc1	$f10,0x10($s0)
/*  f1263f8:	00008825 */ 	or	$s1,$zero,$zero
/*  f1263fc:	461ab03e */ 	c.le.s	$f22,$f26
/*  f126400:	46062501 */ 	sub.s	$f20,$f4,$f6
/*  f126404:	4500003d */ 	bc1f	.NB0f1264fc
/*  f126408:	46085601 */ 	sub.s	$f24,$f10,$f8
/*  f12640c:	4600d007 */ 	neg.s	$f0,$f26
/*  f126410:	4616003e */ 	c.le.s	$f0,$f22
/*  f126414:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126418:	45000038 */ 	bc1f	.NB0f1264fc
/*  f12641c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126420:	461aa03e */ 	c.le.s	$f20,$f26
/*  f126424:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126428:	45000034 */ 	bc1f	.NB0f1264fc
/*  f12642c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126430:	4614003e */ 	c.le.s	$f0,$f20
/*  f126434:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126438:	45000030 */ 	bc1f	.NB0f1264fc
/*  f12643c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126440:	461ac03e */ 	c.le.s	$f24,$f26
/*  f126444:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126448:	4500002c */ 	bc1f	.NB0f1264fc
/*  f12644c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126450:	4618003e */ 	c.le.s	$f0,$f24
/*  f126454:	02002025 */ 	or	$a0,$s0,$zero
/*  f126458:	27a500e0 */ 	addiu	$a1,$sp,0xe0
/*  f12645c:	27a600dc */ 	addiu	$a2,$sp,0xdc
/*  f126460:	45000026 */ 	bc1f	.NB0f1264fc
/*  f126464:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126468:	0fc1951b */ 	jal	propGetBbox
/*  f12646c:	27a700d8 */ 	addiu	$a3,$sp,0xd8
/*  f126470:	3c0141a0 */ 	lui	$at,0x41a0
/*  f126474:	c7a000e0 */ 	lwc1	$f0,0xe0($sp)
/*  f126478:	44812000 */ 	mtc1	$at,$f4
/*  f12647c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126480:	46040001 */ 	sub.s	$f0,$f0,$f4
/*  f126484:	461c003e */ 	c.le.s	$f0,$f28
/*  f126488:	e7a000e0 */ 	swc1	$f0,0xe0($sp)
/*  f12648c:	45020003 */ 	bc1fl	.NB0f12649c
/*  f126490:	c6060008 */ 	lwc1	$f6,0x8($s0)
/*  f126494:	e7bc00e0 */ 	swc1	$f28,0xe0($sp)
/*  f126498:	c6060008 */ 	lwc1	$f6,0x8($s0)
.NB0f12649c:
/*  f12649c:	c7aa00e0 */ 	lwc1	$f10,0xe0($sp)
/*  f1264a0:	c7a400d8 */ 	lwc1	$f4,0xd8($sp)
/*  f1264a4:	8fa403a0 */ 	lw	$a0,0x3a0($sp)
/*  f1264a8:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*  f1264ac:	e7a400d0 */ 	swc1	$f4,0xd0($sp)
/*  f1264b0:	02002825 */ 	or	$a1,$s0,$zero
/*  f1264b4:	27a600cc */ 	addiu	$a2,$sp,0xcc
/*  f1264b8:	e7a800cc */ 	swc1	$f8,0xcc($sp)
/*  f1264bc:	c6060010 */ 	lwc1	$f6,0x10($s0)
/*  f1264c0:	27a700c0 */ 	addiu	$a3,$sp,0xc0
/*  f1264c4:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*  f1264c8:	e7a800d4 */ 	swc1	$f8,0xd4($sp)
/*  f1264cc:	c6040008 */ 	lwc1	$f4,0x8($s0)
/*  f1264d0:	c7a800dc */ 	lwc1	$f8,0xdc($sp)
/*  f1264d4:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f1264d8:	e7a800c4 */ 	swc1	$f8,0xc4($sp)
/*  f1264dc:	e7a600c0 */ 	swc1	$f6,0xc0($sp)
/*  f1264e0:	c6040010 */ 	lwc1	$f4,0x10($s0)
/*  f1264e4:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f1264e8:	0fc496be */ 	jal	func0f12af5c
/*  f1264ec:	e7a600c8 */ 	swc1	$f6,0xc8($sp)
/*  f1264f0:	10400002 */ 	beqz	$v0,.NB0f1264fc
/*  f1264f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1264f8:	24110001 */ 	addiu	$s1,$zero,0x1
.NB0f1264fc:
/*  f1264fc:	52200086 */ 	beqzl	$s1,.NB0f126718
/*  f126500:	86820002 */ 	lh	$v0,0x2($s4)
/*  f126504:	461ab083 */ 	div.s	$f2,$f22,$f26
/*  f126508:	3c0c8008 */ 	lui	$t4,0x8008
/*  f12650c:	258c1190 */ 	addiu	$t4,$t4,0x1190
/*  f126510:	8d810000 */ 	lw	$at,0x0($t4)
/*  f126514:	27ab00a0 */ 	addiu	$t3,$sp,0xa0
/*  f126518:	8d8e0004 */ 	lw	$t6,0x4($t4)
/*  f12651c:	ad610000 */ 	sw	$at,0x0($t3)
/*  f126520:	8d810008 */ 	lw	$at,0x8($t4)
/*  f126524:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f126528:	00008825 */ 	or	$s1,$zero,$zero
/*  f12652c:	ad610008 */ 	sw	$at,0x8($t3)
/*  f126530:	8e120004 */ 	lw	$s2,0x4($s0)
/*  f126534:	26f30008 */ 	addiu	$s3,$s7,0x8
/*  f126538:	461aa383 */ 	div.s	$f14,$f20,$f26
/*  f12653c:	46001006 */ 	mov.s	$f0,$f2
/*  f126540:	461c103c */ 	c.lt.s	$f2,$f28
/*  f126544:	461ac483 */ 	div.s	$f18,$f24,$f26
/*  f126548:	46007306 */ 	mov.s	$f12,$f14
/*  f12654c:	45000002 */ 	bc1f	.NB0f126558
/*  f126550:	46009406 */ 	mov.s	$f16,$f18
/*  f126554:	46001007 */ 	neg.s	$f0,$f2
.NB0f126558:
/*  f126558:	461c703c */ 	c.lt.s	$f14,$f28
/*  f12655c:	4600f501 */ 	sub.s	$f20,$f30,$f0
/*  f126560:	45020003 */ 	bc1fl	.NB0f126570
/*  f126564:	461c903c */ 	c.lt.s	$f18,$f28
/*  f126568:	46007307 */ 	neg.s	$f12,$f14
/*  f12656c:	461c903c */ 	c.lt.s	$f18,$f28
.NB0f126570:
/*  f126570:	460cf301 */ 	sub.s	$f12,$f30,$f12
/*  f126574:	45020003 */ 	bc1fl	.NB0f126584
/*  f126578:	4614603c */ 	c.lt.s	$f12,$f20
/*  f12657c:	46009407 */ 	neg.s	$f16,$f18
/*  f126580:	4614603c */ 	c.lt.s	$f12,$f20
.NB0f126584:
/*  f126584:	4610f401 */ 	sub.s	$f16,$f30,$f16
/*  f126588:	45020003 */ 	bc1fl	.NB0f126598
/*  f12658c:	4614803c */ 	c.lt.s	$f16,$f20
/*  f126590:	46006506 */ 	mov.s	$f20,$f12
/*  f126594:	4614803c */ 	c.lt.s	$f16,$f20
.NB0f126598:
/*  f126598:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12659c:	45000002 */ 	bc1f	.NB0f1265a8
/*  f1265a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1265a4:	46008506 */ 	mov.s	$f20,$f16
.NB0f1265a8:
/*  f1265a8:	4614a502 */ 	mul.s	$f20,$f20,$f20
/*  f1265ac:	8fb8039c */ 	lw	$t8,0x39c($sp)
/*  f1265b0:	3c014100 */ 	lui	$at,0x4100
/*  f1265b4:	44815000 */ 	mtc1	$at,$f10
/*  f1265b8:	c7080028 */ 	lwc1	$f8,0x28($t8)
/*  f1265bc:	8fb90194 */ 	lw	$t9,0x194($sp)
/*  f1265c0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1265c4:	46144102 */ 	mul.s	$f4,$f8,$f20
/*  f1265c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1265cc:	460a2502 */ 	mul.s	$f20,$f4,$f10
/*  f1265d0:	1320001a */ 	beqz	$t9,.NB0f12663c
/*  f1265d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1265d8:	461cb032 */ 	c.eq.s	$f22,$f28
/*  f1265dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1265e0:	45000005 */ 	bc1f	.NB0f1265f8
/*  f1265e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1265e8:	461cc032 */ 	c.eq.s	$f24,$f28
/*  f1265ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1265f0:	45030019 */ 	bc1tl	.NB0f126658
/*  f1265f4:	8fc80318 */ 	lw	$t0,0x318($s8)
.NB0f1265f8:
/*  f1265f8:	4616b182 */ 	mul.s	$f6,$f22,$f22
/*  f1265fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126600:	4618c202 */ 	mul.s	$f8,$f24,$f24
/*  f126604:	0c012e84 */ 	jal	sqrtf
/*  f126608:	46083300 */ 	add.s	$f12,$f6,$f8
/*  f12660c:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f126610:	00000000 */ 	sll	$zero,$zero,0x0
/*  f126614:	45020010 */ 	bc1fl	.NB0f126658
/*  f126618:	8fc80318 */ 	lw	$t0,0x318($s8)
/*  f12661c:	4600f083 */ 	div.s	$f2,$f30,$f0
/*  f126620:	e7bc00a4 */ 	swc1	$f28,0xa4($sp)
/*  f126624:	4602b582 */ 	mul.s	$f22,$f22,$f2
/*  f126628:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12662c:	4602c602 */ 	mul.s	$f24,$f24,$f2
/*  f126630:	e7b600a0 */ 	swc1	$f22,0xa0($sp)
/*  f126634:	10000007 */ 	beqz	$zero,.NB0f126654
/*  f126638:	e7b800a8 */ 	swc1	$f24,0xa8($sp)
.NB0f12663c:
/*  f12663c:	c424fad8 */ 	lwc1	$f4,-0x528($at)
/*  f126640:	c7ca004c */ 	lwc1	$f10,0x4c($s8)
/*  f126644:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f126648:	00000000 */ 	sll	$zero,$zero,0x0
/*  f12664c:	4606a502 */ 	mul.s	$f20,$f20,$f6
/*  f126650:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f126654:
/*  f126654:	8fc80318 */ 	lw	$t0,0x318($s8)
.NB0f126658:
/*  f126658:	8fa903a0 */ 	lw	$t1,0x3a0($sp)
/*  f12665c:	8faf03a0 */ 	lw	$t7,0x3a0($sp)
/*  f126660:	51000008 */ 	beqzl	$t0,.NB0f126684
/*  f126664:	81e203ce */ 	lb	$v0,0x3ce($t7)
/*  f126668:	0fc61c91 */ 	jal	mpGetChrFromPlayerIndex
/*  f12666c:	812403ce */ 	lb	$a0,0x3ce($t1)
/*  f126670:	5040001a */ 	beqzl	$v0,.NB0f1266dc
/*  f126674:	4405a000 */ 	mfc1	$a1,$f20
/*  f126678:	10000017 */ 	beqz	$zero,.NB0f1266d8
/*  f12667c:	8c51001c */ 	lw	$s1,0x1c($v0)
/*  f126680:	81e203ce */ 	lb	$v0,0x3ce($t7)
.NB0f126684:
/*  f126684:	8fca0294 */ 	lw	$t2,0x294($s8)
/*  f126688:	55420005 */ 	bnel	$t2,$v0,.NB0f1266a0
/*  f12668c:	8fc30298 */ 	lw	$v1,0x298($s8)
/*  f126690:	8fcd02a0 */ 	lw	$t5,0x2a0($s8)
/*  f126694:	10000010 */ 	beqz	$zero,.NB0f1266d8
/*  f126698:	8db100bc */ 	lw	$s1,0xbc($t5)
/*  f12669c:	8fc30298 */ 	lw	$v1,0x298($s8)
.NB0f1266a0:
/*  f1266a0:	04620007 */ 	bltzl	$v1,.NB0f1266c0
/*  f1266a4:	8fc3029c */ 	lw	$v1,0x29c($s8)
/*  f1266a8:	54620005 */ 	bnel	$v1,$v0,.NB0f1266c0
/*  f1266ac:	8fc3029c */ 	lw	$v1,0x29c($s8)
/*  f1266b0:	8fcb02a4 */ 	lw	$t3,0x2a4($s8)
/*  f1266b4:	10000008 */ 	beqz	$zero,.NB0f1266d8
/*  f1266b8:	8d7100bc */ 	lw	$s1,0xbc($t3)
/*  f1266bc:	8fc3029c */ 	lw	$v1,0x29c($s8)
.NB0f1266c0:
/*  f1266c0:	04620006 */ 	bltzl	$v1,.NB0f1266dc
/*  f1266c4:	4405a000 */ 	mfc1	$a1,$f20
/*  f1266c8:	54620004 */ 	bnel	$v1,$v0,.NB0f1266dc
/*  f1266cc:	4405a000 */ 	mfc1	$a1,$f20
/*  f1266d0:	8fcc02a8 */ 	lw	$t4,0x2a8($s8)
/*  f1266d4:	8d9100bc */ 	lw	$s1,0xbc($t4)
.NB0f1266d8:
/*  f1266d8:	4405a000 */ 	mfc1	$a1,$f20
.NB0f1266dc:
/*  f1266dc:	02402025 */ 	or	$a0,$s2,$zero
/*  f1266e0:	27a600a0 */ 	addiu	$a2,$sp,0xa0
/*  f1266e4:	02203825 */ 	or	$a3,$s1,$zero
/*  f1266e8:	0fc0cf46 */ 	jal	func0f034410
/*  f1266ec:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f1266f0:	920e0000 */ 	lbu	$t6,0x0($s0)
/*  f1266f4:	8fb80194 */ 	lw	$t8,0x194($sp)
/*  f1266f8:	56ae0007 */ 	bnel	$s5,$t6,.NB0f126718
/*  f1266fc:	86820002 */ 	lh	$v0,0x2($s4)
/*  f126700:	17000004 */ 	bnez	$t8,.NB0f126714
/*  f126704:	02402025 */ 	or	$a0,$s2,$zero
/*  f126708:	4406d000 */ 	mfc1	$a2,$f26
/*  f12670c:	0fc09ac4 */ 	jal	func0f0270f4
/*  f126710:	02602825 */ 	or	$a1,$s3,$zero
.NB0f126714:
/*  f126714:	86820002 */ 	lh	$v0,0x2($s4)
.NB0f126718:
/*  f126718:	26940002 */ 	addiu	$s4,$s4,0x2
/*  f12671c:	0443fe17 */ 	bgezl	$v0,.NB0f125f7c
/*  f126720:	8fae03a0 */ 	lw	$t6,0x3a0($sp)
.NB0f126724:
/*  f126724:	8fbf0074 */ 	lw	$ra,0x74($sp)
.NB0f126728:
/*  f126728:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f12672c:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f126730:	d7b80030 */ 	ldc1	$f24,0x30($sp)
/*  f126734:	d7ba0038 */ 	ldc1	$f26,0x38($sp)
/*  f126738:	d7bc0040 */ 	ldc1	$f28,0x40($sp)
/*  f12673c:	d7be0048 */ 	ldc1	$f30,0x48($sp)
/*  f126740:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f126744:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f126748:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f12674c:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f126750:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f126754:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f126758:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f12675c:	8fb7006c */ 	lw	$s7,0x6c($sp)
/*  f126760:	8fbe0070 */ 	lw	$s8,0x70($sp)
/*  f126764:	03e00008 */ 	jr	$ra
/*  f126768:	27bd03a8 */ 	addiu	$sp,$sp,0x3a8
);
#endif

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f12bbdc
.late_rodata
glabel var7f1b68a4pf
.word 0x40c907a9
glabel var7f1b68a8pf
.word 0x3e4ccccd
glabel var7f1b68acpf
.word 0x3f4ccccd
glabel var7f1b68b0pf
.word 0x3f555555
.text
/*  f12c6e0:	27bdfe98 */ 	addiu	$sp,$sp,-360
/*  f12c6e4:	afbf0084 */ 	sw	$ra,0x84($sp)
/*  f12c6e8:	afb70080 */ 	sw	$s7,0x80($sp)
/*  f12c6ec:	afb6007c */ 	sw	$s6,0x7c($sp)
/*  f12c6f0:	afb50078 */ 	sw	$s5,0x78($sp)
/*  f12c6f4:	afb40074 */ 	sw	$s4,0x74($sp)
/*  f12c6f8:	afb30070 */ 	sw	$s3,0x70($sp)
/*  f12c6fc:	afb2006c */ 	sw	$s2,0x6c($sp)
/*  f12c700:	afb10068 */ 	sw	$s1,0x68($sp)
/*  f12c704:	afb00064 */ 	sw	$s0,0x64($sp)
/*  f12c708:	f7b60058 */ 	sdc1	$f22,0x58($sp)
/*  f12c70c:	f7b40050 */ 	sdc1	$f20,0x50($sp)
/*  f12c710:	8c910004 */ 	lw	$s1,0x4($a0)
/*  f12c714:	3c188008 */ 	lui	$t8,0x8008
/*  f12c718:	2718e988 */ 	addiu	$t8,$t8,-5752
/*  f12c71c:	822e03cc */ 	lb	$t6,0x3cc($s1)
/*  f12c720:	2401003c */ 	li	$at,0x3c
/*  f12c724:	3c15800a */ 	lui	$s5,0x800a
/*  f12c728:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f12c72c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f12c730:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f12c734:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f12c738:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f12c73c:	01f8b021 */ 	addu	$s6,$t7,$t8
/*  f12c740:	86d9001c */ 	lh	$t9,0x1c($s6)
/*  f12c744:	26b5a510 */ 	addiu	$s5,$s5,-23280
/*  f12c748:	8ea20038 */ 	lw	$v0,0x38($s5)
/*  f12c74c:	00194080 */ 	sll	$t0,$t9,0x2
/*  f12c750:	01194023 */ 	subu	$t0,$t0,$t9
/*  f12c754:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f12c758:	01194021 */ 	addu	$t0,$t0,$t9
/*  f12c75c:	00084040 */ 	sll	$t0,$t0,0x1
/*  f12c760:	0101001a */ 	div	$zero,$t0,$at
/*  f12c764:	00004812 */ 	mflo	$t1
/*  f12c768:	0080b825 */ 	move	$s7,$a0
/*  f12c76c:	14400003 */ 	bnez	$v0,.PF0f12c77c
/*  f12c770:	a7a9012e */ 	sh	$t1,0x12e($sp)
/*  f12c774:	1000024b */ 	b	.PF0f12d0a4
/*  f12c778:	00001025 */ 	move	$v0,$zero
.PF0f12c77c:
/*  f12c77c:	2841000c */ 	slti	$at,$v0,0xc
/*  f12c780:	50200007 */ 	beqzl	$at,.PF0f12c7a0
/*  f12c784:	3c014140 */ 	lui	$at,0x4140
/*  f12c788:	44822000 */ 	mtc1	$v0,$f4
/*  f12c78c:	00000000 */ 	nop
/*  f12c790:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f12c794:	10000005 */ 	b	.PF0f12c7ac
/*  f12c798:	e7a60148 */ 	swc1	$f6,0x148($sp)
/*  f12c79c:	3c014140 */ 	lui	$at,0x4140
.PF0f12c7a0:
/*  f12c7a0:	44814000 */ 	mtc1	$at,$f8
/*  f12c7a4:	00000000 */ 	nop
/*  f12c7a8:	e7a80148 */ 	swc1	$f8,0x148($sp)
.PF0f12c7ac:
/*  f12c7ac:	862603c8 */ 	lh	$a2,0x3c8($s1)
/*  f12c7b0:	87aa012e */ 	lh	$t2,0x12e($sp)
/*  f12c7b4:	28c10007 */ 	slti	$at,$a2,0x7
/*  f12c7b8:	14200141 */ 	bnez	$at,.PF0f12ccc0
/*  f12c7bc:	00ca082a */ 	slt	$at,$a2,$t2
/*  f12c7c0:	1020013f */ 	beqz	$at,.PF0f12ccc0
/*  f12c7c4:	02202025 */ 	move	$a0,$s1
/*  f12c7c8:	0fc4a976 */ 	jal	explosionGetHorizontalRangeAtFrame
/*  f12c7cc:	00c02825 */ 	move	$a1,$a2
/*  f12c7d0:	46000506 */ 	mov.s	$f20,$f0
/*  f12c7d4:	02202025 */ 	move	$a0,$s1
/*  f12c7d8:	0fc4a9a0 */ 	jal	explosionGetVerticalRangeAtFrame
/*  f12c7dc:	862503c8 */ 	lh	$a1,0x3c8($s1)
/*  f12c7e0:	3c013f00 */ 	lui	$at,0x3f00
/*  f12c7e4:	44815000 */ 	mtc1	$at,$f10
/*  f12c7e8:	c6f20008 */ 	lwc1	$f18,0x8($s7)
/*  f12c7ec:	44813000 */ 	mtc1	$at,$f6
/*  f12c7f0:	460aa082 */ 	mul.s	$f2,$f20,$f10
/*  f12c7f4:	2401000e */ 	li	$at,0xe
/*  f12c7f8:	46060302 */ 	mul.s	$f12,$f0,$f6
/*  f12c7fc:	46029101 */ 	sub.s	$f4,$f18,$f2
/*  f12c800:	e7a4011c */ 	swc1	$f4,0x11c($sp)
/*  f12c804:	c6e8000c */ 	lwc1	$f8,0xc($s7)
/*  f12c808:	460c4281 */ 	sub.s	$f10,$f8,$f12
/*  f12c80c:	e7aa0120 */ 	swc1	$f10,0x120($sp)
/*  f12c810:	c6f20010 */ 	lwc1	$f18,0x10($s7)
/*  f12c814:	46029101 */ 	sub.s	$f4,$f18,$f2
/*  f12c818:	e7a40124 */ 	swc1	$f4,0x124($sp)
/*  f12c81c:	c6e60008 */ 	lwc1	$f6,0x8($s7)
/*  f12c820:	46023200 */ 	add.s	$f8,$f6,$f2
/*  f12c824:	e7a80110 */ 	swc1	$f8,0x110($sp)
/*  f12c828:	c6ea000c */ 	lwc1	$f10,0xc($s7)
/*  f12c82c:	460c5480 */ 	add.s	$f18,$f10,$f12
/*  f12c830:	e7b20114 */ 	swc1	$f18,0x114($sp)
/*  f12c834:	c6e40010 */ 	lwc1	$f4,0x10($s7)
/*  f12c838:	46022180 */ 	add.s	$f6,$f4,$f2
/*  f12c83c:	e7a60118 */ 	swc1	$f6,0x118($sp)
/*  f12c840:	822b03cc */ 	lb	$t3,0x3cc($s1)
/*  f12c844:	5561000c */ 	bnel	$t3,$at,.PF0f12c878
/*  f12c848:	862603c8 */ 	lh	$a2,0x3c8($s1)
/*  f12c84c:	862c03c8 */ 	lh	$t4,0x3c8($s1)
/*  f12c850:	c7aa0148 */ 	lwc1	$f10,0x148($sp)
/*  f12c854:	2981001a */ 	slti	$at,$t4,0x1a
/*  f12c858:	10200006 */ 	beqz	$at,.PF0f12c874
/*  f12c85c:	3c014140 */ 	lui	$at,0x4140
/*  f12c860:	44814000 */ 	mtc1	$at,$f8
/*  f12c864:	c6e4000c */ 	lwc1	$f4,0xc($s7)
/*  f12c868:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f12c86c:	46122180 */ 	add.s	$f6,$f4,$f18
/*  f12c870:	e6e6000c */ 	swc1	$f6,0xc($s7)
.PF0f12c874:
/*  f12c874:	862603c8 */ 	lh	$a2,0x3c8($s1)
.PF0f12c878:
/*  f12c878:	86cd001e */ 	lh	$t5,0x1e($s6)
/*  f12c87c:	87ae012e */ 	lh	$t6,0x12e($sp)
/*  f12c880:	44862000 */ 	mtc1	$a2,$f4
/*  f12c884:	448d4000 */ 	mtc1	$t5,$f8
/*  f12c888:	0000a025 */ 	move	$s4,$zero
/*  f12c88c:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f12c890:	3c012f80 */ 	lui	$at,0x2f80
/*  f12c894:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f12c898:	448e4000 */ 	mtc1	$t6,$f8
/*  f12c89c:	00000000 */ 	nop
/*  f12c8a0:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f12c8a4:	46125182 */ 	mul.s	$f6,$f10,$f18
/*  f12c8a8:	46043283 */ 	div.s	$f10,$f6,$f4
/*  f12c8ac:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f12c8b0:	44189000 */ 	mfc1	$t8,$f18
/*  f12c8b4:	00000000 */ 	nop
/*  f12c8b8:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f12c8bc:	1b200100 */ 	blez	$t9,.PF0f12ccc0
/*  f12c8c0:	afb90128 */ 	sw	$t9,0x128($sp)
/*  f12c8c4:	4481b000 */ 	mtc1	$at,$f22
/*  f12c8c8:	3c013f80 */ 	lui	$at,0x3f80
/*  f12c8cc:	4481a000 */ 	mtc1	$at,$f20
/*  f12c8d0:	24120028 */ 	li	$s2,0x28
/*  f12c8d4:	00001825 */ 	move	$v1,$zero
.PF0f12c8d8:
/*  f12c8d8:	02208025 */ 	move	$s0,$s1
.PF0f12c8dc:
/*  f12c8dc:	8608001c */ 	lh	$t0,0x1c($s0)
/*  f12c8e0:	550000f0 */ 	bnezl	$t0,.PF0f12cca4
/*  f12c8e4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f12c8e8:	922403cf */ 	lbu	$a0,0x3cf($s1)
/*  f12c8ec:	50800006 */ 	beqzl	$a0,.PF0f12c908
/*  f12c8f0:	c7a00120 */ 	lwc1	$f0,0x120($sp)
/*  f12c8f4:	822903cc */ 	lb	$t1,0x3cc($s1)
/*  f12c8f8:	24010019 */ 	li	$at,0x19
/*  f12c8fc:	1521000f */ 	bne	$t1,$at,.PF0f12c93c
/*  f12c900:	00000000 */ 	nop
/*  f12c904:	c7a00120 */ 	lwc1	$f0,0x120($sp)
.PF0f12c908:
/*  f12c908:	c7a20124 */ 	lwc1	$f2,0x124($sp)
/*  f12c90c:	c7ac0110 */ 	lwc1	$f12,0x110($sp)
/*  f12c910:	c7ae0114 */ 	lwc1	$f14,0x114($sp)
/*  f12c914:	c7b00118 */ 	lwc1	$f16,0x118($sp)
/*  f12c918:	c7a8011c */ 	lwc1	$f8,0x11c($sp)
/*  f12c91c:	00009825 */ 	move	$s3,$zero
/*  f12c920:	e7a00100 */ 	swc1	$f0,0x100($sp)
/*  f12c924:	e7a20104 */ 	swc1	$f2,0x104($sp)
/*  f12c928:	e7ac00f0 */ 	swc1	$f12,0xf0($sp)
/*  f12c92c:	e7ae00f4 */ 	swc1	$f14,0xf4($sp)
/*  f12c930:	e7b000f8 */ 	swc1	$f16,0xf8($sp)
/*  f12c934:	10000089 */ 	b	.PF0f12cb5c
/*  f12c938:	e7a800fc */ 	swc1	$f8,0xfc($sp)
.PF0f12c93c:
/*  f12c93c:	0064001a */ 	div	$zero,$v1,$a0
/*  f12c940:	00009810 */ 	mfhi	$s3
/*  f12c944:	001350c0 */ 	sll	$t2,$s3,0x3
/*  f12c948:	01535023 */ 	subu	$t2,$t2,$s3
/*  f12c94c:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f12c950:	022a1021 */ 	addu	$v0,$s1,$t2
/*  f12c954:	c44603e8 */ 	lwc1	$f6,0x3e8($v0)
/*  f12c958:	14800002 */ 	bnez	$a0,.PF0f12c964
/*  f12c95c:	00000000 */ 	nop
/*  f12c960:	0007000d */ 	break	0x7
.PF0f12c964:
/*  f12c964:	2401ffff */ 	li	$at,-1
/*  f12c968:	14810004 */ 	bne	$a0,$at,.PF0f12c97c
/*  f12c96c:	3c018000 */ 	lui	$at,0x8000
/*  f12c970:	14610002 */ 	bne	$v1,$at,.PF0f12c97c
/*  f12c974:	00000000 */ 	nop
/*  f12c978:	0006000d */ 	break	0x6
.PF0f12c97c:
/*  f12c97c:	e7a600fc */ 	swc1	$f6,0xfc($sp)
/*  f12c980:	c44403ec */ 	lwc1	$f4,0x3ec($v0)
/*  f12c984:	e7a40100 */ 	swc1	$f4,0x100($sp)
/*  f12c988:	c44a03f0 */ 	lwc1	$f10,0x3f0($v0)
/*  f12c98c:	c7a400fc */ 	lwc1	$f4,0xfc($sp)
/*  f12c990:	e7aa0104 */ 	swc1	$f10,0x104($sp)
/*  f12c994:	c45203f4 */ 	lwc1	$f18,0x3f4($v0)
/*  f12c998:	c7aa011c */ 	lwc1	$f10,0x11c($sp)
/*  f12c99c:	e7b200f0 */ 	swc1	$f18,0xf0($sp)
/*  f12c9a0:	c44803f8 */ 	lwc1	$f8,0x3f8($v0)
/*  f12c9a4:	460a203c */ 	c.lt.s	$f4,$f10
/*  f12c9a8:	e7a800f4 */ 	swc1	$f8,0xf4($sp)
/*  f12c9ac:	c44603fc */ 	lwc1	$f6,0x3fc($v0)
/*  f12c9b0:	45000002 */ 	bc1f	.PF0f12c9bc
/*  f12c9b4:	e7a600f8 */ 	swc1	$f6,0xf8($sp)
/*  f12c9b8:	e7aa00fc */ 	swc1	$f10,0xfc($sp)
.PF0f12c9bc:
/*  f12c9bc:	c7a00120 */ 	lwc1	$f0,0x120($sp)
/*  f12c9c0:	c7b20100 */ 	lwc1	$f18,0x100($sp)
/*  f12c9c4:	4600903c */ 	c.lt.s	$f18,$f0
/*  f12c9c8:	00000000 */ 	nop
/*  f12c9cc:	45020003 */ 	bc1fl	.PF0f12c9dc
/*  f12c9d0:	c7a20124 */ 	lwc1	$f2,0x124($sp)
/*  f12c9d4:	e7a00100 */ 	swc1	$f0,0x100($sp)
/*  f12c9d8:	c7a20124 */ 	lwc1	$f2,0x124($sp)
.PF0f12c9dc:
/*  f12c9dc:	c7a80104 */ 	lwc1	$f8,0x104($sp)
/*  f12c9e0:	4602403c */ 	c.lt.s	$f8,$f2
/*  f12c9e4:	00000000 */ 	nop
/*  f12c9e8:	45020003 */ 	bc1fl	.PF0f12c9f8
/*  f12c9ec:	c7ac0110 */ 	lwc1	$f12,0x110($sp)
/*  f12c9f0:	e7a20104 */ 	swc1	$f2,0x104($sp)
/*  f12c9f4:	c7ac0110 */ 	lwc1	$f12,0x110($sp)
.PF0f12c9f8:
/*  f12c9f8:	c7a600f0 */ 	lwc1	$f6,0xf0($sp)
/*  f12c9fc:	4606603c */ 	c.lt.s	$f12,$f6
/*  f12ca00:	00000000 */ 	nop
/*  f12ca04:	45020003 */ 	bc1fl	.PF0f12ca14
/*  f12ca08:	c7ae0114 */ 	lwc1	$f14,0x114($sp)
/*  f12ca0c:	e7ac00f0 */ 	swc1	$f12,0xf0($sp)
/*  f12ca10:	c7ae0114 */ 	lwc1	$f14,0x114($sp)
.PF0f12ca14:
/*  f12ca14:	c7a400f4 */ 	lwc1	$f4,0xf4($sp)
/*  f12ca18:	4604703c */ 	c.lt.s	$f14,$f4
/*  f12ca1c:	00000000 */ 	nop
/*  f12ca20:	45020003 */ 	bc1fl	.PF0f12ca30
/*  f12ca24:	c7b00118 */ 	lwc1	$f16,0x118($sp)
/*  f12ca28:	e7ae00f4 */ 	swc1	$f14,0xf4($sp)
/*  f12ca2c:	c7b00118 */ 	lwc1	$f16,0x118($sp)
.PF0f12ca30:
/*  f12ca30:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f12ca34:	460a803c */ 	c.lt.s	$f16,$f10
/*  f12ca38:	00000000 */ 	nop
/*  f12ca3c:	45020003 */ 	bc1fl	.PF0f12ca4c
/*  f12ca40:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
/*  f12ca44:	e7b000f8 */ 	swc1	$f16,0xf8($sp)
/*  f12ca48:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
.PF0f12ca4c:
/*  f12ca4c:	c7a800f0 */ 	lwc1	$f8,0xf0($sp)
/*  f12ca50:	c7a60100 */ 	lwc1	$f6,0x100($sp)
/*  f12ca54:	c7a400f4 */ 	lwc1	$f4,0xf4($sp)
/*  f12ca58:	4612403e */ 	c.le.s	$f8,$f18
/*  f12ca5c:	00000000 */ 	nop
/*  f12ca60:	4503000b */ 	bc1tl	.PF0f12ca90
/*  f12ca64:	c62803e8 */ 	lwc1	$f8,0x3e8($s1)
/*  f12ca68:	4606203e */ 	c.le.s	$f4,$f6
/*  f12ca6c:	c7aa0104 */ 	lwc1	$f10,0x104($sp)
/*  f12ca70:	c7b200f8 */ 	lwc1	$f18,0xf8($sp)
/*  f12ca74:	45030006 */ 	bc1tl	.PF0f12ca90
/*  f12ca78:	c62803e8 */ 	lwc1	$f8,0x3e8($s1)
/*  f12ca7c:	460a903e */ 	c.le.s	$f18,$f10
/*  f12ca80:	00000000 */ 	nop
/*  f12ca84:	45000035 */ 	bc1f	.PF0f12cb5c
/*  f12ca88:	00000000 */ 	nop
/*  f12ca8c:	c62803e8 */ 	lwc1	$f8,0x3e8($s1)
.PF0f12ca90:
/*  f12ca90:	00009825 */ 	move	$s3,$zero
/*  f12ca94:	e7a800fc */ 	swc1	$f8,0xfc($sp)
/*  f12ca98:	c62603ec */ 	lwc1	$f6,0x3ec($s1)
/*  f12ca9c:	e7a60100 */ 	swc1	$f6,0x100($sp)
/*  f12caa0:	c62403f0 */ 	lwc1	$f4,0x3f0($s1)
/*  f12caa4:	c7a600fc */ 	lwc1	$f6,0xfc($sp)
/*  f12caa8:	e7a40104 */ 	swc1	$f4,0x104($sp)
/*  f12caac:	c62a03f4 */ 	lwc1	$f10,0x3f4($s1)
/*  f12cab0:	c7a4011c */ 	lwc1	$f4,0x11c($sp)
/*  f12cab4:	e7aa00f0 */ 	swc1	$f10,0xf0($sp)
/*  f12cab8:	c63203f8 */ 	lwc1	$f18,0x3f8($s1)
/*  f12cabc:	4604303c */ 	c.lt.s	$f6,$f4
/*  f12cac0:	e7b200f4 */ 	swc1	$f18,0xf4($sp)
/*  f12cac4:	c62803fc */ 	lwc1	$f8,0x3fc($s1)
/*  f12cac8:	45000002 */ 	bc1f	.PF0f12cad4
/*  f12cacc:	e7a800f8 */ 	swc1	$f8,0xf8($sp)
/*  f12cad0:	e7a400fc */ 	swc1	$f4,0xfc($sp)
.PF0f12cad4:
/*  f12cad4:	c7a00120 */ 	lwc1	$f0,0x120($sp)
/*  f12cad8:	c7aa0100 */ 	lwc1	$f10,0x100($sp)
/*  f12cadc:	c7a20124 */ 	lwc1	$f2,0x124($sp)
/*  f12cae0:	c7ac0110 */ 	lwc1	$f12,0x110($sp)
/*  f12cae4:	4600503c */ 	c.lt.s	$f10,$f0
/*  f12cae8:	c7ae0114 */ 	lwc1	$f14,0x114($sp)
/*  f12caec:	c7b00118 */ 	lwc1	$f16,0x118($sp)
/*  f12caf0:	45020003 */ 	bc1fl	.PF0f12cb00
/*  f12caf4:	c7b20104 */ 	lwc1	$f18,0x104($sp)
/*  f12caf8:	e7a00100 */ 	swc1	$f0,0x100($sp)
/*  f12cafc:	c7b20104 */ 	lwc1	$f18,0x104($sp)
.PF0f12cb00:
/*  f12cb00:	4602903c */ 	c.lt.s	$f18,$f2
/*  f12cb04:	00000000 */ 	nop
/*  f12cb08:	45020003 */ 	bc1fl	.PF0f12cb18
/*  f12cb0c:	c7a800f0 */ 	lwc1	$f8,0xf0($sp)
/*  f12cb10:	e7a20104 */ 	swc1	$f2,0x104($sp)
/*  f12cb14:	c7a800f0 */ 	lwc1	$f8,0xf0($sp)
.PF0f12cb18:
/*  f12cb18:	4608603c */ 	c.lt.s	$f12,$f8
/*  f12cb1c:	00000000 */ 	nop
/*  f12cb20:	45020003 */ 	bc1fl	.PF0f12cb30
/*  f12cb24:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
/*  f12cb28:	e7ac00f0 */ 	swc1	$f12,0xf0($sp)
/*  f12cb2c:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
.PF0f12cb30:
/*  f12cb30:	4606703c */ 	c.lt.s	$f14,$f6
/*  f12cb34:	00000000 */ 	nop
/*  f12cb38:	45020003 */ 	bc1fl	.PF0f12cb48
/*  f12cb3c:	c7a400f8 */ 	lwc1	$f4,0xf8($sp)
/*  f12cb40:	e7ae00f4 */ 	swc1	$f14,0xf4($sp)
/*  f12cb44:	c7a400f8 */ 	lwc1	$f4,0xf8($sp)
.PF0f12cb48:
/*  f12cb48:	4604803c */ 	c.lt.s	$f16,$f4
/*  f12cb4c:	00000000 */ 	nop
/*  f12cb50:	45000002 */ 	bc1f	.PF0f12cb5c
/*  f12cb54:	00000000 */ 	nop
/*  f12cb58:	e7b000f8 */ 	swc1	$f16,0xf8($sp)
.PF0f12cb5c:
/*  f12cb5c:	0c004ad4 */ 	jal	random
/*  f12cb60:	00000000 */ 	nop
/*  f12cb64:	c7aa00f0 */ 	lwc1	$f10,0xf0($sp)
/*  f12cb68:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
/*  f12cb6c:	44823000 */ 	mtc1	$v0,$f6
/*  f12cb70:	3c014f80 */ 	lui	$at,0x4f80
/*  f12cb74:	46125201 */ 	sub.s	$f8,$f10,$f18
/*  f12cb78:	04410004 */ 	bgez	$v0,.PF0f12cb8c
/*  f12cb7c:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f12cb80:	44815000 */ 	mtc1	$at,$f10
/*  f12cb84:	00000000 */ 	nop
/*  f12cb88:	460a2100 */ 	add.s	$f4,$f4,$f10
.PF0f12cb8c:
/*  f12cb8c:	46162182 */ 	mul.s	$f6,$f4,$f22
/*  f12cb90:	00000000 */ 	nop
/*  f12cb94:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f12cb98:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f12cb9c:	0c004ad4 */ 	jal	random
/*  f12cba0:	e6040008 */ 	swc1	$f4,0x8($s0)
/*  f12cba4:	c7a800f4 */ 	lwc1	$f8,0xf4($sp)
/*  f12cba8:	c7a60100 */ 	lwc1	$f6,0x100($sp)
/*  f12cbac:	44829000 */ 	mtc1	$v0,$f18
/*  f12cbb0:	3c014f80 */ 	lui	$at,0x4f80
/*  f12cbb4:	46064281 */ 	sub.s	$f10,$f8,$f6
/*  f12cbb8:	04410004 */ 	bgez	$v0,.PF0f12cbcc
/*  f12cbbc:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f12cbc0:	44814000 */ 	mtc1	$at,$f8
/*  f12cbc4:	00000000 */ 	nop
/*  f12cbc8:	46082100 */ 	add.s	$f4,$f4,$f8
.PF0f12cbcc:
/*  f12cbcc:	46162482 */ 	mul.s	$f18,$f4,$f22
/*  f12cbd0:	00000000 */ 	nop
/*  f12cbd4:	46125202 */ 	mul.s	$f8,$f10,$f18
/*  f12cbd8:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f12cbdc:	0c004ad4 */ 	jal	random
/*  f12cbe0:	e604000c */ 	swc1	$f4,0xc($s0)
/*  f12cbe4:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f12cbe8:	c7b20104 */ 	lwc1	$f18,0x104($sp)
/*  f12cbec:	44823000 */ 	mtc1	$v0,$f6
/*  f12cbf0:	3c014f80 */ 	lui	$at,0x4f80
/*  f12cbf4:	46125201 */ 	sub.s	$f8,$f10,$f18
/*  f12cbf8:	04410004 */ 	bgez	$v0,.PF0f12cc0c
/*  f12cbfc:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f12cc00:	44815000 */ 	mtc1	$at,$f10
/*  f12cc04:	00000000 */ 	nop
/*  f12cc08:	460a2100 */ 	add.s	$f4,$f4,$f10
.PF0f12cc0c:
/*  f12cc0c:	46162182 */ 	mul.s	$f6,$f4,$f22
/*  f12cc10:	240b0001 */ 	li	$t3,0x1
/*  f12cc14:	a213001e */ 	sb	$s3,0x1e($s0)
/*  f12cc18:	a60b001c */ 	sh	$t3,0x1c($s0)
/*  f12cc1c:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f12cc20:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f12cc24:	0c004ad4 */ 	jal	random
/*  f12cc28:	e6040010 */ 	swc1	$f4,0x10($s0)
/*  f12cc2c:	44824000 */ 	mtc1	$v0,$f8
/*  f12cc30:	3c014f80 */ 	lui	$at,0x4f80
/*  f12cc34:	04410004 */ 	bgez	$v0,.PF0f12cc48
/*  f12cc38:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f12cc3c:	44815000 */ 	mtc1	$at,$f10
/*  f12cc40:	00000000 */ 	nop
/*  f12cc44:	460a3180 */ 	add.s	$f6,$f6,$f10
.PF0f12cc48:
/*  f12cc48:	46163482 */ 	mul.s	$f18,$f6,$f22
/*  f12cc4c:	3c013f00 */ 	lui	$at,0x3f00
/*  f12cc50:	44812000 */ 	mtc1	$at,$f4
/*  f12cc54:	c6c60010 */ 	lwc1	$f6,0x10($s6)
/*  f12cc58:	46049202 */ 	mul.s	$f8,$f18,$f4
/*  f12cc5c:	46144280 */ 	add.s	$f10,$f8,$f20
/*  f12cc60:	46065482 */ 	mul.s	$f18,$f10,$f6
/*  f12cc64:	0c004ad4 */ 	jal	random
/*  f12cc68:	e6120014 */ 	swc1	$f18,0x14($s0)
/*  f12cc6c:	44822000 */ 	mtc1	$v0,$f4
/*  f12cc70:	3c014f80 */ 	lui	$at,0x4f80
/*  f12cc74:	04410004 */ 	bgez	$v0,.PF0f12cc88
/*  f12cc78:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f12cc7c:	44815000 */ 	mtc1	$at,$f10
/*  f12cc80:	00000000 */ 	nop
/*  f12cc84:	460a4200 */ 	add.s	$f8,$f8,$f10
.PF0f12cc88:
/*  f12cc88:	46164182 */ 	mul.s	$f6,$f8,$f22
/*  f12cc8c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f12cc90:	c43268a4 */ 	lwc1	$f18,0x68a4($at)
/*  f12cc94:	46123102 */ 	mul.s	$f4,$f6,$f18
/*  f12cc98:	10000004 */ 	b	.PF0f12ccac
/*  f12cc9c:	e6040018 */ 	swc1	$f4,0x18($s0)
/*  f12cca0:	24630001 */ 	addiu	$v1,$v1,0x1
.PF0f12cca4:
/*  f12cca4:	1472ff0d */ 	bne	$v1,$s2,.PF0f12c8dc
/*  f12cca8:	26100018 */ 	addiu	$s0,$s0,0x18
.PF0f12ccac:
/*  f12ccac:	8fac0128 */ 	lw	$t4,0x128($sp)
/*  f12ccb0:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f12ccb4:	568cff08 */ 	bnel	$s4,$t4,.PF0f12c8d8
/*  f12ccb8:	00001825 */ 	move	$v1,$zero
/*  f12ccbc:	862603c8 */ 	lh	$a2,0x3c8($s1)
.PF0f12ccc0:
/*  f12ccc0:	3c012f80 */ 	lui	$at,0x2f80
/*  f12ccc4:	4481b000 */ 	mtc1	$at,$f22
/*  f12ccc8:	27b0013c */ 	addiu	$s0,$sp,0x13c
/*  f12cccc:	27b20130 */ 	addiu	$s2,$sp,0x130
/*  f12ccd0:	02402825 */ 	move	$a1,$s2
/*  f12ccd4:	02002025 */ 	move	$a0,$s0
/*  f12ccd8:	0fc4a9bc */ 	jal	explosionGetBboxAtFrame
/*  f12ccdc:	02e03825 */ 	move	$a3,$s7
/*  f12cce0:	26e60028 */ 	addiu	$a2,$s7,0x28
/*  f12cce4:	afa6009c */ 	sw	$a2,0x9c($sp)
/*  f12cce8:	02002025 */ 	move	$a0,$s0
/*  f12ccec:	02402825 */ 	move	$a1,$s2
/*  f12ccf0:	24070007 */ 	li	$a3,0x7
/*  f12ccf4:	0fc59814 */ 	jal	func0f1650d0
/*  f12ccf8:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f12ccfc:	0fc4aef2 */ 	jal	func0f12b0e0
/*  f12cd00:	02e02025 */ 	move	$a0,$s7
/*  f12cd04:	862603c8 */ 	lh	$a2,0x3c8($s1)
/*  f12cd08:	3c01bf80 */ 	lui	$at,0xbf80
/*  f12cd0c:	00002025 */ 	move	$a0,$zero
/*  f12cd10:	14c00016 */ 	bnez	$a2,.PF0f12cd6c
/*  f12cd14:	00002825 */ 	move	$a1,$zero
/*  f12cd18:	86c60026 */ 	lh	$a2,0x26($s6)
/*  f12cd1c:	240dffff */ 	li	$t5,-1
/*  f12cd20:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f12cd24:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f12cd28:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f12cd2c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f12cd30:	8e220000 */ 	lw	$v0,0x0($s1)
/*  f12cd34:	44810000 */ 	mtc1	$at,$f0
/*  f12cd38:	2418ffff */ 	li	$t8,-1
/*  f12cd3c:	244e0008 */ 	addiu	$t6,$v0,0x8
/*  f12cd40:	244f0028 */ 	addiu	$t7,$v0,0x28
/*  f12cd44:	afaf0028 */ 	sw	$t7,0x28($sp)
/*  f12cd48:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f12cd4c:	afb8002c */ 	sw	$t8,0x2c($sp)
/*  f12cd50:	2407ffff */ 	li	$a3,-1
/*  f12cd54:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f12cd58:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f12cd5c:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f12cd60:	0fc24e3a */ 	jal	func0f0939f8
/*  f12cd64:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f12cd68:	862603c8 */ 	lh	$a2,0x3c8($s1)
.PF0f12cd6c:
/*  f12cd6c:	c7aa0148 */ 	lwc1	$f10,0x148($sp)
/*  f12cd70:	87a9012e */ 	lh	$t1,0x12e($sp)
/*  f12cd74:	0000a025 */ 	move	$s4,$zero
/*  f12cd78:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f12cd7c:	241203c0 */ 	li	$s2,0x3c0
/*  f12cd80:	00095043 */ 	sra	$t2,$t1,0x1
/*  f12cd84:	44084000 */ 	mfc1	$t0,$f8
/*  f12cd88:	00000000 */ 	nop
/*  f12cd8c:	190000ac */ 	blez	$t0,.PF0f12d040
/*  f12cd90:	afa80098 */ 	sw	$t0,0x98($sp)
/*  f12cd94:	afaa0094 */ 	sw	$t2,0x94($sp)
/*  f12cd98:	24cb0001 */ 	addiu	$t3,$a2,0x1
.PF0f12cd9c:
/*  f12cd9c:	a62b03c8 */ 	sh	$t3,0x3c8($s1)
/*  f12cda0:	00001025 */ 	move	$v0,$zero
/*  f12cda4:	02208025 */ 	move	$s0,$s1
.PF0f12cda8:
/*  f12cda8:	8603001c */ 	lh	$v1,0x1c($s0)
/*  f12cdac:	24420018 */ 	addiu	$v0,$v0,0x18
/*  f12cdb0:	18600002 */ 	blez	$v1,.PF0f12cdbc
/*  f12cdb4:	246c0001 */ 	addiu	$t4,$v1,0x1
/*  f12cdb8:	a60c001c */ 	sh	$t4,0x1c($s0)
.PF0f12cdbc:
/*  f12cdbc:	1452fffa */ 	bne	$v0,$s2,.PF0f12cda8
/*  f12cdc0:	26100018 */ 	addiu	$s0,$s0,0x18
/*  f12cdc4:	862603c8 */ 	lh	$a2,0x3c8($s1)
/*  f12cdc8:	2401000c */ 	li	$at,0xc
/*  f12cdcc:	87ad012e */ 	lh	$t5,0x12e($sp)
/*  f12cdd0:	14c10005 */ 	bne	$a2,$at,.PF0f12cde8
/*  f12cdd4:	24ce0010 */ 	addiu	$t6,$a2,0x10
/*  f12cdd8:	822203cc */ 	lb	$v0,0x3cc($s1)
/*  f12cddc:	2401000e */ 	li	$at,0xe
/*  f12cde0:	50410007 */ 	beql	$v0,$at,.PF0f12ce00
/*  f12cde4:	24010001 */ 	li	$at,0x1
.PF0f12cde8:
/*  f12cde8:	55ae001a */ 	bnel	$t5,$t6,.PF0f12ce54
/*  f12cdec:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f12cdf0:	822203cc */ 	lb	$v0,0x3cc($s1)
/*  f12cdf4:	2401000e */ 	li	$at,0xe
/*  f12cdf8:	10410015 */ 	beq	$v0,$at,.PF0f12ce50
/*  f12cdfc:	24010001 */ 	li	$at,0x1
.PF0f12ce00:
/*  f12ce00:	54410007 */ 	bnel	$v0,$at,.PF0f12ce20
/*  f12ce04:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f12ce08:	0c004ad4 */ 	jal	random
/*  f12ce0c:	00000000 */ 	nop
/*  f12ce10:	304f0001 */ 	andi	$t7,$v0,0x1
/*  f12ce14:	55e0000f */ 	bnezl	$t7,.PF0f12ce54
/*  f12ce18:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f12ce1c:	8e220004 */ 	lw	$v0,0x4($s1)
.PF0f12ce20:
/*  f12ce20:	26e40008 */ 	addiu	$a0,$s7,0x8
/*  f12ce24:	8fa5009c */ 	lw	$a1,0x9c($sp)
/*  f12ce28:	10400007 */ 	beqz	$v0,.PF0f12ce48
/*  f12ce2c:	00000000 */ 	nop
/*  f12ce30:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f12ce34:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f12ce38:	0fc4bcd8 */ 	jal	smokeCreateSimple
/*  f12ce3c:	92c60024 */ 	lbu	$a2,0x24($s6)
/*  f12ce40:	10000004 */ 	b	.PF0f12ce54
/*  f12ce44:	8fb80094 */ 	lw	$t8,0x94($sp)
.PF0f12ce48:
/*  f12ce48:	0fc4bcd8 */ 	jal	smokeCreateSimple
/*  f12ce4c:	92c60024 */ 	lbu	$a2,0x24($s6)
.PF0f12ce50:
/*  f12ce50:	8fb80094 */ 	lw	$t8,0x94($sp)
.PF0f12ce54:
/*  f12ce54:	863903c8 */ 	lh	$t9,0x3c8($s1)
/*  f12ce58:	57190075 */ 	bnel	$t8,$t9,.PF0f12d030
/*  f12ce5c:	8faa0098 */ 	lw	$t2,0x98($sp)
/*  f12ce60:	822803cd */ 	lb	$t0,0x3cd($s1)
/*  f12ce64:	51000072 */ 	beqzl	$t0,.PF0f12d030
/*  f12ce68:	8faa0098 */ 	lw	$t2,0x98($sp)
/*  f12ce6c:	c6c00010 */ 	lwc1	$f0,0x10($s6)
/*  f12ce70:	3c0142c8 */ 	lui	$at,0x42c8
/*  f12ce74:	44811000 */ 	mtc1	$at,$f2
/*  f12ce78:	46000500 */ 	add.s	$f20,$f0,$f0
/*  f12ce7c:	00009825 */ 	move	$s3,$zero
/*  f12ce80:	4614103c */ 	c.lt.s	$f2,$f20
/*  f12ce84:	00000000 */ 	nop
/*  f12ce88:	45000002 */ 	bc1f	.PF0f12ce94
/*  f12ce8c:	00000000 */ 	nop
/*  f12ce90:	46001506 */ 	mov.s	$f20,$f2
.PF0f12ce94:
/*  f12ce94:	0c004ad4 */ 	jal	random
/*  f12ce98:	00000000 */ 	nop
/*  f12ce9c:	44829000 */ 	mtc1	$v0,$f18
/*  f12cea0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f12cea4:	c42668a8 */ 	lwc1	$f6,0x68a8($at)
/*  f12cea8:	04410005 */ 	bgez	$v0,.PF0f12cec0
/*  f12ceac:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f12ceb0:	3c014f80 */ 	lui	$at,0x4f80
/*  f12ceb4:	44815000 */ 	mtc1	$at,$f10
/*  f12ceb8:	00000000 */ 	nop
/*  f12cebc:	460a2100 */ 	add.s	$f4,$f4,$f10
.PF0f12cec0:
/*  f12cec0:	46162202 */ 	mul.s	$f8,$f4,$f22
/*  f12cec4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f12cec8:	c42a68ac */ 	lwc1	$f10,0x68ac($at)
/*  f12cecc:	8ea90318 */ 	lw	$t1,0x318($s5)
/*  f12ced0:	46083482 */ 	mul.s	$f18,$f6,$f8
/*  f12ced4:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f12ced8:	4604a502 */ 	mul.s	$f20,$f20,$f4
/*  f12cedc:	51200006 */ 	beqzl	$t1,.PF0f12cef8
/*  f12cee0:	8ea2029c */ 	lw	$v0,0x29c($s5)
/*  f12cee4:	0fc63843 */ 	jal	mpGetChrFromPlayerIndex
/*  f12cee8:	822403ce */ 	lb	$a0,0x3ce($s1)
/*  f12ceec:	10000018 */ 	b	.PF0f12cf50
/*  f12cef0:	00401825 */ 	move	$v1,$v0
/*  f12cef4:	8ea2029c */ 	lw	$v0,0x29c($s5)
.PF0f12cef8:
/*  f12cef8:	04420009 */ 	bltzl	$v0,.PF0f12cf20
/*  f12cefc:	8ea20298 */ 	lw	$v0,0x298($s5)
/*  f12cf00:	822a03ce */ 	lb	$t2,0x3ce($s1)
/*  f12cf04:	544a0006 */ 	bnel	$v0,$t2,.PF0f12cf20
/*  f12cf08:	8ea20298 */ 	lw	$v0,0x298($s5)
/*  f12cf0c:	8eab02a8 */ 	lw	$t3,0x2a8($s5)
/*  f12cf10:	8d6c00bc */ 	lw	$t4,0xbc($t3)
/*  f12cf14:	1000000e */ 	b	.PF0f12cf50
/*  f12cf18:	8d830004 */ 	lw	$v1,0x4($t4)
/*  f12cf1c:	8ea20298 */ 	lw	$v0,0x298($s5)
.PF0f12cf20:
/*  f12cf20:	04420009 */ 	bltzl	$v0,.PF0f12cf48
/*  f12cf24:	8eb802a0 */ 	lw	$t8,0x2a0($s5)
/*  f12cf28:	822d03ce */ 	lb	$t5,0x3ce($s1)
/*  f12cf2c:	544d0006 */ 	bnel	$v0,$t5,.PF0f12cf48
/*  f12cf30:	8eb802a0 */ 	lw	$t8,0x2a0($s5)
/*  f12cf34:	8eae02a4 */ 	lw	$t6,0x2a4($s5)
/*  f12cf38:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f12cf3c:	10000004 */ 	b	.PF0f12cf50
/*  f12cf40:	8de30004 */ 	lw	$v1,0x4($t7)
/*  f12cf44:	8eb802a0 */ 	lw	$t8,0x2a0($s5)
.PF0f12cf48:
/*  f12cf48:	8f1900bc */ 	lw	$t9,0xbc($t8)
/*  f12cf4c:	8f230004 */ 	lw	$v1,0x4($t9)
.PF0f12cf50:
/*  f12cf50:	862603ca */ 	lh	$a2,0x3ca($s1)
/*  f12cf54:	3c08800a */ 	lui	$t0,0x800a
/*  f12cf58:	8d084ec8 */ 	lw	$t0,0x4ec8($t0)
/*  f12cf5c:	000648c0 */ 	sll	$t1,$a2,0x3
/*  f12cf60:	01264821 */ 	addu	$t1,$t1,$a2
/*  f12cf64:	00094880 */ 	sll	$t1,$t1,0x2
/*  f12cf68:	01264823 */ 	subu	$t1,$t1,$a2
/*  f12cf6c:	00094880 */ 	sll	$t1,$t1,0x2
/*  f12cf70:	01095021 */ 	addu	$t2,$t0,$t1
/*  f12cf74:	8d420014 */ 	lw	$v0,0x14($t2)
/*  f12cf78:	262b03d0 */ 	addiu	$t3,$s1,0x3d0
/*  f12cf7c:	262c03dc */ 	addiu	$t4,$s1,0x3dc
/*  f12cf80:	5040002b */ 	beqzl	$v0,.PF0f12d030
/*  f12cf84:	8faa0098 */ 	lw	$t2,0x98($sp)
/*  f12cf88:	afab0090 */ 	sw	$t3,0x90($sp)
/*  f12cf8c:	afac008c */ 	sw	$t4,0x8c($sp)
/*  f12cf90:	8c4d000c */ 	lw	$t5,0xc($v0)
/*  f12cf94:	26f00008 */ 	addiu	$s0,$s7,0x8
/*  f12cf98:	02002025 */ 	move	$a0,$s0
/*  f12cf9c:	11a00009 */ 	beqz	$t5,.PF0f12cfc4
/*  f12cfa0:	01602825 */ 	move	$a1,$t3
/*  f12cfa4:	27a700b0 */ 	addiu	$a3,$sp,0xb0
/*  f12cfa8:	0fc58928 */ 	jal	func0f161520
/*  f12cfac:	afa300e4 */ 	sw	$v1,0xe4($sp)
/*  f12cfb0:	10400004 */ 	beqz	$v0,.PF0f12cfc4
/*  f12cfb4:	8fa300e4 */ 	lw	$v1,0xe4($sp)
/*  f12cfb8:	87b300dc */ 	lh	$s3,0xdc($sp)
/*  f12cfbc:	3a6e0002 */ 	xori	$t6,$s3,0x2
/*  f12cfc0:	2dd30001 */ 	sltiu	$s3,$t6,0x1
.PF0f12cfc4:
/*  f12cfc4:	240f0007 */ 	li	$t7,0x7
/*  f12cfc8:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f12cfcc:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f12cfd0:	863803ca */ 	lh	$t8,0x3ca($s1)
/*  f12cfd4:	2419ffff */ 	li	$t9,-1
/*  f12cfd8:	240800ff */ 	li	$t0,0xff
/*  f12cfdc:	240900ff */ 	li	$t1,0xff
/*  f12cfe0:	afa9003c */ 	sw	$t1,0x3c($sp)
/*  f12cfe4:	afa80038 */ 	sw	$t0,0x38($sp)
/*  f12cfe8:	afb90024 */ 	sw	$t9,0x24($sp)
/*  f12cfec:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f12cff0:	afa00048 */ 	sw	$zero,0x48($sp)
/*  f12cff4:	afa00044 */ 	sw	$zero,0x44($sp)
/*  f12cff8:	afa00040 */ 	sw	$zero,0x40($sp)
/*  f12cffc:	e7b40034 */ 	swc1	$f20,0x34($sp)
/*  f12d000:	e7b40030 */ 	swc1	$f20,0x30($sp)
/*  f12d004:	afa3002c */ 	sw	$v1,0x2c($sp)
/*  f12d008:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f12d00c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f12d010:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f12d014:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f12d018:	8fa5008c */ 	lw	$a1,0x8c($sp)
/*  f12d01c:	02003025 */ 	move	$a2,$s0
/*  f12d020:	00003825 */ 	move	$a3,$zero
/*  f12d024:	0fc5001d */ 	jal	func0f13f504
/*  f12d028:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f12d02c:	8faa0098 */ 	lw	$t2,0x98($sp)
.PF0f12d030:
/*  f12d030:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f12d034:	862603c8 */ 	lh	$a2,0x3c8($s1)
/*  f12d038:	568aff58 */ 	bnel	$s4,$t2,.PF0f12cd9c
/*  f12d03c:	24cb0001 */ 	addiu	$t3,$a2,0x1
.PF0f12d040:
/*  f12d040:	3c014180 */ 	lui	$at,0x4180
/*  f12d044:	44813000 */ 	mtc1	$at,$f6
/*  f12d048:	c6c80020 */ 	lwc1	$f8,0x20($s6)
/*  f12d04c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f12d050:	c43268b0 */ 	lwc1	$f18,0x68b0($at)
/*  f12d054:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f12d058:	87ad012e */ 	lh	$t5,0x12e($sp)
/*  f12d05c:	00001025 */ 	move	$v0,$zero
/*  f12d060:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f12d064:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f12d068:	440c3000 */ 	mfc1	$t4,$f6
/*  f12d06c:	00000000 */ 	nop
/*  f12d070:	01ac7021 */ 	addu	$t6,$t5,$t4
/*  f12d074:	00ce082a */ 	slt	$at,$a2,$t6
/*  f12d078:	1420000a */ 	bnez	$at,.PF0f12d0a4
/*  f12d07c:	00000000 */ 	nop
/*  f12d080:	822f03cc */ 	lb	$t7,0x3cc($s1)
/*  f12d084:	24010001 */ 	li	$at,0x1
/*  f12d088:	51e10004 */ 	beql	$t7,$at,.PF0f12d09c
/*  f12d08c:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f12d090:	0fc10ecf */ 	jal	propUnsetDangerous
/*  f12d094:	8e240000 */ 	lw	$a0,0x0($s1)
/*  f12d098:	ae200000 */ 	sw	$zero,0x0($s1)
.PF0f12d09c:
/*  f12d09c:	10000001 */ 	b	.PF0f12d0a4
/*  f12d0a0:	24020001 */ 	li	$v0,0x1
.PF0f12d0a4:
/*  f12d0a4:	8fbf0084 */ 	lw	$ra,0x84($sp)
/*  f12d0a8:	d7b40050 */ 	ldc1	$f20,0x50($sp)
/*  f12d0ac:	d7b60058 */ 	ldc1	$f22,0x58($sp)
/*  f12d0b0:	8fb00064 */ 	lw	$s0,0x64($sp)
/*  f12d0b4:	8fb10068 */ 	lw	$s1,0x68($sp)
/*  f12d0b8:	8fb2006c */ 	lw	$s2,0x6c($sp)
/*  f12d0bc:	8fb30070 */ 	lw	$s3,0x70($sp)
/*  f12d0c0:	8fb40074 */ 	lw	$s4,0x74($sp)
/*  f12d0c4:	8fb50078 */ 	lw	$s5,0x78($sp)
/*  f12d0c8:	8fb6007c */ 	lw	$s6,0x7c($sp)
/*  f12d0cc:	8fb70080 */ 	lw	$s7,0x80($sp)
/*  f12d0d0:	03e00008 */ 	jr	$ra
/*  f12d0d4:	27bd0168 */ 	addiu	$sp,$sp,0x168
);
#else
GLOBAL_ASM(
glabel func0f12bbdc
.late_rodata
glabel var7f1b55a0
.word 0x40c907a9
glabel var7f1b55a4
.word 0x3e4ccccd
glabel var7f1b55a8
.word 0x3f4ccccd
.text
/*  f12bbdc:	27bdfe98 */ 	addiu	$sp,$sp,-360
/*  f12bbe0:	afbf0084 */ 	sw	$ra,0x84($sp)
/*  f12bbe4:	afb70080 */ 	sw	$s7,0x80($sp)
/*  f12bbe8:	afb6007c */ 	sw	$s6,0x7c($sp)
/*  f12bbec:	afb50078 */ 	sw	$s5,0x78($sp)
/*  f12bbf0:	afb40074 */ 	sw	$s4,0x74($sp)
/*  f12bbf4:	afb30070 */ 	sw	$s3,0x70($sp)
/*  f12bbf8:	afb2006c */ 	sw	$s2,0x6c($sp)
/*  f12bbfc:	afb10068 */ 	sw	$s1,0x68($sp)
/*  f12bc00:	afb00064 */ 	sw	$s0,0x64($sp)
/*  f12bc04:	f7b60058 */ 	sdc1	$f22,0x58($sp)
/*  f12bc08:	f7b40050 */ 	sdc1	$f20,0x50($sp)
/*  f12bc0c:	8c910004 */ 	lw	$s1,0x4($a0)
/*  f12bc10:	3c15800a */ 	lui	$s5,%hi(g_Vars)
/*  f12bc14:	3c188008 */ 	lui	$t8,%hi(g_ExplosionTypes)
/*  f12bc18:	822e03cc */ 	lb	$t6,0x3cc($s1)
/*  f12bc1c:	26b59fc0 */ 	addiu	$s5,$s5,%lo(g_Vars)
/*  f12bc20:	2718e4b8 */ 	addiu	$t8,$t8,%lo(g_ExplosionTypes)
/*  f12bc24:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f12bc28:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f12bc2c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f12bc30:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f12bc34:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f12bc38:	8ea20038 */ 	lw	$v0,0x38($s5)
/*  f12bc3c:	01f8b021 */ 	addu	$s6,$t7,$t8
/*  f12bc40:	86d9001c */ 	lh	$t9,0x1c($s6)
/*  f12bc44:	0080b825 */ 	or	$s7,$a0,$zero
/*  f12bc48:	14400003 */ 	bnez	$v0,.L0f12bc58
/*  f12bc4c:	a7b9012e */ 	sh	$t9,0x12e($sp)
/*  f12bc50:	10000248 */ 	b	.L0f12c574
/*  f12bc54:	00001025 */ 	or	$v0,$zero,$zero
.L0f12bc58:
/*  f12bc58:	2841000f */ 	slti	$at,$v0,0xf
/*  f12bc5c:	50200007 */ 	beqzl	$at,.L0f12bc7c
/*  f12bc60:	3c014170 */ 	lui	$at,0x4170
/*  f12bc64:	44822000 */ 	mtc1	$v0,$f4
/*  f12bc68:	00000000 */ 	nop
/*  f12bc6c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f12bc70:	10000005 */ 	b	.L0f12bc88
/*  f12bc74:	e7a60148 */ 	swc1	$f6,0x148($sp)
/*  f12bc78:	3c014170 */ 	lui	$at,0x4170
.L0f12bc7c:
/*  f12bc7c:	44814000 */ 	mtc1	$at,$f8
/*  f12bc80:	00000000 */ 	nop
/*  f12bc84:	e7a80148 */ 	swc1	$f8,0x148($sp)
.L0f12bc88:
/*  f12bc88:	862603c8 */ 	lh	$a2,0x3c8($s1)
/*  f12bc8c:	87a8012e */ 	lh	$t0,0x12e($sp)
/*  f12bc90:	28c10008 */ 	slti	$at,$a2,0x8
/*  f12bc94:	14200141 */ 	bnez	$at,.L0f12c19c
/*  f12bc98:	00c8082a */ 	slt	$at,$a2,$t0
/*  f12bc9c:	1020013f */ 	beqz	$at,.L0f12c19c
/*  f12bca0:	02202025 */ 	or	$a0,$s1,$zero
/*  f12bca4:	0fc4a6c2 */ 	jal	explosionGetHorizontalRangeAtFrame
/*  f12bca8:	00c02825 */ 	or	$a1,$a2,$zero
/*  f12bcac:	46000506 */ 	mov.s	$f20,$f0
/*  f12bcb0:	02202025 */ 	or	$a0,$s1,$zero
/*  f12bcb4:	0fc4a6e9 */ 	jal	explosionGetVerticalRangeAtFrame
/*  f12bcb8:	862503c8 */ 	lh	$a1,0x3c8($s1)
/*  f12bcbc:	3c013f00 */ 	lui	$at,0x3f00
/*  f12bcc0:	44815000 */ 	mtc1	$at,$f10
/*  f12bcc4:	c6f20008 */ 	lwc1	$f18,0x8($s7)
/*  f12bcc8:	44813000 */ 	mtc1	$at,$f6
/*  f12bccc:	460aa082 */ 	mul.s	$f2,$f20,$f10
/*  f12bcd0:	2401000e */ 	addiu	$at,$zero,0xe
/*  f12bcd4:	46060302 */ 	mul.s	$f12,$f0,$f6
/*  f12bcd8:	46029101 */ 	sub.s	$f4,$f18,$f2
/*  f12bcdc:	e7a4011c */ 	swc1	$f4,0x11c($sp)
/*  f12bce0:	c6e8000c */ 	lwc1	$f8,0xc($s7)
/*  f12bce4:	460c4281 */ 	sub.s	$f10,$f8,$f12
/*  f12bce8:	e7aa0120 */ 	swc1	$f10,0x120($sp)
/*  f12bcec:	c6f20010 */ 	lwc1	$f18,0x10($s7)
/*  f12bcf0:	46029101 */ 	sub.s	$f4,$f18,$f2
/*  f12bcf4:	e7a40124 */ 	swc1	$f4,0x124($sp)
/*  f12bcf8:	c6e60008 */ 	lwc1	$f6,0x8($s7)
/*  f12bcfc:	46023200 */ 	add.s	$f8,$f6,$f2
/*  f12bd00:	e7a80110 */ 	swc1	$f8,0x110($sp)
/*  f12bd04:	c6ea000c */ 	lwc1	$f10,0xc($s7)
/*  f12bd08:	460c5480 */ 	add.s	$f18,$f10,$f12
/*  f12bd0c:	e7b20114 */ 	swc1	$f18,0x114($sp)
/*  f12bd10:	c6e40010 */ 	lwc1	$f4,0x10($s7)
/*  f12bd14:	46022180 */ 	add.s	$f6,$f4,$f2
/*  f12bd18:	e7a60118 */ 	swc1	$f6,0x118($sp)
/*  f12bd1c:	822903cc */ 	lb	$t1,0x3cc($s1)
/*  f12bd20:	5521000c */ 	bnel	$t1,$at,.L0f12bd54
/*  f12bd24:	862603c8 */ 	lh	$a2,0x3c8($s1)
/*  f12bd28:	862a03c8 */ 	lh	$t2,0x3c8($s1)
/*  f12bd2c:	c7aa0148 */ 	lwc1	$f10,0x148($sp)
/*  f12bd30:	29410020 */ 	slti	$at,$t2,0x20
/*  f12bd34:	10200006 */ 	beqz	$at,.L0f12bd50
/*  f12bd38:	3c014120 */ 	lui	$at,0x4120
/*  f12bd3c:	44814000 */ 	mtc1	$at,$f8
/*  f12bd40:	c6e4000c */ 	lwc1	$f4,0xc($s7)
/*  f12bd44:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f12bd48:	46122180 */ 	add.s	$f6,$f4,$f18
/*  f12bd4c:	e6e6000c */ 	swc1	$f6,0xc($s7)
.L0f12bd50:
/*  f12bd50:	862603c8 */ 	lh	$a2,0x3c8($s1)
.L0f12bd54:
/*  f12bd54:	86cb001e */ 	lh	$t3,0x1e($s6)
/*  f12bd58:	87ac012e */ 	lh	$t4,0x12e($sp)
/*  f12bd5c:	44862000 */ 	mtc1	$a2,$f4
/*  f12bd60:	448b4000 */ 	mtc1	$t3,$f8
/*  f12bd64:	0000a025 */ 	or	$s4,$zero,$zero
/*  f12bd68:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f12bd6c:	3c012f80 */ 	lui	$at,0x2f80
/*  f12bd70:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f12bd74:	448c4000 */ 	mtc1	$t4,$f8
/*  f12bd78:	00000000 */ 	nop
/*  f12bd7c:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f12bd80:	46125182 */ 	mul.s	$f6,$f10,$f18
/*  f12bd84:	46043283 */ 	div.s	$f10,$f6,$f4
/*  f12bd88:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f12bd8c:	440e9000 */ 	mfc1	$t6,$f18
/*  f12bd90:	00000000 */ 	nop
/*  f12bd94:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f12bd98:	19e00100 */ 	blez	$t7,.L0f12c19c
/*  f12bd9c:	afaf0128 */ 	sw	$t7,0x128($sp)
/*  f12bda0:	4481b000 */ 	mtc1	$at,$f22
/*  f12bda4:	3c013f80 */ 	lui	$at,0x3f80
/*  f12bda8:	4481a000 */ 	mtc1	$at,$f20
/*  f12bdac:	24120028 */ 	addiu	$s2,$zero,0x28
/*  f12bdb0:	00001825 */ 	or	$v1,$zero,$zero
.L0f12bdb4:
/*  f12bdb4:	02208025 */ 	or	$s0,$s1,$zero
.L0f12bdb8:
/*  f12bdb8:	8618001c */ 	lh	$t8,0x1c($s0)
/*  f12bdbc:	570000f0 */ 	bnezl	$t8,.L0f12c180
/*  f12bdc0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f12bdc4:	922403cf */ 	lbu	$a0,0x3cf($s1)
/*  f12bdc8:	50800006 */ 	beqzl	$a0,.L0f12bde4
/*  f12bdcc:	c7a00120 */ 	lwc1	$f0,0x120($sp)
/*  f12bdd0:	823903cc */ 	lb	$t9,0x3cc($s1)
/*  f12bdd4:	24010019 */ 	addiu	$at,$zero,0x19
/*  f12bdd8:	1721000f */ 	bne	$t9,$at,.L0f12be18
/*  f12bddc:	00000000 */ 	nop
/*  f12bde0:	c7a00120 */ 	lwc1	$f0,0x120($sp)
.L0f12bde4:
/*  f12bde4:	c7a20124 */ 	lwc1	$f2,0x124($sp)
/*  f12bde8:	c7ac0110 */ 	lwc1	$f12,0x110($sp)
/*  f12bdec:	c7ae0114 */ 	lwc1	$f14,0x114($sp)
/*  f12bdf0:	c7b00118 */ 	lwc1	$f16,0x118($sp)
/*  f12bdf4:	c7a8011c */ 	lwc1	$f8,0x11c($sp)
/*  f12bdf8:	00009825 */ 	or	$s3,$zero,$zero
/*  f12bdfc:	e7a00100 */ 	swc1	$f0,0x100($sp)
/*  f12be00:	e7a20104 */ 	swc1	$f2,0x104($sp)
/*  f12be04:	e7ac00f0 */ 	swc1	$f12,0xf0($sp)
/*  f12be08:	e7ae00f4 */ 	swc1	$f14,0xf4($sp)
/*  f12be0c:	e7b000f8 */ 	swc1	$f16,0xf8($sp)
/*  f12be10:	10000089 */ 	b	.L0f12c038
/*  f12be14:	e7a800fc */ 	swc1	$f8,0xfc($sp)
.L0f12be18:
/*  f12be18:	0064001a */ 	div	$zero,$v1,$a0
/*  f12be1c:	00009810 */ 	mfhi	$s3
/*  f12be20:	001340c0 */ 	sll	$t0,$s3,0x3
/*  f12be24:	01134023 */ 	subu	$t0,$t0,$s3
/*  f12be28:	00084080 */ 	sll	$t0,$t0,0x2
/*  f12be2c:	02281021 */ 	addu	$v0,$s1,$t0
/*  f12be30:	c44603e8 */ 	lwc1	$f6,0x3e8($v0)
/*  f12be34:	14800002 */ 	bnez	$a0,.L0f12be40
/*  f12be38:	00000000 */ 	nop
/*  f12be3c:	0007000d */ 	break	0x7
.L0f12be40:
/*  f12be40:	2401ffff */ 	addiu	$at,$zero,-1
/*  f12be44:	14810004 */ 	bne	$a0,$at,.L0f12be58
/*  f12be48:	3c018000 */ 	lui	$at,0x8000
/*  f12be4c:	14610002 */ 	bne	$v1,$at,.L0f12be58
/*  f12be50:	00000000 */ 	nop
/*  f12be54:	0006000d */ 	break	0x6
.L0f12be58:
/*  f12be58:	e7a600fc */ 	swc1	$f6,0xfc($sp)
/*  f12be5c:	c44403ec */ 	lwc1	$f4,0x3ec($v0)
/*  f12be60:	e7a40100 */ 	swc1	$f4,0x100($sp)
/*  f12be64:	c44a03f0 */ 	lwc1	$f10,0x3f0($v0)
/*  f12be68:	c7a400fc */ 	lwc1	$f4,0xfc($sp)
/*  f12be6c:	e7aa0104 */ 	swc1	$f10,0x104($sp)
/*  f12be70:	c45203f4 */ 	lwc1	$f18,0x3f4($v0)
/*  f12be74:	c7aa011c */ 	lwc1	$f10,0x11c($sp)
/*  f12be78:	e7b200f0 */ 	swc1	$f18,0xf0($sp)
/*  f12be7c:	c44803f8 */ 	lwc1	$f8,0x3f8($v0)
/*  f12be80:	460a203c */ 	c.lt.s	$f4,$f10
/*  f12be84:	e7a800f4 */ 	swc1	$f8,0xf4($sp)
/*  f12be88:	c44603fc */ 	lwc1	$f6,0x3fc($v0)
/*  f12be8c:	45000002 */ 	bc1f	.L0f12be98
/*  f12be90:	e7a600f8 */ 	swc1	$f6,0xf8($sp)
/*  f12be94:	e7aa00fc */ 	swc1	$f10,0xfc($sp)
.L0f12be98:
/*  f12be98:	c7a00120 */ 	lwc1	$f0,0x120($sp)
/*  f12be9c:	c7b20100 */ 	lwc1	$f18,0x100($sp)
/*  f12bea0:	4600903c */ 	c.lt.s	$f18,$f0
/*  f12bea4:	00000000 */ 	nop
/*  f12bea8:	45020003 */ 	bc1fl	.L0f12beb8
/*  f12beac:	c7a20124 */ 	lwc1	$f2,0x124($sp)
/*  f12beb0:	e7a00100 */ 	swc1	$f0,0x100($sp)
/*  f12beb4:	c7a20124 */ 	lwc1	$f2,0x124($sp)
.L0f12beb8:
/*  f12beb8:	c7a80104 */ 	lwc1	$f8,0x104($sp)
/*  f12bebc:	4602403c */ 	c.lt.s	$f8,$f2
/*  f12bec0:	00000000 */ 	nop
/*  f12bec4:	45020003 */ 	bc1fl	.L0f12bed4
/*  f12bec8:	c7ac0110 */ 	lwc1	$f12,0x110($sp)
/*  f12becc:	e7a20104 */ 	swc1	$f2,0x104($sp)
/*  f12bed0:	c7ac0110 */ 	lwc1	$f12,0x110($sp)
.L0f12bed4:
/*  f12bed4:	c7a600f0 */ 	lwc1	$f6,0xf0($sp)
/*  f12bed8:	4606603c */ 	c.lt.s	$f12,$f6
/*  f12bedc:	00000000 */ 	nop
/*  f12bee0:	45020003 */ 	bc1fl	.L0f12bef0
/*  f12bee4:	c7ae0114 */ 	lwc1	$f14,0x114($sp)
/*  f12bee8:	e7ac00f0 */ 	swc1	$f12,0xf0($sp)
/*  f12beec:	c7ae0114 */ 	lwc1	$f14,0x114($sp)
.L0f12bef0:
/*  f12bef0:	c7a400f4 */ 	lwc1	$f4,0xf4($sp)
/*  f12bef4:	4604703c */ 	c.lt.s	$f14,$f4
/*  f12bef8:	00000000 */ 	nop
/*  f12befc:	45020003 */ 	bc1fl	.L0f12bf0c
/*  f12bf00:	c7b00118 */ 	lwc1	$f16,0x118($sp)
/*  f12bf04:	e7ae00f4 */ 	swc1	$f14,0xf4($sp)
/*  f12bf08:	c7b00118 */ 	lwc1	$f16,0x118($sp)
.L0f12bf0c:
/*  f12bf0c:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f12bf10:	460a803c */ 	c.lt.s	$f16,$f10
/*  f12bf14:	00000000 */ 	nop
/*  f12bf18:	45020003 */ 	bc1fl	.L0f12bf28
/*  f12bf1c:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
/*  f12bf20:	e7b000f8 */ 	swc1	$f16,0xf8($sp)
/*  f12bf24:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
.L0f12bf28:
/*  f12bf28:	c7a800f0 */ 	lwc1	$f8,0xf0($sp)
/*  f12bf2c:	c7a60100 */ 	lwc1	$f6,0x100($sp)
/*  f12bf30:	c7a400f4 */ 	lwc1	$f4,0xf4($sp)
/*  f12bf34:	4612403e */ 	c.le.s	$f8,$f18
/*  f12bf38:	00000000 */ 	nop
/*  f12bf3c:	4503000b */ 	bc1tl	.L0f12bf6c
/*  f12bf40:	c62803e8 */ 	lwc1	$f8,0x3e8($s1)
/*  f12bf44:	4606203e */ 	c.le.s	$f4,$f6
/*  f12bf48:	c7aa0104 */ 	lwc1	$f10,0x104($sp)
/*  f12bf4c:	c7b200f8 */ 	lwc1	$f18,0xf8($sp)
/*  f12bf50:	45030006 */ 	bc1tl	.L0f12bf6c
/*  f12bf54:	c62803e8 */ 	lwc1	$f8,0x3e8($s1)
/*  f12bf58:	460a903e */ 	c.le.s	$f18,$f10
/*  f12bf5c:	00000000 */ 	nop
/*  f12bf60:	45000035 */ 	bc1f	.L0f12c038
/*  f12bf64:	00000000 */ 	nop
/*  f12bf68:	c62803e8 */ 	lwc1	$f8,0x3e8($s1)
.L0f12bf6c:
/*  f12bf6c:	00009825 */ 	or	$s3,$zero,$zero
/*  f12bf70:	e7a800fc */ 	swc1	$f8,0xfc($sp)
/*  f12bf74:	c62603ec */ 	lwc1	$f6,0x3ec($s1)
/*  f12bf78:	e7a60100 */ 	swc1	$f6,0x100($sp)
/*  f12bf7c:	c62403f0 */ 	lwc1	$f4,0x3f0($s1)
/*  f12bf80:	c7a600fc */ 	lwc1	$f6,0xfc($sp)
/*  f12bf84:	e7a40104 */ 	swc1	$f4,0x104($sp)
/*  f12bf88:	c62a03f4 */ 	lwc1	$f10,0x3f4($s1)
/*  f12bf8c:	c7a4011c */ 	lwc1	$f4,0x11c($sp)
/*  f12bf90:	e7aa00f0 */ 	swc1	$f10,0xf0($sp)
/*  f12bf94:	c63203f8 */ 	lwc1	$f18,0x3f8($s1)
/*  f12bf98:	4604303c */ 	c.lt.s	$f6,$f4
/*  f12bf9c:	e7b200f4 */ 	swc1	$f18,0xf4($sp)
/*  f12bfa0:	c62803fc */ 	lwc1	$f8,0x3fc($s1)
/*  f12bfa4:	45000002 */ 	bc1f	.L0f12bfb0
/*  f12bfa8:	e7a800f8 */ 	swc1	$f8,0xf8($sp)
/*  f12bfac:	e7a400fc */ 	swc1	$f4,0xfc($sp)
.L0f12bfb0:
/*  f12bfb0:	c7a00120 */ 	lwc1	$f0,0x120($sp)
/*  f12bfb4:	c7aa0100 */ 	lwc1	$f10,0x100($sp)
/*  f12bfb8:	c7a20124 */ 	lwc1	$f2,0x124($sp)
/*  f12bfbc:	c7ac0110 */ 	lwc1	$f12,0x110($sp)
/*  f12bfc0:	4600503c */ 	c.lt.s	$f10,$f0
/*  f12bfc4:	c7ae0114 */ 	lwc1	$f14,0x114($sp)
/*  f12bfc8:	c7b00118 */ 	lwc1	$f16,0x118($sp)
/*  f12bfcc:	45020003 */ 	bc1fl	.L0f12bfdc
/*  f12bfd0:	c7b20104 */ 	lwc1	$f18,0x104($sp)
/*  f12bfd4:	e7a00100 */ 	swc1	$f0,0x100($sp)
/*  f12bfd8:	c7b20104 */ 	lwc1	$f18,0x104($sp)
.L0f12bfdc:
/*  f12bfdc:	4602903c */ 	c.lt.s	$f18,$f2
/*  f12bfe0:	00000000 */ 	nop
/*  f12bfe4:	45020003 */ 	bc1fl	.L0f12bff4
/*  f12bfe8:	c7a800f0 */ 	lwc1	$f8,0xf0($sp)
/*  f12bfec:	e7a20104 */ 	swc1	$f2,0x104($sp)
/*  f12bff0:	c7a800f0 */ 	lwc1	$f8,0xf0($sp)
.L0f12bff4:
/*  f12bff4:	4608603c */ 	c.lt.s	$f12,$f8
/*  f12bff8:	00000000 */ 	nop
/*  f12bffc:	45020003 */ 	bc1fl	.L0f12c00c
/*  f12c000:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
/*  f12c004:	e7ac00f0 */ 	swc1	$f12,0xf0($sp)
/*  f12c008:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
.L0f12c00c:
/*  f12c00c:	4606703c */ 	c.lt.s	$f14,$f6
/*  f12c010:	00000000 */ 	nop
/*  f12c014:	45020003 */ 	bc1fl	.L0f12c024
/*  f12c018:	c7a400f8 */ 	lwc1	$f4,0xf8($sp)
/*  f12c01c:	e7ae00f4 */ 	swc1	$f14,0xf4($sp)
/*  f12c020:	c7a400f8 */ 	lwc1	$f4,0xf8($sp)
.L0f12c024:
/*  f12c024:	4604803c */ 	c.lt.s	$f16,$f4
/*  f12c028:	00000000 */ 	nop
/*  f12c02c:	45000002 */ 	bc1f	.L0f12c038
/*  f12c030:	00000000 */ 	nop
/*  f12c034:	e7b000f8 */ 	swc1	$f16,0xf8($sp)
.L0f12c038:
/*  f12c038:	0c004b70 */ 	jal	random
/*  f12c03c:	00000000 */ 	nop
/*  f12c040:	c7aa00f0 */ 	lwc1	$f10,0xf0($sp)
/*  f12c044:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
/*  f12c048:	44823000 */ 	mtc1	$v0,$f6
/*  f12c04c:	3c014f80 */ 	lui	$at,0x4f80
/*  f12c050:	46125201 */ 	sub.s	$f8,$f10,$f18
/*  f12c054:	04410004 */ 	bgez	$v0,.L0f12c068
/*  f12c058:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f12c05c:	44815000 */ 	mtc1	$at,$f10
/*  f12c060:	00000000 */ 	nop
/*  f12c064:	460a2100 */ 	add.s	$f4,$f4,$f10
.L0f12c068:
/*  f12c068:	46162182 */ 	mul.s	$f6,$f4,$f22
/*  f12c06c:	00000000 */ 	nop
/*  f12c070:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f12c074:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f12c078:	0c004b70 */ 	jal	random
/*  f12c07c:	e6040008 */ 	swc1	$f4,0x8($s0)
/*  f12c080:	c7a800f4 */ 	lwc1	$f8,0xf4($sp)
/*  f12c084:	c7a60100 */ 	lwc1	$f6,0x100($sp)
/*  f12c088:	44829000 */ 	mtc1	$v0,$f18
/*  f12c08c:	3c014f80 */ 	lui	$at,0x4f80
/*  f12c090:	46064281 */ 	sub.s	$f10,$f8,$f6
/*  f12c094:	04410004 */ 	bgez	$v0,.L0f12c0a8
/*  f12c098:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f12c09c:	44814000 */ 	mtc1	$at,$f8
/*  f12c0a0:	00000000 */ 	nop
/*  f12c0a4:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f12c0a8:
/*  f12c0a8:	46162482 */ 	mul.s	$f18,$f4,$f22
/*  f12c0ac:	00000000 */ 	nop
/*  f12c0b0:	46125202 */ 	mul.s	$f8,$f10,$f18
/*  f12c0b4:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f12c0b8:	0c004b70 */ 	jal	random
/*  f12c0bc:	e604000c */ 	swc1	$f4,0xc($s0)
/*  f12c0c0:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f12c0c4:	c7b20104 */ 	lwc1	$f18,0x104($sp)
/*  f12c0c8:	44823000 */ 	mtc1	$v0,$f6
/*  f12c0cc:	3c014f80 */ 	lui	$at,0x4f80
/*  f12c0d0:	46125201 */ 	sub.s	$f8,$f10,$f18
/*  f12c0d4:	04410004 */ 	bgez	$v0,.L0f12c0e8
/*  f12c0d8:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f12c0dc:	44815000 */ 	mtc1	$at,$f10
/*  f12c0e0:	00000000 */ 	nop
/*  f12c0e4:	460a2100 */ 	add.s	$f4,$f4,$f10
.L0f12c0e8:
/*  f12c0e8:	46162182 */ 	mul.s	$f6,$f4,$f22
/*  f12c0ec:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f12c0f0:	a213001e */ 	sb	$s3,0x1e($s0)
/*  f12c0f4:	a609001c */ 	sh	$t1,0x1c($s0)
/*  f12c0f8:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f12c0fc:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f12c100:	0c004b70 */ 	jal	random
/*  f12c104:	e6040010 */ 	swc1	$f4,0x10($s0)
/*  f12c108:	44824000 */ 	mtc1	$v0,$f8
/*  f12c10c:	3c014f80 */ 	lui	$at,0x4f80
/*  f12c110:	04410004 */ 	bgez	$v0,.L0f12c124
/*  f12c114:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f12c118:	44815000 */ 	mtc1	$at,$f10
/*  f12c11c:	00000000 */ 	nop
/*  f12c120:	460a3180 */ 	add.s	$f6,$f6,$f10
.L0f12c124:
/*  f12c124:	46163482 */ 	mul.s	$f18,$f6,$f22
/*  f12c128:	3c013f00 */ 	lui	$at,0x3f00
/*  f12c12c:	44812000 */ 	mtc1	$at,$f4
/*  f12c130:	c6c60010 */ 	lwc1	$f6,0x10($s6)
/*  f12c134:	46049202 */ 	mul.s	$f8,$f18,$f4
/*  f12c138:	46144280 */ 	add.s	$f10,$f8,$f20
/*  f12c13c:	46065482 */ 	mul.s	$f18,$f10,$f6
/*  f12c140:	0c004b70 */ 	jal	random
/*  f12c144:	e6120014 */ 	swc1	$f18,0x14($s0)
/*  f12c148:	44822000 */ 	mtc1	$v0,$f4
/*  f12c14c:	3c014f80 */ 	lui	$at,0x4f80
/*  f12c150:	04410004 */ 	bgez	$v0,.L0f12c164
/*  f12c154:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f12c158:	44815000 */ 	mtc1	$at,$f10
/*  f12c15c:	00000000 */ 	nop
/*  f12c160:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f12c164:
/*  f12c164:	46164182 */ 	mul.s	$f6,$f8,$f22
/*  f12c168:	3c017f1b */ 	lui	$at,%hi(var7f1b55a0)
/*  f12c16c:	c43255a0 */ 	lwc1	$f18,%lo(var7f1b55a0)($at)
/*  f12c170:	46123102 */ 	mul.s	$f4,$f6,$f18
/*  f12c174:	10000004 */ 	b	.L0f12c188
/*  f12c178:	e6040018 */ 	swc1	$f4,0x18($s0)
/*  f12c17c:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f12c180:
/*  f12c180:	1472ff0d */ 	bne	$v1,$s2,.L0f12bdb8
/*  f12c184:	26100018 */ 	addiu	$s0,$s0,0x18
.L0f12c188:
/*  f12c188:	8faa0128 */ 	lw	$t2,0x128($sp)
/*  f12c18c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f12c190:	568aff08 */ 	bnel	$s4,$t2,.L0f12bdb4
/*  f12c194:	00001825 */ 	or	$v1,$zero,$zero
/*  f12c198:	862603c8 */ 	lh	$a2,0x3c8($s1)
.L0f12c19c:
/*  f12c19c:	3c012f80 */ 	lui	$at,0x2f80
/*  f12c1a0:	4481b000 */ 	mtc1	$at,$f22
/*  f12c1a4:	27b0013c */ 	addiu	$s0,$sp,0x13c
/*  f12c1a8:	27b20130 */ 	addiu	$s2,$sp,0x130
/*  f12c1ac:	02402825 */ 	or	$a1,$s2,$zero
/*  f12c1b0:	02002025 */ 	or	$a0,$s0,$zero
/*  f12c1b4:	0fc4a702 */ 	jal	explosionGetBboxAtFrame
/*  f12c1b8:	02e03825 */ 	or	$a3,$s7,$zero
/*  f12c1bc:	26e60028 */ 	addiu	$a2,$s7,0x28
/*  f12c1c0:	afa6009c */ 	sw	$a2,0x9c($sp)
/*  f12c1c4:	02002025 */ 	or	$a0,$s0,$zero
/*  f12c1c8:	02402825 */ 	or	$a1,$s2,$zero
/*  f12c1cc:	24070007 */ 	addiu	$a3,$zero,0x7
/*  f12c1d0:	0fc59434 */ 	jal	func0f1650d0
/*  f12c1d4:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f12c1d8:	0fc4ac38 */ 	jal	func0f12b0e0
/*  f12c1dc:	02e02025 */ 	or	$a0,$s7,$zero
/*  f12c1e0:	862603c8 */ 	lh	$a2,0x3c8($s1)
/*  f12c1e4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f12c1e8:	00002025 */ 	or	$a0,$zero,$zero
/*  f12c1ec:	14c00016 */ 	bnez	$a2,.L0f12c248
/*  f12c1f0:	00002825 */ 	or	$a1,$zero,$zero
/*  f12c1f4:	86c60026 */ 	lh	$a2,0x26($s6)
/*  f12c1f8:	240bffff */ 	addiu	$t3,$zero,-1
/*  f12c1fc:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f12c200:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f12c204:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f12c208:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f12c20c:	8e220000 */ 	lw	$v0,0x0($s1)
/*  f12c210:	44810000 */ 	mtc1	$at,$f0
/*  f12c214:	240effff */ 	addiu	$t6,$zero,-1
/*  f12c218:	244c0008 */ 	addiu	$t4,$v0,0x8
/*  f12c21c:	244d0028 */ 	addiu	$t5,$v0,0x28
/*  f12c220:	afad0028 */ 	sw	$t5,0x28($sp)
/*  f12c224:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f12c228:	afae002c */ 	sw	$t6,0x2c($sp)
/*  f12c22c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f12c230:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f12c234:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f12c238:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f12c23c:	0fc24e7e */ 	jal	func0f0939f8
/*  f12c240:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f12c244:	862603c8 */ 	lh	$a2,0x3c8($s1)
.L0f12c248:
/*  f12c248:	c7aa0148 */ 	lwc1	$f10,0x148($sp)
/*  f12c24c:	87b9012e */ 	lh	$t9,0x12e($sp)
/*  f12c250:	0000a025 */ 	or	$s4,$zero,$zero
/*  f12c254:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f12c258:	241203c0 */ 	addiu	$s2,$zero,0x3c0
/*  f12c25c:	00194043 */ 	sra	$t0,$t9,0x1
/*  f12c260:	44184000 */ 	mfc1	$t8,$f8
/*  f12c264:	00000000 */ 	nop
/*  f12c268:	1b0000ac */ 	blez	$t8,.L0f12c51c
/*  f12c26c:	afb80098 */ 	sw	$t8,0x98($sp)
/*  f12c270:	afa80094 */ 	sw	$t0,0x94($sp)
/*  f12c274:	24c90001 */ 	addiu	$t1,$a2,0x1
.L0f12c278:
/*  f12c278:	a62903c8 */ 	sh	$t1,0x3c8($s1)
/*  f12c27c:	00001025 */ 	or	$v0,$zero,$zero
/*  f12c280:	02208025 */ 	or	$s0,$s1,$zero
.L0f12c284:
/*  f12c284:	8603001c */ 	lh	$v1,0x1c($s0)
/*  f12c288:	24420018 */ 	addiu	$v0,$v0,0x18
/*  f12c28c:	18600002 */ 	blez	$v1,.L0f12c298
/*  f12c290:	246a0001 */ 	addiu	$t2,$v1,0x1
/*  f12c294:	a60a001c */ 	sh	$t2,0x1c($s0)
.L0f12c298:
/*  f12c298:	1452fffa */ 	bne	$v0,$s2,.L0f12c284
/*  f12c29c:	26100018 */ 	addiu	$s0,$s0,0x18
/*  f12c2a0:	862603c8 */ 	lh	$a2,0x3c8($s1)
/*  f12c2a4:	2401000f */ 	addiu	$at,$zero,0xf
/*  f12c2a8:	87ab012e */ 	lh	$t3,0x12e($sp)
/*  f12c2ac:	14c10005 */ 	bne	$a2,$at,.L0f12c2c4
/*  f12c2b0:	24cc0014 */ 	addiu	$t4,$a2,0x14
/*  f12c2b4:	822203cc */ 	lb	$v0,0x3cc($s1)
/*  f12c2b8:	2401000e */ 	addiu	$at,$zero,0xe
/*  f12c2bc:	50410007 */ 	beql	$v0,$at,.L0f12c2dc
/*  f12c2c0:	24010001 */ 	addiu	$at,$zero,0x1
.L0f12c2c4:
/*  f12c2c4:	556c001a */ 	bnel	$t3,$t4,.L0f12c330
/*  f12c2c8:	8fae0094 */ 	lw	$t6,0x94($sp)
/*  f12c2cc:	822203cc */ 	lb	$v0,0x3cc($s1)
/*  f12c2d0:	2401000e */ 	addiu	$at,$zero,0xe
/*  f12c2d4:	10410015 */ 	beq	$v0,$at,.L0f12c32c
/*  f12c2d8:	24010001 */ 	addiu	$at,$zero,0x1
.L0f12c2dc:
/*  f12c2dc:	54410007 */ 	bnel	$v0,$at,.L0f12c2fc
/*  f12c2e0:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f12c2e4:	0c004b70 */ 	jal	random
/*  f12c2e8:	00000000 */ 	nop
/*  f12c2ec:	304d0001 */ 	andi	$t5,$v0,0x1
/*  f12c2f0:	55a0000f */ 	bnezl	$t5,.L0f12c330
/*  f12c2f4:	8fae0094 */ 	lw	$t6,0x94($sp)
/*  f12c2f8:	8e220004 */ 	lw	$v0,0x4($s1)
.L0f12c2fc:
/*  f12c2fc:	26e40008 */ 	addiu	$a0,$s7,0x8
/*  f12c300:	8fa5009c */ 	lw	$a1,0x9c($sp)
/*  f12c304:	10400007 */ 	beqz	$v0,.L0f12c324
/*  f12c308:	00000000 */ 	nop
/*  f12c30c:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f12c310:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f12c314:	0fc4ba08 */ 	jal	smokeCreateSimple
/*  f12c318:	92c60024 */ 	lbu	$a2,0x24($s6)
/*  f12c31c:	10000004 */ 	b	.L0f12c330
/*  f12c320:	8fae0094 */ 	lw	$t6,0x94($sp)
.L0f12c324:
/*  f12c324:	0fc4ba08 */ 	jal	smokeCreateSimple
/*  f12c328:	92c60024 */ 	lbu	$a2,0x24($s6)
.L0f12c32c:
/*  f12c32c:	8fae0094 */ 	lw	$t6,0x94($sp)
.L0f12c330:
/*  f12c330:	862f03c8 */ 	lh	$t7,0x3c8($s1)
/*  f12c334:	55cf0075 */ 	bnel	$t6,$t7,.L0f12c50c
/*  f12c338:	8fa80098 */ 	lw	$t0,0x98($sp)
/*  f12c33c:	823803cd */ 	lb	$t8,0x3cd($s1)
/*  f12c340:	53000072 */ 	beqzl	$t8,.L0f12c50c
/*  f12c344:	8fa80098 */ 	lw	$t0,0x98($sp)
/*  f12c348:	c6c00010 */ 	lwc1	$f0,0x10($s6)
/*  f12c34c:	3c0142c8 */ 	lui	$at,0x42c8
/*  f12c350:	44811000 */ 	mtc1	$at,$f2
/*  f12c354:	46000500 */ 	add.s	$f20,$f0,$f0
/*  f12c358:	00009825 */ 	or	$s3,$zero,$zero
/*  f12c35c:	4614103c */ 	c.lt.s	$f2,$f20
/*  f12c360:	00000000 */ 	nop
/*  f12c364:	45000002 */ 	bc1f	.L0f12c370
/*  f12c368:	00000000 */ 	nop
/*  f12c36c:	46001506 */ 	mov.s	$f20,$f2
.L0f12c370:
/*  f12c370:	0c004b70 */ 	jal	random
/*  f12c374:	00000000 */ 	nop
/*  f12c378:	44829000 */ 	mtc1	$v0,$f18
/*  f12c37c:	3c017f1b */ 	lui	$at,%hi(var7f1b55a4)
/*  f12c380:	c42655a4 */ 	lwc1	$f6,%lo(var7f1b55a4)($at)
/*  f12c384:	04410005 */ 	bgez	$v0,.L0f12c39c
/*  f12c388:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f12c38c:	3c014f80 */ 	lui	$at,0x4f80
/*  f12c390:	44815000 */ 	mtc1	$at,$f10
/*  f12c394:	00000000 */ 	nop
/*  f12c398:	460a2100 */ 	add.s	$f4,$f4,$f10
.L0f12c39c:
/*  f12c39c:	46162202 */ 	mul.s	$f8,$f4,$f22
/*  f12c3a0:	3c017f1b */ 	lui	$at,%hi(var7f1b55a8)
/*  f12c3a4:	c42a55a8 */ 	lwc1	$f10,%lo(var7f1b55a8)($at)
/*  f12c3a8:	8eb90318 */ 	lw	$t9,0x318($s5)
/*  f12c3ac:	46083482 */ 	mul.s	$f18,$f6,$f8
/*  f12c3b0:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f12c3b4:	4604a502 */ 	mul.s	$f20,$f20,$f4
/*  f12c3b8:	53200006 */ 	beqzl	$t9,.L0f12c3d4
/*  f12c3bc:	8ea2029c */ 	lw	$v0,0x29c($s5)
/*  f12c3c0:	0fc63410 */ 	jal	mpGetChrFromPlayerIndex
/*  f12c3c4:	822403ce */ 	lb	$a0,0x3ce($s1)
/*  f12c3c8:	10000018 */ 	b	.L0f12c42c
/*  f12c3cc:	00401825 */ 	or	$v1,$v0,$zero
/*  f12c3d0:	8ea2029c */ 	lw	$v0,0x29c($s5)
.L0f12c3d4:
/*  f12c3d4:	04420009 */ 	bltzl	$v0,.L0f12c3fc
/*  f12c3d8:	8ea20298 */ 	lw	$v0,0x298($s5)
/*  f12c3dc:	822803ce */ 	lb	$t0,0x3ce($s1)
/*  f12c3e0:	54480006 */ 	bnel	$v0,$t0,.L0f12c3fc
/*  f12c3e4:	8ea20298 */ 	lw	$v0,0x298($s5)
/*  f12c3e8:	8ea902a8 */ 	lw	$t1,0x2a8($s5)
/*  f12c3ec:	8d2a00bc */ 	lw	$t2,0xbc($t1)
/*  f12c3f0:	1000000e */ 	b	.L0f12c42c
/*  f12c3f4:	8d430004 */ 	lw	$v1,0x4($t2)
/*  f12c3f8:	8ea20298 */ 	lw	$v0,0x298($s5)
.L0f12c3fc:
/*  f12c3fc:	04420009 */ 	bltzl	$v0,.L0f12c424
/*  f12c400:	8eae02a0 */ 	lw	$t6,0x2a0($s5)
/*  f12c404:	822b03ce */ 	lb	$t3,0x3ce($s1)
/*  f12c408:	544b0006 */ 	bnel	$v0,$t3,.L0f12c424
/*  f12c40c:	8eae02a0 */ 	lw	$t6,0x2a0($s5)
/*  f12c410:	8eac02a4 */ 	lw	$t4,0x2a4($s5)
/*  f12c414:	8d8d00bc */ 	lw	$t5,0xbc($t4)
/*  f12c418:	10000004 */ 	b	.L0f12c42c
/*  f12c41c:	8da30004 */ 	lw	$v1,0x4($t5)
/*  f12c420:	8eae02a0 */ 	lw	$t6,0x2a0($s5)
.L0f12c424:
/*  f12c424:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f12c428:	8de30004 */ 	lw	$v1,0x4($t7)
.L0f12c42c:
/*  f12c42c:	862603ca */ 	lh	$a2,0x3ca($s1)
/*  f12c430:	3c18800a */ 	lui	$t8,%hi(g_Rooms)
/*  f12c434:	8f184928 */ 	lw	$t8,%lo(g_Rooms)($t8)
/*  f12c438:	0006c8c0 */ 	sll	$t9,$a2,0x3
/*  f12c43c:	0326c821 */ 	addu	$t9,$t9,$a2
/*  f12c440:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12c444:	0326c823 */ 	subu	$t9,$t9,$a2
/*  f12c448:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f12c44c:	03194021 */ 	addu	$t0,$t8,$t9
/*  f12c450:	8d020014 */ 	lw	$v0,0x14($t0)
/*  f12c454:	262903d0 */ 	addiu	$t1,$s1,0x3d0
/*  f12c458:	262a03dc */ 	addiu	$t2,$s1,0x3dc
/*  f12c45c:	5040002b */ 	beqzl	$v0,.L0f12c50c
/*  f12c460:	8fa80098 */ 	lw	$t0,0x98($sp)
/*  f12c464:	afa90090 */ 	sw	$t1,0x90($sp)
/*  f12c468:	afaa008c */ 	sw	$t2,0x8c($sp)
/*  f12c46c:	8c4b000c */ 	lw	$t3,0xc($v0)
/*  f12c470:	26f00008 */ 	addiu	$s0,$s7,0x8
/*  f12c474:	02002025 */ 	or	$a0,$s0,$zero
/*  f12c478:	11600009 */ 	beqz	$t3,.L0f12c4a0
/*  f12c47c:	01202825 */ 	or	$a1,$t1,$zero
/*  f12c480:	27a700b0 */ 	addiu	$a3,$sp,0xb0
/*  f12c484:	0fc58548 */ 	jal	func0f161520
/*  f12c488:	afa300e4 */ 	sw	$v1,0xe4($sp)
/*  f12c48c:	10400004 */ 	beqz	$v0,.L0f12c4a0
/*  f12c490:	8fa300e4 */ 	lw	$v1,0xe4($sp)
/*  f12c494:	87b300dc */ 	lh	$s3,0xdc($sp)
/*  f12c498:	3a6c0002 */ 	xori	$t4,$s3,0x2
/*  f12c49c:	2d930001 */ 	sltiu	$s3,$t4,0x1
.L0f12c4a0:
/*  f12c4a0:	240d0007 */ 	addiu	$t5,$zero,0x7
/*  f12c4a4:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f12c4a8:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f12c4ac:	862e03ca */ 	lh	$t6,0x3ca($s1)
/*  f12c4b0:	240fffff */ 	addiu	$t7,$zero,-1
/*  f12c4b4:	241800ff */ 	addiu	$t8,$zero,0xff
/*  f12c4b8:	241900ff */ 	addiu	$t9,$zero,0xff
/*  f12c4bc:	afb9003c */ 	sw	$t9,0x3c($sp)
/*  f12c4c0:	afb80038 */ 	sw	$t8,0x38($sp)
/*  f12c4c4:	afaf0024 */ 	sw	$t7,0x24($sp)
/*  f12c4c8:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f12c4cc:	afa00048 */ 	sw	$zero,0x48($sp)
/*  f12c4d0:	afa00044 */ 	sw	$zero,0x44($sp)
/*  f12c4d4:	afa00040 */ 	sw	$zero,0x40($sp)
/*  f12c4d8:	e7b40034 */ 	swc1	$f20,0x34($sp)
/*  f12c4dc:	e7b40030 */ 	swc1	$f20,0x30($sp)
/*  f12c4e0:	afa3002c */ 	sw	$v1,0x2c($sp)
/*  f12c4e4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f12c4e8:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f12c4ec:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f12c4f0:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f12c4f4:	8fa5008c */ 	lw	$a1,0x8c($sp)
/*  f12c4f8:	02003025 */ 	or	$a2,$s0,$zero
/*  f12c4fc:	00003825 */ 	or	$a3,$zero,$zero
/*  f12c500:	0fc4fd41 */ 	jal	func0f13f504
/*  f12c504:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f12c508:	8fa80098 */ 	lw	$t0,0x98($sp)
.L0f12c50c:
/*  f12c50c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f12c510:	862603c8 */ 	lh	$a2,0x3c8($s1)
/*  f12c514:	5688ff58 */ 	bnel	$s4,$t0,.L0f12c278
/*  f12c518:	24c90001 */ 	addiu	$t1,$a2,0x1
.L0f12c51c:
/*  f12c51c:	3c014180 */ 	lui	$at,0x4180
/*  f12c520:	44813000 */ 	mtc1	$at,$f6
/*  f12c524:	c6c80020 */ 	lwc1	$f8,0x20($s6)
/*  f12c528:	87ab012e */ 	lh	$t3,0x12e($sp)
/*  f12c52c:	00001025 */ 	or	$v0,$zero,$zero
/*  f12c530:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f12c534:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f12c538:	440a9000 */ 	mfc1	$t2,$f18
/*  f12c53c:	00000000 */ 	nop
/*  f12c540:	016a6021 */ 	addu	$t4,$t3,$t2
/*  f12c544:	00cc082a */ 	slt	$at,$a2,$t4
/*  f12c548:	1420000a */ 	bnez	$at,.L0f12c574
/*  f12c54c:	00000000 */ 	nop
/*  f12c550:	822d03cc */ 	lb	$t5,0x3cc($s1)
/*  f12c554:	24010001 */ 	addiu	$at,$zero,0x1
/*  f12c558:	51a10004 */ 	beql	$t5,$at,.L0f12c56c
/*  f12c55c:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f12c560:	0fc10e62 */ 	jal	propUnsetDangerous
/*  f12c564:	8e240000 */ 	lw	$a0,0x0($s1)
/*  f12c568:	ae200000 */ 	sw	$zero,0x0($s1)
.L0f12c56c:
/*  f12c56c:	10000001 */ 	b	.L0f12c574
/*  f12c570:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f12c574:
/*  f12c574:	8fbf0084 */ 	lw	$ra,0x84($sp)
/*  f12c578:	d7b40050 */ 	ldc1	$f20,0x50($sp)
/*  f12c57c:	d7b60058 */ 	ldc1	$f22,0x58($sp)
/*  f12c580:	8fb00064 */ 	lw	$s0,0x64($sp)
/*  f12c584:	8fb10068 */ 	lw	$s1,0x68($sp)
/*  f12c588:	8fb2006c */ 	lw	$s2,0x6c($sp)
/*  f12c58c:	8fb30070 */ 	lw	$s3,0x70($sp)
/*  f12c590:	8fb40074 */ 	lw	$s4,0x74($sp)
/*  f12c594:	8fb50078 */ 	lw	$s5,0x78($sp)
/*  f12c598:	8fb6007c */ 	lw	$s6,0x7c($sp)
/*  f12c59c:	8fb70080 */ 	lw	$s7,0x80($sp)
/*  f12c5a0:	03e00008 */ 	jr	$ra
/*  f12c5a4:	27bd0168 */ 	addiu	$sp,$sp,0x168
);
#endif

u32 explosionUpdateZ(struct prop *prop)
{
	Mtxf *matrix = currentPlayerGetMatrix1740();

	prop->z = -(matrix->m[0][2] * prop->pos.x + matrix->m[1][2] * prop->pos.y + matrix->m[2][2] * prop->pos.z + matrix->m[3][2]);

	if (prop->z < 100) {
		prop->z *= 0.5f;
	} else {
		prop->z -= 100;
	}

	prop->flags |= PROPFLAG_40 | PROPFLAG_02;

	return 0;
}

Gfx *explosionRender(struct prop *prop, Gfx *gdl, bool withalpha)
{
	struct explosion *exp = prop->explosion;
	s32 roomnum;
	s32 i;
	s32 j;

	if (!withalpha) {
		return gdl;
	}

	j = 0;
	roomnum = prop->rooms[j];

	while (roomnum != -1) {
		if (g_Rooms[roomnum].unk14
				&& g_Rooms[roomnum].unk02
				&& (g_Rooms[roomnum].flags & ROOMFLAG_VISIBLEBYPLAYER)) {
			break;
		}

		j++;
		roomnum = prop->rooms[j];
	}

	if (roomnum != -1) {
		struct screenbox screenbox;
		struct coord *coord = func0f166dd0(roomnum);
		u32 *colour;
		s32 tmp;

		if (func0f08e5a8(prop->rooms, &screenbox) > 0) {
			gdl = currentPlayerScissorWithinViewport(gdl, screenbox.xmin, screenbox.ymin, screenbox.xmax, screenbox.ymax);
		} else {
			gdl = currentPlayerScissorToViewport(gdl);
		}

		gSPClearGeometryMode(gdl++, G_CULL_BOTH | G_FOG);
		gSPMatrix(gdl++, osVirtualToPhysical(currentPlayerGetUnk1758()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

		gdl = func0f166d7c(gdl, roomnum);

		gSPDisplayList(gdl++, var800ab568);

		colour = gfxAllocateColours(1);

		if ((!g_Vars.currentplayer->isdead
				&& !g_InCutscene
				&& EYESPYINACTIVE()
				&& (g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_NIGHTVISION))
				||
				(!g_Vars.currentplayer->isdead
				&& !g_InCutscene
				&& EYESPYINACTIVE()
				&& (g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_IRSCANNER))) {
			*colour = 0xffffffff;
		} else if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
			u32 alpha = 0x80;
			u32 red;
			u32 green;
			f32 expdist = sqrtf(ERASERSQDIST(prop->pos.f));

			if (g_Vars.currentplayer->eraserpropdist < expdist) {
				return gdl;
			}

			if (g_Vars.currentplayer->eraserpropdist - 150.0f < expdist) {
				alpha = (1.0f - (expdist - (g_Vars.currentplayer->eraserpropdist - 150.0f)) / 150.0f) * 128.0f;
			}

			expdist = expdist / g_Vars.currentplayer->eraserpropdist;

			if (expdist > 1.0f) {
				expdist = 1.0f;
			}

			red = expdist * 127.0f;
			green = (1.0f - expdist) * 127.0f;

			*colour = red << 24 | green << 16 | alpha | 0x80800000;
		} else {
			static u32 var8007e93c = 0xffffffff;
			func0000db30("ecol", &var8007e93c);
			*colour = 0xffffffff;
			*colour = var8007e93c;
		}

		gDPSetColorArray(gdl++, osVirtualToPhysical(colour), 1);

		for (i = 14; i >= 0; i--) {
			gDPSetTextureImage(gdl++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, var800ab570[i].unk00);
			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, 1567, 0);

			gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, var800ab570[i].unk04);
			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, 5, 0, 0, 223, 0);

			gDPPipeSync(gdl++);

			for (j = 0; j < ARRAYCOUNT(exp->parts); j++) {
				if (exp->parts[j].frame > 0) {
#if PAL
					if (i == (s32)((f32)(exp->parts[j].frame - 1) / (g_ExplosionTypes[exp->type].flarespeed * 0.83333331346512f))) {
						gdl = explosionRenderPart(exp, &exp->parts[j], gdl, coord, i);
					}
#else
					if (i == (s32)((f32)(exp->parts[j].frame - 1) / g_ExplosionTypes[exp->type].flarespeed)) {
						gdl = explosionRenderPart(exp, &exp->parts[j], gdl, coord, i);
					}
#endif
				}
			}
		}

		gSPMatrix(gdl++, osVirtualToPhysical(currentPlayerGetUnk1750()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

#if PAL
		tmp = (g_ExplosionTypes[exp->type].flarespeed * 15.0f) * 0.83333331346512f;
#else
		tmp = g_ExplosionTypes[exp->type].flarespeed * 15.0f;
#endif

		for (j = 0; j < ARRAYCOUNT(exp->parts); j++) {
			if (exp->parts[j].frame > tmp) {
				exp->parts[j].frame = 0;
			}
		}
	}

	return gdl;
}

GLOBAL_ASM(
glabel explosionRenderPart
.late_rodata
glabel var7f1b55ac
.word 0x3f333333
glabel var7f1b55b0
.word 0x3f266666
glabel var7f1b55b4
.word 0x3f4ccccd
glabel var7f1b55b8
.word 0x3f16db6e
glabel var7f1b55bc
.word 0x3f324925
glabel var7f1b55c0
.word 0x3f524925
glabel var7f1b55c4
.word 0x3f76db6e
.text
/*  f12cd64:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f12cd68:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f12cd6c:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f12cd70:	afa400d0 */ 	sw	$a0,0xd0($sp)
/*  f12cd74:	00a08825 */ 	or	$s1,$a1,$zero
/*  f12cd78:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f12cd7c:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f12cd80:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f12cd84:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f12cd88:	afa600d8 */ 	sw	$a2,0xd8($sp)
/*  f12cd8c:	afa700dc */ 	sw	$a3,0xdc($sp)
/*  f12cd90:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f12cd94:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f12cd98:	0fc2d5de */ 	jal	currentPlayerGetUnk174c
/*  f12cd9c:	00408025 */ 	or	$s0,$v0,$zero
/*  f12cda0:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*  f12cda4:	00405825 */ 	or	$t3,$v0,$zero
/*  f12cda8:	c636000c */ 	lwc1	$f22,0xc($s1)
/*  f12cdac:	914e03cf */ 	lbu	$t6,0x3cf($t2)
/*  f12cdb0:	c62e0000 */ 	lwc1	$f14,0x0($s1)
/*  f12cdb4:	c6300004 */ 	lwc1	$f16,0x4($s1)
/*  f12cdb8:	19c000b4 */ 	blez	$t6,.L0f12d08c
/*  f12cdbc:	c6320008 */ 	lwc1	$f18,0x8($s1)
/*  f12cdc0:	e7ae0068 */ 	swc1	$f14,0x68($sp)
/*  f12cdc4:	e7b0006c */ 	swc1	$f16,0x6c($sp)
/*  f12cdc8:	e7b20070 */ 	swc1	$f18,0x70($sp)
/*  f12cdcc:	914803cf */ 	lbu	$t0,0x3cf($t2)
/*  f12cdd0:	4480c000 */ 	mtc1	$zero,$f24
/*  f12cdd4:	92290016 */ 	lbu	$t1,0x16($s1)
/*  f12cdd8:	00003825 */ 	or	$a3,$zero,$zero
/*  f12cddc:	19000043 */ 	blez	$t0,.L0f12ceec
/*  f12cde0:	4600c506 */ 	mov.s	$f20,$f24
/*  f12cde4:	01403025 */ 	or	$a2,$t2,$zero
/*  f12cde8:	27a50074 */ 	addiu	$a1,$sp,0x74
.L0f12cdec:
/*  f12cdec:	c4c403e8 */ 	lwc1	$f4,0x3e8($a2)
/*  f12cdf0:	460e203e */ 	c.le.s	$f4,$f14
/*  f12cdf4:	00000000 */ 	nop
/*  f12cdf8:	45020039 */ 	bc1fl	.L0f12cee0
/*  f12cdfc:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ce00:	c4c603f4 */ 	lwc1	$f6,0x3f4($a2)
/*  f12ce04:	4606703e */ 	c.le.s	$f14,$f6
/*  f12ce08:	00000000 */ 	nop
/*  f12ce0c:	45020034 */ 	bc1fl	.L0f12cee0
/*  f12ce10:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ce14:	c4c803ec */ 	lwc1	$f8,0x3ec($a2)
/*  f12ce18:	4610403e */ 	c.le.s	$f8,$f16
/*  f12ce1c:	00000000 */ 	nop
/*  f12ce20:	4502002f */ 	bc1fl	.L0f12cee0
/*  f12ce24:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ce28:	c4ca03f8 */ 	lwc1	$f10,0x3f8($a2)
/*  f12ce2c:	460a803e */ 	c.le.s	$f16,$f10
/*  f12ce30:	00000000 */ 	nop
/*  f12ce34:	4502002a */ 	bc1fl	.L0f12cee0
/*  f12ce38:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ce3c:	c4c403f0 */ 	lwc1	$f4,0x3f0($a2)
/*  f12ce40:	4612203e */ 	c.le.s	$f4,$f18
/*  f12ce44:	00000000 */ 	nop
/*  f12ce48:	45020025 */ 	bc1fl	.L0f12cee0
/*  f12ce4c:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ce50:	c4c603fc */ 	lwc1	$f6,0x3fc($a2)
/*  f12ce54:	000778c0 */ 	sll	$t7,$a3,0x3
/*  f12ce58:	01e77823 */ 	subu	$t7,$t7,$a3
/*  f12ce5c:	4606903e */ 	c.le.s	$f18,$f6
/*  f12ce60:	3c014780 */ 	lui	$at,0x4780
/*  f12ce64:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f12ce68:	27a20068 */ 	addiu	$v0,$sp,0x68
/*  f12ce6c:	4502001c */ 	bc1fl	.L0f12cee0
/*  f12ce70:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ce74:	44816000 */ 	mtc1	$at,$f12
/*  f12ce78:	014f1821 */ 	addu	$v1,$t2,$t7
.L0f12ce7c:
/*  f12ce7c:	c4420000 */ 	lwc1	$f2,0x0($v0)
/*  f12ce80:	c46803e8 */ 	lwc1	$f8,0x3e8($v1)
/*  f12ce84:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f12ce88:	46081001 */ 	sub.s	$f0,$f2,$f8
/*  f12ce8c:	460c003c */ 	c.lt.s	$f0,$f12
/*  f12ce90:	00000000 */ 	nop
/*  f12ce94:	45020003 */ 	bc1fl	.L0f12cea4
/*  f12ce98:	c46a03f4 */ 	lwc1	$f10,0x3f4($v1)
/*  f12ce9c:	46000306 */ 	mov.s	$f12,$f0
/*  f12cea0:	c46a03f4 */ 	lwc1	$f10,0x3f4($v1)
.L0f12cea4:
/*  f12cea4:	46025001 */ 	sub.s	$f0,$f10,$f2
/*  f12cea8:	460c003c */ 	c.lt.s	$f0,$f12
/*  f12ceac:	00000000 */ 	nop
/*  f12ceb0:	45000002 */ 	bc1f	.L0f12cebc
/*  f12ceb4:	00000000 */ 	nop
/*  f12ceb8:	46000306 */ 	mov.s	$f12,$f0
.L0f12cebc:
/*  f12cebc:	1445ffef */ 	bne	$v0,$a1,.L0f12ce7c
/*  f12cec0:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f12cec4:	460ca03c */ 	c.lt.s	$f20,$f12
/*  f12cec8:	00000000 */ 	nop
/*  f12cecc:	45020004 */ 	bc1fl	.L0f12cee0
/*  f12ced0:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f12ced4:	46006506 */ 	mov.s	$f20,$f12
/*  f12ced8:	00e04825 */ 	or	$t1,$a3,$zero
/*  f12cedc:	24e70001 */ 	addiu	$a3,$a3,0x1
.L0f12cee0:
/*  f12cee0:	00e8082a */ 	slt	$at,$a3,$t0
/*  f12cee4:	1420ffc1 */ 	bnez	$at,.L0f12cdec
/*  f12cee8:	24c6001c */ 	addiu	$a2,$a2,0x1c
.L0f12ceec:
/*  f12ceec:	3c017f1b */ 	lui	$at,%hi(var7f1b55ac)
/*  f12cef0:	c42c55ac */ 	lwc1	$f12,%lo(var7f1b55ac)($at)
/*  f12cef4:	0009c0c0 */ 	sll	$t8,$t1,0x3
/*  f12cef8:	0309c023 */ 	subu	$t8,$t8,$t1
/*  f12cefc:	460cb082 */ 	mul.s	$f2,$f22,$f12
/*  f12cf00:	3c017f1b */ 	lui	$at,%hi(var7f1b55b0)
/*  f12cf04:	c43255b0 */ 	lwc1	$f18,%lo(var7f1b55b0)($at)
/*  f12cf08:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f12cf0c:	01582021 */ 	addu	$a0,$t2,$t8
/*  f12cf10:	3c017f1b */ 	lui	$at,%hi(var7f1b55b4)
/*  f12cf14:	c42e55b4 */ 	lwc1	$f14,%lo(var7f1b55b4)($at)
/*  f12cf18:	46001406 */ 	mov.s	$f16,$f2
/*  f12cf1c:	00801825 */ 	or	$v1,$a0,$zero
/*  f12cf20:	00001025 */ 	or	$v0,$zero,$zero
.L0f12cf24:
/*  f12cf24:	c46403f4 */ 	lwc1	$f4,0x3f4($v1)
/*  f12cf28:	c46603e8 */ 	lwc1	$f6,0x3e8($v1)
/*  f12cf2c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f12cf30:	2841000c */ 	slti	$at,$v0,0xc
/*  f12cf34:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f12cf38:	460e4002 */ 	mul.s	$f0,$f8,$f14
/*  f12cf3c:	4602003c */ 	c.lt.s	$f0,$f2
/*  f12cf40:	00000000 */ 	nop
/*  f12cf44:	4500000b */ 	bc1f	.L0f12cf74
/*  f12cf48:	00000000 */ 	nop
/*  f12cf4c:	460c0583 */ 	div.s	$f22,$f0,$f12
/*  f12cf50:	c62a000c */ 	lwc1	$f10,0xc($s1)
/*  f12cf54:	46125082 */ 	mul.s	$f2,$f10,$f18
/*  f12cf58:	4602b03c */ 	c.lt.s	$f22,$f2
/*  f12cf5c:	00000000 */ 	nop
/*  f12cf60:	45000002 */ 	bc1f	.L0f12cf6c
/*  f12cf64:	00000000 */ 	nop
/*  f12cf68:	46001586 */ 	mov.s	$f22,$f2
.L0f12cf6c:
/*  f12cf6c:	460cb082 */ 	mul.s	$f2,$f22,$f12
/*  f12cf70:	46001406 */ 	mov.s	$f16,$f2
.L0f12cf74:
/*  f12cf74:	1420ffeb */ 	bnez	$at,.L0f12cf24
/*  f12cf78:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f12cf7c:	8fa200e0 */ 	lw	$v0,0xe0($sp)
/*  f12cf80:	24010001 */ 	addiu	$at,$zero,0x1
/*  f12cf84:	00801825 */ 	or	$v1,$a0,$zero
/*  f12cf88:	14410006 */ 	bne	$v0,$at,.L0f12cfa4
/*  f12cf8c:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f12cf90:	3c017f1b */ 	lui	$at,%hi(var7f1b55b8)
/*  f12cf94:	c42455b8 */ 	lwc1	$f4,%lo(var7f1b55b8)($at)
/*  f12cf98:	46041402 */ 	mul.s	$f16,$f2,$f4
/*  f12cf9c:	10000016 */ 	b	.L0f12cff8
/*  f12cfa0:	3c013f00 */ 	lui	$at,0x3f00
.L0f12cfa4:
/*  f12cfa4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f12cfa8:	14410005 */ 	bne	$v0,$at,.L0f12cfc0
/*  f12cfac:	3c017f1b */ 	lui	$at,%hi(var7f1b55bc)
/*  f12cfb0:	c42655bc */ 	lwc1	$f6,%lo(var7f1b55bc)($at)
/*  f12cfb4:	46061402 */ 	mul.s	$f16,$f2,$f6
/*  f12cfb8:	1000000f */ 	b	.L0f12cff8
/*  f12cfbc:	3c013f00 */ 	lui	$at,0x3f00
.L0f12cfc0:
/*  f12cfc0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f12cfc4:	14410006 */ 	bne	$v0,$at,.L0f12cfe0
/*  f12cfc8:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f12cfcc:	3c017f1b */ 	lui	$at,%hi(var7f1b55c0)
/*  f12cfd0:	c42855c0 */ 	lwc1	$f8,%lo(var7f1b55c0)($at)
/*  f12cfd4:	46081402 */ 	mul.s	$f16,$f2,$f8
/*  f12cfd8:	10000007 */ 	b	.L0f12cff8
/*  f12cfdc:	3c013f00 */ 	lui	$at,0x3f00
.L0f12cfe0:
/*  f12cfe0:	14450004 */ 	bne	$v0,$a1,.L0f12cff4
/*  f12cfe4:	3c017f1b */ 	lui	$at,%hi(var7f1b55c4)
/*  f12cfe8:	c42a55c4 */ 	lwc1	$f10,%lo(var7f1b55c4)($at)
/*  f12cfec:	460a1402 */ 	mul.s	$f16,$f2,$f10
/*  f12cff0:	00000000 */ 	nop
.L0f12cff4:
/*  f12cff4:	3c013f00 */ 	lui	$at,0x3f00
.L0f12cff8:
/*  f12cff8:	44819000 */ 	mtc1	$at,$f18
/*  f12cffc:	27a20068 */ 	addiu	$v0,$sp,0x68
.L0f12d000:
/*  f12d000:	c46c03f4 */ 	lwc1	$f12,0x3f4($v1)
/*  f12d004:	c46e03e8 */ 	lwc1	$f14,0x3e8($v1)
/*  f12d008:	460e6101 */ 	sub.s	$f4,$f12,$f14
/*  f12d00c:	4610203c */ 	c.lt.s	$f4,$f16
/*  f12d010:	00000000 */ 	nop
/*  f12d014:	45020006 */ 	bc1fl	.L0f12d030
/*  f12d018:	46107280 */ 	add.s	$f10,$f14,$f16
/*  f12d01c:	460c7180 */ 	add.s	$f6,$f14,$f12
/*  f12d020:	46123202 */ 	mul.s	$f8,$f6,$f18
/*  f12d024:	10000013 */ 	b	.L0f12d074
/*  f12d028:	e4480000 */ 	swc1	$f8,0x0($v0)
/*  f12d02c:	46107280 */ 	add.s	$f10,$f14,$f16
.L0f12d030:
/*  f12d030:	c4420000 */ 	lwc1	$f2,0x0($v0)
/*  f12d034:	46025001 */ 	sub.s	$f0,$f10,$f2
/*  f12d038:	4600c03c */ 	c.lt.s	$f24,$f0
/*  f12d03c:	00000000 */ 	nop
/*  f12d040:	45020005 */ 	bc1fl	.L0f12d058
/*  f12d044:	46106181 */ 	sub.s	$f6,$f12,$f16
/*  f12d048:	46001100 */ 	add.s	$f4,$f2,$f0
/*  f12d04c:	10000009 */ 	b	.L0f12d074
/*  f12d050:	e4440000 */ 	swc1	$f4,0x0($v0)
/*  f12d054:	46106181 */ 	sub.s	$f6,$f12,$f16
.L0f12d058:
/*  f12d058:	46061001 */ 	sub.s	$f0,$f2,$f6
/*  f12d05c:	4600c03c */ 	c.lt.s	$f24,$f0
/*  f12d060:	00000000 */ 	nop
/*  f12d064:	45020004 */ 	bc1fl	.L0f12d078
/*  f12d068:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f12d06c:	46001201 */ 	sub.s	$f8,$f2,$f0
/*  f12d070:	e4480000 */ 	swc1	$f8,0x0($v0)
.L0f12d074:
/*  f12d074:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f12d078:
/*  f12d078:	1444ffe1 */ 	bne	$v0,$a0,.L0f12d000
/*  f12d07c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f12d080:	c7ae0068 */ 	lwc1	$f14,0x68($sp)
/*  f12d084:	c7b0006c */ 	lwc1	$f16,0x6c($sp)
/*  f12d088:	c7b20070 */ 	lwc1	$f18,0x70($sp)
.L0f12d08c:
/*  f12d08c:	c62c0010 */ 	lwc1	$f12,0x10($s1)
/*  f12d090:	e7b2008c */ 	swc1	$f18,0x8c($sp)
/*  f12d094:	e7b00090 */ 	swc1	$f16,0x90($sp)
/*  f12d098:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f12d09c:	0c0068f4 */ 	jal	cosf
/*  f12d0a0:	afab00c8 */ 	sw	$t3,0xc8($sp)
/*  f12d0a4:	46160502 */ 	mul.s	$f20,$f0,$f22
/*  f12d0a8:	0c0068f7 */ 	jal	sinf
/*  f12d0ac:	c62c0010 */ 	lwc1	$f12,0x10($s1)
/*  f12d0b0:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*  f12d0b4:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f12d0b8:	8fac00dc */ 	lw	$t4,0xdc($sp)
/*  f12d0bc:	c56a0000 */ 	lwc1	$f10,0x0($t3)
/*  f12d0c0:	c7b00090 */ 	lwc1	$f16,0x90($sp)
/*  f12d0c4:	c7b2008c */ 	lwc1	$f18,0x8c($sp)
/*  f12d0c8:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f12d0cc:	240306e0 */ 	addiu	$v1,$zero,0x6e0
/*  f12d0d0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f12d0d4:	00002025 */ 	or	$a0,$zero,$zero
/*  f12d0d8:	02001025 */ 	or	$v0,$s0,$zero
/*  f12d0dc:	e7a400bc */ 	swc1	$f4,0xbc($sp)
/*  f12d0e0:	c5660004 */ 	lwc1	$f6,0x4($t3)
/*  f12d0e4:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f12d0e8:	e7a800c0 */ 	swc1	$f8,0xc0($sp)
/*  f12d0ec:	c56a0008 */ 	lwc1	$f10,0x8($t3)
/*  f12d0f0:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f12d0f4:	e7a400c4 */ 	swc1	$f4,0xc4($sp)
/*  f12d0f8:	46160082 */ 	mul.s	$f2,$f0,$f22
/*  f12d0fc:	c5660000 */ 	lwc1	$f6,0x0($t3)
/*  f12d100:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f12d104:	e7a800b0 */ 	swc1	$f8,0xb0($sp)
/*  f12d108:	c56a0004 */ 	lwc1	$f10,0x4($t3)
/*  f12d10c:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f12d110:	e7a400b4 */ 	swc1	$f4,0xb4($sp)
/*  f12d114:	c5660008 */ 	lwc1	$f6,0x8($t3)
/*  f12d118:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f12d11c:	e7a800b8 */ 	swc1	$f8,0xb8($sp)
/*  f12d120:	c56a0010 */ 	lwc1	$f10,0x10($t3)
/*  f12d124:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f12d128:	e7a400a4 */ 	swc1	$f4,0xa4($sp)
/*  f12d12c:	c5660014 */ 	lwc1	$f6,0x14($t3)
/*  f12d130:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f12d134:	e7a800a8 */ 	swc1	$f8,0xa8($sp)
/*  f12d138:	c56a0018 */ 	lwc1	$f10,0x18($t3)
/*  f12d13c:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f12d140:	e7a400ac */ 	swc1	$f4,0xac($sp)
/*  f12d144:	c5660010 */ 	lwc1	$f6,0x10($t3)
/*  f12d148:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f12d14c:	e7a80098 */ 	swc1	$f8,0x98($sp)
/*  f12d150:	c56a0014 */ 	lwc1	$f10,0x14($t3)
/*  f12d154:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f12d158:	c7aa00bc */ 	lwc1	$f10,0xbc($sp)
/*  f12d15c:	e7a4009c */ 	swc1	$f4,0x9c($sp)
/*  f12d160:	c5660018 */ 	lwc1	$f6,0x18($t3)
/*  f12d164:	460a7101 */ 	sub.s	$f4,$f14,$f10
/*  f12d168:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f12d16c:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f12d170:	e7a800a0 */ 	swc1	$f8,0xa0($sp)
/*  f12d174:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f12d178:	c58a0000 */ 	lwc1	$f10,0x0($t4)
/*  f12d17c:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f12d180:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f12d184:	440d3000 */ 	mfc1	$t5,$f6
/*  f12d188:	00000000 */ 	nop
/*  f12d18c:	a60d0000 */ 	sh	$t5,0x0($s0)
/*  f12d190:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f12d194:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f12d198:	46088281 */ 	sub.s	$f10,$f16,$f8
/*  f12d19c:	c5880004 */ 	lwc1	$f8,0x4($t4)
/*  f12d1a0:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f12d1a4:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f12d1a8:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f12d1ac:	440f2000 */ 	mfc1	$t7,$f4
/*  f12d1b0:	00000000 */ 	nop
/*  f12d1b4:	a60f0002 */ 	sh	$t7,0x2($s0)
/*  f12d1b8:	c7a600c4 */ 	lwc1	$f6,0xc4($sp)
/*  f12d1bc:	c7aa00a0 */ 	lwc1	$f10,0xa0($sp)
/*  f12d1c0:	46069201 */ 	sub.s	$f8,$f18,$f6
/*  f12d1c4:	c5860008 */ 	lwc1	$f6,0x8($t4)
/*  f12d1c8:	a6030008 */ 	sh	$v1,0x8($s0)
/*  f12d1cc:	a600000a */ 	sh	$zero,0xa($s0)
/*  f12d1d0:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f12d1d4:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f12d1d8:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f12d1dc:	44195000 */ 	mfc1	$t9,$f10
/*  f12d1e0:	00000000 */ 	nop
/*  f12d1e4:	a6190004 */ 	sh	$t9,0x4($s0)
/*  f12d1e8:	c7a400b0 */ 	lwc1	$f4,0xb0($sp)
/*  f12d1ec:	c7a800a4 */ 	lwc1	$f8,0xa4($sp)
/*  f12d1f0:	46047180 */ 	add.s	$f6,$f14,$f4
/*  f12d1f4:	c5840000 */ 	lwc1	$f4,0x0($t4)
/*  f12d1f8:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f12d1fc:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f12d200:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f12d204:	440e4000 */ 	mfc1	$t6,$f8
/*  f12d208:	00000000 */ 	nop
/*  f12d20c:	a60e000c */ 	sh	$t6,0xc($s0)
/*  f12d210:	c7aa00b4 */ 	lwc1	$f10,0xb4($sp)
/*  f12d214:	c7a600a8 */ 	lwc1	$f6,0xa8($sp)
/*  f12d218:	460a8100 */ 	add.s	$f4,$f16,$f10
/*  f12d21c:	c58a0004 */ 	lwc1	$f10,0x4($t4)
/*  f12d220:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f12d224:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f12d228:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f12d22c:	44183000 */ 	mfc1	$t8,$f6
/*  f12d230:	00000000 */ 	nop
/*  f12d234:	a618000e */ 	sh	$t8,0xe($s0)
/*  f12d238:	c7a800b8 */ 	lwc1	$f8,0xb8($sp)
/*  f12d23c:	c7a400ac */ 	lwc1	$f4,0xac($sp)
/*  f12d240:	46089280 */ 	add.s	$f10,$f18,$f8
/*  f12d244:	c5880008 */ 	lwc1	$f8,0x8($t4)
/*  f12d248:	a6000014 */ 	sh	$zero,0x14($s0)
/*  f12d24c:	a6000016 */ 	sh	$zero,0x16($s0)
/*  f12d250:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f12d254:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f12d258:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f12d25c:	440d2000 */ 	mfc1	$t5,$f4
/*  f12d260:	00000000 */ 	nop
/*  f12d264:	a60d0010 */ 	sh	$t5,0x10($s0)
/*  f12d268:	c7a600bc */ 	lwc1	$f6,0xbc($sp)
/*  f12d26c:	c7aa0098 */ 	lwc1	$f10,0x98($sp)
/*  f12d270:	46067200 */ 	add.s	$f8,$f14,$f6
/*  f12d274:	c5860000 */ 	lwc1	$f6,0x0($t4)
/*  f12d278:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f12d27c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f12d280:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f12d284:	440f5000 */ 	mfc1	$t7,$f10
/*  f12d288:	00000000 */ 	nop
/*  f12d28c:	a60f0018 */ 	sh	$t7,0x18($s0)
/*  f12d290:	c7a400c0 */ 	lwc1	$f4,0xc0($sp)
/*  f12d294:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f12d298:	46048180 */ 	add.s	$f6,$f16,$f4
/*  f12d29c:	c5840004 */ 	lwc1	$f4,0x4($t4)
/*  f12d2a0:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f12d2a4:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f12d2a8:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f12d2ac:	44194000 */ 	mfc1	$t9,$f8
/*  f12d2b0:	00000000 */ 	nop
/*  f12d2b4:	a619001a */ 	sh	$t9,0x1a($s0)
/*  f12d2b8:	c7aa00c4 */ 	lwc1	$f10,0xc4($sp)
/*  f12d2bc:	c7a600a0 */ 	lwc1	$f6,0xa0($sp)
/*  f12d2c0:	460a9100 */ 	add.s	$f4,$f18,$f10
/*  f12d2c4:	c58a0008 */ 	lwc1	$f10,0x8($t4)
/*  f12d2c8:	a6000020 */ 	sh	$zero,0x20($s0)
/*  f12d2cc:	a6030022 */ 	sh	$v1,0x22($s0)
/*  f12d2d0:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f12d2d4:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f12d2d8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f12d2dc:	440e3000 */ 	mfc1	$t6,$f6
/*  f12d2e0:	00000000 */ 	nop
/*  f12d2e4:	a60e001c */ 	sh	$t6,0x1c($s0)
/*  f12d2e8:	c7a800b0 */ 	lwc1	$f8,0xb0($sp)
/*  f12d2ec:	c7a400a4 */ 	lwc1	$f4,0xa4($sp)
/*  f12d2f0:	46087281 */ 	sub.s	$f10,$f14,$f8
/*  f12d2f4:	c5880000 */ 	lwc1	$f8,0x0($t4)
/*  f12d2f8:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f12d2fc:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f12d300:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f12d304:	44182000 */ 	mfc1	$t8,$f4
/*  f12d308:	00000000 */ 	nop
/*  f12d30c:	a6180024 */ 	sh	$t8,0x24($s0)
/*  f12d310:	c7a600b4 */ 	lwc1	$f6,0xb4($sp)
/*  f12d314:	c7aa00a8 */ 	lwc1	$f10,0xa8($sp)
/*  f12d318:	3c180430 */ 	lui	$t8,0x430
/*  f12d31c:	46068201 */ 	sub.s	$f8,$f16,$f6
/*  f12d320:	c5860004 */ 	lwc1	$f6,0x4($t4)
/*  f12d324:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f12d328:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f12d32c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f12d330:	440d5000 */ 	mfc1	$t5,$f10
/*  f12d334:	00000000 */ 	nop
/*  f12d338:	a60d0026 */ 	sh	$t5,0x26($s0)
/*  f12d33c:	c7a400b8 */ 	lwc1	$f4,0xb8($sp)
/*  f12d340:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f12d344:	46049181 */ 	sub.s	$f6,$f18,$f4
/*  f12d348:	c5840008 */ 	lwc1	$f4,0x8($t4)
/*  f12d34c:	a603002c */ 	sh	$v1,0x2c($s0)
/*  f12d350:	a603002e */ 	sh	$v1,0x2e($s0)
/*  f12d354:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f12d358:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f12d35c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f12d360:	440f4000 */ 	mfc1	$t7,$f8
/*  f12d364:	00000000 */ 	nop
/*  f12d368:	a60f0028 */ 	sh	$t7,0x28($s0)
.L0f12d36c:
/*  f12d36c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f12d370:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f12d374:	1485fffd */ 	bne	$a0,$a1,.L0f12d36c
/*  f12d378:	a040fffb */ 	sb	$zero,-0x5($v0)
/*  f12d37c:	8fa200d8 */ 	lw	$v0,0xd8($sp)
/*  f12d380:	37180030 */ 	ori	$t8,$t8,0x30
/*  f12d384:	02002025 */ 	or	$a0,$s0,$zero
/*  f12d388:	00402825 */ 	or	$a1,$v0,$zero
/*  f12d38c:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f12d390:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f12d394:	afa200d8 */ 	sw	$v0,0xd8($sp)
/*  f12d398:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f12d39c:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f12d3a0:	8fa300d8 */ 	lw	$v1,0xd8($sp)
/*  f12d3a4:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f12d3a8:	3c19b100 */ 	lui	$t9,0xb100
/*  f12d3ac:	37390032 */ 	ori	$t9,$t9,0x32
/*  f12d3b0:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f12d3b4:	240d2010 */ 	addiu	$t5,$zero,0x2010
/*  f12d3b8:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f12d3bc:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f12d3c0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f12d3c4:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f12d3c8:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f12d3cc:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f12d3d0:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f12d3d4:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f12d3d8:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
/*  f12d3dc:	03e00008 */ 	jr	$ra
/*  f12d3e0:	24620008 */ 	addiu	$v0,$v1,0x8
);
