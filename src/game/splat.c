#include <ultra64.h>
#include "constants.h"
#include "game/smoke.h"
#include "game/bg.h"
#include "game/propobj.h"
#include "game/splat.h"
#include "game/utils.h"
#include "game/wallhit.h"
#include "bss.h"
#include "lib/model.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

#if VERSION < VERSION_NTSC_1_0
u32 var80082100nb = 0;
#endif

u32 var8007f8a0 = 0x3e19999a;
u32 var8007f8a4 = 0x40400000;
f32 var8007f8a8 = 12;
u32 var8007f8ac = 0x00000008;
f32 g_SplatMaxDistance = 180;
u32 var8007f8b4 = 0x40a00000;
u32 var8007f8b8 = 0x42480000;

void splatTickChr(struct prop *prop)
{
	struct chrdata *chr = prop->chr;
	struct chrdata *attacker = chr->lastattacker;
	s32 race;

	if (chr->noblood || (chr->chrflags & CHRCFLAG_HIDDEN) || chr->bulletstaken == 0) {
		return;
	}

	race = CHRRACE(chr);

	if (race != RACE_DRCAROLL && race != RACE_ROBOT) {
		u8 isskedar = false;

		if (race == RACE_SKEDAR || chr->bodynum == BODY_MRBLONDE) {
			isskedar = true;
		}

		osSyncPrintf("Splat Tick - P=%x, B=%d, T=%d, S=%d, W=%d, D=%d, H=%d\n");

		if (chr->actiontype == ACT_DEAD || chr->actiontype == ACT_DIE) {
			u32 stack;
			f32 thudframe = -1.0f;

			if (chr->actiontype == ACT_DIE) {
				if (chr->act_die.thudframe2 != -1) {
					thudframe = chr->act_die.thudframe2;
				} else if (chr->act_die.thudframe1 != -1) {
					thudframe = chr->act_die.thudframe1;
				}
			}

			if (thudframe != -1.0f && modelGetCurAnimFrame(chr->model) < thudframe) {
				osSyncPrintf("SPLAT : Not Dead Enough %s%s%f", "", "", modelGetCurAnimFrame(chr->model));
			} else if (chr->tickssincesplat > TICKS(30) && chr->deaddropsplatsadded < 6) {
				chr->deaddropsplatsadded += splatsCreate(1, 1.1f, prop, NULL, 0, 0, isskedar, 1, TICKS(150), attacker, random() & 8);
			}
		} else {
			// Consider creating a wounded drop
			u32 value = chr->bulletstaken * chr->tickssincesplat;

			if (value > TICKS(240)) {
				f32 dist = coordsGetDistance(&chr->lastdroppos, &prop->pos);
				s32 addmore = false;

				if (dist > 40) {
					addmore = true;
					chr->splatsdroppedhere = 0;
				} else if (chr->splatsdroppedhere < 8) {
					addmore = true;
					chr->splatsdroppedhere++;
				}

				if (addmore) {
					chr->woundedsplatsadded += splatsCreate(1, 0.3f, prop, NULL, 0, 0, isskedar, 2, TICKS(80), attacker, 0);
				}
			}

			if (chr->woundedsplatsadded >= 40) {
				wallhitRemoveOldestWoundedSplatByChr(prop);
				chr->woundedsplatsadded--;
			}

			chr->deaddropsplatsadded = 0;
		}
	}

	chr->tickssincesplat += g_Vars.lvupdate240_60;
}

void splatsCreateForChrHit(struct prop *prop, struct shotdata *arg1, struct coord *arg2, struct coord *arg3, s32 arg4, s32 arg5, struct chrdata *arg6)
{
#if VERSION != VERSION_JPN_FINAL
	struct chrdata *chr = prop->chr;

	if (chr->bulletstaken < 7) {
		chr->bulletstaken++;
	}

	if (arg5 == 0) {
		u32 rand = random() % 3;

		if (rand) {
			chr->stdsplatsadded += splatsCreate(rand, 0.8f, prop, arg1, arg2, arg3, arg4, arg5, TICKS(50), arg6, 0);
		}
	}
#endif
}

