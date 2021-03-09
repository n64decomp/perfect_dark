#include <ultra64.h>
#include "constants.h"
#include "game/game_006900.h"
#include "game/game_0d4690.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/lang.h"
#include "gvars/gvars.h"
#include "lib/lib_09a80.h"
#include "lib/dma.h"
#include "lib/main.h"
#include "lib/memory.h"
#include "data.h"
#include "types.h"

const char var7f1b73b0[] = "burncol";
const char var7f1b73b8[] = "sbrd";
const char var7f1b73c0[] = "lalpha";
const char var7f1b73c8[] = "subtlety";
const char var7f1b73d4[] = "subtletx";
const char var7f1b73e0[] = "coly";
const char var7f1b73e8[] = "colx";
const char var7f1b73f0[] = "lfade";
const char var7f1b73f8[] = "llimbo";

const u32 var7f1b7400[] = {0x453b8000};
const u32 var7f1b7404[] = {0x453b8000};

struct var800a45d0 var800a45d0;
Gfx *var800a4634;
u32 var800a4638;
u32 var800a463c;

s32 g_ScaleX = 1;
u32 var8007fac4 = 0x00000000;
u32 var8007fac8 = 0x00000000;
u32 var8007facc = 0x00000000;
u32 var8007fad0 = 0x00000001;
u32 var8007fad4 = 0xffffffff;
u32 var8007fad8 = 0x00000000;
u32 var8007fadc = 0x00000000;
u32 var8007fae0 = 0x00000000;
u32 var8007fae4 = 0x00000000;
u32 var8007fae8 = 0x00000000;
u32 var8007faec = 0x00000000;
u32 var8007faf0 = 0x00000000;

struct font *g_FontTahoma2 = NULL;
struct font2a4 *g_FontTahoma1 = NULL;
struct font *g_FontNumeric2 = NULL;
struct font2a4 *g_FontNumeric1 = NULL;
struct font *g_FontHandelGothicXs2 = NULL;
struct font2a4 *g_FontHandelGothicXs1 = NULL;
struct font *g_FontHandelGothicSm2 = NULL;
struct font2a4 *g_FontHandelGothicSm1 = NULL;
struct font *g_FontHandelGothicMd2 = NULL;
struct font2a4 *g_FontHandelGothicMd1 = NULL;
struct font *g_FontHandelGothicLg2 = NULL;
struct font2a4 *g_FontHandelGothicLg1 = NULL;

u32 var8007fb24 = 0x00000000;
u32 var8007fb28 = 0x00000000;
u32 var8007fb2c = 0x00000000;
u32 var8007fb30 = 0x00000000;
u32 var8007fb34 = 0x00000000;
u32 var8007fb38 = 0x00000000;
u32 var8007fb3c = 0xff00ff00;
u32 var8007fb40 = 0xff00ff00;
u32 var8007fb44 = 0xff00ff00;
u32 var8007fb48 = 0xff00ff00;
u32 var8007fb4c = 0xff00ff24;
u32 var8007fb50 = 0xff48ff6c;
u32 var8007fb54 = 0xff90ffb4;
u32 var8007fb58 = 0xffd8ffff;
u32 var8007fb5c = 0xff00ff58;
u32 var8007fb60 = 0xff74ff90;
u32 var8007fb64 = 0xffacffc8;
u32 var8007fb68 = 0xffe4ffff;
u32 var8007fb6c = 0xffffffff;
u32 var8007fb70 = 0xffffffff;
u32 var8007fb74 = 0xffffffff;
u32 var8007fb78 = 0xffffffff;
u32 var8007fb7c = 0xff00ff00;
u32 var8007fb80 = 0xff00ff00;
u32 var8007fb84 = 0xff00ff00;
u32 var8007fb88 = 0xff00ff00;
u32 var8007fb8c = 0xff00ff18;
u32 var8007fb90 = 0xff30ff5c;
u32 var8007fb94 = 0xff88ffb4;
u32 var8007fb98 = 0xffd8ffff;
u32 var8007fb9c = 0x00000000;
s32 var8007fba0 = 0;
s32 var8007fba4 = -1;
u32 var8007fba8 = 0x00000000;
u32 var8007fbac = 0x00000001;
u32 var8007fbb0 = 0x00000064;
u32 var8007fbb4 = 0x0000002c;
u32 var8007fbb8 = 0x00000080;
u32 var8007fbbc = 0x0000003c;
u32 var8007fbc0 = 0x44444400;
u32 var8007fbc4 = 0xffffff00;
u32 var8007fbc8 = 0xffffff00;
u32 var8007fbcc = 0x00000c0b;
u32 var8007fbd0 = 0x00000000;
u32 var8007fbd4 = 0x00000000;
u32 var8007fbd8 = 0x00000000;
u32 var8007fbdc = 0x00000c0b;
u32 var8007fbe0 = 0x00000000;
u32 var8007fbe4 = 0x00000000;
u32 var8007fbe8 = 0x00000000;
u32 var8007fbec = 0x00000c0b;
u32 var8007fbf0 = 0x00000000;
u32 var8007fbf4 = 0x00000000;
u32 var8007fbf8 = 0x00000000;
u32 var8007fbfc = 0x00000000;

void func0f1531a0(void)
{
	// empty
}

GLOBAL_ASM(
glabel func0f1531a8
/*  f1531a8:	00047023 */ 	negu	$t6,$a0
/*  f1531ac:	3c018008 */ 	lui	$at,%hi(var8007fac4)
/*  f1531b0:	03e00008 */ 	jr	$ra
/*  f1531b4:	ac2efac4 */ 	sw	$t6,%lo(var8007fac4)($at)
);

GLOBAL_ASM(
glabel func0f1531b8
/*  f1531b8:	3c018008 */ 	lui	$at,%hi(var8007fac8)
/*  f1531bc:	03e00008 */ 	jr	$ra
/*  f1531c0:	ac24fac8 */ 	sw	$a0,%lo(var8007fac8)($at)
/*  f1531c4:	3c018008 */ 	lui	$at,%hi(var8007facc)
/*  f1531c8:	03e00008 */ 	jr	$ra
/*  f1531cc:	ac24facc */ 	sw	$a0,%lo(var8007facc)($at)
/*  f1531d0:	3c018008 */ 	lui	$at,%hi(var8007fad4)
/*  f1531d4:	03e00008 */ 	jr	$ra
/*  f1531d8:	ac24fad4 */ 	sw	$a0,%lo(var8007fad4)($at)
);

void func0f1531dc(bool arg0)
{
	if (arg0) {
		var8007fad0 = 2;
	} else {
		var8007fad0 = 1;
	}
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel fontLoad
/*  f153eb4:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f153eb8:	3c0e007e */ 	lui	$t6,0x7e
/*  f153ebc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f153ec0:	25ce5530 */ 	addiu	$t6,$t6,0x5530
/*  f153ec4:	00808025 */ 	move	$s0,$a0
/*  f153ec8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f153ecc:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f153ed0:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f153ed4:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f153ed8:	108e0008 */ 	beq	$a0,$t6,.PF0f153efc
/*  f153edc:	2408005e */ 	li	$t0,0x5e
/*  f153ee0:	3c0f007f */ 	lui	$t7,0x7f
/*  f153ee4:	25ef87b0 */ 	addiu	$t7,$t7,-30800
/*  f153ee8:	108f0004 */ 	beq	$a0,$t7,.PF0f153efc
/*  f153eec:	3c18007f */ 	lui	$t8,0x7f
/*  f153ef0:	2718ae20 */ 	addiu	$t8,$t8,-20960
/*  f153ef4:	54980003 */ 	bnel	$a0,$t8,.PF0f153f04
/*  f153ef8:	8fb90044 */ 	lw	$t9,0x44($sp)
.PF0f153efc:
/*  f153efc:	24080087 */ 	li	$t0,0x87
/*  f153f00:	8fb90044 */ 	lw	$t9,0x44($sp)
.PF0f153f04:
/*  f153f04:	24050004 */ 	li	$a1,0x4
/*  f153f08:	afa80028 */ 	sw	$t0,0x28($sp)
/*  f153f0c:	03303023 */ 	subu	$a2,$t9,$s0
/*  f153f10:	00c02025 */ 	move	$a0,$a2
/*  f153f14:	0c004856 */ 	jal	0x12158
/*  f153f18:	afa60024 */ 	sw	$a2,0x24($sp)
/*  f153f1c:	244902a4 */ 	addiu	$t1,$v0,0x2a4
/*  f153f20:	8fa60024 */ 	lw	$a2,0x24($sp)
/*  f153f24:	afa9002c */ 	sw	$t1,0x2c($sp)
/*  f153f28:	00402025 */ 	move	$a0,$v0
/*  f153f2c:	02002825 */ 	move	$a1,$s0
/*  f153f30:	0c003454 */ 	jal	0xd150
/*  f153f34:	afa20030 */ 	sw	$v0,0x30($sp)
/*  f153f38:	8fa80028 */ 	lw	$t0,0x28($sp)
/*  f153f3c:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f153f40:	8fa9002c */ 	lw	$t1,0x2c($sp)
/*  f153f44:	19000008 */ 	blez	$t0,.PF0f153f68
/*  f153f48:	00001825 */ 	move	$v1,$zero
/*  f153f4c:	01201025 */ 	move	$v0,$t1
.PF0f153f50:
/*  f153f50:	8c4a0008 */ 	lw	$t2,0x8($v0)
/*  f153f54:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f153f58:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f153f5c:	01475821 */ 	addu	$t3,$t2,$a3
/*  f153f60:	1468fffb */ 	bne	$v1,$t0,.PF0f153f50
/*  f153f64:	ac4bfffc */ 	sw	$t3,-0x4($v0)
.PF0f153f68:
/*  f153f68:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f153f6c:	00002825 */ 	move	$a1,$zero
/*  f153f70:	3c0e007e */ 	lui	$t6,0x7e
/*  f153f74:	11800014 */ 	beqz	$t4,.PF0f153fc8
/*  f153f78:	3c0f007f */ 	lui	$t7,0x7f
/*  f153f7c:	1900000b */ 	blez	$t0,.PF0f153fac
/*  f153f80:	00001825 */ 	move	$v1,$zero
/*  f153f84:	01201025 */ 	move	$v0,$t1
.PF0f153f88:
/*  f153f88:	90440003 */ 	lbu	$a0,0x3($v0)
/*  f153f8c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f153f90:	00a4082a */ 	slt	$at,$a1,$a0
/*  f153f94:	10200002 */ 	beqz	$at,.PF0f153fa0
/*  f153f98:	00000000 */ 	nop
/*  f153f9c:	00802825 */ 	move	$a1,$a0
.PF0f153fa0:
/*  f153fa0:	1468fff9 */ 	bne	$v1,$t0,.PF0f153f88
/*  f153fa4:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f153fa8:	00001825 */ 	move	$v1,$zero
.PF0f153fac:
/*  f153fac:	19000006 */ 	blez	$t0,.PF0f153fc8
/*  f153fb0:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f153fb4:	01201025 */ 	move	$v0,$t1
.PF0f153fb8:
/*  f153fb8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f153fbc:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f153fc0:	1468fffd */ 	bne	$v1,$t0,.PF0f153fb8
/*  f153fc4:	a045fff7 */ 	sb	$a1,-0x9($v0)
.PF0f153fc8:
/*  f153fc8:	8fad0048 */ 	lw	$t5,0x48($sp)
/*  f153fcc:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f153fd0:	25ce5530 */ 	addiu	$t6,$t6,0x5530
/*  f153fd4:	ada70000 */ 	sw	$a3,0x0($t5)
/*  f153fd8:	120e0007 */ 	beq	$s0,$t6,.PF0f153ff8
/*  f153fdc:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f153fe0:	25ef87b0 */ 	addiu	$t7,$t7,-30800
/*  f153fe4:	120f0004 */ 	beq	$s0,$t7,.PF0f153ff8
/*  f153fe8:	3c18007f */ 	lui	$t8,0x7f
/*  f153fec:	2718ae20 */ 	addiu	$t8,$t8,-20960
/*  f153ff0:	56180006 */ 	bnel	$s0,$t8,.PF0f15400c
/*  f153ff4:	8fbf001c */ 	lw	$ra,0x1c($sp)
.PF0f153ff8:
/*  f153ff8:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f153ffc:	80590445 */ 	lb	$t9,0x445($v0)
/*  f154000:	272a0001 */ 	addiu	$t2,$t9,0x1
/*  f154004:	a04a0445 */ 	sb	$t2,0x445($v0)
/*  f154008:	8fbf001c */ 	lw	$ra,0x1c($sp)
.PF0f15400c:
/*  f15400c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f154010:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f154014:	03e00008 */ 	jr	$ra
/*  f154018:	00000000 */ 	nop
);
#else
void fontLoad(u8 *romstart, u8 *romend, struct font **font1, struct font2a4 **font2, bool monospace)
{
	u32 len = (u32)romend - (u32)romstart;
	s32 maxwidth;
	s32 i;
	struct font *font = malloc(len, MEMPOOL_STAGE);
	struct font2a4 *font2a4 = font->unk2a4;

	dmaExec(font, romstart, len);

	// Convert pointers
	for (i = 0; i < 94; i++) {
		font2a4[i].data += (u32)font;
	}

	// If requested monospace, set all widths to the max, minus 1 for some reason
	if (monospace) {
		maxwidth = 0;

		for (i = 0; i < 94; i++) {
			if (font2a4[i].width > maxwidth) {
				maxwidth = font2a4[i].width;
			}
		}

		maxwidth--;

		for (i = 0; i < 94; i++) {
			font2a4[i].width = maxwidth;
		}
	}

	*font1 = font;
	*font2 = font2a4;
}
#endif

void fontsLoadForCurrentStage(void)
{
	extern u8 _fontbankgothicSegmentRomStart,     _fontbankgothicSegmentRomEnd;
	extern u8 _fontzurichSegmentRomStart,         _fontzurichSegmentRomEnd;
	extern u8 _fonttahomaSegmentRomStart,         _fonttahomaSegmentRomEnd;
	extern u8 _fontnumericSegmentRomStart,        _fontnumericSegmentRomEnd;
	extern u8 _fonthandelgothicsmSegmentRomStart, _fonthandelgothicsmSegmentRomEnd;
	extern u8 _fonthandelgothicxsSegmentRomStart, _fonthandelgothicxsSegmentRomEnd;
	extern u8 _fonthandelgothicmdSegmentRomStart, _fonthandelgothicmdSegmentRomEnd;
	extern u8 _fonthandelgothiclgSegmentRomStart, _fonthandelgothiclgSegmentRomEnd;
	extern u8 _fontocramdSegmentRomStart,         _fontocramdSegmentRomEnd;
	extern u8 _fontocralgSegmentRomStart,         _fontocralgSegmentRomEnd;

	var8007faec = 0;
	g_FontTahoma2 = NULL;
	g_FontNumeric2 = NULL;
	g_FontHandelGothicXs2 = NULL;
	g_FontHandelGothicSm2 = NULL;
	g_FontHandelGothicMd2 = NULL;
	g_FontHandelGothicLg2 = NULL;
	var8007fb24 = 0;
	var8007fb2c = 0;
	var8007fb34 = 0;

	var8007faf0 = 0;
	g_FontTahoma1 = NULL;
	g_FontNumeric1 = NULL;
	g_FontHandelGothicXs1 = NULL;
	g_FontHandelGothicSm1 = NULL;
	g_FontHandelGothicMd1 = NULL;
	g_FontHandelGothicLg1 = NULL;
	var8007fb28 = 0;
	var8007fb30 = 0;
	var8007fb38 = 0;

	var8007fac4 = 0;
	var8007fac8 = 0;
	var8007facc = 0;
	var8007fad4 = 0xffffffff;
	var8007fad8 = 0;
	var8007fadc = 0;
	var8007fae0 = 0;
	var8007fae4 = 0;
	var8007fae8 = 0;

	if (g_Vars.stagenum == STAGE_TITLE) {
		fontLoad(&_fonthandelgothicsmSegmentRomStart, &_fonthandelgothicsmSegmentRomEnd, &g_FontHandelGothicSm2, &g_FontHandelGothicSm1, false);
		fontLoad(&_fonthandelgothicmdSegmentRomStart, &_fonthandelgothicmdSegmentRomEnd, &g_FontHandelGothicMd2, &g_FontHandelGothicMd1, false);
		fontLoad(&_fonthandelgothiclgSegmentRomStart, &_fonthandelgothiclgSegmentRomEnd, &g_FontHandelGothicLg2, &g_FontHandelGothicLg1, false);
	} else if (g_Vars.stagenum == STAGE_CREDITS) {
		fontLoad(&_fonthandelgothicxsSegmentRomStart, &_fonthandelgothicxsSegmentRomEnd, &g_FontHandelGothicXs2, &g_FontHandelGothicXs1, false);
		fontLoad(&_fonthandelgothicsmSegmentRomStart, &_fonthandelgothicsmSegmentRomEnd, &g_FontHandelGothicSm2, &g_FontHandelGothicSm1, false);
		fontLoad(&_fonthandelgothicmdSegmentRomStart, &_fonthandelgothicmdSegmentRomEnd, &g_FontHandelGothicMd2, &g_FontHandelGothicMd1, false);
		fontLoad(&_fonthandelgothiclgSegmentRomStart, &_fonthandelgothiclgSegmentRomEnd, &g_FontHandelGothicLg2, &g_FontHandelGothicLg1, false);
	} else {
#if !PAL
		// This unused GE font exists in NTSC but was removed in the PAL version
		fontLoad(&_fonttahomaSegmentRomStart, &_fonttahomaSegmentRomEnd, &g_FontTahoma2, &g_FontTahoma1, false);
#endif

		fontLoad(&_fontnumericSegmentRomStart, &_fontnumericSegmentRomEnd, &g_FontNumeric2, &g_FontNumeric1, false);
		fontLoad(&_fonthandelgothicxsSegmentRomStart, &_fonthandelgothicxsSegmentRomEnd, &g_FontHandelGothicXs2, &g_FontHandelGothicXs1, false);
		fontLoad(&_fonthandelgothicsmSegmentRomStart, &_fonthandelgothicsmSegmentRomEnd, &g_FontHandelGothicSm2, &g_FontHandelGothicSm1, false);

#if PAL
		if (!g_Vars.normmplayerisrunning) {
			fontLoad(&_fonthandelgothicmdSegmentRomStart, &_fonthandelgothicmdSegmentRomEnd, &g_FontHandelGothicMd2, &g_FontHandelGothicMd1, false);
		}
#else
		fontLoad(&_fonthandelgothicmdSegmentRomStart, &_fonthandelgothicmdSegmentRomEnd, &g_FontHandelGothicMd2, &g_FontHandelGothicMd1, false);
#endif

		if (g_Vars.stagenum == STAGE_TEST_OLD) {
			fontLoad(&_fonthandelgothiclgSegmentRomStart, &_fonthandelgothiclgSegmentRomEnd, &g_FontHandelGothicLg2, &g_FontHandelGothicLg1, false);
		}
	}
}

Gfx *func0f153628(Gfx *gdl)
{
	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
	gDPSetCombineLERP(gdl++,
			0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0,
			0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureConvert(gdl++, G_TC_FILT);
	gDPSetTextureLUT(gdl++, G_TT_NONE);

	if (var8007fad8) {
		gDPSetTextureFilter(gdl++, G_TF_AVERAGE);
	} else {
		gDPSetTextureFilter(gdl++, G_TF_BILERP);
	}

	return gdl;
}

Gfx *func0f153780(Gfx *gdl)
{
	gDPPipeSync(gdl++);
	gDPSetColorDither(gdl++, G_CD_BAYER);
	gDPSetTexturePersp(gdl++, G_TP_PERSP);
	gDPSetTextureLOD(gdl++, G_TL_LOD);

	return gdl;
}

Gfx *gfxSetPrimColour(Gfx *gdl, u32 colour)
{
	gDPPipeSync(gdl++);
    gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

	gDPSetPrimColorViaWord(gdl++, 0, 0, colour);

	return gdl;
}

Gfx *func0f153838(Gfx *gdl)
{
	gDPSetCombineLERP(gdl++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);

	return gdl;
}

Gfx *func0f153858(Gfx *gdl, s32 *x1, s32 *y1, s32 *x2, s32 *y2)
{
	gdl = gfxSetPrimColour(gdl, 0x00000000);

	gDPFillRectangle(gdl++, *x1, *y1, *x2, *y2);

	gdl = func0f153838(gdl);

	return gdl;
}

Gfx *func0f1538e4(Gfx *gdl, s32 *x1, s32 *y1, s32 *x2, s32 *y2)
{
	gdl = gfxSetPrimColour(gdl, 0x00000000);

	gDPFillRectangleScaled(gdl++, *x1, *y1, *x2, *y2);

	gdl = func0f153838(gdl);

	return gdl;
}

Gfx *func0f153990(Gfx *gdl, s32 left, s32 top, s32 width, s32 height)
{
	gdl = gfxSetPrimColour(gdl, 0x00000000);

	gDPFillRectangle(gdl++, left - 1, top - 1, width * var8007fad0 + left + 1, top + height + 1);

	gdl = func0f153838(gdl);

	return gdl;
}

Gfx *func0f153a34(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour)
{
	gdl = gfxSetPrimColour(gdl, colour);

	gDPFillRectangle(gdl++, x1, y1, x2, y2);

	gdl = func0f153838(gdl);

	return gdl;
}

GLOBAL_ASM(
glabel func0f153ab0
/*  f153ab0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f153ab4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f153ab8:	00808025 */ 	or	$s0,$a0,$zero
/*  f153abc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f153ac0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f153ac4:	3c018008 */ 	lui	$at,%hi(var8007fb9c)
/*  f153ac8:	ac2efb9c */ 	sw	$t6,%lo(var8007fb9c)($at)
/*  f153acc:	0fc59e7d */ 	jal	gfxAllocate
/*  f153ad0:	24041090 */ 	addiu	$a0,$zero,0x1090
/*  f153ad4:	3c05800a */ 	lui	$a1,%hi(var800a4634)
/*  f153ad8:	24a54634 */ 	addiu	$a1,$a1,%lo(var800a4634)
/*  f153adc:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f153ae0:	244f1090 */ 	addiu	$t7,$v0,0x1090
/*  f153ae4:	3c01800a */ 	lui	$at,%hi(var800a4638)
/*  f153ae8:	ac2f4638 */ 	sw	$t7,%lo(var800a4638)($at)
/*  f153aec:	3c180600 */ 	lui	$t8,0x600
/*  f153af0:	ae180000 */ 	sw	$t8,0x0($s0)
/*  f153af4:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f153af8:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f153afc:	0fc35320 */ 	jal	func0f0d4c80
/*  f153b00:	ae190004 */ 	sw	$t9,0x4($s0)
/*  f153b04:	3c04800a */ 	lui	$a0,%hi(var800a4634)
/*  f153b08:	00408025 */ 	or	$s0,$v0,$zero
/*  f153b0c:	8c844634 */ 	lw	$a0,%lo(var800a4634)($a0)
/*  f153b10:	0fc3528f */ 	jal	func0f0d4a3c
/*  f153b14:	00002825 */ 	or	$a1,$zero,$zero
/*  f153b18:	3c01800a */ 	lui	$at,%hi(var800a4634)
/*  f153b1c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f153b20:	ac224634 */ 	sw	$v0,%lo(var800a4634)($at)
/*  f153b24:	02001025 */ 	or	$v0,$s0,$zero
/*  f153b28:	3c018008 */ 	lui	$at,%hi(var8007fba4)
/*  f153b2c:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f153b30:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f153b34:	ac28fba4 */ 	sw	$t0,%lo(var8007fba4)($at)
/*  f153b38:	03e00008 */ 	jr	$ra
/*  f153b3c:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

void func0f153b40(void)
{
	var8007fb9c = 0;

	gSPEndDisplayList(var800a4634++);
}

void func0f153b6c(s32 arg0)
{
	if (arg0 != var8007fba4) {
		f32 tmp = var800a45d0.unk14 * var800a45d0.unk14 - (f32)((arg0 - var800a45d0.unk10) * (arg0 - var800a45d0.unk10));

		if (tmp > 0.0f) {
			var8007fba0 = sqrtf(tmp) + var800a45d0.unk0c;
		} else {
			var8007fba0 = 0;
		}

		var8007fba4 = arg0;
	}
}

void func0f153c20(s32 x, s32 y, f32 arg2, u8 arg3)
{
	var800a45d0.unk00 |= 0x01;
	var800a45d0.unk0c = x;
	var800a45d0.unk10 = y;
	var800a45d0.unk14 = arg2;
	var800a45d0.unk18 = arg3;
}

void func0f153c50(void)
{
	var800a45d0.unk1c = var800a45d0.unk0c;
	var800a45d0.unk20 = var800a45d0.unk10;
	var800a45d0.unk24 = var800a45d0.unk14;
	var800a45d0.unk28 = var800a45d0.unk18;
	var800a45d0.unk29 = var800a45d0.unk00 & 1;
}

void func0f153c88(void)
{
	var800a45d0.unk0c = var800a45d0.unk1c;
	var800a45d0.unk10 = var800a45d0.unk20;
	var800a45d0.unk14 = var800a45d0.unk24;
	var800a45d0.unk18 = var800a45d0.unk28;
	var800a45d0.unk00 |= var800a45d0.unk29;
}

void func0f153cc4(s32 arg0, s32 arg1, u32 arg2)
{
	var800a45d0.unk00 |= 0x02;
	var800a45d0.unk2c = arg0;
	var800a45d0.unk30 = arg1;
	var800a45d0.unk34 = arg2;
}

void func0f153ce8(s32 x1, s32 x2, u32 arg2)
{
	var800a45d0.unk00 |= 0x10;
	var800a45d0.x1 = x1;
	var800a45d0.x2 = x2;
	var800a45d0.unk40 = arg2;
}

void func0f153d0c(void)
{
	var800a45d0.unk00 = 0;
}

void func0f153d18(void)
{
	var800a45d0.unk00 = 0;
}

void func0f153d24(void)
{
	var800a45d0.unk2a = var800a45d0.unk00;
	var800a45d0.unk00 = 0;
}

void func0f153d3c(void)
{
	var800a45d0.unk00 = var800a45d0.unk2a;
}

void func0f153d50(u32 arg0, u32 arg1, u32 arg2)
{
	var800a45d0.unk00 |= 0x04;
	var800a45d0.unk4c = arg0;
	var800a45d0.unk50 = arg1;
	var800a45d0.unk54 = arg2;
	var800a45d0.colour58 = 0x44444400;
	var800a45d0.colour5c = 0xffffff00;
}

void func0f153d88(f32 arg0)
{
	var800a45d0.unk00 |= 0x08;
	var800a45d0.unk60 = arg0 * arg0 * 110.0f;
}

void func0f153e38(u32 colour51, u32 colour2)
{
	var800a45d0.colour58 = colour51;
	var800a45d0.colour5c = colour2;
}

void func0f153e4c(void)
{
	var800a45d0.unk00 = 0;
}

s32 func0f153e58(void)
{
	return (var800a45d0.unk00 & 1)
		&& (var800a45d0.unk18 == 0 || var800a45d0.unk18 == 2);
}

GLOBAL_ASM(
glabel func0f153e94
/*  f153e94:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f153e98:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f153e9c:	912e0000 */ 	lbu	$t6,0x0($t1)
/*  f153ea0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f153ea4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f153ea8:	31cf0001 */ 	andi	$t7,$t6,0x1
/*  f153eac:	00c03825 */ 	or	$a3,$a2,$zero
/*  f153eb0:	11e00139 */ 	beqz	$t7,.L0f154398
/*  f153eb4:	00c04025 */ 	or	$t0,$a2,$zero
/*  f153eb8:	8d38000c */ 	lw	$t8,0xc($t1)
/*  f153ebc:	00981023 */ 	subu	$v0,$a0,$t8
/*  f153ec0:	2841f449 */ 	slti	$at,$v0,-2999
/*  f153ec4:	1420001c */ 	bnez	$at,.L0f153f38
/*  f153ec8:	28410bb8 */ 	slti	$at,$v0,0xbb8
/*  f153ecc:	1020001a */ 	beqz	$at,.L0f153f38
/*  f153ed0:	00000000 */ 	nop
/*  f153ed4:	8d390010 */ 	lw	$t9,0x10($t1)
/*  f153ed8:	00b91823 */ 	subu	$v1,$a1,$t9
/*  f153edc:	2861f449 */ 	slti	$at,$v1,-2999
/*  f153ee0:	14200015 */ 	bnez	$at,.L0f153f38
/*  f153ee4:	28610bb8 */ 	slti	$at,$v1,0xbb8
/*  f153ee8:	10200013 */ 	beqz	$at,.L0f153f38
/*  f153eec:	00000000 */ 	nop
/*  f153ef0:	00420019 */ 	multu	$v0,$v0
/*  f153ef4:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f153ef8:	afa60018 */ 	sw	$a2,0x18($sp)
/*  f153efc:	00005012 */ 	mflo	$t2
/*  f153f00:	00000000 */ 	nop
/*  f153f04:	00000000 */ 	nop
/*  f153f08:	00630019 */ 	multu	$v1,$v1
/*  f153f0c:	00005812 */ 	mflo	$t3
/*  f153f10:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f153f14:	448c2000 */ 	mtc1	$t4,$f4
/*  f153f18:	0c012974 */ 	jal	sqrtf
/*  f153f1c:	46802320 */ 	cvt.s.w	$f12,$f4
/*  f153f20:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f153f24:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f153f28:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f153f2c:	8fa80018 */ 	lw	$t0,0x18($sp)
/*  f153f30:	10000003 */ 	b	.L0f153f40
/*  f153f34:	46000306 */ 	mov.s	$f12,$f0
.L0f153f38:
/*  f153f38:	3c017f1b */ 	lui	$at,%hi(var7f1b7400)
/*  f153f3c:	c42c7400 */ 	lwc1	$f12,%lo(var7f1b7400)($at)
.L0f153f40:
/*  f153f40:	3c0d8008 */ 	lui	$t5,%hi(var8007fbac)
/*  f153f44:	8dadfbac */ 	lw	$t5,%lo(var8007fbac)($t5)
/*  f153f48:	3c014f80 */ 	lui	$at,0x4f80
/*  f153f4c:	3c0e8008 */ 	lui	$t6,%hi(var8007fbb0)
/*  f153f50:	448d3000 */ 	mtc1	$t5,$f6
/*  f153f54:	3c0f8008 */ 	lui	$t7,%hi(var8007fbb4)
/*  f153f58:	05a10004 */ 	bgez	$t5,.L0f153f6c
/*  f153f5c:	468033a0 */ 	cvt.s.w	$f14,$f6
/*  f153f60:	44814000 */ 	mtc1	$at,$f8
/*  f153f64:	00000000 */ 	nop
/*  f153f68:	46087380 */ 	add.s	$f14,$f14,$f8
.L0f153f6c:
/*  f153f6c:	8dcefbb0 */ 	lw	$t6,%lo(var8007fbb0)($t6)
/*  f153f70:	3c014f80 */ 	lui	$at,0x4f80
/*  f153f74:	448e5000 */ 	mtc1	$t6,$f10
/*  f153f78:	05c10004 */ 	bgez	$t6,.L0f153f8c
/*  f153f7c:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f153f80:	44812000 */ 	mtc1	$at,$f4
/*  f153f84:	00000000 */ 	nop
/*  f153f88:	46049480 */ 	add.s	$f18,$f18,$f4
.L0f153f8c:
/*  f153f8c:	8deffbb4 */ 	lw	$t7,%lo(var8007fbb4)($t7)
/*  f153f90:	3c014f80 */ 	lui	$at,0x4f80
/*  f153f94:	448f3000 */ 	mtc1	$t7,$f6
/*  f153f98:	05e10004 */ 	bgez	$t7,.L0f153fac
/*  f153f9c:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f153fa0:	44814000 */ 	mtc1	$at,$f8
/*  f153fa4:	00000000 */ 	nop
/*  f153fa8:	46088400 */ 	add.s	$f16,$f16,$f8
.L0f153fac:
/*  f153fac:	91220018 */ 	lbu	$v0,0x18($t1)
/*  f153fb0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f153fb4:	14400082 */ 	bnez	$v0,.L0f1541c0
/*  f153fb8:	00000000 */ 	nop
/*  f153fbc:	c5200014 */ 	lwc1	$f0,0x14($t1)
/*  f153fc0:	460c003c */ 	c.lt.s	$f0,$f12
/*  f153fc4:	00000000 */ 	nop
/*  f153fc8:	45020004 */ 	bc1fl	.L0f153fdc
/*  f153fcc:	460e0081 */ 	sub.s	$f2,$f0,$f14
/*  f153fd0:	100000f1 */ 	b	.L0f154398
/*  f153fd4:	00004025 */ 	or	$t0,$zero,$zero
/*  f153fd8:	460e0081 */ 	sub.s	$f2,$f0,$f14
.L0f153fdc:
/*  f153fdc:	240a00ff */ 	addiu	$t2,$zero,0xff
/*  f153fe0:	460c103c */ 	c.lt.s	$f2,$f12
/*  f153fe4:	00000000 */ 	nop
/*  f153fe8:	45020030 */ 	bc1fl	.L0f1540ac
/*  f153fec:	46107280 */ 	add.s	$f10,$f14,$f16
/*  f153ff0:	46026281 */ 	sub.s	$f10,$f12,$f2
/*  f153ff4:	3c01437f */ 	lui	$at,0x437f
/*  f153ff8:	44813000 */ 	mtc1	$at,$f6
/*  f153ffc:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f154000:	460e5103 */ 	div.s	$f4,$f10,$f14
/*  f154004:	3c014f00 */ 	lui	$at,0x4f00
/*  f154008:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f15400c:	4458f800 */ 	cfc1	$t8,$31
/*  f154010:	44d9f800 */ 	ctc1	$t9,$31
/*  f154014:	00000000 */ 	nop
/*  f154018:	46000224 */ 	cvt.w.s	$f8,$f0
/*  f15401c:	4459f800 */ 	cfc1	$t9,$31
/*  f154020:	00000000 */ 	nop
/*  f154024:	33390078 */ 	andi	$t9,$t9,0x78
/*  f154028:	53200013 */ 	beqzl	$t9,.L0f154078
/*  f15402c:	44194000 */ 	mfc1	$t9,$f8
/*  f154030:	44814000 */ 	mtc1	$at,$f8
/*  f154034:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f154038:	46080201 */ 	sub.s	$f8,$f0,$f8
/*  f15403c:	44d9f800 */ 	ctc1	$t9,$31
/*  f154040:	00000000 */ 	nop
/*  f154044:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f154048:	4459f800 */ 	cfc1	$t9,$31
/*  f15404c:	00000000 */ 	nop
/*  f154050:	33390078 */ 	andi	$t9,$t9,0x78
/*  f154054:	17200005 */ 	bnez	$t9,.L0f15406c
/*  f154058:	00000000 */ 	nop
/*  f15405c:	44194000 */ 	mfc1	$t9,$f8
/*  f154060:	3c018000 */ 	lui	$at,0x8000
/*  f154064:	10000007 */ 	b	.L0f154084
/*  f154068:	0321c825 */ 	or	$t9,$t9,$at
.L0f15406c:
/*  f15406c:	10000005 */ 	b	.L0f154084
/*  f154070:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f154074:	44194000 */ 	mfc1	$t9,$f8
.L0f154078:
/*  f154078:	00000000 */ 	nop
/*  f15407c:	0720fffb */ 	bltz	$t9,.L0f15406c
/*  f154080:	00000000 */ 	nop
.L0f154084:
/*  f154084:	01591023 */ 	subu	$v0,$t2,$t9
/*  f154088:	00025a00 */ 	sll	$t3,$v0,0x8
/*  f15408c:	01626025 */ 	or	$t4,$t3,$v0
/*  f154090:	00026c00 */ 	sll	$t5,$v0,0x10
/*  f154094:	018d7025 */ 	or	$t6,$t4,$t5
/*  f154098:	00027e00 */ 	sll	$t7,$v0,0x18
/*  f15409c:	44d8f800 */ 	ctc1	$t8,$31
/*  f1540a0:	100000bd */ 	b	.L0f154398
/*  f1540a4:	01cf4025 */ 	or	$t0,$t6,$t7
/*  f1540a8:	46107280 */ 	add.s	$f10,$f14,$f16
.L0f1540ac:
/*  f1540ac:	30f800ff */ 	andi	$t8,$a3,0xff
/*  f1540b0:	270a00ff */ 	addiu	$t2,$t8,0xff
/*  f1540b4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f1540b8:	460a0101 */ 	sub.s	$f4,$f0,$f10
/*  f1540bc:	00e15824 */ 	and	$t3,$a3,$at
/*  f1540c0:	000ac842 */ 	srl	$t9,$t2,0x1
/*  f1540c4:	460c203c */ 	c.lt.s	$f4,$f12
/*  f1540c8:	00000000 */ 	nop
/*  f1540cc:	45020004 */ 	bc1fl	.L0f1540e0
/*  f1540d0:	46127180 */ 	add.s	$f6,$f14,$f18
/*  f1540d4:	100000b0 */ 	b	.L0f154398
/*  f1540d8:	032b4025 */ 	or	$t0,$t9,$t3
/*  f1540dc:	46127180 */ 	add.s	$f6,$f14,$f18
.L0f1540e0:
/*  f1540e0:	241900ff */ 	addiu	$t9,$zero,0xff
/*  f1540e4:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f1540e8:	46080081 */ 	sub.s	$f2,$f0,$f8
/*  f1540ec:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1540f0:	00000000 */ 	nop
/*  f1540f4:	450200a9 */ 	bc1fl	.L0f15439c
/*  f1540f8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1540fc:	46026281 */ 	sub.s	$f10,$f12,$f2
/*  f154100:	3c01437f */ 	lui	$at,0x437f
/*  f154104:	44813000 */ 	mtc1	$at,$f6
/*  f154108:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f15410c:	46125103 */ 	div.s	$f4,$f10,$f18
/*  f154110:	30ec00ff */ 	andi	$t4,$a3,0xff
/*  f154114:	258d00ff */ 	addiu	$t5,$t4,0xff
/*  f154118:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f15411c:	00e17824 */ 	and	$t7,$a3,$at
/*  f154120:	000d7042 */ 	srl	$t6,$t5,0x1
/*  f154124:	01cf2825 */ 	or	$a1,$t6,$t7
/*  f154128:	3c014f00 */ 	lui	$at,0x4f00
/*  f15412c:	00e02025 */ 	or	$a0,$a3,$zero
/*  f154130:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f154134:	4458f800 */ 	cfc1	$t8,$31
/*  f154138:	44caf800 */ 	ctc1	$t2,$31
/*  f15413c:	00000000 */ 	nop
/*  f154140:	46000224 */ 	cvt.w.s	$f8,$f0
/*  f154144:	444af800 */ 	cfc1	$t2,$31
/*  f154148:	00000000 */ 	nop
/*  f15414c:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f154150:	51400013 */ 	beqzl	$t2,.L0f1541a0
/*  f154154:	440a4000 */ 	mfc1	$t2,$f8
/*  f154158:	44814000 */ 	mtc1	$at,$f8
/*  f15415c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f154160:	46080201 */ 	sub.s	$f8,$f0,$f8
/*  f154164:	44caf800 */ 	ctc1	$t2,$31
/*  f154168:	00000000 */ 	nop
/*  f15416c:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f154170:	444af800 */ 	cfc1	$t2,$31
/*  f154174:	00000000 */ 	nop
/*  f154178:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f15417c:	15400005 */ 	bnez	$t2,.L0f154194
/*  f154180:	00000000 */ 	nop
/*  f154184:	440a4000 */ 	mfc1	$t2,$f8
/*  f154188:	3c018000 */ 	lui	$at,0x8000
/*  f15418c:	10000007 */ 	b	.L0f1541ac
/*  f154190:	01415025 */ 	or	$t2,$t2,$at
.L0f154194:
/*  f154194:	10000005 */ 	b	.L0f1541ac
/*  f154198:	240affff */ 	addiu	$t2,$zero,-1
/*  f15419c:	440a4000 */ 	mfc1	$t2,$f8
.L0f1541a0:
/*  f1541a0:	00000000 */ 	nop
/*  f1541a4:	0540fffb */ 	bltz	$t2,.L0f154194
/*  f1541a8:	00000000 */ 	nop
.L0f1541ac:
/*  f1541ac:	44d8f800 */ 	ctc1	$t8,$31
/*  f1541b0:	0fc01a40 */ 	jal	colourBlend
/*  f1541b4:	032a3023 */ 	subu	$a2,$t9,$t2
/*  f1541b8:	10000077 */ 	b	.L0f154398
/*  f1541bc:	00404025 */ 	or	$t0,$v0,$zero
.L0f1541c0:
/*  f1541c0:	54410076 */ 	bnel	$v0,$at,.L0f15439c
/*  f1541c4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1541c8:	c5200014 */ 	lwc1	$f0,0x14($t1)
/*  f1541cc:	460c003c */ 	c.lt.s	$f0,$f12
/*  f1541d0:	00000000 */ 	nop
/*  f1541d4:	45020004 */ 	bc1fl	.L0f1541e8
/*  f1541d8:	460e0081 */ 	sub.s	$f2,$f0,$f14
/*  f1541dc:	1000006e */ 	b	.L0f154398
/*  f1541e0:	00004025 */ 	or	$t0,$zero,$zero
/*  f1541e4:	460e0081 */ 	sub.s	$f2,$f0,$f14
.L0f1541e8:
/*  f1541e8:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1541ec:	00000000 */ 	nop
/*  f1541f0:	4502002e */ 	bc1fl	.L0f1542ac
/*  f1541f4:	44808000 */ 	mtc1	$zero,$f16
/*  f1541f8:	46026281 */ 	sub.s	$f10,$f12,$f2
/*  f1541fc:	3c01437f */ 	lui	$at,0x437f
/*  f154200:	44813000 */ 	mtc1	$at,$f6
/*  f154204:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f154208:	460e5103 */ 	div.s	$f4,$f10,$f14
/*  f15420c:	3c014f00 */ 	lui	$at,0x4f00
/*  f154210:	00002025 */ 	or	$a0,$zero,$zero
/*  f154214:	30e500ff */ 	andi	$a1,$a3,0xff
/*  f154218:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f15421c:	444bf800 */ 	cfc1	$t3,$31
/*  f154220:	44c6f800 */ 	ctc1	$a2,$31
/*  f154224:	00000000 */ 	nop
/*  f154228:	46000224 */ 	cvt.w.s	$f8,$f0
/*  f15422c:	4446f800 */ 	cfc1	$a2,$31
/*  f154230:	00000000 */ 	nop
/*  f154234:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f154238:	50c00013 */ 	beqzl	$a2,.L0f154288
/*  f15423c:	44064000 */ 	mfc1	$a2,$f8
/*  f154240:	44814000 */ 	mtc1	$at,$f8
/*  f154244:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f154248:	46080201 */ 	sub.s	$f8,$f0,$f8
/*  f15424c:	44c6f800 */ 	ctc1	$a2,$31
/*  f154250:	00000000 */ 	nop
/*  f154254:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f154258:	4446f800 */ 	cfc1	$a2,$31
/*  f15425c:	00000000 */ 	nop
/*  f154260:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f154264:	14c00005 */ 	bnez	$a2,.L0f15427c
/*  f154268:	00000000 */ 	nop
/*  f15426c:	44064000 */ 	mfc1	$a2,$f8
/*  f154270:	3c018000 */ 	lui	$at,0x8000
/*  f154274:	10000007 */ 	b	.L0f154294
/*  f154278:	00c13025 */ 	or	$a2,$a2,$at
.L0f15427c:
/*  f15427c:	10000005 */ 	b	.L0f154294
/*  f154280:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f154284:	44064000 */ 	mfc1	$a2,$f8
.L0f154288:
/*  f154288:	00000000 */ 	nop
/*  f15428c:	04c0fffb */ 	bltz	$a2,.L0f15427c
/*  f154290:	00000000 */ 	nop
.L0f154294:
/*  f154294:	44cbf800 */ 	ctc1	$t3,$31
/*  f154298:	0fc01a40 */ 	jal	colourBlend
/*  f15429c:	00000000 */ 	nop
/*  f1542a0:	1000003d */ 	b	.L0f154398
/*  f1542a4:	00404025 */ 	or	$t0,$v0,$zero
/*  f1542a8:	44808000 */ 	mtc1	$zero,$f16
.L0f1542ac:
/*  f1542ac:	00000000 */ 	nop
/*  f1542b0:	46107280 */ 	add.s	$f10,$f14,$f16
/*  f1542b4:	460a0101 */ 	sub.s	$f4,$f0,$f10
/*  f1542b8:	460c203c */ 	c.lt.s	$f4,$f12
/*  f1542bc:	00000000 */ 	nop
/*  f1542c0:	45020004 */ 	bc1fl	.L0f1542d4
/*  f1542c4:	46127180 */ 	add.s	$f6,$f14,$f18
/*  f1542c8:	10000033 */ 	b	.L0f154398
/*  f1542cc:	30e800ff */ 	andi	$t0,$a3,0xff
/*  f1542d0:	46127180 */ 	add.s	$f6,$f14,$f18
.L0f1542d4:
/*  f1542d4:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f1542d8:	46080081 */ 	sub.s	$f2,$f0,$f8
/*  f1542dc:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1542e0:	00000000 */ 	nop
/*  f1542e4:	4502002d */ 	bc1fl	.L0f15439c
/*  f1542e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1542ec:	46026281 */ 	sub.s	$f10,$f12,$f2
/*  f1542f0:	3c01437f */ 	lui	$at,0x437f
/*  f1542f4:	44813000 */ 	mtc1	$at,$f6
/*  f1542f8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1542fc:	46125103 */ 	div.s	$f4,$f10,$f18
/*  f154300:	3c014f00 */ 	lui	$at,0x4f00
/*  f154304:	30e400ff */ 	andi	$a0,$a3,0xff
/*  f154308:	00e02825 */ 	or	$a1,$a3,$zero
/*  f15430c:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f154310:	444cf800 */ 	cfc1	$t4,$31
/*  f154314:	44c6f800 */ 	ctc1	$a2,$31
/*  f154318:	00000000 */ 	nop
/*  f15431c:	46000224 */ 	cvt.w.s	$f8,$f0
/*  f154320:	4446f800 */ 	cfc1	$a2,$31
/*  f154324:	00000000 */ 	nop
/*  f154328:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f15432c:	50c00013 */ 	beqzl	$a2,.L0f15437c
/*  f154330:	44064000 */ 	mfc1	$a2,$f8
/*  f154334:	44814000 */ 	mtc1	$at,$f8
/*  f154338:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f15433c:	46080201 */ 	sub.s	$f8,$f0,$f8
/*  f154340:	44c6f800 */ 	ctc1	$a2,$31
/*  f154344:	00000000 */ 	nop
/*  f154348:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f15434c:	4446f800 */ 	cfc1	$a2,$31
/*  f154350:	00000000 */ 	nop
/*  f154354:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f154358:	14c00005 */ 	bnez	$a2,.L0f154370
/*  f15435c:	00000000 */ 	nop
/*  f154360:	44064000 */ 	mfc1	$a2,$f8
/*  f154364:	3c018000 */ 	lui	$at,0x8000
/*  f154368:	10000007 */ 	b	.L0f154388
/*  f15436c:	00c13025 */ 	or	$a2,$a2,$at
.L0f154370:
/*  f154370:	10000005 */ 	b	.L0f154388
/*  f154374:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f154378:	44064000 */ 	mfc1	$a2,$f8
.L0f15437c:
/*  f15437c:	00000000 */ 	nop
/*  f154380:	04c0fffb */ 	bltz	$a2,.L0f154370
/*  f154384:	00000000 */ 	nop
.L0f154388:
/*  f154388:	44ccf800 */ 	ctc1	$t4,$31
/*  f15438c:	0fc01a40 */ 	jal	colourBlend
/*  f154390:	00000000 */ 	nop
/*  f154394:	00404025 */ 	or	$t0,$v0,$zero
.L0f154398:
/*  f154398:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f15439c:
/*  f15439c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f1543a0:	01001025 */ 	or	$v0,$t0,$zero
/*  f1543a4:	03e00008 */ 	jr	$ra
/*  f1543a8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f1543ac
/*  f1543ac:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f1543b0:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f1543b4:	91280000 */ 	lbu	$t0,0x0($t1)
/*  f1543b8:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f1543bc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1543c0:	310e0008 */ 	andi	$t6,$t0,0x8
/*  f1543c4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1543c8:	afa400a8 */ 	sw	$a0,0xa8($sp)
/*  f1543cc:	afa500ac */ 	sw	$a1,0xac($sp)
/*  f1543d0:	00c03825 */ 	or	$a3,$a2,$zero
/*  f1543d4:	11c0000e */ 	beqz	$t6,.L0f154410
/*  f1543d8:	00c08025 */ 	or	$s0,$a2,$zero
/*  f1543dc:	00002025 */ 	or	$a0,$zero,$zero
/*  f1543e0:	00e02825 */ 	or	$a1,$a3,$zero
/*  f1543e4:	8d260060 */ 	lw	$a2,0x60($t1)
/*  f1543e8:	0fc01a40 */ 	jal	colourBlend
/*  f1543ec:	afa700b0 */ 	sw	$a3,0xb0($sp)
/*  f1543f0:	8fa700b0 */ 	lw	$a3,0xb0($sp)
/*  f1543f4:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f1543f8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f1543fc:	00417824 */ 	and	$t7,$v0,$at
/*  f154400:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f154404:	30f800ff */ 	andi	$t8,$a3,0xff
/*  f154408:	01f88025 */ 	or	$s0,$t7,$t8
/*  f15440c:	91280000 */ 	lbu	$t0,0x0($t1)
.L0f154410:
/*  f154410:	31190002 */ 	andi	$t9,$t0,0x2
/*  f154414:	53200029 */ 	beqzl	$t9,.L0f1544bc
/*  f154418:	310e0010 */ 	andi	$t6,$t0,0x10
/*  f15441c:	8faa00ac */ 	lw	$t2,0xac($sp)
/*  f154420:	8d2b002c */ 	lw	$t3,0x2c($t1)
/*  f154424:	8d2c0030 */ 	lw	$t4,0x30($t1)
/*  f154428:	02002025 */ 	or	$a0,$s0,$zero
/*  f15442c:	014b1023 */ 	subu	$v0,$t2,$t3
/*  f154430:	04410002 */ 	bgez	$v0,.L0f15443c
/*  f154434:	014c1823 */ 	subu	$v1,$t2,$t4
/*  f154438:	00021023 */ 	negu	$v0,$v0
.L0f15443c:
/*  f15443c:	04630003 */ 	bgezl	$v1,.L0f15444c
/*  f154440:	0062082a */ 	slt	$at,$v1,$v0
/*  f154444:	00031823 */ 	negu	$v1,$v1
/*  f154448:	0062082a */ 	slt	$at,$v1,$v0
.L0f15444c:
/*  f15444c:	50200003 */ 	beqzl	$at,.L0f15445c
/*  f154450:	8d230034 */ 	lw	$v1,0x34($t1)
/*  f154454:	00601025 */ 	or	$v0,$v1,$zero
/*  f154458:	8d230034 */ 	lw	$v1,0x34($t1)
.L0f15445c:
/*  f15445c:	0062082a */ 	slt	$at,$v1,$v0
/*  f154460:	54200016 */ 	bnezl	$at,.L0f1544bc
/*  f154464:	310e0010 */ 	andi	$t6,$t0,0x10
/*  f154468:	00026a00 */ 	sll	$t5,$v0,0x8
/*  f15446c:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f154470:	01a3001a */ 	div	$zero,$t5,$v1
/*  f154474:	00003012 */ 	mflo	$a2
/*  f154478:	00002825 */ 	or	$a1,$zero,$zero
/*  f15447c:	14600002 */ 	bnez	$v1,.L0f154488
/*  f154480:	00000000 */ 	nop
/*  f154484:	0007000d */ 	break	0x7
.L0f154488:
/*  f154488:	2401ffff */ 	addiu	$at,$zero,-1
/*  f15448c:	14610004 */ 	bne	$v1,$at,.L0f1544a0
/*  f154490:	3c018000 */ 	lui	$at,0x8000
/*  f154494:	15a10002 */ 	bne	$t5,$at,.L0f1544a0
/*  f154498:	00000000 */ 	nop
/*  f15449c:	0006000d */ 	break	0x6
.L0f1544a0:
/*  f1544a0:	0fc01a40 */ 	jal	colourBlend
/*  f1544a4:	00000000 */ 	nop
/*  f1544a8:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f1544ac:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f1544b0:	91280000 */ 	lbu	$t0,0x0($t1)
/*  f1544b4:	00408025 */ 	or	$s0,$v0,$zero
/*  f1544b8:	310e0010 */ 	andi	$t6,$t0,0x10
.L0f1544bc:
/*  f1544bc:	11c00027 */ 	beqz	$t6,.L0f15455c
/*  f1544c0:	8faf00a8 */ 	lw	$t7,0xa8($sp)
/*  f1544c4:	8d380038 */ 	lw	$t8,0x38($t1)
/*  f1544c8:	8d39003c */ 	lw	$t9,0x3c($t1)
/*  f1544cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f1544d0:	01f81023 */ 	subu	$v0,$t7,$t8
/*  f1544d4:	04410002 */ 	bgez	$v0,.L0f1544e0
/*  f1544d8:	01f91823 */ 	subu	$v1,$t7,$t9
/*  f1544dc:	00001025 */ 	or	$v0,$zero,$zero
.L0f1544e0:
/*  f1544e0:	04630003 */ 	bgezl	$v1,.L0f1544f0
/*  f1544e4:	0062082a */ 	slt	$at,$v1,$v0
/*  f1544e8:	00031823 */ 	negu	$v1,$v1
/*  f1544ec:	0062082a */ 	slt	$at,$v1,$v0
.L0f1544f0:
/*  f1544f0:	50200003 */ 	beqzl	$at,.L0f154500
/*  f1544f4:	8d230040 */ 	lw	$v1,0x40($t1)
/*  f1544f8:	00601025 */ 	or	$v0,$v1,$zero
/*  f1544fc:	8d230040 */ 	lw	$v1,0x40($t1)
.L0f154500:
/*  f154500:	00025a00 */ 	sll	$t3,$v0,0x8
/*  f154504:	01625823 */ 	subu	$t3,$t3,$v0
/*  f154508:	0062082a */ 	slt	$at,$v1,$v0
/*  f15450c:	54200014 */ 	bnezl	$at,.L0f154560
/*  f154510:	310a0001 */ 	andi	$t2,$t0,0x1
/*  f154514:	0163001a */ 	div	$zero,$t3,$v1
/*  f154518:	00003012 */ 	mflo	$a2
/*  f15451c:	00002825 */ 	or	$a1,$zero,$zero
/*  f154520:	14600002 */ 	bnez	$v1,.L0f15452c
/*  f154524:	00000000 */ 	nop
/*  f154528:	0007000d */ 	break	0x7
.L0f15452c:
/*  f15452c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f154530:	14610004 */ 	bne	$v1,$at,.L0f154544
/*  f154534:	3c018000 */ 	lui	$at,0x8000
/*  f154538:	15610002 */ 	bne	$t3,$at,.L0f154544
/*  f15453c:	00000000 */ 	nop
/*  f154540:	0006000d */ 	break	0x6
.L0f154544:
/*  f154544:	0fc01a40 */ 	jal	colourBlend
/*  f154548:	00000000 */ 	nop
/*  f15454c:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f154550:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f154554:	91280000 */ 	lbu	$t0,0x0($t1)
/*  f154558:	00408025 */ 	or	$s0,$v0,$zero
.L0f15455c:
/*  f15455c:	310a0001 */ 	andi	$t2,$t0,0x1
.L0f154560:
/*  f154560:	114001fd */ 	beqz	$t2,.L0f154d58
/*  f154564:	8fac00a8 */ 	lw	$t4,0xa8($sp)
/*  f154568:	8d2d000c */ 	lw	$t5,0xc($t1)
/*  f15456c:	018d1023 */ 	subu	$v0,$t4,$t5
/*  f154570:	2841f449 */ 	slti	$at,$v0,-2999
/*  f154574:	14200018 */ 	bnez	$at,.L0f1545d8
/*  f154578:	28410bb8 */ 	slti	$at,$v0,0xbb8
/*  f15457c:	10200016 */ 	beqz	$at,.L0f1545d8
/*  f154580:	8fae00ac */ 	lw	$t6,0xac($sp)
/*  f154584:	8d380010 */ 	lw	$t8,0x10($t1)
/*  f154588:	01d81823 */ 	subu	$v1,$t6,$t8
/*  f15458c:	2861f449 */ 	slti	$at,$v1,-2999
/*  f154590:	14200011 */ 	bnez	$at,.L0f1545d8
/*  f154594:	28610bb8 */ 	slti	$at,$v1,0xbb8
/*  f154598:	1020000f */ 	beqz	$at,.L0f1545d8
/*  f15459c:	00000000 */ 	nop
/*  f1545a0:	00420019 */ 	multu	$v0,$v0
/*  f1545a4:	00007812 */ 	mflo	$t7
/*  f1545a8:	00000000 */ 	nop
/*  f1545ac:	00000000 */ 	nop
/*  f1545b0:	00630019 */ 	multu	$v1,$v1
/*  f1545b4:	0000c812 */ 	mflo	$t9
/*  f1545b8:	01f95821 */ 	addu	$t3,$t7,$t9
/*  f1545bc:	448b2000 */ 	mtc1	$t3,$f4
/*  f1545c0:	0c012974 */ 	jal	sqrtf
/*  f1545c4:	46802320 */ 	cvt.s.w	$f12,$f4
/*  f1545c8:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f1545cc:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f1545d0:	10000003 */ 	b	.L0f1545e0
/*  f1545d4:	46000306 */ 	mov.s	$f12,$f0
.L0f1545d8:
/*  f1545d8:	3c017f1b */ 	lui	$at,%hi(var7f1b7404)
/*  f1545dc:	c42c7404 */ 	lwc1	$f12,%lo(var7f1b7404)($at)
.L0f1545e0:
/*  f1545e0:	3c0a8008 */ 	lui	$t2,%hi(var8007fbac)
/*  f1545e4:	8d4afbac */ 	lw	$t2,%lo(var8007fbac)($t2)
/*  f1545e8:	3c014f80 */ 	lui	$at,0x4f80
/*  f1545ec:	3c0c8008 */ 	lui	$t4,%hi(var8007fbb0)
/*  f1545f0:	448a3000 */ 	mtc1	$t2,$f6
/*  f1545f4:	3c0d8008 */ 	lui	$t5,%hi(var8007fbb4)
/*  f1545f8:	05410004 */ 	bgez	$t2,.L0f15460c
/*  f1545fc:	468033a0 */ 	cvt.s.w	$f14,$f6
/*  f154600:	44814000 */ 	mtc1	$at,$f8
/*  f154604:	00000000 */ 	nop
/*  f154608:	46087380 */ 	add.s	$f14,$f14,$f8
.L0f15460c:
/*  f15460c:	8d8cfbb0 */ 	lw	$t4,%lo(var8007fbb0)($t4)
/*  f154610:	3c014f80 */ 	lui	$at,0x4f80
/*  f154614:	448c5000 */ 	mtc1	$t4,$f10
/*  f154618:	05810004 */ 	bgez	$t4,.L0f15462c
/*  f15461c:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f154620:	44812000 */ 	mtc1	$at,$f4
/*  f154624:	00000000 */ 	nop
/*  f154628:	46049480 */ 	add.s	$f18,$f18,$f4
.L0f15462c:
/*  f15462c:	8dadfbb4 */ 	lw	$t5,%lo(var8007fbb4)($t5)
/*  f154630:	3c014f80 */ 	lui	$at,0x4f80
/*  f154634:	448d3000 */ 	mtc1	$t5,$f6
/*  f154638:	05a10004 */ 	bgez	$t5,.L0f15464c
/*  f15463c:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f154640:	44814000 */ 	mtc1	$at,$f8
/*  f154644:	00000000 */ 	nop
/*  f154648:	46088400 */ 	add.s	$f16,$f16,$f8
.L0f15464c:
/*  f15464c:	91220018 */ 	lbu	$v0,0x18($t1)
/*  f154650:	24010002 */ 	addiu	$at,$zero,0x2
/*  f154654:	14400095 */ 	bnez	$v0,.L0f1548ac
/*  f154658:	00000000 */ 	nop
/*  f15465c:	c5200014 */ 	lwc1	$f0,0x14($t1)
/*  f154660:	460c003c */ 	c.lt.s	$f0,$f12
/*  f154664:	00000000 */ 	nop
/*  f154668:	45020004 */ 	bc1fl	.L0f15467c
/*  f15466c:	460e0081 */ 	sub.s	$f2,$f0,$f14
/*  f154670:	100001b9 */ 	b	.L0f154d58
/*  f154674:	00008025 */ 	or	$s0,$zero,$zero
/*  f154678:	460e0081 */ 	sub.s	$f2,$f0,$f14
.L0f15467c:
/*  f15467c:	460c103c */ 	c.lt.s	$f2,$f12
/*  f154680:	00000000 */ 	nop
/*  f154684:	45020031 */ 	bc1fl	.L0f15474c
/*  f154688:	46107280 */ 	add.s	$f10,$f14,$f16
/*  f15468c:	46026281 */ 	sub.s	$f10,$f12,$f2
/*  f154690:	3c01437f */ 	lui	$at,0x437f
/*  f154694:	44813000 */ 	mtc1	$at,$f6
/*  f154698:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f15469c:	460e5103 */ 	div.s	$f4,$f10,$f14
/*  f1546a0:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f1546a4:	3c014f00 */ 	lui	$at,0x4f00
/*  f1546a8:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f1546ac:	444ef800 */ 	cfc1	$t6,$31
/*  f1546b0:	44d8f800 */ 	ctc1	$t8,$31
/*  f1546b4:	00000000 */ 	nop
/*  f1546b8:	46000224 */ 	cvt.w.s	$f8,$f0
/*  f1546bc:	4458f800 */ 	cfc1	$t8,$31
/*  f1546c0:	00000000 */ 	nop
/*  f1546c4:	33180078 */ 	andi	$t8,$t8,0x78
/*  f1546c8:	53000013 */ 	beqzl	$t8,.L0f154718
/*  f1546cc:	44184000 */ 	mfc1	$t8,$f8
/*  f1546d0:	44814000 */ 	mtc1	$at,$f8
/*  f1546d4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1546d8:	46080201 */ 	sub.s	$f8,$f0,$f8
/*  f1546dc:	44d8f800 */ 	ctc1	$t8,$31
/*  f1546e0:	00000000 */ 	nop
/*  f1546e4:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f1546e8:	4458f800 */ 	cfc1	$t8,$31
/*  f1546ec:	00000000 */ 	nop
/*  f1546f0:	33180078 */ 	andi	$t8,$t8,0x78
/*  f1546f4:	17000005 */ 	bnez	$t8,.L0f15470c
/*  f1546f8:	00000000 */ 	nop
/*  f1546fc:	44184000 */ 	mfc1	$t8,$f8
/*  f154700:	3c018000 */ 	lui	$at,0x8000
/*  f154704:	10000007 */ 	b	.L0f154724
/*  f154708:	0301c025 */ 	or	$t8,$t8,$at
.L0f15470c:
/*  f15470c:	10000005 */ 	b	.L0f154724
/*  f154710:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f154714:	44184000 */ 	mfc1	$t8,$f8
.L0f154718:
/*  f154718:	00000000 */ 	nop
/*  f15471c:	0700fffb */ 	bltz	$t8,.L0f15470c
/*  f154720:	00000000 */ 	nop
.L0f154724:
/*  f154724:	00f81023 */ 	subu	$v0,$a3,$t8
/*  f154728:	00027a00 */ 	sll	$t7,$v0,0x8
/*  f15472c:	01e2c825 */ 	or	$t9,$t7,$v0
/*  f154730:	00025c00 */ 	sll	$t3,$v0,0x10
/*  f154734:	032b5025 */ 	or	$t2,$t9,$t3
/*  f154738:	00026600 */ 	sll	$t4,$v0,0x18
/*  f15473c:	44cef800 */ 	ctc1	$t6,$31
/*  f154740:	10000185 */ 	b	.L0f154d58
/*  f154744:	014c8025 */ 	or	$s0,$t2,$t4
/*  f154748:	46107280 */ 	add.s	$f10,$f14,$f16
.L0f15474c:
/*  f15474c:	460a0101 */ 	sub.s	$f4,$f0,$f10
/*  f154750:	460c203c */ 	c.lt.s	$f4,$f12
/*  f154754:	00000000 */ 	nop
/*  f154758:	45020004 */ 	bc1fl	.L0f15476c
/*  f15475c:	46127180 */ 	add.s	$f6,$f14,$f18
/*  f154760:	1000017d */ 	b	.L0f154d58
/*  f154764:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f154768:	46127180 */ 	add.s	$f6,$f14,$f18
.L0f15476c:
/*  f15476c:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f154770:	46080081 */ 	sub.s	$f2,$f0,$f8
/*  f154774:	460c103c */ 	c.lt.s	$f2,$f12
/*  f154778:	00000000 */ 	nop
/*  f15477c:	45020177 */ 	bc1fl	.L0f154d5c
/*  f154780:	912a0000 */ 	lbu	$t2,0x0($t1)
/*  f154784:	46026281 */ 	sub.s	$f10,$f12,$f2
/*  f154788:	3c01437f */ 	lui	$at,0x437f
/*  f15478c:	44813000 */ 	mtc1	$at,$f6
/*  f154790:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f154794:	46125103 */ 	div.s	$f4,$f10,$f18
/*  f154798:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f15479c:	3c014f00 */ 	lui	$at,0x4f00
/*  f1547a0:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f1547a4:	444df800 */ 	cfc1	$t5,$31
/*  f1547a8:	44c4f800 */ 	ctc1	$a0,$31
/*  f1547ac:	00000000 */ 	nop
/*  f1547b0:	46000224 */ 	cvt.w.s	$f8,$f0
/*  f1547b4:	4444f800 */ 	cfc1	$a0,$31
/*  f1547b8:	00000000 */ 	nop
/*  f1547bc:	30840078 */ 	andi	$a0,$a0,0x78
/*  f1547c0:	50800013 */ 	beqzl	$a0,.L0f154810
/*  f1547c4:	44044000 */ 	mfc1	$a0,$f8
/*  f1547c8:	44814000 */ 	mtc1	$at,$f8
/*  f1547cc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1547d0:	46080201 */ 	sub.s	$f8,$f0,$f8
/*  f1547d4:	44c4f800 */ 	ctc1	$a0,$31
/*  f1547d8:	00000000 */ 	nop
/*  f1547dc:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f1547e0:	4444f800 */ 	cfc1	$a0,$31
/*  f1547e4:	00000000 */ 	nop
/*  f1547e8:	30840078 */ 	andi	$a0,$a0,0x78
/*  f1547ec:	14800005 */ 	bnez	$a0,.L0f154804
/*  f1547f0:	00000000 */ 	nop
/*  f1547f4:	44044000 */ 	mfc1	$a0,$f8
/*  f1547f8:	3c018000 */ 	lui	$at,0x8000
/*  f1547fc:	10000007 */ 	b	.L0f15481c
/*  f154800:	00812025 */ 	or	$a0,$a0,$at
.L0f154804:
/*  f154804:	10000005 */ 	b	.L0f15481c
/*  f154808:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f15480c:	44044000 */ 	mfc1	$a0,$f8
.L0f154810:
/*  f154810:	00000000 */ 	nop
/*  f154814:	0480fffb */ 	bltz	$a0,.L0f154804
/*  f154818:	00000000 */ 	nop
.L0f15481c:
/*  f15481c:	00870019 */ 	multu	$a0,$a3
/*  f154820:	00107602 */ 	srl	$t6,$s0,0x18
/*  f154824:	31d800ff */ 	andi	$t8,$t6,0xff
/*  f154828:	00e41023 */ 	subu	$v0,$a3,$a0
/*  f15482c:	44cdf800 */ 	ctc1	$t5,$31
/*  f154830:	00106402 */ 	srl	$t4,$s0,0x10
/*  f154834:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f154838:	00106202 */ 	srl	$t4,$s0,0x8
/*  f15483c:	00001812 */ 	mflo	$v1
/*  f154840:	00000000 */ 	nop
/*  f154844:	00000000 */ 	nop
/*  f154848:	03020019 */ 	multu	$t8,$v0
/*  f15484c:	00007812 */ 	mflo	$t7
/*  f154850:	01e3c821 */ 	addu	$t9,$t7,$v1
/*  f154854:	00195a02 */ 	srl	$t3,$t9,0x8
/*  f154858:	01a20019 */ 	multu	$t5,$v0
/*  f15485c:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f154860:	320c00ff */ 	andi	$t4,$s0,0xff
/*  f154864:	000b5600 */ 	sll	$t2,$t3,0x18
/*  f154868:	00007012 */ 	mflo	$t6
/*  f15486c:	01c3c021 */ 	addu	$t8,$t6,$v1
/*  f154870:	00187a02 */ 	srl	$t7,$t8,0x8
/*  f154874:	01a20019 */ 	multu	$t5,$v0
/*  f154878:	000fcc00 */ 	sll	$t9,$t7,0x10
/*  f15487c:	01595825 */ 	or	$t3,$t2,$t9
/*  f154880:	00007012 */ 	mflo	$t6
/*  f154884:	01c3c021 */ 	addu	$t8,$t6,$v1
/*  f154888:	00187a02 */ 	srl	$t7,$t8,0x8
/*  f15488c:	01820019 */ 	multu	$t4,$v0
/*  f154890:	000f5200 */ 	sll	$t2,$t7,0x8
/*  f154894:	016ac825 */ 	or	$t9,$t3,$t2
/*  f154898:	00006812 */ 	mflo	$t5
/*  f15489c:	01a37021 */ 	addu	$t6,$t5,$v1
/*  f1548a0:	000ec202 */ 	srl	$t8,$t6,0x8
/*  f1548a4:	1000012c */ 	b	.L0f154d58
/*  f1548a8:	03388025 */ 	or	$s0,$t9,$t8
.L0f1548ac:
/*  f1548ac:	1441007f */ 	bne	$v0,$at,.L0f154aac
/*  f1548b0:	3c047f1b */ 	lui	$a0,%hi(var7f1b73b0)
/*  f1548b4:	c5200014 */ 	lwc1	$f0,0x14($t1)
/*  f1548b8:	460c003c */ 	c.lt.s	$f0,$f12
/*  f1548bc:	00000000 */ 	nop
/*  f1548c0:	45020004 */ 	bc1fl	.L0f1548d4
/*  f1548c4:	44807000 */ 	mtc1	$zero,$f14
/*  f1548c8:	10000123 */ 	b	.L0f154d58
/*  f1548cc:	00008025 */ 	or	$s0,$zero,$zero
/*  f1548d0:	44807000 */ 	mtc1	$zero,$f14
.L0f1548d4:
/*  f1548d4:	00000000 */ 	nop
/*  f1548d8:	460e0081 */ 	sub.s	$f2,$f0,$f14
/*  f1548dc:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1548e0:	00000000 */ 	nop
/*  f1548e4:	45020030 */ 	bc1fl	.L0f1549a8
/*  f1548e8:	44805000 */ 	mtc1	$zero,$f10
/*  f1548ec:	46026281 */ 	sub.s	$f10,$f12,$f2
/*  f1548f0:	3c01437f */ 	lui	$at,0x437f
/*  f1548f4:	44813000 */ 	mtc1	$at,$f6
/*  f1548f8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1548fc:	460e5103 */ 	div.s	$f4,$f10,$f14
/*  f154900:	3c014f00 */ 	lui	$at,0x4f00
/*  f154904:	00002025 */ 	or	$a0,$zero,$zero
/*  f154908:	320500ff */ 	andi	$a1,$s0,0xff
/*  f15490c:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f154910:	444ff800 */ 	cfc1	$t7,$31
/*  f154914:	44c6f800 */ 	ctc1	$a2,$31
/*  f154918:	00000000 */ 	nop
/*  f15491c:	46000224 */ 	cvt.w.s	$f8,$f0
/*  f154920:	4446f800 */ 	cfc1	$a2,$31
/*  f154924:	00000000 */ 	nop
/*  f154928:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f15492c:	50c00013 */ 	beqzl	$a2,.L0f15497c
/*  f154930:	44064000 */ 	mfc1	$a2,$f8
/*  f154934:	44814000 */ 	mtc1	$at,$f8
/*  f154938:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f15493c:	46080201 */ 	sub.s	$f8,$f0,$f8
/*  f154940:	44c6f800 */ 	ctc1	$a2,$31
/*  f154944:	00000000 */ 	nop
/*  f154948:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f15494c:	4446f800 */ 	cfc1	$a2,$31
/*  f154950:	00000000 */ 	nop
/*  f154954:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f154958:	14c00005 */ 	bnez	$a2,.L0f154970
/*  f15495c:	00000000 */ 	nop
/*  f154960:	44064000 */ 	mfc1	$a2,$f8
/*  f154964:	3c018000 */ 	lui	$at,0x8000
/*  f154968:	10000007 */ 	b	.L0f154988
/*  f15496c:	00c13025 */ 	or	$a2,$a2,$at
.L0f154970:
/*  f154970:	10000005 */ 	b	.L0f154988
/*  f154974:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f154978:	44064000 */ 	mfc1	$a2,$f8
.L0f15497c:
/*  f15497c:	00000000 */ 	nop
/*  f154980:	04c0fffb */ 	bltz	$a2,.L0f154970
/*  f154984:	00000000 */ 	nop
.L0f154988:
/*  f154988:	44cff800 */ 	ctc1	$t7,$31
/*  f15498c:	0fc01a40 */ 	jal	colourBlend
/*  f154990:	00000000 */ 	nop
/*  f154994:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f154998:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f15499c:	100000ee */ 	b	.L0f154d58
/*  f1549a0:	00408025 */ 	or	$s0,$v0,$zero
/*  f1549a4:	44805000 */ 	mtc1	$zero,$f10
.L0f1549a8:
/*  f1549a8:	3c014284 */ 	lui	$at,0x4284
/*  f1549ac:	320b00ff */ 	andi	$t3,$s0,0xff
/*  f1549b0:	460a7100 */ 	add.s	$f4,$f14,$f10
/*  f1549b4:	46040181 */ 	sub.s	$f6,$f0,$f4
/*  f1549b8:	460c303c */ 	c.lt.s	$f6,$f12
/*  f1549bc:	00000000 */ 	nop
/*  f1549c0:	45020004 */ 	bc1fl	.L0f1549d4
/*  f1549c4:	44818000 */ 	mtc1	$at,$f16
/*  f1549c8:	100000e3 */ 	b	.L0f154d58
/*  f1549cc:	01608025 */ 	or	$s0,$t3,$zero
/*  f1549d0:	44818000 */ 	mtc1	$at,$f16
.L0f1549d4:
/*  f1549d4:	44805000 */ 	mtc1	$zero,$f10
/*  f1549d8:	46107200 */ 	add.s	$f8,$f14,$f16
/*  f1549dc:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f1549e0:	46040081 */ 	sub.s	$f2,$f0,$f4
/*  f1549e4:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1549e8:	00000000 */ 	nop
/*  f1549ec:	450200db */ 	bc1fl	.L0f154d5c
/*  f1549f0:	912a0000 */ 	lbu	$t2,0x0($t1)
/*  f1549f4:	46026181 */ 	sub.s	$f6,$f12,$f2
/*  f1549f8:	3c01437f */ 	lui	$at,0x437f
/*  f1549fc:	44815000 */ 	mtc1	$at,$f10
/*  f154a00:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f154a04:	46103203 */ 	div.s	$f8,$f6,$f16
/*  f154a08:	3c014f00 */ 	lui	$at,0x4f00
/*  f154a0c:	00002025 */ 	or	$a0,$zero,$zero
/*  f154a10:	02002825 */ 	or	$a1,$s0,$zero
/*  f154a14:	460a4002 */ 	mul.s	$f0,$f8,$f10
/*  f154a18:	444af800 */ 	cfc1	$t2,$31
/*  f154a1c:	44c6f800 */ 	ctc1	$a2,$31
/*  f154a20:	00000000 */ 	nop
/*  f154a24:	46000124 */ 	cvt.w.s	$f4,$f0
/*  f154a28:	4446f800 */ 	cfc1	$a2,$31
/*  f154a2c:	00000000 */ 	nop
/*  f154a30:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f154a34:	50c00013 */ 	beqzl	$a2,.L0f154a84
/*  f154a38:	44062000 */ 	mfc1	$a2,$f4
/*  f154a3c:	44812000 */ 	mtc1	$at,$f4
/*  f154a40:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f154a44:	46040101 */ 	sub.s	$f4,$f0,$f4
/*  f154a48:	44c6f800 */ 	ctc1	$a2,$31
/*  f154a4c:	00000000 */ 	nop
/*  f154a50:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f154a54:	4446f800 */ 	cfc1	$a2,$31
/*  f154a58:	00000000 */ 	nop
/*  f154a5c:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f154a60:	14c00005 */ 	bnez	$a2,.L0f154a78
/*  f154a64:	00000000 */ 	nop
/*  f154a68:	44062000 */ 	mfc1	$a2,$f4
/*  f154a6c:	3c018000 */ 	lui	$at,0x8000
/*  f154a70:	10000007 */ 	b	.L0f154a90
/*  f154a74:	00c13025 */ 	or	$a2,$a2,$at
.L0f154a78:
/*  f154a78:	10000005 */ 	b	.L0f154a90
/*  f154a7c:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f154a80:	44062000 */ 	mfc1	$a2,$f4
.L0f154a84:
/*  f154a84:	00000000 */ 	nop
/*  f154a88:	04c0fffb */ 	bltz	$a2,.L0f154a78
/*  f154a8c:	00000000 */ 	nop
.L0f154a90:
/*  f154a90:	44caf800 */ 	ctc1	$t2,$31
/*  f154a94:	0fc01a40 */ 	jal	colourBlend
/*  f154a98:	00000000 */ 	nop
/*  f154a9c:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f154aa0:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f154aa4:	100000ac */ 	b	.L0f154d58
/*  f154aa8:	00408025 */ 	or	$s0,$v0,$zero
.L0f154aac:
/*  f154aac:	320200ff */ 	andi	$v0,$s0,0xff
/*  f154ab0:	3c058008 */ 	lui	$a1,%hi(var8007fbc8)
/*  f154ab4:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f154ab8:	24a5fbc8 */ 	addiu	$a1,$a1,%lo(var8007fbc8)
/*  f154abc:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f154ac0:	248473b0 */ 	addiu	$a0,$a0,%lo(var7f1b73b0)
/*  f154ac4:	e7ac0084 */ 	swc1	$f12,0x84($sp)
/*  f154ac8:	0c0036cc */ 	jal	func0000db30
/*  f154acc:	e7ae00a4 */ 	swc1	$f14,0xa4($sp)
/*  f154ad0:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f154ad4:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f154ad8:	c7ac0084 */ 	lwc1	$f12,0x84($sp)
/*  f154adc:	c5200014 */ 	lwc1	$f0,0x14($t1)
/*  f154ae0:	8fa20024 */ 	lw	$v0,0x24($sp)
/*  f154ae4:	c7ae00a4 */ 	lwc1	$f14,0xa4($sp)
/*  f154ae8:	460c003c */ 	c.lt.s	$f0,$f12
/*  f154aec:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f154af0:	02002825 */ 	or	$a1,$s0,$zero
/*  f154af4:	45020008 */ 	bc1fl	.L0f154b18
/*  f154af8:	460e0081 */ 	sub.s	$f2,$f0,$f14
/*  f154afc:	0fc01a40 */ 	jal	colourBlend
/*  f154b00:	2406006e */ 	addiu	$a2,$zero,0x6e
/*  f154b04:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f154b08:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f154b0c:	10000092 */ 	b	.L0f154d58
/*  f154b10:	00408025 */ 	or	$s0,$v0,$zero
/*  f154b14:	460e0081 */ 	sub.s	$f2,$f0,$f14
.L0f154b18:
/*  f154b18:	3c0141b0 */ 	lui	$at,0x41b0
/*  f154b1c:	460c103c */ 	c.lt.s	$f2,$f12
/*  f154b20:	00000000 */ 	nop
/*  f154b24:	4502003d */ 	bc1fl	.L0f154c1c
/*  f154b28:	44818000 */ 	mtc1	$at,$f16
/*  f154b2c:	46026181 */ 	sub.s	$f6,$f12,$f2
/*  f154b30:	3c01437f */ 	lui	$at,0x437f
/*  f154b34:	44815000 */ 	mtc1	$at,$f10
/*  f154b38:	3c0c8008 */ 	lui	$t4,%hi(var8007fbc8)
/*  f154b3c:	460e3203 */ 	div.s	$f8,$f6,$f14
/*  f154b40:	8d8cfbc8 */ 	lw	$t4,%lo(var8007fbc8)($t4)
/*  f154b44:	02002825 */ 	or	$a1,$s0,$zero
/*  f154b48:	240600c0 */ 	addiu	$a2,$zero,0xc0
/*  f154b4c:	01822025 */ 	or	$a0,$t4,$v0
/*  f154b50:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f154b54:	0fc01a40 */ 	jal	colourBlend
/*  f154b58:	e7a4004c */ 	swc1	$f4,0x4c($sp)
/*  f154b5c:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f154b60:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f154b64:	02002825 */ 	or	$a1,$s0,$zero
/*  f154b68:	0fc01a40 */ 	jal	colourBlend
/*  f154b6c:	2406006e */ 	addiu	$a2,$zero,0x6e
/*  f154b70:	444df800 */ 	cfc1	$t5,$31
/*  f154b74:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f154b78:	44cef800 */ 	ctc1	$t6,$31
/*  f154b7c:	c7a6004c */ 	lwc1	$f6,0x4c($sp)
/*  f154b80:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f154b84:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f154b88:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f154b8c:	00402825 */ 	or	$a1,$v0,$zero
/*  f154b90:	3c014f00 */ 	lui	$at,0x4f00
/*  f154b94:	444ef800 */ 	cfc1	$t6,$31
/*  f154b98:	00000000 */ 	nop
/*  f154b9c:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f154ba0:	51c00013 */ 	beqzl	$t6,.L0f154bf0
/*  f154ba4:	440e4000 */ 	mfc1	$t6,$f8
/*  f154ba8:	44814000 */ 	mtc1	$at,$f8
/*  f154bac:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f154bb0:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f154bb4:	44cef800 */ 	ctc1	$t6,$31
/*  f154bb8:	00000000 */ 	nop
/*  f154bbc:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f154bc0:	444ef800 */ 	cfc1	$t6,$31
/*  f154bc4:	00000000 */ 	nop
/*  f154bc8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f154bcc:	15c00005 */ 	bnez	$t6,.L0f154be4
/*  f154bd0:	00000000 */ 	nop
/*  f154bd4:	440e4000 */ 	mfc1	$t6,$f8
/*  f154bd8:	3c018000 */ 	lui	$at,0x8000
/*  f154bdc:	10000007 */ 	b	.L0f154bfc
/*  f154be0:	01c17025 */ 	or	$t6,$t6,$at
.L0f154be4:
/*  f154be4:	10000005 */ 	b	.L0f154bfc
/*  f154be8:	240effff */ 	addiu	$t6,$zero,-1
/*  f154bec:	440e4000 */ 	mfc1	$t6,$f8
.L0f154bf0:
/*  f154bf0:	00000000 */ 	nop
/*  f154bf4:	05c0fffb */ 	bltz	$t6,.L0f154be4
/*  f154bf8:	00000000 */ 	nop
.L0f154bfc:
/*  f154bfc:	44cdf800 */ 	ctc1	$t5,$31
/*  f154c00:	0fc01a40 */ 	jal	colourBlend
/*  f154c04:	00ee3023 */ 	subu	$a2,$a3,$t6
/*  f154c08:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f154c0c:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f154c10:	10000051 */ 	b	.L0f154d58
/*  f154c14:	00408025 */ 	or	$s0,$v0,$zero
/*  f154c18:	44818000 */ 	mtc1	$at,$f16
.L0f154c1c:
/*  f154c1c:	3c014248 */ 	lui	$at,0x4248
/*  f154c20:	3c198008 */ 	lui	$t9,%hi(var8007fbc8)
/*  f154c24:	46107280 */ 	add.s	$f10,$f14,$f16
/*  f154c28:	02002825 */ 	or	$a1,$s0,$zero
/*  f154c2c:	460a0101 */ 	sub.s	$f4,$f0,$f10
/*  f154c30:	460c203c */ 	c.lt.s	$f4,$f12
/*  f154c34:	00000000 */ 	nop
/*  f154c38:	4502000a */ 	bc1fl	.L0f154c64
/*  f154c3c:	44819000 */ 	mtc1	$at,$f18
/*  f154c40:	8f39fbc8 */ 	lw	$t9,%lo(var8007fbc8)($t9)
/*  f154c44:	240600c0 */ 	addiu	$a2,$zero,0xc0
/*  f154c48:	0fc01a40 */ 	jal	colourBlend
/*  f154c4c:	03222025 */ 	or	$a0,$t9,$v0
/*  f154c50:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f154c54:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f154c58:	1000003f */ 	b	.L0f154d58
/*  f154c5c:	00408025 */ 	or	$s0,$v0,$zero
/*  f154c60:	44819000 */ 	mtc1	$at,$f18
.L0f154c64:
/*  f154c64:	00000000 */ 	nop
/*  f154c68:	46127180 */ 	add.s	$f6,$f14,$f18
/*  f154c6c:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f154c70:	46080081 */ 	sub.s	$f2,$f0,$f8
/*  f154c74:	460c103c */ 	c.lt.s	$f2,$f12
/*  f154c78:	00000000 */ 	nop
/*  f154c7c:	45020037 */ 	bc1fl	.L0f154d5c
/*  f154c80:	912a0000 */ 	lbu	$t2,0x0($t1)
/*  f154c84:	46026281 */ 	sub.s	$f10,$f12,$f2
/*  f154c88:	3c01437f */ 	lui	$at,0x437f
/*  f154c8c:	44813000 */ 	mtc1	$at,$f6
/*  f154c90:	3c188008 */ 	lui	$t8,%hi(var8007fbc8)
/*  f154c94:	46125103 */ 	div.s	$f4,$f10,$f18
/*  f154c98:	8f18fbc8 */ 	lw	$t8,%lo(var8007fbc8)($t8)
/*  f154c9c:	02002825 */ 	or	$a1,$s0,$zero
/*  f154ca0:	240600c0 */ 	addiu	$a2,$zero,0xc0
/*  f154ca4:	03022025 */ 	or	$a0,$t8,$v0
/*  f154ca8:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f154cac:	0fc01a40 */ 	jal	colourBlend
/*  f154cb0:	e7a80044 */ 	swc1	$f8,0x44($sp)
/*  f154cb4:	444ff800 */ 	cfc1	$t7,$31
/*  f154cb8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f154cbc:	44cbf800 */ 	ctc1	$t3,$31
/*  f154cc0:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*  f154cc4:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f154cc8:	02002025 */ 	or	$a0,$s0,$zero
/*  f154ccc:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f154cd0:	00402825 */ 	or	$a1,$v0,$zero
/*  f154cd4:	3c014f00 */ 	lui	$at,0x4f00
/*  f154cd8:	444bf800 */ 	cfc1	$t3,$31
/*  f154cdc:	00000000 */ 	nop
/*  f154ce0:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f154ce4:	51600013 */ 	beqzl	$t3,.L0f154d34
/*  f154ce8:	440b2000 */ 	mfc1	$t3,$f4
/*  f154cec:	44812000 */ 	mtc1	$at,$f4
/*  f154cf0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f154cf4:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f154cf8:	44cbf800 */ 	ctc1	$t3,$31
/*  f154cfc:	00000000 */ 	nop
/*  f154d00:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f154d04:	444bf800 */ 	cfc1	$t3,$31
/*  f154d08:	00000000 */ 	nop
/*  f154d0c:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f154d10:	15600005 */ 	bnez	$t3,.L0f154d28
/*  f154d14:	00000000 */ 	nop
/*  f154d18:	440b2000 */ 	mfc1	$t3,$f4
/*  f154d1c:	3c018000 */ 	lui	$at,0x8000
/*  f154d20:	10000007 */ 	b	.L0f154d40
/*  f154d24:	01615825 */ 	or	$t3,$t3,$at
.L0f154d28:
/*  f154d28:	10000005 */ 	b	.L0f154d40
/*  f154d2c:	240bffff */ 	addiu	$t3,$zero,-1
/*  f154d30:	440b2000 */ 	mfc1	$t3,$f4
.L0f154d34:
/*  f154d34:	00000000 */ 	nop
/*  f154d38:	0560fffb */ 	bltz	$t3,.L0f154d28
/*  f154d3c:	00000000 */ 	nop
.L0f154d40:
/*  f154d40:	44cff800 */ 	ctc1	$t7,$31
/*  f154d44:	0fc01a40 */ 	jal	colourBlend
/*  f154d48:	00eb3023 */ 	subu	$a2,$a3,$t3
/*  f154d4c:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f154d50:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f154d54:	00408025 */ 	or	$s0,$v0,$zero
.L0f154d58:
/*  f154d58:	912a0000 */ 	lbu	$t2,0x0($t1)
.L0f154d5c:
/*  f154d5c:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f154d60:	314c0004 */ 	andi	$t4,$t2,0x4
/*  f154d64:	51800055 */ 	beqzl	$t4,.L0f154ebc
/*  f154d68:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f154d6c:	8d2d004c */ 	lw	$t5,0x4c($t1)
/*  f154d70:	8d380050 */ 	lw	$t8,0x50($t1)
/*  f154d74:	8fab00ac */ 	lw	$t3,0xac($sp)
/*  f154d78:	01aec823 */ 	subu	$t9,$t5,$t6
/*  f154d7c:	03387821 */ 	addu	$t7,$t9,$t8
/*  f154d80:	01eb5023 */ 	subu	$t2,$t7,$t3
/*  f154d84:	254c0320 */ 	addiu	$t4,$t2,0x320
/*  f154d88:	448c3000 */ 	mtc1	$t4,$f6
/*  f154d8c:	8d2d0054 */ 	lw	$t5,0x54($t1)
/*  f154d90:	3c014080 */ 	lui	$at,0x4080
/*  f154d94:	46803020 */ 	cvt.s.w	$f0,$f6
/*  f154d98:	44811000 */ 	mtc1	$at,$f2
/*  f154d9c:	448d5000 */ 	mtc1	$t5,$f10
/*  f154da0:	3c013f80 */ 	lui	$at,0x3f80
/*  f154da4:	44816000 */ 	mtc1	$at,$f12
/*  f154da8:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f154dac:	46001202 */ 	mul.s	$f8,$f2,$f0
/*  f154db0:	3c013e80 */ 	lui	$at,0x3e80
/*  f154db4:	44813000 */ 	mtc1	$at,$f6
/*  f154db8:	3c014000 */ 	lui	$at,0x4000
/*  f154dbc:	320200ff */ 	andi	$v0,$s0,0xff
/*  f154dc0:	3c188008 */ 	lui	$t8,%hi(var8007fbbc)
/*  f154dc4:	3c0a8008 */ 	lui	$t2,%hi(var8007fbb8)
/*  f154dc8:	46044003 */ 	div.s	$f0,$f8,$f4
/*  f154dcc:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f154dd0:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f154dd4:	44194000 */ 	mfc1	$t9,$f8
/*  f154dd8:	00000000 */ 	nop
/*  f154ddc:	44992000 */ 	mtc1	$t9,$f4
/*  f154de0:	00000000 */ 	nop
/*  f154de4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f154de8:	44802000 */ 	mtc1	$zero,$f4
/*  f154dec:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f154df0:	460a0001 */ 	sub.s	$f0,$f0,$f10
/*  f154df4:	460c0001 */ 	sub.s	$f0,$f0,$f12
/*  f154df8:	4600603c */ 	c.lt.s	$f12,$f0
/*  f154dfc:	00000000 */ 	nop
/*  f154e00:	45020005 */ 	bc1fl	.L0f154e18
/*  f154e04:	4604003c */ 	c.lt.s	$f0,$f4
/*  f154e08:	44814000 */ 	mtc1	$at,$f8
/*  f154e0c:	00000000 */ 	nop
/*  f154e10:	46004001 */ 	sub.s	$f0,$f8,$f0
/*  f154e14:	4604003c */ 	c.lt.s	$f0,$f4
.L0f154e18:
/*  f154e18:	00000000 */ 	nop
/*  f154e1c:	45000015 */ 	bc1f	.L0f154e74
/*  f154e20:	00000000 */ 	nop
/*  f154e24:	8f18fbbc */ 	lw	$t8,%lo(var8007fbbc)($t8)
/*  f154e28:	44802000 */ 	mtc1	$zero,$f4
/*  f154e2c:	3c014f80 */ 	lui	$at,0x4f80
/*  f154e30:	44983000 */ 	mtc1	$t8,$f6
/*  f154e34:	07010004 */ 	bgez	$t8,.L0f154e48
/*  f154e38:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f154e3c:	44814000 */ 	mtc1	$at,$f8
/*  f154e40:	00000000 */ 	nop
/*  f154e44:	46085280 */ 	add.s	$f10,$f10,$f8
.L0f154e48:
/*  f154e48:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f154e4c:	8d2b0058 */ 	lw	$t3,0x58($t1)
/*  f154e50:	02002825 */ 	or	$a1,$s0,$zero
/*  f154e54:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f154e58:	004b2025 */ 	or	$a0,$v0,$t3
/*  f154e5c:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f154e60:	44062000 */ 	mfc1	$a2,$f4
/*  f154e64:	0fc01a40 */ 	jal	colourBlend
/*  f154e68:	00000000 */ 	nop
/*  f154e6c:	10000012 */ 	b	.L0f154eb8
/*  f154e70:	00408025 */ 	or	$s0,$v0,$zero
.L0f154e74:
/*  f154e74:	8d4afbb8 */ 	lw	$t2,%lo(var8007fbb8)($t2)
/*  f154e78:	3c014f80 */ 	lui	$at,0x4f80
/*  f154e7c:	448a5000 */ 	mtc1	$t2,$f10
/*  f154e80:	05410004 */ 	bgez	$t2,.L0f154e94
/*  f154e84:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f154e88:	44814000 */ 	mtc1	$at,$f8
/*  f154e8c:	00000000 */ 	nop
/*  f154e90:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f154e94:
/*  f154e94:	46003102 */ 	mul.s	$f4,$f6,$f0
/*  f154e98:	8d2d005c */ 	lw	$t5,0x5c($t1)
/*  f154e9c:	02002825 */ 	or	$a1,$s0,$zero
/*  f154ea0:	004d2025 */ 	or	$a0,$v0,$t5
/*  f154ea4:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f154ea8:	44065000 */ 	mfc1	$a2,$f10
/*  f154eac:	0fc01a40 */ 	jal	colourBlend
/*  f154eb0:	00000000 */ 	nop
/*  f154eb4:	00408025 */ 	or	$s0,$v0,$zero
.L0f154eb8:
/*  f154eb8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f154ebc:
/*  f154ebc:	02001025 */ 	or	$v0,$s0,$zero
/*  f154ec0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f154ec4:	03e00008 */ 	jr	$ra
/*  f154ec8:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

Gfx *func0f154ecc(Gfx *gdl, u32 arg1, u32 arg2)
{
	u32 colour = func0f1543ac(arg1, arg2, var800a45d0.colour04);

	if (colour != var800a45d0.colour44) {
		gDPSetPrimColorViaWord(gdl++, 0, 0, colour);
	}

	var800a45d0.colour44 = colour;

	return gdl;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f155c4cpf
.late_rodata
glabel var7f1b8738pf
.word 0x7f155d1c
glabel var7f1b873cpf
.word 0x7f155d24
glabel var7f1b8740pf
.word 0x7f155d24
glabel var7f1b8744pf
.word 0x7f155d24
glabel var7f1b8748pf
.word 0x7f155d24
glabel var7f1b874cpf
.word 0x7f155d24
glabel var7f1b8750pf
.word 0x7f155d24
glabel var7f1b8754pf
.word 0x7f155d24
glabel var7f1b8758pf
.word 0x7f155d24
glabel var7f1b875cpf
.word 0x7f155d1c
glabel var7f1b8760pf
.word 0x7f155d24
glabel var7f1b8764pf
.word 0x7f155d24
glabel var7f1b8768pf
.word 0x7f155d24
glabel var7f1b876cpf
.word 0x7f155d24
glabel var7f1b8770pf
.word 0x7f155d24
glabel var7f1b8774pf
.word 0x7f155d1c
glabel var7f1b8778pf
.word 0x7f155d24
glabel var7f1b877cpf
.word 0x7f155d24
glabel var7f1b8780pf
.word 0x7f155d24
glabel var7f1b8784pf
.word 0x7f155d24
glabel var7f1b8788pf
.word 0x7f155d24
glabel var7f1b878cpf
.word 0x7f155d24
glabel var7f1b8790pf
.word 0x7f155d24
glabel var7f1b8794pf
.word 0x7f155d24
glabel var7f1b8798pf
.word 0x7f155d24
glabel var7f1b879cpf
.word 0x7f155d24
glabel var7f1b87a0pf
.word 0x7f155d24
glabel var7f1b87a4pf
.word 0x7f155d24
glabel var7f1b87a8pf
.word 0x7f155d24
glabel var7f1b87acpf
.word 0x7f155d24
glabel var7f1b87b0pf
.word 0x7f155d1c
glabel var7f1b87b4pf
.word 0x7f155c74
glabel var7f1b87b8pf
.word 0x7f155c74
glabel var7f1b87bcpf
.word 0x7f155d24
glabel var7f1b87c0pf
.word 0x7f155d24
glabel var7f1b87c4pf
.word 0x7f155c74
glabel var7f1b87c8pf
.word 0x7f155d24
glabel var7f1b87ccpf
.word 0x7f155d24
glabel var7f1b87d0pf
.word 0x7f155d24
glabel var7f1b87d4pf
.word 0x7f155c80
glabel var7f1b87d8pf
.word 0x7f155c80
glabel var7f1b87dcpf
.word 0x7f155d24
glabel var7f1b87e0pf
.word 0x7f155d24
glabel var7f1b87e4pf
.word 0x7f155c8c
glabel var7f1b87e8pf
.word 0x7f155c8c
glabel var7f1b87ecpf
.word 0x7f155d24
glabel var7f1b87f0pf
.word 0x7f155d24
glabel var7f1b87f4pf
.word 0x7f155d24
glabel var7f1b87f8pf
.word 0x7f155cec
glabel var7f1b87fcpf
.word 0x7f155c98
glabel var7f1b8800pf
.word 0x7f155c98
glabel var7f1b8804pf
.word 0x7f155d24
glabel var7f1b8808pf
.word 0x7f155d24
glabel var7f1b880cpf
.word 0x7f155c98
glabel var7f1b8810pf
.word 0x7f155d24
glabel var7f1b8814pf
.word 0x7f155d24
glabel var7f1b8818pf
.word 0x7f155ca4
glabel var7f1b881cpf
.word 0x7f155ca4
glabel var7f1b8820pf
.word 0x7f155d24
glabel var7f1b8824pf
.word 0x7f155ca4
glabel var7f1b8828pf
.word 0x7f155d24
glabel var7f1b882cpf
.word 0x7f155d24
glabel var7f1b8830pf
.word 0x7f155d10
glabel var7f1b8834pf
.word 0x7f155cb0
glabel var7f1b8838pf
.word 0x7f155cb0
glabel var7f1b883cpf
.word 0x7f155cb0
glabel var7f1b8840pf
.word 0x7f155d24
glabel var7f1b8844pf
.word 0x7f155cb0
glabel var7f1b8848pf
.word 0x7f155d24
glabel var7f1b884cpf
.word 0x7f155d24
glabel var7f1b8850pf
.word 0x7f155d04
glabel var7f1b8854pf
.word 0x7f155cbc
glabel var7f1b8858pf
.word 0x7f155cbc
glabel var7f1b885cpf
.word 0x7f155cbc
glabel var7f1b8860pf
.word 0x7f155cbc
glabel var7f1b8864pf
.word 0x7f155cc8
glabel var7f1b8868pf
.word 0x7f155cc8
glabel var7f1b886cpf
.word 0x7f155cc8
glabel var7f1b8870pf
.word 0x7f155cc8
glabel var7f1b8874pf
.word 0x7f155d24
glabel var7f1b8878pf
.word 0x7f155cf8
glabel var7f1b887cpf
.word 0x7f155cd4
glabel var7f1b8880pf
.word 0x7f155cd4
glabel var7f1b8884pf
.word 0x7f155cd4
glabel var7f1b8888pf
.word 0x7f155d24
glabel var7f1b888cpf
.word 0x7f155cd4
glabel var7f1b8890pf
.word 0x7f155d24
glabel var7f1b8894pf
.word 0x7f155d24
glabel var7f1b8898pf
.word 0x7f155ce0
glabel var7f1b889cpf
.word 0x7f155ce0
glabel var7f1b88a0pf
.word 0x7f155ce0
glabel var7f1b88a4pf
.word 0x7f155ce0
.text
/*  f155c4c:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f155c50:	25cfff5f */ 	addiu	$t7,$t6,-161
/*  f155c54:	2de1005c */ 	sltiu	$at,$t7,0x5c
/*  f155c58:	10200032 */ 	beqz	$at,.PF0f155d24
/*  f155c5c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f155c60:	3c017f1c */ 	lui	$at,0x7f1c
/*  f155c64:	002f0821 */ 	addu	$at,$at,$t7
/*  f155c68:	8c2f8738 */ 	lw	$t7,-0x78c8($at)
/*  f155c6c:	01e00008 */ 	jr	$t7
/*  f155c70:	00000000 */ 	nop
/*  f155c74:	24180041 */ 	li	$t8,0x41
/*  f155c78:	03e00008 */ 	jr	$ra
/*  f155c7c:	a0980000 */ 	sb	$t8,0x0($a0)
/*  f155c80:	24190045 */ 	li	$t9,0x45
/*  f155c84:	03e00008 */ 	jr	$ra
/*  f155c88:	a0990000 */ 	sb	$t9,0x0($a0)
/*  f155c8c:	24080049 */ 	li	$t0,0x49
/*  f155c90:	03e00008 */ 	jr	$ra
/*  f155c94:	a0880000 */ 	sb	$t0,0x0($a0)
/*  f155c98:	2409004f */ 	li	$t1,0x4f
/*  f155c9c:	03e00008 */ 	jr	$ra
/*  f155ca0:	a0890000 */ 	sb	$t1,0x0($a0)
/*  f155ca4:	240a0055 */ 	li	$t2,0x55
/*  f155ca8:	03e00008 */ 	jr	$ra
/*  f155cac:	a08a0000 */ 	sb	$t2,0x0($a0)
/*  f155cb0:	240b0061 */ 	li	$t3,0x61
/*  f155cb4:	03e00008 */ 	jr	$ra
/*  f155cb8:	a08b0000 */ 	sb	$t3,0x0($a0)
/*  f155cbc:	240c0065 */ 	li	$t4,0x65
/*  f155cc0:	03e00008 */ 	jr	$ra
/*  f155cc4:	a08c0000 */ 	sb	$t4,0x0($a0)
/*  f155cc8:	240d0069 */ 	li	$t5,0x69
/*  f155ccc:	03e00008 */ 	jr	$ra
/*  f155cd0:	a08d0000 */ 	sb	$t5,0x0($a0)
/*  f155cd4:	240e006f */ 	li	$t6,0x6f
/*  f155cd8:	03e00008 */ 	jr	$ra
/*  f155cdc:	a08e0000 */ 	sb	$t6,0x0($a0)
/*  f155ce0:	240f0075 */ 	li	$t7,0x75
/*  f155ce4:	03e00008 */ 	jr	$ra
/*  f155ce8:	a08f0000 */ 	sb	$t7,0x0($a0)
/*  f155cec:	2418004e */ 	li	$t8,0x4e
/*  f155cf0:	03e00008 */ 	jr	$ra
/*  f155cf4:	a0980000 */ 	sb	$t8,0x0($a0)
/*  f155cf8:	2419006e */ 	li	$t9,0x6e
/*  f155cfc:	03e00008 */ 	jr	$ra
/*  f155d00:	a0990000 */ 	sb	$t9,0x0($a0)
/*  f155d04:	24080063 */ 	li	$t0,0x63
/*  f155d08:	03e00008 */ 	jr	$ra
/*  f155d0c:	a0880000 */ 	sb	$t0,0x0($a0)
/*  f155d10:	24090042 */ 	li	$t1,0x42
/*  f155d14:	03e00008 */ 	jr	$ra
/*  f155d18:	a0890000 */ 	sb	$t1,0x0($a0)
/*  f155d1c:	240a0020 */ 	li	$t2,0x20
/*  f155d20:	a08a0000 */ 	sb	$t2,0x0($a0)
.PF0f155d24:
/*  f155d24:	03e00008 */ 	jr	$ra
/*  f155d28:	00000000 */ 	nop
);
#endif

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f155d2cpf
.late_rodata
glabel var7f1b88a8pf
.word 0x7f155f94
glabel var7f1b88acpf
.word 0x7f155fc8
glabel var7f1b88b0pf
.word 0x7f155fc8
glabel var7f1b88b4pf
.word 0x7f155fc8
glabel var7f1b88b8pf
.word 0x7f155fc8
glabel var7f1b88bcpf
.word 0x7f155fc8
glabel var7f1b88c0pf
.word 0x7f155fc8
glabel var7f1b88c4pf
.word 0x7f155fc8
glabel var7f1b88c8pf
.word 0x7f155fc8
glabel var7f1b88ccpf
.word 0x7f155fa4
glabel var7f1b88d0pf
.word 0x7f155fc8
glabel var7f1b88d4pf
.word 0x7f155fc8
glabel var7f1b88d8pf
.word 0x7f155fc8
glabel var7f1b88dcpf
.word 0x7f155fc8
glabel var7f1b88e0pf
.word 0x7f155fc8
glabel var7f1b88e4pf
.word 0x7f155f9c
glabel var7f1b88e8pf
.word 0x7f155fc8
glabel var7f1b88ecpf
.word 0x7f155fc8
glabel var7f1b88f0pf
.word 0x7f155fc8
glabel var7f1b88f4pf
.word 0x7f155fc8
glabel var7f1b88f8pf
.word 0x7f155fc8
glabel var7f1b88fcpf
.word 0x7f155fc8
glabel var7f1b8900pf
.word 0x7f155fc8
glabel var7f1b8904pf
.word 0x7f155fc8
glabel var7f1b8908pf
.word 0x7f155fc8
glabel var7f1b890cpf
.word 0x7f155fc8
glabel var7f1b8910pf
.word 0x7f155fc8
glabel var7f1b8914pf
.word 0x7f155fc8
glabel var7f1b8918pf
.word 0x7f155fc8
glabel var7f1b891cpf
.word 0x7f155fc8
glabel var7f1b8920pf
.word 0x7f155f8c
glabel var7f1b8924pf
.word 0x7f155e74
glabel var7f1b8928pf
.word 0x7f155e6c
glabel var7f1b892cpf
.word 0x7f155fc8
glabel var7f1b8930pf
.word 0x7f155fc8
glabel var7f1b8934pf
.word 0x7f155e64
glabel var7f1b8938pf
.word 0x7f155fc8
glabel var7f1b893cpf
.word 0x7f155fc8
glabel var7f1b8940pf
.word 0x7f155fc8
glabel var7f1b8944pf
.word 0x7f155e84
glabel var7f1b8948pf
.word 0x7f155e7c
glabel var7f1b894cpf
.word 0x7f155fc8
glabel var7f1b8950pf
.word 0x7f155fc8
glabel var7f1b8954pf
.word 0x7f155e94
glabel var7f1b8958pf
.word 0x7f155e8c
glabel var7f1b895cpf
.word 0x7f155fc8
glabel var7f1b8960pf
.word 0x7f155fc8
glabel var7f1b8964pf
.word 0x7f155fc8
glabel var7f1b8968pf
.word 0x7f155f6c
glabel var7f1b896cpf
.word 0x7f155eac
glabel var7f1b8970pf
.word 0x7f155ea4
glabel var7f1b8974pf
.word 0x7f155fc8
glabel var7f1b8978pf
.word 0x7f155fc8
glabel var7f1b897cpf
.word 0x7f155e9c
glabel var7f1b8980pf
.word 0x7f155fc8
glabel var7f1b8984pf
.word 0x7f155fc8
glabel var7f1b8988pf
.word 0x7f155ec4
glabel var7f1b898cpf
.word 0x7f155ebc
glabel var7f1b8990pf
.word 0x7f155fc8
glabel var7f1b8994pf
.word 0x7f155eb4
glabel var7f1b8998pf
.word 0x7f155fc8
glabel var7f1b899cpf
.word 0x7f155fc8
glabel var7f1b89a0pf
.word 0x7f155f84
glabel var7f1b89a4pf
.word 0x7f155edc
glabel var7f1b89a8pf
.word 0x7f155ed4
glabel var7f1b89acpf
.word 0x7f155ee4
glabel var7f1b89b0pf
.word 0x7f155fc8
glabel var7f1b89b4pf
.word 0x7f155ecc
glabel var7f1b89b8pf
.word 0x7f155fc8
glabel var7f1b89bcpf
.word 0x7f155fc8
glabel var7f1b89c0pf
.word 0x7f155f7c
glabel var7f1b89c4pf
.word 0x7f155f04
glabel var7f1b89c8pf
.word 0x7f155ef4
glabel var7f1b89ccpf
.word 0x7f155eec
glabel var7f1b89d0pf
.word 0x7f155efc
glabel var7f1b89d4pf
.word 0x7f155f0c
glabel var7f1b89d8pf
.word 0x7f155f1c
glabel var7f1b89dcpf
.word 0x7f155f24
glabel var7f1b89e0pf
.word 0x7f155f14
glabel var7f1b89e4pf
.word 0x7f155fc8
glabel var7f1b89e8pf
.word 0x7f155f74
glabel var7f1b89ecpf
.word 0x7f155f44
glabel var7f1b89f0pf
.word 0x7f155f3c
glabel var7f1b89f4pf
.word 0x7f155f2c
glabel var7f1b89f8pf
.word 0x7f155fc8
glabel var7f1b89fcpf
.word 0x7f155f34
glabel var7f1b8a00pf
.word 0x7f155fc8
glabel var7f1b8a04pf
.word 0x7f155fc8
glabel var7f1b8a08pf
.word 0x7f155f4c
glabel var7f1b8a0cpf
.word 0x7f155f5c
glabel var7f1b8a10pf
.word 0x7f155f64
glabel var7f1b8a14pf
.word 0x7f155f54
.text
/*  f155d2c:	3c0e8008 */ 	lui	$t6,0x8008
/*  f155d30:	8dce4660 */ 	lw	$t6,0x4660($t6)
/*  f155d34:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f155d38:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f155d3c:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f155d40:	11c0002d */ 	beqz	$t6,.PF0f155df8
/*  f155d44:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f155d48:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f155d4c:	2405000c */ 	li	$a1,0xc
/*  f155d50:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f155d54:	93020000 */ 	lbu	$v0,0x0($t8)
/*  f155d58:	28410080 */ 	slti	$at,$v0,0x80
/*  f155d5c:	50200018 */ 	beqzl	$at,.PF0f155dc0
/*  f155d60:	906b0000 */ 	lbu	$t3,0x0($v1)
/*  f155d64:	00450019 */ 	multu	$v0,$a1
/*  f155d68:	8faa002c */ 	lw	$t2,0x2c($sp)
/*  f155d6c:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f155d70:	0000c812 */ 	mflo	$t9
/*  f155d74:	03274021 */ 	addu	$t0,$t9,$a3
/*  f155d78:	2509fe74 */ 	addiu	$t1,$t0,-396
/*  f155d7c:	ad490000 */ 	sw	$t1,0x0($t2)
/*  f155d80:	906b0000 */ 	lbu	$t3,0x0($v1)
/*  f155d84:	01650019 */ 	multu	$t3,$a1
/*  f155d88:	00006012 */ 	mflo	$t4
/*  f155d8c:	01876821 */ 	addu	$t5,$t4,$a3
/*  f155d90:	25aefe74 */ 	addiu	$t6,$t5,-396
/*  f155d94:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f155d98:	8faf0028 */ 	lw	$t7,0x28($sp)
/*  f155d9c:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f155da0:	93190000 */ 	lbu	$t9,0x0($t8)
/*  f155da4:	a0790000 */ 	sb	$t9,0x0($v1)
/*  f155da8:	8fa80028 */ 	lw	$t0,0x28($sp)
/*  f155dac:	8d090000 */ 	lw	$t1,0x0($t0)
/*  f155db0:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f155db4:	100000b2 */ 	b	.PF0f156080
/*  f155db8:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f155dbc:	906b0000 */ 	lbu	$t3,0x0($v1)
.PF0f155dc0:
/*  f155dc0:	2405000c */ 	li	$a1,0xc
/*  f155dc4:	8faf002c */ 	lw	$t7,0x2c($sp)
/*  f155dc8:	01650019 */ 	multu	$t3,$a1
/*  f155dcc:	00006012 */ 	mflo	$t4
/*  f155dd0:	01876821 */ 	addu	$t5,$t4,$a3
/*  f155dd4:	25aefe74 */ 	addiu	$t6,$t5,-396
/*  f155dd8:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f155ddc:	90780000 */ 	lbu	$t8,0x0($v1)
/*  f155de0:	03050019 */ 	multu	$t8,$a1
/*  f155de4:	0000c812 */ 	mflo	$t9
/*  f155de8:	03274821 */ 	addu	$t1,$t9,$a3
/*  f155dec:	252afe74 */ 	addiu	$t2,$t1,-396
/*  f155df0:	100000a3 */ 	b	.PF0f156080
/*  f155df4:	acca0000 */ 	sw	$t2,0x0($a2)
.PF0f155df8:
/*  f155df8:	8fa80028 */ 	lw	$t0,0x28($sp)
/*  f155dfc:	3c0d8008 */ 	lui	$t5,0x8008
/*  f155e00:	8dad0070 */ 	lw	$t5,0x70($t5)
/*  f155e04:	8d0b0000 */ 	lw	$t3,0x0($t0)
/*  f155e08:	00001025 */ 	move	$v0,$zero
/*  f155e0c:	3c0e8008 */ 	lui	$t6,0x8008
/*  f155e10:	916c0000 */ 	lbu	$t4,0x0($t3)
/*  f155e14:	10ed0009 */ 	beq	$a3,$t5,.PF0f155e3c
/*  f155e18:	a3ac0027 */ 	sb	$t4,0x27($sp)
/*  f155e1c:	8dce0078 */ 	lw	$t6,0x78($t6)
/*  f155e20:	3c0f8008 */ 	lui	$t7,0x8008
/*  f155e24:	50ee0006 */ 	beql	$a3,$t6,.PF0f155e40
/*  f155e28:	93b80027 */ 	lbu	$t8,0x27($sp)
/*  f155e2c:	8def0068 */ 	lw	$t7,0x68($t7)
/*  f155e30:	27a40027 */ 	addiu	$a0,$sp,0x27
/*  f155e34:	54ef005e */ 	bnel	$a3,$t7,.PF0f155fb0
/*  f155e38:	a3a20026 */ 	sb	$v0,0x26($sp)
.PF0f155e3c:
/*  f155e3c:	93b80027 */ 	lbu	$t8,0x27($sp)
.PF0f155e40:
/*  f155e40:	2719ff5f */ 	addiu	$t9,$t8,-161
/*  f155e44:	2f21005c */ 	sltiu	$at,$t9,0x5c
/*  f155e48:	1020005f */ 	beqz	$at,.PF0f155fc8
/*  f155e4c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f155e50:	3c017f1c */ 	lui	$at,0x7f1c
/*  f155e54:	00390821 */ 	addu	$at,$at,$t9
/*  f155e58:	8c3988a8 */ 	lw	$t9,-0x7758($at)
/*  f155e5c:	03200008 */ 	jr	$t9
/*  f155e60:	00000000 */ 	nop
/*  f155e64:	10000058 */ 	b	.PF0f155fc8
/*  f155e68:	2402005e */ 	li	$v0,0x5e
/*  f155e6c:	10000056 */ 	b	.PF0f155fc8
/*  f155e70:	24020066 */ 	li	$v0,0x66
/*  f155e74:	10000054 */ 	b	.PF0f155fc8
/*  f155e78:	24020070 */ 	li	$v0,0x70
/*  f155e7c:	10000052 */ 	b	.PF0f155fc8
/*  f155e80:	24020067 */ 	li	$v0,0x67
/*  f155e84:	10000050 */ 	b	.PF0f155fc8
/*  f155e88:	24020071 */ 	li	$v0,0x71
/*  f155e8c:	1000004e */ 	b	.PF0f155fc8
/*  f155e90:	24020068 */ 	li	$v0,0x68
/*  f155e94:	1000004c */ 	b	.PF0f155fc8
/*  f155e98:	24020072 */ 	li	$v0,0x72
/*  f155e9c:	1000004a */ 	b	.PF0f155fc8
/*  f155ea0:	2402005f */ 	li	$v0,0x5f
/*  f155ea4:	10000048 */ 	b	.PF0f155fc8
/*  f155ea8:	24020069 */ 	li	$v0,0x69
/*  f155eac:	10000046 */ 	b	.PF0f155fc8
/*  f155eb0:	24020073 */ 	li	$v0,0x73
/*  f155eb4:	10000044 */ 	b	.PF0f155fc8
/*  f155eb8:	24020060 */ 	li	$v0,0x60
/*  f155ebc:	10000042 */ 	b	.PF0f155fc8
/*  f155ec0:	2402006a */ 	li	$v0,0x6a
/*  f155ec4:	10000040 */ 	b	.PF0f155fc8
/*  f155ec8:	24020074 */ 	li	$v0,0x74
/*  f155ecc:	1000003e */ 	b	.PF0f155fc8
/*  f155ed0:	24020061 */ 	li	$v0,0x61
/*  f155ed4:	1000003c */ 	b	.PF0f155fc8
/*  f155ed8:	2402006b */ 	li	$v0,0x6b
/*  f155edc:	1000003a */ 	b	.PF0f155fc8
/*  f155ee0:	24020075 */ 	li	$v0,0x75
/*  f155ee4:	10000038 */ 	b	.PF0f155fc8
/*  f155ee8:	2402007a */ 	li	$v0,0x7a
/*  f155eec:	10000036 */ 	b	.PF0f155fc8
/*  f155ef0:	2402007b */ 	li	$v0,0x7b
/*  f155ef4:	10000034 */ 	b	.PF0f155fc8
/*  f155ef8:	2402006c */ 	li	$v0,0x6c
/*  f155efc:	10000032 */ 	b	.PF0f155fc8
/*  f155f00:	24020062 */ 	li	$v0,0x62
/*  f155f04:	10000030 */ 	b	.PF0f155fc8
/*  f155f08:	24020076 */ 	li	$v0,0x76
/*  f155f0c:	1000002e */ 	b	.PF0f155fc8
/*  f155f10:	24020077 */ 	li	$v0,0x77
/*  f155f14:	1000002c */ 	b	.PF0f155fc8
/*  f155f18:	24020063 */ 	li	$v0,0x63
/*  f155f1c:	1000002a */ 	b	.PF0f155fc8
/*  f155f20:	2402006d */ 	li	$v0,0x6d
/*  f155f24:	10000028 */ 	b	.PF0f155fc8
/*  f155f28:	2402007c */ 	li	$v0,0x7c
/*  f155f2c:	10000026 */ 	b	.PF0f155fc8
/*  f155f30:	2402007d */ 	li	$v0,0x7d
/*  f155f34:	10000024 */ 	b	.PF0f155fc8
/*  f155f38:	24020064 */ 	li	$v0,0x64
/*  f155f3c:	10000022 */ 	b	.PF0f155fc8
/*  f155f40:	2402006e */ 	li	$v0,0x6e
/*  f155f44:	10000020 */ 	b	.PF0f155fc8
/*  f155f48:	24020078 */ 	li	$v0,0x78
/*  f155f4c:	1000001e */ 	b	.PF0f155fc8
/*  f155f50:	24020079 */ 	li	$v0,0x79
/*  f155f54:	1000001c */ 	b	.PF0f155fc8
/*  f155f58:	24020065 */ 	li	$v0,0x65
/*  f155f5c:	1000001a */ 	b	.PF0f155fc8
/*  f155f60:	2402006f */ 	li	$v0,0x6f
/*  f155f64:	10000018 */ 	b	.PF0f155fc8
/*  f155f68:	2402007e */ 	li	$v0,0x7e
/*  f155f6c:	10000016 */ 	b	.PF0f155fc8
/*  f155f70:	2402007f */ 	li	$v0,0x7f
/*  f155f74:	10000014 */ 	b	.PF0f155fc8
/*  f155f78:	24020080 */ 	li	$v0,0x80
/*  f155f7c:	10000012 */ 	b	.PF0f155fc8
/*  f155f80:	24020081 */ 	li	$v0,0x81
/*  f155f84:	10000010 */ 	b	.PF0f155fc8
/*  f155f88:	24020082 */ 	li	$v0,0x82
/*  f155f8c:	1000000e */ 	b	.PF0f155fc8
/*  f155f90:	24020083 */ 	li	$v0,0x83
/*  f155f94:	1000000c */ 	b	.PF0f155fc8
/*  f155f98:	24020084 */ 	li	$v0,0x84
/*  f155f9c:	1000000a */ 	b	.PF0f155fc8
/*  f155fa0:	24020085 */ 	li	$v0,0x85
/*  f155fa4:	10000008 */ 	b	.PF0f155fc8
/*  f155fa8:	24020086 */ 	li	$v0,0x86
/*  f155fac:	a3a20026 */ 	sb	$v0,0x26($sp)
.PF0f155fb0:
/*  f155fb0:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f155fb4:	0fc55713 */ 	jal	0xf155c4c
/*  f155fb8:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f155fbc:	93a20026 */ 	lbu	$v0,0x26($sp)
/*  f155fc0:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f155fc4:	8fa70034 */ 	lw	$a3,0x34($sp)
.PF0f155fc8:
/*  f155fc8:	18400009 */ 	blez	$v0,.PF0f155ff0
/*  f155fcc:	00402025 */ 	move	$a0,$v0
/*  f155fd0:	00024880 */ 	sll	$t1,$v0,0x2
/*  f155fd4:	01224823 */ 	subu	$t1,$t1,$v0
/*  f155fd8:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*  f155fdc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f155fe0:	01275021 */ 	addu	$t2,$t1,$a3
/*  f155fe4:	2405000c */ 	li	$a1,0xc
/*  f155fe8:	10000014 */ 	b	.PF0f15603c
/*  f155fec:	ad0a0000 */ 	sw	$t2,0x0($t0)
.PF0f155ff0:
/*  f155ff0:	93a20027 */ 	lbu	$v0,0x27($sp)
/*  f155ff4:	240b0021 */ 	li	$t3,0x21
/*  f155ff8:	2405000c */ 	li	$a1,0xc
/*  f155ffc:	28410021 */ 	slti	$at,$v0,0x21
/*  f156000:	10200003 */ 	beqz	$at,.PF0f156010
/*  f156004:	240c0021 */ 	li	$t4,0x21
/*  f156008:	a3ab0027 */ 	sb	$t3,0x27($sp)
/*  f15600c:	24020021 */ 	li	$v0,0x21
.PF0f156010:
/*  f156010:	2841007f */ 	slti	$at,$v0,0x7f
/*  f156014:	14200003 */ 	bnez	$at,.PF0f156024
/*  f156018:	00000000 */ 	nop
/*  f15601c:	a3ac0027 */ 	sb	$t4,0x27($sp)
/*  f156020:	24020021 */ 	li	$v0,0x21
.PF0f156024:
/*  f156024:	00450019 */ 	multu	$v0,$a1
/*  f156028:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*  f15602c:	00006812 */ 	mflo	$t5
/*  f156030:	01a77021 */ 	addu	$t6,$t5,$a3
/*  f156034:	25cffe74 */ 	addiu	$t7,$t6,-396
/*  f156038:	af0f0000 */ 	sw	$t7,0x0($t8)
.PF0f15603c:
/*  f15603c:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f156040:	90790000 */ 	lbu	$t9,0x0($v1)
/*  f156044:	03250019 */ 	multu	$t9,$a1
/*  f156048:	00004812 */ 	mflo	$t1
/*  f15604c:	01275021 */ 	addu	$t2,$t1,$a3
/*  f156050:	2548fe74 */ 	addiu	$t0,$t2,-396
/*  f156054:	18800004 */ 	blez	$a0,.PF0f156068
/*  f156058:	acc80000 */ 	sw	$t0,0x0($a2)
/*  f15605c:	0fc55713 */ 	jal	0xf155c4c
/*  f156060:	27a40027 */ 	addiu	$a0,$sp,0x27
/*  f156064:	8fa30038 */ 	lw	$v1,0x38($sp)
.PF0f156068:
/*  f156068:	93ab0027 */ 	lbu	$t3,0x27($sp)
/*  f15606c:	a06b0000 */ 	sb	$t3,0x0($v1)
/*  f156070:	8fac0028 */ 	lw	$t4,0x28($sp)
/*  f156074:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f156078:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f15607c:	ad8e0000 */ 	sw	$t6,0x0($t4)
.PF0f156080:
/*  f156080:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f156084:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f156088:	03e00008 */ 	jr	$ra
/*  f15608c:	00000000 */ 	nop
);
#endif

GLOBAL_ASM(
glabel func0f154f38
/*  f154f38:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f154f3c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f154f40:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f154f44:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f154f48:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f154f4c:	8cef0004 */ 	lw	$t7,0x4($a3)
/*  f154f50:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f154f54:	8ccd0004 */ 	lw	$t5,0x4($a2)
/*  f154f58:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f154f5c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f154f60:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f154f64:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f154f68:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f154f6c:	01d96021 */ 	addu	$t4,$t6,$t9
/*  f154f70:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f154f74:	018fc021 */ 	addu	$t8,$t4,$t7
/*  f154f78:	3c198008 */ 	lui	$t9,%hi(var8007fac4)
/*  f154f7c:	8f39fac4 */ 	lw	$t9,%lo(var8007fac4)($t9)
/*  f154f80:	8f0e0000 */ 	lw	$t6,0x0($t8)
/*  f154f84:	8cad0000 */ 	lw	$t5,0x0($a1)
/*  f154f88:	3c18fd50 */ 	lui	$t8,0xfd50
/*  f154f8c:	01d94021 */ 	addu	$t0,$t6,$t9
/*  f154f90:	01a86023 */ 	subu	$t4,$t5,$t0
/*  f154f94:	258f0001 */ 	addiu	$t7,$t4,0x1
/*  f154f98:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f154f9c:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f154fa0:	8cce0008 */ 	lw	$t6,0x8($a2)
/*  f154fa4:	24900008 */ 	addiu	$s0,$a0,0x8
/*  f154fa8:	02001825 */ 	or	$v1,$s0,$zero
/*  f154fac:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f154fb0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f154fb4:	3c19e600 */ 	lui	$t9,0xe600
/*  f154fb8:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f154fbc:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f154fc0:	02004825 */ 	or	$t1,$s0,$zero
/*  f154fc4:	3c0df300 */ 	lui	$t5,0xf300
/*  f154fc8:	ad2d0000 */ 	sw	$t5,0x0($t1)
/*  f154fcc:	90ca0002 */ 	lbu	$t2,0x2($a2)
/*  f154fd0:	00c08825 */ 	or	$s1,$a2,$zero
/*  f154fd4:	00a09025 */ 	or	$s2,$a1,$zero
/*  f154fd8:	000a60c0 */ 	sll	$t4,$t2,0x3
/*  f154fdc:	258a0011 */ 	addiu	$t2,$t4,0x11
/*  f154fe0:	000a7843 */ 	sra	$t7,$t2,0x1
/*  f154fe4:	25eaffff */ 	addiu	$t2,$t7,-1
/*  f154fe8:	294107ff */ 	slti	$at,$t2,0x7ff
/*  f154fec:	10200003 */ 	beqz	$at,.L0f154ffc
/*  f154ff0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f154ff4:	10000002 */ 	b	.L0f155000
/*  f154ff8:	01403825 */ 	or	$a3,$t2,$zero
.L0f154ffc:
/*  f154ffc:	240707ff */ 	addiu	$a3,$zero,0x7ff
.L0f155000:
/*  f155000:	3c014120 */ 	lui	$at,0x4120
/*  f155004:	44816000 */ 	mtc1	$at,$f12
/*  f155008:	3c014220 */ 	lui	$at,0x4220
/*  f15500c:	44819000 */ 	mtc1	$at,$f18
/*  f155010:	30f80fff */ 	andi	$t8,$a3,0xfff
/*  f155014:	00187300 */ 	sll	$t6,$t8,0xc
/*  f155018:	3c010700 */ 	lui	$at,0x700
/*  f15501c:	01c1c825 */ 	or	$t9,$t6,$at
/*  f155020:	c7ae005c */ 	lwc1	$f14,0x5c($sp)
/*  f155024:	c7b00060 */ 	lwc1	$f16,0x60($sp)
/*  f155028:	372d0800 */ 	ori	$t5,$t9,0x800
/*  f15502c:	ad2d0004 */ 	sw	$t5,0x4($t1)
/*  f155030:	02001825 */ 	or	$v1,$s0,$zero
/*  f155034:	3c0ce700 */ 	lui	$t4,0xe700
/*  f155038:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f15503c:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f155040:	8e420000 */ 	lw	$v0,0x0($s2)
/*  f155044:	3c048008 */ 	lui	$a0,%hi(var8007fadc)
/*  f155048:	8c84fadc */ 	lw	$a0,%lo(var8007fadc)($a0)
/*  f15504c:	00027880 */ 	sll	$t7,$v0,0x2
/*  f155050:	c7a40064 */ 	lwc1	$f4,0x64($sp)
/*  f155054:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f155058:	44983000 */ 	mtc1	$t8,$f6
/*  f15505c:	46049002 */ 	mul.s	$f0,$f18,$f4
/*  f155060:	3c058008 */ 	lui	$a1,%hi(var8007fae0)
/*  f155064:	8ca5fae0 */ 	lw	$a1,%lo(var8007fae0)($a1)
/*  f155068:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15506c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f155070:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*  f155074:	00000000 */ 	nop
/*  f155078:	460c5102 */ 	mul.s	$f4,$f10,$f12
/*  f15507c:	c7aa0068 */ 	lwc1	$f10,0x68($sp)
/*  f155080:	460a9082 */ 	mul.s	$f2,$f18,$f10
/*  f155084:	46002180 */ 	add.s	$f6,$f4,$f0
/*  f155088:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f15508c:	44194000 */ 	mfc1	$t9,$f8
/*  f155090:	00000000 */ 	nop
/*  f155094:	a7b9003e */ 	sh	$t9,0x3e($sp)
/*  f155098:	82260001 */ 	lb	$a2,0x1($s1)
/*  f15509c:	00066880 */ 	sll	$t5,$a2,0x2
/*  f1550a0:	01a56021 */ 	addu	$t4,$t5,$a1
/*  f1550a4:	448c2000 */ 	mtc1	$t4,$f4
/*  f1550a8:	00000000 */ 	nop
/*  f1550ac:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1550b0:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f1550b4:	00000000 */ 	nop
/*  f1550b8:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f1550bc:	46025100 */ 	add.s	$f4,$f10,$f2
/*  f1550c0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f1550c4:	44183000 */ 	mfc1	$t8,$f6
/*  f1550c8:	00000000 */ 	nop
/*  f1550cc:	a7b8003c */ 	sh	$t8,0x3c($sp)
/*  f1550d0:	922a0003 */ 	lbu	$t2,0x3($s1)
/*  f1550d4:	004a7021 */ 	addu	$t6,$v0,$t2
/*  f1550d8:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f1550dc:	03246821 */ 	addu	$t5,$t9,$a0
/*  f1550e0:	25ac0004 */ 	addiu	$t4,$t5,0x4
/*  f1550e4:	448c4000 */ 	mtc1	$t4,$f8
/*  f1550e8:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f1550ec:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f1550f0:	460e5102 */ 	mul.s	$f4,$f10,$f14
/*  f1550f4:	00000000 */ 	nop
/*  f1550f8:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f1550fc:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f155100:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f155104:	44185000 */ 	mfc1	$t8,$f10
/*  f155108:	00000000 */ 	nop
/*  f15510c:	a7b8003a */ 	sh	$t8,0x3a($sp)
/*  f155110:	92270002 */ 	lbu	$a3,0x2($s1)
/*  f155114:	00c77021 */ 	addu	$t6,$a2,$a3
/*  f155118:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f15511c:	03256821 */ 	addu	$t5,$t9,$a1
/*  f155120:	25ac0004 */ 	addiu	$t4,$t5,0x4
/*  f155124:	448c2000 */ 	mtc1	$t4,$f4
/*  f155128:	00e0c825 */ 	or	$t9,$a3,$zero
/*  f15512c:	27270001 */ 	addiu	$a3,$t9,0x1
/*  f155130:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f155134:	25460001 */ 	addiu	$a2,$t2,0x1
/*  f155138:	00066980 */ 	sll	$t5,$a2,0x6
/*  f15513c:	25af0001 */ 	addiu	$t7,$t5,0x1
/*  f155140:	a7af0034 */ 	sh	$t7,0x34($sp)
/*  f155144:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f155148:	00000000 */ 	nop
/*  f15514c:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f155150:	46025100 */ 	add.s	$f4,$f10,$f2
/*  f155154:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f155158:	44183000 */ 	mfc1	$t8,$f6
/*  f15515c:	00000000 */ 	nop
/*  f155160:	a7b80038 */ 	sh	$t8,0x38($sp)
/*  f155164:	0007c180 */ 	sll	$t8,$a3,0x6
/*  f155168:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f15516c:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f155170:	a7b90030 */ 	sh	$t9,0x30($sp)
/*  f155174:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f155178:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f15517c:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f155180:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f155184:	3c0dff00 */ 	lui	$t5,0xff00
/*  f155188:	87a60034 */ 	lh	$a2,0x34($sp)
/*  f15518c:	87a70030 */ 	lh	$a3,0x30($sp)
/*  f155190:	35ad00ff */ 	ori	$t5,$t5,0xff
/*  f155194:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f155198:	2405fff6 */ 	addiu	$a1,$zero,-10
/*  f15519c:	a4650004 */ 	sh	$a1,0x4($v1)
/*  f1551a0:	a4650010 */ 	sh	$a1,0x10($v1)
/*  f1551a4:	a465001c */ 	sh	$a1,0x1c($v1)
/*  f1551a8:	a4650028 */ 	sh	$a1,0x28($v1)
/*  f1551ac:	a0600007 */ 	sb	$zero,0x7($v1)
/*  f1551b0:	a0600013 */ 	sb	$zero,0x13($v1)
/*  f1551b4:	a060001f */ 	sb	$zero,0x1f($v1)
/*  f1551b8:	a060002b */ 	sb	$zero,0x2b($v1)
/*  f1551bc:	87a8003e */ 	lh	$t0,0x3e($sp)
/*  f1551c0:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f1551c4:	00405825 */ 	or	$t3,$v0,$zero
/*  f1551c8:	05010003 */ 	bgez	$t0,.L0f1551d8
/*  f1551cc:	00086083 */ 	sra	$t4,$t0,0x2
/*  f1551d0:	25010003 */ 	addiu	$at,$t0,0x3
/*  f1551d4:	00016083 */ 	sra	$t4,$at,0x2
.L0f1551d8:
/*  f1551d8:	a46c0000 */ 	sh	$t4,0x0($v1)
/*  f1551dc:	87a4003c */ 	lh	$a0,0x3c($sp)
/*  f1551e0:	a46a0008 */ 	sh	$t2,0x8($v1)
/*  f1551e4:	a46a000a */ 	sh	$t2,0xa($v1)
/*  f1551e8:	01804025 */ 	or	$t0,$t4,$zero
/*  f1551ec:	04810003 */ 	bgez	$a0,.L0f1551fc
/*  f1551f0:	00047883 */ 	sra	$t7,$a0,0x2
/*  f1551f4:	24810003 */ 	addiu	$at,$a0,0x3
/*  f1551f8:	00017883 */ 	sra	$t7,$at,0x2
.L0f1551fc:
/*  f1551fc:	a46f0002 */ 	sh	$t7,0x2($v1)
/*  f155200:	87a9003a */ 	lh	$t1,0x3a($sp)
/*  f155204:	01e02025 */ 	or	$a0,$t7,$zero
/*  f155208:	a464000e */ 	sh	$a0,0xe($v1)
/*  f15520c:	05210003 */ 	bgez	$t1,.L0f15521c
/*  f155210:	0009c083 */ 	sra	$t8,$t1,0x2
/*  f155214:	25210003 */ 	addiu	$at,$t1,0x3
/*  f155218:	0001c083 */ 	sra	$t8,$at,0x2
.L0f15521c:
/*  f15521c:	a478000c */ 	sh	$t8,0xc($v1)
/*  f155220:	a46a0016 */ 	sh	$t2,0x16($v1)
/*  f155224:	a4780018 */ 	sh	$t8,0x18($v1)
/*  f155228:	a4660014 */ 	sh	$a2,0x14($v1)
/*  f15522c:	87a20038 */ 	lh	$v0,0x38($sp)
/*  f155230:	02002025 */ 	or	$a0,$s0,$zero
/*  f155234:	a4660020 */ 	sh	$a2,0x20($v1)
/*  f155238:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15523c:	3c190700 */ 	lui	$t9,0x700
/*  f155240:	a4680024 */ 	sh	$t0,0x24($v1)
/*  f155244:	a46a002c */ 	sh	$t2,0x2c($v1)
/*  f155248:	a4670022 */ 	sh	$a3,0x22($v1)
/*  f15524c:	a467002e */ 	sh	$a3,0x2e($v1)
/*  f155250:	37390004 */ 	ori	$t9,$t9,0x4
/*  f155254:	02002825 */ 	or	$a1,$s0,$zero
/*  f155258:	3c0d0430 */ 	lui	$t5,0x430
/*  f15525c:	35ad0030 */ 	ori	$t5,$t5,0x30
/*  f155260:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155264:	02003025 */ 	or	$a2,$s0,$zero
/*  f155268:	3c0cb100 */ 	lui	$t4,0xb100
/*  f15526c:	358c0002 */ 	ori	$t4,$t4,0x2
/*  f155270:	240f3210 */ 	addiu	$t7,$zero,0x3210
/*  f155274:	03004825 */ 	or	$t1,$t8,$zero
/*  f155278:	04410003 */ 	bgez	$v0,.L0f155288
/*  f15527c:	00027083 */ 	sra	$t6,$v0,0x2
/*  f155280:	24410003 */ 	addiu	$at,$v0,0x3
/*  f155284:	00017083 */ 	sra	$t6,$at,0x2
.L0f155288:
/*  f155288:	a46e001a */ 	sh	$t6,0x1a($v1)
/*  f15528c:	a46e0026 */ 	sh	$t6,0x26($v1)
/*  f155290:	ac8b0004 */ 	sw	$t3,0x4($a0)
/*  f155294:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f155298:	acad0000 */ 	sw	$t5,0x0($a1)
/*  f15529c:	aca30004 */ 	sw	$v1,0x4($a1)
/*  f1552a0:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f1552a4:	accc0000 */ 	sw	$t4,0x0($a2)
/*  f1552a8:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f1552ac:	922e0003 */ 	lbu	$t6,0x3($s1)
/*  f1552b0:	26020008 */ 	addiu	$v0,$s0,0x8
/*  f1552b4:	030ec821 */ 	addu	$t9,$t8,$t6
/*  f1552b8:	ae590000 */ 	sw	$t9,0x0($s2)
/*  f1552bc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1552c0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1552c4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1552c8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1552cc:	03e00008 */ 	jr	$ra
/*  f1552d0:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f1552d4
/*  f15642c:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f156430:	f7ba0048 */ 	sdc1	$f26,0x48($sp)
/*  f156434:	4487d000 */ 	mtc1	$a3,$f26
/*  f156438:	8fa700e8 */ 	lw	$a3,0xe8($sp)
/*  f15643c:	240e0048 */ 	li	$t6,0x48
/*  f156440:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f156444:	afbe0070 */ 	sw	$s8,0x70($sp)
/*  f156448:	afb7006c */ 	sw	$s7,0x6c($sp)
/*  f15644c:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f156450:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f156454:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f156458:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f15645c:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f156460:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f156464:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f156468:	f7b80040 */ 	sdc1	$f24,0x40($sp)
/*  f15646c:	f7b60038 */ 	sdc1	$f22,0x38($sp)
/*  f156470:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f156474:	afa500d4 */ 	sw	$a1,0xd4($sp)
/*  f156478:	afa600d8 */ 	sw	$a2,0xd8($sp)
/*  f15647c:	a3ae00cb */ 	sb	$t6,0xcb($sp)
/*  f156480:	afa000b8 */ 	sw	$zero,0xb8($sp)
/*  f156484:	3c198008 */ 	lui	$t9,0x8008
/*  f156488:	8f394660 */ 	lw	$t9,0x4660($t9)
/*  f15648c:	90f80446 */ 	lbu	$t8,0x446($a3)
/*  f156490:	80ef0445 */ 	lb	$t7,0x445($a3)
/*  f156494:	00808025 */ 	move	$s0,$a0
/*  f156498:	00008825 */ 	move	$s1,$zero
/*  f15649c:	13200005 */ 	beqz	$t9,.PF0f1564b4
/*  f1564a0:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f1564a4:	2841000e */ 	slti	$at,$v0,0xe
/*  f1564a8:	50200003 */ 	beqzl	$at,.PF0f1564b8
/*  f1564ac:	8fa800ec */ 	lw	$t0,0xec($sp)
/*  f1564b0:	2402000e */ 	li	$v0,0xe
.PF0f1564b4:
/*  f1564b4:	8fa800ec */ 	lw	$t0,0xec($sp)
.PF0f1564b8:
/*  f1564b8:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1564bc:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f1564c0:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f1564c4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1564c8:	afa200bc */ 	sw	$v0,0xbc($sp)
/*  f1564cc:	0fc5609a */ 	jal	0xf158268
/*  f1564d0:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f1564d4:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f1564d8:	3c013f80 */ 	lui	$at,0x3f80
/*  f1564dc:	44810000 */ 	mtc1	$at,$f0
/*  f1564e0:	44893000 */ 	mtc1	$t1,$f6
/*  f1564e4:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*  f1564e8:	4600d101 */ 	sub.s	$f4,$f26,$f0
/*  f1564ec:	3c013f00 */ 	lui	$at,0x3f00
/*  f1564f0:	44811000 */ 	mtc1	$at,$f2
/*  f1564f4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1564f8:	448a9000 */ 	mtc1	$t2,$f18
/*  f1564fc:	8fab00bc */ 	lw	$t3,0xbc($sp)
/*  f156500:	c7b800e0 */ 	lwc1	$f24,0xe0($sp)
/*  f156504:	8fac00f8 */ 	lw	$t4,0xf8($sp)
/*  f156508:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f15650c:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f156510:	448b9000 */ 	mtc1	$t3,$f18
/*  f156514:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f156518:	02001025 */ 	move	$v0,$s0
/*  f15651c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156520:	3c13e700 */ 	lui	$s3,0xe700
/*  f156524:	02001825 */ 	move	$v1,$s0
/*  f156528:	46025402 */ 	mul.s	$f16,$f10,$f2
/*  f15652c:	4600c281 */ 	sub.s	$f10,$f24,$f0
/*  f156530:	3c0dba00 */ 	lui	$t5,0xba00
/*  f156534:	35ad0e02 */ 	ori	$t5,$t5,0xe02
/*  f156538:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15653c:	340ec000 */ 	li	$t6,0xc000
/*  f156540:	02009025 */ 	move	$s2,$s0
/*  f156544:	46068102 */ 	mul.s	$f4,$f16,$f6
/*  f156548:	3c0ffd10 */ 	lui	$t7,0xfd10
/*  f15654c:	3c048008 */ 	lui	$a0,0x8008
/*  f156550:	2484009c */ 	addiu	$a0,$a0,0x9c
/*  f156554:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156558:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f15655c:	46044501 */ 	sub.s	$f20,$f8,$f4
/*  f156560:	46105182 */ 	mul.s	$f6,$f10,$f16
/*  f156564:	448c2000 */ 	mtc1	$t4,$f4
/*  f156568:	c7b000d8 */ 	lwc1	$f16,0xd8($sp)
/*  f15656c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f156570:	ac530000 */ 	sw	$s3,0x0($v0)
/*  f156574:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f156578:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f15657c:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f156580:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f156584:	ae4f0000 */ 	sw	$t7,0x0($s2)
/*  f156588:	46124282 */ 	mul.s	$f10,$f8,$f18
/*  f15658c:	0c012ab0 */ 	jal	0x4aac0
/*  f156590:	460a8581 */ 	sub.s	$f22,$f16,$f10
/*  f156594:	02001825 */ 	move	$v1,$s0
/*  f156598:	ae420004 */ 	sw	$v0,0x4($s2)
/*  f15659c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1565a0:	3c18e600 */ 	lui	$t8,0xe600
/*  f1565a4:	02002025 */ 	move	$a0,$s0
/*  f1565a8:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f1565ac:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f1565b0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1565b4:	3c080603 */ 	lui	$t0,0x603
/*  f1565b8:	3508c000 */ 	ori	$t0,$t0,0xc000
/*  f1565bc:	3c19f000 */ 	lui	$t9,0xf000
/*  f1565c0:	02002825 */ 	move	$a1,$s0
/*  f1565c4:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f1565c8:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f1565cc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1565d0:	3c09f540 */ 	lui	$t1,0xf540
/*  f1565d4:	35290200 */ 	ori	$t1,$t1,0x200
/*  f1565d8:	02003025 */ 	move	$a2,$s0
/*  f1565dc:	aca90000 */ 	sw	$t1,0x0($a1)
/*  f1565e0:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f1565e4:	3c0b0007 */ 	lui	$t3,0x7
/*  f1565e8:	356bc07c */ 	ori	$t3,$t3,0xc07c
/*  f1565ec:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1565f0:	3c0af200 */ 	lui	$t2,0xf200
/*  f1565f4:	acca0000 */ 	sw	$t2,0x0($a2)
/*  f1565f8:	accb0004 */ 	sw	$t3,0x4($a2)
/*  f1565fc:	02003825 */ 	move	$a3,$s0
/*  f156600:	3c0cfa00 */ 	lui	$t4,0xfa00
/*  f156604:	acec0000 */ 	sw	$t4,0x0($a3)
/*  f156608:	8fad00f0 */ 	lw	$t5,0xf0($sp)
/*  f15660c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156610:	02001025 */ 	move	$v0,$s0
/*  f156614:	aced0004 */ 	sw	$t5,0x4($a3)
/*  f156618:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f15661c:	ac530000 */ 	sw	$s3,0x0($v0)
/*  f156620:	8fae00e4 */ 	lw	$t6,0xe4($sp)
/*  f156624:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156628:	51c00045 */ 	beqzl	$t6,.PF0f156740
/*  f15662c:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f156630:	91c20000 */ 	lbu	$v0,0x0($t6)
/*  f156634:	27be0084 */ 	addiu	$s8,$sp,0x84
/*  f156638:	27b700e4 */ 	addiu	$s7,$sp,0xe4
/*  f15663c:	1040003f */ 	beqz	$v0,.PF0f15673c
/*  f156640:	3c168008 */ 	lui	$s6,0x8008
/*  f156644:	3c138008 */ 	lui	$s3,0x8008
/*  f156648:	26730030 */ 	addiu	$s3,$s3,0x30
/*  f15664c:	26d60034 */ 	addiu	$s6,$s6,0x34
/*  f156650:	2415000a */ 	li	$s5,0xa
/*  f156654:	24140005 */ 	li	$s4,0x5
/*  f156658:	24120020 */ 	li	$s2,0x20
.PF0f15665c:
/*  f15665c:	1642000d */ 	bne	$s2,$v0,.PF0f156694
/*  f156660:	00000000 */ 	nop
/*  f156664:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f156668:	8fa300b8 */ 	lw	$v1,0xb8($sp)
/*  f15666c:	8fa800e4 */ 	lw	$t0,0xe4($sp)
/*  f156670:	01f40019 */ 	multu	$t7,$s4
/*  f156674:	24190048 */ 	li	$t9,0x48
/*  f156678:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f15667c:	a3b900cb */ 	sb	$t9,0xcb($sp)
/*  f156680:	afa900e4 */ 	sw	$t1,0xe4($sp)
/*  f156684:	0000c012 */ 	mflo	$t8
/*  f156688:	03031821 */ 	addu	$v1,$t8,$v1
/*  f15668c:	10000027 */ 	b	.PF0f15672c
/*  f156690:	afa300b8 */ 	sw	$v1,0xb8($sp)
.PF0f156694:
/*  f156694:	16a20013 */ 	bne	$s5,$v0,.PF0f1566e4
/*  f156698:	02e02025 */ 	move	$a0,$s7
/*  f15669c:	8ec20000 */ 	lw	$v0,0x0($s6)
/*  f1566a0:	240a0048 */ 	li	$t2,0x48
/*  f1566a4:	8fa300b8 */ 	lw	$v1,0xb8($sp)
/*  f1566a8:	04400006 */ 	bltz	$v0,.PF0f1566c4
/*  f1566ac:	a3aa00cb */ 	sb	$t2,0xcb($sp)
/*  f1566b0:	54600005 */ 	bnezl	$v1,.PF0f1566c8
/*  f1566b4:	8fab00bc */ 	lw	$t3,0xbc($sp)
/*  f1566b8:	02228821 */ 	addu	$s1,$s1,$v0
/*  f1566bc:	10000004 */ 	b	.PF0f1566d0
/*  f1566c0:	00001825 */ 	move	$v1,$zero
.PF0f1566c4:
/*  f1566c4:	8fab00bc */ 	lw	$t3,0xbc($sp)
.PF0f1566c8:
/*  f1566c8:	00001825 */ 	move	$v1,$zero
/*  f1566cc:	022b8821 */ 	addu	$s1,$s1,$t3
.PF0f1566d0:
/*  f1566d0:	8fac00e4 */ 	lw	$t4,0xe4($sp)
/*  f1566d4:	afa300b8 */ 	sw	$v1,0xb8($sp)
/*  f1566d8:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f1566dc:	10000013 */ 	b	.PF0f15672c
/*  f1566e0:	afad00e4 */ 	sw	$t5,0xe4($sp)
.PF0f1566e4:
/*  f1566e4:	27ae00cb */ 	addiu	$t6,$sp,0xcb
/*  f1566e8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1566ec:	03c02825 */ 	move	$a1,$s8
/*  f1566f0:	27a60080 */ 	addiu	$a2,$sp,0x80
/*  f1566f4:	0fc5574b */ 	jal	0xf155d2c
/*  f1566f8:	8fa700e8 */ 	lw	$a3,0xe8($sp)
/*  f1566fc:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f156700:	02002025 */ 	move	$a0,$s0
/*  f156704:	27a500b8 */ 	addiu	$a1,$sp,0xb8
/*  f156708:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f15670c:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f156710:	e7ba0014 */ 	swc1	$f26,0x14($sp)
/*  f156714:	e7b80018 */ 	swc1	$f24,0x18($sp)
/*  f156718:	e7b4001c */ 	swc1	$f20,0x1c($sp)
/*  f15671c:	e7b60020 */ 	swc1	$f22,0x20($sp)
/*  f156720:	0fc55824 */ 	jal	0xf156090
/*  f156724:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f156728:	00408025 */ 	move	$s0,$v0
.PF0f15672c:
/*  f15672c:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f156730:	93020000 */ 	lbu	$v0,0x0($t8)
/*  f156734:	1440ffc9 */ 	bnez	$v0,.PF0f15665c
/*  f156738:	00000000 */ 	nop
.PF0f15673c:
/*  f15673c:	8fbf0074 */ 	lw	$ra,0x74($sp)
.PF0f156740:
/*  f156740:	02001025 */ 	move	$v0,$s0
/*  f156744:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f156748:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f15674c:	d7b60038 */ 	ldc1	$f22,0x38($sp)
/*  f156750:	d7b80040 */ 	ldc1	$f24,0x40($sp)
/*  f156754:	d7ba0048 */ 	ldc1	$f26,0x48($sp)
/*  f156758:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f15675c:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f156760:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f156764:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f156768:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f15676c:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f156770:	8fb7006c */ 	lw	$s7,0x6c($sp)
/*  f156774:	8fbe0070 */ 	lw	$s8,0x70($sp)
/*  f156778:	03e00008 */ 	jr	$ra
/*  f15677c:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);
#else
GLOBAL_ASM(
glabel func0f1552d4
/*  f1552d4:	27bdff28 */ 	addiu	$sp,$sp,-216
/*  f1552d8:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f1552dc:	8fb500f0 */ 	lw	$s5,0xf0($sp)
/*  f1552e0:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f1552e4:	afbe0070 */ 	sw	$s8,0x70($sp)
/*  f1552e8:	afb7006c */ 	sw	$s7,0x6c($sp)
/*  f1552ec:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f1552f0:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f1552f4:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f1552f8:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f1552fc:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f155300:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f155304:	f7ba0048 */ 	sdc1	$f26,0x48($sp)
/*  f155308:	f7b80040 */ 	sdc1	$f24,0x40($sp)
/*  f15530c:	f7b60038 */ 	sdc1	$f22,0x38($sp)
/*  f155310:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f155314:	afa500dc */ 	sw	$a1,0xdc($sp)
/*  f155318:	afa600e0 */ 	sw	$a2,0xe0($sp)
/*  f15531c:	afa000c0 */ 	sw	$zero,0xc0($sp)
/*  f155320:	3c188008 */ 	lui	$t8,%hi(g_LanguageId)
/*  f155324:	8f184120 */ 	lw	$t8,%lo(g_LanguageId)($t8)
/*  f155328:	92af0446 */ 	lbu	$t7,0x446($s5)
/*  f15532c:	82ae0445 */ 	lb	$t6,0x445($s5)
/*  f155330:	4487d000 */ 	mtc1	$a3,$f26
/*  f155334:	00808825 */ 	or	$s1,$a0,$zero
/*  f155338:	00009025 */ 	or	$s2,$zero,$zero
/*  f15533c:	24130048 */ 	addiu	$s3,$zero,0x48
/*  f155340:	13000005 */ 	beqz	$t8,.L0f155358
/*  f155344:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f155348:	2841000e */ 	slti	$at,$v0,0xe
/*  f15534c:	50200003 */ 	beqzl	$at,.L0f15535c
/*  f155350:	8fb000ec */ 	lw	$s0,0xec($sp)
/*  f155354:	2402000e */ 	addiu	$v0,$zero,0xe
.L0f155358:
/*  f155358:	8fb000ec */ 	lw	$s0,0xec($sp)
.L0f15535c:
/*  f15535c:	8fb900f4 */ 	lw	$t9,0xf4($sp)
/*  f155360:	27a400c8 */ 	addiu	$a0,$sp,0xc8
/*  f155364:	27a500cc */ 	addiu	$a1,$sp,0xcc
/*  f155368:	02a03825 */ 	or	$a3,$s5,$zero
/*  f15536c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f155370:	afa200c4 */ 	sw	$v0,0xc4($sp)
/*  f155374:	02003025 */ 	or	$a2,$s0,$zero
/*  f155378:	0fc55cbe */ 	jal	textMeasure
/*  f15537c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f155380:	8fa800cc */ 	lw	$t0,0xcc($sp)
/*  f155384:	3c013f80 */ 	lui	$at,0x3f80
/*  f155388:	44810000 */ 	mtc1	$at,$f0
/*  f15538c:	44883000 */ 	mtc1	$t0,$f6
/*  f155390:	8fa900fc */ 	lw	$t1,0xfc($sp)
/*  f155394:	4600d101 */ 	sub.s	$f4,$f26,$f0
/*  f155398:	3c013f00 */ 	lui	$at,0x3f00
/*  f15539c:	44811000 */ 	mtc1	$at,$f2
/*  f1553a0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1553a4:	44899000 */ 	mtc1	$t1,$f18
/*  f1553a8:	8faa00c4 */ 	lw	$t2,0xc4($sp)
/*  f1553ac:	c7b800e8 */ 	lwc1	$f24,0xe8($sp)
/*  f1553b0:	8fab0100 */ 	lw	$t3,0x100($sp)
/*  f1553b4:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f1553b8:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f1553bc:	448a9000 */ 	mtc1	$t2,$f18
/*  f1553c0:	c7a800dc */ 	lwc1	$f8,0xdc($sp)
/*  f1553c4:	02201025 */ 	or	$v0,$s1,$zero
/*  f1553c8:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f1553cc:	3c16e700 */ 	lui	$s6,0xe700
/*  f1553d0:	02201825 */ 	or	$v1,$s1,$zero
/*  f1553d4:	46025402 */ 	mul.s	$f16,$f10,$f2
/*  f1553d8:	4600c281 */ 	sub.s	$f10,$f24,$f0
/*  f1553dc:	3c0cba00 */ 	lui	$t4,0xba00
/*  f1553e0:	358c0e02 */ 	ori	$t4,$t4,0xe02
/*  f1553e4:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f1553e8:	340dc000 */ 	dli	$t5,0xc000
/*  f1553ec:	0220a025 */ 	or	$s4,$s1,$zero
/*  f1553f0:	46068102 */ 	mul.s	$f4,$f16,$f6
/*  f1553f4:	3c0efd10 */ 	lui	$t6,0xfd10
/*  f1553f8:	3c048008 */ 	lui	$a0,%hi(var8007fb3c)
/*  f1553fc:	2484fb3c */ 	addiu	$a0,$a0,%lo(var8007fb3c)
/*  f155400:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f155404:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f155408:	46044501 */ 	sub.s	$f20,$f8,$f4
/*  f15540c:	46105182 */ 	mul.s	$f6,$f10,$f16
/*  f155410:	448b2000 */ 	mtc1	$t3,$f4
/*  f155414:	c7b000e0 */ 	lwc1	$f16,0xe0($sp)
/*  f155418:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f15541c:	ac560000 */ 	sw	$s6,0x0($v0)
/*  f155420:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f155424:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f155428:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f15542c:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f155430:	ae8e0000 */ 	sw	$t6,0x0($s4)
/*  f155434:	46124282 */ 	mul.s	$f10,$f8,$f18
/*  f155438:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f15543c:	460a8581 */ 	sub.s	$f22,$f16,$f10
/*  f155440:	02201825 */ 	or	$v1,$s1,$zero
/*  f155444:	ae820004 */ 	sw	$v0,0x4($s4)
/*  f155448:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f15544c:	3c0fe600 */ 	lui	$t7,0xe600
/*  f155450:	02202025 */ 	or	$a0,$s1,$zero
/*  f155454:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f155458:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f15545c:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f155460:	3c190603 */ 	lui	$t9,0x603
/*  f155464:	3739c000 */ 	ori	$t9,$t9,0xc000
/*  f155468:	3c18f000 */ 	lui	$t8,0xf000
/*  f15546c:	02202825 */ 	or	$a1,$s1,$zero
/*  f155470:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f155474:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f155478:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f15547c:	3c08f540 */ 	lui	$t0,0xf540
/*  f155480:	35080200 */ 	ori	$t0,$t0,0x200
/*  f155484:	02203025 */ 	or	$a2,$s1,$zero
/*  f155488:	aca80000 */ 	sw	$t0,0x0($a1)
/*  f15548c:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f155490:	3c0a0007 */ 	lui	$t2,0x7
/*  f155494:	354ac07c */ 	ori	$t2,$t2,0xc07c
/*  f155498:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f15549c:	3c09f200 */ 	lui	$t1,0xf200
/*  f1554a0:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f1554a4:	acca0004 */ 	sw	$t2,0x4($a2)
/*  f1554a8:	02203825 */ 	or	$a3,$s1,$zero
/*  f1554ac:	3c0bfa00 */ 	lui	$t3,0xfa00
/*  f1554b0:	aceb0000 */ 	sw	$t3,0x0($a3)
/*  f1554b4:	8fac00f8 */ 	lw	$t4,0xf8($sp)
/*  f1554b8:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f1554bc:	02201025 */ 	or	$v0,$s1,$zero
/*  f1554c0:	acec0004 */ 	sw	$t4,0x4($a3)
/*  f1554c4:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f1554c8:	ac560000 */ 	sw	$s6,0x0($v0)
/*  f1554cc:	1200005e */ 	beqz	$s0,.L0f155648
/*  f1554d0:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f1554d4:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f1554d8:	3c178008 */ 	lui	$s7,%hi(var8007fad0)
/*  f1554dc:	26f7fad0 */ 	addiu	$s7,$s7,%lo(var8007fad0)
/*  f1554e0:	10400059 */ 	beqz	$v0,.L0f155648
/*  f1554e4:	241e0005 */ 	addiu	$s8,$zero,0x5
/*  f1554e8:	24160020 */ 	addiu	$s6,$zero,0x20
/*  f1554ec:	2414000c */ 	addiu	$s4,$zero,0xc
.L0f1554f0:
/*  f1554f0:	16c2000a */ 	bne	$s6,$v0,.L0f15551c
/*  f1554f4:	2401000a */ 	addiu	$at,$zero,0xa
/*  f1554f8:	8eed0000 */ 	lw	$t5,0x0($s7)
/*  f1554fc:	8fa300c0 */ 	lw	$v1,0xc0($sp)
/*  f155500:	24130048 */ 	addiu	$s3,$zero,0x48
/*  f155504:	01be0019 */ 	multu	$t5,$s8
/*  f155508:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15550c:	00007012 */ 	mflo	$t6
/*  f155510:	01c31821 */ 	addu	$v1,$t6,$v1
/*  f155514:	10000049 */ 	b	.L0f15563c
/*  f155518:	afa300c0 */ 	sw	$v1,0xc0($sp)
.L0f15551c:
/*  f15551c:	54410012 */ 	bnel	$v0,$at,.L0f155568
/*  f155520:	28410080 */ 	slti	$at,$v0,0x80
/*  f155524:	3c028008 */ 	lui	$v0,%hi(var8007fad4)
/*  f155528:	8c42fad4 */ 	lw	$v0,%lo(var8007fad4)($v0)
/*  f15552c:	8fa300c0 */ 	lw	$v1,0xc0($sp)
/*  f155530:	24130048 */ 	addiu	$s3,$zero,0x48
/*  f155534:	04400006 */ 	bltz	$v0,.L0f155550
/*  f155538:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15553c:	54600005 */ 	bnezl	$v1,.L0f155554
/*  f155540:	8faf00c4 */ 	lw	$t7,0xc4($sp)
/*  f155544:	02429021 */ 	addu	$s2,$s2,$v0
/*  f155548:	10000004 */ 	b	.L0f15555c
/*  f15554c:	00001825 */ 	or	$v1,$zero,$zero
.L0f155550:
/*  f155550:	8faf00c4 */ 	lw	$t7,0xc4($sp)
.L0f155554:
/*  f155554:	00001825 */ 	or	$v1,$zero,$zero
/*  f155558:	024f9021 */ 	addu	$s2,$s2,$t7
.L0f15555c:
/*  f15555c:	10000037 */ 	b	.L0f15563c
/*  f155560:	afa300c0 */ 	sw	$v1,0xc0($sp)
/*  f155564:	28410080 */ 	slti	$at,$v0,0x80
.L0f155568:
/*  f155568:	10200016 */ 	beqz	$at,.L0f1555c4
/*  f15556c:	304b007f */ 	andi	$t3,$v0,0x7f
/*  f155570:	00540019 */ 	multu	$v0,$s4
/*  f155574:	8fa800f4 */ 	lw	$t0,0xf4($sp)
/*  f155578:	02202025 */ 	or	$a0,$s1,$zero
/*  f15557c:	27a500c0 */ 	addiu	$a1,$sp,0xc0
/*  f155580:	e7ba0014 */ 	swc1	$f26,0x14($sp)
/*  f155584:	e7b80018 */ 	swc1	$f24,0x18($sp)
/*  f155588:	e7b4001c */ 	swc1	$f20,0x1c($sp)
/*  f15558c:	e7b60020 */ 	swc1	$f22,0x20($sp)
/*  f155590:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f155594:	0000c012 */ 	mflo	$t8
/*  f155598:	03153021 */ 	addu	$a2,$t8,$s5
/*  f15559c:	24c6fe74 */ 	addiu	$a2,$a2,-396
/*  f1555a0:	02740019 */ 	multu	$s3,$s4
/*  f1555a4:	0000c812 */ 	mflo	$t9
/*  f1555a8:	03353821 */ 	addu	$a3,$t9,$s5
/*  f1555ac:	0fc553ce */ 	jal	func0f154f38
/*  f1555b0:	24e7fe74 */ 	addiu	$a3,$a3,-396
/*  f1555b4:	00408825 */ 	or	$s1,$v0,$zero
/*  f1555b8:	92130000 */ 	lbu	$s3,0x0($s0)
/*  f1555bc:	1000001f */ 	b	.L0f15563c
/*  f1555c0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1555c4:
/*  f1555c4:	3c0f8008 */ 	lui	$t7,%hi(var8007fbcc)
/*  f1555c8:	92090001 */ 	lbu	$t1,0x1($s0)
/*  f1555cc:	25effbcc */ 	addiu	$t7,$t7,%lo(var8007fbcc)
/*  f1555d0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1555d4:	000b61c0 */ 	sll	$t4,$t3,0x7
/*  f1555d8:	27ae0080 */ 	addiu	$t6,$sp,0x80
/*  f1555dc:	312a007f */ 	andi	$t2,$t1,0x7f
/*  f1555e0:	014c1825 */ 	or	$v1,$t2,$t4
/*  f1555e4:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1555e8:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1555ec:	8df90004 */ 	lw	$t9,0x4($t7)
/*  f1555f0:	3064ffff */ 	andi	$a0,$v1,0xffff
/*  f1555f4:	30882000 */ 	andi	$t0,$a0,0x2000
/*  f1555f8:	adc10008 */ 	sw	$at,0x8($t6)
/*  f1555fc:	11000005 */ 	beqz	$t0,.L0f155614
/*  f155600:	add90004 */ 	sw	$t9,0x4($t6)
/*  f155604:	2409000f */ 	addiu	$t1,$zero,0xf
/*  f155608:	240b0010 */ 	addiu	$t3,$zero,0x10
/*  f15560c:	a3a90083 */ 	sb	$t1,0x83($sp)
/*  f155610:	a3ab0082 */ 	sb	$t3,0x82($sp)
.L0f155614:
/*  f155614:	308a1fff */ 	andi	$t2,$a0,0x1fff
/*  f155618:	294103c8 */ 	slti	$at,$t2,0x3c8
/*  f15561c:	54200003 */ 	bnezl	$at,.L0f15562c
/*  f155620:	248c0080 */ 	addiu	$t4,$a0,0x80
/*  f155624:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f155628:	248c0080 */ 	addiu	$t4,$a0,0x80
.L0f15562c:
/*  f15562c:	0fc5b8ff */ 	jal	func0f16e3fc
/*  f155630:	a3ac0080 */ 	sb	$t4,0x80($sp)
/*  f155634:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f155638:	26100002 */ 	addiu	$s0,$s0,0x2
.L0f15563c:
/*  f15563c:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f155640:	1440ffab */ 	bnez	$v0,.L0f1554f0
/*  f155644:	00000000 */ 	nop
.L0f155648:
/*  f155648:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f15564c:	02201025 */ 	or	$v0,$s1,$zero
/*  f155650:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f155654:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f155658:	d7b60038 */ 	ldc1	$f22,0x38($sp)
/*  f15565c:	d7b80040 */ 	ldc1	$f24,0x40($sp)
/*  f155660:	d7ba0048 */ 	ldc1	$f26,0x48($sp)
/*  f155664:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f155668:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f15566c:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f155670:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f155674:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f155678:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f15567c:	8fb7006c */ 	lw	$s7,0x6c($sp)
/*  f155680:	8fbe0070 */ 	lw	$s8,0x70($sp)
/*  f155684:	03e00008 */ 	jr	$ra
/*  f155688:	27bd00d8 */ 	addiu	$sp,$sp,0xd8
);
#endif

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f15568c
/*  f156780:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f156784:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f156788:	3c0c8008 */ 	lui	$t4,0x8008
/*  f15678c:	3c198008 */ 	lui	$t9,0x8008
/*  f156790:	8f390028 */ 	lw	$t9,0x28($t9)
/*  f156794:	258c0030 */ 	addiu	$t4,$t4,0x30
/*  f156798:	8d8e0000 */ 	lw	$t6,0x0($t4)
/*  f15679c:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f1567a0:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f1567a4:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f1567a8:	25f8fffe */ 	addiu	$t8,$t7,-2
/*  f1567ac:	00808025 */ 	move	$s0,$a0
/*  f1567b0:	00e08825 */ 	move	$s1,$a3
/*  f1567b4:	00a09025 */ 	move	$s2,$a1
/*  f1567b8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f1567bc:	afa600a0 */ 	sw	$a2,0xa0($sp)
/*  f1567c0:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f1567c4:	13200003 */ 	beqz	$t9,.PF0f1567d4
/*  f1567c8:	afae008c */ 	sw	$t6,0x8c($sp)
/*  f1567cc:	240d0001 */ 	li	$t5,0x1
/*  f1567d0:	afad008c */ 	sw	$t5,0x8c($sp)
.PF0f1567d4:
/*  f1567d4:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f1567d8:	8fad00a8 */ 	lw	$t5,0xa8($sp)
/*  f1567dc:	8fb800c0 */ 	lw	$t8,0xc0($sp)
/*  f1567e0:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f1567e4:	8dae0004 */ 	lw	$t6,0x4($t5)
/*  f1567e8:	8fb900ac */ 	lw	$t9,0xac($sp)
/*  f1567ec:	01f85021 */ 	addu	$t2,$t7,$t8
/*  f1567f0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1567f4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1567f8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1567fc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f156800:	8e2e0004 */ 	lw	$t6,0x4($s1)
/*  f156804:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f156808:	03386821 */ 	addu	$t5,$t9,$t8
/*  f15680c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f156810:	01afc821 */ 	addu	$t9,$t5,$t7
/*  f156814:	3c0e8008 */ 	lui	$t6,0x8008
/*  f156818:	8dce0024 */ 	lw	$t6,0x24($t6)
/*  f15681c:	8f380000 */ 	lw	$t8,0x0($t9)
/*  f156820:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f156824:	030e1021 */ 	addu	$v0,$t8,$t6
/*  f156828:	244dffff */ 	addiu	$t5,$v0,-1
/*  f15682c:	01af0019 */ 	multu	$t5,$t7
/*  f156830:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f156834:	0000c812 */ 	mflo	$t9
/*  f156838:	03197023 */ 	subu	$t6,$t8,$t9
/*  f15683c:	ae4e0000 */ 	sw	$t6,0x0($s2)
/*  f156840:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*  f156844:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f156848:	3c198008 */ 	lui	$t9,0x8008
/*  f15684c:	8f390028 */ 	lw	$t9,0x28($t9)
/*  f156850:	01af0019 */ 	multu	$t5,$t7
/*  f156854:	0000c012 */ 	mflo	$t8
/*  f156858:	afb800b8 */ 	sw	$t8,0xb8($sp)
/*  f15685c:	57200016 */ 	bnezl	$t9,.PF0f1568b8
/*  f156860:	8fa200b0 */ 	lw	$v0,0xb0($sp)
/*  f156864:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f156868:	59c00222 */ 	blezl	$t6,.PF0f1570f4
/*  f15686c:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f156870:	0c002e53 */ 	jal	0xb94c
/*  f156874:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f156878:	8e4d0000 */ 	lw	$t5,0x0($s2)
/*  f15687c:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f156880:	004d082a */ 	slt	$at,$v0,$t5
/*  f156884:	5420021b */ 	bnezl	$at,.PF0f1570f4
/*  f156888:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f15688c:	0c002e57 */ 	jal	0xb95c
/*  f156890:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f156894:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f156898:	822f0001 */ 	lb	$t7,0x1($s1)
/*  f15689c:	3c0c8008 */ 	lui	$t4,0x8008
/*  f1568a0:	258c0030 */ 	addiu	$t4,$t4,0x30
/*  f1568a4:	014fc021 */ 	addu	$t8,$t2,$t7
/*  f1568a8:	0058082a */ 	slt	$at,$v0,$t8
/*  f1568ac:	54200211 */ 	bnezl	$at,.PF0f1570f4
/*  f1568b0:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f1568b4:	8fa200b0 */ 	lw	$v0,0xb0($sp)
.PF0f1568b8:
/*  f1568b8:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*  f1568bc:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f1568c0:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f1568c4:	00594021 */ 	addu	$t0,$v0,$t9
/*  f1568c8:	0107082a */ 	slt	$at,$t0,$a3
/*  f1568cc:	14200208 */ 	bnez	$at,.PF0f1570f0
/*  f1568d0:	8fad00bc */ 	lw	$t5,0xbc($sp)
/*  f1568d4:	822f0001 */ 	lb	$t7,0x1($s1)
/*  f1568d8:	01cd5821 */ 	addu	$t3,$t6,$t5
/*  f1568dc:	01ea3021 */ 	addu	$a2,$t7,$t2
/*  f1568e0:	0166082a */ 	slt	$at,$t3,$a2
/*  f1568e4:	14200202 */ 	bnez	$at,.PF0f1570f0
/*  f1568e8:	00e2082a */ 	slt	$at,$a3,$v0
/*  f1568ec:	54200201 */ 	bnezl	$at,.PF0f1570f4
/*  f1568f0:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f1568f4:	92380002 */ 	lbu	$t8,0x2($s1)
/*  f1568f8:	02001025 */ 	move	$v0,$s0
/*  f1568fc:	3c0dfd50 */ 	lui	$t5,0xfd50
/*  f156900:	00d8c821 */ 	addu	$t9,$a2,$t8
/*  f156904:	032e082a */ 	slt	$at,$t9,$t6
/*  f156908:	142001f9 */ 	bnez	$at,.PF0f1570f0
/*  f15690c:	3c18e600 */ 	lui	$t8,0xe600
/*  f156910:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f156914:	8e2f0008 */ 	lw	$t7,0x8($s1)
/*  f156918:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15691c:	02001825 */ 	move	$v1,$s0
/*  f156920:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f156924:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156928:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f15692c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f156930:	02002025 */ 	move	$a0,$s0
/*  f156934:	3c19f300 */ 	lui	$t9,0xf300
/*  f156938:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f15693c:	92250002 */ 	lbu	$a1,0x2($s1)
/*  f156940:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156944:	02001025 */ 	move	$v0,$s0
/*  f156948:	000570c0 */ 	sll	$t6,$a1,0x3
/*  f15694c:	25c50011 */ 	addiu	$a1,$t6,0x11
/*  f156950:	00056843 */ 	sra	$t5,$a1,0x1
/*  f156954:	25a5ffff */ 	addiu	$a1,$t5,-1
/*  f156958:	28a107ff */ 	slti	$at,$a1,0x7ff
/*  f15695c:	10200003 */ 	beqz	$at,.PF0f15696c
/*  f156960:	3c0de700 */ 	lui	$t5,0xe700
/*  f156964:	10000002 */ 	b	.PF0f156970
/*  f156968:	00a01825 */ 	move	$v1,$a1
.PF0f15696c:
/*  f15696c:	240307ff */ 	li	$v1,0x7ff
.PF0f156970:
/*  f156970:	306f0fff */ 	andi	$t7,$v1,0xfff
/*  f156974:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f156978:	3c010700 */ 	lui	$at,0x700
/*  f15697c:	0301c825 */ 	or	$t9,$t8,$at
/*  f156980:	372e0800 */ 	ori	$t6,$t9,0x800
/*  f156984:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f156988:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f15698c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f156990:	3c0f800a */ 	lui	$t7,0x800a
/*  f156994:	91ef4b70 */ 	lbu	$t7,0x4b70($t7)
/*  f156998:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15699c:	02002025 */ 	move	$a0,$s0
/*  f1569a0:	11e0001c */ 	beqz	$t7,.PF0f156a14
/*  f1569a4:	3c198008 */ 	lui	$t9,0x8008
/*  f1569a8:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f1569ac:	8f390020 */ 	lw	$t9,0x20($t9)
/*  f1569b0:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f1569b4:	8faf00c0 */ 	lw	$t7,0xc0($sp)
/*  f1569b8:	0319001a */ 	div	$zero,$t8,$t9
/*  f1569bc:	8dcd0000 */ 	lw	$t5,0x0($t6)
/*  f1569c0:	00002812 */ 	mflo	$a1
/*  f1569c4:	afab0038 */ 	sw	$t3,0x38($sp)
/*  f1569c8:	17200002 */ 	bnez	$t9,.PF0f1569d4
/*  f1569cc:	00000000 */ 	nop
/*  f1569d0:	0007000d */ 	break	0x7
.PF0f1569d4:
/*  f1569d4:	2401ffff */ 	li	$at,-1
/*  f1569d8:	17210004 */ 	bne	$t9,$at,.PF0f1569ec
/*  f1569dc:	3c018000 */ 	lui	$at,0x8000
/*  f1569e0:	17010002 */ 	bne	$t8,$at,.PF0f1569ec
/*  f1569e4:	00000000 */ 	nop
/*  f1569e8:	0006000d */ 	break	0x6
.PF0f1569ec:
/*  f1569ec:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f1569f0:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f1569f4:	0fc556f8 */ 	jal	0xf155be0
/*  f1569f8:	01af3021 */ 	addu	$a2,$t5,$t7
/*  f1569fc:	3c0c8008 */ 	lui	$t4,0x8008
/*  f156a00:	258c0030 */ 	addiu	$t4,$t4,0x30
/*  f156a04:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f156a08:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f156a0c:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f156a10:	00408025 */ 	move	$s0,$v0
.PF0f156a14:
/*  f156a14:	92290003 */ 	lbu	$t1,0x3($s1)
/*  f156a18:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f156a1c:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f156a20:	03090019 */ 	multu	$t8,$t1
/*  f156a24:	0000c812 */ 	mflo	$t9
/*  f156a28:	00f97021 */ 	addu	$t6,$a3,$t9
/*  f156a2c:	010e082a */ 	slt	$at,$t0,$t6
/*  f156a30:	542001b0 */ 	bnezl	$at,.PF0f1570f4
/*  f156a34:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f156a38:	82240001 */ 	lb	$a0,0x1($s1)
/*  f156a3c:	8fa300b4 */ 	lw	$v1,0xb4($sp)
/*  f156a40:	008a3021 */ 	addu	$a2,$a0,$t2
/*  f156a44:	00c3082a */ 	slt	$at,$a2,$v1
/*  f156a48:	54200158 */ 	bnezl	$at,.PF0f156fac
/*  f156a4c:	92380002 */ 	lbu	$t8,0x2($s1)
/*  f156a50:	922d0002 */ 	lbu	$t5,0x2($s1)
/*  f156a54:	3c0f8008 */ 	lui	$t7,0x8008
/*  f156a58:	00cd1021 */ 	addu	$v0,$a2,$t5
/*  f156a5c:	0162082a */ 	slt	$at,$t3,$v0
/*  f156a60:	54200106 */ 	bnezl	$at,.PF0f156e7c
/*  f156a64:	0166082a */ 	slt	$at,$t3,$a2
/*  f156a68:	8def0028 */ 	lw	$t7,0x28($t7)
/*  f156a6c:	3c068008 */ 	lui	$a2,0x8008
/*  f156a70:	24c6003c */ 	addiu	$a2,$a2,0x3c
/*  f156a74:	11e00050 */ 	beqz	$t7,.PF0f156bb8
/*  f156a78:	3c088008 */ 	lui	$t0,0x8008
/*  f156a7c:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f156a80:	00e9c021 */ 	addu	$t8,$a3,$t1
/*  f156a84:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f156a88:	032e6821 */ 	addu	$t5,$t9,$t6
/*  f156a8c:	25080040 */ 	addiu	$t0,$t0,0x40
/*  f156a90:	31af0fff */ 	andi	$t7,$t5,0xfff
/*  f156a94:	8d0d0000 */ 	lw	$t5,0x0($t0)
/*  f156a98:	0144c823 */ 	subu	$t9,$t2,$a0
/*  f156a9c:	3c01e500 */ 	lui	$at,0xe500
/*  f156aa0:	01e1c025 */ 	or	$t8,$t7,$at
/*  f156aa4:	00197080 */ 	sll	$t6,$t9,0x2
/*  f156aa8:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f156aac:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f156ab0:	00197300 */ 	sll	$t6,$t9,0xc
/*  f156ab4:	030e6825 */ 	or	$t5,$t8,$t6
/*  f156ab8:	02001025 */ 	move	$v0,$s0
/*  f156abc:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f156ac0:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f156ac4:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f156ac8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156acc:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f156ad0:	03387021 */ 	addu	$t6,$t9,$t8
/*  f156ad4:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f156ad8:	922f0002 */ 	lbu	$t7,0x2($s1)
/*  f156adc:	31cd0fff */ 	andi	$t5,$t6,0xfff
/*  f156ae0:	822e0001 */ 	lb	$t6,0x1($s1)
/*  f156ae4:	01f90019 */ 	multu	$t7,$t9
/*  f156ae8:	02001825 */ 	move	$v1,$s0
/*  f156aec:	014e7823 */ 	subu	$t7,$t2,$t6
/*  f156af0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156af4:	02002825 */ 	move	$a1,$s0
/*  f156af8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156afc:	0000c012 */ 	mflo	$t8
/*  f156b00:	01f8c823 */ 	subu	$t9,$t7,$t8
/*  f156b04:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f156b08:	00197080 */ 	sll	$t6,$t9,0x2
/*  f156b0c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f156b10:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f156b14:	00197300 */ 	sll	$t6,$t9,0xc
/*  f156b18:	01ae7825 */ 	or	$t7,$t5,$t6
/*  f156b1c:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f156b20:	3c18b400 */ 	lui	$t8,0xb400
/*  f156b24:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f156b28:	92390002 */ 	lbu	$t9,0x2($s1)
/*  f156b2c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f156b30:	8def0044 */ 	lw	$t7,0x44($t7)
/*  f156b34:	272dffff */ 	addiu	$t5,$t9,-1
/*  f156b38:	000d7140 */ 	sll	$t6,$t5,0x5
/*  f156b3c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f156b40:	3c0e8008 */ 	lui	$t6,0x8008
/*  f156b44:	8dce0048 */ 	lw	$t6,0x48($t6)
/*  f156b48:	27190020 */ 	addiu	$t9,$t8,0x20
/*  f156b4c:	332dffff */ 	andi	$t5,$t9,0xffff
/*  f156b50:	25d80020 */ 	addiu	$t8,$t6,0x20
/*  f156b54:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f156b58:	032d7025 */ 	or	$t6,$t9,$t5
/*  f156b5c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f156b60:	3c0fb300 */ 	lui	$t7,0xb300
/*  f156b64:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f156b68:	24190400 */ 	li	$t9,0x400
/*  f156b6c:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f156b70:	3c0e0001 */ 	lui	$t6,0x1
/*  f156b74:	0338001a */ 	div	$zero,$t9,$t8
/*  f156b78:	17000002 */ 	bnez	$t8,.PF0f156b84
/*  f156b7c:	00000000 */ 	nop
/*  f156b80:	0007000d */ 	break	0x7
.PF0f156b84:
/*  f156b84:	2401ffff */ 	li	$at,-1
/*  f156b88:	17010004 */ 	bne	$t8,$at,.PF0f156b9c
/*  f156b8c:	3c018000 */ 	lui	$at,0x8000
/*  f156b90:	17210002 */ 	bne	$t9,$at,.PF0f156b9c
/*  f156b94:	00000000 */ 	nop
/*  f156b98:	0006000d */ 	break	0x6
.PF0f156b9c:
/*  f156b9c:	00006812 */ 	mflo	$t5
/*  f156ba0:	01cd7823 */ 	subu	$t7,$t6,$t5
/*  f156ba4:	31f9ffff */ 	andi	$t9,$t7,0xffff
/*  f156ba8:	3c010400 */ 	lui	$at,0x400
/*  f156bac:	0321c025 */ 	or	$t8,$t9,$at
/*  f156bb0:	1000014f */ 	b	.PF0f1570f0
/*  f156bb4:	acb80004 */ 	sw	$t8,0x4($a1)
.PF0f156bb8:
/*  f156bb8:	8d8e0000 */ 	lw	$t6,0x0($t4)
/*  f156bbc:	3c068008 */ 	lui	$a2,0x8008
/*  f156bc0:	24c6003c */ 	addiu	$a2,$a2,0x3c
/*  f156bc4:	012e0019 */ 	multu	$t1,$t6
/*  f156bc8:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f156bcc:	3c088008 */ 	lui	$t0,0x8008
/*  f156bd0:	25080040 */ 	addiu	$t0,$t0,0x40
/*  f156bd4:	3c01e400 */ 	lui	$at,0xe400
/*  f156bd8:	02001825 */ 	move	$v1,$s0
/*  f156bdc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156be0:	02002025 */ 	move	$a0,$s0
/*  f156be4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156be8:	02002825 */ 	move	$a1,$s0
/*  f156bec:	00006812 */ 	mflo	$t5
/*  f156bf0:	00ed7821 */ 	addu	$t7,$a3,$t5
/*  f156bf4:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f156bf8:	03387021 */ 	addu	$t6,$t9,$t8
/*  f156bfc:	31cd0fff */ 	andi	$t5,$t6,0xfff
/*  f156c00:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f156c04:	000d7b00 */ 	sll	$t7,$t5,0xc
/*  f156c08:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f156c0c:	01e1c825 */ 	or	$t9,$t7,$at
/*  f156c10:	030e6821 */ 	addu	$t5,$t8,$t6
/*  f156c14:	31af0fff */ 	andi	$t7,$t5,0xfff
/*  f156c18:	032fc025 */ 	or	$t8,$t9,$t7
/*  f156c1c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f156c20:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f156c24:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f156c28:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156c2c:	000e6880 */ 	sll	$t5,$t6,0x2
/*  f156c30:	01b97821 */ 	addu	$t7,$t5,$t9
/*  f156c34:	822d0001 */ 	lb	$t5,0x1($s1)
/*  f156c38:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f156c3c:	00187300 */ 	sll	$t6,$t8,0xc
/*  f156c40:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f156c44:	014dc821 */ 	addu	$t9,$t2,$t5
/*  f156c48:	00197880 */ 	sll	$t7,$t9,0x2
/*  f156c4c:	01f86821 */ 	addu	$t5,$t7,$t8
/*  f156c50:	31b90fff */ 	andi	$t9,$t5,0xfff
/*  f156c54:	01d97825 */ 	or	$t7,$t6,$t9
/*  f156c58:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f156c5c:	3c18b400 */ 	lui	$t8,0xb400
/*  f156c60:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f156c64:	3c0d8008 */ 	lui	$t5,0x8008
/*  f156c68:	8dad0044 */ 	lw	$t5,0x44($t5)
/*  f156c6c:	3c188008 */ 	lui	$t8,0x8008
/*  f156c70:	8f180048 */ 	lw	$t8,0x48($t8)
/*  f156c74:	25b90020 */ 	addiu	$t9,$t5,0x20
/*  f156c78:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f156c7c:	270d0020 */ 	addiu	$t5,$t8,0x20
/*  f156c80:	31aeffff */ 	andi	$t6,$t5,0xffff
/*  f156c84:	01eec825 */ 	or	$t9,$t7,$t6
/*  f156c88:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f156c8c:	3c18b300 */ 	lui	$t8,0xb300
/*  f156c90:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f156c94:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f156c98:	240f0400 */ 	li	$t7,0x400
/*  f156c9c:	01ed001a */ 	div	$zero,$t7,$t5
/*  f156ca0:	00007012 */ 	mflo	$t6
/*  f156ca4:	31d9ffff */ 	andi	$t9,$t6,0xffff
/*  f156ca8:	0019c400 */ 	sll	$t8,$t9,0x10
/*  f156cac:	15a00002 */ 	bnez	$t5,.PF0f156cb8
/*  f156cb0:	00000000 */ 	nop
/*  f156cb4:	0007000d */ 	break	0x7
.PF0f156cb8:
/*  f156cb8:	2401ffff */ 	li	$at,-1
/*  f156cbc:	15a10004 */ 	bne	$t5,$at,.PF0f156cd0
/*  f156cc0:	3c018000 */ 	lui	$at,0x8000
/*  f156cc4:	15e10002 */ 	bne	$t7,$at,.PF0f156cd0
/*  f156cc8:	00000000 */ 	nop
/*  f156ccc:	0006000d */ 	break	0x6
.PF0f156cd0:
/*  f156cd0:	370f0400 */ 	ori	$t7,$t8,0x400
/*  f156cd4:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f156cd8:	3c0d8008 */ 	lui	$t5,0x8008
/*  f156cdc:	8dad00fc */ 	lw	$t5,0xfc($t5)
/*  f156ce0:	8fb800c0 */ 	lw	$t8,0xc0($sp)
/*  f156ce4:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f156ce8:	51a00102 */ 	beqzl	$t5,.PF0f1570f4
/*  f156cec:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f156cf0:	8dd90000 */ 	lw	$t9,0x0($t6)
/*  f156cf4:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f156cf8:	0fc55220 */ 	jal	0xf154880
/*  f156cfc:	03382021 */ 	addu	$a0,$t9,$t8
/*  f156d00:	3c0d8008 */ 	lui	$t5,0x8008
/*  f156d04:	8dad0020 */ 	lw	$t5,0x20($t5)
/*  f156d08:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f156d0c:	3c058008 */ 	lui	$a1,0x8008
/*  f156d10:	8ca50100 */ 	lw	$a1,0x100($a1)
/*  f156d14:	01ed001a */ 	div	$zero,$t7,$t5
/*  f156d18:	00001812 */ 	mflo	$v1
/*  f156d1c:	3c0c8008 */ 	lui	$t4,0x8008
/*  f156d20:	258c0030 */ 	addiu	$t4,$t4,0x30
/*  f156d24:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f156d28:	15a00002 */ 	bnez	$t5,.PF0f156d34
/*  f156d2c:	00000000 */ 	nop
/*  f156d30:	0007000d */ 	break	0x7
.PF0f156d34:
/*  f156d34:	2401ffff */ 	li	$at,-1
/*  f156d38:	15a10004 */ 	bne	$t5,$at,.PF0f156d4c
/*  f156d3c:	3c018000 */ 	lui	$at,0x8000
/*  f156d40:	15e10002 */ 	bne	$t7,$at,.PF0f156d4c
/*  f156d44:	00000000 */ 	nop
/*  f156d48:	0006000d */ 	break	0x6
.PF0f156d4c:
/*  f156d4c:	00a3082a */ 	slt	$at,$a1,$v1
/*  f156d50:	5420002e */ 	bnezl	$at,.PF0f156e0c
/*  f156d54:	24a2fffd */ 	addiu	$v0,$a1,-3
/*  f156d58:	922e0003 */ 	lbu	$t6,0x3($s1)
/*  f156d5c:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f156d60:	3c04800a */ 	lui	$a0,0x800a
/*  f156d64:	00a03825 */ 	move	$a3,$a1
/*  f156d68:	01d90019 */ 	multu	$t6,$t9
/*  f156d6c:	3c02800a */ 	lui	$v0,0x800a
/*  f156d70:	0000c012 */ 	mflo	$t8
/*  f156d74:	00787821 */ 	addu	$t7,$v1,$t8
/*  f156d78:	01e5082a */ 	slt	$at,$t7,$a1
/*  f156d7c:	54200023 */ 	bnezl	$at,.PF0f156e0c
/*  f156d80:	24a2fffd */ 	addiu	$v0,$a1,-3
/*  f156d84:	822d0001 */ 	lb	$t5,0x1($s1)
/*  f156d88:	922e0002 */ 	lbu	$t6,0x2($s1)
/*  f156d8c:	8c424b74 */ 	lw	$v0,0x4b74($v0)
/*  f156d90:	01aa3021 */ 	addu	$a2,$t5,$t2
/*  f156d94:	00cec821 */ 	addu	$t9,$a2,$t6
/*  f156d98:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f156d9c:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f156da0:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f156da4:	8c844bd4 */ 	lw	$a0,0x4bd4($a0)
/*  f156da8:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f156dac:	0fc354ab */ 	jal	0xf0d52ac
/*  f156db0:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f156db4:	3c01800a */ 	lui	$at,0x800a
/*  f156db8:	ac224bd4 */ 	sw	$v0,0x4bd4($at)
/*  f156dbc:	3c0f8008 */ 	lui	$t7,0x8008
/*  f156dc0:	8def0020 */ 	lw	$t7,0x20($t7)
/*  f156dc4:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f156dc8:	3c0c8008 */ 	lui	$t4,0x8008
/*  f156dcc:	3c058008 */ 	lui	$a1,0x8008
/*  f156dd0:	030f001a */ 	div	$zero,$t8,$t7
/*  f156dd4:	00001812 */ 	mflo	$v1
/*  f156dd8:	8ca50100 */ 	lw	$a1,0x100($a1)
/*  f156ddc:	258c0030 */ 	addiu	$t4,$t4,0x30
/*  f156de0:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f156de4:	15e00002 */ 	bnez	$t7,.PF0f156df0
/*  f156de8:	00000000 */ 	nop
/*  f156dec:	0007000d */ 	break	0x7
.PF0f156df0:
/*  f156df0:	2401ffff */ 	li	$at,-1
/*  f156df4:	15e10004 */ 	bne	$t7,$at,.PF0f156e08
/*  f156df8:	3c018000 */ 	lui	$at,0x8000
/*  f156dfc:	17010002 */ 	bne	$t8,$at,.PF0f156e08
/*  f156e00:	00000000 */ 	nop
/*  f156e04:	0006000d */ 	break	0x6
.PF0f156e08:
/*  f156e08:	24a2fffd */ 	addiu	$v0,$a1,-3
.PF0f156e0c:
/*  f156e0c:	0043082a */ 	slt	$at,$v0,$v1
/*  f156e10:	542000b8 */ 	bnezl	$at,.PF0f1570f4
/*  f156e14:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f156e18:	922d0003 */ 	lbu	$t5,0x3($s1)
/*  f156e1c:	8d8e0000 */ 	lw	$t6,0x0($t4)
/*  f156e20:	3c04800a */ 	lui	$a0,0x800a
/*  f156e24:	00a03825 */ 	move	$a3,$a1
/*  f156e28:	01ae0019 */ 	multu	$t5,$t6
/*  f156e2c:	0000c812 */ 	mflo	$t9
/*  f156e30:	0079c021 */ 	addu	$t8,$v1,$t9
/*  f156e34:	0302082a */ 	slt	$at,$t8,$v0
/*  f156e38:	142000ad */ 	bnez	$at,.PF0f1570f0
/*  f156e3c:	3c02800a */ 	lui	$v0,0x800a
/*  f156e40:	822f0001 */ 	lb	$t7,0x1($s1)
/*  f156e44:	922d0002 */ 	lbu	$t5,0x2($s1)
/*  f156e48:	8c424b74 */ 	lw	$v0,0x4b74($v0)
/*  f156e4c:	01ea3021 */ 	addu	$a2,$t7,$t2
/*  f156e50:	00cd7021 */ 	addu	$t6,$a2,$t5
/*  f156e54:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f156e58:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f156e5c:	8c844bd4 */ 	lw	$a0,0x4bd4($a0)
/*  f156e60:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f156e64:	0fc354ab */ 	jal	0xf0d52ac
/*  f156e68:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f156e6c:	3c01800a */ 	lui	$at,0x800a
/*  f156e70:	1000009f */ 	b	.PF0f1570f0
/*  f156e74:	ac224bd4 */ 	sw	$v0,0x4bd4($at)
/*  f156e78:	0166082a */ 	slt	$at,$t3,$a2
.PF0f156e7c:
/*  f156e7c:	5420009d */ 	bnezl	$at,.PF0f1570f4
/*  f156e80:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f156e84:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f156e88:	3c068008 */ 	lui	$a2,0x8008
/*  f156e8c:	24c6003c */ 	addiu	$a2,$a2,0x3c
/*  f156e90:	01390019 */ 	multu	$t1,$t9
/*  f156e94:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f156e98:	3c088008 */ 	lui	$t0,0x8008
/*  f156e9c:	25080040 */ 	addiu	$t0,$t0,0x40
/*  f156ea0:	3c01e400 */ 	lui	$at,0xe400
/*  f156ea4:	02001025 */ 	move	$v0,$s0
/*  f156ea8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156eac:	02001825 */ 	move	$v1,$s0
/*  f156eb0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156eb4:	02002025 */ 	move	$a0,$s0
/*  f156eb8:	0000c012 */ 	mflo	$t8
/*  f156ebc:	00f87821 */ 	addu	$t7,$a3,$t8
/*  f156ec0:	000f6880 */ 	sll	$t5,$t7,0x2
/*  f156ec4:	01aec821 */ 	addu	$t9,$t5,$t6
/*  f156ec8:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f156ecc:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f156ed0:	00187b00 */ 	sll	$t7,$t8,0xc
/*  f156ed4:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f156ed8:	01e16825 */ 	or	$t5,$t7,$at
/*  f156edc:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f156ee0:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f156ee4:	01af7025 */ 	or	$t6,$t5,$t7
/*  f156ee8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f156eec:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f156ef0:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f156ef4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156ef8:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f156efc:	030d7821 */ 	addu	$t7,$t8,$t5
/*  f156f00:	82380001 */ 	lb	$t8,0x1($s1)
/*  f156f04:	31ee0fff */ 	andi	$t6,$t7,0xfff
/*  f156f08:	000ecb00 */ 	sll	$t9,$t6,0xc
/*  f156f0c:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f156f10:	01586821 */ 	addu	$t5,$t2,$t8
/*  f156f14:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f156f18:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f156f1c:	330d0fff */ 	andi	$t5,$t8,0xfff
/*  f156f20:	032d7825 */ 	or	$t7,$t9,$t5
/*  f156f24:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f156f28:	3c0eb400 */ 	lui	$t6,0xb400
/*  f156f2c:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f156f30:	3c188008 */ 	lui	$t8,0x8008
/*  f156f34:	8f180044 */ 	lw	$t8,0x44($t8)
/*  f156f38:	3c0e8008 */ 	lui	$t6,0x8008
/*  f156f3c:	8dce0048 */ 	lw	$t6,0x48($t6)
/*  f156f40:	270d0020 */ 	addiu	$t5,$t8,0x20
/*  f156f44:	000d7c00 */ 	sll	$t7,$t5,0x10
/*  f156f48:	25d80020 */ 	addiu	$t8,$t6,0x20
/*  f156f4c:	3319ffff */ 	andi	$t9,$t8,0xffff
/*  f156f50:	01f96825 */ 	or	$t5,$t7,$t9
/*  f156f54:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f156f58:	240f0400 */ 	li	$t7,0x400
/*  f156f5c:	3c0eb300 */ 	lui	$t6,0xb300
/*  f156f60:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f156f64:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f156f68:	01f8001a */ 	div	$zero,$t7,$t8
/*  f156f6c:	0000c812 */ 	mflo	$t9
/*  f156f70:	332dffff */ 	andi	$t5,$t9,0xffff
/*  f156f74:	000d7400 */ 	sll	$t6,$t5,0x10
/*  f156f78:	17000002 */ 	bnez	$t8,.PF0f156f84
/*  f156f7c:	00000000 */ 	nop
/*  f156f80:	0007000d */ 	break	0x7
.PF0f156f84:
/*  f156f84:	2401ffff */ 	li	$at,-1
/*  f156f88:	17010004 */ 	bne	$t8,$at,.PF0f156f9c
/*  f156f8c:	3c018000 */ 	lui	$at,0x8000
/*  f156f90:	15e10002 */ 	bne	$t7,$at,.PF0f156f9c
/*  f156f94:	00000000 */ 	nop
/*  f156f98:	0006000d */ 	break	0x6
.PF0f156f9c:
/*  f156f9c:	35cf0400 */ 	ori	$t7,$t6,0x400
/*  f156fa0:	10000053 */ 	b	.PF0f1570f0
/*  f156fa4:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f156fa8:	92380002 */ 	lbu	$t8,0x2($s1)
.PF0f156fac:
/*  f156fac:	00d81021 */ 	addu	$v0,$a2,$t8
/*  f156fb0:	0043082a */ 	slt	$at,$v0,$v1
/*  f156fb4:	5420004f */ 	bnezl	$at,.PF0f1570f4
/*  f156fb8:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f156fbc:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f156fc0:	3c068008 */ 	lui	$a2,0x8008
/*  f156fc4:	24c6003c */ 	addiu	$a2,$a2,0x3c
/*  f156fc8:	01390019 */ 	multu	$t1,$t9
/*  f156fcc:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f156fd0:	3c088008 */ 	lui	$t0,0x8008
/*  f156fd4:	25080040 */ 	addiu	$t0,$t0,0x40
/*  f156fd8:	3c01e400 */ 	lui	$at,0xe400
/*  f156fdc:	02001825 */ 	move	$v1,$s0
/*  f156fe0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156fe4:	02002025 */ 	move	$a0,$s0
/*  f156fe8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156fec:	02002825 */ 	move	$a1,$s0
/*  f156ff0:	00006812 */ 	mflo	$t5
/*  f156ff4:	00ed7021 */ 	addu	$t6,$a3,$t5
/*  f156ff8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f156ffc:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f157000:	332d0fff */ 	andi	$t5,$t9,0xfff
/*  f157004:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f157008:	000d7300 */ 	sll	$t6,$t5,0xc
/*  f15700c:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f157010:	01c17825 */ 	or	$t7,$t6,$at
/*  f157014:	03196821 */ 	addu	$t5,$t8,$t9
/*  f157018:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f15701c:	01eec025 */ 	or	$t8,$t7,$t6
/*  f157020:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f157024:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f157028:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f15702c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f157030:	00196880 */ 	sll	$t5,$t9,0x2
/*  f157034:	01af7021 */ 	addu	$t6,$t5,$t7
/*  f157038:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f15703c:	31d80fff */ 	andi	$t8,$t6,0xfff
/*  f157040:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f157044:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f157048:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f15704c:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f157050:	330d0fff */ 	andi	$t5,$t8,0xfff
/*  f157054:	032d7825 */ 	or	$t7,$t9,$t5
/*  f157058:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f15705c:	3c0eb400 */ 	lui	$t6,0xb400
/*  f157060:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f157064:	8fb800b4 */ 	lw	$t8,0xb4($sp)
/*  f157068:	822d0001 */ 	lb	$t5,0x1($s1)
/*  f15706c:	030ac823 */ 	subu	$t9,$t8,$t2
/*  f157070:	3c188008 */ 	lui	$t8,0x8008
/*  f157074:	8f180048 */ 	lw	$t8,0x48($t8)
/*  f157078:	032d7823 */ 	subu	$t7,$t9,$t5
/*  f15707c:	000f7140 */ 	sll	$t6,$t7,0x5
/*  f157080:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f157084:	3c0e8008 */ 	lui	$t6,0x8008
/*  f157088:	8dce0044 */ 	lw	$t6,0x44($t6)
/*  f15708c:	272d0020 */ 	addiu	$t5,$t9,0x20
/*  f157090:	31afffff */ 	andi	$t7,$t5,0xffff
/*  f157094:	25d90020 */ 	addiu	$t9,$t6,0x20
/*  f157098:	00196c00 */ 	sll	$t5,$t9,0x10
/*  f15709c:	01af7025 */ 	or	$t6,$t5,$t7
/*  f1570a0:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f1570a4:	3c18b300 */ 	lui	$t8,0xb300
/*  f1570a8:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1570ac:	240d0400 */ 	li	$t5,0x400
/*  f1570b0:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f1570b4:	01b9001a */ 	div	$zero,$t5,$t9
/*  f1570b8:	00007812 */ 	mflo	$t7
/*  f1570bc:	31eeffff */ 	andi	$t6,$t7,0xffff
/*  f1570c0:	000ec400 */ 	sll	$t8,$t6,0x10
/*  f1570c4:	17200002 */ 	bnez	$t9,.PF0f1570d0
/*  f1570c8:	00000000 */ 	nop
/*  f1570cc:	0007000d */ 	break	0x7
.PF0f1570d0:
/*  f1570d0:	2401ffff */ 	li	$at,-1
/*  f1570d4:	17210004 */ 	bne	$t9,$at,.PF0f1570e8
/*  f1570d8:	3c018000 */ 	lui	$at,0x8000
/*  f1570dc:	15a10002 */ 	bne	$t5,$at,.PF0f1570e8
/*  f1570e0:	00000000 */ 	nop
/*  f1570e4:	0006000d */ 	break	0x6
.PF0f1570e8:
/*  f1570e8:	370d0400 */ 	ori	$t5,$t8,0x400
/*  f1570ec:	acad0004 */ 	sw	$t5,0x4($a1)
.PF0f1570f0:
/*  f1570f0:	92390003 */ 	lbu	$t9,0x3($s1)
.PF0f1570f4:
/*  f1570f4:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f1570f8:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f1570fc:	02001025 */ 	move	$v0,$s0
/*  f157100:	032f0019 */ 	multu	$t9,$t7
/*  f157104:	00007012 */ 	mflo	$t6
/*  f157108:	030e6821 */ 	addu	$t5,$t8,$t6
/*  f15710c:	ae4d0000 */ 	sw	$t5,0x0($s2)
/*  f157110:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f157114:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f157118:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f15711c:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f157120:	03e00008 */ 	jr	$ra
/*  f157124:	27bd0098 */ 	addiu	$sp,$sp,0x98
);
#else
GLOBAL_ASM(
glabel func0f15568c
/*  f15568c:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f155690:	3c0d8008 */ 	lui	$t5,%hi(var8007fad0)
/*  f155694:	3c0f8008 */ 	lui	$t7,%hi(var8007fac8)
/*  f155698:	8deffac8 */ 	lw	$t7,%lo(var8007fac8)($t7)
/*  f15569c:	25adfad0 */ 	addiu	$t5,$t5,%lo(var8007fad0)
/*  f1556a0:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f1556a4:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f1556a8:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f1556ac:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f1556b0:	00808025 */ 	or	$s0,$a0,$zero
/*  f1556b4:	00e08825 */ 	or	$s1,$a3,$zero
/*  f1556b8:	00a09025 */ 	or	$s2,$a1,$zero
/*  f1556bc:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f1556c0:	afa600a0 */ 	sw	$a2,0xa0($sp)
/*  f1556c4:	11e00003 */ 	beqz	$t7,.L0f1556d4
/*  f1556c8:	afae008c */ 	sw	$t6,0x8c($sp)
/*  f1556cc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1556d0:	afb8008c */ 	sw	$t8,0x8c($sp)
.L0f1556d4:
/*  f1556d4:	8fb900a0 */ 	lw	$t9,0xa0($sp)
/*  f1556d8:	8faf00c0 */ 	lw	$t7,0xc0($sp)
/*  f1556dc:	8fb800ac */ 	lw	$t8,0xac($sp)
/*  f1556e0:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f1556e4:	8fb900a8 */ 	lw	$t9,0xa8($sp)
/*  f1556e8:	01cf5021 */ 	addu	$t2,$t6,$t7
/*  f1556ec:	8f2e0004 */ 	lw	$t6,0x4($t9)
/*  f1556f0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1556f4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1556f8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1556fc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f155700:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f155704:	8e2f0004 */ 	lw	$t7,0x4($s1)
/*  f155708:	03197021 */ 	addu	$t6,$t8,$t9
/*  f15570c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f155710:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f155714:	3c0e8008 */ 	lui	$t6,%hi(var8007fac4)
/*  f155718:	8dcefac4 */ 	lw	$t6,%lo(var8007fac4)($t6)
/*  f15571c:	8f2f0000 */ 	lw	$t7,0x0($t9)
/*  f155720:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f155724:	01ee1021 */ 	addu	$v0,$t7,$t6
/*  f155728:	2458ffff */ 	addiu	$t8,$v0,-1
/*  f15572c:	03190019 */ 	multu	$t8,$t9
/*  f155730:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f155734:	00007812 */ 	mflo	$t7
/*  f155738:	01cfc023 */ 	subu	$t8,$t6,$t7
/*  f15573c:	ae580000 */ 	sw	$t8,0x0($s2)
/*  f155740:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*  f155744:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f155748:	3c188008 */ 	lui	$t8,%hi(var8007fac8)
/*  f15574c:	8f18fac8 */ 	lw	$t8,%lo(var8007fac8)($t8)
/*  f155750:	032e0019 */ 	multu	$t9,$t6
/*  f155754:	00007812 */ 	mflo	$t7
/*  f155758:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f15575c:	57000016 */ 	bnezl	$t8,.L0f1557b8
/*  f155760:	8fa200b0 */ 	lw	$v0,0xb0($sp)
/*  f155764:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f155768:	5b200221 */ 	blezl	$t9,.L0f155ff0
/*  f15576c:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f155770:	0c002f02 */ 	jal	viGetWidth
/*  f155774:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f155778:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f15577c:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f155780:	004e082a */ 	slt	$at,$v0,$t6
/*  f155784:	5420021a */ 	bnezl	$at,.L0f155ff0
/*  f155788:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f15578c:	0c002f06 */ 	jal	viGetHeight
/*  f155790:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f155794:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f155798:	822f0001 */ 	lb	$t7,0x1($s1)
/*  f15579c:	3c0d8008 */ 	lui	$t5,%hi(var8007fad0)
/*  f1557a0:	25adfad0 */ 	addiu	$t5,$t5,%lo(var8007fad0)
/*  f1557a4:	014fc021 */ 	addu	$t8,$t2,$t7
/*  f1557a8:	0058082a */ 	slt	$at,$v0,$t8
/*  f1557ac:	54200210 */ 	bnezl	$at,.L0f155ff0
/*  f1557b0:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f1557b4:	8fa200b0 */ 	lw	$v0,0xb0($sp)
.L0f1557b8:
/*  f1557b8:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*  f1557bc:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f1557c0:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f1557c4:	00594021 */ 	addu	$t0,$v0,$t9
/*  f1557c8:	0107082a */ 	slt	$at,$t0,$a3
/*  f1557cc:	14200207 */ 	bnez	$at,.L0f155fec
/*  f1557d0:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*  f1557d4:	822f0001 */ 	lb	$t7,0x1($s1)
/*  f1557d8:	016e6021 */ 	addu	$t4,$t3,$t6
/*  f1557dc:	01ea3021 */ 	addu	$a2,$t7,$t2
/*  f1557e0:	0186082a */ 	slt	$at,$t4,$a2
/*  f1557e4:	14200201 */ 	bnez	$at,.L0f155fec
/*  f1557e8:	00e2082a */ 	slt	$at,$a3,$v0
/*  f1557ec:	54200200 */ 	bnezl	$at,.L0f155ff0
/*  f1557f0:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f1557f4:	92380002 */ 	lbu	$t8,0x2($s1)
/*  f1557f8:	02001025 */ 	or	$v0,$s0,$zero
/*  f1557fc:	3c0efd50 */ 	lui	$t6,0xfd50
/*  f155800:	00d8c821 */ 	addu	$t9,$a2,$t8
/*  f155804:	032b082a */ 	slt	$at,$t9,$t3
/*  f155808:	142001f8 */ 	bnez	$at,.L0f155fec
/*  f15580c:	3c18e600 */ 	lui	$t8,0xe600
/*  f155810:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f155814:	8e2f0008 */ 	lw	$t7,0x8($s1)
/*  f155818:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15581c:	02001825 */ 	or	$v1,$s0,$zero
/*  f155820:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f155824:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155828:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f15582c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f155830:	02002025 */ 	or	$a0,$s0,$zero
/*  f155834:	3c19f300 */ 	lui	$t9,0xf300
/*  f155838:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f15583c:	92250002 */ 	lbu	$a1,0x2($s1)
/*  f155840:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155844:	240307ff */ 	addiu	$v1,$zero,0x7ff
/*  f155848:	000570c0 */ 	sll	$t6,$a1,0x3
/*  f15584c:	25c50011 */ 	addiu	$a1,$t6,0x11
/*  f155850:	00057843 */ 	sra	$t7,$a1,0x1
/*  f155854:	25e5ffff */ 	addiu	$a1,$t7,-1
/*  f155858:	28a107ff */ 	slti	$at,$a1,0x7ff
/*  f15585c:	10200003 */ 	beqz	$at,.L0f15586c
/*  f155860:	02001025 */ 	or	$v0,$s0,$zero
/*  f155864:	10000001 */ 	b	.L0f15586c
/*  f155868:	00a01825 */ 	or	$v1,$a1,$zero
.L0f15586c:
/*  f15586c:	30780fff */ 	andi	$t8,$v1,0xfff
/*  f155870:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f155874:	3c010700 */ 	lui	$at,0x700
/*  f155878:	03217025 */ 	or	$t6,$t9,$at
/*  f15587c:	35cf0800 */ 	ori	$t7,$t6,0x800
/*  f155880:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f155884:	3c18e700 */ 	lui	$t8,0xe700
/*  f155888:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f15588c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f155890:	3c19800a */ 	lui	$t9,%hi(var800a45d0)
/*  f155894:	933945d0 */ 	lbu	$t9,%lo(var800a45d0)($t9)
/*  f155898:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15589c:	3c0f8008 */ 	lui	$t7,%hi(g_ScaleX)
/*  f1558a0:	5320001f */ 	beqzl	$t9,.L0f155920
/*  f1558a4:	92290003 */ 	lbu	$t1,0x3($s1)
/*  f1558a8:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f1558ac:	8deffac0 */ 	lw	$t7,%lo(g_ScaleX)($t7)
/*  f1558b0:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*  f1558b4:	02002025 */ 	or	$a0,$s0,$zero
/*  f1558b8:	01cf001a */ 	div	$zero,$t6,$t7
/*  f1558bc:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f1558c0:	15e00002 */ 	bnez	$t7,.L0f1558cc
/*  f1558c4:	00000000 */ 	nop
/*  f1558c8:	0007000d */ 	break	0x7
.L0f1558cc:
/*  f1558cc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1558d0:	15e10004 */ 	bne	$t7,$at,.L0f1558e4
/*  f1558d4:	3c018000 */ 	lui	$at,0x8000
/*  f1558d8:	15c10002 */ 	bne	$t6,$at,.L0f1558e4
/*  f1558dc:	00000000 */ 	nop
/*  f1558e0:	0006000d */ 	break	0x6
.L0f1558e4:
/*  f1558e4:	8fae00c0 */ 	lw	$t6,0xc0($sp)
/*  f1558e8:	00002812 */ 	mflo	$a1
/*  f1558ec:	afac0038 */ 	sw	$t4,0x38($sp)
/*  f1558f0:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f1558f4:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f1558f8:	0fc553b3 */ 	jal	func0f154ecc
/*  f1558fc:	032e3021 */ 	addu	$a2,$t9,$t6
/*  f155900:	3c0d8008 */ 	lui	$t5,%hi(var8007fad0)
/*  f155904:	25adfad0 */ 	addiu	$t5,$t5,%lo(var8007fad0)
/*  f155908:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f15590c:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f155910:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f155914:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f155918:	00408025 */ 	or	$s0,$v0,$zero
/*  f15591c:	92290003 */ 	lbu	$t1,0x3($s1)
.L0f155920:
/*  f155920:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f155924:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f155928:	01e90019 */ 	multu	$t7,$t1
/*  f15592c:	0000c012 */ 	mflo	$t8
/*  f155930:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f155934:	0119082a */ 	slt	$at,$t0,$t9
/*  f155938:	542001ad */ 	bnezl	$at,.L0f155ff0
/*  f15593c:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f155940:	82240001 */ 	lb	$a0,0x1($s1)
/*  f155944:	008a3021 */ 	addu	$a2,$a0,$t2
/*  f155948:	00cb082a */ 	slt	$at,$a2,$t3
/*  f15594c:	54200158 */ 	bnezl	$at,.L0f155eb0
/*  f155950:	92390002 */ 	lbu	$t9,0x2($s1)
/*  f155954:	922e0002 */ 	lbu	$t6,0x2($s1)
/*  f155958:	3c0f8008 */ 	lui	$t7,%hi(var8007fac8)
/*  f15595c:	00ce1021 */ 	addu	$v0,$a2,$t6
/*  f155960:	0182082a */ 	slt	$at,$t4,$v0
/*  f155964:	54200106 */ 	bnezl	$at,.L0f155d80
/*  f155968:	0186082a */ 	slt	$at,$t4,$a2
/*  f15596c:	8deffac8 */ 	lw	$t7,%lo(var8007fac8)($t7)
/*  f155970:	3c068008 */ 	lui	$a2,%hi(var8007fadc)
/*  f155974:	24c6fadc */ 	addiu	$a2,$a2,%lo(var8007fadc)
/*  f155978:	11e00050 */ 	beqz	$t7,.L0f155abc
/*  f15597c:	3c088008 */ 	lui	$t0,%hi(var8007fae0)
/*  f155980:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f155984:	00e9c021 */ 	addu	$t8,$a3,$t1
/*  f155988:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f15598c:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f155990:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f155994:	3c01e500 */ 	lui	$at,0xe500
/*  f155998:	2508fae0 */ 	addiu	$t0,$t0,%lo(var8007fae0)
/*  f15599c:	0301c825 */ 	or	$t9,$t8,$at
/*  f1559a0:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f1559a4:	01447023 */ 	subu	$t6,$t2,$a0
/*  f1559a8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1559ac:	01f87021 */ 	addu	$t6,$t7,$t8
/*  f1559b0:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f1559b4:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f1559b8:	03387025 */ 	or	$t6,$t9,$t8
/*  f1559bc:	02001025 */ 	or	$v0,$s0,$zero
/*  f1559c0:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f1559c4:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f1559c8:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f1559cc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1559d0:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f1559d4:	03387021 */ 	addu	$t6,$t9,$t8
/*  f1559d8:	8db80000 */ 	lw	$t8,0x0($t5)
/*  f1559dc:	92390002 */ 	lbu	$t9,0x2($s1)
/*  f1559e0:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f1559e4:	02001825 */ 	or	$v1,$s0,$zero
/*  f1559e8:	03380019 */ 	multu	$t9,$t8
/*  f1559ec:	82390001 */ 	lb	$t9,0x1($s1)
/*  f1559f0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1559f4:	02002825 */ 	or	$a1,$s0,$zero
/*  f1559f8:	0159c023 */ 	subu	$t8,$t2,$t9
/*  f1559fc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155a00:	00007012 */ 	mflo	$t6
/*  f155a04:	030ec823 */ 	subu	$t9,$t8,$t6
/*  f155a08:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f155a0c:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f155a10:	030ec821 */ 	addu	$t9,$t8,$t6
/*  f155a14:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f155a18:	00187300 */ 	sll	$t6,$t8,0xc
/*  f155a1c:	01eec825 */ 	or	$t9,$t7,$t6
/*  f155a20:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f155a24:	3c18b400 */ 	lui	$t8,0xb400
/*  f155a28:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f155a2c:	922f0002 */ 	lbu	$t7,0x2($s1)
/*  f155a30:	3c188008 */ 	lui	$t8,%hi(var8007fae4)
/*  f155a34:	8f18fae4 */ 	lw	$t8,%lo(var8007fae4)($t8)
/*  f155a38:	25eeffff */ 	addiu	$t6,$t7,-1
/*  f155a3c:	000ec940 */ 	sll	$t9,$t6,0x5
/*  f155a40:	03387821 */ 	addu	$t7,$t9,$t8
/*  f155a44:	3c188008 */ 	lui	$t8,%hi(var8007fae8)
/*  f155a48:	8f18fae8 */ 	lw	$t8,%lo(var8007fae8)($t8)
/*  f155a4c:	25ee0020 */ 	addiu	$t6,$t7,0x20
/*  f155a50:	31d9ffff */ 	andi	$t9,$t6,0xffff
/*  f155a54:	270e0020 */ 	addiu	$t6,$t8,0x20
/*  f155a58:	000ec400 */ 	sll	$t8,$t6,0x10
/*  f155a5c:	03197825 */ 	or	$t7,$t8,$t9
/*  f155a60:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f155a64:	3c0eb300 */ 	lui	$t6,0xb300
/*  f155a68:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f155a6c:	24190400 */ 	addiu	$t9,$zero,0x400
/*  f155a70:	8db80000 */ 	lw	$t8,0x0($t5)
/*  f155a74:	3c0e0001 */ 	lui	$t6,0x1
/*  f155a78:	0338001a */ 	div	$zero,$t9,$t8
/*  f155a7c:	17000002 */ 	bnez	$t8,.L0f155a88
/*  f155a80:	00000000 */ 	nop
/*  f155a84:	0007000d */ 	break	0x7
.L0f155a88:
/*  f155a88:	2401ffff */ 	addiu	$at,$zero,-1
/*  f155a8c:	17010004 */ 	bne	$t8,$at,.L0f155aa0
/*  f155a90:	3c018000 */ 	lui	$at,0x8000
/*  f155a94:	17210002 */ 	bne	$t9,$at,.L0f155aa0
/*  f155a98:	00000000 */ 	nop
/*  f155a9c:	0006000d */ 	break	0x6
.L0f155aa0:
/*  f155aa0:	00007812 */ 	mflo	$t7
/*  f155aa4:	01cfc823 */ 	subu	$t9,$t6,$t7
/*  f155aa8:	3338ffff */ 	andi	$t8,$t9,0xffff
/*  f155aac:	3c010400 */ 	lui	$at,0x400
/*  f155ab0:	03017025 */ 	or	$t6,$t8,$at
/*  f155ab4:	1000014d */ 	b	.L0f155fec
/*  f155ab8:	acae0004 */ 	sw	$t6,0x4($a1)
.L0f155abc:
/*  f155abc:	8daf0000 */ 	lw	$t7,0x0($t5)
/*  f155ac0:	3c068008 */ 	lui	$a2,%hi(var8007fadc)
/*  f155ac4:	24c6fadc */ 	addiu	$a2,$a2,%lo(var8007fadc)
/*  f155ac8:	012f0019 */ 	multu	$t1,$t7
/*  f155acc:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f155ad0:	3c088008 */ 	lui	$t0,%hi(var8007fae0)
/*  f155ad4:	2508fae0 */ 	addiu	$t0,$t0,%lo(var8007fae0)
/*  f155ad8:	3c01e400 */ 	lui	$at,0xe400
/*  f155adc:	02001825 */ 	or	$v1,$s0,$zero
/*  f155ae0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155ae4:	02002025 */ 	or	$a0,$s0,$zero
/*  f155ae8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155aec:	02002825 */ 	or	$a1,$s0,$zero
/*  f155af0:	0000c812 */ 	mflo	$t9
/*  f155af4:	00f9c021 */ 	addu	$t8,$a3,$t9
/*  f155af8:	00187080 */ 	sll	$t6,$t8,0x2
/*  f155afc:	01cfc821 */ 	addu	$t9,$t6,$t7
/*  f155b00:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f155b04:	00187300 */ 	sll	$t6,$t8,0xc
/*  f155b08:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f155b0c:	01c17825 */ 	or	$t7,$t6,$at
/*  f155b10:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f155b14:	03387021 */ 	addu	$t6,$t9,$t8
/*  f155b18:	31d90fff */ 	andi	$t9,$t6,0xfff
/*  f155b1c:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f155b20:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f155b24:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f155b28:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f155b2c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155b30:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f155b34:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f155b38:	82390001 */ 	lb	$t9,0x1($s1)
/*  f155b3c:	330e0fff */ 	andi	$t6,$t8,0xfff
/*  f155b40:	000e7b00 */ 	sll	$t7,$t6,0xc
/*  f155b44:	0159c021 */ 	addu	$t8,$t2,$t9
/*  f155b48:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f155b4c:	00187080 */ 	sll	$t6,$t8,0x2
/*  f155b50:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f155b54:	330e0fff */ 	andi	$t6,$t8,0xfff
/*  f155b58:	01eec825 */ 	or	$t9,$t7,$t6
/*  f155b5c:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f155b60:	3c18b400 */ 	lui	$t8,0xb400
/*  f155b64:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f155b68:	3c0f8008 */ 	lui	$t7,%hi(var8007fae4)
/*  f155b6c:	8deffae4 */ 	lw	$t7,%lo(var8007fae4)($t7)
/*  f155b70:	25f90020 */ 	addiu	$t9,$t7,0x20
/*  f155b74:	3c0f8008 */ 	lui	$t7,%hi(var8007fae8)
/*  f155b78:	8deffae8 */ 	lw	$t7,%lo(var8007fae8)($t7)
/*  f155b7c:	0019c400 */ 	sll	$t8,$t9,0x10
/*  f155b80:	25ee0020 */ 	addiu	$t6,$t7,0x20
/*  f155b84:	31d9ffff */ 	andi	$t9,$t6,0xffff
/*  f155b88:	03197825 */ 	or	$t7,$t8,$t9
/*  f155b8c:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f155b90:	3c0eb300 */ 	lui	$t6,0xb300
/*  f155b94:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f155b98:	24190400 */ 	addiu	$t9,$zero,0x400
/*  f155b9c:	8db80000 */ 	lw	$t8,0x0($t5)
/*  f155ba0:	0338001a */ 	div	$zero,$t9,$t8
/*  f155ba4:	00007812 */ 	mflo	$t7
/*  f155ba8:	31eeffff */ 	andi	$t6,$t7,0xffff
/*  f155bac:	17000002 */ 	bnez	$t8,.L0f155bb8
/*  f155bb0:	00000000 */ 	nop
/*  f155bb4:	0007000d */ 	break	0x7
.L0f155bb8:
/*  f155bb8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f155bbc:	17010004 */ 	bne	$t8,$at,.L0f155bd0
/*  f155bc0:	3c018000 */ 	lui	$at,0x8000
/*  f155bc4:	17210002 */ 	bne	$t9,$at,.L0f155bd0
/*  f155bc8:	00000000 */ 	nop
/*  f155bcc:	0006000d */ 	break	0x6
.L0f155bd0:
/*  f155bd0:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f155bd4:	37380400 */ 	ori	$t8,$t9,0x400
/*  f155bd8:	acb80004 */ 	sw	$t8,0x4($a1)
/*  f155bdc:	3c0f8008 */ 	lui	$t7,%hi(var8007fb9c)
/*  f155be0:	8deffb9c */ 	lw	$t7,%lo(var8007fb9c)($t7)
/*  f155be4:	8fb800c0 */ 	lw	$t8,0xc0($sp)
/*  f155be8:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f155bec:	51e00100 */ 	beqzl	$t7,.L0f155ff0
/*  f155bf0:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f155bf4:	8dd90000 */ 	lw	$t9,0x0($t6)
/*  f155bf8:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f155bfc:	0fc54edb */ 	jal	func0f153b6c
/*  f155c00:	03382021 */ 	addu	$a0,$t9,$t8
/*  f155c04:	3c0e8008 */ 	lui	$t6,%hi(g_ScaleX)
/*  f155c08:	8dcefac0 */ 	lw	$t6,%lo(g_ScaleX)($t6)
/*  f155c0c:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f155c10:	3c058008 */ 	lui	$a1,%hi(var8007fba0)
/*  f155c14:	8ca5fba0 */ 	lw	$a1,%lo(var8007fba0)($a1)
/*  f155c18:	01ee001a */ 	div	$zero,$t7,$t6
/*  f155c1c:	00001812 */ 	mflo	$v1
/*  f155c20:	3c0d8008 */ 	lui	$t5,%hi(var8007fad0)
/*  f155c24:	25adfad0 */ 	addiu	$t5,$t5,%lo(var8007fad0)
/*  f155c28:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f155c2c:	15c00002 */ 	bnez	$t6,.L0f155c38
/*  f155c30:	00000000 */ 	nop
/*  f155c34:	0007000d */ 	break	0x7
.L0f155c38:
/*  f155c38:	2401ffff */ 	addiu	$at,$zero,-1
/*  f155c3c:	15c10004 */ 	bne	$t6,$at,.L0f155c50
/*  f155c40:	3c018000 */ 	lui	$at,0x8000
/*  f155c44:	15e10002 */ 	bne	$t7,$at,.L0f155c50
/*  f155c48:	00000000 */ 	nop
/*  f155c4c:	0006000d */ 	break	0x6
.L0f155c50:
/*  f155c50:	00a3082a */ 	slt	$at,$a1,$v1
/*  f155c54:	5420002e */ 	bnezl	$at,.L0f155d10
/*  f155c58:	24a2fffd */ 	addiu	$v0,$a1,-3
/*  f155c5c:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f155c60:	8db80000 */ 	lw	$t8,0x0($t5)
/*  f155c64:	3c04800a */ 	lui	$a0,%hi(var800a4634)
/*  f155c68:	00a03825 */ 	or	$a3,$a1,$zero
/*  f155c6c:	03380019 */ 	multu	$t9,$t8
/*  f155c70:	3c02800a */ 	lui	$v0,%hi(var800a45d0+0x4)
/*  f155c74:	00007812 */ 	mflo	$t7
/*  f155c78:	006f7021 */ 	addu	$t6,$v1,$t7
/*  f155c7c:	01c5082a */ 	slt	$at,$t6,$a1
/*  f155c80:	54200023 */ 	bnezl	$at,.L0f155d10
/*  f155c84:	24a2fffd */ 	addiu	$v0,$a1,-3
/*  f155c88:	82390001 */ 	lb	$t9,0x1($s1)
/*  f155c8c:	92380002 */ 	lbu	$t8,0x2($s1)
/*  f155c90:	8c4245d4 */ 	lw	$v0,%lo(var800a45d0+0x4)($v0)
/*  f155c94:	032a3021 */ 	addu	$a2,$t9,$t2
/*  f155c98:	00d87821 */ 	addu	$t7,$a2,$t8
/*  f155c9c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f155ca0:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f155ca4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f155ca8:	8c844634 */ 	lw	$a0,%lo(var800a4634)($a0)
/*  f155cac:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f155cb0:	0fc35343 */ 	jal	func0f0d4d0c
/*  f155cb4:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f155cb8:	3c01800a */ 	lui	$at,%hi(var800a4634)
/*  f155cbc:	ac224634 */ 	sw	$v0,%lo(var800a4634)($at)
/*  f155cc0:	3c198008 */ 	lui	$t9,%hi(g_ScaleX)
/*  f155cc4:	8f39fac0 */ 	lw	$t9,%lo(g_ScaleX)($t9)
/*  f155cc8:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f155ccc:	3c0d8008 */ 	lui	$t5,%hi(var8007fad0)
/*  f155cd0:	3c058008 */ 	lui	$a1,%hi(var8007fba0)
/*  f155cd4:	01d9001a */ 	div	$zero,$t6,$t9
/*  f155cd8:	00001812 */ 	mflo	$v1
/*  f155cdc:	8ca5fba0 */ 	lw	$a1,%lo(var8007fba0)($a1)
/*  f155ce0:	25adfad0 */ 	addiu	$t5,$t5,%lo(var8007fad0)
/*  f155ce4:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f155ce8:	17200002 */ 	bnez	$t9,.L0f155cf4
/*  f155cec:	00000000 */ 	nop
/*  f155cf0:	0007000d */ 	break	0x7
.L0f155cf4:
/*  f155cf4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f155cf8:	17210004 */ 	bne	$t9,$at,.L0f155d0c
/*  f155cfc:	3c018000 */ 	lui	$at,0x8000
/*  f155d00:	15c10002 */ 	bne	$t6,$at,.L0f155d0c
/*  f155d04:	00000000 */ 	nop
/*  f155d08:	0006000d */ 	break	0x6
.L0f155d0c:
/*  f155d0c:	24a2fffd */ 	addiu	$v0,$a1,-3
.L0f155d10:
/*  f155d10:	0043082a */ 	slt	$at,$v0,$v1
/*  f155d14:	542000b6 */ 	bnezl	$at,.L0f155ff0
/*  f155d18:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f155d1c:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f155d20:	8daf0000 */ 	lw	$t7,0x0($t5)
/*  f155d24:	3c04800a */ 	lui	$a0,%hi(var800a4634)
/*  f155d28:	00a03825 */ 	or	$a3,$a1,$zero
/*  f155d2c:	030f0019 */ 	multu	$t8,$t7
/*  f155d30:	00007012 */ 	mflo	$t6
/*  f155d34:	006ec821 */ 	addu	$t9,$v1,$t6
/*  f155d38:	0322082a */ 	slt	$at,$t9,$v0
/*  f155d3c:	142000ab */ 	bnez	$at,.L0f155fec
/*  f155d40:	3c02800a */ 	lui	$v0,%hi(var800a45d0+0x4)
/*  f155d44:	82380001 */ 	lb	$t8,0x1($s1)
/*  f155d48:	922f0002 */ 	lbu	$t7,0x2($s1)
/*  f155d4c:	8c4245d4 */ 	lw	$v0,%lo(var800a45d0+0x4)($v0)
/*  f155d50:	030a3021 */ 	addu	$a2,$t8,$t2
/*  f155d54:	00cf7021 */ 	addu	$t6,$a2,$t7
/*  f155d58:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f155d5c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f155d60:	8c844634 */ 	lw	$a0,%lo(var800a4634)($a0)
/*  f155d64:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f155d68:	0fc35343 */ 	jal	func0f0d4d0c
/*  f155d6c:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f155d70:	3c01800a */ 	lui	$at,%hi(var800a4634)
/*  f155d74:	1000009d */ 	b	.L0f155fec
/*  f155d78:	ac224634 */ 	sw	$v0,%lo(var800a4634)($at)
/*  f155d7c:	0186082a */ 	slt	$at,$t4,$a2
.L0f155d80:
/*  f155d80:	5420009b */ 	bnezl	$at,.L0f155ff0
/*  f155d84:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f155d88:	8db90000 */ 	lw	$t9,0x0($t5)
/*  f155d8c:	3c068008 */ 	lui	$a2,%hi(var8007fadc)
/*  f155d90:	24c6fadc */ 	addiu	$a2,$a2,%lo(var8007fadc)
/*  f155d94:	01390019 */ 	multu	$t1,$t9
/*  f155d98:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f155d9c:	3c088008 */ 	lui	$t0,%hi(var8007fae0)
/*  f155da0:	2508fae0 */ 	addiu	$t0,$t0,%lo(var8007fae0)
/*  f155da4:	3c01e400 */ 	lui	$at,0xe400
/*  f155da8:	02001025 */ 	or	$v0,$s0,$zero
/*  f155dac:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155db0:	02001825 */ 	or	$v1,$s0,$zero
/*  f155db4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155db8:	02002025 */ 	or	$a0,$s0,$zero
/*  f155dbc:	0000c012 */ 	mflo	$t8
/*  f155dc0:	00f87821 */ 	addu	$t7,$a3,$t8
/*  f155dc4:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f155dc8:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f155dcc:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f155dd0:	000f7300 */ 	sll	$t6,$t7,0xc
/*  f155dd4:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f155dd8:	01c1c825 */ 	or	$t9,$t6,$at
/*  f155ddc:	000cc080 */ 	sll	$t8,$t4,0x2
/*  f155de0:	030f7021 */ 	addu	$t6,$t8,$t7
/*  f155de4:	31d80fff */ 	andi	$t8,$t6,0xfff
/*  f155de8:	03387825 */ 	or	$t7,$t9,$t8
/*  f155dec:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f155df0:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f155df4:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f155df8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155dfc:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f155e00:	03387821 */ 	addu	$t7,$t9,$t8
/*  f155e04:	82380001 */ 	lb	$t8,0x1($s1)
/*  f155e08:	31ee0fff */ 	andi	$t6,$t7,0xfff
/*  f155e0c:	000ecb00 */ 	sll	$t9,$t6,0xc
/*  f155e10:	01587821 */ 	addu	$t7,$t2,$t8
/*  f155e14:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f155e18:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f155e1c:	01d87821 */ 	addu	$t7,$t6,$t8
/*  f155e20:	31ee0fff */ 	andi	$t6,$t7,0xfff
/*  f155e24:	032ec025 */ 	or	$t8,$t9,$t6
/*  f155e28:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f155e2c:	3c0fb400 */ 	lui	$t7,0xb400
/*  f155e30:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f155e34:	3c198008 */ 	lui	$t9,%hi(var8007fae4)
/*  f155e38:	8f39fae4 */ 	lw	$t9,%lo(var8007fae4)($t9)
/*  f155e3c:	27380020 */ 	addiu	$t8,$t9,0x20
/*  f155e40:	3c198008 */ 	lui	$t9,%hi(var8007fae8)
/*  f155e44:	8f39fae8 */ 	lw	$t9,%lo(var8007fae8)($t9)
/*  f155e48:	00187c00 */ 	sll	$t7,$t8,0x10
/*  f155e4c:	272e0020 */ 	addiu	$t6,$t9,0x20
/*  f155e50:	31d8ffff */ 	andi	$t8,$t6,0xffff
/*  f155e54:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f155e58:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f155e5c:	3c0eb300 */ 	lui	$t6,0xb300
/*  f155e60:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f155e64:	24180400 */ 	addiu	$t8,$zero,0x400
/*  f155e68:	8daf0000 */ 	lw	$t7,0x0($t5)
/*  f155e6c:	030f001a */ 	div	$zero,$t8,$t7
/*  f155e70:	0000c812 */ 	mflo	$t9
/*  f155e74:	332effff */ 	andi	$t6,$t9,0xffff
/*  f155e78:	15e00002 */ 	bnez	$t7,.L0f155e84
/*  f155e7c:	00000000 */ 	nop
/*  f155e80:	0007000d */ 	break	0x7
.L0f155e84:
/*  f155e84:	2401ffff */ 	addiu	$at,$zero,-1
/*  f155e88:	15e10004 */ 	bne	$t7,$at,.L0f155e9c
/*  f155e8c:	3c018000 */ 	lui	$at,0x8000
/*  f155e90:	17010002 */ 	bne	$t8,$at,.L0f155e9c
/*  f155e94:	00000000 */ 	nop
/*  f155e98:	0006000d */ 	break	0x6
.L0f155e9c:
/*  f155e9c:	000ec400 */ 	sll	$t8,$t6,0x10
/*  f155ea0:	370f0400 */ 	ori	$t7,$t8,0x400
/*  f155ea4:	10000051 */ 	b	.L0f155fec
/*  f155ea8:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f155eac:	92390002 */ 	lbu	$t9,0x2($s1)
.L0f155eb0:
/*  f155eb0:	00d91021 */ 	addu	$v0,$a2,$t9
/*  f155eb4:	004b082a */ 	slt	$at,$v0,$t3
/*  f155eb8:	5420004d */ 	bnezl	$at,.L0f155ff0
/*  f155ebc:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f155ec0:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f155ec4:	3c068008 */ 	lui	$a2,%hi(var8007fadc)
/*  f155ec8:	24c6fadc */ 	addiu	$a2,$a2,%lo(var8007fadc)
/*  f155ecc:	012e0019 */ 	multu	$t1,$t6
/*  f155ed0:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f155ed4:	3c088008 */ 	lui	$t0,%hi(var8007fae0)
/*  f155ed8:	2508fae0 */ 	addiu	$t0,$t0,%lo(var8007fae0)
/*  f155edc:	3c01e400 */ 	lui	$at,0xe400
/*  f155ee0:	02001825 */ 	or	$v1,$s0,$zero
/*  f155ee4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155ee8:	02002025 */ 	or	$a0,$s0,$zero
/*  f155eec:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155ef0:	02002825 */ 	or	$a1,$s0,$zero
/*  f155ef4:	0000c012 */ 	mflo	$t8
/*  f155ef8:	00f87821 */ 	addu	$t7,$a3,$t8
/*  f155efc:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f155f00:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f155f04:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f155f08:	000fcb00 */ 	sll	$t9,$t7,0xc
/*  f155f0c:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f155f10:	03217025 */ 	or	$t6,$t9,$at
/*  f155f14:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f155f18:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f155f1c:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f155f20:	01d87825 */ 	or	$t7,$t6,$t8
/*  f155f24:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f155f28:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f155f2c:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f155f30:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155f34:	00197080 */ 	sll	$t6,$t9,0x2
/*  f155f38:	01d87821 */ 	addu	$t7,$t6,$t8
/*  f155f3c:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f155f40:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f155f44:	00197300 */ 	sll	$t6,$t9,0xc
/*  f155f48:	000bc080 */ 	sll	$t8,$t3,0x2
/*  f155f4c:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f155f50:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f155f54:	01d87825 */ 	or	$t7,$t6,$t8
/*  f155f58:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f155f5c:	3c19b400 */ 	lui	$t9,0xb400
/*  f155f60:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f155f64:	82380001 */ 	lb	$t8,0x1($s1)
/*  f155f68:	016a7023 */ 	subu	$t6,$t3,$t2
/*  f155f6c:	01d87823 */ 	subu	$t7,$t6,$t8
/*  f155f70:	3c0e8008 */ 	lui	$t6,%hi(var8007fae8)
/*  f155f74:	8dcefae8 */ 	lw	$t6,%lo(var8007fae8)($t6)
/*  f155f78:	000fc940 */ 	sll	$t9,$t7,0x5
/*  f155f7c:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f155f80:	3c0e8008 */ 	lui	$t6,%hi(var8007fae4)
/*  f155f84:	8dcefae4 */ 	lw	$t6,%lo(var8007fae4)($t6)
/*  f155f88:	270f0020 */ 	addiu	$t7,$t8,0x20
/*  f155f8c:	31f9ffff */ 	andi	$t9,$t7,0xffff
/*  f155f90:	25cf0020 */ 	addiu	$t7,$t6,0x20
/*  f155f94:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f155f98:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f155f9c:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f155fa0:	3c0fb300 */ 	lui	$t7,0xb300
/*  f155fa4:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f155fa8:	24190400 */ 	addiu	$t9,$zero,0x400
/*  f155fac:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f155fb0:	032e001a */ 	div	$zero,$t9,$t6
/*  f155fb4:	0000c012 */ 	mflo	$t8
/*  f155fb8:	330fffff */ 	andi	$t7,$t8,0xffff
/*  f155fbc:	15c00002 */ 	bnez	$t6,.L0f155fc8
/*  f155fc0:	00000000 */ 	nop
/*  f155fc4:	0007000d */ 	break	0x7
.L0f155fc8:
/*  f155fc8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f155fcc:	15c10004 */ 	bne	$t6,$at,.L0f155fe0
/*  f155fd0:	3c018000 */ 	lui	$at,0x8000
/*  f155fd4:	17210002 */ 	bne	$t9,$at,.L0f155fe0
/*  f155fd8:	00000000 */ 	nop
/*  f155fdc:	0006000d */ 	break	0x6
.L0f155fe0:
/*  f155fe0:	000fcc00 */ 	sll	$t9,$t7,0x10
/*  f155fe4:	372e0400 */ 	ori	$t6,$t9,0x400
/*  f155fe8:	acae0004 */ 	sw	$t6,0x4($a1)
.L0f155fec:
/*  f155fec:	92380003 */ 	lbu	$t8,0x3($s1)
.L0f155ff0:
/*  f155ff0:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f155ff4:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f155ff8:	02001025 */ 	or	$v0,$s0,$zero
/*  f155ffc:	030f0019 */ 	multu	$t8,$t7
/*  f156000:	0000c812 */ 	mflo	$t9
/*  f156004:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f156008:	ae580000 */ 	sw	$t8,0x0($s2)
/*  f15600c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f156010:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f156014:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f156018:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f15601c:	03e00008 */ 	jr	$ra
/*  f156020:	27bd0098 */ 	addiu	$sp,$sp,0x98
);
#endif

GLOBAL_ASM(
glabel func0f156024
/*  f156024:	3c018008 */ 	lui	$at,%hi(var8007fbd8)
/*  f156028:	03e00008 */ 	jr	$ra
/*  f15602c:	ac24fbd8 */ 	sw	$a0,%lo(var8007fbd8)($at)
);

GLOBAL_ASM(
glabel func0f156030
/*  f156030:	3c01800a */ 	lui	$at,%hi(var800a463c)
/*  f156034:	03e00008 */ 	jr	$ra
/*  f156038:	ac24463c */ 	sw	$a0,%lo(var800a463c)($at)
);

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel textRenderProjected
/*  f157140:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f157144:	3c0e8008 */ 	lui	$t6,0x8008
/*  f157148:	8dce0028 */ 	lw	$t6,0x28($t6)
/*  f15714c:	afb50048 */ 	sw	$s5,0x48($sp)
/*  f157150:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f157154:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f157158:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f15715c:	3c158008 */ 	lui	$s5,0x8008
/*  f157160:	00c08025 */ 	move	$s0,$a2
/*  f157164:	00a08825 */ 	move	$s1,$a1
/*  f157168:	00809825 */ 	move	$s3,$a0
/*  f15716c:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f157170:	afb40044 */ 	sw	$s4,0x44($sp)
/*  f157174:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f157178:	afa700b4 */ 	sw	$a3,0xb4($sp)
/*  f15717c:	11c0000a */ 	beqz	$t6,.PF0f1571a8
/*  f157180:	8eb50030 */ 	lw	$s5,0x30($s5)
/*  f157184:	3c188008 */ 	lui	$t8,0x8008
/*  f157188:	8f180020 */ 	lw	$t8,0x20($t8)
/*  f15718c:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f157190:	24150001 */ 	li	$s5,0x1
/*  f157194:	01f80019 */ 	multu	$t7,$t8
/*  f157198:	0000c812 */ 	mflo	$t9
/*  f15719c:	acd90000 */ 	sw	$t9,0x0($a2)
/*  f1571a0:	10000008 */ 	b	.PF0f1571c4
/*  f1571a4:	00000000 */ 	nop
.PF0f1571a8:
/*  f1571a8:	3c0a8008 */ 	lui	$t2,0x8008
/*  f1571ac:	8d4a0020 */ 	lw	$t2,0x20($t2)
/*  f1571b0:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f1571b4:	012a0019 */ 	multu	$t1,$t2
/*  f1571b8:	00005812 */ 	mflo	$t3
/*  f1571bc:	ae2b0000 */ 	sw	$t3,0x0($s1)
/*  f1571c0:	00000000 */ 	nop
.PF0f1571c4:
/*  f1571c4:	3c0c8008 */ 	lui	$t4,0x8008
/*  f1571c8:	8d8c012c */ 	lw	$t4,0x12c($t4)
/*  f1571cc:	11800064 */ 	beqz	$t4,.PF0f157360
/*  f1571d0:	3c014220 */ 	lui	$at,0x4220
/*  f1571d4:	44816000 */ 	mtc1	$at,$f12
/*  f1571d8:	0fc01abe */ 	jal	0xf006af8
/*  f1571dc:	00000000 */ 	nop
/*  f1571e0:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1571e4:	8dce0020 */ 	lw	$t6,0x20($t6)
/*  f1571e8:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f1571ec:	24090001 */ 	li	$t1,0x1
/*  f1571f0:	3c12800a */ 	lui	$s2,0x800a
/*  f1571f4:	01ae001a */ 	div	$zero,$t5,$t6
/*  f1571f8:	15c00002 */ 	bnez	$t6,.PF0f157204
/*  f1571fc:	00000000 */ 	nop
/*  f157200:	0007000d */ 	break	0x7
.PF0f157204:
/*  f157204:	2401ffff */ 	li	$at,-1
/*  f157208:	15c10004 */ 	bne	$t6,$at,.PF0f15721c
/*  f15720c:	3c018000 */ 	lui	$at,0x8000
/*  f157210:	15a10002 */ 	bne	$t5,$at,.PF0f15721c
/*  f157214:	00000000 */ 	nop
/*  f157218:	0006000d */ 	break	0x6
.PF0f15721c:
/*  f15721c:	3c013f80 */ 	lui	$at,0x3f80
/*  f157220:	44812000 */ 	mtc1	$at,$f4
/*  f157224:	3c0142c8 */ 	lui	$at,0x42c8
/*  f157228:	44814000 */ 	mtc1	$at,$f8
/*  f15722c:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f157230:	3c014316 */ 	lui	$at,0x4316
/*  f157234:	44818000 */ 	mtc1	$at,$f16
/*  f157238:	00007812 */ 	mflo	$t7
/*  f15723c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f157240:	afaf008c */ 	sw	$t7,0x8c($sp)
/*  f157244:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f157248:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f15724c:	3c058008 */ 	lui	$a1,0x8008
/*  f157250:	8e524bdc */ 	lw	$s2,0x4bdc($s2)
/*  f157254:	8faa00c0 */ 	lw	$t2,0xc0($sp)
/*  f157258:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f15725c:	24a50130 */ 	addiu	$a1,$a1,0x130
/*  f157260:	248486e8 */ 	addiu	$a0,$a0,-31000
/*  f157264:	afb80088 */ 	sw	$t8,0x88($sp)
/*  f157268:	4459f800 */ 	cfc1	$t9,$31
/*  f15726c:	44c9f800 */ 	ctc1	$t1,$31
/*  f157270:	00000000 */ 	nop
/*  f157274:	46009124 */ 	cvt.w.s	$f4,$f18
/*  f157278:	4449f800 */ 	cfc1	$t1,$31
/*  f15727c:	00000000 */ 	nop
/*  f157280:	31210004 */ 	andi	$at,$t1,0x4
/*  f157284:	31290078 */ 	andi	$t1,$t1,0x78
/*  f157288:	11200012 */ 	beqz	$t1,.PF0f1572d4
/*  f15728c:	3c014f00 */ 	lui	$at,0x4f00
/*  f157290:	44812000 */ 	mtc1	$at,$f4
/*  f157294:	24090001 */ 	li	$t1,0x1
/*  f157298:	46049101 */ 	sub.s	$f4,$f18,$f4
/*  f15729c:	44c9f800 */ 	ctc1	$t1,$31
/*  f1572a0:	00000000 */ 	nop
/*  f1572a4:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f1572a8:	4449f800 */ 	cfc1	$t1,$31
/*  f1572ac:	00000000 */ 	nop
/*  f1572b0:	31290078 */ 	andi	$t1,$t1,0x78
/*  f1572b4:	15200005 */ 	bnez	$t1,.PF0f1572cc
/*  f1572b8:	00000000 */ 	nop
/*  f1572bc:	44092000 */ 	mfc1	$t1,$f4
/*  f1572c0:	3c018000 */ 	lui	$at,0x8000
/*  f1572c4:	10000007 */ 	b	.PF0f1572e4
/*  f1572c8:	01214825 */ 	or	$t1,$t1,$at
.PF0f1572cc:
/*  f1572cc:	10000005 */ 	b	.PF0f1572e4
/*  f1572d0:	2409ffff */ 	li	$t1,-1
.PF0f1572d4:
/*  f1572d4:	44092000 */ 	mfc1	$t1,$f4
/*  f1572d8:	00000000 */ 	nop
/*  f1572dc:	0520fffb */ 	bltz	$t1,.PF0f1572cc
/*  f1572e0:	00000000 */ 	nop
.PF0f1572e4:
/*  f1572e4:	2401ff00 */ 	li	$at,-256
/*  f1572e8:	01415824 */ 	and	$t3,$t2,$at
/*  f1572ec:	01696025 */ 	or	$t4,$t3,$t1
/*  f1572f0:	44d9f800 */ 	ctc1	$t9,$31
/*  f1572f4:	0c003624 */ 	jal	0xd890
/*  f1572f8:	afac0094 */ 	sw	$t4,0x94($sp)
/*  f1572fc:	3c028008 */ 	lui	$v0,0x8008
/*  f157300:	8c420130 */ 	lw	$v0,0x130($v0)
/*  f157304:	8fb400d0 */ 	lw	$s4,0xd0($sp)
/*  f157308:	02602025 */ 	move	$a0,$s3
/*  f15730c:	10400002 */ 	beqz	$v0,.PF0f157318
/*  f157310:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f157314:	00409025 */ 	move	$s2,$v0
.PF0f157318:
/*  f157318:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*  f15731c:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*  f157320:	8faf0094 */ 	lw	$t7,0x94($sp)
/*  f157324:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f157328:	8fb900c8 */ 	lw	$t9,0xc8($sp)
/*  f15732c:	8faa00cc */ 	lw	$t2,0xcc($sp)
/*  f157330:	27a60088 */ 	addiu	$a2,$sp,0x88
/*  f157334:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f157338:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f15733c:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f157340:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f157344:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f157348:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f15734c:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f157350:	afb90024 */ 	sw	$t9,0x24($sp)
/*  f157354:	0fc55fa0 */ 	jal	0xf157e80
/*  f157358:	afaa0028 */ 	sw	$t2,0x28($sp)
/*  f15735c:	00409825 */ 	move	$s3,$v0
.PF0f157360:
/*  f157360:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f157364:	3c058008 */ 	lui	$a1,0x8008
/*  f157368:	8fb400d0 */ 	lw	$s4,0xd0($sp)
/*  f15736c:	24a5010c */ 	addiu	$a1,$a1,0x10c
/*  f157370:	0c003624 */ 	jal	0xd890
/*  f157374:	248486f0 */ 	addiu	$a0,$a0,-30992
/*  f157378:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f15737c:	3c058008 */ 	lui	$a1,0x8008
/*  f157380:	24a50118 */ 	addiu	$a1,$a1,0x118
/*  f157384:	0c003624 */ 	jal	0xd890
/*  f157388:	248486f8 */ 	addiu	$a0,$a0,-30984
/*  f15738c:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f157390:	3c058008 */ 	lui	$a1,0x8008
/*  f157394:	24a5011c */ 	addiu	$a1,$a1,0x11c
/*  f157398:	0c003624 */ 	jal	0xd890
/*  f15739c:	24848704 */ 	addiu	$a0,$a0,-30972
/*  f1573a0:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f1573a4:	3c058008 */ 	lui	$a1,0x8008
/*  f1573a8:	24a50124 */ 	addiu	$a1,$a1,0x124
/*  f1573ac:	0c003624 */ 	jal	0xd890
/*  f1573b0:	24848710 */ 	addiu	$a0,$a0,-30960
/*  f1573b4:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f1573b8:	3c058008 */ 	lui	$a1,0x8008
/*  f1573bc:	24a50120 */ 	addiu	$a1,$a1,0x120
/*  f1573c0:	0c003624 */ 	jal	0xd890
/*  f1573c4:	24848718 */ 	addiu	$a0,$a0,-30952
/*  f1573c8:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f1573cc:	3c058008 */ 	lui	$a1,0x8008
/*  f1573d0:	24a50110 */ 	addiu	$a1,$a1,0x110
/*  f1573d4:	0c003624 */ 	jal	0xd890
/*  f1573d8:	24848720 */ 	addiu	$a0,$a0,-30944
/*  f1573dc:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f1573e0:	3c058008 */ 	lui	$a1,0x8008
/*  f1573e4:	24a50114 */ 	addiu	$a1,$a1,0x114
/*  f1573e8:	0c003624 */ 	jal	0xd890
/*  f1573ec:	24848728 */ 	addiu	$a0,$a0,-30936
/*  f1573f0:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f1573f4:	8e320000 */ 	lw	$s2,0x0($s1)
/*  f1573f8:	24090048 */ 	li	$t1,0x48
/*  f1573fc:	a3a9009f */ 	sb	$t1,0x9f($sp)
/*  f157400:	16800005 */ 	bnez	$s4,.PF0f157418
/*  f157404:	afab00a0 */ 	sw	$t3,0xa0($sp)
/*  f157408:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*  f15740c:	818d0445 */ 	lb	$t5,0x445($t4)
/*  f157410:	918e0446 */ 	lbu	$t6,0x446($t4)
/*  f157414:	01aea021 */ 	addu	$s4,$t5,$t6
.PF0f157418:
/*  f157418:	3c0f8008 */ 	lui	$t7,0x8008
/*  f15741c:	8def4660 */ 	lw	$t7,0x4660($t7)
/*  f157420:	02601025 */ 	move	$v0,$s3
/*  f157424:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f157428:	11e00005 */ 	beqz	$t7,.PF0f157440
/*  f15742c:	3c18e700 */ 	lui	$t8,0xe700
/*  f157430:	2a81000e */ 	slti	$at,$s4,0xe
/*  f157434:	50200003 */ 	beqzl	$at,.PF0f157444
/*  f157438:	02601825 */ 	move	$v1,$s3
/*  f15743c:	2414000e */ 	li	$s4,0xe
.PF0f157440:
/*  f157440:	02601825 */ 	move	$v1,$s3
.PF0f157444:
/*  f157444:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f157448:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f15744c:	3c19ba00 */ 	lui	$t9,0xba00
/*  f157450:	37390e02 */ 	ori	$t9,$t9,0xe02
/*  f157454:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f157458:	340ac000 */ 	li	$t2,0xc000
/*  f15745c:	ac6a0004 */ 	sw	$t2,0x4($v1)
/*  f157460:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f157464:	02603825 */ 	move	$a3,$s3
/*  f157468:	3c0bfd10 */ 	lui	$t3,0xfd10
/*  f15746c:	aceb0000 */ 	sw	$t3,0x0($a3)
/*  f157470:	3c048008 */ 	lui	$a0,0x8008
/*  f157474:	2484009c */ 	addiu	$a0,$a0,0x9c
/*  f157478:	afa70078 */ 	sw	$a3,0x78($sp)
/*  f15747c:	0c012ab0 */ 	jal	0x4aac0
/*  f157480:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f157484:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f157488:	02601825 */ 	move	$v1,$s3
/*  f15748c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f157490:	ace20004 */ 	sw	$v0,0x4($a3)
/*  f157494:	3c09e600 */ 	lui	$t1,0xe600
/*  f157498:	02602025 */ 	move	$a0,$s3
/*  f15749c:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1574a0:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f1574a4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1574a8:	3c0d0603 */ 	lui	$t5,0x603
/*  f1574ac:	35adc000 */ 	ori	$t5,$t5,0xc000
/*  f1574b0:	3c0cf000 */ 	lui	$t4,0xf000
/*  f1574b4:	02602825 */ 	move	$a1,$s3
/*  f1574b8:	ac8c0000 */ 	sw	$t4,0x0($a0)
/*  f1574bc:	ac8d0004 */ 	sw	$t5,0x4($a0)
/*  f1574c0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1574c4:	3c0ef540 */ 	lui	$t6,0xf540
/*  f1574c8:	35ce0200 */ 	ori	$t6,$t6,0x200
/*  f1574cc:	02603025 */ 	move	$a2,$s3
/*  f1574d0:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f1574d4:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f1574d8:	3c180007 */ 	lui	$t8,0x7
/*  f1574dc:	3718c07c */ 	ori	$t8,$t8,0xc07c
/*  f1574e0:	3c0ff200 */ 	lui	$t7,0xf200
/*  f1574e4:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f1574e8:	acd80004 */ 	sw	$t8,0x4($a2)
/*  f1574ec:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1574f0:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f1574f4:	02604025 */ 	move	$t0,$s3
/*  f1574f8:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1574fc:	3c19fa00 */ 	lui	$t9,0xfa00
/*  f157500:	ad190000 */ 	sw	$t9,0x0($t0)
/*  f157504:	02601025 */ 	move	$v0,$s3
/*  f157508:	ad040004 */ 	sw	$a0,0x4($t0)
/*  f15750c:	3c0ae700 */ 	lui	$t2,0xe700
/*  f157510:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f157514:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f157518:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f15751c:	3c03800a */ 	lui	$v1,0x800a
/*  f157520:	24634b70 */ 	addiu	$v1,$v1,0x4b70
/*  f157524:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f157528:	ac640004 */ 	sw	$a0,0x4($v1)
/*  f15752c:	11600047 */ 	beqz	$t3,.PF0f15764c
/*  f157530:	ac640044 */ 	sw	$a0,0x44($v1)
/*  f157534:	91620000 */ 	lbu	$v0,0x0($t3)
/*  f157538:	10400044 */ 	beqz	$v0,.PF0f15764c
/*  f15753c:	00000000 */ 	nop
/*  f157540:	24010020 */ 	li	$at,0x20
.PF0f157544:
/*  f157544:	5441000d */ 	bnel	$v0,$at,.PF0f15757c
/*  f157548:	2401000a */ 	li	$at,0xa
/*  f15754c:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f157550:	00156080 */ 	sll	$t4,$s5,0x2
/*  f157554:	01956021 */ 	addu	$t4,$t4,$s5
/*  f157558:	012c6821 */ 	addu	$t5,$t1,$t4
/*  f15755c:	ae2d0000 */ 	sw	$t5,0x0($s1)
/*  f157560:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f157564:	240e0048 */ 	li	$t6,0x48
/*  f157568:	a3ae009f */ 	sb	$t6,0x9f($sp)
/*  f15756c:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f157570:	10000032 */ 	b	.PF0f15763c
/*  f157574:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f157578:	2401000a */ 	li	$at,0xa
.PF0f15757c:
/*  f15757c:	14410015 */ 	bne	$v0,$at,.PF0f1575d4
/*  f157580:	3c028008 */ 	lui	$v0,0x8008
/*  f157584:	8c420034 */ 	lw	$v0,0x34($v0)
/*  f157588:	04420009 */ 	bltzl	$v0,.PF0f1575b0
/*  f15758c:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f157590:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f157594:	56590006 */ 	bnel	$s2,$t9,.PF0f1575b0
/*  f157598:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f15759c:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f1575a0:	01425821 */ 	addu	$t3,$t2,$v0
/*  f1575a4:	10000004 */ 	b	.PF0f1575b8
/*  f1575a8:	ae0b0000 */ 	sw	$t3,0x0($s0)
/*  f1575ac:	8e090000 */ 	lw	$t1,0x0($s0)
.PF0f1575b0:
/*  f1575b0:	01346021 */ 	addu	$t4,$t1,$s4
/*  f1575b4:	ae0c0000 */ 	sw	$t4,0x0($s0)
.PF0f1575b8:
/*  f1575b8:	ae320000 */ 	sw	$s2,0x0($s1)
/*  f1575bc:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f1575c0:	240d0048 */ 	li	$t5,0x48
/*  f1575c4:	a3ad009f */ 	sb	$t5,0x9f($sp)
/*  f1575c8:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f1575cc:	1000001b */ 	b	.PF0f15763c
/*  f1575d0:	afaf00b4 */ 	sw	$t7,0xb4($sp)
.PF0f1575d4:
/*  f1575d4:	27b8009f */ 	addiu	$t8,$sp,0x9f
/*  f1575d8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1575dc:	27a400b4 */ 	addiu	$a0,$sp,0xb4
/*  f1575e0:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f1575e4:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f1575e8:	0fc5574b */ 	jal	0xf155d2c
/*  f1575ec:	8fa700b8 */ 	lw	$a3,0xb8($sp)
/*  f1575f0:	8fb90058 */ 	lw	$t9,0x58($sp)
/*  f1575f4:	8faa00bc */ 	lw	$t2,0xbc($sp)
/*  f1575f8:	8fab00a0 */ 	lw	$t3,0xa0($sp)
/*  f1575fc:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f157600:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*  f157604:	8fad00cc */ 	lw	$t5,0xcc($sp)
/*  f157608:	02602025 */ 	move	$a0,$s3
/*  f15760c:	02202825 */ 	move	$a1,$s1
/*  f157610:	02003025 */ 	move	$a2,$s0
/*  f157614:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f157618:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f15761c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f157620:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f157624:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f157628:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f15762c:	afac0024 */ 	sw	$t4,0x24($sp)
/*  f157630:	0fc559e0 */ 	jal	0xf156780
/*  f157634:	afad0028 */ 	sw	$t5,0x28($sp)
/*  f157638:	00409825 */ 	move	$s3,$v0
.PF0f15763c:
/*  f15763c:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f157640:	91c20000 */ 	lbu	$v0,0x0($t6)
/*  f157644:	5440ffbf */ 	bnezl	$v0,.PF0f157544
/*  f157648:	24010020 */ 	li	$at,0x20
.PF0f15764c:
/*  f15764c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f157650:	8def0028 */ 	lw	$t7,0x28($t7)
/*  f157654:	02601025 */ 	move	$v0,$s3
/*  f157658:	11e00012 */ 	beqz	$t7,.PF0f1576a4
/*  f15765c:	00000000 */ 	nop
/*  f157660:	3c198008 */ 	lui	$t9,0x8008
/*  f157664:	8f390020 */ 	lw	$t9,0x20($t9)
/*  f157668:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f15766c:	0319001a */ 	div	$zero,$t8,$t9
/*  f157670:	00005012 */ 	mflo	$t2
/*  f157674:	ae0a0000 */ 	sw	$t2,0x0($s0)
/*  f157678:	17200002 */ 	bnez	$t9,.PF0f157684
/*  f15767c:	00000000 */ 	nop
/*  f157680:	0007000d */ 	break	0x7
.PF0f157684:
/*  f157684:	2401ffff */ 	li	$at,-1
/*  f157688:	17210004 */ 	bne	$t9,$at,.PF0f15769c
/*  f15768c:	3c018000 */ 	lui	$at,0x8000
/*  f157690:	17010002 */ 	bne	$t8,$at,.PF0f15769c
/*  f157694:	00000000 */ 	nop
/*  f157698:	0006000d */ 	break	0x6
.PF0f15769c:
/*  f15769c:	10000011 */ 	b	.PF0f1576e4
/*  f1576a0:	8fbf004c */ 	lw	$ra,0x4c($sp)
.PF0f1576a4:
/*  f1576a4:	3c098008 */ 	lui	$t1,0x8008
/*  f1576a8:	8d290020 */ 	lw	$t1,0x20($t1)
/*  f1576ac:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f1576b0:	0169001a */ 	div	$zero,$t3,$t1
/*  f1576b4:	00006012 */ 	mflo	$t4
/*  f1576b8:	ae2c0000 */ 	sw	$t4,0x0($s1)
/*  f1576bc:	15200002 */ 	bnez	$t1,.PF0f1576c8
/*  f1576c0:	00000000 */ 	nop
/*  f1576c4:	0007000d */ 	break	0x7
.PF0f1576c8:
/*  f1576c8:	2401ffff */ 	li	$at,-1
/*  f1576cc:	15210004 */ 	bne	$t1,$at,.PF0f1576e0
/*  f1576d0:	3c018000 */ 	lui	$at,0x8000
/*  f1576d4:	15610002 */ 	bne	$t3,$at,.PF0f1576e0
/*  f1576d8:	00000000 */ 	nop
/*  f1576dc:	0006000d */ 	break	0x6
.PF0f1576e0:
/*  f1576e0:	8fbf004c */ 	lw	$ra,0x4c($sp)
.PF0f1576e4:
/*  f1576e4:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f1576e8:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f1576ec:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f1576f0:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f1576f4:	8fb40044 */ 	lw	$s4,0x44($sp)
/*  f1576f8:	8fb50048 */ 	lw	$s5,0x48($sp)
/*  f1576fc:	03e00008 */ 	jr	$ra
/*  f157700:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);
#else
GLOBAL_ASM(
glabel textRenderProjected
/*  f15603c:	27bdff40 */ 	addiu	$sp,$sp,-192
/*  f156040:	3c0f8008 */ 	lui	$t7,%hi(var8007fac8)
/*  f156044:	8deffac8 */ 	lw	$t7,%lo(var8007fac8)($t7)
/*  f156048:	3c0e8008 */ 	lui	$t6,%hi(var8007fad0)
/*  f15604c:	8dcefad0 */ 	lw	$t6,%lo(var8007fad0)($t6)
/*  f156050:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f156054:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f156058:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f15605c:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f156060:	00e08025 */ 	or	$s0,$a3,$zero
/*  f156064:	00c09825 */ 	or	$s3,$a2,$zero
/*  f156068:	00a0a025 */ 	or	$s4,$a1,$zero
/*  f15606c:	0080a825 */ 	or	$s5,$a0,$zero
/*  f156070:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f156074:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f156078:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f15607c:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f156080:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f156084:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f156088:	11e0000a */ 	beqz	$t7,.L0f1560b4
/*  f15608c:	afae00b0 */ 	sw	$t6,0xb0($sp)
/*  f156090:	3c198008 */ 	lui	$t9,%hi(g_ScaleX)
/*  f156094:	8f39fac0 */ 	lw	$t9,%lo(g_ScaleX)($t9)
/*  f156098:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f15609c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f1560a0:	03190019 */ 	multu	$t8,$t9
/*  f1560a4:	00004012 */ 	mflo	$t0
/*  f1560a8:	acc80000 */ 	sw	$t0,0x0($a2)
/*  f1560ac:	10000008 */ 	b	.L0f1560d0
/*  f1560b0:	afa900b0 */ 	sw	$t1,0xb0($sp)
.L0f1560b4:
/*  f1560b4:	3c0b8008 */ 	lui	$t3,%hi(g_ScaleX)
/*  f1560b8:	8d6bfac0 */ 	lw	$t3,%lo(g_ScaleX)($t3)
/*  f1560bc:	8e8a0000 */ 	lw	$t2,0x0($s4)
/*  f1560c0:	014b0019 */ 	multu	$t2,$t3
/*  f1560c4:	00006012 */ 	mflo	$t4
/*  f1560c8:	ae8c0000 */ 	sw	$t4,0x0($s4)
/*  f1560cc:	00000000 */ 	nop
.L0f1560d0:
/*  f1560d0:	3c0d8008 */ 	lui	$t5,%hi(var8007fbd8)
/*  f1560d4:	8dadfbd8 */ 	lw	$t5,%lo(var8007fbd8)($t5)
/*  f1560d8:	11a00062 */ 	beqz	$t5,.L0f156264
/*  f1560dc:	3c014220 */ 	lui	$at,0x4220
/*  f1560e0:	44816000 */ 	mtc1	$at,$f12
/*  f1560e4:	0fc01ac2 */ 	jal	func0f006b08
/*  f1560e8:	00000000 */ 	nop
/*  f1560ec:	3c0f8008 */ 	lui	$t7,%hi(g_ScaleX)
/*  f1560f0:	8deffac0 */ 	lw	$t7,%lo(g_ScaleX)($t7)
/*  f1560f4:	8e8e0000 */ 	lw	$t6,0x0($s4)
/*  f1560f8:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f1560fc:	3c11800a */ 	lui	$s1,%hi(var800a463c)
/*  f156100:	01cf001a */ 	div	$zero,$t6,$t7
/*  f156104:	15e00002 */ 	bnez	$t7,.L0f156110
/*  f156108:	00000000 */ 	nop
/*  f15610c:	0007000d */ 	break	0x7
.L0f156110:
/*  f156110:	2401ffff */ 	addiu	$at,$zero,-1
/*  f156114:	15e10004 */ 	bne	$t7,$at,.L0f156128
/*  f156118:	3c018000 */ 	lui	$at,0x8000
/*  f15611c:	15c10002 */ 	bne	$t6,$at,.L0f156128
/*  f156120:	00000000 */ 	nop
/*  f156124:	0006000d */ 	break	0x6
.L0f156128:
/*  f156128:	3c013f80 */ 	lui	$at,0x3f80
/*  f15612c:	44812000 */ 	mtc1	$at,$f4
/*  f156130:	3c0142c8 */ 	lui	$at,0x42c8
/*  f156134:	44814000 */ 	mtc1	$at,$f8
/*  f156138:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f15613c:	3c014316 */ 	lui	$at,0x4316
/*  f156140:	44818000 */ 	mtc1	$at,$f16
/*  f156144:	0000c012 */ 	mflo	$t8
/*  f156148:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f15614c:	afb800a4 */ 	sw	$t8,0xa4($sp)
/*  f156150:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f156154:	3c047f1b */ 	lui	$a0,%hi(var7f1b73b8)
/*  f156158:	3c058008 */ 	lui	$a1,%hi(var8007fbe8)
/*  f15615c:	8e31463c */ 	lw	$s1,%lo(var800a463c)($s1)
/*  f156160:	8faa00d8 */ 	lw	$t2,0xd8($sp)
/*  f156164:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f156168:	24a5fbe8 */ 	addiu	$a1,$a1,%lo(var8007fbe8)
/*  f15616c:	248473b8 */ 	addiu	$a0,$a0,%lo(var7f1b73b8)
/*  f156170:	afb900a0 */ 	sw	$t9,0xa0($sp)
/*  f156174:	4448f800 */ 	cfc1	$t0,$31
/*  f156178:	44c9f800 */ 	ctc1	$t1,$31
/*  f15617c:	00000000 */ 	nop
/*  f156180:	46009124 */ 	cvt.w.s	$f4,$f18
/*  f156184:	4449f800 */ 	cfc1	$t1,$31
/*  f156188:	00000000 */ 	nop
/*  f15618c:	31210004 */ 	andi	$at,$t1,0x4
/*  f156190:	31290078 */ 	andi	$t1,$t1,0x78
/*  f156194:	11200012 */ 	beqz	$t1,.L0f1561e0
/*  f156198:	3c014f00 */ 	lui	$at,0x4f00
/*  f15619c:	44812000 */ 	mtc1	$at,$f4
/*  f1561a0:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f1561a4:	46049101 */ 	sub.s	$f4,$f18,$f4
/*  f1561a8:	44c9f800 */ 	ctc1	$t1,$31
/*  f1561ac:	00000000 */ 	nop
/*  f1561b0:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f1561b4:	4449f800 */ 	cfc1	$t1,$31
/*  f1561b8:	00000000 */ 	nop
/*  f1561bc:	31290078 */ 	andi	$t1,$t1,0x78
/*  f1561c0:	15200005 */ 	bnez	$t1,.L0f1561d8
/*  f1561c4:	00000000 */ 	nop
/*  f1561c8:	44092000 */ 	mfc1	$t1,$f4
/*  f1561cc:	3c018000 */ 	lui	$at,0x8000
/*  f1561d0:	10000007 */ 	b	.L0f1561f0
/*  f1561d4:	01214825 */ 	or	$t1,$t1,$at
.L0f1561d8:
/*  f1561d8:	10000005 */ 	b	.L0f1561f0
/*  f1561dc:	2409ffff */ 	addiu	$t1,$zero,-1
.L0f1561e0:
/*  f1561e0:	44092000 */ 	mfc1	$t1,$f4
/*  f1561e4:	00000000 */ 	nop
/*  f1561e8:	0520fffb */ 	bltz	$t1,.L0f1561d8
/*  f1561ec:	00000000 */ 	nop
.L0f1561f0:
/*  f1561f0:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f1561f4:	01415824 */ 	and	$t3,$t2,$at
/*  f1561f8:	44c8f800 */ 	ctc1	$t0,$31
/*  f1561fc:	0c0036cc */ 	jal	func0000db30
/*  f156200:	01699025 */ 	or	$s2,$t3,$t1
/*  f156204:	3c028008 */ 	lui	$v0,%hi(var8007fbe8)
/*  f156208:	8c42fbe8 */ 	lw	$v0,%lo(var8007fbe8)($v0)
/*  f15620c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f156210:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f156214:	10400002 */ 	beqz	$v0,.L0f156220
/*  f156218:	27a600a0 */ 	addiu	$a2,$sp,0xa0
/*  f15621c:	00408825 */ 	or	$s1,$v0,$zero
.L0f156220:
/*  f156220:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*  f156224:	8fad00d4 */ 	lw	$t5,0xd4($sp)
/*  f156228:	8fae00dc */ 	lw	$t6,0xdc($sp)
/*  f15622c:	8faf00e0 */ 	lw	$t7,0xe0($sp)
/*  f156230:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f156234:	8fb900e8 */ 	lw	$t9,0xe8($sp)
/*  f156238:	02003825 */ 	or	$a3,$s0,$zero
/*  f15623c:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f156240:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f156244:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f156248:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f15624c:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f156250:	afaf0024 */ 	sw	$t7,0x24($sp)
/*  f156254:	afb80028 */ 	sw	$t8,0x28($sp)
/*  f156258:	0fc55b92 */ 	jal	textRender
/*  f15625c:	afb9002c */ 	sw	$t9,0x2c($sp)
/*  f156260:	0040a825 */ 	or	$s5,$v0,$zero
.L0f156264:
/*  f156264:	3c047f1b */ 	lui	$a0,%hi(var7f1b73c0)
/*  f156268:	3c058008 */ 	lui	$a1,%hi(var8007fbac)
/*  f15626c:	24a5fbac */ 	addiu	$a1,$a1,%lo(var8007fbac)
/*  f156270:	0c0036cc */ 	jal	func0000db30
/*  f156274:	248473c0 */ 	addiu	$a0,$a0,%lo(var7f1b73c0)
/*  f156278:	3c047f1b */ 	lui	$a0,%hi(var7f1b73c8)
/*  f15627c:	3c058008 */ 	lui	$a1,%hi(var8007fbb8)
/*  f156280:	24a5fbb8 */ 	addiu	$a1,$a1,%lo(var8007fbb8)
/*  f156284:	0c0036cc */ 	jal	func0000db30
/*  f156288:	248473c8 */ 	addiu	$a0,$a0,%lo(var7f1b73c8)
/*  f15628c:	3c047f1b */ 	lui	$a0,%hi(var7f1b73d4)
/*  f156290:	3c058008 */ 	lui	$a1,%hi(var8007fbbc)
/*  f156294:	24a5fbbc */ 	addiu	$a1,$a1,%lo(var8007fbbc)
/*  f156298:	0c0036cc */ 	jal	func0000db30
/*  f15629c:	248473d4 */ 	addiu	$a0,$a0,%lo(var7f1b73d4)
/*  f1562a0:	3c047f1b */ 	lui	$a0,%hi(var7f1b73e0)
/*  f1562a4:	3c058008 */ 	lui	$a1,%hi(var8007fbc4)
/*  f1562a8:	24a5fbc4 */ 	addiu	$a1,$a1,%lo(var8007fbc4)
/*  f1562ac:	0c0036cc */ 	jal	func0000db30
/*  f1562b0:	248473e0 */ 	addiu	$a0,$a0,%lo(var7f1b73e0)
/*  f1562b4:	3c047f1b */ 	lui	$a0,%hi(var7f1b73e8)
/*  f1562b8:	3c058008 */ 	lui	$a1,%hi(var8007fbc0)
/*  f1562bc:	24a5fbc0 */ 	addiu	$a1,$a1,%lo(var8007fbc0)
/*  f1562c0:	0c0036cc */ 	jal	func0000db30
/*  f1562c4:	248473e8 */ 	addiu	$a0,$a0,%lo(var7f1b73e8)
/*  f1562c8:	3c047f1b */ 	lui	$a0,%hi(var7f1b73f0)
/*  f1562cc:	3c058008 */ 	lui	$a1,%hi(var8007fbb0)
/*  f1562d0:	24a5fbb0 */ 	addiu	$a1,$a1,%lo(var8007fbb0)
/*  f1562d4:	0c0036cc */ 	jal	func0000db30
/*  f1562d8:	248473f0 */ 	addiu	$a0,$a0,%lo(var7f1b73f0)
/*  f1562dc:	3c047f1b */ 	lui	$a0,%hi(var7f1b73f8)
/*  f1562e0:	3c058008 */ 	lui	$a1,%hi(var8007fbb4)
/*  f1562e4:	24a5fbb4 */ 	addiu	$a1,$a1,%lo(var8007fbb4)
/*  f1562e8:	0c0036cc */ 	jal	func0000db30
/*  f1562ec:	248473f8 */ 	addiu	$a0,$a0,%lo(var7f1b73f8)
/*  f1562f0:	8fa800e8 */ 	lw	$t0,0xe8($sp)
/*  f1562f4:	8e910000 */ 	lw	$s1,0x0($s4)
/*  f1562f8:	8e7e0000 */ 	lw	$s8,0x0($s3)
/*  f1562fc:	15000006 */ 	bnez	$t0,.L0f156318
/*  f156300:	24120048 */ 	addiu	$s2,$zero,0x48
/*  f156304:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*  f156308:	814b0445 */ 	lb	$t3,0x445($t2)
/*  f15630c:	91490446 */ 	lbu	$t1,0x446($t2)
/*  f156310:	01696021 */ 	addu	$t4,$t3,$t1
/*  f156314:	afac00e8 */ 	sw	$t4,0xe8($sp)
.L0f156318:
/*  f156318:	3c0d8008 */ 	lui	$t5,%hi(g_LanguageId)
/*  f15631c:	8dad4120 */ 	lw	$t5,%lo(g_LanguageId)($t5)
/*  f156320:	02a01025 */ 	or	$v0,$s5,$zero
/*  f156324:	3c17e700 */ 	lui	$s7,0xe700
/*  f156328:	11a00007 */ 	beqz	$t5,.L0f156348
/*  f15632c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f156330:	8fae00e8 */ 	lw	$t6,0xe8($sp)
/*  f156334:	240f000e */ 	addiu	$t7,$zero,0xe
/*  f156338:	29c1000e */ 	slti	$at,$t6,0xe
/*  f15633c:	50200003 */ 	beqzl	$at,.L0f15634c
/*  f156340:	02a01825 */ 	or	$v1,$s5,$zero
/*  f156344:	afaf00e8 */ 	sw	$t7,0xe8($sp)
.L0f156348:
/*  f156348:	02a01825 */ 	or	$v1,$s5,$zero
.L0f15634c:
/*  f15634c:	ac570000 */ 	sw	$s7,0x0($v0)
/*  f156350:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f156354:	3c18ba00 */ 	lui	$t8,0xba00
/*  f156358:	37180e02 */ 	ori	$t8,$t8,0xe02
/*  f15635c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f156360:	3419c000 */ 	dli	$t9,0xc000
/*  f156364:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f156368:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f15636c:	02a0b025 */ 	or	$s6,$s5,$zero
/*  f156370:	3c08fd10 */ 	lui	$t0,0xfd10
/*  f156374:	3c048008 */ 	lui	$a0,%hi(var8007fb3c)
/*  f156378:	2484fb3c */ 	addiu	$a0,$a0,%lo(var8007fb3c)
/*  f15637c:	aec80000 */ 	sw	$t0,0x0($s6)
/*  f156380:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f156384:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f156388:	02a01825 */ 	or	$v1,$s5,$zero
/*  f15638c:	aec20004 */ 	sw	$v0,0x4($s6)
/*  f156390:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f156394:	3c0ae600 */ 	lui	$t2,0xe600
/*  f156398:	02a02025 */ 	or	$a0,$s5,$zero
/*  f15639c:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f1563a0:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f1563a4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1563a8:	3c090603 */ 	lui	$t1,0x603
/*  f1563ac:	3529c000 */ 	ori	$t1,$t1,0xc000
/*  f1563b0:	3c0bf000 */ 	lui	$t3,0xf000
/*  f1563b4:	02a02825 */ 	or	$a1,$s5,$zero
/*  f1563b8:	ac8b0000 */ 	sw	$t3,0x0($a0)
/*  f1563bc:	ac890004 */ 	sw	$t1,0x4($a0)
/*  f1563c0:	3c0cf540 */ 	lui	$t4,0xf540
/*  f1563c4:	358c0200 */ 	ori	$t4,$t4,0x200
/*  f1563c8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1563cc:	acac0000 */ 	sw	$t4,0x0($a1)
/*  f1563d0:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f1563d4:	02a03025 */ 	or	$a2,$s5,$zero
/*  f1563d8:	3c0e0007 */ 	lui	$t6,0x7
/*  f1563dc:	35cec07c */ 	ori	$t6,$t6,0xc07c
/*  f1563e0:	3c0df200 */ 	lui	$t5,0xf200
/*  f1563e4:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f1563e8:	acce0004 */ 	sw	$t6,0x4($a2)
/*  f1563ec:	8fa400d8 */ 	lw	$a0,0xd8($sp)
/*  f1563f0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1563f4:	02a03825 */ 	or	$a3,$s5,$zero
/*  f1563f8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1563fc:	3c0ffa00 */ 	lui	$t7,0xfa00
/*  f156400:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f156404:	02a01025 */ 	or	$v0,$s5,$zero
/*  f156408:	ace40004 */ 	sw	$a0,0x4($a3)
/*  f15640c:	3c03800a */ 	lui	$v1,%hi(var800a45d0)
/*  f156410:	246345d0 */ 	addiu	$v1,$v1,%lo(var800a45d0)
/*  f156414:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f156418:	ac570000 */ 	sw	$s7,0x0($v0)
/*  f15641c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f156420:	ac640004 */ 	sw	$a0,0x4($v1)
/*  f156424:	12000078 */ 	beqz	$s0,.L0f156608
/*  f156428:	ac640044 */ 	sw	$a0,0x44($v1)
/*  f15642c:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f156430:	10400075 */ 	beqz	$v0,.L0f156608
/*  f156434:	00000000 */ 	nop
/*  f156438:	2417000c */ 	addiu	$s7,$zero,0xc
/*  f15643c:	27b60068 */ 	addiu	$s6,$sp,0x68
/*  f156440:	24010020 */ 	addiu	$at,$zero,0x20
.L0f156444:
/*  f156444:	5441000b */ 	bnel	$v0,$at,.L0f156474
/*  f156448:	2401000a */ 	addiu	$at,$zero,0xa
/*  f15644c:	8fb900b0 */ 	lw	$t9,0xb0($sp)
/*  f156450:	8e980000 */ 	lw	$t8,0x0($s4)
/*  f156454:	24120048 */ 	addiu	$s2,$zero,0x48
/*  f156458:	00194080 */ 	sll	$t0,$t9,0x2
/*  f15645c:	01194021 */ 	addu	$t0,$t0,$t9
/*  f156460:	03085021 */ 	addu	$t2,$t8,$t0
/*  f156464:	ae8a0000 */ 	sw	$t2,0x0($s4)
/*  f156468:	10000064 */ 	b	.L0f1565fc
/*  f15646c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f156470:	2401000a */ 	addiu	$at,$zero,0xa
.L0f156474:
/*  f156474:	54410015 */ 	bnel	$v0,$at,.L0f1564cc
/*  f156478:	28410080 */ 	slti	$at,$v0,0x80
/*  f15647c:	3c028008 */ 	lui	$v0,%hi(var8007fad4)
/*  f156480:	8c42fad4 */ 	lw	$v0,%lo(var8007fad4)($v0)
/*  f156484:	24120048 */ 	addiu	$s2,$zero,0x48
/*  f156488:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15648c:	04420009 */ 	bltzl	$v0,.L0f1564b4
/*  f156490:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f156494:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f156498:	562b0006 */ 	bnel	$s1,$t3,.L0f1564b4
/*  f15649c:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f1564a0:	8e690000 */ 	lw	$t1,0x0($s3)
/*  f1564a4:	01226021 */ 	addu	$t4,$t1,$v0
/*  f1564a8:	10000005 */ 	b	.L0f1564c0
/*  f1564ac:	ae6c0000 */ 	sw	$t4,0x0($s3)
/*  f1564b0:	8e6d0000 */ 	lw	$t5,0x0($s3)
.L0f1564b4:
/*  f1564b4:	8fae00e8 */ 	lw	$t6,0xe8($sp)
/*  f1564b8:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f1564bc:	ae6f0000 */ 	sw	$t7,0x0($s3)
.L0f1564c0:
/*  f1564c0:	1000004e */ 	b	.L0f1565fc
/*  f1564c4:	ae910000 */ 	sw	$s1,0x0($s4)
/*  f1564c8:	28410080 */ 	slti	$at,$v0,0x80
.L0f1564cc:
/*  f1564cc:	1020001d */ 	beqz	$at,.L0f156544
/*  f1564d0:	3059007f */ 	andi	$t9,$v0,0x7f
/*  f1564d4:	00570019 */ 	multu	$v0,$s7
/*  f1564d8:	8fa300d0 */ 	lw	$v1,0xd0($sp)
/*  f1564dc:	8fab00d4 */ 	lw	$t3,0xd4($sp)
/*  f1564e0:	8fa900dc */ 	lw	$t1,0xdc($sp)
/*  f1564e4:	8fac00e0 */ 	lw	$t4,0xe0($sp)
/*  f1564e8:	8fad00e4 */ 	lw	$t5,0xe4($sp)
/*  f1564ec:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1564f0:	02802825 */ 	or	$a1,$s4,$zero
/*  f1564f4:	02603025 */ 	or	$a2,$s3,$zero
/*  f1564f8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f1564fc:	0000c812 */ 	mflo	$t9
/*  f156500:	03233821 */ 	addu	$a3,$t9,$v1
/*  f156504:	24e7fe74 */ 	addiu	$a3,$a3,-396
/*  f156508:	02570019 */ 	multu	$s2,$s7
/*  f15650c:	afbe001c */ 	sw	$s8,0x1c($sp)
/*  f156510:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f156514:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f156518:	afac0024 */ 	sw	$t4,0x24($sp)
/*  f15651c:	afad0028 */ 	sw	$t5,0x28($sp)
/*  f156520:	0000c012 */ 	mflo	$t8
/*  f156524:	03034021 */ 	addu	$t0,$t8,$v1
/*  f156528:	250afe74 */ 	addiu	$t2,$t0,-396
/*  f15652c:	0fc555a3 */ 	jal	func0f15568c
/*  f156530:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f156534:	0040a825 */ 	or	$s5,$v0,$zero
/*  f156538:	92120000 */ 	lbu	$s2,0x0($s0)
/*  f15653c:	1000002f */ 	b	.L0f1565fc
/*  f156540:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f156544:
/*  f156544:	3c0a8008 */ 	lui	$t2,%hi(var8007fbdc)
/*  f156548:	254afbdc */ 	addiu	$t2,$t2,%lo(var8007fbdc)
/*  f15654c:	8d410000 */ 	lw	$at,0x0($t2)
/*  f156550:	920e0001 */ 	lbu	$t6,0x1($s0)
/*  f156554:	0019c1c0 */ 	sll	$t8,$t9,0x7
/*  f156558:	aec10000 */ 	sw	$at,0x0($s6)
/*  f15655c:	8d490004 */ 	lw	$t1,0x4($t2)
/*  f156560:	31cf007f */ 	andi	$t7,$t6,0x7f
/*  f156564:	01f81825 */ 	or	$v1,$t7,$t8
/*  f156568:	aec90004 */ 	sw	$t1,0x4($s6)
/*  f15656c:	8d410008 */ 	lw	$at,0x8($t2)
/*  f156570:	3064ffff */ 	andi	$a0,$v1,0xffff
/*  f156574:	308c2000 */ 	andi	$t4,$a0,0x2000
/*  f156578:	11800005 */ 	beqz	$t4,.L0f156590
/*  f15657c:	aec10008 */ 	sw	$at,0x8($s6)
/*  f156580:	240d000f */ 	addiu	$t5,$zero,0xf
/*  f156584:	240e0010 */ 	addiu	$t6,$zero,0x10
/*  f156588:	a3ad006b */ 	sb	$t5,0x6b($sp)
/*  f15658c:	a3ae006a */ 	sb	$t6,0x6a($sp)
.L0f156590:
/*  f156590:	30991fff */ 	andi	$t9,$a0,0x1fff
/*  f156594:	2b2103c8 */ 	slti	$at,$t9,0x3c8
/*  f156598:	54200003 */ 	bnezl	$at,.L0f1565a8
/*  f15659c:	248f0080 */ 	addiu	$t7,$a0,0x80
/*  f1565a0:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f1565a4:	248f0080 */ 	addiu	$t7,$a0,0x80
.L0f1565a8:
/*  f1565a8:	0fc5b8ff */ 	jal	func0f16e3fc
/*  f1565ac:	a3af0068 */ 	sb	$t7,0x68($sp)
/*  f1565b0:	8fb800d4 */ 	lw	$t8,0xd4($sp)
/*  f1565b4:	8fa800dc */ 	lw	$t0,0xdc($sp)
/*  f1565b8:	8fab00e0 */ 	lw	$t3,0xe0($sp)
/*  f1565bc:	8faa00e4 */ 	lw	$t2,0xe4($sp)
/*  f1565c0:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f1565c4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1565c8:	02802825 */ 	or	$a1,$s4,$zero
/*  f1565cc:	02603025 */ 	or	$a2,$s3,$zero
/*  f1565d0:	02c03825 */ 	or	$a3,$s6,$zero
/*  f1565d4:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f1565d8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f1565dc:	afbe001c */ 	sw	$s8,0x1c($sp)
/*  f1565e0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1565e4:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f1565e8:	afab0024 */ 	sw	$t3,0x24($sp)
/*  f1565ec:	0fc555a3 */ 	jal	func0f15568c
/*  f1565f0:	afaa0028 */ 	sw	$t2,0x28($sp)
/*  f1565f4:	0040a825 */ 	or	$s5,$v0,$zero
/*  f1565f8:	26100002 */ 	addiu	$s0,$s0,0x2
.L0f1565fc:
/*  f1565fc:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f156600:	5440ff90 */ 	bnezl	$v0,.L0f156444
/*  f156604:	24010020 */ 	addiu	$at,$zero,0x20
.L0f156608:
/*  f156608:	3c098008 */ 	lui	$t1,%hi(var8007fac8)
/*  f15660c:	8d29fac8 */ 	lw	$t1,%lo(var8007fac8)($t1)
/*  f156610:	02a01025 */ 	or	$v0,$s5,$zero
/*  f156614:	11200012 */ 	beqz	$t1,.L0f156660
/*  f156618:	00000000 */ 	nop
/*  f15661c:	3c0d8008 */ 	lui	$t5,%hi(g_ScaleX)
/*  f156620:	8dadfac0 */ 	lw	$t5,%lo(g_ScaleX)($t5)
/*  f156624:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f156628:	018d001a */ 	div	$zero,$t4,$t5
/*  f15662c:	00007012 */ 	mflo	$t6
/*  f156630:	ae6e0000 */ 	sw	$t6,0x0($s3)
/*  f156634:	15a00002 */ 	bnez	$t5,.L0f156640
/*  f156638:	00000000 */ 	nop
/*  f15663c:	0007000d */ 	break	0x7
.L0f156640:
/*  f156640:	2401ffff */ 	addiu	$at,$zero,-1
/*  f156644:	15a10004 */ 	bne	$t5,$at,.L0f156658
/*  f156648:	3c018000 */ 	lui	$at,0x8000
/*  f15664c:	15810002 */ 	bne	$t4,$at,.L0f156658
/*  f156650:	00000000 */ 	nop
/*  f156654:	0006000d */ 	break	0x6
.L0f156658:
/*  f156658:	10000011 */ 	b	.L0f1566a0
/*  f15665c:	8fbf005c */ 	lw	$ra,0x5c($sp)
.L0f156660:
/*  f156660:	3c0f8008 */ 	lui	$t7,%hi(g_ScaleX)
/*  f156664:	8deffac0 */ 	lw	$t7,%lo(g_ScaleX)($t7)
/*  f156668:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f15666c:	032f001a */ 	div	$zero,$t9,$t7
/*  f156670:	0000c012 */ 	mflo	$t8
/*  f156674:	ae980000 */ 	sw	$t8,0x0($s4)
/*  f156678:	15e00002 */ 	bnez	$t7,.L0f156684
/*  f15667c:	00000000 */ 	nop
/*  f156680:	0007000d */ 	break	0x7
.L0f156684:
/*  f156684:	2401ffff */ 	addiu	$at,$zero,-1
/*  f156688:	15e10004 */ 	bne	$t7,$at,.L0f15669c
/*  f15668c:	3c018000 */ 	lui	$at,0x8000
/*  f156690:	17210002 */ 	bne	$t9,$at,.L0f15669c
/*  f156694:	00000000 */ 	nop
/*  f156698:	0006000d */ 	break	0x6
.L0f15669c:
/*  f15669c:	8fbf005c */ 	lw	$ra,0x5c($sp)
.L0f1566a0:
/*  f1566a0:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1566a4:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f1566a8:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f1566ac:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f1566b0:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f1566b4:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f1566b8:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f1566bc:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f1566c0:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f1566c4:	03e00008 */ 	jr	$ra
/*  f1566c8:	27bd00c0 */ 	addiu	$sp,$sp,0xc0
);
#endif

Gfx *func0f1566cc(Gfx *gdl, u32 arg1, u32 arg2)
{
	u32 colour = func0f1543ac(arg1, arg2, var800a45d0.colour04);

	if (colour != var800a45d0.colour44) {
		gDPSetColor(gdl++, G_SETENVCOLOR, colour);
	}

	var800a45d0.colour44 = colour;

	colour = (var800a45d0.colour08 & 0xffffff00) | (func0f1543ac(arg1, arg2, var800a45d0.colour08) & 0xff);

	if (colour != var800a45d0.colour48) {
		gDPSetPrimColorViaWord(gdl++, 0, 0, colour);
	}

	var800a45d0.colour48 = colour;

	return gdl;
}

GLOBAL_ASM(
glabel func0f156790
/*  f156790:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f156794:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f156798:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f15679c:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f1567a0:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f1567a4:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f1567a8:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f1567ac:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f1567b0:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f1567b4:	8fab0054 */ 	lw	$t3,0x54($sp)
/*  f1567b8:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f1567bc:	afb90038 */ 	sw	$t9,0x38($sp)
/*  f1567c0:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*  f1567c4:	8cf90004 */ 	lw	$t9,0x4($a3)
/*  f1567c8:	00808025 */ 	or	$s0,$a0,$zero
/*  f1567cc:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f1567d0:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f1567d4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1567d8:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f1567dc:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1567e0:	016fc021 */ 	addu	$t8,$t3,$t7
/*  f1567e4:	00196080 */ 	sll	$t4,$t9,0x2
/*  f1567e8:	030c6821 */ 	addu	$t5,$t8,$t4
/*  f1567ec:	3c0b8008 */ 	lui	$t3,%hi(var8007fac4)
/*  f1567f0:	8d6bfac4 */ 	lw	$t3,%lo(var8007fac4)($t3)
/*  f1567f4:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f1567f8:	3c198008 */ 	lui	$t9,%hi(var8007fad0)
/*  f1567fc:	8f39fad0 */ 	lw	$t9,%lo(var8007fad0)($t9)
/*  f156800:	01cb1021 */ 	addu	$v0,$t6,$t3
/*  f156804:	244fffff */ 	addiu	$t7,$v0,-1
/*  f156808:	01f90019 */ 	multu	$t7,$t9
/*  f15680c:	8cac0000 */ 	lw	$t4,0x0($a1)
/*  f156810:	00a08825 */ 	or	$s1,$a1,$zero
/*  f156814:	00e09025 */ 	or	$s2,$a3,$zero
/*  f156818:	0000c012 */ 	mflo	$t8
/*  f15681c:	01986823 */ 	subu	$t5,$t4,$t8
/*  f156820:	19a00071 */ 	blez	$t5,.L0f1569e8
/*  f156824:	acad0000 */ 	sw	$t5,0x0($a1)
/*  f156828:	0c002f02 */ 	jal	viGetWidth
/*  f15682c:	00000000 */ 	nop
/*  f156830:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f156834:	004b082a */ 	slt	$at,$v0,$t3
/*  f156838:	1420006b */ 	bnez	$at,.L0f1569e8
/*  f15683c:	00000000 */ 	nop
/*  f156840:	0c002f06 */ 	jal	viGetHeight
/*  f156844:	00000000 */ 	nop
/*  f156848:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f15684c:	82590001 */ 	lb	$t9,0x1($s2)
/*  f156850:	8fa90058 */ 	lw	$t1,0x58($sp)
/*  f156854:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f156858:	01f91821 */ 	addu	$v1,$t7,$t9
/*  f15685c:	0043082a */ 	slt	$at,$v0,$v1
/*  f156860:	14200061 */ 	bnez	$at,.L0f1569e8
/*  f156864:	00000000 */ 	nop
/*  f156868:	8e220000 */ 	lw	$v0,0x0($s1)
/*  f15686c:	012cc021 */ 	addu	$t8,$t1,$t4
/*  f156870:	8faa005c */ 	lw	$t2,0x5c($sp)
/*  f156874:	0302082a */ 	slt	$at,$t8,$v0
/*  f156878:	1420005b */ 	bnez	$at,.L0f1569e8
/*  f15687c:	8fad0064 */ 	lw	$t5,0x64($sp)
/*  f156880:	014d7021 */ 	addu	$t6,$t2,$t5
/*  f156884:	01c3082a */ 	slt	$at,$t6,$v1
/*  f156888:	14200057 */ 	bnez	$at,.L0f1569e8
/*  f15688c:	0049082a */ 	slt	$at,$v0,$t1
/*  f156890:	14200055 */ 	bnez	$at,.L0f1569e8
/*  f156894:	00000000 */ 	nop
/*  f156898:	924b0002 */ 	lbu	$t3,0x2($s2)
/*  f15689c:	3c19800a */ 	lui	$t9,%hi(var800a45d0)
/*  f1568a0:	006b7821 */ 	addu	$t7,$v1,$t3
/*  f1568a4:	01ea082a */ 	slt	$at,$t7,$t2
/*  f1568a8:	1420004f */ 	bnez	$at,.L0f1569e8
/*  f1568ac:	00000000 */ 	nop
/*  f1568b0:	933945d0 */ 	lbu	$t9,%lo(var800a45d0)($t9)
/*  f1568b4:	3c0c8008 */ 	lui	$t4,%hi(g_ScaleX)
/*  f1568b8:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f1568bc:	53200017 */ 	beqzl	$t9,.L0f15691c
/*  f1568c0:	02001025 */ 	or	$v0,$s0,$zero
/*  f1568c4:	8d8cfac0 */ 	lw	$t4,%lo(g_ScaleX)($t4)
/*  f1568c8:	8f0d0000 */ 	lw	$t5,0x0($t8)
/*  f1568cc:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f1568d0:	004c001a */ 	div	$zero,$v0,$t4
/*  f1568d4:	00002812 */ 	mflo	$a1
/*  f1568d8:	02002025 */ 	or	$a0,$s0,$zero
/*  f1568dc:	15800002 */ 	bnez	$t4,.L0f1568e8
/*  f1568e0:	00000000 */ 	nop
/*  f1568e4:	0007000d */ 	break	0x7
.L0f1568e8:
/*  f1568e8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1568ec:	15810004 */ 	bne	$t4,$at,.L0f156900
/*  f1568f0:	3c018000 */ 	lui	$at,0x8000
/*  f1568f4:	14410002 */ 	bne	$v0,$at,.L0f156900
/*  f1568f8:	00000000 */ 	nop
/*  f1568fc:	0006000d */ 	break	0x6
.L0f156900:
/*  f156900:	01ae3021 */ 	addu	$a2,$t5,$t6
/*  f156904:	0fc559b3 */ 	jal	func0f1566cc
/*  f156908:	00000000 */ 	nop
/*  f15690c:	8fa90058 */ 	lw	$t1,0x58($sp)
/*  f156910:	8faa005c */ 	lw	$t2,0x5c($sp)
/*  f156914:	00408025 */ 	or	$s0,$v0,$zero
/*  f156918:	02001025 */ 	or	$v0,$s0,$zero
.L0f15691c:
/*  f15691c:	3c0bfd50 */ 	lui	$t3,0xfd50
/*  f156920:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f156924:	8e4f0008 */ 	lw	$t7,0x8($s2)
/*  f156928:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15692c:	02001825 */ 	or	$v1,$s0,$zero
/*  f156930:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f156934:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156938:	3c19e600 */ 	lui	$t9,0xe600
/*  f15693c:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f156940:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f156944:	02004025 */ 	or	$t0,$s0,$zero
/*  f156948:	3c0cf300 */ 	lui	$t4,0xf300
/*  f15694c:	ad0c0000 */ 	sw	$t4,0x0($t0)
/*  f156950:	92440002 */ 	lbu	$a0,0x2($s2)
/*  f156954:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156958:	02001025 */ 	or	$v0,$s0,$zero
/*  f15695c:	0004c0c0 */ 	sll	$t8,$a0,0x3
/*  f156960:	27040011 */ 	addiu	$a0,$t8,0x11
/*  f156964:	00046843 */ 	sra	$t5,$a0,0x1
/*  f156968:	25a4ffff */ 	addiu	$a0,$t5,-1
/*  f15696c:	288107ff */ 	slti	$at,$a0,0x7ff
/*  f156970:	10200003 */ 	beqz	$at,.L0f156980
/*  f156974:	3c0ce700 */ 	lui	$t4,0xe700
/*  f156978:	10000002 */ 	b	.L0f156984
/*  f15697c:	00801825 */ 	or	$v1,$a0,$zero
.L0f156980:
/*  f156980:	240307ff */ 	addiu	$v1,$zero,0x7ff
.L0f156984:
/*  f156984:	306e0fff */ 	andi	$t6,$v1,0xfff
/*  f156988:	000e5b00 */ 	sll	$t3,$t6,0xc
/*  f15698c:	3c010700 */ 	lui	$at,0x700
/*  f156990:	01617825 */ 	or	$t7,$t3,$at
/*  f156994:	35f90800 */ 	ori	$t9,$t7,0x800
/*  f156998:	ad190004 */ 	sw	$t9,0x4($t0)
/*  f15699c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f1569a0:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f1569a4:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f1569a8:	3c0d8008 */ 	lui	$t5,%hi(var8007fad0)
/*  f1569ac:	8dadfad0 */ 	lw	$t5,%lo(var8007fad0)($t5)
/*  f1569b0:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f1569b4:	8fab0060 */ 	lw	$t3,0x60($sp)
/*  f1569b8:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f1569bc:	254effff */ 	addiu	$t6,$t2,-1
/*  f1569c0:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f1569c4:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f1569c8:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f1569cc:	02403825 */ 	or	$a3,$s2,$zero
/*  f1569d0:	030d2823 */ 	subu	$a1,$t8,$t5
/*  f1569d4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f1569d8:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f1569dc:	0fc55a89 */ 	jal	func0f156a24
/*  f1569e0:	24c6ffff */ 	addiu	$a2,$a2,-1
/*  f1569e4:	00408025 */ 	or	$s0,$v0,$zero
.L0f1569e8:
/*  f1569e8:	3c0c8008 */ 	lui	$t4,%hi(var8007fad0)
/*  f1569ec:	8d8cfad0 */ 	lw	$t4,%lo(var8007fad0)($t4)
/*  f1569f0:	92590003 */ 	lbu	$t9,0x3($s2)
/*  f1569f4:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f1569f8:	02001025 */ 	or	$v0,$s0,$zero
/*  f1569fc:	032c0019 */ 	multu	$t9,$t4
/*  f156a00:	0000c012 */ 	mflo	$t8
/*  f156a04:	01b87021 */ 	addu	$t6,$t5,$t8
/*  f156a08:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f156a0c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f156a10:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f156a14:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f156a18:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f156a1c:	03e00008 */ 	jr	$ra
/*  f156a20:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel func0f156a24
/*  f156a24:	90e30003 */ 	lbu	$v1,0x3($a3)
/*  f156a28:	8fae0010 */ 	lw	$t6,0x10($sp)
/*  f156a2c:	8faf0018 */ 	lw	$t7,0x18($sp)
/*  f156a30:	00654821 */ 	addu	$t1,$v1,$a1
/*  f156a34:	25390002 */ 	addiu	$t9,$t1,0x2
/*  f156a38:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f156a3c:	0319082a */ 	slt	$at,$t8,$t9
/*  f156a40:	142000ff */ 	bnez	$at,.L0f156e40
/*  f156a44:	00000000 */ 	nop
/*  f156a48:	80ea0001 */ 	lb	$t2,0x1($a3)
/*  f156a4c:	8fab0014 */ 	lw	$t3,0x14($sp)
/*  f156a50:	8fad001c */ 	lw	$t5,0x1c($sp)
/*  f156a54:	01464021 */ 	addu	$t0,$t2,$a2
/*  f156a58:	010b082a */ 	slt	$at,$t0,$t3
/*  f156a5c:	542000bb */ 	bnezl	$at,.L0f156d4c
/*  f156a60:	90ed0002 */ 	lbu	$t5,0x2($a3)
/*  f156a64:	90ee0002 */ 	lbu	$t6,0x2($a3)
/*  f156a68:	016d6021 */ 	addu	$t4,$t3,$t5
/*  f156a6c:	3c188008 */ 	lui	$t8,%hi(var8007fac8)
/*  f156a70:	010e1021 */ 	addu	$v0,$t0,$t6
/*  f156a74:	244f0002 */ 	addiu	$t7,$v0,0x2
/*  f156a78:	018f082a */ 	slt	$at,$t4,$t7
/*  f156a7c:	5420007a */ 	bnezl	$at,.L0f156c68
/*  f156a80:	0188082a */ 	slt	$at,$t4,$t0
/*  f156a84:	8f18fac8 */ 	lw	$t8,%lo(var8007fac8)($t8)
/*  f156a88:	3c088008 */ 	lui	$t0,%hi(var8007fad0)
/*  f156a8c:	2508fad0 */ 	addiu	$t0,$t0,%lo(var8007fad0)
/*  f156a90:	1300003e */ 	beqz	$t8,.L0f156b8c
/*  f156a94:	00cac823 */ 	subu	$t9,$a2,$t2
/*  f156a98:	00196880 */ 	sll	$t5,$t9,0x2
/*  f156a9c:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f156aa0:	000e7b00 */ 	sll	$t7,$t6,0xc
/*  f156aa4:	0009c880 */ 	sll	$t9,$t1,0x2
/*  f156aa8:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f156aac:	3c01e500 */ 	lui	$at,0xe500
/*  f156ab0:	01e1c025 */ 	or	$t8,$t7,$at
/*  f156ab4:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f156ab8:	030e7825 */ 	or	$t7,$t8,$t6
/*  f156abc:	00801025 */ 	or	$v0,$a0,$zero
/*  f156ac0:	3c088008 */ 	lui	$t0,%hi(var8007fad0)
/*  f156ac4:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f156ac8:	90f90002 */ 	lbu	$t9,0x2($a3)
/*  f156acc:	2508fad0 */ 	addiu	$t0,$t0,%lo(var8007fad0)
/*  f156ad0:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f156ad4:	272d0002 */ 	addiu	$t5,$t9,0x2
/*  f156ad8:	80ef0001 */ 	lb	$t7,0x1($a3)
/*  f156adc:	01b80019 */ 	multu	$t5,$t8
/*  f156ae0:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156ae4:	00cfc823 */ 	subu	$t9,$a2,$t7
/*  f156ae8:	00801825 */ 	or	$v1,$a0,$zero
/*  f156aec:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156af0:	00805825 */ 	or	$t3,$a0,$zero
/*  f156af4:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156af8:	00007012 */ 	mflo	$t6
/*  f156afc:	032e6823 */ 	subu	$t5,$t9,$t6
/*  f156b00:	000dc080 */ 	sll	$t8,$t5,0x2
/*  f156b04:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f156b08:	00057080 */ 	sll	$t6,$a1,0x2
/*  f156b0c:	31cd0fff */ 	andi	$t5,$t6,0xfff
/*  f156b10:	000fcb00 */ 	sll	$t9,$t7,0xc
/*  f156b14:	032dc025 */ 	or	$t8,$t9,$t5
/*  f156b18:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f156b1c:	3c0fb400 */ 	lui	$t7,0xb400
/*  f156b20:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f156b24:	90ee0002 */ 	lbu	$t6,0x2($a3)
/*  f156b28:	3c0fb300 */ 	lui	$t7,0xb300
/*  f156b2c:	00801025 */ 	or	$v0,$a0,$zero
/*  f156b30:	25d90001 */ 	addiu	$t9,$t6,0x1
/*  f156b34:	00196940 */ 	sll	$t5,$t9,0x5
/*  f156b38:	31b8ffff */ 	andi	$t8,$t5,0xffff
/*  f156b3c:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f156b40:	24190400 */ 	addiu	$t9,$zero,0x400
/*  f156b44:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f156b48:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f156b4c:	032e001a */ 	div	$zero,$t9,$t6
/*  f156b50:	00006812 */ 	mflo	$t5
/*  f156b54:	31b8ffff */ 	andi	$t8,$t5,0xffff
/*  f156b58:	00187c00 */ 	sll	$t7,$t8,0x10
/*  f156b5c:	15c00002 */ 	bnez	$t6,.L0f156b68
/*  f156b60:	00000000 */ 	nop
/*  f156b64:	0007000d */ 	break	0x7
.L0f156b68:
/*  f156b68:	2401ffff */ 	addiu	$at,$zero,-1
/*  f156b6c:	15c10004 */ 	bne	$t6,$at,.L0f156b80
/*  f156b70:	3c018000 */ 	lui	$at,0x8000
/*  f156b74:	17210002 */ 	bne	$t9,$at,.L0f156b80
/*  f156b78:	00000000 */ 	nop
/*  f156b7c:	0006000d */ 	break	0x6
.L0f156b80:
/*  f156b80:	35f9fc00 */ 	ori	$t9,$t7,0xfc00
/*  f156b84:	03e00008 */ 	jr	$ra
/*  f156b88:	ad790004 */ 	sw	$t9,0x4($t3)
.L0f156b8c:
/*  f156b8c:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f156b90:	3c01e400 */ 	lui	$at,0xe400
/*  f156b94:	00804825 */ 	or	$t1,$a0,$zero
/*  f156b98:	006e0019 */ 	multu	$v1,$t6
/*  f156b9c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156ba0:	00805025 */ 	or	$t2,$a0,$zero
/*  f156ba4:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156ba8:	00805825 */ 	or	$t3,$a0,$zero
/*  f156bac:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156bb0:	00006812 */ 	mflo	$t5
/*  f156bb4:	01a5c021 */ 	addu	$t8,$t5,$a1
/*  f156bb8:	00187880 */ 	sll	$t7,$t8,0x2
/*  f156bbc:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f156bc0:	332e0fff */ 	andi	$t6,$t9,0xfff
/*  f156bc4:	000e6b00 */ 	sll	$t5,$t6,0xc
/*  f156bc8:	00027880 */ 	sll	$t7,$v0,0x2
/*  f156bcc:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f156bd0:	332e0fff */ 	andi	$t6,$t9,0xfff
/*  f156bd4:	01a1c025 */ 	or	$t8,$t5,$at
/*  f156bd8:	030e6825 */ 	or	$t5,$t8,$t6
/*  f156bdc:	ad2d0000 */ 	sw	$t5,0x0($t1)
/*  f156be0:	80ee0001 */ 	lb	$t6,0x1($a3)
/*  f156be4:	00057880 */ 	sll	$t7,$a1,0x2
/*  f156be8:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f156bec:	00ce6821 */ 	addu	$t5,$a2,$t6
/*  f156bf0:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f156bf4:	0019c300 */ 	sll	$t8,$t9,0xc
/*  f156bf8:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f156bfc:	03197025 */ 	or	$t6,$t8,$t9
/*  f156c00:	ad2e0004 */ 	sw	$t6,0x4($t1)
/*  f156c04:	3c0db400 */ 	lui	$t5,0xb400
/*  f156c08:	ad4d0000 */ 	sw	$t5,0x0($t2)
/*  f156c0c:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f156c10:	24190400 */ 	addiu	$t9,$zero,0x400
/*  f156c14:	3c0fb300 */ 	lui	$t7,0xb300
/*  f156c18:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f156c1c:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f156c20:	00801025 */ 	or	$v0,$a0,$zero
/*  f156c24:	0338001a */ 	div	$zero,$t9,$t8
/*  f156c28:	00007012 */ 	mflo	$t6
/*  f156c2c:	31cdffff */ 	andi	$t5,$t6,0xffff
/*  f156c30:	000d7c00 */ 	sll	$t7,$t5,0x10
/*  f156c34:	17000002 */ 	bnez	$t8,.L0f156c40
/*  f156c38:	00000000 */ 	nop
/*  f156c3c:	0007000d */ 	break	0x7
.L0f156c40:
/*  f156c40:	2401ffff */ 	addiu	$at,$zero,-1
/*  f156c44:	17010004 */ 	bne	$t8,$at,.L0f156c58
/*  f156c48:	3c018000 */ 	lui	$at,0x8000
/*  f156c4c:	17210002 */ 	bne	$t9,$at,.L0f156c58
/*  f156c50:	00000000 */ 	nop
/*  f156c54:	0006000d */ 	break	0x6
.L0f156c58:
/*  f156c58:	35f90400 */ 	ori	$t9,$t7,0x400
/*  f156c5c:	03e00008 */ 	jr	$ra
/*  f156c60:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f156c64:	0188082a */ 	slt	$at,$t4,$t0
.L0f156c68:
/*  f156c68:	14200075 */ 	bnez	$at,.L0f156e40
/*  f156c6c:	3c088008 */ 	lui	$t0,%hi(var8007fad0)
/*  f156c70:	2508fad0 */ 	addiu	$t0,$t0,%lo(var8007fad0)
/*  f156c74:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f156c78:	3c01e400 */ 	lui	$at,0xe400
/*  f156c7c:	00801025 */ 	or	$v0,$a0,$zero
/*  f156c80:	00780019 */ 	multu	$v1,$t8
/*  f156c84:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156c88:	00804825 */ 	or	$t1,$a0,$zero
/*  f156c8c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156c90:	00805025 */ 	or	$t2,$a0,$zero
/*  f156c94:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156c98:	00007012 */ 	mflo	$t6
/*  f156c9c:	01c56821 */ 	addu	$t5,$t6,$a1
/*  f156ca0:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f156ca4:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f156ca8:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f156cac:	00187300 */ 	sll	$t6,$t8,0xc
/*  f156cb0:	000c7880 */ 	sll	$t7,$t4,0x2
/*  f156cb4:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f156cb8:	01c16825 */ 	or	$t5,$t6,$at
/*  f156cbc:	01b9c025 */ 	or	$t8,$t5,$t9
/*  f156cc0:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f156cc4:	80f90001 */ 	lb	$t9,0x1($a3)
/*  f156cc8:	00057080 */ 	sll	$t6,$a1,0x2
/*  f156ccc:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f156cd0:	00d9c021 */ 	addu	$t8,$a2,$t9
/*  f156cd4:	00187080 */ 	sll	$t6,$t8,0x2
/*  f156cd8:	000f6b00 */ 	sll	$t5,$t7,0xc
/*  f156cdc:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f156ce0:	01afc825 */ 	or	$t9,$t5,$t7
/*  f156ce4:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f156ce8:	3c18b400 */ 	lui	$t8,0xb400
/*  f156cec:	ad380000 */ 	sw	$t8,0x0($t1)
/*  f156cf0:	ad200004 */ 	sw	$zero,0x4($t1)
/*  f156cf4:	240f0400 */ 	addiu	$t7,$zero,0x400
/*  f156cf8:	3c0eb300 */ 	lui	$t6,0xb300
/*  f156cfc:	ad4e0000 */ 	sw	$t6,0x0($t2)
/*  f156d00:	8d0d0000 */ 	lw	$t5,0x0($t0)
/*  f156d04:	00801025 */ 	or	$v0,$a0,$zero
/*  f156d08:	01ed001a */ 	div	$zero,$t7,$t5
/*  f156d0c:	0000c812 */ 	mflo	$t9
/*  f156d10:	3338ffff */ 	andi	$t8,$t9,0xffff
/*  f156d14:	00187400 */ 	sll	$t6,$t8,0x10
/*  f156d18:	15a00002 */ 	bnez	$t5,.L0f156d24
/*  f156d1c:	00000000 */ 	nop
/*  f156d20:	0007000d */ 	break	0x7
.L0f156d24:
/*  f156d24:	2401ffff */ 	addiu	$at,$zero,-1
/*  f156d28:	15a10004 */ 	bne	$t5,$at,.L0f156d3c
/*  f156d2c:	3c018000 */ 	lui	$at,0x8000
/*  f156d30:	15e10002 */ 	bne	$t7,$at,.L0f156d3c
/*  f156d34:	00000000 */ 	nop
/*  f156d38:	0006000d */ 	break	0x6
.L0f156d3c:
/*  f156d3c:	35cf0400 */ 	ori	$t7,$t6,0x400
/*  f156d40:	03e00008 */ 	jr	$ra
/*  f156d44:	ad4f0004 */ 	sw	$t7,0x4($t2)
/*  f156d48:	90ed0002 */ 	lbu	$t5,0x2($a3)
.L0f156d4c:
/*  f156d4c:	010d1021 */ 	addu	$v0,$t0,$t5
/*  f156d50:	24590002 */ 	addiu	$t9,$v0,0x2
/*  f156d54:	032b082a */ 	slt	$at,$t9,$t3
/*  f156d58:	14200039 */ 	bnez	$at,.L0f156e40
/*  f156d5c:	3c088008 */ 	lui	$t0,%hi(var8007fad0)
/*  f156d60:	2508fad0 */ 	addiu	$t0,$t0,%lo(var8007fad0)
/*  f156d64:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f156d68:	3c01e400 */ 	lui	$at,0xe400
/*  f156d6c:	00804825 */ 	or	$t1,$a0,$zero
/*  f156d70:	00780019 */ 	multu	$v1,$t8
/*  f156d74:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156d78:	00805025 */ 	or	$t2,$a0,$zero
/*  f156d7c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156d80:	00806025 */ 	or	$t4,$a0,$zero
/*  f156d84:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156d88:	00007012 */ 	mflo	$t6
/*  f156d8c:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f156d90:	000f6880 */ 	sll	$t5,$t7,0x2
/*  f156d94:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f156d98:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f156d9c:	00187300 */ 	sll	$t6,$t8,0xc
/*  f156da0:	00026880 */ 	sll	$t5,$v0,0x2
/*  f156da4:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f156da8:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f156dac:	01c17825 */ 	or	$t7,$t6,$at
/*  f156db0:	01f87025 */ 	or	$t6,$t7,$t8
/*  f156db4:	00056880 */ 	sll	$t5,$a1,0x2
/*  f156db8:	31b90fff */ 	andi	$t9,$t5,0xfff
/*  f156dbc:	ad2e0000 */ 	sw	$t6,0x0($t1)
/*  f156dc0:	000bc080 */ 	sll	$t8,$t3,0x2
/*  f156dc4:	330e0fff */ 	andi	$t6,$t8,0xfff
/*  f156dc8:	00197b00 */ 	sll	$t7,$t9,0xc
/*  f156dcc:	01ee6825 */ 	or	$t5,$t7,$t6
/*  f156dd0:	ad2d0004 */ 	sw	$t5,0x4($t1)
/*  f156dd4:	3c19b400 */ 	lui	$t9,0xb400
/*  f156dd8:	ad590000 */ 	sw	$t9,0x0($t2)
/*  f156ddc:	80f80001 */ 	lb	$t8,0x1($a3)
/*  f156de0:	01787823 */ 	subu	$t7,$t3,$t8
/*  f156de4:	01e67023 */ 	subu	$t6,$t7,$a2
/*  f156de8:	000e6940 */ 	sll	$t5,$t6,0x5
/*  f156dec:	31b9ffff */ 	andi	$t9,$t5,0xffff
/*  f156df0:	ad590004 */ 	sw	$t9,0x4($t2)
/*  f156df4:	3c18b300 */ 	lui	$t8,0xb300
/*  f156df8:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f156dfc:	240e0400 */ 	addiu	$t6,$zero,0x400
/*  f156e00:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f156e04:	01cf001a */ 	div	$zero,$t6,$t7
/*  f156e08:	00006812 */ 	mflo	$t5
/*  f156e0c:	31b9ffff */ 	andi	$t9,$t5,0xffff
/*  f156e10:	0019c400 */ 	sll	$t8,$t9,0x10
/*  f156e14:	15e00002 */ 	bnez	$t7,.L0f156e20
/*  f156e18:	00000000 */ 	nop
/*  f156e1c:	0007000d */ 	break	0x7
.L0f156e20:
/*  f156e20:	2401ffff */ 	addiu	$at,$zero,-1
/*  f156e24:	15e10004 */ 	bne	$t7,$at,.L0f156e38
/*  f156e28:	3c018000 */ 	lui	$at,0x8000
/*  f156e2c:	15c10002 */ 	bne	$t6,$at,.L0f156e38
/*  f156e30:	00000000 */ 	nop
/*  f156e34:	0006000d */ 	break	0x6
.L0f156e38:
/*  f156e38:	370e0400 */ 	ori	$t6,$t8,0x400
/*  f156e3c:	ad8e0004 */ 	sw	$t6,0x4($t4)
.L0f156e40:
/*  f156e40:	03e00008 */ 	jr	$ra
/*  f156e44:	00801025 */ 	or	$v0,$a0,$zero
);

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel textRender
/*  f157e80:	27bdff40 */ 	addiu	$sp,$sp,-192
/*  f157e84:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f157e88:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f157e8c:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f157e90:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f157e94:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f157e98:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f157e9c:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f157ea0:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f157ea4:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f157ea8:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f157eac:	afa700cc */ 	sw	$a3,0xcc($sp)
/*  f157eb0:	3c0f8008 */ 	lui	$t7,0x8008
/*  f157eb4:	8def0020 */ 	lw	$t7,0x20($t7)
/*  f157eb8:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f157ebc:	00808025 */ 	move	$s0,$a0
/*  f157ec0:	02001025 */ 	move	$v0,$s0
/*  f157ec4:	01cf0019 */ 	multu	$t6,$t7
/*  f157ec8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f157ecc:	02001825 */ 	move	$v1,$s0
/*  f157ed0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f157ed4:	240b0048 */ 	li	$t3,0x48
/*  f157ed8:	02009025 */ 	move	$s2,$s0
/*  f157edc:	00a08825 */ 	move	$s1,$a1
/*  f157ee0:	00c09825 */ 	move	$s3,$a2
/*  f157ee4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f157ee8:	3c048008 */ 	lui	$a0,0x8008
/*  f157eec:	0000a012 */ 	mflo	$s4
/*  f157ef0:	acb40000 */ 	sw	$s4,0x0($a1)
/*  f157ef4:	8fac00ec */ 	lw	$t4,0xec($sp)
/*  f157ef8:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f157efc:	a3ab00b7 */ 	sb	$t3,0xb7($sp)
/*  f157f00:	15800006 */ 	bnez	$t4,.PF0f157f1c
/*  f157f04:	afb900b8 */ 	sw	$t9,0xb8($sp)
/*  f157f08:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*  f157f0c:	81ae0445 */ 	lb	$t6,0x445($t5)
/*  f157f10:	91af0446 */ 	lbu	$t7,0x446($t5)
/*  f157f14:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f157f18:	afb800ec */ 	sw	$t8,0xec($sp)
.PF0f157f1c:
/*  f157f1c:	3c198008 */ 	lui	$t9,0x8008
/*  f157f20:	8f394660 */ 	lw	$t9,0x4660($t9)
/*  f157f24:	3c0eba00 */ 	lui	$t6,0xba00
/*  f157f28:	3c0de700 */ 	lui	$t5,0xe700
/*  f157f2c:	13200007 */ 	beqz	$t9,.PF0f157f4c
/*  f157f30:	35ce0e02 */ 	ori	$t6,$t6,0xe02
/*  f157f34:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f157f38:	240c000e */ 	li	$t4,0xe
/*  f157f3c:	2961000e */ 	slti	$at,$t3,0xe
/*  f157f40:	50200003 */ 	beqzl	$at,.PF0f157f50
/*  f157f44:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f157f48:	afac00ec */ 	sw	$t4,0xec($sp)
.PF0f157f4c:
/*  f157f4c:	ac4d0000 */ 	sw	$t5,0x0($v0)
.PF0f157f50:
/*  f157f50:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f157f54:	340fc000 */ 	li	$t7,0xc000
/*  f157f58:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f157f5c:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f157f60:	3c18fd10 */ 	lui	$t8,0xfd10
/*  f157f64:	ae580000 */ 	sw	$t8,0x0($s2)
/*  f157f68:	0c012ab0 */ 	jal	0x4aac0
/*  f157f6c:	248400bc */ 	addiu	$a0,$a0,0xbc
/*  f157f70:	02001825 */ 	move	$v1,$s0
/*  f157f74:	ae420004 */ 	sw	$v0,0x4($s2)
/*  f157f78:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f157f7c:	3c19e600 */ 	lui	$t9,0xe600
/*  f157f80:	02002025 */ 	move	$a0,$s0
/*  f157f84:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f157f88:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f157f8c:	3c0c0607 */ 	lui	$t4,0x607
/*  f157f90:	358cc000 */ 	ori	$t4,$t4,0xc000
/*  f157f94:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f157f98:	3c0bf000 */ 	lui	$t3,0xf000
/*  f157f9c:	ac8b0000 */ 	sw	$t3,0x0($a0)
/*  f157fa0:	ac8c0004 */ 	sw	$t4,0x4($a0)
/*  f157fa4:	02002825 */ 	move	$a1,$s0
/*  f157fa8:	3c09f540 */ 	lui	$t1,0xf540
/*  f157fac:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f157fb0:	35290200 */ 	ori	$t1,$t1,0x200
/*  f157fb4:	02003025 */ 	move	$a2,$s0
/*  f157fb8:	3c0d0007 */ 	lui	$t5,0x7
/*  f157fbc:	aca90000 */ 	sw	$t1,0x0($a1)
/*  f157fc0:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f157fc4:	35adc07c */ 	ori	$t5,$t5,0xc07c
/*  f157fc8:	3c0af200 */ 	lui	$t2,0xf200
/*  f157fcc:	accd0004 */ 	sw	$t5,0x4($a2)
/*  f157fd0:	acca0000 */ 	sw	$t2,0x0($a2)
/*  f157fd4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f157fd8:	8fa800dc */ 	lw	$t0,0xdc($sp)
/*  f157fdc:	02003825 */ 	move	$a3,$s0
/*  f157fe0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f157fe4:	3c0e0110 */ 	lui	$t6,0x110
/*  f157fe8:	02001025 */ 	move	$v0,$s0
/*  f157fec:	acee0004 */ 	sw	$t6,0x4($a3)
/*  f157ff0:	ace90000 */ 	sw	$t1,0x0($a3)
/*  f157ff4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f157ff8:	3c0f0107 */ 	lui	$t7,0x107
/*  f157ffc:	35efc07c */ 	ori	$t7,$t7,0xc07c
/*  f158000:	02001825 */ 	move	$v1,$s0
/*  f158004:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f158008:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f15800c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f158010:	3c18ba00 */ 	lui	$t8,0xba00
/*  f158014:	37181402 */ 	ori	$t8,$t8,0x1402
/*  f158018:	3c190010 */ 	lui	$t9,0x10
/*  f15801c:	02002025 */ 	move	$a0,$s0
/*  f158020:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f158024:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f158028:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15802c:	3c0c3f15 */ 	lui	$t4,0x3f15
/*  f158030:	3c0bfc54 */ 	lui	$t3,0xfc54
/*  f158034:	356bffff */ 	ori	$t3,$t3,0xffff
/*  f158038:	358cf23f */ 	ori	$t4,$t4,0xf23f
/*  f15803c:	02002825 */ 	move	$a1,$s0
/*  f158040:	ac8c0004 */ 	sw	$t4,0x4($a0)
/*  f158044:	ac8b0000 */ 	sw	$t3,0x0($a0)
/*  f158048:	3c0dfa00 */ 	lui	$t5,0xfa00
/*  f15804c:	acad0000 */ 	sw	$t5,0x0($a1)
/*  f158050:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f158054:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f158058:	8fa500d8 */ 	lw	$a1,0xd8($sp)
/*  f15805c:	02003025 */ 	move	$a2,$s0
/*  f158060:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f158064:	3c0efb00 */ 	lui	$t6,0xfb00
/*  f158068:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f15806c:	02001825 */ 	move	$v1,$s0
/*  f158070:	acc50004 */ 	sw	$a1,0x4($a2)
/*  f158074:	3c0fe700 */ 	lui	$t7,0xe700
/*  f158078:	3c04800a */ 	lui	$a0,0x800a
/*  f15807c:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f158080:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f158084:	24844b70 */ 	addiu	$a0,$a0,0x4b70
/*  f158088:	8fb800cc */ 	lw	$t8,0xcc($sp)
/*  f15808c:	ac880008 */ 	sw	$t0,0x8($a0)
/*  f158090:	ac880048 */ 	sw	$t0,0x48($a0)
/*  f158094:	ac850004 */ 	sw	$a1,0x4($a0)
/*  f158098:	ac850044 */ 	sw	$a1,0x44($a0)
/*  f15809c:	93020000 */ 	lbu	$v0,0x0($t8)
/*  f1580a0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1580a4:	50400041 */ 	beqzl	$v0,.PF0f1581ac
/*  f1580a8:	02001825 */ 	move	$v1,$s0
/*  f1580ac:	3c128008 */ 	lui	$s2,0x8008
/*  f1580b0:	26520030 */ 	addiu	$s2,$s2,0x30
/*  f1580b4:	8fbe00e8 */ 	lw	$s8,0xe8($sp)
/*  f1580b8:	8fb700e4 */ 	lw	$s7,0xe4($sp)
/*  f1580bc:	8fb600e0 */ 	lw	$s6,0xe0($sp)
/*  f1580c0:	8fb500d4 */ 	lw	$s5,0xd4($sp)
/*  f1580c4:	24010020 */ 	li	$at,0x20
.PF0f1580c8:
/*  f1580c8:	5441000e */ 	bnel	$v0,$at,.PF0f158104
/*  f1580cc:	2401000a */ 	li	$at,0xa
/*  f1580d0:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f1580d4:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f1580d8:	240e0048 */ 	li	$t6,0x48
/*  f1580dc:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f1580e0:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f1580e4:	032c6821 */ 	addu	$t5,$t9,$t4
/*  f1580e8:	ae2d0000 */ 	sw	$t5,0x0($s1)
/*  f1580ec:	8faf00cc */ 	lw	$t7,0xcc($sp)
/*  f1580f0:	a3ae00b7 */ 	sb	$t6,0xb7($sp)
/*  f1580f4:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f1580f8:	10000027 */ 	b	.PF0f158198
/*  f1580fc:	afb800cc */ 	sw	$t8,0xcc($sp)
/*  f158100:	2401000a */ 	li	$at,0xa
.PF0f158104:
/*  f158104:	1441000c */ 	bne	$v0,$at,.PF0f158138
/*  f158108:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f15810c:	ae340000 */ 	sw	$s4,0x0($s1)
/*  f158110:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f158114:	8fb900ec */ 	lw	$t9,0xec($sp)
/*  f158118:	240d0048 */ 	li	$t5,0x48
/*  f15811c:	01796021 */ 	addu	$t4,$t3,$t9
/*  f158120:	ae6c0000 */ 	sw	$t4,0x0($s3)
/*  f158124:	8fae00cc */ 	lw	$t6,0xcc($sp)
/*  f158128:	a3ad00b7 */ 	sb	$t5,0xb7($sp)
/*  f15812c:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f158130:	10000019 */ 	b	.PF0f158198
/*  f158134:	afaf00cc */ 	sw	$t7,0xcc($sp)
.PF0f158138:
/*  f158138:	27b800b7 */ 	addiu	$t8,$sp,0xb7
/*  f15813c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f158140:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f158144:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f158148:	0fc5574b */ 	jal	0xf155d2c
/*  f15814c:	8fa700d0 */ 	lw	$a3,0xd0($sp)
/*  f158150:	8e4c0000 */ 	lw	$t4,0x0($s2)
/*  f158154:	8fab0074 */ 	lw	$t3,0x74($sp)
/*  f158158:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*  f15815c:	02cc0019 */ 	multu	$s6,$t4
/*  f158160:	02002025 */ 	move	$a0,$s0
/*  f158164:	02202825 */ 	move	$a1,$s1
/*  f158168:	02603025 */ 	move	$a2,$s3
/*  f15816c:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f158170:	afb50014 */ 	sw	$s5,0x14($sp)
/*  f158174:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f158178:	afb70024 */ 	sw	$s7,0x24($sp)
/*  f15817c:	afbe0028 */ 	sw	$s8,0x28($sp)
/*  f158180:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f158184:	00006812 */ 	mflo	$t5
/*  f158188:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f15818c:	0fc55df2 */ 	jal	0xf1577c8
/*  f158190:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f158194:	00408025 */ 	move	$s0,$v0
.PF0f158198:
/*  f158198:	8fae00cc */ 	lw	$t6,0xcc($sp)
/*  f15819c:	91c20000 */ 	lbu	$v0,0x0($t6)
/*  f1581a0:	5440ffc9 */ 	bnezl	$v0,.PF0f1580c8
/*  f1581a4:	24010020 */ 	li	$at,0x20
/*  f1581a8:	02001825 */ 	move	$v1,$s0
.PF0f1581ac:
/*  f1581ac:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1581b0:	3c0fe700 */ 	lui	$t7,0xe700
/*  f1581b4:	02002025 */ 	move	$a0,$s0
/*  f1581b8:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f1581bc:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f1581c0:	3c18ba00 */ 	lui	$t8,0xba00
/*  f1581c4:	37181402 */ 	ori	$t8,$t8,0x1402
/*  f1581c8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1581cc:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f1581d0:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f1581d4:	02002825 */ 	move	$a1,$s0
/*  f1581d8:	3c0bfcff */ 	lui	$t3,0xfcff
/*  f1581dc:	3c19ff2d */ 	lui	$t9,0xff2d
/*  f1581e0:	3739feff */ 	ori	$t9,$t9,0xfeff
/*  f1581e4:	356b97ff */ 	ori	$t3,$t3,0x97ff
/*  f1581e8:	acab0000 */ 	sw	$t3,0x0($a1)
/*  f1581ec:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f1581f0:	3c0d8008 */ 	lui	$t5,0x8008
/*  f1581f4:	8dad0020 */ 	lw	$t5,0x20($t5)
/*  f1581f8:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f1581fc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f158200:	02001025 */ 	move	$v0,$s0
/*  f158204:	018d001a */ 	div	$zero,$t4,$t5
/*  f158208:	00007012 */ 	mflo	$t6
/*  f15820c:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f158210:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f158214:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f158218:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f15821c:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f158220:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f158224:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f158228:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f15822c:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f158230:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f158234:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f158238:	15a00002 */ 	bnez	$t5,.PF0f158244
/*  f15823c:	00000000 */ 	nop
/*  f158240:	0007000d */ 	break	0x7
.PF0f158244:
/*  f158244:	2401ffff */ 	li	$at,-1
/*  f158248:	15a10004 */ 	bne	$t5,$at,.PF0f15825c
/*  f15824c:	3c018000 */ 	lui	$at,0x8000
/*  f158250:	15810002 */ 	bne	$t4,$at,.PF0f15825c
/*  f158254:	00000000 */ 	nop
/*  f158258:	0006000d */ 	break	0x6
.PF0f15825c:
/*  f15825c:	27bd00c0 */ 	addiu	$sp,$sp,0xc0
/*  f158260:	03e00008 */ 	jr	$ra
/*  f158264:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel textRender
/*  f156e48:	27bdff38 */ 	addiu	$sp,$sp,-200
/*  f156e4c:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f156e50:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f156e54:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f156e58:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f156e5c:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f156e60:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f156e64:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f156e68:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f156e6c:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f156e70:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f156e74:	3c0f8008 */ 	lui	$t7,%hi(g_ScaleX)
/*  f156e78:	8deffac0 */ 	lw	$t7,%lo(g_ScaleX)($t7)
/*  f156e7c:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f156e80:	00808825 */ 	or	$s1,$a0,$zero
/*  f156e84:	02201025 */ 	or	$v0,$s1,$zero
/*  f156e88:	01cf0019 */ 	multu	$t6,$t7
/*  f156e8c:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f156e90:	02201825 */ 	or	$v1,$s1,$zero
/*  f156e94:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f156e98:	02209825 */ 	or	$s3,$s1,$zero
/*  f156e9c:	00e08025 */ 	or	$s0,$a3,$zero
/*  f156ea0:	00a09025 */ 	or	$s2,$a1,$zero
/*  f156ea4:	00c0a825 */ 	or	$s5,$a2,$zero
/*  f156ea8:	24160048 */ 	addiu	$s6,$zero,0x48
/*  f156eac:	3c188008 */ 	lui	$t8,%hi(g_LanguageId)
/*  f156eb0:	0000b812 */ 	mflo	$s7
/*  f156eb4:	acb70000 */ 	sw	$s7,0x0($a1)
/*  f156eb8:	8fab00f4 */ 	lw	$t3,0xf4($sp)
/*  f156ebc:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f156ec0:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f156ec4:	15600006 */ 	bnez	$t3,.L0f156ee0
/*  f156ec8:	afb900c0 */ 	sw	$t9,0xc0($sp)
/*  f156ecc:	8fac00d8 */ 	lw	$t4,0xd8($sp)
/*  f156ed0:	818d0445 */ 	lb	$t5,0x445($t4)
/*  f156ed4:	918e0446 */ 	lbu	$t6,0x446($t4)
/*  f156ed8:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f156edc:	afaf00f4 */ 	sw	$t7,0xf4($sp)
.L0f156ee0:
/*  f156ee0:	8f184120 */ 	lw	$t8,%lo(g_LanguageId)($t8)
/*  f156ee4:	3c0dba00 */ 	lui	$t5,0xba00
/*  f156ee8:	3c0ce700 */ 	lui	$t4,0xe700
/*  f156eec:	13000007 */ 	beqz	$t8,.L0f156f0c
/*  f156ef0:	35ad0e02 */ 	ori	$t5,$t5,0xe02
/*  f156ef4:	8fb900f4 */ 	lw	$t9,0xf4($sp)
/*  f156ef8:	240b000e */ 	addiu	$t3,$zero,0xe
/*  f156efc:	2b21000e */ 	slti	$at,$t9,0xe
/*  f156f00:	50200003 */ 	beqzl	$at,.L0f156f10
/*  f156f04:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f156f08:	afab00f4 */ 	sw	$t3,0xf4($sp)
.L0f156f0c:
/*  f156f0c:	ac4c0000 */ 	sw	$t4,0x0($v0)
.L0f156f10:
/*  f156f10:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f156f14:	340ec000 */ 	dli	$t6,0xc000
/*  f156f18:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f156f1c:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f156f20:	3c0ffd10 */ 	lui	$t7,0xfd10
/*  f156f24:	3c048008 */ 	lui	$a0,%hi(var8007fb5c)
/*  f156f28:	2484fb5c */ 	addiu	$a0,$a0,%lo(var8007fb5c)
/*  f156f2c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f156f30:	ae6f0000 */ 	sw	$t7,0x0($s3)
/*  f156f34:	02201825 */ 	or	$v1,$s1,$zero
/*  f156f38:	ae620004 */ 	sw	$v0,0x4($s3)
/*  f156f3c:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f156f40:	3c18e600 */ 	lui	$t8,0xe600
/*  f156f44:	02202025 */ 	or	$a0,$s1,$zero
/*  f156f48:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f156f4c:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f156f50:	3c0b0607 */ 	lui	$t3,0x607
/*  f156f54:	356bc000 */ 	ori	$t3,$t3,0xc000
/*  f156f58:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f156f5c:	3c19f000 */ 	lui	$t9,0xf000
/*  f156f60:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f156f64:	ac8b0004 */ 	sw	$t3,0x4($a0)
/*  f156f68:	02202825 */ 	or	$a1,$s1,$zero
/*  f156f6c:	3c09f540 */ 	lui	$t1,0xf540
/*  f156f70:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f156f74:	35290200 */ 	ori	$t1,$t1,0x200
/*  f156f78:	02203025 */ 	or	$a2,$s1,$zero
/*  f156f7c:	3c0c0007 */ 	lui	$t4,0x7
/*  f156f80:	aca90000 */ 	sw	$t1,0x0($a1)
/*  f156f84:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f156f88:	358cc07c */ 	ori	$t4,$t4,0xc07c
/*  f156f8c:	3c0af200 */ 	lui	$t2,0xf200
/*  f156f90:	accc0004 */ 	sw	$t4,0x4($a2)
/*  f156f94:	acca0000 */ 	sw	$t2,0x0($a2)
/*  f156f98:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f156f9c:	8fa800e4 */ 	lw	$t0,0xe4($sp)
/*  f156fa0:	02203825 */ 	or	$a3,$s1,$zero
/*  f156fa4:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f156fa8:	3c0d0110 */ 	lui	$t5,0x110
/*  f156fac:	02201025 */ 	or	$v0,$s1,$zero
/*  f156fb0:	aced0004 */ 	sw	$t5,0x4($a3)
/*  f156fb4:	ace90000 */ 	sw	$t1,0x0($a3)
/*  f156fb8:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f156fbc:	3c0e0107 */ 	lui	$t6,0x107
/*  f156fc0:	35cec07c */ 	ori	$t6,$t6,0xc07c
/*  f156fc4:	02201825 */ 	or	$v1,$s1,$zero
/*  f156fc8:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f156fcc:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f156fd0:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f156fd4:	3c0fba00 */ 	lui	$t7,0xba00
/*  f156fd8:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*  f156fdc:	3c180010 */ 	lui	$t8,0x10
/*  f156fe0:	02202025 */ 	or	$a0,$s1,$zero
/*  f156fe4:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f156fe8:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f156fec:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f156ff0:	3c0b3f15 */ 	lui	$t3,0x3f15
/*  f156ff4:	3c19fc54 */ 	lui	$t9,0xfc54
/*  f156ff8:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f156ffc:	356bf23f */ 	ori	$t3,$t3,0xf23f
/*  f157000:	02202825 */ 	or	$a1,$s1,$zero
/*  f157004:	ac8b0004 */ 	sw	$t3,0x4($a0)
/*  f157008:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f15700c:	3c0cfa00 */ 	lui	$t4,0xfa00
/*  f157010:	acac0000 */ 	sw	$t4,0x0($a1)
/*  f157014:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f157018:	aca80004 */ 	sw	$t0,0x4($a1)
/*  f15701c:	8fa500e0 */ 	lw	$a1,0xe0($sp)
/*  f157020:	02203025 */ 	or	$a2,$s1,$zero
/*  f157024:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f157028:	3c0dfb00 */ 	lui	$t5,0xfb00
/*  f15702c:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f157030:	02201825 */ 	or	$v1,$s1,$zero
/*  f157034:	acc50004 */ 	sw	$a1,0x4($a2)
/*  f157038:	3c04800a */ 	lui	$a0,%hi(var800a45d0)
/*  f15703c:	3c0ee700 */ 	lui	$t6,0xe700
/*  f157040:	248445d0 */ 	addiu	$a0,$a0,%lo(var800a45d0)
/*  f157044:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f157048:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f15704c:	ac880008 */ 	sw	$t0,0x8($a0)
/*  f157050:	ac880048 */ 	sw	$t0,0x48($a0)
/*  f157054:	ac850004 */ 	sw	$a1,0x4($a0)
/*  f157058:	ac850044 */ 	sw	$a1,0x44($a0)
/*  f15705c:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f157060:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f157064:	50400075 */ 	beqzl	$v0,.L0f15723c
/*  f157068:	02201825 */ 	or	$v1,$s1,$zero
/*  f15706c:	3c138008 */ 	lui	$s3,%hi(var8007fad0)
/*  f157070:	2673fad0 */ 	addiu	$s3,$s3,%lo(var8007fad0)
/*  f157074:	8fbe00dc */ 	lw	$s8,0xdc($sp)
/*  f157078:	27b40074 */ 	addiu	$s4,$sp,0x74
/*  f15707c:	24010020 */ 	addiu	$at,$zero,0x20
.L0f157080:
/*  f157080:	5441000b */ 	bnel	$v0,$at,.L0f1570b0
/*  f157084:	2401000a */ 	addiu	$at,$zero,0xa
/*  f157088:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f15708c:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f157090:	24160048 */ 	addiu	$s6,$zero,0x48
/*  f157094:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f157098:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f15709c:	01f95821 */ 	addu	$t3,$t7,$t9
/*  f1570a0:	ae4b0000 */ 	sw	$t3,0x0($s2)
/*  f1570a4:	10000061 */ 	b	.L0f15722c
/*  f1570a8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1570ac:	2401000a */ 	addiu	$at,$zero,0xa
.L0f1570b0:
/*  f1570b0:	5441000a */ 	bnel	$v0,$at,.L0f1570dc
/*  f1570b4:	28410080 */ 	slti	$at,$v0,0x80
/*  f1570b8:	ae570000 */ 	sw	$s7,0x0($s2)
/*  f1570bc:	8eac0000 */ 	lw	$t4,0x0($s5)
/*  f1570c0:	8fad00f4 */ 	lw	$t5,0xf4($sp)
/*  f1570c4:	24160048 */ 	addiu	$s6,$zero,0x48
/*  f1570c8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1570cc:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f1570d0:	10000056 */ 	b	.L0f15722c
/*  f1570d4:	aeae0000 */ 	sw	$t6,0x0($s5)
/*  f1570d8:	28410080 */ 	slti	$at,$v0,0x80
.L0f1570dc:
/*  f1570dc:	10200022 */ 	beqz	$at,.L0f157168
/*  f1570e0:	304d007f */ 	andi	$t5,$v0,0x7f
/*  f1570e4:	2403000c */ 	addiu	$v1,$zero,0xc
/*  f1570e8:	00430019 */ 	multu	$v0,$v1
/*  f1570ec:	8fad00e8 */ 	lw	$t5,0xe8($sp)
/*  f1570f0:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f1570f4:	8fa800d8 */ 	lw	$t0,0xd8($sp)
/*  f1570f8:	8fac00c0 */ 	lw	$t4,0xc0($sp)
/*  f1570fc:	02202025 */ 	or	$a0,$s1,$zero
/*  f157100:	02402825 */ 	or	$a1,$s2,$zero
/*  f157104:	02a03025 */ 	or	$a2,$s5,$zero
/*  f157108:	afbe0014 */ 	sw	$s8,0x14($sp)
/*  f15710c:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f157110:	0000c012 */ 	mflo	$t8
/*  f157114:	03083821 */ 	addu	$a3,$t8,$t0
/*  f157118:	24e7fe74 */ 	addiu	$a3,$a3,-396
/*  f15711c:	02c30019 */ 	multu	$s6,$v1
/*  f157120:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f157124:	00007812 */ 	mflo	$t7
/*  f157128:	01e8c821 */ 	addu	$t9,$t7,$t0
/*  f15712c:	272bfe74 */ 	addiu	$t3,$t9,-396
/*  f157130:	01ae0019 */ 	multu	$t5,$t6
/*  f157134:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f157138:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f15713c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f157140:	afb90028 */ 	sw	$t9,0x28($sp)
/*  f157144:	afaf0024 */ 	sw	$t7,0x24($sp)
/*  f157148:	0000c012 */ 	mflo	$t8
/*  f15714c:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f157150:	0fc559e4 */ 	jal	func0f156790
/*  f157154:	00000000 */ 	nop
/*  f157158:	00408825 */ 	or	$s1,$v0,$zero
/*  f15715c:	92160000 */ 	lbu	$s6,0x0($s0)
/*  f157160:	10000032 */ 	b	.L0f15722c
/*  f157164:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f157168:
/*  f157168:	3c0f8008 */ 	lui	$t7,%hi(var8007fbec)
/*  f15716c:	25effbec */ 	addiu	$t7,$t7,%lo(var8007fbec)
/*  f157170:	920b0001 */ 	lbu	$t3,0x1($s0)
/*  f157174:	8de10000 */ 	lw	$at,0x0($t7)
/*  f157178:	000d71c0 */ 	sll	$t6,$t5,0x7
/*  f15717c:	316c007f */ 	andi	$t4,$t3,0x7f
/*  f157180:	ae810000 */ 	sw	$at,0x0($s4)
/*  f157184:	8deb0004 */ 	lw	$t3,0x4($t7)
/*  f157188:	018e1825 */ 	or	$v1,$t4,$t6
/*  f15718c:	3064ffff */ 	andi	$a0,$v1,0xffff
/*  f157190:	ae8b0004 */ 	sw	$t3,0x4($s4)
/*  f157194:	8de10008 */ 	lw	$at,0x8($t7)
/*  f157198:	308d2000 */ 	andi	$t5,$a0,0x2000
/*  f15719c:	11a00005 */ 	beqz	$t5,.L0f1571b4
/*  f1571a0:	ae810008 */ 	sw	$at,0x8($s4)
/*  f1571a4:	240c000f */ 	addiu	$t4,$zero,0xf
/*  f1571a8:	240e0010 */ 	addiu	$t6,$zero,0x10
/*  f1571ac:	a3ac0077 */ 	sb	$t4,0x77($sp)
/*  f1571b0:	a3ae0076 */ 	sb	$t6,0x76($sp)
.L0f1571b4:
/*  f1571b4:	30981fff */ 	andi	$t8,$a0,0x1fff
/*  f1571b8:	2b0103c8 */ 	slti	$at,$t8,0x3c8
/*  f1571bc:	54200003 */ 	bnezl	$at,.L0f1571cc
/*  f1571c0:	24990080 */ 	addiu	$t9,$a0,0x80
/*  f1571c4:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f1571c8:	24990080 */ 	addiu	$t9,$a0,0x80
.L0f1571cc:
/*  f1571cc:	0fc5b8ff */ 	jal	func0f16e3fc
/*  f1571d0:	a3b90074 */ 	sb	$t9,0x74($sp)
/*  f1571d4:	8fab00e8 */ 	lw	$t3,0xe8($sp)
/*  f1571d8:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f1571dc:	8faf00c0 */ 	lw	$t7,0xc0($sp)
/*  f1571e0:	8fae00ec */ 	lw	$t6,0xec($sp)
/*  f1571e4:	016d0019 */ 	multu	$t3,$t5
/*  f1571e8:	8fb800f0 */ 	lw	$t8,0xf0($sp)
/*  f1571ec:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f1571f0:	02202025 */ 	or	$a0,$s1,$zero
/*  f1571f4:	02402825 */ 	or	$a1,$s2,$zero
/*  f1571f8:	02a03025 */ 	or	$a2,$s5,$zero
/*  f1571fc:	02803825 */ 	or	$a3,$s4,$zero
/*  f157200:	afb40010 */ 	sw	$s4,0x10($sp)
/*  f157204:	afbe0014 */ 	sw	$s8,0x14($sp)
/*  f157208:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f15720c:	00006012 */ 	mflo	$t4
/*  f157210:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f157214:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f157218:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f15721c:	0fc559e4 */ 	jal	func0f156790
/*  f157220:	afb80028 */ 	sw	$t8,0x28($sp)
/*  f157224:	00408825 */ 	or	$s1,$v0,$zero
/*  f157228:	26100002 */ 	addiu	$s0,$s0,0x2
.L0f15722c:
/*  f15722c:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f157230:	5440ff93 */ 	bnezl	$v0,.L0f157080
/*  f157234:	24010020 */ 	addiu	$at,$zero,0x20
/*  f157238:	02201825 */ 	or	$v1,$s1,$zero
.L0f15723c:
/*  f15723c:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f157240:	3c19e700 */ 	lui	$t9,0xe700
/*  f157244:	02202025 */ 	or	$a0,$s1,$zero
/*  f157248:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f15724c:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f157250:	3c0fba00 */ 	lui	$t7,0xba00
/*  f157254:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*  f157258:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f15725c:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f157260:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f157264:	02202825 */ 	or	$a1,$s1,$zero
/*  f157268:	3c0bfcff */ 	lui	$t3,0xfcff
/*  f15726c:	3c0dff2d */ 	lui	$t5,0xff2d
/*  f157270:	35adfeff */ 	ori	$t5,$t5,0xfeff
/*  f157274:	356b97ff */ 	ori	$t3,$t3,0x97ff
/*  f157278:	acab0000 */ 	sw	$t3,0x0($a1)
/*  f15727c:	acad0004 */ 	sw	$t5,0x4($a1)
/*  f157280:	3c0e8008 */ 	lui	$t6,%hi(g_ScaleX)
/*  f157284:	8dcefac0 */ 	lw	$t6,%lo(g_ScaleX)($t6)
/*  f157288:	8e4c0000 */ 	lw	$t4,0x0($s2)
/*  f15728c:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f157290:	02201025 */ 	or	$v0,$s1,$zero
/*  f157294:	018e001a */ 	div	$zero,$t4,$t6
/*  f157298:	0000c012 */ 	mflo	$t8
/*  f15729c:	ae580000 */ 	sw	$t8,0x0($s2)
/*  f1572a0:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f1572a4:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f1572a8:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f1572ac:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f1572b0:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f1572b4:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f1572b8:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f1572bc:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f1572c0:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f1572c4:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1572c8:	15c00002 */ 	bnez	$t6,.L0f1572d4
/*  f1572cc:	00000000 */ 	nop
/*  f1572d0:	0007000d */ 	break	0x7
.L0f1572d4:
/*  f1572d4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1572d8:	15c10004 */ 	bne	$t6,$at,.L0f1572ec
/*  f1572dc:	3c018000 */ 	lui	$at,0x8000
/*  f1572e0:	15810002 */ 	bne	$t4,$at,.L0f1572ec
/*  f1572e4:	00000000 */ 	nop
/*  f1572e8:	0006000d */ 	break	0x6
.L0f1572ec:
/*  f1572ec:	27bd00c8 */ 	addiu	$sp,$sp,0xc8
/*  f1572f0:	03e00008 */ 	jr	$ra
/*  f1572f4:	00000000 */ 	nop
);
#endif

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel textMeasure
/*  f158268:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f15826c:	240e0048 */ 	li	$t6,0x48
/*  f158270:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f158274:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f158278:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f15827c:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f158280:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f158284:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f158288:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f15828c:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f158290:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f158294:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f158298:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f15829c:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f1582a0:	a3ae005f */ 	sb	$t6,0x5f($sp)
/*  f1582a4:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f1582a8:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f1582ac:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f1582b0:	00a08025 */ 	move	$s0,$a1
/*  f1582b4:	00809025 */ 	move	$s2,$a0
/*  f1582b8:	15e00006 */ 	bnez	$t7,.PF0f1582d4
/*  f1582bc:	00009825 */ 	move	$s3,$zero
/*  f1582c0:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f1582c4:	93190446 */ 	lbu	$t9,0x446($t8)
/*  f1582c8:	83080445 */ 	lb	$t0,0x445($t8)
/*  f1582cc:	03284821 */ 	addu	$t1,$t9,$t0
/*  f1582d0:	afa90074 */ 	sw	$t1,0x74($sp)
.PF0f1582d4:
/*  f1582d4:	3c0a8008 */ 	lui	$t2,0x8008
/*  f1582d8:	8d4a4660 */ 	lw	$t2,0x4660($t2)
/*  f1582dc:	8fab0074 */ 	lw	$t3,0x74($sp)
/*  f1582e0:	11400004 */ 	beqz	$t2,.PF0f1582f4
/*  f1582e4:	2961000e */ 	slti	$at,$t3,0xe
/*  f1582e8:	10200002 */ 	beqz	$at,.PF0f1582f4
/*  f1582ec:	240c000e */ 	li	$t4,0xe
/*  f1582f0:	afac0074 */ 	sw	$t4,0x74($sp)
.PF0f1582f4:
/*  f1582f4:	8fad0068 */ 	lw	$t5,0x68($sp)
/*  f1582f8:	11a00047 */ 	beqz	$t5,.PF0f158418
/*  f1582fc:	00000000 */ 	nop
/*  f158300:	91a20000 */ 	lbu	$v0,0x0($t5)
/*  f158304:	27be004c */ 	addiu	$s8,$sp,0x4c
/*  f158308:	27b70050 */ 	addiu	$s7,$sp,0x50
/*  f15830c:	10400042 */ 	beqz	$v0,.PF0f158418
/*  f158310:	27b60068 */ 	addiu	$s6,$sp,0x68
/*  f158314:	24150020 */ 	li	$s5,0x20
/*  f158318:	8fb40070 */ 	lw	$s4,0x70($sp)
/*  f15831c:	2411000a */ 	li	$s1,0xa
.PF0f158320:
/*  f158320:	16a2000d */ 	bne	$s5,$v0,.PF0f158358
/*  f158324:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f158328:	91cf0001 */ 	lbu	$t7,0x1($t6)
/*  f15832c:	522f0005 */ 	beql	$s1,$t7,.PF0f158344
/*  f158330:	8fa90068 */ 	lw	$t1,0x68($sp)
/*  f158334:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f158338:	27190005 */ 	addiu	$t9,$t8,0x5
/*  f15833c:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f158340:	8fa90068 */ 	lw	$t1,0x68($sp)
.PF0f158344:
/*  f158344:	24080048 */ 	li	$t0,0x48
/*  f158348:	a3a8005f */ 	sb	$t0,0x5f($sp)
/*  f15834c:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f158350:	1000002d */ 	b	.PF0f158408
/*  f158354:	afaa0068 */ 	sw	$t2,0x68($sp)
.PF0f158358:
/*  f158358:	1622000f */ 	bne	$s1,$v0,.PF0f158398
/*  f15835c:	02c02025 */ 	move	$a0,$s6
/*  f158360:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f158364:	0262082a */ 	slt	$at,$s3,$v0
/*  f158368:	50200003 */ 	beqzl	$at,.PF0f158378
/*  f15836c:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f158370:	00409825 */ 	move	$s3,$v0
/*  f158374:	ae000000 */ 	sw	$zero,0x0($s0)
.PF0f158378:
/*  f158378:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f15837c:	8fac0074 */ 	lw	$t4,0x74($sp)
/*  f158380:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f158384:	ae4d0000 */ 	sw	$t5,0x0($s2)
/*  f158388:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f15838c:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f158390:	1000001d */ 	b	.PF0f158408
/*  f158394:	afaf0068 */ 	sw	$t7,0x68($sp)
.PF0f158398:
/*  f158398:	27b8005f */ 	addiu	$t8,$sp,0x5f
/*  f15839c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1583a0:	02e02825 */ 	move	$a1,$s7
/*  f1583a4:	03c03025 */ 	move	$a2,$s8
/*  f1583a8:	0fc5574b */ 	jal	0xf155d2c
/*  f1583ac:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f1583b0:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*  f1583b4:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f1583b8:	8f280004 */ 	lw	$t0,0x4($t9)
/*  f1583bc:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*  f1583c0:	3c198008 */ 	lui	$t9,0x8008
/*  f1583c4:	00084880 */ 	sll	$t1,$t0,0x2
/*  f1583c8:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1583cc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1583d0:	01284821 */ 	addu	$t1,$t1,$t0
/*  f1583d4:	00095080 */ 	sll	$t2,$t1,0x2
/*  f1583d8:	028a5821 */ 	addu	$t3,$s4,$t2
/*  f1583dc:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f1583e0:	016e7821 */ 	addu	$t7,$t3,$t6
/*  f1583e4:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f1583e8:	8f390024 */ 	lw	$t9,0x24($t9)
/*  f1583ec:	8e080000 */ 	lw	$t0,0x0($s0)
/*  f1583f0:	91890003 */ 	lbu	$t1,0x3($t4)
/*  f1583f4:	03191021 */ 	addu	$v0,$t8,$t9
/*  f1583f8:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f1583fc:	01095021 */ 	addu	$t2,$t0,$t1
/*  f158400:	01426823 */ 	subu	$t5,$t2,$v0
/*  f158404:	ae0d0000 */ 	sw	$t5,0x0($s0)
.PF0f158408:
/*  f158408:	8fab0068 */ 	lw	$t3,0x68($sp)
/*  f15840c:	91620000 */ 	lbu	$v0,0x0($t3)
/*  f158410:	1440ffc3 */ 	bnez	$v0,.PF0f158320
/*  f158414:	00000000 */ 	nop
.PF0f158418:
/*  f158418:	3c0e8008 */ 	lui	$t6,0x8008
/*  f15841c:	8dce0020 */ 	lw	$t6,0x20($t6)
/*  f158420:	24010001 */ 	li	$at,0x1
/*  f158424:	3c188008 */ 	lui	$t8,0x8008
/*  f158428:	55c10008 */ 	bnel	$t6,$at,.PF0f15844c
/*  f15842c:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f158430:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f158434:	8f180030 */ 	lw	$t8,0x30($t8)
/*  f158438:	01f80019 */ 	multu	$t7,$t8
/*  f15843c:	0000c812 */ 	mflo	$t9
/*  f158440:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f158444:	00000000 */ 	nop
/*  f158448:	8e0c0000 */ 	lw	$t4,0x0($s0)
.PF0f15844c:
/*  f15844c:	0193082a */ 	slt	$at,$t4,$s3
/*  f158450:	50200003 */ 	beqzl	$at,.PF0f158460
/*  f158454:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f158458:	ae130000 */ 	sw	$s3,0x0($s0)
/*  f15845c:	8fbf0044 */ 	lw	$ra,0x44($sp)
.PF0f158460:
/*  f158460:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f158464:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f158468:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f15846c:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f158470:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f158474:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f158478:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f15847c:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f158480:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f158484:	03e00008 */ 	jr	$ra
/*  f158488:	27bd0060 */ 	addiu	$sp,$sp,0x60
);
#else
GLOBAL_ASM(
glabel textMeasure
/*  f1572f8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1572fc:	afb10008 */ 	sw	$s1,0x8($sp)
/*  f157300:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f157304:	afb40014 */ 	sw	$s4,0x14($sp)
/*  f157308:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f15730c:	afb2000c */ 	sw	$s2,0xc($sp)
/*  f157310:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f157314:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f157318:	00808025 */ 	or	$s0,$a0,$zero
/*  f15731c:	24030048 */ 	addiu	$v1,$zero,0x48
/*  f157320:	00001025 */ 	or	$v0,$zero,$zero
/*  f157324:	16200004 */ 	bnez	$s1,.L0f157338
/*  f157328:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f15732c:	90ee0446 */ 	lbu	$t6,0x446($a3)
/*  f157330:	80ef0445 */ 	lb	$t7,0x445($a3)
/*  f157334:	01cf8821 */ 	addu	$s1,$t6,$t7
.L0f157338:
/*  f157338:	3c188008 */ 	lui	$t8,%hi(g_LanguageId)
/*  f15733c:	8f184120 */ 	lw	$t8,%lo(g_LanguageId)($t8)
/*  f157340:	2a21000e */ 	slti	$at,$s1,0xe
/*  f157344:	13000004 */ 	beqz	$t8,.L0f157358
/*  f157348:	00000000 */ 	nop
/*  f15734c:	10200002 */ 	beqz	$at,.L0f157358
/*  f157350:	00000000 */ 	nop
/*  f157354:	2411000e */ 	addiu	$s1,$zero,0xe
.L0f157358:
/*  f157358:	10c00059 */ 	beqz	$a2,.L0f1574c0
/*  f15735c:	00000000 */ 	nop
/*  f157360:	90c40000 */ 	lbu	$a0,0x0($a2)
/*  f157364:	3c148008 */ 	lui	$s4,%hi(var8007fac4)
/*  f157368:	2694fac4 */ 	addiu	$s4,$s4,%lo(var8007fac4)
/*  f15736c:	10800054 */ 	beqz	$a0,.L0f1574c0
/*  f157370:	00804025 */ 	or	$t0,$a0,$zero
/*  f157374:	2413000d */ 	addiu	$s3,$zero,0xd
/*  f157378:	2412000c */ 	addiu	$s2,$zero,0xc
/*  f15737c:	240c000a */ 	addiu	$t4,$zero,0xa
/*  f157380:	240b0020 */ 	addiu	$t3,$zero,0x20
/*  f157384:	8fa90028 */ 	lw	$t1,0x28($sp)
.L0f157388:
/*  f157388:	1568000a */ 	bne	$t3,$t0,.L0f1573b4
/*  f15738c:	00000000 */ 	nop
/*  f157390:	90d90001 */ 	lbu	$t9,0x1($a2)
/*  f157394:	24030048 */ 	addiu	$v1,$zero,0x48
/*  f157398:	11990004 */ 	beq	$t4,$t9,.L0f1573ac
/*  f15739c:	00000000 */ 	nop
/*  f1573a0:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f1573a4:	25cf0005 */ 	addiu	$t7,$t6,0x5
/*  f1573a8:	acaf0000 */ 	sw	$t7,0x0($a1)
.L0f1573ac:
/*  f1573ac:	10000041 */ 	b	.L0f1574b4
/*  f1573b0:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f1573b4:
/*  f1573b4:	1588000c */ 	bne	$t4,$t0,.L0f1573e8
/*  f1573b8:	29010080 */ 	slti	$at,$t0,0x80
/*  f1573bc:	8ca40000 */ 	lw	$a0,0x0($a1)
/*  f1573c0:	0044082a */ 	slt	$at,$v0,$a0
/*  f1573c4:	50200003 */ 	beqzl	$at,.L0f1573d4
/*  f1573c8:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f1573cc:	00801025 */ 	or	$v0,$a0,$zero
/*  f1573d0:	aca00000 */ 	sw	$zero,0x0($a1)
.L0f1573d4:
/*  f1573d4:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f1573d8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f1573dc:	0311c821 */ 	addu	$t9,$t8,$s1
/*  f1573e0:	10000034 */ 	b	.L0f1574b4
/*  f1573e4:	ae190000 */ 	sw	$t9,0x0($s0)
.L0f1573e8:
/*  f1573e8:	5020001d */ 	beqzl	$at,.L0f157460
/*  f1573ec:	290100c0 */ 	slti	$at,$t0,0xc0
/*  f1573f0:	308800ff */ 	andi	$t0,$a0,0xff
/*  f1573f4:	01120019 */ 	multu	$t0,$s2
/*  f1573f8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f1573fc:	00007012 */ 	mflo	$t6
/*  f157400:	00ee5021 */ 	addu	$t2,$a3,$t6
/*  f157404:	8d4ffe78 */ 	lw	$t7,-0x188($t2)
/*  f157408:	00720019 */ 	multu	$v1,$s2
/*  f15740c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f157410:	0138c821 */ 	addu	$t9,$t1,$t8
/*  f157414:	00007012 */ 	mflo	$t6
/*  f157418:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f15741c:	8df8fe78 */ 	lw	$t8,-0x188($t7)
/*  f157420:	03130019 */ 	multu	$t8,$s3
/*  f157424:	00007012 */ 	mflo	$t6
/*  f157428:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f15742c:	032fc021 */ 	addu	$t8,$t9,$t7
/*  f157430:	8f0e0000 */ 	lw	$t6,0x0($t8)
/*  f157434:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f157438:	9158fe77 */ 	lbu	$t8,-0x189($t2)
/*  f15743c:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f157440:	01d92021 */ 	addu	$a0,$t6,$t9
/*  f157444:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f157448:	01f87021 */ 	addu	$t6,$t7,$t8
/*  f15744c:	01c4c823 */ 	subu	$t9,$t6,$a0
/*  f157450:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f157454:	10000017 */ 	b	.L0f1574b4
/*  f157458:	90c3ffff */ 	lbu	$v1,-0x1($a2)
/*  f15745c:	290100c0 */ 	slti	$at,$t0,0xc0
.L0f157460:
/*  f157460:	5020000c */ 	beqzl	$at,.L0f157494
/*  f157464:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f157468:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f15746c:	8e980000 */ 	lw	$t8,0x0($s4)
/*  f157470:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f157474:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f157478:	01f82021 */ 	addu	$a0,$t7,$t8
/*  f15747c:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f157480:	01c4c823 */ 	subu	$t9,$t6,$a0
/*  f157484:	272f000b */ 	addiu	$t7,$t9,0xb
/*  f157488:	1000000a */ 	b	.L0f1574b4
/*  f15748c:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f157490:	8d380000 */ 	lw	$t8,0x0($t1)
.L0f157494:
/*  f157494:	8e8e0000 */ 	lw	$t6,0x0($s4)
/*  f157498:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f15749c:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f1574a0:	030e2021 */ 	addu	$a0,$t8,$t6
/*  f1574a4:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f1574a8:	03247823 */ 	subu	$t7,$t9,$a0
/*  f1574ac:	25f8000f */ 	addiu	$t8,$t7,0xf
/*  f1574b0:	acb80000 */ 	sw	$t8,0x0($a1)
.L0f1574b4:
/*  f1574b4:	90c40000 */ 	lbu	$a0,0x0($a2)
/*  f1574b8:	1480ffb3 */ 	bnez	$a0,.L0f157388
/*  f1574bc:	00804025 */ 	or	$t0,$a0,$zero
.L0f1574c0:
/*  f1574c0:	3c0e8008 */ 	lui	$t6,%hi(g_ScaleX)
/*  f1574c4:	8dcefac0 */ 	lw	$t6,%lo(g_ScaleX)($t6)
/*  f1574c8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1574cc:	3c0f8008 */ 	lui	$t7,%hi(var8007fad0)
/*  f1574d0:	55c10008 */ 	bnel	$t6,$at,.L0f1574f4
/*  f1574d4:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f1574d8:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f1574dc:	8deffad0 */ 	lw	$t7,%lo(var8007fad0)($t7)
/*  f1574e0:	032f0019 */ 	multu	$t9,$t7
/*  f1574e4:	0000c012 */ 	mflo	$t8
/*  f1574e8:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1574ec:	00000000 */ 	nop
/*  f1574f0:	8cae0000 */ 	lw	$t6,0x0($a1)
.L0f1574f4:
/*  f1574f4:	01c2082a */ 	slt	$at,$t6,$v0
/*  f1574f8:	50200003 */ 	beqzl	$at,.L0f157508
/*  f1574fc:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f157500:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f157504:	8fb00004 */ 	lw	$s0,0x4($sp)
.L0f157508:
/*  f157508:	8fb10008 */ 	lw	$s1,0x8($sp)
/*  f15750c:	8fb2000c */ 	lw	$s2,0xc($sp)
/*  f157510:	8fb30010 */ 	lw	$s3,0x10($sp)
/*  f157514:	8fb40014 */ 	lw	$s4,0x14($sp)
/*  f157518:	03e00008 */ 	jr	$ra
/*  f15751c:	27bd0018 */ 	addiu	$sp,$sp,0x18
);
#endif

// Mismatch: Goal moves textheight to s0 then uses a0 for text[i] and/or
// thischar.
//void textMeasure(s32 *textheight, s32 *textwidth, char *text, struct font2a4 *font1, struct font *font2, s32 lineheight)
//{
//	s32 thischar;
//	s32 prevchar;
//	s32 longest;
//	s32 i;
//	s32 tmp;
//
//	*textheight = 0;
//	prevchar = 'H'; // Just a default - presumably chosen for its flat right edge
//	longest = 0;
//	*textwidth = 0;
//
//	// 324
//	if (lineheight == 0) {
//		lineheight = font1['['].baseline + font1['['].height;
//	}
//
//	// 344
//	// Force minimum height for non-English languages
//	if (g_LanguageId != LANGUAGE_ENGLISH && lineheight < 14) {
//		lineheight = 14;
//	}
//
//	// 358
//	if (text) {
//		thischar = text[0];
//
//		for (i = 0; text[i] != '\0'; ) {
//			// 388
//			if (thischar == ' ') {
//				// Space
//				if (text[i + 1] != '\n') {
//					*textwidth += 5;
//				}
//
//				prevchar = 'H';
//				i++;
//			} else /*3b4*/ if (thischar == '\n') {
//				// Line break
//				if (*textwidth > longest) {
//					longest = *textwidth;
//				}
//
//				*textwidth = 0;
//				*textheight += lineheight;
//				i++;
//			} else /*3e8*/ {
//				if (thischar < 0x80) {
//					// Normal single-byte character
//					u8 character = thischar;
//					s32 b = font1[character - 0x21].unk04;
//					s32 a = font1[prevchar - 0x21].unk04;
//
//					tmp = font2->unk000[b + a * 13] + var8007fac4 - 1;
//					tmp = font1[character - 0x21].width + tmp;
//
//					*textwidth = *textwidth - tmp;
//
//					prevchar = text[i];
//					i++;
//				} else /*460*/ if (thischar < 0xc0) {
//					// Multi-byte character
//					tmp = font2->unk000[0] + var8007fac4 - 1;
//					*textwidth = *textwidth - tmp + 11;
//					i += 2;
//				} else {
//					// Multi-byte character
//					// 494
//					tmp = font2->unk000[0] + var8007fac4 - 1;
//					*textwidth = *textwidth - tmp + 15;
//					i += 2;
//				}
//
//				if (textheight);
//			}
//
//			thischar = text[i];
//		}
//	}
//
//	if (g_ScaleX == 1) {
//		*textwidth *= var8007fad0;
//	}
//
//	// @bug? Shouldn't this go before the scale check?
//	if (*textwidth < longest) {
//		*textwidth = longest;
//	}
//}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel textWrap
/*  f15848c:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f158490:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f158494:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f158498:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f15849c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1584a0:	00c08025 */ 	move	$s0,$a2
/*  f1584a4:	00a09025 */ 	move	$s2,$a1
/*  f1584a8:	00e09825 */ 	move	$s3,$a3
/*  f1584ac:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f1584b0:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f1584b4:	afa40088 */ 	sw	$a0,0x88($sp)
/*  f1584b8:	00005825 */ 	move	$t3,$zero
/*  f1584bc:	afa00074 */ 	sw	$zero,0x74($sp)
/*  f1584c0:	240d0001 */ 	li	$t5,0x1
/*  f1584c4:	27b40044 */ 	addiu	$s4,$sp,0x44
/*  f1584c8:	240a000c */ 	li	$t2,0xc
.PF0f1584cc:
/*  f1584cc:	afa00078 */ 	sw	$zero,0x78($sp)
/*  f1584d0:	92430000 */ 	lbu	$v1,0x0($s2)
/*  f1584d4:	00008825 */ 	move	$s1,$zero
/*  f1584d8:	00002025 */ 	move	$a0,$zero
/*  f1584dc:	28610021 */ 	slti	$at,$v1,0x21
/*  f1584e0:	14200022 */ 	bnez	$at,.PF0f15856c
/*  f1584e4:	02803025 */ 	move	$a2,$s4
/*  f1584e8:	3c058008 */ 	lui	$a1,0x8008
/*  f1584ec:	8ca54660 */ 	lw	$a1,0x4660($a1)
/*  f1584f0:	27a20044 */ 	addiu	$v0,$sp,0x44
/*  f1584f4:	a0430000 */ 	sb	$v1,0x0($v0)
.PF0f1584f8:
/*  f1584f8:	924e0000 */ 	lbu	$t6,0x0($s2)
/*  f1584fc:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f158500:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f158504:	01ca0019 */ 	multu	$t6,$t2
/*  f158508:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f15850c:	00007812 */ 	mflo	$t7
/*  f158510:	026fc021 */ 	addu	$t8,$s3,$t7
/*  f158514:	9319fe77 */ 	lbu	$t9,-0x189($t8)
/*  f158518:	10a00010 */ 	beqz	$a1,.PF0f15855c
/*  f15851c:	00992021 */ 	addu	$a0,$a0,$t9
/*  f158520:	904effff */ 	lbu	$t6,-0x1($v0)
/*  f158524:	29c10080 */ 	slti	$at,$t6,0x80
/*  f158528:	5420000d */ 	bnezl	$at,.PF0f158560
/*  f15852c:	92430000 */ 	lbu	$v1,0x0($s2)
/*  f158530:	924f0000 */ 	lbu	$t7,0x0($s2)
/*  f158534:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f158538:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f15853c:	a04f0000 */ 	sb	$t7,0x0($v0)
/*  f158540:	9258ffff */ 	lbu	$t8,-0x1($s2)
/*  f158544:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f158548:	030a0019 */ 	multu	$t8,$t2
/*  f15854c:	0000c812 */ 	mflo	$t9
/*  f158550:	02797021 */ 	addu	$t6,$s3,$t9
/*  f158554:	91cffe77 */ 	lbu	$t7,-0x189($t6)
/*  f158558:	008f2021 */ 	addu	$a0,$a0,$t7
.PF0f15855c:
/*  f15855c:	92430000 */ 	lbu	$v1,0x0($s2)
.PF0f158560:
/*  f158560:	28610021 */ 	slti	$at,$v1,0x21
/*  f158564:	5020ffe4 */ 	beqzl	$at,.PF0f1584f8
/*  f158568:	a0430000 */ 	sb	$v1,0x0($v0)
.PF0f15856c:
/*  f15856c:	0291c021 */ 	addu	$t8,$s4,$s1
/*  f158570:	a3000000 */ 	sb	$zero,0x0($t8)
/*  f158574:	8fb90098 */ 	lw	$t9,0x98($sp)
/*  f158578:	afad0070 */ 	sw	$t5,0x70($sp)
/*  f15857c:	afab0084 */ 	sw	$t3,0x84($sp)
/*  f158580:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f158584:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f158588:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f15858c:	02603825 */ 	move	$a3,$s3
/*  f158590:	0fc5609a */ 	jal	0xf158268
/*  f158594:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f158598:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f15859c:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f1585a0:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f1585a4:	3c088008 */ 	lui	$t0,0x8008
/*  f1585a8:	016e5821 */ 	addu	$t3,$t3,$t6
/*  f1585ac:	01eb082a */ 	slt	$at,$t7,$t3
/*  f1585b0:	2508002c */ 	addiu	$t0,$t0,0x2c
/*  f1585b4:	24090020 */ 	li	$t1,0x20
/*  f1585b8:	240a000c */ 	li	$t2,0xc
/*  f1585bc:	240c000a */ 	li	$t4,0xa
/*  f1585c0:	14200003 */ 	bnez	$at,.PF0f1585d0
/*  f1585c4:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f1585c8:	10000002 */ 	b	.PF0f1585d4
/*  f1585cc:	24040001 */ 	li	$a0,0x1
.PF0f1585d0:
/*  f1585d0:	00002025 */ 	move	$a0,$zero
.PF0f1585d4:
/*  f1585d4:	92420000 */ 	lbu	$v0,0x0($s2)
/*  f1585d8:	2401000a */ 	li	$at,0xa
/*  f1585dc:	5441001d */ 	bnel	$v0,$at,.PF0f158654
/*  f1585e0:	24010020 */ 	li	$at,0x20
/*  f1585e4:	1480000e */ 	bnez	$a0,.PF0f158620
/*  f1585e8:	00001825 */ 	move	$v1,$zero
/*  f1585ec:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f1585f0:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f1585f4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1585f8:	1b000009 */ 	blez	$t8,.PF0f158620
/*  f1585fc:	00000000 */ 	nop
/*  f158600:	a2090000 */ 	sb	$t1,0x0($s0)
.PF0f158604:
/*  f158604:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f158608:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f15860c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f158610:	0079082a */ 	slt	$at,$v1,$t9
/*  f158614:	5420fffb */ 	bnezl	$at,.PF0f158604
/*  f158618:	a2090000 */ 	sb	$t1,0x0($s0)
/*  f15861c:	00001825 */ 	move	$v1,$zero
.PF0f158620:
/*  f158620:	1a200008 */ 	blez	$s1,.PF0f158644
/*  f158624:	00005825 */ 	move	$t3,$zero
/*  f158628:	27a20044 */ 	addiu	$v0,$sp,0x44
.PF0f15862c:
/*  f15862c:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f158630:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f158634:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f158638:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15863c:	1471fffb */ 	bne	$v1,$s1,.PF0f15862c
/*  f158640:	a20effff */ 	sb	$t6,-0x1($s0)
.PF0f158644:
/*  f158644:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f158648:	1000003d */ 	b	.PF0f158740
/*  f15864c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f158650:	24010020 */ 	li	$at,0x20
.PF0f158654:
/*  f158654:	14410020 */ 	bne	$v0,$at,.PF0f1586d8
/*  f158658:	00000000 */ 	nop
/*  f15865c:	14800012 */ 	bnez	$a0,.PF0f1586a8
/*  f158660:	00001825 */ 	move	$v1,$zero
/*  f158664:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f158668:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f15866c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f158670:	5840000a */ 	blezl	$v0,.PF0f15869c
/*  f158674:	8fb80078 */ 	lw	$t8,0x78($sp)
/*  f158678:	a2090000 */ 	sb	$t1,0x0($s0)
.PF0f15867c:
/*  f15867c:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f158680:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f158684:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f158688:	0062082a */ 	slt	$at,$v1,$v0
/*  f15868c:	5420fffb */ 	bnezl	$at,.PF0f15867c
/*  f158690:	a2090000 */ 	sb	$t1,0x0($s0)
/*  f158694:	00001825 */ 	move	$v1,$zero
/*  f158698:	8fb80078 */ 	lw	$t8,0x78($sp)
.PF0f15869c:
/*  f15869c:	00027880 */ 	sll	$t7,$v0,0x2
/*  f1586a0:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f1586a4:	01f85821 */ 	addu	$t3,$t7,$t8
.PF0f1586a8:
/*  f1586a8:	1a200008 */ 	blez	$s1,.PF0f1586cc
/*  f1586ac:	256b0005 */ 	addiu	$t3,$t3,0x5
/*  f1586b0:	27a20044 */ 	addiu	$v0,$sp,0x44
.PF0f1586b4:
/*  f1586b4:	90590000 */ 	lbu	$t9,0x0($v0)
/*  f1586b8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1586bc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1586c0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1586c4:	1471fffb */ 	bne	$v1,$s1,.PF0f1586b4
/*  f1586c8:	a219ffff */ 	sb	$t9,-0x1($s0)
.PF0f1586cc:
/*  f1586cc:	a2090000 */ 	sb	$t1,0x0($s0)
/*  f1586d0:	1000001b */ 	b	.PF0f158740
/*  f1586d4:	26100001 */ 	addiu	$s0,$s0,0x1
.PF0f1586d8:
/*  f1586d8:	14400019 */ 	bnez	$v0,.PF0f158740
/*  f1586dc:	00001825 */ 	move	$v1,$zero
/*  f1586e0:	1480000e */ 	bnez	$a0,.PF0f15871c
/*  f1586e4:	00006825 */ 	move	$t5,$zero
/*  f1586e8:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f1586ec:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f1586f0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1586f4:	19c00009 */ 	blez	$t6,.PF0f15871c
/*  f1586f8:	00000000 */ 	nop
/*  f1586fc:	a2090000 */ 	sb	$t1,0x0($s0)
.PF0f158700:
/*  f158700:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f158704:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f158708:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15870c:	006f082a */ 	slt	$at,$v1,$t7
/*  f158710:	5420fffb */ 	bnezl	$at,.PF0f158700
/*  f158714:	a2090000 */ 	sb	$t1,0x0($s0)
/*  f158718:	00001825 */ 	move	$v1,$zero
.PF0f15871c:
/*  f15871c:	1a200007 */ 	blez	$s1,.PF0f15873c
/*  f158720:	27a20044 */ 	addiu	$v0,$sp,0x44
.PF0f158724:
/*  f158724:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f158728:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f15872c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f158730:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f158734:	1471fffb */ 	bne	$v1,$s1,.PF0f158724
/*  f158738:	a218ffff */ 	sb	$t8,-0x1($s0)
.PF0f15873c:
/*  f15873c:	a2000000 */ 	sb	$zero,0x0($s0)
.PF0f158740:
/*  f158740:	24010001 */ 	li	$at,0x1
/*  f158744:	11a1ff61 */ 	beq	$t5,$at,.PF0f1584cc
/*  f158748:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f15874c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f158750:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f158754:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f158758:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f15875c:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f158760:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f158764:	03e00008 */ 	jr	$ra
/*  f158768:	27bd0088 */ 	addiu	$sp,$sp,0x88
);
#else
GLOBAL_ASM(
glabel textWrap
/*  f157520:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f157524:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f157528:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f15752c:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f157530:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f157534:	00c08025 */ 	or	$s0,$a2,$zero
/*  f157538:	00a09025 */ 	or	$s2,$a1,$zero
/*  f15753c:	00e09825 */ 	or	$s3,$a3,$zero
/*  f157540:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f157544:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f157548:	afa40088 */ 	sw	$a0,0x88($sp)
/*  f15754c:	00005825 */ 	or	$t3,$zero,$zero
/*  f157550:	afa00074 */ 	sw	$zero,0x74($sp)
/*  f157554:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f157558:	27b40044 */ 	addiu	$s4,$sp,0x44
/*  f15755c:	240a000c */ 	addiu	$t2,$zero,0xc
.L0f157560:
/*  f157560:	afa00078 */ 	sw	$zero,0x78($sp)
/*  f157564:	92440000 */ 	lbu	$a0,0x0($s2)
/*  f157568:	00008825 */ 	or	$s1,$zero,$zero
/*  f15756c:	00001825 */ 	or	$v1,$zero,$zero
/*  f157570:	28810021 */ 	slti	$at,$a0,0x21
/*  f157574:	1420001e */ 	bnez	$at,.L0f1575f0
/*  f157578:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f15757c:	27a20044 */ 	addiu	$v0,$sp,0x44
/*  f157580:	a0440000 */ 	sb	$a0,0x0($v0)
.L0f157584:
/*  f157584:	924e0000 */ 	lbu	$t6,0x0($s2)
/*  f157588:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f15758c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f157590:	01ca0019 */ 	multu	$t6,$t2
/*  f157594:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f157598:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f15759c:	29c10080 */ 	slti	$at,$t6,0x80
/*  f1575a0:	00007812 */ 	mflo	$t7
/*  f1575a4:	026fc021 */ 	addu	$t8,$s3,$t7
/*  f1575a8:	9319fe77 */ 	lbu	$t9,-0x189($t8)
/*  f1575ac:	1420000c */ 	bnez	$at,.L0f1575e0
/*  f1575b0:	00791821 */ 	addu	$v1,$v1,$t9
/*  f1575b4:	924f0000 */ 	lbu	$t7,0x0($s2)
/*  f1575b8:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1575bc:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1575c0:	a04f0000 */ 	sb	$t7,0x0($v0)
/*  f1575c4:	9258ffff */ 	lbu	$t8,-0x1($s2)
/*  f1575c8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1575cc:	030a0019 */ 	multu	$t8,$t2
/*  f1575d0:	0000c812 */ 	mflo	$t9
/*  f1575d4:	02797021 */ 	addu	$t6,$s3,$t9
/*  f1575d8:	91cffe77 */ 	lbu	$t7,-0x189($t6)
/*  f1575dc:	006f1821 */ 	addu	$v1,$v1,$t7
.L0f1575e0:
/*  f1575e0:	92440000 */ 	lbu	$a0,0x0($s2)
/*  f1575e4:	28810021 */ 	slti	$at,$a0,0x21
/*  f1575e8:	5020ffe6 */ 	beqzl	$at,.L0f157584
/*  f1575ec:	a0440000 */ 	sb	$a0,0x0($v0)
.L0f1575f0:
/*  f1575f0:	0291c021 */ 	addu	$t8,$s4,$s1
/*  f1575f4:	a3000000 */ 	sb	$zero,0x0($t8)
/*  f1575f8:	8fb90098 */ 	lw	$t9,0x98($sp)
/*  f1575fc:	afad0070 */ 	sw	$t5,0x70($sp)
/*  f157600:	afab0084 */ 	sw	$t3,0x84($sp)
/*  f157604:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f157608:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f15760c:	02803025 */ 	or	$a2,$s4,$zero
/*  f157610:	02603825 */ 	or	$a3,$s3,$zero
/*  f157614:	0fc55cbe */ 	jal	textMeasure
/*  f157618:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f15761c:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f157620:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f157624:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f157628:	3c088008 */ 	lui	$t0,%hi(var8007facc)
/*  f15762c:	016e5821 */ 	addu	$t3,$t3,$t6
/*  f157630:	01eb082a */ 	slt	$at,$t7,$t3
/*  f157634:	2508facc */ 	addiu	$t0,$t0,%lo(var8007facc)
/*  f157638:	24090020 */ 	addiu	$t1,$zero,0x20
/*  f15763c:	240a000c */ 	addiu	$t2,$zero,0xc
/*  f157640:	240c000a */ 	addiu	$t4,$zero,0xa
/*  f157644:	14200003 */ 	bnez	$at,.L0f157654
/*  f157648:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f15764c:	10000002 */ 	b	.L0f157658
/*  f157650:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f157654:
/*  f157654:	00002025 */ 	or	$a0,$zero,$zero
.L0f157658:
/*  f157658:	92420000 */ 	lbu	$v0,0x0($s2)
/*  f15765c:	2401000a */ 	addiu	$at,$zero,0xa
/*  f157660:	5441001d */ 	bnel	$v0,$at,.L0f1576d8
/*  f157664:	24010020 */ 	addiu	$at,$zero,0x20
/*  f157668:	1480000e */ 	bnez	$a0,.L0f1576a4
/*  f15766c:	00001825 */ 	or	$v1,$zero,$zero
/*  f157670:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f157674:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f157678:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15767c:	1b000009 */ 	blez	$t8,.L0f1576a4
/*  f157680:	00000000 */ 	nop
/*  f157684:	a2090000 */ 	sb	$t1,0x0($s0)
.L0f157688:
/*  f157688:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f15768c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f157690:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f157694:	0079082a */ 	slt	$at,$v1,$t9
/*  f157698:	5420fffb */ 	bnezl	$at,.L0f157688
/*  f15769c:	a2090000 */ 	sb	$t1,0x0($s0)
/*  f1576a0:	00001825 */ 	or	$v1,$zero,$zero
.L0f1576a4:
/*  f1576a4:	1a200008 */ 	blez	$s1,.L0f1576c8
/*  f1576a8:	00005825 */ 	or	$t3,$zero,$zero
/*  f1576ac:	27a20044 */ 	addiu	$v0,$sp,0x44
.L0f1576b0:
/*  f1576b0:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f1576b4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1576b8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1576bc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1576c0:	1471fffb */ 	bne	$v1,$s1,.L0f1576b0
/*  f1576c4:	a20effff */ 	sb	$t6,-0x1($s0)
.L0f1576c8:
/*  f1576c8:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f1576cc:	1000003d */ 	b	.L0f1577c4
/*  f1576d0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1576d4:	24010020 */ 	addiu	$at,$zero,0x20
.L0f1576d8:
/*  f1576d8:	14410020 */ 	bne	$v0,$at,.L0f15775c
/*  f1576dc:	00000000 */ 	nop
/*  f1576e0:	14800012 */ 	bnez	$a0,.L0f15772c
/*  f1576e4:	00001825 */ 	or	$v1,$zero,$zero
/*  f1576e8:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f1576ec:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f1576f0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1576f4:	5840000a */ 	blezl	$v0,.L0f157720
/*  f1576f8:	8fb80078 */ 	lw	$t8,0x78($sp)
/*  f1576fc:	a2090000 */ 	sb	$t1,0x0($s0)
.L0f157700:
/*  f157700:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f157704:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f157708:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15770c:	0062082a */ 	slt	$at,$v1,$v0
/*  f157710:	5420fffb */ 	bnezl	$at,.L0f157700
/*  f157714:	a2090000 */ 	sb	$t1,0x0($s0)
/*  f157718:	00001825 */ 	or	$v1,$zero,$zero
/*  f15771c:	8fb80078 */ 	lw	$t8,0x78($sp)
.L0f157720:
/*  f157720:	00027880 */ 	sll	$t7,$v0,0x2
/*  f157724:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f157728:	01f85821 */ 	addu	$t3,$t7,$t8
.L0f15772c:
/*  f15772c:	1a200008 */ 	blez	$s1,.L0f157750
/*  f157730:	256b0005 */ 	addiu	$t3,$t3,0x5
/*  f157734:	27a20044 */ 	addiu	$v0,$sp,0x44
.L0f157738:
/*  f157738:	90590000 */ 	lbu	$t9,0x0($v0)
/*  f15773c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f157740:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f157744:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f157748:	1471fffb */ 	bne	$v1,$s1,.L0f157738
/*  f15774c:	a219ffff */ 	sb	$t9,-0x1($s0)
.L0f157750:
/*  f157750:	a2090000 */ 	sb	$t1,0x0($s0)
/*  f157754:	1000001b */ 	b	.L0f1577c4
/*  f157758:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f15775c:
/*  f15775c:	14400019 */ 	bnez	$v0,.L0f1577c4
/*  f157760:	00001825 */ 	or	$v1,$zero,$zero
/*  f157764:	1480000e */ 	bnez	$a0,.L0f1577a0
/*  f157768:	00006825 */ 	or	$t5,$zero,$zero
/*  f15776c:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f157770:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f157774:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f157778:	19c00009 */ 	blez	$t6,.L0f1577a0
/*  f15777c:	00000000 */ 	nop
/*  f157780:	a2090000 */ 	sb	$t1,0x0($s0)
.L0f157784:
/*  f157784:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f157788:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f15778c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f157790:	006f082a */ 	slt	$at,$v1,$t7
/*  f157794:	5420fffb */ 	bnezl	$at,.L0f157784
/*  f157798:	a2090000 */ 	sb	$t1,0x0($s0)
/*  f15779c:	00001825 */ 	or	$v1,$zero,$zero
.L0f1577a0:
/*  f1577a0:	1a200007 */ 	blez	$s1,.L0f1577c0
/*  f1577a4:	27a20044 */ 	addiu	$v0,$sp,0x44
.L0f1577a8:
/*  f1577a8:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f1577ac:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1577b0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1577b4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1577b8:	1471fffb */ 	bne	$v1,$s1,.L0f1577a8
/*  f1577bc:	a218ffff */ 	sb	$t8,-0x1($s0)
.L0f1577c0:
/*  f1577c0:	a2000000 */ 	sb	$zero,0x0($s0)
.L0f1577c4:
/*  f1577c4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1577c8:	11a1ff65 */ 	beq	$t5,$at,.L0f157560
/*  f1577cc:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1577d0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1577d4:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f1577d8:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f1577dc:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f1577e0:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f1577e4:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f1577e8:	03e00008 */ 	jr	$ra
/*  f1577ec:	27bd0088 */ 	addiu	$sp,$sp,0x88
);
#endif
