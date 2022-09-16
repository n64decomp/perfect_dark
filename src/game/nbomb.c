#include <ultra64.h>
#include "constants.h"
#include "game/chraction.h"
#include "game/dlights.h"
#include "game/game_006900.h"
#include "game/nbomb.h"
#include "game/chr.h"
#include "game/chraction.h"
#include "game/prop.h"
#include "game/objectives.h"
#include "game/atan2f.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/savebuffer.h"
#include "game/bg.h"
#include "game/file.h"
#include "game/gfxmemory.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/snd.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

s16 var8009cb00;
s32 var8009cb04;
struct nbomb g_Nbombs[6];
u32 var8009cbf8;

bool g_NbombsActive = false;
f32 var80061644 = 100;
u32 var80061648 = 0;

#define MAKEVERTEX(i, src) \
	vertices[i].x = src.x * var80061644; \
	vertices[i].y = src.y * var80061644; \
	vertices[i].z = src.z * var80061644; \
	vertices[i].s = src.y * 256.0f * 32.0f; \
	vertices[i].t = atan2f(src.x, src.z) / M_TAU * 256.0f * 32.0f; \
	vertices[i].colour = var80061648 * 0; \
\
	var80061648 = 1 - var80061648; \
\
	if (var8009cb04 && vertices[i].t == 0) { \
		vertices[i].t = 256 * 32; \
	} \
\
	vertices[i].t += var8009cb00;

Gfx *func0f006c80(Gfx *gdl, struct coord *arg1, struct coord *arg2, struct coord *arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, s8 depth)
{
	struct coord sp7c;
	struct coord sp70;
	struct coord sp64;
	f32 dist;
	struct gfxvtx *vertices;

	sp7c.x = arg2->x + arg1->x;
	sp7c.y = arg2->y + arg1->y;
	sp7c.z = arg2->z + arg1->z;

	dist = sqrtf(sp7c.f[0] * sp7c.f[0] + sp7c.f[1] * sp7c.f[1] + sp7c.f[2] * sp7c.f[2]);

	sp7c.x /= dist;
	sp7c.y /= dist;
	sp7c.z /= dist;

	sp70.x = arg3->x + arg2->x;
	sp70.y = arg3->y + arg2->y;
	sp70.z = arg3->z + arg2->z;

	dist = sqrtf(sp70.f[0] * sp70.f[0] + sp70.f[1] * sp70.f[1] + sp70.f[2] * sp70.f[2]);

	sp70.x /= dist;
	sp70.y /= dist;
	sp70.z /= dist;

	sp64.x = arg1->x + arg3->x;
	sp64.y = arg1->y + arg3->y;
	sp64.z = arg1->z + arg3->z;

	dist = sqrtf(sp64.f[0] * sp64.f[0] + sp64.f[1] * sp64.f[1] + sp64.f[2] * sp64.f[2]);

	sp64.x /= dist;
	sp64.y /= dist;
	sp64.z /= dist;

	vertices = gfxAllocateVertices(3);

	MAKEVERTEX(0, sp7c);
	MAKEVERTEX(1, sp70);
	MAKEVERTEX(2, sp64);

	gDPSetVerticeArrayRaw(gdl++, osVirtualToPhysical(vertices), arg7 | 0x20, 3 * sizeof(struct gfxvtx));

	if (depth == 0) {
		gDPTri4(gdl++,
				arg4, arg7, arg7 + 2,
				arg5, arg7 + 1, arg7,
				arg6, arg7 + 2, arg7 + 1,
				arg7, arg7 + 1, arg7 + 2);
	} else {
		gdl = func0f006c80(gdl, arg1, &sp7c, &sp64, arg4, arg7, arg7 + 2, arg7 + 3, depth - 1);
		gdl = func0f006c80(gdl, arg2, &sp70, &sp7c, arg5, arg7 + 1, arg7, arg7 + 3, depth - 1);
		gdl = func0f006c80(gdl, arg3, &sp64, &sp70, arg6, arg7 + 2, arg7 + 1, arg7 + 3, depth - 1);
		gdl = func0f006c80(gdl, &sp7c, &sp70, &sp64, arg7, arg7 + 1, arg7 + 2, arg7 + 3, depth - 1);
	}

	return gdl;
}

Gfx *func0f0073ac(Gfx *gdl, struct coord *pos, f32 arg2)
{
	Mtxf *modelmtx = gfxAllocateMatrix();
	struct gfxvtx *vertices;
	u32 *colours;
	Mtxf sp104;
	struct coord spf8[1];
	struct coord spb0[] = {
		{ 0,  0,  1  },
		{ 1,  0,  0  },
		{ 0,  0,  -1 },
		{ -1, 0,  0  },
		{ 0,  1,  0  },
		{ 0,  -1, 0  },
	};

	var80061644 = arg2;

	spf8[0].x = 0.0f;
	spf8[0].y = 0.0f;
	spf8[0].z = -100.0f;

	mtx4LoadIdentity(&sp104);
	mtx4LoadTranslation(pos, &sp104);
	mtx00015be0(camGetWorldToScreenMtxf(), &sp104);
	mtx00016054(&sp104, modelmtx);

	gSPMatrix(gdl++, osVirtualToPhysical(modelmtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	texSelect(&gdl, &g_TexGeneralConfigs[10], 2, 1, 2, true, NULL);

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetCombineMode(gdl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);
	gDPSetRenderMode(gdl++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
	gDPSetTexturePersp(gdl++, G_TP_PERSP);

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetCombineMode(gdl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);
	gDPSetRenderMode(gdl++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
	gDPSetTexturePersp(gdl++, G_TP_PERSP);

	texSelect(&gdl, NULL, 2, 1, 2, true, NULL);

	gDPSetRenderMode(gdl++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);

	var8009cb00 = 2048.0f * g_20SecIntervalFrac;
	var8009cb04 = 0;

	vertices = gfxAllocateVertices(6);

	MAKEVERTEX(0, spb0[0]);
	MAKEVERTEX(1, spb0[1]);
	MAKEVERTEX(2, spb0[2]);
	MAKEVERTEX(3, spb0[3]);
	MAKEVERTEX(4, spb0[4]);
	MAKEVERTEX(5, spb0[5]);

	colours = gfxAllocateColours(1);

	colours[0] = 0xff00007f;

	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 1);
	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 6);

	gdl = func0f006c80(gdl, &spb0[0], &spb0[4], &spb0[1], 0, 4, 1, 6, 2);
	gdl = func0f006c80(gdl, &spb0[1], &spb0[4], &spb0[2], 1, 4, 2, 6, 2);
	gdl = func0f006c80(gdl, &spb0[1], &spb0[5], &spb0[0], 1, 5, 0, 6, 2);
	gdl = func0f006c80(gdl, &spb0[2], &spb0[5], &spb0[1], 2, 5, 1, 6, 2);

	var8009cb04 = 1;

	vertices = gfxAllocateVertices(6);

	MAKEVERTEX(0, spb0[0]);
	MAKEVERTEX(1, spb0[1]);
	MAKEVERTEX(2, spb0[2]);
	MAKEVERTEX(3, spb0[3]);
	MAKEVERTEX(4, spb0[4]);
	MAKEVERTEX(5, spb0[5]);

	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 6);

	gdl = func0f006c80(gdl, &spb0[2], &spb0[4], &spb0[3], 2, 4, 3, 6, 2);
	gdl = func0f006c80(gdl, &spb0[3], &spb0[4], &spb0[0], 3, 4, 0, 6, 2);
	gdl = func0f006c80(gdl, &spb0[3], &spb0[5], &spb0[2], 3, 5, 2, 6, 2);
	gdl = func0f006c80(gdl, &spb0[0], &spb0[5], &spb0[3], 0, 5, 3, 6, 2);

	return gdl;
}

Gfx *func0f008558(Gfx *gdl, s32 depth)
{
	struct gfxvtx *vertices;
	struct coord sp5c[] = {
		{ 0,  0,  1  },
		{ 1,  0,  0  },
		{ 0,  0,  -1 },
		{ -1, 0,  0  },
		{ 0,  1,  0  },
		{ 0,  -1, 0  },
	};

	var80061648 = 0;

	var8009cb04 = 0;

	vertices = gfxAllocateVertices(6);

	MAKEVERTEX(0, sp5c[0]);
	MAKEVERTEX(1, sp5c[1]);
	MAKEVERTEX(2, sp5c[2]);
	MAKEVERTEX(3, sp5c[3]);
	MAKEVERTEX(4, sp5c[4]);
	MAKEVERTEX(5, sp5c[5]);

	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 6);

	gdl = func0f006c80(gdl, &sp5c[0], &sp5c[4], &sp5c[1], 0, 4, 1, 6, depth);
	gdl = func0f006c80(gdl, &sp5c[1], &sp5c[4], &sp5c[2], 1, 4, 2, 6, depth);
	gdl = func0f006c80(gdl, &sp5c[1], &sp5c[5], &sp5c[0], 1, 5, 0, 6, depth);
	gdl = func0f006c80(gdl, &sp5c[2], &sp5c[5], &sp5c[1], 2, 5, 1, 6, depth);

	var8009cb04 = 1;

	vertices = gfxAllocateVertices(6);

	MAKEVERTEX(0, sp5c[0]);
	MAKEVERTEX(1, sp5c[1]);
	MAKEVERTEX(2, sp5c[2]);
	MAKEVERTEX(3, sp5c[3]);
	MAKEVERTEX(4, sp5c[4]);
	MAKEVERTEX(5, sp5c[5]);

	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 6);

	gdl = func0f006c80(gdl, &sp5c[2], &sp5c[4], &sp5c[3], 2, 4, 3, 6, depth);
	gdl = func0f006c80(gdl, &sp5c[3], &sp5c[4], &sp5c[0], 3, 4, 0, 6, depth);
	gdl = func0f006c80(gdl, &sp5c[3], &sp5c[5], &sp5c[2], 3, 5, 2, 6, depth);
	gdl = func0f006c80(gdl, &sp5c[0], &sp5c[5], &sp5c[3], 0, 5, 3, 6, depth);

	return gdl;
}

