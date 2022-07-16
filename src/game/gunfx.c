#include <ultra64.h>
#include "constants.h"
#include "game/acosfasinf.h"
#include "game/bondgun.h"
#include "game/gunfx.h"
#include "game/game_0b0fd0.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/game_0c33f0.h"
#include "game/gfxmemory.h"
#include "game/file.h"
#include "bss.h"
#include "lib/main.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

#define BOLTBEAMTICKMODE_MANUAL    0
#define BOLTBEAMTICKMODE_AUTOMATIC 1

const u32 var7f1acc10[] = {0x73703100};
const u32 var7f1acc14[] = {0x73703200};
const u32 var7f1acc18[] = {0x73703300};
const u32 var7f1acc1c[] = {0x73706200};
const u32 var7f1acc20[] = {0x73706900};

struct casing g_Casings[20];
struct boltbeam g_BoltBeams[8];
struct lasersight g_LaserSights[4];

void beamCreate(struct beam *beam, s32 weaponnum, struct coord *from, struct coord *to)
{
	f32 distance;

	beam->from.x = from->x;
	beam->from.y = from->y;
	beam->from.z = from->z;

	beam->dir.x = to->x - from->x;
	beam->dir.y = to->y - from->y;
	beam->dir.z = to->z - from->z;

	distance = sqrtf(beam->dir.f[0] * beam->dir.f[0] + beam->dir.f[1] * beam->dir.f[1] + beam->dir.f[2] * beam->dir.f[2]);

	if (distance > 0) {
		beam->dir.x *= 1.0f / distance;
		beam->dir.y *= 1.0f / distance;
		beam->dir.z *= 1.0f / distance;
	}

	if (distance > 10000) {
		distance = 10000;
	}

	beam->age = 0;
	beam->weaponnum = weaponnum;
	beam->maxdist = distance;

	if (distance < 500) {
		distance = 500;
	}

	if (weaponnum == -1) {
		beam->speed = 0;
		beam->mindist = distance;

		if (beam->mindist > 3000) {
			beam->mindist = 3000;
		}

		beam->dist = 0;
	} else if (weaponnum == WEAPON_LASER || weaponnum == WEAPON_WATCHLASER) {
		beam->speed = 0.25f * distance;
		beam->mindist = 0.6f * distance;

		if (beam->mindist > 3000) {
			beam->mindist = 3000;
		}

		beam->dist = (-0.1f - RANDOMFRAC() * 0.3f) * distance;
	} else if (weaponnum == -2) {
		beam->speed = 0;
		beam->mindist = distance;

		if (beam->mindist > 3000) {
			beam->mindist = 3000;
		}

		beam->dist = 0;
	} else {
		f32 tmp;
		beam->speed = 0.2f * distance;
		beam->mindist = 0.2f * distance;

		if (beam->mindist > 3000) {
			beam->mindist = 3000;
		}

		tmp = RANDOMFRAC();
		beam->dist = (tmp + tmp - 1) * beam->speed;
	}

	if (beam->dist >= beam->maxdist) {
		beam->age = -1;
	}
}

void beamCreateForHand(s32 handnum)
{
	struct player *player = g_Vars.currentplayer;
	struct hand *hand = player->hands + handnum;
	Mtxf *mtx = camGetWorldToScreenMtxf();
	f32 tmp;

	tmp = hand->hitpos.f[0] * mtx->m[0][2] + hand->hitpos.f[1] * mtx->m[1][2] + hand->hitpos.f[2] * mtx->m[2][2] + mtx->m[3][2];
	tmp = -tmp;

	if (tmp < hand->muzzlez) {
		// empty
	} else {
		struct beam *beam;
		s32 weaponnum = bgunGetWeaponNum(handnum);

		if (hand->gset.weaponnum == WEAPON_LASER && hand->gset.weaponfunc == FUNC_SECONDARY) {
			weaponnum = -2;
		}

		beam = &hand->beam;
		beamCreate(beam, weaponnum, &hand->muzzlepos, &hand->hitpos);

		if (beam->weaponnum == WEAPON_MAULER) {
			beam->weaponnum = -3 - (s32)player->hands[handnum].matmot1;
		}

		if (player->prop->chr && PLAYERCOUNT() >= 2) {
			struct chrdata *chr = player->prop->chr;
			struct coord disttolast;
			struct coord disttocur;
			f32 radians;

			if (chr->fireslots[handnum] == -1) {
				chr->fireslots[handnum] = bgunAllocateFireslot();
			}

			if (chr->fireslots[handnum] != -1) {
				disttolast.x = hand->hitpos.x - player->chrmuzzlelastpos[handnum].x;
				disttolast.y = hand->hitpos.y - player->chrmuzzlelastpos[handnum].y;
				disttolast.z = hand->hitpos.z - player->chrmuzzlelastpos[handnum].z;

				guNormalize(&disttolast.x, &disttolast.y, &disttolast.z);

				disttocur.x = hand->hitpos.x - hand->muzzlepos.x;
				disttocur.y = hand->hitpos.y - hand->muzzlepos.y;
				disttocur.z = hand->hitpos.z - hand->muzzlepos.z;

				guNormalize(&disttocur.x, &disttocur.y, &disttocur.z);

				radians = acosf(disttolast.f[0] * disttocur.f[0] + disttolast.f[1] * disttocur.f[1] + disttolast.f[2] * disttocur.f[2]);

				if (!(radians > 0.08725257f) || weaponnum == -2) {
					beamCreate(&g_Fireslots[chr->fireslots[handnum]].beam, weaponnum, &player->chrmuzzlelastpos[handnum], &hand->hitpos);

					if (g_Fireslots[chr->fireslots[handnum]].beam.weaponnum == WEAPON_MAULER) {
						g_Fireslots[chr->fireslots[handnum]].beam.weaponnum = -3 - (s32)player->hands[handnum].matmot1;
					}
				}
			}
		}
	}
}

Gfx *beamRenderGeneric(Gfx *gdl, struct textureconfig *texconfig,
		f32 arg2, struct coord *headpos, u32 headcolour,
		f32 arg5, struct coord *tailpos, u32 tailcolour)
{
	struct coord spe4;
	f32 length;
	struct gfxvtx *vertices;
	struct coord spd0;
	struct coord *campos = &g_Vars.currentplayer->cam_pos;
	Mtxf *spc8;
	u32 *colours = gfxAllocateColours(2);
	Mtxf sp84;
	Mtxf *worldtoscreenmtx = camGetWorldToScreenMtxf();
	struct coord sp74 = {0, 0, 0};
	f32 mult;
	u32 stack[2];
	struct coord sp5c;

	spe4.f[0] = tailpos->f[0] - headpos->f[0];
	spe4.f[1] = tailpos->f[1] - headpos->f[1];
	spe4.f[2] = tailpos->f[2] - headpos->f[2];

	length = sqrtf(spe4.f[0] * spe4.f[0] + spe4.f[1] * spe4.f[1] + spe4.f[2] * spe4.f[2]);

	if (length < 0.00001f && length > -0.00001f) {
		return gdl;
	}

	spe4.f[0] /= length;
	spe4.f[1] /= length;
	spe4.f[2] /= length;

	mtx4TransformVec(camGetWorldToScreenMtxf(), headpos, &sp5c);

	if (sp5c.f[0] * arg2 > 10000.0f || sp5c.f[0] * arg2 < -10000.0f) {
		return gdl;
	}

	if (sp5c.f[1] * arg2 > 10000.0f || sp5c.f[1] * arg2 < -10000.0f) {
		return gdl;
	}

	if (sp5c.f[2] * arg2 > 10000.0f || sp5c.f[2] * arg2 < -10000.0f) {
		return gdl;
	}

	mtx4TransformVec(camGetWorldToScreenMtxf(), tailpos, &sp5c);

	if (sp5c.f[0] * arg2 > 10000.0f || sp5c.f[0] * arg2 < -10000.0f) {
		return gdl;
	}

	if (sp5c.f[1] * arg2 > 10000.0f || sp5c.f[1] * arg2 < -10000.0f) {
		return gdl;
	}

	if (sp5c.f[2] * arg2 > 10000.0f || sp5c.f[2] * arg2 < -10000.0f) {
		return gdl;
	}

	colours[0] = headcolour;
	colours[1] = tailcolour;

	spd0.f[0] = (spe4.f[1] * (campos->f[2] - (headpos->f[2] + length * spe4.f[2]))) - (spe4.f[2] * (campos->f[1] - (headpos->f[1] + length * spe4.f[1])));
	spd0.f[1] = (spe4.f[2] * (campos->f[0] - (headpos->f[0] + length * spe4.f[0]))) - (spe4.f[0] * (campos->f[2] - (headpos->f[2] + length * spe4.f[2])));
	spd0.f[2] = (spe4.f[0] * (campos->f[1] - (headpos->f[1] + length * spe4.f[1]))) - (spe4.f[1] * (campos->f[0] - (headpos->f[0] + length * spe4.f[0])));

	if (spd0.f[0] != 0.0f || spd0.f[1] != 0.0f || spd0.f[2] != 0.0f) {
		guNormalize(&spd0.f[0], &spd0.f[1], &spd0.f[2]);
	} else {
		spd0.f[0] = 0.0f;
		spd0.f[1] = 1.0f;
		spd0.f[2] = 0.0f;
	}

	vertices = gfxAllocateVertices(4);
	spc8 = gfxAllocateMatrix();

	mtx4LoadTranslation(headpos, &sp84);

	mtx00015f04(1.0f / arg2, &sp84);
	mtx00015be0(worldtoscreenmtx, &sp84);
	mtx00016054(&sp84, spc8);

	mult = arg5 * arg2;

	sp74.f[0] = spe4.f[0] * (length * arg2);
	sp74.f[1] = spe4.f[1] * (length * arg2);
	sp74.f[2] = spe4.f[2] * (length * arg2);

	vertices[0].x = spd0.f[0] * mult;
	vertices[0].y = spd0.f[1] * mult;
	vertices[0].z = spd0.f[2] * mult;
	vertices[0].s = 0;
	vertices[0].t = 0;
	vertices[0].colour = 0;

	vertices[1].x = -spd0.f[0] * mult;
	vertices[1].y = -spd0.f[1] * mult;
	vertices[1].z = -spd0.f[2] * mult;
	vertices[1].s = texconfig->width * 32;
	vertices[1].t = 0;
	vertices[1].colour = 0;

	vertices[2].x = sp74.f[0] - spd0.f[0] * mult;
	vertices[2].y = sp74.f[1] - spd0.f[1] * mult;
	vertices[2].z = sp74.f[2] - spd0.f[2] * mult;
	vertices[2].s = texconfig->width * 32;
	vertices[2].t = texconfig->height * 32;
	vertices[2].colour = 4;

	vertices[3].x = sp74.f[0] + spd0.f[0] * mult;
	vertices[3].y = sp74.f[1] + spd0.f[1] * mult;
	vertices[3].z = sp74.f[2] + spd0.f[2] * mult;
	vertices[3].s = 0;
	vertices[3].t = texconfig->height * 32;
	vertices[3].colour = 4;

	gSPClearGeometryMode(gdl++, G_CULL_BACK);
	gSPMatrix(gdl++, osVirtualToPhysical(spc8), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 2);

	texSelect(&gdl, texconfig, 4, 1, 2, true, NULL);

	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 4);
	gDPTri2(gdl++, 0, 1, 2, 2, 3, 0);

	return gdl;
}

u32 var8007050c = 0x00000000;
u32 var80070510 = 0x00000000;
u32 var80070514 = 0x00000000;
u32 var80070518 = 0x00000000;
u32 var8007051c = 0x00000000;
u32 var80070520 = 0x00000000;