s32 splatsCreate(s32 qty, f32 arg1, struct prop *prop, struct shotdata *arg3, struct coord *arg4, struct coord *arg5, s32 arg6, s32 arg7, s32 arg8, struct chrdata *arg9, s32 arg10)
{
#if VERSION == VERSION_JPN_FINAL
	return 0;
#else
	struct shotdata stackshotdata;
	struct shotdata *shotdata = arg7 == 0 ? arg3 : &stackshotdata;
	struct coord spfc;
	struct coord spf0;
	struct coord spe4;
	Mtxf spa4;
	s32 numdropped = 0;
	f32 dist;
	s32 i;
	s32 j;

	if (arg7 == 0) {
		dist = coordsGetDistance(&shotdata->gunpos, arg5);

		for (i = 0; i < 3; i++) {
			spfc.f[i] = shotdata->dir.f[i];
			spf0.f[i] = shotdata->unk0c.f[i];
			shotdata->gunpos.f[i] = arg5->f[i];
			shotdata->unk00.f[i] = arg4->f[i];
		}
	} else {
		f32 extraheight;

		if (prop->type == PROPTYPE_CHR) {
			extraheight = 50;
		} else {
			extraheight = 0;
		}

		dist = 0.7f;

		spfc.x = shotdata->dir.x = 0;
		spfc.y = shotdata->dir.y = -1;
		spfc.z = shotdata->dir.z = 0;

		spf0.x = shotdata->unk0c.x = 0;
		spf0.y = shotdata->unk0c.y = -1;
		spf0.z = shotdata->unk0c.z = 0;

		shotdata->gunpos.x = prop->pos.x;
		shotdata->gunpos.y = prop->pos.y + extraheight;
		shotdata->gunpos.z = prop->pos.z;

		shotdata->unk00.x = prop->pos.x;
		shotdata->unk00.y = prop->pos.y + extraheight;
		shotdata->unk00.z = prop->pos.z;
	}

	for (i = 0; i < qty; i++) {
		for (j = 0; j < 3; j++) {
			spe4.f[j] = (RANDOMFRAC() * var8007f8a8 * 2.0f - var8007f8a8) * 0.017453292384744f;
		}

		mtx4LoadRotation(&spe4, &spa4);
		mtx4RotateVec(&spa4, &spfc, &shotdata->dir);
		mtx4RotateVec(&spa4, &spf0, &shotdata->unk0c);

#if VERSION >= VERSION_NTSC_1_0
		func0f177164(&shotdata->dir, &shotdata->dir, 403, "splat.c");
		func0f177164(&shotdata->unk0c, &shotdata->unk0c, 404, "splat.c");
#else
		func0f177164(&shotdata->dir, &shotdata->dir, 405, "splat.c");
		func0f177164(&shotdata->unk0c, &shotdata->unk0c, 406, "splat.c");
#endif

		if (splat0f149274(arg1, prop, shotdata, dist, arg6, arg7, arg8, arg9, arg10)) {
			numdropped++;
		}
	}

	if (numdropped) {
		struct chrdata *chr = prop->chr;

		chr->tickssincesplat = 0;
		chr->lastdroppos.x = prop->pos.x;
		chr->lastdroppos.y = prop->pos.y;
		chr->lastdroppos.z = prop->pos.z;
	}

	return numdropped;
#endif
}

struct splatdata {
	struct coord unk00;
	struct coord unk0c;
	struct coord unk18;
	struct coord gunpos;
	s32 unk30;
	struct prop *prop34;
	struct prop *prop38;
	struct chrdata *chr;
	s32 unk40;
	s32 unk44;
	s32 unk48;
	s32 unk4c;
	f32 unk50;
	s32 unk54;
	s32 unk58;
};

void func0f14986c(struct splatdata *splatdata);