void nbomb0f0093c4(f32 *arg0)
{
	arg0[0] = 0.0f;
	arg0[1] = RANDOMFRAC() - 0.5f;
	arg0[2] = RANDOMFRAC() - 0.5f;
	arg0[3] = RANDOMFRAC() - 0.5f;

	guNormalize(&arg0[1], &arg0[2], &arg0[3]);
}

void nbombReset(struct nbomb *nbomb)
{
	nbomb->age240 = 0;
#if VERSION >= VERSION_PAL_BETA
	nbomb->radius = 0;
#endif
}

/**
 * If nbomb->age240 is 0 to 310, return 127
 * If nbomb->age240 is 311 to 349, return a scaled number between 127 and 0
 * If nbomb->age240 is 350+, return 0
 */
s32 nbombCalculateAlpha(struct nbomb *nbomb)
{
	s32 alpha = 127;

	if (nbomb->age240 > TICKS(310)) {
		if (nbomb->age240 < TICKS(350)) {
			alpha = (TICKS(350) * 127 - nbomb->age240 * 127) / TICKS(40);
		} else {
			alpha = 0;
		}
	}

	return alpha;
}

/**
 * Allocate and populate a graphics display list for an nbomb dome.
 *
 * The gdl sets up a single vertex but has no colour or triangles.
 */
Gfx *nbombCreateGdl(void)
{
	struct gfxvtx *vertices;
	u32 gdlsizes[] = { 0x0a30, 0x0330 }; // 1 player, 2+ players
	Gfx *gdlstart;
	Gfx *gdl;
	s32 index = 0;

	if (PLAYERCOUNT() >= 2) {
		index = 1;
	}

	var8009cb00 = (s32)(g_20SecIntervalFrac * 64.0f * 32.0f * 16.0f) % 0x800;

	gdl = gdlstart = gfxAllocate(gdlsizes[index]);

	texSelect(&gdl, &g_TexGeneralConfigs[0x0a], 2, 1, 2, 1, NULL);

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetCombineMode(gdl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);
	gDPSetRenderMode(gdl++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
	gDPSetTexturePersp(gdl++, G_TP_PERSP);

	vertices = gfxAllocateVertices(1);

	vertices[0].z = 0;
	vertices[0].t = 0;
	vertices[0].colour = 0;
	vertices[0].y = vertices[0].z;
	vertices[0].x = vertices[0].z;
	vertices[0].s = vertices[0].t;

	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 1);

	if (index != 0) {
		u32 stack;
		gdl = func0f008558(gdl, 1);
	} else {
		gdl = func0f008558(gdl, 2);
	}

	gSPEndDisplayList(gdl++);

	return gdlstart;
}

struct sndstate *g_NbombAudioHandle = NULL;

Gfx *nbombRender(Gfx *gdl, struct nbomb *nbomb, Gfx *subgdl)
{
	f32 divider = 2048;
	Mtxf *mtx;
	Mtxf spc8;
	Mtxf sp88;
	Mtxf sp48;
	struct coord sp3c;
	u32 colour;
	u32 *colours;

	mtx = gfxAllocateMatrix();
	var80061644 = 2000.0f;
	colour = nbombCalculateAlpha(nbomb);

	colours = gfxAllocateColours(2);
	colours[0] = colour;
	colours[1] = 0xffffff00;

	gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 2);

	sp3c.x = 0;
	sp3c.y = 0;
	sp3c.z = -100;

	mtx4LoadIdentity(&sp48);
	mtx4LoadTranslation(&nbomb->pos, &sp48);

	sp3c.x = 0;
	sp3c.y = nbomb->unk14 / divider * M_TAU;
	sp3c.z = 0;

	mtx4LoadRotation(&sp3c, &sp88);
	mtx00015f04(nbomb->radius / 2000.0f, &sp88);
	mtx4MultMtx4(&sp48, &sp88, &spc8);

	mtx00015be0(camGetWorldToScreenMtxf(), &spc8);
	mtx00016054(&spc8, mtx);

	gSPMatrix(gdl++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	gSPDisplayList(gdl++, subgdl);

	return gdl;
}

void func0f0099a4(void)
{
	s32 i;

	g_NbombsActive = false;
	g_NbombAudioHandle = NULL;

	for (i = 0; i < ARRAYCOUNT(g_Nbombs); i++) {
		g_Nbombs[i].age240 = -1;

#if VERSION >= VERSION_NTSC_1_0
		g_Nbombs[i].audiohandle20 = NULL;
		g_Nbombs[i].audiohandle24 = NULL;
#endif
	}
}