GLOBAL_ASM(
glabel beamRender
.late_rodata
glabel var7f1acc6c
.word 0x3fb50481
glabel jtbl_var7f1acc70
.word .L0f0accc0
.word .L0f0accc0
.word .L0f0acccc
.word .L0f0acccc
.word .L0f0acccc
.word .L0f0acca0
.word .L0f0accc0
.word .L0f0acccc
.word .L0f0acccc
.word .L0f0acccc
.word .L0f0acccc
.word .L0f0acccc
.word .L0f0acccc
.word .L0f0acccc
.word .L0f0accc0
.word .L0f0acccc
.word .L0f0accc0
.word .L0f0acccc
.word .L0f0acccc
.word .L0f0acccc
.word .L0f0acccc
.word .L0f0acccc
.word .L0f0accb0
glabel var7f1acccc
.word 0x3dcccccd
glabel var7f1accd0
.word 0xc6ea6000
glabel var7f1accd4
.word 0x46ea6000
glabel var7f1accd8
.word 0x3f666666
glabel var7f1accdc
.word 0x3f666666
glabel var7f1acce0
.word 0x3f666666
glabel var7f1acce4
.word 0x3f666666
glabel var7f1acce8
.word 0x3f666666
glabel var7f1accec
.word 0x3f666666
glabel var7f1accf0
.word 0x3fb50481
glabel var7f1accf4
.word 0x3f666666
.text
/*  f0acb90:	27bdfe70 */ 	addiu	$sp,$sp,-400
/*  f0acb94:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f0acb98:	30f000ff */ 	andi	$s0,$a3,0xff
/*  f0acb9c:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f0acba0:	2a010005 */ 	slti	$at,$s0,0x5
/*  f0acba4:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0acba8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0acbac:	afa40190 */ 	sw	$a0,0x190($sp)
/*  f0acbb0:	afa60198 */ 	sw	$a2,0x198($sp)
/*  f0acbb4:	102003fb */ 	beqz	$at,.L0f0adba4
/*  f0acbb8:	afa7019c */ 	sw	$a3,0x19c($sp)
/*  f0acbbc:	80ac0000 */ 	lb	$t4,0x0($a1)
/*  f0acbc0:	058203f9 */ 	bltzl	$t4,.L0f0adba8
/*  f0acbc4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0acbc8:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f0acbcc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0acbd0:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x284)
/*  f0acbd4:	8d29a244 */ 	lw	$t1,%lo(g_Vars+0x284)($t1)
/*  f0acbd8:	afa20144 */ 	sw	$v0,0x144($sp)
/*  f0acbdc:	3c0d8007 */ 	lui	$t5,%hi(var8007050c)
/*  f0acbe0:	25381bb0 */ 	addiu	$t8,$t1,0x1bb0
/*  f0acbe4:	afb80134 */ 	sw	$t8,0x134($sp)
/*  f0acbe8:	c6240024 */ 	lwc1	$f4,0x24($s1)
/*  f0acbec:	25ad050c */ 	addiu	$t5,$t5,%lo(var8007050c)
/*  f0acbf0:	27af0100 */ 	addiu	$t7,$sp,0x100
/*  f0acbf4:	e7a4012c */ 	swc1	$f4,0x12c($sp)
/*  f0acbf8:	8da10000 */ 	lw	$at,0x0($t5)
/*  f0acbfc:	c6220028 */ 	lwc1	$f2,0x28($s1)
/*  f0acc00:	8daa0004 */ 	lw	$t2,0x4($t5)
/*  f0acc04:	ade10000 */ 	sw	$at,0x0($t7)
/*  f0acc08:	8da10008 */ 	lw	$at,0x8($t5)
/*  f0acc0c:	3c0c8007 */ 	lui	$t4,%hi(var80070518)
/*  f0acc10:	258c0518 */ 	addiu	$t4,$t4,%lo(var80070518)
/*  f0acc14:	adea0004 */ 	sw	$t2,0x4($t7)
/*  f0acc18:	ade10008 */ 	sw	$at,0x8($t7)
/*  f0acc1c:	8d810000 */ 	lw	$at,0x0($t4)
/*  f0acc20:	27b900f4 */ 	addiu	$t9,$sp,0xf4
/*  f0acc24:	8d8b0004 */ 	lw	$t3,0x4($t4)
/*  f0acc28:	af210000 */ 	sw	$at,0x0($t9)
/*  f0acc2c:	8d810008 */ 	lw	$at,0x8($t4)
/*  f0acc30:	3c0f800b */ 	lui	$t7,%hi(g_TexBeamConfigs)
/*  f0acc34:	af2b0004 */ 	sw	$t3,0x4($t9)
/*  f0acc38:	af210008 */ 	sw	$at,0x8($t9)
/*  f0acc3c:	8defb574 */ 	lw	$t7,%lo(g_TexBeamConfigs)($t7)
/*  f0acc40:	00107080 */ 	sll	$t6,$s0,0x2
/*  f0acc44:	3c017f1b */ 	lui	$at,%hi(var7f1acc6c)
/*  f0acc48:	01d07023 */ 	subu	$t6,$t6,$s0
/*  f0acc4c:	c42acc6c */ 	lwc1	$f10,%lo(var7f1acc6c)($at)
/*  f0acc50:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0acc54:	01cf6821 */ 	addu	$t5,$t6,$t7
/*  f0acc58:	afad00ec */ 	sw	$t5,0xec($sp)
/*  f0acc5c:	e7a20124 */ 	swc1	$f2,0x124($sp)
/*  f0acc60:	0fc2d5be */ 	jal	camGetWorldToScreenMtxf
/*  f0acc64:	e7aa00f0 */ 	swc1	$f10,0xf0($sp)
/*  f0acc68:	afa200e4 */ 	sw	$v0,0xe4($sp)
/*  f0acc6c:	82230001 */ 	lb	$v1,0x1($s1)
/*  f0acc70:	3c10800b */ 	lui	$s0,%hi(g_TexBeamConfigs)
/*  f0acc74:	2610b574 */ 	addiu	$s0,$s0,%lo(g_TexBeamConfigs)
/*  f0acc78:	246afffa */ 	addiu	$t2,$v1,-6
/*  f0acc7c:	2d410017 */ 	sltiu	$at,$t2,0x17
/*  f0acc80:	10200012 */ 	beqz	$at,.L0f0acccc
/*  f0acc84:	c7a20124 */ 	lwc1	$f2,0x124($sp)
/*  f0acc88:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0acc8c:	3c017f1b */ 	lui	$at,%hi(jtbl_var7f1acc70)
/*  f0acc90:	002a0821 */ 	addu	$at,$at,$t2
/*  f0acc94:	8c2acc70 */ 	lw	$t2,%lo(jtbl_var7f1acc70)($at)
/*  f0acc98:	01400008 */ 	jr	$t2
/*  f0acc9c:	00000000 */ 	nop
.L0f0acca0:
/*  f0acca0:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0acca4:	2709000c */ 	addiu	$t1,$t8,0xc
/*  f0acca8:	10000008 */ 	b	.L0f0acccc
/*  f0accac:	afa900ec */ 	sw	$t1,0xec($sp)
.L0f0accb0:
/*  f0accb0:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f0accb4:	272c0024 */ 	addiu	$t4,$t9,0x24
/*  f0accb8:	10000004 */ 	b	.L0f0acccc
/*  f0accbc:	afac00ec */ 	sw	$t4,0xec($sp)
.L0f0accc0:
/*  f0accc0:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f0accc4:	256e0030 */ 	addiu	$t6,$t3,0x30
/*  f0accc8:	afae00ec */ 	sw	$t6,0xec($sp)
.L0f0acccc:
/*  f0acccc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0accd0:	10610004 */ 	beq	$v1,$at,.L0f0acce4
/*  f0accd4:	8fad0144 */ 	lw	$t5,0x144($sp)
/*  f0accd8:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0accdc:	14610004 */ 	bne	$v1,$at,.L0f0accf0
/*  f0acce0:	8fb80144 */ 	lw	$t8,0x144($sp)
.L0f0acce4:
/*  f0acce4:	240fff7f */ 	addiu	$t7,$zero,-129
/*  f0acce8:	10000003 */ 	b	.L0f0accf8
/*  f0accec:	adaf0000 */ 	sw	$t7,0x0($t5)
.L0f0accf0:
/*  f0accf0:	240affff */ 	addiu	$t2,$zero,-1
/*  f0accf4:	af0a0000 */ 	sw	$t2,0x0($t8)
.L0f0accf8:
/*  f0accf8:	82230001 */ 	lb	$v1,0x1($s1)
/*  f0accfc:	2401001d */ 	addiu	$at,$zero,0x1d
/*  f0acd00:	3c09800b */ 	lui	$t1,%hi(g_TexLaserConfigs)
/*  f0acd04:	54610008 */ 	bnel	$v1,$at,.L0f0acd28
/*  f0acd08:	2401fffe */ 	addiu	$at,$zero,-2
/*  f0acd0c:	8d29b578 */ 	lw	$t1,%lo(g_TexLaserConfigs)($t1)
/*  f0acd10:	3c014248 */ 	lui	$at,0x4248
/*  f0acd14:	44819000 */ 	mtc1	$at,$f18
/*  f0acd18:	afa900ec */ 	sw	$t1,0xec($sp)
/*  f0acd1c:	10000029 */ 	b	.L0f0acdc4
/*  f0acd20:	e7b20130 */ 	swc1	$f18,0x130($sp)
/*  f0acd24:	2401fffe */ 	addiu	$at,$zero,-2
.L0f0acd28:
/*  f0acd28:	14610022 */ 	bne	$v1,$at,.L0f0acdb4
/*  f0acd2c:	3c19800b */ 	lui	$t9,%hi(g_TexLaserConfigs)
/*  f0acd30:	3c014120 */ 	lui	$at,0x4120
/*  f0acd34:	44813000 */ 	mtc1	$at,$f6
/*  f0acd38:	8f39b578 */ 	lw	$t9,%lo(g_TexLaserConfigs)($t9)
/*  f0acd3c:	e7a20124 */ 	swc1	$f2,0x124($sp)
/*  f0acd40:	e7a60130 */ 	swc1	$f6,0x130($sp)
/*  f0acd44:	0c004b70 */ 	jal	random
/*  f0acd48:	afb900ec */ 	sw	$t9,0xec($sp)
/*  f0acd4c:	24010032 */ 	addiu	$at,$zero,0x32
/*  f0acd50:	0041001b */ 	divu	$zero,$v0,$at
/*  f0acd54:	8fae0144 */ 	lw	$t6,0x144($sp)
/*  f0acd58:	00006010 */ 	mfhi	$t4
/*  f0acd5c:	258b0096 */ 	addiu	$t3,$t4,0x96
/*  f0acd60:	0c004b70 */ 	jal	random
/*  f0acd64:	a1cb0003 */ 	sb	$t3,0x3($t6)
/*  f0acd68:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0acd6c:	0041001b */ 	divu	$zero,$v0,$at
/*  f0acd70:	00007810 */ 	mfhi	$t7
/*  f0acd74:	c7a20124 */ 	lwc1	$f2,0x124($sp)
/*  f0acd78:	15e0000c */ 	bnez	$t7,.L0f0acdac
/*  f0acd7c:	00000000 */ 	nop
/*  f0acd80:	0c004b70 */ 	jal	random
/*  f0acd84:	e7a20124 */ 	swc1	$f2,0x124($sp)
/*  f0acd88:	24010064 */ 	addiu	$at,$zero,0x64
/*  f0acd8c:	0041001b */ 	divu	$zero,$v0,$at
/*  f0acd90:	8fb80144 */ 	lw	$t8,0x144($sp)
/*  f0acd94:	00006810 */ 	mfhi	$t5
/*  f0acd98:	240a00ff */ 	addiu	$t2,$zero,0xff
/*  f0acd9c:	014d1823 */ 	subu	$v1,$t2,$t5
/*  f0acda0:	c7a20124 */ 	lwc1	$f2,0x124($sp)
/*  f0acda4:	a3030000 */ 	sb	$v1,0x0($t8)
/*  f0acda8:	a3030001 */ 	sb	$v1,0x1($t8)
.L0f0acdac:
/*  f0acdac:	10000005 */ 	b	.L0f0acdc4
/*  f0acdb0:	82230001 */ 	lb	$v1,0x1($s1)
.L0f0acdb4:
/*  f0acdb4:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0acdb8:	44812000 */ 	mtc1	$at,$f4
/*  f0acdbc:	00000000 */ 	nop
/*  f0acdc0:	e7a40130 */ 	swc1	$f4,0x130($sp)
.L0f0acdc4:
/*  f0acdc4:	2861fffe */ 	slti	$at,$v1,-2
/*  f0acdc8:	1020000d */ 	beqz	$at,.L0f0ace00
/*  f0acdcc:	24690003 */ 	addiu	$t1,$v1,0x3
/*  f0acdd0:	44895000 */ 	mtc1	$t1,$f10
/*  f0acdd4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0acdd8:	44813000 */ 	mtc1	$at,$f6
/*  f0acddc:	46805020 */ 	cvt.s.w	$f0,$f10
/*  f0acde0:	c7aa0130 */ 	lwc1	$f10,0x130($sp)
/*  f0acde4:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f0acde8:	272c0030 */ 	addiu	$t4,$t9,0x30
/*  f0acdec:	46000200 */ 	add.s	$f8,$f0,$f0
/*  f0acdf0:	afac00ec */ 	sw	$t4,0xec($sp)
/*  f0acdf4:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0acdf8:	460a2202 */ 	mul.s	$f8,$f4,$f10
/*  f0acdfc:	e7a80130 */ 	swc1	$f8,0x130($sp)
.L0f0ace00:
/*  f0ace00:	c6260004 */ 	lwc1	$f6,0x4($s1)
/*  f0ace04:	44807000 */ 	mtc1	$zero,$f14
/*  f0ace08:	27a4010c */ 	addiu	$a0,$sp,0x10c
/*  f0ace0c:	e7a60138 */ 	swc1	$f6,0x138($sp)
/*  f0ace10:	c6240008 */ 	lwc1	$f4,0x8($s1)
/*  f0ace14:	4602703c */ 	c.lt.s	$f14,$f2
/*  f0ace18:	c7a6012c */ 	lwc1	$f6,0x12c($sp)
/*  f0ace1c:	e7a4013c */ 	swc1	$f4,0x13c($sp)
/*  f0ace20:	c62a000c */ 	lwc1	$f10,0xc($s1)
/*  f0ace24:	27a50110 */ 	addiu	$a1,$sp,0x110
/*  f0ace28:	45000011 */ 	bc1f	.L0f0ace70
/*  f0ace2c:	e7aa0140 */ 	swc1	$f10,0x140($sp)
/*  f0ace30:	c6260010 */ 	lwc1	$f6,0x10($s1)
/*  f0ace34:	c7a80138 */ 	lwc1	$f8,0x138($sp)
/*  f0ace38:	46061102 */ 	mul.s	$f4,$f2,$f6
/*  f0ace3c:	c7a6013c */ 	lwc1	$f6,0x13c($sp)
/*  f0ace40:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f0ace44:	e7aa0138 */ 	swc1	$f10,0x138($sp)
/*  f0ace48:	c6280014 */ 	lwc1	$f8,0x14($s1)
/*  f0ace4c:	46081102 */ 	mul.s	$f4,$f2,$f8
/*  f0ace50:	c7a80140 */ 	lwc1	$f8,0x140($sp)
/*  f0ace54:	46043280 */ 	add.s	$f10,$f6,$f4
/*  f0ace58:	e7aa013c */ 	swc1	$f10,0x13c($sp)
/*  f0ace5c:	c6260018 */ 	lwc1	$f6,0x18($s1)
/*  f0ace60:	46061102 */ 	mul.s	$f4,$f2,$f6
/*  f0ace64:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f0ace68:	10000004 */ 	b	.L0f0ace7c
/*  f0ace6c:	e7aa0140 */ 	swc1	$f10,0x140($sp)
.L0f0ace70:
/*  f0ace70:	46023200 */ 	add.s	$f8,$f6,$f2
/*  f0ace74:	46007086 */ 	mov.s	$f2,$f14
/*  f0ace78:	e7a8012c */ 	swc1	$f8,0x12c($sp)
.L0f0ace7c:
/*  f0ace7c:	c7a4012c */ 	lwc1	$f4,0x12c($sp)
/*  f0ace80:	c620001c */ 	lwc1	$f0,0x1c($s1)
/*  f0ace84:	27a60114 */ 	addiu	$a2,$sp,0x114
/*  f0ace88:	46041280 */ 	add.s	$f10,$f2,$f4
/*  f0ace8c:	460a003c */ 	c.lt.s	$f0,$f10
/*  f0ace90:	00000000 */ 	nop
/*  f0ace94:	45020004 */ 	bc1fl	.L0f0acea8
/*  f0ace98:	c7b0012c */ 	lwc1	$f16,0x12c($sp)
/*  f0ace9c:	46020401 */ 	sub.s	$f16,$f0,$f2
/*  f0acea0:	e7b0012c */ 	swc1	$f16,0x12c($sp)
/*  f0acea4:	c7b0012c */ 	lwc1	$f16,0x12c($sp)
.L0f0acea8:
/*  f0acea8:	c62c0018 */ 	lwc1	$f12,0x18($s1)
/*  f0aceac:	c7a60140 */ 	lwc1	$f6,0x140($sp)
/*  f0aceb0:	8fa20134 */ 	lw	$v0,0x134($sp)
/*  f0aceb4:	460c8202 */ 	mul.s	$f8,$f16,$f12
/*  f0aceb8:	c6220014 */ 	lwc1	$f2,0x14($s1)
/*  f0acebc:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f0acec0:	e7a60030 */ 	swc1	$f6,0x30($sp)
/*  f0acec4:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f0acec8:	c4460004 */ 	lwc1	$f6,0x4($v0)
/*  f0acecc:	46045201 */ 	sub.s	$f8,$f10,$f4
/*  f0aced0:	46081282 */ 	mul.s	$f10,$f2,$f8
/*  f0aced4:	c7a8013c */ 	lwc1	$f8,0x13c($sp)
/*  f0aced8:	46101102 */ 	mul.s	$f4,$f2,$f16
/*  f0acedc:	46082100 */ 	add.s	$f4,$f4,$f8
/*  f0acee0:	46043181 */ 	sub.s	$f6,$f6,$f4
/*  f0acee4:	460c3102 */ 	mul.s	$f4,$f6,$f12
/*  f0acee8:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f0aceec:	c7aa0138 */ 	lwc1	$f10,0x138($sp)
/*  f0acef0:	e7a6010c */ 	swc1	$f6,0x10c($sp)
/*  f0acef4:	c6200010 */ 	lwc1	$f0,0x10($s1)
/*  f0acef8:	c62c0018 */ 	lwc1	$f12,0x18($s1)
/*  f0acefc:	e7a80034 */ 	swc1	$f8,0x34($sp)
/*  f0acf00:	46008102 */ 	mul.s	$f4,$f16,$f0
/*  f0acf04:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f0acf08:	e7a60038 */ 	swc1	$f6,0x38($sp)
/*  f0acf0c:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*  f0acf10:	46045100 */ 	add.s	$f4,$f10,$f4
/*  f0acf14:	46044201 */ 	sub.s	$f8,$f8,$f4
/*  f0acf18:	46086102 */ 	mul.s	$f4,$f12,$f8
/*  f0acf1c:	00000000 */ 	nop
/*  f0acf20:	46106202 */ 	mul.s	$f8,$f12,$f16
/*  f0acf24:	46064200 */ 	add.s	$f8,$f8,$f6
/*  f0acf28:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f0acf2c:	46083181 */ 	sub.s	$f6,$f6,$f8
/*  f0acf30:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0acf34:	46082181 */ 	sub.s	$f6,$f4,$f8
/*  f0acf38:	c7a40034 */ 	lwc1	$f4,0x34($sp)
/*  f0acf3c:	e7a60110 */ 	swc1	$f6,0x110($sp)
/*  f0acf40:	c6220014 */ 	lwc1	$f2,0x14($s1)
/*  f0acf44:	c6200010 */ 	lwc1	$f0,0x10($s1)
/*  f0acf48:	46028202 */ 	mul.s	$f8,$f16,$f2
/*  f0acf4c:	46082100 */ 	add.s	$f4,$f4,$f8
/*  f0acf50:	c4480004 */ 	lwc1	$f8,0x4($v0)
/*  f0acf54:	46044201 */ 	sub.s	$f8,$f8,$f4
/*  f0acf58:	46080102 */ 	mul.s	$f4,$f0,$f8
/*  f0acf5c:	00000000 */ 	nop
/*  f0acf60:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f0acf64:	460a4200 */ 	add.s	$f8,$f8,$f10
/*  f0acf68:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f0acf6c:	46085281 */ 	sub.s	$f10,$f10,$f8
/*  f0acf70:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f0acf74:	46082281 */ 	sub.s	$f10,$f4,$f8
/*  f0acf78:	c7a40038 */ 	lwc1	$f4,0x38($sp)
/*  f0acf7c:	46047032 */ 	c.eq.s	$f14,$f4
/*  f0acf80:	e7aa0114 */ 	swc1	$f10,0x114($sp)
/*  f0acf84:	45000009 */ 	bc1f	.L0f0acfac
/*  f0acf88:	00000000 */ 	nop
/*  f0acf8c:	46067032 */ 	c.eq.s	$f14,$f6
/*  f0acf90:	00000000 */ 	nop
/*  f0acf94:	45000005 */ 	bc1f	.L0f0acfac
/*  f0acf98:	00000000 */ 	nop
/*  f0acf9c:	460a7032 */ 	c.eq.s	$f14,$f10
/*  f0acfa0:	00000000 */ 	nop
/*  f0acfa4:	4503000f */ 	bc1tl	.L0f0acfe4
/*  f0acfa8:	c7a60130 */ 	lwc1	$f6,0x130($sp)
.L0f0acfac:
/*  f0acfac:	0c0011e4 */ 	jal	guNormalize
/*  f0acfb0:	e7b0012c */ 	swc1	$f16,0x12c($sp)
/*  f0acfb4:	c7a00130 */ 	lwc1	$f0,0x130($sp)
/*  f0acfb8:	c7a8010c */ 	lwc1	$f8,0x10c($sp)
/*  f0acfbc:	c7a60110 */ 	lwc1	$f6,0x110($sp)
/*  f0acfc0:	46004102 */ 	mul.s	$f4,$f8,$f0
/*  f0acfc4:	c7a80114 */ 	lwc1	$f8,0x114($sp)
/*  f0acfc8:	46003282 */ 	mul.s	$f10,$f6,$f0
/*  f0acfcc:	e7a4010c */ 	swc1	$f4,0x10c($sp)
/*  f0acfd0:	46004102 */ 	mul.s	$f4,$f8,$f0
/*  f0acfd4:	e7aa0110 */ 	swc1	$f10,0x110($sp)
/*  f0acfd8:	10000006 */ 	b	.L0f0acff4
/*  f0acfdc:	e7a40114 */ 	swc1	$f4,0x114($sp)
/*  f0acfe0:	c7a60130 */ 	lwc1	$f6,0x130($sp)
.L0f0acfe4:
/*  f0acfe4:	e7ae010c */ 	swc1	$f14,0x10c($sp)
/*  f0acfe8:	e7ae0114 */ 	swc1	$f14,0x114($sp)
/*  f0acfec:	e7b0012c */ 	swc1	$f16,0x12c($sp)
/*  f0acff0:	e7a60110 */ 	swc1	$f6,0x110($sp)
.L0f0acff4:
/*  f0acff4:	c62a0014 */ 	lwc1	$f10,0x14($s1)
/*  f0acff8:	c7a80114 */ 	lwc1	$f8,0x114($sp)
/*  f0acffc:	c7a60110 */ 	lwc1	$f6,0x110($sp)
/*  f0ad000:	27a40118 */ 	addiu	$a0,$sp,0x118
/*  f0ad004:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0ad008:	c62a0018 */ 	lwc1	$f10,0x18($s1)
/*  f0ad00c:	27a5011c */ 	addiu	$a1,$sp,0x11c
/*  f0ad010:	27a60120 */ 	addiu	$a2,$sp,0x120
/*  f0ad014:	460a3282 */ 	mul.s	$f10,$f6,$f10
/*  f0ad018:	460a2101 */ 	sub.s	$f4,$f4,$f10
/*  f0ad01c:	e7a40118 */ 	swc1	$f4,0x118($sp)
/*  f0ad020:	c62a0018 */ 	lwc1	$f10,0x18($s1)
/*  f0ad024:	c7a4010c */ 	lwc1	$f4,0x10c($sp)
/*  f0ad028:	e7a60038 */ 	swc1	$f6,0x38($sp)
/*  f0ad02c:	c6260010 */ 	lwc1	$f6,0x10($s1)
/*  f0ad030:	46045282 */ 	mul.s	$f10,$f10,$f4
/*  f0ad034:	00000000 */ 	nop
/*  f0ad038:	46064202 */ 	mul.s	$f8,$f8,$f6
/*  f0ad03c:	46085181 */ 	sub.s	$f6,$f10,$f8
/*  f0ad040:	c7a80038 */ 	lwc1	$f8,0x38($sp)
/*  f0ad044:	e7a6011c */ 	swc1	$f6,0x11c($sp)
/*  f0ad048:	c62a0010 */ 	lwc1	$f10,0x10($s1)
/*  f0ad04c:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f0ad050:	c62a0014 */ 	lwc1	$f10,0x14($s1)
/*  f0ad054:	460a2202 */ 	mul.s	$f8,$f4,$f10
/*  f0ad058:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f0ad05c:	0c0011e4 */ 	jal	guNormalize
/*  f0ad060:	e7a40120 */ 	swc1	$f4,0x120($sp)
/*  f0ad064:	c7a00130 */ 	lwc1	$f0,0x130($sp)
/*  f0ad068:	c7aa0118 */ 	lwc1	$f10,0x118($sp)
/*  f0ad06c:	c7a8011c */ 	lwc1	$f8,0x11c($sp)
/*  f0ad070:	2401001d */ 	addiu	$at,$zero,0x1d
/*  f0ad074:	46005182 */ 	mul.s	$f6,$f10,$f0
/*  f0ad078:	c7aa0120 */ 	lwc1	$f10,0x120($sp)
/*  f0ad07c:	46004102 */ 	mul.s	$f4,$f8,$f0
/*  f0ad080:	e7a60118 */ 	swc1	$f6,0x118($sp)
/*  f0ad084:	46005182 */ 	mul.s	$f6,$f10,$f0
/*  f0ad088:	e7a4011c */ 	swc1	$f4,0x11c($sp)
/*  f0ad08c:	e7a60120 */ 	swc1	$f6,0x120($sp)
/*  f0ad090:	822b0001 */ 	lb	$t3,0x1($s1)
/*  f0ad094:	15610005 */ 	bne	$t3,$at,.L0f0ad0ac
/*  f0ad098:	00000000 */ 	nop
/*  f0ad09c:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f0ad0a0:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f0ad0a4:	10000004 */ 	b	.L0f0ad0b8
/*  f0ad0a8:	00408025 */ 	or	$s0,$v0,$zero
.L0f0ad0ac:
/*  f0ad0ac:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f0ad0b0:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0ad0b4:	00408025 */ 	or	$s0,$v0,$zero
.L0f0ad0b8:
/*  f0ad0b8:	0fc59e66 */ 	jal	gfxAllocateMatrix
/*  f0ad0bc:	00000000 */ 	nop
/*  f0ad0c0:	44807000 */ 	mtc1	$zero,$f14
/*  f0ad0c4:	c7a8012c */ 	lwc1	$f8,0x12c($sp)
/*  f0ad0c8:	afa20188 */ 	sw	$v0,0x188($sp)
/*  f0ad0cc:	c7ac0138 */ 	lwc1	$f12,0x138($sp)
/*  f0ad0d0:	4608703c */ 	c.lt.s	$f14,$f8
/*  f0ad0d4:	3c01c6fa */ 	lui	$at,0xc6fa
/*  f0ad0d8:	450202b3 */ 	bc1fl	.L0f0adba8
/*  f0ad0dc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0ad0e0:	44817000 */ 	mtc1	$at,$f14
/*  f0ad0e4:	3c0146fa */ 	lui	$at,0x46fa
/*  f0ad0e8:	460c703c */ 	c.lt.s	$f14,$f12
/*  f0ad0ec:	00000000 */ 	nop
/*  f0ad0f0:	450202ad */ 	bc1fl	.L0f0adba8
/*  f0ad0f4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0ad0f8:	44811000 */ 	mtc1	$at,$f2
/*  f0ad0fc:	c7b0013c */ 	lwc1	$f16,0x13c($sp)
/*  f0ad100:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0ad104:	00000000 */ 	nop
/*  f0ad108:	450202a7 */ 	bc1fl	.L0f0adba8
/*  f0ad10c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0ad110:	4610703c */ 	c.lt.s	$f14,$f16
/*  f0ad114:	00000000 */ 	nop
/*  f0ad118:	450202a3 */ 	bc1fl	.L0f0adba8
/*  f0ad11c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0ad120:	4602803c */ 	c.lt.s	$f16,$f2
/*  f0ad124:	c7b20140 */ 	lwc1	$f18,0x140($sp)
/*  f0ad128:	4502029f */ 	bc1fl	.L0f0adba8
/*  f0ad12c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0ad130:	4612703c */ 	c.lt.s	$f14,$f18
/*  f0ad134:	00000000 */ 	nop
/*  f0ad138:	4502029b */ 	bc1fl	.L0f0adba8
/*  f0ad13c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0ad140:	4602903c */ 	c.lt.s	$f18,$f2
/*  f0ad144:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0ad148:	27a40138 */ 	addiu	$a0,$sp,0x138
/*  f0ad14c:	27a50148 */ 	addiu	$a1,$sp,0x148
/*  f0ad150:	45020295 */ 	bc1fl	.L0f0adba8
/*  f0ad154:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0ad158:	0c0059b7 */ 	jal	mtx4LoadTranslation
/*  f0ad15c:	afa800d8 */ 	sw	$t0,0xd8($sp)
/*  f0ad160:	3c017f1b */ 	lui	$at,%hi(var7f1acccc)
/*  f0ad164:	c42ccccc */ 	lwc1	$f12,%lo(var7f1acccc)($at)
/*  f0ad168:	0c0057c1 */ 	jal	mtx00015f04
/*  f0ad16c:	27a50148 */ 	addiu	$a1,$sp,0x148
/*  f0ad170:	8fa400e4 */ 	lw	$a0,0xe4($sp)
/*  f0ad174:	0c0056f8 */ 	jal	mtx00015be0
/*  f0ad178:	27a50148 */ 	addiu	$a1,$sp,0x148
/*  f0ad17c:	3c0146fa */ 	lui	$at,0x46fa
/*  f0ad180:	44811000 */ 	mtc1	$at,$f2
/*  f0ad184:	3c01c6fa */ 	lui	$at,0xc6fa
/*  f0ad188:	44817000 */ 	mtc1	$at,$f14
/*  f0ad18c:	8fa800d8 */ 	lw	$t0,0xd8($sp)
/*  f0ad190:	27a50148 */ 	addiu	$a1,$sp,0x148
/*  f0ad194:	27a70188 */ 	addiu	$a3,$sp,0x188
/*  f0ad198:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f0ad19c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0ad1a0:
/*  f0ad1a0:	00a01825 */ 	or	$v1,$a1,$zero
.L0f0ad1a4:
/*  f0ad1a4:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f0ad1a8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f0ad1ac:	460e003c */ 	c.lt.s	$f0,$f14
/*  f0ad1b0:	00000000 */ 	nop
/*  f0ad1b4:	45010005 */ 	bc1t	.L0f0ad1cc
/*  f0ad1b8:	00000000 */ 	nop
/*  f0ad1bc:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0ad1c0:	00000000 */ 	nop
/*  f0ad1c4:	45000003 */ 	bc1f	.L0f0ad1d4
/*  f0ad1c8:	00000000 */ 	nop
.L0f0ad1cc:
/*  f0ad1cc:	10000003 */ 	b	.L0f0ad1dc
/*  f0ad1d0:	00004025 */ 	or	$t0,$zero,$zero
.L0f0ad1d4:
/*  f0ad1d4:	1444fff3 */ 	bne	$v0,$a0,.L0f0ad1a4
/*  f0ad1d8:	24630004 */ 	addiu	$v1,$v1,0x4
.L0f0ad1dc:
/*  f0ad1dc:	24a50010 */ 	addiu	$a1,$a1,0x10
/*  f0ad1e0:	54a7ffef */ 	bnel	$a1,$a3,.L0f0ad1a0
/*  f0ad1e4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ad1e8:	1100026e */ 	beqz	$t0,.L0f0adba4
/*  f0ad1ec:	27a40148 */ 	addiu	$a0,$sp,0x148
/*  f0ad1f0:	0c005815 */ 	jal	mtx00016054
/*  f0ad1f4:	8fa50188 */ 	lw	$a1,0x188($sp)
/*  f0ad1f8:	82230001 */ 	lb	$v1,0x1($s1)
/*  f0ad1fc:	2401fffe */ 	addiu	$at,$zero,-2
/*  f0ad200:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f0ad204:	1461006c */ 	bne	$v1,$at,.L0f0ad3b8
/*  f0ad208:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f0ad20c:	8c4e006c */ 	lw	$t6,0x6c($v0)
/*  f0ad210:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ad214:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ad218:	11c00003 */ 	beqz	$t6,.L0f0ad228
/*  f0ad21c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ad220:	10000001 */ 	b	.L0f0ad228
/*  f0ad224:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ad228:
/*  f0ad228:	8c4f0068 */ 	lw	$t7,0x68($v0)
/*  f0ad22c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ad230:	c7a0012c */ 	lwc1	$f0,0x12c($sp)
/*  f0ad234:	11e00003 */ 	beqz	$t7,.L0f0ad244
/*  f0ad238:	00000000 */ 	nop
/*  f0ad23c:	10000001 */ 	b	.L0f0ad244
/*  f0ad240:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0ad244:
/*  f0ad244:	8c4a0064 */ 	lw	$t2,0x64($v0)
/*  f0ad248:	11400003 */ 	beqz	$t2,.L0f0ad258
/*  f0ad24c:	00000000 */ 	nop
/*  f0ad250:	10000001 */ 	b	.L0f0ad258
/*  f0ad254:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0ad258:
/*  f0ad258:	8c4d0070 */ 	lw	$t5,0x70($v0)
/*  f0ad25c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ad260:	11a00003 */ 	beqz	$t5,.L0f0ad270
/*  f0ad264:	00000000 */ 	nop
/*  f0ad268:	10000001 */ 	b	.L0f0ad270
/*  f0ad26c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0ad270:
/*  f0ad270:	0044c021 */ 	addu	$t8,$v0,$a0
/*  f0ad274:	03034821 */ 	addu	$t1,$t8,$v1
/*  f0ad278:	0125c821 */ 	addu	$t9,$t1,$a1
/*  f0ad27c:	5721004f */ 	bnel	$t9,$at,.L0f0ad3bc
/*  f0ad280:	3c014120 */ 	lui	$at,0x4120
/*  f0ad284:	c6240010 */ 	lwc1	$f4,0x10($s1)
/*  f0ad288:	c7a60138 */ 	lwc1	$f6,0x138($sp)
/*  f0ad28c:	8fa400e4 */ 	lw	$a0,0xe4($sp)
/*  f0ad290:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0ad294:	27a500cc */ 	addiu	$a1,$sp,0xcc
/*  f0ad298:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0ad29c:	c7a6013c */ 	lwc1	$f6,0x13c($sp)
/*  f0ad2a0:	e7a800cc */ 	swc1	$f8,0xcc($sp)
/*  f0ad2a4:	c6240014 */ 	lwc1	$f4,0x14($s1)
/*  f0ad2a8:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0ad2ac:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0ad2b0:	c7a60140 */ 	lwc1	$f6,0x140($sp)
/*  f0ad2b4:	e7a800d0 */ 	swc1	$f8,0xd0($sp)
/*  f0ad2b8:	c6240018 */ 	lwc1	$f4,0x18($s1)
/*  f0ad2bc:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0ad2c0:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0ad2c4:	0c0056d9 */ 	jal	mtx4TransformVecInPlace
/*  f0ad2c8:	e7a800d4 */ 	swc1	$f8,0xd4($sp)
/*  f0ad2cc:	3c014120 */ 	lui	$at,0x4120
/*  f0ad2d0:	44815000 */ 	mtc1	$at,$f10
/*  f0ad2d4:	c7a40130 */ 	lwc1	$f4,0x130($sp)
/*  f0ad2d8:	c7a200d4 */ 	lwc1	$f2,0xd4($sp)
/*  f0ad2dc:	27a400b8 */ 	addiu	$a0,$sp,0xb8
/*  f0ad2e0:	460a2003 */ 	div.s	$f0,$f4,$f10
/*  f0ad2e4:	27a600c0 */ 	addiu	$a2,$sp,0xc0
/*  f0ad2e8:	46001087 */ 	neg.s	$f2,$f2
/*  f0ad2ec:	44051000 */ 	mfc1	$a1,$f2
/*  f0ad2f0:	e7a000bc */ 	swc1	$f0,0xbc($sp)
/*  f0ad2f4:	0fc2d39a */ 	jal	cam0f0b4e68
/*  f0ad2f8:	e7a000b8 */ 	swc1	$f0,0xb8($sp)
/*  f0ad2fc:	3c014000 */ 	lui	$at,0x4000
/*  f0ad300:	c7ac00c0 */ 	lwc1	$f12,0xc0($sp)
/*  f0ad304:	44813000 */ 	mtc1	$at,$f6
/*  f0ad308:	3c013f00 */ 	lui	$at,0x3f00
/*  f0ad30c:	4606603c */ 	c.lt.s	$f12,$f6
/*  f0ad310:	00000000 */ 	nop
/*  f0ad314:	4500000e */ 	bc1f	.L0f0ad350
/*  f0ad318:	00000000 */ 	nop
/*  f0ad31c:	44814000 */ 	mtc1	$at,$f8
/*  f0ad320:	c7a200cc */ 	lwc1	$f2,0xcc($sp)
/*  f0ad324:	c7ae00d0 */ 	lwc1	$f14,0xd0($sp)
/*  f0ad328:	46086002 */ 	mul.s	$f0,$f12,$f8
/*  f0ad32c:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0ad330:	46001082 */ 	mul.s	$f2,$f2,$f0
/*  f0ad334:	00000000 */ 	nop
/*  f0ad338:	46007382 */ 	mul.s	$f14,$f14,$f0
/*  f0ad33c:	00000000 */ 	nop
/*  f0ad340:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0ad344:	e7a200cc */ 	swc1	$f2,0xcc($sp)
/*  f0ad348:	e7ae00d0 */ 	swc1	$f14,0xd0($sp)
/*  f0ad34c:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
.L0f0ad350:
/*  f0ad350:	0fc2d5de */ 	jal	camGetProjectionMtxF
/*  f0ad354:	00000000 */ 	nop
/*  f0ad358:	00402025 */ 	or	$a0,$v0,$zero
/*  f0ad35c:	0c0056d9 */ 	jal	mtx4TransformVecInPlace
/*  f0ad360:	27a500cc */ 	addiu	$a1,$sp,0xcc
/*  f0ad364:	c7a200cc */ 	lwc1	$f2,0xcc($sp)
/*  f0ad368:	c7ac0138 */ 	lwc1	$f12,0x138($sp)
/*  f0ad36c:	c7ae00d0 */ 	lwc1	$f14,0xd0($sp)
/*  f0ad370:	c7b0013c */ 	lwc1	$f16,0x13c($sp)
/*  f0ad374:	460c1081 */ 	sub.s	$f2,$f2,$f12
/*  f0ad378:	3c014120 */ 	lui	$at,0x4120
/*  f0ad37c:	44810000 */ 	mtc1	$at,$f0
/*  f0ad380:	46107381 */ 	sub.s	$f14,$f14,$f16
/*  f0ad384:	c7b20140 */ 	lwc1	$f18,0x140($sp)
/*  f0ad388:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f0ad38c:	46001102 */ 	mul.s	$f4,$f2,$f0
/*  f0ad390:	e7ae00d0 */ 	swc1	$f14,0xd0($sp)
/*  f0ad394:	46123201 */ 	sub.s	$f8,$f6,$f18
/*  f0ad398:	46007282 */ 	mul.s	$f10,$f14,$f0
/*  f0ad39c:	e7a200cc */ 	swc1	$f2,0xcc($sp)
/*  f0ad3a0:	46004182 */ 	mul.s	$f6,$f8,$f0
/*  f0ad3a4:	e7a800d4 */ 	swc1	$f8,0xd4($sp)
/*  f0ad3a8:	e7a40100 */ 	swc1	$f4,0x100($sp)
/*  f0ad3ac:	e7aa0104 */ 	swc1	$f10,0x104($sp)
/*  f0ad3b0:	1000000f */ 	b	.L0f0ad3f0
/*  f0ad3b4:	e7a60108 */ 	swc1	$f6,0x108($sp)
.L0f0ad3b8:
/*  f0ad3b8:	3c014120 */ 	lui	$at,0x4120
.L0f0ad3bc:
/*  f0ad3bc:	44815000 */ 	mtc1	$at,$f10
/*  f0ad3c0:	c7a4012c */ 	lwc1	$f4,0x12c($sp)
/*  f0ad3c4:	c6280010 */ 	lwc1	$f8,0x10($s1)
/*  f0ad3c8:	460a2002 */ 	mul.s	$f0,$f4,$f10
/*  f0ad3cc:	00000000 */ 	nop
/*  f0ad3d0:	46004182 */ 	mul.s	$f6,$f8,$f0
/*  f0ad3d4:	e7a60100 */ 	swc1	$f6,0x100($sp)
/*  f0ad3d8:	c6240014 */ 	lwc1	$f4,0x14($s1)
/*  f0ad3dc:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0ad3e0:	e7aa0104 */ 	swc1	$f10,0x104($sp)
/*  f0ad3e4:	c6280018 */ 	lwc1	$f8,0x18($s1)
/*  f0ad3e8:	46004182 */ 	mul.s	$f6,$f8,$f0
/*  f0ad3ec:	e7a60108 */ 	swc1	$f6,0x108($sp)
.L0f0ad3f0:
/*  f0ad3f0:	3c017f1b */ 	lui	$at,%hi(var7f1accd0)
/*  f0ad3f4:	c420ccd0 */ 	lwc1	$f0,%lo(var7f1accd0)($at)
/*  f0ad3f8:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*  f0ad3fc:	3c017f1b */ 	lui	$at,%hi(var7f1accd4)
/*  f0ad400:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0ad404:	00000000 */ 	nop
/*  f0ad408:	450201e7 */ 	bc1fl	.L0f0adba8
/*  f0ad40c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0ad410:	c422ccd4 */ 	lwc1	$f2,%lo(var7f1accd4)($at)
/*  f0ad414:	c7aa0104 */ 	lwc1	$f10,0x104($sp)
/*  f0ad418:	4602203c */ 	c.lt.s	$f4,$f2
/*  f0ad41c:	00000000 */ 	nop
/*  f0ad420:	450201e1 */ 	bc1fl	.L0f0adba8
/*  f0ad424:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0ad428:	460a003c */ 	c.lt.s	$f0,$f10
/*  f0ad42c:	00000000 */ 	nop
/*  f0ad430:	450201dd */ 	bc1fl	.L0f0adba8
/*  f0ad434:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0ad438:	4602503c */ 	c.lt.s	$f10,$f2
/*  f0ad43c:	c7a80108 */ 	lwc1	$f8,0x108($sp)
/*  f0ad440:	450201d9 */ 	bc1fl	.L0f0adba8
/*  f0ad444:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0ad448:	4608003c */ 	c.lt.s	$f0,$f8
/*  f0ad44c:	00000000 */ 	nop
/*  f0ad450:	450201d5 */ 	bc1fl	.L0f0adba8
/*  f0ad454:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0ad458:	4602403c */ 	c.lt.s	$f8,$f2
/*  f0ad45c:	c7a6010c */ 	lwc1	$f6,0x10c($sp)
/*  f0ad460:	450201d1 */ 	bc1fl	.L0f0adba8
/*  f0ad464:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0ad468:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f0ad46c:	8fa500ec */ 	lw	$a1,0xec($sp)
/*  f0ad470:	3c017f1b */ 	lui	$at,%hi(var7f1accd8)
/*  f0ad474:	440b2000 */ 	mfc1	$t3,$f4
/*  f0ad478:	00000000 */ 	nop
/*  f0ad47c:	a60b0000 */ 	sh	$t3,0x0($s0)
/*  f0ad480:	c7aa0110 */ 	lwc1	$f10,0x110($sp)
/*  f0ad484:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f0ad488:	440f4000 */ 	mfc1	$t7,$f8
/*  f0ad48c:	00000000 */ 	nop
/*  f0ad490:	a60f0002 */ 	sh	$t7,0x2($s0)
/*  f0ad494:	c7a60114 */ 	lwc1	$f6,0x114($sp)
/*  f0ad498:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f0ad49c:	440d2000 */ 	mfc1	$t5,$f4
/*  f0ad4a0:	00000000 */ 	nop
/*  f0ad4a4:	a60d0004 */ 	sh	$t5,0x4($s0)
/*  f0ad4a8:	90b80004 */ 	lbu	$t8,0x4($a1)
/*  f0ad4ac:	a600000a */ 	sh	$zero,0xa($s0)
/*  f0ad4b0:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f0ad4b4:	00184940 */ 	sll	$t1,$t8,0x5
/*  f0ad4b8:	a6090008 */ 	sh	$t1,0x8($s0)
/*  f0ad4bc:	c7aa010c */ 	lwc1	$f10,0x10c($sp)
/*  f0ad4c0:	46005207 */ 	neg.s	$f8,$f10
/*  f0ad4c4:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f0ad4c8:	440c3000 */ 	mfc1	$t4,$f6
/*  f0ad4cc:	00000000 */ 	nop
/*  f0ad4d0:	a60c000c */ 	sh	$t4,0xc($s0)
/*  f0ad4d4:	c7a40110 */ 	lwc1	$f4,0x110($sp)
/*  f0ad4d8:	46002287 */ 	neg.s	$f10,$f4
/*  f0ad4dc:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f0ad4e0:	440e4000 */ 	mfc1	$t6,$f8
/*  f0ad4e4:	00000000 */ 	nop
/*  f0ad4e8:	a60e000e */ 	sh	$t6,0xe($s0)
/*  f0ad4ec:	c7a60114 */ 	lwc1	$f6,0x114($sp)
/*  f0ad4f0:	a6000014 */ 	sh	$zero,0x14($s0)
/*  f0ad4f4:	a6000016 */ 	sh	$zero,0x16($s0)
/*  f0ad4f8:	46003107 */ 	neg.s	$f4,$f6
/*  f0ad4fc:	a2000013 */ 	sb	$zero,0x13($s0)
/*  f0ad500:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f0ad504:	440a5000 */ 	mfc1	$t2,$f10
/*  f0ad508:	00000000 */ 	nop
/*  f0ad50c:	a60a0010 */ 	sh	$t2,0x10($s0)
/*  f0ad510:	c7a8010c */ 	lwc1	$f8,0x10c($sp)
/*  f0ad514:	c426ccd8 */ 	lwc1	$f6,%lo(var7f1accd8)($at)
/*  f0ad518:	c7aa0100 */ 	lwc1	$f10,0x100($sp)
/*  f0ad51c:	3c017f1b */ 	lui	$at,%hi(var7f1accdc)
/*  f0ad520:	46064102 */ 	mul.s	$f4,$f8,$f6
/*  f0ad524:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0ad528:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f0ad52c:	44183000 */ 	mfc1	$t8,$f6
/*  f0ad530:	00000000 */ 	nop
/*  f0ad534:	a6180018 */ 	sh	$t8,0x18($s0)
/*  f0ad538:	c7a40110 */ 	lwc1	$f4,0x110($sp)
/*  f0ad53c:	c42accdc */ 	lwc1	$f10,%lo(var7f1accdc)($at)
/*  f0ad540:	c7a60104 */ 	lwc1	$f6,0x104($sp)
/*  f0ad544:	3c017f1b */ 	lui	$at,%hi(var7f1acce0)
/*  f0ad548:	460a2202 */ 	mul.s	$f8,$f4,$f10
/*  f0ad54c:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0ad550:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f0ad554:	44195000 */ 	mfc1	$t9,$f10
/*  f0ad558:	00000000 */ 	nop
/*  f0ad55c:	a619001a */ 	sh	$t9,0x1a($s0)
/*  f0ad560:	c7a80114 */ 	lwc1	$f8,0x114($sp)
/*  f0ad564:	c426cce0 */ 	lwc1	$f6,%lo(var7f1acce0)($at)
/*  f0ad568:	c7aa0108 */ 	lwc1	$f10,0x108($sp)
/*  f0ad56c:	3c017f1b */ 	lui	$at,%hi(var7f1acce4)
/*  f0ad570:	46064102 */ 	mul.s	$f4,$f8,$f6
/*  f0ad574:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0ad578:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f0ad57c:	440b3000 */ 	mfc1	$t3,$f6
/*  f0ad580:	00000000 */ 	nop
/*  f0ad584:	a60b001c */ 	sh	$t3,0x1c($s0)
/*  f0ad588:	90ae0004 */ 	lbu	$t6,0x4($a1)
/*  f0ad58c:	000e7940 */ 	sll	$t7,$t6,0x5
/*  f0ad590:	a60f0020 */ 	sh	$t7,0x20($s0)
/*  f0ad594:	90aa0005 */ 	lbu	$t2,0x5($a1)
/*  f0ad598:	a200001f */ 	sb	$zero,0x1f($s0)
/*  f0ad59c:	000a6940 */ 	sll	$t5,$t2,0x5
/*  f0ad5a0:	a60d0022 */ 	sh	$t5,0x22($s0)
/*  f0ad5a4:	c42acce4 */ 	lwc1	$f10,%lo(var7f1acce4)($at)
/*  f0ad5a8:	c7a4010c */ 	lwc1	$f4,0x10c($sp)
/*  f0ad5ac:	c7a60100 */ 	lwc1	$f6,0x100($sp)
/*  f0ad5b0:	3c017f1b */ 	lui	$at,%hi(var7f1acce8)
/*  f0ad5b4:	460a2202 */ 	mul.s	$f8,$f4,$f10
/*  f0ad5b8:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f0ad5bc:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f0ad5c0:	44095000 */ 	mfc1	$t1,$f10
/*  f0ad5c4:	00000000 */ 	nop
/*  f0ad5c8:	a6090024 */ 	sh	$t1,0x24($s0)
/*  f0ad5cc:	c428cce8 */ 	lwc1	$f8,%lo(var7f1acce8)($at)
/*  f0ad5d0:	c7a60110 */ 	lwc1	$f6,0x110($sp)
/*  f0ad5d4:	c7aa0104 */ 	lwc1	$f10,0x104($sp)
/*  f0ad5d8:	3c017f1b */ 	lui	$at,%hi(var7f1accec)
/*  f0ad5dc:	46083102 */ 	mul.s	$f4,$f6,$f8
/*  f0ad5e0:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f0ad5e4:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0ad5e8:	440c4000 */ 	mfc1	$t4,$f8
/*  f0ad5ec:	00000000 */ 	nop
/*  f0ad5f0:	a60c0026 */ 	sh	$t4,0x26($s0)
/*  f0ad5f4:	c424ccec */ 	lwc1	$f4,%lo(var7f1accec)($at)
/*  f0ad5f8:	c7aa0114 */ 	lwc1	$f10,0x114($sp)
/*  f0ad5fc:	c7a80108 */ 	lwc1	$f8,0x108($sp)
/*  f0ad600:	a600002c */ 	sh	$zero,0x2c($s0)
/*  f0ad604:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f0ad608:	2401001d */ 	addiu	$at,$zero,0x1d
/*  f0ad60c:	46064281 */ 	sub.s	$f10,$f8,$f6
/*  f0ad610:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0ad614:	440e2000 */ 	mfc1	$t6,$f4
/*  f0ad618:	00000000 */ 	nop
/*  f0ad61c:	a60e0028 */ 	sh	$t6,0x28($s0)
/*  f0ad620:	90af0005 */ 	lbu	$t7,0x5($a1)
/*  f0ad624:	a200002b */ 	sb	$zero,0x2b($s0)
/*  f0ad628:	000f5140 */ 	sll	$t2,$t7,0x5
/*  f0ad62c:	a60a002e */ 	sh	$t2,0x2e($s0)
/*  f0ad630:	822d0001 */ 	lb	$t5,0x1($s1)
/*  f0ad634:	c7a80138 */ 	lwc1	$f8,0x138($sp)
/*  f0ad638:	8fb80134 */ 	lw	$t8,0x134($sp)
/*  f0ad63c:	55a100b4 */ 	bnel	$t5,$at,.L0f0ad910
/*  f0ad640:	8fa90190 */ 	lw	$t1,0x190($sp)
/*  f0ad644:	c70c0000 */ 	lwc1	$f12,0x0($t8)
/*  f0ad648:	c7020004 */ 	lwc1	$f2,0x4($t8)
/*  f0ad64c:	c7a6013c */ 	lwc1	$f6,0x13c($sp)
/*  f0ad650:	46086381 */ 	sub.s	$f14,$f12,$f8
/*  f0ad654:	c7000008 */ 	lwc1	$f0,0x8($t8)
/*  f0ad658:	e7a80038 */ 	swc1	$f8,0x38($sp)
/*  f0ad65c:	46061401 */ 	sub.s	$f16,$f2,$f6
/*  f0ad660:	460e7102 */ 	mul.s	$f4,$f14,$f14
/*  f0ad664:	c7aa0140 */ 	lwc1	$f10,0x140($sp)
/*  f0ad668:	3c017f1b */ 	lui	$at,%hi(var7f1accf0)
/*  f0ad66c:	46108202 */ 	mul.s	$f8,$f16,$f16
/*  f0ad670:	460a0481 */ 	sub.s	$f18,$f0,$f10
/*  f0ad674:	46082100 */ 	add.s	$f4,$f4,$f8
/*  f0ad678:	46129202 */ 	mul.s	$f8,$f18,$f18
/*  f0ad67c:	46082100 */ 	add.s	$f4,$f4,$f8
/*  f0ad680:	e7a400a8 */ 	swc1	$f4,0xa8($sp)
/*  f0ad684:	c6280010 */ 	lwc1	$f8,0x10($s1)
/*  f0ad688:	e7a60034 */ 	swc1	$f6,0x34($sp)
/*  f0ad68c:	c7a6012c */ 	lwc1	$f6,0x12c($sp)
/*  f0ad690:	e7aa0030 */ 	swc1	$f10,0x30($sp)
/*  f0ad694:	c7aa0038 */ 	lwc1	$f10,0x38($sp)
/*  f0ad698:	46064202 */ 	mul.s	$f8,$f8,$f6
/*  f0ad69c:	460a4200 */ 	add.s	$f8,$f8,$f10
/*  f0ad6a0:	c62a0014 */ 	lwc1	$f10,0x14($s1)
/*  f0ad6a4:	46086381 */ 	sub.s	$f14,$f12,$f8
/*  f0ad6a8:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0ad6ac:	c7aa0034 */ 	lwc1	$f10,0x34($sp)
/*  f0ad6b0:	460a4200 */ 	add.s	$f8,$f8,$f10
/*  f0ad6b4:	c62a0018 */ 	lwc1	$f10,0x18($s1)
/*  f0ad6b8:	46081401 */ 	sub.s	$f16,$f2,$f8
/*  f0ad6bc:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f0ad6c0:	c7aa0030 */ 	lwc1	$f10,0x30($sp)
/*  f0ad6c4:	460a4180 */ 	add.s	$f6,$f8,$f10
/*  f0ad6c8:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*  f0ad6cc:	00000000 */ 	nop
/*  f0ad6d0:	46108282 */ 	mul.s	$f10,$f16,$f16
/*  f0ad6d4:	46060481 */ 	sub.s	$f18,$f0,$f6
/*  f0ad6d8:	460a4180 */ 	add.s	$f6,$f8,$f10
/*  f0ad6dc:	46129202 */ 	mul.s	$f8,$f18,$f18
/*  f0ad6e0:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0ad6e4:	c7a60100 */ 	lwc1	$f6,0x100($sp)
/*  f0ad6e8:	4604503c */ 	c.lt.s	$f10,$f4
/*  f0ad6ec:	00000000 */ 	nop
/*  f0ad6f0:	4500000b */ 	bc1f	.L0f0ad720
/*  f0ad6f4:	00000000 */ 	nop
/*  f0ad6f8:	c424ccf0 */ 	lwc1	$f4,%lo(var7f1accf0)($at)
/*  f0ad6fc:	e7a600f4 */ 	swc1	$f6,0xf4($sp)
/*  f0ad700:	3c017f1b */ 	lui	$at,%hi(var7f1accf4)
/*  f0ad704:	c426ccf4 */ 	lwc1	$f6,%lo(var7f1accf4)($at)
/*  f0ad708:	c7a80104 */ 	lwc1	$f8,0x104($sp)
/*  f0ad70c:	c7aa0108 */ 	lwc1	$f10,0x108($sp)
/*  f0ad710:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f0ad714:	e7a800f8 */ 	swc1	$f8,0xf8($sp)
/*  f0ad718:	e7aa00fc */ 	swc1	$f10,0xfc($sp)
/*  f0ad71c:	e7a000f0 */ 	swc1	$f0,0xf0($sp)
.L0f0ad720:
/*  f0ad720:	c7a000f0 */ 	lwc1	$f0,0xf0($sp)
/*  f0ad724:	c7a80118 */ 	lwc1	$f8,0x118($sp)
/*  f0ad728:	c7a400f4 */ 	lwc1	$f4,0xf4($sp)
/*  f0ad72c:	3c03800b */ 	lui	$v1,%hi(g_TexGroup03Configs)
/*  f0ad730:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0ad734:	2463b57c */ 	addiu	$v1,$v1,%lo(g_TexGroup03Configs)
/*  f0ad738:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0ad73c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0ad740:	44194000 */ 	mfc1	$t9,$f8
/*  f0ad744:	00000000 */ 	nop
/*  f0ad748:	a6190030 */ 	sh	$t9,0x30($s0)
/*  f0ad74c:	c7aa011c */ 	lwc1	$f10,0x11c($sp)
/*  f0ad750:	c7a600f8 */ 	lwc1	$f6,0xf8($sp)
/*  f0ad754:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0ad758:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0ad75c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0ad760:	440b5000 */ 	mfc1	$t3,$f10
/*  f0ad764:	00000000 */ 	nop
/*  f0ad768:	a60b0032 */ 	sh	$t3,0x32($s0)
/*  f0ad76c:	c7a40120 */ 	lwc1	$f4,0x120($sp)
/*  f0ad770:	c7a800fc */ 	lwc1	$f8,0xfc($sp)
/*  f0ad774:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f0ad778:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0ad77c:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0ad780:	440f2000 */ 	mfc1	$t7,$f4
/*  f0ad784:	00000000 */ 	nop
/*  f0ad788:	a60f0034 */ 	sh	$t7,0x34($s0)
/*  f0ad78c:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f0ad790:	914d0004 */ 	lbu	$t5,0x4($t2)
/*  f0ad794:	000dc140 */ 	sll	$t8,$t5,0x5
/*  f0ad798:	a6180038 */ 	sh	$t8,0x38($s0)
/*  f0ad79c:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f0ad7a0:	91390005 */ 	lbu	$t9,0x5($t1)
/*  f0ad7a4:	a2000037 */ 	sb	$zero,0x37($s0)
/*  f0ad7a8:	00196140 */ 	sll	$t4,$t9,0x5
/*  f0ad7ac:	a60c003a */ 	sh	$t4,0x3a($s0)
/*  f0ad7b0:	c7a80118 */ 	lwc1	$f8,0x118($sp)
/*  f0ad7b4:	c7a600f4 */ 	lwc1	$f6,0xf4($sp)
/*  f0ad7b8:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0ad7bc:	460a3101 */ 	sub.s	$f4,$f6,$f10
/*  f0ad7c0:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f0ad7c4:	440e4000 */ 	mfc1	$t6,$f8
/*  f0ad7c8:	00000000 */ 	nop
/*  f0ad7cc:	a60e003c */ 	sh	$t6,0x3c($s0)
/*  f0ad7d0:	c7aa011c */ 	lwc1	$f10,0x11c($sp)
/*  f0ad7d4:	c7a600f8 */ 	lwc1	$f6,0xf8($sp)
/*  f0ad7d8:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0ad7dc:	46043201 */ 	sub.s	$f8,$f6,$f4
/*  f0ad7e0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0ad7e4:	440a5000 */ 	mfc1	$t2,$f10
/*  f0ad7e8:	00000000 */ 	nop
/*  f0ad7ec:	a60a003e */ 	sh	$t2,0x3e($s0)
/*  f0ad7f0:	c7a40120 */ 	lwc1	$f4,0x120($sp)
/*  f0ad7f4:	c7a600fc */ 	lwc1	$f6,0xfc($sp)
/*  f0ad7f8:	a6000044 */ 	sh	$zero,0x44($s0)
/*  f0ad7fc:	46002202 */ 	mul.s	$f8,$f4,$f0
/*  f0ad800:	a6000046 */ 	sh	$zero,0x46($s0)
/*  f0ad804:	a2000043 */ 	sb	$zero,0x43($s0)
/*  f0ad808:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0ad80c:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0ad810:	44182000 */ 	mfc1	$t8,$f4
/*  f0ad814:	00000000 */ 	nop
/*  f0ad818:	a6180040 */ 	sh	$t8,0x40($s0)
/*  f0ad81c:	c7a6010c */ 	lwc1	$f6,0x10c($sp)
/*  f0ad820:	c7aa00f4 */ 	lwc1	$f10,0xf4($sp)
/*  f0ad824:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0ad828:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0ad82c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0ad830:	44193000 */ 	mfc1	$t9,$f6
/*  f0ad834:	00000000 */ 	nop
/*  f0ad838:	a6190048 */ 	sh	$t9,0x48($s0)
/*  f0ad83c:	c7a80110 */ 	lwc1	$f8,0x110($sp)
/*  f0ad840:	c7a400f8 */ 	lwc1	$f4,0xf8($sp)
/*  f0ad844:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0ad848:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0ad84c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0ad850:	440b4000 */ 	mfc1	$t3,$f8
/*  f0ad854:	00000000 */ 	nop
/*  f0ad858:	a60b004a */ 	sh	$t3,0x4a($s0)
/*  f0ad85c:	c7aa0114 */ 	lwc1	$f10,0x114($sp)
/*  f0ad860:	c7a600fc */ 	lwc1	$f6,0xfc($sp)
/*  f0ad864:	a6000050 */ 	sh	$zero,0x50($s0)
/*  f0ad868:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0ad86c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0ad870:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0ad874:	440f5000 */ 	mfc1	$t7,$f10
/*  f0ad878:	00000000 */ 	nop
/*  f0ad87c:	a60f004c */ 	sh	$t7,0x4c($s0)
/*  f0ad880:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f0ad884:	914d0005 */ 	lbu	$t5,0x5($t2)
/*  f0ad888:	a200004f */ 	sb	$zero,0x4f($s0)
/*  f0ad88c:	000dc140 */ 	sll	$t8,$t5,0x5
/*  f0ad890:	a6180052 */ 	sh	$t8,0x52($s0)
/*  f0ad894:	c7a6010c */ 	lwc1	$f6,0x10c($sp)
/*  f0ad898:	c7a400f4 */ 	lwc1	$f4,0xf4($sp)
/*  f0ad89c:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0ad8a0:	46082281 */ 	sub.s	$f10,$f4,$f8
/*  f0ad8a4:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f0ad8a8:	44193000 */ 	mfc1	$t9,$f6
/*  f0ad8ac:	00000000 */ 	nop
/*  f0ad8b0:	a6190054 */ 	sh	$t9,0x54($s0)
/*  f0ad8b4:	c7a80110 */ 	lwc1	$f8,0x110($sp)
/*  f0ad8b8:	c7a400f8 */ 	lwc1	$f4,0xf8($sp)
/*  f0ad8bc:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0ad8c0:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f0ad8c4:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0ad8c8:	440b4000 */ 	mfc1	$t3,$f8
/*  f0ad8cc:	00000000 */ 	nop
/*  f0ad8d0:	a60b0056 */ 	sh	$t3,0x56($s0)
/*  f0ad8d4:	c7aa0114 */ 	lwc1	$f10,0x114($sp)
/*  f0ad8d8:	c7a400fc */ 	lwc1	$f4,0xfc($sp)
/*  f0ad8dc:	46005182 */ 	mul.s	$f6,$f10,$f0
/*  f0ad8e0:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0ad8e4:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0ad8e8:	440f5000 */ 	mfc1	$t7,$f10
/*  f0ad8ec:	00000000 */ 	nop
/*  f0ad8f0:	a60f0058 */ 	sh	$t7,0x58($s0)
/*  f0ad8f4:	8c6a0000 */ 	lw	$t2,0x0($v1)
/*  f0ad8f8:	914d0004 */ 	lbu	$t5,0x4($t2)
/*  f0ad8fc:	a600005e */ 	sh	$zero,0x5e($s0)
/*  f0ad900:	a200005b */ 	sb	$zero,0x5b($s0)
/*  f0ad904:	000dc140 */ 	sll	$t8,$t5,0x5
/*  f0ad908:	a618005c */ 	sh	$t8,0x5c($s0)
/*  f0ad90c:	8fa90190 */ 	lw	$t1,0x190($sp)
.L0f0ad910:
/*  f0ad910:	3c0cb600 */ 	lui	$t4,0xb600
/*  f0ad914:	240b2000 */ 	addiu	$t3,$zero,0x2000
/*  f0ad918:	25390008 */ 	addiu	$t9,$t1,0x8
/*  f0ad91c:	afb90190 */ 	sw	$t9,0x190($sp)
/*  f0ad920:	ad2b0004 */ 	sw	$t3,0x4($t1)
/*  f0ad924:	ad2c0000 */ 	sw	$t4,0x0($t1)
/*  f0ad928:	8fae0190 */ 	lw	$t6,0x190($sp)
/*  f0ad92c:	3c0a0102 */ 	lui	$t2,0x102
/*  f0ad930:	354a0040 */ 	ori	$t2,$t2,0x40
/*  f0ad934:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0ad938:	afaf0190 */ 	sw	$t7,0x190($sp)
/*  f0ad93c:	adca0000 */ 	sw	$t2,0x0($t6)
/*  f0ad940:	8fa40188 */ 	lw	$a0,0x188($sp)
/*  f0ad944:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0ad948:	afae009c */ 	sw	$t6,0x9c($sp)
/*  f0ad94c:	8fa7009c */ 	lw	$a3,0x9c($sp)
/*  f0ad950:	3c09ba00 */ 	lui	$t1,0xba00
/*  f0ad954:	35291402 */ 	ori	$t1,$t1,0x1402
/*  f0ad958:	ace20004 */ 	sw	$v0,0x4($a3)
/*  f0ad95c:	8fad0190 */ 	lw	$t5,0x190($sp)
/*  f0ad960:	3c0bba00 */ 	lui	$t3,0xba00
/*  f0ad964:	356b0602 */ 	ori	$t3,$t3,0x602
/*  f0ad968:	25b80008 */ 	addiu	$t8,$t5,0x8
/*  f0ad96c:	afb80190 */ 	sw	$t8,0x190($sp)
/*  f0ad970:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f0ad974:	ada90000 */ 	sw	$t1,0x0($t5)
/*  f0ad978:	8fb90190 */ 	lw	$t9,0x190($sp)
/*  f0ad97c:	240e00c0 */ 	addiu	$t6,$zero,0xc0
/*  f0ad980:	3c0db900 */ 	lui	$t5,0xb900
/*  f0ad984:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f0ad988:	afac0190 */ 	sw	$t4,0x190($sp)
/*  f0ad98c:	af2e0004 */ 	sw	$t6,0x4($t9)
/*  f0ad990:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f0ad994:	8faf0190 */ 	lw	$t7,0x190($sp)
/*  f0ad998:	3c180050 */ 	lui	$t8,0x50
/*  f0ad99c:	371849d8 */ 	ori	$t8,$t8,0x49d8
/*  f0ad9a0:	25ea0008 */ 	addiu	$t2,$t7,0x8
/*  f0ad9a4:	afaa0190 */ 	sw	$t2,0x190($sp)
/*  f0ad9a8:	35ad031d */ 	ori	$t5,$t5,0x31d
/*  f0ad9ac:	aded0000 */ 	sw	$t5,0x0($t7)
/*  f0ad9b0:	adf80004 */ 	sw	$t8,0x4($t7)
/*  f0ad9b4:	8fa90190 */ 	lw	$t1,0x190($sp)
/*  f0ad9b8:	3c0cb900 */ 	lui	$t4,0xb900
/*  f0ad9bc:	358c0002 */ 	ori	$t4,$t4,0x2
/*  f0ad9c0:	25390008 */ 	addiu	$t9,$t1,0x8
/*  f0ad9c4:	afb90190 */ 	sw	$t9,0x190($sp)
/*  f0ad9c8:	ad200004 */ 	sw	$zero,0x4($t1)
/*  f0ad9cc:	ad2c0000 */ 	sw	$t4,0x0($t1)
/*  f0ad9d0:	8fab0190 */ 	lw	$t3,0x190($sp)
/*  f0ad9d4:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0ad9d8:	35ef1001 */ 	ori	$t7,$t7,0x1001
/*  f0ad9dc:	256e0008 */ 	addiu	$t6,$t3,0x8
/*  f0ad9e0:	afae0190 */ 	sw	$t6,0x190($sp)
/*  f0ad9e4:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f0ad9e8:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f0ad9ec:	8faa0190 */ 	lw	$t2,0x190($sp)
/*  f0ad9f0:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0ad9f4:	37180903 */ 	ori	$t8,$t8,0x903
/*  f0ad9f8:	254d0008 */ 	addiu	$t5,$t2,0x8
/*  f0ad9fc:	afad0190 */ 	sw	$t5,0x190($sp)
/*  f0ada00:	24090c00 */ 	addiu	$t1,$zero,0xc00
/*  f0ada04:	ad490004 */ 	sw	$t1,0x4($t2)
/*  f0ada08:	ad580000 */ 	sw	$t8,0x0($t2)
/*  f0ada0c:	8fb90190 */ 	lw	$t9,0x190($sp)
/*  f0ada10:	3c0bfc50 */ 	lui	$t3,0xfc50
/*  f0ada14:	3c0e4432 */ 	lui	$t6,0x4432
/*  f0ada18:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f0ada1c:	afac0190 */ 	sw	$t4,0x190($sp)
/*  f0ada20:	35ce7f3f */ 	ori	$t6,$t6,0x7f3f
/*  f0ada24:	356b98a1 */ 	ori	$t3,$t3,0x98a1
/*  f0ada28:	af2b0000 */ 	sw	$t3,0x0($t9)
/*  f0ada2c:	af2e0004 */ 	sw	$t6,0x4($t9)
/*  f0ada30:	8faf0190 */ 	lw	$t7,0x190($sp)
/*  f0ada34:	3c0d0700 */ 	lui	$t5,0x700
/*  f0ada38:	35ad0004 */ 	ori	$t5,$t5,0x4
/*  f0ada3c:	25ea0008 */ 	addiu	$t2,$t7,0x8
/*  f0ada40:	afaa0190 */ 	sw	$t2,0x190($sp)
/*  f0ada44:	aded0000 */ 	sw	$t5,0x0($t7)
/*  f0ada48:	8fa40144 */ 	lw	$a0,0x144($sp)
/*  f0ada4c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0ada50:	afaf007c */ 	sw	$t7,0x7c($sp)
/*  f0ada54:	8fa5007c */ 	lw	$a1,0x7c($sp)
/*  f0ada58:	2401001d */ 	addiu	$at,$zero,0x1d
/*  f0ada5c:	27a40190 */ 	addiu	$a0,$sp,0x190
/*  f0ada60:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0ada64:	82380001 */ 	lb	$t8,0x1($s1)
/*  f0ada68:	8fa70198 */ 	lw	$a3,0x198($sp)
/*  f0ada6c:	8fa500ec */ 	lw	$a1,0xec($sp)
/*  f0ada70:	17010033 */ 	bne	$t8,$at,.L0f0adb40
/*  f0ada74:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f0ada78:	27b10190 */ 	addiu	$s1,$sp,0x190
/*  f0ada7c:	3c05800b */ 	lui	$a1,%hi(g_TexGroup03Configs)
/*  f0ada80:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f0ada84:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0ada88:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0ada8c:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0ada90:	8ca5b57c */ 	lw	$a1,%lo(g_TexGroup03Configs)($a1)
/*  f0ada94:	02202025 */ 	or	$a0,$s1,$zero
/*  f0ada98:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f0ada9c:	8fa70198 */ 	lw	$a3,0x198($sp)
/*  f0adaa0:	0fc2ce70 */ 	jal	texSelect
/*  f0adaa4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0adaa8:	8fac0190 */ 	lw	$t4,0x190($sp)
/*  f0adaac:	3c0e0470 */ 	lui	$t6,0x470
/*  f0adab0:	35ce0060 */ 	ori	$t6,$t6,0x60
/*  f0adab4:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f0adab8:	afab0190 */ 	sw	$t3,0x190($sp)
/*  f0adabc:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f0adac0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0adac4:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0adac8:	afac0078 */ 	sw	$t4,0x78($sp)
/*  f0adacc:	8fa80078 */ 	lw	$t0,0x78($sp)
/*  f0adad0:	3c0db100 */ 	lui	$t5,0xb100
/*  f0adad4:	35ad0076 */ 	ori	$t5,$t5,0x76
/*  f0adad8:	ad020004 */ 	sw	$v0,0x4($t0)
/*  f0adadc:	8faf0190 */ 	lw	$t7,0x190($sp)
/*  f0adae0:	24185454 */ 	addiu	$t8,$zero,0x5454
/*  f0adae4:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f0adae8:	25ea0008 */ 	addiu	$t2,$t7,0x8
/*  f0adaec:	afaa0190 */ 	sw	$t2,0x190($sp)
/*  f0adaf0:	adf80004 */ 	sw	$t8,0x4($t7)
/*  f0adaf4:	aded0000 */ 	sw	$t5,0x0($t7)
/*  f0adaf8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0adafc:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0adb00:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0adb04:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0adb08:	8fa70198 */ 	lw	$a3,0x198($sp)
/*  f0adb0c:	8fa500ec */ 	lw	$a1,0xec($sp)
/*  f0adb10:	02202025 */ 	or	$a0,$s1,$zero
/*  f0adb14:	0fc2ce70 */ 	jal	texSelect
/*  f0adb18:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f0adb1c:	8fac0190 */ 	lw	$t4,0x190($sp)
/*  f0adb20:	3c0eb100 */ 	lui	$t6,0xb100
/*  f0adb24:	35ce0013 */ 	ori	$t6,$t6,0x13
/*  f0adb28:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f0adb2c:	afab0190 */ 	sw	$t3,0x190($sp)
/*  f0adb30:	240f3020 */ 	addiu	$t7,$zero,0x3020
/*  f0adb34:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f0adb38:	1000001a */ 	b	.L0f0adba4
/*  f0adb3c:	ad8e0000 */ 	sw	$t6,0x0($t4)
.L0f0adb40:
/*  f0adb40:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f0adb44:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0adb48:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0adb4c:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0adb50:	0fc2ce70 */ 	jal	texSelect
/*  f0adb54:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0adb58:	8fb80190 */ 	lw	$t8,0x190($sp)
/*  f0adb5c:	3c190430 */ 	lui	$t9,0x430
/*  f0adb60:	37390030 */ 	ori	$t9,$t9,0x30
/*  f0adb64:	27090008 */ 	addiu	$t1,$t8,0x8
/*  f0adb68:	afa90190 */ 	sw	$t1,0x190($sp)
/*  f0adb6c:	af190000 */ 	sw	$t9,0x0($t8)
/*  f0adb70:	02002025 */ 	or	$a0,$s0,$zero
/*  f0adb74:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0adb78:	afb8006c */ 	sw	$t8,0x6c($sp)
/*  f0adb7c:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f0adb80:	3c0eb100 */ 	lui	$t6,0xb100
/*  f0adb84:	35ce0013 */ 	ori	$t6,$t6,0x13
/*  f0adb88:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0adb8c:	8fac0190 */ 	lw	$t4,0x190($sp)
/*  f0adb90:	240f3020 */ 	addiu	$t7,$zero,0x3020
/*  f0adb94:	258b0008 */ 	addiu	$t3,$t4,0x8
/*  f0adb98:	afab0190 */ 	sw	$t3,0x190($sp)
/*  f0adb9c:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f0adba0:	ad8e0000 */ 	sw	$t6,0x0($t4)
.L0f0adba4:
/*  f0adba4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0adba8:
/*  f0adba8:	8fa20190 */ 	lw	$v0,0x190($sp)
/*  f0adbac:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f0adbb0:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f0adbb4:	03e00008 */ 	jr	$ra
/*  f0adbb8:	27bd0190 */ 	addiu	$sp,$sp,0x190
);