#if VERSION == VERSION_JPN_FINAL
const char var7f1b5fe0[] = "Splat : Out of range\n";
#else
bool splat0f149274(f32 arg0, struct prop *prop, struct shotdata *shotdata, f32 arg3, s32 arg4, s32 arg5, s32 arg6, struct chrdata *chr, s32 arg8)
{
	struct prop **propptr;
	struct prop *hitprop;
	struct hitthing hitthing;
	struct hitthing besthitthing;
	s16 rooms[32];
	s16 gunrooms[8];
	s16 endrooms[8];
	struct coord endpos;
	s32 i;
	struct coord *sp50c;
	struct coord *hitpos;
	struct coord *sp504;
	s32 bestroom = 0;
	s32 sp4fc;
	s32 sp4f8;
	f32 spraydistance;
	s32 sp4f0;
	bool hasresult = false;
	struct shotdata stackshotdata;

	for (i = 0; i < 3; i++) {
		stackshotdata.unk00.f[i] = shotdata->unk00.f[i];
		stackshotdata.unk0c.f[i] = shotdata->unk0c.f[i];
		stackshotdata.gunpos.f[i] = shotdata->gunpos.f[i];
		stackshotdata.dir.f[i] = shotdata->dir.f[i];
	}

	stackshotdata.unk38 = 1;

	for (i = 0; i < 3; i++) {
		endpos.f[i] = stackshotdata.gunpos.f[i] + stackshotdata.dir.f[i] * g_SplatMaxDistance;
	}

	portal00018148(&prop->pos, &stackshotdata.gunpos, prop->rooms, &gunrooms, NULL, 0);
	portal00018148(&stackshotdata.gunpos, &endpos, &gunrooms, &endrooms, rooms, ARRAYCOUNT(rooms) - 1);

	for (i = 0; rooms[i] != -1; i++) {
		if (func0f161520(&stackshotdata.gunpos, &endpos, rooms[i], &hitthing)
				&& ((stackshotdata.gunpos.x <= endpos.x && hitthing.unk00.x <= endpos.x && stackshotdata.gunpos.x <= hitthing.unk00.x) || (endpos.x <= stackshotdata.gunpos.x && endpos.x <= hitthing.unk00.x && hitthing.unk00.x <= stackshotdata.gunpos.x))
					&& ((stackshotdata.gunpos.y <= endpos.y && hitthing.unk00.y <= endpos.y && stackshotdata.gunpos.y <= hitthing.unk00.y) || (endpos.y <= stackshotdata.gunpos.y && endpos.y <= hitthing.unk00.y && hitthing.unk00.y <= stackshotdata.gunpos.y))
					&& ((stackshotdata.gunpos.z <= endpos.z && hitthing.unk00.z <= endpos.z && stackshotdata.gunpos.z <= hitthing.unk00.z) || (endpos.z <= stackshotdata.gunpos.z && endpos.z <= hitthing.unk00.z && hitthing.unk00.z <= stackshotdata.gunpos.z))) {
			if (stackshotdata.gunpos.x != hitthing.unk00.x || stackshotdata.gunpos.y != hitthing.unk00.y || stackshotdata.gunpos.z != hitthing.unk00.z) {
				bestroom = rooms[i];
				besthitthing = hitthing;

				endpos.x = hitthing.unk00.x;
				endpos.y = hitthing.unk00.y;
				endpos.z = hitthing.unk00.z;

				hasresult = true;
				break;
			}
		}
	}

	if (hasresult) {
		spraydistance = coordsGetDistance(&stackshotdata.gunpos, &besthitthing.unk00);

		if (spraydistance < g_SplatMaxDistance) {
			sp50c = &hitthing.unk00;
			hitpos = &hitthing.unk00;
			sp504 = &hitthing.unk0c;
			hitprop = NULL;
			sp4fc = 0;
			sp4f8 = bestroom;
			sp4f0 = hitthing.unk2c == 2;
		} else {
			osSyncPrintf("Splat : Out of range\n");
			hasresult = false;
		}
	} else {
		spraydistance = 999999.0f;
	}

	if (arg5 == 0) {
		stackshotdata.unk34 = (spraydistance < g_SplatMaxDistance ? spraydistance : g_SplatMaxDistance);
		stackshotdata.unk34 += arg3;

		for (i = 0; i < ARRAYCOUNT(stackshotdata.hits); i++) {
			stackshotdata.hits[i].prop = NULL;
			stackshotdata.hits[i].hitpart = 0;
			stackshotdata.hits[i].node = NULL;
		}

		propptr = g_Vars.endonscreenprops - 1;

		while (propptr >= g_Vars.onscreenprops) {
			struct prop *prop = *propptr;

			if (prop) {
				if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_DOOR || prop->type == PROPTYPE_WEAPON) {
					func0f085e00(prop, &stackshotdata);
					if (1);
				}
			}

			propptr--;
		}

		for (i = 0; i < ARRAYCOUNT(stackshotdata.hits); i++) {
			struct hit *hit = &stackshotdata.hits[i];

			if (hit->prop && (hit->hitthing.texturenum < 0
						|| hit->hitthing.texturenum >= NUM_TEXTURES
						|| g_SurfaceTypes[g_Textures[hit->hitthing.texturenum].surfacetype]->numwallhittexes != 0)) {
				sp50c = &hit->hitthing.unk00;
				hitpos = &hit->pos;
				sp504 = &hit->hitthing.unk0c;
				hitprop = hit->prop;
				sp4fc = (s8)hit->mtxindex;
				sp4f8 = 1;
				sp4f0 = 0;
				hasresult = true;
				break;
			}
		}
	}

	if (hasresult) {
		struct splatdata splatdata;
		u32 stack;

		for (i = 0; i < 3; i++) {
			splatdata.unk00.f[i] = sp50c->f[i];
			splatdata.unk0c.f[i] = hitpos->f[i];
			splatdata.gunpos.f[i] = stackshotdata.gunpos.f[i];
			splatdata.unk18.f[i] = sp504->f[i];
		}

		splatdata.prop38 = prop;
		splatdata.prop34 = hitprop;
		splatdata.chr = chr;
		splatdata.unk40 = sp4fc;
		splatdata.unk44 = sp4f8;
		splatdata.unk48 = arg4;
		splatdata.unk54 = arg6;
		splatdata.unk50 = arg0;
		splatdata.unk30 = arg5;
		splatdata.unk58 = arg8;
		splatdata.unk4c = sp4f0;

		func0f14986c(&splatdata);

		return true;
	}

	if (hitthing.unk00.x);
	if (hitthing.unk00.y);
	if (hitthing.unk00.z);

	return false;
}
#endif

