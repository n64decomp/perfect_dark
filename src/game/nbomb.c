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
	vertices[i].colour = 0; \
\
	var80061648 = 1 - var80061648; \
\
	if (var8009cb04 && vertices[i].t == 0) { \
		vertices[i].t = var80061648 * 0 + 256 * 32; \
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

	var8009cb00 = 2048.0f * var80061630;
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

u32 var80061694 = 0x00000000;
u32 var80061698 = 0x00000000;
u32 var8006169c = 0x3f800000;
u32 var800616a0 = 0x3f800000;
u32 var800616a4 = 0x00000000;
u32 var800616a8 = 0x00000000;
u32 var800616ac = 0x00000000;
u32 var800616b0 = 0x00000000;
u32 var800616b4 = 0xbf800000;
u32 var800616b8 = 0xbf800000;
u32 var800616bc = 0x00000000;
u32 var800616c0 = 0x00000000;
u32 var800616c4 = 0x00000000;
u32 var800616c8 = 0x3f800000;
u32 var800616cc = 0x00000000;
u32 var800616d0 = 0x00000000;
u32 var800616d4 = 0xbf800000;
u32 var800616d8 = 0x00000000;

GLOBAL_ASM(
glabel func0f008558
.late_rodata
glabel var7f1a7eec
.word 0x40c90fdb
glabel var7f1a7ef0
.word 0x40c90fdb
glabel var7f1a7ef4
.word 0x40c90fdb
glabel var7f1a7ef8
.word 0x40c90fdb
glabel var7f1a7efc
.word 0x40c90fdb
glabel var7f1a7f00
.word 0x40c90fdb
glabel var7f1a7f04
.word 0x40c90fdb
glabel var7f1a7f08
.word 0x40c90fdb
glabel var7f1a7f0c
.word 0x40c90fdb
glabel var7f1a7f10
.word 0x40c90fdb
glabel var7f1a7f14
.word 0x40c90fdb
glabel var7f1a7f18
.word 0x40c90fdb
.text
/*  f008558:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f00855c:	afb10044 */ 	sw	$s1,0x44($sp)
/*  f008560:	3c0f8006 */ 	lui	$t7,%hi(var80061694)
/*  f008564:	3c118006 */ 	lui	$s1,%hi(var80061648)
/*  f008568:	25ef1694 */ 	addiu	$t7,$t7,%lo(var80061694)
/*  f00856c:	26311648 */ 	addiu	$s1,$s1,%lo(var80061648)
/*  f008570:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f008574:	afb20048 */ 	sw	$s2,0x48($sp)
/*  f008578:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f00857c:	f7b60038 */ 	sdc1	$f22,0x38($sp)
/*  f008580:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f008584:	afa400a8 */ 	sw	$a0,0xa8($sp)
/*  f008588:	afa500ac */ 	sw	$a1,0xac($sp)
/*  f00858c:	25e90048 */ 	addiu	$t1,$t7,0x48
/*  f008590:	27ae005c */ 	addiu	$t6,$sp,0x5c
.L0f008594:
/*  f008594:	8de10000 */ 	lw	$at,0x0($t7)
/*  f008598:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f00859c:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f0085a0:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f0085a4:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f0085a8:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f0085ac:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f0085b0:	15e9fff8 */ 	bne	$t7,$t1,.L0f008594
/*  f0085b4:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f0085b8:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f0085bc:	3c01800a */ 	lui	$at,%hi(var8009cb04)
/*  f0085c0:	ac20cb04 */ 	sw	$zero,%lo(var8009cb04)($at)
/*  f0085c4:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f0085c8:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f0085cc:	3c128006 */ 	lui	$s2,%hi(var80061644)
/*  f0085d0:	26521644 */ 	addiu	$s2,$s2,%lo(var80061644)
/*  f0085d4:	c6460000 */ 	lwc1	$f6,0x0($s2)
/*  f0085d8:	c7a4005c */ 	lwc1	$f4,0x5c($sp)
/*  f0085dc:	3c014380 */ 	lui	$at,0x4380
/*  f0085e0:	4481a000 */ 	mtc1	$at,$f20
/*  f0085e4:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0085e8:	3c014200 */ 	lui	$at,0x4200
/*  f0085ec:	4481b000 */ 	mtc1	$at,$f22
/*  f0085f0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0085f4:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0085f8:	440b5000 */ 	mfc1	$t3,$f10
/*  f0085fc:	00000000 */ 	nop
/*  f008600:	a44b0000 */ 	sh	$t3,0x0($v0)
/*  f008604:	c7b00060 */ 	lwc1	$f16,0x60($sp)
/*  f008608:	c6520000 */ 	lwc1	$f18,0x0($s2)
/*  f00860c:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f008610:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f008614:	440d3000 */ 	mfc1	$t5,$f6
/*  f008618:	00000000 */ 	nop
/*  f00861c:	a44d0002 */ 	sh	$t5,0x2($v0)
/*  f008620:	c7a80064 */ 	lwc1	$f8,0x64($sp)
/*  f008624:	c64a0000 */ 	lwc1	$f10,0x0($s2)
/*  f008628:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f00862c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f008630:	44189000 */ 	mfc1	$t8,$f18
/*  f008634:	00000000 */ 	nop
/*  f008638:	a4580004 */ 	sh	$t8,0x4($v0)
/*  f00863c:	c7a40060 */ 	lwc1	$f4,0x60($sp)
/*  f008640:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f008644:	00000000 */ 	nop
/*  f008648:	46163202 */ 	mul.s	$f8,$f6,$f22
/*  f00864c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f008650:	440f5000 */ 	mfc1	$t7,$f10
/*  f008654:	00000000 */ 	nop
/*  f008658:	a44f0008 */ 	sh	$t7,0x8($v0)
/*  f00865c:	c7ae0064 */ 	lwc1	$f14,0x64($sp)
/*  f008660:	0fc259d4 */ 	jal	atan2f
/*  f008664:	c7ac005c */ 	lwc1	$f12,0x5c($sp)
/*  f008668:	3c017f1a */ 	lui	$at,%hi(var7f1a7eec)
/*  f00866c:	c4307eec */ 	lwc1	$f16,%lo(var7f1a7eec)($at)
/*  f008670:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f008674:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f008678:	46100483 */ 	div.s	$f18,$f0,$f16
/*  f00867c:	3c19800a */ 	lui	$t9,%hi(var8009cb04)
/*  f008680:	3c0e800a */ 	lui	$t6,%hi(var8009cb00)
/*  f008684:	46149102 */ 	mul.s	$f4,$f18,$f20
/*  f008688:	00000000 */ 	nop
/*  f00868c:	46162182 */ 	mul.s	$f6,$f4,$f22
/*  f008690:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f008694:	440a4000 */ 	mfc1	$t2,$f8
/*  f008698:	00000000 */ 	nop
/*  f00869c:	a60a000a */ 	sh	$t2,0xa($s0)
/*  f0086a0:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f0086a4:	018b6823 */ 	subu	$t5,$t4,$t3
/*  f0086a8:	ae2d0000 */ 	sw	$t5,0x0($s1)
/*  f0086ac:	8f39cb04 */ 	lw	$t9,%lo(var8009cb04)($t9)
/*  f0086b0:	13200006 */ 	beqz	$t9,.L0f0086cc
/*  f0086b4:	00000000 */ 	nop
/*  f0086b8:	8618000a */ 	lh	$t8,0xa($s0)
/*  f0086bc:	24092000 */ 	addiu	$t1,$zero,0x2000
/*  f0086c0:	57000003 */ 	bnezl	$t8,.L0f0086d0
/*  f0086c4:	860f000a */ 	lh	$t7,0xa($s0)
/*  f0086c8:	a609000a */ 	sh	$t1,0xa($s0)
.L0f0086cc:
/*  f0086cc:	860f000a */ 	lh	$t7,0xa($s0)
.L0f0086d0:
/*  f0086d0:	85cecb00 */ 	lh	$t6,%lo(var8009cb00)($t6)
/*  f0086d4:	01ee5021 */ 	addu	$t2,$t7,$t6
/*  f0086d8:	a60a000a */ 	sh	$t2,0xa($s0)
/*  f0086dc:	c7aa0068 */ 	lwc1	$f10,0x68($sp)
/*  f0086e0:	c6500000 */ 	lwc1	$f16,0x0($s2)
/*  f0086e4:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0086e8:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0086ec:	440b2000 */ 	mfc1	$t3,$f4
/*  f0086f0:	00000000 */ 	nop
/*  f0086f4:	a60b000c */ 	sh	$t3,0xc($s0)
/*  f0086f8:	c7a6006c */ 	lwc1	$f6,0x6c($sp)
/*  f0086fc:	c6480000 */ 	lwc1	$f8,0x0($s2)
/*  f008700:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f008704:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f008708:	44198000 */ 	mfc1	$t9,$f16
/*  f00870c:	00000000 */ 	nop
/*  f008710:	a619000e */ 	sh	$t9,0xe($s0)
/*  f008714:	c7b20070 */ 	lwc1	$f18,0x70($sp)
/*  f008718:	c6440000 */ 	lwc1	$f4,0x0($s2)
/*  f00871c:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f008720:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f008724:	44094000 */ 	mfc1	$t1,$f8
/*  f008728:	00000000 */ 	nop
/*  f00872c:	a6090010 */ 	sh	$t1,0x10($s0)
/*  f008730:	c7aa006c */ 	lwc1	$f10,0x6c($sp)
/*  f008734:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f008738:	00000000 */ 	nop
/*  f00873c:	46168482 */ 	mul.s	$f18,$f16,$f22
/*  f008740:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f008744:	440e2000 */ 	mfc1	$t6,$f4
/*  f008748:	00000000 */ 	nop
/*  f00874c:	a60e0014 */ 	sh	$t6,0x14($s0)
/*  f008750:	c7ae0070 */ 	lwc1	$f14,0x70($sp)
/*  f008754:	0fc259d4 */ 	jal	atan2f
/*  f008758:	c7ac0068 */ 	lwc1	$f12,0x68($sp)
/*  f00875c:	3c017f1a */ 	lui	$at,%hi(var7f1a7ef0)
/*  f008760:	c4267ef0 */ 	lwc1	$f6,%lo(var7f1a7ef0)($at)
/*  f008764:	a2000013 */ 	sb	$zero,0x13($s0)
/*  f008768:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f00876c:	46060203 */ 	div.s	$f8,$f0,$f6
/*  f008770:	3c18800a */ 	lui	$t8,%hi(var8009cb04)
/*  f008774:	3c0a800a */ 	lui	$t2,%hi(var8009cb00)
/*  f008778:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f00877c:	00000000 */ 	nop
/*  f008780:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f008784:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f008788:	440c9000 */ 	mfc1	$t4,$f18
/*  f00878c:	00000000 */ 	nop
/*  f008790:	a60c0016 */ 	sh	$t4,0x16($s0)
/*  f008794:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f008798:	01abc823 */ 	subu	$t9,$t5,$t3
/*  f00879c:	ae390000 */ 	sw	$t9,0x0($s1)
/*  f0087a0:	8f18cb04 */ 	lw	$t8,%lo(var8009cb04)($t8)
/*  f0087a4:	13000006 */ 	beqz	$t8,.L0f0087c0
/*  f0087a8:	00000000 */ 	nop
/*  f0087ac:	86090016 */ 	lh	$t1,0x16($s0)
/*  f0087b0:	240f2000 */ 	addiu	$t7,$zero,0x2000
/*  f0087b4:	55200003 */ 	bnezl	$t1,.L0f0087c4
/*  f0087b8:	860e0016 */ 	lh	$t6,0x16($s0)
/*  f0087bc:	a60f0016 */ 	sh	$t7,0x16($s0)
.L0f0087c0:
/*  f0087c0:	860e0016 */ 	lh	$t6,0x16($s0)
.L0f0087c4:
/*  f0087c4:	854acb00 */ 	lh	$t2,%lo(var8009cb00)($t2)
/*  f0087c8:	01ca6021 */ 	addu	$t4,$t6,$t2
/*  f0087cc:	a60c0016 */ 	sh	$t4,0x16($s0)
/*  f0087d0:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f0087d4:	c6460000 */ 	lwc1	$f6,0x0($s2)
/*  f0087d8:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0087dc:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0087e0:	440b5000 */ 	mfc1	$t3,$f10
/*  f0087e4:	00000000 */ 	nop
/*  f0087e8:	a60b0018 */ 	sh	$t3,0x18($s0)
/*  f0087ec:	c7b00078 */ 	lwc1	$f16,0x78($sp)
/*  f0087f0:	c6520000 */ 	lwc1	$f18,0x0($s2)
/*  f0087f4:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0087f8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0087fc:	44183000 */ 	mfc1	$t8,$f6
/*  f008800:	00000000 */ 	nop
/*  f008804:	a618001a */ 	sh	$t8,0x1a($s0)
/*  f008808:	c7a8007c */ 	lwc1	$f8,0x7c($sp)
/*  f00880c:	c64a0000 */ 	lwc1	$f10,0x0($s2)
/*  f008810:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f008814:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f008818:	440f9000 */ 	mfc1	$t7,$f18
/*  f00881c:	00000000 */ 	nop
/*  f008820:	a60f001c */ 	sh	$t7,0x1c($s0)
/*  f008824:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f008828:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f00882c:	00000000 */ 	nop
/*  f008830:	46163202 */ 	mul.s	$f8,$f6,$f22
/*  f008834:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f008838:	440a5000 */ 	mfc1	$t2,$f10
/*  f00883c:	00000000 */ 	nop
/*  f008840:	a60a0020 */ 	sh	$t2,0x20($s0)
/*  f008844:	c7ae007c */ 	lwc1	$f14,0x7c($sp)
/*  f008848:	0fc259d4 */ 	jal	atan2f
/*  f00884c:	c7ac0074 */ 	lwc1	$f12,0x74($sp)
/*  f008850:	3c017f1a */ 	lui	$at,%hi(var7f1a7ef4)
/*  f008854:	c4307ef4 */ 	lwc1	$f16,%lo(var7f1a7ef4)($at)
/*  f008858:	a200001f */ 	sb	$zero,0x1f($s0)
/*  f00885c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f008860:	46100483 */ 	div.s	$f18,$f0,$f16
/*  f008864:	3c09800a */ 	lui	$t1,%hi(var8009cb04)
/*  f008868:	3c0c800a */ 	lui	$t4,%hi(var8009cb00)
/*  f00886c:	46149102 */ 	mul.s	$f4,$f18,$f20
/*  f008870:	00000000 */ 	nop
/*  f008874:	46162182 */ 	mul.s	$f6,$f4,$f22
/*  f008878:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f00887c:	440d4000 */ 	mfc1	$t5,$f8
/*  f008880:	00000000 */ 	nop
/*  f008884:	a60d0022 */ 	sh	$t5,0x22($s0)
/*  f008888:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f00888c:	032bc023 */ 	subu	$t8,$t9,$t3
/*  f008890:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f008894:	8d29cb04 */ 	lw	$t1,%lo(var8009cb04)($t1)
/*  f008898:	11200006 */ 	beqz	$t1,.L0f0088b4
/*  f00889c:	00000000 */ 	nop
/*  f0088a0:	860f0022 */ 	lh	$t7,0x22($s0)
/*  f0088a4:	240e2000 */ 	addiu	$t6,$zero,0x2000
/*  f0088a8:	55e00003 */ 	bnezl	$t7,.L0f0088b8
/*  f0088ac:	860a0022 */ 	lh	$t2,0x22($s0)
/*  f0088b0:	a60e0022 */ 	sh	$t6,0x22($s0)
.L0f0088b4:
/*  f0088b4:	860a0022 */ 	lh	$t2,0x22($s0)
.L0f0088b8:
/*  f0088b8:	858ccb00 */ 	lh	$t4,%lo(var8009cb00)($t4)
/*  f0088bc:	014c6821 */ 	addu	$t5,$t2,$t4
/*  f0088c0:	a60d0022 */ 	sh	$t5,0x22($s0)
/*  f0088c4:	c7aa0080 */ 	lwc1	$f10,0x80($sp)
/*  f0088c8:	c6500000 */ 	lwc1	$f16,0x0($s2)
/*  f0088cc:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0088d0:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0088d4:	440b2000 */ 	mfc1	$t3,$f4
/*  f0088d8:	00000000 */ 	nop
/*  f0088dc:	a60b0024 */ 	sh	$t3,0x24($s0)
/*  f0088e0:	c7a60084 */ 	lwc1	$f6,0x84($sp)
/*  f0088e4:	c6480000 */ 	lwc1	$f8,0x0($s2)
/*  f0088e8:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0088ec:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0088f0:	44098000 */ 	mfc1	$t1,$f16
/*  f0088f4:	00000000 */ 	nop
/*  f0088f8:	a6090026 */ 	sh	$t1,0x26($s0)
/*  f0088fc:	c7b20088 */ 	lwc1	$f18,0x88($sp)
/*  f008900:	c6440000 */ 	lwc1	$f4,0x0($s2)
/*  f008904:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f008908:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f00890c:	440e4000 */ 	mfc1	$t6,$f8
/*  f008910:	00000000 */ 	nop
/*  f008914:	a60e0028 */ 	sh	$t6,0x28($s0)
/*  f008918:	c7aa0084 */ 	lwc1	$f10,0x84($sp)
/*  f00891c:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f008920:	00000000 */ 	nop
/*  f008924:	46168482 */ 	mul.s	$f18,$f16,$f22
/*  f008928:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f00892c:	440c2000 */ 	mfc1	$t4,$f4
/*  f008930:	00000000 */ 	nop
/*  f008934:	a60c002c */ 	sh	$t4,0x2c($s0)
/*  f008938:	c7ae0088 */ 	lwc1	$f14,0x88($sp)
/*  f00893c:	0fc259d4 */ 	jal	atan2f
/*  f008940:	c7ac0080 */ 	lwc1	$f12,0x80($sp)
/*  f008944:	3c017f1a */ 	lui	$at,%hi(var7f1a7ef8)
/*  f008948:	c4267ef8 */ 	lwc1	$f6,%lo(var7f1a7ef8)($at)
/*  f00894c:	a200002b */ 	sb	$zero,0x2b($s0)
/*  f008950:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f008954:	46060203 */ 	div.s	$f8,$f0,$f6
/*  f008958:	3c0f800a */ 	lui	$t7,%hi(var8009cb04)
/*  f00895c:	3c0d800a */ 	lui	$t5,%hi(var8009cb00)
/*  f008960:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f008964:	00000000 */ 	nop
/*  f008968:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f00896c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f008970:	44199000 */ 	mfc1	$t9,$f18
/*  f008974:	00000000 */ 	nop
/*  f008978:	a619002e */ 	sh	$t9,0x2e($s0)
/*  f00897c:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f008980:	030b4823 */ 	subu	$t1,$t8,$t3
/*  f008984:	ae290000 */ 	sw	$t1,0x0($s1)
/*  f008988:	8defcb04 */ 	lw	$t7,%lo(var8009cb04)($t7)
/*  f00898c:	11e00006 */ 	beqz	$t7,.L0f0089a8
/*  f008990:	00000000 */ 	nop
/*  f008994:	860e002e */ 	lh	$t6,0x2e($s0)
/*  f008998:	240a2000 */ 	addiu	$t2,$zero,0x2000
/*  f00899c:	55c00003 */ 	bnezl	$t6,.L0f0089ac
/*  f0089a0:	860c002e */ 	lh	$t4,0x2e($s0)
/*  f0089a4:	a60a002e */ 	sh	$t2,0x2e($s0)
.L0f0089a8:
/*  f0089a8:	860c002e */ 	lh	$t4,0x2e($s0)
.L0f0089ac:
/*  f0089ac:	85adcb00 */ 	lh	$t5,%lo(var8009cb00)($t5)
/*  f0089b0:	018dc821 */ 	addu	$t9,$t4,$t5
/*  f0089b4:	a619002e */ 	sh	$t9,0x2e($s0)
/*  f0089b8:	c7a4008c */ 	lwc1	$f4,0x8c($sp)
/*  f0089bc:	c6460000 */ 	lwc1	$f6,0x0($s2)
/*  f0089c0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0089c4:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0089c8:	440b5000 */ 	mfc1	$t3,$f10
/*  f0089cc:	00000000 */ 	nop
/*  f0089d0:	a60b0030 */ 	sh	$t3,0x30($s0)
/*  f0089d4:	c7b00090 */ 	lwc1	$f16,0x90($sp)
/*  f0089d8:	c6520000 */ 	lwc1	$f18,0x0($s2)
/*  f0089dc:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0089e0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0089e4:	440f3000 */ 	mfc1	$t7,$f6
/*  f0089e8:	00000000 */ 	nop
/*  f0089ec:	a60f0032 */ 	sh	$t7,0x32($s0)
/*  f0089f0:	c7a80094 */ 	lwc1	$f8,0x94($sp)
/*  f0089f4:	c64a0000 */ 	lwc1	$f10,0x0($s2)
/*  f0089f8:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0089fc:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f008a00:	440a9000 */ 	mfc1	$t2,$f18
/*  f008a04:	00000000 */ 	nop
/*  f008a08:	a60a0034 */ 	sh	$t2,0x34($s0)
/*  f008a0c:	c7a40090 */ 	lwc1	$f4,0x90($sp)
/*  f008a10:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f008a14:	00000000 */ 	nop
/*  f008a18:	46163202 */ 	mul.s	$f8,$f6,$f22
/*  f008a1c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f008a20:	440d5000 */ 	mfc1	$t5,$f10
/*  f008a24:	00000000 */ 	nop
/*  f008a28:	a60d0038 */ 	sh	$t5,0x38($s0)
/*  f008a2c:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f008a30:	0fc259d4 */ 	jal	atan2f
/*  f008a34:	c7ac008c */ 	lwc1	$f12,0x8c($sp)
/*  f008a38:	3c017f1a */ 	lui	$at,%hi(var7f1a7efc)
/*  f008a3c:	c4307efc */ 	lwc1	$f16,%lo(var7f1a7efc)($at)
/*  f008a40:	a2000037 */ 	sb	$zero,0x37($s0)
/*  f008a44:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f008a48:	46100483 */ 	div.s	$f18,$f0,$f16
/*  f008a4c:	3c0e800a */ 	lui	$t6,%hi(var8009cb04)
/*  f008a50:	3c19800a */ 	lui	$t9,%hi(var8009cb00)
/*  f008a54:	46149102 */ 	mul.s	$f4,$f18,$f20
/*  f008a58:	00000000 */ 	nop
/*  f008a5c:	46162182 */ 	mul.s	$f6,$f4,$f22
/*  f008a60:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f008a64:	44184000 */ 	mfc1	$t8,$f8
/*  f008a68:	00000000 */ 	nop
/*  f008a6c:	a618003a */ 	sh	$t8,0x3a($s0)
/*  f008a70:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f008a74:	012b7823 */ 	subu	$t7,$t1,$t3
/*  f008a78:	ae2f0000 */ 	sw	$t7,0x0($s1)
/*  f008a7c:	8dcecb04 */ 	lw	$t6,%lo(var8009cb04)($t6)
/*  f008a80:	11c00006 */ 	beqz	$t6,.L0f008a9c
/*  f008a84:	00000000 */ 	nop
/*  f008a88:	860a003a */ 	lh	$t2,0x3a($s0)
/*  f008a8c:	240c2000 */ 	addiu	$t4,$zero,0x2000
/*  f008a90:	55400003 */ 	bnezl	$t2,.L0f008aa0
/*  f008a94:	860d003a */ 	lh	$t5,0x3a($s0)
/*  f008a98:	a60c003a */ 	sh	$t4,0x3a($s0)
.L0f008a9c:
/*  f008a9c:	860d003a */ 	lh	$t5,0x3a($s0)
.L0f008aa0:
/*  f008aa0:	8739cb00 */ 	lh	$t9,%lo(var8009cb00)($t9)
/*  f008aa4:	01b9c021 */ 	addu	$t8,$t5,$t9
/*  f008aa8:	a618003a */ 	sh	$t8,0x3a($s0)
/*  f008aac:	c7aa0098 */ 	lwc1	$f10,0x98($sp)
/*  f008ab0:	c6500000 */ 	lwc1	$f16,0x0($s2)
/*  f008ab4:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f008ab8:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f008abc:	440b2000 */ 	mfc1	$t3,$f4
/*  f008ac0:	00000000 */ 	nop
/*  f008ac4:	a60b003c */ 	sh	$t3,0x3c($s0)
/*  f008ac8:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
/*  f008acc:	c6480000 */ 	lwc1	$f8,0x0($s2)
/*  f008ad0:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f008ad4:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f008ad8:	440e8000 */ 	mfc1	$t6,$f16
/*  f008adc:	00000000 */ 	nop
/*  f008ae0:	a60e003e */ 	sh	$t6,0x3e($s0)
/*  f008ae4:	c7b200a0 */ 	lwc1	$f18,0xa0($sp)
/*  f008ae8:	c6440000 */ 	lwc1	$f4,0x0($s2)
/*  f008aec:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f008af0:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f008af4:	440c4000 */ 	mfc1	$t4,$f8
/*  f008af8:	00000000 */ 	nop
/*  f008afc:	a60c0040 */ 	sh	$t4,0x40($s0)
/*  f008b00:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
/*  f008b04:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f008b08:	00000000 */ 	nop
/*  f008b0c:	46168482 */ 	mul.s	$f18,$f16,$f22
/*  f008b10:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f008b14:	44192000 */ 	mfc1	$t9,$f4
/*  f008b18:	00000000 */ 	nop
/*  f008b1c:	a6190044 */ 	sh	$t9,0x44($s0)
/*  f008b20:	c7ae00a0 */ 	lwc1	$f14,0xa0($sp)
/*  f008b24:	0fc259d4 */ 	jal	atan2f
/*  f008b28:	c7ac0098 */ 	lwc1	$f12,0x98($sp)
/*  f008b2c:	3c017f1a */ 	lui	$at,%hi(var7f1a7f00)
/*  f008b30:	c4267f00 */ 	lwc1	$f6,%lo(var7f1a7f00)($at)
/*  f008b34:	a2000043 */ 	sb	$zero,0x43($s0)
/*  f008b38:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f008b3c:	46060203 */ 	div.s	$f8,$f0,$f6
/*  f008b40:	3c0a800a */ 	lui	$t2,%hi(var8009cb04)
/*  f008b44:	3c18800a */ 	lui	$t8,%hi(var8009cb00)
/*  f008b48:	02002025 */ 	or	$a0,$s0,$zero
/*  f008b4c:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f008b50:	00000000 */ 	nop
/*  f008b54:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f008b58:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f008b5c:	44099000 */ 	mfc1	$t1,$f18
/*  f008b60:	00000000 */ 	nop
/*  f008b64:	a6090046 */ 	sh	$t1,0x46($s0)
/*  f008b68:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f008b6c:	01eb7023 */ 	subu	$t6,$t7,$t3
/*  f008b70:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f008b74:	8d4acb04 */ 	lw	$t2,%lo(var8009cb04)($t2)
/*  f008b78:	3c0f0450 */ 	lui	$t7,0x450
/*  f008b7c:	35ef0048 */ 	ori	$t7,$t7,0x48
/*  f008b80:	11400006 */ 	beqz	$t2,.L0f008b9c
/*  f008b84:	00000000 */ 	nop
/*  f008b88:	860c0046 */ 	lh	$t4,0x46($s0)
/*  f008b8c:	240d2000 */ 	addiu	$t5,$zero,0x2000
/*  f008b90:	55800003 */ 	bnezl	$t4,.L0f008ba0
/*  f008b94:	8fa200a8 */ 	lw	$v0,0xa8($sp)
/*  f008b98:	a60d0046 */ 	sh	$t5,0x46($s0)
.L0f008b9c:
/*  f008b9c:	8fa200a8 */ 	lw	$v0,0xa8($sp)
.L0f008ba0:
/*  f008ba0:	86190046 */ 	lh	$t9,0x46($s0)
/*  f008ba4:	8718cb00 */ 	lh	$t8,%lo(var8009cb00)($t8)
/*  f008ba8:	00401825 */ 	or	$v1,$v0,$zero
/*  f008bac:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f008bb0:	03384821 */ 	addu	$t1,$t9,$t8
/*  f008bb4:	a6090046 */ 	sh	$t1,0x46($s0)
/*  f008bb8:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f008bbc:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f008bc0:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f008bc4:	afa200a8 */ 	sw	$v0,0xa8($sp)
/*  f008bc8:	8fa30058 */ 	lw	$v1,0x58($sp)
/*  f008bcc:	27b00068 */ 	addiu	$s0,$sp,0x68
/*  f008bd0:	240b0004 */ 	addiu	$t3,$zero,0x4
/*  f008bd4:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f008bd8:	83a800af */ 	lb	$t0,0xaf($sp)
/*  f008bdc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f008be0:	240a0006 */ 	addiu	$t2,$zero,0x6
/*  f008be4:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f008be8:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f008bec:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f008bf0:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f008bf4:	8fa400a8 */ 	lw	$a0,0xa8($sp)
/*  f008bf8:	02003825 */ 	or	$a3,$s0,$zero
/*  f008bfc:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f008c00:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f008c04:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f008c08:	0fc01b20 */ 	jal	func0f006c80
/*  f008c0c:	afa80050 */ 	sw	$t0,0x50($sp)
/*  f008c10:	8fa90050 */ 	lw	$t1,0x50($sp)
/*  f008c14:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f008c18:	240d0004 */ 	addiu	$t5,$zero,0x4
/*  f008c1c:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f008c20:	24180006 */ 	addiu	$t8,$zero,0x6
/*  f008c24:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f008c28:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f008c2c:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f008c30:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f008c34:	00402025 */ 	or	$a0,$v0,$zero
/*  f008c38:	02002825 */ 	or	$a1,$s0,$zero
/*  f008c3c:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f008c40:	27a70074 */ 	addiu	$a3,$sp,0x74
/*  f008c44:	0fc01b20 */ 	jal	func0f006c80
/*  f008c48:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f008c4c:	8faa0050 */ 	lw	$t2,0x50($sp)
/*  f008c50:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f008c54:	240b0005 */ 	addiu	$t3,$zero,0x5
/*  f008c58:	240e0006 */ 	addiu	$t6,$zero,0x6
/*  f008c5c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f008c60:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f008c64:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f008c68:	00402025 */ 	or	$a0,$v0,$zero
/*  f008c6c:	02002825 */ 	or	$a1,$s0,$zero
/*  f008c70:	27a60098 */ 	addiu	$a2,$sp,0x98
/*  f008c74:	27a7005c */ 	addiu	$a3,$sp,0x5c
/*  f008c78:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f008c7c:	0fc01b20 */ 	jal	func0f006c80
/*  f008c80:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f008c84:	8fa90050 */ 	lw	$t1,0x50($sp)
/*  f008c88:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f008c8c:	240d0005 */ 	addiu	$t5,$zero,0x5
/*  f008c90:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f008c94:	24180006 */ 	addiu	$t8,$zero,0x6
/*  f008c98:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f008c9c:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f008ca0:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f008ca4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f008ca8:	00402025 */ 	or	$a0,$v0,$zero
/*  f008cac:	27a50074 */ 	addiu	$a1,$sp,0x74
/*  f008cb0:	27a60098 */ 	addiu	$a2,$sp,0x98
/*  f008cb4:	02003825 */ 	or	$a3,$s0,$zero
/*  f008cb8:	0fc01b20 */ 	jal	func0f006c80
/*  f008cbc:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f008cc0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f008cc4:	3c01800a */ 	lui	$at,%hi(var8009cb04)
/*  f008cc8:	afa200a8 */ 	sw	$v0,0xa8($sp)
/*  f008ccc:	ac2fcb04 */ 	sw	$t7,%lo(var8009cb04)($at)
/*  f008cd0:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f008cd4:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f008cd8:	c7a4005c */ 	lwc1	$f4,0x5c($sp)
/*  f008cdc:	c6460000 */ 	lwc1	$f6,0x0($s2)
/*  f008ce0:	00408025 */ 	or	$s0,$v0,$zero
/*  f008ce4:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f008ce8:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f008cec:	440e5000 */ 	mfc1	$t6,$f10
/*  f008cf0:	00000000 */ 	nop
/*  f008cf4:	a44e0000 */ 	sh	$t6,0x0($v0)
/*  f008cf8:	c7b00060 */ 	lwc1	$f16,0x60($sp)
/*  f008cfc:	c6520000 */ 	lwc1	$f18,0x0($s2)
/*  f008d00:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f008d04:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f008d08:	440c3000 */ 	mfc1	$t4,$f6
/*  f008d0c:	00000000 */ 	nop
/*  f008d10:	a44c0002 */ 	sh	$t4,0x2($v0)
/*  f008d14:	c7a80064 */ 	lwc1	$f8,0x64($sp)
/*  f008d18:	c64a0000 */ 	lwc1	$f10,0x0($s2)
/*  f008d1c:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f008d20:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f008d24:	44199000 */ 	mfc1	$t9,$f18
/*  f008d28:	00000000 */ 	nop
/*  f008d2c:	a4590004 */ 	sh	$t9,0x4($v0)
/*  f008d30:	c7a40060 */ 	lwc1	$f4,0x60($sp)
/*  f008d34:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f008d38:	00000000 */ 	nop
/*  f008d3c:	46163202 */ 	mul.s	$f8,$f6,$f22
/*  f008d40:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f008d44:	44095000 */ 	mfc1	$t1,$f10
/*  f008d48:	00000000 */ 	nop
/*  f008d4c:	a4490008 */ 	sh	$t1,0x8($v0)
/*  f008d50:	c7ae0064 */ 	lwc1	$f14,0x64($sp)
/*  f008d54:	0fc259d4 */ 	jal	atan2f
/*  f008d58:	c7ac005c */ 	lwc1	$f12,0x5c($sp)
/*  f008d5c:	3c017f1a */ 	lui	$at,%hi(var7f1a7f04)
/*  f008d60:	c4307f04 */ 	lwc1	$f16,%lo(var7f1a7f04)($at)
/*  f008d64:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f008d68:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f008d6c:	46100483 */ 	div.s	$f18,$f0,$f16
/*  f008d70:	3c0d800a */ 	lui	$t5,%hi(var8009cb04)
/*  f008d74:	3c0f800a */ 	lui	$t7,%hi(var8009cb00)
/*  f008d78:	46149102 */ 	mul.s	$f4,$f18,$f20
/*  f008d7c:	00000000 */ 	nop
/*  f008d80:	46162182 */ 	mul.s	$f6,$f4,$f22
/*  f008d84:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f008d88:	440b4000 */ 	mfc1	$t3,$f8
/*  f008d8c:	00000000 */ 	nop
/*  f008d90:	a60b000a */ 	sh	$t3,0xa($s0)
/*  f008d94:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f008d98:	014e6023 */ 	subu	$t4,$t2,$t6
/*  f008d9c:	ae2c0000 */ 	sw	$t4,0x0($s1)
/*  f008da0:	8dadcb04 */ 	lw	$t5,%lo(var8009cb04)($t5)
/*  f008da4:	11a00006 */ 	beqz	$t5,.L0f008dc0
/*  f008da8:	00000000 */ 	nop
/*  f008dac:	8619000a */ 	lh	$t9,0xa($s0)
/*  f008db0:	24182000 */ 	addiu	$t8,$zero,0x2000
/*  f008db4:	57200003 */ 	bnezl	$t9,.L0f008dc4
/*  f008db8:	8609000a */ 	lh	$t1,0xa($s0)
/*  f008dbc:	a618000a */ 	sh	$t8,0xa($s0)
.L0f008dc0:
/*  f008dc0:	8609000a */ 	lh	$t1,0xa($s0)
.L0f008dc4:
/*  f008dc4:	85efcb00 */ 	lh	$t7,%lo(var8009cb00)($t7)
/*  f008dc8:	012f5821 */ 	addu	$t3,$t1,$t7
/*  f008dcc:	a60b000a */ 	sh	$t3,0xa($s0)
/*  f008dd0:	c7aa0068 */ 	lwc1	$f10,0x68($sp)
/*  f008dd4:	c6500000 */ 	lwc1	$f16,0x0($s2)
/*  f008dd8:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f008ddc:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f008de0:	440e2000 */ 	mfc1	$t6,$f4
/*  f008de4:	00000000 */ 	nop
/*  f008de8:	a60e000c */ 	sh	$t6,0xc($s0)
/*  f008dec:	c7a6006c */ 	lwc1	$f6,0x6c($sp)
/*  f008df0:	c6480000 */ 	lwc1	$f8,0x0($s2)
/*  f008df4:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f008df8:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f008dfc:	440d8000 */ 	mfc1	$t5,$f16
/*  f008e00:	00000000 */ 	nop
/*  f008e04:	a60d000e */ 	sh	$t5,0xe($s0)
/*  f008e08:	c7b20070 */ 	lwc1	$f18,0x70($sp)
/*  f008e0c:	c6440000 */ 	lwc1	$f4,0x0($s2)
/*  f008e10:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f008e14:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f008e18:	44184000 */ 	mfc1	$t8,$f8
/*  f008e1c:	00000000 */ 	nop
/*  f008e20:	a6180010 */ 	sh	$t8,0x10($s0)
/*  f008e24:	c7aa006c */ 	lwc1	$f10,0x6c($sp)
/*  f008e28:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f008e2c:	00000000 */ 	nop
/*  f008e30:	46168482 */ 	mul.s	$f18,$f16,$f22
/*  f008e34:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f008e38:	440f2000 */ 	mfc1	$t7,$f4
/*  f008e3c:	00000000 */ 	nop
/*  f008e40:	a60f0014 */ 	sh	$t7,0x14($s0)
/*  f008e44:	c7ae0070 */ 	lwc1	$f14,0x70($sp)
/*  f008e48:	0fc259d4 */ 	jal	atan2f
/*  f008e4c:	c7ac0068 */ 	lwc1	$f12,0x68($sp)
/*  f008e50:	3c017f1a */ 	lui	$at,%hi(var7f1a7f08)
/*  f008e54:	c4267f08 */ 	lwc1	$f6,%lo(var7f1a7f08)($at)
/*  f008e58:	a2000013 */ 	sb	$zero,0x13($s0)
/*  f008e5c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f008e60:	46060203 */ 	div.s	$f8,$f0,$f6
/*  f008e64:	3c19800a */ 	lui	$t9,%hi(var8009cb04)
/*  f008e68:	3c0b800a */ 	lui	$t3,%hi(var8009cb00)
/*  f008e6c:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f008e70:	00000000 */ 	nop
/*  f008e74:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f008e78:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f008e7c:	440a9000 */ 	mfc1	$t2,$f18
/*  f008e80:	00000000 */ 	nop
/*  f008e84:	a60a0016 */ 	sh	$t2,0x16($s0)
/*  f008e88:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f008e8c:	018e6823 */ 	subu	$t5,$t4,$t6
/*  f008e90:	ae2d0000 */ 	sw	$t5,0x0($s1)
/*  f008e94:	8f39cb04 */ 	lw	$t9,%lo(var8009cb04)($t9)
/*  f008e98:	13200006 */ 	beqz	$t9,.L0f008eb4
/*  f008e9c:	00000000 */ 	nop
/*  f008ea0:	86180016 */ 	lh	$t8,0x16($s0)
/*  f008ea4:	24092000 */ 	addiu	$t1,$zero,0x2000
/*  f008ea8:	57000003 */ 	bnezl	$t8,.L0f008eb8
/*  f008eac:	860f0016 */ 	lh	$t7,0x16($s0)
/*  f008eb0:	a6090016 */ 	sh	$t1,0x16($s0)
.L0f008eb4:
/*  f008eb4:	860f0016 */ 	lh	$t7,0x16($s0)
.L0f008eb8:
/*  f008eb8:	856bcb00 */ 	lh	$t3,%lo(var8009cb00)($t3)
/*  f008ebc:	01eb5021 */ 	addu	$t2,$t7,$t3
/*  f008ec0:	a60a0016 */ 	sh	$t2,0x16($s0)
/*  f008ec4:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f008ec8:	c6460000 */ 	lwc1	$f6,0x0($s2)
/*  f008ecc:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f008ed0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f008ed4:	440e5000 */ 	mfc1	$t6,$f10
/*  f008ed8:	00000000 */ 	nop
/*  f008edc:	a60e0018 */ 	sh	$t6,0x18($s0)
/*  f008ee0:	c7b00078 */ 	lwc1	$f16,0x78($sp)
/*  f008ee4:	c6520000 */ 	lwc1	$f18,0x0($s2)
/*  f008ee8:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f008eec:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f008ef0:	44193000 */ 	mfc1	$t9,$f6
/*  f008ef4:	00000000 */ 	nop
/*  f008ef8:	a619001a */ 	sh	$t9,0x1a($s0)
/*  f008efc:	c7a8007c */ 	lwc1	$f8,0x7c($sp)
/*  f008f00:	c64a0000 */ 	lwc1	$f10,0x0($s2)
/*  f008f04:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f008f08:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f008f0c:	44099000 */ 	mfc1	$t1,$f18
/*  f008f10:	00000000 */ 	nop
/*  f008f14:	a609001c */ 	sh	$t1,0x1c($s0)
/*  f008f18:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f008f1c:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f008f20:	00000000 */ 	nop
/*  f008f24:	46163202 */ 	mul.s	$f8,$f6,$f22
/*  f008f28:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f008f2c:	440b5000 */ 	mfc1	$t3,$f10
/*  f008f30:	00000000 */ 	nop
/*  f008f34:	a60b0020 */ 	sh	$t3,0x20($s0)
/*  f008f38:	c7ae007c */ 	lwc1	$f14,0x7c($sp)
/*  f008f3c:	0fc259d4 */ 	jal	atan2f
/*  f008f40:	c7ac0074 */ 	lwc1	$f12,0x74($sp)
/*  f008f44:	3c017f1a */ 	lui	$at,%hi(var7f1a7f0c)
/*  f008f48:	c4307f0c */ 	lwc1	$f16,%lo(var7f1a7f0c)($at)
/*  f008f4c:	a200001f */ 	sb	$zero,0x1f($s0)
/*  f008f50:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f008f54:	46100483 */ 	div.s	$f18,$f0,$f16
/*  f008f58:	3c18800a */ 	lui	$t8,%hi(var8009cb04)
/*  f008f5c:	3c0a800a */ 	lui	$t2,%hi(var8009cb00)
/*  f008f60:	46149102 */ 	mul.s	$f4,$f18,$f20
/*  f008f64:	00000000 */ 	nop
/*  f008f68:	46162182 */ 	mul.s	$f6,$f4,$f22
/*  f008f6c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f008f70:	440c4000 */ 	mfc1	$t4,$f8
/*  f008f74:	00000000 */ 	nop
/*  f008f78:	a60c0022 */ 	sh	$t4,0x22($s0)
/*  f008f7c:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f008f80:	01aec823 */ 	subu	$t9,$t5,$t6
/*  f008f84:	ae390000 */ 	sw	$t9,0x0($s1)
/*  f008f88:	8f18cb04 */ 	lw	$t8,%lo(var8009cb04)($t8)
/*  f008f8c:	13000006 */ 	beqz	$t8,.L0f008fa8
/*  f008f90:	00000000 */ 	nop
/*  f008f94:	86090022 */ 	lh	$t1,0x22($s0)
/*  f008f98:	240f2000 */ 	addiu	$t7,$zero,0x2000
/*  f008f9c:	55200003 */ 	bnezl	$t1,.L0f008fac
/*  f008fa0:	860b0022 */ 	lh	$t3,0x22($s0)
/*  f008fa4:	a60f0022 */ 	sh	$t7,0x22($s0)
.L0f008fa8:
/*  f008fa8:	860b0022 */ 	lh	$t3,0x22($s0)
.L0f008fac:
/*  f008fac:	854acb00 */ 	lh	$t2,%lo(var8009cb00)($t2)
/*  f008fb0:	016a6021 */ 	addu	$t4,$t3,$t2
/*  f008fb4:	a60c0022 */ 	sh	$t4,0x22($s0)
/*  f008fb8:	c7aa0080 */ 	lwc1	$f10,0x80($sp)
/*  f008fbc:	c6500000 */ 	lwc1	$f16,0x0($s2)
/*  f008fc0:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f008fc4:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f008fc8:	440e2000 */ 	mfc1	$t6,$f4
/*  f008fcc:	00000000 */ 	nop
/*  f008fd0:	a60e0024 */ 	sh	$t6,0x24($s0)
/*  f008fd4:	c7a60084 */ 	lwc1	$f6,0x84($sp)
/*  f008fd8:	c6480000 */ 	lwc1	$f8,0x0($s2)
/*  f008fdc:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f008fe0:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f008fe4:	44188000 */ 	mfc1	$t8,$f16
/*  f008fe8:	00000000 */ 	nop
/*  f008fec:	a6180026 */ 	sh	$t8,0x26($s0)
/*  f008ff0:	c7b20088 */ 	lwc1	$f18,0x88($sp)
/*  f008ff4:	c6440000 */ 	lwc1	$f4,0x0($s2)
/*  f008ff8:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f008ffc:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f009000:	440f4000 */ 	mfc1	$t7,$f8
/*  f009004:	00000000 */ 	nop
/*  f009008:	a60f0028 */ 	sh	$t7,0x28($s0)
/*  f00900c:	c7aa0084 */ 	lwc1	$f10,0x84($sp)
/*  f009010:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f009014:	00000000 */ 	nop
/*  f009018:	46168482 */ 	mul.s	$f18,$f16,$f22
/*  f00901c:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f009020:	440a2000 */ 	mfc1	$t2,$f4
/*  f009024:	00000000 */ 	nop
/*  f009028:	a60a002c */ 	sh	$t2,0x2c($s0)
/*  f00902c:	c7ae0088 */ 	lwc1	$f14,0x88($sp)
/*  f009030:	0fc259d4 */ 	jal	atan2f
/*  f009034:	c7ac0080 */ 	lwc1	$f12,0x80($sp)
/*  f009038:	3c017f1a */ 	lui	$at,%hi(var7f1a7f10)
/*  f00903c:	c4267f10 */ 	lwc1	$f6,%lo(var7f1a7f10)($at)
/*  f009040:	a200002b */ 	sb	$zero,0x2b($s0)
/*  f009044:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f009048:	46060203 */ 	div.s	$f8,$f0,$f6
/*  f00904c:	3c09800a */ 	lui	$t1,%hi(var8009cb04)
/*  f009050:	3c0c800a */ 	lui	$t4,%hi(var8009cb00)
/*  f009054:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f009058:	00000000 */ 	nop
/*  f00905c:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f009060:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f009064:	440d9000 */ 	mfc1	$t5,$f18
/*  f009068:	00000000 */ 	nop
/*  f00906c:	a60d002e */ 	sh	$t5,0x2e($s0)
/*  f009070:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f009074:	032ec023 */ 	subu	$t8,$t9,$t6
/*  f009078:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f00907c:	8d29cb04 */ 	lw	$t1,%lo(var8009cb04)($t1)
/*  f009080:	11200006 */ 	beqz	$t1,.L0f00909c
/*  f009084:	00000000 */ 	nop
/*  f009088:	860f002e */ 	lh	$t7,0x2e($s0)
/*  f00908c:	240b2000 */ 	addiu	$t3,$zero,0x2000
/*  f009090:	55e00003 */ 	bnezl	$t7,.L0f0090a0
/*  f009094:	860a002e */ 	lh	$t2,0x2e($s0)
/*  f009098:	a60b002e */ 	sh	$t3,0x2e($s0)
.L0f00909c:
/*  f00909c:	860a002e */ 	lh	$t2,0x2e($s0)
.L0f0090a0:
/*  f0090a0:	858ccb00 */ 	lh	$t4,%lo(var8009cb00)($t4)
/*  f0090a4:	014c6821 */ 	addu	$t5,$t2,$t4
/*  f0090a8:	a60d002e */ 	sh	$t5,0x2e($s0)
/*  f0090ac:	c7a4008c */ 	lwc1	$f4,0x8c($sp)
/*  f0090b0:	c6460000 */ 	lwc1	$f6,0x0($s2)
/*  f0090b4:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0090b8:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0090bc:	440e5000 */ 	mfc1	$t6,$f10
/*  f0090c0:	00000000 */ 	nop
/*  f0090c4:	a60e0030 */ 	sh	$t6,0x30($s0)
/*  f0090c8:	c7b00090 */ 	lwc1	$f16,0x90($sp)
/*  f0090cc:	c6520000 */ 	lwc1	$f18,0x0($s2)
/*  f0090d0:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0090d4:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0090d8:	44093000 */ 	mfc1	$t1,$f6
/*  f0090dc:	00000000 */ 	nop
/*  f0090e0:	a6090032 */ 	sh	$t1,0x32($s0)
/*  f0090e4:	c7a80094 */ 	lwc1	$f8,0x94($sp)
/*  f0090e8:	c64a0000 */ 	lwc1	$f10,0x0($s2)
/*  f0090ec:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0090f0:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0090f4:	440b9000 */ 	mfc1	$t3,$f18
/*  f0090f8:	00000000 */ 	nop
/*  f0090fc:	a60b0034 */ 	sh	$t3,0x34($s0)
/*  f009100:	c7a40090 */ 	lwc1	$f4,0x90($sp)
/*  f009104:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f009108:	00000000 */ 	nop
/*  f00910c:	46163202 */ 	mul.s	$f8,$f6,$f22
/*  f009110:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f009114:	440c5000 */ 	mfc1	$t4,$f10
/*  f009118:	00000000 */ 	nop
/*  f00911c:	a60c0038 */ 	sh	$t4,0x38($s0)
/*  f009120:	c7ae0094 */ 	lwc1	$f14,0x94($sp)
/*  f009124:	0fc259d4 */ 	jal	atan2f
/*  f009128:	c7ac008c */ 	lwc1	$f12,0x8c($sp)
/*  f00912c:	3c017f1a */ 	lui	$at,%hi(var7f1a7f14)
/*  f009130:	c4307f14 */ 	lwc1	$f16,%lo(var7f1a7f14)($at)
/*  f009134:	a2000037 */ 	sb	$zero,0x37($s0)
/*  f009138:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f00913c:	46100483 */ 	div.s	$f18,$f0,$f16
/*  f009140:	3c0f800a */ 	lui	$t7,%hi(var8009cb04)
/*  f009144:	3c0d800a */ 	lui	$t5,%hi(var8009cb00)
/*  f009148:	46149102 */ 	mul.s	$f4,$f18,$f20
/*  f00914c:	00000000 */ 	nop
/*  f009150:	46162182 */ 	mul.s	$f6,$f4,$f22
/*  f009154:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f009158:	44194000 */ 	mfc1	$t9,$f8
/*  f00915c:	00000000 */ 	nop
/*  f009160:	a619003a */ 	sh	$t9,0x3a($s0)
/*  f009164:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f009168:	030e4823 */ 	subu	$t1,$t8,$t6
/*  f00916c:	ae290000 */ 	sw	$t1,0x0($s1)
/*  f009170:	8defcb04 */ 	lw	$t7,%lo(var8009cb04)($t7)
/*  f009174:	11e00006 */ 	beqz	$t7,.L0f009190
/*  f009178:	00000000 */ 	nop
/*  f00917c:	860b003a */ 	lh	$t3,0x3a($s0)
/*  f009180:	240a2000 */ 	addiu	$t2,$zero,0x2000
/*  f009184:	55600003 */ 	bnezl	$t3,.L0f009194
/*  f009188:	860c003a */ 	lh	$t4,0x3a($s0)
/*  f00918c:	a60a003a */ 	sh	$t2,0x3a($s0)
.L0f009190:
/*  f009190:	860c003a */ 	lh	$t4,0x3a($s0)
.L0f009194:
/*  f009194:	85adcb00 */ 	lh	$t5,%lo(var8009cb00)($t5)
/*  f009198:	018dc821 */ 	addu	$t9,$t4,$t5
/*  f00919c:	a619003a */ 	sh	$t9,0x3a($s0)
/*  f0091a0:	c7aa0098 */ 	lwc1	$f10,0x98($sp)
/*  f0091a4:	c6500000 */ 	lwc1	$f16,0x0($s2)
/*  f0091a8:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f0091ac:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0091b0:	440e2000 */ 	mfc1	$t6,$f4
/*  f0091b4:	00000000 */ 	nop
/*  f0091b8:	a60e003c */ 	sh	$t6,0x3c($s0)
/*  f0091bc:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
/*  f0091c0:	c6480000 */ 	lwc1	$f8,0x0($s2)
/*  f0091c4:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0091c8:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0091cc:	440f8000 */ 	mfc1	$t7,$f16
/*  f0091d0:	00000000 */ 	nop
/*  f0091d4:	a60f003e */ 	sh	$t7,0x3e($s0)
/*  f0091d8:	c7b200a0 */ 	lwc1	$f18,0xa0($sp)
/*  f0091dc:	c6440000 */ 	lwc1	$f4,0x0($s2)
/*  f0091e0:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0091e4:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0091e8:	440a4000 */ 	mfc1	$t2,$f8
/*  f0091ec:	00000000 */ 	nop
/*  f0091f0:	a60a0040 */ 	sh	$t2,0x40($s0)
/*  f0091f4:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
/*  f0091f8:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f0091fc:	00000000 */ 	nop
/*  f009200:	46168482 */ 	mul.s	$f18,$f16,$f22
/*  f009204:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f009208:	440d2000 */ 	mfc1	$t5,$f4
/*  f00920c:	00000000 */ 	nop
/*  f009210:	a60d0044 */ 	sh	$t5,0x44($s0)
/*  f009214:	c7ae00a0 */ 	lwc1	$f14,0xa0($sp)
/*  f009218:	0fc259d4 */ 	jal	atan2f
/*  f00921c:	c7ac0098 */ 	lwc1	$f12,0x98($sp)
/*  f009220:	3c017f1a */ 	lui	$at,%hi(var7f1a7f18)
/*  f009224:	c4267f18 */ 	lwc1	$f6,%lo(var7f1a7f18)($at)
/*  f009228:	a2000043 */ 	sb	$zero,0x43($s0)
/*  f00922c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f009230:	46060203 */ 	div.s	$f8,$f0,$f6
/*  f009234:	3c0b800a */ 	lui	$t3,%hi(var8009cb04)
/*  f009238:	3c19800a */ 	lui	$t9,%hi(var8009cb00)
/*  f00923c:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f009240:	00000000 */ 	nop
/*  f009244:	46165402 */ 	mul.s	$f16,$f10,$f22
/*  f009248:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f00924c:	44189000 */ 	mfc1	$t8,$f18
/*  f009250:	00000000 */ 	nop
/*  f009254:	a6180046 */ 	sh	$t8,0x46($s0)
/*  f009258:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f00925c:	012e7823 */ 	subu	$t7,$t1,$t6
/*  f009260:	ae2f0000 */ 	sw	$t7,0x0($s1)
/*  f009264:	8d6bcb04 */ 	lw	$t3,%lo(var8009cb04)($t3)
/*  f009268:	11600006 */ 	beqz	$t3,.L0f009284
/*  f00926c:	00000000 */ 	nop
/*  f009270:	860a0046 */ 	lh	$t2,0x46($s0)
/*  f009274:	240c2000 */ 	addiu	$t4,$zero,0x2000
/*  f009278:	55400003 */ 	bnezl	$t2,.L0f009288
/*  f00927c:	860d0046 */ 	lh	$t5,0x46($s0)
/*  f009280:	a60c0046 */ 	sh	$t4,0x46($s0)
.L0f009284:
/*  f009284:	860d0046 */ 	lh	$t5,0x46($s0)
.L0f009288:
/*  f009288:	8739cb00 */ 	lh	$t9,%lo(var8009cb00)($t9)
/*  f00928c:	3c0f0450 */ 	lui	$t7,0x450
/*  f009290:	35ef0048 */ 	ori	$t7,$t7,0x48
/*  f009294:	01b9c021 */ 	addu	$t8,$t5,$t9
/*  f009298:	a6180046 */ 	sh	$t8,0x46($s0)
/*  f00929c:	8fb100a8 */ 	lw	$s1,0xa8($sp)
/*  f0092a0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0092a4:	262e0008 */ 	addiu	$t6,$s1,0x8
/*  f0092a8:	afae00a8 */ 	sw	$t6,0xa8($sp)
/*  f0092ac:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0092b0:	ae2f0000 */ 	sw	$t7,0x0($s1)
/*  f0092b4:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0092b8:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f0092bc:	27b00080 */ 	addiu	$s0,$sp,0x80
/*  f0092c0:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f0092c4:	240a0004 */ 	addiu	$t2,$zero,0x4
/*  f0092c8:	240c0003 */ 	addiu	$t4,$zero,0x3
/*  f0092cc:	240d0006 */ 	addiu	$t5,$zero,0x6
/*  f0092d0:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0092d4:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0092d8:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0092dc:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0092e0:	02003825 */ 	or	$a3,$s0,$zero
/*  f0092e4:	8fa400a8 */ 	lw	$a0,0xa8($sp)
/*  f0092e8:	27a50074 */ 	addiu	$a1,$sp,0x74
/*  f0092ec:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f0092f0:	0fc01b20 */ 	jal	func0f006c80
/*  f0092f4:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0092f8:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f0092fc:	24180003 */ 	addiu	$t8,$zero,0x3
/*  f009300:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f009304:	240e0006 */ 	addiu	$t6,$zero,0x6
/*  f009308:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f00930c:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f009310:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f009314:	00402025 */ 	or	$a0,$v0,$zero
/*  f009318:	02002825 */ 	or	$a1,$s0,$zero
/*  f00931c:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f009320:	27a7005c */ 	addiu	$a3,$sp,0x5c
/*  f009324:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f009328:	0fc01b20 */ 	jal	func0f006c80
/*  f00932c:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f009330:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f009334:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f009338:	240a0005 */ 	addiu	$t2,$zero,0x5
/*  f00933c:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f009340:	240d0006 */ 	addiu	$t5,$zero,0x6
/*  f009344:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f009348:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f00934c:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f009350:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f009354:	00402025 */ 	or	$a0,$v0,$zero
/*  f009358:	02002825 */ 	or	$a1,$s0,$zero
/*  f00935c:	27a60098 */ 	addiu	$a2,$sp,0x98
/*  f009360:	27a70074 */ 	addiu	$a3,$sp,0x74
/*  f009364:	0fc01b20 */ 	jal	func0f006c80
/*  f009368:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f00936c:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f009370:	24180005 */ 	addiu	$t8,$zero,0x5
/*  f009374:	24090003 */ 	addiu	$t1,$zero,0x3
/*  f009378:	240e0006 */ 	addiu	$t6,$zero,0x6
/*  f00937c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f009380:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f009384:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f009388:	00402025 */ 	or	$a0,$v0,$zero
/*  f00938c:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f009390:	27a60098 */ 	addiu	$a2,$sp,0x98
/*  f009394:	02003825 */ 	or	$a3,$s0,$zero
/*  f009398:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f00939c:	0fc01b20 */ 	jal	func0f006c80
/*  f0093a0:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0093a4:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0093a8:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f0093ac:	d7b60038 */ 	ldc1	$f22,0x38($sp)
/*  f0093b0:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f0093b4:	8fb10044 */ 	lw	$s1,0x44($sp)
/*  f0093b8:	8fb20048 */ 	lw	$s2,0x48($sp)
/*  f0093bc:	03e00008 */ 	jr	$ra
/*  f0093c0:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

// Mismatch: swapped s1/s2 registers (var80061644 and var80061648)
//Gfx *func0f008558(Gfx *gdl, s32 depth)
//{
//	struct gfxvtx *vertices;
//	struct coord sp5c[] = {
//		{ 0,  0,  1  },
//		{ 1,  0,  0  },
//		{ 0,  0,  -1 },
//		{ -1, 0,  0  },
//		{ 0,  1,  0  },
//		{ 0,  -1, 0  },
//	};
//
//	var80061648 = 0;
//
//	// First half
//	var8009cb04 = 0;
//
//	vertices = gfxAllocateVertices(6);
//
//	MAKEVERTEX(0, sp5c[0]);
//	MAKEVERTEX(1, sp5c[1]);
//	MAKEVERTEX(2, sp5c[2]);
//	MAKEVERTEX(3, sp5c[3]);
//	MAKEVERTEX(4, sp5c[4]);
//	MAKEVERTEX(5, sp5c[5]);
//
//	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 6);
//
//	gdl = func0f006c80(gdl, &sp5c[0], &sp5c[4], &sp5c[1], 0, 4, 1, 6, depth);
//	gdl = func0f006c80(gdl, &sp5c[1], &sp5c[4], &sp5c[2], 1, 4, 2, 6, depth);
//	gdl = func0f006c80(gdl, &sp5c[1], &sp5c[5], &sp5c[0], 1, 5, 0, 6, depth);
//	gdl = func0f006c80(gdl, &sp5c[2], &sp5c[5], &sp5c[1], 2, 5, 1, 6, depth);
//
//	// Second half
//	var8009cb04 = 1;
//
//	vertices = gfxAllocateVertices(6);
//
//	MAKEVERTEX(0, sp5c[0]);
//	MAKEVERTEX(1, sp5c[1]);
//	MAKEVERTEX(2, sp5c[2]);
//	MAKEVERTEX(3, sp5c[3]);
//	MAKEVERTEX(4, sp5c[4]);
//	MAKEVERTEX(5, sp5c[5]);
//
//	gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 6);
//
//	gdl = func0f006c80(gdl, &sp5c[2], &sp5c[4], &sp5c[3], 2, 4, 3, 6, depth);
//	gdl = func0f006c80(gdl, &sp5c[3], &sp5c[4], &sp5c[0], 3, 4, 0, 6, depth);
//	gdl = func0f006c80(gdl, &sp5c[3], &sp5c[5], &sp5c[2], 3, 5, 2, 6, depth);
//	gdl = func0f006c80(gdl, &sp5c[0], &sp5c[5], &sp5c[3], 0, 5, 3, 6, depth);
//
//	return gdl;
//}

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

	var8009cb00 = (s32)(var80061630 * 64.0f * 32.0f * 16.0f) % 0x800;

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

// Mismatch: different usage of callee-save registers relating to room loop
//void nbombInflictDamage(struct nbomb *nbomb)
//{
//	s32 index = 0;
//	u32 stack;
//	s16 propnums[256]; // 100
//	struct coord bbmin; // f4
//	struct coord bbmax; // e8
//	s16 roomnums[54]; // 7c
//	s16 *propnumptr;
//	s32 i;
//	u8 sp70[4];
//	u32 stack2;
//
//	sp70[0] = WEAPON_NBOMB;
//	sp70[3] = 0;
//
//	if (g_Vars.lvupdate240 <= 0 || nbomb->age240 > 350) {
//		return;
//	}
//
//	if (g_Rooms);
//
//	// Find rooms which intersect the nbomb dome's bbox
//	bbmin.x = nbomb->pos.f[0] - nbomb->radius;
//	bbmin.y = nbomb->pos.f[1] - nbomb->radius;
//	bbmin.z = nbomb->pos.f[2] - nbomb->radius;
//
//	bbmax.x = nbomb->pos.f[0] + nbomb->radius;
//	bbmax.y = nbomb->pos.f[1] + nbomb->radius;
//	bbmax.z = nbomb->pos.f[2] + nbomb->radius;
//
//	if (g_Vars.roomcount);
//	if (g_Vars.roomcount);
//
//	for (i = 1; i < g_Vars.roomcount; i++) {
//		if (!(bbmax.f[0] < g_Rooms[i].bbmin[0]
//				|| bbmin.f[0] > g_Rooms[i].bbmax[0]
//				|| bbmax.f[1] < g_Rooms[i].bbmin[1]
//				|| bbmin.f[1] > g_Rooms[i].bbmax[1]
//				|| bbmax.f[2] < g_Rooms[i].bbmin[2]
//				|| bbmin.f[2] > g_Rooms[i].bbmax[2])
//				&& index < 52) {
//			roomnums[index] = i;
//			index++;
//			roomAdjustLighting(i, -38, -180);
//		}
//	}
//
//	roomnums[index] = -1;
//
//	// Iterate props in the affected rooms and damage any chrs
//	roomGetProps(roomnums, propnums, 256);
//
//	propnumptr = propnums;
//
//	while (*propnumptr >= 0) {
//		struct prop *prop = &g_Vars.props[*propnumptr];
//
//		if (prop->timetoregen == 0) {
//			if (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER) {
//				f32 xdiff = prop->pos.f[0] - nbomb->pos.f[0];
//				f32 ydiff = prop->pos.f[1] - nbomb->pos.f[1];
//				f32 zdiff = prop->pos.f[2] - nbomb->pos.f[2];
//
//				f32 dist = sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff);
//
//				if (dist < nbomb->radius) {
//					struct chrdata *chr = prop->chr;
//
//					if (chr) {
//						struct coord vector = {0, 0, 0};
//						f32 damage = 0.0099999997764826f * g_Vars.lvupdate240freal;
//
//						chrDamageByMisc(chr, damage, &vector, sp70, nbomb->prop);
//
//						chr->chrflags |= CHRCFLAG_TRIGGERSHOTLIST;
//
//						if (chr->hidden & CHRHFLAG_CLOAKED) {
//							chrUncloak(chr, true);
//						}
//					}
//				}
//			}
//		}
//
//		propnumptr++;
//	}
//}

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
				f32 speed = func0f006b08(20) * 0.02f + 0.4f;

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
	s32 oldest240 = -1;
	s32 index = 0;
	s32 i;

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

#if PAL
GLOBAL_ASM(
glabel nbombRenderOverlay
/*  f00a490:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f00a494:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f00a498:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f00a49c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f00a4a0:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f00a4a4:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f00a4a8:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f00a4ac:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f00a4b0:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f00a4b4:	afa00050 */ 	sw	$zero,0x50($sp)
/*  f00a4b8:	c4441bb0 */ 	lwc1	$f4,0x1bb0($v0)
/*  f00a4bc:	3c10800a */ 	lui	$s0,%hi(g_Nbombs)
/*  f00a4c0:	3c11800a */ 	lui	$s1,%hi(var8009cbf8)
/*  f00a4c4:	e7a40070 */ 	swc1	$f4,0x70($sp)
/*  f00a4c8:	c4461bb4 */ 	lwc1	$f6,0x1bb4($v0)
/*  f00a4cc:	00009025 */ 	or	$s2,$zero,$zero
/*  f00a4d0:	00009825 */ 	or	$s3,$zero,$zero
/*  f00a4d4:	e7a60074 */ 	swc1	$f6,0x74($sp)
/*  f00a4d8:	c4481bb8 */ 	lwc1	$f8,0x1bb8($v0)
/*  f00a4dc:	2631cbf8 */ 	addiu	$s1,$s1,%lo(var8009cbf8)
/*  f00a4e0:	2610cb08 */ 	addiu	$s0,$s0,%lo(g_Nbombs)
/*  f00a4e4:	e7a80078 */ 	swc1	$f8,0x78($sp)
/*  f00a4e8:	8e02000c */ 	lw	$v0,0xc($s0)
.L0f00a4ec:
/*  f00a4ec:	0440001d */ 	bltz	$v0,.L0f00a564
/*  f00a4f0:	2841015f */ 	slti	$at,$v0,0x124
/*  f00a4f4:	1020001b */ 	beqz	$at,.L0f00a564
/*  f00a4f8:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*  f00a4fc:	c6100000 */ 	lwc1	$f16,0x0($s0)
/*  f00a500:	c7b20074 */ 	lwc1	$f18,0x74($sp)
/*  f00a504:	c6040004 */ 	lwc1	$f4,0x4($s0)
/*  f00a508:	46105001 */ 	sub.s	$f0,$f10,$f16
/*  f00a50c:	c7a60078 */ 	lwc1	$f6,0x78($sp)
/*  f00a510:	c6080008 */ 	lwc1	$f8,0x8($s0)
/*  f00a514:	46049081 */ 	sub.s	$f2,$f18,$f4
/*  f00a518:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f00a51c:	46083381 */ 	sub.s	$f14,$f6,$f8
/*  f00a520:	46021402 */ 	mul.s	$f16,$f2,$f2
/*  f00a524:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f00a528:	460e7102 */ 	mul.s	$f4,$f14,$f14
/*  f00a52c:	0c012974 */ 	jal	sqrtf
/*  f00a530:	46049300 */ 	add.s	$f12,$f18,$f4
/*  f00a534:	c6060010 */ 	lwc1	$f6,0x10($s0)
/*  f00a538:	02002025 */ 	or	$a0,$s0,$zero
/*  f00a53c:	4606003c */ 	c.lt.s	$f0,$f6
/*  f00a540:	00000000 */ 	nop
/*  f00a544:	45020008 */ 	bc1fl	.L0f00a568
/*  f00a548:	26100028 */ 	addiu	$s0,$s0,0x28
/*  f00a54c:	0fc0252f */ 	jal	nbombCalculateAlpha
/*  f00a550:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f00a554:	0262082b */ 	sltu	$at,$s3,$v0
/*  f00a558:	50200003 */ 	beqzl	$at,.L0f00a568
/*  f00a55c:	26100028 */ 	addiu	$s0,$s0,0x28
/*  f00a560:	00409825 */ 	or	$s3,$v0,$zero
.L0f00a564:
/*  f00a564:	26100028 */ 	addiu	$s0,$s0,0x28
.L0f00a568:
/*  f00a568:	5611ffe0 */ 	bnel	$s0,$s1,.L0f00a4ec
/*  f00a56c:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f00a570:	524000e6 */ 	beqzl	$s2,.L0f00a90c
/*  f00a574:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f00a578:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f00a57c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f00a580:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f00a584:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f00a588:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f00a58c:	0c002f40 */ 	jal	viGetViewLeft
/*  f00a590:	00408025 */ 	or	$s0,$v0,$zero
/*  f00a594:	00027080 */ 	sll	$t6,$v0,0x2
/*  f00a598:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f00a59c:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f00a5a0:	0c002f44 */ 	jal	viGetViewTop
/*  f00a5a4:	a7ae0042 */ 	sh	$t6,0x42($sp)
/*  f00a5a8:	00027880 */ 	sll	$t7,$v0,0x2
/*  f00a5ac:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f00a5b0:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f00a5b4:	0c002f40 */ 	jal	viGetViewLeft
/*  f00a5b8:	a7af0040 */ 	sh	$t7,0x40($sp)
/*  f00a5bc:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f00a5c0:	0011c403 */ 	sra	$t8,$s1,0x10
/*  f00a5c4:	0c002f22 */ 	jal	viGetViewWidth
/*  f00a5c8:	03008825 */ 	or	$s1,$t8,$zero
/*  f00a5cc:	00515821 */ 	addu	$t3,$v0,$s1
/*  f00a5d0:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f00a5d4:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f00a5d8:	000c6040 */ 	sll	$t4,$t4,0x1
/*  f00a5dc:	0c002f44 */ 	jal	viGetViewTop
/*  f00a5e0:	a7ac003e */ 	sh	$t4,0x3e($sp)
/*  f00a5e4:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f00a5e8:	00116c03 */ 	sra	$t5,$s1,0x10
/*  f00a5ec:	0c002f26 */ 	jal	viGetViewHeight
/*  f00a5f0:	01a08825 */ 	or	$s1,$t5,$zero
/*  f00a5f4:	3c014100 */ 	lui	$at,0x4100
/*  f00a5f8:	44811000 */ 	mtc1	$at,$f2
/*  f00a5fc:	3c014300 */ 	lui	$at,0x4300
/*  f00a600:	44816000 */ 	mtc1	$at,$f12
/*  f00a604:	3c014200 */ 	lui	$at,0x4200
/*  f00a608:	44817000 */ 	mtc1	$at,$f14
/*  f00a60c:	3c018006 */ 	lui	$at,%hi(var80061630)
/*  f00a610:	c4201630 */ 	lwc1	$f0,%lo(var80061630)($at)
/*  f00a614:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f00a618:	00514821 */ 	addu	$t1,$v0,$s1
/*  f00a61c:	46001202 */ 	mul.s	$f8,$f2,$f0
/*  f00a620:	00097400 */ 	sll	$t6,$t1,0x10
/*  f00a624:	000e7c03 */ 	sra	$t7,$t6,0x10
/*  f00a628:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f00a62c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f00a630:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f00a634:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f00a638:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f00a63c:	00195403 */ 	sra	$t2,$t9,0x10
/*  f00a640:	01404825 */ 	or	$t1,$t2,$zero
/*  f00a644:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f00a648:	afaa0050 */ 	sw	$t2,0x50($sp)
/*  f00a64c:	a7a9003c */ 	sh	$t1,0x3c($sp)
/*  f00a650:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f00a654:	460e5402 */ 	mul.s	$f16,$f10,$f14
/*  f00a658:	46000280 */ 	add.s	$f10,$f0,$f0
/*  f00a65c:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f00a660:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f00a664:	460c5402 */ 	mul.s	$f16,$f10,$f12
/*  f00a668:	44129000 */ 	mfc1	$s2,$f18
/*  f00a66c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f00a670:	460e8482 */ 	mul.s	$f18,$f16,$f14
/*  f00a674:	06410004 */ 	bgez	$s2,.L0f00a688
/*  f00a678:	324c07ff */ 	andi	$t4,$s2,0x7ff
/*  f00a67c:	11800002 */ 	beqz	$t4,.L0f00a688
/*  f00a680:	00000000 */ 	nop
/*  f00a684:	258cf800 */ 	addiu	$t4,$t4,-2048
.L0f00a688:
/*  f00a688:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f00a68c:	44184000 */ 	mfc1	$t8,$f8
/*  f00a690:	000c6c00 */ 	sll	$t5,$t4,0x10
/*  f00a694:	000d7403 */ 	sra	$t6,$t5,0x10
/*  f00a698:	440f2000 */ 	mfc1	$t7,$f4
/*  f00a69c:	01c09025 */ 	or	$s2,$t6,$zero
/*  f00a6a0:	07010004 */ 	bgez	$t8,.L0f00a6b4
/*  f00a6a4:	331907ff */ 	andi	$t9,$t8,0x7ff
/*  f00a6a8:	13200002 */ 	beqz	$t9,.L0f00a6b4
/*  f00a6ac:	00000000 */ 	nop
/*  f00a6b0:	2739f800 */ 	addiu	$t9,$t9,-2048
.L0f00a6b4:
/*  f00a6b4:	03205825 */ 	or	$t3,$t9,$zero
/*  f00a6b8:	016fc821 */ 	addu	$t9,$t3,$t7
/*  f00a6bc:	0fc351e7 */ 	jal	func0f0d479c
/*  f00a6c0:	a7b9005e */ 	sh	$t9,0x5e($sp)
/*  f00a6c4:	3c05800b */ 	lui	$a1,%hi(g_TexGeneralConfigs)
/*  f00a6c8:	87a8005e */ 	lh	$t0,0x5e($sp)
/*  f00a6cc:	87a9003c */ 	lh	$t1,0x3c($sp)
/*  f00a6d0:	8ca5b5a8 */ 	lw	$a1,%lo(g_TexGeneralConfigs)($a1)
/*  f00a6d4:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f00a6d8:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f00a6dc:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f00a6e0:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f00a6e4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f00a6e8:	27a40080 */ 	addiu	$a0,$sp,0x80
/*  f00a6ec:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f00a6f0:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f00a6f4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f00a6f8:	a7a8005e */ 	sh	$t0,0x5e($sp)
/*  f00a6fc:	a7a9003c */ 	sh	$t1,0x3c($sp)
/*  f00a700:	0fc2ce70 */ 	jal	texSelect
/*  f00a704:	24a50078 */ 	addiu	$a1,$a1,0x0078
/*  f00a708:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f00a70c:	87a8005e */ 	lh	$t0,0x5e($sp)
/*  f00a710:	87a9003c */ 	lh	$t1,0x3c($sp)
/*  f00a714:	25cb0008 */ 	addiu	$t3,$t6,0x8
/*  f00a718:	afab0080 */ 	sw	$t3,0x80($sp)
/*  f00a71c:	3c0fe700 */ 	lui	$t7,0xe700
/*  f00a720:	adcf0000 */ 	sw	$t7,0x0($t6)
/*  f00a724:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f00a728:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f00a72c:	3c0aba00 */ 	lui	$t2,0xba00
/*  f00a730:	354a1402 */ 	ori	$t2,$t2,0x1402
/*  f00a734:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f00a738:	afb90080 */ 	sw	$t9,0x80($sp)
/*  f00a73c:	af000004 */ 	sw	$zero,0x4($t8)
/*  f00a740:	af0a0000 */ 	sw	$t2,0x0($t8)
/*  f00a744:	8fac0080 */ 	lw	$t4,0x80($sp)
/*  f00a748:	3c0eb900 */ 	lui	$t6,0xb900
/*  f00a74c:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f00a750:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f00a754:	afad0080 */ 	sw	$t5,0x80($sp)
/*  f00a758:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f00a75c:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f00a760:	8fab0080 */ 	lw	$t3,0x80($sp)
/*  f00a764:	3c18fc12 */ 	lui	$t8,0xfc12
/*  f00a768:	3c19ff33 */ 	lui	$t9,0xff33
/*  f00a76c:	256f0008 */ 	addiu	$t7,$t3,0x8
/*  f00a770:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f00a774:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f00a778:	37181824 */ 	ori	$t8,$t8,0x1824
/*  f00a77c:	ad780000 */ 	sw	$t8,0x0($t3)
/*  f00a780:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f00a784:	8faa0080 */ 	lw	$t2,0x80($sp)
/*  f00a788:	240e3000 */ 	addiu	$t6,$zero,0x3000
/*  f00a78c:	3c0db600 */ 	lui	$t5,0xb600
/*  f00a790:	254c0008 */ 	addiu	$t4,$t2,0x8
/*  f00a794:	afac0080 */ 	sw	$t4,0x80($sp)
/*  f00a798:	ad4e0004 */ 	sw	$t6,0x4($t2)
/*  f00a79c:	ad4d0000 */ 	sw	$t5,0x0($t2)
/*  f00a7a0:	8fab0080 */ 	lw	$t3,0x80($sp)
/*  f00a7a4:	87a70040 */ 	lh	$a3,0x40($sp)
/*  f00a7a8:	87a60042 */ 	lh	$a2,0x42($sp)
/*  f00a7ac:	256f0008 */ 	addiu	$t7,$t3,0x8
/*  f00a7b0:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f00a7b4:	3c18ba00 */ 	lui	$t8,0xba00
/*  f00a7b8:	37180602 */ 	ori	$t8,$t8,0x602
/*  f00a7bc:	241900c0 */ 	addiu	$t9,$zero,0xc0
/*  f00a7c0:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f00a7c4:	ad780000 */ 	sw	$t8,0x0($t3)
/*  f00a7c8:	8faa0080 */ 	lw	$t2,0x80($sp)
/*  f00a7cc:	3c0dba00 */ 	lui	$t5,0xba00
/*  f00a7d0:	35ad0c02 */ 	ori	$t5,$t5,0xc02
/*  f00a7d4:	254c0008 */ 	addiu	$t4,$t2,0x8
/*  f00a7d8:	afac0080 */ 	sw	$t4,0x80($sp)
/*  f00a7dc:	240e2000 */ 	addiu	$t6,$zero,0x2000
/*  f00a7e0:	ad4e0004 */ 	sw	$t6,0x4($t2)
/*  f00a7e4:	ad4d0000 */ 	sw	$t5,0x0($t2)
/*  f00a7e8:	8fab0080 */ 	lw	$t3,0x80($sp)
/*  f00a7ec:	3c18b900 */ 	lui	$t8,0xb900
/*  f00a7f0:	3c190050 */ 	lui	$t9,0x50
/*  f00a7f4:	256f0008 */ 	addiu	$t7,$t3,0x8
/*  f00a7f8:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f00a7fc:	37394a50 */ 	ori	$t9,$t9,0x4a50
/*  f00a800:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f00a804:	ad780000 */ 	sw	$t8,0x0($t3)
/*  f00a808:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f00a80c:	8faa0080 */ 	lw	$t2,0x80($sp)
/*  f00a810:	3c0dba00 */ 	lui	$t5,0xba00
/*  f00a814:	35ad1301 */ 	ori	$t5,$t5,0x1301
/*  f00a818:	254c0008 */ 	addiu	$t4,$t2,0x8
/*  f00a81c:	afac0080 */ 	sw	$t4,0x80($sp)
/*  f00a820:	3c0e0008 */ 	lui	$t6,0x8
/*  f00a824:	ad4e0004 */ 	sw	$t6,0x4($t2)
/*  f00a828:	ad4d0000 */ 	sw	$t5,0x0($t2)
/*  f00a82c:	a6070002 */ 	sh	$a3,0x2($s0)
/*  f00a830:	a6060000 */ 	sh	$a2,0x0($s0)
/*  f00a834:	87a3003e */ 	lh	$v1,0x3e($sp)
/*  f00a838:	2402fff6 */ 	addiu	$v0,$zero,-10
/*  f00a83c:	a6020004 */ 	sh	$v0,0x4($s0)
/*  f00a840:	a6020010 */ 	sh	$v0,0x10($s0)
/*  f00a844:	a602001c */ 	sh	$v0,0x1c($s0)
/*  f00a848:	a6020028 */ 	sh	$v0,0x28($s0)
/*  f00a84c:	a6120008 */ 	sh	$s2,0x8($s0)
/*  f00a850:	a608000a */ 	sh	$t0,0xa($s0)
/*  f00a854:	a609001a */ 	sh	$t1,0x1a($s0)
/*  f00a858:	a6090026 */ 	sh	$t1,0x26($s0)
/*  f00a85c:	a607000e */ 	sh	$a3,0xe($s0)
/*  f00a860:	a6060024 */ 	sh	$a2,0x24($s0)
/*  f00a864:	a603000c */ 	sh	$v1,0xc($s0)
/*  f00a868:	a6030018 */ 	sh	$v1,0x18($s0)
/*  f00a86c:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f00a870:	264200a0 */ 	addiu	$v0,$s2,0xa0
/*  f00a874:	250303c0 */ 	addiu	$v1,$t0,0x3c0
/*  f00a878:	a6020014 */ 	sh	$v0,0x14($s0)
/*  f00a87c:	a6020020 */ 	sh	$v0,0x20($s0)
/*  f00a880:	a6030022 */ 	sh	$v1,0x22($s0)
/*  f00a884:	a612002c */ 	sh	$s2,0x2c($s0)
/*  f00a888:	a603002e */ 	sh	$v1,0x2e($s0)
/*  f00a88c:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f00a890:	a2000013 */ 	sb	$zero,0x13($s0)
/*  f00a894:	a200001f */ 	sb	$zero,0x1f($s0)
/*  f00a898:	a200002b */ 	sb	$zero,0x2b($s0)
/*  f00a89c:	a6080016 */ 	sh	$t0,0x16($s0)
/*  f00a8a0:	ac930000 */ 	sw	$s3,0x0($a0)
/*  f00a8a4:	8fb10080 */ 	lw	$s1,0x80($sp)
/*  f00a8a8:	3c180700 */ 	lui	$t8,0x700
/*  f00a8ac:	37180004 */ 	ori	$t8,$t8,0x4
/*  f00a8b0:	262f0008 */ 	addiu	$t7,$s1,0x8
/*  f00a8b4:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f00a8b8:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f00a8bc:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f00a8c0:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f00a8c4:	8fb20080 */ 	lw	$s2,0x80($sp)
/*  f00a8c8:	3c0c0430 */ 	lui	$t4,0x430
/*  f00a8cc:	358c0030 */ 	ori	$t4,$t4,0x30
/*  f00a8d0:	264a0008 */ 	addiu	$t2,$s2,0x8
/*  f00a8d4:	afaa0080 */ 	sw	$t2,0x80($sp)
/*  f00a8d8:	02002025 */ 	or	$a0,$s0,$zero
/*  f00a8dc:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f00a8e0:	ae4c0000 */ 	sw	$t4,0x0($s2)
/*  f00a8e4:	ae420004 */ 	sw	$v0,0x4($s2)
/*  f00a8e8:	8fad0080 */ 	lw	$t5,0x80($sp)
/*  f00a8ec:	3c0bb100 */ 	lui	$t3,0xb100
/*  f00a8f0:	356b0002 */ 	ori	$t3,$t3,0x2
/*  f00a8f4:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f00a8f8:	afae0080 */ 	sw	$t6,0x80($sp)
/*  f00a8fc:	240f3210 */ 	addiu	$t7,$zero,0x3210
/*  f00a900:	adaf0004 */ 	sw	$t7,0x4($t5)
/*  f00a904:	adab0000 */ 	sw	$t3,0x0($t5)
/*  f00a908:	8fb80050 */ 	lw	$t8,0x50($sp)
.L0f00a90c:
/*  f00a90c:	53000005 */ 	beqzl	$t8,.L0f00a924
/*  f00a910:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f00a914:	0fc35272 */ 	jal	func0f0d49c8
/*  f00a918:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f00a91c:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f00a920:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f00a924:
/*  f00a924:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f00a928:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f00a92c:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f00a930:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f00a934:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f00a938:	03e00008 */ 	jr	$ra
/*  f00a93c:	27bd0080 */ 	addiu	$sp,$sp,0x80
);
#else
GLOBAL_ASM(
glabel nbombRenderOverlay
/*  f00a490:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f00a494:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f00a498:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f00a49c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f00a4a0:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f00a4a4:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f00a4a8:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f00a4ac:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f00a4b0:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f00a4b4:	afa00050 */ 	sw	$zero,0x50($sp)
/*  f00a4b8:	c4441bb0 */ 	lwc1	$f4,0x1bb0($v0)
/*  f00a4bc:	3c10800a */ 	lui	$s0,%hi(g_Nbombs)
/*  f00a4c0:	3c11800a */ 	lui	$s1,%hi(var8009cbf8)
/*  f00a4c4:	e7a40070 */ 	swc1	$f4,0x70($sp)
/*  f00a4c8:	c4461bb4 */ 	lwc1	$f6,0x1bb4($v0)
/*  f00a4cc:	00009025 */ 	or	$s2,$zero,$zero
/*  f00a4d0:	00009825 */ 	or	$s3,$zero,$zero
/*  f00a4d4:	e7a60074 */ 	swc1	$f6,0x74($sp)
/*  f00a4d8:	c4481bb8 */ 	lwc1	$f8,0x1bb8($v0)
/*  f00a4dc:	2631cbf8 */ 	addiu	$s1,$s1,%lo(var8009cbf8)
/*  f00a4e0:	2610cb08 */ 	addiu	$s0,$s0,%lo(g_Nbombs)
/*  f00a4e4:	e7a80078 */ 	swc1	$f8,0x78($sp)
/*  f00a4e8:	8e02000c */ 	lw	$v0,0xc($s0)
.L0f00a4ec:
/*  f00a4ec:	0440001d */ 	bltz	$v0,.L0f00a564
/*  f00a4f0:	2841015f */ 	slti	$at,$v0,0x15f
/*  f00a4f4:	1020001b */ 	beqz	$at,.L0f00a564
/*  f00a4f8:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*  f00a4fc:	c6100000 */ 	lwc1	$f16,0x0($s0)
/*  f00a500:	c7b20074 */ 	lwc1	$f18,0x74($sp)
/*  f00a504:	c6040004 */ 	lwc1	$f4,0x4($s0)
/*  f00a508:	46105001 */ 	sub.s	$f0,$f10,$f16
/*  f00a50c:	c7a60078 */ 	lwc1	$f6,0x78($sp)
/*  f00a510:	c6080008 */ 	lwc1	$f8,0x8($s0)
/*  f00a514:	46049081 */ 	sub.s	$f2,$f18,$f4
/*  f00a518:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f00a51c:	46083381 */ 	sub.s	$f14,$f6,$f8
/*  f00a520:	46021402 */ 	mul.s	$f16,$f2,$f2
/*  f00a524:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f00a528:	460e7102 */ 	mul.s	$f4,$f14,$f14
/*  f00a52c:	0c012974 */ 	jal	sqrtf
/*  f00a530:	46049300 */ 	add.s	$f12,$f18,$f4
/*  f00a534:	c6060010 */ 	lwc1	$f6,0x10($s0)
/*  f00a538:	02002025 */ 	or	$a0,$s0,$zero
/*  f00a53c:	4606003c */ 	c.lt.s	$f0,$f6
/*  f00a540:	00000000 */ 	nop
/*  f00a544:	45020008 */ 	bc1fl	.L0f00a568
/*  f00a548:	26100028 */ 	addiu	$s0,$s0,0x28
/*  f00a54c:	0fc0252f */ 	jal	nbombCalculateAlpha
/*  f00a550:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f00a554:	0262082b */ 	sltu	$at,$s3,$v0
/*  f00a558:	50200003 */ 	beqzl	$at,.L0f00a568
/*  f00a55c:	26100028 */ 	addiu	$s0,$s0,0x28
/*  f00a560:	00409825 */ 	or	$s3,$v0,$zero
.L0f00a564:
/*  f00a564:	26100028 */ 	addiu	$s0,$s0,0x28
.L0f00a568:
/*  f00a568:	5611ffe0 */ 	bnel	$s0,$s1,.L0f00a4ec
/*  f00a56c:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f00a570:	524000e6 */ 	beqzl	$s2,.L0f00a90c
/*  f00a574:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f00a578:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f00a57c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f00a580:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f00a584:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f00a588:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f00a58c:	0c002f40 */ 	jal	viGetViewLeft
/*  f00a590:	00408025 */ 	or	$s0,$v0,$zero
/*  f00a594:	00027080 */ 	sll	$t6,$v0,0x2
/*  f00a598:	01c27021 */ 	addu	$t6,$t6,$v0
/*  f00a59c:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f00a5a0:	0c002f44 */ 	jal	viGetViewTop
/*  f00a5a4:	a7ae0042 */ 	sh	$t6,0x42($sp)
/*  f00a5a8:	00027880 */ 	sll	$t7,$v0,0x2
/*  f00a5ac:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f00a5b0:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f00a5b4:	0c002f40 */ 	jal	viGetViewLeft
/*  f00a5b8:	a7af0040 */ 	sh	$t7,0x40($sp)
/*  f00a5bc:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f00a5c0:	0011c403 */ 	sra	$t8,$s1,0x10
/*  f00a5c4:	0c002f22 */ 	jal	viGetViewWidth
/*  f00a5c8:	03008825 */ 	or	$s1,$t8,$zero
/*  f00a5cc:	00515821 */ 	addu	$t3,$v0,$s1
/*  f00a5d0:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f00a5d4:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f00a5d8:	000c6040 */ 	sll	$t4,$t4,0x1
/*  f00a5dc:	0c002f44 */ 	jal	viGetViewTop
/*  f00a5e0:	a7ac003e */ 	sh	$t4,0x3e($sp)
/*  f00a5e4:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f00a5e8:	00116c03 */ 	sra	$t5,$s1,0x10
/*  f00a5ec:	0c002f26 */ 	jal	viGetViewHeight
/*  f00a5f0:	01a08825 */ 	or	$s1,$t5,$zero
/*  f00a5f4:	3c014100 */ 	lui	$at,0x4100
/*  f00a5f8:	44811000 */ 	mtc1	$at,$f2
/*  f00a5fc:	3c014300 */ 	lui	$at,0x4300
/*  f00a600:	44816000 */ 	mtc1	$at,$f12
/*  f00a604:	3c014200 */ 	lui	$at,0x4200
/*  f00a608:	44817000 */ 	mtc1	$at,$f14
/*  f00a60c:	3c018006 */ 	lui	$at,%hi(var80061630)
/*  f00a610:	c4201630 */ 	lwc1	$f0,%lo(var80061630)($at)
/*  f00a614:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f00a618:	00514821 */ 	addu	$t1,$v0,$s1
/*  f00a61c:	46001202 */ 	mul.s	$f8,$f2,$f0
/*  f00a620:	00097400 */ 	sll	$t6,$t1,0x10
/*  f00a624:	000e7c03 */ 	sra	$t7,$t6,0x10
/*  f00a628:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f00a62c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f00a630:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f00a634:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f00a638:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f00a63c:	00195403 */ 	sra	$t2,$t9,0x10
/*  f00a640:	01404825 */ 	or	$t1,$t2,$zero
/*  f00a644:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f00a648:	afaa0050 */ 	sw	$t2,0x50($sp)
/*  f00a64c:	a7a9003c */ 	sh	$t1,0x3c($sp)
/*  f00a650:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f00a654:	460e5402 */ 	mul.s	$f16,$f10,$f14
/*  f00a658:	46000280 */ 	add.s	$f10,$f0,$f0
/*  f00a65c:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f00a660:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f00a664:	460c5402 */ 	mul.s	$f16,$f10,$f12
/*  f00a668:	44129000 */ 	mfc1	$s2,$f18
/*  f00a66c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f00a670:	460e8482 */ 	mul.s	$f18,$f16,$f14
/*  f00a674:	06410004 */ 	bgez	$s2,.L0f00a688
/*  f00a678:	324c07ff */ 	andi	$t4,$s2,0x7ff
/*  f00a67c:	11800002 */ 	beqz	$t4,.L0f00a688
/*  f00a680:	00000000 */ 	nop
/*  f00a684:	258cf800 */ 	addiu	$t4,$t4,-2048
.L0f00a688:
/*  f00a688:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f00a68c:	44184000 */ 	mfc1	$t8,$f8
/*  f00a690:	000c6c00 */ 	sll	$t5,$t4,0x10
/*  f00a694:	000d7403 */ 	sra	$t6,$t5,0x10
/*  f00a698:	440f2000 */ 	mfc1	$t7,$f4
/*  f00a69c:	01c09025 */ 	or	$s2,$t6,$zero
/*  f00a6a0:	07010004 */ 	bgez	$t8,.L0f00a6b4
/*  f00a6a4:	331907ff */ 	andi	$t9,$t8,0x7ff
/*  f00a6a8:	13200002 */ 	beqz	$t9,.L0f00a6b4
/*  f00a6ac:	00000000 */ 	nop
/*  f00a6b0:	2739f800 */ 	addiu	$t9,$t9,-2048
.L0f00a6b4:
/*  f00a6b4:	03205825 */ 	or	$t3,$t9,$zero
/*  f00a6b8:	016fc821 */ 	addu	$t9,$t3,$t7
/*  f00a6bc:	0fc351e7 */ 	jal	func0f0d479c
/*  f00a6c0:	a7b9005e */ 	sh	$t9,0x5e($sp)
/*  f00a6c4:	3c05800b */ 	lui	$a1,%hi(g_TexGeneralConfigs)
/*  f00a6c8:	87a8005e */ 	lh	$t0,0x5e($sp)
/*  f00a6cc:	87a9003c */ 	lh	$t1,0x3c($sp)
/*  f00a6d0:	8ca5b5a8 */ 	lw	$a1,%lo(g_TexGeneralConfigs)($a1)
/*  f00a6d4:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f00a6d8:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f00a6dc:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f00a6e0:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f00a6e4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f00a6e8:	27a40080 */ 	addiu	$a0,$sp,0x80
/*  f00a6ec:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f00a6f0:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f00a6f4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f00a6f8:	a7a8005e */ 	sh	$t0,0x5e($sp)
/*  f00a6fc:	a7a9003c */ 	sh	$t1,0x3c($sp)
/*  f00a700:	0fc2ce70 */ 	jal	texSelect
/*  f00a704:	24a50078 */ 	addiu	$a1,$a1,0x0078
/*  f00a708:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f00a70c:	87a8005e */ 	lh	$t0,0x5e($sp)
/*  f00a710:	87a9003c */ 	lh	$t1,0x3c($sp)
/*  f00a714:	25cb0008 */ 	addiu	$t3,$t6,0x8
/*  f00a718:	afab0080 */ 	sw	$t3,0x80($sp)
/*  f00a71c:	3c0fe700 */ 	lui	$t7,0xe700
/*  f00a720:	adcf0000 */ 	sw	$t7,0x0($t6)
/*  f00a724:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f00a728:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f00a72c:	3c0aba00 */ 	lui	$t2,0xba00
/*  f00a730:	354a1402 */ 	ori	$t2,$t2,0x1402
/*  f00a734:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f00a738:	afb90080 */ 	sw	$t9,0x80($sp)
/*  f00a73c:	af000004 */ 	sw	$zero,0x4($t8)
/*  f00a740:	af0a0000 */ 	sw	$t2,0x0($t8)
/*  f00a744:	8fac0080 */ 	lw	$t4,0x80($sp)
/*  f00a748:	3c0eb900 */ 	lui	$t6,0xb900
/*  f00a74c:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f00a750:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f00a754:	afad0080 */ 	sw	$t5,0x80($sp)
/*  f00a758:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f00a75c:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f00a760:	8fab0080 */ 	lw	$t3,0x80($sp)
/*  f00a764:	3c18fc12 */ 	lui	$t8,0xfc12
/*  f00a768:	3c19ff33 */ 	lui	$t9,0xff33
/*  f00a76c:	256f0008 */ 	addiu	$t7,$t3,0x8
/*  f00a770:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f00a774:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f00a778:	37181824 */ 	ori	$t8,$t8,0x1824
/*  f00a77c:	ad780000 */ 	sw	$t8,0x0($t3)
/*  f00a780:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f00a784:	8faa0080 */ 	lw	$t2,0x80($sp)
/*  f00a788:	240e3000 */ 	addiu	$t6,$zero,0x3000
/*  f00a78c:	3c0db600 */ 	lui	$t5,0xb600
/*  f00a790:	254c0008 */ 	addiu	$t4,$t2,0x8
/*  f00a794:	afac0080 */ 	sw	$t4,0x80($sp)
/*  f00a798:	ad4e0004 */ 	sw	$t6,0x4($t2)
/*  f00a79c:	ad4d0000 */ 	sw	$t5,0x0($t2)
/*  f00a7a0:	8fab0080 */ 	lw	$t3,0x80($sp)
/*  f00a7a4:	87a70040 */ 	lh	$a3,0x40($sp)
/*  f00a7a8:	87a60042 */ 	lh	$a2,0x42($sp)
/*  f00a7ac:	256f0008 */ 	addiu	$t7,$t3,0x8
/*  f00a7b0:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f00a7b4:	3c18ba00 */ 	lui	$t8,0xba00
/*  f00a7b8:	37180602 */ 	ori	$t8,$t8,0x602
/*  f00a7bc:	241900c0 */ 	addiu	$t9,$zero,0xc0
/*  f00a7c0:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f00a7c4:	ad780000 */ 	sw	$t8,0x0($t3)
/*  f00a7c8:	8faa0080 */ 	lw	$t2,0x80($sp)
/*  f00a7cc:	3c0dba00 */ 	lui	$t5,0xba00
/*  f00a7d0:	35ad0c02 */ 	ori	$t5,$t5,0xc02
/*  f00a7d4:	254c0008 */ 	addiu	$t4,$t2,0x8
/*  f00a7d8:	afac0080 */ 	sw	$t4,0x80($sp)
/*  f00a7dc:	240e2000 */ 	addiu	$t6,$zero,0x2000
/*  f00a7e0:	ad4e0004 */ 	sw	$t6,0x4($t2)
/*  f00a7e4:	ad4d0000 */ 	sw	$t5,0x0($t2)
/*  f00a7e8:	8fab0080 */ 	lw	$t3,0x80($sp)
/*  f00a7ec:	3c18b900 */ 	lui	$t8,0xb900
/*  f00a7f0:	3c190050 */ 	lui	$t9,0x50
/*  f00a7f4:	256f0008 */ 	addiu	$t7,$t3,0x8
/*  f00a7f8:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f00a7fc:	37394a50 */ 	ori	$t9,$t9,0x4a50
/*  f00a800:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f00a804:	ad780000 */ 	sw	$t8,0x0($t3)
/*  f00a808:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f00a80c:	8faa0080 */ 	lw	$t2,0x80($sp)
/*  f00a810:	3c0dba00 */ 	lui	$t5,0xba00
/*  f00a814:	35ad1301 */ 	ori	$t5,$t5,0x1301
/*  f00a818:	254c0008 */ 	addiu	$t4,$t2,0x8
/*  f00a81c:	afac0080 */ 	sw	$t4,0x80($sp)
/*  f00a820:	3c0e0008 */ 	lui	$t6,0x8
/*  f00a824:	ad4e0004 */ 	sw	$t6,0x4($t2)
/*  f00a828:	ad4d0000 */ 	sw	$t5,0x0($t2)
/*  f00a82c:	a6070002 */ 	sh	$a3,0x2($s0)
/*  f00a830:	a6060000 */ 	sh	$a2,0x0($s0)
/*  f00a834:	87a3003e */ 	lh	$v1,0x3e($sp)
/*  f00a838:	2402fff6 */ 	addiu	$v0,$zero,-10
/*  f00a83c:	a6020004 */ 	sh	$v0,0x4($s0)
/*  f00a840:	a6020010 */ 	sh	$v0,0x10($s0)
/*  f00a844:	a602001c */ 	sh	$v0,0x1c($s0)
/*  f00a848:	a6020028 */ 	sh	$v0,0x28($s0)
/*  f00a84c:	a6120008 */ 	sh	$s2,0x8($s0)
/*  f00a850:	a608000a */ 	sh	$t0,0xa($s0)
/*  f00a854:	a609001a */ 	sh	$t1,0x1a($s0)
/*  f00a858:	a6090026 */ 	sh	$t1,0x26($s0)
/*  f00a85c:	a607000e */ 	sh	$a3,0xe($s0)
/*  f00a860:	a6060024 */ 	sh	$a2,0x24($s0)
/*  f00a864:	a603000c */ 	sh	$v1,0xc($s0)
/*  f00a868:	a6030018 */ 	sh	$v1,0x18($s0)
/*  f00a86c:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f00a870:	264200a0 */ 	addiu	$v0,$s2,0xa0
/*  f00a874:	250303c0 */ 	addiu	$v1,$t0,0x3c0
/*  f00a878:	a6020014 */ 	sh	$v0,0x14($s0)
/*  f00a87c:	a6020020 */ 	sh	$v0,0x20($s0)
/*  f00a880:	a6030022 */ 	sh	$v1,0x22($s0)
/*  f00a884:	a612002c */ 	sh	$s2,0x2c($s0)
/*  f00a888:	a603002e */ 	sh	$v1,0x2e($s0)
/*  f00a88c:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f00a890:	a2000013 */ 	sb	$zero,0x13($s0)
/*  f00a894:	a200001f */ 	sb	$zero,0x1f($s0)
/*  f00a898:	a200002b */ 	sb	$zero,0x2b($s0)
/*  f00a89c:	a6080016 */ 	sh	$t0,0x16($s0)
/*  f00a8a0:	ac930000 */ 	sw	$s3,0x0($a0)
/*  f00a8a4:	8fb10080 */ 	lw	$s1,0x80($sp)
/*  f00a8a8:	3c180700 */ 	lui	$t8,0x700
/*  f00a8ac:	37180004 */ 	ori	$t8,$t8,0x4
/*  f00a8b0:	262f0008 */ 	addiu	$t7,$s1,0x8
/*  f00a8b4:	afaf0080 */ 	sw	$t7,0x80($sp)
/*  f00a8b8:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f00a8bc:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f00a8c0:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f00a8c4:	8fb20080 */ 	lw	$s2,0x80($sp)
/*  f00a8c8:	3c0c0430 */ 	lui	$t4,0x430
/*  f00a8cc:	358c0030 */ 	ori	$t4,$t4,0x30
/*  f00a8d0:	264a0008 */ 	addiu	$t2,$s2,0x8
/*  f00a8d4:	afaa0080 */ 	sw	$t2,0x80($sp)
/*  f00a8d8:	02002025 */ 	or	$a0,$s0,$zero
/*  f00a8dc:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f00a8e0:	ae4c0000 */ 	sw	$t4,0x0($s2)
/*  f00a8e4:	ae420004 */ 	sw	$v0,0x4($s2)
/*  f00a8e8:	8fad0080 */ 	lw	$t5,0x80($sp)
/*  f00a8ec:	3c0bb100 */ 	lui	$t3,0xb100
/*  f00a8f0:	356b0002 */ 	ori	$t3,$t3,0x2
/*  f00a8f4:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f00a8f8:	afae0080 */ 	sw	$t6,0x80($sp)
/*  f00a8fc:	240f3210 */ 	addiu	$t7,$zero,0x3210
/*  f00a900:	adaf0004 */ 	sw	$t7,0x4($t5)
/*  f00a904:	adab0000 */ 	sw	$t3,0x0($t5)
/*  f00a908:	8fb80050 */ 	lw	$t8,0x50($sp)
.L0f00a90c:
/*  f00a90c:	53000005 */ 	beqzl	$t8,.L0f00a924
/*  f00a910:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f00a914:	0fc35272 */ 	jal	func0f0d49c8
/*  f00a918:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f00a91c:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f00a920:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f00a924:
/*  f00a924:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f00a928:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f00a92c:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f00a930:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f00a934:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f00a938:	03e00008 */ 	jr	$ra
/*  f00a93c:	27bd0080 */ 	addiu	$sp,$sp,0x80
);
#endif

/**
 * Checks if the player is inside an nbomb storm, and if so renders the black
 * storm texture directly over the screen.
 */
// Mismatch: The below saves a and b to the stack then adds them together later,
// while goal adds them immediately to save into sp5e.
//Gfx *nbombRenderOverlay(Gfx *gdl)
//{
//	u32 stack;
//	struct coord campos; // 70
//	struct gfxvtx *vertices;
//	u32 maxalpha;
//	bool inside;
//	s32 i;
//	s16 sp5e;
//	s16 s2;
//	u32 stack2[2];
//	bool sp50 = false;
//	u32 stack3;
//	u32 *colours; // 48
//	s16 a;
//	s16 b;
//	s16 viewleft; // 42
//	s16 viewtop; // 40
//	s16 viewright; // 3e
//	s16 viewbottom; // 3c
//
//	campos.x = g_Vars.currentplayer->cam_pos.x;
//	campos.y = g_Vars.currentplayer->cam_pos.y;
//	campos.z = g_Vars.currentplayer->cam_pos.z;
//
//	inside = false;
//	maxalpha = 0;
//
//	for (i = 0; i < ARRAYCOUNT(g_Nbombs); i++) {
//		if (g_Nbombs[i].age240 >= 0 && g_Nbombs[i].age240 <= TICKS(350)) {
//			f32 xdiff = campos.f[0] - g_Nbombs[i].pos.f[0];
//			f32 ydiff = campos.f[1] - g_Nbombs[i].pos.f[1];
//			f32 zdiff = campos.f[2] - g_Nbombs[i].pos.f[2];
//
//			if (sqrtf(xdiff * xdiff + ydiff * ydiff + zdiff * zdiff) < g_Nbombs[i].radius) {
//				u32 alpha = nbombCalculateAlpha(&g_Nbombs[i]);
//
//				inside = true;
//
//				if (alpha > maxalpha) {
//					maxalpha = alpha;
//				}
//			}
//		}
//	}
//
//	if (inside) {
//		colours = gfxAllocateColours(1);
//		vertices = gfxAllocateVertices(4);
//
//		viewleft = viGetViewLeft() * 10;
//		viewtop = viGetViewTop() * 10;
//		viewright = (s16)(viGetViewLeft() + viGetViewWidth()) * 10;
//		viewbottom = (s16)(viGetViewTop() + viGetViewHeight()) * 10;
//
//		s2 = (s32) (8.0f * var80061630 * 128.0f * 32.0f) % 2048;
//		a = (s32)(campos.f[1] * 8.0f) % 2048;
//		b = 2.0f * var80061630 * 128.0f * 32.0f;
//		sp5e = a + b;
//
//		if (1);
//		sp50 = true;
//
//		gdl = func0f0d479c(gdl);
//
//		texSelect(&gdl, &g_TexGeneralConfigs[10], 2, 1, 2, 1, NULL);
//
//		gDPPipeSync(gdl++);
//		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
//		gDPSetAlphaCompare(gdl++, G_AC_NONE);
//		gDPSetCombineMode(gdl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
//		gSPClearGeometryMode(gdl++, G_CULL_BOTH);
//		gDPSetColorDither(gdl++, G_CD_DISABLE);
//		gDPSetTextureFilter(gdl++, G_TF_BILERP);
//		gDPSetRenderMode(gdl++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
//		gDPSetTexturePersp(gdl++, G_TP_PERSP);
//
//		vertices[0].z = -10;
//		vertices[1].z = -10;
//		vertices[2].z = -10;
//		vertices[3].z = -10;
//
//		vertices[0].x = viewleft;
//		vertices[0].y = viewtop;
//
//		vertices[1].x = viewright;
//		vertices[1].y = viewtop;
//
//		vertices[2].x = viewright;
//		vertices[2].y = viewbottom;
//
//		vertices[3].x = viewleft;
//		vertices[3].y = viewbottom;
//
//		vertices[0].s = s2;
//		vertices[0].t = sp5e;
//		vertices[1].s = s2 + 160;
//		vertices[1].t = sp5e;
//		vertices[2].s = s2 + 160;
//		vertices[2].t = sp5e + 960;
//		vertices[3].s = s2;
//		vertices[3].t = sp5e + 960;
//
//		vertices[0].colour = 0;
//		vertices[1].colour = 0;
//		vertices[2].colour = 0;
//		vertices[3].colour = 0;
//
//		colours[0] = maxalpha;
//
//		gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 1);
//		gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 4);
//		gDPTri2(gdl++, 0, 1, 2, 2, 3, 0);
//	}
//
//	if (sp50) {
//		gdl = func0f0d49c8(gdl);
//	}
//
//	return gdl;
//}

GLOBAL_ASM(
glabel gasRender
.late_rodata
glabel var7f1a7f44
.word 0xc6557000
glabel var7f1a7f48
.word 0xc4b82000
glabel var7f1a7f4c
.word 0x3e4ccccd
glabel var7f1a7f50
.word 0x40c907a9
glabel var7f1a7f54
.word 0x453b8000
.text
/*  f00a940:	27bdfef0 */ 	addiu	$sp,$sp,-272
/*  f00a944:	3c013f80 */ 	lui	$at,0x3f80
/*  f00a948:	44810000 */ 	mtc1	$at,$f0
/*  f00a94c:	3c0f7f1a */ 	lui	$t7,%hi(var7f1a7e80)
/*  f00a950:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f00a954:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f00a958:	25ef7e80 */ 	addiu	$t7,$t7,%lo(var7f1a7e80)
/*  f00a95c:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f00a960:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f00a964:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f00a968:	afa40110 */ 	sw	$a0,0x110($sp)
/*  f00a96c:	00008825 */ 	or	$s1,$zero,$zero
/*  f00a970:	afa000ec */ 	sw	$zero,0xec($sp)
/*  f00a974:	25ea0030 */ 	addiu	$t2,$t7,0x30
/*  f00a978:	27ae00bc */ 	addiu	$t6,$sp,0xbc
/*  f00a97c:	e7a00108 */ 	swc1	$f0,0x108($sp)
.L0f00a980:
/*  f00a980:	8de10000 */ 	lw	$at,0x0($t7)
/*  f00a984:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f00a988:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f00a98c:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f00a990:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f00a994:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f00a998:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f00a99c:	15eafff8 */ 	bne	$t7,$t2,.L0f00a980
/*  f00a9a0:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f00a9a4:	8ccb04b4 */ 	lw	$t3,0x4b4($a2)
/*  f00a9a8:	24010019 */ 	addiu	$at,$zero,0x19
/*  f00a9ac:	556101e9 */ 	bnel	$t3,$at,.L0f00b154
/*  f00a9b0:	8fad00ec */ 	lw	$t5,0xec($sp)
/*  f00a9b4:	8cc30284 */ 	lw	$v1,0x284($a2)
/*  f00a9b8:	e7a000b8 */ 	swc1	$f0,0xb8($sp)
/*  f00a9bc:	27b000bc */ 	addiu	$s0,$sp,0xbc
/*  f00a9c0:	c4641bb0 */ 	lwc1	$f4,0x1bb0($v1)
/*  f00a9c4:	e7a400fc */ 	swc1	$f4,0xfc($sp)
/*  f00a9c8:	c4661bb4 */ 	lwc1	$f6,0x1bb4($v1)
/*  f00a9cc:	e7a60100 */ 	swc1	$f6,0x100($sp)
/*  f00a9d0:	c4681bb8 */ 	lwc1	$f8,0x1bb8($v1)
/*  f00a9d4:	e7a80104 */ 	swc1	$f8,0x104($sp)
/*  f00a9d8:	27a400fc */ 	addiu	$a0,$sp,0xfc
.L0f00a9dc:
/*  f00a9dc:	0fc586b7 */ 	jal	roomContainsCoord
/*  f00a9e0:	86050002 */ 	lh	$a1,0x2($s0)
/*  f00a9e4:	10400002 */ 	beqz	$v0,.L0f00a9f0
/*  f00a9e8:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f00a9ec:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f00a9f0:
/*  f00a9f0:	27ac00ec */ 	addiu	$t4,$sp,0xec
/*  f00a9f4:	560cfff9 */ 	bnel	$s0,$t4,.L0f00a9dc
/*  f00a9f8:	27a400fc */ 	addiu	$a0,$sp,0xfc
/*  f00a9fc:	16200025 */ 	bnez	$s1,.L0f00aa94
/*  f00aa00:	27a400fc */ 	addiu	$a0,$sp,0xfc
/*  f00aa04:	3c017f1a */ 	lui	$at,%hi(var7f1a7f44)
/*  f00aa08:	c4247f44 */ 	lwc1	$f4,%lo(var7f1a7f44)($at)
/*  f00aa0c:	c7aa0104 */ 	lwc1	$f10,0x104($sp)
/*  f00aa10:	3c017f1a */ 	lui	$at,%hi(var7f1a7f48)
/*  f00aa14:	c4287f48 */ 	lwc1	$f8,%lo(var7f1a7f48)($at)
/*  f00aa18:	c7a600fc */ 	lwc1	$f6,0xfc($sp)
/*  f00aa1c:	46045001 */ 	sub.s	$f0,$f10,$f4
/*  f00aa20:	3c01c39a */ 	lui	$at,0xc39a
/*  f00aa24:	44812000 */ 	mtc1	$at,$f4
/*  f00aa28:	46083081 */ 	sub.s	$f2,$f6,$f8
/*  f00aa2c:	c7aa0100 */ 	lwc1	$f10,0x100($sp)
/*  f00aa30:	46045381 */ 	sub.s	$f14,$f10,$f4
/*  f00aa34:	46021182 */ 	mul.s	$f6,$f2,$f2
/*  f00aa38:	00000000 */ 	nop
/*  f00aa3c:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*  f00aa40:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f00aa44:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f00aa48:	0c012974 */ 	jal	sqrtf
/*  f00aa4c:	460a2300 */ 	add.s	$f12,$f4,$f10
/*  f00aa50:	3c0144a6 */ 	lui	$at,0x44a6
/*  f00aa54:	44816000 */ 	mtc1	$at,$f12
/*  f00aa58:	00000000 */ 	nop
/*  f00aa5c:	460c003c */ 	c.lt.s	$f0,$f12
/*  f00aa60:	00000000 */ 	nop
/*  f00aa64:	45020022 */ 	bc1fl	.L0f00aaf0
/*  f00aa68:	c7a40108 */ 	lwc1	$f4,0x108($sp)
/*  f00aa6c:	460c0203 */ 	div.s	$f8,$f0,$f12
/*  f00aa70:	3c013f80 */ 	lui	$at,0x3f80
/*  f00aa74:	44813000 */ 	mtc1	$at,$f6
/*  f00aa78:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f00aa7c:	24040032 */ 	addiu	$a0,$zero,0x32
/*  f00aa80:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f00aa84:	0fc02911 */ 	jal	gasGetDoorFrac
/*  f00aa88:	e7a40108 */ 	swc1	$f4,0x108($sp)
/*  f00aa8c:	10000017 */ 	b	.L0f00aaec
/*  f00aa90:	e7a000b8 */ 	swc1	$f0,0xb8($sp)
.L0f00aa94:
/*  f00aa94:	0fc586b7 */ 	jal	roomContainsCoord
/*  f00aa98:	24050091 */ 	addiu	$a1,$zero,0x91
/*  f00aa9c:	50400014 */ 	beqzl	$v0,.L0f00aaf0
/*  f00aaa0:	c7a40108 */ 	lwc1	$f4,0x108($sp)
/*  f00aaa4:	0fc02911 */ 	jal	gasGetDoorFrac
/*  f00aaa8:	24040030 */ 	addiu	$a0,$zero,0x30
/*  f00aaac:	24040031 */ 	addiu	$a0,$zero,0x31
/*  f00aab0:	0fc02911 */ 	jal	gasGetDoorFrac
/*  f00aab4:	e7a000b0 */ 	swc1	$f0,0xb0($sp)
/*  f00aab8:	c7a200b0 */ 	lwc1	$f2,0xb0($sp)
/*  f00aabc:	3c017f1a */ 	lui	$at,%hi(var7f1a7f4c)
/*  f00aac0:	4600103c */ 	c.lt.s	$f2,$f0
/*  f00aac4:	00000000 */ 	nop
/*  f00aac8:	45020004 */ 	bc1fl	.L0f00aadc
/*  f00aacc:	e7a200b8 */ 	swc1	$f2,0xb8($sp)
/*  f00aad0:	10000002 */ 	b	.L0f00aadc
/*  f00aad4:	e7a000b8 */ 	swc1	$f0,0xb8($sp)
/*  f00aad8:	e7a200b8 */ 	swc1	$f2,0xb8($sp)
.L0f00aadc:
/*  f00aadc:	c7aa00b8 */ 	lwc1	$f10,0xb8($sp)
/*  f00aae0:	c4267f4c */ 	lwc1	$f6,%lo(var7f1a7f4c)($at)
/*  f00aae4:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f00aae8:	e7a800b8 */ 	swc1	$f8,0xb8($sp)
.L0f00aaec:
/*  f00aaec:	c7a40108 */ 	lwc1	$f4,0x108($sp)
.L0f00aaf0:
/*  f00aaf0:	c7aa00b8 */ 	lwc1	$f10,0xb8($sp)
/*  f00aaf4:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x2ac)
/*  f00aaf8:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f00aafc:	12200017 */ 	beqz	$s1,.L0f00ab5c
/*  f00ab00:	e7a60108 */ 	swc1	$f6,0x108($sp)
/*  f00ab04:	8dada26c */ 	lw	$t5,%lo(g_Vars+0x2ac)($t5)
/*  f00ab08:	24010006 */ 	addiu	$at,$zero,0x6
/*  f00ab0c:	3c02800a */ 	lui	$v0,%hi(g_CutsceneCurAnimFrame60)
/*  f00ab10:	15a10012 */ 	bne	$t5,$at,.L0f00ab5c
/*  f00ab14:	00000000 */ 	nop
/*  f00ab18:	8c42de10 */ 	lw	$v0,%lo(g_CutsceneCurAnimFrame60)($v0)
/*  f00ab1c:	28410884 */ 	slti	$at,$v0,0x884
/*  f00ab20:	50200004 */ 	beqzl	$at,.L0f00ab34
/*  f00ab24:	28410a28 */ 	slti	$at,$v0,0xa28
/*  f00ab28:	1000000c */ 	b	.L0f00ab5c
/*  f00ab2c:	00008825 */ 	or	$s1,$zero,$zero
/*  f00ab30:	28410a28 */ 	slti	$at,$v0,0xa28
.L0f00ab34:
/*  f00ab34:	10200009 */ 	beqz	$at,.L0f00ab5c
/*  f00ab38:	2459f77c */ 	addiu	$t9,$v0,-2180
/*  f00ab3c:	44994000 */ 	mtc1	$t9,$f8
/*  f00ab40:	3c0143d2 */ 	lui	$at,0x43d2
/*  f00ab44:	44815000 */ 	mtc1	$at,$f10
/*  f00ab48:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f00ab4c:	c7a60108 */ 	lwc1	$f6,0x108($sp)
/*  f00ab50:	460a2003 */ 	div.s	$f0,$f4,$f10
/*  f00ab54:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f00ab58:	e7a80108 */ 	swc1	$f8,0x108($sp)
.L0f00ab5c:
/*  f00ab5c:	5220017d */ 	beqzl	$s1,.L0f00b154
/*  f00ab60:	8fad00ec */ 	lw	$t5,0xec($sp)
/*  f00ab64:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f00ab68:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f00ab6c:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f00ab70:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f00ab74:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f00ab78:	0c002f40 */ 	jal	viGetViewLeft
/*  f00ab7c:	00408025 */ 	or	$s0,$v0,$zero
/*  f00ab80:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f00ab84:	0302c021 */ 	addu	$t8,$t8,$v0
/*  f00ab88:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f00ab8c:	0c002f44 */ 	jal	viGetViewTop
/*  f00ab90:	a7b8009e */ 	sh	$t8,0x9e($sp)
/*  f00ab94:	00025080 */ 	sll	$t2,$v0,0x2
/*  f00ab98:	01425021 */ 	addu	$t2,$t2,$v0
/*  f00ab9c:	000a5040 */ 	sll	$t2,$t2,0x1
/*  f00aba0:	0c002f40 */ 	jal	viGetViewLeft
/*  f00aba4:	a7aa009c */ 	sh	$t2,0x9c($sp)
/*  f00aba8:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f00abac:	00117c03 */ 	sra	$t7,$s1,0x10
/*  f00abb0:	0c002f22 */ 	jal	viGetViewWidth
/*  f00abb4:	01e08825 */ 	or	$s1,$t7,$zero
/*  f00abb8:	00516021 */ 	addu	$t4,$v0,$s1
/*  f00abbc:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f00abc0:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f00abc4:	000d6840 */ 	sll	$t5,$t5,0x1
/*  f00abc8:	0c002f44 */ 	jal	viGetViewTop
/*  f00abcc:	a7ad009a */ 	sh	$t5,0x9a($sp)
/*  f00abd0:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f00abd4:	0011cc03 */ 	sra	$t9,$s1,0x10
/*  f00abd8:	0c002f26 */ 	jal	viGetViewHeight
/*  f00abdc:	03208825 */ 	or	$s1,$t9,$zero
/*  f00abe0:	00517821 */ 	addu	$t7,$v0,$s1
/*  f00abe4:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f00abe8:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f00abec:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f00abf0:	01cf7021 */ 	addu	$t6,$t6,$t7
/*  f00abf4:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f00abf8:	a7ae0098 */ 	sh	$t6,0x98($sp)
/*  f00abfc:	c4641bb0 */ 	lwc1	$f4,0x1bb0($v1)
/*  f00ac00:	c4601bbc */ 	lwc1	$f0,0x1bbc($v1)
/*  f00ac04:	c46e1bc4 */ 	lwc1	$f14,0x1bc4($v1)
/*  f00ac08:	e7a4008c */ 	swc1	$f4,0x8c($sp)
/*  f00ac0c:	c46a1bb8 */ 	lwc1	$f10,0x1bb8($v1)
/*  f00ac10:	46000307 */ 	neg.s	$f12,$f0
/*  f00ac14:	0fc259d4 */ 	jal	atan2f
/*  f00ac18:	e7aa0088 */ 	swc1	$f10,0x88($sp)
/*  f00ac1c:	3c017f1a */ 	lui	$at,%hi(var7f1a7f50)
/*  f00ac20:	c4267f50 */ 	lwc1	$f6,%lo(var7f1a7f50)($at)
/*  f00ac24:	3c014080 */ 	lui	$at,0x4080
/*  f00ac28:	44816000 */ 	mtc1	$at,$f12
/*  f00ac2c:	46060203 */ 	div.s	$f8,$f0,$f6
/*  f00ac30:	0fc01ac2 */ 	jal	func0f006b08
/*  f00ac34:	e7a80078 */ 	swc1	$f8,0x78($sp)
/*  f00ac38:	c7a4008c */ 	lwc1	$f4,0x8c($sp)
/*  f00ac3c:	c7aa0088 */ 	lwc1	$f10,0x88($sp)
/*  f00ac40:	3c014200 */ 	lui	$at,0x4200
/*  f00ac44:	44819000 */ 	mtc1	$at,$f18
/*  f00ac48:	460a2180 */ 	add.s	$f6,$f4,$f10
/*  f00ac4c:	3c017f1a */ 	lui	$at,%hi(var7f1a7f54)
/*  f00ac50:	c4287f54 */ 	lwc1	$f8,%lo(var7f1a7f54)($at)
/*  f00ac54:	3c013f00 */ 	lui	$at,0x3f00
/*  f00ac58:	46083083 */ 	div.s	$f2,$f6,$f8
/*  f00ac5c:	44814000 */ 	mtc1	$at,$f8
/*  f00ac60:	3c0140c0 */ 	lui	$at,0x40c0
/*  f00ac64:	4600110d */ 	trunc.w.s	$f4,$f2
/*  f00ac68:	440c2000 */ 	mfc1	$t4,$f4
/*  f00ac6c:	46080101 */ 	sub.s	$f4,$f0,$f8
/*  f00ac70:	c7a80078 */ 	lwc1	$f8,0x78($sp)
/*  f00ac74:	448c5000 */ 	mtc1	$t4,$f10
/*  f00ac78:	00000000 */ 	nop
/*  f00ac7c:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f00ac80:	44815000 */ 	mtc1	$at,$f10
/*  f00ac84:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f00ac88:	46061401 */ 	sub.s	$f16,$f2,$f6
/*  f00ac8c:	460a2183 */ 	div.s	$f6,$f4,$f10
/*  f00ac90:	44815000 */ 	mtc1	$at,$f10
/*  f00ac94:	3c014300 */ 	lui	$at,0x4300
/*  f00ac98:	e7b00038 */ 	swc1	$f16,0x38($sp)
/*  f00ac9c:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f00aca0:	460a8182 */ 	mul.s	$f6,$f16,$f10
/*  f00aca4:	44815000 */ 	mtc1	$at,$f10
/*  f00aca8:	3c014080 */ 	lui	$at,0x4080
/*  f00acac:	44816000 */ 	mtc1	$at,$f12
/*  f00acb0:	46062380 */ 	add.s	$f14,$f4,$f6
/*  f00acb4:	460e7200 */ 	add.s	$f8,$f14,$f14
/*  f00acb8:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f00acbc:	00000000 */ 	nop
/*  f00acc0:	46122182 */ 	mul.s	$f6,$f4,$f18
/*  f00acc4:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f00acc8:	44194000 */ 	mfc1	$t9,$f8
/*  f00accc:	00000000 */ 	nop
/*  f00acd0:	07210004 */ 	bgez	$t9,.L0f00ace4
/*  f00acd4:	333807ff */ 	andi	$t8,$t9,0x7ff
/*  f00acd8:	13000002 */ 	beqz	$t8,.L0f00ace4
/*  f00acdc:	00000000 */ 	nop
/*  f00ace0:	2718f800 */ 	addiu	$t8,$t8,-2048
.L0f00ace4:
/*  f00ace4:	0fc01ad5 */ 	jal	func0f006b54
/*  f00ace8:	a7b80076 */ 	sh	$t8,0x76($sp)
/*  f00acec:	3c014200 */ 	lui	$at,0x4200
/*  f00acf0:	44819000 */ 	mtc1	$at,$f18
/*  f00acf4:	3c013f00 */ 	lui	$at,0x3f00
/*  f00acf8:	44815000 */ 	mtc1	$at,$f10
/*  f00acfc:	3c01c110 */ 	lui	$at,0xc110
/*  f00ad00:	44813000 */ 	mtc1	$at,$f6
/*  f00ad04:	460a0101 */ 	sub.s	$f4,$f0,$f10
/*  f00ad08:	c7aa0078 */ 	lwc1	$f10,0x78($sp)
/*  f00ad0c:	c7b00038 */ 	lwc1	$f16,0x38($sp)
/*  f00ad10:	3c014300 */ 	lui	$at,0x4300
/*  f00ad14:	46062203 */ 	div.s	$f8,$f4,$f6
/*  f00ad18:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f00ad1c:	afac00ec */ 	sw	$t4,0xec($sp)
/*  f00ad20:	8fa40110 */ 	lw	$a0,0x110($sp)
/*  f00ad24:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f00ad28:	44814000 */ 	mtc1	$at,$f8
/*  f00ad2c:	3c014100 */ 	lui	$at,0x4100
/*  f00ad30:	46102380 */ 	add.s	$f14,$f4,$f16
/*  f00ad34:	460e7180 */ 	add.s	$f6,$f14,$f14
/*  f00ad38:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f00ad3c:	c7a80100 */ 	lwc1	$f8,0x100($sp)
/*  f00ad40:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f00ad44:	44815000 */ 	mtc1	$at,$f10
/*  f00ad48:	3c018006 */ 	lui	$at,%hi(var80061630)
/*  f00ad4c:	c4221630 */ 	lwc1	$f2,%lo(var80061630)($at)
/*  f00ad50:	3c014300 */ 	lui	$at,0x4300
/*  f00ad54:	46021300 */ 	add.s	$f12,$f2,$f2
/*  f00ad58:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f00ad5c:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f00ad60:	44814000 */ 	mtc1	$at,$f8
/*  f00ad64:	3c014280 */ 	lui	$at,0x4280
/*  f00ad68:	44113000 */ 	mfc1	$s1,$f6
/*  f00ad6c:	46086282 */ 	mul.s	$f10,$f12,$f8
/*  f00ad70:	44814000 */ 	mtc1	$at,$f8
/*  f00ad74:	06210004 */ 	bgez	$s1,.L0f00ad88
/*  f00ad78:	322f07ff */ 	andi	$t7,$s1,0x7ff
/*  f00ad7c:	11e00002 */ 	beqz	$t7,.L0f00ad88
/*  f00ad80:	00000000 */ 	nop
/*  f00ad84:	25eff800 */ 	addiu	$t7,$t7,-2048
.L0f00ad88:
/*  f00ad88:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f00ad8c:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f00ad90:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f00ad94:	000e5c03 */ 	sra	$t3,$t6,0x10
/*  f00ad98:	46086282 */ 	mul.s	$f10,$f12,$f8
/*  f00ad9c:	44023000 */ 	mfc1	$v0,$f6
/*  f00ada0:	01608825 */ 	or	$s1,$t3,$zero
/*  f00ada4:	04410004 */ 	bgez	$v0,.L0f00adb8
/*  f00ada8:	304d07ff */ 	andi	$t5,$v0,0x7ff
/*  f00adac:	11a00002 */ 	beqz	$t5,.L0f00adb8
/*  f00adb0:	00000000 */ 	nop
/*  f00adb4:	25adf800 */ 	addiu	$t5,$t5,-2048
.L0f00adb8:
/*  f00adb8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f00adbc:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f00adc0:	01a01025 */ 	or	$v0,$t5,$zero
/*  f00adc4:	440b3000 */ 	mfc1	$t3,$f6
/*  f00adc8:	00000000 */ 	nop
/*  f00adcc:	004b6821 */ 	addu	$t5,$v0,$t3
/*  f00add0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f00add4:	a7ad00fa */ 	sh	$t5,0xfa($sp)
/*  f00add8:	440f3000 */ 	mfc1	$t7,$f6
/*  f00addc:	00000000 */ 	nop
/*  f00ade0:	004f5821 */ 	addu	$t3,$v0,$t7
/*  f00ade4:	0fc351e7 */ 	jal	func0f0d479c
/*  f00ade8:	a7ab0072 */ 	sh	$t3,0x72($sp)
/*  f00adec:	3c05800b */ 	lui	$a1,%hi(g_TexGeneralConfigs)
/*  f00adf0:	87a80072 */ 	lh	$t0,0x72($sp)
/*  f00adf4:	87a900fa */ 	lh	$t1,0xfa($sp)
/*  f00adf8:	8ca5b5a8 */ 	lw	$a1,%lo(g_TexGeneralConfigs)($a1)
/*  f00adfc:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f00ae00:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f00ae04:	afa20110 */ 	sw	$v0,0x110($sp)
/*  f00ae08:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f00ae0c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f00ae10:	27a40110 */ 	addiu	$a0,$sp,0x110
/*  f00ae14:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f00ae18:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f00ae1c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f00ae20:	a7a80072 */ 	sh	$t0,0x72($sp)
/*  f00ae24:	a7a900fa */ 	sh	$t1,0xfa($sp)
/*  f00ae28:	0fc2ce70 */ 	jal	texSelect
/*  f00ae2c:	24a50048 */ 	addiu	$a1,$a1,0x0048
/*  f00ae30:	8fb80110 */ 	lw	$t8,0x110($sp)
/*  f00ae34:	87a80072 */ 	lh	$t0,0x72($sp)
/*  f00ae38:	87a900fa */ 	lh	$t1,0xfa($sp)
/*  f00ae3c:	270a0008 */ 	addiu	$t2,$t8,0x8
/*  f00ae40:	afaa0110 */ 	sw	$t2,0x110($sp)
/*  f00ae44:	3c0fe700 */ 	lui	$t7,0xe700
/*  f00ae48:	af0f0000 */ 	sw	$t7,0x0($t8)
/*  f00ae4c:	af000004 */ 	sw	$zero,0x4($t8)
/*  f00ae50:	8fae0110 */ 	lw	$t6,0x110($sp)
/*  f00ae54:	3c0cba00 */ 	lui	$t4,0xba00
/*  f00ae58:	358c1402 */ 	ori	$t4,$t4,0x1402
/*  f00ae5c:	25cb0008 */ 	addiu	$t3,$t6,0x8
/*  f00ae60:	afab0110 */ 	sw	$t3,0x110($sp)
/*  f00ae64:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f00ae68:	adcc0000 */ 	sw	$t4,0x0($t6)
/*  f00ae6c:	8fad0110 */ 	lw	$t5,0x110($sp)
/*  f00ae70:	3c18b900 */ 	lui	$t8,0xb900
/*  f00ae74:	37180002 */ 	ori	$t8,$t8,0x2
/*  f00ae78:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f00ae7c:	afb90110 */ 	sw	$t9,0x110($sp)
/*  f00ae80:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f00ae84:	adb80000 */ 	sw	$t8,0x0($t5)
/*  f00ae88:	8faa0110 */ 	lw	$t2,0x110($sp)
/*  f00ae8c:	3c0efc12 */ 	lui	$t6,0xfc12
/*  f00ae90:	3c0bff33 */ 	lui	$t3,0xff33
/*  f00ae94:	254f0008 */ 	addiu	$t7,$t2,0x8
/*  f00ae98:	afaf0110 */ 	sw	$t7,0x110($sp)
/*  f00ae9c:	356bffff */ 	ori	$t3,$t3,0xffff
/*  f00aea0:	35ce1824 */ 	ori	$t6,$t6,0x1824
/*  f00aea4:	ad4e0000 */ 	sw	$t6,0x0($t2)
/*  f00aea8:	ad4b0004 */ 	sw	$t3,0x4($t2)
/*  f00aeac:	8fac0110 */ 	lw	$t4,0x110($sp)
/*  f00aeb0:	24183000 */ 	addiu	$t8,$zero,0x3000
/*  f00aeb4:	3c19b600 */ 	lui	$t9,0xb600
/*  f00aeb8:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f00aebc:	afad0110 */ 	sw	$t5,0x110($sp)
/*  f00aec0:	ad980004 */ 	sw	$t8,0x4($t4)
/*  f00aec4:	ad990000 */ 	sw	$t9,0x0($t4)
/*  f00aec8:	8faa0110 */ 	lw	$t2,0x110($sp)
/*  f00aecc:	87a7009c */ 	lh	$a3,0x9c($sp)
/*  f00aed0:	87a6009e */ 	lh	$a2,0x9e($sp)
/*  f00aed4:	254f0008 */ 	addiu	$t7,$t2,0x8
/*  f00aed8:	afaf0110 */ 	sw	$t7,0x110($sp)
/*  f00aedc:	3c0eba00 */ 	lui	$t6,0xba00
/*  f00aee0:	35ce0602 */ 	ori	$t6,$t6,0x602
/*  f00aee4:	240b00c0 */ 	addiu	$t3,$zero,0xc0
/*  f00aee8:	ad4b0004 */ 	sw	$t3,0x4($t2)
/*  f00aeec:	ad4e0000 */ 	sw	$t6,0x0($t2)
/*  f00aef0:	8fac0110 */ 	lw	$t4,0x110($sp)
/*  f00aef4:	3c19ba00 */ 	lui	$t9,0xba00
/*  f00aef8:	37390c02 */ 	ori	$t9,$t9,0xc02
/*  f00aefc:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f00af00:	afad0110 */ 	sw	$t5,0x110($sp)
/*  f00af04:	24182000 */ 	addiu	$t8,$zero,0x2000
/*  f00af08:	ad980004 */ 	sw	$t8,0x4($t4)
/*  f00af0c:	ad990000 */ 	sw	$t9,0x0($t4)
/*  f00af10:	8faa0110 */ 	lw	$t2,0x110($sp)
/*  f00af14:	3c0eb900 */ 	lui	$t6,0xb900
/*  f00af18:	3c0b0050 */ 	lui	$t3,0x50
/*  f00af1c:	254f0008 */ 	addiu	$t7,$t2,0x8
/*  f00af20:	afaf0110 */ 	sw	$t7,0x110($sp)
/*  f00af24:	356b4340 */ 	ori	$t3,$t3,0x4340
/*  f00af28:	35ce031d */ 	ori	$t6,$t6,0x31d
/*  f00af2c:	ad4e0000 */ 	sw	$t6,0x0($t2)
/*  f00af30:	ad4b0004 */ 	sw	$t3,0x4($t2)
/*  f00af34:	8fac0110 */ 	lw	$t4,0x110($sp)
/*  f00af38:	3c19ba00 */ 	lui	$t9,0xba00
/*  f00af3c:	37391301 */ 	ori	$t9,$t9,0x1301
/*  f00af40:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f00af44:	afad0110 */ 	sw	$t5,0x110($sp)
/*  f00af48:	3c180008 */ 	lui	$t8,0x8
/*  f00af4c:	ad980004 */ 	sw	$t8,0x4($t4)
/*  f00af50:	ad990000 */ 	sw	$t9,0x0($t4)
/*  f00af54:	a6070002 */ 	sh	$a3,0x2($s0)
/*  f00af58:	a6060000 */ 	sh	$a2,0x0($s0)
/*  f00af5c:	87a40098 */ 	lh	$a0,0x98($sp)
/*  f00af60:	87a3009a */ 	lh	$v1,0x9a($sp)
/*  f00af64:	2402fff6 */ 	addiu	$v0,$zero,-10
/*  f00af68:	a6020004 */ 	sh	$v0,0x4($s0)
/*  f00af6c:	a6020010 */ 	sh	$v0,0x10($s0)
/*  f00af70:	a602001c */ 	sh	$v0,0x1c($s0)
/*  f00af74:	a6020028 */ 	sh	$v0,0x28($s0)
/*  f00af78:	a6020034 */ 	sh	$v0,0x34($s0)
/*  f00af7c:	a6020040 */ 	sh	$v0,0x40($s0)
/*  f00af80:	a602004c */ 	sh	$v0,0x4c($s0)
/*  f00af84:	a6020058 */ 	sh	$v0,0x58($s0)
/*  f00af88:	a6110008 */ 	sh	$s1,0x8($s0)
/*  f00af8c:	a608000a */ 	sh	$t0,0xa($s0)
/*  f00af90:	a607000e */ 	sh	$a3,0xe($s0)
/*  f00af94:	a6070032 */ 	sh	$a3,0x32($s0)
/*  f00af98:	a607003e */ 	sh	$a3,0x3e($s0)
/*  f00af9c:	a6060024 */ 	sh	$a2,0x24($s0)
/*  f00afa0:	a6060030 */ 	sh	$a2,0x30($s0)
/*  f00afa4:	a6060054 */ 	sh	$a2,0x54($s0)
/*  f00afa8:	a604001a */ 	sh	$a0,0x1a($s0)
/*  f00afac:	a6040026 */ 	sh	$a0,0x26($s0)
/*  f00afb0:	a604004a */ 	sh	$a0,0x4a($s0)
/*  f00afb4:	a6040056 */ 	sh	$a0,0x56($s0)
/*  f00afb8:	a603000c */ 	sh	$v1,0xc($s0)
/*  f00afbc:	a6030018 */ 	sh	$v1,0x18($s0)
/*  f00afc0:	a603003c */ 	sh	$v1,0x3c($s0)
/*  f00afc4:	a6030048 */ 	sh	$v1,0x48($s0)
/*  f00afc8:	87a40076 */ 	lh	$a0,0x76($sp)
/*  f00afcc:	262203c0 */ 	addiu	$v0,$s1,0x3c0
/*  f00afd0:	25030280 */ 	addiu	$v1,$t0,0x280
/*  f00afd4:	a6020014 */ 	sh	$v0,0x14($s0)
/*  f00afd8:	a6020020 */ 	sh	$v0,0x20($s0)
/*  f00afdc:	a6030022 */ 	sh	$v1,0x22($s0)
/*  f00afe0:	a611002c */ 	sh	$s1,0x2c($s0)
/*  f00afe4:	a603002e */ 	sh	$v1,0x2e($s0)
/*  f00afe8:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f00afec:	a2000013 */ 	sb	$zero,0x13($s0)
/*  f00aff0:	a200001f */ 	sb	$zero,0x1f($s0)
/*  f00aff4:	a200002b */ 	sb	$zero,0x2b($s0)
/*  f00aff8:	a6080016 */ 	sh	$t0,0x16($s0)
/*  f00affc:	a609003a */ 	sh	$t1,0x3a($s0)
/*  f00b000:	a6040038 */ 	sh	$a0,0x38($s0)
/*  f00b004:	8fa500a4 */ 	lw	$a1,0xa4($sp)
/*  f00b008:	252301e0 */ 	addiu	$v1,$t1,0x1e0
/*  f00b00c:	24820280 */ 	addiu	$v0,$a0,0x280
/*  f00b010:	a6020044 */ 	sh	$v0,0x44($s0)
/*  f00b014:	a6020050 */ 	sh	$v0,0x50($s0)
/*  f00b018:	a6030052 */ 	sh	$v1,0x52($s0)
/*  f00b01c:	a603005e */ 	sh	$v1,0x5e($s0)
/*  f00b020:	a2000037 */ 	sb	$zero,0x37($s0)
/*  f00b024:	a2000043 */ 	sb	$zero,0x43($s0)
/*  f00b028:	a200004f */ 	sb	$zero,0x4f($s0)
/*  f00b02c:	a200005b */ 	sb	$zero,0x5b($s0)
/*  f00b030:	3c0142fe */ 	lui	$at,0x42fe
/*  f00b034:	a6090046 */ 	sh	$t1,0x46($s0)
/*  f00b038:	a604005c */ 	sh	$a0,0x5c($s0)
/*  f00b03c:	c7aa0108 */ 	lwc1	$f10,0x108($sp)
/*  f00b040:	44814000 */ 	mtc1	$at,$f8
/*  f00b044:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f00b048:	3c0d0700 */ 	lui	$t5,0x700
/*  f00b04c:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f00b050:	3c014f00 */ 	lui	$at,0x4f00
/*  f00b054:	35ad0004 */ 	ori	$t5,$t5,0x4
/*  f00b058:	444af800 */ 	cfc1	$t2,$31
/*  f00b05c:	44cff800 */ 	ctc1	$t7,$31
/*  f00b060:	00000000 */ 	nop
/*  f00b064:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f00b068:	444ff800 */ 	cfc1	$t7,$31
/*  f00b06c:	00000000 */ 	nop
/*  f00b070:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f00b074:	51e00013 */ 	beqzl	$t7,.L0f00b0c4
/*  f00b078:	440f3000 */ 	mfc1	$t7,$f6
/*  f00b07c:	44813000 */ 	mtc1	$at,$f6
/*  f00b080:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f00b084:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f00b088:	44cff800 */ 	ctc1	$t7,$31
/*  f00b08c:	00000000 */ 	nop
/*  f00b090:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f00b094:	444ff800 */ 	cfc1	$t7,$31
/*  f00b098:	00000000 */ 	nop
/*  f00b09c:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f00b0a0:	15e00005 */ 	bnez	$t7,.L0f00b0b8
/*  f00b0a4:	00000000 */ 	nop
/*  f00b0a8:	440f3000 */ 	mfc1	$t7,$f6
/*  f00b0ac:	3c018000 */ 	lui	$at,0x8000
/*  f00b0b0:	10000007 */ 	b	.L0f00b0d0
/*  f00b0b4:	01e17825 */ 	or	$t7,$t7,$at
.L0f00b0b8:
/*  f00b0b8:	10000005 */ 	b	.L0f00b0d0
/*  f00b0bc:	240fffff */ 	addiu	$t7,$zero,-1
/*  f00b0c0:	440f3000 */ 	mfc1	$t7,$f6
.L0f00b0c4:
/*  f00b0c4:	00000000 */ 	nop
/*  f00b0c8:	05e0fffb */ 	bltz	$t7,.L0f00b0b8
/*  f00b0cc:	00000000 */ 	nop
.L0f00b0d0:
/*  f00b0d0:	3c013faf */ 	lui	$at,0x3faf
/*  f00b0d4:	34211100 */ 	ori	$at,$at,0x1100
/*  f00b0d8:	01e17025 */ 	or	$t6,$t7,$at
/*  f00b0dc:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f00b0e0:	8fb10110 */ 	lw	$s1,0x110($sp)
/*  f00b0e4:	44caf800 */ 	ctc1	$t2,$31
/*  f00b0e8:	00a02025 */ 	or	$a0,$a1,$zero
/*  f00b0ec:	262c0008 */ 	addiu	$t4,$s1,0x8
/*  f00b0f0:	afac0110 */ 	sw	$t4,0x110($sp)
/*  f00b0f4:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f00b0f8:	ae2d0000 */ 	sw	$t5,0x0($s1)
/*  f00b0fc:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f00b100:	8fb90110 */ 	lw	$t9,0x110($sp)
/*  f00b104:	3c0a0470 */ 	lui	$t2,0x470
/*  f00b108:	354a0060 */ 	ori	$t2,$t2,0x60
/*  f00b10c:	27380008 */ 	addiu	$t8,$t9,0x8
/*  f00b110:	afb80110 */ 	sw	$t8,0x110($sp)
/*  f00b114:	af2a0000 */ 	sw	$t2,0x0($t9)
/*  f00b118:	02002025 */ 	or	$a0,$s0,$zero
/*  f00b11c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f00b120:	afb90044 */ 	sw	$t9,0x44($sp)
/*  f00b124:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f00b128:	3c0bb100 */ 	lui	$t3,0xb100
/*  f00b12c:	3c0c7654 */ 	lui	$t4,0x7654
/*  f00b130:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f00b134:	8faf0110 */ 	lw	$t7,0x110($sp)
/*  f00b138:	358c3210 */ 	ori	$t4,$t4,0x3210
/*  f00b13c:	356b4602 */ 	ori	$t3,$t3,0x4602
/*  f00b140:	25ee0008 */ 	addiu	$t6,$t7,0x8
/*  f00b144:	afae0110 */ 	sw	$t6,0x110($sp)
/*  f00b148:	adec0004 */ 	sw	$t4,0x4($t7)
/*  f00b14c:	adeb0000 */ 	sw	$t3,0x0($t7)
/*  f00b150:	8fad00ec */ 	lw	$t5,0xec($sp)
.L0f00b154:
/*  f00b154:	51a00005 */ 	beqzl	$t5,.L0f00b16c
/*  f00b158:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f00b15c:	0fc35272 */ 	jal	func0f0d49c8
/*  f00b160:	8fa40110 */ 	lw	$a0,0x110($sp)
/*  f00b164:	afa20110 */ 	sw	$v0,0x110($sp)
/*  f00b168:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f00b16c:
/*  f00b16c:	8fa20110 */ 	lw	$v0,0x110($sp)
/*  f00b170:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f00b174:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f00b178:	03e00008 */ 	jr	$ra
/*  f00b17c:	27bd0110 */ 	addiu	$sp,$sp,0x110
);

const u32 var7f1a7e80[] = {0x00000092};
const u32 var7f1a7e84[] = {0x00000093};
const u32 var7f1a7e88[] = {0x00000094};
const u32 var7f1a7e8c[] = {0x00000095};
const u32 var7f1a7e90[] = {0x00000096};
const u32 var7f1a7e94[] = {0x00000097};
const u32 var7f1a7e98[] = {0x00000098};
const u32 var7f1a7e9c[] = {0x00000099};
const u32 var7f1a7ea0[] = {0x0000009a};
const u32 var7f1a7ea4[] = {0x00000091};
const u32 var7f1a7ea8[] = {0x0000008f};
const u32 var7f1a7eac[] = {0x00000090};

// Mismatch: Float calculations
//Gfx *gasRender(Gfx *gdl)
//{
//	bool show = false;
//	f32 alphafrac = 1.0f; // 108
//	struct coord campos; // fc
//	s16 spfa; // fa
//	u32 alpha;
//	s32 i;
//	bool drawn = false; // ec
//	const u32 gasrooms[] = { 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x91, 0x8f, 0x90 }; // bc
//	f32 intensityfrac; // b8
//	u32 stack;
//	f32 frac1; // b0
//	f32 frac2;
//
//	f32 distance;
//	u32 *colours; // a4
//	struct gfxvtx *vertices;
//	s16 viewleft; // 9e
//	s16 viewtop; // 9c
//	s16 viewright; // 9a
//	s16 viewbottom; // 98
//	f32 fVar19;
//	f32 camposx; // 8c
//	f32 camposz; // 88
//	f32 sp78; // 78
//	s16 sp76; // 76
//	s16 sp72; // 72
//	s16 sVar15;
//	s32 uVar21;
//	f32 sp38; // 38
//
//	if (g_Vars.stagenum == STAGE_ESCAPE) {
//		intensityfrac = 1.0f;
//
//		campos.x = g_Vars.currentplayer->cam_pos.x;
//		campos.y = g_Vars.currentplayer->cam_pos.y;
//		campos.z = g_Vars.currentplayer->cam_pos.z;
//
//		for (i = 0; i < 12; i++) {
//			if (roomContainsCoord(&campos, gasrooms[i])) {
//				show = true;
//			}
//		}
//
//		if (!show) {
//			// Outside of the gas rooms list - check distance to abitrary point
//			distance = sqrtf(
//					(campos.f[0] - -1473.0f) * (campos.f[0] - -1473.0f) +
//					(campos.f[1] - -308.0f) * (campos.f[1] - -308.0f) +
//					(campos.f[2] - -13660.0f) * (campos.f[2] - -13660.0f));
//
//			if (distance < 1328.0f) {
//				show = true;
//				alphafrac = 1.0f - distance / 1328.0f;
//				intensityfrac = gasGetDoorFrac(0x32);
//			}
//		} else {
//			if (roomContainsCoord(&campos, 0x91)) {
//				// In the small room between the first two doors
//				frac1 = gasGetDoorFrac(0x30);
//				frac2 = gasGetDoorFrac(0x31);
//
//				if (frac2 > frac1) {
//					intensityfrac = frac2;
//				} else {
//					intensityfrac = frac1;
//				}
//
//				intensityfrac += 0.2f;
//			}
//		}
//
//		alphafrac *= intensityfrac;
//
//		if (show && g_Vars.tickmode == TICKMODE_CUTSCENE) {
//			if (g_CutsceneCurAnimFrame60 < 2180) {
//				show = false;
//			} else {
//				if (g_CutsceneCurAnimFrame60 < 2600) {
//					alphafrac *= (g_CutsceneCurAnimFrame60 - 2180) / 420.0f;
//				}
//			}
//		}
//
//		if (show) {
//			f32 lookx;
//			f32 lookz;
//			f32 tmp;
//			f32 tmp2;
//			s32 tmp3;
//			colours = gfxAllocateColours(1);
//			vertices = gfxAllocateVertices(8);
//			viewleft = viGetViewLeft() * 10;
//			viewtop = viGetViewTop() * 10;
//			viewright = (viGetViewLeft() + viGetViewWidth()) * 10;
//			viewbottom = (viGetViewTop() + viGetViewHeight()) * 10;
//
//			lookx = g_Vars.currentplayer->cam_look.x;
//			lookz = g_Vars.currentplayer->cam_look.z;
//			camposx = g_Vars.currentplayer->cam_pos.f[0];
//			camposz = g_Vars.currentplayer->cam_pos.f[2];
//
//			sp78 = atan2f(-lookx, lookz) / M_BADTAU;
//			sp38 = (func0f006b08(4) - 0.5f) / 6.0f;
//
//			fVar19 = (camposx + camposz) / 3000.0f;
//			fVar19 -= (s32)fVar19;
//			tmp = sp38 + sp78 + fVar19 * 1.5f;
//
//			sp76 = (s32)((2.0f * tmp) * 128.0f * 32.0f) % 0x800;
//
//			tmp2 = (func0f006b54(4) - 0.5f) / -9.0f;
//			drawn = true;
//			fVar19 = tmp2 + sp78 + sp38;
//
//			sVar15 = (s32)((2.0f * fVar19) * 128.0f * 32.0f) % 0x800;
//
//			tmp3 = (s32)(campos.y * 8.0f) % 0x800;
//
//			spfa = tmp3 + (s32)((2.0f * var80061630) * 128.0f * 32.0f);
//			sp72 = tmp3 + (s32)((2.0f * var80061630) * 64.0f * 32.0f);
//
//			gdl = func0f0d479c(gdl);
//
//			texSelect(&gdl, &g_TexGeneralConfigs[6], 4, 1, 2, 1, NULL);
//
//			gDPPipeSync(gdl++);
//			gDPSetCycleType(gdl++, G_CYC_1CYCLE);
//			gDPSetAlphaCompare(gdl++, G_AC_NONE);
//			gDPSetCombineMode(gdl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
//			gSPClearGeometryMode(gdl++, G_CULL_BOTH);
//			gDPSetColorDither(gdl++, G_CD_DISABLE);
//			gDPSetTextureFilter(gdl++, G_TF_BILERP);
//			gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
//			gDPSetTexturePersp(gdl++, G_TP_PERSP);
//
//			vertices[0].x = viewleft;
//			vertices[0].y = viewtop;
//			vertices[0].z = -10;
//			vertices[1].z = -10;
//			vertices[2].z = -10;
//			vertices[3].z = -10;
//			vertices[4].z = -10;
//			vertices[5].z = -10;
//			vertices[6].z = -10;
//			vertices[7].z = -10;
//			vertices[0].s = sVar15;
//			vertices[0].t = sp72;
//			vertices[1].y = viewtop;
//			vertices[4].y = viewtop;
//			vertices[5].y = viewtop;
//			vertices[3].x = viewleft;
//			vertices[4].x = viewleft;
//			vertices[7].x = viewleft;
//			vertices[2].y = viewbottom;
//			vertices[3].y = viewbottom;
//			vertices[6].y = viewbottom;
//			vertices[7].y = viewbottom;
//			vertices[1].x = viewright;
//			vertices[2].x = viewright;
//			vertices[5].x = viewright;
//			vertices[6].x = viewright;
//			vertices[1].s = sVar15 + 960;
//			vertices[2].s = sVar15 + 960;
//			vertices[2].t = sp72 + 640;
//			vertices[3].s = sVar15;
//			vertices[3].t = sp72 + 640;
//			vertices[0].colour = 0;
//			vertices[1].colour = 0;
//			vertices[2].colour = 0;
//			vertices[3].colour = 0;
//			vertices[1].t = sp72;
//			vertices[4].t = spfa;
//			vertices[4].s = sp76;
//			vertices[5].s = sp76 + 640;
//			vertices[6].s = sp76 + 640;
//			vertices[6].t = spfa + 480;
//			vertices[7].t = spfa + 480;
//			vertices[4].colour = 0;
//			vertices[5].colour = 0;
//			vertices[6].colour = 0;
//			vertices[7].colour = 0;
//			vertices[5].t = spfa;
//			vertices[7].s = sp76;
//
//			colours[0] = 0x3faf1100 | (u32)(alphafrac * 127.0f);
//
//			gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 1);
//			gDPSetVerticeArray(gdl++, osVirtualToPhysical(vertices), 8);
//
//			gDPTri4(gdl++, 0, 1, 2, 2, 3, 0, 4, 5, 6, 6, 7, 4);
//		}
//	}
//
//	if (drawn) {
//		gdl = func0f0d49c8(gdl);
//	}
//
//	return gdl;
//}