#if MATCHING
#if PAL
GLOBAL_ASM(
glabel nbombInflictDamage
.late_rodata
glabel var7f1a7f20
.word 0x3c23d70a
.text
/*  f0099e4:	27bdfcf8 */ 	addiu	$sp,$sp,-776
/*  f0099e8:	afb50030 */ 	sw	$s5,0x30($sp)
/*  f0099ec:	3c15800a */ 	lui	$s5,%hi(g_Vars)
/*  f0099f0:	26b59fc0 */ 	addiu	$s5,$s5,%lo(g_Vars)
/*  f0099f4:	8eaf0034 */ 	lw	$t7,0x34($s5)
/*  f0099f8:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f0099fc:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f009a00:	240e001f */ 	addiu	$t6,$zero,0x1f
/*  f009a04:	00809025 */ 	or	$s2,$a0,$zero
/*  f009a08:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f009a0c:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f009a10:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f009a14:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f009a18:	00008825 */ 	or	$s1,$zero,$zero
/*  f009a1c:	a3ae0070 */ 	sb	$t6,0x70($sp)
/*  f009a20:	19e000b2 */ 	blez	$t7,.L0f009cec
/*  f009a24:	a3a00073 */ 	sb	$zero,0x73($sp)
/*  f009a28:	8c98000c */ 	lw	$t8,0xc($a0)
/*  f009a2c:	2b01015f */ 	slti	$at,$t8,0x124
/*  f009a30:	502000af */ 	beqzl	$at,.L0f009cf0
/*  f009a34:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f009a38:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f009a3c:	c4860010 */ 	lwc1	$f6,0x10($a0)
/*  f009a40:	3c13800a */ 	lui	$s3,%hi(g_Rooms)
/*  f009a44:	26734928 */ 	addiu	$s3,$s3,%lo(g_Rooms)
/*  f009a48:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f009a4c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f009a50:	2403008c */ 	addiu	$v1,$zero,0x8c
/*  f009a54:	27b4007c */ 	addiu	$s4,$sp,0x7c
/*  f009a58:	e7a800f4 */ 	swc1	$f8,0xf4($sp)
/*  f009a5c:	c4900010 */ 	lwc1	$f16,0x10($a0)
/*  f009a60:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f009a64:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f009a68:	e7b200f8 */ 	swc1	$f18,0xf8($sp)
/*  f009a6c:	c4860010 */ 	lwc1	$f6,0x10($a0)
/*  f009a70:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f009a74:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f009a78:	e7a800fc */ 	swc1	$f8,0xfc($sp)
/*  f009a7c:	c4900010 */ 	lwc1	$f16,0x10($a0)
/*  f009a80:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f009a84:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f009a88:	e7b200e8 */ 	swc1	$f18,0xe8($sp)
/*  f009a8c:	c4860010 */ 	lwc1	$f6,0x10($a0)
/*  f009a90:	c4840004 */ 	lwc1	$f4,0x4($a0)
/*  f009a94:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f009a98:	e7a800ec */ 	swc1	$f8,0xec($sp)
/*  f009a9c:	c4900010 */ 	lwc1	$f16,0x10($a0)
/*  f009aa0:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f009aa4:	8ea402bc */ 	lw	$a0,0x2bc($s5)
/*  f009aa8:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f009aac:	28810002 */ 	slti	$at,$a0,0x2
/*  f009ab0:	14200038 */ 	bnez	$at,.L0f009b94
/*  f009ab4:	e7b200f0 */ 	swc1	$f18,0xf0($sp)
.L0f009ab8:
/*  f009ab8:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f009abc:	c7a400e8 */ 	lwc1	$f4,0xe8($sp)
/*  f009ac0:	c7aa00f4 */ 	lwc1	$f10,0xf4($sp)
/*  f009ac4:	03231021 */ 	addu	$v0,$t9,$v1
/*  f009ac8:	c4460018 */ 	lwc1	$f6,0x18($v0)
/*  f009acc:	4606203c */ 	c.lt.s	$f4,$f6
/*  f009ad0:	00000000 */ 	nop
/*  f009ad4:	4503002c */ 	bc1tl	.L0f009b88
/*  f009ad8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f009adc:	c4480024 */ 	lwc1	$f8,0x24($v0)
/*  f009ae0:	c7b000ec */ 	lwc1	$f16,0xec($sp)
/*  f009ae4:	460a403c */ 	c.lt.s	$f8,$f10
/*  f009ae8:	00000000 */ 	nop
/*  f009aec:	45030026 */ 	bc1tl	.L0f009b88
/*  f009af0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f009af4:	c452001c */ 	lwc1	$f18,0x1c($v0)
/*  f009af8:	c7a600f8 */ 	lwc1	$f6,0xf8($sp)
/*  f009afc:	4612803c */ 	c.lt.s	$f16,$f18
/*  f009b00:	00000000 */ 	nop
/*  f009b04:	45030020 */ 	bc1tl	.L0f009b88
/*  f009b08:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f009b0c:	c4440028 */ 	lwc1	$f4,0x28($v0)
/*  f009b10:	c7a800f0 */ 	lwc1	$f8,0xf0($sp)
/*  f009b14:	4606203c */ 	c.lt.s	$f4,$f6
/*  f009b18:	00000000 */ 	nop
/*  f009b1c:	4503001a */ 	bc1tl	.L0f009b88
/*  f009b20:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f009b24:	c44a0020 */ 	lwc1	$f10,0x20($v0)
/*  f009b28:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
/*  f009b2c:	460a403c */ 	c.lt.s	$f8,$f10
/*  f009b30:	00000000 */ 	nop
/*  f009b34:	45030014 */ 	bc1tl	.L0f009b88
/*  f009b38:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f009b3c:	c450002c */ 	lwc1	$f16,0x2c($v0)
/*  f009b40:	2a210034 */ 	slti	$at,$s1,0x34
/*  f009b44:	4612803c */ 	c.lt.s	$f16,$f18
/*  f009b48:	00000000 */ 	nop
/*  f009b4c:	4503000e */ 	bc1tl	.L0f009b88
/*  f009b50:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f009b54:	1020000b */ 	beqz	$at,.L0f009b84
/*  f009b58:	00114040 */ 	sll	$t0,$s1,0x1
/*  f009b5c:	02884821 */ 	addu	$t1,$s4,$t0
/*  f009b60:	a5300000 */ 	sh	$s0,0x0($t1)
/*  f009b64:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f009b68:	afa30040 */ 	sw	$v1,0x40($sp)
/*  f009b6c:	02002025 */ 	or	$a0,$s0,$zero
/*  f009b70:	2405ffda */ 	addiu	$a1,$zero,-38
/*  f009b74:	0fc010e3 */ 	jal	roomAdjustLighting
/*  f009b78:	2406ff4c */ 	addiu	$a2,$zero,-180
/*  f009b7c:	8fa30040 */ 	lw	$v1,0x40($sp)
/*  f009b80:	8ea402bc */ 	lw	$a0,0x2bc($s5)
.L0f009b84:
/*  f009b84:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f009b88:
/*  f009b88:	0204082a */ 	slt	$at,$s0,$a0
/*  f009b8c:	1420ffca */ 	bnez	$at,.L0f009ab8
/*  f009b90:	2463008c */ 	addiu	$v1,$v1,0x8c
.L0f009b94:
/*  f009b94:	27a4007c */ 	addiu	$a0,$sp,0x7c
/*  f009b98:	00115840 */ 	sll	$t3,$s1,0x1
/*  f009b9c:	008b6021 */ 	addu	$t4,$a0,$t3
/*  f009ba0:	240affff */ 	addiu	$t2,$zero,-1
/*  f009ba4:	27b00100 */ 	addiu	$s0,$sp,0x100
/*  f009ba8:	a58a0000 */ 	sh	$t2,0x0($t4)
/*  f009bac:	02002825 */ 	or	$a1,$s0,$zero
/*  f009bb0:	0fc197e0 */ 	jal	roomGetProps
/*  f009bb4:	24060100 */ 	addiu	$a2,$zero,0x100
/*  f009bb8:	87ad0100 */ 	lh	$t5,0x100($sp)
/*  f009bbc:	02009825 */ 	or	$s3,$s0,$zero
/*  f009bc0:	27ae0100 */ 	addiu	$t6,$sp,0x100
/*  f009bc4:	05a00049 */ 	bltz	$t5,.L0f009cec
/*  f009bc8:	27b4004c */ 	addiu	$s4,$sp,0x4c
/*  f009bcc:	85c20000 */ 	lh	$v0,0x0($t6)
/*  f009bd0:	8eb80338 */ 	lw	$t8,0x338($s5)
.L0f009bd4:
/*  f009bd4:	000278c0 */ 	sll	$t7,$v0,0x3
/*  f009bd8:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f009bdc:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f009be0:	01f88821 */ 	addu	$s1,$t7,$t8
/*  f009be4:	86390002 */ 	lh	$t9,0x2($s1)
/*  f009be8:	5720003d */ 	bnezl	$t9,.L0f009ce0
/*  f009bec:	86620002 */ 	lh	$v0,0x2($s3)
/*  f009bf0:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f009bf4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f009bf8:	10410003 */ 	beq	$v0,$at,.L0f009c08
/*  f009bfc:	24010006 */ 	addiu	$at,$zero,0x6
/*  f009c00:	54410037 */ 	bnel	$v0,$at,.L0f009ce0
/*  f009c04:	86620002 */ 	lh	$v0,0x2($s3)
.L0f009c08:
/*  f009c08:	c6240008 */ 	lwc1	$f4,0x8($s1)
/*  f009c0c:	c6460000 */ 	lwc1	$f6,0x0($s2)
/*  f009c10:	c628000c */ 	lwc1	$f8,0xc($s1)
/*  f009c14:	c64a0004 */ 	lwc1	$f10,0x4($s2)
/*  f009c18:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f009c1c:	c6300010 */ 	lwc1	$f16,0x10($s1)
/*  f009c20:	c6520008 */ 	lwc1	$f18,0x8($s2)
/*  f009c24:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f009c28:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f009c2c:	46128381 */ 	sub.s	$f14,$f16,$f18
/*  f009c30:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f009c34:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f009c38:	460e7282 */ 	mul.s	$f10,$f14,$f14
/*  f009c3c:	0c012974 */ 	jal	sqrtf
/*  f009c40:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f009c44:	c6500010 */ 	lwc1	$f16,0x10($s2)
/*  f009c48:	4610003c */ 	c.lt.s	$f0,$f16
/*  f009c4c:	00000000 */ 	nop
/*  f009c50:	45020023 */ 	bc1fl	.L0f009ce0
/*  f009c54:	86620002 */ 	lh	$v0,0x2($s3)
/*  f009c58:	8e300004 */ 	lw	$s0,0x4($s1)
/*  f009c5c:	3c088006 */ 	lui	$t0,%hi(var800616e8)
/*  f009c60:	250816e8 */ 	addiu	$t0,$t0,%lo(var800616e8)
/*  f009c64:	5200001e */ 	beqzl	$s0,.L0f009ce0
/*  f009c68:	86620002 */ 	lh	$v0,0x2($s3)
/*  f009c6c:	8d010000 */ 	lw	$at,0x0($t0)
/*  f009c70:	c6a4004c */ 	lwc1	$f4,0x4c($s5)
/*  f009c74:	02002025 */ 	or	$a0,$s0,$zero
/*  f009c78:	ae810000 */ 	sw	$at,0x0($s4)
/*  f009c7c:	8d0b0004 */ 	lw	$t3,0x4($t0)
/*  f009c80:	02803025 */ 	or	$a2,$s4,$zero
/*  f009c84:	27a70070 */ 	addiu	$a3,$sp,0x70
/*  f009c88:	ae8b0004 */ 	sw	$t3,0x4($s4)
/*  f009c8c:	8d010008 */ 	lw	$at,0x8($t0)
/*  f009c90:	ae810008 */ 	sw	$at,0x8($s4)
/*  f009c94:	3c017f1a */ 	lui	$at,%hi(var7f1a7f20)
/*  f009c98:	c4327f20 */ 	lwc1	$f18,%lo(var7f1a7f20)($at)
/*  f009c9c:	8e4a001c */ 	lw	$t2,0x1c($s2)
/*  f009ca0:	46049002 */ 	mul.s	$f0,$f18,$f4
/*  f009ca4:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f009ca8:	44050000 */ 	mfc1	$a1,$f0
/*  f009cac:	0fc0d049 */ 	jal	chrDamageByMisc
/*  f009cb0:	00000000 */ 	nop
/*  f009cb4:	8e0c0018 */ 	lw	$t4,0x18($s0)
/*  f009cb8:	8e0e0014 */ 	lw	$t6,0x14($s0)
/*  f009cbc:	3c010020 */ 	lui	$at,0x20
/*  f009cc0:	01816825 */ 	or	$t5,$t4,$at
/*  f009cc4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f009cc8:	05e10004 */ 	bgez	$t7,.L0f009cdc
/*  f009ccc:	ae0d0018 */ 	sw	$t5,0x18($s0)
/*  f009cd0:	02002025 */ 	or	$a0,$s0,$zero
/*  f009cd4:	0fc08946 */ 	jal	chrUncloak
/*  f009cd8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f009cdc:
/*  f009cdc:	86620002 */ 	lh	$v0,0x2($s3)
.L0f009ce0:
/*  f009ce0:	26730002 */ 	addiu	$s3,$s3,0x2
/*  f009ce4:	0443ffbb */ 	bgezl	$v0,.L0f009bd4
/*  f009ce8:	8eb80338 */ 	lw	$t8,0x338($s5)
.L0f009cec:
/*  f009cec:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f009cf0:
/*  f009cf0:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f009cf4:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f009cf8:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f009cfc:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f009d00:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*  f009d04:	8fb50030 */ 	lw	$s5,0x30($sp)
/*  f009d08:	03e00008 */ 	jr	$ra
/*  f009d0c:	27bd0308 */ 	addiu	$sp,$sp,0x308
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel nbombInflictDamage
.late_rodata
glabel var7f1a7f20
.word 0x3c23d70a
.text
/*  f0099e4:	27bdfcf8 */ 	addiu	$sp,$sp,-776
/*  f0099e8:	afb50030 */ 	sw	$s5,0x30($sp)
/*  f0099ec:	3c15800a */ 	lui	$s5,%hi(g_Vars)
/*  f0099f0:	26b59fc0 */ 	addiu	$s5,$s5,%lo(g_Vars)
/*  f0099f4:	8eaf0034 */ 	lw	$t7,0x34($s5)
/*  f0099f8:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f0099fc:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f009a00:	240e001f */ 	addiu	$t6,$zero,0x1f
/*  f009a04:	00809025 */ 	or	$s2,$a0,$zero
/*  f009a08:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f009a0c:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f009a10:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f009a14:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f009a18:	00008825 */ 	or	$s1,$zero,$zero
/*  f009a1c:	a3ae0070 */ 	sb	$t6,0x70($sp)
/*  f009a20:	19e000b2 */ 	blez	$t7,.L0f009cec
/*  f009a24:	a3a00073 */ 	sb	$zero,0x73($sp)
/*  f009a28:	8c98000c */ 	lw	$t8,0xc($a0)
/*  f009a2c:	2b01015f */ 	slti	$at,$t8,0x15f
/*  f009a30:	502000af */ 	beqzl	$at,.L0f009cf0
/*  f009a34:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f009a38:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f009a3c:	c4860010 */ 	lwc1	$f6,0x10($a0)
/*  f009a40:	3c13800a */ 	lui	$s3,%hi(g_Rooms)
/*  f009a44:	26734928 */ 	addiu	$s3,$s3,%lo(g_Rooms)
/*  f009a48:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f009a4c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f009a50:	2403008c */ 	addiu	$v1,$zero,0x8c
/*  f009a54:	27b4007c */ 	addiu	$s4,$sp,0x7c
/*  f009a58:	e7a800f4 */ 	swc1	$f8,0xf4($sp)
/*  f009a5c:	c4900010 */ 	lwc1	$f16,0x10($a0)
/*  f009a60:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f009a64:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f009a68:	e7b200f8 */ 	swc1	$f18,0xf8($sp)
/*  f009a6c:	c4860010 */ 	lwc1	$f6,0x10($a0)
/*  f009a70:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f009a74:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f009a78:	e7a800fc */ 	swc1	$f8,0xfc($sp)
/*  f009a7c:	c4900010 */ 	lwc1	$f16,0x10($a0)
/*  f009a80:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f009a84:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f009a88:	e7b200e8 */ 	swc1	$f18,0xe8($sp)
/*  f009a8c:	c4860010 */ 	lwc1	$f6,0x10($a0)
/*  f009a90:	c4840004 */ 	lwc1	$f4,0x4($a0)
/*  f009a94:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f009a98:	e7a800ec */ 	swc1	$f8,0xec($sp)
/*  f009a9c:	c4900010 */ 	lwc1	$f16,0x10($a0)
/*  f009aa0:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f009aa4:	8ea402bc */ 	lw	$a0,0x2bc($s5)
/*  f009aa8:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f009aac:	28810002 */ 	slti	$at,$a0,0x2
/*  f009ab0:	14200038 */ 	bnez	$at,.L0f009b94
/*  f009ab4:	e7b200f0 */ 	swc1	$f18,0xf0($sp)
.L0f009ab8:
/*  f009ab8:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f009abc:	c7a400e8 */ 	lwc1	$f4,0xe8($sp)
/*  f009ac0:	c7aa00f4 */ 	lwc1	$f10,0xf4($sp)
/*  f009ac4:	03231021 */ 	addu	$v0,$t9,$v1
/*  f009ac8:	c4460018 */ 	lwc1	$f6,0x18($v0)
/*  f009acc:	4606203c */ 	c.lt.s	$f4,$f6
/*  f009ad0:	00000000 */ 	nop
/*  f009ad4:	4503002c */ 	bc1tl	.L0f009b88
/*  f009ad8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f009adc:	c4480024 */ 	lwc1	$f8,0x24($v0)
/*  f009ae0:	c7b000ec */ 	lwc1	$f16,0xec($sp)
/*  f009ae4:	460a403c */ 	c.lt.s	$f8,$f10
/*  f009ae8:	00000000 */ 	nop
/*  f009aec:	45030026 */ 	bc1tl	.L0f009b88
/*  f009af0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f009af4:	c452001c */ 	lwc1	$f18,0x1c($v0)
/*  f009af8:	c7a600f8 */ 	lwc1	$f6,0xf8($sp)
/*  f009afc:	4612803c */ 	c.lt.s	$f16,$f18
/*  f009b00:	00000000 */ 	nop
/*  f009b04:	45030020 */ 	bc1tl	.L0f009b88
/*  f009b08:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f009b0c:	c4440028 */ 	lwc1	$f4,0x28($v0)
/*  f009b10:	c7a800f0 */ 	lwc1	$f8,0xf0($sp)
/*  f009b14:	4606203c */ 	c.lt.s	$f4,$f6
/*  f009b18:	00000000 */ 	nop
/*  f009b1c:	4503001a */ 	bc1tl	.L0f009b88
/*  f009b20:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f009b24:	c44a0020 */ 	lwc1	$f10,0x20($v0)
/*  f009b28:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
/*  f009b2c:	460a403c */ 	c.lt.s	$f8,$f10
/*  f009b30:	00000000 */ 	nop
/*  f009b34:	45030014 */ 	bc1tl	.L0f009b88
/*  f009b38:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f009b3c:	c450002c */ 	lwc1	$f16,0x2c($v0)
/*  f009b40:	2a210034 */ 	slti	$at,$s1,0x34
/*  f009b44:	4612803c */ 	c.lt.s	$f16,$f18
/*  f009b48:	00000000 */ 	nop
/*  f009b4c:	4503000e */ 	bc1tl	.L0f009b88
/*  f009b50:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f009b54:	1020000b */ 	beqz	$at,.L0f009b84
/*  f009b58:	00114040 */ 	sll	$t0,$s1,0x1
/*  f009b5c:	02884821 */ 	addu	$t1,$s4,$t0
/*  f009b60:	a5300000 */ 	sh	$s0,0x0($t1)
/*  f009b64:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f009b68:	afa30040 */ 	sw	$v1,0x40($sp)
/*  f009b6c:	02002025 */ 	or	$a0,$s0,$zero
/*  f009b70:	2405ffda */ 	addiu	$a1,$zero,-38
/*  f009b74:	0fc010e3 */ 	jal	roomAdjustLighting
/*  f009b78:	2406ff4c */ 	addiu	$a2,$zero,-180
/*  f009b7c:	8fa30040 */ 	lw	$v1,0x40($sp)
/*  f009b80:	8ea402bc */ 	lw	$a0,0x2bc($s5)
.L0f009b84:
/*  f009b84:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f009b88:
/*  f009b88:	0204082a */ 	slt	$at,$s0,$a0
/*  f009b8c:	1420ffca */ 	bnez	$at,.L0f009ab8
/*  f009b90:	2463008c */ 	addiu	$v1,$v1,0x8c
.L0f009b94:
/*  f009b94:	27a4007c */ 	addiu	$a0,$sp,0x7c
/*  f009b98:	00115840 */ 	sll	$t3,$s1,0x1
/*  f009b9c:	008b6021 */ 	addu	$t4,$a0,$t3
/*  f009ba0:	240affff */ 	addiu	$t2,$zero,-1
/*  f009ba4:	27b00100 */ 	addiu	$s0,$sp,0x100
/*  f009ba8:	a58a0000 */ 	sh	$t2,0x0($t4)
/*  f009bac:	02002825 */ 	or	$a1,$s0,$zero
/*  f009bb0:	0fc197e0 */ 	jal	roomGetProps
/*  f009bb4:	24060100 */ 	addiu	$a2,$zero,0x100
/*  f009bb8:	87ad0100 */ 	lh	$t5,0x100($sp)
/*  f009bbc:	02009825 */ 	or	$s3,$s0,$zero
/*  f009bc0:	27ae0100 */ 	addiu	$t6,$sp,0x100
/*  f009bc4:	05a00049 */ 	bltz	$t5,.L0f009cec
/*  f009bc8:	27b4004c */ 	addiu	$s4,$sp,0x4c
/*  f009bcc:	85c20000 */ 	lh	$v0,0x0($t6)
/*  f009bd0:	8eb80338 */ 	lw	$t8,0x338($s5)
.L0f009bd4:
/*  f009bd4:	000278c0 */ 	sll	$t7,$v0,0x3
/*  f009bd8:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f009bdc:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f009be0:	01f88821 */ 	addu	$s1,$t7,$t8
/*  f009be4:	86390002 */ 	lh	$t9,0x2($s1)
/*  f009be8:	5720003d */ 	bnezl	$t9,.L0f009ce0
/*  f009bec:	86620002 */ 	lh	$v0,0x2($s3)
/*  f009bf0:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f009bf4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f009bf8:	10410003 */ 	beq	$v0,$at,.L0f009c08
/*  f009bfc:	24010006 */ 	addiu	$at,$zero,0x6
/*  f009c00:	54410037 */ 	bnel	$v0,$at,.L0f009ce0
/*  f009c04:	86620002 */ 	lh	$v0,0x2($s3)
.L0f009c08:
/*  f009c08:	c6240008 */ 	lwc1	$f4,0x8($s1)
/*  f009c0c:	c6460000 */ 	lwc1	$f6,0x0($s2)
/*  f009c10:	c628000c */ 	lwc1	$f8,0xc($s1)
/*  f009c14:	c64a0004 */ 	lwc1	$f10,0x4($s2)
/*  f009c18:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f009c1c:	c6300010 */ 	lwc1	$f16,0x10($s1)
/*  f009c20:	c6520008 */ 	lwc1	$f18,0x8($s2)
/*  f009c24:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f009c28:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f009c2c:	46128381 */ 	sub.s	$f14,$f16,$f18
/*  f009c30:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f009c34:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f009c38:	460e7282 */ 	mul.s	$f10,$f14,$f14
/*  f009c3c:	0c012974 */ 	jal	sqrtf
/*  f009c40:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f009c44:	c6500010 */ 	lwc1	$f16,0x10($s2)
/*  f009c48:	4610003c */ 	c.lt.s	$f0,$f16
/*  f009c4c:	00000000 */ 	nop
/*  f009c50:	45020023 */ 	bc1fl	.L0f009ce0
/*  f009c54:	86620002 */ 	lh	$v0,0x2($s3)
/*  f009c58:	8e300004 */ 	lw	$s0,0x4($s1)
/*  f009c5c:	3c088006 */ 	lui	$t0,%hi(var800616e8)
/*  f009c60:	250816e8 */ 	addiu	$t0,$t0,%lo(var800616e8)
/*  f009c64:	5200001e */ 	beqzl	$s0,.L0f009ce0
/*  f009c68:	86620002 */ 	lh	$v0,0x2($s3)
/*  f009c6c:	8d010000 */ 	lw	$at,0x0($t0)
/*  f009c70:	c6a4004c */ 	lwc1	$f4,0x4c($s5)
/*  f009c74:	02002025 */ 	or	$a0,$s0,$zero
/*  f009c78:	ae810000 */ 	sw	$at,0x0($s4)
/*  f009c7c:	8d0b0004 */ 	lw	$t3,0x4($t0)
/*  f009c80:	02803025 */ 	or	$a2,$s4,$zero
/*  f009c84:	27a70070 */ 	addiu	$a3,$sp,0x70
/*  f009c88:	ae8b0004 */ 	sw	$t3,0x4($s4)
/*  f009c8c:	8d010008 */ 	lw	$at,0x8($t0)
/*  f009c90:	ae810008 */ 	sw	$at,0x8($s4)
/*  f009c94:	3c017f1a */ 	lui	$at,%hi(var7f1a7f20)
/*  f009c98:	c4327f20 */ 	lwc1	$f18,%lo(var7f1a7f20)($at)
/*  f009c9c:	8e4a001c */ 	lw	$t2,0x1c($s2)
/*  f009ca0:	46049002 */ 	mul.s	$f0,$f18,$f4
/*  f009ca4:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f009ca8:	44050000 */ 	mfc1	$a1,$f0
/*  f009cac:	0fc0d049 */ 	jal	chrDamageByMisc
/*  f009cb0:	00000000 */ 	nop
/*  f009cb4:	8e0c0018 */ 	lw	$t4,0x18($s0)
/*  f009cb8:	8e0e0014 */ 	lw	$t6,0x14($s0)
/*  f009cbc:	3c010020 */ 	lui	$at,0x20
/*  f009cc0:	01816825 */ 	or	$t5,$t4,$at
/*  f009cc4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f009cc8:	05e10004 */ 	bgez	$t7,.L0f009cdc
/*  f009ccc:	ae0d0018 */ 	sw	$t5,0x18($s0)
/*  f009cd0:	02002025 */ 	or	$a0,$s0,$zero
/*  f009cd4:	0fc08946 */ 	jal	chrUncloak
/*  f009cd8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f009cdc:
/*  f009cdc:	86620002 */ 	lh	$v0,0x2($s3)
.L0f009ce0:
/*  f009ce0:	26730002 */ 	addiu	$s3,$s3,0x2
/*  f009ce4:	0443ffbb */ 	bgezl	$v0,.L0f009bd4
/*  f009ce8:	8eb80338 */ 	lw	$t8,0x338($s5)
.L0f009cec:
/*  f009cec:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f009cf0:
/*  f009cf0:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f009cf4:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f009cf8:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f009cfc:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f009d00:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*  f009d04:	8fb50030 */ 	lw	$s5,0x30($sp)
/*  f009d08:	03e00008 */ 	jr	$ra
/*  f009d0c:	27bd0308 */ 	addiu	$sp,$sp,0x308
);
#else
GLOBAL_ASM(
glabel nbombInflictDamage
.late_rodata
glabel var7f1a7f20
.word 0x3c23d70a
.text
/*  f00968c:	27bdfce0 */ 	addiu	$sp,$sp,-800
/*  f009690:	3c0f800a */ 	lui	$t7,0x800a
/*  f009694:	8defe6f4 */ 	lw	$t7,-0x190c($t7)
/*  f009698:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f00969c:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f0096a0:	240e001f */ 	addiu	$t6,$zero,0x1f
/*  f0096a4:	00809825 */ 	or	$s3,$a0,$zero
/*  f0096a8:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0096ac:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f0096b0:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f0096b4:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f0096b8:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f0096bc:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f0096c0:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f0096c4:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0096c8:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f0096cc:	00008825 */ 	or	$s1,$zero,$zero
/*  f0096d0:	a3ae0088 */ 	sb	$t6,0x88($sp)
/*  f0096d4:	19e000b3 */ 	blez	$t7,.NB0f0099a4
/*  f0096d8:	a3a0008b */ 	sb	$zero,0x8b($sp)
/*  f0096dc:	8c98000c */ 	lw	$t8,0xc($a0)
/*  f0096e0:	2b01015f */ 	slti	$at,$t8,0x15f
/*  f0096e4:	502000b0 */ 	beqzl	$at,.NB0f0099a8
/*  f0096e8:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0096ec:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f0096f0:	c4860010 */ 	lwc1	$f6,0x10($a0)
/*  f0096f4:	3c03800a */ 	lui	$v1,0x800a
/*  f0096f8:	8c63e97c */ 	lw	$v1,-0x1684($v1)
/*  f0096fc:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f009700:	3c14800b */ 	lui	$s4,0x800b
/*  f009704:	28610002 */ 	slti	$at,$v1,0x2
/*  f009708:	269490a8 */ 	addiu	$s4,$s4,-28504
/*  f00970c:	e7a8010c */ 	swc1	$f8,0x10c($sp)
/*  f009710:	c4900010 */ 	lwc1	$f16,0x10($a0)
/*  f009714:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f009718:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f00971c:	2412008c */ 	addiu	$s2,$zero,0x8c
/*  f009720:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f009724:	27b50094 */ 	addiu	$s5,$sp,0x94
/*  f009728:	e7b20110 */ 	swc1	$f18,0x110($sp)
/*  f00972c:	c4860010 */ 	lwc1	$f6,0x10($a0)
/*  f009730:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f009734:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f009738:	e7a80114 */ 	swc1	$f8,0x114($sp)
/*  f00973c:	c4900010 */ 	lwc1	$f16,0x10($a0)
/*  f009740:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f009744:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f009748:	e7b20100 */ 	swc1	$f18,0x100($sp)
/*  f00974c:	c4860010 */ 	lwc1	$f6,0x10($a0)
/*  f009750:	c4840004 */ 	lwc1	$f4,0x4($a0)
/*  f009754:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f009758:	e7a80104 */ 	swc1	$f8,0x104($sp)
/*  f00975c:	c4900010 */ 	lwc1	$f16,0x10($a0)
/*  f009760:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f009764:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f009768:	14200037 */ 	bnez	$at,.NB0f009848
/*  f00976c:	e7b20108 */ 	swc1	$f18,0x108($sp)
.NB0f009770:
/*  f009770:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f009774:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*  f009778:	c7aa010c */ 	lwc1	$f10,0x10c($sp)
/*  f00977c:	03321021 */ 	addu	$v0,$t9,$s2
/*  f009780:	c4460018 */ 	lwc1	$f6,0x18($v0)
/*  f009784:	4606203c */ 	c.lt.s	$f4,$f6
/*  f009788:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00978c:	4503002b */ 	bc1tl	.NB0f00983c
/*  f009790:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f009794:	c4480024 */ 	lwc1	$f8,0x24($v0)
/*  f009798:	c7b00104 */ 	lwc1	$f16,0x104($sp)
/*  f00979c:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0097a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0097a4:	45030025 */ 	bc1tl	.NB0f00983c
/*  f0097a8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0097ac:	c452001c */ 	lwc1	$f18,0x1c($v0)
/*  f0097b0:	c7a60110 */ 	lwc1	$f6,0x110($sp)
/*  f0097b4:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0097b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0097bc:	4503001f */ 	bc1tl	.NB0f00983c
/*  f0097c0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0097c4:	c4440028 */ 	lwc1	$f4,0x28($v0)
/*  f0097c8:	c7a80108 */ 	lwc1	$f8,0x108($sp)
/*  f0097cc:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0097d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0097d4:	45030019 */ 	bc1tl	.NB0f00983c
/*  f0097d8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0097dc:	c44a0020 */ 	lwc1	$f10,0x20($v0)
/*  f0097e0:	c7b20114 */ 	lwc1	$f18,0x114($sp)
/*  f0097e4:	460a403c */ 	c.lt.s	$f8,$f10
/*  f0097e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0097ec:	45030013 */ 	bc1tl	.NB0f00983c
/*  f0097f0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0097f4:	c450002c */ 	lwc1	$f16,0x2c($v0)
/*  f0097f8:	2a210034 */ 	slti	$at,$s1,0x34
/*  f0097fc:	4612803c */ 	c.lt.s	$f16,$f18
/*  f009800:	00000000 */ 	sll	$zero,$zero,0x0
/*  f009804:	4503000d */ 	bc1tl	.NB0f00983c
/*  f009808:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f00980c:	1020000a */ 	beqz	$at,.NB0f009838
/*  f009810:	00114040 */ 	sll	$t0,$s1,0x1
/*  f009814:	02a84821 */ 	addu	$t1,$s5,$t0
/*  f009818:	a5300000 */ 	sh	$s0,0x0($t1)
/*  f00981c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f009820:	02002025 */ 	or	$a0,$s0,$zero
/*  f009824:	2405ffda */ 	addiu	$a1,$zero,-38
/*  f009828:	0fc01035 */ 	jal	roomAdjustLighting
/*  f00982c:	2406ff4c */ 	addiu	$a2,$zero,-180
/*  f009830:	3c03800a */ 	lui	$v1,0x800a
/*  f009834:	8c63e97c */ 	lw	$v1,-0x1684($v1)
.NB0f009838:
/*  f009838:	26100001 */ 	addiu	$s0,$s0,0x1
.NB0f00983c:
/*  f00983c:	0203082a */ 	slt	$at,$s0,$v1
/*  f009840:	1420ffcb */ 	bnez	$at,.NB0f009770
/*  f009844:	2652008c */ 	addiu	$s2,$s2,0x8c
.NB0f009848:
/*  f009848:	27a40094 */ 	addiu	$a0,$sp,0x94
/*  f00984c:	00115840 */ 	sll	$t3,$s1,0x1
/*  f009850:	008b6021 */ 	addu	$t4,$a0,$t3
/*  f009854:	240affff */ 	addiu	$t2,$zero,-1
/*  f009858:	27b00118 */ 	addiu	$s0,$sp,0x118
/*  f00985c:	a58a0000 */ 	sh	$t2,0x0($t4)
/*  f009860:	02002825 */ 	or	$a1,$s0,$zero
/*  f009864:	0fc1947a */ 	jal	roomGetProps
/*  f009868:	24060100 */ 	addiu	$a2,$zero,0x100
/*  f00986c:	87ad0118 */ 	lh	$t5,0x118($sp)
/*  f009870:	02009025 */ 	or	$s2,$s0,$zero
/*  f009874:	27ae0118 */ 	addiu	$t6,$sp,0x118
/*  f009878:	05a0004a */ 	bltz	$t5,.NB0f0099a4
/*  f00987c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f009880:	3c1e8006 */ 	lui	$s8,0x8006
/*  f009884:	27de3bf8 */ 	addiu	$s8,$s8,0x3bf8
/*  f009888:	85c20000 */ 	lh	$v0,0x0($t6)
/*  f00988c:	c4341bc0 */ 	lwc1	$f20,0x1bc0($at)
/*  f009890:	24170006 */ 	addiu	$s7,$zero,0x6
/*  f009894:	24160003 */ 	addiu	$s6,$zero,0x3
/*  f009898:	24150048 */ 	addiu	$s5,$zero,0x48
/*  f00989c:	27b40064 */ 	addiu	$s4,$sp,0x64
.NB0f0098a0:
/*  f0098a0:	00550019 */ 	multu	$v0,$s5
/*  f0098a4:	3c18800a */ 	lui	$t8,0x800a
/*  f0098a8:	8f18e9f8 */ 	lw	$t8,-0x1608($t8)
/*  f0098ac:	00007812 */ 	mflo	$t7
/*  f0098b0:	01f88821 */ 	addu	$s1,$t7,$t8
/*  f0098b4:	86390002 */ 	lh	$t9,0x2($s1)
/*  f0098b8:	57200037 */ 	bnezl	$t9,.NB0f009998
/*  f0098bc:	86420002 */ 	lh	$v0,0x2($s2)
/*  f0098c0:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f0098c4:	52c20004 */ 	beql	$s6,$v0,.NB0f0098d8
/*  f0098c8:	c6240008 */ 	lwc1	$f4,0x8($s1)
/*  f0098cc:	56e20032 */ 	bnel	$s7,$v0,.NB0f009998
/*  f0098d0:	86420002 */ 	lh	$v0,0x2($s2)
/*  f0098d4:	c6240008 */ 	lwc1	$f4,0x8($s1)
.NB0f0098d8:
/*  f0098d8:	c6660000 */ 	lwc1	$f6,0x0($s3)
/*  f0098dc:	c628000c */ 	lwc1	$f8,0xc($s1)
/*  f0098e0:	c66a0004 */ 	lwc1	$f10,0x4($s3)
/*  f0098e4:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f0098e8:	c6300010 */ 	lwc1	$f16,0x10($s1)
/*  f0098ec:	c6720008 */ 	lwc1	$f18,0x8($s3)
/*  f0098f0:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f0098f4:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f0098f8:	46128381 */ 	sub.s	$f14,$f16,$f18
/*  f0098fc:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f009900:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f009904:	460e7282 */ 	mul.s	$f10,$f14,$f14
/*  f009908:	0c012e84 */ 	jal	sqrtf
/*  f00990c:	460a4300 */ 	add.s	$f12,$f8,$f10
/*  f009910:	c6700010 */ 	lwc1	$f16,0x10($s3)
/*  f009914:	4610003c */ 	c.lt.s	$f0,$f16
/*  f009918:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00991c:	4502001e */ 	bc1fl	.NB0f009998
/*  f009920:	86420002 */ 	lh	$v0,0x2($s2)
/*  f009924:	8fc10000 */ 	lw	$at,0x0($s8)
/*  f009928:	8e300004 */ 	lw	$s0,0x4($s1)
/*  f00992c:	8fc90004 */ 	lw	$t1,0x4($s8)
/*  f009930:	ae810000 */ 	sw	$at,0x0($s4)
/*  f009934:	8fc10008 */ 	lw	$at,0x8($s8)
/*  f009938:	ae890004 */ 	sw	$t1,0x4($s4)
/*  f00993c:	02803025 */ 	or	$a2,$s4,$zero
/*  f009940:	ae810008 */ 	sw	$at,0x8($s4)
/*  f009944:	3c01800a */ 	lui	$at,0x800a
/*  f009948:	c432e70c */ 	lwc1	$f18,-0x18f4($at)
/*  f00994c:	8e6b001c */ 	lw	$t3,0x1c($s3)
/*  f009950:	27a70088 */ 	addiu	$a3,$sp,0x88
/*  f009954:	4612a002 */ 	mul.s	$f0,$f20,$f18
/*  f009958:	02002025 */ 	or	$a0,$s0,$zero
/*  f00995c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f009960:	44050000 */ 	mfc1	$a1,$f0
/*  f009964:	0fc0ce8b */ 	jal	chrDamageByMisc
/*  f009968:	00000000 */ 	sll	$zero,$zero,0x0
/*  f00996c:	8e0a0018 */ 	lw	$t2,0x18($s0)
/*  f009970:	8e0d0014 */ 	lw	$t5,0x14($s0)
/*  f009974:	3c010020 */ 	lui	$at,0x20
/*  f009978:	01416025 */ 	or	$t4,$t2,$at
/*  f00997c:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f009980:	05c10004 */ 	bgez	$t6,.NB0f009994
/*  f009984:	ae0c0018 */ 	sw	$t4,0x18($s0)
/*  f009988:	02002025 */ 	or	$a0,$s0,$zero
/*  f00998c:	0fc08814 */ 	jal	chrUncloak
/*  f009990:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f009994:
/*  f009994:	86420002 */ 	lh	$v0,0x2($s2)
.NB0f009998:
/*  f009998:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f00999c:	0441ffc0 */ 	bgez	$v0,.NB0f0098a0
/*  f0099a0:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0099a4:
/*  f0099a4:	8fbf004c */ 	lw	$ra,0x4c($sp)
.NB0f0099a8:
/*  f0099a8:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f0099ac:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0099b0:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f0099b4:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f0099b8:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f0099bc:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f0099c0:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f0099c4:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f0099c8:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f0099cc:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f0099d0:	03e00008 */ 	jr	$ra
/*  f0099d4:	27bd0320 */ 	addiu	$sp,$sp,0x320
);
#endif
#else
// Mismatch: different usage of callee-save registers relating to room loop
void nbombInflictDamage(struct nbomb *nbomb)
{
	s32 index = 0;
	u32 stack;
	s16 propnums[256]; // 100
	struct coord bbmin; // f4
	struct coord bbmax; // e8
	s16 roomnums[54]; // 7c
	s16 *propnumptr;
	s32 i;
	struct gset gset; // 70
	u32 stack2;

	gset.weaponnum = WEAPON_NBOMB;
	gset.weaponfunc = FUNC_PRIMARY;

	if (g_Vars.lvupdate240 <= 0 || nbomb->age240 > 350) {
		return;
	}

	if (g_Rooms);

	// Find rooms which intersect the nbomb dome's bbox
	bbmin.x = nbomb->pos.f[0] - nbomb->radius;
	bbmin.y = nbomb->pos.f[1] - nbomb->radius;
	bbmin.z = nbomb->pos.f[2] - nbomb->radius;

	bbmax.x = nbomb->pos.f[0] + nbomb->radius;
	bbmax.y = nbomb->pos.f[1] + nbomb->radius;
	bbmax.z = nbomb->pos.f[2] + nbomb->radius;

	if (g_Vars.roomcount);
	if (g_Vars.roomcount);

	for (i = 1; i < g_Vars.roomcount; i++) {
		if (!(bbmax.f[0] < g_Rooms[i].bbmin[0]
				|| bbmin.f[0] > g_Rooms[i].bbmax[0]
				|| bbmax.f[1] < g_Rooms[i].bbmin[1]
				|| bbmin.f[1] > g_Rooms[i].bbmax[1]
				|| bbmax.f[2] < g_Rooms[i].bbmin[2]
				|| bbmin.f[2] > g_Rooms[i].bbmax[2])
				&& index < 52) {
			roomnums[index] = i;
			index++;
			roomAdjustLighting(i, -38, -180);
		}
	}

	roomnums[index] = -1;

	// Iterate props in the affected rooms and damage any chrs
	roomGetProps(roomnums, propnums, 256);

	propnumptr = propnums;

	while (*propnumptr >= 0) {
		struct prop *prop = &g_Vars.props[*propnumptr];

		if (prop->timetoregen == 0) {
			if (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER) {
				f32 xdiff = prop->pos.f[0] - nbomb->pos.f[0];
				f32 ydiff = prop->pos.f[1] - nbomb->pos.f[1];
				f32 zdiff = prop->pos.f[2] - nbomb->pos.f[2];

				f32 dist = sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);

				if (dist < nbomb->radius) {
					struct chrdata *chr = prop->chr;

					if (chr) {
						struct coord vector = {0, 0, 0};
						f32 damage = 0.0099999997764826f * g_Vars.lvupdate240freal;

						chrDamageByMisc(chr, damage, &vector, &gset, nbomb->ownerprop);

						chr->chrflags |= CHRCFLAG_TRIGGERSHOTLIST;

						if (chr->hidden & CHRHFLAG_CLOAKED) {
							chrUncloak(chr, true);
						}
					}
				}
			}
		}

		propnumptr++;
	}
}
#endif

