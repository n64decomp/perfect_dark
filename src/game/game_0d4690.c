#include <ultra64.h>
#include "constants.h"
#include "game/game_0b3350.h"
#include "game/game_0b4950.h"
#include "game/game_0d4690.h"
#include "game/gfxmemory.h"
#include "game/file.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/lib_09a80.h"
#include "lib/main.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "data.h"
#include "types.h"

const char var7f1adba0[] = "txmul";
const char var7f1adba8[] = "depthsub";
const char var7f1adbb4[] = "rsub";
const char var7f1adbbc[] = ":%02d";
const char var7f1adbc4[] = "%d";

u32 var8009de90;
u32 var8009de94;
u32 var8009de98;
u32 var8009de9c;

#if VERSION >= VERSION_NTSC_1_0
Vp *var80070f10 = NULL;
#else
Vp var80070f10;
#endif

u32 var80070f14 = 0x000003e8;
u32 var80070f18 = 0x00000014;
u32 var80070f1c = 0x00000005;

void func0f0d4690(Mtxf *mtx)
{
	struct coord pos;

	func000159b0(mtx);

	pos.x = -159.75f;
	pos.y = PAL ? 136.25f : 120.25f;
	pos.z = 0;

	pos.x = (.5f - viGetWidth()) * 0.5f;
	pos.y = (.5f + viGetHeight()) * 0.5f;
	pos.z = 0;

	func00015dd4(&pos, mtx);
	func00015e4c(-1, mtx);

	if (g_ScaleX == 2) {
		func00015df0(2, mtx);
	}
}

void func0f0d475c(Mtxf *mtx)
{
	func0f0d4690(mtx);
	func00015df0(0.1f, mtx);
	func00015e4c(0.1f, mtx);
}