// Mismatch: Regalloc and some swapped loads and stores
// - After gfxAllocateMatrix, goal skips f0 and uses f12
// - Goal reuses f2 in neg.s instruction for cam0f0b4e68's a1
// - Calculation of spcc near sp100 is reordered
//Gfx *beamRender(Gfx *gdl, struct beam *beam, bool arg2, u8 arg3)
//{
//	u32 stack;
//	Mtxf *sp188;
//	Mtxf sp148;
//
//	if (arg3 < 5 && beam->age >= 0) {
//		struct colour *colours = gfxAllocateColours(1); // 144
//		struct coord sp138;
//		struct coord *campos = &g_Vars.currentplayer->cam_pos; // 134
//		f32 sp130;
//		f32 sp12c = beam->mindist;
//		struct gfxvtx *vertices;
//		f32 sp124 = beam->dist;
//		struct coord sp118;
//		struct coord sp10c;
//		struct coord sp100 = {0, 0, 0};
//		struct coord spf4 = {0, 0, 0};
//		f32 spf0 = 1.4142f;
//		struct textureconfig *texconfig = &g_TexBeamConfigs[arg3]; // ec
//		s32 i;
//		Mtxf *worldtoscreenmtx = camGetWorldToScreenMtxf(); // e4
//		s32 j;
//		u32 stack1;
//		s32 spd8;
//		struct coord spcc;
//		u32 stack2;
//		f32 spc0[2];
//		f32 spb8[2];
//		f32 f14;
//		f32 f16;
//		f32 f18;
//		f32 spa8;
//		f32 spa4;
//
//		switch (beam->weaponnum) {
//		case WEAPON_CYCLONE:
//			texconfig = &g_TexBeamConfigs[1];
//			break;
//		case WEAPON_TRANQUILIZER:
//			texconfig = &g_TexBeamConfigs[3];
//			break;
//		case WEAPON_MAULER:
//		case WEAPON_PHOENIX:
//		case WEAPON_CALLISTO:
//		case WEAPON_REAPER:
//		case WEAPON_FARSIGHT:
//			texconfig = &g_TexBeamConfigs[4];
//			break;
//		}
//
//		if (beam->weaponnum == -1 || beam->weaponnum == WEAPON_CYCLONE) {
//			colours[0].word = 0xffffff7f;
//		} else {
//			colours[0].word = 0xffffffff;
//		}
//
//		if (beam->weaponnum == WEAPON_LASER) {
//			// Laser primary
//			sp130 = 50.0f;
//			texconfig = &g_TexLaserConfigs[0];
//		} else if (beam->weaponnum == -2) {
//			// Laser secondary
//			sp130 = 10.0f;
//			texconfig = &g_TexLaserConfigs[0];
//
//			colours[0].a = 150 + (random() % 50);
//
//			if ((random() % 5) == 0) {
//				colours[0].r = colours[0].g = 255 - (random() % 100);
//			}
//		} else {
//			sp130 = 30.0f;
//		}
//
//		if (beam->weaponnum <= -3) {
//			// Mauler
//			sp130 = sp130 * ((beam->weaponnum + 3) * 2.0f + 1.0f);
//			texconfig = &g_TexBeamConfigs[4];
//		}
//
//		sp138.f[0] = beam->from.f[0];
//		sp138.f[1] = beam->from.f[1];
//		sp138.f[2] = beam->from.f[2];
//
//		if (sp124 > 0.0f) {
//			sp138.f[0] += sp124 * beam->dir.f[0];
//			sp138.f[1] += sp124 * beam->dir.f[1];
//			sp138.f[2] += sp124 * beam->dir.f[2];
//		} else {
//			sp12c += sp124;
//			sp124 = 0.0f;
//		}
//
//		if (sp124 + sp12c > beam->maxdist) {
//			sp12c = beam->maxdist - sp124;
//		}
//
//		sp10c.f[0] = (beam->dir.f[1] * (campos->f[2] - (sp138.f[2] + sp12c * beam->dir.f[2]))) - (beam->dir.f[2] * (campos->f[1] - (sp138.f[1] + sp12c * beam->dir.f[1])));
//		sp10c.f[1] = (beam->dir.f[2] * (campos->f[0] - (sp138.f[0] + sp12c * beam->dir.f[0]))) - (beam->dir.f[0] * (campos->f[2] - (sp138.f[2] + sp12c * beam->dir.f[2])));
//		sp10c.f[2] = (beam->dir.f[0] * (campos->f[1] - (sp138.f[1] + sp12c * beam->dir.f[1]))) - (beam->dir.f[1] * (campos->f[0] - (sp138.f[0] + sp12c * beam->dir.f[0])));
//
//		if (sp10c.f[0] != 0.0f || sp10c.f[1] != 0.0f || sp10c.f[2] != 0.0f) {
//			guNormalize(&sp10c.f[0], &sp10c.f[1], &sp10c.f[2]);
//
//			sp10c.f[0] *= sp130;
//			sp10c.f[1] *= sp130;
//			sp10c.f[2] *= sp130;
//		} else {
//			sp10c.f[0] = 0.0f;
//			sp10c.f[1] = sp130;
//			sp10c.f[2] = 0.0f;
//		}
//
//		sp118.f[0] = beam->dir.f[1] * sp10c.f[2] - beam->dir.f[2] * sp10c.f[1];
//		sp118.f[1] = beam->dir.f[2] * sp10c.f[0] - beam->dir.f[0] * sp10c.f[2];
//		sp118.f[2] = beam->dir.f[0] * sp10c.f[1] - beam->dir.f[1] * sp10c.f[0];
//
//		guNormalize(&sp118.f[0], &sp118.f[1], &sp118.f[2]);
//
//		sp118.f[0] *= sp130;
//		sp118.f[1] *= sp130;
//		sp118.f[2] *= sp130;
//
//		if (beam->weaponnum == WEAPON_LASER) {
//			vertices = gfxAllocateVertices(8);
//		} else {
//			vertices = gfxAllocateVertices(4);
//		}
//
//		sp188 = gfxAllocateMatrix();
//
//		if (sp12c > 0.0f
//				&& sp138.f[0] > -32000.0f && sp138.f[0] < 32000.0f
//				&& sp138.f[1] > -32000.0f && sp138.f[1] < 32000.0f
//				&& sp138.f[2] > -32000.0f && sp138.f[2] < 32000.0f) {
//			spd8 = true;
//			mtx4LoadTranslation(&sp138, &sp148);
//			mtx00015f04(0.1f, &sp148);
//			mtx00015be0(worldtoscreenmtx, &sp148);
//
//			for (i = 0; i < 4; i++) {
//				for (j = 0; j < 4; j++) {
//					if (sp148.m[i][j] < -32000.0f || sp148.m[i][j] > 32000.0f) {
//						spd8 = false;
//						break;
//					}
//				}
//			}
//
//			if (spd8) {
//				mtx00016054(&sp148, sp188);
//
//				if (beam->weaponnum);
//
//				if (beam->weaponnum == -2 && PLAYERCOUNT() == 1) {
//					spcc.f[0] = sp138.f[0] + beam->dir.f[0] * sp12c;
//					spcc.f[1] = sp138.f[1] + beam->dir.f[1] * sp12c;
//					spcc.f[2] = sp138.f[2] + beam->dir.f[2] * sp12c;
//
//					mtx4TransformVecInPlace(worldtoscreenmtx, &spcc);
//
//					spb8[0] = spb8[1] = sp130 / 10.0f;
//
//					cam0f0b4e68(spb8, -spcc.f[2], spc0);
//
//					if (spc0[0] < 2.0f) {
//						spcc.f[0] *= spc0[0] * 0.5f;
//						spcc.f[1] *= spc0[0] * 0.5f;
//						spcc.f[2] *= spc0[0] * 0.5f;
//					}
//
//					mtx4TransformVecInPlace(camGetProjectionMtxF(), &spcc);
//
//					spcc.f[0] -= sp138.f[0];
//					spcc.f[1] -= sp138.f[1];
//					spcc.f[2] -= sp138.f[2];
//
//					if (1);
//
//					sp100.f[0] = spcc.f[0] * 10.0f;
//					sp100.f[1] = spcc.f[1] * 10.0f;
//					sp100.f[2] = spcc.f[2] * 10.0f;
//				} else {
//					sp100.f[0] = beam->dir.f[0] * (sp12c * 10.0f);
//					sp100.f[1] = beam->dir.f[1] * (sp12c * 10.0f);
//					sp100.f[2] = beam->dir.f[2] * (sp12c * 10.0f);
//				}
//
//				if (sp100.f[0] > -30000.0f && sp100.f[0] < 30000.0f
//						&& sp100.f[1] > -30000.0f && sp100.f[1] < 30000.0f
//						&& sp100.f[2] > -30000.0f && sp100.f[2] < 30000.0f) {
//					vertices[0].x = sp10c.f[0];
//					vertices[0].y = sp10c.f[1];
//					vertices[0].z = sp10c.f[2];
//					vertices[0].s = texconfig->width * 32;
//					vertices[0].t = 0;
//					vertices[0].colour = 0;
//
//					vertices[1].x = -sp10c.f[0];
//					vertices[1].y = -sp10c.f[1];
//					vertices[1].z = -sp10c.f[2];
//					vertices[1].s = 0;
//					vertices[1].t = 0;
//					vertices[1].colour = 0;
//
//					vertices[2].x = sp100.f[0] + sp10c.f[0] * 0.9f;
//					vertices[2].y = sp100.f[1] + sp10c.f[1] * 0.9f;
//					vertices[2].z = sp100.f[2] + sp10c.f[2] * 0.9f;
//					vertices[2].s = texconfig->width * 32;
//					vertices[2].t = texconfig->height * 32;
//					vertices[2].colour = 0;
//
//					vertices[3].x = sp100.f[0] - sp10c.f[0] * 0.9f;
//					vertices[3].y = sp100.f[1] - sp10c.f[1] * 0.9f;
//					vertices[3].z = sp100.f[2] - sp10c.f[2] * 0.9f;
//					vertices[3].s = 0;
//					vertices[3].t = texconfig->height * 32;
//					vertices[3].colour = 0;
//
//					if (beam->weaponnum == WEAPON_LASER) {
//						f14 = campos->f[0] - sp138.f[0];
//						f16 = campos->f[1] - sp138.f[1];
//						f18 = campos->f[2] - sp138.f[2];
//
//						spa8 = f14 * f14 + f16 * f16 + f18 * f18;
//
//						f14 = campos->f[0] - (sp138.f[0] + beam->dir.f[0] * sp12c);
//						f16 = campos->f[1] - (sp138.f[1] + beam->dir.f[1] * sp12c);
//						f18 = campos->f[2] - (sp138.f[2] + beam->dir.f[2] * sp12c);
//
//						spa4 = f14 * f14 + f16 * f16 + f18 * f18;
//
//						if (spa4 < spa8) {
//							spf4.f[0] = sp100.f[0];
//							spf4.f[1] = sp100.f[1];
//							spf4.f[2] = sp100.f[2];
//							spf0 *= 0.9f;
//						}
//
//						vertices[4].x = spf4.f[0] + sp118.f[0] * spf0;
//						vertices[4].y = spf4.f[1] + sp118.f[1] * spf0;
//						vertices[4].z = spf4.f[2] + sp118.f[2] * spf0;
//						vertices[4].s = g_TexGroup03Configs[0].width * 32;
//						vertices[4].t = g_TexGroup03Configs[0].height * 32;
//						vertices[4].colour = 0;
//
//						vertices[5].x = spf4.f[0] - sp118.f[0] * spf0;
//						vertices[5].y = spf4.f[1] - sp118.f[1] * spf0;
//						vertices[5].z = spf4.f[2] - sp118.f[2] * spf0;
//						vertices[5].s = 0;
//						vertices[5].t = 0;
//						vertices[5].colour = 0;
//
//						vertices[6].x = spf4.f[0] + sp10c.f[0] * spf0;
//						vertices[6].y = spf4.f[1] + sp10c.f[1] * spf0;
//						vertices[6].z = spf4.f[2] + sp10c.f[2] * spf0;
//						vertices[6].s = 0;
//						vertices[6].t = g_TexGroup03Configs[0].height * 32;
//						vertices[6].colour = 0;
//
//						vertices[7].x = spf4.f[0] - sp10c.f[0] * spf0;
//						vertices[7].y = spf4.f[1] - sp10c.f[1] * spf0;
//						vertices[7].z = spf4.f[2] - sp10c.f[2] * spf0;
//						vertices[7].s = g_TexGroup03Configs[0].width * 32;
//						vertices[7].t = 0;
//						vertices[7].colour = 0;
//					}
//
//					gSPClearGeometryMode(gdl++, G_CULL_BACK);
//					gSPMatrix(gdl++, osVirtualToPhysical(sp188), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
//					gDPSetCycleType(gdl++, G_CYC_1CYCLE);
//					gDPSetColorDither(gdl++, G_CD_DISABLE);
//					gDPSetRenderMode(gdl++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
//					gDPSetAlphaCompare(gdl++, G_AC_NONE);
//					gDPSetTextureLOD(gdl++, G_TL_TILE);
//					gDPSetTextureConvert(gdl++, G_TC_FILT);
//					gDPSetCombineMode(gdl++, G_CC_BLENDIA, G_CC_BLENDIA);
//					gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 1);
//
//					if (beam->weaponnum == WEAPON_LASER) {
//						texSelect(&gdl, &g_TexGroup03Configs[0], 4, arg2, 2, true, NULL);
//
//						gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 8);
//						gDPTri2(gdl++, 4, 5, 6, 4, 5, 7);
//
//						texSelect(&gdl, texconfig, 4, arg2, 2, true, NULL);
//
//						gDPTri2(gdl++, 0, 2, 3, 0, 3, 1);
//					} else {
//						texSelect(&gdl, texconfig, 4, arg2, 2, true, NULL);
//
//						gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 4);
//						gDPTri2(gdl++, 0, 2, 3, 0, 3, 1);
//					}
//				}
//			}
//		}
//	}
//
//	return gdl;
//}

