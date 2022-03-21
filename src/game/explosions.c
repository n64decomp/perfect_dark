#include <ultra64.h>
#include "constants.h"
#include "game/chraction.h"
#include "game/dlights.h"
#include "game/chr.h"
#include "game/prop.h"
#include "game/game_091e10.h"
#include "game/propsnd.h"
#include "game/game_0b3350.h"
#include "game/game_0b4950.h"
#include "game/explosions.h"
#include "game/smoke.h"
#include "game/bg.h"
#include "game/game_1668e0.h"
#include "game/file.h"
#include "game/gfxmemory.h"
#include "game/mplayer/mplayer.h"
#include "game/propobj.h"
#include "game/utils.h"
#include "game/wallhit.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "data.h"
#include "types.h"

struct explosion *g_Explosions;
s32 g_MaxExplosions;

s32 var8007e4a0 = 0;
s32 var8007e4a4 = 0;
f32 g_ExplosionDamageReceivedScale = 1;
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
		ret = cd0002a564(&prop->pos, prop->rooms, &y, 0, &sp88, &sp68);
		sp100.x = prop->pos.x;
		sp100.y = y;
		sp100.z = prop->pos.z;
	} else {
		ret = cd0002a564(pos, rooms, &y, 0, &sp88, &sp68);
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

	if (exp->type == EXPLOSIONTYPE_14 && frame > TICKS(32)) {
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

	if (exp->type == EXPLOSIONTYPE_14 && frame > TICKS(32)) {
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
				&& (g_ChrSlots[i].prop->flags & PROPFLAG_ENABLED)) {
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
		s32 *ptr = (s32 *)&glassDestroy;

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
/*  f12a190:	0fc18ad9 */ 	jal	propExecuteTickOperation
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
/*  f12a2cc:	0fc1814e */ 	jal	propActivateThisFrame
/*  f12a2d0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f12a2d4:	0fc180bc */ 	jal	propEnable
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
);

void explosion0f12acd4(void)
{
	var8007e4a0 = 6;
	var8007e4a4 = 6;
}

void explosionsUpdateShake(struct coord *arg0, struct coord *arg1, struct coord *arg2)
{
	u32 stack[4];
	f32 sp54;
	f32 sp50;
	s32 i;
	f32 intensity;

	if (var8007e4a0 == 0) {
		viShake(0);
		return;
	}

	sp54 = cosf(0.8f) * arg1->f[0] - sinf(0.8f) * arg1->f[2];
	sp50 = sinf(0.8f) * arg1->f[0] + cosf(0.8f) * arg1->f[2];

	intensity = 0.0f;

	for (i = 0; i < g_MaxExplosions; i++) {
		struct prop *prop = g_Explosions[i].prop;

		if (prop) {
			f32 xdiff = prop->pos.x - arg0->x;
			f32 ydiff = prop->pos.y - arg0->y;
			f32 zdiff = prop->pos.z - arg0->z;

			f32 dist = sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);
			f32 mult;

			if (dist == 0.0f) {
				dist = 0.0001f;
			}

			mult = g_ExplosionTypes[g_Explosions[i].type].innersize / dist;

			intensity += mult * 15.0f;
		}
	}

	if (var8007e4a4 > 0) {
		var8007e4a4--;
		intensity++;
	}

	var8007e4a0--;

	if (var8007e4a0 & 2) {
		arg2->y = intensity;
		intensity = -intensity;
	} else {
		arg2->y = -intensity;
	}

	arg2->x = intensity * sp54;
	arg2->z = intensity * sp50;

	viShake(var8007e4a0 * intensity);
}

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

void explosionInflictDamage(struct prop *expprop)
{
	s32 stack;
	struct explosion *exp = expprop->explosion;
	struct explosiontype *type = &g_ExplosionTypes[exp->type];
	s16 *propnumptr;
	s16 propnums[256];
	bool isfirstframe = exp->age <= 0;
	s32 i;
	f32 k;
	s32 j;
	f32 damageradius;

	if (g_Vars.lvupdate240_60 <= 0) {
		return;
	}

	if (type->damage <= 0.0f) {
		return;
	}

	if (isfirstframe) {
		damageradius = type->damageradius;
	} else {
#if PAL
		damageradius = type->blastradius + (type->damageradius - type->blastradius) * exp->age / (type->duration * 0.8333333f);
#else
		damageradius = type->blastradius + (type->damageradius - type->blastradius) * exp->age / type->duration;
#endif

		if (damageradius > type->damageradius) {
			damageradius = type->damageradius;
		}
	}

#if PAL
	if (exp->age > (s32)((type->duration + 7.0f * type->flarespeed) * 0.8333333f)) {
		return;
	}
#else
	if (exp->age > (s32)(type->duration + 7.0f * type->flarespeed)) {
		return;
	}
#endif

	// Flicker room lighting
	for (i = 0; expprop->rooms[i] != -1; i++) {
		if (random() % 2048 <= 240) {
			roomAdjustLighting(expprop->rooms[i], type->rangeh, 255);
		}
	}

	// Break lights
	for (i = 0; expprop->rooms[i] != -1; i++) {
		s32 roomnum = expprop->rooms[i];

		if (roomnum != 0) {
			s32 numlights = g_Rooms[roomnum].numlights;
			f32 xdist = expprop->pos.f[0];
			f32 ydist = expprop->pos.f[1];
			f32 zdist = expprop->pos.f[2];
			struct coord sp164;

			xdist -= g_BgRooms[roomnum].pos.f[0];
			ydist -= g_BgRooms[roomnum].pos.f[1];
			zdist -= g_BgRooms[roomnum].pos.f[2];

			for (j = 0; j < numlights; j++) {
				if (lightIsHealthy(roomnum, j)
						&& lightIsVulnerable(roomnum, j)
						&& lightGetBboxCentre(roomnum, j, &sp164)) {
					struct coord sp158;
					struct coord sp14c;

					sp14c.f[0] = sp164.f[0] - xdist; \
					sp14c.f[1] = sp164.f[1] - ydist; \
					sp14c.f[2] = sp164.f[2] - zdist;

					sp158.f[0] = damageradius;
					sp158.f[1] = damageradius;
					sp158.f[2] = damageradius;

					if (func0f1773c8(&sp14c, &sp158)) {
						roomSetLightBroken(roomnum, j);
					}
				}
			}
		}
	}

	// Damage props
	roomGetProps(expprop->rooms, propnums, 256);

	propnumptr = propnums;

	while (*propnumptr >= 0) {
		struct prop *prop = &g_Vars.props[*propnumptr];

		if (prop != exp->source && prop->timetoregen == 0) {
			if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_DOOR) {
				f32 xdist;
				f32 ydist;
				f32 zdist;
				struct coord sp130;
				struct coord sp124;
				struct defaultobj *obj = prop->obj;
				bool candamage = false;

				xdist = prop->pos.x - expprop->pos.x;
				ydist = prop->pos.y - expprop->pos.y;
				zdist = prop->pos.z - expprop->pos.z;

				if (candamage);

#if VERSION >= VERSION_NTSC_1_0
				if (obj)
#endif
				{
					if (xdist <= damageradius && xdist >= -damageradius
							&& ydist <= damageradius && ydist >= -damageradius
							&& zdist <= damageradius && zdist >= -damageradius) {

						if (func0f092304(obj, &sp130, &sp124)) {
							if (func0f12af5c(exp, prop, &sp130, &sp124)) {
								candamage = true;
							}
						} else {
							candamage = true;
						}
					}

					if (candamage && prop->type == PROPTYPE_WEAPON) {
						struct weaponobj *weapon = prop->weapon;

						if (weapon && weapon->weaponnum == WEAPON_SKROCKET) {
							weapon->timer240 = 0;
						}
					}

					if (candamage) {
						f32 f0;
						f32 xfrac;
						f32 yfrac;
						f32 zfrac;
						f32 minfrac;

						xfrac = f0 = xdist / damageradius;

						if (xfrac < 0.0f) {
							xfrac = -xfrac;
						}

						xfrac = 1.0f - xfrac;

						yfrac = f0 = ydist / damageradius;

						if (yfrac < 0.0f) {
							yfrac = -yfrac;
						}

						yfrac = 1.0f - yfrac;

						zfrac = f0 = zdist / damageradius;

						if (zfrac < 0.0f) {
							zfrac = -zfrac;
						}

						zfrac = 1.0f - zfrac;

						minfrac = xfrac;

						if (yfrac < minfrac) {
							minfrac = yfrac;
						}

						if (zfrac < minfrac) {
							minfrac = zfrac;
						}

						minfrac = (minfrac * 0.7f + 0.3f) * type->damage;

						if (g_Vars.antiplayernum >= 0
								&& g_Vars.antiplayernum == exp->owner
								&& (obj->flags2 & OBJFLAG2_00000001)) {
							// anti cannot damage this obj
						} else if (isfirstframe) {
							// Unblock path if this object is a path blocker
							objUpdateLinkedScenery(obj, expprop);

							// Damage the object
							if ((obj->hidden & OBJHFLAG_00001000) == 0
									&& (obj->flags2 & (OBJFLAG2_LINKEDTOSAFE | OBJFLAG2_00200000)) == 0) {
								func0f085050(prop, (random() * (1.0f / U32_MAX) * 0.5f + 1.0f) * minfrac, &prop->pos, 0x22, exp->owner);
							}

							// Give object momentum if it's a hover obj
							if ((obj->hidden & OBJHFLAG_MOUNTED) == 0
									&& (obj->hidden & OBJHFLAG_GRABBED) == 0
									&& (obj->flags3 & OBJFLAG3_PUSHABLE)) {
								f32 dist;
								struct coord spf4;
								spf4.x = prop->pos.x - expprop->pos.x;
								spf4.y = 0.0f;
								spf4.z = prop->pos.z - expprop->pos.z;

								if (spf4.f[0] != 0.0f || spf4.f[2] != 0.0f) {
									dist = sqrtf(spf4.f[0] * spf4.f[0] + spf4.f[2] * spf4.f[2]);

									if (dist > 0.0f) {
										f32 tmp = minfrac * 4.0f / dist;
										spf4.x *= tmp;
										spf4.z *= tmp;
									}
								}

								func0f082a1c(obj, &spf4, 0.0f, 1, 1);
							}
						} else if (objIsHealthy(obj)) {
							// Sustained damage
							minfrac *= 0.05f * g_Vars.lvupdate240freal;

							if ((obj->hidden & OBJHFLAG_00001000) == 0
									&& (obj->flags2 & (OBJFLAG2_LINKEDTOSAFE | OBJFLAG2_00200000)) == 0) {
								func0f085050(prop, (random() * (1.0f / U32_MAX) * 0.5f + 1.0f) * minfrac,
										&prop->pos, 0x22, exp->owner);
							}
						}
					}
				}
			} else if (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER) {
				f32 xdist = prop->pos.f[0] - expprop->pos.f[0];
				f32 ydist = prop->pos.f[1] - expprop->pos.f[1];
				f32 zdist = prop->pos.f[2] - expprop->pos.f[2];
				f32 width;
				f32 ymax;
				f32 ymin;
				struct coord spcc;
				struct coord spc0;

				bool candamage = false;

				if (prop->type == PROPTYPE_CHR);

				if (xdist <= damageradius && xdist >= -damageradius
						&& ydist <= damageradius && ydist >= -damageradius
						&& zdist <= damageradius && zdist >= -damageradius) {
					propGetBbox(prop, &width, &ymax, &ymin);

					width -= 20.0f;

					if (width <= 0.0f) {
						width = 0.0f;
					}

					spcc.f[0] = prop->pos.f[0] - width;
					spcc.f[1] = ymin;
					spcc.f[2] = prop->pos.f[2] - width;

					spc0.f[0] = prop->pos.f[0] + width;
					spc0.f[1] = ymax;
					spc0.f[2] = prop->pos.f[2] + width;

					if (func0f12af5c(exp, prop, &spcc, &spc0)) {
						candamage = true;
					}
				}

				if (candamage) {
					struct prop *ownerprop = NULL;
					f32 xfrac = xdist / damageradius;
					f32 yfrac = ydist / damageradius;
					f32 zfrac = zdist / damageradius;
					struct coord spa0 = {0, 0, 0};
					struct chrdata *chr = prop->chr;
					f32 minfrac;

					if (xfrac < 0.0f) {
						xfrac = -xfrac;
					}

					if (yfrac < 0.0f) {
						yfrac = -yfrac;
					}

					if (zfrac < 0.0f) {
						zfrac = -zfrac;
					}

					xfrac = 1.0f - xfrac;
					yfrac = 1.0f - yfrac;
					zfrac = 1.0f - zfrac;

					minfrac = xfrac;

					if (yfrac < minfrac) {
						minfrac = yfrac;
					}

					if (zfrac < minfrac) {
						minfrac = zfrac;
					}

					minfrac *= minfrac;
					minfrac = minfrac * type->damage * 8.0f;

					if (isfirstframe) {
						if (xdist != 0.0f || zdist != 0.0f) {
							f32 dist = sqrtf(xdist * xdist + zdist * zdist);

							if (dist > 0.0f) {
								xdist *= 1.0f / dist;
								zdist *= 1.0f / dist;

								spa0.x = xdist;
								spa0.y = 0.0f;
								spa0.z = zdist;
							}
						}
					} else {
						minfrac *= 0.05f * g_Vars.lvupdate240freal;
					}

					if (g_Vars.normmplayerisrunning) {
						struct chrdata *ownerchr = mpGetChrFromPlayerIndex(exp->owner);

						if (ownerchr) {
							ownerprop = ownerchr->prop;
						}
					} else if (exp->owner == g_Vars.bondplayernum) {
						ownerprop = g_Vars.bond->prop;
					} else if (g_Vars.coopplayernum >= 0 && exp->owner == g_Vars.coopplayernum) {
						ownerprop = g_Vars.coop->prop;
					} else if (g_Vars.antiplayernum >= 0 && exp->owner == g_Vars.antiplayernum) {
						ownerprop = g_Vars.anti->prop;
					}

					chrDamageByExplosion(chr, minfrac, &spa0, ownerprop, &expprop->pos);

					if (prop->type == PROPTYPE_CHR && !isfirstframe) {
						chrDisfigure(chr, &expprop->pos, damageradius);
					}
				}
			}
		}

		propnumptr++;
	}
}

