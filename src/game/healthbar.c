#include <ultra64.h>
#include "constants.h"
#include "game/player.h"
#include "game/healthbar.h"
#include "game/game_1531a0.h"
#include "game/gfxmemory.h"
#include "game/file.h"
#include "bss.h"
#include "lib/main.h"
#include "data.h"
#include "types.h"

struct marker {
	f32 x1;
	f32 y1;
	f32 x2;
	f32 y2;
	f32 frac;
};

s32 healthbarMaybeInsertMarker(struct marker *markers, s32 *indexes, s32 len, f32 fillfrac);

GLOBAL_ASM(
glabel healthbarMaybeInsertMarker
/*  f0d5a90:	44876000 */ 	mtc1	$a3,$f12
/*  f0d5a94:	44800000 */ 	mtc1	$zero,$f0
/*  f0d5a98:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0d5a9c:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f0d5aa0:	4600603c */ 	c.lt.s	$f12,$f0
/*  f0d5aa4:	00808025 */ 	or	$s0,$a0,$zero
/*  f0d5aa8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0d5aac:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d5ab0:	45000002 */ 	bc1f	.L0f0d5abc
/*  f0d5ab4:	00a02025 */ 	or	$a0,$a1,$zero
/*  f0d5ab8:	46000306 */ 	mov.s	$f12,$f0
.L0f0d5abc:
/*  f0d5abc:	44810000 */ 	mtc1	$at,$f0
/*  f0d5ac0:	24090014 */ 	addiu	$t1,$zero,0x14
/*  f0d5ac4:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0d5ac8:	00000000 */ 	nop
/*  f0d5acc:	45000002 */ 	bc1f	.L0f0d5ad8
/*  f0d5ad0:	00000000 */ 	nop
/*  f0d5ad4:	46000306 */ 	mov.s	$f12,$f0
.L0f0d5ad8:
/*  f0d5ad8:	18c0000a */ 	blez	$a2,.L0f0d5b04
/*  f0d5adc:	00001025 */ 	or	$v0,$zero,$zero
.L0f0d5ae0:
/*  f0d5ae0:	8c870000 */ 	lw	$a3,0x0($a0)
/*  f0d5ae4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0d5ae8:	0067082a */ 	slt	$at,$v1,$a3
/*  f0d5aec:	10200002 */ 	beqz	$at,.L0f0d5af8
/*  f0d5af0:	00000000 */ 	nop
/*  f0d5af4:	00e01825 */ 	or	$v1,$a3,$zero
.L0f0d5af8:
/*  f0d5af8:	1446fff9 */ 	bne	$v0,$a2,.L0f0d5ae0
/*  f0d5afc:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f0d5b00:	00001025 */ 	or	$v0,$zero,$zero
.L0f0d5b04:
/*  f0d5b04:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0d5b08:	18600051 */ 	blez	$v1,.L0f0d5c50
/*  f0d5b0c:	00a02025 */ 	or	$a0,$a1,$zero
.L0f0d5b10:
/*  f0d5b10:	8c860000 */ 	lw	$a2,0x0($a0)
/*  f0d5b14:	8c870004 */ 	lw	$a3,0x4($a0)
/*  f0d5b18:	00c90019 */ 	multu	$a2,$t1
/*  f0d5b1c:	00007012 */ 	mflo	$t6
/*  f0d5b20:	020e4021 */ 	addu	$t0,$s0,$t6
/*  f0d5b24:	c5000010 */ 	lwc1	$f0,0x10($t0)
/*  f0d5b28:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0d5b2c:	00000000 */ 	nop
/*  f0d5b30:	45020045 */ 	bc1fl	.L0f0d5c48
/*  f0d5b34:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0d5b38:	00e90019 */ 	multu	$a3,$t1
/*  f0d5b3c:	00007812 */ 	mflo	$t7
/*  f0d5b40:	020f3021 */ 	addu	$a2,$s0,$t7
/*  f0d5b44:	c4c20010 */ 	lwc1	$f2,0x10($a2)
/*  f0d5b48:	4602603c */ 	c.lt.s	$f12,$f2
/*  f0d5b4c:	00000000 */ 	nop
/*  f0d5b50:	4502003d */ 	bc1fl	.L0f0d5c48
/*  f0d5b54:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0d5b58:	c5100000 */ 	lwc1	$f16,0x0($t0)
/*  f0d5b5c:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*  f0d5b60:	c4c60004 */ 	lwc1	$f6,0x4($a2)
/*  f0d5b64:	c5080004 */ 	lwc1	$f8,0x4($t0)
/*  f0d5b68:	46102381 */ 	sub.s	$f14,$f4,$f16
/*  f0d5b6c:	c5040008 */ 	lwc1	$f4,0x8($t0)
/*  f0d5b70:	c4ca0008 */ 	lwc1	$f10,0x8($a2)
/*  f0d5b74:	46083481 */ 	sub.s	$f18,$f6,$f8
/*  f0d5b78:	00690019 */ 	multu	$v1,$t1
/*  f0d5b7c:	2469ffff */ 	addiu	$t1,$v1,-1
/*  f0d5b80:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f0d5b84:	0049082a */ 	slt	$at,$v0,$t1
/*  f0d5b88:	01203825 */ 	or	$a3,$t1,$zero
/*  f0d5b8c:	0009c880 */ 	sll	$t9,$t1,0x2
/*  f0d5b90:	e7a6002c */ 	swc1	$f6,0x2c($sp)
/*  f0d5b94:	46001181 */ 	sub.s	$f6,$f2,$f0
/*  f0d5b98:	c4c8000c */ 	lwc1	$f8,0xc($a2)
/*  f0d5b9c:	c50a000c */ 	lwc1	$f10,0xc($t0)
/*  f0d5ba0:	46006081 */ 	sub.s	$f2,$f12,$f0
/*  f0d5ba4:	e7a60020 */ 	swc1	$f6,0x20($sp)
/*  f0d5ba8:	0000c012 */ 	mflo	$t8
/*  f0d5bac:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f0d5bb0:	c7a80020 */ 	lwc1	$f8,0x20($sp)
/*  f0d5bb4:	02183021 */ 	addu	$a2,$s0,$t8
/*  f0d5bb8:	46081283 */ 	div.s	$f10,$f2,$f8
/*  f0d5bbc:	e7a40024 */ 	swc1	$f4,0x24($sp)
/*  f0d5bc0:	e7aa0008 */ 	swc1	$f10,0x8($sp)
/*  f0d5bc4:	c7a40008 */ 	lwc1	$f4,0x8($sp)
/*  f0d5bc8:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f0d5bcc:	46068200 */ 	add.s	$f8,$f16,$f6
/*  f0d5bd0:	e4c80000 */ 	swc1	$f8,0x0($a2)
/*  f0d5bd4:	c7a40008 */ 	lwc1	$f4,0x8($sp)
/*  f0d5bd8:	c50a0004 */ 	lwc1	$f10,0x4($t0)
/*  f0d5bdc:	46122182 */ 	mul.s	$f6,$f4,$f18
/*  f0d5be0:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0d5be4:	e4c80004 */ 	swc1	$f8,0x4($a2)
/*  f0d5be8:	c7a40008 */ 	lwc1	$f4,0x8($sp)
/*  f0d5bec:	c7aa002c */ 	lwc1	$f10,0x2c($sp)
/*  f0d5bf0:	c5080008 */ 	lwc1	$f8,0x8($t0)
/*  f0d5bf4:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f0d5bf8:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f0d5bfc:	e4c40008 */ 	swc1	$f4,0x8($a2)
/*  f0d5c00:	c7a80024 */ 	lwc1	$f8,0x24($sp)
/*  f0d5c04:	c7aa0008 */ 	lwc1	$f10,0x8($sp)
/*  f0d5c08:	c504000c */ 	lwc1	$f4,0xc($t0)
/*  f0d5c0c:	e4cc0010 */ 	swc1	$f12,0x10($a2)
/*  f0d5c10:	46085182 */ 	mul.s	$f6,$f10,$f8
/*  f0d5c14:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f0d5c18:	10200007 */ 	beqz	$at,.L0f0d5c38
/*  f0d5c1c:	e4ca000c */ 	swc1	$f10,0xc($a2)
/*  f0d5c20:	00b93021 */ 	addu	$a2,$a1,$t9
.L0f0d5c24:
/*  f0d5c24:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f0d5c28:	24e7ffff */ 	addiu	$a3,$a3,-1
/*  f0d5c2c:	24c6fffc */ 	addiu	$a2,$a2,-4
/*  f0d5c30:	1447fffc */ 	bne	$v0,$a3,.L0f0d5c24
/*  f0d5c34:	acca0008 */ 	sw	$t2,0x8($a2)
.L0f0d5c38:
/*  f0d5c38:	ac830004 */ 	sw	$v1,0x4($a0)
/*  f0d5c3c:	10000005 */ 	b	.L0f0d5c54
/*  f0d5c40:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0d5c44:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f0d5c48:
/*  f0d5c48:	1443ffb1 */ 	bne	$v0,$v1,.L0f0d5b10
/*  f0d5c4c:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f0d5c50:
/*  f0d5c50:	00001025 */ 	or	$v0,$zero,$zero
.L0f0d5c54:
/*  f0d5c54:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f0d5c58:	03e00008 */ 	jr	$ra
/*  f0d5c5c:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

u32 healthbarChooseColour(u32 fillcol, u32 bgcol, f32 fillexcfade, f32 fillincfade, f32 frac);

GLOBAL_ASM(
glabel healthbarChooseColour
/*  f0d5c60:	44877000 */ 	mtc1	$a3,$f14
/*  f0d5c64:	c7ac0010 */ 	lwc1	$f12,0x10($sp)
/*  f0d5c68:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f0d5c6c:	c7a40008 */ 	lwc1	$f4,0x8($sp)
/*  f0d5c70:	460c703e */ 	c.le.s	$f14,$f12
/*  f0d5c74:	00000000 */ 	nop
/*  f0d5c78:	45020004 */ 	bc1fl	.L0f0d5c8c
/*  f0d5c7c:	4604603e */ 	c.le.s	$f12,$f4
/*  f0d5c80:	03e00008 */ 	jr	$ra
/*  f0d5c84:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0d5c88:	4604603e */ 	c.le.s	$f12,$f4
.L0f0d5c8c:
/*  f0d5c8c:	00000000 */ 	nop
/*  f0d5c90:	45020004 */ 	bc1fl	.L0f0d5ca4
/*  f0d5c94:	c7a60008 */ 	lwc1	$f6,0x8($sp)
/*  f0d5c98:	03e00008 */ 	jr	$ra
/*  f0d5c9c:	00801025 */ 	or	$v0,$a0,$zero
/*  f0d5ca0:	c7a60008 */ 	lwc1	$f6,0x8($sp)
.L0f0d5ca4:
/*  f0d5ca4:	00041e02 */ 	srl	$v1,$a0,0x18
/*  f0d5ca8:	0005ce02 */ 	srl	$t9,$a1,0x18
/*  f0d5cac:	46066201 */ 	sub.s	$f8,$f12,$f6
/*  f0d5cb0:	332900ff */ 	andi	$t1,$t9,0xff
/*  f0d5cb4:	306e00ff */ 	andi	$t6,$v1,0xff
/*  f0d5cb8:	46067281 */ 	sub.s	$f10,$f14,$f6
/*  f0d5cbc:	00043402 */ 	srl	$a2,$a0,0x10
/*  f0d5cc0:	30cf00ff */ 	andi	$t7,$a2,0xff
/*  f0d5cc4:	012e5023 */ 	subu	$t2,$t1,$t6
/*  f0d5cc8:	460a4003 */ 	div.s	$f0,$f8,$f10
/*  f0d5ccc:	00043a02 */ 	srl	$a3,$a0,0x8
/*  f0d5cd0:	448a8000 */ 	mtc1	$t2,$f16
/*  f0d5cd4:	30f800ff */ 	andi	$t8,$a3,0xff
/*  f0d5cd8:	01e03025 */ 	or	$a2,$t7,$zero
/*  f0d5cdc:	00057c02 */ 	srl	$t7,$a1,0x10
/*  f0d5ce0:	03003825 */ 	or	$a3,$t8,$zero
/*  f0d5ce4:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f0d5ce8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0d5cec:	0306c823 */ 	subu	$t9,$t8,$a2
/*  f0d5cf0:	44994000 */ 	mtc1	$t9,$f8
/*  f0d5cf4:	00057a02 */ 	srl	$t7,$a1,0x8
/*  f0d5cf8:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f0d5cfc:	0307c823 */ 	subu	$t9,$t8,$a3
/*  f0d5d00:	30af00ff */ 	andi	$t7,$a1,0xff
/*  f0d5d04:	308800ff */ 	andi	$t0,$a0,0xff
/*  f0d5d08:	01e8c023 */ 	subu	$t8,$t7,$t0
/*  f0d5d0c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d5d10:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0d5d14:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d5d18:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0d5d1c:	44992000 */ 	mtc1	$t9,$f4
/*  f0d5d20:	440c3000 */ 	mfc1	$t4,$f6
/*  f0d5d24:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0d5d28:	01cc6821 */ 	addu	$t5,$t6,$t4
/*  f0d5d2c:	000d7600 */ 	sll	$t6,$t5,0x18
/*  f0d5d30:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0d5d34:	44988000 */ 	mtc1	$t8,$f16
/*  f0d5d38:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0d5d3c:	440a9000 */ 	mfc1	$t2,$f18
/*  f0d5d40:	00000000 */ 	nop
/*  f0d5d44:	00ca5821 */ 	addu	$t3,$a2,$t2
/*  f0d5d48:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0d5d4c:	000b6400 */ 	sll	$t4,$t3,0x10
/*  f0d5d50:	01cc6825 */ 	or	$t5,$t6,$t4
/*  f0d5d54:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0d5d58:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0d5d5c:	440a5000 */ 	mfc1	$t2,$f10
/*  f0d5d60:	00000000 */ 	nop
/*  f0d5d64:	00ea5821 */ 	addu	$t3,$a3,$t2
/*  f0d5d68:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d5d6c:	000b7200 */ 	sll	$t6,$t3,0x8
/*  f0d5d70:	01ae6025 */ 	or	$t4,$t5,$t6
/*  f0d5d74:	44093000 */ 	mfc1	$t1,$f6
/*  f0d5d78:	00000000 */ 	nop
/*  f0d5d7c:	01095021 */ 	addu	$t2,$t0,$t1
/*  f0d5d80:	018a1025 */ 	or	$v0,$t4,$t2
/*  f0d5d84:	03e00008 */ 	jr	$ra
/*  f0d5d88:	00000000 */ 	nop
);