void beamTick(struct beam *beam)
{
	if (beam->age >= 0) {
		if (beam->weaponnum == -2) {
			beam->age++;

			if (beam->age > 1) {
				beam->age = -1;
			}
		} else {
			if (g_Vars.lvupdate240 <= 8) {
				// Not lagging
				beam->dist += beam->speed * g_Vars.lvupdate240f;
			} else {
				// Lagging
				beam->dist += beam->speed * (2 + RANDOMFRAC() * 0.5f);
			}

			if (beam->dist >= beam->maxdist) {
				beam->age = -1;
			}
		}
	}
}

bool g_CasingsActive = false;

struct casing *casingCreate(struct modelfiledata *modeldef, Mtxf *mtx)
{
	s32 i;
	s32 j;
	f32 rot[3][3];
	struct casing *casing = g_Casings;
	struct casing *end = g_Casings + ARRAYCOUNT(g_Casings);
	u32 stack;

	while (casing < end && casing->modeldef != NULL) {
		casing++;
	}

	if (casing < end) {
		casing->modeldef = modeldef;
		casing->pos.x = mtx->m[3][0];
		casing->pos.y = mtx->m[3][1];
		casing->pos.z = mtx->m[3][2];

		mtx4ToMtx3(mtx, rot);

		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				casing->rot[i][j] = rot[i][j] * 4096.0f;
			}
		}

		g_CasingsActive = true;

		return casing;
	}

	return NULL;
}