u32 explosionTick(struct prop *prop)
{
	struct explosion *exp = prop->explosion;
	struct explosiontype *type = &g_ExplosionTypes[exp->type];
	s32 i;
	s32 j;
	s32 k;
	f32 hrange;
	f32 vrange;
	f32 lvupdate;
	struct coord bbmin;
	struct coord bbmax;
	s16 maxage;
	s32 numpartstocreate;
	struct coord sp11c;
	struct coord sp110;
	u32 stack[2];
	struct coord spfc;
	struct coord spf0;
	s32 bb;
	bool s3;
	struct chrdata *chr;
	f32 scorchsize;
	struct hitthing spb0;

	maxage = TICKS(type->duration);

	if (g_Vars.lvupdate240_60 == 0) {
		return TICKOP_NONE;
	}

	lvupdate = g_Vars.lvupdate240_60 < TICKS(15) ? g_Vars.lvupdate240_60 : (s32)TICKS(15);

#if PAL
	if (exp->age >= 7 && exp->age < maxage)
#else
	if (exp->age >= 8 && exp->age < maxage)
#endif
	{
		hrange = explosionGetHorizontalRangeAtFrame(exp, exp->age);
		vrange = explosionGetVerticalRangeAtFrame(exp, exp->age);

		sp11c.x = prop->pos.x - hrange * 0.5f;
		sp11c.y = prop->pos.y - vrange * 0.5f;
		sp11c.z = prop->pos.z - hrange * 0.5f;

		sp110.x = prop->pos.x + hrange * 0.5f;
		sp110.y = prop->pos.y + vrange * 0.5f;
		sp110.z = prop->pos.z + hrange * 0.5f;

		// Barrel explosions ascend upwards
		if (exp->type == EXPLOSIONTYPE_14 && exp->age < TICKS(32)) {
			prop->pos.y += PALUPF(10.0f) * lvupdate;
		}

		// Create new parts
		numpartstocreate = (s32)((f32)type->propagationrate * exp->age / maxage) + 1;

		for (i = 0; i < numpartstocreate; i++) {
			for (j = 0; j < 40; j++) {
				if (exp->parts[j].frame == 0) {
					if (exp->numbb == 0 || exp->type == EXPLOSIONTYPE_25) {
						spfc.f[0] = sp11c.f[0];
						spfc.f[1] = sp11c.f[1];
						spfc.f[2] = sp11c.f[2];

						spf0.f[0] = sp110.f[0];
						spf0.f[1] = sp110.f[1];
						spf0.f[2] = sp110.f[2];

						bb = 0;
					} else {
						bb = j % exp->numbb;

						spfc.x = exp->bbs[bb].unk00.x;
						spfc.y = exp->bbs[bb].unk00.y;
						spfc.z = exp->bbs[bb].unk00.z;

						spf0.x = exp->bbs[bb].unk0c.x;
						spf0.y = exp->bbs[bb].unk0c.y;
						spf0.z = exp->bbs[bb].unk0c.z;

						if (spfc.x < sp11c.x) {
							spfc.x = sp11c.x;
						}

						if (spfc.y < sp11c.y) {
							spfc.y = sp11c.y;
						}

						if (spfc.z < sp11c.z) {
							spfc.z = sp11c.z;
						}

						if (sp110.x < spf0.x) {
							spf0.x = sp110.x;
						}

						if (sp110.y < spf0.y) {
							spf0.y = sp110.y;
						}

						if (sp110.z < spf0.z) {
							spf0.z = sp110.z;
						}

						if (spf0.x <= spfc.x || spf0.y <= spfc.y || spf0.z <= spfc.z) {
							bb = 0;

							spfc.x = exp->bbs[bb].unk00.x;
							spfc.y = exp->bbs[bb].unk00.y;
							spfc.z = exp->bbs[bb].unk00.z;

							spf0.x = exp->bbs[bb].unk0c.x;
							spf0.y = exp->bbs[bb].unk0c.y;
							spf0.z = exp->bbs[bb].unk0c.z;

							if (spfc.x < sp11c.x) {
								spfc.x = sp11c.x;
							}

							if (spfc.y < sp11c.y) {
								spfc.y = sp11c.y;
							}

							if (spfc.z < sp11c.z) {
								spfc.z = sp11c.z;
							}

							if (sp110.x < spf0.x) {
								spf0.x = sp110.x;
							}

							if (sp110.y < spf0.y) {
								spf0.y = sp110.y;
							}

							if (sp110.z < spf0.z) {
								spf0.z = sp110.z;
							}
						}
					}

					exp->parts[j].pos.f[0] = spfc.f[0] + random() * (1.0f / U32_MAX) * (spf0.f[0] - spfc.f[0]);
					exp->parts[j].pos.f[1] = spfc.f[1] + random() * (1.0f / U32_MAX) * (spf0.f[1] - spfc.f[1]);
					exp->parts[j].pos.f[2] = spfc.f[2] + random() * (1.0f / U32_MAX) * (spf0.f[2] - spfc.f[2]);
					exp->parts[j].bb = bb;
					exp->parts[j].frame = 1;
					exp->parts[j].size = (1.0f + random() * (1.0f / U32_MAX) * 0.5f) * type->innersize;
					exp->parts[j].rot = random() * (1.0f / U32_MAX) * M_BADTAU;
					break;
				}
			}
		}
	}

	explosionGetBboxAtFrame(&bbmin, &bbmax, exp->age, prop);
	func0f1650d0(&bbmin, &bbmax, prop->rooms, 7, 0);
	explosionInflictDamage(prop);

	// Play boom sound if this is the first frame
	if (exp->age == 0) {
		func0f0939f8(NULL, NULL, type->sound, -1, -1, 0, 0, 0, &exp->prop->pos, -1.0f, exp->prop->rooms, -1, -1.0f, -1.0f, -1.0f);
	}

	for (k = 0; k < (s32)lvupdate; k++) {
		exp->age++;

		for (j = 0; j < 40; j++) {
			if (exp->parts[j].frame > 0) {
				exp->parts[j].frame++;
			}
		}

		// Create smoke
		if (((exp->age == TICKS(15) && exp->type == EXPLOSIONTYPE_14)
					|| (exp->age == maxage - TICKS(20) && exp->type != EXPLOSIONTYPE_14))
				&& (exp->type != EXPLOSIONTYPE_1 || (random() % 2) == 0)) {
			if (exp->source) {
				smokeCreateSimple(&exp->source->pos, exp->source->rooms, type->smoketype);
			} else {
				smokeCreateSimple(&prop->pos, prop->rooms, type->smoketype);
			}
		}

		// Make scorch at half duration
		if (exp->age == (maxage >> 1) && exp->makescorch) {
			s3 = false;
			scorchsize = 2.0f * type->innersize;

			if (scorchsize > 100.0f) {
				scorchsize = 100.0f;
			}

			scorchsize *= 0.8f + 0.2f * (random() * (1.0f / U32_MAX));

			if (g_Vars.normmplayerisrunning) {
				chr = mpGetChrFromPlayerIndex(exp->owner);
			} else if (g_Vars.antiplayernum >= 0 && exp->owner == g_Vars.antiplayernum) {
				chr = g_Vars.anti->prop->chr;
			} else if (g_Vars.coopplayernum >= 0 && exp->owner == g_Vars.coopplayernum) {
				chr = g_Vars.coop->prop->chr;
			} else {
				chr = g_Vars.bond->prop->chr;
			}

			if (g_Rooms[exp->room].gfxdata) {
				// Not 100% sure about spb0 being a struct hitthing, but it's likely
				if (g_Rooms[exp->room].gfxdata->unk0c && func0f161520(&prop->pos, &exp->unk3d0, exp->room, &spb0)) {
					s3 = spb0.unk2c == 2;
				}

				func0f13f504(&exp->unk3d0, &exp->unk3dc, &prop->pos, 0, 0, 7, exp->room, 0, 0, -1, 0, chr, scorchsize, scorchsize, 0xff, 0xff, 0, 0, 0, s3);
			}
		}
	}

	// Free explosion if finished
#if PAL
	if (exp->age >= maxage + (s32)((16.0f * type->flarespeed) * 0.8333333f))
#else
	if (exp->age >= maxage + (s32)(16.0f * type->flarespeed))
#endif
	{
		if (exp->type != EXPLOSIONTYPE_1) {
			propUnsetDangerous(exp->prop);
		}

		exp->prop = NULL;
		return TICKOP_FREE;
	}

	return TICKOP_NONE;
}

