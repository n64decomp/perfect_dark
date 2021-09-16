#include <ultra64.h>
#include "constants.h"
#include "game/dlights.h"
#include "game/game_006900.h"
#include "game/atan2f.h"
#include "game/savebuffer.h"
#include "game/game_11f000.h"
#include "game/bondview.h"
#include "game/game_1531a0.h"
#include "game/gfxmemory.h"
#include "game/lang.h"
#include "game/options.h"
#include "bss.h"
#include "lib/lib_09a80.h"
#include "lib/main.h"
#include "lib/rng.h"
#include "lib/lib_16110.h"
#include "data.h"
#include "types.h"
#include "gbiex.h"

char var800a41c0[990];

s32 var8007f840 = 0x00000000;
u8 var8007f844 = 0;
u8 var8007f848 = 0;
u32 g_IrBinocularRadius = PAL ? 102 : 90;
u32 var8007f850 = 0x00000003;
u32 var8007f854 = 0x00000000;
u32 var8007f858 = 0xb8000000;
u32 var8007f85c = 0x00000000;

#if VERSION < VERSION_NTSC_1_0
const char var7f1b02b0nb[] = "fsrad";
const char var7f1b02b8nb[] = "fscs";

GLOBAL_ASM(
glabel func7f13c2d0nb
/*  f13c2d0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f13c2d4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f13c2d8:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f13c2dc:	3c058008 */ 	lui	$a1,0x8008
/*  f13c2e0:	24a520ac */ 	addiu	$a1,$a1,0x20ac
/*  f13c2e4:	0c00381c */ 	jal	func0000db30
/*  f13c2e8:	248402b0 */ 	addiu	$a0,$a0,0x2b0
/*  f13c2ec:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f13c2f0:	3c058008 */ 	lui	$a1,0x8008
/*  f13c2f4:	24a520b0 */ 	addiu	$a1,$a1,0x20b0
/*  f13c2f8:	0c00381c */ 	jal	func0000db30
/*  f13c2fc:	248402b8 */ 	addiu	$a0,$a0,0x2b8
/*  f13c300:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f13c304:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f13c308:	03e00008 */ 	jr	$ra
/*  f13c30c:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

Gfx *bviewRenderIrRect(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2)
{
	gDPFillRectangle(gdl++, x1, y1, x2, y2);

	return gdl;
}

Gfx *func0f141864(Gfx *gdl, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
	s32 value = viGetWidth() * arg2 + arg4;

	gDPPipeSync(gdl++);
	gDPSetTextureImage(gdl++, G_IM_FMT_I, G_IM_SIZ_8b, 320, value * 2 + arg1);
	gDPLoadSync(gdl++);
	gDPLoadBlock(gdl++, arg3, 0, 0, arg5 - 1, 0);

	return gdl;
}

Gfx *func0f141940(Gfx *gdl, s32 arg1, s32 arg2, s32 tile, s32 arg4, s32 width)
{
	s32 value = viGetWidth() * arg2 + arg4;

	gDPPipeSync(gdl++);
	gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, value * 2 + arg1);
	gDPLoadSync(gdl++);
	gDPLoadBlock(gdl++, tile, 0, 0, width - 1, 0);

	return gdl;
}

Gfx *func0f141a20(Gfx *gdl, u32 a, u32 b, u32 c, u32 d)
{
	gDPPipeSync(gdl++);

	gSPTextureRectangle(gdl++,
			c << 2,
			a << 2,
			(c + d) << 2,
			(a + 1) << 2,
			G_TX_RENDERTILE, 0, 0, b << 10, 0x0400);

	return gdl;
}

GLOBAL_ASM(
glabel bviewRenderLensRect
/*  f141ab0:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f141ab4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f141ab8:	8fb0009c */ 	lw	$s0,0x9c($sp)
/*  f141abc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f141ac0:	afa50084 */ 	sw	$a1,0x84($sp)
/*  f141ac4:	2a010141 */ 	slti	$at,$s0,0x141
/*  f141ac8:	afa60088 */ 	sw	$a2,0x88($sp)
/*  f141acc:	142000a5 */ 	bnez	$at,.L0f141d64
/*  f141ad0:	afa7008c */ 	sw	$a3,0x8c($sp)
/*  f141ad4:	06010003 */ 	bgez	$s0,.L0f141ae4
/*  f141ad8:	00103043 */ 	sra	$a2,$s0,0x1
/*  f141adc:	26010001 */ 	addiu	$at,$s0,0x1
/*  f141ae0:	00013043 */ 	sra	$a2,$at,0x1
.L0f141ae4:
/*  f141ae4:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f141ae8:	afa6002c */ 	sw	$a2,0x2c($sp)
/*  f141aec:	0c002f02 */ 	jal	viGetWidth
/*  f141af0:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f141af4:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f141af8:	3c0efd10 */ 	lui	$t6,0xfd10
/*  f141afc:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f141b00:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f141b04:	35ce013f */ 	ori	$t6,$t6,0x13f
/*  f141b08:	00801825 */ 	or	$v1,$a0,$zero
/*  f141b0c:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f141b10:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f141b14:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f141b18:	3c0100ff */ 	lui	$at,0xff
/*  f141b1c:	004f0019 */ 	multu	$v0,$t7
/*  f141b20:	3421ffff */ 	ori	$at,$at,0xffff
/*  f141b24:	44902000 */ 	mtc1	$s0,$f4
/*  f141b28:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141b2c:	24c5ffff */ 	addiu	$a1,$a2,-1
/*  f141b30:	00804025 */ 	or	$t0,$a0,$zero
/*  f141b34:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141b38:	240207ff */ 	addiu	$v0,$zero,0x7ff
/*  f141b3c:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f141b40:	0000c012 */ 	mflo	$t8
/*  f141b44:	0307c821 */ 	addu	$t9,$t8,$a3
/*  f141b48:	00196840 */ 	sll	$t5,$t9,0x1
/*  f141b4c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f141b50:	01e1c024 */ 	and	$t8,$t7,$at
/*  f141b54:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f141b58:	28a107ff */ 	slti	$at,$a1,0x7ff
/*  f141b5c:	3c19f300 */ 	lui	$t9,0xf300
/*  f141b60:	10200003 */ 	beqz	$at,.L0f141b70
/*  f141b64:	ad190000 */ 	sw	$t9,0x0($t0)
/*  f141b68:	10000001 */ 	b	.L0f141b70
/*  f141b6c:	00a01025 */ 	or	$v0,$a1,$zero
.L0f141b70:
/*  f141b70:	c7a20094 */ 	lwc1	$f2,0x94($sp)
/*  f141b74:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f141b78:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f141b7c:	46020183 */ 	div.s	$f6,$f0,$f2
/*  f141b80:	304f0fff */ 	andi	$t7,$v0,0xfff
/*  f141b84:	312d0007 */ 	andi	$t5,$t1,0x7
/*  f141b88:	000d4e00 */ 	sll	$t1,$t5,0x18
/*  f141b8c:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f141b90:	0309c825 */ 	or	$t9,$t8,$t1
/*  f141b94:	00e67821 */ 	addu	$t7,$a3,$a2
/*  f141b98:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f141b9c:	ad190004 */ 	sw	$t9,0x4($t0)
/*  f141ba0:	000b6880 */ 	sll	$t5,$t3,0x2
/*  f141ba4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f141ba8:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f141bac:	31ab0fff */ 	andi	$t3,$t5,0xfff
/*  f141bb0:	00196b00 */ 	sll	$t5,$t9,0xc
/*  f141bb4:	3c01e400 */ 	lui	$at,0xe400
/*  f141bb8:	01a17025 */ 	or	$t6,$t5,$at
/*  f141bbc:	3c014180 */ 	lui	$at,0x4180
/*  f141bc0:	44815000 */ 	mtc1	$at,$f10
/*  f141bc4:	3c014480 */ 	lui	$at,0x4480
/*  f141bc8:	44812000 */ 	mtc1	$at,$f4
/*  f141bcc:	01cb7825 */ 	or	$t7,$t6,$t3
/*  f141bd0:	0007c880 */ 	sll	$t9,$a3,0x2
/*  f141bd4:	332d0fff */ 	andi	$t5,$t9,0xfff
/*  f141bd8:	46060201 */ 	sub.s	$f8,$f0,$f6
/*  f141bdc:	00801825 */ 	or	$v1,$a0,$zero
/*  f141be0:	000a6080 */ 	sll	$t4,$t2,0x2
/*  f141be4:	46022183 */ 	div.s	$f6,$f4,$f2
/*  f141be8:	31980fff */ 	andi	$t8,$t4,0xfff
/*  f141bec:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f141bf0:	000d7300 */ 	sll	$t6,$t5,0xc
/*  f141bf4:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f141bf8:	01d87825 */ 	or	$t7,$t6,$t8
/*  f141bfc:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f141c00:	03006025 */ 	or	$t4,$t8,$zero
/*  f141c04:	24850008 */ 	addiu	$a1,$a0,0x8
/*  f141c08:	3c18b400 */ 	lui	$t8,0xb400
/*  f141c0c:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f141c10:	24a20008 */ 	addiu	$v0,$a1,0x8
/*  f141c14:	3c18b300 */ 	lui	$t8,0xb300
/*  f141c18:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f141c1c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f141c20:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f141c24:	440e9000 */ 	mfc1	$t6,$f18
/*  f141c28:	440d4000 */ 	mfc1	$t5,$f8
/*  f141c2c:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f141c30:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f141c34:	000d7400 */ 	sll	$t6,$t5,0x10
/*  f141c38:	35d00400 */ 	ori	$s0,$t6,0x400
/*  f141c3c:	ac500004 */ 	sw	$s0,0x4($v0)
/*  f141c40:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f141c44:	8fb80070 */ 	lw	$t8,0x70($sp)
/*  f141c48:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f141c4c:	afab0024 */ 	sw	$t3,0x24($sp)
/*  f141c50:	00f83821 */ 	addu	$a3,$a3,$t8
/*  f141c54:	afa70098 */ 	sw	$a3,0x98($sp)
/*  f141c58:	afa90028 */ 	sw	$t1,0x28($sp)
/*  f141c5c:	0c002f02 */ 	jal	viGetWidth
/*  f141c60:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f141c64:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f141c68:	3c19fd10 */ 	lui	$t9,0xfd10
/*  f141c6c:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f141c70:	8fa90028 */ 	lw	$t1,0x28($sp)
/*  f141c74:	8fab0024 */ 	lw	$t3,0x24($sp)
/*  f141c78:	8fac0020 */ 	lw	$t4,0x20($sp)
/*  f141c7c:	3739013f */ 	ori	$t9,$t9,0x13f
/*  f141c80:	00801825 */ 	or	$v1,$a0,$zero
/*  f141c84:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f141c88:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f141c8c:	8fb90084 */ 	lw	$t9,0x84($sp)
/*  f141c90:	3c0100ff */ 	lui	$at,0xff
/*  f141c94:	004d0019 */ 	multu	$v0,$t5
/*  f141c98:	3421ffff */ 	ori	$at,$at,0xffff
/*  f141c9c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141ca0:	00804025 */ 	or	$t0,$a0,$zero
/*  f141ca4:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141ca8:	240207ff */ 	addiu	$v0,$zero,0x7ff
/*  f141cac:	00007012 */ 	mflo	$t6
/*  f141cb0:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f141cb4:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f141cb8:	03196821 */ 	addu	$t5,$t8,$t9
/*  f141cbc:	01a17024 */ 	and	$t6,$t5,$at
/*  f141cc0:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f141cc4:	3c0ff300 */ 	lui	$t7,0xf300
/*  f141cc8:	ad0f0000 */ 	sw	$t7,0x0($t0)
/*  f141ccc:	8fa50070 */ 	lw	$a1,0x70($sp)
/*  f141cd0:	00801825 */ 	or	$v1,$a0,$zero
/*  f141cd4:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141cd8:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f141cdc:	28a107ff */ 	slti	$at,$a1,0x7ff
/*  f141ce0:	10200003 */ 	beqz	$at,.L0f141cf0
/*  f141ce4:	00000000 */ 	nop
/*  f141ce8:	10000001 */ 	b	.L0f141cf0
/*  f141cec:	00a01025 */ 	or	$v0,$a1,$zero
.L0f141cf0:
/*  f141cf0:	30580fff */ 	andi	$t8,$v0,0xfff
/*  f141cf4:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f141cf8:	03296825 */ 	or	$t5,$t9,$t1
/*  f141cfc:	ad0d0004 */ 	sw	$t5,0x4($t0)
/*  f141d00:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f141d04:	3c01e400 */ 	lui	$at,0xe400
/*  f141d08:	00802825 */ 	or	$a1,$a0,$zero
/*  f141d0c:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f141d10:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f141d14:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f141d18:	00196b00 */ 	sll	$t5,$t9,0xc
/*  f141d1c:	01a17025 */ 	or	$t6,$t5,$at
/*  f141d20:	0007c080 */ 	sll	$t8,$a3,0x2
/*  f141d24:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f141d28:	01cb7825 */ 	or	$t7,$t6,$t3
/*  f141d2c:	00196b00 */ 	sll	$t5,$t9,0xc
/*  f141d30:	01ac7025 */ 	or	$t6,$t5,$t4
/*  f141d34:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f141d38:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f141d3c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141d40:	00803025 */ 	or	$a2,$a0,$zero
/*  f141d44:	3c0fb400 */ 	lui	$t7,0xb400
/*  f141d48:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f141d4c:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f141d50:	3c18b300 */ 	lui	$t8,0xb300
/*  f141d54:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f141d58:	acd00004 */ 	sw	$s0,0x4($a2)
/*  f141d5c:	10000058 */ 	b	.L0f141ec0
/*  f141d60:	24840008 */ 	addiu	$a0,$a0,0x8
.L0f141d64:
/*  f141d64:	0c002f02 */ 	jal	viGetWidth
/*  f141d68:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f141d6c:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f141d70:	3c19fd10 */ 	lui	$t9,0xfd10
/*  f141d74:	8fa70098 */ 	lw	$a3,0x98($sp)
/*  f141d78:	3739013f */ 	ori	$t9,$t9,0x13f
/*  f141d7c:	00801825 */ 	or	$v1,$a0,$zero
/*  f141d80:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f141d84:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f141d88:	8fb90084 */ 	lw	$t9,0x84($sp)
/*  f141d8c:	3c0100ff */ 	lui	$at,0xff
/*  f141d90:	004d0019 */ 	multu	$v0,$t5
/*  f141d94:	3421ffff */ 	ori	$at,$at,0xffff
/*  f141d98:	44905000 */ 	mtc1	$s0,$f10
/*  f141d9c:	2605ffff */ 	addiu	$a1,$s0,-1
/*  f141da0:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141da4:	00803025 */ 	or	$a2,$a0,$zero
/*  f141da8:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141dac:	240207ff */ 	addiu	$v0,$zero,0x7ff
/*  f141db0:	46805020 */ 	cvt.s.w	$f0,$f10
/*  f141db4:	00007012 */ 	mflo	$t6
/*  f141db8:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f141dbc:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f141dc0:	03196821 */ 	addu	$t5,$t8,$t9
/*  f141dc4:	01a17024 */ 	and	$t6,$t5,$at
/*  f141dc8:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f141dcc:	28a107ff */ 	slti	$at,$a1,0x7ff
/*  f141dd0:	3c0ff300 */ 	lui	$t7,0xf300
/*  f141dd4:	10200003 */ 	beqz	$at,.L0f141de4
/*  f141dd8:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f141ddc:	10000001 */ 	b	.L0f141de4
/*  f141de0:	00a01025 */ 	or	$v0,$a1,$zero
.L0f141de4:
/*  f141de4:	c7a20094 */ 	lwc1	$f2,0x94($sp)
/*  f141de8:	8fad008c */ 	lw	$t5,0x8c($sp)
/*  f141dec:	30580fff */ 	andi	$t8,$v0,0xfff
/*  f141df0:	46020403 */ 	div.s	$f16,$f0,$f2
/*  f141df4:	31ae0007 */ 	andi	$t6,$t5,0x7
/*  f141df8:	000e7e00 */ 	sll	$t7,$t6,0x18
/*  f141dfc:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f141e00:	032fc025 */ 	or	$t8,$t9,$t7
/*  f141e04:	00f06821 */ 	addu	$t5,$a3,$s0
/*  f141e08:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f141e0c:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f141e10:	31d90fff */ 	andi	$t9,$t6,0xfff
/*  f141e14:	acd80004 */ 	sw	$t8,0x4($a2)
/*  f141e18:	00197b00 */ 	sll	$t7,$t9,0xc
/*  f141e1c:	3c01e400 */ 	lui	$at,0xe400
/*  f141e20:	01e1c025 */ 	or	$t8,$t7,$at
/*  f141e24:	3c014180 */ 	lui	$at,0x4180
/*  f141e28:	44812000 */ 	mtc1	$at,$f4
/*  f141e2c:	3c014480 */ 	lui	$at,0x4480
/*  f141e30:	44815000 */ 	mtc1	$at,$f10
/*  f141e34:	254d0001 */ 	addiu	$t5,$t2,0x1
/*  f141e38:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f141e3c:	31d90fff */ 	andi	$t9,$t6,0xfff
/*  f141e40:	03197825 */ 	or	$t7,$t8,$t9
/*  f141e44:	00076880 */ 	sll	$t5,$a3,0x2
/*  f141e48:	00801825 */ 	or	$v1,$a0,$zero
/*  f141e4c:	46100481 */ 	sub.s	$f18,$f0,$f16
/*  f141e50:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f141e54:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f141e58:	46025403 */ 	div.s	$f16,$f10,$f2
/*  f141e5c:	000ac880 */ 	sll	$t9,$t2,0x2
/*  f141e60:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f141e64:	000ec300 */ 	sll	$t8,$t6,0xc
/*  f141e68:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f141e6c:	030f6825 */ 	or	$t5,$t8,$t7
/*  f141e70:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141e74:	00802825 */ 	or	$a1,$a0,$zero
/*  f141e78:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f141e7c:	3c0eb400 */ 	lui	$t6,0xb400
/*  f141e80:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f141e84:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141e88:	00801025 */ 	or	$v0,$a0,$zero
/*  f141e8c:	3c0eb300 */ 	lui	$t6,0xb300
/*  f141e90:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f141e94:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f141e98:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f141e9c:	440f4000 */ 	mfc1	$t7,$f8
/*  f141ea0:	00000000 */ 	nop
/*  f141ea4:	000f6c00 */ 	sll	$t5,$t7,0x10
/*  f141ea8:	440f9000 */ 	mfc1	$t7,$f18
/*  f141eac:	acad0004 */ 	sw	$t5,0x4($a1)
/*  f141eb0:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f141eb4:	000f6c00 */ 	sll	$t5,$t7,0x10
/*  f141eb8:	35ae0400 */ 	ori	$t6,$t5,0x400
/*  f141ebc:	ac4e0004 */ 	sw	$t6,0x4($v0)
.L0f141ec0:
/*  f141ec0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f141ec4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f141ec8:	27bd0080 */ 	addiu	$sp,$sp,0x80
/*  f141ecc:	03e00008 */ 	jr	$ra
/*  f141ed0:	00801025 */ 	or	$v0,$a0,$zero
);

// Mismatch due to wildly different codegen
//Gfx *bviewRenderLensRect(Gfx *gdl, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, s32 left, s32 width)
//{
//	if (width > 320) {
//		s32 sp70 = width / 2;
//
//		if (sp70);
//
//		gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, ((viGetWidth() * arg2 + left) * 2 + arg1));
//		gDPLoadBlock(gdl++, arg3, 0, 0, sp70 - 1, 0);
//		gSPTextureRectangle(gdl++,
//				left << 2,
//				arg4 << 2,
//				(left + sp70) << 2,
//				(arg4 + 1) << 2,
//				G_TX_RENDERTILE,
//				(width - width / arg5) * 16.0f,
//				0,
//				(s32)(1024.0f / arg5),
//				1024);
//
//		left += sp70;
//
//		gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, ((viGetWidth() * arg2 + left) * 2 + arg1));
//		gDPLoadBlock(gdl++, arg3, 0, 0, sp70 - 1, 0);
//		gSPTextureRectangle(gdl++,
//				left << 2,
//				arg4 << 2,
//				(left + sp70) << 2,
//				(arg4 + 1) << 2,
//				G_TX_RENDERTILE,
//				0,
//				0,
//				(s32)(1024.0f / arg5),
//				1024);
//
//	} else {
//		gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, ((viGetWidth() * arg2 + left) * 2 + arg1));
//		gDPLoadBlock(gdl++, arg3, 0, 0, width - 1, 0);
//		gSPTextureRectangle(gdl++,
//				left << 2,
//				arg4 << 2,
//				(left + width) << 2,
//				(arg4 + 1) << 2,
//				G_TX_RENDERTILE,
//				(width - width / arg5) * 16.0f,
//				0,
//				(s32)(1024.0f / arg5),
//				1024);
//	}
//
//	return gdl;
//}

Gfx *bviewRenderFisheyeRect(Gfx *gdl, s32 arg1, f32 arg2, s32 arg3, s32 arg4)
{
	if (arg2 < 1) {
		f32 tmp = arg4 * 0.5f;
		f32 fVar4 = arg3 + tmp;
		f32 fVar7 = (s32)(arg2 * tmp);

		gDPFillRectangle(gdl++, arg3, arg1, fVar4 - fVar7, arg1 + 1);
		gDPFillRectangle(gdl++, fVar4 + fVar7, arg1, arg3 + arg4, arg1 + 1);
	}

	return gdl;
}

Gfx *bviewPrepareStaticRgba16(Gfx *gdl, u32 colour, u32 alpha)
{
	static u32 envcol = 0xffffffff;
	static u32 primcol = 0x7f7f7fff;

	func0000db30("envcol", &envcol);
	func0000db30("primcol", &primcol);

	gDPPipeSync(gdl++);
	gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, 5, 0,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gSPTexture(gdl++, 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureDetail(gdl++, G_TD_CLAMP);
	gDPSetTextureLUT(gdl++, G_TT_NONE);
	gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, G_TX_RENDERTILE, 0,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x0800, 0x0020);
	gDPSetTextureFilter(gdl++, G_TF_POINT);
	gDPSetColor(gdl++, G_SETENVCOLOR, colour & 0xffffff00 | alpha & 0xff);
	gDPSetCombineLERP(gdl++,
			TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, ENVIRONMENT,
			TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, ENVIRONMENT);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetAlphaDither(gdl++, G_AD_NOISE);
	gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_NOOP2);

	return gdl;
}

Gfx *bviewPrepareStaticI8(Gfx *gdl, u32 colour, u32 alpha)
{
	static u32 envcol = 0xffffffff;
	static u32 primcol = 0x7f7f7fff;

	func0000db30("envcol", &envcol);
	func0000db30("primcol", &primcol);

	gDPPipeSync(gdl++);
	gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_8b, 0, 0x0000, 5, 0,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gSPTexture(gdl++, 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureDetail(gdl++, G_TD_CLAMP);
	gDPSetTextureLUT(gdl++, G_TT_NONE);
	gDPSetTile(gdl++, G_IM_FMT_I, G_IM_SIZ_8b, 160, 0, G_TX_RENDERTILE, 0,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
			G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x0800, 0x0020);
	gDPSetTextureFilter(gdl++, G_TF_POINT);
	gDPSetColor(gdl++, G_SETENVCOLOR, colour & 0xffffff00 | alpha & 0xff);
	gDPSetCombineLERP(gdl++,
			TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, ENVIRONMENT,
			TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, ENVIRONMENT);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetAlphaDither(gdl++, G_AD_NOISE);
	gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_NOOP2);

	return gdl;
}

Gfx *bviewRenderMotionBlur(Gfx *gdl, u32 colour, u32 alpha)
{
	void *unk28 = vi2GetUnk28();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewHeight();
	f32 fxxx;
	f32 fyyy;
	s32 viewwidth = viGetViewWidth();
	s32 viewleft = viGetViewLeft();
	f32 somefloat;
	s32 newalpha;
	s32 i;

	static u32 sfyyy = 1000;
	static u32 sfxxx = 1000;

	if (var8007f848) {
		return gdl;
	}

	var8007f848 = true;

	newalpha = alpha;
	newalpha += var8007f844;

	if (newalpha > 230) {
		newalpha = 230;
	}

	var8007f844 = 0;

	func0000db30("sfxxx", &sfxxx);
	fxxx = sfxxx / 1000.0f;
	func0000db30("sfyyy", &sfyyy);
	fyyy = sfyyy / 1000.0f;

	gDPPipeSync(gdl++);

	somefloat = (viewheight - viewheight / fyyy) * 0.5f;
	gdl = bviewPrepareStaticRgba16(gdl, colour, newalpha);

	for (i = viewtop; i < viewtop + viewheight; i++) {
		gdl = bviewRenderLensRect(gdl, unk28, viewtop + (s32)somefloat, 5, i, fxxx, viewleft, viewwidth);
		somefloat += 1.0f / fyyy;
	}

	return gdl;
}

Gfx *bviewRenderStatic(Gfx *gdl, u32 arg1, s32 arg2)
{
	void *unk28 = vi2GetUnk28();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewHeight();
	s32 viewwidth = viGetViewWidth();
	s32 viewleft = viGetViewLeft();
	void *ptr = (void *)(random() & 0xfff00 | 0x80000000);
	s32 y;

	gDPPipeSync(gdl++);

	gdl = bviewPrepareStaticI8(gdl, arg1, arg2);

	for (y = viewtop; y < viewtop + viewheight; y++) {
		gdl = bviewRenderLensRect(gdl, ptr, random() % 240, 5, y, 1.0f, viewleft, viewwidth);
	}

	if (ptr) {
		// empty
	}

	return gdl;
}

Gfx *bviewRenderSlayerRocketLens(Gfx *gdl, u32 colour, u32 alpha)
{
	void *sp7c = viGetUnk28();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewHeight();
	s32 viewwidth = viGetViewWidth();
	s32 y;
	s32 viewleft = viGetViewLeft();
	f32 angle = 0.52359879016876f;
	s32 offset = (s32)(var80061630 * 600.0f) % 12;
	f32 increment;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	strcpy(var800a41c0, "interlaceGfx");

	gDPPipeSync(gdl++);

	increment = (2.6179938316345f - angle) / viewheight;

	gdl = bviewPrepareStaticRgba16(gdl, colour, alpha);

	for (y = viewtop; y < viewtop + viewheight; y++) {
		s32 offsety = y - offset;

		if ((offsety % 8) == 0 || y == viewtop) {
			if ((offsety % 16) < 8) {
				gDPSetEnvColor(gdl++, 0xff, 0xff, 0x00, 0xff);
			} else {
				gDPSetEnvColor(gdl++, 0xff, 0xff, 0xbf, 0xff);
			}
		}

		gdl = bviewRenderLensRect(gdl, sp7c, y, 5, y, 2.0f - sinf(angle), viewleft, viewwidth);

		angle += increment;
	}

	return gdl;
}

Gfx *bviewRenderFilmLens(Gfx *gdl, u32 colour, u32 alpha)
{
	void *unk28 = viGetUnk28();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewHeight();
	s32 y;
	s32 viewwidth = viGetViewWidth();
	s32 viewleft = viGetViewLeft();
	s32 offset = (s32)(var80061630 * 600.0f) % 12;
	u32 stack;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	strcpy(var800a41c0, "BlueInterlaceGfx");

	gDPPipeSync(gdl++);

	gdl = bviewPrepareStaticRgba16(gdl, colour, alpha);

	for (y = viewtop; y < viewtop + viewheight; y++) {
		s32 offsety = y - offset;
		s32 tmpy = y;

		if (offsety % 6 == 0 || y == viewtop) {
			if (offsety % 12 < 6) {
				gDPSetEnvColor(gdl++, 0x7f, 0xff, 0xff, 0xff);
			} else {
				gDPSetEnvColor(gdl++, 0x00, 0xaf, 0xff, 0xff);
			}
		}

		if (random() % 20 == 1) {
			tmpy = random() % 200;
		}

		gdl = bviewRenderLensRect(gdl, unk28, tmpy, 5, y, 1, viewleft, viewwidth);
	}

	return gdl;
}

/**
 * Renders a zoom in/out motion blur effect.
 *
 * Used when entering/exiting combat boosts and when entering/exiting xray mode.
 */
Gfx *bviewRenderZoomBlur(Gfx *gdl, u32 colour, s32 alpha, f32 arg3, f32 arg4)
{
	void *unk28 = vi2GetUnk28();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewHeight();
	s32 viewwidth = viGetViewWidth();
	s32 viewleft = viGetViewLeft();
	f32 somefloat;
	s32 i;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	strcpy(var800a41c0, "stretchBlurGfx");

	gDPPipeSync(gdl++);

	somefloat = (viewheight - viewheight / arg4) * 0.5f;

	gdl = bviewPrepareStaticRgba16(gdl, colour, alpha);

	for (i = viewtop; i < viewtop + viewheight; i++) {
		gdl = bviewRenderLensRect(gdl, unk28, (s32)somefloat + viewtop, 5, i, arg3, viewleft, viewwidth);
		somefloat += 1.0f / arg4;
	}

	return gdl;
}

const char var7f1b5dd4[] = "blurGfxFisheye";

f32 bview0f142d74(s32 arg0, f32 arg1, f32 arg2, f32 arg3)
{
	f32 result;
	f32 value = arg2;

	if (arg0 < 0 || arg0 >= 0x80) {
		return 0.01f;
	}

	value += arg0 * arg1;

	if (arg3 > value * value) {
		result = sqrtf(arg3 - value * value) * 0.00625f;
	} else {
		result = 0.01f;
	}

	return result;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel bviewRenderFisheye
.late_rodata
glabel var7f1b5f40
.word 0x3f83d70a
glabel var7f1b5f44
.word 0x3bcccccd
glabel var7f1b5f48
.word 0x3c23d70a
.text
/*  f143970:	27bdfec8 */ 	addiu	$sp,$sp,-312
/*  f143974:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f143978:	afbe0060 */ 	sw	$s8,0x60($sp)
/*  f14397c:	afb20048 */ 	sw	$s2,0x48($sp)
/*  f143980:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f143984:	00c08025 */ 	move	$s0,$a2
/*  f143988:	00809025 */ 	move	$s2,$a0
/*  f14398c:	00a0f025 */ 	move	$s8,$a1
/*  f143990:	afb7005c */ 	sw	$s7,0x5c($sp)
/*  f143994:	afb60058 */ 	sw	$s6,0x58($sp)
/*  f143998:	afb50054 */ 	sw	$s5,0x54($sp)
/*  f14399c:	afb40050 */ 	sw	$s4,0x50($sp)
/*  f1439a0:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f1439a4:	afb10044 */ 	sw	$s1,0x44($sp)
/*  f1439a8:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f1439ac:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f1439b0:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f1439b4:	0c002a18 */ 	jal	viGetUnk28
/*  f1439b8:	afa70144 */ 	sw	$a3,0x144($sp)
/*  f1439bc:	0c002e95 */ 	jal	viGetViewTop
/*  f1439c0:	afa20134 */ 	sw	$v0,0x134($sp)
/*  f1439c4:	0c002e77 */ 	jal	viGetViewHeight
/*  f1439c8:	afa20130 */ 	sw	$v0,0x130($sp)
/*  f1439cc:	0c002e73 */ 	jal	viGetViewWidth
/*  f1439d0:	afa2012c */ 	sw	$v0,0x12c($sp)
/*  f1439d4:	0c002e91 */ 	jal	viGetViewLeft
/*  f1439d8:	0040b025 */ 	move	$s6,$v0
/*  f1439dc:	3c06800a */ 	lui	$a2,0x800a
/*  f1439e0:	24c6a510 */ 	addiu	$a2,$a2,-23280
/*  f1439e4:	8cce006c */ 	lw	$t6,0x6c($a2)
/*  f1439e8:	3c013f80 */ 	lui	$at,0x3f80
/*  f1439ec:	4481c000 */ 	mtc1	$at,$f24
/*  f1439f0:	0040a825 */ 	move	$s5,$v0
/*  f1439f4:	00008825 */ 	move	$s1,$zero
/*  f1439f8:	11c00003 */ 	beqz	$t6,.PF0f143a08
/*  f1439fc:	e7b80100 */ 	swc1	$f24,0x100($sp)
/*  f143a00:	10000002 */ 	b	.PF0f143a0c
/*  f143a04:	24050001 */ 	li	$a1,0x1
.PF0f143a08:
/*  f143a08:	00002825 */ 	move	$a1,$zero
.PF0f143a0c:
/*  f143a0c:	8ccf0068 */ 	lw	$t7,0x68($a2)
/*  f143a10:	00001825 */ 	move	$v1,$zero
/*  f143a14:	00002025 */ 	move	$a0,$zero
/*  f143a18:	11e00003 */ 	beqz	$t7,.PF0f143a28
/*  f143a1c:	00001025 */ 	move	$v0,$zero
/*  f143a20:	10000001 */ 	b	.PF0f143a28
/*  f143a24:	24030001 */ 	li	$v1,0x1
.PF0f143a28:
/*  f143a28:	8cd80064 */ 	lw	$t8,0x64($a2)
/*  f143a2c:	13000003 */ 	beqz	$t8,.PF0f143a3c
/*  f143a30:	00000000 */ 	nop
/*  f143a34:	10000001 */ 	b	.PF0f143a3c
/*  f143a38:	24040001 */ 	li	$a0,0x1
.PF0f143a3c:
/*  f143a3c:	8cd90070 */ 	lw	$t9,0x70($a2)
/*  f143a40:	13200003 */ 	beqz	$t9,.PF0f143a50
/*  f143a44:	00000000 */ 	nop
/*  f143a48:	10000001 */ 	b	.PF0f143a50
/*  f143a4c:	24020001 */ 	li	$v0,0x1
.PF0f143a50:
/*  f143a50:	00444821 */ 	addu	$t1,$v0,$a0
/*  f143a54:	01235021 */ 	addu	$t2,$t1,$v1
/*  f143a58:	01455821 */ 	addu	$t3,$t2,$a1
/*  f143a5c:	29610002 */ 	slti	$at,$t3,0x2
/*  f143a60:	5020000c */ 	beqzl	$at,.PF0f143a94
/*  f143a64:	8fad0130 */ 	lw	$t5,0x130($sp)
/*  f143a68:	0fc54e8c */ 	jal	optionsGetEffectiveScreenSize
/*  f143a6c:	00000000 */ 	nop
/*  f143a70:	24010001 */ 	li	$at,0x1
/*  f143a74:	50410007 */ 	beql	$v0,$at,.PF0f143a94
/*  f143a78:	8fad0130 */ 	lw	$t5,0x130($sp)
/*  f143a7c:	0fc54e8c */ 	jal	optionsGetEffectiveScreenSize
/*  f143a80:	00000000 */ 	nop
/*  f143a84:	24010002 */ 	li	$at,0x2
/*  f143a88:	1441000a */ 	bne	$v0,$at,.PF0f143ab4
/*  f143a8c:	24190017 */ 	li	$t9,0x17
/*  f143a90:	8fad0130 */ 	lw	$t5,0x130($sp)
.PF0f143a94:
/*  f143a94:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f143a98:	240c0010 */ 	li	$t4,0x10
/*  f143a9c:	25ae0010 */ 	addiu	$t6,$t5,0x10
/*  f143aa0:	25f8ffe0 */ 	addiu	$t8,$t7,-32
/*  f143aa4:	afac00ec */ 	sw	$t4,0xec($sp)
/*  f143aa8:	afae0130 */ 	sw	$t6,0x130($sp)
/*  f143aac:	10000008 */ 	b	.PF0f143ad0
/*  f143ab0:	afb8012c */ 	sw	$t8,0x12c($sp)
.PF0f143ab4:
/*  f143ab4:	8fa90130 */ 	lw	$t1,0x130($sp)
/*  f143ab8:	8fab012c */ 	lw	$t3,0x12c($sp)
/*  f143abc:	afb900ec */ 	sw	$t9,0xec($sp)
/*  f143ac0:	252a0017 */ 	addiu	$t2,$t1,0x17
/*  f143ac4:	256cffd2 */ 	addiu	$t4,$t3,-46
/*  f143ac8:	afaa0130 */ 	sw	$t2,0x130($sp)
/*  f143acc:	afac012c */ 	sw	$t4,0x12c($sp)
.PF0f143ad0:
/*  f143ad0:	8fad012c */ 	lw	$t5,0x12c($sp)
/*  f143ad4:	3c013f00 */ 	lui	$at,0x3f00
/*  f143ad8:	44813000 */ 	mtc1	$at,$f6
/*  f143adc:	448d2000 */ 	mtc1	$t5,$f4
/*  f143ae0:	3c028008 */ 	lui	$v0,0x8008
/*  f143ae4:	2442fda0 */ 	addiu	$v0,$v0,-608
/*  f143ae8:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f143aec:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f143af0:	3c04800a */ 	lui	$a0,0x800a
/*  f143af4:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f143af8:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f143afc:	29e10002 */ 	slti	$at,$t7,0x2
/*  f143b00:	46060582 */ 	mul.s	$f22,$f0,$f6
/*  f143b04:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f143b08:	24a570f4 */ 	addiu	$a1,$a1,0x70f4
/*  f143b0c:	24844760 */ 	addiu	$a0,$a0,0x4760
/*  f143b10:	14200003 */ 	bnez	$at,.PF0f143b20
/*  f143b14:	e7b60124 */ 	swc1	$f22,0x124($sp)
/*  f143b18:	100001f9 */ 	b	.PF0f144300
/*  f143b1c:	02401025 */ 	move	$v0,$s2
.PF0f143b20:
/*  f143b20:	0c004bb0 */ 	jal	strcpy
/*  f143b24:	e7a00084 */ 	swc1	$f0,0x84($sp)
/*  f143b28:	83a3014b */ 	lb	$v1,0x14b($sp)
/*  f143b2c:	24130001 */ 	li	$s3,0x1
/*  f143b30:	26440008 */ 	addiu	$a0,$s2,0x8
/*  f143b34:	28670029 */ 	slti	$a3,$v1,0x29
/*  f143b38:	30f900ff */ 	andi	$t9,$a3,0xff
/*  f143b3c:	13200018 */ 	beqz	$t9,.PF0f143ba0
/*  f143b40:	03203825 */ 	move	$a3,$t9
/*  f143b44:	44834000 */ 	mtc1	$v1,$f8
/*  f143b48:	3c014224 */ 	lui	$at,0x4224
/*  f143b4c:	44818000 */ 	mtc1	$at,$f16
/*  f143b50:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f143b54:	3c01437f */ 	lui	$at,0x437f
/*  f143b58:	44813000 */ 	mtc1	$at,$f6
/*  f143b5c:	4600b506 */ 	mov.s	$f20,$f22
/*  f143b60:	e7b400fc */ 	swc1	$f20,0xfc($sp)
/*  f143b64:	240c00ff */ 	li	$t4,0xff
/*  f143b68:	46105003 */ 	div.s	$f0,$f10,$f16
/*  f143b6c:	4600b482 */ 	mul.s	$f18,$f22,$f0
/*  f143b70:	e7a00100 */ 	swc1	$f0,0x100($sp)
/*  f143b74:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f143b78:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f143b7c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f143b80:	440a2000 */ 	mfc1	$t2,$f4
/*  f143b84:	44025000 */ 	mfc1	$v0,$f10
/*  f143b88:	afaa0104 */ 	sw	$t2,0x104($sp)
/*  f143b8c:	28410100 */ 	slti	$at,$v0,0x100
/*  f143b90:	14200003 */ 	bnez	$at,.PF0f143ba0
/*  f143b94:	afa200f4 */ 	sw	$v0,0xf4($sp)
/*  f143b98:	afac00f4 */ 	sw	$t4,0xf4($sp)
/*  f143b9c:	e7b400fc */ 	swc1	$f20,0xfc($sp)
.PF0f143ba0:
/*  f143ba0:	c7b400fc */ 	lwc1	$f20,0xfc($sp)
/*  f143ba4:	02401025 */ 	move	$v0,$s2
/*  f143ba8:	3c0de700 */ 	lui	$t5,0xe700
/*  f143bac:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f143bb0:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f143bb4:	afa70068 */ 	sw	$a3,0x68($sp)
/*  f143bb8:	03c02825 */ 	move	$a1,$s8
/*  f143bbc:	0fc50b08 */ 	jal	bviewPrepareStaticRgba16
/*  f143bc0:	02003025 */ 	move	$a2,$s0
/*  f143bc4:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f143bc8:	00409025 */ 	move	$s2,$v0
/*  f143bcc:	8fa20130 */ 	lw	$v0,0x130($sp)
/*  f143bd0:	11c00052 */ 	beqz	$t6,.PF0f143d1c
/*  f143bd4:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f143bd8:	004fb821 */ 	addu	$s7,$v0,$t7
/*  f143bdc:	0057082a */ 	slt	$at,$v0,$s7
/*  f143be0:	102000d7 */ 	beqz	$at,.PF0f143f40
/*  f143be4:	00408025 */ 	move	$s0,$v0
/*  f143be8:	3c14fb00 */ 	lui	$s4,0xfb00
.PF0f143bec:
/*  f143bec:	06010004 */ 	bgez	$s0,.PF0f143c00
/*  f143bf0:	32180001 */ 	andi	$t8,$s0,0x1
/*  f143bf4:	13000002 */ 	beqz	$t8,.PF0f143c00
/*  f143bf8:	00000000 */ 	nop
/*  f143bfc:	2718fffe */ 	addiu	$t8,$t8,-2
.PF0f143c00:
/*  f143c00:	53000036 */ 	beqzl	$t8,.PF0f143cdc
/*  f143c04:	02338821 */ 	addu	$s1,$s1,$s3
/*  f143c08:	44828000 */ 	mtc1	$v0,$f16
/*  f143c0c:	8fb90104 */ 	lw	$t9,0x104($sp)
/*  f143c10:	44903000 */ 	mtc1	$s0,$f6
/*  f143c14:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f143c18:	44992000 */ 	mtc1	$t9,$f4
/*  f143c1c:	00000000 */ 	nop
/*  f143c20:	468020a0 */ 	cvt.s.w	$f2,$f4
/*  f143c24:	46149000 */ 	add.s	$f0,$f18,$f20
/*  f143c28:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f143c2c:	46020201 */ 	sub.s	$f8,$f0,$f2
/*  f143c30:	460c403c */ 	c.lt.s	$f8,$f12
/*  f143c34:	00000000 */ 	nop
/*  f143c38:	45020028 */ 	bc1fl	.PF0f143cdc
/*  f143c3c:	02338821 */ 	addu	$s1,$s1,$s3
/*  f143c40:	46020280 */ 	add.s	$f10,$f0,$f2
/*  f143c44:	2401ff00 */ 	li	$at,-256
/*  f143c48:	460a603c */ 	c.lt.s	$f12,$f10
/*  f143c4c:	00000000 */ 	nop
/*  f143c50:	45020022 */ 	bc1fl	.PF0f143cdc
/*  f143c54:	02338821 */ 	addu	$s1,$s1,$s3
/*  f143c58:	02401025 */ 	move	$v0,$s2
/*  f143c5c:	ac540000 */ 	sw	$s4,0x0($v0)
/*  f143c60:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*  f143c64:	4616b400 */ 	add.s	$f16,$f22,$f22
/*  f143c68:	03c14824 */ 	and	$t1,$s8,$at
/*  f143c6c:	314b00ff */ 	andi	$t3,$t2,0xff
/*  f143c70:	012b6025 */ 	or	$t4,$t1,$t3
/*  f143c74:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f143c78:	c7a40084 */ 	lwc1	$f4,0x84($sp)
/*  f143c7c:	46008487 */ 	neg.s	$f18,$f16
/*  f143c80:	4616b202 */ 	mul.s	$f8,$f22,$f22
/*  f143c84:	46049183 */ 	div.s	$f6,$f18,$f4
/*  f143c88:	4406b000 */ 	mfc1	$a2,$f22
/*  f143c8c:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f143c90:	02202025 */ 	move	$a0,$s1
/*  f143c94:	44074000 */ 	mfc1	$a3,$f8
/*  f143c98:	44053000 */ 	mfc1	$a1,$f6
/*  f143c9c:	0fc50e39 */ 	jal	bview0f142d74
/*  f143ca0:	00000000 */ 	nop
/*  f143ca4:	c7aa0100 */ 	lwc1	$f10,0x100($sp)
/*  f143ca8:	02402025 */ 	move	$a0,$s2
/*  f143cac:	8fa50134 */ 	lw	$a1,0x134($sp)
/*  f143cb0:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f143cb4:	02003025 */ 	move	$a2,$s0
/*  f143cb8:	24070005 */ 	li	$a3,0x5
/*  f143cbc:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f143cc0:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f143cc4:	afb6001c */ 	sw	$s6,0x1c($sp)
/*  f143cc8:	0fc50988 */ 	jal	bviewRenderLensRect
/*  f143ccc:	e7b00014 */ 	swc1	$f16,0x14($sp)
/*  f143cd0:	00409025 */ 	move	$s2,$v0
/*  f143cd4:	8fa20130 */ 	lw	$v0,0x130($sp)
/*  f143cd8:	02338821 */ 	addu	$s1,$s1,$s3
.PF0f143cdc:
/*  f143cdc:	44919000 */ 	mtc1	$s1,$f18
/*  f143ce0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f143ce4:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f143ce8:	4604b03e */ 	c.le.s	$f22,$f4
/*  f143cec:	00000000 */ 	nop
/*  f143cf0:	45000005 */ 	bc1f	.PF0f143d08
/*  f143cf4:	00000000 */ 	nop
/*  f143cf8:	4600b18d */ 	trunc.w.s	$f6,$f22
/*  f143cfc:	00139823 */ 	negu	$s3,$s3
/*  f143d00:	44113000 */ 	mfc1	$s1,$f6
/*  f143d04:	00000000 */ 	nop
.PF0f143d08:
/*  f143d08:	1617ffb8 */ 	bne	$s0,$s7,.PF0f143bec
/*  f143d0c:	00000000 */ 	nop
/*  f143d10:	24130001 */ 	li	$s3,0x1
/*  f143d14:	1000008a */ 	b	.PF0f143f40
/*  f143d18:	00408025 */ 	move	$s0,$v0
.PF0f143d1c:
/*  f143d1c:	8fb00130 */ 	lw	$s0,0x130($sp)
/*  f143d20:	8faf012c */ 	lw	$t7,0x12c($sp)
/*  f143d24:	e7b800dc */ 	swc1	$f24,0xdc($sp)
/*  f143d28:	c7b00084 */ 	lwc1	$f16,0x84($sp)
/*  f143d2c:	020fb821 */ 	addu	$s7,$s0,$t7
/*  f143d30:	0217082a */ 	slt	$at,$s0,$s7
/*  f143d34:	10200082 */ 	beqz	$at,.PF0f143f40
/*  f143d38:	93b8014f */ 	lbu	$t8,0x14f($sp)
/*  f143d3c:	4616b200 */ 	add.s	$f8,$f22,$f22
/*  f143d40:	4616b602 */ 	mul.s	$f24,$f22,$f22
/*  f143d44:	afb8006c */ 	sw	$t8,0x6c($sp)
/*  f143d48:	3c14fb00 */ 	lui	$s4,0xfb00
/*  f143d4c:	46004287 */ 	neg.s	$f10,$f8
/*  f143d50:	46105503 */ 	div.s	$f20,$f10,$f16
.PF0f143d54:
/*  f143d54:	8fb9006c */ 	lw	$t9,0x6c($sp)
/*  f143d58:	24010004 */ 	li	$at,0x4
/*  f143d5c:	02401025 */ 	move	$v0,$s2
/*  f143d60:	17210020 */ 	bne	$t9,$at,.PF0f143de4
/*  f143d64:	240dffff */ 	li	$t5,-1
/*  f143d68:	0c004ad4 */ 	jal	random
/*  f143d6c:	00000000 */ 	nop
/*  f143d70:	24010078 */ 	li	$at,0x78
/*  f143d74:	0041001b */ 	divu	$zero,$v0,$at
/*  f143d78:	0000f010 */ 	mfhi	$s8
/*  f143d7c:	27ca0078 */ 	addiu	$t2,$s8,0x78
/*  f143d80:	3c01ff33 */ 	lui	$at,0xff33
/*  f143d84:	34213300 */ 	ori	$at,$at,0x3300
/*  f143d88:	314900ff */ 	andi	$t1,$t2,0xff
/*  f143d8c:	0c004ad4 */ 	jal	random
/*  f143d90:	0121f025 */ 	or	$s8,$t1,$at
/*  f143d94:	304c001f */ 	andi	$t4,$v0,0x1f
/*  f143d98:	448c9000 */ 	mtc1	$t4,$f18
/*  f143d9c:	3c014f80 */ 	lui	$at,0x4f80
/*  f143da0:	05810004 */ 	bgez	$t4,.PF0f143db4
/*  f143da4:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f143da8:	44813000 */ 	mtc1	$at,$f6
/*  f143dac:	00000000 */ 	nop
/*  f143db0:	46062100 */ 	add.s	$f4,$f4,$f6
.PF0f143db4:
/*  f143db4:	3c01435c */ 	lui	$at,0x435c
/*  f143db8:	44814000 */ 	mtc1	$at,$f8
/*  f143dbc:	3c013b80 */ 	lui	$at,0x3b80
/*  f143dc0:	44818000 */ 	mtc1	$at,$f16
/*  f143dc4:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f143dc8:	02401825 */ 	move	$v1,$s2
/*  f143dcc:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f143dd0:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f143dd4:	e7b200dc */ 	swc1	$f18,0xdc($sp)
/*  f143dd8:	ac7e0004 */ 	sw	$s8,0x4($v1)
/*  f143ddc:	10000004 */ 	b	.PF0f143df0
/*  f143de0:	ac740000 */ 	sw	$s4,0x0($v1)
.PF0f143de4:
/*  f143de4:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f143de8:	ac540000 */ 	sw	$s4,0x0($v0)
/*  f143dec:	ac4d0004 */ 	sw	$t5,0x4($v0)
.PF0f143df0:
/*  f143df0:	4405a000 */ 	mfc1	$a1,$f20
/*  f143df4:	4406b000 */ 	mfc1	$a2,$f22
/*  f143df8:	4407c000 */ 	mfc1	$a3,$f24
/*  f143dfc:	0fc50e39 */ 	jal	bview0f142d74
/*  f143e00:	02202025 */ 	move	$a0,$s1
/*  f143e04:	c7a600dc */ 	lwc1	$f6,0xdc($sp)
/*  f143e08:	02402025 */ 	move	$a0,$s2
/*  f143e0c:	8fa50134 */ 	lw	$a1,0x134($sp)
/*  f143e10:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f143e14:	02003025 */ 	move	$a2,$s0
/*  f143e18:	24070005 */ 	li	$a3,0x5
/*  f143e1c:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f143e20:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f143e24:	afb6001c */ 	sw	$s6,0x1c($sp)
/*  f143e28:	0fc50988 */ 	jal	bviewRenderLensRect
/*  f143e2c:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f143e30:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f143e34:	24010004 */ 	li	$at,0x4
/*  f143e38:	00409025 */ 	move	$s2,$v0
/*  f143e3c:	15e10018 */ 	bne	$t7,$at,.PF0f143ea0
/*  f143e40:	3c0eddaa */ 	lui	$t6,0xddaa
/*  f143e44:	02401025 */ 	move	$v0,$s2
/*  f143e48:	35ceaa99 */ 	ori	$t6,$t6,0xaa99
/*  f143e4c:	4405a000 */ 	mfc1	$a1,$f20
/*  f143e50:	4406b000 */ 	mfc1	$a2,$f22
/*  f143e54:	4407c000 */ 	mfc1	$a3,$f24
/*  f143e58:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f143e5c:	ac540000 */ 	sw	$s4,0x0($v0)
/*  f143e60:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f143e64:	0fc50e39 */ 	jal	bview0f142d74
/*  f143e68:	02202025 */ 	move	$a0,$s1
/*  f143e6c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f143e70:	c4287260 */ 	lwc1	$f8,0x7260($at)
/*  f143e74:	02402025 */ 	move	$a0,$s2
/*  f143e78:	8fa50134 */ 	lw	$a1,0x134($sp)
/*  f143e7c:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f143e80:	02003025 */ 	move	$a2,$s0
/*  f143e84:	24070005 */ 	li	$a3,0x5
/*  f143e88:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f143e8c:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f143e90:	afb6001c */ 	sw	$s6,0x1c($sp)
/*  f143e94:	0fc50988 */ 	jal	bviewRenderLensRect
/*  f143e98:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f143e9c:	00409025 */ 	move	$s2,$v0
.PF0f143ea0:
/*  f143ea0:	32180001 */ 	andi	$t8,$s0,0x1
/*  f143ea4:	17000017 */ 	bnez	$t8,.PF0f143f04
/*  f143ea8:	02338821 */ 	addu	$s1,$s1,$s3
/*  f143eac:	02b65021 */ 	addu	$t2,$s5,$s6
/*  f143eb0:	314903ff */ 	andi	$t1,$t2,0x3ff
/*  f143eb4:	24190055 */ 	li	$t9,0x55
/*  f143eb8:	00095b80 */ 	sll	$t3,$t1,0xe
/*  f143ebc:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f143ec0:	24520008 */ 	addiu	$s2,$v0,0x8
/*  f143ec4:	3c01f600 */ 	lui	$at,0xf600
/*  f143ec8:	260d0001 */ 	addiu	$t5,$s0,0x1
/*  f143ecc:	31af03ff */ 	andi	$t7,$t5,0x3ff
/*  f143ed0:	01616025 */ 	or	$t4,$t3,$at
/*  f143ed4:	02402025 */ 	move	$a0,$s2
/*  f143ed8:	32b903ff */ 	andi	$t9,$s5,0x3ff
/*  f143edc:	320903ff */ 	andi	$t1,$s0,0x3ff
/*  f143ee0:	ac540000 */ 	sw	$s4,0x0($v0)
/*  f143ee4:	00095880 */ 	sll	$t3,$t1,0x2
/*  f143ee8:	00195380 */ 	sll	$t2,$t9,0xe
/*  f143eec:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f143ef0:	018ec025 */ 	or	$t8,$t4,$t6
/*  f143ef4:	014b6825 */ 	or	$t5,$t2,$t3
/*  f143ef8:	ac8d0004 */ 	sw	$t5,0x4($a0)
/*  f143efc:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f143f00:	26520008 */ 	addiu	$s2,$s2,0x8
.PF0f143f04:
/*  f143f04:	44918000 */ 	mtc1	$s1,$f16
/*  f143f08:	26020001 */ 	addiu	$v0,$s0,0x1
/*  f143f0c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f143f10:	4612b03e */ 	c.le.s	$f22,$f18
/*  f143f14:	00000000 */ 	nop
/*  f143f18:	45000005 */ 	bc1f	.PF0f143f30
/*  f143f1c:	00000000 */ 	nop
/*  f143f20:	4600b18d */ 	trunc.w.s	$f6,$f22
/*  f143f24:	00139823 */ 	negu	$s3,$s3
/*  f143f28:	44113000 */ 	mfc1	$s1,$f6
/*  f143f2c:	00000000 */ 	nop
.PF0f143f30:
/*  f143f30:	1457ff88 */ 	bne	$v0,$s7,.PF0f143d54
/*  f143f34:	00408025 */ 	move	$s0,$v0
/*  f143f38:	24130001 */ 	li	$s3,0x1
/*  f143f3c:	8fb00130 */ 	lw	$s0,0x130($sp)
.PF0f143f40:
/*  f143f40:	02401025 */ 	move	$v0,$s2
/*  f143f44:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f143f48:	3c0ce700 */ 	lui	$t4,0xe700
/*  f143f4c:	02401825 */ 	move	$v1,$s2
/*  f143f50:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f143f54:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f143f58:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f143f5c:	3c0eba00 */ 	lui	$t6,0xba00
/*  f143f60:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f143f64:	02402025 */ 	move	$a0,$s2
/*  f143f68:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f143f6c:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f143f70:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f143f74:	3c18b900 */ 	lui	$t8,0xb900
/*  f143f78:	3c190050 */ 	lui	$t9,0x50
/*  f143f7c:	37394240 */ 	ori	$t9,$t9,0x4240
/*  f143f80:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f143f84:	02402825 */ 	move	$a1,$s2
/*  f143f88:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f143f8c:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f143f90:	3c09fcff */ 	lui	$t1,0xfcff
/*  f143f94:	3c0afffd */ 	lui	$t2,0xfffd
/*  f143f98:	354af6fb */ 	ori	$t2,$t2,0xf6fb
/*  f143f9c:	3529ffff */ 	ori	$t1,$t1,0xffff
/*  f143fa0:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f143fa4:	aca90000 */ 	sw	$t1,0x0($a1)
/*  f143fa8:	acaa0004 */ 	sw	$t2,0x4($a1)
/*  f143fac:	02403025 */ 	move	$a2,$s2
/*  f143fb0:	3c0bfa00 */ 	lui	$t3,0xfa00
/*  f143fb4:	240d00ff */ 	li	$t5,0xff
/*  f143fb8:	accd0004 */ 	sw	$t5,0x4($a2)
/*  f143fbc:	accb0000 */ 	sw	$t3,0x0($a2)
/*  f143fc0:	8fa30144 */ 	lw	$v1,0x144($sp)
/*  f143fc4:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f143fc8:	8faf0068 */ 	lw	$t7,0x68($sp)
/*  f143fcc:	54600004 */ 	bnezl	$v1,.PF0f143fe0
/*  f143fd0:	4600b10d */ 	trunc.w.s	$f4,$f22
/*  f143fd4:	51e0007b */ 	beqzl	$t7,.PF0f1441c4
/*  f143fd8:	8faf0130 */ 	lw	$t7,0x130($sp)
/*  f143fdc:	4600b10d */ 	trunc.w.s	$f4,$f22
.PF0f143fe0:
/*  f143fe0:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f143fe4:	2463fff6 */ 	addiu	$v1,$v1,-10
/*  f143fe8:	8fb70104 */ 	lw	$s7,0x104($sp)
/*  f143fec:	44022000 */ 	mfc1	$v0,$f4
/*  f143ff0:	8fb90130 */ 	lw	$t9,0x130($sp)
/*  f143ff4:	15c00011 */ 	bnez	$t6,.PF0f14403c
/*  f143ff8:	afa200ac */ 	sw	$v0,0xac($sp)
/*  f143ffc:	04630003 */ 	bgezl	$v1,.PF0f14400c
/*  f144000:	44834000 */ 	mtc1	$v1,$f8
/*  f144004:	00031823 */ 	negu	$v1,$v1
/*  f144008:	44834000 */ 	mtc1	$v1,$f8
.PF0f14400c:
/*  f14400c:	3c014120 */ 	lui	$at,0x4120
/*  f144010:	44818000 */ 	mtc1	$at,$f16
/*  f144014:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f144018:	44823000 */ 	mtc1	$v0,$f6
/*  f14401c:	00000000 */ 	nop
/*  f144020:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f144024:	46105483 */ 	div.s	$f18,$f10,$f16
/*  f144028:	46122202 */ 	mul.s	$f8,$f4,$f18
/*  f14402c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f144030:	44175000 */ 	mfc1	$s7,$f10
/*  f144034:	10000002 */ 	b	.PF0f144040
/*  f144038:	0322f021 */ 	addu	$s8,$t9,$v0
.PF0f14403c:
/*  f14403c:	0322f021 */ 	addu	$s8,$t9,$v0
.PF0f144040:
/*  f144040:	03d7a023 */ 	subu	$s4,$s8,$s7
/*  f144044:	0334082a */ 	slt	$at,$t9,$s4
/*  f144048:	10200018 */ 	beqz	$at,.PF0f1440ac
/*  f14404c:	8fa900ac */ 	lw	$t1,0xac($sp)
/*  f144050:	8fad012c */ 	lw	$t5,0x12c($sp)
/*  f144054:	03395821 */ 	addu	$t3,$t9,$t9
/*  f144058:	03295021 */ 	addu	$t2,$t9,$t1
/*  f14405c:	016d7821 */ 	addu	$t7,$t3,$t5
/*  f144060:	4480a000 */ 	mtc1	$zero,$f20
/*  f144064:	01f08823 */ 	subu	$s1,$t7,$s0
/*  f144068:	01579823 */ 	subu	$s3,$t2,$s7
.PF0f14406c:
/*  f14406c:	4406a000 */ 	mfc1	$a2,$f20
/*  f144070:	02402025 */ 	move	$a0,$s2
/*  f144074:	02002825 */ 	move	$a1,$s0
/*  f144078:	02a03825 */ 	move	$a3,$s5
/*  f14407c:	0fc50a91 */ 	jal	bviewRenderFisheyeRect
/*  f144080:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f144084:	4406a000 */ 	mfc1	$a2,$f20
/*  f144088:	00402025 */ 	move	$a0,$v0
/*  f14408c:	02202825 */ 	move	$a1,$s1
/*  f144090:	02a03825 */ 	move	$a3,$s5
/*  f144094:	0fc50a91 */ 	jal	bviewRenderFisheyeRect
/*  f144098:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f14409c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1440a0:	2631ffff */ 	addiu	$s1,$s1,-1
/*  f1440a4:	1613fff1 */ 	bne	$s0,$s3,.PF0f14406c
/*  f1440a8:	00409025 */ 	move	$s2,$v0
.PF0f1440ac:
/*  f1440ac:	c7a00124 */ 	lwc1	$f0,0x124($sp)
/*  f1440b0:	02401025 */ 	move	$v0,$s2
/*  f1440b4:	3c0cfa00 */ 	lui	$t4,0xfa00
/*  f1440b8:	240e00ff */ 	li	$t6,0xff
/*  f1440bc:	03d4082a */ 	slt	$at,$s8,$s4
/*  f1440c0:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f1440c4:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f1440c8:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f1440cc:	02808025 */ 	move	$s0,$s4
/*  f1440d0:	1420005f */ 	bnez	$at,.PF0f144250
/*  f1440d4:	46000506 */ 	mov.s	$f20,$f0
/*  f1440d8:	240d0001 */ 	li	$t5,0x1
/*  f1440dc:	448d8000 */ 	mtc1	$t5,$f16
/*  f1440e0:	4616b602 */ 	mul.s	$f24,$f22,$f22
/*  f1440e4:	44974000 */ 	mtc1	$s7,$f8
/*  f1440e8:	8fb80130 */ 	lw	$t8,0x130($sp)
/*  f1440ec:	8fb9012c */ 	lw	$t9,0x12c($sp)
/*  f1440f0:	8fa900ac */ 	lw	$t1,0xac($sp)
/*  f1440f4:	03185021 */ 	addu	$t2,$t8,$t8
/*  f1440f8:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f1440fc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f144100:	01595821 */ 	addu	$t3,$t2,$t9
/*  f144104:	01748823 */ 	subu	$s1,$t3,$s4
/*  f144108:	c4367264 */ 	lwc1	$f22,0x7264($at)
/*  f14410c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f144110:	46003102 */ 	mul.s	$f4,$f6,$f0
/*  f144114:	03099821 */ 	addu	$s3,$t8,$t1
/*  f144118:	46002487 */ 	neg.s	$f18,$f4
/*  f14411c:	460a9403 */ 	div.s	$f16,$f18,$f10
/*  f144120:	e7b00074 */ 	swc1	$f16,0x74($sp)
.PF0f144124:
/*  f144124:	4614a002 */ 	mul.s	$f0,$f20,$f20
/*  f144128:	3c017f1b */ 	lui	$at,0x7f1b
/*  f14412c:	4618003c */ 	c.lt.s	$f0,$f24
/*  f144130:	00000000 */ 	nop
/*  f144134:	45000006 */ 	bc1f	.PF0f144150
/*  f144138:	00000000 */ 	nop
/*  f14413c:	0c0127b4 */ 	jal	sqrtf
/*  f144140:	4600c301 */ 	sub.s	$f12,$f24,$f0
/*  f144144:	46160082 */ 	mul.s	$f2,$f0,$f22
/*  f144148:	10000003 */ 	b	.PF0f144158
/*  f14414c:	c7a40100 */ 	lwc1	$f4,0x100($sp)
.PF0f144150:
/*  f144150:	c4227268 */ 	lwc1	$f2,0x7268($at)
/*  f144154:	c7a40100 */ 	lwc1	$f4,0x100($sp)
.PF0f144158:
/*  f144158:	c7a60074 */ 	lwc1	$f6,0x74($sp)
/*  f14415c:	02402025 */ 	move	$a0,$s2
/*  f144160:	46041002 */ 	mul.s	$f0,$f2,$f4
/*  f144164:	02002825 */ 	move	$a1,$s0
/*  f144168:	02a03825 */ 	move	$a3,$s5
/*  f14416c:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f144170:	4606a500 */ 	add.s	$f20,$f20,$f6
/*  f144174:	44060000 */ 	mfc1	$a2,$f0
/*  f144178:	0fc50a91 */ 	jal	bviewRenderFisheyeRect
/*  f14417c:	e7a00080 */ 	swc1	$f0,0x80($sp)
/*  f144180:	c7a00080 */ 	lwc1	$f0,0x80($sp)
/*  f144184:	12110008 */ 	beq	$s0,$s1,.PF0f1441a8
/*  f144188:	00409025 */ 	move	$s2,$v0
/*  f14418c:	44060000 */ 	mfc1	$a2,$f0
/*  f144190:	00402025 */ 	move	$a0,$v0
/*  f144194:	02202825 */ 	move	$a1,$s1
/*  f144198:	02a03825 */ 	move	$a3,$s5
/*  f14419c:	0fc50a91 */ 	jal	bviewRenderFisheyeRect
/*  f1441a0:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f1441a4:	00409025 */ 	move	$s2,$v0
.PF0f1441a8:
/*  f1441a8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1441ac:	0270082a */ 	slt	$at,$s3,$s0
/*  f1441b0:	1020ffdc */ 	beqz	$at,.PF0f144124
/*  f1441b4:	2631ffff */ 	addiu	$s1,$s1,-1
/*  f1441b8:	10000025 */ 	b	.PF0f144250
/*  f1441bc:	00000000 */ 	nop
/*  f1441c0:	8faf0130 */ 	lw	$t7,0x130($sp)
.PF0f1441c4:
/*  f1441c4:	00008825 */ 	move	$s1,$zero
/*  f1441c8:	c7aa0084 */ 	lwc1	$f10,0x84($sp)
/*  f1441cc:	01f7082a */ 	slt	$at,$t7,$s7
/*  f1441d0:	1020001f */ 	beqz	$at,.PF0f144250
/*  f1441d4:	00000000 */ 	nop
/*  f1441d8:	4616b200 */ 	add.s	$f8,$f22,$f22
/*  f1441dc:	4616b602 */ 	mul.s	$f24,$f22,$f22
/*  f1441e0:	46004487 */ 	neg.s	$f18,$f8
/*  f1441e4:	460a9503 */ 	div.s	$f20,$f18,$f10
/*  f1441e8:	4405a000 */ 	mfc1	$a1,$f20
.PF0f1441ec:
/*  f1441ec:	4406b000 */ 	mfc1	$a2,$f22
/*  f1441f0:	4407c000 */ 	mfc1	$a3,$f24
/*  f1441f4:	0fc50e39 */ 	jal	bview0f142d74
/*  f1441f8:	02202025 */ 	move	$a0,$s1
/*  f1441fc:	44060000 */ 	mfc1	$a2,$f0
/*  f144200:	02402025 */ 	move	$a0,$s2
/*  f144204:	02002825 */ 	move	$a1,$s0
/*  f144208:	02a03825 */ 	move	$a3,$s5
/*  f14420c:	0fc50a91 */ 	jal	bviewRenderFisheyeRect
/*  f144210:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f144214:	02338821 */ 	addu	$s1,$s1,$s3
/*  f144218:	44918000 */ 	mtc1	$s1,$f16
/*  f14421c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f144220:	00409025 */ 	move	$s2,$v0
/*  f144224:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f144228:	4606b03e */ 	c.le.s	$f22,$f6
/*  f14422c:	00000000 */ 	nop
/*  f144230:	45000005 */ 	bc1f	.PF0f144248
/*  f144234:	00000000 */ 	nop
/*  f144238:	4600b10d */ 	trunc.w.s	$f4,$f22
/*  f14423c:	00139823 */ 	negu	$s3,$s3
/*  f144240:	44112000 */ 	mfc1	$s1,$f4
/*  f144244:	00000000 */ 	nop
.PF0f144248:
/*  f144248:	5617ffe8 */ 	bnel	$s0,$s7,.PF0f1441ec
/*  f14424c:	4405a000 */ 	mfc1	$a1,$f20
.PF0f144250:
/*  f144250:	0c002e95 */ 	jal	viGetViewTop
/*  f144254:	00000000 */ 	nop
/*  f144258:	0c002e77 */ 	jal	viGetViewHeight
/*  f14425c:	00409825 */ 	move	$s3,$v0
/*  f144260:	8fa800ec */ 	lw	$t0,0xec($sp)
/*  f144264:	00537021 */ 	addu	$t6,$v0,$s3
/*  f144268:	00008025 */ 	move	$s0,$zero
/*  f14426c:	19000023 */ 	blez	$t0,.PF0f1442fc
/*  f144270:	01c88823 */ 	subu	$s1,$t6,$t0
/*  f144274:	02b63021 */ 	addu	$a2,$s5,$s6
/*  f144278:	30c903ff */ 	andi	$t1,$a2,0x3ff
/*  f14427c:	32a703ff */ 	andi	$a3,$s5,0x3ff
/*  f144280:	0007cb80 */ 	sll	$t9,$a3,0xe
/*  f144284:	0009c380 */ 	sll	$t8,$t1,0xe
/*  f144288:	3c01f600 */ 	lui	$at,0xf600
/*  f14428c:	03013025 */ 	or	$a2,$t8,$at
/*  f144290:	03203825 */ 	move	$a3,$t9
.PF0f144294:
/*  f144294:	26630001 */ 	addiu	$v1,$s3,0x1
/*  f144298:	306b03ff */ 	andi	$t3,$v1,0x3ff
/*  f14429c:	000b6880 */ 	sll	$t5,$t3,0x2
/*  f1442a0:	00cd7825 */ 	or	$t7,$a2,$t5
/*  f1442a4:	02401025 */ 	move	$v0,$s2
/*  f1442a8:	326c03ff */ 	andi	$t4,$s3,0x3ff
/*  f1442ac:	26250001 */ 	addiu	$a1,$s1,0x1
/*  f1442b0:	000c7080 */ 	sll	$t6,$t4,0x2
/*  f1442b4:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f1442b8:	30b803ff */ 	andi	$t8,$a1,0x3ff
/*  f1442bc:	322b03ff */ 	andi	$t3,$s1,0x3ff
/*  f1442c0:	00ee4825 */ 	or	$t1,$a3,$t6
/*  f1442c4:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f1442c8:	000b6880 */ 	sll	$t5,$t3,0x2
/*  f1442cc:	00185080 */ 	sll	$t2,$t8,0x2
/*  f1442d0:	02402025 */ 	move	$a0,$s2
/*  f1442d4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1442d8:	ac490004 */ 	sw	$t1,0x4($v0)
/*  f1442dc:	00cac825 */ 	or	$t9,$a2,$t2
/*  f1442e0:	00ed7825 */ 	or	$t7,$a3,$t5
/*  f1442e4:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f1442e8:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f1442ec:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f1442f0:	00609825 */ 	move	$s3,$v1
/*  f1442f4:	1608ffe7 */ 	bne	$s0,$t0,.PF0f144294
/*  f1442f8:	00a08825 */ 	move	$s1,$a1
.PF0f1442fc:
/*  f1442fc:	02401025 */ 	move	$v0,$s2
.PF0f144300:
/*  f144300:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f144304:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f144308:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f14430c:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f144310:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f144314:	8fb10044 */ 	lw	$s1,0x44($sp)
/*  f144318:	8fb20048 */ 	lw	$s2,0x48($sp)
/*  f14431c:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*  f144320:	8fb40050 */ 	lw	$s4,0x50($sp)
/*  f144324:	8fb50054 */ 	lw	$s5,0x54($sp)
/*  f144328:	8fb60058 */ 	lw	$s6,0x58($sp)
/*  f14432c:	8fb7005c */ 	lw	$s7,0x5c($sp)
/*  f144330:	8fbe0060 */ 	lw	$s8,0x60($sp)
/*  f144334:	03e00008 */ 	jr	$ra
/*  f144338:	27bd0138 */ 	addiu	$sp,$sp,0x138
);
#else
GLOBAL_ASM(
glabel bviewRenderFisheye
.late_rodata
glabel var7f1b5f40
.word 0x3f83d70a
glabel var7f1b5f44
.word 0x3bcccccd
glabel var7f1b5f48
.word 0x3c23d70a
.text
/*  f142e00:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f142e04:	afbf007c */ 	sw	$ra,0x7c($sp)
/*  f142e08:	afb70074 */ 	sw	$s7,0x74($sp)
/*  f142e0c:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f142e10:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f142e14:	00c08025 */ 	or	$s0,$a2,$zero
/*  f142e18:	00808825 */ 	or	$s1,$a0,$zero
/*  f142e1c:	00a0b825 */ 	or	$s7,$a1,$zero
/*  f142e20:	afbe0078 */ 	sw	$s8,0x78($sp)
/*  f142e24:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f142e28:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f142e2c:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f142e30:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f142e34:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f142e38:	f7be0050 */ 	sdc1	$f30,0x50($sp)
/*  f142e3c:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f142e40:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f142e44:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f142e48:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f142e4c:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f142e50:	0c002ac7 */ 	jal	viGetUnk28
/*  f142e54:	afa7013c */ 	sw	$a3,0x13c($sp)
/*  f142e58:	0c002f44 */ 	jal	viGetViewTop
/*  f142e5c:	afa2012c */ 	sw	$v0,0x12c($sp)
/*  f142e60:	0c002f26 */ 	jal	viGetViewHeight
/*  f142e64:	afa20128 */ 	sw	$v0,0x128($sp)
/*  f142e68:	44822000 */ 	mtc1	$v0,$f4
/*  f142e6c:	3c013f00 */ 	lui	$at,0x3f00
/*  f142e70:	44813000 */ 	mtc1	$at,$f6
/*  f142e74:	468020a0 */ 	cvt.s.w	$f2,$f4
/*  f142e78:	afa20124 */ 	sw	$v0,0x124($sp)
/*  f142e7c:	46061702 */ 	mul.s	$f28,$f2,$f6
/*  f142e80:	461ce200 */ 	add.s	$f8,$f28,$f28
/*  f142e84:	461ce602 */ 	mul.s	$f24,$f28,$f28
/*  f142e88:	46004287 */ 	neg.s	$f10,$f8
/*  f142e8c:	0c002f22 */ 	jal	viGetViewWidth
/*  f142e90:	46025683 */ 	div.s	$f26,$f10,$f2
/*  f142e94:	0c002f40 */ 	jal	viGetViewLeft
/*  f142e98:	0040b025 */ 	or	$s6,$v0,$zero
/*  f142e9c:	3c038008 */ 	lui	$v1,%hi(var8007f840)
/*  f142ea0:	2463f840 */ 	addiu	$v1,$v1,%lo(var8007f840)
/*  f142ea4:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f142ea8:	3c013f80 */ 	lui	$at,0x3f80
/*  f142eac:	4481f000 */ 	mtc1	$at,$f30
/*  f142eb0:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f142eb4:	29e10002 */ 	slti	$at,$t7,0x2
/*  f142eb8:	0040a825 */ 	or	$s5,$v0,$zero
/*  f142ebc:	00009025 */ 	or	$s2,$zero,$zero
/*  f142ec0:	14200003 */ 	bnez	$at,.L0f142ed0
/*  f142ec4:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f142ec8:	100001d9 */ 	b	.L0f143630
/*  f142ecc:	02201025 */ 	or	$v0,$s1,$zero
.L0f142ed0:
/*  f142ed0:	3c04800a */ 	lui	$a0,%hi(var800a41c0)
/*  f142ed4:	3c057f1b */ 	lui	$a1,%hi(var7f1b5dd4)
/*  f142ed8:	24a55dd4 */ 	addiu	$a1,$a1,%lo(var7f1b5dd4)
/*  f142edc:	0c004c4c */ 	jal	strcpy
/*  f142ee0:	248441c0 */ 	addiu	$a0,$a0,%lo(var800a41c0)
/*  f142ee4:	83a30143 */ 	lb	$v1,0x143($sp)
/*  f142ee8:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f142eec:	26240008 */ 	addiu	$a0,$s1,0x8
/*  f142ef0:	28670032 */ 	slti	$a3,$v1,0x32
/*  f142ef4:	30f900ff */ 	andi	$t9,$a3,0xff
/*  f142ef8:	1320001d */ 	beqz	$t9,.L0f142f70
/*  f142efc:	03203825 */ 	or	$a3,$t9,$zero
/*  f142f00:	44833000 */ 	mtc1	$v1,$f6
/*  f142f04:	3c013f00 */ 	lui	$at,0x3f00
/*  f142f08:	44812000 */ 	mtc1	$at,$f4
/*  f142f0c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f142f10:	3c014248 */ 	lui	$at,0x4248
/*  f142f14:	44815000 */ 	mtc1	$at,$f10
/*  f142f18:	8fa80124 */ 	lw	$t0,0x124($sp)
/*  f142f1c:	3c01437f */ 	lui	$at,0x437f
/*  f142f20:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f142f24:	460a4783 */ 	div.s	$f30,$f8,$f10
/*  f142f28:	44888000 */ 	mtc1	$t0,$f16
/*  f142f2c:	00000000 */ 	nop
/*  f142f30:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f142f34:	46049582 */ 	mul.s	$f22,$f18,$f4
/*  f142f38:	44812000 */ 	mtc1	$at,$f4
/*  f142f3c:	461eb402 */ 	mul.s	$f16,$f22,$f30
/*  f142f40:	e7b600f4 */ 	swc1	$f22,0xf4($sp)
/*  f142f44:	4604f182 */ 	mul.s	$f6,$f30,$f4
/*  f142f48:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f142f4c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f142f50:	440a9000 */ 	mfc1	$t2,$f18
/*  f142f54:	44024000 */ 	mfc1	$v0,$f8
/*  f142f58:	afaa00fc */ 	sw	$t2,0xfc($sp)
/*  f142f5c:	28410100 */ 	slti	$at,$v0,0x100
/*  f142f60:	14200003 */ 	bnez	$at,.L0f142f70
/*  f142f64:	afa200ec */ 	sw	$v0,0xec($sp)
/*  f142f68:	afac00ec */ 	sw	$t4,0xec($sp)
/*  f142f6c:	e7b600f4 */ 	swc1	$f22,0xf4($sp)
.L0f142f70:
/*  f142f70:	c7b600f4 */ 	lwc1	$f22,0xf4($sp)
/*  f142f74:	02201025 */ 	or	$v0,$s1,$zero
/*  f142f78:	3c0de700 */ 	lui	$t5,0xe700
/*  f142f7c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f142f80:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f142f84:	afa70084 */ 	sw	$a3,0x84($sp)
/*  f142f88:	02e02825 */ 	or	$a1,$s7,$zero
/*  f142f8c:	0fc5082c */ 	jal	bviewPrepareStaticRgba16
/*  f142f90:	02003025 */ 	or	$a2,$s0,$zero
/*  f142f94:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f142f98:	00408825 */ 	or	$s1,$v0,$zero
/*  f142f9c:	8fb00128 */ 	lw	$s0,0x128($sp)
/*  f142fa0:	11c00055 */ 	beqz	$t6,.L0f1430f8
/*  f142fa4:	8faf0124 */ 	lw	$t7,0x124($sp)
/*  f142fa8:	8fa30128 */ 	lw	$v1,0x128($sp)
/*  f142fac:	8faf0124 */ 	lw	$t7,0x124($sp)
/*  f142fb0:	00608025 */ 	or	$s0,$v1,$zero
/*  f142fb4:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f142fb8:	0078082a */ 	slt	$at,$v1,$t8
/*  f142fbc:	102000d4 */ 	beqz	$at,.L0f143310
/*  f142fc0:	afb80094 */ 	sw	$t8,0x94($sp)
/*  f142fc4:	448f5000 */ 	mtc1	$t7,$f10
/*  f142fc8:	3c013f00 */ 	lui	$at,0x3f00
/*  f142fcc:	44819000 */ 	mtc1	$at,$f18
/*  f142fd0:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f142fd4:	241eff00 */ 	addiu	$s8,$zero,-256
/*  f142fd8:	3c14fb00 */ 	lui	$s4,0xfb00
/*  f142fdc:	46128502 */ 	mul.s	$f20,$f16,$f18
/*  f142fe0:	00000000 */ 	nop
.L0f142fe4:
/*  f142fe4:	06010004 */ 	bgez	$s0,.L0f142ff8
/*  f142fe8:	32080001 */ 	andi	$t0,$s0,0x1
/*  f142fec:	11000002 */ 	beqz	$t0,.L0f142ff8
/*  f142ff0:	00000000 */ 	nop
/*  f142ff4:	2508fffe */ 	addiu	$t0,$t0,-2
.L0f142ff8:
/*  f142ff8:	5100002e */ 	beqzl	$t0,.L0f1430b4
/*  f142ffc:	02539021 */ 	addu	$s2,$s2,$s3
/*  f143000:	44832000 */ 	mtc1	$v1,$f4
/*  f143004:	8fa900fc */ 	lw	$t1,0xfc($sp)
/*  f143008:	44905000 */ 	mtc1	$s0,$f10
/*  f14300c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f143010:	44894000 */ 	mtc1	$t1,$f8
/*  f143014:	00000000 */ 	nop
/*  f143018:	468040a0 */ 	cvt.s.w	$f2,$f8
/*  f14301c:	46163000 */ 	add.s	$f0,$f6,$f22
/*  f143020:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f143024:	46020401 */ 	sub.s	$f16,$f0,$f2
/*  f143028:	460c803c */ 	c.lt.s	$f16,$f12
/*  f14302c:	00000000 */ 	nop
/*  f143030:	45020020 */ 	bc1fl	.L0f1430b4
/*  f143034:	02539021 */ 	addu	$s2,$s2,$s3
/*  f143038:	46020480 */ 	add.s	$f18,$f0,$f2
/*  f14303c:	02201025 */ 	or	$v0,$s1,$zero
/*  f143040:	02fe5024 */ 	and	$t2,$s7,$s8
/*  f143044:	02402025 */ 	or	$a0,$s2,$zero
/*  f143048:	4612603c */ 	c.lt.s	$f12,$f18
/*  f14304c:	00000000 */ 	nop
/*  f143050:	45020018 */ 	bc1fl	.L0f1430b4
/*  f143054:	02539021 */ 	addu	$s2,$s2,$s3
/*  f143058:	ac540000 */ 	sw	$s4,0x0($v0)
/*  f14305c:	8fab00ec */ 	lw	$t3,0xec($sp)
/*  f143060:	4405d000 */ 	mfc1	$a1,$f26
/*  f143064:	4406e000 */ 	mfc1	$a2,$f28
/*  f143068:	316c00ff */ 	andi	$t4,$t3,0xff
/*  f14306c:	014c6825 */ 	or	$t5,$t2,$t4
/*  f143070:	4407c000 */ 	mfc1	$a3,$f24
/*  f143074:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f143078:	0fc50b5d */ 	jal	bview0f142d74
/*  f14307c:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f143080:	461e0102 */ 	mul.s	$f4,$f0,$f30
/*  f143084:	02202025 */ 	or	$a0,$s1,$zero
/*  f143088:	8fa5012c */ 	lw	$a1,0x12c($sp)
/*  f14308c:	02003025 */ 	or	$a2,$s0,$zero
/*  f143090:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f143094:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f143098:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f14309c:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f1430a0:	0fc506ac */ 	jal	bviewRenderLensRect
/*  f1430a4:	afb6001c */ 	sw	$s6,0x1c($sp)
/*  f1430a8:	00408825 */ 	or	$s1,$v0,$zero
/*  f1430ac:	8fa30128 */ 	lw	$v1,0x128($sp)
/*  f1430b0:	02539021 */ 	addu	$s2,$s2,$s3
.L0f1430b4:
/*  f1430b4:	44923000 */ 	mtc1	$s2,$f6
/*  f1430b8:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f1430bc:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1430c0:	4608a03e */ 	c.le.s	$f20,$f8
/*  f1430c4:	00000000 */ 	nop
/*  f1430c8:	45020006 */ 	bc1fl	.L0f1430e4
/*  f1430cc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1430d0:	4600a28d */ 	trunc.w.s	$f10,$f20
/*  f1430d4:	00139823 */ 	negu	$s3,$s3
/*  f1430d8:	44125000 */ 	mfc1	$s2,$f10
/*  f1430dc:	00000000 */ 	nop
/*  f1430e0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1430e4:
/*  f1430e4:	1618ffbf */ 	bne	$s0,$t8,.L0f142fe4
/*  f1430e8:	00000000 */ 	nop
/*  f1430ec:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f1430f0:	10000087 */ 	b	.L0f143310
/*  f1430f4:	00608025 */ 	or	$s0,$v1,$zero
.L0f1430f8:
/*  f1430f8:	3c013f80 */ 	lui	$at,0x3f80
/*  f1430fc:	4481b000 */ 	mtc1	$at,$f22
/*  f143100:	020f4021 */ 	addu	$t0,$s0,$t7
/*  f143104:	0208082a */ 	slt	$at,$s0,$t0
/*  f143108:	10200081 */ 	beqz	$at,.L0f143310
/*  f14310c:	afa80094 */ 	sw	$t0,0x94($sp)
/*  f143110:	448f8000 */ 	mtc1	$t7,$f16
/*  f143114:	3c013f00 */ 	lui	$at,0x3f00
/*  f143118:	44812000 */ 	mtc1	$at,$f4
/*  f14311c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f143120:	93be0147 */ 	lbu	$s8,0x147($sp)
/*  f143124:	3c14fb00 */ 	lui	$s4,0xfb00
/*  f143128:	46049502 */ 	mul.s	$f20,$f18,$f4
/*  f14312c:	00000000 */ 	nop
.L0f143130:
/*  f143130:	24010004 */ 	addiu	$at,$zero,0x4
/*  f143134:	17c1001f */ 	bne	$s8,$at,.L0f1431b4
/*  f143138:	02201025 */ 	or	$v0,$s1,$zero
/*  f14313c:	0c004b70 */ 	jal	random
/*  f143140:	00000000 */ 	nop
/*  f143144:	24010078 */ 	addiu	$at,$zero,0x78
/*  f143148:	0041001b */ 	divu	$zero,$v0,$at
/*  f14314c:	0000b810 */ 	mfhi	$s7
/*  f143150:	26e90078 */ 	addiu	$t1,$s7,0x78
/*  f143154:	3c01ff33 */ 	lui	$at,0xff33
/*  f143158:	34213300 */ 	ori	$at,$at,0x3300
/*  f14315c:	312b00ff */ 	andi	$t3,$t1,0xff
/*  f143160:	0c004b70 */ 	jal	random
/*  f143164:	0161b825 */ 	or	$s7,$t3,$at
/*  f143168:	304c001f */ 	andi	$t4,$v0,0x1f
/*  f14316c:	448c3000 */ 	mtc1	$t4,$f6
/*  f143170:	3c014f80 */ 	lui	$at,0x4f80
/*  f143174:	05810004 */ 	bgez	$t4,.L0f143188
/*  f143178:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f14317c:	44815000 */ 	mtc1	$at,$f10
/*  f143180:	00000000 */ 	nop
/*  f143184:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f143188:
/*  f143188:	3c01435c */ 	lui	$at,0x435c
/*  f14318c:	44818000 */ 	mtc1	$at,$f16
/*  f143190:	3c013b80 */ 	lui	$at,0x3b80
/*  f143194:	44812000 */ 	mtc1	$at,$f4
/*  f143198:	46104480 */ 	add.s	$f18,$f8,$f16
/*  f14319c:	02201825 */ 	or	$v1,$s1,$zero
/*  f1431a0:	ac740000 */ 	sw	$s4,0x0($v1)
/*  f1431a4:	ac770004 */ 	sw	$s7,0x4($v1)
/*  f1431a8:	46049582 */ 	mul.s	$f22,$f18,$f4
/*  f1431ac:	10000005 */ 	b	.L0f1431c4
/*  f1431b0:	26310008 */ 	addiu	$s1,$s1,0x8
.L0f1431b4:
/*  f1431b4:	240dffff */ 	addiu	$t5,$zero,-1
/*  f1431b8:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f1431bc:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f1431c0:	ac540000 */ 	sw	$s4,0x0($v0)
.L0f1431c4:
/*  f1431c4:	4405d000 */ 	mfc1	$a1,$f26
/*  f1431c8:	4406e000 */ 	mfc1	$a2,$f28
/*  f1431cc:	4407c000 */ 	mfc1	$a3,$f24
/*  f1431d0:	0fc50b5d */ 	jal	bview0f142d74
/*  f1431d4:	02402025 */ 	or	$a0,$s2,$zero
/*  f1431d8:	46160182 */ 	mul.s	$f6,$f0,$f22
/*  f1431dc:	02202025 */ 	or	$a0,$s1,$zero
/*  f1431e0:	8fa5012c */ 	lw	$a1,0x12c($sp)
/*  f1431e4:	02003025 */ 	or	$a2,$s0,$zero
/*  f1431e8:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f1431ec:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f1431f0:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f1431f4:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f1431f8:	0fc506ac */ 	jal	bviewRenderLensRect
/*  f1431fc:	afb6001c */ 	sw	$s6,0x1c($sp)
/*  f143200:	24010004 */ 	addiu	$at,$zero,0x4
/*  f143204:	17c10019 */ 	bne	$s8,$at,.L0f14326c
/*  f143208:	00408825 */ 	or	$s1,$v0,$zero
/*  f14320c:	02201025 */ 	or	$v0,$s1,$zero
/*  f143210:	3c0eddaa */ 	lui	$t6,0xddaa
/*  f143214:	35ceaa99 */ 	ori	$t6,$t6,0xaa99
/*  f143218:	4405d000 */ 	mfc1	$a1,$f26
/*  f14321c:	4406e000 */ 	mfc1	$a2,$f28
/*  f143220:	4407c000 */ 	mfc1	$a3,$f24
/*  f143224:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f143228:	ac540000 */ 	sw	$s4,0x0($v0)
/*  f14322c:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f143230:	0fc50b5d */ 	jal	bview0f142d74
/*  f143234:	02402025 */ 	or	$a0,$s2,$zero
/*  f143238:	3c017f1b */ 	lui	$at,%hi(var7f1b5f40)
/*  f14323c:	c42a5f40 */ 	lwc1	$f10,%lo(var7f1b5f40)($at)
/*  f143240:	02202025 */ 	or	$a0,$s1,$zero
/*  f143244:	8fa5012c */ 	lw	$a1,0x12c($sp)
/*  f143248:	460a0202 */ 	mul.s	$f8,$f0,$f10
/*  f14324c:	02003025 */ 	or	$a2,$s0,$zero
/*  f143250:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f143254:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f143258:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f14325c:	afb6001c */ 	sw	$s6,0x1c($sp)
/*  f143260:	0fc506ac */ 	jal	bviewRenderLensRect
/*  f143264:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f143268:	00408825 */ 	or	$s1,$v0,$zero
.L0f14326c:
/*  f14326c:	32180001 */ 	andi	$t8,$s0,0x1
/*  f143270:	17000017 */ 	bnez	$t8,.L0f1432d0
/*  f143274:	02539021 */ 	addu	$s2,$s2,$s3
/*  f143278:	02b64021 */ 	addu	$t0,$s5,$s6
/*  f14327c:	310f03ff */ 	andi	$t7,$t0,0x3ff
/*  f143280:	24510008 */ 	addiu	$s1,$v0,0x8
/*  f143284:	24190055 */ 	addiu	$t9,$zero,0x55
/*  f143288:	000f4b80 */ 	sll	$t1,$t7,0xe
/*  f14328c:	3c01f600 */ 	lui	$at,0xf600
/*  f143290:	260a0001 */ 	addiu	$t2,$s0,0x1
/*  f143294:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f143298:	314c03ff */ 	andi	$t4,$t2,0x3ff
/*  f14329c:	01215825 */ 	or	$t3,$t1,$at
/*  f1432a0:	02202025 */ 	or	$a0,$s1,$zero
/*  f1432a4:	320803ff */ 	andi	$t0,$s0,0x3ff
/*  f1432a8:	32b803ff */ 	andi	$t8,$s5,0x3ff
/*  f1432ac:	ac540000 */ 	sw	$s4,0x0($v0)
/*  f1432b0:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f1432b4:	00087880 */ 	sll	$t7,$t0,0x2
/*  f1432b8:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f1432bc:	016d7025 */ 	or	$t6,$t3,$t5
/*  f1432c0:	032f4825 */ 	or	$t1,$t9,$t7
/*  f1432c4:	ac890004 */ 	sw	$t1,0x4($a0)
/*  f1432c8:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1432cc:	26310008 */ 	addiu	$s1,$s1,0x8
.L0f1432d0:
/*  f1432d0:	44928000 */ 	mtc1	$s2,$f16
/*  f1432d4:	8fac0094 */ 	lw	$t4,0x94($sp)
/*  f1432d8:	26020001 */ 	addiu	$v0,$s0,0x1
/*  f1432dc:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f1432e0:	4612a03e */ 	c.le.s	$f20,$f18
/*  f1432e4:	00000000 */ 	nop
/*  f1432e8:	45000005 */ 	bc1f	.L0f143300
/*  f1432ec:	00000000 */ 	nop
/*  f1432f0:	4600a10d */ 	trunc.w.s	$f4,$f20
/*  f1432f4:	00139823 */ 	negu	$s3,$s3
/*  f1432f8:	44122000 */ 	mfc1	$s2,$f4
/*  f1432fc:	00000000 */ 	nop
.L0f143300:
/*  f143300:	144cff8b */ 	bne	$v0,$t4,.L0f143130
/*  f143304:	00408025 */ 	or	$s0,$v0,$zero
/*  f143308:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f14330c:	8fb00128 */ 	lw	$s0,0x128($sp)
.L0f143310:
/*  f143310:	02201025 */ 	or	$v0,$s1,$zero
/*  f143314:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f143318:	3c0be700 */ 	lui	$t3,0xe700
/*  f14331c:	02201825 */ 	or	$v1,$s1,$zero
/*  f143320:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f143324:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f143328:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f14332c:	3c0dba00 */ 	lui	$t5,0xba00
/*  f143330:	35ad1402 */ 	ori	$t5,$t5,0x1402
/*  f143334:	02202025 */ 	or	$a0,$s1,$zero
/*  f143338:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f14333c:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f143340:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f143344:	3c0eb900 */ 	lui	$t6,0xb900
/*  f143348:	3c180050 */ 	lui	$t8,0x50
/*  f14334c:	37184240 */ 	ori	$t8,$t8,0x4240
/*  f143350:	35ce031d */ 	ori	$t6,$t6,0x31d
/*  f143354:	02202825 */ 	or	$a1,$s1,$zero
/*  f143358:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f14335c:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f143360:	3c08fcff */ 	lui	$t0,0xfcff
/*  f143364:	3c19fffd */ 	lui	$t9,0xfffd
/*  f143368:	3739f6fb */ 	ori	$t9,$t9,0xf6fb
/*  f14336c:	3508ffff */ 	ori	$t0,$t0,0xffff
/*  f143370:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f143374:	aca80000 */ 	sw	$t0,0x0($a1)
/*  f143378:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f14337c:	02203025 */ 	or	$a2,$s1,$zero
/*  f143380:	3c0ffa00 */ 	lui	$t7,0xfa00
/*  f143384:	240900ff */ 	addiu	$t1,$zero,0xff
/*  f143388:	acc90004 */ 	sw	$t1,0x4($a2)
/*  f14338c:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f143390:	8fa3013c */ 	lw	$v1,0x13c($sp)
/*  f143394:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f143398:	8faa0084 */ 	lw	$t2,0x84($sp)
/*  f14339c:	14600003 */ 	bnez	$v1,.L0f1433ac
/*  f1433a0:	8fac0124 */ 	lw	$t4,0x124($sp)
/*  f1433a4:	1140007a */ 	beqz	$t2,.L0f143590
/*  f1433a8:	8fb90128 */ 	lw	$t9,0x128($sp)
.L0f1433ac:
/*  f1433ac:	448c3000 */ 	mtc1	$t4,$f6
/*  f1433b0:	3c013f00 */ 	lui	$at,0x3f00
/*  f1433b4:	44814000 */ 	mtc1	$at,$f8
/*  f1433b8:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f1433bc:	8fad0084 */ 	lw	$t5,0x84($sp)
/*  f1433c0:	2463fff4 */ 	addiu	$v1,$v1,-12
/*  f1433c4:	8fb700fc */ 	lw	$s7,0xfc($sp)
/*  f1433c8:	8faf0124 */ 	lw	$t7,0x124($sp)
/*  f1433cc:	46085402 */ 	mul.s	$f16,$f10,$f8
/*  f1433d0:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f1433d4:	44029000 */ 	mfc1	$v0,$f18
/*  f1433d8:	15a00011 */ 	bnez	$t5,.L0f143420
/*  f1433dc:	afa200a8 */ 	sw	$v0,0xa8($sp)
/*  f1433e0:	04630003 */ 	bgezl	$v1,.L0f1433f0
/*  f1433e4:	44832000 */ 	mtc1	$v1,$f4
/*  f1433e8:	00031823 */ 	negu	$v1,$v1
/*  f1433ec:	44832000 */ 	mtc1	$v1,$f4
.L0f1433f0:
/*  f1433f0:	3c014140 */ 	lui	$at,0x4140
/*  f1433f4:	44815000 */ 	mtc1	$at,$f10
/*  f1433f8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1433fc:	44828000 */ 	mtc1	$v0,$f16
/*  f143400:	00000000 */ 	nop
/*  f143404:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f143408:	460a3203 */ 	div.s	$f8,$f6,$f10
/*  f14340c:	46089102 */ 	mul.s	$f4,$f18,$f8
/*  f143410:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f143414:	44173000 */ 	mfc1	$s7,$f6
/*  f143418:	10000002 */ 	b	.L0f143424
/*  f14341c:	8fa30128 */ 	lw	$v1,0x128($sp)
.L0f143420:
/*  f143420:	8fa30128 */ 	lw	$v1,0x128($sp)
.L0f143424:
/*  f143424:	8fb800a8 */ 	lw	$t8,0xa8($sp)
/*  f143428:	0062f021 */ 	addu	$s8,$v1,$v0
/*  f14342c:	03d7a023 */ 	subu	$s4,$s8,$s7
/*  f143430:	0074082a */ 	slt	$at,$v1,$s4
/*  f143434:	10200017 */ 	beqz	$at,.L0f143494
/*  f143438:	00784021 */ 	addu	$t0,$v1,$t8
/*  f14343c:	0063c821 */ 	addu	$t9,$v1,$v1
/*  f143440:	032f4821 */ 	addu	$t1,$t9,$t7
/*  f143444:	4480a000 */ 	mtc1	$zero,$f20
/*  f143448:	01309023 */ 	subu	$s2,$t1,$s0
/*  f14344c:	01179823 */ 	subu	$s3,$t0,$s7
.L0f143450:
/*  f143450:	4406a000 */ 	mfc1	$a2,$f20
/*  f143454:	02202025 */ 	or	$a0,$s1,$zero
/*  f143458:	02002825 */ 	or	$a1,$s0,$zero
/*  f14345c:	02a03825 */ 	or	$a3,$s5,$zero
/*  f143460:	0fc507b5 */ 	jal	bviewRenderFisheyeRect
/*  f143464:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f143468:	4406a000 */ 	mfc1	$a2,$f20
/*  f14346c:	00402025 */ 	or	$a0,$v0,$zero
/*  f143470:	02402825 */ 	or	$a1,$s2,$zero
/*  f143474:	02a03825 */ 	or	$a3,$s5,$zero
/*  f143478:	0fc507b5 */ 	jal	bviewRenderFisheyeRect
/*  f14347c:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f143480:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f143484:	2652ffff */ 	addiu	$s2,$s2,-1
/*  f143488:	1613fff1 */ 	bne	$s0,$s3,.L0f143450
/*  f14348c:	00408825 */ 	or	$s1,$v0,$zero
/*  f143490:	8fa30128 */ 	lw	$v1,0x128($sp)
.L0f143494:
/*  f143494:	02201025 */ 	or	$v0,$s1,$zero
/*  f143498:	3c0afa00 */ 	lui	$t2,0xfa00
/*  f14349c:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f1434a0:	03d4082a */ 	slt	$at,$s8,$s4
/*  f1434a4:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f1434a8:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f1434ac:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f1434b0:	4600e506 */ 	mov.s	$f20,$f28
/*  f1434b4:	1420005d */ 	bnez	$at,.L0f14362c
/*  f1434b8:	02808025 */ 	or	$s0,$s4,$zero
/*  f1434bc:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f1434c0:	44885000 */ 	mtc1	$t0,$f10
/*  f1434c4:	44972000 */ 	mtc1	$s7,$f4
/*  f1434c8:	8fae0124 */ 	lw	$t6,0x124($sp)
/*  f1434cc:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f1434d0:	8fab00a8 */ 	lw	$t3,0xa8($sp)
/*  f1434d4:	00636821 */ 	addu	$t5,$v1,$v1
/*  f1434d8:	3c017f1b */ 	lui	$at,%hi(var7f1b5f44)
/*  f1434dc:	01aec021 */ 	addu	$t8,$t5,$t6
/*  f1434e0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1434e4:	461c8482 */ 	mul.s	$f18,$f16,$f28
/*  f1434e8:	03149023 */ 	subu	$s2,$t8,$s4
/*  f1434ec:	c4365f44 */ 	lwc1	$f22,%lo(var7f1b5f44)($at)
/*  f1434f0:	006b9821 */ 	addu	$s3,$v1,$t3
/*  f1434f4:	46009207 */ 	neg.s	$f8,$f18
/*  f1434f8:	46064683 */ 	div.s	$f26,$f8,$f6
.L0f1434fc:
/*  f1434fc:	4614a002 */ 	mul.s	$f0,$f20,$f20
/*  f143500:	3c017f1b */ 	lui	$at,%hi(var7f1b5f48)
/*  f143504:	4618003c */ 	c.lt.s	$f0,$f24
/*  f143508:	00000000 */ 	nop
/*  f14350c:	45000006 */ 	bc1f	.L0f143528
/*  f143510:	00000000 */ 	nop
/*  f143514:	0c012974 */ 	jal	sqrtf
/*  f143518:	4600c301 */ 	sub.s	$f12,$f24,$f0
/*  f14351c:	46160082 */ 	mul.s	$f2,$f0,$f22
/*  f143520:	10000002 */ 	b	.L0f14352c
/*  f143524:	00000000 */ 	nop
.L0f143528:
/*  f143528:	c4225f48 */ 	lwc1	$f2,%lo(var7f1b5f48)($at)
.L0f14352c:
/*  f14352c:	461e1002 */ 	mul.s	$f0,$f2,$f30
/*  f143530:	461aa500 */ 	add.s	$f20,$f20,$f26
/*  f143534:	02202025 */ 	or	$a0,$s1,$zero
/*  f143538:	02002825 */ 	or	$a1,$s0,$zero
/*  f14353c:	02a03825 */ 	or	$a3,$s5,$zero
/*  f143540:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f143544:	44060000 */ 	mfc1	$a2,$f0
/*  f143548:	0fc507b5 */ 	jal	bviewRenderFisheyeRect
/*  f14354c:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f143550:	c7a00090 */ 	lwc1	$f0,0x90($sp)
/*  f143554:	12120008 */ 	beq	$s0,$s2,.L0f143578
/*  f143558:	00408825 */ 	or	$s1,$v0,$zero
/*  f14355c:	44060000 */ 	mfc1	$a2,$f0
/*  f143560:	00402025 */ 	or	$a0,$v0,$zero
/*  f143564:	02402825 */ 	or	$a1,$s2,$zero
/*  f143568:	02a03825 */ 	or	$a3,$s5,$zero
/*  f14356c:	0fc507b5 */ 	jal	bviewRenderFisheyeRect
/*  f143570:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f143574:	00408825 */ 	or	$s1,$v0,$zero
.L0f143578:
/*  f143578:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f14357c:	0270082a */ 	slt	$at,$s3,$s0
/*  f143580:	1020ffde */ 	beqz	$at,.L0f1434fc
/*  f143584:	2652ffff */ 	addiu	$s2,$s2,-1
/*  f143588:	10000029 */ 	b	.L0f143630
/*  f14358c:	02201025 */ 	or	$v0,$s1,$zero
.L0f143590:
/*  f143590:	8faf0094 */ 	lw	$t7,0x94($sp)
/*  f143594:	00009025 */ 	or	$s2,$zero,$zero
/*  f143598:	8fa90124 */ 	lw	$t1,0x124($sp)
/*  f14359c:	032f082a */ 	slt	$at,$t9,$t7
/*  f1435a0:	50200023 */ 	beqzl	$at,.L0f143630
/*  f1435a4:	02201025 */ 	or	$v0,$s1,$zero
/*  f1435a8:	44895000 */ 	mtc1	$t1,$f10
/*  f1435ac:	3c013f00 */ 	lui	$at,0x3f00
/*  f1435b0:	44819000 */ 	mtc1	$at,$f18
/*  f1435b4:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f1435b8:	46128502 */ 	mul.s	$f20,$f16,$f18
/*  f1435bc:	00000000 */ 	nop
/*  f1435c0:	4405d000 */ 	mfc1	$a1,$f26
.L0f1435c4:
/*  f1435c4:	4406e000 */ 	mfc1	$a2,$f28
/*  f1435c8:	4407c000 */ 	mfc1	$a3,$f24
/*  f1435cc:	0fc50b5d */ 	jal	bview0f142d74
/*  f1435d0:	02402025 */ 	or	$a0,$s2,$zero
/*  f1435d4:	44060000 */ 	mfc1	$a2,$f0
/*  f1435d8:	02202025 */ 	or	$a0,$s1,$zero
/*  f1435dc:	02002825 */ 	or	$a1,$s0,$zero
/*  f1435e0:	02a03825 */ 	or	$a3,$s5,$zero
/*  f1435e4:	0fc507b5 */ 	jal	bviewRenderFisheyeRect
/*  f1435e8:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f1435ec:	02539021 */ 	addu	$s2,$s2,$s3
/*  f1435f0:	44922000 */ 	mtc1	$s2,$f4
/*  f1435f4:	8fac0094 */ 	lw	$t4,0x94($sp)
/*  f1435f8:	00408825 */ 	or	$s1,$v0,$zero
/*  f1435fc:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f143600:	4608a03e */ 	c.le.s	$f20,$f8
/*  f143604:	00000000 */ 	nop
/*  f143608:	45020006 */ 	bc1fl	.L0f143624
/*  f14360c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f143610:	4600a18d */ 	trunc.w.s	$f6,$f20
/*  f143614:	00139823 */ 	negu	$s3,$s3
/*  f143618:	44123000 */ 	mfc1	$s2,$f6
/*  f14361c:	00000000 */ 	nop
/*  f143620:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f143624:
/*  f143624:	560cffe7 */ 	bnel	$s0,$t4,.L0f1435c4
/*  f143628:	4405d000 */ 	mfc1	$a1,$f26
.L0f14362c:
/*  f14362c:	02201025 */ 	or	$v0,$s1,$zero
.L0f143630:
/*  f143630:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f143634:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f143638:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f14363c:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f143640:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f143644:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f143648:	d7be0050 */ 	ldc1	$f30,0x50($sp)
/*  f14364c:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f143650:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f143654:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f143658:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f14365c:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f143660:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f143664:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f143668:	8fb70074 */ 	lw	$s7,0x74($sp)
/*  f14366c:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*  f143670:	03e00008 */ 	jr	$ra
/*  f143674:	27bd0130 */ 	addiu	$sp,$sp,0x130
);
#endif

Gfx *bviewRenderEyespySideRect(Gfx *gdl, s32 *points, u8 r, u8 g, u8 b, u8 alpha)
{
	struct gfxvtx *vertices = gfxAllocateVertices(4);
	u32 *colours = gfxAllocateColours(2);

	vertices[0].x = points[0] * 10.0f;
	vertices[0].y = points[1] * 10.0f;
	vertices[0].z = -10;

	vertices[1].x = points[2] * 10.0f;
	vertices[1].y = points[3] * 10.0f;
	vertices[1].z = -10;

	vertices[2].x = points[4] * 10.0f;
	vertices[2].y = points[5] * 10.0f;
	vertices[2].z = -10;

	vertices[3].x = points[6] * 10.0f;
	vertices[3].y = points[7] * 10.0f;
	vertices[3].z = -10;

	colours[0] = r << 0x18 | g << 0x10 | b << 8 | 0xff;
	colours[1] = r << 0x18 | g << 0x10 | b << 8 | alpha;

	vertices[0].s = 0;
	vertices[1].s = 0;
	vertices[2].s = 4;
	vertices[3].s = 4;

	gDPSetColorArray(gdl++, colours, 2);
	gDPSetVerticeArray(gdl++, vertices, 4);

	if (colours);

	gDPTri2(gdl++, 0, 1, 2, 0, 2, 3);

	return gdl;
}

const char var7f1b5de4[] = "%s %s%5.2f";
const char var7f1b5df0[] = "";
const char var7f1b5df4[] = "%s %s%4.2f";
const char var7f1b5e00[] = "";
const char var7f1b5e04[] = "%s %d";
const char var7f1b5e0c[] = "%s %d";
const char var7f1b5e14[] = "%s";
const char var7f1b5e18[] = "%s";
const char var7f1b5e1c[] = "%s";
const char var7f1b5e20[] = "%s";
const char var7f1b5e24[] = "   %s";
const char var7f1b5e2c[] = "   %s";
const char var7f1b5e34[] = "   %s";
const char var7f1b5e3c[] = "%s";
const char var7f1b5e40[] = "%s";
const char var7f1b5e44[] = "%s";
const char var7f1b5e48[] = "%s";
const char var7f1b5e4c[] = "%s";

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel bviewRenderEyespyDecorations
.late_rodata
glabel var7f1b726cpf
.word 0x3fb33333
glabel var7f1b5f4c
.word 0x3a83126f
glabel var7f1b5f50
.word 0x3f19999a
glabel var7f1b5f54
.word 0x3c23d70a
glabel var7f1b5f58
.word 0x3bcccccd
.text
/*  f14454c:	27bdfbf0 */ 	addiu	$sp,$sp,-1040
/*  f144550:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f144554:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f144558:	0080a025 */ 	move	$s4,$a0
/*  f14455c:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f144560:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f144564:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f144568:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f14456c:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f144570:	0c002e91 */ 	jal	viGetViewLeft
/*  f144574:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f144578:	0c002e73 */ 	jal	viGetViewWidth
/*  f14457c:	afa2030c */ 	sw	$v0,0x30c($sp)
/*  f144580:	0c002e95 */ 	jal	viGetViewTop
/*  f144584:	afa20308 */ 	sw	$v0,0x308($sp)
/*  f144588:	0c002e77 */ 	jal	viGetViewHeight
/*  f14458c:	afa20304 */ 	sw	$v0,0x304($sp)
/*  f144590:	8fae0308 */ 	lw	$t6,0x308($sp)
/*  f144594:	44806000 */ 	mtc1	$zero,$f12
/*  f144598:	afa20300 */ 	sw	$v0,0x300($sp)
/*  f14459c:	29c10141 */ 	slti	$at,$t6,0x141
/*  f1445a0:	14200005 */ 	bnez	$at,.PF0f1445b8
/*  f1445a4:	3c16800a */ 	lui	$s6,0x800a
/*  f1445a8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1445ac:	c424726c */ 	lwc1	$f4,0x726c($at)
/*  f1445b0:	10000005 */ 	b	.PF0f1445c8
/*  f1445b4:	e7a402b0 */ 	swc1	$f4,0x2b0($sp)
.PF0f1445b8:
/*  f1445b8:	3c013f80 */ 	lui	$at,0x3f80
/*  f1445bc:	44813000 */ 	mtc1	$at,$f6
/*  f1445c0:	00000000 */ 	nop
/*  f1445c4:	e7a602b0 */ 	swc1	$f6,0x2b0($sp)
.PF0f1445c8:
/*  f1445c8:	26d6a510 */ 	addiu	$s6,$s6,-23280
/*  f1445cc:	8ecf006c */ 	lw	$t7,0x6c($s6)
/*  f1445d0:	afa002ac */ 	sw	$zero,0x2ac($sp)
/*  f1445d4:	00003025 */ 	move	$a2,$zero
/*  f1445d8:	11e00003 */ 	beqz	$t7,.PF0f1445e8
/*  f1445dc:	00002825 */ 	move	$a1,$zero
/*  f1445e0:	10000001 */ 	b	.PF0f1445e8
/*  f1445e4:	24060001 */ 	li	$a2,0x1
.PF0f1445e8:
/*  f1445e8:	8ed80068 */ 	lw	$t8,0x68($s6)
/*  f1445ec:	00001825 */ 	move	$v1,$zero
/*  f1445f0:	00001025 */ 	move	$v0,$zero
/*  f1445f4:	13000003 */ 	beqz	$t8,.PF0f144604
/*  f1445f8:	00000000 */ 	nop
/*  f1445fc:	10000001 */ 	b	.PF0f144604
/*  f144600:	24050001 */ 	li	$a1,0x1
.PF0f144604:
/*  f144604:	8ed90064 */ 	lw	$t9,0x64($s6)
/*  f144608:	13200003 */ 	beqz	$t9,.PF0f144618
/*  f14460c:	00000000 */ 	nop
/*  f144610:	10000001 */ 	b	.PF0f144618
/*  f144614:	24030001 */ 	li	$v1,0x1
.PF0f144618:
/*  f144618:	8ece0070 */ 	lw	$t6,0x70($s6)
/*  f14461c:	11c00003 */ 	beqz	$t6,.PF0f14462c
/*  f144620:	00000000 */ 	nop
/*  f144624:	10000001 */ 	b	.PF0f14462c
/*  f144628:	24020001 */ 	li	$v0,0x1
.PF0f14462c:
/*  f14462c:	00437821 */ 	addu	$t7,$v0,$v1
/*  f144630:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f144634:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f144638:	2b210002 */ 	slti	$at,$t9,0x2
/*  f14463c:	5020000c */ 	beqzl	$at,.PF0f144670
/*  f144640:	8fae0304 */ 	lw	$t6,0x304($sp)
/*  f144644:	0fc54e8c */ 	jal	optionsGetEffectiveScreenSize
/*  f144648:	e7ac02c4 */ 	swc1	$f12,0x2c4($sp)
/*  f14464c:	24010001 */ 	li	$at,0x1
/*  f144650:	10410006 */ 	beq	$v0,$at,.PF0f14466c
/*  f144654:	c7ac02c4 */ 	lwc1	$f12,0x2c4($sp)
/*  f144658:	0fc54e8c */ 	jal	optionsGetEffectiveScreenSize
/*  f14465c:	e7ac02c4 */ 	swc1	$f12,0x2c4($sp)
/*  f144660:	24010002 */ 	li	$at,0x2
/*  f144664:	14410008 */ 	bne	$v0,$at,.PF0f144688
/*  f144668:	c7ac02c4 */ 	lwc1	$f12,0x2c4($sp)
.PF0f14466c:
/*  f14466c:	8fae0304 */ 	lw	$t6,0x304($sp)
.PF0f144670:
/*  f144670:	8fb80300 */ 	lw	$t8,0x300($sp)
/*  f144674:	25cf0010 */ 	addiu	$t7,$t6,0x10
/*  f144678:	2719ffe0 */ 	addiu	$t9,$t8,-32
/*  f14467c:	afaf0304 */ 	sw	$t7,0x304($sp)
/*  f144680:	10000007 */ 	b	.PF0f1446a0
/*  f144684:	afb90300 */ 	sw	$t9,0x300($sp)
.PF0f144688:
/*  f144688:	8fae0304 */ 	lw	$t6,0x304($sp)
/*  f14468c:	8fb80300 */ 	lw	$t8,0x300($sp)
/*  f144690:	25cf0017 */ 	addiu	$t7,$t6,0x17
/*  f144694:	2719ffd2 */ 	addiu	$t9,$t8,-46
/*  f144698:	afaf0304 */ 	sw	$t7,0x304($sp)
/*  f14469c:	afb90300 */ 	sw	$t9,0x300($sp)
.PF0f1446a0:
/*  f1446a0:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f1446a4:	8dc20480 */ 	lw	$v0,0x480($t6)
/*  f1446a8:	10400007 */ 	beqz	$v0,.PF0f1446c8
/*  f1446ac:	00000000 */ 	nop
/*  f1446b0:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f1446b4:	10600004 */ 	beqz	$v1,.PF0f1446c8
/*  f1446b8:	00000000 */ 	nop
/*  f1446bc:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f1446c0:	14400003 */ 	bnez	$v0,.PF0f1446d0
/*  f1446c4:	00408025 */ 	move	$s0,$v0
.PF0f1446c8:
/*  f1446c8:	10000e51 */ 	b	.PF0f148010
/*  f1446cc:	02801025 */ 	move	$v0,$s4
.PF0f1446d0:
/*  f1446d0:	0fc54ef9 */ 	jal	optionsGetScreenSplit
/*  f1446d4:	e7ac02c4 */ 	swc1	$f12,0x2c4($sp)
/*  f1446d8:	44800000 */ 	mtc1	$zero,$f0
/*  f1446dc:	24010001 */ 	li	$at,0x1
/*  f1446e0:	1441001f */ 	bne	$v0,$at,.PF0f144760
/*  f1446e4:	c7ac02c4 */ 	lwc1	$f12,0x2c4($sp)
/*  f1446e8:	8ecf006c */ 	lw	$t7,0x6c($s6)
/*  f1446ec:	00003025 */ 	move	$a2,$zero
/*  f1446f0:	00002825 */ 	move	$a1,$zero
/*  f1446f4:	11e00003 */ 	beqz	$t7,.PF0f144704
/*  f1446f8:	00001825 */ 	move	$v1,$zero
/*  f1446fc:	10000001 */ 	b	.PF0f144704
/*  f144700:	24060001 */ 	li	$a2,0x1
.PF0f144704:
/*  f144704:	8ed80068 */ 	lw	$t8,0x68($s6)
/*  f144708:	00001025 */ 	move	$v0,$zero
/*  f14470c:	13000003 */ 	beqz	$t8,.PF0f14471c
/*  f144710:	00000000 */ 	nop
/*  f144714:	10000001 */ 	b	.PF0f14471c
/*  f144718:	24050001 */ 	li	$a1,0x1
.PF0f14471c:
/*  f14471c:	8ed90064 */ 	lw	$t9,0x64($s6)
/*  f144720:	13200003 */ 	beqz	$t9,.PF0f144730
/*  f144724:	00000000 */ 	nop
/*  f144728:	10000001 */ 	b	.PF0f144730
/*  f14472c:	24030001 */ 	li	$v1,0x1
.PF0f144730:
/*  f144730:	8ece0070 */ 	lw	$t6,0x70($s6)
/*  f144734:	11c00003 */ 	beqz	$t6,.PF0f144744
/*  f144738:	00000000 */ 	nop
/*  f14473c:	10000001 */ 	b	.PF0f144744
/*  f144740:	24020001 */ 	li	$v0,0x1
.PF0f144744:
/*  f144744:	00437821 */ 	addu	$t7,$v0,$v1
/*  f144748:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f14474c:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f144750:	2b210002 */ 	slti	$at,$t9,0x2
/*  f144754:	14200002 */ 	bnez	$at,.PF0f144760
/*  f144758:	240e0001 */ 	li	$t6,0x1
/*  f14475c:	afae02ac */ 	sw	$t6,0x2ac($sp)
.PF0f144760:
/*  f144760:	8e02001c */ 	lw	$v0,0x1c($s0)
/*  f144764:	c60a00c8 */ 	lwc1	$f10,0xc8($s0)
/*  f144768:	3c017f1b */ 	lui	$at,0x7f1b
/*  f14476c:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f144770:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f144774:	c60a00cc */ 	lwc1	$f10,0xcc($s0)
/*  f144778:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f14477c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f144780:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f144784:	44033000 */ 	mfc1	$v1,$f6
/*  f144788:	c60a00d0 */ 	lwc1	$f10,0xd0($s0)
/*  f14478c:	c4480010 */ 	lwc1	$f8,0x10($v0)
/*  f144790:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f144794:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f144798:	44834000 */ 	mtc1	$v1,$f8
/*  f14479c:	44043000 */ 	mfc1	$a0,$f6
/*  f1447a0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f1447a4:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f1447a8:	460a0032 */ 	c.eq.s	$f0,$f10
/*  f1447ac:	44053000 */ 	mfc1	$a1,$f6
/*  f1447b0:	4500000f */ 	bc1f	.PF0f1447f0
/*  f1447b4:	00000000 */ 	nop
/*  f1447b8:	44842000 */ 	mtc1	$a0,$f4
/*  f1447bc:	00000000 */ 	nop
/*  f1447c0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1447c4:	46060032 */ 	c.eq.s	$f0,$f6
/*  f1447c8:	00000000 */ 	nop
/*  f1447cc:	45000008 */ 	bc1f	.PF0f1447f0
/*  f1447d0:	00000000 */ 	nop
/*  f1447d4:	44854000 */ 	mtc1	$a1,$f8
/*  f1447d8:	00000000 */ 	nop
/*  f1447dc:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f1447e0:	460a0032 */ 	c.eq.s	$f0,$f10
/*  f1447e4:	00000000 */ 	nop
/*  f1447e8:	4501000f */ 	bc1t	.PF0f144828
/*  f1447ec:	00000000 */ 	nop
.PF0f1447f0:
/*  f1447f0:	00630019 */ 	multu	$v1,$v1
/*  f1447f4:	00007012 */ 	mflo	$t6
/*  f1447f8:	00000000 */ 	nop
/*  f1447fc:	00000000 */ 	nop
/*  f144800:	00840019 */ 	multu	$a0,$a0
/*  f144804:	00007812 */ 	mflo	$t7
/*  f144808:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f14480c:	00000000 */ 	nop
/*  f144810:	00a50019 */ 	multu	$a1,$a1
/*  f144814:	0000c812 */ 	mflo	$t9
/*  f144818:	03197021 */ 	addu	$t6,$t8,$t9
/*  f14481c:	448e2000 */ 	mtc1	$t6,$f4
/*  f144820:	00000000 */ 	nop
/*  f144824:	46802320 */ 	cvt.s.w	$f12,$f4
.PF0f144828:
/*  f144828:	c4267270 */ 	lwc1	$f6,0x7270($at)
/*  f14482c:	460c303c */ 	c.lt.s	$f6,$f12
/*  f144830:	00000000 */ 	nop
/*  f144834:	45020006 */ 	bc1fl	.PF0f144850
/*  f144838:	e7a002c8 */ 	swc1	$f0,0x2c8($sp)
/*  f14483c:	0c0127b4 */ 	jal	sqrtf
/*  f144840:	00000000 */ 	nop
/*  f144844:	10000002 */ 	b	.PF0f144850
/*  f144848:	e7a002c8 */ 	swc1	$f0,0x2c8($sp)
/*  f14484c:	e7a002c8 */ 	swc1	$f0,0x2c8($sp)
.PF0f144850:
/*  f144850:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f144854:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f144858:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f14485c:	14600006 */ 	bnez	$v1,.PF0f144878
/*  f144860:	3c0500ff */ 	lui	$a1,0xff
/*  f144864:	34a50028 */ 	ori	$a1,$a1,0x28
/*  f144868:	0fc5513c */ 	jal	gfxSetPrimColour
/*  f14486c:	02802025 */ 	move	$a0,$s4
/*  f144870:	1000000e */ 	b	.PF0f1448ac
/*  f144874:	0040a025 */ 	move	$s4,$v0
.PF0f144878:
/*  f144878:	24010001 */ 	li	$at,0x1
/*  f14487c:	14610007 */ 	bne	$v1,$at,.PF0f14489c
/*  f144880:	02802025 */ 	move	$a0,$s4
/*  f144884:	3c052244 */ 	lui	$a1,0x2244
/*  f144888:	34a5ffa0 */ 	ori	$a1,$a1,0xffa0
/*  f14488c:	0fc5513c */ 	jal	gfxSetPrimColour
/*  f144890:	02802025 */ 	move	$a0,$s4
/*  f144894:	10000005 */ 	b	.PF0f1448ac
/*  f144898:	0040a025 */ 	move	$s4,$v0
.PF0f14489c:
/*  f14489c:	3c05ff33 */ 	lui	$a1,0xff33
/*  f1448a0:	0fc5513c */ 	jal	gfxSetPrimColour
/*  f1448a4:	34a500a0 */ 	ori	$a1,$a1,0xa0
/*  f1448a8:	0040a025 */ 	move	$s4,$v0
.PF0f1448ac:
/*  f1448ac:	8fb902ac */ 	lw	$t9,0x2ac($sp)
/*  f1448b0:	57200186 */ 	bnezl	$t9,.PF0f144ecc
/*  f1448b4:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f1448b8:	8fab0304 */ 	lw	$t3,0x304($sp)
/*  f1448bc:	8fae0300 */ 	lw	$t6,0x300($sp)
/*  f1448c0:	8fbf030c */ 	lw	$ra,0x30c($sp)
/*  f1448c4:	3c0af600 */ 	lui	$t2,0xf600
/*  f1448c8:	016e6021 */ 	addu	$t4,$t3,$t6
/*  f1448cc:	258cffff */ 	addiu	$t4,$t4,-1
/*  f1448d0:	2585ffe8 */ 	addiu	$a1,$t4,-24
/*  f1448d4:	30af03ff */ 	andi	$t7,$a1,0x3ff
/*  f1448d8:	27f9001a */ 	addiu	$t9,$ra,0x1a
/*  f1448dc:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1448e0:	000f2880 */ 	sll	$a1,$t7,0x2
/*  f1448e4:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1448e8:	01eac025 */ 	or	$t8,$t7,$t2
/*  f1448ec:	25660037 */ 	addiu	$a2,$t3,0x37
/*  f1448f0:	27f50019 */ 	addiu	$s5,$ra,0x19
/*  f1448f4:	32a703ff */ 	andi	$a3,$s5,0x3ff
/*  f1448f8:	30cf03ff */ 	andi	$t7,$a2,0x3ff
/*  f1448fc:	0305c825 */ 	or	$t9,$t8,$a1
/*  f144900:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f144904:	000f3080 */ 	sll	$a2,$t7,0x2
/*  f144908:	00077380 */ 	sll	$t6,$a3,0xe
/*  f14490c:	01c6c825 */ 	or	$t9,$t6,$a2
/*  f144910:	01c03825 */ 	move	$a3,$t6
/*  f144914:	258dffd6 */ 	addiu	$t5,$t4,-42
/*  f144918:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f14491c:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f144920:	27f80020 */ 	addiu	$t8,$ra,0x20
/*  f144924:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f144928:	000e6880 */ 	sll	$t5,$t6,0x2
/*  f14492c:	00197380 */ 	sll	$t6,$t9,0xe
/*  f144930:	27e8001f */ 	addiu	$t0,$ra,0x1f
/*  f144934:	24540008 */ 	addiu	$s4,$v0,0x8
/*  f144938:	311903ff */ 	andi	$t9,$t0,0x3ff
/*  f14493c:	01ca7825 */ 	or	$t7,$t6,$t2
/*  f144940:	01edc025 */ 	or	$t8,$t7,$t5
/*  f144944:	00194380 */ 	sll	$t0,$t9,0xe
/*  f144948:	02802025 */ 	move	$a0,$s4
/*  f14494c:	01067825 */ 	or	$t7,$t0,$a2
/*  f144950:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f144954:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f144958:	8fb80308 */ 	lw	$t8,0x308($sp)
/*  f14495c:	3c013f80 */ 	lui	$at,0x3f80
/*  f144960:	44818000 */ 	mtc1	$at,$f16
/*  f144964:	44985000 */ 	mtc1	$t8,$f10
/*  f144968:	3c0140a0 */ 	lui	$at,0x40a0
/*  f14496c:	44812000 */ 	mtc1	$at,$f4
/*  f144970:	468053a0 */ 	cvt.s.w	$f14,$f10
/*  f144974:	44954000 */ 	mtc1	$s5,$f8
/*  f144978:	240e0001 */ 	li	$t6,0x1
/*  f14497c:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f144980:	02804825 */ 	move	$t1,$s4
/*  f144984:	468040a0 */ 	cvt.s.w	$f2,$f8
/*  f144988:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f14498c:	3c014f00 */ 	lui	$at,0x4f00
/*  f144990:	46047003 */ 	div.s	$f0,$f14,$f4
/*  f144994:	46001180 */ 	add.s	$f6,$f2,$f0
/*  f144998:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f14499c:	4459f800 */ 	cfc1	$t9,$31
/*  f1449a0:	44cef800 */ 	ctc1	$t6,$31
/*  f1449a4:	00000000 */ 	nop
/*  f1449a8:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f1449ac:	444ef800 */ 	cfc1	$t6,$31
/*  f1449b0:	00000000 */ 	nop
/*  f1449b4:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f1449b8:	51c00013 */ 	beqzl	$t6,.PF0f144a08
/*  f1449bc:	440e5000 */ 	mfc1	$t6,$f10
/*  f1449c0:	44815000 */ 	mtc1	$at,$f10
/*  f1449c4:	240e0001 */ 	li	$t6,0x1
/*  f1449c8:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f1449cc:	44cef800 */ 	ctc1	$t6,$31
/*  f1449d0:	00000000 */ 	nop
/*  f1449d4:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f1449d8:	444ef800 */ 	cfc1	$t6,$31
/*  f1449dc:	00000000 */ 	nop
/*  f1449e0:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f1449e4:	15c00005 */ 	bnez	$t6,.PF0f1449fc
/*  f1449e8:	00000000 */ 	nop
/*  f1449ec:	440e5000 */ 	mfc1	$t6,$f10
/*  f1449f0:	3c018000 */ 	lui	$at,0x8000
/*  f1449f4:	10000007 */ 	b	.PF0f144a14
/*  f1449f8:	01c17025 */ 	or	$t6,$t6,$at
.PF0f1449fc:
/*  f1449fc:	10000005 */ 	b	.PF0f144a14
/*  f144a00:	240effff */ 	li	$t6,-1
/*  f144a04:	440e5000 */ 	mfc1	$t6,$f10
.PF0f144a08:
/*  f144a08:	00000000 */ 	nop
/*  f144a0c:	05c0fffb */ 	bltz	$t6,.PF0f1449fc
/*  f144a10:	00000000 */ 	nop
.PF0f144a14:
/*  f144a14:	3c0140e0 */ 	lui	$at,0x40e0
/*  f144a18:	44d9f800 */ 	ctc1	$t9,$31
/*  f144a1c:	44812000 */ 	mtc1	$at,$f4
/*  f144a20:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f144a24:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f144a28:	46047303 */ 	div.s	$f12,$f14,$f4
/*  f144a2c:	030ac825 */ 	or	$t9,$t8,$t2
/*  f144a30:	258fffe7 */ 	addiu	$t7,$t4,-25
/*  f144a34:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f144a38:	03257025 */ 	or	$t6,$t9,$a1
/*  f144a3c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f144a40:	24180001 */ 	li	$t8,0x1
/*  f144a44:	ad2e0000 */ 	sw	$t6,0x0($t1)
/*  f144a48:	02801025 */ 	move	$v0,$s4
/*  f144a4c:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f144a50:	afac008c */ 	sw	$t4,0x8c($sp)
/*  f144a54:	00f97025 */ 	or	$t6,$a3,$t9
/*  f144a58:	01808025 */ 	move	$s0,$t4
/*  f144a5c:	02801825 */ 	move	$v1,$s4
/*  f144a60:	ad2e0004 */ 	sw	$t6,0x4($t1)
/*  f144a64:	3c04f600 */ 	lui	$a0,0xf600
/*  f144a68:	3c014f00 */ 	lui	$at,0x4f00
/*  f144a6c:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f144a70:	2605ffca */ 	addiu	$a1,$s0,-54
/*  f144a74:	460c1180 */ 	add.s	$f6,$f2,$f12
/*  f144a78:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f144a7c:	444ff800 */ 	cfc1	$t7,$31
/*  f144a80:	44d8f800 */ 	ctc1	$t8,$31
/*  f144a84:	00000000 */ 	nop
/*  f144a88:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f144a8c:	4458f800 */ 	cfc1	$t8,$31
/*  f144a90:	00000000 */ 	nop
/*  f144a94:	33180078 */ 	andi	$t8,$t8,0x78
/*  f144a98:	53000013 */ 	beqzl	$t8,.PF0f144ae8
/*  f144a9c:	44185000 */ 	mfc1	$t8,$f10
/*  f144aa0:	44815000 */ 	mtc1	$at,$f10
/*  f144aa4:	24180001 */ 	li	$t8,0x1
/*  f144aa8:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f144aac:	44d8f800 */ 	ctc1	$t8,$31
/*  f144ab0:	00000000 */ 	nop
/*  f144ab4:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f144ab8:	4458f800 */ 	cfc1	$t8,$31
/*  f144abc:	00000000 */ 	nop
/*  f144ac0:	33180078 */ 	andi	$t8,$t8,0x78
/*  f144ac4:	17000005 */ 	bnez	$t8,.PF0f144adc
/*  f144ac8:	00000000 */ 	nop
/*  f144acc:	44185000 */ 	mfc1	$t8,$f10
/*  f144ad0:	3c018000 */ 	lui	$at,0x8000
/*  f144ad4:	10000007 */ 	b	.PF0f144af4
/*  f144ad8:	0301c025 */ 	or	$t8,$t8,$at
.PF0f144adc:
/*  f144adc:	10000005 */ 	b	.PF0f144af4
/*  f144ae0:	2418ffff */ 	li	$t8,-1
/*  f144ae4:	44185000 */ 	mfc1	$t8,$f10
.PF0f144ae8:
/*  f144ae8:	00000000 */ 	nop
/*  f144aec:	0700fffb */ 	bltz	$t8,.PF0f144adc
/*  f144af0:	00000000 */ 	nop
.PF0f144af4:
/*  f144af4:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f144af8:	44cff800 */ 	ctc1	$t7,$31
/*  f144afc:	00197380 */ 	sll	$t6,$t9,0xe
/*  f144b00:	01c47825 */ 	or	$t7,$t6,$a0
/*  f144b04:	01edc025 */ 	or	$t8,$t7,$t5
/*  f144b08:	2619ffd5 */ 	addiu	$t9,$s0,-43
/*  f144b0c:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f144b10:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f144b14:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f144b18:	010fc025 */ 	or	$t8,$t0,$t7
/*  f144b1c:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f144b20:	8fae0308 */ 	lw	$t6,0x308($sp)
/*  f144b24:	8fb9030c */ 	lw	$t9,0x30c($sp)
/*  f144b28:	3c01f600 */ 	lui	$at,0xf600
/*  f144b2c:	02801025 */ 	move	$v0,$s4
/*  f144b30:	032ef821 */ 	addu	$ra,$t9,$t6
/*  f144b34:	27ffffff */ 	addiu	$ra,$ra,-1
/*  f144b38:	27efffe8 */ 	addiu	$t7,$ra,-24
/*  f144b3c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f144b40:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f144b44:	30ae03ff */ 	andi	$t6,$a1,0x3ff
/*  f144b48:	000e2880 */ 	sll	$a1,$t6,0x2
/*  f144b4c:	03246025 */ 	or	$t4,$t9,$a0
/*  f144b50:	0185c025 */ 	or	$t8,$t4,$a1
/*  f144b54:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f144b58:	8faa0304 */ 	lw	$t2,0x304($sp)
/*  f144b5c:	27ebffe7 */ 	addiu	$t3,$ra,-25
/*  f144b60:	316f03ff */ 	andi	$t7,$t3,0x3ff
/*  f144b64:	254a0019 */ 	addiu	$t2,$t2,0x19
/*  f144b68:	315903ff */ 	andi	$t9,$t2,0x3ff
/*  f144b6c:	448b2000 */ 	mtc1	$t3,$f4
/*  f144b70:	00195080 */ 	sll	$t2,$t9,0x2
/*  f144b74:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f144b78:	27e4ffe2 */ 	addiu	$a0,$ra,-30
/*  f144b7c:	030ac825 */ 	or	$t9,$t8,$t2
/*  f144b80:	308e03ff */ 	andi	$t6,$a0,0x3ff
/*  f144b84:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f144b88:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f144b8c:	468020a0 */ 	cvt.s.w	$f2,$f4
/*  f144b90:	8fad0304 */ 	lw	$t5,0x304($sp)
/*  f144b94:	01e1c025 */ 	or	$t8,$t7,$at
/*  f144b98:	0305c825 */ 	or	$t9,$t8,$a1
/*  f144b9c:	afbf0090 */ 	sw	$ra,0x90($sp)
/*  f144ba0:	03002025 */ 	move	$a0,$t8
/*  f144ba4:	27f8ffe1 */ 	addiu	$t8,$ra,-31
/*  f144ba8:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f144bac:	25a7002b */ 	addiu	$a3,$t5,0x2b
/*  f144bb0:	30ee03ff */ 	andi	$t6,$a3,0x3ff
/*  f144bb4:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f144bb8:	000e3880 */ 	sll	$a3,$t6,0x2
/*  f144bbc:	46001181 */ 	sub.s	$f6,$f2,$f0
/*  f144bc0:	00197380 */ 	sll	$t6,$t9,0xe
/*  f144bc4:	25b8001a */ 	addiu	$t8,$t5,0x1a
/*  f144bc8:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f144bcc:	01c77825 */ 	or	$t7,$t6,$a3
/*  f144bd0:	00197080 */ 	sll	$t6,$t9,0x2
/*  f144bd4:	24190001 */ 	li	$t9,0x1
/*  f144bd8:	4458f800 */ 	cfc1	$t8,$31
/*  f144bdc:	44d9f800 */ 	ctc1	$t9,$31
/*  f144be0:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f144be4:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f144be8:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f144bec:	02801825 */ 	move	$v1,$s4
/*  f144bf0:	018e7825 */ 	or	$t7,$t4,$t6
/*  f144bf4:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f144bf8:	4459f800 */ 	cfc1	$t9,$31
/*  f144bfc:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f144c00:	3c014f00 */ 	lui	$at,0x4f00
/*  f144c04:	33390078 */ 	andi	$t9,$t9,0x78
/*  f144c08:	53200013 */ 	beqzl	$t9,.PF0f144c58
/*  f144c0c:	44194000 */ 	mfc1	$t9,$f8
/*  f144c10:	44814000 */ 	mtc1	$at,$f8
/*  f144c14:	24190001 */ 	li	$t9,0x1
/*  f144c18:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f144c1c:	44d9f800 */ 	ctc1	$t9,$31
/*  f144c20:	00000000 */ 	nop
/*  f144c24:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f144c28:	4459f800 */ 	cfc1	$t9,$31
/*  f144c2c:	00000000 */ 	nop
/*  f144c30:	33390078 */ 	andi	$t9,$t9,0x78
/*  f144c34:	17200005 */ 	bnez	$t9,.PF0f144c4c
/*  f144c38:	00000000 */ 	nop
/*  f144c3c:	44194000 */ 	mfc1	$t9,$f8
/*  f144c40:	3c018000 */ 	lui	$at,0x8000
/*  f144c44:	10000007 */ 	b	.PF0f144c64
/*  f144c48:	0321c825 */ 	or	$t9,$t9,$at
.PF0f144c4c:
/*  f144c4c:	10000005 */ 	b	.PF0f144c64
/*  f144c50:	2419ffff */ 	li	$t9,-1
/*  f144c54:	44194000 */ 	mfc1	$t9,$f8
.PF0f144c58:
/*  f144c58:	00000000 */ 	nop
/*  f144c5c:	0720fffb */ 	bltz	$t9,.PF0f144c4c
/*  f144c60:	00000000 */ 	nop
.PF0f144c64:
/*  f144c64:	44d8f800 */ 	ctc1	$t8,$31
/*  f144c68:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f144c6c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f144c70:	460c1281 */ 	sub.s	$f10,$f2,$f12
/*  f144c74:	25b9002c */ 	addiu	$t9,$t5,0x2c
/*  f144c78:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f144c7c:	01eac025 */ 	or	$t8,$t7,$t2
/*  f144c80:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f144c84:	240e0001 */ 	li	$t6,0x1
/*  f144c88:	4459f800 */ 	cfc1	$t9,$31
/*  f144c8c:	44cef800 */ 	ctc1	$t6,$31
/*  f144c90:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f144c94:	008fc025 */ 	or	$t8,$a0,$t7
/*  f144c98:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f144c9c:	02804025 */ 	move	$t0,$s4
/*  f144ca0:	ad180000 */ 	sw	$t8,0x0($t0)
/*  f144ca4:	8fa9030c */ 	lw	$t1,0x30c($sp)
/*  f144ca8:	444ef800 */ 	cfc1	$t6,$31
/*  f144cac:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f144cb0:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f144cb4:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f144cb8:	11c00012 */ 	beqz	$t6,.PF0f144d04
/*  f144cbc:	3c014f00 */ 	lui	$at,0x4f00
/*  f144cc0:	44812000 */ 	mtc1	$at,$f4
/*  f144cc4:	240e0001 */ 	li	$t6,0x1
/*  f144cc8:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f144ccc:	44cef800 */ 	ctc1	$t6,$31
/*  f144cd0:	00000000 */ 	nop
/*  f144cd4:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f144cd8:	444ef800 */ 	cfc1	$t6,$31
/*  f144cdc:	00000000 */ 	nop
/*  f144ce0:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f144ce4:	15c00005 */ 	bnez	$t6,.PF0f144cfc
/*  f144ce8:	00000000 */ 	nop
/*  f144cec:	440e2000 */ 	mfc1	$t6,$f4
/*  f144cf0:	3c018000 */ 	lui	$at,0x8000
/*  f144cf4:	10000007 */ 	b	.PF0f144d14
/*  f144cf8:	01c17025 */ 	or	$t6,$t6,$at
.PF0f144cfc:
/*  f144cfc:	10000005 */ 	b	.PF0f144d14
/*  f144d00:	240effff */ 	li	$t6,-1
.PF0f144d04:
/*  f144d04:	440e2000 */ 	mfc1	$t6,$f4
/*  f144d08:	00000000 */ 	nop
/*  f144d0c:	05c0fffb */ 	bltz	$t6,.PF0f144cfc
/*  f144d10:	00000000 */ 	nop
.PF0f144d14:
/*  f144d14:	44d9f800 */ 	ctc1	$t9,$31
/*  f144d18:	44893000 */ 	mtc1	$t1,$f6
/*  f144d1c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f144d20:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f144d24:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f144d28:	240f0001 */ 	li	$t7,0x1
/*  f144d2c:	0307c825 */ 	or	$t9,$t8,$a3
/*  f144d30:	02801025 */ 	move	$v0,$s4
/*  f144d34:	ad190004 */ 	sw	$t9,0x4($t0)
/*  f144d38:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f144d3c:	46004280 */ 	add.s	$f10,$f8,$f0
/*  f144d40:	3c014f00 */ 	lui	$at,0x4f00
/*  f144d44:	46105100 */ 	add.s	$f4,$f10,$f16
/*  f144d48:	444ef800 */ 	cfc1	$t6,$31
/*  f144d4c:	44cff800 */ 	ctc1	$t7,$31
/*  f144d50:	00000000 */ 	nop
/*  f144d54:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f144d58:	444ff800 */ 	cfc1	$t7,$31
/*  f144d5c:	00000000 */ 	nop
/*  f144d60:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f144d64:	51e00013 */ 	beqzl	$t7,.PF0f144db4
/*  f144d68:	440f3000 */ 	mfc1	$t7,$f6
/*  f144d6c:	44813000 */ 	mtc1	$at,$f6
/*  f144d70:	240f0001 */ 	li	$t7,0x1
/*  f144d74:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f144d78:	44cff800 */ 	ctc1	$t7,$31
/*  f144d7c:	00000000 */ 	nop
/*  f144d80:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f144d84:	444ff800 */ 	cfc1	$t7,$31
/*  f144d88:	00000000 */ 	nop
/*  f144d8c:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f144d90:	15e00005 */ 	bnez	$t7,.PF0f144da8
/*  f144d94:	00000000 */ 	nop
/*  f144d98:	440f3000 */ 	mfc1	$t7,$f6
/*  f144d9c:	3c018000 */ 	lui	$at,0x8000
/*  f144da0:	10000007 */ 	b	.PF0f144dc0
/*  f144da4:	01e17825 */ 	or	$t7,$t7,$at
.PF0f144da8:
/*  f144da8:	10000005 */ 	b	.PF0f144dc0
/*  f144dac:	240fffff */ 	li	$t7,-1
/*  f144db0:	440f3000 */ 	mfc1	$t7,$f6
.PF0f144db4:
/*  f144db4:	00000000 */ 	nop
/*  f144db8:	05e0fffb */ 	bltz	$t7,.PF0f144da8
/*  f144dbc:	00000000 */ 	nop
.PF0f144dc0:
/*  f144dc0:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f144dc4:	8faf0304 */ 	lw	$t7,0x304($sp)
/*  f144dc8:	44cef800 */ 	ctc1	$t6,$31
/*  f144dcc:	44844000 */ 	mtc1	$a0,$f8
/*  f144dd0:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f144dd4:	3c01f600 */ 	lui	$at,0xf600
/*  f144dd8:	03217025 */ 	or	$t6,$t9,$at
/*  f144ddc:	25f80038 */ 	addiu	$t8,$t7,0x38
/*  f144de0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f144de4:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f144de8:	00197880 */ 	sll	$t7,$t9,0x2
/*  f144dec:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f144df0:	313903ff */ 	andi	$t9,$t1,0x3ff
/*  f144df4:	00197380 */ 	sll	$t6,$t9,0xe
/*  f144df8:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f144dfc:	24980001 */ 	addiu	$t8,$a0,0x1
/*  f144e00:	46005101 */ 	sub.s	$f4,$f10,$f0
/*  f144e04:	01c67825 */ 	or	$t7,$t6,$a2
/*  f144e08:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f144e0c:	00197380 */ 	sll	$t6,$t9,0xe
/*  f144e10:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f144e14:	01c17825 */ 	or	$t7,$t6,$at
/*  f144e18:	240e0001 */ 	li	$t6,0x1
/*  f144e1c:	4459f800 */ 	cfc1	$t9,$31
/*  f144e20:	44cef800 */ 	ctc1	$t6,$31
/*  f144e24:	01e5c025 */ 	or	$t8,$t7,$a1
/*  f144e28:	02801825 */ 	move	$v1,$s4
/*  f144e2c:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f144e30:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f144e34:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f144e38:	3c014f00 */ 	lui	$at,0x4f00
/*  f144e3c:	444ef800 */ 	cfc1	$t6,$31
/*  f144e40:	00000000 */ 	nop
/*  f144e44:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f144e48:	51c00013 */ 	beqzl	$t6,.PF0f144e98
/*  f144e4c:	440e3000 */ 	mfc1	$t6,$f6
/*  f144e50:	44813000 */ 	mtc1	$at,$f6
/*  f144e54:	240e0001 */ 	li	$t6,0x1
/*  f144e58:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f144e5c:	44cef800 */ 	ctc1	$t6,$31
/*  f144e60:	00000000 */ 	nop
/*  f144e64:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f144e68:	444ef800 */ 	cfc1	$t6,$31
/*  f144e6c:	00000000 */ 	nop
/*  f144e70:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f144e74:	15c00005 */ 	bnez	$t6,.PF0f144e8c
/*  f144e78:	00000000 */ 	nop
/*  f144e7c:	440e3000 */ 	mfc1	$t6,$f6
/*  f144e80:	3c018000 */ 	lui	$at,0x8000
/*  f144e84:	10000007 */ 	b	.PF0f144ea4
/*  f144e88:	01c17025 */ 	or	$t6,$t6,$at
.PF0f144e8c:
/*  f144e8c:	10000005 */ 	b	.PF0f144ea4
/*  f144e90:	240effff */ 	li	$t6,-1
/*  f144e94:	440e3000 */ 	mfc1	$t6,$f6
.PF0f144e98:
/*  f144e98:	00000000 */ 	nop
/*  f144e9c:	05c0fffb */ 	bltz	$t6,.PF0f144e8c
/*  f144ea0:	00000000 */ 	nop
.PF0f144ea4:
/*  f144ea4:	44d9f800 */ 	ctc1	$t9,$31
/*  f144ea8:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f144eac:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f144eb0:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f144eb4:	272effc9 */ 	addiu	$t6,$t9,-55
/*  f144eb8:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f144ebc:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f144ec0:	03197025 */ 	or	$t6,$t8,$t9
/*  f144ec4:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f144ec8:	8ecf0284 */ 	lw	$t7,0x284($s6)
.PF0f144ecc:
/*  f144ecc:	8fa9030c */ 	lw	$t1,0x30c($sp)
/*  f144ed0:	8fb90308 */ 	lw	$t9,0x308($sp)
/*  f144ed4:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f144ed8:	24010001 */ 	li	$at,0x1
/*  f144edc:	01397021 */ 	addu	$t6,$t1,$t9
/*  f144ee0:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f144ee4:	25cfffff */ 	addiu	$t7,$t6,-1
/*  f144ee8:	8fae0300 */ 	lw	$t6,0x300($sp)
/*  f144eec:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f144ef0:	afaf0090 */ 	sw	$t7,0x90($sp)
/*  f144ef4:	25350019 */ 	addiu	$s5,$t1,0x19
/*  f144ef8:	030e7821 */ 	addu	$t7,$t8,$t6
/*  f144efc:	25efffff */ 	addiu	$t7,$t7,-1
/*  f144f00:	1461006b */ 	bne	$v1,$at,.PF0f1450b0
/*  f144f04:	afaf008c */ 	sw	$t7,0x8c($sp)
/*  f144f08:	00197843 */ 	sra	$t7,$t9,0x1
/*  f144f0c:	8fb9030c */ 	lw	$t9,0x30c($sp)
/*  f144f10:	3c0cf600 */ 	lui	$t4,0xf600
/*  f144f14:	02803025 */ 	move	$a2,$s4
/*  f144f18:	01f91021 */ 	addu	$v0,$t7,$t9
/*  f144f1c:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f144f20:	01f82021 */ 	addu	$a0,$t7,$t8
/*  f144f24:	24830001 */ 	addiu	$v1,$a0,0x1
/*  f144f28:	307903ff */ 	andi	$t9,$v1,0x3ff
/*  f144f2c:	244f0007 */ 	addiu	$t7,$v0,0x7
/*  f144f30:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f144f34:	00191880 */ 	sll	$v1,$t9,0x2
/*  f144f38:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f144f3c:	032c7025 */ 	or	$t6,$t9,$t4
/*  f144f40:	01c37825 */ 	or	$t7,$t6,$v1
/*  f144f44:	24590002 */ 	addiu	$t9,$v0,0x2
/*  f144f48:	308503ff */ 	andi	$a1,$a0,0x3ff
/*  f144f4c:	0005c080 */ 	sll	$t8,$a1,0x2
/*  f144f50:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f144f54:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f144f58:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f144f5c:	01f83825 */ 	or	$a3,$t7,$t8
/*  f144f60:	03002825 */ 	move	$a1,$t8
/*  f144f64:	24580005 */ 	addiu	$t8,$v0,0x5
/*  f144f68:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f144f6c:	00197380 */ 	sll	$t6,$t9,0xe
/*  f144f70:	01cc7825 */ 	or	$t7,$t6,$t4
/*  f144f74:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f144f78:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f144f7c:	2459ffff */ 	addiu	$t9,$v0,-1
/*  f144f80:	acc70004 */ 	sw	$a3,0x4($a2)
/*  f144f84:	02804025 */ 	move	$t0,$s4
/*  f144f88:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f144f8c:	ad180000 */ 	sw	$t8,0x0($t0)
/*  f144f90:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f144f94:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f144f98:	2459fffa */ 	addiu	$t9,$v0,-6
/*  f144f9c:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f144fa0:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f144fa4:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f144fa8:	03035025 */ 	or	$t2,$t8,$v1
/*  f144fac:	01e5c025 */ 	or	$t8,$t7,$a1
/*  f144fb0:	02804825 */ 	move	$t1,$s4
/*  f144fb4:	2459fffc */ 	addiu	$t9,$v0,-4
/*  f144fb8:	ad070004 */ 	sw	$a3,0x4($t0)
/*  f144fbc:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f144fc0:	ad380004 */ 	sw	$t8,0x4($t1)
/*  f144fc4:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f144fc8:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f144fcc:	24430001 */ 	addiu	$v1,$v0,0x1
/*  f144fd0:	ad2a0000 */ 	sw	$t2,0x0($t1)
/*  f144fd4:	01e5c025 */ 	or	$t8,$t7,$a1
/*  f144fd8:	02805825 */ 	move	$t3,$s4
/*  f144fdc:	307903ff */ 	andi	$t9,$v1,0x3ff
/*  f144fe0:	ad780004 */ 	sw	$t8,0x4($t3)
/*  f144fe4:	00197380 */ 	sll	$t6,$t9,0xe
/*  f144fe8:	24980007 */ 	addiu	$t8,$a0,0x7
/*  f144fec:	3c01f600 */ 	lui	$at,0xf600
/*  f144ff0:	01c11825 */ 	or	$v1,$t6,$at
/*  f144ff4:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f144ff8:	00197080 */ 	sll	$t6,$t9,0x2
/*  f144ffc:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f145000:	006e7825 */ 	or	$t7,$v1,$t6
/*  f145004:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*  f145008:	02802825 */ 	move	$a1,$s4
/*  f14500c:	24990002 */ 	addiu	$t9,$a0,0x2
/*  f145010:	304803ff */ 	andi	$t0,$v0,0x3ff
/*  f145014:	0008c380 */ 	sll	$t8,$t0,0xe
/*  f145018:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f14501c:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f145020:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f145024:	030f3825 */ 	or	$a3,$t8,$t7
/*  f145028:	03004025 */ 	move	$t0,$t8
/*  f14502c:	24980005 */ 	addiu	$t8,$a0,0x5
/*  f145030:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f145034:	00197080 */ 	sll	$t6,$t9,0x2
/*  f145038:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f14503c:	006e7825 */ 	or	$t7,$v1,$t6
/*  f145040:	aca70004 */ 	sw	$a3,0x4($a1)
/*  f145044:	02803025 */ 	move	$a2,$s4
/*  f145048:	2498ffff */ 	addiu	$t8,$a0,-1
/*  f14504c:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f145050:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f145054:	00197080 */ 	sll	$t6,$t9,0x2
/*  f145058:	248ffffa */ 	addiu	$t7,$a0,-6
/*  f14505c:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f145060:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f145064:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f145068:	02804825 */ 	move	$t1,$s4
/*  f14506c:	006e5025 */ 	or	$t2,$v1,$t6
/*  f145070:	acc70004 */ 	sw	$a3,0x4($a2)
/*  f145074:	01197025 */ 	or	$t6,$t0,$t9
/*  f145078:	248ffffc */ 	addiu	$t7,$a0,-4
/*  f14507c:	ad2e0004 */ 	sw	$t6,0x4($t1)
/*  f145080:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f145084:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f145088:	ad2a0000 */ 	sw	$t2,0x0($t1)
/*  f14508c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f145090:	02801025 */ 	move	$v0,$s4
/*  f145094:	01197025 */ 	or	$t6,$t0,$t9
/*  f145098:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f14509c:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f1450a0:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f1450a4:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f1450a8:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f1450ac:	9303006b */ 	lbu	$v1,0x6b($t8)
.PF0f1450b0:
/*  f1450b0:	1460000a */ 	bnez	$v1,.PF0f1450dc
/*  f1450b4:	3c1900ff */ 	lui	$t9,0xff
/*  f1450b8:	3c0e0050 */ 	lui	$t6,0x50
/*  f1450bc:	3c0f000f */ 	lui	$t7,0xf
/*  f1450c0:	373900a0 */ 	ori	$t9,$t9,0xa0
/*  f1450c4:	35ce00ff */ 	ori	$t6,$t6,0xff
/*  f1450c8:	35ef00ff */ 	ori	$t7,$t7,0xff
/*  f1450cc:	afb902c0 */ 	sw	$t9,0x2c0($sp)
/*  f1450d0:	afae02bc */ 	sw	$t6,0x2bc($sp)
/*  f1450d4:	10000011 */ 	b	.PF0f14511c
/*  f1450d8:	afaf02b8 */ 	sw	$t7,0x2b8($sp)
.PF0f1450dc:
/*  f1450dc:	24010001 */ 	li	$at,0x1
/*  f1450e0:	14610008 */ 	bne	$v1,$at,.PF0f145104
/*  f1450e4:	3c02ff33 */ 	lui	$v0,0xff33
/*  f1450e8:	3c022244 */ 	lui	$v0,0x2244
/*  f1450ec:	3442ffff */ 	ori	$v0,$v0,0xffff
/*  f1450f0:	24180fff */ 	li	$t8,0xfff
/*  f1450f4:	afa202c0 */ 	sw	$v0,0x2c0($sp)
/*  f1450f8:	afa202bc */ 	sw	$v0,0x2bc($sp)
/*  f1450fc:	10000007 */ 	b	.PF0f14511c
/*  f145100:	afb802b8 */ 	sw	$t8,0x2b8($sp)
.PF0f145104:
/*  f145104:	344200ff */ 	ori	$v0,$v0,0xff
/*  f145108:	3c190f00 */ 	lui	$t9,0xf00
/*  f14510c:	373900ff */ 	ori	$t9,$t9,0xff
/*  f145110:	afa202c0 */ 	sw	$v0,0x2c0($sp)
/*  f145114:	afa202bc */ 	sw	$v0,0x2bc($sp)
/*  f145118:	afb902b8 */ 	sw	$t9,0x2b8($sp)
.PF0f14511c:
/*  f14511c:	0fc5bdaa */ 	jal	langGet
/*  f145120:	2404580c */ 	li	$a0,0x580c
/*  f145124:	3c017f1b */ 	lui	$at,0x7f1b
/*  f145128:	c42a7274 */ 	lwc1	$f10,0x7274($at)
/*  f14512c:	c7a802c8 */ 	lwc1	$f8,0x2c8($sp)
/*  f145130:	27b30310 */ 	addiu	$s3,$sp,0x310
/*  f145134:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145138:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f14513c:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f145140:	24e77110 */ 	addiu	$a3,$a3,0x7110
/*  f145144:	24a57104 */ 	addiu	$a1,$a1,0x7104
/*  f145148:	02602025 */ 	move	$a0,$s3
/*  f14514c:	00403025 */ 	move	$a2,$v0
/*  f145150:	460021a1 */ 	cvt.d.s	$f6,$f4
/*  f145154:	0c004d11 */ 	jal	sprintf
/*  f145158:	f7a60010 */ 	sdc1	$f6,0x10($sp)
/*  f14515c:	3c0e8008 */ 	lui	$t6,0x8008
/*  f145160:	8dce0064 */ 	lw	$t6,0x64($t6)
/*  f145164:	3c078008 */ 	lui	$a3,0x8008
/*  f145168:	8ce70068 */ 	lw	$a3,0x68($a3)
/*  f14516c:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f145170:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145174:	02603025 */ 	move	$a2,$s3
/*  f145178:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f14517c:	0fc5609a */ 	jal	textMeasure
/*  f145180:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f145184:	8fb20304 */ 	lw	$s2,0x304($sp)
/*  f145188:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f14518c:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f145190:	2652000e */ 	addiu	$s2,$s2,0xe
/*  f145194:	27ae02e0 */ 	addiu	$t6,$sp,0x2e0
/*  f145198:	02a97821 */ 	addu	$t7,$s5,$t1
/*  f14519c:	0258c821 */ 	addu	$t9,$s2,$t8
/*  f1451a0:	afb902e0 */ 	sw	$t9,0x2e0($sp)
/*  f1451a4:	afaf02e4 */ 	sw	$t7,0x2e4($sp)
/*  f1451a8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1451ac:	afb202f0 */ 	sw	$s2,0x2f0($sp)
/*  f1451b0:	02802025 */ 	move	$a0,$s4
/*  f1451b4:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f1451b8:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f1451bc:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f1451c0:	0fc5515b */ 	jal	func0f153858
/*  f1451c4:	afb502f4 */ 	sw	$s5,0x2f4($sp)
/*  f1451c8:	0c002e53 */ 	jal	viGetWidth
/*  f1451cc:	0040a025 */ 	move	$s4,$v0
/*  f1451d0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1451d4:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f1451d8:	0c002e57 */ 	jal	viGetHeight
/*  f1451dc:	01e08025 */ 	move	$s0,$t7
/*  f1451e0:	3c188008 */ 	lui	$t8,0x8008
/*  f1451e4:	3c198008 */ 	lui	$t9,0x8008
/*  f1451e8:	8f390064 */ 	lw	$t9,0x64($t9)
/*  f1451ec:	8f180068 */ 	lw	$t8,0x68($t8)
/*  f1451f0:	8fae02c0 */ 	lw	$t6,0x2c0($sp)
/*  f1451f4:	8faf02b8 */ 	lw	$t7,0x2b8($sp)
/*  f1451f8:	02802025 */ 	move	$a0,$s4
/*  f1451fc:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f145200:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f145204:	02603825 */ 	move	$a3,$s3
/*  f145208:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f14520c:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f145210:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f145214:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f145218:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f14521c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f145220:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f145224:	0fc55fa0 */ 	jal	textRender
/*  f145228:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f14522c:	0040a025 */ 	move	$s4,$v0
/*  f145230:	0fc5bdaa */ 	jal	langGet
/*  f145234:	2404580d */ 	li	$a0,0x580d
/*  f145238:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f14523c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f145240:	c42a7278 */ 	lwc1	$f10,0x7278($at)
/*  f145244:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f145248:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f14524c:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f145250:	c7280060 */ 	lwc1	$f8,0x60($t9)
/*  f145254:	24e77120 */ 	addiu	$a3,$a3,0x7120
/*  f145258:	24a57114 */ 	addiu	$a1,$a1,0x7114
/*  f14525c:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f145260:	02602025 */ 	move	$a0,$s3
/*  f145264:	00403025 */ 	move	$a2,$v0
/*  f145268:	460021a1 */ 	cvt.d.s	$f6,$f4
/*  f14526c:	0c004d11 */ 	jal	sprintf
/*  f145270:	f7a60010 */ 	sdc1	$f6,0x10($sp)
/*  f145274:	3c0e8008 */ 	lui	$t6,0x8008
/*  f145278:	8dce0064 */ 	lw	$t6,0x64($t6)
/*  f14527c:	3c078008 */ 	lui	$a3,0x8008
/*  f145280:	26510009 */ 	addiu	$s1,$s2,0x9
/*  f145284:	8ce70068 */ 	lw	$a3,0x68($a3)
/*  f145288:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f14528c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145290:	02603025 */ 	move	$a2,$s3
/*  f145294:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f145298:	0fc5609a */ 	jal	textMeasure
/*  f14529c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1452a0:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f1452a4:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f1452a8:	27ae02e0 */ 	addiu	$t6,$sp,0x2e0
/*  f1452ac:	02a97821 */ 	addu	$t7,$s5,$t1
/*  f1452b0:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f1452b4:	afb902e0 */ 	sw	$t9,0x2e0($sp)
/*  f1452b8:	afaf02e4 */ 	sw	$t7,0x2e4($sp)
/*  f1452bc:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1452c0:	02802025 */ 	move	$a0,$s4
/*  f1452c4:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f1452c8:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f1452cc:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f1452d0:	afb502f4 */ 	sw	$s5,0x2f4($sp)
/*  f1452d4:	0fc5515b */ 	jal	func0f153858
/*  f1452d8:	afb102f0 */ 	sw	$s1,0x2f0($sp)
/*  f1452dc:	0c002e53 */ 	jal	viGetWidth
/*  f1452e0:	0040a025 */ 	move	$s4,$v0
/*  f1452e4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1452e8:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f1452ec:	0c002e57 */ 	jal	viGetHeight
/*  f1452f0:	01e08025 */ 	move	$s0,$t7
/*  f1452f4:	3c188008 */ 	lui	$t8,0x8008
/*  f1452f8:	3c198008 */ 	lui	$t9,0x8008
/*  f1452fc:	8f390064 */ 	lw	$t9,0x64($t9)
/*  f145300:	8f180068 */ 	lw	$t8,0x68($t8)
/*  f145304:	8fae02c0 */ 	lw	$t6,0x2c0($sp)
/*  f145308:	8faf02b8 */ 	lw	$t7,0x2b8($sp)
/*  f14530c:	02802025 */ 	move	$a0,$s4
/*  f145310:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f145314:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f145318:	02603825 */ 	move	$a3,$s3
/*  f14531c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f145320:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f145324:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f145328:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f14532c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f145330:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f145334:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f145338:	0fc55fa0 */ 	jal	textRender
/*  f14533c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f145340:	0040a025 */ 	move	$s4,$v0
/*  f145344:	0fc5bdaa */ 	jal	langGet
/*  f145348:	2404580e */ 	li	$a0,0x580e
/*  f14534c:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f145350:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145354:	24a57124 */ 	addiu	$a1,$a1,0x7124
/*  f145358:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f14535c:	02602025 */ 	move	$a0,$s3
/*  f145360:	00403025 */ 	move	$a2,$v0
/*  f145364:	c728001c */ 	lwc1	$f8,0x1c($t9)
/*  f145368:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f14536c:	44075000 */ 	mfc1	$a3,$f10
/*  f145370:	0c004d11 */ 	jal	sprintf
/*  f145374:	00000000 */ 	nop
/*  f145378:	3c0f8008 */ 	lui	$t7,0x8008
/*  f14537c:	8def0064 */ 	lw	$t7,0x64($t7)
/*  f145380:	3c078008 */ 	lui	$a3,0x8008
/*  f145384:	26310009 */ 	addiu	$s1,$s1,0x9
/*  f145388:	8ce70068 */ 	lw	$a3,0x68($a3)
/*  f14538c:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f145390:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145394:	02603025 */ 	move	$a2,$s3
/*  f145398:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f14539c:	0fc5609a */ 	jal	textMeasure
/*  f1453a0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1453a4:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f1453a8:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f1453ac:	27af02e0 */ 	addiu	$t7,$sp,0x2e0
/*  f1453b0:	02a9c021 */ 	addu	$t8,$s5,$t1
/*  f1453b4:	02397021 */ 	addu	$t6,$s1,$t9
/*  f1453b8:	afae02e0 */ 	sw	$t6,0x2e0($sp)
/*  f1453bc:	afb802e4 */ 	sw	$t8,0x2e4($sp)
/*  f1453c0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1453c4:	02802025 */ 	move	$a0,$s4
/*  f1453c8:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f1453cc:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f1453d0:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f1453d4:	afb502f4 */ 	sw	$s5,0x2f4($sp)
/*  f1453d8:	0fc5515b */ 	jal	func0f153858
/*  f1453dc:	afb102f0 */ 	sw	$s1,0x2f0($sp)
/*  f1453e0:	0c002e53 */ 	jal	viGetWidth
/*  f1453e4:	0040a025 */ 	move	$s4,$v0
/*  f1453e8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1453ec:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f1453f0:	0c002e57 */ 	jal	viGetHeight
/*  f1453f4:	03008025 */ 	move	$s0,$t8
/*  f1453f8:	3c198008 */ 	lui	$t9,0x8008
/*  f1453fc:	3c0e8008 */ 	lui	$t6,0x8008
/*  f145400:	8dce0064 */ 	lw	$t6,0x64($t6)
/*  f145404:	8f390068 */ 	lw	$t9,0x68($t9)
/*  f145408:	8faf02c0 */ 	lw	$t7,0x2c0($sp)
/*  f14540c:	8fb802b8 */ 	lw	$t8,0x2b8($sp)
/*  f145410:	02802025 */ 	move	$a0,$s4
/*  f145414:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f145418:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f14541c:	02603825 */ 	move	$a3,$s3
/*  f145420:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f145424:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f145428:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f14542c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f145430:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f145434:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f145438:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f14543c:	0fc55fa0 */ 	jal	textRender
/*  f145440:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f145444:	0040a025 */ 	move	$s4,$v0
/*  f145448:	0fc5bdaa */ 	jal	langGet
/*  f14544c:	2404580f */ 	li	$a0,0x580f
/*  f145450:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f145454:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145458:	24a5712c */ 	addiu	$a1,$a1,0x712c
/*  f14545c:	8f2e0480 */ 	lw	$t6,0x480($t9)
/*  f145460:	02602025 */ 	move	$a0,$s3
/*  f145464:	00403025 */ 	move	$a2,$v0
/*  f145468:	c5c40028 */ 	lwc1	$f4,0x28($t6)
/*  f14546c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f145470:	44073000 */ 	mfc1	$a3,$f6
/*  f145474:	0c004d11 */ 	jal	sprintf
/*  f145478:	00000000 */ 	nop
/*  f14547c:	3c188008 */ 	lui	$t8,0x8008
/*  f145480:	8f180064 */ 	lw	$t8,0x64($t8)
/*  f145484:	3c078008 */ 	lui	$a3,0x8008
/*  f145488:	26310009 */ 	addiu	$s1,$s1,0x9
/*  f14548c:	8ce70068 */ 	lw	$a3,0x68($a3)
/*  f145490:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f145494:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145498:	02603025 */ 	move	$a2,$s3
/*  f14549c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1454a0:	0fc5609a */ 	jal	textMeasure
/*  f1454a4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1454a8:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f1454ac:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f1454b0:	27b802e0 */ 	addiu	$t8,$sp,0x2e0
/*  f1454b4:	02a9c821 */ 	addu	$t9,$s5,$t1
/*  f1454b8:	022e7821 */ 	addu	$t7,$s1,$t6
/*  f1454bc:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f1454c0:	afb902e4 */ 	sw	$t9,0x2e4($sp)
/*  f1454c4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1454c8:	02802025 */ 	move	$a0,$s4
/*  f1454cc:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f1454d0:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f1454d4:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f1454d8:	afb502f4 */ 	sw	$s5,0x2f4($sp)
/*  f1454dc:	0fc5515b */ 	jal	func0f153858
/*  f1454e0:	afb102f0 */ 	sw	$s1,0x2f0($sp)
/*  f1454e4:	0c002e53 */ 	jal	viGetWidth
/*  f1454e8:	0040a025 */ 	move	$s4,$v0
/*  f1454ec:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1454f0:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f1454f4:	0c002e57 */ 	jal	viGetHeight
/*  f1454f8:	03208025 */ 	move	$s0,$t9
/*  f1454fc:	3c0e8008 */ 	lui	$t6,0x8008
/*  f145500:	3c0f8008 */ 	lui	$t7,0x8008
/*  f145504:	8def0064 */ 	lw	$t7,0x64($t7)
/*  f145508:	8dce0068 */ 	lw	$t6,0x68($t6)
/*  f14550c:	8fb802c0 */ 	lw	$t8,0x2c0($sp)
/*  f145510:	8fb902b8 */ 	lw	$t9,0x2b8($sp)
/*  f145514:	02802025 */ 	move	$a0,$s4
/*  f145518:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f14551c:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f145520:	02603825 */ 	move	$a3,$s3
/*  f145524:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f145528:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f14552c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f145530:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f145534:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f145538:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f14553c:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f145540:	0fc55fa0 */ 	jal	textRender
/*  f145544:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f145548:	0040a025 */ 	move	$s4,$v0
/*  f14554c:	0fc5bdaa */ 	jal	langGet
/*  f145550:	24045810 */ 	li	$a0,0x5810
/*  f145554:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145558:	24a57134 */ 	addiu	$a1,$a1,0x7134
/*  f14555c:	02602025 */ 	move	$a0,$s3
/*  f145560:	0c004d11 */ 	jal	sprintf
/*  f145564:	00403025 */ 	move	$a2,$v0
/*  f145568:	3c0e8008 */ 	lui	$t6,0x8008
/*  f14556c:	8dce0064 */ 	lw	$t6,0x64($t6)
/*  f145570:	3c078008 */ 	lui	$a3,0x8008
/*  f145574:	8ce70068 */ 	lw	$a3,0x68($a3)
/*  f145578:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f14557c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145580:	02603025 */ 	move	$a2,$s3
/*  f145584:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f145588:	0fc5609a */ 	jal	textMeasure
/*  f14558c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f145590:	8fa402ac */ 	lw	$a0,0x2ac($sp)
/*  f145594:	8faf030c */ 	lw	$t7,0x30c($sp)
/*  f145598:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f14559c:	10800003 */ 	beqz	$a0,.PF0f1455ac
/*  f1455a0:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f1455a4:	10000002 */ 	b	.PF0f1455b0
/*  f1455a8:	2402fffd */ 	li	$v0,-3
.PF0f1455ac:
/*  f1455ac:	00001025 */ 	move	$v0,$zero
.PF0f1455b0:
/*  f1455b0:	004f1821 */ 	addu	$v1,$v0,$t7
/*  f1455b4:	10800003 */ 	beqz	$a0,.PF0f1455c4
/*  f1455b8:	2463001e */ 	addiu	$v1,$v1,0x1e
/*  f1455bc:	10000002 */ 	b	.PF0f1455c8
/*  f1455c0:	24020012 */ 	li	$v0,0x12
.PF0f1455c4:
/*  f1455c4:	00001025 */ 	move	$v0,$zero
.PF0f1455c8:
/*  f1455c8:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f1455cc:	00584021 */ 	addu	$t0,$v0,$t8
/*  f1455d0:	2508ffd7 */ 	addiu	$t0,$t0,-41
/*  f1455d4:	27b802e0 */ 	addiu	$t8,$sp,0x2e0
/*  f1455d8:	0069c821 */ 	addu	$t9,$v1,$t1
/*  f1455dc:	010e7821 */ 	addu	$t7,$t0,$t6
/*  f1455e0:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f1455e4:	afb902e4 */ 	sw	$t9,0x2e4($sp)
/*  f1455e8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1455ec:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f1455f0:	02802025 */ 	move	$a0,$s4
/*  f1455f4:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f1455f8:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f1455fc:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f145600:	0fc5515b */ 	jal	func0f153858
/*  f145604:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f145608:	0c002e53 */ 	jal	viGetWidth
/*  f14560c:	0040a025 */ 	move	$s4,$v0
/*  f145610:	00028400 */ 	sll	$s0,$v0,0x10
/*  f145614:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f145618:	0c002e57 */ 	jal	viGetHeight
/*  f14561c:	03208025 */ 	move	$s0,$t9
/*  f145620:	3c0e8008 */ 	lui	$t6,0x8008
/*  f145624:	3c0f8008 */ 	lui	$t7,0x8008
/*  f145628:	8def0064 */ 	lw	$t7,0x64($t7)
/*  f14562c:	8dce0068 */ 	lw	$t6,0x68($t6)
/*  f145630:	8fb802bc */ 	lw	$t8,0x2bc($sp)
/*  f145634:	8fb902b8 */ 	lw	$t9,0x2b8($sp)
/*  f145638:	02802025 */ 	move	$a0,$s4
/*  f14563c:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f145640:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f145644:	02603825 */ 	move	$a3,$s3
/*  f145648:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f14564c:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f145650:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f145654:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f145658:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f14565c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f145660:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f145664:	0fc55fa0 */ 	jal	textRender
/*  f145668:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f14566c:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f145670:	0040a025 */ 	move	$s4,$v0
/*  f145674:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f145678:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f14567c:	5460000b */ 	bnezl	$v1,.PF0f1456ac
/*  f145680:	24010001 */ 	li	$at,0x1
/*  f145684:	0fc5bdaa */ 	jal	langGet
/*  f145688:	24045811 */ 	li	$a0,0x5811
/*  f14568c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145690:	24a57138 */ 	addiu	$a1,$a1,0x7138
/*  f145694:	02602025 */ 	move	$a0,$s3
/*  f145698:	0c004d11 */ 	jal	sprintf
/*  f14569c:	00403025 */ 	move	$a2,$v0
/*  f1456a0:	10000014 */ 	b	.PF0f1456f4
/*  f1456a4:	00000000 */ 	nop
/*  f1456a8:	24010001 */ 	li	$at,0x1
.PF0f1456ac:
/*  f1456ac:	1461000a */ 	bne	$v1,$at,.PF0f1456d8
/*  f1456b0:	00000000 */ 	nop
/*  f1456b4:	0fc5bdaa */ 	jal	langGet
/*  f1456b8:	24045893 */ 	li	$a0,0x5893
/*  f1456bc:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1456c0:	24a5713c */ 	addiu	$a1,$a1,0x713c
/*  f1456c4:	02602025 */ 	move	$a0,$s3
/*  f1456c8:	0c004d11 */ 	jal	sprintf
/*  f1456cc:	00403025 */ 	move	$a2,$v0
/*  f1456d0:	10000008 */ 	b	.PF0f1456f4
/*  f1456d4:	00000000 */ 	nop
.PF0f1456d8:
/*  f1456d8:	0fc5bdaa */ 	jal	langGet
/*  f1456dc:	2404589c */ 	li	$a0,0x589c
/*  f1456e0:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1456e4:	24a57140 */ 	addiu	$a1,$a1,0x7140
/*  f1456e8:	02602025 */ 	move	$a0,$s3
/*  f1456ec:	0c004d11 */ 	jal	sprintf
/*  f1456f0:	00403025 */ 	move	$a2,$v0
.PF0f1456f4:
/*  f1456f4:	3c188008 */ 	lui	$t8,0x8008
/*  f1456f8:	8f180064 */ 	lw	$t8,0x64($t8)
/*  f1456fc:	3c078008 */ 	lui	$a3,0x8008
/*  f145700:	8ce70068 */ 	lw	$a3,0x68($a3)
/*  f145704:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f145708:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f14570c:	02603025 */ 	move	$a2,$s3
/*  f145710:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f145714:	0fc5609a */ 	jal	textMeasure
/*  f145718:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f14571c:	8faa02ac */ 	lw	$t2,0x2ac($sp)
/*  f145720:	8fb9030c */ 	lw	$t9,0x30c($sp)
/*  f145724:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f145728:	11400003 */ 	beqz	$t2,.PF0f145738
/*  f14572c:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f145730:	10000002 */ 	b	.PF0f14573c
/*  f145734:	2402fffd */ 	li	$v0,-3
.PF0f145738:
/*  f145738:	00001025 */ 	move	$v0,$zero
.PF0f14573c:
/*  f14573c:	00591821 */ 	addu	$v1,$v0,$t9
/*  f145740:	11400003 */ 	beqz	$t2,.PF0f145750
/*  f145744:	2463001e */ 	addiu	$v1,$v1,0x1e
/*  f145748:	10000002 */ 	b	.PF0f145754
/*  f14574c:	24020014 */ 	li	$v0,0x14
.PF0f145750:
/*  f145750:	00001025 */ 	move	$v0,$zero
.PF0f145754:
/*  f145754:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f145758:	004e4021 */ 	addu	$t0,$v0,$t6
/*  f14575c:	2508ffde */ 	addiu	$t0,$t0,-34
/*  f145760:	27ae02e0 */ 	addiu	$t6,$sp,0x2e0
/*  f145764:	00697821 */ 	addu	$t7,$v1,$t1
/*  f145768:	0118c821 */ 	addu	$t9,$t0,$t8
/*  f14576c:	afb902e0 */ 	sw	$t9,0x2e0($sp)
/*  f145770:	afaf02e4 */ 	sw	$t7,0x2e4($sp)
/*  f145774:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f145778:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f14577c:	02802025 */ 	move	$a0,$s4
/*  f145780:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f145784:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f145788:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f14578c:	0fc5515b */ 	jal	func0f153858
/*  f145790:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f145794:	0c002e53 */ 	jal	viGetWidth
/*  f145798:	0040a025 */ 	move	$s4,$v0
/*  f14579c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1457a0:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f1457a4:	0c002e57 */ 	jal	viGetHeight
/*  f1457a8:	01e08025 */ 	move	$s0,$t7
/*  f1457ac:	3c188008 */ 	lui	$t8,0x8008
/*  f1457b0:	3c198008 */ 	lui	$t9,0x8008
/*  f1457b4:	8f390064 */ 	lw	$t9,0x64($t9)
/*  f1457b8:	8f180068 */ 	lw	$t8,0x68($t8)
/*  f1457bc:	8fae02bc */ 	lw	$t6,0x2bc($sp)
/*  f1457c0:	8faf02b8 */ 	lw	$t7,0x2b8($sp)
/*  f1457c4:	02802025 */ 	move	$a0,$s4
/*  f1457c8:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f1457cc:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f1457d0:	02603825 */ 	move	$a3,$s3
/*  f1457d4:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1457d8:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1457dc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1457e0:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1457e4:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1457e8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1457ec:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f1457f0:	0fc55fa0 */ 	jal	textRender
/*  f1457f4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f1457f8:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f1457fc:	0040a025 */ 	move	$s4,$v0
/*  f145800:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f145804:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f145808:	54600048 */ 	bnezl	$v1,.PF0f14592c
/*  f14580c:	24010001 */ 	li	$at,0x1
/*  f145810:	0fc5bdaa */ 	jal	langGet
/*  f145814:	24045812 */ 	li	$a0,0x5812
/*  f145818:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f14581c:	24a57144 */ 	addiu	$a1,$a1,0x7144
/*  f145820:	02602025 */ 	move	$a0,$s3
/*  f145824:	0c004d11 */ 	jal	sprintf
/*  f145828:	00403025 */ 	move	$a2,$v0
/*  f14582c:	3c0e8008 */ 	lui	$t6,0x8008
/*  f145830:	8dce0064 */ 	lw	$t6,0x64($t6)
/*  f145834:	3c078008 */ 	lui	$a3,0x8008
/*  f145838:	8ce70068 */ 	lw	$a3,0x68($a3)
/*  f14583c:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f145840:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145844:	02603025 */ 	move	$a2,$s3
/*  f145848:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f14584c:	0fc5609a */ 	jal	textMeasure
/*  f145850:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f145854:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f145858:	8faf0090 */ 	lw	$t7,0x90($sp)
/*  f14585c:	8fb802ac */ 	lw	$t8,0x2ac($sp)
/*  f145860:	8fb90304 */ 	lw	$t9,0x304($sp)
/*  f145864:	01e91823 */ 	subu	$v1,$t7,$t1
/*  f145868:	13000003 */ 	beqz	$t8,.PF0f145878
/*  f14586c:	2463ffe5 */ 	addiu	$v1,$v1,-27
/*  f145870:	10000002 */ 	b	.PF0f14587c
/*  f145874:	2402fff3 */ 	li	$v0,-13
.PF0f145878:
/*  f145878:	00001025 */ 	move	$v0,$zero
.PF0f14587c:
/*  f14587c:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f145880:	00594021 */ 	addu	$t0,$v0,$t9
/*  f145884:	2508001b */ 	addiu	$t0,$t0,0x1b
/*  f145888:	27b902e0 */ 	addiu	$t9,$sp,0x2e0
/*  f14588c:	00697021 */ 	addu	$t6,$v1,$t1
/*  f145890:	010fc021 */ 	addu	$t8,$t0,$t7
/*  f145894:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f145898:	afae02e4 */ 	sw	$t6,0x2e4($sp)
/*  f14589c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f1458a0:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f1458a4:	02802025 */ 	move	$a0,$s4
/*  f1458a8:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f1458ac:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f1458b0:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f1458b4:	0fc5515b */ 	jal	func0f153858
/*  f1458b8:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f1458bc:	0c002e53 */ 	jal	viGetWidth
/*  f1458c0:	0040a025 */ 	move	$s4,$v0
/*  f1458c4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1458c8:	00107403 */ 	sra	$t6,$s0,0x10
/*  f1458cc:	0c002e57 */ 	jal	viGetHeight
/*  f1458d0:	01c08025 */ 	move	$s0,$t6
/*  f1458d4:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1458d8:	3c188008 */ 	lui	$t8,0x8008
/*  f1458dc:	8f180064 */ 	lw	$t8,0x64($t8)
/*  f1458e0:	8def0068 */ 	lw	$t7,0x68($t7)
/*  f1458e4:	8fb902bc */ 	lw	$t9,0x2bc($sp)
/*  f1458e8:	8fae02b8 */ 	lw	$t6,0x2b8($sp)
/*  f1458ec:	02802025 */ 	move	$a0,$s4
/*  f1458f0:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f1458f4:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f1458f8:	02603825 */ 	move	$a3,$s3
/*  f1458fc:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f145900:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f145904:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f145908:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f14590c:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f145910:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f145914:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f145918:	0fc55fa0 */ 	jal	textRender
/*  f14591c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f145920:	1000008f */ 	b	.PF0f145b60
/*  f145924:	0040a025 */ 	move	$s4,$v0
/*  f145928:	24010001 */ 	li	$at,0x1
.PF0f14592c:
/*  f14592c:	14610047 */ 	bne	$v1,$at,.PF0f145a4c
/*  f145930:	00000000 */ 	nop
/*  f145934:	0fc5bdaa */ 	jal	langGet
/*  f145938:	240458d1 */ 	li	$a0,0x58d1
/*  f14593c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145940:	24a5714c */ 	addiu	$a1,$a1,0x714c
/*  f145944:	02602025 */ 	move	$a0,$s3
/*  f145948:	0c004d11 */ 	jal	sprintf
/*  f14594c:	00403025 */ 	move	$a2,$v0
/*  f145950:	3c0f8008 */ 	lui	$t7,0x8008
/*  f145954:	8def0064 */ 	lw	$t7,0x64($t7)
/*  f145958:	3c078008 */ 	lui	$a3,0x8008
/*  f14595c:	8ce70068 */ 	lw	$a3,0x68($a3)
/*  f145960:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f145964:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145968:	02603025 */ 	move	$a2,$s3
/*  f14596c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f145970:	0fc5609a */ 	jal	textMeasure
/*  f145974:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f145978:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f14597c:	8fb80090 */ 	lw	$t8,0x90($sp)
/*  f145980:	8fb902ac */ 	lw	$t9,0x2ac($sp)
/*  f145984:	8fae0304 */ 	lw	$t6,0x304($sp)
/*  f145988:	03091823 */ 	subu	$v1,$t8,$t1
/*  f14598c:	13200003 */ 	beqz	$t9,.PF0f14599c
/*  f145990:	2463ffe5 */ 	addiu	$v1,$v1,-27
/*  f145994:	10000002 */ 	b	.PF0f1459a0
/*  f145998:	2402fff3 */ 	li	$v0,-13
.PF0f14599c:
/*  f14599c:	00001025 */ 	move	$v0,$zero
.PF0f1459a0:
/*  f1459a0:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f1459a4:	004e4021 */ 	addu	$t0,$v0,$t6
/*  f1459a8:	2508001b */ 	addiu	$t0,$t0,0x1b
/*  f1459ac:	27ae02e0 */ 	addiu	$t6,$sp,0x2e0
/*  f1459b0:	00697821 */ 	addu	$t7,$v1,$t1
/*  f1459b4:	0118c821 */ 	addu	$t9,$t0,$t8
/*  f1459b8:	afb902e0 */ 	sw	$t9,0x2e0($sp)
/*  f1459bc:	afaf02e4 */ 	sw	$t7,0x2e4($sp)
/*  f1459c0:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1459c4:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f1459c8:	02802025 */ 	move	$a0,$s4
/*  f1459cc:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f1459d0:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f1459d4:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f1459d8:	0fc5515b */ 	jal	func0f153858
/*  f1459dc:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f1459e0:	0c002e53 */ 	jal	viGetWidth
/*  f1459e4:	0040a025 */ 	move	$s4,$v0
/*  f1459e8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1459ec:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f1459f0:	0c002e57 */ 	jal	viGetHeight
/*  f1459f4:	01e08025 */ 	move	$s0,$t7
/*  f1459f8:	3c188008 */ 	lui	$t8,0x8008
/*  f1459fc:	3c198008 */ 	lui	$t9,0x8008
/*  f145a00:	8f390064 */ 	lw	$t9,0x64($t9)
/*  f145a04:	8f180068 */ 	lw	$t8,0x68($t8)
/*  f145a08:	8fae02bc */ 	lw	$t6,0x2bc($sp)
/*  f145a0c:	8faf02b8 */ 	lw	$t7,0x2b8($sp)
/*  f145a10:	02802025 */ 	move	$a0,$s4
/*  f145a14:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f145a18:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f145a1c:	02603825 */ 	move	$a3,$s3
/*  f145a20:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f145a24:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f145a28:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f145a2c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f145a30:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f145a34:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f145a38:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f145a3c:	0fc55fa0 */ 	jal	textRender
/*  f145a40:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f145a44:	10000046 */ 	b	.PF0f145b60
/*  f145a48:	0040a025 */ 	move	$s4,$v0
.PF0f145a4c:
/*  f145a4c:	0fc5bdaa */ 	jal	langGet
/*  f145a50:	240458d2 */ 	li	$a0,0x58d2
/*  f145a54:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145a58:	24a57154 */ 	addiu	$a1,$a1,0x7154
/*  f145a5c:	02602025 */ 	move	$a0,$s3
/*  f145a60:	0c004d11 */ 	jal	sprintf
/*  f145a64:	00403025 */ 	move	$a2,$v0
/*  f145a68:	3c188008 */ 	lui	$t8,0x8008
/*  f145a6c:	8f180064 */ 	lw	$t8,0x64($t8)
/*  f145a70:	3c078008 */ 	lui	$a3,0x8008
/*  f145a74:	8ce70068 */ 	lw	$a3,0x68($a3)
/*  f145a78:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f145a7c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145a80:	02603025 */ 	move	$a2,$s3
/*  f145a84:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f145a88:	0fc5609a */ 	jal	textMeasure
/*  f145a8c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f145a90:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f145a94:	8fb90090 */ 	lw	$t9,0x90($sp)
/*  f145a98:	8fae02ac */ 	lw	$t6,0x2ac($sp)
/*  f145a9c:	8faf0304 */ 	lw	$t7,0x304($sp)
/*  f145aa0:	03291823 */ 	subu	$v1,$t9,$t1
/*  f145aa4:	11c00003 */ 	beqz	$t6,.PF0f145ab4
/*  f145aa8:	2463ffe5 */ 	addiu	$v1,$v1,-27
/*  f145aac:	10000002 */ 	b	.PF0f145ab8
/*  f145ab0:	2402fff3 */ 	li	$v0,-13
.PF0f145ab4:
/*  f145ab4:	00001025 */ 	move	$v0,$zero
.PF0f145ab8:
/*  f145ab8:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f145abc:	004f4021 */ 	addu	$t0,$v0,$t7
/*  f145ac0:	2508001b */ 	addiu	$t0,$t0,0x1b
/*  f145ac4:	27af02e0 */ 	addiu	$t7,$sp,0x2e0
/*  f145ac8:	0069c021 */ 	addu	$t8,$v1,$t1
/*  f145acc:	01197021 */ 	addu	$t6,$t0,$t9
/*  f145ad0:	afae02e0 */ 	sw	$t6,0x2e0($sp)
/*  f145ad4:	afb802e4 */ 	sw	$t8,0x2e4($sp)
/*  f145ad8:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f145adc:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f145ae0:	02802025 */ 	move	$a0,$s4
/*  f145ae4:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f145ae8:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f145aec:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f145af0:	0fc5515b */ 	jal	func0f153858
/*  f145af4:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f145af8:	0c002e53 */ 	jal	viGetWidth
/*  f145afc:	0040a025 */ 	move	$s4,$v0
/*  f145b00:	00028400 */ 	sll	$s0,$v0,0x10
/*  f145b04:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f145b08:	0c002e57 */ 	jal	viGetHeight
/*  f145b0c:	03008025 */ 	move	$s0,$t8
/*  f145b10:	3c198008 */ 	lui	$t9,0x8008
/*  f145b14:	3c0e8008 */ 	lui	$t6,0x8008
/*  f145b18:	8dce0064 */ 	lw	$t6,0x64($t6)
/*  f145b1c:	8f390068 */ 	lw	$t9,0x68($t9)
/*  f145b20:	8faf02bc */ 	lw	$t7,0x2bc($sp)
/*  f145b24:	8fb802b8 */ 	lw	$t8,0x2b8($sp)
/*  f145b28:	02802025 */ 	move	$a0,$s4
/*  f145b2c:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f145b30:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f145b34:	02603825 */ 	move	$a3,$s3
/*  f145b38:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f145b3c:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f145b40:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f145b44:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f145b48:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f145b4c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f145b50:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f145b54:	0fc55fa0 */ 	jal	textRender
/*  f145b58:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f145b5c:	0040a025 */ 	move	$s4,$v0
.PF0f145b60:
/*  f145b60:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f145b64:	8f2e0480 */ 	lw	$t6,0x480($t9)
/*  f145b68:	91c3006b */ 	lbu	$v1,0x6b($t6)
/*  f145b6c:	5460000b */ 	bnezl	$v1,.PF0f145b9c
/*  f145b70:	24010001 */ 	li	$at,0x1
/*  f145b74:	0fc5bdaa */ 	jal	langGet
/*  f145b78:	24045813 */ 	li	$a0,0x5813
/*  f145b7c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145b80:	24a5715c */ 	addiu	$a1,$a1,0x715c
/*  f145b84:	02602025 */ 	move	$a0,$s3
/*  f145b88:	0c004d11 */ 	jal	sprintf
/*  f145b8c:	00403025 */ 	move	$a2,$v0
/*  f145b90:	10000014 */ 	b	.PF0f145be4
/*  f145b94:	00000000 */ 	nop
/*  f145b98:	24010001 */ 	li	$at,0x1
.PF0f145b9c:
/*  f145b9c:	1461000a */ 	bne	$v1,$at,.PF0f145bc8
/*  f145ba0:	00000000 */ 	nop
/*  f145ba4:	0fc5bdaa */ 	jal	langGet
/*  f145ba8:	24045892 */ 	li	$a0,0x5892
/*  f145bac:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145bb0:	24a57160 */ 	addiu	$a1,$a1,0x7160
/*  f145bb4:	02602025 */ 	move	$a0,$s3
/*  f145bb8:	0c004d11 */ 	jal	sprintf
/*  f145bbc:	00403025 */ 	move	$a2,$v0
/*  f145bc0:	10000008 */ 	b	.PF0f145be4
/*  f145bc4:	00000000 */ 	nop
.PF0f145bc8:
/*  f145bc8:	0fc5bdaa */ 	jal	langGet
/*  f145bcc:	2404589b */ 	li	$a0,0x589b
/*  f145bd0:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145bd4:	24a57164 */ 	addiu	$a1,$a1,0x7164
/*  f145bd8:	02602025 */ 	move	$a0,$s3
/*  f145bdc:	0c004d11 */ 	jal	sprintf
/*  f145be0:	00403025 */ 	move	$a2,$v0
.PF0f145be4:
/*  f145be4:	3c0f8008 */ 	lui	$t7,0x8008
/*  f145be8:	8def0064 */ 	lw	$t7,0x64($t7)
/*  f145bec:	3c078008 */ 	lui	$a3,0x8008
/*  f145bf0:	8ce70068 */ 	lw	$a3,0x68($a3)
/*  f145bf4:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f145bf8:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145bfc:	02603025 */ 	move	$a2,$s3
/*  f145c00:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f145c04:	0fc5609a */ 	jal	textMeasure
/*  f145c08:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f145c0c:	8fb802ac */ 	lw	$t8,0x2ac($sp)
/*  f145c10:	8fb90090 */ 	lw	$t9,0x90($sp)
/*  f145c14:	02802025 */ 	move	$a0,$s4
/*  f145c18:	13000003 */ 	beqz	$t8,.PF0f145c28
/*  f145c1c:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f145c20:	10000002 */ 	b	.PF0f145c2c
/*  f145c24:	24020003 */ 	li	$v0,0x3
.PF0f145c28:
/*  f145c28:	00001025 */ 	move	$v0,$zero
.PF0f145c2c:
/*  f145c2c:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f145c30:	8faf02ac */ 	lw	$t7,0x2ac($sp)
/*  f145c34:	00597021 */ 	addu	$t6,$v0,$t9
/*  f145c38:	01c91823 */ 	subu	$v1,$t6,$t1
/*  f145c3c:	11e00003 */ 	beqz	$t7,.PF0f145c4c
/*  f145c40:	2463ffe5 */ 	addiu	$v1,$v1,-27
/*  f145c44:	10000002 */ 	b	.PF0f145c50
/*  f145c48:	2402fff5 */ 	li	$v0,-11
.PF0f145c4c:
/*  f145c4c:	00001025 */ 	move	$v0,$zero
.PF0f145c50:
/*  f145c50:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f145c54:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f145c58:	0069c821 */ 	addu	$t9,$v1,$t1
/*  f145c5c:	00584021 */ 	addu	$t0,$v0,$t8
/*  f145c60:	25080022 */ 	addiu	$t0,$t0,0x22
/*  f145c64:	27b802e0 */ 	addiu	$t8,$sp,0x2e0
/*  f145c68:	010e7821 */ 	addu	$t7,$t0,$t6
/*  f145c6c:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f145c70:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f145c74:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f145c78:	afb902e4 */ 	sw	$t9,0x2e4($sp)
/*  f145c7c:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f145c80:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f145c84:	0fc5515b */ 	jal	func0f153858
/*  f145c88:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f145c8c:	0c002e53 */ 	jal	viGetWidth
/*  f145c90:	0040a025 */ 	move	$s4,$v0
/*  f145c94:	00028400 */ 	sll	$s0,$v0,0x10
/*  f145c98:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f145c9c:	0c002e57 */ 	jal	viGetHeight
/*  f145ca0:	03208025 */ 	move	$s0,$t9
/*  f145ca4:	3c0e8008 */ 	lui	$t6,0x8008
/*  f145ca8:	3c0f8008 */ 	lui	$t7,0x8008
/*  f145cac:	8def0064 */ 	lw	$t7,0x64($t7)
/*  f145cb0:	8dce0068 */ 	lw	$t6,0x68($t6)
/*  f145cb4:	8fb802bc */ 	lw	$t8,0x2bc($sp)
/*  f145cb8:	8fb902b8 */ 	lw	$t9,0x2b8($sp)
/*  f145cbc:	02802025 */ 	move	$a0,$s4
/*  f145cc0:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f145cc4:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f145cc8:	02603825 */ 	move	$a3,$s3
/*  f145ccc:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f145cd0:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f145cd4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f145cd8:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f145cdc:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f145ce0:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f145ce4:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f145ce8:	0fc55fa0 */ 	jal	textRender
/*  f145cec:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f145cf0:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f145cf4:	0040a025 */ 	move	$s4,$v0
/*  f145cf8:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f145cfc:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f145d00:	10600003 */ 	beqz	$v1,.PF0f145d10
/*  f145d04:	24010002 */ 	li	$at,0x2
/*  f145d08:	1461000a */ 	bne	$v1,$at,.PF0f145d34
/*  f145d0c:	00000000 */ 	nop
.PF0f145d10:
/*  f145d10:	0fc5bdaa */ 	jal	langGet
/*  f145d14:	24045814 */ 	li	$a0,0x5814
/*  f145d18:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145d1c:	24a57168 */ 	addiu	$a1,$a1,0x7168
/*  f145d20:	02602025 */ 	move	$a0,$s3
/*  f145d24:	0c004d11 */ 	jal	sprintf
/*  f145d28:	00403025 */ 	move	$a2,$v0
/*  f145d2c:	10000008 */ 	b	.PF0f145d50
/*  f145d30:	00000000 */ 	nop
.PF0f145d34:
/*  f145d34:	0fc5bdaa */ 	jal	langGet
/*  f145d38:	24045891 */ 	li	$a0,0x5891
/*  f145d3c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f145d40:	24a5716c */ 	addiu	$a1,$a1,0x716c
/*  f145d44:	02602025 */ 	move	$a0,$s3
/*  f145d48:	0c004d11 */ 	jal	sprintf
/*  f145d4c:	00403025 */ 	move	$a2,$v0
.PF0f145d50:
/*  f145d50:	3c188008 */ 	lui	$t8,0x8008
/*  f145d54:	8f180064 */ 	lw	$t8,0x64($t8)
/*  f145d58:	3c078008 */ 	lui	$a3,0x8008
/*  f145d5c:	8ce70068 */ 	lw	$a3,0x68($a3)
/*  f145d60:	27a402e8 */ 	addiu	$a0,$sp,0x2e8
/*  f145d64:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f145d68:	02603025 */ 	move	$a2,$s3
/*  f145d6c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f145d70:	0fc5609a */ 	jal	textMeasure
/*  f145d74:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f145d78:	8fa902ec */ 	lw	$t1,0x2ec($sp)
/*  f145d7c:	8fb90090 */ 	lw	$t9,0x90($sp)
/*  f145d80:	8fae02ac */ 	lw	$t6,0x2ac($sp)
/*  f145d84:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f145d88:	03291823 */ 	subu	$v1,$t9,$t1
/*  f145d8c:	11c00003 */ 	beqz	$t6,.PF0f145d9c
/*  f145d90:	2463ffe5 */ 	addiu	$v1,$v1,-27
/*  f145d94:	10000002 */ 	b	.PF0f145da0
/*  f145d98:	2402fffe */ 	li	$v0,-2
.PF0f145d9c:
/*  f145d9c:	00001025 */ 	move	$v0,$zero
.PF0f145da0:
/*  f145da0:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f145da4:	004f4021 */ 	addu	$t0,$v0,$t7
/*  f145da8:	2508fff4 */ 	addiu	$t0,$t0,-12
/*  f145dac:	27af02e0 */ 	addiu	$t7,$sp,0x2e0
/*  f145db0:	0069c021 */ 	addu	$t8,$v1,$t1
/*  f145db4:	01197021 */ 	addu	$t6,$t0,$t9
/*  f145db8:	afae02e0 */ 	sw	$t6,0x2e0($sp)
/*  f145dbc:	afb802e4 */ 	sw	$t8,0x2e4($sp)
/*  f145dc0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f145dc4:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f145dc8:	02802025 */ 	move	$a0,$s4
/*  f145dcc:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f145dd0:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f145dd4:	27a702e4 */ 	addiu	$a3,$sp,0x2e4
/*  f145dd8:	0fc5515b */ 	jal	func0f153858
/*  f145ddc:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f145de0:	0c002e53 */ 	jal	viGetWidth
/*  f145de4:	0040a025 */ 	move	$s4,$v0
/*  f145de8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f145dec:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f145df0:	0c002e57 */ 	jal	viGetHeight
/*  f145df4:	03008025 */ 	move	$s0,$t8
/*  f145df8:	3c198008 */ 	lui	$t9,0x8008
/*  f145dfc:	3c0e8008 */ 	lui	$t6,0x8008
/*  f145e00:	8dce0064 */ 	lw	$t6,0x64($t6)
/*  f145e04:	8f390068 */ 	lw	$t9,0x68($t9)
/*  f145e08:	8faf02bc */ 	lw	$t7,0x2bc($sp)
/*  f145e0c:	8fb802b8 */ 	lw	$t8,0x2b8($sp)
/*  f145e10:	02802025 */ 	move	$a0,$s4
/*  f145e14:	27a502f4 */ 	addiu	$a1,$sp,0x2f4
/*  f145e18:	27a602f0 */ 	addiu	$a2,$sp,0x2f0
/*  f145e1c:	02603825 */ 	move	$a3,$s3
/*  f145e20:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f145e24:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f145e28:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f145e2c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f145e30:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f145e34:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f145e38:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f145e3c:	0fc55fa0 */ 	jal	textRender
/*  f145e40:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f145e44:	0fc55153 */ 	jal	func0f153838
/*  f145e48:	00402025 */ 	move	$a0,$v0
/*  f145e4c:	8ed90288 */ 	lw	$t9,0x288($s6)
/*  f145e50:	0040a025 */ 	move	$s4,$v0
/*  f145e54:	0fc54cfe */ 	jal	optionsGetContpadNum1
/*  f145e58:	8f240070 */ 	lw	$a0,0x70($t9)
/*  f145e5c:	00028600 */ 	sll	$s0,$v0,0x18
/*  f145e60:	00022600 */ 	sll	$a0,$v0,0x18
/*  f145e64:	00107603 */ 	sra	$t6,$s0,0x18
/*  f145e68:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f145e6c:	01c08025 */ 	move	$s0,$t6
/*  f145e70:	01e02025 */ 	move	$a0,$t7
/*  f145e74:	0c00533a */ 	jal	joyGetButtons
/*  f145e78:	3405ffff */ 	li	$a1,0xffff
/*  f145e7c:	00102600 */ 	sll	$a0,$s0,0x18
/*  f145e80:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f145e84:	03002025 */ 	move	$a0,$t8
/*  f145e88:	3051ffff */ 	andi	$s1,$v0,0xffff
/*  f145e8c:	0c00536a */ 	jal	joyGetButtonsPressedThisFrame
/*  f145e90:	3405ffff */ 	li	$a1,0xffff
/*  f145e94:	00102600 */ 	sll	$a0,$s0,0x18
/*  f145e98:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f145e9c:	3053ffff */ 	andi	$s3,$v0,0xffff
/*  f145ea0:	0c0052e6 */ 	jal	joyGetStickX
/*  f145ea4:	03202025 */ 	move	$a0,$t9
/*  f145ea8:	0002ae00 */ 	sll	$s5,$v0,0x18
/*  f145eac:	00102600 */ 	sll	$a0,$s0,0x18
/*  f145eb0:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f145eb4:	00157603 */ 	sra	$t6,$s5,0x18
/*  f145eb8:	01c0a825 */ 	move	$s5,$t6
/*  f145ebc:	0c005310 */ 	jal	joyGetStickY
/*  f145ec0:	01e02025 */ 	move	$a0,$t7
/*  f145ec4:	02801825 */ 	move	$v1,$s4
/*  f145ec8:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f145ecc:	3c10e700 */ 	lui	$s0,0xe700
/*  f145ed0:	02802025 */ 	move	$a0,$s4
/*  f145ed4:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f145ed8:	ac700000 */ 	sw	$s0,0x0($v1)
/*  f145edc:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f145ee0:	3c18ba00 */ 	lui	$t8,0xba00
/*  f145ee4:	37181402 */ 	ori	$t8,$t8,0x1402
/*  f145ee8:	02802825 */ 	move	$a1,$s4
/*  f145eec:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f145ef0:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f145ef4:	3c19ba00 */ 	lui	$t9,0xba00
/*  f145ef8:	37390602 */ 	ori	$t9,$t9,0x602
/*  f145efc:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f145f00:	240e00c0 */ 	li	$t6,0xc0
/*  f145f04:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f145f08:	02803025 */ 	move	$a2,$s4
/*  f145f0c:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f145f10:	3c0fba00 */ 	lui	$t7,0xba00
/*  f145f14:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f145f18:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f145f1c:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f145f20:	02803825 */ 	move	$a3,$s4
/*  f145f24:	acc00004 */ 	sw	$zero,0x4($a2)
/*  f145f28:	3c18b900 */ 	lui	$t8,0xb900
/*  f145f2c:	37180002 */ 	ori	$t8,$t8,0x2
/*  f145f30:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f145f34:	02801825 */ 	move	$v1,$s4
/*  f145f38:	acf80000 */ 	sw	$t8,0x0($a3)
/*  f145f3c:	3c19ba00 */ 	lui	$t9,0xba00
/*  f145f40:	37391001 */ 	ori	$t9,$t9,0x1001
/*  f145f44:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f145f48:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f145f4c:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f145f50:	02802025 */ 	move	$a0,$s4
/*  f145f54:	3c0eba00 */ 	lui	$t6,0xba00
/*  f145f58:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f145f5c:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f145f60:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f145f64:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f145f68:	02802825 */ 	move	$a1,$s4
/*  f145f6c:	240f2000 */ 	li	$t7,0x2000
/*  f145f70:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f145f74:	3c18ba00 */ 	lui	$t8,0xba00
/*  f145f78:	37180903 */ 	ori	$t8,$t8,0x903
/*  f145f7c:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f145f80:	24190c00 */ 	li	$t9,0xc00
/*  f145f84:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f145f88:	02803025 */ 	move	$a2,$s4
/*  f145f8c:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f145f90:	3c0eba00 */ 	lui	$t6,0xba00
/*  f145f94:	35ce0e02 */ 	ori	$t6,$t6,0xe02
/*  f145f98:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f145f9c:	02804025 */ 	move	$t0,$s4
/*  f145fa0:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f145fa4:	acc00004 */ 	sw	$zero,0x4($a2)
/*  f145fa8:	3c180050 */ 	lui	$t8,0x50
/*  f145fac:	3c0fb900 */ 	lui	$t7,0xb900
/*  f145fb0:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f145fb4:	37184340 */ 	ori	$t8,$t8,0x4340
/*  f145fb8:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f145fbc:	02801825 */ 	move	$v1,$s4
/*  f145fc0:	ad180004 */ 	sw	$t8,0x4($t0)
/*  f145fc4:	ad0f0000 */ 	sw	$t7,0x0($t0)
/*  f145fc8:	3c0efffd */ 	lui	$t6,0xfffd
/*  f145fcc:	3c19fcff */ 	lui	$t9,0xfcff
/*  f145fd0:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f145fd4:	35cef6fb */ 	ori	$t6,$t6,0xf6fb
/*  f145fd8:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f145fdc:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f145fe0:	8faf02ac */ 	lw	$t7,0x2ac($sp)
/*  f145fe4:	44954000 */ 	mtc1	$s5,$f8
/*  f145fe8:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f145fec:	15e001d9 */ 	bnez	$t7,.PF0f146754
/*  f145ff0:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f145ff4:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f145ff8:	2405ffab */ 	li	$a1,-85
/*  f145ffc:	24010001 */ 	li	$at,0x1
/*  f146000:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f146004:	24120014 */ 	li	$s2,0x14
/*  f146008:	322e0808 */ 	andi	$t6,$s1,0x808
/*  f14600c:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f146010:	326f0808 */ 	andi	$t7,$s3,0x808
/*  f146014:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f146018:	14600011 */ 	bnez	$v1,.PF0f146060
/*  f14601c:	3c0b1020 */ 	lui	$t3,0x1020
/*  f146020:	11c00002 */ 	beqz	$t6,.PF0f14602c
/*  f146024:	02203025 */ 	move	$a2,$s1
/*  f146028:	24120028 */ 	li	$s2,0x28
.PF0f14602c:
/*  f14602c:	11e00004 */ 	beqz	$t7,.PF0f146040
/*  f146030:	02603825 */ 	move	$a3,$s3
/*  f146034:	26520014 */ 	addiu	$s2,$s2,0x14
/*  f146038:	325800ff */ 	andi	$t8,$s2,0xff
/*  f14603c:	03009025 */ 	move	$s2,$t8
.PF0f146040:
/*  f146040:	325900ff */ 	andi	$t9,$s2,0xff
/*  f146044:	00197400 */ 	sll	$t6,$t9,0x10
/*  f146048:	02801825 */ 	move	$v1,$s4
/*  f14604c:	35cf00ff */ 	ori	$t7,$t6,0xff
/*  f146050:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f146054:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146058:	1000002f */ 	b	.PF0f146118
/*  f14605c:	26940008 */ 	addiu	$s4,$s4,0x8
.PF0f146060:
/*  f146060:	14610017 */ 	bne	$v1,$at,.PF0f1460c0
/*  f146064:	24120014 */ 	li	$s2,0x14
/*  f146068:	32380808 */ 	andi	$t8,$s1,0x808
/*  f14606c:	2412007f */ 	li	$s2,0x7f
/*  f146070:	13000002 */ 	beqz	$t8,.PF0f14607c
/*  f146074:	02203025 */ 	move	$a2,$s1
/*  f146078:	241200be */ 	li	$s2,0xbe
.PF0f14607c:
/*  f14607c:	32790808 */ 	andi	$t9,$s3,0x808
/*  f146080:	13200004 */ 	beqz	$t9,.PF0f146094
/*  f146084:	02603825 */ 	move	$a3,$s3
/*  f146088:	2652003f */ 	addiu	$s2,$s2,0x3f
/*  f14608c:	324e00ff */ 	andi	$t6,$s2,0xff
/*  f146090:	01c09025 */ 	move	$s2,$t6
.PF0f146094:
/*  f146094:	324f00ff */ 	andi	$t7,$s2,0xff
/*  f146098:	000fc200 */ 	sll	$t8,$t7,0x8
/*  f14609c:	3c0b1020 */ 	lui	$t3,0x1020
/*  f1460a0:	030bc825 */ 	or	$t9,$t8,$t3
/*  f1460a4:	02801825 */ 	move	$v1,$s4
/*  f1460a8:	372e00ff */ 	ori	$t6,$t9,0xff
/*  f1460ac:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f1460b0:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1460b4:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f1460b8:	10000017 */ 	b	.PF0f146118
/*  f1460bc:	26940008 */ 	addiu	$s4,$s4,0x8
.PF0f1460c0:
/*  f1460c0:	322f0808 */ 	andi	$t7,$s1,0x808
/*  f1460c4:	11e00002 */ 	beqz	$t7,.PF0f1460d0
/*  f1460c8:	02203025 */ 	move	$a2,$s1
/*  f1460cc:	24120028 */ 	li	$s2,0x28
.PF0f1460d0:
/*  f1460d0:	32780808 */ 	andi	$t8,$s3,0x808
/*  f1460d4:	13000004 */ 	beqz	$t8,.PF0f1460e8
/*  f1460d8:	02603825 */ 	move	$a3,$s3
/*  f1460dc:	26520014 */ 	addiu	$s2,$s2,0x14
/*  f1460e0:	325900ff */ 	andi	$t9,$s2,0xff
/*  f1460e4:	03209025 */ 	move	$s2,$t9
.PF0f1460e8:
/*  f1460e8:	0012c083 */ 	sra	$t8,$s2,0x2
/*  f1460ec:	331900ff */ 	andi	$t9,$t8,0xff
/*  f1460f0:	00197400 */ 	sll	$t6,$t9,0x10
/*  f1460f4:	02801825 */ 	move	$v1,$s4
/*  f1460f8:	00127e00 */ 	sll	$t7,$s2,0x18
/*  f1460fc:	01eec025 */ 	or	$t8,$t7,$t6
/*  f146100:	371900ff */ 	ori	$t9,$t8,0xff
/*  f146104:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f146108:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f14610c:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f146110:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146114:	3c0b1020 */ 	lui	$t3,0x1020
.PF0f146118:
/*  f146118:	8fbf0090 */ 	lw	$ra,0x90($sp)
/*  f14611c:	8fac0304 */ 	lw	$t4,0x304($sp)
/*  f146120:	3c01f600 */ 	lui	$at,0xf600
/*  f146124:	00bf5021 */ 	addu	$t2,$a1,$ra
/*  f146128:	254a0008 */ 	addiu	$t2,$t2,0x8
/*  f14612c:	258c0012 */ 	addiu	$t4,$t4,0x12
/*  f146130:	318f03ff */ 	andi	$t7,$t4,0x3ff
/*  f146134:	315803ff */ 	andi	$t8,$t2,0x3ff
/*  f146138:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f14613c:	000f6080 */ 	sll	$t4,$t7,0x2
/*  f146140:	03217825 */ 	or	$t7,$t9,$at
/*  f146144:	01ec7025 */ 	or	$t6,$t7,$t4
/*  f146148:	02802025 */ 	move	$a0,$s4
/*  f14614c:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f146150:	8fad0304 */ 	lw	$t5,0x304($sp)
/*  f146154:	00bf4021 */ 	addu	$t0,$a1,$ra
/*  f146158:	310f03ff */ 	andi	$t7,$t0,0x3ff
/*  f14615c:	25ad000a */ 	addiu	$t5,$t5,0xa
/*  f146160:	31b803ff */ 	andi	$t8,$t5,0x3ff
/*  f146164:	00186880 */ 	sll	$t5,$t8,0x2
/*  f146168:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f14616c:	01cdc025 */ 	or	$t8,$t6,$t5
/*  f146170:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f146174:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f146178:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f14617c:	2508000a */ 	addiu	$t0,$t0,0xa
/*  f146180:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f146184:	254a000a */ 	addiu	$t2,$t2,0xa
/*  f146188:	30f80404 */ 	andi	$t8,$a3,0x404
/*  f14618c:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f146190:	30ce0404 */ 	andi	$t6,$a2,0x404
/*  f146194:	24010001 */ 	li	$at,0x1
/*  f146198:	14600010 */ 	bnez	$v1,.PF0f1461dc
/*  f14619c:	00000000 */ 	nop
/*  f1461a0:	11c00002 */ 	beqz	$t6,.PF0f1461ac
/*  f1461a4:	24120014 */ 	li	$s2,0x14
/*  f1461a8:	24120028 */ 	li	$s2,0x28
.PF0f1461ac:
/*  f1461ac:	13000004 */ 	beqz	$t8,.PF0f1461c0
/*  f1461b0:	02801825 */ 	move	$v1,$s4
/*  f1461b4:	26520014 */ 	addiu	$s2,$s2,0x14
/*  f1461b8:	325900ff */ 	andi	$t9,$s2,0xff
/*  f1461bc:	03209025 */ 	move	$s2,$t9
.PF0f1461c0:
/*  f1461c0:	324f00ff */ 	andi	$t7,$s2,0xff
/*  f1461c4:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f1461c8:	35d800ff */ 	ori	$t8,$t6,0xff
/*  f1461cc:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f1461d0:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f1461d4:	10000027 */ 	b	.PF0f146274
/*  f1461d8:	ac690000 */ 	sw	$t1,0x0($v1)
.PF0f1461dc:
/*  f1461dc:	14610013 */ 	bne	$v1,$at,.PF0f14622c
/*  f1461e0:	30d80404 */ 	andi	$t8,$a2,0x404
/*  f1461e4:	30d90404 */ 	andi	$t9,$a2,0x404
/*  f1461e8:	13200002 */ 	beqz	$t9,.PF0f1461f4
/*  f1461ec:	2412007f */ 	li	$s2,0x7f
/*  f1461f0:	241200be */ 	li	$s2,0xbe
.PF0f1461f4:
/*  f1461f4:	30ef0404 */ 	andi	$t7,$a3,0x404
/*  f1461f8:	11e00004 */ 	beqz	$t7,.PF0f14620c
/*  f1461fc:	02801825 */ 	move	$v1,$s4
/*  f146200:	2652003f */ 	addiu	$s2,$s2,0x3f
/*  f146204:	324e00ff */ 	andi	$t6,$s2,0xff
/*  f146208:	01c09025 */ 	move	$s2,$t6
.PF0f14620c:
/*  f14620c:	325800ff */ 	andi	$t8,$s2,0xff
/*  f146210:	0018ca00 */ 	sll	$t9,$t8,0x8
/*  f146214:	032b7825 */ 	or	$t7,$t9,$t3
/*  f146218:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f14621c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f146220:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146224:	10000013 */ 	b	.PF0f146274
/*  f146228:	ac690000 */ 	sw	$t1,0x0($v1)
.PF0f14622c:
/*  f14622c:	13000002 */ 	beqz	$t8,.PF0f146238
/*  f146230:	24120014 */ 	li	$s2,0x14
/*  f146234:	24120028 */ 	li	$s2,0x28
.PF0f146238:
/*  f146238:	30f90404 */ 	andi	$t9,$a3,0x404
/*  f14623c:	13200004 */ 	beqz	$t9,.PF0f146250
/*  f146240:	02801825 */ 	move	$v1,$s4
/*  f146244:	26520014 */ 	addiu	$s2,$s2,0x14
/*  f146248:	324f00ff */ 	andi	$t7,$s2,0xff
/*  f14624c:	01e09025 */ 	move	$s2,$t7
.PF0f146250:
/*  f146250:	0012c883 */ 	sra	$t9,$s2,0x2
/*  f146254:	332f00ff */ 	andi	$t7,$t9,0xff
/*  f146258:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f14625c:	0012c600 */ 	sll	$t8,$s2,0x18
/*  f146260:	030ec825 */ 	or	$t9,$t8,$t6
/*  f146264:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f146268:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f14626c:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146270:	ac690000 */ 	sw	$t1,0x0($v1)
.PF0f146274:
/*  f146274:	315803ff */ 	andi	$t8,$t2,0x3ff
/*  f146278:	00187380 */ 	sll	$t6,$t8,0xe
/*  f14627c:	3c01f600 */ 	lui	$at,0xf600
/*  f146280:	01c1c825 */ 	or	$t9,$t6,$at
/*  f146284:	311803ff */ 	andi	$t8,$t0,0x3ff
/*  f146288:	00187380 */ 	sll	$t6,$t8,0xe
/*  f14628c:	032c7825 */ 	or	$t7,$t9,$t4
/*  f146290:	02802025 */ 	move	$a0,$s4
/*  f146294:	01cdc825 */ 	or	$t9,$t6,$t5
/*  f146298:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f14629c:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f1462a0:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f1462a4:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f1462a8:	2508000a */ 	addiu	$t0,$t0,0xa
/*  f1462ac:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f1462b0:	254a000a */ 	addiu	$t2,$t2,0xa
/*  f1462b4:	30f90202 */ 	andi	$t9,$a3,0x202
/*  f1462b8:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f1462bc:	30ce0202 */ 	andi	$t6,$a2,0x202
/*  f1462c0:	24010001 */ 	li	$at,0x1
/*  f1462c4:	14600010 */ 	bnez	$v1,.PF0f146308
/*  f1462c8:	00000000 */ 	nop
/*  f1462cc:	11c00002 */ 	beqz	$t6,.PF0f1462d8
/*  f1462d0:	24120014 */ 	li	$s2,0x14
/*  f1462d4:	24120028 */ 	li	$s2,0x28
.PF0f1462d8:
/*  f1462d8:	13200004 */ 	beqz	$t9,.PF0f1462ec
/*  f1462dc:	02801825 */ 	move	$v1,$s4
/*  f1462e0:	26520014 */ 	addiu	$s2,$s2,0x14
/*  f1462e4:	324f00ff */ 	andi	$t7,$s2,0xff
/*  f1462e8:	01e09025 */ 	move	$s2,$t7
.PF0f1462ec:
/*  f1462ec:	325800ff */ 	andi	$t8,$s2,0xff
/*  f1462f0:	00187400 */ 	sll	$t6,$t8,0x10
/*  f1462f4:	35d900ff */ 	ori	$t9,$t6,0xff
/*  f1462f8:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f1462fc:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146300:	10000027 */ 	b	.PF0f1463a0
/*  f146304:	ac690000 */ 	sw	$t1,0x0($v1)
.PF0f146308:
/*  f146308:	14610013 */ 	bne	$v1,$at,.PF0f146358
/*  f14630c:	30d90202 */ 	andi	$t9,$a2,0x202
/*  f146310:	30cf0202 */ 	andi	$t7,$a2,0x202
/*  f146314:	11e00002 */ 	beqz	$t7,.PF0f146320
/*  f146318:	2412007f */ 	li	$s2,0x7f
/*  f14631c:	241200be */ 	li	$s2,0xbe
.PF0f146320:
/*  f146320:	30f80202 */ 	andi	$t8,$a3,0x202
/*  f146324:	13000004 */ 	beqz	$t8,.PF0f146338
/*  f146328:	02801825 */ 	move	$v1,$s4
/*  f14632c:	2652003f */ 	addiu	$s2,$s2,0x3f
/*  f146330:	324e00ff */ 	andi	$t6,$s2,0xff
/*  f146334:	01c09025 */ 	move	$s2,$t6
.PF0f146338:
/*  f146338:	325900ff */ 	andi	$t9,$s2,0xff
/*  f14633c:	00197a00 */ 	sll	$t7,$t9,0x8
/*  f146340:	01ebc025 */ 	or	$t8,$t7,$t3
/*  f146344:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f146348:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f14634c:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146350:	10000013 */ 	b	.PF0f1463a0
/*  f146354:	ac690000 */ 	sw	$t1,0x0($v1)
.PF0f146358:
/*  f146358:	13200002 */ 	beqz	$t9,.PF0f146364
/*  f14635c:	24120014 */ 	li	$s2,0x14
/*  f146360:	24120028 */ 	li	$s2,0x28
.PF0f146364:
/*  f146364:	30ef0202 */ 	andi	$t7,$a3,0x202
/*  f146368:	11e00004 */ 	beqz	$t7,.PF0f14637c
/*  f14636c:	02801825 */ 	move	$v1,$s4
/*  f146370:	26520014 */ 	addiu	$s2,$s2,0x14
/*  f146374:	325800ff */ 	andi	$t8,$s2,0xff
/*  f146378:	03009025 */ 	move	$s2,$t8
.PF0f14637c:
/*  f14637c:	00127883 */ 	sra	$t7,$s2,0x2
/*  f146380:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f146384:	00187400 */ 	sll	$t6,$t8,0x10
/*  f146388:	0012ce00 */ 	sll	$t9,$s2,0x18
/*  f14638c:	032e7825 */ 	or	$t7,$t9,$t6
/*  f146390:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f146394:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f146398:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f14639c:	ac690000 */ 	sw	$t1,0x0($v1)
.PF0f1463a0:
/*  f1463a0:	315903ff */ 	andi	$t9,$t2,0x3ff
/*  f1463a4:	00197380 */ 	sll	$t6,$t9,0xe
/*  f1463a8:	3c01f600 */ 	lui	$at,0xf600
/*  f1463ac:	01c17825 */ 	or	$t7,$t6,$at
/*  f1463b0:	311903ff */ 	andi	$t9,$t0,0x3ff
/*  f1463b4:	00197380 */ 	sll	$t6,$t9,0xe
/*  f1463b8:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f1463bc:	02802025 */ 	move	$a0,$s4
/*  f1463c0:	01cd7825 */ 	or	$t7,$t6,$t5
/*  f1463c4:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f1463c8:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f1463cc:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f1463d0:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f1463d4:	2508000a */ 	addiu	$t0,$t0,0xa
/*  f1463d8:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f1463dc:	254a000a */ 	addiu	$t2,$t2,0xa
/*  f1463e0:	30ef0101 */ 	andi	$t7,$a3,0x101
/*  f1463e4:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f1463e8:	30ce0101 */ 	andi	$t6,$a2,0x101
/*  f1463ec:	24010001 */ 	li	$at,0x1
/*  f1463f0:	14600010 */ 	bnez	$v1,.PF0f146434
/*  f1463f4:	00000000 */ 	nop
/*  f1463f8:	11c00002 */ 	beqz	$t6,.PF0f146404
/*  f1463fc:	24120014 */ 	li	$s2,0x14
/*  f146400:	24120028 */ 	li	$s2,0x28
.PF0f146404:
/*  f146404:	11e00004 */ 	beqz	$t7,.PF0f146418
/*  f146408:	02801825 */ 	move	$v1,$s4
/*  f14640c:	26520014 */ 	addiu	$s2,$s2,0x14
/*  f146410:	325800ff */ 	andi	$t8,$s2,0xff
/*  f146414:	03009025 */ 	move	$s2,$t8
.PF0f146418:
/*  f146418:	325900ff */ 	andi	$t9,$s2,0xff
/*  f14641c:	00197400 */ 	sll	$t6,$t9,0x10
/*  f146420:	35cf00ff */ 	ori	$t7,$t6,0xff
/*  f146424:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f146428:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f14642c:	10000027 */ 	b	.PF0f1464cc
/*  f146430:	ac690000 */ 	sw	$t1,0x0($v1)
.PF0f146434:
/*  f146434:	14610013 */ 	bne	$v1,$at,.PF0f146484
/*  f146438:	30cf0101 */ 	andi	$t7,$a2,0x101
/*  f14643c:	30d80101 */ 	andi	$t8,$a2,0x101
/*  f146440:	13000002 */ 	beqz	$t8,.PF0f14644c
/*  f146444:	2412007f */ 	li	$s2,0x7f
/*  f146448:	241200be */ 	li	$s2,0xbe
.PF0f14644c:
/*  f14644c:	30f90101 */ 	andi	$t9,$a3,0x101
/*  f146450:	13200004 */ 	beqz	$t9,.PF0f146464
/*  f146454:	02801825 */ 	move	$v1,$s4
/*  f146458:	2652003f */ 	addiu	$s2,$s2,0x3f
/*  f14645c:	324e00ff */ 	andi	$t6,$s2,0xff
/*  f146460:	01c09025 */ 	move	$s2,$t6
.PF0f146464:
/*  f146464:	324f00ff */ 	andi	$t7,$s2,0xff
/*  f146468:	000fc200 */ 	sll	$t8,$t7,0x8
/*  f14646c:	030bc825 */ 	or	$t9,$t8,$t3
/*  f146470:	372e00ff */ 	ori	$t6,$t9,0xff
/*  f146474:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f146478:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f14647c:	10000013 */ 	b	.PF0f1464cc
/*  f146480:	ac690000 */ 	sw	$t1,0x0($v1)
.PF0f146484:
/*  f146484:	11e00002 */ 	beqz	$t7,.PF0f146490
/*  f146488:	24120014 */ 	li	$s2,0x14
/*  f14648c:	24120028 */ 	li	$s2,0x28
.PF0f146490:
/*  f146490:	30f80101 */ 	andi	$t8,$a3,0x101
/*  f146494:	13000004 */ 	beqz	$t8,.PF0f1464a8
/*  f146498:	02801825 */ 	move	$v1,$s4
/*  f14649c:	26520014 */ 	addiu	$s2,$s2,0x14
/*  f1464a0:	325900ff */ 	andi	$t9,$s2,0xff
/*  f1464a4:	03209025 */ 	move	$s2,$t9
.PF0f1464a8:
/*  f1464a8:	0012c083 */ 	sra	$t8,$s2,0x2
/*  f1464ac:	331900ff */ 	andi	$t9,$t8,0xff
/*  f1464b0:	00197400 */ 	sll	$t6,$t9,0x10
/*  f1464b4:	00127e00 */ 	sll	$t7,$s2,0x18
/*  f1464b8:	01eec025 */ 	or	$t8,$t7,$t6
/*  f1464bc:	371900ff */ 	ori	$t9,$t8,0xff
/*  f1464c0:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f1464c4:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f1464c8:	ac690000 */ 	sw	$t1,0x0($v1)
.PF0f1464cc:
/*  f1464cc:	314f03ff */ 	andi	$t7,$t2,0x3ff
/*  f1464d0:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f1464d4:	3c01f600 */ 	lui	$at,0xf600
/*  f1464d8:	01c1c025 */ 	or	$t8,$t6,$at
/*  f1464dc:	310f03ff */ 	andi	$t7,$t0,0x3ff
/*  f1464e0:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f1464e4:	030cc825 */ 	or	$t9,$t8,$t4
/*  f1464e8:	02802025 */ 	move	$a0,$s4
/*  f1464ec:	01cdc025 */ 	or	$t8,$t6,$t5
/*  f1464f0:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f1464f4:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f1464f8:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f1464fc:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146500:	2508000a */ 	addiu	$t0,$t0,0xa
/*  f146504:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f146508:	254a000a */ 	addiu	$t2,$t2,0xa
/*  f14650c:	30f80030 */ 	andi	$t8,$a3,0x30
/*  f146510:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f146514:	30ce0030 */ 	andi	$t6,$a2,0x30
/*  f146518:	24010001 */ 	li	$at,0x1
/*  f14651c:	14600010 */ 	bnez	$v1,.PF0f146560
/*  f146520:	00000000 */ 	nop
/*  f146524:	11c00002 */ 	beqz	$t6,.PF0f146530
/*  f146528:	24120014 */ 	li	$s2,0x14
/*  f14652c:	24120028 */ 	li	$s2,0x28
.PF0f146530:
/*  f146530:	13000004 */ 	beqz	$t8,.PF0f146544
/*  f146534:	02801825 */ 	move	$v1,$s4
/*  f146538:	26520014 */ 	addiu	$s2,$s2,0x14
/*  f14653c:	325900ff */ 	andi	$t9,$s2,0xff
/*  f146540:	03209025 */ 	move	$s2,$t9
.PF0f146544:
/*  f146544:	324f00ff */ 	andi	$t7,$s2,0xff
/*  f146548:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f14654c:	35d800ff */ 	ori	$t8,$t6,0xff
/*  f146550:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f146554:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146558:	10000027 */ 	b	.PF0f1465f8
/*  f14655c:	ac690000 */ 	sw	$t1,0x0($v1)
.PF0f146560:
/*  f146560:	14610013 */ 	bne	$v1,$at,.PF0f1465b0
/*  f146564:	30d80030 */ 	andi	$t8,$a2,0x30
/*  f146568:	30d90030 */ 	andi	$t9,$a2,0x30
/*  f14656c:	13200002 */ 	beqz	$t9,.PF0f146578
/*  f146570:	2412007f */ 	li	$s2,0x7f
/*  f146574:	241200be */ 	li	$s2,0xbe
.PF0f146578:
/*  f146578:	30ef0030 */ 	andi	$t7,$a3,0x30
/*  f14657c:	11e00004 */ 	beqz	$t7,.PF0f146590
/*  f146580:	02801825 */ 	move	$v1,$s4
/*  f146584:	2652003f */ 	addiu	$s2,$s2,0x3f
/*  f146588:	324e00ff */ 	andi	$t6,$s2,0xff
/*  f14658c:	01c09025 */ 	move	$s2,$t6
.PF0f146590:
/*  f146590:	325800ff */ 	andi	$t8,$s2,0xff
/*  f146594:	0018ca00 */ 	sll	$t9,$t8,0x8
/*  f146598:	032b7825 */ 	or	$t7,$t9,$t3
/*  f14659c:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f1465a0:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f1465a4:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f1465a8:	10000013 */ 	b	.PF0f1465f8
/*  f1465ac:	ac690000 */ 	sw	$t1,0x0($v1)
.PF0f1465b0:
/*  f1465b0:	13000002 */ 	beqz	$t8,.PF0f1465bc
/*  f1465b4:	24120014 */ 	li	$s2,0x14
/*  f1465b8:	24120028 */ 	li	$s2,0x28
.PF0f1465bc:
/*  f1465bc:	30f90030 */ 	andi	$t9,$a3,0x30
/*  f1465c0:	13200004 */ 	beqz	$t9,.PF0f1465d4
/*  f1465c4:	02801825 */ 	move	$v1,$s4
/*  f1465c8:	26520014 */ 	addiu	$s2,$s2,0x14
/*  f1465cc:	324f00ff */ 	andi	$t7,$s2,0xff
/*  f1465d0:	01e09025 */ 	move	$s2,$t7
.PF0f1465d4:
/*  f1465d4:	0012c883 */ 	sra	$t9,$s2,0x2
/*  f1465d8:	332f00ff */ 	andi	$t7,$t9,0xff
/*  f1465dc:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f1465e0:	0012c600 */ 	sll	$t8,$s2,0x18
/*  f1465e4:	030ec825 */ 	or	$t9,$t8,$t6
/*  f1465e8:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f1465ec:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f1465f0:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f1465f4:	ac690000 */ 	sw	$t1,0x0($v1)
.PF0f1465f8:
/*  f1465f8:	315803ff */ 	andi	$t8,$t2,0x3ff
/*  f1465fc:	00187380 */ 	sll	$t6,$t8,0xe
/*  f146600:	3c01f600 */ 	lui	$at,0xf600
/*  f146604:	01c1c825 */ 	or	$t9,$t6,$at
/*  f146608:	311803ff */ 	andi	$t8,$t0,0x3ff
/*  f14660c:	00187380 */ 	sll	$t6,$t8,0xe
/*  f146610:	032c7825 */ 	or	$t7,$t9,$t4
/*  f146614:	02802025 */ 	move	$a0,$s4
/*  f146618:	01cdc825 */ 	or	$t9,$t6,$t5
/*  f14661c:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f146620:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f146624:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f146628:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f14662c:	2508000a */ 	addiu	$t0,$t0,0xa
/*  f146630:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f146634:	254a000a */ 	addiu	$t2,$t2,0xa
/*  f146638:	30f92000 */ 	andi	$t9,$a3,0x2000
/*  f14663c:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f146640:	30ce2000 */ 	andi	$t6,$a2,0x2000
/*  f146644:	24010001 */ 	li	$at,0x1
/*  f146648:	14600010 */ 	bnez	$v1,.PF0f14668c
/*  f14664c:	00000000 */ 	nop
/*  f146650:	11c00002 */ 	beqz	$t6,.PF0f14665c
/*  f146654:	24120014 */ 	li	$s2,0x14
/*  f146658:	24120028 */ 	li	$s2,0x28
.PF0f14665c:
/*  f14665c:	13200004 */ 	beqz	$t9,.PF0f146670
/*  f146660:	02801825 */ 	move	$v1,$s4
/*  f146664:	26520014 */ 	addiu	$s2,$s2,0x14
/*  f146668:	324f00ff */ 	andi	$t7,$s2,0xff
/*  f14666c:	01e09025 */ 	move	$s2,$t7
.PF0f146670:
/*  f146670:	325800ff */ 	andi	$t8,$s2,0xff
/*  f146674:	00187400 */ 	sll	$t6,$t8,0x10
/*  f146678:	35d900ff */ 	ori	$t9,$t6,0xff
/*  f14667c:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f146680:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146684:	10000027 */ 	b	.PF0f146724
/*  f146688:	ac690000 */ 	sw	$t1,0x0($v1)
.PF0f14668c:
/*  f14668c:	14610013 */ 	bne	$v1,$at,.PF0f1466dc
/*  f146690:	30d92000 */ 	andi	$t9,$a2,0x2000
/*  f146694:	30cf2000 */ 	andi	$t7,$a2,0x2000
/*  f146698:	11e00002 */ 	beqz	$t7,.PF0f1466a4
/*  f14669c:	2412007f */ 	li	$s2,0x7f
/*  f1466a0:	241200be */ 	li	$s2,0xbe
.PF0f1466a4:
/*  f1466a4:	30f82000 */ 	andi	$t8,$a3,0x2000
/*  f1466a8:	13000004 */ 	beqz	$t8,.PF0f1466bc
/*  f1466ac:	02801825 */ 	move	$v1,$s4
/*  f1466b0:	2652003f */ 	addiu	$s2,$s2,0x3f
/*  f1466b4:	324e00ff */ 	andi	$t6,$s2,0xff
/*  f1466b8:	01c09025 */ 	move	$s2,$t6
.PF0f1466bc:
/*  f1466bc:	325900ff */ 	andi	$t9,$s2,0xff
/*  f1466c0:	00197a00 */ 	sll	$t7,$t9,0x8
/*  f1466c4:	01ebc025 */ 	or	$t8,$t7,$t3
/*  f1466c8:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f1466cc:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f1466d0:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f1466d4:	10000013 */ 	b	.PF0f146724
/*  f1466d8:	ac690000 */ 	sw	$t1,0x0($v1)
.PF0f1466dc:
/*  f1466dc:	13200002 */ 	beqz	$t9,.PF0f1466e8
/*  f1466e0:	24120014 */ 	li	$s2,0x14
/*  f1466e4:	24120028 */ 	li	$s2,0x28
.PF0f1466e8:
/*  f1466e8:	30ef2000 */ 	andi	$t7,$a3,0x2000
/*  f1466ec:	11e00004 */ 	beqz	$t7,.PF0f146700
/*  f1466f0:	02801825 */ 	move	$v1,$s4
/*  f1466f4:	26520014 */ 	addiu	$s2,$s2,0x14
/*  f1466f8:	325800ff */ 	andi	$t8,$s2,0xff
/*  f1466fc:	03009025 */ 	move	$s2,$t8
.PF0f146700:
/*  f146700:	00127883 */ 	sra	$t7,$s2,0x2
/*  f146704:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f146708:	00187400 */ 	sll	$t6,$t8,0x10
/*  f14670c:	0012ce00 */ 	sll	$t9,$s2,0x18
/*  f146710:	032e7825 */ 	or	$t7,$t9,$t6
/*  f146714:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f146718:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f14671c:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146720:	ac690000 */ 	sw	$t1,0x0($v1)
.PF0f146724:
/*  f146724:	315903ff */ 	andi	$t9,$t2,0x3ff
/*  f146728:	00197380 */ 	sll	$t6,$t9,0xe
/*  f14672c:	3c01f600 */ 	lui	$at,0xf600
/*  f146730:	01c17825 */ 	or	$t7,$t6,$at
/*  f146734:	311903ff */ 	andi	$t9,$t0,0x3ff
/*  f146738:	02801825 */ 	move	$v1,$s4
/*  f14673c:	00197380 */ 	sll	$t6,$t9,0xe
/*  f146740:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f146744:	01cd7825 */ 	or	$t7,$t6,$t5
/*  f146748:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f14674c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f146750:	26940008 */ 	addiu	$s4,$s4,0x8
.PF0f146754:
/*  f146754:	3c0142a0 */ 	lui	$at,0x42a0
/*  f146758:	44817000 */ 	mtc1	$at,$f14
/*  f14675c:	3c0142c0 */ 	lui	$at,0x42c0
/*  f146760:	44818000 */ 	mtc1	$at,$f16
/*  f146764:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f146768:	3c0b1020 */ 	lui	$t3,0x1020
/*  f14676c:	46106282 */ 	mul.s	$f10,$f12,$f16
/*  f146770:	2405ffc9 */ 	li	$a1,-55
/*  f146774:	24010001 */ 	li	$at,0x1
/*  f146778:	00022600 */ 	sll	$a0,$v0,0x18
/*  f14677c:	460e5103 */ 	div.s	$f4,$f10,$f14
/*  f146780:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f146784:	44033000 */ 	mfc1	$v1,$f6
/*  f146788:	00000000 */ 	nop
/*  f14678c:	04610005 */ 	bgez	$v1,.PF0f1467a4
/*  f146790:	307200ff */ 	andi	$s2,$v1,0xff
/*  f146794:	00039023 */ 	negu	$s2,$v1
/*  f146798:	325900ff */ 	andi	$t9,$s2,0xff
/*  f14679c:	10000001 */ 	b	.PF0f1467a4
/*  f1467a0:	03209025 */ 	move	$s2,$t9
.PF0f1467a4:
/*  f1467a4:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f1467a8:	325800ff */ 	andi	$t8,$s2,0xff
/*  f1467ac:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f1467b0:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f1467b4:	372e00ff */ 	ori	$t6,$t9,0xff
/*  f1467b8:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f1467bc:	14600006 */ 	bnez	$v1,.PF0f1467d8
/*  f1467c0:	00000000 */ 	nop
/*  f1467c4:	02801825 */ 	move	$v1,$s4
/*  f1467c8:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1467cc:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f1467d0:	10000031 */ 	b	.PF0f146898
/*  f1467d4:	26940008 */ 	addiu	$s4,$s4,0x8
.PF0f1467d8:
/*  f1467d8:	14610026 */ 	bne	$v1,$at,.PF0f146874
/*  f1467dc:	0012ce00 */ 	sll	$t9,$s2,0x18
/*  f1467e0:	44924000 */ 	mtc1	$s2,$f8
/*  f1467e4:	02801825 */ 	move	$v1,$s4
/*  f1467e8:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1467ec:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f1467f0:	06410005 */ 	bgez	$s2,.PF0f146808
/*  f1467f4:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f1467f8:	3c014f80 */ 	lui	$at,0x4f80
/*  f1467fc:	44815000 */ 	mtc1	$at,$f10
/*  f146800:	00000000 */ 	nop
/*  f146804:	460a0000 */ 	add.s	$f0,$f0,$f10
.PF0f146808:
/*  f146808:	46100083 */ 	div.s	$f2,$f0,$f16
/*  f14680c:	3c014180 */ 	lui	$at,0x4180
/*  f146810:	44812000 */ 	mtc1	$at,$f4
/*  f146814:	3c014200 */ 	lui	$at,0x4200
/*  f146818:	44815000 */ 	mtc1	$at,$f10
/*  f14681c:	3c014020 */ 	lui	$at,0x4020
/*  f146820:	46041182 */ 	mul.s	$f6,$f2,$f4
/*  f146824:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f146828:	460a1102 */ 	mul.s	$f4,$f2,$f10
/*  f14682c:	44194000 */ 	mfc1	$t9,$f8
/*  f146830:	44814000 */ 	mtc1	$at,$f8
/*  f146834:	00197600 */ 	sll	$t6,$t9,0x18
/*  f146838:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f14683c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f146840:	44183000 */ 	mfc1	$t8,$f6
/*  f146844:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f146848:	331900ff */ 	andi	$t9,$t8,0xff
/*  f14684c:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f146850:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f146854:	440e2000 */ 	mfc1	$t6,$f4
/*  f146858:	00000000 */ 	nop
/*  f14685c:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f146860:	000fca00 */ 	sll	$t9,$t7,0x8
/*  f146864:	03197025 */ 	or	$t6,$t8,$t9
/*  f146868:	35cf00ff */ 	ori	$t7,$t6,0xff
/*  f14686c:	1000000a */ 	b	.PF0f146898
/*  f146870:	ac6f0004 */ 	sw	$t7,0x4($v1)
.PF0f146874:
/*  f146874:	00127083 */ 	sra	$t6,$s2,0x2
/*  f146878:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f14687c:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f146880:	02801825 */ 	move	$v1,$s4
/*  f146884:	03387025 */ 	or	$t6,$t9,$t8
/*  f146888:	35cf00ff */ 	ori	$t7,$t6,0xff
/*  f14688c:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f146890:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146894:	26940008 */ 	addiu	$s4,$s4,0x8
.PF0f146898:
/*  f146898:	8fb902ac */ 	lw	$t9,0x2ac($sp)
/*  f14689c:	57200044 */ 	bnezl	$t9,.PF0f1469b0
/*  f1468a0:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f1468a4:	1aa00022 */ 	blez	$s5,.PF0f146930
/*  f1468a8:	3c0141e0 */ 	lui	$at,0x41e0
/*  f1468ac:	3c0141e0 */ 	lui	$at,0x41e0
/*  f1468b0:	44819000 */ 	mtc1	$at,$f18
/*  f1468b4:	8fb90090 */ 	lw	$t9,0x90($sp)
/*  f1468b8:	3c01f600 */ 	lui	$at,0xf600
/*  f1468bc:	46126182 */ 	mul.s	$f6,$f12,$f18
/*  f1468c0:	02801825 */ 	move	$v1,$s4
/*  f1468c4:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f1468c8:	460e3203 */ 	div.s	$f8,$f6,$f14
/*  f1468cc:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f1468d0:	440e5000 */ 	mfc1	$t6,$f10
/*  f1468d4:	00000000 */ 	nop
/*  f1468d8:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f1468dc:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f1468e0:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f1468e4:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f1468e8:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1468ec:	01e1c825 */ 	or	$t9,$t7,$at
/*  f1468f0:	270e0015 */ 	addiu	$t6,$t8,0x15
/*  f1468f4:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1468f8:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1468fc:	03387025 */ 	or	$t6,$t9,$t8
/*  f146900:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f146904:	8faf0090 */ 	lw	$t7,0x90($sp)
/*  f146908:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f14690c:	8faf0304 */ 	lw	$t7,0x304($sp)
/*  f146910:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146914:	00187380 */ 	sll	$t6,$t8,0xe
/*  f146918:	25f90013 */ 	addiu	$t9,$t7,0x13
/*  f14691c:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146920:	00187880 */ 	sll	$t7,$t8,0x2
/*  f146924:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f146928:	10000020 */ 	b	.PF0f1469ac
/*  f14692c:	ac790004 */ 	sw	$t9,0x4($v1)
.PF0f146930:
/*  f146930:	44819000 */ 	mtc1	$at,$f18
/*  f146934:	8fb80090 */ 	lw	$t8,0x90($sp)
/*  f146938:	3c01f600 */ 	lui	$at,0xf600
/*  f14693c:	46126102 */ 	mul.s	$f4,$f12,$f18
/*  f146940:	00b87021 */ 	addu	$t6,$a1,$t8
/*  f146944:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f146948:	8fae0304 */ 	lw	$t6,0x304($sp)
/*  f14694c:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f146950:	0321c025 */ 	or	$t8,$t9,$at
/*  f146954:	25cf0015 */ 	addiu	$t7,$t6,0x15
/*  f146958:	460e2183 */ 	div.s	$f6,$f4,$f14
/*  f14695c:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f146960:	00197080 */ 	sll	$t6,$t9,0x2
/*  f146964:	030e7825 */ 	or	$t7,$t8,$t6
/*  f146968:	02801825 */ 	move	$v1,$s4
/*  f14696c:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f146970:	8faf0090 */ 	lw	$t7,0x90($sp)
/*  f146974:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146978:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f14697c:	44184000 */ 	mfc1	$t8,$f8
/*  f146980:	00000000 */ 	nop
/*  f146984:	03057021 */ 	addu	$t6,$t8,$a1
/*  f146988:	01cfc821 */ 	addu	$t9,$t6,$t7
/*  f14698c:	8faf0304 */ 	lw	$t7,0x304($sp)
/*  f146990:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146994:	00187380 */ 	sll	$t6,$t8,0xe
/*  f146998:	25f90013 */ 	addiu	$t9,$t7,0x13
/*  f14699c:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f1469a0:	00187880 */ 	sll	$t7,$t8,0x2
/*  f1469a4:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f1469a8:	ac790004 */ 	sw	$t9,0x4($v1)
.PF0f1469ac:
/*  f1469ac:	0004c603 */ 	sra	$t8,$a0,0x18
.PF0f1469b0:
/*  f1469b0:	03002025 */ 	move	$a0,$t8
/*  f1469b4:	44845000 */ 	mtc1	$a0,$f10
/*  f1469b8:	3c0141e0 */ 	lui	$at,0x41e0
/*  f1469bc:	44819000 */ 	mtc1	$at,$f18
/*  f1469c0:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f1469c4:	02801025 */ 	move	$v0,$s4
/*  f1469c8:	24010001 */ 	li	$at,0x1
/*  f1469cc:	46106102 */ 	mul.s	$f4,$f12,$f16
/*  f1469d0:	460e2183 */ 	div.s	$f6,$f4,$f14
/*  f1469d4:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f1469d8:	44034000 */ 	mfc1	$v1,$f8
/*  f1469dc:	00000000 */ 	nop
/*  f1469e0:	04610005 */ 	bgez	$v1,.PF0f1469f8
/*  f1469e4:	307200ff */ 	andi	$s2,$v1,0xff
/*  f1469e8:	00039023 */ 	negu	$s2,$v1
/*  f1469ec:	324f00ff */ 	andi	$t7,$s2,0xff
/*  f1469f0:	10000001 */ 	b	.PF0f1469f8
/*  f1469f4:	01e09025 */ 	move	$s2,$t7
.PF0f1469f8:
/*  f1469f8:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f1469fc:	324e00ff */ 	andi	$t6,$s2,0xff
/*  f146a00:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f146a04:	8f380480 */ 	lw	$t8,0x480($t9)
/*  f146a08:	35f900ff */ 	ori	$t9,$t7,0xff
/*  f146a0c:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f146a10:	14600005 */ 	bnez	$v1,.PF0f146a28
/*  f146a14:	00000000 */ 	nop
/*  f146a18:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146a1c:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f146a20:	10000031 */ 	b	.PF0f146ae8
/*  f146a24:	ac590004 */ 	sw	$t9,0x4($v0)
.PF0f146a28:
/*  f146a28:	14610026 */ 	bne	$v1,$at,.PF0f146ac4
/*  f146a2c:	02801025 */ 	move	$v0,$s4
/*  f146a30:	44925000 */ 	mtc1	$s2,$f10
/*  f146a34:	02801025 */ 	move	$v0,$s4
/*  f146a38:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f146a3c:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146a40:	06410005 */ 	bgez	$s2,.PF0f146a58
/*  f146a44:	46805020 */ 	cvt.s.w	$f0,$f10
/*  f146a48:	3c014f80 */ 	lui	$at,0x4f80
/*  f146a4c:	44812000 */ 	mtc1	$at,$f4
/*  f146a50:	00000000 */ 	nop
/*  f146a54:	46040000 */ 	add.s	$f0,$f0,$f4
.PF0f146a58:
/*  f146a58:	46100083 */ 	div.s	$f2,$f0,$f16
/*  f146a5c:	3c014180 */ 	lui	$at,0x4180
/*  f146a60:	44813000 */ 	mtc1	$at,$f6
/*  f146a64:	3c014200 */ 	lui	$at,0x4200
/*  f146a68:	44812000 */ 	mtc1	$at,$f4
/*  f146a6c:	3c014020 */ 	lui	$at,0x4020
/*  f146a70:	46061202 */ 	mul.s	$f8,$f2,$f6
/*  f146a74:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f146a78:	46041182 */ 	mul.s	$f6,$f2,$f4
/*  f146a7c:	440f5000 */ 	mfc1	$t7,$f10
/*  f146a80:	44815000 */ 	mtc1	$at,$f10
/*  f146a84:	000fce00 */ 	sll	$t9,$t7,0x18
/*  f146a88:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f146a8c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f146a90:	440e4000 */ 	mfc1	$t6,$f8
/*  f146a94:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f146a98:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f146a9c:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f146aa0:	03387025 */ 	or	$t6,$t9,$t8
/*  f146aa4:	44193000 */ 	mfc1	$t9,$f6
/*  f146aa8:	00000000 */ 	nop
/*  f146aac:	333800ff */ 	andi	$t8,$t9,0xff
/*  f146ab0:	00187a00 */ 	sll	$t7,$t8,0x8
/*  f146ab4:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f146ab8:	373800ff */ 	ori	$t8,$t9,0xff
/*  f146abc:	1000000a */ 	b	.PF0f146ae8
/*  f146ac0:	ac580004 */ 	sw	$t8,0x4($v0)
.PF0f146ac4:
/*  f146ac4:	0012c883 */ 	sra	$t9,$s2,0x2
/*  f146ac8:	333800ff */ 	andi	$t8,$t9,0xff
/*  f146acc:	00187400 */ 	sll	$t6,$t8,0x10
/*  f146ad0:	00127e00 */ 	sll	$t7,$s2,0x18
/*  f146ad4:	01eec825 */ 	or	$t9,$t7,$t6
/*  f146ad8:	373800ff */ 	ori	$t8,$t9,0xff
/*  f146adc:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f146ae0:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146ae4:	ac490000 */ 	sw	$t1,0x0($v0)
.PF0f146ae8:
/*  f146ae8:	8faf02ac */ 	lw	$t7,0x2ac($sp)
/*  f146aec:	8fa60090 */ 	lw	$a2,0x90($sp)
/*  f146af0:	15e00037 */ 	bnez	$t7,.PF0f146bd0
/*  f146af4:	00a61821 */ 	addu	$v1,$a1,$a2
/*  f146af8:	306e03ff */ 	andi	$t6,$v1,0x3ff
/*  f146afc:	1880001b */ 	blez	$a0,.PF0f146b6c
/*  f146b00:	000e1b80 */ 	sll	$v1,$t6,0xe
/*  f146b04:	46126202 */ 	mul.s	$f8,$f12,$f18
/*  f146b08:	3c01f600 */ 	lui	$at,0xf600
/*  f146b0c:	02801025 */ 	move	$v0,$s4
/*  f146b10:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146b14:	460e4283 */ 	div.s	$f10,$f8,$f14
/*  f146b18:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f146b1c:	440f2000 */ 	mfc1	$t7,$f4
/*  f146b20:	00000000 */ 	nop
/*  f146b24:	01e57021 */ 	addu	$t6,$t7,$a1
/*  f146b28:	01c6c821 */ 	addu	$t9,$t6,$a2
/*  f146b2c:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146b30:	8fb90304 */ 	lw	$t9,0x304($sp)
/*  f146b34:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f146b38:	01e17025 */ 	or	$t6,$t7,$at
/*  f146b3c:	27380018 */ 	addiu	$t8,$t9,0x18
/*  f146b40:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f146b44:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f146b48:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f146b4c:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f146b50:	8faf0304 */ 	lw	$t7,0x304($sp)
/*  f146b54:	25ee0016 */ 	addiu	$t6,$t7,0x16
/*  f146b58:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146b5c:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f146b60:	00787825 */ 	or	$t7,$v1,$t8
/*  f146b64:	1000001a */ 	b	.PF0f146bd0
/*  f146b68:	ac4f0004 */ 	sw	$t7,0x4($v0)
.PF0f146b6c:
/*  f146b6c:	46126182 */ 	mul.s	$f6,$f12,$f18
/*  f146b70:	8fb90304 */ 	lw	$t9,0x304($sp)
/*  f146b74:	3c01f600 */ 	lui	$at,0xf600
/*  f146b78:	00617025 */ 	or	$t6,$v1,$at
/*  f146b7c:	27380018 */ 	addiu	$t8,$t9,0x18
/*  f146b80:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f146b84:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f146b88:	460e3203 */ 	div.s	$f8,$f6,$f14
/*  f146b8c:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f146b90:	02801025 */ 	move	$v0,$s4
/*  f146b94:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f146b98:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146b9c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f146ba0:	440e5000 */ 	mfc1	$t6,$f10
/*  f146ba4:	00000000 */ 	nop
/*  f146ba8:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f146bac:	0326c021 */ 	addu	$t8,$t9,$a2
/*  f146bb0:	8fb90304 */ 	lw	$t9,0x304($sp)
/*  f146bb4:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f146bb8:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f146bbc:	27380016 */ 	addiu	$t8,$t9,0x16
/*  f146bc0:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f146bc4:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f146bc8:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f146bcc:	ac580004 */ 	sw	$t8,0x4($v0)
.PF0f146bd0:
/*  f146bd0:	8ec40284 */ 	lw	$a0,0x284($s6)
/*  f146bd4:	8fa60090 */ 	lw	$a2,0x90($sp)
/*  f146bd8:	8fae02ac */ 	lw	$t6,0x2ac($sp)
/*  f146bdc:	8c8f0480 */ 	lw	$t7,0x480($a0)
/*  f146be0:	24010002 */ 	li	$at,0x2
/*  f146be4:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f146be8:	1460015d */ 	bnez	$v1,.PF0f147160
/*  f146bec:	00000000 */ 	nop
/*  f146bf0:	15c00314 */ 	bnez	$t6,.PF0f147844
/*  f146bf4:	8fb90308 */ 	lw	$t9,0x308($sp)
/*  f146bf8:	44992000 */ 	mtc1	$t9,$f4
/*  f146bfc:	3c01420c */ 	lui	$at,0x420c
/*  f146c00:	44816000 */ 	mtc1	$at,$f12
/*  f146c04:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f146c08:	3c0143b4 */ 	lui	$at,0x43b4
/*  f146c0c:	44817000 */ 	mtc1	$at,$f14
/*  f146c10:	3c0140a0 */ 	lui	$at,0x40a0
/*  f146c14:	44814000 */ 	mtc1	$at,$f8
/*  f146c18:	44862000 */ 	mtc1	$a2,$f4
/*  f146c1c:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f146c20:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f146c24:	3c05f600 */ 	lui	$a1,0xf600
/*  f146c28:	25d9fff3 */ 	addiu	$t9,$t6,-13
/*  f146c2c:	afb902f0 */ 	sw	$t9,0x2f0($sp)
/*  f146c30:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f146c34:	02801825 */ 	move	$v1,$s4
/*  f146c38:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*  f146c3c:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f146c40:	440f2000 */ 	mfc1	$t7,$f4
/*  f146c44:	00000000 */ 	nop
/*  f146c48:	afaf02f4 */ 	sw	$t7,0x2f4($sp)
/*  f146c4c:	8c980480 */ 	lw	$t8,0x480($a0)
/*  f146c50:	c700001c */ 	lwc1	$f0,0x1c($t8)
/*  f146c54:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f146c58:	00000000 */ 	nop
/*  f146c5c:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f146c60:	460e3283 */ 	div.s	$f10,$f6,$f14
/*  f146c64:	460e2183 */ 	div.s	$f6,$f4,$f14
/*  f146c68:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f146c6c:	44024000 */ 	mfc1	$v0,$f8
/*  f146c70:	00000000 */ 	nop
/*  f146c74:	305200ff */ 	andi	$s2,$v0,0xff
/*  f146c78:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f146c7c:	44195000 */ 	mfc1	$t9,$f10
/*  f146c80:	04410005 */ 	bgez	$v0,.PF0f146c98
/*  f146c84:	afb902e8 */ 	sw	$t9,0x2e8($sp)
/*  f146c88:	00029023 */ 	negu	$s2,$v0
/*  f146c8c:	325800ff */ 	andi	$t8,$s2,0xff
/*  f146c90:	10000001 */ 	b	.PF0f146c98
/*  f146c94:	03009025 */ 	move	$s2,$t8
.PF0f146c98:
/*  f146c98:	324f00ff */ 	andi	$t7,$s2,0xff
/*  f146c9c:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f146ca0:	35d900ff */ 	ori	$t9,$t6,0xff
/*  f146ca4:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f146ca8:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146cac:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f146cb0:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146cb4:	02802025 */ 	move	$a0,$s4
/*  f146cb8:	270f0005 */ 	addiu	$t7,$t8,0x5
/*  f146cbc:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f146cc0:	8faf02f0 */ 	lw	$t7,0x2f0($sp)
/*  f146cc4:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f146cc8:	0325c025 */ 	or	$t8,$t9,$a1
/*  f146ccc:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f146cd0:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f146cd4:	03197825 */ 	or	$t7,$t8,$t9
/*  f146cd8:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f146cdc:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f146ce0:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f146ce4:	3c013f00 */ 	lui	$at,0x3f00
/*  f146ce8:	44811000 */ 	mtc1	$at,$f2
/*  f146cec:	01d8c823 */ 	subu	$t9,$t6,$t8
/*  f146cf0:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f146cf4:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f146cf8:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f146cfc:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f146d00:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f146d04:	01eec025 */ 	or	$t8,$t7,$t6
/*  f146d08:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f146d0c:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f146d10:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f146d14:	3c013f80 */ 	lui	$at,0x3f80
/*  f146d18:	272f0007 */ 	addiu	$t7,$t9,0x7
/*  f146d1c:	afaf02f4 */ 	sw	$t7,0x2f4($sp)
/*  f146d20:	8dd80480 */ 	lw	$t8,0x480($t6)
/*  f146d24:	44819000 */ 	mtc1	$at,$f18
/*  f146d28:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146d2c:	c7080020 */ 	lwc1	$f8,0x20($t8)
/*  f146d30:	02801825 */ 	move	$v1,$s4
/*  f146d34:	3c01f600 */ 	lui	$at,0xf600
/*  f146d38:	46124000 */ 	add.s	$f0,$f8,$f18
/*  f146d3c:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f146d40:	00000000 */ 	nop
/*  f146d44:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f146d48:	00000000 */ 	nop
/*  f146d4c:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f146d50:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f146d54:	46024102 */ 	mul.s	$f4,$f8,$f2
/*  f146d58:	44025000 */ 	mfc1	$v0,$f10
/*  f146d5c:	00000000 */ 	nop
/*  f146d60:	305200ff */ 	andi	$s2,$v0,0xff
/*  f146d64:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f146d68:	440e3000 */ 	mfc1	$t6,$f6
/*  f146d6c:	04410005 */ 	bgez	$v0,.PF0f146d84
/*  f146d70:	afae02e8 */ 	sw	$t6,0x2e8($sp)
/*  f146d74:	00029023 */ 	negu	$s2,$v0
/*  f146d78:	325800ff */ 	andi	$t8,$s2,0xff
/*  f146d7c:	10000001 */ 	b	.PF0f146d84
/*  f146d80:	03009025 */ 	move	$s2,$t8
.PF0f146d84:
/*  f146d84:	325900ff */ 	andi	$t9,$s2,0xff
/*  f146d88:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f146d8c:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f146d90:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f146d94:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146d98:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f146d9c:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146da0:	02802025 */ 	move	$a0,$s4
/*  f146da4:	27190005 */ 	addiu	$t9,$t8,0x5
/*  f146da8:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f146dac:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f146db0:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f146db4:	01c5c025 */ 	or	$t8,$t6,$a1
/*  f146db8:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f146dbc:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f146dc0:	030ec825 */ 	or	$t9,$t8,$t6
/*  f146dc4:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f146dc8:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f146dcc:	8faf02f0 */ 	lw	$t7,0x2f0($sp)
/*  f146dd0:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146dd4:	02801825 */ 	move	$v1,$s4
/*  f146dd8:	01f87023 */ 	subu	$t6,$t7,$t8
/*  f146ddc:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f146de0:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146de4:	00197880 */ 	sll	$t7,$t9,0x2
/*  f146de8:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f146dec:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f146df0:	032fc025 */ 	or	$t8,$t9,$t7
/*  f146df4:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f146df8:	8fae02f4 */ 	lw	$t6,0x2f4($sp)
/*  f146dfc:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f146e00:	25d90007 */ 	addiu	$t9,$t6,0x7
/*  f146e04:	afb902f4 */ 	sw	$t9,0x2f4($sp)
/*  f146e08:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f146e0c:	c70a0024 */ 	lwc1	$f10,0x24($t8)
/*  f146e10:	46125000 */ 	add.s	$f0,$f10,$f18
/*  f146e14:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f146e18:	00000000 */ 	nop
/*  f146e1c:	46024102 */ 	mul.s	$f4,$f8,$f2
/*  f146e20:	00000000 */ 	nop
/*  f146e24:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f146e28:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f146e2c:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f146e30:	44023000 */ 	mfc1	$v0,$f6
/*  f146e34:	00000000 */ 	nop
/*  f146e38:	305200ff */ 	andi	$s2,$v0,0xff
/*  f146e3c:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f146e40:	440f2000 */ 	mfc1	$t7,$f4
/*  f146e44:	04410005 */ 	bgez	$v0,.PF0f146e5c
/*  f146e48:	afaf02e8 */ 	sw	$t7,0x2e8($sp)
/*  f146e4c:	00029023 */ 	negu	$s2,$v0
/*  f146e50:	325800ff */ 	andi	$t8,$s2,0xff
/*  f146e54:	10000001 */ 	b	.PF0f146e5c
/*  f146e58:	03009025 */ 	move	$s2,$t8
.PF0f146e5c:
/*  f146e5c:	324e00ff */ 	andi	$t6,$s2,0xff
/*  f146e60:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f146e64:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f146e68:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f146e6c:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146e70:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f146e74:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146e78:	02802025 */ 	move	$a0,$s4
/*  f146e7c:	270e0005 */ 	addiu	$t6,$t8,0x5
/*  f146e80:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146e84:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f146e88:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f146e8c:	01e5c025 */ 	or	$t8,$t7,$a1
/*  f146e90:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146e94:	00197880 */ 	sll	$t7,$t9,0x2
/*  f146e98:	030f7025 */ 	or	$t6,$t8,$t7
/*  f146e9c:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f146ea0:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f146ea4:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f146ea8:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146eac:	02801825 */ 	move	$v1,$s4
/*  f146eb0:	03387823 */ 	subu	$t7,$t9,$t8
/*  f146eb4:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f146eb8:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f146ebc:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f146ec0:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f146ec4:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f146ec8:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f146ecc:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f146ed0:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f146ed4:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f146ed8:	25ee0007 */ 	addiu	$t6,$t7,0x7
/*  f146edc:	afae02f4 */ 	sw	$t6,0x2f4($sp)
/*  f146ee0:	8f380480 */ 	lw	$t8,0x480($t9)
/*  f146ee4:	c7000028 */ 	lwc1	$f0,0x28($t8)
/*  f146ee8:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f146eec:	00000000 */ 	nop
/*  f146ef0:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f146ef4:	460e3283 */ 	div.s	$f10,$f6,$f14
/*  f146ef8:	460e2183 */ 	div.s	$f6,$f4,$f14
/*  f146efc:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f146f00:	44024000 */ 	mfc1	$v0,$f8
/*  f146f04:	00000000 */ 	nop
/*  f146f08:	305200ff */ 	andi	$s2,$v0,0xff
/*  f146f0c:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f146f10:	44195000 */ 	mfc1	$t9,$f10
/*  f146f14:	04410005 */ 	bgez	$v0,.PF0f146f2c
/*  f146f18:	afb902e8 */ 	sw	$t9,0x2e8($sp)
/*  f146f1c:	00029023 */ 	negu	$s2,$v0
/*  f146f20:	325800ff */ 	andi	$t8,$s2,0xff
/*  f146f24:	10000001 */ 	b	.PF0f146f2c
/*  f146f28:	03009025 */ 	move	$s2,$t8
.PF0f146f2c:
/*  f146f2c:	324f00ff */ 	andi	$t7,$s2,0xff
/*  f146f30:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f146f34:	35d900ff */ 	ori	$t9,$t6,0xff
/*  f146f38:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f146f3c:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146f40:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f146f44:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146f48:	02802025 */ 	move	$a0,$s4
/*  f146f4c:	270f0005 */ 	addiu	$t7,$t8,0x5
/*  f146f50:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f146f54:	8faf02f0 */ 	lw	$t7,0x2f0($sp)
/*  f146f58:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f146f5c:	0325c025 */ 	or	$t8,$t9,$a1
/*  f146f60:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f146f64:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f146f68:	03197825 */ 	or	$t7,$t8,$t9
/*  f146f6c:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f146f70:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f146f74:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f146f78:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f146f7c:	02801825 */ 	move	$v1,$s4
/*  f146f80:	01d8c823 */ 	subu	$t9,$t6,$t8
/*  f146f84:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f146f88:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f146f8c:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f146f90:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f146f94:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f146f98:	01eec025 */ 	or	$t8,$t7,$t6
/*  f146f9c:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f146fa0:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f146fa4:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f146fa8:	272f0007 */ 	addiu	$t7,$t9,0x7
/*  f146fac:	afaf02f4 */ 	sw	$t7,0x2f4($sp)
/*  f146fb0:	8dd80480 */ 	lw	$t8,0x480($t6)
/*  f146fb4:	c708002c */ 	lwc1	$f8,0x2c($t8)
/*  f146fb8:	46124000 */ 	add.s	$f0,$f8,$f18
/*  f146fbc:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f146fc0:	00000000 */ 	nop
/*  f146fc4:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f146fc8:	00000000 */ 	nop
/*  f146fcc:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f146fd0:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f146fd4:	46024102 */ 	mul.s	$f4,$f8,$f2
/*  f146fd8:	44025000 */ 	mfc1	$v0,$f10
/*  f146fdc:	00000000 */ 	nop
/*  f146fe0:	305200ff */ 	andi	$s2,$v0,0xff
/*  f146fe4:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f146fe8:	440e3000 */ 	mfc1	$t6,$f6
/*  f146fec:	04410005 */ 	bgez	$v0,.PF0f147004
/*  f146ff0:	afae02e8 */ 	sw	$t6,0x2e8($sp)
/*  f146ff4:	00029023 */ 	negu	$s2,$v0
/*  f146ff8:	325800ff */ 	andi	$t8,$s2,0xff
/*  f146ffc:	10000001 */ 	b	.PF0f147004
/*  f147000:	03009025 */ 	move	$s2,$t8
.PF0f147004:
/*  f147004:	325900ff */ 	andi	$t9,$s2,0xff
/*  f147008:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f14700c:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f147010:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f147014:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f147018:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f14701c:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f147020:	02802025 */ 	move	$a0,$s4
/*  f147024:	27190005 */ 	addiu	$t9,$t8,0x5
/*  f147028:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f14702c:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f147030:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f147034:	01c1c025 */ 	or	$t8,$t6,$at
/*  f147038:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f14703c:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f147040:	030ec825 */ 	or	$t9,$t8,$t6
/*  f147044:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f147048:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f14704c:	8faf02f0 */ 	lw	$t7,0x2f0($sp)
/*  f147050:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f147054:	3c01f600 */ 	lui	$at,0xf600
/*  f147058:	01f87023 */ 	subu	$t6,$t7,$t8
/*  f14705c:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f147060:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f147064:	00197880 */ 	sll	$t7,$t9,0x2
/*  f147068:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f14706c:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f147070:	032fc025 */ 	or	$t8,$t9,$t7
/*  f147074:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f147078:	8fae02f4 */ 	lw	$t6,0x2f4($sp)
/*  f14707c:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f147080:	25d90007 */ 	addiu	$t9,$t6,0x7
/*  f147084:	afb902f4 */ 	sw	$t9,0x2f4($sp)
/*  f147088:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f14708c:	c70a0030 */ 	lwc1	$f10,0x30($t8)
/*  f147090:	46125000 */ 	add.s	$f0,$f10,$f18
/*  f147094:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f147098:	00000000 */ 	nop
/*  f14709c:	46024102 */ 	mul.s	$f4,$f8,$f2
/*  f1470a0:	00000000 */ 	nop
/*  f1470a4:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f1470a8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f1470ac:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f1470b0:	44023000 */ 	mfc1	$v0,$f6
/*  f1470b4:	00000000 */ 	nop
/*  f1470b8:	305200ff */ 	andi	$s2,$v0,0xff
/*  f1470bc:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f1470c0:	440f2000 */ 	mfc1	$t7,$f4
/*  f1470c4:	04410005 */ 	bgez	$v0,.PF0f1470dc
/*  f1470c8:	afaf02e8 */ 	sw	$t7,0x2e8($sp)
/*  f1470cc:	00029023 */ 	negu	$s2,$v0
/*  f1470d0:	325800ff */ 	andi	$t8,$s2,0xff
/*  f1470d4:	10000001 */ 	b	.PF0f1470dc
/*  f1470d8:	03009025 */ 	move	$s2,$t8
.PF0f1470dc:
/*  f1470dc:	324e00ff */ 	andi	$t6,$s2,0xff
/*  f1470e0:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f1470e4:	02801025 */ 	move	$v0,$s4
/*  f1470e8:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f1470ec:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f1470f0:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f1470f4:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f1470f8:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f1470fc:	02801825 */ 	move	$v1,$s4
/*  f147100:	270e0005 */ 	addiu	$t6,$t8,0x5
/*  f147104:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f147108:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f14710c:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f147110:	01e1c025 */ 	or	$t8,$t7,$at
/*  f147114:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f147118:	00197880 */ 	sll	$t7,$t9,0x2
/*  f14711c:	030f7025 */ 	or	$t6,$t8,$t7
/*  f147120:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f147124:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f147128:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f14712c:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f147130:	03387823 */ 	subu	$t7,$t9,$t8
/*  f147134:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f147138:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f14713c:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f147140:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f147144:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f147148:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f14714c:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f147150:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f147154:	25ee0007 */ 	addiu	$t6,$t7,0x7
/*  f147158:	100001ba */ 	b	.PF0f147844
/*  f14715c:	afae02f4 */ 	sw	$t6,0x2f4($sp)
.PF0f147160:
/*  f147160:	14610174 */ 	bne	$v1,$at,.PF0f147734
/*  f147164:	8fb80308 */ 	lw	$t8,0x308($sp)
/*  f147168:	8fb902ac */ 	lw	$t9,0x2ac($sp)
/*  f14716c:	8fb80308 */ 	lw	$t8,0x308($sp)
/*  f147170:	02801825 */ 	move	$v1,$s4
/*  f147174:	572001b4 */ 	bnezl	$t9,.PF0f147848
/*  f147178:	02801025 */ 	move	$v0,$s4
/*  f14717c:	44983000 */ 	mtc1	$t8,$f6
/*  f147180:	3c01420c */ 	lui	$at,0x420c
/*  f147184:	44816000 */ 	mtc1	$at,$f12
/*  f147188:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f14718c:	3c0143b4 */ 	lui	$at,0x43b4
/*  f147190:	44817000 */ 	mtc1	$at,$f14
/*  f147194:	3c0140a0 */ 	lui	$at,0x40a0
/*  f147198:	44814000 */ 	mtc1	$at,$f8
/*  f14719c:	44863000 */ 	mtc1	$a2,$f6
/*  f1471a0:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f1471a4:	46085103 */ 	div.s	$f4,$f10,$f8
/*  f1471a8:	3c013f00 */ 	lui	$at,0x3f00
/*  f1471ac:	2738fff3 */ 	addiu	$t8,$t9,-13
/*  f1471b0:	afb802f0 */ 	sw	$t8,0x2f0($sp)
/*  f1471b4:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f1471b8:	44811000 */ 	mtc1	$at,$f2
/*  f1471bc:	3c013f80 */ 	lui	$at,0x3f80
/*  f1471c0:	44819000 */ 	mtc1	$at,$f18
/*  f1471c4:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f1471c8:	46045201 */ 	sub.s	$f8,$f10,$f4
/*  f1471cc:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f1471d0:	440e3000 */ 	mfc1	$t6,$f6
/*  f1471d4:	00000000 */ 	nop
/*  f1471d8:	afae02f4 */ 	sw	$t6,0x2f4($sp)
/*  f1471dc:	8c8f0480 */ 	lw	$t7,0x480($a0)
/*  f1471e0:	c5e0001c */ 	lwc1	$f0,0x1c($t7)
/*  f1471e4:	46100282 */ 	mul.s	$f10,$f0,$f16
/*  f1471e8:	00000000 */ 	nop
/*  f1471ec:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f1471f0:	460e5103 */ 	div.s	$f4,$f10,$f14
/*  f1471f4:	460e3283 */ 	div.s	$f10,$f6,$f14
/*  f1471f8:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f1471fc:	44024000 */ 	mfc1	$v0,$f8
/*  f147200:	00000000 */ 	nop
/*  f147204:	305200ff */ 	andi	$s2,$v0,0xff
/*  f147208:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f14720c:	44182000 */ 	mfc1	$t8,$f4
/*  f147210:	04410005 */ 	bgez	$v0,.PF0f147228
/*  f147214:	afb802e8 */ 	sw	$t8,0x2e8($sp)
/*  f147218:	00029023 */ 	negu	$s2,$v0
/*  f14721c:	324f00ff */ 	andi	$t7,$s2,0xff
/*  f147220:	10000001 */ 	b	.PF0f147228
/*  f147224:	01e09025 */ 	move	$s2,$t7
.PF0f147228:
/*  f147228:	0012c083 */ 	sra	$t8,$s2,0x2
/*  f14722c:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f147230:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f147234:	0012ce00 */ 	sll	$t9,$s2,0x18
/*  f147238:	032ec025 */ 	or	$t8,$t9,$t6
/*  f14723c:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f147240:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f147244:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f147248:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f14724c:	3c01f600 */ 	lui	$at,0xf600
/*  f147250:	02802025 */ 	move	$a0,$s4
/*  f147254:	272e0005 */ 	addiu	$t6,$t9,0x5
/*  f147258:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f14725c:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f147260:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f147264:	01e1c825 */ 	or	$t9,$t7,$at
/*  f147268:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f14726c:	00187880 */ 	sll	$t7,$t8,0x2
/*  f147270:	032f7025 */ 	or	$t6,$t9,$t7
/*  f147274:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f147278:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f14727c:	8fb802f0 */ 	lw	$t8,0x2f0($sp)
/*  f147280:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f147284:	02801825 */ 	move	$v1,$s4
/*  f147288:	03197823 */ 	subu	$t7,$t8,$t9
/*  f14728c:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f147290:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f147294:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f147298:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f14729c:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f1472a0:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f1472a4:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f1472a8:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f1472ac:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f1472b0:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f1472b4:	25ee0007 */ 	addiu	$t6,$t7,0x7
/*  f1472b8:	afae02f4 */ 	sw	$t6,0x2f4($sp)
/*  f1472bc:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f1472c0:	c7280020 */ 	lwc1	$f8,0x20($t9)
/*  f1472c4:	46124000 */ 	add.s	$f0,$f8,$f18
/*  f1472c8:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f1472cc:	00000000 */ 	nop
/*  f1472d0:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f1472d4:	00000000 */ 	nop
/*  f1472d8:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f1472dc:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f1472e0:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f1472e4:	44022000 */ 	mfc1	$v0,$f4
/*  f1472e8:	00000000 */ 	nop
/*  f1472ec:	305200ff */ 	andi	$s2,$v0,0xff
/*  f1472f0:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f1472f4:	44185000 */ 	mfc1	$t8,$f10
/*  f1472f8:	04410005 */ 	bgez	$v0,.PF0f147310
/*  f1472fc:	afb802e8 */ 	sw	$t8,0x2e8($sp)
/*  f147300:	00029023 */ 	negu	$s2,$v0
/*  f147304:	325900ff */ 	andi	$t9,$s2,0xff
/*  f147308:	10000001 */ 	b	.PF0f147310
/*  f14730c:	03209025 */ 	move	$s2,$t9
.PF0f147310:
/*  f147310:	0012c083 */ 	sra	$t8,$s2,0x2
/*  f147314:	331900ff */ 	andi	$t9,$t8,0xff
/*  f147318:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f14731c:	00127600 */ 	sll	$t6,$s2,0x18
/*  f147320:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f147324:	371900ff */ 	ori	$t9,$t8,0xff
/*  f147328:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f14732c:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f147330:	8fae02f4 */ 	lw	$t6,0x2f4($sp)
/*  f147334:	3c01f600 */ 	lui	$at,0xf600
/*  f147338:	02802025 */ 	move	$a0,$s4
/*  f14733c:	25cf0005 */ 	addiu	$t7,$t6,0x5
/*  f147340:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f147344:	8faf02f0 */ 	lw	$t7,0x2f0($sp)
/*  f147348:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f14734c:	03217025 */ 	or	$t6,$t9,$at
/*  f147350:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f147354:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f147358:	01d97825 */ 	or	$t7,$t6,$t9
/*  f14735c:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f147360:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f147364:	8fb802f0 */ 	lw	$t8,0x2f0($sp)
/*  f147368:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f14736c:	02801825 */ 	move	$v1,$s4
/*  f147370:	030ec823 */ 	subu	$t9,$t8,$t6
/*  f147374:	8fae02f4 */ 	lw	$t6,0x2f4($sp)
/*  f147378:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f14737c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f147380:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f147384:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f147388:	01f87025 */ 	or	$t6,$t7,$t8
/*  f14738c:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f147390:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f147394:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f147398:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f14739c:	272f0007 */ 	addiu	$t7,$t9,0x7
/*  f1473a0:	afaf02f4 */ 	sw	$t7,0x2f4($sp)
/*  f1473a4:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f1473a8:	c5c40024 */ 	lwc1	$f4,0x24($t6)
/*  f1473ac:	46122000 */ 	add.s	$f0,$f4,$f18
/*  f1473b0:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f1473b4:	00000000 */ 	nop
/*  f1473b8:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f1473bc:	00000000 */ 	nop
/*  f1473c0:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f1473c4:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f1473c8:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f1473cc:	44025000 */ 	mfc1	$v0,$f10
/*  f1473d0:	00000000 */ 	nop
/*  f1473d4:	305200ff */ 	andi	$s2,$v0,0xff
/*  f1473d8:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f1473dc:	44183000 */ 	mfc1	$t8,$f6
/*  f1473e0:	04410005 */ 	bgez	$v0,.PF0f1473f8
/*  f1473e4:	afb802e8 */ 	sw	$t8,0x2e8($sp)
/*  f1473e8:	00029023 */ 	negu	$s2,$v0
/*  f1473ec:	324e00ff */ 	andi	$t6,$s2,0xff
/*  f1473f0:	10000001 */ 	b	.PF0f1473f8
/*  f1473f4:	01c09025 */ 	move	$s2,$t6
.PF0f1473f8:
/*  f1473f8:	0012c083 */ 	sra	$t8,$s2,0x2
/*  f1473fc:	330e00ff */ 	andi	$t6,$t8,0xff
/*  f147400:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f147404:	00127e00 */ 	sll	$t7,$s2,0x18
/*  f147408:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f14740c:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f147410:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f147414:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f147418:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f14741c:	3c01f600 */ 	lui	$at,0xf600
/*  f147420:	02802025 */ 	move	$a0,$s4
/*  f147424:	25f90005 */ 	addiu	$t9,$t7,0x5
/*  f147428:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f14742c:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f147430:	00187380 */ 	sll	$t6,$t8,0xe
/*  f147434:	01c17825 */ 	or	$t7,$t6,$at
/*  f147438:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f14743c:	00187080 */ 	sll	$t6,$t8,0x2
/*  f147440:	01eec825 */ 	or	$t9,$t7,$t6
/*  f147444:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f147448:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f14744c:	8fb802f0 */ 	lw	$t8,0x2f0($sp)
/*  f147450:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f147454:	02801825 */ 	move	$v1,$s4
/*  f147458:	030f7023 */ 	subu	$t6,$t8,$t7
/*  f14745c:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f147460:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f147464:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f147468:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f14746c:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f147470:	03387825 */ 	or	$t7,$t9,$t8
/*  f147474:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f147478:	8fae02f4 */ 	lw	$t6,0x2f4($sp)
/*  f14747c:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f147480:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f147484:	25d90007 */ 	addiu	$t9,$t6,0x7
/*  f147488:	afb902f4 */ 	sw	$t9,0x2f4($sp)
/*  f14748c:	8f0f0480 */ 	lw	$t7,0x480($t8)
/*  f147490:	c5e00028 */ 	lwc1	$f0,0x28($t7)
/*  f147494:	46100282 */ 	mul.s	$f10,$f0,$f16
/*  f147498:	00000000 */ 	nop
/*  f14749c:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f1474a0:	460e5103 */ 	div.s	$f4,$f10,$f14
/*  f1474a4:	460e3283 */ 	div.s	$f10,$f6,$f14
/*  f1474a8:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f1474ac:	44024000 */ 	mfc1	$v0,$f8
/*  f1474b0:	00000000 */ 	nop
/*  f1474b4:	305200ff */ 	andi	$s2,$v0,0xff
/*  f1474b8:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f1474bc:	44182000 */ 	mfc1	$t8,$f4
/*  f1474c0:	04410005 */ 	bgez	$v0,.PF0f1474d8
/*  f1474c4:	afb802e8 */ 	sw	$t8,0x2e8($sp)
/*  f1474c8:	00029023 */ 	negu	$s2,$v0
/*  f1474cc:	324f00ff */ 	andi	$t7,$s2,0xff
/*  f1474d0:	10000001 */ 	b	.PF0f1474d8
/*  f1474d4:	01e09025 */ 	move	$s2,$t7
.PF0f1474d8:
/*  f1474d8:	0012c083 */ 	sra	$t8,$s2,0x2
/*  f1474dc:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f1474e0:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f1474e4:	0012ce00 */ 	sll	$t9,$s2,0x18
/*  f1474e8:	032ec025 */ 	or	$t8,$t9,$t6
/*  f1474ec:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f1474f0:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f1474f4:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1474f8:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f1474fc:	3c01f600 */ 	lui	$at,0xf600
/*  f147500:	02802025 */ 	move	$a0,$s4
/*  f147504:	272e0005 */ 	addiu	$t6,$t9,0x5
/*  f147508:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f14750c:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f147510:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f147514:	01e1c825 */ 	or	$t9,$t7,$at
/*  f147518:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f14751c:	00187880 */ 	sll	$t7,$t8,0x2
/*  f147520:	032f7025 */ 	or	$t6,$t9,$t7
/*  f147524:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f147528:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f14752c:	8fb802f0 */ 	lw	$t8,0x2f0($sp)
/*  f147530:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f147534:	02801825 */ 	move	$v1,$s4
/*  f147538:	03197823 */ 	subu	$t7,$t8,$t9
/*  f14753c:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f147540:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f147544:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f147548:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f14754c:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f147550:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f147554:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f147558:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f14755c:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f147560:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f147564:	25ee0007 */ 	addiu	$t6,$t7,0x7
/*  f147568:	afae02f4 */ 	sw	$t6,0x2f4($sp)
/*  f14756c:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f147570:	c728002c */ 	lwc1	$f8,0x2c($t9)
/*  f147574:	46124000 */ 	add.s	$f0,$f8,$f18
/*  f147578:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f14757c:	00000000 */ 	nop
/*  f147580:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f147584:	00000000 */ 	nop
/*  f147588:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f14758c:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f147590:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f147594:	44022000 */ 	mfc1	$v0,$f4
/*  f147598:	00000000 */ 	nop
/*  f14759c:	305200ff */ 	andi	$s2,$v0,0xff
/*  f1475a0:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f1475a4:	44185000 */ 	mfc1	$t8,$f10
/*  f1475a8:	04410005 */ 	bgez	$v0,.PF0f1475c0
/*  f1475ac:	afb802e8 */ 	sw	$t8,0x2e8($sp)
/*  f1475b0:	00029023 */ 	negu	$s2,$v0
/*  f1475b4:	325900ff */ 	andi	$t9,$s2,0xff
/*  f1475b8:	10000001 */ 	b	.PF0f1475c0
/*  f1475bc:	03209025 */ 	move	$s2,$t9
.PF0f1475c0:
/*  f1475c0:	0012c083 */ 	sra	$t8,$s2,0x2
/*  f1475c4:	331900ff */ 	andi	$t9,$t8,0xff
/*  f1475c8:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f1475cc:	00127600 */ 	sll	$t6,$s2,0x18
/*  f1475d0:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f1475d4:	371900ff */ 	ori	$t9,$t8,0xff
/*  f1475d8:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f1475dc:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1475e0:	8fae02f4 */ 	lw	$t6,0x2f4($sp)
/*  f1475e4:	3c01f600 */ 	lui	$at,0xf600
/*  f1475e8:	02802025 */ 	move	$a0,$s4
/*  f1475ec:	25cf0005 */ 	addiu	$t7,$t6,0x5
/*  f1475f0:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1475f4:	8faf02f0 */ 	lw	$t7,0x2f0($sp)
/*  f1475f8:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f1475fc:	03217025 */ 	or	$t6,$t9,$at
/*  f147600:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f147604:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f147608:	01d97825 */ 	or	$t7,$t6,$t9
/*  f14760c:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f147610:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f147614:	8fb802f0 */ 	lw	$t8,0x2f0($sp)
/*  f147618:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f14761c:	3c01f600 */ 	lui	$at,0xf600
/*  f147620:	030ec823 */ 	subu	$t9,$t8,$t6
/*  f147624:	8fae02f4 */ 	lw	$t6,0x2f4($sp)
/*  f147628:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f14762c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f147630:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f147634:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f147638:	01f87025 */ 	or	$t6,$t7,$t8
/*  f14763c:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f147640:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f147644:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f147648:	272f0007 */ 	addiu	$t7,$t9,0x7
/*  f14764c:	afaf02f4 */ 	sw	$t7,0x2f4($sp)
/*  f147650:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f147654:	c5c40030 */ 	lwc1	$f4,0x30($t6)
/*  f147658:	46122000 */ 	add.s	$f0,$f4,$f18
/*  f14765c:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f147660:	00000000 */ 	nop
/*  f147664:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f147668:	00000000 */ 	nop
/*  f14766c:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f147670:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f147674:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f147678:	44025000 */ 	mfc1	$v0,$f10
/*  f14767c:	00000000 */ 	nop
/*  f147680:	305200ff */ 	andi	$s2,$v0,0xff
/*  f147684:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f147688:	44183000 */ 	mfc1	$t8,$f6
/*  f14768c:	04410005 */ 	bgez	$v0,.PF0f1476a4
/*  f147690:	afb802e8 */ 	sw	$t8,0x2e8($sp)
/*  f147694:	00029023 */ 	negu	$s2,$v0
/*  f147698:	324e00ff */ 	andi	$t6,$s2,0xff
/*  f14769c:	10000001 */ 	b	.PF0f1476a4
/*  f1476a0:	01c09025 */ 	move	$s2,$t6
.PF0f1476a4:
/*  f1476a4:	0012c083 */ 	sra	$t8,$s2,0x2
/*  f1476a8:	330e00ff */ 	andi	$t6,$t8,0xff
/*  f1476ac:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f1476b0:	00127e00 */ 	sll	$t7,$s2,0x18
/*  f1476b4:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f1476b8:	02801025 */ 	move	$v0,$s4
/*  f1476bc:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f1476c0:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f1476c4:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f1476c8:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f1476cc:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f1476d0:	02801825 */ 	move	$v1,$s4
/*  f1476d4:	25f90005 */ 	addiu	$t9,$t7,0x5
/*  f1476d8:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f1476dc:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f1476e0:	00187380 */ 	sll	$t6,$t8,0xe
/*  f1476e4:	01c17825 */ 	or	$t7,$t6,$at
/*  f1476e8:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f1476ec:	00187080 */ 	sll	$t6,$t8,0x2
/*  f1476f0:	01eec825 */ 	or	$t9,$t7,$t6
/*  f1476f4:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f1476f8:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f1476fc:	8fb802f0 */ 	lw	$t8,0x2f0($sp)
/*  f147700:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f147704:	030f7023 */ 	subu	$t6,$t8,$t7
/*  f147708:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f14770c:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f147710:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f147714:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f147718:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f14771c:	03387825 */ 	or	$t7,$t9,$t8
/*  f147720:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f147724:	8fae02f4 */ 	lw	$t6,0x2f4($sp)
/*  f147728:	25d90007 */ 	addiu	$t9,$t6,0x7
/*  f14772c:	10000045 */ 	b	.PF0f147844
/*  f147730:	afb902f4 */ 	sw	$t9,0x2f4($sp)
.PF0f147734:
/*  f147734:	44985000 */ 	mtc1	$t8,$f10
/*  f147738:	3c0140a0 */ 	lui	$at,0x40a0
/*  f14773c:	44814000 */ 	mtc1	$at,$f8
/*  f147740:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f147744:	44865000 */ 	mtc1	$a2,$f10
/*  f147748:	8fa8008c */ 	lw	$t0,0x8c($sp)
/*  f14774c:	8fae02ac */ 	lw	$t6,0x2ac($sp)
/*  f147750:	240500ff */ 	li	$a1,0xff
/*  f147754:	2508fff3 */ 	addiu	$t0,$t0,-13
/*  f147758:	46082183 */ 	div.s	$f6,$f4,$f8
/*  f14775c:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f147760:	2407001e */ 	li	$a3,0x1e
/*  f147764:	2508fffd */ 	addiu	$t0,$t0,-3
/*  f147768:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f14776c:	44815000 */ 	mtc1	$at,$f10
/*  f147770:	24060008 */ 	li	$a2,0x8
/*  f147774:	00002025 */ 	move	$a0,$zero
/*  f147778:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f14777c:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f147780:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f147784:	44033000 */ 	mfc1	$v1,$f6
/*  f147788:	11c00005 */ 	beqz	$t6,.PF0f1477a0
/*  f14778c:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f147790:	2463fff4 */ 	addiu	$v1,$v1,-12
/*  f147794:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f147798:	2407000f */ 	li	$a3,0xf
/*  f14779c:	afa802f0 */ 	sw	$t0,0x2f0($sp)
.PF0f1477a0:
/*  f1477a0:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f1477a4:	02801025 */ 	move	$v0,$s4
/*  f1477a8:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f1477ac:	8f380490 */ 	lw	$t8,0x490($t9)
/*  f1477b0:	0098082a */ 	slt	$at,$a0,$t8
/*  f1477b4:	54200003 */ 	bnezl	$at,.PF0f1477c4
/*  f1477b8:	30af00ff */ 	andi	$t7,$a1,0xff
/*  f1477bc:	24050088 */ 	li	$a1,0x88
/*  f1477c0:	30af00ff */ 	andi	$t7,$a1,0xff
.PF0f1477c4:
/*  f1477c4:	000f7200 */ 	sll	$t6,$t7,0x8
/*  f1477c8:	01cbc825 */ 	or	$t9,$t6,$t3
/*  f1477cc:	373800ff */ 	ori	$t8,$t9,0xff
/*  f1477d0:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f1477d4:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f1477d8:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f1477dc:	3c01f600 */ 	lui	$at,0xf600
/*  f1477e0:	02801825 */ 	move	$v1,$s4
/*  f1477e4:	01e77021 */ 	addu	$t6,$t7,$a3
/*  f1477e8:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f1477ec:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f1477f0:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f1477f4:	03017825 */ 	or	$t7,$t8,$at
/*  f1477f8:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f1477fc:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f147800:	01f87025 */ 	or	$t6,$t7,$t8
/*  f147804:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f147808:	8fb902f4 */ 	lw	$t9,0x2f4($sp)
/*  f14780c:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f147810:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f147814:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f147818:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f14781c:	25d9fffc */ 	addiu	$t9,$t6,-4
/*  f147820:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f147824:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f147828:	030ec825 */ 	or	$t9,$t8,$t6
/*  f14782c:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f147830:	8faf02f0 */ 	lw	$t7,0x2f0($sp)
/*  f147834:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f147838:	25f8fffb */ 	addiu	$t8,$t7,-5
/*  f14783c:	1486ffd8 */ 	bne	$a0,$a2,.PF0f1477a0
/*  f147840:	afb802f0 */ 	sw	$t8,0x2f0($sp)
.PF0f147844:
/*  f147844:	02801025 */ 	move	$v0,$s4
.PF0f147848:
/*  f147848:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f14784c:	02801825 */ 	move	$v1,$s4
/*  f147850:	ac500000 */ 	sw	$s0,0x0($v0)
/*  f147854:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f147858:	3c0eba00 */ 	lui	$t6,0xba00
/*  f14785c:	35ce0602 */ 	ori	$t6,$t6,0x602
/*  f147860:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f147864:	24190040 */ 	li	$t9,0x40
/*  f147868:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f14786c:	02802025 */ 	move	$a0,$s4
/*  f147870:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f147874:	3c0fba00 */ 	lui	$t7,0xba00
/*  f147878:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f14787c:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f147880:	3c180008 */ 	lui	$t8,0x8
/*  f147884:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f147888:	02802825 */ 	move	$a1,$s4
/*  f14788c:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f147890:	3c0eba00 */ 	lui	$t6,0xba00
/*  f147894:	35ce1001 */ 	ori	$t6,$t6,0x1001
/*  f147898:	3c190001 */ 	lui	$t9,0x1
/*  f14789c:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f1478a0:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f1478a4:	8ecf0298 */ 	lw	$t7,0x298($s6)
/*  f1478a8:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f1478ac:	05e101d6 */ 	bgez	$t7,.PF0f148008
/*  f1478b0:	00000000 */ 	nop
/*  f1478b4:	8ed8029c */ 	lw	$t8,0x29c($s6)
/*  f1478b8:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f1478bc:	8fb90304 */ 	lw	$t9,0x304($sp)
/*  f1478c0:	070101d1 */ 	bgez	$t8,.PF0f148008
/*  f1478c4:	02802025 */ 	move	$a0,$s4
/*  f1478c8:	01d97823 */ 	subu	$t7,$t6,$t9
/*  f1478cc:	25f8ff99 */ 	addiu	$t8,$t7,-103
/*  f1478d0:	44984000 */ 	mtc1	$t8,$f8
/*  f1478d4:	3c014188 */ 	lui	$at,0x4188
/*  f1478d8:	44810000 */ 	mtc1	$at,$f0
/*  f1478dc:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f1478e0:	3c013f80 */ 	lui	$at,0x3f80
/*  f1478e4:	44813000 */ 	mtc1	$at,$f6
/*  f1478e8:	3c0141c8 */ 	lui	$at,0x41c8
/*  f1478ec:	8faf0308 */ 	lw	$t7,0x308($sp)
/*  f1478f0:	8fae0300 */ 	lw	$t6,0x300($sp)
/*  f1478f4:	46005103 */ 	div.s	$f4,$f10,$f0
/*  f1478f8:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f1478fc:	c7a402c8 */ 	lwc1	$f4,0x2c8($sp)
/*  f147900:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f147904:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f147908:	44814000 */ 	mtc1	$at,$f8
/*  f14790c:	44035000 */ 	mfc1	$v1,$f10
/*  f147910:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f147914:	448f3000 */ 	mtc1	$t7,$f6
/*  f147918:	0060a825 */ 	move	$s5,$v1
/*  f14791c:	468033a0 */ 	cvt.s.w	$f14,$f6
/*  f147920:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f147924:	44052000 */ 	mfc1	$a1,$f4
/*  f147928:	00000000 */ 	nop
/*  f14792c:	28a10012 */ 	slti	$at,$a1,0x12
/*  f147930:	54200003 */ 	bnezl	$at,.PF0f147940
/*  f147934:	24180011 */ 	li	$t8,0x11
/*  f147938:	24050011 */ 	li	$a1,0x11
/*  f14793c:	24180011 */ 	li	$t8,0x11
.PF0f147940:
/*  f147940:	240100dc */ 	li	$at,0xdc
/*  f147944:	15c10004 */ 	bne	$t6,$at,.PF0f147958
/*  f147948:	03052823 */ 	subu	$a1,$t8,$a1
/*  f14794c:	2419000a */ 	li	$t9,0xa
/*  f147950:	1000000a */ 	b	.PF0f14797c
/*  f147954:	a3b900cb */ 	sb	$t9,0xcb($sp)
.PF0f147958:
/*  f147958:	8faf0300 */ 	lw	$t7,0x300($sp)
/*  f14795c:	240100b4 */ 	li	$at,0xb4
/*  f147960:	2418fff8 */ 	li	$t8,-8
/*  f147964:	55e10005 */ 	bnel	$t7,$at,.PF0f14797c
/*  f147968:	a3a000cb */ 	sb	$zero,0xcb($sp)
/*  f14796c:	2475ffff */ 	addiu	$s5,$v1,-1
/*  f147970:	10000002 */ 	b	.PF0f14797c
/*  f147974:	a3b800cb */ 	sb	$t8,0xcb($sp)
/*  f147978:	a3a000cb */ 	sb	$zero,0xcb($sp)
.PF0f14797c:
/*  f14797c:	afa500c4 */ 	sw	$a1,0xc4($sp)
/*  f147980:	0fc3534f */ 	jal	func0f0d479c
/*  f147984:	e7ae0078 */ 	swc1	$f14,0x78($sp)
/*  f147988:	c7ae0078 */ 	lwc1	$f14,0x78($sp)
/*  f14798c:	3c0eb600 */ 	lui	$t6,0xb600
/*  f147990:	24193000 */ 	li	$t9,0x3000
/*  f147994:	3c0fb700 */ 	lui	$t7,0xb700
/*  f147998:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f14799c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f1479a0:	ac4f0008 */ 	sw	$t7,0x8($v0)
/*  f1479a4:	3c0efcff */ 	lui	$t6,0xfcff
/*  f1479a8:	3c19fffe */ 	lui	$t9,0xfffe
/*  f1479ac:	3c0fba00 */ 	lui	$t7,0xba00
/*  f1479b0:	3739793c */ 	ori	$t9,$t9,0x793c
/*  f1479b4:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f1479b8:	35ef0c02 */ 	ori	$t7,$t7,0xc02
/*  f1479bc:	24180204 */ 	li	$t8,0x204
/*  f1479c0:	ac4e0010 */ 	sw	$t6,0x10($v0)
/*  f1479c4:	ac590014 */ 	sw	$t9,0x14($v0)
/*  f1479c8:	ac4f0018 */ 	sw	$t7,0x18($v0)
/*  f1479cc:	ac58000c */ 	sw	$t8,0xc($v0)
/*  f1479d0:	3c0eba00 */ 	lui	$t6,0xba00
/*  f1479d4:	3c0f0050 */ 	lui	$t7,0x50
/*  f1479d8:	3c19b900 */ 	lui	$t9,0xb900
/*  f1479dc:	24182000 */ 	li	$t8,0x2000
/*  f1479e0:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f1479e4:	3739031d */ 	ori	$t9,$t9,0x31d
/*  f1479e8:	35ef41c8 */ 	ori	$t7,$t7,0x41c8
/*  f1479ec:	ac58001c */ 	sw	$t8,0x1c($v0)
/*  f1479f0:	ac4e0020 */ 	sw	$t6,0x20($v0)
/*  f1479f4:	ac400024 */ 	sw	$zero,0x24($v0)
/*  f1479f8:	ac4f002c */ 	sw	$t7,0x2c($v0)
/*  f1479fc:	ac590028 */ 	sw	$t9,0x28($v0)
/*  f147a00:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f147a04:	8fb90300 */ 	lw	$t9,0x300($sp)
/*  f147a08:	240100b4 */ 	li	$at,0xb4
/*  f147a0c:	270e003a */ 	addiu	$t6,$t8,0x3a
/*  f147a10:	24540030 */ 	addiu	$s4,$v0,0x30
/*  f147a14:	17210003 */ 	bne	$t9,$at,.PF0f147a24
/*  f147a18:	afae02f0 */ 	sw	$t6,0x2f0($sp)
/*  f147a1c:	25c80005 */ 	addiu	$t0,$t6,0x5
/*  f147a20:	afa802f0 */ 	sw	$t0,0x2f0($sp)
.PF0f147a24:
/*  f147a24:	8faf0300 */ 	lw	$t7,0x300($sp)
/*  f147a28:	3c013f00 */ 	lui	$at,0x3f00
/*  f147a2c:	44812000 */ 	mtc1	$at,$f4
/*  f147a30:	448f4000 */ 	mtc1	$t7,$f8
/*  f147a34:	8fa802f0 */ 	lw	$t0,0x2f0($sp)
/*  f147a38:	8ece006c */ 	lw	$t6,0x6c($s6)
/*  f147a3c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f147a40:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f147a44:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f147a48:	44194000 */ 	mfc1	$t9,$f8
/*  f147a4c:	00000000 */ 	nop
/*  f147a50:	03289823 */ 	subu	$s3,$t9,$t0
/*  f147a54:	2673000a */ 	addiu	$s3,$s3,0xa
/*  f147a58:	11c00003 */ 	beqz	$t6,.PF0f147a68
/*  f147a5c:	afb9008c */ 	sw	$t9,0x8c($sp)
/*  f147a60:	10000002 */ 	b	.PF0f147a6c
/*  f147a64:	24060001 */ 	li	$a2,0x1
.PF0f147a68:
/*  f147a68:	00003025 */ 	move	$a2,$zero
.PF0f147a6c:
/*  f147a6c:	8ecf0068 */ 	lw	$t7,0x68($s6)
/*  f147a70:	51e00004 */ 	beqzl	$t7,.PF0f147a84
/*  f147a74:	00002825 */ 	move	$a1,$zero
/*  f147a78:	10000002 */ 	b	.PF0f147a84
/*  f147a7c:	24050001 */ 	li	$a1,0x1
/*  f147a80:	00002825 */ 	move	$a1,$zero
.PF0f147a84:
/*  f147a84:	8ed80064 */ 	lw	$t8,0x64($s6)
/*  f147a88:	53000004 */ 	beqzl	$t8,.PF0f147a9c
/*  f147a8c:	00001825 */ 	move	$v1,$zero
/*  f147a90:	10000002 */ 	b	.PF0f147a9c
/*  f147a94:	24030001 */ 	li	$v1,0x1
/*  f147a98:	00001825 */ 	move	$v1,$zero
.PF0f147a9c:
/*  f147a9c:	8ed90070 */ 	lw	$t9,0x70($s6)
/*  f147aa0:	53200004 */ 	beqzl	$t9,.PF0f147ab4
/*  f147aa4:	00001025 */ 	move	$v0,$zero
/*  f147aa8:	10000002 */ 	b	.PF0f147ab4
/*  f147aac:	24020001 */ 	li	$v0,0x1
/*  f147ab0:	00001025 */ 	move	$v0,$zero
.PF0f147ab4:
/*  f147ab4:	00437021 */ 	addu	$t6,$v0,$v1
/*  f147ab8:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f147abc:	01e6c021 */ 	addu	$t8,$t7,$a2
/*  f147ac0:	2b010002 */ 	slti	$at,$t8,0x2
/*  f147ac4:	1020000b */ 	beqz	$at,.PF0f147af4
/*  f147ac8:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f147acc:	0fc54e8c */ 	jal	optionsGetEffectiveScreenSize
/*  f147ad0:	e7ae0078 */ 	swc1	$f14,0x78($sp)
/*  f147ad4:	24010001 */ 	li	$at,0x1
/*  f147ad8:	10410006 */ 	beq	$v0,$at,.PF0f147af4
/*  f147adc:	c7ae0078 */ 	lwc1	$f14,0x78($sp)
/*  f147ae0:	0fc54e8c */ 	jal	optionsGetEffectiveScreenSize
/*  f147ae4:	e7ae0078 */ 	swc1	$f14,0x78($sp)
/*  f147ae8:	24010002 */ 	li	$at,0x2
/*  f147aec:	14410004 */ 	bne	$v0,$at,.PF0f147b00
/*  f147af0:	c7ae0078 */ 	lwc1	$f14,0x78($sp)
.PF0f147af4:
/*  f147af4:	8fa802f0 */ 	lw	$t0,0x2f0($sp)
/*  f147af8:	10000003 */ 	b	.PF0f147b08
/*  f147afc:	26730010 */ 	addiu	$s3,$s3,0x10
.PF0f147b00:
/*  f147b00:	26730017 */ 	addiu	$s3,$s3,0x17
/*  f147b04:	8fa802f0 */ 	lw	$t0,0x2f0($sp)
.PF0f147b08:
/*  f147b08:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f147b0c:	3c013f00 */ 	lui	$at,0x3f00
/*  f147b10:	44815000 */ 	mtc1	$at,$f10
/*  f147b14:	03390019 */ 	multu	$t9,$t9
/*  f147b18:	8faf030c */ 	lw	$t7,0x30c($sp)
/*  f147b1c:	460a7102 */ 	mul.s	$f4,$f14,$f10
/*  f147b20:	83b900cb */ 	lb	$t9,0xcb($sp)
/*  f147b24:	25f80022 */ 	addiu	$t8,$t7,0x22
/*  f147b28:	afb80080 */ 	sw	$t8,0x80($sp)
/*  f147b2c:	00008825 */ 	move	$s1,$zero
/*  f147b30:	02798023 */ 	subu	$s0,$s3,$t9
/*  f147b34:	e7a40074 */ 	swc1	$f4,0x74($sp)
/*  f147b38:	00007012 */ 	mflo	$t6
/*  f147b3c:	afae0088 */ 	sw	$t6,0x88($sp)
/*  f147b40:	00000000 */ 	nop
.PF0f147b44:
/*  f147b44:	8fa400c4 */ 	lw	$a0,0xc4($sp)
/*  f147b48:	24120050 */ 	li	$s2,0x50
/*  f147b4c:	24020056 */ 	li	$v0,0x56
/*  f147b50:	0224082a */ 	slt	$at,$s1,$a0
/*  f147b54:	10200003 */ 	beqz	$at,.PF0f147b64
/*  f147b58:	00000000 */ 	nop
/*  f147b5c:	10000001 */ 	b	.PF0f147b64
/*  f147b60:	24120028 */ 	li	$s2,0x28
.PF0f147b64:
/*  f147b64:	0224082a */ 	slt	$at,$s1,$a0
/*  f147b68:	10200003 */ 	beqz	$at,.PF0f147b78
/*  f147b6c:	00000000 */ 	nop
/*  f147b70:	10000001 */ 	b	.PF0f147b78
/*  f147b74:	24020022 */ 	li	$v0,0x22
.PF0f147b78:
/*  f147b78:	02100019 */ 	multu	$s0,$s0
/*  f147b7c:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f147b80:	8fa30080 */ 	lw	$v1,0x80($sp)
/*  f147b84:	01157021 */ 	addu	$t6,$t0,$s5
/*  f147b88:	afa8022c */ 	sw	$t0,0x22c($sp)
/*  f147b8c:	afae0234 */ 	sw	$t6,0x234($sp)
/*  f147b90:	a3a200d7 */ 	sb	$v0,0xd7($sp)
/*  f147b94:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f147b98:	afa30228 */ 	sw	$v1,0x228($sp)
/*  f147b9c:	afa30230 */ 	sw	$v1,0x230($sp)
/*  f147ba0:	0000c012 */ 	mflo	$t8
/*  f147ba4:	01f8c823 */ 	subu	$t9,$t7,$t8
/*  f147ba8:	44993000 */ 	mtc1	$t9,$f6
/*  f147bac:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f147bb0:	0c0127b4 */ 	jal	sqrtf
/*  f147bb4:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f147bb8:	c7aa02b0 */ 	lwc1	$f10,0x2b0($sp)
/*  f147bbc:	c7a80074 */ 	lwc1	$f8,0x74($sp)
/*  f147bc0:	83b800cb */ 	lb	$t8,0xcb($sp)
/*  f147bc4:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f147bc8:	02759823 */ 	subu	$s3,$s3,$s5
/*  f147bcc:	3c0140a0 */ 	lui	$at,0x40a0
/*  f147bd0:	02788023 */ 	subu	$s0,$s3,$t8
/*  f147bd4:	02100019 */ 	multu	$s0,$s0
/*  f147bd8:	44815000 */ 	mtc1	$at,$f10
/*  f147bdc:	8fa802f0 */ 	lw	$t0,0x2f0($sp)
/*  f147be0:	46044181 */ 	sub.s	$f6,$f8,$f4
/*  f147be4:	8fb90088 */ 	lw	$t9,0x88($sp)
/*  f147be8:	01157821 */ 	addu	$t7,$t0,$s5
/*  f147bec:	afaf023c */ 	sw	$t7,0x23c($sp)
/*  f147bf0:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*  f147bf4:	00007012 */ 	mflo	$t6
/*  f147bf8:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f147bfc:	032e7823 */ 	subu	$t7,$t9,$t6
/*  f147c00:	448f3000 */ 	mtc1	$t7,$f6
/*  f147c04:	44032000 */ 	mfc1	$v1,$f4
/*  f147c08:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f147c0c:	afa30240 */ 	sw	$v1,0x240($sp)
/*  f147c10:	0c0127b4 */ 	jal	sqrtf
/*  f147c14:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f147c18:	c7a802b0 */ 	lwc1	$f8,0x2b0($sp)
/*  f147c1c:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f147c20:	3c0140a0 */ 	lui	$at,0x40a0
/*  f147c24:	46080102 */ 	mul.s	$f4,$f0,$f8
/*  f147c28:	44814000 */ 	mtc1	$at,$f8
/*  f147c2c:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f147c30:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f147c34:	93a200d7 */ 	lbu	$v0,0xd7($sp)
/*  f147c38:	afae0244 */ 	sw	$t6,0x244($sp)
/*  f147c3c:	2673fffe */ 	addiu	$s3,$s3,-2
/*  f147c40:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f147c44:	2610fffe */ 	addiu	$s0,$s0,-2
/*  f147c48:	02802025 */ 	move	$a0,$s4
/*  f147c4c:	27a50228 */ 	addiu	$a1,$sp,0x228
/*  f147c50:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f147c54:	00003025 */ 	move	$a2,$zero
/*  f147c58:	324700ff */ 	andi	$a3,$s2,0xff
/*  f147c5c:	24010001 */ 	li	$at,0x1
/*  f147c60:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f147c64:	44192000 */ 	mfc1	$t9,$f4
/*  f147c68:	00000000 */ 	nop
/*  f147c6c:	afb902f4 */ 	sw	$t9,0x2f4($sp)
/*  f147c70:	afb90238 */ 	sw	$t9,0x238($sp)
/*  f147c74:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f147c78:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f147c7c:	14600006 */ 	bnez	$v1,.PF0f147c98
/*  f147c80:	00000000 */ 	nop
/*  f147c84:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f147c88:	0fc510cf */ 	jal	bviewRenderEyespySideRect
/*  f147c8c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f147c90:	10000017 */ 	b	.PF0f147cf0
/*  f147c94:	0040a025 */ 	move	$s4,$v0
.PF0f147c98:
/*  f147c98:	1461000c */ 	bne	$v1,$at,.PF0f147ccc
/*  f147c9c:	02802025 */ 	move	$a0,$s4
/*  f147ca0:	0012c880 */ 	sll	$t9,$s2,0x2
/*  f147ca4:	0332c823 */ 	subu	$t9,$t9,$s2
/*  f147ca8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f147cac:	02802025 */ 	move	$a0,$s4
/*  f147cb0:	27a50228 */ 	addiu	$a1,$sp,0x228
/*  f147cb4:	24060010 */ 	li	$a2,0x10
/*  f147cb8:	324700ff */ 	andi	$a3,$s2,0xff
/*  f147cbc:	0fc510cf */ 	jal	bviewRenderEyespySideRect
/*  f147cc0:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f147cc4:	1000000a */ 	b	.PF0f147cf0
/*  f147cc8:	0040a025 */ 	move	$s4,$v0
.PF0f147ccc:
/*  f147ccc:	00123883 */ 	sra	$a3,$s2,0x2
/*  f147cd0:	30ee00ff */ 	andi	$t6,$a3,0xff
/*  f147cd4:	01c03825 */ 	move	$a3,$t6
/*  f147cd8:	27a50228 */ 	addiu	$a1,$sp,0x228
/*  f147cdc:	324600ff */ 	andi	$a2,$s2,0xff
/*  f147ce0:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f147ce4:	0fc510cf */ 	jal	bviewRenderEyespySideRect
/*  f147ce8:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f147cec:	0040a025 */ 	move	$s4,$v0
.PF0f147cf0:
/*  f147cf0:	8fa802f0 */ 	lw	$t0,0x2f0($sp)
/*  f147cf4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f147cf8:	2a210011 */ 	slti	$at,$s1,0x11
/*  f147cfc:	01154021 */ 	addu	$t0,$t0,$s5
/*  f147d00:	1420ff90 */ 	bnez	$at,.PF0f147b44
/*  f147d04:	25080002 */ 	addiu	$t0,$t0,0x2
/*  f147d08:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f147d0c:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f147d10:	3c014188 */ 	lui	$at,0x4188
/*  f147d14:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f147d18:	44814000 */ 	mtc1	$at,$f8
/*  f147d1c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f147d20:	c7060060 */ 	lwc1	$f6,0x60($t8)
/*  f147d24:	c424727c */ 	lwc1	$f4,0x727c($at)
/*  f147d28:	240e0011 */ 	li	$t6,0x11
/*  f147d2c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f147d30:	8fa80304 */ 	lw	$t0,0x304($sp)
/*  f147d34:	8faf0300 */ 	lw	$t7,0x300($sp)
/*  f147d38:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f147d3c:	00003025 */ 	move	$a2,$zero
/*  f147d40:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f147d44:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f147d48:	44044000 */ 	mfc1	$a0,$f8
/*  f147d4c:	00000000 */ 	nop
/*  f147d50:	28810012 */ 	slti	$at,$a0,0x12
/*  f147d54:	54200003 */ 	bnezl	$at,.PF0f147d64
/*  f147d58:	240100b4 */ 	li	$at,0xb4
/*  f147d5c:	24040011 */ 	li	$a0,0x11
/*  f147d60:	240100b4 */ 	li	$at,0xb4
.PF0f147d64:
/*  f147d64:	01c42023 */ 	subu	$a0,$t6,$a0
/*  f147d68:	15e10002 */ 	bne	$t7,$at,.PF0f147d74
/*  f147d6c:	2508002e */ 	addiu	$t0,$t0,0x2e
/*  f147d70:	25080005 */ 	addiu	$t0,$t0,0x5
.PF0f147d74:
/*  f147d74:	8ed9006c */ 	lw	$t9,0x6c($s6)
/*  f147d78:	03089823 */ 	subu	$s3,$t8,$t0
/*  f147d7c:	2673000a */ 	addiu	$s3,$s3,0xa
/*  f147d80:	13200003 */ 	beqz	$t9,.PF0f147d90
/*  f147d84:	00002825 */ 	move	$a1,$zero
/*  f147d88:	10000001 */ 	b	.PF0f147d90
/*  f147d8c:	24060001 */ 	li	$a2,0x1
.PF0f147d90:
/*  f147d90:	8ece0068 */ 	lw	$t6,0x68($s6)
/*  f147d94:	00001825 */ 	move	$v1,$zero
/*  f147d98:	00001025 */ 	move	$v0,$zero
/*  f147d9c:	11c00003 */ 	beqz	$t6,.PF0f147dac
/*  f147da0:	00000000 */ 	nop
/*  f147da4:	10000001 */ 	b	.PF0f147dac
/*  f147da8:	24050001 */ 	li	$a1,0x1
.PF0f147dac:
/*  f147dac:	8ecf0064 */ 	lw	$t7,0x64($s6)
/*  f147db0:	11e00003 */ 	beqz	$t7,.PF0f147dc0
/*  f147db4:	00000000 */ 	nop
/*  f147db8:	10000001 */ 	b	.PF0f147dc0
/*  f147dbc:	24030001 */ 	li	$v1,0x1
.PF0f147dc0:
/*  f147dc0:	8ed80070 */ 	lw	$t8,0x70($s6)
/*  f147dc4:	13000003 */ 	beqz	$t8,.PF0f147dd4
/*  f147dc8:	00000000 */ 	nop
/*  f147dcc:	10000001 */ 	b	.PF0f147dd4
/*  f147dd0:	24020001 */ 	li	$v0,0x1
.PF0f147dd4:
/*  f147dd4:	0043c821 */ 	addu	$t9,$v0,$v1
/*  f147dd8:	03257021 */ 	addu	$t6,$t9,$a1
/*  f147ddc:	01c67821 */ 	addu	$t7,$t6,$a2
/*  f147de0:	29e10002 */ 	slti	$at,$t7,0x2
/*  f147de4:	afa400c4 */ 	sw	$a0,0xc4($sp)
/*  f147de8:	1020000b */ 	beqz	$at,.PF0f147e18
/*  f147dec:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f147df0:	0fc54e8c */ 	jal	optionsGetEffectiveScreenSize
/*  f147df4:	afa400c4 */ 	sw	$a0,0xc4($sp)
/*  f147df8:	24010001 */ 	li	$at,0x1
/*  f147dfc:	50410007 */ 	beql	$v0,$at,.PF0f147e1c
/*  f147e00:	8fa802f0 */ 	lw	$t0,0x2f0($sp)
/*  f147e04:	0fc54e8c */ 	jal	optionsGetEffectiveScreenSize
/*  f147e08:	00000000 */ 	nop
/*  f147e0c:	24010002 */ 	li	$at,0x2
/*  f147e10:	14410004 */ 	bne	$v0,$at,.PF0f147e24
/*  f147e14:	8fa802f0 */ 	lw	$t0,0x2f0($sp)
.PF0f147e18:
/*  f147e18:	8fa802f0 */ 	lw	$t0,0x2f0($sp)
.PF0f147e1c:
/*  f147e1c:	10000002 */ 	b	.PF0f147e28
/*  f147e20:	26730010 */ 	addiu	$s3,$s3,0x10
.PF0f147e24:
/*  f147e24:	26730017 */ 	addiu	$s3,$s3,0x17
.PF0f147e28:
/*  f147e28:	8fb90090 */ 	lw	$t9,0x90($sp)
/*  f147e2c:	83b800cb */ 	lb	$t8,0xcb($sp)
/*  f147e30:	00008825 */ 	move	$s1,$zero
/*  f147e34:	272effde */ 	addiu	$t6,$t9,-34
/*  f147e38:	afae008c */ 	sw	$t6,0x8c($sp)
/*  f147e3c:	02788023 */ 	subu	$s0,$s3,$t8
.PF0f147e40:
/*  f147e40:	8fa400c4 */ 	lw	$a0,0xc4($sp)
/*  f147e44:	24120050 */ 	li	$s2,0x50
/*  f147e48:	24020056 */ 	li	$v0,0x56
/*  f147e4c:	0224082a */ 	slt	$at,$s1,$a0
/*  f147e50:	10200003 */ 	beqz	$at,.PF0f147e60
/*  f147e54:	8fa3008c */ 	lw	$v1,0x8c($sp)
/*  f147e58:	10000001 */ 	b	.PF0f147e60
/*  f147e5c:	24120028 */ 	li	$s2,0x28
.PF0f147e60:
/*  f147e60:	0224082a */ 	slt	$at,$s1,$a0
/*  f147e64:	10200003 */ 	beqz	$at,.PF0f147e74
/*  f147e68:	00000000 */ 	nop
/*  f147e6c:	10000001 */ 	b	.PF0f147e74
/*  f147e70:	24020022 */ 	li	$v0,0x22
.PF0f147e74:
/*  f147e74:	02100019 */ 	multu	$s0,$s0
/*  f147e78:	8fb80088 */ 	lw	$t8,0x88($sp)
/*  f147e7c:	01157821 */ 	addu	$t7,$t0,$s5
/*  f147e80:	afa30228 */ 	sw	$v1,0x228($sp)
/*  f147e84:	afa8022c */ 	sw	$t0,0x22c($sp)
/*  f147e88:	afaf0234 */ 	sw	$t7,0x234($sp)
/*  f147e8c:	afa30230 */ 	sw	$v1,0x230($sp)
/*  f147e90:	a3a200d7 */ 	sb	$v0,0xd7($sp)
/*  f147e94:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f147e98:	afa400c4 */ 	sw	$a0,0xc4($sp)
/*  f147e9c:	0000c812 */ 	mflo	$t9
/*  f147ea0:	03197023 */ 	subu	$t6,$t8,$t9
/*  f147ea4:	448e5000 */ 	mtc1	$t6,$f10
/*  f147ea8:	afa802f0 */ 	sw	$t0,0x2f0($sp)
/*  f147eac:	0c0127b4 */ 	jal	sqrtf
/*  f147eb0:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f147eb4:	c7a402b0 */ 	lwc1	$f4,0x2b0($sp)
/*  f147eb8:	c7a80074 */ 	lwc1	$f8,0x74($sp)
/*  f147ebc:	83b900cb */ 	lb	$t9,0xcb($sp)
/*  f147ec0:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f147ec4:	02759823 */ 	subu	$s3,$s3,$s5
/*  f147ec8:	3c0140a0 */ 	lui	$at,0x40a0
/*  f147ecc:	02798023 */ 	subu	$s0,$s3,$t9
/*  f147ed0:	02100019 */ 	multu	$s0,$s0
/*  f147ed4:	44812000 */ 	mtc1	$at,$f4
/*  f147ed8:	8fa802f0 */ 	lw	$t0,0x2f0($sp)
/*  f147edc:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f147ee0:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f147ee4:	0115c021 */ 	addu	$t8,$t0,$s5
/*  f147ee8:	afb8023c */ 	sw	$t8,0x23c($sp)
/*  f147eec:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f147ef0:	00007812 */ 	mflo	$t7
/*  f147ef4:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f147ef8:	01cfc023 */ 	subu	$t8,$t6,$t7
/*  f147efc:	44985000 */ 	mtc1	$t8,$f10
/*  f147f00:	44034000 */ 	mfc1	$v1,$f8
/*  f147f04:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f147f08:	afa30240 */ 	sw	$v1,0x240($sp)
/*  f147f0c:	0c0127b4 */ 	jal	sqrtf
/*  f147f10:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f147f14:	c7a402b0 */ 	lwc1	$f4,0x2b0($sp)
/*  f147f18:	c7a80074 */ 	lwc1	$f8,0x74($sp)
/*  f147f1c:	3c0140a0 */ 	lui	$at,0x40a0
/*  f147f20:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f147f24:	44812000 */ 	mtc1	$at,$f4
/*  f147f28:	8faf02f0 */ 	lw	$t7,0x2f0($sp)
/*  f147f2c:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f147f30:	93a200d7 */ 	lbu	$v0,0xd7($sp)
/*  f147f34:	afaf0244 */ 	sw	$t7,0x244($sp)
/*  f147f38:	2673fffe */ 	addiu	$s3,$s3,-2
/*  f147f3c:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f147f40:	2610fffe */ 	addiu	$s0,$s0,-2
/*  f147f44:	02802025 */ 	move	$a0,$s4
/*  f147f48:	27a50228 */ 	addiu	$a1,$sp,0x228
/*  f147f4c:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f147f50:	00003025 */ 	move	$a2,$zero
/*  f147f54:	324700ff */ 	andi	$a3,$s2,0xff
/*  f147f58:	24010001 */ 	li	$at,0x1
/*  f147f5c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f147f60:	440e4000 */ 	mfc1	$t6,$f8
/*  f147f64:	00000000 */ 	nop
/*  f147f68:	afae02f4 */ 	sw	$t6,0x2f4($sp)
/*  f147f6c:	afae0238 */ 	sw	$t6,0x238($sp)
/*  f147f70:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f147f74:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f147f78:	14600006 */ 	bnez	$v1,.PF0f147f94
/*  f147f7c:	00000000 */ 	nop
/*  f147f80:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f147f84:	0fc510cf */ 	jal	bviewRenderEyespySideRect
/*  f147f88:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f147f8c:	10000017 */ 	b	.PF0f147fec
/*  f147f90:	0040a025 */ 	move	$s4,$v0
.PF0f147f94:
/*  f147f94:	1461000c */ 	bne	$v1,$at,.PF0f147fc8
/*  f147f98:	02802025 */ 	move	$a0,$s4
/*  f147f9c:	00127080 */ 	sll	$t6,$s2,0x2
/*  f147fa0:	01d27023 */ 	subu	$t6,$t6,$s2
/*  f147fa4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f147fa8:	02802025 */ 	move	$a0,$s4
/*  f147fac:	27a50228 */ 	addiu	$a1,$sp,0x228
/*  f147fb0:	24060010 */ 	li	$a2,0x10
/*  f147fb4:	324700ff */ 	andi	$a3,$s2,0xff
/*  f147fb8:	0fc510cf */ 	jal	bviewRenderEyespySideRect
/*  f147fbc:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f147fc0:	1000000a */ 	b	.PF0f147fec
/*  f147fc4:	0040a025 */ 	move	$s4,$v0
.PF0f147fc8:
/*  f147fc8:	00123883 */ 	sra	$a3,$s2,0x2
/*  f147fcc:	30ef00ff */ 	andi	$t7,$a3,0xff
/*  f147fd0:	01e03825 */ 	move	$a3,$t7
/*  f147fd4:	27a50228 */ 	addiu	$a1,$sp,0x228
/*  f147fd8:	324600ff */ 	andi	$a2,$s2,0xff
/*  f147fdc:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f147fe0:	0fc510cf */ 	jal	bviewRenderEyespySideRect
/*  f147fe4:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f147fe8:	0040a025 */ 	move	$s4,$v0
.PF0f147fec:
/*  f147fec:	8fa802f0 */ 	lw	$t0,0x2f0($sp)
/*  f147ff0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f147ff4:	24010011 */ 	li	$at,0x11
/*  f147ff8:	01154021 */ 	addu	$t0,$t0,$s5
/*  f147ffc:	1621ff90 */ 	bne	$s1,$at,.PF0f147e40
/*  f148000:	25080002 */ 	addiu	$t0,$t0,0x2
/*  f148004:	afa802f0 */ 	sw	$t0,0x2f0($sp)
.PF0f148008:
/*  f148008:	0fc353da */ 	jal	func0f0d49c8
/*  f14800c:	02802025 */ 	move	$a0,$s4
.PF0f148010:
/*  f148010:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f148014:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f148018:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f14801c:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f148020:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f148024:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f148028:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f14802c:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f148030:	03e00008 */ 	jr	$ra
/*  f148034:	27bd0410 */ 	addiu	$sp,$sp,0x410
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel bviewRenderEyespyDecorations
.late_rodata
glabel var7f1b5f4c
.word 0x3a83126f
glabel var7f1b5f50
.word 0x3f19999a
glabel var7f1b5f54
.word 0x3c23d70a
glabel var7f1b5f58
.word 0x3bcccccd
.text
/*  f143888:	27bdfbf8 */ 	addiu	$sp,$sp,-1032
/*  f14388c:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f143890:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f143894:	0080a825 */ 	or	$s5,$a0,$zero
/*  f143898:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f14389c:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f1438a0:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f1438a4:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f1438a8:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f1438ac:	0c002f40 */ 	jal	viGetViewLeft
/*  f1438b0:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1438b4:	0c002f44 */ 	jal	viGetViewTop
/*  f1438b8:	afa20304 */ 	sw	$v0,0x304($sp)
/*  f1438bc:	0c002f22 */ 	jal	viGetViewWidth
/*  f1438c0:	afa20300 */ 	sw	$v0,0x300($sp)
/*  f1438c4:	0c002f26 */ 	jal	viGetViewHeight
/*  f1438c8:	00408825 */ 	or	$s1,$v0,$zero
/*  f1438cc:	8fae0300 */ 	lw	$t6,0x300($sp)
/*  f1438d0:	44806000 */ 	mtc1	$zero,$f12
/*  f1438d4:	2a210141 */ 	slti	$at,$s1,0x141
/*  f1438d8:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f1438dc:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f1438e0:	afa202f8 */ 	sw	$v0,0x2f8($sp)
/*  f1438e4:	14200004 */ 	bnez	$at,.L0f1438f8
/*  f1438e8:	afb802f0 */ 	sw	$t8,0x2f0($sp)
/*  f1438ec:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f1438f0:	10000003 */ 	b	.L0f143900
/*  f1438f4:	afb902ac */ 	sw	$t9,0x2ac($sp)
.L0f1438f8:
/*  f1438f8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1438fc:	afae02ac */ 	sw	$t6,0x2ac($sp)
.L0f143900:
/*  f143900:	3c16800a */ 	lui	$s6,%hi(g_Vars)
/*  f143904:	26d69fc0 */ 	addiu	$s6,$s6,%lo(g_Vars)
/*  f143908:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f14390c:	afa002a8 */ 	sw	$zero,0x2a8($sp)
/*  f143910:	8de20480 */ 	lw	$v0,0x480($t7)
/*  f143914:	10400007 */ 	beqz	$v0,.L0f143934
/*  f143918:	00000000 */ 	nop
/*  f14391c:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f143920:	10600004 */ 	beqz	$v1,.L0f143934
/*  f143924:	00000000 */ 	nop
/*  f143928:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f14392c:	14400003 */ 	bnez	$v0,.L0f14393c
/*  f143930:	00408025 */ 	or	$s0,$v0,$zero
.L0f143934:
/*  f143934:	10000e65 */ 	b	.L0f1472cc
/*  f143938:	02a01025 */ 	or	$v0,$s5,$zero
.L0f14393c:
/*  f14393c:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f143940:	e7ac02bc */ 	swc1	$f12,0x2bc($sp)
/*  f143944:	44800000 */ 	mtc1	$zero,$f0
/*  f143948:	24010001 */ 	addiu	$at,$zero,0x1
/*  f14394c:	1441001f */ 	bne	$v0,$at,.L0f1439cc
/*  f143950:	c7ac02bc */ 	lwc1	$f12,0x2bc($sp)
/*  f143954:	8ed8006c */ 	lw	$t8,0x6c($s6)
/*  f143958:	00002825 */ 	or	$a1,$zero,$zero
/*  f14395c:	00001825 */ 	or	$v1,$zero,$zero
/*  f143960:	13000003 */ 	beqz	$t8,.L0f143970
/*  f143964:	00002025 */ 	or	$a0,$zero,$zero
/*  f143968:	10000001 */ 	b	.L0f143970
/*  f14396c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f143970:
/*  f143970:	8ed90068 */ 	lw	$t9,0x68($s6)
/*  f143974:	00001025 */ 	or	$v0,$zero,$zero
/*  f143978:	13200003 */ 	beqz	$t9,.L0f143988
/*  f14397c:	00000000 */ 	nop
/*  f143980:	10000001 */ 	b	.L0f143988
/*  f143984:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f143988:
/*  f143988:	8ece0064 */ 	lw	$t6,0x64($s6)
/*  f14398c:	11c00003 */ 	beqz	$t6,.L0f14399c
/*  f143990:	00000000 */ 	nop
/*  f143994:	10000001 */ 	b	.L0f14399c
/*  f143998:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f14399c:
/*  f14399c:	8ecf0070 */ 	lw	$t7,0x70($s6)
/*  f1439a0:	11e00003 */ 	beqz	$t7,.L0f1439b0
/*  f1439a4:	00000000 */ 	nop
/*  f1439a8:	10000001 */ 	b	.L0f1439b0
/*  f1439ac:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1439b0:
/*  f1439b0:	0044c021 */ 	addu	$t8,$v0,$a0
/*  f1439b4:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f1439b8:	03257021 */ 	addu	$t6,$t9,$a1
/*  f1439bc:	29c10002 */ 	slti	$at,$t6,0x2
/*  f1439c0:	14200002 */ 	bnez	$at,.L0f1439cc
/*  f1439c4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f1439c8:	afaf02a8 */ 	sw	$t7,0x2a8($sp)
.L0f1439cc:
/*  f1439cc:	8e02001c */ 	lw	$v0,0x1c($s0)
/*  f1439d0:	c60600c8 */ 	lwc1	$f6,0xc8($s0)
/*  f1439d4:	3c017f1b */ 	lui	$at,%hi(var7f1b5f4c)
/*  f1439d8:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f1439dc:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f1439e0:	c60600cc */ 	lwc1	$f6,0xcc($s0)
/*  f1439e4:	c444000c */ 	lwc1	$f4,0xc($v0)
/*  f1439e8:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f1439ec:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f1439f0:	44035000 */ 	mfc1	$v1,$f10
/*  f1439f4:	c60600d0 */ 	lwc1	$f6,0xd0($s0)
/*  f1439f8:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f1439fc:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f143a00:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f143a04:	44832000 */ 	mtc1	$v1,$f4
/*  f143a08:	44045000 */ 	mfc1	$a0,$f10
/*  f143a0c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f143a10:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f143a14:	46060032 */ 	c.eq.s	$f0,$f6
/*  f143a18:	44055000 */ 	mfc1	$a1,$f10
/*  f143a1c:	4500000f */ 	bc1f	.L0f143a5c
/*  f143a20:	00000000 */ 	nop
/*  f143a24:	44844000 */ 	mtc1	$a0,$f8
/*  f143a28:	00000000 */ 	nop
/*  f143a2c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f143a30:	460a0032 */ 	c.eq.s	$f0,$f10
/*  f143a34:	00000000 */ 	nop
/*  f143a38:	45000008 */ 	bc1f	.L0f143a5c
/*  f143a3c:	00000000 */ 	nop
/*  f143a40:	44852000 */ 	mtc1	$a1,$f4
/*  f143a44:	00000000 */ 	nop
/*  f143a48:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f143a4c:	46060032 */ 	c.eq.s	$f0,$f6
/*  f143a50:	00000000 */ 	nop
/*  f143a54:	4501000f */ 	bc1t	.L0f143a94
/*  f143a58:	00000000 */ 	nop
.L0f143a5c:
/*  f143a5c:	00630019 */ 	multu	$v1,$v1
/*  f143a60:	00007812 */ 	mflo	$t7
/*  f143a64:	00000000 */ 	nop
/*  f143a68:	00000000 */ 	nop
/*  f143a6c:	00840019 */ 	multu	$a0,$a0
/*  f143a70:	0000c012 */ 	mflo	$t8
/*  f143a74:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f143a78:	00000000 */ 	nop
/*  f143a7c:	00a50019 */ 	multu	$a1,$a1
/*  f143a80:	00007012 */ 	mflo	$t6
/*  f143a84:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f143a88:	448f4000 */ 	mtc1	$t7,$f8
/*  f143a8c:	00000000 */ 	nop
/*  f143a90:	46804320 */ 	cvt.s.w	$f12,$f8
.L0f143a94:
/*  f143a94:	c42a5f4c */ 	lwc1	$f10,%lo(var7f1b5f4c)($at)
/*  f143a98:	460c503c */ 	c.lt.s	$f10,$f12
/*  f143a9c:	00000000 */ 	nop
/*  f143aa0:	45020006 */ 	bc1fl	.L0f143abc
/*  f143aa4:	e7a002c0 */ 	swc1	$f0,0x2c0($sp)
/*  f143aa8:	0c012974 */ 	jal	sqrtf
/*  f143aac:	00000000 */ 	nop
/*  f143ab0:	10000002 */ 	b	.L0f143abc
/*  f143ab4:	e7a002c0 */ 	swc1	$f0,0x2c0($sp)
/*  f143ab8:	e7a002c0 */ 	swc1	$f0,0x2c0($sp)
.L0f143abc:
/*  f143abc:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f143ac0:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f143ac4:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f143ac8:	14600006 */ 	bnez	$v1,.L0f143ae4
/*  f143acc:	3c0500ff */ 	lui	$a1,0xff
/*  f143ad0:	34a50028 */ 	ori	$a1,$a1,0x28
/*  f143ad4:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f143ad8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f143adc:	1000000e */ 	b	.L0f143b18
/*  f143ae0:	0040a825 */ 	or	$s5,$v0,$zero
.L0f143ae4:
/*  f143ae4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f143ae8:	14610007 */ 	bne	$v1,$at,.L0f143b08
/*  f143aec:	02a02025 */ 	or	$a0,$s5,$zero
/*  f143af0:	3c052244 */ 	lui	$a1,0x2244
/*  f143af4:	34a5ffa0 */ 	ori	$a1,$a1,0xffa0
/*  f143af8:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f143afc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f143b00:	10000005 */ 	b	.L0f143b18
/*  f143b04:	0040a825 */ 	or	$s5,$v0,$zero
.L0f143b08:
/*  f143b08:	3c05ff33 */ 	lui	$a1,0xff33
/*  f143b0c:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f143b10:	34a500a0 */ 	ori	$a1,$a1,0xa0
/*  f143b14:	0040a825 */ 	or	$s5,$v0,$zero
.L0f143b18:
/*  f143b18:	8fae02a8 */ 	lw	$t6,0x2a8($sp)
/*  f143b1c:	55c00182 */ 	bnezl	$t6,.L0f144128
/*  f143b20:	44912000 */ 	mtc1	$s1,$f4
/*  f143b24:	44913000 */ 	mtc1	$s1,$f6
/*  f143b28:	3c013f80 */ 	lui	$at,0x3f80
/*  f143b2c:	44818000 */ 	mtc1	$at,$f16
/*  f143b30:	468033a0 */ 	cvt.s.w	$f14,$f6
/*  f143b34:	3c0140a0 */ 	lui	$at,0x40a0
/*  f143b38:	44814000 */ 	mtc1	$at,$f8
/*  f143b3c:	8fad02f0 */ 	lw	$t5,0x2f0($sp)
/*  f143b40:	8fbf0304 */ 	lw	$ra,0x304($sp)
/*  f143b44:	3c0cf600 */ 	lui	$t4,0xf600
/*  f143b48:	46087003 */ 	div.s	$f0,$f14,$f8
/*  f143b4c:	25a4ffe8 */ 	addiu	$a0,$t5,-24
/*  f143b50:	308f03ff */ 	andi	$t7,$a0,0x3ff
/*  f143b54:	27f9001a */ 	addiu	$t9,$ra,0x1a
/*  f143b58:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f143b5c:	000f2080 */ 	sll	$a0,$t7,0x2
/*  f143b60:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f143b64:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f143b68:	27e50019 */ 	addiu	$a1,$ra,0x19
/*  f143b6c:	44852000 */ 	mtc1	$a1,$f4
/*  f143b70:	0304c825 */ 	or	$t9,$t8,$a0
/*  f143b74:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f143b78:	8fa70300 */ 	lw	$a3,0x300($sp)
/*  f143b7c:	30a803ff */ 	andi	$t0,$a1,0x3ff
/*  f143b80:	00087380 */ 	sll	$t6,$t0,0xe
/*  f143b84:	24e70037 */ 	addiu	$a3,$a3,0x37
/*  f143b88:	30ef03ff */ 	andi	$t7,$a3,0x3ff
/*  f143b8c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f143b90:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f143b94:	03003825 */ 	or	$a3,$t8,$zero
/*  f143b98:	01c04025 */ 	or	$t0,$t6,$zero
/*  f143b9c:	25a9ffd6 */ 	addiu	$t1,$t5,-42
/*  f143ba0:	468020a0 */ 	cvt.s.w	$f2,$f4
/*  f143ba4:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f143ba8:	312e03ff */ 	andi	$t6,$t1,0x3ff
/*  f143bac:	27f80020 */ 	addiu	$t8,$ra,0x20
/*  f143bb0:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f143bb4:	000e4880 */ 	sll	$t1,$t6,0x2
/*  f143bb8:	46001280 */ 	add.s	$f10,$f2,$f0
/*  f143bbc:	00197380 */ 	sll	$t6,$t9,0xe
/*  f143bc0:	24550008 */ 	addiu	$s5,$v0,0x8
/*  f143bc4:	01cc7825 */ 	or	$t7,$t6,$t4
/*  f143bc8:	46105100 */ 	add.s	$f4,$f10,$f16
/*  f143bcc:	27ea001f */ 	addiu	$t2,$ra,0x1f
/*  f143bd0:	315903ff */ 	andi	$t9,$t2,0x3ff
/*  f143bd4:	01e9c025 */ 	or	$t8,$t7,$t1
/*  f143bd8:	02a03025 */ 	or	$a2,$s5,$zero
/*  f143bdc:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f143be0:	00195380 */ 	sll	$t2,$t9,0xe
/*  f143be4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f143be8:	4458f800 */ 	cfc1	$t8,$31
/*  f143bec:	44d9f800 */ 	ctc1	$t9,$31
/*  f143bf0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f143bf4:	01477825 */ 	or	$t7,$t2,$a3
/*  f143bf8:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f143bfc:	02a05825 */ 	or	$t3,$s5,$zero
/*  f143c00:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f143c04:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f143c08:	4459f800 */ 	cfc1	$t9,$31
/*  f143c0c:	3c014f00 */ 	lui	$at,0x4f00
/*  f143c10:	33390078 */ 	andi	$t9,$t9,0x78
/*  f143c14:	53200013 */ 	beqzl	$t9,.L0f143c64
/*  f143c18:	44193000 */ 	mfc1	$t9,$f6
/*  f143c1c:	44813000 */ 	mtc1	$at,$f6
/*  f143c20:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f143c24:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f143c28:	44d9f800 */ 	ctc1	$t9,$31
/*  f143c2c:	00000000 */ 	nop
/*  f143c30:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f143c34:	4459f800 */ 	cfc1	$t9,$31
/*  f143c38:	00000000 */ 	nop
/*  f143c3c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f143c40:	17200005 */ 	bnez	$t9,.L0f143c58
/*  f143c44:	00000000 */ 	nop
/*  f143c48:	44193000 */ 	mfc1	$t9,$f6
/*  f143c4c:	3c018000 */ 	lui	$at,0x8000
/*  f143c50:	10000007 */ 	b	.L0f143c70
/*  f143c54:	0321c825 */ 	or	$t9,$t9,$at
.L0f143c58:
/*  f143c58:	10000005 */ 	b	.L0f143c70
/*  f143c5c:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f143c60:	44193000 */ 	mfc1	$t9,$f6
.L0f143c64:
/*  f143c64:	00000000 */ 	nop
/*  f143c68:	0720fffb */ 	bltz	$t9,.L0f143c58
/*  f143c6c:	00000000 */ 	nop
.L0f143c70:
/*  f143c70:	3c0140e0 */ 	lui	$at,0x40e0
/*  f143c74:	44d8f800 */ 	ctc1	$t8,$31
/*  f143c78:	44814000 */ 	mtc1	$at,$f8
/*  f143c7c:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f143c80:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f143c84:	46087303 */ 	div.s	$f12,$f14,$f8
/*  f143c88:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f143c8c:	0304c825 */ 	or	$t9,$t8,$a0
/*  f143c90:	ad790000 */ 	sw	$t9,0x0($t3)
/*  f143c94:	8fb002f0 */ 	lw	$s0,0x2f0($sp)
/*  f143c98:	02a01025 */ 	or	$v0,$s5,$zero
/*  f143c9c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f143ca0:	260effe7 */ 	addiu	$t6,$s0,-25
/*  f143ca4:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f143ca8:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f143cac:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f143cb0:	0118c825 */ 	or	$t9,$t0,$t8
/*  f143cb4:	02a01825 */ 	or	$v1,$s5,$zero
/*  f143cb8:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f143cbc:	3c04f600 */ 	lui	$a0,0xf600
/*  f143cc0:	3c014f00 */ 	lui	$at,0x4f00
/*  f143cc4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f143cc8:	2605ffca */ 	addiu	$a1,$s0,-54
/*  f143ccc:	460c1280 */ 	add.s	$f10,$f2,$f12
/*  f143cd0:	46105100 */ 	add.s	$f4,$f10,$f16
/*  f143cd4:	444ef800 */ 	cfc1	$t6,$31
/*  f143cd8:	44cff800 */ 	ctc1	$t7,$31
/*  f143cdc:	00000000 */ 	nop
/*  f143ce0:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f143ce4:	444ff800 */ 	cfc1	$t7,$31
/*  f143ce8:	00000000 */ 	nop
/*  f143cec:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f143cf0:	51e00013 */ 	beqzl	$t7,.L0f143d40
/*  f143cf4:	440f3000 */ 	mfc1	$t7,$f6
/*  f143cf8:	44813000 */ 	mtc1	$at,$f6
/*  f143cfc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f143d00:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f143d04:	44cff800 */ 	ctc1	$t7,$31
/*  f143d08:	00000000 */ 	nop
/*  f143d0c:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f143d10:	444ff800 */ 	cfc1	$t7,$31
/*  f143d14:	00000000 */ 	nop
/*  f143d18:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f143d1c:	15e00005 */ 	bnez	$t7,.L0f143d34
/*  f143d20:	00000000 */ 	nop
/*  f143d24:	440f3000 */ 	mfc1	$t7,$f6
/*  f143d28:	3c018000 */ 	lui	$at,0x8000
/*  f143d2c:	10000007 */ 	b	.L0f143d4c
/*  f143d30:	01e17825 */ 	or	$t7,$t7,$at
.L0f143d34:
/*  f143d34:	10000005 */ 	b	.L0f143d4c
/*  f143d38:	240fffff */ 	addiu	$t7,$zero,-1
/*  f143d3c:	440f3000 */ 	mfc1	$t7,$f6
.L0f143d40:
/*  f143d40:	00000000 */ 	nop
/*  f143d44:	05e0fffb */ 	bltz	$t7,.L0f143d34
/*  f143d48:	00000000 */ 	nop
.L0f143d4c:
/*  f143d4c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f143d50:	44cef800 */ 	ctc1	$t6,$31
/*  f143d54:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f143d58:	03247025 */ 	or	$t6,$t9,$a0
/*  f143d5c:	01c97825 */ 	or	$t7,$t6,$t1
/*  f143d60:	2618ffd5 */ 	addiu	$t8,$s0,-43
/*  f143d64:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f143d68:	00197080 */ 	sll	$t6,$t9,0x2
/*  f143d6c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f143d70:	014e7825 */ 	or	$t7,$t2,$t6
/*  f143d74:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f143d78:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f143d7c:	3c01f600 */ 	lui	$at,0xf600
/*  f143d80:	02a01025 */ 	or	$v0,$s5,$zero
/*  f143d84:	0311f821 */ 	addu	$ra,$t8,$s1
/*  f143d88:	27ffffff */ 	addiu	$ra,$ra,-1
/*  f143d8c:	27f9ffe8 */ 	addiu	$t9,$ra,-24
/*  f143d90:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f143d94:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f143d98:	30b803ff */ 	andi	$t8,$a1,0x3ff
/*  f143d9c:	00182880 */ 	sll	$a1,$t8,0x2
/*  f143da0:	01e46825 */ 	or	$t5,$t7,$a0
/*  f143da4:	01a57025 */ 	or	$t6,$t5,$a1
/*  f143da8:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f143dac:	8fa60300 */ 	lw	$a2,0x300($sp)
/*  f143db0:	27ecffe7 */ 	addiu	$t4,$ra,-25
/*  f143db4:	319903ff */ 	andi	$t9,$t4,0x3ff
/*  f143db8:	24c60019 */ 	addiu	$a2,$a2,0x19
/*  f143dbc:	30cf03ff */ 	andi	$t7,$a2,0x3ff
/*  f143dc0:	448c4000 */ 	mtc1	$t4,$f8
/*  f143dc4:	000f3080 */ 	sll	$a2,$t7,0x2
/*  f143dc8:	00197380 */ 	sll	$t6,$t9,0xe
/*  f143dcc:	27e4ffe2 */ 	addiu	$a0,$ra,-30
/*  f143dd0:	01c67825 */ 	or	$t7,$t6,$a2
/*  f143dd4:	309803ff */ 	andi	$t8,$a0,0x3ff
/*  f143dd8:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f143ddc:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f143de0:	468040a0 */ 	cvt.s.w	$f2,$f8
/*  f143de4:	8faa0300 */ 	lw	$t2,0x300($sp)
/*  f143de8:	03217025 */ 	or	$t6,$t9,$at
/*  f143dec:	01c57825 */ 	or	$t7,$t6,$a1
/*  f143df0:	afbf008c */ 	sw	$ra,0x8c($sp)
/*  f143df4:	01c02025 */ 	or	$a0,$t6,$zero
/*  f143df8:	27eeffe1 */ 	addiu	$t6,$ra,-31
/*  f143dfc:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f143e00:	2548002b */ 	addiu	$t0,$t2,0x2b
/*  f143e04:	311803ff */ 	andi	$t8,$t0,0x3ff
/*  f143e08:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f143e0c:	00184080 */ 	sll	$t0,$t8,0x2
/*  f143e10:	46001281 */ 	sub.s	$f10,$f2,$f0
/*  f143e14:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f143e18:	254e001a */ 	addiu	$t6,$t2,0x1a
/*  f143e1c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f143e20:	0308c825 */ 	or	$t9,$t8,$t0
/*  f143e24:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f143e28:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f143e2c:	444ef800 */ 	cfc1	$t6,$31
/*  f143e30:	44cff800 */ 	ctc1	$t7,$31
/*  f143e34:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f143e38:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f143e3c:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f143e40:	02a01825 */ 	or	$v1,$s5,$zero
/*  f143e44:	01b8c825 */ 	or	$t9,$t5,$t8
/*  f143e48:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f143e4c:	444ff800 */ 	cfc1	$t7,$31
/*  f143e50:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f143e54:	3c014f00 */ 	lui	$at,0x4f00
/*  f143e58:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f143e5c:	51e00013 */ 	beqzl	$t7,.L0f143eac
/*  f143e60:	440f2000 */ 	mfc1	$t7,$f4
/*  f143e64:	44812000 */ 	mtc1	$at,$f4
/*  f143e68:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f143e6c:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f143e70:	44cff800 */ 	ctc1	$t7,$31
/*  f143e74:	00000000 */ 	nop
/*  f143e78:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f143e7c:	444ff800 */ 	cfc1	$t7,$31
/*  f143e80:	00000000 */ 	nop
/*  f143e84:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f143e88:	15e00005 */ 	bnez	$t7,.L0f143ea0
/*  f143e8c:	00000000 */ 	nop
/*  f143e90:	440f2000 */ 	mfc1	$t7,$f4
/*  f143e94:	3c018000 */ 	lui	$at,0x8000
/*  f143e98:	10000007 */ 	b	.L0f143eb8
/*  f143e9c:	01e17825 */ 	or	$t7,$t7,$at
.L0f143ea0:
/*  f143ea0:	10000005 */ 	b	.L0f143eb8
/*  f143ea4:	240fffff */ 	addiu	$t7,$zero,-1
/*  f143ea8:	440f2000 */ 	mfc1	$t7,$f4
.L0f143eac:
/*  f143eac:	00000000 */ 	nop
/*  f143eb0:	05e0fffb */ 	bltz	$t7,.L0f143ea0
/*  f143eb4:	00000000 */ 	nop
.L0f143eb8:
/*  f143eb8:	44cef800 */ 	ctc1	$t6,$31
/*  f143ebc:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f143ec0:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f143ec4:	460c1181 */ 	sub.s	$f6,$f2,$f12
/*  f143ec8:	254f002c */ 	addiu	$t7,$t2,0x2c
/*  f143ecc:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f143ed0:	03267025 */ 	or	$t6,$t9,$a2
/*  f143ed4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f143ed8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f143edc:	444ff800 */ 	cfc1	$t7,$31
/*  f143ee0:	44d8f800 */ 	ctc1	$t8,$31
/*  f143ee4:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f143ee8:	00997025 */ 	or	$t6,$a0,$t9
/*  f143eec:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f143ef0:	02a04825 */ 	or	$t1,$s5,$zero
/*  f143ef4:	ad2e0000 */ 	sw	$t6,0x0($t1)
/*  f143ef8:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f143efc:	4458f800 */ 	cfc1	$t8,$31
/*  f143f00:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f143f04:	3c014f00 */ 	lui	$at,0x4f00
/*  f143f08:	33180078 */ 	andi	$t8,$t8,0x78
/*  f143f0c:	53000013 */ 	beqzl	$t8,.L0f143f5c
/*  f143f10:	44184000 */ 	mfc1	$t8,$f8
/*  f143f14:	44814000 */ 	mtc1	$at,$f8
/*  f143f18:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f143f1c:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f143f20:	44d8f800 */ 	ctc1	$t8,$31
/*  f143f24:	00000000 */ 	nop
/*  f143f28:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f143f2c:	4458f800 */ 	cfc1	$t8,$31
/*  f143f30:	00000000 */ 	nop
/*  f143f34:	33180078 */ 	andi	$t8,$t8,0x78
/*  f143f38:	17000005 */ 	bnez	$t8,.L0f143f50
/*  f143f3c:	00000000 */ 	nop
/*  f143f40:	44184000 */ 	mfc1	$t8,$f8
/*  f143f44:	3c018000 */ 	lui	$at,0x8000
/*  f143f48:	10000007 */ 	b	.L0f143f68
/*  f143f4c:	0301c025 */ 	or	$t8,$t8,$at
.L0f143f50:
/*  f143f50:	10000005 */ 	b	.L0f143f68
/*  f143f54:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f143f58:	44184000 */ 	mfc1	$t8,$f8
.L0f143f5c:
/*  f143f5c:	00000000 */ 	nop
/*  f143f60:	0700fffb */ 	bltz	$t8,.L0f143f50
/*  f143f64:	00000000 */ 	nop
.L0f143f68:
/*  f143f68:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f143f6c:	44cff800 */ 	ctc1	$t7,$31
/*  f143f70:	00197380 */ 	sll	$t6,$t9,0xe
/*  f143f74:	01c87825 */ 	or	$t7,$t6,$t0
/*  f143f78:	ad2f0004 */ 	sw	$t7,0x4($t1)
/*  f143f7c:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f143f80:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f143f84:	02a01025 */ 	or	$v0,$s5,$zero
/*  f143f88:	44985000 */ 	mtc1	$t8,$f10
/*  f143f8c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f143f90:	3c014f00 */ 	lui	$at,0x4f00
/*  f143f94:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f143f98:	46002180 */ 	add.s	$f6,$f4,$f0
/*  f143f9c:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f143fa0:	4459f800 */ 	cfc1	$t9,$31
/*  f143fa4:	44cef800 */ 	ctc1	$t6,$31
/*  f143fa8:	00000000 */ 	nop
/*  f143fac:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f143fb0:	444ef800 */ 	cfc1	$t6,$31
/*  f143fb4:	00000000 */ 	nop
/*  f143fb8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f143fbc:	51c00013 */ 	beqzl	$t6,.L0f14400c
/*  f143fc0:	440e5000 */ 	mfc1	$t6,$f10
/*  f143fc4:	44815000 */ 	mtc1	$at,$f10
/*  f143fc8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f143fcc:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f143fd0:	44cef800 */ 	ctc1	$t6,$31
/*  f143fd4:	00000000 */ 	nop
/*  f143fd8:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f143fdc:	444ef800 */ 	cfc1	$t6,$31
/*  f143fe0:	00000000 */ 	nop
/*  f143fe4:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f143fe8:	15c00005 */ 	bnez	$t6,.L0f144000
/*  f143fec:	00000000 */ 	nop
/*  f143ff0:	440e5000 */ 	mfc1	$t6,$f10
/*  f143ff4:	3c018000 */ 	lui	$at,0x8000
/*  f143ff8:	10000007 */ 	b	.L0f144018
/*  f143ffc:	01c17025 */ 	or	$t6,$t6,$at
.L0f144000:
/*  f144000:	10000005 */ 	b	.L0f144018
/*  f144004:	240effff */ 	addiu	$t6,$zero,-1
/*  f144008:	440e5000 */ 	mfc1	$t6,$f10
.L0f14400c:
/*  f14400c:	00000000 */ 	nop
/*  f144010:	05c0fffb */ 	bltz	$t6,.L0f144000
/*  f144014:	00000000 */ 	nop
.L0f144018:
/*  f144018:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f14401c:	8fae0300 */ 	lw	$t6,0x300($sp)
/*  f144020:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f144024:	44d9f800 */ 	ctc1	$t9,$31
/*  f144028:	3c01f600 */ 	lui	$at,0xf600
/*  f14402c:	0301c825 */ 	or	$t9,$t8,$at
/*  f144030:	25cf0038 */ 	addiu	$t7,$t6,0x38
/*  f144034:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f144038:	44842000 */ 	mtc1	$a0,$f4
/*  f14403c:	00187080 */ 	sll	$t6,$t8,0x2
/*  f144040:	032e7825 */ 	or	$t7,$t9,$t6
/*  f144044:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f144048:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f14404c:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f144050:	02a01825 */ 	or	$v1,$s5,$zero
/*  f144054:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f144058:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f14405c:	00197380 */ 	sll	$t6,$t9,0xe
/*  f144060:	24980001 */ 	addiu	$t8,$a0,0x1
/*  f144064:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f144068:	01c77825 */ 	or	$t7,$t6,$a3
/*  f14406c:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f144070:	00197380 */ 	sll	$t6,$t9,0xe
/*  f144074:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f144078:	01c17825 */ 	or	$t7,$t6,$at
/*  f14407c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f144080:	4459f800 */ 	cfc1	$t9,$31
/*  f144084:	44cef800 */ 	ctc1	$t6,$31
/*  f144088:	01e5c025 */ 	or	$t8,$t7,$a1
/*  f14408c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f144090:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f144094:	3c014f00 */ 	lui	$at,0x4f00
/*  f144098:	444ef800 */ 	cfc1	$t6,$31
/*  f14409c:	00000000 */ 	nop
/*  f1440a0:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f1440a4:	51c00013 */ 	beqzl	$t6,.L0f1440f4
/*  f1440a8:	440e5000 */ 	mfc1	$t6,$f10
/*  f1440ac:	44815000 */ 	mtc1	$at,$f10
/*  f1440b0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f1440b4:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f1440b8:	44cef800 */ 	ctc1	$t6,$31
/*  f1440bc:	00000000 */ 	nop
/*  f1440c0:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f1440c4:	444ef800 */ 	cfc1	$t6,$31
/*  f1440c8:	00000000 */ 	nop
/*  f1440cc:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f1440d0:	15c00005 */ 	bnez	$t6,.L0f1440e8
/*  f1440d4:	00000000 */ 	nop
/*  f1440d8:	440e5000 */ 	mfc1	$t6,$f10
/*  f1440dc:	3c018000 */ 	lui	$at,0x8000
/*  f1440e0:	10000007 */ 	b	.L0f144100
/*  f1440e4:	01c17025 */ 	or	$t6,$t6,$at
.L0f1440e8:
/*  f1440e8:	10000005 */ 	b	.L0f144100
/*  f1440ec:	240effff */ 	addiu	$t6,$zero,-1
/*  f1440f0:	440e5000 */ 	mfc1	$t6,$f10
.L0f1440f4:
/*  f1440f4:	00000000 */ 	nop
/*  f1440f8:	05c0fffb */ 	bltz	$t6,.L0f1440e8
/*  f1440fc:	00000000 */ 	nop
.L0f144100:
/*  f144100:	44d9f800 */ 	ctc1	$t9,$31
/*  f144104:	8fb902f0 */ 	lw	$t9,0x2f0($sp)
/*  f144108:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f14410c:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f144110:	272effc9 */ 	addiu	$t6,$t9,-55
/*  f144114:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f144118:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f14411c:	03197025 */ 	or	$t6,$t8,$t9
/*  f144120:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f144124:	44912000 */ 	mtc1	$s1,$f4
.L0f144128:
/*  f144128:	3c0140a0 */ 	lui	$at,0x40a0
/*  f14412c:	44815000 */ 	mtc1	$at,$f10
/*  f144130:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f144134:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f144138:	8fb90304 */ 	lw	$t9,0x304($sp)
/*  f14413c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f144140:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f144144:	03317021 */ 	addu	$t6,$t9,$s1
/*  f144148:	460a0103 */ 	div.s	$f4,$f0,$f10
/*  f14414c:	25cfffff */ 	addiu	$t7,$t6,-1
/*  f144150:	448f3000 */ 	mtc1	$t7,$f6
/*  f144154:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f144158:	afaf008c */ 	sw	$t7,0x8c($sp)
/*  f14415c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f144160:	46044181 */ 	sub.s	$f6,$f8,$f4
/*  f144164:	1461006c */ 	bne	$v1,$at,.L0f144318
/*  f144168:	e7a60068 */ 	swc1	$f6,0x68($sp)
/*  f14416c:	0011c043 */ 	sra	$t8,$s1,0x1
/*  f144170:	8fae02f8 */ 	lw	$t6,0x2f8($sp)
/*  f144174:	03191021 */ 	addu	$v0,$t8,$t9
/*  f144178:	8fb80300 */ 	lw	$t8,0x300($sp)
/*  f14417c:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f144180:	3c0cf600 */ 	lui	$t4,0xf600
/*  f144184:	01f82021 */ 	addu	$a0,$t7,$t8
/*  f144188:	24830001 */ 	addiu	$v1,$a0,0x1
/*  f14418c:	307903ff */ 	andi	$t9,$v1,0x3ff
/*  f144190:	244f0007 */ 	addiu	$t7,$v0,0x7
/*  f144194:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f144198:	00191880 */ 	sll	$v1,$t9,0x2
/*  f14419c:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f1441a0:	032c7025 */ 	or	$t6,$t9,$t4
/*  f1441a4:	01c37825 */ 	or	$t7,$t6,$v1
/*  f1441a8:	24590002 */ 	addiu	$t9,$v0,0x2
/*  f1441ac:	308503ff */ 	andi	$a1,$a0,0x3ff
/*  f1441b0:	02a03025 */ 	or	$a2,$s5,$zero
/*  f1441b4:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f1441b8:	0005c080 */ 	sll	$t8,$a1,0x2
/*  f1441bc:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1441c0:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1441c4:	01f83825 */ 	or	$a3,$t7,$t8
/*  f1441c8:	03002825 */ 	or	$a1,$t8,$zero
/*  f1441cc:	24580005 */ 	addiu	$t8,$v0,0x5
/*  f1441d0:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f1441d4:	00197380 */ 	sll	$t6,$t9,0xe
/*  f1441d8:	01cc7825 */ 	or	$t7,$t6,$t4
/*  f1441dc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1441e0:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f1441e4:	2459ffff */ 	addiu	$t9,$v0,-1
/*  f1441e8:	acc70004 */ 	sw	$a3,0x4($a2)
/*  f1441ec:	02a04025 */ 	or	$t0,$s5,$zero
/*  f1441f0:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1441f4:	ad180000 */ 	sw	$t8,0x0($t0)
/*  f1441f8:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1441fc:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f144200:	2459fffa */ 	addiu	$t9,$v0,-6
/*  f144204:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f144208:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14420c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f144210:	03035025 */ 	or	$t2,$t8,$v1
/*  f144214:	01e5c025 */ 	or	$t8,$t7,$a1
/*  f144218:	02a04825 */ 	or	$t1,$s5,$zero
/*  f14421c:	2459fffc */ 	addiu	$t9,$v0,-4
/*  f144220:	ad070004 */ 	sw	$a3,0x4($t0)
/*  f144224:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f144228:	ad380004 */ 	sw	$t8,0x4($t1)
/*  f14422c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f144230:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f144234:	24430001 */ 	addiu	$v1,$v0,0x1
/*  f144238:	ad2a0000 */ 	sw	$t2,0x0($t1)
/*  f14423c:	01e5c025 */ 	or	$t8,$t7,$a1
/*  f144240:	02a05825 */ 	or	$t3,$s5,$zero
/*  f144244:	307903ff */ 	andi	$t9,$v1,0x3ff
/*  f144248:	ad780004 */ 	sw	$t8,0x4($t3)
/*  f14424c:	00197380 */ 	sll	$t6,$t9,0xe
/*  f144250:	24980007 */ 	addiu	$t8,$a0,0x7
/*  f144254:	3c01f600 */ 	lui	$at,0xf600
/*  f144258:	01c11825 */ 	or	$v1,$t6,$at
/*  f14425c:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f144260:	00197080 */ 	sll	$t6,$t9,0x2
/*  f144264:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f144268:	006e7825 */ 	or	$t7,$v1,$t6
/*  f14426c:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*  f144270:	02a02825 */ 	or	$a1,$s5,$zero
/*  f144274:	24990002 */ 	addiu	$t9,$a0,0x2
/*  f144278:	304803ff */ 	andi	$t0,$v0,0x3ff
/*  f14427c:	0008c380 */ 	sll	$t8,$t0,0xe
/*  f144280:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f144284:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f144288:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f14428c:	030f3825 */ 	or	$a3,$t8,$t7
/*  f144290:	03004025 */ 	or	$t0,$t8,$zero
/*  f144294:	24980005 */ 	addiu	$t8,$a0,0x5
/*  f144298:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f14429c:	00197080 */ 	sll	$t6,$t9,0x2
/*  f1442a0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1442a4:	006e7825 */ 	or	$t7,$v1,$t6
/*  f1442a8:	aca70004 */ 	sw	$a3,0x4($a1)
/*  f1442ac:	02a03025 */ 	or	$a2,$s5,$zero
/*  f1442b0:	2498ffff */ 	addiu	$t8,$a0,-1
/*  f1442b4:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f1442b8:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f1442bc:	00197080 */ 	sll	$t6,$t9,0x2
/*  f1442c0:	248ffffa */ 	addiu	$t7,$a0,-6
/*  f1442c4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1442c8:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1442cc:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1442d0:	02a04825 */ 	or	$t1,$s5,$zero
/*  f1442d4:	006e5025 */ 	or	$t2,$v1,$t6
/*  f1442d8:	acc70004 */ 	sw	$a3,0x4($a2)
/*  f1442dc:	01197025 */ 	or	$t6,$t0,$t9
/*  f1442e0:	248ffffc */ 	addiu	$t7,$a0,-4
/*  f1442e4:	ad2e0004 */ 	sw	$t6,0x4($t1)
/*  f1442e8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1442ec:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1442f0:	ad2a0000 */ 	sw	$t2,0x0($t1)
/*  f1442f4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1442f8:	02a01025 */ 	or	$v0,$s5,$zero
/*  f1442fc:	01197025 */ 	or	$t6,$t0,$t9
/*  f144300:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f144304:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f144308:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f14430c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f144310:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f144314:	9303006b */ 	lbu	$v1,0x6b($t8)
.L0f144318:
/*  f144318:	1460000a */ 	bnez	$v1,.L0f144344
/*  f14431c:	24045849 */ 	addiu	$a0,$zero,0x5849
/*  f144320:	3c190050 */ 	lui	$t9,0x50
/*  f144324:	3c0e000f */ 	lui	$t6,0xf
/*  f144328:	3c1400ff */ 	lui	$s4,0xff
/*  f14432c:	373900ff */ 	ori	$t9,$t9,0xff
/*  f144330:	35ce00ff */ 	ori	$t6,$t6,0xff
/*  f144334:	369400a0 */ 	ori	$s4,$s4,0xa0
/*  f144338:	afb902b4 */ 	sw	$t9,0x2b4($sp)
/*  f14433c:	1000000f */ 	b	.L0f14437c
/*  f144340:	afae02b0 */ 	sw	$t6,0x2b0($sp)
.L0f144344:
/*  f144344:	24010001 */ 	addiu	$at,$zero,0x1
/*  f144348:	14610007 */ 	bne	$v1,$at,.L0f144368
/*  f14434c:	3c02ff33 */ 	lui	$v0,0xff33
/*  f144350:	3c022244 */ 	lui	$v0,0x2244
/*  f144354:	3454ffff */ 	ori	$s4,$v0,0xffff
/*  f144358:	240f0fff */ 	addiu	$t7,$zero,0xfff
/*  f14435c:	afb402b4 */ 	sw	$s4,0x2b4($sp)
/*  f144360:	10000006 */ 	b	.L0f14437c
/*  f144364:	afaf02b0 */ 	sw	$t7,0x2b0($sp)
.L0f144368:
/*  f144368:	3c180f00 */ 	lui	$t8,0xf00
/*  f14436c:	345400ff */ 	ori	$s4,$v0,0xff
/*  f144370:	371800ff */ 	ori	$t8,$t8,0xff
/*  f144374:	afb402b4 */ 	sw	$s4,0x2b4($sp)
/*  f144378:	afb802b0 */ 	sw	$t8,0x2b0($sp)
.L0f14437c:
/*  f14437c:	0fc5b9f1 */ 	jal	langGet
/*  f144380:	e7a00074 */ 	swc1	$f0,0x74($sp)
/*  f144384:	3c017f1b */ 	lui	$at,%hi(var7f1b5f50)
/*  f144388:	c4285f50 */ 	lwc1	$f8,%lo(var7f1b5f50)($at)
/*  f14438c:	c7aa02c0 */ 	lwc1	$f10,0x2c0($sp)
/*  f144390:	27b30308 */ 	addiu	$s3,$sp,0x308
/*  f144394:	3c057f1b */ 	lui	$a1,%hi(var7f1b5de4)
/*  f144398:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f14439c:	3c077f1b */ 	lui	$a3,%hi(var7f1b5df0)
/*  f1443a0:	24e75df0 */ 	addiu	$a3,$a3,%lo(var7f1b5df0)
/*  f1443a4:	24a55de4 */ 	addiu	$a1,$a1,%lo(var7f1b5de4)
/*  f1443a8:	02602025 */ 	or	$a0,$s3,$zero
/*  f1443ac:	00403025 */ 	or	$a2,$v0,$zero
/*  f1443b0:	460021a1 */ 	cvt.d.s	$f6,$f4
/*  f1443b4:	0c004dad */ 	jal	sprintf
/*  f1443b8:	f7a60010 */ 	sdc1	$f6,0x10($sp)
/*  f1443bc:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicXs)
/*  f1443c0:	8f39fb04 */ 	lw	$t9,%lo(g_FontHandelGothicXs)($t9)
/*  f1443c4:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicXs)
/*  f1443c8:	8ce7fb08 */ 	lw	$a3,%lo(g_CharsHandelGothicXs)($a3)
/*  f1443cc:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f1443d0:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f1443d4:	02603025 */ 	or	$a2,$s3,$zero
/*  f1443d8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1443dc:	0fc55cbe */ 	jal	textMeasure
/*  f1443e0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f1443e4:	8fa902ac */ 	lw	$t1,0x2ac($sp)
/*  f1443e8:	8faf0304 */ 	lw	$t7,0x304($sp)
/*  f1443ec:	8fb20300 */ 	lw	$s2,0x300($sp)
/*  f1443f0:	00097080 */ 	sll	$t6,$t1,0x2
/*  f1443f4:	01c97023 */ 	subu	$t6,$t6,$t1
/*  f1443f8:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f1443fc:	01c97021 */ 	addu	$t6,$t6,$t1
/*  f144400:	8fb802e4 */ 	lw	$t8,0x2e4($sp)
/*  f144404:	01c04825 */ 	or	$t1,$t6,$zero
/*  f144408:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f14440c:	8fae02e0 */ 	lw	$t6,0x2e0($sp)
/*  f144410:	2652000e */ 	addiu	$s2,$s2,0xe
/*  f144414:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f144418:	27b802d8 */ 	addiu	$t8,$sp,0x2d8
/*  f14441c:	024e7821 */ 	addu	$t7,$s2,$t6
/*  f144420:	afaf02d8 */ 	sw	$t7,0x2d8($sp)
/*  f144424:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f144428:	afb902dc */ 	sw	$t9,0x2dc($sp)
/*  f14442c:	afb202e8 */ 	sw	$s2,0x2e8($sp)
/*  f144430:	afa20084 */ 	sw	$v0,0x84($sp)
/*  f144434:	afa202ec */ 	sw	$v0,0x2ec($sp)
/*  f144438:	afa90080 */ 	sw	$t1,0x80($sp)
/*  f14443c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144440:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144444:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144448:	0fc54e16 */ 	jal	func0f153858
/*  f14444c:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f144450:	0c002f02 */ 	jal	viGetWidth
/*  f144454:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144458:	00028400 */ 	sll	$s0,$v0,0x10
/*  f14445c:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f144460:	0c002f06 */ 	jal	viGetHeight
/*  f144464:	03208025 */ 	or	$s0,$t9,$zero
/*  f144468:	3c0e8008 */ 	lui	$t6,%hi(g_CharsHandelGothicXs)
/*  f14446c:	3c0f8008 */ 	lui	$t7,%hi(g_FontHandelGothicXs)
/*  f144470:	8deffb04 */ 	lw	$t7,%lo(g_FontHandelGothicXs)($t7)
/*  f144474:	8dcefb08 */ 	lw	$t6,%lo(g_CharsHandelGothicXs)($t6)
/*  f144478:	8fb802b0 */ 	lw	$t8,0x2b0($sp)
/*  f14447c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144480:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144484:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144488:	02603825 */ 	or	$a3,$s3,$zero
/*  f14448c:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f144490:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f144494:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f144498:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f14449c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1444a0:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f1444a4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1444a8:	0fc55b92 */ 	jal	textRender
/*  f1444ac:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f1444b0:	0040a825 */ 	or	$s5,$v0,$zero
/*  f1444b4:	0fc5b9f1 */ 	jal	langGet
/*  f1444b8:	2404584a */ 	addiu	$a0,$zero,0x584a
/*  f1444bc:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f1444c0:	3c017f1b */ 	lui	$at,%hi(var7f1b5f54)
/*  f1444c4:	c4285f54 */ 	lwc1	$f8,%lo(var7f1b5f54)($at)
/*  f1444c8:	8f2e0480 */ 	lw	$t6,0x480($t9)
/*  f1444cc:	3c057f1b */ 	lui	$a1,%hi(var7f1b5df4)
/*  f1444d0:	3c077f1b */ 	lui	$a3,%hi(var7f1b5e00)
/*  f1444d4:	c5ca0060 */ 	lwc1	$f10,0x60($t6)
/*  f1444d8:	24e75e00 */ 	addiu	$a3,$a3,%lo(var7f1b5e00)
/*  f1444dc:	24a55df4 */ 	addiu	$a1,$a1,%lo(var7f1b5df4)
/*  f1444e0:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f1444e4:	02602025 */ 	or	$a0,$s3,$zero
/*  f1444e8:	00403025 */ 	or	$a2,$v0,$zero
/*  f1444ec:	460021a1 */ 	cvt.d.s	$f6,$f4
/*  f1444f0:	0c004dad */ 	jal	sprintf
/*  f1444f4:	f7a60010 */ 	sdc1	$f6,0x10($sp)
/*  f1444f8:	3c0f8008 */ 	lui	$t7,%hi(g_FontHandelGothicXs)
/*  f1444fc:	8deffb04 */ 	lw	$t7,%lo(g_FontHandelGothicXs)($t7)
/*  f144500:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicXs)
/*  f144504:	26510009 */ 	addiu	$s1,$s2,0x9
/*  f144508:	8ce7fb08 */ 	lw	$a3,%lo(g_CharsHandelGothicXs)($a3)
/*  f14450c:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f144510:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f144514:	02603025 */ 	or	$a2,$s3,$zero
/*  f144518:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f14451c:	0fc55cbe */ 	jal	textMeasure
/*  f144520:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f144524:	8fa30084 */ 	lw	$v1,0x84($sp)
/*  f144528:	8fb802e4 */ 	lw	$t8,0x2e4($sp)
/*  f14452c:	8fae02e0 */ 	lw	$t6,0x2e0($sp)
/*  f144530:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144534:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f144538:	27b802d8 */ 	addiu	$t8,$sp,0x2d8
/*  f14453c:	022e7821 */ 	addu	$t7,$s1,$t6
/*  f144540:	afaf02d8 */ 	sw	$t7,0x2d8($sp)
/*  f144544:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f144548:	afb902dc */ 	sw	$t9,0x2dc($sp)
/*  f14454c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144550:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144554:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f144558:	afb102e8 */ 	sw	$s1,0x2e8($sp)
/*  f14455c:	0fc54e16 */ 	jal	func0f153858
/*  f144560:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f144564:	0c002f02 */ 	jal	viGetWidth
/*  f144568:	0040a825 */ 	or	$s5,$v0,$zero
/*  f14456c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144570:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f144574:	0c002f06 */ 	jal	viGetHeight
/*  f144578:	03208025 */ 	or	$s0,$t9,$zero
/*  f14457c:	3c0e8008 */ 	lui	$t6,%hi(g_CharsHandelGothicXs)
/*  f144580:	3c0f8008 */ 	lui	$t7,%hi(g_FontHandelGothicXs)
/*  f144584:	8deffb04 */ 	lw	$t7,%lo(g_FontHandelGothicXs)($t7)
/*  f144588:	8dcefb08 */ 	lw	$t6,%lo(g_CharsHandelGothicXs)($t6)
/*  f14458c:	8fb802b0 */ 	lw	$t8,0x2b0($sp)
/*  f144590:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144594:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144598:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f14459c:	02603825 */ 	or	$a3,$s3,$zero
/*  f1445a0:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f1445a4:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1445a8:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1445ac:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1445b0:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1445b4:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f1445b8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1445bc:	0fc55b92 */ 	jal	textRender
/*  f1445c0:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f1445c4:	0040a825 */ 	or	$s5,$v0,$zero
/*  f1445c8:	0fc5b9f1 */ 	jal	langGet
/*  f1445cc:	2404584b */ 	addiu	$a0,$zero,0x584b
/*  f1445d0:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f1445d4:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e04)
/*  f1445d8:	24a55e04 */ 	addiu	$a1,$a1,%lo(var7f1b5e04)
/*  f1445dc:	8f2e0480 */ 	lw	$t6,0x480($t9)
/*  f1445e0:	02602025 */ 	or	$a0,$s3,$zero
/*  f1445e4:	00403025 */ 	or	$a2,$v0,$zero
/*  f1445e8:	c5ca001c */ 	lwc1	$f10,0x1c($t6)
/*  f1445ec:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f1445f0:	44074000 */ 	mfc1	$a3,$f8
/*  f1445f4:	0c004dad */ 	jal	sprintf
/*  f1445f8:	00000000 */ 	nop
/*  f1445fc:	3c188008 */ 	lui	$t8,%hi(g_FontHandelGothicXs)
/*  f144600:	8f18fb04 */ 	lw	$t8,%lo(g_FontHandelGothicXs)($t8)
/*  f144604:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicXs)
/*  f144608:	26310009 */ 	addiu	$s1,$s1,0x9
/*  f14460c:	8ce7fb08 */ 	lw	$a3,%lo(g_CharsHandelGothicXs)($a3)
/*  f144610:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f144614:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f144618:	02603025 */ 	or	$a2,$s3,$zero
/*  f14461c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f144620:	0fc55cbe */ 	jal	textMeasure
/*  f144624:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f144628:	8fa30084 */ 	lw	$v1,0x84($sp)
/*  f14462c:	8fb902e4 */ 	lw	$t9,0x2e4($sp)
/*  f144630:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f144634:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144638:	00797021 */ 	addu	$t6,$v1,$t9
/*  f14463c:	27b902d8 */ 	addiu	$t9,$sp,0x2d8
/*  f144640:	022fc021 */ 	addu	$t8,$s1,$t7
/*  f144644:	afb802d8 */ 	sw	$t8,0x2d8($sp)
/*  f144648:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f14464c:	afae02dc */ 	sw	$t6,0x2dc($sp)
/*  f144650:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144654:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144658:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f14465c:	afb102e8 */ 	sw	$s1,0x2e8($sp)
/*  f144660:	0fc54e16 */ 	jal	func0f153858
/*  f144664:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f144668:	0c002f02 */ 	jal	viGetWidth
/*  f14466c:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144670:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144674:	00107403 */ 	sra	$t6,$s0,0x10
/*  f144678:	0c002f06 */ 	jal	viGetHeight
/*  f14467c:	01c08025 */ 	or	$s0,$t6,$zero
/*  f144680:	3c0f8008 */ 	lui	$t7,%hi(g_CharsHandelGothicXs)
/*  f144684:	3c188008 */ 	lui	$t8,%hi(g_FontHandelGothicXs)
/*  f144688:	8f18fb04 */ 	lw	$t8,%lo(g_FontHandelGothicXs)($t8)
/*  f14468c:	8deffb08 */ 	lw	$t7,%lo(g_CharsHandelGothicXs)($t7)
/*  f144690:	8fb902b0 */ 	lw	$t9,0x2b0($sp)
/*  f144694:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144698:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f14469c:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f1446a0:	02603825 */ 	or	$a3,$s3,$zero
/*  f1446a4:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f1446a8:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1446ac:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1446b0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1446b4:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1446b8:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1446bc:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1446c0:	0fc55b92 */ 	jal	textRender
/*  f1446c4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f1446c8:	0040a825 */ 	or	$s5,$v0,$zero
/*  f1446cc:	0fc5b9f1 */ 	jal	langGet
/*  f1446d0:	2404584c */ 	addiu	$a0,$zero,0x584c
/*  f1446d4:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f1446d8:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e0c)
/*  f1446dc:	24a55e0c */ 	addiu	$a1,$a1,%lo(var7f1b5e0c)
/*  f1446e0:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f1446e4:	02602025 */ 	or	$a0,$s3,$zero
/*  f1446e8:	00403025 */ 	or	$a2,$v0,$zero
/*  f1446ec:	c5e40028 */ 	lwc1	$f4,0x28($t7)
/*  f1446f0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f1446f4:	44073000 */ 	mfc1	$a3,$f6
/*  f1446f8:	0c004dad */ 	jal	sprintf
/*  f1446fc:	00000000 */ 	nop
/*  f144700:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicXs)
/*  f144704:	8f39fb04 */ 	lw	$t9,%lo(g_FontHandelGothicXs)($t9)
/*  f144708:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicXs)
/*  f14470c:	26310009 */ 	addiu	$s1,$s1,0x9
/*  f144710:	8ce7fb08 */ 	lw	$a3,%lo(g_CharsHandelGothicXs)($a3)
/*  f144714:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f144718:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f14471c:	02603025 */ 	or	$a2,$s3,$zero
/*  f144720:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f144724:	0fc55cbe */ 	jal	textMeasure
/*  f144728:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f14472c:	8fa30084 */ 	lw	$v1,0x84($sp)
/*  f144730:	8fae02e4 */ 	lw	$t6,0x2e4($sp)
/*  f144734:	8fb802e0 */ 	lw	$t8,0x2e0($sp)
/*  f144738:	02a02025 */ 	or	$a0,$s5,$zero
/*  f14473c:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f144740:	27ae02d8 */ 	addiu	$t6,$sp,0x2d8
/*  f144744:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f144748:	afb902d8 */ 	sw	$t9,0x2d8($sp)
/*  f14474c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f144750:	afaf02dc */ 	sw	$t7,0x2dc($sp)
/*  f144754:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144758:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f14475c:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f144760:	afb102e8 */ 	sw	$s1,0x2e8($sp)
/*  f144764:	0fc54e16 */ 	jal	func0f153858
/*  f144768:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f14476c:	0c002f02 */ 	jal	viGetWidth
/*  f144770:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144774:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144778:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f14477c:	0c002f06 */ 	jal	viGetHeight
/*  f144780:	01e08025 */ 	or	$s0,$t7,$zero
/*  f144784:	3c188008 */ 	lui	$t8,%hi(g_CharsHandelGothicXs)
/*  f144788:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicXs)
/*  f14478c:	8f39fb04 */ 	lw	$t9,%lo(g_FontHandelGothicXs)($t9)
/*  f144790:	8f18fb08 */ 	lw	$t8,%lo(g_CharsHandelGothicXs)($t8)
/*  f144794:	8fae02b0 */ 	lw	$t6,0x2b0($sp)
/*  f144798:	02a02025 */ 	or	$a0,$s5,$zero
/*  f14479c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f1447a0:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f1447a4:	02603825 */ 	or	$a3,$s3,$zero
/*  f1447a8:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f1447ac:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1447b0:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1447b4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1447b8:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1447bc:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1447c0:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1447c4:	0fc55b92 */ 	jal	textRender
/*  f1447c8:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f1447cc:	0040a825 */ 	or	$s5,$v0,$zero
/*  f1447d0:	0fc5b9f1 */ 	jal	langGet
/*  f1447d4:	2404584d */ 	addiu	$a0,$zero,0x584d
/*  f1447d8:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e14)
/*  f1447dc:	24a55e14 */ 	addiu	$a1,$a1,%lo(var7f1b5e14)
/*  f1447e0:	02602025 */ 	or	$a0,$s3,$zero
/*  f1447e4:	0c004dad */ 	jal	sprintf
/*  f1447e8:	00403025 */ 	or	$a2,$v0,$zero
/*  f1447ec:	3c0f8008 */ 	lui	$t7,%hi(g_FontHandelGothicXs)
/*  f1447f0:	8deffb04 */ 	lw	$t7,%lo(g_FontHandelGothicXs)($t7)
/*  f1447f4:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicXs)
/*  f1447f8:	8ce7fb08 */ 	lw	$a3,%lo(g_CharsHandelGothicXs)($a3)
/*  f1447fc:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f144800:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f144804:	02603025 */ 	or	$a2,$s3,$zero
/*  f144808:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f14480c:	0fc55cbe */ 	jal	textMeasure
/*  f144810:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f144814:	8fa902a8 */ 	lw	$t1,0x2a8($sp)
/*  f144818:	8fb80304 */ 	lw	$t8,0x304($sp)
/*  f14481c:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f144820:	11200003 */ 	beqz	$t1,.L0f144830
/*  f144824:	8faf02f0 */ 	lw	$t7,0x2f0($sp)
/*  f144828:	10000002 */ 	b	.L0f144834
/*  f14482c:	2402fffd */ 	addiu	$v0,$zero,-3
.L0f144830:
/*  f144830:	00001025 */ 	or	$v0,$zero,$zero
.L0f144834:
/*  f144834:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f144838:	032e1821 */ 	addu	$v1,$t9,$t6
/*  f14483c:	11200003 */ 	beqz	$t1,.L0f14484c
/*  f144840:	24630005 */ 	addiu	$v1,$v1,0x5
/*  f144844:	10000002 */ 	b	.L0f144850
/*  f144848:	24020012 */ 	addiu	$v0,$zero,0x12
.L0f14484c:
/*  f14484c:	00001025 */ 	or	$v0,$zero,$zero
.L0f144850:
/*  f144850:	8fb802e4 */ 	lw	$t8,0x2e4($sp)
/*  f144854:	8fae02e0 */ 	lw	$t6,0x2e0($sp)
/*  f144858:	004f4021 */ 	addu	$t0,$v0,$t7
/*  f14485c:	2508ffd7 */ 	addiu	$t0,$t0,-41
/*  f144860:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f144864:	27b802d8 */ 	addiu	$t8,$sp,0x2d8
/*  f144868:	010e7821 */ 	addu	$t7,$t0,$t6
/*  f14486c:	afaf02d8 */ 	sw	$t7,0x2d8($sp)
/*  f144870:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f144874:	afb902dc */ 	sw	$t9,0x2dc($sp)
/*  f144878:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f14487c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144880:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144884:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144888:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f14488c:	0fc54e16 */ 	jal	func0f153858
/*  f144890:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f144894:	0c002f02 */ 	jal	viGetWidth
/*  f144898:	0040a825 */ 	or	$s5,$v0,$zero
/*  f14489c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1448a0:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f1448a4:	0c002f06 */ 	jal	viGetHeight
/*  f1448a8:	03208025 */ 	or	$s0,$t9,$zero
/*  f1448ac:	3c0e8008 */ 	lui	$t6,%hi(g_CharsHandelGothicXs)
/*  f1448b0:	3c0f8008 */ 	lui	$t7,%hi(g_FontHandelGothicXs)
/*  f1448b4:	8deffb04 */ 	lw	$t7,%lo(g_FontHandelGothicXs)($t7)
/*  f1448b8:	8dcefb08 */ 	lw	$t6,%lo(g_CharsHandelGothicXs)($t6)
/*  f1448bc:	8fb802b4 */ 	lw	$t8,0x2b4($sp)
/*  f1448c0:	8fb902b0 */ 	lw	$t9,0x2b0($sp)
/*  f1448c4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1448c8:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f1448cc:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f1448d0:	02603825 */ 	or	$a3,$s3,$zero
/*  f1448d4:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1448d8:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1448dc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f1448e0:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f1448e4:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f1448e8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1448ec:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f1448f0:	0fc55b92 */ 	jal	textRender
/*  f1448f4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f1448f8:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f1448fc:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144900:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f144904:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f144908:	5460000b */ 	bnezl	$v1,.L0f144938
/*  f14490c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f144910:	0fc5b9f1 */ 	jal	langGet
/*  f144914:	2404584e */ 	addiu	$a0,$zero,0x584e
/*  f144918:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e18)
/*  f14491c:	24a55e18 */ 	addiu	$a1,$a1,%lo(var7f1b5e18)
/*  f144920:	02602025 */ 	or	$a0,$s3,$zero
/*  f144924:	0c004dad */ 	jal	sprintf
/*  f144928:	00403025 */ 	or	$a2,$v0,$zero
/*  f14492c:	10000014 */ 	b	.L0f144980
/*  f144930:	00000000 */ 	nop
/*  f144934:	24010001 */ 	addiu	$at,$zero,0x1
.L0f144938:
/*  f144938:	1461000a */ 	bne	$v1,$at,.L0f144964
/*  f14493c:	00000000 */ 	nop
/*  f144940:	0fc5b9f1 */ 	jal	langGet
/*  f144944:	240458d0 */ 	addiu	$a0,$zero,0x58d0
/*  f144948:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e1c)
/*  f14494c:	24a55e1c */ 	addiu	$a1,$a1,%lo(var7f1b5e1c)
/*  f144950:	02602025 */ 	or	$a0,$s3,$zero
/*  f144954:	0c004dad */ 	jal	sprintf
/*  f144958:	00403025 */ 	or	$a2,$v0,$zero
/*  f14495c:	10000008 */ 	b	.L0f144980
/*  f144960:	00000000 */ 	nop
.L0f144964:
/*  f144964:	0fc5b9f1 */ 	jal	langGet
/*  f144968:	240458d9 */ 	addiu	$a0,$zero,0x58d9
/*  f14496c:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e20)
/*  f144970:	24a55e20 */ 	addiu	$a1,$a1,%lo(var7f1b5e20)
/*  f144974:	02602025 */ 	or	$a0,$s3,$zero
/*  f144978:	0c004dad */ 	jal	sprintf
/*  f14497c:	00403025 */ 	or	$a2,$v0,$zero
.L0f144980:
/*  f144980:	3c188008 */ 	lui	$t8,%hi(g_FontHandelGothicXs)
/*  f144984:	8f18fb04 */ 	lw	$t8,%lo(g_FontHandelGothicXs)($t8)
/*  f144988:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicXs)
/*  f14498c:	8ce7fb08 */ 	lw	$a3,%lo(g_CharsHandelGothicXs)($a3)
/*  f144990:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f144994:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f144998:	02603025 */ 	or	$a2,$s3,$zero
/*  f14499c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1449a0:	0fc55cbe */ 	jal	textMeasure
/*  f1449a4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1449a8:	8fa902a8 */ 	lw	$t1,0x2a8($sp)
/*  f1449ac:	8fb90304 */ 	lw	$t9,0x304($sp)
/*  f1449b0:	8faf0080 */ 	lw	$t7,0x80($sp)
/*  f1449b4:	11200003 */ 	beqz	$t1,.L0f1449c4
/*  f1449b8:	8fb802f0 */ 	lw	$t8,0x2f0($sp)
/*  f1449bc:	10000002 */ 	b	.L0f1449c8
/*  f1449c0:	2402fffd */ 	addiu	$v0,$zero,-3
.L0f1449c4:
/*  f1449c4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1449c8:
/*  f1449c8:	00597021 */ 	addu	$t6,$v0,$t9
/*  f1449cc:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f1449d0:	11200003 */ 	beqz	$t1,.L0f1449e0
/*  f1449d4:	24630005 */ 	addiu	$v1,$v1,0x5
/*  f1449d8:	10000002 */ 	b	.L0f1449e4
/*  f1449dc:	24020014 */ 	addiu	$v0,$zero,0x14
.L0f1449e0:
/*  f1449e0:	00001025 */ 	or	$v0,$zero,$zero
.L0f1449e4:
/*  f1449e4:	8fb902e4 */ 	lw	$t9,0x2e4($sp)
/*  f1449e8:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f1449ec:	00584021 */ 	addu	$t0,$v0,$t8
/*  f1449f0:	2508ffde */ 	addiu	$t0,$t0,-34
/*  f1449f4:	00797021 */ 	addu	$t6,$v1,$t9
/*  f1449f8:	27b902d8 */ 	addiu	$t9,$sp,0x2d8
/*  f1449fc:	010fc021 */ 	addu	$t8,$t0,$t7
/*  f144a00:	afb802d8 */ 	sw	$t8,0x2d8($sp)
/*  f144a04:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f144a08:	afae02dc */ 	sw	$t6,0x2dc($sp)
/*  f144a0c:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f144a10:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144a14:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144a18:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144a1c:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f144a20:	0fc54e16 */ 	jal	func0f153858
/*  f144a24:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f144a28:	0c002f02 */ 	jal	viGetWidth
/*  f144a2c:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144a30:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144a34:	00107403 */ 	sra	$t6,$s0,0x10
/*  f144a38:	0c002f06 */ 	jal	viGetHeight
/*  f144a3c:	01c08025 */ 	or	$s0,$t6,$zero
/*  f144a40:	3c0f8008 */ 	lui	$t7,%hi(g_CharsHandelGothicXs)
/*  f144a44:	3c188008 */ 	lui	$t8,%hi(g_FontHandelGothicXs)
/*  f144a48:	8f18fb04 */ 	lw	$t8,%lo(g_FontHandelGothicXs)($t8)
/*  f144a4c:	8deffb08 */ 	lw	$t7,%lo(g_CharsHandelGothicXs)($t7)
/*  f144a50:	8fb902b4 */ 	lw	$t9,0x2b4($sp)
/*  f144a54:	8fae02b0 */ 	lw	$t6,0x2b0($sp)
/*  f144a58:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144a5c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144a60:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144a64:	02603825 */ 	or	$a3,$s3,$zero
/*  f144a68:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f144a6c:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f144a70:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f144a74:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f144a78:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f144a7c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f144a80:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f144a84:	0fc55b92 */ 	jal	textRender
/*  f144a88:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f144a8c:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f144a90:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144a94:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f144a98:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f144a9c:	5460004f */ 	bnezl	$v1,.L0f144bdc
/*  f144aa0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f144aa4:	0fc5b9f1 */ 	jal	langGet
/*  f144aa8:	2404584f */ 	addiu	$a0,$zero,0x584f
/*  f144aac:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e24)
/*  f144ab0:	24a55e24 */ 	addiu	$a1,$a1,%lo(var7f1b5e24)
/*  f144ab4:	02602025 */ 	or	$a0,$s3,$zero
/*  f144ab8:	0c004dad */ 	jal	sprintf
/*  f144abc:	00403025 */ 	or	$a2,$v0,$zero
/*  f144ac0:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicXs)
/*  f144ac4:	8f39fb04 */ 	lw	$t9,%lo(g_FontHandelGothicXs)($t9)
/*  f144ac8:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicXs)
/*  f144acc:	8ce7fb08 */ 	lw	$a3,%lo(g_CharsHandelGothicXs)($a3)
/*  f144ad0:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f144ad4:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f144ad8:	02603025 */ 	or	$a2,$s3,$zero
/*  f144adc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f144ae0:	0fc55cbe */ 	jal	textMeasure
/*  f144ae4:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f144ae8:	8faf02ac */ 	lw	$t7,0x2ac($sp)
/*  f144aec:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f144af0:	8fb902a8 */ 	lw	$t9,0x2a8($sp)
/*  f144af4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f144af8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f144afc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f144b00:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f144b04:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f144b08:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f144b0c:	01d81823 */ 	subu	$v1,$t6,$t8
/*  f144b10:	13200003 */ 	beqz	$t9,.L0f144b20
/*  f144b14:	2463ffe7 */ 	addiu	$v1,$v1,-25
/*  f144b18:	10000002 */ 	b	.L0f144b24
/*  f144b1c:	2402fff3 */ 	addiu	$v0,$zero,-13
.L0f144b20:
/*  f144b20:	00001025 */ 	or	$v0,$zero,$zero
.L0f144b24:
/*  f144b24:	8faf0300 */ 	lw	$t7,0x300($sp)
/*  f144b28:	8fae02e4 */ 	lw	$t6,0x2e4($sp)
/*  f144b2c:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f144b30:	004f4021 */ 	addu	$t0,$v0,$t7
/*  f144b34:	2508001b */ 	addiu	$t0,$t0,0x1b
/*  f144b38:	006ec021 */ 	addu	$t8,$v1,$t6
/*  f144b3c:	27ae02d8 */ 	addiu	$t6,$sp,0x2d8
/*  f144b40:	01197821 */ 	addu	$t7,$t0,$t9
/*  f144b44:	afaf02d8 */ 	sw	$t7,0x2d8($sp)
/*  f144b48:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f144b4c:	afb802dc */ 	sw	$t8,0x2dc($sp)
/*  f144b50:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f144b54:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144b58:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144b5c:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144b60:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f144b64:	0fc54e16 */ 	jal	func0f153858
/*  f144b68:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f144b6c:	0c002f02 */ 	jal	viGetWidth
/*  f144b70:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144b74:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144b78:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f144b7c:	0c002f06 */ 	jal	viGetHeight
/*  f144b80:	03008025 */ 	or	$s0,$t8,$zero
/*  f144b84:	3c198008 */ 	lui	$t9,%hi(g_CharsHandelGothicXs)
/*  f144b88:	3c0f8008 */ 	lui	$t7,%hi(g_FontHandelGothicXs)
/*  f144b8c:	8deffb04 */ 	lw	$t7,%lo(g_FontHandelGothicXs)($t7)
/*  f144b90:	8f39fb08 */ 	lw	$t9,%lo(g_CharsHandelGothicXs)($t9)
/*  f144b94:	8fae02b4 */ 	lw	$t6,0x2b4($sp)
/*  f144b98:	8fb802b0 */ 	lw	$t8,0x2b0($sp)
/*  f144b9c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144ba0:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144ba4:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144ba8:	02603825 */ 	or	$a3,$s3,$zero
/*  f144bac:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f144bb0:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f144bb4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f144bb8:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f144bbc:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f144bc0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f144bc4:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f144bc8:	0fc55b92 */ 	jal	textRender
/*  f144bcc:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f144bd0:	1000009b */ 	b	.L0f144e40
/*  f144bd4:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144bd8:	24010001 */ 	addiu	$at,$zero,0x1
.L0f144bdc:
/*  f144bdc:	1461004e */ 	bne	$v1,$at,.L0f144d18
/*  f144be0:	00000000 */ 	nop
/*  f144be4:	0fc5b9f1 */ 	jal	langGet
/*  f144be8:	240459d4 */ 	addiu	$a0,$zero,0x59d4
/*  f144bec:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e2c)
/*  f144bf0:	24a55e2c */ 	addiu	$a1,$a1,%lo(var7f1b5e2c)
/*  f144bf4:	02602025 */ 	or	$a0,$s3,$zero
/*  f144bf8:	0c004dad */ 	jal	sprintf
/*  f144bfc:	00403025 */ 	or	$a2,$v0,$zero
/*  f144c00:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicXs)
/*  f144c04:	8f39fb04 */ 	lw	$t9,%lo(g_FontHandelGothicXs)($t9)
/*  f144c08:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicXs)
/*  f144c0c:	8ce7fb08 */ 	lw	$a3,%lo(g_CharsHandelGothicXs)($a3)
/*  f144c10:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f144c14:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f144c18:	02603025 */ 	or	$a2,$s3,$zero
/*  f144c1c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f144c20:	0fc55cbe */ 	jal	textMeasure
/*  f144c24:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f144c28:	8fae02ac */ 	lw	$t6,0x2ac($sp)
/*  f144c2c:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f144c30:	8fb902a8 */ 	lw	$t9,0x2a8($sp)
/*  f144c34:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f144c38:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f144c3c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f144c40:	030ec021 */ 	addu	$t8,$t8,$t6
/*  f144c44:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f144c48:	030ec021 */ 	addu	$t8,$t8,$t6
/*  f144c4c:	01f81823 */ 	subu	$v1,$t7,$t8
/*  f144c50:	13200003 */ 	beqz	$t9,.L0f144c60
/*  f144c54:	2463ffe7 */ 	addiu	$v1,$v1,-25
/*  f144c58:	10000002 */ 	b	.L0f144c64
/*  f144c5c:	2402fff3 */ 	addiu	$v0,$zero,-13
.L0f144c60:
/*  f144c60:	00001025 */ 	or	$v0,$zero,$zero
.L0f144c64:
/*  f144c64:	8fae0300 */ 	lw	$t6,0x300($sp)
/*  f144c68:	8faf02e4 */ 	lw	$t7,0x2e4($sp)
/*  f144c6c:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f144c70:	004e4021 */ 	addu	$t0,$v0,$t6
/*  f144c74:	2508001b */ 	addiu	$t0,$t0,0x1b
/*  f144c78:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f144c7c:	27af02d8 */ 	addiu	$t7,$sp,0x2d8
/*  f144c80:	01197021 */ 	addu	$t6,$t0,$t9
/*  f144c84:	afae02d8 */ 	sw	$t6,0x2d8($sp)
/*  f144c88:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f144c8c:	afb802dc */ 	sw	$t8,0x2dc($sp)
/*  f144c90:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f144c94:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144c98:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144c9c:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144ca0:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f144ca4:	0fc54e16 */ 	jal	func0f153858
/*  f144ca8:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f144cac:	0c002f02 */ 	jal	viGetWidth
/*  f144cb0:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144cb4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144cb8:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f144cbc:	0c002f06 */ 	jal	viGetHeight
/*  f144cc0:	03008025 */ 	or	$s0,$t8,$zero
/*  f144cc4:	3c198008 */ 	lui	$t9,%hi(g_CharsHandelGothicXs)
/*  f144cc8:	3c0e8008 */ 	lui	$t6,%hi(g_FontHandelGothicXs)
/*  f144ccc:	8dcefb04 */ 	lw	$t6,%lo(g_FontHandelGothicXs)($t6)
/*  f144cd0:	8f39fb08 */ 	lw	$t9,%lo(g_CharsHandelGothicXs)($t9)
/*  f144cd4:	8faf02b4 */ 	lw	$t7,0x2b4($sp)
/*  f144cd8:	8fb802b0 */ 	lw	$t8,0x2b0($sp)
/*  f144cdc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144ce0:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144ce4:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144ce8:	02603825 */ 	or	$a3,$s3,$zero
/*  f144cec:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f144cf0:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f144cf4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f144cf8:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f144cfc:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f144d00:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f144d04:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f144d08:	0fc55b92 */ 	jal	textRender
/*  f144d0c:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f144d10:	1000004b */ 	b	.L0f144e40
/*  f144d14:	0040a825 */ 	or	$s5,$v0,$zero
.L0f144d18:
/*  f144d18:	0fc5b9f1 */ 	jal	langGet
/*  f144d1c:	240459d5 */ 	addiu	$a0,$zero,0x59d5
/*  f144d20:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e34)
/*  f144d24:	24a55e34 */ 	addiu	$a1,$a1,%lo(var7f1b5e34)
/*  f144d28:	02602025 */ 	or	$a0,$s3,$zero
/*  f144d2c:	0c004dad */ 	jal	sprintf
/*  f144d30:	00403025 */ 	or	$a2,$v0,$zero
/*  f144d34:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicXs)
/*  f144d38:	8f39fb04 */ 	lw	$t9,%lo(g_FontHandelGothicXs)($t9)
/*  f144d3c:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicXs)
/*  f144d40:	8ce7fb08 */ 	lw	$a3,%lo(g_CharsHandelGothicXs)($a3)
/*  f144d44:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f144d48:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f144d4c:	02603025 */ 	or	$a2,$s3,$zero
/*  f144d50:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f144d54:	0fc55cbe */ 	jal	textMeasure
/*  f144d58:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f144d5c:	8faf02ac */ 	lw	$t7,0x2ac($sp)
/*  f144d60:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f144d64:	8fb902a8 */ 	lw	$t9,0x2a8($sp)
/*  f144d68:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f144d6c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f144d70:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f144d74:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f144d78:	01d81823 */ 	subu	$v1,$t6,$t8
/*  f144d7c:	13200003 */ 	beqz	$t9,.L0f144d8c
/*  f144d80:	2463ffe7 */ 	addiu	$v1,$v1,-25
/*  f144d84:	10000002 */ 	b	.L0f144d90
/*  f144d88:	2402fff3 */ 	addiu	$v0,$zero,-13
.L0f144d8c:
/*  f144d8c:	00001025 */ 	or	$v0,$zero,$zero
.L0f144d90:
/*  f144d90:	8faf0300 */ 	lw	$t7,0x300($sp)
/*  f144d94:	8fae02e4 */ 	lw	$t6,0x2e4($sp)
/*  f144d98:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f144d9c:	004f4021 */ 	addu	$t0,$v0,$t7
/*  f144da0:	2508001b */ 	addiu	$t0,$t0,0x1b
/*  f144da4:	006ec021 */ 	addu	$t8,$v1,$t6
/*  f144da8:	27ae02d8 */ 	addiu	$t6,$sp,0x2d8
/*  f144dac:	01197821 */ 	addu	$t7,$t0,$t9
/*  f144db0:	afaf02d8 */ 	sw	$t7,0x2d8($sp)
/*  f144db4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f144db8:	afb802dc */ 	sw	$t8,0x2dc($sp)
/*  f144dbc:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f144dc0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144dc4:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144dc8:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144dcc:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f144dd0:	0fc54e16 */ 	jal	func0f153858
/*  f144dd4:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f144dd8:	0c002f02 */ 	jal	viGetWidth
/*  f144ddc:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144de0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144de4:	0010c403 */ 	sra	$t8,$s0,0x10
/*  f144de8:	0c002f06 */ 	jal	viGetHeight
/*  f144dec:	03008025 */ 	or	$s0,$t8,$zero
/*  f144df0:	3c198008 */ 	lui	$t9,%hi(g_CharsHandelGothicXs)
/*  f144df4:	3c0f8008 */ 	lui	$t7,%hi(g_FontHandelGothicXs)
/*  f144df8:	8deffb04 */ 	lw	$t7,%lo(g_FontHandelGothicXs)($t7)
/*  f144dfc:	8f39fb08 */ 	lw	$t9,%lo(g_CharsHandelGothicXs)($t9)
/*  f144e00:	8fae02b4 */ 	lw	$t6,0x2b4($sp)
/*  f144e04:	8fb802b0 */ 	lw	$t8,0x2b0($sp)
/*  f144e08:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144e0c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144e10:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144e14:	02603825 */ 	or	$a3,$s3,$zero
/*  f144e18:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f144e1c:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f144e20:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f144e24:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f144e28:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f144e2c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f144e30:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f144e34:	0fc55b92 */ 	jal	textRender
/*  f144e38:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f144e3c:	0040a825 */ 	or	$s5,$v0,$zero
.L0f144e40:
/*  f144e40:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f144e44:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f144e48:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f144e4c:	5460000b */ 	bnezl	$v1,.L0f144e7c
/*  f144e50:	24010001 */ 	addiu	$at,$zero,0x1
/*  f144e54:	0fc5b9f1 */ 	jal	langGet
/*  f144e58:	24045850 */ 	addiu	$a0,$zero,0x5850
/*  f144e5c:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e3c)
/*  f144e60:	24a55e3c */ 	addiu	$a1,$a1,%lo(var7f1b5e3c)
/*  f144e64:	02602025 */ 	or	$a0,$s3,$zero
/*  f144e68:	0c004dad */ 	jal	sprintf
/*  f144e6c:	00403025 */ 	or	$a2,$v0,$zero
/*  f144e70:	10000014 */ 	b	.L0f144ec4
/*  f144e74:	00000000 */ 	nop
/*  f144e78:	24010001 */ 	addiu	$at,$zero,0x1
.L0f144e7c:
/*  f144e7c:	1461000a */ 	bne	$v1,$at,.L0f144ea8
/*  f144e80:	00000000 */ 	nop
/*  f144e84:	0fc5b9f1 */ 	jal	langGet
/*  f144e88:	240458cf */ 	addiu	$a0,$zero,0x58cf
/*  f144e8c:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e40)
/*  f144e90:	24a55e40 */ 	addiu	$a1,$a1,%lo(var7f1b5e40)
/*  f144e94:	02602025 */ 	or	$a0,$s3,$zero
/*  f144e98:	0c004dad */ 	jal	sprintf
/*  f144e9c:	00403025 */ 	or	$a2,$v0,$zero
/*  f144ea0:	10000008 */ 	b	.L0f144ec4
/*  f144ea4:	00000000 */ 	nop
.L0f144ea8:
/*  f144ea8:	0fc5b9f1 */ 	jal	langGet
/*  f144eac:	240458d8 */ 	addiu	$a0,$zero,0x58d8
/*  f144eb0:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e44)
/*  f144eb4:	24a55e44 */ 	addiu	$a1,$a1,%lo(var7f1b5e44)
/*  f144eb8:	02602025 */ 	or	$a0,$s3,$zero
/*  f144ebc:	0c004dad */ 	jal	sprintf
/*  f144ec0:	00403025 */ 	or	$a2,$v0,$zero
.L0f144ec4:
/*  f144ec4:	3c0e8008 */ 	lui	$t6,%hi(g_FontHandelGothicXs)
/*  f144ec8:	8dcefb04 */ 	lw	$t6,%lo(g_FontHandelGothicXs)($t6)
/*  f144ecc:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicXs)
/*  f144ed0:	8ce7fb08 */ 	lw	$a3,%lo(g_CharsHandelGothicXs)($a3)
/*  f144ed4:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f144ed8:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f144edc:	02603025 */ 	or	$a2,$s3,$zero
/*  f144ee0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f144ee4:	0fc55cbe */ 	jal	textMeasure
/*  f144ee8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f144eec:	8fa902a8 */ 	lw	$t1,0x2a8($sp)
/*  f144ef0:	8faf02ac */ 	lw	$t7,0x2ac($sp)
/*  f144ef4:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f144ef8:	11200003 */ 	beqz	$t1,.L0f144f08
/*  f144efc:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f144f00:	10000002 */ 	b	.L0f144f0c
/*  f144f04:	24020003 */ 	addiu	$v0,$zero,0x3
.L0f144f08:
/*  f144f08:	00001025 */ 	or	$v0,$zero,$zero
.L0f144f0c:
/*  f144f0c:	01cf7023 */ 	subu	$t6,$t6,$t7
/*  f144f10:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f144f14:	01cf7023 */ 	subu	$t6,$t6,$t7
/*  f144f18:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f144f1c:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f144f20:	032e1823 */ 	subu	$v1,$t9,$t6
/*  f144f24:	11200003 */ 	beqz	$t1,.L0f144f34
/*  f144f28:	2463ffe7 */ 	addiu	$v1,$v1,-25
/*  f144f2c:	10000002 */ 	b	.L0f144f38
/*  f144f30:	2402fff5 */ 	addiu	$v0,$zero,-11
.L0f144f34:
/*  f144f34:	00001025 */ 	or	$v0,$zero,$zero
.L0f144f38:
/*  f144f38:	8fb80300 */ 	lw	$t8,0x300($sp)
/*  f144f3c:	8faf02e4 */ 	lw	$t7,0x2e4($sp)
/*  f144f40:	8fae02e0 */ 	lw	$t6,0x2e0($sp)
/*  f144f44:	00584021 */ 	addu	$t0,$v0,$t8
/*  f144f48:	25080022 */ 	addiu	$t0,$t0,0x22
/*  f144f4c:	006fc821 */ 	addu	$t9,$v1,$t7
/*  f144f50:	27af02d8 */ 	addiu	$t7,$sp,0x2d8
/*  f144f54:	010ec021 */ 	addu	$t8,$t0,$t6
/*  f144f58:	afb802d8 */ 	sw	$t8,0x2d8($sp)
/*  f144f5c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f144f60:	afb902dc */ 	sw	$t9,0x2dc($sp)
/*  f144f64:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f144f68:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144f6c:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144f70:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144f74:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f144f78:	0fc54e16 */ 	jal	func0f153858
/*  f144f7c:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f144f80:	0c002f02 */ 	jal	viGetWidth
/*  f144f84:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144f88:	00028400 */ 	sll	$s0,$v0,0x10
/*  f144f8c:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f144f90:	0c002f06 */ 	jal	viGetHeight
/*  f144f94:	03208025 */ 	or	$s0,$t9,$zero
/*  f144f98:	3c0e8008 */ 	lui	$t6,%hi(g_CharsHandelGothicXs)
/*  f144f9c:	3c188008 */ 	lui	$t8,%hi(g_FontHandelGothicXs)
/*  f144fa0:	8f18fb04 */ 	lw	$t8,%lo(g_FontHandelGothicXs)($t8)
/*  f144fa4:	8dcefb08 */ 	lw	$t6,%lo(g_CharsHandelGothicXs)($t6)
/*  f144fa8:	8faf02b4 */ 	lw	$t7,0x2b4($sp)
/*  f144fac:	8fb902b0 */ 	lw	$t9,0x2b0($sp)
/*  f144fb0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f144fb4:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f144fb8:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f144fbc:	02603825 */ 	or	$a3,$s3,$zero
/*  f144fc0:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f144fc4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f144fc8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f144fcc:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f144fd0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f144fd4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f144fd8:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f144fdc:	0fc55b92 */ 	jal	textRender
/*  f144fe0:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f144fe4:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f144fe8:	0040a825 */ 	or	$s5,$v0,$zero
/*  f144fec:	8dd80480 */ 	lw	$t8,0x480($t6)
/*  f144ff0:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f144ff4:	10600003 */ 	beqz	$v1,.L0f145004
/*  f144ff8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f144ffc:	1461000a */ 	bne	$v1,$at,.L0f145028
/*  f145000:	00000000 */ 	nop
.L0f145004:
/*  f145004:	0fc5b9f1 */ 	jal	langGet
/*  f145008:	24045851 */ 	addiu	$a0,$zero,0x5851
/*  f14500c:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e48)
/*  f145010:	24a55e48 */ 	addiu	$a1,$a1,%lo(var7f1b5e48)
/*  f145014:	02602025 */ 	or	$a0,$s3,$zero
/*  f145018:	0c004dad */ 	jal	sprintf
/*  f14501c:	00403025 */ 	or	$a2,$v0,$zero
/*  f145020:	10000008 */ 	b	.L0f145044
/*  f145024:	00000000 */ 	nop
.L0f145028:
/*  f145028:	0fc5b9f1 */ 	jal	langGet
/*  f14502c:	240458ce */ 	addiu	$a0,$zero,0x58ce
/*  f145030:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e4c)
/*  f145034:	24a55e4c */ 	addiu	$a1,$a1,%lo(var7f1b5e4c)
/*  f145038:	02602025 */ 	or	$a0,$s3,$zero
/*  f14503c:	0c004dad */ 	jal	sprintf
/*  f145040:	00403025 */ 	or	$a2,$v0,$zero
.L0f145044:
/*  f145044:	3c0f8008 */ 	lui	$t7,%hi(g_FontHandelGothicXs)
/*  f145048:	8deffb04 */ 	lw	$t7,%lo(g_FontHandelGothicXs)($t7)
/*  f14504c:	3c078008 */ 	lui	$a3,%hi(g_CharsHandelGothicXs)
/*  f145050:	8ce7fb08 */ 	lw	$a3,%lo(g_CharsHandelGothicXs)($a3)
/*  f145054:	27a402e0 */ 	addiu	$a0,$sp,0x2e0
/*  f145058:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f14505c:	02603025 */ 	or	$a2,$s3,$zero
/*  f145060:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f145064:	0fc55cbe */ 	jal	textMeasure
/*  f145068:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f14506c:	8fb902a8 */ 	lw	$t9,0x2a8($sp)
/*  f145070:	8fb402ac */ 	lw	$s4,0x2ac($sp)
/*  f145074:	c7aa0068 */ 	lwc1	$f10,0x68($sp)
/*  f145078:	13200003 */ 	beqz	$t9,.L0f145088
/*  f14507c:	00147080 */ 	sll	$t6,$s4,0x2
/*  f145080:	10000002 */ 	b	.L0f14508c
/*  f145084:	2402ffdd */ 	addiu	$v0,$zero,-35
.L0f145088:
/*  f145088:	00001025 */ 	or	$v0,$zero,$zero
.L0f14508c:
/*  f14508c:	01d47021 */ 	addu	$t6,$t6,$s4
/*  f145090:	3c014040 */ 	lui	$at,0x4040
/*  f145094:	44814000 */ 	mtc1	$at,$f8
/*  f145098:	25d8fffb */ 	addiu	$t8,$t6,-5
/*  f14509c:	44983000 */ 	mtc1	$t8,$f6
/*  f1450a0:	46085101 */ 	sub.s	$f4,$f10,$f8
/*  f1450a4:	8fb902a8 */ 	lw	$t9,0x2a8($sp)
/*  f1450a8:	01c0a025 */ 	or	$s4,$t6,$zero
/*  f1450ac:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f1450b0:	44823000 */ 	mtc1	$v0,$f6
/*  f1450b4:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f1450b8:	8fb802e4 */ 	lw	$t8,0x2e4($sp)
/*  f1450bc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1450c0:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f1450c4:	460a2201 */ 	sub.s	$f8,$f4,$f10
/*  f1450c8:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f1450cc:	27a702dc */ 	addiu	$a3,$sp,0x2dc
/*  f1450d0:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f1450d4:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f1450d8:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f1450dc:	44033000 */ 	mfc1	$v1,$f6
/*  f1450e0:	53200004 */ 	beqzl	$t9,.L0f1450f4
/*  f1450e4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1450e8:	10000002 */ 	b	.L0f1450f4
/*  f1450ec:	2402fffe */ 	addiu	$v0,$zero,-2
/*  f1450f0:	00001025 */ 	or	$v0,$zero,$zero
.L0f1450f4:
/*  f1450f4:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f1450f8:	004e4021 */ 	addu	$t0,$v0,$t6
/*  f1450fc:	2508fff4 */ 	addiu	$t0,$t0,-12
/*  f145100:	00787821 */ 	addu	$t7,$v1,$t8
/*  f145104:	27b802d8 */ 	addiu	$t8,$sp,0x2d8
/*  f145108:	01197021 */ 	addu	$t6,$t0,$t9
/*  f14510c:	afae02d8 */ 	sw	$t6,0x2d8($sp)
/*  f145110:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f145114:	afaf02dc */ 	sw	$t7,0x2dc($sp)
/*  f145118:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f14511c:	0fc54e16 */ 	jal	func0f153858
/*  f145120:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f145124:	0c002f02 */ 	jal	viGetWidth
/*  f145128:	0040a825 */ 	or	$s5,$v0,$zero
/*  f14512c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f145130:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f145134:	0c002f06 */ 	jal	viGetHeight
/*  f145138:	01e08025 */ 	or	$s0,$t7,$zero
/*  f14513c:	3c198008 */ 	lui	$t9,%hi(g_CharsHandelGothicXs)
/*  f145140:	3c0e8008 */ 	lui	$t6,%hi(g_FontHandelGothicXs)
/*  f145144:	8dcefb04 */ 	lw	$t6,%lo(g_FontHandelGothicXs)($t6)
/*  f145148:	8f39fb08 */ 	lw	$t9,%lo(g_CharsHandelGothicXs)($t9)
/*  f14514c:	8fb802b4 */ 	lw	$t8,0x2b4($sp)
/*  f145150:	8faf02b0 */ 	lw	$t7,0x2b0($sp)
/*  f145154:	02a02025 */ 	or	$a0,$s5,$zero
/*  f145158:	27a502ec */ 	addiu	$a1,$sp,0x2ec
/*  f14515c:	27a602e8 */ 	addiu	$a2,$sp,0x2e8
/*  f145160:	02603825 */ 	or	$a3,$s3,$zero
/*  f145164:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f145168:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f14516c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f145170:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f145174:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f145178:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f14517c:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f145180:	0fc55b92 */ 	jal	textRender
/*  f145184:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f145188:	0fc54e0e */ 	jal	func0f153838
/*  f14518c:	00402025 */ 	or	$a0,$v0,$zero
/*  f145190:	8ed90288 */ 	lw	$t9,0x288($s6)
/*  f145194:	0040a825 */ 	or	$s5,$v0,$zero
/*  f145198:	0fc549d2 */ 	jal	optionsGetContpadNum1
/*  f14519c:	8f240070 */ 	lw	$a0,0x70($t9)
/*  f1451a0:	00028600 */ 	sll	$s0,$v0,0x18
/*  f1451a4:	00022600 */ 	sll	$a0,$v0,0x18
/*  f1451a8:	00107603 */ 	sra	$t6,$s0,0x18
/*  f1451ac:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f1451b0:	01c08025 */ 	or	$s0,$t6,$zero
/*  f1451b4:	03002025 */ 	or	$a0,$t8,$zero
/*  f1451b8:	0c0053d8 */ 	jal	joyGetButtons
/*  f1451bc:	3405ffff */ 	dli	$a1,0xffff
/*  f1451c0:	00102600 */ 	sll	$a0,$s0,0x18
/*  f1451c4:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f1451c8:	01e02025 */ 	or	$a0,$t7,$zero
/*  f1451cc:	3051ffff */ 	andi	$s1,$v0,0xffff
/*  f1451d0:	0c005408 */ 	jal	joyGetButtonsPressedThisFrame
/*  f1451d4:	3405ffff */ 	dli	$a1,0xffff
/*  f1451d8:	00102600 */ 	sll	$a0,$s0,0x18
/*  f1451dc:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f1451e0:	3052ffff */ 	andi	$s2,$v0,0xffff
/*  f1451e4:	0c005384 */ 	jal	joyGetStickX
/*  f1451e8:	03202025 */ 	or	$a0,$t9,$zero
/*  f1451ec:	00102600 */ 	sll	$a0,$s0,0x18
/*  f1451f0:	00047603 */ 	sra	$t6,$a0,0x18
/*  f1451f4:	01c02025 */ 	or	$a0,$t6,$zero
/*  f1451f8:	0c0053ae */ 	jal	joyGetStickY
/*  f1451fc:	a3a20251 */ 	sb	$v0,0x251($sp)
/*  f145200:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145204:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145208:	3c18e700 */ 	lui	$t8,0xe700
/*  f14520c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f145210:	02a02025 */ 	or	$a0,$s5,$zero
/*  f145214:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145218:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f14521c:	3c0fba00 */ 	lui	$t7,0xba00
/*  f145220:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*  f145224:	02a02825 */ 	or	$a1,$s5,$zero
/*  f145228:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f14522c:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f145230:	3c19ba00 */ 	lui	$t9,0xba00
/*  f145234:	37390602 */ 	ori	$t9,$t9,0x602
/*  f145238:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14523c:	240e00c0 */ 	addiu	$t6,$zero,0xc0
/*  f145240:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f145244:	02a03025 */ 	or	$a2,$s5,$zero
/*  f145248:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f14524c:	3c18ba00 */ 	lui	$t8,0xba00
/*  f145250:	37181301 */ 	ori	$t8,$t8,0x1301
/*  f145254:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f145258:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14525c:	02a03825 */ 	or	$a3,$s5,$zero
/*  f145260:	acc00004 */ 	sw	$zero,0x4($a2)
/*  f145264:	3c0fb900 */ 	lui	$t7,0xb900
/*  f145268:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f14526c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145270:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145274:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f145278:	3c19ba00 */ 	lui	$t9,0xba00
/*  f14527c:	37391001 */ 	ori	$t9,$t9,0x1001
/*  f145280:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145284:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f145288:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f14528c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f145290:	3c0eba00 */ 	lui	$t6,0xba00
/*  f145294:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f145298:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14529c:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f1452a0:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1452a4:	02a02825 */ 	or	$a1,$s5,$zero
/*  f1452a8:	24182000 */ 	addiu	$t8,$zero,0x2000
/*  f1452ac:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f1452b0:	3c0fba00 */ 	lui	$t7,0xba00
/*  f1452b4:	35ef0903 */ 	ori	$t7,$t7,0x903
/*  f1452b8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1452bc:	24190c00 */ 	addiu	$t9,$zero,0xc00
/*  f1452c0:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f1452c4:	02a03025 */ 	or	$a2,$s5,$zero
/*  f1452c8:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f1452cc:	3c0eba00 */ 	lui	$t6,0xba00
/*  f1452d0:	35ce0e02 */ 	ori	$t6,$t6,0xe02
/*  f1452d4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1452d8:	02a04025 */ 	or	$t0,$s5,$zero
/*  f1452dc:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f1452e0:	acc00004 */ 	sw	$zero,0x4($a2)
/*  f1452e4:	3c0f0050 */ 	lui	$t7,0x50
/*  f1452e8:	3c18b900 */ 	lui	$t8,0xb900
/*  f1452ec:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f1452f0:	35ef4340 */ 	ori	$t7,$t7,0x4340
/*  f1452f4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1452f8:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1452fc:	ad0f0004 */ 	sw	$t7,0x4($t0)
/*  f145300:	ad180000 */ 	sw	$t8,0x0($t0)
/*  f145304:	3c0efffd */ 	lui	$t6,0xfffd
/*  f145308:	3c19fcff */ 	lui	$t9,0xfcff
/*  f14530c:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f145310:	35cef6fb */ 	ori	$t6,$t6,0xf6fb
/*  f145314:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f145318:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f14531c:	8fb802a8 */ 	lw	$t8,0x2a8($sp)
/*  f145320:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145324:	8faf02ac */ 	lw	$t7,0x2ac($sp)
/*  f145328:	170001ff */ 	bnez	$t8,.L0f145b28
/*  f14532c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f145330:	15e10003 */ 	bne	$t7,$at,.L0f145340
/*  f145334:	2407ffab */ 	addiu	$a3,$zero,-85
/*  f145338:	10000001 */ 	b	.L0f145340
/*  f14533c:	2407ffb4 */ 	addiu	$a3,$zero,-76
.L0f145340:
/*  f145340:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f145344:	24010001 */ 	addiu	$at,$zero,0x1
/*  f145348:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f14534c:	8f2e0480 */ 	lw	$t6,0x480($t9)
/*  f145350:	32380808 */ 	andi	$t8,$s1,0x808
/*  f145354:	324f0808 */ 	andi	$t7,$s2,0x808
/*  f145358:	91c3006b */ 	lbu	$v1,0x6b($t6)
/*  f14535c:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f145360:	3c0b1020 */ 	lui	$t3,0x1020
/*  f145364:	14600011 */ 	bnez	$v1,.L0f1453ac
/*  f145368:	00000000 */ 	nop
/*  f14536c:	13000002 */ 	beqz	$t8,.L0f145378
/*  f145370:	02202825 */ 	or	$a1,$s1,$zero
/*  f145374:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f145378:
/*  f145378:	11e00004 */ 	beqz	$t7,.L0f14538c
/*  f14537c:	02403025 */ 	or	$a2,$s2,$zero
/*  f145380:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145384:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145388:	03209825 */ 	or	$s3,$t9,$zero
.L0f14538c:
/*  f14538c:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f145390:	000ec400 */ 	sll	$t8,$t6,0x10
/*  f145394:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145398:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f14539c:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f1453a0:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1453a4:	1000002f */ 	b	.L0f145464
/*  f1453a8:	26b50008 */ 	addiu	$s5,$s5,0x8
.L0f1453ac:
/*  f1453ac:	14610017 */ 	bne	$v1,$at,.L0f14540c
/*  f1453b0:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f1453b4:	32390808 */ 	andi	$t9,$s1,0x808
/*  f1453b8:	2413007f */ 	addiu	$s3,$zero,0x7f
/*  f1453bc:	13200002 */ 	beqz	$t9,.L0f1453c8
/*  f1453c0:	02202825 */ 	or	$a1,$s1,$zero
/*  f1453c4:	241300be */ 	addiu	$s3,$zero,0xbe
.L0f1453c8:
/*  f1453c8:	324e0808 */ 	andi	$t6,$s2,0x808
/*  f1453cc:	11c00004 */ 	beqz	$t6,.L0f1453e0
/*  f1453d0:	02403025 */ 	or	$a2,$s2,$zero
/*  f1453d4:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f1453d8:	327800ff */ 	andi	$t8,$s3,0xff
/*  f1453dc:	03009825 */ 	or	$s3,$t8,$zero
.L0f1453e0:
/*  f1453e0:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f1453e4:	000fca00 */ 	sll	$t9,$t7,0x8
/*  f1453e8:	3c0b1020 */ 	lui	$t3,0x1020
/*  f1453ec:	032b7025 */ 	or	$t6,$t9,$t3
/*  f1453f0:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1453f4:	35d800ff */ 	ori	$t8,$t6,0xff
/*  f1453f8:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f1453fc:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f145400:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f145404:	10000017 */ 	b	.L0f145464
/*  f145408:	26b50008 */ 	addiu	$s5,$s5,0x8
.L0f14540c:
/*  f14540c:	322f0808 */ 	andi	$t7,$s1,0x808
/*  f145410:	11e00002 */ 	beqz	$t7,.L0f14541c
/*  f145414:	02202825 */ 	or	$a1,$s1,$zero
/*  f145418:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f14541c:
/*  f14541c:	32590808 */ 	andi	$t9,$s2,0x808
/*  f145420:	13200004 */ 	beqz	$t9,.L0f145434
/*  f145424:	02403025 */ 	or	$a2,$s2,$zero
/*  f145428:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f14542c:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f145430:	01c09825 */ 	or	$s3,$t6,$zero
.L0f145434:
/*  f145434:	0013c883 */ 	sra	$t9,$s3,0x2
/*  f145438:	332e00ff */ 	andi	$t6,$t9,0xff
/*  f14543c:	000ec400 */ 	sll	$t8,$t6,0x10
/*  f145440:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145444:	00137e00 */ 	sll	$t7,$s3,0x18
/*  f145448:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f14544c:	372e00ff */ 	ori	$t6,$t9,0xff
/*  f145450:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f145454:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f145458:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f14545c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145460:	3c0b1020 */ 	lui	$t3,0x1020
.L0f145464:
/*  f145464:	8fbf02ac */ 	lw	$ra,0x2ac($sp)
/*  f145468:	24ef0008 */ 	addiu	$t7,$a3,0x8
/*  f14546c:	8fb0008c */ 	lw	$s0,0x8c($sp)
/*  f145470:	01ff0019 */ 	multu	$t7,$ra
/*  f145474:	8fb10300 */ 	lw	$s1,0x300($sp)
/*  f145478:	3c01f600 */ 	lui	$at,0xf600
/*  f14547c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f145480:	262c0012 */ 	addiu	$t4,$s1,0x12
/*  f145484:	319903ff */ 	andi	$t9,$t4,0x3ff
/*  f145488:	00196080 */ 	sll	$t4,$t9,0x2
/*  f14548c:	262d000a */ 	addiu	$t5,$s1,0xa
/*  f145490:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145494:	0000c012 */ 	mflo	$t8
/*  f145498:	03105021 */ 	addu	$t2,$t8,$s0
/*  f14549c:	314f03ff */ 	andi	$t7,$t2,0x3ff
/*  f1454a0:	00ff0019 */ 	multu	$a3,$ra
/*  f1454a4:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f1454a8:	0301c825 */ 	or	$t9,$t8,$at
/*  f1454ac:	032c7025 */ 	or	$t6,$t9,$t4
/*  f1454b0:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1454b4:	31b803ff */ 	andi	$t8,$t5,0x3ff
/*  f1454b8:	00186880 */ 	sll	$t5,$t8,0x2
/*  f1454bc:	001fc880 */ 	sll	$t9,$ra,0x2
/*  f1454c0:	033fc821 */ 	addu	$t9,$t9,$ra
/*  f1454c4:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f1454c8:	00007812 */ 	mflo	$t7
/*  f1454cc:	01f04021 */ 	addu	$t0,$t7,$s0
/*  f1454d0:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f1454d4:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1454d8:	01edc025 */ 	or	$t8,$t7,$t5
/*  f1454dc:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f1454e0:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f1454e4:	001f7080 */ 	sll	$t6,$ra,0x2
/*  f1454e8:	01df7021 */ 	addu	$t6,$t6,$ra
/*  f1454ec:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f1454f0:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f1454f4:	24e7000a */ 	addiu	$a3,$a3,0xa
/*  f1454f8:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f1454fc:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f145500:	01194021 */ 	addu	$t0,$t0,$t9
/*  f145504:	14600012 */ 	bnez	$v1,.L0f145550
/*  f145508:	24e7000a */ 	addiu	$a3,$a3,0xa
/*  f14550c:	30b90404 */ 	andi	$t9,$a1,0x404
/*  f145510:	13200002 */ 	beqz	$t9,.L0f14551c
/*  f145514:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f145518:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f14551c:
/*  f14551c:	30ce0404 */ 	andi	$t6,$a2,0x404
/*  f145520:	11c00004 */ 	beqz	$t6,.L0f145534
/*  f145524:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145528:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f14552c:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f145530:	01e09825 */ 	or	$s3,$t7,$zero
.L0f145534:
/*  f145534:	327800ff */ 	andi	$t8,$s3,0xff
/*  f145538:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f14553c:	372e00ff */ 	ori	$t6,$t9,0xff
/*  f145540:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f145544:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145548:	10000028 */ 	b	.L0f1455ec
/*  f14554c:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145550:
/*  f145550:	24010001 */ 	addiu	$at,$zero,0x1
/*  f145554:	14610013 */ 	bne	$v1,$at,.L0f1455a4
/*  f145558:	30ae0404 */ 	andi	$t6,$a1,0x404
/*  f14555c:	30af0404 */ 	andi	$t7,$a1,0x404
/*  f145560:	11e00002 */ 	beqz	$t7,.L0f14556c
/*  f145564:	2413007f */ 	addiu	$s3,$zero,0x7f
/*  f145568:	241300be */ 	addiu	$s3,$zero,0xbe
.L0f14556c:
/*  f14556c:	30d80404 */ 	andi	$t8,$a2,0x404
/*  f145570:	13000004 */ 	beqz	$t8,.L0f145584
/*  f145574:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145578:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f14557c:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145580:	03209825 */ 	or	$s3,$t9,$zero
.L0f145584:
/*  f145584:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f145588:	000e7a00 */ 	sll	$t7,$t6,0x8
/*  f14558c:	01ebc025 */ 	or	$t8,$t7,$t3
/*  f145590:	371900ff */ 	ori	$t9,$t8,0xff
/*  f145594:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f145598:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14559c:	10000013 */ 	b	.L0f1455ec
/*  f1455a0:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f1455a4:
/*  f1455a4:	11c00002 */ 	beqz	$t6,.L0f1455b0
/*  f1455a8:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f1455ac:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f1455b0:
/*  f1455b0:	30cf0404 */ 	andi	$t7,$a2,0x404
/*  f1455b4:	11e00004 */ 	beqz	$t7,.L0f1455c8
/*  f1455b8:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1455bc:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f1455c0:	327800ff */ 	andi	$t8,$s3,0xff
/*  f1455c4:	03009825 */ 	or	$s3,$t8,$zero
.L0f1455c8:
/*  f1455c8:	00137883 */ 	sra	$t7,$s3,0x2
/*  f1455cc:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f1455d0:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f1455d4:	00137600 */ 	sll	$t6,$s3,0x18
/*  f1455d8:	01d97825 */ 	or	$t7,$t6,$t9
/*  f1455dc:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f1455e0:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f1455e4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1455e8:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f1455ec:
/*  f1455ec:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f1455f0:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f1455f4:	3c01f600 */ 	lui	$at,0xf600
/*  f1455f8:	03217825 */ 	or	$t7,$t9,$at
/*  f1455fc:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f145600:	8fbf02ac */ 	lw	$ra,0x2ac($sp)
/*  f145604:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f145608:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f14560c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f145610:	032d7825 */ 	or	$t7,$t9,$t5
/*  f145614:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f145618:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f14561c:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f145620:	001fc080 */ 	sll	$t8,$ra,0x2
/*  f145624:	001f7080 */ 	sll	$t6,$ra,0x2
/*  f145628:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f14562c:	01df7021 */ 	addu	$t6,$t6,$ra
/*  f145630:	031fc021 */ 	addu	$t8,$t8,$ra
/*  f145634:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f145638:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f14563c:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f145640:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145644:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f145648:	14600012 */ 	bnez	$v1,.L0f145694
/*  f14564c:	01184021 */ 	addu	$t0,$t0,$t8
/*  f145650:	30b80202 */ 	andi	$t8,$a1,0x202
/*  f145654:	13000002 */ 	beqz	$t8,.L0f145660
/*  f145658:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f14565c:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f145660:
/*  f145660:	30ce0202 */ 	andi	$t6,$a2,0x202
/*  f145664:	11c00004 */ 	beqz	$t6,.L0f145678
/*  f145668:	02a01825 */ 	or	$v1,$s5,$zero
/*  f14566c:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145670:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145674:	03209825 */ 	or	$s3,$t9,$zero
.L0f145678:
/*  f145678:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f14567c:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f145680:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f145684:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f145688:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14568c:	10000028 */ 	b	.L0f145730
/*  f145690:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145694:
/*  f145694:	24010001 */ 	addiu	$at,$zero,0x1
/*  f145698:	14610013 */ 	bne	$v1,$at,.L0f1456e8
/*  f14569c:	30ae0202 */ 	andi	$t6,$a1,0x202
/*  f1456a0:	30b90202 */ 	andi	$t9,$a1,0x202
/*  f1456a4:	13200002 */ 	beqz	$t9,.L0f1456b0
/*  f1456a8:	2413007f */ 	addiu	$s3,$zero,0x7f
/*  f1456ac:	241300be */ 	addiu	$s3,$zero,0xbe
.L0f1456b0:
/*  f1456b0:	30cf0202 */ 	andi	$t7,$a2,0x202
/*  f1456b4:	11e00004 */ 	beqz	$t7,.L0f1456c8
/*  f1456b8:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1456bc:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f1456c0:	327800ff */ 	andi	$t8,$s3,0xff
/*  f1456c4:	03009825 */ 	or	$s3,$t8,$zero
.L0f1456c8:
/*  f1456c8:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f1456cc:	000eca00 */ 	sll	$t9,$t6,0x8
/*  f1456d0:	032b7825 */ 	or	$t7,$t9,$t3
/*  f1456d4:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f1456d8:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f1456dc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1456e0:	10000013 */ 	b	.L0f145730
/*  f1456e4:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f1456e8:
/*  f1456e8:	11c00002 */ 	beqz	$t6,.L0f1456f4
/*  f1456ec:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f1456f0:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f1456f4:
/*  f1456f4:	30d90202 */ 	andi	$t9,$a2,0x202
/*  f1456f8:	13200004 */ 	beqz	$t9,.L0f14570c
/*  f1456fc:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145700:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145704:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f145708:	01e09825 */ 	or	$s3,$t7,$zero
.L0f14570c:
/*  f14570c:	0013c883 */ 	sra	$t9,$s3,0x2
/*  f145710:	332f00ff */ 	andi	$t7,$t9,0xff
/*  f145714:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f145718:	00137600 */ 	sll	$t6,$s3,0x18
/*  f14571c:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f145720:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f145724:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f145728:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14572c:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145730:
/*  f145730:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f145734:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f145738:	3c01f600 */ 	lui	$at,0xf600
/*  f14573c:	0301c825 */ 	or	$t9,$t8,$at
/*  f145740:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f145744:	8fbf02ac */ 	lw	$ra,0x2ac($sp)
/*  f145748:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f14574c:	032c7825 */ 	or	$t7,$t9,$t4
/*  f145750:	02a02025 */ 	or	$a0,$s5,$zero
/*  f145754:	030dc825 */ 	or	$t9,$t8,$t5
/*  f145758:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f14575c:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f145760:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f145764:	001f7880 */ 	sll	$t7,$ra,0x2
/*  f145768:	001f7080 */ 	sll	$t6,$ra,0x2
/*  f14576c:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f145770:	01df7021 */ 	addu	$t6,$t6,$ra
/*  f145774:	01ff7821 */ 	addu	$t7,$t7,$ra
/*  f145778:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f14577c:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f145780:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f145784:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145788:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f14578c:	010f4021 */ 	addu	$t0,$t0,$t7
/*  f145790:	14600012 */ 	bnez	$v1,.L0f1457dc
/*  f145794:	24e7000a */ 	addiu	$a3,$a3,0xa
/*  f145798:	30af0101 */ 	andi	$t7,$a1,0x101
/*  f14579c:	11e00002 */ 	beqz	$t7,.L0f1457a8
/*  f1457a0:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f1457a4:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f1457a8:
/*  f1457a8:	30ce0101 */ 	andi	$t6,$a2,0x101
/*  f1457ac:	11c00004 */ 	beqz	$t6,.L0f1457c0
/*  f1457b0:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1457b4:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f1457b8:	327800ff */ 	andi	$t8,$s3,0xff
/*  f1457bc:	03009825 */ 	or	$s3,$t8,$zero
.L0f1457c0:
/*  f1457c0:	327900ff */ 	andi	$t9,$s3,0xff
/*  f1457c4:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f1457c8:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f1457cc:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f1457d0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1457d4:	10000028 */ 	b	.L0f145878
/*  f1457d8:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f1457dc:
/*  f1457dc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1457e0:	14610013 */ 	bne	$v1,$at,.L0f145830
/*  f1457e4:	30ae0101 */ 	andi	$t6,$a1,0x101
/*  f1457e8:	30b80101 */ 	andi	$t8,$a1,0x101
/*  f1457ec:	13000002 */ 	beqz	$t8,.L0f1457f8
/*  f1457f0:	2413007f */ 	addiu	$s3,$zero,0x7f
/*  f1457f4:	241300be */ 	addiu	$s3,$zero,0xbe
.L0f1457f8:
/*  f1457f8:	30d90101 */ 	andi	$t9,$a2,0x101
/*  f1457fc:	13200004 */ 	beqz	$t9,.L0f145810
/*  f145800:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145804:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f145808:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f14580c:	01e09825 */ 	or	$s3,$t7,$zero
.L0f145810:
/*  f145810:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f145814:	000ec200 */ 	sll	$t8,$t6,0x8
/*  f145818:	030bc825 */ 	or	$t9,$t8,$t3
/*  f14581c:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f145820:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f145824:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145828:	10000013 */ 	b	.L0f145878
/*  f14582c:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145830:
/*  f145830:	11c00002 */ 	beqz	$t6,.L0f14583c
/*  f145834:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f145838:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f14583c:
/*  f14583c:	30d80101 */ 	andi	$t8,$a2,0x101
/*  f145840:	13000004 */ 	beqz	$t8,.L0f145854
/*  f145844:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145848:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f14584c:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145850:	03209825 */ 	or	$s3,$t9,$zero
.L0f145854:
/*  f145854:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f145858:	331900ff */ 	andi	$t9,$t8,0xff
/*  f14585c:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f145860:	00137600 */ 	sll	$t6,$s3,0x18
/*  f145864:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f145868:	371900ff */ 	ori	$t9,$t8,0xff
/*  f14586c:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f145870:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145874:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145878:
/*  f145878:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f14587c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f145880:	3c01f600 */ 	lui	$at,0xf600
/*  f145884:	01e1c025 */ 	or	$t8,$t7,$at
/*  f145888:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f14588c:	8fbf02ac */ 	lw	$ra,0x2ac($sp)
/*  f145890:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f145894:	030cc825 */ 	or	$t9,$t8,$t4
/*  f145898:	02a02025 */ 	or	$a0,$s5,$zero
/*  f14589c:	01edc025 */ 	or	$t8,$t7,$t5
/*  f1458a0:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f1458a4:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f1458a8:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f1458ac:	001fc880 */ 	sll	$t9,$ra,0x2
/*  f1458b0:	001f7080 */ 	sll	$t6,$ra,0x2
/*  f1458b4:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f1458b8:	01df7021 */ 	addu	$t6,$t6,$ra
/*  f1458bc:	033fc821 */ 	addu	$t9,$t9,$ra
/*  f1458c0:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f1458c4:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f1458c8:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f1458cc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1458d0:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f1458d4:	01194021 */ 	addu	$t0,$t0,$t9
/*  f1458d8:	14600012 */ 	bnez	$v1,.L0f145924
/*  f1458dc:	24e7000a */ 	addiu	$a3,$a3,0xa
/*  f1458e0:	30b90030 */ 	andi	$t9,$a1,0x30
/*  f1458e4:	13200002 */ 	beqz	$t9,.L0f1458f0
/*  f1458e8:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f1458ec:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f1458f0:
/*  f1458f0:	30ce0030 */ 	andi	$t6,$a2,0x30
/*  f1458f4:	11c00004 */ 	beqz	$t6,.L0f145908
/*  f1458f8:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1458fc:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145900:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f145904:	01e09825 */ 	or	$s3,$t7,$zero
.L0f145908:
/*  f145908:	327800ff */ 	andi	$t8,$s3,0xff
/*  f14590c:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f145910:	372e00ff */ 	ori	$t6,$t9,0xff
/*  f145914:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f145918:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14591c:	10000028 */ 	b	.L0f1459c0
/*  f145920:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145924:
/*  f145924:	24010001 */ 	addiu	$at,$zero,0x1
/*  f145928:	14610013 */ 	bne	$v1,$at,.L0f145978
/*  f14592c:	30ae0030 */ 	andi	$t6,$a1,0x30
/*  f145930:	30af0030 */ 	andi	$t7,$a1,0x30
/*  f145934:	11e00002 */ 	beqz	$t7,.L0f145940
/*  f145938:	2413007f */ 	addiu	$s3,$zero,0x7f
/*  f14593c:	241300be */ 	addiu	$s3,$zero,0xbe
.L0f145940:
/*  f145940:	30d80030 */ 	andi	$t8,$a2,0x30
/*  f145944:	13000004 */ 	beqz	$t8,.L0f145958
/*  f145948:	02a01825 */ 	or	$v1,$s5,$zero
/*  f14594c:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f145950:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145954:	03209825 */ 	or	$s3,$t9,$zero
.L0f145958:
/*  f145958:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f14595c:	000e7a00 */ 	sll	$t7,$t6,0x8
/*  f145960:	01ebc025 */ 	or	$t8,$t7,$t3
/*  f145964:	371900ff */ 	ori	$t9,$t8,0xff
/*  f145968:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f14596c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145970:	10000013 */ 	b	.L0f1459c0
/*  f145974:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145978:
/*  f145978:	11c00002 */ 	beqz	$t6,.L0f145984
/*  f14597c:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f145980:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f145984:
/*  f145984:	30cf0030 */ 	andi	$t7,$a2,0x30
/*  f145988:	11e00004 */ 	beqz	$t7,.L0f14599c
/*  f14598c:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145990:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145994:	327800ff */ 	andi	$t8,$s3,0xff
/*  f145998:	03009825 */ 	or	$s3,$t8,$zero
.L0f14599c:
/*  f14599c:	00137883 */ 	sra	$t7,$s3,0x2
/*  f1459a0:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f1459a4:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f1459a8:	00137600 */ 	sll	$t6,$s3,0x18
/*  f1459ac:	01d97825 */ 	or	$t7,$t6,$t9
/*  f1459b0:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f1459b4:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f1459b8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1459bc:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f1459c0:
/*  f1459c0:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f1459c4:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f1459c8:	3c01f600 */ 	lui	$at,0xf600
/*  f1459cc:	03217825 */ 	or	$t7,$t9,$at
/*  f1459d0:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f1459d4:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f1459d8:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f1459dc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1459e0:	032d7825 */ 	or	$t7,$t9,$t5
/*  f1459e4:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f1459e8:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f1459ec:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f1459f0:	8fb802ac */ 	lw	$t8,0x2ac($sp)
/*  f1459f4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1459f8:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f1459fc:	00187080 */ 	sll	$t6,$t8,0x2
/*  f145a00:	01d87021 */ 	addu	$t6,$t6,$t8
/*  f145a04:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f145a08:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f145a0c:	010e4021 */ 	addu	$t0,$t0,$t6
/*  f145a10:	14600012 */ 	bnez	$v1,.L0f145a5c
/*  f145a14:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f145a18:	30b82000 */ 	andi	$t8,$a1,0x2000
/*  f145a1c:	13000002 */ 	beqz	$t8,.L0f145a28
/*  f145a20:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f145a24:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f145a28:
/*  f145a28:	30ce2000 */ 	andi	$t6,$a2,0x2000
/*  f145a2c:	11c00004 */ 	beqz	$t6,.L0f145a40
/*  f145a30:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145a34:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145a38:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145a3c:	03209825 */ 	or	$s3,$t9,$zero
.L0f145a40:
/*  f145a40:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f145a44:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f145a48:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f145a4c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f145a50:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145a54:	10000028 */ 	b	.L0f145af8
/*  f145a58:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145a5c:
/*  f145a5c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f145a60:	14610013 */ 	bne	$v1,$at,.L0f145ab0
/*  f145a64:	30ae2000 */ 	andi	$t6,$a1,0x2000
/*  f145a68:	30b92000 */ 	andi	$t9,$a1,0x2000
/*  f145a6c:	13200002 */ 	beqz	$t9,.L0f145a78
/*  f145a70:	2413007f */ 	addiu	$s3,$zero,0x7f
/*  f145a74:	241300be */ 	addiu	$s3,$zero,0xbe
.L0f145a78:
/*  f145a78:	30cf2000 */ 	andi	$t7,$a2,0x2000
/*  f145a7c:	11e00004 */ 	beqz	$t7,.L0f145a90
/*  f145a80:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145a84:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f145a88:	327800ff */ 	andi	$t8,$s3,0xff
/*  f145a8c:	03009825 */ 	or	$s3,$t8,$zero
.L0f145a90:
/*  f145a90:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f145a94:	000eca00 */ 	sll	$t9,$t6,0x8
/*  f145a98:	032b7825 */ 	or	$t7,$t9,$t3
/*  f145a9c:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f145aa0:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f145aa4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145aa8:	10000013 */ 	b	.L0f145af8
/*  f145aac:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145ab0:
/*  f145ab0:	11c00002 */ 	beqz	$t6,.L0f145abc
/*  f145ab4:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f145ab8:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f145abc:
/*  f145abc:	30d92000 */ 	andi	$t9,$a2,0x2000
/*  f145ac0:	13200004 */ 	beqz	$t9,.L0f145ad4
/*  f145ac4:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145ac8:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f145acc:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f145ad0:	01e09825 */ 	or	$s3,$t7,$zero
.L0f145ad4:
/*  f145ad4:	0013c883 */ 	sra	$t9,$s3,0x2
/*  f145ad8:	332f00ff */ 	andi	$t7,$t9,0xff
/*  f145adc:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f145ae0:	00137600 */ 	sll	$t6,$s3,0x18
/*  f145ae4:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f145ae8:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f145aec:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f145af0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145af4:	ac690000 */ 	sw	$t1,0x0($v1)
.L0f145af8:
/*  f145af8:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f145afc:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f145b00:	3c01f600 */ 	lui	$at,0xf600
/*  f145b04:	0301c825 */ 	or	$t9,$t8,$at
/*  f145b08:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f145b0c:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145b10:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f145b14:	032c7825 */ 	or	$t7,$t9,$t4
/*  f145b18:	030dc825 */ 	or	$t9,$t8,$t5
/*  f145b1c:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f145b20:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f145b24:	26b50008 */ 	addiu	$s5,$s5,0x8
.L0f145b28:
/*  f145b28:	8faf02ac */ 	lw	$t7,0x2ac($sp)
/*  f145b2c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f145b30:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f145b34:	15e10003 */ 	bne	$t7,$at,.L0f145b44
/*  f145b38:	3c0b1020 */ 	lui	$t3,0x1020
/*  f145b3c:	10000002 */ 	b	.L0f145b48
/*  f145b40:	2407ffd0 */ 	addiu	$a3,$zero,-48
.L0f145b44:
/*  f145b44:	2407ffc9 */ 	addiu	$a3,$zero,-55
.L0f145b48:
/*  f145b48:	83ae0251 */ 	lb	$t6,0x251($sp)
/*  f145b4c:	3c0142a0 */ 	lui	$at,0x42a0
/*  f145b50:	44817000 */ 	mtc1	$at,$f14
/*  f145b54:	448e2000 */ 	mtc1	$t6,$f4
/*  f145b58:	3c0142c0 */ 	lui	$at,0x42c0
/*  f145b5c:	44818000 */ 	mtc1	$at,$f16
/*  f145b60:	46802320 */ 	cvt.s.w	$f12,$f4
/*  f145b64:	24010001 */ 	addiu	$at,$zero,0x1
/*  f145b68:	00022600 */ 	sll	$a0,$v0,0x18
/*  f145b6c:	46106202 */ 	mul.s	$f8,$f12,$f16
/*  f145b70:	460e4283 */ 	div.s	$f10,$f8,$f14
/*  f145b74:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f145b78:	44033000 */ 	mfc1	$v1,$f6
/*  f145b7c:	00000000 */ 	nop
/*  f145b80:	04610005 */ 	bgez	$v1,.L0f145b98
/*  f145b84:	307300ff */ 	andi	$s3,$v1,0xff
/*  f145b88:	00039823 */ 	negu	$s3,$v1
/*  f145b8c:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145b90:	10000001 */ 	b	.L0f145b98
/*  f145b94:	03209825 */ 	or	$s3,$t9,$zero
.L0f145b98:
/*  f145b98:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f145b9c:	327800ff */ 	andi	$t8,$s3,0xff
/*  f145ba0:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f145ba4:	8dee0480 */ 	lw	$t6,0x480($t7)
/*  f145ba8:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f145bac:	91c3006b */ 	lbu	$v1,0x6b($t6)
/*  f145bb0:	14600006 */ 	bnez	$v1,.L0f145bcc
/*  f145bb4:	00000000 */ 	nop
/*  f145bb8:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145bbc:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f145bc0:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f145bc4:	10000031 */ 	b	.L0f145c8c
/*  f145bc8:	26b50008 */ 	addiu	$s5,$s5,0x8
.L0f145bcc:
/*  f145bcc:	14610026 */ 	bne	$v1,$at,.L0f145c68
/*  f145bd0:	0013ce00 */ 	sll	$t9,$s3,0x18
/*  f145bd4:	44932000 */ 	mtc1	$s3,$f4
/*  f145bd8:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145bdc:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f145be0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145be4:	06610005 */ 	bgez	$s3,.L0f145bfc
/*  f145be8:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f145bec:	3c014f80 */ 	lui	$at,0x4f80
/*  f145bf0:	44814000 */ 	mtc1	$at,$f8
/*  f145bf4:	00000000 */ 	nop
/*  f145bf8:	46080000 */ 	add.s	$f0,$f0,$f8
.L0f145bfc:
/*  f145bfc:	46100083 */ 	div.s	$f2,$f0,$f16
/*  f145c00:	3c014180 */ 	lui	$at,0x4180
/*  f145c04:	44815000 */ 	mtc1	$at,$f10
/*  f145c08:	3c014200 */ 	lui	$at,0x4200
/*  f145c0c:	44814000 */ 	mtc1	$at,$f8
/*  f145c10:	3c014020 */ 	lui	$at,0x4020
/*  f145c14:	460a1182 */ 	mul.s	$f6,$f2,$f10
/*  f145c18:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f145c1c:	46081282 */ 	mul.s	$f10,$f2,$f8
/*  f145c20:	44192000 */ 	mfc1	$t9,$f4
/*  f145c24:	44812000 */ 	mtc1	$at,$f4
/*  f145c28:	00197e00 */ 	sll	$t7,$t9,0x18
/*  f145c2c:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f145c30:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f145c34:	44183000 */ 	mfc1	$t8,$f6
/*  f145c38:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f145c3c:	331900ff */ 	andi	$t9,$t8,0xff
/*  f145c40:	00197400 */ 	sll	$t6,$t9,0x10
/*  f145c44:	01eec025 */ 	or	$t8,$t7,$t6
/*  f145c48:	440f5000 */ 	mfc1	$t7,$f10
/*  f145c4c:	00000000 */ 	nop
/*  f145c50:	31ee00ff */ 	andi	$t6,$t7,0xff
/*  f145c54:	000eca00 */ 	sll	$t9,$t6,0x8
/*  f145c58:	03197825 */ 	or	$t7,$t8,$t9
/*  f145c5c:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f145c60:	1000000a */ 	b	.L0f145c8c
/*  f145c64:	ac6e0004 */ 	sw	$t6,0x4($v1)
.L0f145c68:
/*  f145c68:	00137883 */ 	sra	$t7,$s3,0x2
/*  f145c6c:	31ee00ff */ 	andi	$t6,$t7,0xff
/*  f145c70:	000ec400 */ 	sll	$t8,$t6,0x10
/*  f145c74:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145c78:	03387825 */ 	or	$t7,$t9,$t8
/*  f145c7c:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f145c80:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f145c84:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f145c88:	26b50008 */ 	addiu	$s5,$s5,0x8
.L0f145c8c:
/*  f145c8c:	8fb902a8 */ 	lw	$t9,0x2a8($sp)
/*  f145c90:	83b80251 */ 	lb	$t8,0x251($sp)
/*  f145c94:	57200050 */ 	bnezl	$t9,.L0f145dd8
/*  f145c98:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f145c9c:	1b000028 */ 	blez	$t8,.L0f145d40
/*  f145ca0:	3c0141e0 */ 	lui	$at,0x41e0
/*  f145ca4:	3c0141e0 */ 	lui	$at,0x41e0
/*  f145ca8:	44819000 */ 	mtc1	$at,$f18
/*  f145cac:	8fb802ac */ 	lw	$t8,0x2ac($sp)
/*  f145cb0:	3c01f600 */ 	lui	$at,0xf600
/*  f145cb4:	46126182 */ 	mul.s	$f6,$f12,$f18
/*  f145cb8:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145cbc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145cc0:	460e3103 */ 	div.s	$f4,$f6,$f14
/*  f145cc4:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f145cc8:	440e4000 */ 	mfc1	$t6,$f8
/*  f145ccc:	00000000 */ 	nop
/*  f145cd0:	01c7c821 */ 	addu	$t9,$t6,$a3
/*  f145cd4:	03380019 */ 	multu	$t9,$t8
/*  f145cd8:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f145cdc:	00007812 */ 	mflo	$t7
/*  f145ce0:	01eec821 */ 	addu	$t9,$t7,$t6
/*  f145ce4:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f145ce8:	8fb90300 */ 	lw	$t9,0x300($sp)
/*  f145cec:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f145cf0:	01e17025 */ 	or	$t6,$t7,$at
/*  f145cf4:	27380015 */ 	addiu	$t8,$t9,0x15
/*  f145cf8:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f145cfc:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f145d00:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f145d04:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f145d08:	8faf02ac */ 	lw	$t7,0x2ac($sp)
/*  f145d0c:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f145d10:	00ef0019 */ 	multu	$a3,$t7
/*  f145d14:	00007012 */ 	mflo	$t6
/*  f145d18:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f145d1c:	8fb90300 */ 	lw	$t9,0x300($sp)
/*  f145d20:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f145d24:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f145d28:	27380013 */ 	addiu	$t8,$t9,0x13
/*  f145d2c:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f145d30:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f145d34:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f145d38:	10000026 */ 	b	.L0f145dd4
/*  f145d3c:	ac780004 */ 	sw	$t8,0x4($v1)
.L0f145d40:
/*  f145d40:	44819000 */ 	mtc1	$at,$f18
/*  f145d44:	8faf02ac */ 	lw	$t7,0x2ac($sp)
/*  f145d48:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f145d4c:	46126282 */ 	mul.s	$f10,$f12,$f18
/*  f145d50:	3c01f600 */ 	lui	$at,0xf600
/*  f145d54:	00ef0019 */ 	multu	$a3,$t7
/*  f145d58:	02a01825 */ 	or	$v1,$s5,$zero
/*  f145d5c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145d60:	460e5183 */ 	div.s	$f6,$f10,$f14
/*  f145d64:	00007012 */ 	mflo	$t6
/*  f145d68:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f145d6c:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f145d70:	8fb80300 */ 	lw	$t8,0x300($sp)
/*  f145d74:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f145d78:	01c1c825 */ 	or	$t9,$t6,$at
/*  f145d7c:	270f0015 */ 	addiu	$t7,$t8,0x15
/*  f145d80:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f145d84:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f145d88:	03387825 */ 	or	$t7,$t9,$t8
/*  f145d8c:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f145d90:	8faf02ac */ 	lw	$t7,0x2ac($sp)
/*  f145d94:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f145d98:	44192000 */ 	mfc1	$t9,$f4
/*  f145d9c:	00000000 */ 	nop
/*  f145da0:	0327c021 */ 	addu	$t8,$t9,$a3
/*  f145da4:	030f0019 */ 	multu	$t8,$t7
/*  f145da8:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f145dac:	00007012 */ 	mflo	$t6
/*  f145db0:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f145db4:	8fb90300 */ 	lw	$t9,0x300($sp)
/*  f145db8:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f145dbc:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f145dc0:	27380013 */ 	addiu	$t8,$t9,0x13
/*  f145dc4:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f145dc8:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f145dcc:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f145dd0:	ac780004 */ 	sw	$t8,0x4($v1)
.L0f145dd4:
/*  f145dd4:	00047e03 */ 	sra	$t7,$a0,0x18
.L0f145dd8:
/*  f145dd8:	01e02025 */ 	or	$a0,$t7,$zero
/*  f145ddc:	44844000 */ 	mtc1	$a0,$f8
/*  f145de0:	3c0141e0 */ 	lui	$at,0x41e0
/*  f145de4:	44819000 */ 	mtc1	$at,$f18
/*  f145de8:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f145dec:	02a01025 */ 	or	$v0,$s5,$zero
/*  f145df0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f145df4:	46106282 */ 	mul.s	$f10,$f12,$f16
/*  f145df8:	460e5183 */ 	div.s	$f6,$f10,$f14
/*  f145dfc:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f145e00:	44032000 */ 	mfc1	$v1,$f4
/*  f145e04:	00000000 */ 	nop
/*  f145e08:	04610005 */ 	bgez	$v1,.L0f145e20
/*  f145e0c:	307300ff */ 	andi	$s3,$v1,0xff
/*  f145e10:	00039823 */ 	negu	$s3,$v1
/*  f145e14:	327900ff */ 	andi	$t9,$s3,0xff
/*  f145e18:	10000001 */ 	b	.L0f145e20
/*  f145e1c:	03209825 */ 	or	$s3,$t9,$zero
.L0f145e20:
/*  f145e20:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f145e24:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f145e28:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f145e2c:	8f0f0480 */ 	lw	$t7,0x480($t8)
/*  f145e30:	373800ff */ 	ori	$t8,$t9,0xff
/*  f145e34:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f145e38:	14600005 */ 	bnez	$v1,.L0f145e50
/*  f145e3c:	00000000 */ 	nop
/*  f145e40:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145e44:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f145e48:	10000031 */ 	b	.L0f145f10
/*  f145e4c:	ac580004 */ 	sw	$t8,0x4($v0)
.L0f145e50:
/*  f145e50:	14610026 */ 	bne	$v1,$at,.L0f145eec
/*  f145e54:	02a01025 */ 	or	$v0,$s5,$zero
/*  f145e58:	44934000 */ 	mtc1	$s3,$f8
/*  f145e5c:	02a01025 */ 	or	$v0,$s5,$zero
/*  f145e60:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f145e64:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145e68:	06610005 */ 	bgez	$s3,.L0f145e80
/*  f145e6c:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f145e70:	3c014f80 */ 	lui	$at,0x4f80
/*  f145e74:	44815000 */ 	mtc1	$at,$f10
/*  f145e78:	00000000 */ 	nop
/*  f145e7c:	460a0000 */ 	add.s	$f0,$f0,$f10
.L0f145e80:
/*  f145e80:	46100083 */ 	div.s	$f2,$f0,$f16
/*  f145e84:	3c014180 */ 	lui	$at,0x4180
/*  f145e88:	44813000 */ 	mtc1	$at,$f6
/*  f145e8c:	3c014200 */ 	lui	$at,0x4200
/*  f145e90:	44815000 */ 	mtc1	$at,$f10
/*  f145e94:	3c014020 */ 	lui	$at,0x4020
/*  f145e98:	46061102 */ 	mul.s	$f4,$f2,$f6
/*  f145e9c:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f145ea0:	460a1182 */ 	mul.s	$f6,$f2,$f10
/*  f145ea4:	44194000 */ 	mfc1	$t9,$f8
/*  f145ea8:	44814000 */ 	mtc1	$at,$f8
/*  f145eac:	0019c600 */ 	sll	$t8,$t9,0x18
/*  f145eb0:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f145eb4:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f145eb8:	440e2000 */ 	mfc1	$t6,$f4
/*  f145ebc:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f145ec0:	31d900ff */ 	andi	$t9,$t6,0xff
/*  f145ec4:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f145ec8:	030f7025 */ 	or	$t6,$t8,$t7
/*  f145ecc:	44183000 */ 	mfc1	$t8,$f6
/*  f145ed0:	00000000 */ 	nop
/*  f145ed4:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f145ed8:	000fca00 */ 	sll	$t9,$t7,0x8
/*  f145edc:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f145ee0:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f145ee4:	1000000a */ 	b	.L0f145f10
/*  f145ee8:	ac4f0004 */ 	sw	$t7,0x4($v0)
.L0f145eec:
/*  f145eec:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f145ef0:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f145ef4:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f145ef8:	0013ce00 */ 	sll	$t9,$s3,0x18
/*  f145efc:	032ec025 */ 	or	$t8,$t9,$t6
/*  f145f00:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f145f04:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f145f08:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145f0c:	ac490000 */ 	sw	$t1,0x0($v0)
.L0f145f10:
/*  f145f10:	8fb902a8 */ 	lw	$t9,0x2a8($sp)
/*  f145f14:	8fae02ac */ 	lw	$t6,0x2ac($sp)
/*  f145f18:	57200042 */ 	bnezl	$t9,.L0f146024
/*  f145f1c:	8ec40284 */ 	lw	$a0,0x284($s6)
/*  f145f20:	00ee0019 */ 	multu	$a3,$t6
/*  f145f24:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f145f28:	0000c012 */ 	mflo	$t8
/*  f145f2c:	030f1821 */ 	addu	$v1,$t8,$t7
/*  f145f30:	307903ff */ 	andi	$t9,$v1,0x3ff
/*  f145f34:	1880001d */ 	blez	$a0,.L0f145fac
/*  f145f38:	00191b80 */ 	sll	$v1,$t9,0xe
/*  f145f3c:	46126102 */ 	mul.s	$f4,$f12,$f18
/*  f145f40:	3c01f600 */ 	lui	$at,0xf600
/*  f145f44:	02a01025 */ 	or	$v0,$s5,$zero
/*  f145f48:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145f4c:	460e2203 */ 	div.s	$f8,$f4,$f14
/*  f145f50:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f145f54:	44185000 */ 	mfc1	$t8,$f10
/*  f145f58:	00000000 */ 	nop
/*  f145f5c:	0307c821 */ 	addu	$t9,$t8,$a3
/*  f145f60:	032e0019 */ 	multu	$t9,$t6
/*  f145f64:	0000c012 */ 	mflo	$t8
/*  f145f68:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f145f6c:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f145f70:	8fb90300 */ 	lw	$t9,0x300($sp)
/*  f145f74:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f145f78:	03017825 */ 	or	$t7,$t8,$at
/*  f145f7c:	272e0018 */ 	addiu	$t6,$t9,0x18
/*  f145f80:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f145f84:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f145f88:	01f97025 */ 	or	$t6,$t7,$t9
/*  f145f8c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f145f90:	8fb80300 */ 	lw	$t8,0x300($sp)
/*  f145f94:	270f0016 */ 	addiu	$t7,$t8,0x16
/*  f145f98:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f145f9c:	00197080 */ 	sll	$t6,$t9,0x2
/*  f145fa0:	006ec025 */ 	or	$t8,$v1,$t6
/*  f145fa4:	1000001e */ 	b	.L0f146020
/*  f145fa8:	ac580004 */ 	sw	$t8,0x4($v0)
.L0f145fac:
/*  f145fac:	46126182 */ 	mul.s	$f6,$f12,$f18
/*  f145fb0:	8fb90300 */ 	lw	$t9,0x300($sp)
/*  f145fb4:	3c01f600 */ 	lui	$at,0xf600
/*  f145fb8:	00617825 */ 	or	$t7,$v1,$at
/*  f145fbc:	272e0018 */ 	addiu	$t6,$t9,0x18
/*  f145fc0:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f145fc4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f145fc8:	460e3103 */ 	div.s	$f4,$f6,$f14
/*  f145fcc:	01f97025 */ 	or	$t6,$t7,$t9
/*  f145fd0:	02a01025 */ 	or	$v0,$s5,$zero
/*  f145fd4:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f145fd8:	8fae02ac */ 	lw	$t6,0x2ac($sp)
/*  f145fdc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f145fe0:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f145fe4:	440f4000 */ 	mfc1	$t7,$f8
/*  f145fe8:	00000000 */ 	nop
/*  f145fec:	01e7c821 */ 	addu	$t9,$t7,$a3
/*  f145ff0:	032e0019 */ 	multu	$t9,$t6
/*  f145ff4:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f145ff8:	0000c012 */ 	mflo	$t8
/*  f145ffc:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f146000:	8faf0300 */ 	lw	$t7,0x300($sp)
/*  f146004:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f146008:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f14600c:	25f90016 */ 	addiu	$t9,$t7,0x16
/*  f146010:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f146014:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f146018:	030fc825 */ 	or	$t9,$t8,$t7
/*  f14601c:	ac590004 */ 	sw	$t9,0x4($v0)
.L0f146020:
/*  f146020:	8ec40284 */ 	lw	$a0,0x284($s6)
.L0f146024:
/*  f146024:	8fb802a8 */ 	lw	$t8,0x2a8($sp)
/*  f146028:	24010002 */ 	addiu	$at,$zero,0x2
/*  f14602c:	8c8e0480 */ 	lw	$t6,0x480($a0)
/*  f146030:	91c3006b */ 	lbu	$v1,0x6b($t6)
/*  f146034:	1460015b */ 	bnez	$v1,.L0f1465a4
/*  f146038:	00000000 */ 	nop
/*  f14603c:	1700030a */ 	bnez	$t8,.L0f146c68
/*  f146040:	c7aa0068 */ 	lwc1	$f10,0x68($sp)
/*  f146044:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f146048:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f14604c:	3c01420c */ 	lui	$at,0x420c
/*  f146050:	44816000 */ 	mtc1	$at,$f12
/*  f146054:	44193000 */ 	mfc1	$t9,$f6
/*  f146058:	25d8fff3 */ 	addiu	$t8,$t6,-13
/*  f14605c:	afb802e8 */ 	sw	$t8,0x2e8($sp)
/*  f146060:	afb902ec */ 	sw	$t9,0x2ec($sp)
/*  f146064:	8c8f0480 */ 	lw	$t7,0x480($a0)
/*  f146068:	3c0143b4 */ 	lui	$at,0x43b4
/*  f14606c:	44817000 */ 	mtc1	$at,$f14
/*  f146070:	c5e0001c */ 	lwc1	$f0,0x1c($t7)
/*  f146074:	3c06f600 */ 	lui	$a2,0xf600
/*  f146078:	02a01825 */ 	or	$v1,$s5,$zero
/*  f14607c:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f146080:	00000000 */ 	nop
/*  f146084:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f146088:	460e2203 */ 	div.s	$f8,$f4,$f14
/*  f14608c:	460e3103 */ 	div.s	$f4,$f6,$f14
/*  f146090:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f146094:	44025000 */ 	mfc1	$v0,$f10
/*  f146098:	00000000 */ 	nop
/*  f14609c:	305300ff */ 	andi	$s3,$v0,0xff
/*  f1460a0:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f1460a4:	44184000 */ 	mfc1	$t8,$f8
/*  f1460a8:	04410005 */ 	bgez	$v0,.L0f1460c0
/*  f1460ac:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f1460b0:	00029823 */ 	negu	$s3,$v0
/*  f1460b4:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f1460b8:	10000001 */ 	b	.L0f1460c0
/*  f1460bc:	01e09825 */ 	or	$s3,$t7,$zero
.L0f1460c0:
/*  f1460c0:	327900ff */ 	andi	$t9,$s3,0xff
/*  f1460c4:	00197400 */ 	sll	$t6,$t9,0x10
/*  f1460c8:	35d800ff */ 	ori	$t8,$t6,0xff
/*  f1460cc:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f1460d0:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1460d4:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f1460d8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1460dc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1460e0:	028fc821 */ 	addu	$t9,$s4,$t7
/*  f1460e4:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1460e8:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f1460ec:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f1460f0:	03067825 */ 	or	$t7,$t8,$a2
/*  f1460f4:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1460f8:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f1460fc:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f146100:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f146104:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f146108:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f14610c:	3c013f00 */ 	lui	$at,0x3f00
/*  f146110:	44811000 */ 	mtc1	$at,$f2
/*  f146114:	01cfc023 */ 	subu	$t8,$t6,$t7
/*  f146118:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f14611c:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f146120:	00197080 */ 	sll	$t6,$t9,0x2
/*  f146124:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f146128:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f14612c:	032e7825 */ 	or	$t7,$t9,$t6
/*  f146130:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f146134:	8fa502ac */ 	lw	$a1,0x2ac($sp)
/*  f146138:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f14613c:	3c013f80 */ 	lui	$at,0x3f80
/*  f146140:	0005c040 */ 	sll	$t8,$a1,0x1
/*  f146144:	03002825 */ 	or	$a1,$t8,$zero
/*  f146148:	03387021 */ 	addu	$t6,$t9,$t8
/*  f14614c:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f146150:	01d47821 */ 	addu	$t7,$t6,$s4
/*  f146154:	afaf02ec */ 	sw	$t7,0x2ec($sp)
/*  f146158:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f14615c:	44819000 */ 	mtc1	$at,$f18
/*  f146160:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146164:	c72a0020 */ 	lwc1	$f10,0x20($t9)
/*  f146168:	02a01825 */ 	or	$v1,$s5,$zero
/*  f14616c:	46125000 */ 	add.s	$f0,$f10,$f18
/*  f146170:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f146174:	00000000 */ 	nop
/*  f146178:	46023102 */ 	mul.s	$f4,$f6,$f2
/*  f14617c:	00000000 */ 	nop
/*  f146180:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f146184:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f146188:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f14618c:	44024000 */ 	mfc1	$v0,$f8
/*  f146190:	00000000 */ 	nop
/*  f146194:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146198:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f14619c:	44182000 */ 	mfc1	$t8,$f4
/*  f1461a0:	04410005 */ 	bgez	$v0,.L0f1461b8
/*  f1461a4:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f1461a8:	00029823 */ 	negu	$s3,$v0
/*  f1461ac:	327900ff */ 	andi	$t9,$s3,0xff
/*  f1461b0:	10000001 */ 	b	.L0f1461b8
/*  f1461b4:	03209825 */ 	or	$s3,$t9,$zero
.L0f1461b8:
/*  f1461b8:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f1461bc:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f1461c0:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f1461c4:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f1461c8:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1461cc:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f1461d0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1461d4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1461d8:	02997021 */ 	addu	$t6,$s4,$t9
/*  f1461dc:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1461e0:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f1461e4:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f1461e8:	0306c825 */ 	or	$t9,$t8,$a2
/*  f1461ec:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1461f0:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1461f4:	03387025 */ 	or	$t6,$t9,$t8
/*  f1461f8:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1461fc:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f146200:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f146204:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146208:	02a01825 */ 	or	$v1,$s5,$zero
/*  f14620c:	01f9c023 */ 	subu	$t8,$t7,$t9
/*  f146210:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f146214:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f146218:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f14621c:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146220:	00187380 */ 	sll	$t6,$t8,0xe
/*  f146224:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f146228:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f14622c:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f146230:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f146234:	03057021 */ 	addu	$t6,$t8,$a1
/*  f146238:	01d47821 */ 	addu	$t7,$t6,$s4
/*  f14623c:	afaf02ec */ 	sw	$t7,0x2ec($sp)
/*  f146240:	8f380480 */ 	lw	$t8,0x480($t9)
/*  f146244:	c7080024 */ 	lwc1	$f8,0x24($t8)
/*  f146248:	46124000 */ 	add.s	$f0,$f8,$f18
/*  f14624c:	46100282 */ 	mul.s	$f10,$f0,$f16
/*  f146250:	00000000 */ 	nop
/*  f146254:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f146258:	00000000 */ 	nop
/*  f14625c:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f146260:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f146264:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f146268:	44022000 */ 	mfc1	$v0,$f4
/*  f14626c:	00000000 */ 	nop
/*  f146270:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146274:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f146278:	44193000 */ 	mfc1	$t9,$f6
/*  f14627c:	04410005 */ 	bgez	$v0,.L0f146294
/*  f146280:	afb902e0 */ 	sw	$t9,0x2e0($sp)
/*  f146284:	00029823 */ 	negu	$s3,$v0
/*  f146288:	327800ff */ 	andi	$t8,$s3,0xff
/*  f14628c:	10000001 */ 	b	.L0f146294
/*  f146290:	03009825 */ 	or	$s3,$t8,$zero
.L0f146294:
/*  f146294:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146298:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f14629c:	35f900ff */ 	ori	$t9,$t7,0xff
/*  f1462a0:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f1462a4:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1462a8:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f1462ac:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1462b0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1462b4:	02987021 */ 	addu	$t6,$s4,$t8
/*  f1462b8:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1462bc:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f1462c0:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f1462c4:	0326c025 */ 	or	$t8,$t9,$a2
/*  f1462c8:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1462cc:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f1462d0:	03197025 */ 	or	$t6,$t8,$t9
/*  f1462d4:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1462d8:	8fb802e0 */ 	lw	$t8,0x2e0($sp)
/*  f1462dc:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f1462e0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1462e4:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1462e8:	01f8c823 */ 	subu	$t9,$t7,$t8
/*  f1462ec:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f1462f0:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1462f4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1462f8:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f1462fc:	00197380 */ 	sll	$t6,$t9,0xe
/*  f146300:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f146304:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f146308:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f14630c:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f146310:	03257021 */ 	addu	$t6,$t9,$a1
/*  f146314:	01d47821 */ 	addu	$t7,$t6,$s4
/*  f146318:	afaf02ec */ 	sw	$t7,0x2ec($sp)
/*  f14631c:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f146320:	c7200028 */ 	lwc1	$f0,0x28($t9)
/*  f146324:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f146328:	00000000 */ 	nop
/*  f14632c:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f146330:	460e2203 */ 	div.s	$f8,$f4,$f14
/*  f146334:	460e3103 */ 	div.s	$f4,$f6,$f14
/*  f146338:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f14633c:	44025000 */ 	mfc1	$v0,$f10
/*  f146340:	00000000 */ 	nop
/*  f146344:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146348:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f14634c:	44184000 */ 	mfc1	$t8,$f8
/*  f146350:	04410005 */ 	bgez	$v0,.L0f146368
/*  f146354:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f146358:	00029823 */ 	negu	$s3,$v0
/*  f14635c:	327900ff */ 	andi	$t9,$s3,0xff
/*  f146360:	10000001 */ 	b	.L0f146368
/*  f146364:	03209825 */ 	or	$s3,$t9,$zero
.L0f146368:
/*  f146368:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f14636c:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f146370:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f146374:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f146378:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f14637c:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f146380:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146384:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146388:	02997021 */ 	addu	$t6,$s4,$t9
/*  f14638c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f146390:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f146394:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f146398:	0306c825 */ 	or	$t9,$t8,$a2
/*  f14639c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f1463a0:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1463a4:	03387025 */ 	or	$t6,$t9,$t8
/*  f1463a8:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1463ac:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f1463b0:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f1463b4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1463b8:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1463bc:	01f9c023 */ 	subu	$t8,$t7,$t9
/*  f1463c0:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f1463c4:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f1463c8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1463cc:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f1463d0:	00187380 */ 	sll	$t6,$t8,0xe
/*  f1463d4:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f1463d8:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f1463dc:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f1463e0:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f1463e4:	03057021 */ 	addu	$t6,$t8,$a1
/*  f1463e8:	01d47821 */ 	addu	$t7,$t6,$s4
/*  f1463ec:	afaf02ec */ 	sw	$t7,0x2ec($sp)
/*  f1463f0:	8f380480 */ 	lw	$t8,0x480($t9)
/*  f1463f4:	c70a002c */ 	lwc1	$f10,0x2c($t8)
/*  f1463f8:	46125000 */ 	add.s	$f0,$f10,$f18
/*  f1463fc:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f146400:	00000000 */ 	nop
/*  f146404:	46023102 */ 	mul.s	$f4,$f6,$f2
/*  f146408:	00000000 */ 	nop
/*  f14640c:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f146410:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f146414:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f146418:	44024000 */ 	mfc1	$v0,$f8
/*  f14641c:	00000000 */ 	nop
/*  f146420:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146424:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f146428:	44192000 */ 	mfc1	$t9,$f4
/*  f14642c:	04410005 */ 	bgez	$v0,.L0f146444
/*  f146430:	afb902e0 */ 	sw	$t9,0x2e0($sp)
/*  f146434:	00029823 */ 	negu	$s3,$v0
/*  f146438:	327800ff */ 	andi	$t8,$s3,0xff
/*  f14643c:	10000001 */ 	b	.L0f146444
/*  f146440:	03009825 */ 	or	$s3,$t8,$zero
.L0f146444:
/*  f146444:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146448:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f14644c:	35f900ff */ 	ori	$t9,$t7,0xff
/*  f146450:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f146454:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146458:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f14645c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146460:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146464:	02987021 */ 	addu	$t6,$s4,$t8
/*  f146468:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f14646c:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f146470:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f146474:	0326c025 */ 	or	$t8,$t9,$a2
/*  f146478:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f14647c:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f146480:	03197025 */ 	or	$t6,$t8,$t9
/*  f146484:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f146488:	8fb802e0 */ 	lw	$t8,0x2e0($sp)
/*  f14648c:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f146490:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146494:	01f8c823 */ 	subu	$t9,$t7,$t8
/*  f146498:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f14649c:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1464a0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1464a4:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f1464a8:	00197380 */ 	sll	$t6,$t9,0xe
/*  f1464ac:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f1464b0:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f1464b4:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f1464b8:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f1464bc:	03257021 */ 	addu	$t6,$t9,$a1
/*  f1464c0:	01d47821 */ 	addu	$t7,$t6,$s4
/*  f1464c4:	afaf02ec */ 	sw	$t7,0x2ec($sp)
/*  f1464c8:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f1464cc:	c7280030 */ 	lwc1	$f8,0x30($t9)
/*  f1464d0:	46124000 */ 	add.s	$f0,$f8,$f18
/*  f1464d4:	46100282 */ 	mul.s	$f10,$f0,$f16
/*  f1464d8:	00000000 */ 	nop
/*  f1464dc:	46025182 */ 	mul.s	$f6,$f10,$f2
/*  f1464e0:	00000000 */ 	nop
/*  f1464e4:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f1464e8:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f1464ec:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f1464f0:	44022000 */ 	mfc1	$v0,$f4
/*  f1464f4:	00000000 */ 	nop
/*  f1464f8:	305300ff */ 	andi	$s3,$v0,0xff
/*  f1464fc:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f146500:	44183000 */ 	mfc1	$t8,$f6
/*  f146504:	04410005 */ 	bgez	$v0,.L0f14651c
/*  f146508:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f14650c:	00029823 */ 	negu	$s3,$v0
/*  f146510:	327900ff */ 	andi	$t9,$s3,0xff
/*  f146514:	10000001 */ 	b	.L0f14651c
/*  f146518:	03209825 */ 	or	$s3,$t9,$zero
.L0f14651c:
/*  f14651c:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146520:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f146524:	02a01025 */ 	or	$v0,$s5,$zero
/*  f146528:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f14652c:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f146530:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f146534:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f146538:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14653c:	02a01825 */ 	or	$v1,$s5,$zero
/*  f146540:	02997021 */ 	addu	$t6,$s4,$t9
/*  f146544:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f146548:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f14654c:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f146550:	0306c825 */ 	or	$t9,$t8,$a2
/*  f146554:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f146558:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f14655c:	03387025 */ 	or	$t6,$t9,$t8
/*  f146560:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f146564:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f146568:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f14656c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146570:	01f9c023 */ 	subu	$t8,$t7,$t9
/*  f146574:	8fb902ec */ 	lw	$t9,0x2ec($sp)
/*  f146578:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f14657c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f146580:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146584:	00187380 */ 	sll	$t6,$t8,0xe
/*  f146588:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f14658c:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f146590:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f146594:	03057021 */ 	addu	$t6,$t8,$a1
/*  f146598:	01d47821 */ 	addu	$t7,$t6,$s4
/*  f14659c:	100001b2 */ 	b	.L0f146c68
/*  f1465a0:	afaf02ec */ 	sw	$t7,0x2ec($sp)
.L0f1465a4:
/*  f1465a4:	14610170 */ 	bne	$v1,$at,.L0f146b68
/*  f1465a8:	c7aa0068 */ 	lwc1	$f10,0x68($sp)
/*  f1465ac:	8fb902a8 */ 	lw	$t9,0x2a8($sp)
/*  f1465b0:	c7a40068 */ 	lwc1	$f4,0x68($sp)
/*  f1465b4:	3c06f600 */ 	lui	$a2,0xf600
/*  f1465b8:	172001ab */ 	bnez	$t9,.L0f146c68
/*  f1465bc:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1465c0:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f1465c4:	8faf02f0 */ 	lw	$t7,0x2f0($sp)
/*  f1465c8:	3c01420c */ 	lui	$at,0x420c
/*  f1465cc:	44816000 */ 	mtc1	$at,$f12
/*  f1465d0:	440e4000 */ 	mfc1	$t6,$f8
/*  f1465d4:	25f9fff3 */ 	addiu	$t9,$t7,-13
/*  f1465d8:	afb902e8 */ 	sw	$t9,0x2e8($sp)
/*  f1465dc:	afae02ec */ 	sw	$t6,0x2ec($sp)
/*  f1465e0:	8c980480 */ 	lw	$t8,0x480($a0)
/*  f1465e4:	3c0143b4 */ 	lui	$at,0x43b4
/*  f1465e8:	44817000 */ 	mtc1	$at,$f14
/*  f1465ec:	c700001c */ 	lwc1	$f0,0x1c($t8)
/*  f1465f0:	46100282 */ 	mul.s	$f10,$f0,$f16
/*  f1465f4:	00000000 */ 	nop
/*  f1465f8:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f1465fc:	460e5183 */ 	div.s	$f6,$f10,$f14
/*  f146600:	460e4283 */ 	div.s	$f10,$f8,$f14
/*  f146604:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f146608:	44022000 */ 	mfc1	$v0,$f4
/*  f14660c:	00000000 */ 	nop
/*  f146610:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146614:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f146618:	44193000 */ 	mfc1	$t9,$f6
/*  f14661c:	04410005 */ 	bgez	$v0,.L0f146634
/*  f146620:	afb902e0 */ 	sw	$t9,0x2e0($sp)
/*  f146624:	00029823 */ 	negu	$s3,$v0
/*  f146628:	327800ff */ 	andi	$t8,$s3,0xff
/*  f14662c:	10000001 */ 	b	.L0f146634
/*  f146630:	03009825 */ 	or	$s3,$t8,$zero
.L0f146634:
/*  f146634:	0013c883 */ 	sra	$t9,$s3,0x2
/*  f146638:	333800ff */ 	andi	$t8,$t9,0xff
/*  f14663c:	00187400 */ 	sll	$t6,$t8,0x10
/*  f146640:	00137e00 */ 	sll	$t7,$s3,0x18
/*  f146644:	01eec825 */ 	or	$t9,$t7,$t6
/*  f146648:	373800ff */ 	ori	$t8,$t9,0xff
/*  f14664c:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f146650:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146654:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f146658:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14665c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146660:	028f7021 */ 	addu	$t6,$s4,$t7
/*  f146664:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146668:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f14666c:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f146670:	03067825 */ 	or	$t7,$t8,$a2
/*  f146674:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146678:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f14667c:	01f87025 */ 	or	$t6,$t7,$t8
/*  f146680:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f146684:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f146688:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f14668c:	3c013f00 */ 	lui	$at,0x3f00
/*  f146690:	44811000 */ 	mtc1	$at,$f2
/*  f146694:	032fc023 */ 	subu	$t8,$t9,$t7
/*  f146698:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f14669c:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f1466a0:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f1466a4:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1466a8:	00187380 */ 	sll	$t6,$t8,0xe
/*  f1466ac:	01d97825 */ 	or	$t7,$t6,$t9
/*  f1466b0:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f1466b4:	8fa502ac */ 	lw	$a1,0x2ac($sp)
/*  f1466b8:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f1466bc:	3c013f80 */ 	lui	$at,0x3f80
/*  f1466c0:	0005c040 */ 	sll	$t8,$a1,0x1
/*  f1466c4:	03002825 */ 	or	$a1,$t8,$zero
/*  f1466c8:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f1466cc:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f1466d0:	03347821 */ 	addu	$t7,$t9,$s4
/*  f1466d4:	afaf02ec */ 	sw	$t7,0x2ec($sp)
/*  f1466d8:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f1466dc:	44819000 */ 	mtc1	$at,$f18
/*  f1466e0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1466e4:	c5c40020 */ 	lwc1	$f4,0x20($t6)
/*  f1466e8:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1466ec:	3c01f600 */ 	lui	$at,0xf600
/*  f1466f0:	46122000 */ 	add.s	$f0,$f4,$f18
/*  f1466f4:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f1466f8:	00000000 */ 	nop
/*  f1466fc:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f146700:	00000000 */ 	nop
/*  f146704:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f146708:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f14670c:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f146710:	44023000 */ 	mfc1	$v0,$f6
/*  f146714:	00000000 */ 	nop
/*  f146718:	305300ff */ 	andi	$s3,$v0,0xff
/*  f14671c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f146720:	44185000 */ 	mfc1	$t8,$f10
/*  f146724:	04410005 */ 	bgez	$v0,.L0f14673c
/*  f146728:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f14672c:	00029823 */ 	negu	$s3,$v0
/*  f146730:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146734:	10000001 */ 	b	.L0f14673c
/*  f146738:	01c09825 */ 	or	$s3,$t6,$zero
.L0f14673c:
/*  f14673c:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f146740:	330e00ff */ 	andi	$t6,$t8,0xff
/*  f146744:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f146748:	00137e00 */ 	sll	$t7,$s3,0x18
/*  f14674c:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f146750:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f146754:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f146758:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f14675c:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f146760:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146764:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146768:	028fc821 */ 	addu	$t9,$s4,$t7
/*  f14676c:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146770:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f146774:	00187380 */ 	sll	$t6,$t8,0xe
/*  f146778:	01c67825 */ 	or	$t7,$t6,$a2
/*  f14677c:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146780:	00187080 */ 	sll	$t6,$t8,0x2
/*  f146784:	01eec825 */ 	or	$t9,$t7,$t6
/*  f146788:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f14678c:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f146790:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f146794:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146798:	02a01825 */ 	or	$v1,$s5,$zero
/*  f14679c:	030f7023 */ 	subu	$t6,$t8,$t7
/*  f1467a0:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f1467a4:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f1467a8:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f1467ac:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f1467b0:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f1467b4:	03387825 */ 	or	$t7,$t9,$t8
/*  f1467b8:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f1467bc:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f1467c0:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f1467c4:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f1467c8:	0334c021 */ 	addu	$t8,$t9,$s4
/*  f1467cc:	afb802ec */ 	sw	$t8,0x2ec($sp)
/*  f1467d0:	8dee0480 */ 	lw	$t6,0x480($t7)
/*  f1467d4:	c5c60024 */ 	lwc1	$f6,0x24($t6)
/*  f1467d8:	46123000 */ 	add.s	$f0,$f6,$f18
/*  f1467dc:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f1467e0:	00000000 */ 	nop
/*  f1467e4:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f1467e8:	00000000 */ 	nop
/*  f1467ec:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f1467f0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f1467f4:	46023102 */ 	mul.s	$f4,$f6,$f2
/*  f1467f8:	44025000 */ 	mfc1	$v0,$f10
/*  f1467fc:	00000000 */ 	nop
/*  f146800:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146804:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f146808:	440f4000 */ 	mfc1	$t7,$f8
/*  f14680c:	04410005 */ 	bgez	$v0,.L0f146824
/*  f146810:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f146814:	00029823 */ 	negu	$s3,$v0
/*  f146818:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f14681c:	10000001 */ 	b	.L0f146824
/*  f146820:	01c09825 */ 	or	$s3,$t6,$zero
.L0f146824:
/*  f146824:	00137883 */ 	sra	$t7,$s3,0x2
/*  f146828:	31ee00ff */ 	andi	$t6,$t7,0xff
/*  f14682c:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f146830:	0013c600 */ 	sll	$t8,$s3,0x18
/*  f146834:	03197825 */ 	or	$t7,$t8,$t9
/*  f146838:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f14683c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f146840:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146844:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f146848:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14684c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146850:	0298c821 */ 	addu	$t9,$s4,$t8
/*  f146854:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f146858:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f14685c:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f146860:	01c6c025 */ 	or	$t8,$t6,$a2
/*  f146864:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f146868:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f14686c:	030ec825 */ 	or	$t9,$t8,$t6
/*  f146870:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f146874:	8fb802e0 */ 	lw	$t8,0x2e0($sp)
/*  f146878:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f14687c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146880:	02a01825 */ 	or	$v1,$s5,$zero
/*  f146884:	01f87023 */ 	subu	$t6,$t7,$t8
/*  f146888:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f14688c:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146890:	00197880 */ 	sll	$t7,$t9,0x2
/*  f146894:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f146898:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f14689c:	032fc025 */ 	or	$t8,$t9,$t7
/*  f1468a0:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f1468a4:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f1468a8:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f1468ac:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f1468b0:	03347821 */ 	addu	$t7,$t9,$s4
/*  f1468b4:	afaf02ec */ 	sw	$t7,0x2ec($sp)
/*  f1468b8:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f1468bc:	c5c00028 */ 	lwc1	$f0,0x28($t6)
/*  f1468c0:	46100282 */ 	mul.s	$f10,$f0,$f16
/*  f1468c4:	00000000 */ 	nop
/*  f1468c8:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f1468cc:	460e5183 */ 	div.s	$f6,$f10,$f14
/*  f1468d0:	460e4283 */ 	div.s	$f10,$f8,$f14
/*  f1468d4:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f1468d8:	44022000 */ 	mfc1	$v0,$f4
/*  f1468dc:	00000000 */ 	nop
/*  f1468e0:	305300ff */ 	andi	$s3,$v0,0xff
/*  f1468e4:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f1468e8:	44183000 */ 	mfc1	$t8,$f6
/*  f1468ec:	04410005 */ 	bgez	$v0,.L0f146904
/*  f1468f0:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f1468f4:	00029823 */ 	negu	$s3,$v0
/*  f1468f8:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f1468fc:	10000001 */ 	b	.L0f146904
/*  f146900:	01c09825 */ 	or	$s3,$t6,$zero
.L0f146904:
/*  f146904:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f146908:	330e00ff */ 	andi	$t6,$t8,0xff
/*  f14690c:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f146910:	00137e00 */ 	sll	$t7,$s3,0x18
/*  f146914:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f146918:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f14691c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f146920:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146924:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f146928:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14692c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146930:	028fc821 */ 	addu	$t9,$s4,$t7
/*  f146934:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146938:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f14693c:	00187380 */ 	sll	$t6,$t8,0xe
/*  f146940:	01c67825 */ 	or	$t7,$t6,$a2
/*  f146944:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146948:	00187080 */ 	sll	$t6,$t8,0x2
/*  f14694c:	01eec825 */ 	or	$t9,$t7,$t6
/*  f146950:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f146954:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f146958:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f14695c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146960:	02a01825 */ 	or	$v1,$s5,$zero
/*  f146964:	030f7023 */ 	subu	$t6,$t8,$t7
/*  f146968:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f14696c:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146970:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f146974:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f146978:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f14697c:	03387825 */ 	or	$t7,$t9,$t8
/*  f146980:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f146984:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f146988:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f14698c:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f146990:	0334c021 */ 	addu	$t8,$t9,$s4
/*  f146994:	afb802ec */ 	sw	$t8,0x2ec($sp)
/*  f146998:	8dee0480 */ 	lw	$t6,0x480($t7)
/*  f14699c:	c5c4002c */ 	lwc1	$f4,0x2c($t6)
/*  f1469a0:	46122000 */ 	add.s	$f0,$f4,$f18
/*  f1469a4:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f1469a8:	00000000 */ 	nop
/*  f1469ac:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f1469b0:	00000000 */ 	nop
/*  f1469b4:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f1469b8:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f1469bc:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f1469c0:	44023000 */ 	mfc1	$v0,$f6
/*  f1469c4:	00000000 */ 	nop
/*  f1469c8:	305300ff */ 	andi	$s3,$v0,0xff
/*  f1469cc:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f1469d0:	440f5000 */ 	mfc1	$t7,$f10
/*  f1469d4:	04410005 */ 	bgez	$v0,.L0f1469ec
/*  f1469d8:	afaf02e0 */ 	sw	$t7,0x2e0($sp)
/*  f1469dc:	00029823 */ 	negu	$s3,$v0
/*  f1469e0:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f1469e4:	10000001 */ 	b	.L0f1469ec
/*  f1469e8:	01c09825 */ 	or	$s3,$t6,$zero
.L0f1469ec:
/*  f1469ec:	00137883 */ 	sra	$t7,$s3,0x2
/*  f1469f0:	31ee00ff */ 	andi	$t6,$t7,0xff
/*  f1469f4:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f1469f8:	0013c600 */ 	sll	$t8,$s3,0x18
/*  f1469fc:	03197825 */ 	or	$t7,$t8,$t9
/*  f146a00:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f146a04:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f146a08:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f146a0c:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f146a10:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146a14:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146a18:	0298c821 */ 	addu	$t9,$s4,$t8
/*  f146a1c:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f146a20:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f146a24:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f146a28:	01c1c025 */ 	or	$t8,$t6,$at
/*  f146a2c:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f146a30:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f146a34:	030ec825 */ 	or	$t9,$t8,$t6
/*  f146a38:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f146a3c:	8fb802e0 */ 	lw	$t8,0x2e0($sp)
/*  f146a40:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f146a44:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146a48:	3c01f600 */ 	lui	$at,0xf600
/*  f146a4c:	01f87023 */ 	subu	$t6,$t7,$t8
/*  f146a50:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f146a54:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146a58:	00197880 */ 	sll	$t7,$t9,0x2
/*  f146a5c:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f146a60:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f146a64:	032fc025 */ 	or	$t8,$t9,$t7
/*  f146a68:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f146a6c:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f146a70:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f146a74:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f146a78:	03347821 */ 	addu	$t7,$t9,$s4
/*  f146a7c:	afaf02ec */ 	sw	$t7,0x2ec($sp)
/*  f146a80:	8f0e0480 */ 	lw	$t6,0x480($t8)
/*  f146a84:	c5c60030 */ 	lwc1	$f6,0x30($t6)
/*  f146a88:	46123000 */ 	add.s	$f0,$f6,$f18
/*  f146a8c:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f146a90:	00000000 */ 	nop
/*  f146a94:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f146a98:	00000000 */ 	nop
/*  f146a9c:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f146aa0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f146aa4:	46023102 */ 	mul.s	$f4,$f6,$f2
/*  f146aa8:	44025000 */ 	mfc1	$v0,$f10
/*  f146aac:	00000000 */ 	nop
/*  f146ab0:	305300ff */ 	andi	$s3,$v0,0xff
/*  f146ab4:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f146ab8:	44184000 */ 	mfc1	$t8,$f8
/*  f146abc:	04410005 */ 	bgez	$v0,.L0f146ad4
/*  f146ac0:	afb802e0 */ 	sw	$t8,0x2e0($sp)
/*  f146ac4:	00029823 */ 	negu	$s3,$v0
/*  f146ac8:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f146acc:	10000001 */ 	b	.L0f146ad4
/*  f146ad0:	01c09825 */ 	or	$s3,$t6,$zero
.L0f146ad4:
/*  f146ad4:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f146ad8:	330e00ff */ 	andi	$t6,$t8,0xff
/*  f146adc:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f146ae0:	00137e00 */ 	sll	$t7,$s3,0x18
/*  f146ae4:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f146ae8:	02a01025 */ 	or	$v0,$s5,$zero
/*  f146aec:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f146af0:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f146af4:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f146af8:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f146afc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146b00:	02a01825 */ 	or	$v1,$s5,$zero
/*  f146b04:	028fc821 */ 	addu	$t9,$s4,$t7
/*  f146b08:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146b0c:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f146b10:	00187380 */ 	sll	$t6,$t8,0xe
/*  f146b14:	01c17825 */ 	or	$t7,$t6,$at
/*  f146b18:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146b1c:	00187080 */ 	sll	$t6,$t8,0x2
/*  f146b20:	01eec825 */ 	or	$t9,$t7,$t6
/*  f146b24:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f146b28:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f146b2c:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f146b30:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146b34:	030f7023 */ 	subu	$t6,$t8,$t7
/*  f146b38:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f146b3c:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f146b40:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f146b44:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f146b48:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f146b4c:	03387825 */ 	or	$t7,$t9,$t8
/*  f146b50:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f146b54:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f146b58:	01c5c821 */ 	addu	$t9,$t6,$a1
/*  f146b5c:	0334c021 */ 	addu	$t8,$t9,$s4
/*  f146b60:	10000041 */ 	b	.L0f146c68
/*  f146b64:	afb802ec */ 	sw	$t8,0x2ec($sp)
.L0f146b68:
/*  f146b68:	3c0140a0 */ 	lui	$at,0x40a0
/*  f146b6c:	44813000 */ 	mtc1	$at,$f6
/*  f146b70:	8fa702ac */ 	lw	$a3,0x2ac($sp)
/*  f146b74:	8fa802f0 */ 	lw	$t0,0x2f0($sp)
/*  f146b78:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f146b7c:	8fb902a8 */ 	lw	$t9,0x2a8($sp)
/*  f146b80:	00077900 */ 	sll	$t7,$a3,0x4
/*  f146b84:	01e77823 */ 	subu	$t7,$t7,$a3
/*  f146b88:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f146b8c:	2508fff3 */ 	addiu	$t0,$t0,-13
/*  f146b90:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f146b94:	000f3840 */ 	sll	$a3,$t7,0x1
/*  f146b98:	44034000 */ 	mfc1	$v1,$f8
/*  f146b9c:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f146ba0:	13200006 */ 	beqz	$t9,.L0f146bbc
/*  f146ba4:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f146ba8:	2463fff4 */ 	addiu	$v1,$v1,-12
/*  f146bac:	2508fffd */ 	addiu	$t0,$t0,-3
/*  f146bb0:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f146bb4:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f146bb8:	2407000f */ 	addiu	$a3,$zero,0xf
.L0f146bbc:
/*  f146bbc:	00002025 */ 	or	$a0,$zero,$zero
/*  f146bc0:	24060008 */ 	addiu	$a2,$zero,0x8
.L0f146bc4:
/*  f146bc4:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f146bc8:	02a01025 */ 	or	$v0,$s5,$zero
/*  f146bcc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146bd0:	8f0f0490 */ 	lw	$t7,0x490($t8)
/*  f146bd4:	008f082a */ 	slt	$at,$a0,$t7
/*  f146bd8:	54200003 */ 	bnezl	$at,.L0f146be8
/*  f146bdc:	30ae00ff */ 	andi	$t6,$a1,0xff
/*  f146be0:	24050088 */ 	addiu	$a1,$zero,0x88
/*  f146be4:	30ae00ff */ 	andi	$t6,$a1,0xff
.L0f146be8:
/*  f146be8:	000eca00 */ 	sll	$t9,$t6,0x8
/*  f146bec:	032bc025 */ 	or	$t8,$t9,$t3
/*  f146bf0:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f146bf4:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f146bf8:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f146bfc:	8fae02ec */ 	lw	$t6,0x2ec($sp)
/*  f146c00:	3c01f600 */ 	lui	$at,0xf600
/*  f146c04:	02a01825 */ 	or	$v1,$s5,$zero
/*  f146c08:	01c7c821 */ 	addu	$t9,$t6,$a3
/*  f146c0c:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146c10:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f146c14:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f146c18:	01e17025 */ 	or	$t6,$t7,$at
/*  f146c1c:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f146c20:	00187880 */ 	sll	$t7,$t8,0x2
/*  f146c24:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f146c28:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f146c2c:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f146c30:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f146c34:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f146c38:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f146c3c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f146c40:	2738fffc */ 	addiu	$t8,$t9,-4
/*  f146c44:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f146c48:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f146c4c:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f146c50:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f146c54:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f146c58:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146c5c:	25cffffb */ 	addiu	$t7,$t6,-5
/*  f146c60:	1486ffd8 */ 	bne	$a0,$a2,.L0f146bc4
/*  f146c64:	afaf02e8 */ 	sw	$t7,0x2e8($sp)
.L0f146c68:
/*  f146c68:	02a01025 */ 	or	$v0,$s5,$zero
/*  f146c6c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146c70:	02a01825 */ 	or	$v1,$s5,$zero
/*  f146c74:	3c19e700 */ 	lui	$t9,0xe700
/*  f146c78:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f146c7c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f146c80:	3c18ba00 */ 	lui	$t8,0xba00
/*  f146c84:	37180602 */ 	ori	$t8,$t8,0x602
/*  f146c88:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146c8c:	240e0040 */ 	addiu	$t6,$zero,0x40
/*  f146c90:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f146c94:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146c98:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f146c9c:	3c0fba00 */ 	lui	$t7,0xba00
/*  f146ca0:	35ef1301 */ 	ori	$t7,$t7,0x1301
/*  f146ca4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146ca8:	3c190008 */ 	lui	$t9,0x8
/*  f146cac:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f146cb0:	02a02825 */ 	or	$a1,$s5,$zero
/*  f146cb4:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f146cb8:	3c18ba00 */ 	lui	$t8,0xba00
/*  f146cbc:	37181001 */ 	ori	$t8,$t8,0x1001
/*  f146cc0:	3c0e0001 */ 	lui	$t6,0x1
/*  f146cc4:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f146cc8:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f146ccc:	8ecf0298 */ 	lw	$t7,0x298($s6)
/*  f146cd0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f146cd4:	05e1017b */ 	bgez	$t7,.L0f1472c4
/*  f146cd8:	00000000 */ 	nop
/*  f146cdc:	8ed9029c */ 	lw	$t9,0x29c($s6)
/*  f146ce0:	8fb802f0 */ 	lw	$t8,0x2f0($sp)
/*  f146ce4:	8fae0300 */ 	lw	$t6,0x300($sp)
/*  f146ce8:	07210176 */ 	bgez	$t9,.L0f1472c4
/*  f146cec:	8fa202f8 */ 	lw	$v0,0x2f8($sp)
/*  f146cf0:	030e7823 */ 	subu	$t7,$t8,$t6
/*  f146cf4:	25f9ff99 */ 	addiu	$t9,$t7,-103
/*  f146cf8:	44995000 */ 	mtc1	$t9,$f10
/*  f146cfc:	3c014188 */ 	lui	$at,0x4188
/*  f146d00:	44810000 */ 	mtc1	$at,$f0
/*  f146d04:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f146d08:	3c013f80 */ 	lui	$at,0x3f80
/*  f146d0c:	44814000 */ 	mtc1	$at,$f8
/*  f146d10:	3c0141c8 */ 	lui	$at,0x41c8
/*  f146d14:	240f0011 */ 	addiu	$t7,$zero,0x11
/*  f146d18:	2419000a */ 	addiu	$t9,$zero,0xa
/*  f146d1c:	46003103 */ 	div.s	$f4,$f6,$f0
/*  f146d20:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146d24:	46082281 */ 	sub.s	$f10,$f4,$f8
/*  f146d28:	c7a402c0 */ 	lwc1	$f4,0x2c0($sp)
/*  f146d2c:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f146d30:	4600518d */ 	trunc.w.s	$f6,$f10
/*  f146d34:	44815000 */ 	mtc1	$at,$f10
/*  f146d38:	44033000 */ 	mfc1	$v1,$f6
/*  f146d3c:	460a4183 */ 	div.s	$f6,$f8,$f10
/*  f146d40:	0060a025 */ 	or	$s4,$v1,$zero
/*  f146d44:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f146d48:	44052000 */ 	mfc1	$a1,$f4
/*  f146d4c:	00000000 */ 	nop
/*  f146d50:	28a10012 */ 	slti	$at,$a1,0x12
/*  f146d54:	54200003 */ 	bnezl	$at,.L0f146d64
/*  f146d58:	240100dc */ 	addiu	$at,$zero,0xdc
/*  f146d5c:	24050011 */ 	addiu	$a1,$zero,0x11
/*  f146d60:	240100dc */ 	addiu	$at,$zero,0xdc
.L0f146d64:
/*  f146d64:	14410003 */ 	bne	$v0,$at,.L0f146d74
/*  f146d68:	01e52823 */ 	subu	$a1,$t7,$a1
/*  f146d6c:	10000008 */ 	b	.L0f146d90
/*  f146d70:	a3b900c7 */ 	sb	$t9,0xc7($sp)
.L0f146d74:
/*  f146d74:	240100b4 */ 	addiu	$at,$zero,0xb4
/*  f146d78:	14410004 */ 	bne	$v0,$at,.L0f146d8c
/*  f146d7c:	2418fff8 */ 	addiu	$t8,$zero,-8
/*  f146d80:	2474ffff */ 	addiu	$s4,$v1,-1
/*  f146d84:	10000002 */ 	b	.L0f146d90
/*  f146d88:	a3b800c7 */ 	sb	$t8,0xc7($sp)
.L0f146d8c:
/*  f146d8c:	a3a000c7 */ 	sb	$zero,0xc7($sp)
.L0f146d90:
/*  f146d90:	0fc351e7 */ 	jal	func0f0d479c
/*  f146d94:	afa500c0 */ 	sw	$a1,0xc0($sp)
/*  f146d98:	3c0eb600 */ 	lui	$t6,0xb600
/*  f146d9c:	240f3000 */ 	addiu	$t7,$zero,0x3000
/*  f146da0:	3c19b700 */ 	lui	$t9,0xb700
/*  f146da4:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f146da8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f146dac:	ac590008 */ 	sw	$t9,0x8($v0)
/*  f146db0:	3c0efcff */ 	lui	$t6,0xfcff
/*  f146db4:	3c0ffffe */ 	lui	$t7,0xfffe
/*  f146db8:	3c19ba00 */ 	lui	$t9,0xba00
/*  f146dbc:	35ef793c */ 	ori	$t7,$t7,0x793c
/*  f146dc0:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f146dc4:	37390c02 */ 	ori	$t9,$t9,0xc02
/*  f146dc8:	24180204 */ 	addiu	$t8,$zero,0x204
/*  f146dcc:	ac4e0010 */ 	sw	$t6,0x10($v0)
/*  f146dd0:	ac4f0014 */ 	sw	$t7,0x14($v0)
/*  f146dd4:	ac590018 */ 	sw	$t9,0x18($v0)
/*  f146dd8:	ac58000c */ 	sw	$t8,0xc($v0)
/*  f146ddc:	3c0eba00 */ 	lui	$t6,0xba00
/*  f146de0:	3c190050 */ 	lui	$t9,0x50
/*  f146de4:	3c0fb900 */ 	lui	$t7,0xb900
/*  f146de8:	24182000 */ 	addiu	$t8,$zero,0x2000
/*  f146dec:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f146df0:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f146df4:	373941c8 */ 	ori	$t9,$t9,0x41c8
/*  f146df8:	ac58001c */ 	sw	$t8,0x1c($v0)
/*  f146dfc:	ac4e0020 */ 	sw	$t6,0x20($v0)
/*  f146e00:	ac400024 */ 	sw	$zero,0x24($v0)
/*  f146e04:	ac59002c */ 	sw	$t9,0x2c($v0)
/*  f146e08:	ac4f0028 */ 	sw	$t7,0x28($v0)
/*  f146e0c:	8fb80300 */ 	lw	$t8,0x300($sp)
/*  f146e10:	8faf02f8 */ 	lw	$t7,0x2f8($sp)
/*  f146e14:	240100b4 */ 	addiu	$at,$zero,0xb4
/*  f146e18:	270e003a */ 	addiu	$t6,$t8,0x3a
/*  f146e1c:	24550030 */ 	addiu	$s5,$v0,0x30
/*  f146e20:	15e10003 */ 	bne	$t7,$at,.L0f146e30
/*  f146e24:	afae02e8 */ 	sw	$t6,0x2e8($sp)
/*  f146e28:	25c80005 */ 	addiu	$t0,$t6,0x5
/*  f146e2c:	afa802e8 */ 	sw	$t0,0x2e8($sp)
.L0f146e30:
/*  f146e30:	8fb902f8 */ 	lw	$t9,0x2f8($sp)
/*  f146e34:	3c013f00 */ 	lui	$at,0x3f00
/*  f146e38:	44813000 */ 	mtc1	$at,$f6
/*  f146e3c:	44994000 */ 	mtc1	$t9,$f8
/*  f146e40:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f146e44:	8fb90304 */ 	lw	$t9,0x304($sp)
/*  f146e48:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f146e4c:	00009025 */ 	or	$s2,$zero,$zero
/*  f146e50:	27380022 */ 	addiu	$t8,$t9,0x22
/*  f146e54:	afb8007c */ 	sw	$t8,0x7c($sp)
/*  f146e58:	46065102 */ 	mul.s	$f4,$f10,$f6
/*  f146e5c:	44813000 */ 	mtc1	$at,$f6
/*  f146e60:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f146e64:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f146e68:	46065102 */ 	mul.s	$f4,$f10,$f6
/*  f146e6c:	440f4000 */ 	mfc1	$t7,$f8
/*  f146e70:	00000000 */ 	nop
/*  f146e74:	01ef0019 */ 	multu	$t7,$t7
/*  f146e78:	afaf0088 */ 	sw	$t7,0x88($sp)
/*  f146e7c:	01e88823 */ 	subu	$s1,$t7,$t0
/*  f146e80:	83af00c7 */ 	lb	$t7,0xc7($sp)
/*  f146e84:	2631000a */ 	addiu	$s1,$s1,0xa
/*  f146e88:	e7a40070 */ 	swc1	$f4,0x70($sp)
/*  f146e8c:	022f8023 */ 	subu	$s0,$s1,$t7
/*  f146e90:	00007012 */ 	mflo	$t6
/*  f146e94:	afae0080 */ 	sw	$t6,0x80($sp)
/*  f146e98:	8fae02ac */ 	lw	$t6,0x2ac($sp)
/*  f146e9c:	448e4000 */ 	mtc1	$t6,$f8
/*  f146ea0:	00000000 */ 	nop
/*  f146ea4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f146ea8:	e7aa006c */ 	swc1	$f10,0x6c($sp)
.L0f146eac:
/*  f146eac:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f146eb0:	24130050 */ 	addiu	$s3,$zero,0x50
/*  f146eb4:	24020056 */ 	addiu	$v0,$zero,0x56
/*  f146eb8:	0244082a */ 	slt	$at,$s2,$a0
/*  f146ebc:	10200003 */ 	beqz	$at,.L0f146ecc
/*  f146ec0:	00000000 */ 	nop
/*  f146ec4:	10000001 */ 	b	.L0f146ecc
/*  f146ec8:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f146ecc:
/*  f146ecc:	0244082a */ 	slt	$at,$s2,$a0
/*  f146ed0:	10200003 */ 	beqz	$at,.L0f146ee0
/*  f146ed4:	00000000 */ 	nop
/*  f146ed8:	10000001 */ 	b	.L0f146ee0
/*  f146edc:	24020022 */ 	addiu	$v0,$zero,0x22
.L0f146ee0:
/*  f146ee0:	02100019 */ 	multu	$s0,$s0
/*  f146ee4:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f146ee8:	8fa3007c */ 	lw	$v1,0x7c($sp)
/*  f146eec:	0114c821 */ 	addu	$t9,$t0,$s4
/*  f146ef0:	afa80228 */ 	sw	$t0,0x228($sp)
/*  f146ef4:	afb90230 */ 	sw	$t9,0x230($sp)
/*  f146ef8:	a3a200d3 */ 	sb	$v0,0xd3($sp)
/*  f146efc:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f146f00:	afa30224 */ 	sw	$v1,0x224($sp)
/*  f146f04:	afa3022c */ 	sw	$v1,0x22c($sp)
/*  f146f08:	00007812 */ 	mflo	$t7
/*  f146f0c:	030f7023 */ 	subu	$t6,$t8,$t7
/*  f146f10:	448e3000 */ 	mtc1	$t6,$f6
/*  f146f14:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f146f18:	0c012974 */ 	jal	sqrtf
/*  f146f1c:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f146f20:	c7a8006c */ 	lwc1	$f8,0x6c($sp)
/*  f146f24:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f146f28:	83af00c7 */ 	lb	$t7,0xc7($sp)
/*  f146f2c:	46080282 */ 	mul.s	$f10,$f0,$f8
/*  f146f30:	02348823 */ 	subu	$s1,$s1,$s4
/*  f146f34:	3c0140a0 */ 	lui	$at,0x40a0
/*  f146f38:	022f8023 */ 	subu	$s0,$s1,$t7
/*  f146f3c:	02100019 */ 	multu	$s0,$s0
/*  f146f40:	44814000 */ 	mtc1	$at,$f8
/*  f146f44:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f146f48:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f146f4c:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f146f50:	0114c021 */ 	addu	$t8,$t0,$s4
/*  f146f54:	afb80238 */ 	sw	$t8,0x238($sp)
/*  f146f58:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f146f5c:	0000c812 */ 	mflo	$t9
/*  f146f60:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f146f64:	01d9c023 */ 	subu	$t8,$t6,$t9
/*  f146f68:	44983000 */ 	mtc1	$t8,$f6
/*  f146f6c:	44035000 */ 	mfc1	$v1,$f10
/*  f146f70:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f146f74:	afa3023c */ 	sw	$v1,0x23c($sp)
/*  f146f78:	0c012974 */ 	jal	sqrtf
/*  f146f7c:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f146f80:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*  f146f84:	c7a80070 */ 	lwc1	$f8,0x70($sp)
/*  f146f88:	3c0140a0 */ 	lui	$at,0x40a0
/*  f146f8c:	46040282 */ 	mul.s	$f10,$f0,$f4
/*  f146f90:	44812000 */ 	mtc1	$at,$f4
/*  f146f94:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f146f98:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f146f9c:	93a200d3 */ 	lbu	$v0,0xd3($sp)
/*  f146fa0:	afb90240 */ 	sw	$t9,0x240($sp)
/*  f146fa4:	2631fffe */ 	addiu	$s1,$s1,-2
/*  f146fa8:	460a4181 */ 	sub.s	$f6,$f8,$f10
/*  f146fac:	2610fffe */ 	addiu	$s0,$s0,-2
/*  f146fb0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f146fb4:	27a50224 */ 	addiu	$a1,$sp,0x224
/*  f146fb8:	46043201 */ 	sub.s	$f8,$f6,$f4
/*  f146fbc:	00003025 */ 	or	$a2,$zero,$zero
/*  f146fc0:	326700ff */ 	andi	$a3,$s3,0xff
/*  f146fc4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f146fc8:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f146fcc:	440e5000 */ 	mfc1	$t6,$f10
/*  f146fd0:	00000000 */ 	nop
/*  f146fd4:	afae02ec */ 	sw	$t6,0x2ec($sp)
/*  f146fd8:	afae0234 */ 	sw	$t6,0x234($sp)
/*  f146fdc:	8f0f0480 */ 	lw	$t7,0x480($t8)
/*  f146fe0:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f146fe4:	14600006 */ 	bnez	$v1,.L0f147000
/*  f146fe8:	00000000 */ 	nop
/*  f146fec:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f146ff0:	0fc50d9e */ 	jal	bviewRenderEyespySideRect
/*  f146ff4:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f146ff8:	10000017 */ 	b	.L0f147058
/*  f146ffc:	0040a825 */ 	or	$s5,$v0,$zero
.L0f147000:
/*  f147000:	1461000c */ 	bne	$v1,$at,.L0f147034
/*  f147004:	02a02025 */ 	or	$a0,$s5,$zero
/*  f147008:	00137080 */ 	sll	$t6,$s3,0x2
/*  f14700c:	01d37023 */ 	subu	$t6,$t6,$s3
/*  f147010:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f147014:	02a02025 */ 	or	$a0,$s5,$zero
/*  f147018:	27a50224 */ 	addiu	$a1,$sp,0x224
/*  f14701c:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f147020:	326700ff */ 	andi	$a3,$s3,0xff
/*  f147024:	0fc50d9e */ 	jal	bviewRenderEyespySideRect
/*  f147028:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f14702c:	1000000a */ 	b	.L0f147058
/*  f147030:	0040a825 */ 	or	$s5,$v0,$zero
.L0f147034:
/*  f147034:	00133883 */ 	sra	$a3,$s3,0x2
/*  f147038:	30f900ff */ 	andi	$t9,$a3,0xff
/*  f14703c:	03203825 */ 	or	$a3,$t9,$zero
/*  f147040:	27a50224 */ 	addiu	$a1,$sp,0x224
/*  f147044:	326600ff */ 	andi	$a2,$s3,0xff
/*  f147048:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f14704c:	0fc50d9e */ 	jal	bviewRenderEyespySideRect
/*  f147050:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f147054:	0040a825 */ 	or	$s5,$v0,$zero
.L0f147058:
/*  f147058:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f14705c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f147060:	2a410011 */ 	slti	$at,$s2,0x11
/*  f147064:	01144021 */ 	addu	$t0,$t0,$s4
/*  f147068:	1420ff90 */ 	bnez	$at,.L0f146eac
/*  f14706c:	25080002 */ 	addiu	$t0,$t0,0x2
/*  f147070:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f147074:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f147078:	3c014188 */ 	lui	$at,0x4188
/*  f14707c:	8f0f0480 */ 	lw	$t7,0x480($t8)
/*  f147080:	44812000 */ 	mtc1	$at,$f4
/*  f147084:	3c017f1b */ 	lui	$at,%hi(var7f1b5f58)
/*  f147088:	c5e60060 */ 	lwc1	$f6,0x60($t7)
/*  f14708c:	c42a5f58 */ 	lwc1	$f10,%lo(var7f1b5f58)($at)
/*  f147090:	24190011 */ 	addiu	$t9,$zero,0x11
/*  f147094:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f147098:	8fa80300 */ 	lw	$t0,0x300($sp)
/*  f14709c:	8fb802f8 */ 	lw	$t8,0x2f8($sp)
/*  f1470a0:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f1470a4:	00009025 */ 	or	$s2,$zero,$zero
/*  f1470a8:	83ae00c7 */ 	lb	$t6,0xc7($sp)
/*  f1470ac:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f1470b0:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f1470b4:	44042000 */ 	mfc1	$a0,$f4
/*  f1470b8:	00000000 */ 	nop
/*  f1470bc:	28810012 */ 	slti	$at,$a0,0x12
/*  f1470c0:	54200003 */ 	bnezl	$at,.L0f1470d0
/*  f1470c4:	240100b4 */ 	addiu	$at,$zero,0xb4
/*  f1470c8:	24040011 */ 	addiu	$a0,$zero,0x11
/*  f1470cc:	240100b4 */ 	addiu	$at,$zero,0xb4
.L0f1470d0:
/*  f1470d0:	03242023 */ 	subu	$a0,$t9,$a0
/*  f1470d4:	17010002 */ 	bne	$t8,$at,.L0f1470e0
/*  f1470d8:	2508002e */ 	addiu	$t0,$t0,0x2e
/*  f1470dc:	25080005 */ 	addiu	$t0,$t0,0x5
.L0f1470e0:
/*  f1470e0:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f1470e4:	01e88823 */ 	subu	$s1,$t7,$t0
/*  f1470e8:	2631000a */ 	addiu	$s1,$s1,0xa
/*  f1470ec:	2738ffde */ 	addiu	$t8,$t9,-34
/*  f1470f0:	afb8007c */ 	sw	$t8,0x7c($sp)
/*  f1470f4:	022e8023 */ 	subu	$s0,$s1,$t6
/*  f1470f8:	afa400c0 */ 	sw	$a0,0xc0($sp)
.L0f1470fc:
/*  f1470fc:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f147100:	24130050 */ 	addiu	$s3,$zero,0x50
/*  f147104:	24020056 */ 	addiu	$v0,$zero,0x56
/*  f147108:	0244082a */ 	slt	$at,$s2,$a0
/*  f14710c:	10200003 */ 	beqz	$at,.L0f14711c
/*  f147110:	8fa3007c */ 	lw	$v1,0x7c($sp)
/*  f147114:	10000001 */ 	b	.L0f14711c
/*  f147118:	24130028 */ 	addiu	$s3,$zero,0x28
.L0f14711c:
/*  f14711c:	0244082a */ 	slt	$at,$s2,$a0
/*  f147120:	10200003 */ 	beqz	$at,.L0f147130
/*  f147124:	00000000 */ 	nop
/*  f147128:	10000001 */ 	b	.L0f147130
/*  f14712c:	24020022 */ 	addiu	$v0,$zero,0x22
.L0f147130:
/*  f147130:	02100019 */ 	multu	$s0,$s0
/*  f147134:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f147138:	01147821 */ 	addu	$t7,$t0,$s4
/*  f14713c:	afa30224 */ 	sw	$v1,0x224($sp)
/*  f147140:	afa80228 */ 	sw	$t0,0x228($sp)
/*  f147144:	afaf0230 */ 	sw	$t7,0x230($sp)
/*  f147148:	afa3022c */ 	sw	$v1,0x22c($sp)
/*  f14714c:	a3a200d3 */ 	sb	$v0,0xd3($sp)
/*  f147150:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f147154:	afa400c0 */ 	sw	$a0,0xc0($sp)
/*  f147158:	0000c812 */ 	mflo	$t9
/*  f14715c:	01d9c023 */ 	subu	$t8,$t6,$t9
/*  f147160:	44984000 */ 	mtc1	$t8,$f8
/*  f147164:	afa802e8 */ 	sw	$t0,0x2e8($sp)
/*  f147168:	0c012974 */ 	jal	sqrtf
/*  f14716c:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f147170:	c7aa006c */ 	lwc1	$f10,0x6c($sp)
/*  f147174:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f147178:	83b900c7 */ 	lb	$t9,0xc7($sp)
/*  f14717c:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f147180:	02348823 */ 	subu	$s1,$s1,$s4
/*  f147184:	3c0140a0 */ 	lui	$at,0x40a0
/*  f147188:	02398023 */ 	subu	$s0,$s1,$t9
/*  f14718c:	02100019 */ 	multu	$s0,$s0
/*  f147190:	44815000 */ 	mtc1	$at,$f10
/*  f147194:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f147198:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f14719c:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f1471a0:	01147021 */ 	addu	$t6,$t0,$s4
/*  f1471a4:	afae0238 */ 	sw	$t6,0x238($sp)
/*  f1471a8:	460a4180 */ 	add.s	$f6,$f8,$f10
/*  f1471ac:	00007812 */ 	mflo	$t7
/*  f1471b0:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f1471b4:	030f7023 */ 	subu	$t6,$t8,$t7
/*  f1471b8:	448e4000 */ 	mtc1	$t6,$f8
/*  f1471bc:	44032000 */ 	mfc1	$v1,$f4
/*  f1471c0:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f1471c4:	afa3023c */ 	sw	$v1,0x23c($sp)
/*  f1471c8:	0c012974 */ 	jal	sqrtf
/*  f1471cc:	afa302ec */ 	sw	$v1,0x2ec($sp)
/*  f1471d0:	c7aa006c */ 	lwc1	$f10,0x6c($sp)
/*  f1471d4:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f1471d8:	3c0140a0 */ 	lui	$at,0x40a0
/*  f1471dc:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f1471e0:	44815000 */ 	mtc1	$at,$f10
/*  f1471e4:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f1471e8:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f1471ec:	93a200d3 */ 	lbu	$v0,0xd3($sp)
/*  f1471f0:	afaf0240 */ 	sw	$t7,0x240($sp)
/*  f1471f4:	2631fffe */ 	addiu	$s1,$s1,-2
/*  f1471f8:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f1471fc:	2610fffe */ 	addiu	$s0,$s0,-2
/*  f147200:	02a02025 */ 	or	$a0,$s5,$zero
/*  f147204:	27a50224 */ 	addiu	$a1,$sp,0x224
/*  f147208:	460a4180 */ 	add.s	$f6,$f8,$f10
/*  f14720c:	00003025 */ 	or	$a2,$zero,$zero
/*  f147210:	326700ff */ 	andi	$a3,$s3,0xff
/*  f147214:	24010001 */ 	addiu	$at,$zero,0x1
/*  f147218:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f14721c:	44182000 */ 	mfc1	$t8,$f4
/*  f147220:	00000000 */ 	nop
/*  f147224:	afb802ec */ 	sw	$t8,0x2ec($sp)
/*  f147228:	afb80234 */ 	sw	$t8,0x234($sp)
/*  f14722c:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f147230:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f147234:	14600006 */ 	bnez	$v1,.L0f147250
/*  f147238:	00000000 */ 	nop
/*  f14723c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f147240:	0fc50d9e */ 	jal	bviewRenderEyespySideRect
/*  f147244:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f147248:	10000017 */ 	b	.L0f1472a8
/*  f14724c:	0040a825 */ 	or	$s5,$v0,$zero
.L0f147250:
/*  f147250:	1461000c */ 	bne	$v1,$at,.L0f147284
/*  f147254:	02a02025 */ 	or	$a0,$s5,$zero
/*  f147258:	0013c080 */ 	sll	$t8,$s3,0x2
/*  f14725c:	0313c023 */ 	subu	$t8,$t8,$s3
/*  f147260:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f147264:	02a02025 */ 	or	$a0,$s5,$zero
/*  f147268:	27a50224 */ 	addiu	$a1,$sp,0x224
/*  f14726c:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f147270:	326700ff */ 	andi	$a3,$s3,0xff
/*  f147274:	0fc50d9e */ 	jal	bviewRenderEyespySideRect
/*  f147278:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f14727c:	1000000a */ 	b	.L0f1472a8
/*  f147280:	0040a825 */ 	or	$s5,$v0,$zero
.L0f147284:
/*  f147284:	00133883 */ 	sra	$a3,$s3,0x2
/*  f147288:	30ef00ff */ 	andi	$t7,$a3,0xff
/*  f14728c:	01e03825 */ 	or	$a3,$t7,$zero
/*  f147290:	27a50224 */ 	addiu	$a1,$sp,0x224
/*  f147294:	326600ff */ 	andi	$a2,$s3,0xff
/*  f147298:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f14729c:	0fc50d9e */ 	jal	bviewRenderEyespySideRect
/*  f1472a0:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f1472a4:	0040a825 */ 	or	$s5,$v0,$zero
.L0f1472a8:
/*  f1472a8:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f1472ac:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1472b0:	24010011 */ 	addiu	$at,$zero,0x11
/*  f1472b4:	01144021 */ 	addu	$t0,$t0,$s4
/*  f1472b8:	1641ff90 */ 	bne	$s2,$at,.L0f1470fc
/*  f1472bc:	25080002 */ 	addiu	$t0,$t0,0x2
/*  f1472c0:	afa802e8 */ 	sw	$t0,0x2e8($sp)
.L0f1472c4:
/*  f1472c4:	0fc35272 */ 	jal	func0f0d49c8
/*  f1472c8:	02a02025 */ 	or	$a0,$s5,$zero
.L0f1472cc:
/*  f1472cc:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f1472d0:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1472d4:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f1472d8:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f1472dc:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f1472e0:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f1472e4:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f1472e8:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f1472ec:	03e00008 */ 	jr	$ra
/*  f1472f0:	27bd0408 */ 	addiu	$sp,$sp,0x408
);
#else
GLOBAL_ASM(
glabel bviewRenderEyespyDecorations
.late_rodata
glabel var7f1b5f4c
.word 0x3a83126f
glabel var7f1b5f50
.word 0x3f19999a
glabel var7f1b5f54
.word 0x3c23d70a
glabel var7f1b5f58
.word 0x3bcccccd
.text
/*  f13e378:	27bdfc10 */ 	addiu	$sp,$sp,-1008
/*  f13e37c:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f13e380:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f13e384:	0080a825 */ 	or	$s5,$a0,$zero
/*  f13e388:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f13e38c:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f13e390:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f13e394:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f13e398:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f13e39c:	0c002fb5 */ 	jal	viGetViewLeft
/*  f13e3a0:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f13e3a4:	0c002fb9 */ 	jal	viGetViewTop
/*  f13e3a8:	afa202ec */ 	sw	$v0,0x2ec($sp)
/*  f13e3ac:	0c002f97 */ 	jal	viGetViewWidth
/*  f13e3b0:	afa202e8 */ 	sw	$v0,0x2e8($sp)
/*  f13e3b4:	0c002f9b */ 	jal	viGetViewHeight
/*  f13e3b8:	00408025 */ 	or	$s0,$v0,$zero
/*  f13e3bc:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f13e3c0:	44800000 */ 	mtc1	$zero,$f0
/*  f13e3c4:	2a010141 */ 	slti	$at,$s0,0x141
/*  f13e3c8:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f13e3cc:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f13e3d0:	afa202e0 */ 	sw	$v0,0x2e0($sp)
/*  f13e3d4:	afb802d8 */ 	sw	$t8,0x2d8($sp)
/*  f13e3d8:	14200004 */ 	bnez	$at,.NB0f13e3ec
/*  f13e3dc:	46000306 */ 	mov.s	$f12,$f0
/*  f13e3e0:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f13e3e4:	10000003 */ 	beqz	$zero,.NB0f13e3f4
/*  f13e3e8:	afb90294 */ 	sw	$t9,0x294($sp)
.NB0f13e3ec:
/*  f13e3ec:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f13e3f0:	afae0294 */ 	sw	$t6,0x294($sp)
.NB0f13e3f4:
/*  f13e3f4:	3c16800a */ 	lui	$s6,0x800a
/*  f13e3f8:	26d6e6c0 */ 	addiu	$s6,$s6,-6464
/*  f13e3fc:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f13e400:	8de70480 */ 	lw	$a3,0x480($t7)
/*  f13e404:	10e00007 */ 	beqz	$a3,.NB0f13e424
/*  f13e408:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e40c:	8ce20000 */ 	lw	$v0,0x0($a3)
/*  f13e410:	10400004 */ 	beqz	$v0,.NB0f13e424
/*  f13e414:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e418:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f13e41c:	54800004 */ 	bnezl	$a0,.NB0f13e430
/*  f13e420:	8ed80298 */ 	lw	$t8,0x298($s6)
.NB0f13e424:
/*  f13e424:	10000dce */ 	beqz	$zero,.NB0f141b60
/*  f13e428:	02a01025 */ 	or	$v0,$s5,$zero
/*  f13e42c:	8ed80298 */ 	lw	$t8,0x298($s6)
.NB0f13e430:
/*  f13e430:	00801825 */ 	or	$v1,$a0,$zero
/*  f13e434:	07030044 */ 	bgezl	$t8,.NB0f13e548
/*  f13e438:	e7a002a8 */ 	swc1	$f0,0x2a8($sp)
/*  f13e43c:	8ed9029c */ 	lw	$t9,0x29c($s6)
/*  f13e440:	3c017f1b */ 	lui	$at,0x7f1b
/*  f13e444:	07230040 */ 	bgezl	$t9,.NB0f13e548
/*  f13e448:	e7a002a8 */ 	swc1	$f0,0x2a8($sp)
/*  f13e44c:	8c82001c */ 	lw	$v0,0x1c($a0)
/*  f13e450:	c48600c8 */ 	lwc1	$f6,0xc8($a0)
/*  f13e454:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f13e458:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f13e45c:	c46600cc */ 	lwc1	$f6,0xcc($v1)
/*  f13e460:	c444000c */ 	lwc1	$f4,0xc($v0)
/*  f13e464:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f13e468:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f13e46c:	44045000 */ 	mfc1	$a0,$f10
/*  f13e470:	c46600d0 */ 	lwc1	$f6,0xd0($v1)
/*  f13e474:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f13e478:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f13e47c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f13e480:	44842000 */ 	mtc1	$a0,$f4
/*  f13e484:	44055000 */ 	mfc1	$a1,$f10
/*  f13e488:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f13e48c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f13e490:	46060032 */ 	c.eq.s	$f0,$f6
/*  f13e494:	44065000 */ 	mfc1	$a2,$f10
/*  f13e498:	4500000f */ 	bc1f	.NB0f13e4d8
/*  f13e49c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e4a0:	44854000 */ 	mtc1	$a1,$f8
/*  f13e4a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e4a8:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f13e4ac:	460a0032 */ 	c.eq.s	$f0,$f10
/*  f13e4b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e4b4:	45000008 */ 	bc1f	.NB0f13e4d8
/*  f13e4b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e4bc:	44862000 */ 	mtc1	$a2,$f4
/*  f13e4c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e4c4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f13e4c8:	46060032 */ 	c.eq.s	$f0,$f6
/*  f13e4cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e4d0:	4501000f */ 	bc1t	.NB0f13e510
/*  f13e4d4:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f13e4d8:
/*  f13e4d8:	00840019 */ 	multu	$a0,$a0
/*  f13e4dc:	0000c812 */ 	mflo	$t9
/*  f13e4e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e4e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e4e8:	00a50019 */ 	multu	$a1,$a1
/*  f13e4ec:	00007012 */ 	mflo	$t6
/*  f13e4f0:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f13e4f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e4f8:	00c60019 */ 	multu	$a2,$a2
/*  f13e4fc:	0000c012 */ 	mflo	$t8
/*  f13e500:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f13e504:	44994000 */ 	mtc1	$t9,$f8
/*  f13e508:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e50c:	46804320 */ 	cvt.s.w	$f12,$f8
.NB0f13e510:
/*  f13e510:	c42a04b0 */ 	lwc1	$f10,0x4b0($at)
/*  f13e514:	460c503c */ 	c.lt.s	$f10,$f12
/*  f13e518:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e51c:	45000007 */ 	bc1f	.NB0f13e53c
/*  f13e520:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e524:	0c012e84 */ 	jal	sqrtf
/*  f13e528:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e52c:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f13e530:	e7a002a8 */ 	swc1	$f0,0x2a8($sp)
/*  f13e534:	10000004 */ 	beqz	$zero,.NB0f13e548
/*  f13e538:	8dc70480 */ 	lw	$a3,0x480($t6)
.NB0f13e53c:
/*  f13e53c:	10000002 */ 	beqz	$zero,.NB0f13e548
/*  f13e540:	e7a002a8 */ 	swc1	$f0,0x2a8($sp)
/*  f13e544:	e7a002a8 */ 	swc1	$f0,0x2a8($sp)
.NB0f13e548:
/*  f13e548:	90e3006b */ 	lbu	$v1,0x6b($a3)
/*  f13e54c:	14600006 */ 	bnez	$v1,.NB0f13e568
/*  f13e550:	3c0500ff */ 	lui	$a1,0xff
/*  f13e554:	34a50028 */ 	ori	$a1,$a1,0x28
/*  f13e558:	0fc537b7 */ 	jal	gfxSetPrimColour
/*  f13e55c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13e560:	1000000e */ 	beqz	$zero,.NB0f13e59c
/*  f13e564:	44903000 */ 	mtc1	$s0,$f6
.NB0f13e568:
/*  f13e568:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13e56c:	14610007 */ 	bne	$v1,$at,.NB0f13e58c
/*  f13e570:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13e574:	3c052244 */ 	lui	$a1,0x2244
/*  f13e578:	34a5ffa0 */ 	ori	$a1,$a1,0xffa0
/*  f13e57c:	0fc537b7 */ 	jal	gfxSetPrimColour
/*  f13e580:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13e584:	10000005 */ 	beqz	$zero,.NB0f13e59c
/*  f13e588:	44903000 */ 	mtc1	$s0,$f6
.NB0f13e58c:
/*  f13e58c:	3c05ff33 */ 	lui	$a1,0xff33
/*  f13e590:	0fc537b7 */ 	jal	gfxSetPrimColour
/*  f13e594:	34a500a0 */ 	ori	$a1,$a1,0xa0
/*  f13e598:	44903000 */ 	mtc1	$s0,$f6
.NB0f13e59c:
/*  f13e59c:	3c013f80 */ 	lui	$at,0x3f80
/*  f13e5a0:	44819000 */ 	mtc1	$at,$f18
/*  f13e5a4:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f13e5a8:	3c0140a0 */ 	lui	$at,0x40a0
/*  f13e5ac:	44814000 */ 	mtc1	$at,$f8
/*  f13e5b0:	8fad02d8 */ 	lw	$t5,0x2d8($sp)
/*  f13e5b4:	8fbf02ec */ 	lw	$ra,0x2ec($sp)
/*  f13e5b8:	3c0cf600 */ 	lui	$t4,0xf600
/*  f13e5bc:	46088003 */ 	div.s	$f0,$f16,$f8
/*  f13e5c0:	25a4ffe8 */ 	addiu	$a0,$t5,-24
/*  f13e5c4:	308f03ff */ 	andi	$t7,$a0,0x3ff
/*  f13e5c8:	27f9001a */ 	addiu	$t9,$ra,0x1a
/*  f13e5cc:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f13e5d0:	000f2080 */ 	sll	$a0,$t7,0x2
/*  f13e5d4:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f13e5d8:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f13e5dc:	27e50019 */ 	addiu	$a1,$ra,0x19
/*  f13e5e0:	44852000 */ 	mtc1	$a1,$f4
/*  f13e5e4:	0304c825 */ 	or	$t9,$t8,$a0
/*  f13e5e8:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f13e5ec:	8fa702e8 */ 	lw	$a3,0x2e8($sp)
/*  f13e5f0:	30a803ff */ 	andi	$t0,$a1,0x3ff
/*  f13e5f4:	00087380 */ 	sll	$t6,$t0,0xe
/*  f13e5f8:	24e70037 */ 	addiu	$a3,$a3,0x37
/*  f13e5fc:	30ef03ff */ 	andi	$t7,$a3,0x3ff
/*  f13e600:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f13e604:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f13e608:	03003825 */ 	or	$a3,$t8,$zero
/*  f13e60c:	01c04025 */ 	or	$t0,$t6,$zero
/*  f13e610:	25a9ffd6 */ 	addiu	$t1,$t5,-42
/*  f13e614:	468020a0 */ 	cvt.s.w	$f2,$f4
/*  f13e618:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f13e61c:	312e03ff */ 	andi	$t6,$t1,0x3ff
/*  f13e620:	27f80020 */ 	addiu	$t8,$ra,0x20
/*  f13e624:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f13e628:	000e4880 */ 	sll	$t1,$t6,0x2
/*  f13e62c:	46001280 */ 	add.s	$f10,$f2,$f0
/*  f13e630:	00197380 */ 	sll	$t6,$t9,0xe
/*  f13e634:	24550008 */ 	addiu	$s5,$v0,0x8
/*  f13e638:	01cc7825 */ 	or	$t7,$t6,$t4
/*  f13e63c:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f13e640:	27ea001f */ 	addiu	$t2,$ra,0x1f
/*  f13e644:	315903ff */ 	andi	$t9,$t2,0x3ff
/*  f13e648:	01e9c025 */ 	or	$t8,$t7,$t1
/*  f13e64c:	02a03025 */ 	or	$a2,$s5,$zero
/*  f13e650:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f13e654:	00195380 */ 	sll	$t2,$t9,0xe
/*  f13e658:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f13e65c:	4458f800 */ 	cfc1	$t8,$31
/*  f13e660:	44d9f800 */ 	ctc1	$t9,$31
/*  f13e664:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13e668:	01477825 */ 	or	$t7,$t2,$a3
/*  f13e66c:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f13e670:	02a05825 */ 	or	$t3,$s5,$zero
/*  f13e674:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f13e678:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13e67c:	4459f800 */ 	cfc1	$t9,$31
/*  f13e680:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e684:	33390078 */ 	andi	$t9,$t9,0x78
/*  f13e688:	13200012 */ 	beqz	$t9,.NB0f13e6d4
/*  f13e68c:	3c014f00 */ 	lui	$at,0x4f00
/*  f13e690:	44813000 */ 	mtc1	$at,$f6
/*  f13e694:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f13e698:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f13e69c:	44d9f800 */ 	ctc1	$t9,$31
/*  f13e6a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e6a4:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f13e6a8:	4459f800 */ 	cfc1	$t9,$31
/*  f13e6ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e6b0:	33390078 */ 	andi	$t9,$t9,0x78
/*  f13e6b4:	17200005 */ 	bnez	$t9,.NB0f13e6cc
/*  f13e6b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e6bc:	44193000 */ 	mfc1	$t9,$f6
/*  f13e6c0:	3c018000 */ 	lui	$at,0x8000
/*  f13e6c4:	10000007 */ 	beqz	$zero,.NB0f13e6e4
/*  f13e6c8:	0321c825 */ 	or	$t9,$t9,$at
.NB0f13e6cc:
/*  f13e6cc:	10000005 */ 	beqz	$zero,.NB0f13e6e4
/*  f13e6d0:	2419ffff */ 	addiu	$t9,$zero,-1
.NB0f13e6d4:
/*  f13e6d4:	44193000 */ 	mfc1	$t9,$f6
/*  f13e6d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e6dc:	0720fffb */ 	bltz	$t9,.NB0f13e6cc
/*  f13e6e0:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f13e6e4:
/*  f13e6e4:	3c0140e0 */ 	lui	$at,0x40e0
/*  f13e6e8:	44d8f800 */ 	ctc1	$t8,$31
/*  f13e6ec:	44814000 */ 	mtc1	$at,$f8
/*  f13e6f0:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f13e6f4:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f13e6f8:	46088303 */ 	div.s	$f12,$f16,$f8
/*  f13e6fc:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f13e700:	0304c825 */ 	or	$t9,$t8,$a0
/*  f13e704:	ad790000 */ 	sw	$t9,0x0($t3)
/*  f13e708:	8fb102d8 */ 	lw	$s1,0x2d8($sp)
/*  f13e70c:	02a01025 */ 	or	$v0,$s5,$zero
/*  f13e710:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13e714:	262effe7 */ 	addiu	$t6,$s1,-25
/*  f13e718:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f13e71c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f13e720:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f13e724:	0118c825 */ 	or	$t9,$t0,$t8
/*  f13e728:	02a01825 */ 	or	$v1,$s5,$zero
/*  f13e72c:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f13e730:	3c04f600 */ 	lui	$a0,0xf600
/*  f13e734:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13e738:	2625ffca */ 	addiu	$a1,$s1,-54
/*  f13e73c:	460c1280 */ 	add.s	$f10,$f2,$f12
/*  f13e740:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f13e744:	444ef800 */ 	cfc1	$t6,$31
/*  f13e748:	44cff800 */ 	ctc1	$t7,$31
/*  f13e74c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e750:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f13e754:	444ff800 */ 	cfc1	$t7,$31
/*  f13e758:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e75c:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f13e760:	11e00012 */ 	beqz	$t7,.NB0f13e7ac
/*  f13e764:	3c014f00 */ 	lui	$at,0x4f00
/*  f13e768:	44813000 */ 	mtc1	$at,$f6
/*  f13e76c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f13e770:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f13e774:	44cff800 */ 	ctc1	$t7,$31
/*  f13e778:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e77c:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f13e780:	444ff800 */ 	cfc1	$t7,$31
/*  f13e784:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e788:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f13e78c:	15e00005 */ 	bnez	$t7,.NB0f13e7a4
/*  f13e790:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e794:	440f3000 */ 	mfc1	$t7,$f6
/*  f13e798:	3c018000 */ 	lui	$at,0x8000
/*  f13e79c:	10000007 */ 	beqz	$zero,.NB0f13e7bc
/*  f13e7a0:	01e17825 */ 	or	$t7,$t7,$at
.NB0f13e7a4:
/*  f13e7a4:	10000005 */ 	beqz	$zero,.NB0f13e7bc
/*  f13e7a8:	240fffff */ 	addiu	$t7,$zero,-1
.NB0f13e7ac:
/*  f13e7ac:	440f3000 */ 	mfc1	$t7,$f6
/*  f13e7b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e7b4:	05e0fffb */ 	bltz	$t7,.NB0f13e7a4
/*  f13e7b8:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f13e7bc:
/*  f13e7bc:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f13e7c0:	44cef800 */ 	ctc1	$t6,$31
/*  f13e7c4:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f13e7c8:	03247025 */ 	or	$t6,$t9,$a0
/*  f13e7cc:	01c97825 */ 	or	$t7,$t6,$t1
/*  f13e7d0:	2638ffd5 */ 	addiu	$t8,$s1,-43
/*  f13e7d4:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f13e7d8:	00197080 */ 	sll	$t6,$t9,0x2
/*  f13e7dc:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f13e7e0:	014e7825 */ 	or	$t7,$t2,$t6
/*  f13e7e4:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f13e7e8:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f13e7ec:	3c01f600 */ 	lui	$at,0xf600
/*  f13e7f0:	02a01025 */ 	or	$v0,$s5,$zero
/*  f13e7f4:	0310f821 */ 	addu	$ra,$t8,$s0
/*  f13e7f8:	27ffffff */ 	addiu	$ra,$ra,-1
/*  f13e7fc:	27f9ffe8 */ 	addiu	$t9,$ra,-24
/*  f13e800:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f13e804:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f13e808:	30b803ff */ 	andi	$t8,$a1,0x3ff
/*  f13e80c:	00182880 */ 	sll	$a1,$t8,0x2
/*  f13e810:	01e46825 */ 	or	$t5,$t7,$a0
/*  f13e814:	01a57025 */ 	or	$t6,$t5,$a1
/*  f13e818:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f13e81c:	8fa602e8 */ 	lw	$a2,0x2e8($sp)
/*  f13e820:	27ecffe7 */ 	addiu	$t4,$ra,-25
/*  f13e824:	319903ff */ 	andi	$t9,$t4,0x3ff
/*  f13e828:	24c60019 */ 	addiu	$a2,$a2,0x19
/*  f13e82c:	30cf03ff */ 	andi	$t7,$a2,0x3ff
/*  f13e830:	448c4000 */ 	mtc1	$t4,$f8
/*  f13e834:	000f3080 */ 	sll	$a2,$t7,0x2
/*  f13e838:	00197380 */ 	sll	$t6,$t9,0xe
/*  f13e83c:	27e4ffe2 */ 	addiu	$a0,$ra,-30
/*  f13e840:	01c67825 */ 	or	$t7,$t6,$a2
/*  f13e844:	309803ff */ 	andi	$t8,$a0,0x3ff
/*  f13e848:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f13e84c:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f13e850:	468040a0 */ 	cvt.s.w	$f2,$f8
/*  f13e854:	8faa02e8 */ 	lw	$t2,0x2e8($sp)
/*  f13e858:	03217025 */ 	or	$t6,$t9,$at
/*  f13e85c:	01c57825 */ 	or	$t7,$t6,$a1
/*  f13e860:	afbf0088 */ 	sw	$ra,0x88($sp)
/*  f13e864:	01c02025 */ 	or	$a0,$t6,$zero
/*  f13e868:	27eeffe1 */ 	addiu	$t6,$ra,-31
/*  f13e86c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f13e870:	2548002b */ 	addiu	$t0,$t2,0x2b
/*  f13e874:	311803ff */ 	andi	$t8,$t0,0x3ff
/*  f13e878:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f13e87c:	00184080 */ 	sll	$t0,$t8,0x2
/*  f13e880:	46001281 */ 	sub.s	$f10,$f2,$f0
/*  f13e884:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f13e888:	254e001a */ 	addiu	$t6,$t2,0x1a
/*  f13e88c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f13e890:	0308c825 */ 	or	$t9,$t8,$t0
/*  f13e894:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f13e898:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f13e89c:	444ef800 */ 	cfc1	$t6,$31
/*  f13e8a0:	44cff800 */ 	ctc1	$t7,$31
/*  f13e8a4:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f13e8a8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13e8ac:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f13e8b0:	02a01825 */ 	or	$v1,$s5,$zero
/*  f13e8b4:	01b8c825 */ 	or	$t9,$t5,$t8
/*  f13e8b8:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f13e8bc:	444ff800 */ 	cfc1	$t7,$31
/*  f13e8c0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13e8c4:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f13e8c8:	11e00012 */ 	beqz	$t7,.NB0f13e914
/*  f13e8cc:	3c014f00 */ 	lui	$at,0x4f00
/*  f13e8d0:	44812000 */ 	mtc1	$at,$f4
/*  f13e8d4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f13e8d8:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f13e8dc:	44cff800 */ 	ctc1	$t7,$31
/*  f13e8e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e8e4:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f13e8e8:	444ff800 */ 	cfc1	$t7,$31
/*  f13e8ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e8f0:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f13e8f4:	15e00005 */ 	bnez	$t7,.NB0f13e90c
/*  f13e8f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e8fc:	440f2000 */ 	mfc1	$t7,$f4
/*  f13e900:	3c018000 */ 	lui	$at,0x8000
/*  f13e904:	10000007 */ 	beqz	$zero,.NB0f13e924
/*  f13e908:	01e17825 */ 	or	$t7,$t7,$at
.NB0f13e90c:
/*  f13e90c:	10000005 */ 	beqz	$zero,.NB0f13e924
/*  f13e910:	240fffff */ 	addiu	$t7,$zero,-1
.NB0f13e914:
/*  f13e914:	440f2000 */ 	mfc1	$t7,$f4
/*  f13e918:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e91c:	05e0fffb */ 	bltz	$t7,.NB0f13e90c
/*  f13e920:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f13e924:
/*  f13e924:	44cef800 */ 	ctc1	$t6,$31
/*  f13e928:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f13e92c:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f13e930:	460c1181 */ 	sub.s	$f6,$f2,$f12
/*  f13e934:	254f002c */ 	addiu	$t7,$t2,0x2c
/*  f13e938:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f13e93c:	03267025 */ 	or	$t6,$t9,$a2
/*  f13e940:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f13e944:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f13e948:	444ff800 */ 	cfc1	$t7,$31
/*  f13e94c:	44d8f800 */ 	ctc1	$t8,$31
/*  f13e950:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f13e954:	00997025 */ 	or	$t6,$a0,$t9
/*  f13e958:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f13e95c:	02a04825 */ 	or	$t1,$s5,$zero
/*  f13e960:	ad2e0000 */ 	sw	$t6,0x0($t1)
/*  f13e964:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13e968:	4458f800 */ 	cfc1	$t8,$31
/*  f13e96c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e970:	33180078 */ 	andi	$t8,$t8,0x78
/*  f13e974:	13000012 */ 	beqz	$t8,.NB0f13e9c0
/*  f13e978:	3c014f00 */ 	lui	$at,0x4f00
/*  f13e97c:	44814000 */ 	mtc1	$at,$f8
/*  f13e980:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f13e984:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f13e988:	44d8f800 */ 	ctc1	$t8,$31
/*  f13e98c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e990:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f13e994:	4458f800 */ 	cfc1	$t8,$31
/*  f13e998:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e99c:	33180078 */ 	andi	$t8,$t8,0x78
/*  f13e9a0:	17000005 */ 	bnez	$t8,.NB0f13e9b8
/*  f13e9a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e9a8:	44184000 */ 	mfc1	$t8,$f8
/*  f13e9ac:	3c018000 */ 	lui	$at,0x8000
/*  f13e9b0:	10000007 */ 	beqz	$zero,.NB0f13e9d0
/*  f13e9b4:	0301c025 */ 	or	$t8,$t8,$at
.NB0f13e9b8:
/*  f13e9b8:	10000005 */ 	beqz	$zero,.NB0f13e9d0
/*  f13e9bc:	2418ffff */ 	addiu	$t8,$zero,-1
.NB0f13e9c0:
/*  f13e9c0:	44184000 */ 	mfc1	$t8,$f8
/*  f13e9c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13e9c8:	0700fffb */ 	bltz	$t8,.NB0f13e9b8
/*  f13e9cc:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f13e9d0:
/*  f13e9d0:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f13e9d4:	44cff800 */ 	ctc1	$t7,$31
/*  f13e9d8:	00197380 */ 	sll	$t6,$t9,0xe
/*  f13e9dc:	01c87825 */ 	or	$t7,$t6,$t0
/*  f13e9e0:	ad2f0004 */ 	sw	$t7,0x4($t1)
/*  f13e9e4:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f13e9e8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f13e9ec:	02a01025 */ 	or	$v0,$s5,$zero
/*  f13e9f0:	44985000 */ 	mtc1	$t8,$f10
/*  f13e9f4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13e9f8:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f13e9fc:	46002180 */ 	add.s	$f6,$f4,$f0
/*  f13ea00:	46123200 */ 	add.s	$f8,$f6,$f18
/*  f13ea04:	4459f800 */ 	cfc1	$t9,$31
/*  f13ea08:	44cef800 */ 	ctc1	$t6,$31
/*  f13ea0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ea10:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f13ea14:	444ef800 */ 	cfc1	$t6,$31
/*  f13ea18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ea1c:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f13ea20:	11c00012 */ 	beqz	$t6,.NB0f13ea6c
/*  f13ea24:	3c014f00 */ 	lui	$at,0x4f00
/*  f13ea28:	44815000 */ 	mtc1	$at,$f10
/*  f13ea2c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f13ea30:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f13ea34:	44cef800 */ 	ctc1	$t6,$31
/*  f13ea38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ea3c:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f13ea40:	444ef800 */ 	cfc1	$t6,$31
/*  f13ea44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ea48:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f13ea4c:	15c00005 */ 	bnez	$t6,.NB0f13ea64
/*  f13ea50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ea54:	440e5000 */ 	mfc1	$t6,$f10
/*  f13ea58:	3c018000 */ 	lui	$at,0x8000
/*  f13ea5c:	10000007 */ 	beqz	$zero,.NB0f13ea7c
/*  f13ea60:	01c17025 */ 	or	$t6,$t6,$at
.NB0f13ea64:
/*  f13ea64:	10000005 */ 	beqz	$zero,.NB0f13ea7c
/*  f13ea68:	240effff */ 	addiu	$t6,$zero,-1
.NB0f13ea6c:
/*  f13ea6c:	440e5000 */ 	mfc1	$t6,$f10
/*  f13ea70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ea74:	05c0fffb */ 	bltz	$t6,.NB0f13ea64
/*  f13ea78:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f13ea7c:
/*  f13ea7c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f13ea80:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f13ea84:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f13ea88:	44d9f800 */ 	ctc1	$t9,$31
/*  f13ea8c:	3c01f600 */ 	lui	$at,0xf600
/*  f13ea90:	0301c825 */ 	or	$t9,$t8,$at
/*  f13ea94:	25cf0038 */ 	addiu	$t7,$t6,0x38
/*  f13ea98:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f13ea9c:	00187080 */ 	sll	$t6,$t8,0x2
/*  f13eaa0:	032e7825 */ 	or	$t7,$t9,$t6
/*  f13eaa4:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f13eaa8:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f13eaac:	02a01825 */ 	or	$v1,$s5,$zero
/*  f13eab0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13eab4:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f13eab8:	00197380 */ 	sll	$t6,$t9,0xe
/*  f13eabc:	01c77825 */ 	or	$t7,$t6,$a3
/*  f13eac0:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f13eac4:	8fb80088 */ 	lw	$t8,0x88($sp)
/*  f13eac8:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f13eacc:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f13ead0:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f13ead4:	01e1c025 */ 	or	$t8,$t7,$at
/*  f13ead8:	0305c825 */ 	or	$t9,$t8,$a1
/*  f13eadc:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f13eae0:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f13eae4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f13eae8:	448e2000 */ 	mtc1	$t6,$f4
/*  f13eaec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13eaf0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f13eaf4:	46003381 */ 	sub.s	$f14,$f6,$f0
/*  f13eaf8:	444ff800 */ 	cfc1	$t7,$31
/*  f13eafc:	44d8f800 */ 	ctc1	$t8,$31
/*  f13eb00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13eb04:	46007224 */ 	cvt.w.s	$f8,$f14
/*  f13eb08:	4458f800 */ 	cfc1	$t8,$31
/*  f13eb0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13eb10:	33180078 */ 	andi	$t8,$t8,0x78
/*  f13eb14:	13000012 */ 	beqz	$t8,.NB0f13eb60
/*  f13eb18:	3c014f00 */ 	lui	$at,0x4f00
/*  f13eb1c:	44814000 */ 	mtc1	$at,$f8
/*  f13eb20:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f13eb24:	46087201 */ 	sub.s	$f8,$f14,$f8
/*  f13eb28:	44d8f800 */ 	ctc1	$t8,$31
/*  f13eb2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13eb30:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f13eb34:	4458f800 */ 	cfc1	$t8,$31
/*  f13eb38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13eb3c:	33180078 */ 	andi	$t8,$t8,0x78
/*  f13eb40:	17000005 */ 	bnez	$t8,.NB0f13eb58
/*  f13eb44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13eb48:	44184000 */ 	mfc1	$t8,$f8
/*  f13eb4c:	3c018000 */ 	lui	$at,0x8000
/*  f13eb50:	10000007 */ 	beqz	$zero,.NB0f13eb70
/*  f13eb54:	0301c025 */ 	or	$t8,$t8,$at
.NB0f13eb58:
/*  f13eb58:	10000005 */ 	beqz	$zero,.NB0f13eb70
/*  f13eb5c:	2418ffff */ 	addiu	$t8,$zero,-1
.NB0f13eb60:
/*  f13eb60:	44184000 */ 	mfc1	$t8,$f8
/*  f13eb64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13eb68:	0700fffb */ 	bltz	$t8,.NB0f13eb58
/*  f13eb6c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f13eb70:
/*  f13eb70:	44cff800 */ 	ctc1	$t7,$31
/*  f13eb74:	8faf02d8 */ 	lw	$t7,0x2d8($sp)
/*  f13eb78:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f13eb7c:	00197380 */ 	sll	$t6,$t9,0xe
/*  f13eb80:	25f8ffc9 */ 	addiu	$t8,$t7,-55
/*  f13eb84:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f13eb88:	00197880 */ 	sll	$t7,$t9,0x2
/*  f13eb8c:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f13eb90:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f13eb94:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f13eb98:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13eb9c:	8f2e0480 */ 	lw	$t6,0x480($t9)
/*  f13eba0:	91c3006b */ 	lbu	$v1,0x6b($t6)
/*  f13eba4:	1461006d */ 	bne	$v1,$at,.NB0f13ed5c
/*  f13eba8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13ebac:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f13ebb0:	00107843 */ 	sra	$t7,$s0,0x1
/*  f13ebb4:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f13ebb8:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f13ebbc:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f13ebc0:	00197043 */ 	sra	$t6,$t9,0x1
/*  f13ebc4:	3c0cf600 */ 	lui	$t4,0xf600
/*  f13ebc8:	01cf2021 */ 	addu	$a0,$t6,$t7
/*  f13ebcc:	24830001 */ 	addiu	$v1,$a0,0x1
/*  f13ebd0:	307803ff */ 	andi	$t8,$v1,0x3ff
/*  f13ebd4:	244e0007 */ 	addiu	$t6,$v0,0x7
/*  f13ebd8:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f13ebdc:	00181880 */ 	sll	$v1,$t8,0x2
/*  f13ebe0:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f13ebe4:	030cc825 */ 	or	$t9,$t8,$t4
/*  f13ebe8:	03237025 */ 	or	$t6,$t9,$v1
/*  f13ebec:	24580002 */ 	addiu	$t8,$v0,0x2
/*  f13ebf0:	308503ff */ 	andi	$a1,$a0,0x3ff
/*  f13ebf4:	02a03025 */ 	or	$a2,$s5,$zero
/*  f13ebf8:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f13ebfc:	00057880 */ 	sll	$t7,$a1,0x2
/*  f13ec00:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f13ec04:	00197380 */ 	sll	$t6,$t9,0xe
/*  f13ec08:	01cf3825 */ 	or	$a3,$t6,$t7
/*  f13ec0c:	01e02825 */ 	or	$a1,$t7,$zero
/*  f13ec10:	244f0005 */ 	addiu	$t7,$v0,0x5
/*  f13ec14:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f13ec18:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f13ec1c:	032c7025 */ 	or	$t6,$t9,$t4
/*  f13ec20:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13ec24:	01c37825 */ 	or	$t7,$t6,$v1
/*  f13ec28:	2458ffff */ 	addiu	$t8,$v0,-1
/*  f13ec2c:	acc70004 */ 	sw	$a3,0x4($a2)
/*  f13ec30:	02a04025 */ 	or	$t0,$s5,$zero
/*  f13ec34:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f13ec38:	ad0f0000 */ 	sw	$t7,0x0($t0)
/*  f13ec3c:	00197380 */ 	sll	$t6,$t9,0xe
/*  f13ec40:	01cc7825 */ 	or	$t7,$t6,$t4
/*  f13ec44:	2458fffa */ 	addiu	$t8,$v0,-6
/*  f13ec48:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f13ec4c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13ec50:	00197380 */ 	sll	$t6,$t9,0xe
/*  f13ec54:	01e35025 */ 	or	$t2,$t7,$v1
/*  f13ec58:	01c57825 */ 	or	$t7,$t6,$a1
/*  f13ec5c:	02a04825 */ 	or	$t1,$s5,$zero
/*  f13ec60:	2458fffc */ 	addiu	$t8,$v0,-4
/*  f13ec64:	ad070004 */ 	sw	$a3,0x4($t0)
/*  f13ec68:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f13ec6c:	ad2f0004 */ 	sw	$t7,0x4($t1)
/*  f13ec70:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13ec74:	00197380 */ 	sll	$t6,$t9,0xe
/*  f13ec78:	24430001 */ 	addiu	$v1,$v0,0x1
/*  f13ec7c:	ad2a0000 */ 	sw	$t2,0x0($t1)
/*  f13ec80:	01c57825 */ 	or	$t7,$t6,$a1
/*  f13ec84:	02a05825 */ 	or	$t3,$s5,$zero
/*  f13ec88:	307803ff */ 	andi	$t8,$v1,0x3ff
/*  f13ec8c:	ad6f0004 */ 	sw	$t7,0x4($t3)
/*  f13ec90:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f13ec94:	248f0007 */ 	addiu	$t7,$a0,0x7
/*  f13ec98:	3c01f600 */ 	lui	$at,0xf600
/*  f13ec9c:	03211825 */ 	or	$v1,$t9,$at
/*  f13eca0:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f13eca4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f13eca8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13ecac:	00797025 */ 	or	$t6,$v1,$t9
/*  f13ecb0:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*  f13ecb4:	02a02825 */ 	or	$a1,$s5,$zero
/*  f13ecb8:	24980002 */ 	addiu	$t8,$a0,0x2
/*  f13ecbc:	304803ff */ 	andi	$t0,$v0,0x3ff
/*  f13ecc0:	00087b80 */ 	sll	$t7,$t0,0xe
/*  f13ecc4:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f13ecc8:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f13eccc:	00197080 */ 	sll	$t6,$t9,0x2
/*  f13ecd0:	01ee3825 */ 	or	$a3,$t7,$t6
/*  f13ecd4:	01e04025 */ 	or	$t0,$t7,$zero
/*  f13ecd8:	248f0005 */ 	addiu	$t7,$a0,0x5
/*  f13ecdc:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f13ece0:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f13ece4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13ece8:	00797025 */ 	or	$t6,$v1,$t9
/*  f13ecec:	aca70004 */ 	sw	$a3,0x4($a1)
/*  f13ecf0:	02a03025 */ 	or	$a2,$s5,$zero
/*  f13ecf4:	248fffff */ 	addiu	$t7,$a0,-1
/*  f13ecf8:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f13ecfc:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f13ed00:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f13ed04:	248efffa */ 	addiu	$t6,$a0,-6
/*  f13ed08:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13ed0c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f13ed10:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f13ed14:	02a04825 */ 	or	$t1,$s5,$zero
/*  f13ed18:	00795025 */ 	or	$t2,$v1,$t9
/*  f13ed1c:	acc70004 */ 	sw	$a3,0x4($a2)
/*  f13ed20:	0118c825 */ 	or	$t9,$t0,$t8
/*  f13ed24:	248efffc */ 	addiu	$t6,$a0,-4
/*  f13ed28:	ad390004 */ 	sw	$t9,0x4($t1)
/*  f13ed2c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13ed30:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f13ed34:	ad2a0000 */ 	sw	$t2,0x0($t1)
/*  f13ed38:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f13ed3c:	02a01025 */ 	or	$v0,$s5,$zero
/*  f13ed40:	0118c825 */ 	or	$t9,$t0,$t8
/*  f13ed44:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f13ed48:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f13ed4c:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f13ed50:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13ed54:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f13ed58:	91e3006b */ 	lbu	$v1,0x6b($t7)
.NB0f13ed5c:
/*  f13ed5c:	1460000a */ 	bnez	$v1,.NB0f13ed88
/*  f13ed60:	24045849 */ 	addiu	$a0,$zero,0x5849
/*  f13ed64:	3c180050 */ 	lui	$t8,0x50
/*  f13ed68:	3c19000f */ 	lui	$t9,0xf
/*  f13ed6c:	3c1400ff */ 	lui	$s4,0xff
/*  f13ed70:	371800ff */ 	ori	$t8,$t8,0xff
/*  f13ed74:	373900ff */ 	ori	$t9,$t9,0xff
/*  f13ed78:	369400a0 */ 	ori	$s4,$s4,0xa0
/*  f13ed7c:	afb8029c */ 	sw	$t8,0x29c($sp)
/*  f13ed80:	1000000f */ 	beqz	$zero,.NB0f13edc0
/*  f13ed84:	afb90298 */ 	sw	$t9,0x298($sp)
.NB0f13ed88:
/*  f13ed88:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13ed8c:	14610007 */ 	bne	$v1,$at,.NB0f13edac
/*  f13ed90:	3c02ff33 */ 	lui	$v0,0xff33
/*  f13ed94:	3c022244 */ 	lui	$v0,0x2244
/*  f13ed98:	3454ffff */ 	ori	$s4,$v0,0xffff
/*  f13ed9c:	240e0fff */ 	addiu	$t6,$zero,0xfff
/*  f13eda0:	afb4029c */ 	sw	$s4,0x29c($sp)
/*  f13eda4:	10000006 */ 	beqz	$zero,.NB0f13edc0
/*  f13eda8:	afae0298 */ 	sw	$t6,0x298($sp)
.NB0f13edac:
/*  f13edac:	3c0f0f00 */ 	lui	$t7,0xf00
/*  f13edb0:	345400ff */ 	ori	$s4,$v0,0xff
/*  f13edb4:	35ef00ff */ 	ori	$t7,$t7,0xff
/*  f13edb8:	afb4029c */ 	sw	$s4,0x29c($sp)
/*  f13edbc:	afaf0298 */ 	sw	$t7,0x298($sp)
.NB0f13edc0:
/*  f13edc0:	e7ae0060 */ 	swc1	$f14,0x60($sp)
/*  f13edc4:	0fc5a4dd */ 	jal	langGet
/*  f13edc8:	e7b00070 */ 	swc1	$f16,0x70($sp)
/*  f13edcc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f13edd0:	c42404b4 */ 	lwc1	$f4,0x4b4($at)
/*  f13edd4:	c7aa02a8 */ 	lwc1	$f10,0x2a8($sp)
/*  f13edd8:	27b302f0 */ 	addiu	$s3,$sp,0x2f0
/*  f13eddc:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f13ede0:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f13ede4:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f13ede8:	24e70340 */ 	addiu	$a3,$a3,0x340
/*  f13edec:	24a50334 */ 	addiu	$a1,$a1,0x334
/*  f13edf0:	02602025 */ 	or	$a0,$s3,$zero
/*  f13edf4:	00403025 */ 	or	$a2,$v0,$zero
/*  f13edf8:	46003221 */ 	cvt.d.s	$f8,$f6
/*  f13edfc:	0c004fc1 */ 	jal	sprintf
/*  f13ee00:	f7a80010 */ 	sdc1	$f8,0x10($sp)
/*  f13ee04:	3c188008 */ 	lui	$t8,0x8008
/*  f13ee08:	8f182364 */ 	lw	$t8,0x2364($t8)
/*  f13ee0c:	3c078008 */ 	lui	$a3,0x8008
/*  f13ee10:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f13ee14:	27a402c8 */ 	addiu	$a0,$sp,0x2c8
/*  f13ee18:	27a502cc */ 	addiu	$a1,$sp,0x2cc
/*  f13ee1c:	02603025 */ 	or	$a2,$s3,$zero
/*  f13ee20:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f13ee24:	0fc54655 */ 	jal	textMeasure
/*  f13ee28:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f13ee2c:	8fb90294 */ 	lw	$t9,0x294($sp)
/*  f13ee30:	8faf02ec */ 	lw	$t7,0x2ec($sp)
/*  f13ee34:	8fb202e8 */ 	lw	$s2,0x2e8($sp)
/*  f13ee38:	00197080 */ 	sll	$t6,$t9,0x2
/*  f13ee3c:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f13ee40:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f13ee44:	01d97021 */ 	addu	$t6,$t6,$t9
/*  f13ee48:	8fb802cc */ 	lw	$t8,0x2cc($sp)
/*  f13ee4c:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f13ee50:	8fae02c8 */ 	lw	$t6,0x2c8($sp)
/*  f13ee54:	2652000e */ 	addiu	$s2,$s2,0xe
/*  f13ee58:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f13ee5c:	27b802c0 */ 	addiu	$t8,$sp,0x2c0
/*  f13ee60:	024e7821 */ 	addu	$t7,$s2,$t6
/*  f13ee64:	afaf02c0 */ 	sw	$t7,0x2c0($sp)
/*  f13ee68:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f13ee6c:	afb902c4 */ 	sw	$t9,0x2c4($sp)
/*  f13ee70:	afb202d0 */ 	sw	$s2,0x2d0($sp)
/*  f13ee74:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f13ee78:	afa202d4 */ 	sw	$v0,0x2d4($sp)
/*  f13ee7c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13ee80:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13ee84:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13ee88:	0fc537d6 */ 	jal	func0f153858
/*  f13ee8c:	27a702c4 */ 	addiu	$a3,$sp,0x2c4
/*  f13ee90:	0c002f77 */ 	jal	viGetWidth
/*  f13ee94:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13ee98:	00028400 */ 	sll	$s0,$v0,0x10
/*  f13ee9c:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f13eea0:	0c002f7b */ 	jal	viGetHeight
/*  f13eea4:	03208025 */ 	or	$s0,$t9,$zero
/*  f13eea8:	3c0e8008 */ 	lui	$t6,0x8008
/*  f13eeac:	3c0f8008 */ 	lui	$t7,0x8008
/*  f13eeb0:	8def2364 */ 	lw	$t7,0x2364($t7)
/*  f13eeb4:	8dce2368 */ 	lw	$t6,0x2368($t6)
/*  f13eeb8:	8fb80298 */ 	lw	$t8,0x298($sp)
/*  f13eebc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13eec0:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13eec4:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13eec8:	02603825 */ 	or	$a3,$s3,$zero
/*  f13eecc:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f13eed0:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f13eed4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f13eed8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f13eedc:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f13eee0:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f13eee4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f13eee8:	0fc54529 */ 	jal	textRender
/*  f13eeec:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f13eef0:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13eef4:	0fc5a4dd */ 	jal	langGet
/*  f13eef8:	2404584a */ 	addiu	$a0,$zero,0x584a
/*  f13eefc:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f13ef00:	3c017f1b */ 	lui	$at,0x7f1b
/*  f13ef04:	c42404b8 */ 	lwc1	$f4,0x4b8($at)
/*  f13ef08:	8f2e0480 */ 	lw	$t6,0x480($t9)
/*  f13ef0c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f13ef10:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f13ef14:	c5ca0060 */ 	lwc1	$f10,0x60($t6)
/*  f13ef18:	24e70350 */ 	addiu	$a3,$a3,0x350
/*  f13ef1c:	24a50344 */ 	addiu	$a1,$a1,0x344
/*  f13ef20:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f13ef24:	02602025 */ 	or	$a0,$s3,$zero
/*  f13ef28:	00403025 */ 	or	$a2,$v0,$zero
/*  f13ef2c:	46003221 */ 	cvt.d.s	$f8,$f6
/*  f13ef30:	0c004fc1 */ 	jal	sprintf
/*  f13ef34:	f7a80010 */ 	sdc1	$f8,0x10($sp)
/*  f13ef38:	3c0f8008 */ 	lui	$t7,0x8008
/*  f13ef3c:	8def2364 */ 	lw	$t7,0x2364($t7)
/*  f13ef40:	3c078008 */ 	lui	$a3,0x8008
/*  f13ef44:	26510009 */ 	addiu	$s1,$s2,0x9
/*  f13ef48:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f13ef4c:	27a402c8 */ 	addiu	$a0,$sp,0x2c8
/*  f13ef50:	27a502cc */ 	addiu	$a1,$sp,0x2cc
/*  f13ef54:	02603025 */ 	or	$a2,$s3,$zero
/*  f13ef58:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f13ef5c:	0fc54655 */ 	jal	textMeasure
/*  f13ef60:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f13ef64:	8fa30080 */ 	lw	$v1,0x80($sp)
/*  f13ef68:	8fb802cc */ 	lw	$t8,0x2cc($sp)
/*  f13ef6c:	8fae02c8 */ 	lw	$t6,0x2c8($sp)
/*  f13ef70:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13ef74:	0078c821 */ 	addu	$t9,$v1,$t8
/*  f13ef78:	27b802c0 */ 	addiu	$t8,$sp,0x2c0
/*  f13ef7c:	022e7821 */ 	addu	$t7,$s1,$t6
/*  f13ef80:	afaf02c0 */ 	sw	$t7,0x2c0($sp)
/*  f13ef84:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f13ef88:	afb902c4 */ 	sw	$t9,0x2c4($sp)
/*  f13ef8c:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13ef90:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13ef94:	27a702c4 */ 	addiu	$a3,$sp,0x2c4
/*  f13ef98:	afb102d0 */ 	sw	$s1,0x2d0($sp)
/*  f13ef9c:	0fc537d6 */ 	jal	func0f153858
/*  f13efa0:	afa302d4 */ 	sw	$v1,0x2d4($sp)
/*  f13efa4:	0c002f77 */ 	jal	viGetWidth
/*  f13efa8:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13efac:	00028400 */ 	sll	$s0,$v0,0x10
/*  f13efb0:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f13efb4:	0c002f7b */ 	jal	viGetHeight
/*  f13efb8:	03208025 */ 	or	$s0,$t9,$zero
/*  f13efbc:	3c0e8008 */ 	lui	$t6,0x8008
/*  f13efc0:	3c0f8008 */ 	lui	$t7,0x8008
/*  f13efc4:	8def2364 */ 	lw	$t7,0x2364($t7)
/*  f13efc8:	8dce2368 */ 	lw	$t6,0x2368($t6)
/*  f13efcc:	8fb80298 */ 	lw	$t8,0x298($sp)
/*  f13efd0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13efd4:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13efd8:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13efdc:	02603825 */ 	or	$a3,$s3,$zero
/*  f13efe0:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f13efe4:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f13efe8:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f13efec:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f13eff0:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f13eff4:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f13eff8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f13effc:	0fc54529 */ 	jal	textRender
/*  f13f000:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f13f004:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13f008:	0fc5a4dd */ 	jal	langGet
/*  f13f00c:	2404584b */ 	addiu	$a0,$zero,0x584b
/*  f13f010:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f13f014:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f13f018:	24a50354 */ 	addiu	$a1,$a1,0x354
/*  f13f01c:	8f2e0480 */ 	lw	$t6,0x480($t9)
/*  f13f020:	02602025 */ 	or	$a0,$s3,$zero
/*  f13f024:	00403025 */ 	or	$a2,$v0,$zero
/*  f13f028:	c5ca001c */ 	lwc1	$f10,0x1c($t6)
/*  f13f02c:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f13f030:	44072000 */ 	mfc1	$a3,$f4
/*  f13f034:	0c004fc1 */ 	jal	sprintf
/*  f13f038:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f03c:	3c188008 */ 	lui	$t8,0x8008
/*  f13f040:	8f182364 */ 	lw	$t8,0x2364($t8)
/*  f13f044:	3c078008 */ 	lui	$a3,0x8008
/*  f13f048:	26310009 */ 	addiu	$s1,$s1,0x9
/*  f13f04c:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f13f050:	27a402c8 */ 	addiu	$a0,$sp,0x2c8
/*  f13f054:	27a502cc */ 	addiu	$a1,$sp,0x2cc
/*  f13f058:	02603025 */ 	or	$a2,$s3,$zero
/*  f13f05c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f13f060:	0fc54655 */ 	jal	textMeasure
/*  f13f064:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f13f068:	8fa30080 */ 	lw	$v1,0x80($sp)
/*  f13f06c:	8fb902cc */ 	lw	$t9,0x2cc($sp)
/*  f13f070:	8faf02c8 */ 	lw	$t7,0x2c8($sp)
/*  f13f074:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13f078:	00797021 */ 	addu	$t6,$v1,$t9
/*  f13f07c:	27b902c0 */ 	addiu	$t9,$sp,0x2c0
/*  f13f080:	022fc021 */ 	addu	$t8,$s1,$t7
/*  f13f084:	afb802c0 */ 	sw	$t8,0x2c0($sp)
/*  f13f088:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f13f08c:	afae02c4 */ 	sw	$t6,0x2c4($sp)
/*  f13f090:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13f094:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13f098:	27a702c4 */ 	addiu	$a3,$sp,0x2c4
/*  f13f09c:	afb102d0 */ 	sw	$s1,0x2d0($sp)
/*  f13f0a0:	0fc537d6 */ 	jal	func0f153858
/*  f13f0a4:	afa302d4 */ 	sw	$v1,0x2d4($sp)
/*  f13f0a8:	0c002f77 */ 	jal	viGetWidth
/*  f13f0ac:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13f0b0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f13f0b4:	00107403 */ 	sra	$t6,$s0,0x10
/*  f13f0b8:	0c002f7b */ 	jal	viGetHeight
/*  f13f0bc:	01c08025 */ 	or	$s0,$t6,$zero
/*  f13f0c0:	3c0f8008 */ 	lui	$t7,0x8008
/*  f13f0c4:	3c188008 */ 	lui	$t8,0x8008
/*  f13f0c8:	8f182364 */ 	lw	$t8,0x2364($t8)
/*  f13f0cc:	8def2368 */ 	lw	$t7,0x2368($t7)
/*  f13f0d0:	8fb90298 */ 	lw	$t9,0x298($sp)
/*  f13f0d4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13f0d8:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13f0dc:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13f0e0:	02603825 */ 	or	$a3,$s3,$zero
/*  f13f0e4:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f13f0e8:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f13f0ec:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f13f0f0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f13f0f4:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f13f0f8:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f13f0fc:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f13f100:	0fc54529 */ 	jal	textRender
/*  f13f104:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f13f108:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13f10c:	0fc5a4dd */ 	jal	langGet
/*  f13f110:	2404584c */ 	addiu	$a0,$zero,0x584c
/*  f13f114:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f13f118:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f13f11c:	24a5035c */ 	addiu	$a1,$a1,0x35c
/*  f13f120:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f13f124:	02602025 */ 	or	$a0,$s3,$zero
/*  f13f128:	00403025 */ 	or	$a2,$v0,$zero
/*  f13f12c:	c5e60028 */ 	lwc1	$f6,0x28($t7)
/*  f13f130:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f13f134:	44074000 */ 	mfc1	$a3,$f8
/*  f13f138:	0c004fc1 */ 	jal	sprintf
/*  f13f13c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f140:	3c198008 */ 	lui	$t9,0x8008
/*  f13f144:	8f392364 */ 	lw	$t9,0x2364($t9)
/*  f13f148:	3c078008 */ 	lui	$a3,0x8008
/*  f13f14c:	26310009 */ 	addiu	$s1,$s1,0x9
/*  f13f150:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f13f154:	27a402c8 */ 	addiu	$a0,$sp,0x2c8
/*  f13f158:	27a502cc */ 	addiu	$a1,$sp,0x2cc
/*  f13f15c:	02603025 */ 	or	$a2,$s3,$zero
/*  f13f160:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f13f164:	0fc54655 */ 	jal	textMeasure
/*  f13f168:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f13f16c:	8fa30080 */ 	lw	$v1,0x80($sp)
/*  f13f170:	8fae02cc */ 	lw	$t6,0x2cc($sp)
/*  f13f174:	8fb802c8 */ 	lw	$t8,0x2c8($sp)
/*  f13f178:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13f17c:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f13f180:	27ae02c0 */ 	addiu	$t6,$sp,0x2c0
/*  f13f184:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f13f188:	afb902c0 */ 	sw	$t9,0x2c0($sp)
/*  f13f18c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f13f190:	afaf02c4 */ 	sw	$t7,0x2c4($sp)
/*  f13f194:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13f198:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13f19c:	27a702c4 */ 	addiu	$a3,$sp,0x2c4
/*  f13f1a0:	afb102d0 */ 	sw	$s1,0x2d0($sp)
/*  f13f1a4:	0fc537d6 */ 	jal	func0f153858
/*  f13f1a8:	afa302d4 */ 	sw	$v1,0x2d4($sp)
/*  f13f1ac:	0c002f77 */ 	jal	viGetWidth
/*  f13f1b0:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13f1b4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f13f1b8:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f13f1bc:	0c002f7b */ 	jal	viGetHeight
/*  f13f1c0:	01e08025 */ 	or	$s0,$t7,$zero
/*  f13f1c4:	3c188008 */ 	lui	$t8,0x8008
/*  f13f1c8:	3c198008 */ 	lui	$t9,0x8008
/*  f13f1cc:	8f392364 */ 	lw	$t9,0x2364($t9)
/*  f13f1d0:	8f182368 */ 	lw	$t8,0x2368($t8)
/*  f13f1d4:	8fae0298 */ 	lw	$t6,0x298($sp)
/*  f13f1d8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13f1dc:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13f1e0:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13f1e4:	02603825 */ 	or	$a3,$s3,$zero
/*  f13f1e8:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f13f1ec:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f13f1f0:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f13f1f4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f13f1f8:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f13f1fc:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f13f200:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f13f204:	0fc54529 */ 	jal	textRender
/*  f13f208:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f13f20c:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13f210:	0fc5a4dd */ 	jal	langGet
/*  f13f214:	2404584d */ 	addiu	$a0,$zero,0x584d
/*  f13f218:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f13f21c:	24a50364 */ 	addiu	$a1,$a1,0x364
/*  f13f220:	02602025 */ 	or	$a0,$s3,$zero
/*  f13f224:	0c004fc1 */ 	jal	sprintf
/*  f13f228:	00403025 */ 	or	$a2,$v0,$zero
/*  f13f22c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f13f230:	8def2364 */ 	lw	$t7,0x2364($t7)
/*  f13f234:	3c078008 */ 	lui	$a3,0x8008
/*  f13f238:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f13f23c:	27a402c8 */ 	addiu	$a0,$sp,0x2c8
/*  f13f240:	27a502cc */ 	addiu	$a1,$sp,0x2cc
/*  f13f244:	02603025 */ 	or	$a2,$s3,$zero
/*  f13f248:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f13f24c:	0fc54655 */ 	jal	textMeasure
/*  f13f250:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f13f254:	8fb10080 */ 	lw	$s1,0x80($sp)
/*  f13f258:	8fa802d8 */ 	lw	$t0,0x2d8($sp)
/*  f13f25c:	8fb802cc */ 	lw	$t8,0x2cc($sp)
/*  f13f260:	8fae02c8 */ 	lw	$t6,0x2c8($sp)
/*  f13f264:	26310005 */ 	addiu	$s1,$s1,0x5
/*  f13f268:	2508ffd7 */ 	addiu	$t0,$t0,-41
/*  f13f26c:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f13f270:	27b802c0 */ 	addiu	$t8,$sp,0x2c0
/*  f13f274:	010e7821 */ 	addu	$t7,$t0,$t6
/*  f13f278:	afaf02c0 */ 	sw	$t7,0x2c0($sp)
/*  f13f27c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f13f280:	afb902c4 */ 	sw	$t9,0x2c4($sp)
/*  f13f284:	afa802d0 */ 	sw	$t0,0x2d0($sp)
/*  f13f288:	afb102d4 */ 	sw	$s1,0x2d4($sp)
/*  f13f28c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13f290:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13f294:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13f298:	0fc537d6 */ 	jal	func0f153858
/*  f13f29c:	27a702c4 */ 	addiu	$a3,$sp,0x2c4
/*  f13f2a0:	0c002f77 */ 	jal	viGetWidth
/*  f13f2a4:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13f2a8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f13f2ac:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f13f2b0:	0c002f7b */ 	jal	viGetHeight
/*  f13f2b4:	03208025 */ 	or	$s0,$t9,$zero
/*  f13f2b8:	3c0e8008 */ 	lui	$t6,0x8008
/*  f13f2bc:	3c0f8008 */ 	lui	$t7,0x8008
/*  f13f2c0:	8def2364 */ 	lw	$t7,0x2364($t7)
/*  f13f2c4:	8dce2368 */ 	lw	$t6,0x2368($t6)
/*  f13f2c8:	8fb8029c */ 	lw	$t8,0x29c($sp)
/*  f13f2cc:	8fb90298 */ 	lw	$t9,0x298($sp)
/*  f13f2d0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13f2d4:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13f2d8:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13f2dc:	02603825 */ 	or	$a3,$s3,$zero
/*  f13f2e0:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f13f2e4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f13f2e8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f13f2ec:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f13f2f0:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f13f2f4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f13f2f8:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f13f2fc:	0fc54529 */ 	jal	textRender
/*  f13f300:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f13f304:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f13f308:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13f30c:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f13f310:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f13f314:	5460000b */ 	bnezl	$v1,.NB0f13f344
/*  f13f318:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13f31c:	0fc5a4dd */ 	jal	langGet
/*  f13f320:	2404584e */ 	addiu	$a0,$zero,0x584e
/*  f13f324:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f13f328:	24a50368 */ 	addiu	$a1,$a1,0x368
/*  f13f32c:	02602025 */ 	or	$a0,$s3,$zero
/*  f13f330:	0c004fc1 */ 	jal	sprintf
/*  f13f334:	00403025 */ 	or	$a2,$v0,$zero
/*  f13f338:	10000014 */ 	beqz	$zero,.NB0f13f38c
/*  f13f33c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f340:	24010001 */ 	addiu	$at,$zero,0x1
.NB0f13f344:
/*  f13f344:	1461000a */ 	bne	$v1,$at,.NB0f13f370
/*  f13f348:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f34c:	0fc5a4dd */ 	jal	langGet
/*  f13f350:	240458d0 */ 	addiu	$a0,$zero,0x58d0
/*  f13f354:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f13f358:	24a5036c */ 	addiu	$a1,$a1,0x36c
/*  f13f35c:	02602025 */ 	or	$a0,$s3,$zero
/*  f13f360:	0c004fc1 */ 	jal	sprintf
/*  f13f364:	00403025 */ 	or	$a2,$v0,$zero
/*  f13f368:	10000008 */ 	beqz	$zero,.NB0f13f38c
/*  f13f36c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f13f370:
/*  f13f370:	0fc5a4dd */ 	jal	langGet
/*  f13f374:	240458d9 */ 	addiu	$a0,$zero,0x58d9
/*  f13f378:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f13f37c:	24a50370 */ 	addiu	$a1,$a1,0x370
/*  f13f380:	02602025 */ 	or	$a0,$s3,$zero
/*  f13f384:	0c004fc1 */ 	jal	sprintf
/*  f13f388:	00403025 */ 	or	$a2,$v0,$zero
.NB0f13f38c:
/*  f13f38c:	3c188008 */ 	lui	$t8,0x8008
/*  f13f390:	8f182364 */ 	lw	$t8,0x2364($t8)
/*  f13f394:	3c078008 */ 	lui	$a3,0x8008
/*  f13f398:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f13f39c:	27a402c8 */ 	addiu	$a0,$sp,0x2c8
/*  f13f3a0:	27a502cc */ 	addiu	$a1,$sp,0x2cc
/*  f13f3a4:	02603025 */ 	or	$a2,$s3,$zero
/*  f13f3a8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f13f3ac:	0fc54655 */ 	jal	textMeasure
/*  f13f3b0:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f13f3b4:	8fa802d8 */ 	lw	$t0,0x2d8($sp)
/*  f13f3b8:	8fb902cc */ 	lw	$t9,0x2cc($sp)
/*  f13f3bc:	8faf02c8 */ 	lw	$t7,0x2c8($sp)
/*  f13f3c0:	2508ffde */ 	addiu	$t0,$t0,-34
/*  f13f3c4:	02397021 */ 	addu	$t6,$s1,$t9
/*  f13f3c8:	27b902c0 */ 	addiu	$t9,$sp,0x2c0
/*  f13f3cc:	010fc021 */ 	addu	$t8,$t0,$t7
/*  f13f3d0:	afb802c0 */ 	sw	$t8,0x2c0($sp)
/*  f13f3d4:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f13f3d8:	afae02c4 */ 	sw	$t6,0x2c4($sp)
/*  f13f3dc:	afa802d0 */ 	sw	$t0,0x2d0($sp)
/*  f13f3e0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13f3e4:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13f3e8:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13f3ec:	27a702c4 */ 	addiu	$a3,$sp,0x2c4
/*  f13f3f0:	0fc537d6 */ 	jal	func0f153858
/*  f13f3f4:	afb102d4 */ 	sw	$s1,0x2d4($sp)
/*  f13f3f8:	0c002f77 */ 	jal	viGetWidth
/*  f13f3fc:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13f400:	00028400 */ 	sll	$s0,$v0,0x10
/*  f13f404:	00107403 */ 	sra	$t6,$s0,0x10
/*  f13f408:	0c002f7b */ 	jal	viGetHeight
/*  f13f40c:	01c08025 */ 	or	$s0,$t6,$zero
/*  f13f410:	3c0f8008 */ 	lui	$t7,0x8008
/*  f13f414:	3c188008 */ 	lui	$t8,0x8008
/*  f13f418:	8f182364 */ 	lw	$t8,0x2364($t8)
/*  f13f41c:	8def2368 */ 	lw	$t7,0x2368($t7)
/*  f13f420:	8fb9029c */ 	lw	$t9,0x29c($sp)
/*  f13f424:	8fae0298 */ 	lw	$t6,0x298($sp)
/*  f13f428:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13f42c:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13f430:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13f434:	02603825 */ 	or	$a3,$s3,$zero
/*  f13f438:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f13f43c:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f13f440:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f13f444:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f13f448:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f13f44c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f13f450:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f13f454:	0fc54529 */ 	jal	textRender
/*  f13f458:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f13f45c:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f13f460:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13f464:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f13f468:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f13f46c:	54600049 */ 	bnezl	$v1,.NB0f13f594
/*  f13f470:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13f474:	0fc5a4dd */ 	jal	langGet
/*  f13f478:	2404584f */ 	addiu	$a0,$zero,0x584f
/*  f13f47c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f13f480:	24a50374 */ 	addiu	$a1,$a1,0x374
/*  f13f484:	02602025 */ 	or	$a0,$s3,$zero
/*  f13f488:	0c004fc1 */ 	jal	sprintf
/*  f13f48c:	00403025 */ 	or	$a2,$v0,$zero
/*  f13f490:	3c198008 */ 	lui	$t9,0x8008
/*  f13f494:	8f392364 */ 	lw	$t9,0x2364($t9)
/*  f13f498:	3c078008 */ 	lui	$a3,0x8008
/*  f13f49c:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f13f4a0:	27a402c8 */ 	addiu	$a0,$sp,0x2c8
/*  f13f4a4:	27a502cc */ 	addiu	$a1,$sp,0x2cc
/*  f13f4a8:	02603025 */ 	or	$a2,$s3,$zero
/*  f13f4ac:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f13f4b0:	0fc54655 */ 	jal	textMeasure
/*  f13f4b4:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f13f4b8:	8faf0294 */ 	lw	$t7,0x294($sp)
/*  f13f4bc:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f13f4c0:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f13f4c4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f13f4c8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f13f4cc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f13f4d0:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f13f4d4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f13f4d8:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f13f4dc:	8fb902cc */ 	lw	$t9,0x2cc($sp)
/*  f13f4e0:	01d81823 */ 	subu	$v1,$t6,$t8
/*  f13f4e4:	8fae02c8 */ 	lw	$t6,0x2c8($sp)
/*  f13f4e8:	2463ffe7 */ 	addiu	$v1,$v1,-25
/*  f13f4ec:	2508001b */ 	addiu	$t0,$t0,0x1b
/*  f13f4f0:	00797821 */ 	addu	$t7,$v1,$t9
/*  f13f4f4:	27b902c0 */ 	addiu	$t9,$sp,0x2c0
/*  f13f4f8:	010ec021 */ 	addu	$t8,$t0,$t6
/*  f13f4fc:	afb802c0 */ 	sw	$t8,0x2c0($sp)
/*  f13f500:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f13f504:	afaf02c4 */ 	sw	$t7,0x2c4($sp)
/*  f13f508:	afa802d0 */ 	sw	$t0,0x2d0($sp)
/*  f13f50c:	afa302d4 */ 	sw	$v1,0x2d4($sp)
/*  f13f510:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13f514:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13f518:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13f51c:	0fc537d6 */ 	jal	func0f153858
/*  f13f520:	27a702c4 */ 	addiu	$a3,$sp,0x2c4
/*  f13f524:	0c002f77 */ 	jal	viGetWidth
/*  f13f528:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13f52c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f13f530:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f13f534:	0c002f7b */ 	jal	viGetHeight
/*  f13f538:	01e08025 */ 	or	$s0,$t7,$zero
/*  f13f53c:	3c0e8008 */ 	lui	$t6,0x8008
/*  f13f540:	3c188008 */ 	lui	$t8,0x8008
/*  f13f544:	8f182364 */ 	lw	$t8,0x2364($t8)
/*  f13f548:	8dce2368 */ 	lw	$t6,0x2368($t6)
/*  f13f54c:	8fb9029c */ 	lw	$t9,0x29c($sp)
/*  f13f550:	8faf0298 */ 	lw	$t7,0x298($sp)
/*  f13f554:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13f558:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13f55c:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13f560:	02603825 */ 	or	$a3,$s3,$zero
/*  f13f564:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f13f568:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f13f56c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f13f570:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f13f574:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f13f578:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f13f57c:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f13f580:	0fc54529 */ 	jal	textRender
/*  f13f584:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f13f588:	1000008f */ 	beqz	$zero,.NB0f13f7c8
/*  f13f58c:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13f590:	24010001 */ 	addiu	$at,$zero,0x1
.NB0f13f594:
/*  f13f594:	14610048 */ 	bne	$v1,$at,.NB0f13f6b8
/*  f13f598:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f59c:	0fc5a4dd */ 	jal	langGet
/*  f13f5a0:	240459d4 */ 	addiu	$a0,$zero,0x59d4
/*  f13f5a4:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f13f5a8:	24a5037c */ 	addiu	$a1,$a1,0x37c
/*  f13f5ac:	02602025 */ 	or	$a0,$s3,$zero
/*  f13f5b0:	0c004fc1 */ 	jal	sprintf
/*  f13f5b4:	00403025 */ 	or	$a2,$v0,$zero
/*  f13f5b8:	3c0e8008 */ 	lui	$t6,0x8008
/*  f13f5bc:	8dce2364 */ 	lw	$t6,0x2364($t6)
/*  f13f5c0:	3c078008 */ 	lui	$a3,0x8008
/*  f13f5c4:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f13f5c8:	27a402c8 */ 	addiu	$a0,$sp,0x2c8
/*  f13f5cc:	27a502cc */ 	addiu	$a1,$sp,0x2cc
/*  f13f5d0:	02603025 */ 	or	$a2,$s3,$zero
/*  f13f5d4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f13f5d8:	0fc54655 */ 	jal	textMeasure
/*  f13f5dc:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f13f5e0:	8fb90294 */ 	lw	$t9,0x294($sp)
/*  f13f5e4:	8fb80088 */ 	lw	$t8,0x88($sp)
/*  f13f5e8:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f13f5ec:	00197880 */ 	sll	$t7,$t9,0x2
/*  f13f5f0:	01f97823 */ 	subu	$t7,$t7,$t9
/*  f13f5f4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f13f5f8:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f13f5fc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f13f600:	01f97821 */ 	addu	$t7,$t7,$t9
/*  f13f604:	8fae02cc */ 	lw	$t6,0x2cc($sp)
/*  f13f608:	030f1823 */ 	subu	$v1,$t8,$t7
/*  f13f60c:	8fb802c8 */ 	lw	$t8,0x2c8($sp)
/*  f13f610:	2463ffe7 */ 	addiu	$v1,$v1,-25
/*  f13f614:	2508001b */ 	addiu	$t0,$t0,0x1b
/*  f13f618:	006ec821 */ 	addu	$t9,$v1,$t6
/*  f13f61c:	27ae02c0 */ 	addiu	$t6,$sp,0x2c0
/*  f13f620:	01187821 */ 	addu	$t7,$t0,$t8
/*  f13f624:	afaf02c0 */ 	sw	$t7,0x2c0($sp)
/*  f13f628:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f13f62c:	afb902c4 */ 	sw	$t9,0x2c4($sp)
/*  f13f630:	afa802d0 */ 	sw	$t0,0x2d0($sp)
/*  f13f634:	afa302d4 */ 	sw	$v1,0x2d4($sp)
/*  f13f638:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13f63c:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13f640:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13f644:	0fc537d6 */ 	jal	func0f153858
/*  f13f648:	27a702c4 */ 	addiu	$a3,$sp,0x2c4
/*  f13f64c:	0c002f77 */ 	jal	viGetWidth
/*  f13f650:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13f654:	00028400 */ 	sll	$s0,$v0,0x10
/*  f13f658:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f13f65c:	0c002f7b */ 	jal	viGetHeight
/*  f13f660:	03208025 */ 	or	$s0,$t9,$zero
/*  f13f664:	3c188008 */ 	lui	$t8,0x8008
/*  f13f668:	3c0f8008 */ 	lui	$t7,0x8008
/*  f13f66c:	8def2364 */ 	lw	$t7,0x2364($t7)
/*  f13f670:	8f182368 */ 	lw	$t8,0x2368($t8)
/*  f13f674:	8fae029c */ 	lw	$t6,0x29c($sp)
/*  f13f678:	8fb90298 */ 	lw	$t9,0x298($sp)
/*  f13f67c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13f680:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13f684:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13f688:	02603825 */ 	or	$a3,$s3,$zero
/*  f13f68c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f13f690:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f13f694:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f13f698:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f13f69c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f13f6a0:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f13f6a4:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f13f6a8:	0fc54529 */ 	jal	textRender
/*  f13f6ac:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f13f6b0:	10000045 */ 	beqz	$zero,.NB0f13f7c8
/*  f13f6b4:	0040a825 */ 	or	$s5,$v0,$zero
.NB0f13f6b8:
/*  f13f6b8:	0fc5a4dd */ 	jal	langGet
/*  f13f6bc:	240459d5 */ 	addiu	$a0,$zero,0x59d5
/*  f13f6c0:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f13f6c4:	24a50384 */ 	addiu	$a1,$a1,0x384
/*  f13f6c8:	02602025 */ 	or	$a0,$s3,$zero
/*  f13f6cc:	0c004fc1 */ 	jal	sprintf
/*  f13f6d0:	00403025 */ 	or	$a2,$v0,$zero
/*  f13f6d4:	3c188008 */ 	lui	$t8,0x8008
/*  f13f6d8:	8f182364 */ 	lw	$t8,0x2364($t8)
/*  f13f6dc:	3c078008 */ 	lui	$a3,0x8008
/*  f13f6e0:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f13f6e4:	27a402c8 */ 	addiu	$a0,$sp,0x2c8
/*  f13f6e8:	27a502cc */ 	addiu	$a1,$sp,0x2cc
/*  f13f6ec:	02603025 */ 	or	$a2,$s3,$zero
/*  f13f6f0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f13f6f4:	0fc54655 */ 	jal	textMeasure
/*  f13f6f8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f13f6fc:	8fae0294 */ 	lw	$t6,0x294($sp)
/*  f13f700:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f13f704:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f13f708:	000ec900 */ 	sll	$t9,$t6,0x4
/*  f13f70c:	032ec823 */ 	subu	$t9,$t9,$t6
/*  f13f710:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f13f714:	032ec823 */ 	subu	$t9,$t9,$t6
/*  f13f718:	8fb802cc */ 	lw	$t8,0x2cc($sp)
/*  f13f71c:	01f91823 */ 	subu	$v1,$t7,$t9
/*  f13f720:	8faf02c8 */ 	lw	$t7,0x2c8($sp)
/*  f13f724:	2463ffe7 */ 	addiu	$v1,$v1,-25
/*  f13f728:	2508001b */ 	addiu	$t0,$t0,0x1b
/*  f13f72c:	00787021 */ 	addu	$t6,$v1,$t8
/*  f13f730:	27b802c0 */ 	addiu	$t8,$sp,0x2c0
/*  f13f734:	010fc821 */ 	addu	$t9,$t0,$t7
/*  f13f738:	afb902c0 */ 	sw	$t9,0x2c0($sp)
/*  f13f73c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f13f740:	afae02c4 */ 	sw	$t6,0x2c4($sp)
/*  f13f744:	afa802d0 */ 	sw	$t0,0x2d0($sp)
/*  f13f748:	afa302d4 */ 	sw	$v1,0x2d4($sp)
/*  f13f74c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13f750:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13f754:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13f758:	0fc537d6 */ 	jal	func0f153858
/*  f13f75c:	27a702c4 */ 	addiu	$a3,$sp,0x2c4
/*  f13f760:	0c002f77 */ 	jal	viGetWidth
/*  f13f764:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13f768:	00028400 */ 	sll	$s0,$v0,0x10
/*  f13f76c:	00107403 */ 	sra	$t6,$s0,0x10
/*  f13f770:	0c002f7b */ 	jal	viGetHeight
/*  f13f774:	01c08025 */ 	or	$s0,$t6,$zero
/*  f13f778:	3c0f8008 */ 	lui	$t7,0x8008
/*  f13f77c:	3c198008 */ 	lui	$t9,0x8008
/*  f13f780:	8f392364 */ 	lw	$t9,0x2364($t9)
/*  f13f784:	8def2368 */ 	lw	$t7,0x2368($t7)
/*  f13f788:	8fb8029c */ 	lw	$t8,0x29c($sp)
/*  f13f78c:	8fae0298 */ 	lw	$t6,0x298($sp)
/*  f13f790:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13f794:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13f798:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13f79c:	02603825 */ 	or	$a3,$s3,$zero
/*  f13f7a0:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f13f7a4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f13f7a8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f13f7ac:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f13f7b0:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f13f7b4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f13f7b8:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f13f7bc:	0fc54529 */ 	jal	textRender
/*  f13f7c0:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f13f7c4:	0040a825 */ 	or	$s5,$v0,$zero
.NB0f13f7c8:
/*  f13f7c8:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f13f7cc:	8df90480 */ 	lw	$t9,0x480($t7)
/*  f13f7d0:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f13f7d4:	5460000b */ 	bnezl	$v1,.NB0f13f804
/*  f13f7d8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13f7dc:	0fc5a4dd */ 	jal	langGet
/*  f13f7e0:	24045850 */ 	addiu	$a0,$zero,0x5850
/*  f13f7e4:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f13f7e8:	24a5038c */ 	addiu	$a1,$a1,0x38c
/*  f13f7ec:	02602025 */ 	or	$a0,$s3,$zero
/*  f13f7f0:	0c004fc1 */ 	jal	sprintf
/*  f13f7f4:	00403025 */ 	or	$a2,$v0,$zero
/*  f13f7f8:	10000014 */ 	beqz	$zero,.NB0f13f84c
/*  f13f7fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f800:	24010001 */ 	addiu	$at,$zero,0x1
.NB0f13f804:
/*  f13f804:	1461000a */ 	bne	$v1,$at,.NB0f13f830
/*  f13f808:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13f80c:	0fc5a4dd */ 	jal	langGet
/*  f13f810:	240458cf */ 	addiu	$a0,$zero,0x58cf
/*  f13f814:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f13f818:	24a50390 */ 	addiu	$a1,$a1,0x390
/*  f13f81c:	02602025 */ 	or	$a0,$s3,$zero
/*  f13f820:	0c004fc1 */ 	jal	sprintf
/*  f13f824:	00403025 */ 	or	$a2,$v0,$zero
/*  f13f828:	10000008 */ 	beqz	$zero,.NB0f13f84c
/*  f13f82c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f13f830:
/*  f13f830:	0fc5a4dd */ 	jal	langGet
/*  f13f834:	240458d8 */ 	addiu	$a0,$zero,0x58d8
/*  f13f838:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f13f83c:	24a50394 */ 	addiu	$a1,$a1,0x394
/*  f13f840:	02602025 */ 	or	$a0,$s3,$zero
/*  f13f844:	0c004fc1 */ 	jal	sprintf
/*  f13f848:	00403025 */ 	or	$a2,$v0,$zero
.NB0f13f84c:
/*  f13f84c:	3c188008 */ 	lui	$t8,0x8008
/*  f13f850:	8f182364 */ 	lw	$t8,0x2364($t8)
/*  f13f854:	3c078008 */ 	lui	$a3,0x8008
/*  f13f858:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f13f85c:	27a402c8 */ 	addiu	$a0,$sp,0x2c8
/*  f13f860:	27a502cc */ 	addiu	$a1,$sp,0x2cc
/*  f13f864:	02603025 */ 	or	$a2,$s3,$zero
/*  f13f868:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f13f86c:	0fc54655 */ 	jal	textMeasure
/*  f13f870:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f13f874:	8faf0294 */ 	lw	$t7,0x294($sp)
/*  f13f878:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f13f87c:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f13f880:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f13f884:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f13f888:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f13f88c:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f13f890:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f13f894:	8fb802cc */ 	lw	$t8,0x2cc($sp)
/*  f13f898:	01d91823 */ 	subu	$v1,$t6,$t9
/*  f13f89c:	8fae02c8 */ 	lw	$t6,0x2c8($sp)
/*  f13f8a0:	2463ffe7 */ 	addiu	$v1,$v1,-25
/*  f13f8a4:	25080022 */ 	addiu	$t0,$t0,0x22
/*  f13f8a8:	00787821 */ 	addu	$t7,$v1,$t8
/*  f13f8ac:	27b802c0 */ 	addiu	$t8,$sp,0x2c0
/*  f13f8b0:	010ec821 */ 	addu	$t9,$t0,$t6
/*  f13f8b4:	afb902c0 */ 	sw	$t9,0x2c0($sp)
/*  f13f8b8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f13f8bc:	afaf02c4 */ 	sw	$t7,0x2c4($sp)
/*  f13f8c0:	afa802d0 */ 	sw	$t0,0x2d0($sp)
/*  f13f8c4:	afa302d4 */ 	sw	$v1,0x2d4($sp)
/*  f13f8c8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13f8cc:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13f8d0:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13f8d4:	0fc537d6 */ 	jal	func0f153858
/*  f13f8d8:	27a702c4 */ 	addiu	$a3,$sp,0x2c4
/*  f13f8dc:	0c002f77 */ 	jal	viGetWidth
/*  f13f8e0:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13f8e4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f13f8e8:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f13f8ec:	0c002f7b */ 	jal	viGetHeight
/*  f13f8f0:	01e08025 */ 	or	$s0,$t7,$zero
/*  f13f8f4:	3c0e8008 */ 	lui	$t6,0x8008
/*  f13f8f8:	3c198008 */ 	lui	$t9,0x8008
/*  f13f8fc:	8f392364 */ 	lw	$t9,0x2364($t9)
/*  f13f900:	8dce2368 */ 	lw	$t6,0x2368($t6)
/*  f13f904:	8fb8029c */ 	lw	$t8,0x29c($sp)
/*  f13f908:	8faf0298 */ 	lw	$t7,0x298($sp)
/*  f13f90c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13f910:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13f914:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13f918:	02603825 */ 	or	$a3,$s3,$zero
/*  f13f91c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f13f920:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f13f924:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f13f928:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f13f92c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f13f930:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f13f934:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f13f938:	0fc54529 */ 	jal	textRender
/*  f13f93c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f13f940:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f13f944:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13f948:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f13f94c:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f13f950:	10600003 */ 	beqz	$v1,.NB0f13f960
/*  f13f954:	24010002 */ 	addiu	$at,$zero,0x2
/*  f13f958:	1461000a */ 	bne	$v1,$at,.NB0f13f984
/*  f13f95c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f13f960:
/*  f13f960:	0fc5a4dd */ 	jal	langGet
/*  f13f964:	24045851 */ 	addiu	$a0,$zero,0x5851
/*  f13f968:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f13f96c:	24a50398 */ 	addiu	$a1,$a1,0x398
/*  f13f970:	02602025 */ 	or	$a0,$s3,$zero
/*  f13f974:	0c004fc1 */ 	jal	sprintf
/*  f13f978:	00403025 */ 	or	$a2,$v0,$zero
/*  f13f97c:	10000008 */ 	beqz	$zero,.NB0f13f9a0
/*  f13f980:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f13f984:
/*  f13f984:	0fc5a4dd */ 	jal	langGet
/*  f13f988:	240458ce */ 	addiu	$a0,$zero,0x58ce
/*  f13f98c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f13f990:	24a5039c */ 	addiu	$a1,$a1,0x39c
/*  f13f994:	02602025 */ 	or	$a0,$s3,$zero
/*  f13f998:	0c004fc1 */ 	jal	sprintf
/*  f13f99c:	00403025 */ 	or	$a2,$v0,$zero
.NB0f13f9a0:
/*  f13f9a0:	3c188008 */ 	lui	$t8,0x8008
/*  f13f9a4:	8f182364 */ 	lw	$t8,0x2364($t8)
/*  f13f9a8:	3c078008 */ 	lui	$a3,0x8008
/*  f13f9ac:	8ce72368 */ 	lw	$a3,0x2368($a3)
/*  f13f9b0:	27a402c8 */ 	addiu	$a0,$sp,0x2c8
/*  f13f9b4:	27a502cc */ 	addiu	$a1,$sp,0x2cc
/*  f13f9b8:	02603025 */ 	or	$a2,$s3,$zero
/*  f13f9bc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f13f9c0:	0fc54655 */ 	jal	textMeasure
/*  f13f9c4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f13f9c8:	8fb40294 */ 	lw	$s4,0x294($sp)
/*  f13f9cc:	3c014040 */ 	lui	$at,0x4040
/*  f13f9d0:	44812000 */ 	mtc1	$at,$f4
/*  f13f9d4:	00147880 */ 	sll	$t7,$s4,0x2
/*  f13f9d8:	01f47821 */ 	addu	$t7,$t7,$s4
/*  f13f9dc:	c7aa0060 */ 	lwc1	$f10,0x60($sp)
/*  f13f9e0:	25eefffb */ 	addiu	$t6,$t7,-5
/*  f13f9e4:	448e4000 */ 	mtc1	$t6,$f8
/*  f13f9e8:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f13f9ec:	8fa802d8 */ 	lw	$t0,0x2d8($sp)
/*  f13f9f0:	8fb802cc */ 	lw	$t8,0x2cc($sp)
/*  f13f9f4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f13f9f8:	8fae02c8 */ 	lw	$t6,0x2c8($sp)
/*  f13f9fc:	01e0a025 */ 	or	$s4,$t7,$zero
/*  f13fa00:	2508fff4 */ 	addiu	$t0,$t0,-12
/*  f13fa04:	010ec821 */ 	addu	$t9,$t0,$t6
/*  f13fa08:	afb902c0 */ 	sw	$t9,0x2c0($sp)
/*  f13fa0c:	460a3101 */ 	sub.s	$f4,$f6,$f10
/*  f13fa10:	afa802d0 */ 	sw	$t0,0x2d0($sp)
/*  f13fa14:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13fa18:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13fa1c:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f13fa20:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13fa24:	27a702c4 */ 	addiu	$a3,$sp,0x2c4
/*  f13fa28:	44034000 */ 	mfc1	$v1,$f8
/*  f13fa2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f13fa30:	00787821 */ 	addu	$t7,$v1,$t8
/*  f13fa34:	27b802c0 */ 	addiu	$t8,$sp,0x2c0
/*  f13fa38:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f13fa3c:	afaf02c4 */ 	sw	$t7,0x2c4($sp)
/*  f13fa40:	0fc537d6 */ 	jal	func0f153858
/*  f13fa44:	afa302d4 */ 	sw	$v1,0x2d4($sp)
/*  f13fa48:	0c002f77 */ 	jal	viGetWidth
/*  f13fa4c:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13fa50:	00028400 */ 	sll	$s0,$v0,0x10
/*  f13fa54:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f13fa58:	0c002f7b */ 	jal	viGetHeight
/*  f13fa5c:	01e08025 */ 	or	$s0,$t7,$zero
/*  f13fa60:	3c0e8008 */ 	lui	$t6,0x8008
/*  f13fa64:	3c198008 */ 	lui	$t9,0x8008
/*  f13fa68:	8f392364 */ 	lw	$t9,0x2364($t9)
/*  f13fa6c:	8dce2368 */ 	lw	$t6,0x2368($t6)
/*  f13fa70:	8fb8029c */ 	lw	$t8,0x29c($sp)
/*  f13fa74:	8faf0298 */ 	lw	$t7,0x298($sp)
/*  f13fa78:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13fa7c:	27a502d4 */ 	addiu	$a1,$sp,0x2d4
/*  f13fa80:	27a602d0 */ 	addiu	$a2,$sp,0x2d0
/*  f13fa84:	02603825 */ 	or	$a3,$s3,$zero
/*  f13fa88:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f13fa8c:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f13fa90:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f13fa94:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f13fa98:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f13fa9c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f13faa0:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f13faa4:	0fc54529 */ 	jal	textRender
/*  f13faa8:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f13faac:	0fc537ce */ 	jal	func0f153838
/*  f13fab0:	00402025 */ 	or	$a0,$v0,$zero
/*  f13fab4:	8ece0288 */ 	lw	$t6,0x288($s6)
/*  f13fab8:	0040a825 */ 	or	$s5,$v0,$zero
/*  f13fabc:	0fc5338e */ 	jal	optionsGetContpadNum1
/*  f13fac0:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f13fac4:	00028600 */ 	sll	$s0,$v0,0x18
/*  f13fac8:	00022600 */ 	sll	$a0,$v0,0x18
/*  f13facc:	0010ce03 */ 	sra	$t9,$s0,0x18
/*  f13fad0:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f13fad4:	03208025 */ 	or	$s0,$t9,$zero
/*  f13fad8:	03002025 */ 	or	$a0,$t8,$zero
/*  f13fadc:	0c005790 */ 	jal	joyGetButtons
/*  f13fae0:	3405ffff */ 	dli	$a1,0xffff
/*  f13fae4:	00102600 */ 	sll	$a0,$s0,0x18
/*  f13fae8:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f13faec:	01e02025 */ 	or	$a0,$t7,$zero
/*  f13faf0:	3051ffff */ 	andi	$s1,$v0,0xffff
/*  f13faf4:	0c0057c0 */ 	jal	joyGetButtonsPressedThisFrame
/*  f13faf8:	3405ffff */ 	dli	$a1,0xffff
/*  f13fafc:	00102600 */ 	sll	$a0,$s0,0x18
/*  f13fb00:	00047603 */ 	sra	$t6,$a0,0x18
/*  f13fb04:	3052ffff */ 	andi	$s2,$v0,0xffff
/*  f13fb08:	0c00573c */ 	jal	joyGetStickX
/*  f13fb0c:	01c02025 */ 	or	$a0,$t6,$zero
/*  f13fb10:	00102600 */ 	sll	$a0,$s0,0x18
/*  f13fb14:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f13fb18:	03202025 */ 	or	$a0,$t9,$zero
/*  f13fb1c:	0c005766 */ 	jal	joyGetStickY
/*  f13fb20:	a3a2023d */ 	sb	$v0,0x23d($sp)
/*  f13fb24:	02a01825 */ 	or	$v1,$s5,$zero
/*  f13fb28:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13fb2c:	3c18e700 */ 	lui	$t8,0xe700
/*  f13fb30:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f13fb34:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13fb38:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13fb3c:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f13fb40:	3c0fba00 */ 	lui	$t7,0xba00
/*  f13fb44:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*  f13fb48:	02a02825 */ 	or	$a1,$s5,$zero
/*  f13fb4c:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f13fb50:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f13fb54:	3c0eba00 */ 	lui	$t6,0xba00
/*  f13fb58:	35ce0602 */ 	ori	$t6,$t6,0x602
/*  f13fb5c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13fb60:	241900c0 */ 	addiu	$t9,$zero,0xc0
/*  f13fb64:	acb90004 */ 	sw	$t9,0x4($a1)
/*  f13fb68:	02a03025 */ 	or	$a2,$s5,$zero
/*  f13fb6c:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f13fb70:	3c18ba00 */ 	lui	$t8,0xba00
/*  f13fb74:	37181301 */ 	ori	$t8,$t8,0x1301
/*  f13fb78:	acd80000 */ 	sw	$t8,0x0($a2)
/*  f13fb7c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13fb80:	02a03825 */ 	or	$a3,$s5,$zero
/*  f13fb84:	acc00004 */ 	sw	$zero,0x4($a2)
/*  f13fb88:	3c0fb900 */ 	lui	$t7,0xb900
/*  f13fb8c:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f13fb90:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13fb94:	02a01825 */ 	or	$v1,$s5,$zero
/*  f13fb98:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f13fb9c:	3c0eba00 */ 	lui	$t6,0xba00
/*  f13fba0:	35ce1001 */ 	ori	$t6,$t6,0x1001
/*  f13fba4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13fba8:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f13fbac:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f13fbb0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13fbb4:	3c19ba00 */ 	lui	$t9,0xba00
/*  f13fbb8:	37390c02 */ 	ori	$t9,$t9,0xc02
/*  f13fbbc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13fbc0:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f13fbc4:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f13fbc8:	02a02825 */ 	or	$a1,$s5,$zero
/*  f13fbcc:	24182000 */ 	addiu	$t8,$zero,0x2000
/*  f13fbd0:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f13fbd4:	3c0fba00 */ 	lui	$t7,0xba00
/*  f13fbd8:	35ef0903 */ 	ori	$t7,$t7,0x903
/*  f13fbdc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13fbe0:	240e0c00 */ 	addiu	$t6,$zero,0xc00
/*  f13fbe4:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f13fbe8:	02a03025 */ 	or	$a2,$s5,$zero
/*  f13fbec:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f13fbf0:	3c19ba00 */ 	lui	$t9,0xba00
/*  f13fbf4:	37390e02 */ 	ori	$t9,$t9,0xe02
/*  f13fbf8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13fbfc:	02a04025 */ 	or	$t0,$s5,$zero
/*  f13fc00:	acd90000 */ 	sw	$t9,0x0($a2)
/*  f13fc04:	acc00004 */ 	sw	$zero,0x4($a2)
/*  f13fc08:	3c0f0050 */ 	lui	$t7,0x50
/*  f13fc0c:	3c18b900 */ 	lui	$t8,0xb900
/*  f13fc10:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f13fc14:	35ef4340 */ 	ori	$t7,$t7,0x4340
/*  f13fc18:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13fc1c:	02a01825 */ 	or	$v1,$s5,$zero
/*  f13fc20:	ad0f0004 */ 	sw	$t7,0x4($t0)
/*  f13fc24:	ad180000 */ 	sw	$t8,0x0($t0)
/*  f13fc28:	3c19fffd */ 	lui	$t9,0xfffd
/*  f13fc2c:	3c0efcff */ 	lui	$t6,0xfcff
/*  f13fc30:	35ceffff */ 	ori	$t6,$t6,0xffff
/*  f13fc34:	3739f6fb */ 	ori	$t9,$t9,0xf6fb
/*  f13fc38:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f13fc3c:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f13fc40:	8fb80294 */ 	lw	$t8,0x294($sp)
/*  f13fc44:	24010002 */ 	addiu	$at,$zero,0x2
/*  f13fc48:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13fc4c:	57010004 */ 	bnel	$t8,$at,.NB0f13fc60
/*  f13fc50:	2407ffab */ 	addiu	$a3,$zero,-85
/*  f13fc54:	10000002 */ 	beqz	$zero,.NB0f13fc60
/*  f13fc58:	2407ffb4 */ 	addiu	$a3,$zero,-76
/*  f13fc5c:	2407ffab */ 	addiu	$a3,$zero,-85
.NB0f13fc60:
/*  f13fc60:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f13fc64:	8dee0480 */ 	lw	$t6,0x480($t7)
/*  f13fc68:	91c3006b */ 	lbu	$v1,0x6b($t6)
/*  f13fc6c:	14600015 */ 	bnez	$v1,.NB0f13fcc4
/*  f13fc70:	32390808 */ 	andi	$t9,$s1,0x808
/*  f13fc74:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f13fc78:	13200002 */ 	beqz	$t9,.NB0f13fc84
/*  f13fc7c:	02202825 */ 	or	$a1,$s1,$zero
/*  f13fc80:	24130028 */ 	addiu	$s3,$zero,0x28
.NB0f13fc84:
/*  f13fc84:	32580808 */ 	andi	$t8,$s2,0x808
/*  f13fc88:	13000004 */ 	beqz	$t8,.NB0f13fc9c
/*  f13fc8c:	02403025 */ 	or	$a2,$s2,$zero
/*  f13fc90:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f13fc94:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f13fc98:	01e09825 */ 	or	$s3,$t7,$zero
.NB0f13fc9c:
/*  f13fc9c:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f13fca0:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f13fca4:	02a01825 */ 	or	$v1,$s5,$zero
/*  f13fca8:	373800ff */ 	ori	$t8,$t9,0xff
/*  f13fcac:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f13fcb0:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f13fcb4:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f13fcb8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13fcbc:	10000030 */ 	beqz	$zero,.NB0f13fd80
/*  f13fcc0:	3c0b1020 */ 	lui	$t3,0x1020
.NB0f13fcc4:
/*  f13fcc4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13fcc8:	14610017 */ 	bne	$v1,$at,.NB0f13fd28
/*  f13fccc:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f13fcd0:	322f0808 */ 	andi	$t7,$s1,0x808
/*  f13fcd4:	2413007f */ 	addiu	$s3,$zero,0x7f
/*  f13fcd8:	11e00002 */ 	beqz	$t7,.NB0f13fce4
/*  f13fcdc:	02202825 */ 	or	$a1,$s1,$zero
/*  f13fce0:	241300be */ 	addiu	$s3,$zero,0xbe
.NB0f13fce4:
/*  f13fce4:	324e0808 */ 	andi	$t6,$s2,0x808
/*  f13fce8:	11c00004 */ 	beqz	$t6,.NB0f13fcfc
/*  f13fcec:	02403025 */ 	or	$a2,$s2,$zero
/*  f13fcf0:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f13fcf4:	327900ff */ 	andi	$t9,$s3,0xff
/*  f13fcf8:	03209825 */ 	or	$s3,$t9,$zero
.NB0f13fcfc:
/*  f13fcfc:	327800ff */ 	andi	$t8,$s3,0xff
/*  f13fd00:	00187a00 */ 	sll	$t7,$t8,0x8
/*  f13fd04:	3c0b1020 */ 	lui	$t3,0x1020
/*  f13fd08:	01eb7025 */ 	or	$t6,$t7,$t3
/*  f13fd0c:	02a01825 */ 	or	$v1,$s5,$zero
/*  f13fd10:	35d900ff */ 	ori	$t9,$t6,0xff
/*  f13fd14:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f13fd18:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f13fd1c:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f13fd20:	10000017 */ 	beqz	$zero,.NB0f13fd80
/*  f13fd24:	26b50008 */ 	addiu	$s5,$s5,0x8
.NB0f13fd28:
/*  f13fd28:	32380808 */ 	andi	$t8,$s1,0x808
/*  f13fd2c:	13000002 */ 	beqz	$t8,.NB0f13fd38
/*  f13fd30:	02202825 */ 	or	$a1,$s1,$zero
/*  f13fd34:	24130028 */ 	addiu	$s3,$zero,0x28
.NB0f13fd38:
/*  f13fd38:	324f0808 */ 	andi	$t7,$s2,0x808
/*  f13fd3c:	11e00004 */ 	beqz	$t7,.NB0f13fd50
/*  f13fd40:	02403025 */ 	or	$a2,$s2,$zero
/*  f13fd44:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f13fd48:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f13fd4c:	01c09825 */ 	or	$s3,$t6,$zero
.NB0f13fd50:
/*  f13fd50:	00137883 */ 	sra	$t7,$s3,0x2
/*  f13fd54:	31ee00ff */ 	andi	$t6,$t7,0xff
/*  f13fd58:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f13fd5c:	02a01825 */ 	or	$v1,$s5,$zero
/*  f13fd60:	0013c600 */ 	sll	$t8,$s3,0x18
/*  f13fd64:	03197825 */ 	or	$t7,$t8,$t9
/*  f13fd68:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f13fd6c:	3c09fa00 */ 	lui	$t1,0xfa00
/*  f13fd70:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f13fd74:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f13fd78:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13fd7c:	3c0b1020 */ 	lui	$t3,0x1020
.NB0f13fd80:
/*  f13fd80:	8fbf0294 */ 	lw	$ra,0x294($sp)
/*  f13fd84:	24f80008 */ 	addiu	$t8,$a3,0x8
/*  f13fd88:	8fb00088 */ 	lw	$s0,0x88($sp)
/*  f13fd8c:	031f0019 */ 	multu	$t8,$ra
/*  f13fd90:	8fb102e8 */ 	lw	$s1,0x2e8($sp)
/*  f13fd94:	3c01f600 */ 	lui	$at,0xf600
/*  f13fd98:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13fd9c:	262c0012 */ 	addiu	$t4,$s1,0x12
/*  f13fda0:	318f03ff */ 	andi	$t7,$t4,0x3ff
/*  f13fda4:	000f6080 */ 	sll	$t4,$t7,0x2
/*  f13fda8:	262d000a */ 	addiu	$t5,$s1,0xa
/*  f13fdac:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13fdb0:	0000c812 */ 	mflo	$t9
/*  f13fdb4:	03305021 */ 	addu	$t2,$t9,$s0
/*  f13fdb8:	315803ff */ 	andi	$t8,$t2,0x3ff
/*  f13fdbc:	00ff0019 */ 	multu	$a3,$ra
/*  f13fdc0:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f13fdc4:	03217825 */ 	or	$t7,$t9,$at
/*  f13fdc8:	01ec7025 */ 	or	$t6,$t7,$t4
/*  f13fdcc:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f13fdd0:	31b903ff */ 	andi	$t9,$t5,0x3ff
/*  f13fdd4:	00196880 */ 	sll	$t5,$t9,0x2
/*  f13fdd8:	001f7880 */ 	sll	$t7,$ra,0x2
/*  f13fddc:	01ff7821 */ 	addu	$t7,$t7,$ra
/*  f13fde0:	000f7840 */ 	sll	$t7,$t7,0x1
/*  f13fde4:	0000c012 */ 	mflo	$t8
/*  f13fde8:	03104021 */ 	addu	$t0,$t8,$s0
/*  f13fdec:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f13fdf0:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f13fdf4:	030dc825 */ 	or	$t9,$t8,$t5
/*  f13fdf8:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f13fdfc:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f13fe00:	001f7080 */ 	sll	$t6,$ra,0x2
/*  f13fe04:	01df7021 */ 	addu	$t6,$t6,$ra
/*  f13fe08:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f13fe0c:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f13fe10:	24e7000a */ 	addiu	$a3,$a3,0xa
/*  f13fe14:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f13fe18:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f13fe1c:	010f4021 */ 	addu	$t0,$t0,$t7
/*  f13fe20:	14600012 */ 	bnez	$v1,.NB0f13fe6c
/*  f13fe24:	24e7000a */ 	addiu	$a3,$a3,0xa
/*  f13fe28:	30af0404 */ 	andi	$t7,$a1,0x404
/*  f13fe2c:	11e00002 */ 	beqz	$t7,.NB0f13fe38
/*  f13fe30:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f13fe34:	24130028 */ 	addiu	$s3,$zero,0x28
.NB0f13fe38:
/*  f13fe38:	30ce0404 */ 	andi	$t6,$a2,0x404
/*  f13fe3c:	11c00004 */ 	beqz	$t6,.NB0f13fe50
/*  f13fe40:	02a01825 */ 	or	$v1,$s5,$zero
/*  f13fe44:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f13fe48:	327800ff */ 	andi	$t8,$s3,0xff
/*  f13fe4c:	03009825 */ 	or	$s3,$t8,$zero
.NB0f13fe50:
/*  f13fe50:	327900ff */ 	andi	$t9,$s3,0xff
/*  f13fe54:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f13fe58:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f13fe5c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f13fe60:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13fe64:	10000028 */ 	beqz	$zero,.NB0f13ff08
/*  f13fe68:	ac690000 */ 	sw	$t1,0x0($v1)
.NB0f13fe6c:
/*  f13fe6c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13fe70:	14610013 */ 	bne	$v1,$at,.NB0f13fec0
/*  f13fe74:	30ae0404 */ 	andi	$t6,$a1,0x404
/*  f13fe78:	30b80404 */ 	andi	$t8,$a1,0x404
/*  f13fe7c:	13000002 */ 	beqz	$t8,.NB0f13fe88
/*  f13fe80:	2413007f */ 	addiu	$s3,$zero,0x7f
/*  f13fe84:	241300be */ 	addiu	$s3,$zero,0xbe
.NB0f13fe88:
/*  f13fe88:	30d90404 */ 	andi	$t9,$a2,0x404
/*  f13fe8c:	13200004 */ 	beqz	$t9,.NB0f13fea0
/*  f13fe90:	02a01825 */ 	or	$v1,$s5,$zero
/*  f13fe94:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f13fe98:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f13fe9c:	01e09825 */ 	or	$s3,$t7,$zero
.NB0f13fea0:
/*  f13fea0:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f13fea4:	000ec200 */ 	sll	$t8,$t6,0x8
/*  f13fea8:	030bc825 */ 	or	$t9,$t8,$t3
/*  f13feac:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f13feb0:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f13feb4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13feb8:	10000013 */ 	beqz	$zero,.NB0f13ff08
/*  f13febc:	ac690000 */ 	sw	$t1,0x0($v1)
.NB0f13fec0:
/*  f13fec0:	11c00002 */ 	beqz	$t6,.NB0f13fecc
/*  f13fec4:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f13fec8:	24130028 */ 	addiu	$s3,$zero,0x28
.NB0f13fecc:
/*  f13fecc:	30d80404 */ 	andi	$t8,$a2,0x404
/*  f13fed0:	13000004 */ 	beqz	$t8,.NB0f13fee4
/*  f13fed4:	02a01825 */ 	or	$v1,$s5,$zero
/*  f13fed8:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f13fedc:	327900ff */ 	andi	$t9,$s3,0xff
/*  f13fee0:	03209825 */ 	or	$s3,$t9,$zero
.NB0f13fee4:
/*  f13fee4:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f13fee8:	331900ff */ 	andi	$t9,$t8,0xff
/*  f13feec:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f13fef0:	00137600 */ 	sll	$t6,$s3,0x18
/*  f13fef4:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f13fef8:	371900ff */ 	ori	$t9,$t8,0xff
/*  f13fefc:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f13ff00:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13ff04:	ac690000 */ 	sw	$t1,0x0($v1)
.NB0f13ff08:
/*  f13ff08:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f13ff0c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f13ff10:	3c01f600 */ 	lui	$at,0xf600
/*  f13ff14:	01e1c025 */ 	or	$t8,$t7,$at
/*  f13ff18:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f13ff1c:	8fbf0294 */ 	lw	$ra,0x294($sp)
/*  f13ff20:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f13ff24:	030cc825 */ 	or	$t9,$t8,$t4
/*  f13ff28:	02a02025 */ 	or	$a0,$s5,$zero
/*  f13ff2c:	01edc025 */ 	or	$t8,$t7,$t5
/*  f13ff30:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f13ff34:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f13ff38:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f13ff3c:	001fc880 */ 	sll	$t9,$ra,0x2
/*  f13ff40:	001f7080 */ 	sll	$t6,$ra,0x2
/*  f13ff44:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f13ff48:	01df7021 */ 	addu	$t6,$t6,$ra
/*  f13ff4c:	033fc821 */ 	addu	$t9,$t9,$ra
/*  f13ff50:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f13ff54:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f13ff58:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f13ff5c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13ff60:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f13ff64:	14600012 */ 	bnez	$v1,.NB0f13ffb0
/*  f13ff68:	01194021 */ 	addu	$t0,$t0,$t9
/*  f13ff6c:	30b90202 */ 	andi	$t9,$a1,0x202
/*  f13ff70:	13200002 */ 	beqz	$t9,.NB0f13ff7c
/*  f13ff74:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f13ff78:	24130028 */ 	addiu	$s3,$zero,0x28
.NB0f13ff7c:
/*  f13ff7c:	30ce0202 */ 	andi	$t6,$a2,0x202
/*  f13ff80:	11c00004 */ 	beqz	$t6,.NB0f13ff94
/*  f13ff84:	02a01825 */ 	or	$v1,$s5,$zero
/*  f13ff88:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f13ff8c:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f13ff90:	01e09825 */ 	or	$s3,$t7,$zero
.NB0f13ff94:
/*  f13ff94:	327800ff */ 	andi	$t8,$s3,0xff
/*  f13ff98:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f13ff9c:	372e00ff */ 	ori	$t6,$t9,0xff
/*  f13ffa0:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f13ffa4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13ffa8:	10000028 */ 	beqz	$zero,.NB0f14004c
/*  f13ffac:	ac690000 */ 	sw	$t1,0x0($v1)
.NB0f13ffb0:
/*  f13ffb0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f13ffb4:	14610013 */ 	bne	$v1,$at,.NB0f140004
/*  f13ffb8:	30ae0202 */ 	andi	$t6,$a1,0x202
/*  f13ffbc:	30af0202 */ 	andi	$t7,$a1,0x202
/*  f13ffc0:	11e00002 */ 	beqz	$t7,.NB0f13ffcc
/*  f13ffc4:	2413007f */ 	addiu	$s3,$zero,0x7f
/*  f13ffc8:	241300be */ 	addiu	$s3,$zero,0xbe
.NB0f13ffcc:
/*  f13ffcc:	30d80202 */ 	andi	$t8,$a2,0x202
/*  f13ffd0:	13000004 */ 	beqz	$t8,.NB0f13ffe4
/*  f13ffd4:	02a01825 */ 	or	$v1,$s5,$zero
/*  f13ffd8:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f13ffdc:	327900ff */ 	andi	$t9,$s3,0xff
/*  f13ffe0:	03209825 */ 	or	$s3,$t9,$zero
.NB0f13ffe4:
/*  f13ffe4:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f13ffe8:	000e7a00 */ 	sll	$t7,$t6,0x8
/*  f13ffec:	01ebc025 */ 	or	$t8,$t7,$t3
/*  f13fff0:	371900ff */ 	ori	$t9,$t8,0xff
/*  f13fff4:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f13fff8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f13fffc:	10000013 */ 	beqz	$zero,.NB0f14004c
/*  f140000:	ac690000 */ 	sw	$t1,0x0($v1)
.NB0f140004:
/*  f140004:	11c00002 */ 	beqz	$t6,.NB0f140010
/*  f140008:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f14000c:	24130028 */ 	addiu	$s3,$zero,0x28
.NB0f140010:
/*  f140010:	30cf0202 */ 	andi	$t7,$a2,0x202
/*  f140014:	11e00004 */ 	beqz	$t7,.NB0f140028
/*  f140018:	02a01825 */ 	or	$v1,$s5,$zero
/*  f14001c:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f140020:	327800ff */ 	andi	$t8,$s3,0xff
/*  f140024:	03009825 */ 	or	$s3,$t8,$zero
.NB0f140028:
/*  f140028:	00137883 */ 	sra	$t7,$s3,0x2
/*  f14002c:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f140030:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f140034:	00137600 */ 	sll	$t6,$s3,0x18
/*  f140038:	01d97825 */ 	or	$t7,$t6,$t9
/*  f14003c:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f140040:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f140044:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140048:	ac690000 */ 	sw	$t1,0x0($v1)
.NB0f14004c:
/*  f14004c:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f140050:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f140054:	3c01f600 */ 	lui	$at,0xf600
/*  f140058:	03217825 */ 	or	$t7,$t9,$at
/*  f14005c:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f140060:	8fbf0294 */ 	lw	$ra,0x294($sp)
/*  f140064:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f140068:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f14006c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f140070:	032d7825 */ 	or	$t7,$t9,$t5
/*  f140074:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f140078:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f14007c:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f140080:	001fc080 */ 	sll	$t8,$ra,0x2
/*  f140084:	001f7080 */ 	sll	$t6,$ra,0x2
/*  f140088:	8f2f0480 */ 	lw	$t7,0x480($t9)
/*  f14008c:	01df7021 */ 	addu	$t6,$t6,$ra
/*  f140090:	031fc021 */ 	addu	$t8,$t8,$ra
/*  f140094:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f140098:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f14009c:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f1400a0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1400a4:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f1400a8:	01184021 */ 	addu	$t0,$t0,$t8
/*  f1400ac:	14600012 */ 	bnez	$v1,.NB0f1400f8
/*  f1400b0:	24e7000a */ 	addiu	$a3,$a3,0xa
/*  f1400b4:	30b80101 */ 	andi	$t8,$a1,0x101
/*  f1400b8:	13000002 */ 	beqz	$t8,.NB0f1400c4
/*  f1400bc:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f1400c0:	24130028 */ 	addiu	$s3,$zero,0x28
.NB0f1400c4:
/*  f1400c4:	30ce0101 */ 	andi	$t6,$a2,0x101
/*  f1400c8:	11c00004 */ 	beqz	$t6,.NB0f1400dc
/*  f1400cc:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1400d0:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f1400d4:	327900ff */ 	andi	$t9,$s3,0xff
/*  f1400d8:	03209825 */ 	or	$s3,$t9,$zero
.NB0f1400dc:
/*  f1400dc:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f1400e0:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f1400e4:	370e00ff */ 	ori	$t6,$t8,0xff
/*  f1400e8:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f1400ec:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1400f0:	10000028 */ 	beqz	$zero,.NB0f140194
/*  f1400f4:	ac690000 */ 	sw	$t1,0x0($v1)
.NB0f1400f8:
/*  f1400f8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1400fc:	14610013 */ 	bne	$v1,$at,.NB0f14014c
/*  f140100:	30ae0101 */ 	andi	$t6,$a1,0x101
/*  f140104:	30b90101 */ 	andi	$t9,$a1,0x101
/*  f140108:	13200002 */ 	beqz	$t9,.NB0f140114
/*  f14010c:	2413007f */ 	addiu	$s3,$zero,0x7f
/*  f140110:	241300be */ 	addiu	$s3,$zero,0xbe
.NB0f140114:
/*  f140114:	30cf0101 */ 	andi	$t7,$a2,0x101
/*  f140118:	11e00004 */ 	beqz	$t7,.NB0f14012c
/*  f14011c:	02a01825 */ 	or	$v1,$s5,$zero
/*  f140120:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f140124:	327800ff */ 	andi	$t8,$s3,0xff
/*  f140128:	03009825 */ 	or	$s3,$t8,$zero
.NB0f14012c:
/*  f14012c:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f140130:	000eca00 */ 	sll	$t9,$t6,0x8
/*  f140134:	032b7825 */ 	or	$t7,$t9,$t3
/*  f140138:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f14013c:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f140140:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140144:	10000013 */ 	beqz	$zero,.NB0f140194
/*  f140148:	ac690000 */ 	sw	$t1,0x0($v1)
.NB0f14014c:
/*  f14014c:	11c00002 */ 	beqz	$t6,.NB0f140158
/*  f140150:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f140154:	24130028 */ 	addiu	$s3,$zero,0x28
.NB0f140158:
/*  f140158:	30d90101 */ 	andi	$t9,$a2,0x101
/*  f14015c:	13200004 */ 	beqz	$t9,.NB0f140170
/*  f140160:	02a01825 */ 	or	$v1,$s5,$zero
/*  f140164:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f140168:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f14016c:	01e09825 */ 	or	$s3,$t7,$zero
.NB0f140170:
/*  f140170:	0013c883 */ 	sra	$t9,$s3,0x2
/*  f140174:	332f00ff */ 	andi	$t7,$t9,0xff
/*  f140178:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f14017c:	00137600 */ 	sll	$t6,$s3,0x18
/*  f140180:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f140184:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f140188:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f14018c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140190:	ac690000 */ 	sw	$t1,0x0($v1)
.NB0f140194:
/*  f140194:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f140198:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f14019c:	3c01f600 */ 	lui	$at,0xf600
/*  f1401a0:	0301c825 */ 	or	$t9,$t8,$at
/*  f1401a4:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f1401a8:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f1401ac:	032c7825 */ 	or	$t7,$t9,$t4
/*  f1401b0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1401b4:	030dc825 */ 	or	$t9,$t8,$t5
/*  f1401b8:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f1401bc:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f1401c0:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f1401c4:	8faf0294 */ 	lw	$t7,0x294($sp)
/*  f1401c8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1401cc:	8f190480 */ 	lw	$t9,0x480($t8)
/*  f1401d0:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f1401d4:	01cf7021 */ 	addu	$t6,$t6,$t7
/*  f1401d8:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f1401dc:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f1401e0:	010e4021 */ 	addu	$t0,$t0,$t6
/*  f1401e4:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f1401e8:	14600012 */ 	bnez	$v1,.NB0f140234
/*  f1401ec:	24e7000a */ 	addiu	$a3,$a3,0xa
/*  f1401f0:	30af0030 */ 	andi	$t7,$a1,0x30
/*  f1401f4:	11e00002 */ 	beqz	$t7,.NB0f140200
/*  f1401f8:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f1401fc:	24130028 */ 	addiu	$s3,$zero,0x28
.NB0f140200:
/*  f140200:	30ce0030 */ 	andi	$t6,$a2,0x30
/*  f140204:	11c00004 */ 	beqz	$t6,.NB0f140218
/*  f140208:	02a01825 */ 	or	$v1,$s5,$zero
/*  f14020c:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f140210:	327800ff */ 	andi	$t8,$s3,0xff
/*  f140214:	03009825 */ 	or	$s3,$t8,$zero
.NB0f140218:
/*  f140218:	327900ff */ 	andi	$t9,$s3,0xff
/*  f14021c:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f140220:	35ee00ff */ 	ori	$t6,$t7,0xff
/*  f140224:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f140228:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14022c:	10000028 */ 	beqz	$zero,.NB0f1402d0
/*  f140230:	ac690000 */ 	sw	$t1,0x0($v1)
.NB0f140234:
/*  f140234:	24010001 */ 	addiu	$at,$zero,0x1
/*  f140238:	14610013 */ 	bne	$v1,$at,.NB0f140288
/*  f14023c:	30ae0030 */ 	andi	$t6,$a1,0x30
/*  f140240:	30b80030 */ 	andi	$t8,$a1,0x30
/*  f140244:	13000002 */ 	beqz	$t8,.NB0f140250
/*  f140248:	2413007f */ 	addiu	$s3,$zero,0x7f
/*  f14024c:	241300be */ 	addiu	$s3,$zero,0xbe
.NB0f140250:
/*  f140250:	30d90030 */ 	andi	$t9,$a2,0x30
/*  f140254:	13200004 */ 	beqz	$t9,.NB0f140268
/*  f140258:	02a01825 */ 	or	$v1,$s5,$zero
/*  f14025c:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f140260:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f140264:	01e09825 */ 	or	$s3,$t7,$zero
.NB0f140268:
/*  f140268:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f14026c:	000ec200 */ 	sll	$t8,$t6,0x8
/*  f140270:	030bc825 */ 	or	$t9,$t8,$t3
/*  f140274:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f140278:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f14027c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140280:	10000013 */ 	beqz	$zero,.NB0f1402d0
/*  f140284:	ac690000 */ 	sw	$t1,0x0($v1)
.NB0f140288:
/*  f140288:	11c00002 */ 	beqz	$t6,.NB0f140294
/*  f14028c:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f140290:	24130028 */ 	addiu	$s3,$zero,0x28
.NB0f140294:
/*  f140294:	30d80030 */ 	andi	$t8,$a2,0x30
/*  f140298:	13000004 */ 	beqz	$t8,.NB0f1402ac
/*  f14029c:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1402a0:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f1402a4:	327900ff */ 	andi	$t9,$s3,0xff
/*  f1402a8:	03209825 */ 	or	$s3,$t9,$zero
.NB0f1402ac:
/*  f1402ac:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f1402b0:	331900ff */ 	andi	$t9,$t8,0xff
/*  f1402b4:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f1402b8:	00137600 */ 	sll	$t6,$s3,0x18
/*  f1402bc:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f1402c0:	371900ff */ 	ori	$t9,$t8,0xff
/*  f1402c4:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f1402c8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1402cc:	ac690000 */ 	sw	$t1,0x0($v1)
.NB0f1402d0:
/*  f1402d0:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f1402d4:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1402d8:	3c01f600 */ 	lui	$at,0xf600
/*  f1402dc:	01e1c025 */ 	or	$t8,$t7,$at
/*  f1402e0:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f1402e4:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1402e8:	030cc825 */ 	or	$t9,$t8,$t4
/*  f1402ec:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1402f0:	01edc025 */ 	or	$t8,$t7,$t5
/*  f1402f4:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f1402f8:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f1402fc:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f140300:	8fb90294 */ 	lw	$t9,0x294($sp)
/*  f140304:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140308:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f14030c:	00197080 */ 	sll	$t6,$t9,0x2
/*  f140310:	01d97021 */ 	addu	$t6,$t6,$t9
/*  f140314:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f140318:	000e7040 */ 	sll	$t6,$t6,0x1
/*  f14031c:	010e4021 */ 	addu	$t0,$t0,$t6
/*  f140320:	14600012 */ 	bnez	$v1,.NB0f14036c
/*  f140324:	014e5021 */ 	addu	$t2,$t2,$t6
/*  f140328:	30b92000 */ 	andi	$t9,$a1,0x2000
/*  f14032c:	13200002 */ 	beqz	$t9,.NB0f140338
/*  f140330:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f140334:	24130028 */ 	addiu	$s3,$zero,0x28
.NB0f140338:
/*  f140338:	30ce2000 */ 	andi	$t6,$a2,0x2000
/*  f14033c:	11c00004 */ 	beqz	$t6,.NB0f140350
/*  f140340:	02a01825 */ 	or	$v1,$s5,$zero
/*  f140344:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f140348:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f14034c:	01e09825 */ 	or	$s3,$t7,$zero
.NB0f140350:
/*  f140350:	327800ff */ 	andi	$t8,$s3,0xff
/*  f140354:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f140358:	372e00ff */ 	ori	$t6,$t9,0xff
/*  f14035c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f140360:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140364:	10000028 */ 	beqz	$zero,.NB0f140408
/*  f140368:	ac690000 */ 	sw	$t1,0x0($v1)
.NB0f14036c:
/*  f14036c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f140370:	14610013 */ 	bne	$v1,$at,.NB0f1403c0
/*  f140374:	30ae2000 */ 	andi	$t6,$a1,0x2000
/*  f140378:	30af2000 */ 	andi	$t7,$a1,0x2000
/*  f14037c:	11e00002 */ 	beqz	$t7,.NB0f140388
/*  f140380:	2413007f */ 	addiu	$s3,$zero,0x7f
/*  f140384:	241300be */ 	addiu	$s3,$zero,0xbe
.NB0f140388:
/*  f140388:	30d82000 */ 	andi	$t8,$a2,0x2000
/*  f14038c:	13000004 */ 	beqz	$t8,.NB0f1403a0
/*  f140390:	02a01825 */ 	or	$v1,$s5,$zero
/*  f140394:	2673003f */ 	addiu	$s3,$s3,0x3f
/*  f140398:	327900ff */ 	andi	$t9,$s3,0xff
/*  f14039c:	03209825 */ 	or	$s3,$t9,$zero
.NB0f1403a0:
/*  f1403a0:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f1403a4:	000e7a00 */ 	sll	$t7,$t6,0x8
/*  f1403a8:	01ebc025 */ 	or	$t8,$t7,$t3
/*  f1403ac:	371900ff */ 	ori	$t9,$t8,0xff
/*  f1403b0:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f1403b4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1403b8:	10000013 */ 	beqz	$zero,.NB0f140408
/*  f1403bc:	ac690000 */ 	sw	$t1,0x0($v1)
.NB0f1403c0:
/*  f1403c0:	11c00002 */ 	beqz	$t6,.NB0f1403cc
/*  f1403c4:	24130014 */ 	addiu	$s3,$zero,0x14
/*  f1403c8:	24130028 */ 	addiu	$s3,$zero,0x28
.NB0f1403cc:
/*  f1403cc:	30cf2000 */ 	andi	$t7,$a2,0x2000
/*  f1403d0:	11e00004 */ 	beqz	$t7,.NB0f1403e4
/*  f1403d4:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1403d8:	26730014 */ 	addiu	$s3,$s3,0x14
/*  f1403dc:	327800ff */ 	andi	$t8,$s3,0xff
/*  f1403e0:	03009825 */ 	or	$s3,$t8,$zero
.NB0f1403e4:
/*  f1403e4:	00137883 */ 	sra	$t7,$s3,0x2
/*  f1403e8:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f1403ec:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f1403f0:	00137600 */ 	sll	$t6,$s3,0x18
/*  f1403f4:	01d97825 */ 	or	$t7,$t6,$t9
/*  f1403f8:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f1403fc:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f140400:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140404:	ac690000 */ 	sw	$t1,0x0($v1)
.NB0f140408:
/*  f140408:	314e03ff */ 	andi	$t6,$t2,0x3ff
/*  f14040c:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f140410:	3c01f600 */ 	lui	$at,0xf600
/*  f140414:	03217825 */ 	or	$t7,$t9,$at
/*  f140418:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f14041c:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f140420:	01ecc025 */ 	or	$t8,$t7,$t4
/*  f140424:	02a01825 */ 	or	$v1,$s5,$zero
/*  f140428:	032d7825 */ 	or	$t7,$t9,$t5
/*  f14042c:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f140430:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f140434:	8fb80294 */ 	lw	$t8,0x294($sp)
/*  f140438:	24010002 */ 	addiu	$at,$zero,0x2
/*  f14043c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140440:	17010003 */ 	bne	$t8,$at,.NB0f140450
/*  f140444:	83a4023d */ 	lb	$a0,0x23d($sp)
/*  f140448:	10000002 */ 	beqz	$zero,.NB0f140454
/*  f14044c:	2407ffd0 */ 	addiu	$a3,$zero,-48
.NB0f140450:
/*  f140450:	2407ffc9 */ 	addiu	$a3,$zero,-55
.NB0f140454:
/*  f140454:	44843000 */ 	mtc1	$a0,$f6
/*  f140458:	3c0142c0 */ 	lui	$at,0x42c0
/*  f14045c:	44817000 */ 	mtc1	$at,$f14
/*  f140460:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f140464:	3c0142a0 */ 	lui	$at,0x42a0
/*  f140468:	44818000 */ 	mtc1	$at,$f16
/*  f14046c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f140470:	00022e00 */ 	sll	$a1,$v0,0x18
/*  f140474:	460e6282 */ 	mul.s	$f10,$f12,$f14
/*  f140478:	46105103 */ 	div.s	$f4,$f10,$f16
/*  f14047c:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f140480:	44034000 */ 	mfc1	$v1,$f8
/*  f140484:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140488:	04610005 */ 	bgez	$v1,.NB0f1404a0
/*  f14048c:	307300ff */ 	andi	$s3,$v1,0xff
/*  f140490:	00039823 */ 	negu	$s3,$v1
/*  f140494:	327900ff */ 	andi	$t9,$s3,0xff
/*  f140498:	10000001 */ 	beqz	$zero,.NB0f1404a0
/*  f14049c:	03209825 */ 	or	$s3,$t9,$zero
.NB0f1404a0:
/*  f1404a0:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f1404a4:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f1404a8:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f1404ac:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f1404b0:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f1404b4:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f1404b8:	14600006 */ 	bnez	$v1,.NB0f1404d4
/*  f1404bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1404c0:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1404c4:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1404c8:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f1404cc:	10000031 */ 	beqz	$zero,.NB0f140594
/*  f1404d0:	26b50008 */ 	addiu	$s5,$s5,0x8
.NB0f1404d4:
/*  f1404d4:	14610026 */ 	bne	$v1,$at,.NB0f140570
/*  f1404d8:	0013ce00 */ 	sll	$t9,$s3,0x18
/*  f1404dc:	44933000 */ 	mtc1	$s3,$f6
/*  f1404e0:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1404e4:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1404e8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1404ec:	06610005 */ 	bgez	$s3,.NB0f140504
/*  f1404f0:	46803020 */ 	cvt.s.w	$f0,$f6
/*  f1404f4:	3c014f80 */ 	lui	$at,0x4f80
/*  f1404f8:	44815000 */ 	mtc1	$at,$f10
/*  f1404fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140500:	460a0000 */ 	add.s	$f0,$f0,$f10
.NB0f140504:
/*  f140504:	460e0083 */ 	div.s	$f2,$f0,$f14
/*  f140508:	3c014180 */ 	lui	$at,0x4180
/*  f14050c:	44812000 */ 	mtc1	$at,$f4
/*  f140510:	3c014200 */ 	lui	$at,0x4200
/*  f140514:	44815000 */ 	mtc1	$at,$f10
/*  f140518:	3c014020 */ 	lui	$at,0x4020
/*  f14051c:	46041202 */ 	mul.s	$f8,$f2,$f4
/*  f140520:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f140524:	460a1102 */ 	mul.s	$f4,$f2,$f10
/*  f140528:	44193000 */ 	mfc1	$t9,$f6
/*  f14052c:	44813000 */ 	mtc1	$at,$f6
/*  f140530:	00197e00 */ 	sll	$t7,$t9,0x18
/*  f140534:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f140538:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f14053c:	440e4000 */ 	mfc1	$t6,$f8
/*  f140540:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f140544:	31d900ff */ 	andi	$t9,$t6,0xff
/*  f140548:	0019c400 */ 	sll	$t8,$t9,0x10
/*  f14054c:	01f87025 */ 	or	$t6,$t7,$t8
/*  f140550:	440f2000 */ 	mfc1	$t7,$f4
/*  f140554:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140558:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f14055c:	0018ca00 */ 	sll	$t9,$t8,0x8
/*  f140560:	01d97825 */ 	or	$t7,$t6,$t9
/*  f140564:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f140568:	1000000a */ 	beqz	$zero,.NB0f140594
/*  f14056c:	ac780004 */ 	sw	$t8,0x4($v1)
.NB0f140570:
/*  f140570:	00137883 */ 	sra	$t7,$s3,0x2
/*  f140574:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f140578:	00187400 */ 	sll	$t6,$t8,0x10
/*  f14057c:	02a01825 */ 	or	$v1,$s5,$zero
/*  f140580:	032e7825 */ 	or	$t7,$t9,$t6
/*  f140584:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f140588:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f14058c:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f140590:	26b50008 */ 	addiu	$s5,$s5,0x8
.NB0f140594:
/*  f140594:	18800027 */ 	blez	$a0,.NB0f140634
/*  f140598:	3c0141e0 */ 	lui	$at,0x41e0
/*  f14059c:	3c0141e0 */ 	lui	$at,0x41e0
/*  f1405a0:	44819000 */ 	mtc1	$at,$f18
/*  f1405a4:	8fb80294 */ 	lw	$t8,0x294($sp)
/*  f1405a8:	8fa602e8 */ 	lw	$a2,0x2e8($sp)
/*  f1405ac:	46126202 */ 	mul.s	$f8,$f12,$f18
/*  f1405b0:	3c01f600 */ 	lui	$at,0xf600
/*  f1405b4:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1405b8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1405bc:	46104183 */ 	div.s	$f6,$f8,$f16
/*  f1405c0:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f1405c4:	440e5000 */ 	mfc1	$t6,$f10
/*  f1405c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1405cc:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f1405d0:	01f80019 */ 	multu	$t7,$t8
/*  f1405d4:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f1405d8:	0000c812 */ 	mflo	$t9
/*  f1405dc:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f1405e0:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1405e4:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f1405e8:	24cf0015 */ 	addiu	$t7,$a2,0x15
/*  f1405ec:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1405f0:	03217025 */ 	or	$t6,$t9,$at
/*  f1405f4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1405f8:	01d97825 */ 	or	$t7,$t6,$t9
/*  f1405fc:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f140600:	8fb80294 */ 	lw	$t8,0x294($sp)
/*  f140604:	8fb90088 */ 	lw	$t9,0x88($sp)
/*  f140608:	00f80019 */ 	multu	$a3,$t8
/*  f14060c:	00007012 */ 	mflo	$t6
/*  f140610:	01d92021 */ 	addu	$a0,$t6,$t9
/*  f140614:	308f03ff */ 	andi	$t7,$a0,0x3ff
/*  f140618:	24ce0013 */ 	addiu	$t6,$a2,0x13
/*  f14061c:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f140620:	000f2380 */ 	sll	$a0,$t7,0xe
/*  f140624:	00197880 */ 	sll	$t7,$t9,0x2
/*  f140628:	008fc025 */ 	or	$t8,$a0,$t7
/*  f14062c:	10000027 */ 	beqz	$zero,.NB0f1406cc
/*  f140630:	ac780004 */ 	sw	$t8,0x4($v1)
.NB0f140634:
/*  f140634:	44819000 */ 	mtc1	$at,$f18
/*  f140638:	8fae0294 */ 	lw	$t6,0x294($sp)
/*  f14063c:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f140640:	46126102 */ 	mul.s	$f4,$f12,$f18
/*  f140644:	3c01f600 */ 	lui	$at,0xf600
/*  f140648:	00ee0019 */ 	multu	$a3,$t6
/*  f14064c:	02a01825 */ 	or	$v1,$s5,$zero
/*  f140650:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140654:	46102203 */ 	div.s	$f8,$f4,$f16
/*  f140658:	0000c812 */ 	mflo	$t9
/*  f14065c:	032f2021 */ 	addu	$a0,$t9,$t7
/*  f140660:	8faf02e8 */ 	lw	$t7,0x2e8($sp)
/*  f140664:	309803ff */ 	andi	$t8,$a0,0x3ff
/*  f140668:	00182380 */ 	sll	$a0,$t8,0xe
/*  f14066c:	25f80015 */ 	addiu	$t8,$t7,0x15
/*  f140670:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f140674:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f140678:	0081c825 */ 	or	$t9,$a0,$at
/*  f14067c:	032fc025 */ 	or	$t8,$t9,$t7
/*  f140680:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f140684:	8fb80294 */ 	lw	$t8,0x294($sp)
/*  f140688:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f14068c:	44193000 */ 	mfc1	$t9,$f6
/*  f140690:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140694:	03277821 */ 	addu	$t7,$t9,$a3
/*  f140698:	01f80019 */ 	multu	$t7,$t8
/*  f14069c:	8fb90088 */ 	lw	$t9,0x88($sp)
/*  f1406a0:	00007012 */ 	mflo	$t6
/*  f1406a4:	01d97821 */ 	addu	$t7,$t6,$t9
/*  f1406a8:	8fb902e8 */ 	lw	$t9,0x2e8($sp)
/*  f1406ac:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1406b0:	00187380 */ 	sll	$t6,$t8,0xe
/*  f1406b4:	272f0013 */ 	addiu	$t7,$t9,0x13
/*  f1406b8:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f1406bc:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1406c0:	01d97825 */ 	or	$t7,$t6,$t9
/*  f1406c4:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f1406c8:	8fa602e8 */ 	lw	$a2,0x2e8($sp)
.NB0f1406cc:
/*  f1406cc:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f1406d0:	03002825 */ 	or	$a1,$t8,$zero
/*  f1406d4:	44855000 */ 	mtc1	$a1,$f10
/*  f1406d8:	02a01025 */ 	or	$v0,$s5,$zero
/*  f1406dc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1406e0:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f1406e4:	460e6102 */ 	mul.s	$f4,$f12,$f14
/*  f1406e8:	46102203 */ 	div.s	$f8,$f4,$f16
/*  f1406ec:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f1406f0:	44033000 */ 	mfc1	$v1,$f6
/*  f1406f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1406f8:	04610005 */ 	bgez	$v1,.NB0f140710
/*  f1406fc:	307300ff */ 	andi	$s3,$v1,0xff
/*  f140700:	00039823 */ 	negu	$s3,$v1
/*  f140704:	327900ff */ 	andi	$t9,$s3,0xff
/*  f140708:	10000001 */ 	beqz	$zero,.NB0f140710
/*  f14070c:	03209825 */ 	or	$s3,$t9,$zero
.NB0f140710:
/*  f140710:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f140714:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f140718:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f14071c:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f140720:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f140724:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f140728:	14600005 */ 	bnez	$v1,.NB0f140740
/*  f14072c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140730:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140734:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f140738:	10000031 */ 	beqz	$zero,.NB0f140800
/*  f14073c:	ac4f0004 */ 	sw	$t7,0x4($v0)
.NB0f140740:
/*  f140740:	14610026 */ 	bne	$v1,$at,.NB0f1407dc
/*  f140744:	02a01025 */ 	or	$v0,$s5,$zero
/*  f140748:	44935000 */ 	mtc1	$s3,$f10
/*  f14074c:	02a01025 */ 	or	$v0,$s5,$zero
/*  f140750:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f140754:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140758:	06610005 */ 	bgez	$s3,.NB0f140770
/*  f14075c:	46805020 */ 	cvt.s.w	$f0,$f10
/*  f140760:	3c014f80 */ 	lui	$at,0x4f80
/*  f140764:	44812000 */ 	mtc1	$at,$f4
/*  f140768:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14076c:	46040000 */ 	add.s	$f0,$f0,$f4
.NB0f140770:
/*  f140770:	460e0083 */ 	div.s	$f2,$f0,$f14
/*  f140774:	3c014180 */ 	lui	$at,0x4180
/*  f140778:	44814000 */ 	mtc1	$at,$f8
/*  f14077c:	3c014200 */ 	lui	$at,0x4200
/*  f140780:	44812000 */ 	mtc1	$at,$f4
/*  f140784:	3c014020 */ 	lui	$at,0x4020
/*  f140788:	46081182 */ 	mul.s	$f6,$f2,$f8
/*  f14078c:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f140790:	46041202 */ 	mul.s	$f8,$f2,$f4
/*  f140794:	44195000 */ 	mfc1	$t9,$f10
/*  f140798:	44815000 */ 	mtc1	$at,$f10
/*  f14079c:	00197e00 */ 	sll	$t7,$t9,0x18
/*  f1407a0:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f1407a4:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f1407a8:	440e3000 */ 	mfc1	$t6,$f6
/*  f1407ac:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f1407b0:	31d900ff */ 	andi	$t9,$t6,0xff
/*  f1407b4:	0019c400 */ 	sll	$t8,$t9,0x10
/*  f1407b8:	01f87025 */ 	or	$t6,$t7,$t8
/*  f1407bc:	440f4000 */ 	mfc1	$t7,$f8
/*  f1407c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1407c4:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f1407c8:	0018ca00 */ 	sll	$t9,$t8,0x8
/*  f1407cc:	01d97825 */ 	or	$t7,$t6,$t9
/*  f1407d0:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f1407d4:	1000000a */ 	beqz	$zero,.NB0f140800
/*  f1407d8:	ac580004 */ 	sw	$t8,0x4($v0)
.NB0f1407dc:
/*  f1407dc:	00137883 */ 	sra	$t7,$s3,0x2
/*  f1407e0:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f1407e4:	00187400 */ 	sll	$t6,$t8,0x10
/*  f1407e8:	0013ce00 */ 	sll	$t9,$s3,0x18
/*  f1407ec:	032e7825 */ 	or	$t7,$t9,$t6
/*  f1407f0:	35f800ff */ 	ori	$t8,$t7,0xff
/*  f1407f4:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f1407f8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1407fc:	ac490000 */ 	sw	$t1,0x0($v0)
.NB0f140800:
/*  f140800:	18a0001d */ 	blez	$a1,.NB0f140878
/*  f140804:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140808:	46126182 */ 	mul.s	$f6,$f12,$f18
/*  f14080c:	8fb80294 */ 	lw	$t8,0x294($sp)
/*  f140810:	3c01f600 */ 	lui	$at,0xf600
/*  f140814:	02a01025 */ 	or	$v0,$s5,$zero
/*  f140818:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14081c:	46103283 */ 	div.s	$f10,$f6,$f16
/*  f140820:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f140824:	440e2000 */ 	mfc1	$t6,$f4
/*  f140828:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14082c:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f140830:	01f80019 */ 	multu	$t7,$t8
/*  f140834:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f140838:	0000c812 */ 	mflo	$t9
/*  f14083c:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f140840:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f140844:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f140848:	24cf0018 */ 	addiu	$t7,$a2,0x18
/*  f14084c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f140850:	03217025 */ 	or	$t6,$t9,$at
/*  f140854:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f140858:	01d97825 */ 	or	$t7,$t6,$t9
/*  f14085c:	24d80016 */ 	addiu	$t8,$a2,0x16
/*  f140860:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f140864:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f140868:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f14086c:	00997825 */ 	or	$t7,$a0,$t9
/*  f140870:	1000001c */ 	beqz	$zero,.NB0f1408e4
/*  f140874:	ac4f0004 */ 	sw	$t7,0x4($v0)
.NB0f140878:
/*  f140878:	46126202 */ 	mul.s	$f8,$f12,$f18
/*  f14087c:	24ce0018 */ 	addiu	$t6,$a2,0x18
/*  f140880:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f140884:	3c01f600 */ 	lui	$at,0xf600
/*  f140888:	0081c025 */ 	or	$t8,$a0,$at
/*  f14088c:	00197880 */ 	sll	$t7,$t9,0x2
/*  f140890:	030f7025 */ 	or	$t6,$t8,$t7
/*  f140894:	46104183 */ 	div.s	$f6,$f8,$f16
/*  f140898:	02a01025 */ 	or	$v0,$s5,$zero
/*  f14089c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f1408a0:	8fae0294 */ 	lw	$t6,0x294($sp)
/*  f1408a4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1408a8:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f1408ac:	44185000 */ 	mfc1	$t8,$f10
/*  f1408b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1408b4:	03077821 */ 	addu	$t7,$t8,$a3
/*  f1408b8:	01ee0019 */ 	multu	$t7,$t6
/*  f1408bc:	8fb80088 */ 	lw	$t8,0x88($sp)
/*  f1408c0:	0000c812 */ 	mflo	$t9
/*  f1408c4:	03387821 */ 	addu	$t7,$t9,$t8
/*  f1408c8:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f1408cc:	24d80016 */ 	addiu	$t8,$a2,0x16
/*  f1408d0:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f1408d4:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f1408d8:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f1408dc:	032ec025 */ 	or	$t8,$t9,$t6
/*  f1408e0:	ac580004 */ 	sw	$t8,0x4($v0)
.NB0f1408e4:
/*  f1408e4:	8ec40284 */ 	lw	$a0,0x284($s6)
/*  f1408e8:	c7a40060 */ 	lwc1	$f4,0x60($sp)
/*  f1408ec:	3c06f600 */ 	lui	$a2,0xf600
/*  f1408f0:	8c8f0480 */ 	lw	$t7,0x480($a0)
/*  f1408f4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1408f8:	91e3006b */ 	lbu	$v1,0x6b($t7)
/*  f1408fc:	14600158 */ 	bnez	$v1,.NB0f140e60
/*  f140900:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140904:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f140908:	8fb802d8 */ 	lw	$t8,0x2d8($sp)
/*  f14090c:	3c01420c */ 	lui	$at,0x420c
/*  f140910:	44816000 */ 	mtc1	$at,$f12
/*  f140914:	440e4000 */ 	mfc1	$t6,$f8
/*  f140918:	270ffff3 */ 	addiu	$t7,$t8,-13
/*  f14091c:	afaf02d0 */ 	sw	$t7,0x2d0($sp)
/*  f140920:	afae02d4 */ 	sw	$t6,0x2d4($sp)
/*  f140924:	8c990480 */ 	lw	$t9,0x480($a0)
/*  f140928:	3c0143b4 */ 	lui	$at,0x43b4
/*  f14092c:	44818000 */ 	mtc1	$at,$f16
/*  f140930:	c720001c */ 	lwc1	$f0,0x1c($t9)
/*  f140934:	02a01825 */ 	or	$v1,$s5,$zero
/*  f140938:	460e0182 */ 	mul.s	$f6,$f0,$f14
/*  f14093c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140940:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f140944:	46103283 */ 	div.s	$f10,$f6,$f16
/*  f140948:	46104183 */ 	div.s	$f6,$f8,$f16
/*  f14094c:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f140950:	44022000 */ 	mfc1	$v0,$f4
/*  f140954:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140958:	305300ff */ 	andi	$s3,$v0,0xff
/*  f14095c:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f140960:	440f5000 */ 	mfc1	$t7,$f10
/*  f140964:	04410005 */ 	bgez	$v0,.NB0f14097c
/*  f140968:	afaf02c8 */ 	sw	$t7,0x2c8($sp)
/*  f14096c:	00029823 */ 	negu	$s3,$v0
/*  f140970:	327900ff */ 	andi	$t9,$s3,0xff
/*  f140974:	10000001 */ 	beqz	$zero,.NB0f14097c
/*  f140978:	03209825 */ 	or	$s3,$t9,$zero
.NB0f14097c:
/*  f14097c:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f140980:	000ec400 */ 	sll	$t8,$t6,0x10
/*  f140984:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f140988:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f14098c:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f140990:	8fb902d4 */ 	lw	$t9,0x2d4($sp)
/*  f140994:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140998:	02a02025 */ 	or	$a0,$s5,$zero
/*  f14099c:	02997021 */ 	addu	$t6,$s4,$t9
/*  f1409a0:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f1409a4:	8fae02d0 */ 	lw	$t6,0x2d0($sp)
/*  f1409a8:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f1409ac:	01e6c825 */ 	or	$t9,$t7,$a2
/*  f1409b0:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f1409b4:	00187880 */ 	sll	$t7,$t8,0x2
/*  f1409b8:	032f7025 */ 	or	$t6,$t9,$t7
/*  f1409bc:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f1409c0:	8fb902c8 */ 	lw	$t9,0x2c8($sp)
/*  f1409c4:	8fb802d0 */ 	lw	$t8,0x2d0($sp)
/*  f1409c8:	3c013f00 */ 	lui	$at,0x3f00
/*  f1409cc:	44811000 */ 	mtc1	$at,$f2
/*  f1409d0:	03197823 */ 	subu	$t7,$t8,$t9
/*  f1409d4:	8fb902d4 */ 	lw	$t9,0x2d4($sp)
/*  f1409d8:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f1409dc:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f1409e0:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f1409e4:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f1409e8:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f1409ec:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f1409f0:	8fa50294 */ 	lw	$a1,0x294($sp)
/*  f1409f4:	8fae02d4 */ 	lw	$t6,0x2d4($sp)
/*  f1409f8:	3c013f80 */ 	lui	$at,0x3f80
/*  f1409fc:	00057840 */ 	sll	$t7,$a1,0x1
/*  f140a00:	01e02825 */ 	or	$a1,$t7,$zero
/*  f140a04:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f140a08:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f140a0c:	0314c821 */ 	addu	$t9,$t8,$s4
/*  f140a10:	afb902d4 */ 	sw	$t9,0x2d4($sp)
/*  f140a14:	8dee0480 */ 	lw	$t6,0x480($t7)
/*  f140a18:	44819000 */ 	mtc1	$at,$f18
/*  f140a1c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140a20:	c5c40020 */ 	lwc1	$f4,0x20($t6)
/*  f140a24:	02a01825 */ 	or	$v1,$s5,$zero
/*  f140a28:	46122000 */ 	add.s	$f0,$f4,$f18
/*  f140a2c:	460e0202 */ 	mul.s	$f8,$f0,$f14
/*  f140a30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140a34:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f140a38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140a3c:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f140a40:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f140a44:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f140a48:	44025000 */ 	mfc1	$v0,$f10
/*  f140a4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140a50:	305300ff */ 	andi	$s3,$v0,0xff
/*  f140a54:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f140a58:	440f3000 */ 	mfc1	$t7,$f6
/*  f140a5c:	04410005 */ 	bgez	$v0,.NB0f140a74
/*  f140a60:	afaf02c8 */ 	sw	$t7,0x2c8($sp)
/*  f140a64:	00029823 */ 	negu	$s3,$v0
/*  f140a68:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f140a6c:	10000001 */ 	beqz	$zero,.NB0f140a74
/*  f140a70:	01c09825 */ 	or	$s3,$t6,$zero
.NB0f140a74:
/*  f140a74:	327800ff */ 	andi	$t8,$s3,0xff
/*  f140a78:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f140a7c:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f140a80:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f140a84:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f140a88:	8fae02d4 */ 	lw	$t6,0x2d4($sp)
/*  f140a8c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140a90:	02a02025 */ 	or	$a0,$s5,$zero
/*  f140a94:	028ec021 */ 	addu	$t8,$s4,$t6
/*  f140a98:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f140a9c:	8fb802d0 */ 	lw	$t8,0x2d0($sp)
/*  f140aa0:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f140aa4:	01e67025 */ 	or	$t6,$t7,$a2
/*  f140aa8:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f140aac:	00197880 */ 	sll	$t7,$t9,0x2
/*  f140ab0:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f140ab4:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f140ab8:	8fae02c8 */ 	lw	$t6,0x2c8($sp)
/*  f140abc:	8fb902d0 */ 	lw	$t9,0x2d0($sp)
/*  f140ac0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140ac4:	02a01825 */ 	or	$v1,$s5,$zero
/*  f140ac8:	032e7823 */ 	subu	$t7,$t9,$t6
/*  f140acc:	8fae02d4 */ 	lw	$t6,0x2d4($sp)
/*  f140ad0:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f140ad4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f140ad8:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f140adc:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f140ae0:	03197025 */ 	or	$t6,$t8,$t9
/*  f140ae4:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f140ae8:	8faf02d4 */ 	lw	$t7,0x2d4($sp)
/*  f140aec:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f140af0:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f140af4:	0314c821 */ 	addu	$t9,$t8,$s4
/*  f140af8:	afb902d4 */ 	sw	$t9,0x2d4($sp)
/*  f140afc:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f140b00:	c5ea0024 */ 	lwc1	$f10,0x24($t7)
/*  f140b04:	46125000 */ 	add.s	$f0,$f10,$f18
/*  f140b08:	460e0102 */ 	mul.s	$f4,$f0,$f14
/*  f140b0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140b10:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f140b14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140b18:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f140b1c:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f140b20:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f140b24:	44023000 */ 	mfc1	$v0,$f6
/*  f140b28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140b2c:	305300ff */ 	andi	$s3,$v0,0xff
/*  f140b30:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f140b34:	440e4000 */ 	mfc1	$t6,$f8
/*  f140b38:	04410005 */ 	bgez	$v0,.NB0f140b50
/*  f140b3c:	afae02c8 */ 	sw	$t6,0x2c8($sp)
/*  f140b40:	00029823 */ 	negu	$s3,$v0
/*  f140b44:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f140b48:	10000001 */ 	beqz	$zero,.NB0f140b50
/*  f140b4c:	01e09825 */ 	or	$s3,$t7,$zero
.NB0f140b50:
/*  f140b50:	327800ff */ 	andi	$t8,$s3,0xff
/*  f140b54:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f140b58:	372e00ff */ 	ori	$t6,$t9,0xff
/*  f140b5c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f140b60:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f140b64:	8faf02d4 */ 	lw	$t7,0x2d4($sp)
/*  f140b68:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140b6c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f140b70:	028fc021 */ 	addu	$t8,$s4,$t7
/*  f140b74:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f140b78:	8fb802d0 */ 	lw	$t8,0x2d0($sp)
/*  f140b7c:	00197380 */ 	sll	$t6,$t9,0xe
/*  f140b80:	01c67825 */ 	or	$t7,$t6,$a2
/*  f140b84:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f140b88:	00197080 */ 	sll	$t6,$t9,0x2
/*  f140b8c:	01eec025 */ 	or	$t8,$t7,$t6
/*  f140b90:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f140b94:	8faf02c8 */ 	lw	$t7,0x2c8($sp)
/*  f140b98:	8fb902d0 */ 	lw	$t9,0x2d0($sp)
/*  f140b9c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140ba0:	02a01825 */ 	or	$v1,$s5,$zero
/*  f140ba4:	032f7023 */ 	subu	$t6,$t9,$t7
/*  f140ba8:	8faf02d4 */ 	lw	$t7,0x2d4($sp)
/*  f140bac:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f140bb0:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f140bb4:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f140bb8:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f140bbc:	03197825 */ 	or	$t7,$t8,$t9
/*  f140bc0:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f140bc4:	8fae02d4 */ 	lw	$t6,0x2d4($sp)
/*  f140bc8:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f140bcc:	01c5c021 */ 	addu	$t8,$t6,$a1
/*  f140bd0:	0314c821 */ 	addu	$t9,$t8,$s4
/*  f140bd4:	afb902d4 */ 	sw	$t9,0x2d4($sp)
/*  f140bd8:	8dee0480 */ 	lw	$t6,0x480($t7)
/*  f140bdc:	c5c00028 */ 	lwc1	$f0,0x28($t6)
/*  f140be0:	460e0182 */ 	mul.s	$f6,$f0,$f14
/*  f140be4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140be8:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f140bec:	46103283 */ 	div.s	$f10,$f6,$f16
/*  f140bf0:	46104183 */ 	div.s	$f6,$f8,$f16
/*  f140bf4:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f140bf8:	44022000 */ 	mfc1	$v0,$f4
/*  f140bfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140c00:	305300ff */ 	andi	$s3,$v0,0xff
/*  f140c04:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f140c08:	440f5000 */ 	mfc1	$t7,$f10
/*  f140c0c:	04410005 */ 	bgez	$v0,.NB0f140c24
/*  f140c10:	afaf02c8 */ 	sw	$t7,0x2c8($sp)
/*  f140c14:	00029823 */ 	negu	$s3,$v0
/*  f140c18:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f140c1c:	10000001 */ 	beqz	$zero,.NB0f140c24
/*  f140c20:	01c09825 */ 	or	$s3,$t6,$zero
.NB0f140c24:
/*  f140c24:	327800ff */ 	andi	$t8,$s3,0xff
/*  f140c28:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f140c2c:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f140c30:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f140c34:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f140c38:	8fae02d4 */ 	lw	$t6,0x2d4($sp)
/*  f140c3c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140c40:	02a02025 */ 	or	$a0,$s5,$zero
/*  f140c44:	028ec021 */ 	addu	$t8,$s4,$t6
/*  f140c48:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f140c4c:	8fb802d0 */ 	lw	$t8,0x2d0($sp)
/*  f140c50:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f140c54:	01e67025 */ 	or	$t6,$t7,$a2
/*  f140c58:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f140c5c:	00197880 */ 	sll	$t7,$t9,0x2
/*  f140c60:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f140c64:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f140c68:	8fae02c8 */ 	lw	$t6,0x2c8($sp)
/*  f140c6c:	8fb902d0 */ 	lw	$t9,0x2d0($sp)
/*  f140c70:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140c74:	02a01825 */ 	or	$v1,$s5,$zero
/*  f140c78:	032e7823 */ 	subu	$t7,$t9,$t6
/*  f140c7c:	8fae02d4 */ 	lw	$t6,0x2d4($sp)
/*  f140c80:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f140c84:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f140c88:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f140c8c:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f140c90:	03197025 */ 	or	$t6,$t8,$t9
/*  f140c94:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f140c98:	8faf02d4 */ 	lw	$t7,0x2d4($sp)
/*  f140c9c:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f140ca0:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f140ca4:	0314c821 */ 	addu	$t9,$t8,$s4
/*  f140ca8:	afb902d4 */ 	sw	$t9,0x2d4($sp)
/*  f140cac:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f140cb0:	c5e4002c */ 	lwc1	$f4,0x2c($t7)
/*  f140cb4:	46122000 */ 	add.s	$f0,$f4,$f18
/*  f140cb8:	460e0202 */ 	mul.s	$f8,$f0,$f14
/*  f140cbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140cc0:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f140cc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140cc8:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f140ccc:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f140cd0:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f140cd4:	44025000 */ 	mfc1	$v0,$f10
/*  f140cd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140cdc:	305300ff */ 	andi	$s3,$v0,0xff
/*  f140ce0:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f140ce4:	440e3000 */ 	mfc1	$t6,$f6
/*  f140ce8:	04410005 */ 	bgez	$v0,.NB0f140d00
/*  f140cec:	afae02c8 */ 	sw	$t6,0x2c8($sp)
/*  f140cf0:	00029823 */ 	negu	$s3,$v0
/*  f140cf4:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f140cf8:	10000001 */ 	beqz	$zero,.NB0f140d00
/*  f140cfc:	01e09825 */ 	or	$s3,$t7,$zero
.NB0f140d00:
/*  f140d00:	327800ff */ 	andi	$t8,$s3,0xff
/*  f140d04:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f140d08:	372e00ff */ 	ori	$t6,$t9,0xff
/*  f140d0c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f140d10:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f140d14:	8faf02d4 */ 	lw	$t7,0x2d4($sp)
/*  f140d18:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140d1c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f140d20:	028fc021 */ 	addu	$t8,$s4,$t7
/*  f140d24:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f140d28:	8fb802d0 */ 	lw	$t8,0x2d0($sp)
/*  f140d2c:	00197380 */ 	sll	$t6,$t9,0xe
/*  f140d30:	01c67825 */ 	or	$t7,$t6,$a2
/*  f140d34:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f140d38:	00197080 */ 	sll	$t6,$t9,0x2
/*  f140d3c:	01eec025 */ 	or	$t8,$t7,$t6
/*  f140d40:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f140d44:	8faf02c8 */ 	lw	$t7,0x2c8($sp)
/*  f140d48:	8fb902d0 */ 	lw	$t9,0x2d0($sp)
/*  f140d4c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140d50:	032f7023 */ 	subu	$t6,$t9,$t7
/*  f140d54:	8faf02d4 */ 	lw	$t7,0x2d4($sp)
/*  f140d58:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f140d5c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f140d60:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f140d64:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f140d68:	03197825 */ 	or	$t7,$t8,$t9
/*  f140d6c:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f140d70:	8fae02d4 */ 	lw	$t6,0x2d4($sp)
/*  f140d74:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f140d78:	01c5c021 */ 	addu	$t8,$t6,$a1
/*  f140d7c:	0314c821 */ 	addu	$t9,$t8,$s4
/*  f140d80:	afb902d4 */ 	sw	$t9,0x2d4($sp)
/*  f140d84:	8dee0480 */ 	lw	$t6,0x480($t7)
/*  f140d88:	c5ca0030 */ 	lwc1	$f10,0x30($t6)
/*  f140d8c:	46125000 */ 	add.s	$f0,$f10,$f18
/*  f140d90:	460e0102 */ 	mul.s	$f4,$f0,$f14
/*  f140d94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140d98:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f140d9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140da0:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f140da4:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f140da8:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f140dac:	44023000 */ 	mfc1	$v0,$f6
/*  f140db0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140db4:	305300ff */ 	andi	$s3,$v0,0xff
/*  f140db8:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f140dbc:	440f4000 */ 	mfc1	$t7,$f8
/*  f140dc0:	04410005 */ 	bgez	$v0,.NB0f140dd8
/*  f140dc4:	afaf02c8 */ 	sw	$t7,0x2c8($sp)
/*  f140dc8:	00029823 */ 	negu	$s3,$v0
/*  f140dcc:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f140dd0:	10000001 */ 	beqz	$zero,.NB0f140dd8
/*  f140dd4:	01c09825 */ 	or	$s3,$t6,$zero
.NB0f140dd8:
/*  f140dd8:	327800ff */ 	andi	$t8,$s3,0xff
/*  f140ddc:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f140de0:	02a01025 */ 	or	$v0,$s5,$zero
/*  f140de4:	372f00ff */ 	ori	$t7,$t9,0xff
/*  f140de8:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f140dec:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f140df0:	8fae02d4 */ 	lw	$t6,0x2d4($sp)
/*  f140df4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140df8:	02a01825 */ 	or	$v1,$s5,$zero
/*  f140dfc:	028ec021 */ 	addu	$t8,$s4,$t6
/*  f140e00:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f140e04:	8fb802d0 */ 	lw	$t8,0x2d0($sp)
/*  f140e08:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f140e0c:	01e67025 */ 	or	$t6,$t7,$a2
/*  f140e10:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f140e14:	00197880 */ 	sll	$t7,$t9,0x2
/*  f140e18:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f140e1c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f140e20:	8fae02c8 */ 	lw	$t6,0x2c8($sp)
/*  f140e24:	8fb902d0 */ 	lw	$t9,0x2d0($sp)
/*  f140e28:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140e2c:	032e7823 */ 	subu	$t7,$t9,$t6
/*  f140e30:	8fae02d4 */ 	lw	$t6,0x2d4($sp)
/*  f140e34:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f140e38:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f140e3c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f140e40:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f140e44:	03197025 */ 	or	$t6,$t8,$t9
/*  f140e48:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f140e4c:	8faf02d4 */ 	lw	$t7,0x2d4($sp)
/*  f140e50:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f140e54:	0314c821 */ 	addu	$t9,$t8,$s4
/*  f140e58:	100001a7 */ 	beqz	$zero,.NB0f1414f8
/*  f140e5c:	afb902d4 */ 	sw	$t9,0x2d4($sp)
.NB0f140e60:
/*  f140e60:	1461016c */ 	bne	$v1,$at,.NB0f141414
/*  f140e64:	c7a40060 */ 	lwc1	$f4,0x60($sp)
/*  f140e68:	c7a60060 */ 	lwc1	$f6,0x60($sp)
/*  f140e6c:	8fb802d8 */ 	lw	$t8,0x2d8($sp)
/*  f140e70:	3c01420c */ 	lui	$at,0x420c
/*  f140e74:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f140e78:	2719fff3 */ 	addiu	$t9,$t8,-13
/*  f140e7c:	afb902d0 */ 	sw	$t9,0x2d0($sp)
/*  f140e80:	44816000 */ 	mtc1	$at,$f12
/*  f140e84:	440f5000 */ 	mfc1	$t7,$f10
/*  f140e88:	3c0143b4 */ 	lui	$at,0x43b4
/*  f140e8c:	44818000 */ 	mtc1	$at,$f16
/*  f140e90:	afaf02d4 */ 	sw	$t7,0x2d4($sp)
/*  f140e94:	8c8e0480 */ 	lw	$t6,0x480($a0)
/*  f140e98:	3c06f600 */ 	lui	$a2,0xf600
/*  f140e9c:	02a01825 */ 	or	$v1,$s5,$zero
/*  f140ea0:	c5c0001c */ 	lwc1	$f0,0x1c($t6)
/*  f140ea4:	460e0102 */ 	mul.s	$f4,$f0,$f14
/*  f140ea8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140eac:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f140eb0:	46102203 */ 	div.s	$f8,$f4,$f16
/*  f140eb4:	46105103 */ 	div.s	$f4,$f10,$f16
/*  f140eb8:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f140ebc:	44023000 */ 	mfc1	$v0,$f6
/*  f140ec0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140ec4:	305300ff */ 	andi	$s3,$v0,0xff
/*  f140ec8:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f140ecc:	44194000 */ 	mfc1	$t9,$f8
/*  f140ed0:	04410005 */ 	bgez	$v0,.NB0f140ee8
/*  f140ed4:	afb902c8 */ 	sw	$t9,0x2c8($sp)
/*  f140ed8:	00029823 */ 	negu	$s3,$v0
/*  f140edc:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f140ee0:	10000001 */ 	beqz	$zero,.NB0f140ee8
/*  f140ee4:	01c09825 */ 	or	$s3,$t6,$zero
.NB0f140ee8:
/*  f140ee8:	0013c883 */ 	sra	$t9,$s3,0x2
/*  f140eec:	332e00ff */ 	andi	$t6,$t9,0xff
/*  f140ef0:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f140ef4:	0013c600 */ 	sll	$t8,$s3,0x18
/*  f140ef8:	030fc825 */ 	or	$t9,$t8,$t7
/*  f140efc:	372e00ff */ 	ori	$t6,$t9,0xff
/*  f140f00:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f140f04:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f140f08:	8fb802d4 */ 	lw	$t8,0x2d4($sp)
/*  f140f0c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140f10:	02a02025 */ 	or	$a0,$s5,$zero
/*  f140f14:	02987821 */ 	addu	$t7,$s4,$t8
/*  f140f18:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f140f1c:	8faf02d0 */ 	lw	$t7,0x2d0($sp)
/*  f140f20:	00197380 */ 	sll	$t6,$t9,0xe
/*  f140f24:	01c6c025 */ 	or	$t8,$t6,$a2
/*  f140f28:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f140f2c:	00197080 */ 	sll	$t6,$t9,0x2
/*  f140f30:	030e7825 */ 	or	$t7,$t8,$t6
/*  f140f34:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f140f38:	8fb802c8 */ 	lw	$t8,0x2c8($sp)
/*  f140f3c:	8fb902d0 */ 	lw	$t9,0x2d0($sp)
/*  f140f40:	3c013f00 */ 	lui	$at,0x3f00
/*  f140f44:	44811000 */ 	mtc1	$at,$f2
/*  f140f48:	03387023 */ 	subu	$t6,$t9,$t8
/*  f140f4c:	8fb802d4 */ 	lw	$t8,0x2d4($sp)
/*  f140f50:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f140f54:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f140f58:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f140f5c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f140f60:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f140f64:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f140f68:	8fa50294 */ 	lw	$a1,0x294($sp)
/*  f140f6c:	8faf02d4 */ 	lw	$t7,0x2d4($sp)
/*  f140f70:	3c013f80 */ 	lui	$at,0x3f80
/*  f140f74:	00057040 */ 	sll	$t6,$a1,0x1
/*  f140f78:	01c02825 */ 	or	$a1,$t6,$zero
/*  f140f7c:	01eec821 */ 	addu	$t9,$t7,$t6
/*  f140f80:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f140f84:	0334c021 */ 	addu	$t8,$t9,$s4
/*  f140f88:	afb802d4 */ 	sw	$t8,0x2d4($sp)
/*  f140f8c:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f140f90:	44819000 */ 	mtc1	$at,$f18
/*  f140f94:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f140f98:	c5e60020 */ 	lwc1	$f6,0x20($t7)
/*  f140f9c:	02a01825 */ 	or	$v1,$s5,$zero
/*  f140fa0:	46123000 */ 	add.s	$f0,$f6,$f18
/*  f140fa4:	460e0282 */ 	mul.s	$f10,$f0,$f14
/*  f140fa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140fac:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f140fb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140fb4:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f140fb8:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f140fbc:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f140fc0:	44024000 */ 	mfc1	$v0,$f8
/*  f140fc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f140fc8:	305300ff */ 	andi	$s3,$v0,0xff
/*  f140fcc:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f140fd0:	440e2000 */ 	mfc1	$t6,$f4
/*  f140fd4:	04410005 */ 	bgez	$v0,.NB0f140fec
/*  f140fd8:	afae02c8 */ 	sw	$t6,0x2c8($sp)
/*  f140fdc:	00029823 */ 	negu	$s3,$v0
/*  f140fe0:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f140fe4:	10000001 */ 	beqz	$zero,.NB0f140fec
/*  f140fe8:	01e09825 */ 	or	$s3,$t7,$zero
.NB0f140fec:
/*  f140fec:	00137083 */ 	sra	$t6,$s3,0x2
/*  f140ff0:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f140ff4:	000fcc00 */ 	sll	$t9,$t7,0x10
/*  f140ff8:	0013c600 */ 	sll	$t8,$s3,0x18
/*  f140ffc:	03197025 */ 	or	$t6,$t8,$t9
/*  f141000:	35cf00ff */ 	ori	$t7,$t6,0xff
/*  f141004:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f141008:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f14100c:	8fb802d4 */ 	lw	$t8,0x2d4($sp)
/*  f141010:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f141014:	02a02025 */ 	or	$a0,$s5,$zero
/*  f141018:	0298c821 */ 	addu	$t9,$s4,$t8
/*  f14101c:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f141020:	8fb902d0 */ 	lw	$t9,0x2d0($sp)
/*  f141024:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f141028:	01e6c025 */ 	or	$t8,$t7,$a2
/*  f14102c:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f141030:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f141034:	030fc825 */ 	or	$t9,$t8,$t7
/*  f141038:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f14103c:	8fb802c8 */ 	lw	$t8,0x2c8($sp)
/*  f141040:	8fae02d0 */ 	lw	$t6,0x2d0($sp)
/*  f141044:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f141048:	02a01825 */ 	or	$v1,$s5,$zero
/*  f14104c:	01d87823 */ 	subu	$t7,$t6,$t8
/*  f141050:	8fb802d4 */ 	lw	$t8,0x2d4($sp)
/*  f141054:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f141058:	00197080 */ 	sll	$t6,$t9,0x2
/*  f14105c:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f141060:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f141064:	032ec025 */ 	or	$t8,$t9,$t6
/*  f141068:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f14106c:	8faf02d4 */ 	lw	$t7,0x2d4($sp)
/*  f141070:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f141074:	01e5c821 */ 	addu	$t9,$t7,$a1
/*  f141078:	03347021 */ 	addu	$t6,$t9,$s4
/*  f14107c:	afae02d4 */ 	sw	$t6,0x2d4($sp)
/*  f141080:	8f0f0480 */ 	lw	$t7,0x480($t8)
/*  f141084:	c5e80024 */ 	lwc1	$f8,0x24($t7)
/*  f141088:	46124000 */ 	add.s	$f0,$f8,$f18
/*  f14108c:	460e0182 */ 	mul.s	$f6,$f0,$f14
/*  f141090:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141094:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f141098:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14109c:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f1410a0:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f1410a4:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f1410a8:	44022000 */ 	mfc1	$v0,$f4
/*  f1410ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1410b0:	305300ff */ 	andi	$s3,$v0,0xff
/*  f1410b4:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f1410b8:	44185000 */ 	mfc1	$t8,$f10
/*  f1410bc:	04410005 */ 	bgez	$v0,.NB0f1410d4
/*  f1410c0:	afb802c8 */ 	sw	$t8,0x2c8($sp)
/*  f1410c4:	00029823 */ 	negu	$s3,$v0
/*  f1410c8:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f1410cc:	10000001 */ 	beqz	$zero,.NB0f1410d4
/*  f1410d0:	01e09825 */ 	or	$s3,$t7,$zero
.NB0f1410d4:
/*  f1410d4:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f1410d8:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f1410dc:	000fcc00 */ 	sll	$t9,$t7,0x10
/*  f1410e0:	00137600 */ 	sll	$t6,$s3,0x18
/*  f1410e4:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f1410e8:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f1410ec:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f1410f0:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1410f4:	8fae02d4 */ 	lw	$t6,0x2d4($sp)
/*  f1410f8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1410fc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f141100:	028ec821 */ 	addu	$t9,$s4,$t6
/*  f141104:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f141108:	8fb902d0 */ 	lw	$t9,0x2d0($sp)
/*  f14110c:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f141110:	01e67025 */ 	or	$t6,$t7,$a2
/*  f141114:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f141118:	00187880 */ 	sll	$t7,$t8,0x2
/*  f14111c:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f141120:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f141124:	8fae02c8 */ 	lw	$t6,0x2c8($sp)
/*  f141128:	8fb802d0 */ 	lw	$t8,0x2d0($sp)
/*  f14112c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f141130:	02a01825 */ 	or	$v1,$s5,$zero
/*  f141134:	030e7823 */ 	subu	$t7,$t8,$t6
/*  f141138:	8fae02d4 */ 	lw	$t6,0x2d4($sp)
/*  f14113c:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f141140:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f141144:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f141148:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f14114c:	03387025 */ 	or	$t6,$t9,$t8
/*  f141150:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f141154:	8faf02d4 */ 	lw	$t7,0x2d4($sp)
/*  f141158:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f14115c:	01e5c821 */ 	addu	$t9,$t7,$a1
/*  f141160:	0334c021 */ 	addu	$t8,$t9,$s4
/*  f141164:	afb802d4 */ 	sw	$t8,0x2d4($sp)
/*  f141168:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f14116c:	c5e00028 */ 	lwc1	$f0,0x28($t7)
/*  f141170:	460e0102 */ 	mul.s	$f4,$f0,$f14
/*  f141174:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141178:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f14117c:	46102203 */ 	div.s	$f8,$f4,$f16
/*  f141180:	46105103 */ 	div.s	$f4,$f10,$f16
/*  f141184:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f141188:	44023000 */ 	mfc1	$v0,$f6
/*  f14118c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141190:	305300ff */ 	andi	$s3,$v0,0xff
/*  f141194:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f141198:	440e4000 */ 	mfc1	$t6,$f8
/*  f14119c:	04410005 */ 	bgez	$v0,.NB0f1411b4
/*  f1411a0:	afae02c8 */ 	sw	$t6,0x2c8($sp)
/*  f1411a4:	00029823 */ 	negu	$s3,$v0
/*  f1411a8:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f1411ac:	10000001 */ 	beqz	$zero,.NB0f1411b4
/*  f1411b0:	01e09825 */ 	or	$s3,$t7,$zero
.NB0f1411b4:
/*  f1411b4:	00137083 */ 	sra	$t6,$s3,0x2
/*  f1411b8:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f1411bc:	000fcc00 */ 	sll	$t9,$t7,0x10
/*  f1411c0:	0013c600 */ 	sll	$t8,$s3,0x18
/*  f1411c4:	03197025 */ 	or	$t6,$t8,$t9
/*  f1411c8:	35cf00ff */ 	ori	$t7,$t6,0xff
/*  f1411cc:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f1411d0:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1411d4:	8fb802d4 */ 	lw	$t8,0x2d4($sp)
/*  f1411d8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1411dc:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1411e0:	0298c821 */ 	addu	$t9,$s4,$t8
/*  f1411e4:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1411e8:	8fb902d0 */ 	lw	$t9,0x2d0($sp)
/*  f1411ec:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1411f0:	01e6c025 */ 	or	$t8,$t7,$a2
/*  f1411f4:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1411f8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1411fc:	030fc825 */ 	or	$t9,$t8,$t7
/*  f141200:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f141204:	8fb802c8 */ 	lw	$t8,0x2c8($sp)
/*  f141208:	8fae02d0 */ 	lw	$t6,0x2d0($sp)
/*  f14120c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f141210:	02a01825 */ 	or	$v1,$s5,$zero
/*  f141214:	01d87823 */ 	subu	$t7,$t6,$t8
/*  f141218:	8fb802d4 */ 	lw	$t8,0x2d4($sp)
/*  f14121c:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f141220:	00197080 */ 	sll	$t6,$t9,0x2
/*  f141224:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f141228:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f14122c:	032ec025 */ 	or	$t8,$t9,$t6
/*  f141230:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f141234:	8faf02d4 */ 	lw	$t7,0x2d4($sp)
/*  f141238:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f14123c:	01e5c821 */ 	addu	$t9,$t7,$a1
/*  f141240:	03347021 */ 	addu	$t6,$t9,$s4
/*  f141244:	afae02d4 */ 	sw	$t6,0x2d4($sp)
/*  f141248:	8f0f0480 */ 	lw	$t7,0x480($t8)
/*  f14124c:	c5e6002c */ 	lwc1	$f6,0x2c($t7)
/*  f141250:	46123000 */ 	add.s	$f0,$f6,$f18
/*  f141254:	460e0282 */ 	mul.s	$f10,$f0,$f14
/*  f141258:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14125c:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f141260:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141264:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f141268:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f14126c:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f141270:	44024000 */ 	mfc1	$v0,$f8
/*  f141274:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141278:	305300ff */ 	andi	$s3,$v0,0xff
/*  f14127c:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f141280:	44182000 */ 	mfc1	$t8,$f4
/*  f141284:	04410005 */ 	bgez	$v0,.NB0f14129c
/*  f141288:	afb802c8 */ 	sw	$t8,0x2c8($sp)
/*  f14128c:	00029823 */ 	negu	$s3,$v0
/*  f141290:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f141294:	10000001 */ 	beqz	$zero,.NB0f14129c
/*  f141298:	01e09825 */ 	or	$s3,$t7,$zero
.NB0f14129c:
/*  f14129c:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f1412a0:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f1412a4:	000fcc00 */ 	sll	$t9,$t7,0x10
/*  f1412a8:	00137600 */ 	sll	$t6,$s3,0x18
/*  f1412ac:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f1412b0:	370f00ff */ 	ori	$t7,$t8,0xff
/*  f1412b4:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f1412b8:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1412bc:	8fae02d4 */ 	lw	$t6,0x2d4($sp)
/*  f1412c0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1412c4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1412c8:	028ec821 */ 	addu	$t9,$s4,$t6
/*  f1412cc:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f1412d0:	8fb902d0 */ 	lw	$t9,0x2d0($sp)
/*  f1412d4:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f1412d8:	01e67025 */ 	or	$t6,$t7,$a2
/*  f1412dc:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f1412e0:	00187880 */ 	sll	$t7,$t8,0x2
/*  f1412e4:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f1412e8:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f1412ec:	8fae02c8 */ 	lw	$t6,0x2c8($sp)
/*  f1412f0:	8fb802d0 */ 	lw	$t8,0x2d0($sp)
/*  f1412f4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1412f8:	030e7823 */ 	subu	$t7,$t8,$t6
/*  f1412fc:	8fae02d4 */ 	lw	$t6,0x2d4($sp)
/*  f141300:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f141304:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f141308:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f14130c:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f141310:	03387025 */ 	or	$t6,$t9,$t8
/*  f141314:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f141318:	8faf02d4 */ 	lw	$t7,0x2d4($sp)
/*  f14131c:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f141320:	01e5c821 */ 	addu	$t9,$t7,$a1
/*  f141324:	0334c021 */ 	addu	$t8,$t9,$s4
/*  f141328:	afb802d4 */ 	sw	$t8,0x2d4($sp)
/*  f14132c:	8dcf0480 */ 	lw	$t7,0x480($t6)
/*  f141330:	c5e80030 */ 	lwc1	$f8,0x30($t7)
/*  f141334:	46124000 */ 	add.s	$f0,$f8,$f18
/*  f141338:	460e0182 */ 	mul.s	$f6,$f0,$f14
/*  f14133c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141340:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f141344:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141348:	460c0202 */ 	mul.s	$f8,$f0,$f12
/*  f14134c:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f141350:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f141354:	44022000 */ 	mfc1	$v0,$f4
/*  f141358:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14135c:	305300ff */ 	andi	$s3,$v0,0xff
/*  f141360:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f141364:	440e5000 */ 	mfc1	$t6,$f10
/*  f141368:	04410005 */ 	bgez	$v0,.NB0f141380
/*  f14136c:	afae02c8 */ 	sw	$t6,0x2c8($sp)
/*  f141370:	00029823 */ 	negu	$s3,$v0
/*  f141374:	326f00ff */ 	andi	$t7,$s3,0xff
/*  f141378:	10000001 */ 	beqz	$zero,.NB0f141380
/*  f14137c:	01e09825 */ 	or	$s3,$t7,$zero
.NB0f141380:
/*  f141380:	00137083 */ 	sra	$t6,$s3,0x2
/*  f141384:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f141388:	000fcc00 */ 	sll	$t9,$t7,0x10
/*  f14138c:	0013c600 */ 	sll	$t8,$s3,0x18
/*  f141390:	03197025 */ 	or	$t6,$t8,$t9
/*  f141394:	02a01025 */ 	or	$v0,$s5,$zero
/*  f141398:	35cf00ff */ 	ori	$t7,$t6,0xff
/*  f14139c:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f1413a0:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f1413a4:	8fb802d4 */ 	lw	$t8,0x2d4($sp)
/*  f1413a8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1413ac:	02a01825 */ 	or	$v1,$s5,$zero
/*  f1413b0:	0298c821 */ 	addu	$t9,$s4,$t8
/*  f1413b4:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1413b8:	8fb902d0 */ 	lw	$t9,0x2d0($sp)
/*  f1413bc:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f1413c0:	01e6c025 */ 	or	$t8,$t7,$a2
/*  f1413c4:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f1413c8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1413cc:	030fc825 */ 	or	$t9,$t8,$t7
/*  f1413d0:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f1413d4:	8fb802c8 */ 	lw	$t8,0x2c8($sp)
/*  f1413d8:	8fae02d0 */ 	lw	$t6,0x2d0($sp)
/*  f1413dc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1413e0:	01d87823 */ 	subu	$t7,$t6,$t8
/*  f1413e4:	8fb802d4 */ 	lw	$t8,0x2d4($sp)
/*  f1413e8:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f1413ec:	00197080 */ 	sll	$t6,$t9,0x2
/*  f1413f0:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f1413f4:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f1413f8:	032ec025 */ 	or	$t8,$t9,$t6
/*  f1413fc:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f141400:	8faf02d4 */ 	lw	$t7,0x2d4($sp)
/*  f141404:	01e5c821 */ 	addu	$t9,$t7,$a1
/*  f141408:	03347021 */ 	addu	$t6,$t9,$s4
/*  f14140c:	1000003a */ 	beqz	$zero,.NB0f1414f8
/*  f141410:	afae02d4 */ 	sw	$t6,0x2d4($sp)
.NB0f141414:
/*  f141414:	3c0140a0 */ 	lui	$at,0x40a0
/*  f141418:	44814000 */ 	mtc1	$at,$f8
/*  f14141c:	8fa60294 */ 	lw	$a2,0x294($sp)
/*  f141420:	8fa802d8 */ 	lw	$t0,0x2d8($sp)
/*  f141424:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f141428:	00067900 */ 	sll	$t7,$a2,0x4
/*  f14142c:	01e67823 */ 	subu	$t7,$t7,$a2
/*  f141430:	2508fff3 */ 	addiu	$t0,$t0,-13
/*  f141434:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f141438:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f14143c:	afa802d0 */ 	sw	$t0,0x2d0($sp)
/*  f141440:	000f3040 */ 	sll	$a2,$t7,0x1
/*  f141444:	44035000 */ 	mfc1	$v1,$f10
/*  f141448:	00002025 */ 	or	$a0,$zero,$zero
/*  f14144c:	24070008 */ 	addiu	$a3,$zero,0x8
/*  f141450:	afa302d4 */ 	sw	$v1,0x2d4($sp)
.NB0f141454:
/*  f141454:	8ed90284 */ 	lw	$t9,0x284($s6)
/*  f141458:	02a01025 */ 	or	$v0,$s5,$zero
/*  f14145c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f141460:	8f2e0490 */ 	lw	$t6,0x490($t9)
/*  f141464:	008e082a */ 	slt	$at,$a0,$t6
/*  f141468:	54200003 */ 	bnezl	$at,.NB0f141478
/*  f14146c:	30b800ff */ 	andi	$t8,$a1,0xff
/*  f141470:	24050088 */ 	addiu	$a1,$zero,0x88
/*  f141474:	30b800ff */ 	andi	$t8,$a1,0xff
.NB0f141478:
/*  f141478:	00187a00 */ 	sll	$t7,$t8,0x8
/*  f14147c:	01ebc825 */ 	or	$t9,$t7,$t3
/*  f141480:	372e00ff */ 	ori	$t6,$t9,0xff
/*  f141484:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f141488:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f14148c:	8fb802d4 */ 	lw	$t8,0x2d4($sp)
/*  f141490:	3c01f600 */ 	lui	$at,0xf600
/*  f141494:	02a01825 */ 	or	$v1,$s5,$zero
/*  f141498:	00d87821 */ 	addu	$t7,$a2,$t8
/*  f14149c:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f1414a0:	8faf02d0 */ 	lw	$t7,0x2d0($sp)
/*  f1414a4:	00197380 */ 	sll	$t6,$t9,0xe
/*  f1414a8:	01c1c025 */ 	or	$t8,$t6,$at
/*  f1414ac:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f1414b0:	00197080 */ 	sll	$t6,$t9,0x2
/*  f1414b4:	030e7825 */ 	or	$t7,$t8,$t6
/*  f1414b8:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f1414bc:	8fb902d4 */ 	lw	$t9,0x2d4($sp)
/*  f1414c0:	8faf02d0 */ 	lw	$t7,0x2d0($sp)
/*  f1414c4:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f1414c8:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f1414cc:	00187380 */ 	sll	$t6,$t8,0xe
/*  f1414d0:	25f9fffc */ 	addiu	$t9,$t7,-4
/*  f1414d4:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f1414d8:	00187880 */ 	sll	$t7,$t8,0x2
/*  f1414dc:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f1414e0:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f1414e4:	8fb802d0 */ 	lw	$t8,0x2d0($sp)
/*  f1414e8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1414ec:	270efffb */ 	addiu	$t6,$t8,-5
/*  f1414f0:	1487ffd8 */ 	bne	$a0,$a3,.NB0f141454
/*  f1414f4:	afae02d0 */ 	sw	$t6,0x2d0($sp)
.NB0f1414f8:
/*  f1414f8:	02a01025 */ 	or	$v0,$s5,$zero
/*  f1414fc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f141500:	02a01825 */ 	or	$v1,$s5,$zero
/*  f141504:	3c0fe700 */ 	lui	$t7,0xe700
/*  f141508:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f14150c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f141510:	3c19ba00 */ 	lui	$t9,0xba00
/*  f141514:	37390602 */ 	ori	$t9,$t9,0x602
/*  f141518:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f14151c:	24180040 */ 	addiu	$t8,$zero,0x40
/*  f141520:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f141524:	02a02025 */ 	or	$a0,$s5,$zero
/*  f141528:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f14152c:	3c0eba00 */ 	lui	$t6,0xba00
/*  f141530:	35ce1301 */ 	ori	$t6,$t6,0x1301
/*  f141534:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f141538:	3c0f0008 */ 	lui	$t7,0x8
/*  f14153c:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f141540:	02a02825 */ 	or	$a1,$s5,$zero
/*  f141544:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f141548:	3c19ba00 */ 	lui	$t9,0xba00
/*  f14154c:	37391001 */ 	ori	$t9,$t9,0x1001
/*  f141550:	3c180001 */ 	lui	$t8,0x1
/*  f141554:	acb80004 */ 	sw	$t8,0x4($a1)
/*  f141558:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f14155c:	8ece0298 */ 	lw	$t6,0x298($s6)
/*  f141560:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f141564:	05c1017c */ 	bgez	$t6,.NB0f141b58
/*  f141568:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14156c:	8ecf029c */ 	lw	$t7,0x29c($s6)
/*  f141570:	8fb902d8 */ 	lw	$t9,0x2d8($sp)
/*  f141574:	8fb802e8 */ 	lw	$t8,0x2e8($sp)
/*  f141578:	05e10177 */ 	bgez	$t7,.NB0f141b58
/*  f14157c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f141580:	03387023 */ 	subu	$t6,$t9,$t8
/*  f141584:	25cfff99 */ 	addiu	$t7,$t6,-103
/*  f141588:	448f2000 */ 	mtc1	$t7,$f4
/*  f14158c:	3c014188 */ 	lui	$at,0x4188
/*  f141590:	44810000 */ 	mtc1	$at,$f0
/*  f141594:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f141598:	3c013f80 */ 	lui	$at,0x3f80
/*  f14159c:	44815000 */ 	mtc1	$at,$f10
/*  f1415a0:	3c0141c8 */ 	lui	$at,0x41c8
/*  f1415a4:	8faf02e0 */ 	lw	$t7,0x2e0($sp)
/*  f1415a8:	2419000a */ 	addiu	$t9,$zero,0xa
/*  f1415ac:	46004183 */ 	div.s	$f6,$f8,$f0
/*  f1415b0:	8fb802e0 */ 	lw	$t8,0x2e0($sp)
/*  f1415b4:	460a3101 */ 	sub.s	$f4,$f6,$f10
/*  f1415b8:	c7a602a8 */ 	lwc1	$f6,0x2a8($sp)
/*  f1415bc:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f1415c0:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f1415c4:	44812000 */ 	mtc1	$at,$f4
/*  f1415c8:	44034000 */ 	mfc1	$v1,$f8
/*  f1415cc:	46045203 */ 	div.s	$f8,$f10,$f4
/*  f1415d0:	0060a025 */ 	or	$s4,$v1,$zero
/*  f1415d4:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f1415d8:	44053000 */ 	mfc1	$a1,$f6
/*  f1415dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1415e0:	28a10012 */ 	slti	$at,$a1,0x12
/*  f1415e4:	54200003 */ 	bnezl	$at,.NB0f1415f4
/*  f1415e8:	240e0011 */ 	addiu	$t6,$zero,0x11
/*  f1415ec:	24050011 */ 	addiu	$a1,$zero,0x11
/*  f1415f0:	240e0011 */ 	addiu	$t6,$zero,0x11
.NB0f1415f4:
/*  f1415f4:	240100dc */ 	addiu	$at,$zero,0xdc
/*  f1415f8:	15e10003 */ 	bne	$t7,$at,.NB0f141608
/*  f1415fc:	01c52823 */ 	subu	$a1,$t6,$a1
/*  f141600:	10000008 */ 	beqz	$zero,.NB0f141624
/*  f141604:	a3b900b7 */ 	sb	$t9,0xb7($sp)
.NB0f141608:
/*  f141608:	240100b4 */ 	addiu	$at,$zero,0xb4
/*  f14160c:	17010004 */ 	bne	$t8,$at,.NB0f141620
/*  f141610:	240efff8 */ 	addiu	$t6,$zero,-8
/*  f141614:	2474ffff */ 	addiu	$s4,$v1,-1
/*  f141618:	10000002 */ 	beqz	$zero,.NB0f141624
/*  f14161c:	a3ae00b7 */ 	sb	$t6,0xb7($sp)
.NB0f141620:
/*  f141620:	a3a000b7 */ 	sb	$zero,0xb7($sp)
.NB0f141624:
/*  f141624:	0fc347cf */ 	jal	func0f0d479c
/*  f141628:	afa500b0 */ 	sw	$a1,0xb0($sp)
/*  f14162c:	3c0fb600 */ 	lui	$t7,0xb600
/*  f141630:	24193000 */ 	addiu	$t9,$zero,0x3000
/*  f141634:	3c18b700 */ 	lui	$t8,0xb700
/*  f141638:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f14163c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f141640:	ac580008 */ 	sw	$t8,0x8($v0)
/*  f141644:	3c0ffcff */ 	lui	$t7,0xfcff
/*  f141648:	3c19fffe */ 	lui	$t9,0xfffe
/*  f14164c:	3c18ba00 */ 	lui	$t8,0xba00
/*  f141650:	3739793c */ 	ori	$t9,$t9,0x793c
/*  f141654:	35efffff */ 	ori	$t7,$t7,0xffff
/*  f141658:	37180c02 */ 	ori	$t8,$t8,0xc02
/*  f14165c:	240e0204 */ 	addiu	$t6,$zero,0x204
/*  f141660:	ac4f0010 */ 	sw	$t7,0x10($v0)
/*  f141664:	ac590014 */ 	sw	$t9,0x14($v0)
/*  f141668:	ac580018 */ 	sw	$t8,0x18($v0)
/*  f14166c:	ac4e000c */ 	sw	$t6,0xc($v0)
/*  f141670:	3c0fba00 */ 	lui	$t7,0xba00
/*  f141674:	3c180050 */ 	lui	$t8,0x50
/*  f141678:	3c19b900 */ 	lui	$t9,0xb900
/*  f14167c:	240e2000 */ 	addiu	$t6,$zero,0x2000
/*  f141680:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*  f141684:	3739031d */ 	ori	$t9,$t9,0x31d
/*  f141688:	371841c8 */ 	ori	$t8,$t8,0x41c8
/*  f14168c:	ac4e001c */ 	sw	$t6,0x1c($v0)
/*  f141690:	ac4f0020 */ 	sw	$t7,0x20($v0)
/*  f141694:	ac400024 */ 	sw	$zero,0x24($v0)
/*  f141698:	ac58002c */ 	sw	$t8,0x2c($v0)
/*  f14169c:	ac590028 */ 	sw	$t9,0x28($v0)
/*  f1416a0:	8fae02e8 */ 	lw	$t6,0x2e8($sp)
/*  f1416a4:	8fb902e0 */ 	lw	$t9,0x2e0($sp)
/*  f1416a8:	240100b4 */ 	addiu	$at,$zero,0xb4
/*  f1416ac:	25cf003a */ 	addiu	$t7,$t6,0x3a
/*  f1416b0:	24550030 */ 	addiu	$s5,$v0,0x30
/*  f1416b4:	17210003 */ 	bne	$t9,$at,.NB0f1416c4
/*  f1416b8:	afaf02d0 */ 	sw	$t7,0x2d0($sp)
/*  f1416bc:	25e80005 */ 	addiu	$t0,$t7,0x5
/*  f1416c0:	afa802d0 */ 	sw	$t0,0x2d0($sp)
.NB0f1416c4:
/*  f1416c4:	8fb802e0 */ 	lw	$t8,0x2e0($sp)
/*  f1416c8:	3c013f00 */ 	lui	$at,0x3f00
/*  f1416cc:	44814000 */ 	mtc1	$at,$f8
/*  f1416d0:	44985000 */ 	mtc1	$t8,$f10
/*  f1416d4:	8fa802d0 */ 	lw	$t0,0x2d0($sp)
/*  f1416d8:	8fb802ec */ 	lw	$t8,0x2ec($sp)
/*  f1416dc:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f1416e0:	00009025 */ 	or	$s2,$zero,$zero
/*  f1416e4:	270e0022 */ 	addiu	$t6,$t8,0x22
/*  f1416e8:	afae0078 */ 	sw	$t6,0x78($sp)
/*  f1416ec:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f1416f0:	44814000 */ 	mtc1	$at,$f8
/*  f1416f4:	c7a40070 */ 	lwc1	$f4,0x70($sp)
/*  f1416f8:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f1416fc:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f141700:	44195000 */ 	mfc1	$t9,$f10
/*  f141704:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141708:	03390019 */ 	multu	$t9,$t9
/*  f14170c:	afb90084 */ 	sw	$t9,0x84($sp)
/*  f141710:	03288823 */ 	subu	$s1,$t9,$t0
/*  f141714:	83b900b7 */ 	lb	$t9,0xb7($sp)
/*  f141718:	2631000a */ 	addiu	$s1,$s1,0xa
/*  f14171c:	e7a6006c */ 	swc1	$f6,0x6c($sp)
/*  f141720:	02398023 */ 	subu	$s0,$s1,$t9
/*  f141724:	00007812 */ 	mflo	$t7
/*  f141728:	afaf007c */ 	sw	$t7,0x7c($sp)
/*  f14172c:	8faf0294 */ 	lw	$t7,0x294($sp)
/*  f141730:	448f5000 */ 	mtc1	$t7,$f10
/*  f141734:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141738:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f14173c:	e7a40068 */ 	swc1	$f4,0x68($sp)
.NB0f141740:
/*  f141740:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f141744:	24130050 */ 	addiu	$s3,$zero,0x50
/*  f141748:	24020056 */ 	addiu	$v0,$zero,0x56
/*  f14174c:	0244082a */ 	slt	$at,$s2,$a0
/*  f141750:	10200003 */ 	beqz	$at,.NB0f141760
/*  f141754:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141758:	10000001 */ 	beqz	$zero,.NB0f141760
/*  f14175c:	24130028 */ 	addiu	$s3,$zero,0x28
.NB0f141760:
/*  f141760:	0244082a */ 	slt	$at,$s2,$a0
/*  f141764:	10200003 */ 	beqz	$at,.NB0f141774
/*  f141768:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14176c:	10000001 */ 	beqz	$zero,.NB0f141774
/*  f141770:	24020022 */ 	addiu	$v0,$zero,0x22
.NB0f141774:
/*  f141774:	02100019 */ 	multu	$s0,$s0
/*  f141778:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f14177c:	8fa30078 */ 	lw	$v1,0x78($sp)
/*  f141780:	0114c021 */ 	addu	$t8,$t0,$s4
/*  f141784:	afa80214 */ 	sw	$t0,0x214($sp)
/*  f141788:	afb8021c */ 	sw	$t8,0x21c($sp)
/*  f14178c:	a3a200c3 */ 	sb	$v0,0xc3($sp)
/*  f141790:	afa802d0 */ 	sw	$t0,0x2d0($sp)
/*  f141794:	afa30210 */ 	sw	$v1,0x210($sp)
/*  f141798:	afa30218 */ 	sw	$v1,0x218($sp)
/*  f14179c:	0000c812 */ 	mflo	$t9
/*  f1417a0:	01d97823 */ 	subu	$t7,$t6,$t9
/*  f1417a4:	448f4000 */ 	mtc1	$t7,$f8
/*  f1417a8:	afa302d4 */ 	sw	$v1,0x2d4($sp)
/*  f1417ac:	0c012e84 */ 	jal	sqrtf
/*  f1417b0:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f1417b4:	c7aa0068 */ 	lwc1	$f10,0x68($sp)
/*  f1417b8:	c7a6006c */ 	lwc1	$f6,0x6c($sp)
/*  f1417bc:	83b900b7 */ 	lb	$t9,0xb7($sp)
/*  f1417c0:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f1417c4:	02348823 */ 	subu	$s1,$s1,$s4
/*  f1417c8:	3c0140a0 */ 	lui	$at,0x40a0
/*  f1417cc:	02398023 */ 	subu	$s0,$s1,$t9
/*  f1417d0:	02100019 */ 	multu	$s0,$s0
/*  f1417d4:	44815000 */ 	mtc1	$at,$f10
/*  f1417d8:	8fa802d0 */ 	lw	$t0,0x2d0($sp)
/*  f1417dc:	46043201 */ 	sub.s	$f8,$f6,$f4
/*  f1417e0:	8faf007c */ 	lw	$t7,0x7c($sp)
/*  f1417e4:	01147021 */ 	addu	$t6,$t0,$s4
/*  f1417e8:	afae0224 */ 	sw	$t6,0x224($sp)
/*  f1417ec:	460a4181 */ 	sub.s	$f6,$f8,$f10
/*  f1417f0:	0000c012 */ 	mflo	$t8
/*  f1417f4:	4600310d */ 	trunc.w.s	$f4,$f6
/*  f1417f8:	01f87023 */ 	subu	$t6,$t7,$t8
/*  f1417fc:	448e4000 */ 	mtc1	$t6,$f8
/*  f141800:	44032000 */ 	mfc1	$v1,$f4
/*  f141804:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f141808:	afa30228 */ 	sw	$v1,0x228($sp)
/*  f14180c:	0c012e84 */ 	jal	sqrtf
/*  f141810:	afa302d4 */ 	sw	$v1,0x2d4($sp)
/*  f141814:	c7a60068 */ 	lwc1	$f6,0x68($sp)
/*  f141818:	c7aa006c */ 	lwc1	$f10,0x6c($sp)
/*  f14181c:	3c0140a0 */ 	lui	$at,0x40a0
/*  f141820:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f141824:	44813000 */ 	mtc1	$at,$f6
/*  f141828:	8fb802d0 */ 	lw	$t8,0x2d0($sp)
/*  f14182c:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f141830:	93a200c3 */ 	lbu	$v0,0xc3($sp)
/*  f141834:	afb8022c */ 	sw	$t8,0x22c($sp)
/*  f141838:	2631fffe */ 	addiu	$s1,$s1,-2
/*  f14183c:	46045201 */ 	sub.s	$f8,$f10,$f4
/*  f141840:	2610fffe */ 	addiu	$s0,$s0,-2
/*  f141844:	02a02025 */ 	or	$a0,$s5,$zero
/*  f141848:	27a50210 */ 	addiu	$a1,$sp,0x210
/*  f14184c:	46064281 */ 	sub.s	$f10,$f8,$f6
/*  f141850:	00003025 */ 	or	$a2,$zero,$zero
/*  f141854:	326700ff */ 	andi	$a3,$s3,0xff
/*  f141858:	24010001 */ 	addiu	$at,$zero,0x1
/*  f14185c:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f141860:	440f2000 */ 	mfc1	$t7,$f4
/*  f141864:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141868:	afaf02d4 */ 	sw	$t7,0x2d4($sp)
/*  f14186c:	afaf0220 */ 	sw	$t7,0x220($sp)
/*  f141870:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f141874:	9323006b */ 	lbu	$v1,0x6b($t9)
/*  f141878:	14600006 */ 	bnez	$v1,.NB0f141894
/*  f14187c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141880:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f141884:	0fc4f85a */ 	jal	bviewRenderEyespySideRect
/*  f141888:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f14188c:	10000017 */ 	beqz	$zero,.NB0f1418ec
/*  f141890:	0040a825 */ 	or	$s5,$v0,$zero
.NB0f141894:
/*  f141894:	1461000c */ 	bne	$v1,$at,.NB0f1418c8
/*  f141898:	02a02025 */ 	or	$a0,$s5,$zero
/*  f14189c:	00137880 */ 	sll	$t7,$s3,0x2
/*  f1418a0:	01f37823 */ 	subu	$t7,$t7,$s3
/*  f1418a4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1418a8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1418ac:	27a50210 */ 	addiu	$a1,$sp,0x210
/*  f1418b0:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f1418b4:	326700ff */ 	andi	$a3,$s3,0xff
/*  f1418b8:	0fc4f85a */ 	jal	bviewRenderEyespySideRect
/*  f1418bc:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f1418c0:	1000000a */ 	beqz	$zero,.NB0f1418ec
/*  f1418c4:	0040a825 */ 	or	$s5,$v0,$zero
.NB0f1418c8:
/*  f1418c8:	00133883 */ 	sra	$a3,$s3,0x2
/*  f1418cc:	30f800ff */ 	andi	$t8,$a3,0xff
/*  f1418d0:	03003825 */ 	or	$a3,$t8,$zero
/*  f1418d4:	27a50210 */ 	addiu	$a1,$sp,0x210
/*  f1418d8:	326600ff */ 	andi	$a2,$s3,0xff
/*  f1418dc:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f1418e0:	0fc4f85a */ 	jal	bviewRenderEyespySideRect
/*  f1418e4:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f1418e8:	0040a825 */ 	or	$s5,$v0,$zero
.NB0f1418ec:
/*  f1418ec:	8fa802d0 */ 	lw	$t0,0x2d0($sp)
/*  f1418f0:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1418f4:	2a410011 */ 	slti	$at,$s2,0x11
/*  f1418f8:	01144021 */ 	addu	$t0,$t0,$s4
/*  f1418fc:	1420ff90 */ 	bnez	$at,.NB0f141740
/*  f141900:	25080002 */ 	addiu	$t0,$t0,0x2
/*  f141904:	8ece0284 */ 	lw	$t6,0x284($s6)
/*  f141908:	afa802d0 */ 	sw	$t0,0x2d0($sp)
/*  f14190c:	3c014188 */ 	lui	$at,0x4188
/*  f141910:	8dd90480 */ 	lw	$t9,0x480($t6)
/*  f141914:	44813000 */ 	mtc1	$at,$f6
/*  f141918:	3c017f1b */ 	lui	$at,0x7f1b
/*  f14191c:	c7280060 */ 	lwc1	$f8,0x60($t9)
/*  f141920:	c42404bc */ 	lwc1	$f4,0x4bc($at)
/*  f141924:	24180011 */ 	addiu	$t8,$zero,0x11
/*  f141928:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f14192c:	8fa802e8 */ 	lw	$t0,0x2e8($sp)
/*  f141930:	8fae02e0 */ 	lw	$t6,0x2e0($sp)
/*  f141934:	8fb90084 */ 	lw	$t9,0x84($sp)
/*  f141938:	00009025 */ 	or	$s2,$zero,$zero
/*  f14193c:	83af00b7 */ 	lb	$t7,0xb7($sp)
/*  f141940:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f141944:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f141948:	44043000 */ 	mfc1	$a0,$f6
/*  f14194c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141950:	28810012 */ 	slti	$at,$a0,0x12
/*  f141954:	54200003 */ 	bnezl	$at,.NB0f141964
/*  f141958:	240100b4 */ 	addiu	$at,$zero,0xb4
/*  f14195c:	24040011 */ 	addiu	$a0,$zero,0x11
/*  f141960:	240100b4 */ 	addiu	$at,$zero,0xb4
.NB0f141964:
/*  f141964:	03042023 */ 	subu	$a0,$t8,$a0
/*  f141968:	15c10002 */ 	bne	$t6,$at,.NB0f141974
/*  f14196c:	2508002e */ 	addiu	$t0,$t0,0x2e
/*  f141970:	25080005 */ 	addiu	$t0,$t0,0x5
.NB0f141974:
/*  f141974:	8fb80088 */ 	lw	$t8,0x88($sp)
/*  f141978:	03288823 */ 	subu	$s1,$t9,$t0
/*  f14197c:	2631000a */ 	addiu	$s1,$s1,0xa
/*  f141980:	270effde */ 	addiu	$t6,$t8,-34
/*  f141984:	afae0078 */ 	sw	$t6,0x78($sp)
/*  f141988:	022f8023 */ 	subu	$s0,$s1,$t7
/*  f14198c:	afa400b0 */ 	sw	$a0,0xb0($sp)
.NB0f141990:
/*  f141990:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f141994:	24130050 */ 	addiu	$s3,$zero,0x50
/*  f141998:	24020056 */ 	addiu	$v0,$zero,0x56
/*  f14199c:	0244082a */ 	slt	$at,$s2,$a0
/*  f1419a0:	10200003 */ 	beqz	$at,.NB0f1419b0
/*  f1419a4:	8fa30078 */ 	lw	$v1,0x78($sp)
/*  f1419a8:	10000001 */ 	beqz	$zero,.NB0f1419b0
/*  f1419ac:	24130028 */ 	addiu	$s3,$zero,0x28
.NB0f1419b0:
/*  f1419b0:	0244082a */ 	slt	$at,$s2,$a0
/*  f1419b4:	10200003 */ 	beqz	$at,.NB0f1419c4
/*  f1419b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1419bc:	10000001 */ 	beqz	$zero,.NB0f1419c4
/*  f1419c0:	24020022 */ 	addiu	$v0,$zero,0x22
.NB0f1419c4:
/*  f1419c4:	02100019 */ 	multu	$s0,$s0
/*  f1419c8:	8faf007c */ 	lw	$t7,0x7c($sp)
/*  f1419cc:	0114c821 */ 	addu	$t9,$t0,$s4
/*  f1419d0:	afa30210 */ 	sw	$v1,0x210($sp)
/*  f1419d4:	afa80214 */ 	sw	$t0,0x214($sp)
/*  f1419d8:	afb9021c */ 	sw	$t9,0x21c($sp)
/*  f1419dc:	afa30218 */ 	sw	$v1,0x218($sp)
/*  f1419e0:	a3a200c3 */ 	sb	$v0,0xc3($sp)
/*  f1419e4:	afa302d4 */ 	sw	$v1,0x2d4($sp)
/*  f1419e8:	afa400b0 */ 	sw	$a0,0xb0($sp)
/*  f1419ec:	0000c012 */ 	mflo	$t8
/*  f1419f0:	01f87023 */ 	subu	$t6,$t7,$t8
/*  f1419f4:	448e5000 */ 	mtc1	$t6,$f10
/*  f1419f8:	afa802d0 */ 	sw	$t0,0x2d0($sp)
/*  f1419fc:	0c012e84 */ 	jal	sqrtf
/*  f141a00:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f141a04:	c7a40068 */ 	lwc1	$f4,0x68($sp)
/*  f141a08:	c7a6006c */ 	lwc1	$f6,0x6c($sp)
/*  f141a0c:	83b800b7 */ 	lb	$t8,0xb7($sp)
/*  f141a10:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f141a14:	02348823 */ 	subu	$s1,$s1,$s4
/*  f141a18:	3c0140a0 */ 	lui	$at,0x40a0
/*  f141a1c:	02388023 */ 	subu	$s0,$s1,$t8
/*  f141a20:	02100019 */ 	multu	$s0,$s0
/*  f141a24:	44812000 */ 	mtc1	$at,$f4
/*  f141a28:	8fa802d0 */ 	lw	$t0,0x2d0($sp)
/*  f141a2c:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f141a30:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f141a34:	01147821 */ 	addu	$t7,$t0,$s4
/*  f141a38:	afaf0224 */ 	sw	$t7,0x224($sp)
/*  f141a3c:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f141a40:	0000c812 */ 	mflo	$t9
/*  f141a44:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f141a48:	01d97823 */ 	subu	$t7,$t6,$t9
/*  f141a4c:	448f5000 */ 	mtc1	$t7,$f10
/*  f141a50:	44033000 */ 	mfc1	$v1,$f6
/*  f141a54:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f141a58:	afa30228 */ 	sw	$v1,0x228($sp)
/*  f141a5c:	0c012e84 */ 	jal	sqrtf
/*  f141a60:	afa302d4 */ 	sw	$v1,0x2d4($sp)
/*  f141a64:	c7a40068 */ 	lwc1	$f4,0x68($sp)
/*  f141a68:	c7a6006c */ 	lwc1	$f6,0x6c($sp)
/*  f141a6c:	3c0140a0 */ 	lui	$at,0x40a0
/*  f141a70:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f141a74:	44812000 */ 	mtc1	$at,$f4
/*  f141a78:	8fb902d0 */ 	lw	$t9,0x2d0($sp)
/*  f141a7c:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f141a80:	93a200c3 */ 	lbu	$v0,0xc3($sp)
/*  f141a84:	afb9022c */ 	sw	$t9,0x22c($sp)
/*  f141a88:	2631fffe */ 	addiu	$s1,$s1,-2
/*  f141a8c:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f141a90:	2610fffe */ 	addiu	$s0,$s0,-2
/*  f141a94:	02a02025 */ 	or	$a0,$s5,$zero
/*  f141a98:	27a50210 */ 	addiu	$a1,$sp,0x210
/*  f141a9c:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f141aa0:	00003025 */ 	or	$a2,$zero,$zero
/*  f141aa4:	326700ff */ 	andi	$a3,$s3,0xff
/*  f141aa8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f141aac:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f141ab0:	440e3000 */ 	mfc1	$t6,$f6
/*  f141ab4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141ab8:	afae02d4 */ 	sw	$t6,0x2d4($sp)
/*  f141abc:	afae0220 */ 	sw	$t6,0x220($sp)
/*  f141ac0:	8df80480 */ 	lw	$t8,0x480($t7)
/*  f141ac4:	9303006b */ 	lbu	$v1,0x6b($t8)
/*  f141ac8:	14600006 */ 	bnez	$v1,.NB0f141ae4
/*  f141acc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141ad0:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f141ad4:	0fc4f85a */ 	jal	bviewRenderEyespySideRect
/*  f141ad8:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f141adc:	10000017 */ 	beqz	$zero,.NB0f141b3c
/*  f141ae0:	0040a825 */ 	or	$s5,$v0,$zero
.NB0f141ae4:
/*  f141ae4:	1461000c */ 	bne	$v1,$at,.NB0f141b18
/*  f141ae8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f141aec:	00137080 */ 	sll	$t6,$s3,0x2
/*  f141af0:	01d37023 */ 	subu	$t6,$t6,$s3
/*  f141af4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f141af8:	02a02025 */ 	or	$a0,$s5,$zero
/*  f141afc:	27a50210 */ 	addiu	$a1,$sp,0x210
/*  f141b00:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f141b04:	326700ff */ 	andi	$a3,$s3,0xff
/*  f141b08:	0fc4f85a */ 	jal	bviewRenderEyespySideRect
/*  f141b0c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f141b10:	1000000a */ 	beqz	$zero,.NB0f141b3c
/*  f141b14:	0040a825 */ 	or	$s5,$v0,$zero
.NB0f141b18:
/*  f141b18:	00133883 */ 	sra	$a3,$s3,0x2
/*  f141b1c:	30f900ff */ 	andi	$t9,$a3,0xff
/*  f141b20:	03203825 */ 	or	$a3,$t9,$zero
/*  f141b24:	27a50210 */ 	addiu	$a1,$sp,0x210
/*  f141b28:	326600ff */ 	andi	$a2,$s3,0xff
/*  f141b2c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f141b30:	0fc4f85a */ 	jal	bviewRenderEyespySideRect
/*  f141b34:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f141b38:	0040a825 */ 	or	$s5,$v0,$zero
.NB0f141b3c:
/*  f141b3c:	8fa802d0 */ 	lw	$t0,0x2d0($sp)
/*  f141b40:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f141b44:	24010011 */ 	addiu	$at,$zero,0x11
/*  f141b48:	01144021 */ 	addu	$t0,$t0,$s4
/*  f141b4c:	1641ff90 */ 	bne	$s2,$at,.NB0f141990
/*  f141b50:	25080002 */ 	addiu	$t0,$t0,0x2
/*  f141b54:	afa802d0 */ 	sw	$t0,0x2d0($sp)
.NB0f141b58:
/*  f141b58:	0fc34852 */ 	jal	func0f0d49c8
/*  f141b5c:	02a02025 */ 	or	$a0,$s5,$zero
.NB0f141b60:
/*  f141b60:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f141b64:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f141b68:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f141b6c:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f141b70:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f141b74:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f141b78:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f141b7c:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f141b80:	03e00008 */ 	jr	$ra
/*  f141b84:	27bd03f0 */ 	addiu	$sp,$sp,0x3f0
);
#endif

/**
 * Renders the eyespy user interface, excluding the fisheye lens. The lens is
 * drawn first by another function, then this one is called to draw the outer
 * information. Care must be taken not to draw over the top of the fisheye lens.
 *
 * Note that the dimensions of the view can differ based on hi-res on/off, as
 * well as using coop mode in both the vertical and horizontal screen splits.
 * Some elements are omitted if a vertical split is being used, and to handle
 * hi-res a scale variable is used to multiply X values and widths where needed.
 *
 * @bug: Many of the X values and widths are not multiplied by the scale which
 * causes them to display incorrectly when using hi-res:
 * - Some of the horizontal lines don't touch the lens circle.
 * - The vertical lines are thinner and closer to the screen edges than intended.
 * - The speed and height bars are stretched.
 * - The device name and model are closer to the screen edge than intended.
 */
// Mismatch:
// 4420: writes to x2 and y2 are misordered
// Other mismatches are mostly regalloc and swapped instructions which will likely
// resolve themselves once the above is fixed.
//Gfx *bviewRenderEyespyDecorations(Gfx *gdl)
//{
//	char text[256]; // 308
//	s32 viewleft = viGetViewLeft(); // 304
//	s32 viewtop = viGetViewTop(); // 300
//	s32 viewwidth = viGetViewWidth(); // s1
//	s32 viewheight = viGetViewHeight(); // 2f8
//	s32 viewright = viewleft + viewwidth - 1;
//	s32 viewbottom = viewtop + viewheight - 1; // 2f0
//	s32 x; // 2ec
//	s32 y; // 2e8
//	s32 textwidth; // 2e4
//	s32 textheight; // 2e0
//	s32 x2; // 2dc
//	s32 y2; // 2d8
//	struct chrdata *chr;
//	s32 savedy;
//	s32 movex;
//	s32 movey;
//	s32 movez;
//	f32 movedist; // 2c0
//	f32 sqmovedist = 0.0f; // 2bc
//	u32 colourtextbright;
//	u32 colourtextdull; // 2b4
//	u32 colourglow; // 2b0
//	s32 scale = viewwidth > 320 ? 2 : 1; // 2ac
//	bool vsplit = false; // 2a8
//
//	// 3914
//	if (g_Vars.currentplayer->eyespy == NULL
//			|| g_Vars.currentplayer->eyespy->prop == NULL
//			|| g_Vars.currentplayer->eyespy->prop->chr == NULL) {
//		return gdl;
//	}
//
//	chr = g_Vars.currentplayer->eyespy->prop->chr;
//
//	// 393c
//	if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL && PLAYERCOUNT() >= 2) {
//		vsplit = true;
//	}
//
//	// 39cc
//	movex = chr->prop->pos.x - chr->prevpos.x;
//	movey = chr->prop->pos.y - chr->prevpos.y;
//	movez = chr->prop->pos.z - chr->prevpos.z;
//
//	// 3a1c
//	if (movex != 0.0f || movey != 0.0f || movez != 0.0f) {
//		sqmovedist = movex * movex + movey * movey + movez * movez;
//	}
//
//	// 3aa0
//	if (sqmovedist > 0.001f) {
//		movedist = sqrtf(sqmovedist);
//	} else {
//		movedist = 0.0f;
//	}
//
//	// 3abc
//	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//		gdl = gfxSetPrimColour(gdl, 0x00ff0028);
//	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//		gdl = gfxSetPrimColour(gdl, 0x2244ffa0);
//	} else {
//		gdl = gfxSetPrimColour(gdl, 0xff3300a0);
//	}
//
//	// 3b1c
//	if (!vsplit) {
//		// Render borders/lines in background
//		gDPFillRectangle(gdl++, viewleft + 25, viewtop + 55, viewleft + 26, viewbottom - 24);
//		gDPFillRectangle(gdl++, viewleft + 31, viewtop + 55, viewleft + 32, viewbottom - 42);
//		gDPFillRectangle(gdl++, viewleft + 25, viewbottom - 25, viewleft + 25 + viewwidth / 5.0f + 1, viewbottom - 24);
//		gDPFillRectangle(gdl++, viewleft + 31, viewbottom - 43, viewleft + 25 + viewwidth / 7.0f + 1, viewbottom - 42);
//		gDPFillRectangle(gdl++, viewright - 25, viewtop + 25, viewright - 24, viewbottom - 54);
//		gDPFillRectangle(gdl++, viewright - 31, viewtop + 43, viewright - 30, viewbottom - 54);
//		gDPFillRectangle(gdl++, viewright - 25 - viewwidth / 5.0f, viewtop + 25, viewright - 24, viewtop + 26);
//		gDPFillRectangle(gdl++, viewright - 25 - viewwidth / 7.0f, viewtop + 43, viewright - 30, viewtop + 44);
//		gDPFillRectangle(gdl++, viewleft, viewtop + 55, viewleft + viewwidth / 5.0f + 1, viewtop + 56);
//		gDPFillRectangle(gdl++, viewright - viewwidth / 5.0f, viewbottom - 55, viewright + 1, viewbottom - 54);
//	}
//
//	// 4164
//	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//		// Render crosshair
//		s32 x = viewleft + (viewwidth >> 1);
//		s32 y = viewtop + (viewheight >> 1);
//
//		gDPFillRectangle(gdl++, x + 2, y + 0, x + 7, y + 1);
//		gDPFillRectangle(gdl++, x + 2, y + 0, x + 5, y + 1);
//		gDPFillRectangle(gdl++, x - 6, y + 0, x - 1, y + 1);
//		gDPFillRectangle(gdl++, x - 4, y + 0, x - 1, y + 1);
//		gDPFillRectangle(gdl++, x + 0, y + 2, x + 1, y + 7);
//		gDPFillRectangle(gdl++, x + 0, y + 2, x + 1, y + 5);
//		gDPFillRectangle(gdl++, x + 0, y - 6, x + 1, y - 1);
//		gDPFillRectangle(gdl++, x + 0, y - 4, x + 1, y - 1);
//	}
//
//	// 4318
//	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//		colourtextbright = 0x00ff00a0;
//		colourtextdull = 0x005000ff;
//		colourglow = 0x000f00ff;
//	} else /*4348*/ if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//		colourtextbright = 0x2244ffff;
//		colourtextdull = 0x2244ffff;
//		colourglow = 0x00000fff;
//	} else {
//		// 4368
//		colourtextbright = 0xff3300ff;
//		colourtextdull = 0xff3300ff;
//		colourglow = 0x0f0000ff;
//	}
//
//	// "S/MPS"
//	// 437c
//	sprintf(text, "%s %s%5.2f", langGet(L_MISC_073), "", movedist * 0.6f);
//	savedy = viewtop + 14;
//	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
//	x = viewleft + 25 * scale;
//	y = savedy;
//	x2 = x + textwidth;
//	y2 = y + textheight;
//	gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
//			colourtextbright, colourglow, viGetWidth(), viGetHeight(), 0, 0);
//
//	// "H/M"
//	// 44b4
//	sprintf(text, "%s %s%4.2f", langGet(L_MISC_074), "", g_Vars.currentplayer->eyespy->height * 0.01f);
//	savedy += 9;
//	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
//	x = viewleft + 25 * scale;
//	y = savedy;
//	x2 = x + textwidth;
//	y2 = y + textheight;
//	gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
//			colourtextbright, colourglow, viGetWidth(), viGetHeight(), 0, 0);
//
//	// "Y/D"
//	// 45c8
//	sprintf(text, "%s %d", langGet(L_MISC_075), (s32)g_Vars.currentplayer->eyespy->theta);
//	savedy += 9;
//	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
//	y = savedy;
//	x = viewleft + 25 * scale;
//	x2 = x + textwidth;
//	y2 = y + textheight;
//	gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
//			colourtextbright, colourglow, viGetWidth(), viGetHeight(), 0, 0);
//
//	// "P/D"
//	// 46cc
//	sprintf(text, "%s %d", langGet(L_MISC_076), (s32)g_Vars.currentplayer->eyespy->verta);
//	savedy += 9;
//	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
//	y = savedy;
//	x = viewleft + 25 * scale;
//	x2 = x + textwidth;
//	y2 = y + textheight;
//	gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
//			colourtextbright, colourglow, viGetWidth(), viGetHeight(), 0, 0);
//
//	// "CI 2023"
//	// 47d0
//	sprintf(text, "%s", langGet(L_MISC_077));
//	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
//
//	x = (vsplit ? -3 : 0) + viewleft + 25 * scale + 5;
//	y = (vsplit ? 18 : 0) + viewbottom - 41;
//	x2 = x + textwidth;
//	y2 = y + textheight;
//	gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
//			colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
//
//	// 48f8
//	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//		sprintf(text, "%s", langGet(L_MISC_078)); // "YKK: 95935"
//	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//		sprintf(text, "%s", langGet(L_MISC_208)); // "JM: 201172"
//	} else {
//		sprintf(text, "%s", langGet(L_MISC_217)); // "BNC: 15877"
//	}
//
//	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
//
//	// 49a8
//	x = (vsplit ? -3 : 0) + viewleft + 25 * scale + 5;
//	y = (vsplit ? 20 : 0) + viewbottom - 34;
//	x2 = x + textwidth;
//	y2 = y + textheight;
//	gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
//			colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
//
//	// 4a8c
//	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//		// "CAMSPY"
//		sprintf(text, "   %s", langGet(L_MISC_079));
//		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
//
//		x = viewright - scale * 53 - 25;
//		y = (vsplit ? -13 : 0) + viewtop + 27;
//		x2 = x + textwidth;
//		y2 = y + textheight;
//		gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//		gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
//				colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
//	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//		// "DRUGSPY"
//		// 4be4
//		sprintf(text, "   %s", langGet(L_MISC_468));
//		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
//
//		x = viewright - scale * 53 - 25;
//		y = (vsplit ? -13 : 0) + viewtop + 27;
//		x2 = x + textwidth;
//		y2 = y + textheight;
//		gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//		gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
//				colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
//	} else {
//		// "BOMBSPY"
//		// 4d18
//		sprintf(text, "   %s", langGet(L_MISC_469));
//		textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
//
//		x = viewright - scale * 59 - 25;
//		y = (vsplit ? -13 : 0) + viewtop + 27;
//		x2 = x + textwidth;
//		y2 = y + textheight;
//		gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//		gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
//				colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
//	}
//
//	// 4e3c
//	// Model number
//	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//		sprintf(text, "%s", langGet(L_MISC_080)); // "MODEL 1.2"
//	} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//		sprintf(text, "%s", langGet(L_MISC_207)); // "MODEL 1.4"
//	} else {
//		sprintf(text, "%s", langGet(L_MISC_216)); // "MODEL 1.3"
//	}
//
//	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
//	x = (vsplit ? 3 : 0) + viewright - scale * 46 - 25;
//	y = (vsplit ? -11 : 0) + viewtop + 34;
//	x2 = x + textwidth;
//	y2 = y + textheight;
//	gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
//			colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
//
//	// 4fe4
//	// Gyrostat/dartammo text
//	if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY
//			|| g_Vars.currentplayer->eyespy->mode == EYESPYMODE_BOMBSPY) {
//		sprintf(text, "%s", langGet(L_MISC_081)); // "GYROSTAT"
//	} else {
//		sprintf(text, "%s", langGet(L_MISC_206)); // "DARTAMMO"
//	}
//
//	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
//	x = (vsplit ? -35 : 0) + (viewright - viewwidth / 5.0f - 3 - (scale * 5 - 5));
//	y = (vsplit ? -2 : 0) + viewbottom - 12;
//	x2 = x + textwidth;
//	y2 = y + textheight;
//	gdl = func0f153858(gdl, &x, &y, &x2, &y2);
//	gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs,
//			colourtextdull, colourglow, viGetWidth(), viGetHeight(), 0, 0);
//
//	gdl = func0f153838(gdl);
//
//	// 5190
//	{
//		s8 contpadnum = optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex);
//		u16 buttonsdown = joyGetButtons(contpadnum, 0xffff);
//		u16 buttonsthisframe = joyGetButtonsPressedThisFrame(contpadnum, 0xffff);
//		s8 cstickx = joyGetStickX(contpadnum); // 251
//		s8 csticky = joyGetStickY(contpadnum);
//		s32 xpos;
//		s32 tmpval;
//		u8 brightness;
//		u8 brightness2;
//		s32 points[8]; // 224
//		s32 r;
//		s32 g;
//		s32 b;
//
//		// 5200
//		gDPPipeSync(gdl++);
//		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
//		gDPSetColorDither(gdl++, G_CD_DISABLE);
//		gDPSetTexturePersp(gdl++, G_TP_NONE);
//		gDPSetAlphaCompare(gdl++, G_AC_NONE);
//		gDPSetTextureLOD(gdl++, G_TL_TILE);
//		gDPSetTextureFilter(gdl++, G_TF_BILERP);
//		gDPSetTextureConvert(gdl++, G_TC_FILT);
//		gDPSetTextureLUT(gdl++, G_TT_NONE);
//		gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
//		gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
//
//		// 5328
//		if (!vsplit) {
//			// 5330
//			xpos = (scale == 2 ? -76 : -85);
//
//			// Up
//			// 5364
//			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//				brightness = 20;
//
//				if (buttonsdown & (U_JPAD | U_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (U_JPAD | U_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//				// 53b4
//				brightness = 127;
//
//				if (buttonsdown & (U_JPAD | U_CBUTTONS)) {
//					brightness += 63;
//				}
//
//				if (buttonsthisframe & (U_JPAD | U_CBUTTONS)) {
//					brightness += 63;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
//			} else {
//				brightness = 20;
//
//				if (buttonsdown & (U_JPAD | U_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (U_JPAD | U_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//			}
//
//			// 5464
//			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
//			xpos += 10;
//
//			// Down
//
//			// 5504
//			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//				brightness = 20;
//
//				if (buttonsdown & (D_JPAD | D_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (D_JPAD | D_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//				// 555c
//				brightness = 127;
//
//				if (buttonsdown & (D_JPAD | D_CBUTTONS)) {
//					brightness += 63;
//				}
//
//				if (buttonsthisframe & (D_JPAD | D_CBUTTONS)) {
//					brightness += 63;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
//			} else {
//				// 55ac
//				brightness = 20;
//
//				if (buttonsdown & (D_JPAD | D_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (D_JPAD | D_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//			}
//
//			// 55ec
//			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
//			xpos += 10;
//
//			// Left
//
//			// 5648
//			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//				brightness = 20;
//
//				if (buttonsdown & (L_JPAD | L_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (L_JPAD | L_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//				// 56a0
//				brightness = 127;
//
//				if (buttonsdown & (L_JPAD | L_CBUTTONS)) {
//					brightness += 63;
//				}
//
//				if (buttonsthisframe & (L_JPAD | L_CBUTTONS)) {
//					brightness += 63;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
//			} else {
//				// 56e8
//				brightness = 20;
//
//				if (buttonsdown & (L_JPAD | L_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (L_JPAD | L_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//			}
//
//			// 5730
//			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
//			xpos += 10;
//
//			// Right
//
//			// 5790
//			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//				brightness = 20;
//
//				if (buttonsdown & (R_JPAD | R_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (R_JPAD | R_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//				// 57e8
//				brightness = 127;
//
//				if (buttonsdown & (R_JPAD | R_CBUTTONS)) {
//					brightness += 63;
//				}
//
//				if (buttonsthisframe & (R_JPAD | R_CBUTTONS)) {
//					brightness += 63;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
//			} else {
//				// 5838
//				brightness = 20;
//
//				if (buttonsdown & (R_JPAD | R_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (R_JPAD | R_CBUTTONS)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//			}
//
//			// 5878
//			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
//			xpos += 10;
//
//			// Shoulder buttons
//
//			// 58d8
//			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//				brightness = 20;
//
//				if (buttonsdown & (L_TRIG | R_TRIG)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (L_TRIG | R_TRIG)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//				// 5930
//				brightness = 127;
//
//				if (buttonsdown & (L_TRIG | R_TRIG)) {
//					brightness += 63;
//				}
//
//				if (buttonsthisframe & (L_TRIG | R_TRIG)) {
//					brightness += 63;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
//			} else {
//				// 5978
//				brightness = 20;
//
//				if (buttonsdown & (L_TRIG | R_TRIG)) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & (L_TRIG | R_TRIG)) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//			}
//
//			// 59c0
//			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
//			xpos += 10;
//
//			// Z button
//
//			// 5a10
//			if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//				brightness = 20;
//
//				if (buttonsdown & Z_TRIG) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & Z_TRIG) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//			} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//				// 5a68
//				brightness = 127;
//
//				if (buttonsdown & Z_TRIG) {
//					brightness += 63;
//				}
//
//				if (buttonsthisframe & Z_TRIG) {
//					brightness += 63;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness, 0xff);
//			} else {
//				// 5ab8
//				brightness = 20;
//
//				if (buttonsdown & Z_TRIG) {
//					brightness += 20;
//				}
//
//				if (buttonsthisframe & Z_TRIG) {
//					brightness += 20;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//			}
//
//			// 5af8
//			gDPFillRectangle(gdl++, xpos * scale + viewright, viewtop + 10, (xpos + 8) * scale + viewright, viewtop + 18);
//		}
//
//		// 5b28
//		xpos = (scale == 2 ? -48 : -55);
//
//		tmpval = cstickx * 96.0f / 80.0f;
//		brightness = tmpval < 0 ? -tmpval : tmpval;
//
//		// 5bb0
//		if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//			gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//		} else /*5bcc*/ if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//			r = brightness / 96.0f * 16.0f;
//			g = brightness / 96.0f * 32.0f;
//			b = brightness * 2.5f;
//			gDPSetPrimColor(gdl++, 0, 0, r, g, b, 0xff);
//		} else {
//			// 5c68
//			gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//		}
//
//		// 5c8c
//		if (!vsplit) {
//			tmpval = cstickx * 28.0f / 80.0f;
//
//			if (cstickx > 0) {
//				gDPFillRectangle(gdl++,
//						xpos * scale + viewright,
//						viewtop + 19,
//						(tmpval + xpos) * scale + viewright,
//						viewtop + 21);
//			} else {
//				// 5d40
//				gDPFillRectangle(gdl++,
//						(tmpval + xpos) * scale + viewright,
//						viewtop + 19,
//						xpos * scale + viewright,
//						viewtop + 21);
//			}
//		}
//
//		// 5dd4
//		tmpval = csticky * 96.0f / 80.0f;
//		brightness = tmpval < 0 ? -tmpval : tmpval;
//
//		// 5e38
//		if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//			gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//		} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//			r = brightness / 96.0f * 16.0f;
//			g = brightness / 96.0f * 32.0f;
//			b = brightness * 2.5f;
//			gDPSetPrimColor(gdl++, 0, 0, r, g, b, 0xff);
//		} else {
//			gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//		}
//
//		// 5f10
//		if (!vsplit) {
//			tmpval = csticky * 28.0f / 80.0f;
//
//			if (csticky > 0) {
//				gDPFillRectangle(gdl++,
//						xpos * scale + viewright,
//						viewtop + 22,
//						(tmpval + xpos) * scale + viewright,
//						viewtop + 24);
//			} else {
//				gDPFillRectangle(gdl++,
//						(tmpval + xpos) * scale + viewright,
//						viewtop + 22,
//						xpos * scale + viewright,
//						viewtop + 24);
//			}
//		}
//
//		// 6020
//		if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//			if (!vsplit) {
//				// Camspy gyrobar 1
//				x = viewright - viewwidth / 5.0f;
//				y = viewbottom - 13;
//
//				tmpval = g_Vars.currentplayer->eyespy->theta * 96.0f / 360.0f;
//				textheight = g_Vars.currentplayer->eyespy->theta * 35.0f / 360.0f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Camspy gyrobar 2
//				x += scale * 2 + scale * 5;
//
//				tmpval = (g_Vars.currentplayer->eyespy->costheta + 1.0f) * 96.0f * 0.5f;
//				textheight = (g_Vars.currentplayer->eyespy->costheta + 1.0f) * 35.0f * 0.5f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Camspy gyrobar 3
//				x += scale * 2 + scale * 5;
//
//				tmpval = (g_Vars.currentplayer->eyespy->sintheta + 1.0f) * 96.0f * 0.5f;
//				textheight = (g_Vars.currentplayer->eyespy->sintheta + 1.0f) * 35.0f * 0.5f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Camspy gyrobar 4
//				x += scale * 2 + scale * 5;
//
//				tmpval = g_Vars.currentplayer->eyespy->verta * 96.0f / 360.0f;
//				textheight = g_Vars.currentplayer->eyespy->verta * 35.0f / 360.0f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Camspy gyrobar 5
//				x += scale * 2 + scale * 5;
//
//				tmpval = (g_Vars.currentplayer->eyespy->cosverta + 1.0f) * 96.0f * 0.5f;
//				textheight = (g_Vars.currentplayer->eyespy->cosverta + 1.0f) * 35.0f * 0.5f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Camspy gyrobar 6
//				x += scale * 2 + scale * 5;
//
//				tmpval = (g_Vars.currentplayer->eyespy->sinverta + 1.0f) * 96.0f * 0.5f;
//				textheight = (g_Vars.currentplayer->eyespy->sinverta + 1.0f) * 35.0f * 0.5f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, 0, brightness, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				x += scale * 2 + scale * 5;
//			}
//		} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_BOMBSPY) {
//			// 65ac
//			if (!vsplit) {
//				// Bombspy gyrobar 1
//				x = viewright - viewwidth / 5.0f;
//				y = viewbottom - 13;
//
//				tmpval = g_Vars.currentplayer->eyespy->theta * 96.0f / 360.0f;
//				textheight = g_Vars.currentplayer->eyespy->theta * 35.0f / 360.0f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Bombspy gyrobar 2
//				x += scale * 2 + scale * 5;
//
//				tmpval = (g_Vars.currentplayer->eyespy->costheta + 1.0f) * 96.0f * 0.5f;
//				textheight = (g_Vars.currentplayer->eyespy->costheta + 1.0f) * 35.0f * 0.5f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Bombspy gyrobar 3
//				x += scale * 2 + scale * 5;
//
//				tmpval = (g_Vars.currentplayer->eyespy->sintheta + 1.0f) * 96.0f * 0.5f;
//				textheight = (g_Vars.currentplayer->eyespy->sintheta + 1.0f) * 35.0f * 0.5f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Bombspy gyrobar 4
//				x += scale * 2 + scale * 5;
//
//				tmpval = g_Vars.currentplayer->eyespy->verta * 96.0f / 360.0f;
//				textheight = g_Vars.currentplayer->eyespy->verta * 35.0f / 360.0f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Bombspy gyrobar 5
//				x += scale * 2 + scale * 5;
//
//				tmpval = (g_Vars.currentplayer->eyespy->cosverta + 1.0f) * 96.0f * 0.5f;
//				textheight = (g_Vars.currentplayer->eyespy->cosverta + 1.0f) * 35.0f * 0.5f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				// Bombspy gyrobar 6
//				x += scale * 2 + scale * 5;
//
//				tmpval = (g_Vars.currentplayer->eyespy->sinverta + 1.0f) * 96.0f * 0.5f;
//				textheight = (g_Vars.currentplayer->eyespy->sinverta + 1.0f) * 35.0f * 0.5f;
//				brightness = tmpval < 0 ? -tmpval : tmpval;
//
//				gDPSetPrimColor(gdl++, 0, 0, brightness, brightness >> 2, 0, 0xff);
//				gDPFillRectangle(gdl++, x, y - textheight, x + scale * 5, y);
//
//				x += scale * 2 + scale * 5;
//			}
//		} else {
//			// 6b68
//			// Drugspy ammo
//			s32 i;
//			s32 width;
//			x = viewright - viewwidth / 5.0f + 5;
//			y = viewbottom - 13;
//
//			brightness2 = 0xff;
//			width = scale * 30;
//
//			if (vsplit) {
//				x -= 12;
//				y -= 3;
//				width = 15;
//			}
//
//			for (i = 0; i < 8; i++) {
//				if (i >= g_Vars.currentplayer->eyespydarts) {
//					brightness2 = 0x88;
//				}
//
//				gDPSetPrimColor(gdl++, 0, 0, 0x10, 0x20, brightness2, 0xff);
//				gDPFillRectangle(gdl++, x, y - 4, x + width, y);
//
//				y -= 5;
//			}
//		}
//
//		// 6c68
//		gDPPipeSync(gdl++);
//		gDPSetColorDither(gdl++, G_CD_BAYER);
//		gDPSetTexturePersp(gdl++, G_TP_PERSP);
//		gDPSetTextureLOD(gdl++, G_TL_LOD);
//
//		// 6cd4
//		if (g_Vars.coopplayernum < 0 && g_Vars.antiplayernum < 0) {
//			s32 barheight = (viewbottom - viewtop - 103) / 17.0f - 1;
//			s32 centrey;
//			s32 sqcentrey;
//			s32 ypos;
//			u8 alpha; // d3
//			u32 stack;
//			u32 stack2;
//			s8 yoffset; // c7
//			s32 value = 17.0f * movedist / 25.0f; // c0
//			s32 i;
//
//			if (value > 17) {
//				value = 17;
//			}
//
//			value = 17 - value;
//
//			if (viewheight == 220) {
//				yoffset = 10;
//			} else if (viewheight == 180) {
//				barheight--;
//				yoffset = -8;
//			} else {
//				yoffset = 0;
//			}
//
//			// 6d90
//			gdl = func0f0d479c(gdl);
//
//			gSPClearGeometryMode(gdl++, G_CULL_BOTH);
//			gSPSetGeometryMode(gdl++, G_SHADE | G_SHADING_SMOOTH);
//			gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
//			gDPSetTextureFilter(gdl++, G_TF_BILERP);
//			gDPSetCycleType(gdl++, G_CYC_1CYCLE);
//			gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
//
//			// Speed bars (left side)
//			y = viewtop + 58;
//
//			if (viewheight == 180) {
//				y += 5;
//			}
//
//			centrey = viewheight * .5f;
//			ypos = centrey - y + 10;
//			sqcentrey = centrey * centrey;
//
//			for (i = 0; i < 17; i++) {
//				// 6eac
//				brightness = i < value ? 0x28 : 0x50;
//				alpha = i < value ? 0x22 : 0x56;
//
//				points[0] = x = viewleft + 34;
//				points[1] = y;
//				points[2] = x = viewleft + 34;
//				points[3] = y + barheight;
//
//				// 6f18
//				points[6] = x = viewwidth * .5f - sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * scale - 5.0f;
//				points[5] = y + barheight;
//
//				ypos -= barheight;
//
//				// 6f78
//				points[4] = x = viewwidth * .5f - sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * scale - 5.0f;
//				points[7] = y;
//
//				ypos -= 2;
//
//				// 6fec
//				if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//					gdl = bviewRenderEyespySideRect(gdl, points, 0, brightness, 0, alpha);
//				} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//					// 7014
//					gdl = bviewRenderEyespySideRect(gdl, points, 0x10, brightness, brightness * 3, alpha);
//				} else {
//					// 7080
//					gdl = bviewRenderEyespySideRect(gdl, points, brightness, brightness >> 2, 0, alpha);
//				}
//
//				y += barheight;
//				y += 2;
//			}
//
//			// Height bars (right side)
//			value = g_Vars.currentplayer->eyespy->height * 17.0f * 0.00625f;
//
//			if (value > 17) {
//				value = 17;
//			}
//
//			value = 17 - value;
//
//			y = viewtop + 46;
//
//			if (viewheight == 180) {
//				y += 5;
//			}
//
//			ypos = centrey - y + 10;
//
//			for (i = 0; i < 17; i++) {
//				// 70fc
//				brightness = i < value ? 0x28 : 0x50;
//				alpha = i < value ? 0x22 : 0x56;
//
//				points[0] = x = viewright - 34;
//				points[1] = y;
//				points[3] = y + barheight;
//				points[2] = x = viewright - 34;
//
//				// 7168
//				points[6] = x = viewwidth * .5f + sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * scale + 5.0f;
//				points[5] = y + barheight;
//
//				ypos -= barheight;
//
//				// 71c8
//				points[4] = x = viewwidth * .5f + sqrtf(sqcentrey - (ypos - yoffset) * (ypos - yoffset)) * scale + 5.0f;
//				points[7] = y;
//
//				ypos -= 2;
//
//				if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_CAMSPY) {
//					// 7240
//					gdl = bviewRenderEyespySideRect(gdl, points, 0, brightness, 0, alpha);
//				} else if (g_Vars.currentplayer->eyespy->mode == EYESPYMODE_DRUGSPY) {
//					gdl = bviewRenderEyespySideRect(gdl, points, 0x10, brightness, brightness * 3, alpha);
//				} else {
//					gdl = bviewRenderEyespySideRect(gdl, points, brightness, brightness >> 2, 0, alpha);
//				}
//
//				y += barheight;
//				y += 2;
//			}
//		}
//
//		// 72c4
//		gdl = func0f0d49c8(gdl);
//	}
//
//	return gdl;
//}

void func0f1572f8(void)
{
	// empty
}

GLOBAL_ASM(
glabel bviewRenderNvLens
/*  f1472fc:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f147300:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f147304:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f147308:	00808825 */ 	or	$s1,$a0,$zero
/*  f14730c:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f147310:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f147314:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f147318:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f14731c:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f147320:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f147324:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f147328:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f14732c:	0c002ac7 */ 	jal	viGetUnk28
/*  f147330:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f147334:	0c002f26 */ 	jal	viGetViewHeight
/*  f147338:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f14733c:	0c002f22 */ 	jal	viGetViewWidth
/*  f147340:	00408025 */ 	or	$s0,$v0,$zero
/*  f147344:	0c002f44 */ 	jal	viGetViewTop
/*  f147348:	0040b025 */ 	or	$s6,$v0,$zero
/*  f14734c:	0c002f40 */ 	jal	viGetViewLeft
/*  f147350:	00409825 */ 	or	$s3,$v0,$zero
/*  f147354:	3c038008 */ 	lui	$v1,%hi(var8007f840)
/*  f147358:	2463f840 */ 	addiu	$v1,$v1,%lo(var8007f840)
/*  f14735c:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f147360:	0270a021 */ 	addu	$s4,$s3,$s0
/*  f147364:	0040b825 */ 	or	$s7,$v0,$zero
/*  f147368:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f14736c:	29e10002 */ 	slti	$at,$t7,0x2
/*  f147370:	0280f025 */ 	or	$s8,$s4,$zero
/*  f147374:	14200003 */ 	bnez	$at,.L0f147384
/*  f147378:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f14737c:	1000006f */ 	b	.L0f14753c
/*  f147380:	02201025 */ 	or	$v0,$s1,$zero
.L0f147384:
/*  f147384:	3c04800a */ 	lui	$a0,%hi(var800a41c0)
/*  f147388:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e50)
/*  f14738c:	24a55e50 */ 	addiu	$a1,$a1,%lo(var7f1b5e50)
/*  f147390:	0c004c4c */ 	jal	strcpy
/*  f147394:	248441c0 */ 	addiu	$a0,$a0,%lo(var800a41c0)
/*  f147398:	241900bc */ 	addiu	$t9,$zero,0xbc
/*  f14739c:	3c01800a */ 	lui	$at,%hi(var8009caec)
/*  f1473a0:	a039caec */ 	sb	$t9,%lo(var8009caec)($at)
/*  f1473a4:	3c01800a */ 	lui	$at,%hi(var8009caec+0x3)
/*  f1473a8:	240800be */ 	addiu	$t0,$zero,0xbe
/*  f1473ac:	a028caef */ 	sb	$t0,%lo(var8009caec+0x3)($at)
/*  f1473b0:	3c01800a */ 	lui	$at,%hi(var8009caf0)
/*  f1473b4:	240900de */ 	addiu	$t1,$zero,0xde
/*  f1473b8:	a029caf0 */ 	sb	$t1,%lo(var8009caf0)($at)
/*  f1473bc:	3c01800a */ 	lui	$at,%hi(var8009caec+0x1)
/*  f1473c0:	240a0050 */ 	addiu	$t2,$zero,0x50
/*  f1473c4:	a02acaed */ 	sb	$t2,%lo(var8009caec+0x1)($at)
/*  f1473c8:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f1473cc:	3c01800a */ 	lui	$at,%hi(var8009caec+0x2)
/*  f1473d0:	240b00c0 */ 	addiu	$t3,$zero,0xc0
/*  f1473d4:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f1473d8:	a02bcaee */ 	sb	$t3,%lo(var8009caec+0x2)($at)
/*  f1473dc:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f1473e0:	8d8d00bc */ 	lw	$t5,0xbc($t4)
/*  f1473e4:	0fc00270 */ 	jal	func0f0009c0
/*  f1473e8:	85a40028 */ 	lh	$a0,0x28($t5)
/*  f1473ec:	28410081 */ 	slti	$at,$v0,0x81
/*  f1473f0:	14200004 */ 	bnez	$at,.L0f147404
/*  f1473f4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1473f8:	00402825 */ 	or	$a1,$v0,$zero
/*  f1473fc:	0fc49ccd */ 	jal	func0f127334
/*  f147400:	00403025 */ 	or	$a2,$v0,$zero
.L0f147404:
/*  f147404:	8e0e0288 */ 	lw	$t6,0x288($s0)
/*  f147408:	3c19800a */ 	lui	$t9,%hi(g_Menus+0x4f8)
/*  f14740c:	02202025 */ 	or	$a0,$s1,$zero
/*  f147410:	8dcf0070 */ 	lw	$t7,0x70($t6)
/*  f147414:	3c0500ff */ 	lui	$a1,0xff
/*  f147418:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f14741c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f147420:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f147424:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f147428:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f14742c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f147430:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f147434:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f147438:	8f39e4f8 */ 	lw	$t9,%lo(g_Menus+0x4f8)($t9)
/*  f14743c:	57200005 */ 	bnezl	$t9,.L0f147454
/*  f147440:	02201025 */ 	or	$v0,$s1,$zero
/*  f147444:	0fc5090e */ 	jal	bviewRenderMotionBlur
/*  f147448:	24060060 */ 	addiu	$a2,$zero,0x60
/*  f14744c:	00408825 */ 	or	$s1,$v0,$zero
/*  f147450:	02201025 */ 	or	$v0,$s1,$zero
.L0f147454:
/*  f147454:	3c08e700 */ 	lui	$t0,0xe700
/*  f147458:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f14745c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f147460:	26240008 */ 	addiu	$a0,$s1,0x8
/*  f147464:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f147468:	0fc5082c */ 	jal	bviewPrepareStaticRgba16
/*  f14746c:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f147470:	3c128008 */ 	lui	$s2,%hi(var8007f878)
/*  f147474:	2652f878 */ 	addiu	$s2,$s2,%lo(var8007f878)
/*  f147478:	92490000 */ 	lbu	$t1,0x0($s2)
/*  f14747c:	0274082a */ 	slt	$at,$s3,$s4
/*  f147480:	00408825 */ 	or	$s1,$v0,$zero
/*  f147484:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f147488:	a24a0000 */ 	sb	$t2,0x0($s2)
/*  f14748c:	1020002a */ 	beqz	$at,.L0f147538
/*  f147490:	02608025 */ 	or	$s0,$s3,$zero
/*  f147494:	3c013f80 */ 	lui	$at,0x3f80
/*  f147498:	4481a000 */ 	mtc1	$at,$f20
/*  f14749c:	3c15fb00 */ 	lui	$s5,0xfb00
/*  f1474a0:	2414000c */ 	addiu	$s4,$zero,0xc
/*  f1474a4:	241300ff */ 	addiu	$s3,$zero,0xff
.L0f1474a8:
/*  f1474a8:	924c0000 */ 	lbu	$t4,0x0($s2)
/*  f1474ac:	320b0001 */ 	andi	$t3,$s0,0x1
/*  f1474b0:	24030094 */ 	addiu	$v1,$zero,0x94
/*  f1474b4:	318d0001 */ 	andi	$t5,$t4,0x1
/*  f1474b8:	116d000e */ 	beq	$t3,$t5,.L0f1474f4
/*  f1474bc:	00000000 */ 	nop
/*  f1474c0:	0c004b70 */ 	jal	random
/*  f1474c4:	00000000 */ 	nop
/*  f1474c8:	0054001b */ 	divu	$zero,$v0,$s4
/*  f1474cc:	00007810 */ 	mfhi	$t7
/*  f1474d0:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f1474d4:	02781823 */ 	subu	$v1,$s3,$t8
/*  f1474d8:	307900ff */ 	andi	$t9,$v1,0xff
/*  f1474dc:	16800002 */ 	bnez	$s4,.L0f1474e8
/*  f1474e0:	00000000 */ 	nop
/*  f1474e4:	0007000d */ 	break	0x7
.L0f1474e8:
/*  f1474e8:	03201825 */ 	or	$v1,$t9,$zero
/*  f1474ec:	10000002 */ 	b	.L0f1474f8
/*  f1474f0:	02201025 */ 	or	$v0,$s1,$zero
.L0f1474f4:
/*  f1474f4:	02201025 */ 	or	$v0,$s1,$zero
.L0f1474f8:
/*  f1474f8:	00034400 */ 	sll	$t0,$v1,0x10
/*  f1474fc:	250900ff */ 	addiu	$t1,$t0,0xff
/*  f147500:	ac490004 */ 	sw	$t1,0x4($v0)
/*  f147504:	ac550000 */ 	sw	$s5,0x0($v0)
/*  f147508:	26240008 */ 	addiu	$a0,$s1,0x8
/*  f14750c:	afb6001c */ 	sw	$s6,0x1c($sp)
/*  f147510:	afb70018 */ 	sw	$s7,0x18($sp)
/*  f147514:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f147518:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f14751c:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f147520:	02003025 */ 	or	$a2,$s0,$zero
/*  f147524:	0fc506ac */ 	jal	bviewRenderLensRect
/*  f147528:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f14752c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f147530:	161effdd */ 	bne	$s0,$s8,.L0f1474a8
/*  f147534:	00408825 */ 	or	$s1,$v0,$zero
.L0f147538:
/*  f147538:	02201025 */ 	or	$v0,$s1,$zero
.L0f14753c:
/*  f14753c:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f147540:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f147544:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f147548:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f14754c:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f147550:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f147554:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f147558:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f14755c:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f147560:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f147564:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f147568:	03e00008 */ 	jr	$ra
/*  f14756c:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

// Mismatch because var8009caec and friends needs to be moved into this file,
// and regalloc near random().
//Gfx *bviewRenderNvLens(Gfx *gdl)
//{
//	void *unk28 = viGetUnk28();
//	s32 viewheight = viGetViewHeight();
//	s32 viewwidth = viGetViewWidth();
//	s32 viewtop = viGetViewTop();
//	s32 viewleft = viGetViewLeft();
//	s32 viewbottom = viewtop + viewheight;
//	s32 roomvalue;
//	s32 y;
//
//	var8007f840++;
//
//	if (var8007f840 >= 2) {
//		return gdl;
//	}
//
//	strcpy(var800a41c0, "Fullscreen_DrawFaultScope");
//
//	var8009caec = 0xbc;
//	var8009caef = 0xbe;
//	var8009caf0 = 0xde;
//	var8009caed = 0x50;
//	var8009caee = 0xc0;
//
//	roomvalue = func0f0009c0(g_Vars.currentplayer->prop->rooms[0]);
//
//	if (roomvalue > 128) {
//		func0f127334(roomvalue, roomvalue, roomvalue);
//	}
//
//	if (g_Menus[g_Vars.currentplayerstats->mpindex].curframe == NULL) {
//		gdl = bviewRenderMotionBlur(gdl, 0x00ff0000, 0x60);
//	}
//
//	gDPPipeSync(gdl++);
//
//	gdl = bviewPrepareStaticRgba16(gdl, 0xffffffff, 0xff);
//
//	var8007f878++;
//
//	for (y = viewtop; y < viewbottom; y++) {
//		u8 green;
//
//		if ((var8007f878 & 1) != (y & 1)) {
//			u8 tmp = random() % 12;
//			green = 0xff - tmp;
//		} else {
//			green = 148;
//		}
//
//		gDPSetColor(gdl++, G_SETENVCOLOR, (green << 16) + 0xff);
//
//		gdl = bviewRenderLensRect(gdl, unk28, y, 5, y, 1, viewleft, viewwidth);
//	}
//
//	return gdl;
//}

Gfx *bviewRenderNvBinoculars(Gfx *gdl)
{
	return gdl;
}

const char var7f1b5e50[] = "Fullscreen_DrawFaultScope";
const char var7f1b5e6c[] = "Fullscreen_DrawFaultScope";

#if VERSION < VERSION_NTSC_1_0
const char var7f1b03d8nb[] = "Fault Scope is active\n";
#endif

const char var7f1b5e88[] = "IntroFaderBlurGfx";

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel bviewRenderIrLens
/*  f147578:	27bdff10 */ 	addiu	$sp,$sp,-240
/*  f14757c:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f147580:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f147584:	0080a025 */ 	or	$s4,$a0,$zero
/*  f147588:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f14758c:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f147590:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f147594:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f147598:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f14759c:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f1475a0:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f1475a4:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1475a8:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f1475ac:	0c002ac7 */ 	jal	viGetUnk28
/*  f1475b0:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f1475b4:	0c002f26 */ 	jal	viGetViewHeight
/*  f1475b8:	0040f025 */ 	or	$s8,$v0,$zero
/*  f1475bc:	0c002f22 */ 	jal	viGetViewWidth
/*  f1475c0:	00409825 */ 	or	$s3,$v0,$zero
/*  f1475c4:	0c002f44 */ 	jal	viGetViewTop
/*  f1475c8:	afa200dc */ 	sw	$v0,0xdc($sp)
/*  f1475cc:	0c002f40 */ 	jal	viGetViewLeft
/*  f1475d0:	00408025 */ 	or	$s0,$v0,$zero
/*  f1475d4:	3c038008 */ 	lui	$v1,%hi(g_IrBinocularRadius)
/*  f1475d8:	8c63f84c */ 	lw	$v1,%lo(g_IrBinocularRadius)($v1)
/*  f1475dc:	3c0a8008 */ 	lui	$t2,%hi(var8007f850)
/*  f1475e0:	8d4af850 */ 	lw	$t2,%lo(var8007f850)($t2)
/*  f1475e4:	8fae00dc */ 	lw	$t6,0xdc($sp)
/*  f1475e8:	3c048008 */ 	lui	$a0,%hi(var8007f840)
/*  f1475ec:	006a001a */ 	div	$zero,$v1,$t2
/*  f1475f0:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f1475f4:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f1475f8:	2484f840 */ 	addiu	$a0,$a0,%lo(var8007f840)
/*  f1475fc:	8c8b0000 */ 	lw	$t3,0x0($a0)
/*  f147600:	0000a812 */ 	mflo	$s5
/*  f147604:	afa200d4 */ 	sw	$v0,0xd4($sp)
/*  f147608:	07010003 */ 	bgez	$t8,.L0f147618
/*  f14760c:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f147610:	27010001 */ 	addiu	$at,$t8,0x1
/*  f147614:	0001c843 */ 	sra	$t9,$at,0x1
.L0f147618:
/*  f147618:	256c0001 */ 	addiu	$t4,$t3,0x1
/*  f14761c:	afb900c8 */ 	sw	$t9,0xc8($sp)
/*  f147620:	ac8c0000 */ 	sw	$t4,0x0($a0)
/*  f147624:	01806825 */ 	or	$t5,$t4,$zero
/*  f147628:	00609025 */ 	or	$s2,$v1,$zero
/*  f14762c:	15400002 */ 	bnez	$t2,.L0f147638
/*  f147630:	00000000 */ 	nop
/*  f147634:	0007000d */ 	break	0x7
.L0f147638:
/*  f147638:	2401ffff */ 	addiu	$at,$zero,-1
/*  f14763c:	15410004 */ 	bne	$t2,$at,.L0f147650
/*  f147640:	3c018000 */ 	lui	$at,0x8000
/*  f147644:	14610002 */ 	bne	$v1,$at,.L0f147650
/*  f147648:	00000000 */ 	nop
/*  f14764c:	0006000d */ 	break	0x6
.L0f147650:
/*  f147650:	29810002 */ 	slti	$at,$t4,0x2
/*  f147654:	14200003 */ 	bnez	$at,.L0f147664
/*  f147658:	00000000 */ 	nop
/*  f14765c:	10000119 */ 	b	.L0f147ac4
/*  f147660:	02801025 */ 	or	$v0,$s4,$zero
.L0f147664:
/*  f147664:	3c04800a */ 	lui	$a0,%hi(var800a41c0)
/*  f147668:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e6c)
/*  f14766c:	24a55e6c */ 	addiu	$a1,$a1,%lo(var7f1b5e6c)
/*  f147670:	0c004c4c */ 	jal	strcpy
/*  f147674:	248441c0 */ 	addiu	$a0,$a0,%lo(var800a41c0)
/*  f147678:	02131821 */ 	addu	$v1,$s0,$s3
/*  f14767c:	02033821 */ 	addu	$a3,$s0,$v1
/*  f147680:	04e10003 */ 	bgez	$a3,.L0f147690
/*  f147684:	00077043 */ 	sra	$t6,$a3,0x1
/*  f147688:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f14768c:	00017043 */ 	sra	$t6,$at,0x1
.L0f147690:
/*  f147690:	01d28823 */ 	subu	$s1,$t6,$s2
/*  f147694:	01d22821 */ 	addu	$a1,$t6,$s2
/*  f147698:	0071082a */ 	slt	$at,$v1,$s1
/*  f14769c:	01c03825 */ 	or	$a3,$t6,$zero
/*  f1476a0:	10200002 */ 	beqz	$at,.L0f1476ac
/*  f1476a4:	00a03025 */ 	or	$a2,$a1,$zero
/*  f1476a8:	00608825 */ 	or	$s1,$v1,$zero
.L0f1476ac:
/*  f1476ac:	0065082a */ 	slt	$at,$v1,$a1
/*  f1476b0:	50200003 */ 	beqzl	$at,.L0f1476c0
/*  f1476b4:	0230082a */ 	slt	$at,$s1,$s0
/*  f1476b8:	00603025 */ 	or	$a2,$v1,$zero
/*  f1476bc:	0230082a */ 	slt	$at,$s1,$s0
.L0f1476c0:
/*  f1476c0:	10200002 */ 	beqz	$at,.L0f1476cc
/*  f1476c4:	240800ff */ 	addiu	$t0,$zero,0xff
/*  f1476c8:	02008825 */ 	or	$s1,$s0,$zero
.L0f1476cc:
/*  f1476cc:	00d0082a */ 	slt	$at,$a2,$s0
/*  f1476d0:	10200002 */ 	beqz	$at,.L0f1476dc
/*  f1476d4:	240401e0 */ 	addiu	$a0,$zero,0x1e0
/*  f1476d8:	02003025 */ 	or	$a2,$s0,$zero
.L0f1476dc:
/*  f1476dc:	44932000 */ 	mtc1	$s3,$f4
/*  f1476e0:	240f0004 */ 	addiu	$t7,$zero,0x4
/*  f1476e4:	448f3000 */ 	mtc1	$t7,$f6
/*  f1476e8:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f1476ec:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f1476f0:	44992000 */ 	mtc1	$t9,$f4
/*  f1476f4:	3c014370 */ 	lui	$at,0x4370
/*  f1476f8:	44811000 */ 	mtc1	$at,$f2
/*  f1476fc:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f147700:	3c16800a */ 	lui	$s6,%hi(g_Vars)
/*  f147704:	26d69fc0 */ 	addiu	$s6,$s6,%lo(g_Vars)
/*  f147708:	8ec30284 */ 	lw	$v1,0x284($s6)
/*  f14770c:	00008025 */ 	or	$s0,$zero,$zero
/*  f147710:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f147714:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f147718:	00c04825 */ 	or	$t1,$a2,$zero
/*  f14771c:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f147720:	46025403 */ 	div.s	$f16,$f10,$f2
/*  f147724:	46024283 */ 	div.s	$f10,$f8,$f2
/*  f147728:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f14772c:	44059000 */ 	mfc1	$a1,$f18
/*  f147730:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f147734:	440b8000 */ 	mfc1	$t3,$f16
/*  f147738:	00000000 */ 	nop
/*  f14773c:	afab00e8 */ 	sw	$t3,0xe8($sp)
/*  f147740:	846c1c60 */ 	lh	$t4,0x1c60($v1)
/*  f147744:	524c0010 */ 	beql	$s2,$t4,.L0f147788
/*  f147748:	240800ff */ 	addiu	$t0,$zero,0xff
/*  f14774c:	8ecd028c */ 	lw	$t5,0x28c($s6)
/*  f147750:	3c0f800a */ 	lui	$t7,%hi(var800a41c0+0x18)
/*  f147754:	25ef41d8 */ 	addiu	$t7,$t7,%lo(var800a41c0+0x18)
/*  f147758:	000d7100 */ 	sll	$t6,$t5,0x4
/*  f14775c:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f147760:	000e7140 */ 	sll	$t6,$t6,0x5
/*  f147764:	01cf1021 */ 	addu	$v0,$t6,$t7
.L0f147768:
/*  f147768:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f14776c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f147770:	1604fffd */ 	bne	$s0,$a0,.L0f147768
/*  f147774:	a048ffff */ 	sb	$t0,-0x1($v0)
/*  f147778:	a4601c62 */ 	sh	$zero,0x1c62($v1)
/*  f14777c:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f147780:	a7121c60 */ 	sh	$s2,0x1c60($t8)
/*  f147784:	240800ff */ 	addiu	$t0,$zero,0xff
.L0f147788:
/*  f147788:	00008025 */ 	or	$s0,$zero,$zero
/*  f14778c:	afa600ac */ 	sw	$a2,0xac($sp)
/*  f147790:	18a0001b */ 	blez	$a1,.L0f147800
/*  f147794:	afa70064 */ 	sw	$a3,0x64($sp)
/*  f147798:	afa70064 */ 	sw	$a3,0x64($sp)
/*  f14779c:	3c07800a */ 	lui	$a3,%hi(var800a41c0+0x18)
/*  f1477a0:	24e741d8 */ 	addiu	$a3,$a3,%lo(var800a41c0+0x18)
/*  f1477a4:	afa600ac */ 	sw	$a2,0xac($sp)
/*  f1477a8:	240400ff */ 	addiu	$a0,$zero,0xff
.L0f1477ac:
/*  f1477ac:	8ec30284 */ 	lw	$v1,0x284($s6)
/*  f1477b0:	84621c62 */ 	lh	$v0,0x1c62($v1)
/*  f1477b4:	0049082a */ 	slt	$at,$v0,$t1
/*  f1477b8:	54200005 */ 	bnezl	$at,.L0f1477d0
/*  f1477bc:	8eca028c */ 	lw	$t2,0x28c($s6)
/*  f1477c0:	a4711c62 */ 	sh	$s1,0x1c62($v1)
/*  f1477c4:	8ec30284 */ 	lw	$v1,0x284($s6)
/*  f1477c8:	84621c62 */ 	lh	$v0,0x1c62($v1)
/*  f1477cc:	8eca028c */ 	lw	$t2,0x28c($s6)
.L0f1477d0:
/*  f1477d0:	0090c823 */ 	subu	$t9,$a0,$s0
/*  f1477d4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1477d8:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f1477dc:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f1477e0:	000b5940 */ 	sll	$t3,$t3,0x5
/*  f1477e4:	00eb6021 */ 	addu	$t4,$a3,$t3
/*  f1477e8:	01826821 */ 	addu	$t5,$t4,$v0
/*  f1477ec:	a1b90000 */ 	sb	$t9,0x0($t5)
/*  f1477f0:	846e1c62 */ 	lh	$t6,0x1c62($v1)
/*  f1477f4:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f1477f8:	1605ffec */ 	bne	$s0,$a1,.L0f1477ac
/*  f1477fc:	a46f1c62 */ 	sh	$t7,0x1c62($v1)
.L0f147800:
/*  f147800:	3c01800a */ 	lui	$at,%hi(var8009caec)
/*  f147804:	a028caec */ 	sb	$t0,%lo(var8009caec)($at)
/*  f147808:	240300de */ 	addiu	$v1,$zero,0xde
/*  f14780c:	3c01800a */ 	lui	$at,%hi(var8009caec+0x3)
/*  f147810:	a023caef */ 	sb	$v1,%lo(var8009caec+0x3)($at)
/*  f147814:	3c01800a */ 	lui	$at,%hi(var8009caf0)
/*  f147818:	a023caf0 */ 	sb	$v1,%lo(var8009caf0)($at)
/*  f14781c:	02801025 */ 	or	$v0,$s4,$zero
/*  f147820:	3c18e700 */ 	lui	$t8,0xe700
/*  f147824:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f147828:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f14782c:	26840008 */ 	addiu	$a0,$s4,0x8
/*  f147830:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f147834:	0fc5082c */ 	jal	bviewPrepareStaticRgba16
/*  f147838:	01003025 */ 	or	$a2,$t0,$zero
/*  f14783c:	8faa00ac */ 	lw	$t2,0xac($sp)
/*  f147840:	0040a025 */ 	or	$s4,$v0,$zero
/*  f147844:	02208025 */ 	or	$s0,$s1,$zero
/*  f147848:	022a082a */ 	slt	$at,$s1,$t2
/*  f14784c:	5020008a */ 	beqzl	$at,.L0f147a78
/*  f147850:	8ecf0288 */ 	lw	$t7,0x288($s6)
/*  f147854:	02b50019 */ 	multu	$s5,$s5
/*  f147858:	8ecb028c */ 	lw	$t3,0x28c($s6)
/*  f14785c:	3c0d800a */ 	lui	$t5,%hi(var800a41c0+0x18)
/*  f147860:	3c013f80 */ 	lui	$at,0x3f80
/*  f147864:	000b6100 */ 	sll	$t4,$t3,0x4
/*  f147868:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f14786c:	000c6140 */ 	sll	$t4,$t4,0x5
/*  f147870:	0191c821 */ 	addu	$t9,$t4,$s1
/*  f147874:	25ad41d8 */ 	addiu	$t5,$t5,%lo(var800a41c0+0x18)
/*  f147878:	4481b000 */ 	mtc1	$at,$f22
/*  f14787c:	0000b812 */ 	mflo	$s7
/*  f147880:	032d1021 */ 	addu	$v0,$t9,$t5
/*  f147884:	3c15fb00 */ 	lui	$s5,0xfb00
/*  f147888:	320e0001 */ 	andi	$t6,$s0,0x1
.L0f14788c:
/*  f14788c:	51c00004 */ 	beqzl	$t6,.L0f1478a0
/*  f147890:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f147894:	10000008 */ 	b	.L0f1478b8
/*  f147898:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f14789c:	90430000 */ 	lbu	$v1,0x0($v0)
.L0f1478a0:
/*  f1478a0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1478a4:	00037840 */ 	sll	$t7,$v1,0x1
/*  f1478a8:	01e1001a */ 	div	$zero,$t7,$at
/*  f1478ac:	00001812 */ 	mflo	$v1
/*  f1478b0:	00000000 */ 	nop
/*  f1478b4:	00000000 */ 	nop
.L0f1478b8:
/*  f1478b8:	0c004b70 */ 	jal	random
/*  f1478bc:	afa300a0 */ 	sw	$v1,0xa0($sp)
/*  f1478c0:	8fa300a0 */ 	lw	$v1,0xa0($sp)
/*  f1478c4:	304a0007 */ 	andi	$t2,$v0,0x7
/*  f1478c8:	02801025 */ 	or	$v0,$s4,$zero
/*  f1478cc:	006a1821 */ 	addu	$v1,$v1,$t2
/*  f1478d0:	2c610100 */ 	sltiu	$at,$v1,0x100
/*  f1478d4:	14200002 */ 	bnez	$at,.L0f1478e0
/*  f1478d8:	03c02825 */ 	or	$a1,$s8,$zero
/*  f1478dc:	240300ff */ 	addiu	$v1,$zero,0xff
.L0f1478e0:
/*  f1478e0:	00035e00 */ 	sll	$t3,$v1,0x18
/*  f1478e4:	256c00ff */ 	addiu	$t4,$t3,0xff
/*  f1478e8:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f1478ec:	ac550000 */ 	sw	$s5,0x0($v0)
/*  f1478f0:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f1478f4:	26940008 */ 	addiu	$s4,$s4,0x8
/*  f1478f8:	02003025 */ 	or	$a2,$s0,$zero
/*  f1478fc:	03302023 */ 	subu	$a0,$t9,$s0
/*  f147900:	00840019 */ 	multu	$a0,$a0
/*  f147904:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f147908:	00006812 */ 	mflo	$t5
/*  f14790c:	01b7082a */ 	slt	$at,$t5,$s7
/*  f147910:	5020003d */ 	beqzl	$at,.L0f147a08
/*  f147914:	8faf00d4 */ 	lw	$t7,0xd4($sp)
/*  f147918:	44849000 */ 	mtc1	$a0,$f18
/*  f14791c:	8faa00dc */ 	lw	$t2,0xdc($sp)
/*  f147920:	3c0143a0 */ 	lui	$at,0x43a0
/*  f147924:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f147928:	448a5000 */ 	mtc1	$t2,$f10
/*  f14792c:	44819000 */ 	mtc1	$at,$f18
/*  f147930:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f147934:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f147938:	46128503 */ 	div.s	$f20,$f16,$f18
/*  f14793c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f147940:	440f3000 */ 	mfc1	$t7,$f6
/*  f147944:	00000000 */ 	nop
/*  f147948:	02efc023 */ 	subu	$t8,$s7,$t7
/*  f14794c:	44984000 */ 	mtc1	$t8,$f8
/*  f147950:	0c012974 */ 	jal	sqrtf
/*  f147954:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f147958:	46140102 */ 	mul.s	$f4,$f0,$f20
/*  f14795c:	8fa800c8 */ 	lw	$t0,0xc8($sp)
/*  f147960:	8fac00dc */ 	lw	$t4,0xdc($sp)
/*  f147964:	8fb900d4 */ 	lw	$t9,0xd4($sp)
/*  f147968:	02802025 */ 	or	$a0,$s4,$zero
/*  f14796c:	03c02825 */ 	or	$a1,$s8,$zero
/*  f147970:	02003025 */ 	or	$a2,$s0,$zero
/*  f147974:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f147978:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f14797c:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f147980:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*  f147984:	44023000 */ 	mfc1	$v0,$f6
/*  f147988:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f14798c:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f147990:	01029021 */ 	addu	$s2,$t0,$v0
/*  f147994:	01929823 */ 	subu	$s3,$t4,$s2
/*  f147998:	0fc506ac */ 	jal	bviewRenderLensRect
/*  f14799c:	00408825 */ 	or	$s1,$v0,$zero
/*  f1479a0:	00402025 */ 	or	$a0,$v0,$zero
/*  f1479a4:	03c02825 */ 	or	$a1,$s8,$zero
/*  f1479a8:	02003025 */ 	or	$a2,$s0,$zero
/*  f1479ac:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f1479b0:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f1479b4:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*  f1479b8:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f1479bc:	0fc506ac */ 	jal	bviewRenderLensRect
/*  f1479c0:	afb3001c */ 	sw	$s3,0x1c($sp)
/*  f1479c4:	3c0dee00 */ 	lui	$t5,0xee00
/*  f1479c8:	35ad00ff */ 	ori	$t5,$t5,0xff
/*  f1479cc:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f1479d0:	ac550000 */ 	sw	$s5,0x0($v0)
/*  f1479d4:	8fae00c8 */ 	lw	$t6,0xc8($sp)
/*  f1479d8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1479dc:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*  f1479e0:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f1479e4:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f1479e8:	03c02825 */ 	or	$a1,$s8,$zero
/*  f1479ec:	02003025 */ 	or	$a2,$s0,$zero
/*  f1479f0:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f1479f4:	0fc506ac */ 	jal	bviewRenderLensRect
/*  f1479f8:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f1479fc:	1000000a */ 	b	.L0f147a28
/*  f147a00:	0040a025 */ 	or	$s4,$v0,$zero
/*  f147a04:	8faf00d4 */ 	lw	$t7,0xd4($sp)
.L0f147a08:
/*  f147a08:	8fb800dc */ 	lw	$t8,0xdc($sp)
/*  f147a0c:	02802025 */ 	or	$a0,$s4,$zero
/*  f147a10:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f147a14:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*  f147a18:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f147a1c:	0fc506ac */ 	jal	bviewRenderLensRect
/*  f147a20:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f147a24:	0040a025 */ 	or	$s4,$v0,$zero
.L0f147a28:
/*  f147a28:	8eca028c */ 	lw	$t2,0x28c($s6)
/*  f147a2c:	3c19800a */ 	lui	$t9,%hi(var800a41c0+0x18)
/*  f147a30:	273941d8 */ 	addiu	$t9,$t9,%lo(var800a41c0+0x18)
/*  f147a34:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f147a38:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f147a3c:	000b5940 */ 	sll	$t3,$t3,0x5
/*  f147a40:	01706021 */ 	addu	$t4,$t3,$s0
/*  f147a44:	01991021 */ 	addu	$v0,$t4,$t9
/*  f147a48:	8fa400e8 */ 	lw	$a0,0xe8($sp)
/*  f147a4c:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f147a50:	0083082a */ 	slt	$at,$a0,$v1
/*  f147a54:	10200002 */ 	beqz	$at,.L0f147a60
/*  f147a58:	00646823 */ 	subu	$t5,$v1,$a0
/*  f147a5c:	a04d0000 */ 	sb	$t5,0x0($v0)
.L0f147a60:
/*  f147a60:	8fae00ac */ 	lw	$t6,0xac($sp)
/*  f147a64:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f147a68:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f147a6c:	560eff87 */ 	bnel	$s0,$t6,.L0f14788c
/*  f147a70:	320e0001 */ 	andi	$t6,$s0,0x1
/*  f147a74:	8ecf0288 */ 	lw	$t7,0x288($s6)
.L0f147a78:
/*  f147a78:	3c0b800a */ 	lui	$t3,%hi(g_Menus+0x4f8)
/*  f147a7c:	02802025 */ 	or	$a0,$s4,$zero
/*  f147a80:	8df80070 */ 	lw	$t8,0x70($t7)
/*  f147a84:	3c05ff00 */ 	lui	$a1,0xff00
/*  f147a88:	001850c0 */ 	sll	$t2,$t8,0x3
/*  f147a8c:	01585023 */ 	subu	$t2,$t2,$t8
/*  f147a90:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f147a94:	01585021 */ 	addu	$t2,$t2,$t8
/*  f147a98:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f147a9c:	01585023 */ 	subu	$t2,$t2,$t8
/*  f147aa0:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f147aa4:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f147aa8:	8d6be4f8 */ 	lw	$t3,%lo(g_Menus+0x4f8)($t3)
/*  f147aac:	55600005 */ 	bnezl	$t3,.L0f147ac4
/*  f147ab0:	02801025 */ 	or	$v0,$s4,$zero
/*  f147ab4:	0fc5090e */ 	jal	bviewRenderMotionBlur
/*  f147ab8:	24060040 */ 	addiu	$a2,$zero,0x40
/*  f147abc:	0040a025 */ 	or	$s4,$v0,$zero
/*  f147ac0:	02801025 */ 	or	$v0,$s4,$zero
.L0f147ac4:
/*  f147ac4:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f147ac8:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f147acc:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f147ad0:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f147ad4:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f147ad8:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f147adc:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f147ae0:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f147ae4:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f147ae8:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f147aec:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f147af0:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f147af4:	03e00008 */ 	jr	$ra
/*  f147af8:	27bd00f0 */ 	addiu	$sp,$sp,0xf0
/*  f147afc:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f147b00:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f147b04:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f147b08:	00809025 */ 	or	$s2,$a0,$zero
/*  f147b0c:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f147b10:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f147b14:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f147b18:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f147b1c:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f147b20:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f147b24:	f7be0050 */ 	sdc1	$f30,0x50($sp)
/*  f147b28:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f147b2c:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f147b30:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f147b34:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f147b38:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f147b3c:	0c002ac7 */ 	jal	viGetUnk28
/*  f147b40:	afa5008c */ 	sw	$a1,0x8c($sp)
/*  f147b44:	0c002f44 */ 	jal	viGetViewTop
/*  f147b48:	0040b025 */ 	or	$s6,$v0,$zero
/*  f147b4c:	0c002f26 */ 	jal	viGetViewHeight
/*  f147b50:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f147b54:	0c002f22 */ 	jal	viGetViewWidth
/*  f147b58:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f147b5c:	0c002f40 */ 	jal	viGetViewLeft
/*  f147b60:	0040a025 */ 	or	$s4,$v0,$zero
/*  f147b64:	3c038008 */ 	lui	$v1,%hi(var8007f840)
/*  f147b68:	2463f840 */ 	addiu	$v1,$v1,%lo(var8007f840)
/*  f147b6c:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f147b70:	0040a825 */ 	or	$s5,$v0,$zero
/*  f147b74:	3c04800a */ 	lui	$a0,%hi(var800a41c0)
/*  f147b78:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f147b7c:	29e10002 */ 	slti	$at,$t7,0x2
/*  f147b80:	14200003 */ 	bnez	$at,.L0f147b90
/*  f147b84:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f147b88:	1000004b */ 	b	.L0f147cb8
/*  f147b8c:	02401025 */ 	or	$v0,$s2,$zero
.L0f147b90:
/*  f147b90:	3c057f1b */ 	lui	$a1,%hi(var7f1b5e88)
/*  f147b94:	24a55e88 */ 	addiu	$a1,$a1,%lo(var7f1b5e88)
/*  f147b98:	0c004c4c */ 	jal	strcpy
/*  f147b9c:	248441c0 */ 	addiu	$a0,$a0,%lo(var800a41c0)
/*  f147ba0:	3c19e700 */ 	lui	$t9,0xe700
/*  f147ba4:	ae590000 */ 	sw	$t9,0x0($s2)
/*  f147ba8:	26440008 */ 	addiu	$a0,$s2,0x8
/*  f147bac:	ae400004 */ 	sw	$zero,0x4($s2)
/*  f147bb0:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f147bb4:	0fc5082c */ 	jal	bviewPrepareStaticRgba16
/*  f147bb8:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f147bbc:	8fa30080 */ 	lw	$v1,0x80($sp)
/*  f147bc0:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f147bc4:	00409025 */ 	or	$s2,$v0,$zero
/*  f147bc8:	00608025 */ 	or	$s0,$v1,$zero
/*  f147bcc:	00649821 */ 	addu	$s3,$v1,$a0
/*  f147bd0:	0073082a */ 	slt	$at,$v1,$s3
/*  f147bd4:	10200037 */ 	beqz	$at,.L0f147cb4
/*  f147bd8:	00638823 */ 	subu	$s1,$v1,$v1
/*  f147bdc:	44842000 */ 	mtc1	$a0,$f4
/*  f147be0:	3c013f00 */ 	lui	$at,0x3f00
/*  f147be4:	44814000 */ 	mtc1	$at,$f8
/*  f147be8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f147bec:	44815000 */ 	mtc1	$at,$f10
/*  f147bf0:	44818000 */ 	mtc1	$at,$f16
/*  f147bf4:	3c012f80 */ 	lui	$at,0x2f80
/*  f147bf8:	4481f000 */ 	mtc1	$at,$f30
/*  f147bfc:	3c013f80 */ 	lui	$at,0x3f80
/*  f147c00:	4481b000 */ 	mtc1	$at,$f22
/*  f147c04:	4480e000 */ 	mtc1	$zero,$f28
/*  f147c08:	46083602 */ 	mul.s	$f24,$f6,$f8
/*  f147c0c:	46105680 */ 	add.s	$f26,$f10,$f16
.L0f147c10:
/*  f147c10:	44919000 */ 	mtc1	$s1,$f18
/*  f147c14:	00000000 */ 	nop
/*  f147c18:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f147c1c:	46182181 */ 	sub.s	$f6,$f4,$f24
/*  f147c20:	46183003 */ 	div.s	$f0,$f6,$f24
/*  f147c24:	461c003c */ 	c.lt.s	$f0,$f28
/*  f147c28:	46000506 */ 	mov.s	$f20,$f0
/*  f147c2c:	45020003 */ 	bc1fl	.L0f147c3c
/*  f147c30:	461aa500 */ 	add.s	$f20,$f20,$f26
/*  f147c34:	46000507 */ 	neg.s	$f20,$f0
/*  f147c38:	461aa500 */ 	add.s	$f20,$f20,$f26
.L0f147c3c:
/*  f147c3c:	4614b03c */ 	c.lt.s	$f22,$f20
/*  f147c40:	00000000 */ 	nop
/*  f147c44:	45000002 */ 	bc1f	.L0f147c50
/*  f147c48:	00000000 */ 	nop
/*  f147c4c:	4600b506 */ 	mov.s	$f20,$f22
.L0f147c50:
/*  f147c50:	0c004b70 */ 	jal	random
/*  f147c54:	00000000 */ 	nop
/*  f147c58:	44824000 */ 	mtc1	$v0,$f8
/*  f147c5c:	02402025 */ 	or	$a0,$s2,$zero
/*  f147c60:	02c02825 */ 	or	$a1,$s6,$zero
/*  f147c64:	02003025 */ 	or	$a2,$s0,$zero
/*  f147c68:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f147c6c:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f147c70:	04410005 */ 	bgez	$v0,.L0f147c88
/*  f147c74:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f147c78:	3c014f80 */ 	lui	$at,0x4f80
/*  f147c7c:	44818000 */ 	mtc1	$at,$f16
/*  f147c80:	00000000 */ 	nop
/*  f147c84:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f147c88:
/*  f147c88:	461e5482 */ 	mul.s	$f18,$f10,$f30
/*  f147c8c:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f147c90:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f147c94:	46149102 */ 	mul.s	$f4,$f18,$f20
/*  f147c98:	46162180 */ 	add.s	$f6,$f4,$f22
/*  f147c9c:	0fc506ac */ 	jal	bviewRenderLensRect
/*  f147ca0:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f147ca4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f147ca8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f147cac:	1613ffd8 */ 	bne	$s0,$s3,.L0f147c10
/*  f147cb0:	00409025 */ 	or	$s2,$v0,$zero
.L0f147cb4:
/*  f147cb4:	02401025 */ 	or	$v0,$s2,$zero
.L0f147cb8:
/*  f147cb8:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f147cbc:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f147cc0:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f147cc4:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f147cc8:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f147ccc:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f147cd0:	d7be0050 */ 	ldc1	$f30,0x50($sp)
/*  f147cd4:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f147cd8:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f147cdc:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f147ce0:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f147ce4:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f147ce8:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f147cec:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f147cf0:	03e00008 */ 	jr	$ra
/*  f147cf4:	27bd0088 */ 	addiu	$sp,$sp,0x88
);
#else
GLOBAL_ASM(
glabel bviewRenderIrLens
/*  f141e0c:	27bdff10 */ 	addiu	$sp,$sp,-240
/*  f141e10:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f141e14:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f141e18:	0080a825 */ 	or	$s5,$a0,$zero
/*  f141e1c:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f141e20:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f141e24:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f141e28:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f141e2c:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f141e30:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f141e34:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f141e38:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f141e3c:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f141e40:	0c002b27 */ 	jal	viGetUnk28
/*  f141e44:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f141e48:	0c002f9b */ 	jal	viGetViewHeight
/*  f141e4c:	0040f025 */ 	or	$s8,$v0,$zero
/*  f141e50:	0c002f97 */ 	jal	viGetViewWidth
/*  f141e54:	00408825 */ 	or	$s1,$v0,$zero
/*  f141e58:	0c002fb9 */ 	jal	viGetViewTop
/*  f141e5c:	afa200dc */ 	sw	$v0,0xdc($sp)
/*  f141e60:	0c002fb5 */ 	jal	viGetViewLeft
/*  f141e64:	00408025 */ 	or	$s0,$v0,$zero
/*  f141e68:	3c038008 */ 	lui	$v1,0x8008
/*  f141e6c:	8c6320ac */ 	lw	$v1,0x20ac($v1)
/*  f141e70:	3c098008 */ 	lui	$t1,0x8008
/*  f141e74:	8d2920b0 */ 	lw	$t1,0x20b0($t1)
/*  f141e78:	8fae00dc */ 	lw	$t6,0xdc($sp)
/*  f141e7c:	3c048008 */ 	lui	$a0,0x8008
/*  f141e80:	0069001a */ 	div	$zero,$v1,$t1
/*  f141e84:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f141e88:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f141e8c:	248420a0 */ 	addiu	$a0,$a0,0x20a0
/*  f141e90:	8c8a0000 */ 	lw	$t2,0x0($a0)
/*  f141e94:	0000a012 */ 	mflo	$s4
/*  f141e98:	afa200d4 */ 	sw	$v0,0xd4($sp)
/*  f141e9c:	07010003 */ 	bgez	$t8,.NB0f141eac
/*  f141ea0:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f141ea4:	27010001 */ 	addiu	$at,$t8,0x1
/*  f141ea8:	0001c843 */ 	sra	$t9,$at,0x1
.NB0f141eac:
/*  f141eac:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f141eb0:	afb900c8 */ 	sw	$t9,0xc8($sp)
/*  f141eb4:	ac8b0000 */ 	sw	$t3,0x0($a0)
/*  f141eb8:	01606025 */ 	or	$t4,$t3,$zero
/*  f141ebc:	00609825 */ 	or	$s3,$v1,$zero
/*  f141ec0:	15200002 */ 	bnez	$t1,.NB0f141ecc
/*  f141ec4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141ec8:	0007000d */ 	break	0x7
.NB0f141ecc:
/*  f141ecc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f141ed0:	15210004 */ 	bne	$t1,$at,.NB0f141ee4
/*  f141ed4:	3c018000 */ 	lui	$at,0x8000
/*  f141ed8:	14610002 */ 	bne	$v1,$at,.NB0f141ee4
/*  f141edc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141ee0:	0006000d */ 	break	0x6
.NB0f141ee4:
/*  f141ee4:	29610002 */ 	slti	$at,$t3,0x2
/*  f141ee8:	14200003 */ 	bnez	$at,.NB0f141ef8
/*  f141eec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141ef0:	100000fb */ 	beqz	$zero,.NB0f1422e0
/*  f141ef4:	02a01025 */ 	or	$v0,$s5,$zero
.NB0f141ef8:
/*  f141ef8:	3c04800b */ 	lui	$a0,0x800b
/*  f141efc:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f141f00:	24a503bc */ 	addiu	$a1,$a1,0x3bc
/*  f141f04:	0c004e60 */ 	jal	strcpy
/*  f141f08:	24848780 */ 	addiu	$a0,$a0,-30848
/*  f141f0c:	0fc4f0b4 */ 	jal	func7f13c2d0nb
/*  f141f10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f141f14:	02111021 */ 	addu	$v0,$s0,$s1
/*  f141f18:	02024021 */ 	addu	$t0,$s0,$v0
/*  f141f1c:	05010003 */ 	bgez	$t0,.NB0f141f2c
/*  f141f20:	00086843 */ 	sra	$t5,$t0,0x1
/*  f141f24:	25010001 */ 	addiu	$at,$t0,0x1
/*  f141f28:	00016843 */ 	sra	$t5,$at,0x1
.NB0f141f2c:
/*  f141f2c:	01b39023 */ 	subu	$s2,$t5,$s3
/*  f141f30:	01b32021 */ 	addu	$a0,$t5,$s3
/*  f141f34:	0052082a */ 	slt	$at,$v0,$s2
/*  f141f38:	01a04025 */ 	or	$t0,$t5,$zero
/*  f141f3c:	10200002 */ 	beqz	$at,.NB0f141f48
/*  f141f40:	afa400ac */ 	sw	$a0,0xac($sp)
/*  f141f44:	00409025 */ 	or	$s2,$v0,$zero
.NB0f141f48:
/*  f141f48:	0052082a */ 	slt	$at,$v0,$s2
/*  f141f4c:	10200002 */ 	beqz	$at,.NB0f141f58
/*  f141f50:	3c0de700 */ 	lui	$t5,0xe700
/*  f141f54:	00409025 */ 	or	$s2,$v0,$zero
.NB0f141f58:
/*  f141f58:	0250082a */ 	slt	$at,$s2,$s0
/*  f141f5c:	10200002 */ 	beqz	$at,.NB0f141f68
/*  f141f60:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f141f64:	02009025 */ 	or	$s2,$s0,$zero
.NB0f141f68:
/*  f141f68:	0090082a */ 	slt	$at,$a0,$s0
/*  f141f6c:	10200002 */ 	beqz	$at,.NB0f141f78
/*  f141f70:	3c02800b */ 	lui	$v0,0x800b
/*  f141f74:	afb000ac */ 	sw	$s0,0xac($sp)
.NB0f141f78:
/*  f141f78:	44912000 */ 	mtc1	$s1,$f4
/*  f141f7c:	240e0004 */ 	addiu	$t6,$zero,0x4
/*  f141f80:	448e3000 */ 	mtc1	$t6,$f6
/*  f141f84:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f141f88:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f141f8c:	44982000 */ 	mtc1	$t8,$f4
/*  f141f90:	3c014370 */ 	lui	$at,0x4370
/*  f141f94:	44811000 */ 	mtc1	$at,$f2
/*  f141f98:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f141f9c:	3c0a8008 */ 	lui	$t2,0x8008
/*  f141fa0:	8d4a20e0 */ 	lw	$t2,0x20e0($t2)
/*  f141fa4:	3c11800b */ 	lui	$s1,0x800b
/*  f141fa8:	3c03800b */ 	lui	$v1,0x800b
/*  f141fac:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f141fb0:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f141fb4:	26318798 */ 	addiu	$s1,$s1,-30824
/*  f141fb8:	24428978 */ 	addiu	$v0,$v0,-30344
/*  f141fbc:	3c018008 */ 	lui	$at,0x8008
/*  f141fc0:	24638798 */ 	addiu	$v1,$v1,-30824
/*  f141fc4:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f141fc8:	00008025 */ 	or	$s0,$zero,$zero
/*  f141fcc:	240400ff */ 	addiu	$a0,$zero,0xff
/*  f141fd0:	46025403 */ 	div.s	$f16,$f10,$f2
/*  f141fd4:	46024283 */ 	div.s	$f10,$f8,$f2
/*  f141fd8:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f141fdc:	44059000 */ 	mfc1	$a1,$f18
/*  f141fe0:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f141fe4:	44098000 */ 	mfc1	$t1,$f16
/*  f141fe8:	11530007 */ 	beq	$t2,$s3,.NB0f142008
/*  f141fec:	afa900e8 */ 	sw	$t1,0xe8($sp)
.NB0f141ff0:
/*  f141ff0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f141ff4:	1622fffe */ 	bne	$s1,$v0,.NB0f141ff0
/*  f141ff8:	a227ffff */ 	sb	$a3,-0x1($s1)
/*  f141ffc:	ac3320e0 */ 	sw	$s3,0x20e0($at)
/*  f142000:	3c018008 */ 	lui	$at,0x8008
/*  f142004:	ac2020dc */ 	sw	$zero,0x20dc($at)
.NB0f142008:
/*  f142008:	3c028008 */ 	lui	$v0,0x8008
/*  f14200c:	8c4220dc */ 	lw	$v0,0x20dc($v0)
/*  f142010:	18a0000c */ 	blez	$a1,.NB0f142044
/*  f142014:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f142018:	8fa600ac */ 	lw	$a2,0xac($sp)
.NB0f14201c:
/*  f14201c:	14460002 */ 	bne	$v0,$a2,.NB0f142028
/*  f142020:	00905823 */ 	subu	$t3,$a0,$s0
/*  f142024:	02401025 */ 	or	$v0,$s2,$zero
.NB0f142028:
/*  f142028:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f14202c:	00626021 */ 	addu	$t4,$v1,$v0
/*  f142030:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f142034:	1605fff9 */ 	bne	$s0,$a1,.NB0f14201c
/*  f142038:	a18b0000 */ 	sb	$t3,0x0($t4)
/*  f14203c:	3c018008 */ 	lui	$at,0x8008
/*  f142040:	ac2220dc */ 	sw	$v0,0x20dc($at)
.NB0f142044:
/*  f142044:	3c01800a */ 	lui	$at,0x800a
/*  f142048:	a027122c */ 	sb	$a3,0x122c($at)
/*  f14204c:	240300de */ 	addiu	$v1,$zero,0xde
/*  f142050:	3c01800a */ 	lui	$at,0x800a
/*  f142054:	a023122f */ 	sb	$v1,0x122f($at)
/*  f142058:	3c01800a */ 	lui	$at,0x800a
/*  f14205c:	a0231230 */ 	sb	$v1,0x1230($at)
/*  f142060:	02a01025 */ 	or	$v0,$s5,$zero
/*  f142064:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f142068:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f14206c:	26a40008 */ 	addiu	$a0,$s5,0x8
/*  f142070:	afa80064 */ 	sw	$t0,0x64($sp)
/*  f142074:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f142078:	0fc4f2e8 */ 	jal	bviewPrepareStaticRgba16
/*  f14207c:	00e03025 */ 	or	$a2,$a3,$zero
/*  f142080:	8fae00ac */ 	lw	$t6,0xac($sp)
/*  f142084:	0040a825 */ 	or	$s5,$v0,$zero
/*  f142088:	02408025 */ 	or	$s0,$s2,$zero
/*  f14208c:	024e082a */ 	slt	$at,$s2,$t6
/*  f142090:	1020007e */ 	beqz	$at,.NB0f14228c
/*  f142094:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142098:	02940019 */ 	multu	$s4,$s4
/*  f14209c:	3c0f800b */ 	lui	$t7,0x800b
/*  f1420a0:	3c013f80 */ 	lui	$at,0x3f80
/*  f1420a4:	25ef8798 */ 	addiu	$t7,$t7,-30824
/*  f1420a8:	4481b000 */ 	mtc1	$at,$f22
/*  f1420ac:	024f8821 */ 	addu	$s1,$s2,$t7
/*  f1420b0:	3c16fb00 */ 	lui	$s6,0xfb00
/*  f1420b4:	0000b812 */ 	mflo	$s7
/*  f1420b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1420bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1420c0:	32180001 */ 	andi	$t8,$s0,0x1
.NB0f1420c4:
/*  f1420c4:	53000004 */ 	beqzl	$t8,.NB0f1420d8
/*  f1420c8:	92230000 */ 	lbu	$v1,0x0($s1)
/*  f1420cc:	10000008 */ 	beqz	$zero,.NB0f1420f0
/*  f1420d0:	92230000 */ 	lbu	$v1,0x0($s1)
/*  f1420d4:	92230000 */ 	lbu	$v1,0x0($s1)
.NB0f1420d8:
/*  f1420d8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f1420dc:	0003c840 */ 	sll	$t9,$v1,0x1
/*  f1420e0:	0321001a */ 	div	$zero,$t9,$at
/*  f1420e4:	00001812 */ 	mflo	$v1
/*  f1420e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1420ec:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f1420f0:
/*  f1420f0:	0c004d84 */ 	jal	random
/*  f1420f4:	afa300a0 */ 	sw	$v1,0xa0($sp)
/*  f1420f8:	8fa300a0 */ 	lw	$v1,0xa0($sp)
/*  f1420fc:	304a0007 */ 	andi	$t2,$v0,0x7
/*  f142100:	02a01025 */ 	or	$v0,$s5,$zero
/*  f142104:	006a1821 */ 	addu	$v1,$v1,$t2
/*  f142108:	2c610100 */ 	sltiu	$at,$v1,0x100
/*  f14210c:	14200002 */ 	bnez	$at,.NB0f142118
/*  f142110:	03c02825 */ 	or	$a1,$s8,$zero
/*  f142114:	240300ff */ 	addiu	$v1,$zero,0xff
.NB0f142118:
/*  f142118:	00035e00 */ 	sll	$t3,$v1,0x18
/*  f14211c:	256c00ff */ 	addiu	$t4,$t3,0xff
/*  f142120:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f142124:	ac560000 */ 	sw	$s6,0x0($v0)
/*  f142128:	8fad0064 */ 	lw	$t5,0x64($sp)
/*  f14212c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f142130:	02003025 */ 	or	$a2,$s0,$zero
/*  f142134:	01b02023 */ 	subu	$a0,$t5,$s0
/*  f142138:	00840019 */ 	multu	$a0,$a0
/*  f14213c:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f142140:	00007012 */ 	mflo	$t6
/*  f142144:	01d7082a */ 	slt	$at,$t6,$s7
/*  f142148:	5020003d */ 	beqzl	$at,.NB0f142240
/*  f14214c:	8faf00d4 */ 	lw	$t7,0xd4($sp)
/*  f142150:	44849000 */ 	mtc1	$a0,$f18
/*  f142154:	8fa900dc */ 	lw	$t1,0xdc($sp)
/*  f142158:	3c0143a0 */ 	lui	$at,0x43a0
/*  f14215c:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f142160:	44895000 */ 	mtc1	$t1,$f10
/*  f142164:	44819000 */ 	mtc1	$at,$f18
/*  f142168:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f14216c:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f142170:	46128503 */ 	div.s	$f20,$f16,$f18
/*  f142174:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f142178:	44183000 */ 	mfc1	$t8,$f6
/*  f14217c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142180:	02f8c823 */ 	subu	$t9,$s7,$t8
/*  f142184:	44994000 */ 	mtc1	$t9,$f8
/*  f142188:	0c012e84 */ 	jal	sqrtf
/*  f14218c:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f142190:	46140102 */ 	mul.s	$f4,$f0,$f20
/*  f142194:	8fa800c8 */ 	lw	$t0,0xc8($sp)
/*  f142198:	8fab00dc */ 	lw	$t3,0xdc($sp)
/*  f14219c:	8fac00d4 */ 	lw	$t4,0xd4($sp)
/*  f1421a0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1421a4:	03c02825 */ 	or	$a1,$s8,$zero
/*  f1421a8:	02003025 */ 	or	$a2,$s0,$zero
/*  f1421ac:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f1421b0:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f1421b4:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f1421b8:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*  f1421bc:	44023000 */ 	mfc1	$v0,$f6
/*  f1421c0:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f1421c4:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f1421c8:	01029821 */ 	addu	$s3,$t0,$v0
/*  f1421cc:	0173a023 */ 	subu	$s4,$t3,$s3
/*  f1421d0:	0fc4f168 */ 	jal	bviewRenderLensRect
/*  f1421d4:	00409025 */ 	or	$s2,$v0,$zero
/*  f1421d8:	00402025 */ 	or	$a0,$v0,$zero
/*  f1421dc:	03c02825 */ 	or	$a1,$s8,$zero
/*  f1421e0:	02003025 */ 	or	$a2,$s0,$zero
/*  f1421e4:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f1421e8:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f1421ec:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*  f1421f0:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f1421f4:	0fc4f168 */ 	jal	bviewRenderLensRect
/*  f1421f8:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f1421fc:	3c0dee00 */ 	lui	$t5,0xee00
/*  f142200:	35ad00ff */ 	ori	$t5,$t5,0xff
/*  f142204:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f142208:	ac560000 */ 	sw	$s6,0x0($v0)
/*  f14220c:	8fae00c8 */ 	lw	$t6,0xc8($sp)
/*  f142210:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f142214:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*  f142218:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f14221c:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f142220:	03c02825 */ 	or	$a1,$s8,$zero
/*  f142224:	02003025 */ 	or	$a2,$s0,$zero
/*  f142228:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f14222c:	0fc4f168 */ 	jal	bviewRenderLensRect
/*  f142230:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f142234:	1000000a */ 	beqz	$zero,.NB0f142260
/*  f142238:	0040a825 */ 	or	$s5,$v0,$zero
/*  f14223c:	8faf00d4 */ 	lw	$t7,0xd4($sp)
.NB0f142240:
/*  f142240:	8fb800dc */ 	lw	$t8,0xdc($sp)
/*  f142244:	02a02025 */ 	or	$a0,$s5,$zero
/*  f142248:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f14224c:	e7b60014 */ 	swc1	$f22,0x14($sp)
/*  f142250:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f142254:	0fc4f168 */ 	jal	bviewRenderLensRect
/*  f142258:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f14225c:	0040a825 */ 	or	$s5,$v0,$zero
.NB0f142260:
/*  f142260:	8fa400e8 */ 	lw	$a0,0xe8($sp)
/*  f142264:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f142268:	0082082a */ 	slt	$at,$a0,$v0
/*  f14226c:	10200002 */ 	beqz	$at,.NB0f142278
/*  f142270:	0044c823 */ 	subu	$t9,$v0,$a0
/*  f142274:	a2390000 */ 	sb	$t9,0x0($s1)
.NB0f142278:
/*  f142278:	8fa900ac */ 	lw	$t1,0xac($sp)
/*  f14227c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f142280:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f142284:	5609ff8f */ 	bnel	$s0,$t1,.NB0f1420c4
/*  f142288:	32180001 */ 	andi	$t8,$s0,0x1
.NB0f14228c:
/*  f14228c:	3c0a800a */ 	lui	$t2,0x800a
/*  f142290:	8d4ae948 */ 	lw	$t2,-0x16b8($t2)
/*  f142294:	3c0d800a */ 	lui	$t5,0x800a
/*  f142298:	02a02025 */ 	or	$a0,$s5,$zero
/*  f14229c:	8d4b0070 */ 	lw	$t3,0x70($t2)
/*  f1422a0:	3c05ff00 */ 	lui	$a1,0xff00
/*  f1422a4:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f1422a8:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f1422ac:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f1422b0:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f1422b4:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f1422b8:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f1422bc:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f1422c0:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f1422c4:	8dad2c48 */ 	lw	$t5,0x2c48($t5)
/*  f1422c8:	55a00005 */ 	bnezl	$t5,.NB0f1422e0
/*  f1422cc:	02a01025 */ 	or	$v0,$s5,$zero
/*  f1422d0:	0fc4f3ca */ 	jal	bviewRenderMotionBlur
/*  f1422d4:	24060040 */ 	addiu	$a2,$zero,0x40
/*  f1422d8:	0040a825 */ 	or	$s5,$v0,$zero
/*  f1422dc:	02a01025 */ 	or	$v0,$s5,$zero
.NB0f1422e0:
/*  f1422e0:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f1422e4:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f1422e8:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f1422ec:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1422f0:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f1422f4:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f1422f8:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f1422fc:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f142300:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f142304:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f142308:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f14230c:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f142310:	03e00008 */ 	jr	$ra
/*  f142314:	27bd00f0 */ 	addiu	$sp,$sp,0xf0
/*  f142318:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f14231c:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f142320:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f142324:	00809025 */ 	or	$s2,$a0,$zero
/*  f142328:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f14232c:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f142330:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f142334:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f142338:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f14233c:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f142340:	f7be0050 */ 	sdc1	$f30,0x50($sp)
/*  f142344:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f142348:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f14234c:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f142350:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f142354:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f142358:	0c002b27 */ 	jal	viGetUnk28
/*  f14235c:	afa5008c */ 	sw	$a1,0x8c($sp)
/*  f142360:	0c002fb9 */ 	jal	viGetViewTop
/*  f142364:	0040b025 */ 	or	$s6,$v0,$zero
/*  f142368:	0c002f9b */ 	jal	viGetViewHeight
/*  f14236c:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f142370:	0c002f97 */ 	jal	viGetViewWidth
/*  f142374:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f142378:	0c002fb5 */ 	jal	viGetViewLeft
/*  f14237c:	0040a025 */ 	or	$s4,$v0,$zero
/*  f142380:	3c038008 */ 	lui	$v1,0x8008
/*  f142384:	246320a0 */ 	addiu	$v1,$v1,0x20a0
/*  f142388:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f14238c:	0040a825 */ 	or	$s5,$v0,$zero
/*  f142390:	3c04800b */ 	lui	$a0,0x800b
/*  f142394:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f142398:	29e10002 */ 	slti	$at,$t7,0x2
/*  f14239c:	14200003 */ 	bnez	$at,.NB0f1423ac
/*  f1423a0:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f1423a4:	1000004b */ 	beqz	$zero,.NB0f1424d4
/*  f1423a8:	02401025 */ 	or	$v0,$s2,$zero
.NB0f1423ac:
/*  f1423ac:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1423b0:	24a503f0 */ 	addiu	$a1,$a1,0x3f0
/*  f1423b4:	0c004e60 */ 	jal	strcpy
/*  f1423b8:	24848780 */ 	addiu	$a0,$a0,-30848
/*  f1423bc:	3c19e700 */ 	lui	$t9,0xe700
/*  f1423c0:	ae590000 */ 	sw	$t9,0x0($s2)
/*  f1423c4:	26440008 */ 	addiu	$a0,$s2,0x8
/*  f1423c8:	ae400004 */ 	sw	$zero,0x4($s2)
/*  f1423cc:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f1423d0:	0fc4f2e8 */ 	jal	bviewPrepareStaticRgba16
/*  f1423d4:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f1423d8:	8fa30080 */ 	lw	$v1,0x80($sp)
/*  f1423dc:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f1423e0:	00409025 */ 	or	$s2,$v0,$zero
/*  f1423e4:	00608025 */ 	or	$s0,$v1,$zero
/*  f1423e8:	00649821 */ 	addu	$s3,$v1,$a0
/*  f1423ec:	0073082a */ 	slt	$at,$v1,$s3
/*  f1423f0:	10200037 */ 	beqz	$at,.NB0f1424d0
/*  f1423f4:	00638823 */ 	subu	$s1,$v1,$v1
/*  f1423f8:	44842000 */ 	mtc1	$a0,$f4
/*  f1423fc:	3c013f00 */ 	lui	$at,0x3f00
/*  f142400:	44814000 */ 	mtc1	$at,$f8
/*  f142404:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f142408:	44815000 */ 	mtc1	$at,$f10
/*  f14240c:	44818000 */ 	mtc1	$at,$f16
/*  f142410:	3c012f80 */ 	lui	$at,0x2f80
/*  f142414:	4481f000 */ 	mtc1	$at,$f30
/*  f142418:	3c013f80 */ 	lui	$at,0x3f80
/*  f14241c:	4481b000 */ 	mtc1	$at,$f22
/*  f142420:	4480e000 */ 	mtc1	$zero,$f28
/*  f142424:	46083602 */ 	mul.s	$f24,$f6,$f8
/*  f142428:	46105680 */ 	add.s	$f26,$f10,$f16
.NB0f14242c:
/*  f14242c:	44919000 */ 	mtc1	$s1,$f18
/*  f142430:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142434:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f142438:	46182181 */ 	sub.s	$f6,$f4,$f24
/*  f14243c:	46183003 */ 	div.s	$f0,$f6,$f24
/*  f142440:	461c003c */ 	c.lt.s	$f0,$f28
/*  f142444:	46000506 */ 	mov.s	$f20,$f0
/*  f142448:	45020003 */ 	bc1fl	.NB0f142458
/*  f14244c:	461aa500 */ 	add.s	$f20,$f20,$f26
/*  f142450:	46000507 */ 	neg.s	$f20,$f0
/*  f142454:	461aa500 */ 	add.s	$f20,$f20,$f26
.NB0f142458:
/*  f142458:	4614b03c */ 	c.lt.s	$f22,$f20
/*  f14245c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142460:	45000002 */ 	bc1f	.NB0f14246c
/*  f142464:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142468:	4600b506 */ 	mov.s	$f20,$f22
.NB0f14246c:
/*  f14246c:	0c004d84 */ 	jal	random
/*  f142470:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142474:	44824000 */ 	mtc1	$v0,$f8
/*  f142478:	02402025 */ 	or	$a0,$s2,$zero
/*  f14247c:	02c02825 */ 	or	$a1,$s6,$zero
/*  f142480:	02003025 */ 	or	$a2,$s0,$zero
/*  f142484:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f142488:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f14248c:	04410005 */ 	bgez	$v0,.NB0f1424a4
/*  f142490:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f142494:	3c014f80 */ 	lui	$at,0x4f80
/*  f142498:	44818000 */ 	mtc1	$at,$f16
/*  f14249c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1424a0:	46105280 */ 	add.s	$f10,$f10,$f16
.NB0f1424a4:
/*  f1424a4:	461e5482 */ 	mul.s	$f18,$f10,$f30
/*  f1424a8:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f1424ac:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f1424b0:	46149102 */ 	mul.s	$f4,$f18,$f20
/*  f1424b4:	46162180 */ 	add.s	$f6,$f4,$f22
/*  f1424b8:	0fc4f168 */ 	jal	bviewRenderLensRect
/*  f1424bc:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f1424c0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1424c4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1424c8:	1613ffd8 */ 	bne	$s0,$s3,.NB0f14242c
/*  f1424cc:	00409025 */ 	or	$s2,$v0,$zero
.NB0f1424d0:
/*  f1424d0:	02401025 */ 	or	$v0,$s2,$zero
.NB0f1424d4:
/*  f1424d4:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f1424d8:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f1424dc:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f1424e0:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f1424e4:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f1424e8:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f1424ec:	d7be0050 */ 	ldc1	$f30,0x50($sp)
/*  f1424f0:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f1424f4:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f1424f8:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f1424fc:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f142500:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f142504:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f142508:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f14250c:	03e00008 */ 	jr	$ra
/*  f142510:	27bd0088 */ 	addiu	$sp,$sp,0x88
);
#endif

/**
 * Called from the title screen's "Rare Presents" mode, which is unused.
 */
Gfx *bviewRenderRarePresents(Gfx *gdl)
{
	void *unk28 = viGetUnk28();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewHeight();
	s32 viewwidth = viGetViewWidth();
	s32 viewleft = viGetViewLeft();
	s32 y;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	strcpy(var800a41c0, "IntroTextInterfereGfx");

	gDPPipeSync(gdl++);

	gdl = bviewPrepareStaticRgba16(gdl, 0x8f8f8f8f, 255);

	for (y = viewtop; y < viewtop + viewheight; y += 2) {
		gdl = bviewRenderLensRect(gdl, unk28, y, 5, y, 1.0f, viewleft, viewwidth);
	}

	return gdl;
}

u8 var8007f878 = 0;

#if VERSION >= VERSION_NTSC_1_0
Gfx *bviewRenderHorizonScanner(Gfx *gdl)
{
	void *sp194 = viGetUnk28();
	s32 viewtop = viGetViewTop();
	s32 viewheight = viGetViewHeight();
	s32 viewwidth = viGetViewWidth();
	s32 viewleft = viGetViewLeft();
	char directiontext[32];
	char hertztext[24];
	char zoomtext[24];
	char nametext[52];
	f32 lookx = g_Vars.currentplayer->cam_look.x;
	f32 lookz = g_Vars.currentplayer->cam_look.z;
	s32 x;
	s32 y;

	char directions[][3] = {
		{'n', '\0', '\0'},
		{'n', 'e',  '\0'},
		{'e', '\0', '\0'},
		{'s', 'e',  '\0'},
		{'s', '\0', '\0'},
		{'s', 'w',  '\0'},
		{'w', '\0', '\0'},
		{'n', 'w',  '\0'},
		{'n', '\0', '\0'},
	};

	s32 turnangle = atan2f(-lookx, lookz) * 180.0f / M_PI;
	f32 fovy;
	char arrows[12];
	s32 tmplensheight = 130;
	s32 lenstop;
	s32 lensheight;
	s32 liney;
	s32 scale = 1;
	s32 vsplit = false;
	u32 colour;
	f32 range;

	var8007f840++;

	if (var8007f840 >= 2) {
		return gdl;
	}

	strcpy(var800a41c0, "BinocularViewGfx");

	if (!PAL && g_ViMode == VIMODE_HIRES) {
		scale = 2;
	}

	if (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL && PLAYERCOUNT() >= 2) {
		vsplit = true;
	}

	if (tmplensheight > viewheight - 30) {
		tmplensheight = viewheight - 30;
	}

	if (((s32)(var80061630 * 30.0f) & 1) == 1) {
		sprintf(arrows, ">> ");
	} else {
		sprintf(arrows, " >>");
	}

	lensheight = tmplensheight;
	lenstop = viewtop + (viewheight / 2) - (lensheight / 2);

	// Black out areas above and below lens
	gdl = gfxSetPrimColour(gdl, 0x000000ff);

	gDPFillRectangle(gdl++, viewleft, viewtop, viewleft + viewwidth, lenstop);
	gDPFillRectangle(gdl++, viewleft, lenstop + lensheight, viewleft + viewwidth, viewtop + viewheight);

	gdl = func0f153838(gdl);

	// Prepare text buffers
	sprintf(directiontext, "%s %s:%03d", arrows, &directions[(turnangle + 22) / 45], turnangle);
	sprintf(hertztext, "%s %s%s%4.2fh", arrows, "", "", func0f006b54(4) * 4.6f + 917.4f);

	fovy = viGetFovY();

	if (fovy == 0 || fovy == 60.0f) {
		fovy = 1;
	} else {
		fovy = 60.0f / fovy + 1;
	}

	sprintf(zoomtext, "%s %s%s%4.2fX", arrows, "", "", fovy);

	gdl = func0f153628(gdl);

	// Arrows left of product name
	if (vsplit) {
		x = viewleft + 15 * scale;
	} else {
		x = viewleft + 25 * scale;
	}

	y = lenstop - 7;
	gdl = textRenderProjected(gdl, &x, &y, arrows,
			g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xffffff7f, viGetWidth(), viGetHeight(), 0, 0);

	// Product name
	strcpy(nametext, " JMBC");

	if (!vsplit) {
		strcat(nametext, " WIDE BAND");
	}

	strcat(nametext, " SCANNER\n");

	gdl = textRenderProjected(gdl, &x, &y, nametext,
			g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xffffff7f, viGetWidth(), viGetHeight(), 0, 0);

	// Hertz
	x = viewleft + 75 * scale;
	y = lenstop + lensheight + 1;
	gdl = textRenderProjected(gdl, &x, &y, hertztext,
			g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xffffff7f, viGetWidth(), viGetHeight(), 0, 0);

	// Zoom level
	if (vsplit) {
		x = viewleft + 75 * scale;
		y = lenstop + lensheight + 8;
	} else {
		x = viewleft + 150 * scale;
		y = lenstop + lensheight + 1;
	}

	gdl = textRenderProjected(gdl, &x, &y, zoomtext,
			g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xffffff7f, viGetWidth(), viGetHeight(), 0, 0);

	// Direction
	if (vsplit) {
		x = viewleft + 75 * scale;
		y = lenstop + lensheight + 15;
	} else {
		x = viewleft + 225 * scale;
		y = lenstop + lensheight + 1;
	}

	gdl = textRenderProjected(gdl, &x, &y, directiontext,
			g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xffffff7f, viGetWidth(), viGetHeight(), 0, 0);
	gdl = func0f153780(gdl);

	gDPPipeSync(gdl++);

	gdl = bviewPrepareStaticRgba16(gdl, 0xffffffff, 255);

	if (vsplit) {
		vsplit = 14;
	}

	// Iterate horizontal lines down the lens with a bit extra on top and bottom
	for (liney = lenstop - 9; liney < lenstop + lensheight + vsplit + 9; liney++) {
		if (liney < lenstop + lensheight && liney >= lenstop) {
			// Inside the lens
			if ((liney % 2) == 0) {
				colour = 0x00ffffff;
			} else {
				colour = 0x7fffffff;
			}

			range = (liney - lenstop - lensheight * 0.5f) / (lensheight * 0.5f);

			if (range < 0) {
				range = -range;
			}

			if (range > 1) {
				range = 0;
			}

			range = (range - 0.75f) * 4.0f;

			if (range < 0) {
				range = 0;
			}

			if (range > 0) {
				colour = colourBlend(0x000000ff, colour, range * 255.0f);
			}
		} else {
			// Outside of the lens
			if ((liney % 2) == 0) {
				colour = 0x007f7fff;
			} else {
				colour = 0x7fffffff;
			}

			range = 0;
		}

		// Different coloured lines at 1/4 and 3/4 marks in the lens
		if (liney == lenstop + lensheight / 4 || liney == lenstop + lensheight - lensheight / 4) {
			colour = 0xffffffff;
		}

		gDPSetColor(gdl++, G_SETENVCOLOR, colour);

		gdl = bviewRenderLensRect(gdl, sp194, liney, 5, liney, random() * (1.0f / U32_MAX) * range + 1, viewleft, viewwidth);
	}

	return gdl;
}
#else
const char var7f1b041cnb[] = "BinocularViewGfx";
const char var7f1b0430nb[] = ">> ";
const char var7f1b0434nb[] = " >>";
const char var7f1b0438nb[] = "%s %s:%03d";
const char var7f1b0444nb[] = "%s %s%s%4.2fh";
const char var7f1b0454nb[] = "";
const char var7f1b0458nb[] = "";
const char var7f1b045cnb[] = "%s %s%s%4.2fX";
const char var7f1b046cnb[] = "";
const char var7f1b0470nb[] = "";
const char var7f1b0474nb[] = " JMBC WIDE BAND SCANNER\n";

GLOBAL_ASM(
glabel bviewRenderHorizonScanner
.late_rodata
glabel var7f1b04c0nb
.word 0x40490fdb
glabel var7f1b04c4nb
.word 0x40933333
glabel var7f1b04c8nb
.word 0x4465599a
.text
/*  f142640:	27bdfea0 */ 	addiu	$sp,$sp,-352
/*  f142644:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f142648:	afb2004c */ 	sw	$s2,0x4c($sp)
/*  f14264c:	00809025 */ 	or	$s2,$a0,$zero
/*  f142650:	afb30050 */ 	sw	$s3,0x50($sp)
/*  f142654:	afb10048 */ 	sw	$s1,0x48($sp)
/*  f142658:	afb00044 */ 	sw	$s0,0x44($sp)
/*  f14265c:	f7b60038 */ 	sdc1	$f22,0x38($sp)
/*  f142660:	0c002b27 */ 	jal	viGetUnk28
/*  f142664:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f142668:	0c002fb9 */ 	jal	viGetViewTop
/*  f14266c:	afa2015c */ 	sw	$v0,0x15c($sp)
/*  f142670:	0c002f9b */ 	jal	viGetViewHeight
/*  f142674:	afa20158 */ 	sw	$v0,0x158($sp)
/*  f142678:	0c002f97 */ 	jal	viGetViewWidth
/*  f14267c:	afa20154 */ 	sw	$v0,0x154($sp)
/*  f142680:	0c002fb5 */ 	jal	viGetViewLeft
/*  f142684:	afa20150 */ 	sw	$v0,0x150($sp)
/*  f142688:	3c10800a */ 	lui	$s0,0x800a
/*  f14268c:	2610e6c0 */ 	addiu	$s0,$s0,-6464
/*  f142690:	8e030284 */ 	lw	$v1,0x284($s0)
/*  f142694:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f142698:	3c0f8008 */ 	lui	$t7,0x8008
/*  f14269c:	25ef20e4 */ 	addiu	$t7,$t7,0x20e4
/*  f1426a0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1426a4:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1426a8:	c4601bbc */ 	lwc1	$f0,0x1bbc($v1)
/*  f1426ac:	27ae00d0 */ 	addiu	$t6,$sp,0xd0
/*  f1426b0:	c46e1bc4 */ 	lwc1	$f14,0x1bc4($v1)
/*  f1426b4:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1426b8:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1426bc:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f1426c0:	8de8000c */ 	lw	$t0,0xc($t7)
/*  f1426c4:	adc10008 */ 	sw	$at,0x8($t6)
/*  f1426c8:	8de10010 */ 	lw	$at,0x10($t7)
/*  f1426cc:	adc8000c */ 	sw	$t0,0xc($t6)
/*  f1426d0:	8de80014 */ 	lw	$t0,0x14($t7)
/*  f1426d4:	adc10010 */ 	sw	$at,0x10($t6)
/*  f1426d8:	99e1001a */ 	lwr	$at,0x1a($t7)
/*  f1426dc:	adc80014 */ 	sw	$t0,0x14($t6)
/*  f1426e0:	46000307 */ 	neg.s	$f12,$f0
/*  f1426e4:	0fc251b8 */ 	jal	atan2f
/*  f1426e8:	b9c1001a */ 	swr	$at,0x1a($t6)
/*  f1426ec:	3c014334 */ 	lui	$at,0x4334
/*  f1426f0:	44812000 */ 	mtc1	$at,$f4
/*  f1426f4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f1426f8:	c42804c0 */ 	lwc1	$f8,0x4c0($at)
/*  f1426fc:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f142700:	3c028008 */ 	lui	$v0,0x8008
/*  f142704:	244220a0 */ 	addiu	$v0,$v0,0x20a0
/*  f142708:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f14270c:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f142710:	3c04800b */ 	lui	$a0,0x800b
/*  f142714:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f142718:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f14271c:	29a10002 */ 	slti	$at,$t5,0x2
/*  f142720:	24110082 */ 	addiu	$s1,$zero,0x82
/*  f142724:	afab00a8 */ 	sw	$t3,0xa8($sp)
/*  f142728:	afa000a4 */ 	sw	$zero,0xa4($sp)
/*  f14272c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f142730:	24848780 */ 	addiu	$a0,$a0,-30848
/*  f142734:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f142738:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f14273c:	440a8000 */ 	mfc1	$t2,$f16
/*  f142740:	14200003 */ 	bnez	$at,.NB0f142750
/*  f142744:	afaa00cc */ 	sw	$t2,0xcc($sp)
/*  f142748:	10000234 */ 	beqz	$zero,.NB0f14301c
/*  f14274c:	02401025 */ 	or	$v0,$s2,$zero
.NB0f142750:
/*  f142750:	0c004e60 */ 	jal	strcpy
/*  f142754:	24a5041c */ 	addiu	$a1,$a1,0x41c
/*  f142758:	3c188007 */ 	lui	$t8,0x8007
/*  f14275c:	8f182d88 */ 	lw	$t8,0x2d88($t8)
/*  f142760:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f142764:	16780002 */ 	bne	$s3,$t8,.NB0f142770
/*  f142768:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f14276c:	afae00a8 */ 	sw	$t6,0xa8($sp)
.NB0f142770:
/*  f142770:	0fc53588 */ 	jal	optionsGetScreenSplit
/*  f142774:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142778:	56620020 */ 	bnel	$s3,$v0,.NB0f1427fc
/*  f14277c:	8fa20154 */ 	lw	$v0,0x154($sp)
/*  f142780:	8e0f006c */ 	lw	$t7,0x6c($s0)
/*  f142784:	00002825 */ 	or	$a1,$zero,$zero
/*  f142788:	00001825 */ 	or	$v1,$zero,$zero
/*  f14278c:	11e00003 */ 	beqz	$t7,.NB0f14279c
/*  f142790:	00002025 */ 	or	$a0,$zero,$zero
/*  f142794:	10000001 */ 	beqz	$zero,.NB0f14279c
/*  f142798:	02602825 */ 	or	$a1,$s3,$zero
.NB0f14279c:
/*  f14279c:	8e080068 */ 	lw	$t0,0x68($s0)
/*  f1427a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1427a4:	11000003 */ 	beqz	$t0,.NB0f1427b4
/*  f1427a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1427ac:	10000001 */ 	beqz	$zero,.NB0f1427b4
/*  f1427b0:	02601825 */ 	or	$v1,$s3,$zero
.NB0f1427b4:
/*  f1427b4:	8e090064 */ 	lw	$t1,0x64($s0)
/*  f1427b8:	11200003 */ 	beqz	$t1,.NB0f1427c8
/*  f1427bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1427c0:	10000001 */ 	beqz	$zero,.NB0f1427c8
/*  f1427c4:	02602025 */ 	or	$a0,$s3,$zero
.NB0f1427c8:
/*  f1427c8:	8e0a0070 */ 	lw	$t2,0x70($s0)
/*  f1427cc:	11400003 */ 	beqz	$t2,.NB0f1427dc
/*  f1427d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1427d4:	10000001 */ 	beqz	$zero,.NB0f1427dc
/*  f1427d8:	02601025 */ 	or	$v0,$s3,$zero
.NB0f1427dc:
/*  f1427dc:	00445821 */ 	addu	$t3,$v0,$a0
/*  f1427e0:	01636021 */ 	addu	$t4,$t3,$v1
/*  f1427e4:	01856821 */ 	addu	$t5,$t4,$a1
/*  f1427e8:	29a10002 */ 	slti	$at,$t5,0x2
/*  f1427ec:	54200003 */ 	bnezl	$at,.NB0f1427fc
/*  f1427f0:	8fa20154 */ 	lw	$v0,0x154($sp)
/*  f1427f4:	afb300a4 */ 	sw	$s3,0xa4($sp)
/*  f1427f8:	8fa20154 */ 	lw	$v0,0x154($sp)
.NB0f1427fc:
/*  f1427fc:	2442ffe2 */ 	addiu	$v0,$v0,-30
/*  f142800:	28410082 */ 	slti	$at,$v0,0x82
/*  f142804:	10200002 */ 	beqz	$at,.NB0f142810
/*  f142808:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14280c:	00408825 */ 	or	$s1,$v0,$zero
.NB0f142810:
/*  f142810:	3c018006 */ 	lui	$at,0x8006
/*  f142814:	c4323b40 */ 	lwc1	$f18,0x3b40($at)
/*  f142818:	3c0141f0 */ 	lui	$at,0x41f0
/*  f14281c:	44812000 */ 	mtc1	$at,$f4
/*  f142820:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142824:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f142828:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f14282c:	44184000 */ 	mfc1	$t8,$f8
/*  f142830:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142834:	330e0001 */ 	andi	$t6,$t8,0x1
/*  f142838:	166e0006 */ 	bne	$s3,$t6,.NB0f142854
/*  f14283c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f142840:	24a50430 */ 	addiu	$a1,$a1,0x430
/*  f142844:	0c004fc1 */ 	jal	sprintf
/*  f142848:	27a400bc */ 	addiu	$a0,$sp,0xbc
/*  f14284c:	10000006 */ 	beqz	$zero,.NB0f142868
/*  f142850:	8faf0154 */ 	lw	$t7,0x154($sp)
.NB0f142854:
/*  f142854:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f142858:	24a50434 */ 	addiu	$a1,$a1,0x434
/*  f14285c:	0c004fc1 */ 	jal	sprintf
/*  f142860:	27a400bc */ 	addiu	$a0,$sp,0xbc
/*  f142864:	8faf0154 */ 	lw	$t7,0x154($sp)
.NB0f142868:
/*  f142868:	8fa90158 */ 	lw	$t1,0x158($sp)
/*  f14286c:	afb100b0 */ 	sw	$s1,0xb0($sp)
/*  f142870:	05e10003 */ 	bgez	$t7,.NB0f142880
/*  f142874:	000f4043 */ 	sra	$t0,$t7,0x1
/*  f142878:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f14287c:	00014043 */ 	sra	$t0,$at,0x1
.NB0f142880:
/*  f142880:	01095021 */ 	addu	$t2,$t0,$t1
/*  f142884:	06210003 */ 	bgez	$s1,.NB0f142894
/*  f142888:	00115843 */ 	sra	$t3,$s1,0x1
/*  f14288c:	26210001 */ 	addiu	$at,$s1,0x1
/*  f142890:	00015843 */ 	sra	$t3,$at,0x1
.NB0f142894:
/*  f142894:	014b9823 */ 	subu	$s3,$t2,$t3
/*  f142898:	afb300b4 */ 	sw	$s3,0xb4($sp)
/*  f14289c:	02402025 */ 	or	$a0,$s2,$zero
/*  f1428a0:	0fc537b7 */ 	jal	gfxSetPrimColour
/*  f1428a4:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f1428a8:	8fa7014c */ 	lw	$a3,0x14c($sp)
/*  f1428ac:	8fac0150 */ 	lw	$t4,0x150($sp)
/*  f1428b0:	3c01f600 */ 	lui	$at,0xf600
/*  f1428b4:	326e03ff */ 	andi	$t6,$s3,0x3ff
/*  f1428b8:	00ec1821 */ 	addu	$v1,$a3,$t4
/*  f1428bc:	306d03ff */ 	andi	$t5,$v1,0x3ff
/*  f1428c0:	000dcb80 */ 	sll	$t9,$t5,0xe
/*  f1428c4:	03211825 */ 	or	$v1,$t9,$at
/*  f1428c8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1428cc:	006f4025 */ 	or	$t0,$v1,$t7
/*  f1428d0:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f1428d4:	8faa0158 */ 	lw	$t2,0x158($sp)
/*  f1428d8:	30e503ff */ 	andi	$a1,$a3,0x3ff
/*  f1428dc:	00054b80 */ 	sll	$t1,$a1,0xe
/*  f1428e0:	314b03ff */ 	andi	$t3,$t2,0x3ff
/*  f1428e4:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f1428e8:	012c6825 */ 	or	$t5,$t1,$t4
/*  f1428ec:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f1428f0:	8fb80154 */ 	lw	$t8,0x154($sp)
/*  f1428f4:	8fb90158 */ 	lw	$t9,0x158($sp)
/*  f1428f8:	02713021 */ 	addu	$a2,$s3,$s1
/*  f1428fc:	01202825 */ 	or	$a1,$t1,$zero
/*  f142900:	03387021 */ 	addu	$t6,$t9,$t8
/*  f142904:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f142908:	30ca03ff */ 	andi	$t2,$a2,0x3ff
/*  f14290c:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f142910:	000f4080 */ 	sll	$t0,$t7,0x2
/*  f142914:	00684825 */ 	or	$t1,$v1,$t0
/*  f142918:	00ab6025 */ 	or	$t4,$a1,$t3
/*  f14291c:	ac4c000c */ 	sw	$t4,0xc($v0)
/*  f142920:	ac490008 */ 	sw	$t1,0x8($v0)
/*  f142924:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f142928:	0fc537ce */ 	jal	func0f153838
/*  f14292c:	24440010 */ 	addiu	$a0,$v0,0x10
/*  f142930:	8fa300cc */ 	lw	$v1,0xcc($sp)
/*  f142934:	2401002d */ 	addiu	$at,$zero,0x2d
/*  f142938:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f14293c:	246d0016 */ 	addiu	$t5,$v1,0x16
/*  f142940:	01a1001a */ 	div	$zero,$t5,$at
/*  f142944:	0000c812 */ 	mflo	$t9
/*  f142948:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f14294c:	0319c023 */ 	subu	$t8,$t8,$t9
/*  f142950:	27ae00d0 */ 	addiu	$t6,$sp,0xd0
/*  f142954:	00409025 */ 	or	$s2,$v0,$zero
/*  f142958:	030e3821 */ 	addu	$a3,$t8,$t6
/*  f14295c:	24a50438 */ 	addiu	$a1,$a1,0x438
/*  f142960:	27a4012c */ 	addiu	$a0,$sp,0x12c
/*  f142964:	27a600bc */ 	addiu	$a2,$sp,0xbc
/*  f142968:	0c004fc1 */ 	jal	sprintf
/*  f14296c:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f142970:	3c014080 */ 	lui	$at,0x4080
/*  f142974:	44816000 */ 	mtc1	$at,$f12
/*  f142978:	0fc019fe */ 	jal	func0f006b54
/*  f14297c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142980:	3c017f1b */ 	lui	$at,0x7f1b
/*  f142984:	c42a04c4 */ 	lwc1	$f10,0x4c4($at)
/*  f142988:	3c017f1b */ 	lui	$at,0x7f1b
/*  f14298c:	c43204c8 */ 	lwc1	$f18,0x4c8($at)
/*  f142990:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f142994:	3c0f7f1b */ 	lui	$t7,0x7f1b
/*  f142998:	25ef0458 */ 	addiu	$t7,$t7,0x458
/*  f14299c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1429a0:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f1429a4:	24e70454 */ 	addiu	$a3,$a3,0x454
/*  f1429a8:	24a50444 */ 	addiu	$a1,$a1,0x444
/*  f1429ac:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f1429b0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1429b4:	27a40114 */ 	addiu	$a0,$sp,0x114
/*  f1429b8:	27a600bc */ 	addiu	$a2,$sp,0xbc
/*  f1429bc:	460021a1 */ 	cvt.d.s	$f6,$f4
/*  f1429c0:	0c004fc1 */ 	jal	sprintf
/*  f1429c4:	f7a60018 */ 	sdc1	$f6,0x18($sp)
/*  f1429c8:	0c003012 */ 	jal	viGetFovY
/*  f1429cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1429d0:	4480b000 */ 	mtc1	$zero,$f22
/*  f1429d4:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f1429d8:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f1429dc:	46160032 */ 	c.eq.s	$f0,$f22
/*  f1429e0:	24e7046c */ 	addiu	$a3,$a3,0x46c
/*  f1429e4:	24a5045c */ 	addiu	$a1,$a1,0x45c
/*  f1429e8:	27a400fc */ 	addiu	$a0,$sp,0xfc
/*  f1429ec:	45010007 */ 	bc1t	.NB0f142a0c
/*  f1429f0:	27a600bc */ 	addiu	$a2,$sp,0xbc
/*  f1429f4:	3c014270 */ 	lui	$at,0x4270
/*  f1429f8:	44816000 */ 	mtc1	$at,$f12
/*  f1429fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142a00:	460c0032 */ 	c.eq.s	$f0,$f12
/*  f142a04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142a08:	45000004 */ 	bc1f	.NB0f142a1c
.NB0f142a0c:
/*  f142a0c:	3c013f80 */ 	lui	$at,0x3f80
/*  f142a10:	44811000 */ 	mtc1	$at,$f2
/*  f142a14:	10000006 */ 	beqz	$zero,.NB0f142a30
/*  f142a18:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f142a1c:
/*  f142a1c:	46006203 */ 	div.s	$f8,$f12,$f0
/*  f142a20:	3c013f80 */ 	lui	$at,0x3f80
/*  f142a24:	44815000 */ 	mtc1	$at,$f10
/*  f142a28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142a2c:	460a4080 */ 	add.s	$f2,$f8,$f10
.NB0f142a30:
/*  f142a30:	3c087f1b */ 	lui	$t0,0x7f1b
/*  f142a34:	46001421 */ 	cvt.d.s	$f16,$f2
/*  f142a38:	25080470 */ 	addiu	$t0,$t0,0x470
/*  f142a3c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f142a40:	0c004fc1 */ 	jal	sprintf
/*  f142a44:	f7b00018 */ 	sdc1	$f16,0x18($sp)
/*  f142a48:	0fc5374a */ 	jal	func0f153628
/*  f142a4c:	02402025 */ 	or	$a0,$s2,$zero
/*  f142a50:	8fa900a4 */ 	lw	$t1,0xa4($sp)
/*  f142a54:	00409025 */ 	or	$s2,$v0,$zero
/*  f142a58:	2668fff9 */ 	addiu	$t0,$s3,-7
/*  f142a5c:	51200009 */ 	beqzl	$t1,.NB0f142a84
/*  f142a60:	8fb900a8 */ 	lw	$t9,0xa8($sp)
/*  f142a64:	8faa00a8 */ 	lw	$t2,0xa8($sp)
/*  f142a68:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f142a6c:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f142a70:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f142a74:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f142a78:	10000009 */ 	beqz	$zero,.NB0f142aa0
/*  f142a7c:	afad00f0 */ 	sw	$t5,0xf0($sp)
/*  f142a80:	8fb900a8 */ 	lw	$t9,0xa8($sp)
.NB0f142a84:
/*  f142a84:	8fae014c */ 	lw	$t6,0x14c($sp)
/*  f142a88:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f142a8c:	0319c023 */ 	subu	$t8,$t8,$t9
/*  f142a90:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f142a94:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f142a98:	030e7821 */ 	addu	$t7,$t8,$t6
/*  f142a9c:	afaf00f0 */ 	sw	$t7,0xf0($sp)
.NB0f142aa0:
/*  f142aa0:	0c002f77 */ 	jal	viGetWidth
/*  f142aa4:	afa800ec */ 	sw	$t0,0xec($sp)
/*  f142aa8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f142aac:	00104c03 */ 	sra	$t1,$s0,0x10
/*  f142ab0:	0c002f7b */ 	jal	viGetHeight
/*  f142ab4:	01208025 */ 	or	$s0,$t1,$zero
/*  f142ab8:	3c0a8008 */ 	lui	$t2,0x8008
/*  f142abc:	3c0b8008 */ 	lui	$t3,0x8008
/*  f142ac0:	8d6b2364 */ 	lw	$t3,0x2364($t3)
/*  f142ac4:	8d4a2368 */ 	lw	$t2,0x2368($t2)
/*  f142ac8:	240cff7f */ 	addiu	$t4,$zero,-129
/*  f142acc:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f142ad0:	02402025 */ 	or	$a0,$s2,$zero
/*  f142ad4:	27a500f0 */ 	addiu	$a1,$sp,0xf0
/*  f142ad8:	27a600ec */ 	addiu	$a2,$sp,0xec
/*  f142adc:	27a700bc */ 	addiu	$a3,$sp,0xbc
/*  f142ae0:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f142ae4:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f142ae8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f142aec:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f142af0:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f142af4:	0fc541a6 */ 	jal	textRenderProjected
/*  f142af8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f142afc:	0c002f77 */ 	jal	viGetWidth
/*  f142b00:	00409025 */ 	or	$s2,$v0,$zero
/*  f142b04:	00028400 */ 	sll	$s0,$v0,0x10
/*  f142b08:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f142b0c:	0c002f7b */ 	jal	viGetHeight
/*  f142b10:	01a08025 */ 	or	$s0,$t5,$zero
/*  f142b14:	3c198008 */ 	lui	$t9,0x8008
/*  f142b18:	3c188008 */ 	lui	$t8,0x8008
/*  f142b1c:	8f182364 */ 	lw	$t8,0x2364($t8)
/*  f142b20:	8f392368 */ 	lw	$t9,0x2368($t9)
/*  f142b24:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f142b28:	240eff7f */ 	addiu	$t6,$zero,-129
/*  f142b2c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f142b30:	24e70474 */ 	addiu	$a3,$a3,0x474
/*  f142b34:	02402025 */ 	or	$a0,$s2,$zero
/*  f142b38:	27a500f0 */ 	addiu	$a1,$sp,0xf0
/*  f142b3c:	27a600ec */ 	addiu	$a2,$sp,0xec
/*  f142b40:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f142b44:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f142b48:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f142b4c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f142b50:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f142b54:	0fc541a6 */ 	jal	textRenderProjected
/*  f142b58:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f142b5c:	8faf00a8 */ 	lw	$t7,0xa8($sp)
/*  f142b60:	8fa9014c */ 	lw	$t1,0x14c($sp)
/*  f142b64:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f142b68:	000f4080 */ 	sll	$t0,$t7,0x2
/*  f142b6c:	010f4021 */ 	addu	$t0,$t0,$t7
/*  f142b70:	00084080 */ 	sll	$t0,$t0,0x2
/*  f142b74:	010f4023 */ 	subu	$t0,$t0,$t7
/*  f142b78:	00084080 */ 	sll	$t0,$t0,0x2
/*  f142b7c:	010f4023 */ 	subu	$t0,$t0,$t7
/*  f142b80:	01091821 */ 	addu	$v1,$t0,$t1
/*  f142b84:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f142b88:	00409025 */ 	or	$s2,$v0,$zero
/*  f142b8c:	afa300f0 */ 	sw	$v1,0xf0($sp)
/*  f142b90:	afa400ec */ 	sw	$a0,0xec($sp)
/*  f142b94:	afa40064 */ 	sw	$a0,0x64($sp)
/*  f142b98:	0c002f77 */ 	jal	viGetWidth
/*  f142b9c:	afa3006c */ 	sw	$v1,0x6c($sp)
/*  f142ba0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f142ba4:	00105403 */ 	sra	$t2,$s0,0x10
/*  f142ba8:	0c002f7b */ 	jal	viGetHeight
/*  f142bac:	01408025 */ 	or	$s0,$t2,$zero
/*  f142bb0:	3c0b8008 */ 	lui	$t3,0x8008
/*  f142bb4:	3c0c8008 */ 	lui	$t4,0x8008
/*  f142bb8:	8d8c2364 */ 	lw	$t4,0x2364($t4)
/*  f142bbc:	8d6b2368 */ 	lw	$t3,0x2368($t3)
/*  f142bc0:	240dff7f */ 	addiu	$t5,$zero,-129
/*  f142bc4:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f142bc8:	02402025 */ 	or	$a0,$s2,$zero
/*  f142bcc:	27a500f0 */ 	addiu	$a1,$sp,0xf0
/*  f142bd0:	27a600ec */ 	addiu	$a2,$sp,0xec
/*  f142bd4:	27a70114 */ 	addiu	$a3,$sp,0x114
/*  f142bd8:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f142bdc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f142be0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f142be4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f142be8:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f142bec:	0fc541a6 */ 	jal	textRenderProjected
/*  f142bf0:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f142bf4:	8fb900a4 */ 	lw	$t9,0xa4($sp)
/*  f142bf8:	00409025 */ 	or	$s2,$v0,$zero
/*  f142bfc:	53200008 */ 	beqzl	$t9,.NB0f142c20
/*  f142c00:	8fa800a8 */ 	lw	$t0,0xa8($sp)
/*  f142c04:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f142c08:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f142c0c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f142c10:	afaf00ec */ 	sw	$t7,0xec($sp)
/*  f142c14:	1000000e */ 	beqz	$zero,.NB0f142c50
/*  f142c18:	afb800f0 */ 	sw	$t8,0xf0($sp)
/*  f142c1c:	8fa800a8 */ 	lw	$t0,0xa8($sp)
.NB0f142c20:
/*  f142c20:	8faa014c */ 	lw	$t2,0x14c($sp)
/*  f142c24:	8fac0064 */ 	lw	$t4,0x64($sp)
/*  f142c28:	00084880 */ 	sll	$t1,$t0,0x2
/*  f142c2c:	01284821 */ 	addu	$t1,$t1,$t0
/*  f142c30:	00094880 */ 	sll	$t1,$t1,0x2
/*  f142c34:	01284823 */ 	subu	$t1,$t1,$t0
/*  f142c38:	00094880 */ 	sll	$t1,$t1,0x2
/*  f142c3c:	01284823 */ 	subu	$t1,$t1,$t0
/*  f142c40:	00094840 */ 	sll	$t1,$t1,0x1
/*  f142c44:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f142c48:	afab00f0 */ 	sw	$t3,0xf0($sp)
/*  f142c4c:	afac00ec */ 	sw	$t4,0xec($sp)
.NB0f142c50:
/*  f142c50:	0c002f77 */ 	jal	viGetWidth
/*  f142c54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142c58:	00028400 */ 	sll	$s0,$v0,0x10
/*  f142c5c:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f142c60:	0c002f7b */ 	jal	viGetHeight
/*  f142c64:	01a08025 */ 	or	$s0,$t5,$zero
/*  f142c68:	3c198008 */ 	lui	$t9,0x8008
/*  f142c6c:	3c188008 */ 	lui	$t8,0x8008
/*  f142c70:	8f182364 */ 	lw	$t8,0x2364($t8)
/*  f142c74:	8f392368 */ 	lw	$t9,0x2368($t9)
/*  f142c78:	240eff7f */ 	addiu	$t6,$zero,-129
/*  f142c7c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f142c80:	02402025 */ 	or	$a0,$s2,$zero
/*  f142c84:	27a500f0 */ 	addiu	$a1,$sp,0xf0
/*  f142c88:	27a600ec */ 	addiu	$a2,$sp,0xec
/*  f142c8c:	27a700fc */ 	addiu	$a3,$sp,0xfc
/*  f142c90:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f142c94:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f142c98:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f142c9c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f142ca0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f142ca4:	0fc541a6 */ 	jal	textRenderProjected
/*  f142ca8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f142cac:	8faf00a4 */ 	lw	$t7,0xa4($sp)
/*  f142cb0:	8fab00a8 */ 	lw	$t3,0xa8($sp)
/*  f142cb4:	00409025 */ 	or	$s2,$v0,$zero
/*  f142cb8:	11e00007 */ 	beqz	$t7,.NB0f142cd8
/*  f142cbc:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f142cc0:	8fa90068 */ 	lw	$t1,0x68($sp)
/*  f142cc4:	8fa8006c */ 	lw	$t0,0x6c($sp)
/*  f142cc8:	252a000f */ 	addiu	$t2,$t1,0xf
/*  f142ccc:	afaa00ec */ 	sw	$t2,0xec($sp)
/*  f142cd0:	10000009 */ 	beqz	$zero,.NB0f142cf8
/*  f142cd4:	afa800f0 */ 	sw	$t0,0xf0($sp)
.NB0f142cd8:
/*  f142cd8:	8fad014c */ 	lw	$t5,0x14c($sp)
/*  f142cdc:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f142ce0:	8fb80064 */ 	lw	$t8,0x64($sp)
/*  f142ce4:	000c6140 */ 	sll	$t4,$t4,0x5
/*  f142ce8:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f142cec:	018dc821 */ 	addu	$t9,$t4,$t5
/*  f142cf0:	afb900f0 */ 	sw	$t9,0xf0($sp)
/*  f142cf4:	afb800ec */ 	sw	$t8,0xec($sp)
.NB0f142cf8:
/*  f142cf8:	0c002f77 */ 	jal	viGetWidth
/*  f142cfc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142d00:	00028400 */ 	sll	$s0,$v0,0x10
/*  f142d04:	00107403 */ 	sra	$t6,$s0,0x10
/*  f142d08:	0c002f7b */ 	jal	viGetHeight
/*  f142d0c:	01c08025 */ 	or	$s0,$t6,$zero
/*  f142d10:	3c0f8008 */ 	lui	$t7,0x8008
/*  f142d14:	3c088008 */ 	lui	$t0,0x8008
/*  f142d18:	8d082364 */ 	lw	$t0,0x2364($t0)
/*  f142d1c:	8def2368 */ 	lw	$t7,0x2368($t7)
/*  f142d20:	2409ff7f */ 	addiu	$t1,$zero,-129
/*  f142d24:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f142d28:	02402025 */ 	or	$a0,$s2,$zero
/*  f142d2c:	27a500f0 */ 	addiu	$a1,$sp,0xf0
/*  f142d30:	27a600ec */ 	addiu	$a2,$sp,0xec
/*  f142d34:	27a7012c */ 	addiu	$a3,$sp,0x12c
/*  f142d38:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f142d3c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f142d40:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f142d44:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f142d48:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f142d4c:	0fc541a6 */ 	jal	textRenderProjected
/*  f142d50:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f142d54:	0fc537a0 */ 	jal	func0f153780
/*  f142d58:	00402025 */ 	or	$a0,$v0,$zero
/*  f142d5c:	3c0ae700 */ 	lui	$t2,0xe700
/*  f142d60:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f142d64:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f142d68:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f142d6c:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f142d70:	0fc4f2e8 */ 	jal	bviewPrepareStaticRgba16
/*  f142d74:	240600ff */ 	addiu	$a2,$zero,0xff
/*  f142d78:	8fab00a4 */ 	lw	$t3,0xa4($sp)
/*  f142d7c:	00409025 */ 	or	$s2,$v0,$zero
/*  f142d80:	2404000e */ 	addiu	$a0,$zero,0xe
/*  f142d84:	51600003 */ 	beqzl	$t3,.NB0f142d94
/*  f142d88:	8fa30068 */ 	lw	$v1,0x68($sp)
/*  f142d8c:	afa400a4 */ 	sw	$a0,0xa4($sp)
/*  f142d90:	8fa30068 */ 	lw	$v1,0x68($sp)
.NB0f142d94:
/*  f142d94:	8fa400a4 */ 	lw	$a0,0xa4($sp)
/*  f142d98:	2670fff7 */ 	addiu	$s0,$s3,-9
/*  f142d9c:	8fb900b4 */ 	lw	$t9,0xb4($sp)
/*  f142da0:	00646021 */ 	addu	$t4,$v1,$a0
/*  f142da4:	258d0009 */ 	addiu	$t5,$t4,0x9
/*  f142da8:	020d082a */ 	slt	$at,$s0,$t5
/*  f142dac:	1020009a */ 	beqz	$at,.NB0f143018
/*  f142db0:	8fb800b0 */ 	lw	$t8,0xb0($sp)
/*  f142db4:	03387021 */ 	addu	$t6,$t9,$t8
/*  f142db8:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f142dbc:	25e80009 */ 	addiu	$t0,$t7,0x9
/*  f142dc0:	afa8006c */ 	sw	$t0,0x6c($sp)
/*  f142dc4:	06210003 */ 	bgez	$s1,.NB0f142dd4
/*  f142dc8:	00114883 */ 	sra	$t1,$s1,0x2
/*  f142dcc:	26210003 */ 	addiu	$at,$s1,0x3
/*  f142dd0:	00014883 */ 	sra	$t1,$at,0x2
.NB0f142dd4:
/*  f142dd4:	01335821 */ 	addu	$t3,$t1,$s3
/*  f142dd8:	afab0060 */ 	sw	$t3,0x60($sp)
/*  f142ddc:	afa90064 */ 	sw	$t1,0x64($sp)
/*  f142de0:	8fa30068 */ 	lw	$v1,0x68($sp)
.NB0f142de4:
/*  f142de4:	32180001 */ 	andi	$t8,$s0,0x1
/*  f142de8:	0203082a */ 	slt	$at,$s0,$v1
/*  f142dec:	10200058 */ 	beqz	$at,.NB0f142f50
/*  f142df0:	0213082a */ 	slt	$at,$s0,$s3
/*  f142df4:	14200056 */ 	bnez	$at,.NB0f142f50
/*  f142df8:	02136823 */ 	subu	$t5,$s0,$s3
/*  f142dfc:	44919000 */ 	mtc1	$s1,$f18
/*  f142e00:	3c013f00 */ 	lui	$at,0x3f00
/*  f142e04:	44813000 */ 	mtc1	$at,$f6
/*  f142e08:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f142e0c:	448d4000 */ 	mtc1	$t5,$f8
/*  f142e10:	3c013f80 */ 	lui	$at,0x3f80
/*  f142e14:	320c0001 */ 	andi	$t4,$s0,0x1
/*  f142e18:	44819000 */ 	mtc1	$at,$f18
/*  f142e1c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f142e20:	46062082 */ 	mul.s	$f2,$f4,$f6
/*  f142e24:	15800003 */ 	bnez	$t4,.NB0f142e34
/*  f142e28:	3c0500ff */ 	lui	$a1,0xff
/*  f142e2c:	10000003 */ 	beqz	$zero,.NB0f142e3c
/*  f142e30:	34a5ffff */ 	ori	$a1,$a1,0xffff
.NB0f142e34:
/*  f142e34:	3c057fff */ 	lui	$a1,0x7fff
/*  f142e38:	34a5ffff */ 	ori	$a1,$a1,0xffff
.NB0f142e3c:
/*  f142e3c:	46025401 */ 	sub.s	$f16,$f10,$f2
/*  f142e40:	3c013f40 */ 	lui	$at,0x3f40
/*  f142e44:	44812000 */ 	mtc1	$at,$f4
/*  f142e48:	3c014080 */ 	lui	$at,0x4080
/*  f142e4c:	46028003 */ 	div.s	$f0,$f16,$f2
/*  f142e50:	4616003c */ 	c.lt.s	$f0,$f22
/*  f142e54:	46000506 */ 	mov.s	$f20,$f0
/*  f142e58:	45020003 */ 	bc1fl	.NB0f142e68
/*  f142e5c:	4614903c */ 	c.lt.s	$f18,$f20
/*  f142e60:	46000507 */ 	neg.s	$f20,$f0
/*  f142e64:	4614903c */ 	c.lt.s	$f18,$f20
.NB0f142e68:
/*  f142e68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142e6c:	45020003 */ 	bc1fl	.NB0f142e7c
/*  f142e70:	4604a181 */ 	sub.s	$f6,$f20,$f4
/*  f142e74:	4600b506 */ 	mov.s	$f20,$f22
/*  f142e78:	4604a181 */ 	sub.s	$f6,$f20,$f4
.NB0f142e7c:
/*  f142e7c:	44814000 */ 	mtc1	$at,$f8
/*  f142e80:	3c01437f */ 	lui	$at,0x437f
/*  f142e84:	46083502 */ 	mul.s	$f20,$f6,$f8
/*  f142e88:	4616a03c */ 	c.lt.s	$f20,$f22
/*  f142e8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142e90:	45020003 */ 	bc1fl	.NB0f142ea0
/*  f142e94:	4614b03c */ 	c.lt.s	$f22,$f20
/*  f142e98:	4600b506 */ 	mov.s	$f20,$f22
/*  f142e9c:	4614b03c */ 	c.lt.s	$f22,$f20
.NB0f142ea0:
/*  f142ea0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142ea4:	45020032 */ 	bc1fl	.NB0f142f70
/*  f142ea8:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f142eac:	44815000 */ 	mtc1	$at,$f10
/*  f142eb0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f142eb4:	3c014f00 */ 	lui	$at,0x4f00
/*  f142eb8:	460aa402 */ 	mul.s	$f16,$f20,$f10
/*  f142ebc:	240400ff */ 	addiu	$a0,$zero,0xff
/*  f142ec0:	4459f800 */ 	cfc1	$t9,$31
/*  f142ec4:	44c6f800 */ 	ctc1	$a2,$31
/*  f142ec8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142ecc:	460084a4 */ 	cvt.w.s	$f18,$f16
/*  f142ed0:	4446f800 */ 	cfc1	$a2,$31
/*  f142ed4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142ed8:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f142edc:	50c00013 */ 	beqzl	$a2,.NB0f142f2c
/*  f142ee0:	44069000 */ 	mfc1	$a2,$f18
/*  f142ee4:	44819000 */ 	mtc1	$at,$f18
/*  f142ee8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f142eec:	46128481 */ 	sub.s	$f18,$f16,$f18
/*  f142ef0:	44c6f800 */ 	ctc1	$a2,$31
/*  f142ef4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142ef8:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f142efc:	4446f800 */ 	cfc1	$a2,$31
/*  f142f00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142f04:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f142f08:	14c00005 */ 	bnez	$a2,.NB0f142f20
/*  f142f0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142f10:	44069000 */ 	mfc1	$a2,$f18
/*  f142f14:	3c018000 */ 	lui	$at,0x8000
/*  f142f18:	10000007 */ 	beqz	$zero,.NB0f142f38
/*  f142f1c:	00c13025 */ 	or	$a2,$a2,$at
.NB0f142f20:
/*  f142f20:	10000005 */ 	beqz	$zero,.NB0f142f38
/*  f142f24:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f142f28:	44069000 */ 	mfc1	$a2,$f18
.NB0f142f2c:
/*  f142f2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142f30:	04c0fffb */ 	bltz	$a2,.NB0f142f20
/*  f142f34:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f142f38:
/*  f142f38:	44d9f800 */ 	ctc1	$t9,$31
/*  f142f3c:	0fc01990 */ 	jal	colourBlend
/*  f142f40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142f44:	00402825 */ 	or	$a1,$v0,$zero
/*  f142f48:	10000008 */ 	beqz	$zero,.NB0f142f6c
/*  f142f4c:	8fa30068 */ 	lw	$v1,0x68($sp)
.NB0f142f50:
/*  f142f50:	17000004 */ 	bnez	$t8,.NB0f142f64
/*  f142f54:	4600b506 */ 	mov.s	$f20,$f22
/*  f142f58:	3c05007f */ 	lui	$a1,0x7f
/*  f142f5c:	10000003 */ 	beqz	$zero,.NB0f142f6c
/*  f142f60:	34a57fff */ 	ori	$a1,$a1,0x7fff
.NB0f142f64:
/*  f142f64:	3c057fff */ 	lui	$a1,0x7fff
/*  f142f68:	34a5ffff */ 	ori	$a1,$a1,0xffff
.NB0f142f6c:
/*  f142f6c:	8fae0060 */ 	lw	$t6,0x60($sp)
.NB0f142f70:
/*  f142f70:	02401025 */ 	or	$v0,$s2,$zero
/*  f142f74:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f142f78:	120e0005 */ 	beq	$s0,$t6,.NB0f142f90
/*  f142f7c:	3c09fb00 */ 	lui	$t1,0xfb00
/*  f142f80:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f142f84:	006f4023 */ 	subu	$t0,$v1,$t7
/*  f142f88:	56080003 */ 	bnel	$s0,$t0,.NB0f142f98
/*  f142f8c:	ac490000 */ 	sw	$t1,0x0($v0)
.NB0f142f90:
/*  f142f90:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f142f94:	ac490000 */ 	sw	$t1,0x0($v0)
.NB0f142f98:
/*  f142f98:	0c004d84 */ 	jal	random
/*  f142f9c:	ac450004 */ 	sw	$a1,0x4($v0)
/*  f142fa0:	44822000 */ 	mtc1	$v0,$f4
/*  f142fa4:	02402025 */ 	or	$a0,$s2,$zero
/*  f142fa8:	8fa5015c */ 	lw	$a1,0x15c($sp)
/*  f142fac:	02003025 */ 	or	$a2,$s0,$zero
/*  f142fb0:	24070005 */ 	addiu	$a3,$zero,0x5
/*  f142fb4:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f142fb8:	04410005 */ 	bgez	$v0,.NB0f142fd0
/*  f142fbc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f142fc0:	3c014f80 */ 	lui	$at,0x4f80
/*  f142fc4:	44814000 */ 	mtc1	$at,$f8
/*  f142fc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f142fcc:	46083180 */ 	add.s	$f6,$f6,$f8
.NB0f142fd0:
/*  f142fd0:	3c012f80 */ 	lui	$at,0x2f80
/*  f142fd4:	44815000 */ 	mtc1	$at,$f10
/*  f142fd8:	3c013f80 */ 	lui	$at,0x3f80
/*  f142fdc:	44812000 */ 	mtc1	$at,$f4
/*  f142fe0:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f142fe4:	8faa014c */ 	lw	$t2,0x14c($sp)
/*  f142fe8:	8fab0150 */ 	lw	$t3,0x150($sp)
/*  f142fec:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f142ff0:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f142ff4:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f142ff8:	46049200 */ 	add.s	$f8,$f18,$f4
/*  f142ffc:	0fc4f168 */ 	jal	bviewRenderLensRect
/*  f143000:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f143004:	8fac006c */ 	lw	$t4,0x6c($sp)
/*  f143008:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f14300c:	00409025 */ 	or	$s2,$v0,$zero
/*  f143010:	560cff74 */ 	bnel	$s0,$t4,.NB0f142de4
/*  f143014:	8fa30068 */ 	lw	$v1,0x68($sp)
.NB0f143018:
/*  f143018:	02401025 */ 	or	$v0,$s2,$zero
.NB0f14301c:
/*  f14301c:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f143020:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f143024:	d7b60038 */ 	ldc1	$f22,0x38($sp)
/*  f143028:	8fb00044 */ 	lw	$s0,0x44($sp)
/*  f14302c:	8fb10048 */ 	lw	$s1,0x48($sp)
/*  f143030:	8fb2004c */ 	lw	$s2,0x4c($sp)
/*  f143034:	8fb30050 */ 	lw	$s3,0x50($sp)
/*  f143038:	03e00008 */ 	jr	$ra
/*  f14303c:	27bd0160 */ 	addiu	$sp,$sp,0x160
);
#endif

/**
 * Renders the black part of the IR scanner, which obscures the edges of the
 * screen and creates the binocular effect.
 *
 * The two circles are "placed" at the 1/3 and 2/3 marks horizontally. The
 * screen is then iterated top to bottom, one line at a time, and draws
 * black rectangles on each line to fill in the area outside the circles.
 */
Gfx *bviewRenderIrBinoculars(Gfx *gdl)
{
	s32 viewheight = viGetViewHeight();
	s32 viewwidth = viGetViewWidth();
	s32 viewtop = viGetViewTop();
	s32 viewleft = viGetViewLeft();
	s32 viewright = viewleft + viewwidth;
	s32 viewbottom = viewtop + viewheight;
	s32 leftx = viewleft + viewwidth / 3;
	s32 rightx = viewleft + (viewwidth * 2) / 3;
	s32 centrey = (viewtop + viewbottom) / 2;
	s32 radius = g_IrBinocularRadius;
	s32 sqradius = radius * radius;
	s32 y;
	u32 stack[2];

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
	gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
	gDPSetPrimColor(gdl++, 0, 0, 0x00, 0x00, 0x00, 0xff);

	for (y = viewtop; y < viewbottom; y++) {
		s32 ytocentre = centrey - y;
		s32 sqytocentre = ytocentre * ytocentre;

		if (sqytocentre < sqradius) {
			s32 xoffset = (viewwidth / 320.0f) * sqrtf(sqradius - sqytocentre);

			// Left side
			if (leftx - xoffset > viewleft) {
				gdl = bviewRenderIrRect(gdl, viewleft, y, leftx - xoffset, y + 1);
			}

			// Middle (top and bottom)
			if (leftx + xoffset < rightx - xoffset) {
				gdl = bviewRenderIrRect(gdl, leftx + xoffset, y, rightx - xoffset, y + 1);
			}

			// Right side
			if (rightx + xoffset < viewright) {
				gdl = bviewRenderIrRect(gdl, rightx + xoffset, y, viewright, y + 1);
			}
		} else {
			// Very top or bottom - whole line is black
#if VERSION >= VERSION_NTSC_1_0
			gdl = bviewRenderIrRect(gdl, viewleft, y, viewright, y + 1);
#else
			gdl = bviewRenderIrRect(gdl, viewleft, y, viewright - 1, y + 1);
#endif
		}
	}

	return gdl;
}

Gfx *func0f148b38(Gfx *gdl)
{
	return gdl;
}

void bviewSetBlur(u32 bluramount)
{
	var8007f840 = 0;
	var8007f848 = 0;
	var8007f844 = (bluramount << 1) / 3;
}

void bviewClearBlur(void)
{
	var8007f844 = 0;
}