void casingCreateForHand(s32 handnum, f32 ground, Mtxf *mtx)
{
	f32 oldyspeed;
	struct casing *casing = NULL;
	struct player *player = g_Vars.currentplayer;
	s32 i;
	s32 j;
	Mtxf spec;
	f32 spc8[3][3];
	s32 weaponnum = bgunGetWeaponNum(handnum);
	s32 casingtype = -1;
	struct weaponfunc *func = gsetGetWeaponFunction2(&player->hands[handnum].gset);
	struct weapon *weapondef = weaponFindById(player->gunctrl.weaponnum);
	struct weaponfunc_shoot *shootfunc = NULL;
	struct modelfiledata *modeldef;

	if ((func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
		shootfunc = (struct weaponfunc_shoot *)func;
	}

	if (func->ammoindex < 0) {
		return;
	}

	if (weapondef != NULL && shootfunc != NULL) {
		if (weapondef->ammos[func->ammoindex] != NULL) {
			casingtype = weapondef->ammos[func->ammoindex]->casingeject;
		}
	}

	if (casingtype < 0) {
		return;
	}

	if (PLAYERCOUNT() >= 2) {
		return;
	}

	mtx4Copy(mtx, &spec);

	modeldef = bgunGetCartModeldef();

	if (modeldef != NULL) {
		casing = casingCreate(modeldef, &spec);
	}

	if (casing != NULL) {
		struct coord spa4 = {0, 0, 0};
		Mtxf sp64;
		u32 magic = 0x15aca6;
		u32 sp5c;
		u32 stack[3];
		u32 sp4c;
		f32 newyspeed;
		f32 f0;

		casing->ground = ground;

		if (weaponnum == WEAPON_PP9I || weaponnum == WEAPON_CC13
				|| weaponnum == WEAPON_FALCON2 || weaponnum == WEAPON_MAGSEC4) {
			casing->speed.x = -(RANDOMFRAC() * 0.5333333f * 0.0625f + 0.5333333f);
			casing->speed.y = RANDOMFRAC() * 2.5f * 0.0625f + 2.5f;
			casing->speed.z = 0.0f;

			mtx4RotateVecInPlace(mtx, &casing->speed);

			spa4.x = 2.0f * RANDOMFRAC() * M_BADTAU * 0.0625f - 0.39263657f;
			spa4.y = 2.0f * RANDOMFRAC() * M_BADTAU * 0.0625f - 0.39263657f;
			spa4.z = 2.0f * RANDOMFRAC() * M_BADTAU * 0.0625f - 0.39263657f;

			mtx4LoadRotation(&spa4, &sp64);
			mtx4ToMtx3(&sp64, spc8);

			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) {
					casing->rotspeed[i][j] = spc8[i][j] * 4096.0f;
				}
			}

			sp5c = ((s32)((random() >> 24) * magic) >> 10) + magic;
			f0 = (random() % sp5c) / PALUP(781250.0f);

			newyspeed = casing->speed.y - f0 * 0.2777778f;

			casing->pos.y += f0 * (casing->speed.y + newyspeed) * 0.5f;
			casing->pos.x += f0 * casing->speed.x;
			casing->pos.z += f0 * casing->speed.z;

			casing->speed.y = newyspeed;

			if (g_Vars.lvupdate240 > 0) {
				casing->speed.x += (player->hands[handnum].posmtx.m[3][0] - player->hands[handnum].prevmtx.m[3][0]) / g_Vars.lvupdate240freal;
				casing->speed.y += (player->hands[handnum].posmtx.m[3][1] - player->hands[handnum].prevmtx.m[3][1]) / g_Vars.lvupdate240freal;
				casing->speed.z += (player->hands[handnum].posmtx.m[3][2] - player->hands[handnum].prevmtx.m[3][2]) / g_Vars.lvupdate240freal;
			}
		} else {
			if (weaponnum == WEAPON_REAPER) {
				casing->speed.x = -(RANDOMFRAC() * 0.41666666f * 0.125f + 0.41666666f);
				casing->speed.y = RANDOMFRAC() * 3.3333333f * 0.125f + 3.3333333f;
			} else {
				casing->speed.x = -((RANDOMFRAC() * 1.4166666f * 0.125f) + 1.4166666f);
				casing->speed.y = RANDOMFRAC() * 1.6666666f * 0.125f + 1.6666666f;
			}

			casing->speed.z = 0.0f;

			if (weaponnum == WEAPON_DY357MAGNUM || weaponnum == WEAPON_DY357LX) {
				casing->speed.x = 0.0f;
				casing->speed.y = 0.0f;
				casing->speed.z = -1.0f;
			}

			mtx4RotateVecInPlace(mtx, &casing->speed);

			if (weaponnum == WEAPON_REAPER) {
				spa4.x = 2.0f * RANDOMFRAC() * M_BADTAU * 0.015625f - 0.09815914f;
				spa4.y = 2.0f * RANDOMFRAC() * M_BADTAU * 0.015625f - 0.09815914f;
				spa4.z = 2.0f * RANDOMFRAC() * M_BADTAU * 0.015625f - 0.09815914f;

				mtx4LoadRotation(&spa4, &sp64);
				mtx4RotateVecInPlace(&sp64, &casing->speed);
			}

			spa4.x = 2.0f * RANDOMFRAC() * M_BADTAU * 0.015625f - 0.09815914f;
			spa4.y = 2.0f * RANDOMFRAC() * M_BADTAU * 0.015625f - 0.09815914f;
			spa4.z = 2.0f * RANDOMFRAC() * M_BADTAU * 0.015625f - 0.09815914f;

			mtx4LoadRotation(&spa4, &sp64);
			mtx4ToMtx3(&sp64, spc8);

			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) {
					casing->rotspeed[i][j] = spc8[i][j] * 4096.0f;
				}
			}

			sp4c = ((s32) ((random() >> 24) * magic) >> 10) + magic;
			f0 = (random() % sp4c) / PALUP(781250.0f);

			newyspeed = casing->speed.y - f0 * 0.2777778f;

			casing->pos.y += f0 * (casing->speed.y + newyspeed) * 0.5f;
			casing->pos.x += f0 * casing->speed.x;
			casing->pos.z += f0 * casing->speed.z;

			casing->speed.y = newyspeed;

			if (g_Vars.lvupdate240 > 0) {
				casing->speed.x += (player->hands[handnum].posmtx.m[3][0] - player->hands[handnum].prevmtx.m[3][0]) / g_Vars.lvupdate240freal;
				casing->speed.y += (player->hands[handnum].posmtx.m[3][1] - player->hands[handnum].prevmtx.m[3][1]) / g_Vars.lvupdate240freal;
				casing->speed.z += (player->hands[handnum].posmtx.m[3][2] - player->hands[handnum].prevmtx.m[3][2]) / g_Vars.lvupdate240freal;
			}
		}
	}
}

void casingRender(struct casing *casing, Gfx **gdlptr)
{
	Gfx *gdl = *gdlptr;
	struct modelfiledata *modeldef = casing->modeldef;
	Mtxf *matrices = gfxAllocate(modeldef->nummatrices * sizeof(Mtxf));
	struct model model;
	struct modelrenderdata renderdata = { NULL, true, 3 };
	Mtxf mtx;
	s32 i;
	s32 j;
	bool render = true;

	modelCalculateRwDataLen(modeldef);
	modelInit(&model, modeldef, NULL, true);

	model.matrices = matrices;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			mtx.m[i][j] = casing->rot[i][j] * (1.0f / 4096.0f);
		}
	}

	mtx.m[3][0] = 0.0f;
	mtx.m[3][1] = 0.0f;
	mtx.m[3][2] = 0.0f;

	mtx.m[0][3] = 0.0f;
	mtx.m[1][3] = 0.0f;
	mtx.m[2][3] = 0.0f;
	mtx.m[3][3] = 1.0f;

	mtx00015f04(0.1000000089407f, &mtx);
	mtx4SetTranslation(&casing->pos, &mtx);
	mtx00015be4(camGetWorldToScreenMtxf(), &mtx, model.matrices);

	// Check if any coordinate is out of range
	for (i = 0; i < 3; i++) {
		if (model.matrices[0].m[3][i] > 30000) {
			render = false;
		} else if (model.matrices[0].m[3][i] < -30000) {
			render = false;
		}
	}

	if (render) {
		renderdata.zbufferenabled = 1;
		renderdata.gdl = gdl;
		renderdata.unk10 = matrices;
		renderdata.unk30 = 4;
		renderdata.envcolour = g_Vars.currentplayer->gunshadecol[0] << 24
			| g_Vars.currentplayer->gunshadecol[1] << 16
			| g_Vars.currentplayer->gunshadecol[2] << 8
			| g_Vars.currentplayer->gunshadecol[3];

		modelRender(&renderdata, &model);

		*gdlptr = renderdata.gdl;

		func0f0c33f0(matrices, modeldef->nummatrices);
	}
}

void casingsRender(Gfx **gdlptr)
{
	if (g_CasingsActive) {
		struct casing *end = g_Casings + ARRAYCOUNT(g_Casings);
		struct casing *casing = g_Casings;

		while (casing < end) {
			if (casing->modeldef) {
				casingRender(casing, gdlptr);
			}

			casing++;
		}
	}
}

s32 boltbeamFindByProp(struct prop *prop)
{
	s32 result = -1;
	s32 i = 0;

	for (; i < 8 && result == -1; i++) {
		if (g_BoltBeams[i].unk00_prop == prop) {
			result = i;
		}
	}

	return result;
}

s32 boltbeamCreate(struct prop *prop)
{
	s32 beamnum = boltbeamFindByProp((struct prop *) -1);

	if (beamnum >= 0) {
		g_BoltBeams[beamnum].tickmode = BOLTBEAMTICKMODE_MANUAL;
		g_BoltBeams[beamnum].unk00_prop = prop;
	}

	return beamnum;
}

void boltbeamFree(struct prop *prop)
{
	s32 beamnum = boltbeamFindByProp(prop);

	if (beamnum != -1) {
		g_BoltBeams[beamnum].unk00 = -1;
	}
}

void boltbeamSetHeadPos(s32 beamnum, struct coord *pos)
{
	g_BoltBeams[beamnum].headpos.x = pos->x;
	g_BoltBeams[beamnum].headpos.y = pos->y;
	g_BoltBeams[beamnum].headpos.z = pos->z;
}

void boltbeamSetTailPos(s32 beamnum, struct coord *pos)
{
	g_BoltBeams[beamnum].tailpos.x = pos->x;
	g_BoltBeams[beamnum].tailpos.y = pos->y;
	g_BoltBeams[beamnum].tailpos.z = pos->z;
}

void boltbeamIncrementHeadPos(s32 beamnum, f32 arg1, bool arg2)
{
	f32 dist;

#define DIFF(i) (g_BoltBeams[beamnum].tailpos.f[i] - g_BoltBeams[beamnum].headpos.f[i])
#define SQDIFF(i) (DIFF(i) * DIFF(i))

	dist = sqrtf(SQDIFF(0) + SQDIFF(1) + SQDIFF(2));

	if (dist > arg1 && !arg2) {
		f32 tmp[3];

		if (1);

		tmp[0] = (g_BoltBeams[beamnum].headpos.f[0] - g_BoltBeams[beamnum].tailpos.f[0]) / dist;
		tmp[1] = (g_BoltBeams[beamnum].headpos.f[1] - g_BoltBeams[beamnum].tailpos.f[1]) / dist;
		tmp[2] = (g_BoltBeams[beamnum].headpos.f[2] - g_BoltBeams[beamnum].tailpos.f[2]) / dist;

		g_BoltBeams[beamnum].headpos.f[0] = g_BoltBeams[beamnum].tailpos.f[0] + tmp[0] * arg1;
		g_BoltBeams[beamnum].headpos.f[1] = g_BoltBeams[beamnum].tailpos.f[1] + tmp[1] * arg1;
		g_BoltBeams[beamnum].headpos.f[2] = g_BoltBeams[beamnum].tailpos.f[2] + tmp[2] * arg1;
	}
}

void boltbeamSetAutomatic(s32 beamnum, f32 speed)
{
	g_BoltBeams[beamnum].tickmode = BOLTBEAMTICKMODE_AUTOMATIC;
	g_BoltBeams[beamnum].unk00 = 0;
	g_BoltBeams[beamnum].speed = speed;
}

Gfx *boltbeamsRender(Gfx *gdl)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_BoltBeams); i++) {
		if (g_BoltBeams[i].unk00 != -1) {
			gdl = beamRenderGeneric(gdl, g_TexLaserConfigs, 1, &g_BoltBeams[i].headpos, 0xafafff00, 2, &g_BoltBeams[i].tailpos, 0xafafff7f);
		}
	}

	return gdl;
}

void boltbeamsTick(void)
{
	s32 i;

	for (i = 0; i < 8; i++) {
		if (g_BoltBeams[i].unk00 != -1 && g_BoltBeams[i].tickmode == BOLTBEAMTICKMODE_AUTOMATIC) {
			f32 length = sqrtf(
					(g_BoltBeams[i].tailpos.f[0] - g_BoltBeams[i].headpos.f[0]) * (g_BoltBeams[i].tailpos.f[0] - g_BoltBeams[i].headpos.f[0]) +
					(g_BoltBeams[i].tailpos.f[1] - g_BoltBeams[i].headpos.f[1]) * (g_BoltBeams[i].tailpos.f[1] - g_BoltBeams[i].headpos.f[1]) +
					(g_BoltBeams[i].tailpos.f[2] - g_BoltBeams[i].headpos.f[2]) * (g_BoltBeams[i].tailpos.f[2] - g_BoltBeams[i].headpos.f[2]));

			length -= g_BoltBeams[i].speed * LVUPDATE240FREAL() / 60.0f;

			if (length < 0) {
				g_BoltBeams[i].unk00 = -1;
			} else {
				boltbeamIncrementHeadPos(i, length, false);
			}
		}
	}
}

/**
 * Return true if a lasersight with the given ID exists, or false if not.
 *
 * Additionally, populate the index pointer with the index of the lasersight
 * if it exists, or any free slot if it doesn't.
 */
bool lasersightExists(s32 id, s32 *index)
{
	s32 fallback = -1;
	s32 exact = -1;
	s32 i = 0;

	for (; i < 4 && exact == -1; i++) {
		if (g_LaserSights[i].id == id) {
			exact = i;
		}

		if (g_LaserSights[i].id == -1) {
			fallback = i;
		}
	}

	if (exact == -1) {
		*index = fallback;
		return false;
	}

	*index = exact;
	return true;
}

u32 var80070574 = 0x00000320;
u32 var80070578 = 0x00001b58;
u32 var8007057c = 0x00002328;
u32 var80070580 = 0x00000018;
u32 var80070584 = 0x00000006;
u32 var80070588 = 0x00000000;
u32 var8007058c = 0x00000000;

