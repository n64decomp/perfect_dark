#include <ultra64.h>
#include "constants.h"
#include "game/bondmove.h"
#include "game/bondwalk.h"
#include "game/chr/chraction.h"
#include "game/dlights.h"
#include "game/chr/chr.h"
#include "game/prop.h"
#include "game/game_092610.h"
#include "game/game_095320.h"
#include "game/floor.h"
#include "game/ceil.h"
#include "game/game_097ba0.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b3350.h"
#include "game/game_0b4950.h"
#include "game/game_0b69d0.h"
#include "game/game_127910.h"
#include "game/explosions/explosions.h"
#include "game/smoke/smoke.h"
#include "game/sparks/sparks.h"
#include "game/bg.h"
#include "game/game_190260.h"
#include "game/training/training.h"
#include "game/pad.h"
#include "game/propobj.h"
#include "game/splat.h"
#include "game/wallhit.h"
#include "game/mpstats.h"
#include "bss.h"
#include "lib/model.h"
#include "lib/snd.h"
#include "lib/rng.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_233c0.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

s16 *var8009cda0;
struct var8009cda4 *var8009cda4;
struct prop *var8009cda8;
u32 var8009cdac;
u32 var8009cdb0;
u32 var8009cdb4;
u32 var8009cdb8;
u32 var8009cdbc;

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

	gdl = currentPlayerScissorToViewport(gdl);

	return gdl;
}

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel weaponPlayWhooshSound
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
/*  f060ac4:	3c048009 */ 	lui	$a0,%hi(g_AudioManager+0x18)
/*  f060ac8:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f060acc:	0c012230 */ 	jal	osGetThreadPri
/*  f060ad0:	248415e0 */ 	addiu	$a0,$a0,%lo(g_AudioManager+0x18)
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
/*  f060b20:	0c004241 */ 	jal	sndStart
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
#else
GLOBAL_ASM(
glabel weaponPlayWhooshSound
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
/*  f05fc44:	3c013f80 */ 	lui	$at,0x3f80
/*  f05fc48:	44811000 */ 	mtc1	$at,$f2
/*  f05fc4c:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f05fc50:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f05fc54:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f05fc58:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f05fc5c:	14810005 */ 	bne	$a0,$at,.NB0f05fc74
/*  f05fc60:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f05fc64:	3c017f1a */ 	lui	$at,0x7f1a
/*  f05fc68:	240304fb */ 	addiu	$v1,$zero,0x4fb
/*  f05fc6c:	10000036 */ 	beqz	$zero,.NB0f05fd48
/*  f05fc70:	c4224164 */ 	lwc1	$f2,0x4164($at)
.NB0f05fc74:
/*  f05fc74:	24010014 */ 	addiu	$at,$zero,0x14
/*  f05fc78:	10810033 */ 	beq	$a0,$at,.NB0f05fd48
/*  f05fc7c:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f05fc80:	1481001d */ 	bne	$a0,$at,.NB0f05fcf8
/*  f05fc84:	e7a20048 */ 	swc1	$f2,0x48($sp)
/*  f05fc88:	0c004d84 */ 	jal	random
/*  f05fc8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05fc90:	304e0001 */ 	andi	$t6,$v0,0x1
/*  f05fc94:	24010001 */ 	addiu	$at,$zero,0x1
/*  f05fc98:	15c10003 */ 	bne	$t6,$at,.NB0f05fca8
/*  f05fc9c:	34038061 */ 	dli	$v1,0x8061
/*  f05fca0:	10000001 */ 	beqz	$zero,.NB0f05fca8
/*  f05fca4:	34038060 */ 	dli	$v1,0x8060
.NB0f05fca8:
/*  f05fca8:	0c004d84 */ 	jal	random
/*  f05fcac:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f05fcb0:	44822000 */ 	mtc1	$v0,$f4
/*  f05fcb4:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f05fcb8:	04410005 */ 	bgez	$v0,.NB0f05fcd0
/*  f05fcbc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f05fcc0:	3c014f80 */ 	lui	$at,0x4f80
/*  f05fcc4:	44814000 */ 	mtc1	$at,$f8
/*  f05fcc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05fccc:	46083180 */ 	add.s	$f6,$f6,$f8
.NB0f05fcd0:
/*  f05fcd0:	3c012f80 */ 	lui	$at,0x2f80
/*  f05fcd4:	44815000 */ 	mtc1	$at,$f10
/*  f05fcd8:	3c017f1a */ 	lui	$at,0x7f1a
/*  f05fcdc:	c4324168 */ 	lwc1	$f18,0x4168($at)
/*  f05fce0:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f05fce4:	3c017f1a */ 	lui	$at,0x7f1a
/*  f05fce8:	c428416c */ 	lwc1	$f8,0x416c($at)
/*  f05fcec:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f05fcf0:	10000015 */ 	beqz	$zero,.NB0f05fd48
/*  f05fcf4:	46044081 */ 	sub.s	$f2,$f8,$f4
.NB0f05fcf8:
/*  f05fcf8:	24030069 */ 	addiu	$v1,$zero,0x69
/*  f05fcfc:	0c004d84 */ 	jal	random
/*  f05fd00:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f05fd04:	44823000 */ 	mtc1	$v0,$f6
/*  f05fd08:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f05fd0c:	04410005 */ 	bgez	$v0,.NB0f05fd24
/*  f05fd10:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f05fd14:	3c014f80 */ 	lui	$at,0x4f80
/*  f05fd18:	44818000 */ 	mtc1	$at,$f16
/*  f05fd1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05fd20:	46105280 */ 	add.s	$f10,$f10,$f16
.NB0f05fd24:
/*  f05fd24:	3c012f80 */ 	lui	$at,0x2f80
/*  f05fd28:	44819000 */ 	mtc1	$at,$f18
/*  f05fd2c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f05fd30:	c4244170 */ 	lwc1	$f4,0x4170($at)
/*  f05fd34:	46125202 */ 	mul.s	$f8,$f10,$f18
/*  f05fd38:	3c013f80 */ 	lui	$at,0x3f80
/*  f05fd3c:	44818000 */ 	mtc1	$at,$f16
/*  f05fd40:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f05fd44:	46068081 */ 	sub.s	$f2,$f16,$f6
.NB0f05fd48:
/*  f05fd48:	2401ffff */ 	addiu	$at,$zero,-1
/*  f05fd4c:	10610035 */ 	beq	$v1,$at,.NB0f05fe24
/*  f05fd50:	e7a20048 */ 	swc1	$f2,0x48($sp)
/*  f05fd54:	3c18800a */ 	lui	$t8,0x800a
/*  f05fd58:	8f18e944 */ 	lw	$t8,-0x16bc($t8)
/*  f05fd5c:	8faf0054 */ 	lw	$t7,0x54($sp)
/*  f05fd60:	3c01bf80 */ 	lui	$at,0xbf80
/*  f05fd64:	8f1900bc */ 	lw	$t9,0xbc($t8)
/*  f05fd68:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f05fd6c:	00002025 */ 	or	$a0,$zero,$zero
/*  f05fd70:	15f90019 */ 	bne	$t7,$t9,.NB0f05fdd8
/*  f05fd74:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f05fd78:	3c01bf80 */ 	lui	$at,0xbf80
/*  f05fd7c:	44810000 */ 	mtc1	$at,$f0
/*  f05fd80:	00032c00 */ 	sll	$a1,$v1,0x10
/*  f05fd84:	00054403 */ 	sra	$t0,$a1,0x10
/*  f05fd88:	3c04800a */ 	lui	$a0,0x800a
/*  f05fd8c:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f05fd90:	240affff */ 	addiu	$t2,$zero,-1
/*  f05fd94:	240bffff */ 	addiu	$t3,$zero,-1
/*  f05fd98:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f05fd9c:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f05fda0:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f05fda4:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f05fda8:	01002825 */ 	or	$a1,$t0,$zero
/*  f05fdac:	00003025 */ 	or	$a2,$zero,$zero
/*  f05fdb0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f05fdb4:	0c004338 */ 	jal	sndStart
/*  f05fdb8:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f05fdbc:	10400019 */ 	beqz	$v0,.NB0f05fe24
/*  f05fdc0:	00402025 */ 	or	$a0,$v0,$zero
/*  f05fdc4:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f05fdc8:	0c00d492 */ 	jal	func00033e50
/*  f05fdcc:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f05fdd0:	10000015 */ 	beqz	$zero,.NB0f05fe28
/*  f05fdd4:	8fbf0044 */ 	lw	$ra,0x44($sp)
.NB0f05fdd8:
/*  f05fdd8:	44810000 */ 	mtc1	$at,$f0
/*  f05fddc:	00033400 */ 	sll	$a2,$v1,0x10
/*  f05fde0:	00066403 */ 	sra	$t4,$a2,0x10
/*  f05fde4:	240dffff */ 	addiu	$t5,$zero,-1
/*  f05fde8:	240effff */ 	addiu	$t6,$zero,-1
/*  f05fdec:	afae002c */ 	sw	$t6,0x2c($sp)
/*  f05fdf0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f05fdf4:	01803025 */ 	or	$a2,$t4,$zero
/*  f05fdf8:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f05fdfc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f05fe00:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f05fe04:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f05fe08:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f05fe0c:	e7a20024 */ 	swc1	$f2,0x24($sp)
/*  f05fe10:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f05fe14:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f05fe18:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f05fe1c:	0fc24762 */ 	jal	func0f0939f8
/*  f05fe20:	e7a00038 */ 	swc1	$f0,0x38($sp)
.NB0f05fe24:
/*  f05fe24:	8fbf0044 */ 	lw	$ra,0x44($sp)
.NB0f05fe28:
/*  f05fe28:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f05fe2c:	03e00008 */ 	jr	$ra
/*  f05fe30:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION >= VERSION_NTSC_1_0
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
/*  f060cd0:	3c048009 */ 	lui	$a0,%hi(g_AudioManager+0x18)
/*  f060cd4:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f060cd8:	0c012230 */ 	jal	osGetThreadPri
/*  f060cdc:	248415e0 */ 	addiu	$a0,$a0,%lo(g_AudioManager+0x18)
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
/*  f060d28:	0c004241 */ 	jal	sndStart
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
#else
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
/*  f05fe34:	3c013f80 */ 	lui	$at,0x3f80
/*  f05fe38:	44811000 */ 	mtc1	$at,$f2
/*  f05fe3c:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f05fe40:	24010001 */ 	addiu	$at,$zero,0x1
/*  f05fe44:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f05fe48:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f05fe4c:	1481001d */ 	bne	$a0,$at,.NB0f05fec4
/*  f05fe50:	e7a20048 */ 	swc1	$f2,0x48($sp)
/*  f05fe54:	3403808f */ 	dli	$v1,0x808f
/*  f05fe58:	0c004d84 */ 	jal	random
/*  f05fe5c:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f05fe60:	304e0001 */ 	andi	$t6,$v0,0x1
/*  f05fe64:	24010001 */ 	addiu	$at,$zero,0x1
/*  f05fe68:	15c10002 */ 	bne	$t6,$at,.NB0f05fe74
/*  f05fe6c:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f05fe70:	34038094 */ 	dli	$v1,0x8094
.NB0f05fe74:
/*  f05fe74:	0c004d84 */ 	jal	random
/*  f05fe78:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f05fe7c:	44822000 */ 	mtc1	$v0,$f4
/*  f05fe80:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f05fe84:	04410005 */ 	bgez	$v0,.NB0f05fe9c
/*  f05fe88:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f05fe8c:	3c014f80 */ 	lui	$at,0x4f80
/*  f05fe90:	44814000 */ 	mtc1	$at,$f8
/*  f05fe94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05fe98:	46083180 */ 	add.s	$f6,$f6,$f8
.NB0f05fe9c:
/*  f05fe9c:	3c012f80 */ 	lui	$at,0x2f80
/*  f05fea0:	44815000 */ 	mtc1	$at,$f10
/*  f05fea4:	3c017f1a */ 	lui	$at,0x7f1a
/*  f05fea8:	c4324174 */ 	lwc1	$f18,0x4174($at)
/*  f05feac:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f05feb0:	3c013f80 */ 	lui	$at,0x3f80
/*  f05feb4:	44814000 */ 	mtc1	$at,$f8
/*  f05feb8:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f05febc:	10000024 */ 	beqz	$zero,.NB0f05ff50
/*  f05fec0:	46044081 */ 	sub.s	$f2,$f8,$f4
.NB0f05fec4:
/*  f05fec4:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f05fec8:	14810004 */ 	bne	$a0,$at,.NB0f05fedc
/*  f05fecc:	240304fb */ 	addiu	$v1,$zero,0x4fb
/*  f05fed0:	3c017f1a */ 	lui	$at,0x7f1a
/*  f05fed4:	1000001e */ 	beqz	$zero,.NB0f05ff50
/*  f05fed8:	c4224178 */ 	lwc1	$f2,0x4178($at)
.NB0f05fedc:
/*  f05fedc:	2401001a */ 	addiu	$at,$zero,0x1a
/*  f05fee0:	10810008 */ 	beq	$a0,$at,.NB0f05ff04
/*  f05fee4:	34038079 */ 	dli	$v1,0x8079
/*  f05fee8:	0c004d84 */ 	jal	random
/*  f05feec:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f05fef0:	304f0001 */ 	andi	$t7,$v0,0x1
/*  f05fef4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f05fef8:	15e10002 */ 	bne	$t7,$at,.NB0f05ff04
/*  f05fefc:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f05ff00:	3403807c */ 	dli	$v1,0x807c
.NB0f05ff04:
/*  f05ff04:	0c004d84 */ 	jal	random
/*  f05ff08:	afa3004c */ 	sw	$v1,0x4c($sp)
/*  f05ff0c:	44823000 */ 	mtc1	$v0,$f6
/*  f05ff10:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f05ff14:	04410005 */ 	bgez	$v0,.NB0f05ff2c
/*  f05ff18:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f05ff1c:	3c014f80 */ 	lui	$at,0x4f80
/*  f05ff20:	44818000 */ 	mtc1	$at,$f16
/*  f05ff24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f05ff28:	46105280 */ 	add.s	$f10,$f10,$f16
.NB0f05ff2c:
/*  f05ff2c:	3c012f80 */ 	lui	$at,0x2f80
/*  f05ff30:	44819000 */ 	mtc1	$at,$f18
/*  f05ff34:	3c017f1a */ 	lui	$at,0x7f1a
/*  f05ff38:	c424417c */ 	lwc1	$f4,0x417c($at)
/*  f05ff3c:	46125202 */ 	mul.s	$f8,$f10,$f18
/*  f05ff40:	3c013f80 */ 	lui	$at,0x3f80
/*  f05ff44:	44818000 */ 	mtc1	$at,$f16
/*  f05ff48:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f05ff4c:	46068081 */ 	sub.s	$f2,$f16,$f6
.NB0f05ff50:
/*  f05ff50:	2401ffff */ 	addiu	$at,$zero,-1
/*  f05ff54:	10610035 */ 	beq	$v1,$at,.NB0f06002c
/*  f05ff58:	e7a20048 */ 	swc1	$f2,0x48($sp)
/*  f05ff5c:	3c19800a */ 	lui	$t9,0x800a
/*  f05ff60:	8f39e944 */ 	lw	$t9,-0x16bc($t9)
/*  f05ff64:	8fb80054 */ 	lw	$t8,0x54($sp)
/*  f05ff68:	3c01bf80 */ 	lui	$at,0xbf80
/*  f05ff6c:	8f2800bc */ 	lw	$t0,0xbc($t9)
/*  f05ff70:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f05ff74:	00002025 */ 	or	$a0,$zero,$zero
/*  f05ff78:	17080019 */ 	bne	$t8,$t0,.NB0f05ffe0
/*  f05ff7c:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f05ff80:	3c01bf80 */ 	lui	$at,0xbf80
/*  f05ff84:	44810000 */ 	mtc1	$at,$f0
/*  f05ff88:	00032c00 */ 	sll	$a1,$v1,0x10
/*  f05ff8c:	00054c03 */ 	sra	$t1,$a1,0x10
/*  f05ff90:	3c04800a */ 	lui	$a0,0x800a
/*  f05ff94:	240affff */ 	addiu	$t2,$zero,-1
/*  f05ff98:	240bffff */ 	addiu	$t3,$zero,-1
/*  f05ff9c:	240cffff */ 	addiu	$t4,$zero,-1
/*  f05ffa0:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f05ffa4:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f05ffa8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f05ffac:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f05ffb0:	01202825 */ 	or	$a1,$t1,$zero
/*  f05ffb4:	00003025 */ 	or	$a2,$zero,$zero
/*  f05ffb8:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f05ffbc:	0c004338 */ 	jal	sndStart
/*  f05ffc0:	e7a00014 */ 	swc1	$f0,0x14($sp)
/*  f05ffc4:	10400019 */ 	beqz	$v0,.NB0f06002c
/*  f05ffc8:	00402025 */ 	or	$a0,$v0,$zero
/*  f05ffcc:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f05ffd0:	0c00d492 */ 	jal	func00033e50
/*  f05ffd4:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f05ffd8:	10000015 */ 	beqz	$zero,.NB0f060030
/*  f05ffdc:	8fbf0044 */ 	lw	$ra,0x44($sp)
.NB0f05ffe0:
/*  f05ffe0:	44810000 */ 	mtc1	$at,$f0
/*  f05ffe4:	00033400 */ 	sll	$a2,$v1,0x10
/*  f05ffe8:	00066c03 */ 	sra	$t5,$a2,0x10
/*  f05ffec:	240effff */ 	addiu	$t6,$zero,-1
/*  f05fff0:	240fffff */ 	addiu	$t7,$zero,-1
/*  f05fff4:	afaf002c */ 	sw	$t7,0x2c($sp)
/*  f05fff8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f05fffc:	01a03025 */ 	or	$a2,$t5,$zero
/*  f060000:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f060004:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f060008:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f06000c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f060010:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f060014:	e7a20024 */ 	swc1	$f2,0x24($sp)
/*  f060018:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f06001c:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f060020:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f060024:	0fc24762 */ 	jal	func0f0939f8
/*  f060028:	e7a00038 */ 	swc1	$f0,0x38($sp)
.NB0f06002c:
/*  f06002c:	8fbf0044 */ 	lw	$ra,0x44($sp)
.NB0f060030:
/*  f060030:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f060034:	03e00008 */ 	jr	$ra
/*  f060038:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

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
/*  f060e8c:	0fc2c6bc */ 	jal	handPopulateFromCurrentPlayer
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
/*  f0610e4:	0fc5914d */ 	jal	roomsGetActive
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
/*  f061758:	0fc2a519 */ 	jal	handSetHitPos
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
/*  f061b4c:	0fc2a519 */ 	jal	handSetHitPos
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
/*  f061c6c:	0fc18261 */ 	jal	weaponPlayWhooshSound
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
/*  f061d74:	0fc2832c */ 	jal	handCalculateShotSpread
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

void handCreateBulletRaycast(s32 handnum, bool arg1, bool dorandom, s32 arg3, bool arg4)
{
	struct coord shootdir;
	struct coord shootpos;
	struct coord sp44;
	struct coord sp38;

	handCalculateShotSpread(&sp38, &sp44, handnum, dorandom);

	if (arg3 > 0) {
		func00015b68(currentPlayerGetUnk174c(), &sp38, &shootpos);
		func00015b14(currentPlayerGetUnk174c(), &sp44, &shootdir);

		func0f060db8(handnum, arg1, &sp38, &sp44, &shootpos, &shootdir, 0, 4294836224, arg4);

		if (arg3 < 2) {
			handSetLastShootInfo(&shootpos, &shootdir, handnum);
		}
	}
}

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

void handInflictCloseRangeDamage(s32 handnum, struct shorthand *hand, bool arg2)
{
	s32 someval;
	struct prop **ptr;
	struct prop *playerprop;
	bool skipthething;

	playerprop = g_Vars.currentplayer->prop;
	ptr = g_Vars.unk00034c - 1;
	skipthething = false;

	// Iterate tangible list in reverse
	while (ptr >= g_Vars.tangibleprops) {
		struct prop *prop = *ptr;

		if (prop && prop->z < 500) {
			/**
			 * @bug: There is no check to make sure the prop's type is obj
			 * before accessing the obj properties. prop->obj is a void *
			 * pointer or union of pointers so it may point to a non-obj struct.
			 * This means it's checking if the byte at offset 3 in whichever
			 * struct it's pointing to has the value 0x2a (glass) or 0x2f
			 * (tinted glass).
			 *
			 * If the prop being iterated is a chr, this offset corresponds to
			 * the speedrating property in the chrdata struct. So inflicting
			 * close range damage on a chr with a speedrating of 42 (0x2a) or
			 * 47 (0x2f) will cause a crash. No chrs have these speedrating
			 * values though, and the reaction speed setting in PD mode was
			 * removed... maybe because of this bug?
			 *
			 * If the prop being iterated is an explosion or smoke, the offset
			 * corresponds to the last byte of a pointer to a struct. Because
			 * structs are 4-byte aligned, its value will never be 0x2a or 0x2f.
			 * If glass or tinted glass were assigned values that were multiples
			 * of 4 then the game could crash when you punch explosions or
			 * smoke.
			 *
			 * The other prop types use pointers that also point to chr structs,
			 * or to other objs which extend defaultobj, so the bug is not
			 * present for those.
			 */
			struct defaultobj *obj = prop->obj;
			bool isbreakableobj = false;

			if (obj && hand->weaponnum != WEAPON_TRANQUILIZER) {
				isbreakableobj = obj->type == OBJTYPE_GLASS || obj->type == OBJTYPE_TINTEDGLASS;
			}

			if (arg2) {
				isbreakableobj = false;
			}

			if (prop->type == PROPTYPE_CHR
					|| (prop->type == PROPTYPE_PLAYER && prop->chr && propGetPlayerNum(prop) != g_Vars.currentplayernum)
					|| isbreakableobj) {
				f32 rangelimit = 60;
				f32 distance;
				f32 sp110;
				struct chrdata *chr = prop->chr;
				f32 x;
				f32 y;
				f32 spfc[2];
				f32 spf4[2];
				struct model *model;
				struct weaponfunc *func = handGetWeaponFunction(hand);

				if ((func->type & 0xff) == 3) {
					struct weaponfunc_close *closefunc = (struct weaponfunc_close *)func;
					rangelimit = closefunc->range;
				}

				currentPlayerGetCrossPos(&x, &y);

				spfc[0] = (x - currentPlayerGetScreenLeft()) / (currentPlayerGetScreenWidth() * 0.5f) - 1.0f;
				spfc[1] = (y - currentPlayerGetScreenTop()) / (currentPlayerGetScreenHeight() * 0.5f) - 1.0f;
				spf4[0] = currentPlayerGetScreenHeight() * 0.16666667163372f;
				spf4[1] = currentPlayerGetScreenHeight() * 0.125f;

				if (isbreakableobj) {
					model = obj->model;
				} else {
					model = chr->model;
				}

				if (func0f0679ac(model, &distance, &sp110, spfc, spf4)
						&& sp110 <= 0
						&& distance >= -rangelimit) {
					someval = 0x33;

					if (isbreakableobj) {
						someval = 0;
					}

					if (func0002dc18(&playerprop->pos, playerprop->rooms, &prop->pos, someval)) {
						if (isbreakableobj) {
							struct model *model = obj->model;
							struct coord spd8;
							struct coord spcc;
							struct modelnode *node = NULL;

							handCalculateShotSpread(&spd8, &spcc, handnum, true);

							if (func000225d4(model, &spd8, &spcc, &node) > 0) {
								f32 damage = handGetDamage(hand) * 2.5f;
								skipthething = true;
								func0f0a8404(&playerprop->pos, playerprop->rooms, -1);
								func0f085270(obj, damage, &prop->pos, hand->weaponnum, g_Vars.currentplayernum);
								func0f070698(prop, false);
							}
						} else if (arg2) {
							chr->chrflags |= CHRCFLAG_10000000;
						} else {
							struct coord spb8;
							struct coord vector;
							struct modelnode *node = NULL;
							struct model *model = NULL;
							s32 side = -1;
							s32 ibh = IBH_TORSO;

							if (!chrIsAvoiding(chr)) {
								handCalculateShotSpread(&spb8, &vector, handnum, true);
								skipthething = true;
								func00015b10(currentPlayerGetUnk174c(), &vector);
								handPlayPropHitSound(hand, prop, -1);

								if (chr->model && chrGetShield(chr) > 0) {
									chrCalculateShieldHit(chr, &playerprop->pos, &vector, &node, &ibh, &model, &side);
								}

								if (bmoveGetCrouchPos() == CROUCHPOS_DUCK) {
									ibh = IBH_GENERAL;
								} else if (bmoveGetCrouchPos() == CROUCHPOS_SQUAT) {
									ibh = IBH_GENERALHALF;
								} else {
									ibh = IBH_TORSO;
								}

								func0f0341dc(chr, handGetDamage(hand), &vector, hand,
										g_Vars.currentplayer->prop, ibh, chr->prop, node, model, side, 0);
							}
						}
					}
				}
			}
		}

		ptr--;
	}

	if (!skipthething && !arg2) {
		g_Vars.currentplayer->hands[handnum].unk0d0f_02 = true;
	}
}

void handTickAttack(s32 handnum)
{
	if (g_Vars.currentplayer->hands[handnum].unk0d0f_02) {
		s32 doit = true;

		if (handGetWeaponNum(handnum) == WEAPON_REAPER
				&& (g_Vars.currentplayer->hands[handnum].burstbullets % 3) != 1) {
			doit = false;
		}

		if (doit) {
			func0f061d54(handnum, 1, 2);
		}

		g_Vars.currentplayer->hands[handnum].unk0d0f_02 = false;
	}

	if (handIsFiring(handnum)) {
		s32 type = handGetAttackType(handnum);
		s32 weaponnum = handGetWeaponNum(handnum);
		u8 stack1;
		u8 stack2;
		u8 stack3;
		u8 tmpweaponnum;
		bool cloaked;

		g_Vars.currentplayer->hands[handnum].unk0d0f_03 = false;

		handPopulateFromCurrentPlayer(handnum, (struct shorthand *)&tmpweaponnum);
		frIncrementNumShots();

		switch (type) {
		case HANDATTACKTYPE_SHOOT:
			// Always execute if right hand, but if left hand then execute if
			// right hand is not (ie. prevent firing both guns on the same tick)
			if (handnum == HAND_RIGHT || !handIsFiring(HAND_RIGHT)) {
				chrUncloakTemporarily(g_Vars.currentplayer->prop->chr);
				mpstatsIncrementPlayerShotCount2((struct shorthand *)&tmpweaponnum, 0);

				if (weaponnum == WEAPON_SHOTGUN) {
					handCreateBulletRaycast(handnum, true, true, 1, true);
					handCreateBulletRaycast(handnum, true, true, 1, true);
					handCreateBulletRaycast(handnum, true, true, 1, true);
					handCreateBulletRaycast(handnum, true, true, 1, true);
					handCreateBulletRaycast(handnum, true, true, 1, true);
					handCreateBulletRaycast(handnum, true, true, 1, true);
				} else {
					handCreateBulletRaycast(handnum, true, true, handGetUnk0c30(handnum), g_Vars.mplayerisrunning);
				}

				mpstats0f0b0520();
			}
			break;
		case HANDATTACKTYPE_CLOSERANGE:
			chrUncloakTemporarily(g_Vars.currentplayer->prop->chr);
			handInflictCloseRangeDamage(handnum, (struct shorthand *)&tmpweaponnum, false);
			break;
		case HANDATTACKTYPE_CLOSERANGENOUNCLOAK:
			handInflictCloseRangeDamage(handnum, (struct shorthand *)&tmpweaponnum, true);
			break;
		case HANDATTACKTYPE_DETONATE:
			playerActivateRemoteMineDetonator(g_Vars.currentplayernum);
			break;
		case HANDATTACKTYPE_UPLINK:
			func0f062dd0();
			break;
		case HANDATTACKTYPE_BOOST:
			cboostBoost();
			break;
		case HANDATTACKTYPE_REVERTBOOST:
			cboostRevert();
			break;
		case HANDATTACKTYPE_SHOOTPROJECTILE:
			handCreateFiredProjectile(handnum);
			break;
		case HANDATTACKTYPE_CROUCH:
			if (g_Vars.currentplayer->crouchpos == CROUCHPOS_SQUAT) {
				bwalkAdjustCrouchPos(2);
			} else {
				bwalkAdjustCrouchPos(-2);
			}
			break;
		case HANDATTACKTYPE_THROWPROJECTILE:
			handCreateThrownProjectile(handnum, (struct shorthand *)&tmpweaponnum);
			break;
		case HANDATTACKTYPE_RCP120CLOAK:
			cloaked = (g_Vars.currentplayer->devicesactive & DEVICE_CLOAKRCP120) != 0;

			if (cloaked) {
				g_Vars.currentplayer->devicesactive &= ~DEVICE_CLOAKRCP120;
			} else {
				g_Vars.currentplayer->devicesactive =
					(g_Vars.currentplayer->devicesactive & ~DEVICE_CLOAKDEVICE)
					| DEVICE_CLOAKRCP120;
			}
			break;
		}
	}
}

void handsTickAttack(void)
{
	if (g_Vars.lvupdate240 > 0) {
		handTickAttack(HAND_RIGHT);
		handTickAttack(HAND_LEFT);
	}
}

void func0f062b64(struct prop *prop, s32 arg1)
{
	if (arg1 == 1) {
		if ((prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_OBJ)
				&& prop->obj && (prop->obj->hidden2 & OBJH2FLAG_04)) {
			struct defaultobj *obj = prop->obj;

			prop->timetoregen = PALDOWN(1200);

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

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f06302c
.late_rodata
glabel var7f1ab184pf
.word 0x3f99999a
glabel var7f1ab188pf
.word 0x3f99999a
glabel var7f1ab18cpf
.word 0x3f99999a
glabel var7f1ab190pf
.word 0x3f99999a
.text
/*  f06328c:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f063290:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f063294:	3c11800a */ 	lui	$s1,0x800a
/*  f063298:	2631a510 */ 	addiu	$s1,$s1,-23280
/*  f06329c:	ae20043c */ 	sw	$zero,0x43c($s1)
/*  f0632a0:	3c01800a */ 	lui	$at,0x800a
/*  f0632a4:	ac20d30c */ 	sw	$zero,-0x2cf4($at)
/*  f0632a8:	3c01800a */ 	lui	$at,0x800a
/*  f0632ac:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0632b0:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0632b4:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0632b8:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0632bc:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0632c0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0632c4:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f0632c8:	10800009 */ 	beqz	$a0,.PF0f0632f0
/*  f0632cc:	ac20d310 */ 	sw	$zero,-0x2cf0($at)
/*  f0632d0:	9622035c */ 	lhu	$v0,0x35c($s1)
/*  f0632d4:	2401ffff */ 	li	$at,-1
/*  f0632d8:	244f0001 */ 	addiu	$t7,$v0,0x1
/*  f0632dc:	31f8ffff */ 	andi	$t8,$t7,0xffff
/*  f0632e0:	a62f035c */ 	sh	$t7,0x35c($s1)
/*  f0632e4:	17010002 */ 	bne	$t8,$at,.PF0f0632f0
/*  f0632e8:	a622035e */ 	sh	$v0,0x35e($s1)
/*  f0632ec:	a620035c */ 	sh	$zero,0x35c($s1)
.PF0f0632f0:
/*  f0632f0:	92270358 */ 	lbu	$a3,0x358($s1)
/*  f0632f4:	8e390034 */ 	lw	$t9,0x34($s1)
/*  f0632f8:	8e2d0038 */ 	lw	$t5,0x38($s1)
/*  f0632fc:	c6240044 */ 	lwc1	$f4,0x44($s1)
/*  f063300:	c626004c */ 	lwc1	$f6,0x4c($s1)
/*  f063304:	00002825 */ 	move	$a1,$zero
/*  f063308:	afb9008c */ 	sw	$t9,0x8c($sp)
/*  f06330c:	afad0088 */ 	sw	$t5,0x88($sp)
/*  f063310:	e7a40084 */ 	swc1	$f4,0x84($sp)
/*  f063314:	18e0000e */ 	blez	$a3,.PF0f063350
/*  f063318:	e7a60080 */ 	swc1	$f6,0x80($sp)
/*  f06331c:	3c02800a */ 	lui	$v0,0x800a
/*  f063320:	2442a510 */ 	addiu	$v0,$v0,-23280
/*  f063324:	8c4e0370 */ 	lw	$t6,0x370($v0)
.PF0f063328:
/*  f063328:	8e2f0034 */ 	lw	$t7,0x34($s1)
/*  f06332c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f063330:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f063334:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f063338:	ac580354 */ 	sw	$t8,0x354($v0)
/*  f06333c:	92270358 */ 	lbu	$a3,0x358($s1)
/*  f063340:	00a7082a */ 	slt	$at,$a1,$a3
/*  f063344:	5420fff8 */ 	bnezl	$at,.PF0f063328
/*  f063348:	8c4e0370 */ 	lw	$t6,0x370($v0)
/*  f06334c:	00002825 */ 	move	$a1,$zero
.PF0f063350:
/*  f063350:	9239035a */ 	lbu	$t9,0x35a($s1)
/*  f063354:	24150001 */ 	li	$s5,0x1
/*  f063358:	24140003 */ 	li	$s4,0x3
/*  f06335c:	272d0001 */ 	addiu	$t5,$t9,0x1
/*  f063360:	31a300ff */ 	andi	$v1,$t5,0xff
/*  f063364:	0067082a */ 	slt	$at,$v1,$a3
/*  f063368:	14200003 */ 	bnez	$at,.PF0f063378
/*  f06336c:	a22d035a */ 	sb	$t5,0x35a($s1)
/*  f063370:	a220035a */ 	sb	$zero,0x35a($s1)
/*  f063374:	300300ff */ 	andi	$v1,$zero,0xff
.PF0f063378:
/*  f063378:	306900ff */ 	andi	$t1,$v1,0xff
/*  f06337c:	000970c0 */ 	sll	$t6,$t1,0x3
/*  f063380:	01c97023 */ 	subu	$t6,$t6,$t1
/*  f063384:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f063388:	022e5021 */ 	addu	$t2,$s1,$t6
/*  f06338c:	8d420370 */ 	lw	$v0,0x370($t2)
/*  f063390:	3c013e80 */ 	lui	$at,0x3e80
/*  f063394:	8d4f0374 */ 	lw	$t7,0x374($t2)
/*  f063398:	44824000 */ 	mtc1	$v0,$f8
/*  f06339c:	44818000 */ 	mtc1	$at,$f16
/*  f0633a0:	01e24021 */ 	addu	$t0,$t7,$v0
/*  f0633a4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0633a8:	31180003 */ 	andi	$t8,$t0,0x3
/*  f0633ac:	ad580374 */ 	sw	$t8,0x374($t2)
/*  f0633b0:	922d0358 */ 	lbu	$t5,0x358($s1)
/*  f0633b4:	24480002 */ 	addiu	$t0,$v0,0x2
/*  f0633b8:	0008c883 */ 	sra	$t9,$t0,0x2
/*  f0633bc:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0633c0:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f0633c4:	03204025 */ 	move	$t0,$t9
/*  f0633c8:	3c02800a */ 	lui	$v0,0x800a
/*  f0633cc:	2413008c */ 	li	$s3,0x8c
/*  f0633d0:	2412ffff */ 	li	$s2,-1
/*  f0633d4:	19a0000c */ 	blez	$t5,.PF0f063408
/*  f0633d8:	e7b20074 */ 	swc1	$f18,0x74($sp)
/*  f0633dc:	2442a510 */ 	addiu	$v0,$v0,-23280
/*  f0633e0:	a4400360 */ 	sh	$zero,0x360($v0)
.PF0f0633e4:
/*  f0633e4:	a4400362 */ 	sh	$zero,0x362($v0)
/*  f0633e8:	a4400364 */ 	sh	$zero,0x364($v0)
/*  f0633ec:	a4400366 */ 	sh	$zero,0x366($v0)
/*  f0633f0:	922e0358 */ 	lbu	$t6,0x358($s1)
/*  f0633f4:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0633f8:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f0633fc:	00ae082a */ 	slt	$at,$a1,$t6
/*  f063400:	5420fff8 */ 	bnezl	$at,.PF0f0633e4
/*  f063404:	a4400360 */ 	sh	$zero,0x360($v0)
.PF0f063408:
/*  f063408:	8e2f0290 */ 	lw	$t7,0x290($s1)
/*  f06340c:	55e00024 */ 	bnezl	$t7,.PF0f0634a0
/*  f063410:	8e380334 */ 	lw	$t8,0x334($s1)
/*  f063414:	8e380334 */ 	lw	$t8,0x334($s1)
/*  f063418:	8e300338 */ 	lw	$s0,0x338($s1)
/*  f06341c:	2407ff7f */ 	li	$a3,-129
/*  f063420:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f063424:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f063428:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f06342c:	03302821 */ 	addu	$a1,$t9,$s0
/*  f063430:	0205082b */ 	sltu	$at,$s0,$a1
/*  f063434:	1020002e */ 	beqz	$at,.PF0f0634f0
/*  f063438:	2406ffbf */ 	li	$a2,-65
/*  f06343c:	2404fffd */ 	li	$a0,-3
.PF0f063440:
/*  f063440:	92020001 */ 	lbu	$v0,0x1($s0)
/*  f063444:	304d0002 */ 	andi	$t5,$v0,0x2
/*  f063448:	11a00003 */ 	beqz	$t5,.PF0f063458
/*  f06344c:	00401825 */ 	move	$v1,$v0
/*  f063450:	00441024 */ 	and	$v0,$v0,$a0
/*  f063454:	304300ff */ 	andi	$v1,$v0,0xff
.PF0f063458:
/*  f063458:	306f0040 */ 	andi	$t7,$v1,0x40
/*  f06345c:	11e00005 */ 	beqz	$t7,.PF0f063474
/*  f063460:	306d0080 */ 	andi	$t5,$v1,0x80
/*  f063464:	34780080 */ 	ori	$t8,$v1,0x80
/*  f063468:	03061024 */ 	and	$v0,$t8,$a2
/*  f06346c:	10000004 */ 	b	.PF0f063480
/*  f063470:	304300ff */ 	andi	$v1,$v0,0xff
.PF0f063474:
/*  f063474:	11a00002 */ 	beqz	$t5,.PF0f063480
/*  f063478:	00671024 */ 	and	$v0,$v1,$a3
/*  f06347c:	304300ff */ 	andi	$v1,$v0,0xff
.PF0f063480:
/*  f063480:	26100048 */ 	addiu	$s0,$s0,0x48
/*  f063484:	0205082b */ 	sltu	$at,$s0,$a1
/*  f063488:	346f0008 */ 	ori	$t7,$v1,0x8
/*  f06348c:	1420ffec */ 	bnez	$at,.PF0f063440
/*  f063490:	a20fffb9 */ 	sb	$t7,-0x47($s0)
/*  f063494:	10000017 */ 	b	.PF0f0634f4
/*  f063498:	afaa0034 */ 	sw	$t2,0x34($sp)
/*  f06349c:	8e380334 */ 	lw	$t8,0x334($s1)
.PF0f0634a0:
/*  f0634a0:	8e300338 */ 	lw	$s0,0x338($s1)
/*  f0634a4:	2404fffd */ 	li	$a0,-3
/*  f0634a8:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0634ac:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0634b0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0634b4:	03302821 */ 	addu	$a1,$t9,$s0
/*  f0634b8:	0205082b */ 	sltu	$at,$s0,$a1
/*  f0634bc:	5020000d */ 	beqzl	$at,.PF0f0634f4
/*  f0634c0:	afaa0034 */ 	sw	$t2,0x34($sp)
.PF0f0634c4:
/*  f0634c4:	92020001 */ 	lbu	$v0,0x1($s0)
/*  f0634c8:	304d0002 */ 	andi	$t5,$v0,0x2
/*  f0634cc:	11a00004 */ 	beqz	$t5,.PF0f0634e0
/*  f0634d0:	00401825 */ 	move	$v1,$v0
/*  f0634d4:	00641024 */ 	and	$v0,$v1,$a0
/*  f0634d8:	304e00ff */ 	andi	$t6,$v0,0xff
/*  f0634dc:	01c01025 */ 	move	$v0,$t6
.PF0f0634e0:
/*  f0634e0:	26100048 */ 	addiu	$s0,$s0,0x48
/*  f0634e4:	0205082b */ 	sltu	$at,$s0,$a1
/*  f0634e8:	1420fff6 */ 	bnez	$at,.PF0f0634c4
/*  f0634ec:	a202ffb9 */ 	sb	$v0,-0x47($s0)
.PF0f0634f0:
/*  f0634f0:	afaa0034 */ 	sw	$t2,0x34($sp)
.PF0f0634f4:
/*  f0634f4:	afaa0034 */ 	sw	$t2,0x34($sp)
/*  f0634f8:	8e30033c */ 	lw	$s0,0x33c($s1)
/*  f0634fc:	afa80078 */ 	sw	$t0,0x78($sp)
/*  f063500:	a3a90069 */ 	sb	$t1,0x69($sp)
/*  f063504:	8e0f0020 */ 	lw	$t7,0x20($s0)
.PF0f063508:
/*  f063508:	8e390354 */ 	lw	$t9,0x354($s1)
/*  f06350c:	8e2e02ac */ 	lw	$t6,0x2ac($s1)
/*  f063510:	00003025 */ 	move	$a2,$zero
/*  f063514:	01f96826 */ 	xor	$t5,$t7,$t9
/*  f063518:	2dad0001 */ 	sltiu	$t5,$t5,0x1
/*  f06351c:	afad004c */ 	sw	$t5,0x4c($sp)
/*  f063520:	12ae0003 */ 	beq	$s5,$t6,.PF0f063530
/*  f063524:	afaf005c */ 	sw	$t7,0x5c($sp)
/*  f063528:	10000002 */ 	b	.PF0f063534
/*  f06352c:	02a02825 */ 	move	$a1,$s5
.PF0f063530:
/*  f063530:	9225035b */ 	lbu	$a1,0x35b($s1)
.PF0f063534:
/*  f063534:	86080028 */ 	lh	$t0,0x28($s0)
/*  f063538:	26070028 */ 	addiu	$a3,$s0,0x28
/*  f06353c:	00e01825 */ 	move	$v1,$a3
/*  f063540:	1248000f */ 	beq	$s2,$t0,.PF0f063580
/*  f063544:	3c04800a */ 	lui	$a0,0x800a
/*  f063548:	8c844ec8 */ 	lw	$a0,0x4ec8($a0)
/*  f06354c:	84620000 */ 	lh	$v0,0x0($v1)
.PF0f063550:
/*  f063550:	00530019 */ 	multu	$v0,$s3
/*  f063554:	00007812 */ 	mflo	$t7
/*  f063558:	008fc021 */ 	addu	$t8,$a0,$t7
/*  f06355c:	97190000 */ 	lhu	$t9,0x0($t8)
/*  f063560:	332d0004 */ 	andi	$t5,$t9,0x4
/*  f063564:	51a00003 */ 	beqzl	$t5,.PF0f063574
/*  f063568:	84620002 */ 	lh	$v0,0x2($v1)
/*  f06356c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f063570:	84620002 */ 	lh	$v0,0x2($v1)
.PF0f063574:
/*  f063574:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f063578:	1642fff5 */ 	bne	$s2,$v0,.PF0f063550
/*  f06357c:	00000000 */ 	nop
.PF0f063580:
/*  f063580:	54a0003c */ 	bnezl	$a1,.PF0f063674
/*  f063584:	960d003a */ 	lhu	$t5,0x3a($s0)
/*  f063588:	92030000 */ 	lbu	$v1,0x0($s0)
/*  f06358c:	24010006 */ 	li	$at,0x6
/*  f063590:	14610003 */ 	bne	$v1,$at,.PF0f0635a0
/*  f063594:	00000000 */ 	nop
/*  f063598:	1000000b */ 	b	.PF0f0635c8
/*  f06359c:	24a50001 */ 	addiu	$a1,$a1,0x1
.PF0f0635a0:
/*  f0635a0:	12a30003 */ 	beq	$s5,$v1,.PF0f0635b0
/*  f0635a4:	24010004 */ 	li	$at,0x4
/*  f0635a8:	14610007 */ 	bne	$v1,$at,.PF0f0635c8
/*  f0635ac:	00000000 */ 	nop
.PF0f0635b0:
/*  f0635b0:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f0635b4:	8c4e0040 */ 	lw	$t6,0x40($v0)
/*  f0635b8:	31cf0080 */ 	andi	$t7,$t6,0x80
/*  f0635bc:	11e00002 */ 	beqz	$t7,.PF0f0635c8
/*  f0635c0:	00000000 */ 	nop
/*  f0635c4:	24a50001 */ 	addiu	$a1,$a1,0x1
.PF0f0635c8:
/*  f0635c8:	54a0002a */ 	bnezl	$a1,.PF0f063674
/*  f0635cc:	960d003a */ 	lhu	$t5,0x3a($s0)
/*  f0635d0:	92180001 */ 	lbu	$t8,0x1($s0)
/*  f0635d4:	24010084 */ 	li	$at,0x84
/*  f0635d8:	33190084 */ 	andi	$t9,$t8,0x84
/*  f0635dc:	57210004 */ 	bnel	$t9,$at,.PF0f0635f0
/*  f0635e0:	9202003f */ 	lbu	$v0,0x3f($s0)
/*  f0635e4:	10000022 */ 	b	.PF0f063670
/*  f0635e8:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0635ec:	9202003f */ 	lbu	$v0,0x3f($s0)
.PF0f0635f0:
/*  f0635f0:	000269c2 */ 	srl	$t5,$v0,0x7
/*  f0635f4:	11a00004 */ 	beqz	$t5,.PF0f063608
/*  f0635f8:	304eff7f */ 	andi	$t6,$v0,0xff7f
/*  f0635fc:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f063600:	1000001b */ 	b	.PF0f063670
/*  f063604:	a20e003f */ 	sb	$t6,0x3f($s0)
.PF0f063608:
/*  f063608:	8e0f003c */ 	lw	$t7,0x3c($s0)
/*  f06360c:	000fce80 */ 	sll	$t9,$t7,0x1a
/*  f063610:	07210003 */ 	bgez	$t9,.PF0f063620
/*  f063614:	00000000 */ 	nop
/*  f063618:	10000015 */ 	b	.PF0f063670
/*  f06361c:	24a50001 */ 	addiu	$a1,$a1,0x1
.PF0f063620:
/*  f063620:	1248000f */ 	beq	$s2,$t0,.PF0f063660
/*  f063624:	00e01825 */ 	move	$v1,$a3
/*  f063628:	3c04800a */ 	lui	$a0,0x800a
/*  f06362c:	8c844ec8 */ 	lw	$a0,0x4ec8($a0)
/*  f063630:	84e20000 */ 	lh	$v0,0x0($a3)
.PF0f063634:
/*  f063634:	00530019 */ 	multu	$v0,$s3
/*  f063638:	00006812 */ 	mflo	$t5
/*  f06363c:	008d7021 */ 	addu	$t6,$a0,$t5
/*  f063640:	95cf0000 */ 	lhu	$t7,0x0($t6)
/*  f063644:	31f80008 */ 	andi	$t8,$t7,0x8
/*  f063648:	57000006 */ 	bnezl	$t8,.PF0f063664
/*  f06364c:	84790000 */ 	lh	$t9,0x0($v1)
/*  f063650:	84620002 */ 	lh	$v0,0x2($v1)
/*  f063654:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f063658:	1642fff6 */ 	bne	$s2,$v0,.PF0f063634
/*  f06365c:	00000000 */ 	nop
.PF0f063660:
/*  f063660:	84790000 */ 	lh	$t9,0x0($v1)
.PF0f063664:
/*  f063664:	52590003 */ 	beql	$s2,$t9,.PF0f063674
/*  f063668:	960d003a */ 	lhu	$t5,0x3a($s0)
/*  f06366c:	24a50001 */ 	addiu	$a1,$a1,0x1
.PF0f063670:
/*  f063670:	960d003a */ 	lhu	$t5,0x3a($s0)
.PF0f063674:
/*  f063674:	8e2e0034 */ 	lw	$t6,0x34($s1)
/*  f063678:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f06367c:	18a00080 */ 	blez	$a1,.PF0f063880
/*  f063680:	a60f003a */ 	sh	$t7,0x3a($s0)
/*  f063684:	9638035e */ 	lhu	$t8,0x35e($s1)
/*  f063688:	96190038 */ 	lhu	$t9,0x38($s0)
/*  f06368c:	31edffff */ 	andi	$t5,$t7,0xffff
/*  f063690:	53190019 */ 	beql	$t8,$t9,.PF0f0636f8
/*  f063694:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f063698:	ae2d0034 */ 	sw	$t5,0x34($s1)
/*  f06369c:	920f003c */ 	lbu	$t7,0x3c($s0)
/*  f0636a0:	960e003a */ 	lhu	$t6,0x3a($s0)
/*  f0636a4:	3c013e80 */ 	lui	$at,0x3e80
/*  f0636a8:	44814000 */ 	mtc1	$at,$f8
/*  f0636ac:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0636b0:	ae380038 */ 	sw	$t8,0x38($s1)
/*  f0636b4:	330d0003 */ 	andi	$t5,$t8,0x3
/*  f0636b8:	a20d003c */ 	sb	$t5,0x3c($s0)
/*  f0636bc:	8e380034 */ 	lw	$t8,0x34($s1)
/*  f0636c0:	8e2e0038 */ 	lw	$t6,0x38($s1)
/*  f0636c4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0636c8:	44982000 */ 	mtc1	$t8,$f4
/*  f0636cc:	000e7883 */ 	sra	$t7,$t6,0x2
/*  f0636d0:	ae2f0038 */ 	sw	$t7,0x38($s1)
/*  f0636d4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0636d8:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0636dc:	e62a0044 */ 	swc1	$f10,0x44($s1)
/*  f0636e0:	c432b188 */ 	lwc1	$f18,-0x4e78($at)
/*  f0636e4:	c6300044 */ 	lwc1	$f16,0x44($s1)
/*  f0636e8:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0636ec:	10000009 */ 	b	.PF0f063714
/*  f0636f0:	e624004c */ 	swc1	$f4,0x4c($s1)
/*  f0636f4:	8fb9008c */ 	lw	$t9,0x8c($sp)
.PF0f0636f8:
/*  f0636f8:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f0636fc:	c7a60084 */ 	lwc1	$f6,0x84($sp)
/*  f063700:	c7a80080 */ 	lwc1	$f8,0x80($sp)
/*  f063704:	ae390034 */ 	sw	$t9,0x34($s1)
/*  f063708:	ae2d0038 */ 	sw	$t5,0x38($s1)
/*  f06370c:	e6260044 */ 	swc1	$f6,0x44($s1)
/*  f063710:	e628004c */ 	swc1	$f8,0x4c($s1)
.PF0f063714:
/*  f063714:	920e0000 */ 	lbu	$t6,0x0($s0)
/*  f063718:	a200003e */ 	sb	$zero,0x3e($s0)
/*  f06371c:	568e001c */ 	bnel	$s4,$t6,.PF0f063790
/*  f063720:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f063724:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f063728:	02002025 */ 	move	$a0,$s0
/*  f06372c:	0fc5260c */ 	jal	splatTick
/*  f063730:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f063734:	8fa20048 */ 	lw	$v0,0x48($sp)
/*  f063738:	10400008 */ 	beqz	$v0,.PF0f06375c
/*  f06373c:	00000000 */ 	nop
/*  f063740:	8c4f02d4 */ 	lw	$t7,0x2d4($v0)
/*  f063744:	11e00005 */ 	beqz	$t7,.PF0f06375c
/*  f063748:	00000000 */ 	nop
/*  f06374c:	0fc64a62 */ 	jal	aibotTick
/*  f063750:	02002025 */ 	move	$a0,$s0
/*  f063754:	10000004 */ 	b	.PF0f063768
/*  f063758:	00403025 */ 	move	$a2,$v0
.PF0f06375c:
/*  f06375c:	0fc08c75 */ 	jal	func0f023098
/*  f063760:	02002025 */ 	move	$a0,$s0
/*  f063764:	00403025 */ 	move	$a2,$v0
.PF0f063768:
/*  f063768:	9218003d */ 	lbu	$t8,0x3d($s0)
/*  f06376c:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f063770:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f063774:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f063778:	02391021 */ 	addu	$v0,$s1,$t9
/*  f06377c:	944d0366 */ 	lhu	$t5,0x366($v0)
/*  f063780:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f063784:	1000002b */ 	b	.PF0f063834
/*  f063788:	a44e0366 */ 	sh	$t6,0x366($v0)
/*  f06378c:	920f003d */ 	lbu	$t7,0x3d($s0)
.PF0f063790:
/*  f063790:	24010004 */ 	li	$at,0x4
/*  f063794:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f063798:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f06379c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0637a0:	02381021 */ 	addu	$v0,$s1,$t8
/*  f0637a4:	94590364 */ 	lhu	$t9,0x364($v0)
/*  f0637a8:	272d0001 */ 	addiu	$t5,$t9,0x1
/*  f0637ac:	a44d0364 */ 	sh	$t5,0x364($v0)
/*  f0637b0:	92030000 */ 	lbu	$v1,0x0($s0)
/*  f0637b4:	12a30005 */ 	beq	$s5,$v1,.PF0f0637cc
/*  f0637b8:	00000000 */ 	nop
/*  f0637bc:	10610003 */ 	beq	$v1,$at,.PF0f0637cc
/*  f0637c0:	24010002 */ 	li	$at,0x2
/*  f0637c4:	54610006 */ 	bnel	$v1,$at,.PF0f0637e0
/*  f0637c8:	24010007 */ 	li	$at,0x7
.PF0f0637cc:
/*  f0637cc:	0fc1fa6a */ 	jal	objTick
/*  f0637d0:	02002025 */ 	move	$a0,$s0
/*  f0637d4:	10000017 */ 	b	.PF0f063834
/*  f0637d8:	00403025 */ 	move	$a2,$v0
/*  f0637dc:	24010007 */ 	li	$at,0x7
.PF0f0637e0:
/*  f0637e0:	54610006 */ 	bnel	$v1,$at,.PF0f0637fc
/*  f0637e4:	24010008 */ 	li	$at,0x8
/*  f0637e8:	0fc4b436 */ 	jal	explosionUpdateZ
/*  f0637ec:	02002025 */ 	move	$a0,$s0
/*  f0637f0:	10000010 */ 	b	.PF0f063834
/*  f0637f4:	00403025 */ 	move	$a2,$v0
/*  f0637f8:	24010008 */ 	li	$at,0x8
.PF0f0637fc:
/*  f0637fc:	54610006 */ 	bnel	$v1,$at,.PF0f063818
/*  f063800:	24010006 */ 	li	$at,0x6
/*  f063804:	0fc4bf31 */ 	jal	smokeUpdateZ
/*  f063808:	02002025 */ 	move	$a0,$s0
/*  f06380c:	10000009 */ 	b	.PF0f063834
/*  f063810:	00403025 */ 	move	$a2,$v0
/*  f063814:	24010006 */ 	li	$at,0x6
.PF0f063818:
/*  f063818:	54610007 */ 	bnel	$v1,$at,.PF0f063838
/*  f06381c:	962e035e */ 	lhu	$t6,0x35e($s1)
/*  f063820:	0fc5260c */ 	jal	splatTick
/*  f063824:	02002025 */ 	move	$a0,$s0
/*  f063828:	0fc30a3b */ 	jal	func0f0c2364
/*  f06382c:	02002025 */ 	move	$a0,$s0
/*  f063830:	00403025 */ 	move	$a2,$v0
.PF0f063834:
/*  f063834:	962e035e */ 	lhu	$t6,0x35e($s1)
.PF0f063838:
/*  f063838:	960f0038 */ 	lhu	$t7,0x38($s0)
/*  f06383c:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f063840:	51cf0009 */ 	beql	$t6,$t7,.PF0f063868
/*  f063844:	920e003f */ 	lbu	$t6,0x3f($s0)
/*  f063848:	8fb90088 */ 	lw	$t9,0x88($sp)
/*  f06384c:	c7aa0084 */ 	lwc1	$f10,0x84($sp)
/*  f063850:	c7b00080 */ 	lwc1	$f16,0x80($sp)
/*  f063854:	ae380034 */ 	sw	$t8,0x34($s1)
/*  f063858:	ae390038 */ 	sw	$t9,0x38($s1)
/*  f06385c:	e62a0044 */ 	swc1	$f10,0x44($s1)
/*  f063860:	e630004c */ 	swc1	$f16,0x4c($s1)
/*  f063864:	920e003f */ 	lbu	$t6,0x3f($s0)
.PF0f063868:
/*  f063868:	962d035c */ 	lhu	$t5,0x35c($s1)
/*  f06386c:	a600003a */ 	sh	$zero,0x3a($s0)
/*  f063870:	31cfffbf */ 	andi	$t7,$t6,0xffbf
/*  f063874:	a20f003f */ 	sb	$t7,0x3f($s0)
/*  f063878:	100000a5 */ 	b	.PF0f063b10
/*  f06387c:	a60d0038 */ 	sh	$t5,0x38($s0)
.PF0f063880:
/*  f063880:	92180000 */ 	lbu	$t8,0x0($s0)
/*  f063884:	93a30069 */ 	lbu	$v1,0x69($sp)
/*  f063888:	5698000b */ 	bnel	$s4,$t8,.PF0f0638b8
/*  f06388c:	9218003d */ 	lbu	$t8,0x3d($s0)
/*  f063890:	9219003d */ 	lbu	$t9,0x3d($s0)
/*  f063894:	001968c0 */ 	sll	$t5,$t9,0x3
/*  f063898:	01b96823 */ 	subu	$t5,$t5,$t9
/*  f06389c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0638a0:	022d1021 */ 	addu	$v0,$s1,$t5
/*  f0638a4:	944e0362 */ 	lhu	$t6,0x362($v0)
/*  f0638a8:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f0638ac:	10000009 */ 	b	.PF0f0638d4
/*  f0638b0:	a44f0362 */ 	sh	$t7,0x362($v0)
/*  f0638b4:	9218003d */ 	lbu	$t8,0x3d($s0)
.PF0f0638b8:
/*  f0638b8:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0638bc:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0638c0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0638c4:	02391021 */ 	addu	$v0,$s1,$t9
/*  f0638c8:	944d0360 */ 	lhu	$t5,0x360($v0)
/*  f0638cc:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f0638d0:	a44e0360 */ 	sh	$t6,0x360($v0)
.PF0f0638d4:
/*  f0638d4:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f0638d8:	8fb90034 */ 	lw	$t9,0x34($sp)
/*  f0638dc:	546f008d */ 	bnel	$v1,$t7,.PF0f063b14
/*  f0638e0:	8fad008c */ 	lw	$t5,0x8c($sp)
/*  f0638e4:	96180038 */ 	lhu	$t8,0x38($s0)
/*  f0638e8:	972d0378 */ 	lhu	$t5,0x378($t9)
/*  f0638ec:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0638f0:	530d001a */ 	beql	$t8,$t5,.PF0f06395c
/*  f0638f4:	8fad007c */ 	lw	$t5,0x7c($sp)
/*  f0638f8:	960e003a */ 	lhu	$t6,0x3a($s0)
/*  f0638fc:	3c013e80 */ 	lui	$at,0x3e80
/*  f063900:	44813000 */ 	mtc1	$at,$f6
/*  f063904:	ae2e0034 */ 	sw	$t6,0x34($s1)
/*  f063908:	9219003c */ 	lbu	$t9,0x3c($s0)
/*  f06390c:	960f003a */ 	lhu	$t7,0x3a($s0)
/*  f063910:	3c017f1b */ 	lui	$at,0x7f1b
/*  f063914:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f063918:	ae380038 */ 	sw	$t8,0x38($s1)
/*  f06391c:	330e0003 */ 	andi	$t6,$t8,0x3
/*  f063920:	a20e003c */ 	sb	$t6,0x3c($s0)
/*  f063924:	8e380034 */ 	lw	$t8,0x34($s1)
/*  f063928:	8e2f0038 */ 	lw	$t7,0x38($s1)
/*  f06392c:	44989000 */ 	mtc1	$t8,$f18
/*  f063930:	000fc883 */ 	sra	$t9,$t7,0x2
/*  f063934:	ae390038 */ 	sw	$t9,0x38($s1)
/*  f063938:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f06393c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f063940:	e6280044 */ 	swc1	$f8,0x44($s1)
/*  f063944:	c430b18c */ 	lwc1	$f16,-0x4e74($at)
/*  f063948:	c62a0044 */ 	lwc1	$f10,0x44($s1)
/*  f06394c:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f063950:	1000000c */ 	b	.PF0f063984
/*  f063954:	e632004c */ 	swc1	$f18,0x4c($s1)
/*  f063958:	8fad007c */ 	lw	$t5,0x7c($sp)
.PF0f06395c:
/*  f06395c:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f063960:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f063964:	ae2d0034 */ 	sw	$t5,0x34($s1)
/*  f063968:	ae2e0038 */ 	sw	$t6,0x38($s1)
/*  f06396c:	e6240044 */ 	swc1	$f4,0x44($s1)
/*  f063970:	c428b190 */ 	lwc1	$f8,-0x4e70($at)
/*  f063974:	c7a60074 */ 	lwc1	$f6,0x74($sp)
/*  f063978:	3c01800a */ 	lui	$at,0x800a
/*  f06397c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f063980:	e42aa55c */ 	swc1	$f10,-0x5aa4($at)
.PF0f063984:
/*  f063984:	92030000 */ 	lbu	$v1,0x0($s0)
/*  f063988:	16830013 */ 	bne	$s4,$v1,.PF0f0639d8
/*  f06398c:	00000000 */ 	nop
/*  f063990:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f063994:	02002025 */ 	move	$a0,$s0
/*  f063998:	0fc5260c */ 	jal	splatTick
/*  f06399c:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f0639a0:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f0639a4:	10400008 */ 	beqz	$v0,.PF0f0639c8
/*  f0639a8:	00000000 */ 	nop
/*  f0639ac:	8c4f02d4 */ 	lw	$t7,0x2d4($v0)
/*  f0639b0:	11e00005 */ 	beqz	$t7,.PF0f0639c8
/*  f0639b4:	00000000 */ 	nop
/*  f0639b8:	0fc64a62 */ 	jal	aibotTick
/*  f0639bc:	02002025 */ 	move	$a0,$s0
/*  f0639c0:	1000003c */ 	b	.PF0f063ab4
/*  f0639c4:	00403025 */ 	move	$a2,$v0
.PF0f0639c8:
/*  f0639c8:	0fc08c75 */ 	jal	func0f023098
/*  f0639cc:	02002025 */ 	move	$a0,$s0
/*  f0639d0:	10000038 */ 	b	.PF0f063ab4
/*  f0639d4:	00403025 */ 	move	$a2,$v0
.PF0f0639d8:
/*  f0639d8:	12a30005 */ 	beq	$s5,$v1,.PF0f0639f0
/*  f0639dc:	24010004 */ 	li	$at,0x4
/*  f0639e0:	10610003 */ 	beq	$v1,$at,.PF0f0639f0
/*  f0639e4:	24010002 */ 	li	$at,0x2
/*  f0639e8:	5461001d */ 	bnel	$v1,$at,.PF0f063a60
/*  f0639ec:	24010007 */ 	li	$at,0x7
.PF0f0639f0:
/*  f0639f0:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f0639f4:	3c188007 */ 	lui	$t8,0x8007
/*  f0639f8:	90590003 */ 	lbu	$t9,0x3($v0)
/*  f0639fc:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f063a00:	93189564 */ 	lbu	$t8,-0x6a9c($t8)
/*  f063a04:	57000006 */ 	bnezl	$t8,.PF0f063a20
/*  f063a08:	860d0002 */ 	lh	$t5,0x2($s0)
/*  f063a0c:	0fc1fa6a */ 	jal	objTick
/*  f063a10:	02002025 */ 	move	$a0,$s0
/*  f063a14:	10000027 */ 	b	.PF0f063ab4
/*  f063a18:	00403025 */ 	move	$a2,$v0
/*  f063a1c:	860d0002 */ 	lh	$t5,0x2($s0)
.PF0f063a20:
/*  f063a20:	5da00025 */ 	bgtzl	$t5,.PF0f063ab8
/*  f063a24:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f063a28:	920e003e */ 	lbu	$t6,0x3e($s0)
/*  f063a2c:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f063a30:	a20f003e */ 	sb	$t7,0x3e($s0)
/*  f063a34:	92380358 */ 	lbu	$t8,0x358($s1)
/*  f063a38:	31f900ff */ 	andi	$t9,$t7,0xff
/*  f063a3c:	270dffff */ 	addiu	$t5,$t8,-1
/*  f063a40:	01b9082a */ 	slt	$at,$t5,$t9
/*  f063a44:	5020001c */ 	beqzl	$at,.PF0f063ab8
/*  f063a48:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f063a4c:	0fc18c56 */ 	jal	propPrependToList2
/*  f063a50:	02002025 */ 	move	$a0,$s0
/*  f063a54:	10000017 */ 	b	.PF0f063ab4
/*  f063a58:	24060005 */ 	li	$a2,0x5
/*  f063a5c:	24010007 */ 	li	$at,0x7
.PF0f063a60:
/*  f063a60:	54610006 */ 	bnel	$v1,$at,.PF0f063a7c
/*  f063a64:	24010008 */ 	li	$at,0x8
/*  f063a68:	0fc4b436 */ 	jal	explosionUpdateZ
/*  f063a6c:	02002025 */ 	move	$a0,$s0
/*  f063a70:	10000010 */ 	b	.PF0f063ab4
/*  f063a74:	00403025 */ 	move	$a2,$v0
/*  f063a78:	24010008 */ 	li	$at,0x8
.PF0f063a7c:
/*  f063a7c:	54610006 */ 	bnel	$v1,$at,.PF0f063a98
/*  f063a80:	24010006 */ 	li	$at,0x6
/*  f063a84:	0fc4bf31 */ 	jal	smokeUpdateZ
/*  f063a88:	02002025 */ 	move	$a0,$s0
/*  f063a8c:	10000009 */ 	b	.PF0f063ab4
/*  f063a90:	00403025 */ 	move	$a2,$v0
/*  f063a94:	24010006 */ 	li	$at,0x6
.PF0f063a98:
/*  f063a98:	54610007 */ 	bnel	$v1,$at,.PF0f063ab8
/*  f063a9c:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f063aa0:	0fc5260c */ 	jal	splatTick
/*  f063aa4:	02002025 */ 	move	$a0,$s0
/*  f063aa8:	0fc30a3b */ 	jal	func0f0c2364
/*  f063aac:	02002025 */ 	move	$a0,$s0
/*  f063ab0:	00403025 */ 	move	$a2,$v0
.PF0f063ab4:
/*  f063ab4:	8faf0034 */ 	lw	$t7,0x34($sp)
.PF0f063ab8:
/*  f063ab8:	960e0038 */ 	lhu	$t6,0x38($s0)
/*  f063abc:	8fb9007c */ 	lw	$t9,0x7c($sp)
/*  f063ac0:	95f80378 */ 	lhu	$t8,0x378($t7)
/*  f063ac4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f063ac8:	51d8000c */ 	beql	$t6,$t8,.PF0f063afc
/*  f063acc:	9218003f */ 	lbu	$t8,0x3f($s0)
/*  f063ad0:	8fad0078 */ 	lw	$t5,0x78($sp)
/*  f063ad4:	c7b00074 */ 	lwc1	$f16,0x74($sp)
/*  f063ad8:	ae390034 */ 	sw	$t9,0x34($s1)
/*  f063adc:	ae2d0038 */ 	sw	$t5,0x38($s1)
/*  f063ae0:	e6300044 */ 	swc1	$f16,0x44($s1)
/*  f063ae4:	c424b194 */ 	lwc1	$f4,-0x4e6c($at)
/*  f063ae8:	c7b20074 */ 	lwc1	$f18,0x74($sp)
/*  f063aec:	3c01800a */ 	lui	$at,0x800a
/*  f063af0:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f063af4:	e426a55c */ 	swc1	$f6,-0x5aa4($at)
/*  f063af8:	9218003f */ 	lbu	$t8,0x3f($s0)
.PF0f063afc:
/*  f063afc:	962f035c */ 	lhu	$t7,0x35c($s1)
/*  f063b00:	a600003a */ 	sh	$zero,0x3a($s0)
/*  f063b04:	37190040 */ 	ori	$t9,$t8,0x40
/*  f063b08:	a219003f */ 	sb	$t9,0x3f($s0)
/*  f063b0c:	a60f0038 */ 	sh	$t7,0x38($s0)
.PF0f063b10:
/*  f063b10:	8fad008c */ 	lw	$t5,0x8c($sp)
.PF0f063b14:
/*  f063b14:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f063b18:	c7a80084 */ 	lwc1	$f8,0x84($sp)
/*  f063b1c:	c7aa0080 */ 	lwc1	$f10,0x80($sp)
/*  f063b20:	24010005 */ 	li	$at,0x5
/*  f063b24:	ae2d0034 */ 	sw	$t5,0x34($s1)
/*  f063b28:	ae2f0038 */ 	sw	$t7,0x38($s1)
/*  f063b2c:	e6280044 */ 	swc1	$f8,0x44($s1)
/*  f063b30:	14c10003 */ 	bne	$a2,$at,.PF0f063b40
/*  f063b34:	e62a004c */ 	swc1	$f10,0x4c($s1)
/*  f063b38:	1000001d */ 	b	.PF0f063bb0
/*  f063b3c:	8fa2005c */ 	lw	$v0,0x5c($sp)
.PF0f063b40:
/*  f063b40:	8e020020 */ 	lw	$v0,0x20($s0)
/*  f063b44:	8e2e0354 */ 	lw	$t6,0x354($s1)
/*  f063b48:	02002025 */ 	move	$a0,$s0
/*  f063b4c:	00c02825 */ 	move	$a1,$a2
/*  f063b50:	004ec026 */ 	xor	$t8,$v0,$t6
/*  f063b54:	2f180001 */ 	sltiu	$t8,$t8,0x1
/*  f063b58:	14d40012 */ 	bne	$a2,$s4,.PF0f063ba4
/*  f063b5c:	afb8004c */ 	sw	$t8,0x4c($sp)
/*  f063b60:	920f003f */ 	lbu	$t7,0x3f($s0)
/*  f063b64:	3419ffff */ 	li	$t9,0xffff
/*  f063b68:	a6190038 */ 	sh	$t9,0x38($s0)
/*  f063b6c:	35ee0080 */ 	ori	$t6,$t7,0x80
/*  f063b70:	a20e003f */ 	sb	$t6,0x3f($s0)
/*  f063b74:	afa20060 */ 	sw	$v0,0x60($sp)
/*  f063b78:	0fc18209 */ 	jal	propRemoveFromCurrentList
/*  f063b7c:	02002025 */ 	move	$a0,$s0
/*  f063b80:	0fc181e6 */ 	jal	propAppendToList1
/*  f063b84:	02002025 */ 	move	$a0,$s0
/*  f063b88:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f063b8c:	8fa20060 */ 	lw	$v0,0x60($sp)
/*  f063b90:	53000008 */ 	beqzl	$t8,.PF0f063bb4
/*  f063b94:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*  f063b98:	02001025 */ 	move	$v0,$s0
/*  f063b9c:	10000004 */ 	b	.PF0f063bb0
/*  f063ba0:	afa0004c */ 	sw	$zero,0x4c($sp)
.PF0f063ba4:
/*  f063ba4:	0fc18b71 */ 	jal	func0f062b64
/*  f063ba8:	afa20060 */ 	sw	$v0,0x60($sp)
/*  f063bac:	8fa20060 */ 	lw	$v0,0x60($sp)
.PF0f063bb0:
/*  f063bb0:	8fb9004c */ 	lw	$t9,0x4c($sp)
.PF0f063bb4:
/*  f063bb4:	00408025 */ 	move	$s0,$v0
/*  f063bb8:	5320fe53 */ 	beqzl	$t9,.PF0f063508
/*  f063bbc:	8e0f0020 */ 	lw	$t7,0x20($s0)
/*  f063bc0:	8e2d0290 */ 	lw	$t5,0x290($s1)
/*  f063bc4:	8faa0034 */ 	lw	$t2,0x34($sp)
/*  f063bc8:	24140003 */ 	li	$s4,0x3
/*  f063bcc:	15a00104 */ 	bnez	$t5,.PF0f063fe0
/*  f063bd0:	24150001 */ 	li	$s5,0x1
/*  f063bd4:	922f035a */ 	lbu	$t7,0x35a($s1)
/*  f063bd8:	afaa0034 */ 	sw	$t2,0x34($sp)
/*  f063bdc:	24087fff */ 	li	$t0,0x7fff
/*  f063be0:	55e00100 */ 	bnezl	$t7,.PF0f063fe4
/*  f063be4:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f063be8:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f063bec:	00004825 */ 	move	$t1,$zero
/*  f063bf0:	00002825 */ 	move	$a1,$zero
/*  f063bf4:	01805025 */ 	move	$t2,$t4
/*  f063bf8:	318b00ff */ 	andi	$t3,$t4,0xff
/*  f063bfc:	19800015 */ 	blez	$t4,.PF0f063c54
/*  f063c00:	01803825 */ 	move	$a3,$t4
/*  f063c04:	3c02800a */ 	lui	$v0,0x800a
/*  f063c08:	2442a510 */ 	addiu	$v0,$v0,-23280
.PF0f063c0c:
/*  f063c0c:	94430360 */ 	lhu	$v1,0x360($v0)
/*  f063c10:	01202025 */ 	move	$a0,$t1
/*  f063c14:	0068082a */ 	slt	$at,$v1,$t0
/*  f063c18:	10200003 */ 	beqz	$at,.PF0f063c28
/*  f063c1c:	00603025 */ 	move	$a2,$v1
/*  f063c20:	3068ffff */ 	andi	$t0,$v1,0xffff
/*  f063c24:	30aa00ff */ 	andi	$t2,$a1,0xff
.PF0f063c28:
/*  f063c28:	0086082a */ 	slt	$at,$a0,$a2
/*  f063c2c:	50200004 */ 	beqzl	$at,.PF0f063c40
/*  f063c30:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f063c34:	3069ffff */ 	andi	$t1,$v1,0xffff
/*  f063c38:	30ab00ff */ 	andi	$t3,$a1,0xff
/*  f063c3c:	24a50001 */ 	addiu	$a1,$a1,0x1
.PF0f063c40:
/*  f063c40:	00a7082a */ 	slt	$at,$a1,$a3
/*  f063c44:	1420fff1 */ 	bnez	$at,.PF0f063c0c
/*  f063c48:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f063c4c:	24087fff */ 	li	$t0,0x7fff
/*  f063c50:	00004825 */ 	move	$t1,$zero
.PF0f063c54:
/*  f063c54:	2403001c */ 	li	$v1,0x1c
/*  f063c58:	01630019 */ 	multu	$t3,$v1
/*  f063c5c:	00007012 */ 	mflo	$t6
/*  f063c60:	022ec021 */ 	addu	$t8,$s1,$t6
/*  f063c64:	97190360 */ 	lhu	$t9,0x360($t8)
/*  f063c68:	01430019 */ 	multu	$t2,$v1
/*  f063c6c:	00006812 */ 	mflo	$t5
/*  f063c70:	022d7821 */ 	addu	$t7,$s1,$t5
/*  f063c74:	95ee0360 */ 	lhu	$t6,0x360($t7)
/*  f063c78:	032e2823 */ 	subu	$a1,$t9,$t6
/*  f063c7c:	0005c043 */ 	sra	$t8,$a1,0x1
/*  f063c80:	1300001d */ 	beqz	$t8,.PF0f063cf8
/*  f063c84:	03002825 */ 	move	$a1,$t8
/*  f063c88:	8e30033c */ 	lw	$s0,0x33c($s1)
/*  f063c8c:	8e2d0354 */ 	lw	$t5,0x354($s1)
/*  f063c90:	01601025 */ 	move	$v0,$t3
/*  f063c94:	520d0019 */ 	beql	$s0,$t5,.PF0f063cfc
/*  f063c98:	318a00ff */ 	andi	$t2,$t4,0xff
/*  f063c9c:	920f003d */ 	lbu	$t7,0x3d($s0)
.PF0f063ca0:
/*  f063ca0:	544f0010 */ 	bnel	$v0,$t7,.PF0f063ce4
/*  f063ca4:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063ca8:	8e19003c */ 	lw	$t9,0x3c($s0)
/*  f063cac:	00197640 */ 	sll	$t6,$t9,0x19
/*  f063cb0:	000ec7c2 */ 	srl	$t8,$t6,0x1f
/*  f063cb4:	56b8000b */ 	bnel	$s5,$t8,.PF0f063ce4
/*  f063cb8:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063cbc:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f063cc0:	528d0008 */ 	beql	$s4,$t5,.PF0f063ce4
/*  f063cc4:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063cc8:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f063ccc:	14a00004 */ 	bnez	$a1,.PF0f063ce0
/*  f063cd0:	a20a003d */ 	sb	$t2,0x3d($s0)
/*  f063cd4:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f063cd8:	10000007 */ 	b	.PF0f063cf8
/*  f063cdc:	01803825 */ 	move	$a3,$t4
.PF0f063ce0:
/*  f063ce0:	8e100020 */ 	lw	$s0,0x20($s0)
.PF0f063ce4:
/*  f063ce4:	8e2f0354 */ 	lw	$t7,0x354($s1)
/*  f063ce8:	560fffed */ 	bnel	$s0,$t7,.PF0f063ca0
/*  f063cec:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f063cf0:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f063cf4:	01803825 */ 	move	$a3,$t4
.PF0f063cf8:
/*  f063cf8:	318a00ff */ 	andi	$t2,$t4,0xff
.PF0f063cfc:
/*  f063cfc:	318b00ff */ 	andi	$t3,$t4,0xff
/*  f063d00:	18e00016 */ 	blez	$a3,.PF0f063d5c
/*  f063d04:	00002825 */ 	move	$a1,$zero
/*  f063d08:	3c02800a */ 	lui	$v0,0x800a
/*  f063d0c:	2442a510 */ 	addiu	$v0,$v0,-23280
.PF0f063d10:
/*  f063d10:	94430364 */ 	lhu	$v1,0x364($v0)
/*  f063d14:	01202025 */ 	move	$a0,$t1
/*  f063d18:	0068082a */ 	slt	$at,$v1,$t0
/*  f063d1c:	10200003 */ 	beqz	$at,.PF0f063d2c
/*  f063d20:	00603025 */ 	move	$a2,$v1
/*  f063d24:	3068ffff */ 	andi	$t0,$v1,0xffff
/*  f063d28:	30aa00ff */ 	andi	$t2,$a1,0xff
.PF0f063d2c:
/*  f063d2c:	0086082a */ 	slt	$at,$a0,$a2
/*  f063d30:	50200004 */ 	beqzl	$at,.PF0f063d44
/*  f063d34:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f063d38:	3069ffff */ 	andi	$t1,$v1,0xffff
/*  f063d3c:	30ab00ff */ 	andi	$t3,$a1,0xff
/*  f063d40:	24a50001 */ 	addiu	$a1,$a1,0x1
.PF0f063d44:
/*  f063d44:	00a7082a */ 	slt	$at,$a1,$a3
/*  f063d48:	1420fff1 */ 	bnez	$at,.PF0f063d10
/*  f063d4c:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f063d50:	24087fff */ 	li	$t0,0x7fff
/*  f063d54:	00004825 */ 	move	$t1,$zero
/*  f063d58:	2403001c */ 	li	$v1,0x1c
.PF0f063d5c:
/*  f063d5c:	01630019 */ 	multu	$t3,$v1
/*  f063d60:	0000c812 */ 	mflo	$t9
/*  f063d64:	02397021 */ 	addu	$t6,$s1,$t9
/*  f063d68:	95d80364 */ 	lhu	$t8,0x364($t6)
/*  f063d6c:	01430019 */ 	multu	$t2,$v1
/*  f063d70:	00006812 */ 	mflo	$t5
/*  f063d74:	022d7821 */ 	addu	$t7,$s1,$t5
/*  f063d78:	95f90364 */ 	lhu	$t9,0x364($t7)
/*  f063d7c:	03192823 */ 	subu	$a1,$t8,$t9
/*  f063d80:	00057043 */ 	sra	$t6,$a1,0x1
/*  f063d84:	11c0001c */ 	beqz	$t6,.PF0f063df8
/*  f063d88:	01c02825 */ 	move	$a1,$t6
/*  f063d8c:	8e30033c */ 	lw	$s0,0x33c($s1)
/*  f063d90:	8e2d0354 */ 	lw	$t5,0x354($s1)
/*  f063d94:	01601025 */ 	move	$v0,$t3
/*  f063d98:	520d0018 */ 	beql	$s0,$t5,.PF0f063dfc
/*  f063d9c:	318a00ff */ 	andi	$t2,$t4,0xff
/*  f063da0:	920f003d */ 	lbu	$t7,0x3d($s0)
.PF0f063da4:
/*  f063da4:	544f000f */ 	bnel	$v0,$t7,.PF0f063de4
/*  f063da8:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063dac:	8e18003c */ 	lw	$t8,0x3c($s0)
/*  f063db0:	00187640 */ 	sll	$t6,$t8,0x19
/*  f063db4:	05c2000b */ 	bltzl	$t6,.PF0f063de4
/*  f063db8:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063dbc:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f063dc0:	528d0008 */ 	beql	$s4,$t5,.PF0f063de4
/*  f063dc4:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063dc8:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f063dcc:	14a00004 */ 	bnez	$a1,.PF0f063de0
/*  f063dd0:	a20a003d */ 	sb	$t2,0x3d($s0)
/*  f063dd4:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f063dd8:	10000007 */ 	b	.PF0f063df8
/*  f063ddc:	01803825 */ 	move	$a3,$t4
.PF0f063de0:
/*  f063de0:	8e100020 */ 	lw	$s0,0x20($s0)
.PF0f063de4:
/*  f063de4:	8e2f0354 */ 	lw	$t7,0x354($s1)
/*  f063de8:	560fffee */ 	bnel	$s0,$t7,.PF0f063da4
/*  f063dec:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f063df0:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f063df4:	01803825 */ 	move	$a3,$t4
.PF0f063df8:
/*  f063df8:	318a00ff */ 	andi	$t2,$t4,0xff
.PF0f063dfc:
/*  f063dfc:	318b00ff */ 	andi	$t3,$t4,0xff
/*  f063e00:	18e00016 */ 	blez	$a3,.PF0f063e5c
/*  f063e04:	00002825 */ 	move	$a1,$zero
/*  f063e08:	3c02800a */ 	lui	$v0,0x800a
/*  f063e0c:	2442a510 */ 	addiu	$v0,$v0,-23280
.PF0f063e10:
/*  f063e10:	94430362 */ 	lhu	$v1,0x362($v0)
/*  f063e14:	01202025 */ 	move	$a0,$t1
/*  f063e18:	0068082a */ 	slt	$at,$v1,$t0
/*  f063e1c:	10200003 */ 	beqz	$at,.PF0f063e2c
/*  f063e20:	00603025 */ 	move	$a2,$v1
/*  f063e24:	3068ffff */ 	andi	$t0,$v1,0xffff
/*  f063e28:	30aa00ff */ 	andi	$t2,$a1,0xff
.PF0f063e2c:
/*  f063e2c:	0086082a */ 	slt	$at,$a0,$a2
/*  f063e30:	50200004 */ 	beqzl	$at,.PF0f063e44
/*  f063e34:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f063e38:	3069ffff */ 	andi	$t1,$v1,0xffff
/*  f063e3c:	30ab00ff */ 	andi	$t3,$a1,0xff
/*  f063e40:	24a50001 */ 	addiu	$a1,$a1,0x1
.PF0f063e44:
/*  f063e44:	00a7082a */ 	slt	$at,$a1,$a3
/*  f063e48:	1420fff1 */ 	bnez	$at,.PF0f063e10
/*  f063e4c:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f063e50:	24087fff */ 	li	$t0,0x7fff
/*  f063e54:	00004825 */ 	move	$t1,$zero
/*  f063e58:	2403001c */ 	li	$v1,0x1c
.PF0f063e5c:
/*  f063e5c:	01630019 */ 	multu	$t3,$v1
/*  f063e60:	0000c012 */ 	mflo	$t8
/*  f063e64:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f063e68:	972e0362 */ 	lhu	$t6,0x362($t9)
/*  f063e6c:	01430019 */ 	multu	$t2,$v1
/*  f063e70:	00006812 */ 	mflo	$t5
/*  f063e74:	022d7821 */ 	addu	$t7,$s1,$t5
/*  f063e78:	95f80362 */ 	lhu	$t8,0x362($t7)
/*  f063e7c:	01d82823 */ 	subu	$a1,$t6,$t8
/*  f063e80:	0005c843 */ 	sra	$t9,$a1,0x1
/*  f063e84:	1320001d */ 	beqz	$t9,.PF0f063efc
/*  f063e88:	03202825 */ 	move	$a1,$t9
/*  f063e8c:	8e30033c */ 	lw	$s0,0x33c($s1)
/*  f063e90:	8e2d0354 */ 	lw	$t5,0x354($s1)
/*  f063e94:	01601025 */ 	move	$v0,$t3
/*  f063e98:	520d0019 */ 	beql	$s0,$t5,.PF0f063f00
/*  f063e9c:	318a00ff */ 	andi	$t2,$t4,0xff
/*  f063ea0:	920f003d */ 	lbu	$t7,0x3d($s0)
.PF0f063ea4:
/*  f063ea4:	544f0010 */ 	bnel	$v0,$t7,.PF0f063ee8
/*  f063ea8:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063eac:	8e0e003c */ 	lw	$t6,0x3c($s0)
/*  f063eb0:	000ec640 */ 	sll	$t8,$t6,0x19
/*  f063eb4:	0018cfc2 */ 	srl	$t9,$t8,0x1f
/*  f063eb8:	56b9000b */ 	bnel	$s5,$t9,.PF0f063ee8
/*  f063ebc:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063ec0:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f063ec4:	568d0008 */ 	bnel	$s4,$t5,.PF0f063ee8
/*  f063ec8:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063ecc:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f063ed0:	14a00004 */ 	bnez	$a1,.PF0f063ee4
/*  f063ed4:	a20a003d */ 	sb	$t2,0x3d($s0)
/*  f063ed8:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f063edc:	10000007 */ 	b	.PF0f063efc
/*  f063ee0:	01803825 */ 	move	$a3,$t4
.PF0f063ee4:
/*  f063ee4:	8e100020 */ 	lw	$s0,0x20($s0)
.PF0f063ee8:
/*  f063ee8:	8e2f0354 */ 	lw	$t7,0x354($s1)
/*  f063eec:	560fffed */ 	bnel	$s0,$t7,.PF0f063ea4
/*  f063ef0:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f063ef4:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f063ef8:	01803825 */ 	move	$a3,$t4
.PF0f063efc:
/*  f063efc:	318a00ff */ 	andi	$t2,$t4,0xff
.PF0f063f00:
/*  f063f00:	318b00ff */ 	andi	$t3,$t4,0xff
/*  f063f04:	18e00014 */ 	blez	$a3,.PF0f063f58
/*  f063f08:	00002825 */ 	move	$a1,$zero
/*  f063f0c:	3c02800a */ 	lui	$v0,0x800a
/*  f063f10:	2442a510 */ 	addiu	$v0,$v0,-23280
.PF0f063f14:
/*  f063f14:	94430366 */ 	lhu	$v1,0x366($v0)
/*  f063f18:	01202025 */ 	move	$a0,$t1
/*  f063f1c:	0068082a */ 	slt	$at,$v1,$t0
/*  f063f20:	10200003 */ 	beqz	$at,.PF0f063f30
/*  f063f24:	00603025 */ 	move	$a2,$v1
/*  f063f28:	3068ffff */ 	andi	$t0,$v1,0xffff
/*  f063f2c:	30aa00ff */ 	andi	$t2,$a1,0xff
.PF0f063f30:
/*  f063f30:	0086082a */ 	slt	$at,$a0,$a2
/*  f063f34:	50200004 */ 	beqzl	$at,.PF0f063f48
/*  f063f38:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f063f3c:	3069ffff */ 	andi	$t1,$v1,0xffff
/*  f063f40:	30ab00ff */ 	andi	$t3,$a1,0xff
/*  f063f44:	24a50001 */ 	addiu	$a1,$a1,0x1
.PF0f063f48:
/*  f063f48:	00a7082a */ 	slt	$at,$a1,$a3
/*  f063f4c:	1420fff1 */ 	bnez	$at,.PF0f063f14
/*  f063f50:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f063f54:	2403001c */ 	li	$v1,0x1c
.PF0f063f58:
/*  f063f58:	01630019 */ 	multu	$t3,$v1
/*  f063f5c:	00007012 */ 	mflo	$t6
/*  f063f60:	022ec021 */ 	addu	$t8,$s1,$t6
/*  f063f64:	97190366 */ 	lhu	$t9,0x366($t8)
/*  f063f68:	01430019 */ 	multu	$t2,$v1
/*  f063f6c:	00006812 */ 	mflo	$t5
/*  f063f70:	022d7821 */ 	addu	$t7,$s1,$t5
/*  f063f74:	95ee0366 */ 	lhu	$t6,0x366($t7)
/*  f063f78:	032e2823 */ 	subu	$a1,$t9,$t6
/*  f063f7c:	0005c043 */ 	sra	$t8,$a1,0x1
/*  f063f80:	13000017 */ 	beqz	$t8,.PF0f063fe0
/*  f063f84:	03002825 */ 	move	$a1,$t8
/*  f063f88:	8e30033c */ 	lw	$s0,0x33c($s1)
/*  f063f8c:	8e2d0354 */ 	lw	$t5,0x354($s1)
/*  f063f90:	01601025 */ 	move	$v0,$t3
/*  f063f94:	520d0013 */ 	beql	$s0,$t5,.PF0f063fe4
/*  f063f98:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f063f9c:	920f003d */ 	lbu	$t7,0x3d($s0)
.PF0f063fa0:
/*  f063fa0:	544f000c */ 	bnel	$v0,$t7,.PF0f063fd4
/*  f063fa4:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063fa8:	8e19003c */ 	lw	$t9,0x3c($s0)
/*  f063fac:	0019c640 */ 	sll	$t8,$t9,0x19
/*  f063fb0:	07020008 */ 	bltzl	$t8,.PF0f063fd4
/*  f063fb4:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063fb8:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f063fbc:	568d0005 */ 	bnel	$s4,$t5,.PF0f063fd4
/*  f063fc0:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f063fc4:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f063fc8:	10a00005 */ 	beqz	$a1,.PF0f063fe0
/*  f063fcc:	a20a003d */ 	sb	$t2,0x3d($s0)
/*  f063fd0:	8e100020 */ 	lw	$s0,0x20($s0)
.PF0f063fd4:
/*  f063fd4:	8e2f0354 */ 	lw	$t7,0x354($s1)
/*  f063fd8:	560ffff1 */ 	bnel	$s0,$t7,.PF0f063fa0
/*  f063fdc:	920f003d */ 	lbu	$t7,0x3d($s0)
.PF0f063fe0:
/*  f063fe0:	8fb9008c */ 	lw	$t9,0x8c($sp)
.PF0f063fe4:
/*  f063fe4:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f063fe8:	c7b00084 */ 	lwc1	$f16,0x84($sp)
/*  f063fec:	c7b20080 */ 	lwc1	$f18,0x80($sp)
/*  f063ff0:	8faa0034 */ 	lw	$t2,0x34($sp)
/*  f063ff4:	ae390034 */ 	sw	$t9,0x34($s1)
/*  f063ff8:	ae2e0038 */ 	sw	$t6,0x38($s1)
/*  f063ffc:	e6300044 */ 	swc1	$f16,0x44($s1)
/*  f064000:	e632004c */ 	swc1	$f18,0x4c($s1)
/*  f064004:	8fad0098 */ 	lw	$t5,0x98($sp)
/*  f064008:	ad400370 */ 	sw	$zero,0x370($t2)
/*  f06400c:	9638035c */ 	lhu	$t8,0x35c($s1)
/*  f064010:	11a00007 */ 	beqz	$t5,.PF0f064030
/*  f064014:	a5580378 */ 	sh	$t8,0x378($t2)
/*  f064018:	0fc2432d */ 	jal	alarmTick
/*  f06401c:	00000000 */ 	nop
/*  f064020:	0fc24cfe */ 	jal	func0f093508
/*  f064024:	00000000 */ 	nop
/*  f064028:	0fc198b9 */ 	jal	func0f066054
/*  f06402c:	00000000 */ 	nop
.PF0f064030:
/*  f064030:	0fc09214 */ 	jal	func0f02472c
/*  f064034:	00000000 */ 	nop
/*  f064038:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f06403c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f064040:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f064044:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f064048:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f06404c:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f064050:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f064054:	03e00008 */ 	jr	$ra
/*  f064058:	27bd0098 */ 	addiu	$sp,$sp,0x98
);
#elif VERSION >= VERSION_NTSC_1_0
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
/*  f0634e0:	0fc64634 */ 	jal	aibotTick
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
/*  f063734:	0fc64634 */ 	jal	aibotTick
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
#else
GLOBAL_ASM(
glabel func0f06302c
/*  f0622b0:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0622b4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0622b8:	3c11800a */ 	lui	$s1,0x800a
/*  f0622bc:	2631e6c0 */ 	addiu	$s1,$s1,-6464
/*  f0622c0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0622c4:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0622c8:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0622cc:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0622d0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0622d4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0622d8:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f0622dc:	10800009 */ 	beqz	$a0,.NB0f062304
/*  f0622e0:	ae20043c */ 	sw	$zero,0x43c($s1)
/*  f0622e4:	9622035c */ 	lhu	$v0,0x35c($s1)
/*  f0622e8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0622ec:	244f0001 */ 	addiu	$t7,$v0,0x1
/*  f0622f0:	31f8ffff */ 	andi	$t8,$t7,0xffff
/*  f0622f4:	a62f035c */ 	sh	$t7,0x35c($s1)
/*  f0622f8:	17010002 */ 	bne	$t8,$at,.NB0f062304
/*  f0622fc:	a622035e */ 	sh	$v0,0x35e($s1)
/*  f062300:	a620035c */ 	sh	$zero,0x35c($s1)
.NB0f062304:
/*  f062304:	92270358 */ 	lbu	$a3,0x358($s1)
/*  f062308:	8e390034 */ 	lw	$t9,0x34($s1)
/*  f06230c:	8e2d0038 */ 	lw	$t5,0x38($s1)
/*  f062310:	c6240044 */ 	lwc1	$f4,0x44($s1)
/*  f062314:	c626004c */ 	lwc1	$f6,0x4c($s1)
/*  f062318:	00002825 */ 	or	$a1,$zero,$zero
/*  f06231c:	afb9008c */ 	sw	$t9,0x8c($sp)
/*  f062320:	afad0088 */ 	sw	$t5,0x88($sp)
/*  f062324:	e7a40084 */ 	swc1	$f4,0x84($sp)
/*  f062328:	18e0000e */ 	blez	$a3,.NB0f062364
/*  f06232c:	e7a60080 */ 	swc1	$f6,0x80($sp)
/*  f062330:	3c02800a */ 	lui	$v0,0x800a
/*  f062334:	2442e6c0 */ 	addiu	$v0,$v0,-6464
/*  f062338:	8c4e0370 */ 	lw	$t6,0x370($v0)
.NB0f06233c:
/*  f06233c:	8e2f0034 */ 	lw	$t7,0x34($s1)
/*  f062340:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f062344:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f062348:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f06234c:	ac580354 */ 	sw	$t8,0x354($v0)
/*  f062350:	92270358 */ 	lbu	$a3,0x358($s1)
/*  f062354:	00a7082a */ 	slt	$at,$a1,$a3
/*  f062358:	5420fff8 */ 	bnezl	$at,.NB0f06233c
/*  f06235c:	8c4e0370 */ 	lw	$t6,0x370($v0)
/*  f062360:	00002825 */ 	or	$a1,$zero,$zero
.NB0f062364:
/*  f062364:	9239035a */ 	lbu	$t9,0x35a($s1)
/*  f062368:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f06236c:	24140003 */ 	addiu	$s4,$zero,0x3
/*  f062370:	272d0001 */ 	addiu	$t5,$t9,0x1
/*  f062374:	31a300ff */ 	andi	$v1,$t5,0xff
/*  f062378:	0067082a */ 	slt	$at,$v1,$a3
/*  f06237c:	14200003 */ 	bnez	$at,.NB0f06238c
/*  f062380:	a22d035a */ 	sb	$t5,0x35a($s1)
/*  f062384:	a220035a */ 	sb	$zero,0x35a($s1)
/*  f062388:	300300ff */ 	andi	$v1,$zero,0xff
.NB0f06238c:
/*  f06238c:	306900ff */ 	andi	$t1,$v1,0xff
/*  f062390:	000970c0 */ 	sll	$t6,$t1,0x3
/*  f062394:	01c97023 */ 	subu	$t6,$t6,$t1
/*  f062398:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f06239c:	022e5021 */ 	addu	$t2,$s1,$t6
/*  f0623a0:	8d420370 */ 	lw	$v0,0x370($t2)
/*  f0623a4:	3c013e80 */ 	lui	$at,0x3e80
/*  f0623a8:	8d4f0374 */ 	lw	$t7,0x374($t2)
/*  f0623ac:	44824000 */ 	mtc1	$v0,$f8
/*  f0623b0:	44818000 */ 	mtc1	$at,$f16
/*  f0623b4:	01e24021 */ 	addu	$t0,$t7,$v0
/*  f0623b8:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0623bc:	31180003 */ 	andi	$t8,$t0,0x3
/*  f0623c0:	ad580374 */ 	sw	$t8,0x374($t2)
/*  f0623c4:	922d0358 */ 	lbu	$t5,0x358($s1)
/*  f0623c8:	24480002 */ 	addiu	$t0,$v0,0x2
/*  f0623cc:	0008c883 */ 	sra	$t9,$t0,0x2
/*  f0623d0:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0623d4:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f0623d8:	03204025 */ 	or	$t0,$t9,$zero
/*  f0623dc:	3c02800a */ 	lui	$v0,0x800a
/*  f0623e0:	2413008c */ 	addiu	$s3,$zero,0x8c
/*  f0623e4:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f0623e8:	19a0000c */ 	blez	$t5,.NB0f06241c
/*  f0623ec:	e7b20074 */ 	swc1	$f18,0x74($sp)
/*  f0623f0:	2442e6c0 */ 	addiu	$v0,$v0,-6464
/*  f0623f4:	a4400360 */ 	sh	$zero,0x360($v0)
.NB0f0623f8:
/*  f0623f8:	a4400362 */ 	sh	$zero,0x362($v0)
/*  f0623fc:	a4400364 */ 	sh	$zero,0x364($v0)
/*  f062400:	a4400366 */ 	sh	$zero,0x366($v0)
/*  f062404:	922e0358 */ 	lbu	$t6,0x358($s1)
/*  f062408:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f06240c:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f062410:	00ae082a */ 	slt	$at,$a1,$t6
/*  f062414:	5420fff8 */ 	bnezl	$at,.NB0f0623f8
/*  f062418:	a4400360 */ 	sh	$zero,0x360($v0)
.NB0f06241c:
/*  f06241c:	8e2f0290 */ 	lw	$t7,0x290($s1)
/*  f062420:	55e00024 */ 	bnezl	$t7,.NB0f0624b4
/*  f062424:	8e380334 */ 	lw	$t8,0x334($s1)
/*  f062428:	8e380334 */ 	lw	$t8,0x334($s1)
/*  f06242c:	8e300338 */ 	lw	$s0,0x338($s1)
/*  f062430:	2407ff7f */ 	addiu	$a3,$zero,-129
/*  f062434:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f062438:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f06243c:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f062440:	03302821 */ 	addu	$a1,$t9,$s0
/*  f062444:	0205082b */ 	sltu	$at,$s0,$a1
/*  f062448:	1020002e */ 	beqz	$at,.NB0f062504
/*  f06244c:	2406ffbf */ 	addiu	$a2,$zero,-65
/*  f062450:	2404fffd */ 	addiu	$a0,$zero,-3
.NB0f062454:
/*  f062454:	92020001 */ 	lbu	$v0,0x1($s0)
/*  f062458:	304d0002 */ 	andi	$t5,$v0,0x2
/*  f06245c:	11a00003 */ 	beqz	$t5,.NB0f06246c
/*  f062460:	00401825 */ 	or	$v1,$v0,$zero
/*  f062464:	00441024 */ 	and	$v0,$v0,$a0
/*  f062468:	304300ff */ 	andi	$v1,$v0,0xff
.NB0f06246c:
/*  f06246c:	306f0040 */ 	andi	$t7,$v1,0x40
/*  f062470:	11e00005 */ 	beqz	$t7,.NB0f062488
/*  f062474:	306d0080 */ 	andi	$t5,$v1,0x80
/*  f062478:	34780080 */ 	ori	$t8,$v1,0x80
/*  f06247c:	03061024 */ 	and	$v0,$t8,$a2
/*  f062480:	10000004 */ 	beqz	$zero,.NB0f062494
/*  f062484:	304300ff */ 	andi	$v1,$v0,0xff
.NB0f062488:
/*  f062488:	11a00002 */ 	beqz	$t5,.NB0f062494
/*  f06248c:	00671024 */ 	and	$v0,$v1,$a3
/*  f062490:	304300ff */ 	andi	$v1,$v0,0xff
.NB0f062494:
/*  f062494:	26100048 */ 	addiu	$s0,$s0,0x48
/*  f062498:	0205082b */ 	sltu	$at,$s0,$a1
/*  f06249c:	346f0008 */ 	ori	$t7,$v1,0x8
/*  f0624a0:	1420ffec */ 	bnez	$at,.NB0f062454
/*  f0624a4:	a20fffb9 */ 	sb	$t7,-0x47($s0)
/*  f0624a8:	10000017 */ 	beqz	$zero,.NB0f062508
/*  f0624ac:	afaa0034 */ 	sw	$t2,0x34($sp)
/*  f0624b0:	8e380334 */ 	lw	$t8,0x334($s1)
.NB0f0624b4:
/*  f0624b4:	8e300338 */ 	lw	$s0,0x338($s1)
/*  f0624b8:	2404fffd */ 	addiu	$a0,$zero,-3
/*  f0624bc:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0624c0:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0624c4:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0624c8:	03302821 */ 	addu	$a1,$t9,$s0
/*  f0624cc:	0205082b */ 	sltu	$at,$s0,$a1
/*  f0624d0:	5020000d */ 	beqzl	$at,.NB0f062508
/*  f0624d4:	afaa0034 */ 	sw	$t2,0x34($sp)
.NB0f0624d8:
/*  f0624d8:	92020001 */ 	lbu	$v0,0x1($s0)
/*  f0624dc:	304d0002 */ 	andi	$t5,$v0,0x2
/*  f0624e0:	11a00004 */ 	beqz	$t5,.NB0f0624f4
/*  f0624e4:	00401825 */ 	or	$v1,$v0,$zero
/*  f0624e8:	00641024 */ 	and	$v0,$v1,$a0
/*  f0624ec:	304e00ff */ 	andi	$t6,$v0,0xff
/*  f0624f0:	01c01025 */ 	or	$v0,$t6,$zero
.NB0f0624f4:
/*  f0624f4:	26100048 */ 	addiu	$s0,$s0,0x48
/*  f0624f8:	0205082b */ 	sltu	$at,$s0,$a1
/*  f0624fc:	1420fff6 */ 	bnez	$at,.NB0f0624d8
/*  f062500:	a202ffb9 */ 	sb	$v0,-0x47($s0)
.NB0f062504:
/*  f062504:	afaa0034 */ 	sw	$t2,0x34($sp)
.NB0f062508:
/*  f062508:	afaa0034 */ 	sw	$t2,0x34($sp)
/*  f06250c:	8e30033c */ 	lw	$s0,0x33c($s1)
/*  f062510:	afa80078 */ 	sw	$t0,0x78($sp)
/*  f062514:	a3a90069 */ 	sb	$t1,0x69($sp)
/*  f062518:	8e0f0020 */ 	lw	$t7,0x20($s0)
.NB0f06251c:
/*  f06251c:	8e390354 */ 	lw	$t9,0x354($s1)
/*  f062520:	8e2e02ac */ 	lw	$t6,0x2ac($s1)
/*  f062524:	00003025 */ 	or	$a2,$zero,$zero
/*  f062528:	01f96826 */ 	xor	$t5,$t7,$t9
/*  f06252c:	2dad0001 */ 	sltiu	$t5,$t5,0x1
/*  f062530:	afad004c */ 	sw	$t5,0x4c($sp)
/*  f062534:	12ae0003 */ 	beq	$s5,$t6,.NB0f062544
/*  f062538:	afaf005c */ 	sw	$t7,0x5c($sp)
/*  f06253c:	10000002 */ 	beqz	$zero,.NB0f062548
/*  f062540:	02a02825 */ 	or	$a1,$s5,$zero
.NB0f062544:
/*  f062544:	9225035b */ 	lbu	$a1,0x35b($s1)
.NB0f062548:
/*  f062548:	86080028 */ 	lh	$t0,0x28($s0)
/*  f06254c:	26070028 */ 	addiu	$a3,$s0,0x28
/*  f062550:	00e01825 */ 	or	$v1,$a3,$zero
/*  f062554:	1248000f */ 	beq	$s2,$t0,.NB0f062594
/*  f062558:	3c04800b */ 	lui	$a0,0x800b
/*  f06255c:	8c8490a8 */ 	lw	$a0,-0x6f58($a0)
/*  f062560:	84620000 */ 	lh	$v0,0x0($v1)
.NB0f062564:
/*  f062564:	00530019 */ 	multu	$v0,$s3
/*  f062568:	00007812 */ 	mflo	$t7
/*  f06256c:	008fc021 */ 	addu	$t8,$a0,$t7
/*  f062570:	97190000 */ 	lhu	$t9,0x0($t8)
/*  f062574:	332d0004 */ 	andi	$t5,$t9,0x4
/*  f062578:	51a00003 */ 	beqzl	$t5,.NB0f062588
/*  f06257c:	84620002 */ 	lh	$v0,0x2($v1)
/*  f062580:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f062584:	84620002 */ 	lh	$v0,0x2($v1)
.NB0f062588:
/*  f062588:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f06258c:	1642fff5 */ 	bne	$s2,$v0,.NB0f062564
/*  f062590:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f062594:
/*  f062594:	54a0003c */ 	bnezl	$a1,.NB0f062688
/*  f062598:	960d003a */ 	lhu	$t5,0x3a($s0)
/*  f06259c:	92030000 */ 	lbu	$v1,0x0($s0)
/*  f0625a0:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0625a4:	14610003 */ 	bne	$v1,$at,.NB0f0625b4
/*  f0625a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0625ac:	1000000b */ 	beqz	$zero,.NB0f0625dc
/*  f0625b0:	24a50001 */ 	addiu	$a1,$a1,0x1
.NB0f0625b4:
/*  f0625b4:	12a30003 */ 	beq	$s5,$v1,.NB0f0625c4
/*  f0625b8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0625bc:	14610007 */ 	bne	$v1,$at,.NB0f0625dc
/*  f0625c0:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0625c4:
/*  f0625c4:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f0625c8:	8c4e0040 */ 	lw	$t6,0x40($v0)
/*  f0625cc:	31cf0080 */ 	andi	$t7,$t6,0x80
/*  f0625d0:	11e00002 */ 	beqz	$t7,.NB0f0625dc
/*  f0625d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0625d8:	24a50001 */ 	addiu	$a1,$a1,0x1
.NB0f0625dc:
/*  f0625dc:	54a0002a */ 	bnezl	$a1,.NB0f062688
/*  f0625e0:	960d003a */ 	lhu	$t5,0x3a($s0)
/*  f0625e4:	92180001 */ 	lbu	$t8,0x1($s0)
/*  f0625e8:	24010084 */ 	addiu	$at,$zero,0x84
/*  f0625ec:	33190084 */ 	andi	$t9,$t8,0x84
/*  f0625f0:	57210004 */ 	bnel	$t9,$at,.NB0f062604
/*  f0625f4:	9202003f */ 	lbu	$v0,0x3f($s0)
/*  f0625f8:	10000022 */ 	beqz	$zero,.NB0f062684
/*  f0625fc:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f062600:	9202003f */ 	lbu	$v0,0x3f($s0)
.NB0f062604:
/*  f062604:	000269c2 */ 	srl	$t5,$v0,0x7
/*  f062608:	11a00004 */ 	beqz	$t5,.NB0f06261c
/*  f06260c:	304eff7f */ 	andi	$t6,$v0,0xff7f
/*  f062610:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f062614:	1000001b */ 	beqz	$zero,.NB0f062684
/*  f062618:	a20e003f */ 	sb	$t6,0x3f($s0)
.NB0f06261c:
/*  f06261c:	8e0f003c */ 	lw	$t7,0x3c($s0)
/*  f062620:	000fce80 */ 	sll	$t9,$t7,0x1a
/*  f062624:	07210003 */ 	bgez	$t9,.NB0f062634
/*  f062628:	00000000 */ 	sll	$zero,$zero,0x0
/*  f06262c:	10000015 */ 	beqz	$zero,.NB0f062684
/*  f062630:	24a50001 */ 	addiu	$a1,$a1,0x1
.NB0f062634:
/*  f062634:	1248000f */ 	beq	$s2,$t0,.NB0f062674
/*  f062638:	00e01825 */ 	or	$v1,$a3,$zero
/*  f06263c:	3c04800b */ 	lui	$a0,0x800b
/*  f062640:	8c8490a8 */ 	lw	$a0,-0x6f58($a0)
/*  f062644:	84e20000 */ 	lh	$v0,0x0($a3)
.NB0f062648:
/*  f062648:	00530019 */ 	multu	$v0,$s3
/*  f06264c:	00006812 */ 	mflo	$t5
/*  f062650:	008d7021 */ 	addu	$t6,$a0,$t5
/*  f062654:	95cf0000 */ 	lhu	$t7,0x0($t6)
/*  f062658:	31f80008 */ 	andi	$t8,$t7,0x8
/*  f06265c:	57000006 */ 	bnezl	$t8,.NB0f062678
/*  f062660:	84790000 */ 	lh	$t9,0x0($v1)
/*  f062664:	84620002 */ 	lh	$v0,0x2($v1)
/*  f062668:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f06266c:	1642fff6 */ 	bne	$s2,$v0,.NB0f062648
/*  f062670:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f062674:
/*  f062674:	84790000 */ 	lh	$t9,0x0($v1)
.NB0f062678:
/*  f062678:	52590003 */ 	beql	$s2,$t9,.NB0f062688
/*  f06267c:	960d003a */ 	lhu	$t5,0x3a($s0)
/*  f062680:	24a50001 */ 	addiu	$a1,$a1,0x1
.NB0f062684:
/*  f062684:	960d003a */ 	lhu	$t5,0x3a($s0)
.NB0f062688:
/*  f062688:	8e2e0034 */ 	lw	$t6,0x34($s1)
/*  f06268c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f062690:	18a0007d */ 	blez	$a1,.NB0f062888
/*  f062694:	a60f003a */ 	sh	$t7,0x3a($s0)
/*  f062698:	9638035e */ 	lhu	$t8,0x35e($s1)
/*  f06269c:	96190038 */ 	lhu	$t9,0x38($s0)
/*  f0626a0:	31edffff */ 	andi	$t5,$t7,0xffff
/*  f0626a4:	53190016 */ 	beql	$t8,$t9,.NB0f062700
/*  f0626a8:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f0626ac:	ae2d0034 */ 	sw	$t5,0x34($s1)
/*  f0626b0:	920f003c */ 	lbu	$t7,0x3c($s0)
/*  f0626b4:	960e003a */ 	lhu	$t6,0x3a($s0)
/*  f0626b8:	3c013e80 */ 	lui	$at,0x3e80
/*  f0626bc:	44814000 */ 	mtc1	$at,$f8
/*  f0626c0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0626c4:	ae380038 */ 	sw	$t8,0x38($s1)
/*  f0626c8:	330d0003 */ 	andi	$t5,$t8,0x3
/*  f0626cc:	a20d003c */ 	sb	$t5,0x3c($s0)
/*  f0626d0:	8e380034 */ 	lw	$t8,0x34($s1)
/*  f0626d4:	8e2e0038 */ 	lw	$t6,0x38($s1)
/*  f0626d8:	44982000 */ 	mtc1	$t8,$f4
/*  f0626dc:	000e7883 */ 	sra	$t7,$t6,0x2
/*  f0626e0:	ae2f0038 */ 	sw	$t7,0x38($s1)
/*  f0626e4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0626e8:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0626ec:	e62a0044 */ 	swc1	$f10,0x44($s1)
/*  f0626f0:	c6300044 */ 	lwc1	$f16,0x44($s1)
/*  f0626f4:	10000009 */ 	beqz	$zero,.NB0f06271c
/*  f0626f8:	e630004c */ 	swc1	$f16,0x4c($s1)
/*  f0626fc:	8fb9008c */ 	lw	$t9,0x8c($sp)
.NB0f062700:
/*  f062700:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f062704:	c7b20084 */ 	lwc1	$f18,0x84($sp)
/*  f062708:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f06270c:	ae390034 */ 	sw	$t9,0x34($s1)
/*  f062710:	ae2d0038 */ 	sw	$t5,0x38($s1)
/*  f062714:	e6320044 */ 	swc1	$f18,0x44($s1)
/*  f062718:	e624004c */ 	swc1	$f4,0x4c($s1)
.NB0f06271c:
/*  f06271c:	920e0000 */ 	lbu	$t6,0x0($s0)
/*  f062720:	a200003e */ 	sb	$zero,0x3e($s0)
/*  f062724:	568e001c */ 	bnel	$s4,$t6,.NB0f062798
/*  f062728:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f06272c:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f062730:	02002025 */ 	or	$a0,$s0,$zero
/*  f062734:	0fc50cd4 */ 	jal	splatTick
/*  f062738:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f06273c:	8fa20048 */ 	lw	$v0,0x48($sp)
/*  f062740:	10400008 */ 	beqz	$v0,.NB0f062764
/*  f062744:	00000000 */ 	sll	$zero,$zero,0x0
/*  f062748:	8c4f02d4 */ 	lw	$t7,0x2d4($v0)
/*  f06274c:	11e00005 */ 	beqz	$t7,.NB0f062764
/*  f062750:	00000000 */ 	sll	$zero,$zero,0x0
/*  f062754:	0fc62e6d */ 	jal	aibotTick
/*  f062758:	02002025 */ 	or	$a0,$s0,$zero
/*  f06275c:	10000004 */ 	beqz	$zero,.NB0f062770
/*  f062760:	00403025 */ 	or	$a2,$v0,$zero
.NB0f062764:
/*  f062764:	0fc08ae1 */ 	jal	func0f023098
/*  f062768:	02002025 */ 	or	$a0,$s0,$zero
/*  f06276c:	00403025 */ 	or	$a2,$v0,$zero
.NB0f062770:
/*  f062770:	9218003d */ 	lbu	$t8,0x3d($s0)
/*  f062774:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f062778:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f06277c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f062780:	02391021 */ 	addu	$v0,$s1,$t9
/*  f062784:	944d0366 */ 	lhu	$t5,0x366($v0)
/*  f062788:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f06278c:	1000002b */ 	beqz	$zero,.NB0f06283c
/*  f062790:	a44e0366 */ 	sh	$t6,0x366($v0)
/*  f062794:	920f003d */ 	lbu	$t7,0x3d($s0)
.NB0f062798:
/*  f062798:	24010004 */ 	addiu	$at,$zero,0x4
/*  f06279c:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0627a0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0627a4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0627a8:	02381021 */ 	addu	$v0,$s1,$t8
/*  f0627ac:	94590364 */ 	lhu	$t9,0x364($v0)
/*  f0627b0:	272d0001 */ 	addiu	$t5,$t9,0x1
/*  f0627b4:	a44d0364 */ 	sh	$t5,0x364($v0)
/*  f0627b8:	92030000 */ 	lbu	$v1,0x0($s0)
/*  f0627bc:	12a30005 */ 	beq	$s5,$v1,.NB0f0627d4
/*  f0627c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0627c4:	10610003 */ 	beq	$v1,$at,.NB0f0627d4
/*  f0627c8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0627cc:	54610006 */ 	bnel	$v1,$at,.NB0f0627e8
/*  f0627d0:	24010007 */ 	addiu	$at,$zero,0x7
.NB0f0627d4:
/*  f0627d4:	0fc1f474 */ 	jal	objTick
/*  f0627d8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0627dc:	10000017 */ 	beqz	$zero,.NB0f06283c
/*  f0627e0:	00403025 */ 	or	$a2,$v0,$zero
/*  f0627e4:	24010007 */ 	addiu	$at,$zero,0x7
.NB0f0627e8:
/*  f0627e8:	54610006 */ 	bnel	$v1,$at,.NB0f062804
/*  f0627ec:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0627f0:	0fc49c4e */ 	jal	explosionUpdateZ
/*  f0627f4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0627f8:	10000010 */ 	beqz	$zero,.NB0f06283c
/*  f0627fc:	00403025 */ 	or	$a2,$v0,$zero
/*  f062800:	24010008 */ 	addiu	$at,$zero,0x8
.NB0f062804:
/*  f062804:	54610006 */ 	bnel	$v1,$at,.NB0f062820
/*  f062808:	24010006 */ 	addiu	$at,$zero,0x6
/*  f06280c:	0fc4a745 */ 	jal	smokeUpdateZ
/*  f062810:	02002025 */ 	or	$a0,$s0,$zero
/*  f062814:	10000009 */ 	beqz	$zero,.NB0f06283c
/*  f062818:	00403025 */ 	or	$a2,$v0,$zero
/*  f06281c:	24010006 */ 	addiu	$at,$zero,0x6
.NB0f062820:
/*  f062820:	54610007 */ 	bnel	$v1,$at,.NB0f062840
/*  f062824:	962e035e */ 	lhu	$t6,0x35e($s1)
/*  f062828:	0fc50cd4 */ 	jal	splatTick
/*  f06282c:	02002025 */ 	or	$a0,$s0,$zero
/*  f062830:	0fc2ffcb */ 	jal	func0f0c2364
/*  f062834:	02002025 */ 	or	$a0,$s0,$zero
/*  f062838:	00403025 */ 	or	$a2,$v0,$zero
.NB0f06283c:
/*  f06283c:	962e035e */ 	lhu	$t6,0x35e($s1)
.NB0f062840:
/*  f062840:	960f0038 */ 	lhu	$t7,0x38($s0)
/*  f062844:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f062848:	51cf0009 */ 	beql	$t6,$t7,.NB0f062870
/*  f06284c:	920e003f */ 	lbu	$t6,0x3f($s0)
/*  f062850:	8fb90088 */ 	lw	$t9,0x88($sp)
/*  f062854:	c7a60084 */ 	lwc1	$f6,0x84($sp)
/*  f062858:	c7a80080 */ 	lwc1	$f8,0x80($sp)
/*  f06285c:	ae380034 */ 	sw	$t8,0x34($s1)
/*  f062860:	ae390038 */ 	sw	$t9,0x38($s1)
/*  f062864:	e6260044 */ 	swc1	$f6,0x44($s1)
/*  f062868:	e628004c */ 	swc1	$f8,0x4c($s1)
/*  f06286c:	920e003f */ 	lbu	$t6,0x3f($s0)
.NB0f062870:
/*  f062870:	962d035c */ 	lhu	$t5,0x35c($s1)
/*  f062874:	a600003a */ 	sh	$zero,0x3a($s0)
/*  f062878:	31cfffbf */ 	andi	$t7,$t6,0xffbf
/*  f06287c:	a20f003f */ 	sb	$t7,0x3f($s0)
/*  f062880:	1000009c */ 	beqz	$zero,.NB0f062af4
/*  f062884:	a60d0038 */ 	sh	$t5,0x38($s0)
.NB0f062888:
/*  f062888:	92180000 */ 	lbu	$t8,0x0($s0)
/*  f06288c:	93a30069 */ 	lbu	$v1,0x69($sp)
/*  f062890:	5698000b */ 	bnel	$s4,$t8,.NB0f0628c0
/*  f062894:	9218003d */ 	lbu	$t8,0x3d($s0)
/*  f062898:	9219003d */ 	lbu	$t9,0x3d($s0)
/*  f06289c:	001968c0 */ 	sll	$t5,$t9,0x3
/*  f0628a0:	01b96823 */ 	subu	$t5,$t5,$t9
/*  f0628a4:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0628a8:	022d1021 */ 	addu	$v0,$s1,$t5
/*  f0628ac:	944e0362 */ 	lhu	$t6,0x362($v0)
/*  f0628b0:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f0628b4:	10000009 */ 	beqz	$zero,.NB0f0628dc
/*  f0628b8:	a44f0362 */ 	sh	$t7,0x362($v0)
/*  f0628bc:	9218003d */ 	lbu	$t8,0x3d($s0)
.NB0f0628c0:
/*  f0628c0:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0628c4:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0628c8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0628cc:	02391021 */ 	addu	$v0,$s1,$t9
/*  f0628d0:	944d0360 */ 	lhu	$t5,0x360($v0)
/*  f0628d4:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f0628d8:	a44e0360 */ 	sh	$t6,0x360($v0)
.NB0f0628dc:
/*  f0628dc:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f0628e0:	8fb90034 */ 	lw	$t9,0x34($sp)
/*  f0628e4:	546f0084 */ 	bnel	$v1,$t7,.NB0f062af8
/*  f0628e8:	8fad008c */ 	lw	$t5,0x8c($sp)
/*  f0628ec:	96180038 */ 	lhu	$t8,0x38($s0)
/*  f0628f0:	972d0378 */ 	lhu	$t5,0x378($t9)
/*  f0628f4:	3c01800a */ 	lui	$at,0x800a
/*  f0628f8:	530d0017 */ 	beql	$t8,$t5,.NB0f062958
/*  f0628fc:	8fad007c */ 	lw	$t5,0x7c($sp)
/*  f062900:	960e003a */ 	lhu	$t6,0x3a($s0)
/*  f062904:	3c013e80 */ 	lui	$at,0x3e80
/*  f062908:	44819000 */ 	mtc1	$at,$f18
/*  f06290c:	ae2e0034 */ 	sw	$t6,0x34($s1)
/*  f062910:	9219003c */ 	lbu	$t9,0x3c($s0)
/*  f062914:	960f003a */ 	lhu	$t7,0x3a($s0)
/*  f062918:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f06291c:	ae380038 */ 	sw	$t8,0x38($s1)
/*  f062920:	330e0003 */ 	andi	$t6,$t8,0x3
/*  f062924:	a20e003c */ 	sb	$t6,0x3c($s0)
/*  f062928:	8e380034 */ 	lw	$t8,0x34($s1)
/*  f06292c:	8e2f0038 */ 	lw	$t7,0x38($s1)
/*  f062930:	44985000 */ 	mtc1	$t8,$f10
/*  f062934:	000fc883 */ 	sra	$t9,$t7,0x2
/*  f062938:	ae390038 */ 	sw	$t9,0x38($s1)
/*  f06293c:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f062940:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f062944:	e6240044 */ 	swc1	$f4,0x44($s1)
/*  f062948:	c6260044 */ 	lwc1	$f6,0x44($s1)
/*  f06294c:	10000009 */ 	beqz	$zero,.NB0f062974
/*  f062950:	e626004c */ 	swc1	$f6,0x4c($s1)
/*  f062954:	8fad007c */ 	lw	$t5,0x7c($sp)
.NB0f062958:
/*  f062958:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f06295c:	c7a80074 */ 	lwc1	$f8,0x74($sp)
/*  f062960:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f062964:	ae2d0034 */ 	sw	$t5,0x34($s1)
/*  f062968:	ae2e0038 */ 	sw	$t6,0x38($s1)
/*  f06296c:	e6280044 */ 	swc1	$f8,0x44($s1)
/*  f062970:	e42ae70c */ 	swc1	$f10,-0x18f4($at)
.NB0f062974:
/*  f062974:	92030000 */ 	lbu	$v1,0x0($s0)
/*  f062978:	16830013 */ 	bne	$s4,$v1,.NB0f0629c8
/*  f06297c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f062980:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f062984:	02002025 */ 	or	$a0,$s0,$zero
/*  f062988:	0fc50cd4 */ 	jal	splatTick
/*  f06298c:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f062990:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f062994:	10400008 */ 	beqz	$v0,.NB0f0629b8
/*  f062998:	00000000 */ 	sll	$zero,$zero,0x0
/*  f06299c:	8c4f02d4 */ 	lw	$t7,0x2d4($v0)
/*  f0629a0:	11e00005 */ 	beqz	$t7,.NB0f0629b8
/*  f0629a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0629a8:	0fc62e6d */ 	jal	aibotTick
/*  f0629ac:	02002025 */ 	or	$a0,$s0,$zero
/*  f0629b0:	1000003c */ 	beqz	$zero,.NB0f062aa4
/*  f0629b4:	00403025 */ 	or	$a2,$v0,$zero
.NB0f0629b8:
/*  f0629b8:	0fc08ae1 */ 	jal	func0f023098
/*  f0629bc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0629c0:	10000038 */ 	beqz	$zero,.NB0f062aa4
/*  f0629c4:	00403025 */ 	or	$a2,$v0,$zero
.NB0f0629c8:
/*  f0629c8:	12a30005 */ 	beq	$s5,$v1,.NB0f0629e0
/*  f0629cc:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0629d0:	10610003 */ 	beq	$v1,$at,.NB0f0629e0
/*  f0629d4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0629d8:	5461001d */ 	bnel	$v1,$at,.NB0f062a50
/*  f0629dc:	24010007 */ 	addiu	$at,$zero,0x7
.NB0f0629e0:
/*  f0629e0:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f0629e4:	3c188007 */ 	lui	$t8,0x8007
/*  f0629e8:	90590003 */ 	lbu	$t9,0x3($v0)
/*  f0629ec:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f0629f0:	9318bf84 */ 	lbu	$t8,-0x407c($t8)
/*  f0629f4:	57000006 */ 	bnezl	$t8,.NB0f062a10
/*  f0629f8:	860d0002 */ 	lh	$t5,0x2($s0)
/*  f0629fc:	0fc1f474 */ 	jal	objTick
/*  f062a00:	02002025 */ 	or	$a0,$s0,$zero
/*  f062a04:	10000027 */ 	beqz	$zero,.NB0f062aa4
/*  f062a08:	00403025 */ 	or	$a2,$v0,$zero
/*  f062a0c:	860d0002 */ 	lh	$t5,0x2($s0)
.NB0f062a10:
/*  f062a10:	5da00025 */ 	bgtzl	$t5,.NB0f062aa8
/*  f062a14:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f062a18:	920e003e */ 	lbu	$t6,0x3e($s0)
/*  f062a1c:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f062a20:	a20f003e */ 	sb	$t7,0x3e($s0)
/*  f062a24:	92380358 */ 	lbu	$t8,0x358($s1)
/*  f062a28:	31f900ff */ 	andi	$t9,$t7,0xff
/*  f062a2c:	270dffff */ 	addiu	$t5,$t8,-1
/*  f062a30:	01b9082a */ 	slt	$at,$t5,$t9
/*  f062a34:	5020001c */ 	beqzl	$at,.NB0f062aa8
/*  f062a38:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f062a3c:	0fc1885f */ 	jal	propPrependToList2
/*  f062a40:	02002025 */ 	or	$a0,$s0,$zero
/*  f062a44:	10000017 */ 	beqz	$zero,.NB0f062aa4
/*  f062a48:	24060005 */ 	addiu	$a2,$zero,0x5
/*  f062a4c:	24010007 */ 	addiu	$at,$zero,0x7
.NB0f062a50:
/*  f062a50:	54610006 */ 	bnel	$v1,$at,.NB0f062a6c
/*  f062a54:	24010008 */ 	addiu	$at,$zero,0x8
/*  f062a58:	0fc49c4e */ 	jal	explosionUpdateZ
/*  f062a5c:	02002025 */ 	or	$a0,$s0,$zero
/*  f062a60:	10000010 */ 	beqz	$zero,.NB0f062aa4
/*  f062a64:	00403025 */ 	or	$a2,$v0,$zero
/*  f062a68:	24010008 */ 	addiu	$at,$zero,0x8
.NB0f062a6c:
/*  f062a6c:	54610006 */ 	bnel	$v1,$at,.NB0f062a88
/*  f062a70:	24010006 */ 	addiu	$at,$zero,0x6
/*  f062a74:	0fc4a745 */ 	jal	smokeUpdateZ
/*  f062a78:	02002025 */ 	or	$a0,$s0,$zero
/*  f062a7c:	10000009 */ 	beqz	$zero,.NB0f062aa4
/*  f062a80:	00403025 */ 	or	$a2,$v0,$zero
/*  f062a84:	24010006 */ 	addiu	$at,$zero,0x6
.NB0f062a88:
/*  f062a88:	54610007 */ 	bnel	$v1,$at,.NB0f062aa8
/*  f062a8c:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f062a90:	0fc50cd4 */ 	jal	splatTick
/*  f062a94:	02002025 */ 	or	$a0,$s0,$zero
/*  f062a98:	0fc2ffcb */ 	jal	func0f0c2364
/*  f062a9c:	02002025 */ 	or	$a0,$s0,$zero
/*  f062aa0:	00403025 */ 	or	$a2,$v0,$zero
.NB0f062aa4:
/*  f062aa4:	8faf0034 */ 	lw	$t7,0x34($sp)
.NB0f062aa8:
/*  f062aa8:	960e0038 */ 	lhu	$t6,0x38($s0)
/*  f062aac:	8fb9007c */ 	lw	$t9,0x7c($sp)
/*  f062ab0:	95f80378 */ 	lhu	$t8,0x378($t7)
/*  f062ab4:	3c01800a */ 	lui	$at,0x800a
/*  f062ab8:	51d80009 */ 	beql	$t6,$t8,.NB0f062ae0
/*  f062abc:	9218003f */ 	lbu	$t8,0x3f($s0)
/*  f062ac0:	8fad0078 */ 	lw	$t5,0x78($sp)
/*  f062ac4:	c7b00074 */ 	lwc1	$f16,0x74($sp)
/*  f062ac8:	c7b20074 */ 	lwc1	$f18,0x74($sp)
/*  f062acc:	ae390034 */ 	sw	$t9,0x34($s1)
/*  f062ad0:	ae2d0038 */ 	sw	$t5,0x38($s1)
/*  f062ad4:	e6300044 */ 	swc1	$f16,0x44($s1)
/*  f062ad8:	e432e70c */ 	swc1	$f18,-0x18f4($at)
/*  f062adc:	9218003f */ 	lbu	$t8,0x3f($s0)
.NB0f062ae0:
/*  f062ae0:	962f035c */ 	lhu	$t7,0x35c($s1)
/*  f062ae4:	a600003a */ 	sh	$zero,0x3a($s0)
/*  f062ae8:	37190040 */ 	ori	$t9,$t8,0x40
/*  f062aec:	a219003f */ 	sb	$t9,0x3f($s0)
/*  f062af0:	a60f0038 */ 	sh	$t7,0x38($s0)
.NB0f062af4:
/*  f062af4:	8fad008c */ 	lw	$t5,0x8c($sp)
.NB0f062af8:
/*  f062af8:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f062afc:	c7a40084 */ 	lwc1	$f4,0x84($sp)
/*  f062b00:	c7a60080 */ 	lwc1	$f6,0x80($sp)
/*  f062b04:	24010005 */ 	addiu	$at,$zero,0x5
/*  f062b08:	ae2d0034 */ 	sw	$t5,0x34($s1)
/*  f062b0c:	ae2f0038 */ 	sw	$t7,0x38($s1)
/*  f062b10:	e6240044 */ 	swc1	$f4,0x44($s1)
/*  f062b14:	14c10003 */ 	bne	$a2,$at,.NB0f062b24
/*  f062b18:	e626004c */ 	swc1	$f6,0x4c($s1)
/*  f062b1c:	1000001d */ 	beqz	$zero,.NB0f062b94
/*  f062b20:	8fa2005c */ 	lw	$v0,0x5c($sp)
.NB0f062b24:
/*  f062b24:	8e020020 */ 	lw	$v0,0x20($s0)
/*  f062b28:	8e2e0354 */ 	lw	$t6,0x354($s1)
/*  f062b2c:	02002025 */ 	or	$a0,$s0,$zero
/*  f062b30:	00c02825 */ 	or	$a1,$a2,$zero
/*  f062b34:	004ec026 */ 	xor	$t8,$v0,$t6
/*  f062b38:	2f180001 */ 	sltiu	$t8,$t8,0x1
/*  f062b3c:	14d40012 */ 	bne	$a2,$s4,.NB0f062b88
/*  f062b40:	afb8004c */ 	sw	$t8,0x4c($sp)
/*  f062b44:	920f003f */ 	lbu	$t7,0x3f($s0)
/*  f062b48:	3419ffff */ 	dli	$t9,0xffff
/*  f062b4c:	a6190038 */ 	sh	$t9,0x38($s0)
/*  f062b50:	35ee0080 */ 	ori	$t6,$t7,0x80
/*  f062b54:	a20e003f */ 	sb	$t6,0x3f($s0)
/*  f062b58:	afa20060 */ 	sw	$v0,0x60($sp)
/*  f062b5c:	0fc17e21 */ 	jal	propRemoveFromCurrentList
/*  f062b60:	02002025 */ 	or	$a0,$s0,$zero
/*  f062b64:	0fc17dfe */ 	jal	propAppendToList1
/*  f062b68:	02002025 */ 	or	$a0,$s0,$zero
/*  f062b6c:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f062b70:	8fa20060 */ 	lw	$v0,0x60($sp)
/*  f062b74:	53000008 */ 	beqzl	$t8,.NB0f062b98
/*  f062b78:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*  f062b7c:	02001025 */ 	or	$v0,$s0,$zero
/*  f062b80:	10000004 */ 	beqz	$zero,.NB0f062b94
/*  f062b84:	afa0004c */ 	sw	$zero,0x4c($sp)
.NB0f062b88:
/*  f062b88:	0fc1877a */ 	jal	func0f062b64
/*  f062b8c:	afa20060 */ 	sw	$v0,0x60($sp)
/*  f062b90:	8fa20060 */ 	lw	$v0,0x60($sp)
.NB0f062b94:
/*  f062b94:	8fb9004c */ 	lw	$t9,0x4c($sp)
.NB0f062b98:
/*  f062b98:	00408025 */ 	or	$s0,$v0,$zero
/*  f062b9c:	5320fe5f */ 	beqzl	$t9,.NB0f06251c
/*  f062ba0:	8e0f0020 */ 	lw	$t7,0x20($s0)
/*  f062ba4:	8e2d0290 */ 	lw	$t5,0x290($s1)
/*  f062ba8:	8faa0034 */ 	lw	$t2,0x34($sp)
/*  f062bac:	24140003 */ 	addiu	$s4,$zero,0x3
/*  f062bb0:	15a00104 */ 	bnez	$t5,.NB0f062fc4
/*  f062bb4:	24150001 */ 	addiu	$s5,$zero,0x1
/*  f062bb8:	922f035a */ 	lbu	$t7,0x35a($s1)
/*  f062bbc:	afaa0034 */ 	sw	$t2,0x34($sp)
/*  f062bc0:	24087fff */ 	addiu	$t0,$zero,0x7fff
/*  f062bc4:	55e00100 */ 	bnezl	$t7,.NB0f062fc8
/*  f062bc8:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f062bcc:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f062bd0:	00004825 */ 	or	$t1,$zero,$zero
/*  f062bd4:	00002825 */ 	or	$a1,$zero,$zero
/*  f062bd8:	01805025 */ 	or	$t2,$t4,$zero
/*  f062bdc:	318b00ff */ 	andi	$t3,$t4,0xff
/*  f062be0:	19800015 */ 	blez	$t4,.NB0f062c38
/*  f062be4:	01803825 */ 	or	$a3,$t4,$zero
/*  f062be8:	3c02800a */ 	lui	$v0,0x800a
/*  f062bec:	2442e6c0 */ 	addiu	$v0,$v0,-6464
.NB0f062bf0:
/*  f062bf0:	94430360 */ 	lhu	$v1,0x360($v0)
/*  f062bf4:	01202025 */ 	or	$a0,$t1,$zero
/*  f062bf8:	0068082a */ 	slt	$at,$v1,$t0
/*  f062bfc:	10200003 */ 	beqz	$at,.NB0f062c0c
/*  f062c00:	00603025 */ 	or	$a2,$v1,$zero
/*  f062c04:	3068ffff */ 	andi	$t0,$v1,0xffff
/*  f062c08:	30aa00ff */ 	andi	$t2,$a1,0xff
.NB0f062c0c:
/*  f062c0c:	0086082a */ 	slt	$at,$a0,$a2
/*  f062c10:	50200004 */ 	beqzl	$at,.NB0f062c24
/*  f062c14:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f062c18:	3069ffff */ 	andi	$t1,$v1,0xffff
/*  f062c1c:	30ab00ff */ 	andi	$t3,$a1,0xff
/*  f062c20:	24a50001 */ 	addiu	$a1,$a1,0x1
.NB0f062c24:
/*  f062c24:	00a7082a */ 	slt	$at,$a1,$a3
/*  f062c28:	1420fff1 */ 	bnez	$at,.NB0f062bf0
/*  f062c2c:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f062c30:	24087fff */ 	addiu	$t0,$zero,0x7fff
/*  f062c34:	00004825 */ 	or	$t1,$zero,$zero
.NB0f062c38:
/*  f062c38:	2403001c */ 	addiu	$v1,$zero,0x1c
/*  f062c3c:	01630019 */ 	multu	$t3,$v1
/*  f062c40:	00007012 */ 	mflo	$t6
/*  f062c44:	022ec021 */ 	addu	$t8,$s1,$t6
/*  f062c48:	97190360 */ 	lhu	$t9,0x360($t8)
/*  f062c4c:	01430019 */ 	multu	$t2,$v1
/*  f062c50:	00006812 */ 	mflo	$t5
/*  f062c54:	022d7821 */ 	addu	$t7,$s1,$t5
/*  f062c58:	95ee0360 */ 	lhu	$t6,0x360($t7)
/*  f062c5c:	032e2823 */ 	subu	$a1,$t9,$t6
/*  f062c60:	0005c043 */ 	sra	$t8,$a1,0x1
/*  f062c64:	1300001d */ 	beqz	$t8,.NB0f062cdc
/*  f062c68:	03002825 */ 	or	$a1,$t8,$zero
/*  f062c6c:	8e30033c */ 	lw	$s0,0x33c($s1)
/*  f062c70:	8e2d0354 */ 	lw	$t5,0x354($s1)
/*  f062c74:	01601025 */ 	or	$v0,$t3,$zero
/*  f062c78:	520d0019 */ 	beql	$s0,$t5,.NB0f062ce0
/*  f062c7c:	318a00ff */ 	andi	$t2,$t4,0xff
/*  f062c80:	920f003d */ 	lbu	$t7,0x3d($s0)
.NB0f062c84:
/*  f062c84:	544f0010 */ 	bnel	$v0,$t7,.NB0f062cc8
/*  f062c88:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f062c8c:	8e19003c */ 	lw	$t9,0x3c($s0)
/*  f062c90:	00197640 */ 	sll	$t6,$t9,0x19
/*  f062c94:	000ec7c2 */ 	srl	$t8,$t6,0x1f
/*  f062c98:	56b8000b */ 	bnel	$s5,$t8,.NB0f062cc8
/*  f062c9c:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f062ca0:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f062ca4:	528d0008 */ 	beql	$s4,$t5,.NB0f062cc8
/*  f062ca8:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f062cac:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f062cb0:	14a00004 */ 	bnez	$a1,.NB0f062cc4
/*  f062cb4:	a20a003d */ 	sb	$t2,0x3d($s0)
/*  f062cb8:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f062cbc:	10000007 */ 	beqz	$zero,.NB0f062cdc
/*  f062cc0:	01803825 */ 	or	$a3,$t4,$zero
.NB0f062cc4:
/*  f062cc4:	8e100020 */ 	lw	$s0,0x20($s0)
.NB0f062cc8:
/*  f062cc8:	8e2f0354 */ 	lw	$t7,0x354($s1)
/*  f062ccc:	560fffed */ 	bnel	$s0,$t7,.NB0f062c84
/*  f062cd0:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f062cd4:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f062cd8:	01803825 */ 	or	$a3,$t4,$zero
.NB0f062cdc:
/*  f062cdc:	318a00ff */ 	andi	$t2,$t4,0xff
.NB0f062ce0:
/*  f062ce0:	318b00ff */ 	andi	$t3,$t4,0xff
/*  f062ce4:	18e00016 */ 	blez	$a3,.NB0f062d40
/*  f062ce8:	00002825 */ 	or	$a1,$zero,$zero
/*  f062cec:	3c02800a */ 	lui	$v0,0x800a
/*  f062cf0:	2442e6c0 */ 	addiu	$v0,$v0,-6464
.NB0f062cf4:
/*  f062cf4:	94430364 */ 	lhu	$v1,0x364($v0)
/*  f062cf8:	01202025 */ 	or	$a0,$t1,$zero
/*  f062cfc:	0068082a */ 	slt	$at,$v1,$t0
/*  f062d00:	10200003 */ 	beqz	$at,.NB0f062d10
/*  f062d04:	00603025 */ 	or	$a2,$v1,$zero
/*  f062d08:	3068ffff */ 	andi	$t0,$v1,0xffff
/*  f062d0c:	30aa00ff */ 	andi	$t2,$a1,0xff
.NB0f062d10:
/*  f062d10:	0086082a */ 	slt	$at,$a0,$a2
/*  f062d14:	50200004 */ 	beqzl	$at,.NB0f062d28
/*  f062d18:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f062d1c:	3069ffff */ 	andi	$t1,$v1,0xffff
/*  f062d20:	30ab00ff */ 	andi	$t3,$a1,0xff
/*  f062d24:	24a50001 */ 	addiu	$a1,$a1,0x1
.NB0f062d28:
/*  f062d28:	00a7082a */ 	slt	$at,$a1,$a3
/*  f062d2c:	1420fff1 */ 	bnez	$at,.NB0f062cf4
/*  f062d30:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f062d34:	24087fff */ 	addiu	$t0,$zero,0x7fff
/*  f062d38:	00004825 */ 	or	$t1,$zero,$zero
/*  f062d3c:	2403001c */ 	addiu	$v1,$zero,0x1c
.NB0f062d40:
/*  f062d40:	01630019 */ 	multu	$t3,$v1
/*  f062d44:	0000c812 */ 	mflo	$t9
/*  f062d48:	02397021 */ 	addu	$t6,$s1,$t9
/*  f062d4c:	95d80364 */ 	lhu	$t8,0x364($t6)
/*  f062d50:	01430019 */ 	multu	$t2,$v1
/*  f062d54:	00006812 */ 	mflo	$t5
/*  f062d58:	022d7821 */ 	addu	$t7,$s1,$t5
/*  f062d5c:	95f90364 */ 	lhu	$t9,0x364($t7)
/*  f062d60:	03192823 */ 	subu	$a1,$t8,$t9
/*  f062d64:	00057043 */ 	sra	$t6,$a1,0x1
/*  f062d68:	11c0001c */ 	beqz	$t6,.NB0f062ddc
/*  f062d6c:	01c02825 */ 	or	$a1,$t6,$zero
/*  f062d70:	8e30033c */ 	lw	$s0,0x33c($s1)
/*  f062d74:	8e2d0354 */ 	lw	$t5,0x354($s1)
/*  f062d78:	01601025 */ 	or	$v0,$t3,$zero
/*  f062d7c:	520d0018 */ 	beql	$s0,$t5,.NB0f062de0
/*  f062d80:	318a00ff */ 	andi	$t2,$t4,0xff
/*  f062d84:	920f003d */ 	lbu	$t7,0x3d($s0)
.NB0f062d88:
/*  f062d88:	544f000f */ 	bnel	$v0,$t7,.NB0f062dc8
/*  f062d8c:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f062d90:	8e18003c */ 	lw	$t8,0x3c($s0)
/*  f062d94:	00187640 */ 	sll	$t6,$t8,0x19
/*  f062d98:	05c2000b */ 	bltzl	$t6,.NB0f062dc8
/*  f062d9c:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f062da0:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f062da4:	528d0008 */ 	beql	$s4,$t5,.NB0f062dc8
/*  f062da8:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f062dac:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f062db0:	14a00004 */ 	bnez	$a1,.NB0f062dc4
/*  f062db4:	a20a003d */ 	sb	$t2,0x3d($s0)
/*  f062db8:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f062dbc:	10000007 */ 	beqz	$zero,.NB0f062ddc
/*  f062dc0:	01803825 */ 	or	$a3,$t4,$zero
.NB0f062dc4:
/*  f062dc4:	8e100020 */ 	lw	$s0,0x20($s0)
.NB0f062dc8:
/*  f062dc8:	8e2f0354 */ 	lw	$t7,0x354($s1)
/*  f062dcc:	560fffee */ 	bnel	$s0,$t7,.NB0f062d88
/*  f062dd0:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f062dd4:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f062dd8:	01803825 */ 	or	$a3,$t4,$zero
.NB0f062ddc:
/*  f062ddc:	318a00ff */ 	andi	$t2,$t4,0xff
.NB0f062de0:
/*  f062de0:	318b00ff */ 	andi	$t3,$t4,0xff
/*  f062de4:	18e00016 */ 	blez	$a3,.NB0f062e40
/*  f062de8:	00002825 */ 	or	$a1,$zero,$zero
/*  f062dec:	3c02800a */ 	lui	$v0,0x800a
/*  f062df0:	2442e6c0 */ 	addiu	$v0,$v0,-6464
.NB0f062df4:
/*  f062df4:	94430362 */ 	lhu	$v1,0x362($v0)
/*  f062df8:	01202025 */ 	or	$a0,$t1,$zero
/*  f062dfc:	0068082a */ 	slt	$at,$v1,$t0
/*  f062e00:	10200003 */ 	beqz	$at,.NB0f062e10
/*  f062e04:	00603025 */ 	or	$a2,$v1,$zero
/*  f062e08:	3068ffff */ 	andi	$t0,$v1,0xffff
/*  f062e0c:	30aa00ff */ 	andi	$t2,$a1,0xff
.NB0f062e10:
/*  f062e10:	0086082a */ 	slt	$at,$a0,$a2
/*  f062e14:	50200004 */ 	beqzl	$at,.NB0f062e28
/*  f062e18:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f062e1c:	3069ffff */ 	andi	$t1,$v1,0xffff
/*  f062e20:	30ab00ff */ 	andi	$t3,$a1,0xff
/*  f062e24:	24a50001 */ 	addiu	$a1,$a1,0x1
.NB0f062e28:
/*  f062e28:	00a7082a */ 	slt	$at,$a1,$a3
/*  f062e2c:	1420fff1 */ 	bnez	$at,.NB0f062df4
/*  f062e30:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f062e34:	24087fff */ 	addiu	$t0,$zero,0x7fff
/*  f062e38:	00004825 */ 	or	$t1,$zero,$zero
/*  f062e3c:	2403001c */ 	addiu	$v1,$zero,0x1c
.NB0f062e40:
/*  f062e40:	01630019 */ 	multu	$t3,$v1
/*  f062e44:	0000c012 */ 	mflo	$t8
/*  f062e48:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f062e4c:	972e0362 */ 	lhu	$t6,0x362($t9)
/*  f062e50:	01430019 */ 	multu	$t2,$v1
/*  f062e54:	00006812 */ 	mflo	$t5
/*  f062e58:	022d7821 */ 	addu	$t7,$s1,$t5
/*  f062e5c:	95f80362 */ 	lhu	$t8,0x362($t7)
/*  f062e60:	01d82823 */ 	subu	$a1,$t6,$t8
/*  f062e64:	0005c843 */ 	sra	$t9,$a1,0x1
/*  f062e68:	1320001d */ 	beqz	$t9,.NB0f062ee0
/*  f062e6c:	03202825 */ 	or	$a1,$t9,$zero
/*  f062e70:	8e30033c */ 	lw	$s0,0x33c($s1)
/*  f062e74:	8e2d0354 */ 	lw	$t5,0x354($s1)
/*  f062e78:	01601025 */ 	or	$v0,$t3,$zero
/*  f062e7c:	520d0019 */ 	beql	$s0,$t5,.NB0f062ee4
/*  f062e80:	318a00ff */ 	andi	$t2,$t4,0xff
/*  f062e84:	920f003d */ 	lbu	$t7,0x3d($s0)
.NB0f062e88:
/*  f062e88:	544f0010 */ 	bnel	$v0,$t7,.NB0f062ecc
/*  f062e8c:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f062e90:	8e0e003c */ 	lw	$t6,0x3c($s0)
/*  f062e94:	000ec640 */ 	sll	$t8,$t6,0x19
/*  f062e98:	0018cfc2 */ 	srl	$t9,$t8,0x1f
/*  f062e9c:	56b9000b */ 	bnel	$s5,$t9,.NB0f062ecc
/*  f062ea0:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f062ea4:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f062ea8:	568d0008 */ 	bnel	$s4,$t5,.NB0f062ecc
/*  f062eac:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f062eb0:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f062eb4:	14a00004 */ 	bnez	$a1,.NB0f062ec8
/*  f062eb8:	a20a003d */ 	sb	$t2,0x3d($s0)
/*  f062ebc:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f062ec0:	10000007 */ 	beqz	$zero,.NB0f062ee0
/*  f062ec4:	01803825 */ 	or	$a3,$t4,$zero
.NB0f062ec8:
/*  f062ec8:	8e100020 */ 	lw	$s0,0x20($s0)
.NB0f062ecc:
/*  f062ecc:	8e2f0354 */ 	lw	$t7,0x354($s1)
/*  f062ed0:	560fffed */ 	bnel	$s0,$t7,.NB0f062e88
/*  f062ed4:	920f003d */ 	lbu	$t7,0x3d($s0)
/*  f062ed8:	922c0358 */ 	lbu	$t4,0x358($s1)
/*  f062edc:	01803825 */ 	or	$a3,$t4,$zero
.NB0f062ee0:
/*  f062ee0:	318a00ff */ 	andi	$t2,$t4,0xff
.NB0f062ee4:
/*  f062ee4:	318b00ff */ 	andi	$t3,$t4,0xff
/*  f062ee8:	18e00014 */ 	blez	$a3,.NB0f062f3c
/*  f062eec:	00002825 */ 	or	$a1,$zero,$zero
/*  f062ef0:	3c02800a */ 	lui	$v0,0x800a
/*  f062ef4:	2442e6c0 */ 	addiu	$v0,$v0,-6464
.NB0f062ef8:
/*  f062ef8:	94430366 */ 	lhu	$v1,0x366($v0)
/*  f062efc:	01202025 */ 	or	$a0,$t1,$zero
/*  f062f00:	0068082a */ 	slt	$at,$v1,$t0
/*  f062f04:	10200003 */ 	beqz	$at,.NB0f062f14
/*  f062f08:	00603025 */ 	or	$a2,$v1,$zero
/*  f062f0c:	3068ffff */ 	andi	$t0,$v1,0xffff
/*  f062f10:	30aa00ff */ 	andi	$t2,$a1,0xff
.NB0f062f14:
/*  f062f14:	0086082a */ 	slt	$at,$a0,$a2
/*  f062f18:	50200004 */ 	beqzl	$at,.NB0f062f2c
/*  f062f1c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f062f20:	3069ffff */ 	andi	$t1,$v1,0xffff
/*  f062f24:	30ab00ff */ 	andi	$t3,$a1,0xff
/*  f062f28:	24a50001 */ 	addiu	$a1,$a1,0x1
.NB0f062f2c:
/*  f062f2c:	00a7082a */ 	slt	$at,$a1,$a3
/*  f062f30:	1420fff1 */ 	bnez	$at,.NB0f062ef8
/*  f062f34:	2442001c */ 	addiu	$v0,$v0,0x1c
/*  f062f38:	2403001c */ 	addiu	$v1,$zero,0x1c
.NB0f062f3c:
/*  f062f3c:	01630019 */ 	multu	$t3,$v1
/*  f062f40:	00007012 */ 	mflo	$t6
/*  f062f44:	022ec021 */ 	addu	$t8,$s1,$t6
/*  f062f48:	97190366 */ 	lhu	$t9,0x366($t8)
/*  f062f4c:	01430019 */ 	multu	$t2,$v1
/*  f062f50:	00006812 */ 	mflo	$t5
/*  f062f54:	022d7821 */ 	addu	$t7,$s1,$t5
/*  f062f58:	95ee0366 */ 	lhu	$t6,0x366($t7)
/*  f062f5c:	032e2823 */ 	subu	$a1,$t9,$t6
/*  f062f60:	0005c043 */ 	sra	$t8,$a1,0x1
/*  f062f64:	13000017 */ 	beqz	$t8,.NB0f062fc4
/*  f062f68:	03002825 */ 	or	$a1,$t8,$zero
/*  f062f6c:	8e30033c */ 	lw	$s0,0x33c($s1)
/*  f062f70:	8e2d0354 */ 	lw	$t5,0x354($s1)
/*  f062f74:	01601025 */ 	or	$v0,$t3,$zero
/*  f062f78:	520d0013 */ 	beql	$s0,$t5,.NB0f062fc8
/*  f062f7c:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f062f80:	920f003d */ 	lbu	$t7,0x3d($s0)
.NB0f062f84:
/*  f062f84:	544f000c */ 	bnel	$v0,$t7,.NB0f062fb8
/*  f062f88:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f062f8c:	8e19003c */ 	lw	$t9,0x3c($s0)
/*  f062f90:	0019c640 */ 	sll	$t8,$t9,0x19
/*  f062f94:	07020008 */ 	bltzl	$t8,.NB0f062fb8
/*  f062f98:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f062f9c:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f062fa0:	568d0005 */ 	bnel	$s4,$t5,.NB0f062fb8
/*  f062fa4:	8e100020 */ 	lw	$s0,0x20($s0)
/*  f062fa8:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f062fac:	10a00005 */ 	beqz	$a1,.NB0f062fc4
/*  f062fb0:	a20a003d */ 	sb	$t2,0x3d($s0)
/*  f062fb4:	8e100020 */ 	lw	$s0,0x20($s0)
.NB0f062fb8:
/*  f062fb8:	8e2f0354 */ 	lw	$t7,0x354($s1)
/*  f062fbc:	560ffff1 */ 	bnel	$s0,$t7,.NB0f062f84
/*  f062fc0:	920f003d */ 	lbu	$t7,0x3d($s0)
.NB0f062fc4:
/*  f062fc4:	8fb9008c */ 	lw	$t9,0x8c($sp)
.NB0f062fc8:
/*  f062fc8:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f062fcc:	c7a80084 */ 	lwc1	$f8,0x84($sp)
/*  f062fd0:	c7aa0080 */ 	lwc1	$f10,0x80($sp)
/*  f062fd4:	8faa0034 */ 	lw	$t2,0x34($sp)
/*  f062fd8:	ae390034 */ 	sw	$t9,0x34($s1)
/*  f062fdc:	ae2e0038 */ 	sw	$t6,0x38($s1)
/*  f062fe0:	e6280044 */ 	swc1	$f8,0x44($s1)
/*  f062fe4:	e62a004c */ 	swc1	$f10,0x4c($s1)
/*  f062fe8:	8fad0098 */ 	lw	$t5,0x98($sp)
/*  f062fec:	ad400370 */ 	sw	$zero,0x370($t2)
/*  f062ff0:	9638035c */ 	lhu	$t8,0x35c($s1)
/*  f062ff4:	11a00007 */ 	beqz	$t5,.NB0f063014
/*  f062ff8:	a5580378 */ 	sh	$t8,0x378($t2)
/*  f062ffc:	0fc23cf3 */ 	jal	alarmTick
/*  f063000:	00000000 */ 	sll	$zero,$zero,0x0
/*  f063004:	0fc2468f */ 	jal	func0f093508
/*  f063008:	00000000 */ 	sll	$zero,$zero,0x0
/*  f06300c:	0fc194af */ 	jal	func0f066054
/*  f063010:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f063014:
/*  f063014:	0fc09052 */ 	jal	func0f02472c
/*  f063018:	00000000 */ 	sll	$zero,$zero,0x0
/*  f06301c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f063020:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f063024:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f063028:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f06302c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f063030:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f063034:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f063038:	03e00008 */ 	jr	$ra
/*  f06303c:	27bd0098 */ 	addiu	$sp,$sp,0x98
);
#endif

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

void propSetCollisionsEnabled(struct prop *prop, s32 enable)
{
	if (prop->type == PROPTYPE_CHR) {
		chrSetOrUnsetHiddenFlag00000100(prop->chr, enable);
	} else if (prop->type == PROPTYPE_PLAYER) {
		func0f0c1e54(prop, enable);
	} else if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_DOOR || prop->type == PROPTYPE_WEAPON) {
		propObjSetOrUnsetHiddenFlag00400000(prop, enable);
	}
}

#if VERSION >= VERSION_NTSC_1_0
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
/*  f064284:	0fc5916a */ 	jal	roomGetNeighbours
/*  f064288:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f06428c:	02202025 */ 	or	$a0,$s1,$zero
/*  f064290:	02602825 */ 	or	$a1,$s3,$zero
/*  f064294:	0fc195f6 */ 	jal	roomsAppend
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
#else
GLOBAL_ASM(
glabel func0f0641f4
.late_rodata
glabel var7f1a9f30
.word func0f0641f4+0x138
glabel var7f1a9f34
.word func0f0641f4+0x154
glabel var7f1a9f38
.word func0f0641f4+0x154
glabel var7f1a9f3c
.word func0f0641f4+0x148
glabel var7f1a9f40
.word func0f0641f4+0x154
glabel var7f1a9f44
.word func0f0641f4+0x154
glabel var7f1a9f48
.word func0f0641f4+0x154
glabel var7f1a9f4c
.word func0f0641f4+0x154
.text
/*  f063468:	27bdfd70 */ 	addiu	$sp,$sp,-656
/*  f06346c:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f063470:	3c14800a */ 	lui	$s4,0x800a
/*  f063474:	2694e6c0 */ 	addiu	$s4,$s4,-6464
/*  f063478:	8e820284 */ 	lw	$v0,0x284($s4)
/*  f06347c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f063480:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f063484:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f063488:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f06348c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f063490:	8c4e01b0 */ 	lw	$t6,0x1b0($v0)
/*  f063494:	24010005 */ 	addiu	$at,$zero,0x5
/*  f063498:	3c0f8007 */ 	lui	$t7,0x8007
/*  f06349c:	51c1004e */ 	beql	$t6,$at,.NB0f0635d8
/*  f0634a0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0634a4:	8def2e20 */ 	lw	$t7,0x2e20($t7)
/*  f0634a8:	55e0004b */ 	bnezl	$t7,.NB0f0635d8
/*  f0634ac:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0634b0:	8e9802a8 */ 	lw	$t8,0x2a8($s4)
/*  f0634b4:	27b3005c */ 	addiu	$s3,$sp,0x5c
/*  f0634b8:	53020047 */ 	beql	$t8,$v0,.NB0f0635d8
/*  f0634bc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0634c0:	8c4400bc */ 	lw	$a0,0xbc($v0)
/*  f0634c4:	02602825 */ 	or	$a1,$s3,$zero
/*  f0634c8:	0fc19283 */ 	jal	roomsCopy
/*  f0634cc:	24840028 */ 	addiu	$a0,$a0,0x28
/*  f0634d0:	8e990284 */ 	lw	$t9,0x284($s4)
/*  f0634d4:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f0634d8:	00008025 */ 	or	$s0,$zero,$zero
/*  f0634dc:	8f2200bc */ 	lw	$v0,0xbc($t9)
/*  f0634e0:	27b10044 */ 	addiu	$s1,$sp,0x44
/*  f0634e4:	84480028 */ 	lh	$t0,0x28($v0)
/*  f0634e8:	52480011 */ 	beql	$s2,$t0,.NB0f063530
/*  f0634ec:	27b00088 */ 	addiu	$s0,$sp,0x88
/*  f0634f0:	84440028 */ 	lh	$a0,0x28($v0)
/*  f0634f4:	02202825 */ 	or	$a1,$s1,$zero
.NB0f0634f8:
/*  f0634f8:	0fc57b6a */ 	jal	roomGetNeighbours
/*  f0634fc:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f063500:	02202025 */ 	or	$a0,$s1,$zero
/*  f063504:	02602825 */ 	or	$a1,$s3,$zero
/*  f063508:	0fc19290 */ 	jal	roomsAppend
/*  f06350c:	24060014 */ 	addiu	$a2,$zero,0x14
/*  f063510:	8e890284 */ 	lw	$t1,0x284($s4)
/*  f063514:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f063518:	8d2a00bc */ 	lw	$t2,0xbc($t1)
/*  f06351c:	01505821 */ 	addu	$t3,$t2,$s0
/*  f063520:	85640028 */ 	lh	$a0,0x28($t3)
/*  f063524:	5644fff4 */ 	bnel	$s2,$a0,.NB0f0634f8
/*  f063528:	02202825 */ 	or	$a1,$s1,$zero
/*  f06352c:	27b00088 */ 	addiu	$s0,$sp,0x88
.NB0f063530:
/*  f063530:	02002825 */ 	or	$a1,$s0,$zero
/*  f063534:	02602025 */ 	or	$a0,$s3,$zero
/*  f063538:	0fc1947a */ 	jal	roomGetProps
/*  f06353c:	24060100 */ 	addiu	$a2,$zero,0x100
/*  f063540:	87ac0088 */ 	lh	$t4,0x88($sp)
/*  f063544:	02008825 */ 	or	$s1,$s0,$zero
/*  f063548:	27ad0088 */ 	addiu	$t5,$sp,0x88
/*  f06354c:	05800021 */ 	bltz	$t4,.NB0f0635d4
/*  f063550:	24120048 */ 	addiu	$s2,$zero,0x48
/*  f063554:	85a20000 */ 	lh	$v0,0x0($t5)
.NB0f063558:
/*  f063558:	00520019 */ 	multu	$v0,$s2
/*  f06355c:	8e8f0338 */ 	lw	$t7,0x338($s4)
/*  f063560:	00002825 */ 	or	$a1,$zero,$zero
/*  f063564:	00007012 */ 	mflo	$t6
/*  f063568:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f06356c:	86180002 */ 	lh	$t8,0x2($s0)
/*  f063570:	1f000012 */ 	bgtz	$t8,.NB0f0635bc
/*  f063574:	00000000 */ 	sll	$zero,$zero,0x0
/*  f063578:	92190000 */ 	lbu	$t9,0x0($s0)
/*  f06357c:	2728ffff */ 	addiu	$t0,$t9,-1
/*  f063580:	2d010008 */ 	sltiu	$at,$t0,0x8
/*  f063584:	1020000d */ 	beqz	$at,.NB0f0635bc
/*  f063588:	00084080 */ 	sll	$t0,$t0,0x2
/*  f06358c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f063590:	00280821 */ 	addu	$at,$at,$t0
/*  f063594:	8c284250 */ 	lw	$t0,0x4250($at)
/*  f063598:	01000008 */ 	jr	$t0
/*  f06359c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0635a0:	0fc21e1c */ 	jal	func0f089014
/*  f0635a4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0635a8:	10000004 */ 	beqz	$zero,.NB0f0635bc
/*  f0635ac:	00402825 */ 	or	$a1,$v0,$zero
/*  f0635b0:	0fc228d9 */ 	jal	func0f08bb3c
/*  f0635b4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0635b8:	00402825 */ 	or	$a1,$v0,$zero
.NB0f0635bc:
/*  f0635bc:	0fc1877a */ 	jal	func0f062b64
/*  f0635c0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0635c4:	86220002 */ 	lh	$v0,0x2($s1)
/*  f0635c8:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f0635cc:	0441ffe2 */ 	bgez	$v0,.NB0f063558
/*  f0635d0:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0635d4:
/*  f0635d4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.NB0f0635d8:
/*  f0635d8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0635dc:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0635e0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0635e4:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0635e8:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0635ec:	03e00008 */ 	jr	$ra
/*  f0635f0:	27bd0290 */ 	addiu	$sp,$sp,0x290
);
#endif

f32 func0f06438c(struct prop *prop, struct coord *arg1, f32 *arg2, f32 *arg3, f32 *arg4, s32 arg5, bool cangangsta, s32 arg7)
{
	f32 spa0[2];
	struct coord sp94;
	f32 sp8c[2];
	f32 sp84[2];
	f32 sp7c[2];
	f32 sp74[2];
	f32 sp70;
	f32 sp6c;
	f32 top;
	f32 bottom;
	f32 left;
	f32 right;
	f32 result = -2;
	struct weaponfunc *func = currentPlayerGetWeaponFunction(HAND_RIGHT);
	bool sp50 = arg7;
	bool sp4c;
	f32 sp48;
	struct prop *playerprop;
	s32 lVar3;

	if (func && func0f0a27c8()) {
		sp50 = true;
	}

	if (sp50) {
		top = currentPlayerGetScreenTop();
		bottom = currentPlayerGetScreenTop() + currentPlayerGetScreenHeight();
		left = currentPlayerGetScreenLeft();
		right = currentPlayerGetScreenLeft() + currentPlayerGetScreenWidth();
	} else {
		top = currentPlayerGetScreenTop() + currentPlayerGetScreenHeight() * 0.175f;
		bottom = currentPlayerGetScreenTop() + currentPlayerGetScreenHeight() * 0.825f;
		left = currentPlayerGetScreenLeft() + currentPlayerGetScreenWidth() * 0.25f;
		right = currentPlayerGetScreenLeft() + currentPlayerGetScreenWidth() * 0.75f;
	}

	if (arg1->z > -2.5f) {
		return -1;
	}

	func0f0b4d04(arg1, spa0);
	sp94.x = arg2[0];
	sp94.y = arg1->y;
	sp94.z = arg1->z;
	func0f0b4d04(&sp94, sp8c);
	sp94.x = arg2[1];
	sp94.y = arg1->y;
	sp94.z = arg1->z;
	func0f0b4d04(&sp94, sp84);
	sp94.x = arg1->x;
	sp94.y = arg3[1];
	sp94.z = arg1->z;
	func0f0b4d04(&sp94, sp7c);
	sp94.x = arg1->x;
	sp94.y = arg3[0];
	sp94.z = arg1->z;
	func0f0b4d04(&sp94, sp74);

	if (sp74[1] >= top && bottom >= sp7c[1]) {
		sp4c = false;
		currentPlayerGetCrossPos(&sp70, &sp6c);
		sp8c[0] = floorf(sp8c[0]);
		sp84[0] = ceilf(sp84[0]);

		if (bmoveIsAutoAimXEnabledForCurrentWeapon() || cangangsta) {
			if (sp8c[0] <= right && left <= sp84[0]) {
				sp48 = (sp84[0] - sp8c[0]) * 1.5f;

				if (!g_Vars.normmplayerisrunning) {
					sp48 = sp48 * var80069880;
				}

				sp4c = currentPlayerGetScreenLeft() + 0.5f * currentPlayerGetScreenWidth() >= (sp8c[0] + sp84[0]) * 0.5f - sp48
					&& currentPlayerGetScreenLeft() + 0.5f * currentPlayerGetScreenWidth() <= (sp8c[0] + sp84[0]) * 0.5f + sp48
					&& left <= spa0[0]
					&& right >= spa0[0];
			}
		} else {
			sp4c = sp8c[0] <= sp70 && sp70 <= sp84[0];
		}

		if (sp4c) {
			playerprop = g_Vars.currentplayer->prop;

			func0f0c1e54(playerprop, false);

			if (arg5) {
				lVar3 = func0002db98(&playerprop->pos, playerprop->rooms, &prop->pos, 0x32, 16);
			} else {
				lVar3 = func0002db98(&playerprop->pos, playerprop->rooms, &prop->pos, 0x33, 16);
			}

			if (lVar3) {
				f32 value = spa0[1];

				if (value < top) {
					value = top;
				} else if (value > bottom) {
					value = bottom;
				}

				arg4[1] = value;

				if (bmoveIsAutoAimXEnabledForCurrentWeapon() || cangangsta) {
					f32 value = spa0[0];

					if (value < left) {
						value = left;
					} else if (value > right) {
						value = right;
					}

					arg4[0] = value;
				}

				if (currentPlayerGetScreenLeft() + 0.5f * currentPlayerGetScreenWidth() >= sp8c[0]
						&& currentPlayerGetScreenLeft() + 0.5f * currentPlayerGetScreenWidth() <= sp84[0]) {
					result = 1;
				} else if (currentPlayerGetScreenLeft() + 0.5f * currentPlayerGetScreenWidth() >= sp8c[0]) {
					result = 1 - ((currentPlayerGetScreenLeft() + 0.5f * currentPlayerGetScreenWidth()) - sp84[0]) / sp48;
				} else {
					result = 1 - (sp8c[0] - (currentPlayerGetScreenLeft() + 0.5f * currentPlayerGetScreenWidth())) / sp48;
				}
			}

			func0f0c1e54(playerprop, true);
		}
	}

	return result;
}

void farsightChooseTarget(void)
{
	struct prop *besttarget = NULL;
	f32 bestthing = 1;
	f32 bestdist = -1;
	s32 weaponnum = handGetWeaponNum(HAND_RIGHT);
	s32 i;

	if (weaponnum == WEAPON_FARSIGHT) {
		s32 numchrs = getNumChrSlots();

		for (i = numchrs - 1; i >= 0; i--) {
			struct prop *prop = g_ChrSlots[i].prop;

			if (prop && prop->chr) {
				if (prop->type == PROPTYPE_CHR && (prop->flags & PROPFLAG_TANGIBLE)
						|| (prop->type == PROPTYPE_PLAYER && propGetPlayerNum(prop) != g_Vars.currentplayernum)) {
					struct chrdata *chr = prop->chr;

					if ((chr->chrflags & CHRCFLAG_UNEXPLODABLE) == 0
							&& !chrCompareTeams(g_Vars.currentplayer->prop->chr, chr, COMPARE_FRIENDS)
							&& chr->actiontype != ACT_DIE
							&& chr->actiontype != ACT_DRUGGEDDROP
							&& chr->actiontype != ACT_DRUGGEDKO
							&& chr->actiontype != ACT_DEAD
							&& (chr->hidden & CHRHFLAG_CLOAKED) == 0
							&& (prop->type != PROPTYPE_PLAYER || !g_Vars.players[propGetPlayerNum(prop)]->isdead)) {
						f32 xdist = g_Vars.currentplayer->bond2.unk10.x - prop->pos.x;
						f32 ydist = g_Vars.currentplayer->bond2.unk10.y - prop->pos.y;
						f32 zdist = g_Vars.currentplayer->bond2.unk10.z - prop->pos.z;

						f32 dist = sqrtf(xdist * xdist + ydist * ydist + zdist * zdist);

						if (dist > 0) {
							f32 thing = (xdist * g_Vars.currentplayer->bond2.unk1c.f[0]
									+ ydist * g_Vars.currentplayer->bond2.unk1c.f[1]
									+ zdist * g_Vars.currentplayer->bond2.unk1c.f[2]) / dist;

							if (thing < 0 && thing < bestthing) {
								bestthing = thing;
								besttarget = prop;
								bestdist = dist;
							}
						}
					}
				}
			}
		}
	}

	g_Vars.currentplayer->autoeraserdist = bestdist;
	g_Vars.currentplayer->autoerasertarget = besttarget;
}

void autoaimTick(void)
{
	struct prop *bestprop = NULL;
	f32 aimpos[2] = {0, 0};
	bool isclose = false;
	bool cangangsta = weaponHasFlag(handGetWeaponNum(HAND_RIGHT), WEAPONFLAG_GANGSTA);
	bool iscmpsec = false;
	struct weaponfunc *func = currentPlayerGetWeaponFunction(HAND_RIGHT);
	s32 i;

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_CLOSE) {
		isclose = true;
	}

	if (frIsInTraining()) {
		if (!frChooseFarsightTarget()) {
			farsightChooseTarget();
		}
	} else {
		farsightChooseTarget();
	}

	if (handGetWeaponNum(HAND_RIGHT) == WEAPON_CMP150
			&& g_Vars.currentplayer->hands[HAND_RIGHT].base.weaponfunc == FUNC_SECONDARY) {
		iscmpsec = true;
	}

	if (iscmpsec) {
		// For CMP on secondary mode, find the first prop that is within the aim limits
		for (i = 0; i < ARRAYCOUNT(g_Vars.currentplayer->cmpfollowprops); i++) {
			struct threat *threat = &g_Vars.currentplayer->cmpfollowprops[i];

			if (threat->prop
					&& (threat->x1 >= 0 || threat->x2 >= 0)
					&& (threat->y1 >= 0 || threat->y2 >= 0)) {
				// Define the aim limits
				f32 top = currentPlayerGetScreenTop() + currentPlayerGetScreenHeight() * 0.125f;
				f32 bottom = currentPlayerGetScreenTop() + currentPlayerGetScreenHeight() * 0.875f;
				f32 left = currentPlayerGetScreenLeft() + currentPlayerGetScreenWidth() * 0.125f;
				f32 right = currentPlayerGetScreenLeft() + currentPlayerGetScreenWidth() * 0.875f;
				struct chrdata *chr = NULL;

				bestprop = threat->prop;

				if (bestprop->type == PROPTYPE_OBJ
						|| bestprop->type == PROPTYPE_WEAPON
						|| bestprop->type == PROPTYPE_DOOR) {
					// Threat is an object
					aimpos[0] = (threat->x2 + threat->x1) / 2;
					aimpos[1] = (threat->y2 + threat->y1) / 2;

					if (bestprop->flags & PROPFLAG_02) {
						struct defaultobj *obj = bestprop->obj;
						Mtxf *mtx = func0001a60c(obj->model);
						struct coord spac;
						spac.z = mtx->m[3][2];

						if (spac.z < 0) {
							spac.x = mtx->m[3][0];
							spac.y = mtx->m[3][1];
							func0f0b4d04(&spac, aimpos);
						}
					}
				} else {
					// Threat is a chr
					chr = bestprop->chr;
					aimpos[0] = (threat->x2 + threat->x1) / 2;

					if (chr && chr->race == RACE_EYESPY) {
						aimpos[1] = (threat->y2 + threat->y1) >> 1;
					} else {
						// Aim 2/3 up the chr, so about their chest
						aimpos[1] = (threat->y2 + threat->y1 * 2) / 3;
					}
				}

				// Constrain aimpos to the aim limits
				if (aimpos[0] > right) {
					aimpos[0] = right;
				}

				if (aimpos[0] < left) {
					aimpos[0] = left;
				}

				if (aimpos[1] > bottom) {
					aimpos[1] = bottom;
				}

				if (aimpos[1] < top) {
					aimpos[1] = top;
				}

				// Don't use this prop if it's an uninitialised eyespy, or if
				// the threat is outside of the aim limits
				if (chr && chr->race == RACE_EYESPY) {
					struct eyespy *eyespy = chrToEyespy(chr);

					if (eyespy == NULL || !eyespy->initialised) {
						bestprop = NULL;
						aimpos[0] = aimpos[1] = 0;
					}
				} else if (aimpos[0] > threat->x2
						|| aimpos[0] < threat->x1
						|| aimpos[1] > threat->y2
						|| aimpos[1] < threat->y1) {
					bestprop = NULL;
					aimpos[0] = aimpos[1] = 0;
				}
			}

			if (bestprop) {
				break;
			}
		}
	} else if ((bmoveIsAutoAimYEnabledForCurrentWeapon()
				|| bmoveIsAutoAimXEnabledForCurrentWeapon()
				|| cangangsta) && !isclose) {
		// Standard auto aim
		f32 bestthing = -1;
		struct prop *prop;
		struct coord sp94;
		f32 sp8c[2];
		f32 sp84[2];
		struct chrdata *chr;
		f32 sp78[2];
		struct prop **ptr = g_Vars.unk00034c - 1;

		// Iterate tangible list in reverse
		while (ptr >= g_Vars.tangibleprops) {
			prop = *ptr;

			if (prop && prop->chr) {
				if (prop->type == PROPTYPE_CHR
						|| (prop->type == PROPTYPE_PLAYER && propGetPlayerNum(prop) != g_Vars.currentplayernum)) {
					chr = prop->chr;

					if (!chrCompareTeams(g_Vars.currentplayer->prop->chr, chr, COMPARE_FRIENDS)
							&& (chrGetEquippedWeaponProp(chr, HAND_RIGHT)
								|| chrGetEquippedWeaponProp(chr, HAND_LEFT)
								|| (chr->chrflags & CHRCFLAG_FORCEAUTOAIM)
								|| chr->gunprop)
							&& func0f028a50(prop, &sp94, sp8c, sp84)) {
						f32 thing = func0f06438c(prop, &sp94, sp8c, sp84, sp78, 0, cangangsta, 0);

						if (thing > bestthing) {
							bestthing = thing;
							aimpos[0] = sp78[0];
							aimpos[1] = sp78[1];
							bestprop = prop;

							if (thing >= 1) {
								break;
							}
						}
					}
				}
			}

			ptr--;
		}
	}

	if (bestprop) {
		if (bmoveIsAutoAimYEnabledForCurrentWeapon() || iscmpsec) {
			bmoveUpdateAutoAimYProp(bestprop, (aimpos[1] - currentPlayerGetScreenTop()) / (currentPlayerGetScreenHeight() * 0.5f) - 1);
		}

		if (bmoveIsAutoAimXEnabledForCurrentWeapon() || iscmpsec) {
			bmoveUpdateAutoAimXProp(bestprop, (aimpos[0] - currentPlayerGetScreenLeft()) / (currentPlayerGetScreenWidth() * 0.5f) - 1);
		}

		if (cangangsta) {
			f32 xdist = g_Vars.currentplayer->bond2.unk10.x - bestprop->pos.x;
			f32 ydist = g_Vars.currentplayer->bond2.unk10.y - bestprop->pos.y;
			f32 zdist = g_Vars.currentplayer->bond2.unk10.z - bestprop->pos.z;
			f32 dist = sqrtf(xdist * xdist + ydist * ydist + zdist * zdist);

			if (dist < 200) {
				g_Vars.currentplayer->gunctrl.gangsta = true;
			} else {
				g_Vars.currentplayer->gunctrl.gangsta = false;
			}
		} else {
			g_Vars.currentplayer->gunctrl.gangsta = false;
		}
	} else {
		u32 stack;
		bmoveUpdateAutoAimYProp(NULL, 0);
		bmoveUpdateAutoAimXProp(NULL, 0);

		g_Vars.currentplayer->gunctrl.gangsta = false;
	}
}

u32 propDoorGetCdTypes(struct prop *prop)
{
	struct doorobj *door = prop->door;
	u32 types;

	if (door->frac <= 0) {
		types = CDTYPE_CLOSEDDOORS;
	} else if (door->frac >= door->maxfrac) {
		types = CDTYPE_OPENDOORS;
	} else {
		types = CDTYPE_AJARDOORS;
	}

	if (door->base.flags2 & OBJFLAG2_AICANNOTUSE) {
		types |= CDTYPE_DOORSLOCKEDTOAI;
	}

	return types;
}

bool propIsOfCdType(struct prop *prop, u32 types)
{
	bool result = true;

	if (prop->type == PROPTYPE_DOOR) {
		if (types & CDTYPE_OBJSWITHOUTFLAG) {
			struct defaultobj *obj = prop->obj;

			if (obj->flags & OBJFLAG_04000000) {
				result = false;
			}
		}

		if (types & CDTYPE_DOORSWITHOUTFLAG) {
			struct defaultobj *obj = prop->obj;

			if (obj->flags3 & OBJFLAG3_80000000) {
				result = false;
			}
		}

		if ((types & CDTYPE_DOORS) == 0) {
			if ((propDoorGetCdTypes(prop) & types) == 0) {
				result = false;
			}
		}
	} else if (prop->type == PROPTYPE_PLAYER) {
		if ((types & CDTYPE_PLAYERS) == 0) {
			result = false;
		} else {
			struct player *player = g_Vars.players[propGetPlayerNum(prop)];

			if (!player->bondperimenabled || (g_Vars.mplayerisrunning && player->isdead)) {
				result = false;
			}
		}
	} else if (prop->type == PROPTYPE_CHR) {
		if ((types & CDTYPE_CHRS) == 0) {
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

		if (obj->unkgeo == NULL) {
			result = false;
		} else {
			if ((types & CDTYPE_OBJSWITHOUTFLAG) && (obj->flags & OBJFLAG_04000000)) {
				result = false;
			}

			if ((types & CDTYPE_OBJSWITHFLAG)
					&& (obj->flags & OBJFLAG_INVINCIBLE) == 0
					&& (obj->flags2 & OBJFLAG2_00004000) == 0) {
				result = false;
			}

			if ((types & CDTYPE_OBJSWITHFLAG2)
					&& (obj->flags & OBJFLAG_INVINCIBLE) == 0
					&& (obj->flags2 & OBJFLAG2_00200000) == 0) {
				result = false;
			}

			if ((types & CDTYPE_OBJSNOTSAFEORHELI)
					&& (obj->type == OBJTYPE_SAFE || obj->type == OBJTYPE_HELI)) {
				result = false;
			}

			if ((obj->flags & OBJFLAG_00000800)) {
				if ((types & CDTYPE_10) == 0) {
					result = false;
				}
			} else {
				if ((types & CDTYPE_OBJS) == 0) {
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
glabel roomsAppend
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
/*  f065d7c:	0fc586b7 */ 	jal	roomContainsCoord
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
			roomsAppend(newrooms, morerooms, arg5);
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

bool propUpdateGeometry(struct prop *prop, u8 **start, u8 **end)
{
	bool result = false;

	if (prop->type == PROPTYPE_PLAYER) {
		result = playerUpdateGeometry(prop, start, end);
	} else if (prop->type == PROPTYPE_CHR) {
		result = chrUpdateGeometry(prop, start, end);
	} else if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_DOOR) {
		result = objUpdateGeometry(prop, start, end);
	}

	return result;
}