u32 explosionTickPlayer(struct prop *prop)
{
	Mtxf *matrix = currentPlayerGetMatrix1740();

	prop->z = -(matrix->m[0][2] * prop->pos.x + matrix->m[1][2] * prop->pos.y + matrix->m[2][2] * prop->pos.z + matrix->m[3][2]);

	if (prop->z < 100) {
		prop->z *= 0.5f;
	} else {
		prop->z -= 100;
	}

	prop->flags |= PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONTHISSCREENTHISTICK;

	return TICKOP_NONE;
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
		if (g_Rooms[roomnum].gfxdata
				&& g_Rooms[roomnum].loaded240
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

		gSPDisplayList(gdl++, g_TexGdl2);

		colour = gfxAllocateColours(1);

		if (USINGDEVICE(DEVICE_NIGHTVISION) || USINGDEVICE(DEVICE_IRSCANNER)) {
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
			mainOverrideVariable("ecol", &var8007e93c);
			*colour = 0xffffffff;
			*colour = var8007e93c;
		}

		gDPSetColorArray(gdl++, osVirtualToPhysical(colour), 1);

		for (i = 14; i >= 0; i--) {
			gDPSetTextureImage(gdl++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, g_ExplosionTexturePairs[i].texturenum1);
			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, 1567, 0);

			gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, g_ExplosionTexturePairs[i].texturenum2);
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