u32 var800616e8 = 0x00000000;
u32 var800616ec = 0x00000000;
u32 var800616f0 = 0x00000000;
u32 var800616f4 = 0x00000000;
u32 var800616f8 = 0x00000000;
u32 var800616fc = 0x00000000;

void nbombTick(struct nbomb *nbomb)
{
	if (nbomb->age240 >= 0) {
		s32 age60;
		s32 increment = (g_Vars.lvupdate240 + 2) >> 2;

		nbomb->age240 += increment;

		if (nbomb->age240 < TICKS(80)) {
			nbomb->radius = nbomb->age240 / (PAL ? 66.0f : 80.0f);
			nbomb->radius = sqrtf(sqrtf(nbomb->radius));
			nbomb->unk18 = 0;
		} else {
			nbomb->radius = sinf((nbomb->age240 - TICKS(80)) * (PAL ? 0.062800005078316f : 0.0523333363235f)) * 0.05f + 1.0f;

			// Return value is not used - could have been printed
			sinf((nbomb->age240 - TICKS(80)) * (PAL ? 0.062800005078316f : 0.0523333363235f));

			nbomb->unk18 = ((nbomb->age240 - TICKS(80)) / (PAL ? 225.0f : 270.0f)) * 3.0f;
		}

		nbomb->radius *= 500.0f;

		nbombInflictDamage(nbomb);

		age60 = nbomb->age240 / 4;

		if (age60 > 40) {
			age60 = 40;
		}

#if PAL
		nbomb->unk14 += increment * age60 * 60 / 50;
#else
		nbomb->unk14 += increment * age60;
#endif

		nbomb->unk14 %= 0x800;

		if (nbomb->age240 > (PAL ? 307 : 370)) {
			nbomb->age240 = -1;
		}
	}
}

