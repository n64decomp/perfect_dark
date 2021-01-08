#include <ultra64.h>
#include "constants.h"
#include "game/bondmove.h"
#include "game/bondwalk.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/dlights.h"
#include "game/chr/chr.h"
#include "game/game_0601b0.h"
#include "game/game_092610.h"
#include "game/game_095320.h"
#include "game/floor.h"
#include "game/ceil.h"
#include "game/game_097ba0.h"
#include "game/game_0b0420.h"
#include "game/game_0b3350.h"
#include "game/game_0b63b0.h"
#include "game/game_127910.h"
#include "game/explosions/explosions.h"
#include "game/smoke/smoke.h"
#include "game/sparks/sparks.h"
#include "game/game_157db0.h"
#include "game/game_190260.h"
#include "game/training/training.h"
#include "game/pad.h"
#include "game/propobj.h"
#include "game/splat.h"
#include "game/wallhit.h"
#include "gvars/gvars.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_1a500.h"
#include "lib/lib_233c0.h"
#include "lib/lib_317f0.h"
#include "lib/lib_48830.h"
#include "lib/lib_4a360.h"
#include "types.h"

f32 var80069880 = 1;

GLOBAL_ASM(
glabel func0f0601b0
/*  f0601b0:	3c0c800a */ 	lui	$t4,%hi(g_Vars)
/*  f0601b4:	258c9fc0 */ 	addiu	$t4,$t4,%lo(g_Vars)
/*  f0601b8:	8d83033c */ 	lw	$v1,0x33c($t4)
/*  f0601bc:	8d840354 */ 	lw	$a0,0x354($t4)
/*  f0601c0:	27bdfcb8 */ 	addiu	$sp,$sp,-840
/*  f0601c4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0601c8:	10640012 */ 	beq	$v1,$a0,.L0f060214
/*  f0601cc:	27ad000c */ 	addiu	$t5,$sp,0xc
/*  f0601d0:	24060006 */ 	addiu	$a2,$zero,0x6
/*  f0601d4:	906e0001 */ 	lbu	$t6,0x1($v1)
.L0f0601d8:
/*  f0601d8:	31cf0006 */ 	andi	$t7,$t6,0x6
/*  f0601dc:	54cf000b */ 	bnel	$a2,$t7,.L0f06020c
/*  f0601e0:	8c630020 */ 	lw	$v1,0x20($v1)
/*  f0601e4:	c4640014 */ 	lwc1	$f4,0x14($v1)
/*  f0601e8:	00022880 */ 	sll	$a1,$v0,0x2
/*  f0601ec:	01a5c021 */ 	addu	$t8,$t5,$a1
/*  f0601f0:	e7040000 */ 	swc1	$f4,0x0($t8)
/*  f0601f4:	8d990348 */ 	lw	$t9,0x348($t4)
/*  f0601f8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0601fc:	03257021 */ 	addu	$t6,$t9,$a1
/*  f060200:	adc30000 */ 	sw	$v1,0x0($t6)
/*  f060204:	8d840354 */ 	lw	$a0,0x354($t4)
/*  f060208:	8c630020 */ 	lw	$v1,0x20($v1)
.L0f06020c:
/*  f06020c:	5464fff2 */ 	bnel	$v1,$a0,.L0f0601d8
/*  f060210:	906e0001 */ 	lbu	$t6,0x1($v1)
.L0f060214:
/*  f060214:	8d8f0348 */ 	lw	$t7,0x348($t4)
/*  f060218:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f06021c:	ad820350 */ 	sw	$v0,0x350($t4)
/*  f060220:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f060224:	af200000 */ 	sw	$zero,0x0($t9)
/*  f060228:	8d8f0348 */ 	lw	$t7,0x348($t4)
/*  f06022c:	00027080 */ 	sll	$t6,$v0,0x2
/*  f060230:	27ad000c */ 	addiu	$t5,$sp,0xc
/*  f060234:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f060238:	ad98034c */ 	sw	$t8,0x34c($t4)
/*  f06023c:	1840002a */ 	blez	$v0,.L0f0602e8
/*  f060240:	00002825 */ 	or	$a1,$zero,$zero
/*  f060244:	3c01cf80 */ 	lui	$at,0xcf80
/*  f060248:	44816000 */ 	mtc1	$at,$f12
/*  f06024c:	00000000 */ 	nop
/*  f060250:	00a2082a */ 	slt	$at,$a1,$v0
.L0f060254:
/*  f060254:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f060258:	46006006 */ 	mov.s	$f0,$f12
/*  f06025c:	1020000d */ 	beqz	$at,.L0f060294
/*  f060260:	00a01825 */ 	or	$v1,$a1,$zero
/*  f060264:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f060268:	01b92021 */ 	addu	$a0,$t5,$t9
.L0f06026c:
/*  f06026c:	c4820000 */ 	lwc1	$f2,0x0($a0)
/*  f060270:	4602003c */ 	c.lt.s	$f0,$f2
/*  f060274:	00000000 */ 	nop
/*  f060278:	45020004 */ 	bc1fl	.L0f06028c
/*  f06027c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f060280:	46001006 */ 	mov.s	$f0,$f2
/*  f060284:	00603025 */ 	or	$a2,$v1,$zero
/*  f060288:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f06028c:
/*  f06028c:	1462fff7 */ 	bne	$v1,$v0,.L0f06026c
/*  f060290:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f060294:
/*  f060294:	04c00011 */ 	bltz	$a2,.L0f0602dc
/*  f060298:	00053880 */ 	sll	$a3,$a1,0x2
/*  f06029c:	8d840348 */ 	lw	$a0,0x348($t4)
/*  f0602a0:	00065080 */ 	sll	$t2,$a2,0x2
/*  f0602a4:	01a74821 */ 	addu	$t1,$t5,$a3
/*  f0602a8:	008a7021 */ 	addu	$t6,$a0,$t2
/*  f0602ac:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f0602b0:	00874021 */ 	addu	$t0,$a0,$a3
/*  f0602b4:	8d030000 */ 	lw	$v1,0x0($t0)
/*  f0602b8:	c5200000 */ 	lwc1	$f0,0x0($t1)
/*  f0602bc:	ad0f0000 */ 	sw	$t7,0x0($t0)
/*  f0602c0:	01aa5821 */ 	addu	$t3,$t5,$t2
/*  f0602c4:	c5660000 */ 	lwc1	$f6,0x0($t3)
/*  f0602c8:	8d980348 */ 	lw	$t8,0x348($t4)
/*  f0602cc:	e5260000 */ 	swc1	$f6,0x0($t1)
/*  f0602d0:	030ac821 */ 	addu	$t9,$t8,$t2
/*  f0602d4:	af230000 */ 	sw	$v1,0x0($t9)
/*  f0602d8:	e5600000 */ 	swc1	$f0,0x0($t3)
.L0f0602dc:
/*  f0602dc:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0602e0:	54a2ffdc */ 	bnel	$a1,$v0,.L0f060254
/*  f0602e4:	00a2082a */ 	slt	$at,$a1,$v0
.L0f0602e8:
/*  f0602e8:	03e00008 */ 	jr	$ra
/*  f0602ec:	27bd0348 */ 	addiu	$sp,$sp,0x348
);

void propShow(struct prop *prop)
{
	prop->flags |= PROPFLAG_TANGIBLE;
}

void propHide(struct prop *prop)
{
	struct prop **ptr;

	prop->flags &= ~PROPFLAG_TANGIBLE;

	for (ptr = g_Vars.tangibleprops; ptr < g_Vars.unk00034c; ptr++) {
		if (*ptr == prop) {
			*ptr = NULL;
		}
	}
}

struct prop *propAllocate(void)
{
	struct prop *prop = g_Vars.freeprops;

	if (g_Vars.freeprops) {
		g_Vars.freeprops = g_Vars.freeprops->next;

		prop->next = NULL;
		prop->prev = NULL;
		prop->parent = NULL;
		prop->child = NULL;
		prop->flags = 0;
		prop->timetoregen = 0;
		prop->rooms[0] = -1;
		prop->chr = NULL;
		prop->propstateindex = g_Vars.nextpropstateindex;
		prop->unk3e = 0;
		prop->unk3f_00 = 1;
		prop->unk3f_02 = 0;
		prop->inlist1 = false;
		prop->unk3f_01 = 0;
		prop->unk38 = 0xffff;
		prop->unk3a = 0;
		prop->unk3c = 2;
		prop->unk40 = 0;
		prop->unk44 = 0;
		g_Vars.propstates[prop->propstateindex].propcount++;

		g_Vars.nextpropstateindex++;

		if (g_Vars.nextpropstateindex >= g_Vars.numpropstateindexes) {
			g_Vars.nextpropstateindex = 0;
		}

		return prop;
	}

	return NULL;
}

void propFree(struct prop *prop)
{
	if (prop->type == PROPTYPE_CHR) {
		g_Vars.propstates[prop->propstateindex].chrpropcount--;
	} else {
		g_Vars.propstates[prop->propstateindex].propcount--;
	}

	prop->next = g_Vars.freeprops;
	prop->prev = NULL;
	prop->chr = NULL;
	prop->rooms[0] = -1;
	g_Vars.freeprops = prop;
}

void propPrependToList1(struct prop *prop)
{
	if (g_Vars.list1head && g_Vars.list1head != g_Vars.list2head) {
		if (prop != g_Vars.list1head && !prop->prev) {
			g_Vars.list1head->prev = prop;
			prop->next = g_Vars.list1head;
			prop->prev = NULL;
			g_Vars.list1head = prop;
		}
	} else {
		prop->next = g_Vars.list2head;

		if (prop->next) {
			prop->next->prev = prop;
		}

		prop->prev = NULL;
		g_Vars.list1head = prop;
		g_Vars.list1tail = g_Vars.list1head;
	}

	prop->unk3e = 0;
	prop->inlist1 = true;
}

void propAppendToList1(struct prop *prop)
{
	if (g_Vars.list1tail && g_Vars.list1tail != g_Vars.list2head) {
		if (prop != g_Vars.list1tail && !prop->next) {
			prop->prev = g_Vars.list1tail;
			prop->next = g_Vars.list1tail->next;

			if (prop->next) {
				prop->next->prev = prop;
			}

			g_Vars.list1tail->next = prop;
			g_Vars.list1tail = prop;
		}
	} else {
		prop->next = g_Vars.list2head;

		if (prop->next) {
			prop->next->prev = prop;
		}

		prop->prev = NULL;
		g_Vars.list1head = prop;
		g_Vars.list1tail = g_Vars.list1head;
	}

	prop->unk3e = 0;
	prop->inlist1 = true;
}

void propRemoveFromCurrentList(struct prop *prop)
{
	if (prop->inlist1) {
		if (prop == g_Vars.list1head) {
			g_Vars.list1head = prop->next;
		}

		if (prop == g_Vars.list1tail) {
			if (g_Vars.list1head == g_Vars.list2head) {
				g_Vars.list1tail = g_Vars.list2head;
			} else {
				g_Vars.list1tail = prop->prev;
			}
		}
	} else {
		if (prop == g_Vars.list2head) {
			if (g_Vars.list1head == g_Vars.list2head) {
				g_Vars.list1tail = prop->next;
				g_Vars.list1head = g_Vars.list1tail;
			}

			g_Vars.list2head = prop->next;
		}
	}

	if (prop->next) {
		prop->next->prev = prop->prev;
	}

	if (prop->prev) {
		prop->prev->next = prop->next;
	}

	prop->next = NULL;
	prop->prev = NULL;
	prop->inlist1 = false;
	prop->unk3e = 0;
}

void propReparent(struct prop *mover, struct prop *adopter)
{
	mover->parent = adopter;

	if (adopter->child) {
		adopter->child->prev = mover;
	}

	mover->next = adopter->child;
	mover->prev = NULL;
	adopter->child = mover;
}

void propDetach(struct prop *prop)
{
	if (prop->parent) {
		if (prop == prop->parent->child) {
			prop->parent->child = prop->next;
		}

		if (prop->next) {
			prop->next->prev = prop->prev;
		}

		if (prop->prev) {
			prop->prev->next = prop->next;
		}

		prop->parent = NULL;
		prop->next = NULL;
		prop->prev = NULL;
	}
}

Gfx *propRender(Gfx *gdl, struct prop *prop, bool withalpha)
{
	switch (prop->type) {
	case 0:
		break;
	case PROPTYPE_OBJ:
	case PROPTYPE_DOOR:
	case PROPTYPE_WEAPON:
		gdl = objRender(prop, gdl, withalpha);
		break;
	case PROPTYPE_CHR:
		gdl = chrRender(prop, gdl, withalpha);
		break;
	case PROPTYPE_PLAYER:
		gdl = playerRender(prop, gdl, withalpha);
		break;
	case PROPTYPE_EXPLOSION:
		gdl = explosionRender(prop, gdl, withalpha);
		break;
	case PROPTYPE_SMOKE:
		gdl = smokeRender(prop, gdl, withalpha);
		break;
	}

	return gdl;
}

Gfx *propsRender(Gfx *gdl, s16 arg1, s32 arg2, s16 *arg3)
{
	struct prop **ptr;
	struct prop *prop;
	s16 *tmp;

	if (arg2 == 0 || arg2 == 2) {
		// Render tangible list in reverse
		ptr = g_Vars.unk00034c - 1;

		tmp = arg3 + (g_Vars.unk00034c - g_Vars.tangibleprops);
		tmp--;

		while (ptr >= g_Vars.tangibleprops) {
			if (arg1 == *tmp) {
				prop = *ptr;

				if (prop) {
					if ((arg2 == 0 && (prop->flags & (PROPFLAG_20 | PROPFLAG_01)) == 0)
						  || (arg2 == 2 && (prop->flags & (PROPFLAG_20 | PROPFLAG_01)) == 1)) {
						gdl = propRender(gdl, prop, false);
					}
				}
			}

			ptr--;
			tmp--;
		}
	} else {
		// Render tangible list forwards
		ptr = g_Vars.tangibleprops;
		tmp = arg3;

		while (ptr < g_Vars.unk00034c) {
			if (arg1 == *tmp) {
				prop = *ptr;

				if (prop) {
					if (prop->flags & PROPFLAG_20) {
						gdl = propRender(gdl, prop, false);
					}

					gdl = propRender(gdl, prop, true);
				}
			}

			ptr++;
			tmp++;
		}
	}

	gdl = func0f15cb74(gdl);

	return gdl;
}

GLOBAL_ASM(
glabel func0f060984
.late_rodata
glabel var7f1a9e44
.word 0x4031eb85
glabel var7f1a9e48
.word 0x3e4ccccd
glabel var7f1a9e4c
.word 0x3f866666
glabel var7f1a9e50
.word 0x3e4ccccd
.text
/*  f060984:	3c013f80 */ 	lui	$at,0x3f80
/*  f060988:	44811000 */ 	mtc1	$at,$f2
/*  f06098c:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f060990:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f060994:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f060998:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f06099c:	14810005 */ 	bne	$a0,$at,.L0f0609b4
/*  f0609a0:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f0609a4:	3c017f1b */ 	lui	$at,%hi(var7f1a9e44)
/*  f0609a8:	240304fb */ 	addiu	$v1,$zero,0x4fb
/*  f0609ac:	10000036 */ 	b	.L0f060a88
/*  f0609b0:	c4229e44 */ 	lwc1	$f2,%lo(var7f1a9e44)($at)
.L0f0609b4:
/*  f0609b4:	24010014 */ 	addiu	$at,$zero,0x14
/*  f0609b8:	10810033 */ 	beq	$a0,$at,.L0f060a88
/*  f0609bc:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f0609c0:	1481001d */ 	bne	$a0,$at,.L0f060a38
/*  f0609c4:	e7a20058 */ 	swc1	$f2,0x58($sp)
/*  f0609c8:	0c004b70 */ 	jal	random
/*  f0609cc:	00000000 */ 	nop
/*  f0609d0:	304e0001 */ 	andi	$t6,$v0,0x1
/*  f0609d4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0609d8:	15c10003 */ 	bne	$t6,$at,.L0f0609e8
/*  f0609dc:	34038061 */ 	dli	$v1,0x8061
/*  f0609e0:	10000001 */ 	b	.L0f0609e8
/*  f0609e4:	34038060 */ 	dli	$v1,0x8060
.L0f0609e8:
/*  f0609e8:	0c004b70 */ 	jal	random
/*  f0609ec:	afa3005c */ 	sw	$v1,0x5c($sp)
/*  f0609f0:	44822000 */ 	mtc1	$v0,$f4
/*  f0609f4:	8fa3005c */ 	lw	$v1,0x5c($sp)
/*  f0609f8:	04410005 */ 	bgez	$v0,.L0f060a10
/*  f0609fc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f060a00:	3c014f80 */ 	lui	$at,0x4f80
/*  f060a04:	44814000 */ 	mtc1	$at,$f8
/*  f060a08:	00000000 */ 	nop
/*  f060a0c:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f060a10:
/*  f060a10:	3c012f80 */ 	lui	$at,0x2f80
/*  f060a14:	44815000 */ 	mtc1	$at,$f10
/*  f060a18:	3c017f1b */ 	lui	$at,%hi(var7f1a9e48)
/*  f060a1c:	c4329e48 */ 	lwc1	$f18,%lo(var7f1a9e48)($at)
/*  f060a20:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f060a24:	3c017f1b */ 	lui	$at,%hi(var7f1a9e4c)
/*  f060a28:	c4289e4c */ 	lwc1	$f8,%lo(var7f1a9e4c)($at)
/*  f060a2c:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f060a30:	10000015 */ 	b	.L0f060a88
/*  f060a34:	46044081 */ 	sub.s	$f2,$f8,$f4
.L0f060a38:
/*  f060a38:	24030069 */ 	addiu	$v1,$zero,0x69
/*  f060a3c:	0c004b70 */ 	jal	random
/*  f060a40:	afa3005c */ 	sw	$v1,0x5c($sp)
/*  f060a44:	44823000 */ 	mtc1	$v0,$f6
/*  f060a48:	8fa3005c */ 	lw	$v1,0x5c($sp)
/*  f060a4c:	04410005 */ 	bgez	$v0,.L0f060a64
/*  f060a50:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f060a54:	3c014f80 */ 	lui	$at,0x4f80
/*  f060a58:	44818000 */ 	mtc1	$at,$f16
/*  f060a5c:	00000000 */ 	nop
/*  f060a60:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f060a64:
/*  f060a64:	3c012f80 */ 	lui	$at,0x2f80
/*  f060a68:	44819000 */ 	mtc1	$at,$f18
/*  f060a6c:	3c017f1b */ 	lui	$at,%hi(var7f1a9e50)
/*  f060a70:	c4249e50 */ 	lwc1	$f4,%lo(var7f1a9e50)($at)
/*  f060a74:	46125202 */ 	mul.s	$f8,$f10,$f18
/*  f060a78:	3c013f80 */ 	lui	$at,0x3f80
/*  f060a7c:	44818000 */ 	mtc1	$at,$f16
/*  f060a80:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f060a84:	46068081 */ 	sub.s	$f2,$f16,$f6
.L0f060a88:
/*  f060a88:	2401ffff */ 	addiu	$at,$zero,-1
/*  f060a8c:	10610043 */ 	beq	$v1,$at,.L0f060b9c
/*  f060a90:	e7a20058 */ 	swc1	$f2,0x58($sp)
/*  f060a94:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x284)
/*  f060a98:	8f18a244 */ 	lw	$t8,%lo(g_Vars+0x284)($t8)
/*  f060a9c:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f060aa0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f060aa4:	8f1900bc */ 	lw	$t9,0xbc($t8)
/*  f060aa8:	c7a20058 */ 	lwc1	$f2,0x58($sp)
/*  f060aac:	00002025 */ 	or	$a0,$zero,$zero
/*  f060ab0:	15f90027 */ 	bne	$t7,$t9,.L0f060b50
/*  f060ab4:	8fa50064 */ 	lw	$a1,0x64($sp)
/*  f060ab8:	00002025 */ 	or	$a0,$zero,$zero
/*  f060abc:	0c012230 */ 	jal	osGetThreadPri
/*  f060ac0:	afa3005c */ 	sw	$v1,0x5c($sp)
/*  f060ac4:	3c048009 */ 	lui	$a0,%hi(g_AudioThread)
/*  f060ac8:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f060acc:	0c012230 */ 	jal	osGetThreadPri
/*  f060ad0:	248415e0 */ 	addiu	$a0,$a0,%lo(g_AudioThread)
/*  f060ad4:	00002025 */ 	or	$a0,$zero,$zero
/*  f060ad8:	0c01210c */ 	jal	osSetThreadPri
/*  f060adc:	24450001 */ 	addiu	$a1,$v0,0x1
/*  f060ae0:	8fa3005c */ 	lw	$v1,0x5c($sp)
/*  f060ae4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f060ae8:	44810000 */ 	mtc1	$at,$f0
/*  f060aec:	00032c00 */ 	sll	$a1,$v1,0x10
/*  f060af0:	00054403 */ 	sra	$t0,$a1,0x10
/*  f060af4:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f060af8:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f060afc:	240affff */ 	addiu	$t2,$zero,-1
/*  f060b00:	240bffff */ 	addiu	$t3,$zero,-1
/*  f060b04:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f060b08:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f060b0c:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f060b10:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f060b14:	01002825 */ 	or	$a1,$t0,$zero
/*  f060b18:	00003025 */ 	or	$a2,$zero,$zero
/*  f060b1c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f060b20:	0c004241 */ 	jal	audioStart
/*  f060b24:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f060b28:	10400004 */ 	beqz	$v0,.L0f060b3c
/*  f060b2c:	00402025 */ 	or	$a0,$v0,$zero
/*  f060b30:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f060b34:	0c00cf94 */ 	jal	func00033e50
/*  f060b38:	8fa60058 */ 	lw	$a2,0x58($sp)
.L0f060b3c:
/*  f060b3c:	00002025 */ 	or	$a0,$zero,$zero
/*  f060b40:	0c01210c */ 	jal	osSetThreadPri
/*  f060b44:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f060b48:	10000015 */ 	b	.L0f060ba0
/*  f060b4c:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f060b50:
/*  f060b50:	44810000 */ 	mtc1	$at,$f0
/*  f060b54:	00033400 */ 	sll	$a2,$v1,0x10
/*  f060b58:	00066403 */ 	sra	$t4,$a2,0x10
/*  f060b5c:	240dffff */ 	addiu	$t5,$zero,-1
/*  f060b60:	240effff */ 	addiu	$t6,$zero,-1
/*  f060b64:	afae002c */ 	sw	$t6,0x2c($sp)
/*  f060b68:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f060b6c:	01803025 */ 	or	$a2,$t4,$zero
/*  f060b70:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f060b74:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f060b78:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f060b7c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f060b80:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f060b84:	e7a20024 */ 	swc1	$f2,0x24($sp)
/*  f060b88:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f060b8c:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f060b90:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f060b94:	0fc24e7e */ 	jal	func0f0939f8
/*  f060b98:	e7a00038 */ 	swc1	$f0,0x38($sp)
.L0f060b9c:
/*  f060b9c:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f060ba0:
/*  f060ba0:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f060ba4:	03e00008 */ 	jr	$ra
/*  f060ba8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f060bac
.late_rodata
glabel var7f1a9e54
.word 0x3dcccccd
glabel var7f1a9e58
.word 0x4031eb85
glabel var7f1a9e5c
.word 0x3dcccccd
.text
/*  f060bac:	3c013f80 */ 	lui	$at,0x3f80
/*  f060bb0:	44811000 */ 	mtc1	$at,$f2
/*  f060bb4:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f060bb8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f060bbc:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f060bc0:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f060bc4:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f060bc8:	1481001b */ 	bne	$a0,$at,.L0f060c38
/*  f060bcc:	e7a20058 */ 	swc1	$f2,0x58($sp)
/*  f060bd0:	0c004b70 */ 	jal	random
/*  f060bd4:	3410808f */ 	dli	$s0,0x808f
/*  f060bd8:	304e0001 */ 	andi	$t6,$v0,0x1
/*  f060bdc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f060be0:	15c10002 */ 	bne	$t6,$at,.L0f060bec
/*  f060be4:	00000000 */ 	nop
/*  f060be8:	34108094 */ 	dli	$s0,0x8094
.L0f060bec:
/*  f060bec:	0c004b70 */ 	jal	random
/*  f060bf0:	00000000 */ 	nop
/*  f060bf4:	44822000 */ 	mtc1	$v0,$f4
/*  f060bf8:	3c014f80 */ 	lui	$at,0x4f80
/*  f060bfc:	04410004 */ 	bgez	$v0,.L0f060c10
/*  f060c00:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f060c04:	44814000 */ 	mtc1	$at,$f8
/*  f060c08:	00000000 */ 	nop
/*  f060c0c:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f060c10:
/*  f060c10:	3c012f80 */ 	lui	$at,0x2f80
/*  f060c14:	44815000 */ 	mtc1	$at,$f10
/*  f060c18:	3c017f1b */ 	lui	$at,%hi(var7f1a9e54)
/*  f060c1c:	c4329e54 */ 	lwc1	$f18,%lo(var7f1a9e54)($at)
/*  f060c20:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f060c24:	3c013f80 */ 	lui	$at,0x3f80
/*  f060c28:	44814000 */ 	mtc1	$at,$f8
/*  f060c2c:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f060c30:	10000019 */ 	b	.L0f060c98
/*  f060c34:	46044081 */ 	sub.s	$f2,$f8,$f4
.L0f060c38:
/*  f060c38:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f060c3c:	14810004 */ 	bne	$a0,$at,.L0f060c50
/*  f060c40:	241004fb */ 	addiu	$s0,$zero,0x4fb
/*  f060c44:	3c017f1b */ 	lui	$at,%hi(var7f1a9e58)
/*  f060c48:	10000013 */ 	b	.L0f060c98
/*  f060c4c:	c4229e58 */ 	lwc1	$f2,%lo(var7f1a9e58)($at)
.L0f060c50:
/*  f060c50:	0c004b70 */ 	jal	random
/*  f060c54:	34108079 */ 	dli	$s0,0x8079
/*  f060c58:	44823000 */ 	mtc1	$v0,$f6
/*  f060c5c:	3c014f80 */ 	lui	$at,0x4f80
/*  f060c60:	04410004 */ 	bgez	$v0,.L0f060c74
/*  f060c64:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f060c68:	44818000 */ 	mtc1	$at,$f16
/*  f060c6c:	00000000 */ 	nop
/*  f060c70:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f060c74:
/*  f060c74:	3c012f80 */ 	lui	$at,0x2f80
/*  f060c78:	44819000 */ 	mtc1	$at,$f18
/*  f060c7c:	3c017f1b */ 	lui	$at,%hi(var7f1a9e5c)
/*  f060c80:	c4249e5c */ 	lwc1	$f4,%lo(var7f1a9e5c)($at)
/*  f060c84:	46125202 */ 	mul.s	$f8,$f10,$f18
/*  f060c88:	3c013f80 */ 	lui	$at,0x3f80
/*  f060c8c:	44818000 */ 	mtc1	$at,$f16
/*  f060c90:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f060c94:	46068081 */ 	sub.s	$f2,$f16,$f6
.L0f060c98:
/*  f060c98:	2401ffff */ 	addiu	$at,$zero,-1
/*  f060c9c:	12010041 */ 	beq	$s0,$at,.L0f060da4
/*  f060ca0:	e7a20058 */ 	swc1	$f2,0x58($sp)
/*  f060ca4:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x284)
/*  f060ca8:	8f18a244 */ 	lw	$t8,%lo(g_Vars+0x284)($t8)
/*  f060cac:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f060cb0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f060cb4:	8f1900bc */ 	lw	$t9,0xbc($t8)
/*  f060cb8:	c7a20058 */ 	lwc1	$f2,0x58($sp)
/*  f060cbc:	00002025 */ 	or	$a0,$zero,$zero
/*  f060cc0:	15f90025 */ 	bne	$t7,$t9,.L0f060d58
/*  f060cc4:	8fa50064 */ 	lw	$a1,0x64($sp)
/*  f060cc8:	0c012230 */ 	jal	osGetThreadPri
/*  f060ccc:	00002025 */ 	or	$a0,$zero,$zero
/*  f060cd0:	3c048009 */ 	lui	$a0,%hi(g_AudioThread)
/*  f060cd4:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f060cd8:	0c012230 */ 	jal	osGetThreadPri
/*  f060cdc:	248415e0 */ 	addiu	$a0,$a0,%lo(g_AudioThread)
/*  f060ce0:	00002025 */ 	or	$a0,$zero,$zero
/*  f060ce4:	0c01210c */ 	jal	osSetThreadPri
/*  f060ce8:	24450001 */ 	addiu	$a1,$v0,0x1
/*  f060cec:	3c01bf80 */ 	lui	$at,0xbf80
/*  f060cf0:	44810000 */ 	mtc1	$at,$f0
/*  f060cf4:	00102c00 */ 	sll	$a1,$s0,0x10
/*  f060cf8:	00054403 */ 	sra	$t0,$a1,0x10
/*  f060cfc:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f060d00:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f060d04:	240affff */ 	addiu	$t2,$zero,-1
/*  f060d08:	240bffff */ 	addiu	$t3,$zero,-1
/*  f060d0c:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f060d10:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f060d14:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f060d18:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f060d1c:	01002825 */ 	or	$a1,$t0,$zero
/*  f060d20:	00003025 */ 	or	$a2,$zero,$zero
/*  f060d24:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f060d28:	0c004241 */ 	jal	audioStart
/*  f060d2c:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f060d30:	10400004 */ 	beqz	$v0,.L0f060d44
/*  f060d34:	00402025 */ 	or	$a0,$v0,$zero
/*  f060d38:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f060d3c:	0c00cf94 */ 	jal	func00033e50
/*  f060d40:	8fa60058 */ 	lw	$a2,0x58($sp)
.L0f060d44:
/*  f060d44:	00002025 */ 	or	$a0,$zero,$zero
/*  f060d48:	0c01210c */ 	jal	osSetThreadPri
/*  f060d4c:	8fa50050 */ 	lw	$a1,0x50($sp)
/*  f060d50:	10000015 */ 	b	.L0f060da8
/*  f060d54:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f060d58:
/*  f060d58:	44810000 */ 	mtc1	$at,$f0
/*  f060d5c:	00103400 */ 	sll	$a2,$s0,0x10
/*  f060d60:	00066403 */ 	sra	$t4,$a2,0x10
/*  f060d64:	240dffff */ 	addiu	$t5,$zero,-1
/*  f060d68:	240effff */ 	addiu	$t6,$zero,-1
/*  f060d6c:	afae002c */ 	sw	$t6,0x2c($sp)
/*  f060d70:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f060d74:	01803025 */ 	or	$a2,$t4,$zero
/*  f060d78:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f060d7c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f060d80:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f060d84:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f060d88:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f060d8c:	e7a20024 */ 	swc1	$f2,0x24($sp)
/*  f060d90:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f060d94:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f060d98:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f060d9c:	0fc24e7e */ 	jal	func0f0939f8
/*  f060da0:	e7a00038 */ 	swc1	$f0,0x38($sp)
.L0f060da4:
/*  f060da4:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f060da8:
/*  f060da8:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f060dac:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f060db0:	03e00008 */ 	jr	$ra
/*  f060db4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f060db8
.late_rodata
glabel var7f1a9e60
.word func0f060db8+0xd2c # f061ae4
glabel var7f1a9e64
.word func0f060db8+0xd2c # f061ae4
glabel var7f1a9e68
.word func0f060db8+0xd38 # f061af0
glabel var7f1a9e6c
.word func0f060db8+0xd38 # f061af0
glabel var7f1a9e70
.word func0f060db8+0xd38 # f061af0
glabel var7f1a9e74
.word func0f060db8+0xd24 # f061adc
glabel var7f1a9e78
.word func0f060db8+0xd2c # f061ae4
glabel var7f1a9e7c
.word func0f060db8+0xd38 # f061af0
glabel var7f1a9e80
.word func0f060db8+0xd38 # f061af0
glabel var7f1a9e84
.word func0f060db8+0xd38 # f061af0
glabel var7f1a9e88
.word func0f060db8+0xd38 # f061af0
glabel var7f1a9e8c
.word func0f060db8+0xd38 # f061af0
glabel var7f1a9e90
.word func0f060db8+0xd38 # f061af0
glabel var7f1a9e94
.word func0f060db8+0xd38 # f061af0
glabel var7f1a9e98
.word func0f060db8+0xd2c # f061ae4
glabel var7f1a9e9c
.word func0f060db8+0xd38 # f061af0
glabel var7f1a9ea0
.word func0f060db8+0xd1c # f061ad4
glabel var7f1a9ea4
.word func0f060db8+0xd38 # f061af0
glabel var7f1a9ea8
.word func0f060db8+0xd38 # f061af0
glabel var7f1a9eac
.word func0f060db8+0xd38 # f061af0
glabel var7f1a9eb0
.word func0f060db8+0xd38 # f061af0
glabel var7f1a9eb4
.word func0f060db8+0xd38 # f061af0
glabel var7f1a9eb8
.word func0f060db8+0xd34 # f061aec
.text
/*  f060db8:	27bdf920 */ 	addiu	$sp,$sp,-1760
/*  f060dbc:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f060dc0:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f060dc4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f060dc8:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f060dcc:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f060dd0:	afa406e0 */ 	sw	$a0,0x6e0($sp)
/*  f060dd4:	afa506e4 */ 	sw	$a1,0x6e4($sp)
/*  f060dd8:	afa006d0 */ 	sw	$zero,0x6d0($sp)
/*  f060ddc:	afa006cc */ 	sw	$zero,0x6cc($sp)
/*  f060de0:	afa006c8 */ 	sw	$zero,0x6c8($sp)
/*  f060de4:	afa006c4 */ 	sw	$zero,0x6c4($sp)
/*  f060de8:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f060dec:	3c014348 */ 	lui	$at,0x4348
/*  f060df0:	44812000 */ 	mtc1	$at,$f4
/*  f060df4:	00c08025 */ 	or	$s0,$a2,$zero
/*  f060df8:	00008825 */ 	or	$s1,$zero,$zero
/*  f060dfc:	afa001ec */ 	sw	$zero,0x1ec($sp)
/*  f060e00:	afa001e8 */ 	sw	$zero,0x1e8($sp)
/*  f060e04:	afa001e0 */ 	sw	$zero,0x1e0($sp)
/*  f060e08:	afa706ec */ 	sw	$a3,0x6ec($sp)
/*  f060e0c:	8fa406f8 */ 	lw	$a0,0x6f8($sp)
/*  f060e10:	afaf0654 */ 	sw	$t7,0x654($sp)
/*  f060e14:	0fc2a525 */ 	jal	func0f0a9494
/*  f060e18:	e7a401e4 */ 	swc1	$f4,0x1e4($sp)
/*  f060e1c:	8fa206f0 */ 	lw	$v0,0x6f0($sp)
/*  f060e20:	8fa306f4 */ 	lw	$v1,0x6f4($sp)
/*  f060e24:	8fa706ec */ 	lw	$a3,0x6ec($sp)
/*  f060e28:	c4460000 */ 	lwc1	$f6,0x0($v0)
/*  f060e2c:	8fa406e0 */ 	lw	$a0,0x6e0($sp)
/*  f060e30:	27a50214 */ 	addiu	$a1,$sp,0x214
/*  f060e34:	e7a60218 */ 	swc1	$f6,0x218($sp)
/*  f060e38:	c4480004 */ 	lwc1	$f8,0x4($v0)
/*  f060e3c:	e7a8021c */ 	swc1	$f8,0x21c($sp)
/*  f060e40:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f060e44:	e7aa0220 */ 	swc1	$f10,0x220($sp)
/*  f060e48:	c6120000 */ 	lwc1	$f18,0x0($s0)
/*  f060e4c:	e7b201fc */ 	swc1	$f18,0x1fc($sp)
/*  f060e50:	c6040004 */ 	lwc1	$f4,0x4($s0)
/*  f060e54:	e7a40200 */ 	swc1	$f4,0x200($sp)
/*  f060e58:	c6060008 */ 	lwc1	$f6,0x8($s0)
/*  f060e5c:	e7a60204 */ 	swc1	$f6,0x204($sp)
/*  f060e60:	c4680000 */ 	lwc1	$f8,0x0($v1)
/*  f060e64:	e7a80224 */ 	swc1	$f8,0x224($sp)
/*  f060e68:	c46a0004 */ 	lwc1	$f10,0x4($v1)
/*  f060e6c:	e7aa0228 */ 	swc1	$f10,0x228($sp)
/*  f060e70:	c4720008 */ 	lwc1	$f18,0x8($v1)
/*  f060e74:	e7b2022c */ 	swc1	$f18,0x22c($sp)
/*  f060e78:	c4e40000 */ 	lwc1	$f4,0x0($a3)
/*  f060e7c:	e7a40208 */ 	swc1	$f4,0x208($sp)
/*  f060e80:	c4e60004 */ 	lwc1	$f6,0x4($a3)
/*  f060e84:	e7a6020c */ 	swc1	$f6,0x20c($sp)
/*  f060e88:	c4e80008 */ 	lwc1	$f8,0x8($a3)
/*  f060e8c:	0fc2c6bc */ 	jal	func0f0b1af0
/*  f060e90:	e7a80210 */ 	swc1	$f8,0x210($sp)
/*  f060e94:	0fc2c41f */ 	jal	handGetWeaponFunction
/*  f060e98:	27a40214 */ 	addiu	$a0,$sp,0x214
/*  f060e9c:	10400013 */ 	beqz	$v0,.L0f060eec
/*  f060ea0:	afa201f0 */ 	sw	$v0,0x1f0($sp)
/*  f060ea4:	8fa306e4 */ 	lw	$v1,0x6e4($sp)
/*  f060ea8:	50600008 */ 	beqzl	$v1,.L0f060ecc
/*  f060eac:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*  f060eb0:	8c580010 */ 	lw	$t8,0x10($v0)
/*  f060eb4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f060eb8:	33194000 */ 	andi	$t9,$t8,0x4000
/*  f060ebc:	53200003 */ 	beqzl	$t9,.L0f060ecc
/*  f060ec0:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*  f060ec4:	afa906d0 */ 	sw	$t1,0x6d0($sp)
/*  f060ec8:	8c4a0000 */ 	lw	$t2,0x0($v0)
.L0f060ecc:
/*  f060ecc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f060ed0:	314b00ff */ 	andi	$t3,$t2,0xff
/*  f060ed4:	55610006 */ 	bnel	$t3,$at,.L0f060ef0
/*  f060ed8:	93ad0214 */ 	lbu	$t5,0x214($sp)
/*  f060edc:	10600003 */ 	beqz	$v1,.L0f060eec
/*  f060ee0:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f060ee4:	afac01e8 */ 	sw	$t4,0x1e8($sp)
/*  f060ee8:	afa006e4 */ 	sw	$zero,0x6e4($sp)
.L0f060eec:
/*  f060eec:	93ad0214 */ 	lbu	$t5,0x214($sp)
.L0f060ef0:
/*  f060ef0:	2401001d */ 	addiu	$at,$zero,0x1d
/*  f060ef4:	55a10008 */ 	bnel	$t5,$at,.L0f060f18
/*  f060ef8:	8fb806e4 */ 	lw	$t8,0x6e4($sp)
/*  f060efc:	93ae0217 */ 	lbu	$t6,0x217($sp)
/*  f060f00:	24010001 */ 	addiu	$at,$zero,0x1
/*  f060f04:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f060f08:	55c10003 */ 	bnel	$t6,$at,.L0f060f18
/*  f060f0c:	8fb806e4 */ 	lw	$t8,0x6e4($sp)
/*  f060f10:	afaf01ec */ 	sw	$t7,0x1ec($sp)
/*  f060f14:	8fb806e4 */ 	lw	$t8,0x6e4($sp)
.L0f060f18:
/*  f060f18:	53000006 */ 	beqzl	$t8,.L0f060f34
/*  f060f1c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f060f20:	0fc2c71e */ 	jal	handGetSingleUnk3c
/*  f060f24:	27a40214 */ 	addiu	$a0,$sp,0x214
/*  f060f28:	10000003 */ 	b	.L0f060f38
/*  f060f2c:	afa20234 */ 	sw	$v0,0x234($sp)
/*  f060f30:	24190001 */ 	addiu	$t9,$zero,0x1
.L0f060f34:
/*  f060f34:	afb90234 */ 	sw	$t9,0x234($sp)
.L0f060f38:
/*  f060f38:	c7aa06fc */ 	lwc1	$f10,0x6fc($sp)
/*  f060f3c:	27b001fc */ 	addiu	$s0,$sp,0x1fc
/*  f060f40:	27a2060c */ 	addiu	$v0,$sp,0x60c
/*  f060f44:	e7aa0230 */ 	swc1	$f10,0x230($sp)
.L0f060f48:
/*  f060f48:	26100068 */ 	addiu	$s0,$s0,0x68
/*  f060f4c:	ae00ffd8 */ 	sw	$zero,-0x28($s0)
/*  f060f50:	ae00ffdc */ 	sw	$zero,-0x24($s0)
/*  f060f54:	1602fffc */ 	bne	$s0,$v0,.L0f060f48
/*  f060f58:	ae00ffe0 */ 	sw	$zero,-0x20($s0)
/*  f060f5c:	8fa901ec */ 	lw	$t1,0x1ec($sp)
/*  f060f60:	27b000c8 */ 	addiu	$s0,$sp,0xc8
/*  f060f64:	02003825 */ 	or	$a3,$s0,$zero
/*  f060f68:	11200013 */ 	beqz	$t1,.L0f060fb8
/*  f060f6c:	27a50218 */ 	addiu	$a1,$sp,0x218
/*  f060f70:	3c014396 */ 	lui	$at,0x4396
/*  f060f74:	44817000 */ 	mtc1	$at,$f14
/*  f060f78:	c7b20224 */ 	lwc1	$f18,0x224($sp)
/*  f060f7c:	c7ac0218 */ 	lwc1	$f12,0x218($sp)
/*  f060f80:	c7a80228 */ 	lwc1	$f8,0x228($sp)
/*  f060f84:	460e9102 */ 	mul.s	$f4,$f18,$f14
/*  f060f88:	c7a00220 */ 	lwc1	$f0,0x220($sp)
/*  f060f8c:	c7a2021c */ 	lwc1	$f2,0x21c($sp)
/*  f060f90:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*  f060f94:	460c2180 */ 	add.s	$f6,$f4,$f12
/*  f060f98:	c7a4022c */ 	lwc1	$f4,0x22c($sp)
/*  f060f9c:	46025480 */ 	add.s	$f18,$f10,$f2
/*  f060fa0:	e7a60648 */ 	swc1	$f6,0x648($sp)
/*  f060fa4:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f060fa8:	e7b2064c */ 	swc1	$f18,0x64c($sp)
/*  f060fac:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f060fb0:	1000002d */ 	b	.L0f061068
/*  f060fb4:	e7a80650 */ 	swc1	$f8,0x650($sp)
.L0f060fb8:
/*  f060fb8:	8faa01e8 */ 	lw	$t2,0x1e8($sp)
/*  f060fbc:	8fab01f0 */ 	lw	$t3,0x1f0($sp)
/*  f060fc0:	3c014780 */ 	lui	$at,0x4780
/*  f060fc4:	11400019 */ 	beqz	$t2,.L0f06102c
/*  f060fc8:	c7a80224 */ 	lwc1	$f8,0x224($sp)
/*  f060fcc:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*  f060fd0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f060fd4:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f060fd8:	55a10004 */ 	bnel	$t5,$at,.L0f060fec
/*  f060fdc:	c7b001e4 */ 	lwc1	$f16,0x1e4($sp)
/*  f060fe0:	c5700018 */ 	lwc1	$f16,0x18($t3)
/*  f060fe4:	e7b001e4 */ 	swc1	$f16,0x1e4($sp)
/*  f060fe8:	c7b001e4 */ 	lwc1	$f16,0x1e4($sp)
.L0f060fec:
/*  f060fec:	c7aa0224 */ 	lwc1	$f10,0x224($sp)
/*  f060ff0:	c7ac0218 */ 	lwc1	$f12,0x218($sp)
/*  f060ff4:	c7a60228 */ 	lwc1	$f6,0x228($sp)
/*  f060ff8:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f060ffc:	c7a00220 */ 	lwc1	$f0,0x220($sp)
/*  f061000:	c7a2021c */ 	lwc1	$f2,0x21c($sp)
/*  f061004:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f061008:	460c9100 */ 	add.s	$f4,$f18,$f12
/*  f06100c:	c7b2022c */ 	lwc1	$f18,0x22c($sp)
/*  f061010:	46024280 */ 	add.s	$f10,$f8,$f2
/*  f061014:	e7a40648 */ 	swc1	$f4,0x648($sp)
/*  f061018:	46109102 */ 	mul.s	$f4,$f18,$f16
/*  f06101c:	e7aa064c */ 	swc1	$f10,0x64c($sp)
/*  f061020:	46002180 */ 	add.s	$f6,$f4,$f0
/*  f061024:	10000010 */ 	b	.L0f061068
/*  f061028:	e7a60650 */ 	swc1	$f6,0x650($sp)
.L0f06102c:
/*  f06102c:	44817000 */ 	mtc1	$at,$f14
/*  f061030:	c7ac0218 */ 	lwc1	$f12,0x218($sp)
/*  f061034:	c7a40228 */ 	lwc1	$f4,0x228($sp)
/*  f061038:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*  f06103c:	c7a00220 */ 	lwc1	$f0,0x220($sp)
/*  f061040:	c7a2021c */ 	lwc1	$f2,0x21c($sp)
/*  f061044:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f061048:	460c5480 */ 	add.s	$f18,$f10,$f12
/*  f06104c:	c7aa022c */ 	lwc1	$f10,0x22c($sp)
/*  f061050:	46023200 */ 	add.s	$f8,$f6,$f2
/*  f061054:	e7b20648 */ 	swc1	$f18,0x648($sp)
/*  f061058:	460e5482 */ 	mul.s	$f18,$f10,$f14
/*  f06105c:	e7a8064c */ 	swc1	$f8,0x64c($sp)
/*  f061060:	46009100 */ 	add.s	$f4,$f18,$f0
/*  f061064:	e7a40650 */ 	swc1	$f4,0x650($sp)
.L0f061068:
/*  f061068:	8fa20654 */ 	lw	$v0,0x654($sp)
/*  f06106c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f061070:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f061074:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f061078:	0c006052 */ 	jal	func00018148
/*  f06107c:	24460028 */ 	addiu	$a2,$v0,0x28
/*  f061080:	27ae00d8 */ 	addiu	$t6,$sp,0xd8
/*  f061084:	240f001e */ 	addiu	$t7,$zero,0x1e
/*  f061088:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f06108c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f061090:	27a40218 */ 	addiu	$a0,$sp,0x218
/*  f061094:	27a50648 */ 	addiu	$a1,$sp,0x648
/*  f061098:	02003025 */ 	or	$a2,$s0,$zero
/*  f06109c:	0c006052 */ 	jal	func00018148
/*  f0610a0:	27a700b8 */ 	addiu	$a3,$sp,0xb8
/*  f0610a4:	93b80214 */ 	lbu	$t8,0x214($sp)
/*  f0610a8:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0610ac:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x284)
/*  f0610b0:	17010005 */ 	bne	$t8,$at,.L0f0610c8
/*  f0610b4:	87aa00d8 */ 	lh	$t2,0xd8($sp)
/*  f0610b8:	8f39a244 */ 	lw	$t9,%lo(g_Vars+0x284)($t9)
/*  f0610bc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0610c0:	97290010 */ 	lhu	$t1,0x10($t9)
/*  f0610c4:	11210098 */ 	beq	$t1,$at,.L0f061328
.L0f0610c8:
/*  f0610c8:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0610cc:	104a0005 */ 	beq	$v0,$t2,.L0f0610e4
/*  f0610d0:	27a400d8 */ 	addiu	$a0,$sp,0xd8
/*  f0610d4:	848c0002 */ 	lh	$t4,0x2($a0)
.L0f0610d8:
/*  f0610d8:	24840002 */ 	addiu	$a0,$a0,0x2
/*  f0610dc:	544cfffe */ 	bnel	$v0,$t4,.L0f0610d8
/*  f0610e0:	848c0002 */ 	lh	$t4,0x2($a0)
.L0f0610e4:
/*  f0610e4:	0fc5914d */ 	jal	func0f164534
/*  f0610e8:	24050064 */ 	addiu	$a1,$zero,0x64
/*  f0610ec:	87ad00d8 */ 	lh	$t5,0xd8($sp)
/*  f0610f0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0610f4:	27b000d8 */ 	addiu	$s0,$sp,0xd8
/*  f0610f8:	51a1008c */ 	beql	$t5,$at,.L0f06132c
/*  f0610fc:	8fad06c8 */ 	lw	$t5,0x6c8($sp)
/*  f061100:	86060000 */ 	lh	$a2,0x0($s0)
/*  f061104:	27a40218 */ 	addiu	$a0,$sp,0x218
.L0f061108:
/*  f061108:	27a50648 */ 	addiu	$a1,$sp,0x648
/*  f06110c:	0fc58548 */ 	jal	func0f161520
/*  f061110:	27a70664 */ 	addiu	$a3,$sp,0x664
/*  f061114:	3c013f80 */ 	lui	$at,0x3f80
/*  f061118:	44817000 */ 	mtc1	$at,$f14
/*  f06111c:	1040007d */ 	beqz	$v0,.L0f061314
/*  f061120:	c7a60664 */ 	lwc1	$f6,0x664($sp)
/*  f061124:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*  f061128:	c7aa0668 */ 	lwc1	$f10,0x668($sp)
/*  f06112c:	c7a4066c */ 	lwc1	$f4,0x66c($sp)
/*  f061130:	c7ac0218 */ 	lwc1	$f12,0x218($sp)
/*  f061134:	460e5482 */ 	mul.s	$f18,$f10,$f14
/*  f061138:	c7aa0648 */ 	lwc1	$f10,0x648($sp)
/*  f06113c:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f061140:	e7a80664 */ 	swc1	$f8,0x664($sp)
/*  f061144:	460a603e */ 	c.le.s	$f12,$f10
/*  f061148:	e7b20668 */ 	swc1	$f18,0x668($sp)
/*  f06114c:	c7b20648 */ 	lwc1	$f18,0x648($sp)
/*  f061150:	45000009 */ 	bc1f	.L0f061178
/*  f061154:	e7a6066c */ 	swc1	$f6,0x66c($sp)
/*  f061158:	460a403e */ 	c.le.s	$f8,$f10
/*  f06115c:	00000000 */ 	nop
/*  f061160:	45020006 */ 	bc1fl	.L0f06117c
/*  f061164:	460c903e */ 	c.le.s	$f18,$f12
/*  f061168:	4608603e */ 	c.le.s	$f12,$f8
/*  f06116c:	00000000 */ 	nop
/*  f061170:	4503000e */ 	bc1tl	.L0f0611ac
/*  f061174:	c7a2021c */ 	lwc1	$f2,0x21c($sp)
.L0f061178:
/*  f061178:	460c903e */ 	c.le.s	$f18,$f12
.L0f06117c:
/*  f06117c:	c7a40664 */ 	lwc1	$f4,0x664($sp)
/*  f061180:	45020065 */ 	bc1fl	.L0f061318
/*  f061184:	86060002 */ 	lh	$a2,0x2($s0)
/*  f061188:	4604903e */ 	c.le.s	$f18,$f4
/*  f06118c:	00000000 */ 	nop
/*  f061190:	45020061 */ 	bc1fl	.L0f061318
/*  f061194:	86060002 */ 	lh	$a2,0x2($s0)
/*  f061198:	460c203e */ 	c.le.s	$f4,$f12
/*  f06119c:	00000000 */ 	nop
/*  f0611a0:	4502005d */ 	bc1fl	.L0f061318
/*  f0611a4:	86060002 */ 	lh	$a2,0x2($s0)
/*  f0611a8:	c7a2021c */ 	lwc1	$f2,0x21c($sp)
.L0f0611ac:
/*  f0611ac:	c7a6064c */ 	lwc1	$f6,0x64c($sp)
/*  f0611b0:	c7aa0668 */ 	lwc1	$f10,0x668($sp)
/*  f0611b4:	c7a8064c */ 	lwc1	$f8,0x64c($sp)
/*  f0611b8:	4606103e */ 	c.le.s	$f2,$f6
/*  f0611bc:	00000000 */ 	nop
/*  f0611c0:	4502000a */ 	bc1fl	.L0f0611ec
/*  f0611c4:	4602403e */ 	c.le.s	$f8,$f2
/*  f0611c8:	4606503e */ 	c.le.s	$f10,$f6
/*  f0611cc:	00000000 */ 	nop
/*  f0611d0:	45020006 */ 	bc1fl	.L0f0611ec
/*  f0611d4:	4602403e */ 	c.le.s	$f8,$f2
/*  f0611d8:	460a103e */ 	c.le.s	$f2,$f10
/*  f0611dc:	00000000 */ 	nop
/*  f0611e0:	4503000e */ 	bc1tl	.L0f06121c
/*  f0611e4:	c7a00220 */ 	lwc1	$f0,0x220($sp)
/*  f0611e8:	4602403e */ 	c.le.s	$f8,$f2
.L0f0611ec:
/*  f0611ec:	c7b20668 */ 	lwc1	$f18,0x668($sp)
/*  f0611f0:	45020049 */ 	bc1fl	.L0f061318
/*  f0611f4:	86060002 */ 	lh	$a2,0x2($s0)
/*  f0611f8:	4612403e */ 	c.le.s	$f8,$f18
/*  f0611fc:	00000000 */ 	nop
/*  f061200:	45020045 */ 	bc1fl	.L0f061318
/*  f061204:	86060002 */ 	lh	$a2,0x2($s0)
/*  f061208:	4602903e */ 	c.le.s	$f18,$f2
/*  f06120c:	00000000 */ 	nop
/*  f061210:	45020041 */ 	bc1fl	.L0f061318
/*  f061214:	86060002 */ 	lh	$a2,0x2($s0)
/*  f061218:	c7a00220 */ 	lwc1	$f0,0x220($sp)
.L0f06121c:
/*  f06121c:	c7a40650 */ 	lwc1	$f4,0x650($sp)
/*  f061220:	c7a6066c */ 	lwc1	$f6,0x66c($sp)
/*  f061224:	c7aa0650 */ 	lwc1	$f10,0x650($sp)
/*  f061228:	4604003e */ 	c.le.s	$f0,$f4
/*  f06122c:	00000000 */ 	nop
/*  f061230:	4502000a */ 	bc1fl	.L0f06125c
/*  f061234:	4600503e */ 	c.le.s	$f10,$f0
/*  f061238:	4604303e */ 	c.le.s	$f6,$f4
/*  f06123c:	00000000 */ 	nop
/*  f061240:	45020006 */ 	bc1fl	.L0f06125c
/*  f061244:	4600503e */ 	c.le.s	$f10,$f0
/*  f061248:	4606003e */ 	c.le.s	$f0,$f6
/*  f06124c:	00000000 */ 	nop
/*  f061250:	4503000e */ 	bc1tl	.L0f06128c
/*  f061254:	c7b20664 */ 	lwc1	$f18,0x664($sp)
/*  f061258:	4600503e */ 	c.le.s	$f10,$f0
.L0f06125c:
/*  f06125c:	c7a8066c */ 	lwc1	$f8,0x66c($sp)
/*  f061260:	4502002d */ 	bc1fl	.L0f061318
/*  f061264:	86060002 */ 	lh	$a2,0x2($s0)
/*  f061268:	4608503e */ 	c.le.s	$f10,$f8
/*  f06126c:	00000000 */ 	nop
/*  f061270:	45020029 */ 	bc1fl	.L0f061318
/*  f061274:	86060002 */ 	lh	$a2,0x2($s0)
/*  f061278:	4600403e */ 	c.le.s	$f8,$f0
/*  f06127c:	00000000 */ 	nop
/*  f061280:	45020025 */ 	bc1fl	.L0f061318
/*  f061284:	86060002 */ 	lh	$a2,0x2($s0)
/*  f061288:	c7b20664 */ 	lwc1	$f18,0x664($sp)
.L0f06128c:
/*  f06128c:	c7a40668 */ 	lwc1	$f4,0x668($sp)
/*  f061290:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f061294:	46126032 */ 	c.eq.s	$f12,$f18
/*  f061298:	27b80694 */ 	addiu	$t8,$sp,0x694
/*  f06129c:	4502000a */ 	bc1fl	.L0f0612c8
/*  f0612a0:	afae06c8 */ 	sw	$t6,0x6c8($sp)
/*  f0612a4:	46041032 */ 	c.eq.s	$f2,$f4
/*  f0612a8:	c7a6066c */ 	lwc1	$f6,0x66c($sp)
/*  f0612ac:	45020006 */ 	bc1fl	.L0f0612c8
/*  f0612b0:	afae06c8 */ 	sw	$t6,0x6c8($sp)
/*  f0612b4:	46060032 */ 	c.eq.s	$f0,$f6
/*  f0612b8:	00000000 */ 	nop
/*  f0612bc:	45030016 */ 	bc1tl	.L0f061318
/*  f0612c0:	86060002 */ 	lh	$a2,0x2($s0)
/*  f0612c4:	afae06c8 */ 	sw	$t6,0x6c8($sp)
.L0f0612c8:
/*  f0612c8:	860f0000 */ 	lh	$t7,0x0($s0)
/*  f0612cc:	27b90664 */ 	addiu	$t9,$sp,0x664
/*  f0612d0:	272c0030 */ 	addiu	$t4,$t9,0x30
/*  f0612d4:	afaf06c4 */ 	sw	$t7,0x6c4($sp)
.L0f0612d8:
/*  f0612d8:	8f210000 */ 	lw	$at,0x0($t9)
/*  f0612dc:	2739000c */ 	addiu	$t9,$t9,12
/*  f0612e0:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f0612e4:	af01fff4 */ 	sw	$at,-0xc($t8)
/*  f0612e8:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*  f0612ec:	af01fff8 */ 	sw	$at,-0x8($t8)
/*  f0612f0:	8f21fffc */ 	lw	$at,-0x4($t9)
/*  f0612f4:	172cfff8 */ 	bne	$t9,$t4,.L0f0612d8
/*  f0612f8:	af01fffc */ 	sw	$at,-0x4($t8)
/*  f0612fc:	c7aa0664 */ 	lwc1	$f10,0x664($sp)
/*  f061300:	c7a80668 */ 	lwc1	$f8,0x668($sp)
/*  f061304:	c7b2066c */ 	lwc1	$f18,0x66c($sp)
/*  f061308:	e7aa0648 */ 	swc1	$f10,0x648($sp)
/*  f06130c:	e7a8064c */ 	swc1	$f8,0x64c($sp)
/*  f061310:	e7b20650 */ 	swc1	$f18,0x650($sp)
.L0f061314:
/*  f061314:	86060002 */ 	lh	$a2,0x2($s0)
.L0f061318:
/*  f061318:	2401ffff */ 	addiu	$at,$zero,-1
/*  f06131c:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f061320:	54c1ff79 */ 	bnel	$a2,$at,.L0f061108
/*  f061324:	27a40218 */ 	addiu	$a0,$sp,0x218
.L0f061328:
/*  f061328:	8fad06c8 */ 	lw	$t5,0x6c8($sp)
.L0f06132c:
/*  f06132c:	afa001f8 */ 	sw	$zero,0x1f8($sp)
/*  f061330:	93ab0214 */ 	lbu	$t3,0x214($sp)
/*  f061334:	11a00011 */ 	beqz	$t5,.L0f06137c
/*  f061338:	24010016 */ 	addiu	$at,$zero,0x16
/*  f06133c:	1161000f */ 	beq	$t3,$at,.L0f06137c
/*  f061340:	00000000 */ 	nop
/*  f061344:	0fc2d5be */ 	jal	currentPlayerGetMatrix1740
/*  f061348:	00000000 */ 	nop
/*  f06134c:	00402025 */ 	or	$a0,$v0,$zero
/*  f061350:	27a50694 */ 	addiu	$a1,$sp,0x694
/*  f061354:	0c0056da */ 	jal	func00015b68
/*  f061358:	27a60658 */ 	addiu	$a2,$sp,0x658
/*  f06135c:	c7a00660 */ 	lwc1	$f0,0x660($sp)
/*  f061360:	c7a40230 */ 	lwc1	$f4,0x230($sp)
/*  f061364:	46000007 */ 	neg.s	$f0,$f0
/*  f061368:	4604003c */ 	c.lt.s	$f0,$f4
/*  f06136c:	00000000 */ 	nop
/*  f061370:	45000002 */ 	bc1f	.L0f06137c
/*  f061374:	00000000 */ 	nop
/*  f061378:	e7a00230 */ 	swc1	$f0,0x230($sp)
.L0f06137c:
/*  f06137c:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x34c)
/*  f061380:	8c63a30c */ 	lw	$v1,%lo(g_Vars+0x34c)($v1)
/*  f061384:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x348)
/*  f061388:	8dcea308 */ 	lw	$t6,%lo(g_Vars+0x348)($t6)
/*  f06138c:	2463fffc */ 	addiu	$v1,$v1,-4
/*  f061390:	006e082b */ 	sltu	$at,$v1,$t6
/*  f061394:	54200033 */ 	bnezl	$at,.L0f061464
/*  f061398:	8fb9023c */ 	lw	$t9,0x23c($sp)
/*  f06139c:	8c700000 */ 	lw	$s0,0x0($v1)
.L0f0613a0:
/*  f0613a0:	12000029 */ 	beqz	$s0,.L0f061448
/*  f0613a4:	00000000 */ 	nop
/*  f0613a8:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f0613ac:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0613b0:	1041000e */ 	beq	$v0,$at,.L0f0613ec
/*  f0613b4:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0613b8:	54410017 */ 	bnel	$v0,$at,.L0f061418
/*  f0613bc:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f0613c0:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f0613c4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0613c8:	51e00013 */ 	beqzl	$t7,.L0f061418
/*  f0613cc:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f0613d0:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f0613d4:	afa306d8 */ 	sw	$v1,0x6d8($sp)
/*  f0613d8:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x28c)
/*  f0613dc:	8d4aa24c */ 	lw	$t2,%lo(g_Vars+0x28c)($t2)
/*  f0613e0:	8fa306d8 */ 	lw	$v1,0x6d8($sp)
/*  f0613e4:	504a000c */ 	beql	$v0,$t2,.L0f061418
/*  f0613e8:	92020000 */ 	lbu	$v0,0x0($s0)
.L0f0613ec:
/*  f0613ec:	8fa901e8 */ 	lw	$t1,0x1e8($sp)
/*  f0613f0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0613f4:	27a501fc */ 	addiu	$a1,$sp,0x1fc
/*  f0613f8:	15200013 */ 	bnez	$t1,.L0f061448
/*  f0613fc:	8fa606e4 */ 	lw	$a2,0x6e4($sp)
/*  f061400:	8fa70700 */ 	lw	$a3,0x700($sp)
/*  f061404:	0fc09e65 */ 	jal	func0f027994
/*  f061408:	afa306d8 */ 	sw	$v1,0x6d8($sp)
/*  f06140c:	1000000e */ 	b	.L0f061448
/*  f061410:	8fa306d8 */ 	lw	$v1,0x6d8($sp)
/*  f061414:	92020000 */ 	lbu	$v0,0x0($s0)
.L0f061418:
/*  f061418:	24010001 */ 	addiu	$at,$zero,0x1
/*  f06141c:	02002025 */ 	or	$a0,$s0,$zero
/*  f061420:	10410006 */ 	beq	$v0,$at,.L0f06143c
/*  f061424:	27a501fc */ 	addiu	$a1,$sp,0x1fc
/*  f061428:	24010004 */ 	addiu	$at,$zero,0x4
/*  f06142c:	10410003 */ 	beq	$v0,$at,.L0f06143c
/*  f061430:	24010002 */ 	addiu	$at,$zero,0x2
/*  f061434:	14410004 */ 	bne	$v0,$at,.L0f061448
/*  f061438:	00000000 */ 	nop
.L0f06143c:
/*  f06143c:	0fc21780 */ 	jal	func0f085e00
/*  f061440:	afa306d8 */ 	sw	$v1,0x6d8($sp)
/*  f061444:	8fa306d8 */ 	lw	$v1,0x6d8($sp)
.L0f061448:
/*  f061448:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x348)
/*  f06144c:	8d8ca308 */ 	lw	$t4,%lo(g_Vars+0x348)($t4)
/*  f061450:	2463fffc */ 	addiu	$v1,$v1,-4
/*  f061454:	006c082b */ 	sltu	$at,$v1,$t4
/*  f061458:	5020ffd1 */ 	beqzl	$at,.L0f0613a0
/*  f06145c:	8c700000 */ 	lw	$s0,0x0($v1)
/*  f061460:	8fb9023c */ 	lw	$t9,0x23c($sp)
.L0f061464:
/*  f061464:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f061468:	c7a60288 */ 	lwc1	$f6,0x288($sp)
/*  f06146c:	13200007 */ 	beqz	$t9,.L0f06148c
/*  f061470:	2401ffff */ 	addiu	$at,$zero,-1
/*  f061474:	c7aa028c */ 	lwc1	$f10,0x28c($sp)
/*  f061478:	c7a80290 */ 	lwc1	$f8,0x290($sp)
/*  f06147c:	e7a600a0 */ 	swc1	$f6,0xa0($sp)
/*  f061480:	00001825 */ 	or	$v1,$zero,$zero
/*  f061484:	e7aa00a4 */ 	swc1	$f10,0xa4($sp)
/*  f061488:	e7a800a8 */ 	swc1	$f8,0xa8($sp)
.L0f06148c:
/*  f06148c:	1061000e */ 	beq	$v1,$at,.L0f0614c8
/*  f061490:	8fab06c8 */ 	lw	$t3,0x6c8($sp)
/*  f061494:	0003c080 */ 	sll	$t8,$v1,0x2
/*  f061498:	0303c023 */ 	subu	$t8,$t8,$v1
/*  f06149c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0614a0:	0303c021 */ 	addu	$t8,$t8,$v1
/*  f0614a4:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0614a8:	27ad01fc */ 	addiu	$t5,$sp,0x1fc
/*  f0614ac:	030d1021 */ 	addu	$v0,$t8,$t5
/*  f0614b0:	2445008c */ 	addiu	$a1,$v0,0x8c
/*  f0614b4:	24460098 */ 	addiu	$a2,$v0,0x98
/*  f0614b8:	0fc2a534 */ 	jal	func0f0a94d0
/*  f0614bc:	8fa406f8 */ 	lw	$a0,0x6f8($sp)
/*  f0614c0:	10000007 */ 	b	.L0f0614e0
/*  f0614c4:	8fae06e4 */ 	lw	$t6,0x6e4($sp)
.L0f0614c8:
/*  f0614c8:	11600004 */ 	beqz	$t3,.L0f0614dc
/*  f0614cc:	8fa406f8 */ 	lw	$a0,0x6f8($sp)
/*  f0614d0:	27a50694 */ 	addiu	$a1,$sp,0x694
/*  f0614d4:	0fc2a534 */ 	jal	func0f0a94d0
/*  f0614d8:	27a606a0 */ 	addiu	$a2,$sp,0x6a0
.L0f0614dc:
/*  f0614dc:	8fae06e4 */ 	lw	$t6,0x6e4($sp)
.L0f0614e0:
/*  f0614e0:	27b001fc */ 	addiu	$s0,$sp,0x1fc
/*  f0614e4:	8fa806d0 */ 	lw	$t0,0x6d0($sp)
/*  f0614e8:	11c0019c */ 	beqz	$t6,.L0f061b5c
/*  f0614ec:	8faa01e8 */ 	lw	$t2,0x1e8($sp)
/*  f0614f0:	8e040040 */ 	lw	$a0,0x40($s0)
.L0f0614f4:
/*  f0614f4:	8faf01ec */ 	lw	$t7,0x1ec($sp)
/*  f0614f8:	50800070 */ 	beqzl	$a0,.L0f0616bc
/*  f0614fc:	26100068 */ 	addiu	$s0,$s0,0x68
/*  f061500:	11e00007 */ 	beqz	$t7,.L0f061520
/*  f061504:	3c014396 */ 	lui	$at,0x4396
/*  f061508:	44819000 */ 	mtc1	$at,$f18
/*  f06150c:	c604003c */ 	lwc1	$f4,0x3c($s0)
/*  f061510:	4604903c */ 	c.lt.s	$f18,$f4
/*  f061514:	00000000 */ 	nop
/*  f061518:	45030068 */ 	bc1tl	.L0f0616bc
/*  f06151c:	26100068 */ 	addiu	$s0,$s0,0x68
.L0f061520:
/*  f061520:	8c8a0004 */ 	lw	$t2,0x4($a0)
/*  f061524:	00003025 */ 	or	$a2,$zero,$zero
/*  f061528:	00801825 */ 	or	$v1,$a0,$zero
/*  f06152c:	afaa009c */ 	sw	$t2,0x9c($sp)
/*  f061530:	8c890018 */ 	lw	$t1,0x18($a0)
/*  f061534:	2605003c */ 	addiu	$a1,$s0,0x3c
/*  f061538:	51200007 */ 	beqzl	$t1,.L0f061558
/*  f06153c:	90620000 */ 	lbu	$v0,0x0($v1)
/*  f061540:	8c620018 */ 	lw	$v0,0x18($v1)
/*  f061544:	00401825 */ 	or	$v1,$v0,$zero
.L0f061548:
/*  f061548:	8c420018 */ 	lw	$v0,0x18($v0)
/*  f06154c:	5440fffe */ 	bnezl	$v0,.L0f061548
/*  f061550:	00401825 */ 	or	$v1,$v0,$zero
/*  f061554:	90620000 */ 	lbu	$v0,0x0($v1)
.L0f061558:
/*  f061558:	24010003 */ 	addiu	$at,$zero,0x3
/*  f06155c:	10410003 */ 	beq	$v0,$at,.L0f06156c
/*  f061560:	24010006 */ 	addiu	$at,$zero,0x6
/*  f061564:	5441000a */ 	bnel	$v0,$at,.L0f061590
/*  f061568:	90820000 */ 	lbu	$v0,0x0($a0)
.L0f06156c:
/*  f06156c:	27a401fc */ 	addiu	$a0,$sp,0x1fc
/*  f061570:	afa306d4 */ 	sw	$v1,0x6d4($sp)
/*  f061574:	0fc09f87 */ 	jal	func0f027e1c
/*  f061578:	afa60098 */ 	sw	$a2,0x98($sp)
/*  f06157c:	8fa306d4 */ 	lw	$v1,0x6d4($sp)
/*  f061580:	8fa60098 */ 	lw	$a2,0x98($sp)
/*  f061584:	10000011 */ 	b	.L0f0615cc
/*  f061588:	8fa806d0 */ 	lw	$t0,0x6d0($sp)
/*  f06158c:	90820000 */ 	lbu	$v0,0x0($a0)
.L0f061590:
/*  f061590:	24010001 */ 	addiu	$at,$zero,0x1
/*  f061594:	27a401fc */ 	addiu	$a0,$sp,0x1fc
/*  f061598:	10410006 */ 	beq	$v0,$at,.L0f0615b4
/*  f06159c:	2605003c */ 	addiu	$a1,$s0,0x3c
/*  f0615a0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0615a4:	10410003 */ 	beq	$v0,$at,.L0f0615b4
/*  f0615a8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0615ac:	54410008 */ 	bnel	$v0,$at,.L0f0615d0
/*  f0615b0:	820c0089 */ 	lb	$t4,0x89($s0)
.L0f0615b4:
/*  f0615b4:	afa306d4 */ 	sw	$v1,0x6d4($sp)
/*  f0615b8:	0fc217ab */ 	jal	func0f085eac
/*  f0615bc:	afa60098 */ 	sw	$a2,0x98($sp)
/*  f0615c0:	8fa306d4 */ 	lw	$v1,0x6d4($sp)
/*  f0615c4:	8fa60098 */ 	lw	$a2,0x98($sp)
/*  f0615c8:	8fa806d0 */ 	lw	$t0,0x6d0($sp)
.L0f0615cc:
/*  f0615cc:	820c0089 */ 	lb	$t4,0x89($s0)
.L0f0615d0:
/*  f0615d0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0615d4:	5180000b */ 	beqzl	$t4,.L0f061604
/*  f0615d8:	82180088 */ 	lb	$t8,0x88($s0)
/*  f0615dc:	afb906cc */ 	sw	$t9,0x6cc($sp)
/*  f0615e0:	c606008c */ 	lwc1	$f6,0x8c($s0)
/*  f0615e4:	01003025 */ 	or	$a2,$t0,$zero
/*  f0615e8:	e7a60648 */ 	swc1	$f6,0x648($sp)
/*  f0615ec:	c60a0090 */ 	lwc1	$f10,0x90($s0)
/*  f0615f0:	e7aa064c */ 	swc1	$f10,0x64c($sp)
/*  f0615f4:	c6080094 */ 	lwc1	$f8,0x94($s0)
/*  f0615f8:	10000019 */ 	b	.L0f061660
/*  f0615fc:	e7a80650 */ 	swc1	$f8,0x650($sp)
/*  f061600:	82180088 */ 	lb	$t8,0x88($s0)
.L0f061604:
/*  f061604:	8fab0234 */ 	lw	$t3,0x234($sp)
/*  f061608:	5700000a */ 	bnezl	$t8,.L0f061634
/*  f06160c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f061610:	11000013 */ 	beqz	$t0,.L0f061660
/*  f061614:	8fad009c */ 	lw	$t5,0x9c($sp)
/*  f061618:	91a20003 */ 	lbu	$v0,0x3($t5)
/*  f06161c:	2401002a */ 	addiu	$at,$zero,0x2a
/*  f061620:	10410003 */ 	beq	$v0,$at,.L0f061630
/*  f061624:	2401002f */ 	addiu	$at,$zero,0x2f
/*  f061628:	1441000d */ 	bne	$v0,$at,.L0f061660
/*  f06162c:	00000000 */ 	nop
.L0f061630:
/*  f061630:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f061634:
/*  f061634:	022b082a */ 	slt	$at,$s1,$t3
/*  f061638:	14200009 */ 	bnez	$at,.L0f061660
/*  f06163c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f061640:	afae06cc */ 	sw	$t6,0x6cc($sp)
/*  f061644:	c612008c */ 	lwc1	$f18,0x8c($s0)
/*  f061648:	01003025 */ 	or	$a2,$t0,$zero
/*  f06164c:	e7b20648 */ 	swc1	$f18,0x648($sp)
/*  f061650:	c6040090 */ 	lwc1	$f4,0x90($s0)
/*  f061654:	e7a4064c */ 	swc1	$f4,0x64c($sp)
/*  f061658:	c6060094 */ 	lwc1	$f6,0x94($s0)
/*  f06165c:	e7a60650 */ 	swc1	$f6,0x650($sp)
.L0f061660:
/*  f061660:	50c00016 */ 	beqzl	$a2,.L0f0616bc
/*  f061664:	26100068 */ 	addiu	$s0,$s0,0x68
/*  f061668:	c60a008c */ 	lwc1	$f10,0x8c($s0)
/*  f06166c:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f061670:	24650028 */ 	addiu	$a1,$v1,0x28
/*  f061674:	e7aa008c */ 	swc1	$f10,0x8c($sp)
/*  f061678:	c6080090 */ 	lwc1	$f8,0x90($s0)
/*  f06167c:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f061680:	27a7007c */ 	addiu	$a3,$sp,0x7c
/*  f061684:	e7a80090 */ 	swc1	$f8,0x90($sp)
/*  f061688:	c6120094 */ 	lwc1	$f18,0x94($s0)
/*  f06168c:	0fc1979d */ 	jal	func0f065e74
/*  f061690:	e7b20094 */ 	swc1	$f18,0x94($sp)
/*  f061694:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x28c)
/*  f061698:	8defa24c */ 	lw	$t7,%lo(g_Vars+0x28c)($t7)
/*  f06169c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0616a0:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0616a4:	27a6007c */ 	addiu	$a2,$sp,0x7c
/*  f0616a8:	24070016 */ 	addiu	$a3,$zero,0x16
/*  f0616ac:	0fc4a640 */ 	jal	explosionCreateSimple
/*  f0616b0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0616b4:	8fa806d0 */ 	lw	$t0,0x6d0($sp)
/*  f0616b8:	26100068 */ 	addiu	$s0,$s0,0x68
.L0f0616bc:
/*  f0616bc:	27aa060c */ 	addiu	$t2,$sp,0x60c
/*  f0616c0:	560aff8c */ 	bnel	$s0,$t2,.L0f0614f4
/*  f0616c4:	8e040040 */ 	lw	$a0,0x40($s0)
/*  f0616c8:	8fa906c8 */ 	lw	$t1,0x6c8($sp)
/*  f0616cc:	8fac06cc */ 	lw	$t4,0x6cc($sp)
/*  f0616d0:	1120011e */ 	beqz	$t1,.L0f061b4c
/*  f0616d4:	00000000 */ 	nop
/*  f0616d8:	1580011c */ 	bnez	$t4,.L0f061b4c
/*  f0616dc:	8fa606c4 */ 	lw	$a2,0x6c4($sp)
/*  f0616e0:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0616e4:	a7a6006c */ 	sh	$a2,0x6c($sp)
/*  f0616e8:	a7b8006e */ 	sh	$t8,0x6e($sp)
/*  f0616ec:	27a40218 */ 	addiu	$a0,$sp,0x218
/*  f0616f0:	0fc005cd */ 	jal	func0f001734
/*  f0616f4:	27a50648 */ 	addiu	$a1,$sp,0x648
/*  f0616f8:	87a606be */ 	lh	$a2,0x6be($sp)
/*  f0616fc:	00408825 */ 	or	$s1,$v0,$zero
/*  f061700:	3c108008 */ 	lui	$s0,%hi(somethings)
/*  f061704:	04c00003 */ 	bltz	$a2,.L0f061714
/*  f061708:	28c10daf */ 	slti	$at,$a2,0xdaf
/*  f06170c:	14200003 */ 	bnez	$at,.L0f06171c
/*  f061710:	3c0d800b */ 	lui	$t5,%hi(g_Textures)
.L0f061714:
/*  f061714:	10000010 */ 	b	.L0f061758
/*  f061718:	8e104458 */ 	lw	$s0,%lo(somethings)($s0)
.L0f06171c:
/*  f06171c:	87ab06be */ 	lh	$t3,0x6be($sp)
/*  f061720:	8dadabc0 */ 	lw	$t5,%lo(g_Textures)($t5)
/*  f061724:	3c108008 */ 	lui	$s0,%hi(somethings)
/*  f061728:	000b70c0 */ 	sll	$t6,$t3,0x3
/*  f06172c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f061730:	91e20000 */ 	lbu	$v0,0x0($t7)
/*  f061734:	304a000f */ 	andi	$t2,$v0,0xf
/*  f061738:	2d41000f */ 	sltiu	$at,$t2,0xf
/*  f06173c:	10200005 */ 	beqz	$at,.L0f061754
/*  f061740:	000a4880 */ 	sll	$t1,$t2,0x2
/*  f061744:	3c108008 */ 	lui	$s0,%hi(somethings)
/*  f061748:	02098021 */ 	addu	$s0,$s0,$t1
/*  f06174c:	10000002 */ 	b	.L0f061758
/*  f061750:	8e104458 */ 	lw	$s0,%lo(somethings)($s0)
.L0f061754:
/*  f061754:	8e104458 */ 	lw	$s0,%lo(somethings)($s0)
.L0f061758:
/*  f061758:	0fc2a519 */ 	jal	func0f0a9464
/*  f06175c:	27a40694 */ 	addiu	$a0,$sp,0x694
/*  f061760:	860c000a */ 	lh	$t4,0xa($s0)
/*  f061764:	8fb801f0 */ 	lw	$t8,0x1f0($sp)
/*  f061768:	198000fa */ 	blez	$t4,.L0f061b54
/*  f06176c:	00000000 */ 	nop
/*  f061770:	13000005 */ 	beqz	$t8,.L0f061788
/*  f061774:	93a40214 */ 	lbu	$a0,0x214($sp)
/*  f061778:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f06177c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f061780:	332b00ff */ 	andi	$t3,$t9,0xff
/*  f061784:	116100f3 */ 	beq	$t3,$at,.L0f061b54
.L0f061788:
/*  f061788:	24010001 */ 	addiu	$at,$zero,0x1
/*  f06178c:	1081002f */ 	beq	$a0,$at,.L0f06184c
/*  f061790:	2401001d */ 	addiu	$at,$zero,0x1d
/*  f061794:	1081002d */ 	beq	$a0,$at,.L0f06184c
/*  f061798:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f06179c:	1081002b */ 	beq	$a0,$at,.L0f06184c
/*  f0617a0:	24010016 */ 	addiu	$at,$zero,0x16
/*  f0617a4:	5081002a */ 	beql	$a0,$at,.L0f061850
/*  f0617a8:	27b0006c */ 	addiu	$s0,$sp,0x6c
/*  f0617ac:	0c004b70 */ 	jal	random
/*  f0617b0:	00000000 */ 	nop
/*  f0617b4:	860d000a */ 	lh	$t5,0xa($s0)
/*  f0617b8:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f0617bc:	27a40694 */ 	addiu	$a0,$sp,0x694
/*  f0617c0:	004d001b */ 	divu	$zero,$v0,$t5
/*  f0617c4:	00008810 */ 	mfhi	$s1
/*  f0617c8:	01d17821 */ 	addu	$t7,$t6,$s1
/*  f0617cc:	91f10000 */ 	lbu	$s1,0x0($t7)
/*  f0617d0:	15a00002 */ 	bnez	$t5,.L0f0617dc
/*  f0617d4:	00000000 */ 	nop
/*  f0617d8:	0007000d */ 	break	0x7
.L0f0617dc:
/*  f0617dc:	2a210003 */ 	slti	$at,$s1,0x3
/*  f0617e0:	14200005 */ 	bnez	$at,.L0f0617f8
/*  f0617e4:	27a506a0 */ 	addiu	$a1,$sp,0x6a0
/*  f0617e8:	2a210006 */ 	slti	$at,$s1,0x6
/*  f0617ec:	10200002 */ 	beqz	$at,.L0f0617f8
/*  f0617f0:	00000000 */ 	nop
/*  f0617f4:	2631000a */ 	addiu	$s1,$s1,0xa
.L0f0617f8:
/*  f0617f8:	12200014 */ 	beqz	$s1,.L0f06184c
/*  f0617fc:	27a60218 */ 	addiu	$a2,$sp,0x218
/*  f061800:	8faa06c4 */ 	lw	$t2,0x6c4($sp)
/*  f061804:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x284)
/*  f061808:	8d8ca244 */ 	lw	$t4,%lo(g_Vars+0x284)($t4)
/*  f06180c:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f061810:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f061814:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f061818:	afb10014 */ 	sw	$s1,0x14($sp)
/*  f06181c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f061820:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f061824:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f061828:	87ab06c0 */ 	lh	$t3,0x6c0($sp)
/*  f06182c:	8d9800bc */ 	lw	$t8,0xbc($t4)
/*  f061830:	00003825 */ 	or	$a3,$zero,$zero
/*  f061834:	396d0002 */ 	xori	$t5,$t3,0x2
/*  f061838:	8f190004 */ 	lw	$t9,0x4($t8)
/*  f06183c:	2dad0001 */ 	sltiu	$t5,$t5,0x1
/*  f061840:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f061844:	0fc4fcfd */ 	jal	func0f13f3f4
/*  f061848:	afb90028 */ 	sw	$t9,0x28($sp)
.L0f06184c:
/*  f06184c:	27b0006c */ 	addiu	$s0,$sp,0x6c
.L0f061850:
/*  f061850:	87a606be */ 	lh	$a2,0x6be($sp)
/*  f061854:	02003825 */ 	or	$a3,$s0,$zero
/*  f061858:	27a40214 */ 	addiu	$a0,$sp,0x214
/*  f06185c:	0fc2a132 */ 	jal	func0f0a84c8
/*  f061860:	27a50694 */ 	addiu	$a1,$sp,0x694
/*  f061864:	8fae06d0 */ 	lw	$t6,0x6d0($sp)
/*  f061868:	00002025 */ 	or	$a0,$zero,$zero
/*  f06186c:	27a50694 */ 	addiu	$a1,$sp,0x694
/*  f061870:	11c00009 */ 	beqz	$t6,.L0f061898
/*  f061874:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x284)
/*  f061878:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x28c)
/*  f06187c:	8defa24c */ 	lw	$t7,%lo(g_Vars+0x28c)($t7)
/*  f061880:	02003025 */ 	or	$a2,$s0,$zero
/*  f061884:	24070016 */ 	addiu	$a3,$zero,0x16
/*  f061888:	0fc4a640 */ 	jal	explosionCreateSimple
/*  f06188c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f061890:	100000b0 */ 	b	.L0f061b54
/*  f061894:	00000000 */ 	nop
.L0f061898:
/*  f061898:	8d4aa244 */ 	lw	$t2,%lo(g_Vars+0x284)($t2)
/*  f06189c:	8d4900bc */ 	lw	$t1,0xbc($t2)
/*  f0618a0:	0fc4f92a */ 	jal	chrIsUsingPaintball
/*  f0618a4:	8d240004 */ 	lw	$a0,0x4($t1)
/*  f0618a8:	14400033 */ 	bnez	$v0,.L0f061978
/*  f0618ac:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x6c)
/*  f0618b0:	8d8ca02c */ 	lw	$t4,%lo(g_Vars+0x6c)($t4)
/*  f0618b4:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x68)
/*  f0618b8:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x64)
/*  f0618bc:	11800003 */ 	beqz	$t4,.L0f0618cc
/*  f0618c0:	3c0b800a */ 	lui	$t3,%hi(g_Vars+0x70)
/*  f0618c4:	10000002 */ 	b	.L0f0618d0
/*  f0618c8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0618cc:
/*  f0618cc:	00002825 */ 	or	$a1,$zero,$zero
.L0f0618d0:
/*  f0618d0:	8f18a028 */ 	lw	$t8,%lo(g_Vars+0x68)($t8)
/*  f0618d4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0618d8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0618dc:	13000003 */ 	beqz	$t8,.L0f0618ec
/*  f0618e0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0618e4:	10000001 */ 	b	.L0f0618ec
/*  f0618e8:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0618ec:
/*  f0618ec:	8f39a024 */ 	lw	$t9,%lo(g_Vars+0x64)($t9)
/*  f0618f0:	13200003 */ 	beqz	$t9,.L0f061900
/*  f0618f4:	00000000 */ 	nop
/*  f0618f8:	10000001 */ 	b	.L0f061900
/*  f0618fc:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f061900:
/*  f061900:	8d6ba030 */ 	lw	$t3,%lo(g_Vars+0x70)($t3)
/*  f061904:	11600003 */ 	beqz	$t3,.L0f061914
/*  f061908:	00000000 */ 	nop
/*  f06190c:	10000001 */ 	b	.L0f061914
/*  f061910:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f061914:
/*  f061914:	00436821 */ 	addu	$t5,$v0,$v1
/*  f061918:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f06191c:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f061920:	29e10002 */ 	slti	$at,$t7,0x2
/*  f061924:	1420000b */ 	bnez	$at,.L0f061954
/*  f061928:	00000000 */ 	nop
/*  f06192c:	0c004b70 */ 	jal	random
/*  f061930:	00000000 */ 	nop
/*  f061934:	304a0007 */ 	andi	$t2,$v0,0x7
/*  f061938:	1540000f */ 	bnez	$t2,.L0f061978
/*  f06193c:	27a40694 */ 	addiu	$a0,$sp,0x694
/*  f061940:	02002825 */ 	or	$a1,$s0,$zero
/*  f061944:	0fc4ba08 */ 	jal	smokeCreateSimple
/*  f061948:	24060007 */ 	addiu	$a2,$zero,0x7
/*  f06194c:	1000000a */ 	b	.L0f061978
/*  f061950:	00000000 */ 	nop
.L0f061954:
/*  f061954:	12200008 */ 	beqz	$s1,.L0f061978
/*  f061958:	00002025 */ 	or	$a0,$zero,$zero
/*  f06195c:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x28c)
/*  f061960:	8d29a24c */ 	lw	$t1,%lo(g_Vars+0x28c)($t1)
/*  f061964:	27a50694 */ 	addiu	$a1,$sp,0x694
/*  f061968:	02003025 */ 	or	$a2,$s0,$zero
/*  f06196c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f061970:	0fc4a640 */ 	jal	explosionCreateSimple
/*  f061974:	afa90010 */ 	sw	$t1,0x10($sp)
.L0f061978:
/*  f061978:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x6c)
/*  f06197c:	8d8ca02c */ 	lw	$t4,%lo(g_Vars+0x6c)($t4)
/*  f061980:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x68)
/*  f061984:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x64)
/*  f061988:	3c06800a */ 	lui	$a2,%hi(g_Vars+0x70)
/*  f06198c:	8cc6a030 */ 	lw	$a2,%lo(g_Vars+0x70)($a2)
/*  f061990:	8c63a024 */ 	lw	$v1,%lo(g_Vars+0x64)($v1)
/*  f061994:	11800003 */ 	beqz	$t4,.L0f0619a4
/*  f061998:	8c42a028 */ 	lw	$v0,%lo(g_Vars+0x68)($v0)
/*  f06199c:	10000002 */ 	b	.L0f0619a8
/*  f0619a0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0619a4:
/*  f0619a4:	00002825 */ 	or	$a1,$zero,$zero
.L0f0619a8:
/*  f0619a8:	10400003 */ 	beqz	$v0,.L0f0619b8
/*  f0619ac:	00002025 */ 	or	$a0,$zero,$zero
/*  f0619b0:	10000001 */ 	b	.L0f0619b8
/*  f0619b4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0619b8:
/*  f0619b8:	10600003 */ 	beqz	$v1,.L0f0619c8
/*  f0619bc:	00001025 */ 	or	$v0,$zero,$zero
/*  f0619c0:	10000002 */ 	b	.L0f0619cc
/*  f0619c4:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0619c8:
/*  f0619c8:	00001825 */ 	or	$v1,$zero,$zero
.L0f0619cc:
/*  f0619cc:	10c00003 */ 	beqz	$a2,.L0f0619dc
/*  f0619d0:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x34)
/*  f0619d4:	10000001 */ 	b	.L0f0619dc
/*  f0619d8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0619dc:
/*  f0619dc:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f0619e0:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f0619e4:	03255821 */ 	addu	$t3,$t9,$a1
/*  f0619e8:	29610003 */ 	slti	$at,$t3,0x3
/*  f0619ec:	5420000a */ 	bnezl	$at,.L0f061a18
/*  f0619f0:	3c01c6fa */ 	lui	$at,0xc6fa
/*  f0619f4:	8dad9ff4 */ 	lw	$t5,%lo(g_Vars+0x34)($t5)
/*  f0619f8:	29a10009 */ 	slti	$at,$t5,0x9
/*  f0619fc:	54200006 */ 	bnezl	$at,.L0f061a18
/*  f061a00:	3c01c6fa */ 	lui	$at,0xc6fa
/*  f061a04:	0c004b70 */ 	jal	random
/*  f061a08:	00000000 */ 	nop
/*  f061a0c:	304e0003 */ 	andi	$t6,$v0,0x3
/*  f061a10:	15c00050 */ 	bnez	$t6,.L0f061b54
/*  f061a14:	3c01c6fa */ 	lui	$at,0xc6fa
.L0f061a18:
/*  f061a18:	44810000 */ 	mtc1	$at,$f0
/*  f061a1c:	c7ac0694 */ 	lwc1	$f12,0x694($sp)
/*  f061a20:	3c0146fa */ 	lui	$at,0x46fa
/*  f061a24:	460c003c */ 	c.lt.s	$f0,$f12
/*  f061a28:	00000000 */ 	nop
/*  f061a2c:	45000049 */ 	bc1f	.L0f061b54
/*  f061a30:	00000000 */ 	nop
/*  f061a34:	44811000 */ 	mtc1	$at,$f2
/*  f061a38:	00000000 */ 	nop
/*  f061a3c:	4602603c */ 	c.lt.s	$f12,$f2
/*  f061a40:	c7ac0698 */ 	lwc1	$f12,0x698($sp)
/*  f061a44:	45000043 */ 	bc1f	.L0f061b54
/*  f061a48:	00000000 */ 	nop
/*  f061a4c:	460c003c */ 	c.lt.s	$f0,$f12
/*  f061a50:	00000000 */ 	nop
/*  f061a54:	4500003f */ 	bc1f	.L0f061b54
/*  f061a58:	00000000 */ 	nop
/*  f061a5c:	4602603c */ 	c.lt.s	$f12,$f2
/*  f061a60:	c7ac069c */ 	lwc1	$f12,0x69c($sp)
/*  f061a64:	4500003b */ 	bc1f	.L0f061b54
/*  f061a68:	00000000 */ 	nop
/*  f061a6c:	460c003c */ 	c.lt.s	$f0,$f12
/*  f061a70:	00000000 */ 	nop
/*  f061a74:	45000037 */ 	bc1f	.L0f061b54
/*  f061a78:	00000000 */ 	nop
/*  f061a7c:	4602603c */ 	c.lt.s	$f12,$f2
/*  f061a80:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x284)
/*  f061a84:	45000033 */ 	bc1f	.L0f061b54
/*  f061a88:	00000000 */ 	nop
/*  f061a8c:	8defa244 */ 	lw	$t7,%lo(g_Vars+0x284)($t7)
/*  f061a90:	00008025 */ 	or	$s0,$zero,$zero
/*  f061a94:	8dea00bc */ 	lw	$t2,0xbc($t7)
/*  f061a98:	0fc4f92a */ 	jal	chrIsUsingPaintball
/*  f061a9c:	8d440004 */ 	lw	$a0,0x4($t2)
/*  f061aa0:	10400003 */ 	beqz	$v0,.L0f061ab0
/*  f061aa4:	93a90214 */ 	lbu	$t1,0x214($sp)
/*  f061aa8:	1000001e */ 	b	.L0f061b24
/*  f061aac:	24100019 */ 	addiu	$s0,$zero,0x19
.L0f061ab0:
/*  f061ab0:	252cfffa */ 	addiu	$t4,$t1,-6
/*  f061ab4:	2d810017 */ 	sltiu	$at,$t4,0x17
/*  f061ab8:	1020000d */ 	beqz	$at,.L0f061af0
/*  f061abc:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f061ac0:	3c017f1b */ 	lui	$at,%hi(var7f1a9e60)
/*  f061ac4:	002c0821 */ 	addu	$at,$at,$t4
/*  f061ac8:	8c2c9e60 */ 	lw	$t4,%lo(var7f1a9e60)($at)
/*  f061acc:	01800008 */ 	jr	$t4
/*  f061ad0:	00000000 */ 	nop
/*  f061ad4:	10000006 */ 	b	.L0f061af0
/*  f061ad8:	24100016 */ 	addiu	$s0,$zero,0x16
/*  f061adc:	10000004 */ 	b	.L0f061af0
/*  f061ae0:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f061ae4:	10000002 */ 	b	.L0f061af0
/*  f061ae8:	24100017 */ 	addiu	$s0,$zero,0x17
/*  f061aec:	24100018 */ 	addiu	$s0,$zero,0x18
.L0f061af0:
/*  f061af0:	87b906be */ 	lh	$t9,0x6be($sp)
/*  f061af4:	3c18800b */ 	lui	$t8,%hi(g_Textures)
/*  f061af8:	8f18abc0 */ 	lw	$t8,%lo(g_Textures)($t8)
/*  f061afc:	001958c0 */ 	sll	$t3,$t9,0x3
/*  f061b00:	24010005 */ 	addiu	$at,$zero,0x5
/*  f061b04:	030b6821 */ 	addu	$t5,$t8,$t3
/*  f061b08:	91b10000 */ 	lbu	$s1,0x0($t5)
/*  f061b0c:	322e000f */ 	andi	$t6,$s1,0xf
/*  f061b10:	11c10003 */ 	beq	$t6,$at,.L0f061b20
/*  f061b14:	2401000e */ 	addiu	$at,$zero,0xe
/*  f061b18:	55c10003 */ 	bnel	$t6,$at,.L0f061b28
/*  f061b1c:	27af06a0 */ 	addiu	$t7,$sp,0x6a0
.L0f061b20:
/*  f061b20:	2410000f */ 	addiu	$s0,$zero,0xf
.L0f061b24:
/*  f061b24:	27af06a0 */ 	addiu	$t7,$sp,0x6a0
.L0f061b28:
/*  f061b28:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f061b2c:	8fa406c4 */ 	lw	$a0,0x6c4($sp)
/*  f061b30:	00002825 */ 	or	$a1,$zero,$zero
/*  f061b34:	27a60694 */ 	addiu	$a2,$sp,0x694
/*  f061b38:	27a70224 */ 	addiu	$a3,$sp,0x224
/*  f061b3c:	0fc4be7c */ 	jal	sparksCreate
/*  f061b40:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f061b44:	10000003 */ 	b	.L0f061b54
/*  f061b48:	00000000 */ 	nop
.L0f061b4c:
/*  f061b4c:	0fc2a519 */ 	jal	func0f0a9464
/*  f061b50:	27a40648 */ 	addiu	$a0,$sp,0x648
.L0f061b54:
/*  f061b54:	10000079 */ 	b	.L0f061d3c
/*  f061b58:	8fa601e0 */ 	lw	$a2,0x1e0($sp)
.L0f061b5c:
/*  f061b5c:	11400047 */ 	beqz	$t2,.L0f061c7c
/*  f061b60:	00001825 */ 	or	$v1,$zero,$zero
/*  f061b64:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f061b68:	00008825 */ 	or	$s1,$zero,$zero
/*  f061b6c:	00004025 */ 	or	$t0,$zero,$zero
/*  f061b70:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f061b74:	93a40214 */ 	lbu	$a0,0x214($sp)
/*  f061b78:	27b001fc */ 	addiu	$s0,$sp,0x1fc
/*  f061b7c:	c7a001e4 */ 	lwc1	$f0,0x1e4($sp)
/*  f061b80:	2402000a */ 	addiu	$v0,$zero,0xa
.L0f061b84:
/*  f061b84:	8e090040 */ 	lw	$t1,0x40($s0)
/*  f061b88:	8fac01f8 */ 	lw	$t4,0x1f8($sp)
/*  f061b8c:	11200009 */ 	beqz	$t1,.L0f061bb4
/*  f061b90:	25990001 */ 	addiu	$t9,$t4,0x1
/*  f061b94:	c604003c */ 	lwc1	$f4,0x3c($s0)
/*  f061b98:	4600203c */ 	c.lt.s	$f4,$f0
/*  f061b9c:	00000000 */ 	nop
/*  f061ba0:	45020005 */ 	bc1fl	.L0f061bb8
/*  f061ba4:	afb901f8 */ 	sw	$t9,0x1f8($sp)
/*  f061ba8:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f061bac:	10000004 */ 	b	.L0f061bc0
/*  f061bb0:	8fa801f8 */ 	lw	$t0,0x1f8($sp)
.L0f061bb4:
/*  f061bb4:	afb901f8 */ 	sw	$t9,0x1f8($sp)
.L0f061bb8:
/*  f061bb8:	1722fff2 */ 	bne	$t9,$v0,.L0f061b84
/*  f061bbc:	26100068 */ 	addiu	$s0,$s0,0x68
.L0f061bc0:
/*  f061bc0:	16200003 */ 	bnez	$s1,.L0f061bd0
/*  f061bc4:	8fb806c8 */ 	lw	$t8,0x6c8($sp)
/*  f061bc8:	13000028 */ 	beqz	$t8,.L0f061c6c
/*  f061bcc:	00000000 */ 	nop
.L0f061bd0:
/*  f061bd0:	8c6500bc */ 	lw	$a1,0xbc($v1)
/*  f061bd4:	0fc182eb */ 	jal	func0f060bac
/*  f061bd8:	afa80060 */ 	sw	$t0,0x60($sp)
/*  f061bdc:	93a40214 */ 	lbu	$a0,0x214($sp)
/*  f061be0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f061be4:	8fa80060 */ 	lw	$t0,0x60($sp)
/*  f061be8:	10810022 */ 	beq	$a0,$at,.L0f061c74
/*  f061bec:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f061bf0:	10810020 */ 	beq	$a0,$at,.L0f061c74
/*  f061bf4:	00000000 */ 	nop
/*  f061bf8:	12200013 */ 	beqz	$s1,.L0f061c48
/*  f061bfc:	8fa406c4 */ 	lw	$a0,0x6c4($sp)
/*  f061c00:	00085880 */ 	sll	$t3,$t0,0x2
/*  f061c04:	01685823 */ 	subu	$t3,$t3,$t0
/*  f061c08:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f061c0c:	01685821 */ 	addu	$t3,$t3,$t0
/*  f061c10:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f061c14:	27ad01fc */ 	addiu	$t5,$sp,0x1fc
/*  f061c18:	016d1021 */ 	addu	$v0,$t3,$t5
/*  f061c1c:	8c4e0040 */ 	lw	$t6,0x40($v0)
/*  f061c20:	244f0098 */ 	addiu	$t7,$v0,0x98
/*  f061c24:	2446008c */ 	addiu	$a2,$v0,0x8c
/*  f061c28:	85c40028 */ 	lh	$a0,0x28($t6)
/*  f061c2c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f061c30:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f061c34:	00002825 */ 	or	$a1,$zero,$zero
/*  f061c38:	0fc4be7c */ 	jal	sparksCreate
/*  f061c3c:	27a70224 */ 	addiu	$a3,$sp,0x224
/*  f061c40:	1000000c */ 	b	.L0f061c74
/*  f061c44:	00000000 */ 	nop
.L0f061c48:
/*  f061c48:	27aa06a0 */ 	addiu	$t2,$sp,0x6a0
/*  f061c4c:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f061c50:	00002825 */ 	or	$a1,$zero,$zero
/*  f061c54:	27a60694 */ 	addiu	$a2,$sp,0x694
/*  f061c58:	27a70224 */ 	addiu	$a3,$sp,0x224
/*  f061c5c:	0fc4be7c */ 	jal	sparksCreate
/*  f061c60:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f061c64:	10000003 */ 	b	.L0f061c74
/*  f061c68:	00000000 */ 	nop
.L0f061c6c:
/*  f061c6c:	0fc18261 */ 	jal	func0f060984
/*  f061c70:	8c6500bc */ 	lw	$a1,0xbc($v1)
.L0f061c74:
/*  f061c74:	10000031 */ 	b	.L0f061d3c
/*  f061c78:	8fa601e0 */ 	lw	$a2,0x1e0($sp)
.L0f061c7c:
/*  f061c7c:	27b001fc */ 	addiu	$s0,$sp,0x1fc
/*  f061c80:	8fa601e0 */ 	lw	$a2,0x1e0($sp)
/*  f061c84:	27a5060c */ 	addiu	$a1,$sp,0x60c
/*  f061c88:	8e040040 */ 	lw	$a0,0x40($s0)
.L0f061c8c:
/*  f061c8c:	50800029 */ 	beqzl	$a0,.L0f061d34
/*  f061c90:	26100068 */ 	addiu	$s0,$s0,0x68
/*  f061c94:	14600026 */ 	bnez	$v1,.L0f061d30
/*  f061c98:	8fa901ec */ 	lw	$t1,0x1ec($sp)
/*  f061c9c:	11200009 */ 	beqz	$t1,.L0f061cc4
/*  f061ca0:	3c014396 */ 	lui	$at,0x4396
/*  f061ca4:	44813000 */ 	mtc1	$at,$f6
/*  f061ca8:	c60a003c */ 	lwc1	$f10,0x3c($s0)
/*  f061cac:	460a303c */ 	c.lt.s	$f6,$f10
/*  f061cb0:	00000000 */ 	nop
/*  f061cb4:	45020004 */ 	bc1fl	.L0f061cc8
/*  f061cb8:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f061cbc:	1000001c */ 	b	.L0f061d30
/*  f061cc0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f061cc4:
/*  f061cc4:	90820000 */ 	lbu	$v0,0x0($a0)
.L0f061cc8:
/*  f061cc8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f061ccc:	8fb90234 */ 	lw	$t9,0x234($sp)
/*  f061cd0:	10410003 */ 	beq	$v0,$at,.L0f061ce0
/*  f061cd4:	24010006 */ 	addiu	$at,$zero,0x6
/*  f061cd8:	54410005 */ 	bnel	$v0,$at,.L0f061cf0
/*  f061cdc:	24010001 */ 	addiu	$at,$zero,0x1
.L0f061ce0:
/*  f061ce0:	00803025 */ 	or	$a2,$a0,$zero
/*  f061ce4:	1000000a */ 	b	.L0f061d10
/*  f061ce8:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f061cec:	24010001 */ 	addiu	$at,$zero,0x1
.L0f061cf0:
/*  f061cf0:	10410005 */ 	beq	$v0,$at,.L0f061d08
/*  f061cf4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f061cf8:	10410003 */ 	beq	$v0,$at,.L0f061d08
/*  f061cfc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f061d00:	54410004 */ 	bnel	$v0,$at,.L0f061d14
/*  f061d04:	820c0088 */ 	lb	$t4,0x88($s0)
.L0f061d08:
/*  f061d08:	00803025 */ 	or	$a2,$a0,$zero
/*  f061d0c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f061d10:
/*  f061d10:	820c0088 */ 	lb	$t4,0x88($s0)
.L0f061d14:
/*  f061d14:	51800007 */ 	beqzl	$t4,.L0f061d34
/*  f061d18:	26100068 */ 	addiu	$s0,$s0,0x68
/*  f061d1c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f061d20:	0239082a */ 	slt	$at,$s1,$t9
/*  f061d24:	54200003 */ 	bnezl	$at,.L0f061d34
/*  f061d28:	26100068 */ 	addiu	$s0,$s0,0x68
/*  f061d2c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f061d30:
/*  f061d30:	26100068 */ 	addiu	$s0,$s0,0x68
.L0f061d34:
/*  f061d34:	5605ffd5 */ 	bnel	$s0,$a1,.L0f061c8c
/*  f061d38:	8e040040 */ 	lw	$a0,0x40($s0)
.L0f061d3c:
/*  f061d3c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f061d40:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f061d44:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f061d48:	27bd06e0 */ 	addiu	$sp,$sp,0x6e0
/*  f061d4c:	03e00008 */ 	jr	$ra
/*  f061d50:	00c01025 */ 	or	$v0,$a2,$zero
);

GLOBAL_ASM(
glabel func0f061d54
.late_rodata
glabel var7f1a9ebc
.word 0x4f7ffe00
.text
/*  f061d54:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f061d58:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f061d5c:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f061d60:	afa50074 */ 	sw	$a1,0x74($sp)
/*  f061d64:	afa60078 */ 	sw	$a2,0x78($sp)
/*  f061d68:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f061d6c:	8fa60070 */ 	lw	$a2,0x70($sp)
/*  f061d70:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f061d74:	0fc2832c */ 	jal	func0f0a0cb0
/*  f061d78:	27a40058 */ 	addiu	$a0,$sp,0x58
/*  f061d7c:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f061d80:	24010002 */ 	addiu	$at,$zero,0x2
/*  f061d84:	15c10018 */ 	bne	$t6,$at,.L0f061de8
/*  f061d88:	00000000 */ 	nop
/*  f061d8c:	0fc2866a */ 	jal	handGetWeaponNum
/*  f061d90:	00002025 */ 	or	$a0,$zero,$zero
/*  f061d94:	24010014 */ 	addiu	$at,$zero,0x14
/*  f061d98:	14410013 */ 	bne	$v0,$at,.L0f061de8
/*  f061d9c:	00000000 */ 	nop
/*  f061da0:	0c004b70 */ 	jal	random
/*  f061da4:	00000000 */ 	nop
/*  f061da8:	44822000 */ 	mtc1	$v0,$f4
/*  f061dac:	3c014f80 */ 	lui	$at,0x4f80
/*  f061db0:	04410004 */ 	bgez	$v0,.L0f061dc4
/*  f061db4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f061db8:	44814000 */ 	mtc1	$at,$f8
/*  f061dbc:	00000000 */ 	nop
/*  f061dc0:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f061dc4:
/*  f061dc4:	3c012f80 */ 	lui	$at,0x2f80
/*  f061dc8:	44815000 */ 	mtc1	$at,$f10
/*  f061dcc:	3c014170 */ 	lui	$at,0x4170
/*  f061dd0:	44819000 */ 	mtc1	$at,$f18
/*  f061dd4:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f061dd8:	c7a8005c */ 	lwc1	$f8,0x5c($sp)
/*  f061ddc:	46109102 */ 	mul.s	$f4,$f18,$f16
/*  f061de0:	46044181 */ 	sub.s	$f6,$f8,$f4
/*  f061de4:	e7a6005c */ 	swc1	$f6,0x5c($sp)
.L0f061de8:
/*  f061de8:	0fc2d5de */ 	jal	currentPlayerGetUnk174c
/*  f061dec:	00000000 */ 	nop
/*  f061df0:	00402025 */ 	or	$a0,$v0,$zero
/*  f061df4:	27a50058 */ 	addiu	$a1,$sp,0x58
/*  f061df8:	0c0056da */ 	jal	func00015b68
/*  f061dfc:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f061e00:	0fc2d5de */ 	jal	currentPlayerGetUnk174c
/*  f061e04:	00000000 */ 	nop
/*  f061e08:	00402025 */ 	or	$a0,$v0,$zero
/*  f061e0c:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f061e10:	0c0056c5 */ 	jal	func00015b14
/*  f061e14:	27a6004c */ 	addiu	$a2,$sp,0x4c
/*  f061e18:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f061e1c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f061e20:	8c4f006c */ 	lw	$t7,0x6c($v0)
/*  f061e24:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f061e28:	8fa50074 */ 	lw	$a1,0x74($sp)
/*  f061e2c:	11e00003 */ 	beqz	$t7,.L0f061e3c
/*  f061e30:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f061e34:	10000002 */ 	b	.L0f061e40
/*  f061e38:	24090001 */ 	addiu	$t1,$zero,0x1
.L0f061e3c:
/*  f061e3c:	00004825 */ 	or	$t1,$zero,$zero
.L0f061e40:
/*  f061e40:	8c580068 */ 	lw	$t8,0x68($v0)
/*  f061e44:	27a70064 */ 	addiu	$a3,$sp,0x64
/*  f061e48:	27ab0040 */ 	addiu	$t3,$sp,0x40
/*  f061e4c:	13000003 */ 	beqz	$t8,.L0f061e5c
/*  f061e50:	27ac004c */ 	addiu	$t4,$sp,0x4c
/*  f061e54:	10000002 */ 	b	.L0f061e60
/*  f061e58:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f061e5c:
/*  f061e5c:	00001825 */ 	or	$v1,$zero,$zero
.L0f061e60:
/*  f061e60:	8c590064 */ 	lw	$t9,0x64($v0)
/*  f061e64:	3c017f1b */ 	lui	$at,%hi(var7f1a9ebc)
/*  f061e68:	00004025 */ 	or	$t0,$zero,$zero
/*  f061e6c:	13200003 */ 	beqz	$t9,.L0f061e7c
/*  f061e70:	00000000 */ 	nop
/*  f061e74:	10000001 */ 	b	.L0f061e7c
/*  f061e78:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f061e7c:
/*  f061e7c:	8c4a0070 */ 	lw	$t2,0x70($v0)
/*  f061e80:	00001025 */ 	or	$v0,$zero,$zero
/*  f061e84:	11400003 */ 	beqz	$t2,.L0f061e94
/*  f061e88:	00000000 */ 	nop
/*  f061e8c:	10000001 */ 	b	.L0f061e94
/*  f061e90:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f061e94:
/*  f061e94:	00486821 */ 	addu	$t5,$v0,$t0
/*  f061e98:	01a37021 */ 	addu	$t6,$t5,$v1
/*  f061e9c:	01c97821 */ 	addu	$t7,$t6,$t1
/*  f061ea0:	c42a9ebc */ 	lwc1	$f10,%lo(var7f1a9ebc)($at)
/*  f061ea4:	29f80002 */ 	slti	$t8,$t7,0x2
/*  f061ea8:	3b180001 */ 	xori	$t8,$t8,0x1
/*  f061eac:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f061eb0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f061eb4:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f061eb8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f061ebc:	0fc1836e */ 	jal	func0f060db8
/*  f061ec0:	e7aa001c */ 	swc1	$f10,0x1c($sp)
/*  f061ec4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f061ec8:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*  f061ecc:	03e00008 */ 	jr	$ra
/*  f061ed0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f061ed4
.late_rodata
glabel var7f1a9ec0
.word 0x4f7ffe00
.text
/*  f061ed4:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f061ed8:	afa70074 */ 	sw	$a3,0x74($sp)
/*  f061edc:	00c03825 */ 	or	$a3,$a2,$zero
/*  f061ee0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f061ee4:	afa40068 */ 	sw	$a0,0x68($sp)
/*  f061ee8:	afa5006c */ 	sw	$a1,0x6c($sp)
/*  f061eec:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f061ef0:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f061ef4:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f061ef8:	0fc2832c */ 	jal	func0f0a0cb0
/*  f061efc:	27a40038 */ 	addiu	$a0,$sp,0x38
/*  f061f00:	8fae0074 */ 	lw	$t6,0x74($sp)
/*  f061f04:	59c00025 */ 	blezl	$t6,.L0f061f9c
/*  f061f08:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f061f0c:	0fc2d5de */ 	jal	currentPlayerGetUnk174c
/*  f061f10:	00000000 */ 	nop
/*  f061f14:	00402025 */ 	or	$a0,$v0,$zero
/*  f061f18:	27a50038 */ 	addiu	$a1,$sp,0x38
/*  f061f1c:	0c0056da */ 	jal	func00015b68
/*  f061f20:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f061f24:	0fc2d5de */ 	jal	currentPlayerGetUnk174c
/*  f061f28:	00000000 */ 	nop
/*  f061f2c:	00402025 */ 	or	$a0,$v0,$zero
/*  f061f30:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f061f34:	0c0056c5 */ 	jal	func00015b14
/*  f061f38:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*  f061f3c:	3c017f1b */ 	lui	$at,%hi(var7f1a9ec0)
/*  f061f40:	c4249ec0 */ 	lwc1	$f4,%lo(var7f1a9ec0)($at)
/*  f061f44:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f061f48:	27af0050 */ 	addiu	$t7,$sp,0x50
/*  f061f4c:	27b8005c */ 	addiu	$t8,$sp,0x5c
/*  f061f50:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f061f54:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f061f58:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f061f5c:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f061f60:	27a60038 */ 	addiu	$a2,$sp,0x38
/*  f061f64:	27a70044 */ 	addiu	$a3,$sp,0x44
/*  f061f68:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f061f6c:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f061f70:	0fc1836e */ 	jal	func0f060db8
/*  f061f74:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f061f78:	8fa80074 */ 	lw	$t0,0x74($sp)
/*  f061f7c:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f061f80:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f061f84:	29010002 */ 	slti	$at,$t0,0x2
/*  f061f88:	50200004 */ 	beqzl	$at,.L0f061f9c
/*  f061f8c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f061f90:	0fc284ac */ 	jal	func0f0a12b0
/*  f061f94:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f061f98:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f061f9c:
/*  f061f9c:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*  f061fa0:	03e00008 */ 	jr	$ra
/*  f061fa4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f061fa8
/*  f061fa8:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f061fac:	8fae006c */ 	lw	$t6,0x6c($sp)
/*  f061fb0:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f061fb4:	4486a000 */ 	mtc1	$a2,$f20
/*  f061fb8:	00803025 */ 	or	$a2,$a0,$zero
/*  f061fbc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f061fc0:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f061fc4:	11c00045 */ 	beqz	$t6,.L0f0620dc
/*  f061fc8:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f061fcc:	44806000 */ 	mtc1	$zero,$f12
/*  f061fd0:	00002825 */ 	or	$a1,$zero,$zero
/*  f061fd4:	00001825 */ 	or	$v1,$zero,$zero
/*  f061fd8:	00002025 */ 	or	$a0,$zero,$zero
/*  f061fdc:	00c01025 */ 	or	$v0,$a2,$zero
/*  f061fe0:	46006086 */ 	mov.s	$f2,$f12
.L0f061fe4:
/*  f061fe4:	8c4f0040 */ 	lw	$t7,0x40($v0)
/*  f061fe8:	51e0000e */ 	beqzl	$t7,.L0f062024
/*  f061fec:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f061ff0:	80580088 */ 	lb	$t8,0x88($v0)
/*  f061ff4:	5300000b */ 	beqzl	$t8,.L0f062024
/*  f061ff8:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f061ffc:	c440003c */ 	lwc1	$f0,0x3c($v0)
/*  f062000:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f062004:	4600103c */ 	c.lt.s	$f2,$f0
/*  f062008:	00000000 */ 	nop
/*  f06200c:	45020005 */ 	bc1fl	.L0f062024
/*  f062010:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f062014:	46001306 */ 	mov.s	$f12,$f2
/*  f062018:	46000086 */ 	mov.s	$f2,$f0
/*  f06201c:	00802825 */ 	or	$a1,$a0,$zero
/*  f062020:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f062024:
/*  f062024:	2881000a */ 	slti	$at,$a0,0xa
/*  f062028:	1420ffee */ 	bnez	$at,.L0f061fe4
/*  f06202c:	24420068 */ 	addiu	$v0,$v0,0x68
/*  f062030:	8cc20038 */ 	lw	$v0,0x38($a2)
/*  f062034:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f062038:	0325c823 */ 	subu	$t9,$t9,$a1
/*  f06203c:	0062082a */ 	slt	$at,$v1,$v0
/*  f062040:	1420001e */ 	bnez	$at,.L0f0620bc
/*  f062044:	246b0001 */ 	addiu	$t3,$v1,0x1
/*  f062048:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f06204c:	4614603c */ 	c.lt.s	$f12,$f20
/*  f062050:	0325c821 */ 	addu	$t9,$t9,$a1
/*  f062054:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f062058:	00d94021 */ 	addu	$t0,$a2,$t9
/*  f06205c:	ad000040 */ 	sw	$zero,0x40($t0)
/*  f062060:	45000002 */ 	bc1f	.L0f06206c
/*  f062064:	e4cc0034 */ 	swc1	$f12,0x34($a2)
/*  f062068:	e4d40034 */ 	swc1	$f20,0x34($a2)
.L0f06206c:
/*  f06206c:	00001825 */ 	or	$v1,$zero,$zero
/*  f062070:	00c01025 */ 	or	$v0,$a2,$zero
/*  f062074:	24040410 */ 	addiu	$a0,$zero,0x410
.L0f062078:
/*  f062078:	8c490040 */ 	lw	$t1,0x40($v0)
/*  f06207c:	24630068 */ 	addiu	$v1,$v1,0x68
/*  f062080:	1120000a */ 	beqz	$t1,.L0f0620ac
/*  f062084:	00000000 */ 	nop
/*  f062088:	804a0088 */ 	lb	$t2,0x88($v0)
/*  f06208c:	15400007 */ 	bnez	$t2,.L0f0620ac
/*  f062090:	00000000 */ 	nop
/*  f062094:	c444003c */ 	lwc1	$f4,0x3c($v0)
/*  f062098:	4604603c */ 	c.lt.s	$f12,$f4
/*  f06209c:	00000000 */ 	nop
/*  f0620a0:	45000002 */ 	bc1f	.L0f0620ac
/*  f0620a4:	00000000 */ 	nop
/*  f0620a8:	ac400040 */ 	sw	$zero,0x40($v0)
.L0f0620ac:
/*  f0620ac:	1464fff2 */ 	bne	$v1,$a0,.L0f062078
/*  f0620b0:	24420068 */ 	addiu	$v0,$v0,0x68
/*  f0620b4:	1000000a */ 	b	.L0f0620e0
/*  f0620b8:	8fa50070 */ 	lw	$a1,0x70($sp)
.L0f0620bc:
/*  f0620bc:	55620008 */ 	bnel	$t3,$v0,.L0f0620e0
/*  f0620c0:	8fa50070 */ 	lw	$a1,0x70($sp)
/*  f0620c4:	c4c60034 */ 	lwc1	$f6,0x34($a2)
/*  f0620c8:	4606a03c */ 	c.lt.s	$f20,$f6
/*  f0620cc:	00000000 */ 	nop
/*  f0620d0:	45020003 */ 	bc1fl	.L0f0620e0
/*  f0620d4:	8fa50070 */ 	lw	$a1,0x70($sp)
/*  f0620d8:	e4d40034 */ 	swc1	$f20,0x34($a2)
.L0f0620dc:
/*  f0620dc:	8fa50070 */ 	lw	$a1,0x70($sp)
.L0f0620e0:
/*  f0620e0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0620e4:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0620e8:	10a0000e */ 	beqz	$a1,.L0f062124
/*  f0620ec:	24040410 */ 	addiu	$a0,$zero,0x410
.L0f0620f0:
/*  f0620f0:	8c4c0040 */ 	lw	$t4,0x40($v0)
/*  f0620f4:	24630068 */ 	addiu	$v1,$v1,0x68
/*  f0620f8:	11800007 */ 	beqz	$t4,.L0f062118
/*  f0620fc:	00000000 */ 	nop
/*  f062100:	c448003c */ 	lwc1	$f8,0x3c($v0)
/*  f062104:	4608a03c */ 	c.lt.s	$f20,$f8
/*  f062108:	00000000 */ 	nop
/*  f06210c:	45000002 */ 	bc1f	.L0f062118
/*  f062110:	00000000 */ 	nop
/*  f062114:	ac400040 */ 	sw	$zero,0x40($v0)
.L0f062118:
/*  f062118:	1464fff5 */ 	bne	$v1,$a0,.L0f0620f0
/*  f06211c:	24420068 */ 	addiu	$v0,$v0,0x68
/*  f062120:	e4d40034 */ 	swc1	$f20,0x34($a2)
.L0f062124:
/*  f062124:	00001825 */ 	or	$v1,$zero,$zero
/*  f062128:	00c01025 */ 	or	$v0,$a2,$zero
/*  f06212c:	24040410 */ 	addiu	$a0,$zero,0x410
.L0f062130:
/*  f062130:	8c4d0040 */ 	lw	$t5,0x40($v0)
/*  f062134:	24630068 */ 	addiu	$v1,$v1,0x68
/*  f062138:	15a00046 */ 	bnez	$t5,.L0f062254
/*  f06213c:	00000000 */ 	nop
/*  f062140:	8fa30074 */ 	lw	$v1,0x74($sp)
/*  f062144:	8fa40078 */ 	lw	$a0,0x78($sp)
/*  f062148:	e454003c */ 	swc1	$f20,0x3c($v0)
/*  f06214c:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f062150:	ac470044 */ 	sw	$a3,0x44($v0)
/*  f062154:	00404825 */ 	or	$t1,$v0,$zero
/*  f062158:	ac4e0040 */ 	sw	$t6,0x40($v0)
/*  f06215c:	8faf0058 */ 	lw	$t7,0x58($sp)
/*  f062160:	ac4f0048 */ 	sw	$t7,0x48($v0)
/*  f062164:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*  f062168:	27080030 */ 	addiu	$t0,$t8,0x30
.L0f06216c:
/*  f06216c:	8f010000 */ 	lw	$at,0x0($t8)
/*  f062170:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f062174:	2529000c */ 	addiu	$t1,$t1,0xc
/*  f062178:	ad210040 */ 	sw	$at,0x40($t1)
/*  f06217c:	8f01fff8 */ 	lw	$at,-0x8($t8)
/*  f062180:	ad210044 */ 	sw	$at,0x44($t1)
/*  f062184:	8f01fffc */ 	lw	$at,-0x4($t8)
/*  f062188:	1708fff8 */ 	bne	$t8,$t0,.L0f06216c
/*  f06218c:	ad210048 */ 	sw	$at,0x48($t1)
/*  f062190:	8faa0060 */ 	lw	$t2,0x60($sp)
/*  f062194:	ac4a007c */ 	sw	$t2,0x7c($v0)
/*  f062198:	8fab0064 */ 	lw	$t3,0x64($sp)
/*  f06219c:	ac4b0080 */ 	sw	$t3,0x80($v0)
/*  f0621a0:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0621a4:	ac4c0084 */ 	sw	$t4,0x84($v0)
/*  f0621a8:	8fad006c */ 	lw	$t5,0x6c($sp)
/*  f0621ac:	a0450089 */ 	sb	$a1,0x89($v0)
/*  f0621b0:	a04d0088 */ 	sb	$t5,0x88($v0)
/*  f0621b4:	c46a0000 */ 	lwc1	$f10,0x0($v1)
/*  f0621b8:	e44a008c */ 	swc1	$f10,0x8c($v0)
/*  f0621bc:	c4720004 */ 	lwc1	$f18,0x4($v1)
/*  f0621c0:	e4520090 */ 	swc1	$f18,0x90($v0)
/*  f0621c4:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f0621c8:	e4440094 */ 	swc1	$f4,0x94($v0)
/*  f0621cc:	c4820000 */ 	lwc1	$f2,0x0($a0)
/*  f0621d0:	c48e0004 */ 	lwc1	$f14,0x4($a0)
/*  f0621d4:	c4800008 */ 	lwc1	$f0,0x8($a0)
/*  f0621d8:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f0621dc:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0621e0:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*  f0621e4:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0621e8:	46000482 */ 	mul.s	$f18,$f0,$f0
/*  f0621ec:	0c012974 */ 	jal	sqrtf
/*  f0621f0:	460a9300 */ 	add.s	$f12,$f18,$f10
/*  f0621f4:	44808000 */ 	mtc1	$zero,$f16
/*  f0621f8:	8fa20024 */ 	lw	$v0,0x24($sp)
/*  f0621fc:	8fa40078 */ 	lw	$a0,0x78($sp)
/*  f062200:	4600803c */ 	c.lt.s	$f16,$f0
/*  f062204:	3c013f80 */ 	lui	$at,0x3f80
/*  f062208:	2443003c */ 	addiu	$v1,$v0,0x3c
/*  f06220c:	4502000d */ 	bc1fl	.L0f062244
/*  f062210:	44813000 */ 	mtc1	$at,$f6
/*  f062214:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f062218:	2443003c */ 	addiu	$v1,$v0,0x3c
/*  f06221c:	46002183 */ 	div.s	$f6,$f4,$f0
/*  f062220:	e466005c */ 	swc1	$f6,0x5c($v1)
/*  f062224:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f062228:	46004483 */ 	div.s	$f18,$f8,$f0
/*  f06222c:	e4720060 */ 	swc1	$f18,0x60($v1)
/*  f062230:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f062234:	46005103 */ 	div.s	$f4,$f10,$f0
/*  f062238:	10000008 */ 	b	.L0f06225c
/*  f06223c:	e4640064 */ 	swc1	$f4,0x64($v1)
/*  f062240:	44813000 */ 	mtc1	$at,$f6
.L0f062244:
/*  f062244:	e470005c */ 	swc1	$f16,0x5c($v1)
/*  f062248:	e4700060 */ 	swc1	$f16,0x60($v1)
/*  f06224c:	10000003 */ 	b	.L0f06225c
/*  f062250:	e4660064 */ 	swc1	$f6,0x64($v1)
.L0f062254:
/*  f062254:	1464ffb6 */ 	bne	$v1,$a0,.L0f062130
/*  f062258:	24420068 */ 	addiu	$v0,$v0,0x68
.L0f06225c:
/*  f06225c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f062260:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f062264:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f062268:	03e00008 */ 	jr	$ra
/*  f06226c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f062270
.late_rodata
glabel var7f1a9ec4
.word 0x3e2aaaab
.text
/*  f062270:	27bdfec8 */ 	addiu	$sp,$sp,-312
/*  f062274:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f062278:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f06227c:	8c6e0284 */ 	lw	$t6,0x284($v1)
/*  f062280:	8c62034c */ 	lw	$v0,0x34c($v1)
/*  f062284:	8c780348 */ 	lw	$t8,0x348($v1)
/*  f062288:	afbf0084 */ 	sw	$ra,0x84($sp)
/*  f06228c:	afbe0080 */ 	sw	$s8,0x80($sp)
/*  f062290:	afb7007c */ 	sw	$s7,0x7c($sp)
/*  f062294:	afb60078 */ 	sw	$s6,0x78($sp)
/*  f062298:	afb50074 */ 	sw	$s5,0x74($sp)
/*  f06229c:	afb40070 */ 	sw	$s4,0x70($sp)
/*  f0622a0:	afb3006c */ 	sw	$s3,0x6c($sp)
/*  f0622a4:	afb20068 */ 	sw	$s2,0x68($sp)
/*  f0622a8:	afb10064 */ 	sw	$s1,0x64($sp)
/*  f0622ac:	afb00060 */ 	sw	$s0,0x60($sp)
/*  f0622b0:	f7bc0058 */ 	sdc1	$f28,0x58($sp)
/*  f0622b4:	f7ba0050 */ 	sdc1	$f26,0x50($sp)
/*  f0622b8:	f7b80048 */ 	sdc1	$f24,0x48($sp)
/*  f0622bc:	f7b60040 */ 	sdc1	$f22,0x40($sp)
/*  f0622c0:	f7b40038 */ 	sdc1	$f20,0x38($sp)
/*  f0622c4:	afa40138 */ 	sw	$a0,0x138($sp)
/*  f0622c8:	afa60140 */ 	sw	$a2,0x140($sp)
/*  f0622cc:	8dcf00bc */ 	lw	$t7,0xbc($t6)
/*  f0622d0:	2442fffc */ 	addiu	$v0,$v0,-4
/*  f0622d4:	0058082b */ 	sltu	$at,$v0,$t8
/*  f0622d8:	00a0b825 */ 	or	$s7,$a1,$zero
/*  f0622dc:	afa00128 */ 	sw	$zero,0x128($sp)
/*  f0622e0:	14200109 */ 	bnez	$at,.L0f062708
/*  f0622e4:	afaf012c */ 	sw	$t7,0x12c($sp)
/*  f0622e8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0622ec:	4481d000 */ 	mtc1	$at,$f26
/*  f0622f0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0622f4:	4481c000 */ 	mtc1	$at,$f24
/*  f0622f8:	4480e000 */ 	mtc1	$zero,$f28
/*  f0622fc:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f062300:	27be00ac */ 	addiu	$s8,$sp,0xac
/*  f062304:	8fb90130 */ 	lw	$t9,0x130($sp)
.L0f062308:
/*  f062308:	3c0143fa */ 	lui	$at,0x43fa
/*  f06230c:	8f330000 */ 	lw	$s3,0x0($t9)
/*  f062310:	526000f4 */ 	beqzl	$s3,.L0f0626e4
/*  f062314:	8fb90130 */ 	lw	$t9,0x130($sp)
/*  f062318:	c6640014 */ 	lwc1	$f4,0x14($s3)
/*  f06231c:	44813000 */ 	mtc1	$at,$f6
/*  f062320:	8fa90140 */ 	lw	$t1,0x140($sp)
/*  f062324:	4606203c */ 	c.lt.s	$f4,$f6
/*  f062328:	00000000 */ 	nop
/*  f06232c:	450200ed */ 	bc1fl	.L0f0626e4
/*  f062330:	8fb90130 */ 	lw	$t9,0x130($sp)
/*  f062334:	8e640004 */ 	lw	$a0,0x4($s3)
/*  f062338:	0000a025 */ 	or	$s4,$zero,$zero
/*  f06233c:	1080000d */ 	beqz	$a0,.L0f062374
/*  f062340:	0080b025 */ 	or	$s6,$a0,$zero
/*  f062344:	92e80000 */ 	lbu	$t0,0x0($s7)
/*  f062348:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f06234c:	11010009 */ 	beq	$t0,$at,.L0f062374
/*  f062350:	00000000 */ 	nop
/*  f062354:	92c30003 */ 	lbu	$v1,0x3($s6)
/*  f062358:	3862002a */ 	xori	$v0,$v1,0x2a
/*  f06235c:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f062360:	54400004 */ 	bnezl	$v0,.L0f062374
/*  f062364:	0040a025 */ 	or	$s4,$v0,$zero
/*  f062368:	3862002f */ 	xori	$v0,$v1,0x2f
/*  f06236c:	2c420001 */ 	sltiu	$v0,$v0,0x1
/*  f062370:	0040a025 */ 	or	$s4,$v0,$zero
.L0f062374:
/*  f062374:	51200003 */ 	beqzl	$t1,.L0f062384
/*  f062378:	92620000 */ 	lbu	$v0,0x0($s3)
/*  f06237c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f062380:	92620000 */ 	lbu	$v0,0x0($s3)
.L0f062384:
/*  f062384:	24010003 */ 	addiu	$at,$zero,0x3
/*  f062388:	1041000c */ 	beq	$v0,$at,.L0f0623bc
/*  f06238c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f062390:	14410009 */ 	bne	$v0,$at,.L0f0623b8
/*  f062394:	00000000 */ 	nop
/*  f062398:	10800007 */ 	beqz	$a0,.L0f0623b8
/*  f06239c:	00000000 */ 	nop
/*  f0623a0:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f0623a4:	02602025 */ 	or	$a0,$s3,$zero
/*  f0623a8:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x28c)
/*  f0623ac:	8d4aa24c */ 	lw	$t2,%lo(g_Vars+0x28c)($t2)
/*  f0623b0:	544a0003 */ 	bnel	$v0,$t2,.L0f0623c0
/*  f0623b4:	3c014270 */ 	lui	$at,0x4270
.L0f0623b8:
/*  f0623b8:	128000c9 */ 	beqz	$s4,.L0f0626e0
.L0f0623bc:
/*  f0623bc:	3c014270 */ 	lui	$at,0x4270
.L0f0623c0:
/*  f0623c0:	4481b000 */ 	mtc1	$at,$f22
/*  f0623c4:	8e710004 */ 	lw	$s1,0x4($s3)
/*  f0623c8:	0fc2c41f */ 	jal	handGetWeaponFunction
/*  f0623cc:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0623d0:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f0623d4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0623d8:	27a40108 */ 	addiu	$a0,$sp,0x108
/*  f0623dc:	316c00ff */ 	andi	$t4,$t3,0xff
/*  f0623e0:	15810002 */ 	bne	$t4,$at,.L0f0623ec
/*  f0623e4:	00000000 */ 	nop
/*  f0623e8:	c4560018 */ 	lwc1	$f22,0x18($v0)
.L0f0623ec:
/*  f0623ec:	0fc282fb */ 	jal	currentPlayerGetCrossPos
/*  f0623f0:	27a50104 */ 	addiu	$a1,$sp,0x104
/*  f0623f4:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f0623f8:	00000000 */ 	nop
/*  f0623fc:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f062400:	46000506 */ 	mov.s	$f20,$f0
/*  f062404:	46180402 */ 	mul.s	$f16,$f0,$f24
/*  f062408:	c7a80108 */ 	lwc1	$f8,0x108($sp)
/*  f06240c:	46144281 */ 	sub.s	$f10,$f8,$f20
/*  f062410:	46105483 */ 	div.s	$f18,$f10,$f16
/*  f062414:	461a9101 */ 	sub.s	$f4,$f18,$f26
/*  f062418:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f06241c:	e7a400fc */ 	swc1	$f4,0xfc($sp)
/*  f062420:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f062424:	46000506 */ 	mov.s	$f20,$f0
/*  f062428:	46180282 */ 	mul.s	$f10,$f0,$f24
/*  f06242c:	c7a60104 */ 	lwc1	$f6,0x104($sp)
/*  f062430:	46143201 */ 	sub.s	$f8,$f6,$f20
/*  f062434:	460a4403 */ 	div.s	$f16,$f8,$f10
/*  f062438:	461a8481 */ 	sub.s	$f18,$f16,$f26
/*  f06243c:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f062440:	e7b20100 */ 	swc1	$f18,0x100($sp)
/*  f062444:	3c017f1b */ 	lui	$at,%hi(var7f1a9ec4)
/*  f062448:	c4249ec4 */ 	lwc1	$f4,%lo(var7f1a9ec4)($at)
/*  f06244c:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f062450:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f062454:	e7a600f4 */ 	swc1	$f6,0xf4($sp)
/*  f062458:	3c013e00 */ 	lui	$at,0x3e00
/*  f06245c:	44814000 */ 	mtc1	$at,$f8
/*  f062460:	27a50114 */ 	addiu	$a1,$sp,0x114
/*  f062464:	27a60110 */ 	addiu	$a2,$sp,0x110
/*  f062468:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f06246c:	27a700fc */ 	addiu	$a3,$sp,0xfc
/*  f062470:	27ad00f4 */ 	addiu	$t5,$sp,0xf4
/*  f062474:	12800003 */ 	beqz	$s4,.L0f062484
/*  f062478:	e7aa00f8 */ 	swc1	$f10,0xf8($sp)
/*  f06247c:	10000002 */ 	b	.L0f062488
/*  f062480:	8ec40018 */ 	lw	$a0,0x18($s6)
.L0f062484:
/*  f062484:	8e240020 */ 	lw	$a0,0x20($s1)
.L0f062488:
/*  f062488:	0fc19e6b */ 	jal	func0f0679ac
/*  f06248c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f062490:	10400093 */ 	beqz	$v0,.L0f0626e0
/*  f062494:	c7b00110 */ 	lwc1	$f16,0x110($sp)
/*  f062498:	461c803e */ 	c.le.s	$f16,$f28
/*  f06249c:	c7b20114 */ 	lwc1	$f18,0x114($sp)
/*  f0624a0:	45020090 */ 	bc1fl	.L0f0626e4
/*  f0624a4:	8fb90130 */ 	lw	$t9,0x130($sp)
/*  f0624a8:	4600b107 */ 	neg.s	$f4,$f22
/*  f0624ac:	8fa2012c */ 	lw	$v0,0x12c($sp)
/*  f0624b0:	4612203e */ 	c.le.s	$f4,$f18
/*  f0624b4:	24070033 */ 	addiu	$a3,$zero,0x33
/*  f0624b8:	24550008 */ 	addiu	$s5,$v0,0x8
/*  f0624bc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0624c0:	45000087 */ 	bc1f	.L0f0626e0
/*  f0624c4:	26700008 */ 	addiu	$s0,$s3,0x8
/*  f0624c8:	12800002 */ 	beqz	$s4,.L0f0624d4
/*  f0624cc:	24520028 */ 	addiu	$s2,$v0,0x28
/*  f0624d0:	00003825 */ 	or	$a3,$zero,$zero
.L0f0624d4:
/*  f0624d4:	02402825 */ 	or	$a1,$s2,$zero
/*  f0624d8:	0c00b706 */ 	jal	func0002dc18
/*  f0624dc:	02003025 */ 	or	$a2,$s0,$zero
/*  f0624e0:	50400080 */ 	beqzl	$v0,.L0f0626e4
/*  f0624e4:	8fb90130 */ 	lw	$t9,0x130($sp)
/*  f0624e8:	12800027 */ 	beqz	$s4,.L0f062588
/*  f0624ec:	8fb90140 */ 	lw	$t9,0x140($sp)
/*  f0624f0:	8ece0018 */ 	lw	$t6,0x18($s6)
/*  f0624f4:	afa000c8 */ 	sw	$zero,0xc8($sp)
/*  f0624f8:	27a400d8 */ 	addiu	$a0,$sp,0xd8
/*  f0624fc:	27a500cc */ 	addiu	$a1,$sp,0xcc
/*  f062500:	8fa60138 */ 	lw	$a2,0x138($sp)
/*  f062504:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f062508:	0fc2832c */ 	jal	func0f0a0cb0
/*  f06250c:	afae00e4 */ 	sw	$t6,0xe4($sp)
/*  f062510:	8fa400e4 */ 	lw	$a0,0xe4($sp)
/*  f062514:	27a500d8 */ 	addiu	$a1,$sp,0xd8
/*  f062518:	27a600cc */ 	addiu	$a2,$sp,0xcc
/*  f06251c:	0c008975 */ 	jal	func000225d4
/*  f062520:	27a700c8 */ 	addiu	$a3,$sp,0xc8
/*  f062524:	1840006e */ 	blez	$v0,.L0f0626e0
/*  f062528:	02e02025 */ 	or	$a0,$s7,$zero
/*  f06252c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f062530:	0fc2c74a */ 	jal	func0f0b1d28
/*  f062534:	afaf0128 */ 	sw	$t7,0x128($sp)
/*  f062538:	3c014020 */ 	lui	$at,0x4020
/*  f06253c:	44813000 */ 	mtc1	$at,$f6
/*  f062540:	02a02025 */ 	or	$a0,$s5,$zero
/*  f062544:	02402825 */ 	or	$a1,$s2,$zero
/*  f062548:	46060502 */ 	mul.s	$f20,$f0,$f6
/*  f06254c:	0fc2a101 */ 	jal	func0f0a8404
/*  f062550:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f062554:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x28c)
/*  f062558:	8f18a24c */ 	lw	$t8,%lo(g_Vars+0x28c)($t8)
/*  f06255c:	4405a000 */ 	mfc1	$a1,$f20
/*  f062560:	92e70000 */ 	lbu	$a3,0x0($s7)
/*  f062564:	02c02025 */ 	or	$a0,$s6,$zero
/*  f062568:	02003025 */ 	or	$a2,$s0,$zero
/*  f06256c:	0fc2149c */ 	jal	func0f085270
/*  f062570:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f062574:	02602025 */ 	or	$a0,$s3,$zero
/*  f062578:	0fc1c1a6 */ 	jal	func0f070698
/*  f06257c:	00002825 */ 	or	$a1,$zero,$zero
/*  f062580:	10000058 */ 	b	.L0f0626e4
/*  f062584:	8fb90130 */ 	lw	$t9,0x130($sp)
.L0f062588:
/*  f062588:	13200006 */ 	beqz	$t9,.L0f0625a4
/*  f06258c:	240affff */ 	addiu	$t2,$zero,-1
/*  f062590:	8e280018 */ 	lw	$t0,0x18($s1)
/*  f062594:	3c011000 */ 	lui	$at,0x1000
/*  f062598:	01014825 */ 	or	$t1,$t0,$at
/*  f06259c:	10000050 */ 	b	.L0f0626e0
/*  f0625a0:	ae290018 */ 	sw	$t1,0x18($s1)
.L0f0625a4:
/*  f0625a4:	240b000f */ 	addiu	$t3,$zero,0xf
/*  f0625a8:	afa000a8 */ 	sw	$zero,0xa8($sp)
/*  f0625ac:	afa000a4 */ 	sw	$zero,0xa4($sp)
/*  f0625b0:	afaa00a0 */ 	sw	$t2,0xa0($sp)
/*  f0625b4:	afab009c */ 	sw	$t3,0x9c($sp)
/*  f0625b8:	0fc13513 */ 	jal	chrIsAvoiding
/*  f0625bc:	02202025 */ 	or	$a0,$s1,$zero
/*  f0625c0:	14400047 */ 	bnez	$v0,.L0f0626e0
/*  f0625c4:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f0625c8:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0625cc:	afac0128 */ 	sw	$t4,0x128($sp)
/*  f0625d0:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0625d4:	8fa60138 */ 	lw	$a2,0x138($sp)
/*  f0625d8:	0fc2832c */ 	jal	func0f0a0cb0
/*  f0625dc:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0625e0:	0fc2d5de */ 	jal	currentPlayerGetUnk174c
/*  f0625e4:	00000000 */ 	nop
/*  f0625e8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0625ec:	0c0056c4 */ 	jal	func00015b10
/*  f0625f0:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0625f4:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0625f8:	02602825 */ 	or	$a1,$s3,$zero
/*  f0625fc:	0fc29f66 */ 	jal	func0f0a7d98
/*  f062600:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f062604:	8e2d0020 */ 	lw	$t5,0x20($s1)
/*  f062608:	11a00010 */ 	beqz	$t5,.L0f06264c
/*  f06260c:	00000000 */ 	nop
/*  f062610:	0fc0cfe8 */ 	jal	chrGetShield
/*  f062614:	02202025 */ 	or	$a0,$s1,$zero
/*  f062618:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f06261c:	02202025 */ 	or	$a0,$s1,$zero
/*  f062620:	02a02825 */ 	or	$a1,$s5,$zero
/*  f062624:	03c03025 */ 	or	$a2,$s8,$zero
/*  f062628:	45000008 */ 	bc1f	.L0f06264c
/*  f06262c:	27a700a8 */ 	addiu	$a3,$sp,0xa8
/*  f062630:	27ae009c */ 	addiu	$t6,$sp,0x9c
/*  f062634:	27af00a4 */ 	addiu	$t7,$sp,0xa4
/*  f062638:	27b800a0 */ 	addiu	$t8,$sp,0xa0
/*  f06263c:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f062640:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f062644:	0fc0ffcb */ 	jal	func0f03ff2c
/*  f062648:	afae0010 */ 	sw	$t6,0x10($sp)
.L0f06264c:
/*  f06264c:	0fc331a0 */ 	jal	currentPlayerGetCrouchPos
/*  f062650:	00000000 */ 	nop
/*  f062654:	24010001 */ 	addiu	$at,$zero,0x1
/*  f062658:	14410003 */ 	bne	$v0,$at,.L0f062668
/*  f06265c:	241900c8 */ 	addiu	$t9,$zero,0xc8
/*  f062660:	10000009 */ 	b	.L0f062688
/*  f062664:	afb9009c */ 	sw	$t9,0x9c($sp)
.L0f062668:
/*  f062668:	0fc331a0 */ 	jal	currentPlayerGetCrouchPos
/*  f06266c:	00000000 */ 	nop
/*  f062670:	14400004 */ 	bnez	$v0,.L0f062684
/*  f062674:	2409000f */ 	addiu	$t1,$zero,0xf
/*  f062678:	240800c9 */ 	addiu	$t0,$zero,0xc9
/*  f06267c:	10000002 */ 	b	.L0f062688
/*  f062680:	afa8009c */ 	sw	$t0,0x9c($sp)
.L0f062684:
/*  f062684:	afa9009c */ 	sw	$t1,0x9c($sp)
.L0f062688:
/*  f062688:	0fc2c74a */ 	jal	func0f0b1d28
/*  f06268c:	02e02025 */ 	or	$a0,$s7,$zero
/*  f062690:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x284)
/*  f062694:	8d4aa244 */ 	lw	$t2,%lo(g_Vars+0x284)($t2)
/*  f062698:	8fac009c */ 	lw	$t4,0x9c($sp)
/*  f06269c:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f0626a0:	8d4b00bc */ 	lw	$t3,0xbc($t2)
/*  f0626a4:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0626a8:	8faf00a4 */ 	lw	$t7,0xa4($sp)
/*  f0626ac:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0626b0:	8e2d001c */ 	lw	$t5,0x1c($s1)
/*  f0626b4:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*  f0626b8:	44050000 */ 	mfc1	$a1,$f0
/*  f0626bc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0626c0:	02202025 */ 	or	$a0,$s1,$zero
/*  f0626c4:	03c03025 */ 	or	$a2,$s8,$zero
/*  f0626c8:	02e03825 */ 	or	$a3,$s7,$zero
/*  f0626cc:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0626d0:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0626d4:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0626d8:	0fc0d077 */ 	jal	func0f0341dc
/*  f0626dc:	afb80024 */ 	sw	$t8,0x24($sp)
.L0f0626e0:
/*  f0626e0:	8fb90130 */ 	lw	$t9,0x130($sp)
.L0f0626e4:
/*  f0626e4:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x348)
/*  f0626e8:	8d29a308 */ 	lw	$t1,%lo(g_Vars+0x348)($t1)
/*  f0626ec:	2728fffc */ 	addiu	$t0,$t9,-4
/*  f0626f0:	afa80130 */ 	sw	$t0,0x130($sp)
/*  f0626f4:	0109082b */ 	sltu	$at,$t0,$t1
/*  f0626f8:	5020ff03 */ 	beqzl	$at,.L0f062308
/*  f0626fc:	8fb90130 */ 	lw	$t9,0x130($sp)
/*  f062700:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f062704:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
.L0f062708:
/*  f062708:	8faa0128 */ 	lw	$t2,0x128($sp)
/*  f06270c:	8fab0140 */ 	lw	$t3,0x140($sp)
/*  f062710:	55400010 */ 	bnezl	$t2,.L0f062754
/*  f062714:	8fbf0084 */ 	lw	$ra,0x84($sp)
/*  f062718:	1560000d */ 	bnez	$t3,.L0f062750
/*  f06271c:	8fad0138 */ 	lw	$t5,0x138($sp)
/*  f062720:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f062724:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f062728:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f06272c:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f062730:	8c6c0284 */ 	lw	$t4,0x284($v1)
/*  f062734:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f062738:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f06273c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f062740:	018e1021 */ 	addu	$v0,$t4,$t6
/*  f062744:	90580d0f */ 	lbu	$t8,0xd0f($v0)
/*  f062748:	37190020 */ 	ori	$t9,$t8,0x20
/*  f06274c:	a0590d0f */ 	sb	$t9,0xd0f($v0)
.L0f062750:
/*  f062750:	8fbf0084 */ 	lw	$ra,0x84($sp)
.L0f062754:
/*  f062754:	d7b40038 */ 	ldc1	$f20,0x38($sp)
/*  f062758:	d7b60040 */ 	ldc1	$f22,0x40($sp)
/*  f06275c:	d7b80048 */ 	ldc1	$f24,0x48($sp)
/*  f062760:	d7ba0050 */ 	ldc1	$f26,0x50($sp)
/*  f062764:	d7bc0058 */ 	ldc1	$f28,0x58($sp)
/*  f062768:	8fb00060 */ 	lw	$s0,0x60($sp)
/*  f06276c:	8fb10064 */ 	lw	$s1,0x64($sp)
/*  f062770:	8fb20068 */ 	lw	$s2,0x68($sp)
/*  f062774:	8fb3006c */ 	lw	$s3,0x6c($sp)
/*  f062778:	8fb40070 */ 	lw	$s4,0x70($sp)
/*  f06277c:	8fb50074 */ 	lw	$s5,0x74($sp)
/*  f062780:	8fb60078 */ 	lw	$s6,0x78($sp)
/*  f062784:	8fb7007c */ 	lw	$s7,0x7c($sp)
/*  f062788:	8fbe0080 */ 	lw	$s8,0x80($sp)
/*  f06278c:	03e00008 */ 	jr	$ra
/*  f062790:	27bd0138 */ 	addiu	$sp,$sp,0x138
);

GLOBAL_ASM(
glabel func0f062794
.late_rodata
glabel var7f1a9ec8
.word func0f062794+0x144 # f0628d8
glabel var7f1a9ecc
.word func0f062794+0x2f4 # f062a88
glabel var7f1a9ed0
.word func0f062794+0x338 # f062acc
glabel var7f1a9ed4
.word func0f062794+0x26c # f062a00
glabel var7f1a9ed8
.word func0f062794+0x2b0 # f062a44
glabel var7f1a9edc
.word func0f062794+0x2d4 # f062a68
glabel var7f1a9ee0
.word func0f062794+0x2e4 # f062a78
glabel var7f1a9ee4
.word func0f062794+0x304 # f062a98
glabel var7f1a9ee8
.word func0f062794+0x34c # f062ae0
glabel var7f1a9eec
.word func0f062794+0x298 # f062a2c
glabel var7f1a9ef0
.word func0f062794+0x384 # f062b18
glabel var7f1a9ef4
.word func0f062794+0x2c4 # f062a58
.text
/*  f062794:	00047100 */ 	sll	$t6,$a0,0x4
/*  f062798:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f06279c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0627a0:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f0627a4:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0627a8:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x284)
/*  f0627ac:	8defa244 */ 	lw	$t7,%lo(g_Vars+0x284)($t7)
/*  f0627b0:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0627b4:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f0627b8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0627bc:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0627c0:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0627c4:	afae002c */ 	sw	$t6,0x2c($sp)
/*  f0627c8:	01eec821 */ 	addu	$t9,$t7,$t6
/*  f0627cc:	8f280d0c */ 	lw	$t0,0xd0c($t9)
/*  f0627d0:	00808025 */ 	or	$s0,$a0,$zero
/*  f0627d4:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0627d8:	00085680 */ 	sll	$t2,$t0,0x1a
/*  f0627dc:	0541001e */ 	bgez	$t2,.L0f062858
/*  f0627e0:	00000000 */ 	nop
/*  f0627e4:	0fc2866a */ 	jal	handGetWeaponNum
/*  f0627e8:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0627ec:	24010014 */ 	addiu	$at,$zero,0x14
/*  f0627f0:	1441000d */ 	bne	$v0,$at,.L0f062828
/*  f0627f4:	8fa30044 */ 	lw	$v1,0x44($sp)
/*  f0627f8:	3c0b800a */ 	lui	$t3,%hi(g_Vars+0x284)
/*  f0627fc:	8d6ba244 */ 	lw	$t3,%lo(g_Vars+0x284)($t3)
/*  f062800:	8fac002c */ 	lw	$t4,0x2c($sp)
/*  f062804:	24010003 */ 	addiu	$at,$zero,0x3
/*  f062808:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f06280c:	8dae0b90 */ 	lw	$t6,0xb90($t5)
/*  f062810:	01c1001a */ 	div	$zero,$t6,$at
/*  f062814:	00007810 */ 	mfhi	$t7
/*  f062818:	24010001 */ 	addiu	$at,$zero,0x1
/*  f06281c:	11e10002 */ 	beq	$t7,$at,.L0f062828
/*  f062820:	00000000 */ 	nop
/*  f062824:	00001825 */ 	or	$v1,$zero,$zero
.L0f062828:
/*  f062828:	10600004 */ 	beqz	$v1,.L0f06283c
/*  f06282c:	02002025 */ 	or	$a0,$s0,$zero
/*  f062830:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f062834:	0fc18755 */ 	jal	func0f061d54
/*  f062838:	24060002 */ 	addiu	$a2,$zero,0x2
.L0f06283c:
/*  f06283c:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x284)
/*  f062840:	8f18a244 */ 	lw	$t8,%lo(g_Vars+0x284)($t8)
/*  f062844:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*  f062848:	03191821 */ 	addu	$v1,$t8,$t9
/*  f06284c:	90680d0f */ 	lbu	$t0,0xd0f($v1)
/*  f062850:	3109ffdf */ 	andi	$t1,$t0,0xffdf
/*  f062854:	a0690d0f */ 	sb	$t1,0xd0f($v1)
.L0f062858:
/*  f062858:	0fc2883f */ 	jal	func0f0a20fc
/*  f06285c:	02002025 */ 	or	$a0,$s0,$zero
/*  f062860:	504000ae */ 	beqzl	$v0,.L0f062b1c
/*  f062864:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f062868:	0fc2884b */ 	jal	func0f0a212c
/*  f06286c:	02002025 */ 	or	$a0,$s0,$zero
/*  f062870:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f062874:	0fc2866a */ 	jal	handGetWeaponNum
/*  f062878:	02002025 */ 	or	$a0,$s0,$zero
/*  f06287c:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x284)
/*  f062880:	8d4aa244 */ 	lw	$t2,%lo(g_Vars+0x284)($t2)
/*  f062884:	8fab002c */ 	lw	$t3,0x2c($sp)
/*  f062888:	afa2003c */ 	sw	$v0,0x3c($sp)
/*  f06288c:	02002025 */ 	or	$a0,$s0,$zero
/*  f062890:	014b1821 */ 	addu	$v1,$t2,$t3
/*  f062894:	906c0d0f */ 	lbu	$t4,0xd0f($v1)
/*  f062898:	27a50038 */ 	addiu	$a1,$sp,0x38
/*  f06289c:	318dffef */ 	andi	$t5,$t4,0xffef
/*  f0628a0:	0fc2c6bc */ 	jal	func0f0b1af0
/*  f0628a4:	a06d0d0f */ 	sb	$t5,0xd0f($v1)
/*  f0628a8:	0fc683f2 */ 	jal	frIncrementNumShots
/*  f0628ac:	00000000 */ 	nop
/*  f0628b0:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f0628b4:	25cfffff */ 	addiu	$t7,$t6,-1
/*  f0628b8:	2de1000c */ 	sltiu	$at,$t7,0xc
/*  f0628bc:	10200096 */ 	beqz	$at,.L0f062b18
/*  f0628c0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0628c4:	3c017f1b */ 	lui	$at,%hi(var7f1a9ec8)
/*  f0628c8:	002f0821 */ 	addu	$at,$at,$t7
/*  f0628cc:	8c2f9ec8 */ 	lw	$t7,%lo(var7f1a9ec8)($at)
/*  f0628d0:	01e00008 */ 	jr	$t7
/*  f0628d4:	00000000 */ 	nop
/*  f0628d8:	12000004 */ 	beqz	$s0,.L0f0628ec
/*  f0628dc:	00000000 */ 	nop
/*  f0628e0:	0fc2883f */ 	jal	func0f0a20fc
/*  f0628e4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0628e8:	1440008b */ 	bnez	$v0,.L0f062b18
.L0f0628ec:
/*  f0628ec:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x284)
/*  f0628f0:	8f18a244 */ 	lw	$t8,%lo(g_Vars+0x284)($t8)
/*  f0628f4:	8f1900bc */ 	lw	$t9,0xbc($t8)
/*  f0628f8:	0fc0897d */ 	jal	chrUncloakTemporarily
/*  f0628fc:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f062900:	27a40038 */ 	addiu	$a0,$sp,0x38
/*  f062904:	0fc2c11b */ 	jal	func0f0b046c
/*  f062908:	00002825 */ 	or	$a1,$zero,$zero
/*  f06290c:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*  f062910:	24010013 */ 	addiu	$at,$zero,0x13
/*  f062914:	02002025 */ 	or	$a0,$s0,$zero
/*  f062918:	1501002b */ 	bne	$t0,$at,.L0f0629c8
/*  f06291c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f062920:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f062924:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f062928:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f06292c:	0fc187b5 */ 	jal	func0f061ed4
/*  f062930:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f062934:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f062938:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f06293c:	02002025 */ 	or	$a0,$s0,$zero
/*  f062940:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f062944:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f062948:	0fc187b5 */ 	jal	func0f061ed4
/*  f06294c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f062950:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f062954:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f062958:	02002025 */ 	or	$a0,$s0,$zero
/*  f06295c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f062960:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f062964:	0fc187b5 */ 	jal	func0f061ed4
/*  f062968:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f06296c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f062970:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f062974:	02002025 */ 	or	$a0,$s0,$zero
/*  f062978:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f06297c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f062980:	0fc187b5 */ 	jal	func0f061ed4
/*  f062984:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f062988:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f06298c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f062990:	02002025 */ 	or	$a0,$s0,$zero
/*  f062994:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f062998:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f06299c:	0fc187b5 */ 	jal	func0f061ed4
/*  f0629a0:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0629a4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0629a8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0629ac:	02002025 */ 	or	$a0,$s0,$zero
/*  f0629b0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0629b4:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0629b8:	0fc187b5 */ 	jal	func0f061ed4
/*  f0629bc:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0629c0:	1000000b */ 	b	.L0f0629f0
/*  f0629c4:	00000000 */ 	nop
.L0f0629c8:
/*  f0629c8:	0fc284c6 */ 	jal	func0f0a1318
/*  f0629cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0629d0:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x314)
/*  f0629d4:	8defa2d4 */ 	lw	$t7,%lo(g_Vars+0x314)($t7)
/*  f0629d8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0629dc:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0629e0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0629e4:	00403825 */ 	or	$a3,$v0,$zero
/*  f0629e8:	0fc187b5 */ 	jal	func0f061ed4
/*  f0629ec:	afaf0010 */ 	sw	$t7,0x10($sp)
.L0f0629f0:
/*  f0629f0:	0fc2c148 */ 	jal	func0f0b0520
/*  f0629f4:	00000000 */ 	nop
/*  f0629f8:	10000048 */ 	b	.L0f062b1c
/*  f0629fc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f062a00:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x284)
/*  f062a04:	8f18a244 */ 	lw	$t8,%lo(g_Vars+0x284)($t8)
/*  f062a08:	8f1900bc */ 	lw	$t9,0xbc($t8)
/*  f062a0c:	0fc0897d */ 	jal	chrUncloakTemporarily
/*  f062a10:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f062a14:	02002025 */ 	or	$a0,$s0,$zero
/*  f062a18:	27a50038 */ 	addiu	$a1,$sp,0x38
/*  f062a1c:	0fc1889c */ 	jal	func0f062270
/*  f062a20:	00003025 */ 	or	$a2,$zero,$zero
/*  f062a24:	1000003d */ 	b	.L0f062b1c
/*  f062a28:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f062a2c:	02002025 */ 	or	$a0,$s0,$zero
/*  f062a30:	27a50038 */ 	addiu	$a1,$sp,0x38
/*  f062a34:	0fc1889c */ 	jal	func0f062270
/*  f062a38:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f062a3c:	10000037 */ 	b	.L0f062b1c
/*  f062a40:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f062a44:	3c04800a */ 	lui	$a0,%hi(g_Vars+0x28c)
/*  f062a48:	0fc22a7d */ 	jal	playerActivateRemoteMineDetonator
/*  f062a4c:	8c84a24c */ 	lw	$a0,%lo(g_Vars+0x28c)($a0)
/*  f062a50:	10000032 */ 	b	.L0f062b1c
/*  f062a54:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f062a58:	0fc18b74 */ 	jal	func0f062dd0
/*  f062a5c:	00000000 */ 	nop
/*  f062a60:	1000002e */ 	b	.L0f062b1c
/*  f062a64:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f062a68:	0fc2aeea */ 	jal	func0f0abba8
/*  f062a6c:	00000000 */ 	nop
/*  f062a70:	1000002a */ 	b	.L0f062b1c
/*  f062a74:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f062a78:	0fc2aefa */ 	jal	func0f0abbe8
/*  f062a7c:	00000000 */ 	nop
/*  f062a80:	10000026 */ 	b	.L0f062b1c
/*  f062a84:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f062a88:	0fc27ea1 */ 	jal	func0f09fa84
/*  f062a8c:	02002025 */ 	or	$a0,$s0,$zero
/*  f062a90:	10000022 */ 	b	.L0f062b1c
/*  f062a94:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f062a98:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x284)
/*  f062a9c:	8d08a244 */ 	lw	$t0,%lo(g_Vars+0x284)($t0)
/*  f062aa0:	8d0900ac */ 	lw	$t1,0xac($t0)
/*  f062aa4:	15200005 */ 	bnez	$t1,.L0f062abc
/*  f062aa8:	00000000 */ 	nop
/*  f062aac:	0fc30ebd */ 	jal	currentPlayerAdjustCrouchPos
/*  f062ab0:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f062ab4:	10000019 */ 	b	.L0f062b1c
/*  f062ab8:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f062abc:
/*  f062abc:	0fc30ebd */ 	jal	currentPlayerAdjustCrouchPos
/*  f062ac0:	2404fffe */ 	addiu	$a0,$zero,-2
/*  f062ac4:	10000015 */ 	b	.L0f062b1c
/*  f062ac8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f062acc:	02002025 */ 	or	$a0,$s0,$zero
/*  f062ad0:	0fc27c40 */ 	jal	func0f09f100
/*  f062ad4:	27a50038 */ 	addiu	$a1,$sp,0x38
/*  f062ad8:	10000010 */ 	b	.L0f062b1c
/*  f062adc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f062ae0:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f062ae4:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f062ae8:	2401ffbf */ 	addiu	$at,$zero,-65
/*  f062aec:	8c4400c4 */ 	lw	$a0,0xc4($v0)
/*  f062af0:	30830080 */ 	andi	$v1,$a0,0x80
/*  f062af4:	0003502b */ 	sltu	$t2,$zero,$v1
/*  f062af8:	11400005 */ 	beqz	$t2,.L0f062b10
/*  f062afc:	00816024 */ 	and	$t4,$a0,$at
/*  f062b00:	2401ff7f */ 	addiu	$at,$zero,-129
/*  f062b04:	00815824 */ 	and	$t3,$a0,$at
/*  f062b08:	10000003 */ 	b	.L0f062b18
/*  f062b0c:	ac4b00c4 */ 	sw	$t3,0xc4($v0)
.L0f062b10:
/*  f062b10:	358d0080 */ 	ori	$t5,$t4,0x80
/*  f062b14:	ac4d00c4 */ 	sw	$t5,0xc4($v0)
.L0f062b18:
/*  f062b18:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f062b1c:
/*  f062b1c:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f062b20:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f062b24:	03e00008 */ 	jr	$ra
/*  f062b28:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f062b2c
/*  f062b2c:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x34)
/*  f062b30:	8dce9ff4 */ 	lw	$t6,%lo(g_Vars+0x34)($t6)
/*  f062b34:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f062b38:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f062b3c:	59c00006 */ 	blezl	$t6,.L0f062b58
/*  f062b40:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f062b44:	0fc189e5 */ 	jal	func0f062794
/*  f062b48:	00002025 */ 	or	$a0,$zero,$zero
/*  f062b4c:	0fc189e5 */ 	jal	func0f062794
/*  f062b50:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f062b54:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f062b58:
/*  f062b58:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f062b5c:	03e00008 */ 	jr	$ra
/*  f062b60:	00000000 */ 	nop
);

void func0f062b64(struct prop *prop, s32 arg1)
{
	if (arg1 == 1) {
		if ((prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_OBJ)
				&& prop->obj && (prop->obj->hidden2 & OBJH2FLAG_04)) {
			struct defaultobj *obj = prop->obj;

			prop->timetoregen = 1200;

			obj->damage = 0;
			obj->hidden |= OBJHFLAG_00000800;
			obj->hidden &= ~OBJHFLAG_00000004;
			obj->hidden2 &= ~OBJH2FLAG_40;

			func0f065c44(prop);
			propHide(prop);

			if (!prop->inlist1) {
				propMoveFromList2To1(prop);
			}
		} else {
			func0f065c44(prop);
			propRemoveFromCurrentList(prop);
			propHide(prop);
			propFree(prop);
		}
	} else if (arg1 == 2) {
		func0f065c44(prop);
		propRemoveFromCurrentList(prop);
		propHide(prop);
	} else if (arg1 == 4) {
		func0f065c44(prop);
		propRemoveFromCurrentList(prop);
		propHide(prop);
		objDetach(prop);
		func0f06ac90(prop);
		propReparent(prop, g_Vars.currentplayer->prop);
	}
}

GLOBAL_ASM(
glabel currentPlayerFindPropForInteract
/*  f062cbc:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f062cc0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f062cc4:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f062cc8:	3c01800a */ 	lui	$at,%hi(var8009cda8)
/*  f062ccc:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f062cd0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f062cd4:	ac20cda8 */ 	sw	$zero,%lo(var8009cda8)($at)
/*  f062cd8:	8e30034c */ 	lw	$s0,0x34c($s1)
/*  f062cdc:	8e2e0348 */ 	lw	$t6,0x348($s1)
/*  f062ce0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f062ce4:	2610fffc */ 	addiu	$s0,$s0,-4
/*  f062ce8:	020e082b */ 	sltu	$at,$s0,$t6
/*  f062cec:	00809025 */ 	or	$s2,$a0,$zero
/*  f062cf0:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f062cf4:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f062cf8:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f062cfc:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f062d00:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f062d04:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f062d08:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f062d0c:	14200022 */ 	bnez	$at,.L0f062d98
/*  f062d10:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f062d14:	241e0008 */ 	addiu	$s8,$zero,0x8
/*  f062d18:	24160002 */ 	addiu	$s6,$zero,0x2
/*  f062d1c:	24150004 */ 	addiu	$s5,$zero,0x4
/*  f062d20:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f062d24:	24130003 */ 	addiu	$s3,$zero,0x3
/*  f062d28:	8e040000 */ 	lw	$a0,0x0($s0)
.L0f062d2c:
/*  f062d2c:	50800016 */ 	beqzl	$a0,.L0f062d88
/*  f062d30:	8e2f0348 */ 	lw	$t7,0x348($s1)
/*  f062d34:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f062d38:	12620010 */ 	beq	$s3,$v0,.L0f062d7c
/*  f062d3c:	00000000 */ 	nop
/*  f062d40:	12820003 */ 	beq	$s4,$v0,.L0f062d50
/*  f062d44:	00000000 */ 	nop
/*  f062d48:	16a20007 */ 	bne	$s5,$v0,.L0f062d68
/*  f062d4c:	00000000 */ 	nop
.L0f062d50:
/*  f062d50:	1640000a */ 	bnez	$s2,.L0f062d7c
/*  f062d54:	00000000 */ 	nop
/*  f062d58:	0fc21a73 */ 	jal	func0f0869cc
/*  f062d5c:	00000000 */ 	nop
/*  f062d60:	10000006 */ 	b	.L0f062d7c
/*  f062d64:	00401825 */ 	or	$v1,$v0,$zero
.L0f062d68:
/*  f062d68:	16c20004 */ 	bne	$s6,$v0,.L0f062d7c
/*  f062d6c:	00000000 */ 	nop
/*  f062d70:	0fc23f2e */ 	jal	doorTestForInteract
/*  f062d74:	00000000 */ 	nop
/*  f062d78:	00401825 */ 	or	$v1,$v0,$zero
.L0f062d7c:
/*  f062d7c:	50600007 */ 	beqzl	$v1,.L0f062d9c
/*  f062d80:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f062d84:	8e2f0348 */ 	lw	$t7,0x348($s1)
.L0f062d88:
/*  f062d88:	2610fffc */ 	addiu	$s0,$s0,-4
/*  f062d8c:	020f082b */ 	sltu	$at,$s0,$t7
/*  f062d90:	5020ffe6 */ 	beqzl	$at,.L0f062d2c
/*  f062d94:	8e040000 */ 	lw	$a0,0x0($s0)
.L0f062d98:
/*  f062d98:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f062d9c:
/*  f062d9c:	3c02800a */ 	lui	$v0,%hi(var8009cda8)
/*  f062da0:	8c42cda8 */ 	lw	$v0,%lo(var8009cda8)($v0)
/*  f062da4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f062da8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f062dac:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f062db0:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f062db4:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f062db8:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f062dbc:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f062dc0:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f062dc4:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f062dc8:	03e00008 */ 	jr	$ra
/*  f062dcc:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

// Mismatch due to regalloc.
// It's likely a switch was used, and using one comes close but doesn't match
// as well. Another problem is that 8 (PROPTYPE_SMOKE) needs to be loaded into
// a register, but referencing prop an extra time time promotes it to s0. This
// is resolved below by passing *ptr to those functions instead of prop, but
// this seems unlikely.
// If attempting to use a switch, note that the door part needs to be an if
// statement inside the default case.
//struct prop *currentPlayerFindPropForInteract(bool usingeyespy)
//{
//	struct prop **ptr;
//	bool result;
//
//	var8009cda8 = NULL;
//	ptr = g_Vars.unk00034c - 1;
//	result = true;
//
//	// Iterate tangible list in reverse
//	while (ptr >= g_Vars.tangibleprops) {
//		struct prop *prop = *ptr;
//
//		if (prop) {
//			if (prop->type != PROPTYPE_CHR) {
//				if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON) {
//					if (!usingeyespy) {
//						result = func0f0869cc(*ptr);
//					}
//				} else if (prop->type == PROPTYPE_DOOR) {
//					result = doorTestForInteract(*ptr);
//
//					if (prop->type == PROPTYPE_SMOKE);
//				}
//			}
//
//			if (!result) {
//				break;
//			}
//		}
//
//		ptr--;
//	}
//
//	return var8009cda8;
//}

void func0f062dd0(void)
{
	struct prop **ptr = g_Vars.unk00034c - 1;
	bool result = true;

	// Iterate tangible list in reverse
	while (ptr >= g_Vars.tangibleprops) {
		struct prop *prop = *ptr;

		if (prop) {
			if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON) {
				result = func0f0869cc(prop);
			}

			if (!result) {
				return;
			}
		}

		ptr--;
	}
}

bool currentPlayerInteract(bool eyespy)
{
	struct prop *prop;
	bool value = false;

	prop = currentPlayerFindPropForInteract(eyespy);

	if (prop) {
		switch (prop->type) {
		case PROPTYPE_OBJ:
		case PROPTYPE_WEAPON:
			value = propobjInteract(prop);
			break;
		case PROPTYPE_DOOR:
			value = propdoorInteract(prop);
			break;
		case PROPTYPE_CHR:
		case PROPTYPE_EYESPY:
		case PROPTYPE_PLAYER:
		case PROPTYPE_EXPLOSION:
		case PROPTYPE_SMOKE:
			break;
		}

		func0f062b64(prop, value);

		return false;
	}

	return true;
}

void propPrependToList2(struct prop *prop)
{
	if ((prop->flags & PROPFLAG_10) == 0) {
		propRemoveFromCurrentList(prop);

		if (g_Vars.list2head) {
			prop->prev = g_Vars.list2head->prev;

			if (prop->prev) {
				prop->prev->next = prop;
			}

			g_Vars.list2head->prev = prop;
			prop->next = g_Vars.list2head;

			if (g_Vars.list1head == g_Vars.list2head) {
				g_Vars.list1head = g_Vars.list1tail = prop;
			}

			g_Vars.list2head = prop;
		} else {
			prop->next = NULL;

			if (g_Vars.list1tail) {
				prop->prev = g_Vars.list1tail;
				g_Vars.list1tail->next = prop;
			} else {
				g_Vars.list1tail = prop;
				g_Vars.list1head = prop;
			}

			g_Vars.list2head = prop;
		}
	}
}

void propMoveFromList2To1(struct prop *prop)
{
	if (prop == g_Vars.list2head) {
		if (g_Vars.list1head == g_Vars.list2head) {
			g_Vars.list1head = g_Vars.list1tail = prop->next;
		}

		g_Vars.list2head = prop->next;
	}

	if (prop->next) {
		prop->next->prev = prop->prev;
	}

	if (prop->prev) {
		prop->prev->next = prop->next;
	}

	prop->next = NULL;
	prop->prev = NULL;

	propPrependToList1(prop);
}

u32 var80069884 = 0x00000001;
u32 var80069888 = 0x01010101;
u32 var8006988c = 0x01000101;
u32 var80069890 = 0x01010100;
u32 var80069894 = 0x00010101;
u32 var80069898 = 0x01010000;
u32 var8006989c = 0x00000000;
u32 var800698a0 = 0x00000100;
u32 var800698a4 = 0x00000000;
u32 var800698a8 = 0x01010000;
u32 var800698ac = 0x00000101;
u32 var800698b0 = 0x01000101;
u32 var800698b4 = 0x00000000;
u32 var800698b8 = 0x00000100;
u32 var800698bc = 0x00000001;
u32 var800698c0 = 0x00000000;
u32 var800698c4 = 0x00000000;
u32 var800698c8 = 0x00000000;
u32 var800698cc = 0x00000000;

GLOBAL_ASM(
glabel func0f06302c
/*  f06302c:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f063030:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f063034:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f063038:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f06303c:	ae20043c */ 	sw	$zero,0x43c($s1)
/*  f063040:	3c01800a */ 	lui	$at,%hi(var8009cdac)
/*  f063044:	ac20cdac */ 	sw	$zero,%lo(var8009cdac)($at)
/*  f063048:	3c01800a */ 	lui	$at,%hi(var8009cdb0)
/*  f06304c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f063050:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f063054:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f063058:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f06305c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f063060:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f063064:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f063068:	10800009 */ 	beqz	$a0,.L0f063090
/*  f06306c:	ac20cdb0 */ 	sw	$zero,%lo(var8009cdb0)($at)
/*  f063070:	9622035c */ 	lhu	$v0,0x35c($s1)
/*  f063074:	2401ffff */ 	addiu	$at,$zero,-1
/*  f063078:	244f0001 */ 	addiu	$t7,$v0,0x1
/*  f06307c:	31f8ffff */ 	andi	$t8,$t7,0xffff
/*  f063080:	a62f035c */ 	sh	$t7,0x35c($s1)
/*  f063084:	17010002 */ 	bne	$t8,$at,.L0f063090
/*  f063088:	a622035e */ 	sh	$v0,0x35e($s1)
/*  f06308c:	a620035c */ 	sh	$zero,0x35c($s1)
.L0f063090:
/*  f063090:	92270358 */ 	lbu	$a3,0x358($s1)
/*  f063094:	8e390034 */ 	lw	$t9,0x34($s1)
/*  f063098:	8e2d0038 */ 	lw	$t5,0x38($s1)
/*  f06309c:	c6240044 */ 	lwc1	$f4,0x44($s1)
/*  f0630a0:	c626004c */ 	lwc1	$f6,0x4c($s1)
/*  f0630a4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0630a8:	afb9008c */ 	sw	$t9,0x8c($sp)
/*  f0630ac:	afad0088 */ 	sw	$t5,0x88($sp)
/*  f0630b0:	e7a40084 */ 	swc1	$f4,0x84($sp)
/*  f0630b4:	18e0000e */ 	blez	$a3,.L0f0630f0
/*  f0630b8:	e7a60080 */ 	swc1	$f6,0x80($sp)
/*  f0630bc:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0630c0:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0630c4:	8c4e0370 */ 	lw	$t6,0x370($v0)
.L0f0630c8:
/*  f0630c8:	8e2f0034 */ 	lw	$t7,0x34($s1)
/*  f0630cc:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0630d0:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f0630d4:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0630d8:	ac580354 */ 	sw	$t8,0x354($v0)
/*  f0630dc:	92270358 */ 	lbu	$a3,0x358($s1)
/*  f0630e0:	00a7082a */ 	slt	$at,$a1,$a3
/*  f0630e4:	5420fff8 */ 	bnezl	$at,.L0f0630c8
/*  f0630e8:	8c4e0370 */ 	lw	$t6,0x370($v0)
/*  f0630ec:	00002825 */ 	or	$a1,$zero,$zero
.L0f0630f0:
/*  f0630f0:	9239035a */ 	lbu	$t9,0x35a($s1)
/*  f0630f4:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f0630f8:	24140003 */ 	addiu	$s4,$zero,0x3
/*  f0630fc:	272d0001 */ 	addiu	$t5,$t9,0x1
/*  f063100:	31a300ff */ 	andi	$v1,$t5,0xff
/*  f063104:	0067082a */ 	slt	$at,$v1,$a3
/*  f063108:	14200003 */ 	bnez	$at,.L0f063118
/*  f06310c:	a22d035a */ 	sb	$t5,0x35a($s1)
/*  f063110:	a220035a */ 	sb	$zero,0x35a($s1)
/*  f063114:	300300ff */ 	andi	$v1,$zero,0xff
.L0f063118:
/*  f063118:	306900ff */ 	andi	$t1,$v1,0xff
/*  f06311c:	000970c0 */ 	sll	$t6,$t1,0x3
/*  f063120:	01c97023 */ 	subu	$t6,$t6,$t1
/*  f063124:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f063128:	022e5021 */ 	addu	$t2,$s1,$t6
/*  f06312c:	8d420370 */ 	lw	$v0,0x370($t2)
/*  f063130:	3c013e80 */ 	lui	$at,0x3e80
/*  f063134:	8d4f0374 */ 	lw	$t7,0x374($t2)
/*  f063138:	44824000 */ 	mtc1	$v0,$f8
/*  f06313c:	44818000 */ 	mtc1	$at,$f16
/*  f063140:	01e24021 */ 	addu	$t0,$t7,$v0
/*  f063144:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f063148:	31180003 */ 	andi	$t8,$t0,0x3
/*  f06314c:	ad580374 */ 	sw	$t8,0x374($t2)
/*  f063150:	922d0358 */ 	lbu	$t5,0x358($s1)
/*  f063154:	24480002 */ 	addiu	$t0,$v0,0x2
/*  f063158:	0008c883 */ 	sra	$t9,$t0,0x2
/*  f06315c:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f063160:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f063164:	03204025 */ 	or	$t0,$t9,$zero
/*  f063168:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f06316c:	2413008c */ 	addiu	$s3,$zero,0x8c
/*  f063170:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f063174:	19a0000c */ 	blez	$t5,.L0f0631a8
/*  f063178:	e7b20074 */ 	swc1	$f18,0x74($sp)
/*  f06317c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f063180:	a4400360 */ 	sh	$zero,0x360($v0)
.L0f063184:
/*  f063184:	a4400362 */ 	sh	$zero,0x362($v0)
/*  f063188:	a4400364 */ 	sh	$zero,0x364($v0)
/*  f06318c:	a4400366 */ 	sh	$zero,0x366($v0)
/*  f063190:	922e0358 */ 	lbu	$t6,0x358($s1)
/*  f063194:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f063198:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f06319c:	00ae082a */ 	slt	$at,$a1,$t6
/*  f0631a0:	5420fff8 */ 	bnezl	$at,.L0f063184
/*  f0631a4:	a4400360 */ 	sh	$zero,0x360($v0)
.L0f0631a8:
/*  f0631a8:	8e2f0290 */ 	lw	$t7,0x290($s1)
/*  f0631ac:	55e00024 */ 	bnezl	$t7,.L0f063240
/*  f0631b0:	8e380334 */ 	lw	$t8,0x334($s1)
/*  f0631b4:	8e380334 */ 	lw	$t8,0x334($s1)
/*  f0631b8:	8e300338 */ 	lw	$s0,0x338($s1)
/*  f0631bc:	2407ff7f */ 	addiu	$a3,$zero,-129
/*  f0631c0:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0631c4:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0631c8:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0631cc:	03302821 */ 	addu	$a1,$t9,$s0
/*  f0631d0:	0205082b */ 	sltu	$at,$s0,$a1
/*  f0631d4:	1020002e */ 	beqz	$at,.L0f063290
/*  f0631d8:	2406ffbf */ 	addiu	$a2,$zero,-65
/*  f0631dc:	2404fffd */ 	addiu	$a0,$zero,-3
.L0f0631e0:
/*  f0631e0:	92020001 */ 	lbu	$v0,0x1($s0)
/*  f0631e4:	304d0002 */ 	andi	$t5,$v0,0x2
/*  f0631e8:	11a00003 */ 	beqz	$t5,.L0f0631f8
/*  f0631ec:	00401825 */ 	or	$v1,$v0,$zero
/*  f0631f0:	00441024 */ 	and	$v0,$v0,$a0
/*  f0631f4:	304300ff */ 	andi	$v1,$v0,0xff
.L0f0631f8:
/*  f0631f8:	306f0040 */ 	andi	$t7,$v1,0x40
/*  f0631fc:	11e00005 */ 	beqz	$t7,.L0f063214
/*  f063200:	306d0080 */ 	andi	$t5,$v1,0x80
/*  f063204:	34780080 */ 	ori	$t8,$v1,0x80
/*  f063208:	03061024 */ 	and	$v0,$t8,$a2
/*  f06320c:	10000004 */ 	b	.L0f063220
/*  f063210:	304300ff */ 	andi	$v1,$v0,0xff
.L0f063214:
/*  f063214:	11a00002 */ 	beqz	$t5,.L0f063220
/*  f063218:	00671024 */ 	and	$v0,$v1,$a3
/*  f06321c:	304300ff */ 	andi	$v1,$v0,0xff
.L0f063220:
/*  f063220:	26100048 */ 	addiu	$s0,$s0,0x48
/*  f063224:	0205082b */ 	sltu	$at,$s0,$a1
/*  f063228:	346f0008 */ 	ori	$t7,$v1,0x8
/*  f06322c:	1420ffec */ 	bnez	$at,.L0f0631e0
/*  f063230:	a20fffb9 */ 	sb	$t7,-0x47($s0)
/*  f063234:	10000017 */ 	b	.L0f063294
/*  f063238:	afaa0034 */ 	sw	$t2,0x34($sp)
/*  f06323c:	8e380334 */ 	lw	$t8,0x334($s1)
.L0f063240:
/*  f063240:	8e300338 */ 	lw	$s0,0x338($s1)
/*  f063244:	2404fffd */ 	addiu	$a0,$zero,-3
/*  f063248:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f06324c:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f063250:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f063254:	03302821 */ 	addu	$a1,$t9,$s0
/*  f063258:	0205082b */ 	sltu	$at,$s0,$a1
/*  f06325c:	5020000d */ 	beqzl	$at,.L0f063294
/*  f063260:	afaa0034 */ 	sw	$t2,0x34($sp)
.L0f063264:
/*  f063264:	92020001 */ 	lbu	$v0,0x1($s0)
/*  f063268:	304d0002 */ 	andi	$t5,$v0,0x2
/*  f06326c:	11a00004 */ 	beqz	$t5,.L0f063280
/*  f063270:	00401825 */ 	or	$v1,$v0,$zero
/*  f063274:	00641024 */ 	and	$v0,$v1,$a0
/*  f063278:	304e00ff */ 	andi	$t6,$v0,0xff
/*  f06327c:	01c01025 */ 	or	$v0,$t6,$zero
.L0f063280:
/*  f063280:	26100048 */ 	addiu	$s0,$s0,0x48
/*  f063284:	0205082b */ 	sltu	$at,$s0,$a1
/*  f063288:	1420fff6 */ 	bnez	$at,.L0f063264
/*  f06328c:	a202ffb9 */ 	sb	$v0,-0x47($s0)
.L0f063290:
/*  f063290:	afaa0034 */ 	sw	$t2,0x34($sp)
.L0f063294:
/*  f063294:	afaa0034 */ 	sw	$t2,0x34($sp)
/*  f063298:	8e30033c */ 	lw	$s0,0x33c($s1)
/*  f06329c:	afa80078 */ 	sw	$t0,0x78($sp)
/*  f0632a0:	a3a90069 */ 	sb	$t1,0x69($sp)
/*  f0632a4:	8e0f0020 */ 	lw	$t7,0x20($s0)
.L0f0632a8:
/*  f0632a8:	8e390354 */ 	lw	$t9,0x354($s1)
/*  f0632ac:	8e2e02ac */ 	lw	$t6,0x2ac($s1)
/*  f0632b0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0632b4:	01f96826 */ 	xor	$t5,$t7,$t9
/*  f0632b8:	2dad0001 */ 	sltiu	$t5,$t5,0x1
/*  f0632bc:	afad004c */ 	sw	$t5,0x4c($sp)
/*  f0632c0:	12ae0003 */ 	beq	$s5,$t6,.L0f0632d0
/*  f0632c4:	afaf005c */ 	sw	$t7,0x5c($sp)
/*  f0632c8:	10000002 */ 	b	.L0f0632d4
/*  f0632cc:	02a02825 */ 	or	$a1,$s5,$zero
.L0f0632d0:
/*  f0632d0:	9225035b */ 	lbu	$a1,0x35b($s1)
.L0f0632d4:
/*  f0632d4:	86080028 */ 	lh	$t0,0x28($s0)
/*  f0632d8:	26070028 */ 	addiu	$a3,$s0,0x28
/*  f0632dc:	00e01825 */ 	or	$v1,$a3,$zero
/*  f0632e0:	1248000f */ 	beq	$s2,$t0,.L0f063320
/*  f0632e4:	3c04800a */ 	lui	$a0,%hi(g_Rooms)
/*  f0632e8:	8c844928 */ 	lw	$a0,%lo(g_Rooms)($a0)
/*  f0632ec:	84620000 */ 	lh	$v0,0x0($v1)
.L0f0632f0:
/*  f0632f0:	00530019 */ 	multu	$v0,$s3
/*  f0632f4:	00007812 */ 	mflo	$t7
/*  f0632f8:	008fc021 */ 	addu	$t8,$a0,$t7
/*  f0632fc:	97190000 */ 	lhu	$t9,0x0($t8)
/*  f063300:	332d0004 */ 	andi	$t5,$t9,0x4
/*  f063304:	51a00003 */ 	beqzl	$t5,.L0f063314
/*  f063308:	84620002 */ 	lh	$v0,0x2($v1)
/*  f06330c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f063310:	84620002 */ 	lh	$v0,0x2($v1)
.L0f063314:
/*  f063314:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f063318:	1642fff5 */ 	bne	$s2,$v0,.L0f0632f0
/*  f06331c:	00000000 */ 	nop
.L0f063320:
/*  f063320:	54a0003c */ 	bnezl	$a1,.L0f063414
/*  f063324:	960d003a */ 	lhu	$t5,0x3a($s0)
/*  f063328:	92030000 */ 	lbu	$v1,0x0($s0)
/*  f06332c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f063330:	14610003 */ 	bne	$v1,$at,.L0f063340
/*  f063334:	00000000 */ 	nop
/*  f063338:	1000000b */ 	b	.L0f063368
/*  f06333c:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f063340:
/*  f063340:	12a30003 */ 	beq	$s5,$v1,.L0f063350
/*  f063344:	24010004 */ 	addiu	$at,$zero,0x4
/*  f063348:	14610007 */ 	bne	$v1,$at,.L0f063368
/*  f06334c:	00000000 */ 	nop
.L0f063350:
/*  f063350:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f063354:	8c4e0040 */ 	lw	$t6,0x40($v0)
/*  f063358:	31cf0080 */ 	andi	$t7,$t6,0x80
/*  f06335c:	11e00002 */ 	beqz	$t7,.L0f063368
/*  f063360:	00000000 */ 	nop
/*  f063364:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f063368:
/*  f063368:	54a0002a */ 	bnezl	$a1,.L0f063414
/*  f06336c:	960d003a */ 	lhu	$t5,0x3a($s0)
/*  f063370:	92180001 */ 	lbu	$t8,0x1($s0)
/*  f063374:	24010084 */ 	addiu	$at,$zero,0x84
/*  f063378:	33190084 */ 	andi	$t9,$t8,0x84
/*  f06337c:	57210004 */ 	bnel	$t9,$at,.L0f063390
/*  f063380:	9202003f */ 	lbu	$v0,0x3f($s0)
/*  f063384:	10000022 */ 	b	.L0f063410
/*  f063388:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f06338c:	9202003f */ 	lbu	$v0,0x3f($s0)
.L0f063390:
/*  f063390:	000269c2 */ 	srl	$t5,$v0,0x7
/*  f063394:	11a00004 */ 	beqz	$t5,.L0f0633a8
/*  f063398:	304eff7f */ 	andi	$t6,$v0,0xff7f
/*  f06339c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0633a0:	1000001b */ 	b	.L0f063410
/*  f0633a4:	a20e003f */ 	sb	$t6,0x3f($s0)
.L0f0633a8:
/*  f0633a8:	8e0f003c */ 	lw	$t7,0x3c($s0)
/*  f0633ac:	000fce80 */ 	sll	$t9,$t7,0x1a
/*  f0633b0:	07210003 */ 	bgez	$t9,.L0f0633c0
/*  f0633b4:	00000000 */ 	nop
/*  f0633b8:	10000015 */ 	b	.L0f063410
/*  f0633bc:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f0633c0:
/*  f0633c0:	1248000f */ 	beq	$s2,$t0,.L0f063400
/*  f0633c4:	00e01825 */ 	or	$v1,$a3,$zero
/*  f0633c8:	3c04800a */ 	lui	$a0,%hi(g_Rooms)
/*  f0633cc:	8c844928 */ 	lw	$a0,%lo(g_Rooms)($a0)
/*  f0633d0:	84e20000 */ 	lh	$v0,0x0($a3)
.L0f0633d4:
/*  f0633d4:	00530019 */ 	multu	$v0,$s3
/*  f0633d8:	00006812 */ 	mflo	$t5
/*  f0633dc:	008d7021 */ 	addu	$t6,$a0,$t5
/*  f0633e0:	95cf0000 */ 	lhu	$t7,0x0($t6)
/*  f0633e4:	31f80008 */ 	andi	$t8,$t7,0x8
/*  f0633e8:	57000006 */ 	bnezl	$t8,.L0f063404
/*  f0633ec:	84790000 */ 	lh	$t9,0x0($v1)
/*  f0633f0:	84620002 */ 	lh	$v0,0x2($v1)
/*  f0633f4:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f0633f8:	1642fff6 */ 	bne	$s2,$v0,.L0f0633d4
/*  f0633fc:	00000000 */ 	nop
.L0f063400:
/*  f063400:	84790000 */ 	lh	$t9,0x0($v1)
.L0f063404:
/*  f063404:	52590003 */ 	beql	$s2,$t9,.L0f063414
/*  f063408:	960d003a */ 	lhu	$t5,0x3a($s0)
/*  f06340c:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f063410:
/*  f063410:	960d003a */ 	lhu	$t5,0x3a($s0)
.L0f063414:
/*  f063414:	8e2e0034 */ 	lw	$t6,0x34($s1)
/*  f063418:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f06341c:	18a0007d */ 	blez	$a1,.L0f063614
/*  f063420:	a60f003a */ 	sh	$t7,0x3a($s0)
/*  f063424:	9638035e */ 	lhu	$t8,0x35e($s1)
/*  f063428:	96190038 */ 	lhu	$t9,0x38($s0)
/*  f06342c:	31edffff */ 	andi	$t5,$t7,0xffff
/*  f063430:	53190016 */ 	beql	$t8,$t9,.L0f06348c
/*  f063434:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f063438:	ae2d0034 */ 	sw	$t5,0x34($s1)
/*  f06343c:	920f003c */ 	lbu	$t7,0x3c($s0)
/*  f063440:	960e003a */ 	lhu	$t6,0x3a($s0)
/*  f063444:	3c013e80 */ 	lui	$at,0x3e80
/*  f063448:	44814000 */ 	mtc1	$at,$f8
/*  f06344c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f063450:	ae380038 */ 	sw	$t8,0x38($s1)
/*  f063454:	330d0003 */ 	andi	$t5,$t8,0x3
/*  f063458:	a20d003c */ 	sb	$t5,0x3c($s0)
/*  f06345c:	8e380034 */ 	lw	$t8,0x34($s1)
/*  f063460:	8e2e0038 */ 	lw	$t6,0x38($s1)
/*  f063464:	44982000 */ 	mtc1	$t8,$f4
/*  f063468:	000e7883 */ 	sra	$t7,$t6,0x2
/*  f06346c:	ae2f0038 */ 	sw	$t7,0x38($s1)
/*  f063470:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f063474:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f063478:	e62a0044 */ 	swc1	$f10,0x44($s1)
/*  f06347c:	c6300044 */ 	lwc1	$f16,0x44($s1)
/*  f063480:	10000009 */ 	b	.L0f0634a8
/*  f063484:	e630004c */ 	swc1	$f16,0x4c($s1)
/*  f063488:	8fb9008c */ 	lw	$t9,0x8c($sp)
.L0f06348c:
/*  f06348c:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f063490:	c7b20084 */ 	lwc1	$f18,0x84($sp)
/*  f063494:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f063498:	ae390034 */ 	sw	$t9,0x34($s1)
/*  f06349c:	ae2d0038 */ 	sw	$t5,0x38($s1)
/*  f0634a0:	e6320044 */ 	swc1	$f18,0x44($s1)
/*  f0634a4:	e624004c */ 	swc1	$f4,0x4c($s1)
.L0f0634a8:
/*  f0634a8:	920e0000 */ 	lbu	$t6,0x0($s0)
/*  f0634ac:	a200003e */ 	sb	$zero,0x3e($s0)
/*  f0634b0:	568e001c */ 	bnel	$s4,$t6,.L0f063524
/*  f0634b4:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f0634b8:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f0634bc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0634c0:	0fc522e0 */ 	jal	splatTick
/*  f0634c4:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f0634c8:	8fa20048 */ 	lw	$v0,0x48($sp)
/*  f0634cc:	10400008 */ 	beqz	$v0,.L0f0634f0
/*  f0634d0:	00000000 */ 	nop
/*  f0634d4:	8c4f02d4 */ 	lw	$t7,0x2d4($v0)
/*  f0634d8:	11e00005 */ 	beqz	$t7,.L0f0634f0
/*  f0634dc:	00000000 */ 	nop
/*  f0634e0:	0fc64634 */ 	jal	func0f1918d0
/*  f0634e4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0634e8:	10000004 */ 	b	.L0f0634fc
/*  f0634ec:	00403025 */ 	or	$a2,$v0,$zero
.L0f0634f0:
/*  f0634f0:	0fc08c26 */ 	jal	func0f023098
/*  f0634f4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0634f8:	00403025 */ 	or	$a2,$v0,$zero
.L0f0634fc:
/*  f0634fc:	9218003d */ 	lbu	$t8,0x3d($s0)
/*  f063500:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f063504:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f063508:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f06350c:	02391021 */ 	addu	$v0,$s1,$t9
/*  f063510:	944d0366 */ 	lhu	$t5,0x366($v0)
/*  f063514:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f063518:	1000002b */ 	b	.L0f0635c8
/*  f06351c:	a44e0366 */ 	sh	$t6,0x366($v0)
/*  f063520:	920f003d */ 	lbu	$t7,0x3d($s0)
.L0f063524:
/*  f063524:	24010004 */ 	addiu	$at,$zero,0x4
/*  f063528:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f06352c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f063530:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f063534:	02381021 */ 	addu	$v0,$s1,$t8
/*  f063538:	94590364 */ 	lhu	$t9,0x364($v0)
/*  f06353c:	272d0001 */ 	addiu	$t5,$t9,0x1
/*  f063540:	a44d0364 */ 	sh	$t5,0x364($v0)
/*  f063544:	92030000 */ 	lbu	$v1,0x0($s0)
/*  f063548:	12a30005 */ 	beq	$s5,$v1,.L0f063560
/*  f06354c:	00000000 */ 	nop
/*  f063550:	10610003 */ 	beq	$v1,$at,.L0f063560
/*  f063554:	24010002 */ 	addiu	$at,$zero,0x2
/*  f063558:	54610006 */ 	bnel	$v1,$at,.L0f063574
/*  f06355c:	24010007 */ 	addiu	$at,$zero,0x7
.L0f063560:
/*  f063560:	0fc1f9d6 */ 	jal	objTick
/*  f063564:	02002025 */ 	or	$a0,$s0,$zero
/*  f063568:	10000017 */ 	b	.L0f0635c8
/*  f06356c:	00403025 */ 	or	$a2,$v0,$zero
/*  f063570:	24010007 */ 	addiu	$at,$zero,0x7
.L0f063574:
/*  f063574:	54610006 */ 	bnel	$v1,$at,.L0f063590
/*  f063578:	24010008 */ 	addiu	$at,$zero,0x8
/*  f06357c:	0fc4b16a */ 	jal	explosionUpdateZ
/*  f063580:	02002025 */ 	or	$a0,$s0,$zero
/*  f063584:	10000010 */ 	b	.L0f0635c8
/*  f063588:	00403025 */ 	or	$a2,$v0,$zero
/*  f06358c:	24010008 */ 	addiu	$at,$zero,0x8
.L0f063590:
/*  f063590:	54610006 */ 	bnel	$v1,$at,.L0f0635ac
/*  f063594:	24010006 */ 	addiu	$at,$zero,0x6
/*  f063598:	0fc4bc61 */ 	jal	smokeUpdateZ
/*  f06359c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0635a0:	10000009 */ 	b	.L0f0635c8
/*  f0635a4:	00403025 */ 	or	$a2,$v0,$zero
/*  f0635a8:	24010006 */ 	addiu	$at,$zero,0x6
.L0f0635ac:
/*  f0635ac:	54610007 */ 	bnel	$v1,$at,.L0f0635cc
/*  f0635b0:	962e035e */ 	lhu	$t6,0x35e($s1)
/*  f0635b4:	0fc522e0 */ 	jal	splatTick
/*  f0635b8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0635bc:	0fc308d9 */ 	jal	func0f0c2364
/*  f0635c0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0635c4:	00403025 */ 	or	$a2,$v0,$zero
.L0f0635c8:
/*  f0635c8:	962e035e */ 	lhu	$t6,0x35e($s1)
.L0f0635cc:
/*  f0635cc:	960f0038 */ 	lhu	$t7,0x38($s0)
/*  f0635d0:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f0635d4:	51cf0009 */ 	beql	$t6,$t7,.L0f0635fc
/*  f0635d8:	920e003f */ 	lbu	$t6,0x3f($s0)
/*  f0635dc:	8fb90088 */ 	lw	$t9,0x88($sp)
/*  f0635e0:	c7a60084 */ 	lwc1	$f6,0x84($sp)
/*  f0635e4:	c7a80080 */ 	lwc1	$f8,0x80($sp)
/*  f0635e8:	ae380034 */ 	sw	$t8,0x34($s1)
/*  f0635ec:	ae390038 */ 	sw	$t9,0x38($s1)
/*  f0635f0:	e6260044 */ 	swc1	$f6,0x44($s1)
/*  f0635f4:	e628004c */ 	swc1	$f8,0x4c($s1)
/*  f0635f8:	920e003f */ 	lbu	$t6,0x3f($s0)
.L0f0635fc:
/*  f0635fc:	962d035c */ 	lhu	$t5,0x35c($s1)
/*  f063600:	a600003a */ 	sh	$zero,0x3a($s0)
/*  f063604:	31cfffbf */ 	andi	$t7,$t6,0xffbf
/*  f063608:	a20f003f */ 	sb	$t7,0x3f($s0)
/*  f06360c:	1000009c */ 	b	.L0f063880
/*  f063610:	a60d0038 */ 	sh	$t5,0x38($s0)
.L0f063614:
/*  f063614:	92180000 */ 	lbu	$t8,0x0($s0)
/*  f063618:	93a30069 */ 	lbu	$v1,0x69($sp)
/*  f06361c:	5698000b */ 	bnel	$s4,$t8,.L0f06364c
/*  f063620:	9218003d */ 	lbu	$t8,0x3d($s0)
/*  f063624:	9219003d */ 	lbu	$t9,0x3d($s0)
/*  f063628:	001968c0 */ 	sll	$t5,$t9,0x3
/*  f06362c:	01b96823 */ 	subu	$t5,$t5,$t9
/*  f063630:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f063634:	022d1021 */ 	addu	$v0,$s1,$t5
/*  f063638:	944e0362 */ 	lhu	$t6,0x362($v0)
/*  f06363c:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f063640:	10000009 */ 	b	.L0f063668
/*  f063644:	a44f0362 */ 	sh	$t7,0x362($v0)
/*  f063648:	9218003d */ 	lbu	$t8,0x3d($s0)
.L0f06364c:
/*  f06364c:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f063650:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f063654:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f063658:	02391021 */ 	addu	$v0,$s1,$t9
/*  f06365c:	944d0360 */ 	lhu	$t5,0x360($v0)
/*  f063660:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f063664:	a44e0360 */ 	sh	$t6,0x360($v0)
.L0f063668:
/*  f063668:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f06366c:	8fb90034 */ 	lw	$t9,0x34($sp)
/*  f063670:	546f0084 */ 	bnel	$v1,$t7,.L0f063884
/*  f063674:	8fad008c */ 	lw	$t5,0x8c($sp)
/*  f063678:	96180038 */ 	lhu	$t8,0x38($s0)
/*  f06367c:	972d0378 */ 	lhu	$t5,0x378($t9)
/*  f063680:	3c01800a */ 	lui	$at,%hi(g_Vars+0x4c)
/*  f063684:	530d0017 */ 	beql	$t8,$t5,.L0f0636e4
/*  f063688:	8fad007c */ 	lw	$t5,0x7c($sp)
/*  f06368c:	960e003a */ 	lhu	$t6,0x3a($s0)
/*  f063690:	3c013e80 */ 	lui	$at,0x3e80
/*  f063694:	44819000 */ 	mtc1	$at,$f18
/*  f063698:	ae2e0034 */ 	sw	$t6,0x34($s1)
/*  f06369c:	9219003c */ 	lbu	$t9,0x3c($s0)
/*  f0636a0:	960f003a */ 	lhu	$t7,0x3a($s0)
/*  f0636a4:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f0636a8:	ae380038 */ 	sw	$t8,0x38($s1)
/*  f0636ac:	330e0003 */ 	andi	$t6,$t8,0x3
/*  f0636b0:	a20e003c */ 	sb	$t6,0x3c($s0)
/*  f0636b4:	8e380034 */ 	lw	$t8,0x34($s1)
/*  f0636b8:	8e2f0038 */ 	lw	$t7,0x38($s1)
/*  f0636bc:	44985000 */ 	mtc1	$t8,$f10
/*  f0636c0:	000fc883 */ 	sra	$t9,$t7,0x2
/*  f0636c4:	ae390038 */ 	sw	$t9,0x38($s1)
/*  f0636c8:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0636cc:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0636d0:	e6240044 */ 	swc1	$f4,0x44($s1)
/*  f0636d4:	c6260044 */ 	lwc1	$f6,0x44($s1)
/*  f0636d8:	10000009 */ 	b	.L0f063700
/*  f0636dc:	e626004c */ 	swc1	$f6,0x4c($s1)
/*  f0636e0:	8fad007c */ 	lw	$t5,0x7c($sp)
.L0f0636e4:
/*  f0636e4:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f0636e8:	c7a80074 */ 	lwc1	$f8,0x74($sp)
/*  f0636ec:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f0636f0:	ae2d0034 */ 	sw	$t5,0x34($s1)
/*  f0636f4:	ae2e0038 */ 	sw	$t6,0x38($s1)
/*  f0636f8:	e6280044 */ 	swc1	$f8,0x44($s1)
/*  f0636fc:	e42aa00c */ 	swc1	$f10,%lo(g_Vars+0x4c)($at)
.L0f063700:
/*  f063700:	92030000 */ 	lbu	$v1,0x0($s0)
/*  f063704:	16830013 */ 	bne	$s4,$v1,.L0f063754
/*  f063708:	00000000 */ 	nop
/*  f06370c:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f063710:	02002025 */ 	or	$a0,$s0,$zero
/*  f063714:	0fc522e0 */ 	jal	splatTick
/*  f063718:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f06371c:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f063720:	10400008 */ 	beqz	$v0,.L0f063744
/*  f063724:	00000000 */ 	nop
/*  f063728:	8c4f02d4 */ 	lw	$t7,0x2d4($v0)
/*  f06372c:	11e00005 */ 	beqz	$t7,.L0f063744
/*  f063730:	00000000 */ 	nop
/*  f063734:	0fc64634 */ 	jal	func0f1918d0
/*  f063738:	02002025 */ 	or	$a0,$s0,$zero
/*  f06373c:	1000003c */ 	b	.L0f063830
/*  f063740:	00403025 */ 	or	$a2,$v0,$zero
.L0f063744:
/*  f063744:	0fc08c26 */ 	jal	func0f023098
/*  f063748:	02002025 */ 	or	$a0,$s0,$zero
/*  f06374c:	10000038 */ 	b	.L0f063830
/*  f063750:	00403025 */ 	or	$a2,$v0,$zero
.L0f063754:
/*  f063754:	12a30005 */ 	beq	$s5,$v1,.L0f06376c
/*  f063758:	24010004 */ 	addiu	$at,$zero,0x4
/*  f06375c:	10610003 */ 	beq	$v1,$at,.L0f06376c
/*  f063760:	24010002 */ 	addiu	$at,$zero,0x2
/*  f063764:	5461001d */ 	bnel	$v1,$at,.L0f0637dc
/*  f063768:	24010007 */ 	addiu	$at,$zero,0x7
.L0f06376c:
/*  f06376c:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f063770:	3c188007 */ 	lui	$t8,%hi(var80069884)
/*  f063774:	90590003 */ 	lbu	$t9,0x3($v0)
/*  f063778:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f06377c:	93189884 */ 	lbu	$t8,%lo(var80069884)($t8)
/*  f063780:	57000006 */ 	bnezl	$t8,.L0f06379c
/*  f063784:	860d0002 */ 	lh	$t5,0x2($s0)
/*  f063788:	0fc1f9d6 */ 	jal	objTick
/*  f06378c:	02002025 */ 	or	$a0,$s0,$zero
/*  f063790:	10000027 */ 	b	.L0f063830
/*  f063794:	00403025 */ 	or	$a2,$v0,$zero
/*  f063798:	860d0002 */ 	lh	$t5,0x2($s0)
.L0f06379c:
/*  f06379c:	5da00025 */ 	bgtzl	$t5,.L0f063834
/*  f0637a0:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f0637a4:	920e003e */ 	lbu	$t6,0x3e($s0)
/*  f0637a8:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f0637ac:	a20f003e */ 	sb	$t7,0x3e($s0)
/*  f0637b0:	92380358 */ 	lbu	$t8,0x358($s1)
/*  f0637b4:	31f900ff */ 	andi	$t9,$t7,0xff
/*  f0637b8:	270dffff */ 	addiu	$t5,$t8,-1
/*  f0637bc:	01b9082a */ 	slt	$at,$t5,$t9
/*  f0637c0:	5020001c */ 	beqzl	$at,.L0f063834
/*  f0637c4:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f0637c8:	0fc18bbe */ 	jal	propPrependToList2
/*  f0637cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0637d0:	10000017 */ 	b	.L0f063830
/*  f0637d4:	24060005 */ 	addiu	$a2,$zero,0x5
/*  f0637d8:	24010007 */ 	addiu	$at,$zero,0x7
.L0f0637dc:
/*  f0637dc:	54610006 */ 	bnel	$v1,$at,.L0f0637f8
/*  f0637e0:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0637e4:	0fc4b16a */ 	jal	explosionUpdateZ
/*  f0637e8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0637ec:	10000010 */ 	b	.L0f063830
/*  f0637f0:	00403025 */ 	or	$a2,$v0,$zero
/*  f0637f4:	24010008 */ 	addiu	$at,$zero,0x8
.L0f0637f8:
/*  f0637f8:	54610006 */ 	bnel	$v1,$at,.L0f063814
/*  f0637fc:	24010006 */ 	addiu	$at,$zero,0x6
/*  f063800:	0fc4bc61 */ 	jal	smokeUpdateZ
/*  f063804:	02002025 */ 	or	$a0,$s0,$zero
/*  f063808:	10000009 */ 	b	.L0f063830
/*  f06380c:	00403025 */ 	or	$a2,$v0,$zero
/*  f063810:	24010006 */ 	addiu	$at,$zero,0x6
.L0f063814:
/*  f063814:	54610007 */ 	bnel	$v1,$at,.L0f063834
/*  f063818:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f06381c:	0fc522e0 */ 	jal	splatTick
/*  f063820:	02002025 */ 	or	$a0,$s0,$zero
/*  f063824:	0fc308d9 */ 	jal	func0f0c2364
/*  f063828:	02002025 */ 	or	$a0,$s0,$zero
/*  f06382c:	00403025 */ 	or	$a2,$v0,$zero
.L0f063830:
/*  f063830:	8faf0034 */ 	lw	$t7,0x34($sp)
.L0f063834:
/*  f063834:	960e0038 */ 	lhu	$t6,0x38($s0)
/*  f063838:	8fb9007c */ 	lw	$t9,0x7c($sp)
/*  f06383c:	95f80378 */ 	lhu	$t8,0x378($t7)
/*  f063840:	3c01800a */ 	lui	$at,%hi(g_Vars+0x4c)
/*  f063844:	51d80009 */ 	beql	$t6,$t8,.L0f06386c
/*  f063848:	9218003f */ 	lbu	$t8,0x3f($s0)
/*  f06384c:	8fad0078 */ 	lw	$t5,0x78($sp)
/*  f063850:	c7b00074 */ 	lwc1	$f16,0x74($sp)
/*  f063854:	c7b20074 */ 	lwc1	$f18,0x74($sp)
/*  f063858:	ae390034 */ 	sw	$t9,0x34($s1)
/*  f06385c:	ae2d0038 */ 	sw	$t5,0x38($s1)
/*  f063860:	e6300044 */ 	swc1	$f16,0x44($s1)
/*  f063864:	e432a00c */ 	swc1	$f18,%lo(g_Vars+0x4c)($at)
/*  f063868:	9218003f */ 	lbu	$t8,0x3f($s0)
.L0f06386c:
/*  f06386c:	962f035c */ 	lhu	$t7,0x35c($s1)
/*  f063870:	a600003a */ 	sh	$zero,0x3a($s0)
/*  f063874:	37190040 */ 	ori	$t9,$t8,0x40
/*  f063878:	a219003f */ 	sb	$t9,0x3f($s0)
/*  f06387c:	a60f0038 */ 	sh	$t7,0x38($s0)
.L0f063880:
/*  f063880:	8fad008c */ 	lw	$t5,0x8c($sp)
.L0f063884:
/*  f063884:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f063888:	c7a40084 */ 	lwc1	$f4,0x84($sp)
/*  f06388c:	c7a60080 */ 	lwc1	$f6,0x80($sp)
/*  f063890:	24010005 */ 	addiu	$at,$zero,0x5
/*  f063894:	ae2d0034 */ 	sw	$t5,0x34($s1)
/*  f063898:	ae2f0038 */ 	sw	$t7,0x38($s1)
/*  f06389c:	e6240044 */ 	swc1	$f4,0x44($s1)
/*  f0638a0:	14c10003 */ 	bne	$a2,$at,.L0f0638b0
/*  f0638a4:	e626004c */ 	swc1	$f6,0x4c($s1)
/*  f0638a8:	1000001d */ 	b	.L0f063920
/*  f0638ac:	8fa2005c */ 	lw	$v0,0x5c($sp)
.L0f0638b0:
/*  f0638b0:	8e020020 */ 	lw	$v0,0x20($s0)
/*  f0638b4:	8e2e0354 */ 	lw	$t6,0x354($s1)
/*  f0638b8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0638bc:	00c02825 */ 	or	$a1,$a2,$zero
/*  f0638c0:	004ec026 */ 	xor	$t8,$v0,$t6
/*  f0638c4:	2f180001 */ 	sltiu	$t8,$t8,0x1
/*  f0638c8:	14d40012 */ 	bne	$a2,$s4,.L0f063914
/*  f0638cc:	afb8004c */ 	sw	$t8,0x4c($sp)
/*  f0638d0:	920f003f */ 	lbu	$t7,0x3f($s0)
/*  f0638d4:	3419ffff */ 	dli	$t9,0xffff
/*  f0638d8:	a6190038 */ 	sh	$t9,0x38($s0)
/*  f0638dc:	35ee0080 */ 	ori	$t6,$t7,0x80
/*  f0638e0:	a20e003f */ 	sb	$t6,0x3f($s0)
/*  f0638e4:	afa20060 */ 	sw	$v0,0x60($sp)
/*  f0638e8:	0fc18171 */ 	jal	propRemoveFromCurrentList
/*  f0638ec:	02002025 */ 	or	$a0,$s0,$zero
/*  f0638f0:	0fc1814e */ 	jal	propAppendToList1
/*  f0638f4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0638f8:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f0638fc:	8fa20060 */ 	lw	$v0,0x60($sp)
/*  f063900:	53000008 */ 	beqzl	$t8,.L0f063924
/*  f063904:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*  f063908:	02001025 */ 	or	$v0,$s0,$zero
/*  f06390c:	10000004 */ 	b	.L0f063920
/*  f063910:	afa0004c */ 	sw	$zero,0x4c($sp)
.L0f063914:
/*  f063914:	0fc18ad9 */ 	jal	func0f062b64
/*  f063918:	afa20060 */ 	sw	$v0,0x60($sp)
/*  f06391c:	8fa20060 */ 	lw	$v0,0x60($sp)
.L0f063920:
/*  f063920:	8fb9004c */ 	lw	$t9,0x4c($sp)
.L0f063924:
/*  f063924:	00408025 */ 	or	$s0,$v0,$zero
/*  f063928:	5320fe5f */ 	beqzl	$t9,.L0f0632a8
/*  f06392c:	8e0f0020 */ 	lw	$t7,0x20($s0)
/*  f063930:	8e2d0290 */ 	lw	$t5,0x290($s1)
/*  f063934:	8faa0034 */ 	lw	$t2,0x34($sp)
/*  f063938:	24140003 */ 	addiu	$s4,$zero,0x3
/*  f06393c:	15a00104 */ 	bnez	$t5,.L0f063d50
/*  f063940:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f063944:	922f035a */ 	lbu	$t7,0x35a($s1)
/*  f063948:	afaa0034 */ 	sw	$t2,0x34($sp)
/*  f06394c:	24087fff */ 	addiu	$t0,$zero,0x7fff
/*  f063950:	55e00100 */ 	bnezl	$t7,.L0f063d54
/*  f063954:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f063958:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f06395c:	00004825 */ 	or	$t1,$zero,$zero
/*  f063960:	00002825 */ 	or	$a1,$zero,$zero
/*  f063964:	01805025 */ 	or	$t2,$t4,$zero
/*  f063968:	318b00ff */ 	andi	$t3,$t4,0xff
/*  f06396c:	19800015 */ 	blez	$t4,.L0f0639c4
/*  f063970:	01803825 */ 	or	$a3,$t4,$zero
/*  f063974:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f063978:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
.L0f06397c:
/*  f06397c:	94430360 */ 	lhu	$v1,0x360($v0)
/*  f063980:	01202025 */ 	or	$a0,$t1,$zero
/*  f063984:	0068082a */ 	slt	$at,$v1,$t0
/*  f063988:	10200003 */ 	beqz	$at,.L0f063998
/*  f06398c:	00603025 */ 	or	$a2,$v1,$zero
/*  f063990:	3068ffff */ 	andi	$t0,$v1,0xffff
/*  f063994:	30aa00ff */ 	andi	$t2,$a1,0xff
.L0f063998:
/*  f063998:	0086082a */ 	slt	$at,$a0,$a2
/*  f06399c:	50200004 */ 	beqzl	$at,.L0f0639b0
/*  f0639a0:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0639a4:	3069ffff */ 	andi	$t1,$v1,0xffff
/*  f0639a8:	30ab00ff */ 	andi	$t3,$a1,0xff
/*  f0639ac:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f0639b0:
/*  f0639b0:	00a7082a */ 	slt	$at,$a1,$a3
/*  f0639b4:	1420fff1 */ 	bnez	$at,.L0f06397c
/*  f0639b8:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f0639bc:	24087fff */ 	addiu	$t0,$zero,0x7fff
/*  f0639c0:	00004825 */ 	or	$t1,$zero,$zero
.L0f0639c4:
/*  f0639c4:	2403001c */ 	addiu	$v1,$zero,0x1c
/*  f0639c8:	01630019 */ 	multu	$t3,$v1
/*  f0639cc:	00007012 */ 	mflo	$t6
/*  f0639d0:	022ec021 */ 	addu	$t8,$s1,$t6
/*  f0639d4:	97190360 */ 	lhu	$t9,0x360($t8)
/*  f0639d8:	01430019 */ 	multu	$t2,$v1
/*  f0639dc:	00006812 */ 	mflo	$t5
/*  f0639e0:	022d7821 */ 	addu	$t7,$s1,$t5
/*  f0639e4:	95ee0360 */ 	lhu	$t6,0x360($t7)
/*  f0639e8:	032e2823 */ 	subu	$a1,$t9,$t6
/*  f0639ec:	0005c043 */ 	sra	$t8,$a1,0x1
/*  f0639f0:	1300001d */ 	beqz	$t8,.L0f063a68
/*  f0639f4:	03002825 */ 	or	$a1,$t8,$zero
/*  f0639f8:	8e30033c */ 	lw	$s0,0x33c($s1)
/*  f0639fc:	8e2d0354 */ 	lw	$t5,0x354($s1)
/*  f063a00:	01601025 */ 	or	$v0,$t3,$zero
/*  f063a04:	520d0019 */ 	beql	$s0,$t5,.L0f063a6c
/*  f063a08:	318a00ff */ 	andi	$t2,$t4,0xff
/*  f063a0c:	920f003d */ 	lbu	$t7,0x3d($s0)
.L0f063a10:
/*  f063a10:	544f0010 */ 	bnel	$v0,$t7,.L0f063a54
/*  f063a14:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063a18:	8e19003c */ 	lw	$t9,0x3c($s0)
/*  f063a1c:	00197640 */ 	sll	$t6,$t9,0x19
/*  f063a20:	000ec7c2 */ 	srl	$t8,$t6,0x1f
/*  f063a24:	56b8000b */ 	bnel	$s5,$t8,.L0f063a54
/*  f063a28:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063a2c:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f063a30:	528d0008 */ 	beql	$s4,$t5,.L0f063a54
/*  f063a34:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063a38:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f063a3c:	14a00004 */ 	bnez	$a1,.L0f063a50
/*  f063a40:	a20a003d */ 	sb	$t2,0x3d($s0)
/*  f063a44:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f063a48:	10000007 */ 	b	.L0f063a68
/*  f063a4c:	01803825 */ 	or	$a3,$t4,$zero
.L0f063a50:
/*  f063a50:	8e100020 */ 	lw	$s0,0x20($s0)
.L0f063a54:
/*  f063a54:	8e2f0354 */ 	lw	$t7,0x354($s1)
/*  f063a58:	560fffed */ 	bnel	$s0,$t7,.L0f063a10
/*  f063a5c:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f063a60:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f063a64:	01803825 */ 	or	$a3,$t4,$zero
.L0f063a68:
/*  f063a68:	318a00ff */ 	andi	$t2,$t4,0xff
.L0f063a6c:
/*  f063a6c:	318b00ff */ 	andi	$t3,$t4,0xff
/*  f063a70:	18e00016 */ 	blez	$a3,.L0f063acc
/*  f063a74:	00002825 */ 	or	$a1,$zero,$zero
/*  f063a78:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f063a7c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
.L0f063a80:
/*  f063a80:	94430364 */ 	lhu	$v1,0x364($v0)
/*  f063a84:	01202025 */ 	or	$a0,$t1,$zero
/*  f063a88:	0068082a */ 	slt	$at,$v1,$t0
/*  f063a8c:	10200003 */ 	beqz	$at,.L0f063a9c
/*  f063a90:	00603025 */ 	or	$a2,$v1,$zero
/*  f063a94:	3068ffff */ 	andi	$t0,$v1,0xffff
/*  f063a98:	30aa00ff */ 	andi	$t2,$a1,0xff
.L0f063a9c:
/*  f063a9c:	0086082a */ 	slt	$at,$a0,$a2
/*  f063aa0:	50200004 */ 	beqzl	$at,.L0f063ab4
/*  f063aa4:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f063aa8:	3069ffff */ 	andi	$t1,$v1,0xffff
/*  f063aac:	30ab00ff */ 	andi	$t3,$a1,0xff
/*  f063ab0:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f063ab4:
/*  f063ab4:	00a7082a */ 	slt	$at,$a1,$a3
/*  f063ab8:	1420fff1 */ 	bnez	$at,.L0f063a80
/*  f063abc:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f063ac0:	24087fff */ 	addiu	$t0,$zero,0x7fff
/*  f063ac4:	00004825 */ 	or	$t1,$zero,$zero
/*  f063ac8:	2403001c */ 	addiu	$v1,$zero,0x1c
.L0f063acc:
/*  f063acc:	01630019 */ 	multu	$t3,$v1
/*  f063ad0:	0000c812 */ 	mflo	$t9
/*  f063ad4:	02397021 */ 	addu	$t6,$s1,$t9
/*  f063ad8:	95d80364 */ 	lhu	$t8,0x364($t6)
/*  f063adc:	01430019 */ 	multu	$t2,$v1
/*  f063ae0:	00006812 */ 	mflo	$t5
/*  f063ae4:	022d7821 */ 	addu	$t7,$s1,$t5
/*  f063ae8:	95f90364 */ 	lhu	$t9,0x364($t7)
/*  f063aec:	03192823 */ 	subu	$a1,$t8,$t9
/*  f063af0:	00057043 */ 	sra	$t6,$a1,0x1
/*  f063af4:	11c0001c */ 	beqz	$t6,.L0f063b68
/*  f063af8:	01c02825 */ 	or	$a1,$t6,$zero
/*  f063afc:	8e30033c */ 	lw	$s0,0x33c($s1)
/*  f063b00:	8e2d0354 */ 	lw	$t5,0x354($s1)
/*  f063b04:	01601025 */ 	or	$v0,$t3,$zero
/*  f063b08:	520d0018 */ 	beql	$s0,$t5,.L0f063b6c
/*  f063b0c:	318a00ff */ 	andi	$t2,$t4,0xff
/*  f063b10:	920f003d */ 	lbu	$t7,0x3d($s0)
.L0f063b14:
/*  f063b14:	544f000f */ 	bnel	$v0,$t7,.L0f063b54
/*  f063b18:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063b1c:	8e18003c */ 	lw	$t8,0x3c($s0)
/*  f063b20:	00187640 */ 	sll	$t6,$t8,0x19
/*  f063b24:	05c2000b */ 	bltzl	$t6,.L0f063b54
/*  f063b28:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063b2c:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f063b30:	528d0008 */ 	beql	$s4,$t5,.L0f063b54
/*  f063b34:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063b38:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f063b3c:	14a00004 */ 	bnez	$a1,.L0f063b50
/*  f063b40:	a20a003d */ 	sb	$t2,0x3d($s0)
/*  f063b44:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f063b48:	10000007 */ 	b	.L0f063b68
/*  f063b4c:	01803825 */ 	or	$a3,$t4,$zero
.L0f063b50:
/*  f063b50:	8e100020 */ 	lw	$s0,0x20($s0)
.L0f063b54:
/*  f063b54:	8e2f0354 */ 	lw	$t7,0x354($s1)
/*  f063b58:	560fffee */ 	bnel	$s0,$t7,.L0f063b14
/*  f063b5c:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f063b60:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f063b64:	01803825 */ 	or	$a3,$t4,$zero
.L0f063b68:
/*  f063b68:	318a00ff */ 	andi	$t2,$t4,0xff
.L0f063b6c:
/*  f063b6c:	318b00ff */ 	andi	$t3,$t4,0xff
/*  f063b70:	18e00016 */ 	blez	$a3,.L0f063bcc
/*  f063b74:	00002825 */ 	or	$a1,$zero,$zero
/*  f063b78:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f063b7c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
.L0f063b80:
/*  f063b80:	94430362 */ 	lhu	$v1,0x362($v0)
/*  f063b84:	01202025 */ 	or	$a0,$t1,$zero
/*  f063b88:	0068082a */ 	slt	$at,$v1,$t0
/*  f063b8c:	10200003 */ 	beqz	$at,.L0f063b9c
/*  f063b90:	00603025 */ 	or	$a2,$v1,$zero
/*  f063b94:	3068ffff */ 	andi	$t0,$v1,0xffff
/*  f063b98:	30aa00ff */ 	andi	$t2,$a1,0xff
.L0f063b9c:
/*  f063b9c:	0086082a */ 	slt	$at,$a0,$a2
/*  f063ba0:	50200004 */ 	beqzl	$at,.L0f063bb4
/*  f063ba4:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f063ba8:	3069ffff */ 	andi	$t1,$v1,0xffff
/*  f063bac:	30ab00ff */ 	andi	$t3,$a1,0xff
/*  f063bb0:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f063bb4:
/*  f063bb4:	00a7082a */ 	slt	$at,$a1,$a3
/*  f063bb8:	1420fff1 */ 	bnez	$at,.L0f063b80
/*  f063bbc:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f063bc0:	24087fff */ 	addiu	$t0,$zero,0x7fff
/*  f063bc4:	00004825 */ 	or	$t1,$zero,$zero
/*  f063bc8:	2403001c */ 	addiu	$v1,$zero,0x1c
.L0f063bcc:
/*  f063bcc:	01630019 */ 	multu	$t3,$v1
/*  f063bd0:	0000c012 */ 	mflo	$t8
/*  f063bd4:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f063bd8:	972e0362 */ 	lhu	$t6,0x362($t9)
/*  f063bdc:	01430019 */ 	multu	$t2,$v1
/*  f063be0:	00006812 */ 	mflo	$t5
/*  f063be4:	022d7821 */ 	addu	$t7,$s1,$t5
/*  f063be8:	95f80362 */ 	lhu	$t8,0x362($t7)
/*  f063bec:	01d82823 */ 	subu	$a1,$t6,$t8
/*  f063bf0:	0005c843 */ 	sra	$t9,$a1,0x1
/*  f063bf4:	1320001d */ 	beqz	$t9,.L0f063c6c
/*  f063bf8:	03202825 */ 	or	$a1,$t9,$zero
/*  f063bfc:	8e30033c */ 	lw	$s0,0x33c($s1)
/*  f063c00:	8e2d0354 */ 	lw	$t5,0x354($s1)
/*  f063c04:	01601025 */ 	or	$v0,$t3,$zero
/*  f063c08:	520d0019 */ 	beql	$s0,$t5,.L0f063c70
/*  f063c0c:	318a00ff */ 	andi	$t2,$t4,0xff
/*  f063c10:	920f003d */ 	lbu	$t7,0x3d($s0)
.L0f063c14:
/*  f063c14:	544f0010 */ 	bnel	$v0,$t7,.L0f063c58
/*  f063c18:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063c1c:	8e0e003c */ 	lw	$t6,0x3c($s0)
/*  f063c20:	000ec640 */ 	sll	$t8,$t6,0x19
/*  f063c24:	0018cfc2 */ 	srl	$t9,$t8,0x1f
/*  f063c28:	56b9000b */ 	bnel	$s5,$t9,.L0f063c58
/*  f063c2c:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063c30:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f063c34:	568d0008 */ 	bnel	$s4,$t5,.L0f063c58
/*  f063c38:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063c3c:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f063c40:	14a00004 */ 	bnez	$a1,.L0f063c54
/*  f063c44:	a20a003d */ 	sb	$t2,0x3d($s0)
/*  f063c48:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f063c4c:	10000007 */ 	b	.L0f063c6c
/*  f063c50:	01803825 */ 	or	$a3,$t4,$zero
.L0f063c54:
/*  f063c54:	8e100020 */ 	lw	$s0,0x20($s0)
.L0f063c58:
/*  f063c58:	8e2f0354 */ 	lw	$t7,0x354($s1)
/*  f063c5c:	560fffed */ 	bnel	$s0,$t7,.L0f063c14
/*  f063c60:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f063c64:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f063c68:	01803825 */ 	or	$a3,$t4,$zero
.L0f063c6c:
/*  f063c6c:	318a00ff */ 	andi	$t2,$t4,0xff
.L0f063c70:
/*  f063c70:	318b00ff */ 	andi	$t3,$t4,0xff
/*  f063c74:	18e00014 */ 	blez	$a3,.L0f063cc8
/*  f063c78:	00002825 */ 	or	$a1,$zero,$zero
/*  f063c7c:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f063c80:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
.L0f063c84:
/*  f063c84:	94430366 */ 	lhu	$v1,0x366($v0)
/*  f063c88:	01202025 */ 	or	$a0,$t1,$zero
/*  f063c8c:	0068082a */ 	slt	$at,$v1,$t0
/*  f063c90:	10200003 */ 	beqz	$at,.L0f063ca0
/*  f063c94:	00603025 */ 	or	$a2,$v1,$zero
/*  f063c98:	3068ffff */ 	andi	$t0,$v1,0xffff
/*  f063c9c:	30aa00ff */ 	andi	$t2,$a1,0xff
.L0f063ca0:
/*  f063ca0:	0086082a */ 	slt	$at,$a0,$a2
/*  f063ca4:	50200004 */ 	beqzl	$at,.L0f063cb8
/*  f063ca8:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f063cac:	3069ffff */ 	andi	$t1,$v1,0xffff
/*  f063cb0:	30ab00ff */ 	andi	$t3,$a1,0xff
/*  f063cb4:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f063cb8:
/*  f063cb8:	00a7082a */ 	slt	$at,$a1,$a3
/*  f063cbc:	1420fff1 */ 	bnez	$at,.L0f063c84
/*  f063cc0:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f063cc4:	2403001c */ 	addiu	$v1,$zero,0x1c
.L0f063cc8:
/*  f063cc8:	01630019 */ 	multu	$t3,$v1
/*  f063ccc:	00007012 */ 	mflo	$t6
/*  f063cd0:	022ec021 */ 	addu	$t8,$s1,$t6
/*  f063cd4:	97190366 */ 	lhu	$t9,0x366($t8)
/*  f063cd8:	01430019 */ 	multu	$t2,$v1
/*  f063cdc:	00006812 */ 	mflo	$t5
/*  f063ce0:	022d7821 */ 	addu	$t7,$s1,$t5
/*  f063ce4:	95ee0366 */ 	lhu	$t6,0x366($t7)
/*  f063ce8:	032e2823 */ 	subu	$a1,$t9,$t6
/*  f063cec:	0005c043 */ 	sra	$t8,$a1,0x1
/*  f063cf0:	13000017 */ 	beqz	$t8,.L0f063d50
/*  f063cf4:	03002825 */ 	or	$a1,$t8,$zero
/*  f063cf8:	8e30033c */ 	lw	$s0,0x33c($s1)
/*  f063cfc:	8e2d0354 */ 	lw	$t5,0x354($s1)
/*  f063d00:	01601025 */ 	or	$v0,$t3,$zero
/*  f063d04:	520d0013 */ 	beql	$s0,$t5,.L0f063d54
/*  f063d08:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f063d0c:	920f003d */ 	lbu	$t7,0x3d($s0)
.L0f063d10:
/*  f063d10:	544f000c */ 	bnel	$v0,$t7,.L0f063d44
/*  f063d14:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063d18:	8e19003c */ 	lw	$t9,0x3c($s0)
/*  f063d1c:	0019c640 */ 	sll	$t8,$t9,0x19
/*  f063d20:	07020008 */ 	bltzl	$t8,.L0f063d44
/*  f063d24:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063d28:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f063d2c:	568d0005 */ 	bnel	$s4,$t5,.L0f063d44
/*  f063d30:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063d34:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f063d38:	10a00005 */ 	beqz	$a1,.L0f063d50
/*  f063d3c:	a20a003d */ 	sb	$t2,0x3d($s0)
/*  f063d40:	8e100020 */ 	lw	$s0,0x20($s0)
.L0f063d44:
/*  f063d44:	8e2f0354 */ 	lw	$t7,0x354($s1)
/*  f063d48:	560ffff1 */ 	bnel	$s0,$t7,.L0f063d10
/*  f063d4c:	920f003d */ 	lbu	$t7,0x3d($s0)
.L0f063d50:
/*  f063d50:	8fb9008c */ 	lw	$t9,0x8c($sp)
.L0f063d54:
/*  f063d54:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f063d58:	c7a80084 */ 	lwc1	$f8,0x84($sp)
/*  f063d5c:	c7aa0080 */ 	lwc1	$f10,0x80($sp)
/*  f063d60:	8faa0034 */ 	lw	$t2,0x34($sp)
/*  f063d64:	ae390034 */ 	sw	$t9,0x34($s1)
/*  f063d68:	ae2e0038 */ 	sw	$t6,0x38($s1)
/*  f063d6c:	e6280044 */ 	swc1	$f8,0x44($s1)
/*  f063d70:	e62a004c */ 	swc1	$f10,0x4c($s1)
/*  f063d74:	8fad0098 */ 	lw	$t5,0x98($sp)
/*  f063d78:	ad400370 */ 	sw	$zero,0x370($t2)
/*  f063d7c:	9638035c */ 	lhu	$t8,0x35c($s1)
/*  f063d80:	11a00007 */ 	beqz	$t5,.L0f063da0
/*  f063d84:	a5580378 */ 	sh	$t8,0x378($t2)
/*  f063d88:	0fc2436d */ 	jal	alarmTick
/*  f063d8c:	00000000 */ 	nop
/*  f063d90:	0fc24d42 */ 	jal	func0f093508
/*  f063d94:	00000000 */ 	nop
/*  f063d98:	0fc19815 */ 	jal	func0f066054
/*  f063d9c:	00000000 */ 	nop
.L0f063da0:
/*  f063da0:	0fc091cb */ 	jal	func0f02472c
/*  f063da4:	00000000 */ 	nop
/*  f063da8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f063dac:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f063db0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f063db4:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f063db8:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f063dbc:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f063dc0:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f063dc4:	03e00008 */ 	jr	$ra
/*  f063dc8:	27bd0098 */ 	addiu	$sp,$sp,0x98
);

GLOBAL_ASM(
glabel func0f063dcc
.late_rodata
glabel var7f1a9f18
.word func0f063dcc+0xa8 # f063e74
glabel var7f1a9f1c
.word func0f063dcc+0x364 # f064130
glabel var7f1a9f20
.word func0f063dcc+0x2fc # f0640c8
glabel var7f1a9f24
.word func0f063dcc+0xa8 # f063e74
glabel var7f1a9f28
.word func0f063dcc+0x2fc # f0640c8
glabel var7f1a9f2c
.word func0f063dcc+0x2d4 # f0640a0
.text
/*  f063dcc:	27bdff08 */ 	addiu	$sp,$sp,-248
/*  f063dd0:	3c028007 */ 	lui	$v0,%hi(var80069964)
/*  f063dd4:	8c429964 */ 	lw	$v0,%lo(var80069964)($v0)
/*  f063dd8:	afbf006c */ 	sw	$ra,0x6c($sp)
/*  f063ddc:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f063de0:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f063de4:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f063de8:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f063dec:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f063df0:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f063df4:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f063df8:	044000d4 */ 	bltz	$v0,.L0f06414c
/*  f063dfc:	f7b40048 */ 	sdc1	$f20,0x48($sp)
/*  f063e00:	044000d2 */ 	bltz	$v0,.L0f06414c
/*  f063e04:	0000b025 */ 	or	$s6,$zero,$zero
/*  f063e08:	3c01bf80 */ 	lui	$at,0xbf80
/*  f063e0c:	4481a000 */ 	mtc1	$at,$f20
/*  f063e10:	0000a025 */ 	or	$s4,$zero,$zero
/*  f063e14:	27b5008c */ 	addiu	$s5,$sp,0x8c
/*  f063e18:	27b300b8 */ 	addiu	$s3,$sp,0xb8
/*  f063e1c:	27b20090 */ 	addiu	$s2,$sp,0x90
/*  f063e20:	27b100a0 */ 	addiu	$s1,$sp,0xa0
.L0f063e24:
/*  f063e24:	3c0e8007 */ 	lui	$t6,%hi(var80069960)
/*  f063e28:	8dce9960 */ 	lw	$t6,%lo(var80069960)($t6)
/*  f063e2c:	24050040 */ 	addiu	$a1,$zero,0x40
/*  f063e30:	02203025 */ 	or	$a2,$s1,$zero
/*  f063e34:	028e8021 */ 	addu	$s0,$s4,$t6
/*  f063e38:	0fc456ac */ 	jal	padUnpack
/*  f063e3c:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f063e40:	0fc575ba */ 	jal	roomIsVisibleByAnyPlayer
/*  f063e44:	8fa400e8 */ 	lw	$a0,0xe8($sp)
/*  f063e48:	104000b9 */ 	beqz	$v0,.L0f064130
/*  f063e4c:	00000000 */ 	nop
/*  f063e50:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f063e54:	2c410006 */ 	sltiu	$at,$v0,0x6
/*  f063e58:	102000b5 */ 	beqz	$at,.L0f064130
/*  f063e5c:	00027880 */ 	sll	$t7,$v0,0x2
/*  f063e60:	3c017f1b */ 	lui	$at,%hi(var7f1a9f18)
/*  f063e64:	002f0821 */ 	addu	$at,$at,$t7
/*  f063e68:	8c2f9f18 */ 	lw	$t7,%lo(var7f1a9f18)($at)
/*  f063e6c:	01e00008 */ 	jr	$t7
/*  f063e70:	00000000 */ 	nop
/*  f063e74:	8fb800e8 */ 	lw	$t8,0xe8($sp)
/*  f063e78:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f063e7c:	a7b9008e */ 	sh	$t9,0x8e($sp)
/*  f063e80:	a7b8008c */ 	sh	$t8,0x8c($sp)
/*  f063e84:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f063e88:	2405000a */ 	addiu	$a1,$zero,0xa
/*  f063e8c:	0fc456ac */ 	jal	padUnpack
/*  f063e90:	02203025 */ 	or	$a2,$s1,$zero
/*  f063e94:	c7a400b8 */ 	lwc1	$f4,0xb8($sp)
/*  f063e98:	c7a800bc */ 	lwc1	$f8,0xbc($sp)
/*  f063e9c:	c7b000c0 */ 	lwc1	$f16,0xc0($sp)
/*  f063ea0:	46002187 */ 	neg.s	$f6,$f4
/*  f063ea4:	46004287 */ 	neg.s	$f10,$f8
/*  f063ea8:	46008487 */ 	neg.s	$f18,$f16
/*  f063eac:	e7a60090 */ 	swc1	$f6,0x90($sp)
/*  f063eb0:	e7aa0094 */ 	swc1	$f10,0x94($sp)
/*  f063eb4:	0c004b70 */ 	jal	random
/*  f063eb8:	e7b20098 */ 	swc1	$f18,0x98($sp)
/*  f063ebc:	304907ff */ 	andi	$t1,$v0,0x7ff
/*  f063ec0:	2d210033 */ 	sltiu	$at,$t1,0x33
/*  f063ec4:	1020001e */ 	beqz	$at,.L0f063f40
/*  f063ec8:	87a4008c */ 	lh	$a0,0x8c($sp)
/*  f063ecc:	240a0009 */ 	addiu	$t2,$zero,0x9
/*  f063ed0:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f063ed4:	00002825 */ 	or	$a1,$zero,$zero
/*  f063ed8:	02203025 */ 	or	$a2,$s1,$zero
/*  f063edc:	02403825 */ 	or	$a3,$s2,$zero
/*  f063ee0:	0fc4be7c */ 	jal	sparksCreate
/*  f063ee4:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f063ee8:	0fc25480 */ 	jal	func0f095200
/*  f063eec:	00000000 */ 	nop
/*  f063ef0:	00023400 */ 	sll	$a2,$v0,0x10
/*  f063ef4:	00065c03 */ 	sra	$t3,$a2,0x10
/*  f063ef8:	240cffff */ 	addiu	$t4,$zero,-1
/*  f063efc:	240dffff */ 	addiu	$t5,$zero,-1
/*  f063f00:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f063f04:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f063f08:	01603025 */ 	or	$a2,$t3,$zero
/*  f063f0c:	00002025 */ 	or	$a0,$zero,$zero
/*  f063f10:	00002825 */ 	or	$a1,$zero,$zero
/*  f063f14:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f063f18:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f063f1c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f063f20:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f063f24:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f063f28:	e7b40024 */ 	swc1	$f20,0x24($sp)
/*  f063f2c:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f063f30:	e7b40030 */ 	swc1	$f20,0x30($sp)
/*  f063f34:	e7b40034 */ 	swc1	$f20,0x34($sp)
/*  f063f38:	0fc24e7e */ 	jal	func0f0939f8
/*  f063f3c:	e7b40038 */ 	swc1	$f20,0x38($sp)
.L0f063f40:
/*  f063f40:	0c004b70 */ 	jal	random
/*  f063f44:	00000000 */ 	nop
/*  f063f48:	304e07ff */ 	andi	$t6,$v0,0x7ff
/*  f063f4c:	2dc10010 */ 	sltiu	$at,$t6,0x10
/*  f063f50:	10200026 */ 	beqz	$at,.L0f063fec
/*  f063f54:	87a4008c */ 	lh	$a0,0x8c($sp)
/*  f063f58:	240f0009 */ 	addiu	$t7,$zero,0x9
/*  f063f5c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f063f60:	00002825 */ 	or	$a1,$zero,$zero
/*  f063f64:	02203025 */ 	or	$a2,$s1,$zero
/*  f063f68:	02403825 */ 	or	$a3,$s2,$zero
/*  f063f6c:	0fc4be7c */ 	jal	sparksCreate
/*  f063f70:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f063f74:	2418000a */ 	addiu	$t8,$zero,0xa
/*  f063f78:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f063f7c:	87a4008c */ 	lh	$a0,0x8c($sp)
/*  f063f80:	00002825 */ 	or	$a1,$zero,$zero
/*  f063f84:	02203025 */ 	or	$a2,$s1,$zero
/*  f063f88:	02403825 */ 	or	$a3,$s2,$zero
/*  f063f8c:	0fc4be7c */ 	jal	sparksCreate
/*  f063f90:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f063f94:	0fc25480 */ 	jal	func0f095200
/*  f063f98:	00000000 */ 	nop
/*  f063f9c:	00023400 */ 	sll	$a2,$v0,0x10
/*  f063fa0:	0006cc03 */ 	sra	$t9,$a2,0x10
/*  f063fa4:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f063fa8:	240affff */ 	addiu	$t2,$zero,-1
/*  f063fac:	afaa002c */ 	sw	$t2,0x2c($sp)
/*  f063fb0:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f063fb4:	03203025 */ 	or	$a2,$t9,$zero
/*  f063fb8:	00002025 */ 	or	$a0,$zero,$zero
/*  f063fbc:	00002825 */ 	or	$a1,$zero,$zero
/*  f063fc0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f063fc4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f063fc8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f063fcc:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f063fd0:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f063fd4:	e7b40024 */ 	swc1	$f20,0x24($sp)
/*  f063fd8:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f063fdc:	e7b40030 */ 	swc1	$f20,0x30($sp)
/*  f063fe0:	e7b40034 */ 	swc1	$f20,0x34($sp)
/*  f063fe4:	0fc24e7e */ 	jal	func0f0939f8
/*  f063fe8:	e7b40038 */ 	swc1	$f20,0x38($sp)
.L0f063fec:
/*  f063fec:	0c004b70 */ 	jal	random
/*  f063ff0:	00000000 */ 	nop
/*  f063ff4:	304b07ff */ 	andi	$t3,$v0,0x7ff
/*  f063ff8:	2d610006 */ 	sltiu	$at,$t3,0x6
/*  f063ffc:	1020004c */ 	beqz	$at,.L0f064130
/*  f064000:	87a4008c */ 	lh	$a0,0x8c($sp)
/*  f064004:	240c0009 */ 	addiu	$t4,$zero,0x9
/*  f064008:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f06400c:	00002825 */ 	or	$a1,$zero,$zero
/*  f064010:	02203025 */ 	or	$a2,$s1,$zero
/*  f064014:	02403825 */ 	or	$a3,$s2,$zero
/*  f064018:	0fc4be7c */ 	jal	sparksCreate
/*  f06401c:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f064020:	240d000b */ 	addiu	$t5,$zero,0xb
/*  f064024:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f064028:	87a4008c */ 	lh	$a0,0x8c($sp)
/*  f06402c:	00002825 */ 	or	$a1,$zero,$zero
/*  f064030:	02203025 */ 	or	$a2,$s1,$zero
/*  f064034:	02403825 */ 	or	$a3,$s2,$zero
/*  f064038:	0fc4be7c */ 	jal	sparksCreate
/*  f06403c:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f064040:	0fc25480 */ 	jal	func0f095200
/*  f064044:	00000000 */ 	nop
/*  f064048:	00023400 */ 	sll	$a2,$v0,0x10
/*  f06404c:	00067403 */ 	sra	$t6,$a2,0x10
/*  f064050:	240fffff */ 	addiu	$t7,$zero,-1
/*  f064054:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f064058:	afb8002c */ 	sw	$t8,0x2c($sp)
/*  f06405c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f064060:	01c03025 */ 	or	$a2,$t6,$zero
/*  f064064:	00002025 */ 	or	$a0,$zero,$zero
/*  f064068:	00002825 */ 	or	$a1,$zero,$zero
/*  f06406c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f064070:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f064074:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f064078:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f06407c:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f064080:	e7b40024 */ 	swc1	$f20,0x24($sp)
/*  f064084:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f064088:	e7b40030 */ 	swc1	$f20,0x30($sp)
/*  f06408c:	e7b40034 */ 	swc1	$f20,0x34($sp)
/*  f064090:	0fc24e7e */ 	jal	func0f0939f8
/*  f064094:	e7b40038 */ 	swc1	$f20,0x38($sp)
/*  f064098:	10000025 */ 	b	.L0f064130
/*  f06409c:	00000000 */ 	nop
/*  f0640a0:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x2ac)
/*  f0640a4:	8f39a26c */ 	lw	$t9,%lo(g_Vars+0x2ac)($t9)
/*  f0640a8:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0640ac:	57210028 */ 	bnel	$t9,$at,.L0f064150
/*  f0640b0:	8fbf006c */ 	lw	$ra,0x6c($sp)
/*  f0640b4:	0fc256d9 */ 	jal	objectiveIsAllComplete
/*  f0640b8:	00000000 */ 	nop
/*  f0640bc:	50400024 */ 	beqzl	$v0,.L0f064150
/*  f0640c0:	8fbf006c */ 	lw	$ra,0x6c($sp)
/*  f0640c4:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f0640c8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0640cc:	10410007 */ 	beq	$v0,$at,.L0f0640ec
/*  f0640d0:	24080014 */ 	addiu	$t0,$zero,0x14
/*  f0640d4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0640d8:	10410003 */ 	beq	$v0,$at,.L0f0640e8
/*  f0640dc:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0640e0:	54410003 */ 	bnel	$v0,$at,.L0f0640f0
/*  f0640e4:	8fa900e8 */ 	lw	$t1,0xe8($sp)
.L0f0640e8:
/*  f0640e8:	24080015 */ 	addiu	$t0,$zero,0x15
.L0f0640ec:
/*  f0640ec:	8fa900e8 */ 	lw	$t1,0xe8($sp)
.L0f0640f0:
/*  f0640f0:	240affff */ 	addiu	$t2,$zero,-1
/*  f0640f4:	a7aa008a */ 	sh	$t2,0x8a($sp)
/*  f0640f8:	a7a90088 */ 	sh	$t1,0x88($sp)
/*  f0640fc:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f064100:	afa80084 */ 	sw	$t0,0x84($sp)
/*  f064104:	2405000a */ 	addiu	$a1,$zero,0xa
/*  f064108:	0fc456ac */ 	jal	padUnpack
/*  f06410c:	02203025 */ 	or	$a2,$s1,$zero
/*  f064110:	8fa80084 */ 	lw	$t0,0x84($sp)
/*  f064114:	02002025 */ 	or	$a0,$s0,$zero
/*  f064118:	02202825 */ 	or	$a1,$s1,$zero
/*  f06411c:	00083c00 */ 	sll	$a3,$t0,0x10
/*  f064120:	00075c03 */ 	sra	$t3,$a3,0x10
/*  f064124:	01603825 */ 	or	$a3,$t3,$zero
/*  f064128:	0fc4b9d3 */ 	jal	func0f12e74c
/*  f06412c:	27a60088 */ 	addiu	$a2,$sp,0x88
.L0f064130:
/*  f064130:	3c0c8007 */ 	lui	$t4,%hi(var80069964)
/*  f064134:	8d8c9964 */ 	lw	$t4,%lo(var80069964)($t4)
/*  f064138:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f06413c:	2694000c */ 	addiu	$s4,$s4,0xc
/*  f064140:	0196082a */ 	slt	$at,$t4,$s6
/*  f064144:	1020ff37 */ 	beqz	$at,.L0f063e24
/*  f064148:	00000000 */ 	nop
.L0f06414c:
/*  f06414c:	8fbf006c */ 	lw	$ra,0x6c($sp)
.L0f064150:
/*  f064150:	d7b40048 */ 	ldc1	$f20,0x48($sp)
/*  f064154:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f064158:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f06415c:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f064160:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f064164:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f064168:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f06416c:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f064170:	03e00008 */ 	jr	$ra
/*  f064174:	27bd00f8 */ 	addiu	$sp,$sp,0xf8
);

void func0f064178(struct prop *prop, s32 enable)
{
	if (prop->type == PROPTYPE_CHR) {
		chrSetOrUnsetHiddenFlag00000100(prop->chr, enable);
	} else if (prop->type == PROPTYPE_PLAYER) {
		func0f0c1e54(prop, enable);
	} else if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_DOOR || prop->type == PROPTYPE_WEAPON) {
		propObjSetOrUnsetHiddenFlag00400000(prop, enable);
	}
}

GLOBAL_ASM(
glabel func0f0641f4
.late_rodata
glabel var7f1a9f30
.word func0f0641f4+0x144 # f064338
glabel var7f1a9f34
.word func0f0641f4+0x160 # f064354
glabel var7f1a9f38
.word func0f0641f4+0x160 # f064354
glabel var7f1a9f3c
.word func0f0641f4+0x154 # f064348
glabel var7f1a9f40
.word func0f0641f4+0x160 # f064354
glabel var7f1a9f44
.word func0f0641f4+0x160 # f064354
glabel var7f1a9f48
.word func0f0641f4+0x160 # f064354
glabel var7f1a9f4c
.word func0f0641f4+0x160 # f064354
.text
/*  f0641f4:	27bdfd70 */ 	addiu	$sp,$sp,-656
/*  f0641f8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0641fc:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f064200:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f064204:	8e820284 */ 	lw	$v0,0x284($s4)
/*  f064208:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f06420c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f064210:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f064214:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f064218:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f06421c:	8c4e01b0 */ 	lw	$t6,0x1b0($v0)
/*  f064220:	24010005 */ 	addiu	$at,$zero,0x5
/*  f064224:	3c0f8007 */ 	lui	$t7,%hi(g_PlayerInvincible)
/*  f064228:	51c10051 */ 	beql	$t6,$at,.L0f064370
/*  f06422c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f064230:	8def0760 */ 	lw	$t7,%lo(g_PlayerInvincible)($t7)
/*  f064234:	55e0004e */ 	bnezl	$t7,.L0f064370
/*  f064238:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f06423c:	8e9802a8 */ 	lw	$t8,0x2a8($s4)
/*  f064240:	27b3005c */ 	addiu	$s3,$sp,0x5c
/*  f064244:	5302004a */ 	beql	$t8,$v0,.L0f064370
/*  f064248:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f06424c:	8c4400bc */ 	lw	$a0,0xbc($v0)
/*  f064250:	02602825 */ 	or	$a1,$s3,$zero
/*  f064254:	0fc195e9 */ 	jal	roomsCopy
/*  f064258:	24840028 */ 	addiu	$a0,$a0,0x28
/*  f06425c:	8e990284 */ 	lw	$t9,0x284($s4)
/*  f064260:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f064264:	00008025 */ 	or	$s0,$zero,$zero
/*  f064268:	8f2200bc */ 	lw	$v0,0xbc($t9)
/*  f06426c:	27b10044 */ 	addiu	$s1,$sp,0x44
/*  f064270:	84480028 */ 	lh	$t0,0x28($v0)
/*  f064274:	52480011 */ 	beql	$s2,$t0,.L0f0642bc
/*  f064278:	27b00088 */ 	addiu	$s0,$sp,0x88
/*  f06427c:	84440028 */ 	lh	$a0,0x28($v0)
/*  f064280:	02202825 */ 	or	$a1,$s1,$zero
.L0f064284:
/*  f064284:	0fc5916a */ 	jal	func0f1645a8
/*  f064288:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f06428c:	02202025 */ 	or	$a0,$s1,$zero
/*  f064290:	02602825 */ 	or	$a1,$s3,$zero
/*  f064294:	0fc195f6 */ 	jal	func0f0657d8
/*  f064298:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f06429c:	8e890284 */ 	lw	$t1,0x284($s4)
/*  f0642a0:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f0642a4:	8d2a00bc */ 	lw	$t2,0xbc($t1)
/*  f0642a8:	01505821 */ 	addu	$t3,$t2,$s0
/*  f0642ac:	85640028 */ 	lh	$a0,0x28($t3)
/*  f0642b0:	5644fff4 */ 	bnel	$s2,$a0,.L0f064284
/*  f0642b4:	02202825 */ 	or	$a1,$s1,$zero
/*  f0642b8:	27b00088 */ 	addiu	$s0,$sp,0x88
.L0f0642bc:
/*  f0642bc:	02002825 */ 	or	$a1,$s0,$zero
/*  f0642c0:	02602025 */ 	or	$a0,$s3,$zero
/*  f0642c4:	0fc197e0 */ 	jal	roomGetProps
/*  f0642c8:	24060100 */ 	addiu	$a2,$zero,0x100
/*  f0642cc:	87ac0088 */ 	lh	$t4,0x88($sp)
/*  f0642d0:	02008825 */ 	or	$s1,$s0,$zero
/*  f0642d4:	27ad0088 */ 	addiu	$t5,$sp,0x88
/*  f0642d8:	05800024 */ 	bltz	$t4,.L0f06436c
/*  f0642dc:	24120048 */ 	addiu	$s2,$zero,0x48
/*  f0642e0:	85a20000 */ 	lh	$v0,0x0($t5)
.L0f0642e4:
/*  f0642e4:	00520019 */ 	multu	$v0,$s2
/*  f0642e8:	8e8f0338 */ 	lw	$t7,0x338($s4)
/*  f0642ec:	00002825 */ 	or	$a1,$zero,$zero
/*  f0642f0:	00007012 */ 	mflo	$t6
/*  f0642f4:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f0642f8:	86180002 */ 	lh	$t8,0x2($s0)
/*  f0642fc:	1f000015 */ 	bgtz	$t8,.L0f064354
/*  f064300:	00000000 */ 	nop
/*  f064304:	8e190004 */ 	lw	$t9,0x4($s0)
/*  f064308:	13200012 */ 	beqz	$t9,.L0f064354
/*  f06430c:	00000000 */ 	nop
/*  f064310:	92080000 */ 	lbu	$t0,0x0($s0)
/*  f064314:	2509ffff */ 	addiu	$t1,$t0,-1
/*  f064318:	2d210008 */ 	sltiu	$at,$t1,0x8
/*  f06431c:	1020000d */ 	beqz	$at,.L0f064354
/*  f064320:	00094880 */ 	sll	$t1,$t1,0x2
/*  f064324:	3c017f1b */ 	lui	$at,%hi(var7f1a9f30)
/*  f064328:	00290821 */ 	addu	$at,$at,$t1
/*  f06432c:	8c299f30 */ 	lw	$t1,%lo(var7f1a9f30)($at)
/*  f064330:	01200008 */ 	jr	$t1
/*  f064334:	00000000 */ 	nop
/*  f064338:	0fc22405 */ 	jal	func0f089014
/*  f06433c:	02002025 */ 	or	$a0,$s0,$zero
/*  f064340:	10000004 */ 	b	.L0f064354
/*  f064344:	00402825 */ 	or	$a1,$v0,$zero
/*  f064348:	0fc22ecf */ 	jal	func0f08bb3c
/*  f06434c:	02002025 */ 	or	$a0,$s0,$zero
/*  f064350:	00402825 */ 	or	$a1,$v0,$zero
.L0f064354:
/*  f064354:	0fc18ad9 */ 	jal	func0f062b64
/*  f064358:	02002025 */ 	or	$a0,$s0,$zero
/*  f06435c:	86220002 */ 	lh	$v0,0x2($s1)
/*  f064360:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f064364:	0441ffdf */ 	bgez	$v0,.L0f0642e4
/*  f064368:	00000000 */ 	nop
.L0f06436c:
/*  f06436c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f064370:
/*  f064370:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f064374:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f064378:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f06437c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f064380:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f064384:	03e00008 */ 	jr	$ra
/*  f064388:	27bd0290 */ 	addiu	$sp,$sp,0x290
);

GLOBAL_ASM(
glabel func0f06438c
.late_rodata
glabel var7f1a9f50
.word 0x3e333333
glabel var7f1a9f54
.word 0x3f533333
.text
/*  f06438c:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f064390:	3c01c000 */ 	lui	$at,0xc000
/*  f064394:	44812000 */ 	mtc1	$at,$f4
/*  f064398:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f06439c:	afa400a8 */ 	sw	$a0,0xa8($sp)
/*  f0643a0:	afa500ac */ 	sw	$a1,0xac($sp)
/*  f0643a4:	afa600b0 */ 	sw	$a2,0xb0($sp)
/*  f0643a8:	afa700b4 */ 	sw	$a3,0xb4($sp)
/*  f0643ac:	00002025 */ 	or	$a0,$zero,$zero
/*  f0643b0:	0fc2c43b */ 	jal	currentPlayerGetWeaponFunction
/*  f0643b4:	e7a40058 */ 	swc1	$f4,0x58($sp)
/*  f0643b8:	10400006 */ 	beqz	$v0,.L0f0643d4
/*  f0643bc:	8fa300c4 */ 	lw	$v1,0xc4($sp)
/*  f0643c0:	0fc289f2 */ 	jal	func0f0a27c8
/*  f0643c4:	afa30050 */ 	sw	$v1,0x50($sp)
/*  f0643c8:	10400002 */ 	beqz	$v0,.L0f0643d4
/*  f0643cc:	8fa30050 */ 	lw	$v1,0x50($sp)
/*  f0643d0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0643d4:
/*  f0643d4:	10600013 */ 	beqz	$v1,.L0f064424
/*  f0643d8:	00000000 */ 	nop
/*  f0643dc:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f0643e0:	00000000 */ 	nop
/*  f0643e4:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f0643e8:	e7a00068 */ 	swc1	$f0,0x68($sp)
/*  f0643ec:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f0643f0:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f0643f4:	c7a60034 */ 	lwc1	$f6,0x34($sp)
/*  f0643f8:	46060200 */ 	add.s	$f8,$f0,$f6
/*  f0643fc:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f064400:	e7a80064 */ 	swc1	$f8,0x64($sp)
/*  f064404:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f064408:	e7a00060 */ 	swc1	$f0,0x60($sp)
/*  f06440c:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f064410:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f064414:	c7aa0034 */ 	lwc1	$f10,0x34($sp)
/*  f064418:	460a0400 */ 	add.s	$f16,$f0,$f10
/*  f06441c:	10000026 */ 	b	.L0f0644b8
/*  f064420:	e7b0005c */ 	swc1	$f16,0x5c($sp)
.L0f064424:
/*  f064424:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f064428:	00000000 */ 	nop
/*  f06442c:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f064430:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f064434:	3c017f1b */ 	lui	$at,%hi(var7f1a9f50)
/*  f064438:	c4329f50 */ 	lwc1	$f18,%lo(var7f1a9f50)($at)
/*  f06443c:	c7a60034 */ 	lwc1	$f6,0x34($sp)
/*  f064440:	46120102 */ 	mul.s	$f4,$f0,$f18
/*  f064444:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f064448:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f06444c:	e7a80068 */ 	swc1	$f8,0x68($sp)
/*  f064450:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f064454:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f064458:	3c017f1b */ 	lui	$at,%hi(var7f1a9f54)
/*  f06445c:	c42a9f54 */ 	lwc1	$f10,%lo(var7f1a9f54)($at)
/*  f064460:	c7b20034 */ 	lwc1	$f18,0x34($sp)
/*  f064464:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f064468:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f06446c:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f064470:	e7a40064 */ 	swc1	$f4,0x64($sp)
/*  f064474:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f064478:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f06447c:	3c013e80 */ 	lui	$at,0x3e80
/*  f064480:	44813000 */ 	mtc1	$at,$f6
/*  f064484:	c7aa0034 */ 	lwc1	$f10,0x34($sp)
/*  f064488:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f06448c:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f064490:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f064494:	e7b00060 */ 	swc1	$f16,0x60($sp)
/*  f064498:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f06449c:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f0644a0:	3c013f40 */ 	lui	$at,0x3f40
/*  f0644a4:	44819000 */ 	mtc1	$at,$f18
/*  f0644a8:	c7a60034 */ 	lwc1	$f6,0x34($sp)
/*  f0644ac:	46120102 */ 	mul.s	$f4,$f0,$f18
/*  f0644b0:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0644b4:	e7a8005c */ 	swc1	$f8,0x5c($sp)
.L0f0644b8:
/*  f0644b8:	8fa400ac */ 	lw	$a0,0xac($sp)
/*  f0644bc:	3c01c020 */ 	lui	$at,0xc020
/*  f0644c0:	44815000 */ 	mtc1	$at,$f10
/*  f0644c4:	c4900008 */ 	lwc1	$f16,0x8($a0)
/*  f0644c8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0644cc:	4610503c */ 	c.lt.s	$f10,$f16
/*  f0644d0:	00000000 */ 	nop
/*  f0644d4:	45000004 */ 	bc1f	.L0f0644e8
/*  f0644d8:	00000000 */ 	nop
/*  f0644dc:	44810000 */ 	mtc1	$at,$f0
/*  f0644e0:	1000014d */ 	b	.L0f064a18
/*  f0644e4:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0644e8:
/*  f0644e8:	0fc2d341 */ 	jal	func0f0b4d04
/*  f0644ec:	27a500a0 */ 	addiu	$a1,$sp,0xa0
/*  f0644f0:	8fae00b0 */ 	lw	$t6,0xb0($sp)
/*  f0644f4:	8fa200ac */ 	lw	$v0,0xac($sp)
/*  f0644f8:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f0644fc:	c5d20000 */ 	lwc1	$f18,0x0($t6)
/*  f064500:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f064504:	e7b20094 */ 	swc1	$f18,0x94($sp)
/*  f064508:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f06450c:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f064510:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f064514:	0fc2d341 */ 	jal	func0f0b4d04
/*  f064518:	e7a6009c */ 	swc1	$f6,0x9c($sp)
/*  f06451c:	8faf00b0 */ 	lw	$t7,0xb0($sp)
/*  f064520:	8fa200ac */ 	lw	$v0,0xac($sp)
/*  f064524:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f064528:	c5e80004 */ 	lwc1	$f8,0x4($t7)
/*  f06452c:	27a50084 */ 	addiu	$a1,$sp,0x84
/*  f064530:	e7a80094 */ 	swc1	$f8,0x94($sp)
/*  f064534:	c44a0004 */ 	lwc1	$f10,0x4($v0)
/*  f064538:	e7aa0098 */ 	swc1	$f10,0x98($sp)
/*  f06453c:	c4500008 */ 	lwc1	$f16,0x8($v0)
/*  f064540:	0fc2d341 */ 	jal	func0f0b4d04
/*  f064544:	e7b0009c */ 	swc1	$f16,0x9c($sp)
/*  f064548:	8fa200ac */ 	lw	$v0,0xac($sp)
/*  f06454c:	8fb800b4 */ 	lw	$t8,0xb4($sp)
/*  f064550:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f064554:	c4520000 */ 	lwc1	$f18,0x0($v0)
/*  f064558:	27a5007c */ 	addiu	$a1,$sp,0x7c
/*  f06455c:	e7b20094 */ 	swc1	$f18,0x94($sp)
/*  f064560:	c7040004 */ 	lwc1	$f4,0x4($t8)
/*  f064564:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f064568:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f06456c:	0fc2d341 */ 	jal	func0f0b4d04
/*  f064570:	e7a6009c */ 	swc1	$f6,0x9c($sp)
/*  f064574:	8fb900ac */ 	lw	$t9,0xac($sp)
/*  f064578:	8fa800b4 */ 	lw	$t0,0xb4($sp)
/*  f06457c:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f064580:	c7280000 */ 	lwc1	$f8,0x0($t9)
/*  f064584:	27a50074 */ 	addiu	$a1,$sp,0x74
/*  f064588:	e7a80094 */ 	swc1	$f8,0x94($sp)
/*  f06458c:	c50a0000 */ 	lwc1	$f10,0x0($t0)
/*  f064590:	e7aa0098 */ 	swc1	$f10,0x98($sp)
/*  f064594:	c7300008 */ 	lwc1	$f16,0x8($t9)
/*  f064598:	0fc2d341 */ 	jal	func0f0b4d04
/*  f06459c:	e7b0009c */ 	swc1	$f16,0x9c($sp)
/*  f0645a0:	c7b20078 */ 	lwc1	$f18,0x78($sp)
/*  f0645a4:	c7a40068 */ 	lwc1	$f4,0x68($sp)
/*  f0645a8:	c7a60064 */ 	lwc1	$f6,0x64($sp)
/*  f0645ac:	c7a80080 */ 	lwc1	$f8,0x80($sp)
/*  f0645b0:	4612203e */ 	c.le.s	$f4,$f18
/*  f0645b4:	00000000 */ 	nop
/*  f0645b8:	45020116 */ 	bc1fl	.L0f064a14
/*  f0645bc:	c7a00058 */ 	lwc1	$f0,0x58($sp)
/*  f0645c0:	4606403e */ 	c.le.s	$f8,$f6
/*  f0645c4:	27a40070 */ 	addiu	$a0,$sp,0x70
/*  f0645c8:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f0645cc:	45020111 */ 	bc1fl	.L0f064a14
/*  f0645d0:	c7a00058 */ 	lwc1	$f0,0x58($sp)
/*  f0645d4:	0fc282fb */ 	jal	currentPlayerGetCrossPos
/*  f0645d8:	afa0004c */ 	sw	$zero,0x4c($sp)
/*  f0645dc:	0fc25e24 */ 	jal	floorf
/*  f0645e0:	c7ac008c */ 	lwc1	$f12,0x8c($sp)
/*  f0645e4:	e7a0008c */ 	swc1	$f0,0x8c($sp)
/*  f0645e8:	0fc25e5c */ 	jal	ceilf
/*  f0645ec:	c7ac0084 */ 	lwc1	$f12,0x84($sp)
/*  f0645f0:	0fc31ef4 */ 	jal	func0f0c7bd0
/*  f0645f4:	e7a00084 */ 	swc1	$f0,0x84($sp)
/*  f0645f8:	14400003 */ 	bnez	$v0,.L0f064608
/*  f0645fc:	8fa900c0 */ 	lw	$t1,0xc0($sp)
/*  f064600:	1120005a */ 	beqz	$t1,.L0f06476c
/*  f064604:	c7a00070 */ 	lwc1	$f0,0x70($sp)
.L0f064608:
/*  f064608:	c7aa005c */ 	lwc1	$f10,0x5c($sp)
/*  f06460c:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*  f064610:	c7b20084 */ 	lwc1	$f18,0x84($sp)
/*  f064614:	c7a40060 */ 	lwc1	$f4,0x60($sp)
/*  f064618:	460a803e */ 	c.le.s	$f16,$f10
/*  f06461c:	00000000 */ 	nop
/*  f064620:	45020063 */ 	bc1fl	.L0f0647b0
/*  f064624:	8fab004c */ 	lw	$t3,0x4c($sp)
/*  f064628:	4612203e */ 	c.le.s	$f4,$f18
/*  f06462c:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f064630:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x318)
/*  f064634:	4502005e */ 	bc1fl	.L0f0647b0
/*  f064638:	8fab004c */ 	lw	$t3,0x4c($sp)
/*  f06463c:	46109181 */ 	sub.s	$f6,$f18,$f16
/*  f064640:	44814000 */ 	mtc1	$at,$f8
/*  f064644:	8d4aa2d8 */ 	lw	$t2,%lo(g_Vars+0x318)($t2)
/*  f064648:	3c018007 */ 	lui	$at,%hi(var80069880)
/*  f06464c:	46083002 */ 	mul.s	$f0,$f6,$f8
/*  f064650:	15400004 */ 	bnez	$t2,.L0f064664
/*  f064654:	00000000 */ 	nop
/*  f064658:	c42a9880 */ 	lwc1	$f10,%lo(var80069880)($at)
/*  f06465c:	460a0002 */ 	mul.s	$f0,$f0,$f10
/*  f064660:	00000000 */ 	nop
.L0f064664:
/*  f064664:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f064668:	e7a00048 */ 	swc1	$f0,0x48($sp)
/*  f06466c:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f064670:	e7a0002c */ 	swc1	$f0,0x2c($sp)
/*  f064674:	3c013f00 */ 	lui	$at,0x3f00
/*  f064678:	44812000 */ 	mtc1	$at,$f4
/*  f06467c:	c7b2002c */ 	lwc1	$f18,0x2c($sp)
/*  f064680:	c7a80084 */ 	lwc1	$f8,0x84($sp)
/*  f064684:	c7aa008c */ 	lwc1	$f10,0x8c($sp)
/*  f064688:	46122402 */ 	mul.s	$f16,$f4,$f18
/*  f06468c:	44819000 */ 	mtc1	$at,$f18
/*  f064690:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f064694:	c7a80048 */ 	lwc1	$f8,0x48($sp)
/*  f064698:	00001025 */ 	or	$v0,$zero,$zero
/*  f06469c:	46100180 */ 	add.s	$f6,$f0,$f16
/*  f0646a0:	46122402 */ 	mul.s	$f16,$f4,$f18
/*  f0646a4:	46088281 */ 	sub.s	$f10,$f16,$f8
/*  f0646a8:	4606503e */ 	c.le.s	$f10,$f6
/*  f0646ac:	00000000 */ 	nop
/*  f0646b0:	45000002 */ 	bc1f	.L0f0646bc
/*  f0646b4:	00000000 */ 	nop
/*  f0646b8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0646bc:
/*  f0646bc:	10400029 */ 	beqz	$v0,.L0f064764
/*  f0646c0:	00000000 */ 	nop
/*  f0646c4:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f0646c8:	00000000 */ 	nop
/*  f0646cc:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f0646d0:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f0646d4:	c7a40084 */ 	lwc1	$f4,0x84($sp)
/*  f0646d8:	c7b2008c */ 	lwc1	$f18,0x8c($sp)
/*  f0646dc:	3c013f00 */ 	lui	$at,0x3f00
/*  f0646e0:	44816000 */ 	mtc1	$at,$f12
/*  f0646e4:	46122400 */ 	add.s	$f16,$f4,$f18
/*  f0646e8:	c7a40024 */ 	lwc1	$f4,0x24($sp)
/*  f0646ec:	c7a60048 */ 	lwc1	$f6,0x48($sp)
/*  f0646f0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0646f4:	460c8202 */ 	mul.s	$f8,$f16,$f12
/*  f0646f8:	00000000 */ 	nop
/*  f0646fc:	46046482 */ 	mul.s	$f18,$f12,$f4
/*  f064700:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f064704:	c7a80060 */ 	lwc1	$f8,0x60($sp)
/*  f064708:	46120400 */ 	add.s	$f16,$f0,$f18
/*  f06470c:	460a803e */ 	c.le.s	$f16,$f10
/*  f064710:	00000000 */ 	nop
/*  f064714:	45000002 */ 	bc1f	.L0f064720
/*  f064718:	00000000 */ 	nop
/*  f06471c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f064720:
/*  f064720:	10400010 */ 	beqz	$v0,.L0f064764
/*  f064724:	00000000 */ 	nop
/*  f064728:	c7a200a0 */ 	lwc1	$f2,0xa0($sp)
/*  f06472c:	00001025 */ 	or	$v0,$zero,$zero
/*  f064730:	c7a6005c */ 	lwc1	$f6,0x5c($sp)
/*  f064734:	4602403e */ 	c.le.s	$f8,$f2
/*  f064738:	00000000 */ 	nop
/*  f06473c:	45000002 */ 	bc1f	.L0f064748
/*  f064740:	00000000 */ 	nop
/*  f064744:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f064748:
/*  f064748:	10400006 */ 	beqz	$v0,.L0f064764
/*  f06474c:	00000000 */ 	nop
/*  f064750:	4606103e */ 	c.le.s	$f2,$f6
/*  f064754:	00001025 */ 	or	$v0,$zero,$zero
/*  f064758:	45000002 */ 	bc1f	.L0f064764
/*  f06475c:	00000000 */ 	nop
/*  f064760:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f064764:
/*  f064764:	10000011 */ 	b	.L0f0647ac
/*  f064768:	afa2004c */ 	sw	$v0,0x4c($sp)
.L0f06476c:
/*  f06476c:	c7a4008c */ 	lwc1	$f4,0x8c($sp)
/*  f064770:	00001025 */ 	or	$v0,$zero,$zero
/*  f064774:	c7b20084 */ 	lwc1	$f18,0x84($sp)
/*  f064778:	4600203e */ 	c.le.s	$f4,$f0
/*  f06477c:	00000000 */ 	nop
/*  f064780:	45000002 */ 	bc1f	.L0f06478c
/*  f064784:	00000000 */ 	nop
/*  f064788:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f06478c:
/*  f06478c:	50400007 */ 	beqzl	$v0,.L0f0647ac
/*  f064790:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f064794:	4612003e */ 	c.le.s	$f0,$f18
/*  f064798:	00001025 */ 	or	$v0,$zero,$zero
/*  f06479c:	45020003 */ 	bc1fl	.L0f0647ac
/*  f0647a0:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f0647a4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0647a8:	afa2004c */ 	sw	$v0,0x4c($sp)
.L0f0647ac:
/*  f0647ac:	8fab004c */ 	lw	$t3,0x4c($sp)
.L0f0647b0:
/*  f0647b0:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x284)
/*  f0647b4:	51600097 */ 	beqzl	$t3,.L0f064a14
/*  f0647b8:	c7a00058 */ 	lwc1	$f0,0x58($sp)
/*  f0647bc:	8d8ca244 */ 	lw	$t4,%lo(g_Vars+0x284)($t4)
/*  f0647c0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0647c4:	8d8400bc */ 	lw	$a0,0xbc($t4)
/*  f0647c8:	0fc30795 */ 	jal	func0f0c1e54
/*  f0647cc:	afa40044 */ 	sw	$a0,0x44($sp)
/*  f0647d0:	8fad00bc */ 	lw	$t5,0xbc($sp)
/*  f0647d4:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0647d8:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0647dc:	11a0000c */ 	beqz	$t5,.L0f064810
/*  f0647e0:	25e40008 */ 	addiu	$a0,$t7,0x8
/*  f0647e4:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f0647e8:	8fa600a8 */ 	lw	$a2,0xa8($sp)
/*  f0647ec:	240e0010 */ 	addiu	$t6,$zero,0x10
/*  f0647f0:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0647f4:	24070032 */ 	addiu	$a3,$zero,0x32
/*  f0647f8:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0647fc:	24450028 */ 	addiu	$a1,$v0,0x28
/*  f064800:	0c00b6e6 */ 	jal	func0002db98
/*  f064804:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f064808:	10000007 */ 	b	.L0f064828
/*  f06480c:	00000000 */ 	nop
.L0f064810:
/*  f064810:	24180010 */ 	addiu	$t8,$zero,0x10
/*  f064814:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f064818:	25e50028 */ 	addiu	$a1,$t7,0x28
/*  f06481c:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f064820:	0c00b6e6 */ 	jal	func0002db98
/*  f064824:	24070033 */ 	addiu	$a3,$zero,0x33
.L0f064828:
/*  f064828:	10400076 */ 	beqz	$v0,.L0f064a04
/*  f06482c:	c7a200a4 */ 	lwc1	$f2,0xa4($sp)
/*  f064830:	c7aa0068 */ 	lwc1	$f10,0x68($sp)
/*  f064834:	46001006 */ 	mov.s	$f0,$f2
/*  f064838:	c7b00064 */ 	lwc1	$f16,0x64($sp)
/*  f06483c:	460a103c */ 	c.lt.s	$f2,$f10
/*  f064840:	8fa800b8 */ 	lw	$t0,0xb8($sp)
/*  f064844:	45020004 */ 	bc1fl	.L0f064858
/*  f064848:	4602803c */ 	c.lt.s	$f16,$f2
/*  f06484c:	10000006 */ 	b	.L0f064868
/*  f064850:	46005006 */ 	mov.s	$f0,$f10
/*  f064854:	4602803c */ 	c.lt.s	$f16,$f2
.L0f064858:
/*  f064858:	00000000 */ 	nop
/*  f06485c:	45000002 */ 	bc1f	.L0f064868
/*  f064860:	00000000 */ 	nop
/*  f064864:	46008006 */ 	mov.s	$f0,$f16
.L0f064868:
/*  f064868:	0fc31ef4 */ 	jal	func0f0c7bd0
/*  f06486c:	e5000004 */ 	swc1	$f0,0x4($t0)
/*  f064870:	14400003 */ 	bnez	$v0,.L0f064880
/*  f064874:	8fb900c0 */ 	lw	$t9,0xc0($sp)
/*  f064878:	13200011 */ 	beqz	$t9,.L0f0648c0
/*  f06487c:	00000000 */ 	nop
.L0f064880:
/*  f064880:	c7a200a0 */ 	lwc1	$f2,0xa0($sp)
/*  f064884:	c7a80060 */ 	lwc1	$f8,0x60($sp)
/*  f064888:	c7a6005c */ 	lwc1	$f6,0x5c($sp)
/*  f06488c:	8fa900b8 */ 	lw	$t1,0xb8($sp)
/*  f064890:	4608103c */ 	c.lt.s	$f2,$f8
/*  f064894:	46001006 */ 	mov.s	$f0,$f2
/*  f064898:	45020004 */ 	bc1fl	.L0f0648ac
/*  f06489c:	4602303c */ 	c.lt.s	$f6,$f2
/*  f0648a0:	10000006 */ 	b	.L0f0648bc
/*  f0648a4:	46004006 */ 	mov.s	$f0,$f8
/*  f0648a8:	4602303c */ 	c.lt.s	$f6,$f2
.L0f0648ac:
/*  f0648ac:	00000000 */ 	nop
/*  f0648b0:	45020003 */ 	bc1fl	.L0f0648c0
/*  f0648b4:	e5200000 */ 	swc1	$f0,0x0($t1)
/*  f0648b8:	46003006 */ 	mov.s	$f0,$f6
.L0f0648bc:
/*  f0648bc:	e5200000 */ 	swc1	$f0,0x0($t1)
.L0f0648c0:
/*  f0648c0:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f0648c4:	00000000 */ 	nop
/*  f0648c8:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f0648cc:	e7a0002c */ 	swc1	$f0,0x2c($sp)
/*  f0648d0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0648d4:	44812000 */ 	mtc1	$at,$f4
/*  f0648d8:	c7b2002c */ 	lwc1	$f18,0x2c($sp)
/*  f0648dc:	c7a8008c */ 	lwc1	$f8,0x8c($sp)
/*  f0648e0:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f0648e4:	460a0400 */ 	add.s	$f16,$f0,$f10
/*  f0648e8:	4610403e */ 	c.le.s	$f8,$f16
/*  f0648ec:	00000000 */ 	nop
/*  f0648f0:	45000013 */ 	bc1f	.L0f064940
/*  f0648f4:	00000000 */ 	nop
/*  f0648f8:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f0648fc:	00000000 */ 	nop
/*  f064900:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f064904:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f064908:	3c013f00 */ 	lui	$at,0x3f00
/*  f06490c:	44812000 */ 	mtc1	$at,$f4
/*  f064910:	c7b20024 */ 	lwc1	$f18,0x24($sp)
/*  f064914:	c7a60084 */ 	lwc1	$f6,0x84($sp)
/*  f064918:	3c013f80 */ 	lui	$at,0x3f80
/*  f06491c:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f064920:	460a0400 */ 	add.s	$f16,$f0,$f10
/*  f064924:	4606803e */ 	c.le.s	$f16,$f6
/*  f064928:	00000000 */ 	nop
/*  f06492c:	45000004 */ 	bc1f	.L0f064940
/*  f064930:	00000000 */ 	nop
/*  f064934:	44814000 */ 	mtc1	$at,$f8
/*  f064938:	10000032 */ 	b	.L0f064a04
/*  f06493c:	e7a80058 */ 	swc1	$f8,0x58($sp)
.L0f064940:
/*  f064940:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f064944:	00000000 */ 	nop
/*  f064948:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f06494c:	e7a0002c */ 	swc1	$f0,0x2c($sp)
/*  f064950:	3c013f00 */ 	lui	$at,0x3f00
/*  f064954:	44812000 */ 	mtc1	$at,$f4
/*  f064958:	c7b2002c */ 	lwc1	$f18,0x2c($sp)
/*  f06495c:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*  f064960:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f064964:	460a0180 */ 	add.s	$f6,$f0,$f10
/*  f064968:	4606803e */ 	c.le.s	$f16,$f6
/*  f06496c:	00000000 */ 	nop
/*  f064970:	45000013 */ 	bc1f	.L0f0649c0
/*  f064974:	00000000 */ 	nop
/*  f064978:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f06497c:	00000000 */ 	nop
/*  f064980:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f064984:	e7a0002c */ 	swc1	$f0,0x2c($sp)
/*  f064988:	3c013f00 */ 	lui	$at,0x3f00
/*  f06498c:	44814000 */ 	mtc1	$at,$f8
/*  f064990:	c7a4002c */ 	lwc1	$f4,0x2c($sp)
/*  f064994:	c7a60084 */ 	lwc1	$f6,0x84($sp)
/*  f064998:	3c013f80 */ 	lui	$at,0x3f80
/*  f06499c:	46044482 */ 	mul.s	$f18,$f8,$f4
/*  f0649a0:	c7a80048 */ 	lwc1	$f8,0x48($sp)
/*  f0649a4:	46120280 */ 	add.s	$f10,$f0,$f18
/*  f0649a8:	44819000 */ 	mtc1	$at,$f18
/*  f0649ac:	46065401 */ 	sub.s	$f16,$f10,$f6
/*  f0649b0:	46088103 */ 	div.s	$f4,$f16,$f8
/*  f0649b4:	46049281 */ 	sub.s	$f10,$f18,$f4
/*  f0649b8:	10000012 */ 	b	.L0f064a04
/*  f0649bc:	e7aa0058 */ 	swc1	$f10,0x58($sp)
.L0f0649c0:
/*  f0649c0:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f0649c4:	00000000 */ 	nop
/*  f0649c8:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f0649cc:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f0649d0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0649d4:	44813000 */ 	mtc1	$at,$f6
/*  f0649d8:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*  f0649dc:	c7a4008c */ 	lwc1	$f4,0x8c($sp)
/*  f0649e0:	46060402 */ 	mul.s	$f16,$f0,$f6
/*  f0649e4:	c7a60048 */ 	lwc1	$f6,0x48($sp)
/*  f0649e8:	3c013f80 */ 	lui	$at,0x3f80
/*  f0649ec:	46088480 */ 	add.s	$f18,$f16,$f8
/*  f0649f0:	44814000 */ 	mtc1	$at,$f8
/*  f0649f4:	46122281 */ 	sub.s	$f10,$f4,$f18
/*  f0649f8:	46065403 */ 	div.s	$f16,$f10,$f6
/*  f0649fc:	46104101 */ 	sub.s	$f4,$f8,$f16
/*  f064a00:	e7a40058 */ 	swc1	$f4,0x58($sp)
.L0f064a04:
/*  f064a04:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f064a08:	0fc30795 */ 	jal	func0f0c1e54
/*  f064a0c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f064a10:	c7a00058 */ 	lwc1	$f0,0x58($sp)
.L0f064a14:
/*  f064a14:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f064a18:
/*  f064a18:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
/*  f064a1c:	03e00008 */ 	jr	$ra
/*  f064a20:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f064a24
/*  f064a24:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f064a28:	f7bc0038 */ 	sdc1	$f28,0x38($sp)
/*  f064a2c:	3c013f80 */ 	lui	$at,0x3f80
/*  f064a30:	4481e000 */ 	mtc1	$at,$f28
/*  f064a34:	f7be0040 */ 	sdc1	$f30,0x40($sp)
/*  f064a38:	3c01bf80 */ 	lui	$at,0xbf80
/*  f064a3c:	afbf006c */ 	sw	$ra,0x6c($sp)
/*  f064a40:	4481f000 */ 	mtc1	$at,$f30
/*  f064a44:	afbe0068 */ 	sw	$s8,0x68($sp)
/*  f064a48:	afb70064 */ 	sw	$s7,0x64($sp)
/*  f064a4c:	afb60060 */ 	sw	$s6,0x60($sp)
/*  f064a50:	afb5005c */ 	sw	$s5,0x5c($sp)
/*  f064a54:	afb40058 */ 	sw	$s4,0x58($sp)
/*  f064a58:	afb30054 */ 	sw	$s3,0x54($sp)
/*  f064a5c:	afb20050 */ 	sw	$s2,0x50($sp)
/*  f064a60:	afb1004c */ 	sw	$s1,0x4c($sp)
/*  f064a64:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f064a68:	f7ba0030 */ 	sdc1	$f26,0x30($sp)
/*  f064a6c:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f064a70:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f064a74:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f064a78:	afa00074 */ 	sw	$zero,0x74($sp)
/*  f064a7c:	0fc2866a */ 	jal	handGetWeaponNum
/*  f064a80:	00002025 */ 	or	$a0,$zero,$zero
/*  f064a84:	24010016 */ 	addiu	$at,$zero,0x16
/*  f064a88:	1441007e */ 	bne	$v0,$at,.L0f064c84
/*  f064a8c:	00000000 */ 	nop
/*  f064a90:	0fc07934 */ 	jal	getNumChrSlots
/*  f064a94:	00000000 */ 	nop
/*  f064a98:	2443ffff */ 	addiu	$v1,$v0,-1
/*  f064a9c:	04600079 */ 	bltz	$v1,.L0f064c84
/*  f064aa0:	000398c0 */ 	sll	$s3,$v1,0x3
/*  f064aa4:	02639823 */ 	subu	$s3,$s3,$v1
/*  f064aa8:	00139880 */ 	sll	$s3,$s3,0x2
/*  f064aac:	02639823 */ 	subu	$s3,$s3,$v1
/*  f064ab0:	00139880 */ 	sll	$s3,$s3,0x2
/*  f064ab4:	02639821 */ 	addu	$s3,$s3,$v1
/*  f064ab8:	3c158006 */ 	lui	$s5,%hi(g_ChrSlots)
/*  f064abc:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f064ac0:	4480d000 */ 	mtc1	$zero,$f26
/*  f064ac4:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f064ac8:	26b52988 */ 	addiu	$s5,$s5,%lo(g_ChrSlots)
/*  f064acc:	001398c0 */ 	sll	$s3,$s3,0x3
/*  f064ad0:	241e001e */ 	addiu	$s8,$zero,0x1e
/*  f064ad4:	24170004 */ 	addiu	$s7,$zero,0x4
/*  f064ad8:	24160003 */ 	addiu	$s6,$zero,0x3
/*  f064adc:	24140006 */ 	addiu	$s4,$zero,0x6
/*  f064ae0:	8eae0000 */ 	lw	$t6,0x0($s5)
.L0f064ae4:
/*  f064ae4:	01d37821 */ 	addu	$t7,$t6,$s3
/*  f064ae8:	8df1001c */ 	lw	$s1,0x1c($t7)
/*  f064aec:	52200063 */ 	beqzl	$s1,.L0f064c7c
/*  f064af0:	2673fc98 */ 	addiu	$s3,$s3,-872
/*  f064af4:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f064af8:	50400060 */ 	beqzl	$v0,.L0f064c7c
/*  f064afc:	2673fc98 */ 	addiu	$s3,$s3,-872
/*  f064b00:	92230000 */ 	lbu	$v1,0x0($s1)
/*  f064b04:	16c30005 */ 	bne	$s6,$v1,.L0f064b1c
/*  f064b08:	00000000 */ 	nop
/*  f064b0c:	92380001 */ 	lbu	$t8,0x1($s1)
/*  f064b10:	33190004 */ 	andi	$t9,$t8,0x4
/*  f064b14:	5720000a */ 	bnezl	$t9,.L0f064b40
/*  f064b18:	8c490018 */ 	lw	$t1,0x18($v0)
.L0f064b1c:
/*  f064b1c:	56830057 */ 	bnel	$s4,$v1,.L0f064c7c
/*  f064b20:	2673fc98 */ 	addiu	$s3,$s3,-872
/*  f064b24:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f064b28:	02202025 */ 	or	$a0,$s1,$zero
/*  f064b2c:	8e48028c */ 	lw	$t0,0x28c($s2)
/*  f064b30:	50480052 */ 	beql	$v0,$t0,.L0f064c7c
/*  f064b34:	2673fc98 */ 	addiu	$s3,$s3,-872
/*  f064b38:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f064b3c:	8c490018 */ 	lw	$t1,0x18($v0)
.L0f064b40:
/*  f064b40:	00408025 */ 	or	$s0,$v0,$zero
/*  f064b44:	312a1000 */ 	andi	$t2,$t1,0x1000
/*  f064b48:	5540004c */ 	bnezl	$t2,.L0f064c7c
/*  f064b4c:	2673fc98 */ 	addiu	$s3,$s3,-872
/*  f064b50:	8e4b0284 */ 	lw	$t3,0x284($s2)
/*  f064b54:	00402825 */ 	or	$a1,$v0,$zero
/*  f064b58:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f064b5c:	8d6c00bc */ 	lw	$t4,0xbc($t3)
/*  f064b60:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f064b64:	8d840004 */ 	lw	$a0,0x4($t4)
/*  f064b68:	54400044 */ 	bnezl	$v0,.L0f064c7c
/*  f064b6c:	2673fc98 */ 	addiu	$s3,$s3,-872
/*  f064b70:	82020007 */ 	lb	$v0,0x7($s0)
/*  f064b74:	52e20041 */ 	beql	$s7,$v0,.L0f064c7c
/*  f064b78:	2673fc98 */ 	addiu	$s3,$s3,-872
/*  f064b7c:	13c2003e */ 	beq	$s8,$v0,.L0f064c78
/*  f064b80:	2401001f */ 	addiu	$at,$zero,0x1f
/*  f064b84:	1041003c */ 	beq	$v0,$at,.L0f064c78
/*  f064b88:	24010005 */ 	addiu	$at,$zero,0x5
/*  f064b8c:	5041003b */ 	beql	$v0,$at,.L0f064c7c
/*  f064b90:	2673fc98 */ 	addiu	$s3,$s3,-872
/*  f064b94:	8e0d0014 */ 	lw	$t5,0x14($s0)
/*  f064b98:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f064b9c:	05c20037 */ 	bltzl	$t6,.L0f064c7c
/*  f064ba0:	2673fc98 */ 	addiu	$s3,$s3,-872
/*  f064ba4:	922f0000 */ 	lbu	$t7,0x0($s1)
/*  f064ba8:	568f000a */ 	bnel	$s4,$t7,.L0f064bd4
/*  f064bac:	8e420284 */ 	lw	$v0,0x284($s2)
/*  f064bb0:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f064bb4:	02202025 */ 	or	$a0,$s1,$zero
/*  f064bb8:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f064bbc:	0258c821 */ 	addu	$t9,$s2,$t8
/*  f064bc0:	8f280064 */ 	lw	$t0,0x64($t9)
/*  f064bc4:	8d0900d8 */ 	lw	$t1,0xd8($t0)
/*  f064bc8:	5520002c */ 	bnezl	$t1,.L0f064c7c
/*  f064bcc:	2673fc98 */ 	addiu	$s3,$s3,-872
/*  f064bd0:	8e420284 */ 	lw	$v0,0x284($s2)
.L0f064bd4:
/*  f064bd4:	c6260008 */ 	lwc1	$f6,0x8($s1)
/*  f064bd8:	c62a000c */ 	lwc1	$f10,0xc($s1)
/*  f064bdc:	c444037c */ 	lwc1	$f4,0x37c($v0)
/*  f064be0:	c4480380 */ 	lwc1	$f8,0x380($v0)
/*  f064be4:	c6320010 */ 	lwc1	$f18,0x10($s1)
/*  f064be8:	46062501 */ 	sub.s	$f20,$f4,$f6
/*  f064bec:	c4500384 */ 	lwc1	$f16,0x384($v0)
/*  f064bf0:	460a4581 */ 	sub.s	$f22,$f8,$f10
/*  f064bf4:	4614a102 */ 	mul.s	$f4,$f20,$f20
/*  f064bf8:	46128601 */ 	sub.s	$f24,$f16,$f18
/*  f064bfc:	4616b182 */ 	mul.s	$f6,$f22,$f22
/*  f064c00:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f064c04:	4618c282 */ 	mul.s	$f10,$f24,$f24
/*  f064c08:	0c012974 */ 	jal	sqrtf
/*  f064c0c:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f064c10:	4600d03c */ 	c.lt.s	$f26,$f0
/*  f064c14:	00000000 */ 	nop
/*  f064c18:	45020018 */ 	bc1fl	.L0f064c7c
/*  f064c1c:	2673fc98 */ 	addiu	$s3,$s3,-872
/*  f064c20:	8e420284 */ 	lw	$v0,0x284($s2)
/*  f064c24:	c4500388 */ 	lwc1	$f16,0x388($v0)
/*  f064c28:	c444038c */ 	lwc1	$f4,0x38c($v0)
/*  f064c2c:	c44a0390 */ 	lwc1	$f10,0x390($v0)
/*  f064c30:	4610a482 */ 	mul.s	$f18,$f20,$f16
/*  f064c34:	00000000 */ 	nop
/*  f064c38:	4604b182 */ 	mul.s	$f6,$f22,$f4
/*  f064c3c:	46069200 */ 	add.s	$f8,$f18,$f6
/*  f064c40:	46185402 */ 	mul.s	$f16,$f10,$f24
/*  f064c44:	46088100 */ 	add.s	$f4,$f16,$f8
/*  f064c48:	46002083 */ 	div.s	$f2,$f4,$f0
/*  f064c4c:	461a103c */ 	c.lt.s	$f2,$f26
/*  f064c50:	00000000 */ 	nop
/*  f064c54:	45000008 */ 	bc1f	.L0f064c78
/*  f064c58:	00000000 */ 	nop
/*  f064c5c:	461c103c */ 	c.lt.s	$f2,$f28
/*  f064c60:	00000000 */ 	nop
/*  f064c64:	45020005 */ 	bc1fl	.L0f064c7c
/*  f064c68:	2673fc98 */ 	addiu	$s3,$s3,-872
/*  f064c6c:	46001706 */ 	mov.s	$f28,$f2
/*  f064c70:	afb10074 */ 	sw	$s1,0x74($sp)
/*  f064c74:	46000786 */ 	mov.s	$f30,$f0
.L0f064c78:
/*  f064c78:	2673fc98 */ 	addiu	$s3,$s3,-872
.L0f064c7c:
/*  f064c7c:	0663ff99 */ 	bgezl	$s3,.L0f064ae4
/*  f064c80:	8eae0000 */ 	lw	$t6,0x0($s5)
.L0f064c84:
/*  f064c84:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f064c88:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f064c8c:	8e4a0284 */ 	lw	$t2,0x284($s2)
/*  f064c90:	e55e0258 */ 	swc1	$f30,0x258($t2)
/*  f064c94:	8e4c0284 */ 	lw	$t4,0x284($s2)
/*  f064c98:	8fab0074 */ 	lw	$t3,0x74($sp)
/*  f064c9c:	ad8b025c */ 	sw	$t3,0x25c($t4)
/*  f064ca0:	8fbf006c */ 	lw	$ra,0x6c($sp)
/*  f064ca4:	8fbe0068 */ 	lw	$s8,0x68($sp)
/*  f064ca8:	8fb70064 */ 	lw	$s7,0x64($sp)
/*  f064cac:	8fb60060 */ 	lw	$s6,0x60($sp)
/*  f064cb0:	8fb5005c */ 	lw	$s5,0x5c($sp)
/*  f064cb4:	8fb40058 */ 	lw	$s4,0x58($sp)
/*  f064cb8:	8fb30054 */ 	lw	$s3,0x54($sp)
/*  f064cbc:	8fb20050 */ 	lw	$s2,0x50($sp)
/*  f064cc0:	8fb1004c */ 	lw	$s1,0x4c($sp)
/*  f064cc4:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f064cc8:	d7be0040 */ 	ldc1	$f30,0x40($sp)
/*  f064ccc:	d7bc0038 */ 	ldc1	$f28,0x38($sp)
/*  f064cd0:	d7ba0030 */ 	ldc1	$f26,0x30($sp)
/*  f064cd4:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f064cd8:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f064cdc:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f064ce0:	03e00008 */ 	jr	$ra
/*  f064ce4:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

GLOBAL_ASM(
glabel func0f064ce8
/*  f064ce8:	27bdff08 */ 	addiu	$sp,$sp,-248
/*  f064cec:	3c0f8007 */ 	lui	$t7,%hi(var800698c0)
/*  f064cf0:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f064cf4:	afb50040 */ 	sw	$s5,0x40($sp)
/*  f064cf8:	afb4003c */ 	sw	$s4,0x3c($sp)
/*  f064cfc:	afb30038 */ 	sw	$s3,0x38($sp)
/*  f064d00:	afb20034 */ 	sw	$s2,0x34($sp)
/*  f064d04:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f064d08:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f064d0c:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f064d10:	25ef98c0 */ 	addiu	$t7,$t7,%lo(var800698c0)
/*  f064d14:	8de10000 */ 	lw	$at,0x0($t7)
/*  f064d18:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f064d1c:	27ae00ec */ 	addiu	$t6,$sp,0xec
/*  f064d20:	00009825 */ 	or	$s3,$zero,$zero
/*  f064d24:	00008025 */ 	or	$s0,$zero,$zero
/*  f064d28:	00002025 */ 	or	$a0,$zero,$zero
/*  f064d2c:	adc10000 */ 	sw	$at,0x0($t6)
/*  f064d30:	0fc2866a */ 	jal	handGetWeaponNum
/*  f064d34:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f064d38:	00402025 */ 	or	$a0,$v0,$zero
/*  f064d3c:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f064d40:	3c050008 */ 	lui	$a1,0x8
/*  f064d44:	afa200e4 */ 	sw	$v0,0xe4($sp)
/*  f064d48:	afa000e0 */ 	sw	$zero,0xe0($sp)
/*  f064d4c:	0fc2c43b */ 	jal	currentPlayerGetWeaponFunction
/*  f064d50:	00002025 */ 	or	$a0,$zero,$zero
/*  f064d54:	10400007 */ 	beqz	$v0,.L0f064d74
/*  f064d58:	00000000 */ 	nop
/*  f064d5c:	8c490000 */ 	lw	$t1,0x0($v0)
/*  f064d60:	24140003 */ 	addiu	$s4,$zero,0x3
/*  f064d64:	312a00ff */ 	andi	$t2,$t1,0xff
/*  f064d68:	168a0002 */ 	bne	$s4,$t2,.L0f064d74
/*  f064d6c:	00000000 */ 	nop
/*  f064d70:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f064d74:
/*  f064d74:	0fc6830c */ 	jal	frIsInTraining
/*  f064d78:	24140003 */ 	addiu	$s4,$zero,0x3
/*  f064d7c:	10400009 */ 	beqz	$v0,.L0f064da4
/*  f064d80:	00000000 */ 	nop
/*  f064d84:	0fc6829c */ 	jal	frChooseFarsightTarget
/*  f064d88:	00000000 */ 	nop
/*  f064d8c:	14400007 */ 	bnez	$v0,.L0f064dac
/*  f064d90:	00000000 */ 	nop
/*  f064d94:	0fc19289 */ 	jal	func0f064a24
/*  f064d98:	00000000 */ 	nop
/*  f064d9c:	10000003 */ 	b	.L0f064dac
/*  f064da0:	00000000 */ 	nop
.L0f064da4:
/*  f064da4:	0fc19289 */ 	jal	func0f064a24
/*  f064da8:	00000000 */ 	nop
.L0f064dac:
/*  f064dac:	0fc2866a */ 	jal	handGetWeaponNum
/*  f064db0:	00002025 */ 	or	$a0,$zero,$zero
/*  f064db4:	2401000a */ 	addiu	$at,$zero,0xa
/*  f064db8:	14410009 */ 	bne	$v0,$at,.L0f064de0
/*  f064dbc:	3c15800a */ 	lui	$s5,%hi(g_Vars)
/*  f064dc0:	26b59fc0 */ 	addiu	$s5,$s5,%lo(g_Vars)
/*  f064dc4:	8eab0284 */ 	lw	$t3,0x284($s5)
/*  f064dc8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f064dcc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f064dd0:	916c063b */ 	lbu	$t4,0x63b($t3)
/*  f064dd4:	55810003 */ 	bnel	$t4,$at,.L0f064de4
/*  f064dd8:	8fb900e0 */ 	lw	$t9,0xe0($sp)
/*  f064ddc:	afad00e0 */ 	sw	$t5,0xe0($sp)
.L0f064de0:
/*  f064de0:	8fb900e0 */ 	lw	$t9,0xe0($sp)
.L0f064de4:
/*  f064de4:	3c15800a */ 	lui	$s5,%hi(g_Vars)
/*  f064de8:	26b59fc0 */ 	addiu	$s5,$s5,%lo(g_Vars)
/*  f064dec:	132000f3 */ 	beqz	$t9,.L0f0651bc
/*  f064df0:	00009025 */ 	or	$s2,$zero,$zero
/*  f064df4:	8eb80284 */ 	lw	$t8,0x284($s5)
.L0f064df8:
/*  f064df8:	03128021 */ 	addu	$s0,$t8,$s2
/*  f064dfc:	8e0e1630 */ 	lw	$t6,0x1630($s0)
/*  f064e00:	26101630 */ 	addiu	$s0,$s0,0x1630
/*  f064e04:	11c000e6 */ 	beqz	$t6,.L0f0651a0
/*  f064e08:	00000000 */ 	nop
/*  f064e0c:	860f0004 */ 	lh	$t7,0x4($s0)
/*  f064e10:	05e30005 */ 	bgezl	$t7,.L0f064e28
/*  f064e14:	86090006 */ 	lh	$t1,0x6($s0)
/*  f064e18:	86080008 */ 	lh	$t0,0x8($s0)
/*  f064e1c:	050000e0 */ 	bltz	$t0,.L0f0651a0
/*  f064e20:	00000000 */ 	nop
/*  f064e24:	86090006 */ 	lh	$t1,0x6($s0)
.L0f064e28:
/*  f064e28:	05210004 */ 	bgez	$t1,.L0f064e3c
/*  f064e2c:	00000000 */ 	nop
/*  f064e30:	860a000a */ 	lh	$t2,0xa($s0)
/*  f064e34:	054000da */ 	bltz	$t2,.L0f0651a0
/*  f064e38:	00000000 */ 	nop
.L0f064e3c:
/*  f064e3c:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f064e40:	00008825 */ 	or	$s1,$zero,$zero
/*  f064e44:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f064e48:	46000506 */ 	mov.s	$f20,$f0
/*  f064e4c:	3c013e00 */ 	lui	$at,0x3e00
/*  f064e50:	44812000 */ 	mtc1	$at,$f4
/*  f064e54:	00000000 */ 	nop
/*  f064e58:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f064e5c:	46143200 */ 	add.s	$f8,$f6,$f20
/*  f064e60:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f064e64:	e7a800d0 */ 	swc1	$f8,0xd0($sp)
/*  f064e68:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f064e6c:	46000506 */ 	mov.s	$f20,$f0
/*  f064e70:	3c013f60 */ 	lui	$at,0x3f60
/*  f064e74:	44815000 */ 	mtc1	$at,$f10
/*  f064e78:	00000000 */ 	nop
/*  f064e7c:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f064e80:	46148480 */ 	add.s	$f18,$f16,$f20
/*  f064e84:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f064e88:	e7b200cc */ 	swc1	$f18,0xcc($sp)
/*  f064e8c:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f064e90:	46000506 */ 	mov.s	$f20,$f0
/*  f064e94:	3c013e00 */ 	lui	$at,0x3e00
/*  f064e98:	44812000 */ 	mtc1	$at,$f4
/*  f064e9c:	00000000 */ 	nop
/*  f064ea0:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f064ea4:	46143200 */ 	add.s	$f8,$f6,$f20
/*  f064ea8:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f064eac:	e7a800c8 */ 	swc1	$f8,0xc8($sp)
/*  f064eb0:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f064eb4:	46000506 */ 	mov.s	$f20,$f0
/*  f064eb8:	3c013f60 */ 	lui	$at,0x3f60
/*  f064ebc:	44815000 */ 	mtc1	$at,$f10
/*  f064ec0:	8e130000 */ 	lw	$s3,0x0($s0)
/*  f064ec4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f064ec8:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f064ecc:	92620000 */ 	lbu	$v0,0x0($s3)
/*  f064ed0:	10410006 */ 	beq	$v0,$at,.L0f064eec
/*  f064ed4:	46148080 */ 	add.s	$f2,$f16,$f20
/*  f064ed8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f064edc:	10410003 */ 	beq	$v0,$at,.L0f064eec
/*  f064ee0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f064ee4:	54410033 */ 	bnel	$v0,$at,.L0f064fb4
/*  f064ee8:	860b0008 */ 	lh	$t3,0x8($s0)
.L0f064eec:
/*  f064eec:	860b0008 */ 	lh	$t3,0x8($s0)
/*  f064ef0:	860c0004 */ 	lh	$t4,0x4($s0)
/*  f064ef4:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f064ef8:	05a10003 */ 	bgez	$t5,.L0f064f08
/*  f064efc:	000dc843 */ 	sra	$t9,$t5,0x1
/*  f064f00:	25a10001 */ 	addiu	$at,$t5,0x1
/*  f064f04:	0001c843 */ 	sra	$t9,$at,0x1
.L0f064f08:
/*  f064f08:	44999000 */ 	mtc1	$t9,$f18
/*  f064f0c:	00000000 */ 	nop
/*  f064f10:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f064f14:	e7a400ec */ 	swc1	$f4,0xec($sp)
/*  f064f18:	860e0006 */ 	lh	$t6,0x6($s0)
/*  f064f1c:	8618000a */ 	lh	$t8,0xa($s0)
/*  f064f20:	030e7821 */ 	addu	$t7,$t8,$t6
/*  f064f24:	05e10003 */ 	bgez	$t7,.L0f064f34
/*  f064f28:	000f4043 */ 	sra	$t0,$t7,0x1
/*  f064f2c:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f064f30:	00014043 */ 	sra	$t0,$at,0x1
.L0f064f34:
/*  f064f34:	44883000 */ 	mtc1	$t0,$f6
/*  f064f38:	00000000 */ 	nop
/*  f064f3c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f064f40:	e7a800f0 */ 	swc1	$f8,0xf0($sp)
/*  f064f44:	92690001 */ 	lbu	$t1,0x1($s3)
/*  f064f48:	312a0002 */ 	andi	$t2,$t1,0x2
/*  f064f4c:	51400044 */ 	beqzl	$t2,.L0f065060
/*  f064f50:	c7ac00ec */ 	lwc1	$f12,0xec($sp)
/*  f064f54:	8e620004 */ 	lw	$v0,0x4($s3)
/*  f064f58:	8c440018 */ 	lw	$a0,0x18($v0)
/*  f064f5c:	0c006983 */ 	jal	func0001a60c
/*  f064f60:	e7a200c4 */ 	swc1	$f2,0xc4($sp)
/*  f064f64:	c44a0038 */ 	lwc1	$f10,0x38($v0)
/*  f064f68:	44809000 */ 	mtc1	$zero,$f18
/*  f064f6c:	c7a200c4 */ 	lwc1	$f2,0xc4($sp)
/*  f064f70:	e7aa00b4 */ 	swc1	$f10,0xb4($sp)
/*  f064f74:	c7b000b4 */ 	lwc1	$f16,0xb4($sp)
/*  f064f78:	4612803c */ 	c.lt.s	$f16,$f18
/*  f064f7c:	00000000 */ 	nop
/*  f064f80:	45020037 */ 	bc1fl	.L0f065060
/*  f064f84:	c7ac00ec */ 	lwc1	$f12,0xec($sp)
/*  f064f88:	c4440030 */ 	lwc1	$f4,0x30($v0)
/*  f064f8c:	27a400ac */ 	addiu	$a0,$sp,0xac
/*  f064f90:	27a500ec */ 	addiu	$a1,$sp,0xec
/*  f064f94:	e7a400ac */ 	swc1	$f4,0xac($sp)
/*  f064f98:	c4460034 */ 	lwc1	$f6,0x34($v0)
/*  f064f9c:	e7a200c4 */ 	swc1	$f2,0xc4($sp)
/*  f064fa0:	0fc2d341 */ 	jal	func0f0b4d04
/*  f064fa4:	e7a600b0 */ 	swc1	$f6,0xb0($sp)
/*  f064fa8:	1000002c */ 	b	.L0f06505c
/*  f064fac:	c7a200c4 */ 	lwc1	$f2,0xc4($sp)
/*  f064fb0:	860b0008 */ 	lh	$t3,0x8($s0)
.L0f064fb4:
/*  f064fb4:	860c0004 */ 	lh	$t4,0x4($s0)
/*  f064fb8:	8e710004 */ 	lw	$s1,0x4($s3)
/*  f064fbc:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f064fc0:	05a10003 */ 	bgez	$t5,.L0f064fd0
/*  f064fc4:	000dc843 */ 	sra	$t9,$t5,0x1
/*  f064fc8:	25a10001 */ 	addiu	$at,$t5,0x1
/*  f064fcc:	0001c843 */ 	sra	$t9,$at,0x1
.L0f064fd0:
/*  f064fd0:	44994000 */ 	mtc1	$t9,$f8
/*  f064fd4:	00000000 */ 	nop
/*  f064fd8:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f064fdc:	1220000d */ 	beqz	$s1,.L0f065014
/*  f064fe0:	e7aa00ec */ 	swc1	$f10,0xec($sp)
/*  f064fe4:	923802fe */ 	lbu	$t8,0x2fe($s1)
/*  f064fe8:	5698000b */ 	bnel	$s4,$t8,.L0f065018
/*  f064fec:	860b0006 */ 	lh	$t3,0x6($s0)
/*  f064ff0:	860e000a */ 	lh	$t6,0xa($s0)
/*  f064ff4:	860f0006 */ 	lh	$t7,0x6($s0)
/*  f064ff8:	01cf4021 */ 	addu	$t0,$t6,$t7
/*  f064ffc:	00084843 */ 	sra	$t1,$t0,0x1
/*  f065000:	44898000 */ 	mtc1	$t1,$f16
/*  f065004:	00000000 */ 	nop
/*  f065008:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f06500c:	10000013 */ 	b	.L0f06505c
/*  f065010:	e7b200f0 */ 	swc1	$f18,0xf0($sp)
.L0f065014:
/*  f065014:	860b0006 */ 	lh	$t3,0x6($s0)
.L0f065018:
/*  f065018:	860a000a */ 	lh	$t2,0xa($s0)
/*  f06501c:	000b6040 */ 	sll	$t4,$t3,0x1
/*  f065020:	014c6821 */ 	addu	$t5,$t2,$t4
/*  f065024:	01b4001a */ 	div	$zero,$t5,$s4
/*  f065028:	0000c812 */ 	mflo	$t9
/*  f06502c:	44992000 */ 	mtc1	$t9,$f4
/*  f065030:	16800002 */ 	bnez	$s4,.L0f06503c
/*  f065034:	00000000 */ 	nop
/*  f065038:	0007000d */ 	break	0x7
.L0f06503c:
/*  f06503c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f065040:	16810004 */ 	bne	$s4,$at,.L0f065054
/*  f065044:	3c018000 */ 	lui	$at,0x8000
/*  f065048:	15a10002 */ 	bne	$t5,$at,.L0f065054
/*  f06504c:	00000000 */ 	nop
/*  f065050:	0006000d */ 	break	0x6
.L0f065054:
/*  f065054:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f065058:	e7a600f0 */ 	swc1	$f6,0xf0($sp)
.L0f06505c:
/*  f06505c:	c7ac00ec */ 	lwc1	$f12,0xec($sp)
.L0f065060:
/*  f065060:	c7a000c8 */ 	lwc1	$f0,0xc8($sp)
/*  f065064:	460c103c */ 	c.lt.s	$f2,$f12
/*  f065068:	00000000 */ 	nop
/*  f06506c:	45020003 */ 	bc1fl	.L0f06507c
/*  f065070:	4600603c */ 	c.lt.s	$f12,$f0
/*  f065074:	46001306 */ 	mov.s	$f12,$f2
/*  f065078:	4600603c */ 	c.lt.s	$f12,$f0
.L0f06507c:
/*  f06507c:	e7ac00ec */ 	swc1	$f12,0xec($sp)
/*  f065080:	45020003 */ 	bc1fl	.L0f065090
/*  f065084:	c7a000cc */ 	lwc1	$f0,0xcc($sp)
/*  f065088:	e7a000ec */ 	swc1	$f0,0xec($sp)
/*  f06508c:	c7a000cc */ 	lwc1	$f0,0xcc($sp)
.L0f065090:
/*  f065090:	c7a200f0 */ 	lwc1	$f2,0xf0($sp)
/*  f065094:	4602003c */ 	c.lt.s	$f0,$f2
/*  f065098:	00000000 */ 	nop
/*  f06509c:	45020003 */ 	bc1fl	.L0f0650ac
/*  f0650a0:	c7a000d0 */ 	lwc1	$f0,0xd0($sp)
/*  f0650a4:	46000086 */ 	mov.s	$f2,$f0
/*  f0650a8:	c7a000d0 */ 	lwc1	$f0,0xd0($sp)
.L0f0650ac:
/*  f0650ac:	e7a200f0 */ 	swc1	$f2,0xf0($sp)
/*  f0650b0:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0650b4:	00000000 */ 	nop
/*  f0650b8:	45000002 */ 	bc1f	.L0f0650c4
/*  f0650bc:	00000000 */ 	nop
/*  f0650c0:	e7a000f0 */ 	swc1	$f0,0xf0($sp)
.L0f0650c4:
/*  f0650c4:	52200011 */ 	beqzl	$s1,.L0f06510c
/*  f0650c8:	860f0008 */ 	lh	$t7,0x8($s0)
/*  f0650cc:	923802fe */ 	lbu	$t8,0x2fe($s1)
/*  f0650d0:	5698000e */ 	bnel	$s4,$t8,.L0f06510c
/*  f0650d4:	860f0008 */ 	lh	$t7,0x8($s0)
/*  f0650d8:	0fc0f011 */ 	jal	chrToEyespy
/*  f0650dc:	02202025 */ 	or	$a0,$s1,$zero
/*  f0650e0:	50400005 */ 	beqzl	$v0,.L0f0650f8
/*  f0650e4:	44806000 */ 	mtc1	$zero,$f12
/*  f0650e8:	904e0035 */ 	lbu	$t6,0x35($v0)
/*  f0650ec:	15c0002c */ 	bnez	$t6,.L0f0651a0
/*  f0650f0:	00000000 */ 	nop
/*  f0650f4:	44806000 */ 	mtc1	$zero,$f12
.L0f0650f8:
/*  f0650f8:	00009825 */ 	or	$s3,$zero,$zero
/*  f0650fc:	e7ac00f0 */ 	swc1	$f12,0xf0($sp)
/*  f065100:	10000027 */ 	b	.L0f0651a0
/*  f065104:	e7ac00ec */ 	swc1	$f12,0xec($sp)
/*  f065108:	860f0008 */ 	lh	$t7,0x8($s0)
.L0f06510c:
/*  f06510c:	c7b000ec */ 	lwc1	$f16,0xec($sp)
/*  f065110:	448f4000 */ 	mtc1	$t7,$f8
/*  f065114:	00000000 */ 	nop
/*  f065118:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f06511c:	4610503c */ 	c.lt.s	$f10,$f16
/*  f065120:	00000000 */ 	nop
/*  f065124:	4503001b */ 	bc1tl	.L0f065194
/*  f065128:	44806000 */ 	mtc1	$zero,$f12
/*  f06512c:	86080004 */ 	lh	$t0,0x4($s0)
/*  f065130:	44889000 */ 	mtc1	$t0,$f18
/*  f065134:	00000000 */ 	nop
/*  f065138:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f06513c:	4604803c */ 	c.lt.s	$f16,$f4
/*  f065140:	00000000 */ 	nop
/*  f065144:	45030013 */ 	bc1tl	.L0f065194
/*  f065148:	44806000 */ 	mtc1	$zero,$f12
/*  f06514c:	8609000a */ 	lh	$t1,0xa($s0)
/*  f065150:	c7aa00f0 */ 	lwc1	$f10,0xf0($sp)
/*  f065154:	44893000 */ 	mtc1	$t1,$f6
/*  f065158:	00000000 */ 	nop
/*  f06515c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f065160:	460a403c */ 	c.lt.s	$f8,$f10
/*  f065164:	00000000 */ 	nop
/*  f065168:	4503000a */ 	bc1tl	.L0f065194
/*  f06516c:	44806000 */ 	mtc1	$zero,$f12
/*  f065170:	860b0006 */ 	lh	$t3,0x6($s0)
/*  f065174:	448b9000 */ 	mtc1	$t3,$f18
/*  f065178:	00000000 */ 	nop
/*  f06517c:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f065180:	4610503c */ 	c.lt.s	$f10,$f16
/*  f065184:	00000000 */ 	nop
/*  f065188:	45000005 */ 	bc1f	.L0f0651a0
/*  f06518c:	00000000 */ 	nop
/*  f065190:	44806000 */ 	mtc1	$zero,$f12
.L0f065194:
/*  f065194:	00009825 */ 	or	$s3,$zero,$zero
/*  f065198:	e7ac00f0 */ 	swc1	$f12,0xf0($sp)
/*  f06519c:	e7ac00ec */ 	swc1	$f12,0xec($sp)
.L0f0651a0:
/*  f0651a0:	16600065 */ 	bnez	$s3,.L0f065338
/*  f0651a4:	2652000c */ 	addiu	$s2,$s2,0xc
/*  f0651a8:	24010030 */ 	addiu	$at,$zero,0x30
/*  f0651ac:	5641ff12 */ 	bnel	$s2,$at,.L0f064df8
/*  f0651b0:	8eb80284 */ 	lw	$t8,0x284($s5)
/*  f0651b4:	10000060 */ 	b	.L0f065338
/*  f0651b8:	00000000 */ 	nop
.L0f0651bc:
/*  f0651bc:	0fc31ea3 */ 	jal	func0f0c7a8c
/*  f0651c0:	00000000 */ 	nop
/*  f0651c4:	14400007 */ 	bnez	$v0,.L0f0651e4
/*  f0651c8:	00000000 */ 	nop
/*  f0651cc:	0fc31ef4 */ 	jal	func0f0c7bd0
/*  f0651d0:	00000000 */ 	nop
/*  f0651d4:	14400003 */ 	bnez	$v0,.L0f0651e4
/*  f0651d8:	8faa00e4 */ 	lw	$t2,0xe4($sp)
/*  f0651dc:	11400056 */ 	beqz	$t2,.L0f065338
/*  f0651e0:	00000000 */ 	nop
.L0f0651e4:
/*  f0651e4:	16000054 */ 	bnez	$s0,.L0f065338
/*  f0651e8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0651ec:	8eb2034c */ 	lw	$s2,0x34c($s5)
/*  f0651f0:	8eac0348 */ 	lw	$t4,0x348($s5)
/*  f0651f4:	4481a000 */ 	mtc1	$at,$f20
/*  f0651f8:	2652fffc */ 	addiu	$s2,$s2,-4
/*  f0651fc:	024c082b */ 	sltu	$at,$s2,$t4
/*  f065200:	1420004d */ 	bnez	$at,.L0f065338
/*  f065204:	00000000 */ 	nop
/*  f065208:	8e510000 */ 	lw	$s1,0x0($s2)
.L0f06520c:
/*  f06520c:	52200046 */ 	beqzl	$s1,.L0f065328
/*  f065210:	8eaa0348 */ 	lw	$t2,0x348($s5)
/*  f065214:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f065218:	50400043 */ 	beqzl	$v0,.L0f065328
/*  f06521c:	8eaa0348 */ 	lw	$t2,0x348($s5)
/*  f065220:	92230000 */ 	lbu	$v1,0x0($s1)
/*  f065224:	24010006 */ 	addiu	$at,$zero,0x6
/*  f065228:	5283000a */ 	beql	$s4,$v1,.L0f065254
/*  f06522c:	8eb90284 */ 	lw	$t9,0x284($s5)
/*  f065230:	5461003d */ 	bnel	$v1,$at,.L0f065328
/*  f065234:	8eaa0348 */ 	lw	$t2,0x348($s5)
/*  f065238:	0fc4a25f */ 	jal	propGetPlayerNum
/*  f06523c:	02202025 */ 	or	$a0,$s1,$zero
/*  f065240:	8ead028c */ 	lw	$t5,0x28c($s5)
/*  f065244:	504d0038 */ 	beql	$v0,$t5,.L0f065328
/*  f065248:	8eaa0348 */ 	lw	$t2,0x348($s5)
/*  f06524c:	8e220004 */ 	lw	$v0,0x4($s1)
/*  f065250:	8eb90284 */ 	lw	$t9,0x284($s5)
.L0f065254:
/*  f065254:	00408025 */ 	or	$s0,$v0,$zero
/*  f065258:	00402825 */ 	or	$a1,$v0,$zero
/*  f06525c:	8f3800bc */ 	lw	$t8,0xbc($t9)
/*  f065260:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f065264:	0fc12aa3 */ 	jal	chrCompareTeams
/*  f065268:	8f040004 */ 	lw	$a0,0x4($t8)
/*  f06526c:	1440002d */ 	bnez	$v0,.L0f065324
/*  f065270:	02002025 */ 	or	$a0,$s0,$zero
/*  f065274:	0fc0a209 */ 	jal	chrGetEquippedWeaponProp
/*  f065278:	00002825 */ 	or	$a1,$zero,$zero
/*  f06527c:	1440000b */ 	bnez	$v0,.L0f0652ac
/*  f065280:	02002025 */ 	or	$a0,$s0,$zero
/*  f065284:	0fc0a209 */ 	jal	chrGetEquippedWeaponProp
/*  f065288:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f06528c:	54400008 */ 	bnezl	$v0,.L0f0652b0
/*  f065290:	02202025 */ 	or	$a0,$s1,$zero
/*  f065294:	8e0e0018 */ 	lw	$t6,0x18($s0)
/*  f065298:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f06529c:	05e20004 */ 	bltzl	$t7,.L0f0652b0
/*  f0652a0:	02202025 */ 	or	$a0,$s1,$zero
/*  f0652a4:	8e080300 */ 	lw	$t0,0x300($s0)
/*  f0652a8:	1100001e */ 	beqz	$t0,.L0f065324
.L0f0652ac:
/*  f0652ac:	02202025 */ 	or	$a0,$s1,$zero
.L0f0652b0:
/*  f0652b0:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0652b4:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f0652b8:	0fc0a294 */ 	jal	func0f028a50
/*  f0652bc:	27a70084 */ 	addiu	$a3,$sp,0x84
/*  f0652c0:	10400018 */ 	beqz	$v0,.L0f065324
/*  f0652c4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0652c8:	8fab00e4 */ 	lw	$t3,0xe4($sp)
/*  f0652cc:	27a90078 */ 	addiu	$t1,$sp,0x78
/*  f0652d0:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0652d4:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f0652d8:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f0652dc:	27a70084 */ 	addiu	$a3,$sp,0x84
/*  f0652e0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0652e4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0652e8:	0fc190e3 */ 	jal	func0f06438c
/*  f0652ec:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0652f0:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f0652f4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0652f8:	4502000b */ 	bc1fl	.L0f065328
/*  f0652fc:	8eaa0348 */ 	lw	$t2,0x348($s5)
/*  f065300:	44812000 */ 	mtc1	$at,$f4
/*  f065304:	c7ac0078 */ 	lwc1	$f12,0x78($sp)
/*  f065308:	c7a2007c */ 	lwc1	$f2,0x7c($sp)
/*  f06530c:	4600203e */ 	c.le.s	$f4,$f0
/*  f065310:	46000506 */ 	mov.s	$f20,$f0
/*  f065314:	02209825 */ 	or	$s3,$s1,$zero
/*  f065318:	e7ac00ec */ 	swc1	$f12,0xec($sp)
/*  f06531c:	45010006 */ 	bc1t	.L0f065338
/*  f065320:	e7a200f0 */ 	swc1	$f2,0xf0($sp)
.L0f065324:
/*  f065324:	8eaa0348 */ 	lw	$t2,0x348($s5)
.L0f065328:
/*  f065328:	2652fffc */ 	addiu	$s2,$s2,-4
/*  f06532c:	024a082b */ 	sltu	$at,$s2,$t2
/*  f065330:	5020ffb6 */ 	beqzl	$at,.L0f06520c
/*  f065334:	8e510000 */ 	lw	$s1,0x0($s2)
.L0f065338:
/*  f065338:	12600058 */ 	beqz	$s3,.L0f06549c
/*  f06533c:	00002025 */ 	or	$a0,$zero,$zero
/*  f065340:	0fc31ea3 */ 	jal	func0f0c7a8c
/*  f065344:	00000000 */ 	nop
/*  f065348:	14400003 */ 	bnez	$v0,.L0f065358
/*  f06534c:	8fac00e0 */ 	lw	$t4,0xe0($sp)
/*  f065350:	11800012 */ 	beqz	$t4,.L0f06539c
/*  f065354:	00000000 */ 	nop
.L0f065358:
/*  f065358:	0fc2d602 */ 	jal	currentPlayerGetScreenTop
/*  f06535c:	00000000 */ 	nop
/*  f065360:	0fc2d5fa */ 	jal	currentPlayerGetScreenHeight
/*  f065364:	46000506 */ 	mov.s	$f20,$f0
/*  f065368:	3c013f00 */ 	lui	$at,0x3f00
/*  f06536c:	44814000 */ 	mtc1	$at,$f8
/*  f065370:	c7a200f0 */ 	lwc1	$f2,0xf0($sp)
/*  f065374:	3c013f80 */ 	lui	$at,0x3f80
/*  f065378:	46080482 */ 	mul.s	$f18,$f0,$f8
/*  f06537c:	46141181 */ 	sub.s	$f6,$f2,$f20
/*  f065380:	44818000 */ 	mtc1	$at,$f16
/*  f065384:	02602025 */ 	or	$a0,$s3,$zero
/*  f065388:	46123283 */ 	div.s	$f10,$f6,$f18
/*  f06538c:	46105101 */ 	sub.s	$f4,$f10,$f16
/*  f065390:	44052000 */ 	mfc1	$a1,$f4
/*  f065394:	0fc31ec0 */ 	jal	currentPlayerUpdateAutoAimYProp
/*  f065398:	00000000 */ 	nop
.L0f06539c:
/*  f06539c:	0fc31ef4 */ 	jal	func0f0c7bd0
/*  f0653a0:	00000000 */ 	nop
/*  f0653a4:	14400003 */ 	bnez	$v0,.L0f0653b4
/*  f0653a8:	8fad00e0 */ 	lw	$t5,0xe0($sp)
/*  f0653ac:	51a00013 */ 	beqzl	$t5,.L0f0653fc
/*  f0653b0:	8fb900e4 */ 	lw	$t9,0xe4($sp)
.L0f0653b4:
/*  f0653b4:	0fc2d5fe */ 	jal	currentPlayerGetScreenLeft
/*  f0653b8:	00000000 */ 	nop
/*  f0653bc:	0fc2d5f6 */ 	jal	currentPlayerGetScreenWidth
/*  f0653c0:	46000506 */ 	mov.s	$f20,$f0
/*  f0653c4:	3c013f00 */ 	lui	$at,0x3f00
/*  f0653c8:	44813000 */ 	mtc1	$at,$f6
/*  f0653cc:	c7ac00ec */ 	lwc1	$f12,0xec($sp)
/*  f0653d0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0653d4:	46060482 */ 	mul.s	$f18,$f0,$f6
/*  f0653d8:	46146201 */ 	sub.s	$f8,$f12,$f20
/*  f0653dc:	44818000 */ 	mtc1	$at,$f16
/*  f0653e0:	02602025 */ 	or	$a0,$s3,$zero
/*  f0653e4:	46124283 */ 	div.s	$f10,$f8,$f18
/*  f0653e8:	46105101 */ 	sub.s	$f4,$f10,$f16
/*  f0653ec:	44052000 */ 	mfc1	$a1,$f4
/*  f0653f0:	0fc31f0d */ 	jal	currentPlayerUpdateAutoAimXProp
/*  f0653f4:	00000000 */ 	nop
/*  f0653f8:	8fb900e4 */ 	lw	$t9,0xe4($sp)
.L0f0653fc:
/*  f0653fc:	53200023 */ 	beqzl	$t9,.L0f06548c
/*  f065400:	8ea20284 */ 	lw	$v0,0x284($s5)
/*  f065404:	8ea20284 */ 	lw	$v0,0x284($s5)
/*  f065408:	c6680008 */ 	lwc1	$f8,0x8($s3)
/*  f06540c:	c66a000c */ 	lwc1	$f10,0xc($s3)
/*  f065410:	c446037c */ 	lwc1	$f6,0x37c($v0)
/*  f065414:	c4520380 */ 	lwc1	$f18,0x380($v0)
/*  f065418:	c6640010 */ 	lwc1	$f4,0x10($s3)
/*  f06541c:	46083001 */ 	sub.s	$f0,$f6,$f8
/*  f065420:	c4500384 */ 	lwc1	$f16,0x384($v0)
/*  f065424:	460a9081 */ 	sub.s	$f2,$f18,$f10
/*  f065428:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f06542c:	46048381 */ 	sub.s	$f14,$f16,$f4
/*  f065430:	46021202 */ 	mul.s	$f8,$f2,$f2
/*  f065434:	46083480 */ 	add.s	$f18,$f6,$f8
/*  f065438:	460e7282 */ 	mul.s	$f10,$f14,$f14
/*  f06543c:	0c012974 */ 	jal	sqrtf
/*  f065440:	460a9300 */ 	add.s	$f12,$f18,$f10
/*  f065444:	3c014348 */ 	lui	$at,0x4348
/*  f065448:	44818000 */ 	mtc1	$at,$f16
/*  f06544c:	00000000 */ 	nop
/*  f065450:	4610003c */ 	c.lt.s	$f0,$f16
/*  f065454:	00000000 */ 	nop
/*  f065458:	45020007 */ 	bc1fl	.L0f065478
/*  f06545c:	8ea20284 */ 	lw	$v0,0x284($s5)
/*  f065460:	8ea20284 */ 	lw	$v0,0x284($s5)
/*  f065464:	904e1583 */ 	lbu	$t6,0x1583($v0)
/*  f065468:	35cf0010 */ 	ori	$t7,$t6,0x10
/*  f06546c:	10000014 */ 	b	.L0f0654c0
/*  f065470:	a04f1583 */ 	sb	$t7,0x1583($v0)
/*  f065474:	8ea20284 */ 	lw	$v0,0x284($s5)
.L0f065478:
/*  f065478:	90481583 */ 	lbu	$t0,0x1583($v0)
/*  f06547c:	3109ffef */ 	andi	$t1,$t0,0xffef
/*  f065480:	1000000f */ 	b	.L0f0654c0
/*  f065484:	a0491583 */ 	sb	$t1,0x1583($v0)
/*  f065488:	8ea20284 */ 	lw	$v0,0x284($s5)
.L0f06548c:
/*  f06548c:	904b1583 */ 	lbu	$t3,0x1583($v0)
/*  f065490:	316affef */ 	andi	$t2,$t3,0xffef
/*  f065494:	1000000a */ 	b	.L0f0654c0
/*  f065498:	a04a1583 */ 	sb	$t2,0x1583($v0)
.L0f06549c:
/*  f06549c:	0fc31ec0 */ 	jal	currentPlayerUpdateAutoAimYProp
/*  f0654a0:	24050000 */ 	addiu	$a1,$zero,0x0
/*  f0654a4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0654a8:	0fc31f0d */ 	jal	currentPlayerUpdateAutoAimXProp
/*  f0654ac:	24050000 */ 	addiu	$a1,$zero,0x0
/*  f0654b0:	8ea20284 */ 	lw	$v0,0x284($s5)
/*  f0654b4:	904c1583 */ 	lbu	$t4,0x1583($v0)
/*  f0654b8:	318dffef */ 	andi	$t5,$t4,0xffef
/*  f0654bc:	a04d1583 */ 	sb	$t5,0x1583($v0)
.L0f0654c0:
/*  f0654c0:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0654c4:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f0654c8:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f0654cc:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f0654d0:	8fb20034 */ 	lw	$s2,0x34($sp)
/*  f0654d4:	8fb30038 */ 	lw	$s3,0x38($sp)
/*  f0654d8:	8fb4003c */ 	lw	$s4,0x3c($sp)
/*  f0654dc:	8fb50040 */ 	lw	$s5,0x40($sp)
/*  f0654e0:	03e00008 */ 	jr	$ra
/*  f0654e4:	27bd00f8 */ 	addiu	$sp,$sp,0xf8
);

u32 func0f0654e8(struct prop *prop)
{
	struct doorobj *door = prop->door;
	u32 flags;

	if (door->frac <= 0) {
		flags = 0x1000;
	} else if (door->frac >= door->maxfrac) {
		flags = 0x2000;
	} else {
		flags = 0x4000;
	}

	if (door->base.flags2 & OBJFLAG2_AICANNOTUSE) {
		flags |= 0x8000;
	}

	return flags;
}

bool func0f06554c(struct prop *prop, u32 flags)
{
	bool result = true;

	if (prop->type == PROPTYPE_DOOR) {
		if (flags & 0x0100) {
			struct defaultobj *obj = prop->obj;

			if (obj->flags & OBJFLAG_04000000) {
				result = false;
			}
		}

		if (flags & 0x0800) {
			struct defaultobj *obj = prop->obj;

			if (obj->flags3 & OBJFLAG3_80000000) {
				result = false;
			}
		}

		if ((flags & 0x0002) == 0) {
			if ((func0f0654e8(prop) & flags) == 0) {
				result = false;
			}
		}
	} else if (prop->type == PROPTYPE_PLAYER) {
		if ((flags & 0x0004) == 0) {
			result = false;
		} else {
			struct player *player = g_Vars.players[propGetPlayerNum(prop)];

			if (!player->bondperimenabled || (g_Vars.mplayerisrunning && player->isdead)) {
				result = false;
			}
		}
	} else if (prop->type == PROPTYPE_CHR) {
		if ((flags & 0x0008) == 0) {
			result = false;
		} else {
			struct chrdata *chr = prop->chr;

			if (chr->actiontype == ACT_DEAD
					|| (chr->chrflags & (CHRCFLAG_HIDDEN | CHRCFLAG_00010000))
					|| (chr->hidden & CHRHFLAG_00000100)) {
				result = false;
			}
		}
	} else if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON) {
		struct defaultobj *obj = prop->obj;

		if (obj->geo == NULL) {
			result = false;
		} else {
			if ((flags & 0x0100) && (obj->flags & OBJFLAG_04000000)) {
				result = false;
			}

			if ((flags & 0x0080)
					&& (obj->flags & OBJFLAG_INVINCIBLE) == 0
					&& (obj->flags2 & OBJFLAG2_00004000) == 0) {
				result = false;
			}

			if ((flags & 0x0200)
					&& (obj->flags & OBJFLAG_INVINCIBLE) == 0
					&& (obj->flags2 & OBJFLAG2_00200000) == 0) {
				result = false;
			}

			if ((flags & 0x0400)
					&& (obj->type == OBJTYPE_SAFE || obj->type == OBJTYPE_HELI)) {
				result = false;
			}

			if ((obj->flags & OBJFLAG_00000800)) {
				if ((flags & 0x0010) == 0) {
					result = false;
				}
			} else {
				if ((flags & 0x0001) == 0) {
					result = false;
				}
			}
		}
	}

	return result;
}

void roomsCopy(s16 *src, s16 *dst)
{
	s16 *srcptr = src;
	s16 *dstptr = dst;
	s32 val;

	while ((val = *srcptr) != -1) {
		*dstptr = val;
		srcptr++;
		dstptr++;
	}

	*dstptr = -1;
}

GLOBAL_ASM(
glabel func0f0657d8
/*  f0657d8:	27bdfff8 */ 	addiu	$sp,$sp,-8
/*  f0657dc:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f0657e0:	848e0000 */ 	lh	$t6,0x0($a0)
/*  f0657e4:	00c08025 */ 	or	$s0,$a2,$zero
/*  f0657e8:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0657ec:	110e0021 */ 	beq	$t0,$t6,.L0f065874
/*  f0657f0:	00803025 */ 	or	$a2,$a0,$zero
/*  f0657f4:	84af0000 */ 	lh	$t7,0x0($a1)
.L0f0657f8:
/*  f0657f8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0657fc:	510f000f */ 	beql	$t0,$t7,.L0f06583c
/*  f065800:	00024840 */ 	sll	$t1,$v0,0x1
/*  f065804:	84c70000 */ 	lh	$a3,0x0($a2)
/*  f065808:	84b80000 */ 	lh	$t8,0x0($a1)
/*  f06580c:	0000c840 */ 	sll	$t9,$zero,0x1
/*  f065810:	00b91821 */ 	addu	$v1,$a1,$t9
/*  f065814:	53070009 */ 	beql	$t8,$a3,.L0f06583c
/*  f065818:	00024840 */ 	sll	$t1,$v0,0x1
/*  f06581c:	84640002 */ 	lh	$a0,0x2($v1)
.L0f065820:
/*  f065820:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f065824:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f065828:	51040004 */ 	beql	$t0,$a0,.L0f06583c
/*  f06582c:	00024840 */ 	sll	$t1,$v0,0x1
/*  f065830:	5487fffb */ 	bnel	$a0,$a3,.L0f065820
/*  f065834:	84640002 */ 	lh	$a0,0x2($v1)
/*  f065838:	00024840 */ 	sll	$t1,$v0,0x1
.L0f06583c:
/*  f06583c:	00a91821 */ 	addu	$v1,$a1,$t1
/*  f065840:	846a0000 */ 	lh	$t2,0x0($v1)
/*  f065844:	0050082a */ 	slt	$at,$v0,$s0
/*  f065848:	550a0007 */ 	bnel	$t0,$t2,.L0f065868
/*  f06584c:	84cc0002 */ 	lh	$t4,0x2($a2)
/*  f065850:	50200005 */ 	beqzl	$at,.L0f065868
/*  f065854:	84cc0002 */ 	lh	$t4,0x2($a2)
/*  f065858:	84cb0000 */ 	lh	$t3,0x0($a2)
/*  f06585c:	a4680002 */ 	sh	$t0,0x2($v1)
/*  f065860:	a46b0000 */ 	sh	$t3,0x0($v1)
/*  f065864:	84cc0002 */ 	lh	$t4,0x2($a2)
.L0f065868:
/*  f065868:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f06586c:	550cffe2 */ 	bnel	$t0,$t4,.L0f0657f8
/*  f065870:	84af0000 */ 	lh	$t7,0x0($a1)
.L0f065874:
/*  f065874:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f065878:	03e00008 */ 	jr	$ra
/*  f06587c:	27bd0008 */ 	addiu	$sp,$sp,0x8
);

GLOBAL_ASM(
glabel arrayIntersects
/*  f065880:	84830000 */ 	lh	$v1,0x0($a0)
/*  f065884:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f065888:	00801025 */ 	or	$v0,$a0,$zero
/*  f06588c:	50680014 */ 	beql	$v1,$t0,.L0f0658e0
/*  f065890:	00001025 */ 	or	$v0,$zero,$zero
/*  f065894:	84a70000 */ 	lh	$a3,0x0($a1)
/*  f065898:	00073400 */ 	sll	$a2,$a3,0x10
.L0f06589c:
/*  f06589c:	00067403 */ 	sra	$t6,$a2,0x10
/*  f0658a0:	01c03025 */ 	or	$a2,$t6,$zero
/*  f0658a4:	11c80009 */ 	beq	$t6,$t0,.L0f0658cc
/*  f0658a8:	00a02025 */ 	or	$a0,$a1,$zero
.L0f0658ac:
/*  f0658ac:	54660004 */ 	bnel	$v1,$a2,.L0f0658c0
/*  f0658b0:	84860002 */ 	lh	$a2,0x2($a0)
/*  f0658b4:	03e00008 */ 	jr	$ra
/*  f0658b8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0658bc:	84860002 */ 	lh	$a2,0x2($a0)
.L0f0658c0:
/*  f0658c0:	24840002 */ 	addiu	$a0,$a0,0x2
/*  f0658c4:	14c8fff9 */ 	bne	$a2,$t0,.L0f0658ac
/*  f0658c8:	00000000 */ 	nop
.L0f0658cc:
/*  f0658cc:	84430002 */ 	lh	$v1,0x2($v0)
/*  f0658d0:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0658d4:	5468fff1 */ 	bnel	$v1,$t0,.L0f06589c
/*  f0658d8:	00073400 */ 	sll	$a2,$a3,0x10
/*  f0658dc:	00001025 */ 	or	$v0,$zero,$zero
.L0f0658e0:
/*  f0658e0:	03e00008 */ 	jr	$ra
/*  f0658e4:	00000000 */ 	nop
);

bool func0f0658e8(s16 arg0, s32 arg1)
{
	s32 i;

	for (i = 0; i < 7; i++) {
		if (var8009cda4[arg1].unk00[i] < 0) {
			var8009cda4[arg1].unk00[i] = arg0;
			return true;
		}
	}

	return false;
}

GLOBAL_ASM(
glabel func0f06593c
/*  f06593c:	00803025 */ 	or	$a2,$a0,$zero
/*  f065940:	3c02800a */ 	lui	$v0,%hi(var8009cda4)
/*  f065944:	8c42cda4 */ 	lw	$v0,%lo(var8009cda4)($v0)
/*  f065948:	2404fffe */ 	addiu	$a0,$zero,-2
/*  f06594c:	00001825 */ 	or	$v1,$zero,$zero
/*  f065950:	24070100 */ 	addiu	$a3,$zero,0x100
.L0f065954:
/*  f065954:	844e0000 */ 	lh	$t6,0x0($v0)
/*  f065958:	548e001d */ 	bnel	$a0,$t6,.L0f0659d0
/*  f06595c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f065960:	3c02800a */ 	lui	$v0,%hi(var8009cda4)
/*  f065964:	2442cda4 */ 	addiu	$v0,$v0,%lo(var8009cda4)
/*  f065968:	00002025 */ 	or	$a0,$zero,$zero
/*  f06596c:	24080010 */ 	addiu	$t0,$zero,0x10
/*  f065970:	2407ffff */ 	addiu	$a3,$zero,-1
.L0f065974:
/*  f065974:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f065978:	0003c100 */ 	sll	$t8,$v1,0x4
/*  f06597c:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f065980:	03244821 */ 	addu	$t1,$t9,$a0
/*  f065984:	24840002 */ 	addiu	$a0,$a0,0x2
/*  f065988:	1488fffa */ 	bne	$a0,$t0,.L0f065974
/*  f06598c:	a5270000 */ 	sh	$a3,0x0($t1)
/*  f065990:	04a00007 */ 	bltz	$a1,.L0f0659b0
/*  f065994:	00000000 */ 	nop
/*  f065998:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*  f06599c:	00055900 */ 	sll	$t3,$a1,0x4
/*  f0659a0:	00601025 */ 	or	$v0,$v1,$zero
/*  f0659a4:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f0659a8:	03e00008 */ 	jr	$ra
/*  f0659ac:	a583000e */ 	sh	$v1,0xe($t4)
.L0f0659b0:
/*  f0659b0:	3c0d800a */ 	lui	$t5,%hi(var8009cda0)
/*  f0659b4:	8dadcda0 */ 	lw	$t5,%lo(var8009cda0)($t5)
/*  f0659b8:	00067040 */ 	sll	$t6,$a2,0x1
/*  f0659bc:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0659c0:	a5e30000 */ 	sh	$v1,0x0($t7)
/*  f0659c4:	03e00008 */ 	jr	$ra
/*  f0659c8:	00601025 */ 	or	$v0,$v1,$zero
/*  f0659cc:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f0659d0:
/*  f0659d0:	1467ffe0 */ 	bne	$v1,$a3,.L0f065954
/*  f0659d4:	24420010 */ 	addiu	$v0,$v0,16
/*  f0659d8:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0659dc:	03e00008 */ 	jr	$ra
/*  f0659e0:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0659e4
/*  f0659e4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f0659e8:	00053c00 */ 	sll	$a3,$a1,0x10
/*  f0659ec:	00077403 */ 	sra	$t6,$a3,0x10
/*  f0659f0:	01c03825 */ 	or	$a3,$t6,$zero
/*  f0659f4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0659f8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0659fc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f065a00:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f065a04:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f065a08:	05c0002f */ 	bltz	$t6,.L0f065ac8
/*  f065a0c:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f065a10:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f065a14:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f065a18:	8c4f02bc */ 	lw	$t7,0x2bc($v0)
/*  f065a1c:	3c18800a */ 	lui	$t8,%hi(var8009cda0)
/*  f065a20:	000ec840 */ 	sll	$t9,$t6,0x1
/*  f065a24:	01cf082a */ 	slt	$at,$t6,$t7
/*  f065a28:	50200028 */ 	beqzl	$at,.L0f065acc
/*  f065a2c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f065a30:	8c490338 */ 	lw	$t1,0x338($v0)
/*  f065a34:	24010048 */ 	addiu	$at,$zero,0x48
/*  f065a38:	8f18cda0 */ 	lw	$t8,%lo(var8009cda0)($t8)
/*  f065a3c:	00899023 */ 	subu	$s2,$a0,$t1
/*  f065a40:	0241001a */ 	div	$zero,$s2,$at
/*  f065a44:	03194021 */ 	addu	$t0,$t8,$t9
/*  f065a48:	85100000 */ 	lh	$s0,0x0($t0)
/*  f065a4c:	00005012 */ 	mflo	$t2
/*  f065a50:	000a5c00 */ 	sll	$t3,$t2,0x10
/*  f065a54:	06000013 */ 	bltz	$s0,.L0f065aa4
/*  f065a58:	000b9403 */ 	sra	$s2,$t3,0x10
/*  f065a5c:	3c11800a */ 	lui	$s1,%hi(var8009cda4)
/*  f065a60:	2631cda4 */ 	addiu	$s1,$s1,%lo(var8009cda4)
/*  f065a64:	a7ae002e */ 	sh	$t6,0x2e($sp)
/*  f065a68:	00122400 */ 	sll	$a0,$s2,0x10
.L0f065a6c:
/*  f065a6c:	00046c03 */ 	sra	$t5,$a0,0x10
/*  f065a70:	01a02025 */ 	or	$a0,$t5,$zero
/*  f065a74:	0fc1963a */ 	jal	func0f0658e8
/*  f065a78:	02002825 */ 	or	$a1,$s0,$zero
/*  f065a7c:	54400013 */ 	bnezl	$v0,.L0f065acc
/*  f065a80:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f065a84:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f065a88:	00107900 */ 	sll	$t7,$s0,0x4
/*  f065a8c:	02003025 */ 	or	$a2,$s0,$zero
/*  f065a90:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f065a94:	8710000e */ 	lh	$s0,0xe($t8)
/*  f065a98:	0603fff4 */ 	bgezl	$s0,.L0f065a6c
/*  f065a9c:	00122400 */ 	sll	$a0,$s2,0x10
/*  f065aa0:	87a7002e */ 	lh	$a3,0x2e($sp)
.L0f065aa4:
/*  f065aa4:	00e02025 */ 	or	$a0,$a3,$zero
/*  f065aa8:	0fc1964f */ 	jal	func0f06593c
/*  f065aac:	00c02825 */ 	or	$a1,$a2,$zero
/*  f065ab0:	04400005 */ 	bltz	$v0,.L0f065ac8
/*  f065ab4:	00122400 */ 	sll	$a0,$s2,0x10
/*  f065ab8:	0004cc03 */ 	sra	$t9,$a0,0x10
/*  f065abc:	03202025 */ 	or	$a0,$t9,$zero
/*  f065ac0:	0fc1963a */ 	jal	func0f0658e8
/*  f065ac4:	00402825 */ 	or	$a1,$v0,$zero
.L0f065ac8:
/*  f065ac8:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f065acc:
/*  f065acc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f065ad0:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f065ad4:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f065ad8:	03e00008 */ 	jr	$ra
/*  f065adc:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f065ae0
/*  f065ae0:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*  f065ae4:	00057400 */ 	sll	$t6,$a1,0x10
/*  f065ae8:	000e7c03 */ 	sra	$t7,$t6,0x10
/*  f065aec:	afb1000c */ 	sw	$s1,0xc($sp)
/*  f065af0:	afb00008 */ 	sw	$s0,0x8($sp)
/*  f065af4:	afa40010 */ 	sw	$a0,0x10($sp)
/*  f065af8:	afa50014 */ 	sw	$a1,0x14($sp)
/*  f065afc:	00001025 */ 	or	$v0,$zero,$zero
/*  f065b00:	05e0004c */ 	bltz	$t7,.L0f065c34
/*  f065b04:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f065b08:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f065b0c:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f065b10:	8d1802bc */ 	lw	$t8,0x2bc($t0)
/*  f065b14:	3c0b800a */ 	lui	$t3,%hi(var8009cda0)
/*  f065b18:	256bcda0 */ 	addiu	$t3,$t3,%lo(var8009cda0)
/*  f065b1c:	01f8082a */ 	slt	$at,$t7,$t8
/*  f065b20:	10200044 */ 	beqz	$at,.L0f065c34
/*  f065b24:	000f3040 */ 	sll	$a2,$t7,0x1
/*  f065b28:	8faf0010 */ 	lw	$t7,0x10($sp)
/*  f065b2c:	8d180338 */ 	lw	$t8,0x338($t0)
/*  f065b30:	24010048 */ 	addiu	$at,$zero,0x48
/*  f065b34:	8d790000 */ 	lw	$t9,0x0($t3)
/*  f065b38:	01f83823 */ 	subu	$a3,$t7,$t8
/*  f065b3c:	00e1001a */ 	div	$zero,$a3,$at
/*  f065b40:	03267021 */ 	addu	$t6,$t9,$a2
/*  f065b44:	85c40000 */ 	lh	$a0,0x0($t6)
/*  f065b48:	0000c812 */ 	mflo	$t9
/*  f065b4c:	00197400 */ 	sll	$t6,$t9,0x10
/*  f065b50:	04800038 */ 	bltz	$a0,.L0f065c34
/*  f065b54:	000e3c03 */ 	sra	$a3,$t6,0x10
/*  f065b58:	3c0c800a */ 	lui	$t4,%hi(var8009cda4)
/*  f065b5c:	258ccda4 */ 	addiu	$t4,$t4,%lo(var8009cda4)
/*  f065b60:	2411fffe */ 	addiu	$s1,$zero,-2
/*  f065b64:	2410000e */ 	addiu	$s0,$zero,0xe
/*  f065b68:	240dffff */ 	addiu	$t5,$zero,-1
/*  f065b6c:	00002825 */ 	or	$a1,$zero,$zero
.L0f065b70:
/*  f065b70:	00004825 */ 	or	$t1,$zero,$zero
/*  f065b74:	8d980000 */ 	lw	$t8,0x0($t4)
.L0f065b78:
/*  f065b78:	0004c900 */ 	sll	$t9,$a0,0x4
/*  f065b7c:	03197021 */ 	addu	$t6,$t8,$t9
/*  f065b80:	01c94021 */ 	addu	$t0,$t6,$t1
/*  f065b84:	850a0000 */ 	lh	$t2,0x0($t0)
/*  f065b88:	25290002 */ 	addiu	$t1,$t1,0x2
/*  f065b8c:	14ea0004 */ 	bne	$a3,$t2,.L0f065ba0
/*  f065b90:	00000000 */ 	nop
/*  f065b94:	a50d0000 */ 	sh	$t5,0x0($t0)
/*  f065b98:	10000006 */ 	b	.L0f065bb4
/*  f065b9c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f065ba0:
/*  f065ba0:	14a00004 */ 	bnez	$a1,.L0f065bb4
/*  f065ba4:	00000000 */ 	nop
/*  f065ba8:	05400002 */ 	bltz	$t2,.L0f065bb4
/*  f065bac:	00000000 */ 	nop
/*  f065bb0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f065bb4:
/*  f065bb4:	5530fff0 */ 	bnel	$t1,$s0,.L0f065b78
/*  f065bb8:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f065bbc:	54a00015 */ 	bnezl	$a1,.L0f065c14
/*  f065bc0:	00801825 */ 	or	$v1,$a0,$zero
/*  f065bc4:	8d8f0000 */ 	lw	$t7,0x0($t4)
/*  f065bc8:	00044100 */ 	sll	$t0,$a0,0x4
/*  f065bcc:	01e8c021 */ 	addu	$t8,$t7,$t0
/*  f065bd0:	04600008 */ 	bltz	$v1,.L0f065bf4
/*  f065bd4:	a7110000 */ 	sh	$s1,0x0($t8)
/*  f065bd8:	8d850000 */ 	lw	$a1,0x0($t4)
/*  f065bdc:	00037900 */ 	sll	$t7,$v1,0x4
/*  f065be0:	00a8c821 */ 	addu	$t9,$a1,$t0
/*  f065be4:	872e000e */ 	lh	$t6,0xe($t9)
/*  f065be8:	00afc021 */ 	addu	$t8,$a1,$t7
/*  f065bec:	10000009 */ 	b	.L0f065c14
/*  f065bf0:	a70e000e */ 	sh	$t6,0xe($t8)
.L0f065bf4:
/*  f065bf4:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f065bf8:	8d780000 */ 	lw	$t8,0x0($t3)
/*  f065bfc:	03287821 */ 	addu	$t7,$t9,$t0
/*  f065c00:	85ee000e */ 	lh	$t6,0xe($t7)
/*  f065c04:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f065c08:	10000002 */ 	b	.L0f065c14
/*  f065c0c:	a72e0000 */ 	sh	$t6,0x0($t9)
/*  f065c10:	00801825 */ 	or	$v1,$a0,$zero
.L0f065c14:
/*  f065c14:	54400008 */ 	bnezl	$v0,.L0f065c38
/*  f065c18:	8fb00008 */ 	lw	$s0,0x8($sp)
/*  f065c1c:	8d8f0000 */ 	lw	$t7,0x0($t4)
/*  f065c20:	0004c100 */ 	sll	$t8,$a0,0x4
/*  f065c24:	01f87021 */ 	addu	$t6,$t7,$t8
/*  f065c28:	85c4000e */ 	lh	$a0,0xe($t6)
/*  f065c2c:	0483ffd0 */ 	bgezl	$a0,.L0f065b70
/*  f065c30:	00002825 */ 	or	$a1,$zero,$zero
.L0f065c34:
/*  f065c34:	8fb00008 */ 	lw	$s0,0x8($sp)
.L0f065c38:
/*  f065c38:	8fb1000c */ 	lw	$s1,0xc($sp)
/*  f065c3c:	03e00008 */ 	jr	$ra
/*  f065c40:	27bd0010 */ 	addiu	$sp,$sp,0x10
);

void func0f065c44(struct prop *prop)
{
	s16 *rooms = prop->rooms;
	s16 room = *rooms;

	while (room != -1) {
		func0f065ae0(prop, room);
		rooms++;
		room = *rooms;
	}
}

void func0f065cb0(struct prop *prop)
{
	s16 *rooms = prop->rooms;
	s16 room = *rooms;

	while (room != -1) {
		func0f0659e4(prop, room);
		rooms++;
		room = *rooms;
	}
}

GLOBAL_ASM(
glabel func0f065d1c
/*  f065d1c:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f065d20:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f065d24:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f065d28:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f065d2c:	00c09025 */ 	or	$s2,$a2,$zero
/*  f065d30:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f065d34:	00e09825 */ 	or	$s3,$a3,$zero
/*  f065d38:	00a03025 */ 	or	$a2,$a1,$zero
/*  f065d3c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f065d40:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f065d44:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f065d48:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f065d4c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f065d50:	02402825 */ 	or	$a1,$s2,$zero
/*  f065d54:	27a70048 */ 	addiu	$a3,$sp,0x48
/*  f065d58:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f065d5c:	0c006052 */ 	jal	func00018148
/*  f065d60:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f065d64:	87b80048 */ 	lh	$t8,0x48($sp)
/*  f065d68:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f065d6c:	00008825 */ 	or	$s1,$zero,$zero
/*  f065d70:	1298000e */ 	beq	$s4,$t8,.L0f065dac
/*  f065d74:	27b00048 */ 	addiu	$s0,$sp,0x48
/*  f065d78:	86050000 */ 	lh	$a1,0x0($s0)
.L0f065d7c:
/*  f065d7c:	0fc586b7 */ 	jal	func0f161adc
/*  f065d80:	02402025 */ 	or	$a0,$s2,$zero
/*  f065d84:	10400005 */ 	beqz	$v0,.L0f065d9c
/*  f065d88:	00114840 */ 	sll	$t1,$s1,0x1
/*  f065d8c:	86080000 */ 	lh	$t0,0x0($s0)
/*  f065d90:	02695021 */ 	addu	$t2,$s3,$t1
/*  f065d94:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f065d98:	a5480000 */ 	sh	$t0,0x0($t2)
.L0f065d9c:
/*  f065d9c:	86050002 */ 	lh	$a1,0x2($s0)
/*  f065da0:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f065da4:	1685fff5 */ 	bne	$s4,$a1,.L0f065d7c
/*  f065da8:	00000000 */ 	nop
.L0f065dac:
/*  f065dac:	00115840 */ 	sll	$t3,$s1,0x1
/*  f065db0:	026b6021 */ 	addu	$t4,$s3,$t3
/*  f065db4:	a5940000 */ 	sh	$s4,0x0($t4)
/*  f065db8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f065dbc:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f065dc0:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f065dc4:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f065dc8:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f065dcc:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f065dd0:	03e00008 */ 	jr	$ra
/*  f065dd4:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

void func0f065dd8(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms)
{
	func0f065d1c(pos, rooms, newpos, newrooms, NULL, 0);
}

void func0f065dfc(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms, s16 *morerooms, u32 arg5)
{
	func0f065d1c(pos, rooms, newpos, newrooms, morerooms, arg5);

	if (newrooms[0] == -1) {
		func0f065e98(pos, rooms, newpos, newrooms);

		if (morerooms) {
			func0f0657d8(newrooms, morerooms, arg5);
		}
	}
}

void func0f065e74(struct coord *pos, s16 *rooms, struct coord *newpos, s16 *newrooms)
{
	func0f065dfc(pos, rooms, newpos, newrooms, NULL, 0);
}

GLOBAL_ASM(
glabel func0f065e98
/*  f065e98:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f065e9c:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f065ea0:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f065ea4:	00e08825 */ 	or	$s1,$a3,$zero
/*  f065ea8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f065eac:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f065eb0:	afa5009c */ 	sw	$a1,0x9c($sp)
/*  f065eb4:	afa600a0 */ 	sw	$a2,0xa0($sp)
/*  f065eb8:	00c02025 */ 	or	$a0,$a2,$zero
/*  f065ebc:	00008025 */ 	or	$s0,$zero,$zero
/*  f065ec0:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f065ec4:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f065ec8:	24070014 */ 	addiu	$a3,$zero,0x14
/*  f065ecc:	0fc58865 */ 	jal	func0f162194
/*  f065ed0:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f065ed4:	87ae006c */ 	lh	$t6,0x6c($sp)
/*  f065ed8:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f065edc:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f065ee0:	10ce0003 */ 	beq	$a2,$t6,.L0f065ef0
/*  f065ee4:	87af0040 */ 	lh	$t7,0x40($sp)
/*  f065ee8:	10000004 */ 	b	.L0f065efc
/*  f065eec:	27b0006c */ 	addiu	$s0,$sp,0x6c
.L0f065ef0:
/*  f065ef0:	10cf0002 */ 	beq	$a2,$t7,.L0f065efc
/*  f065ef4:	00000000 */ 	nop
/*  f065ef8:	27b00040 */ 	addiu	$s0,$sp,0x40
.L0f065efc:
/*  f065efc:	1200000c */ 	beqz	$s0,.L0f065f30
/*  f065f00:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f065f04:	0c00a900 */ 	jal	func0002a400
/*  f065f08:	02002825 */ 	or	$a1,$s0,$zero
/*  f065f0c:	18400004 */ 	blez	$v0,.L0f065f20
/*  f065f10:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f065f14:	a6220000 */ 	sh	$v0,0x0($s1)
/*  f065f18:	10000014 */ 	b	.L0f065f6c
/*  f065f1c:	a6260002 */ 	sh	$a2,0x2($s1)
.L0f065f20:
/*  f065f20:	86180000 */ 	lh	$t8,0x0($s0)
/*  f065f24:	a6260002 */ 	sh	$a2,0x2($s1)
/*  f065f28:	10000010 */ 	b	.L0f065f6c
/*  f065f2c:	a6380000 */ 	sh	$t8,0x0($s1)
.L0f065f30:
/*  f065f30:	84f90000 */ 	lh	$t9,0x0($a3)
/*  f065f34:	00002825 */ 	or	$a1,$zero,$zero
/*  f065f38:	02201825 */ 	or	$v1,$s1,$zero
/*  f065f3c:	10d90008 */ 	beq	$a2,$t9,.L0f065f60
/*  f065f40:	00e01025 */ 	or	$v0,$a3,$zero
/*  f065f44:	84e40000 */ 	lh	$a0,0x0($a3)
.L0f065f48:
/*  f065f48:	a4640000 */ 	sh	$a0,0x0($v1)
/*  f065f4c:	84440002 */ 	lh	$a0,0x2($v0)
/*  f065f50:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f065f54:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f065f58:	14c4fffb */ 	bne	$a2,$a0,.L0f065f48
/*  f065f5c:	24420002 */ 	addiu	$v0,$v0,0x2
.L0f065f60:
/*  f065f60:	00054040 */ 	sll	$t0,$a1,0x1
/*  f065f64:	02284821 */ 	addu	$t1,$s1,$t0
/*  f065f68:	a5260000 */ 	sh	$a2,0x0($t1)
.L0f065f6c:
/*  f065f6c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f065f70:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f065f74:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f065f78:	03e00008 */ 	jr	$ra
/*  f065f7c:	27bd0098 */ 	addiu	$sp,$sp,0x98
);

GLOBAL_ASM(
glabel roomGetProps
/*  f065f80:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f065f84:	84830000 */ 	lh	$v1,0x0($a0)
/*  f065f88:	240affff */ 	addiu	$t2,$zero,-1
/*  f065f8c:	00a01025 */ 	or	$v0,$a1,$zero
/*  f065f90:	106a002e */ 	beq	$v1,$t2,.L0f06604c
/*  f065f94:	240c000e */ 	addiu	$t4,$zero,0xe
/*  f065f98:	3c0b800a */ 	lui	$t3,%hi(var8009cda0)
/*  f065f9c:	256bcda0 */ 	addiu	$t3,$t3,%lo(var8009cda0)
/*  f065fa0:	8d6e0000 */ 	lw	$t6,0x0($t3)
.L0f065fa4:
/*  f065fa4:	00037840 */ 	sll	$t7,$v1,0x1
/*  f065fa8:	3c07800a */ 	lui	$a3,%hi(var8009cda4)
/*  f065fac:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f065fb0:	87060000 */ 	lh	$a2,0x0($t8)
/*  f065fb4:	04c20022 */ 	bltzl	$a2,.L0f066040
/*  f065fb8:	84830002 */ 	lh	$v1,0x2($a0)
/*  f065fbc:	8ce7cda4 */ 	lw	$a3,%lo(var8009cda4)($a3)
/*  f065fc0:	00004025 */ 	or	$t0,$zero,$zero
.L0f065fc4:
/*  f065fc4:	0006c900 */ 	sll	$t9,$a2,0x4
.L0f065fc8:
/*  f065fc8:	00f96821 */ 	addu	$t5,$a3,$t9
/*  f065fcc:	01a87021 */ 	addu	$t6,$t5,$t0
/*  f065fd0:	85c30000 */ 	lh	$v1,0x0($t6)
/*  f065fd4:	25080002 */ 	addiu	$t0,$t0,0x2
/*  f065fd8:	00a2082b */ 	sltu	$at,$a1,$v0
/*  f065fdc:	04600010 */ 	bltz	$v1,.L0f066020
/*  f065fe0:	00000000 */ 	nop
/*  f065fe4:	10200008 */ 	beqz	$at,.L0f066008
/*  f065fe8:	00a04825 */ 	or	$t1,$a1,$zero
/*  f065fec:	852f0000 */ 	lh	$t7,0x0($t1)
.L0f065ff0:
/*  f065ff0:	106f0005 */ 	beq	$v1,$t7,.L0f066008
/*  f065ff4:	00000000 */ 	nop
/*  f065ff8:	25290002 */ 	addiu	$t1,$t1,0x2
/*  f065ffc:	0122082b */ 	sltu	$at,$t1,$v0
/*  f066000:	5420fffb */ 	bnezl	$at,.L0f065ff0
/*  f066004:	852f0000 */ 	lh	$t7,0x0($t1)
.L0f066008:
/*  f066008:	15220005 */ 	bne	$t1,$v0,.L0f066020
/*  f06600c:	00000000 */ 	nop
/*  f066010:	a4430000 */ 	sh	$v1,0x0($v0)
/*  f066014:	3c07800a */ 	lui	$a3,%hi(var8009cda4)
/*  f066018:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f06601c:	8ce7cda4 */ 	lw	$a3,%lo(var8009cda4)($a3)
.L0f066020:
/*  f066020:	550cffe9 */ 	bnel	$t0,$t4,.L0f065fc8
/*  f066024:	0006c900 */ 	sll	$t9,$a2,0x4
/*  f066028:	0006c100 */ 	sll	$t8,$a2,0x4
/*  f06602c:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f066030:	8726000e */ 	lh	$a2,0xe($t9)
/*  f066034:	04c3ffe3 */ 	bgezl	$a2,.L0f065fc4
/*  f066038:	00004025 */ 	or	$t0,$zero,$zero
/*  f06603c:	84830002 */ 	lh	$v1,0x2($a0)
.L0f066040:
/*  f066040:	24840002 */ 	addiu	$a0,$a0,0x2
/*  f066044:	546affd7 */ 	bnel	$v1,$t2,.L0f065fa4
/*  f066048:	8d6e0000 */ 	lw	$t6,0x0($t3)
.L0f06604c:
/*  f06604c:	03e00008 */ 	jr	$ra
/*  f066050:	a44a0000 */ 	sh	$t2,0x0($v0)
);

GLOBAL_ASM(
glabel func0f066054
/*  f066054:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x2bc)
/*  f066058:	8c63a27c */ 	lw	$v1,%lo(g_Vars+0x2bc)($v1)
/*  f06605c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f066060:	afb30014 */ 	sw	$s3,0x14($sp)
/*  f066064:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f066068:	afb1000c */ 	sw	$s1,0xc($sp)
/*  f06606c:	afb00008 */ 	sw	$s0,0x8($sp)
/*  f066070:	1860005c */ 	blez	$v1,.L0f0661e4
/*  f066074:	00001025 */ 	or	$v0,$zero,$zero
/*  f066078:	3c0d800a */ 	lui	$t5,%hi(var8009cda4)
/*  f06607c:	3c0c800a */ 	lui	$t4,%hi(var8009cda0)
/*  f066080:	258ccda0 */ 	addiu	$t4,$t4,%lo(var8009cda0)
/*  f066084:	25adcda4 */ 	addiu	$t5,$t5,%lo(var8009cda4)
/*  f066088:	00002825 */ 	or	$a1,$zero,$zero
/*  f06608c:	2413000e */ 	addiu	$s3,$zero,0xe
/*  f066090:	2412fffe */ 	addiu	$s2,$zero,-2
/*  f066094:	2411000e */ 	addiu	$s1,$zero,0xe
/*  f066098:	2410ffff */ 	addiu	$s0,$zero,-1
.L0f06609c:
/*  f06609c:	8d8e0000 */ 	lw	$t6,0x0($t4)
/*  f0660a0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0660a4:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f0660a8:	85e40000 */ 	lh	$a0,0x0($t7)
/*  f0660ac:	0482004b */ 	bltzl	$a0,.L0f0661dc
/*  f0660b0:	0043082a */ 	slt	$at,$v0,$v1
/*  f0660b4:	8db80000 */ 	lw	$t8,0x0($t5)
/*  f0660b8:	0004c900 */ 	sll	$t9,$a0,0x4
/*  f0660bc:	03197021 */ 	addu	$t6,$t8,$t9
/*  f0660c0:	85c6000e */ 	lh	$a2,0xe($t6)
/*  f0660c4:	04c00044 */ 	bltz	$a2,.L0f0661d8
/*  f0660c8:	00004025 */ 	or	$t0,$zero,$zero
.L0f0660cc:
/*  f0660cc:	8da30000 */ 	lw	$v1,0x0($t5)
.L0f0660d0:
/*  f0660d0:	00047900 */ 	sll	$t7,$a0,0x4
/*  f0660d4:	00067100 */ 	sll	$t6,$a2,0x4
/*  f0660d8:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f0660dc:	03083821 */ 	addu	$a3,$t8,$t0
/*  f0660e0:	84f90000 */ 	lh	$t9,0x0($a3)
/*  f0660e4:	25080002 */ 	addiu	$t0,$t0,0x2
/*  f0660e8:	00005025 */ 	or	$t2,$zero,$zero
/*  f0660ec:	0721002c */ 	bgez	$t9,.L0f0661a0
/*  f0660f0:	006e5821 */ 	addu	$t3,$v1,$t6
.L0f0660f4:
/*  f0660f4:	85630000 */ 	lh	$v1,0x0($t3)
/*  f0660f8:	04620009 */ 	bltzl	$v1,.L0f066120
/*  f0660fc:	254a0002 */ 	addiu	$t2,$t2,0x2
/*  f066100:	a4e30000 */ 	sh	$v1,0x0($a3)
/*  f066104:	8daf0000 */ 	lw	$t7,0x0($t5)
/*  f066108:	0006c100 */ 	sll	$t8,$a2,0x4
/*  f06610c:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f066110:	032a7021 */ 	addu	$t6,$t9,$t2
/*  f066114:	10000004 */ 	b	.L0f066128
/*  f066118:	a5d00000 */ 	sh	$s0,0x0($t6)
/*  f06611c:	254a0002 */ 	addiu	$t2,$t2,0x2
.L0f066120:
/*  f066120:	1553fff4 */ 	bne	$t2,$s3,.L0f0660f4
/*  f066124:	256b0002 */ 	addiu	$t3,$t3,0x2
.L0f066128:
/*  f066128:	2941000e */ 	slti	$at,$t2,0xe
/*  f06612c:	1020000c */ 	beqz	$at,.L0f066160
/*  f066130:	00000000 */ 	nop
/*  f066134:	8daf0000 */ 	lw	$t7,0x0($t5)
/*  f066138:	0006c100 */ 	sll	$t8,$a2,0x4
/*  f06613c:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f066140:	032a5821 */ 	addu	$t3,$t9,$t2
.L0f066144:
/*  f066144:	856e0000 */ 	lh	$t6,0x0($t3)
/*  f066148:	05c10005 */ 	bgez	$t6,.L0f066160
/*  f06614c:	00000000 */ 	nop
/*  f066150:	254a0002 */ 	addiu	$t2,$t2,0x2
/*  f066154:	2941000e */ 	slti	$at,$t2,0xe
/*  f066158:	1420fffa */ 	bnez	$at,.L0f066144
/*  f06615c:	256b0002 */ 	addiu	$t3,$t3,0x2
.L0f066160:
/*  f066160:	55510010 */ 	bnel	$t2,$s1,.L0f0661a4
/*  f066164:	2901000e */ 	slti	$at,$t0,0xe
/*  f066168:	8daf0000 */ 	lw	$t7,0x0($t5)
/*  f06616c:	00064900 */ 	sll	$t1,$a2,0x4
/*  f066170:	00043900 */ 	sll	$a3,$a0,0x4
/*  f066174:	01e9c021 */ 	addu	$t8,$t7,$t1
/*  f066178:	a7120000 */ 	sh	$s2,0x0($t8)
/*  f06617c:	8da30000 */ 	lw	$v1,0x0($t5)
/*  f066180:	0069c821 */ 	addu	$t9,$v1,$t1
/*  f066184:	872e000e */ 	lh	$t6,0xe($t9)
/*  f066188:	00677821 */ 	addu	$t7,$v1,$a3
/*  f06618c:	a5ee000e */ 	sh	$t6,0xe($t7)
/*  f066190:	8db80000 */ 	lw	$t8,0x0($t5)
/*  f066194:	0307c821 */ 	addu	$t9,$t8,$a3
/*  f066198:	8726000e */ 	lh	$a2,0xe($t9)
/*  f06619c:	04c00003 */ 	bltz	$a2,.L0f0661ac
.L0f0661a0:
/*  f0661a0:	2901000e */ 	slti	$at,$t0,0xe
.L0f0661a4:
/*  f0661a4:	5420ffca */ 	bnezl	$at,.L0f0660d0
/*  f0661a8:	8da30000 */ 	lw	$v1,0x0($t5)
.L0f0661ac:
/*  f0661ac:	04c00006 */ 	bltz	$a2,.L0f0661c8
/*  f0661b0:	00000000 */ 	nop
/*  f0661b4:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f0661b8:	00067900 */ 	sll	$t7,$a2,0x4
/*  f0661bc:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0661c0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0661c4:	8706000e */ 	lh	$a2,0xe($t8)
.L0f0661c8:
/*  f0661c8:	04c3ffc0 */ 	bgezl	$a2,.L0f0660cc
/*  f0661cc:	00004025 */ 	or	$t0,$zero,$zero
/*  f0661d0:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x2bc)
/*  f0661d4:	8c63a27c */ 	lw	$v1,%lo(g_Vars+0x2bc)($v1)
.L0f0661d8:
/*  f0661d8:	0043082a */ 	slt	$at,$v0,$v1
.L0f0661dc:
/*  f0661dc:	1420ffaf */ 	bnez	$at,.L0f06609c
/*  f0661e0:	24a50002 */ 	addiu	$a1,$a1,0x2
.L0f0661e4:
/*  f0661e4:	8fb00008 */ 	lw	$s0,0x8($sp)
/*  f0661e8:	8fb1000c */ 	lw	$s1,0xc($sp)
/*  f0661ec:	8fb20010 */ 	lw	$s2,0x10($sp)
/*  f0661f0:	8fb30014 */ 	lw	$s3,0x14($sp)
/*  f0661f4:	03e00008 */ 	jr	$ra
/*  f0661f8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0661fc:	03e00008 */ 	jr	$ra
/*  f066200:	00000000 */ 	nop
);

void propGetBbox(struct prop *prop, f32 *width, f32 *ymax, f32 *ymin)
{
	if (prop->type == PROPTYPE_CHR) {
		propChrGetBbox(prop, width, ymax, ymin);
	} else if (prop->type == PROPTYPE_PLAYER) {
		propPlayerGetBbox(prop, width, ymax, ymin);
	} else if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_DOOR) {
		propObjGetBbox(prop, width, ymax, ymin);
	} else {
		*width = 0;
		*ymin = 0;
		*ymax = 0;
	}
}

bool propUpdateGeometry(struct prop *prop, struct geo **arg1, struct geo **arg2)
{
	bool result = false;

	if (prop->type == PROPTYPE_PLAYER) {
		result = playerUpdateGeometry(prop, arg1, arg2);
	} else if (prop->type == PROPTYPE_CHR) {
		result = chrUpdateGeometry(prop, arg1, arg2);
	} else if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_DOOR) {
		result = objUpdateGeometry(prop, arg1, arg2);
	}

	return result;
}