/**
 * Terminology used in this function:
 *
 * armour - is the green part of the main health bar
 * trauma - is the red part of the main health bar
 * shield - is the green shield bar underneath the health bar
 * health - refers to armour + trauma collectively
 *
 * The health bar determines what shapes to draw by utilising markers. A marker
 * is a pair of vertices at a certain fraction (0.0 to 1.0) across a healthbar
 * element. Each marker's vertices are used to allocate proper graphics vertices
 * and are connected in order.
 *
 * For example, the green health part of the bar has a single marker on the left
 * at frac 0, then the next marker on the right side where the curve starts at
 * 0.9, then several markers in close proximity between 0.9 and 1.0 to implement
 * the rounded end.
 *
 * If the player's health falls between two markers, up to two two additional
 * markers will be created dynamically for colouring purposes. The coordinates
 * of these dynamic markers are tweened from the two neighbours. There are two
 * of these because the colour change uses a fade rather than a hard edge.
 */
Gfx *healthbarDraw(Gfx *gdl, struct chrdata *chr, s32 offyarg, f32 heightfracarg)
{
	struct marker shieldmarkers[12];
	struct marker armourmarkers[8];
	struct marker traumamarkers[8];
	s32 shieldmarkerindexes[12];
	s32 armourmarkerindexes[8];
	s32 traumamarkerindexes[8];
	struct gfxvtx *vertices;
	u32 *colours;
	u32 *shieldcolours;
	u32 *armourcolours;
	u32 *traumacolours;
	struct gfxvtx *shieldvertices;
	struct gfxvtx *armourvertices;
	struct gfxvtx *traumavertices;
	f32 shieldfillincfade;
	f32 shieldfillexcfade;
	f32 armourfillincfade;
	f32 armourfillexcfade;
	f32 traumafillincfade;
	f32 traumafillexcfade;
	struct marker *marker;
	s32 numshieldmarkers;
	s32 numtraumamarkers;
	s32 numarmourmarkers;
	f32 shieldfrac;
	f32 armourfrac;
	f32 traumafrac;
	f32 healthfrac;
	f32 heightfrac;
	u32 colour;
	s32 index;
	s32 i;
	s32 numverts;
	s32 numvertsremaining;
	f32 len0 = 0.0f;
	s32 coloursize;

	static s32 radmax = 30; // outer radius of the shield
	static s32 radmed = 18; // inner radius of the shield
	static s32 radmin = 12; // radius of the health bar
	static s32 len1 = 170; // x pos of right side radius centre
	static s32 len2 = 47;  // x pos of the left side of armour
	static s32 len3 = 40;  // x pos of the right side of trauma (left side is 0)
	static u32 shieldcol = 0x10500090;
	static u32 armourcol = 0x00c00060;
	static u32 traumacol = 0xff000060;
	static u32 bgcol = 0x00000080;
	static s32 offx = -85;
	static s32 offy = -185;
	static s32 shieldfade = 100;
	static s32 armourfade = 100;
	static s32 traumafade = 200;
	static s32 shielddir = 1;
	static s32 underleft = 95;
	static s32 undertop = 18;
	static s32 underright = 225;
	static s32 underbottom = 46;
	static u32 undercol = 0x00000000;

	vertices = gfxAllocateVertices(56);
	colours = gfxAllocateColours(56);

	// 12 markers (24 vertices) for shield
	// 8 markers (16 vertices) for armour
	// 8 markers (16 vertices) for trauma
	shieldvertices = vertices;
	armourvertices = vertices + 24;
	traumavertices = vertices + 40;

	shieldcolours = colours;
	armourcolours = colours + 24;
	traumacolours = colours + 40;

	mainOverrideVariable("radmax", &radmax);
	mainOverrideVariable("radmed", &radmed);
	mainOverrideVariable("radmin", &radmin);
	mainOverrideVariable("len1", &len1);
	mainOverrideVariable("len2", &len2);
	mainOverrideVariable("len3", &len3);
	mainOverrideVariable("offx", &offx);
	mainOverrideVariable("offy", &offy);
	mainOverrideVariable("shieldcol", &shieldcol);
	mainOverrideVariable("armourcol", &armourcol);
	mainOverrideVariable("traumacol", &traumacol);
	mainOverrideVariable("bgcol", &bgcol);
	mainOverrideVariable("shieldfade", &shieldfade);
	mainOverrideVariable("armourfade", &armourfade);
	mainOverrideVariable("traumafade", &traumafade);
	mainOverrideVariable("shielddir", &shielddir);
	mainOverrideVariable("underleft", &underleft);
	mainOverrideVariable("undertop", &undertop);
	mainOverrideVariable("underright", &underright);
	mainOverrideVariable("underbottom", &underbottom);
	mainOverrideVariable("undercol", &undercol);

	if (chr == NULL || offyarg <= 0 || heightfracarg <= 0.0f) {
		// Use the player's health
		shieldfrac = g_Vars.currentplayer->apparentarmour;
		armourfrac = (g_Vars.currentplayer->apparenthealth - 0.25f) / 0.75f;
		traumafrac = (0.25f - g_Vars.currentplayer->apparenthealth) * 4.0f;
		heightfrac = playerGetHealthBarHeightFrac();
	} else {
		// Use the given chr's health
		healthfrac = (chr->maxdamage - chr->damage) / chr->maxdamage;
		shieldfrac = chr->cshield * 0.125f;
		armourfrac = (healthfrac - 0.25f) / 0.75f;
		traumafrac = (0.25f - healthfrac) * 4.0f;
		heightfrac = heightfracarg;
		offy += offyarg;
	}

	armourfrac = armourfrac > 0 ? armourfrac : 0;
	traumafrac = traumafrac > 0 ? traumafrac : 0;

	for (i = 0; i < 12; i++) {
		shieldmarkerindexes[i] = i < 10 ? i : -1;

		if (i < 8) {
			armourmarkerindexes[i] = i < 6 ? i : -1;
			traumamarkerindexes[i] = i < 6 ? i : -1;
		}
	}

	/**
	 * Shield markers
	 *
	 * This is actually defined and drawn right to left rather than left to
	 * right, but is coloured the other way around using the shielddir variable.
	 *
	 * len0 - is the X position of the left side, and is defined as 0.
	 *        A variable must be used in some places for this to match, and a
	 *        literal 0 in others. It's even required in a Y value for a match.
	 * len1 - is the X position of the right side.
	 */
	shieldmarkers[0].x1 = len1 + radmax * 1.08f;
	shieldmarkers[0].y1 = 0;
	shieldmarkers[0].x2 = len1 + (f32)radmed;
	shieldmarkers[0].y2 = 0;
	shieldmarkers[0].frac = 0;

	shieldmarkers[1].x1 = len1 + radmax * 0.924f * 1.04f;
	shieldmarkers[1].y1 = heightfrac * radmax * 0.383f;
	shieldmarkers[1].x2 = len1 + radmed * 0.924f;
	shieldmarkers[1].y2 = heightfrac * radmed * 0.383f;
	shieldmarkers[1].frac = 0.05f;

	shieldmarkers[2].x1 = len1 + radmax * 0.707f * 1.02f;
	shieldmarkers[2].y1 = heightfrac * radmax * 0.707f;
	shieldmarkers[2].x2 = len1 + radmed * 0.707f;
	shieldmarkers[2].y2 = heightfrac * radmed * 0.707f;
	shieldmarkers[2].frac = 0.1f;

	shieldmarkers[3].x1 = len1 + radmax * 0.383f;
	shieldmarkers[3].y1 = heightfrac * radmax * 0.924f;
	shieldmarkers[3].x2 = len1 + radmed * 0.383f;
	shieldmarkers[3].y2 = heightfrac * radmed * 0.924f;
	shieldmarkers[3].frac = 0.15f;

	shieldmarkers[4].x1 = len1;
	shieldmarkers[4].y1 = heightfrac * radmax;
	shieldmarkers[4].x2 = len1;
	shieldmarkers[4].y2 = heightfrac * radmed;
	shieldmarkers[4].frac = 0.2f;

	shieldmarkers[5].x1 = len0;
	shieldmarkers[5].y1 = heightfrac * radmax;
	shieldmarkers[5].x2 = len0;
	shieldmarkers[5].y2 = heightfrac * radmed;
	shieldmarkers[5].frac = 0.8f;

	shieldmarkers[6].x1 = len0 - radmax * 0.383f;
	shieldmarkers[6].y1 = heightfrac * radmax * 0.924f;
	shieldmarkers[6].x2 = len0 - radmed * 0.383f;
	shieldmarkers[6].y2 = heightfrac * radmed * 0.924f;
	shieldmarkers[6].frac = 0.85f;

	shieldmarkers[7].x1 = 0.0f - radmax * 0.707f * 1.02f;
	shieldmarkers[7].y1 = heightfrac * radmax * 0.707f;
	shieldmarkers[7].x2 = 0.0f - radmed * 0.707f;
	shieldmarkers[7].y2 = heightfrac * radmed * 0.707f;
	shieldmarkers[7].frac = 0.9f;

	shieldmarkers[8].x1 = len0 - radmax * 0.924f * 1.04f;
	shieldmarkers[8].y1 = heightfrac * radmax * 0.383f;
	shieldmarkers[8].x2 = len0 - radmed * 0.924f;
	shieldmarkers[8].y2 = heightfrac * radmed * 0.383f;
	shieldmarkers[8].frac = 0.95f;

	shieldmarkers[9].x1 = len0 - radmax * 1.08f;
	shieldmarkers[9].y1 = len0;
	shieldmarkers[9].x2 = len0 - radmed;
	shieldmarkers[9].y2 = len0;
	shieldmarkers[9].frac = 1;

	/**
	 * Armour markers
	 *
	 * Drawn left to right as expected.
	 *
	 * len2 - is the X position of the left side.
	 * len1 - is the X position of the right side.
	 */
	armourmarkers[0].x1 = len2;
	armourmarkers[0].y1 = heightfrac * radmin;
	armourmarkers[0].x2 = len2;
	armourmarkers[0].y2 = -heightfrac * radmin;
	armourmarkers[0].frac = 0;

	armourmarkers[1].x1 = len1;
	armourmarkers[1].y1 = heightfrac * radmin;
	armourmarkers[1].x2 = len1;
	armourmarkers[1].y2 = -heightfrac * radmin;
	armourmarkers[1].frac = 0.9f;

	armourmarkers[2].x1 = len1 + radmin * 0.342f;
	armourmarkers[2].y1 = heightfrac * radmin * 0.94f;
	armourmarkers[2].x2 = len1 + radmin * 0.342f;
	armourmarkers[2].y2 = -heightfrac * radmin * 0.94f;
	armourmarkers[2].frac = 0.94f;

	armourmarkers[3].x1 = len1 + radmin * 0.643f;
	armourmarkers[3].y1 = heightfrac * radmin * 0.766f;
	armourmarkers[3].x2 = len1 + radmin * 0.643f;
	armourmarkers[3].y2 = -heightfrac * radmin * 0.766f;
	armourmarkers[3].frac = 0.97f;

	armourmarkers[4].x1 = len1 + radmin * 0.866f;
	armourmarkers[4].y1 = heightfrac * radmin * 0.5f;
	armourmarkers[4].x2 = len1 + radmin * 0.866f;
	armourmarkers[4].y2 = -heightfrac * radmin * 0.5f;
	armourmarkers[4].frac = 0.99f;

	armourmarkers[5].x1 = len1 + radmin * 0.985f;
	armourmarkers[5].y1 = heightfrac * radmin * 0.174f;
	armourmarkers[5].x2 = len1 + radmin * 0.985f;
	armourmarkers[5].y2 = -heightfrac * radmin * 0.174f;
	armourmarkers[5].frac = 1;

	/**
	 * Trauma markers
	 *
	 * Drawn right to left because it fills right to left.
	 *
	 * len0 - is the X position of the left side. Like the shield markers, this
	 *        is defined as 0 and must only be used sometimes.
	 * len3 - is the X position of the right side.
	 *
	 * Note that the trailing 0 on 0.7070f is absolutely required for a match.
	 *
	 * Fun fact: There are also trauma markers on my brain after matching this
	 * code.
	 */
	traumamarkers[0].x1 = len3;
	traumamarkers[0].y1 = heightfrac * radmin;
	traumamarkers[0].x2 = len3;
	traumamarkers[0].y2 = -heightfrac * radmin;
	traumamarkers[0].frac = 0;

	traumamarkers[1].x1 = 0.0f;
	traumamarkers[1].y1 = heightfrac * radmin;
	traumamarkers[1].x2 = 0.0f;
	traumamarkers[1].y2 = -heightfrac * radmin;
	traumamarkers[1].frac = 0.8f;

	traumamarkers[2].x1 = 0.0f - radmin * 0.383f;
	traumamarkers[2].y1 = heightfrac * radmin * 0.924f;
	traumamarkers[2].x2 = 0.0f - radmin * 0.383f;
	traumamarkers[2].y2 = -heightfrac * radmin * 0.924f;
	traumamarkers[2].frac = 0.85f;

	traumamarkers[3].x1 = 0.0f - radmin * 0.707f;
	traumamarkers[3].y1 = heightfrac * radmin * 0.7070f;
	traumamarkers[3].x2 = 0.0f - radmin * 0.707f;
	traumamarkers[3].y2 = -heightfrac * radmin * 0.7070f;
	traumamarkers[3].frac = 0.9f;

	traumamarkers[4].x1 = len0 - radmin * 0.924f;
	traumamarkers[4].y1 = heightfrac * radmin * 0.383f;
	traumamarkers[4].x2 = len0 - radmin * 0.924f;
	traumamarkers[4].y2 = -heightfrac * radmin * 0.383f;
	traumamarkers[4].frac = 0.95f;

	traumamarkers[5].x1 = len0 - radmin;
	traumamarkers[5].y1 = 0.0f;
	traumamarkers[5].x2 = len0 - radmin;
	traumamarkers[5].y2 = 0.0f;
	traumamarkers[5].frac = 1;

	// Build shield graphics data
	if (shielddir != 0) {
		shieldfrac = 1.0f - shieldfrac;
	}

	shieldfillincfade = shieldfade * 0.001f;
	shieldfillincfade = (1.0f + shieldfillincfade) * shieldfrac;
	shieldfillexcfade = shieldfillincfade - shieldfade * 0.001f;

	numshieldmarkers = 10;
	numshieldmarkers += healthbarMaybeInsertMarker(shieldmarkers, shieldmarkerindexes, ARRAYCOUNT(shieldmarkers), shieldfillexcfade);
	numshieldmarkers += healthbarMaybeInsertMarker(shieldmarkers, shieldmarkerindexes, ARRAYCOUNT(shieldmarkers), shieldfillincfade);

	for (i = 0; i < numshieldmarkers; i++) {
		index = shieldmarkerindexes[i];
		marker = &shieldmarkers[index];

		if (shielddir != 0) {
			colour = healthbarChooseColour(bgcol, shieldcol, shieldfillexcfade, shieldfillincfade, marker->frac);
		} else {
			colour = healthbarChooseColour(shieldcol, bgcol, shieldfillexcfade, shieldfillincfade, marker->frac);
		}

		shieldvertices->x = (s32)marker->x1 + offx;
		shieldvertices->y = 0;
		shieldvertices->z = (s32)marker->y1 + offy;
		shieldvertices->colour = (i + i) << 2;
		shieldvertices++;

		*shieldcolours = colour;
		shieldcolours++;

		shieldvertices->x = (s32)marker->x2 + offx;
		shieldvertices->y = 0;
		shieldvertices->z = (s32)marker->y2 + offy;
		shieldvertices->colour = (i + i + 1) << 2;
		shieldvertices++;

		*shieldcolours = colour;
		shieldcolours++;
	}

	// Build armour graphics data
	armourfillincfade = armourfade * 0.001f;
	armourfillincfade = (1.0f + armourfillincfade) * armourfrac;
	armourfillexcfade = armourfillincfade - armourfade * 0.001f;

	numarmourmarkers = 6;
	numarmourmarkers += healthbarMaybeInsertMarker(armourmarkers, armourmarkerindexes, ARRAYCOUNT(armourmarkers), armourfillexcfade);
	numarmourmarkers += healthbarMaybeInsertMarker(armourmarkers, armourmarkerindexes, ARRAYCOUNT(armourmarkers), armourfillincfade);

	for (i = 0; i < numarmourmarkers; i++) {
		index = armourmarkerindexes[i];
		marker = &armourmarkers[index];

		colour = healthbarChooseColour(armourcol, bgcol, armourfillexcfade, armourfillincfade, marker->frac);

		armourvertices->x = (s32)marker->x1 + offx;
		armourvertices->y = 0;
		armourvertices->z = (s32)marker->y1 + offy;
		armourvertices->colour = (i + i) << 2;
		armourvertices++;

		*armourcolours = colour;
		armourcolours++;

		armourvertices->x = (s32)marker->x2 + offx;
		armourvertices->y = 0;
		armourvertices->z = (s32)marker->y2 + offy;
		armourvertices->colour = (i + i + 1) << 2;
		armourvertices++;

		*armourcolours = colour;
		armourcolours++;
	}

	// Build trauma graphics data
	traumafillincfade = traumafade * 0.001f;
	traumafillincfade = (1.0f + traumafillincfade) * traumafrac;
	traumafillexcfade = traumafillincfade - traumafade * 0.001f;

	numtraumamarkers = 6;
	numtraumamarkers += healthbarMaybeInsertMarker(traumamarkers, traumamarkerindexes, ARRAYCOUNT(traumamarkers), traumafillexcfade);
	numtraumamarkers += healthbarMaybeInsertMarker(traumamarkers, traumamarkerindexes, ARRAYCOUNT(traumamarkers), traumafillincfade);

	for (i = 0; i < numtraumamarkers; i++) {
		index = traumamarkerindexes[i];
		marker = &traumamarkers[index];

		colour = healthbarChooseColour(traumacol, bgcol, traumafillexcfade, traumafillincfade, marker->frac);

		traumavertices->x = (s32)marker->x1 + offx;
		traumavertices->y = 0;
		traumavertices->z = (s32)marker->y1 + offy;
		traumavertices->colour = (i + i) << 2;
		traumavertices++;

		*traumacolours = colour;
		traumacolours++;

		traumavertices->x = (s32)marker->x2 + offx;
		traumavertices->y = 0;
		traumavertices->z = (s32)marker->y2 + offy;
		traumavertices->colour = (i + i + 1) << 2;
		traumavertices++;

		*traumacolours = colour;
		traumacolours++;
	}

	gdl = func0f153628(gdl);
	gdl = func0f153a34(gdl, underleft, undertop, underright, underbottom, undercol);
	gdl = func0f153780(gdl);

	gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
	gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);

	// Draw shield
	// There's between 20 and 24 colours and vertices to load here.
	// The colours are loaded all at once, but the vertices are split into two.
	numverts = numshieldmarkers * 2;

	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), numverts);
	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 14);

	gDPTri4(gdl++, 0, 1, 2, 1, 2, 3, 2, 3, 4, 3, 4, 5);
	gDPTri4(gdl++, 4, 5, 6, 5, 6, 7, 6, 7, 8, 7, 8, 9);
	gDPTri4(gdl++, 8, 9, 10, 9, 10, 11, 10, 11, 12, 11, 12, 13);

	// numvertsremaining will be 8-12
	numvertsremaining = numverts - 12U;

	gDPSetVerticeArrayRaw(gdl++, osVirtualToPhysical(vertices + 12), (numverts - 13) << 4, numvertsremaining * (s32)sizeof(struct gfxvtx));

	gDPTri4(gdl++, 0, 1, 2, 1, 2, 3, 2, 3, 4, 3, 4, 5);

	if (numvertsremaining < 10) {
		gDPTri2(gdl++, 4, 5, 6, 5, 6, 7);
	} else {
		gDPTri4(gdl++, 4, 5, 6, 5, 6, 7, 6, 7, 8, 7, 8, 9);

		if (numvertsremaining >= 12) {
			gDPTri2(gdl++, 8, 9, 10, 9, 10, 11);
		}
	}

	// Draw armour
	numverts = numarmourmarkers * 2;
	coloursize = numverts * 4;

	gDPSetColorArray(gdl++, osVirtualToPhysical(colours + 24), numverts);
	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices + 24), numverts);

	gDPTri4(gdl++, 0, 1, 2, 1, 2, 3, 2, 3, 4, 3, 4, 5);
	gDPTri4(gdl++, 4, 5, 6, 5, 6, 7, 6, 7, 8, 7, 8, 9);

	if (coloursize < 56) {
		gDPTri2(gdl++, 8, 9, 10, 9, 10, 11);
	} else {
		gDPTri4(gdl++, 8, 9, 10, 9, 10, 11, 10, 11, 12, 11, 12, 13);

		if (coloursize >= 64) {
			gDPTri2(gdl++, 12, 13, 14, 13, 14, 15);
		}
	}

	// Draw trauma
	numverts = numtraumamarkers * 2;
	coloursize = numverts * 4;

	gDPSetColorArray(gdl++, osVirtualToPhysical(colours + 40), numverts);
	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices + 40), numverts);

	gDPTri4(gdl++, 0, 1, 2, 1, 2, 3, 2, 3, 4, 3, 4, 5);
	gDPTri4(gdl++, 4, 5, 6, 5, 6, 7, 6, 7, 8, 7, 8, 9);

	if (coloursize < 56) {
		gDPTri2(gdl++, 8, 9, 10, 9, 10, 11);
	} else {
		gDPTri4(gdl++, 8, 9, 10, 9, 10, 11, 10, 11, 12, 11, 12, 13);

		if (coloursize >= 64) {
			gDPTri2(gdl++, 12, 13, 14, 13, 14, 15);
		}
	}

	return gdl;
}