void nbombsTick(void)
{
	s32 i;
	s32 youngest240 = 20000;
	s32 somevalue;

	if (g_Vars.lvupdate240 != 0) {
		g_NbombsActive = false;
	}

	for (i = 0; i < 6; i++) {
		if (g_Vars.lvupdate240 != 0 && g_Nbombs[i].age240 >= 0) {
			nbombTick(&g_Nbombs[i]);

			if (g_Nbombs[i].age240 < youngest240) {
				youngest240 = g_Nbombs[i].age240;
			}

			g_NbombsActive = true;
		}
	}

	somevalue = 0;

	if (youngest240 < TICKS(350)) {
		if (g_Vars.lvupdate240 != 0) {
			if (g_NbombAudioHandle == 0) {
				sndStart(var80095200, SFX_SHIP_HUM, &g_NbombAudioHandle, -1, -1, -1, -1, -1);
			}

			somevalue = 32767;

			if (g_NbombAudioHandle) {
				f32 speed = menuGetSinOscFrac(20) * 0.02f + 0.4f;

				if (youngest240 > TICKS(300)) {
					somevalue = (1.0f - (f32)(youngest240 - TICKS(300)) / (PAL ? 41.0f : 50.0f)) * 32767.0f;
				}

				if (youngest240 >= TICKS(350)) {
					somevalue = 0;
				}

				audioPostEvent(g_NbombAudioHandle, 8, somevalue);
				audioPostEvent(g_NbombAudioHandle, 16, *(s32 *)&speed);
			}
		} else {
			if (g_NbombAudioHandle && sndGetState(g_NbombAudioHandle) != AL_STOPPED) {
				audioStop(g_NbombAudioHandle);
			}
		}
	} else {
		if (g_NbombAudioHandle && sndGetState(g_NbombAudioHandle) != AL_STOPPED) {
			audioStop(g_NbombAudioHandle);
		}
	}

	if (g_Vars.lvupdate240 == 0) {
		for (i = 0; i < 6; i++) {
			if (g_Nbombs[i].age240 >= 0) {
				if (g_Nbombs[i].audiohandle20 && sndGetState(g_Nbombs[i].audiohandle20) != AL_STOPPED) {
					audioStop(g_Nbombs[i].audiohandle20);
#if VERSION < VERSION_NTSC_1_0
					g_Nbombs[i].audiohandle20 = NULL;
#endif
				}

				if (g_Nbombs[i].audiohandle24 && sndGetState(g_Nbombs[i].audiohandle24) != AL_STOPPED) {
					audioStop(g_Nbombs[i].audiohandle24);
#if VERSION < VERSION_NTSC_1_0
					g_Nbombs[i].audiohandle24 = NULL;
#endif
				}
			}
		}
	}
}