Gfx *func0f0d479c(Gfx *gdl)
{
	Mtxf mtx;
	Mtxf *mtx1;
	Mtxf *mtx2;

	mtx1 = gfxAllocateMatrix();
	mtx2 = gfxAllocateMatrix();

	func00016760();
	func0f0d475c(&mtx);
	func00016054(&mtx, mtx2);
	func000159b0(&mtx);

	guFrustumF(mtx.m,
			-(f32) viGetWidth() * 0.5f, viGetWidth() * 0.5f,
			-(f32) viGetHeight() * 0.5f, viGetHeight() * 0.5f,
			10, 10000, 1);

	func00016054(&mtx, mtx1);
	func00016784();

	gSPMatrix(gdl++, osVirtualToPhysical(mtx2), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gSPMatrix(gdl++, osVirtualToPhysical(mtx1), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

#if VERSION >= VERSION_NTSC_1_0
	if (var80070f10 == NULL) {
		u32 size = align16(sizeof(Vp));
		var80070f10 = gfxAllocate(size);

		if (var80070f10 != NULL) {
			var80070f10->vp.vscale[0] = viGetWidth() << 1;
			var80070f10->vp.vscale[1] = viGetHeight() << 1;
			var80070f10->vp.vscale[2] = 1;
			var80070f10->vp.vscale[3] = 0;

			var80070f10->vp.vtrans[0] = viGetWidth() << 1;
			var80070f10->vp.vtrans[1] = viGetHeight() << 1;
			var80070f10->vp.vtrans[2] = 0x1ff;
			var80070f10->vp.vtrans[3] = 0;
		}
	}

	gSPViewport(gdl++, var80070f10);
#else
	var80070f10.vp.vscale[0] = 640;
	var80070f10.vp.vscale[1] = 480;
	var80070f10.vp.vscale[2] = 640;
	var80070f10.vp.vscale[3] = 0;

	var80070f10.vp.vtrans[0] = 640;
	var80070f10.vp.vtrans[1] = 480;
	var80070f10.vp.vtrans[2] = 0x1ff;
	var80070f10.vp.vtrans[3] = 0;

	var80070f10.vp.vscale[0] = viGetWidth() << 1;
	var80070f10.vp.vscale[1] = viGetHeight() << 1;
	var80070f10.vp.vscale[2] = 1;
	var80070f10.vp.vscale[3] = 0;

	var80070f10.vp.vtrans[0] = viGetWidth() << 1;
	var80070f10.vp.vtrans[1] = viGetHeight() << 1;
	var80070f10.vp.vtrans[2] = 0x1ff;
	var80070f10.vp.vtrans[3] = 0;

	gSPViewport(gdl++, &var80070f10);
#endif

	gDPPipeSync(gdl++);

	return gdl;
}

Gfx *func0f0d49c8(Gfx *gdl)
{
	gSPViewport(gdl++, OS_K0_TO_PHYSICAL(func0000ab4c()));
	gSPMatrix(gdl++, osVirtualToPhysical(currentPlayerGetUnk1750()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

	return gdl;
}

Gfx *func0f0d4a3c(Gfx *gdl, s32 arg1)
{
	Mtxf mtx;
	Mtxf *mtxptr = gfxAllocateMatrix();

	gDPPipeSync(gdl++);

	if (arg1 == 0) {
		func0f0b39c0(&gdl, &var800ab5a8[6], 2, 0, 2, 1, 0);
	} else if (arg1 == 1) {
		func0f0b39c0(&gdl, &var800ab5a8[11], 2, 0, 2, 1, 0);
	}

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetCombineMode(gdl++, G_CC_MODULATEIA, G_CC_MODULATEIA);
	gSPSetGeometryMode(gdl++, G_SHADE);
	gSPSetGeometryMode(gdl++, G_SHADING_SMOOTH);
	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);
	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
	gDPSetTexturePersp(gdl++, G_TP_PERSP);

	func0f0d4690(&mtx);
	func00016054(&mtx, mtxptr);

	gSPMatrix(gdl++, osVirtualToPhysical(mtxptr), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	return gdl;
}

Gfx *func0f0d4c80(Gfx *gdl)
{
	Mtxf mtx;
	Mtxf *mtxptr = gfxAllocateMatrix();

	func0f0d4690(&mtx);
	func00015df0(0.1f, &mtx);
	func00015e4c(0.1f, &mtx);
	func00016054(&mtx, mtxptr);

	gSPMatrix(gdl++, osVirtualToPhysical(mtxptr), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

	return gdl;
}

GLOBAL_ASM(
glabel func0f0d4d0c
/*  f0d4d0c:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0d4d10:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0d4d14:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f0d4d18:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f0d4d1c:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f0d4d20:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0d4d24:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f0d4d28:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0d4d2c:	afa20044 */ 	sw	$v0,0x44($sp)
/*  f0d4d30:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f0d4d34:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0d4d38:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d4d3c:	44819000 */ 	mtc1	$at,$f18
/*  f0d4d40:	3c047f1b */ 	lui	$a0,%hi(var7f1adba0)
/*  f0d4d44:	3c058007 */ 	lui	$a1,%hi(var80070f18)
/*  f0d4d48:	24a50f18 */ 	addiu	$a1,$a1,%lo(var80070f18)
/*  f0d4d4c:	2484dba0 */ 	addiu	$a0,$a0,%lo(var7f1adba0)
/*  f0d4d50:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0d4d54:	e7b20030 */ 	swc1	$f18,0x30($sp)
/*  f0d4d58:	0c0036cc */ 	jal	func0000db30
/*  f0d4d5c:	e7b20034 */ 	swc1	$f18,0x34($sp)
/*  f0d4d60:	3c02800a */ 	lui	$v0,%hi(var8009de90)
/*  f0d4d64:	8fa90050 */ 	lw	$t1,0x50($sp)
/*  f0d4d68:	8c42de90 */ 	lw	$v0,%lo(var8009de90)($v0)
/*  f0d4d6c:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0d4d70:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f0d4d74:	0122082a */ 	slt	$at,$t1,$v0
/*  f0d4d78:	c7b00030 */ 	lwc1	$f16,0x30($sp)
/*  f0d4d7c:	10200007 */ 	beqz	$at,.L0f0d4d9c
/*  f0d4d80:	c7b20034 */ 	lwc1	$f18,0x34($sp)
/*  f0d4d84:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f0d4d88:	01a2082a */ 	slt	$at,$t5,$v0
/*  f0d4d8c:	10200003 */ 	beqz	$at,.L0f0d4d9c
/*  f0d4d90:	00000000 */ 	nop
/*  f0d4d94:	10000154 */ 	b	.L0f0d52e8
/*  f0d4d98:	01801025 */ 	or	$v0,$t4,$zero
.L0f0d4d9c:
/*  f0d4d9c:	3c03800a */ 	lui	$v1,%hi(var8009de94)
/*  f0d4da0:	8c63de94 */ 	lw	$v1,%lo(var8009de94)($v1)
/*  f0d4da4:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f0d4da8:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f0d4dac:	0069082a */ 	slt	$at,$v1,$t1
/*  f0d4db0:	10200006 */ 	beqz	$at,.L0f0d4dcc
/*  f0d4db4:	3c047f1b */ 	lui	$a0,%hi(var7f1adba8)
/*  f0d4db8:	006d082a */ 	slt	$at,$v1,$t5
/*  f0d4dbc:	50200004 */ 	beqzl	$at,.L0f0d4dd0
/*  f0d4dc0:	0122082a */ 	slt	$at,$t1,$v0
/*  f0d4dc4:	10000148 */ 	b	.L0f0d52e8
/*  f0d4dc8:	01801025 */ 	or	$v0,$t4,$zero
.L0f0d4dcc:
/*  f0d4dcc:	0122082a */ 	slt	$at,$t1,$v0
.L0f0d4dd0:
/*  f0d4dd0:	10200002 */ 	beqz	$at,.L0f0d4ddc
/*  f0d4dd4:	2484dba8 */ 	addiu	$a0,$a0,%lo(var7f1adba8)
/*  f0d4dd8:	00404825 */ 	or	$t1,$v0,$zero
.L0f0d4ddc:
/*  f0d4ddc:	01a2082a */ 	slt	$at,$t5,$v0
/*  f0d4de0:	10200002 */ 	beqz	$at,.L0f0d4dec
/*  f0d4de4:	3c058007 */ 	lui	$a1,%hi(var80070f14)
/*  f0d4de8:	00406825 */ 	or	$t5,$v0,$zero
.L0f0d4dec:
/*  f0d4dec:	0069082a */ 	slt	$at,$v1,$t1
/*  f0d4df0:	10200002 */ 	beqz	$at,.L0f0d4dfc
/*  f0d4df4:	3c028007 */ 	lui	$v0,%hi(var80070f18)
/*  f0d4df8:	00604825 */ 	or	$t1,$v1,$zero
.L0f0d4dfc:
/*  f0d4dfc:	006d082a */ 	slt	$at,$v1,$t5
/*  f0d4e00:	10200002 */ 	beqz	$at,.L0f0d4e0c
/*  f0d4e04:	24a50f14 */ 	addiu	$a1,$a1,%lo(var80070f14)
/*  f0d4e08:	00606825 */ 	or	$t5,$v1,$zero
.L0f0d4e0c:
/*  f0d4e0c:	8c420f18 */ 	lw	$v0,%lo(var80070f18)($v0)
/*  f0d4e10:	01c97821 */ 	addu	$t7,$t6,$t1
/*  f0d4e14:	8fae0054 */ 	lw	$t6,0x54($sp)
/*  f0d4e18:	01e20019 */ 	multu	$t7,$v0
/*  f0d4e1c:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f0d4e20:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f0d4e24:	240e4000 */ 	addiu	$t6,$zero,0x4000
/*  f0d4e28:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0d4e2c:	a7a0002a */ 	sh	$zero,0x2a($sp)
/*  f0d4e30:	a7ae0028 */ 	sh	$t6,0x28($sp)
/*  f0d4e34:	00005012 */ 	mflo	$t2
/*  f0d4e38:	000ac400 */ 	sll	$t8,$t2,0x10
/*  f0d4e3c:	00185403 */ 	sra	$t2,$t8,0x10
/*  f0d4e40:	01e20019 */ 	multu	$t7,$v0
/*  f0d4e44:	00005812 */ 	mflo	$t3
/*  f0d4e48:	000bc400 */ 	sll	$t8,$t3,0x10
/*  f0d4e4c:	14e10004 */ 	bne	$a3,$at,.L0f0d4e60
/*  f0d4e50:	00185c03 */ 	sra	$t3,$t8,0x10
/*  f0d4e54:	3c014000 */ 	lui	$at,0x4000
/*  f0d4e58:	44818000 */ 	mtc1	$at,$f16
/*  f0d4e5c:	00000000 */ 	nop
.L0f0d4e60:
/*  f0d4e60:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0d4e64:	afa90050 */ 	sw	$t1,0x50($sp)
/*  f0d4e68:	a7aa002e */ 	sh	$t2,0x2e($sp)
/*  f0d4e6c:	a7ab002c */ 	sh	$t3,0x2c($sp)
/*  f0d4e70:	afac0048 */ 	sw	$t4,0x48($sp)
/*  f0d4e74:	afad0058 */ 	sw	$t5,0x58($sp)
/*  f0d4e78:	e7b00030 */ 	swc1	$f16,0x30($sp)
/*  f0d4e7c:	0c0036cc */ 	jal	func0000db30
/*  f0d4e80:	e7b20034 */ 	swc1	$f18,0x34($sp)
/*  f0d4e84:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f0d4e88:	3c014000 */ 	lui	$at,0x4000
/*  f0d4e8c:	44811000 */ 	mtc1	$at,$f2
/*  f0d4e90:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f0d4e94:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0d4e98:	8fa90050 */ 	lw	$t1,0x50($sp)
/*  f0d4e9c:	87aa002e */ 	lh	$t2,0x2e($sp)
/*  f0d4ea0:	87ab002c */ 	lh	$t3,0x2c($sp)
/*  f0d4ea4:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f0d4ea8:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f0d4eac:	c7b00030 */ 	lwc1	$f16,0x30($sp)
/*  f0d4eb0:	c7b20034 */ 	lwc1	$f18,0x34($sp)
/*  f0d4eb4:	10e20004 */ 	beq	$a3,$v0,.L0f0d4ec8
/*  f0d4eb8:	240500c8 */ 	addiu	$a1,$zero,0xc8
/*  f0d4ebc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0d4ec0:	54e1000c */ 	bnel	$a3,$at,.L0f0d4ef4
/*  f0d4ec4:	3c014080 */ 	lui	$at,0x4080
.L0f0d4ec8:
/*  f0d4ec8:	14e20004 */ 	bne	$a3,$v0,.L0f0d4edc
/*  f0d4ecc:	3c014080 */ 	lui	$at,0x4080
/*  f0d4ed0:	00005025 */ 	or	$t2,$zero,$zero
/*  f0d4ed4:	10000003 */ 	b	.L0f0d4ee4
/*  f0d4ed8:	240b0400 */ 	addiu	$t3,$zero,0x400
.L0f0d4edc:
/*  f0d4edc:	240a0400 */ 	addiu	$t2,$zero,0x400
/*  f0d4ee0:	240b0800 */ 	addiu	$t3,$zero,0x800
.L0f0d4ee4:
/*  f0d4ee4:	44818000 */ 	mtc1	$at,$f16
/*  f0d4ee8:	24051770 */ 	addiu	$a1,$zero,0x1770
/*  f0d4eec:	46008486 */ 	mov.s	$f18,$f16
/*  f0d4ef0:	3c014080 */ 	lui	$at,0x4080
.L0f0d4ef4:
/*  f0d4ef4:	44810000 */ 	mtc1	$at,$f0
/*  f0d4ef8:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0d4efc:	10e10004 */ 	beq	$a3,$at,.L0f0d4f10
/*  f0d4f00:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0d4f04:	10e10002 */ 	beq	$a3,$at,.L0f0d4f10
/*  f0d4f08:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0d4f0c:	14e10008 */ 	bne	$a3,$at,.L0f0d4f30
.L0f0d4f10:
/*  f0d4f10:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0d4f14:	00005025 */ 	or	$t2,$zero,$zero
/*  f0d4f18:	240b0800 */ 	addiu	$t3,$zero,0x800
/*  f0d4f1c:	240507d0 */ 	addiu	$a1,$zero,0x7d0
/*  f0d4f20:	46000486 */ 	mov.s	$f18,$f0
/*  f0d4f24:	14e10002 */ 	bne	$a3,$at,.L0f0d4f30
/*  f0d4f28:	46000406 */ 	mov.s	$f16,$f0
/*  f0d4f2c:	46001406 */ 	mov.s	$f16,$f2
.L0f0d4f30:
/*  f0d4f30:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0d4f34:	14e10004 */ 	bne	$a3,$at,.L0f0d4f48
/*  f0d4f38:	3c013f80 */ 	lui	$at,0x3f80
/*  f0d4f3c:	44818000 */ 	mtc1	$at,$f16
/*  f0d4f40:	240507d0 */ 	addiu	$a1,$zero,0x7d0
/*  f0d4f44:	46008486 */ 	mov.s	$f18,$f16
.L0f0d4f48:
/*  f0d4f48:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0d4f4c:	10e10005 */ 	beq	$a3,$at,.L0f0d4f64
/*  f0d4f50:	3c047f1b */ 	lui	$a0,%hi(var7f1adbb4)
/*  f0d4f54:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0d4f58:	10e10002 */ 	beq	$a3,$at,.L0f0d4f64
/*  f0d4f5c:	241f000a */ 	addiu	$ra,$zero,0xa
/*  f0d4f60:	14ff0013 */ 	bne	$a3,$ra,.L0f0d4fb0
.L0f0d4f64:
/*  f0d4f64:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0d4f68:	241f000a */ 	addiu	$ra,$zero,0xa
/*  f0d4f6c:	240503e8 */ 	addiu	$a1,$zero,0x3e8
/*  f0d4f70:	00005025 */ 	or	$t2,$zero,$zero
/*  f0d4f74:	240b1000 */ 	addiu	$t3,$zero,0x1000
/*  f0d4f78:	14e10006 */ 	bne	$a3,$at,.L0f0d4f94
/*  f0d4f7c:	46000406 */ 	mov.s	$f16,$f0
/*  f0d4f80:	3c014100 */ 	lui	$at,0x4100
/*  f0d4f84:	44818000 */ 	mtc1	$at,$f16
/*  f0d4f88:	240a0180 */ 	addiu	$t2,$zero,0x180
/*  f0d4f8c:	10000008 */ 	b	.L0f0d4fb0
/*  f0d4f90:	240b1180 */ 	addiu	$t3,$zero,0x1180
.L0f0d4f94:
/*  f0d4f94:	14ff0005 */ 	bne	$a3,$ra,.L0f0d4fac
/*  f0d4f98:	3c014100 */ 	lui	$at,0x4100
/*  f0d4f9c:	44818000 */ 	mtc1	$at,$f16
/*  f0d4fa0:	240a0180 */ 	addiu	$t2,$zero,0x180
/*  f0d4fa4:	10000002 */ 	b	.L0f0d4fb0
/*  f0d4fa8:	240b1180 */ 	addiu	$t3,$zero,0x1180
.L0f0d4fac:
/*  f0d4fac:	46001486 */ 	mov.s	$f18,$f2
.L0f0d4fb0:
/*  f0d4fb0:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0d4fb4:	14e10020 */ 	bne	$a3,$at,.L0f0d5038
/*  f0d4fb8:	2484dbb4 */ 	addiu	$a0,$a0,%lo(var7f1adbb4)
/*  f0d4fbc:	3c014100 */ 	lui	$at,0x4100
/*  f0d4fc0:	44818000 */ 	mtc1	$at,$f16
/*  f0d4fc4:	3c058007 */ 	lui	$a1,%hi(var80070f1c)
/*  f0d4fc8:	24a50f1c */ 	addiu	$a1,$a1,%lo(var80070f1c)
/*  f0d4fcc:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0d4fd0:	afa90050 */ 	sw	$t1,0x50($sp)
/*  f0d4fd4:	a7aa002e */ 	sh	$t2,0x2e($sp)
/*  f0d4fd8:	a7ab002c */ 	sh	$t3,0x2c($sp)
/*  f0d4fdc:	afac0048 */ 	sw	$t4,0x48($sp)
/*  f0d4fe0:	afad0058 */ 	sw	$t5,0x58($sp)
/*  f0d4fe4:	e7b20034 */ 	swc1	$f18,0x34($sp)
/*  f0d4fe8:	0c0036cc */ 	jal	func0000db30
/*  f0d4fec:	e7b00030 */ 	swc1	$f16,0x30($sp)
/*  f0d4ff0:	3c058007 */ 	lui	$a1,%hi(var80070f1c)
/*  f0d4ff4:	8ca50f1c */ 	lw	$a1,%lo(var80070f1c)($a1)
/*  f0d4ff8:	24190100 */ 	addiu	$t9,$zero,0x100
/*  f0d4ffc:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0d5000:	00052823 */ 	negu	$a1,$a1
/*  f0d5004:	00057c00 */ 	sll	$t7,$a1,0x10
/*  f0d5008:	8fa70064 */ 	lw	$a3,0x64($sp)
/*  f0d500c:	8fa90050 */ 	lw	$t1,0x50($sp)
/*  f0d5010:	87aa002e */ 	lh	$t2,0x2e($sp)
/*  f0d5014:	87ab002c */ 	lh	$t3,0x2c($sp)
/*  f0d5018:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f0d501c:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f0d5020:	241f000a */ 	addiu	$ra,$zero,0xa
/*  f0d5024:	c7b00030 */ 	lwc1	$f16,0x30($sp)
/*  f0d5028:	c7b20034 */ 	lwc1	$f18,0x34($sp)
/*  f0d502c:	000f2c03 */ 	sra	$a1,$t7,0x10
/*  f0d5030:	a7b9002a */ 	sh	$t9,0x2a($sp)
/*  f0d5034:	a7a00028 */ 	sh	$zero,0x28($sp)
.L0f0d5038:
/*  f0d5038:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f0d503c:	2408fff6 */ 	addiu	$t0,$zero,-10
/*  f0d5040:	a4c90002 */ 	sh	$t1,0x2($a2)
/*  f0d5044:	a4c80004 */ 	sh	$t0,0x4($a2)
/*  f0d5048:	a4ce0000 */ 	sh	$t6,0x0($a2)
/*  f0d504c:	8faf0054 */ 	lw	$t7,0x54($sp)
/*  f0d5050:	a4cd000e */ 	sh	$t5,0xe($a2)
/*  f0d5054:	a4c80010 */ 	sh	$t0,0x10($a2)
/*  f0d5058:	3c19800a */ 	lui	$t9,%hi(var8009de98)
/*  f0d505c:	a4cf000c */ 	sh	$t7,0xc($a2)
/*  f0d5060:	8f39de98 */ 	lw	$t9,%lo(var8009de98)($t9)
/*  f0d5064:	44852000 */ 	mtc1	$a1,$f4
/*  f0d5068:	2418000a */ 	addiu	$t8,$zero,0xa
/*  f0d506c:	44994000 */ 	mtc1	$t9,$f8
/*  f0d5070:	44983000 */ 	mtc1	$t8,$f6
/*  f0d5074:	3c0e800a */ 	lui	$t6,%hi(var8009de9c)
/*  f0d5078:	8dcede9c */ 	lw	$t6,%lo(var8009de9c)($t6)
/*  f0d507c:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0d5080:	84d9000c */ 	lh	$t9,0xc($a2)
/*  f0d5084:	01051023 */ 	subu	$v0,$t0,$a1
/*  f0d5088:	a4c2001c */ 	sh	$v0,0x1c($a2)
/*  f0d508c:	a4c20028 */ 	sh	$v0,0x28($a2)
/*  f0d5090:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d5094:	3c014280 */ 	lui	$at,0x4280
/*  f0d5098:	468030a0 */ 	cvt.s.w	$f2,$f6
/*  f0d509c:	448e3000 */ 	mtc1	$t6,$f6
/*  f0d50a0:	46005102 */ 	mul.s	$f4,$f10,$f0
/*  f0d50a4:	84ce0000 */ 	lh	$t6,0x0($a2)
/*  f0d50a8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0d50ac:	46022303 */ 	div.s	$f12,$f4,$f2
/*  f0d50b0:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0d50b4:	46025383 */ 	div.s	$f14,$f10,$f2
/*  f0d50b8:	4600610d */ 	trunc.w.s	$f4,$f12
/*  f0d50bc:	44032000 */ 	mfc1	$v1,$f4
/*  f0d50c0:	00000000 */ 	nop
/*  f0d50c4:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f0d50c8:	a4cf0018 */ 	sh	$t7,0x18($a2)
/*  f0d50cc:	84cf0002 */ 	lh	$t7,0x2($a2)
/*  f0d50d0:	03237021 */ 	addu	$t6,$t9,$v1
/*  f0d50d4:	a4ce0024 */ 	sh	$t6,0x24($a2)
/*  f0d50d8:	4600718d */ 	trunc.w.s	$f6,$f14
/*  f0d50dc:	44043000 */ 	mfc1	$a0,$f6
/*  f0d50e0:	00000000 */ 	nop
/*  f0d50e4:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f0d50e8:	84cf000e */ 	lh	$t7,0xe($a2)
/*  f0d50ec:	a4d8001a */ 	sh	$t8,0x1a($a2)
/*  f0d50f0:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f0d50f4:	14ff0012 */ 	bne	$a3,$ra,.L0f0d5140
/*  f0d50f8:	a4d80026 */ 	sh	$t8,0x26($a2)
/*  f0d50fc:	3c014280 */ 	lui	$at,0x4280
/*  f0d5100:	44811000 */ 	mtc1	$at,$f2
/*  f0d5104:	3c014200 */ 	lui	$at,0x4200
/*  f0d5108:	44816000 */ 	mtc1	$at,$f12
/*  f0d510c:	3c018006 */ 	lui	$at,%hi(var80061630)
/*  f0d5110:	c4201630 */ 	lwc1	$f0,%lo(var80061630)($at)
/*  f0d5114:	46120202 */ 	mul.s	$f8,$f0,$f18
/*  f0d5118:	00000000 */ 	nop
/*  f0d511c:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0d5120:	00000000 */ 	nop
/*  f0d5124:	460c5102 */ 	mul.s	$f4,$f10,$f12
/*  f0d5128:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d512c:	44093000 */ 	mfc1	$t1,$f6
/*  f0d5130:	00000000 */ 	nop
/*  f0d5134:	00097400 */ 	sll	$t6,$t1,0x10
/*  f0d5138:	10000014 */ 	b	.L0f0d518c
/*  f0d513c:	000e4c03 */ 	sra	$t1,$t6,0x10
.L0f0d5140:
/*  f0d5140:	44811000 */ 	mtc1	$at,$f2
/*  f0d5144:	3c014200 */ 	lui	$at,0x4200
/*  f0d5148:	44816000 */ 	mtc1	$at,$f12
/*  f0d514c:	3c018006 */ 	lui	$at,%hi(var80061630)
/*  f0d5150:	c4201630 */ 	lwc1	$f0,%lo(var80061630)($at)
/*  f0d5154:	3c013f00 */ 	lui	$at,0x3f00
/*  f0d5158:	44814000 */ 	mtc1	$at,$f8
/*  f0d515c:	00000000 */ 	nop
/*  f0d5160:	46080281 */ 	sub.s	$f10,$f0,$f8
/*  f0d5164:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f0d5168:	00000000 */ 	nop
/*  f0d516c:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f0d5170:	00000000 */ 	nop
/*  f0d5174:	460c3202 */ 	mul.s	$f8,$f6,$f12
/*  f0d5178:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0d517c:	44095000 */ 	mfc1	$t1,$f10
/*  f0d5180:	00000000 */ 	nop
/*  f0d5184:	0009cc00 */ 	sll	$t9,$t1,0x10
/*  f0d5188:	00194c03 */ 	sra	$t1,$t9,0x10
.L0f0d518c:
/*  f0d518c:	14ff0010 */ 	bne	$a3,$ra,.L0f0d51d0
/*  f0d5190:	01491021 */ 	addu	$v0,$t2,$t1
/*  f0d5194:	3c013f00 */ 	lui	$at,0x3f00
/*  f0d5198:	44812000 */ 	mtc1	$at,$f4
/*  f0d519c:	00000000 */ 	nop
/*  f0d51a0:	46040181 */ 	sub.s	$f6,$f0,$f4
/*  f0d51a4:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f0d51a8:	00000000 */ 	nop
/*  f0d51ac:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0d51b0:	00000000 */ 	nop
/*  f0d51b4:	460c5102 */ 	mul.s	$f4,$f10,$f12
/*  f0d51b8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d51bc:	44053000 */ 	mfc1	$a1,$f6
/*  f0d51c0:	00000000 */ 	nop
/*  f0d51c4:	0005c400 */ 	sll	$t8,$a1,0x10
/*  f0d51c8:	1000000b */ 	b	.L0f0d51f8
/*  f0d51cc:	00182c03 */ 	sra	$a1,$t8,0x10
.L0f0d51d0:
/*  f0d51d0:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f0d51d4:	00000000 */ 	nop
/*  f0d51d8:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0d51dc:	00000000 */ 	nop
/*  f0d51e0:	460c5102 */ 	mul.s	$f4,$f10,$f12
/*  f0d51e4:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d51e8:	44053000 */ 	mfc1	$a1,$f6
/*  f0d51ec:	00000000 */ 	nop
/*  f0d51f0:	00057c00 */ 	sll	$t7,$a1,0x10
/*  f0d51f4:	000f2c03 */ 	sra	$a1,$t7,0x10
.L0f0d51f8:
/*  f0d51f8:	a4c20008 */ 	sh	$v0,0x8($a2)
/*  f0d51fc:	87b9002a */ 	lh	$t9,0x2a($sp)
/*  f0d5200:	01692021 */ 	addu	$a0,$t3,$t1
/*  f0d5204:	a4c40014 */ 	sh	$a0,0x14($a2)
/*  f0d5208:	03251821 */ 	addu	$v1,$t9,$a1
/*  f0d520c:	a4c3000a */ 	sh	$v1,0xa($a2)
/*  f0d5210:	a4c30016 */ 	sh	$v1,0x16($a2)
/*  f0d5214:	a4c4002c */ 	sh	$a0,0x2c($a2)
/*  f0d5218:	87ae0028 */ 	lh	$t6,0x28($sp)
/*  f0d521c:	24010007 */ 	addiu	$at,$zero,0x7
/*  f0d5220:	a4c20020 */ 	sh	$v0,0x20($a2)
/*  f0d5224:	01c54021 */ 	addu	$t0,$t6,$a1
/*  f0d5228:	a4c8002e */ 	sh	$t0,0x2e($a2)
/*  f0d522c:	14e10007 */ 	bne	$a3,$at,.L0f0d524c
/*  f0d5230:	a4c80022 */ 	sh	$t0,0x22($a2)
/*  f0d5234:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f0d5238:	a0c00007 */ 	sb	$zero,0x7($a2)
/*  f0d523c:	a0c00013 */ 	sb	$zero,0x13($a2)
/*  f0d5240:	a0c2001f */ 	sb	$v0,0x1f($a2)
/*  f0d5244:	10000006 */ 	b	.L0f0d5260
/*  f0d5248:	a0c2002b */ 	sb	$v0,0x2b($a2)
.L0f0d524c:
/*  f0d524c:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f0d5250:	a0c00007 */ 	sb	$zero,0x7($a2)
/*  f0d5254:	a0c20013 */ 	sb	$v0,0x13($a2)
/*  f0d5258:	a0c0001f */ 	sb	$zero,0x1f($a2)
/*  f0d525c:	a0c2002b */ 	sb	$v0,0x2b($a2)
.L0f0d5260:
/*  f0d5260:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f0d5264:	8faf005c */ 	lw	$t7,0x5c($sp)
/*  f0d5268:	3c190704 */ 	lui	$t9,0x704
/*  f0d526c:	37390008 */ 	ori	$t9,$t9,0x8
/*  f0d5270:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f0d5274:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0d5278:	01801825 */ 	or	$v1,$t4,$zero
/*  f0d527c:	258c0008 */ 	addiu	$t4,$t4,0x8
/*  f0d5280:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f0d5284:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f0d5288:	afac0048 */ 	sw	$t4,0x48($sp)
/*  f0d528c:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0d5290:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0d5294:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f0d5298:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f0d529c:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f0d52a0:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f0d52a4:	3c0e0430 */ 	lui	$t6,0x430
/*  f0d52a8:	35ce0030 */ 	ori	$t6,$t6,0x30
/*  f0d52ac:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f0d52b0:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f0d52b4:	24ac0008 */ 	addiu	$t4,$a1,0x8
/*  f0d52b8:	afac0048 */ 	sw	$t4,0x48($sp)
/*  f0d52bc:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0d52c0:	afa50018 */ 	sw	$a1,0x18($sp)
/*  f0d52c4:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f0d52c8:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f0d52cc:	3c0fb100 */ 	lui	$t7,0xb100
/*  f0d52d0:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0d52d4:	35ef0003 */ 	ori	$t7,$t7,0x3
/*  f0d52d8:	24182310 */ 	addiu	$t8,$zero,0x2310
/*  f0d52dc:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f0d52e0:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f0d52e4:	24620008 */ 	addiu	$v0,$v1,0x8
.L0f0d52e8:
/*  f0d52e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0d52ec:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f0d52f0:	03e00008 */ 	jr	$ra
/*  f0d52f4:	00000000 */ 	nop
);

/**
 * Write the specified amount of bits to the buffer, advancing the internal pointer.
 *
 * numbits is expected to be 32 or less.
 *
 * This function only sets bits to on and does not unset them.
 */
void savebufferOr(struct savebuffer *buffer, u32 value, s32 numbits)
{
	u32 bit = 1 << (numbits + 31);

	for (; bit; bit >>= 1) {
		if (bit & value) {
			s32 bitindex = buffer->bitpos % 8;
			u8 mask = 1 << (7 - bitindex);
			s32 byteindex = buffer->bitpos / 8;

			buffer->bytes[byteindex] |= mask;
		}

		buffer->bitpos++;
	}
}

#if VERSION >= VERSION_NTSC_1_0
/**
 * Write the specified amount of bits to the buffer, advancing the internal pointer.
 *
 * numbits is expected to be 32 or less.
 */
void savebufferWriteBits(struct savebuffer *buffer, u32 value, s32 numbits, u8 *dst)
{
	u32 bit = 1 << (numbits + 31);

	for (; bit; bit >>= 1) {
		s32 bitindex = buffer->bitpos % 8;
		u8 mask = 1 << (7 - bitindex);
		s32 byteindex = buffer->bitpos / 8;

		if (bit & value) {
			dst[byteindex] |= mask;
		} else {
			dst[byteindex] &= ~mask;
		}

		buffer->bitpos++;
	}
}
#endif

/**
 * Read the specified amount of bits from the buffer and return it as an
 * integer, advancing the internal pointer.
 *
 * numbits is expected to be 32 or less.
 */
u32 savebufferReadBits(struct savebuffer *buffer, s32 numbits)
{
	u32 bit = 1 << (numbits + 31);
	u32 value = 0;

	for (; bit; bit >>= 1) {
		s32 bitindex = buffer->bitpos % 8;
		u8 mask = 1 << (7 - bitindex);
		s32 byteindex = buffer->bitpos / 8;

		if (buffer->bytes[byteindex] & mask) {
			value |= bit;
		}

		buffer->bitpos++;
	}

	return value;
}

void savebufferClear(struct savebuffer *buffer)
{
	s32 i;

	buffer->bitpos = 0;

	for (i = 0; i < sizeof(buffer->bytes);) {
		buffer->bytes[i] = 0;
		i++;
	}
}

void func0f0d5484(struct savebuffer *buffer, u8 *data, u8 len)
{
	s32 i;

	buffer->bitpos = 0;

	for (i = 0; i < len; i++) {
		buffer->bytes[i] = data[i];
	}
}

void func0f0d54c4(struct savebuffer *buffer)
{
	s32 tmp = buffer->bitpos;

	if (tmp / 8 && buffer->bitpos);
}

/**
 * Read a zero-terminated string from the buffer and move the buffer's internal
 * pointer past the end of the string.
 */
void savebufferReadString(struct savebuffer *buffer, char *dst, bool addlinebreak)
{
	bool foundnull = false;
	s32 index = 0;
	s32 i;

	for (i = 0; i < 10; i++) {
		s32 byte = savebufferReadBits(buffer, 8);

		if (!foundnull) {
			if (byte == '\0') {
				foundnull = true;
			} else {
				dst[i] = byte;
				index = i;
			}
		}
	}

	if (addlinebreak) {
		index++;
		dst[index] = '\n';
	}

	index++;
	dst[index] = '\0';
}

GLOBAL_ASM(
glabel func0f0d55a4
/*  f0d55a4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0d55a8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0d55ac:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0d55b0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0d55b4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0d55b8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0d55bc:	00809025 */ 	or	$s2,$a0,$zero
/*  f0d55c0:	00a0a025 */ 	or	$s4,$a1,$zero
/*  f0d55c4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0d55c8:	00008025 */ 	or	$s0,$zero,$zero
/*  f0d55cc:	00008825 */ 	or	$s1,$zero,$zero
/*  f0d55d0:	2413000a */ 	addiu	$s3,$zero,0xa
.L0f0d55d4:
/*  f0d55d4:	1600000d */ 	bnez	$s0,.L0f0d560c
/*  f0d55d8:	02917021 */ 	addu	$t6,$s4,$s1
/*  f0d55dc:	91c20000 */ 	lbu	$v0,0x0($t6)
/*  f0d55e0:	14400003 */ 	bnez	$v0,.L0f0d55f0
/*  f0d55e4:	00401825 */ 	or	$v1,$v0,$zero
/*  f0d55e8:	10000008 */ 	b	.L0f0d560c
/*  f0d55ec:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0d55f0:
/*  f0d55f0:	16630003 */ 	bne	$s3,$v1,.L0f0d5600
/*  f0d55f4:	00402825 */ 	or	$a1,$v0,$zero
/*  f0d55f8:	10000004 */ 	b	.L0f0d560c
/*  f0d55fc:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0d5600:
/*  f0d5600:	02402025 */ 	or	$a0,$s2,$zero
/*  f0d5604:	0fc354be */ 	jal	savebufferOr
/*  f0d5608:	24060008 */ 	addiu	$a2,$zero,0x8
.L0f0d560c:
/*  f0d560c:	12000004 */ 	beqz	$s0,.L0f0d5620
/*  f0d5610:	02402025 */ 	or	$a0,$s2,$zero
/*  f0d5614:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d5618:	0fc354be */ 	jal	savebufferOr
/*  f0d561c:	24060008 */ 	addiu	$a2,$zero,0x8
.L0f0d5620:
/*  f0d5620:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0d5624:	1633ffeb */ 	bne	$s1,$s3,.L0f0d55d4
/*  f0d5628:	00000000 */ 	nop
/*  f0d562c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0d5630:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0d5634:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0d5638:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0d563c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0d5640:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0d5644:	03e00008 */ 	jr	$ra
/*  f0d5648:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

// Mismatch: Goal uses both v0 and v1 for src[i] and c, but in some weird way.
//void func0f0d55a4(struct savebuffer *buffer, char *src)
//{
//	bool done = false;
//	s32 i;
//
//	for (i = 0; i < 10; i++) {
//		if (!done) {
//			char c = src[i];
//
//			if (c == '\0') {
//				done = true;
//			} else if (src[i] == '\n') {
//				done = true;
//			} else {
//				savebufferOr(buffer, c, 8);
//			}
//		}
//
//		if (done) {
//			savebufferOr(buffer, 0, 8);
//		}
//	}
//}

void func0f0d564c(u8 *data, char *dst, bool addlinebreak)
{
	struct savebuffer buffer;

	func0f0d5484(&buffer, data, 10);
	savebufferReadString(&buffer, dst, addlinebreak);
}

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f0d5690
/*  f0d5690:	27bdfed8 */ 	addiu	$sp,$sp,-296
/*  f0d5694:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0d5698:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0d569c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0d56a0:	00809025 */ 	or	$s2,$a0,$zero
/*  f0d56a4:	27b30048 */ 	addiu	$s3,$sp,0x48
/*  f0d56a8:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f0d56ac:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0d56b0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0d56b4:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0d56b8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0d56bc:	00008025 */ 	or	$s0,$zero,$zero
/*  f0d56c0:	02402825 */ 	or	$a1,$s2,$zero
/*  f0d56c4:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d56c8:	0fc35521 */ 	jal	func0f0d5484
/*  f0d56cc:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f0d56d0:	00008825 */ 	or	$s1,$zero,$zero
/*  f0d56d4:	2414000a */ 	addiu	$s4,$zero,0xa
.L0f0d56d8:
/*  f0d56d8:	1600000e */ 	bnez	$s0,.L0f0d5714
/*  f0d56dc:	02b17021 */ 	addu	$t6,$s5,$s1
/*  f0d56e0:	91c20000 */ 	lbu	$v0,0x0($t6)
/*  f0d56e4:	14400003 */ 	bnez	$v0,.L0f0d56f4
/*  f0d56e8:	00401825 */ 	or	$v1,$v0,$zero
/*  f0d56ec:	10000009 */ 	b	.L0f0d5714
/*  f0d56f0:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0d56f4:
/*  f0d56f4:	16830003 */ 	bne	$s4,$v1,.L0f0d5704
/*  f0d56f8:	00402825 */ 	or	$a1,$v0,$zero
/*  f0d56fc:	10000005 */ 	b	.L0f0d5714
/*  f0d5700:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0d5704:
/*  f0d5704:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d5708:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f0d570c:	0fc354d8 */ 	jal	savebufferWriteBits
/*  f0d5710:	02403825 */ 	or	$a3,$s2,$zero
.L0f0d5714:
/*  f0d5714:	12000005 */ 	beqz	$s0,.L0f0d572c
/*  f0d5718:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d571c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d5720:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f0d5724:	0fc354d8 */ 	jal	savebufferWriteBits
/*  f0d5728:	02403825 */ 	or	$a3,$s2,$zero
.L0f0d572c:
/*  f0d572c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0d5730:	1634ffe9 */ 	bne	$s1,$s4,.L0f0d56d8
/*  f0d5734:	00000000 */ 	nop
/*  f0d5738:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0d573c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0d5740:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0d5744:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0d5748:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0d574c:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0d5750:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0d5754:	03e00008 */ 	jr	$ra
/*  f0d5758:	27bd0128 */ 	addiu	$sp,$sp,0x128
);

// Mismatch: Goal uses both v0 and v1 for src[i] and c, but in some weird way.
//void func0f0d5690(u8 *dst, char *src)
//{
//	struct savebuffer buffer;
//	bool done = false;
//	s32 i;
//	char c;
//	s32 v1;
//
//	func0f0d5484(&buffer, arg0, 10);
//
//	for (i = 0; i < 10; i++) {
//		if (!done) {
//			c = src[i];
//
//			if (src[i] == '\0') {
//				done = true;
//			} else if (c == '\n') {
//				done = true;
//			} else {
//				savebufferWriteBits(&buffer, c, 8, dst);
//			}
//		}
//
//		if (done) {
//			savebufferWriteBits(&buffer, '\0', 8, dst);
//		}
//	}
//}
#endif

void func0f0d575c(struct savebuffer *buffer, u32 *arg1)
{
	savebufferOr(buffer, *(s32 *) arg1, 7);
	savebufferOr(buffer, *(u16 *) (arg1 + 1), 13);
}

void func0f0d579c(struct savebuffer *buffer, u32 *arg1)
{
	*(s32 *) arg1 = savebufferReadBits(buffer, 7);
	*(u16 *) (arg1 + 1) = savebufferReadBits(buffer, 13);
}

GLOBAL_ASM(
glabel formatTime
/*  f0d57e0:	2402003c */ 	addiu	$v0,$zero,0x3c
/*  f0d57e4:	00a2001a */ 	div	$zero,$a1,$v0
/*  f0d57e8:	00007010 */ 	mfhi	$t6
/*  f0d57ec:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0d57f0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0d57f4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0d57f8:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0d57fc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0d5800:	01e2001a */ 	div	$zero,$t7,$v0
/*  f0d5804:	0000c012 */ 	mflo	$t8
/*  f0d5808:	240a0018 */ 	addiu	$t2,$zero,0x18
/*  f0d580c:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f0d5810:	00a2001a */ 	div	$zero,$a1,$v0
/*  f0d5814:	00001812 */ 	mflo	$v1
/*  f0d5818:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f0d581c:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f0d5820:	0062001a */ 	div	$zero,$v1,$v0
/*  f0d5824:	00003812 */ 	mflo	$a3
/*  f0d5828:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f0d582c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0d5830:	00e2001a */ 	div	$zero,$a3,$v0
/*  f0d5834:	00004012 */ 	mflo	$t0
/*  f0d5838:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0d583c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0d5840:	010a001a */ 	div	$zero,$t0,$t2
/*  f0d5844:	0000c812 */ 	mflo	$t9
/*  f0d5848:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0d584c:	00809825 */ 	or	$s3,$a0,$zero
/*  f0d5850:	0062001a */ 	div	$zero,$v1,$v0
/*  f0d5854:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0d5858:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f0d585c:	00009025 */ 	or	$s2,$zero,$zero
/*  f0d5860:	00008025 */ 	or	$s0,$zero,$zero
/*  f0d5864:	14400002 */ 	bnez	$v0,.L0f0d5870
/*  f0d5868:	00000000 */ 	nop
/*  f0d586c:	0007000d */ 	break	0x7
.L0f0d5870:
/*  f0d5870:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d5874:	14410004 */ 	bne	$v0,$at,.L0f0d5888
/*  f0d5878:	3c018000 */ 	lui	$at,0x8000
/*  f0d587c:	14a10002 */ 	bne	$a1,$at,.L0f0d5888
/*  f0d5880:	00000000 */ 	nop
/*  f0d5884:	0006000d */ 	break	0x6
.L0f0d5888:
/*  f0d5888:	afb80064 */ 	sw	$t8,0x64($sp)
/*  f0d588c:	14400002 */ 	bnez	$v0,.L0f0d5898
/*  f0d5890:	00000000 */ 	nop
/*  f0d5894:	0007000d */ 	break	0x7
.L0f0d5898:
/*  f0d5898:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d589c:	14410004 */ 	bne	$v0,$at,.L0f0d58b0
/*  f0d58a0:	3c018000 */ 	lui	$at,0x8000
/*  f0d58a4:	15e10002 */ 	bne	$t7,$at,.L0f0d58b0
/*  f0d58a8:	00000000 */ 	nop
/*  f0d58ac:	0006000d */ 	break	0x6
.L0f0d58b0:
/*  f0d58b0:	afb90054 */ 	sw	$t9,0x54($sp)
/*  f0d58b4:	14400002 */ 	bnez	$v0,.L0f0d58c0
/*  f0d58b8:	00000000 */ 	nop
/*  f0d58bc:	0007000d */ 	break	0x7
.L0f0d58c0:
/*  f0d58c0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d58c4:	14410004 */ 	bne	$v0,$at,.L0f0d58d8
/*  f0d58c8:	3c018000 */ 	lui	$at,0x8000
/*  f0d58cc:	14a10002 */ 	bne	$a1,$at,.L0f0d58d8
/*  f0d58d0:	00000000 */ 	nop
/*  f0d58d4:	0006000d */ 	break	0x6
.L0f0d58d8:
/*  f0d58d8:	27b10054 */ 	addiu	$s1,$sp,0x54
/*  f0d58dc:	14400002 */ 	bnez	$v0,.L0f0d58e8
/*  f0d58e0:	00000000 */ 	nop
/*  f0d58e4:	0007000d */ 	break	0x7
.L0f0d58e8:
/*  f0d58e8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d58ec:	14410004 */ 	bne	$v0,$at,.L0f0d5900
/*  f0d58f0:	3c018000 */ 	lui	$at,0x8000
/*  f0d58f4:	14610002 */ 	bne	$v1,$at,.L0f0d5900
/*  f0d58f8:	00000000 */ 	nop
/*  f0d58fc:	0006000d */ 	break	0x6
.L0f0d5900:
/*  f0d5900:	3c147f1b */ 	lui	$s4,%hi(var7f1adbbc)
/*  f0d5904:	14400002 */ 	bnez	$v0,.L0f0d5910
/*  f0d5908:	00000000 */ 	nop
/*  f0d590c:	0007000d */ 	break	0x7
.L0f0d5910:
/*  f0d5910:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d5914:	14410004 */ 	bne	$v0,$at,.L0f0d5928
/*  f0d5918:	3c018000 */ 	lui	$at,0x8000
/*  f0d591c:	14e10002 */ 	bne	$a3,$at,.L0f0d5928
/*  f0d5920:	00000000 */ 	nop
/*  f0d5924:	0006000d */ 	break	0x6
.L0f0d5928:
/*  f0d5928:	27b5005c */ 	addiu	$s5,$sp,0x5c
/*  f0d592c:	15400002 */ 	bnez	$t2,.L0f0d5938
/*  f0d5930:	00000000 */ 	nop
/*  f0d5934:	0007000d */ 	break	0x7
.L0f0d5938:
/*  f0d5938:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d593c:	15410004 */ 	bne	$t2,$at,.L0f0d5950
/*  f0d5940:	3c018000 */ 	lui	$at,0x8000
/*  f0d5944:	15010002 */ 	bne	$t0,$at,.L0f0d5950
/*  f0d5948:	00000000 */ 	nop
/*  f0d594c:	0006000d */ 	break	0x6
.L0f0d5950:
/*  f0d5950:	3c167f1b */ 	lui	$s6,%hi(var7f1adbc4)
/*  f0d5954:	14400002 */ 	bnez	$v0,.L0f0d5960
/*  f0d5958:	00000000 */ 	nop
/*  f0d595c:	0007000d */ 	break	0x7
.L0f0d5960:
/*  f0d5960:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d5964:	14410004 */ 	bne	$v0,$at,.L0f0d5978
/*  f0d5968:	3c018000 */ 	lui	$at,0x8000
/*  f0d596c:	14610002 */ 	bne	$v1,$at,.L0f0d5978
/*  f0d5970:	00000000 */ 	nop
/*  f0d5974:	0006000d */ 	break	0x6
.L0f0d5978:
/*  f0d5978:	00001810 */ 	mfhi	$v1
/*  f0d597c:	afa30060 */ 	sw	$v1,0x60($sp)
/*  f0d5980:	27ad0054 */ 	addiu	$t5,$sp,0x54
/*  f0d5984:	00e2001a */ 	div	$zero,$a3,$v0
/*  f0d5988:	14400002 */ 	bnez	$v0,.L0f0d5994
/*  f0d598c:	00000000 */ 	nop
/*  f0d5990:	0007000d */ 	break	0x7
.L0f0d5994:
/*  f0d5994:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d5998:	14410004 */ 	bne	$v0,$at,.L0f0d59ac
/*  f0d599c:	3c018000 */ 	lui	$at,0x8000
/*  f0d59a0:	14e10002 */ 	bne	$a3,$at,.L0f0d59ac
/*  f0d59a4:	00000000 */ 	nop
/*  f0d59a8:	0006000d */ 	break	0x6
.L0f0d59ac:
/*  f0d59ac:	00003810 */ 	mfhi	$a3
/*  f0d59b0:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f0d59b4:	00004825 */ 	or	$t1,$zero,$zero
/*  f0d59b8:	010a001a */ 	div	$zero,$t0,$t2
/*  f0d59bc:	15400002 */ 	bnez	$t2,.L0f0d59c8
/*  f0d59c0:	00000000 */ 	nop
/*  f0d59c4:	0007000d */ 	break	0x7
.L0f0d59c8:
/*  f0d59c8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d59cc:	15410004 */ 	bne	$t2,$at,.L0f0d59e0
/*  f0d59d0:	3c018000 */ 	lui	$at,0x8000
/*  f0d59d4:	15010002 */ 	bne	$t0,$at,.L0f0d59e0
/*  f0d59d8:	00000000 */ 	nop
/*  f0d59dc:	0006000d */ 	break	0x6
.L0f0d59e0:
/*  f0d59e0:	00004010 */ 	mfhi	$t0
/*  f0d59e4:	afa80058 */ 	sw	$t0,0x58($sp)
/*  f0d59e8:	04c00019 */ 	bltz	$a2,.L0f0d5a50
/*  f0d59ec:	00065880 */ 	sll	$t3,$a2,0x2
/*  f0d59f0:	256c0004 */ 	addiu	$t4,$t3,0x4
/*  f0d59f4:	018db821 */ 	addu	$s7,$t4,$t5
/*  f0d59f8:	26d6dbc4 */ 	addiu	$s6,$s6,%lo(var7f1adbc4)
/*  f0d59fc:	2694dbbc */ 	addiu	$s4,$s4,%lo(var7f1adbbc)
.L0f0d5a00:
/*  f0d5a00:	12400006 */ 	beqz	$s2,.L0f0d5a1c
/*  f0d5a04:	02702021 */ 	addu	$a0,$s3,$s0
/*  f0d5a08:	02802825 */ 	or	$a1,$s4,$zero
/*  f0d5a0c:	0c004dad */ 	jal	sprintf
/*  f0d5a10:	8e260000 */ 	lw	$a2,0x0($s1)
/*  f0d5a14:	1000000b */ 	b	.L0f0d5a44
/*  f0d5a18:	02028021 */ 	addu	$s0,$s0,$v0
.L0f0d5a1c:
/*  f0d5a1c:	8e260000 */ 	lw	$a2,0x0($s1)
/*  f0d5a20:	0235082b */ 	sltu	$at,$s1,$s5
/*  f0d5a24:	02702021 */ 	addu	$a0,$s3,$s0
/*  f0d5a28:	14c00003 */ 	bnez	$a2,.L0f0d5a38
/*  f0d5a2c:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0d5a30:	54200005 */ 	bnezl	$at,.L0f0d5a48
/*  f0d5a34:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f0d5a38:
/*  f0d5a38:	0c004dad */ 	jal	sprintf
/*  f0d5a3c:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0d5a40:	02028021 */ 	addu	$s0,$s0,$v0
.L0f0d5a44:
/*  f0d5a44:	26310004 */ 	addiu	$s1,$s1,0x4
.L0f0d5a48:
/*  f0d5a48:	16f1ffed */ 	bne	$s7,$s1,.L0f0d5a00
/*  f0d5a4c:	00000000 */ 	nop
.L0f0d5a50:
/*  f0d5a50:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0d5a54:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0d5a58:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0d5a5c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0d5a60:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0d5a64:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f0d5a68:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f0d5a6c:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f0d5a70:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f0d5a74:	03e00008 */ 	jr	$ra
/*  f0d5a78:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

#if VERSION >= VERSION_NTSC_1_0
void func0f0d5a7c(void)
{
	var80070f10 = 0;
}
#endif