#if VERSION == VERSION_JPN_FINAL
void func0f149260jf(void)
{
	// empty
}
#endif

void splatsTick(void)
{
	// empty
}

#if VERSION == VERSION_JPN_FINAL
void func0f149270jf(void)
{
	// empty
}
#endif

#if VERSION == VERSION_JPN_FINAL
void func0f149260jf(void);
#else
GLOBAL_ASM(
glabel func0f14986c
.late_rodata
glabel var7f1b6034
.word func0f14986c+0x11c # f149988
glabel var7f1b6038
.word func0f14986c+0x11c # f149988
glabel var7f1b603c
.word func0f14986c+0x11c # f149988
glabel var7f1b6040
.word func0f14986c+0x12c # f149998
glabel var7f1b6044
.word func0f14986c+0x12c # f149998
glabel var7f1b6048
.word func0f14986c+0x13c # f1499a8
.text
/*  f14986c:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f149870:	240e00c0 */ 	addiu	$t6,$zero,0xc0
/*  f149874:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f149878:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f14987c:	a3ae0092 */ 	sb	$t6,0x92($sp)
/*  f149880:	8c820048 */ 	lw	$v0,0x48($a0)
/*  f149884:	00808025 */ 	or	$s0,$a0,$zero
/*  f149888:	304f0001 */ 	andi	$t7,$v0,0x1
/*  f14988c:	afaf0088 */ 	sw	$t7,0x88($sp)
/*  f149890:	afaf0084 */ 	sw	$t7,0x84($sp)
/*  f149894:	8c98004c */ 	lw	$t8,0x4c($a0)
/*  f149898:	0c004b70 */ 	jal	random
/*  f14989c:	afb80080 */ 	sw	$t8,0x80($sp)
/*  f1498a0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1498a4:	0041001b */ 	divu	$zero,$v0,$at
/*  f1498a8:	0000c810 */ 	mfhi	$t9
/*  f1498ac:	27280009 */ 	addiu	$t0,$t9,0x9
/*  f1498b0:	afa8008c */ 	sw	$t0,0x8c($sp)
/*  f1498b4:	8e030034 */ 	lw	$v1,0x34($s0)
/*  f1498b8:	50600013 */ 	beqzl	$v1,.L0f149908
/*  f1498bc:	8e020030 */ 	lw	$v0,0x30($s0)
/*  f1498c0:	90690000 */ 	lbu	$t1,0x0($v1)
/*  f1498c4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1498c8:	5521000f */ 	bnel	$t1,$at,.L0f149908
/*  f1498cc:	8e020030 */ 	lw	$v0,0x30($s0)
/*  f1498d0:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f1498d4:	5040000c */ 	beqzl	$v0,.L0f149908
/*  f1498d8:	8e020030 */ 	lw	$v0,0x30($s0)
/*  f1498dc:	90430003 */ 	lbu	$v1,0x3($v0)
/*  f1498e0:	2401002a */ 	addiu	$at,$zero,0x2a
/*  f1498e4:	240a0040 */ 	addiu	$t2,$zero,0x40
/*  f1498e8:	10610004 */ 	beq	$v1,$at,.L0f1498fc
/*  f1498ec:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f1498f0:	2401002f */ 	addiu	$at,$zero,0x2f
/*  f1498f4:	54610004 */ 	bnel	$v1,$at,.L0f149908
/*  f1498f8:	8e020030 */ 	lw	$v0,0x30($s0)
.L0f1498fc:
/*  f1498fc:	a3aa0092 */ 	sb	$t2,0x92($sp)
/*  f149900:	afab0080 */ 	sw	$t3,0x80($sp)
/*  f149904:	8e020030 */ 	lw	$v0,0x30($s0)
.L0f149908:
/*  f149908:	24010001 */ 	addiu	$at,$zero,0x1
/*  f14990c:	10410005 */ 	beq	$v0,$at,.L0f149924
/*  f149910:	24010002 */ 	addiu	$at,$zero,0x2
/*  f149914:	1041000b */ 	beq	$v0,$at,.L0f149944
/*  f149918:	00000000 */ 	nop
/*  f14991c:	1000000d */ 	b	.L0f149954
/*  f149920:	00000000 */ 	nop
.L0f149924:
/*  f149924:	0c004b70 */ 	jal	random
/*  f149928:	00000000 */ 	nop
/*  f14992c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f149930:	0041001b */ 	divu	$zero,$v0,$at
/*  f149934:	00006010 */ 	mfhi	$t4
/*  f149938:	258d0009 */ 	addiu	$t5,$t4,0x9
/*  f14993c:	10000005 */ 	b	.L0f149954
/*  f149940:	afad008c */ 	sw	$t5,0x8c($sp)
.L0f149944:
/*  f149944:	0c004b70 */ 	jal	random
/*  f149948:	00000000 */ 	nop
/*  f14994c:	240e000c */ 	addiu	$t6,$zero,0xc
/*  f149950:	afae008c */ 	sw	$t6,0x8c($sp)
.L0f149954:
/*  f149954:	0c004b70 */ 	jal	random
/*  f149958:	00000000 */ 	nop
/*  f14995c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f149960:	0041001b */ 	divu	$zero,$v0,$at
/*  f149964:	00007810 */ 	mfhi	$t7
/*  f149968:	2de10006 */ 	sltiu	$at,$t7,0x6
/*  f14996c:	10200012 */ 	beqz	$at,.L0f1499b8
/*  f149970:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f149974:	3c017f1b */ 	lui	$at,%hi(var7f1b6034)
/*  f149978:	002f0821 */ 	addu	$at,$at,$t7
/*  f14997c:	8c2f6034 */ 	lw	$t7,%lo(var7f1b6034)($at)
/*  f149980:	01e00008 */ 	jr	$t7
/*  f149984:	00000000 */ 	nop
/*  f149988:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f14998c:	44812000 */ 	mtc1	$at,$f4
/*  f149990:	10000009 */ 	b	.L0f1499b8
/*  f149994:	e7a4009c */ 	swc1	$f4,0x9c($sp)
/*  f149998:	3c0140a0 */ 	lui	$at,0x40a0
/*  f14999c:	44813000 */ 	mtc1	$at,$f6
/*  f1499a0:	10000005 */ 	b	.L0f1499b8
/*  f1499a4:	e7a6009c */ 	swc1	$f6,0x9c($sp)
/*  f1499a8:	3c014040 */ 	lui	$at,0x4040
/*  f1499ac:	44814000 */ 	mtc1	$at,$f8
/*  f1499b0:	00000000 */ 	nop
/*  f1499b4:	e7a8009c */ 	swc1	$f8,0x9c($sp)
.L0f1499b8:
/*  f1499b8:	2605000c */ 	addiu	$a1,$s0,0xc
/*  f1499bc:	afa5006c */ 	sw	$a1,0x6c($sp)
/*  f1499c0:	0fc5dd18 */ 	jal	coordsGetDistance
/*  f1499c4:	26040024 */ 	addiu	$a0,$s0,0x24
/*  f1499c8:	3c018008 */ 	lui	$at,%hi(var8007f8a0)
/*  f1499cc:	c42af8a0 */ 	lwc1	$f10,%lo(var8007f8a0)($at)
/*  f1499d0:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
/*  f1499d4:	3c018008 */ 	lui	$at,%hi(var8007f8b8)
/*  f1499d8:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f1499dc:	c422f8b8 */ 	lwc1	$f2,%lo(var8007f8b8)($at)
/*  f1499e0:	3c018008 */ 	lui	$at,%hi(var8007f8b4)
/*  f1499e4:	46062302 */ 	mul.s	$f12,$f4,$f6
/*  f1499e8:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1499ec:	00000000 */ 	nop
/*  f1499f0:	45000002 */ 	bc1f	.L0f1499fc
/*  f1499f4:	00000000 */ 	nop
/*  f1499f8:	46001306 */ 	mov.s	$f12,$f2
.L0f1499fc:
/*  f1499fc:	c420f8b4 */ 	lwc1	$f0,%lo(var8007f8b4)($at)
/*  f149a00:	3c013f80 */ 	lui	$at,0x3f80
/*  f149a04:	44811000 */ 	mtc1	$at,$f2
/*  f149a08:	4600603c */ 	c.lt.s	$f12,$f0
/*  f149a0c:	3c013f00 */ 	lui	$at,0x3f00
/*  f149a10:	44814000 */ 	mtc1	$at,$f8
/*  f149a14:	45000002 */ 	bc1f	.L0f149a20
/*  f149a18:	00000000 */ 	nop
/*  f149a1c:	46000306 */ 	mov.s	$f12,$f0
.L0f149a20:
/*  f149a20:	460c4002 */ 	mul.s	$f0,$f8,$f12
/*  f149a24:	4602003c */ 	c.lt.s	$f0,$f2
/*  f149a28:	46000406 */ 	mov.s	$f16,$f0
/*  f149a2c:	46000486 */ 	mov.s	$f18,$f0
/*  f149a30:	45020003 */ 	bc1fl	.L0f149a40
/*  f149a34:	4602003c */ 	c.lt.s	$f0,$f2
/*  f149a38:	46001406 */ 	mov.s	$f16,$f2
/*  f149a3c:	4602003c */ 	c.lt.s	$f0,$f2
.L0f149a40:
/*  f149a40:	00000000 */ 	nop
/*  f149a44:	45020003 */ 	bc1fl	.L0f149a54
/*  f149a48:	e7ac00a0 */ 	swc1	$f12,0xa0($sp)
/*  f149a4c:	46001486 */ 	mov.s	$f18,$f2
/*  f149a50:	e7ac00a0 */ 	swc1	$f12,0xa0($sp)
.L0f149a54:
/*  f149a54:	e7b000ac */ 	swc1	$f16,0xac($sp)
/*  f149a58:	0c004b70 */ 	jal	random
/*  f149a5c:	e7b200a8 */ 	swc1	$f18,0xa8($sp)
/*  f149a60:	44825000 */ 	mtc1	$v0,$f10
/*  f149a64:	c7ac00a0 */ 	lwc1	$f12,0xa0($sp)
/*  f149a68:	c7b000ac */ 	lwc1	$f16,0xac($sp)
/*  f149a6c:	04410005 */ 	bgez	$v0,.L0f149a84
/*  f149a70:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f149a74:	3c014f80 */ 	lui	$at,0x4f80
/*  f149a78:	44813000 */ 	mtc1	$at,$f6
/*  f149a7c:	00000000 */ 	nop
/*  f149a80:	46062100 */ 	add.s	$f4,$f4,$f6
.L0f149a84:
/*  f149a84:	3c012f80 */ 	lui	$at,0x2f80
/*  f149a88:	44814000 */ 	mtc1	$at,$f8
/*  f149a8c:	00000000 */ 	nop
/*  f149a90:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f149a94:	00000000 */ 	nop
/*  f149a98:	46105002 */ 	mul.s	$f0,$f10,$f16
/*  f149a9c:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f149aa0:	46103101 */ 	sub.s	$f4,$f6,$f16
/*  f149aa4:	460c2380 */ 	add.s	$f14,$f4,$f12
/*  f149aa8:	0c004b70 */ 	jal	random
/*  f149aac:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f149ab0:	44824000 */ 	mtc1	$v0,$f8
/*  f149ab4:	c7ac00a0 */ 	lwc1	$f12,0xa0($sp)
/*  f149ab8:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f149abc:	c7b200a8 */ 	lwc1	$f18,0xa8($sp)
/*  f149ac0:	04410005 */ 	bgez	$v0,.L0f149ad8
/*  f149ac4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f149ac8:	3c014f80 */ 	lui	$at,0x4f80
/*  f149acc:	44813000 */ 	mtc1	$at,$f6
/*  f149ad0:	00000000 */ 	nop
/*  f149ad4:	46065280 */ 	add.s	$f10,$f10,$f6
.L0f149ad8:
/*  f149ad8:	3c012f80 */ 	lui	$at,0x2f80
/*  f149adc:	44812000 */ 	mtc1	$at,$f4
/*  f149ae0:	3c018008 */ 	lui	$at,%hi(var8007f8b8)
/*  f149ae4:	c422f8b8 */ 	lwc1	$f2,%lo(var8007f8b8)($at)
/*  f149ae8:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f149aec:	460e103c */ 	c.lt.s	$f2,$f14
/*  f149af0:	46124002 */ 	mul.s	$f0,$f8,$f18
/*  f149af4:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f149af8:	46123281 */ 	sub.s	$f10,$f6,$f18
/*  f149afc:	460c5400 */ 	add.s	$f16,$f10,$f12
/*  f149b00:	45000002 */ 	bc1f	.L0f149b0c
/*  f149b04:	e7b00098 */ 	swc1	$f16,0x98($sp)
/*  f149b08:	46001386 */ 	mov.s	$f14,$f2
.L0f149b0c:
/*  f149b0c:	4610103c */ 	c.lt.s	$f2,$f16
/*  f149b10:	00000000 */ 	nop
/*  f149b14:	45020003 */ 	bc1fl	.L0f149b24
/*  f149b18:	c6000050 */ 	lwc1	$f0,0x50($s0)
/*  f149b1c:	e7a20098 */ 	swc1	$f2,0x98($sp)
/*  f149b20:	c6000050 */ 	lwc1	$f0,0x50($s0)
.L0f149b24:
/*  f149b24:	c7a40098 */ 	lwc1	$f4,0x98($sp)
/*  f149b28:	46007382 */ 	mul.s	$f14,$f14,$f0
/*  f149b2c:	00000000 */ 	nop
/*  f149b30:	46002202 */ 	mul.s	$f8,$f4,$f0
/*  f149b34:	e7a80098 */ 	swc1	$f8,0x98($sp)
/*  f149b38:	8e040038 */ 	lw	$a0,0x38($s0)
/*  f149b3c:	0fc4f972 */ 	jal	wallhitChooseBloodColour
/*  f149b40:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f149b44:	8e02003c */ 	lw	$v0,0x3c($s0)
/*  f149b48:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f149b4c:	00003025 */ 	or	$a2,$zero,$zero
/*  f149b50:	10400004 */ 	beqz	$v0,.L0f149b64
/*  f149b54:	00000000 */ 	nop
/*  f149b58:	8c46001c */ 	lw	$a2,0x1c($v0)
/*  f149b5c:	10000001 */ 	b	.L0f149b64
/*  f149b60:	24c60008 */ 	addiu	$a2,$a2,0x8
.L0f149b64:
/*  f149b64:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f149b68:	0c004b70 */ 	jal	random
/*  f149b6c:	e7ae0094 */ 	swc1	$f14,0x94($sp)
/*  f149b70:	24010168 */ 	addiu	$at,$zero,0x168
/*  f149b74:	0041001b */ 	divu	$zero,$v0,$at
/*  f149b78:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f149b7c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f149b80:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f149b84:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f149b88:	8e190044 */ 	lw	$t9,0x44($s0)
/*  f149b8c:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f149b90:	93ac0092 */ 	lbu	$t4,0x92($sp)
/*  f149b94:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f149b98:	8e080034 */ 	lw	$t0,0x34($s0)
/*  f149b9c:	00007010 */ 	mfhi	$t6
/*  f149ba0:	240d00ff */ 	addiu	$t5,$zero,0xff
/*  f149ba4:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f149ba8:	8e090038 */ 	lw	$t1,0x38($s0)
/*  f149bac:	8fb90080 */ 	lw	$t9,0x80($sp)
/*  f149bb0:	8fa60070 */ 	lw	$a2,0x70($sp)
/*  f149bb4:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f149bb8:	8e0a0040 */ 	lw	$t2,0x40($s0)
/*  f149bbc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f149bc0:	02002025 */ 	or	$a0,$s0,$zero
/*  f149bc4:	afaa0024 */ 	sw	$t2,0x24($sp)
/*  f149bc8:	8e0b003c */ 	lw	$t3,0x3c($s0)
/*  f149bcc:	afae0040 */ 	sw	$t6,0x40($sp)
/*  f149bd0:	afad003c */ 	sw	$t5,0x3c($sp)
/*  f149bd4:	e7ae0030 */ 	swc1	$f14,0x30($sp)
/*  f149bd8:	e7a60034 */ 	swc1	$f6,0x34($sp)
/*  f149bdc:	afac0038 */ 	sw	$t4,0x38($sp)
/*  f149be0:	afab002c */ 	sw	$t3,0x2c($sp)
/*  f149be4:	960f0056 */ 	lhu	$t7,0x56($s0)
/*  f149be8:	26050018 */ 	addiu	$a1,$s0,0x18
/*  f149bec:	00003825 */ 	or	$a3,$zero,$zero
/*  f149bf0:	afaf0044 */ 	sw	$t7,0x44($sp)
/*  f149bf4:	8e180058 */ 	lw	$t8,0x58($s0)
/*  f149bf8:	afb9004c */ 	sw	$t9,0x4c($sp)
/*  f149bfc:	0fc4fd41 */ 	jal	wallhitCreateWith20Args
/*  f149c00:	afb80048 */ 	sw	$t8,0x48($sp)
/*  f149c04:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f149c08:	8fa80084 */ 	lw	$t0,0x84($sp)
/*  f149c0c:	240affff */ 	addiu	$t2,$zero,-1
/*  f149c10:	14400003 */ 	bnez	$v0,.L0f149c20
/*  f149c14:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f149c18:	5100000e */ 	beqzl	$t0,.L0f149c54
/*  f149c1c:	8fbf005c */ 	lw	$ra,0x5c($sp)
.L0f149c20:
/*  f149c20:	8e090044 */ 	lw	$t1,0x44($s0)
/*  f149c24:	a7aa007a */ 	sh	$t2,0x7a($sp)
/*  f149c28:	10400003 */ 	beqz	$v0,.L0f149c38
/*  f149c2c:	a7a90078 */ 	sh	$t1,0x78($sp)
/*  f149c30:	10000002 */ 	b	.L0f149c3c
/*  f149c34:	2402000d */ 	addiu	$v0,$zero,0xd
.L0f149c38:
/*  f149c38:	2402000e */ 	addiu	$v0,$zero,0xe
.L0f149c3c:
/*  f149c3c:	00023400 */ 	sll	$a2,$v0,0x10
/*  f149c40:	00065c03 */ 	sra	$t3,$a2,0x10
/*  f149c44:	01603025 */ 	or	$a2,$t3,$zero
/*  f149c48:	0fc4ba08 */ 	jal	smokeCreateSimple
/*  f149c4c:	8fa4006c */ 	lw	$a0,0x6c($sp)
/*  f149c50:	8fbf005c */ 	lw	$ra,0x5c($sp)
.L0f149c54:
/*  f149c54:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f149c58:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
/*  f149c5c:	03e00008 */ 	jr	$ra
/*  f149c60:	00000000 */ 	nop
);
#endif

void splatResetChr(struct chrdata *chr)
{
	osSyncPrintf("Splat_ResetChr : Reset One Char : chrdata = %x\n", (u32)chr);

	chr->bulletstaken = 0;
	chr->tickssincesplat = 0;
	chr->stdsplatsadded = 0;
	chr->woundedsplatsadded = 0;
	chr->deaddropsplatsadded = 0;
	chr->splatsdroppedhere = 0;
	chr->lastdroppos.x = 0;
	chr->lastdroppos.y = 0;
	chr->lastdroppos.z = 0;
}