Gfx *nbombsRender(Gfx *gdl)
{
	s32 i;
	Gfx *subgdl = NULL;

	for (i = 0; i < 6; i++) {
		if (g_Nbombs[i].age240 >= 0) {
			if (!subgdl) {
				subgdl = nbombCreateGdl();
			}

			gdl = nbombRender(gdl, &g_Nbombs[i], subgdl);
		}
	}

	return gdl;
}

void nbombCreateStorm(struct coord *pos, struct prop *ownerprop)
{
	u32 stack;
	s32 oldest240;
	s32 index;
	s32 i;

	oldest240 = -1;
	index = 0;

	g_NbombsActive = true;

	for (i = 0; i < 6; i++) {
		if (g_Nbombs[i].age240 == -1
#if VERSION >= VERSION_NTSC_1_0
				&& g_Nbombs[i].audiohandle20 == NULL
				&& g_Nbombs[i].audiohandle24 == NULL
#endif
				) {
			index = i;
			break;
		}

		if (g_Nbombs[i].age240 > oldest240) {
			index = i;
			oldest240 = g_Nbombs[i].age240;
		}
	}

	nbombReset(&g_Nbombs[index]);

	g_Nbombs[index].pos.x = pos->x;
	g_Nbombs[index].pos.y = pos->y;
	g_Nbombs[index].pos.z = pos->z;
	g_Nbombs[index].age240 = 0;
	g_Nbombs[index].ownerprop = ownerprop;

#if VERSION >= VERSION_NTSC_1_0
	// Newer versions only play audio if the handles are null,
	// while ntsc-beta clears the handles then plays them unconditionally.
	if (g_Nbombs[index].audiohandle20 == NULL) {
		sndStart(var80095200, SFX_LAUNCH_ROCKET, &g_Nbombs[index].audiohandle20, -1, -1, -1, -1, -1);

		if (g_Nbombs[index].audiohandle20) {
			union audioparam param;
			param.f32 = 0.4f;
			audioPostEvent(g_Nbombs[index].audiohandle20, 16, param.s32);
		}
	}

	if (g_Nbombs[index].audiohandle24 == NULL) {
		sndStart(var80095200, SFX_LAUNCH_ROCKET, &g_Nbombs[index].audiohandle24, -1, -1, -1, -1, -1);

		if (g_Nbombs[index].audiohandle24) {
			union audioparam param;
			param.f32 = 0.4f;
			audioPostEvent(g_Nbombs[index].audiohandle24, 16, param.s32);
		}
	}
#else
	g_Nbombs[index].audiohandle20 = NULL;
	g_Nbombs[index].audiohandle24 = NULL;

	sndStart(var80095200, SFX_LAUNCH_ROCKET, &g_Nbombs[index].audiohandle20, -1, -1, -1, -1, -1);

	if (g_Nbombs[index].audiohandle20) {
		union audioparam param;
		param.f32 = 0.4f;
		audioPostEvent(g_Nbombs[index].audiohandle20, 16, param.s32);
	}

	sndStart(var80095200, SFX_LAUNCH_ROCKET, &g_Nbombs[index].audiohandle24, -1, -1, -1, -1, -1);

	if (g_Nbombs[index].audiohandle24) {
		union audioparam param;
		param.f32 = 0.4f;
		audioPostEvent(g_Nbombs[index].audiohandle24, 16, param.s32);
	}
#endif
}