GLOBAL_ASM(
glabel lasersightRenderDot
.late_rodata
glabel var7f1acd70
.word 0x3e4ccccd
glabel var7f1acd74
.word 0xb58637bd
glabel var7f1acd78
.word 0x33d6bf95
glabel var7f1acd7c
.word 0x3dcccccd
glabel var7f1acd80
.word 0xb58637bd
glabel var7f1acd84
.word 0x33d6bf95
glabel var7f1acd88
.word 0xb58637bd
glabel var7f1acd8c
.word 0x33d6bf95
.text
/*  f0af158:	27bdfe00 */ 	addiu	$sp,$sp,-512
/*  f0af15c:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f0af160:	afa40200 */ 	sw	$a0,0x200($sp)
/*  f0af164:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f0af168:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f0af16c:	3c047f1b */ 	lui	$a0,%hi(var7f1acc10)
/*  f0af170:	3c058007 */ 	lui	$a1,%hi(var80070574)
/*  f0af174:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f0af178:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f0af17c:	f7be0050 */ 	sdc1	$f30,0x50($sp)
/*  f0af180:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f0af184:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f0af188:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f0af18c:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f0af190:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f0af194:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f0af198:	24a50574 */ 	addiu	$a1,$a1,%lo(var80070574)
/*  f0af19c:	0c0036cc */ 	jal	mainOverrideVariable
/*  f0af1a0:	2484cc10 */ 	addiu	$a0,$a0,%lo(var7f1acc10)
/*  f0af1a4:	3c047f1b */ 	lui	$a0,%hi(var7f1acc14)
/*  f0af1a8:	3c058007 */ 	lui	$a1,%hi(var80070578)
/*  f0af1ac:	24a50578 */ 	addiu	$a1,$a1,%lo(var80070578)
/*  f0af1b0:	0c0036cc */ 	jal	mainOverrideVariable
/*  f0af1b4:	2484cc14 */ 	addiu	$a0,$a0,%lo(var7f1acc14)
/*  f0af1b8:	3c047f1b */ 	lui	$a0,%hi(var7f1acc18)
/*  f0af1bc:	3c058007 */ 	lui	$a1,%hi(var8007057c)
/*  f0af1c0:	24a5057c */ 	addiu	$a1,$a1,%lo(var8007057c)
/*  f0af1c4:	0c0036cc */ 	jal	mainOverrideVariable
/*  f0af1c8:	2484cc18 */ 	addiu	$a0,$a0,%lo(var7f1acc18)
/*  f0af1cc:	3c047f1b */ 	lui	$a0,%hi(var7f1acc1c)
/*  f0af1d0:	3c058007 */ 	lui	$a1,%hi(var80070580)
/*  f0af1d4:	24a50580 */ 	addiu	$a1,$a1,%lo(var80070580)
/*  f0af1d8:	0c0036cc */ 	jal	mainOverrideVariable
/*  f0af1dc:	2484cc1c */ 	addiu	$a0,$a0,%lo(var7f1acc1c)
/*  f0af1e0:	3c047f1b */ 	lui	$a0,%hi(var7f1acc20)
/*  f0af1e4:	3c058007 */ 	lui	$a1,%hi(var80070584)
/*  f0af1e8:	24a50584 */ 	addiu	$a1,$a1,%lo(var80070584)
/*  f0af1ec:	0c0036cc */ 	jal	mainOverrideVariable
/*  f0af1f0:	2484cc20 */ 	addiu	$a0,$a0,%lo(var7f1acc20)
/*  f0af1f4:	8fae0200 */ 	lw	$t6,0x200($sp)
/*  f0af1f8:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0af1fc:	37181402 */ 	ori	$t8,$t8,0x1402
/*  f0af200:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0af204:	afaf0200 */ 	sw	$t7,0x200($sp)
/*  f0af208:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0af20c:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0af210:	8fb90200 */ 	lw	$t9,0x200($sp)
/*  f0af214:	3c09ba00 */ 	lui	$t1,0xba00
/*  f0af218:	35290c02 */ 	ori	$t1,$t1,0xc02
/*  f0af21c:	27280008 */ 	addiu	$t0,$t9,0x8
/*  f0af220:	afa80200 */ 	sw	$t0,0x200($sp)
/*  f0af224:	240a2000 */ 	addiu	$t2,$zero,0x2000
/*  f0af228:	af2a0004 */ 	sw	$t2,0x4($t9)
/*  f0af22c:	af290000 */ 	sw	$t1,0x0($t9)
/*  f0af230:	8fab0200 */ 	lw	$t3,0x200($sp)
/*  f0af234:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0af238:	35ad1301 */ 	ori	$t5,$t5,0x1301
/*  f0af23c:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f0af240:	afac0200 */ 	sw	$t4,0x200($sp)
/*  f0af244:	3c0e0008 */ 	lui	$t6,0x8
/*  f0af248:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f0af24c:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f0af250:	8faf0200 */ 	lw	$t7,0x200($sp)
/*  f0af254:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0af258:	37390602 */ 	ori	$t9,$t9,0x602
/*  f0af25c:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0af260:	afb80200 */ 	sw	$t8,0x200($sp)
/*  f0af264:	240800c0 */ 	addiu	$t0,$zero,0xc0
/*  f0af268:	ade80004 */ 	sw	$t0,0x4($t7)
/*  f0af26c:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0af270:	8fa90200 */ 	lw	$t1,0x200($sp)
/*  f0af274:	3c0bb900 */ 	lui	$t3,0xb900
/*  f0af278:	3c0c0050 */ 	lui	$t4,0x50
/*  f0af27c:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f0af280:	afaa0200 */ 	sw	$t2,0x200($sp)
/*  f0af284:	358c49d8 */ 	ori	$t4,$t4,0x49d8
/*  f0af288:	356b031d */ 	ori	$t3,$t3,0x31d
/*  f0af28c:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f0af290:	ad2c0004 */ 	sw	$t4,0x4($t1)
/*  f0af294:	8fad0200 */ 	lw	$t5,0x200($sp)
/*  f0af298:	3c0fb900 */ 	lui	$t7,0xb900
/*  f0af29c:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f0af2a0:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0af2a4:	afae0200 */ 	sw	$t6,0x200($sp)
/*  f0af2a8:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f0af2ac:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0af2b0:	8fb80200 */ 	lw	$t8,0x200($sp)
/*  f0af2b4:	3c08ba00 */ 	lui	$t0,0xba00
/*  f0af2b8:	35081001 */ 	ori	$t0,$t0,0x1001
/*  f0af2bc:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0af2c0:	afb90200 */ 	sw	$t9,0x200($sp)
/*  f0af2c4:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0af2c8:	af080000 */ 	sw	$t0,0x0($t8)
/*  f0af2cc:	8fa90200 */ 	lw	$t1,0x200($sp)
/*  f0af2d0:	3c0bba00 */ 	lui	$t3,0xba00
/*  f0af2d4:	356b0903 */ 	ori	$t3,$t3,0x903
/*  f0af2d8:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f0af2dc:	afaa0200 */ 	sw	$t2,0x200($sp)
/*  f0af2e0:	240c0c00 */ 	addiu	$t4,$zero,0xc00
/*  f0af2e4:	ad2c0004 */ 	sw	$t4,0x4($t1)
/*  f0af2e8:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f0af2ec:	8fad0200 */ 	lw	$t5,0x200($sp)
/*  f0af2f0:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0af2f4:	35ef0e02 */ 	ori	$t7,$t7,0xe02
/*  f0af2f8:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0af2fc:	afae0200 */ 	sw	$t6,0x200($sp)
/*  f0af300:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f0af304:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0af308:	8fb80200 */ 	lw	$t8,0x200($sp)
/*  f0af30c:	3c094432 */ 	lui	$t1,0x4432
/*  f0af310:	3c08fc50 */ 	lui	$t0,0xfc50
/*  f0af314:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0af318:	afb90200 */ 	sw	$t9,0x200($sp)
/*  f0af31c:	350898a1 */ 	ori	$t0,$t0,0x98a1
/*  f0af320:	35297f3f */ 	ori	$t1,$t1,0x7f3f
/*  f0af324:	27b10164 */ 	addiu	$s1,$sp,0x164
/*  f0af328:	02202025 */ 	or	$a0,$s1,$zero
/*  f0af32c:	af090004 */ 	sw	$t1,0x4($t8)
/*  f0af330:	0c00566c */ 	jal	mtx4LoadIdentity
/*  f0af334:	af080000 */ 	sw	$t0,0x0($t8)
/*  f0af338:	0fc2d5be */ 	jal	camGetWorldToScreenMtxf
/*  f0af33c:	00000000 */ 	nop
/*  f0af340:	00402025 */ 	or	$a0,$v0,$zero
/*  f0af344:	0c0056f8 */ 	jal	mtx00015be0
/*  f0af348:	02202825 */ 	or	$a1,$s1,$zero
/*  f0af34c:	27b10124 */ 	addiu	$s1,$sp,0x124
/*  f0af350:	0c00566c */ 	jal	mtx4LoadIdentity
/*  f0af354:	02202025 */ 	or	$a0,$s1,$zero
/*  f0af358:	0fc2d5de */ 	jal	camGetProjectionMtxF
/*  f0af35c:	00000000 */ 	nop
/*  f0af360:	00402025 */ 	or	$a0,$v0,$zero
/*  f0af364:	0c0056f8 */ 	jal	mtx00015be0
/*  f0af368:	02202825 */ 	or	$a1,$s1,$zero
/*  f0af36c:	44800000 */ 	mtc1	$zero,$f0
/*  f0af370:	27b101b0 */ 	addiu	$s1,$sp,0x1b0
/*  f0af374:	02202025 */ 	or	$a0,$s1,$zero
/*  f0af378:	e7a00158 */ 	swc1	$f0,0x158($sp)
/*  f0af37c:	e7a00154 */ 	swc1	$f0,0x154($sp)
/*  f0af380:	0c00566c */ 	jal	mtx4LoadIdentity
/*  f0af384:	e7a0015c */ 	swc1	$f0,0x15c($sp)
/*  f0af388:	0fc2d5be */ 	jal	camGetWorldToScreenMtxf
/*  f0af38c:	00000000 */ 	nop
/*  f0af390:	00402025 */ 	or	$a0,$v0,$zero
/*  f0af394:	0c0056f8 */ 	jal	mtx00015be0
/*  f0af398:	02202825 */ 	or	$a1,$s1,$zero
/*  f0af39c:	c6041bb0 */ 	lwc1	$f4,0x1bb0($s0)
/*  f0af3a0:	44805000 */ 	mtc1	$zero,$f10
/*  f0af3a4:	3c017f1b */ 	lui	$at,%hi(var7f1acd70)
/*  f0af3a8:	e7a401a4 */ 	swc1	$f4,0x1a4($sp)
/*  f0af3ac:	c6061bb4 */ 	lwc1	$f6,0x1bb4($s0)
/*  f0af3b0:	44802000 */ 	mtc1	$zero,$f4
/*  f0af3b4:	c42ccd70 */ 	lwc1	$f12,%lo(var7f1acd70)($at)
/*  f0af3b8:	e7a601a8 */ 	swc1	$f6,0x1a8($sp)
/*  f0af3bc:	c6081bb8 */ 	lwc1	$f8,0x1bb8($s0)
/*  f0af3c0:	44803000 */ 	mtc1	$zero,$f6
/*  f0af3c4:	02202825 */ 	or	$a1,$s1,$zero
/*  f0af3c8:	e7aa01e0 */ 	swc1	$f10,0x1e0($sp)
/*  f0af3cc:	e7a401e4 */ 	swc1	$f4,0x1e4($sp)
/*  f0af3d0:	e7a801ac */ 	swc1	$f8,0x1ac($sp)
/*  f0af3d4:	0c0057e2 */ 	jal	mtx00015f88
/*  f0af3d8:	e7a601e8 */ 	swc1	$f6,0x1e8($sp)
/*  f0af3dc:	0fc59e66 */ 	jal	gfxAllocateMatrix
/*  f0af3e0:	00000000 */ 	nop
/*  f0af3e4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0af3e8:	02202025 */ 	or	$a0,$s1,$zero
/*  f0af3ec:	0c005815 */ 	jal	mtx00016054
/*  f0af3f0:	00402825 */ 	or	$a1,$v0,$zero
/*  f0af3f4:	8fb10200 */ 	lw	$s1,0x200($sp)
/*  f0af3f8:	3c0c0102 */ 	lui	$t4,0x102
/*  f0af3fc:	358c0040 */ 	ori	$t4,$t4,0x40
/*  f0af400:	262b0008 */ 	addiu	$t3,$s1,0x8
/*  f0af404:	afab0200 */ 	sw	$t3,0x200($sp)
/*  f0af408:	02002025 */ 	or	$a0,$s0,$zero
/*  f0af40c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0af410:	ae2c0000 */ 	sw	$t4,0x0($s1)
/*  f0af414:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0af418:	3c017f1b */ 	lui	$at,%hi(var7f1acd74)
/*  f0af41c:	c43ccd74 */ 	lwc1	$f28,%lo(var7f1acd74)($at)
/*  f0af420:	3c017f1b */ 	lui	$at,%hi(var7f1acd78)
/*  f0af424:	3c10800a */ 	lui	$s0,%hi(g_LaserSights)
/*  f0af428:	2610dbe0 */ 	addiu	$s0,$s0,%lo(g_LaserSights)
/*  f0af42c:	c43acd78 */ 	lwc1	$f26,%lo(var7f1acd78)($at)
/*  f0af430:	24120200 */ 	addiu	$s2,$zero,0x200
/*  f0af434:	8e0d0000 */ 	lw	$t5,0x0($s0)
.L0f0af438:
/*  f0af438:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0af43c:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0af440:	11a10170 */ 	beq	$t5,$at,.L0f0afa04
/*  f0af444:	00000000 */ 	nop
/*  f0af448:	c600002c */ 	lwc1	$f0,0x2c($s0)
/*  f0af44c:	c6020030 */ 	lwc1	$f2,0x30($s0)
/*  f0af450:	c60e0034 */ 	lwc1	$f14,0x34($s0)
/*  f0af454:	c6080038 */ 	lwc1	$f8,0x38($s0)
/*  f0af458:	c616003c */ 	lwc1	$f22,0x3c($s0)
/*  f0af45c:	c6180040 */ 	lwc1	$f24,0x40($s0)
/*  f0af460:	e7a000e8 */ 	swc1	$f0,0xe8($sp)
/*  f0af464:	e7a200ec */ 	swc1	$f2,0xec($sp)
/*  f0af468:	e7ae00f0 */ 	swc1	$f14,0xf0($sp)
/*  f0af46c:	e7a800dc */ 	swc1	$f8,0xdc($sp)
/*  f0af470:	e7b600e0 */ 	swc1	$f22,0xe0($sp)
/*  f0af474:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f0af478:	e7b800e4 */ 	swc1	$f24,0xe4($sp)
/*  f0af47c:	3c0eff00 */ 	lui	$t6,0xff00
/*  f0af480:	3c0fff00 */ 	lui	$t7,0xff00
/*  f0af484:	35ce005f */ 	ori	$t6,$t6,0x5f
/*  f0af488:	35ef000f */ 	ori	$t7,$t7,0xf
/*  f0af48c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0af490:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0af494:	8fb10200 */ 	lw	$s1,0x200($sp)
/*  f0af498:	3c080704 */ 	lui	$t0,0x704
/*  f0af49c:	35080008 */ 	ori	$t0,$t0,0x8
/*  f0af4a0:	26390008 */ 	addiu	$t9,$s1,0x8
/*  f0af4a4:	afb90200 */ 	sw	$t9,0x200($sp)
/*  f0af4a8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0af4ac:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0af4b0:	ae280000 */ 	sw	$t0,0x0($s1)
/*  f0af4b4:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0af4b8:	c6040028 */ 	lwc1	$f4,0x28($s0)
/*  f0af4bc:	44805000 */ 	mtc1	$zero,$f10
/*  f0af4c0:	00000000 */ 	nop
/*  f0af4c4:	4604503c */ 	c.lt.s	$f10,$f4
/*  f0af4c8:	00000000 */ 	nop
/*  f0af4cc:	4500014d */ 	bc1f	.L0f0afa04
/*  f0af4d0:	00000000 */ 	nop
/*  f0af4d4:	c600002c */ 	lwc1	$f0,0x2c($s0)
/*  f0af4d8:	c7a200ec */ 	lwc1	$f2,0xec($sp)
/*  f0af4dc:	c7ae00f0 */ 	lwc1	$f14,0xf0($sp)
/*  f0af4e0:	461a003c */ 	c.lt.s	$f0,$f26
/*  f0af4e4:	3c098007 */ 	lui	$t1,%hi(var80070584)
/*  f0af4e8:	c7aa01a4 */ 	lwc1	$f10,0x1a4($sp)
/*  f0af4ec:	45000017 */ 	bc1f	.L0f0af54c
/*  f0af4f0:	00000000 */ 	nop
/*  f0af4f4:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f0af4f8:	00000000 */ 	nop
/*  f0af4fc:	45000013 */ 	bc1f	.L0f0af54c
/*  f0af500:	00000000 */ 	nop
/*  f0af504:	c6000030 */ 	lwc1	$f0,0x30($s0)
/*  f0af508:	461a003c */ 	c.lt.s	$f0,$f26
/*  f0af50c:	00000000 */ 	nop
/*  f0af510:	4500000e */ 	bc1f	.L0f0af54c
/*  f0af514:	00000000 */ 	nop
/*  f0af518:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f0af51c:	00000000 */ 	nop
/*  f0af520:	4500000a */ 	bc1f	.L0f0af54c
/*  f0af524:	00000000 */ 	nop
/*  f0af528:	c6000034 */ 	lwc1	$f0,0x34($s0)
/*  f0af52c:	461a003c */ 	c.lt.s	$f0,$f26
/*  f0af530:	00000000 */ 	nop
/*  f0af534:	45000005 */ 	bc1f	.L0f0af54c
/*  f0af538:	00000000 */ 	nop
/*  f0af53c:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f0af540:	00000000 */ 	nop
/*  f0af544:	4501012f */ 	bc1t	.L0f0afa04
/*  f0af548:	00000000 */ 	nop
.L0f0af54c:
/*  f0af54c:	8d290584 */ 	lw	$t1,%lo(var80070584)($t1)
/*  f0af550:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0af554:	4481b000 */ 	mtc1	$at,$f22
/*  f0af558:	44893000 */ 	mtc1	$t1,$f6
/*  f0af55c:	c7a000e8 */ 	lwc1	$f0,0xe8($sp)
/*  f0af560:	05210005 */ 	bgez	$t1,.L0f0af578
/*  f0af564:	46803520 */ 	cvt.s.w	$f20,$f6
/*  f0af568:	3c014f80 */ 	lui	$at,0x4f80
/*  f0af56c:	44814000 */ 	mtc1	$at,$f8
/*  f0af570:	00000000 */ 	nop
/*  f0af574:	4608a500 */ 	add.s	$f20,$f20,$f8
.L0f0af578:
/*  f0af578:	460a0101 */ 	sub.s	$f4,$f0,$f10
/*  f0af57c:	c7a601a8 */ 	lwc1	$f6,0x1a8($sp)
/*  f0af580:	c7aa01ac */ 	lwc1	$f10,0x1ac($sp)
/*  f0af584:	46061201 */ 	sub.s	$f8,$f2,$f6
/*  f0af588:	46162002 */ 	mul.s	$f0,$f4,$f22
/*  f0af58c:	460a7101 */ 	sub.s	$f4,$f14,$f10
/*  f0af590:	46164082 */ 	mul.s	$f2,$f8,$f22
/*  f0af594:	00000000 */ 	nop
/*  f0af598:	46162382 */ 	mul.s	$f14,$f4,$f22
/*  f0af59c:	e7a000e8 */ 	swc1	$f0,0xe8($sp)
/*  f0af5a0:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f0af5a4:	e7a200ec */ 	swc1	$f2,0xec($sp)
/*  f0af5a8:	46021202 */ 	mul.s	$f8,$f2,$f2
/*  f0af5ac:	e7ae00f0 */ 	swc1	$f14,0xf0($sp)
/*  f0af5b0:	460e7102 */ 	mul.s	$f4,$f14,$f14
/*  f0af5b4:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0af5b8:	0c012974 */ 	jal	sqrtf
/*  f0af5bc:	460a2300 */ 	add.s	$f12,$f4,$f10
/*  f0af5c0:	3c0a8007 */ 	lui	$t2,%hi(var80070574)
/*  f0af5c4:	8d4a0574 */ 	lw	$t2,%lo(var80070574)($t2)
/*  f0af5c8:	27a40200 */ 	addiu	$a0,$sp,0x200
/*  f0af5cc:	3c05800b */ 	lui	$a1,%hi(g_TexGeneralConfigs)
/*  f0af5d0:	448a3000 */ 	mtc1	$t2,$f6
/*  f0af5d4:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f0af5d8:	05410005 */ 	bgez	$t2,.L0f0af5f0
/*  f0af5dc:	468030a0 */ 	cvt.s.w	$f2,$f6
/*  f0af5e0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0af5e4:	44814000 */ 	mtc1	$at,$f8
/*  f0af5e8:	00000000 */ 	nop
/*  f0af5ec:	46081080 */ 	add.s	$f2,$f2,$f8
.L0f0af5f0:
/*  f0af5f0:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0af5f4:	3c0b8007 */ 	lui	$t3,%hi(var80070578)
/*  f0af5f8:	00003825 */ 	or	$a3,$zero,$zero
/*  f0af5fc:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0af600:	4500003c */ 	bc1f	.L0f0af6f4
/*  f0af604:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0af608:	8d6b0578 */ 	lw	$t3,%lo(var80070578)($t3)
/*  f0af60c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0af610:	3c0c8007 */ 	lui	$t4,%hi(var8007057c)
/*  f0af614:	448b2000 */ 	mtc1	$t3,$f4
/*  f0af618:	3c0e8007 */ 	lui	$t6,%hi(var80070580)
/*  f0af61c:	05610004 */ 	bgez	$t3,.L0f0af630
/*  f0af620:	46802320 */ 	cvt.s.w	$f12,$f4
/*  f0af624:	44815000 */ 	mtc1	$at,$f10
/*  f0af628:	00000000 */ 	nop
/*  f0af62c:	460a6300 */ 	add.s	$f12,$f12,$f10
.L0f0af630:
/*  f0af630:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0af634:	00000000 */ 	nop
/*  f0af638:	45000021 */ 	bc1f	.L0f0af6c0
/*  f0af63c:	00000000 */ 	nop
/*  f0af640:	8d8c057c */ 	lw	$t4,%lo(var8007057c)($t4)
/*  f0af644:	3c014f80 */ 	lui	$at,0x4f80
/*  f0af648:	3c0d8007 */ 	lui	$t5,%hi(var80070580)
/*  f0af64c:	448c3000 */ 	mtc1	$t4,$f6
/*  f0af650:	05810004 */ 	bgez	$t4,.L0f0af664
/*  f0af654:	468033a0 */ 	cvt.s.w	$f14,$f6
/*  f0af658:	44814000 */ 	mtc1	$at,$f8
/*  f0af65c:	00000000 */ 	nop
/*  f0af660:	46087380 */ 	add.s	$f14,$f14,$f8
.L0f0af664:
/*  f0af664:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0af668:	3c017f1b */ 	lui	$at,%hi(var7f1acd7c)
/*  f0af66c:	45000003 */ 	bc1f	.L0f0af67c
/*  f0af670:	00000000 */ 	nop
/*  f0af674:	10000010 */ 	b	.L0f0af6b8
/*  f0af678:	c434cd7c */ 	lwc1	$f20,%lo(var7f1acd7c)($at)
.L0f0af67c:
/*  f0af67c:	8dad0580 */ 	lw	$t5,%lo(var80070580)($t5)
/*  f0af680:	460c0201 */ 	sub.s	$f8,$f0,$f12
/*  f0af684:	3c014f80 */ 	lui	$at,0x4f80
/*  f0af688:	448d2000 */ 	mtc1	$t5,$f4
/*  f0af68c:	00000000 */ 	nop
/*  f0af690:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0af694:	05a10004 */ 	bgez	$t5,.L0f0af6a8
/*  f0af698:	460c7101 */ 	sub.s	$f4,$f14,$f12
/*  f0af69c:	44813000 */ 	mtc1	$at,$f6
/*  f0af6a0:	00000000 */ 	nop
/*  f0af6a4:	46065280 */ 	add.s	$f10,$f10,$f6
.L0f0af6a8:
/*  f0af6a8:	46044183 */ 	div.s	$f6,$f8,$f4
/*  f0af6ac:	46145080 */ 	add.s	$f2,$f10,$f20
/*  f0af6b0:	46061282 */ 	mul.s	$f10,$f2,$f6
/*  f0af6b4:	460a1501 */ 	sub.s	$f20,$f2,$f10
.L0f0af6b8:
/*  f0af6b8:	1000000e */ 	b	.L0f0af6f4
/*  f0af6bc:	00000000 */ 	nop
.L0f0af6c0:
/*  f0af6c0:	8dce0580 */ 	lw	$t6,%lo(var80070580)($t6)
/*  f0af6c4:	46026281 */ 	sub.s	$f10,$f12,$f2
/*  f0af6c8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0af6cc:	448e4000 */ 	mtc1	$t6,$f8
/*  f0af6d0:	05c10004 */ 	bgez	$t6,.L0f0af6e4
/*  f0af6d4:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0af6d8:	44813000 */ 	mtc1	$at,$f6
/*  f0af6dc:	00000000 */ 	nop
/*  f0af6e0:	46062100 */ 	add.s	$f4,$f4,$f6
.L0f0af6e4:
/*  f0af6e4:	460a2203 */ 	div.s	$f8,$f4,$f10
/*  f0af6e8:	46020181 */ 	sub.s	$f6,$f0,$f2
/*  f0af6ec:	46083102 */ 	mul.s	$f4,$f6,$f8
/*  f0af6f0:	46142500 */ 	add.s	$f20,$f4,$f20
.L0f0af6f4:
/*  f0af6f4:	8ca5b5a8 */ 	lw	$a1,%lo(g_TexGeneralConfigs)($a1)
/*  f0af6f8:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0af6fc:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0af700:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0af704:	0fc2ce70 */ 	jal	texSelect
/*  f0af708:	24a50030 */ 	addiu	$a1,$a1,0x0030
/*  f0af70c:	44800000 */ 	mtc1	$zero,$f0
/*  f0af710:	c7aa00dc */ 	lwc1	$f10,0xdc($sp)
/*  f0af714:	c7b800e4 */ 	lwc1	$f24,0xe4($sp)
/*  f0af718:	c7a600dc */ 	lwc1	$f6,0xdc($sp)
/*  f0af71c:	460a0032 */ 	c.eq.s	$f0,$f10
/*  f0af720:	00000000 */ 	nop
/*  f0af724:	4500000b */ 	bc1f	.L0f0af754
/*  f0af728:	00000000 */ 	nop
/*  f0af72c:	46180032 */ 	c.eq.s	$f0,$f24
/*  f0af730:	3c013f80 */ 	lui	$at,0x3f80
/*  f0af734:	45000007 */ 	bc1f	.L0f0af754
/*  f0af738:	00000000 */ 	nop
/*  f0af73c:	4480c000 */ 	mtc1	$zero,$f24
/*  f0af740:	44819000 */ 	mtc1	$at,$f18
/*  f0af744:	4481b000 */ 	mtc1	$at,$f22
/*  f0af748:	4600c386 */ 	mov.s	$f14,$f24
/*  f0af74c:	1000001a */ 	b	.L0f0af7b8
/*  f0af750:	4600c406 */ 	mov.s	$f16,$f24
.L0f0af754:
/*  f0af754:	46063202 */ 	mul.s	$f8,$f6,$f6
/*  f0af758:	c7b600e0 */ 	lwc1	$f22,0xe0($sp)
/*  f0af75c:	c7b800e4 */ 	lwc1	$f24,0xe4($sp)
/*  f0af760:	4616b102 */ 	mul.s	$f4,$f22,$f22
/*  f0af764:	46044280 */ 	add.s	$f10,$f8,$f4
/*  f0af768:	4618c182 */ 	mul.s	$f6,$f24,$f24
/*  f0af76c:	0c012974 */ 	jal	sqrtf
/*  f0af770:	460a3300 */ 	add.s	$f12,$f6,$f10
/*  f0af774:	c7a800dc */ 	lwc1	$f8,0xdc($sp)
/*  f0af778:	c7b800e4 */ 	lwc1	$f24,0xe4($sp)
/*  f0af77c:	c7b600e0 */ 	lwc1	$f22,0xe0($sp)
/*  f0af780:	46004683 */ 	div.s	$f26,$f8,$f0
/*  f0af784:	4600c703 */ 	div.s	$f28,$f24,$f0
/*  f0af788:	461ad102 */ 	mul.s	$f4,$f26,$f26
/*  f0af78c:	4600b783 */ 	div.s	$f30,$f22,$f0
/*  f0af790:	461ce182 */ 	mul.s	$f6,$f28,$f28
/*  f0af794:	0c012974 */ 	jal	sqrtf
/*  f0af798:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f0af79c:	4600d083 */ 	div.s	$f2,$f26,$f0
/*  f0af7a0:	46000407 */ 	neg.s	$f16,$f0
/*  f0af7a4:	4600e583 */ 	div.s	$f22,$f28,$f0
/*  f0af7a8:	4602f382 */ 	mul.s	$f14,$f30,$f2
/*  f0af7ac:	46001607 */ 	neg.s	$f24,$f2
/*  f0af7b0:	4616f482 */ 	mul.s	$f18,$f30,$f22
/*  f0af7b4:	00000000 */ 	nop
.L0f0af7b8:
/*  f0af7b8:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0af7bc:	e7ae00cc */ 	swc1	$f14,0xcc($sp)
/*  f0af7c0:	e7b000c8 */ 	swc1	$f16,0xc8($sp)
/*  f0af7c4:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f0af7c8:	e7b200c4 */ 	swc1	$f18,0xc4($sp)
/*  f0af7cc:	c7ae00cc */ 	lwc1	$f14,0xcc($sp)
/*  f0af7d0:	c7b000c8 */ 	lwc1	$f16,0xc8($sp)
/*  f0af7d4:	c7b200c4 */ 	lwc1	$f18,0xc4($sp)
/*  f0af7d8:	4600a007 */ 	neg.s	$f0,$f20
/*  f0af7dc:	a040002b */ 	sb	$zero,0x2b($v0)
/*  f0af7e0:	46160682 */ 	mul.s	$f26,$f0,$f22
/*  f0af7e4:	a040001f */ 	sb	$zero,0x1f($v0)
/*  f0af7e8:	a0400013 */ 	sb	$zero,0x13($v0)
/*  f0af7ec:	a0400007 */ 	sb	$zero,0x7($v0)
/*  f0af7f0:	a4400008 */ 	sh	$zero,0x8($v0)
/*  f0af7f4:	a440000a */ 	sh	$zero,0xa($v0)
/*  f0af7f8:	a4520014 */ 	sh	$s2,0x14($v0)
/*  f0af7fc:	a4400016 */ 	sh	$zero,0x16($v0)
/*  f0af800:	a4520020 */ 	sh	$s2,0x20($v0)
/*  f0af804:	a4520022 */ 	sh	$s2,0x22($v0)
/*  f0af808:	a440002c */ 	sh	$zero,0x2c($v0)
/*  f0af80c:	a452002e */ 	sh	$s2,0x2e($v0)
/*  f0af810:	460ea082 */ 	mul.s	$f2,$f20,$f14
/*  f0af814:	c7aa00e8 */ 	lwc1	$f10,0xe8($sp)
/*  f0af818:	3c0d0430 */ 	lui	$t5,0x430
/*  f0af81c:	4610a302 */ 	mul.s	$f12,$f20,$f16
/*  f0af820:	35ad0030 */ 	ori	$t5,$t5,0x30
/*  f0af824:	461a5200 */ 	add.s	$f8,$f10,$f26
/*  f0af828:	46180702 */ 	mul.s	$f28,$f0,$f24
/*  f0af82c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0af830:	4612a782 */ 	mul.s	$f30,$f20,$f18
/*  f0af834:	46024100 */ 	add.s	$f4,$f8,$f2
/*  f0af838:	44804000 */ 	mtc1	$zero,$f8
/*  f0af83c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0af840:	44083000 */ 	mfc1	$t0,$f6
/*  f0af844:	00000000 */ 	nop
/*  f0af848:	a4480000 */ 	sh	$t0,0x0($v0)
/*  f0af84c:	c7aa00ec */ 	lwc1	$f10,0xec($sp)
/*  f0af850:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0af854:	460c2180 */ 	add.s	$f6,$f4,$f12
/*  f0af858:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f0af85c:	440a5000 */ 	mfc1	$t2,$f10
/*  f0af860:	00000000 */ 	nop
/*  f0af864:	a44a0002 */ 	sh	$t2,0x2($v0)
/*  f0af868:	c7a800f0 */ 	lwc1	$f8,0xf0($sp)
/*  f0af86c:	461c4100 */ 	add.s	$f4,$f8,$f28
/*  f0af870:	4616a202 */ 	mul.s	$f8,$f20,$f22
/*  f0af874:	461e2180 */ 	add.s	$f6,$f4,$f30
/*  f0af878:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f0af87c:	440c5000 */ 	mfc1	$t4,$f10
/*  f0af880:	00000000 */ 	nop
/*  f0af884:	a44c0004 */ 	sh	$t4,0x4($v0)
/*  f0af888:	e7a80074 */ 	swc1	$f8,0x74($sp)
/*  f0af88c:	c7a60074 */ 	lwc1	$f6,0x74($sp)
/*  f0af890:	c7a400e8 */ 	lwc1	$f4,0xe8($sp)
/*  f0af894:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f0af898:	46025200 */ 	add.s	$f8,$f10,$f2
/*  f0af89c:	44805000 */ 	mtc1	$zero,$f10
/*  f0af8a0:	4618a082 */ 	mul.s	$f2,$f20,$f24
/*  f0af8a4:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f0af8a8:	440e2000 */ 	mfc1	$t6,$f4
/*  f0af8ac:	00000000 */ 	nop
/*  f0af8b0:	a44e000c */ 	sh	$t6,0xc($v0)
/*  f0af8b4:	c7a600ec */ 	lwc1	$f6,0xec($sp)
/*  f0af8b8:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f0af8bc:	460c4100 */ 	add.s	$f4,$f8,$f12
/*  f0af8c0:	460e0302 */ 	mul.s	$f12,$f0,$f14
/*  f0af8c4:	00000000 */ 	nop
/*  f0af8c8:	46100582 */ 	mul.s	$f22,$f0,$f16
/*  f0af8cc:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0af8d0:	44183000 */ 	mfc1	$t8,$f6
/*  f0af8d4:	00000000 */ 	nop
/*  f0af8d8:	a458000e */ 	sh	$t8,0xe($v0)
/*  f0af8dc:	c7aa00f0 */ 	lwc1	$f10,0xf0($sp)
/*  f0af8e0:	46025200 */ 	add.s	$f8,$f10,$f2
/*  f0af8e4:	461e4100 */ 	add.s	$f4,$f8,$f30
/*  f0af8e8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0af8ec:	44083000 */ 	mfc1	$t0,$f6
/*  f0af8f0:	00000000 */ 	nop
/*  f0af8f4:	a4480010 */ 	sh	$t0,0x10($v0)
/*  f0af8f8:	c7aa00e8 */ 	lwc1	$f10,0xe8($sp)
/*  f0af8fc:	c7a80074 */ 	lwc1	$f8,0x74($sp)
/*  f0af900:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0af904:	460c2180 */ 	add.s	$f6,$f4,$f12
/*  f0af908:	44802000 */ 	mtc1	$zero,$f4
/*  f0af90c:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f0af910:	440a5000 */ 	mfc1	$t2,$f10
/*  f0af914:	00000000 */ 	nop
/*  f0af918:	a44a0018 */ 	sh	$t2,0x18($v0)
/*  f0af91c:	c7a800ec */ 	lwc1	$f8,0xec($sp)
/*  f0af920:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0af924:	46120102 */ 	mul.s	$f4,$f0,$f18
/*  f0af928:	46163280 */ 	add.s	$f10,$f6,$f22
/*  f0af92c:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f0af930:	440c4000 */ 	mfc1	$t4,$f8
/*  f0af934:	00000000 */ 	nop
/*  f0af938:	a44c001a */ 	sh	$t4,0x1a($v0)
/*  f0af93c:	c7a600f0 */ 	lwc1	$f6,0xf0($sp)
/*  f0af940:	e7a40068 */ 	swc1	$f4,0x68($sp)
/*  f0af944:	c7a80068 */ 	lwc1	$f8,0x68($sp)
/*  f0af948:	46023280 */ 	add.s	$f10,$f6,$f2
/*  f0af94c:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0af950:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0af954:	440e3000 */ 	mfc1	$t6,$f6
/*  f0af958:	00000000 */ 	nop
/*  f0af95c:	a44e001c */ 	sh	$t6,0x1c($v0)
/*  f0af960:	c7aa00e8 */ 	lwc1	$f10,0xe8($sp)
/*  f0af964:	461a5200 */ 	add.s	$f8,$f10,$f26
/*  f0af968:	460c4100 */ 	add.s	$f4,$f8,$f12
/*  f0af96c:	44804000 */ 	mtc1	$zero,$f8
/*  f0af970:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0af974:	44183000 */ 	mfc1	$t8,$f6
/*  f0af978:	00000000 */ 	nop
/*  f0af97c:	a4580024 */ 	sh	$t8,0x24($v0)
/*  f0af980:	c7aa00ec */ 	lwc1	$f10,0xec($sp)
/*  f0af984:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0af988:	46162180 */ 	add.s	$f6,$f4,$f22
/*  f0af98c:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f0af990:	44085000 */ 	mfc1	$t0,$f10
/*  f0af994:	00000000 */ 	nop
/*  f0af998:	a4480026 */ 	sh	$t0,0x26($v0)
/*  f0af99c:	c7a800f0 */ 	lwc1	$f8,0xf0($sp)
/*  f0af9a0:	c7a60068 */ 	lwc1	$f6,0x68($sp)
/*  f0af9a4:	461c4100 */ 	add.s	$f4,$f8,$f28
/*  f0af9a8:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f0af9ac:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f0af9b0:	440a4000 */ 	mfc1	$t2,$f8
/*  f0af9b4:	00000000 */ 	nop
/*  f0af9b8:	a44a0028 */ 	sh	$t2,0x28($v0)
/*  f0af9bc:	8fb10200 */ 	lw	$s1,0x200($sp)
/*  f0af9c0:	262c0008 */ 	addiu	$t4,$s1,0x8
/*  f0af9c4:	afac0200 */ 	sw	$t4,0x200($sp)
/*  f0af9c8:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0af9cc:	ae2d0000 */ 	sw	$t5,0x0($s1)
/*  f0af9d0:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0af9d4:	8fae0200 */ 	lw	$t6,0x200($sp)
/*  f0af9d8:	3c18b100 */ 	lui	$t8,0xb100
/*  f0af9dc:	37180002 */ 	ori	$t8,$t8,0x2
/*  f0af9e0:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0af9e4:	afaf0200 */ 	sw	$t7,0x200($sp)
/*  f0af9e8:	24193210 */ 	addiu	$t9,$zero,0x3210
/*  f0af9ec:	3c017f1b */ 	lui	$at,%hi(var7f1acd88)
/*  f0af9f0:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0af9f4:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0af9f8:	c43ccd88 */ 	lwc1	$f28,%lo(var7f1acd88)($at)
/*  f0af9fc:	3c017f1b */ 	lui	$at,%hi(var7f1acd8c)
/*  f0afa00:	c43acd8c */ 	lwc1	$f26,%lo(var7f1acd8c)($at)
.L0f0afa04:
/*  f0afa04:	3c08800a */ 	lui	$t0,%hi(var8009dd00)
/*  f0afa08:	2508dd00 */ 	addiu	$t0,$t0,%lo(var8009dd00)
/*  f0afa0c:	26100048 */ 	addiu	$s0,$s0,72
/*  f0afa10:	5608fe89 */ 	bnel	$s0,$t0,.L0f0af438
/*  f0afa14:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f0afa18:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f0afa1c:	8fa20200 */ 	lw	$v0,0x200($sp)
/*  f0afa20:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f0afa24:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f0afa28:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f0afa2c:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f0afa30:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f0afa34:	d7be0050 */ 	ldc1	$f30,0x50($sp)
/*  f0afa38:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f0afa3c:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f0afa40:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f0afa44:	03e00008 */ 	jr	$ra
/*  f0afa48:	27bd0200 */ 	addiu	$sp,$sp,0x200
);