bool doorIsOpenOrOpening(s32 tagnum)
{
	struct defaultobj *obj = objFindByTagId(tagnum);

	if (obj && obj->prop && obj->type == OBJTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *)obj;

		if (door->mode == DOORMODE_IDLE) {
			if (door->frac <= 0) {
				return false;
			}
			return true;
		} else if (door->mode == DOORMODE_OPENING) {
			return true;
		} else if (door->mode == DOORMODE_CLOSING) {
			return false;
		} else {
			return false;
		}
	}

	return false;
}

f32 gasGetDoorFrac(s32 tagnum)
{
	struct defaultobj *obj = objFindByTagId(tagnum);

	if (obj && obj->prop && obj->type == OBJTYPE_DOOR) {
		struct doorobj *door = (struct doorobj *)obj;
		return door->frac;
	}

	return 0;
}

/**
 * Checks if the player is inside an nbomb storm, and if so renders the black
 * storm texture directly over the screen.
 */
Gfx *nbombRenderOverlay(Gfx *gdl)
{
	bool inside = false;
	struct coord campos;
	s32 finalalpha = 0;
	s32 i;
	u32 stack[2];
	s16 t;
	s16 s;
	u32 stack2[2];
	bool drawn = false;
	s32 stack3;
	u32 *colours;
	struct gfxvtx *vertices;
	s16 viewleft;
	s16 viewtop;
	s16 viewright;
	s16 viewbottom;

	campos.x = g_Vars.currentplayer->cam_pos.x;
	campos.y = g_Vars.currentplayer->cam_pos.y;
	campos.z = g_Vars.currentplayer->cam_pos.z;

	for (i = 0; i < ARRAYCOUNT(g_Nbombs); i++) {
		if (g_Nbombs[i].age240 >= 0 && g_Nbombs[i].age240 <= TICKS(350)) {
			f32 xdiff = campos.f[0] - g_Nbombs[i].pos.f[0];
			f32 ydiff = campos.f[1] - g_Nbombs[i].pos.f[1];
			f32 zdiff = campos.f[2] - g_Nbombs[i].pos.f[2];

			if (sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff) < g_Nbombs[i].radius) {
				u32 alpha = nbombCalculateAlpha(&g_Nbombs[i]);

				inside = true;

				if (alpha > finalalpha) {
					finalalpha = alpha;
				}
			}
		}
	}

	if (inside) {
		colours = gfxAllocateColours(1);
		vertices = gfxAllocateVertices(4);

		viewleft = viGetViewLeft() * 10;
		viewtop = viGetViewTop() * 10;
		viewright = (s16) (viGetViewLeft() + viGetViewWidth()) * 10;
		viewbottom = (s16) (viGetViewTop() + viGetViewHeight()) * 10;

		s = (s32) (8.0f * g_20SecIntervalFrac * 128.0f * 32.0f) % 2048;
		t = (s16) ((s32) (campos.f[1] * 8.0f) % 2048) + (s16) (2.0f * g_20SecIntervalFrac * 128.0f * 32.0f);

		drawn = true;

		if (1);
		if (1);

		gdl = func0f0d479c(gdl);

		if (1);

		texSelect(&gdl, &g_TexGeneralConfigs[10], 2, 1, 2, true, NULL);

		gDPPipeSync(gdl++);
		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
		gDPSetAlphaCompare(gdl++, G_AC_NONE);
		gDPSetCombineMode(gdl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
		gSPClearGeometryMode(gdl++, G_CULL_BOTH);
		gDPSetColorDither(gdl++, G_CD_DISABLE);
		gDPSetTextureFilter(gdl++, G_TF_BILERP);
		gDPSetRenderMode(gdl++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
		gDPSetTexturePersp(gdl++, G_TP_PERSP);

		vertices[0].x = viewleft;
		vertices[0].y = viewtop;
		vertices[0].z = -10;

		vertices[1].x = viewright;
		vertices[1].y = viewtop;
		vertices[1].z = -10;

		vertices[2].x = viewright;
		vertices[2].y = viewbottom;
		vertices[2].z = -10;

		vertices[3].x = viewleft;
		vertices[3].y = viewbottom;
		vertices[3].z = -10;

		vertices[0].s = s;
		vertices[0].t = t;
		vertices[1].s = s + 160;
		vertices[1].t = t;
		vertices[2].s = s + 160;
		vertices[2].t = t + 960;
		vertices[3].s = s;
		vertices[3].t = t + 960;

		vertices[0].colour = 0;
		vertices[1].colour = 0;
		vertices[2].colour = 0;
		vertices[3].colour = 0;

		colours[0] = finalalpha;

		gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 1);
		gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 4);

		gDPTri2(gdl++, 0, 1, 2, 2, 3, 0);
	}

	if (drawn) {
		gdl = func0f0d49c8(gdl);
	}

	return gdl;
}

Gfx *gasRender(Gfx *gdl)
{
	bool show = false;
	f32 alphafrac = 1.0f;
	struct coord campos;
	s16 layer2t;
	u32 alpha;
	s32 i;
	bool drawn = false;

	const s32 gasrooms[] = {
		0x92,
		0x93,
		0x94,
		0x95,
		0x96,
		0x97,
		0x98,
		0x99,
		0x9a,
		0x91,
		0x8f,
		0x90,
	};

	if (g_Vars.stagenum == STAGE_ESCAPE) {
		f32 intensityfrac = 1.0f;

		campos.x = g_Vars.currentplayer->cam_pos.x;
		campos.y = g_Vars.currentplayer->cam_pos.y;
		campos.z = g_Vars.currentplayer->cam_pos.z;

		for (i = 0; i < 12; i++) {
			if (roomContainsCoord(&campos, gasrooms[i])) {
				show = true;
			}
		}

		if (!show) {
			// Outside of the gas rooms list - check distance to abitrary point
			f32 distance = sqrtf(
					(campos.f[0] - -1473.0f) * (campos.f[0] - -1473.0f) +
					(campos.f[1] - -308.0f) * (campos.f[1] - -308.0f) +
					(campos.f[2] - -13660.0f) * (campos.f[2] - -13660.0f));

			if (distance < 1328.0f) {
				show = true;
				alphafrac = 1.0f - distance / 1328.0f;
				intensityfrac = gasGetDoorFrac(0x32);
			}
		} else {
			if (roomContainsCoord(&campos, 0x91)) {
				// In the small room between the first two doors
				f32 frac1 = gasGetDoorFrac(0x30);
				f32 frac2 = gasGetDoorFrac(0x31);

				if (frac2 > frac1) {
					intensityfrac = frac2;
				} else {
					intensityfrac = frac1;
				}

				intensityfrac += 0.2f;
			}
		}

		alphafrac *= intensityfrac;

		if (show && g_Vars.tickmode == TICKMODE_CUTSCENE) {
			if (g_CutsceneCurAnimFrame60 < 2180) {
				show = false;
			} else if (g_CutsceneCurAnimFrame60 < 2600) {
				f32 tmp = (g_CutsceneCurAnimFrame60 - 2180) / 420.0f;
				alphafrac *= tmp;
			}
		}

		if (show) {
			u32 *colours = gfxAllocateColours(1);
			struct gfxvtx *vertices = gfxAllocateVertices(8);
			s16 viewleft = viGetViewLeft() * 10;
			s16 viewtop = viGetViewTop() * 10;
			s16 viewright = (s16) (viGetViewLeft() + viGetViewWidth()) * 10;
			s16 viewbottom = (s16) (viGetViewTop() + viGetViewHeight()) * 10;
			f32 lookx = g_Vars.currentplayer->cam_look.x;
			f32 lookz = g_Vars.currentplayer->cam_look.z;
			f32 camposx = g_Vars.currentplayer->cam_pos.x;
			f32 camposz = g_Vars.currentplayer->cam_pos.z;
			f32 f2;
			f32 f16;
			s32 stack;
			f32 sp78;
			s16 layer2s;
			s16 layer1s;
			s16 layer1t;

			f2 = (camposx + camposz) / 3000.0f;
			f16 = (f2 - (s32) f2);

			sp78 = atan2f(-lookx, lookz) / M_BADTAU;

			layer2s = ((s32) (2.0f * ((menuGetSinOscFrac(4.0f) - 0.5f) / 6.0f + sp78 + f16 * 1.5f) * 128.0f * 32.0f) % 2048);
			layer1s = ((s32) (2.0f * ((menuGetCosOscFrac(4.0f) - 0.5f) / -9.0f + sp78 + f16) * 128.0f * 32.0f) % 2048);

			layer2t = (s16) ((s32) (campos.y * 8.0f) % 2048) + (s16) (2.0f * g_20SecIntervalFrac * 128.0f * 32.0f);
			layer1t = (s16) ((s32) (campos.y * 8.0f) % 2048) + (s16) (2.0f * g_20SecIntervalFrac * 64.0f * 32.0f);

			drawn = true;

			gdl = func0f0d479c(gdl);

			if (1);

			texSelect(&gdl, &g_TexGeneralConfigs[6], 4, 1, 2, true, NULL);

			gDPPipeSync(gdl++);
			gDPSetCycleType(gdl++, G_CYC_1CYCLE);
			gDPSetAlphaCompare(gdl++, G_AC_NONE);
			gDPSetCombineMode(gdl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
			gSPClearGeometryMode(gdl++, G_CULL_BOTH);
			gDPSetColorDither(gdl++, G_CD_DISABLE);
			gDPSetTextureFilter(gdl++, G_TF_BILERP);
			gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
			gDPSetTexturePersp(gdl++, G_TP_PERSP);

			vertices[0].x = viewleft;
			vertices[0].y = viewtop;
			vertices[0].z = -10;

			vertices[1].x = viewright;
			vertices[1].y = viewtop;
			vertices[1].z = -10;

			vertices[2].x = viewright;
			vertices[2].y = viewbottom;
			vertices[2].z = -10;

			vertices[3].x = viewleft;
			vertices[3].y = viewbottom;
			vertices[3].z = -10;

			vertices[4].x = viewleft;
			vertices[4].y = viewtop;
			vertices[4].z = -10;

			vertices[5].x = viewright;
			vertices[5].y = viewtop;
			vertices[5].z = -10;

			vertices[6].x = viewright;
			vertices[6].y = viewbottom;
			vertices[6].z = -10;

			vertices[7].x = viewleft;
			vertices[7].y = viewbottom;
			vertices[7].z = -10;

			vertices[0].s = layer1s;
			vertices[0].t = layer1t;
			vertices[1].s = layer1s + 960;
			vertices[1].t = layer1t;
			vertices[2].s = layer1s + 960;
			vertices[2].t = layer1t + 640;
			vertices[3].s = layer1s;
			vertices[3].t = layer1t + 640;

			vertices[0].colour = 0;
			vertices[1].colour = 0;
			vertices[2].colour = 0;
			vertices[3].colour = 0;

			vertices[4].s = layer2s;
			vertices[4].t = layer2t;
			vertices[5].s = layer2s + 640;
			vertices[5].t = layer2t;
			vertices[6].s = layer2s + 640;
			vertices[6].t = layer2t + 480;
			vertices[7].s = layer2s;
			vertices[7].t = layer2t + 480;

			vertices[4].colour = 0;
			vertices[5].colour = 0;
			vertices[6].colour = 0;
			vertices[7].colour = 0;

			alpha = 127.0f * alphafrac;

			colours[0] = 0x3faf1100 | alpha;

			gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 1);
			gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 8);

			gDPTri4(gdl++, 0, 1, 2, 2, 3, 0, 4, 5, 6, 6, 7, 4);
		}
	}

	if (drawn) {
		gdl = func0f0d49c8(gdl);
	}

	return gdl;
}