// Mismatch: floating point callee-save register usage is different.
// eg. the registers for 0.0000001f and -0.000001f should be f26 and f28
// but the below loads them from rodata each time.
// There is also something wrong with the dot rotation.
//Gfx *lasersightRenderDot(Gfx *gdl)
//{
//	Mtxf *mtx;
//	f32 fVar10;
//	f32 f20;
//	struct player *player = g_Vars.currentplayer;
//	Mtxf sp1b0;
//	struct coord campos; // 1a4
//	Mtxf sp164;
//	Mtxf sp124;
//	s32 i;
//
//	static u32 sp1 = 800;
//	static u32 sp2 = 7000;
//	static u32 sp3 = 9000;
//	static u32 spb = 24;
//	static u32 spi = 6;
//
//	mainOverrideVariable("sp1", &sp1);
//	mainOverrideVariable("sp2", &sp2);
//	mainOverrideVariable("sp3", &sp3);
//	mainOverrideVariable("spb", &spb);
//	mainOverrideVariable("spi", &spi);
//
//	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
//	gDPSetTextureFilter(gdl++, G_TF_BILERP);
//	gDPSetTexturePersp(gdl++, G_TP_PERSP);
//	gDPSetColorDither(gdl++, G_CD_DISABLE);
//	gDPSetRenderMode(gdl++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
//	gDPSetAlphaCompare(gdl++, G_AC_NONE);
//	gDPSetTextureLOD(gdl++, G_TL_TILE);
//	gDPSetTextureConvert(gdl++, G_TC_FILT);
//	gDPSetTextureLUT(gdl++, G_TT_NONE);
//	gDPSetCombineMode(gdl++, G_CC_BLENDIA, G_CC_BLENDIA);
//
//	mtx4LoadIdentity(&sp164);
//	mtx00015be0(camGetWorldToScreenMtxf(), &sp164);
//	mtx4LoadIdentity(&sp124);
//	mtx00015be0(camGetProjectionMtxF(), &sp124);
//
//	sp124.m[3][1] = 0;
//	sp124.m[3][0] = 0;
//	sp124.m[3][2] = 0;
//
//	mtx4LoadIdentity(&sp1b0);
//	mtx00015be0(camGetWorldToScreenMtxf(), &sp1b0);
//
//	campos.x = player->cam_pos.x;
//	campos.y = player->cam_pos.y;
//	campos.z = player->cam_pos.z;
//
//	sp1b0.m[3][0] = 0.0f;
//	sp1b0.m[3][1] = 0.0f;
//	sp1b0.m[3][2] = 0.0f;
//
//	mtx00015f88(0.2f, &sp1b0);
//
//	mtx = gfxAllocateMatrix();
//	mtx00016054(&sp1b0, mtx);
//
//	gSPMatrix(gdl++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
//
//	// 438
//	for (i = 0; i < 4; i++) {
//		if (g_LaserSights[i].id != -1) {
//			struct coord pos; // e8
//			struct coord rot; // dc
//			u32 *colours;
//			struct gfxvtx *vertices;
//
//			pos.x = g_LaserSights[i].dotpos.f[0];
//			pos.y = g_LaserSights[i].dotpos.f[1];
//			pos.z = g_LaserSights[i].dotpos.f[2];
//
//			rot.x = g_LaserSights[i].dotrot.f[0];
//			rot.y = g_LaserSights[i].dotrot.f[1];
//			rot.z = g_LaserSights[i].dotrot.f[2];
//
//			colours = gfxAllocateColours(2);
//
//			colours[0] = 0xff00005f;
//			colours[1] = 0xff00000f;
//
//			gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 2);
//
//			// 4c4
//			if (g_LaserSights[i].unk28 > 0.0f) {
//				if (pos.f[0] < 0.0000001f || pos.f[0] > -0.000001f
//						|| pos.f[1] < 0.0000001f || pos.f[1] > -0.000001f
//						|| pos.f[2] < 0.0000001f || pos.f[2] > -0.000001f) {
//					// 54c
//					f32 f14;
//					f32 f16;
//					f32 f18;
//					f32 f22;
//					f32 f24;
//					f32 f26;
//					f32 f28;
//					f32 f30;
//					f32 f2;
//					f32 sp1f;
//					f32 sp2f;
//					f32 sp3f;
//
//					f20 = spi; // = 6
//
//					pos.x = (pos.x - campos.x) * 5;
//					pos.y = (pos.y - campos.y) * 5;
//					pos.z = (pos.z - campos.z) * 5;
//
//					fVar10 = sqrtf(pos.f[0] * pos.f[0] + pos.f[1] * pos.f[1] + pos.f[2] * pos.f[2]);
//
//					sp1f = sp1;
//
//					// 600
//					if (fVar10 > sp1f) { // > 800
//						sp2f = sp2;
//
//						// 638
//						if (fVar10 > sp2f) { // > 7000
//							sp3f = sp3;
//
//							// 66c
//							if (fVar10 > sp3f) { // > 9000
//								f20 = 0.1f;
//							} else {
//								// 67c
//								f32 tmp = spb + f20;
//								f20 = tmp - tmp * ((fVar10 - sp2f) / (sp3f - sp2f));
//							}
//						} else {
//							// 6c0
//							f20 += (fVar10 - sp1f) * (spb / (sp2f - sp1f));
//						}
//					}
//
//					texSelect(&gdl, &g_TexGeneralConfigs[4], 4, 0, 2, 1, NULL);
//
//					// 724
//					if (rot.f[0] == 0 && rot.f[2] == 0) {
//						// 73c
//						f18 = 1;
//						f22 = 1;
//						f24 = 0;
//						f14 = 0;
//						f16 = 0;
//					} else {
//						// 754
//						f32 f0 = sqrtf(rot.f[0] * rot.f[0] + rot.f[1] * rot.f[1] + rot.f[2] * rot.f[2]);
//						f26 = rot.x / f0;
//						f30 = rot.y / f0;
//						f28 = rot.z / f0;
//
//						f0 = sqrtf(f26 * f26 + f28 * f28);
//						f2 = f26 / f0;
//
//						f22 = f28 / f0;
//						f14 = f30 * f2;
//						f16 = -f0;
//						f18 = f30 * f22;
//						f24 = -f2;
//					}
//
//					// 7b8
//					vertices = gfxAllocateVertices(4);
//
//					vertices[0].colour = vertices[1].colour = vertices[2].colour = vertices[3].colour = 0;
//
//					vertices[0].s = 0;
//					vertices[0].t = 0;
//					vertices[1].s = 512;
//					vertices[1].t = 0;
//					vertices[2].s = 512;
//					vertices[2].t = 512;
//					vertices[3].s = 0;
//					vertices[3].t = 512;
//
//					vertices[0].x = pos.f[0] + ((-f20 * f22) + (f20 * f14));
//					vertices[0].y = pos.f[1] + 0.0f + (f20 * f16);
//					vertices[0].z = pos.f[2] + ((-f20 * f24) + (f20 * f18));
//
//					vertices[1].x = pos.f[0] + ((f20 * f22) + (f20 * f14));
//					vertices[1].y = pos.f[1] + 0.0f + (f20 * f16);
//					vertices[1].z = pos.f[2] + ((f20 * f24) + (f20 * f18));
//
//					vertices[2].x = pos.f[0] + ((f20 * f22) + (-f20 * f14));
//					vertices[2].y = pos.f[1] + 0.0f + (-f20 * f16);
//					vertices[2].z = pos.f[2] + ((f20 * f24) + (-f20 * f18));
//
//					vertices[3].x = pos.f[0] + ((-f20 * f22) + (-f20 * f14));
//					vertices[3].y = pos.f[1] + 0.0f + (-f20 * f16);
//					vertices[3].z = pos.f[2] + ((-f20 * f24) + (-f20 * f18));
//
//					gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 4);
//
//					gDPTri2(gdl++, 0, 1, 2, 2, 3, 0);
//				}
//			}
//		}
//	}
//
//	return gdl;
//}

GLOBAL_ASM(
glabel lasersightRenderBeam
.late_rodata
glabel var7f1acd90
.word 0x3e4ccccd
.text
/*  f0afa4c:	27bdfe18 */ 	addiu	$sp,$sp,-488
/*  f0afa50:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f0afa54:	afa401e8 */ 	sw	$a0,0x1e8($sp)
/*  f0afa58:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f0afa5c:	248f0008 */ 	addiu	$t7,$a0,0x8
/*  f0afa60:	afbf007c */ 	sw	$ra,0x7c($sp)
/*  f0afa64:	afbe0078 */ 	sw	$s8,0x78($sp)
/*  f0afa68:	afb70074 */ 	sw	$s7,0x74($sp)
/*  f0afa6c:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f0afa70:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f0afa74:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f0afa78:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f0afa7c:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f0afa80:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f0afa84:	f7be0050 */ 	sdc1	$f30,0x50($sp)
/*  f0afa88:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f0afa8c:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f0afa90:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f0afa94:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f0afa98:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f0afa9c:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f0afaa0:	afaf01e8 */ 	sw	$t7,0x1e8($sp)
/*  f0afaa4:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0afaa8:	37181402 */ 	ori	$t8,$t8,0x1402
/*  f0afaac:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f0afab0:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f0afab4:	8fb901e8 */ 	lw	$t9,0x1e8($sp)
/*  f0afab8:	3c09ba00 */ 	lui	$t1,0xba00
/*  f0afabc:	35290c02 */ 	ori	$t1,$t1,0xc02
/*  f0afac0:	27280008 */ 	addiu	$t0,$t9,0x8
/*  f0afac4:	afa801e8 */ 	sw	$t0,0x1e8($sp)
/*  f0afac8:	240a2000 */ 	addiu	$t2,$zero,0x2000
/*  f0afacc:	af2a0004 */ 	sw	$t2,0x4($t9)
/*  f0afad0:	af290000 */ 	sw	$t1,0x0($t9)
/*  f0afad4:	8fab01e8 */ 	lw	$t3,0x1e8($sp)
/*  f0afad8:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0afadc:	35ad1301 */ 	ori	$t5,$t5,0x1301
/*  f0afae0:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f0afae4:	afac01e8 */ 	sw	$t4,0x1e8($sp)
/*  f0afae8:	3c0e0008 */ 	lui	$t6,0x8
/*  f0afaec:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f0afaf0:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f0afaf4:	8faf01e8 */ 	lw	$t7,0x1e8($sp)
/*  f0afaf8:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0afafc:	37390602 */ 	ori	$t9,$t9,0x602
/*  f0afb00:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0afb04:	afb801e8 */ 	sw	$t8,0x1e8($sp)
/*  f0afb08:	240800c0 */ 	addiu	$t0,$zero,0xc0
/*  f0afb0c:	ade80004 */ 	sw	$t0,0x4($t7)
/*  f0afb10:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0afb14:	8fa901e8 */ 	lw	$t1,0x1e8($sp)
/*  f0afb18:	3c0bb900 */ 	lui	$t3,0xb900
/*  f0afb1c:	3c0c0050 */ 	lui	$t4,0x50
/*  f0afb20:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f0afb24:	afaa01e8 */ 	sw	$t2,0x1e8($sp)
/*  f0afb28:	358c41c8 */ 	ori	$t4,$t4,0x41c8
/*  f0afb2c:	356b031d */ 	ori	$t3,$t3,0x31d
/*  f0afb30:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f0afb34:	ad2c0004 */ 	sw	$t4,0x4($t1)
/*  f0afb38:	8fad01e8 */ 	lw	$t5,0x1e8($sp)
/*  f0afb3c:	3c0fb900 */ 	lui	$t7,0xb900
/*  f0afb40:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f0afb44:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0afb48:	afae01e8 */ 	sw	$t6,0x1e8($sp)
/*  f0afb4c:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f0afb50:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0afb54:	8fb801e8 */ 	lw	$t8,0x1e8($sp)
/*  f0afb58:	3c08ba00 */ 	lui	$t0,0xba00
/*  f0afb5c:	35081001 */ 	ori	$t0,$t0,0x1001
/*  f0afb60:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0afb64:	afb901e8 */ 	sw	$t9,0x1e8($sp)
/*  f0afb68:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0afb6c:	af080000 */ 	sw	$t0,0x0($t8)
/*  f0afb70:	8fa901e8 */ 	lw	$t1,0x1e8($sp)
/*  f0afb74:	3c0bba00 */ 	lui	$t3,0xba00
/*  f0afb78:	356b0903 */ 	ori	$t3,$t3,0x903
/*  f0afb7c:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f0afb80:	afaa01e8 */ 	sw	$t2,0x1e8($sp)
/*  f0afb84:	240c0c00 */ 	addiu	$t4,$zero,0xc00
/*  f0afb88:	ad2c0004 */ 	sw	$t4,0x4($t1)
/*  f0afb8c:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f0afb90:	8fad01e8 */ 	lw	$t5,0x1e8($sp)
/*  f0afb94:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0afb98:	35ef0e02 */ 	ori	$t7,$t7,0xe02
/*  f0afb9c:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0afba0:	afae01e8 */ 	sw	$t6,0x1e8($sp)
/*  f0afba4:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f0afba8:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0afbac:	8fb801e8 */ 	lw	$t8,0x1e8($sp)
/*  f0afbb0:	3c094432 */ 	lui	$t1,0x4432
/*  f0afbb4:	3c08fc50 */ 	lui	$t0,0xfc50
/*  f0afbb8:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0afbbc:	afb901e8 */ 	sw	$t9,0x1e8($sp)
/*  f0afbc0:	350898a1 */ 	ori	$t0,$t0,0x98a1
/*  f0afbc4:	35297f3f */ 	ori	$t1,$t1,0x7f3f
/*  f0afbc8:	af090004 */ 	sw	$t1,0x4($t8)
/*  f0afbcc:	af080000 */ 	sw	$t0,0x0($t8)
/*  f0afbd0:	8faa01e8 */ 	lw	$t2,0x1e8($sp)
/*  f0afbd4:	240d3000 */ 	addiu	$t5,$zero,0x3000
/*  f0afbd8:	3c0cb600 */ 	lui	$t4,0xb600
/*  f0afbdc:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0afbe0:	afab01e8 */ 	sw	$t3,0x1e8($sp)
/*  f0afbe4:	3c05800b */ 	lui	$a1,%hi(g_TexGeneralConfigs)
/*  f0afbe8:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0afbec:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f0afbf0:	8ca5b5a8 */ 	lw	$a1,%lo(g_TexGeneralConfigs)($a1)
/*  f0afbf4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0afbf8:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f0afbfc:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0afc00:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0afc04:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0afc08:	27a401e8 */ 	addiu	$a0,$sp,0x1e8
/*  f0afc0c:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f0afc10:	00003825 */ 	or	$a3,$zero,$zero
/*  f0afc14:	0fc2ce70 */ 	jal	texSelect
/*  f0afc18:	24a50024 */ 	addiu	$a1,$a1,0x0024
/*  f0afc1c:	0c00566c */ 	jal	mtx4LoadIdentity
/*  f0afc20:	27a4014c */ 	addiu	$a0,$sp,0x14c
/*  f0afc24:	0fc2d5be */ 	jal	camGetWorldToScreenMtxf
/*  f0afc28:	00000000 */ 	nop
/*  f0afc2c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0afc30:	0c0056f8 */ 	jal	mtx00015be0
/*  f0afc34:	27a5014c */ 	addiu	$a1,$sp,0x14c
/*  f0afc38:	0c00566c */ 	jal	mtx4LoadIdentity
/*  f0afc3c:	27a4010c */ 	addiu	$a0,$sp,0x10c
/*  f0afc40:	0fc2d5de */ 	jal	camGetProjectionMtxF
/*  f0afc44:	00000000 */ 	nop
/*  f0afc48:	00402025 */ 	or	$a0,$v0,$zero
/*  f0afc4c:	0c0056f8 */ 	jal	mtx00015be0
/*  f0afc50:	27a5010c */ 	addiu	$a1,$sp,0x10c
/*  f0afc54:	4480a000 */ 	mtc1	$zero,$f20
/*  f0afc58:	27b10198 */ 	addiu	$s1,$sp,0x198
/*  f0afc5c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0afc60:	e7b40140 */ 	swc1	$f20,0x140($sp)
/*  f0afc64:	e7b4013c */ 	swc1	$f20,0x13c($sp)
/*  f0afc68:	0c00566c */ 	jal	mtx4LoadIdentity
/*  f0afc6c:	e7b40144 */ 	swc1	$f20,0x144($sp)
/*  f0afc70:	0fc2d5be */ 	jal	camGetWorldToScreenMtxf
/*  f0afc74:	00000000 */ 	nop
/*  f0afc78:	00402025 */ 	or	$a0,$v0,$zero
/*  f0afc7c:	0c0056f8 */ 	jal	mtx00015be0
/*  f0afc80:	02202825 */ 	or	$a1,$s1,$zero
/*  f0afc84:	c6041bb0 */ 	lwc1	$f4,0x1bb0($s0)
/*  f0afc88:	3c017f1b */ 	lui	$at,%hi(var7f1acd90)
/*  f0afc8c:	c42ccd90 */ 	lwc1	$f12,%lo(var7f1acd90)($at)
/*  f0afc90:	e7a4018c */ 	swc1	$f4,0x18c($sp)
/*  f0afc94:	c6061bb4 */ 	lwc1	$f6,0x1bb4($s0)
/*  f0afc98:	02202825 */ 	or	$a1,$s1,$zero
/*  f0afc9c:	e7a60190 */ 	swc1	$f6,0x190($sp)
/*  f0afca0:	c6081bb8 */ 	lwc1	$f8,0x1bb8($s0)
/*  f0afca4:	e7b401c8 */ 	swc1	$f20,0x1c8($sp)
/*  f0afca8:	e7b401cc */ 	swc1	$f20,0x1cc($sp)
/*  f0afcac:	e7b401d0 */ 	swc1	$f20,0x1d0($sp)
/*  f0afcb0:	0c0057e2 */ 	jal	mtx00015f88
/*  f0afcb4:	e7a80194 */ 	swc1	$f8,0x194($sp)
/*  f0afcb8:	0fc59e66 */ 	jal	gfxAllocateMatrix
/*  f0afcbc:	00000000 */ 	nop
/*  f0afcc0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0afcc4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0afcc8:	0c005815 */ 	jal	mtx00016054
/*  f0afccc:	00402825 */ 	or	$a1,$v0,$zero
/*  f0afcd0:	8fb101e8 */ 	lw	$s1,0x1e8($sp)
/*  f0afcd4:	3c080102 */ 	lui	$t0,0x102
/*  f0afcd8:	35080040 */ 	ori	$t0,$t0,0x40
/*  f0afcdc:	26390008 */ 	addiu	$t9,$s1,0x8
/*  f0afce0:	afb901e8 */ 	sw	$t9,0x1e8($sp)
/*  f0afce4:	02002025 */ 	or	$a0,$s0,$zero
/*  f0afce8:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0afcec:	ae280000 */ 	sw	$t0,0x0($s1)
/*  f0afcf0:	3c0143c8 */ 	lui	$at,0x43c8
/*  f0afcf4:	4481d000 */ 	mtc1	$at,$f26
/*  f0afcf8:	3c014348 */ 	lui	$at,0x4348
/*  f0afcfc:	4481c000 */ 	mtc1	$at,$f24
/*  f0afd00:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0afd04:	4481b000 */ 	mtc1	$at,$f22
/*  f0afd08:	3c014170 */ 	lui	$at,0x4170
/*  f0afd0c:	3c10800a */ 	lui	$s0,%hi(g_LaserSights)
/*  f0afd10:	4481a000 */ 	mtc1	$at,$f20
/*  f0afd14:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0afd18:	2610dbe0 */ 	addiu	$s0,$s0,%lo(g_LaserSights)
/*  f0afd1c:	27be00ac */ 	addiu	$s8,$sp,0xac
/*  f0afd20:	27b70098 */ 	addiu	$s7,$sp,0x98
/*  f0afd24:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f0afd28:	24150020 */ 	addiu	$s5,$zero,0x20
/*  f0afd2c:	24140004 */ 	addiu	$s4,$zero,0x4
/*  f0afd30:	27b300a8 */ 	addiu	$s3,$sp,0xa8
/*  f0afd34:	24120100 */ 	addiu	$s2,$zero,0x100
/*  f0afd38:	8e090000 */ 	lw	$t1,0x0($s0)
.L0f0afd3c:
/*  f0afd3c:	27a4014c */ 	addiu	$a0,$sp,0x14c
/*  f0afd40:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0afd44:	12c90130 */ 	beq	$s6,$t1,.L0f0b0208
/*  f0afd48:	00000000 */ 	nop
/*  f0afd4c:	c60a0010 */ 	lwc1	$f10,0x10($s0)
/*  f0afd50:	c6040014 */ 	lwc1	$f4,0x14($s0)
/*  f0afd54:	c6060018 */ 	lwc1	$f6,0x18($s0)
/*  f0afd58:	e7aa0098 */ 	swc1	$f10,0x98($sp)
/*  f0afd5c:	e7a4009c */ 	swc1	$f4,0x9c($sp)
/*  f0afd60:	0c0056d9 */ 	jal	mtx4TransformVecInPlace
/*  f0afd64:	e7a600a0 */ 	swc1	$f6,0xa0($sp)
/*  f0afd68:	4480e000 */ 	mtc1	$zero,$f28
/*  f0afd6c:	c7a80098 */ 	lwc1	$f8,0x98($sp)
/*  f0afd70:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0afd74:	02602025 */ 	or	$a0,$s3,$zero
/*  f0afd78:	461c403c */ 	c.lt.s	$f8,$f28
/*  f0afd7c:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0afd80:	27a600b0 */ 	addiu	$a2,$sp,0xb0
/*  f0afd84:	45020006 */ 	bc1fl	.L0f0afda0
/*  f0afd88:	44812000 */ 	mtc1	$at,$f4
/*  f0afd8c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0afd90:	44815000 */ 	mtc1	$at,$f10
/*  f0afd94:	10000004 */ 	b	.L0f0afda8
/*  f0afd98:	e7aa00a8 */ 	swc1	$f10,0xa8($sp)
/*  f0afd9c:	44812000 */ 	mtc1	$at,$f4
.L0f0afda0:
/*  f0afda0:	00000000 */ 	nop
/*  f0afda4:	e7a400a8 */ 	swc1	$f4,0xa8($sp)
.L0f0afda8:
/*  f0afda8:	3c014000 */ 	lui	$at,0x4000
/*  f0afdac:	44813000 */ 	mtc1	$at,$f6
/*  f0afdb0:	e7bc00b0 */ 	swc1	$f28,0xb0($sp)
/*  f0afdb4:	0c0011e4 */ 	jal	guNormalize
/*  f0afdb8:	e7a600ac */ 	swc1	$f6,0xac($sp)
/*  f0afdbc:	27a4010c */ 	addiu	$a0,$sp,0x10c
/*  f0afdc0:	0c0056c4 */ 	jal	mtx4RotateVecInPlace
/*  f0afdc4:	02602825 */ 	or	$a1,$s3,$zero
/*  f0afdc8:	c7bc018c */ 	lwc1	$f28,0x18c($sp)
/*  f0afdcc:	c6000010 */ 	lwc1	$f0,0x10($s0)
/*  f0afdd0:	c7be0190 */ 	lwc1	$f30,0x190($sp)
/*  f0afdd4:	c6020014 */ 	lwc1	$f2,0x14($s0)
/*  f0afdd8:	461c0201 */ 	sub.s	$f8,$f0,$f28
/*  f0afddc:	c60c0018 */ 	lwc1	$f12,0x18($s0)
/*  f0afde0:	c7a40194 */ 	lwc1	$f4,0x194($sp)
/*  f0afde4:	461e1281 */ 	sub.s	$f10,$f2,$f30
/*  f0afde8:	46164002 */ 	mul.s	$f0,$f8,$f22
/*  f0afdec:	c60e001c */ 	lwc1	$f14,0x1c($s0)
/*  f0afdf0:	46046181 */ 	sub.s	$f6,$f12,$f4
/*  f0afdf4:	46165082 */ 	mul.s	$f2,$f10,$f22
/*  f0afdf8:	c6100020 */ 	lwc1	$f16,0x20($s0)
/*  f0afdfc:	461c7201 */ 	sub.s	$f8,$f14,$f28
/*  f0afe00:	46163302 */ 	mul.s	$f12,$f6,$f22
/*  f0afe04:	c6120024 */ 	lwc1	$f18,0x24($s0)
/*  f0afe08:	461e8281 */ 	sub.s	$f10,$f16,$f30
/*  f0afe0c:	46164382 */ 	mul.s	$f14,$f8,$f22
/*  f0afe10:	e7a200d0 */ 	swc1	$f2,0xd0($sp)
/*  f0afe14:	46049181 */ 	sub.s	$f6,$f18,$f4
/*  f0afe18:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f0afe1c:	e7ac00d4 */ 	swc1	$f12,0xd4($sp)
/*  f0afe20:	e7a000cc */ 	swc1	$f0,0xcc($sp)
/*  f0afe24:	46163482 */ 	mul.s	$f18,$f6,$f22
/*  f0afe28:	e7ae00c0 */ 	swc1	$f14,0xc0($sp)
/*  f0afe2c:	46007201 */ 	sub.s	$f8,$f14,$f0
/*  f0afe30:	27a400b4 */ 	addiu	$a0,$sp,0xb4
/*  f0afe34:	e7b000c4 */ 	swc1	$f16,0xc4($sp)
/*  f0afe38:	46028281 */ 	sub.s	$f10,$f16,$f2
/*  f0afe3c:	e7a800b4 */ 	swc1	$f8,0xb4($sp)
/*  f0afe40:	e7b200c8 */ 	swc1	$f18,0xc8($sp)
/*  f0afe44:	460c9101 */ 	sub.s	$f4,$f18,$f12
/*  f0afe48:	e7aa00b8 */ 	swc1	$f10,0xb8($sp)
/*  f0afe4c:	27a500b8 */ 	addiu	$a1,$sp,0xb8
/*  f0afe50:	27a600bc */ 	addiu	$a2,$sp,0xbc
/*  f0afe54:	0c0011e4 */ 	jal	guNormalize
/*  f0afe58:	e7a400bc */ 	swc1	$f4,0xbc($sp)
/*  f0afe5c:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f0afe60:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0afe64:	3c0aff00 */ 	lui	$t2,0xff00
/*  f0afe68:	3c0bff00 */ 	lui	$t3,0xff00
/*  f0afe6c:	354a005f */ 	ori	$t2,$t2,0x5f
/*  f0afe70:	356b000f */ 	ori	$t3,$t3,0xf
/*  f0afe74:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f0afe78:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f0afe7c:	8fb101e8 */ 	lw	$s1,0x1e8($sp)
/*  f0afe80:	3c0e0704 */ 	lui	$t6,0x704
/*  f0afe84:	35ce0008 */ 	ori	$t6,$t6,0x8
/*  f0afe88:	262d0008 */ 	addiu	$t5,$s1,0x8
/*  f0afe8c:	afad01e8 */ 	sw	$t5,0x1e8($sp)
/*  f0afe90:	00402025 */ 	or	$a0,$v0,$zero
/*  f0afe94:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0afe98:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f0afe9c:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0afea0:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f0afea4:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f0afea8:	a0400007 */ 	sb	$zero,0x7($v0)
/*  f0afeac:	a0400013 */ 	sb	$zero,0x13($v0)
/*  f0afeb0:	a040001f */ 	sb	$zero,0x1f($v0)
/*  f0afeb4:	a040002b */ 	sb	$zero,0x2b($v0)
/*  f0afeb8:	a0540037 */ 	sb	$s4,0x37($v0)
/*  f0afebc:	a0540043 */ 	sb	$s4,0x43($v0)
/*  f0afec0:	a4400008 */ 	sh	$zero,0x8($v0)
/*  f0afec4:	a440000a */ 	sh	$zero,0xa($v0)
/*  f0afec8:	a4400014 */ 	sh	$zero,0x14($v0)
/*  f0afecc:	a4520016 */ 	sh	$s2,0x16($v0)
/*  f0afed0:	a4550020 */ 	sh	$s5,0x20($v0)
/*  f0afed4:	a4400022 */ 	sh	$zero,0x22($v0)
/*  f0afed8:	a455002c */ 	sh	$s5,0x2c($v0)
/*  f0afedc:	a452002e */ 	sh	$s2,0x2e($v0)
/*  f0afee0:	a4400038 */ 	sh	$zero,0x38($v0)
/*  f0afee4:	a440003a */ 	sh	$zero,0x3a($v0)
/*  f0afee8:	a4400044 */ 	sh	$zero,0x44($v0)
/*  f0afeec:	a4520046 */ 	sh	$s2,0x46($v0)
/*  f0afef0:	c7a800a8 */ 	lwc1	$f8,0xa8($sp)
/*  f0afef4:	c7a600cc */ 	lwc1	$f6,0xcc($sp)
/*  f0afef8:	3c0d0450 */ 	lui	$t5,0x450
/*  f0afefc:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f0aff00:	35ad0048 */ 	ori	$t5,$t5,0x48
/*  f0aff04:	00402025 */ 	or	$a0,$v0,$zero
/*  f0aff08:	460a3101 */ 	sub.s	$f4,$f6,$f10
/*  f0aff0c:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f0aff10:	44184000 */ 	mfc1	$t8,$f8
/*  f0aff14:	00000000 */ 	nop
/*  f0aff18:	a4580000 */ 	sh	$t8,0x0($v0)
/*  f0aff1c:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*  f0aff20:	c7a600d0 */ 	lwc1	$f6,0xd0($sp)
/*  f0aff24:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0aff28:	46043201 */ 	sub.s	$f8,$f6,$f4
/*  f0aff2c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0aff30:	44085000 */ 	mfc1	$t0,$f10
/*  f0aff34:	00000000 */ 	nop
/*  f0aff38:	a4480002 */ 	sh	$t0,0x2($v0)
/*  f0aff3c:	c7a400b0 */ 	lwc1	$f4,0xb0($sp)
/*  f0aff40:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f0aff44:	46142202 */ 	mul.s	$f8,$f4,$f20
/*  f0aff48:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f0aff4c:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0aff50:	440a2000 */ 	mfc1	$t2,$f4
/*  f0aff54:	00000000 */ 	nop
/*  f0aff58:	a44a0004 */ 	sh	$t2,0x4($v0)
/*  f0aff5c:	c7a600a8 */ 	lwc1	$f6,0xa8($sp)
/*  f0aff60:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0aff64:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f0aff68:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f0aff6c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0aff70:	440c3000 */ 	mfc1	$t4,$f6
/*  f0aff74:	00000000 */ 	nop
/*  f0aff78:	a44c000c */ 	sh	$t4,0xc($v0)
/*  f0aff7c:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f0aff80:	c7a400d0 */ 	lwc1	$f4,0xd0($sp)
/*  f0aff84:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f0aff88:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0aff8c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0aff90:	440e4000 */ 	mfc1	$t6,$f8
/*  f0aff94:	00000000 */ 	nop
/*  f0aff98:	a44e000e */ 	sh	$t6,0xe($v0)
/*  f0aff9c:	c7aa00b0 */ 	lwc1	$f10,0xb0($sp)
/*  f0affa0:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f0affa4:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0affa8:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0affac:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0affb0:	44185000 */ 	mfc1	$t8,$f10
/*  f0affb4:	00000000 */ 	nop
/*  f0affb8:	a4580010 */ 	sh	$t8,0x10($v0)
/*  f0affbc:	c7a600b4 */ 	lwc1	$f6,0xb4($sp)
/*  f0affc0:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0affc4:	4606c202 */ 	mul.s	$f8,$f24,$f6
/*  f0affc8:	c7a600a8 */ 	lwc1	$f6,0xa8($sp)
/*  f0affcc:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0affd0:	46143102 */ 	mul.s	$f4,$f6,$f20
/*  f0affd4:	46045201 */ 	sub.s	$f8,$f10,$f4
/*  f0affd8:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f0affdc:	44083000 */ 	mfc1	$t0,$f6
/*  f0affe0:	00000000 */ 	nop
/*  f0affe4:	a4480018 */ 	sh	$t0,0x18($v0)
/*  f0affe8:	c7a400b8 */ 	lwc1	$f4,0xb8($sp)
/*  f0affec:	c7aa00d0 */ 	lwc1	$f10,0xd0($sp)
/*  f0afff0:	4604c202 */ 	mul.s	$f8,$f24,$f4
/*  f0afff4:	c7a400ac */ 	lwc1	$f4,0xac($sp)
/*  f0afff8:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f0afffc:	46142282 */ 	mul.s	$f10,$f4,$f20
/*  f0b0000:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*  f0b0004:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f0b0008:	440a2000 */ 	mfc1	$t2,$f4
/*  f0b000c:	00000000 */ 	nop
/*  f0b0010:	a44a001a */ 	sh	$t2,0x1a($v0)
/*  f0b0014:	c7aa00bc */ 	lwc1	$f10,0xbc($sp)
/*  f0b0018:	c7a600d4 */ 	lwc1	$f6,0xd4($sp)
/*  f0b001c:	460ac202 */ 	mul.s	$f8,$f24,$f10
/*  f0b0020:	c7aa00b0 */ 	lwc1	$f10,0xb0($sp)
/*  f0b0024:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f0b0028:	46145182 */ 	mul.s	$f6,$f10,$f20
/*  f0b002c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0b0030:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0b0034:	440c5000 */ 	mfc1	$t4,$f10
/*  f0b0038:	00000000 */ 	nop
/*  f0b003c:	a44c001c */ 	sh	$t4,0x1c($v0)
/*  f0b0040:	c7a600b4 */ 	lwc1	$f6,0xb4($sp)
/*  f0b0044:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0b0048:	4606c202 */ 	mul.s	$f8,$f24,$f6
/*  f0b004c:	c7a600a8 */ 	lwc1	$f6,0xa8($sp)
/*  f0b0050:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0b0054:	46143102 */ 	mul.s	$f4,$f6,$f20
/*  f0b0058:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0b005c:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f0b0060:	440e3000 */ 	mfc1	$t6,$f6
/*  f0b0064:	00000000 */ 	nop
/*  f0b0068:	a44e0024 */ 	sh	$t6,0x24($v0)
/*  f0b006c:	c7aa00b8 */ 	lwc1	$f10,0xb8($sp)
/*  f0b0070:	c7a400d0 */ 	lwc1	$f4,0xd0($sp)
/*  f0b0074:	460ac202 */ 	mul.s	$f8,$f24,$f10
/*  f0b0078:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*  f0b007c:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f0b0080:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0b0084:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0b0088:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0b008c:	44185000 */ 	mfc1	$t8,$f10
/*  f0b0090:	00000000 */ 	nop
/*  f0b0094:	a4580026 */ 	sh	$t8,0x26($v0)
/*  f0b0098:	c7a600bc */ 	lwc1	$f6,0xbc($sp)
/*  f0b009c:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0b00a0:	4606c202 */ 	mul.s	$f8,$f24,$f6
/*  f0b00a4:	c7a600b0 */ 	lwc1	$f6,0xb0($sp)
/*  f0b00a8:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0b00ac:	46143102 */ 	mul.s	$f4,$f6,$f20
/*  f0b00b0:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0b00b4:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f0b00b8:	44083000 */ 	mfc1	$t0,$f6
/*  f0b00bc:	00000000 */ 	nop
/*  f0b00c0:	a4480028 */ 	sh	$t0,0x28($v0)
/*  f0b00c4:	c7aa00b4 */ 	lwc1	$f10,0xb4($sp)
/*  f0b00c8:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0b00cc:	460ad202 */ 	mul.s	$f8,$f26,$f10
/*  f0b00d0:	c7aa00a8 */ 	lwc1	$f10,0xa8($sp)
/*  f0b00d4:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f0b00d8:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0b00dc:	46043201 */ 	sub.s	$f8,$f6,$f4
/*  f0b00e0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0b00e4:	440a5000 */ 	mfc1	$t2,$f10
/*  f0b00e8:	00000000 */ 	nop
/*  f0b00ec:	a44a0030 */ 	sh	$t2,0x30($v0)
/*  f0b00f0:	c7a400b8 */ 	lwc1	$f4,0xb8($sp)
/*  f0b00f4:	c7a600d0 */ 	lwc1	$f6,0xd0($sp)
/*  f0b00f8:	4604d202 */ 	mul.s	$f8,$f26,$f4
/*  f0b00fc:	c7a400ac */ 	lwc1	$f4,0xac($sp)
/*  f0b0100:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0b0104:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f0b0108:	46065201 */ 	sub.s	$f8,$f10,$f6
/*  f0b010c:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f0b0110:	440c2000 */ 	mfc1	$t4,$f4
/*  f0b0114:	00000000 */ 	nop
/*  f0b0118:	a44c0032 */ 	sh	$t4,0x32($v0)
/*  f0b011c:	c7a600bc */ 	lwc1	$f6,0xbc($sp)
/*  f0b0120:	c7aa00d4 */ 	lwc1	$f10,0xd4($sp)
/*  f0b0124:	4606d202 */ 	mul.s	$f8,$f26,$f6
/*  f0b0128:	c7a600b0 */ 	lwc1	$f6,0xb0($sp)
/*  f0b012c:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f0b0130:	46143282 */ 	mul.s	$f10,$f6,$f20
/*  f0b0134:	460a2201 */ 	sub.s	$f8,$f4,$f10
/*  f0b0138:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f0b013c:	440e3000 */ 	mfc1	$t6,$f6
/*  f0b0140:	00000000 */ 	nop
/*  f0b0144:	a44e0034 */ 	sh	$t6,0x34($v0)
/*  f0b0148:	c7aa00b4 */ 	lwc1	$f10,0xb4($sp)
/*  f0b014c:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0b0150:	460ad202 */ 	mul.s	$f8,$f26,$f10
/*  f0b0154:	c7aa00a8 */ 	lwc1	$f10,0xa8($sp)
/*  f0b0158:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f0b015c:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0b0160:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0b0164:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0b0168:	44185000 */ 	mfc1	$t8,$f10
/*  f0b016c:	00000000 */ 	nop
/*  f0b0170:	a458003c */ 	sh	$t8,0x3c($v0)
/*  f0b0174:	c7a600b8 */ 	lwc1	$f6,0xb8($sp)
/*  f0b0178:	c7a400d0 */ 	lwc1	$f4,0xd0($sp)
/*  f0b017c:	4606d202 */ 	mul.s	$f8,$f26,$f6
/*  f0b0180:	c7a600ac */ 	lwc1	$f6,0xac($sp)
/*  f0b0184:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0b0188:	46143102 */ 	mul.s	$f4,$f6,$f20
/*  f0b018c:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f0b0190:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f0b0194:	44083000 */ 	mfc1	$t0,$f6
/*  f0b0198:	00000000 */ 	nop
/*  f0b019c:	a448003e */ 	sh	$t0,0x3e($v0)
/*  f0b01a0:	c7aa00bc */ 	lwc1	$f10,0xbc($sp)
/*  f0b01a4:	c7a400d4 */ 	lwc1	$f4,0xd4($sp)
/*  f0b01a8:	460ad202 */ 	mul.s	$f8,$f26,$f10
/*  f0b01ac:	c7aa00b0 */ 	lwc1	$f10,0xb0($sp)
/*  f0b01b0:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f0b01b4:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0b01b8:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0b01bc:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0b01c0:	440a5000 */ 	mfc1	$t2,$f10
/*  f0b01c4:	00000000 */ 	nop
/*  f0b01c8:	a44a0040 */ 	sh	$t2,0x40($v0)
/*  f0b01cc:	8fb101e8 */ 	lw	$s1,0x1e8($sp)
/*  f0b01d0:	262c0008 */ 	addiu	$t4,$s1,0x8
/*  f0b01d4:	afac01e8 */ 	sw	$t4,0x1e8($sp)
/*  f0b01d8:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0b01dc:	ae2d0000 */ 	sw	$t5,0x0($s1)
/*  f0b01e0:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0b01e4:	8fae01e8 */ 	lw	$t6,0x1e8($sp)
/*  f0b01e8:	3c18b100 */ 	lui	$t8,0xb100
/*  f0b01ec:	3c195232 */ 	lui	$t9,0x5232
/*  f0b01f0:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0b01f4:	afaf01e8 */ 	sw	$t7,0x1e8($sp)
/*  f0b01f8:	37393210 */ 	ori	$t9,$t9,0x3210
/*  f0b01fc:	37184512 */ 	ori	$t8,$t8,0x4512
/*  f0b0200:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0b0204:	add90004 */ 	sw	$t9,0x4($t6)
.L0f0b0208:
/*  f0b0208:	3c08800a */ 	lui	$t0,%hi(var8009dd00)
/*  f0b020c:	2508dd00 */ 	addiu	$t0,$t0,%lo(var8009dd00)
/*  f0b0210:	26100048 */ 	addiu	$s0,$s0,72
/*  f0b0214:	5608fec9 */ 	bnel	$s0,$t0,.L0f0afd3c
/*  f0b0218:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f0b021c:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f0b0220:	8fa201e8 */ 	lw	$v0,0x1e8($sp)
/*  f0b0224:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f0b0228:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f0b022c:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f0b0230:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f0b0234:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f0b0238:	d7be0050 */ 	ldc1	$f30,0x50($sp)
/*  f0b023c:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f0b0240:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f0b0244:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f0b0248:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f0b024c:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f0b0250:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f0b0254:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f0b0258:	8fb70074 */ 	lw	$s7,0x74($sp)
/*  f0b025c:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*  f0b0260:	03e00008 */ 	jr	$ra
/*  f0b0264:	27bd01e8 */ 	addiu	$sp,$sp,0x1e8
);

// Mismatch: Two load instructions are swapped at afddc, and regalloc
//Gfx *lasersightRenderBeam(Gfx *gdl)
//{
//	f32 tmp;
//	struct player *player = g_Vars.currentplayer;
//	Mtxf *mtx;
//	s32 i;
//	Mtxf sp198;
//	struct coord campos; // 18c
//	Mtxf sp14c;
//	Mtxf sp10c;
//
//	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
//	gDPSetTextureFilter(gdl++, G_TF_BILERP);
//	gDPSetTexturePersp(gdl++, G_TP_PERSP);
//	gDPSetColorDither(gdl++, G_CD_DISABLE);
//	gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
//	gDPSetAlphaCompare(gdl++, G_AC_NONE);
//	gDPSetTextureLOD(gdl++, G_TL_TILE);
//	gDPSetTextureConvert(gdl++, G_TC_FILT);
//	gDPSetTextureLUT(gdl++, G_TT_NONE);
//	gDPSetCombineMode(gdl++, G_CC_BLENDIA, G_CC_BLENDIA);
//	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
//
//	texSelect(&gdl, &g_TexGeneralConfigs[3], 4, 0, 2, 1, NULL);
//	mtx4LoadIdentity(&sp14c);
//
//	mtx00015be0(camGetWorldToScreenMtxf(), &sp14c);
//	mtx4LoadIdentity(&sp10c);
//	mtx00015be0(camGetProjectionMtxF(), &sp10c);
//
//	sp10c.m[3][1] = 0;
//	sp10c.m[3][0] = 0;
//	sp10c.m[3][2] = 0;
//
//	mtx4LoadIdentity(&sp198);
//	mtx00015be0(camGetWorldToScreenMtxf(), &sp198);
//
//	campos.x = player->cam_pos.x;
//	campos.y = player->cam_pos.y;
//	campos.z = player->cam_pos.z;
//
//	sp198.m[3][0] = 0;
//	sp198.m[3][1] = 0;
//	sp198.m[3][2] = 0;
//
//	mtx00015f88(0.2f, &sp198);
//	mtx = gfxAllocateMatrix();
//	mtx00016054(&sp198, mtx);
//
//	gSPMatrix(gdl++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
//
//	for (i = 0; i < 4; i++) {
//		if (g_LaserSights[i].id != -1) {
//			u32 *colours;
//			struct coord spcc;
//			struct coord spc0;
//			struct coord spb4;
//			struct coord spa8;
//			struct gfxvtx *vertices;
//			struct coord sp98;
//
//			sp98.f[0] = g_LaserSights[i].beamnear.f[0];
//			sp98.f[1] = g_LaserSights[i].beamnear.f[1];
//			sp98.f[2] = g_LaserSights[i].beamnear.f[2];
//
//			mtx4TransformVecInPlace(&sp14c, &sp98);
//
//			spa8.f[0] = sp98.f[0] < 0.0f ? 1 : -1;
//			spa8.f[1] = 2;
//			spa8.f[2] = 0.0f;
//
//			guNormalize(&spa8.x, &spa8.y, &spa8.z);
//
//			mtx4RotateVecInPlace(&sp10c, &spa8);
//
//			spcc.f[0] = (g_LaserSights[i].beamnear.f[0] - campos.f[0]) * 5;
//			spcc.f[1] = (g_LaserSights[i].beamnear.f[1] - campos.f[1]) * 5;
//			spcc.f[2] = (g_LaserSights[i].beamnear.f[2] - campos.f[2]) * 5;
//
//			spc0.f[0] = (g_LaserSights[i].beamfar.f[0] - campos.f[0]) * 5;
//			spc0.f[1] = (g_LaserSights[i].beamfar.f[1] - campos.f[1]) * 5;
//			spc0.f[2] = (g_LaserSights[i].beamfar.f[2] - campos.f[2]) * 5;
//
//			spb4.f[0] = spc0.f[0] - spcc.f[0];
//			spb4.f[1] = spc0.f[1] - spcc.f[1];
//			spb4.f[2] = spc0.f[2] - spcc.f[2];
//
//			guNormalize(&spb4.x, &spb4.y, &spb4.z);
//
//			colours = gfxAllocateColours(2);
//
//			colours[0] = 0xff00005f;
//			colours[1] = 0xff00000f;
//
//			gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 2);
//
//			vertices = gfxAllocateVertices(6);
//
//			vertices[0].colour = 0;
//			vertices[1].colour = 0;
//			vertices[2].colour = 0;
//			vertices[3].colour = 0;
//			vertices[4].colour = 4;
//			vertices[5].colour = 4;
//
//			vertices[0].s = 0;
//			vertices[0].t = 0;
//			vertices[1].s = 0;
//			vertices[1].t = 256;
//			vertices[2].s = 32;
//			vertices[2].t = 0;
//			vertices[3].s = 32;
//			vertices[3].t = 256;
//			vertices[4].s = 0;
//			vertices[4].t = 0;
//			vertices[5].s = 0;
//			vertices[5].t = 256;
//
//			vertices[0].x = spcc.f[0] - spa8.f[0] * 15;
//			vertices[0].y = spcc.f[1] - spa8.f[1] * 15;
//			vertices[0].z = spcc.f[2] - spa8.f[2] * 15;
//
//			vertices[1].x = spcc.f[0] + spa8.f[0] * 15;
//			vertices[1].y = spcc.f[1] + spa8.f[1] * 15;
//			vertices[1].z = spcc.f[2] + spa8.f[2] * 15;
//
//			vertices[2].x = spcc.f[0] + (200 * spb4.f[0]) - (spa8.f[0] * 15);
//			vertices[2].y = spcc.f[1] + (200 * spb4.f[1]) - (spa8.f[1] * 15);
//			vertices[2].z = spcc.f[2] + (200 * spb4.f[2]) - (spa8.f[2] * 15);
//
//			vertices[3].x = spcc.f[0] + (200 * spb4.f[0]) + (spa8.f[0] * 15);
//			vertices[3].y = spcc.f[1] + (200 * spb4.f[1]) + (spa8.f[1] * 15);
//			vertices[3].z = spcc.f[2] + (200 * spb4.f[2]) + (spa8.f[2] * 15);
//
//			vertices[4].x = spcc.f[0] + (400 * spb4.f[0]) - (spa8.f[0] * 15);
//			vertices[4].y = spcc.f[1] + (400 * spb4.f[1]) - (spa8.f[1] * 15);
//			vertices[4].z = spcc.f[2] + (400 * spb4.f[2]) - (spa8.f[2] * 15);
//
//			vertices[5].x = spcc.f[0] + (400 * spb4.f[0]) + (spa8.f[0] * 15);
//			vertices[5].y = spcc.f[1] + (400 * spb4.f[1]) + (spa8.f[1] * 15);
//			vertices[5].z = spcc.f[2] + (400 * spb4.f[2]) + (spa8.f[2] * 15);
//
//			gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 6);
//
//			gDPTri4(gdl++, 0, 1, 2, 2, 3, 1, 2, 3, 5, 2, 5, 4);
//		}
//	}
//
//	return gdl;
//}

void lasersightSetBeam(s32 id, s32 arg1, struct coord *near, struct coord *far)
{
	s32 i;

	if (!lasersightExists(id, &i)) {
		if (i == -1) {
			return;
		}

		g_LaserSights[i].id = id;
	}

	g_LaserSights[i].unk04.x = near->x;
	g_LaserSights[i].unk04.y = near->y;
	g_LaserSights[i].unk04.z = near->z;

	g_LaserSights[i].beamnear.x = near->x;
	g_LaserSights[i].beamnear.y = near->y;
	g_LaserSights[i].beamnear.z = near->z;

	g_LaserSights[i].beamfar.x = far->x;
	g_LaserSights[i].beamfar.y = far->y;
	g_LaserSights[i].beamfar.z = far->z;

	g_LaserSights[i].unk44 = arg1;
	g_LaserSights[i].unk28 = 0;
}

void lasersightSetDot(s32 arg0, struct coord *pos, struct coord *rot)
{
	s32 i;

	if (lasersightExists(arg0, &i)) {
		g_LaserSights[i].unk28 += 1.0f;

		g_LaserSights[i].dotpos.x = pos->x;
		g_LaserSights[i].dotpos.y = pos->y;
		g_LaserSights[i].dotpos.z = pos->z;

		g_LaserSights[i].dotrot.x = rot->x;
		g_LaserSights[i].dotrot.y = rot->y;
		g_LaserSights[i].dotrot.z = rot->z;
	}
}

void lasersightFree(s32 arg0)
{
	s32 i;

	if (lasersightExists(arg0, &i)) {
		g_LaserSights[i].id = -1;
	}
}
